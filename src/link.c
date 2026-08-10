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

void InitLocalLinkPlayer(void);
void VBlankCB_LinkError(void);
void CB2_LinkTest(void);
static void ProcessRecvCmds(u8);
static void LinkCB_SendHeldKeys(void);
static void ResetBlockSend(void);
static bool32 InitBlockSend(const void *, size_t);
static void LinkCB_BlockSendBegin(void);
static void LinkCB_BlockSend(void);
static void LinkCB_BlockSendEnd(void);
static void SetBlockReceivedFlag(u8);
static u16 LinkTestCalcBlockChecksum(const u16 *, u16);
static void LinkTest_PrintHex(u32, u8, u8, u8);
static void LinkCB_RequestPlayerDataExchange(void);
static void Task_PrintTestData(u8);

static void LinkCB_ReadyCloseLink(void);
static void LinkCB_WaitCloseLink(void);
static void LinkCB_ReadyCloseLinkWithJP(void);
static void LinkCB_WaitCloseLinkWithJP(void);
static void LinkCB_Standby(void);
static void LinkCB_StandbyForAll(void);

static void TrySetLinkErrorBuffer(void);
static void CB2_PrintErrorMessage(void);
static bool8 IsSioMultiMaster(void);
static void SetWirelessCommType0_Internal(void);
static void DisableSerial(void);
static void EnableSerial(void);
static void CheckMasterOrSlave(void);
static void InitTimer(void);
static void EnqueueSendCmd(u16 *sendCmd);
static void DequeueRecvCmds(u16 (*recvCmds)[CMD_LENGTH]);

static void StartTransfer(void);
static bool8 DoHandshake(void);
static void DoRecv(void);
static void DoSend(void);
static void StopTimer(void);
static void SendRecvDone(void);

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
static const char sASCIIGameFreakInc[] = "GameFreak inc.";
static const char sASCIITestPrint[] = "TEST PRINT\nP0\nP1\nP2\nP3";
static const struct BgTemplate sLinkErrorBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .priority = 0
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 8,
        .priority = 1
    }
};

static const struct WindowTemplate sLinkErrorWindowTemplates[] = {
    [WIN_LINK_ERROR_TOP] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = DISPLAY_TILE_WIDTH,
        .height = 5,
        .paletteNum = 15,
        .baseBlock = 0x002
    },
    [WIN_LINK_ERROR_MID] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 6,
        .width = DISPLAY_TILE_WIDTH,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 0x098
    },
    [WIN_LINK_ERROR_BOTTOM] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 13,
        .width = DISPLAY_TILE_WIDTH,
        .height = 7,
        .paletteNum = 15,
        .baseBlock = 0x16A
    }, DUMMY_WIN_TEMPLATE
};

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

