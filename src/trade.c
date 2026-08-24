#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "cable_club.h"
#include "trade.h"
#include "evolution_scene.h"
#include "data.h"

#include "AgbRfu_LinkManager.h"
#include "bg.h"
#include "constants/union_room.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/region_map_sections.h"
#include "constants/mystery_gift.h"
#include "constants/characters.h"
#include "decompress.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokeball.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "sprite.h"
#include "sound.h"
#include "text.h"
#include "text_window.h"
#include "union_room.h"
#include "util.h"
#include "window.h"

// IDs for RunTradeMenuCallback
enum {
    CB_MAIN_MENU,
    CB_SELECTED_MON,
    CB_SHOW_MON_SUMMARY,
    CB_CONFIRM_TRADE_PROMPT,
    CB_CANCEL_TRADE_PROMPT,
    CB_READY_WAIT, // Unused in Emerald, equivalent to CB_IDLE
    CB_SET_SELECTED_MONS,
    CB_PRINT_IS_THIS_OKAY,
    CB_HANDLE_TRADE_CANCELED,
    CB_FADE_TO_START_TRADE,
    CB_WAIT_TO_START_TRADE,
    CB_INIT_EXIT_CANCELED_TRADE,
    CB_EXIT_CANCELED_TRADE,
    CB_START_LINK_TRADE,
    CB_INIT_CONFIRM_TRADE_PROMPT,
    CB_UNUSED_CLOSE_MSG,
    CB_WAIT_TO_START_RFU_TRADE,
    CB_PARTNER_MON_INVALID,
    CB_IDLE = 100,
};

enum {
    STATUS_NONE,
    STATUS_READY,
    STATUS_CANCEL,
};

struct TradeMenu
{
    u8 bg2hofs;
    u8 bg3hofs;
    u8 filler_2[38];
    u8 partySpriteIds[2][PARTY_SIZE];
    u8 cursorSpriteId;
    u8 cursorPosition;
    u8 partyCounts[2];
    bool8 optionsActive[PARTY_SIZE * 2 + 1];
    bool8 isLiveMon[2][PARTY_SIZE];
    bool8 isEgg[2][PARTY_SIZE];
    u8 hpBarLevels[2][PARTY_SIZE];
    u8 bufferPartyState;
    u8 filler_6A[5];
    u8 callbackId;
    u8 neverRead_70;
    u16 bottomTextTileStart;
    u8 drawSelectedMonState[2];
    u8 selectedMonIdx[2];
    u8 playerSelectStatus;
    u8 partnerSelectStatus;
    u8 playerConfirmStatus;
    u8 partnerConfirmStatus;
    u8 filler_7C[2];
    u8 partnerCursorPosition;
    u16 linkData[20];
    u8 timer;
    u8 giftRibbons[GIFT_RIBBONS_COUNT];
    u8 filler_B4[0x81C];
    struct {
        bool8 active;
        u16 delay;
        u8 actionId;
    } queuedActions[4];
    u16 tilemapBuffer[BG_SCREEN_SIZE / 2];
};

extern struct TradeMenu *sTradeMenu;
extern u8 *sMenuTextTileBuffer;
extern u8 *sMenuTextTileBuffers[];
static void RedrawPartyWindow(u8 whichParty);
extern const struct BgTemplate gUnknown_8300C04[];
extern const struct WindowTemplate gUnknown_8300C14[];
extern void VBlankCB_TradeMenu(void);
extern const u16 sTradeMovesBoxTilemap[];
extern const u16 sTradePartyBoxTilemap[];
extern const u8 sTradeStripesBG2Tilemap[];
extern const u8 sTradeStripesBG3Tilemap[];

static bool32 IsWirelessTrade(void);
static void CB2_CreateTradeMenu(void);
static void CB2_TradeMenu(void);

// Sprite tags for the menu text (JP layout: no CANCEL_R, 6 Choose-Pokémon sprites)
enum {
    GFXTAG_PLAYER_NAME_L,
    GFXTAG_PLAYER_NAME_M,
    GFXTAG_PLAYER_NAME_R,
    GFXTAG_PARTNER_NAME_L,
    GFXTAG_PARTNER_NAME_M,
    GFXTAG_PARTNER_NAME_R,
    GFXTAG_CANCEL_L,
    GFXTAG_CHOOSE_PKMN_L,
    GFXTAG_CHOOSE_PKMN_M,
    GFXTAG_CHOOSE_PKMN_R,
    GFXTAG_CHOOSE_PKMN_EMPTY_1, // 6 sprites to cover the full bottom bar, but only first 3 are needed
    GFXTAG_CHOOSE_PKMN_EMPTY_2,
    GFXTAG_CHOOSE_PKMN_EMPTY_3,
    NUM_MENU_TEXT_SPRITES
};

enum {
    TEXT_CANCEL,
    TEXT_CHOOSE_MON,
    TEXT_SUMMARY,
    TEXT_TRADE,
    TEXT_CANCEL_TRADE,
    TEXT_JP_QUIT,
};

// Indexes for sMessages
enum {
    MSG_STANDBY,
    MSG_CANCELED,
    MSG_ONLY_MON1,
    MSG_ONLY_MON2,
    MSG_WAITING_FOR_FRIEND,
    MSG_FRIEND_WANTS_TO_TRADE,
    MSG_MON_CANT_BE_TRADED,
    MSG_EGG_CANT_BE_TRADED,
    MSG_FRIENDS_MON_CANT_BE_TRADED,
};

// IDs for QueueAction
enum {
    QUEUE_SEND_DATA,
    QUEUE_STANDBY,
    QUEUE_ONLY_MON1,
    QUEUE_ONLY_MON2,
    QUEUE_UNUSED1, // Presumably intended for MSG_WAITING_FOR_FRIEND
    QUEUE_UNUSED2, // Presumably intended for MSG_FRIEND_WANTS_TO_TRADE
    QUEUE_MON_CANT_BE_TRADED,
    QUEUE_EGG_CANT_BE_TRADED,
    QUEUE_FRIENDS_MON_CANT_BE_TRADED,
};

#define QUEUE_DELAY_MSG   3
#define QUEUE_DELAY_DATA  5

// Checked to confirm DrawSelectedMonScreen has reached final state
#define DRAW_SELECTED_FINISH 5

enum {
    CURSOR_ANIM_NORMAL,
    CURSOR_ANIM_ON_CANCEL,
};

#define NUM_PLAYER_NAME_SPRITES 3
#define NUM_PARTNER_NAME_SPRITES 3
#define NUM_CHOOSE_PKMN_SPRITES 6 // JP creates all 6 Choose-Pokémon sprites
#define GFXTAG_MENU_TEXT 200 // Used as a base tag in CB2_CreateTradeMenu and CB2_ReturnToTradeMenu

static u32 GetNumQueuedActions(void);
extern void CB2_ReturnToFieldFromMultiplayer(void);
void sub_080790C8(u8 side);
static u8 GetMonNicknameWidth(u8 *str, u8 whichParty, u8 partyIdx);
static void BufferMovesString(u8 *str, u8 whichParty, u8 partyIdx);
static void PrintLevelAndGender(u8 whichParty, u8 monIdx, u8 x, u8 y, u8 width, u8 height);
static void PrintPartyLevelsAndGenders(u8 whichParty);
static void DoQueuedActions(void);
static void PrintPartyNicknames(u8 whichParty);
static bool8 LoadUISpriteGfx(void);
extern const struct SpritePalette gUnknown_83008DC;
extern const struct SpritePalette gUnknown_830083C;
extern const struct SpriteSheet gUnknown_8300834;
extern const u16 gUnknown_830D0E8[];
extern const struct SpriteSheet gUnknown_830CF5C;
extern const struct SpritePalette gUnknown_830CF64;
extern const struct SpriteSheet gUnknown_830CFB4;
extern const struct SpriteSheet gUnknown_830D004;
extern const struct SpriteSheet gUnknown_830D038;
extern const struct SpriteSheet gUnknown_830D0B0;
extern const struct SpritePalette gUnknown_830CFBC;
extern const struct SpritePalette gUnknown_830CFC4;
extern const struct BgTemplate gUnknown_830D294[];
extern const struct WindowTemplate gUnknown_830D27C[];
extern u8 gUnknown_20226A8[];
extern const struct InGameTrade gUnknown_830D114[];
extern u8 gStringVar1[0x100];
extern u8 gStringVar2[0x100];
extern u8 gStringVar3[0x100];
extern const s8 gUnknown_830D2A4[];
extern const u16 gUnknown_830D204[][MAIL_WORDS_COUNT + 1];
extern u8 gStringVar4[0x3E8];
extern const u8 gUnknown_8595430[];
extern const u8 gText_SavingDontTurnOffPower[];
extern u8 *StringExpandPlaceholders(u8 *dest, const u8 *src);
extern void IncrementGameStat(u8 index);
extern u16 Random(void);
extern void FadeOutBGMTemporarily(u8 speed);
extern bool8 IsBGMStopped(void);
extern void MysteryGift_TryIncrementStat(u32 stat, u32 trainerId);
extern void SetContinueGameWarpStatusToDynamicWarp(void);
extern void ClearContinueGameWarpStatus(void);
extern bool8 LinkFullSave_Init(void);
extern bool8 LinkFullSave_WriteSector(void);
extern bool8 LinkFullSave_ReplaceLastSector(void);
extern bool8 LinkFullSave_SetLastSectorSignature(void);
extern void FreeMonSpritesGfx(void);
extern void FieldCB_ContinueScriptHandleMusic(void);
extern void LockPlayerFieldControls(void);
extern void (*gFieldCallback)(void);
extern u8 FlagSet(u16 id);
extern const u16 gUnknown_830BCE4[];
extern const u16 gUnknown_830BEE4[];
extern const u16 gUnknown_830C0E4[];
extern const u8 gUnknown_830D310[][2];
extern const u16 gUnknown_8305D24[];
extern const u16 gUnknown_8305D84[];
extern const u16 gUnknown_8304D04[];
extern const u16 gUnknown_830ABE4[];
extern const u16 gUnknown_8309BE4[];
extern const u32 gUnknown_830BBE4[];
extern const u16 gUnknown_8302D64[];
extern const u32 gUnknown_830C104[];
extern const u32 gUnknown_830C794[];
extern const u16 gUnknown_83071A4[];
extern const u16 gUnknown_83099E4[];
extern const u16 gUnknown_8309AE4[];
extern void LZ77UnCompVram(const u32 *src, void *dest);
void DrawTextOnTradeWindow(u8 windowId, const u8 *str, u8 speed);
static void CB2_FreeTradeAnim(void);
static void Task_InGameTrade(u8 taskId);
extern u16 gSpecialVar_0x8004;
extern u16 gSpecialVar_0x8005;
void CB2_InGameTradeAnim(void);

// JP trade-animation state (fields used by the affine setup below; the
// layout of the leading region differs from the US TradeAnim struct).
struct TradeAnim
{
    struct Pokemon tempMon;    // 0x00
    u32 timer;               // 0x64
    u32 monPersonalities[2]; // 0x68
    u8 filler_70[2];         // 0x70
    u8 playerFinishStatus;   // 0x72
    u8 partnerFinishStatus;  // 0x73
    u16 linkData[10];        // 0x74
    u8 linkTimeoutZero1;   // 0x88
    u8 linkTimeoutZero2;   // 0x89
    u16 linkTimeoutTimer;  // 0x8A
    u16 neverRead_8C;      // 0x8C
    u8 monSpriteIds[2];    // 0x8E
    u8 connectionSpriteId1; // 0x90
    u8 connectionSpriteId2; // 0x91
    u8 cableEndSpriteId;    // 0x92
    u8 scheduleLinkTransfer; // 0x93
    u16 state;             // 0x94
    u8 filler_96[0x3C];    // 0x96
    u8 releasePokeballSpriteId; // 0xD2
    u8 bouncingPokeballSpriteId; // 0xD3
    u16 texX;       // 0xD4
    u16 texY;       // 0xD6
    u16 neverRead_D8;   // 0xD8
    u16 neverRead_DA;   // 0xDA
    u16 scrX;               // 0xDC
    u16 scrY;               // 0xDE
    s16 bg1vofs;            // 0xE0
    s16 bg1hofs;            // 0xE2
    s16 bg2vofs;            // 0xE4
    s16 bg2hofs;            // 0xE6
    u16 sXY;                // 0xE8
    u16 gbaScale;           // 0xEA
    u16 alpha;              // 0xEC
    u8 isLinkTrade;         // 0xEE
    u8 filler_EF[1];
    u16 monSpecies[2];  // 0xF0
    u16 cachedMapMusic;     // 0xF4
    u8 textColors[3];       // 0xF6
    u8 filler_F9[1];        // 0xF9
    u8 isCableTrade;        // 0xFA
    u8 wirelessWinLeft;     // 0xFB
    u8 wirelessWinTop;      // 0xFC
    u8 wirelessWinRight;    // 0xFD
    u8 wirelessWinBottom;   // 0xFE
    u8 filler_FF;           // 0xFF
};

extern struct TradeAnim *gUnknown_2031F40;

// JP in-game trade data. Each entry is 0x3C bytes; the leading fields differ
// from the US struct (nickname is at 0x00 and otName at 0x2B, with no mail
// struct embedded). Species IDs follow the JP ROM's internal ordering.
struct InGameTrade
{
    u8 nickname[12];            // 0x00
    u16 species;                // 0x0C
    u8 ivs[NUM_STATS];          // 0x0E
    u8 abilityNum;              // 0x14
    u8 filler_15[3];            // 0x15
    u32 otId;                   // 0x18
    u8 conditions[CONTEST_CATEGORIES_COUNT]; // 0x1C
    u8 filler_21;               // 0x21
    u8 filler_22[2];            // 0x22
    u32 personality;            // 0x24
    u16 heldItem;               // 0x28
    u8 mailNum;                 // 0x2A
    u8 otName[11];              // 0x2B
    u8 otGender;                // 0x36
    u8 sheen;                   // 0x37
    u16 requestedSpecies;       // 0x38
    u8 filler_3A[2];            // 0x3A
};                              // size: 0x3C

static void CB2_UpdateLinkTrade(void);
static void CB2_WaitTradeComplete(void);
static void CB2_TryLinkTradeEvolution(void);
static void CB2_SaveAndEndTrade(void);
static void CB2_SaveAndEndWirelessTrade(void);
static bool8 DoTradeAnim_Cable(void);
static bool8 DoTradeAnim_Wireless(void);
static void SpriteCB_BouncingPokeballDepart(struct Sprite *sprite);
static void SpriteCB_BouncingPokeballDepartEnd(struct Sprite *sprite);
static void SpriteCB_BouncingPokeballArrive(struct Sprite *sprite);
static void Task_AnimateWirelessSignal(u8 taskId);
static void Task_OpenCenterWhiteColumn(u8 taskId);
static void Task_CloseCenterWhiteColumn(u8 taskId);
static void CheckPartnersMonForRibbons(void);
static void BufferInGameTradeMonName(void);
static void CreateInGameTradePokemonInternal(u8 whichPlayerMon, u8 whichInGameTrade);
static void GetInGameTradeMail(struct Mail *mail, const struct InGameTrade *trade);
extern struct MonSpritesGfx *gMonSpritesGfxPtr;
extern const struct CompressedSpriteSheet gMonFrontPicTable[];
void DrawBottomRowText(const u8 *str, u8 *dest, u8 unused);
static void SetTradePartyHPBarSprites(void);
void sub_080C66A4(const u8 *str, u8 *buffer, u8 x, u8 y, void *decompBuffer);
static void PrintTradeMessage(u8 messageId);
extern const u8 *const gUnknown_8300BDC[];
static bool8 BufferTradeParties(void);
static void SaveTradeGiftRibbons(void);
static void ComputePartyTradeableFlags(u8 whichParty);
static void ComputePartyHPBarLevels(u8 whichParty);
void CB1_UpdateLink(void);
static void SetSelectedMon(u8 cursorPosition);
static void QueueAction(u16 delay, u8 actionId);
static void PrintTradePartnerPartyNicknames(void);
static u32 CanTradeSelectedMon(struct Pokemon *playerParty, int partyCount, int monIdx);
u8 CheckValidityOfTradeMons(u8 *aliveMons, u8 playerPartyCount, u8 playerMonIdx, u8 partnerMonIdx);
extern void sub_08198964(u8 a1, u8 a2, u8 a3, u8 a4, const u8 *text);
extern u8 sub_081984B0(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos);
extern void CreateYesNoMenuAtPos(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
extern u8 *StringCopy10(u8 *dest, const u8 *src);
extern u8 *StringCopy(u8 *dest, const u8 *src);
extern u8 *StringAppend(u8 *dest, const u8 *src);
extern const u8 gMoveNames[][MOVE_NAME_LENGTH + 1];
extern const u8 gUnknown_8300A8A[];
extern const u8 gUnknown_8300A9E[];
extern const u8 gUnknown_8300AA9[];
extern const u8 gUnknown_8300AAE[];
extern const u8 gUnknown_8300AA0[];
extern const u8 gUnknown_8300AA2[];
extern const u8 gUnknown_8300AA5[];
extern const u8 gUnknown_8300AB1[];
extern const u8 gUnknown_8300C00[];
extern const u8 gUnknown_8300A9B[];
extern const u8 gUnknown_8300A36[][2];
extern const u8 gUnknown_8300A4E[][2];
extern const u8 gUnknown_8300A1C[][2];
extern const u8 gUnknown_8300D40[][2];
extern const struct SpriteTemplate gUnknown_830CF6C;
extern const struct SpriteTemplate gUnknown_830CFCC;
extern const struct SpriteTemplate gUnknown_830D00C;
extern const struct SpriteTemplate gUnknown_830D040;
extern const struct SpriteTemplate gUnknown_830D0B8;
extern const struct SpriteTemplate gUnknown_830D0D0;
extern const union AffineAnimCmd *const gUnknown_830D110[];
extern const u8 gUnknown_830D240[];
extern const u8 gUnknown_830D24F[];
extern const u8 gUnknown_830D258[];
extern const u8 gUnknown_830D26A[];
extern const struct MenuAction sSelectTradeMonActions[];
extern const struct WindowTemplate sTradeYesNoWindowTemplate;
static void LoadTradeBgGfx(u8 state);
static void SetActiveMenuOptions(void);

extern const u8 sTradeMonSpriteCoords[][2];
extern const u8 sCursorMoveDestinations[][4][6];
extern const struct SpriteTemplate sSpriteTemplate_MenuText;
extern const struct SpriteTemplate sSpriteTemplate_Cursor;
extern const u8 *const sActionTexts[];

static bool8 SendLinkData(const void *linkData, u32 size)
{
    if (gPlayerCurrActivity == ACTIVITY_29)
    {
        rfu_NI_setSendData(lman.acceptSlot_flag, 84, linkData, size);
        return TRUE;
    }
    else
    {
        return SendBlock(0, linkData, size);
    }
}

static void RequestLinkData(u8 type)
{
    SendBlockRequest(type);
}

static bool32 IsLinkTradeTaskFinished(void)
{
    if (gPlayerCurrActivity == ACTIVITY_29)
    {
        if (gRfuSlotStatusNI[Rfu_GetIndexOfNewestChild(lman.acceptSlot_flag)]->send.state == 0)
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        return IsLinkTaskFinished();
    }
}

static u32 _GetBlockReceivedStatus(void)
{
    return GetBlockReceivedStatus();
}

static void TradeResetReceivedFlags(void)
{
    if (IsWirelessTrade())
        rfu_clearSlot(12, lman.acceptSlot_flag);
    else
        ResetBlockReceivedFlags();
}

static void TradeResetReceivedFlag(u32 who)
{
    if (IsWirelessTrade())
        rfu_clearSlot(12, lman.acceptSlot_flag);
    else
        ResetBlockReceivedFlag(who);
}

static bool32 IsWirelessTrade(void)
{
    if (gWirelessCommType && gPlayerCurrActivity == ACTIVITY_29)
        return TRUE;
    else
        return FALSE;
}

static void SetTradeLinkStandbyCallback(u8 unused)
{
    SetLinkStandbyCallback();
}

static bool32 _IsLinkTaskFinished(void)
{
    return IsLinkTaskFinished();
}

static void InitTradeMenu(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ResetPaletteFade();

    gPaletteFade.bufferTransferDisabled = TRUE;

    SetVBlankCallback(VBlankCB_TradeMenu);
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZEOF(10));
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(13), PLTT_SIZEOF(10));
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_8300C04, 4);
    SetBgTilemapBuffer(1, sTradeMenu->tilemapBuffer);

    if (InitWindows(gUnknown_8300C14))
    {
        u32 i;

        DeactivateAllTextPrinters();

        for (i = 0; i < 18; i++)
        {
            ClearWindowTilemap(i);
            FillWindowPixelBuffer(i, PIXEL_FILL(0));
        }

        FillBgTilemapBufferRect(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT, 15);
        LoadUserWindowBorderGfx_(0, 20, BG_PLTT_ID(12));
        LoadUserWindowBorderGfx(2, 1, BG_PLTT_ID(14));
        LoadMonIconPalettes();
        sTradeMenu->bufferPartyState = 0;
        sTradeMenu->callbackId = CB_MAIN_MENU;
        sTradeMenu->neverRead_70 = 0;
        sTradeMenu->drawSelectedMonState[TRADE_PLAYER] = 0;
        sTradeMenu->drawSelectedMonState[TRADE_PARTNER] = 0;
        sTradeMenu->playerConfirmStatus = STATUS_NONE;
        sTradeMenu->partnerConfirmStatus = STATUS_NONE;
        sTradeMenu->timer = 0;
    }
}

void CB2_StartCreateTradeMenu(void)
{
    SetMainCallback2(CB2_CreateTradeMenu);
    gMain.callback1 = NULL;
    gEnemyPartyCount = 0;
}

static void CB2_CreateTradeMenu(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;
    u16 nameLen;

    switch (gMain.state)
    {
    case 0:
        sTradeMenu = AllocZeroed(sizeof(*sTradeMenu));
        InitTradeMenu();
        sMenuTextTileBuffer = AllocZeroed(NUM_MENU_TEXT_SPRITES * 256);

        for (i = 0; i < NUM_MENU_TEXT_SPRITES; i++)
            sMenuTextTileBuffers[i] = &sMenuTextTileBuffer[i * 256];

        gMain.state++;
        break;
    case 1:
        gPaletteFade.bufferTransferDisabled = FALSE;

        for (i = 0; i < PARTY_SIZE; i++)
            CreateMon(&gEnemyParty[i], SPECIES_NONE, 0, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);

        PrintTradeMessage(MSG_STANDBY);
        ShowBg(0);

        if (!gReceivedRemoteLinkPlayers)
        {
            gLinkType = LINKTYPE_TRADE_CONNECTING;
            sTradeMenu->timer = 0;

            if (gWirelessCommType)
            {
                SetWirelessCommType1();
                OpenLink();
                CreateTask_RfuIdle();
            }
            else
            {
                OpenLink();
                gMain.state++;
                CreateTask(Task_WaitForLinkPlayerConnection, 1);
            }
        }
        else
        {
            gMain.state = 4;
        }
        break;
    case 2:
        sTradeMenu->timer++;
        if (sTradeMenu->timer > 11)
        {
            sTradeMenu->timer = 0;
            gMain.state++;
        }
        break;
    case 3:
        if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
        {
            if (IsLinkMaster())
            {
                if (++sTradeMenu->timer > 30)
                {
                    CheckShouldAdvanceLinkState();
                    gMain.state++;
                }
            }
            else
            {
                gMain.state++;
            }
        }
        break;
    case 4:
        if (gReceivedRemoteLinkPlayers == TRUE && IsLinkPlayerDataExchangeComplete() == TRUE)
        {
            DestroyTask_RfuIdle();
            CalculatePlayerPartyCount();
            gMain.state++;
            sTradeMenu->timer = 0;
            if (gWirelessCommType)
            {
                Rfu_SetLinkRecovery(TRUE);
                SetLinkStandbyCallback();
            }
        }
        break;
    case 5:
        if (gWirelessCommType)
        {
            if (IsLinkRfuTaskFinished())
            {
                gMain.state++;
                LoadWirelessStatusIndicatorSpriteGfx();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            gMain.state++;
        }
        break;
    case 6:
        if (BufferTradeParties())
        {
            SaveTradeGiftRibbons(); // SaveTradeGiftRibbons
            gMain.state++;
        }
        break;
    case 7:
        CalculateEnemyPartyCount();
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        sTradeMenu->partyCounts[TRADE_PLAYER] = gPlayerPartyCount;
        sTradeMenu->partyCounts[TRADE_PARTNER] = gEnemyPartyCount;

        for (i = 0; i < sTradeMenu->partyCounts[TRADE_PLAYER]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            sTradeMenu->partySpriteIds[TRADE_PLAYER][i] = CreateMonIcon(GetMonData3(mon, MON_DATA_SPECIES_OR_EGG),
                                                         SpriteCB_MonIcon,
                                                         (sTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (sTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData3(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < sTradeMenu->partyCounts[TRADE_PARTNER]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            sTradeMenu->partySpriteIds[TRADE_PARTNER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES_OR_EGG, NULL),
                                                         SpriteCB_MonIcon,
                                                         (sTradeMonSpriteCoords[i + PARTY_SIZE][0] * 8) + 14,
                                                         (sTradeMonSpriteCoords[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        DrawHeldItemIconsForTrade(&sTradeMenu->partyCounts[0], sTradeMenu->partySpriteIds[0], TRADE_PLAYER);
        gMain.state++;
        break;
    case 9:
        DrawHeldItemIconsForTrade(&sTradeMenu->partyCounts[0], sTradeMenu->partySpriteIds[0], TRADE_PARTNER);
        gMain.state++;
        break;
    case 10:
        sub_080C66A4(gSaveBlock2Ptr->playerName, sMenuTextTileBuffers[GFXTAG_PLAYER_NAME_L], 0, 0, gDecompressionBuffer);
        id = GetMultiplayerId();
        sub_080C66A4(gLinkPlayers[id ^ 1].name, sMenuTextTileBuffers[GFXTAG_PARTNER_NAME_L], 0, 0, gDecompressionBuffer);
        sub_080C66A4(sActionTexts[TEXT_CANCEL], sMenuTextTileBuffers[GFXTAG_CANCEL_L], 0, 0, gDecompressionBuffer);
        DrawBottomRowText(sActionTexts[TEXT_CHOOSE_MON], sMenuTextTileBuffers[GFXTAG_CHOOSE_PKMN_L], 24);
        gMain.state++;
        sTradeMenu->timer = 0;
        break;
    case 11:
        if (LoadUISpriteGfx())
            gMain.state++;
        break;
    case 12:
        // Create player's name text sprites (JP inlines the 8px-font centering)
        nameLen = StringLength(gSaveBlock2Ptr->playerName);
        xPos = 76 - nameLen * 4;
        for (i = 0; i < NUM_PLAYER_NAME_SPRITES; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_PLAYER_NAME_L;
            CreateSprite(&temp, xPos + (i * 32), 8, 1);
        }

        // Create partner's name text sprites
        nameLen = StringLength(gLinkPlayers[GetMultiplayerId() ^ 1].name);
        xPos = 196 - nameLen * 4;
        for (i = 0; i < NUM_PARTNER_NAME_SPRITES; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_PARTNER_NAME_L;
            CreateSprite(&temp, xPos + (i * 32), 8, 1);
        }
        gMain.state++;
        break;
    case 13:
        // Create Cancel text sprite
        temp = sSpriteTemplate_MenuText;
        temp.tileTag += GFXTAG_CANCEL_L;
        CreateSprite(&temp, 224, 152, 1);

        // Create Choose a Pokémon text sprites (JP creates all 6)
        for (i = 0; i < NUM_CHOOSE_PKMN_SPRITES; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_CHOOSE_PKMN_L;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        sTradeMenu->cursorSpriteId = CreateSprite(&sSpriteTemplate_Cursor,
                                                     sTradeMonSpriteCoords[0][0] * 8 + 32,
                                                     sTradeMonSpriteCoords[0][1] * 8, 2);
        sTradeMenu->cursorPosition = 0;
        gMain.state++;
        rbox_fill_rectangle(0);
        break;
    case 14:
        ComputePartyTradeableFlags(TRADE_PLAYER);
        PrintPartyNicknames(TRADE_PLAYER);
        sTradeMenu->bg2hofs = 0;
        sTradeMenu->bg3hofs = 0;
        SetActiveMenuOptions();
        gMain.state++;
        PlayBGM(MUS_SCHOOL);
        break;
    case 15:
        ComputePartyTradeableFlags(TRADE_PARTNER);
        PrintPartyNicknames(TRADE_PARTNER);
        gMain.state++;
        // fallthrough
    case 16:
        LoadTradeBgGfx(0);
        gMain.state++;
        break;
    case 17:
        LoadTradeBgGfx(1);
        gMain.state++;
        break;
    case 18:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        LoadTradeBgGfx(2);
        gMain.state++;
        break;
    case 20:
        ComputePartyHPBarLevels(TRADE_PLAYER);
        gMain.state++;
        break;
    case 21:
        ComputePartyHPBarLevels(TRADE_PARTNER);
        SetTradePartyHPBarSprites();
        gMain.state++;
        break;
    case 22:
        if (!gPaletteFade.active)
        {
            gMain.callback1 = CB1_UpdateLink; // CB1_UpdateLink
            SetMainCallback2(CB2_TradeMenu);
        }
        break;
    }

    RunTextPrinters();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CB2_ReturnToTradeMenu(void)
{
    int i;
    struct SpriteTemplate temp;
    u8 id;
    u32 xPos;
    u16 nameLen;

    switch (gMain.state)
    {
    case 0:
        InitTradeMenu();
        gMain.state++;
        break;
    case 1:
        gMain.state++;
        sTradeMenu->timer = 0;
        break;
    case 2:
        gMain.state++;
        break;
    case 3:
        gMain.state++;
        break;
    case 4:
        CalculatePlayerPartyCount();
        gMain.state++;
        break;
    case 5:
        if (gWirelessCommType)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        gMain.state++;
        break;
    case 6:
        gMain.state++;
        break;
    case 7:
        CalculateEnemyPartyCount();
        sTradeMenu->partyCounts[TRADE_PLAYER] = gPlayerPartyCount;
        sTradeMenu->partyCounts[TRADE_PARTNER] = gEnemyPartyCount;
        ClearWindowTilemap(0);
        PrintPartyNicknames(TRADE_PLAYER);
        PrintPartyNicknames(TRADE_PARTNER);

        for (i = 0; i < sTradeMenu->partyCounts[TRADE_PLAYER]; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            sTradeMenu->partySpriteIds[TRADE_PLAYER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES_OR_EGG, NULL),
                                                         SpriteCB_MonIcon,
                                                         (sTradeMonSpriteCoords[i][0] * 8) + 14,
                                                         (sTradeMonSpriteCoords[i][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         TRUE);
        }

        for (i = 0; i < sTradeMenu->partyCounts[TRADE_PARTNER]; i++)
        {
            struct Pokemon *mon = &gEnemyParty[i];
            sTradeMenu->partySpriteIds[TRADE_PARTNER][i] = CreateMonIcon(GetMonData(mon, MON_DATA_SPECIES_OR_EGG, NULL),
                                                         SpriteCB_MonIcon,
                                                         (sTradeMonSpriteCoords[i + PARTY_SIZE][0] * 8) + 14,
                                                         (sTradeMonSpriteCoords[i + PARTY_SIZE][1] * 8) - 12,
                                                         1,
                                                         GetMonData(mon, MON_DATA_PERSONALITY),
                                                         FALSE);
        }
        gMain.state++;
        break;
    case 8:
        LoadHeldItemIcons();
        DrawHeldItemIconsForTrade(&sTradeMenu->partyCounts[0], sTradeMenu->partySpriteIds[0], TRADE_PLAYER);
        gMain.state++;
        break;
    case 9:
        DrawHeldItemIconsForTrade(&sTradeMenu->partyCounts[0], sTradeMenu->partySpriteIds[0], TRADE_PARTNER);
        gMain.state++;
        break;
    case 10:
        sub_080C66A4(gSaveBlock2Ptr->playerName, sMenuTextTileBuffers[GFXTAG_PLAYER_NAME_L], 0, 0, gDecompressionBuffer);
        id = GetMultiplayerId();
        sub_080C66A4(gLinkPlayers[id ^ 1].name, sMenuTextTileBuffers[GFXTAG_PARTNER_NAME_L], 0, 0, gDecompressionBuffer);
        sub_080C66A4(sActionTexts[TEXT_CANCEL], sMenuTextTileBuffers[GFXTAG_CANCEL_L], 0, 0, gDecompressionBuffer);
        DrawBottomRowText(sActionTexts[TEXT_CHOOSE_MON], sMenuTextTileBuffers[GFXTAG_CHOOSE_PKMN_L], 24);
        gMain.state++;
        sTradeMenu->timer = 0;
        break;
    case 11:
        if (LoadUISpriteGfx())
            gMain.state++;
        break;
    case 12:
        // Create player's name text sprites (JP inlines the 8px-font centering)
        nameLen = StringLength(gSaveBlock2Ptr->playerName);
        xPos = 76 - nameLen * 4;
        for (i = 0; i < NUM_PLAYER_NAME_SPRITES; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_PLAYER_NAME_L;
            CreateSprite(&temp, xPos + (i * 32), 8, 1);
        }

        // Create partner's name text sprites
        nameLen = StringLength(gLinkPlayers[GetMultiplayerId() ^ 1].name);
        xPos = 196 - nameLen * 4;
        for (i = 0; i < NUM_PARTNER_NAME_SPRITES; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_PARTNER_NAME_L;
            CreateSprite(&temp, xPos + (i * 32), 8, 1);
        }
        gMain.state++;
        break;
    case 13:
        // Create Cancel text sprite
        temp = sSpriteTemplate_MenuText;
        temp.tileTag += GFXTAG_CANCEL_L;
        CreateSprite(&temp, 224, 152, 1);

        // Create Choose a Pokémon text sprites (JP creates all 6)
        for (i = 0; i < NUM_CHOOSE_PKMN_SPRITES; i++)
        {
            temp = sSpriteTemplate_MenuText;
            temp.tileTag += i + GFXTAG_CHOOSE_PKMN_L;
            CreateSprite(&temp, (i * 32) + 24, 150, 1);
        }

        if (sTradeMenu->cursorPosition < PARTY_SIZE)
            sTradeMenu->cursorPosition = gLastViewedMonIndex;
        else
            sTradeMenu->cursorPosition = gLastViewedMonIndex + PARTY_SIZE;

        sTradeMenu->cursorSpriteId = CreateSprite(&sSpriteTemplate_Cursor,
                                                     sTradeMonSpriteCoords[sTradeMenu->cursorPosition][0] * 8 + 32,
                                                     sTradeMonSpriteCoords[sTradeMenu->cursorPosition][1] * 8, 2);
        gMain.state = 16;
        break;
    case 16:
        LoadTradeBgGfx(0);
        gMain.state++;
        break;
    case 17:
        LoadTradeBgGfx(1);
        sTradeMenu->bg2hofs = 0;
        sTradeMenu->bg3hofs = 0;
        SetActiveMenuOptions();
        gMain.state++;
        break;
    case 18:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 19:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        LoadTradeBgGfx(2);
        gMain.state++;
        break;
    case 20:
        gMain.state++;
        break;
    case 21:
        SetTradePartyHPBarSprites();
        gMain.state++;
        break;
    case 22:
        if (!gPaletteFade.active)
            SetMainCallback2(CB2_TradeMenu);
        break;
    }

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_TradeMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB_FadeToStartTrade(void)
{
    if (++sTradeMenu->timer > 15)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeMenu->callbackId = CB_WAIT_TO_START_TRADE;
    }
}

static void CB_WaitToStartTrade(void)
{
    if (!gPaletteFade.active)
    {
        gSelectedTradeMonPositions[TRADE_PLAYER] = sTradeMenu->cursorPosition;
        gSelectedTradeMonPositions[TRADE_PARTNER] = sTradeMenu->partnerCursorPosition;

        if (gWirelessCommType)
        {
            sTradeMenu->callbackId = CB_WAIT_TO_START_RFU_TRADE;
        }
        else
        {
            SetCloseLinkCallbackAndType(32);
            sTradeMenu->callbackId = CB_START_LINK_TRADE;
        }
    }
}

static void CB_StartLinkTrade(void)
{
    gMain.savedCallback = CB2_StartCreateTradeMenu;

    if (gWirelessCommType)
    {
        // Wireless Link Trade
        if (IsLinkRfuTaskFinished())
        {
            Free(sMenuTextTileBuffer);
            FreeAllWindowBuffers();
            Free(sTradeMenu);
            gMain.callback1 = NULL;
            DestroyWirelessStatusIndicatorSprite();
            SetMainCallback2(CB2_LinkTrade);
        }
    }
    else
    {
        // Cable Link Trade
        if (!gReceivedRemoteLinkPlayers)
        {
            Free(sMenuTextTileBuffer);
            FreeAllWindowBuffers();
            Free(sTradeMenu);
            gMain.callback1 = NULL;
            SetMainCallback2(CB2_LinkTrade);
        }
    }
}

static void CB2_TradeMenu(void)
{
    RunTradeMenuCallback();
    DoQueuedActions();

    // As long as drawSelectedMonState is 0, these do nothing
    sub_080790C8(TRADE_PLAYER);
    sub_080790C8(TRADE_PARTNER);

    SetGpuReg(REG_OFFSET_BG2HOFS, sTradeMenu->bg2hofs++);
    SetGpuReg(REG_OFFSET_BG3HOFS, sTradeMenu->bg3hofs--);

    RunTextPrintersAndIsPrinter0Active();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void LoadTradeBgGfx(u8 state)
{
    int i;

    switch (state)
    {
    case 0:
        LoadPalette(gTradeMenu_Pal, 0, 3 * PLTT_SIZE_4BPP);
        LoadBgTiles(1, gTradeMenu_Gfx, 0x1280, 0);
        CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMenu_Tilemap, 0, 0, 32, 20, 0);
        LoadBgTilemap(2, sTradeStripesBG2Tilemap, 0x800, 0);
        break;
    case 1:
        LoadBgTilemap(3, sTradeStripesBG3Tilemap, 0x800, 0);
        PrintPartyLevelsAndGenders(TRADE_PLAYER);
        PrintPartyLevelsAndGenders(TRADE_PARTNER);
        CopyBgTilemapBufferToVram(1);
        break;
    case 2:
        for (i = 0; i < 4; i++)
            SetGpuReg((u8)(REG_OFFSET_BG0HOFS + (i * 2)), 0);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        break;
    }
}

static void SetActiveMenuOptions(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i < sTradeMenu->partyCounts[TRADE_PLAYER])
        {
            // Present player Pokémon
            gSprites[sTradeMenu->partySpriteIds[TRADE_PLAYER][i]].invisible = FALSE;
            sTradeMenu->optionsActive[i] = TRUE;
        }
        else
        {
            // Absent player Pokémon
            sTradeMenu->optionsActive[i] = FALSE;
        }

        if (i < sTradeMenu->partyCounts[TRADE_PARTNER])
        {
            // Present partner Pokémon
            gSprites[sTradeMenu->partySpriteIds[TRADE_PARTNER][i]].invisible = FALSE;
            sTradeMenu->optionsActive[i + PARTY_SIZE] = TRUE;
        }
        else
        {
            // Absent partner Pokémon
            sTradeMenu->optionsActive[i + PARTY_SIZE] = FALSE;
        }
    }

    // Cancel is always active
    sTradeMenu->optionsActive[PARTY_SIZE * 2] = TRUE;
}


void Trade_Memcpy(void *dest, const void *src, u32 size)
{
    u8 *_dest = dest;
    const u8 *_src = src;
    u32 i;

    for (i = 0; i < size; i++)
        _dest[i] = _src[i];
}

static bool8 BufferTradeParties(void)
{
    u8 id = GetMultiplayerId();

    switch (sTradeMenu->bufferPartyState)
    {
    case 0:
        // The parties are sent in pairs rather than all at once
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[0], 2 * sizeof(struct Pokemon));
        sTradeMenu->bufferPartyState++;
        sTradeMenu->timer = 0;
        break;
    case 1:
        if (IsLinkTradeTaskFinished())
        {
            if (_GetBlockReceivedStatus() == 0)
            {
                sTradeMenu->bufferPartyState++;
            }
            else
            {
                TradeResetReceivedFlags();
                sTradeMenu->bufferPartyState++;
            }
        }
        break;
    case 3:
        if (id == 0)
            RequestLinkData(BLOCK_REQ_SIZE_200);
        sTradeMenu->bufferPartyState++;
        break;
    case 4:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[0], gBlockRecvBuffer[id ^ 1], 2 * sizeof(struct Pokemon));
            TradeResetReceivedFlags();
            sTradeMenu->bufferPartyState++;
        }
        break;
    case 5:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[2], 2 * sizeof(struct Pokemon));
        sTradeMenu->bufferPartyState++;
        break;
    case 7:
        if (id == 0)
            RequestLinkData(BLOCK_REQ_SIZE_200);
        sTradeMenu->bufferPartyState++;
        break;
    case 8:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[2], gBlockRecvBuffer[id ^ 1], 2 * sizeof(struct Pokemon));
            TradeResetReceivedFlags();
            sTradeMenu->bufferPartyState++;
        }
        break;
    case 9:
        Trade_Memcpy(gBlockSendBuffer, &gPlayerParty[4], 2 * sizeof(struct Pokemon));
        sTradeMenu->bufferPartyState++;
        break;
    case 11:
        if (id == 0)
            RequestLinkData(BLOCK_REQ_SIZE_200);
        sTradeMenu->bufferPartyState++;
        break;
    case 12:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(&gEnemyParty[4], gBlockRecvBuffer[id ^ 1], 2 * sizeof(struct Pokemon));
            TradeResetReceivedFlags();
            sTradeMenu->bufferPartyState++;
        }
        break;
    case 13:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->mail, PARTY_SIZE * sizeof(struct Mail) + 4);
        sTradeMenu->bufferPartyState++;
        break;
    case 15:
        if (id == 0)
            RequestLinkData(BLOCK_REQ_SIZE_220);
        sTradeMenu->bufferPartyState++;
        break;
    case 16:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(gTradeMail, gBlockRecvBuffer[id ^ 1], PARTY_SIZE * sizeof(struct Mail));
            TradeResetReceivedFlags();
            sTradeMenu->bufferPartyState++;
        }
        break;
    case 17:
        Trade_Memcpy(gBlockSendBuffer, gSaveBlock1Ptr->giftRibbons, sizeof(sTradeMenu->giftRibbons));
        sTradeMenu->bufferPartyState++;
        break;
    case 19:
        if (id == 0)
            RequestLinkData(BLOCK_REQ_SIZE_40);
        sTradeMenu->bufferPartyState++;
        break;
    case 20:
        if (_GetBlockReceivedStatus() == 3)
        {
            Trade_Memcpy(sTradeMenu->giftRibbons, gBlockRecvBuffer[id ^ 1], sizeof(sTradeMenu->giftRibbons));
            TradeResetReceivedFlags();
            sTradeMenu->bufferPartyState++;
        }
        break;
    case 21:
        // JP returns TRUE here without the US Shedinja nickname fixup loop
        return TRUE;
    // Delay until next state
    case 2:
    case 6:
    case 10:
    case 14:
    case 18:
        sTradeMenu->timer++;
        if (sTradeMenu->timer > 10)
        {
            sTradeMenu->timer = 0;
            sTradeMenu->bufferPartyState++;
        }
        break;
    }
    return FALSE;
}

// JP-specific: draws "player nickname と　 partner nickname ..." in the bottom bar
static void DrawTradeMonNicknames(void)
{
    u8 nickname[0x1C];
    u8 str1[0xC];
    u8 str2[0xC];

    GetMonData(&gPlayerParty[sTradeMenu->cursorPosition], MON_DATA_NICKNAME, nickname);
    StringCopy10(str1, nickname);
    GetMonData(&gEnemyParty[sTradeMenu->partnerCursorPosition % PARTY_SIZE], MON_DATA_NICKNAME, nickname);
    StringCopy10(str2, nickname);
    StringCopy(nickname, str1);
    StringAppend(nickname, gUnknown_8300AAE);
    StringAppend(nickname, str2);
    StringAppend(nickname, gUnknown_8300AB1);
    DrawBottomRowText(nickname, (void *)(OBJ_VRAM0 + (sTradeMenu->bottomTextTileStart * 32)), 24);
}

static void Leader_ReadLinkBuffer(u8 mpId, u8 status)
{
    if (status & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case LINKCMD_REQUEST_CANCEL:
            sTradeMenu->playerSelectStatus = STATUS_CANCEL;
            break;
        case LINKCMD_READY_TO_TRADE:
            sTradeMenu->playerSelectStatus = STATUS_READY;
            break;
        case LINKCMD_INIT_BLOCK:
            sTradeMenu->playerConfirmStatus = STATUS_READY;
            break;
        case LINKCMD_READY_CANCEL_TRADE:
            sTradeMenu->playerConfirmStatus = STATUS_CANCEL;
            break;
        }
        TradeResetReceivedFlag(0);
    }

    if (status & 2)
    {
        switch (gBlockRecvBuffer[1][0])
        {
        case LINKCMD_REQUEST_CANCEL:
            sTradeMenu->partnerSelectStatus = STATUS_CANCEL;
            break;
        case LINKCMD_READY_TO_TRADE:
            sTradeMenu->partnerCursorPosition = gBlockRecvBuffer[1][1] + PARTY_SIZE;
            sTradeMenu->partnerSelectStatus = STATUS_READY;
            break;
        case LINKCMD_INIT_BLOCK:
            sTradeMenu->partnerConfirmStatus = STATUS_READY;
            break;
        case LINKCMD_READY_CANCEL_TRADE:
            sTradeMenu->partnerConfirmStatus = STATUS_CANCEL;
            break;
        }
        TradeResetReceivedFlag(1);
    }
}

static void Follower_ReadLinkBuffer(u8 mpId, u8 status)
{
    if (status & 1)
    {
        switch (gBlockRecvBuffer[0][0])
        {
        case LINKCMD_BOTH_CANCEL_TRADE:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            PrintTradeMessage(MSG_WAITING_FOR_FRIEND);
            sTradeMenu->callbackId = CB_INIT_EXIT_CANCELED_TRADE;
            break;
        case LINKCMD_PARTNER_CANCEL_TRADE:
            PrintTradeMessage(MSG_FRIEND_WANTS_TO_TRADE);
            sTradeMenu->callbackId = CB_HANDLE_TRADE_CANCELED;
            break;
        case LINKCMD_SET_MONS_TO_TRADE:
            sTradeMenu->partnerCursorPosition = gBlockRecvBuffer[0][1] + PARTY_SIZE;
            rbox_fill_rectangle(0);
            SetSelectedMon(sTradeMenu->cursorPosition);
            SetSelectedMon(sTradeMenu->partnerCursorPosition);
            sTradeMenu->callbackId = CB_PRINT_IS_THIS_OKAY;
            break;
        case LINKCMD_START_TRADE:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sTradeMenu->callbackId = CB_WAIT_TO_START_TRADE;
            break;
        case LINKCMD_PLAYER_CANCEL_TRADE:
            PrintTradeMessage(MSG_CANCELED);
            sTradeMenu->callbackId = CB_HANDLE_TRADE_CANCELED;
            break;
        }
        TradeResetReceivedFlag(0);
    }

    if (status & 2)
        TradeResetReceivedFlag(1);
}

static void Leader_HandleCommunication(void)
{
    if (sTradeMenu->playerSelectStatus != STATUS_NONE
     && sTradeMenu->partnerSelectStatus != STATUS_NONE)
    {
        if (sTradeMenu->playerSelectStatus == STATUS_READY
         && sTradeMenu->partnerSelectStatus == STATUS_READY)
        {
            // Both players have selected a Pokémon to trade
            sTradeMenu->callbackId = CB_SET_SELECTED_MONS;
            sTradeMenu->linkData[0] = LINKCMD_SET_MONS_TO_TRADE;
            sTradeMenu->linkData[1] = sTradeMenu->cursorPosition;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenu->playerSelectStatus = sTradeMenu->partnerSelectStatus = STATUS_NONE;
        }
        else if (sTradeMenu->playerSelectStatus == STATUS_READY
              && sTradeMenu->partnerSelectStatus == STATUS_CANCEL)
        {
            // The player has selected a Pokémon to trade,
            // but the partner has selected Cancel
            PrintTradeMessage(MSG_CANCELED);
            sTradeMenu->linkData[0] = LINKCMD_PARTNER_CANCEL_TRADE;
            sTradeMenu->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenu->playerConfirmStatus = sTradeMenu->partnerConfirmStatus = STATUS_NONE;
            sTradeMenu->playerSelectStatus = sTradeMenu->partnerSelectStatus = STATUS_NONE;
            sTradeMenu->callbackId = CB_HANDLE_TRADE_CANCELED;
        }
        else if (sTradeMenu->playerSelectStatus == STATUS_CANCEL
              && sTradeMenu->partnerSelectStatus == STATUS_READY)
        {
            // The partner has selected a Pokémon to trade,
            // but the player has selected cancel
            PrintTradeMessage(MSG_FRIEND_WANTS_TO_TRADE);
            sTradeMenu->linkData[0] = LINKCMD_PLAYER_CANCEL_TRADE;
            sTradeMenu->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenu->playerConfirmStatus = sTradeMenu->partnerConfirmStatus = STATUS_NONE;
            sTradeMenu->playerSelectStatus = sTradeMenu->partnerSelectStatus = STATUS_NONE;
            sTradeMenu->callbackId = CB_HANDLE_TRADE_CANCELED;
        }
        else if (sTradeMenu->playerSelectStatus == STATUS_CANCEL
              && sTradeMenu->partnerSelectStatus == STATUS_CANCEL)
        {
            // Both players have selected Cancel
            sTradeMenu->linkData[0] = LINKCMD_BOTH_CANCEL_TRADE;
            sTradeMenu->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sTradeMenu->playerSelectStatus = sTradeMenu->partnerSelectStatus = STATUS_NONE;
            sTradeMenu->callbackId = CB_INIT_EXIT_CANCELED_TRADE;
        }
    }

    if (sTradeMenu->playerConfirmStatus != STATUS_NONE
     && sTradeMenu->partnerConfirmStatus != STATUS_NONE)
    {
        if (sTradeMenu->playerConfirmStatus == STATUS_READY
         && sTradeMenu->partnerConfirmStatus == STATUS_READY)
        {
            // Both players have confirmed trade
            sTradeMenu->linkData[0] = LINKCMD_START_TRADE;
            sTradeMenu->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenu->playerConfirmStatus = STATUS_NONE;
            sTradeMenu->partnerConfirmStatus = STATUS_NONE;
            sTradeMenu->callbackId = CB_FADE_TO_START_TRADE;
        }

        if (sTradeMenu->playerConfirmStatus == STATUS_CANCEL
         || sTradeMenu->partnerConfirmStatus == STATUS_CANCEL)
        {
            // One of the players has decided not to confirm the trade,
            // or the trade was not allowed.
            PrintTradeMessage(MSG_CANCELED);
            sTradeMenu->linkData[0] = LINKCMD_PLAYER_CANCEL_TRADE;
            sTradeMenu->linkData[1] = 0;
            QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
            sTradeMenu->playerConfirmStatus = STATUS_NONE;
            sTradeMenu->partnerConfirmStatus = STATUS_NONE;
            sTradeMenu->callbackId = CB_HANDLE_TRADE_CANCELED;
        }
    }
}

static void _SetLinkData(u16 *linkData, u16 linkCmd, u16 cursorPosition)
{
    linkData[0] = linkCmd;
    linkData[1] = cursorPosition;
    QueueAction(QUEUE_DELAY_DATA, QUEUE_SEND_DATA);
}

static void SetLinkData(u16 linkCmd, u16 cursorPosition)
{
    _SetLinkData(sTradeMenu->linkData, linkCmd, cursorPosition);
}

static void CB1_UpdateLink(void)
{
    u8 mpId = GetMultiplayerId();
    u8 status;

    if ((status = _GetBlockReceivedStatus()))
    {
        if (mpId == 0)
            Leader_ReadLinkBuffer(mpId, status);
        else
            Follower_ReadLinkBuffer(mpId, status);
    }

    if (mpId == 0)
        Leader_HandleCommunication();
}

static u8 GetNewCursorPosition(u8 oldPosition, u8 direction)
{
    int i;
    u8 newPosition = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sTradeMenu->optionsActive[sCursorMoveDestinations[oldPosition][direction][i]] == TRUE)
        {
            newPosition = sCursorMoveDestinations[oldPosition][direction][i];
            break;
        }
    }

    return newPosition;
}

static void TradeMenuMoveCursor(u8 *cursorPosition, u8 direction)
{
    u8 newPosition = GetNewCursorPosition(*cursorPosition, direction);

    if (newPosition == (PARTY_SIZE * 2)) // CANCEL
    {
        StartSpriteAnim(&gSprites[sTradeMenu->cursorSpriteId], CURSOR_ANIM_ON_CANCEL);
        gSprites[sTradeMenu->cursorSpriteId].x = 0xE8; // JP: DISPLAY_WIDTH - 8
        gSprites[sTradeMenu->cursorSpriteId].y = DISPLAY_HEIGHT;
    }
    else
    {
        StartSpriteAnim(&gSprites[sTradeMenu->cursorSpriteId], CURSOR_ANIM_NORMAL);
        gSprites[sTradeMenu->cursorSpriteId].x = sTradeMonSpriteCoords[newPosition][0] * 8 + 32;
        gSprites[sTradeMenu->cursorSpriteId].y = sTradeMonSpriteCoords[newPosition][1] * 8;
    }

    if (*cursorPosition != newPosition)
        PlaySE(SE_SELECT);

    *cursorPosition = newPosition;
}

static void SetReadyToTrade(void)
{
    PrintTradeMessage(MSG_STANDBY);
    sTradeMenu->callbackId = CB_IDLE;

    if (GetMultiplayerId() == 1)
    {
        // Communicate to the link leader that we're ready to trade
        SetLinkData(LINKCMD_READY_TO_TRADE, sTradeMenu->cursorPosition);
    }
    else
    {
        // We are the link leader, no communication necessary
        sTradeMenu->playerSelectStatus = STATUS_READY;
    }
}

static void CB_ProcessMenuInput(void)
{
    if (JOY_REPEAT(DPAD_UP))
        TradeMenuMoveCursor(&sTradeMenu->cursorPosition, 0);
    else if (JOY_REPEAT(DPAD_DOWN))
        TradeMenuMoveCursor(&sTradeMenu->cursorPosition, 1);
    else if (JOY_REPEAT(DPAD_LEFT))
        TradeMenuMoveCursor(&sTradeMenu->cursorPosition, 2);
    else if (JOY_REPEAT(DPAD_RIGHT))
        TradeMenuMoveCursor(&sTradeMenu->cursorPosition, 3);

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        if (sTradeMenu->cursorPosition < PARTY_SIZE)
        {
            // Selected Pokémon in player's party
            DrawTextBorderOuter(1, 1, 14);
            FillWindowPixelBuffer(1, PIXEL_FILL(1));
            sub_08198964(1, 1, 0x10, 2, (const u8 *)sSelectTradeMonActions); // JP: PrintMenuTable
            sub_081984B0(1, 1, 0, 2, 0x10, 2, 0); // JP: InitMenuInUpperLeftCornerNormal
            PutWindowTilemap(1);
            CopyWindowToVram(1, COPYWIN_FULL);
            sTradeMenu->callbackId = CB_SELECTED_MON;
        }
        else if (sTradeMenu->cursorPosition < PARTY_SIZE * 2)
        {
            // Selected Pokémon in partner's party
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sTradeMenu->callbackId = CB_SHOW_MON_SUMMARY;
        }
        else if (sTradeMenu->cursorPosition == PARTY_SIZE * 2)
        {
            // Selected Cancel
            CreateYesNoMenuAtPos(&sTradeYesNoWindowTemplate, FONT_NORMAL, 2, 2, 1, 14, 0);
            sTradeMenu->callbackId = CB_CANCEL_TRADE_PROMPT;
            DrawBottomRowText(sActionTexts[TEXT_CANCEL_TRADE], (void *)(OBJ_VRAM0 + (sTradeMenu->bottomTextTileStart * 32)), 24);
        }
    }
}

static void RedrawChooseAPokemonWindow(void)
{
    PrintTradePartnerPartyNicknames();
    sTradeMenu->callbackId = CB_MAIN_MENU;
    gSprites[sTradeMenu->cursorSpriteId].invisible = FALSE;
    DrawBottomRowText(sActionTexts[TEXT_CHOOSE_MON], (void *)(OBJ_VRAM0 + (sTradeMenu->bottomTextTileStart * 32)), 24);
}

static void CB_ProcessSelectedMonInput(void)
{
    switch (Menu_ProcessInputNoWrap())
    {
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        RedrawChooseAPokemonWindow();
        break;
    case MENU_NOTHING_CHOSEN:
        break;
    case 0: // Summary
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sTradeMenu->callbackId = CB_SHOW_MON_SUMMARY;
        break;
    case 1: // Trade
        switch (CanTradeSelectedMon(gPlayerParty, gPlayerPartyCount, sTradeMenu->cursorPosition))
        {
        case CAN_TRADE_MON:
            SetReadyToTrade();
            gSprites[sTradeMenu->cursorSpriteId].invisible = TRUE;
            break;
        case CANT_TRADE_LAST_MON:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_ONLY_MON2);
            sTradeMenu->callbackId = CB_HANDLE_TRADE_CANCELED;
            break;
        case CANT_TRADE_NATIONAL:
        case CANT_TRADE_INVALID_MON:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_MON_CANT_BE_TRADED);
            sTradeMenu->callbackId = CB_HANDLE_TRADE_CANCELED;
            break;
        case CANT_TRADE_EGG_YET:
        case CANT_TRADE_PARTNER_EGG_YET:
            QueueAction(QUEUE_DELAY_MSG, QUEUE_EGG_CANT_BE_TRADED);
            sTradeMenu->callbackId = CB_HANDLE_TRADE_CANCELED;
            break;
        }
        break;
    }
}

static void CB_ChooseMonAfterButtonPress(void)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        RedrawChooseAPokemonWindow();
    }
}

static void CB_ShowTradeMonSummaryScreen(void)
{
    if (!gPaletteFade.active)
    {
        if (sTradeMenu->cursorPosition < PARTY_SIZE)
            ShowPokemonSummaryScreen(SUMMARY_MODE_LOCK_MOVES, gPlayerParty, sTradeMenu->cursorPosition, sTradeMenu->partyCounts[TRADE_PLAYER] - 1, CB2_ReturnToTradeMenu);
        else
            ShowPokemonSummaryScreen(SUMMARY_MODE_LOCK_MOVES, gEnemyParty, sTradeMenu->cursorPosition - PARTY_SIZE, sTradeMenu->partyCounts[TRADE_PARTNER] - 1, CB2_ReturnToTradeMenu);
        FreeAllWindowBuffers();
    }
}

u8 CheckValidityOfTradeMons(u8 *aliveMons, u8 playerPartyCount, u8 playerMonIdx, u8 partnerMonIdx)
{
    int i;
    u16 partnerSpecies;
    u8 hasLiveMon = 0;

    for (i = 0; i < playerPartyCount; i++)
    {
        if (playerMonIdx != i)
            hasLiveMon += aliveMons[i];
    }
    partnerMonIdx %= PARTY_SIZE;
    partnerSpecies = GetMonData3(&gEnemyParty[partnerMonIdx], MON_DATA_SPECIES);

    if (partnerSpecies == SPECIES_DEOXYS || partnerSpecies == SPECIES_MEW)
    {
        if (!GetMonData3(&gEnemyParty[partnerMonIdx], MON_DATA_MODERN_FATEFUL_ENCOUNTER))
            return PARTNER_MON_INVALID;
    }

    if (!IsNationalPokedexEnabled())
    {
        if (sTradeMenu->isEgg[TRADE_PARTNER][partnerMonIdx] || !IsSpeciesInHoennDex(partnerSpecies))
            return PARTNER_MON_INVALID;
    }

    if (hasLiveMon)
        hasLiveMon = BOTH_MONS_VALID;

    return hasLiveMon;
}

static bool32 CheckMonsBeforeTrade(void)
{
    int i;
    u8 aliveMons[PARTY_SIZE * 2];

    for (i = 0; i < sTradeMenu->partyCounts[TRADE_PLAYER]; i++)
        aliveMons[i] = sTradeMenu->isLiveMon[TRADE_PLAYER][i];

    switch (CheckValidityOfTradeMons(aliveMons, sTradeMenu->partyCounts[TRADE_PLAYER],
                                                sTradeMenu->cursorPosition,
                                                sTradeMenu->partnerCursorPosition))
    {
    case PLAYER_MON_INVALID:
        QueueAction(QUEUE_DELAY_MSG, QUEUE_ONLY_MON2);
        SetLinkData(LINKCMD_READY_CANCEL_TRADE, 0);
        break;
    case BOTH_MONS_VALID:
        QueueAction(QUEUE_DELAY_MSG, QUEUE_STANDBY);
        SetLinkData(LINKCMD_INIT_BLOCK, 0);
        break;
    case PARTNER_MON_INVALID:
        QueueAction(QUEUE_DELAY_MSG, QUEUE_FRIENDS_MON_CANT_BE_TRADED);
        return TRUE;
    }
    return FALSE;
}

static void CB_ProcessConfirmTradeInput(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // YES, Confirm selection
        if (!CheckMonsBeforeTrade())
            sTradeMenu->callbackId = CB_IDLE;
        else
            sTradeMenu->callbackId = CB_PARTNER_MON_INVALID;

        PutWindowTilemap(17);
        break;
    case 1: // NO, Cancel Trade
    case MENU_B_PRESSED:
        QueueAction(QUEUE_DELAY_MSG, QUEUE_STANDBY);
        if (IsLinkTradeTaskFinished())
            SetLinkData(LINKCMD_READY_CANCEL_TRADE, 0);
        sTradeMenu->callbackId = CB_IDLE;
        PutWindowTilemap(17);
        break;
    }
}


// Only when choosing Yes to cancel, when No is chosen all are redrawn anyway
static void RestoreNicknamesCoveredByYesNo(void)
{
    int i;

    for (i = 0; i < sTradeMenu->partyCounts[1] - 4; i++)
    {
        PutWindowTilemap(i + PARTY_SIZE * 2);
        CopyWindowToVram(i + PARTY_SIZE * 2, COPYWIN_MAP);
    }
}

static void CB_ProcessCancelTradeInput(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // YES, Cancel
        PrintTradeMessage(MSG_WAITING_FOR_FRIEND);
        SetLinkData(LINKCMD_REQUEST_CANCEL, 0);
        gSprites[sTradeMenu->cursorSpriteId].invisible = TRUE;
        sTradeMenu->callbackId = CB_IDLE;
        RestoreNicknamesCoveredByYesNo();
        break;
    case 1: // NO, Continue
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        RedrawChooseAPokemonWindow();
        break;
    }
}

static void CB_SetSelectedMons(void)
{
    if (GetMultiplayerId() == 0)
    {
        rbox_fill_rectangle(0);
        SetSelectedMon(sTradeMenu->cursorPosition);
        SetSelectedMon(sTradeMenu->partnerCursorPosition);
    }
    sTradeMenu->callbackId = CB_PRINT_IS_THIS_OKAY;
}

static void CB_PrintIsThisTradeOkay(void)
{
    if (sTradeMenu->drawSelectedMonState[TRADE_PLAYER] == DRAW_SELECTED_FINISH
     && sTradeMenu->drawSelectedMonState[TRADE_PARTNER] == DRAW_SELECTED_FINISH)
    {
        DrawTradeMonNicknames(); // JP shows the nickname matchup instead of the fixed US text
        sTradeMenu->callbackId = CB_INIT_CONFIRM_TRADE_PROMPT;
    }
}

static void CB_InitConfirmTradePrompt(void)
{
    sTradeMenu->timer++;
    if (sTradeMenu->timer > 120)
    {
        CreateYesNoMenuAtPos(&sTradeYesNoWindowTemplate, FONT_NORMAL, 2, 2, 1, 14, 0);
        sTradeMenu->timer = 0;
        sTradeMenu->callbackId = CB_CONFIRM_TRADE_PROMPT;
    }
}

static void CB_HandleTradeCanceled(void)
{
    int i;

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        rbox_fill_rectangle(0);
        rbox_fill_rectangle(1);

        for (i = 0; i < 4; i++)
        {
            FillWindowPixelBuffer(i + 14, PIXEL_FILL(0));
            rbox_fill_rectangle(i + 14);
        }

        RedrawPartyWindow(TRADE_PLAYER);
        RedrawPartyWindow(TRADE_PARTNER);
        sTradeMenu->callbackId = CB_MAIN_MENU;
        gSprites[sTradeMenu->cursorSpriteId].invisible = FALSE;
    }
}

static void CB_InitExitCanceledTrade(void)
{
    if (!gPaletteFade.active)
    {
        if (gWirelessCommType)
            SetLinkStandbyCallback();
        else
            SetCloseLinkCallbackAndType(12);

        sTradeMenu->callbackId = CB_EXIT_CANCELED_TRADE;
    }
}

static void CB_ExitCanceledTrade(void)
{
    if (gWirelessCommType)
    {
        if (IsLinkTradeTaskFinished() && GetNumQueuedActions() == 0)
        {
            Free(sMenuTextTileBuffer);
            Free(sTradeMenu);
            FreeAllWindowBuffers();
            DestroyWirelessStatusIndicatorSprite();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
    else
    {
        if (!gReceivedRemoteLinkPlayers)
        {
            Free(sMenuTextTileBuffer);
            Free(sTradeMenu);
            FreeAllWindowBuffers();
            SetMainCallback2(CB2_ReturnToFieldFromMultiplayer);
        }
    }
}

static void CB_WaitToStartRfuTrade(void)
{
    if (!Rfu_SetLinkRecovery(FALSE) && GetNumQueuedActions() == 0)
    {
        SetLinkStandbyCallback();
        sTradeMenu->callbackId = CB_START_LINK_TRADE;
    }
}

static void CB_PartnersMonWasInvalid(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        SetLinkData(LINKCMD_READY_CANCEL_TRADE, 0);
        sTradeMenu->callbackId = CB_IDLE;
    }
}

static void RunTradeMenuCallback(void)
{
    switch (sTradeMenu->callbackId)
    {
    case CB_MAIN_MENU:
        CB_ProcessMenuInput();
        break;
    case CB_SELECTED_MON:
        CB_ProcessSelectedMonInput();
        break;
    case CB_SHOW_MON_SUMMARY:
        CB_ShowTradeMonSummaryScreen();
        break;
    case CB_CONFIRM_TRADE_PROMPT:
        CB_ProcessConfirmTradeInput();
        break;
    case CB_CANCEL_TRADE_PROMPT:
        CB_ProcessCancelTradeInput();
        break;
    case CB_SET_SELECTED_MONS:
        CB_SetSelectedMons();
        break;
    case CB_PRINT_IS_THIS_OKAY:
        CB_PrintIsThisTradeOkay();
        break;
    case CB_HANDLE_TRADE_CANCELED:
        CB_HandleTradeCanceled();
        break;
    case CB_FADE_TO_START_TRADE:
        CB_FadeToStartTrade();
        break;
    case CB_WAIT_TO_START_TRADE:
        CB_WaitToStartTrade();
        break;
    case CB_INIT_EXIT_CANCELED_TRADE:
        CB_InitExitCanceledTrade();
        break;
    case CB_EXIT_CANCELED_TRADE:
        CB_ExitCanceledTrade();
        break;
    case CB_START_LINK_TRADE:
        CB_StartLinkTrade();
        break;
    case CB_INIT_CONFIRM_TRADE_PROMPT:
        CB_InitConfirmTradePrompt();
        break;
    case CB_UNUSED_CLOSE_MSG:
        CB_ChooseMonAfterButtonPress();
        break;
    case CB_WAIT_TO_START_RFU_TRADE:
        CB_WaitToStartRfuTrade();
        break;
    case CB_PARTNER_MON_INVALID:
        CB_PartnersMonWasInvalid();
        break;
  //case CB_IDLE: is nop
    }
}

static void SetSelectedMon(u8 cursorPosition)
{
    //cursorPosition 0-5 are the player's mons, 6-11 are the partner's
    u8 whichParty = cursorPosition / PARTY_SIZE;

    if (sTradeMenu->drawSelectedMonState[whichParty] == 0)
    {
        // Start the animation to display just the selected
        // Pokémon in the middle of the screen
        sTradeMenu->drawSelectedMonState[whichParty] = 1;
        sTradeMenu->selectedMonIdx[whichParty] = cursorPosition;
    }
}

// Byte-exact exception: agbcc cannot reproduce this JP routine's cross-case r8/r9/sl lifetimes.
__attribute__((naked)) void sub_080790C8(u8 side)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x5c\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r0, _08079114\n\t"
        "	ldr r4, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x76\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	str r1, [sp, #0x50]\n\t"
        "	cmp r0, #5\n\t"
        "	bhi _080790F0\n\t"
        "	movs r2, #0\n\t"
        "	str r2, [sp, #0x50]\n\t"
        "_080790F0:\n\t"
        "	movs r1, #6\n\t"
        "	bl __umodsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x74\n\t"
        "	adds r3, r0, r7\n\t"
        "	ldrb r0, [r3]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0807910A\n\t"
        "	b _080792A0\n\t"
        "_0807910A:\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _08079118\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08079126\n\t"
        "	b _08079454\n\t"
        "	.align 2, 0\n\t"
        "_08079114: .4byte sTradeMenu\n\t"
        "_08079118:\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0807911E\n\t"
        "	b _080792D8\n\t"
        "_0807911E:\n\t"
        "	cmp r0, #4\n\t"
        "	bne _08079124\n\t"
        "	b _0807941C\n\t"
        "_08079124:\n\t"
        "	b _08079454\n\t"
        "_08079126:\n\t"
        "	movs r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x36\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldr r0, [sp, #0x50]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	mov r8, r0\n\t"
        "	lsls r6, r7, #1\n\t"
        "	lsls r2, r7, #4\n\t"
        "	str r2, [sp, #0x58]\n\t"
        "	movs r0, #0\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bhs _0807917C\n\t"
        "	ldr r0, _0807928C\n\t"
        "	mov sb, r0\n\t"
        "	ldr r4, _08079290\n\t"
        "	ldr r0, [sp, #0x50]\n\t"
        "	add r0, r8\n\t"
        "	lsls r2, r0, #1\n\t"
        "	movs r3, #4\n\t"
        "_08079150:\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r1, r5, r2\n\t"
        "	adds r0, #0x28\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sb\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	orrs r1, r3\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x36\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	blo _08079150\n\t"
        "_0807917C:\n\t"
        "	movs r5, #0\n\t"
        "	adds r0, r6, r7\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r4, r0, #2\n\t"
        "_08079184:\n\t"
        "	lsls r0, r5, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #5\n\t"
        "	bls _08079184\n\t"
        "	ldr r1, _08079290\n\t"
        "	mov sb, r1\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r6, [sp, #0x50]\n\t"
        "	add r6, r8\n\t"
        "	lsls r3, r6, #1\n\t"
        "	add sl, r3\n\t"
        "	adds r0, #0x28\n\t"
        "	add r0, sl\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r2, _0807928C\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #5\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	mov r0, sb\n\t"
        "	ldr r4, [r0]\n\t"
        "	adds r4, #0x28\n\t"
        "	add r4, sl\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0807928C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0x14\n\t"
        "	strh r1, [r0, #0x2e]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r2, r0, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldr r0, _0807928C\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r5, _08079294\n\t"
        "	lsls r6, r6, #2\n\t"
        "	adds r0, r6, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r3, #1\n\t"
        "	lsls r3, r3, #1\n\t"
        "	adds r3, r3, r5\n\t"
        "	ldrb r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	asrs r0, r0, #1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, #0xe\n\t"
        "	strh r0, [r2, #0x32]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r2, _0807928C\n\t"
        "	adds r1, r1, r2\n\t"
        "	adds r5, #1\n\t"
        "	adds r6, r6, r5\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	subs r0, #0xc\n\t"
        "	strh r0, [r1, #0x36]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, _08079298\n\t"
        "	bl StoreSpriteCallbackInData6\n\t"
        "	mov r0, sb\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r1, #0x74\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	adds r0, #0x28\n\t"
        "	add r0, sl\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r2, _0807928C\n\t"
        "	adds r0, r0, r2\n\t"
        "	bl sub_080A66B4\n\t"
        "	ldr r1, _0807929C\n\t"
        "	ldr r0, [sp, #0x58]\n\t"
        "	subs r2, r0, r7\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	movs r0, #0xf\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0x11\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl CopyToBgTilemapBufferRect_ChangePalette\n\t"
        "	movs r0, #1\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r0, #0\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	ldr r1, [sp, #0x50]\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08079284\n\t"
        "	b _08079454\n\t"
        "_08079284:\n\t"
        "	bl PrintTradePartnerPartyNicknames\n\t"
        "	b _08079454\n\t"
        "	.align 2, 0\n\t"
        "_0807928C: .4byte gSprites\n\t"
        "_08079290: .4byte sTradeMenu\n\t"
        "_08079294: .4byte gUnknown_8300A1C\n\t"
        "_08079298: .4byte SpriteCB_MonIcon + 1\n\t"
        "_0807929C: .4byte sTradePartyBoxTilemap\n\t"
        "_080792A0:\n\t"
        "	ldr r2, _080792D0\n\t"
        "	ldr r1, [sp, #0x50]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sl\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x28\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r1, [r1]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r2, #0x1c\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080792D4\n\t"
        "	cmp r1, r0\n\t"
        "	beq _080792C8\n\t"
        "	b _08079454\n\t"
        "_080792C8:\n\t"
        "	movs r0, #3\n\t"
        "	strb r0, [r3]\n\t"
        "	b _08079454\n\t"
        "	.align 2, 0\n\t"
        "_080792D0: .4byte gSprites\n\t"
        "_080792D4: .4byte SpriteCB_MonIcon + 1\n\t"
        "_080792D8:\n\t"
        "	ldr r1, _08079404\n\t"
        "	ldr r0, [sp, #0x50]\n\t"
        "	lsls r2, r0, #4\n\t"
        "	subs r2, r2, r0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	movs r0, #0xf\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0x11\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl CopyToBgTilemapBufferRect_ChangePalette\n\t"
        "	movs r0, #1\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	ldr r6, _08079408\n\t"
        "	ldr r1, _0807940C\n\t"
        "	ldr r4, [r1]\n\t"
        "	ldr r2, [sp, #0x50]\n\t"
        "	lsls r3, r2, #1\n\t"
        "	adds r3, r3, r2\n\t"
        "	lsls r1, r3, #1\n\t"
        "	mov r2, sl\n\t"
        "	adds r0, r2, r1\n\t"
        "	adds r4, #0x28\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r2, r0, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r6\n\t"
        "	ldr r5, _08079410\n\t"
        "	lsls r3, r3, #2\n\t"
        "	adds r0, r3, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, #1\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r0, r0, r1\n\t"
        "	asrs r0, r0, #1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, #0xe\n\t"
        "	strh r0, [r2, #0x20]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	adds r5, #1\n\t"
        "	adds r3, r3, r5\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	subs r0, #0xc\n\t"
        "	strh r0, [r1, #0x22]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	mov r1, sb\n\t"
        "	strh r1, [r0, #0x24]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	mov r2, sb\n\t"
        "	strh r2, [r0, #0x26]\n\t"
        "	add r0, sp, #0x14\n\t"
        "	ldr r1, [sp, #0x50]\n\t"
        "	mov r2, sl\n\t"
        "	bl GetMonNicknameWidth\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	lsls r4, r7, #1\n\t"
        "	adds r5, r4, #0\n\t"
        "	adds r5, #0xe\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r6, _08079414\n\t"
        "	str r6, [sp]\n\t"
        "	mov r0, sb\n\t"
        "	str r0, [sp, #4]\n\t"
        "	add r1, sp, #0x14\n\t"
        "	str r1, [sp, #8]\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	mov r2, sp\n\t"
        "	adds r2, #0x28\n\t"
        "	str r2, [sp, #0x54]\n\t"
        "	adds r0, r2, #0\n\t"
        "	ldr r1, [sp, #0x50]\n\t"
        "	mov r2, sl\n\t"
        "	bl BufferMovesString\n\t"
        "	adds r4, #0xf\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	str r6, [sp]\n\t"
        "	mov r0, sb\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _08079418\n\t"
        "	str r0, [sp, #8]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	mov r1, sb\n\t"
        "	str r1, [sp]\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r6, [sp, #8]\n\t"
        "	str r1, [sp, #0xc]\n\t"
        "	ldr r2, [sp, #0x54]\n\t"
        "	str r2, [sp, #0x10]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0x18\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized4\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl PutWindowTilemap\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl PutWindowTilemap\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r0, _0807940C\n\t"
        "	ldr r1, [r0]\n\t"
        "	b _0807944A\n\t"
        "	.align 2, 0\n\t"
        "_08079404: .4byte sTradeMovesBoxTilemap\n\t"
        "_08079408: .4byte gSprites\n\t"
        "_0807940C: .4byte sTradeMenu\n\t"
        "_08079410: .4byte gUnknown_8300A1C\n\t"
        "_08079414: .4byte gUnknown_8300C00\n\t"
        "_08079418: .4byte gUnknown_8300A9B\n\t"
        "_0807941C:\n\t"
        "	ldr r0, _08079464\n\t"
        "	lsls r1, r7, #1\n\t"
        "	adds r4, r1, r0\n\t"
        "	ldrb r2, [r4]\n\t"
        "	adds r2, #4\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r3, [r1]\n\t"
        "	adds r3, #1\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	ldrb r0, [r4]\n\t"
        "	str r0, [sp]\n\t"
        "	ldrb r0, [r1]\n\t"
        "	str r0, [sp, #4]\n\t"
        "	adds r0, r7, #0\n\t"
        "	mov r1, sl\n\t"
        "	bl PrintLevelAndGender\n\t"
        "	ldr r2, _08079468\n\t"
        "	ldr r1, [r2]\n\t"
        "_0807944A:\n\t"
        "	adds r1, #0x74\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "_08079454:\n\t"
        "	add sp, #0x5c\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08079464: .4byte gUnknown_8300D40\n\t"
        "_08079468: .4byte sTradeMenu\n\t"
        ".syntax divided\n\t"
    );
}
static u8 GetMonNicknameWidth(u8 *str, u8 whichParty, u8 partyIdx)
{
    u8 nickname[POKEMON_NAME_STORAGE_LENGTH + 1];
    register u32 monAddr asm("r4");
    u8 gender;
    register u32 level asm("r9");
    register struct TradeMenu **tradeMenuPtr asm("sl");
    register struct TradeMenu **tradeMenuPtr2 asm("r1");

    if (whichParty == TRADE_PLAYER)
    {
        monAddr = partyIdx;
        monAddr *= sizeof(struct Pokemon);
        monAddr += (u32)gPlayerParty;
    }
    else
    {
        monAddr = partyIdx;
        monAddr *= sizeof(struct Pokemon);
        monAddr += (u32)gEnemyParty;
    }

    GetMonData3((struct Pokemon *)monAddr, MON_DATA_NICKNAME, nickname);
    StringCopy10(str, nickname);
    gender = GetMonGender((struct Pokemon *)monAddr);
    level = (u8)GetMonData3((struct Pokemon *)monAddr, MON_DATA_LEVEL);
    tradeMenuPtr = &sTradeMenu;

    if (!(*tradeMenuPtr)->isEgg[whichParty][partyIdx % PARTY_SIZE])
        AppendGenderSymbol(str, gender);
    StringAppend(str, gUnknown_8300AA0);
    tradeMenuPtr2 = tradeMenuPtr;
    if (!(*tradeMenuPtr2)->isEgg[whichParty][partyIdx % PARTY_SIZE])
    {
        StringAppend(str, gUnknown_8300AA2);
        ConvertIntToDecimalStringN(nickname, level, 0, 3);
        StringAppend(str, nickname);
    }
    else
    {
        StringAppend(str, gUnknown_8300AA5);
    }
    return StringLength(str);
}

static void BufferMovesString(u8 *str, u8 whichParty, u8 partyIdx)
{
    u16 moves[MAX_MON_MOVES];
    u16 i;

    if (!sTradeMenu->isEgg[whichParty][partyIdx])
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (whichParty == TRADE_PLAYER)
                moves[i] = GetMonData3(&gPlayerParty[partyIdx], i + MON_DATA_MOVE1, NULL);
            else
                moves[i] = GetMonData3(&gEnemyParty[partyIdx], i + MON_DATA_MOVE1, NULL);
        }

        StringCopy(str, gUnknown_8300A8A);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (moves[i] != MOVE_NONE)
                StringAppend(str, gMoveNames[moves[i]]);
            StringAppend(str, gUnknown_8300A9E);
        }
    }
    else
    {
        StringCopy(str, gUnknown_8300A8A);
        StringAppend(str, gUnknown_8300AA9);
    }
}

static void PrintPartyMonNickname(u8 whichParty, u8 windowIdOffset, u8 *nickname)
{
    s8 signedOffset = windowIdOffset;
    u8 windowId = (u8)(signedOffset + ((whichParty * PARTY_SIZE) + 2));

    AddTextPrinterParameterized3(windowId, FONT_NORMAL, 0, 0, gUnknown_8300C00, 0, nickname);
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void PrintPartyNicknames(u8 whichParty)
{
    u8 temp[POKEMON_NAME_BUFFER_SIZE];
    u8 nickname[32];
    u8 gender;
    u8 i;
    struct Pokemon *party = (whichParty == TRADE_PLAYER) ? gPlayerParty : gEnemyParty;

    for (i = 0; i < sTradeMenu->partyCounts[whichParty]; i++)
    {
        GetMonData3(&party[i], MON_DATA_NICKNAME, temp);
        StringCopy10(nickname, temp);
        gender = GetMonGender(&party[i]);
        if (!sTradeMenu->isEgg[whichParty][i])
            AppendGenderSymbol(nickname, gender);
        PrintPartyMonNickname(whichParty, i, nickname);
    }
}

static void PrintLevelAndGender(u8 whichParty, u8 monIdx, u8 x, u8 y, u8 width, u8 height)
{
    u8 level;
    u8 tens;

    CopyToBgTilemapBufferRect_ChangePalette(1, gTradeMenuMonBox_Tilemap, width, height, 6, 3, 0);
    CopyBgTilemapBufferToVram(1);

    if (whichParty == TRADE_PLAYER)
        level = GetMonData3(&gPlayerParty[monIdx], MON_DATA_LEVEL, NULL);
    else
        level = GetMonData3(&gEnemyParty[monIdx], MON_DATA_LEVEL, NULL);

    if (!sTradeMenu->isEgg[whichParty][monIdx])
    {
        tens = level / 10;
        if (tens != 0)
            sTradeMenu->tilemapBuffer[x + (y * 32)] = tens + 0x60;
        sTradeMenu->tilemapBuffer[x + (y * 32) + 1] = (level % 10) + 0x70;
    }
    else
    {
        sTradeMenu->tilemapBuffer[x + (y * 32) - 32] = sTradeMenu->tilemapBuffer[x + (y * 32) - 33];
        sTradeMenu->tilemapBuffer[x + (y * 32) - 31] = sTradeMenu->tilemapBuffer[x + (y * 32) - 36] | 0x400;
    }
}

static void PrintPartyLevelsAndGenders(u8 whichParty)
{
    s32 i;

    for (i = 0; i < sTradeMenu->partyCounts[whichParty]; i++)
    {
        s32 j = i + PARTY_SIZE * whichParty;
        PrintLevelAndGender(whichParty, i,
            gUnknown_8300A36[j][0],
            gUnknown_8300A36[j][1],
            gUnknown_8300A4E[j][0],
            gUnknown_8300A4E[j][1]);
    }
}

static void ShowTradePartyMonIcons(u8 whichParty)
{
    int i;

    for (i = 0; i < sTradeMenu->partyCounts[whichParty]; i++)
    {
        gSprites[sTradeMenu->partySpriteIds[whichParty][i]].invisible = FALSE;
        gSprites[sTradeMenu->partySpriteIds[whichParty][i]].x = gUnknown_8300A1C[(whichParty * PARTY_SIZE) + i][0] * 8 + 14;
        gSprites[sTradeMenu->partySpriteIds[whichParty][i]].y = gUnknown_8300A1C[(whichParty * PARTY_SIZE) + i][1] * 8 - 12;
        gSprites[sTradeMenu->partySpriteIds[whichParty][i]].x2 = 0;
        gSprites[sTradeMenu->partySpriteIds[whichParty][i]].y2 = 0;
    }
}


static void PrintTradePartnerPartyNicknames(void)
{
    rbox_fill_rectangle(1);
    PrintPartyNicknames(TRADE_PARTNER);
}

static void RedrawPartyWindow(u8 whichParty)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, sTradePartyBoxTilemap, whichParty * 15, 0, 15, 17, 0);
    CopyBgTilemapBufferToVram(1);
    PrintPartyLevelsAndGenders(whichParty);
    PrintPartyNicknames(whichParty);
    ShowTradePartyMonIcons(whichParty);
    DrawBottomRowText(sActionTexts[TEXT_CHOOSE_MON], (void *)(OBJ_VRAM0 + (sTradeMenu->bottomTextTileStart * 32)), 24);
    sTradeMenu->drawSelectedMonState[whichParty] = 0;
}

static void Task_DrawSelectionSummary(u8 taskId)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT);
    CopyBgTilemapBufferToVram(0);
}

static void Task_DrawSelectionTrade(u8 taskId)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT);
    CopyBgTilemapBufferToVram(0);
}

static void QueueAction(u16 delay, u8 actionId)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeMenu->queuedActions); i++)
    {
        // Find first available spot
        if (!sTradeMenu->queuedActions[i].active)
        {
            sTradeMenu->queuedActions[i].delay = delay;
            sTradeMenu->queuedActions[i].actionId = actionId;
            sTradeMenu->queuedActions[i].active = TRUE;
            break;
        }
    }
}

static u32 GetNumQueuedActions(void)
{
    u32 numActions = 0;
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeMenu->queuedActions); i++)
    {
        numActions += sTradeMenu->queuedActions[i].active;
    }

    return numActions;
}

static void DoQueuedActions(void)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeMenu->queuedActions); i++)
    {
        if (sTradeMenu->queuedActions[i].active)
        {
            if (sTradeMenu->queuedActions[i].delay != 0)
            {
                sTradeMenu->queuedActions[i].delay--;
            }
            else
            {
                switch (sTradeMenu->queuedActions[i].actionId)
                {
                case QUEUE_SEND_DATA:
                    SendLinkData(sTradeMenu->linkData, 20);
                    break;
                case QUEUE_STANDBY:
                    PrintTradeMessage(MSG_STANDBY);
                    break;
                case QUEUE_ONLY_MON1:
                    PrintTradeMessage(MSG_ONLY_MON1);
                    break;
                case QUEUE_ONLY_MON2:
                case QUEUE_UNUSED1:
                case QUEUE_UNUSED2:
                    PrintTradeMessage(MSG_ONLY_MON2);
                    break;
                case QUEUE_MON_CANT_BE_TRADED:
                    PrintTradeMessage(MSG_MON_CANT_BE_TRADED);
                    break;
                case QUEUE_EGG_CANT_BE_TRADED:
                    PrintTradeMessage(MSG_EGG_CANT_BE_TRADED);
                    break;
                case QUEUE_FRIENDS_MON_CANT_BE_TRADED:
                    PrintTradeMessage(MSG_FRIENDS_MON_CANT_BE_TRADED);
                    break;
                }
                sTradeMenu->queuedActions[i].active = FALSE;
            }
        }
    }
}

static void PrintTradeMessage(u8 messageId)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized(0, FONT_NORMAL, gUnknown_8300BDC[messageId], 2, 2, TEXT_SKIP_DRAW, NULL);
    DrawTextBorderOuter(0, 20, 12);
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static bool8 LoadUISpriteGfx(void)
{
    struct SpriteSheet sheet;

    if (sTradeMenu->timer < NUM_MENU_TEXT_SPRITES)
    {
        sheet.data = sMenuTextTileBuffers[sTradeMenu->timer];
        sheet.size = 0x100;
        sheet.tag = GFXTAG_MENU_TEXT + sTradeMenu->timer;
    }

    switch (sTradeMenu->timer)
    {
    case GFXTAG_PLAYER_NAME_L:
    case GFXTAG_PLAYER_NAME_M:
    case GFXTAG_PLAYER_NAME_R:
    case GFXTAG_PARTNER_NAME_L:
    case GFXTAG_PARTNER_NAME_M:
    case GFXTAG_PARTNER_NAME_R:
    case GFXTAG_CANCEL_L:
        LoadSpriteSheet(&sheet);
        sTradeMenu->timer++;
        break;
    case GFXTAG_CHOOSE_PKMN_L:
        sTradeMenu->bottomTextTileStart = LoadSpriteSheet(&sheet);
        sTradeMenu->timer++;
        break;
    case GFXTAG_CHOOSE_PKMN_M:
    case GFXTAG_CHOOSE_PKMN_R:
    case GFXTAG_CHOOSE_PKMN_EMPTY_1:
    case GFXTAG_CHOOSE_PKMN_EMPTY_2:
    case GFXTAG_CHOOSE_PKMN_EMPTY_3:
        LoadSpriteSheet(&sheet);
        sTradeMenu->timer++;
        break;
    case NUM_MENU_TEXT_SPRITES:
        LoadSpritePalette(&gUnknown_83008DC);
        sTradeMenu->timer++;
        break;
    case NUM_MENU_TEXT_SPRITES + 1:
        LoadSpritePalette(&gUnknown_830083C);
        sTradeMenu->timer++;
        break;
    case NUM_MENU_TEXT_SPRITES + 2:
        LoadSpriteSheet(&gUnknown_8300834);
        sTradeMenu->timer++;
        break;
    case NUM_MENU_TEXT_SPRITES + 3:
        sTradeMenu->timer = 0;
        return TRUE;
    }

    return FALSE;
}

void DrawBottomRowText(const u8 *str, u8 *dest, u8 width)
{
    u8 buffer[32];
    register s32 i asm("r2");
    register u32 character asm("r1");
    register u8 *bufferPos asm("r0");

    StringFill(buffer, 0, width);
    i = 0;
    if (i < width)
    {
        character = *str;
        asm("mov %0, %1" : "=r"(bufferPos) : "r"(character));
        if ((u32)bufferPos == EOS)
            goto draw;
        bufferPos = buffer;
copy:
        *bufferPos = character;
        i++;
        if (i >= width)
            goto draw;
        character = str[i];
        asm("mov %0, %1" : "=r"(bufferPos) : "r"(character));
        if ((u32)bufferPos == EOS)
            goto draw;
        bufferPos = &buffer[i];
        goto copy;
    }
draw:
    sub_080C66A4(buffer, dest, 0, 0, gDecompressionBuffer);
}

static void ComputePartyTradeableFlags(u8 whichParty)
{
    int i;

    switch (whichParty)
    {
    case TRADE_PLAYER:
        for (i = 0; i < sTradeMenu->partyCounts[whichParty]; i++)
        {
            if (GetMonData3(&gPlayerParty[i], MON_DATA_IS_EGG) == TRUE)
            {
                sTradeMenu->isLiveMon[whichParty][i] = FALSE;
                sTradeMenu->isEgg[whichParty][i] = TRUE;
            }
            else if (GetMonData3(&gPlayerParty[i], MON_DATA_HP) == 0)
            {
                sTradeMenu->isLiveMon[whichParty][i] = FALSE;
                sTradeMenu->isEgg[whichParty][i] = FALSE;
            }
            else
            {
                sTradeMenu->isLiveMon[whichParty][i] = TRUE;
                sTradeMenu->isEgg[whichParty][i] = FALSE;
            }
        }
        break;
    case TRADE_PARTNER:
        for (i = 0; i < sTradeMenu->partyCounts[whichParty]; i++)
        {
            if (GetMonData3(&gEnemyParty[i], MON_DATA_IS_EGG) == TRUE)
            {
                sTradeMenu->isLiveMon[whichParty][i] = FALSE;
                sTradeMenu->isEgg[whichParty][i] = TRUE;
            }
            else if (GetMonData3(&gEnemyParty[i], MON_DATA_HP) == 0)
            {
                sTradeMenu->isLiveMon[whichParty][i] = FALSE;
                sTradeMenu->isEgg[whichParty][i] = FALSE;
            }
            else
            {
                sTradeMenu->isLiveMon[whichParty][i] = TRUE;
                sTradeMenu->isEgg[whichParty][i] = FALSE;
            }
        }
        break;
    }
}

static void ComputePartyHPBarLevels(u8 whichParty)
{
    u16 i;
    s16 curHp, maxHp;

    switch (whichParty)
    {
    case TRADE_PLAYER:
        for (i = 0; i < sTradeMenu->partyCounts[TRADE_PLAYER]; i++)
        {
            curHp = GetMonData3(&gPlayerParty[i], MON_DATA_HP);
            maxHp = GetMonData3(&gPlayerParty[i], MON_DATA_MAX_HP);
            sTradeMenu->hpBarLevels[TRADE_PLAYER][i] = GetHPBarLevel(curHp, maxHp);
        }
        break;
    case TRADE_PARTNER:
        for (i = 0; i < sTradeMenu->partyCounts[TRADE_PARTNER]; i++)
        {
            curHp = GetMonData3(&gEnemyParty[i], MON_DATA_HP);
            maxHp = GetMonData3(&gEnemyParty[i], MON_DATA_MAX_HP);
            sTradeMenu->hpBarLevels[TRADE_PARTNER][i] = GetHPBarLevel(curHp, maxHp);
        }
        break;
    }
}

static void SetTradePartyHPBarSprites(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < sTradeMenu->partyCounts[i]; j++)
            SetPartyHPBarSprite(&gSprites[sTradeMenu->partySpriteIds[i][j]], 4 - sTradeMenu->hpBarLevels[i][j]);
    }
}

static void SaveTradeGiftRibbons(void)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sTradeMenu->giftRibbons); i++)
    {
        if (gSaveBlock1Ptr->giftRibbons[i] == 0 && sTradeMenu->giftRibbons[i] != 0)
            gSaveBlock1Ptr->giftRibbons[i] = sTradeMenu->giftRibbons[i];
    }
}

static u32 CanTradeSelectedMon(struct Pokemon *playerParty, int partyCount, int monIdx)
{
    int i, numMonsLeft;
    struct LinkPlayer *partner;
    u32 species[PARTY_SIZE];
    u32 species2[PARTY_SIZE];

    for (i = 0; i < partyCount; i++)
    {
        species2[i] = GetMonData3(&playerParty[i], MON_DATA_SPECIES_OR_EGG);
        species[i] = GetMonData3(&playerParty[i], MON_DATA_SPECIES);
    }

    // Cant trade Eggs or non-Hoenn mons if player doesn't have National Dex
    if (!IsNationalPokedexEnabled())
    {
        if (species2[monIdx] == SPECIES_EGG)
            return CANT_TRADE_EGG_YET;

        if (!IsSpeciesInHoennDex(species2[monIdx]))
            return CANT_TRADE_NATIONAL;
    }

    partner = &gLinkPlayers[GetMultiplayerId() ^ 1];
    if ((partner->version & 0xFF) != VERSION_RUBY &&
        (partner->version & 0xFF) != VERSION_SAPPHIRE)
    {
        // Does partner not have National Dex
        if (!(partner->progressFlags & 0xF))
        {
            if (species2[monIdx] == SPECIES_EGG)
                return CANT_TRADE_PARTNER_EGG_YET;

            if (!IsSpeciesInHoennDex(species2[monIdx]))
                return CANT_TRADE_INVALID_MON;
        }
    }

    if (species[monIdx] == SPECIES_DEOXYS || species[monIdx] == SPECIES_MEW)
    {
        if (!GetMonData3(&playerParty[monIdx], MON_DATA_MODERN_FATEFUL_ENCOUNTER))
            return CANT_TRADE_INVALID_MON;
    }

    // Make Eggs not count for numMonsLeft
    for (i = 0; i < partyCount; i++)
    {
        if (species2[i] == SPECIES_EGG)
            species2[i] = SPECIES_NONE;
    }

    // Count alive mons in party, excluding selected trade mon
    for (numMonsLeft = 0, i = 0; i < partyCount; i++)
    {
        if (i != monIdx)
            numMonsLeft += species2[i];
    }

    if (numMonsLeft != 0)
        return CAN_TRADE_MON;
    else
        return CANT_TRADE_LAST_MON;
}

s32 GetGameProgressForLinkTrade(void)
{
    // The usage of this value is a little unusual given it's treated as a bool,
    // but it's the result of its usage in FRLG, where 0 is FRLG, 1 is RS, and 2 is Emerald.
    s32 versionId; // 0: RSE, 2: FRLG
    u16 version;

    if (gReceivedRemoteLinkPlayers)
    {
        versionId = 0;
        version = (gLinkPlayers[GetMultiplayerId() ^ 1].version & 0xFF);

        if (version == VERSION_RUBY || version == VERSION_SAPPHIRE || version == VERSION_EMERALD)
            versionId = 0;
        else if (version == VERSION_FIRE_RED || version == VERSION_LEAF_GREEN)
            versionId = 2;

        // If trading with FRLG, both players must have progessed the story enough
        if (versionId > 0)
        {
            // Is player champion
            if (gLinkPlayers[GetMultiplayerId()].progressFlags & 0xF0)
            {
                if (versionId == 2) // Check is only relevant in FRLG, this will always be true
                {
                    // Has FRLG partner finished the Sevii Islands
                    if (gLinkPlayers[GetMultiplayerId() ^ 1].progressFlags & 0xF0)
                        return TRADE_BOTH_PLAYERS_READY;
                    else
                        return TRADE_PARTNER_NOT_READY;
                }
            }
            else
            {
                return TRADE_PLAYER_NOT_READY;
            }
        }
    }
    return TRADE_BOTH_PLAYERS_READY;
}

static bool32 IsDeoxysOrMewUntradable(u16 species, bool8 isModernFatefulEncounter)
{
    if (species == SPECIES_DEOXYS || species == SPECIES_MEW)
    {
        if (!isModernFatefulEncounter)
            return TRUE;
    }
    return FALSE;
}

int GetUnionRoomTradeMessageId(struct RfuGameCompatibilityData player, struct RfuGameCompatibilityData partner, u16 playerSpecies2, u16 partnerSpecies, u8 requestedType, u16 playerSpecies, bool8 isModernFatefulEncounter)
{
    bool8 playerHasNationalDex = player.hasNationalDex;
    bool8 playerCanLinkNationally = player.canLinkNationally;
    bool8 partnerHasNationalDex = partner.hasNationalDex;
    bool8 partnerCanLinkNationally = partner.canLinkNationally;
    u8 partnerVersion = partner.version;

    // If partner is not using Emerald, both players must have progressed the story
    // to a certain point (becoming champion in RSE, finishing the Sevii islands in FRLG)
    if (partnerVersion != VERSION_EMERALD)
    {
        if (!playerCanLinkNationally)
            return UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_1;
        else if (!partnerCanLinkNationally)
            return UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_2;
    }

    // Cannot trade illegitimate Deoxys/Mew
    if (IsDeoxysOrMewUntradable(playerSpecies, isModernFatefulEncounter))
        return UR_TRADE_MSG_MON_CANT_BE_TRADED_2;

    if (partnerSpecies == SPECIES_EGG)
    {
        // If partner is trading an Egg then the player must also be trading an Egg
        if (playerSpecies2 != partnerSpecies)
            return UR_TRADE_MSG_NOT_EGG;
    }
    else
    {
        // Player's Pokémon must be of the type the partner requested
        if (gSpeciesInfo[playerSpecies2].types[0] != requestedType
         && gSpeciesInfo[playerSpecies2].types[1] != requestedType)
            return UR_TRADE_MSG_NOT_MON_PARTNER_WANTS;
    }

    // If the player is trading an Egg then the partner must also be trading an Egg
    // Odd that this wasn't checked earlier, as by this point we know either the partner doesn't have an Egg or that both do.
    if (playerSpecies2 == SPECIES_EGG && playerSpecies2 != partnerSpecies)
        return UR_TRADE_MSG_MON_CANT_BE_TRADED_1;

    // If the player doesn't have the National Dex then Eggs and non-Hoenn Pokémon can't be traded
    if (!playerHasNationalDex)
    {
        if (playerSpecies2 == SPECIES_EGG)
            return UR_TRADE_MSG_EGG_CANT_BE_TRADED;

        if (!IsSpeciesInHoennDex(playerSpecies2))
            return UR_TRADE_MSG_MON_CANT_BE_TRADED_2;

        if (!IsSpeciesInHoennDex(partnerSpecies))
            return UR_TRADE_MSG_PARTNERS_MON_CANT_BE_TRADED;
    }

    // If the partner doesn't have the National Dex then the player's offer has to be a Hoenn Pokémon
    if (!partnerHasNationalDex && !IsSpeciesInHoennDex(playerSpecies2))
        return UR_TRADE_MSG_PARTNER_CANT_ACCEPT_MON;

    // Trade is allowed
    return UR_TRADE_MSG_NONE;
}

int CanRegisterMonForTradingBoard(struct RfuGameCompatibilityData player, u16 species2, u16 species, bool8 isModernFatefulEncounter)
{
    bool8 hasNationalDex = player.hasNationalDex;

    if (IsDeoxysOrMewUntradable(species, isModernFatefulEncounter))
        return CANT_REGISTER_MON;

    if (hasNationalDex)
        return CAN_REGISTER_MON;

    // Eggs can only be traded if the player has the National Dex
    if (species2 == SPECIES_EGG)
        return CANT_REGISTER_EGG;

    if (IsSpeciesInHoennDex(species2))
        return CAN_REGISTER_MON;

    return CANT_REGISTER_MON;
}

int CanSpinTradeMon(struct Pokemon *mon, u16 monIdx)
{
    int i, version, versions, canTradeAnyMon, numMonsLeft;
    int speciesArray[PARTY_SIZE];

    // Make Eggs not count for numMonsLeft
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        speciesArray[i] = GetMonData3(&mon[i], MON_DATA_SPECIES_OR_EGG);
        if (speciesArray[i] == SPECIES_EGG)
            speciesArray[i] = SPECIES_NONE;
    }

    versions = 0;
    canTradeAnyMon = TRUE;
    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        version = gLinkPlayers[i].version & 0xFF;
        if (version == VERSION_FIRE_RED ||
            version == VERSION_LEAF_GREEN)
            versions = 0;
        else
            versions |= 1;
    }

    for (i = 0; i < GetLinkPlayerCount(); i++)
    {
        struct LinkPlayer *player = &gLinkPlayers[i];

        // Does player not have National Dex
        do
        {
            if (!(player->progressFlags & 0xF))
                canTradeAnyMon = FALSE;

            if (versions && (player->progressFlags / 16))
                canTradeAnyMon = FALSE;
        } while (0);
    }

    if (canTradeAnyMon == FALSE)
    {
        if (!IsSpeciesInHoennDex(speciesArray[monIdx]))
            return CANT_TRADE_NATIONAL;

        if (speciesArray[monIdx] == SPECIES_NONE)
            return CANT_TRADE_EGG_YET;
    }

    numMonsLeft = 0;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (monIdx != i)
            numMonsLeft += speciesArray[i];
    }

    if (!numMonsLeft)
        return CANT_TRADE_LAST_MON;
    else
        return CAN_TRADE_MON;
}


static void SpriteCB_LinkMonGlow(struct Sprite *sprite)
{
    if (++sprite->data[0] == 10)
    {
        PlaySE(SE_BALL);
        sprite->data[0] = 0;
    }
}

static void SpriteCB_LinkMonGlowWireless(struct Sprite *sprite)
{
    if (!sprite->invisible && ++sprite->data[0] == 10)
    {
        PlaySE(SE_M_SWAGGER2);
        sprite->data[0] = 0;
    }
}

static void SpriteCB_LinkMonShadow(struct Sprite *sprite)
{
    if (!sprite->data[1])
    {
        if (++sprite->data[0] == 12)
            sprite->data[0] = 0;

        LoadPalette(&gUnknown_830D0E8[sprite->data[0]], OBJ_PLTT_ID2(sprite->oam.paletteNum) + 4, PLTT_SIZEOF(1));
    }
}

static void SpriteCB_CableEndSending(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->y2++;

    if (sprite->data[0] == 10)
        DestroySprite(sprite);
}

static void SpriteCB_CableEndReceiving(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->y2--;

    if (sprite->data[0] == 10)
        DestroySprite(sprite);
}

static void SpriteCB_GbaScreen(struct Sprite *sprite)
{
    if (++sprite->data[0] == 15)
    {
        PlaySE(SE_M_MINIMIZE);
        sprite->data[0] = 0;
    }
}

static void SetTradeBGAffine(void)
{
    struct BgAffineDstData affine;

    DoBgAffineSet(&affine, gUnknown_2031F40->texX * 0x100, gUnknown_2031F40->texY * 0x100, gUnknown_2031F40->scrX, gUnknown_2031F40->scrY, gUnknown_2031F40->sXY, gUnknown_2031F40->sXY, gUnknown_2031F40->alpha);
    SetGpuReg(REG_OFFSET_BG2PA, (u16)affine.pa);
    SetGpuReg(REG_OFFSET_BG2PB, (u16)affine.pb);
    SetGpuReg(REG_OFFSET_BG2PC, (u16)affine.pc);
    SetGpuReg(REG_OFFSET_BG2PD, (u16)affine.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, (u16)affine.dx);
    SetGpuReg(REG_OFFSET_BG2Y_L, (u16)affine.dy);
}

static void SetTradeGpuRegs(void)
{
    u16 dispcnt;

    SetGpuReg(REG_OFFSET_BG1VOFS, (u16)gUnknown_2031F40->bg1vofs);
    SetGpuReg(REG_OFFSET_BG1HOFS, (u16)gUnknown_2031F40->bg1hofs);

    dispcnt = GetGpuReg(REG_OFFSET_DISPCNT);
    if ((dispcnt & 7) == DISPCNT_MODE_0)
    {
        SetGpuReg(REG_OFFSET_BG2VOFS, (u16)gUnknown_2031F40->bg2vofs);
        SetGpuReg(REG_OFFSET_BG2HOFS, (u16)gUnknown_2031F40->bg2hofs);
    }
    else
    {
        SetTradeBGAffine();
    }
}

static void VBlankCB_TradeAnim(void)
{
    SetTradeGpuRegs();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ClearLinkTimeoutTimer(void)
{
    gUnknown_2031F40->linkTimeoutTimer = 0;
    gUnknown_2031F40->linkTimeoutZero1 = 0;
    gUnknown_2031F40->linkTimeoutZero2 = 0;
}

static void CheckForLinkTimeout(void)
{
    if (gUnknown_2031F40->linkTimeoutZero1 == gUnknown_2031F40->linkTimeoutZero2)
        gUnknown_2031F40->linkTimeoutTimer++;
    else
        gUnknown_2031F40->linkTimeoutTimer = 0;

    if (gUnknown_2031F40->linkTimeoutTimer > 300)
    {
        CloseLink();
        SetMainCallback2(CB2_LinkError);
        gUnknown_2031F40->linkTimeoutTimer = 0;
        gUnknown_2031F40->linkTimeoutZero2 = 0;
        gUnknown_2031F40->linkTimeoutZero1 = 0;
    }

    gUnknown_2031F40->linkTimeoutZero2 = gUnknown_2031F40->linkTimeoutZero1;
}

static u32 TradeGetMultiplayerId(void)
{
    if (gReceivedRemoteLinkPlayers)
        return GetMultiplayerId();
    return 0;
}

static void LoadTradeMonPic(u8 whichParty, u8 state)
{
    int pos = 0;
    struct Pokemon *mon = NULL;
    u16 species;
    u32 personality;

    if (whichParty == TRADE_PLAYER)
    {
        mon = &gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]];
        pos = B_POSITION_OPPONENT_LEFT;
    }

    if (whichParty == TRADE_PARTNER)
    {
        mon = &gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE];
        pos = B_POSITION_OPPONENT_RIGHT;
    }

    switch (state)
    {
    case 0:
        species = GetMonData3(mon, MON_DATA_SPECIES_OR_EGG);
        personality = GetMonData3(mon, MON_DATA_PERSONALITY);

        if (whichParty == TRADE_PLAYER)
            HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[B_POSITION_OPPONENT_LEFT], species, personality);
        else
            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[whichParty * 2 + B_POSITION_OPPONENT_LEFT], species, personality);

        LoadCompressedSpritePalette(GetMonSpritePalStruct(mon));
        gUnknown_2031F40->monSpecies[whichParty] = species;
        gUnknown_2031F40->monPersonalities[whichParty] = personality;
        break;
    case 1:
        SetMultiuseSpriteTemplateToPokemon(GetMonSpritePalStruct(mon)->tag, pos);
        gUnknown_2031F40->monSpriteIds[whichParty] = CreateSprite(&gMultiuseSpriteTemplate, 120, 60, 6);
        gSprites[gUnknown_2031F40->monSpriteIds[whichParty]].invisible = TRUE;
        gSprites[gUnknown_2031F40->monSpriteIds[whichParty]].callback = SpriteCallbackDummy;
        break;
    }
}

void CB2_LinkTrade(void)
{
    switch (gMain.state)
    {
    case 0:
        if (!gReceivedRemoteLinkPlayers)
        {
            gLinkType = LINKTYPE_TRADE_DISCONNECTED;
            CloseLink();
        }
        gUnknown_2031F40 = AllocZeroed(sizeof(*gUnknown_2031F40));
        AllocateMonSpritesGfx();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(VBlankCB_TradeAnim);
        TradeAnimInit_LoadGfx();
        ClearLinkTimeoutTimer();
        gMain.state++;
        gUnknown_2031F40->neverRead_8C = 0;
        gUnknown_2031F40->state = 0;
        gUnknown_2031F40->isLinkTrade = TRUE;
        gUnknown_2031F40->texX = 64;
        gUnknown_2031F40->texY = 64;
        gUnknown_2031F40->neverRead_D8 = 0;
        gUnknown_2031F40->neverRead_DA = 0;
        gUnknown_2031F40->scrX = DISPLAY_WIDTH / 2;
        gUnknown_2031F40->scrY = DISPLAY_HEIGHT / 2;
        gUnknown_2031F40->sXY = 256;
        gUnknown_2031F40->alpha = 0;
        break;
    case 1:
        if (!gReceivedRemoteLinkPlayers)
        {
            gUnknown_2031F40->isCableTrade = TRUE;
            OpenLink();
            gMain.state++;
            gUnknown_2031F40->timer = 0;
        }
        else
        {
            gMain.state = 4;
        }
        break;
    case 2:
        if (++gUnknown_2031F40->timer > 60)
        {
            gUnknown_2031F40->timer = 0;
            gMain.state++;
        }
        break;
    case 3:
        if (IsLinkMaster())
        {
            if (GetLinkPlayerCount_2() >= GetSavedPlayerCount())
            {
                if (++gUnknown_2031F40->timer > 30)
                {
                    CheckShouldAdvanceLinkState();
                    gMain.state++;
                }
            }
            else
            {
                CheckForLinkTimeout();
            }
        }
        else
        {
            gMain.state++;
        }
        break;
    case 4:
        CheckForLinkTimeout();
        if (gReceivedRemoteLinkPlayers == TRUE && IsLinkPlayerDataExchangeComplete() == TRUE)
            gMain.state++;
        break;
    case 5:
        gUnknown_2031F40->playerFinishStatus = 0;
        gUnknown_2031F40->partnerFinishStatus = 0;
        gUnknown_2031F40->scheduleLinkTransfer = 0;
        LoadTradeMonPic(TRADE_PLAYER, 0);
        gMain.state++;
        break;
    case 6:
        LoadTradeMonPic(TRADE_PLAYER, 1);
        gMain.state++;
        break;
    case 7:
        LoadTradeMonPic(TRADE_PARTNER, 0);
        gMain.state++;
        break;
    case 8:
        LoadTradeMonPic(TRADE_PARTNER, 1);
        LinkTradeDrawWindow();
        gMain.state++;
        break;
    case 9:
        LoadTradeSequenceSpriteSheetsAndPalettes();
        LoadSpriteSheet(&gUnknown_830CF5C);
        LoadSpritePalette(&gUnknown_830CF64);
        gMain.state++;
        break;
    case 10:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        ShowBg(0);
        gMain.state++;
        break;
    case 11:
        InitTradeSequenceBgGpuRegs();
        SetTradeSceneStrings();
        gMain.state++;
        break;
    case 12:
        if (!gPaletteFade.active)
        {
            if (gWirelessCommType)
            {
                LoadWirelessStatusIndicatorSpriteGfx();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
            SetMainCallback2(CB2_UpdateLinkTrade);
        }
        break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void InitTradeSequenceBgGpuRegs(void)
{
    SetTradeSequenceBgGpuRegs(5);
    SetTradeSequenceBgGpuRegs(0);
}

void LinkTradeDrawWindow(void)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(15));
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void TradeAnimInit_LoadGfx(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_830D294, 4);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    SetBgTilemapBuffer(0, Alloc(BG_SCREEN_SIZE));
    SetBgTilemapBuffer(1, Alloc(BG_SCREEN_SIZE));
    SetBgTilemapBuffer(3, Alloc(BG_SCREEN_SIZE));
    DeactivateAllTextPrinters();
    // Doing the graphics load...
    DecompressAndLoadBgGfxUsingHeap(0, (const u32 *)0x08C00000, 0, 0, 0); // gBattleTextboxTiles (fixed ROM address)
    LZDecompressVram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, BG_SCREEN_SIZE, 0);
    LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    InitWindows(gUnknown_830D27C);
    // ... and doing the same load again
    DecompressAndLoadBgGfxUsingHeap(0, (const u32 *)0x08C00000, 0, 0, 0); // gBattleTextboxTiles (fixed ROM address)
    LZDecompressVram(gBattleTextboxTilemap, gDecompressionBuffer);
    CopyToBgTilemapBuffer(0, gDecompressionBuffer, BG_SCREEN_SIZE, 0);
    LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
}

void CB2_InGameTrade(void)
{
    u8 otName[12];

    switch (gMain.state)
    {
    case 0:
        gSelectedTradeMonPositions[TRADE_PLAYER] = gSpecialVar_0x8005;
        gSelectedTradeMonPositions[TRADE_PARTNER] = 6;
        StringCopy(gUnknown_20226A8, gSaveBlock2Ptr->playerName);
        GetMonData3(&gEnemyParty[0], MON_DATA_OT_NAME, otName);
        StringCopy(gUnknown_20226A8 + 0x1C, otName);
        gUnknown_2031F40 = AllocZeroed(sizeof(*gUnknown_2031F40));
        AllocateMonSpritesGfx();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        SetVBlankCallback(VBlankCB_TradeAnim);
        TradeAnimInit_LoadGfx();
        gUnknown_2031F40->isLinkTrade = FALSE;
        gUnknown_2031F40->neverRead_8C = 0;
        gUnknown_2031F40->state = 0;
        gUnknown_2031F40->texX = 64;
        gUnknown_2031F40->texY = 64;
        gUnknown_2031F40->neverRead_D8 = 0;
        gUnknown_2031F40->neverRead_DA = 0;
        gUnknown_2031F40->scrX = DISPLAY_WIDTH / 2;
        gUnknown_2031F40->scrY = DISPLAY_HEIGHT / 2;
        gUnknown_2031F40->sXY = 256;
        gUnknown_2031F40->alpha = 0;
        gUnknown_2031F40->timer = 0;
        gMain.state = 5;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
        LoadTradeMonPic(TRADE_PLAYER, 0);
        gMain.state++;
        break;
    case 6:
        LoadTradeMonPic(TRADE_PLAYER, 1);
        gMain.state++;
        break;
    case 7:
        LoadTradeMonPic(TRADE_PARTNER, 0);
        ShowBg(0);
        gMain.state++;
        break;
    case 8:
        LoadTradeMonPic(TRADE_PARTNER, 1);
        FillWindowPixelBuffer(0, PIXEL_FILL(15));
        PutWindowTilemap(0);
        CopyWindowToVram(0, COPYWIN_FULL);
        gMain.state++;
        break;
    case 9:
        LoadTradeSequenceSpriteSheetsAndPalettes();
        LoadSpriteSheet(&gUnknown_830CF5C);
        LoadSpritePalette(&gUnknown_830CF64);
        gMain.state++;
        break;
    case 10:
        ShowBg(0);
        gMain.state++;
        break;
    case 11:
        SetTradeSequenceBgGpuRegs(5);
        SetTradeSequenceBgGpuRegs(0);
        SetTradeSceneStrings();
        gMain.state++;
        break;
    case 12:
        SetMainCallback2(CB2_InGameTradeAnim);
        break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}


static void UpdatePokedexForReceivedMon(u8 partyIdx)
{
    struct Pokemon *mon = &gPlayerParty[partyIdx];

    if (!GetMonData3(mon, MON_DATA_IS_EGG))
    {
        u16 species = GetMonData3(mon, MON_DATA_SPECIES, NULL);
        u32 personality = GetMonData3(mon, MON_DATA_PERSONALITY, NULL);
        species = HoennToNationalOrder(species);
        GetSetPokedexFlag(species, FLAG_SET_SEEN);
        HandleSetPokedexFlag(species, FLAG_SET_CAUGHT, personality);
    }
}

static void GetMultiplayerIdWrapper(void)
{
    GetMultiplayerId();
}

static void TradeMons(u8 playerPartyIdx, u8 partnerPartyIdx)
{
    u8 friendship;

    struct Pokemon *playerMon = &gPlayerParty[playerPartyIdx];
    u16 playerMail = GetMonData3(playerMon, MON_DATA_MAIL);

    struct Pokemon *partnerMon = &gEnemyParty[partnerPartyIdx];
    u16 partnerMail = GetMonData3(partnerMon, MON_DATA_MAIL);

    // The mail attached to the sent Pokémon no longer exists in your file.
    if (playerMail != MAIL_NONE)
        ClearMail(&gSaveBlock1Ptr->mail[playerMail]);

    SWAP(*playerMon, *partnerMon, gUnknown_2031F40->tempMon);

    // By default, a Pokémon received from a trade will have 70 Friendship.
    // Eggs use Friendship to track egg cycles, so don't set this on Eggs.
    friendship = 70;
    if (!GetMonData3(playerMon, MON_DATA_IS_EGG))
        SetMonData(playerMon, MON_DATA_FRIENDSHIP, &friendship);

    if (partnerMail != MAIL_NONE)
        GiveMailToMon(playerMon, &gTradeMail[partnerMail]);

    UpdatePokedexForReceivedMon(playerPartyIdx);
    if (gReceivedRemoteLinkPlayers)
        GetMultiplayerIdWrapper();
}

static void HandleLinkDataSend(void)
{
    switch (gUnknown_2031F40->scheduleLinkTransfer)
    {
    case 1:
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), gUnknown_2031F40->linkData, sizeof(gUnknown_2031F40->linkData));
            gUnknown_2031F40->scheduleLinkTransfer++;
        }
        // fallthrough
    case 2:
        gUnknown_2031F40->scheduleLinkTransfer = 0;
        break;
    }
}

static void CB2_InGameTradeAnim(void)
{
    DoTradeAnim();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void SetTradeSequenceBgGpuRegs(u8 state)
{
    switch (state)
    {
    case 0:
        gUnknown_2031F40->bg2vofs = 0;
        gUnknown_2031F40->bg2hofs = 180;
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(18) | BGCNT_TXT512x256);
        LoadPalette(gUnknown_8305D24, BG_PLTT_ID(1), 3 * PLTT_SIZE_4BPP);
        DmaCopyLarge16(3, gUnknown_8305D84, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
        DmaCopy16Defvars(3, gUnknown_8304D04, (void *) BG_SCREEN_ADDR(18), 0x1000);
        break;
    case 1:
        gUnknown_2031F40->bg1hofs = 0;
        gUnknown_2031F40->bg1vofs = 348;
        SetGpuReg(REG_OFFSET_BG1VOFS, 348);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(0) | BGCNT_16COLOR | BGCNT_SCREENBASE(5) | BGCNT_TXT256x512);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(18) | BGCNT_TXT256x512);

        if (gUnknown_2031F40->isCableTrade)
        {
            DmaCopy16Defvars(3, gUnknown_830ABE4, (void *) BG_SCREEN_ADDR(5), 0x1000);
        }
        else
        {
            DmaCopy16Defvars(3, gUnknown_8309BE4, (void *) BG_SCREEN_ADDR(5), 0x1000);
        }

        DmaCopyLarge16(3, gUnknown_8305D84, (void *) BG_CHAR_ADDR(0), 0x1420, 0x1000);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_OBJ_ON);
        break;
    case 2:
        gUnknown_2031F40->bg1vofs = 0;
        gUnknown_2031F40->bg1hofs = 0;
        if (!gUnknown_2031F40->isCableTrade)
        {
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_OBJ_ON);
            LZ77UnCompVram(gUnknown_830BBE4, (void *) BG_SCREEN_ADDR(5));
            BlendPalettes(0x8, 16, RGB_BLACK);
        }
        else
        {
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_OBJ_ON);
            DmaCopy16Defvars(3, gUnknown_8302D64, (void *) BG_SCREEN_ADDR(5), 0x800);
            BlendPalettes(0x1, 16, RGB_BLACK);
        }
        break;
    case 3:
        LoadPalette(gUnknown_830C0E4, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
        LZ77UnCompVram(gUnknown_830C104, (void *) BG_CHAR_ADDR(1));
        LZ77UnCompVram(gUnknown_830C794, (void *) BG_SCREEN_ADDR(18));
        gUnknown_2031F40->bg2vofs = 80;
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
        break;
    case 4:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(1) | BGCNT_256COLOR | BGCNT_SCREENBASE(18) | BGCNT_AFF128x128);
        gUnknown_2031F40->texX = 64;
        gUnknown_2031F40->texY = 92;
        gUnknown_2031F40->sXY = 32;
        gUnknown_2031F40->gbaScale = 1024;
        gUnknown_2031F40->alpha = 0;

        DmaCopyLarge16(3, gUnknown_83071A4, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

        if (gUnknown_2031F40->isCableTrade)
        {
            DmaCopy16Defvars(3, gUnknown_83099E4, (void *) BG_SCREEN_ADDR(18), 0x100);
        }
        else
        {
            DmaCopy16Defvars(3, gUnknown_8309AE4, (void *) BG_SCREEN_ADDR(18), 0x100);
        }
        break;
    case 5:
        gUnknown_2031F40->bg1vofs = 0;
        gUnknown_2031F40->bg1hofs = 0;
        break;
    case 6:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(1) | BGCNT_256COLOR | BGCNT_SCREENBASE(18) | BGCNT_AFF128x128);
        gUnknown_2031F40->texX = 64;
        gUnknown_2031F40->texY = 92;
        gUnknown_2031F40->sXY = 256;
        gUnknown_2031F40->gbaScale = 128;
        gUnknown_2031F40->scrX = 120;
        gUnknown_2031F40->scrY = 80;
        gUnknown_2031F40->alpha = 0;

        DmaCopyLarge16(3, gUnknown_83071A4, (void *) BG_CHAR_ADDR(1), 0x2840, 0x1000);

        if (gUnknown_2031F40->isCableTrade)
        {
            DmaCopy16Defvars(3, gUnknown_83099E4, (void *) BG_SCREEN_ADDR(18), 0x100);
        }
        else
        {
            DmaCopy16Defvars(3, gUnknown_8309AE4, (void *) BG_SCREEN_ADDR(18), 0x100);
        }
        break;
    case 7:
        gUnknown_2031F40->bg2vofs = 0;
        gUnknown_2031F40->bg2hofs = 0;
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_16COLOR | BGCNT_SCREENBASE(18) | BGCNT_TXT512x256);
        LoadPalette(gUnknown_8305D24, BG_PLTT_ID(1), 3 * PLTT_SIZE_4BPP);
        DmaCopyLarge16(3, gUnknown_8305D84, (void *) BG_CHAR_ADDR(1), 0x1420, 0x1000);
        DmaCopy16Defvars(3, gUnknown_8304D04, (void *) BG_SCREEN_ADDR(18), 0x1000);
        break;
    }
}

static void LoadTradeSequenceSpriteSheetsAndPalettes(void)
{
    LoadSpriteSheet(&gUnknown_830CFB4);
    LoadSpriteSheet(&gUnknown_830D004);
    LoadSpriteSheet(&gUnknown_830D038);
    LoadSpriteSheet(&gUnknown_830D0B0);
    LoadSpritePalette(&gUnknown_830CFBC);
    LoadSpritePalette(&gUnknown_830CFC4);
}

static void SetTradeSceneStrings(void)
{
    u8 name[POKEMON_NAME_BUFFER_SIZE];
    const struct InGameTrade *ingameTrade;

    if (gUnknown_2031F40->isLinkTrade)
    {
        u8 mpId = GetMultiplayerId();
        StringCopy(gStringVar1, gLinkPlayers[mpId ^ 1].name);
        GetMonData3(&gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar3, name);
        GetMonData3(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
    else
    {
        ingameTrade = &gUnknown_830D114[gSpecialVar_0x8004];
        StringCopy(gStringVar1, ingameTrade->otName);
        StringCopy10(gStringVar3, ingameTrade->nickname);
        GetMonData3(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, name);
        StringCopy10(gStringVar2, name);
    }
}

static bool8 DoTradeAnim(void)
{
    if (gUnknown_2031F40->isCableTrade)
        return DoTradeAnim_Cable();
    else
        return DoTradeAnim_Wireless();
}

// Below are the states for the main switch in DoTradeAnim_Cable and DoTradeAnim_Wireless
// When DoTradeAnim_Wireless has a unique version of a state used by DoTradeAnim_Cable, it adds the below modifier
#define STATE_WIRELESS 100

enum {
    ANIM_LINKMON_NORMAL,
    ANIM_LINKMON_SMALL,
};
enum {
    STATE_START,
    STATE_MON_SLIDE_IN,
    // 2-9 unused
    STATE_SEND_MSG = 10,
    STATE_BYE_BYE,
    STATE_POKEBALL_DEPART,
    STATE_POKEBALL_DEPART_WAIT,
    STATE_FADE_OUT_TO_GBA_SEND,
    // 15-19 unused
    STATE_WAIT_FADE_OUT_TO_GBA_SEND = 20,
    STATE_FADE_IN_TO_GBA_SEND,
    STATE_WAIT_FADE_IN_TO_GBA_SEND,
    STATE_GBA_ZOOM_OUT,
    STATE_GBA_FLASH_SEND,
    STATE_GBA_STOP_FLASH_SEND,
    STATE_PAN_AWAY_GBA,
    STATE_CREATE_LINK_MON_LEAVING,
    STATE_LINK_MON_TRAVEL_OUT,
    STATE_FADE_OUT_TO_CROSSING,
    STATE_WAIT_FADE_OUT_TO_CROSSING,
    STATE_FADE_IN_TO_CROSSING,
    STATE_WAIT_FADE_IN_TO_CROSSING,
    STATE_CROSSING_LINK_MONS_ENTER,
    STATE_CROSSING_BLEND_WHITE_1,
    STATE_CROSSING_BLEND_WHITE_2,
    STATE_CROSSING_BLEND_WHITE_3,
    STATE_CROSSING_CREATE_MON_PICS,
    STATE_CROSSING_MON_PICS_MOVE,
    STATE_CROSSING_LINK_MONS_EXIT,
    STATE_CREATE_LINK_MON_ARRIVING,
    STATE_FADE_OUT_TO_GBA_RECV,
    STATE_WAIT_FADE_OUT_TO_GBA_RECV,
    STATE_LINK_MON_TRAVEL_IN,
    STATE_PAN_TO_GBA,
    STATE_DESTROY_LINK_MON,
    STATE_LINK_MON_ARRIVED_DELAY,
    STATE_MOVE_GBA_TO_CENTER,
    STATE_GBA_FLASH_RECV,
    STATE_UNUSED,
    STATE_GBA_STOP_FLASH_RECV,
    STATE_GBA_ZOOM_IN,
    STATE_FADE_OUT_TO_NEW_MON,
    // 53-59 unused
    STATE_WAIT_FADE_OUT_TO_NEW_MON = 60,
    STATE_FADE_IN_TO_NEW_MON,
    STATE_WAIT_FADE_IN_TO_NEW_MON,
    STATE_POKEBALL_ARRIVE,
    STATE_FADE_POKEBALL_TO_NORMAL,
    STATE_POKEBALL_ARRIVE_WAIT,
    STATE_SHOW_NEW_MON,
    STATE_NEW_MON_MSG,
    STATE_TAKE_CARE_OF_MON,
    STATE_AFTER_NEW_MON_DELAY,
    STATE_CHECK_RIBBONS,
    STATE_END_LINK_TRADE,
    STATE_TRY_EVOLUTION,
    STATE_FADE_OUT_END,
    STATE_WAIT_FADE_OUT_END,
    // Special states
    STATE_GBA_FLASH_SEND_WIRELESS = STATE_GBA_FLASH_SEND + STATE_WIRELESS,
    STATE_GBA_STOP_FLASH_SEND_WIRELESS,
    STATE_WAIT_WIRELESS_SIGNAL_SEND,
    STATE_PAN_TO_GBA_WIRELESS = STATE_PAN_TO_GBA + STATE_WIRELESS,
    STATE_DESTROY_LINK_MON_WIRELESS,
    STATE_WAIT_WIRELESS_SIGNAL_RECV,
    STATE_DELAY_FOR_MON_ANIM = 167,
    STATE_LINK_MON_TRAVEL_OFFSCREEN = 200,
    STATE_WAIT_FOR_MON_CRY = 267,
};

static bool8 DoTradeAnim_Cable(void)
{
    u16 evoTarget;

    switch (gUnknown_2031F40->state)
    {
    case STATE_START:
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].invisible = FALSE;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].x2 = -180;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 = gMonFrontPicCoords[gUnknown_2031F40->monSpecies[TRADE_PLAYER]].y_offset;
        gUnknown_2031F40->state++;
        gUnknown_2031F40->cachedMapMusic = GetCurrentMapMusic();
        PlayNewMapMusic(MUS_EVOLUTION);
        break;
    case STATE_MON_SLIDE_IN:
        if (gUnknown_2031F40->bg2hofs > 0)
        {
            // Sliding
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].x2 += 3;
            gUnknown_2031F40->bg2hofs -= 3;
        }
        else
        {
            // Pokémon has arrived onscreen
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].x2 = 0;
            gUnknown_2031F40->bg2hofs = 0;
            gUnknown_2031F40->state = STATE_SEND_MSG;
        }
        break;
    case STATE_SEND_MSG:
        StringExpandPlaceholders(gStringVar4, gUnknown_830D240);
        DrawTextOnTradeWindow(0, gStringVar4, 0);

        if (gUnknown_2031F40->monSpecies[TRADE_PLAYER] != SPECIES_EGG)
            PlayCry_Normal(gUnknown_2031F40->monSpecies[TRADE_PLAYER], 0);

        gUnknown_2031F40->state = STATE_BYE_BYE;
        gUnknown_2031F40->timer = 0;
        break;
    case STATE_BYE_BYE:
        if (++gUnknown_2031F40->timer == 80)
        {
            gUnknown_2031F40->releasePokeballSpriteId = CreateTradePokeballSprite(gUnknown_2031F40->monSpriteIds[TRADE_PLAYER], gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
            gUnknown_2031F40->state++;
            StringExpandPlaceholders(gStringVar4, gUnknown_830D24F);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
        }
        break;
    case STATE_POKEBALL_DEPART:
        if (gSprites[gUnknown_2031F40->releasePokeballSpriteId].callback == SpriteCallbackDummy)
        {
            gUnknown_2031F40->bouncingPokeballSpriteId = CreateSprite(&gUnknown_830CF6C, 120, 32, 0);
            gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballDepart;
            DestroySprite(&gSprites[gUnknown_2031F40->releasePokeballSpriteId]);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_POKEBALL_DEPART_WAIT:
        // The game waits here for the sprite to finish its animation sequence.
        break;
    case STATE_FADE_OUT_TO_GBA_SEND:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gUnknown_2031F40->state = STATE_WAIT_FADE_OUT_TO_GBA_SEND;
        break;
    case STATE_WAIT_FADE_OUT_TO_GBA_SEND:
        if (!gPaletteFade.active)
        {
            SetTradeSequenceBgGpuRegs(4);
            FillWindowPixelBuffer(0, PIXEL_FILL(15));
            CopyWindowToVram(0, COPYWIN_FULL);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_FADE_IN_TO_GBA_SEND:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_IN_TO_GBA_SEND:
        if (!gPaletteFade.active)
            gUnknown_2031F40->state = STATE_GBA_ZOOM_OUT;
        break;
    case STATE_GBA_ZOOM_OUT:
        if (gUnknown_2031F40->gbaScale > 0x100)
        {
            gUnknown_2031F40->gbaScale -= 0x34;
        }
        else
        {
            SetTradeSequenceBgGpuRegs(1);
            gUnknown_2031F40->gbaScale = 0x80;
            gUnknown_2031F40->state++;
            gUnknown_2031F40->timer = 0;
        }
        gUnknown_2031F40->sXY = 0x8000 / gUnknown_2031F40->gbaScale;
        break;
    case STATE_GBA_FLASH_SEND:
        if (++gUnknown_2031F40->timer > 20)
        {
            SetTradeBGAffine();
            gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D0B8, 120, 80, 0);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_GBA_STOP_FLASH_SEND:
        if (gSprites[gUnknown_2031F40->connectionSpriteId2].animEnded)
        {
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND |
                                         BLDCNT_TGT2_BG1 |
                                         BLDCNT_TGT2_BG2);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(12, 4));
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_PAN_AWAY_GBA:
        if (--gUnknown_2031F40->bg1vofs == 316)
            gUnknown_2031F40->state++;

        if (gUnknown_2031F40->bg1vofs == 328)
            gUnknown_2031F40->cableEndSpriteId = CreateSprite(&gUnknown_830D040, 128, 65, 0);
        break;
    case STATE_CREATE_LINK_MON_LEAVING:
        gUnknown_2031F40->connectionSpriteId1 = CreateSprite(&gUnknown_830CFCC, 128, 80, 3);
        gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D00C, 128, 80, 0);
        StartSpriteAnim(&gSprites[gUnknown_2031F40->connectionSpriteId2], ANIM_LINKMON_SMALL);
        gUnknown_2031F40->state++;
        break;
    case STATE_LINK_MON_TRAVEL_OUT:
        if ((gUnknown_2031F40->bg1vofs -= 2) == 166)
            gUnknown_2031F40->state = STATE_LINK_MON_TRAVEL_OFFSCREEN;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_OBJ_ON);
        break;
    case STATE_LINK_MON_TRAVEL_OFFSCREEN:
        gSprites[gUnknown_2031F40->connectionSpriteId1].y -= 2;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y -= 2;
        if (gSprites[gUnknown_2031F40->connectionSpriteId1].y < -8)
            gUnknown_2031F40->state = STATE_FADE_OUT_TO_CROSSING;
        break;
    case STATE_FADE_OUT_TO_CROSSING:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
        gUnknown_2031F40->state = STATE_WAIT_FADE_OUT_TO_CROSSING;
        break;
    case STATE_WAIT_FADE_OUT_TO_CROSSING:
        if (!gPaletteFade.active)
        {
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId1]);
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
            SetTradeSequenceBgGpuRegs(2);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_FADE_IN_TO_CROSSING:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        gUnknown_2031F40->connectionSpriteId1 = CreateSprite(&gUnknown_830D00C, 111, 170, 0);
        gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D00C, 129, -10, 0);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_IN_TO_CROSSING:
        if (!gPaletteFade.active)
        {
            PlaySE(SE_WARP_OUT);
            gUnknown_2031F40->state++;
        }
        gSprites[gUnknown_2031F40->connectionSpriteId1].y2 -= 3;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y2 += 3;
        break;
    case STATE_CROSSING_LINK_MONS_ENTER:
        gSprites[gUnknown_2031F40->connectionSpriteId1].y2 -= 3;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y2 += 3;
        if (gSprites[gUnknown_2031F40->connectionSpriteId1].y2 <= -90)
        {
            gSprites[gUnknown_2031F40->connectionSpriteId1].data[1] = 1;
            gSprites[gUnknown_2031F40->connectionSpriteId2].data[1] = 1;
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_CROSSING_BLEND_WHITE_1:
        BlendPalettes(0x1, 16, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        break;
    case STATE_CROSSING_BLEND_WHITE_2:
        BlendPalettes(0x1, 0, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        break;
    case STATE_CROSSING_BLEND_WHITE_3:
        BlendPalettes(0x1, 16, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        break;
    case STATE_CROSSING_CREATE_MON_PICS:
        if (!IsMonSpriteNotFlipped(gUnknown_2031F40->monSpecies[TRADE_PLAYER]))
        {
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].affineAnims = gUnknown_830D110;
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
            CalcCenterToCornerVec(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]], SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), ST_OAM_AFFINE_DOUBLE);
            StartSpriteAffineAnim(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]], 0);
        }
        else
        {
            StartSpriteAffineAnim(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]], 0);
        }
        StartSpriteAffineAnim(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]], 0);
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].x = 60;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].x = 180;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y = 192;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].y = -32;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].invisible = FALSE;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].invisible = FALSE;
        gUnknown_2031F40->state++;
        break;
    case STATE_CROSSING_MON_PICS_MOVE:
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 -= 3;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].y2 += 3;
        if (gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 < -DISPLAY_HEIGHT
         && gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 >= -DISPLAY_HEIGHT - 3)
        {
            PlaySE(SE_WARP_IN);
        }
        if (gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 < -222)
        {
            gSprites[gUnknown_2031F40->connectionSpriteId1].data[1] = 0;
            gSprites[gUnknown_2031F40->connectionSpriteId2].data[1] = 0;
            gUnknown_2031F40->state++;
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].invisible = TRUE;
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].invisible = TRUE;
            BlendPalettes(0x1, 0, RGB_WHITEALPHA);
        }
        break;
    case STATE_CROSSING_LINK_MONS_EXIT:
        gSprites[gUnknown_2031F40->connectionSpriteId1].y2 -= 3;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y2 += 3;
        if (gSprites[gUnknown_2031F40->connectionSpriteId1].y2 <= -222)
        {
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
            gUnknown_2031F40->state++;
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId1]);
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
        }
        break;
    case STATE_CREATE_LINK_MON_ARRIVING:
        if (!gPaletteFade.active)
        {
            gUnknown_2031F40->state++;
            SetTradeSequenceBgGpuRegs(1);
            gUnknown_2031F40->bg1vofs = 166;
            gUnknown_2031F40->connectionSpriteId1 = CreateSprite(&gUnknown_830CFCC, 128, -20, 3);
            gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D00C, 128, -20, 0);
            StartSpriteAnim(&gSprites[gUnknown_2031F40->connectionSpriteId2], ANIM_LINKMON_SMALL);
        }
        break;
    case STATE_FADE_OUT_TO_GBA_RECV:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_OUT_TO_GBA_RECV:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_OBJ_ON);
        if (!gPaletteFade.active)
            gUnknown_2031F40->state++;
        break;
    case STATE_LINK_MON_TRAVEL_IN:
        gSprites[gUnknown_2031F40->connectionSpriteId1].y2 += 3;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y2 += 3;
        if (gSprites[gUnknown_2031F40->connectionSpriteId1].y2 + gSprites[gUnknown_2031F40->connectionSpriteId1].y == 64)
            gUnknown_2031F40->state++;
        break;
    case STATE_PAN_TO_GBA:
        if ((gUnknown_2031F40->bg1vofs += 2) > 316)
        {
            gUnknown_2031F40->bg1vofs = 316;
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_DESTROY_LINK_MON:
        DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId1]);
        DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
        gUnknown_2031F40->state++;
        gUnknown_2031F40->timer = 0;
        break;
    case STATE_LINK_MON_ARRIVED_DELAY:
        if (++gUnknown_2031F40->timer == 10)
            gUnknown_2031F40->state++;
        break;
    case STATE_MOVE_GBA_TO_CENTER:
        if (++gUnknown_2031F40->bg1vofs > 348)
        {
            gUnknown_2031F40->bg1vofs = 348;
            gUnknown_2031F40->state++;
        }
        if (gUnknown_2031F40->bg1vofs == 328 && gUnknown_2031F40->isCableTrade)
        {
            gUnknown_2031F40->cableEndSpriteId = CreateSprite(&gUnknown_830D040, 128, 65, 0);
            gSprites[gUnknown_2031F40->cableEndSpriteId].callback = SpriteCB_CableEndReceiving;
        }
        break;
    case STATE_GBA_FLASH_RECV:
        gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D0B8, 120, 80, 0);
        gUnknown_2031F40->state = STATE_GBA_STOP_FLASH_RECV;
        break;
    case STATE_GBA_STOP_FLASH_RECV:
        if (gSprites[gUnknown_2031F40->connectionSpriteId2].animEnded)
        {
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
            SetTradeSequenceBgGpuRegs(6);
            gUnknown_2031F40->state++;
            PlaySE(SE_M_SAND_ATTACK);
        }
        break;
    case STATE_GBA_ZOOM_IN:
        if (gUnknown_2031F40->gbaScale < 0x400)
        {
            gUnknown_2031F40->gbaScale += 0x34;
        }
        else
        {
            gUnknown_2031F40->gbaScale = 0x400;
            gUnknown_2031F40->state++;
        }
        gUnknown_2031F40->sXY = 0x8000 / gUnknown_2031F40->gbaScale;
        break;
    case STATE_FADE_OUT_TO_NEW_MON:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gUnknown_2031F40->state = STATE_WAIT_FADE_OUT_TO_NEW_MON;
        break;

    case STATE_WAIT_FADE_OUT_TO_NEW_MON:
        if (!gPaletteFade.active)
        {
            SetTradeSequenceBgGpuRegs(5);
            SetTradeSequenceBgGpuRegs(7);
            gPaletteFade.bufferTransferDisabled = TRUE;
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_FADE_IN_TO_NEW_MON:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_IN_TO_NEW_MON:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        if (!gPaletteFade.active)
            gUnknown_2031F40->state++;
        break;
    case STATE_POKEBALL_ARRIVE:
        gUnknown_2031F40->bouncingPokeballSpriteId = CreateSprite(&gUnknown_830CF6C, 120, -8, 0);
        gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].data[3] = 74;
        gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballArrive;
        StartSpriteAnim(&gSprites[gUnknown_2031F40->bouncingPokeballSpriteId], 1);
        StartSpriteAffineAnim(&gSprites[gUnknown_2031F40->bouncingPokeballSpriteId], 2);
        BlendPalettes(1 << (16 + gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].oam.paletteNum), 16, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        gUnknown_2031F40->timer = 0;
        break;
    case STATE_FADE_POKEBALL_TO_NORMAL:
        BeginNormalPaletteFade(1 << (16 + gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        break;
    case STATE_POKEBALL_ARRIVE_WAIT:
        if (gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].callback == SpriteCallbackDummy)
        {
            HandleLoadSpecialPokePic_2(&gMonFrontPicTable[gUnknown_2031F40->monSpecies[TRADE_PARTNER]],
                                        gMonSpritesGfxPtr->sprites.ptr[B_POSITION_OPPONENT_RIGHT],
                                        gUnknown_2031F40->monSpecies[TRADE_PARTNER],
                                        gUnknown_2031F40->monPersonalities[TRADE_PARTNER]);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_SHOW_NEW_MON:
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].x = 120;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].y = gMonFrontPicCoords[gUnknown_2031F40->monSpecies[TRADE_PARTNER]].y_offset + 60;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].x2 = 0;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].y2 = 0;
        StartSpriteAnim(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]], 0);
        CreatePokeballSpriteToReleaseMon(gUnknown_2031F40->monSpriteIds[TRADE_PARTNER], gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].oam.paletteNum, 120, 84, 2, 1, 20, PALETTES_BG | (0xF << 16), gUnknown_2031F40->monSpecies[TRADE_PARTNER]);
        FreeSpriteOamMatrix(&gSprites[gUnknown_2031F40->bouncingPokeballSpriteId]);
        DestroySprite(&gSprites[gUnknown_2031F40->bouncingPokeballSpriteId]);
        gUnknown_2031F40->state++;
        break;
    case STATE_NEW_MON_MSG:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG0_ON |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        StringExpandPlaceholders(gStringVar4, gUnknown_830D258);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        gUnknown_2031F40->state = STATE_DELAY_FOR_MON_ANIM;
        gUnknown_2031F40->timer = 0;
        break;
    case STATE_DELAY_FOR_MON_ANIM:
        if (++gUnknown_2031F40->timer > 60)
        {
            gUnknown_2031F40->state = STATE_WAIT_FOR_MON_CRY;
            gUnknown_2031F40->timer = 0;
        }
        break;
    case STATE_WAIT_FOR_MON_CRY:
        if (IsCryFinished())
            gUnknown_2031F40->state = STATE_TAKE_CARE_OF_MON;
        break;
    case STATE_TAKE_CARE_OF_MON:
        if (++gUnknown_2031F40->timer == 10)
            PlayFanfare(MUS_EVOLVED);

        if (gUnknown_2031F40->timer == 250)
        {
            gUnknown_2031F40->state++;
            StringExpandPlaceholders(gStringVar4, gUnknown_830D26A);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            gUnknown_2031F40->timer = 0;
        }
        break;
    case STATE_AFTER_NEW_MON_DELAY:
        if (++gUnknown_2031F40->timer == 60)
            gUnknown_2031F40->state++;
        break;
    case STATE_CHECK_RIBBONS:
        CheckPartnersMonForRibbons();
        gUnknown_2031F40->state++;
        break;
    case STATE_END_LINK_TRADE:
        if (gUnknown_2031F40->isLinkTrade)
            return TRUE;
        else if (JOY_NEW(A_BUTTON))
            gUnknown_2031F40->state++;
        break;
    case STATE_TRY_EVOLUTION: // Only if in-game trade, link trades use CB2_TryLinkTradeEvolution
        TradeMons(gSpecialVar_0x8005, 0);
        gCB2_AfterEvolution = CB2_InGameTradeAnim;
        evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], EVO_MODE_TRADE, ITEM_NONE);
        if (evoTarget != SPECIES_NONE)
            TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, gUnknown_2031F40->monSpriteIds[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
        gUnknown_2031F40->state++;
        break;
    case STATE_FADE_OUT_END:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_OUT_END:
        if (!gPaletteFade.active)
        {
            PlayNewMapMusic(gUnknown_2031F40->cachedMapMusic);
            if (gUnknown_2031F40)
            {
                FreeAllWindowBuffers();
                Free(GetBgTilemapBuffer(3));
                Free(GetBgTilemapBuffer(1));
                Free(GetBgTilemapBuffer(0));
                FreeMonSpritesGfx();
                FREE_AND_SET_NULL(gUnknown_2031F40);
            }
            SetMainCallback2(CB2_ReturnToField);
            BufferInGameTradeMonName();
        }
        break;
    }
    return FALSE;
}

// Task data for Task_AnimateWirelessSignal
#define tIdx               data[0]
#define tCounter           data[1]
#define tSignalComingBack  data[2]

static bool8 DoTradeAnim_Wireless(void)
{
    u16 evoTarget;

    switch (gUnknown_2031F40->state)
    {
    case STATE_START:
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].invisible = FALSE;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].x2 = -180;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 = gMonFrontPicCoords[gUnknown_2031F40->monSpecies[TRADE_PLAYER]].y_offset;
        gUnknown_2031F40->state++;
        gUnknown_2031F40->cachedMapMusic = GetCurrentMapMusic();
        PlayNewMapMusic(MUS_EVOLUTION);
        break;
    case STATE_MON_SLIDE_IN:
        if (gUnknown_2031F40->bg2hofs > 0)
        {
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].x2 += 3;
            gUnknown_2031F40->bg2hofs -= 3;
        }
        else
        {
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].x2 = 0;
            gUnknown_2031F40->bg2hofs = 0;
            gUnknown_2031F40->state = STATE_SEND_MSG;
        }
        break;
    case STATE_SEND_MSG:
        StringExpandPlaceholders(gStringVar4, gUnknown_830D240);
        DrawTextOnTradeWindow(0, gStringVar4, 0);

        if (gUnknown_2031F40->monSpecies[TRADE_PLAYER] != SPECIES_EGG)
            PlayCry_Normal(gUnknown_2031F40->monSpecies[TRADE_PLAYER], 0);

        gUnknown_2031F40->state = STATE_BYE_BYE;
        gUnknown_2031F40->timer = 0;
        break;
    case STATE_BYE_BYE:
        if (++gUnknown_2031F40->timer == 80)
        {
            gUnknown_2031F40->releasePokeballSpriteId = CreateTradePokeballSprite(gUnknown_2031F40->monSpriteIds[TRADE_PLAYER], gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].oam.paletteNum, 120, 32, 2, 1, 0x14, 0xfffff);
            gUnknown_2031F40->state++;
            StringExpandPlaceholders(gStringVar4, gUnknown_830D24F);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
        }
        break;
    case STATE_POKEBALL_DEPART:
        if (gSprites[gUnknown_2031F40->releasePokeballSpriteId].callback == SpriteCallbackDummy)
        {
            gUnknown_2031F40->bouncingPokeballSpriteId = CreateSprite(&gUnknown_830CF6C, 120, 32, 0);
            gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballDepart;
            DestroySprite(&gSprites[gUnknown_2031F40->releasePokeballSpriteId]);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_POKEBALL_DEPART_WAIT:
        // The game waits here for the sprite to finish its animation sequence.
        break;
    case STATE_FADE_OUT_TO_GBA_SEND:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gUnknown_2031F40->state = STATE_WAIT_FADE_OUT_TO_GBA_SEND;
        break;
    case STATE_WAIT_FADE_OUT_TO_GBA_SEND:
        if (!gPaletteFade.active)
        {
            SetTradeSequenceBgGpuRegs(4);
            FillWindowPixelBuffer(0, PIXEL_FILL(15));
            CopyWindowToVram(0, COPYWIN_FULL);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_FADE_IN_TO_GBA_SEND:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_IN_TO_GBA_SEND:
        if (!gPaletteFade.active)
            gUnknown_2031F40->state = STATE_GBA_ZOOM_OUT;
        break;
    case STATE_GBA_ZOOM_OUT:
        if (gUnknown_2031F40->gbaScale > 0x100)
        {
            gUnknown_2031F40->gbaScale -= 0x34;
        }
        else
        {
            SetTradeSequenceBgGpuRegs(1);
            gUnknown_2031F40->gbaScale = 0x80;
            gUnknown_2031F40->state = STATE_GBA_FLASH_SEND_WIRELESS;
            gUnknown_2031F40->timer = 0;
        }
        gUnknown_2031F40->sXY = 0x8000 / gUnknown_2031F40->gbaScale;
        break;
    case STATE_GBA_FLASH_SEND_WIRELESS:
        if (++gUnknown_2031F40->timer > 20)
        {
            SetTradeSequenceBgGpuRegs(3);
            gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D0D0, 120, 80, 0);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_GBA_STOP_FLASH_SEND_WIRELESS:
        if (gSprites[gUnknown_2031F40->connectionSpriteId2].animEnded)
        {
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 |
                                         BLDCNT_TGT1_OBJ |
                                         BLDCNT_EFFECT_BLEND |
                                         BLDCNT_TGT2_BG2);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 4));

            // Start wireless signal effect
            CreateTask(Task_AnimateWirelessSignal, 5);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_WAIT_WIRELESS_SIGNAL_SEND:
        if (!FuncIsActiveTask(Task_AnimateWirelessSignal))
            gUnknown_2031F40->state = STATE_PAN_AWAY_GBA;
        break;
    case STATE_PAN_AWAY_GBA:
        if (--gUnknown_2031F40->bg1vofs == 316)
            gUnknown_2031F40->state++;
        break;
    case STATE_CREATE_LINK_MON_LEAVING:
        gUnknown_2031F40->connectionSpriteId1 = CreateSprite(&gUnknown_830CFCC, 120, 80, 3);
        gSprites[gUnknown_2031F40->connectionSpriteId1].callback = SpriteCB_LinkMonGlowWireless;
        gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D00C, 120, 80, 0);
        StartSpriteAnim(&gSprites[gUnknown_2031F40->connectionSpriteId2], ANIM_LINKMON_SMALL);
        gUnknown_2031F40->state++;
        break;
    case STATE_LINK_MON_TRAVEL_OUT:
        if ((gUnknown_2031F40->bg1vofs -= 3) == 166)
            gUnknown_2031F40->state = STATE_LINK_MON_TRAVEL_OFFSCREEN;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_OBJ_ON);
        break;
    case STATE_LINK_MON_TRAVEL_OFFSCREEN:
        gSprites[gUnknown_2031F40->connectionSpriteId1].y -= 2;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y -= 2;
        if (gSprites[gUnknown_2031F40->connectionSpriteId1].y < -8)
            gUnknown_2031F40->state = STATE_FADE_OUT_TO_CROSSING;
        break;
    case STATE_FADE_OUT_TO_CROSSING:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
        gUnknown_2031F40->state = STATE_WAIT_FADE_OUT_TO_CROSSING;
        break;
    case STATE_WAIT_FADE_OUT_TO_CROSSING:
        if (!gPaletteFade.active)
        {
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId1]);
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
            SetTradeSequenceBgGpuRegs(2);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_FADE_IN_TO_CROSSING:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        gUnknown_2031F40->connectionSpriteId1 = CreateSprite(&gUnknown_830D00C, 111, 170, 0);
        gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D00C, 129, -10, 0);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_IN_TO_CROSSING:
        if (!gPaletteFade.active)
        {
            PlaySE(SE_WARP_OUT);
            gUnknown_2031F40->state++;
        }
        gSprites[gUnknown_2031F40->connectionSpriteId1].y2 -= 3;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y2 += 3;
        break;
    case STATE_CROSSING_LINK_MONS_ENTER:
        gSprites[gUnknown_2031F40->connectionSpriteId1].y2 -= 3;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y2 += 3;
        if (gSprites[gUnknown_2031F40->connectionSpriteId1].y2 <= -90)
        {
            gSprites[gUnknown_2031F40->connectionSpriteId1].data[1] = 1;
            gSprites[gUnknown_2031F40->connectionSpriteId2].data[1] = 1;
            gUnknown_2031F40->state++;
            CreateTask(Task_OpenCenterWhiteColumn, 5);
        }
        break;
    case STATE_CROSSING_BLEND_WHITE_1:
        BlendPalettes(0x8, 16, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        break;
    case STATE_CROSSING_BLEND_WHITE_2:
        BlendPalettes(0x8, 16, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        break;
    case STATE_CROSSING_BLEND_WHITE_3:
        BlendPalettes(0x8, 16, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        break;
    case STATE_CROSSING_CREATE_MON_PICS:
        if (!IsMonSpriteNotFlipped(gUnknown_2031F40->monSpecies[TRADE_PLAYER]))
        {
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].affineAnims = gUnknown_830D110;
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
            CalcCenterToCornerVec(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]], SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), ST_OAM_AFFINE_DOUBLE);
            StartSpriteAffineAnim(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]], 0);
        }
        else
        {
            StartSpriteAffineAnim(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]], 0);
        }
        StartSpriteAffineAnim(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]], 0);
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].x = 40;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].x = 200;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y = 192;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].y = -32;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].invisible = FALSE;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].invisible = FALSE;
        gUnknown_2031F40->state++;
        break;
    case STATE_CROSSING_MON_PICS_MOVE:
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 -= 3;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].y2 += 3;
        if (gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 < -DISPLAY_HEIGHT
         && gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 >= -DISPLAY_HEIGHT - 3)
        {
            PlaySE(SE_WARP_IN);
        }
        if (gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].y2 < -222)
        {
            gSprites[gUnknown_2031F40->connectionSpriteId1].data[1] = 0;
            gSprites[gUnknown_2031F40->connectionSpriteId2].data[1] = 0;
            gUnknown_2031F40->state++;
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]].invisible = TRUE;
            gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].invisible = TRUE;
            CreateTask(Task_CloseCenterWhiteColumn, 5);
        }
        break;
    case STATE_CROSSING_LINK_MONS_EXIT:
        gSprites[gUnknown_2031F40->connectionSpriteId1].y2 -= 3;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y2 += 3;
        if (gSprites[gUnknown_2031F40->connectionSpriteId1].y2 <= -222)
        {
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
            gUnknown_2031F40->state++;
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId1]);
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
        }
        break;
    case STATE_CREATE_LINK_MON_ARRIVING:
        if (!gPaletteFade.active)
        {
            gUnknown_2031F40->state++;
            SetTradeSequenceBgGpuRegs(1);
            gUnknown_2031F40->bg1vofs = 166;
            SetTradeSequenceBgGpuRegs(3);
            gUnknown_2031F40->bg2vofs = 412;
            gUnknown_2031F40->connectionSpriteId1 = CreateSprite(&gUnknown_830CFCC, 120, -20, 3);
            gSprites[gUnknown_2031F40->connectionSpriteId1].callback = SpriteCB_LinkMonGlowWireless;
            gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D00C, 120, -20, 0);
            StartSpriteAnim(&gSprites[gUnknown_2031F40->connectionSpriteId2], ANIM_LINKMON_SMALL);
        }
        break;
    case STATE_FADE_OUT_TO_GBA_RECV:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_OUT_TO_GBA_RECV:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_OBJ_ON);
        if (!gPaletteFade.active)
            gUnknown_2031F40->state++;
        break;
    case STATE_LINK_MON_TRAVEL_IN:
        gSprites[gUnknown_2031F40->connectionSpriteId1].y2 += 4;
        gSprites[gUnknown_2031F40->connectionSpriteId2].y2 += 4;
        if (gSprites[gUnknown_2031F40->connectionSpriteId1].y2 + gSprites[gUnknown_2031F40->connectionSpriteId1].y == 64)
        {
            gUnknown_2031F40->state = STATE_PAN_TO_GBA_WIRELESS;
            gUnknown_2031F40->timer = 0;
        }
        break;
    case STATE_PAN_TO_GBA_WIRELESS:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG1_ON |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        gUnknown_2031F40->bg1vofs += 3;
        gUnknown_2031F40->bg2vofs += 3;
        if (++gUnknown_2031F40->timer == 10)
        {
            u8 taskId = CreateTask(Task_AnimateWirelessSignal, 5);
            gTasks[taskId].tSignalComingBack = TRUE;
        }
        if (gUnknown_2031F40->bg1vofs > 316)
        {
            gUnknown_2031F40->bg1vofs = 316;
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_DESTROY_LINK_MON_WIRELESS:
        DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId1]);
        DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
        gUnknown_2031F40->state++;
        gUnknown_2031F40->timer = 0;
        break;
    case STATE_WAIT_WIRELESS_SIGNAL_RECV:
        if (!FuncIsActiveTask(Task_AnimateWirelessSignal))
        {
            gUnknown_2031F40->state = STATE_LINK_MON_ARRIVED_DELAY;
            gUnknown_2031F40->timer = 0;
        }
        break;
    case STATE_LINK_MON_ARRIVED_DELAY:
        if (++gUnknown_2031F40->timer == 10)
            gUnknown_2031F40->state++;
        break;
    case STATE_MOVE_GBA_TO_CENTER:
        if (++gUnknown_2031F40->bg1vofs > 348)
        {
            gUnknown_2031F40->bg1vofs = 348;
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_GBA_FLASH_RECV:
        gUnknown_2031F40->connectionSpriteId2 = CreateSprite(&gUnknown_830D0B8, 120, 80, 0);
        gUnknown_2031F40->state = STATE_GBA_STOP_FLASH_RECV;
        break;
    case STATE_GBA_STOP_FLASH_RECV:
        if (gSprites[gUnknown_2031F40->connectionSpriteId2].animEnded)
        {
            DestroySprite(&gSprites[gUnknown_2031F40->connectionSpriteId2]);
            SetTradeSequenceBgGpuRegs(6);
            gUnknown_2031F40->state++;
            PlaySE(SE_M_SAND_ATTACK);
        }
        break;
    case STATE_GBA_ZOOM_IN:
        if (gUnknown_2031F40->gbaScale < 0x400)
        {
            gUnknown_2031F40->gbaScale += 0x34;
        }
        else
        {
            gUnknown_2031F40->gbaScale = 0x400;
            gUnknown_2031F40->state++;
        }
        gUnknown_2031F40->sXY = 0x8000 / gUnknown_2031F40->gbaScale;
        break;
    case STATE_FADE_OUT_TO_NEW_MON:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gUnknown_2031F40->state = STATE_WAIT_FADE_OUT_TO_NEW_MON;
        break;
    case STATE_WAIT_FADE_OUT_TO_NEW_MON:
        if (!gPaletteFade.active)
        {
            SetTradeSequenceBgGpuRegs(5);
            SetTradeSequenceBgGpuRegs(7);
            gPaletteFade.bufferTransferDisabled = TRUE;
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_FADE_IN_TO_NEW_MON:
        gPaletteFade.bufferTransferDisabled = FALSE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_IN_TO_NEW_MON:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        if (!gPaletteFade.active)
            gUnknown_2031F40->state++;
        break;
    case STATE_POKEBALL_ARRIVE:
        gUnknown_2031F40->bouncingPokeballSpriteId = CreateSprite(&gUnknown_830CF6C, 120, -8, 0);
        gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].data[3] = 74;
        gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].callback = SpriteCB_BouncingPokeballArrive;
        StartSpriteAnim(&gSprites[gUnknown_2031F40->bouncingPokeballSpriteId], 1);
        StartSpriteAffineAnim(&gSprites[gUnknown_2031F40->bouncingPokeballSpriteId], 2);
        BlendPalettes(1 << (16 + gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].oam.paletteNum), 16, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        gUnknown_2031F40->timer = 0;
        break;
    case STATE_FADE_POKEBALL_TO_NORMAL:
        BeginNormalPaletteFade(1 << (16 + gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].oam.paletteNum), 1, 16, 0, RGB_WHITEALPHA);
        gUnknown_2031F40->state++;
        break;
    case STATE_POKEBALL_ARRIVE_WAIT:
        if (gSprites[gUnknown_2031F40->bouncingPokeballSpriteId].callback == SpriteCallbackDummy)
        {
            HandleLoadSpecialPokePic_2(&gMonFrontPicTable[gUnknown_2031F40->monSpecies[TRADE_PARTNER]],
                                        gMonSpritesGfxPtr->sprites.ptr[B_POSITION_OPPONENT_RIGHT],
                                        gUnknown_2031F40->monSpecies[TRADE_PARTNER],
                                        gUnknown_2031F40->monPersonalities[TRADE_PARTNER]);
            gUnknown_2031F40->state++;
        }
        break;
    case STATE_SHOW_NEW_MON:
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].x = 120;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].y = gMonFrontPicCoords[gUnknown_2031F40->monSpecies[TRADE_PARTNER]].y_offset + 60;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].x2 = 0;
        gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].y2 = 0;
        StartSpriteAnim(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]], 0);
        CreatePokeballSpriteToReleaseMon(gUnknown_2031F40->monSpriteIds[TRADE_PARTNER], gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]].oam.paletteNum, 120, 84, 2, 1, 20, PALETTES_BG | (0xF << 16), gUnknown_2031F40->monSpecies[TRADE_PARTNER]);
        FreeSpriteOamMatrix(&gSprites[gUnknown_2031F40->bouncingPokeballSpriteId]);
        DestroySprite(&gSprites[gUnknown_2031F40->bouncingPokeballSpriteId]);
        gUnknown_2031F40->state++;
        break;
    case STATE_NEW_MON_MSG:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                      DISPCNT_OBJ_1D_MAP |
                                      DISPCNT_BG0_ON |
                                      DISPCNT_BG2_ON |
                                      DISPCNT_OBJ_ON);
        StringExpandPlaceholders(gStringVar4, gUnknown_830D258);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        gUnknown_2031F40->state = STATE_DELAY_FOR_MON_ANIM;
        gUnknown_2031F40->timer = 0;
        break;
    case STATE_DELAY_FOR_MON_ANIM:
        if (++gUnknown_2031F40->timer > 60)
        {
            gUnknown_2031F40->state = STATE_WAIT_FOR_MON_CRY;
            gUnknown_2031F40->timer = 0;
        }
        break;
    case STATE_WAIT_FOR_MON_CRY:
        if (IsCryFinished())
            gUnknown_2031F40->state = STATE_TAKE_CARE_OF_MON;
        break;
    case STATE_TAKE_CARE_OF_MON:
        if (++gUnknown_2031F40->timer == 10)
            PlayFanfare(MUS_EVOLVED);

        if (gUnknown_2031F40->timer == 250)
        {
            gUnknown_2031F40->state++;
            StringExpandPlaceholders(gStringVar4, gUnknown_830D26A);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            gUnknown_2031F40->timer = 0;
        }
        break;
    case STATE_AFTER_NEW_MON_DELAY:
        if (++gUnknown_2031F40->timer == 60)
            gUnknown_2031F40->state++;
        break;
    case STATE_CHECK_RIBBONS:
        CheckPartnersMonForRibbons();
        gUnknown_2031F40->state++;
        break;
    case STATE_END_LINK_TRADE:
        if (gUnknown_2031F40->isLinkTrade)
            return TRUE;
        else if (JOY_NEW(A_BUTTON))
            gUnknown_2031F40->state++;
        break;
    case STATE_TRY_EVOLUTION: // Only if in-game trade, link trades use CB2_TryLinkTradeEvolution
        TradeMons(gSpecialVar_0x8005, 0);
        gCB2_AfterEvolution = CB2_InGameTradeAnim;
        evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], EVO_MODE_TRADE, ITEM_NONE);
        if (evoTarget != SPECIES_NONE)
            TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, gUnknown_2031F40->monSpriteIds[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
        gUnknown_2031F40->state++;
        break;
    case STATE_FADE_OUT_END:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gUnknown_2031F40->state++;
        break;
    case STATE_WAIT_FADE_OUT_END:
        if (!gPaletteFade.active)
        {
            PlayNewMapMusic(gUnknown_2031F40->cachedMapMusic);
            if (gUnknown_2031F40)
            {
                FreeAllWindowBuffers();
                Free(GetBgTilemapBuffer(3));
                Free(GetBgTilemapBuffer(1));
                Free(GetBgTilemapBuffer(0));
                FreeMonSpritesGfx();
                FREE_AND_SET_NULL(gUnknown_2031F40);
            }
            SetMainCallback2(CB2_ReturnToField);
            BufferInGameTradeMonName();
        }
        break;
    }
    return FALSE;
}

static void CB2_TryLinkTradeEvolution(void)
{
    u16 evoTarget;
    switch (gMain.state)
    {
    case 0:
        gMain.state = 4;
        gSoftResetDisabled = TRUE;
        break;
    case 4:
        gCB2_AfterEvolution = CB2_SaveAndEndTrade;
        evoTarget = GetEvolutionTargetSpecies(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], EVO_MODE_TRADE, ITEM_NONE);
        if (evoTarget != SPECIES_NONE)
            TradeEvolutionScene(&gPlayerParty[gSelectedTradeMonPositions[TRADE_PLAYER]], evoTarget, gUnknown_2031F40->monSpriteIds[TRADE_PARTNER], gSelectedTradeMonPositions[TRADE_PLAYER]);
        else if (IsWirelessTrade())
            SetMainCallback2(CB2_SaveAndEndWirelessTrade);
        else
            SetMainCallback2(CB2_SaveAndEndTrade);
        gSelectedTradeMonPositions[TRADE_PLAYER] = 255;
        break;
    }
    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void HandleLinkDataReceive(void)
{
    u8 recvStatus;
    TradeGetMultiplayerId(); // no effect call, ret val ignored
    recvStatus = GetBlockReceivedStatus();
    if (recvStatus & (1 << 0))
    {
        if (gBlockRecvBuffer[0][0] == LINKCMD_CONFIRM_FINISH_TRADE)
            SetMainCallback2(CB2_TryLinkTradeEvolution);

        if (gBlockRecvBuffer[0][0] == LINKCMD_READY_FINISH_TRADE)
            gUnknown_2031F40->playerFinishStatus = STATUS_READY;

        ResetBlockReceivedFlag(0);
    }
    if (recvStatus & (1 << 1))
    {
        if (gBlockRecvBuffer[1][0] == LINKCMD_READY_FINISH_TRADE)
            gUnknown_2031F40->partnerFinishStatus = STATUS_READY;

        ResetBlockReceivedFlag(1);
    }
}

static void SpriteCB_BouncingPokeball(struct Sprite *sprite)
{
    sprite->y += sprite->data[0] / 10;
    sprite->data[5] += sprite->data[1];
    sprite->x = sprite->data[5] / 10;
    if (sprite->y > 0x4c)
    {
        sprite->y = 0x4c;
        sprite->data[0] = -(sprite->data[0] * sprite->data[2]) / 100;
        sprite->data[3] ++;
    }
    if (sprite->x == 0x78)
        sprite->data[1] = 0;
    sprite->data[0] += sprite->data[4];
    if (sprite->data[3] == 4)
    {
        sprite->data[7] = 1;
        sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_BouncingPokeballDepart(struct Sprite *sprite)
{
    sprite->y2 += gUnknown_830D2A4[sprite->data[0]];
    if (sprite->data[0] == 22)
        PlaySE(SE_BALL_BOUNCE_1);
    if (++sprite->data[0] == 44)
    {
        PlaySE(SE_M_MEGA_KICK);
        sprite->callback = SpriteCB_BouncingPokeballDepartEnd;
        sprite->data[0] = 0;
        BeginNormalPaletteFade(1 << (16 + sprite->oam.paletteNum), -1, 0, 16, RGB_WHITEALPHA);
    }
}

static void SpriteCB_BouncingPokeballDepartEnd(struct Sprite *sprite)
{
    if (sprite->data[1] == 20)
        StartSpriteAffineAnim(sprite, 1);
    if (++sprite->data[1] > 20)
    {
        sprite->y2 -= gUnknown_830D2A4[sprite->data[0]];
        sprite->data[0]++;
        if (sprite->data[0] == 23)
        {
            DestroySprite(sprite);
            gUnknown_2031F40->state = 14; // STATE_FADE_OUT_TO_GBA_SEND
        }
    }
}

static void SpriteCB_BouncingPokeballArrive(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        if ((sprite->y += 4) > sprite->data[3])
        {
            sprite->data[2] ++;
            sprite->data[0] = 0x16;
            PlaySE(SE_BALL_BOUNCE_1);
        }
    }
    else
    {
        if (sprite->data[0] == 0x42)
            PlaySE(SE_BALL_BOUNCE_2);
        if (sprite->data[0] == 0x5c)
            PlaySE(SE_BALL_BOUNCE_3);
        if (sprite->data[0] == 0x6b)
            PlaySE(SE_BALL_BOUNCE_4);
        sprite->y2 += gUnknown_830D2A4[sprite->data[0]];
        if (++sprite->data[0] == 0x6c)
            sprite->callback = SpriteCallbackDummy;
    }
}

u16 GetInGameTradeSpeciesInfo(void)
{
    const struct InGameTrade *inGameTrade = &gUnknown_830D114[gSpecialVar_0x8004];
    StringCopy(gStringVar1, gSpeciesNames[inGameTrade->requestedSpecies]);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
    return inGameTrade->requestedSpecies;
}

static void BufferInGameTradeMonName(void)
{
    u8 name[32];
    const struct InGameTrade *inGameTrade = &gUnknown_830D114[gSpecialVar_0x8004];
    GetMonData3(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_NICKNAME, name);
    StringCopy10(gStringVar1, name);
    StringCopy(gStringVar2, gSpeciesNames[inGameTrade->species]);
}

static void CreateInGameTradePokemonInternal(u8 whichPlayerMon, u8 whichInGameTrade)
{
    const struct InGameTrade *inGameTrade = &gUnknown_830D114[whichInGameTrade];
    u8 level = GetMonData3(&gPlayerParty[whichPlayerMon], MON_DATA_LEVEL);

    struct Mail mail;
    metloc_u8_t metLocation = METLOC_IN_GAME_TRADE;
    u8 mailNum;
    struct Pokemon *pokemon = &gEnemyParty[0];

    CreateMon(pokemon, inGameTrade->species, level, USE_RANDOM_IVS, TRUE, inGameTrade->personality, OT_ID_PRESET, inGameTrade->otId);

    SetMonData(pokemon, MON_DATA_HP_IV, &inGameTrade->ivs[0]);
    SetMonData(pokemon, MON_DATA_ATK_IV, &inGameTrade->ivs[1]);
    SetMonData(pokemon, MON_DATA_DEF_IV, &inGameTrade->ivs[2]);
    SetMonData(pokemon, MON_DATA_SPEED_IV, &inGameTrade->ivs[3]);
    SetMonData(pokemon, MON_DATA_SPATK_IV, &inGameTrade->ivs[4]);
    SetMonData(pokemon, MON_DATA_SPDEF_IV, &inGameTrade->ivs[5]);
    SetMonData(pokemon, MON_DATA_NICKNAME, inGameTrade->nickname);
    SetMonData(pokemon, MON_DATA_OT_NAME, inGameTrade->otName);
    SetMonData(pokemon, MON_DATA_OT_GENDER, &inGameTrade->otGender);
    SetMonData(pokemon, MON_DATA_ABILITY_NUM, &inGameTrade->abilityNum);
    SetMonData(pokemon, MON_DATA_BEAUTY, &inGameTrade->conditions[1]);
    SetMonData(pokemon, MON_DATA_CUTE, &inGameTrade->conditions[2]);
    SetMonData(pokemon, MON_DATA_COOL, &inGameTrade->conditions[0]);
    SetMonData(pokemon, MON_DATA_SMART, &inGameTrade->conditions[3]);
    SetMonData(pokemon, MON_DATA_TOUGH, &inGameTrade->conditions[4]);
    SetMonData(pokemon, MON_DATA_SHEEN, &inGameTrade->sheen);
    SetMonData(pokemon, MON_DATA_MET_LOCATION, &metLocation);

    mailNum = 0;
    if (inGameTrade->heldItem != ITEM_NONE)
    {
        u8 isMail = ItemIsMail(inGameTrade->heldItem);
        if (isMail)
        {
            GetInGameTradeMail(&mail, inGameTrade);
            gTradeMail[0] = mail;
            SetMonData(pokemon, MON_DATA_MAIL, &mailNum);
            SetMonData(pokemon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
        else
        {
            SetMonData(pokemon, MON_DATA_HELD_ITEM, &inGameTrade->heldItem);
        }
    }
    CalculateMonStats(&gEnemyParty[0]);
}

static void GetInGameTradeMail(struct Mail *mail, const struct InGameTrade *trade)
{
    s32 i;

    for (i = 0; i < MAIL_WORDS_COUNT; i++)
        mail->words[i] = gUnknown_830D204[trade->mailNum][i];

    StringCopy(mail->playerName, trade->otName);

    mail->trainerId[0] = trade->otId >> 24;
    mail->trainerId[1] = trade->otId >> 16;
    mail->trainerId[2] = trade->otId >> 8;
    mail->trainerId[3] = trade->otId;
    mail->species = trade->species;
    mail->itemId = trade->heldItem;
}

u16 GetTradeSpecies(void)
{
    if (GetMonData3(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_IS_EGG))
        return SPECIES_NONE;
    return GetMonData3(&gPlayerParty[gSpecialVar_0x8005], MON_DATA_SPECIES);
}

void CreateInGameTradePokemon(void)
{
    CreateInGameTradePokemonInternal(gSpecialVar_0x8005, gSpecialVar_0x8004);
}

static void CB2_UpdateLinkTrade(void)
{
    if (DoTradeAnim() == TRUE)
    {
        DestroySprite(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PLAYER]]);
        FreeSpriteOamMatrix(&gSprites[gUnknown_2031F40->monSpriteIds[TRADE_PARTNER]]);
        TradeMons(gSelectedTradeMonPositions[TRADE_PLAYER], gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE);
        if (!IsWirelessTrade())
        {
            gUnknown_2031F40->linkData[0] = LINKCMD_READY_FINISH_TRADE;
            gUnknown_2031F40->scheduleLinkTransfer = 1;
        }
        SetMainCallback2(CB2_WaitTradeComplete);
    }
    HandleLinkDataSend();
    HandleLinkDataReceive();
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CB2_WaitTradeComplete(void)
{
    u8 mpId = TradeGetMultiplayerId();
    if (IsWirelessTrade())
    {
        SetMainCallback2(CB2_TryLinkTradeEvolution);
    }
    else
    {
        HandleLinkDataReceive();
        // JP reads both finish-status bytes as one u16; 0x0101 = both STATUS_READY.
        if (mpId == 0 && *(u16 *)&gUnknown_2031F40->playerFinishStatus == 0x0101)
        {
            gUnknown_2031F40->linkData[0] = LINKCMD_CONFIRM_FINISH_TRADE;
            SendBlock(BitmaskAllOtherLinkPlayers(), gUnknown_2031F40->linkData, sizeof(gUnknown_2031F40->linkData));
            gUnknown_2031F40->playerFinishStatus = STATUS_CANCEL;
            gUnknown_2031F40->partnerFinishStatus = STATUS_CANCEL;
        }
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CB2_SaveAndEndTrade(void)
{
    switch (gMain.state)
    {
    case 0:
        gMain.state++;
        StringExpandPlaceholders(gStringVar4, gUnknown_8595430);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        break;
    case 1:
        SetTradeLinkStandbyCallback(0);
        gMain.state = 100;
        gUnknown_2031F40->timer = 0;
        break;
    case 100:
        if (++gUnknown_2031F40->timer > 180)
        {
            gMain.state = 101;
            gUnknown_2031F40->timer = 0;
        }
        if (_IsLinkTaskFinished())
            gMain.state = 2;
        break;
    case 101:
        if (_IsLinkTaskFinished())
            gMain.state = 2;
        break;
    case 2:
        gMain.state = 50;
        StringExpandPlaceholders(gStringVar4, gText_SavingDontTurnOffPower);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        break;
    case 50:
        if (!InUnionRoom())
            IncrementGameStat(GAME_STAT_POKEMON_TRADES);
        if (gWirelessCommType)
            MysteryGift_TryIncrementStat(CARD_STAT_NUM_TRADES, gLinkPlayers[GetMultiplayerId() ^ 1].trainerId);

        SetContinueGameWarpStatusToDynamicWarp();
        LinkFullSave_Init();
        gMain.state++;
        gUnknown_2031F40->timer = 0;
        break;
    case 51:
        if (++gUnknown_2031F40->timer == 5)
            gMain.state++;
        break;
    case 52:
        if (LinkFullSave_WriteSector())
        {
            ClearContinueGameWarpStatus();
            gMain.state = 4;
        }
        else
        {
            gUnknown_2031F40->timer = 0;
            gMain.state = 51;
        }
        break;
    case 4:
        LinkFullSave_ReplaceLastSector();
        gMain.state = 40;
        gUnknown_2031F40->timer = 0;
        break;
    case 40:
        if (++gUnknown_2031F40->timer > 50)
        {
            if (GetMultiplayerId() == 0)
                gUnknown_2031F40->timer = Random() % 30;
            else
                gUnknown_2031F40->timer = 0;
            gMain.state = 41;
        }
        break;
    case 41:
        if (gUnknown_2031F40->timer == 0)
        {
            SetTradeLinkStandbyCallback(1);
            gMain.state = 42;
        }
        else
        {
            gUnknown_2031F40->timer--;
        }
        break;
    case 42:
        if (_IsLinkTaskFinished())
        {
            LinkFullSave_SetLastSectorSignature();
            gMain.state = 5;
        }
        break;
    case 5:
        if (++gUnknown_2031F40->timer > 60)
        {
            gMain.state++;
            SetTradeLinkStandbyCallback(2);
        }
        break;
    case 6:
        if (_IsLinkTaskFinished())
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gMain.state++;
        }
        break;
    case 7:
        if (!gPaletteFade.active)
        {
            FadeOutBGMTemporarily(3);
            gMain.state++;
        }
        break;
    case 8:
        if (IsBGMStopped() == TRUE)
        {
            if (gWirelessCommType && gMain.savedCallback == CB2_StartCreateTradeMenu)
                SetTradeLinkStandbyCallback(3);
            else
                SetCloseLinkCallback();
            gMain.state++;
        }
        break;
    case 9:
        if (gWirelessCommType && gMain.savedCallback == CB2_StartCreateTradeMenu)
        {
            if (_IsLinkTaskFinished())
            {
                gSoftResetDisabled = FALSE;
                SetMainCallback2(CB2_FreeTradeAnim);
            }
        }
        else if (!gReceivedRemoteLinkPlayers)
        {
            gSoftResetDisabled = FALSE;
            SetMainCallback2(CB2_FreeTradeAnim);
        }
        break;
    }
    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void CB2_FreeTradeAnim(void)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        Free(GetBgTilemapBuffer(3));
        Free(GetBgTilemapBuffer(1));
        Free(GetBgTilemapBuffer(0));
        FreeMonSpritesGfx();
        FREE_AND_SET_NULL(gUnknown_2031F40);
        if (gWirelessCommType)
            DestroyWirelessStatusIndicatorSprite();
        SetMainCallback2(gMain.savedCallback);
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void DoInGameTradeScene(void)
{
    LockPlayerFieldControls();
    CreateTask(Task_InGameTrade, 10);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}

static void Task_InGameTrade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_InGameTrade);
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        DestroyTask(taskId);
    }
}

static void CheckPartnersMonForRibbons(void)
{
    u8 i;
    u8 numRibbons = 0;
    for (i = 0; i < (MON_DATA_UNUSED_RIBBONS - MON_DATA_CHAMPION_RIBBON); i++)
        numRibbons += GetMonData3(&gEnemyParty[gSelectedTradeMonPositions[TRADE_PARTNER] % PARTY_SIZE], MON_DATA_CHAMPION_RIBBON + i);

    if (numRibbons != 0)
        FlagSet(FLAG_SYS_RIBBON_GET);
}

void LoadTradeAnimGfx(void)
{
    TradeAnimInit_LoadGfx();
}

void DrawTextOnTradeWindow(u8 windowId, const u8 *str, u8 speed)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(15));
    gUnknown_2031F40->textColors[0] = TEXT_DYNAMIC_COLOR_6;
    gUnknown_2031F40->textColors[1] = TEXT_COLOR_WHITE;
    gUnknown_2031F40->textColors[2] = TEXT_COLOR_GREEN;
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, 0, 2, 0, 0, gUnknown_2031F40->textColors, speed, str);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Task_AnimateWirelessSignal(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 paletteIdx = gUnknown_830D310[data[0]][0] * 16;
    if (!data[2])
    {
        if (paletteIdx == 256)
            LoadPalette(gUnknown_830C0E4, 0x30, 0x20);
        else
            LoadPalette(&gUnknown_830BCE4[paletteIdx], 0x30, 0x20);
    }
    else
    {
        if (paletteIdx == 256)
            LoadPalette(gUnknown_830C0E4, 0x30, 0x20);
        else
            LoadPalette(&gUnknown_830BEE4[paletteIdx], 0x30, 0x20);
    }

    if (gUnknown_830D310[data[0]][0] == 0 && data[1] == 0)
        PlaySE(SE_M_HEAL_BELL);

    if (data[1] == gUnknown_830D310[data[0]][1])
    {
        data[0]++;
        data[1] = 0;
        if (gUnknown_830D310[data[0]][1] == 0xFF)
            DestroyTask(taskId);
    }
    else
    {
        data[1]++;
    }
}

static void Task_OpenCenterWhiteColumn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        gUnknown_2031F40->wirelessWinLeft = gUnknown_2031F40->wirelessWinRight = 0x78;
        gUnknown_2031F40->wirelessWinTop = 0;
        gUnknown_2031F40->wirelessWinBottom = 0xA0;
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        SetGpuReg(REG_OFFSET_WINOUT, 0x10);
        SetGpuReg(REG_OFFSET_WININ, 0x13);
    }
    SetGpuReg(REG_OFFSET_WIN0H, gUnknown_2031F40->wirelessWinRight | (gUnknown_2031F40->wirelessWinLeft << 8));
    SetGpuReg(REG_OFFSET_WIN0V, gUnknown_2031F40->wirelessWinBottom | (gUnknown_2031F40->wirelessWinTop << 8));
    data[0]++;
    gUnknown_2031F40->wirelessWinLeft -= 5;
    gUnknown_2031F40->wirelessWinRight += 5;
    if (gUnknown_2031F40->wirelessWinLeft <= 0x4F)
        DestroyTask(taskId);
}

static void Task_CloseCenterWhiteColumn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        gUnknown_2031F40->wirelessWinLeft = 0x50;
        gUnknown_2031F40->wirelessWinRight = 0xA0;
        SetGpuReg(REG_OFFSET_WINOUT, 0x10);
        SetGpuReg(REG_OFFSET_WININ, 0x13);
    }

    SetGpuReg(REG_OFFSET_WIN0H, gUnknown_2031F40->wirelessWinRight | (gUnknown_2031F40->wirelessWinLeft << 8));
    SetGpuReg(REG_OFFSET_WIN0V, gUnknown_2031F40->wirelessWinBottom | (gUnknown_2031F40->wirelessWinTop << 8));

    if (gUnknown_2031F40->wirelessWinLeft != 0x78)
    {
        data[0]++;
        gUnknown_2031F40->wirelessWinLeft += 5;
        gUnknown_2031F40->wirelessWinRight -= 5;

        if (gUnknown_2031F40->wirelessWinLeft > 0x73)
            BlendPalettes(0x8, 0, RGB_WHITEALPHA);
    }
    else
    {
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        DestroyTask(taskId);
    }
}

static void CB2_SaveAndEndWirelessTrade(void)
{
    switch (gMain.state)
    {
    case 0:
        gMain.state = 1;
        StringExpandPlaceholders(gStringVar4, gUnknown_8595430);
        DrawTextOnTradeWindow(0, gStringVar4, 0);
        break;
    case 1:
        SetTradeLinkStandbyCallback(0);
        gMain.state = 2;
        gUnknown_2031F40->timer = 0;
        break;
    case 2:
        if (_IsLinkTaskFinished())
        {
            gMain.state = 3;
            StringExpandPlaceholders(gStringVar4, gText_SavingDontTurnOffPower);
            DrawTextOnTradeWindow(0, gStringVar4, 0);
            IncrementGameStat(GAME_STAT_POKEMON_TRADES);
            LinkFullSave_Init();
            gUnknown_2031F40->timer = 0;
        }
        break;
    case 3:
        if (++gUnknown_2031F40->timer == 5)
            gMain.state = 4;
        break;
    case 4:
        if (LinkFullSave_WriteSector())
        {
            gMain.state = 5;
        }
        else
        {
            gUnknown_2031F40->timer = 0;
            gMain.state = 3;
        }
        break;
    case 5:
        LinkFullSave_ReplaceLastSector();
        gMain.state = 6;
        gUnknown_2031F40->timer = 0;
        break;
    case 6:
        if (++gUnknown_2031F40->timer > 10)
        {
            if (GetMultiplayerId() == 0)
                gUnknown_2031F40->timer = Random() % 30;
            else
                gUnknown_2031F40->timer = 0;
            gMain.state = 7;
        }
        break;
    case 7:
        if (gUnknown_2031F40->timer == 0)
        {
            SetTradeLinkStandbyCallback(1);
            gMain.state = 8;
        }
        else
        {
            gUnknown_2031F40->timer--;
        }
        break;
    case 8:
        if (_IsLinkTaskFinished())
        {
            LinkFullSave_SetLastSectorSignature();
            gMain.state = 9;
        }
        break;
    case 9:
        if (++gUnknown_2031F40->timer > 60)
        {
            gMain.state++;
            SetTradeLinkStandbyCallback(2);
        }
        break;
    case 10:
        if (_IsLinkTaskFinished())
        {
            FadeOutBGMTemporarily(3);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gMain.state = 11;
        }
        break;
    case 11:
        if (!gPaletteFade.active && IsBGMStopped() == TRUE)
        {
            SetTradeLinkStandbyCallback(3);
            gMain.state = 12;
        }
        break;
    case 12:
        if (_IsLinkTaskFinished())
        {
            gSoftResetDisabled = FALSE;
            SetMainCallback2(CB2_FreeTradeAnim);
        }
        break;
    }
    if (!HasLinkErrorOccurred())
        RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}
