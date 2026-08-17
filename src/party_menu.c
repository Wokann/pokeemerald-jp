#include "global.h"
#include "party_menu.h"
#include "pokemon_icon.h"
#include "bg.h"
#include "battle_interface.h"
#include "data.h"
#include "battle.h"
#include "constants/field_effects.h"
#include "constants/field_weather.h"
#include "decompress.h"
#include "field_effect.h"
#include "field_weather.h"
#include "malloc.h"
#include "palette.h"

extern const u16 sTMHMMoves[];
extern const u8 sSlotTilemap_WideEmpty[];

#define PARTY_PAL_SELECTED     (1 << 0)
#define PARTY_PAL_FAINTED      (1 << 1)
#define PARTY_PAL_TO_SWITCH    (1 << 2)
#define PARTY_PAL_MULTI_ALT    (1 << 3)
#define PARTY_PAL_SWITCHING    (1 << 4)
#define PARTY_PAL_TO_SOFTBOIL  (1 << 5)
#define PARTY_PAL_NO_MON       (1 << 6)
#define PARTY_PAL_UNUSED       (1 << 7)

#define MENU_DIR_DOWN     1
#define MENU_DIR_UP      -1
#define MENU_DIR_RIGHT    2
#define MENU_DIR_LEFT    -2
#define MENU_B_PRESSED   -1
#define MENU_NOTHING_CHOSEN -2

#define SUMMARY_MODE_NORMAL      0
#define SUMMARY_MODE_LOCK_MOVES  1

extern const u8 sPartyBoxPalOffsets1[];
extern const u8 sPartyBoxPalOffsets2[];
extern const u8 sPartyBoxNoMonPalOffsets[];
extern const u8 sPartyBoxEmptySlotPalIds1[];
extern const u8 sPartyBoxMultiPalIds1[];
extern const u8 sPartyBoxFaintedPalIds1[];
extern const u8 sPartyBoxCurrSelectionPalIds1[];
extern const u8 sPartyBoxCurrSelectionMultiPalIds[];
extern const u8 sPartyBoxCurrSelectionFaintedPalIds[];
extern const u8 sPartyBoxSelectedForActionPalIds1[];
extern const u8 sPartyBoxEmptySlotPalIds2[];
extern const u8 sPartyBoxMultiPalIds2[];
extern const u8 sPartyBoxFaintedPalIds2[];
extern const u8 sPartyBoxCurrSelectionPalIds2[];
extern const u8 sPartyBoxSelectedForActionPalIds2[];
extern const u8 sPartyBoxNoMonPalIds[];
extern const u8 sFontColorTable[][3];
extern const u8 sGenderPalOffsets[];
extern const u8 sGenderMalePalIds[];
extern const u8 sGenderFemalePalIds[];
extern const u8 sHPBarPalOffsets[];
extern const u8 sHPBarGreenPalIds[];
extern const u8 sHPBarYellowPalIds[];
extern const u8 sHPBarRedPalIds[];
extern const u8 *const sDescriptionStringTable[];
extern const struct WindowTemplate sDefaultPartyMsgWindowTemplate;
extern const struct WindowTemplate sItemGiveTakeWindowTemplate;
extern const struct WindowTemplate sMailReadTakeWindowTemplate;
extern const struct WindowTemplate sMoveSelectWindowTemplate;
extern const struct WindowTemplate sPartyMenuYesNoWindowTemplate;
extern const struct WindowTemplate sLevelUpStatsWindowTemplate;
extern const u8 gUnknown_85C97BD[]; // JP text block; +0x4F0 = gText_PkmnNotHolding
extern const u16 sFieldMoves[];
extern const u32 sConfirmButton_Tilemap[];
extern const u32 sCancelButton_Tilemap[];
extern const u8 sPartyMenuActionCounts[];
extern const u8 *const sPartyMenuActions[];
extern void CreateYesNoMenuAtPos(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
extern const struct WindowTemplate sDoWhatWithMonMsgWindowTemplate;
extern const struct WindowTemplate sWhichMoveMsgWindowTemplate;
extern const struct WindowTemplate sDoWhatWithItemMsgWindowTemplate;
extern const struct WindowTemplate sDoWhatWithMailMsgWindowTemplate;
extern const struct WindowTemplate sDoWhatWithMailMsgWindowTemplate;
extern const struct WindowTemplate sAlreadyHoldingOneMsgWindowTemplate;
extern const u8 *const sActionStringTable[];
extern void DrawStdFrameWithCustomTileAndPalette(u8 windowId, bool8 copyToVram, u16 baseTileNum, u8 paletteNum);
extern void SetWindowTemplateFields(struct WindowTemplate *template, u8 bg, u8 left, u8 top, u8 width, u8 height, u8 paletteNum, u16 baseBlock);
extern void AddTextPrinterParameterized4(u8 windowId, u8 fontId, u8 left, u8 top, u8 letterSpacing, u8 lineSpacing, const u8 *color, s8 speed, const u8 *str);
// JP: 0x0819844C = US static InitMenu (name kept to avoid clash with storage InitMenu)
void sub_0819844C(u8 windowId, u8 fontId, u8 left, u8 top, u8 cursorHeight, u8 numChoices, u8 initialCursorPos, bool8 muteAPress);
extern const struct
{
    const u8 *text;
    TaskFunc func;
} sCursorOptions[];
#include "constants/items.h"
#include "constants/contest.h"
#include "item_use.h"
#include "event_data.h"
#include "item_menu.h"
#include "constants/party_menu.h"
#include "constants/pokemon.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trade.h"
#include "link_rfu.h"
#include "main.h"
#include "text.h"
extern bool16 AddTextPrinterParameterized2(u8 windowId, u8 fontId, const u8 *str, u8 speed, TextPrinterCallback callback, u8 fgColor, u8 bgColor, u8 shadowColor);
extern u8 GetPlayerTextSpeedDelay(void);
extern void SetBgTilemapPalette(u8 bgId, u8 left, u8 top, u8 width, u8 height, u8 palette);
#include "window.h"
#include "menu_helpers.h"
#include "start_menu.h"
#include "battle_pike.h"
#include "mail.h"
#include "sprite.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
extern void AddTextPrinterParameterized3(u8 windowId, u8 fontId, u8 left, u8 top, const u8 *color, s8 speed, const u8 *str);
#include "task.h"
#include "trade.h"

static void Task_ExitPartyMenu(u8 taskId);
static bool8 ShowPartyMenu(void);
static void CB2_InitPartyMenu(void);
void reset_brm(void);
static void SetPartyMonsAllowedInMinigame(void);
static void InitPartyMenuWindows(u8 layout);
static void CreateCancelConfirmWindows(bool8 chooseHalf);
static bool16 IsMonAllowedInPokemonJump(struct Pokemon *mon);
static bool16 IsMonAllowedInDodrioBerryPicking(struct Pokemon *mon);
static bool8 IsMonAllowedInMinigame(u8 slot);
static void TryEnterMonForMinigame(u8 taskId, u8 slot);
static void CancelParticipationPrompt(u8 taskId);
static void Task_CancelParticipationYesNo(u8 taskId);
static void Task_HandleCancelParticipationYesNoInput(u8 taskId);
static u8 CanMonLearnTMTutor(struct Pokemon *mon, u16 item, u8 tutor);
static u16 GetTutorMove(u8 tutor);
static bool8 CanLearnTutorMove(u16 species, u8 tutor);
bool32 IsSpeciesAllowedInPokemonJump(u16 species);
extern const u32 sTutorLearnsets[];
extern const struct WindowTemplate sSinglePartyMenuWindowTemplate[];
extern const struct WindowTemplate sDoublePartyMenuWindowTemplate[];
extern const struct WindowTemplate sMultiPartyMenuWindowTemplate[];
extern const struct WindowTemplate sShowcaseMultiPartyMenuWindowTemplate[];
extern const struct WindowTemplate sCancelButtonWindowTemplate[];
extern const struct WindowTemplate sMultiCancelButtonWindowTemplate[];
extern const struct WindowTemplate sConfirmButtonWindowTemplate[];
extern const u8 gMenuText_Confirm[];
extern const u16 gStandardMenuPalette[];
static void Task_PrintAndWaitForText(u8 taskId);
__attribute__((naked)) void Task_FieldMoveWaitForFade(u8 taskId);
static void MoveCursorToConfirm(void);
u8 GetMaxBattleEntries(void);
static void Task_HandleSelectionMenuInput(u8 taskId);
static void CB2_ShowPokemonSummaryScreen(void);
static void CB2_ReturnToPartyMenuFromSummaryScreen(void);
static void CB2_SelectBagItemToGive(void);
static void CB2_GiveHoldItem(void);
static void Task_GiveHoldItem(u8 taskId);
static void Task_SwitchHoldItemsPrompt(u8 taskId);
static void Task_SwitchItemsYesNo(u8 taskId);
static void Task_HandleSwitchItemsYesNoInput(u8 taskId);
static void Task_WriteMailToGiveMonAfterText(u8 taskId);
static void CB2_WriteMailToGiveMon(void);
static void CB2_ReturnToPartyMenuFromWritingMail(void);
static void Task_DisplayGaveMailFromPartyMessage(u8 taskId);
void DoEasyChatScreen(u8 type, u16 *words, MainCallback exitCallback, u8 displayedPersonType);
void sub_081C47A0(u8 location, MainCallback callback); // GoToBattlePyramidBagMenu
extern u16 sPartyMenuItemId;
u8 CurrentBattlePyramidLocation(void);
#define POCKETS_COUNT       5
#define PYRAMIDBAG_LOC_PARTY 2 // JP enum order differs from US
#define PYRAMID_LOCATION_NONE 0
static void CB2_ReadHeldMail(void);
static void CB2_ReturnToPartyMenuFromReadingMail(void);
static void Task_SendMailToPCYesNo(u8 taskId);
static void Task_HandleSendMailToPCYesNoInput(u8 taskId);
static void Task_LoseMailMessageYesNo(u8 taskId);
static void Task_HandleLoseMailMessageYesNoInput(u8 taskId);
static void CursorCb_Cancel2(u8 taskId);
__attribute__((naked)) bool8 TrySwitchInPokemon(void);
__attribute__((naked)) void Task_SpinTradeYesNo(u8 taskId);
static void Task_UpdateHeldItemSprite(u8 taskId);
static void Task_TossHeldItemYesNo(u8 taskId);
static void Task_HandleTossHeldItemYesNoInput(u8 taskId);
static void Task_TossHeldItem(u8 taskId);
static void CursorCb_TakeItem(u8 taskId);
static void CursorCb_Toss(u8 taskId);

enum {
    ACTIONS_NONE,
    ACTIONS_SWITCH,
    ACTIONS_SHIFT,
    ACTIONS_SEND_OUT,
    ACTIONS_ENTER,
    ACTIONS_NO_ENTRY,
    ACTIONS_STORE,
    ACTIONS_SUMMARY_ONLY,
    ACTIONS_ITEM,
    ACTIONS_MAIL,
    ACTIONS_REGISTER,
    ACTIONS_TRADE,
    ACTIONS_SPIN_TRADE,
    ACTIONS_TAKEITEM_TOSS,
};

enum {
    MENU_SUMMARY,
    MENU_SWITCH,
    MENU_CANCEL1,
    MENU_ITEM,
    MENU_GIVE,
    MENU_TAKE_ITEM,
    MENU_MAIL,
    MENU_TAKE_MAIL,
    MENU_READ,
    MENU_CANCEL2,
    MENU_SHIFT,
    MENU_SEND_OUT,
    MENU_ENTER,
    MENU_NO_ENTRY,
    MENU_STORE,
    MENU_REGISTER,
    MENU_TRADE1,
    MENU_TRADE2,
    MENU_TOSS,
    MENU_FIELD_MOVES
};

enum {
    WIN_MSG = PARTY_SIZE,
};

enum {
    FIELD_MOVE_CUT,
    FIELD_MOVE_FLASH,
    FIELD_MOVE_ROCK_SMASH,
    FIELD_MOVE_STRENGTH,
    FIELD_MOVE_SURF,
    FIELD_MOVE_FLY,
    FIELD_MOVE_DIVE,
    FIELD_MOVE_WATERFALL,
    FIELD_MOVE_TELEPORT,
    FIELD_MOVE_DIG,
    FIELD_MOVE_SECRET_POWER,
    FIELD_MOVE_MILK_DRINK,
    FIELD_MOVE_SOFT_BOILED,
    FIELD_MOVE_SWEET_SCENT,
    FIELD_MOVES_COUNT
};

enum {
    CAN_LEARN_MOVE,
    CANNOT_LEARN_MOVE,
    ALREADY_KNOWS_MOVE,
    CANNOT_LEARN_MOVE_IS_EGG
};

struct PartyMenuInternal
{
    TaskFunc task;
    MainCallback exitCallback;
    u32 chooseHalf:1;
    u32 lastSelectedSlot:3;  // Used to return to same slot when going left/right bewtween columns
    u32 spriteIdConfirmPokeball:7;
    u32 spriteIdCancelPokeball:7;
    u32 messageId:14;
    u8 windowId[3];
    u8 actions[8];
    u8 numActions;
    u16 palBuffer[BG_PLTT_SIZE / sizeof(u16)];
    s16 data[16];
};

struct PartyMenuBoxInfoRects
{
    void (*blitFunc)(u8, u8, u8, u8, u8, bool8);
    u8 dimensions[24];
    u8 descTextLeft;
    u8 descTextTop;
    u8 descTextWidth;
    u8 descTextHeight;
};

struct PartyMenuBox
{
    const struct PartyMenuBoxInfoRects *infoRects;
    const u8 *spriteCoords;
    u8 windowId;
    u8 monSpriteId;
    u8 itemSpriteId;
    u8 pokeballSpriteId;
    u8 statusSpriteId;
};

static void DisplayPartyPokemonLevel(u8, struct PartyMenuBox *);
bool8 ShouldUseChooseMonText(void);
static void Task_ClosePartyMenuAndSetCB2(u8 taskId);
static u8 GetPartyMenuActionsTypeInBattle(struct Pokemon *mon);
static u8 GetPartySlotEntryStatus(s8 slotId);
static void DisplayPartyPokemonDataToTeachMove(u8 slot, u16 item, u8 tutor);
static void ShowOrHideHeldItemSprite(u16 item, struct PartyMenuBox *menuBox);

extern const struct PartyMenuBoxInfoRects gUnknown_85E0F9C[];
extern const u8 gUnknown_85E0FBC[][48];

static void HandleChooseMonSelection(u8 taskId, s8 *slotPtr);
static bool8 IsSelectedMonNotEgg(u8 *slotPtr);
static void HandleChooseMonCancel(u8 taskId, s8 *slotPtr);
static bool8 DisplayCancelChooseMonYesNo(u8 taskId);
static void Task_CancelChooseMonYesNo(u8 taskId);
static void Task_HandleCancelChooseMonYesNoInput(u8 taskId);
static u16 PartyMenuButtonHandler(s8 *slotPtr);
static void UpdateCurrentPartySelection(s8 *slotPtr, s8 movementDir);
static void UpdatePartySelectionSingleLayout(s8 *slotPtr, s8 movementDir);
static void UpdatePartySelectionDoubleLayout(s8 *slotPtr, s8 movementDir);
static s8 GetNewSlotDoubleLayout(s8 slotId, s8 movementDir);
static void PartyMenuRemoveWindow(u8 *windowId);
static void UpdatePartyMonHeldItemSprite(struct Pokemon *mon, struct PartyMenuBox *menuBox);
s8 Menu_ProcessInputNoWrapClearOnChoose(void);
static void Task_ReturnToChooseMonAfterText(u8 taskId);
void TryEnterMonForMinigame(u8 taskId, u8 slotId); // TryEnterMonForMinigame
void CancelParticipationPrompt(u8 taskId); // CancelParticipationPrompt
void Task_TryCreateSelectionWindow(u8 taskId); // Task_TryCreateSelectionWindow
void SwitchSelectedMons(u8 taskId); // SwitchSelectedMons
static void FinishTwoMonAction(u8 taskId);
void sub_081B6434(u8 taskId); // Task_ClosePartyMenuAfterText
void sub_081B7AF0(u8 taskId); // TryTutorSelectedMon
void sub_081B7C4C(u8 taskId); // TryGiveItemOrMailToSelectedMon
void sub_081B8114(u8 taskId); // TryGiveMailToSelectedMon
void sub_081B81F8(void); // ClearSelectedPartyOrder
u8 *sub_081B855C(void); // GetFacilityCancelString
void sub_081B8DE0(void); // CB2_SetUpExitToBattleScreen
void sub_081B2FDC(void); // PartyMenuDisplayYesNoMenu
void CopyItemName(u16 itemId, u8 *dst);
bool8 AddBagItem(u16 itemId, u16 count);
static bool8 AllocPartyMenuBg(void);
static bool8 AllocPartyMenuBgGfx(void);
static void ExitPartyMenu(void);
static void InitPartyMenuBoxes(u8 layout);
static bool8 RenderPartyMenuBoxes(void);
static bool8 CreatePartyMonSpritesLoop(void);
static void CreateCancelConfirmPokeballSprites(void);
static void LoadPartyMenuPokeballGfx(void);
static void LoadPartyMenuAilmentGfx(void);
void ScanlineEffect_Stop(void);
extern struct PartyMenuInternal *sPartyMenuInternal;
s8 Menu_ProcessInputNoWrapAround_other(void);
s8 ProcessMenuInput_other(void);
u8 Menu_GetCursorPos(void);
void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void));
void pokemon_change_order(void); // UpdatePartyToBattleOrder
void sub_08199954(u8 bgId, u16 *dest, u8 left, u8 top, u8 width, u8 height); // CopyToBufferFromBgTilemap
static void SlidePartyMenuBoxOneStep(u8 taskId);
static void Task_SlideSelectedSlotsOffscreen(u8 taskId);
static void Task_SlideSelectedSlotsOnscreen(u8 taskId);
static void SwitchPartyMon(void);
extern u16 *sSlot1TilemapBuffer;
extern u16 *sSlot2TilemapBuffer;
extern u8 gLastViewedMonIndex;
extern const u8 sSlotTilemap_Main[];
extern const u8 sSlotTilemap_MainNoHP[];
extern const u8 sSlotTilemap_Wide[];
extern const u8 sSlotTilemap_WideNoHP[];

static void InitPartyMenu(u8 menuType, u8 layout, u8 partyAction, bool8 keepCursorPos, u8 messageId, TaskFunc task, MainCallback callback)
{
    u16 i;

    reset_brm();
    sPartyMenuInternal = Alloc(sizeof(struct PartyMenuInternal));
    if (sPartyMenuInternal == NULL)
    {
        SetMainCallback2(callback);
    }
    else
    {
        gPartyMenu.menuType = menuType;
        gPartyMenu.exitCallback = callback;
        gPartyMenu.action = partyAction;
        sPartyMenuInternal->messageId = messageId;
        sPartyMenuInternal->task = task;
        sPartyMenuInternal->exitCallback = NULL;
        sPartyMenuInternal->lastSelectedSlot = 0;
        sPartyMenuInternal->spriteIdConfirmPokeball = 0x7F;
        sPartyMenuInternal->spriteIdCancelPokeball = 0x7F;

        if (menuType == PARTY_MENU_TYPE_CHOOSE_HALF)
            sPartyMenuInternal->chooseHalf = TRUE;
        else
            sPartyMenuInternal->chooseHalf = FALSE;

        if (layout != KEEP_PARTY_LAYOUT)
            gPartyMenu.layout = layout;

        for (i = 0; i < ARRAY_COUNT(sPartyMenuInternal->data); i++)
            sPartyMenuInternal->data[i] = 0;
        for (i = 0; i < ARRAY_COUNT(sPartyMenuInternal->windowId); i++)
            sPartyMenuInternal->windowId[i] = WINDOW_NONE;

        if (!keepCursorPos)
            gPartyMenu.slotId = 0;
        else if (gPartyMenu.slotId > PARTY_SIZE - 1 || GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_SPECIES) == SPECIES_NONE)
            gPartyMenu.slotId = 0;

        gTextFlags.autoScroll = 0;
        CalculatePlayerPartyCount();
        SetMainCallback2(CB2_InitPartyMenu);
    }
}

static void CB2_UpdatePartyMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_PartyMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_InitPartyMenu(void)
{
    while (TRUE)
    {
        if (MenuHelpers_ShouldWaitForLinkRecv() == TRUE || ShowPartyMenu() == TRUE || MenuHelpers_IsLinkActive() == TRUE)
            return;
    }
}

static bool8 ShowPartyMenu(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        if (!MenuHelpers_IsLinkActive())
            ResetTasks();
        gMain.state++;
        break;
    case 6:
        SetPartyMonsAllowedInMinigame();
        gMain.state++;
        break;
    case 7:
        if (!AllocPartyMenuBg())
        {
            ExitPartyMenu();
            return TRUE;
        }
        else
        {
            sPartyMenuInternal->data[0] = 0;
            gMain.state++;
        }
        break;
    case 8:
        if (AllocPartyMenuBgGfx())
            gMain.state++;
        break;
    case 9:
        InitPartyMenuWindows(gPartyMenu.layout);
        gMain.state++;
        break;
    case 10:
        InitPartyMenuBoxes(gPartyMenu.layout);
        sPartyMenuInternal->data[0] = 0;
        gMain.state++;
        break;
    case 11:
        LoadHeldItemIcons();
        gMain.state++;
        break;
    case 12:
        LoadPartyMenuPokeballGfx();
        gMain.state++;
        break;
    case 13:
        LoadPartyMenuAilmentGfx();
        gMain.state++;
        break;
    case 14:
        LoadMonIconPalettes();
        gMain.state++;
        break;
    case 15:
        if (CreatePartyMonSpritesLoop())
        {
            sPartyMenuInternal->data[0] = 0;
            gMain.state++;
        }
        break;
    case 16:
        if (RenderPartyMenuBoxes())
        {
            sPartyMenuInternal->data[0] = 0;
            gMain.state++;
        }
        break;
    case 17:
        CreateCancelConfirmPokeballSprites();
        gMain.state++;
        break;
    case 18:
        CreateCancelConfirmWindows(sPartyMenuInternal->chooseHalf);
        gMain.state++;
        break;
    case 19:
        gMain.state++;
        break;
    case 20:
        CreateTask(sPartyMenuInternal->task, 0);
        DisplayPartyMenuStdMessage(sPartyMenuInternal->messageId);
        gMain.state++;
        break;
    case 21:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    case 22:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlankCB_PartyMenu);
        SetMainCallback2(CB2_UpdatePartyMenu);
        return TRUE;
    }
    return FALSE;
}

static void ExitPartyMenu(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_ExitPartyMenu, 0);
    SetVBlankCallback(VBlankCB_PartyMenu);
    SetMainCallback2(CB2_UpdatePartyMenu);
}

static void Task_ExitPartyMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(gPartyMenu.exitCallback);
        FreePartyPointers();
        DestroyTask(taskId);
    }
}

extern struct PartyMenuInternal *sPartyMenuInternal;
extern void *sPartyBgTilemapBuffer;
extern void *sPartyBgGfxTilemap;
extern struct PartyMenuBox *sPartyMenuBoxes;

extern const u32 gUnknown_8D967A0[];
extern const u32 gUnknown_8D96B54[];
extern const u16 gUnknown_8D96A68[];

void reset_brm(void)
{
    sPartyMenuInternal = NULL;
    sPartyBgTilemapBuffer = NULL;
    sPartyMenuBoxes = NULL;
    sPartyBgGfxTilemap = NULL;
}

extern const struct BgTemplate gUnknown_85E0F70[];

static bool8 AllocPartyMenuBg(void)
{
    void **buf = &sPartyBgTilemapBuffer;
    *buf = Alloc(0x800);
    if (*buf == NULL)
        return FALSE;

    memset(*buf, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_85E0F70, 3);
    SetBgTilemapBuffer(1, *buf);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(1);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 AllocPartyMenuBgGfx(void)
{
    u32 sizeout;

    switch (sPartyMenuInternal->data[0])
    {
    case 0:
        sPartyBgGfxTilemap = malloc_and_decompress(gUnknown_8D967A0, &sizeout);
        LoadBgTiles(1, sPartyBgGfxTilemap, sizeout, 0);
        sPartyMenuInternal->data[0]++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            LZDecompressVram(gUnknown_8D96B54, sPartyBgTilemapBuffer);
            sPartyMenuInternal->data[0]++;
        }
        break;
    case 2:
        LoadCompressedPalette(gUnknown_8D96A68, BG_PLTT_ID(0), 11 * PLTT_SIZE_4BPP);
        CpuCopy16(gPlttBufferUnfaded, sPartyMenuInternal->palBuffer, 11 * PLTT_SIZE_4BPP);
        sPartyMenuInternal->data[0]++;
        break;
    case 3:
        PartyPaletteBufferCopy(4);
        sPartyMenuInternal->data[0]++;
        break;
    case 4:
        PartyPaletteBufferCopy(5);
        sPartyMenuInternal->data[0]++;
        break;
    case 5:
        PartyPaletteBufferCopy(6);
        sPartyMenuInternal->data[0]++;
        break;
    case 6:
        PartyPaletteBufferCopy(7);
        sPartyMenuInternal->data[0]++;
        break;
    case 7:
        PartyPaletteBufferCopy(8);
        sPartyMenuInternal->data[0]++;
        break;
    default:
        return TRUE;
    }
    return FALSE;
}

static void PartyPaletteBufferCopy(u8 palNum)
{
    u8 offset = PLTT_ID(palNum);
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(3)], &gPlttBufferUnfaded[offset], PLTT_SIZE_4BPP);
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(3)], &gPlttBufferFaded[offset], PLTT_SIZE_4BPP);
}

static void FreePartyPointers(void)
{
    if (sPartyMenuInternal)
        Free(sPartyMenuInternal);
    if (sPartyBgTilemapBuffer)
        Free(sPartyBgTilemapBuffer);
    if (sPartyBgGfxTilemap)
        Free(sPartyBgGfxTilemap);
    if (sPartyMenuBoxes)
        Free(sPartyMenuBoxes);
    FreeAllWindowBuffers();
}

static void InitPartyMenuBoxes(u8 layout)
{
    u8 i;

    sPartyMenuBoxes = Alloc(sizeof(struct PartyMenuBox[PARTY_SIZE]));

    for (i = 0; i < PARTY_SIZE; i++)
    {
        sPartyMenuBoxes[i].infoRects = &gUnknown_85E0F9C[0];
        sPartyMenuBoxes[i].spriteCoords = &gUnknown_85E0FBC[layout][i * 8];
        sPartyMenuBoxes[i].windowId = i;
        sPartyMenuBoxes[i].monSpriteId = SPRITE_NONE;
        sPartyMenuBoxes[i].itemSpriteId = SPRITE_NONE;
        sPartyMenuBoxes[i].pokeballSpriteId = SPRITE_NONE;
        sPartyMenuBoxes[i].statusSpriteId = SPRITE_NONE;
    }
    // The first party mon goes in the left column
    sPartyMenuBoxes[0].infoRects = &gUnknown_85E0F9C[-1];

    if (layout == PARTY_LAYOUT_MULTI_SHOWCASE)
        sPartyMenuBoxes[3].infoRects = &gUnknown_85E0F9C[-1];
    else if (layout != PARTY_LAYOUT_SINGLE)
        sPartyMenuBoxes[1].infoRects = &gUnknown_85E0F9C[-1];
}

static void RenderPartyMenuBox(u8 slot)
{
    if (gPartyMenu.menuType == PARTY_MENU_TYPE_MULTI_SHOWCASE && slot >= MULTI_PARTY_SIZE)
    {
        DisplayPartyPokemonDataForMultiBattle(slot);
        if (gMultiPartnerParty[slot - MULTI_PARTY_SIZE].species == SPECIES_NONE)
            LoadPartyBoxPalette(&sPartyMenuBoxes[slot], PARTY_PAL_NO_MON);
        else
            LoadPartyBoxPalette(&sPartyMenuBoxes[slot], PARTY_PAL_MULTI_ALT);
        CopyWindowToVram(sPartyMenuBoxes[slot].windowId, COPYWIN_GFX);
        PutWindowTilemap(sPartyMenuBoxes[slot].windowId);
        ScheduleBgCopyTilemapToVram(2);
    }
    else
    {
        if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) == SPECIES_NONE)
        {
            DrawEmptySlot(sPartyMenuBoxes[slot].windowId);
            LoadPartyBoxPalette(&sPartyMenuBoxes[slot], PARTY_PAL_NO_MON);
            CopyWindowToVram(sPartyMenuBoxes[slot].windowId, COPYWIN_GFX);
        }
        else
        {
            if (gPartyMenu.menuType == PARTY_MENU_TYPE_MOVE_RELEARNER)
                DisplayPartyPokemonDataForRelearner(slot);
            else if (gPartyMenu.menuType == PARTY_MENU_TYPE_CONTEST)
                DisplayPartyPokemonDataForContest(slot);
            else if (gPartyMenu.menuType == PARTY_MENU_TYPE_CHOOSE_HALF)
                DisplayPartyPokemonDataForChooseHalf(slot);
            else if (gPartyMenu.menuType == PARTY_MENU_TYPE_MINIGAME)
                DisplayPartyPokemonDataForWirelessMinigame(slot);
            else if (gPartyMenu.menuType == PARTY_MENU_TYPE_STORE_PYRAMID_HELD_ITEMS)
                DisplayPartyPokemonDataForBattlePyramidHeldItem(slot);
            else if (!(u8)DisplayPartyPokemonDataForMoveTutorOrEvolutionItem(slot))
                DisplayPartyPokemonData(slot);

            if (gPartyMenu.menuType == PARTY_MENU_TYPE_MULTI_SHOWCASE)
                AnimatePartySlot(slot, 0);
            else if (gPartyMenu.slotId == slot)
                AnimatePartySlot(slot, 1);
            else
                AnimatePartySlot(slot, 0);
        }
        PutWindowTilemap(sPartyMenuBoxes[slot].windowId);
        ScheduleBgCopyTilemapToVram(0);
    }
}

static void DisplayPartyPokemonData(u8 slot)
{
    if (GetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG))
    {
        sPartyMenuBoxes[slot].infoRects->blitFunc(sPartyMenuBoxes[slot].windowId, 0, 0, 0, 0, TRUE);
        DisplayPartyPokemonNickname(&gPlayerParty[slot], &sPartyMenuBoxes[slot], 0);
    }
    else
    {
        sPartyMenuBoxes[slot].infoRects->blitFunc(sPartyMenuBoxes[slot].windowId, 0, 0, 0, 0, FALSE);
        DisplayPartyPokemonNickname(&gPlayerParty[slot], &sPartyMenuBoxes[slot], 0);
        DisplayPartyPokemonLevelCheck(&gPlayerParty[slot], &sPartyMenuBoxes[slot], 0);
        DisplayPartyPokemonGenderNidoranCheck(&gPlayerParty[slot], &sPartyMenuBoxes[slot], 0);
        DisplayPartyPokemonHPCheck(&gPlayerParty[slot], &sPartyMenuBoxes[slot], 0);
        DisplayPartyPokemonMaxHPCheck(&gPlayerParty[slot], &sPartyMenuBoxes[slot], 0);
        DisplayPartyPokemonHPBarCheck(&gPlayerParty[slot], &sPartyMenuBoxes[slot]);
    }
}

static void DisplayPartyPokemonDescriptionData(u8 slot, u8 stringID)
{
    struct Pokemon *mon = &gPlayerParty[slot];

    sPartyMenuBoxes[slot].infoRects->blitFunc(sPartyMenuBoxes[slot].windowId, 0, 0, 0, 0, TRUE);
    DisplayPartyPokemonNickname(mon, &sPartyMenuBoxes[slot], 0);
    if (!GetMonData(mon, MON_DATA_IS_EGG))
    {
        DisplayPartyPokemonLevelCheck(mon, &sPartyMenuBoxes[slot], 0);
        DisplayPartyPokemonGenderNidoranCheck(mon, &sPartyMenuBoxes[slot], 0);
    }
    DisplayPartyPokemonDescriptionText(stringID, &sPartyMenuBoxes[slot], 0);
}

static void DisplayPartyPokemonDataForChooseHalf(u8 slot)
{
    u8 i;
    struct Pokemon *mon = &gPlayerParty[slot];
    u8 *order = gSelectedOrderFromParty;

    if (!(u8)GetBattleEntryEligibility(mon))
    {
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NOT_ABLE);
        return;
    }
    else
    {
        for (i = 0; i < GetMaxBattleEntries(); i++)
        {
            if (order[i] != 0 && (order[i] - 1) == slot)
            {
                DisplayPartyPokemonDescriptionData(slot, i + PARTYBOX_DESC_FIRST);
                return;
            }
        }
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_ABLE_3);
    }
}

static void DisplayPartyPokemonDataForContest(u8 slot)
{
    switch ((u8)GetContestEntryEligibility(&gPlayerParty[slot]))
    {
    case CANT_ENTER_CONTEST:
    case CANT_ENTER_CONTEST_EGG:
    case CANT_ENTER_CONTEST_FAINTED:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NOT_ABLE);
        break;
    case CAN_ENTER_CONTEST_EQUAL_RANK:
    case CAN_ENTER_CONTEST_HIGH_RANK:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_ABLE);
        break;
    }
}

static void DisplayPartyPokemonDataForRelearner(u8 slot)
{
    if ((u8)GetNumberOfRelearnableMoves(&gPlayerParty[slot]) == 0)
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NOT_ABLE_2);
    else
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_ABLE_2);
}

static void DisplayPartyPokemonDataForWirelessMinigame(u8 slot)
{
    if ((u8)IsMonAllowedInMinigame(slot) == TRUE)
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_ABLE);
    else
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NOT_ABLE);
}

static void DisplayPartyPokemonDataForBattlePyramidHeldItem(u8 slot)
{
    if (GetMonData(&gPlayerParty[slot], MON_DATA_HELD_ITEM))
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_HAVE);
    else
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_DONT_HAVE);
}

static bool8 DisplayPartyPokemonDataForMoveTutorOrEvolutionItem(u8 slot)
{
    struct Pokemon *currentPokemon = &gPlayerParty[slot];
    u16 item = gSpecialVar_ItemId;

    if (gPartyMenu.action == PARTY_ACTION_MOVE_TUTOR)
    {
        gSpecialVar_Result = FALSE;
        DisplayPartyPokemonDataToTeachMove(slot, 0, gSpecialVar_0x8005);
    }
    else
    {
        if (gPartyMenu.action != PARTY_ACTION_USE_ITEM)
            return FALSE;

        switch ((u8)CheckIfItemIsTMHMOrEvolutionStone(item))
        {
        default:
            return FALSE;
        case ITEM_IS_TM_HM:
            DisplayPartyPokemonDataToTeachMove(slot, item, 0);
            break;
        case ITEM_IS_EVOLUTION_STONE:
            if (!GetMonData(currentPokemon, MON_DATA_IS_EGG) && GetEvolutionTargetSpecies(currentPokemon, EVO_MODE_ITEM_CHECK, item) != SPECIES_NONE)
                return FALSE;
            DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NO_USE);
            break;
        }
    }
    return TRUE;
}

static void DisplayPartyPokemonDataToTeachMove(u8 slot, u16 item, u8 tutor)
{
    switch ((u8)CanMonLearnTMTutor(&gPlayerParty[slot], item, tutor))
    {
    case CANNOT_LEARN_MOVE:
    case CANNOT_LEARN_MOVE_IS_EGG:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_NOT_ABLE_2);
        break;
    case ALREADY_KNOWS_MOVE:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_LEARNED);
        break;
    default:
        DisplayPartyPokemonDescriptionData(slot, PARTYBOX_DESC_ABLE_2);
        break;
    }
}

static void DisplayPartyPokemonDataForMultiBattle(u8 slot)
{
    struct PartyMenuBox *menuBox = &sPartyMenuBoxes[slot];
    u8 actualSlot = slot - MULTI_PARTY_SIZE;

    if (gMultiPartnerParty[actualSlot].species == SPECIES_NONE)
    {
        DrawEmptySlot(menuBox->windowId);
    }
    else
    {
        menuBox->infoRects->blitFunc(menuBox->windowId, 0, 0, 0, 0, FALSE);
        StringCopy(gStringVar1, gMultiPartnerParty[actualSlot].nickname);
        StringGet_Nickname(gStringVar1);
        // JP: no ConvertInternationalPlayerName (US converts partner name here)
        DisplayPartyPokemonBarDetail(menuBox->windowId, gStringVar1, 0, menuBox->infoRects->dimensions);
        DisplayPartyPokemonLevel(gMultiPartnerParty[actualSlot].level, menuBox);
        DisplayPartyPokemonGender(gMultiPartnerParty[actualSlot].gender, gMultiPartnerParty[actualSlot].species, gMultiPartnerParty[actualSlot].nickname, menuBox);
        DisplayPartyPokemonHP(gMultiPartnerParty[actualSlot].hp, menuBox);
        DisplayPartyPokemonMaxHP(gMultiPartnerParty[actualSlot].maxhp, menuBox);
        DisplayPartyPokemonHPBar(gMultiPartnerParty[actualSlot].hp, gMultiPartnerParty[actualSlot].maxhp, menuBox);
    }
}

static bool8 RenderPartyMenuBoxes(void)
{
    RenderPartyMenuBox((u8)sPartyMenuInternal->data[0]);
    if (++sPartyMenuInternal->data[0] == PARTY_SIZE)
        return TRUE;
    else
        return FALSE;
}

static u8 *GetPartyMenuBgTile(u16 tileId)
{
    return (u8 *)sPartyBgGfxTilemap + (tileId << 5);
}

static void CreatePartyMonSprites(u8 slot)
{
    u8 actualSlot;

    if (gPartyMenu.menuType == PARTY_MENU_TYPE_MULTI_SHOWCASE && slot >= MULTI_PARTY_SIZE)
    {
        u8 status;
        actualSlot = slot - MULTI_PARTY_SIZE;

        if (gMultiPartnerParty[actualSlot].species != SPECIES_NONE)
        {
            CreatePartyMonIconSpriteParameterized(gMultiPartnerParty[actualSlot].species, gMultiPartnerParty[actualSlot].personality, &sPartyMenuBoxes[slot], 0, FALSE);
            CreatePartyMonHeldItemSpriteParameterized(gMultiPartnerParty[actualSlot].species, gMultiPartnerParty[actualSlot].heldItem, &sPartyMenuBoxes[slot]);
            CreatePartyMonPokeballSpriteParameterized(gMultiPartnerParty[actualSlot].species, &sPartyMenuBoxes[slot]);
            if (gMultiPartnerParty[actualSlot].hp == 0)
                status = AILMENT_FNT;
            else
                status = GetAilmentFromStatus(gMultiPartnerParty[actualSlot].status);
            CreatePartyMonStatusSpriteParameterized(gMultiPartnerParty[actualSlot].species, status, &sPartyMenuBoxes[slot]);
        }
    }
    else if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) != SPECIES_NONE)
    {
        CreatePartyMonIconSprite(&gPlayerParty[slot], &sPartyMenuBoxes[slot], slot);
        CreatePartyMonHeldItemSprite(&gPlayerParty[slot], &sPartyMenuBoxes[slot]);
        CreatePartyMonPokeballSprite(&gPlayerParty[slot], &sPartyMenuBoxes[slot]);
        CreatePartyMonStatusSprite(&gPlayerParty[slot], &sPartyMenuBoxes[slot]);
    }
}

static bool8 CreatePartyMonSpritesLoop(void)
{
    CreatePartyMonSprites(sPartyMenuInternal->data[0]);
    if (++sPartyMenuInternal->data[0] == PARTY_SIZE)
        return TRUE;
    else
        return FALSE;
}

static void CreateCancelConfirmPokeballSprites(void)
{
    if (gPartyMenu.menuType == PARTY_MENU_TYPE_MULTI_SHOWCASE)
    {
        // The showcase has no Cancel/Confirm buttons
        FillBgTilemapBufferRect(1, 14, 23, 17, 7, 2, 1);
    }
    else
    {
        if (sPartyMenuInternal->chooseHalf)
        {
            sPartyMenuInternal->spriteIdConfirmPokeball = (u8)CreateSmallPokeballButtonSprite(0xBF, 0x88);
            DrawCancelConfirmButtons();
            sPartyMenuInternal->spriteIdCancelPokeball = (u8)CreateSmallPokeballButtonSprite(0xBF, 0x98);
        }
        else
        {
            sPartyMenuInternal->spriteIdCancelPokeball = (u8)CreatePokeballButtonSprite(198, 148);
        }
        AnimatePartySlot(gPartyMenu.slotId, 1);
    }
}

void AnimatePartySlot(u8 slot, u8 animNum)
{
    u8 spriteId;

    switch (slot)
    {
    default:
        if (GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES) != SPECIES_NONE)
        {
            LoadPartyBoxPalette(&sPartyMenuBoxes[slot], (u8)GetPartyBoxPaletteFlags(slot, animNum));
            AnimateSelectedPartyIcon(sPartyMenuBoxes[slot].monSpriteId, animNum);
            PartyMenuStartSpriteAnim(sPartyMenuBoxes[slot].pokeballSpriteId, animNum);
        }
        return;
    case PARTY_SIZE: // Confirm
        if (animNum == 0)
            SetBgTilemapPalette(1, 23, 16, 7, 2, 1);
        else
            SetBgTilemapPalette(1, 23, 16, 7, 2, 2);
        spriteId = sPartyMenuInternal->spriteIdConfirmPokeball;
        break;
    case PARTY_SIZE + 1: // Cancel
        // The position of the Cancel button changes if Confirm is present
        if (!sPartyMenuInternal->chooseHalf)
        {
            if (animNum == 0)
                SetBgTilemapPalette(1, 23, 17, 7, 2, 1);
            else
                SetBgTilemapPalette(1, 23, 17, 7, 2, 2);
        }
        else if (animNum == 0)
        {
            SetBgTilemapPalette(1, 23, 18, 7, 2, 1);
        }
        else
        {
            SetBgTilemapPalette(1, 23, 18, 7, 2, 2);
        }
        spriteId = sPartyMenuInternal->spriteIdCancelPokeball;
        break;
    }
    PartyMenuStartSpriteAnim(spriteId, animNum);
    ScheduleBgCopyTilemapToVram(1);
}

static u8 GetPartyBoxPaletteFlags(u8 slot, u8 animNum)
{
    u8 palFlags = 0;

    if (animNum == 1)
        palFlags |= PARTY_PAL_SELECTED;
    if (GetMonData(&gPlayerParty[slot], MON_DATA_HP) == 0)
        palFlags |= PARTY_PAL_FAINTED;
    if ((u8)PartyBoxPal_ParnterOrDisqualifiedInArena(slot) == TRUE)
        palFlags |= PARTY_PAL_MULTI_ALT;
    if (gPartyMenu.action == PARTY_ACTION_SWITCHING)
        palFlags |= PARTY_PAL_SWITCHING;
    if (gPartyMenu.action == PARTY_ACTION_SWITCH)
    {
        if (slot == gPartyMenu.slotId || slot == gPartyMenu.slotId2)
            palFlags |= PARTY_PAL_TO_SWITCH;
    }
    if (gPartyMenu.action == PARTY_ACTION_SOFTBOILED && slot == gPartyMenu.slotId)
        palFlags |= PARTY_PAL_TO_SOFTBOIL;

    return palFlags;
}

static bool8 PartyBoxPal_ParnterOrDisqualifiedInArena(u8 slot)
{
    if (gPartyMenu.layout == PARTY_LAYOUT_MULTI && (slot == 1 || slot == 4 || slot == 5))
        return TRUE;

    if (slot < MULTI_PARTY_SIZE && (gBattleTypeFlags & BATTLE_TYPE_ARENA) && gMain.inBattle && (gBattleStruct->arenaLostPlayerMons >> (u8)GetPartyIdFromBattleSlot(slot) & 1))
        return TRUE;

    return FALSE;
}

static void DrawCancelConfirmButtons(void)
{
    CopyToBgTilemapBufferRect_ChangePalette(1, sConfirmButton_Tilemap, 23, 16, 7, 2, 17);
    CopyToBgTilemapBufferRect_ChangePalette(1, sCancelButton_Tilemap, 23, 18, 7, 2, 17);
    ScheduleBgCopyTilemapToVram(1);
}

bool8 IsMultiBattle(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_DOUBLE && gBattleTypeFlags & BATTLE_TYPE_TRAINER && gMain.inBattle)
        return TRUE;
    else
        return FALSE;
}

// JP-only: swaps two 0x64-byte blocks (used to exchange party slots)
void sub_081B0F58(void *a, void *b)
{
    void *tmp = Alloc(0x64);
    memcpy(tmp, a, 0x64);
    memcpy(a, b, 0x64);
    memcpy(b, tmp, 0x64);
    Free(tmp);
}

static void Task_ClosePartyMenu(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ClosePartyMenuAndSetCB2;
}

static void Task_ClosePartyMenuAndSetCB2(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gPartyMenu.menuType == PARTY_MENU_TYPE_IN_BATTLE)
            UpdatePartyToFieldOrder();

        if (sPartyMenuInternal->exitCallback != NULL)
            SetMainCallback2(sPartyMenuInternal->exitCallback);
        else
            SetMainCallback2(gPartyMenu.exitCallback);

        ResetSpriteData();
        FreePartyPointers();
        DestroyTask(taskId);
    }
}

u8 GetCursorSelectionMonId(void)
{
    return gPartyMenu.slotId;
}

u8 GetPartyMenuType(void)
{
    return gPartyMenu.menuType;
}

void Task_HandleChooseMonInput(u8 taskId)
{
    if (!gPaletteFade.active && MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        s8 *slotPtr = GetCurrentPartySlotPtr();

        switch (PartyMenuButtonHandler(slotPtr))
        {
        case A_BUTTON: // Selected mon
            HandleChooseMonSelection(taskId, slotPtr);
            break;
        case B_BUTTON: // Selected Cancel / pressed B
            HandleChooseMonCancel(taskId, slotPtr);
            break;
        case START_BUTTON:
            if (sPartyMenuInternal->chooseHalf)
            {
                PlaySE(SE_SELECT);
                MoveCursorToConfirm();
            }
            break;
        }
    }
}

static s8 *GetCurrentPartySlotPtr(void)
{
    if (gPartyMenu.action == PARTY_ACTION_SWITCH || gPartyMenu.action == PARTY_ACTION_SOFTBOILED)
        return &gPartyMenu.slotId2;
    else
        return &gPartyMenu.slotId;
}

static void HandleChooseMonSelection(u8 taskId, s8 *slotPtr)
{
    if (*slotPtr == PARTY_SIZE)
    {
        gPartyMenu.task(taskId);
    }
    else
    {
        switch (gPartyMenu.action)
        {
        case PARTY_ACTION_SOFTBOILED:
            if (IsSelectedMonNotEgg((u8 *)slotPtr))
            {
                PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
                Task_TryUseSoftboiledOnPartyMon(taskId);
            }
            break;
        case PARTY_ACTION_USE_ITEM:
            if (IsSelectedMonNotEgg((u8 *)slotPtr))
            {
                if (gPartyMenu.menuType == PARTY_MENU_TYPE_IN_BATTLE)
                    sPartyMenuInternal->exitCallback = sub_081B8DE0; // CB2_SetUpExitToBattleScreen
                PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
                gItemUseCB(taskId, sub_081B6434); // Task_ClosePartyMenuAfterText
            }
            break;
        case PARTY_ACTION_MOVE_TUTOR:
            if (IsSelectedMonNotEgg((u8 *)slotPtr))
            {
                PlaySE(SE_SELECT);
                PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
                sub_081B7AF0(taskId); // TryTutorSelectedMon
            }
            break;
        case PARTY_ACTION_GIVE_MAILBOX_MAIL:
            if (IsSelectedMonNotEgg((u8 *)slotPtr))
            {
                PlaySE(SE_SELECT);
                PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
                sub_081B8114(taskId); // TryGiveMailToSelectedMon
            }
            break;
        case PARTY_ACTION_GIVE_ITEM:
        case PARTY_ACTION_GIVE_PC_ITEM:
            if (IsSelectedMonNotEgg((u8 *)slotPtr))
            {
                PlaySE(SE_SELECT);
                PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
                sub_081B7C4C(taskId); // TryGiveItemOrMailToSelectedMon
            }
            break;
        case PARTY_ACTION_SWITCH:
            PlaySE(SE_SELECT);
            SwitchSelectedMons(taskId); // SwitchSelectedMons
            break;
        case PARTY_ACTION_CHOOSE_AND_CLOSE:
            PlaySE(SE_SELECT);
            Task_ClosePartyMenu(taskId);
            break;
        case PARTY_ACTION_MINIGAME:
            if (IsSelectedMonNotEgg((u8 *)slotPtr))
            {
                TryEnterMonForMinigame(taskId, (u8)*slotPtr); // TryEnterMonForMinigame
            }
            break;
        default:
        case PARTY_ACTION_ABILITY_PREVENTS:
        case PARTY_ACTION_SWITCHING:
            PlaySE(SE_SELECT);
            Task_TryCreateSelectionWindow(taskId); // Task_TryCreateSelectionWindow
            break;
        }
    }
}

static bool8 IsSelectedMonNotEgg(u8 *slotPtr)
{
    if (GetMonData(&gPlayerParty[*slotPtr], MON_DATA_IS_EGG) == TRUE)
    {
        PlaySE(SE_FAILURE);
        return FALSE;
    }
    return TRUE;
}

static void HandleChooseMonCancel(u8 taskId, s8 *slotPtr)
{
    switch (gPartyMenu.action)
    {
    case PARTY_ACTION_SEND_OUT:
        PlaySE(SE_FAILURE);
        break;
    case PARTY_ACTION_SWITCH:
    case PARTY_ACTION_SOFTBOILED:
        PlaySE(SE_SELECT);
        FinishTwoMonAction(taskId); // FinishTwoMonAction
        break;
    case PARTY_ACTION_MINIGAME:
        PlaySE(SE_SELECT);
        CancelParticipationPrompt(taskId); // CancelParticipationPrompt
        break;
    default:
        PlaySE(SE_SELECT);
        if (DisplayCancelChooseMonYesNo(taskId) != TRUE)
        {
            if (!MenuHelpers_IsLinkActive())
                gSpecialVar_0x8004 = PARTY_SIZE + 1;
            gPartyMenuUseExitCallback = FALSE;
            *slotPtr = PARTY_SIZE + 1;
            Task_ClosePartyMenu(taskId);
        }
        break;
    }
}

static bool8 DisplayCancelChooseMonYesNo(u8 taskId)
{
    const u8 *stringPtr = NULL;

    if (gPartyMenu.menuType == PARTY_MENU_TYPE_CONTEST)
        stringPtr = gUnknown_85C97BD + 0xA53; // gText_CancelParticipation
    else if (gPartyMenu.menuType == PARTY_MENU_TYPE_CHOOSE_HALF)
        stringPtr = sub_081B855C(); // GetFacilityCancelString

    if (stringPtr == NULL)
        return FALSE;

    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    StringExpandPlaceholders(gStringVar4, stringPtr);
    DisplayPartyMenuMessage(gStringVar4, TRUE);
    gTasks[taskId].func = Task_CancelChooseMonYesNo;
    return TRUE;
}

static void Task_CancelChooseMonYesNo(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        sub_081B2FDC(); // PartyMenuDisplayYesNoMenu
        gTasks[taskId].func = Task_HandleCancelChooseMonYesNoInput;
    }
}

static void Task_HandleCancelChooseMonYesNoInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        gPartyMenuUseExitCallback = FALSE;
        gPartyMenu.slotId = PARTY_SIZE + 1;
        sub_081B81F8(); // ClearSelectedPartyOrder
        Task_ClosePartyMenu(taskId);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1:
        Task_ReturnToChooseMonAfterText(taskId);
        break;
    }
}

static u16 PartyMenuButtonHandler(s8 *slotPtr)
{
    s8 movementDir;

    switch (gMain.newAndRepeatedKeys)
    {
    case DPAD_UP:
        movementDir = MENU_DIR_UP;
        break;
    case DPAD_DOWN:
        movementDir = MENU_DIR_DOWN;
        break;
    case DPAD_LEFT:
        movementDir = MENU_DIR_LEFT;
        break;
    case DPAD_RIGHT:
        movementDir = MENU_DIR_RIGHT;
        break;
    default:
        switch (GetLRKeysPressedAndHeld())
        {
        case MENU_L_PRESSED:
            movementDir = MENU_DIR_UP;
            break;
        case MENU_R_PRESSED:
            movementDir = MENU_DIR_DOWN;
            break;
        default:
            movementDir = 0;
            break;
        }
        break;
    }

    if (JOY_NEW(START_BUTTON))
        return START_BUTTON;

    if (movementDir)
    {
        UpdateCurrentPartySelection(slotPtr, movementDir);
        return 0;
    }

    // Pressed Cancel
    if (JOY_NEW(A_BUTTON) && *slotPtr == PARTY_SIZE + 1)
        return B_BUTTON;

    return JOY_NEW(A_BUTTON | B_BUTTON);
}

static void UpdateCurrentPartySelection(s8 *slotPtr, s8 movementDir)
{
    s8 newSlotId = *slotPtr;
    u8 layout = gPartyMenu.layout;

    if (layout == PARTY_LAYOUT_SINGLE)
        UpdatePartySelectionSingleLayout(slotPtr, movementDir);
    else
        UpdatePartySelectionDoubleLayout(slotPtr, movementDir);

    if (*slotPtr != newSlotId)
    {
        PlaySE(SE_SELECT);
        AnimatePartySlot(newSlotId, 0);
        AnimatePartySlot(*slotPtr, 1);
    }
}

static void UpdatePartySelectionSingleLayout(s8 *slotPtr, s8 movementDir)
{
    // PARTY_SIZE + 1 is Cancel, PARTY_SIZE is Confirm
    switch (movementDir)
    {
    case MENU_DIR_UP:
        if (*slotPtr == 0)
        {
            *slotPtr = PARTY_SIZE + 1;
        }
        else if (*slotPtr == PARTY_SIZE)
        {
            *slotPtr = gPlayerPartyCount - 1;
        }
        else if (*slotPtr == PARTY_SIZE + 1)
        {
            if (sPartyMenuInternal->chooseHalf)
                *slotPtr = PARTY_SIZE;
            else
                *slotPtr = gPlayerPartyCount - 1;
        }
        else
        {
            (*slotPtr)--;
        }
        break;
    case MENU_DIR_DOWN:
        if (*slotPtr == PARTY_SIZE + 1)
        {
            *slotPtr = 0;
        }
        else
        {
            if (*slotPtr == gPlayerPartyCount - 1)
            {
                if (sPartyMenuInternal->chooseHalf)
                    *slotPtr = PARTY_SIZE;
                else
                    *slotPtr = PARTY_SIZE + 1;
            }
            else
            {
                (*slotPtr)++;
            }
        }
        break;
    case MENU_DIR_RIGHT:
        if (gPlayerPartyCount != 1 && *slotPtr == 0)
        {
            if (sPartyMenuInternal->lastSelectedSlot == 0)
                *slotPtr = 1;
            else
                *slotPtr = sPartyMenuInternal->lastSelectedSlot;
        }
        break;
    case MENU_DIR_LEFT:
        if (*slotPtr != 0 && *slotPtr != PARTY_SIZE && *slotPtr != PARTY_SIZE + 1)
        {
            sPartyMenuInternal->lastSelectedSlot = *slotPtr;
            *slotPtr = 0;
        }
        break;
    }
}

static void UpdatePartySelectionDoubleLayout(s8 *slotPtr, s8 movementDir)
{
    // PARTY_SIZE + 1 is Cancel, PARTY_SIZE is Confirm
    // newSlot is used temporarily as a movement direction during its later assignment
    s8 newSlot = movementDir;

    switch (movementDir)
    {
    case MENU_DIR_UP:
        if (*slotPtr == 0)
        {
            *slotPtr = PARTY_SIZE + 1;
            break;
        }
        else if (*slotPtr == PARTY_SIZE)
        {
            *slotPtr = gPlayerPartyCount - 1;
            break;
        }
        else if (*slotPtr == PARTY_SIZE + 1)
        {
            if (sPartyMenuInternal->chooseHalf)
            {
                *slotPtr = PARTY_SIZE;
                break;
            }
            (*slotPtr)--;
        }
        newSlot = GetNewSlotDoubleLayout(*slotPtr, newSlot);
        if (newSlot != -1)
            *slotPtr = newSlot;
        break;
    case MENU_DIR_DOWN:
        if (*slotPtr == PARTY_SIZE)
        {
            *slotPtr = PARTY_SIZE + 1;
        }
        else if (*slotPtr == PARTY_SIZE + 1)
        {
            *slotPtr = 0;
        }
        else
        {
            newSlot = GetNewSlotDoubleLayout(*slotPtr, MENU_DIR_DOWN);
            if (newSlot == -1)
            {
                if (sPartyMenuInternal->chooseHalf)
                    *slotPtr = PARTY_SIZE;
                else
                    *slotPtr = PARTY_SIZE + 1;
            }
            else
            {
                *slotPtr = newSlot;
            }
        }
        break;
    case MENU_DIR_RIGHT:
        if (*slotPtr == 0)
        {
            if (sPartyMenuInternal->lastSelectedSlot == 3)
            {
                if (GetMonData(&gPlayerParty[3], MON_DATA_SPECIES) != SPECIES_NONE)
                    *slotPtr = 3;
            }
            else if (GetMonData(&gPlayerParty[2], MON_DATA_SPECIES) != SPECIES_NONE)
            {
                *slotPtr = 2;
            }
        }
        else if (*slotPtr == 1)
        {
            if (sPartyMenuInternal->lastSelectedSlot == 5)
            {
                if (GetMonData(&gPlayerParty[5], MON_DATA_SPECIES) != SPECIES_NONE)
                    *slotPtr = 5;
            }
            else if (GetMonData(&gPlayerParty[4], MON_DATA_SPECIES) != SPECIES_NONE)
            {
                *slotPtr = 4;
            }
        }
        break;
    case MENU_DIR_LEFT:
        if (*slotPtr == 2 || *slotPtr == 3)
        {
            sPartyMenuInternal->lastSelectedSlot = *slotPtr;
            *slotPtr = 0;
        }
        else if (*slotPtr == 4 || *slotPtr == 5)
        {
            sPartyMenuInternal->lastSelectedSlot = *slotPtr;
            *slotPtr = 1;
        }
        break;
    }
}

static s8 GetNewSlotDoubleLayout(s8 slotId, s8 movementDir)
{
    while (TRUE)
    {
        slotId += movementDir;
        if ((u8)slotId >= PARTY_SIZE)
            return -1;
        if (GetMonData(&gPlayerParty[slotId], MON_DATA_SPECIES) != SPECIES_NONE)
            return slotId;
    }
}

u8 *GetMonNickname(struct Pokemon *mon, u8 *dest)
{
    GetMonData(mon, MON_DATA_NICKNAME, dest);
    return StringGet_Nickname(dest);
}

#define tKeepOpen  data[0]

u8 DisplayPartyMenuMessage(const u8 *str, bool8 keepOpen)
{
    u8 taskId;

    PrintMessage(str);
    taskId = CreateTask(Task_PrintAndWaitForText, 1);
    gTasks[taskId].tKeepOpen = keepOpen;
    return taskId;
}

static void Task_PrintAndWaitForText(u8 taskId)
{
    if (RunTextPrintersRetIsActive(WIN_MSG) != TRUE)
    {
        if (gTasks[taskId].tKeepOpen == FALSE)
        {
            ClearStdWindowAndFrameToTransparent(WIN_MSG, FALSE);
            ClearWindowTilemap(WIN_MSG);
        }
        DestroyTask(taskId);
    }
}

#undef tKeepOpen

bool8 IsPartyMenuTextPrinterActive(void)
{
    return FuncIsActiveTask(Task_PrintAndWaitForText);
}

static void Task_WaitForLinkAndReturnToChooseMon(u8 taskId)
{
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
        gTasks[taskId].func = Task_HandleChooseMonInput;
    }
}

static void Task_ReturnToChooseMonAfterText(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        ClearStdWindowAndFrameToTransparent(WIN_MSG, FALSE);
        ClearWindowTilemap(WIN_MSG);
        if (MenuHelpers_IsLinkActive() == TRUE)
        {
            gTasks[taskId].func = Task_WaitForLinkAndReturnToChooseMon;
        }
        else
        {
            DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
            gTasks[taskId].func = Task_HandleChooseMonInput;
        }
    }
}

static void DisplayGaveHeldItemMessage(struct Pokemon *mon, u16 item, bool8 keepOpen, u8 unused)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x4B9); // gText_PkmnWasGivenItem
    DisplayPartyMenuMessage(gStringVar4, keepOpen);
    ScheduleBgCopyTilemapToVram(2);
}

static void DisplayTookHeldItemMessage(struct Pokemon *mon, u16 item, bool8 keepOpen)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x509); // gText_ReceivedItemFromPkmn
    DisplayPartyMenuMessage(gStringVar4, keepOpen);
    ScheduleBgCopyTilemapToVram(2);
}

static void DisplayAlreadyHoldingItemSwitchMessage(struct Pokemon *mon, u16 item, bool8 keepOpen)
{
    GetMonNickname(mon, gStringVar1);
    CopyItemName(item, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x4C9); // gText_PkmnAlreadyHoldingItemSwitch
    DisplayPartyMenuMessage(gStringVar4, keepOpen);
    ScheduleBgCopyTilemapToVram(2);
}

static void DisplaySwitchedHeldItemMessage(u16 item, u16 item2, bool8 keepOpen)
{
    CopyItemName(item, gStringVar1);
    CopyItemName(item2, gStringVar2);
    StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x532); // gText_SwitchedPkmnItem
    DisplayPartyMenuMessage(gStringVar4, keepOpen);
    ScheduleBgCopyTilemapToVram(2);
}

static void GiveItemToMon(struct Pokemon *mon, u16 item)
{
    u8 itemBytes[2];

    if (ItemIsMail(item) == TRUE)
    {
        if (GiveMailToMonByItemId(mon, item) == MAIL_NONE)
            return;
    }
    itemBytes[0] = item;
    itemBytes[1] = item >> 8;
    SetMonData(mon, MON_DATA_HELD_ITEM, itemBytes);
}

static u8 TryTakeMonItem(struct Pokemon *mon)
{
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    if (item == ITEM_NONE)
        return 0;
    if (AddBagItem(item, 1) == FALSE)
        return 1;

    item = ITEM_NONE;
    SetMonData(mon, MON_DATA_HELD_ITEM, &item);
    return 2;
}

static void BufferBagFullCantTakeItemMessage(u16 itemUnused)
{
    StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x58A); // gText_BagFullCouldNotRemoveItem
}

#define tHP           data[0]
#define tMaxHP        data[1]
#define tHPIncrement  data[2]
#define tHPToAdd      data[3]
#define tPartyId      data[4]
#define tStartHP      data[5]

static void Task_PartyMenuModifyHP(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tHP += tHPIncrement;
    tHPToAdd--;
    SetMonData(&gPlayerParty[tPartyId], MON_DATA_HP, &tHP);
    DisplayPartyPokemonHPCheck(&gPlayerParty[tPartyId], &sPartyMenuBoxes[tPartyId], 1);
    DisplayPartyPokemonHPBarCheck(&gPlayerParty[tPartyId], &sPartyMenuBoxes[tPartyId]);
    if (tHPToAdd == 0 || tHP == 0 || tHP == tMaxHP)
    {
        // If HP was recovered, buffer the amount recovered
        if (tHP > tStartHP)
            ConvertIntToDecimalStringN(gStringVar2, tHP - tStartHP, STR_CONV_MODE_LEFT_ALIGN, 3);

        SwitchTaskToFollowupFunc(taskId);
    }
}

void PartyMenuModifyHP(u8 taskId, u8 slot, s8 hpIncrement, s16 hpDifference, TaskFunc task)
{
    struct Pokemon *mon = &gPlayerParty[slot];
    s16 *data = gTasks[taskId].data;

    tHP = GetMonData(mon, MON_DATA_HP);
    tMaxHP = GetMonData(mon, MON_DATA_MAX_HP);
    tHPIncrement = hpIncrement;
    tHPToAdd = hpDifference;
    tPartyId = slot;
    tStartHP = tHP;
    SetTaskFuncWithFollowupFunc(taskId, Task_PartyMenuModifyHP, task);
}

// The usage of hp in this function is mostly nonsense
// Because caseId is always passed 0, none of the other cases ever occur
static void ResetHPTaskData(u8 taskId, u8 caseId, u32 hp)
{
    s16 *data = gTasks[taskId].data;

    switch (caseId) // always zero
    {
        case 0:
            tHP = hp;
            tStartHP = hp;
            break;
        case 1:
            tMaxHP = hp;
            break;
        case 2:
            tHPIncrement = hp;
            break;
        case 3:
            tHPToAdd = hp;
            break;
        case 4:
            tPartyId = hp;
            break;
        case 5:
            SetTaskFuncWithFollowupFunc(taskId, Task_PartyMenuModifyHP, (TaskFunc)hp); // >casting hp as a taskfunc
            break;
    }
}

#undef tHP
#undef tMaxHP
#undef tHPIncrement
#undef tHPToAdd
#undef tPartyId
#undef tStartHP

u8 GetAilmentFromStatus(u32 status)
{
    if (status & STATUS1_PSN_ANY)
        return AILMENT_PSN;
    if (status & STATUS1_PARALYSIS)
        return AILMENT_PRZ;
    if (status & STATUS1_SLEEP)
        return AILMENT_SLP;
    if (status & STATUS1_FREEZE)
        return AILMENT_FRZ;
    if (status & STATUS1_BURN)
        return AILMENT_BRN;
    return AILMENT_NONE;
}

u8 GetMonAilment(struct Pokemon *mon)
{
    u8 ailment;

    if (GetMonData(mon, MON_DATA_HP) == 0)
        return AILMENT_FNT;
    ailment = GetAilmentFromStatus(GetMonData(mon, MON_DATA_STATUS));
    if (ailment != AILMENT_NONE)
        return ailment;
    if (CheckPartyPokerus(mon, 0))
        return AILMENT_PKRS;
    return AILMENT_NONE;
}

static void SetPartyMonsAllowedInMinigame(void)
{
    s16 *ptr;

    if (gPartyMenu.menuType == PARTY_MENU_TYPE_MINIGAME)
    {
        u8 i;

        ptr = &gPartyMenu.data[0];
        gPartyMenu.data[0] = 0;
        if (gSpecialVar_0x8005 == 0)
        {
            for (i = 0; i < gPlayerPartyCount; i++)
                *ptr += IsMonAllowedInPokemonJump(&gPlayerParty[i]) << i;
        }
        else
        {
            for (i = 0; i < gPlayerPartyCount; i++)
                *ptr += IsMonAllowedInDodrioBerryPicking(&gPlayerParty[i]) << i;
        }
    }
}

static bool16 IsMonAllowedInPokemonJump(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG) != TRUE && IsSpeciesAllowedInPokemonJump(GetMonData(mon, MON_DATA_SPECIES)))
        return TRUE;
    return FALSE;
}

static bool16 IsMonAllowedInDodrioBerryPicking(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG) != TRUE && GetMonData(mon, MON_DATA_SPECIES) == SPECIES_DODRIO)
        return TRUE;
    return FALSE;
}

static bool8 IsMonAllowedInMinigame(u8 slot)
{
    if (!((gPartyMenu.data[0] >> slot) & 1))
        return FALSE;
    return TRUE;
}

static void TryEnterMonForMinigame(u8 taskId, u8 slot)
{
    if (IsMonAllowedInMinigame(slot) == TRUE)
    {
        PlaySE(SE_SELECT);
        gSpecialVar_0x8004 = slot;
        Task_ClosePartyMenu(taskId);
    }
    else
    {
        PlaySE(SE_FAILURE);
        DisplayPartyMenuMessage(gUnknown_85C97BD + 0xA3E, FALSE); // gText_PkmnCantParticipate
        ScheduleBgCopyTilemapToVram(2);
        gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
    }
}

static void CancelParticipationPrompt(u8 taskId)
{
    DisplayPartyMenuMessage(gUnknown_85C97BD + 0xA53, TRUE); // gText_CancelParticipation
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_CancelParticipationYesNo;
}

static void Task_CancelParticipationYesNo(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        sub_081B2FDC(); // PartyMenuDisplayYesNoMenu
        gTasks[taskId].func = Task_HandleCancelParticipationYesNoInput;
    }
}

static void Task_HandleCancelParticipationYesNoInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        gSpecialVar_0x8004 = PARTY_SIZE + 1;
        Task_ClosePartyMenu(taskId);
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1:
        gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
        break;
    }
}

static u8 CanMonLearnTMTutor(struct Pokemon *mon, u16 item, u8 tutor)
{
    u16 move;

    if (GetMonData(mon, MON_DATA_IS_EGG))
        return CANNOT_LEARN_MOVE_IS_EGG;

    if (item >= ITEM_TM01)
    {
        if (!CanMonLearnTMHM(mon, item - ITEM_TM01))
            return CANNOT_LEARN_MOVE;
        else
            move = ItemIdToBattleMoveId(item);
    }
    else
    {
        if (!CanLearnTutorMove(GetMonData(mon, MON_DATA_SPECIES), tutor))
            return CANNOT_LEARN_MOVE;
        else
            move = GetTutorMove(tutor);
    }

    if (MonKnowsMove(mon, move) == TRUE)
        return ALREADY_KNOWS_MOVE;
    else
        return CAN_LEARN_MOVE;
}

static u16 GetTutorMove(u8 tutor)
{
    return gTutorMoves[tutor];
}

static bool8 CanLearnTutorMove(u16 species, u8 tutor)
{
    if (sTutorLearnsets[species] & (1 << tutor))
        return TRUE;
    else
        return FALSE;
}

static void InitPartyMenuWindows(u8 layout)
{
    u8 i;

    switch (layout)
    {
    case PARTY_LAYOUT_SINGLE:
        InitWindows(sSinglePartyMenuWindowTemplate);
        break;
    case PARTY_LAYOUT_DOUBLE:
        InitWindows(sDoublePartyMenuWindowTemplate);
        break;
    case PARTY_LAYOUT_MULTI:
        InitWindows(sMultiPartyMenuWindowTemplate);
        break;
    default: // PARTY_LAYOUT_MULTI_SHOWCASE
        InitWindows(sShowcaseMultiPartyMenuWindowTemplate);
        break;
    }
    DeactivateAllTextPrinters();
    for (i = 0; i < PARTY_SIZE; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
    LoadUserWindowBorderGfx(0, 0x4F, BG_PLTT_ID(13));
    LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(14), PLTT_SIZE_4BPP);
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
}

static void CreateCancelConfirmWindows(bool8 chooseHalf)
{
    u8 confirmWindowId;
    u8 cancelWindowId;
    u8 offset;

    if (gPartyMenu.menuType != PARTY_MENU_TYPE_MULTI_SHOWCASE)
    {
        if (chooseHalf == TRUE)
        {
            confirmWindowId = AddWindow(&sConfirmButtonWindowTemplate);
            FillWindowPixelBuffer(confirmWindowId, PIXEL_FILL(0));
            AddTextPrinterParameterized4(confirmWindowId, FONT_NORMAL, 8, 2, 0, 0, sFontColorTable[0], TEXT_SKIP_DRAW, gMenuText_Confirm); // JP uses FONT_NORMAL
            PutWindowTilemap(confirmWindowId);
            CopyWindowToVram(confirmWindowId, COPYWIN_GFX);
            cancelWindowId = AddWindow(&sMultiCancelButtonWindowTemplate);
            offset = 0xA;
        }
        else
        {
            cancelWindowId = AddWindow(&sCancelButtonWindowTemplate);
            offset = 0xC;
        }
        FillWindowPixelBuffer(cancelWindowId, PIXEL_FILL(0));

        if (gPartyMenu.menuType != PARTY_MENU_TYPE_SPIN_TRADE)
        {
            AddTextPrinterParameterized3(cancelWindowId, FONT_NORMAL, offset, 2, sFontColorTable[0], TEXT_SKIP_DRAW, gText_Cancel); // JP uses FONT_NORMAL
        }
        else
        {
            AddTextPrinterParameterized3(cancelWindowId, FONT_NORMAL, offset, 2, sFontColorTable[0], TEXT_SKIP_DRAW, gText_Exit); // JP uses FONT_NORMAL
        }
        PutWindowTilemap(cancelWindowId);
        CopyWindowToVram(cancelWindowId, COPYWIN_GFX);
        ScheduleBgCopyTilemapToVram(0);
    }
}

static u16 *GetPartyMenuPalBufferPtr(u8 paletteId)
{
    return &sPartyMenuInternal->palBuffer[paletteId];
}

static void BlitBitmapToPartyWindow(u8 windowId, const u8 *b, u8 c, u8 x, u8 y, u8 width, u8 height)
{
    u8 *pixels = AllocZeroed(height * width * 32);
    u8 i, j;

    if (pixels != NULL)
    {
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
                CpuCopy16(GetPartyMenuBgTile(b[x + j + ((y + i) * c)]), &pixels[(i * width + j) * 32], 32);
        }
        BlitBitmapToWindow(windowId, pixels, x * 8, y * 8, width * 8, height * 8);
        Free(pixels);
    }
}

static void BlitBitmapToPartyWindow_LeftColumn(u8 windowId, u8 x, u8 y, u8 width, u8 height, bool8 hideHP)
{
    if (width == 0 && height == 0)
    {
        width = 10;
        height = 7;
    }
    if (hideHP == FALSE)
        BlitBitmapToPartyWindow(windowId, sSlotTilemap_Main, 10, x, y, width, height);
    else
        BlitBitmapToPartyWindow(windowId, sSlotTilemap_MainNoHP, 10, x, y, width, height);
}

static void BlitBitmapToPartyWindow_RightColumn(u8 windowId, u8 x, u8 y, u8 width, u8 height, bool8 hideHP)
{
    if (width == 0 && height == 0)
    {
        width = 18;
        height = 3;
    }
    if (hideHP == FALSE)
        BlitBitmapToPartyWindow(windowId, sSlotTilemap_Wide, 18, x, y, width, height);
    else
        BlitBitmapToPartyWindow(windowId, sSlotTilemap_WideNoHP, 18, x, y, width, height);
}

static void DrawEmptySlot(u8 windowId)
{
    BlitBitmapToPartyWindow(windowId, sSlotTilemap_WideEmpty, 18, 0, 0, 18, 3);
}

#define LOAD_PARTY_BOX_PAL(paletteIds, paletteOffsets)                                                    \
{                                                                                                         \
    LoadPalette(GetPartyMenuPalBufferPtr(paletteIds[0]), paletteOffsets[0] + palOffset, PLTT_SIZEOF(1));  \
    LoadPalette(GetPartyMenuPalBufferPtr(paletteIds[1]), paletteOffsets[1] + palOffset, PLTT_SIZEOF(1));  \
    LoadPalette(GetPartyMenuPalBufferPtr(paletteIds[2]), paletteOffsets[2] + palOffset, PLTT_SIZEOF(1));  \
}

static void LoadPartyBoxPalette(struct PartyMenuBox *menuBox, u8 palFlags)
{
    u8 palOffset = BG_PLTT_ID(GetWindowAttribute(menuBox->windowId, WINDOW_PALETTE_NUM));

    if (palFlags & PARTY_PAL_NO_MON)
    {
        LOAD_PARTY_BOX_PAL(sPartyBoxNoMonPalIds, sPartyBoxNoMonPalOffsets);
    }
    else if (palFlags & PARTY_PAL_TO_SOFTBOIL)
    {
        if (palFlags & PARTY_PAL_SELECTED)
        {
            LOAD_PARTY_BOX_PAL(sPartyBoxSelectedForActionPalIds1, sPartyBoxPalOffsets1);
            LOAD_PARTY_BOX_PAL(sPartyBoxCurrSelectionPalIds2, sPartyBoxPalOffsets2);
        }
        else
        {
            LOAD_PARTY_BOX_PAL(sPartyBoxSelectedForActionPalIds1, sPartyBoxPalOffsets1);
            LOAD_PARTY_BOX_PAL(sPartyBoxSelectedForActionPalIds2, sPartyBoxPalOffsets2);
        }
    }
    else if (palFlags & PARTY_PAL_SWITCHING)
    {
        LOAD_PARTY_BOX_PAL(sPartyBoxSelectedForActionPalIds1, sPartyBoxPalOffsets1);
        LOAD_PARTY_BOX_PAL(sPartyBoxSelectedForActionPalIds2, sPartyBoxPalOffsets2);
    }
    else if (palFlags & PARTY_PAL_TO_SWITCH)
    {
        if (palFlags & PARTY_PAL_SELECTED)
        {
            LOAD_PARTY_BOX_PAL(sPartyBoxSelectedForActionPalIds1, sPartyBoxPalOffsets1);
            LOAD_PARTY_BOX_PAL(sPartyBoxCurrSelectionPalIds2, sPartyBoxPalOffsets2);
        }
        else
        {
            LOAD_PARTY_BOX_PAL(sPartyBoxSelectedForActionPalIds1, sPartyBoxPalOffsets1);
            LOAD_PARTY_BOX_PAL(sPartyBoxSelectedForActionPalIds2, sPartyBoxPalOffsets2);
        }
    }
    else if (palFlags & PARTY_PAL_FAINTED)
    {
        if (palFlags & PARTY_PAL_SELECTED)
        {
            LOAD_PARTY_BOX_PAL(sPartyBoxCurrSelectionFaintedPalIds, sPartyBoxPalOffsets1);
            LOAD_PARTY_BOX_PAL(sPartyBoxCurrSelectionPalIds2, sPartyBoxPalOffsets2);
        }
        else
        {
            LOAD_PARTY_BOX_PAL(sPartyBoxFaintedPalIds1, sPartyBoxPalOffsets1);
            LOAD_PARTY_BOX_PAL(sPartyBoxFaintedPalIds2, sPartyBoxPalOffsets2);
        }
    }
    else if (palFlags & PARTY_PAL_MULTI_ALT)
    {
        if (palFlags & PARTY_PAL_SELECTED)
        {
            LOAD_PARTY_BOX_PAL(sPartyBoxCurrSelectionMultiPalIds, sPartyBoxPalOffsets1);
            LOAD_PARTY_BOX_PAL(sPartyBoxCurrSelectionPalIds2, sPartyBoxPalOffsets2);
        }
        else
        {
            LOAD_PARTY_BOX_PAL(sPartyBoxMultiPalIds1, sPartyBoxPalOffsets1);
            LOAD_PARTY_BOX_PAL(sPartyBoxMultiPalIds2, sPartyBoxPalOffsets2);
        }
    }
    else if (palFlags & PARTY_PAL_SELECTED)
    {
        LOAD_PARTY_BOX_PAL(sPartyBoxCurrSelectionPalIds1, sPartyBoxPalOffsets1);
        LOAD_PARTY_BOX_PAL(sPartyBoxCurrSelectionPalIds2, sPartyBoxPalOffsets2);
    }
    else
    {
        LOAD_PARTY_BOX_PAL(sPartyBoxEmptySlotPalIds1, sPartyBoxPalOffsets1);
        LOAD_PARTY_BOX_PAL(sPartyBoxEmptySlotPalIds2, sPartyBoxPalOffsets2);
    }
}

static void DisplayPartyPokemonBarDetail(u8 windowId, const u8 *str, u8 color, const u8 *align)
{
    AddTextPrinterParameterized3(windowId, FONT_SMALL, align[0], align[1], sFontColorTable[color], 0, str);
}

static void DisplayPartyPokemonNickname(struct Pokemon *mon, struct PartyMenuBox *menuBox, u8 c)
{
    u8 nickname[POKEMON_NAME_STORAGE_LENGTH + 1];

    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c == 1)
            menuBox->infoRects->blitFunc(menuBox->windowId, menuBox->infoRects->dimensions[0] >> 3, menuBox->infoRects->dimensions[1] >> 3, menuBox->infoRects->dimensions[2] >> 3, menuBox->infoRects->dimensions[3] >> 3, FALSE);
        GetMonNickname(mon, nickname);
        DisplayPartyPokemonBarDetail(menuBox->windowId, nickname, 0, menuBox->infoRects->dimensions);
    }
}

static void DisplayPartyPokemonLevelCheck(struct Pokemon *mon, struct PartyMenuBox *menuBox, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        u8 ailment = GetMonAilment(mon);
        if (ailment == AILMENT_NONE || ailment == AILMENT_PKRS)
        {
            if (c != 0)
                menuBox->infoRects->blitFunc(menuBox->windowId, menuBox->infoRects->dimensions[4] >> 3, (menuBox->infoRects->dimensions[5] >> 3) + 1, menuBox->infoRects->dimensions[6] >> 3, menuBox->infoRects->dimensions[7] >> 3, FALSE);
            if (c != 2)
                DisplayPartyPokemonLevel(GetMonData(mon, MON_DATA_LEVEL), menuBox);
        }
    }
}

static void DisplayPartyPokemonLevel(u8 level, struct PartyMenuBox *menuBox)
{
    ConvertIntToDecimalStringN(gStringVar2, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringCopy(gStringVar1, gText_LevelSymbol);
    StringAppend(gStringVar1, gStringVar2);
    DisplayPartyPokemonBarDetail(menuBox->windowId, gStringVar1, 0, &menuBox->infoRects->dimensions[4]);
}

static void DisplayPartyPokemonGenderNidoranCheck(struct Pokemon *mon, struct PartyMenuBox *menuBox, u8 c)
{
    u8 nickname[POKEMON_NAME_STORAGE_LENGTH + 1];

    if (c == 1)
        menuBox->infoRects->blitFunc(menuBox->windowId, menuBox->infoRects->dimensions[8] >> 3, (menuBox->infoRects->dimensions[9] >> 3) + 1, menuBox->infoRects->dimensions[10] >> 3, menuBox->infoRects->dimensions[11] >> 3, FALSE);
    GetMonNickname(mon, nickname);
    DisplayPartyPokemonGender(GetMonGender(mon), (u16)GetMonData(mon, MON_DATA_SPECIES), nickname, menuBox);
}

static void DisplayPartyPokemonGender(u8 gender, u16 species, u8 *nickname, struct PartyMenuBox *menuBox)
{
    u8 palOffset = BG_PLTT_ID(GetWindowAttribute(menuBox->windowId, WINDOW_PALETTE_NUM));

    if (species == SPECIES_NONE)
        return;
    if ((species == SPECIES_NIDORAN_M || species == SPECIES_NIDORAN_F) && StringCompare(nickname, gSpeciesNames[species]) == 0)
        return;
    switch (gender)
    {
    case MON_MALE:
        LoadPalette(GetPartyMenuPalBufferPtr(sGenderMalePalIds[0]), sGenderPalOffsets[0] + palOffset, PLTT_SIZEOF(1));
        LoadPalette(GetPartyMenuPalBufferPtr(sGenderMalePalIds[1]), sGenderPalOffsets[1] + palOffset, PLTT_SIZEOF(1));
        DisplayPartyPokemonBarDetail(menuBox->windowId, gText_MaleSymbol, 2, &menuBox->infoRects->dimensions[8]);
        break;
    case MON_FEMALE:
        LoadPalette(GetPartyMenuPalBufferPtr(sGenderFemalePalIds[0]), sGenderPalOffsets[0] + palOffset, PLTT_SIZEOF(1));
        LoadPalette(GetPartyMenuPalBufferPtr(sGenderFemalePalIds[1]), sGenderPalOffsets[1] + palOffset, PLTT_SIZEOF(1));
        DisplayPartyPokemonBarDetail(menuBox->windowId, gText_FemaleSymbol, 2, &menuBox->infoRects->dimensions[8]);
        break;
    }
}

static void DisplayPartyPokemonHPCheck(struct Pokemon *mon, struct PartyMenuBox *menuBox, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c != 0)
            menuBox->infoRects->blitFunc(menuBox->windowId, menuBox->infoRects->dimensions[12] >> 3, (menuBox->infoRects->dimensions[13] >> 3) + 1, menuBox->infoRects->dimensions[14] >> 3, menuBox->infoRects->dimensions[15] >> 3, FALSE);
        if (c != 2)
            DisplayPartyPokemonHP((u16)GetMonData(mon, MON_DATA_HP), menuBox);
    }
}

static void DisplayPartyPokemonHP(u16 hp, struct PartyMenuBox *menuBox)
{
    ConvertIntToDecimalStringN(gStringVar1, hp, STR_CONV_MODE_RIGHT_ALIGN, 3);
    DisplayPartyPokemonBarDetail(menuBox->windowId, gStringVar1, 0, &menuBox->infoRects->dimensions[12]);
}

static void DisplayPartyPokemonMaxHPCheck(struct Pokemon *mon, struct PartyMenuBox *menuBox, u8 c)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
    {
        if (c != 0)
            menuBox->infoRects->blitFunc(menuBox->windowId, (menuBox->infoRects->dimensions[16] >> 3) + 1, (menuBox->infoRects->dimensions[17] >> 3) + 1, menuBox->infoRects->dimensions[18] >> 3, menuBox->infoRects->dimensions[19] >> 3, FALSE);
        if (c != 2)
            DisplayPartyPokemonMaxHP((u16)GetMonData(mon, MON_DATA_MAX_HP), menuBox);
    }
}

static void DisplayPartyPokemonMaxHP(u16 maxhp, struct PartyMenuBox *menuBox)
{
    ConvertIntToDecimalStringN(gStringVar2, maxhp, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringCopy(gStringVar1, gText_Slash);
    StringAppend(gStringVar1, gStringVar2);
    DisplayPartyPokemonBarDetail(menuBox->windowId, gStringVar1, 0, &menuBox->infoRects->dimensions[16]);
}

static void DisplayPartyPokemonHPBarCheck(struct Pokemon *mon, struct PartyMenuBox *menuBox)
{
    if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE)
        DisplayPartyPokemonHPBar((u16)GetMonData(mon, MON_DATA_HP), (u16)GetMonData(mon, MON_DATA_MAX_HP), menuBox);
}


static void DisplayPartyPokemonHPBar(u16 hp, u16 maxhp, struct PartyMenuBox *menuBox)
{
    u8 palOffset = BG_PLTT_ID(GetWindowAttribute(menuBox->windowId, WINDOW_PALETTE_NUM));
    u8 hpFraction;

    switch (GetHPBarLevel(hp, maxhp))
    {
    case HP_BAR_GREEN:
    case HP_BAR_FULL:
        LoadPalette(GetPartyMenuPalBufferPtr(sHPBarGreenPalIds[0]), sHPBarPalOffsets[0] + palOffset, PLTT_SIZEOF(1));
        LoadPalette(GetPartyMenuPalBufferPtr(sHPBarGreenPalIds[1]), sHPBarPalOffsets[1] + palOffset, PLTT_SIZEOF(1));
        break;
    case HP_BAR_YELLOW:
        LoadPalette(GetPartyMenuPalBufferPtr(sHPBarYellowPalIds[0]), sHPBarPalOffsets[0] + palOffset, PLTT_SIZEOF(1));
        LoadPalette(GetPartyMenuPalBufferPtr(sHPBarYellowPalIds[1]), sHPBarPalOffsets[1] + palOffset, PLTT_SIZEOF(1));
        break;
    default:
        LoadPalette(GetPartyMenuPalBufferPtr(sHPBarRedPalIds[0]), sHPBarPalOffsets[0] + palOffset, PLTT_SIZEOF(1));
        LoadPalette(GetPartyMenuPalBufferPtr(sHPBarRedPalIds[1]), sHPBarPalOffsets[1] + palOffset, PLTT_SIZEOF(1));
        break;
    }

    hpFraction = GetScaledHPFraction(hp, maxhp, menuBox->infoRects->dimensions[22]);
    FillWindowPixelRect(menuBox->windowId, sHPBarPalOffsets[1], menuBox->infoRects->dimensions[20], menuBox->infoRects->dimensions[21], hpFraction, 1);
    FillWindowPixelRect(menuBox->windowId, sHPBarPalOffsets[0], menuBox->infoRects->dimensions[20], menuBox->infoRects->dimensions[21] + 1, hpFraction, 2);
    if (hpFraction != menuBox->infoRects->dimensions[22])
    {
        FillWindowPixelRect(menuBox->windowId, 0x0D, menuBox->infoRects->dimensions[20] + hpFraction, menuBox->infoRects->dimensions[21], menuBox->infoRects->dimensions[22] - hpFraction, 1);
        FillWindowPixelRect(menuBox->windowId, 0x02, menuBox->infoRects->dimensions[20] + hpFraction, menuBox->infoRects->dimensions[21] + 1, menuBox->infoRects->dimensions[22] - hpFraction, 2);
    }
    CopyWindowToVram(menuBox->windowId, COPYWIN_GFX);
}

static void DisplayPartyPokemonDescriptionText(u8 stringID, struct PartyMenuBox *menuBox, u8 c)
{
    if (c)
    {
        // JP: blit width/height are the raw dimensions >> 3 (US computes (offset%8 + width + 7) / 8)
        menuBox->infoRects->blitFunc(menuBox->windowId, menuBox->infoRects->descTextLeft >> 3, menuBox->infoRects->descTextTop >> 3, menuBox->infoRects->descTextWidth >> 3, menuBox->infoRects->descTextHeight >> 3, TRUE);
    }
    if (c != 2)
        AddTextPrinterParameterized3(menuBox->windowId, FONT_NORMAL, menuBox->infoRects->descTextLeft, menuBox->infoRects->descTextTop, sFontColorTable[0], 0, sDescriptionStringTable[stringID]);
}

static void PartyMenuRemoveWindow(u8 *ptr)
{
    if (*ptr != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(*ptr, FALSE);
        RemoveWindow(*ptr);
        *ptr = WINDOW_NONE;
        ScheduleBgCopyTilemapToVram(2);
    }
}

void DisplayPartyMenuStdMessage(u32 stringId)
{
    u8 *windowPtr = &sPartyMenuInternal->windowId[1];

    if (*windowPtr != WINDOW_NONE)
        PartyMenuRemoveWindow(windowPtr);

    if (stringId != PARTY_MSG_NONE)
    {
        switch (stringId)
        {
        // JP: PARTY_MSG enum order differs from US (RESTORE=22/BOOST=23 before ITEM=24/MAIL=25)
        case PARTY_MSG_DO_WHAT_WITH_MON:
            *windowPtr = AddWindow(&sDoWhatWithMonMsgWindowTemplate);
            break;
        case PARTY_MSG_DO_WHAT_WITH_ITEM:
            *windowPtr = AddWindow(&sDoWhatWithItemMsgWindowTemplate);
            break;
        case PARTY_MSG_DO_WHAT_WITH_MAIL:
            *windowPtr = AddWindow(&sDoWhatWithMailMsgWindowTemplate);
            break;
        case PARTY_MSG_RESTORE_WHICH_MOVE:
        case PARTY_MSG_BOOST_PP_WHICH_MOVE:
            *windowPtr = AddWindow(&sWhichMoveMsgWindowTemplate);
            break;
        case PARTY_MSG_ALREADY_HOLDING_ONE:
            *windowPtr = AddWindow(&sAlreadyHoldingOneMsgWindowTemplate);
            break;
        default:
            *windowPtr = AddWindow(&sDefaultPartyMsgWindowTemplate);
            break;
        }

        if (stringId == PARTY_MSG_CHOOSE_MON)
        {
            if (sPartyMenuInternal->chooseHalf)
                stringId = PARTY_MSG_CHOOSE_MON_AND_CONFIRM;
            else if (!ShouldUseChooseMonText())
                stringId = PARTY_MSG_CHOOSE_MON_OR_CANCEL;
        }
        DrawStdFrameWithCustomTileAndPalette(*windowPtr, FALSE, 0x4F, 13);
        StringExpandPlaceholders(gStringVar4, sActionStringTable[stringId]);
        // JP: message text y = 2 (US uses 1)
        AddTextPrinterParameterized(*windowPtr, FONT_NORMAL, gStringVar4, 0, 2, 0, 0);
        ScheduleBgCopyTilemapToVram(2);
    }
}

static bool8 ShouldUseChooseMonText(void)
{
    struct Pokemon *party = gPlayerParty;
    u8 i;
    u8 numAliveMons = 0;

    if (gPartyMenu.action == PARTY_ACTION_SEND_OUT)
        return TRUE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES) != SPECIES_NONE && (GetMonData(&party[i], MON_DATA_HP) != 0 || GetMonData(&party[i], MON_DATA_IS_EGG)))
            numAliveMons++;
        if (numAliveMons > 1)
            return TRUE;
    }
    return FALSE;
}

static u8 DisplaySelectionWindow(u8 windowType)
{
    struct WindowTemplate window;
    u8 cursorDimension;
    u8 letterSpacing;
    u8 i;

    switch (windowType)
    {
    case SELECTWINDOW_ACTIONS:
        // JP: left=21, width=8, baseBlock=0x2D3 (US uses 19/10/0x2E9)
        SetWindowTemplateFields(&window, 2, 21, 19 - (sPartyMenuInternal->numActions * 2), 8, sPartyMenuInternal->numActions * 2, 14, 0x2D3);
        break;
    case SELECTWINDOW_ITEM:
        window = sItemGiveTakeWindowTemplate;
        break;
    case SELECTWINDOW_MAIL:
        window = sMailReadTakeWindowTemplate;
        break;
    default: // SELECTWINDOW_MOVES
        window = sMoveSelectWindowTemplate;
        break;
    }

    sPartyMenuInternal->windowId[0] = AddWindow(&window);
    DrawStdFrameWithCustomTileAndPalette(sPartyMenuInternal->windowId[0], FALSE, 0x4F, 13);
    if (windowType == SELECTWINDOW_MOVES)
        return sPartyMenuInternal->windowId[0];
    cursorDimension = GetMenuCursorDimensionByFont(FONT_NORMAL, 0);
    letterSpacing = GetFontAttribute(FONT_NORMAL, FONTATTR_LETTER_SPACING);

    for (i = 0; i < sPartyMenuInternal->numActions; i++)
    {
        u8 fontColorsId = (sPartyMenuInternal->actions[i] >= MENU_FIELD_MOVES) ? 4 : 3;
        // JP: y = (i * 16) + 2 (US uses +1)
        AddTextPrinterParameterized4(sPartyMenuInternal->windowId[0], FONT_NORMAL, cursorDimension, (i * 16) + 2, letterSpacing, 0, sFontColorTable[fontColorsId], 0, sCursorOptions[sPartyMenuInternal->actions[i]].text);
    }

    // JP: calls InitMenu (0x0819844C) directly with top=2 (US wraps in InitMenuInUpperLeftCorner with top=0)
    sub_0819844C(sPartyMenuInternal->windowId[0], FONT_NORMAL, 0, 2, 16, sPartyMenuInternal->numActions, 0, TRUE);
    ScheduleBgCopyTilemapToVram(2);

    return sPartyMenuInternal->windowId[0];
}

static void PrintMessage(const u8 *text)
{
    DrawStdFrameWithCustomTileAndPalette(WIN_MSG, FALSE, 0x4F, 13);
    gTextFlags.canABSpeedUpPrint = TRUE;
    AddTextPrinterParameterized2(WIN_MSG, FONT_NORMAL, text, GetPlayerTextSpeedDelay(), 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
}

// JP-only: yes/no menu via CreateYesNoMenuAtPos (US wraps in CreateYesNoMenu; JP left=2/top=2)
void sub_081B2FDC(void)
{
    CreateYesNoMenuAtPos(&sPartyMenuYesNoWindowTemplate, FONT_NORMAL, 2, 2, 0x4F, 13, 0);
}

static u8 CreateLevelUpStatsWindow(void)
{
    sPartyMenuInternal->windowId[0] = AddWindow(&sLevelUpStatsWindowTemplate);
    DrawStdFrameWithCustomTileAndPalette(sPartyMenuInternal->windowId[0], FALSE, 0x4F, 13);
    return sPartyMenuInternal->windowId[0];
}

static void PartyMenuRemoveWindow(u8 *windowId);

static void RemoveLevelUpStatsWindow(void)
{
    ClearWindowTilemap(sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
}

static void SetPartyMonSelectionActions(struct Pokemon *mons, u8 slotId, u8 action)
{
    u8 i;

    if (action == ACTIONS_NONE)
    {
        SetPartyMonFieldSelectionActions(mons, slotId);
    }
    else
    {
        sPartyMenuInternal->numActions = sPartyMenuActionCounts[action];
        for (i = 0; i < sPartyMenuInternal->numActions; i++)
            sPartyMenuInternal->actions[i] = sPartyMenuActions[action][i];
    }
}

static void SetPartyMonFieldSelectionActions(struct Pokemon *mons, u8 slotId)
{
    u8 i, j;

    sPartyMenuInternal->numActions = 0;
    AppendToList(sPartyMenuInternal->actions, &sPartyMenuInternal->numActions, MENU_SUMMARY);

    // Add field moves to action list
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        for (j = 0; sFieldMoves[j] != FIELD_MOVES_COUNT; j++)
        {
            if (GetMonData(&mons[slotId], i + MON_DATA_MOVE1) == sFieldMoves[j])
            {
                AppendToList(sPartyMenuInternal->actions, &sPartyMenuInternal->numActions, j + MENU_FIELD_MOVES);
                break;
            }
        }
    }

    if (!InBattlePike())
    {
        if (GetMonData(&mons[1], MON_DATA_SPECIES) != SPECIES_NONE)
            AppendToList(sPartyMenuInternal->actions, &sPartyMenuInternal->numActions, MENU_SWITCH);
        if (ItemIsMail(GetMonData(&mons[slotId], MON_DATA_HELD_ITEM)))
            AppendToList(sPartyMenuInternal->actions, &sPartyMenuInternal->numActions, MENU_MAIL);
        else
            AppendToList(sPartyMenuInternal->actions, &sPartyMenuInternal->numActions, MENU_ITEM);
    }
    AppendToList(sPartyMenuInternal->actions, &sPartyMenuInternal->numActions, MENU_CANCEL1);
}

static u8 GetPartyMenuActionsType(struct Pokemon *mon)
{
    u32 actionType;

    switch (gPartyMenu.menuType)
    {
    case PARTY_MENU_TYPE_FIELD:
        if ((u8)InMultiPartnerRoom() == TRUE || GetMonData(mon, MON_DATA_IS_EGG))
            actionType = ACTIONS_SWITCH;
        else
            actionType = ACTIONS_NONE; // actions populated by SetPartyMonFieldSelectionActions
        break;
    case PARTY_MENU_TYPE_IN_BATTLE:
        actionType = GetPartyMenuActionsTypeInBattle(mon);
        break;
    case PARTY_MENU_TYPE_CHOOSE_HALF:
        switch (GetPartySlotEntryStatus(gPartyMenu.slotId))
        {
        default: // Not eligible
            actionType = ACTIONS_SUMMARY_ONLY;
            break;
        case 0: // Eligible
            actionType = ACTIONS_ENTER;
            break;
        case 1: // Already selected
            actionType = ACTIONS_NO_ENTRY;
            break;
        }
        break;
    case PARTY_MENU_TYPE_DAYCARE:
        actionType = (GetMonData(mon, MON_DATA_IS_EGG)) ? ACTIONS_SUMMARY_ONLY : ACTIONS_STORE;
        break;
    case PARTY_MENU_TYPE_UNION_ROOM_REGISTER:
        actionType = ACTIONS_REGISTER;
        break;
    case PARTY_MENU_TYPE_UNION_ROOM_TRADE:
        actionType = ACTIONS_TRADE;
        break;
    case PARTY_MENU_TYPE_SPIN_TRADE:
        actionType = ACTIONS_SPIN_TRADE;
        break;
    case PARTY_MENU_TYPE_STORE_PYRAMID_HELD_ITEMS:
        actionType = ACTIONS_TAKEITEM_TOSS;
        break;
    default:
        actionType = ACTIONS_NONE;
        break;
    }
    return actionType;
}

static bool8 CreateSelectionWindow(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];
    u16 item;

    GetMonNickname(mon, gStringVar1);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    if (gPartyMenu.menuType != PARTY_MENU_TYPE_STORE_PYRAMID_HELD_ITEMS)
    {
        SetPartyMonSelectionActions(gPlayerParty, gPartyMenu.slotId, GetPartyMenuActionsType(mon));
        DisplaySelectionWindow(SELECTWINDOW_ACTIONS);
        DisplayPartyMenuStdMessage(PARTY_MSG_DO_WHAT_WITH_MON);
    }
    else
    {
        item = GetMonData(mon, MON_DATA_HELD_ITEM);
        if (item != ITEM_NONE)
        {
            SetPartyMonSelectionActions(gPlayerParty, gPartyMenu.slotId, GetPartyMenuActionsType(mon));
            DisplaySelectionWindow(SELECTWINDOW_ITEM);
            CopyItemName(item, gStringVar2);
            DisplayPartyMenuStdMessage(PARTY_MSG_ALREADY_HOLDING_ONE);
        }
        else
        {
            // JP: gText_PkmnNotHolding is embedded in the gUnknown_85C97BD text block
            StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x4F0);
            DisplayPartyMenuMessage(gStringVar4, TRUE);
            ScheduleBgCopyTilemapToVram(2);
            gTasks[taskId].func = Task_UpdateHeldItemSprite;
            return FALSE;
        }
    }
    return TRUE;
}

static void Task_TryCreateSelectionWindow(u8 taskId)
{
    if (CreateSelectionWindow(taskId))
    {
        gTasks[taskId].data[0] = 0xFF;
        gTasks[taskId].func = Task_HandleSelectionMenuInput;
    }
}

static void Task_HandleSelectionMenuInput(u8 taskId)
{
    if (!gPaletteFade.active && MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        s8 input;
        s16 *data = gTasks[taskId].data;

        if (sPartyMenuInternal->numActions <= 3)
            input = Menu_ProcessInputNoWrapAround_other();
        else
            input = ProcessMenuInput_other();

        data[0] = Menu_GetCursorPos();
        switch (input)
        {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
            PlaySE(SE_SELECT);
            PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[2]);
            sCursorOptions[sPartyMenuInternal->actions[sPartyMenuInternal->numActions - 1]].func(taskId);
            break;
        default:
            PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[2]);
            sCursorOptions[sPartyMenuInternal->actions[input]].func(taskId);
            break;
        }
    }
}

static void CursorCb_Summary(u8 taskId)
{
    PlaySE(SE_SELECT);
    sPartyMenuInternal->exitCallback = CB2_ShowPokemonSummaryScreen;
    Task_ClosePartyMenu(taskId);
}

static void CB2_ShowPokemonSummaryScreen(void)
{
    if (gPartyMenu.menuType == PARTY_MENU_TYPE_IN_BATTLE)
    {
        pokemon_change_order(); // UpdatePartyToBattleOrder
        ShowPokemonSummaryScreen(SUMMARY_MODE_LOCK_MOVES, gPlayerParty, gPartyMenu.slotId, gPlayerPartyCount - 1, CB2_ReturnToPartyMenuFromSummaryScreen);
    }
    else
    {
        ShowPokemonSummaryScreen(SUMMARY_MODE_NORMAL, gPlayerParty, gPartyMenu.slotId, gPlayerPartyCount - 1, CB2_ReturnToPartyMenuFromSummaryScreen);
    }
}

static void CB2_ReturnToPartyMenuFromSummaryScreen(void)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    gPartyMenu.slotId = gLastViewedMonIndex;
    InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, gPartyMenu.action, TRUE, PARTY_MSG_DO_WHAT_WITH_MON, Task_TryCreateSelectionWindow, gPartyMenu.exitCallback);
}

static void CursorCb_Switch(u8 taskId)
{
    PlaySE(SE_SELECT);
    gPartyMenu.action = PARTY_ACTION_SWITCH;
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    DisplayPartyMenuStdMessage(PARTY_MSG_MOVE_TO_WHERE);
    AnimatePartySlot(gPartyMenu.slotId, 1);
    gPartyMenu.slotId2 = gPartyMenu.slotId;
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

#define tSlot1Left     data[0]
#define tSlot1Top      data[1]
#define tSlot1Width    data[2]
#define tSlot1Height   data[3]
#define tSlot2Left     data[4]
#define tSlot2Top      data[5]
#define tSlot2Width    data[6]
#define tSlot2Height   data[7]
#define tSlot1Offset   data[8]
#define tSlot2Offset   data[9]
#define tSlot1SlideDir data[10]
#define tSlot2SlideDir data[11]

static void SwitchSelectedMons(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 windowIds[2];

    if (gPartyMenu.slotId2 == gPartyMenu.slotId)
    {
        FinishTwoMonAction(taskId); // FinishTwoMonAction
    }
    else
    {
        // Initialize switching party mons slide animation
        windowIds[0] = sPartyMenuBoxes[gPartyMenu.slotId].windowId;
        tSlot1Left = GetWindowAttribute(windowIds[0], WINDOW_TILEMAP_LEFT);
        tSlot1Top = GetWindowAttribute(windowIds[0], WINDOW_TILEMAP_TOP);
        tSlot1Width = GetWindowAttribute(windowIds[0], WINDOW_WIDTH);
        tSlot1Height = GetWindowAttribute(windowIds[0], WINDOW_HEIGHT);
        tSlot1Offset = 0;
        if (tSlot1Width == 10)
            tSlot1SlideDir = -1;
        else
            tSlot1SlideDir = 1;
        windowIds[1] = sPartyMenuBoxes[gPartyMenu.slotId2].windowId;
        tSlot2Left = GetWindowAttribute(windowIds[1], WINDOW_TILEMAP_LEFT);
        tSlot2Top = GetWindowAttribute(windowIds[1], WINDOW_TILEMAP_TOP);
        tSlot2Width = GetWindowAttribute(windowIds[1], WINDOW_WIDTH);
        tSlot2Height = GetWindowAttribute(windowIds[1], WINDOW_HEIGHT);
        tSlot2Offset = 0;
        if (tSlot2Width == 10)
            tSlot2SlideDir = -1;
        else
            tSlot2SlideDir = 1;
        sSlot1TilemapBuffer = Alloc(tSlot1Width * (tSlot1Height << 1));
        sSlot2TilemapBuffer = Alloc(tSlot2Width * (tSlot2Height << 1));
        sub_08199954(0, sSlot1TilemapBuffer, tSlot1Left, tSlot1Top, tSlot1Width, tSlot1Height); // CopyToBufferFromBgTilemap
        sub_08199954(0, sSlot2TilemapBuffer, tSlot2Left, tSlot2Top, tSlot2Width, tSlot2Height);
        ClearWindowTilemap(windowIds[0]);
        ClearWindowTilemap(windowIds[1]);
        gPartyMenu.action = PARTY_ACTION_SWITCHING;
        AnimatePartySlot(gPartyMenu.slotId, 1);
        AnimatePartySlot(gPartyMenu.slotId2, 1);
        SlidePartyMenuBoxOneStep(taskId); // SlidePartyMenuBoxOneStep
        gTasks[taskId].func = Task_SlideSelectedSlotsOffscreen; // Task_SlideSelectedSlotsOffscreen
    }
}

#undef tSlot1Left
#undef tSlot1Top
#undef tSlot1Width
#undef tSlot1Height
#undef tSlot2Left
#undef tSlot2Top
#undef tSlot2Width
#undef tSlot2Height
#undef tSlot1Offset
#undef tSlot2Offset
#undef tSlot1SlideDir
#undef tSlot2SlideDir

#define tSlot1Left     data[0]
#define tSlot1Top      data[1]
#define tSlot1Width    data[2]
#define tSlot1Height   data[3]
#define tSlot2Left     data[4]
#define tSlot2Top      data[5]
#define tSlot2Width    data[6]
#define tSlot2Height   data[7]
#define tSlot1Offset   data[8]
#define tSlot2Offset   data[9]
#define tSlot1SlideDir data[10]
#define tSlot2SlideDir data[11]

// returns FALSE if the slot has slid fully offscreen / back onscreen
static bool8 TryMovePartySlot(s16 x, s16 width, u8 *leftMove, u8 *newX, u8 *newWidth)
{
    if (x + width < 0)
        return FALSE;
    if (x >= 32)
        return FALSE;

    if (x < 0)
    {
        *leftMove = x * -1;
        *newX = 0;
        *newWidth = width + x;
    }
    else
    {
        *leftMove = 0;
        *newX = x;
        if (x + width >= 32)
            *newWidth = 32 - x;
        else
            *newWidth = width;

    }
    return TRUE;
}

static void MoveAndBufferPartySlot(const void *rectSrc, s16 x, s16 y, s16 width, s16 height, s16 dir)
{
    u8 srcX, newX, newWidth;

    if (TryMovePartySlot(x, width, &srcX, &newX, &newWidth))
    {
        FillBgTilemapBufferRect_Palette0(0, 0, newX, y, newWidth, height);
        if (TryMovePartySlot(x + dir, width, &srcX, &newX, &newWidth))
            CopyRectToBgTilemapBufferRect(0, rectSrc, srcX, 0, width, height, newX, y, newWidth, height, 17, 0, 0);
    }
}

static void MovePartyMenuBoxSprites(struct PartyMenuBox *menuBox, s16 offset)
{
    gSprites[menuBox->pokeballSpriteId].x2 += offset * 8;
    gSprites[menuBox->itemSpriteId].x2 += offset * 8;
    gSprites[menuBox->monSpriteId].x2 += offset * 8;
    gSprites[menuBox->statusSpriteId].x2 += offset * 8;
}

static void SlidePartyMenuBoxSpritesOneStep(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tSlot1SlideDir != 0)
        MovePartyMenuBoxSprites(&sPartyMenuBoxes[gPartyMenu.slotId], tSlot1SlideDir);
    if (tSlot2SlideDir != 0)
        MovePartyMenuBoxSprites(&sPartyMenuBoxes[gPartyMenu.slotId2], tSlot2SlideDir);
}

static void SlidePartyMenuBoxOneStep(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tSlot1SlideDir != 0)
        MoveAndBufferPartySlot(sSlot1TilemapBuffer, tSlot1Left + tSlot1Offset, tSlot1Top, tSlot1Width, tSlot1Height, tSlot1SlideDir);
    if (tSlot2SlideDir != 0)
        MoveAndBufferPartySlot(sSlot2TilemapBuffer, tSlot2Left + tSlot2Offset, tSlot2Top, tSlot2Width, tSlot2Height, tSlot2SlideDir);
    ScheduleBgCopyTilemapToVram(0);
}

static void Task_SlideSelectedSlotsOffscreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 slidingSlotPositions[2];

    SlidePartyMenuBoxOneStep(taskId);
    SlidePartyMenuBoxSpritesOneStep(taskId);
    tSlot1Offset += tSlot1SlideDir;
    tSlot2Offset += tSlot2SlideDir;
    slidingSlotPositions[0] = tSlot1Left + tSlot1Offset;
    slidingSlotPositions[1] = tSlot2Left + tSlot2Offset;

    // Both slots have slid offscreen
    if (slidingSlotPositions[0] > 33 && slidingSlotPositions[1] > 33)
    {
        tSlot1SlideDir *= -1;
        tSlot2SlideDir *= -1;
        SwitchPartyMon();
        DisplayPartyPokemonData(gPartyMenu.slotId);
        DisplayPartyPokemonData(gPartyMenu.slotId2);
        PutWindowTilemap(sPartyMenuBoxes[gPartyMenu.slotId].windowId);
        PutWindowTilemap(sPartyMenuBoxes[gPartyMenu.slotId2].windowId);
        sub_08199954(0, sSlot1TilemapBuffer, tSlot1Left, tSlot1Top, tSlot1Width, tSlot1Height); // CopyToBufferFromBgTilemap
        sub_08199954(0, sSlot2TilemapBuffer, tSlot2Left, tSlot2Top, tSlot2Width, tSlot2Height); // CopyToBufferFromBgTilemap
        ClearWindowTilemap(sPartyMenuBoxes[gPartyMenu.slotId].windowId);
        ClearWindowTilemap(sPartyMenuBoxes[gPartyMenu.slotId2].windowId);
        gTasks[taskId].func = Task_SlideSelectedSlotsOnscreen;
    }
}

static void Task_SlideSelectedSlotsOnscreen(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    SlidePartyMenuBoxOneStep(taskId);
    SlidePartyMenuBoxSpritesOneStep(taskId);

    // Both slots have slid back onscreen
    if (tSlot1SlideDir == 0 && tSlot2SlideDir == 0)
    {
        PutWindowTilemap(sPartyMenuBoxes[gPartyMenu.slotId].windowId);
        PutWindowTilemap(sPartyMenuBoxes[gPartyMenu.slotId2].windowId);
        ScheduleBgCopyTilemapToVram(0);
        Free(sSlot1TilemapBuffer);
        Free(sSlot2TilemapBuffer);
        FinishTwoMonAction(taskId);
    }
    // Continue sliding
    else
    {
        tSlot1Offset += tSlot1SlideDir;
        tSlot2Offset += tSlot2SlideDir;
        if (tSlot1Offset == 0)
            tSlot1SlideDir = 0;
        if (tSlot2Offset == 0)
            tSlot2SlideDir = 0;
    }
}

static void SwitchMenuBoxSprites(u8 *spriteIdPtr1, u8 *spriteIdPtr2)
{
    u8 spriteIdBuffer = *spriteIdPtr1;
    u16 xBuffer1, yBuffer1, xBuffer2, yBuffer2;

    *spriteIdPtr1 = *spriteIdPtr2;
    *spriteIdPtr2 = spriteIdBuffer;
    xBuffer1 = gSprites[*spriteIdPtr1].x;
    yBuffer1 = gSprites[*spriteIdPtr1].y;
    xBuffer2 = gSprites[*spriteIdPtr1].x2;
    yBuffer2 = gSprites[*spriteIdPtr1].y2;
    gSprites[*spriteIdPtr1].x = gSprites[*spriteIdPtr2].x;
    gSprites[*spriteIdPtr1].y = gSprites[*spriteIdPtr2].y;
    gSprites[*spriteIdPtr1].x2 = gSprites[*spriteIdPtr2].x2;
    gSprites[*spriteIdPtr1].y2 = gSprites[*spriteIdPtr2].y2;
    gSprites[*spriteIdPtr2].x = xBuffer1;
    gSprites[*spriteIdPtr2].y = yBuffer1;
    gSprites[*spriteIdPtr2].x2 = xBuffer2;
    gSprites[*spriteIdPtr2].y2 = yBuffer2;
}

static void SwitchPartyMon(void)
{
    struct PartyMenuBox *menuBoxes[2];
    struct Pokemon *mon1, *mon2;
    struct Pokemon *monBuffer;

    menuBoxes[0] = &sPartyMenuBoxes[gPartyMenu.slotId];
    menuBoxes[1] = &sPartyMenuBoxes[gPartyMenu.slotId2];
    mon1 = &gPlayerParty[gPartyMenu.slotId];
    mon2 = &gPlayerParty[gPartyMenu.slotId2];
    monBuffer = Alloc(sizeof(struct Pokemon));
    *monBuffer = *mon1;
    *mon1 = *mon2;
    *mon2 = *monBuffer;
    Free(monBuffer);
    SwitchMenuBoxSprites(&menuBoxes[0]->pokeballSpriteId, &menuBoxes[1]->pokeballSpriteId);
    SwitchMenuBoxSprites(&menuBoxes[0]->itemSpriteId, &menuBoxes[1]->itemSpriteId);
    SwitchMenuBoxSprites(&menuBoxes[0]->monSpriteId, &menuBoxes[1]->monSpriteId);
    SwitchMenuBoxSprites(&menuBoxes[0]->statusSpriteId, &menuBoxes[1]->statusSpriteId);
}

// Finish switching mons or using Softboiled
static void FinishTwoMonAction(u8 taskId)
{
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    gPartyMenu.action = PARTY_ACTION_CHOOSE_MON;
    AnimatePartySlot(gPartyMenu.slotId, 0);
    gPartyMenu.slotId = gPartyMenu.slotId2;
    AnimatePartySlot(gPartyMenu.slotId2, 1);
    DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

#undef tSlot1Left
#undef tSlot1Top
#undef tSlot1Width
#undef tSlot1Height
#undef tSlot2Left
#undef tSlot2Top
#undef tSlot2Width
#undef tSlot2Height
#undef tSlot1Offset
#undef tSlot2Offset
#undef tSlot1SlideDir
#undef tSlot2SlideDir

static void CursorCb_Cancel1(u8 taskId)
{
    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    if (gPartyMenu.menuType == PARTY_MENU_TYPE_DAYCARE)
        DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON_2);
    else
        DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}

static void CursorCb_Item(u8 taskId)
{
    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    SetPartyMonSelectionActions(gPlayerParty, gPartyMenu.slotId, ACTIONS_ITEM);
    DisplaySelectionWindow(SELECTWINDOW_ITEM);
    DisplayPartyMenuStdMessage(PARTY_MSG_DO_WHAT_WITH_ITEM);
    gTasks[taskId].data[0] = 0xFF;
    gTasks[taskId].func = Task_HandleSelectionMenuInput;
}

static void CursorCb_Give(u8 taskId)
{
    PlaySE(SE_SELECT);
    sPartyMenuInternal->exitCallback = CB2_SelectBagItemToGive;
    Task_ClosePartyMenu(taskId);
}

static void CB2_SelectBagItemToGive(void)
{
    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE == FALSE)
        GoToBagMenu(ITEMMENULOCATION_PARTY, POCKETS_COUNT, CB2_GiveHoldItem);
    else
        sub_081C47A0(PYRAMIDBAG_LOC_PARTY, CB2_GiveHoldItem); // GoToBattlePyramidBagMenu
}

static void CB2_GiveHoldItem(void)
{
    if (gSpecialVar_ItemId == ITEM_NONE)
    {
        InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, gPartyMenu.action, TRUE, PARTY_MSG_NONE, Task_TryCreateSelectionWindow, gPartyMenu.exitCallback);
    }
    else
    {
        sPartyMenuItemId = GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_HELD_ITEM);

        // Already holding item
        if (sPartyMenuItemId != ITEM_NONE)
        {
            InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, gPartyMenu.action, TRUE, PARTY_MSG_NONE, Task_SwitchHoldItemsPrompt, gPartyMenu.exitCallback);
        }
        // Give mail
        else if (ItemIsMail(gSpecialVar_ItemId))
        {
            RemoveBagItem(gSpecialVar_ItemId, 1);
            GiveItemToMon(&gPlayerParty[gPartyMenu.slotId], gSpecialVar_ItemId);
            CB2_WriteMailToGiveMon();
        }
        // Give item
        else
        {
            InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, gPartyMenu.action, TRUE, PARTY_MSG_NONE, Task_GiveHoldItem, gPartyMenu.exitCallback);
        }
    }
}

static void Task_GiveHoldItem(u8 taskId)
{
    u16 item;

    if (!gPaletteFade.active)
    {
        item = gSpecialVar_ItemId;
        DisplayGaveHeldItemMessage(&gPlayerParty[gPartyMenu.slotId], item, FALSE, 0);
        GiveItemToMon(&gPlayerParty[gPartyMenu.slotId], item);
        RemoveBagItem(item, 1);
        gTasks[taskId].func = Task_UpdateHeldItemSprite;
    }
}

static void Task_SwitchHoldItemsPrompt(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DisplayAlreadyHoldingItemSwitchMessage(&gPlayerParty[gPartyMenu.slotId], sPartyMenuItemId, TRUE);
        gTasks[taskId].func = Task_SwitchItemsYesNo;
    }
}

static void Task_SwitchItemsYesNo(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        sub_081B2FDC(); // PartyMenuDisplayYesNoMenu
        gTasks[taskId].func = Task_HandleSwitchItemsYesNoInput;
    }
}

static void Task_HandleSwitchItemsYesNoInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes, switch items
        RemoveBagItem(gSpecialVar_ItemId, 1);

        // No room to return held item to bag
        if (AddBagItem(sPartyMenuItemId, 1) == FALSE)
        {
            AddBagItem(gSpecialVar_ItemId, 1);
            BufferBagFullCantTakeItemMessage(sPartyMenuItemId);
            DisplayPartyMenuMessage(gStringVar4, FALSE);
            gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
        }
        // Giving mail
        else if (ItemIsMail(gSpecialVar_ItemId))
        {
            GiveItemToMon(&gPlayerParty[gPartyMenu.slotId], gSpecialVar_ItemId);
            gTasks[taskId].func = Task_WriteMailToGiveMonAfterText;
        }
        // Giving item
        else
        {
            GiveItemToMon(&gPlayerParty[gPartyMenu.slotId], gSpecialVar_ItemId);
            DisplaySwitchedHeldItemMessage(gSpecialVar_ItemId, sPartyMenuItemId, TRUE);
            gTasks[taskId].func = Task_UpdateHeldItemSprite;
        }
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1: // No
        gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
        break;
    }
}

static void Task_WriteMailToGiveMonAfterText(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        sPartyMenuInternal->exitCallback = CB2_WriteMailToGiveMon;
        Task_ClosePartyMenu(taskId);
    }
}

static void CB2_WriteMailToGiveMon(void)
{
    u8 mail = GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_MAIL);

    DoEasyChatScreen(
        EASY_CHAT_TYPE_MAIL,
        gSaveBlock1Ptr->mail[mail].words,
        CB2_ReturnToPartyMenuFromWritingMail,
        EASY_CHAT_PERSON_DISPLAY_NONE);
}

static void CB2_ReturnToPartyMenuFromWritingMail(void)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    // Canceled writing mail
    if (gSpecialVar_Result == FALSE)
    {
        TakeMailFromMon(mon);
        SetMonData(mon, MON_DATA_HELD_ITEM, &sPartyMenuItemId);
        RemoveBagItem(sPartyMenuItemId, 1);
        AddBagItem(item, 1);
        InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, gPartyMenu.action, TRUE, PARTY_MSG_CHOOSE_MON, Task_TryCreateSelectionWindow, gPartyMenu.exitCallback);
    }
    // Wrote mail
    else
    {
        InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, gPartyMenu.action, TRUE, PARTY_MSG_NONE, Task_DisplayGaveMailFromPartyMessage, gPartyMenu.exitCallback);
    }
}

// Nearly redundant with Task_DisplayGaveMailFromBagMessgae
static void Task_DisplayGaveMailFromPartyMessage(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sPartyMenuItemId == ITEM_NONE)
            DisplayGaveHeldItemMessage(&gPlayerParty[gPartyMenu.slotId], gSpecialVar_ItemId, FALSE, 0);
        else
            DisplaySwitchedHeldItemMessage(gSpecialVar_ItemId, sPartyMenuItemId, FALSE);
        gTasks[taskId].func = Task_UpdateHeldItemSprite;
    }
}

static void Task_UpdateHeldItemSprite(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];

    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        UpdatePartyMonHeldItemSprite(mon, &sPartyMenuBoxes[gPartyMenu.slotId]);
        if (gPartyMenu.menuType == PARTY_MENU_TYPE_STORE_PYRAMID_HELD_ITEMS)
        {
            if (GetMonData(mon, MON_DATA_HELD_ITEM) != ITEM_NONE)
                DisplayPartyPokemonDescriptionText(PARTYBOX_DESC_HAVE, &sPartyMenuBoxes[gPartyMenu.slotId], 1);
            else
                DisplayPartyPokemonDescriptionText(PARTYBOX_DESC_DONT_HAVE, &sPartyMenuBoxes[gPartyMenu.slotId], 1);
        }
        Task_ReturnToChooseMonAfterText(taskId);
    }
}

static void CursorCb_TakeItem(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    switch (TryTakeMonItem(mon))
    {
    case 0: // Not holding item
        GetMonNickname(mon, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x4F0); // gText_PkmnNotHolding
        DisplayPartyMenuMessage(gStringVar4, TRUE);
        break;
    case 1: // No room to take item
        BufferBagFullCantTakeItemMessage(item);
        DisplayPartyMenuMessage(gStringVar4, TRUE);
        break;
    default: // Took item
        DisplayTookHeldItemMessage(mon, item, TRUE);
        break;
    }
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_UpdateHeldItemSprite;
}

static void CursorCb_Toss(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    if (item == ITEM_NONE)
    {
        GetMonNickname(mon, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x4F0); // gText_PkmnNotHolding
        DisplayPartyMenuMessage(gStringVar4, TRUE);
        gTasks[taskId].func = Task_UpdateHeldItemSprite;
    }
    else
    {
        CopyItemName(item, gStringVar1);
        StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x84A); // gText_ThrowAwayItem
        DisplayPartyMenuMessage(gStringVar4, TRUE);
        gTasks[taskId].func = Task_TossHeldItemYesNo;
    }
}

static void Task_TossHeldItemYesNo(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        sub_081B2FDC(); // PartyMenuDisplayYesNoMenu
        gTasks[taskId].func = Task_HandleTossHeldItemYesNoInput;
    }
}

static void Task_HandleTossHeldItemYesNoInput(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0:
        CopyItemName(GetMonData(mon, MON_DATA_HELD_ITEM), gStringVar1);
        StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x85B); // gText_ItemThrownAway
        DisplayPartyMenuMessage(gStringVar4, FALSE);
        gTasks[taskId].func = Task_TossHeldItem;
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1:
        gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
        break;
    }
}

static void Task_TossHeldItem(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];

    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        u16 item = ITEM_NONE;

        SetMonData(mon, MON_DATA_HELD_ITEM, &item);
        UpdatePartyMonHeldItemSprite(mon, &sPartyMenuBoxes[gPartyMenu.slotId]);
        DisplayPartyPokemonDescriptionText(PARTYBOX_DESC_DONT_HAVE, &sPartyMenuBoxes[gPartyMenu.slotId], 1);
        gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
    }
}

static void CursorCb_Mail(u8 taskId)
{
    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    SetPartyMonSelectionActions(gPlayerParty, gPartyMenu.slotId, ACTIONS_MAIL);
    DisplaySelectionWindow(SELECTWINDOW_MAIL);
    DisplayPartyMenuStdMessage(PARTY_MSG_DO_WHAT_WITH_MAIL);
    gTasks[taskId].data[0] = 0xFF;
    gTasks[taskId].func = Task_HandleSelectionMenuInput;
}


static void CursorCb_Read(u8 taskId)
{
    PlaySE(SE_SELECT);
    sPartyMenuInternal->exitCallback = CB2_ReadHeldMail;
    Task_ClosePartyMenu(taskId);
}


static void CB2_ReadHeldMail(void)
{
    ReadMail(&gSaveBlock1Ptr->mail[GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_MAIL)], CB2_ReturnToPartyMenuFromReadingMail, TRUE);
}

static void CB2_ReturnToPartyMenuFromReadingMail(void)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    InitPartyMenu(gPartyMenu.menuType, KEEP_PARTY_LAYOUT, gPartyMenu.action, TRUE, PARTY_MSG_DO_WHAT_WITH_MON, Task_TryCreateSelectionWindow, gPartyMenu.exitCallback);
}

static void CursorCb_TakeMail(u8 taskId)
{
    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    DisplayPartyMenuMessage(gUnknown_85C97BD + 0x434, TRUE); // gText_SendMailToPC
    gTasks[taskId].func = Task_SendMailToPCYesNo;
}

static void Task_SendMailToPCYesNo(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        sub_081B2FDC(); // PartyMenuDisplayYesNoMenu
        gTasks[taskId].func = Task_HandleSendMailToPCYesNoInput;
    }
}

static void Task_HandleSendMailToPCYesNoInput(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes, send to PC
        if (TakeMailFromMonAndSave(&gPlayerParty[gPartyMenu.slotId]) != MAIL_NONE)
        {
            DisplayPartyMenuMessage(gUnknown_85C97BD + 0x44D, FALSE); // gText_MailSentToPC
            gTasks[taskId].func = Task_UpdateHeldItemSprite;
        }
        else
        {
            DisplayPartyMenuMessage(gUnknown_85C97BD + 0x463, FALSE); // gText_PCMailboxFull
            gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
        }
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1:
        DisplayPartyMenuMessage(gUnknown_85C97BD + 0x47C, TRUE); // gText_MailMessageWillBeLost
        gTasks[taskId].func = Task_LoseMailMessageYesNo;
        break;
    }
}

static void Task_LoseMailMessageYesNo(u8 taskId)
{
    if (IsPartyMenuTextPrinterActive() != TRUE)
    {
        sub_081B2FDC(); // PartyMenuDisplayYesNoMenu
        gTasks[taskId].func = Task_HandleLoseMailMessageYesNoInput;
    }
}

static void Task_HandleLoseMailMessageYesNoInput(u8 taskId)
{
    u16 item;

    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes, lose mail message
        item = GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_HELD_ITEM);
        if (AddBagItem(item, 1) == TRUE)
        {
            TakeMailFromMon(&gPlayerParty[gPartyMenu.slotId]);
            DisplayPartyMenuMessage(gUnknown_85C97BD + 0x51D, FALSE); // gText_MailTakenFromPkmn
            gTasks[taskId].func = Task_UpdateHeldItemSprite;
        }
        else
        {
            BufferBagFullCantTakeItemMessage(item);
            DisplayPartyMenuMessage(gStringVar4, FALSE);
            gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
        }
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        // fallthrough
    case 1:
        gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
        break;
    }
}

static void CursorCb_Cancel2(u8 taskId)
{
    struct Pokemon *mon = &gPlayerParty[gPartyMenu.slotId];

    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    SetPartyMonSelectionActions(gPlayerParty, gPartyMenu.slotId, GetPartyMenuActionsType(mon));
    if (gPartyMenu.menuType != PARTY_MENU_TYPE_STORE_PYRAMID_HELD_ITEMS)
    {
        DisplaySelectionWindow(SELECTWINDOW_ACTIONS);
        DisplayPartyMenuStdMessage(PARTY_MSG_DO_WHAT_WITH_MON);
    }
    else
    {
        DisplaySelectionWindow(SELECTWINDOW_ITEM);
        CopyItemName(GetMonData(mon, MON_DATA_HELD_ITEM), gStringVar2);
        DisplayPartyMenuStdMessage(PARTY_MSG_ALREADY_HOLDING_ONE);
    }
    gTasks[taskId].data[0] = 0xFF;
    gTasks[taskId].func = Task_HandleSelectionMenuInput;
}

static void CursorCb_SendMon(u8 taskId)
{
    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    if ((u8)TrySwitchInPokemon() == TRUE)
    {
        Task_ClosePartyMenu(taskId);
    }
    else
    {
        PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
        DisplayPartyMenuMessage(gStringVar4, TRUE);
        gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
    }
}


static void CursorCb_Enter(u8 taskId)
{
    u8 maxBattlers;
    u8 i;

    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    maxBattlers = GetMaxBattleEntries();
    for (i = 0; i < maxBattlers; i++)
    {
        if (gSelectedOrderFromParty[i] == 0)
        {
            PlaySE(SE_SELECT);
            gSelectedOrderFromParty[i] = gPartyMenu.slotId + 1;
            DisplayPartyPokemonDescriptionText(i + PARTYBOX_DESC_FIRST, &sPartyMenuBoxes[gPartyMenu.slotId], 1);
            if (i == (maxBattlers - 1))
                MoveCursorToConfirm();
            DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
            gTasks[taskId].func = Task_HandleChooseMonInput;
            return;
        }
    }
    ConvertIntToDecimalStringN(gStringVar1, maxBattlers, STR_CONV_MODE_LEFT_ALIGN, 1);
    StringExpandPlaceholders(gStringVar4, gUnknown_85C97BD + 0x418);
    PlaySE(SE_FAILURE);
    DisplayPartyMenuMessage(gStringVar4, TRUE);
    gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
}


static void MoveCursorToConfirm(void)
{
    AnimatePartySlot(gPartyMenu.slotId, 0);
    gPartyMenu.slotId = PARTY_SIZE;
    AnimatePartySlot(gPartyMenu.slotId, 1);
}

static void CursorCb_NoEntry(u8 taskId)
{
    u8 maxBattlers;
    u8 i, j;

    PlaySE(SE_SELECT);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    maxBattlers = GetMaxBattleEntries();
    for (i = 0; i < maxBattlers; i++)
    {
        if (gSelectedOrderFromParty[i] == (gPartyMenu.slotId + 1))
        {
            for (j = i; j < (maxBattlers - 1); j++)
                gSelectedOrderFromParty[j] = gSelectedOrderFromParty[j + 1];
            gSelectedOrderFromParty[j] = 0;
            break;
        }
    }
    DisplayPartyPokemonDescriptionText(PARTYBOX_DESC_ABLE_3, &sPartyMenuBoxes[gPartyMenu.slotId], 1);
    for (i = 0; i < (maxBattlers - 1); i++)
    {
        if (gSelectedOrderFromParty[i] != 0)
            DisplayPartyPokemonDescriptionText(i + PARTYBOX_DESC_FIRST, &sPartyMenuBoxes[gSelectedOrderFromParty[i] - 1], 1);
    }
    DisplayPartyMenuStdMessage(PARTY_MSG_CHOOSE_MON);
    gTasks[taskId].func = Task_HandleChooseMonInput;
}


__attribute__((naked)) void Task_ClosePartyMenu(u8 taskId);

static void CursorCb_Store(u8 taskId)
{
    PlaySE(SE_SELECT);
    Task_ClosePartyMenu(taskId);
}

extern const u8 gUnknown_85CA2B4[];
extern const u8 gUnknown_85CA2CC[];
extern const u8 gUnknown_85CA294[];
extern const u8 gUnknown_85CA276[];

static void CursorCb_Register(u8 taskId)
{
    u16 species2 = GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_SPECIES_OR_EGG);
    u16 species = GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_SPECIES);
    u8 isModernFatefulEncounter = GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_MODERN_FATEFUL_ENCOUNTER);

    switch (CanRegisterMonForTradingBoard(*(struct RfuGameCompatibilityData *)GetHostRfuGameData(), species2, species, isModernFatefulEncounter))
    {
    case CANT_REGISTER_MON:
        StringExpandPlaceholders(gStringVar4, gUnknown_85CA2B4);
        break;
    case CANT_REGISTER_EGG:
        StringExpandPlaceholders(gStringVar4, gUnknown_85CA2CC);
        break;
    default:
        PlaySE(SE_SELECT);
        Task_ClosePartyMenu(taskId);
        return;
    }
    PlaySE(SE_FAILURE);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    StringAppend(gStringVar4, gUnknown_85C97BD + 0xAB6);
    DisplayPartyMenuMessage(gStringVar4, TRUE);
    gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
}

__attribute__((naked)) void CursorCb_Trade1(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r0, _081B4F3C\n\t"
        "	mov r8, r0\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	movs r6, #0x64\n\t"
        "	muls r0, r6, r0\n\t"
        "	ldr r4, _081B4F40\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	mov sb, r0\n\t"
        "	mov r1, sb\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	mov sb, r1\n\t"
        "	mov r1, r8\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	muls r0, r6, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	mov r1, r8\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	muls r0, r6, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x50\n\t"
        "	bl GetMonData3\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl GetHostRfuGameData\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _081B4F44\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r2, _081B4F48\n\t"
        "	ldrh r3, [r2]\n\t"
        "	ldr r2, _081B4F4C\n\t"
        "	ldrb r2, [r2]\n\t"
        "	str r2, [sp]\n\t"
        "	str r5, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	mov r2, sb\n\t"
        "	bl sub_0807A250\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B4F68\n\t"
        "	ldr r5, _081B4F50\n\t"
        "	ldr r1, _081B4F54\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	movs r0, #0x20\n\t"
        "	bl PlaySE\n\t"
        "	ldr r4, _081B4F58\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0xc\n\t"
        "	bl PartyMenuRemoveWindow\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0xd\n\t"
        "	bl PartyMenuRemoveWindow\n\t"
        "	ldr r1, _081B4F5C\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StringAppend\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	ldr r1, _081B4F60\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B4F64\n\t"
        "	str r1, [r0]\n\t"
        "	b _081B4F74\n\t"
        "	.align 2, 0\n\t"
        "_081B4F3C: .4byte gPartyMenu\n\t"
        "_081B4F40: .4byte gPlayerParty\n\t"
        "_081B4F44: .4byte gRfuPartnerCompatibilityData\n\t"
        "_081B4F48: .4byte gUnionRoomOfferedSpecies\n\t"
        "_081B4F4C: .4byte gUnionRoomRequestedMonType\n\t"
        "_081B4F50: .4byte gStringVar4\n\t"
        "_081B4F54: .4byte gUnknown_85E16C4\n\t"
        "_081B4F58: .4byte sPartyMenuInternal\n\t"
        "_081B4F5C: .4byte gUnknown_85C97BD + 0xAB6\n\t"
        "_081B4F60: .4byte gTasks\n\t"
        "_081B4F64: .4byte Task_ReturnToChooseMonAfterText + 1\n\t"
        "_081B4F68:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "_081B4F74:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

static void CursorCb_Trade2(u8 taskId)
{
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[0]);
    PartyMenuRemoveWindow(&sPartyMenuInternal->windowId[1]);
    switch (CanSpinTradeMon(gPlayerParty, gPartyMenu.slotId))
    {
    case CANT_TRADE_LAST_MON:
        StringExpandPlaceholders(gStringVar4, gUnknown_85CA294);
        break;
    case CANT_TRADE_NATIONAL:
        StringExpandPlaceholders(gStringVar4, gUnknown_85CA2B4);
        break;
    case CANT_TRADE_EGG_YET:
        StringExpandPlaceholders(gStringVar4, gUnknown_85CA2CC);
        break;
    default: // CAN_TRADE_MON
        PlaySE(SE_SELECT);
        GetMonNickname(&gPlayerParty[gPartyMenu.slotId], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gUnknown_85CA276);
        DisplayPartyMenuMessage(gStringVar4, TRUE);
        gTasks[taskId].func = Task_SpinTradeYesNo;
        return;
    }
    PlaySE(SE_FAILURE);
    StringAppend(gStringVar4, gUnknown_85C97BD + 0xAB6);
    DisplayPartyMenuMessage(gStringVar4, TRUE);
    gTasks[taskId].func = Task_ReturnToChooseMonAfterText;
}


__attribute__((naked)) void Task_SpinTradeYesNo(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B50C0\n\t"
        "	bl sub_081B2FDC\n\t"
        "	ldr r0, _081B50C8\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B50CC\n\t"
        "	str r0, [r1]\n\t"
        "_081B50C0:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B50C8: .4byte gTasks\n\t"
        "_081B50CC: .4byte sub_081B50D0 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B50D0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl Menu_ProcessInputNoWrapClearOnChoose\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r1, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B50F6\n\t"
        "	cmp r1, #0\n\t"
        "	bgt _081B50F0\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r1, r0\n\t"
        "	beq _081B50FE\n\t"
        "	b _081B510A\n\t"
        "_081B50F0:\n\t"
        "	cmp r1, #1\n\t"
        "	beq _081B5104\n\t"
        "	b _081B510A\n\t"
        "_081B50F6:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "	b _081B510A\n\t"
        "_081B50FE:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "_081B5104:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Task_ReturnToChooseMonAfterText\n\t"
        "_081B510A:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CursorCb_FieldMove(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	bl Menu_GetCursorPos\n\t"
        "	ldr r5, _081B517C\n\t"
        "	ldr r1, [r5]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, #0xf\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	subs r0, #0x13\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r1, _081B5180\n\t"
        "	lsls r0, r4, #3\n\t"
        "	adds r7, r0, r1\n\t"
        "	ldr r0, [r7]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B5142\n\t"
        "	b _081B5304\n\t"
        "_081B5142:\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0xc\n\t"
        "	bl PartyMenuRemoveWindow\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0xd\n\t"
        "	bl PartyMenuRemoveWindow\n\t"
        "	bl sub_081221B8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B5166\n\t"
        "	bl InUnionRoom\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B5188\n\t"
        "_081B5166:\n\t"
        "	adds r0, r4, #0\n\t"
        "	subs r0, #0xb\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _081B5184\n\t"
        "	movs r0, #0xd\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "	b _081B52F6\n\t"
        "	.align 2, 0\n\t"
        "_081B517C: .4byte sPartyMenuInternal\n\t"
        "_081B5180: .4byte gUnknown_85E1654\n\t"
        "_081B5184:\n\t"
        "	ldrb r0, [r7, #4]\n\t"
        "	b _081B52F2\n\t"
        "_081B5188:\n\t"
        "	cmp r4, #7\n\t"
        "	bhi _081B51C4\n\t"
        "	ldr r1, _081B51B4\n\t"
        "	adds r0, r4, r1\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B51C4\n\t"
        "	ldr r0, _081B51B8\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	ldr r1, _081B51BC\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B51C0\n\t"
        "	str r1, [r0]\n\t"
        "	b _081B5304\n\t"
        "	.align 2, 0\n\t"
        "_081B51B4: .4byte 0x00000867\n\t"
        "_081B51B8: .4byte gUnknown_85C97BD + 0x3FA\n\t"
        "_081B51BC: .4byte gTasks\n\t"
        "_081B51C0: .4byte Task_ReturnToChooseMonAfterText + 1\n\t"
        "_081B51C4:\n\t"
        "	ldr r1, _081B51EC\n\t"
        "	lsls r0, r4, #3\n\t"
        "	adds r5, r0, r1\n\t"
        "	ldr r0, [r5]\n\t"
        "	bl _call_via_r0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B51DA\n\t"
        "	b _081B52DC\n\t"
        "_081B51DA:\n\t"
        "	subs r0, r4, #5\n\t"
        "	cmp r0, #7\n\t"
        "	bhi _081B52C4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B51F0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081B51EC: .4byte gUnknown_85E1654\n\t"
        "_081B51F0: .4byte 0x081B51F4\n\t"
        "_081B51F4: @ jump table\n\t"
        "	.4byte _081B52B4 @ case 0\n\t"
        "	.4byte _081B52C4 @ case 1\n\t"
        "	.4byte _081B52C4 @ case 2\n\t"
        "	.4byte _081B521C @ case 3\n\t"
        "	.4byte _081B5258 @ case 4\n\t"
        "	.4byte _081B52C4 @ case 5\n\t"
        "	.4byte _081B5214 @ case 6\n\t"
        "	.4byte _081B5214 @ case 7\n\t"
        "_081B5214:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl ChooseMonForSoftboiled\n\t"
        "	b _081B5304\n\t"
        "_081B521C:\n\t"
        "	ldr r0, _081B5248\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x1c\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldrb r1, [r1, #0x1d]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	asrs r1, r1, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	bl Overworld_GetMapHeaderByGroupAndId\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldr r0, _081B524C\n\t"
        "	ldrb r1, [r1, #0x14]\n\t"
        "	bl sub_081245E8\n\t"
        "	ldr r0, _081B5250\n\t"
        "	ldr r1, _081B5254\n\t"
        "	b _081B5288\n\t"
        "	.align 2, 0\n\t"
        "_081B5248: .4byte gSaveBlock1Ptr\n\t"
        "_081B524C: .4byte gStringVar1\n\t"
        "_081B5250: .4byte gStringVar4\n\t"
        "_081B5254: .4byte gUnknown_85C97BD + 0xA9F\n\t"
        "_081B5258:\n\t"
        "	ldr r0, _081B52A0\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x24\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	adds r1, #0x25\n\t"
        "	ldrb r1, [r1]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	asrs r1, r1, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	bl Overworld_GetMapHeaderByGroupAndId\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldr r0, _081B52A4\n\t"
        "	ldrb r1, [r1, #0x14]\n\t"
        "	bl sub_081245E8\n\t"
        "	ldr r0, _081B52A8\n\t"
        "	ldr r1, _081B52AC\n\t"
        "_081B5288:\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_081B5314\n\t"
        "	ldr r0, _081B52B0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x86\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r4, [r0]\n\t"
        "	b _081B5304\n\t"
        "	.align 2, 0\n\t"
        "_081B52A0: .4byte gSaveBlock1Ptr\n\t"
        "_081B52A4: .4byte gStringVar1\n\t"
        "_081B52A8: .4byte gStringVar4\n\t"
        "_081B52AC: .4byte gUnknown_85C97BD + 0xA89\n\t"
        "_081B52B0: .4byte sPartyMenuInternal\n\t"
        "_081B52B4:\n\t"
        "	ldr r1, _081B52BC\n\t"
        "	ldr r0, _081B52C0\n\t"
        "	b _081B52C8\n\t"
        "	.align 2, 0\n\t"
        "_081B52BC: .4byte gPartyMenu\n\t"
        "_081B52C0: .4byte MCB2_FlyMap + 1\n\t"
        "_081B52C4:\n\t"
        "	ldr r1, _081B52D4\n\t"
        "	ldr r0, _081B52D8\n\t"
        "_081B52C8:\n\t"
        "	str r0, [r1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "	b _081B5304\n\t"
        "	.align 2, 0\n\t"
        "_081B52D4: .4byte gPartyMenu\n\t"
        "_081B52D8: .4byte CB2_ReturnToField + 1\n\t"
        "_081B52DC:\n\t"
        "	cmp r4, #1\n\t"
        "	beq _081B52EA\n\t"
        "	cmp r4, #4\n\t"
        "	bne _081B52F0\n\t"
        "	bl DisplayCantUseSurfMessage\n\t"
        "	b _081B52F6\n\t"
        "_081B52EA:\n\t"
        "	bl sub_081B547C\n\t"
        "	b _081B52F6\n\t"
        "_081B52F0:\n\t"
        "	ldrb r0, [r5, #4]\n\t"
        "_081B52F2:\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "_081B52F6:\n\t"
        "	ldr r0, _081B530C\n\t"
        "	lsls r1, r6, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B5310\n\t"
        "	str r0, [r1]\n\t"
        "_081B5304:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B530C: .4byte gTasks\n\t"
        "_081B5310: .4byte task_brm_cancel_1_on_keypad_a_or_b + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B5314(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _081B5338\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	ldr r1, _081B533C\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B5340\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5338: .4byte gStringVar4\n\t"
        "_081B533C: .4byte gTasks\n\t"
        "_081B5340: .4byte sub_081B5344 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B5344(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B5368\n\t"
        "	bl sub_081B2FDC\n\t"
        "	ldr r0, _081B5370\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B5374\n\t"
        "	str r0, [r1]\n\t"
        "_081B5368:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5370: .4byte gTasks\n\t"
        "_081B5374: .4byte sub_081B5378 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B5378(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl Menu_ProcessInputNoWrapClearOnChoose\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r1, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B539E\n\t"
        "	cmp r1, #0\n\t"
        "	bgt _081B5398\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r1, r0\n\t"
        "	beq _081B53B4\n\t"
        "	b _081B53CA\n\t"
        "_081B5398:\n\t"
        "	cmp r1, #1\n\t"
        "	beq _081B53BA\n\t"
        "	b _081B53CA\n\t"
        "_081B539E:\n\t"
        "	ldr r1, _081B53AC\n\t"
        "	ldr r0, _081B53B0\n\t"
        "	str r0, [r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "	b _081B53CA\n\t"
        "	.align 2, 0\n\t"
        "_081B53AC: .4byte gPartyMenu\n\t"
        "_081B53B0: .4byte CB2_ReturnToField + 1\n\t"
        "_081B53B4:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "_081B53BA:\n\t"
        "	ldr r0, _081B53D0\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r0, _081B53D4\n\t"
        "	str r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Task_ReturnToChooseMonAfterText\n\t"
        "_081B53CA:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B53D0: .4byte gFieldCallback2\n\t"
        "_081B53D4: .4byte gPostMenuFieldCallback\n\t"
        ".syntax divided\n\t"
    );
}

bool8 FieldCallback_PrepareFadeInFromMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_FieldMoveWaitForFade, 8);
    return TRUE;
}

__attribute__((naked)) void Task_FieldMoveWaitForFade(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsWeatherNotFadingIn\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B541C\n\t"
        "	bl brm_get_selected_species\n\t"
        "	ldr r1, _081B5424\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _081B5428\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl _call_via_r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_081B541C:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5424: .4byte gFieldEffectArguments\n\t"
        "_081B5428: .4byte gPostMenuFieldCallback\n\t"
        ".syntax divided\n\t"
    );
}

u16 brm_get_selected_species(void)
{
    return GetMonData(&gPlayerParty[gPartyMenu.slotId], MON_DATA_SPECIES);
}

__attribute__((naked)) void task_brm_cancel_1_on_keypad_a_or_b(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	ldr r0, _081B5478\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B546E\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5474\n\t"
        "_081B546E:\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl CursorCb_Cancel1\n\t"
        "_081B5474:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5478: .4byte gMain\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B547C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _081B5494\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B5498\n\t"
        "	movs r0, #0xc\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "	b _081B549E\n\t"
        "	.align 2, 0\n\t"
        "_081B5494: .4byte 0x00000888\n\t"
        "_081B5498:\n\t"
        "	movs r0, #0xd\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "_081B549E:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

static void FieldCallback_Surf(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_SURF);
}


static bool8 SetUpFieldMove_Surf(void)
{
    if ((u8)PartyHasMonWithSurf() == TRUE && (u8)IsPlayerFacingSurfableFishableWater() == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Surf;
        return TRUE;
    }
    return FALSE;
}

static void DisplayCantUseSurfMessage(void)
{
    if ((u8)TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        DisplayPartyMenuStdMessage(PARTY_MSG_ALREADY_SURFING);
    else
        DisplayPartyMenuStdMessage(PARTY_MSG_CANT_SURF_HERE);
}

static bool8 SetUpFieldMove_Fly(void)
{
    if ((u8)Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) == TRUE)
        return TRUE;
    else
        return FALSE;
}


__attribute__((naked)) void sub_081B5548(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B556C\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B5570\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B556C: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B5570: .4byte CB2_ReturnToFieldWithOpenMenu + 1\n\t"
        ".syntax divided\n\t"
    );
}

static void FieldCallback_Waterfall(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_WATERFALL);
}

static bool8 SetUpFieldMove_Waterfall(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    if ((u8)MetatileBehavior_IsWaterfall((u8)MapGridGetMetatileBehaviorAt(x, y)) == TRUE && (u8)IsPlayerSurfingNorth() == TRUE)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Waterfall;
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_Dive(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    FieldEffectStart(FLDEFF_USE_DIVE);
}

static bool8 SetUpFieldMove_Dive(void)
{
    gFieldEffectArguments[1] = (u8)TrySetDiveWarp();
    if (gFieldEffectArguments[1] != 0)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Dive;
        return TRUE;
    }
    return FALSE;
}

__attribute__((naked)) void CreatePartyMonIconSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	adds r4, r2, #0\n\t"
        "	movs r6, #1\n\t"
        "	bl IsMultiBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B568A\n\t"
        "	ldr r0, _081B56C0\n\t"
        "	ldr r1, _081B56C4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B568A\n\t"
        "	ldr r0, _081B56C8\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldrb r1, [r0]\n\t"
        "	eors r1, r6\n\t"
        "	rsbs r0, r1, #0\n\t"
        "	orrs r0, r1\n\t"
        "	lsrs r6, r0, #0x1f\n\t"
        "_081B568A:\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl GetMonData3\n\t"
        "	adds r1, r0, #0\n\t"
        "	str r6, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r2, r7, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl CreatePartyMonIconSpriteParameterized\n\t"
        "	ldrb r0, [r7, #9]\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_081B57D8\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B56C0: .4byte gMain\n\t"
        "_081B56C4: .4byte 0x00000439\n\t"
        "_081B56C8: .4byte gUnknown_85E18D8\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreatePartyMonIconSpriteParameterized(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	adds r6, r1, #0\n\t"
        "	adds r4, r2, #0\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r7, r3, #0x18\n\t"
        "	cmp r5, #0\n\t"
        "	beq _081B571A\n\t"
        "	ldr r1, _081B5724\n\t"
        "	ldr r0, [r4, #4]\n\t"
        "	ldrb r2, [r0]\n\t"
        "	ldrb r3, [r0, #1]\n\t"
        "	movs r0, #4\n\t"
        "	str r0, [sp]\n\t"
        "	str r6, [sp, #4]\n\t"
        "	ldr r0, [sp, #0x20]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl CreateMonIcon\n\t"
        "	strb r0, [r4, #9]\n\t"
        "	ldr r2, _081B5728\n\t"
        "	ldrb r0, [r4, #9]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r0, #3\n\t"
        "	adds r2, r7, #0\n\t"
        "	ands r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldrb r3, [r1, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1, #5]\n\t"
        "_081B571A:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5724: .4byte SpriteCB_MonIcon + 1\n\t"
        "_081B5728: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B572C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl GetHPBarLevel\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #2\n\t"
        "	beq _081B578C\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _081B5754\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B57A4\n\t"
        "	b _081B57BC\n\t"
        "_081B5754:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _081B5774\n\t"
        "	cmp r0, #4\n\t"
        "	bne _081B57BC\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B5770\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	bl SetPartyHPBarSprite\n\t"
        "	b _081B57CC\n\t"
        "	.align 2, 0\n\t"
        "_081B5770: .4byte gSprites\n\t"
        "_081B5774:\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B5788\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	bl SetPartyHPBarSprite\n\t"
        "	b _081B57CC\n\t"
        "	.align 2, 0\n\t"
        "_081B5788: .4byte gSprites\n\t"
        "_081B578C:\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B57A0\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	bl SetPartyHPBarSprite\n\t"
        "	b _081B57CC\n\t"
        "	.align 2, 0\n\t"
        "_081B57A0: .4byte gSprites\n\t"
        "_081B57A4:\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B57B8\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #3\n\t"
        "	bl SetPartyHPBarSprite\n\t"
        "	b _081B57CC\n\t"
        "	.align 2, 0\n\t"
        "_081B57B8: .4byte gSprites\n\t"
        "_081B57BC:\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B57D4\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #4\n\t"
        "	bl SetPartyHPBarSprite\n\t"
        "_081B57CC:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B57D4: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B57D8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0x3a\n\t"
        "	bl GetMonData3\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl sub_081B572C\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void AnimateSelectedPartyIcon(u8 a, u8 b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	ldr r5, _081B583C\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r6, r0, #2\n\t"
        "	adds r2, r6, r5\n\t"
        "	movs r7, #0\n\t"
        "	movs r3, #0\n\t"
        "	strh r3, [r2, #0x2e]\n\t"
        "	mov ip, r5\n\t"
        "	cmp r1, #0\n\t"
        "	bne _081B5864\n\t"
        "	movs r1, #0x20\n\t"
        "	ldrsh r0, [r2, r1]\n\t"
        "	cmp r0, #0x18\n\t"
        "	bne _081B5844\n\t"
        "	strh r3, [r2, #0x24]\n\t"
        "	ldr r0, _081B5840\n\t"
        "	strh r0, [r2, #0x26]\n\t"
        "	b _081B584A\n\t"
        "	.align 2, 0\n\t"
        "_081B583C: .4byte gSprites\n\t"
        "_081B5840: .4byte 0x0000FFFC\n\t"
        "_081B5844:\n\t"
        "	ldr r0, _081B585C\n\t"
        "	strh r0, [r2, #0x24]\n\t"
        "	strh r3, [r2, #0x26]\n\t"
        "_081B584A:\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r1, ip\n\t"
        "	adds r1, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B5860\n\t"
        "	b _081B5870\n\t"
        "	.align 2, 0\n\t"
        "_081B585C: .4byte 0x0000FFFC\n\t"
        "_081B5860: .4byte UpdatePartyMonIconFrame + 1\n\t"
        "_081B5864:\n\t"
        "	strh r3, [r2, #0x24]\n\t"
        "	strh r3, [r2, #0x26]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x1c\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldr r1, _081B5878\n\t"
        "_081B5870:\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5878: .4byte UpdatePartyMonIconFrameAndBounce + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void UpdatePartyMonIconFrameAndBounce(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl UpdateMonIconFrame\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B58A2\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B58A0\n\t"
        "	ldr r0, _081B589C\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	b _081B58A2\n\t"
        "	.align 2, 0\n\t"
        "_081B589C: .4byte 0x0000FFFD\n\t"
        "_081B58A0:\n\t"
        "	strh r1, [r4, #0x26]\n\t"
        "_081B58A2:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

void UpdatePartyMonIconFrame(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

__attribute__((naked)) void CreatePartyMonHeldItemSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B58DC\n\t"
        "	ldr r0, _081B58E4\n\t"
        "	ldr r2, [r4, #4]\n\t"
        "	ldrb r1, [r2, #2]\n\t"
        "	ldrb r2, [r2, #3]\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	strb r0, [r4, #0xa]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl UpdatePartyMonHeldItemSprite\n\t"
        "_081B58DC:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B58E4: .4byte gUnknown_85E1778\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreatePartyMonHeldItemSpriteParameterized(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r2, #0\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r5, r1, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5924\n\t"
        "	ldr r0, _081B592C\n\t"
        "	ldr r2, [r4, #4]\n\t"
        "	ldrb r1, [r2, #2]\n\t"
        "	ldrb r2, [r2, #3]\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	strb r0, [r4, #0xa]\n\t"
        "	ldr r2, _081B5930\n\t"
        "	ldrb r0, [r4, #0xa]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r2, [r1, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl ShowOrHideHeldItemSprite\n\t"
        "_081B5924:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B592C: .4byte gUnknown_85E1778\n\t"
        "_081B5930: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

static void UpdatePartyMonHeldItemSprite(struct Pokemon *mon, struct PartyMenuBox *menuBox)
{
    ShowOrHideHeldItemSprite((u16)GetMonData3(mon, MON_DATA_HELD_ITEM), menuBox);
}

static void ShowOrHideHeldItemSprite(u16 item, struct PartyMenuBox *menuBox)
{
    if (item == ITEM_NONE)
    {
        gSprites[menuBox->itemSpriteId].invisible = TRUE;
    }
    else
    {
        if ((u8)ItemIsMail(item))
            StartSpriteAnim(&gSprites[menuBox->itemSpriteId], 1);
        else
            StartSpriteAnim(&gSprites[menuBox->itemSpriteId], 0);
        gSprites[menuBox->itemSpriteId].invisible = FALSE;
    }
}

extern const struct CompressedSpriteSheet gUnknown_85E1768;
extern const struct CompressedSpritePalette gUnknown_85E1770;

void LoadHeldItemIcons(void)
{
    LoadSpriteSheet(&gUnknown_85E1768);
    LoadSpritePalette(&gUnknown_85E1770);
}


__attribute__((naked)) void sub_081B59EC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	cmp r2, #0\n\t"
        "	beq _081B5A00\n\t"
        "	cmp r2, #1\n\t"
        "	beq _081B5A48\n\t"
        "	b _081B5A84\n\t"
        "_081B5A00:\n\t"
        "	movs r5, #0\n\t"
        "	ldrb r0, [r6]\n\t"
        "	cmp r5, r0\n\t"
        "	bhs _081B5A84\n\t"
        "_081B5A08:\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r5, r0\n\t"
        "	ldr r1, _081B5A44\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B5A34\n\t"
        "	adds r0, r7, r5\n\t"
        "	ldrb r4, [r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl ItemIsMail\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B5A90\n\t"
        "_081B5A34:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldrb r0, [r6]\n\t"
        "	cmp r5, r0\n\t"
        "	blo _081B5A08\n\t"
        "	b _081B5A84\n\t"
        "	.align 2, 0\n\t"
        "_081B5A44: .4byte gPlayerParty\n\t"
        "_081B5A48:\n\t"
        "	movs r5, #0\n\t"
        "	b _081B5A7E\n\t"
        "_081B5A4C:\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r5, r0\n\t"
        "	ldr r1, _081B5A8C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B5A78\n\t"
        "	adds r0, r5, r7\n\t"
        "	ldrb r4, [r0, #6]\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl ItemIsMail\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B5A90\n\t"
        "_081B5A78:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "_081B5A7E:\n\t"
        "	ldrb r0, [r6, #1]\n\t"
        "	cmp r5, r0\n\t"
        "	blo _081B5A4C\n\t"
        "_081B5A84:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5A8C: .4byte gEnemyParty\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B5A90(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6}\n\t"
        "	adds r6, r0, #0\n\t"
        "	mov sb, r1\n\t"
        "	lsls r6, r6, #0x18\n\t"
        "	lsrs r6, r6, #0x18\n\t"
        "	mov r0, sb\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	ldr r0, _081B5B08\n\t"
        "	mov r8, r0\n\t"
        "	lsls r0, r6, #4\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	adds r0, #0x43\n\t"
        "	ldrb r3, [r0]\n\t"
        "	ldr r0, _081B5B0C\n\t"
        "	subs r3, #1\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	movs r1, #0xfa\n\t"
        "	movs r2, #0xaa\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	mov r0, r8\n\t"
        "	adds r5, r4, r0\n\t"
        "	movs r0, #4\n\t"
        "	strh r0, [r5, #0x24]\n\t"
        "	movs r0, #0xa\n\t"
        "	strh r0, [r5, #0x26]\n\t"
        "	movs r0, #0x1c\n\t"
        "	add r8, r0\n\t"
        "	add r4, r8\n\t"
        "	ldr r0, _081B5B10\n\t"
        "	str r0, [r4]\n\t"
        "	strh r6, [r5, #0x3c]\n\t"
        "	adds r0, r5, #0\n\t"
        "	mov r1, sb\n\t"
        "	bl StartSpriteAnim\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl _call_via_r1\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5B08: .4byte gSprites\n\t"
        "_081B5B0C: .4byte gUnknown_85E1778\n\t"
        "_081B5B10: .4byte SpriteCB_HeldItem + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpriteCB_HeldItem(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r1, [r4, #0x3c]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r2, _081B5B44\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r2, r0, r2\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _081B5B48\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	b _081B5B66\n\t"
        "	.align 2, 0\n\t"
        "_081B5B44: .4byte gSprites\n\t"
        "_081B5B48:\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x3e\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	ldrh r0, [r2, #0x24]\n\t"
        "	ldrh r1, [r2, #0x20]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	ldrh r0, [r2, #0x26]\n\t"
        "	ldrh r2, [r2, #0x22]\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "_081B5B66:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreatePartyMonPokeballSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5B8A\n\t"
        "	ldr r0, _081B5B90\n\t"
        "	ldr r2, [r4, #4]\n\t"
        "	ldrb r1, [r2, #6]\n\t"
        "	ldrb r2, [r2, #7]\n\t"
        "	movs r3, #8\n\t"
        "	bl CreateSprite\n\t"
        "	strb r0, [r4, #0xb]\n\t"
        "_081B5B8A:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5B90: .4byte gUnknown_85E17C0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreatePartyMonPokeballSpriteParameterized(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5BC4\n\t"
        "	ldr r0, _081B5BCC\n\t"
        "	ldr r2, [r4, #4]\n\t"
        "	ldrb r1, [r2, #6]\n\t"
        "	ldrb r2, [r2, #7]\n\t"
        "	movs r3, #8\n\t"
        "	bl CreateSprite\n\t"
        "	strb r0, [r4, #0xb]\n\t"
        "	ldr r2, _081B5BD0\n\t"
        "	ldrb r0, [r4, #0xb]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r2, [r1, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #5]\n\t"
        "_081B5BC4:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5BCC: .4byte gUnknown_85E17C0\n\t"
        "_081B5BD0: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreatePokeballButtonSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r3, r0, #0\n\t"
        "	adds r2, r1, #0\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r0, _081B5C0C\n\t"
        "	adds r1, r3, #0\n\t"
        "	movs r3, #8\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _081B5C10\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r3, [r1, #5]\n\t"
        "	movs r2, #0xd\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	ands r2, r3\n\t"
        "	movs r3, #8\n\t"
        "	orrs r2, r3\n\t"
        "	strb r2, [r1, #5]\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B5C0C: .4byte gUnknown_85E17C0\n\t"
        "_081B5C10: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

extern const struct SpriteTemplate gUnknown_85E1830;

static u8 CreateSmallPokeballButtonSprite(u8 x, u8 y)
{
    return CreateSprite(&gUnknown_85E1830, x, y, 8);
}

static void PartyMenuStartSpriteAnim(u8 spriteId, u8 animNum)
{
    StartSpriteAnim(&gSprites[spriteId], animNum);
}

static void UNUSED SpriteCB_BounceConfirmCancelButton(u8 spriteId, u8 spriteId2, u8 animNum)
{
    if (animNum == 0)
    {
        StartSpriteAnim(&gSprites[spriteId], 2);
        StartSpriteAnim(&gSprites[spriteId2], 4);
        gSprites[spriteId].y2 = 0;
        gSprites[spriteId2].y2 = 0;
    }
    else
    {
        StartSpriteAnim(&gSprites[spriteId], 3);
        StartSpriteAnim(&gSprites[spriteId2], 5);
        gSprites[spriteId].y2 = -4;
        gSprites[spriteId2].y2 = 4;
    }
}


extern const struct CompressedSpriteSheet gUnknown_85E17B0;
extern const struct CompressedSpriteSheet gUnknown_85E1828;
extern const struct CompressedSpritePalette gUnknown_85E17B8;

static void LoadPartyMenuPokeballGfx(void)
{
    LoadCompressedSpriteSheet(&gUnknown_85E17B0);
    LoadCompressedSpriteSheet(&gUnknown_85E1828);
    LoadCompressedSpritePalette(&gUnknown_85E17B8);
}

__attribute__((naked)) void CreatePartyMonStatusSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5D2C\n\t"
        "	ldr r0, _081B5D34\n\t"
        "	ldr r2, [r4, #4]\n\t"
        "	ldrb r1, [r2, #4]\n\t"
        "	ldrb r2, [r2, #5]\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	strb r0, [r4, #0xc]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl party_menu_get_status_condition_and_update_object\n\t"
        "_081B5D2C:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5D34: .4byte gUnknown_85E18C0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreatePartyMonStatusSpriteParameterized(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r2, #0\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r5, r1, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5D74\n\t"
        "	ldr r0, _081B5D7C\n\t"
        "	ldr r2, [r4, #4]\n\t"
        "	ldrb r1, [r2, #4]\n\t"
        "	ldrb r2, [r2, #5]\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	strb r0, [r4, #0xc]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl party_menu_update_status_condition_object\n\t"
        "	ldr r2, _081B5D80\n\t"
        "	ldrb r0, [r4, #0xc]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r2, [r1, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #5]\n\t"
        "_081B5D74:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5D7C: .4byte gUnknown_85E18C0\n\t"
        "_081B5D80: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void party_menu_update_status_condition_object(u8 ailment, struct PartyMenuBox *box);

static void party_menu_get_status_condition_and_update_object(struct Pokemon *mon, struct PartyMenuBox *box)
{
    party_menu_update_status_condition_object(GetMonAilment(mon), box);
}

__attribute__((naked)) void party_menu_update_status_condition_object(u8 ailment, struct PartyMenuBox *box)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0\n\t"
        "	beq _081B5DAC\n\t"
        "	cmp r2, #6\n\t"
        "	bne _081B5DC8\n\t"
        "_081B5DAC:\n\t"
        "	ldr r2, _081B5DC4\n\t"
        "	ldrb r1, [r5, #0xc]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	b _081B5DF2\n\t"
        "	.align 2, 0\n\t"
        "_081B5DC4: .4byte gSprites\n\t"
        "_081B5DC8:\n\t"
        "	ldrb r1, [r5, #0xc]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r4, _081B5DFC\n\t"
        "	adds r0, r0, r4\n\t"
        "	subs r1, r2, #1\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	bl StartSpriteAnim\n\t"
        "	ldrb r1, [r5, #0xc]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #5\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "_081B5DF2:\n\t"
        "	strb r1, [r0]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5DFC: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

extern const struct CompressedSpriteSheet gUnknown_85E18B0;
extern const struct CompressedSpritePalette gUnknown_85E18B8;

static void LoadPartyMenuAilmentGfx(void)
{
    LoadCompressedSpriteSheet(&gUnknown_85E18B0);
    LoadCompressedSpritePalette(&gUnknown_85E18B8);
}

__attribute__((naked)) void sub_081B5E1C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r0, _081B5E44\n\t"
        "	mov r8, r0\n\t"
        "	ldr r0, _081B5E48\n\t"
        "	ldr r1, _081B5E4C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5E5C\n\t"
        "	movs r7, #1\n\t"
        "	bl sub_081B8624\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	b _081B5E60\n\t"
        "	.align 2, 0\n\t"
        "_081B5E44: .4byte c2_815ABFC + 1\n\t"
        "_081B5E48: .4byte gMain\n\t"
        "_081B5E4C: .4byte 0x00000439\n\t"
        "_081B5E50:\n\t"
        "	ldr r0, _081B5E58\n\t"
        "	strb r5, [r0, #9]\n\t"
        "	b _081B5EA4\n\t"
        "	.align 2, 0\n\t"
        "_081B5E58: .4byte gPartyMenu\n\t"
        "_081B5E5C:\n\t"
        "	movs r7, #0\n\t"
        "	movs r6, #0\n\t"
        "_081B5E60:\n\t"
        "	ldr r4, _081B5EAC\n\t"
        "	ldrh r0, [r4]\n\t"
        "	bl GetItemEffectType\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0xa\n\t"
        "	bne _081B5EBC\n\t"
        "	ldr r1, _081B5EB0\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1, #9]\n\t"
        "	movs r5, #0\n\t"
        "_081B5E78:\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r1, r5, #0\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B5EB4\n\t"
        "	adds r4, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5E9A\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B5E50\n\t"
        "_081B5E9A:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #5\n\t"
        "	bls _081B5E78\n\t"
        "_081B5EA4:\n\t"
        "	ldr r0, _081B5EB8\n\t"
        "	movs r1, #0x7f\n\t"
        "	b _081B5ED0\n\t"
        "	.align 2, 0\n\t"
        "_081B5EAC: .4byte gSpecialVar_ItemId\n\t"
        "_081B5EB0: .4byte gPartyMenu\n\t"
        "_081B5EB4: .4byte gPlayerParty\n\t"
        "_081B5EB8: .4byte sub_081B5F20 + 1\n\t"
        "_081B5EBC:\n\t"
        "	ldrh r0, [r4]\n\t"
        "	bl GetPocketByItemId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #5\n\t"
        "	cmp r0, #3\n\t"
        "	bne _081B5ECE\n\t"
        "	movs r1, #4\n\t"
        "_081B5ECE:\n\t"
        "	ldr r0, _081B5EF0\n\t"
        "_081B5ED0:\n\t"
        "	str r1, [sp]\n\t"
        "	str r0, [sp, #4]\n\t"
        "	mov r0, r8\n\t"
        "	str r0, [sp, #8]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	movs r2, #3\n\t"
        "	movs r3, #1\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5EF0: .4byte Task_HandleChooseMonInput + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void c2_815ABFC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl CurrentBattlePyramidLocation\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B5F0C\n\t"
        "	movs r0, #0xc\n\t"
        "	movs r1, #5\n\t"
        "	movs r2, #0\n\t"
        "	bl GoToBagMenu\n\t"
        "	b _081B5F16\n\t"
        "_081B5F0C:\n\t"
        "	ldr r0, _081B5F1C\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #4\n\t"
        "	bl sub_081C47A0\n\t"
        "_081B5F16:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5F1C: .4byte gUnknown_203CBFC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B5F20(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	ldr r0, _081B5F58\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B5F52\n\t"
        "	ldr r0, _081B5F5C\n\t"
        "	ldrb r1, [r0, #8]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B5F46\n\t"
        "	ldr r0, _081B5F60\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _081B5F64\n\t"
        "	str r0, [r1, #4]\n\t"
        "_081B5F46:\n\t"
        "	ldr r0, _081B5F68\n\t"
        "	ldr r1, _081B5F6C\n\t"
        "	ldr r2, [r0]\n\t"
        "	adds r0, r3, #0\n\t"
        "	bl _call_via_r2\n\t"
        "_081B5F52:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5F58: .4byte gPaletteFade\n\t"
        "_081B5F5C: .4byte gPartyMenu\n\t"
        "_081B5F60: .4byte sPartyMenuInternal\n\t"
        "_081B5F64: .4byte sub_081B8DE0 + 1\n\t"
        "_081B5F68: .4byte gItemUseCB\n\t"
        "_081B5F6C: .4byte sub_081B6434 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 IsHPRecoveryItem(u16 itemId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bne _081B5F8C\n\t"
        "	ldr r0, _081B5F84\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _081B5F88\n\t"
        "	adds r0, r0, r1\n\t"
        "	b _081B5F96\n\t"
        "	.align 2, 0\n\t"
        "_081B5F84: .4byte gSaveBlock1Ptr\n\t"
        "_081B5F88: .4byte 0x00003214\n\t"
        "_081B5F8C:\n\t"
        "	ldr r1, _081B5FA4\n\t"
        "	subs r0, #0xd\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "_081B5F96:\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	movs r0, #4\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B5FA8\n\t"
        "	movs r0, #0\n\t"
        "	b _081B5FAA\n\t"
        "	.align 2, 0\n\t"
        "_081B5FA4: .4byte gUnknown_82EEF14\n\t"
        "_081B5FA8:\n\t"
        "	movs r0, #1\n\t"
        "_081B5FAA:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetMedicineItemEffectMessage(u16 itemId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl GetItemEffectType\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	subs r0, #3\n\t"
        "	cmp r0, #0x12\n\t"
        "	bls _081B5FC6\n\t"
        "	b _081B615C\n\t"
        "_081B5FC6:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B5FD0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081B5FD0: .4byte 0x081B5FD4\n\t"
        "_081B5FD4: @ jump table\n\t"
        "	.4byte _081B6020 @ case 0\n\t"
        "	.4byte _081B6034 @ case 1\n\t"
        "	.4byte _081B6048 @ case 2\n\t"
        "	.4byte _081B605C @ case 3\n\t"
        "	.4byte _081B6070 @ case 4\n\t"
        "	.4byte _081B6084 @ case 5\n\t"
        "	.4byte _081B6098 @ case 6\n\t"
        "	.4byte _081B615C @ case 7\n\t"
        "	.4byte _081B60AC @ case 8\n\t"
        "	.4byte _081B60D0 @ case 9\n\t"
        "	.4byte _081B60C0 @ case 10\n\t"
        "	.4byte _081B6100 @ case 11\n\t"
        "	.4byte _081B6110 @ case 12\n\t"
        "	.4byte _081B60F0 @ case 13\n\t"
        "	.4byte _081B60E0 @ case 14\n\t"
        "	.4byte _081B615C @ case 15\n\t"
        "	.4byte _081B6134 @ case 16\n\t"
        "	.4byte _081B6134 @ case 17\n\t"
        "	.4byte _081B6148 @ case 18\n\t"
        "_081B6020:\n\t"
        "	ldr r0, _081B602C\n\t"
        "	ldr r1, _081B6030\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B602C: .4byte gStringVar4\n\t"
        "_081B6030: .4byte gUnknown_85C97BD + 0x6E9\n\t"
        "_081B6034:\n\t"
        "	ldr r0, _081B6040\n\t"
        "	ldr r1, _081B6044\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B6040: .4byte gStringVar4\n\t"
        "_081B6044: .4byte gUnknown_85C97BD + 0x717\n\t"
        "_081B6048:\n\t"
        "	ldr r0, _081B6054\n\t"
        "	ldr r1, _081B6058\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B6054: .4byte gStringVar4\n\t"
        "_081B6058: .4byte gUnknown_85C97BD + 0x725\n\t"
        "_081B605C:\n\t"
        "	ldr r0, _081B6068\n\t"
        "	ldr r1, _081B606C\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B6068: .4byte gStringVar4\n\t"
        "_081B606C: .4byte gUnknown_85C97BD + 0x735\n\t"
        "_081B6070:\n\t"
        "	ldr r0, _081B607C\n\t"
        "	ldr r1, _081B6080\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B607C: .4byte gStringVar4\n\t"
        "_081B6080: .4byte gUnknown_85C97BD + 0x703\n\t"
        "_081B6084:\n\t"
        "	ldr r0, _081B6090\n\t"
        "	ldr r1, _081B6094\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B6090: .4byte gStringVar4\n\t"
        "_081B6094: .4byte gUnknown_85C97BD + 0x82A\n\t"
        "_081B6098:\n\t"
        "	ldr r0, _081B60A4\n\t"
        "	ldr r1, _081B60A8\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B60A4: .4byte gStringVar4\n\t"
        "_081B60A8: .4byte gUnknown_85C97BD + 0x83A\n\t"
        "_081B60AC:\n\t"
        "	ldr r0, _081B60B8\n\t"
        "	ldr r1, _081B60BC\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B60B8: .4byte gStringVar4\n\t"
        "_081B60BC: .4byte gUnknown_85C97BD + 0x76E\n\t"
        "_081B60C0:\n\t"
        "	ldr r0, _081B60C8\n\t"
        "	ldr r1, _081B60CC\n\t"
        "	b _081B6114\n\t"
        "	.align 2, 0\n\t"
        "_081B60C8: .4byte gStringVar2\n\t"
        "_081B60CC: .4byte gUnknown_85C97BD + 0x32A\n\t"
        "_081B60D0:\n\t"
        "	ldr r0, _081B60D8\n\t"
        "	ldr r1, _081B60DC\n\t"
        "	b _081B6114\n\t"
        "	.align 2, 0\n\t"
        "_081B60D8: .4byte gStringVar2\n\t"
        "_081B60DC: .4byte gText_Register + 0x7\n\t"
        "_081B60E0:\n\t"
        "	ldr r0, _081B60E8\n\t"
        "	ldr r1, _081B60EC\n\t"
        "	b _081B6114\n\t"
        "	.align 2, 0\n\t"
        "_081B60E8: .4byte gStringVar2\n\t"
        "_081B60EC: .4byte gText_Register + 0xC\n\t"
        "_081B60F0:\n\t"
        "	ldr r0, _081B60F8\n\t"
        "	ldr r1, _081B60FC\n\t"
        "	b _081B6114\n\t"
        "	.align 2, 0\n\t"
        "_081B60F8: .4byte gStringVar2\n\t"
        "_081B60FC: .4byte gText_Register + 0x1B\n\t"
        "_081B6100:\n\t"
        "	ldr r0, _081B6108\n\t"
        "	ldr r1, _081B610C\n\t"
        "	b _081B6114\n\t"
        "	.align 2, 0\n\t"
        "_081B6108: .4byte gStringVar2\n\t"
        "_081B610C: .4byte gUnknown_85C97BD + 0x330\n\t"
        "_081B6110:\n\t"
        "	ldr r0, _081B6124\n\t"
        "	ldr r1, _081B6128\n\t"
        "_081B6114:\n\t"
        "	bl StringCopy\n\t"
        "	ldr r0, _081B612C\n\t"
        "	ldr r1, _081B6130\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B6124: .4byte gStringVar2\n\t"
        "_081B6128: .4byte gUnknown_85C97BD + 0x335\n\t"
        "_081B612C: .4byte gStringVar4\n\t"
        "_081B6130: .4byte gUnknown_85C97BD + 0x7A2\n\t"
        "_081B6134:\n\t"
        "	ldr r0, _081B6140\n\t"
        "	ldr r1, _081B6144\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B6140: .4byte gStringVar4\n\t"
        "_081B6144: .4byte gUnknown_85C97BD + 0x77E\n\t"
        "_081B6148:\n\t"
        "	ldr r0, _081B6154\n\t"
        "	ldr r1, _081B6158\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6164\n\t"
        "	.align 2, 0\n\t"
        "_081B6154: .4byte gStringVar4\n\t"
        "_081B6158: .4byte gUnknown_85C97BD + 0x749\n\t"
        "_081B615C:\n\t"
        "	ldr r0, _081B6168\n\t"
        "	ldr r1, _081B616C\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "_081B6164:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6168: .4byte gStringVar4\n\t"
        "_081B616C: .4byte gUnknown_85C97BD + 0x33A\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void UsingHPEVItemOnShedinja(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl GetItemEffectType\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0xd\n\t"
        "	bne _081B619C\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	ldr r1, _081B6198\n\t"
        "	cmp r0, r1\n\t"
        "	bne _081B619C\n\t"
        "	movs r0, #0\n\t"
        "	b _081B619E\n\t"
        "	.align 2, 0\n\t"
        "_081B6198: .4byte SPECIAL_ScriptCheckFreePokemonStorageSpace\n\t"
        "_081B619C:\n\t"
        "	movs r0, #1\n\t"
        "_081B619E:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

bool8 IsItemFlute(u16 item)
{
    if (item == ITEM_BLUE_FLUTE || item == ITEM_RED_FLUTE || item == ITEM_YELLOW_FLUTE)
        return TRUE;
    return FALSE;
}

__attribute__((naked)) void ExecuteTableBasedItemEffect__(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r5, r1, #0x10\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	ldr r0, _081B61EC\n\t"
        "	ldr r1, _081B61F0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B61F8\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r3, r0\n\t"
        "	ldr r1, _081B61F4\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r3, #0\n\t"
        "	b _081B6212\n\t"
        "	.align 2, 0\n\t"
        "_081B61EC: .4byte gMain\n\t"
        "_081B61F0: .4byte 0x00000439\n\t"
        "_081B61F4: .4byte gPlayerParty\n\t"
        "_081B61F8:\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r4, r3, #0\n\t"
        "	muls r4, r0, r4\n\t"
        "	ldr r0, _081B6224\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r3, #0\n\t"
        "	bl GetPartyIdFromBattleSlot\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "_081B6212:\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl ExecuteTableBasedItemEffect\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B6224: .4byte gPlayerParty\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ItemUseCB_Medicine(u8 taskId, TaskFunc task)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #8\n\t"
        "	str r1, [sp, #4]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	movs r0, #0\n\t"
        "	mov sl, r0\n\t"
        "	ldr r0, _081B62B0\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B62B4\n\t"
        "	adds r5, r1, r0\n\t"
        "	ldr r0, _081B62B8\n\t"
        "	ldrh r6, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl UsingHPEVItemOnShedinja\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B62A0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl IsHPRecoveryItem\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B628E\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sl, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x3a\n\t"
        "	bl GetMonData3\n\t"
        "	cmp sl, r0\n\t"
        "	bne _081B628E\n\t"
        "	movs r1, #0\n\t"
        "	mov r8, r1\n\t"
        "_081B628E:\n\t"
        "	ldr r4, _081B62B0\n\t"
        "	ldrb r0, [r4, #9]\n\t"
        "	adds r1, r6, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ExecuteTableBasedItemEffect__\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B62C4\n\t"
        "_081B62A0:\n\t"
        "	ldr r1, _081B62BC\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _081B62C0\n\t"
        "	b _081B6394\n\t"
        "	.align 2, 0\n\t"
        "_081B62B0: .4byte gPartyMenu\n\t"
        "_081B62B4: .4byte gPlayerParty\n\t"
        "_081B62B8: .4byte gSpecialVar_ItemId\n\t"
        "_081B62BC: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B62C0: .4byte gUnknown_85C97BD + 0x33A\n\t"
        "_081B62C4:\n\t"
        "	ldr r1, _081B62EC\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl IsItemFlute\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B62F0\n\t"
        "	movs r0, #1\n\t"
        "	bl PlaySE\n\t"
        "	ldrb r0, [r4, #0xb]\n\t"
        "	cmp r0, #0xe\n\t"
        "	beq _081B62F6\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "	b _081B62F6\n\t"
        "	.align 2, 0\n\t"
        "_081B62EC: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B62F0:\n\t"
        "	movs r0, #0x75\n\t"
        "	bl PlaySE\n\t"
        "_081B62F6:\n\t"
        "	ldr r4, _081B6374\n\t"
        "	ldr r7, _081B6378\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r7, r0]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl party_menu_get_status_condition_and_update_object\n\t"
        "	ldr r2, _081B637C\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r7, r0]\n\t"
        "	ldr r1, [r4]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r3, r0, r1\n\t"
        "	ldrb r1, [r3, #0xc]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _081B6334\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r3, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl DisplayPartyPokemonLevelCheck\n\t"
        "_081B6334:\n\t"
        "	mov r2, r8\n\t"
        "	cmp r2, #1\n\t"
        "	bne _081B6384\n\t"
        "	mov r0, sl\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B6348\n\t"
        "	ldrb r0, [r7, #9]\n\t"
        "	movs r1, #1\n\t"
        "	bl AnimatePartySlot\n\t"
        "_081B6348:\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	adds r3, r0, #0\n\t"
        "	mov r1, sl\n\t"
        "	subs r3, r3, r1\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	ldrb r1, [r7, #9]\n\t"
        "	ldr r0, _081B6380\n\t"
        "	str r0, [sp]\n\t"
        "	mov r0, sb\n\t"
        "	movs r2, #1\n\t"
        "	bl PartyMenuModifyHP\n\t"
        "	mov r0, sb\n\t"
        "	movs r1, #0\n\t"
        "	mov r2, sl\n\t"
        "	bl ResetHPTaskData\n\t"
        "	b _081B63B0\n\t"
        "	.align 2, 0\n\t"
        "_081B6374: .4byte sPartyMenuBoxes\n\t"
        "_081B6378: .4byte gPartyMenu\n\t"
        "_081B637C: .4byte gSprites\n\t"
        "_081B6380: .4byte sub_081B63CC + 1\n\t"
        "_081B6384:\n\t"
        "	ldr r1, _081B63C0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetMedicineItemEffectMessage\n\t"
        "	ldr r0, _081B63C4\n\t"
        "_081B6394:\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B63C8\n\t"
        "	mov r2, sb\n\t"
        "	lsls r0, r2, #2\n\t"
        "	add r0, sb\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [sp, #4]\n\t"
        "	str r1, [r0]\n\t"
        "_081B63B0:\n\t"
        "	add sp, #8\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B63C0: .4byte gStringVar1\n\t"
        "_081B63C4: .4byte gStringVar4\n\t"
        "_081B63C8: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B63CC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r0, _081B6418\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B641C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6420\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r4, _081B6424\n\t"
        "	ldr r1, _081B6428\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	bl HandleBattleLowHpMusicChange\n\t"
        "	ldr r1, _081B642C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6430\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6418: .4byte gPartyMenu\n\t"
        "_081B641C: .4byte gPlayerParty\n\t"
        "_081B6420: .4byte gStringVar1\n\t"
        "_081B6424: .4byte gStringVar4\n\t"
        "_081B6428: .4byte gText_PkmnHPRestoredByVar2\n\t"
        "_081B642C: .4byte gTasks\n\t"
        "_081B6430: .4byte sub_081B6434 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6434(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B645A\n\t"
        "	ldr r0, _081B6460\n\t"
        "	ldrb r1, [r0]\n\t"
        "	cmp r1, #0\n\t"
        "	bne _081B6454\n\t"
        "	ldr r0, _081B6464\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r1, [r0, #4]\n\t"
        "_081B6454:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "_081B645A:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6460: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B6464: .4byte sPartyMenuInternal\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6468(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	str r1, [sp]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "	ldr r4, _081B6500\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r4, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B6504\n\t"
        "	adds r5, r1, r0\n\t"
        "	ldr r0, _081B6508\n\t"
        "	ldrh r6, [r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetItemEffectType\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x20\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	str r0, [sp, #4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ItemEffectToMonEv\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	str r0, [sp, #8]\n\t"
        "	ldrb r0, [r4, #9]\n\t"
        "	adds r1, r6, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ExecuteTableBasedItemEffect__\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x20\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ItemEffectToMonEv\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	cmp r4, #0\n\t"
        "	bne _081B64F0\n\t"
        "	ldr r0, [sp, #4]\n\t"
        "	cmp r0, sb\n\t"
        "	bne _081B6514\n\t"
        "	ldr r1, [sp, #8]\n\t"
        "	cmp r1, r8\n\t"
        "	bne _081B6514\n\t"
        "_081B64F0:\n\t"
        "	ldr r1, _081B650C\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _081B6510\n\t"
        "	b _081B6582\n\t"
        "	.align 2, 0\n\t"
        "_081B6500: .4byte gPartyMenu\n\t"
        "_081B6504: .4byte gPlayerParty\n\t"
        "_081B6508: .4byte gSpecialVar_ItemId\n\t"
        "_081B650C: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B6510: .4byte gUnknown_85C97BD + 0x33A\n\t"
        "_081B6514:\n\t"
        "	ldr r1, _081B6550\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #1\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "	ldr r1, _081B6554\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r1, _081B6558\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl ItemEffectToStatString\n\t"
        "	ldr r2, [sp, #4]\n\t"
        "	cmp r2, sb\n\t"
        "	beq _081B6578\n\t"
        "	ldr r0, [sp, #8]\n\t"
        "	cmp r0, r8\n\t"
        "	beq _081B6564\n\t"
        "	ldr r0, _081B655C\n\t"
        "	ldr r1, _081B6560\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6580\n\t"
        "	.align 2, 0\n\t"
        "_081B6550: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B6554: .4byte gStringVar1\n\t"
        "_081B6558: .4byte gStringVar2\n\t"
        "_081B655C: .4byte gStringVar4\n\t"
        "_081B6560: .4byte gUnknown_85C97BD + 0x7BB\n\t"
        "_081B6564:\n\t"
        "	ldr r0, _081B6570\n\t"
        "	ldr r1, _081B6574\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	b _081B6580\n\t"
        "	.align 2, 0\n\t"
        "_081B6570: .4byte gStringVar4\n\t"
        "_081B6574: .4byte gUnknown_85C97BD + 0x804\n\t"
        "_081B6578:\n\t"
        "	ldr r0, _081B65B0\n\t"
        "	ldr r1, _081B65B4\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "_081B6580:\n\t"
        "	ldr r0, _081B65B0\n\t"
        "_081B6582:\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B65B8\n\t"
        "	mov r2, sl\n\t"
        "	lsls r0, r2, #2\n\t"
        "	add r0, sl\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [sp]\n\t"
        "	str r1, [r0]\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B65B0: .4byte gStringVar4\n\t"
        "_081B65B4: .4byte gUnknown_85C97BD + 0x7DE\n\t"
        "_081B65B8: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ItemEffectToMonEv(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0xc\n\t"
        "	cmp r0, #5\n\t"
        "	bhi _081B6632\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B65D8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081B65D8: .4byte 0x081B65DC\n\t"
        "_081B65DC: @ jump table\n\t"
        "	.4byte _081B660C @ case 0\n\t"
        "	.4byte _081B65F4 @ case 1\n\t"
        "	.4byte _081B661E @ case 2\n\t"
        "	.4byte _081B6624 @ case 3\n\t"
        "	.4byte _081B6618 @ case 4\n\t"
        "	.4byte _081B6612 @ case 5\n\t"
        "_081B65F4:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	ldr r1, _081B6608\n\t"
        "	cmp r0, r1\n\t"
        "	beq _081B6632\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x1a\n\t"
        "	b _081B6628\n\t"
        "	.align 2, 0\n\t"
        "_081B6608: .4byte SPECIAL_ScriptCheckFreePokemonStorageSpace\n\t"
        "_081B660C:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x1b\n\t"
        "	b _081B6628\n\t"
        "_081B6612:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x1c\n\t"
        "	b _081B6628\n\t"
        "_081B6618:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x1d\n\t"
        "	b _081B6628\n\t"
        "_081B661E:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x1e\n\t"
        "	b _081B6628\n\t"
        "_081B6624:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x1f\n\t"
        "_081B6628:\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	b _081B6634\n\t"
        "_081B6632:\n\t"
        "	movs r0, #0\n\t"
        "_081B6634:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ItemEffectToStatString(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r2, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	subs r0, #0xc\n\t"
        "	cmp r0, #5\n\t"
        "	bhi _081B66A8\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B6654\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6654: .4byte 0x081B6658\n\t"
        "_081B6658: @ jump table\n\t"
        "	.4byte _081B6678 @ case 0\n\t"
        "	.4byte _081B6670 @ case 1\n\t"
        "	.4byte _081B6690 @ case 2\n\t"
        "	.4byte _081B66A0 @ case 3\n\t"
        "	.4byte _081B6688 @ case 4\n\t"
        "	.4byte _081B6680 @ case 5\n\t"
        "_081B6670:\n\t"
        "	ldr r1, _081B6674\n\t"
        "	b _081B6692\n\t"
        "	.align 2, 0\n\t"
        "_081B6674: .4byte gUnknown_85C97BD + 0x32A\n\t"
        "_081B6678:\n\t"
        "	ldr r1, _081B667C\n\t"
        "	b _081B6692\n\t"
        "	.align 2, 0\n\t"
        "_081B667C: .4byte gText_Register + 0x7\n\t"
        "_081B6680:\n\t"
        "	ldr r1, _081B6684\n\t"
        "	b _081B6692\n\t"
        "	.align 2, 0\n\t"
        "_081B6684: .4byte gText_Register + 0xC\n\t"
        "_081B6688:\n\t"
        "	ldr r1, _081B668C\n\t"
        "	b _081B6692\n\t"
        "	.align 2, 0\n\t"
        "_081B668C: .4byte gText_Register + 0x1B\n\t"
        "_081B6690:\n\t"
        "	ldr r1, _081B669C\n\t"
        "_081B6692:\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl StringCopy\n\t"
        "	b _081B66A8\n\t"
        "	.align 2, 0\n\t"
        "_081B669C: .4byte gUnknown_85C97BD + 0x330\n\t"
        "_081B66A0:\n\t"
        "	ldr r1, _081B66AC\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl StringCopy\n\t"
        "_081B66A8:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B66AC: .4byte gUnknown_85C97BD + 0x335\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B66B0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	mov sl, r0\n\t"
        "	movs r1, #1\n\t"
        "	mov r8, r1\n\t"
        "	movs r0, #3\n\t"
        "	bl DisplaySelectionWindow\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	movs r6, #0\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r2, r4, #0\n\t"
        "	muls r2, r0, r2\n\t"
        "	str r2, [sp, #0xc]\n\t"
        "_081B66E0:\n\t"
        "	ldr r0, _081B6774\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	ldr r2, [sp, #0xc]\n\t"
        "	adds r0, r2, r0\n\t"
        "	bl GetMonData3\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #0\n\t"
        "	bl GetFontAttribute\n\t"
        "	adds r4, r0, #0\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #2\n\t"
        "	bl GetFontAttribute\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r2, r5, #3\n\t"
        "	ldr r0, _081B6778\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r0, r6, #4\n\t"
        "	adds r0, #2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r7, #0\n\t"
        "	str r7, [sp, #8]\n\t"
        "	mov r0, sb\n\t"
        "	mov r1, r8\n\t"
        "	adds r3, r4, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	cmp r5, #0\n\t"
        "	beq _081B673C\n\t"
        "	mov r0, sl\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "_081B673C:\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #3\n\t"
        "	bls _081B66E0\n\t"
        "	movs r0, #0x10\n\t"
        "	str r0, [sp]\n\t"
        "	mov r0, sl\n\t"
        "	str r0, [sp, #4]\n\t"
        "	str r7, [sp, #8]\n\t"
        "	mov r0, sb\n\t"
        "	mov r1, r8\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl sub_081984B0\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6774: .4byte gPlayerParty\n\t"
        "_081B6778: .4byte gMoveNames\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ether_effect_related_3(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r5, r4, #0\n\t"
        "	bl Menu_ProcessInput\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r1, r0, #0x18\n\t"
        "	movs r0, #2\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r1, r0\n\t"
        "	beq _081B67B8\n\t"
        "	adds r0, #1\n\t"
        "	cmp r1, r0\n\t"
        "	bne _081B67A8\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B687C\n\t"
        "	b _081B67B8\n\t"
        "_081B67A8:\n\t"
        "	ldr r0, _081B67C0\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0xd\n\t"
        "	bl PartyMenuRemoveWindow\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ether_effect_related_2\n\t"
        "_081B67B8:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B67C0: .4byte sPartyMenuInternal\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void dp05_ether(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _081B67DC\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bne _081B67E8\n\t"
        "	ldr r0, _081B67E0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _081B67E4\n\t"
        "	adds r0, r0, r1\n\t"
        "	b _081B67F2\n\t"
        "	.align 2, 0\n\t"
        "_081B67DC: .4byte gSpecialVar_ItemId\n\t"
        "_081B67E0: .4byte gSaveBlock1Ptr\n\t"
        "_081B67E4: .4byte 0x00003214\n\t"
        "_081B67E8:\n\t"
        "	ldr r1, _081B680C\n\t"
        "	subs r0, #0xd\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "_081B67F2:\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	movs r0, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	bne _081B6814\n\t"
        "	ldr r0, _081B6810\n\t"
        "	strh r1, [r0, #0xe]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ether_effect_related\n\t"
        "	b _081B6836\n\t"
        "	.align 2, 0\n\t"
        "_081B680C: .4byte gUnknown_82EEF14\n\t"
        "_081B6810: .4byte gPartyMenu\n\t"
        "_081B6814:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	movs r0, #0x16\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "	ldr r0, _081B683C\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	bl sub_081B66B0\n\t"
        "	ldr r1, _081B6840\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6844\n\t"
        "	str r1, [r0]\n\t"
        "_081B6836:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B683C: .4byte gPartyMenu\n\t"
        "_081B6840: .4byte gTasks\n\t"
        "_081B6844: .4byte ether_effect_related_3 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ether_effect_related_2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _081B6874\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0xc\n\t"
        "	bl PartyMenuRemoveWindow\n\t"
        "	bl Menu_GetCursorPos\n\t"
        "	ldr r1, _081B6878\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r1, #0xe]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ether_effect_related\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6874: .4byte sPartyMenuInternal\n\t"
        "_081B6878: .4byte gPartyMenu\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B687C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _081B68A8\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r0, _081B68AC\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _081B68B0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [r0, #4]\n\t"
        "	adds r0, #0xc\n\t"
        "	bl PartyMenuRemoveWindow\n\t"
        "	movs r0, #5\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B68A8: .4byte gTasks\n\t"
        "_081B68AC: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B68B0: .4byte sPartyMenuInternal\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ether_effect_related(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r7, _081B68E4\n\t"
        "	ldr r0, _081B68E8\n\t"
        "	ldrh r5, [r0]\n\t"
        "	adds r4, r7, #0\n\t"
        "	subs r4, #0xe\n\t"
        "	ldrb r0, [r4, #9]\n\t"
        "	ldrb r2, [r7]\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl ExecuteTableBasedItemEffect__\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B68F4\n\t"
        "	ldr r1, _081B68EC\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _081B68F0\n\t"
        "	b _081B693A\n\t"
        "	.align 2, 0\n\t"
        "_081B68E4: .4byte gUnknown_203CBA2\n\t"
        "_081B68E8: .4byte gSpecialVar_ItemId\n\t"
        "_081B68EC: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B68F0: .4byte gUnknown_85C97BD + 0x33A\n\t"
        "_081B68F4:\n\t"
        "	ldr r1, _081B695C\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r4, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r4, r1, #0\n\t"
        "	muls r4, r0, r4\n\t"
        "	ldr r0, _081B6960\n\t"
        "	adds r4, r4, r0\n\t"
        "	movs r0, #1\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r7, r0]\n\t"
        "	adds r1, #0xd\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetMonData3\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	ldr r0, _081B6964\n\t"
        "	lsrs r1, r1, #0xd\n\t"
        "	ldr r2, _081B6968\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMedicineItemEffectMessage\n\t"
        "	ldr r0, _081B696C\n\t"
        "_081B693A:\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B6970\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6974\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B695C: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B6960: .4byte gPlayerParty\n\t"
        "_081B6964: .4byte gStringVar1\n\t"
        "_081B6968: .4byte gMoveNames\n\t"
        "_081B696C: .4byte gStringVar4\n\t"
        "_081B6970: .4byte gTasks\n\t"
        "_081B6974: .4byte sub_081B6434 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void dp05_pp_up(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	movs r0, #0x17\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "	ldr r0, _081B69A8\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	bl sub_081B66B0\n\t"
        "	ldr r1, _081B69AC\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B69B0\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B69A8: .4byte gPartyMenu\n\t"
        "_081B69AC: .4byte gTasks\n\t"
        "_081B69B0: .4byte ether_effect_related_3 + 1\n\t"
        ".syntax divided\n\t"
    );
}

u16 ItemIdToBattleMoveId(u16 item)
{
    u16 tmNumber = item - ITEM_TM01;
    return sTMHMMoves[tmNumber];
}

__attribute__((naked)) bool8 IsMoveHm(u16 move)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r2, r0, #0x10\n\t"
        "	movs r1, #0\n\t"
        "	ldr r3, _081B69E8\n\t"
        "_081B69D6:\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x32\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _081B69EC\n\t"
        "	movs r0, #1\n\t"
        "	b _081B69F8\n\t"
        "	.align 2, 0\n\t"
        "_081B69E8: .4byte gUnknown_85E18F8\n\t"
        "_081B69EC:\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #7\n\t"
        "	bls _081B69D6\n\t"
        "	movs r0, #0\n\t"
        "_081B69F8:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 MonKnowsMove(struct Pokemon *mon, u16 move)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r5, r1, #0x10\n\t"
        "	movs r4, #0\n\t"
        "_081B6A06:\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, r5\n\t"
        "	bne _081B6A18\n\t"
        "	movs r0, #1\n\t"
        "	b _081B6A24\n\t"
        "_081B6A18:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #3\n\t"
        "	bls _081B6A06\n\t"
        "	movs r0, #0\n\t"
        "_081B6A24:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

static void DisplayLearnMoveMessage(const u8 *str)
{
    StringExpandPlaceholders(gStringVar4, str);
    DisplayPartyMenuMessage(gStringVar4, TRUE);
    ScheduleBgCopyTilemapToVram(2);
}


__attribute__((naked)) void sub_081B6A50(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r0, r1, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl DisplayLearnMoveMessage\n\t"
        "	ldr r1, _081B6A74\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6A78\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6A74: .4byte gTasks\n\t"
        "_081B6A78: .4byte sub_081B6434 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6A7C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r7, _081B6B00\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r7, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B6B04\n\t"
        "	adds r5, r1, r0\n\t"
        "	movs r0, #0xe\n\t"
        "	adds r0, r0, r7\n\t"
        "	mov r8, r0\n\t"
        "	ldr r0, _081B6B08\n\t"
        "	ldrh r4, [r0]\n\t"
        "	ldr r1, _081B6B0C\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ItemIdToBattleMoveId\n\t"
        "	strh r0, [r7, #0xe]\n\t"
        "	ldr r0, _081B6B10\n\t"
        "	movs r2, #0xe\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _081B6B14\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	movs r0, #0\n\t"
        "	mov r1, r8\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl CanMonLearnTMTutor\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B6B24\n\t"
        "	cmp r0, #2\n\t"
        "	beq _081B6B2C\n\t"
        "	ldrh r1, [r7, #0xe]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GiveMoveToMon\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ldr r1, _081B6B18\n\t"
        "	cmp r0, r1\n\t"
        "	beq _081B6B3C\n\t"
        "	ldr r0, _081B6B1C\n\t"
        "	lsls r1, r6, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B6B20\n\t"
        "	str r0, [r1]\n\t"
        "	b _081B6B50\n\t"
        "	.align 2, 0\n\t"
        "_081B6B00: .4byte gPartyMenu\n\t"
        "_081B6B04: .4byte gPlayerParty\n\t"
        "_081B6B08: .4byte gSpecialVar_ItemId\n\t"
        "_081B6B0C: .4byte gStringVar1\n\t"
        "_081B6B10: .4byte gStringVar2\n\t"
        "_081B6B14: .4byte gMoveNames\n\t"
        "_081B6B18: .4byte 0xFFFF0000\n\t"
        "_081B6B1C: .4byte gTasks\n\t"
        "_081B6B20: .4byte sub_081B6B68 + 1\n\t"
        "_081B6B24:\n\t"
        "	ldr r1, _081B6B28\n\t"
        "	b _081B6B2E\n\t"
        "	.align 2, 0\n\t"
        "_081B6B28: .4byte gUnknown_85C97BD + 0x5BF\n\t"
        "_081B6B2C:\n\t"
        "	ldr r1, _081B6B38\n\t"
        "_081B6B2E:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_081B6A50\n\t"
        "	b _081B6B50\n\t"
        "	.align 2, 0\n\t"
        "_081B6B38: .4byte gUnknown_85C97BD + 0x6BC\n\t"
        "_081B6B3C:\n\t"
        "	ldr r0, _081B6B5C\n\t"
        "	bl DisplayLearnMoveMessage\n\t"
        "	ldr r1, _081B6B60\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6B64\n\t"
        "	str r1, [r0]\n\t"
        "_081B6B50:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6B5C: .4byte gUnknown_85C97BD + 0x5E4\n\t"
        "_081B6B60: .4byte gTasks\n\t"
        "_081B6B64: .4byte sub_081B6CA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6B68(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r2, _081B6BE8\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r2, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B6BEC\n\t"
        "	adds r5, r1, r0\n\t"
        "	adds r7, r2, #0\n\t"
        "	adds r7, #0xe\n\t"
        "	ldr r0, _081B6BF0\n\t"
        "	ldrh r4, [r0]\n\t"
        "	movs r1, #2\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B6BA4\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #4\n\t"
        "	bl AdjustFriendship\n\t"
        "	movs r0, #0xa9\n\t"
        "	lsls r0, r0, #1\n\t"
        "	cmp r4, r0\n\t"
        "	bhi _081B6BA4\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "_081B6BA4:\n\t"
        "	ldr r1, _081B6BF4\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B6BF8\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _081B6BFC\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	ldr r4, _081B6C00\n\t"
        "	ldr r1, _081B6C04\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B6C08\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6C0C\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6BE8: .4byte gPartyMenu\n\t"
        "_081B6BEC: .4byte gPlayerParty\n\t"
        "_081B6BF0: .4byte gSpecialVar_ItemId\n\t"
        "_081B6BF4: .4byte gStringVar1\n\t"
        "_081B6BF8: .4byte gStringVar2\n\t"
        "_081B6BFC: .4byte gMoveNames\n\t"
        "_081B6C00: .4byte gStringVar4\n\t"
        "_081B6C04: .4byte gUnknown_85C97BD + 0x5AB\n\t"
        "_081B6C08: .4byte gTasks\n\t"
        "_081B6C0C: .4byte sub_081B6C10 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6C10(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B6C36\n\t"
        "	ldr r0, _081B6C3C\n\t"
        "	bl PlayFanfare\n\t"
        "	ldr r1, _081B6C40\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6C44\n\t"
        "	str r1, [r0]\n\t"
        "_081B6C36:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6C3C: .4byte SPECIAL_sub_0818DA30\n\t"
        "_081B6C40: .4byte gTasks\n\t"
        "_081B6C44: .4byte sub_081B6C48 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6C48(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r5, r4, #0\n\t"
        "	bl IsFanfareTaskInactive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B6C9A\n\t"
        "	ldr r0, _081B6C84\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r2, #1\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B6C70\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B6C9A\n\t"
        "_081B6C70:\n\t"
        "	ldr r0, _081B6C88\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B6C8C\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Task_TryLearningNextMove\n\t"
        "	b _081B6C9A\n\t"
        "	.align 2, 0\n\t"
        "_081B6C84: .4byte gMain\n\t"
        "_081B6C88: .4byte gPartyMenu\n\t"
        "_081B6C8C:\n\t"
        "	cmp r0, #2\n\t"
        "	bne _081B6C94\n\t"
        "	ldr r0, _081B6CA0\n\t"
        "	strh r2, [r0]\n\t"
        "_081B6C94:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "_081B6C9A:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6CA0: .4byte gSpecialVar_Result\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6CA4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B6CC8\n\t"
        "	bl sub_081B2FDC\n\t"
        "	ldr r0, _081B6CD0\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B6CD4\n\t"
        "	str r0, [r1]\n\t"
        "_081B6CC8:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6CD0: .4byte gTasks\n\t"
        "_081B6CD4: .4byte sub_081B6CD8 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6CD8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl Menu_ProcessInputNoWrapClearOnChoose\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r1, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B6CFE\n\t"
        "	cmp r1, #0\n\t"
        "	bgt _081B6CF8\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r1, r0\n\t"
        "	beq _081B6D24\n\t"
        "	b _081B6D30\n\t"
        "_081B6CF8:\n\t"
        "	cmp r1, #1\n\t"
        "	beq _081B6D2A\n\t"
        "	b _081B6D30\n\t"
        "_081B6CFE:\n\t"
        "	ldr r0, _081B6D18\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	ldr r1, _081B6D1C\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6D20\n\t"
        "	str r1, [r0]\n\t"
        "	b _081B6D30\n\t"
        "	.align 2, 0\n\t"
        "_081B6D18: .4byte gUnknown_85C97BD + 0x666\n\t"
        "_081B6D1C: .4byte gTasks\n\t"
        "_081B6D20: .4byte sub_081B6D38 + 1\n\t"
        "_081B6D24:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "_081B6D2A:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B6EE0\n\t"
        "_081B6D30:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6D38(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B6D58\n\t"
        "	ldr r0, _081B6D60\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _081B6D64\n\t"
        "	str r0, [r1, #4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "_081B6D58:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6D60: .4byte sPartyMenuInternal\n\t"
        "_081B6D64: .4byte sub_081B6D68 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6D68(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r0, _081B6D90\n\t"
        "	ldr r4, _081B6D94\n\t"
        "	ldrb r1, [r4, #9]\n\t"
        "	ldr r2, _081B6D98\n\t"
        "	ldrb r2, [r2]\n\t"
        "	subs r2, #1\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r3, _081B6D9C\n\t"
        "	ldrh r4, [r4, #0xe]\n\t"
        "	str r4, [sp]\n\t"
        "	bl ShowSelectMovePokemonSummaryScreen\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6D90: .4byte gPlayerParty\n\t"
        "_081B6D94: .4byte gPartyMenu\n\t"
        "_081B6D98: .4byte gPlayerPartyCount\n\t"
        "_081B6D9C: .4byte sub_081B6DA0 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6DA0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	movs r0, #0x7f\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B6DC4\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B6DC8\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6DC4: .4byte sub_081B6DCC + 1\n\t"
        "_081B6DC8: .4byte gPartyMenu\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6DCC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r5, r4, #0\n\t"
        "	ldr r0, _081B6DF4\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B6DFE\n\t"
        "	bl sub_081C14C8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	beq _081B6DF8\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B6E04\n\t"
        "	b _081B6DFE\n\t"
        "	.align 2, 0\n\t"
        "_081B6DF4: .4byte gPaletteFade\n\t"
        "_081B6DF8:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_081B6EE0\n\t"
        "_081B6DFE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6E04(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	lsls r6, r6, #0x18\n\t"
        "	lsrs r6, r6, #0x18\n\t"
        "	ldr r0, _081B6E64\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r5, r1, #0\n\t"
        "	muls r5, r0, r5\n\t"
        "	ldr r0, _081B6E68\n\t"
        "	adds r5, r5, r0\n\t"
        "	bl sub_081C14C8\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r1, #0xd\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonData3\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldr r1, _081B6E6C\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B6E70\n\t"
        "	lsls r4, r4, #3\n\t"
        "	ldr r1, _081B6E74\n\t"
        "	adds r4, r4, r1\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl StringCopy\n\t"
        "	ldr r0, _081B6E78\n\t"
        "	bl DisplayLearnMoveMessage\n\t"
        "	ldr r1, _081B6E7C\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6E80\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6E64: .4byte gPartyMenu\n\t"
        "_081B6E68: .4byte gPlayerParty\n\t"
        "_081B6E6C: .4byte gStringVar1\n\t"
        "_081B6E70: .4byte gStringVar2\n\t"
        "_081B6E74: .4byte gMoveNames\n\t"
        "_081B6E78: .4byte gUnknown_85C97BD + 0x678\n\t"
        "_081B6E7C: .4byte gTasks\n\t"
        "_081B6E80: .4byte sub_081B6E84 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6E84(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B6ED0\n\t"
        "	ldr r5, _081B6ED8\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r5, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r4, r1, #0\n\t"
        "	muls r4, r0, r4\n\t"
        "	ldr r0, _081B6EDC\n\t"
        "	adds r4, r4, r0\n\t"
        "	bl sub_081C14C8\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl RemoveMonPPBonus\n\t"
        "	ldrh r5, [r5, #0xe]\n\t"
        "	bl sub_081C14C8\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl SetMonMoveSlot\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_081B6B68\n\t"
        "_081B6ED0:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6ED8: .4byte gPartyMenu\n\t"
        "_081B6EDC: .4byte gPlayerParty\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6EE0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r0, _081B6F28\n\t"
        "	ldr r1, _081B6F2C\n\t"
        "	movs r2, #0xe\n\t"
        "	ldrsh r1, [r1, r2]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _081B6F30\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	ldr r4, _081B6F34\n\t"
        "	ldr r1, _081B6F38\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B6F3C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B6F40\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6F28: .4byte gStringVar2\n\t"
        "_081B6F2C: .4byte gPartyMenu\n\t"
        "_081B6F30: .4byte gMoveNames\n\t"
        "_081B6F34: .4byte gStringVar4\n\t"
        "_081B6F38: .4byte gUnknown_85C97BD + 0x635\n\t"
        "_081B6F3C: .4byte gTasks\n\t"
        "_081B6F40: .4byte sub_081B6F44 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6F44(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B6F68\n\t"
        "	bl sub_081B2FDC\n\t"
        "	ldr r0, _081B6F70\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B6F74\n\t"
        "	str r0, [r1]\n\t"
        "_081B6F68:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B6F70: .4byte gTasks\n\t"
        "_081B6F74: .4byte sub_081B6F78 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B6F78(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r7, _081B6FA8\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r7, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B6FAC\n\t"
        "	adds r4, r1, r0\n\t"
        "	bl Menu_ProcessInputNoWrapClearOnChoose\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r5, r0, #0x18\n\t"
        "	cmp r5, #0\n\t"
        "	beq _081B6FB6\n\t"
        "	cmp r5, #0\n\t"
        "	bgt _081B6FB0\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r5, r0\n\t"
        "	beq _081B7038\n\t"
        "	b _081B706C\n\t"
        "	.align 2, 0\n\t"
        "_081B6FA8: .4byte gPartyMenu\n\t"
        "_081B6FAC: .4byte gPlayerParty\n\t"
        "_081B6FB0:\n\t"
        "	cmp r5, #1\n\t"
        "	beq _081B703E\n\t"
        "	b _081B706C\n\t"
        "_081B6FB6:\n\t"
        "	ldr r1, _081B6FF8\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B6FFC\n\t"
        "	movs r2, #0xe\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _081B7000\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	ldr r4, _081B7004\n\t"
        "	ldr r1, _081B7008\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B7014\n\t"
        "	ldr r0, _081B700C\n\t"
        "	lsls r1, r6, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B7010\n\t"
        "	str r0, [r1]\n\t"
        "	b _081B706C\n\t"
        "	.align 2, 0\n\t"
        "_081B6FF8: .4byte gStringVar1\n\t"
        "_081B6FFC: .4byte gStringVar2\n\t"
        "_081B7000: .4byte gMoveNames\n\t"
        "_081B7004: .4byte gStringVar4\n\t"
        "_081B7008: .4byte gUnknown_85C97BD + 0x650\n\t"
        "_081B700C: .4byte gTasks\n\t"
        "_081B7010: .4byte Task_TryLearningNextMoveAfterText + 1\n\t"
        "_081B7014:\n\t"
        "	cmp r0, #2\n\t"
        "	bne _081B701C\n\t"
        "	ldr r0, _081B702C\n\t"
        "	strh r5, [r0]\n\t"
        "_081B701C:\n\t"
        "	ldr r0, _081B7030\n\t"
        "	lsls r1, r6, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B7034\n\t"
        "	str r0, [r1]\n\t"
        "	b _081B706C\n\t"
        "	.align 2, 0\n\t"
        "_081B702C: .4byte gSpecialVar_Result\n\t"
        "_081B7030: .4byte gTasks\n\t"
        "_081B7034: .4byte sub_081B6434 + 1\n\t"
        "_081B7038:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "_081B703E:\n\t"
        "	ldr r1, _081B7074\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B7078\n\t"
        "	ldr r1, _081B707C\n\t"
        "	movs r2, #0xe\n\t"
        "	ldrsh r1, [r1, r2]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _081B7080\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	ldr r0, _081B7084\n\t"
        "	bl DisplayLearnMoveMessage\n\t"
        "	ldr r1, _081B7088\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B708C\n\t"
        "	str r1, [r0]\n\t"
        "_081B706C:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7074: .4byte gStringVar1\n\t"
        "_081B7078: .4byte gStringVar2\n\t"
        "_081B707C: .4byte gPartyMenu\n\t"
        "_081B7080: .4byte gMoveNames\n\t"
        "_081B7084: .4byte gUnknown_85C97BD + 0x5E4\n\t"
        "_081B7088: .4byte gTasks\n\t"
        "_081B708C: .4byte sub_081B6CA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_TryLearningNextMove(u8 taskId);

static void Task_TryLearningNextMoveAfterText(u8 taskId)
{
    if ((u8)IsPartyMenuTextPrinterActive() != TRUE)
        Task_TryLearningNextMove(taskId);
}

__attribute__((naked)) void dp05_rare_candy(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	mov sl, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r0, _081B7114\n\t"
        "	mov sb, r0\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B7118\n\t"
        "	adds r5, r1, r0\n\t"
        "	ldr r0, _081B711C\n\t"
        "	ldr r6, [r0]\n\t"
        "	movs r1, #0x86\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r4, r6, r1\n\t"
        "	ldr r2, _081B7120\n\t"
        "	mov r8, r2\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x38\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0x64\n\t"
        "	beq _081B7124\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl sub_081B7644\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1, #9]\n\t"
        "	mov r2, r8\n\t"
        "	ldrh r1, [r2]\n\t"
        "	movs r2, #0\n\t"
        "	bl ExecuteTableBasedItemEffect__\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r0, #0x89\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r6, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_081B7644\n\t"
        "	b _081B7126\n\t"
        "	.align 2, 0\n\t"
        "_081B7114: .4byte gPartyMenu\n\t"
        "_081B7118: .4byte gPlayerParty\n\t"
        "_081B711C: .4byte sPartyMenuInternal\n\t"
        "_081B7120: .4byte gSpecialVar_ItemId\n\t"
        "_081B7124:\n\t"
        "	movs r4, #1\n\t"
        "_081B7126:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	cmp r4, #0\n\t"
        "	beq _081B7160\n\t"
        "	ldr r1, _081B7154\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _081B7158\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B715C\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	mov r1, sl\n\t"
        "	b _081B71C2\n\t"
        "	.align 2, 0\n\t"
        "_081B7154: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B7158: .4byte gUnknown_85C97BD + 0x33A\n\t"
        "_081B715C: .4byte gTasks\n\t"
        "_081B7160:\n\t"
        "	ldr r1, _081B71D4\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	bl PlayFanfareByFanfareNum\n\t"
        "	ldr r0, _081B71D8\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_081B71F8\n\t"
        "	ldr r0, _081B71DC\n\t"
        "	ldrh r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "	ldr r1, _081B71E0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r4, _081B71E4\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x38\n\t"
        "	bl GetMonData3\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #3\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r4, _081B71E8\n\t"
        "	ldr r1, _081B71EC\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B71F0\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B71F4\n\t"
        "_081B71C2:\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B71D4: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B71D8: .4byte gPartyMenu\n\t"
        "_081B71DC: .4byte gSpecialVar_ItemId\n\t"
        "_081B71E0: .4byte gStringVar1\n\t"
        "_081B71E4: .4byte gStringVar2\n\t"
        "_081B71E8: .4byte gStringVar4\n\t"
        "_081B71EC: .4byte gUnknown_85C97BD + 0x791\n\t"
        "_081B71F0: .4byte gTasks\n\t"
        "_081B71F4: .4byte sub_081B7280 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B71F8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r7, r0, #0\n\t"
        "	ldr r6, _081B7278\n\t"
        "	lsls r4, r7, #4\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r4\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl party_menu_get_status_condition_and_update_object\n\t"
        "	ldr r2, _081B727C\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r3, r4, r0\n\t"
        "	ldrb r1, [r3, #0xc]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _081B7234\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r3, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl DisplayPartyPokemonLevelCheck\n\t"
        "_081B7234:\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r4\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl DisplayPartyPokemonHPCheck\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r4\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl DisplayPartyPokemonMaxHPCheck\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r4\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DisplayPartyPokemonHPBarCheck\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_081B57D8\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl AnimatePartySlot\n\t"
        "	movs r0, #0\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7278: .4byte sPartyMenuBoxes\n\t"
        "_081B727C: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7280(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	bl WaitFanfare\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B72CC\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B72CC\n\t"
        "	ldr r0, _081B72D4\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B72B2\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B72CC\n\t"
        "_081B72B2:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B7328\n\t"
        "	ldr r0, _081B72D8\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B72DC\n\t"
        "	str r0, [r1]\n\t"
        "_081B72CC:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B72D4: .4byte gMain\n\t"
        "_081B72D8: .4byte gTasks\n\t"
        "_081B72DC: .4byte sub_081B72E0 + 1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_081B72E0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _081B731C\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B72FA\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7314\n\t"
        "_081B72FA:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B7374\n\t"
        "	ldr r0, _081B7320\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B7324\n\t"
        "	str r0, [r1]\n\t"
        "_081B7314:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B731C: .4byte gMain\n\t"
        "_081B7320: .4byte gTasks\n\t"
        "_081B7324: .4byte Task_TryLearnNewMoves + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7328(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r0, _081B7370\n\t"
        "	ldr r5, [r0]\n\t"
        "	movs r0, #0x86\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r4, r5, r0\n\t"
        "	bl CreateLevelUpStatsWindow\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r4, #0x18]\n\t"
        "	ldrh r0, [r4, #0x18]\n\t"
        "	movs r1, #0x89\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r2, r5, r1\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #3\n\t"
        "	str r1, [sp, #4]\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl DrawLevelUpWindowPg1\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7370: .4byte sPartyMenuInternal\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7374(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r0, _081B73AC\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x86\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r4, r1, r0\n\t"
        "	ldrh r0, [r4, #0x18]\n\t"
        "	movs r2, #0x89\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r2, #3\n\t"
        "	str r2, [sp]\n\t"
        "	movs r2, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl DrawLevelUpWindowPg2\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B73AC: .4byte sPartyMenuInternal\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B74BC(u8 taskId);
__attribute__((naked)) void Task_TryLearningNextMove(u8 taskId);
__attribute__((naked)) void sub_081B7528(u8 taskId);
__attribute__((naked)) void sub_081B75B8(u8 taskId, u16 learnMove);

static void Task_TryLearnNewMoves(u8 taskId)
{
    u16 learnMove;

    if ((u8)WaitFanfare(FALSE) && ((JOY_NEW(A_BUTTON)) || (JOY_NEW(B_BUTTON))))
    {
        RemoveLevelUpStatsWindow();
        learnMove = MonTryLearningNewMove(&gPlayerParty[gPartyMenu.slotId], TRUE);
        gPartyMenu.data[1] = 1;
        switch (learnMove)
        {
        case 0: // No moves to learn
            sub_081B74BC(taskId);
            break;
        case MON_HAS_MAX_MOVES:
            sub_081B7528(taskId);
            break;
        case MON_ALREADY_KNOWS_MOVE:
            gTasks[taskId].func = Task_TryLearningNextMove;
            break;
        default:
            sub_081B75B8(taskId, learnMove);
            break;
        }
    }
}

__attribute__((naked)) void Task_TryLearningNextMove(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _081B7488\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B748C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	bl MonTryLearningNewMove\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	ldr r0, _081B7490\n\t"
        "	cmp r1, r0\n\t"
        "	beq _081B74B6\n\t"
        "	cmp r1, r0\n\t"
        "	bgt _081B7494\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B74A0\n\t"
        "	b _081B74B0\n\t"
        "	.align 2, 0\n\t"
        "_081B7488: .4byte gPartyMenu\n\t"
        "_081B748C: .4byte gPlayerParty\n\t"
        "_081B7490: .4byte 0x0000FFFE\n\t"
        "_081B7494:\n\t"
        "	ldr r0, _081B749C\n\t"
        "	cmp r1, r0\n\t"
        "	beq _081B74A8\n\t"
        "	b _081B74B0\n\t"
        "	.align 2, 0\n\t"
        "_081B749C: .4byte 0x0000FFFF\n\t"
        "_081B74A0:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B74BC\n\t"
        "	b _081B74B6\n\t"
        "_081B74A8:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B7528\n\t"
        "	b _081B74B6\n\t"
        "_081B74B0:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B75B8\n\t"
        "_081B74B6:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B74BC(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r6, _081B7500\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r6, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B7504\n\t"
        "	adds r7, r1, r0\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl GetEvolutionTargetSpecies\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	cmp r4, #0\n\t"
        "	beq _081B750C\n\t"
        "	bl FreePartyPointers\n\t"
        "	ldr r0, _081B7508\n\t"
        "	ldr r1, [r6]\n\t"
        "	str r1, [r0]\n\t"
        "	ldrb r3, [r6, #9]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl BeginEvolutionScene\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "	b _081B751A\n\t"
        "	.align 2, 0\n\t"
        "_081B7500: .4byte gPartyMenu\n\t"
        "_081B7504: .4byte gPlayerParty\n\t"
        "_081B7508: .4byte gCB2_AfterEvolution\n\t"
        "_081B750C:\n\t"
        "	ldr r0, _081B7520\n\t"
        "	lsls r1, r5, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B7524\n\t"
        "	str r0, [r1]\n\t"
        "_081B751A:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7520: .4byte gTasks\n\t"
        "_081B7524: .4byte sub_081B6434 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7528(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r0, _081B7590\n\t"
        "	mov r8, r0\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B7594\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7598\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B759C\n\t"
        "	ldr r6, _081B75A0\n\t"
        "	ldrh r1, [r6]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _081B75A4\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	ldr r4, _081B75A8\n\t"
        "	ldr r1, _081B75AC\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldrh r0, [r6]\n\t"
        "	mov r1, r8\n\t"
        "	strh r0, [r1, #0xe]\n\t"
        "	ldr r1, _081B75B0\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B75B4\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7590: .4byte gPartyMenu\n\t"
        "_081B7594: .4byte gPlayerParty\n\t"
        "_081B7598: .4byte gStringVar1\n\t"
        "_081B759C: .4byte gStringVar2\n\t"
        "_081B75A0: .4byte gMoveToLearn\n\t"
        "_081B75A4: .4byte gMoveNames\n\t"
        "_081B75A8: .4byte gStringVar4\n\t"
        "_081B75AC: .4byte gUnknown_85C97BD + 0x5E4\n\t"
        "_081B75B0: .4byte gTasks\n\t"
        "_081B75B4: .4byte sub_081B6CA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B75B8(u8 taskId, u16 learnMove)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r6, r6, #0x18\n\t"
        "	lsrs r6, r6, #0x18\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	ldr r0, _081B7620\n\t"
        "	mov r8, r0\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B7624\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7628\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B762C\n\t"
        "	lsls r1, r5, #3\n\t"
        "	ldr r2, _081B7630\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	ldr r4, _081B7634\n\t"
        "	ldr r1, _081B7638\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	mov r0, r8\n\t"
        "	strh r5, [r0, #0xe]\n\t"
        "	ldr r1, _081B763C\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7640\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7620: .4byte gPartyMenu\n\t"
        "_081B7624: .4byte gPlayerParty\n\t"
        "_081B7628: .4byte gStringVar1\n\t"
        "_081B762C: .4byte gStringVar2\n\t"
        "_081B7630: .4byte gMoveNames\n\t"
        "_081B7634: .4byte gStringVar4\n\t"
        "_081B7638: .4byte gUnknown_85C97BD + 0x5AB\n\t"
        "_081B763C: .4byte gTasks\n\t"
        "_081B7640: .4byte sub_081B6C10 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7644(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	movs r1, #0x3a\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x3b\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5, #2]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x3c\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5, #4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x3e\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x3f\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5, #0xa]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x3d\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5, #6]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B768C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _081B76C0\n\t"
        "	ldr r2, [r1]\n\t"
        "	movs r3, #0x86\n\t"
        "	lsls r3, r3, #2\n\t"
        "	adds r1, r2, r3\n\t"
        "	movs r3, #0\n\t"
        "	strh r3, [r1]\n\t"
        "	ldr r4, _081B76C4\n\t"
        "	adds r1, r2, r4\n\t"
        "	strh r3, [r1]\n\t"
        "	ldr r1, _081B76C8\n\t"
        "	ldrb r1, [r1, #9]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	asrs r1, r1, #0x18\n\t"
        "	movs r3, #0x87\n\t"
        "	lsls r3, r3, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	strh r1, [r2]\n\t"
        "	bl sub_081B76CC\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B76C0: .4byte sPartyMenuInternal\n\t"
        "_081B76C4: .4byte 0x0000021A\n\t"
        "_081B76C8: .4byte gPartyMenu\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B76CC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	mov r8, r4\n\t"
        "	ldr r6, _081B7724\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r6, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B7728\n\t"
        "	adds r5, r1, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7712\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	ldrb r0, [r6, #9]\n\t"
        "	ldr r1, _081B772C\n\t"
        "	ldrh r1, [r1]\n\t"
        "	movs r2, #0\n\t"
        "	bl ExecuteTableBasedItemEffect__\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7738\n\t"
        "_081B7712:\n\t"
        "	ldr r0, _081B7730\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B7734\n\t"
        "	str r0, [r1]\n\t"
        "	b _081B77CE\n\t"
        "	.align 2, 0\n\t"
        "_081B7724: .4byte gPartyMenu\n\t"
        "_081B7728: .4byte gPlayerParty\n\t"
        "_081B772C: .4byte gSpecialVar_ItemId\n\t"
        "_081B7730: .4byte gTasks\n\t"
        "_081B7734: .4byte task_sacred_ash_party_loop + 1\n\t"
        "_081B7738:\n\t"
        "	movs r0, #1\n\t"
        "	bl PlaySE\n\t"
        "	ldr r4, _081B77DC\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r6, r0]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl party_menu_get_status_condition_and_update_object\n\t"
        "	ldr r2, _081B77E0\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r6, r0]\n\t"
        "	ldr r1, [r4]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r3, r0, r1\n\t"
        "	ldrb r1, [r3, #0xc]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _081B777A\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r3, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl DisplayPartyPokemonLevelCheck\n\t"
        "_081B777A:\n\t"
        "	ldr r4, _081B77E4\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #0x87\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	bl AnimatePartySlot\n\t"
        "	ldrb r0, [r6, #9]\n\t"
        "	movs r1, #1\n\t"
        "	bl AnimatePartySlot\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	adds r3, r0, #0\n\t"
        "	subs r3, r3, r7\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	ldrb r1, [r6, #9]\n\t"
        "	ldr r0, _081B77E8\n\t"
        "	str r0, [sp]\n\t"
        "	mov r0, r8\n\t"
        "	movs r2, #1\n\t"
        "	bl PartyMenuModifyHP\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r7, #0\n\t"
        "	bl ResetHPTaskData\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r2, #0x86\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r1, r0, r2\n\t"
        "	movs r2, #1\n\t"
        "	strh r2, [r1]\n\t"
        "	ldr r1, _081B77EC\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r2, [r0]\n\t"
        "_081B77CE:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B77DC: .4byte sPartyMenuBoxes\n\t"
        "_081B77E0: .4byte gSprites\n\t"
        "_081B77E4: .4byte sPartyMenuInternal\n\t"
        "_081B77E8: .4byte sub_081B78B4 + 1\n\t"
        "_081B77EC: .4byte 0x0000021A\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void task_sacred_ash_party_loop(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B78AE\n\t"
        "	ldr r5, _081B7858\n\t"
        "	ldr r2, [r5]\n\t"
        "	movs r0, #0x86\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r2, r0\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r0, [r1, r3]\n\t"
        "	ldr r3, _081B785C\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B7826\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r3, r1]\n\t"
        "	movs r6, #0x87\n\t"
        "	lsls r6, r6, #2\n\t"
        "	adds r0, r2, r6\n\t"
        "	strh r1, [r0]\n\t"
        "_081B7826:\n\t"
        "	ldrb r0, [r3, #9]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r3, #9]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	cmp r0, #6\n\t"
        "	bne _081B78A8\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _081B7860\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	cmp r1, #0\n\t"
        "	bne _081B786C\n\t"
        "	ldr r0, _081B7864\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _081B7868\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	b _081B787C\n\t"
        "	.align 2, 0\n\t"
        "_081B7858: .4byte sPartyMenuInternal\n\t"
        "_081B785C: .4byte gPartyMenu\n\t"
        "_081B7860: .4byte 0x0000021A\n\t"
        "_081B7864: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B7868: .4byte gUnknown_85C97BD + 0x33A\n\t"
        "_081B786C:\n\t"
        "	ldr r1, _081B7894\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _081B7898\n\t"
        "	ldrh r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "_081B787C:\n\t"
        "	ldr r1, _081B789C\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B78A0\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r1, _081B78A4\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1, #9]\n\t"
        "	b _081B78AE\n\t"
        "	.align 2, 0\n\t"
        "_081B7894: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B7898: .4byte gSpecialVar_ItemId\n\t"
        "_081B789C: .4byte gTasks\n\t"
        "_081B78A0: .4byte sub_081B6434 + 1\n\t"
        "_081B78A4: .4byte gPartyMenu\n\t"
        "_081B78A8:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B76CC\n\t"
        "_081B78AE:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B78B4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r0, _081B78FC\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B7900\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7904\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r4, _081B7908\n\t"
        "	ldr r1, _081B790C\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B7910\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7914\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B78FC: .4byte gPartyMenu\n\t"
        "_081B7900: .4byte gPlayerParty\n\t"
        "_081B7904: .4byte gStringVar1\n\t"
        "_081B7908: .4byte gStringVar4\n\t"
        "_081B790C: .4byte gText_PkmnHPRestoredByVar2\n\t"
        "_081B7910: .4byte gTasks\n\t"
        "_081B7914: .4byte task_sacred_ash_party_loop + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7918(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r2, _081B7964\n\t"
        "	ldr r1, _081B7968\n\t"
        "	ldr r0, [r1]\n\t"
        "	str r0, [r2]\n\t"
        "	ldrb r0, [r1, #9]\n\t"
        "	ldr r4, _081B796C\n\t"
        "	ldrh r1, [r4]\n\t"
        "	movs r2, #0\n\t"
        "	bl ExecuteTableBasedItemEffect__\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B797C\n\t"
        "	ldr r1, _081B7970\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _081B7974\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B7978\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	str r6, [r0]\n\t"
        "	b _081B7988\n\t"
        "	.align 2, 0\n\t"
        "_081B7964: .4byte gCB2_AfterEvolution\n\t"
        "_081B7968: .4byte gPartyMenu\n\t"
        "_081B796C: .4byte gSpecialVar_ItemId\n\t"
        "_081B7970: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B7974: .4byte gUnknown_85C97BD + 0x33A\n\t"
        "_081B7978: .4byte gTasks\n\t"
        "_081B797C:\n\t"
        "	ldrh r0, [r4]\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "	bl FreePartyPointers\n\t"
        "_081B7988:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetItemEffectType(u16 item)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	adds r2, r1, #0\n\t"
        "	subs r2, #0xd\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xa5\n\t"
        "	bls _081B79A4\n\t"
        "	b _081B7AE4\n\t"
        "_081B79A4:\n\t"
        "	cmp r1, #0xaf\n\t"
        "	bne _081B79BC\n\t"
        "	ldr r0, _081B79B4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _081B79B8\n\t"
        "	adds r4, r0, r1\n\t"
        "	b _081B79C4\n\t"
        "	.align 2, 0\n\t"
        "_081B79B4: .4byte gSaveBlock1Ptr\n\t"
        "_081B79B8: .4byte 0x00003214\n\t"
        "_081B79BC:\n\t"
        "	ldr r1, _081B79EC\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r4, [r0]\n\t"
        "_081B79C4:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r5, #0x3f\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B79E6\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B79E6\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B79E6\n\t"
        "	ldrb r3, [r4, #3]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B79F0\n\t"
        "_081B79E6:\n\t"
        "	movs r0, #0\n\t"
        "	b _081B7AEA\n\t"
        "	.align 2, 0\n\t"
        "_081B79EC: .4byte gUnknown_82EEF14\n\t"
        "_081B79F0:\n\t"
        "	movs r2, #0x40\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B79FE\n\t"
        "	movs r0, #0xa\n\t"
        "	b _081B7AEA\n\t"
        "_081B79FE:\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r0, r3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7A0A\n\t"
        "	movs r0, #1\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A0A:\n\t"
        "	adds r2, r5, #0\n\t"
        "	ands r2, r3\n\t"
        "	cmp r2, #0\n\t"
        "	bne _081B7A18\n\t"
        "	lsrs r0, r1, #7\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7A5A\n\t"
        "_081B7A18:\n\t"
        "	cmp r2, #0x20\n\t"
        "	bne _081B7A20\n\t"
        "	movs r0, #4\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A20:\n\t"
        "	cmp r2, #0x10\n\t"
        "	bne _081B7A28\n\t"
        "	movs r0, #3\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A28:\n\t"
        "	cmp r2, #8\n\t"
        "	bne _081B7A30\n\t"
        "	movs r0, #5\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A30:\n\t"
        "	cmp r2, #4\n\t"
        "	bne _081B7A38\n\t"
        "	movs r0, #6\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A38:\n\t"
        "	cmp r2, #2\n\t"
        "	bne _081B7A40\n\t"
        "	movs r0, #7\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A40:\n\t"
        "	cmp r2, #1\n\t"
        "	bne _081B7A48\n\t"
        "	movs r0, #8\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A48:\n\t"
        "	lsrs r0, r1, #7\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7A56\n\t"
        "	cmp r2, #0\n\t"
        "	bne _081B7A56\n\t"
        "	movs r0, #9\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A56:\n\t"
        "	movs r0, #0xb\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A5A:\n\t"
        "	ldrb r1, [r4, #4]\n\t"
        "	movs r0, #0x44\n\t"
        "	ands r0, r1\n\t"
        "	adds r2, r1, #0\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7A6A\n\t"
        "	movs r0, #2\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A6A:\n\t"
        "	movs r5, #2\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7A78\n\t"
        "	movs r0, #0xc\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A78:\n\t"
        "	movs r3, #1\n\t"
        "	adds r0, r3, #0\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7A86\n\t"
        "	movs r0, #0xd\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A86:\n\t"
        "	ldrb r1, [r4, #5]\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7A94\n\t"
        "	movs r0, #0xe\n\t"
        "	b _081B7AEA\n\t"
        "_081B7A94:\n\t"
        "	movs r0, #4\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7AA0\n\t"
        "	movs r0, #0xf\n\t"
        "	b _081B7AEA\n\t"
        "_081B7AA0:\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7AAC\n\t"
        "	movs r0, #0x10\n\t"
        "	b _081B7AEA\n\t"
        "_081B7AAC:\n\t"
        "	adds r0, r3, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7AB8\n\t"
        "	movs r0, #0x11\n\t"
        "	b _081B7AEA\n\t"
        "_081B7AB8:\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7AC4\n\t"
        "	movs r0, #0x12\n\t"
        "	b _081B7AEA\n\t"
        "_081B7AC4:\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7AD0\n\t"
        "	movs r0, #0x13\n\t"
        "	b _081B7AEA\n\t"
        "_081B7AD0:\n\t"
        "	movs r0, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7ADC\n\t"
        "	movs r0, #0x14\n\t"
        "	b _081B7AEA\n\t"
        "_081B7ADC:\n\t"
        "	movs r0, #0x18\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B7AE8\n\t"
        "_081B7AE4:\n\t"
        "	movs r0, #0x16\n\t"
        "	b _081B7AEA\n\t"
        "_081B7AE8:\n\t"
        "	movs r0, #0x15\n\t"
        "_081B7AEA:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7AF0(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r0, _081B7B70\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B7BBC\n\t"
        "	ldr r7, _081B7B74\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r7, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B7B78\n\t"
        "	adds r5, r1, r0\n\t"
        "	movs r0, #0xe\n\t"
        "	adds r0, r0, r7\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _081B7B7C\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r4, _081B7B80\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetTutorMove\n\t"
        "	strh r0, [r7, #0xe]\n\t"
        "	ldr r0, _081B7B84\n\t"
        "	movs r2, #0xe\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r2, _081B7B88\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	movs r0, #2\n\t"
        "	mov r1, r8\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	ldrb r2, [r4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl CanMonLearnTMTutor\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B7B90\n\t"
        "	cmp r0, #2\n\t"
        "	beq _081B7B98\n\t"
        "	ldrh r1, [r7, #0xe]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GiveMoveToMon\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ldr r1, _081B7B8C\n\t"
        "	cmp r0, r1\n\t"
        "	beq _081B7BA8\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_081B6B68\n\t"
        "	b _081B7BBC\n\t"
        "	.align 2, 0\n\t"
        "_081B7B70: .4byte gPaletteFade\n\t"
        "_081B7B74: .4byte gPartyMenu\n\t"
        "_081B7B78: .4byte gPlayerParty\n\t"
        "_081B7B7C: .4byte gStringVar1\n\t"
        "_081B7B80: .4byte gSpecialVar_0x8005\n\t"
        "_081B7B84: .4byte gStringVar2\n\t"
        "_081B7B88: .4byte gMoveNames\n\t"
        "_081B7B8C: .4byte 0xFFFF0000\n\t"
        "_081B7B90:\n\t"
        "	ldr r1, _081B7B94\n\t"
        "	b _081B7B9A\n\t"
        "	.align 2, 0\n\t"
        "_081B7B94: .4byte gUnknown_85C97BD + 0x5BF\n\t"
        "_081B7B98:\n\t"
        "	ldr r1, _081B7BA4\n\t"
        "_081B7B9A:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_081B6A50\n\t"
        "	b _081B7BBC\n\t"
        "	.align 2, 0\n\t"
        "_081B7BA4: .4byte gUnknown_85C97BD + 0x6BC\n\t"
        "_081B7BA8:\n\t"
        "	ldr r0, _081B7BC8\n\t"
        "	bl DisplayLearnMoveMessage\n\t"
        "	ldr r1, _081B7BCC\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7BD0\n\t"
        "	str r1, [r0]\n\t"
        "_081B7BBC:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7BC8: .4byte gUnknown_85C97BD + 0x5E4\n\t"
        "_081B7BCC: .4byte gTasks\n\t"
        "_081B7BD0: .4byte sub_081B6CA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CB2_PartyMenuFromStartMenu(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B7BF8\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B7BFC\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7BF8: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B7BFC: .4byte CB2_ReturnToFieldWithOpenMenu + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7C00(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	bl CurrentBattlePyramidLocation\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _081B7C38\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B7C12\n\t"
        "	ldr r1, _081B7C3C\n\t"
        "_081B7C12:\n\t"
        "	movs r0, #6\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B7C40\n\t"
        "	str r0, [sp, #4]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #5\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	ldr r1, _081B7C44\n\t"
        "	ldr r0, _081B7C48\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7C38: .4byte sub_081C478C + 1\n\t"
        "_081B7C3C: .4byte c2_815ABFC + 1\n\t"
        "_081B7C40: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B7C44: .4byte gPartyMenu\n\t"
        "_081B7C48: .4byte gSpecialVar_ItemId\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7C4C(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r6, r4, #0\n\t"
        "	ldr r5, _081B7C8C\n\t"
        "	ldr r0, _081B7C90\n\t"
        "	mov sb, r0\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	movs r1, #0x64\n\t"
        "	mov r8, r1\n\t"
        "	mov r1, r8\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r7, _081B7C94\n\t"
        "	adds r0, r0, r7\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B7C98\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B7CE4\n\t"
        "	b _081B7CD0\n\t"
        "	.align 2, 0\n\t"
        "_081B7C8C: .4byte sPartyMenuItemId\n\t"
        "_081B7C90: .4byte gPartyMenu\n\t"
        "_081B7C94: .4byte gPlayerParty\n\t"
        "_081B7C98:\n\t"
        "	ldrh r0, [r5]\n\t"
        "	bl ItemIsMail\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7CAC\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B8058\n\t"
        "	b _081B7CD0\n\t"
        "_081B7CAC:\n\t"
        "	mov r1, sb\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	mov r1, r8\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrh r1, [r5]\n\t"
        "	movs r2, #1\n\t"
        "	bl DisplayAlreadyHoldingItemSwitchMessage\n\t"
        "	ldr r1, _081B7CDC\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7CE0\n\t"
        "	str r1, [r0]\n\t"
        "_081B7CD0:\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7CDC: .4byte gTasks\n\t"
        "_081B7CE0: .4byte sub_081B7F40 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7CE4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r5, _081B7D10\n\t"
        "	ldrh r0, [r5, #0xc]\n\t"
        "	bl ItemIsMail\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7D1C\n\t"
        "	ldrh r0, [r5, #0xc]\n\t"
        "	bl sub_081B8090\n\t"
        "	ldr r0, _081B7D14\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _081B7D18\n\t"
        "	str r0, [r1, #4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "	b _081B7D22\n\t"
        "	.align 2, 0\n\t"
        "_081B7D10: .4byte gPartyMenu\n\t"
        "_081B7D14: .4byte sPartyMenuInternal\n\t"
        "_081B7D18: .4byte sub_081B7DEC + 1\n\t"
        "_081B7D1C:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B7D28\n\t"
        "_081B7D22:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_081B7D28(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r0, _081B7D90\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B7D84\n\t"
        "	ldr r4, _081B7D94\n\t"
        "	ldrh r5, [r4, #0xc]\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r4, r0]\n\t"
        "	movs r1, #0x64\n\t"
        "	mov r8, r1\n\t"
        "	mov r1, r8\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r6, _081B7D98\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r1, r5, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl DisplayGaveHeldItemMessage\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r4, r0]\n\t"
        "	mov r1, r8\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GiveItemToMon\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_081B8090\n\t"
        "	ldr r1, _081B7D9C\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7DA0\n\t"
        "	str r1, [r0]\n\t"
        "_081B7D84:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7D90: .4byte gPaletteFade\n\t"
        "_081B7D94: .4byte gPartyMenu\n\t"
        "_081B7D98: .4byte gPlayerParty\n\t"
        "_081B7D9C: .4byte gTasks\n\t"
        "_081B7DA0: .4byte sub_081B7DA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7DA4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _081B7DE0\n\t"
        "	ldrb r4, [r0, #9]\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B7DD8\n\t"
        "	lsls r2, r4, #0x18\n\t"
        "	asrs r2, r2, #0x18\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r2, r0\n\t"
        "	ldr r1, _081B7DE4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B7DE8\n\t"
        "	lsls r2, r2, #4\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl UpdatePartyMonHeldItemSprite\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "_081B7DD8:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7DE0: .4byte gPartyMenu\n\t"
        "_081B7DE4: .4byte gPlayerParty\n\t"
        "_081B7DE8: .4byte sPartyMenuBoxes\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7DEC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r4, _081B7E34\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r4, r0]\n\t"
        "	movs r6, #0x64\n\t"
        "	muls r0, r6, r0\n\t"
        "	ldr r5, _081B7E38\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrh r1, [r4, #0xc]\n\t"
        "	bl GiveItemToMon\n\t"
        "	movs r0, #9\n\t"
        "	ldrsb r0, [r4, r0]\n\t"
        "	muls r0, r6, r0\n\t"
        "	adds r0, r0, r5\n\t"
        "	movs r1, #0x40\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _081B7E3C\n\t"
        "	lsls r2, r0, #3\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldr r0, _081B7E40\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _081B7E44\n\t"
        "	movs r0, #4\n\t"
        "	movs r3, #3\n\t"
        "	bl DoEasyChatScreen\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7E34: .4byte gPartyMenu\n\t"
        "_081B7E38: .4byte gPlayerParty\n\t"
        "_081B7E3C: .4byte gSaveBlock1Ptr\n\t"
        "_081B7E40: .4byte 0x00002BE0\n\t"
        "_081B7E44: .4byte sub_081B7E48 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7E48(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r6, _081B7E98\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r6, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B7E9C\n\t"
        "	adds r5, r1, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	ldr r0, _081B7EA0\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B7EA8\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl TakeMailFromMon\n\t"
        "	ldr r4, _081B7EA4\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xc\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl SetMonData\n\t"
        "	ldrh r0, [r4]\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl sub_081B80BC\n\t"
        "	ldr r0, [r6]\n\t"
        "	bl SetMainCallback2\n\t"
        "	b _081B7EC4\n\t"
        "	.align 2, 0\n\t"
        "_081B7E98: .4byte gPartyMenu\n\t"
        "_081B7E9C: .4byte gPlayerParty\n\t"
        "_081B7EA0: .4byte gSpecialVar_Result\n\t"
        "_081B7EA4: .4byte sPartyMenuItemId\n\t"
        "_081B7EA8:\n\t"
        "	ldrb r0, [r6, #8]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	ldrb r2, [r6, #0xb]\n\t"
        "	movs r1, #0x7f\n\t"
        "	str r1, [sp]\n\t"
        "	ldr r1, _081B7ECC\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, [r6]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #0xff\n\t"
        "	movs r3, #1\n\t"
        "	bl InitPartyMenu\n\t"
        "_081B7EC4:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7ECC: .4byte sub_081B7ED0 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7ED0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _081B7EF8\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B7F2A\n\t"
        "	ldr r1, _081B7EFC\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7F04\n\t"
        "	ldr r0, _081B7F00\n\t"
        "	ldrh r0, [r0, #0xc]\n\t"
        "	ldrh r1, [r1]\n\t"
        "	movs r2, #0\n\t"
        "	bl DisplaySwitchedHeldItemMessage\n\t"
        "	b _081B7F1C\n\t"
        "	.align 2, 0\n\t"
        "_081B7EF8: .4byte gPaletteFade\n\t"
        "_081B7EFC: .4byte sPartyMenuItemId\n\t"
        "_081B7F00: .4byte gPartyMenu\n\t"
        "_081B7F04:\n\t"
        "	ldr r2, _081B7F30\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r2, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B7F34\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r2, #0xc]\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl DisplayGaveHeldItemMessage\n\t"
        "_081B7F1C:\n\t"
        "	ldr r0, _081B7F38\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B7F3C\n\t"
        "	str r0, [r1]\n\t"
        "_081B7F2A:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7F30: .4byte gPartyMenu\n\t"
        "_081B7F34: .4byte gPlayerParty\n\t"
        "_081B7F38: .4byte gTasks\n\t"
        "_081B7F3C: .4byte sub_081B7DA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7F40(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsPartyMenuTextPrinterActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B7F64\n\t"
        "	bl sub_081B2FDC\n\t"
        "	ldr r0, _081B7F6C\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B7F70\n\t"
        "	str r0, [r1]\n\t"
        "_081B7F64:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B7F6C: .4byte gTasks\n\t"
        "_081B7F70: .4byte sub_081B7F74 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B7F74(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	bl Menu_ProcessInputNoWrapClearOnChoose\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r1, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B7F9A\n\t"
        "	cmp r1, #0\n\t"
        "	bgt _081B7F94\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r1, r0\n\t"
        "	beq _081B8034\n\t"
        "	b _081B8048\n\t"
        "_081B7F94:\n\t"
        "	cmp r1, #1\n\t"
        "	beq _081B803A\n\t"
        "	b _081B8048\n\t"
        "_081B7F9A:\n\t"
        "	ldr r7, _081B7FCC\n\t"
        "	ldrh r4, [r7, #0xc]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B8090\n\t"
        "	ldr r6, _081B7FD0\n\t"
        "	ldrh r0, [r6]\n\t"
        "	movs r1, #1\n\t"
        "	bl AddBagItem\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B7FD8\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081B80BC\n\t"
        "	ldrh r0, [r6]\n\t"
        "	bl BufferBagFullCantTakeItemMessage\n\t"
        "	ldr r0, _081B7FD4\n\t"
        "	movs r1, #0\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	b _081B8018\n\t"
        "	.align 2, 0\n\t"
        "_081B7FCC: .4byte gPartyMenu\n\t"
        "_081B7FD0: .4byte sPartyMenuItemId\n\t"
        "_081B7FD4: .4byte gStringVar4\n\t"
        "_081B7FD8:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ItemIsMail\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B7FFC\n\t"
        "	ldr r0, _081B7FF4\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _081B7FF8\n\t"
        "	str r0, [r1, #4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "	b _081B8048\n\t"
        "	.align 2, 0\n\t"
        "_081B7FF4: .4byte sPartyMenuInternal\n\t"
        "_081B7FF8: .4byte sub_081B7DEC + 1\n\t"
        "_081B7FFC:\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r7, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B8028\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GiveItemToMon\n\t"
        "	ldrh r1, [r6]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl DisplaySwitchedHeldItemMessage\n\t"
        "_081B8018:\n\t"
        "	ldr r1, _081B802C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B8030\n\t"
        "	str r1, [r0]\n\t"
        "	b _081B8048\n\t"
        "	.align 2, 0\n\t"
        "_081B8028: .4byte gPlayerParty\n\t"
        "_081B802C: .4byte gTasks\n\t"
        "_081B8030: .4byte sub_081B7DA4 + 1\n\t"
        "_081B8034:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "_081B803A:\n\t"
        "	ldr r0, _081B8050\n\t"
        "	lsls r1, r5, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B8054\n\t"
        "	str r0, [r1]\n\t"
        "_081B8048:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8050: .4byte gTasks\n\t"
        "_081B8054: .4byte sub_081B7DA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8058(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _081B8084\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r1, _081B8088\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B808C\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8084: .4byte gUnknown_85C97BD + 0x49F\n\t"
        "_081B8088: .4byte gTasks\n\t"
        "_081B808C: .4byte sub_081B7DA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8090(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	ldr r0, _081B80AC\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	cmp r0, #6\n\t"
        "	bne _081B80B0\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #1\n\t"
        "	bl RemovePCItem\n\t"
        "	b _081B80B8\n\t"
        "	.align 2, 0\n\t"
        "_081B80AC: .4byte gPartyMenu\n\t"
        "_081B80B0:\n\t"
        "	adds r0, r1, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl RemoveBagItem\n\t"
        "_081B80B8:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B80BC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	ldr r0, _081B80D4\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	cmp r0, #5\n\t"
        "	beq _081B80D8\n\t"
        "	adds r0, r1, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl AddPCItem\n\t"
        "	b _081B80E0\n\t"
        "	.align 2, 0\n\t"
        "_081B80D4: .4byte gPartyMenu\n\t"
        "_081B80D8:\n\t"
        "	adds r0, r1, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl AddBagItem\n\t"
        "_081B80E0:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B80E8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	movs r0, #6\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B810C\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B8110\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #7\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B810C: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B8110: .4byte Mailbox_ReturnToMailListAfterDeposit + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8114(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r0, _081B8160\n\t"
        "	movs r1, #9\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B8164\n\t"
        "	adds r5, r1, r0\n\t"
        "	ldr r1, _081B8168\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r2, _081B816C\n\t"
        "	ldr r0, _081B8170\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r1, #6\n\t"
        "	ldrh r0, [r0, #2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081B8174\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r4, r1, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B817C\n\t"
        "	ldr r0, _081B8178\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "	b _081B8192\n\t"
        "	.align 2, 0\n\t"
        "_081B8160: .4byte gPartyMenu\n\t"
        "_081B8164: .4byte gPlayerParty\n\t"
        "_081B8168: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B816C: .4byte gSaveBlock1Ptr\n\t"
        "_081B8170: .4byte gUnknown_203B984\n\t"
        "_081B8174: .4byte 0x00002BE0\n\t"
        "_081B8178: .4byte gUnknown_85C97BD + 0x54F\n\t"
        "_081B817C:\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GiveMailToMon\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ClearMail\n\t"
        "	ldr r0, _081B81AC\n\t"
        "	movs r1, #1\n\t"
        "	bl DisplayPartyMenuMessage\n\t"
        "_081B8192:\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	ldr r0, _081B81B0\n\t"
        "	lsls r1, r6, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B81B4\n\t"
        "	str r0, [r1]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B81AC: .4byte gUnknown_85C97BD + 0x575\n\t"
        "_081B81B0: .4byte gTasks\n\t"
        "_081B81B4: .4byte sub_081B7DA4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InitChooseHalfPartyForBattle(u8 unused)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	bl sub_081B81F8\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B81E8\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B81EC\n\t"
        "	ldr r0, [r0, #8]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #4\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	ldr r1, _081B81F0\n\t"
        "	ldr r0, _081B81F4\n\t"
        "	str r0, [r1, #4]\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B81E8: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B81EC: .4byte gMain\n\t"
        "_081B81F0: .4byte gPartyMenu\n\t"
        "_081B81F4: .4byte sub_081B843C + 1\n\t"
        ".syntax divided\n\t"
    );
}

void sub_081B81F8(void)
{
    memset(gSelectedOrderFromParty, 0, 4);
}

__attribute__((naked)) static u8 GetPartySlotEntryStatus(s8 slotId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r4, r0, #0x18\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r4, r0\n\t"
        "	ldr r1, _081B8228\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl GetBattleEntryEligibility\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B822C\n\t"
        "	movs r0, #2\n\t"
        "	b _081B8244\n\t"
        "	.align 2, 0\n\t"
        "_081B8228: .4byte gPlayerParty\n\t"
        "_081B822C:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl sub_081B8410\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B8242\n\t"
        "	movs r0, #0\n\t"
        "	b _081B8244\n\t"
        "_081B8242:\n\t"
        "	movs r0, #1\n\t"
        "_081B8244:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetBattleEntryEligibility(void *battleEntry)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	movs r6, #0\n\t"
        "	movs r1, #0x2d\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B82A8\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x38\n\t"
        "	bl GetMonData3\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl sub_081B8528\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	bhi _081B82A8\n\t"
        "	ldr r0, _081B82AC\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "	ldr r0, _081B82B0\n\t"
        "	cmp r1, r0\n\t"
        "	bne _081B828A\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B82A8\n\t"
        "_081B828A:\n\t"
        "	ldr r0, _081B82B4\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #8\n\t"
        "	beq _081B82EA\n\t"
        "	cmp r0, #9\n\t"
        "	bne _081B82B8\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B82EA\n\t"
        "_081B82A8:\n\t"
        "	movs r0, #0\n\t"
        "	b _081B82EC\n\t"
        "	.align 2, 0\n\t"
        "_081B82AC: .4byte gSaveBlock1Ptr\n\t"
        "_081B82B0: .4byte 0x0000191A\n\t"
        "_081B82B4: .4byte 0x000040CF\n\t"
        "_081B82B8:\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	ldr r3, _081B82F4\n\t"
        "	lsls r1, r6, #1\n\t"
        "	adds r0, r1, r3\n\t"
        "	ldrh r0, [r0]\n\t"
        "	ldr r2, _081B82F8\n\t"
        "	cmp r0, r2\n\t"
        "	beq _081B82EA\n\t"
        "_081B82D2:\n\t"
        "	adds r0, r1, r3\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r4\n\t"
        "	beq _081B82A8\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	lsls r1, r6, #1\n\t"
        "	adds r0, r1, r3\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _081B82D2\n\t"
        "_081B82EA:\n\t"
        "	movs r0, #1\n\t"
        "_081B82EC:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B82F4: .4byte gUnknown_85DD48E\n\t"
        "_081B82F8: .4byte 0x0000FFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B82FC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	bl sub_081B84FC\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	adds r1, r2, #0\n\t"
        "	ldr r3, _081B8324\n\t"
        "	adds r0, r2, r3\n\t"
        "	subs r0, #1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B833C\n\t"
        "	cmp r2, #1\n\t"
        "	bne _081B8328\n\t"
        "	movs r0, #0xe\n\t"
        "	b _081B83F8\n\t"
        "	.align 2, 0\n\t"
        "_081B8324: .4byte gSelectedOrderFromParty\n\t"
        "_081B8328:\n\t"
        "	ldr r0, _081B8338\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	movs r0, #0x11\n\t"
        "	b _081B83F8\n\t"
        "	.align 2, 0\n\t"
        "_081B8338: .4byte gStringVar1\n\t"
        "_081B833C:\n\t"
        "	ldr r0, _081B8354\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	movs r1, #0xf8\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _081B8360\n\t"
        "	b _081B83F6\n\t"
        "	.align 2, 0\n\t"
        "_081B8354: .4byte 0x000040CF\n\t"
        "_081B8358:\n\t"
        "	movs r0, #0x12\n\t"
        "	b _081B83F8\n\t"
        "_081B835C:\n\t"
        "	movs r0, #0x13\n\t"
        "	b _081B83F8\n\t"
        "_081B8360:\n\t"
        "	bl GetMaxBattleEntries\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	movs r5, #0\n\t"
        "	b _081B83F0\n\t"
        "_081B836E:\n\t"
        "	ldr r3, _081B8408\n\t"
        "	adds r4, r3, r5\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	subs r0, #0x64\n\t"
        "	ldr r3, _081B840C\n\t"
        "	adds r0, r3, r0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sl, r0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	subs r0, #0x64\n\t"
        "	ldr r3, _081B840C\n\t"
        "	adds r0, r3, r0\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	adds r1, r5, #1\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	mov sb, r1\n\t"
        "	cmp r4, r8\n\t"
        "	bhs _081B83E8\n\t"
        "	movs r7, #0x64\n\t"
        "_081B83AE:\n\t"
        "	ldr r0, _081B8408\n\t"
        "	adds r5, r0, r4\n\t"
        "	ldrb r0, [r5]\n\t"
        "	muls r0, r7, r0\n\t"
        "	subs r0, #0x64\n\t"
        "	ldr r1, _081B840C\n\t"
        "	adds r0, r1, r0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp sl, r0\n\t"
        "	beq _081B8358\n\t"
        "	cmp r6, #0\n\t"
        "	beq _081B83DE\n\t"
        "	ldrb r0, [r5]\n\t"
        "	muls r0, r7, r0\n\t"
        "	subs r0, #0x64\n\t"
        "	ldr r3, _081B840C\n\t"
        "	adds r0, r3, r0\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r6, r0\n\t"
        "	beq _081B835C\n\t"
        "_081B83DE:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, r8\n\t"
        "	blo _081B83AE\n\t"
        "_081B83E8:\n\t"
        "	mov r1, sb\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	mov r0, r8\n\t"
        "_081B83F0:\n\t"
        "	subs r0, #1\n\t"
        "	cmp r5, r0\n\t"
        "	blt _081B836E\n\t"
        "_081B83F6:\n\t"
        "	movs r0, #0xff\n\t"
        "_081B83F8:\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B8408: .4byte gSelectedOrderFromParty\n\t"
        "_081B840C: .4byte gPlayerParty\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8410(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	ldr r3, _081B8428\n\t"
        "_081B841A:\n\t"
        "	adds r0, r1, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _081B842C\n\t"
        "	movs r0, #1\n\t"
        "	b _081B8438\n\t"
        "	.align 2, 0\n\t"
        "_081B8428: .4byte gSelectedOrderFromParty\n\t"
        "_081B842C:\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #3\n\t"
        "	bls _081B841A\n\t"
        "	movs r0, #0\n\t"
        "_081B8438:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B843C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	bl sub_081B82FC\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xff\n\t"
        "	beq _081B8474\n\t"
        "	movs r0, #0x20\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "	ldr r0, _081B846C\n\t"
        "	lsls r1, r5, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B8470\n\t"
        "	str r0, [r1]\n\t"
        "	b _081B8480\n\t"
        "	.align 2, 0\n\t"
        "_081B846C: .4byte gTasks\n\t"
        "_081B8470: .4byte sub_081B8488 + 1\n\t"
        "_081B8474:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "_081B8480:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8488(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _081B84C4\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B84A2\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B84BC\n\t"
        "_081B84A2:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	movs r0, #0\n\t"
        "	bl DisplayPartyMenuStdMessage\n\t"
        "	ldr r0, _081B84C8\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B84CC\n\t"
        "	str r0, [r1]\n\t"
        "_081B84BC:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B84C4: .4byte gMain\n\t"
        "_081B84C8: .4byte gTasks\n\t"
        "_081B84CC: .4byte Task_HandleChooseMonInput + 1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) u8 GetMaxBattleEntries(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _081B84E8\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #8\n\t"
        "	beq _081B84EC\n\t"
        "	cmp r0, #9\n\t"
        "	bne _081B84F0\n\t"
        "	movs r0, #3\n\t"
        "	b _081B84F4\n\t"
        "	.align 2, 0\n\t"
        "_081B84E8: .4byte 0x000040CF\n\t"
        "_081B84EC:\n\t"
        "	movs r0, #2\n\t"
        "	b _081B84F4\n\t"
        "_081B84F0:\n\t"
        "	ldr r0, _081B84F8\n\t"
        "	ldrb r0, [r0]\n\t"
        "_081B84F4:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B84F8: .4byte gSpecialVar_0x8005\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B84FC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _081B8514\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #8\n\t"
        "	beq _081B8518\n\t"
        "	cmp r0, #9\n\t"
        "	bne _081B851C\n\t"
        "	movs r0, #1\n\t"
        "	b _081B8520\n\t"
        "	.align 2, 0\n\t"
        "_081B8514: .4byte 0x000040CF\n\t"
        "_081B8518:\n\t"
        "	movs r0, #2\n\t"
        "	b _081B8520\n\t"
        "_081B851C:\n\t"
        "	ldr r0, _081B8524\n\t"
        "	ldrb r0, [r0]\n\t"
        "_081B8520:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B8524: .4byte gSpecialVar_0x8005\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8528(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _081B8540\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #8\n\t"
        "	beq _081B8544\n\t"
        "	cmp r0, #9\n\t"
        "	bne _081B8548\n\t"
        "_081B853C:\n\t"
        "	movs r0, #0x64\n\t"
        "	b _081B8552\n\t"
        "	.align 2, 0\n\t"
        "_081B8540: .4byte 0x000040CF\n\t"
        "_081B8544:\n\t"
        "	movs r0, #0x1e\n\t"
        "	b _081B8552\n\t"
        "_081B8548:\n\t"
        "	ldr r0, _081B8558\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B853C\n\t"
        "	movs r0, #0x32\n\t"
        "_081B8552:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B8558: .4byte gSpecialVar_0x8004\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 *sub_081B855C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _081B8578\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	movs r2, #0xf8\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _081B8580\n\t"
        "	ldr r0, _081B857C\n\t"
        "	b _081B859A\n\t"
        "	.align 2, 0\n\t"
        "_081B8578: .4byte 0x000040CF\n\t"
        "_081B857C: .4byte gUnknown_85C97BD + 0xA5F\n\t"
        "_081B8580:\n\t"
        "	cmp r1, #1\n\t"
        "	bne _081B8598\n\t"
        "	ldr r0, _081B8590\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _081B8598\n\t"
        "	ldr r0, _081B8594\n\t"
        "	b _081B859A\n\t"
        "	.align 2, 0\n\t"
        "_081B8590: .4byte gSpecialVar_0x8005\n\t"
        "_081B8594: .4byte gUnknown_85C97BD + 0xA6C\n\t"
        "_081B8598:\n\t"
        "	ldr r0, _081B85A0\n\t"
        "_081B859A:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B85A0: .4byte gUnknown_85C97BD + 0xA7B\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B85A4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r2, #0\n\t"
        "	str r2, [sp]\n\t"
        "	ldr r2, _081B85C8\n\t"
        "	str r2, [sp, #4]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B85C8: .4byte Task_HandleChooseMonInput + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B85CC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	movs r0, #4\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B85F0\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B85F4\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xc\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B85F0: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B85F4: .4byte CB2_ReturnToFieldContinueScriptPlayMapMusic + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B85F8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B861C\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B8620\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0xb\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xd\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B861C: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B8620: .4byte CB2_ReturnToFieldContinueScriptPlayMapMusic + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8624(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl IsDoubleBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B8634\n\t"
        "	movs r0, #0\n\t"
        "	b _081B8646\n\t"
        "_081B8634:\n\t"
        "	bl IsMultiBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B8644\n\t"
        "	movs r0, #1\n\t"
        "	b _081B8646\n\t"
        "_081B8644:\n\t"
        "	movs r0, #2\n\t"
        "_081B8646:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void OpenPartyMenuInBattle(u8 partyAction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl sub_081B8624\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B8688\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B868C\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	bl nullsub_35\n\t"
        "	bl pokemon_change_order\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8688: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B868C: .4byte SetCB2ToReshowScreenAfterMenu2 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8690(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	bl sub_081B8624\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	movs r0, #5\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B86C4\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B86C8\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r2, #3\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	bl nullsub_35\n\t"
        "	bl pokemon_change_order\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B86C4: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B86C8: .4byte c2_815ABFC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) static u8 GetPartyMenuActionsTypeInBattle(struct Pokemon *mon)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r0, _081B86F4\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B8714\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x2d\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B8714\n\t"
        "	ldr r0, _081B86F8\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B86FC\n\t"
        "	movs r0, #3\n\t"
        "	b _081B8716\n\t"
        "	.align 2, 0\n\t"
        "_081B86F4: .4byte gUnknown_20241F4\n\t"
        "_081B86F8: .4byte gPartyMenu\n\t"
        "_081B86FC:\n\t"
        "	ldr r0, _081B8710\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xb\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B8714\n\t"
        "	movs r0, #2\n\t"
        "	b _081B8716\n\t"
        "	.align 2, 0\n\t"
        "_081B8710: .4byte gBattleTypeFlags\n\t"
        "_081B8714:\n\t"
        "	movs r0, #7\n\t"
        "_081B8716:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 TrySwitchInPokemon(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	bl GetCursorSelectionMonId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	bl IsMultiBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B8764\n\t"
        "	cmp r5, #1\n\t"
        "	beq _081B8742\n\t"
        "	cmp r5, #4\n\t"
        "	beq _081B8742\n\t"
        "	cmp r5, #5\n\t"
        "	bne _081B8764\n\t"
        "_081B8742:\n\t"
        "	ldr r4, _081B8758\n\t"
        "	bl GetTrainerPartnerName\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringCopy\n\t"
        "	ldr r0, _081B875C\n\t"
        "	ldr r1, _081B8760\n\t"
        "	b _081B88E2\n\t"
        "	.align 2, 0\n\t"
        "_081B8758: .4byte gStringVar1\n\t"
        "_081B875C: .4byte gStringVar4\n\t"
        "_081B8760: .4byte gUnknown_85C97BD + 0x3B9\n\t"
        "_081B8764:\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r1, r5, #0\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _081B8788\n\t"
        "	adds r4, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B8798\n\t"
        "	ldr r1, _081B878C\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B8790\n\t"
        "	ldr r1, _081B8794\n\t"
        "	b _081B88E2\n\t"
        "	.align 2, 0\n\t"
        "_081B8788: .4byte gPlayerParty\n\t"
        "_081B878C: .4byte gStringVar1\n\t"
        "_081B8790: .4byte gStringVar4\n\t"
        "_081B8794: .4byte gUnknown_85C97BD + 0x39C\n\t"
        "_081B8798:\n\t"
        "	movs r4, #0\n\t"
        "	b _081B87C4\n\t"
        "_081B879C:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B87BE\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetPartyIdFromBattleSlot\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r2, _081B87EC\n\t"
        "	lsls r1, r4, #1\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrh r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _081B889C\n\t"
        "_081B87BE:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "_081B87C4:\n\t"
        "	ldr r0, _081B87F0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r4, r0\n\t"
        "	blo _081B879C\n\t"
        "	movs r7, #0x64\n\t"
        "	adds r0, r5, #0\n\t"
        "	muls r0, r7, r0\n\t"
        "	ldr r1, _081B87F4\n\t"
        "	mov r8, r1\n\t"
        "	adds r6, r0, r1\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0x2d\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B8800\n\t"
        "	ldr r0, _081B87F8\n\t"
        "	ldr r1, _081B87FC\n\t"
        "	b _081B88E2\n\t"
        "	.align 2, 0\n\t"
        "_081B87EC: .4byte gBattlerPartyIndexes\n\t"
        "_081B87F0: .4byte gBattlersCount\n\t"
        "_081B87F4: .4byte gPlayerParty\n\t"
        "_081B87F8: .4byte gStringVar4\n\t"
        "_081B87FC: .4byte gUnknown_85C97BD + 0x3E0\n\t"
        "_081B8800:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetPartyIdFromBattleSlot\n\t"
        "	ldr r1, _081B8824\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, #0x8b\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bne _081B8834\n\t"
        "	ldr r1, _081B8828\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B882C\n\t"
        "	ldr r1, _081B8830\n\t"
        "	b _081B88E2\n\t"
        "	.align 2, 0\n\t"
        "_081B8824: .4byte gBattleStruct\n\t"
        "_081B8828: .4byte gStringVar1\n\t"
        "_081B882C: .4byte gStringVar4\n\t"
        "_081B8830: .4byte gUnknown_85C97BD + 0x386\n\t"
        "_081B8834:\n\t"
        "	ldr r0, _081B8844\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	cmp r0, #4\n\t"
        "	bne _081B8848\n\t"
        "	bl SetMonPreventsSwitchingString\n\t"
        "	b _081B88E6\n\t"
        "	.align 2, 0\n\t"
        "_081B8844: .4byte gPartyMenu\n\t"
        "_081B8848:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _081B88C0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetPartyIdFromBattleSlot\n\t"
        "	ldr r1, _081B888C\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _081B8890\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _081B8894\n\t"
        "	ldr r0, _081B8898\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl pokemon_order_func\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_081B8C50\n\t"
        "	adds r0, r4, #0\n\t"
        "	muls r0, r7, r0\n\t"
        "	add r0, r8\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl sub_081B0F58\n\t"
        "	movs r0, #1\n\t"
        "	b _081B88E8\n\t"
        "	.align 2, 0\n\t"
        "_081B888C: .4byte gUnknown_203CBB5\n\t"
        "_081B8890: .4byte gPartyMenuUseExitCallback\n\t"
        "_081B8894: .4byte gBattlerPartyIndexes\n\t"
        "_081B8898: .4byte gBattlerInMenuId\n\t"
        "_081B889C:\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r5, r0\n\t"
        "	ldr r1, _081B88B0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B88B4\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B88B8\n\t"
        "	ldr r1, _081B88BC\n\t"
        "	b _081B88E2\n\t"
        "	.align 2, 0\n\t"
        "_081B88B0: .4byte gPlayerParty\n\t"
        "_081B88B4: .4byte gStringVar1\n\t"
        "_081B88B8: .4byte gStringVar4\n\t"
        "_081B88BC: .4byte gUnknown_85C97BD + 0x370\n\t"
        "_081B88C0:\n\t"
        "	ldr r0, _081B88F4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, _081B88F8\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl pokemon_order_func\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	muls r0, r7, r0\n\t"
        "	add r0, r8\n\t"
        "	ldr r1, _081B88FC\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B8900\n\t"
        "	ldr r1, _081B8904\n\t"
        "_081B88E2:\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "_081B88E6:\n\t"
        "	movs r0, #0\n\t"
        "_081B88E8:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B88F4: .4byte gBattlerInMenuId\n\t"
        "_081B88F8: .4byte gBattlerPartyIndexes\n\t"
        "_081B88FC: .4byte gStringVar1\n\t"
        "_081B8900: .4byte gStringVar4\n\t"
        "_081B8904: .4byte gUnknown_85C97BD + 0x35D\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BufferBattlePartyOrder(u8 *partyBattleOrder, u8 flankId);

void BufferBattlePartyCurrentOrder(void)
{
    BufferBattlePartyOrder(gBattlePartyCurrentOrder, (u8)GetPlayerFlankId());
}

__attribute__((naked)) void BufferBattlePartyOrder(u8 *partyBattleOrder, u8 flankId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r6, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r4, r1, #0x18\n\t"
        "	bl IsMultiBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B895E\n\t"
        "	cmp r4, #0\n\t"
        "	beq _081B8950\n\t"
        "	movs r0, #0x30\n\t"
        "	strb r0, [r6]\n\t"
        "	movs r0, #0x45\n\t"
        "	strb r0, [r6, #1]\n\t"
        "	movs r0, #0x12\n\t"
        "	strb r0, [r6, #2]\n\t"
        "	b _081B89F8\n\t"
        "_081B8950:\n\t"
        "	movs r0, #3\n\t"
        "	strb r0, [r6]\n\t"
        "	movs r0, #0x12\n\t"
        "	strb r0, [r6, #1]\n\t"
        "	movs r0, #0x45\n\t"
        "	strb r0, [r6, #2]\n\t"
        "	b _081B89F8\n\t"
        "_081B895E:\n\t"
        "	bl IsDoubleBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B899C\n\t"
        "	movs r5, #1\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	mov r2, sp\n\t"
        "	ldr r1, _081B8998\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r4, #0\n\t"
        "	mov r1, sp\n\t"
        "_081B8982:\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _081B8990\n\t"
        "	mov r2, sp\n\t"
        "	adds r0, r2, r5\n\t"
        "	strb r4, [r0]\n\t"
        "	adds r5, #1\n\t"
        "_081B8990:\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #5\n\t"
        "	ble _081B8982\n\t"
        "	b _081B89E0\n\t"
        "	.align 2, 0\n\t"
        "_081B8998: .4byte gBattlerPartyIndexes\n\t"
        "_081B899C:\n\t"
        "	movs r5, #2\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	mov r1, sp\n\t"
        "	ldr r4, _081B8A00\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #2\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	mov r1, sp\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	movs r4, #0\n\t"
        "_081B89C6:\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _081B89DA\n\t"
        "	ldrb r0, [r1, #1]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _081B89DA\n\t"
        "	mov r2, sp\n\t"
        "	adds r0, r2, r5\n\t"
        "	strb r4, [r0]\n\t"
        "	adds r5, #1\n\t"
        "_081B89DA:\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #5\n\t"
        "	ble _081B89C6\n\t"
        "_081B89E0:\n\t"
        "	movs r4, #0\n\t"
        "	mov r3, sp\n\t"
        "_081B89E4:\n\t"
        "	adds r0, r6, r4\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	ldrb r2, [r3, #1]\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r3, #2\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #2\n\t"
        "	ble _081B89E4\n\t"
        "_081B89F8:\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8A00: .4byte gBattlerPartyIndexes\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BufferBattlePartyOrderBySide(u8 *partyBattleOrder, u8 flankId, u8 battler);

void BufferBattlePartyCurrentOrderBySide(u8 battler, u8 flankId)
{
    BufferBattlePartyOrderBySide(gBattleStruct->battlerPartyOrders[battler], flankId, battler);
}

__attribute__((naked)) void BufferBattlePartyOrderBySide(u8 *partyBattleOrder, u8 flankId, u8 battler)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r0, r2, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r7, r1, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B8A50\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r0, #2\n\t"
        "	b _081B8A5C\n\t"
        "_081B8A50:\n\t"
        "	movs r0, #1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r0, #3\n\t"
        "_081B8A5C:\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	bl IsMultiBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081B8A90\n\t"
        "	cmp r7, #0\n\t"
        "	beq _081B8A82\n\t"
        "	movs r0, #0x30\n\t"
        "	strb r0, [r5]\n\t"
        "	movs r0, #0x45\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	movs r0, #0x12\n\t"
        "	strb r0, [r5, #2]\n\t"
        "	b _081B8B12\n\t"
        "_081B8A82:\n\t"
        "	movs r0, #3\n\t"
        "	strb r0, [r5]\n\t"
        "	movs r0, #0x12\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	movs r0, #0x45\n\t"
        "	strb r0, [r5, #2]\n\t"
        "	b _081B8B12\n\t"
        "_081B8A90:\n\t"
        "	bl IsDoubleBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B8AC8\n\t"
        "	movs r3, #1\n\t"
        "	mov r2, sp\n\t"
        "	ldr r1, _081B8AC4\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r4, #0\n\t"
        "	mov r1, sp\n\t"
        "_081B8AAC:\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _081B8ABA\n\t"
        "	mov r2, sp\n\t"
        "	adds r0, r2, r3\n\t"
        "	strb r4, [r0]\n\t"
        "	adds r3, #1\n\t"
        "_081B8ABA:\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #5\n\t"
        "	ble _081B8AAC\n\t"
        "	b _081B8AFA\n\t"
        "	.align 2, 0\n\t"
        "_081B8AC4: .4byte gBattlerPartyIndexes\n\t"
        "_081B8AC8:\n\t"
        "	movs r3, #2\n\t"
        "	mov r1, sp\n\t"
        "	ldr r2, _081B8B1C\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	lsls r0, r6, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	movs r4, #0\n\t"
        "_081B8AE0:\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _081B8AF4\n\t"
        "	ldrb r0, [r1, #1]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _081B8AF4\n\t"
        "	mov r2, sp\n\t"
        "	adds r0, r2, r3\n\t"
        "	strb r4, [r0]\n\t"
        "	adds r3, #1\n\t"
        "_081B8AF4:\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #5\n\t"
        "	ble _081B8AE0\n\t"
        "_081B8AFA:\n\t"
        "	movs r4, #0\n\t"
        "	mov r3, sp\n\t"
        "_081B8AFE:\n\t"
        "	adds r0, r5, r4\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	ldrb r2, [r3, #1]\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r3, #2\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #2\n\t"
        "	ble _081B8AFE\n\t"
        "_081B8B12:\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8B1C: .4byte gBattlerPartyIndexes\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8B20(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r5, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	movs r7, #0\n\t"
        "	bl IsMultiBattle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B8BCE\n\t"
        "	ldr r0, _081B8B84\n\t"
        "	lsls r1, r4, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	adds r1, #0x60\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "	add r6, sp\n\t"
        "	mov ip, r6\n\t"
        "	movs r6, #0xf\n\t"
        "	mov r3, sp\n\t"
        "_081B8B52:\n\t"
        "	adds r1, r4, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	strb r0, [r3]\n\t"
        "	adds r3, #1\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	adds r3, #1\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #2\n\t"
        "	ble _081B8B52\n\t"
        "	mov r0, ip\n\t"
        "	ldrb r3, [r0]\n\t"
        "	movs r2, #0\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, r5\n\t"
        "	bne _081B8B88\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r7, [r0]\n\t"
        "	strb r3, [r0]\n\t"
        "	b _081B8B9C\n\t"
        "	.align 2, 0\n\t"
        "_081B8B84: .4byte gBattleStruct\n\t"
        "_081B8B88:\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #5\n\t"
        "	bgt _081B8B9C\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r0, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, r5\n\t"
        "	bne _081B8B88\n\t"
        "	adds r7, r0, #0\n\t"
        "	strb r3, [r1]\n\t"
        "_081B8B9C:\n\t"
        "	cmp r2, #6\n\t"
        "	beq _081B8BCE\n\t"
        "	mov r0, ip\n\t"
        "	strb r7, [r0]\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	mov r1, sp\n\t"
        "	ldrb r1, [r1, #1]\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	mov r1, sp\n\t"
        "	ldrb r1, [r1, #3]\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #1]\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	mov r1, sp\n\t"
        "	ldrb r1, [r1, #5]\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "_081B8BCE:\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetPartyIdFromBattleSlot(u8 slotId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r2\n\t"
        "	lsrs r2, r0, #0x19\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B8BF8\n\t"
        "	ldr r0, _081B8BF4\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0xf\n\t"
        "	ands r1, r0\n\t"
        "	b _081B8C00\n\t"
        "	.align 2, 0\n\t"
        "_081B8BF4: .4byte gBattlePartyCurrentOrder\n\t"
        "_081B8BF8:\n\t"
        "	ldr r0, _081B8C08\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsrs r1, r0, #4\n\t"
        "_081B8C00:\n\t"
        "	adds r0, r1, #0\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081B8C08: .4byte gBattlePartyCurrentOrder\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8C0C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r4, r1, #0x18\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r3\n\t"
        "	lsrs r3, r0, #0x19\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B8C34\n\t"
        "	ldr r0, _081B8C30\n\t"
        "	adds r0, r3, r0\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #0xf0\n\t"
        "	ands r1, r2\n\t"
        "	orrs r1, r4\n\t"
        "	strb r1, [r0]\n\t"
        "	b _081B8C44\n\t"
        "	.align 2, 0\n\t"
        "_081B8C30: .4byte gBattlePartyCurrentOrder\n\t"
        "_081B8C34:\n\t"
        "	ldr r2, _081B8C4C\n\t"
        "	adds r2, r3, r2\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	lsls r1, r4, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "_081B8C44:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8C4C: .4byte gBattlePartyCurrentOrder\n\t"
        ".syntax divided\n\t"
    );
}
__attribute__((naked)) void sub_081B8C50(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r6, r6, #0x18\n\t"
        "	lsrs r6, r6, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetPartyIdFromBattleSlot\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetPartyIdFromBattleSlot\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_081B8C0C\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl sub_081B8C0C\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}




__attribute__((naked)) void pokemon_order_func(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r3, #0\n\t"
        "	movs r2, #0\n\t"
        "	ldr r5, _081B8CB4\n\t"
        "_081B8C98:\n\t"
        "	adds r0, r3, r5\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsrs r0, r1, #4\n\t"
        "	cmp r0, r4\n\t"
        "	beq _081B8CB0\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, r4\n\t"
        "	bne _081B8CB8\n\t"
        "_081B8CB0:\n\t"
        "	adds r0, r2, #0\n\t"
        "	b _081B8CCA\n\t"
        "	.align 2, 0\n\t"
        "_081B8CB4: .4byte gBattlePartyCurrentOrder\n\t"
        "_081B8CB8:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	cmp r3, #2\n\t"
        "	bls _081B8C98\n\t"
        "	movs r0, #0\n\t"
        "_081B8CCA:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void pokemon_change_order(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	movs r4, #0x96\n\t"
        "	lsls r4, r4, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Alloc\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r1, _081B8D1C\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl memcpy\n\t"
        "	movs r4, #0\n\t"
        "	movs r6, #0x64\n\t"
        "_081B8CEA:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl pokemon_order_func\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	muls r0, r6, r0\n\t"
        "	ldr r1, _081B8D1C\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r1, r4, #0\n\t"
        "	muls r1, r6, r1\n\t"
        "	adds r1, r1, r5\n\t"
        "	movs r2, #0x64\n\t"
        "	bl memcpy\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #5\n\t"
        "	bls _081B8CEA\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl Free\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8D1C: .4byte gPlayerParty\n\t"
        ".syntax divided\n\t"
    );
}

static void UpdatePartyToFieldOrder(void)
{
    struct Pokemon *partyBuffer = Alloc(sizeof(gPlayerParty));
    u8 i;

    memcpy(partyBuffer, gPlayerParty, sizeof(gPlayerParty));
    for (i = 0; i < PARTY_SIZE; i++)
        memcpy(&gPlayerParty[(u8)GetPartyIdFromBattleSlot(i)], &partyBuffer[i], sizeof(struct Pokemon));
    Free(partyBuffer);
}

__attribute__((naked)) void sub_081B8D70(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	movs r6, #1\n\t"
        "	movs r7, #0x64\n\t"
        "	ldr r0, _081B8DC8\n\t"
        "	mov r8, r0\n\t"
        "_081B8D7E:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetPartyIdFromBattleSlot\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	muls r0, r7, r0\n\t"
        "	mov r1, r8\n\t"
        "	adds r5, r0, r1\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B8DCC\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B8DCC\n\t"
        "	movs r0, #0\n\t"
        "	bl GetPartyIdFromBattleSlot\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl sub_081B8C50\n\t"
        "	adds r0, r4, #0\n\t"
        "	muls r0, r7, r0\n\t"
        "	add r0, r8\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_081B0F58\n\t"
        "	b _081B8DD6\n\t"
        "	.align 2, 0\n\t"
        "_081B8DC8: .4byte gPlayerParty\n\t"
        "_081B8DCC:\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #5\n\t"
        "	bls _081B8D7E\n\t"
        "_081B8DD6:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

void SetCB2ToReshowScreenAfterMenu2(void);

void sub_081B8DE0(void)
{
    SetMainCallback2(SetCB2ToReshowScreenAfterMenu2);
}

__attribute__((naked)) void sub_081B8DF0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	movs r0, #0x7f\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B8E14\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B8E18\n\t"
        "	ldr r0, [r0, #8]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #5\n\t"
        "	movs r1, #3\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8E14: .4byte sub_081B8E1C + 1\n\t"
        "_081B8E18: .4byte gMain\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8E1C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _081B8E4C\n\t"
        "	lsls r4, r0, #2\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r1\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #1\n\t"
        "	strh r1, [r4, #8]\n\t"
        "	bl sub_081B8F34\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #9\n\t"
        "	movs r0, #2\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	ldr r0, _081B8E50\n\t"
        "	str r0, [r4]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8E4C: .4byte gTasks\n\t"
        "_081B8E50: .4byte sub_081B8E54 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8E54(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r6, r5, #2\n\t"
        "	adds r0, r6, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _081B8EC8\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldr r0, _081B8ECC\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B8EC0\n\t"
        "	ldrh r0, [r4]\n\t"
        "	subs r0, #8\n\t"
        "	strh r0, [r4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_081B8F34\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081B8EC0\n\t"
        "	movs r4, #3\n\t"
        "	ldr r7, _081B8ED0\n\t"
        "_081B8E88:\n\t"
        "	subs r0, r4, #3\n\t"
        "	lsls r0, r0, #5\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B8EA4\n\t"
        "	ldr r0, _081B8ED4\n\t"
        "	ldr r1, [r0]\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	movs r1, #0\n\t"
        "	bl AnimateSelectedPartyIcon\n\t"
        "_081B8EA4:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #5\n\t"
        "	bls _081B8E88\n\t"
        "	movs r0, #0x78\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _081B8ED8\n\t"
        "	adds r1, r6, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081B8EDC\n\t"
        "	str r0, [r1]\n\t"
        "_081B8EC0:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8EC8: .4byte gUnknown_3005B68\n\t"
        "_081B8ECC: .4byte gPaletteFade\n\t"
        "_081B8ED0: .4byte gMultiPartnerParty\n\t"
        "_081B8ED4: .4byte sPartyMenuBoxes\n\t"
        "_081B8ED8: .4byte gTasks\n\t"
        "_081B8EDC: .4byte sub_081B8EE0 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8EE0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _081B8F0C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r0]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x11\n\t"
        "	cmp r1, r0\n\t"
        "	bne _081B8F06\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl Task_ClosePartyMenu\n\t"
        "_081B8F06:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8F0C: .4byte gUnknown_3005B68\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8F10(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r3, r1, #0x10\n\t"
        "	cmp r1, #0\n\t"
        "	blt _081B8F2A\n\t"
        "	ldr r1, _081B8F30\n\t"
        "	lsls r0, r2, #4\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r3, [r0, #0x24]\n\t"
        "_081B8F2A:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8F30: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8F34(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _081B8FBC\n\t"
        "	adds r5, r1, r0\n\t"
        "	movs r6, #3\n\t"
        "	ldr r7, _081B8FC0\n\t"
        "_081B8F48:\n\t"
        "	ldr r0, _081B8FC4\n\t"
        "	subs r1, r6, #3\n\t"
        "	lsls r1, r1, #5\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B8FA0\n\t"
        "	ldr r0, [r7]\n\t"
        "	lsls r4, r6, #4\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldrb r0, [r0, #9]\n\t"
        "	ldrh r1, [r5]\n\t"
        "	subs r1, #8\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	bl sub_081B8F10\n\t"
        "	ldr r0, [r7]\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldrb r0, [r0, #0xa]\n\t"
        "	ldrh r1, [r5]\n\t"
        "	subs r1, #8\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	bl sub_081B8F10\n\t"
        "	ldr r0, [r7]\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	ldrh r1, [r5]\n\t"
        "	subs r1, #8\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	bl sub_081B8F10\n\t"
        "	ldr r0, [r7]\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrb r0, [r4, #0xc]\n\t"
        "	ldrh r1, [r5]\n\t"
        "	subs r1, #8\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	bl sub_081B8F10\n\t"
        "_081B8FA0:\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #5\n\t"
        "	bls _081B8F48\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #4\n\t"
        "	movs r0, #2\n\t"
        "	movs r2, #1\n\t"
        "	bl ChangeBgX\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8FBC: .4byte gUnknown_3005B68\n\t"
        "_081B8FC0: .4byte sPartyMenuBoxes\n\t"
        "_081B8FC4: .4byte gMultiPartnerParty\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8FC8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	movs r0, #0xf\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _081B8FEC\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B8FF0\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #6\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B8FEC: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B8FF0: .4byte sub_081B9030 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B8FF4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _081B9020\n\t"
        "	ldr r1, _081B9024\n\t"
        "	str r1, [r2]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp]\n\t"
        "	ldr r1, _081B9028\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, _081B902C\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xb\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B9020: .4byte gFieldCallback2\n\t"
        "_081B9024: .4byte hm_add_c3_without_phase_2 + 1\n\t"
        "_081B9028: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B902C: .4byte CB2_ReturnToField + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B9030(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _081B9058\n\t"
        "	bl GetCursorSelectionMonId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r4]\n\t"
        "	cmp r0, #5\n\t"
        "	bls _081B9046\n\t"
        "	movs r0, #0xff\n\t"
        "	strh r0, [r4]\n\t"
        "_081B9046:\n\t"
        "	ldr r0, _081B905C\n\t"
        "	ldr r1, _081B9060\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r0, _081B9064\n\t"
        "	bl SetMainCallback2\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B9058: .4byte gSpecialVar_0x8004\n\t"
        "_081B905C: .4byte gFieldCallback2\n\t"
        "_081B9060: .4byte hm_add_c3_without_phase_2 + 1\n\t"
        "_081B9064: .4byte CB2_ReturnToField + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void task_hm_without_phase_2(u8 taskId);

bool8 hm_add_c3_without_phase_2(void)
{
    FadeInFromBlack();
    CreateTask(task_hm_without_phase_2, 10);
    return TRUE;
}

__attribute__((naked)) void task_hm_without_phase_2(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl IsWeatherNotFadingIn\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B909E\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	bl ScriptContext_Enable\n\t"
        "_081B909E:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_ChooseContestMon(u8 taskId);

void sub_081B90A4(void)
{
    LockPlayerFieldControls();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_ChooseContestMon, 10);
}

__attribute__((naked)) void Task_ChooseContestMon(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _081B9104\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	bne _081B90FC\n\t"
        "	bl CleanupOverworldWindowsAndTilemaps\n\t"
        "	str r4, [sp]\n\t"
        "	ldr r0, _081B9108\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B910C\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xb\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_081B90FC:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B9104: .4byte gPaletteFade\n\t"
        "_081B9108: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B910C: .4byte sub_081B9110 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B9110(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl GetCursorSelectionMonId\n\t"
        "	ldr r2, _081B913C\n\t"
        "	strb r0, [r2]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #5\n\t"
        "	bls _081B9126\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r2]\n\t"
        "_081B9126:\n\t"
        "	ldr r1, _081B9140\n\t"
        "	ldrb r0, [r2]\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _081B9144\n\t"
        "	ldr r0, _081B9148\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _081B914C\n\t"
        "	bl SetMainCallback2\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B913C: .4byte gContestMonPartyIndex\n\t"
        "_081B9140: .4byte gSpecialVar_0x8004\n\t"
        "_081B9144: .4byte gFieldCallback2\n\t"
        "_081B9148: .4byte hm_add_c3_without_phase_2 + 1\n\t"
        "_081B914C: .4byte CB2_ReturnToField + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_ChoosePartyMon(u8 taskId);

void ChoosePartyMon(void)
{
    LockPlayerFieldControls();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_ChoosePartyMon, 10);
}


__attribute__((naked)) void Task_ChoosePartyMon(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _081B91B0\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	bne _081B91A8\n\t"
        "	bl CleanupOverworldWindowsAndTilemaps\n\t"
        "	str r4, [sp]\n\t"
        "	ldr r0, _081B91B4\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B91B8\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xb\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_081B91A8:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B91B0: .4byte gPaletteFade\n\t"
        "_081B91B4: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B91B8: .4byte sub_081B9030 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_ChooseMonForMoveRelearner(u8 taskId);

void ChooseMonForMoveRelearner(void)
{
    LockPlayerFieldControls();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_ChooseMonForMoveRelearner, 10);
}

__attribute__((naked)) void Task_ChooseMonForMoveRelearner(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _081B921C\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	bne _081B9214\n\t"
        "	bl CleanupOverworldWindowsAndTilemaps\n\t"
        "	str r4, [sp]\n\t"
        "	ldr r0, _081B9220\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B9224\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #7\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xb\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_081B9214:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B921C: .4byte gPaletteFade\n\t"
        "_081B9220: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B9224: .4byte sub_081B9228 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B9228(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r5, _081B9240\n\t"
        "	bl GetCursorSelectionMonId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r5]\n\t"
        "	cmp r0, #5\n\t"
        "	bls _081B9244\n\t"
        "	movs r0, #0xff\n\t"
        "	strh r0, [r5]\n\t"
        "	b _081B925A\n\t"
        "	.align 2, 0\n\t"
        "_081B9240: .4byte gSpecialVar_0x8004\n\t"
        "_081B9244:\n\t"
        "	ldr r4, _081B926C\n\t"
        "	ldrh r1, [r5]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B9270\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl GetNumberOfRelearnableMoves\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r4]\n\t"
        "_081B925A:\n\t"
        "	ldr r0, _081B9274\n\t"
        "	ldr r1, _081B9278\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r0, _081B927C\n\t"
        "	bl SetMainCallback2\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B926C: .4byte gSpecialVar_0x8005\n\t"
        "_081B9270: .4byte gPlayerParty\n\t"
        "_081B9274: .4byte gFieldCallback2\n\t"
        "_081B9278: .4byte hm_add_c3_without_phase_2 + 1\n\t"
        "_081B927C: .4byte CB2_ReturnToField + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B9280(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r1, _081B9290\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r4, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	b _081B929A\n\t"
        "	.align 2, 0\n\t"
        "_081B9290: .4byte gSpecialVar_Result\n\t"
        "_081B9294:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "_081B929A:\n\t"
        "	cmp r4, #2\n\t"
        "	bhi _081B92B4\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r4, r0\n\t"
        "	ldr r1, _081B92BC\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B9294\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r5]\n\t"
        "_081B92B4:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B92BC: .4byte gPlayerParty\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_BattlePyramidChooseMonHeldItems(u8 taskId);

void BattlePyramidChooseMonHeldItems(void)
{
    LockPlayerFieldControls();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_BattlePyramidChooseMonHeldItems, 10);
}

__attribute__((naked)) void Task_BattlePyramidChooseMonHeldItems(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _081B9320\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	bne _081B9318\n\t"
        "	bl CleanupOverworldWindowsAndTilemaps\n\t"
        "	str r4, [sp]\n\t"
        "	ldr r0, _081B9324\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _081B9328\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0xc\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl InitPartyMenu\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_081B9318:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B9320: .4byte gPaletteFade\n\t"
        "_081B9324: .4byte Task_HandleChooseMonInput + 1\n\t"
        "_081B9328: .4byte sub_081B9030 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B932C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r1, _081B9358\n\t"
        "	ldr r0, _081B935C\n\t"
        "	ldrb r2, [r0]\n\t"
        "	ldr r0, _081B9360\n\t"
        "	ldrb r3, [r0]\n\t"
        "	subs r3, #1\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	ldr r0, _081B9364\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #3\n\t"
        "	bl ShowPokemonSummaryScreen\n\t"
        "	ldr r1, _081B9368\n\t"
        "	ldr r0, _081B936C\n\t"
        "	str r0, [r1]\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B9358: .4byte gPlayerParty\n\t"
        "_081B935C: .4byte gSpecialVar_0x8004\n\t"
        "_081B9360: .4byte gPlayerPartyCount\n\t"
        "_081B9364: .4byte CB2_ReturnToField + 1\n\t"
        "_081B9368: .4byte gFieldCallback\n\t"
        "_081B936C: .4byte FieldCB_ContinueScriptHandleMusic + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B9370(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r1, _081B93AC\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r4, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "_081B937C:\n\t"
        "	ldr r0, _081B93B0\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B93B4\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081B939A\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5]\n\t"
        "_081B939A:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #3\n\t"
        "	bls _081B937C\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B93AC: .4byte gSpecialVar_Result\n\t"
        "_081B93B0: .4byte gSpecialVar_0x8004\n\t"
        "_081B93B4: .4byte gPlayerParty\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B93B8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r0, _081B93F8\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r5, r1, #0\n\t"
        "	muls r5, r0, r5\n\t"
        "	ldr r0, _081B93FC\n\t"
        "	adds r5, r5, r0\n\t"
        "	ldr r0, _081B9400\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r1, #0xd\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonData3\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldr r1, _081B9404\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetMonNickname\n\t"
        "	ldr r0, _081B9408\n\t"
        "	lsls r4, r4, #3\n\t"
        "	ldr r1, _081B940C\n\t"
        "	adds r4, r4, r1\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl StringCopy\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B93F8: .4byte gSpecialVar_0x8004\n\t"
        "_081B93FC: .4byte gPlayerParty\n\t"
        "_081B9400: .4byte gSpecialVar_0x8005\n\t"
        "_081B9404: .4byte gStringVar1\n\t"
        "_081B9408: .4byte gStringVar2\n\t"
        "_081B940C: .4byte gMoveNames\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B9410(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	ldr r0, _081B9470\n\t"
        "	mov r8, r0\n\t"
        "	ldrh r0, [r0]\n\t"
        "	movs r6, #0x64\n\t"
        "	muls r0, r6, r0\n\t"
        "	ldr r5, _081B9474\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldr r4, _081B9478\n\t"
        "	ldrb r2, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl SetMonMoveSlot\n\t"
        "	mov r1, r8\n\t"
        "	ldrh r0, [r1]\n\t"
        "	muls r0, r6, r0\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r1, [r4]\n\t"
        "	bl RemoveMonPPBonus\n\t"
        "	ldrh r4, [r4]\n\t"
        "	cmp r4, #2\n\t"
        "	bhi _081B9464\n\t"
        "_081B9442:\n\t"
        "	ldr r0, _081B9470\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B9474\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r1, r4, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r4, #1\n\t"
        "	lsls r2, r4, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	bl sub_081B947C\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	cmp r4, #2\n\t"
        "	bls _081B9442\n\t"
        "_081B9464:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B9470: .4byte gSpecialVar_0x8004\n\t"
        "_081B9474: .4byte gPlayerParty\n\t"
        "_081B9478: .4byte gSpecialVar_0x8005\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B947C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x20\n\t"
        "	mov r8, r0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r4, r2, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0xd\n\t"
        "	str r0, [sp, #8]\n\t"
        "	mov r0, r8\n\t"
        "	ldr r1, [sp, #8]\n\t"
        "	bl GetMonData3\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, #2\n\t"
        "	str r1, [sp, #0x14]\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0xd\n\t"
        "	str r3, [sp, #0xc]\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r3, #0\n\t"
        "	bl GetMonData3\n\t"
        "	mov r1, sp\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r7, r5, #0\n\t"
        "	adds r7, #0x11\n\t"
        "	str r7, [sp, #0x10]\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl GetMonData3\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, #5\n\t"
        "	str r1, [sp, #0x18]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x11\n\t"
        "	str r3, [sp, #0x1c]\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r3, #0\n\t"
        "	bl GetMonData3\n\t"
        "	add r7, sp, #4\n\t"
        "	mov sl, r7\n\t"
        "	strb r0, [r7]\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #0x15\n\t"
        "	bl GetMonData3\n\t"
        "	mov r6, sp\n\t"
        "	adds r6, #6\n\t"
        "	strb r0, [r6]\n\t"
        "	ldr r1, _081B9578\n\t"
        "	adds r0, r5, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov sb, r0\n\t"
        "	ldrb r0, [r6]\n\t"
        "	adds r2, r0, #0\n\t"
        "	mov r3, sb\n\t"
        "	ands r2, r3\n\t"
        "	lsls r5, r5, #1\n\t"
        "	asrs r2, r5\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r1, r4, r1\n\t"
        "	ldrb r3, [r1]\n\t"
        "	adds r1, r0, #0\n\t"
        "	ands r1, r3\n\t"
        "	lsls r4, r4, #1\n\t"
        "	asrs r1, r4\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov r7, sb\n\t"
        "	bics r0, r7\n\t"
        "	strb r0, [r6]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	bics r0, r3\n\t"
        "	strb r0, [r6]\n\t"
        "	lsls r2, r4\n\t"
        "	lsls r1, r5\n\t"
        "	adds r2, r2, r1\n\t"
        "	ldrb r0, [r6]\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r6]\n\t"
        "	mov r0, r8\n\t"
        "	ldr r1, [sp, #8]\n\t"
        "	mov r2, sp\n\t"
        "	bl SetMonData\n\t"
        "	mov r0, r8\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	ldr r2, [sp, #0x14]\n\t"
        "	bl SetMonData\n\t"
        "	mov r0, r8\n\t"
        "	ldr r1, [sp, #0x10]\n\t"
        "	mov r2, sl\n\t"
        "	bl SetMonData\n\t"
        "	mov r0, r8\n\t"
        "	ldr r1, [sp, #0x1c]\n\t"
        "	ldr r2, [sp, #0x18]\n\t"
        "	bl SetMonData\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #0x15\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl SetMonData\n\t"
        "	add sp, #0x20\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B9578: .4byte gUnknown_82FA6AA\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B957C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _081B95A0\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B95A4\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0x2d\n\t"
        "	bl GetMonData3\n\t"
        "	adds r1, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081B95AC\n\t"
        "	ldr r1, _081B95A8\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "	b _081B95B0\n\t"
        "	.align 2, 0\n\t"
        "_081B95A0: .4byte gSpecialVar_0x8004\n\t"
        "_081B95A4: .4byte gPlayerParty\n\t"
        "_081B95A8: .4byte gSpecialVar_Result\n\t"
        "_081B95AC:\n\t"
        "	ldr r0, _081B95B4\n\t"
        "	strh r1, [r0]\n\t"
        "_081B95B0:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B95B4: .4byte gSpecialVar_Result\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081B95B8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	ldr r1, _081B95E8\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _081B95EC\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _081B95F0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081B95F4\n\t"
        "	ldrh r1, [r1]\n\t"
        "	adds r1, #0xd\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	cmp r0, #0x39\n\t"
        "	bne _081B963C\n\t"
        "	movs r6, #0\n\t"
        "	b _081B9620\n\t"
        "	.align 2, 0\n\t"
        "_081B95E8: .4byte gSpecialVar_Result\n\t"
        "_081B95EC: .4byte gSpecialVar_0x8004\n\t"
        "_081B95F0: .4byte gPlayerParty\n\t"
        "_081B95F4: .4byte gSpecialVar_0x8005\n\t"
        "_081B95F8:\n\t"
        "	ldr r0, _081B9648\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r6, r0\n\t"
        "	beq _081B961E\n\t"
        "	movs r4, #0\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r5, r6, #0\n\t"
        "	muls r5, r0, r5\n\t"
        "	ldr r7, _081B964C\n\t"
        "_081B960A:\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	adds r0, r5, r7\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0x39\n\t"
        "	beq _081B963C\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #3\n\t"
        "	bls _081B960A\n\t"
        "_081B961E:\n\t"
        "	adds r6, #1\n\t"
        "_081B9620:\n\t"
        "	bl CalculatePlayerPartyCount\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r6, r0\n\t"
        "	blo _081B95F8\n\t"
        "	mov r0, r8\n\t"
        "	bl AnyStorageMonWithMove\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081B963C\n\t"
        "	ldr r1, _081B9650\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "_081B963C:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081B9648: .4byte gSpecialVar_0x8004\n\t"
        "_081B964C: .4byte gPlayerParty\n\t"
        "_081B9650: .4byte gSpecialVar_Result\n\t"
        ".syntax divided\n\t"
    );
}
