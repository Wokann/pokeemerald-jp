#include "global.h"
#include "m4a.h"
#include "malloc.h"
#include "reload_save.h"
#include "save.h"
#include "bg.h"
#include "window.h"
#include "librfu.h"
#include "random.h"
#include "decompress.h"
#include "string_util.h"
#include "event_data.h"
#include "item_menu.h"
#include "overworld.h"
#include "gpu_regs.h"
#include "palette.h"
#include "task.h"
#include "scanline_effect.h"
#include "menu.h"
#include "text.h"
#include "strings.h"
#include "constants/songs.h"
#include "sound.h"
#include "trade.h"
#include "battle.h"
#include "link.h"
#include "link_rfu.h"
#include "constants/rgb.h"
#include "constants/trade.h"

// Window IDs for the link error screens
enum {
    WIN_LINK_ERROR_TOP,
    WIN_LINK_ERROR_MID,
    WIN_LINK_ERROR_BOTTOM,
};

struct BlockTransfer
{
    u16 pos;
    u16 size;
    const u8 *src;
    bool8 active;
    u8 multiplayerId;
};

struct LinkTestBGInfo
{
    u32 screenBaseBlock;
    u32 paletteNum;
    u32 baseChar;
    u32 unused;
};

// Link data lives at fixed JP addresses (sym_ewram_jp.txt, sym_iwram_jp.txt,
// ld_script_jp.txt), so the C source only carries extern declarations.
// The COMMON_DATA/EWRAM_DATA globals are declared in include/link.h.
extern struct BlockTransfer sBlockSend;
extern struct BlockTransfer sBlockRecv[MAX_LINK_PLAYERS];
extern u32 sBlockSendDelayCounter;
extern bool32 sDummy1; // Never read
extern bool8 sDummy2; // Never assigned, read in unused function
extern u32 sPlayerDataExchangeStatus;
extern bool32 sDummy3; // Never read
extern u8 sLinkTestLastBlockSendPos;
extern u8 sLinkTestLastBlockRecvPos[MAX_LINK_PLAYERS];
extern u8 sNumVBlanksWithoutSerialIntr;
extern bool8 sSendBufferEmpty;
extern u16 sSendNonzeroCheck;
extern u16 sRecvNonzeroCheck;
extern u8 sChecksumAvailable;
extern u8 sHandshakePlayerCount;

extern u32 gLinkFiller1;
extern u32 gLinkFiller2;
extern u32 gLinkFiller3;
extern u32 gLinkFiller4;
extern u32 gLinkFiller5;
extern bool8 gLinkDummy1;
extern bool8 gLinkDummy2;

extern u8 sLinkTestDebugValuesEnabled;
extern u8 sDummyFlag;
extern bool8 sLinkOpen;
extern u16 sTimeOutCounter;
extern struct LinkPlayer sSavedLinkPlayers[MAX_RFU_PLAYERS];
extern struct {
    u32 status;
    u8 lastRecvQueueCount;
    u8 lastSendQueueCount;
    bool8 disconnected;
} sLinkErrorBuffer;
extern u16 sReadyCloseLinkAttempts; // never read
extern void *sLinkErrorBgTilemapBuffer;
u32 sub_08011FC0(void);

void InitLocalLinkPlayer(void);
void VBlankCB_LinkError(void);
void CB2_LinkTest(void);
void ProcessRecvCmds(u8);
void LinkCB_SendHeldKeys(void);
void ResetBlockSend(void);
bool32 InitBlockSend(const void *, size_t);
void LinkCB_BlockSendBegin(void);
void LinkCB_BlockSend(void);
void LinkCB_BlockSendEnd(void);
void SetBlockReceivedFlag(u8);
u16 LinkTestCalcBlockChecksum(const u16 *, u16);
void LinkTest_PrintHex(u32, u8, u8, u8);
void LinkCB_RequestPlayerDataExchange(void);
void Task_PrintTestData(u8);

void LinkCB_ReadyCloseLink(void);
void LinkCB_WaitCloseLink(void);
void LinkCB_ReadyCloseLinkWithJP(void);
void LinkCB_WaitCloseLinkWithJP(void);
void LinkCB_Standby(void);
void LinkCB_StandbyForAll(void);

void TrySetLinkErrorBuffer(void);
void CB2_PrintErrorMessage(void);
bool8 IsSioMultiMaster(void);
void SetWirelessCommType0_Internal(void);
void DisableSerial(void);
void EnableSerial(void);
void CheckMasterOrSlave(void);
void InitTimer(void);
void EnqueueSendCmd(u16 *sendCmd);
void DequeueRecvCmds(u16 (*recvCmds)[CMD_LENGTH]);

void StartTransfer(void);
bool8 DoHandshake(void);
void DoRecv(void);
void DoSend(void);
void StopTimer(void);
void SendRecvDone(void);

// The JP build binds these graphics from the ROM (data.s) instead of PNG
// assets; they are stubbed until their consumers are converted to C.
static const u16 sWirelessLinkDisplayPal[] = {0};
static const u32 sWirelessLinkDisplayGfx[] = {0};
static const u32 sWirelessLinkDisplayTilemap[] = {0};
// JP const data lives in data.s (bound in ld_script_jp.txt).
extern const u16 sLinkTestDigitsPal[];
extern const u16 sLinkTestDigitsGfx[0x110];
static const u8 sUnusedTransparentWhite[] = {0};
static const u16 sCommErrorBg_Gfx[] = {0};
static const struct BlockRequest sBlockRequests[] = {
    [BLOCK_REQ_SIZE_NONE] = {gBlockSendBuffer, 200},
    [BLOCK_REQ_SIZE_200]  = {gBlockSendBuffer, 200},
    [BLOCK_REQ_SIZE_100]  = {gBlockSendBuffer, 100},
    [BLOCK_REQ_SIZE_220]  = {gBlockSendBuffer, 220},
    [BLOCK_REQ_SIZE_40]   = {gBlockSendBuffer,  40}
};
extern const u8 sBGControlRegs[];
// JP const data lives in data.s (bound in ld_script_jp.txt).
extern const char sASCIIGameFreakInc[];
extern const char sASCIITestPrint[];
extern const struct BgTemplate sLinkErrorBgTemplates[2];
extern const struct WindowTemplate sLinkErrorWindowTemplates[4];

static const u8 sTextColors[] = { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY };
static const u8 sUnusedData[] = {0x00, 0xFF, 0xFE, 0xFF, 0x00};

bool8 IsWirelessAdapterConnected(void)
{
    SetWirelessCommType1();
    InitRFUAPI();
    if (rfu_LMAN_REQBN_softReset_and_checkID() == RFU_ID)
    {
        rfu_REQ_stopMode();
        rfu_waitREQComplete();
        return TRUE;
    }
    SetWirelessCommType0_Internal();
    CloseLink();
    RestoreSerialTimer3IntrHandlers();
    return FALSE;
}

void Task_DestroySelf(u8 taskId)
{
    DestroyTask(taskId);
}

void InitLinkTestBG(u8 paletteNum, u8 bgNum, u8 screenBaseBlock, u8 charBaseBlock, u16 baseChar)
{
    LoadPalette(sLinkTestDigitsPal, BG_PLTT_ID(paletteNum), PLTT_SIZE_4BPP);
    DmaCopy16(3, sLinkTestDigitsGfx, (u16 *)BG_CHAR_ADDR(charBaseBlock) + (16 * baseChar), sizeof sLinkTestDigitsGfx);
    gLinkTestBGInfo.screenBaseBlock = screenBaseBlock;
    gLinkTestBGInfo.paletteNum = paletteNum;
    gLinkTestBGInfo.baseChar = baseChar;
    switch (bgNum)
    {
        case 1:
            SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(charBaseBlock));
            break;
        case 2:
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(charBaseBlock));
            break;
        case 3:
            SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_PRIORITY(1) | BGCNT_CHARBASE(charBaseBlock));
            break;
    }
    SetGpuReg(REG_OFFSET_BG0HOFS + bgNum * 4, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS + bgNum * 4, 0);
}

void UNUSED LoadLinkTestBgGfx(u8 paletteNum, u8 bgNum, u8 screenBaseBlock, u8 charBaseBlock)
{
    LoadPalette(sLinkTestDigitsPal, BG_PLTT_ID(paletteNum), PLTT_SIZE_4BPP);
    DmaCopy16(3, sLinkTestDigitsGfx, (u16 *)BG_CHAR_ADDR(charBaseBlock), sizeof sLinkTestDigitsGfx);
    gLinkTestBGInfo.screenBaseBlock = screenBaseBlock;
    gLinkTestBGInfo.paletteNum = paletteNum;
    gLinkTestBGInfo.baseChar = 0;
    SetGpuReg(sBGControlRegs[bgNum], BGCNT_SCREENBASE(screenBaseBlock) | BGCNT_CHARBASE(charBaseBlock));
}

void UNUSED LinkTestScreen(void)
{
    int i;

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    SetVBlankCallback(VBlankCB_LinkError);
    ResetBlockSend();
    gLinkType = LINKTYPE_TRADE;
    OpenLink();
    SeedRng(gMain.vblankCounter2);
    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        gSaveBlock2Ptr->playerTrainerId[i] = Random() % 256;

    InitLinkTestBG(0, 2, 4, 0, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
    CreateTask(Task_DestroySelf, 0);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    sDummy3 = FALSE;
    InitLocalLinkPlayer();
    CreateTask(Task_PrintTestData, 0);
    SetMainCallback2(CB2_LinkTest);
}

void SetLocalLinkPlayerId(u8 playerId)
{
    gLocalLinkPlayer.id = playerId;
}

void InitLocalLinkPlayer(void)
{
    gLocalLinkPlayer.trainerId = gSaveBlock2Ptr->playerTrainerId[0] | (gSaveBlock2Ptr->playerTrainerId[1] << 8) | (gSaveBlock2Ptr->playerTrainerId[2] << 16) | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
    StringCopy(gLocalLinkPlayer.name, gSaveBlock2Ptr->playerName);
    gLocalLinkPlayer.gender = gSaveBlock2Ptr->playerGender;
    gLocalLinkPlayer.linkType = gLinkType;
    gLocalLinkPlayer.language = gGameLanguage;
    gLocalLinkPlayer.version = gGameVersion + 0x4000;
    gLocalLinkPlayer.lp_field_2 = 0x8000;
    gLocalLinkPlayer.progressFlags = IsNationalPokedexEnabled();
    if (FlagGet(FLAG_IS_CHAMPION))
    {
        gLocalLinkPlayer.progressFlags |= 0x10;
    }
}

void VBlankCB_LinkError(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void InitLink(void)
{
    int i;

    for (i = 0; i < CMD_LENGTH; i++)
        gSendCmd[i] = LINKCMD_NONE;

    sLinkOpen = TRUE;
    EnableSerial();
}

void Task_TriggerHandshake(u8 taskId)
{
    if (++gTasks[taskId].data[0] == 5)
    {
        gShouldAdvanceLinkState = 1;
        DestroyTask(taskId);
    }
}

void OpenLink(void)
{
    int i;

    if (!gWirelessCommType)
    {
        ResetSerial();
        InitLink();
        gLinkCallback = LinkCB_RequestPlayerDataExchange;
        gLinkVSyncDisabled = FALSE;
        gLinkErrorOccurred = FALSE;
        gSuppressLinkErrorMessage = FALSE;
        ResetBlockReceivedFlags();
        ResetBlockSend();
        sDummy1 = FALSE;
        gLinkDummy2 = FALSE;
        gLinkDummy1 = FALSE;
        gReadyCloseLinkType = 0;
        CreateTask(Task_TriggerHandshake, 2);
    }
    else
    {
        InitRFUAPI();
    }
    gReceivedRemoteLinkPlayers = 0;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        gRemoteLinkPlayersNotReceived[i] = TRUE;
        gReadyToCloseLink[i] = FALSE;
        gReadyToExitStandby[i] = FALSE;
    }
}

void CloseLink(void)
{
    gReceivedRemoteLinkPlayers = FALSE;
    if (gWirelessCommType)
        LinkRfu_Shutdown();
    sLinkOpen = FALSE;
    DisableSerial();
}

void TestBlockTransfer(u8 nothing, u8 is, u8 used)
{
    u8 i;
    u8 status;

    if (sLinkTestLastBlockSendPos != sBlockSend.pos)
    {
        LinkTest_PrintHex(sBlockSend.pos, 2, 3, 2);
        sLinkTestLastBlockSendPos = sBlockSend.pos;
    }
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (sLinkTestLastBlockRecvPos[i] != sBlockRecv[i].pos)
        {
            LinkTest_PrintHex(sBlockRecv[i].pos, 2, i + 4, 2);
            sLinkTestLastBlockRecvPos[i] = sBlockRecv[i].pos;
        }
    }
    status = GetBlockReceivedStatus();
    if (status == 0xF) // 0b1111
    {
        for (i = 0; i < MAX_LINK_PLAYERS; i++)
        {
            if ((status >> i) & 1)
            {
                gLinkTestBlockChecksums[i] = LinkTestCalcBlockChecksum(gBlockRecvBuffer[i], sBlockRecv[i].size);
                ResetBlockReceivedFlag(i);
                if (gLinkTestBlockChecksums[i] != 0x0342)
                {
                    sLinkTestDebugValuesEnabled = FALSE;
                    sDummyFlag = FALSE;
                }
            }
        }
    }
}

void LinkTestProcessKeyInput(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        gShouldAdvanceLinkState = 1;
    }
    if (JOY_HELD(B_BUTTON))
    {
        InitBlockSend(gHeap + 0x4000, 0x00002004);
    }
    if (JOY_NEW(L_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB(2, 0, 0));
    }
    if (JOY_NEW(START_BUTTON))
    {
        SetSuppressLinkErrorMessage(TRUE);
    }
    if (JOY_NEW(R_BUTTON))
    {
        TrySavingData(SAVE_LINK);
    }
    if (JOY_NEW(SELECT_BUTTON))
    {
        SetCloseLinkCallback();
    }
    if (sLinkTestDebugValuesEnabled)
    {
        SetLinkDebugValues(gMain.vblankCounter2, gLinkCallback ? gLinkVSyncDisabled : gLinkVSyncDisabled | 0x10);
    }
}

void CB2_LinkTest(void)
{
    LinkTestProcessKeyInput();
    TestBlockTransfer(1, 1, 0);
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

u16 LinkMain2(const u16 *heldKeys)
{
    u8 i;

    if (!sLinkOpen)
        return 0;

    for (i = 0; i < CMD_LENGTH; i++)
        gSendCmd[i] = 0;

    gLinkHeldKeys = *heldKeys;
    if (gLinkStatus & LINK_STAT_CONN_ESTABLISHED)
    {
        ProcessRecvCmds(SIO_MULTI_CNT->id);
        if (gLinkCallback != NULL)
            gLinkCallback();
        TrySetLinkErrorBuffer();
    }
    return gLinkStatus;
}

void HandleReceiveRemoteLinkPlayer(u8 who)
{
    int i;
    int count;

    count = 0;
    gRemoteLinkPlayersNotReceived[who] = FALSE;
    for (i = 0; i < GetLinkPlayerCount_2(); i++)
    {
        count += gRemoteLinkPlayersNotReceived[i];
    }
    if (count == 0 && gReceivedRemoteLinkPlayers == 0)
    {
        gReceivedRemoteLinkPlayers = 1;
    }
}


void BuildSendCmd(u16 command)
{
    switch (command)
    {
        case LINKCMD_SEND_LINK_TYPE:
            gSendCmd[0] = LINKCMD_SEND_LINK_TYPE;
            gSendCmd[1] = gLinkType;
            break;
        case LINKCMD_READY_EXIT_STANDBY:
            gSendCmd[0] = LINKCMD_READY_EXIT_STANDBY;
            break;
        case LINKCMD_BLENDER_SEND_KEYS:
            gSendCmd[0] = LINKCMD_BLENDER_SEND_KEYS;
            gSendCmd[1] = gMain.heldKeys;
            break;
        case LINKCMD_DUMMY_1:
            gSendCmd[0] = LINKCMD_DUMMY_1;
            break;
        case LINKCMD_SEND_EMPTY:
            gSendCmd[0] = LINKCMD_SEND_EMPTY;
            gSendCmd[1] = 0;
            break;
        case LINKCMD_SEND_0xEE:
        {
            u8 i;
            gSendCmd[0] = LINKCMD_SEND_0xEE;
            for (i = 0; i < 5; i++)
                gSendCmd[i + 1] = 0xEE;
            break;
        }
        case LINKCMD_INIT_BLOCK:
            gSendCmd[0] = LINKCMD_INIT_BLOCK;
            gSendCmd[1] = sBlockSend.size;
            gSendCmd[2] = sBlockSend.multiplayerId + 0x80;
            break;
        case LINKCMD_BLENDER_NO_PBLOCK_SPACE:
            gSendCmd[0] = LINKCMD_BLENDER_NO_PBLOCK_SPACE;
            break;
        case LINKCMD_SEND_ITEM:
            gSendCmd[0] = LINKCMD_SEND_ITEM;
            gSendCmd[1] = gSpecialVar_ItemId;
            break;
        case LINKCMD_SEND_BLOCK_REQ:
            gSendCmd[0] = LINKCMD_SEND_BLOCK_REQ;
            gSendCmd[1] = gBlockRequestType;
            break;
        case LINKCMD_READY_CLOSE_LINK:
            gSendCmd[0] = LINKCMD_READY_CLOSE_LINK;
            gSendCmd[1] = gReadyCloseLinkType;
            break;
        case LINKCMD_DUMMY_2:
            gSendCmd[0] = LINKCMD_DUMMY_2;
            break;
        case LINKCMD_SEND_HELD_KEYS:
            if (gHeldKeyCodeToSend == 0 || gLinkTransferringData)
                break;

            gSendCmd[0] = LINKCMD_SEND_HELD_KEYS;
            gSendCmd[1] = gHeldKeyCodeToSend;
            break;
    }
}

void StartSendingKeysToLink(void)
{
    if (gWirelessCommType)
        StartSendingKeysToRfu();

    gLinkCallback = LinkCB_SendHeldKeys;
}

bool32 IsSendingKeysToLink(void)
{
    if (gWirelessCommType)
        return IsSendingKeysToRfu();

    if (gLinkCallback == LinkCB_SendHeldKeys)
        return TRUE;

    return FALSE;
}

void LinkCB_SendHeldKeys(void)
{
    if (gReceivedRemoteLinkPlayers == TRUE)
        BuildSendCmd(LINKCMD_SEND_HELD_KEYS);
}

void ClearLinkCallback(void)
{
    if (gWirelessCommType)
        ClearLinkRfuCallback();
    else
        gLinkCallback = NULL;
}

void ClearLinkCallback_2(void)
{
    if (gWirelessCommType)
        ClearLinkRfuCallback();
    else
        gLinkCallback = NULL;
}

u8 GetLinkPlayerCount(void)
{
    if (gWirelessCommType)
        return Rfu_GetLinkPlayerCount();

    return EXTRACT_PLAYER_COUNT(gLinkStatus);
}

int AreAnyLinkPlayersUsingVersions(u32 version1, u32 version2)
{
    int i;
    u8 nPlayers;

    nPlayers = GetLinkPlayerCount();
    for (i = 0; i < nPlayers; i++)
    {
        if ((gLinkPlayers[i].version & 0xFF) == version1
         || (gLinkPlayers[i].version & 0xFF) == version2)
            return 1;
    }
    return -1;
}

bool32 UNUSED IsFullLinkGroupWithNoRS(void)
{
    if (GetLinkPlayerCount() != MAX_LINK_PLAYERS || AreAnyLinkPlayersUsingVersions(VERSION_RUBY, VERSION_SAPPHIRE) < 0)
    {
        return FALSE;
    }
    return TRUE;
}

bool32 Link_AnyPartnersPlayingRubyOrSapphire(void)
{
    if (AreAnyLinkPlayersUsingVersions(VERSION_RUBY, VERSION_SAPPHIRE) >= 0)
    {
        return TRUE;
    }
    return FALSE;
}

bool32 Link_AnyPartnersPlayingFRLG_JP(void)
{
    int i;

    i = AreAnyLinkPlayersUsingVersions(VERSION_FIRE_RED, VERSION_LEAF_GREEN);
    if (i >= 0 && gLinkPlayers[i].language == LANGUAGE_JAPANESE)
    {
        return TRUE;
    }
    return FALSE;
}

void OpenLinkTimed(void)
{
    sPlayerDataExchangeStatus = EXCHANGE_NOT_STARTED;
    sTimeOutCounter = 0;
    OpenLink();
}

u8 GetLinkPlayerDataExchangeStatusTimed(int minPlayers, int maxPlayers)
{
    int i;
    int count;
    u32 index;
    u8 numPlayers;
    u32 linkType1;
    u32 linkType2;

    count = 0;
    if (gReceivedRemoteLinkPlayers == TRUE)
    {
        numPlayers = GetLinkPlayerCount_2();
        if (minPlayers > numPlayers || numPlayers > maxPlayers)
        {
            sPlayerDataExchangeStatus = EXCHANGE_WRONG_NUM_PLAYERS;
            return sPlayerDataExchangeStatus;
        }
        else
        {
            if (GetLinkPlayerCount() == 0)
            {
                gLinkErrorOccurred = TRUE;
                CloseLink();
            }
            for (i = 0, index = 0; i < GetLinkPlayerCount(); index++, i++)
            {
                if (gLinkPlayers[index].linkType == gLinkPlayers[0].linkType)
                {
                    count++;
                }
            }
            if (count == GetLinkPlayerCount())
            {
                if (gLinkPlayers[0].linkType == LINKTYPE_TRADE_SETUP)
                {
                    switch (GetGameProgressForLinkTrade())
                    {
                    case TRADE_PLAYER_NOT_READY:
                        sPlayerDataExchangeStatus = EXCHANGE_PLAYER_NOT_READY;
                        break;
                    case TRADE_PARTNER_NOT_READY:
                        sPlayerDataExchangeStatus = EXCHANGE_PARTNER_NOT_READY;
                        break;
                    case TRADE_BOTH_PLAYERS_READY:
                        sPlayerDataExchangeStatus = EXCHANGE_COMPLETE;
                        break;
                    }
                }
                else
                {
                    sPlayerDataExchangeStatus = EXCHANGE_COMPLETE;
                }
            }
            else
            {
                sPlayerDataExchangeStatus = EXCHANGE_DIFF_SELECTIONS;
                linkType1 = gLinkPlayers[GetMultiplayerId()].linkType;
                linkType2 = gLinkPlayers[GetMultiplayerId() ^ 1].linkType;
                if ((linkType1 == LINKTYPE_BATTLE_TOWER_50 && linkType2 == LINKTYPE_BATTLE_TOWER_OPEN)
                 || (linkType1 == LINKTYPE_BATTLE_TOWER_OPEN && linkType2 == LINKTYPE_BATTLE_TOWER_50))
                {
                    // 3 below indicates partner made different level mode selection
                    // See BattleFrontier_BattleTowerLobby_EventScript_AbortLinkDifferentSelections
                    gSpecialVar_0x8005 = 3;
                }
            }
        }
    }
    else if (++sTimeOutCounter > 600)
    {
        sPlayerDataExchangeStatus = EXCHANGE_TIMED_OUT;
    }
    return sPlayerDataExchangeStatus;
}

bool8 IsLinkPlayerDataExchangeComplete(void)
{
    u8 i;
    u8 count;
    bool8 retval;

    count = 0;
    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        if (gLinkPlayers[i].linkType == gLinkPlayers[0].linkType)
            count++;
    }
    if (count == GetLinkPlayerCount())
    {
        retval = TRUE;
        sPlayerDataExchangeStatus = EXCHANGE_COMPLETE;
    }
    else
    {
        retval = FALSE;
        sPlayerDataExchangeStatus = EXCHANGE_DIFF_SELECTIONS;
    }
    return retval;
}

u32 GetLinkPlayerTrainerId(u8 who)
{
    return gLinkPlayers[who].trainerId;
}

void ResetLinkPlayers(void)
{
    int i;

    for (i = 0; i <= MAX_LINK_PLAYERS; i++)
        gLinkPlayers[i] = (struct LinkPlayer){};
}

void ResetBlockSend(void)
{
    sBlockSend.active = FALSE;
    sBlockSend.pos = 0;
    sBlockSend.size = 0;
    sBlockSend.src = NULL;
}

bool32 InitBlockSend(const void *src, size_t size)
{
    if (sBlockSend.active)
    {
        return FALSE;
    }
    sBlockSend.multiplayerId = GetMultiplayerId();
    sBlockSend.active = TRUE;
    sBlockSend.size = size;
    sBlockSend.pos = 0;
    if (size > BLOCK_BUFFER_SIZE)
    {
        sBlockSend.src = src;
    }
    else
    {
        if (src != gBlockSendBuffer)
            memcpy(gBlockSendBuffer, src, size);

        sBlockSend.src = gBlockSendBuffer;
    }
    BuildSendCmd(LINKCMD_INIT_BLOCK);
    gLinkCallback = LinkCB_BlockSendBegin;
    sBlockSendDelayCounter = 0;
    return TRUE;
}

void LinkCB_BlockSendBegin(void)
{
    if (++sBlockSendDelayCounter > 2)
        gLinkCallback = LinkCB_BlockSend;
}

void LinkCB_BlockSend(void)
{
    int i;
    const u8 *src;

    src = sBlockSend.src;
    gSendCmd[0] = LINKCMD_CONT_BLOCK;
    for (i = 0; i < CMD_LENGTH - 1; i++)
    {
        gSendCmd[i + 1] = (src[sBlockSend.pos + i * 2 + 1] << 8) | src[sBlockSend.pos + i * 2];
    }
    sBlockSend.pos += 14;
    if (sBlockSend.size <= sBlockSend.pos)
    {
        sBlockSend.active = FALSE;
        gLinkCallback = LinkCB_BlockSendEnd;
    }
}

void LinkCB_BlockSendEnd(void)
{
    gLinkCallback = NULL;
}

void LinkCB_BerryBlenderSendHeldKeys(void)
{
    GetMultiplayerId();
    BuildSendCmd(LINKCMD_BLENDER_SEND_KEYS);
    gBerryBlenderKeySendAttempts++;
}

void SetBerryBlenderLinkCallback(void)
{
    gBerryBlenderKeySendAttempts = 0;
    if (gWirelessCommType)
        Rfu_SetBerryBlenderLinkCallback();
    else
        gLinkCallback = LinkCB_BerryBlenderSendHeldKeys;
}

static u32 UNUSED GetBerryBlenderKeySendAttempts(void)
{
    return gBerryBlenderKeySendAttempts;
}

void UNUSED SendBerryBlenderNoSpaceForPokeblocks(void)
{
    BuildSendCmd(LINKCMD_BLENDER_NO_PBLOCK_SPACE);
}

u8 GetMultiplayerId(void)
{
    if (gWirelessCommType == TRUE)
        return Rfu_GetMultiplayerId();

    return SIO_MULTI_CNT->id;
}

u8 BitmaskAllOtherLinkPlayers(void)
{
    u8 mpId;

    mpId = GetMultiplayerId();
    return ((1 << MAX_LINK_PLAYERS) - 1) ^ (1 << mpId);
}

bool8 SendBlock(u8 unused, const void *src, u16 size)
{
    if (gWirelessCommType == TRUE)
        return Rfu_InitBlockSend(src, size);

    return InitBlockSend(src, size);
}

bool8 SendBlockRequest(u8 blockReqType)
{
    if (gWirelessCommType == TRUE)
        return Rfu_SendBlockRequest(blockReqType);

    if (gLinkCallback == NULL)
    {
        gBlockRequestType = blockReqType;
        BuildSendCmd(LINKCMD_SEND_BLOCK_REQ);
        return TRUE;
    }
    return FALSE;
}

bool8 IsLinkTaskFinished(void)
{
    if (gWirelessCommType == TRUE)
        return IsLinkRfuTaskFinished();

    return gLinkCallback == NULL;
}

u8 GetBlockReceivedStatus(void)
{
    if (gWirelessCommType == TRUE)
        return Rfu_GetBlockReceivedStatus();

    return (gBlockReceivedStatus[3] << 3) | (gBlockReceivedStatus[2] << 2) | (gBlockReceivedStatus[1] << 1) | (gBlockReceivedStatus[0] << 0);
}

void SetBlockReceivedFlag(u8 who)
{
    if (gWirelessCommType == TRUE)
        Rfu_SetBlockReceivedFlag(who);
    else
        gBlockReceivedStatus[who] = TRUE;
}

void ResetBlockReceivedFlags(void)
{
    int i;

    if (gWirelessCommType == TRUE)
    {
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            Rfu_ResetBlockReceivedFlag(i);
    }
    else
    {
        for (i = 0; i < MAX_LINK_PLAYERS; i++)
            gBlockReceivedStatus[i] = FALSE;
    }
}

void ResetBlockReceivedFlag(u8 who)
{
    if (gWirelessCommType == TRUE)
    {
        Rfu_ResetBlockReceivedFlag(who);
    }
    else if (gBlockReceivedStatus[who])
    {
        gBlockReceivedStatus[who] = FALSE;
    }
}

void CheckShouldAdvanceLinkState(void)
{
    if ((gLinkStatus & LINK_STAT_MASTER) && EXTRACT_PLAYER_COUNT(gLinkStatus) > 1)
        gShouldAdvanceLinkState = 1;
}

u16 LinkTestCalcBlockChecksum(const u16 *src, u16 size)
{
    u16 chksum;
    u16 i;

    chksum = 0;
    for (i = 0; i < size / 2; i++)
        chksum += src[i];

    return chksum;
}

void LinkTest_PrintNumChar(char val, u8 x, u8 y)
{
    u16 *vAddr;

    vAddr = (u16 *)BG_SCREEN_ADDR(gLinkTestBGInfo.screenBaseBlock);
    vAddr[y * 32 + x] = (gLinkTestBGInfo.paletteNum << 12) | (val + 1 + gLinkTestBGInfo.baseChar);
}

void LinkTest_PrintChar(char val, u8 x, u8 y)
{
    u16 *vAddr;

    vAddr = (u16 *)BG_SCREEN_ADDR(gLinkTestBGInfo.screenBaseBlock);
    vAddr[y * 32 + x] = (gLinkTestBGInfo.paletteNum << 12) | (val + gLinkTestBGInfo.baseChar);
}

void LinkTest_PrintHex(u32 num, u8 x, u8 y, u8 length)
{
    char buff[16];
    int i;

    for (i = 0; i < length; i++)
    {
        buff[i] = num & 0xF;
        num >>= 4;
    }
    for (i = length - 1; i >= 0; i--)
    {
        LinkTest_PrintNumChar(buff[i], x, y);
        x++;
    }
}

void UNUSED LinkTest_PrintInt(int num, u8 x, u8 y, u8 length)
{
    char buff[16];
    int negX;
    int i;

    negX = -1;
    if (num < 0)
    {
        negX = x;
        num = -num;
    }
    for (i = 0; i < length; i++)
    {
        buff[i] = num % 10;
        num /= 10;
    }
    for (i = length - 1; i >= 0; i--)
    {
        LinkTest_PrintNumChar(buff[i], x, y);
        x++;
    }

    if (negX != -1)
        LinkTest_PrintNumChar(*"\n", negX, y);
}

void LinkTest_PrintString(const char *str, u8 x, u8 y)
{
    int xOffset;
    int i;
    int yOffset;

    yOffset = 0;
    xOffset = 0;
    for (i = 0; str[i] != 0; str++)
    {
        if (str[i] == *"\n")
        {
            yOffset++;
            xOffset = 0;
        }
        else
        {
            LinkTest_PrintChar(str[i], x + xOffset, y + yOffset);
            xOffset++;
        }
    }
}

void LinkCB_RequestPlayerDataExchange(void)
{
    if (gLinkStatus & LINK_STAT_MASTER)
    {
        BuildSendCmd(LINKCMD_SEND_LINK_TYPE);
    }
    gLinkCallback = NULL;
}

void Task_PrintTestData(u8 taskId)
{
    char testTitle[32];
    int i;

    strcpy(testTitle, sASCIITestPrint);
    LinkTest_PrintString(testTitle, 5, 2);
    LinkTest_PrintHex(gShouldAdvanceLinkState, 2, 1, 2);
    LinkTest_PrintHex(gLinkStatus, 15, 1, 8);
    LinkTest_PrintHex(gLink.state, 2, 10, 2);
    LinkTest_PrintHex(EXTRACT_PLAYER_COUNT(gLinkStatus), 15, 10, 2);
    LinkTest_PrintHex(GetMultiplayerId(), 15, 12, 2);
    LinkTest_PrintHex(gLastSendQueueCount, 25, 1, 2);
    LinkTest_PrintHex(gLastRecvQueueCount, 25, 2, 2);
    LinkTest_PrintHex(GetBlockReceivedStatus(), 15, 5, 2);
    LinkTest_PrintHex(gLinkDebugSeed, 2, 12, 8);
    LinkTest_PrintHex(gLinkDebugFlags, 2, 13, 8);
    LinkTest_PrintHex(GetSioMultiSI(), 25, 5, 1);
    LinkTest_PrintHex(IsSioMultiMaster(), 25, 6, 1);
    LinkTest_PrintHex(IsLinkConnectionEstablished(), 25, 7, 1);
    LinkTest_PrintHex(HasLinkErrorOccurred(), 25, 8, 1);

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
        LinkTest_PrintHex(gLinkTestBlockChecksums[i], 10, 4 + i, 4);
}

void SetLinkDebugValues(u32 seed, u32 flags)
{
    gLinkDebugSeed = seed;
    gLinkDebugFlags = flags;
}

u8 GetSavedLinkPlayerCountAsBitFlags(void)
{
    int i;
    u8 flags;

    flags = 0;
    for (i = 0; i < gSavedLinkPlayerCount; i++)
        flags |= (1 << i);

    return flags;
}

u8 GetLinkPlayerCountAsBitFlags(void)
{
    int i;
    u8 flags;

    flags = 0;
    for (i = 0; i < GetLinkPlayerCount(); i++)
        flags |= (1 << i);

    return flags;
}

void SaveLinkPlayers(u8 playerCount)
{
    int i;

    gSavedLinkPlayerCount = playerCount;
    gSavedMultiplayerId = GetMultiplayerId();
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        sSavedLinkPlayers[i] = gLinkPlayers[i];
}

u8 GetSavedPlayerCount(void)
{
    return gSavedLinkPlayerCount;
}

static u8 UNUSED GetSavedMultiplayerId(void)
{
    return gSavedMultiplayerId;
}

bool8 DoesLinkPlayerCountMatchSaved(void)
{
    int i;
    u32 count = 0;

    for (i = 0; i < gSavedLinkPlayerCount; i++)
    {
        if (gLinkPlayers[i].trainerId == sSavedLinkPlayers[i].trainerId)
        {
            if (gLinkType == LINKTYPE_BATTLE_TOWER)
            {
                if (gLinkType == gLinkPlayers[i].linkType)
                    count++;
            }
            else
            {
                count++;
            }
        }
    }
    if (count == gSavedLinkPlayerCount)
    {
        if (GetLinkPlayerCount_2() == gSavedLinkPlayerCount)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void ClearSavedLinkPlayers(void)
{
    // The CpuSet loop below is incorrectly writing to NULL
    // instead of sSavedLinkPlayers.
    // Additionally it's using the wrong array size.
#ifdef UBFIX
    memset(sSavedLinkPlayers, 0, sizeof(sSavedLinkPlayers));
#else
    int i;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
        CpuSet(&sSavedLinkPlayers[i], NULL, sizeof(struct LinkPlayer));
#endif
}

void CheckLinkPlayersMatchSaved(void)
{
    u8 i;

    for (i = 0; i < gSavedLinkPlayerCount; i++)
    {
        if (sSavedLinkPlayers[i].trainerId != gLinkPlayers[i].trainerId
         || StringCompare(sSavedLinkPlayers[i].name, gLinkPlayers[i].name) != 0)
        {
            gLinkErrorOccurred = TRUE;
            CloseLink();
            SetMainCallback2(CB2_LinkError);
        }
    }
}

void ResetLinkPlayerCount(void)
{
    gSavedLinkPlayerCount = 0;
    gSavedMultiplayerId = 0;
}

u8 GetLinkPlayerCount_2(void)
{
    return EXTRACT_PLAYER_COUNT(gLinkStatus);
}

bool8 IsLinkMaster(void)
{
    if (gWirelessCommType)
        return Rfu_IsMaster();

    return EXTRACT_MASTER(gLinkStatus);
}

static u8 UNUSED GetDummy2(void)
{
    return sDummy2;
}

void SetCloseLinkCallbackAndType(u16 type)
{
    if (gWirelessCommType == TRUE)
    {
        Rfu_SetCloseLinkCallback();
    }
    else
    {
        if (gLinkCallback == NULL)
        {
            gLinkCallback = LinkCB_ReadyCloseLink;
            gLinkDummy1 = FALSE;
            gReadyCloseLinkType = type;
        }
    }
}

void SetCloseLinkCallback(void)
{
    if (gWirelessCommType == TRUE)
    {
        Rfu_SetCloseLinkCallback();
    }
    else
    {
        if (gLinkCallback != NULL)
        {
            sReadyCloseLinkAttempts++;
        }
        else
        {
            gLinkCallback = LinkCB_ReadyCloseLink;
            gLinkDummy1 = FALSE;
            gReadyCloseLinkType = 0;
        }
    }
}

void LinkCB_ReadyCloseLink(void)
{
    if (gLastRecvQueueCount == 0)
    {
        BuildSendCmd(LINKCMD_READY_CLOSE_LINK);
        gLinkCallback = LinkCB_WaitCloseLink;
    }
}

void LinkCB_WaitCloseLink(void)
{
    int i;
    unsigned count;

    // Wait for all players to be ready
    u8 linkPlayerCount = GetLinkPlayerCount();
    count = 0;
    for (i = 0; i < linkPlayerCount; i++)
    {
        if (gReadyToCloseLink[i])
            count++;
    }

    if (count == linkPlayerCount)
    {
        // All ready, close link
        gBattleTypeFlags &= ~BATTLE_TYPE_LINK_IN_BATTLE;
        gLinkVSyncDisabled = TRUE;
        CloseLink();
        gLinkCallback = NULL;
        gLinkDummy1 = TRUE;
    }
}

void SetLinkStandbyCallback(void)
{
    if (gWirelessCommType == TRUE)
    {
        Rfu_SetLinkStandbyCallback();
    }
    else
    {
        if (gLinkCallback == NULL)
            gLinkCallback = LinkCB_Standby;

        gLinkDummy1 = FALSE;
    }
}

void LinkCB_Standby(void)
{
    if (gLastRecvQueueCount == 0)
    {
        BuildSendCmd(LINKCMD_READY_EXIT_STANDBY);
        gLinkCallback = LinkCB_StandbyForAll;
    }
}

void LinkCB_StandbyForAll(void)
{
    u8 i;
    u8 linkPlayerCount = GetLinkPlayerCount();
    for (i = 0; i < linkPlayerCount; i++)
    {
        if (!gReadyToExitStandby[i])
            break;
    }

    // If true, all players ready to exit standby
    if (i == linkPlayerCount)
    {
        for (i = 0; i < MAX_LINK_PLAYERS; i++)
            gReadyToExitStandby[i] = FALSE;

        gLinkCallback = NULL;
    }
}

void TrySetLinkErrorBuffer(void)
{
    // Check if a link error has occurred
    if (sLinkOpen && EXTRACT_LINK_ERRORS(gLinkStatus))
    {
        // Link error has occurred, handle message details if
        // necessary, then stop the link.
        if (!gSuppressLinkErrorMessage)
        {
            sLinkErrorBuffer.status = gLinkStatus;
            sLinkErrorBuffer.lastRecvQueueCount = gLastRecvQueueCount;
            sLinkErrorBuffer.lastSendQueueCount = gLastSendQueueCount;
            SetMainCallback2(CB2_LinkError);
        }
        gLinkErrorOccurred = TRUE;
        CloseLink();
    }
}

void SetLinkErrorBuffer(u32 status, u8 lastSendQueueCount, u8 lastRecvQueueCount, bool8 disconnected)
{
    sLinkErrorBuffer.status = status;
    sLinkErrorBuffer.lastSendQueueCount = lastSendQueueCount;
    sLinkErrorBuffer.lastRecvQueueCount = lastRecvQueueCount;
    sLinkErrorBuffer.disconnected = disconnected;
}

void CB2_LinkError(void)
{
    u8 *tilemapBuffer;

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    m4aMPlayStop(&gMPlayInfo_SE1);
    m4aMPlayStop(&gMPlayInfo_SE2);
    m4aMPlayStop(&gMPlayInfo_SE3);
    InitHeap(gHeap, HEAP_SIZE);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetPaletteFadeControl();
    SetBackdropFromColor(RGB_BLACK);
    ResetTasks();
    ScanlineEffect_Stop();
    if (gWirelessCommType)
    {
        if (!sLinkErrorBuffer.disconnected)
            gWirelessCommType = 3;

        ResetLinkRfuGFLayer();
    }
    SetVBlankCallback(VBlankCB_LinkError);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sLinkErrorBgTemplates, ARRAY_COUNT(sLinkErrorBgTemplates));
    sLinkErrorBgTilemapBuffer = tilemapBuffer = Alloc(BG_SCREEN_SIZE);
    SetBgTilemapBuffer(1, tilemapBuffer);
    if (InitWindows(sLinkErrorWindowTemplates))
    {
        DeactivateAllTextPrinters();
        ResetTempTileDataBuffers();
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON);
        LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        gSoftResetDisabled = FALSE;
        CreateTask(Task_DestroySelf, 0);
        StopMapMusic();
        gMain.callback1 = NULL;
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        SetMainCallback2(CB2_PrintErrorMessage);
    }
}

bool8 GetSioMultiSI(void)
{
    return (REG_SIOCNT & SIO_MULTI_SI) != 0;
}

bool8 IsSioMultiMaster(void)
{
    return (REG_SIOCNT & SIO_MULTI_SD) && (REG_SIOCNT & SIO_MULTI_SI) == 0;
}

bool8 IsLinkConnectionEstablished(void)
{
    return EXTRACT_CONN_ESTABLISHED(gLinkStatus);
}

void SetSuppressLinkErrorMessage(bool8 flag)
{
    gSuppressLinkErrorMessage = flag;
}

bool8 HasLinkErrorOccurred(void)
{
    return gLinkErrorOccurred;
}

bool8 HandleLinkConnection(void)
{
    bool32 main1Failed, main2Failed;

    if (gWirelessCommType == 0)
    {
        gLinkStatus = LinkMain1(&gShouldAdvanceLinkState, gSendCmd, gRecvCmds);
        LinkMain2(&gMain.heldKeys);
        if ((gLinkStatus & LINK_STAT_RECEIVED_NOTHING) && IsSendingKeysOverCable() == TRUE)
            return TRUE;
    }
    else
    {
        main1Failed = RfuMain1(); // Always returns FALSE
        main2Failed = RfuMain2();
        if (IsSendingKeysOverCable() == TRUE)
        {
            // This will never be reached.
            // IsSendingKeysOverCable is always FALSE for wireless communication
            if (main1Failed == TRUE || IsRfuRecvQueueEmpty() || main2Failed)
                return TRUE;
        }
    }
    return FALSE;
}

void SetWirelessCommType1(void)
{
    if (gReceivedRemoteLinkPlayers == 0)
        gWirelessCommType = 1;
}

void SetWirelessCommType0_Internal(void)
{
    if (gReceivedRemoteLinkPlayers == 0)
        gWirelessCommType = 0;
}

void SetWirelessCommType0(void)
{
    if (gReceivedRemoteLinkPlayers == 0)
        gWirelessCommType = 0;
}

u32 GetLinkRecvQueueLength(void)
{
    if (gWirelessCommType != 0)
        return sub_08011FC0();

    return gLink.recvQueue.count;
}

bool32 IsLinkRecvQueueAtOverworldMax(void)
{
    if (GetLinkRecvQueueLength() >= OVERWORLD_RECV_QUEUE_MAX)
        return TRUE;

    return FALSE;
}

// Unused
u8 GetWirelessCommType(void)
{
    return gWirelessCommType;
}

void DisableSerial(void)
{
    DisableInterrupts(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_TMCNT_H(3) = 0;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
    REG_SIOMLT_SEND = 0;
    REG_SIOMLT_RECV = 0;
    CpuFill32(0, &gLink, sizeof(gLink));
}

void EnableSerial(void)
{
    DisableInterrupts(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_115200_BPS | SIO_INTR_ENABLE;
    EnableInterrupts(INTR_FLAG_SERIAL);
    REG_SIOMLT_SEND = 0;
    CpuFill32(0, &gLink, sizeof(gLink));
    sNumVBlanksWithoutSerialIntr = 0;
    sSendNonzeroCheck = 0;
    sRecvNonzeroCheck = 0;
    sChecksumAvailable = 0;
    sHandshakePlayerCount = 0;
    gLastSendQueueCount = 0;
    gLastRecvQueueCount = 0;
}

void ResetSerial(void)
{
    EnableSerial();
    DisableSerial();
}

void CheckMasterOrSlave(void)
{
    u32 terminals;

    terminals = *(vu32 *)REG_ADDR_SIOCNT & (SIO_MULTI_SD | SIO_MULTI_SI);
    if (terminals == SIO_MULTI_SD && gLink.localId == 0)
    {
        gLink.isMaster = LINK_MASTER;
    }
    else
    {
        gLink.isMaster = LINK_SLAVE;
    }
}

void InitTimer(void)
{
    if (gLink.isMaster)
    {
        REG_TM3CNT_L = -197;
        REG_TM3CNT_H = TIMER_64CLK | TIMER_INTR_ENABLE;
        EnableInterrupts(INTR_FLAG_TIMER3);
    }
}

void EnqueueSendCmd(u16 *sendCmd)
{
    u8 i;
    u8 offset;

    gLinkSavedIme = REG_IME;
    REG_IME = 0;
    if (gLink.sendQueue.count < QUEUE_CAPACITY)
    {
        offset = gLink.sendQueue.pos + gLink.sendQueue.count;
        if (offset >= QUEUE_CAPACITY)
        {
            offset -= QUEUE_CAPACITY;
        }
        for (i = 0; i < CMD_LENGTH; i++)
        {
            sSendNonzeroCheck |= *sendCmd;
            gLink.sendQueue.data[i][offset] = *sendCmd;
            *sendCmd = 0;
            sendCmd++;
        }
    }
    else
    {
        gLink.queueFull = QUEUE_FULL_SEND;
    }
    if (sSendNonzeroCheck)
    {
        gLink.sendQueue.count++;
        sSendNonzeroCheck = 0;
    }
    REG_IME = gLinkSavedIme;
    gLastSendQueueCount = gLink.sendQueue.count;
}

void DequeueRecvCmds(u16 (*recvCmds)[CMD_LENGTH])
{
    u8 i;
    u8 j;

    gLinkSavedIme = REG_IME;
    REG_IME = 0;
    if (gLink.recvQueue.count == 0)
    {
        for (i = 0; i < gLink.playerCount; i++)
        {
            for (j = 0; j < CMD_LENGTH; j++)
            {
                recvCmds[i][j] = 0;
            }
        }

        gLink.receivedNothing = TRUE;
    }
    else
    {
        for (i = 0; i < gLink.playerCount; i++)
        {
            for (j = 0; j < CMD_LENGTH; j++)
            {
                recvCmds[i][j] = gLink.recvQueue.data[i][j][gLink.recvQueue.pos];
            }
        }
        gLink.recvQueue.count--;
        gLink.recvQueue.pos++;
        if (gLink.recvQueue.pos >= QUEUE_CAPACITY)
        {
            gLink.recvQueue.pos = 0;
        }
        gLink.receivedNothing = FALSE;
    }
    REG_IME = gLinkSavedIme;
}

void LinkVSync(void)
{
    if (gLink.isMaster)
    {
        switch (gLink.state)
        {
            case LINK_STATE_CONN_ESTABLISHED:
                if (gLink.serialIntrCounter < 9)
                {
                    if (gLink.hardwareError != TRUE)
                    {
                        gLink.lag = LAG_MASTER;
                    }
                    else
                    {
                        StartTransfer();
                    }
                }
                else if (gLink.lag != LAG_MASTER)
                {
                    gLink.serialIntrCounter = 0;
                    StartTransfer();
                }
                break;
            case LINK_STATE_HANDSHAKE:
                StartTransfer();
                break;
        }
    }
    else if (gLink.state == LINK_STATE_CONN_ESTABLISHED || gLink.state == LINK_STATE_HANDSHAKE)
    {
        if (++sNumVBlanksWithoutSerialIntr > 10)
        {
            if (gLink.state == LINK_STATE_CONN_ESTABLISHED)
            {
                gLink.lag = LAG_SLAVE;
            }
            if (gLink.state == LINK_STATE_HANDSHAKE)
            {
                gLink.playerCount = 0;
                gLink.link_field_F = FALSE;
            }
        }
    }
}

void Timer3Intr(void)
{
    StopTimer();
    StartTransfer();
}

void SerialCB(void)
{
    gLink.localId = SIO_MULTI_CNT->id;
    switch (gLink.state)
    {
        case LINK_STATE_CONN_ESTABLISHED:
            gLink.hardwareError = SIO_MULTI_CNT->error;
            DoRecv();
            DoSend();
            SendRecvDone();
            break;
        case LINK_STATE_HANDSHAKE:
            if (DoHandshake())
            {
                if (gLink.isMaster)
                {
                    gLink.state = LINK_STATE_INIT_TIMER;
                    gLink.serialIntrCounter = 8;
                }
                else
                {
                    gLink.state = LINK_STATE_CONN_ESTABLISHED;
                }
            }
            break;
    }
    gLink.serialIntrCounter++;
    sNumVBlanksWithoutSerialIntr = 0;
    if (gLink.serialIntrCounter == 8)
    {
        gLastRecvQueueCount = gLink.recvQueue.count;
    }
}

void StartTransfer(void)
{
    REG_SIOCNT |= SIO_START;
}

bool8 DoHandshake(void)
{
    u8 i;
    u8 playerCount;
    u16 minRecv;
#ifdef UBFIX
    u64 recvSiomlt;
#endif

    playerCount = 0;
    minRecv = 0xFFFF;
    if (gLink.handshakeAsMaster == TRUE)
    {
        REG_SIOMLT_SEND = MASTER_HANDSHAKE;
    }
    else
    {
        REG_SIOMLT_SEND = SLAVE_HANDSHAKE;
    }
#ifdef UBFIX
    recvSiomlt = REG_SIOMLT_RECV;
    memcpy(gLink.handshakeBuffer, &recvSiomlt, sizeof(gLink.handshakeBuffer));
#else
    *(u64 *)gLink.handshakeBuffer = REG_SIOMLT_RECV;
#endif
    REG_SIOMLT_RECV = 0;
    gLink.handshakeAsMaster = FALSE;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if ((gLink.handshakeBuffer[i] & ~0x3) == SLAVE_HANDSHAKE || gLink.handshakeBuffer[i] == MASTER_HANDSHAKE)
        {
            playerCount++;
            if (minRecv > gLink.handshakeBuffer[i] && gLink.handshakeBuffer[i] != 0)
                minRecv = gLink.handshakeBuffer[i];
        }
        else
        {
            if (gLink.handshakeBuffer[i] != 0xFFFF)
                playerCount = 0;
            break;
        }
    }
    gLink.playerCount = playerCount;
    if (gLink.playerCount > 1 && gLink.playerCount == sHandshakePlayerCount && gLink.handshakeBuffer[0] == MASTER_HANDSHAKE)
    {
        return TRUE;
    }
    if (gLink.playerCount > 1)
    {
        gLink.link_field_F = (minRecv & 3) + 1;
    }
    else
    {
        gLink.link_field_F = 0;
    }
    sHandshakePlayerCount = gLink.playerCount;
    return FALSE;
}

void DoRecv(void)
{
    u16 recv[4];
    u8 i;
    u8 index;
#ifdef UBFIX
    u64 recvSiomlt = REG_SIOMLT_RECV;

    memcpy(recv, &recvSiomlt, sizeof(recv));
#else
    *(u64 *)recv = REG_SIOMLT_RECV;
#endif
    if (gLink.sendCmdIndex == 0)
    {
        for (i = 0; i < gLink.playerCount; i++)
        {
            if (gLink.checksum != recv[i] && sChecksumAvailable)
            {
                gLink.badChecksum = TRUE;
            }
        }
        gLink.checksum = 0;
        sChecksumAvailable = TRUE;
    }
    else
    {
        index = gLink.recvQueue.pos + gLink.recvQueue.count;
        if (index >= QUEUE_CAPACITY)
        {
            index -= QUEUE_CAPACITY;
        }
        if (gLink.recvQueue.count < QUEUE_CAPACITY)
        {
            for (i = 0; i < gLink.playerCount; i++)
            {
                gLink.checksum += recv[i];
                sRecvNonzeroCheck |= recv[i];
                gLink.recvQueue.data[i][gLink.recvCmdIndex][index] = recv[i];
            }
        }
        else
        {
            gLink.queueFull = QUEUE_FULL_RECV;
        }
        gLink.recvCmdIndex++;
        if (gLink.recvCmdIndex == CMD_LENGTH && sRecvNonzeroCheck)
        {
            gLink.recvQueue.count++;
            sRecvNonzeroCheck = 0;
        }
    }
}

void DoSend(void)
{
    if (gLink.sendCmdIndex == CMD_LENGTH)
    {
        REG_SIOMLT_SEND = gLink.checksum;
        if (!sSendBufferEmpty)
        {
            gLink.sendQueue.count--;
            gLink.sendQueue.pos++;
            if (gLink.sendQueue.pos >= QUEUE_CAPACITY)
            {
                gLink.sendQueue.pos = 0;
            }
        }
        else
        {
            sSendBufferEmpty = FALSE;
        }
    }
    else
    {
        if (!sSendBufferEmpty && gLink.sendQueue.count == 0)
        {
            sSendBufferEmpty = TRUE;
        }
        if (sSendBufferEmpty)
        {
            REG_SIOMLT_SEND = 0;
        }
        else
        {
            REG_SIOMLT_SEND = gLink.sendQueue.data[gLink.sendCmdIndex][gLink.sendQueue.pos];
        }
        gLink.sendCmdIndex++;
    }
}

void StopTimer(void)
{
    if (gLink.isMaster)
    {
        REG_TM3CNT_H &= ~TIMER_ENABLE;
        REG_TM3CNT_L = -197;
    }
}

void SendRecvDone(void)
{
    if (gLink.recvCmdIndex == CMD_LENGTH)
    {
        gLink.sendCmdIndex = 0;
        gLink.recvCmdIndex = 0;
    }
    else if (gLink.isMaster)
    {
        REG_TM3CNT_H |= TIMER_ENABLE;
    }
}

void ResetSendBuffer(void)
{
    u8 i;
    u8 j;

    gLink.sendQueue.count = 0;
    gLink.sendQueue.pos = 0;
    for (i = 0; i < CMD_LENGTH; i++)
    {
        for (j = 0; j < QUEUE_CAPACITY; j++)
            gLink.sendQueue.data[i][j] = LINKCMD_NONE;
    }
}

void ResetRecvBuffer(void)
{
    u8 i;
    u8 j;
    u8 k;

    gLink.recvQueue.count = 0;
    gLink.recvQueue.pos = 0;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH; j++)
        {
            for (k = 0; k < QUEUE_CAPACITY; k++)
                gLink.recvQueue.data[i][j][k] = LINKCMD_NONE;
        }
    }
}
