#include "global.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "palette.h"
#include "pokenav.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/songs.h"

extern const u8 *const gRibbonDescriptionPointers[][2];
extern const u8 *const gGiftRibbonDescriptionPointers[][2];
struct RibbonGfxData { u16 tileNumOffset; u16 palNumOffset; };
extern const struct RibbonGfxData sRibbonGfxData[];
struct RibbonData { u8 numBits; u8 numRibbons; u8 ribbonId; bool8 isGiftRibbon; };
extern const struct RibbonData sRibbonData[16]; // ROM 0x085F5E14, 16 entries
extern u32 sRibbonDraw_Total;
extern u32 sRibbonDraw_Current;
extern const u16 sRibbonIcons1_Pal[];
extern const u16 sRibbonIcons2_Pal[];
extern const u16 sRibbonIcons3_Pal[];
extern const u16 sRibbonIcons4_Pal[];
extern const u16 sRibbonIcons5_Pal[];
extern const u16 sMonInfo_Pal[16]; // ROM 0x085F6670, 16 colors
extern const u32 sRibbonIconsSmall_Gfx[];
extern const u32 sRibbonIconsBig_Gfx[];
extern const struct BgTemplate sBgTemplates[2]; // ROM 0x085F7210
extern const LoopedTask sRibbonsSummaryMenuLoopTaskFuncs[];
extern const struct WindowTemplate sRibbonCountWindowTemplate;
extern const struct WindowTemplate sRibbonSummaryMonNameWindowTemplate;
extern const struct WindowTemplate sRibbonMonListIndexWindowTemplate[];
extern const struct CompressedSpriteSheet sSpriteSheet_RibbonIconsBig;
extern const struct SpritePalette sSpritePalettes_RibbonIcons[];
extern const struct OamData sOamData_RibbonIconBig;
extern const union AffineAnimCmd sAffineAnim_RibbonIconBig_Normal[];
extern const union AffineAnimCmd sAffineAnim_RibbonIconBig_ZoomIn[];
extern const union AffineAnimCmd sAffineAnim_RibbonIconBig_ZoomOut[];
extern const union AffineAnimCmd *const sAffineAnims_RibbonIconBig;
extern const struct SpriteTemplate sSpriteTemplate_RibbonIconBig;
extern const u8 sText_MaleSymbol[];
extern const u8 sText_FemaleSymbol[];
extern const u8 sGenderlessIconString[];
extern const struct ScanlineEffectParams sConditionGraphScanline[];
extern const u8 sConditionToLineLength[];
extern const u32 sConditionPokeball_Gfx[];
extern const u32 sConditionPokeballPlaceholder_Gfx[];
extern const u16 sConditionSparkle_Gfx[];
extern const u32 sConditionSparkle_Pal[];
extern const struct OamData sOam_ConditionMonPic;
extern const struct OamData sOam_ConditionSelectionIcon;
extern const union AnimCmd sAnim_ConditionSelectionIcon_Selected[];
extern const union AnimCmd sAnim_ConditionSelectionIcon_Unselected[];
extern const union AnimCmd *const sAnims_ConditionSelectionIcon;
extern const struct OamData sOam_ConditionSparkle;
extern const union AnimCmd sAnim_ConditionSparkle[];
extern const union AnimCmd *const sAnims_ConditionSparkle;
extern const struct SpriteTemplate sSpriteTemplate_ConditionSparkle;
extern const s16 sConditionSparkleCoords[];
extern const u8 *const sLvlUpStatStrings;
extern const struct WindowTemplate sWindowTemplates_MailboxMenu[];
extern const u8 sPlayerNameTextColors[];
extern const u8 sEmptyItemName[];
extern const struct WindowTemplate sMoveRelearnerWindowTemplates[];
extern const struct WindowTemplate sMoveRelearnerYesNoMenuTemplate;
extern const struct ListMenuTemplate sMoveRelearnerMovesListTemplate[];


enum
{
    RIBBONS_SUMMARY_FUNC_NONE,
    RIBBONS_SUMMARY_FUNC_SWITCH_MONS,
    RIBBONS_SUMMARY_FUNC_SELECT_RIBBON,
    RIBBONS_SUMMARY_FUNC_EXPANDED_CURSOR_MOVE,
    RIBBONS_SUMMARY_FUNC_EXPANDED_CANCEL,
    RIBBONS_SUMMARY_FUNC_EXIT,
};

#define GFXTAG_RIBBON_ICONS_BIG 9

#define PALTAG_RIBBON_ICONS_1 15
#define PALTAG_RIBBON_ICONS_2 16
#define PALTAG_RIBBON_ICONS_3 17
#define PALTAG_RIBBON_ICONS_4 18
#define PALTAG_RIBBON_ICONS_5 19

#define RIBBONS_PER_ROW 9
#define GIFT_RIBBON_ROW (1 + (FIRST_GIFT_RIBBON / RIBBONS_PER_ROW)) // Gift ribbons start on a new row after the normal ribbons.
#define GIFT_RIBBON_START_POS (RIBBONS_PER_ROW * GIFT_RIBBON_ROW)

#define MON_SPRITE_X_ON  40
#define MON_SPRITE_X_OFF -32
#define MON_SPRITE_Y     104

struct Pokenav_RibbonsSummaryList
{
    u8 unused1[8];
    struct PokenavMonList *monList;
    u16 selectedPos;
    u16 normalRibbonLastRowStart;
    u16 numNormalRibbons;
    u16 numGiftRibbons;
    u32 ribbonIds[FIRST_GIFT_RIBBON];
    u32 giftRibbonIds[NUM_GIFT_RIBBONS];
    u32 unused2;
    u32 (*callback)(struct Pokenav_RibbonsSummaryList *);
};

struct Pokenav_RibbonsSummaryMenu
{
    u32 (*callback)(void);
    u32 loopedTaskId;
    u16 nameWindowId;
    u16 ribbonCountWindowId;
    u16 listIdxWindowId;
    u16 unusedWindowId;
    u16 monSpriteId;
    struct Sprite *bigRibbonSprite;
    u32 unused;
    u8 tilemapBuffers[2][BG_SCREEN_SIZE];
};

// Used for the initial drawing of the ribbons

static void PrintCurrentMonRibbonCount(struct Pokenav_RibbonsSummaryMenu *);
static void PrintRibbbonsSummaryMonInfo(struct Pokenav_RibbonsSummaryMenu *);
static void PrintRibbonsMonListIndex(struct Pokenav_RibbonsSummaryMenu *);
static void ZoomOutSelectedRibbon(struct Pokenav_RibbonsSummaryMenu *);
static void UpdateAndZoomInSelectedRibbon(struct Pokenav_RibbonsSummaryMenu *);
static void PrintRibbonNameAndDescription(struct Pokenav_RibbonsSummaryMenu *);
static void ResetSpritesAndDrawMonFrontPic(struct Pokenav_RibbonsSummaryMenu *);
static void AddRibbonListIndexWindow(struct Pokenav_RibbonsSummaryMenu *);
static void DestroyRibbonsMonFrontPic(struct Pokenav_RibbonsSummaryMenu *);
static void SlideMonSpriteOff(struct Pokenav_RibbonsSummaryMenu *);
static void SlideMonSpriteOn(struct Pokenav_RibbonsSummaryMenu *);
static void AddRibbonCountWindow(struct Pokenav_RibbonsSummaryMenu *);
static void CreateBigRibbonSprite(struct Pokenav_RibbonsSummaryMenu *);
static void AddRibbonSummaryMonNameWindow(struct Pokenav_RibbonsSummaryMenu *);
static void DrawAllRibbonsSmall(struct Pokenav_RibbonsSummaryMenu *);
static bool32 IsRibbonAnimating(struct Pokenav_RibbonsSummaryMenu *);
static bool32 IsMonSpriteAnimating(struct Pokenav_RibbonsSummaryMenu *);
static void GetMonRibbons(struct Pokenav_RibbonsSummaryList *);
static u32 HandleExpandedRibbonInput(struct Pokenav_RibbonsSummaryList *);
static u32 RibbonsSummaryHandleInput(struct Pokenav_RibbonsSummaryList *);
static u32 ReturnToRibbonsListFromSummary(struct Pokenav_RibbonsSummaryList *);
static bool32 TrySelectRibbonUp(struct Pokenav_RibbonsSummaryList *);
static bool32 TrySelectRibbonRight(struct Pokenav_RibbonsSummaryList *);
static bool32 TrySelectRibbonLeft(struct Pokenav_RibbonsSummaryList *);
static bool32 TrySelectRibbonDown(struct Pokenav_RibbonsSummaryList *);
static bool32 GetCurrentLoopedTaskActive(void);
static u32 GetRibbonsSummaryCurrentIndex(void);
static u32 GetRibbonsSummaryMonListCount(void);
static u16 DrawRibbonsMonFrontPic(s32, s32);
static void StartMonSpriteSlide(struct Sprite *, s32, s32, s32);
static void SpriteCB_MonSpriteSlide(struct Sprite *);
static void ClearRibbonsSummaryBg(void);
static void BufferSmallRibbonGfxData(u16 *, u32);
static void DrawRibbonSmall(u32, u32);
static void SpriteCB_WaitForRibbonAnimation(struct Sprite *);
static u32 LoopedTask_OpenRibbonsSummaryMenu(s32);
static u32 LoopedTask_SwitchRibbonsSummaryMon(s32);
static u32 LoopedTask_ExpandSelectedRibbon(s32);
static u32 LoopedTask_MoveRibbonsCursorExpanded(s32);
static u32 LoopedTask_ShrinkExpandedRibbon(s32);
static u32 LoopedTask_ExitRibbonsSummaryMenu(s32);






bool32 PokenavCallback_Init_RibbonsSummaryMenu(void)
{
    struct Pokenav_RibbonsSummaryList *list = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST, sizeof(struct Pokenav_RibbonsSummaryList));
    if (list == NULL)
        return FALSE;

    list->monList = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    if (list->monList == NULL)
        return FALSE;

    GetMonRibbons(list);
    list->callback = RibbonsSummaryHandleInput;
    gKeyRepeatContinueDelay = 3;
    gKeyRepeatStartDelay = 10;
    return TRUE;
}

u32 GetRibbonsSummaryMenuCallback(void)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    return list->callback(list);
}

void FreeRibbonsSummaryScreen1(void)
{
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
}

// Handles input when a specific ribbon is not currently selected
static u32 RibbonsSummaryHandleInput(struct Pokenav_RibbonsSummaryList *list)
{
    // Handle Up/Down movement to select a new Pokémon to show ribbons for
    if (JOY_REPEAT(DPAD_UP) && list->monList->currIndex != 0)
    {
        list->monList->currIndex--;
        list->selectedPos = 0;
        GetMonRibbons(list);
        return RIBBONS_SUMMARY_FUNC_SWITCH_MONS;
    }
    if (JOY_REPEAT(DPAD_DOWN) && list->monList->currIndex < list->monList->listCount - 1)
    {
        list->monList->currIndex++;
        list->selectedPos = 0;
        GetMonRibbons(list);
        return RIBBONS_SUMMARY_FUNC_SWITCH_MONS;
    }

    if (JOY_NEW(A_BUTTON))
    {
        // Enter ribbon selection
        list->callback = HandleExpandedRibbonInput;
        return RIBBONS_SUMMARY_FUNC_SELECT_RIBBON;
    }
    if (JOY_NEW(B_BUTTON))
    {
        // Exit ribbon summary menu
        list->callback = ReturnToRibbonsListFromSummary;
        return RIBBONS_SUMMARY_FUNC_EXIT;
    }
    return RIBBONS_SUMMARY_FUNC_NONE;
}

// Handles input when a ribbon is selected
static u32 HandleExpandedRibbonInput(struct Pokenav_RibbonsSummaryList *list)
{
    // Handle movement while a ribbon is selected
    if (JOY_REPEAT(DPAD_UP) && TrySelectRibbonUp(list))
        return RIBBONS_SUMMARY_FUNC_EXPANDED_CURSOR_MOVE;
    if (JOY_REPEAT(DPAD_DOWN) && TrySelectRibbonDown(list))
        return RIBBONS_SUMMARY_FUNC_EXPANDED_CURSOR_MOVE;
    if (JOY_REPEAT(DPAD_LEFT) && TrySelectRibbonLeft(list))
        return RIBBONS_SUMMARY_FUNC_EXPANDED_CURSOR_MOVE;
    if (JOY_REPEAT(DPAD_RIGHT) && TrySelectRibbonRight(list))
        return RIBBONS_SUMMARY_FUNC_EXPANDED_CURSOR_MOVE;

    if (JOY_NEW(B_BUTTON))
    {
        // Exit ribbon selection
        list->callback = RibbonsSummaryHandleInput;
        return RIBBONS_SUMMARY_FUNC_EXPANDED_CANCEL;
    }
    return RIBBONS_SUMMARY_FUNC_NONE;
}

static u32 ReturnToRibbonsListFromSummary(struct Pokenav_RibbonsSummaryList *list)
{
    return POKENAV_RIBBONS_RETURN_TO_MON_LIST;
}

static bool32 TrySelectRibbonUp(struct Pokenav_RibbonsSummaryList *list)
{
    if (list->selectedPos < FIRST_GIFT_RIBBON)
    {
        // In normal ribbons, try to move up a row
        if (list->selectedPos < RIBBONS_PER_ROW)
            return FALSE;

        list->selectedPos -= RIBBONS_PER_ROW;
        return TRUE;
    }
    if (list->numNormalRibbons != 0)
    {
        // In gift ribbons, try to move up into normal ribbons
        // If there's > 1 row of gift ribbons (not normally possible)
        // it's impossible to move up between them
        u32 ribbonPos = list->selectedPos - GIFT_RIBBON_START_POS;
        list->selectedPos = ribbonPos + list->normalRibbonLastRowStart;
        if (list->selectedPos >= list->numNormalRibbons)
            list->selectedPos = list->numNormalRibbons - 1;
        return TRUE;
    }
    return FALSE;
}

static bool32 TrySelectRibbonDown(struct Pokenav_RibbonsSummaryList *list)
{
    if (list->selectedPos >= FIRST_GIFT_RIBBON)
        return FALSE;
    if (list->selectedPos < list->normalRibbonLastRowStart)
    {
        // Not in last row of normal ribbons, advance to next row
        list->selectedPos += RIBBONS_PER_ROW;
        if (list->selectedPos >= list->numNormalRibbons)
            list->selectedPos = list->numNormalRibbons - 1;
        return TRUE;
    }
    if (list->numGiftRibbons != 0)
    {
        // In/beyond last of row of normal ribbons and gift ribbons present, move down to gift ribbon row
        int ribbonPos = list->selectedPos - list->normalRibbonLastRowStart;
        if (ribbonPos >= list->numGiftRibbons)
            ribbonPos = list->numGiftRibbons - 1;

        list->selectedPos = ribbonPos + GIFT_RIBBON_START_POS;
        return TRUE;
    }
    return FALSE;
}

static bool32 TrySelectRibbonLeft(struct Pokenav_RibbonsSummaryList *list)
{
    u16 column = list->selectedPos % RIBBONS_PER_ROW;
    if (column != 0)
    {
        list->selectedPos--;
        return TRUE;
    }

    return FALSE;
}

static bool32 TrySelectRibbonRight(struct Pokenav_RibbonsSummaryList *list)
{
    int column = list->selectedPos % RIBBONS_PER_ROW;

    if (column >= RIBBONS_PER_ROW - 1)
        return FALSE;

    if (list->selectedPos < GIFT_RIBBON_START_POS)
    {
        // Move right in normal ribbon row
        if (list->selectedPos < list->numNormalRibbons - 1)
        {
            list->selectedPos++;
            return TRUE;
        }
    }
    else
    {
        // Move right in gift ribbon row
        if (column < list->numGiftRibbons - 1)
        {
            list->selectedPos++;
            return TRUE;
        }
    }
    return FALSE;
}

static u32 GetRibbonsSummaryCurrentIndex(void)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    return list->monList->currIndex;
}

static u32 GetRibbonsSummaryMonListCount(void)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    return list->monList->listCount;
}

static void GetMonNicknameLevelGender(u8 *nick, u8 *level, u8 *gender)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    struct PokenavMonList *mons = list->monList;
    struct PokenavMonListItem *monInfo = &mons->monData[mons->currIndex];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
    {
        // Get info for party mon
        struct Pokemon *mon = &gPlayerParty[monInfo->monId];
        GetMonData(mon, MON_DATA_NICKNAME, nick);
        *level = GetLevelFromMonExp(mon);
        *gender = GetMonGender(mon);
    }
    else
    {
        // Get info for PC box mon
        struct BoxPokemon *boxMon = GetBoxedMonPtr(monInfo->boxId, monInfo->monId);
        *gender = GetBoxMonGender(boxMon);
        *level = GetLevelFromBoxMonExp(boxMon);
        GetBoxMonData(boxMon, MON_DATA_NICKNAME, nick);
    }
    StringGet_Nickname(nick);
}

static void GetMonSpeciesPersonalityOtId(u16 *species, u32 *personality, u32 *otId)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    struct PokenavMonList *mons = list->monList;
    struct PokenavMonListItem *monInfo = &mons->monData[mons->currIndex];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
    {
        // Get info for party mon
        struct Pokemon *mon = &gPlayerParty[monInfo->monId];
        *species = GetMonData(mon, MON_DATA_SPECIES);
        *personality = GetMonData(mon, MON_DATA_PERSONALITY);
        *otId = GetMonData(mon, MON_DATA_OT_ID);
    }
    else
    {
        // Get info for PC box mon
        struct BoxPokemon *boxMon = GetBoxedMonPtr(monInfo->boxId, monInfo->monId);
        *species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
        *personality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY);
        *otId = GetBoxMonData(boxMon, MON_DATA_OT_ID);
    }
}

static u32 GetCurrMonRibbonCount(void)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    struct PokenavMonList *mons = list->monList;
    struct PokenavMonListItem *monInfo = &mons->monData[mons->currIndex];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
        return GetMonData(&gPlayerParty[monInfo->monId], MON_DATA_RIBBON_COUNT);
    else
        return GetBoxMonDataAt(monInfo->boxId, monInfo->monId, MON_DATA_RIBBON_COUNT);
}

// JP 0x081CFEC4 uses high registers (r8/sb/sl) and calls GetMonData3
// directly with a pointer into gPlayerParty, so it is kept as asm.
#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
__attribute__((naked)) static void GetMonRibbons(struct Pokenav_RibbonsSummaryList *list)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "adds r5, r0, #0\n\t"
            "ldr r0, [r5, #8]\n\t"
            "ldrh r1, [r0, #2]\n\t"
            "lsls r1, r1, #2\n\t"
            "adds r1, #4\n\t"
            "adds r1, r0, r1\n\t"
            "ldrb r0, [r1]\n\t"
            "cmp r0, #0xe\n\t"
            "bne _081CFEF8\n\t"
            "ldrb r1, [r1, #1]\n\t"
            "movs r0, #0x64\n\t"
            "muls r0, r1, r0\n\t"
            "ldr r1, _081CFEF4\n\t"
            "adds r0, r0, r1\n\t"
            "movs r1, #0x53\n\t"
            "bl GetMonData3\n\t"
            "b _081CFF02\n\t"
            ".align 2, 0\n\t"
            "_081CFEF4: .4byte gPlayerParty\n\t"
            "_081CFEF8:\n\t"
            "ldrb r0, [r1]\n\t"
            "ldrb r1, [r1, #1]\n\t"
            "movs r2, #0x53\n\t"
            "bl GetBoxMonDataAt\n\t"
            "_081CFF02:\n\t"
            "mov ip, r0\n\t"
            "movs r0, #0\n\t"
            "strh r0, [r5, #0x10]\n\t"
            "strh r0, [r5, #0x12]\n\t"
            "movs r6, #0\n\t"
            "ldr r0, _081CFF58\n\t"
            "mov sb, r0\n\t"
            "mov sl, sb\n\t"
            "_081CFF12:\n\t"
            "lsls r2, r6, #2\n\t"
            "mov r3, sb\n\t"
            "adds r1, r2, r3\n\t"
            "movs r0, #1\n\t"
            "ldrb r3, [r1]\n\t"
            "lsls r0, r3\n\t"
            "subs r4, r0, #1\n\t"
            "mov r0, ip\n\t"
            "ands r4, r0\n\t"
            "ldrb r0, [r1, #3]\n\t"
            "adds r7, r2, #0\n\t"
            "cmp r0, #0\n\t"
            "bne _081CFF5C\n\t"
            "movs r3, #0\n\t"
            "adds r6, #1\n\t"
            "mov r8, r6\n\t"
            "cmp r3, r4\n\t"
            "bge _081CFF86\n\t"
            "adds r6, r5, #0\n\t"
            "adds r6, #0x14\n\t"
            "mov r1, sl\n\t"
            "adds r0, r7, r1\n\t"
            "ldrb r2, [r0, #2]\n\t"
            "_081CFF40:\n\t"
            "ldrh r0, [r5, #0x10]\n\t"
            "adds r1, r0, #1\n\t"
            "strh r1, [r5, #0x10]\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r0, r0, #0xe\n\t"
            "adds r0, r6, r0\n\t"
            "adds r1, r2, r3\n\t"
            "str r1, [r0]\n\t"
            "adds r3, #1\n\t"
            "cmp r3, r4\n\t"
            "blt _081CFF40\n\t"
            "b _081CFF86\n\t"
            ".align 2, 0\n\t"
            "_081CFF58: .4byte sRibbonData\n\t"
            "_081CFF5C:\n\t"
            "movs r3, #0\n\t"
            "adds r6, #1\n\t"
            "mov r8, r6\n\t"
            "cmp r3, r4\n\t"
            "bge _081CFF86\n\t"
            "adds r6, r5, #0\n\t"
            "adds r6, #0x78\n\t"
            "mov r1, sl\n\t"
            "adds r0, r7, r1\n\t"
            "ldrb r2, [r0, #2]\n\t"
            "_081CFF70:\n\t"
            "ldrh r0, [r5, #0x12]\n\t"
            "adds r1, r0, #1\n\t"
            "strh r1, [r5, #0x12]\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r0, r0, #0xe\n\t"
            "adds r0, r6, r0\n\t"
            "adds r1, r2, r3\n\t"
            "str r1, [r0]\n\t"
            "adds r3, #1\n\t"
            "cmp r3, r4\n\t"
            "blt _081CFF70\n\t"
            "_081CFF86:\n\t"
            "mov r3, sb\n\t"
            "adds r0, r7, r3\n\t"
            "mov r1, ip\n\t"
            "ldrb r0, [r0]\n\t"
            "lsrs r1, r0\n\t"
            "mov ip, r1\n\t"
            "mov r6, r8\n\t"
            "cmp r6, #0x10\n\t"
            "bls _081CFF12\n\t"
            "ldrh r0, [r5, #0x10]\n\t"
            "cmp r0, #0\n\t"
            "beq _081CFFB0\n\t"
            "subs r0, #1\n\t"
            "movs r1, #9\n\t"
            "bl __divsi3\n\t"
            "lsls r1, r0, #3\n\t"
            "adds r1, r1, r0\n\t"
            "movs r0, #0\n\t"
            "strh r1, [r5, #0xe]\n\t"
            "b _081CFFB4\n\t"
            "_081CFFB0:\n\t"
            "strh r0, [r5, #0xe]\n\t"
            "movs r0, #0x1b\n\t"
            "_081CFFB4:\n\t"
            "strh r0, [r5, #0xc]\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".syntax divided\n");
}
#else
static void GetMonRibbons(struct Pokenav_RibbonsSummaryList *list)
{
    u32 ribbonFlags;
    s32 i, j;
    struct PokenavMonList *mons = list->monList;
    struct PokenavMonListItem *monInfo = &mons->monData[mons->currIndex];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
        ribbonFlags = GetMonData(&gPlayerParty[monInfo->monId], MON_DATA_RIBBONS);
    else
        ribbonFlags = GetBoxMonDataAt(monInfo->boxId, monInfo->monId, MON_DATA_RIBBONS);

    list->numNormalRibbons = 0;
    list->numGiftRibbons = 0;
    for (i = 0; i < ARRAY_COUNT(sRibbonData); i++)
    {
        // For all non-contest ribbons, numRibbons will be 1 if they have it, 0 if they don't
        // For contest ribbons, numRibbons will be 0-4
        s32 numRibbons = ((1 << sRibbonData[i].numBits) - 1) & ribbonFlags;
        if (!sRibbonData[i].isGiftRibbon)
        {
            for (j = 0; j < numRibbons; j++)
                list->ribbonIds[list->numNormalRibbons++] = sRibbonData[i].ribbonId + j;
        }
        else
        {
            for (j = 0; j < numRibbons; j++)
                list->giftRibbonIds[list->numGiftRibbons++] = sRibbonData[i].ribbonId + j;
        }
        ribbonFlags >>= sRibbonData[i].numBits;
    }

    if (list->numNormalRibbons != 0)
    {
        list->normalRibbonLastRowStart = ((list->numNormalRibbons - 1) / RIBBONS_PER_ROW) * RIBBONS_PER_ROW;
        list->selectedPos = 0;
    }
    else
    {
        // There are no normal ribbons, move cursor to first gift ribbon
        list->normalRibbonLastRowStart = 0;
        list->selectedPos = GIFT_RIBBON_START_POS;
    }
}
#endif

#else
static void GetMonRibbons(struct Pokenav_RibbonsSummaryList *list)
{
    u32 ribbonFlags;
    s32 i, j;
    struct PokenavMonList *mons = list->monList;
    struct PokenavMonListItem *monInfo = &mons->monData[mons->currIndex];

    if (monInfo->boxId == TOTAL_BOXES_COUNT)
        ribbonFlags = GetMonData(&gPlayerParty[monInfo->monId], MON_DATA_RIBBONS);
    else
        ribbonFlags = GetBoxMonDataAt(monInfo->boxId, monInfo->monId, MON_DATA_RIBBONS);

    list->numNormalRibbons = 0;
    list->numGiftRibbons = 0;
    for (i = 0; i < ARRAY_COUNT(sRibbonData); i++)
    {
        // For all non-contest ribbons, numRibbons will be 1 if they have it, 0 if they don't
        // For contest ribbons, numRibbons will be 0-4
        s32 numRibbons = ((1 << sRibbonData[i].numBits) - 1) & ribbonFlags;
        if (!sRibbonData[i].isGiftRibbon)
        {
            for (j = 0; j < numRibbons; j++)
                list->ribbonIds[list->numNormalRibbons++] = sRibbonData[i].ribbonId + j;
        }
        else
        {
            for (j = 0; j < numRibbons; j++)
                list->giftRibbonIds[list->numGiftRibbons++] = sRibbonData[i].ribbonId + j;
        }
        ribbonFlags >>= sRibbonData[i].numBits;
    }

    if (list->numNormalRibbons != 0)
    {
        list->normalRibbonLastRowStart = ((list->numNormalRibbons - 1) / RIBBONS_PER_ROW) * RIBBONS_PER_ROW;
        list->selectedPos = 0;
    }
    else
    {
        // There are no normal ribbons, move cursor to first gift ribbon
        list->normalRibbonLastRowStart = 0;
        list->selectedPos = GIFT_RIBBON_START_POS;
    }
}
#endif


static u32 *GetNormalRibbonIds(u32 *size)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    *size = list->numNormalRibbons;
    return list->ribbonIds;
}

static u32 *GetGiftRibbonIds(u32 *size)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    *size = list->numGiftRibbons;
    return list->giftRibbonIds;
}

static u16 GetSelectedPosition(void)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    return list->selectedPos;
}

static u32 GetRibbonId(void)
{
    struct Pokenav_RibbonsSummaryList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_LIST);
    int ribbonPos = list->selectedPos;
    if (ribbonPos < FIRST_GIFT_RIBBON)
        return list->ribbonIds[ribbonPos];
    else
        return list->giftRibbonIds[ribbonPos - GIFT_RIBBON_START_POS];
}

bool32 OpenRibbonsSummaryMenu(void)
{
    struct Pokenav_RibbonsSummaryMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU, sizeof(struct Pokenav_RibbonsSummaryMenu));
    if (menu == NULL)
        return FALSE;

    menu->loopedTaskId = CreateLoopedTask(LoopedTask_OpenRibbonsSummaryMenu, 1);
    menu->callback = GetCurrentLoopedTaskActive;
    return TRUE;
}

void CreateRibbonsSummaryLoopedTask(s32 id)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    menu->loopedTaskId = CreateLoopedTask(sRibbonsSummaryMenuLoopTaskFuncs[id], 1);
    menu->callback = GetCurrentLoopedTaskActive;
}

u32 sub_081D0090(void)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    return menu->callback();
}

// JP-only alias: the trailing bx r1 is also labeled sub_081D00A0 (0x081D00A0).
__asm__(".set sub_081D00A0, sub_081D0090 + 0x10");

// IsRibbonsSummaryLoopedTaskActive is defined in pokenav_conditions_tail.c
// (JP 0x081CF544) as a naked function.
extern bool32 IsRibbonsSummaryLoopedTaskActive(void);

void FreeRibbonsSummaryScreen2(void)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    RemoveWindow(menu->ribbonCountWindowId);
    RemoveWindow(menu->nameWindowId);
    RemoveWindow(menu->listIdxWindowId);
#ifndef BUGFIX
    RemoveWindow(menu->unusedWindowId); // Removing window, but window id is never set
#endif
    DestroyRibbonsMonFrontPic(menu);
    FreeSpriteTilesByTag(GFXTAG_RIBBON_ICONS_BIG);
    FreeSpritePaletteByTag(PALTAG_RIBBON_ICONS_1);
    FreeSpritePaletteByTag(PALTAG_RIBBON_ICONS_2);
    FreeSpritePaletteByTag(PALTAG_RIBBON_ICONS_3);
    FreeSpritePaletteByTag(PALTAG_RIBBON_ICONS_4);
    FreeSpritePaletteByTag(PALTAG_RIBBON_ICONS_5);
    FreeSpriteOamMatrix(menu->bigRibbonSprite);
    DestroySprite(menu->bigRibbonSprite);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
}

static bool32 GetCurrentLoopedTaskActive(void)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    return IsLoopedTaskActive(menu->loopedTaskId);
}

#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
__attribute__((naked)) u32 LoopedTask_OpenRibbonsSummaryMenu(s32 state)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "sub sp, #8\n\t"
            "adds r4, r0, #0\n\t"
            "movs r0, #0xe\n\t"
            "bl GetSubstructPtr\n\t"
            "adds r5, r0, #0\n\t"
            "cmp r4, #9\n\t"
            "bls _081D0130\n\t"
            "b _081D02F8\n\t"
            "_081D0130:\n\t"
            "lsls r0, r4, #2\n\t"
            "ldr r1, _081D013C\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r0, [r0]\n\t"
            "mov pc, r0\n\t"
            ".align 2, 0\n\t"
            "_081D013C: .4byte _081D0140\n\t"
            "_081D0140: @ jump table\n\t"
            ".4byte _081D0168 @ case 0\n\t"
            ".4byte _081D01B4 @ case 1\n\t"
            ".4byte _081D0224 @ case 2\n\t"
            ".4byte _081D0238 @ case 3\n\t"
            ".4byte _081D024C @ case 4\n\t"
            ".4byte _081D0260 @ case 5\n\t"
            ".4byte _081D0274 @ case 6\n\t"
            ".4byte _081D0288 @ case 7\n\t"
            ".4byte _081D0298 @ case 8\n\t"
            ".4byte _081D02EC @ case 9\n\t"
            "_081D0168:\n\t"
            "ldr r0, _081D01A4\n\t"
            "movs r1, #2\n\t"
            "bl InitBgTemplates\n\t"
            "ldr r1, _081D01A8\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #2\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0\n\t"
            "bl DecompressAndCopyTileDataToVram\n\t"
            "adds r1, r5, #0\n\t"
            "adds r1, #0x1c\n\t"
            "movs r0, #2\n\t"
            "bl SetBgTilemapBuffer\n\t"
            "ldr r1, _081D01AC\n\t"
            "movs r0, #2\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0\n\t"
            "bl CopyToBgTilemapBuffer\n\t"
            "ldr r0, _081D01B0\n\t"
            "movs r1, #0x10\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "b _081D026A\n\t"
            ".align 2, 0\n\t"
            "_081D01A4: .4byte 0x085F7214\n\t"
            "_081D01A8: .4byte 0x085F64AC\n\t"
            "_081D01AC: .4byte 0x085F65A8\n\t"
            "_081D01B0: .4byte 0x085F648C\n\t"
            "_081D01B4:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r4, r0, #0x18\n\t"
            "cmp r4, #0\n\t"
            "beq _081D01C2\n\t"
            "b _081D02F4\n\t"
            "_081D01C2:\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #1\n\t"
            "bl BgDmaFill\n\t"
            "ldr r1, _081D0214\n\t"
            "str r4, [sp]\n\t"
            "movs r0, #1\n\t"
            "movs r2, #0\n\t"
            "movs r3, #1\n\t"
            "bl DecompressAndCopyTileDataToVram\n\t"
            "ldr r0, _081D0218\n\t"
            "adds r1, r5, r0\n\t"
            "movs r0, #1\n\t"
            "bl SetBgTilemapBuffer\n\t"
            "movs r0, #0x20\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #0x14\n\t"
            "str r0, [sp, #4]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0\n\t"
            "bl FillBgTilemapBufferRect_Palette0\n\t"
            "ldr r0, _081D021C\n\t"
            "movs r1, #0x20\n\t"
            "movs r2, #0xa0\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "ldr r0, _081D0220\n\t"
            "movs r1, #0xa0\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "movs r0, #1\n\t"
            "b _081D026C\n\t"
            ".align 2, 0\n\t"
            "_081D0214: .4byte 0x085F6734\n\t"
            "_081D0218: .4byte 0x0000081C\n\t"
            "_081D021C: .4byte 0x085F6674\n\t"
            "_081D0220: .4byte 0x085F6714\n\t"
            "_081D0224:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081D02F4\n\t"
            "adds r0, r5, #0\n\t"
            "bl AddRibbonCountWindow\n\t"
            "movs r0, #0\n\t"
            "b _081D02FA\n\t"
            "_081D0238:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081D02F4\n\t"
            "adds r0, r5, #0\n\t"
            "bl AddRibbonSummaryMonNameWindow\n\t"
            "movs r0, #0\n\t"
            "b _081D02FA\n\t"
            "_081D024C:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081D02F4\n\t"
            "adds r0, r5, #0\n\t"
            "bl AddRibbonListIndexWindow\n\t"
            "movs r0, #0\n\t"
            "b _081D02FA\n\t"
            "_081D0260:\n\t"
            "bl IsDma3ManagerBusyWithBgCopy\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081D02F4\n\t"
            "_081D026A:\n\t"
            "movs r0, #2\n\t"
            "_081D026C:\n\t"
            "bl CopyBgTilemapBufferToVram\n\t"
            "movs r0, #0\n\t"
            "b _081D02FA\n\t"
            "_081D0274:\n\t"
            "bl IsDma3ManagerBusyWithBgCopy\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081D02F4\n\t"
            "adds r0, r5, #0\n\t"
            "bl ResetSpritesAndDrawMonFrontPic\n\t"
            "movs r0, #1\n\t"
            "b _081D02FA\n\t"
            "_081D0288:\n\t"
            "adds r0, r5, #0\n\t"
            "bl DrawAllRibbonsSmall\n\t"
            "movs r0, #0xa\n\t"
            "bl PrintHelpBarText\n\t"
            "movs r0, #0\n\t"
            "b _081D02FA\n\t"
            "_081D0298:\n\t"
            "bl IsDma3ManagerBusyWithBgCopy\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081D02F4\n\t"
            "adds r0, r5, #0\n\t"
            "bl CreateBigRibbonSprite\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgX\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgY\n\t"
            "movs r0, #2\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgX\n\t"
            "movs r0, #2\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgY\n\t"
            "movs r0, #1\n\t"
            "bl ShowBg\n\t"
            "movs r0, #2\n\t"
            "bl ShowBg\n\t"
            "movs r0, #3\n\t"
            "bl HideBg\n\t"
            "movs r0, #1\n\t"
            "bl PokenavFadeScreen\n\t"
            "movs r0, #0\n\t"
            "b _081D02FA\n\t"
            "_081D02EC:\n\t"
            "bl IsPaletteFadeActive\n\t"
            "cmp r0, #0\n\t"
            "beq _081D02F8\n\t"
            "_081D02F4:\n\t"
            "movs r0, #2\n\t"
            "b _081D02FA\n\t"
            "_081D02F8:\n\t"
            "movs r0, #4\n\t"
            "_081D02FA:\n\t"
            "add sp, #8\n\t"
            "pop {r4, r5}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            ".syntax divided");
}
#else
u32 LoopedTask_OpenRibbonsSummaryMenu(s32 state)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    switch (state)
    {
    case 0:
        InitBgTemplates(sBgTemplates, ARRAY_COUNT(sBgTemplates));
        DecompressAndCopyTileDataToVram(2, gPokenavRibbonsSummaryBg_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(2, menu->tilemapBuffers[0]);
        CopyToBgTilemapBuffer(2, gPokenavRibbonsSummaryBg_Tilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(gPokenavRibbonsSummaryBg_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        CopyBgTilemapBufferToVram(2);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            BgDmaFill(1, 0, 0, 1);
            DecompressAndCopyTileDataToVram(1, sRibbonIconsSmall_Gfx, 0, 1, 0);
            SetBgTilemapBuffer(1, menu->tilemapBuffers[1]);
            FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
            CopyPaletteIntoBufferUnfaded(sRibbonIcons1_Pal, BG_PLTT_ID(2), 5 * PLTT_SIZE_4BPP);
            CopyPaletteIntoBufferUnfaded(sMonInfo_Pal, BG_PLTT_ID(10), sizeof(sMonInfo_Pal));
            CopyBgTilemapBufferToVram(1);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            AddRibbonCountWindow(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 3:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            AddRibbonSummaryMonNameWindow(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 4:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            AddRibbonListIndexWindow(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CopyBgTilemapBufferToVram(2);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ResetSpritesAndDrawMonFrontPic(menu);
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 7:
        DrawAllRibbonsSmall(menu);
        PrintHelpBarText(HELPBAR_RIBBONS_LIST);
        return LT_INC_AND_PAUSE;
    case 8:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CreateBigRibbonSprite(menu);
            ChangeBgX(1, 0, BG_COORD_SET);
            ChangeBgY(1, 0, BG_COORD_SET);
            ChangeBgX(2, 0, BG_COORD_SET);
            ChangeBgY(2, 0, BG_COORD_SET);
            ShowBg(1);
            ShowBg(2);
            HideBg(3);
            PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 9:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
    }
    return LT_FINISH;
}
#endif

#else
u32 LoopedTask_OpenRibbonsSummaryMenu(s32 state)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    switch (state)
    {
    case 0:
        InitBgTemplates(sBgTemplates, ARRAY_COUNT(sBgTemplates));
        DecompressAndCopyTileDataToVram(2, gPokenavRibbonsSummaryBg_Gfx, 0, 0, 0);
        SetBgTilemapBuffer(2, menu->tilemapBuffers[0]);
        CopyToBgTilemapBuffer(2, gPokenavRibbonsSummaryBg_Tilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(gPokenavRibbonsSummaryBg_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        CopyBgTilemapBufferToVram(2);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            BgDmaFill(1, 0, 0, 1);
            DecompressAndCopyTileDataToVram(1, sRibbonIconsSmall_Gfx, 0, 1, 0);
            SetBgTilemapBuffer(1, menu->tilemapBuffers[1]);
            FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
            CopyPaletteIntoBufferUnfaded(sRibbonIcons1_Pal, BG_PLTT_ID(2), 5 * PLTT_SIZE_4BPP);
            CopyPaletteIntoBufferUnfaded(sMonInfo_Pal, BG_PLTT_ID(10), sizeof(sMonInfo_Pal));
            CopyBgTilemapBufferToVram(1);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            AddRibbonCountWindow(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 3:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            AddRibbonSummaryMonNameWindow(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 4:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            AddRibbonListIndexWindow(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CopyBgTilemapBufferToVram(2);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ResetSpritesAndDrawMonFrontPic(menu);
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 7:
        DrawAllRibbonsSmall(menu);
        PrintHelpBarText(HELPBAR_RIBBONS_LIST);
        return LT_INC_AND_PAUSE;
    case 8:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CreateBigRibbonSprite(menu);
            ChangeBgX(1, 0, BG_COORD_SET);
            ChangeBgY(1, 0, BG_COORD_SET);
            ChangeBgX(2, 0, BG_COORD_SET);
            ChangeBgY(2, 0, BG_COORD_SET);
            ShowBg(1);
            ShowBg(2);
            HideBg(3);
            PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 9:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
    }
    return LT_FINISH;
}
#endif


static u32 LoopedTask_ExitRibbonsSummaryMenu(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        return LT_FINISH;
    }
    return LT_FINISH;
}

static u32 LoopedTask_SwitchRibbonsSummaryMon(s32 state)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        SlideMonSpriteOff(menu);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!IsMonSpriteAnimating(menu))
        {
            PrintRibbbonsSummaryMonInfo(menu);
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 2:
        DrawAllRibbonsSmall(menu);
        return LT_INC_AND_CONTINUE;
    case 3:
        PrintRibbonsMonListIndex(menu);
        return LT_INC_AND_CONTINUE;
    case 4:
        PrintCurrentMonRibbonCount(menu);
        return LT_INC_AND_CONTINUE;
    case 5:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SlideMonSpriteOn(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 6:
        if (IsMonSpriteAnimating(menu))
            return LT_PAUSE;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ExpandSelectedRibbon(s32 state)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        UpdateAndZoomInSelectedRibbon(menu);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!IsRibbonAnimating(menu))
        {
            PrintRibbonNameAndDescription(menu);
            PrintHelpBarText(HELPBAR_RIBBONS_CHECK);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveRibbonsCursorExpanded(s32 state)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        ZoomOutSelectedRibbon(menu);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!IsRibbonAnimating(menu))
        {
            UpdateAndZoomInSelectedRibbon(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (!IsRibbonAnimating(menu))
        {
            PrintRibbonNameAndDescription(menu);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ShrinkExpandedRibbon(s32 state)
{
    struct Pokenav_RibbonsSummaryMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_SUMMARY_MENU);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        ZoomOutSelectedRibbon(menu);
        return LT_INC_AND_PAUSE;
    case 1:
        if (!IsRibbonAnimating(menu))
        {
            PrintCurrentMonRibbonCount(menu);
            PrintHelpBarText(HELPBAR_RIBBONS_LIST);
            return LT_INC_AND_PAUSE;
        }
        return LT_PAUSE;
    case 2:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
    }
    return LT_FINISH;
}


static void AddRibbonCountWindow(struct Pokenav_RibbonsSummaryMenu *menu)
{
    menu->ribbonCountWindowId = AddWindow(&sRibbonCountWindowTemplate);
    PutWindowTilemap(menu->ribbonCountWindowId);
    PrintCurrentMonRibbonCount(menu);
}

#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
__attribute__((naked)) void PrintCurrentMonRibbonCount(struct Pokenav_RibbonsSummaryMenu *menu)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "sub sp, #0x10\n\t"
            "adds r5, r0, #0\n\t"
            "ldr r1, _081D059C\n\t"
            "add r0, sp, #0xc\n\t"
            "movs r2, #3\n\t"
            "bl memcpy\n\t"
            "ldr r4, _081D05A0\n\t"
            "bl GetCurrMonRibbonCount\n\t"
            "adds r1, r0, #0\n\t"
            "adds r0, r4, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #2\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "bl DynamicPlaceholderTextUtil_Reset\n\t"
            "movs r0, #0\n\t"
            "adds r1, r4, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "ldr r4, _081D05A4\n\t"
            "ldr r1, _081D05A8\n\t"
            "adds r0, r4, #0\n\t"
            "bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
            "ldrb r0, [r5, #0xa]\n\t"
            "movs r1, #0x44\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "ldrb r0, [r5, #0xa]\n\t"
            "add r1, sp, #0xc\n\t"
            "str r1, [sp]\n\t"
            "movs r1, #1\n\t"
            "rsbs r1, r1, #0\n\t"
            "str r1, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "movs r3, #2\n\t"
            "bl AddTextPrinterParameterized3\n\t"
            "ldrb r0, [r5, #0xa]\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "add sp, #0x10\n\t"
            "pop {r4, r5}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D059C: .4byte 0x085F723C\n\t"
            "_081D05A0: .4byte gStringVar1\n\t"
            "_081D05A4: .4byte gStringVar4\n\t"
            "_081D05A8: .4byte 0x085CB821\n\t"
            ".syntax divided");
}
#else
void PrintCurrentMonRibbonCount(struct Pokenav_RibbonsSummaryMenu *menu)
{
    u8 color[] = {TEXT_COLOR_RED, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

    ConvertIntToDecimalStringN(gStringVar1, GetCurrMonRibbonCount(), STR_CONV_MODE_LEFT_ALIGN, 2);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_RibbonsF700);
    FillWindowPixelBuffer(menu->ribbonCountWindowId, PIXEL_FILL(4));
    AddTextPrinterParameterized3(menu->ribbonCountWindowId, FONT_NORMAL, 0, 1, color, TEXT_SKIP_DRAW, gStringVar4);
    CopyWindowToVram(menu->ribbonCountWindowId, COPYWIN_GFX);
}
#endif

#else
void PrintCurrentMonRibbonCount(struct Pokenav_RibbonsSummaryMenu *menu)
{
    u8 color[] = {TEXT_COLOR_RED, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

    ConvertIntToDecimalStringN(gStringVar1, GetCurrMonRibbonCount(), STR_CONV_MODE_LEFT_ALIGN, 2);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_RibbonsF700);
    FillWindowPixelBuffer(menu->ribbonCountWindowId, PIXEL_FILL(4));
    AddTextPrinterParameterized3(menu->ribbonCountWindowId, FONT_NORMAL, 0, 1, color, TEXT_SKIP_DRAW, gStringVar4);
    CopyWindowToVram(menu->ribbonCountWindowId, COPYWIN_GFX);
}
#endif


#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
__attribute__((naked)) void PrintRibbonNameAndDescription(struct Pokenav_RibbonsSummaryMenu *menu)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, r8\n\t"
            "push {r7}\n\t"
            "sub sp, #0x10\n\t"
            "adds r7, r0, #0\n\t"
            "bl GetRibbonId\n\t"
            "adds r5, r0, #0\n\t"
            "ldr r1, _081D0608\n\t"
            "add r0, sp, #0xc\n\t"
            "movs r2, #3\n\t"
            "bl memcpy\n\t"
            "ldrb r0, [r7, #0xa]\n\t"
            "movs r1, #0x44\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "cmp r5, #0x18\n\t"
            "bhi _081D0610\n\t"
            "lsls r1, r5, #3\n\t"
            "ldr r0, _081D060C\n\t"
            "adds r6, r1, r0\n\t"
            "movs r5, #0x80\n\t"
            "lsls r5, r5, #0x12\n\t"
            "movs r4, #1\n\t"
            "_081D05DE:\n\t"
            "ldrb r0, [r7, #0xa]\n\t"
            "lsrs r3, r5, #0x18\n\t"
            "add r1, sp, #0xc\n\t"
            "str r1, [sp]\n\t"
            "movs r1, #1\n\t"
            "rsbs r1, r1, #0\n\t"
            "str r1, [sp, #4]\n\t"
            "ldm r6!, {r1}\n\t"
            "str r1, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "bl AddTextPrinterParameterized3\n\t"
            "movs r0, #0x80\n\t"
            "lsls r0, r0, #0x15\n\t"
            "adds r5, r5, r0\n\t"
            "subs r4, #1\n\t"
            "cmp r4, #0\n\t"
            "bge _081D05DE\n\t"
            "b _081D065A\n\t"
            ".align 2, 0\n\t"
            "_081D0608: .4byte 0x085F723C\n\t"
            "_081D060C: .4byte 0x085F5F60\n\t"
            "_081D0610:\n\t"
            "ldr r0, _081D0670\n\t"
            "ldr r0, [r0]\n\t"
            "adds r0, r0, r5\n\t"
            "ldr r1, _081D0674\n\t"
            "adds r0, r0, r1\n\t"
            "ldrb r5, [r0]\n\t"
            "cmp r5, #0\n\t"
            "beq _081D0662\n\t"
            "subs r5, #1\n\t"
            "movs r4, #0\n\t"
            "ldr r0, _081D0678\n\t"
            "mov r8, r0\n\t"
            "movs r6, #0x80\n\t"
            "lsls r6, r6, #0x12\n\t"
            "_081D062C:\n\t"
            "ldrb r0, [r7, #0xa]\n\t"
            "lsrs r3, r6, #0x18\n\t"
            "add r1, sp, #0xc\n\t"
            "str r1, [sp]\n\t"
            "movs r1, #1\n\t"
            "rsbs r1, r1, #0\n\t"
            "str r1, [sp, #4]\n\t"
            "lsls r1, r4, #2\n\t"
            "lsls r2, r5, #3\n\t"
            "adds r1, r1, r2\n\t"
            "add r1, r8\n\t"
            "ldr r1, [r1]\n\t"
            "str r1, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "bl AddTextPrinterParameterized3\n\t"
            "movs r0, #0x80\n\t"
            "lsls r0, r0, #0x15\n\t"
            "adds r6, r6, r0\n\t"
            "adds r4, #1\n\t"
            "cmp r4, #1\n\t"
            "ble _081D062C\n\t"
            "_081D065A:\n\t"
            "ldrb r0, [r7, #0xa]\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "_081D0662:\n\t"
            "add sp, #0x10\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D0670: .4byte gSaveBlock1Ptr\n\t"
            "_081D0674: .4byte 0x0000318F\n\t"
            "_081D0678: .4byte 0x085F628C\n\t"
            ".syntax divided");
}
#else
void PrintRibbonNameAndDescription(struct Pokenav_RibbonsSummaryMenu *menu)
{
    s32 i;
    u32 ribbonId = GetRibbonId();
    u8 color[] = {TEXT_COLOR_RED, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

    FillWindowPixelBuffer(menu->ribbonCountWindowId, PIXEL_FILL(4));
    if (ribbonId < FIRST_GIFT_RIBBON)
    {
        // Print normal ribbon name/description
        for (i = 0; i < 2; i++)
            AddTextPrinterParameterized3(menu->ribbonCountWindowId, FONT_NORMAL, 0, (i * 16) + 1, color, TEXT_SKIP_DRAW, gRibbonDescriptionPointers[ribbonId][i]);
    }
    else
    {
        // ribbonId here is one of the 'gift' ribbon slots, used to read
        // its actual value from giftRibbons to determine which specific
        // gift ribbon it is
        ribbonId = gSaveBlock1Ptr->giftRibbons[ribbonId - FIRST_GIFT_RIBBON];

        // If 0, this gift ribbon slot is unoccupied
        if (ribbonId == 0)
            return;

        // Print gift ribbon name/description
        ribbonId--;
        for (i = 0; i < 2; i++)
            AddTextPrinterParameterized3(menu->ribbonCountWindowId, FONT_NORMAL, 0, (i * 16) + 1, color, TEXT_SKIP_DRAW, gGiftRibbonDescriptionPointers[ribbonId][i]);
    }

    CopyWindowToVram(menu->ribbonCountWindowId, COPYWIN_GFX);
}
#endif

#else
void PrintRibbonNameAndDescription(struct Pokenav_RibbonsSummaryMenu *menu)
{
    s32 i;
    u32 ribbonId = GetRibbonId();
    u8 color[] = {TEXT_COLOR_RED, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

    FillWindowPixelBuffer(menu->ribbonCountWindowId, PIXEL_FILL(4));
    if (ribbonId < FIRST_GIFT_RIBBON)
    {
        // Print normal ribbon name/description
        for (i = 0; i < 2; i++)
            AddTextPrinterParameterized3(menu->ribbonCountWindowId, FONT_NORMAL, 0, (i * 16) + 1, color, TEXT_SKIP_DRAW, gRibbonDescriptionPointers[ribbonId][i]);
    }
    else
    {
        // ribbonId here is one of the 'gift' ribbon slots, used to read
        // its actual value from giftRibbons to determine which specific
        // gift ribbon it is
        ribbonId = gSaveBlock1Ptr->giftRibbons[ribbonId - FIRST_GIFT_RIBBON];

        // If 0, this gift ribbon slot is unoccupied
        if (ribbonId == 0)
            return;

        // Print gift ribbon name/description
        ribbonId--;
        for (i = 0; i < 2; i++)
            AddTextPrinterParameterized3(menu->ribbonCountWindowId, FONT_NORMAL, 0, (i * 16) + 1, color, TEXT_SKIP_DRAW, gGiftRibbonDescriptionPointers[ribbonId][i]);
    }

    CopyWindowToVram(menu->ribbonCountWindowId, COPYWIN_GFX);
}
#endif



static void AddRibbonSummaryMonNameWindow(struct Pokenav_RibbonsSummaryMenu *menu)
{
    menu->nameWindowId = AddWindow(&sRibbonSummaryMonNameWindowTemplate);
    PutWindowTilemap(menu->nameWindowId);
    PrintRibbbonsSummaryMonInfo(menu);
}


#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
__attribute__((naked)) void PrintRibbbonsSummaryMonInfo(struct Pokenav_RibbonsSummaryMenu *menu)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, r8\n\t"
            "push {r7}\n\t"
            "sub sp, #0x10\n\t"
            "adds r7, r0, #0\n\t"
            "ldr r4, _081D070C\n\t"
            "movs r0, #0xd\n\t"
            "add r0, sp\n\t"
            "mov r8, r0\n\t"
            "adds r0, r4, #0\n\t"
            "add r1, sp, #0xc\n\t"
            "mov r2, r8\n\t"
            "bl GetMonNicknameLevelGender\n\t"
            "ldr r6, _081D0710\n\t"
            "adds r0, r6, #0\n\t"
            "adds r1, r4, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #5\n\t"
            "bl StringCopyPadded\n\t"
            "add r0, sp, #0xc\n\t"
            "ldrb r1, [r0]\n\t"
            "adds r0, r4, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "ldr r5, _081D0714\n\t"
            "adds r0, r5, #0\n\t"
            "adds r1, r4, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl StringCopyPadded\n\t"
            "bl DynamicPlaceholderTextUtil_Reset\n\t"
            "movs r0, #0\n\t"
            "adds r1, r6, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "movs r0, #1\n\t"
            "adds r1, r5, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "mov r1, r8\n\t"
            "ldrb r0, [r1]\n\t"
            "cmp r0, #0\n\t"
            "beq _081D071C\n\t"
            "cmp r0, #0xfe\n\t"
            "beq _081D0724\n\t"
            "ldr r1, _081D0718\n\t"
            "b _081D0726\n\t"
            ".align 2, 0\n\t"
            "_081D070C: .4byte gStringVar3\n\t"
            "_081D0710: .4byte gStringVar1\n\t"
            "_081D0714: .4byte gStringVar2\n\t"
            "_081D0718: .4byte 0x085CB7FE\n\t"
            "_081D071C:\n\t"
            "ldr r1, _081D0720\n\t"
            "b _081D0726\n\t"
            ".align 2, 0\n\t"
            "_081D0720: .4byte 0x085CB7D6\n\t"
            "_081D0724:\n\t"
            "ldr r1, _081D0764\n\t"
            "_081D0726:\n\t"
            "ldr r4, _081D0768\n\t"
            "adds r0, r4, #0\n\t"
            "bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
            "ldrb r0, [r7, #8]\n\t"
            "movs r1, #0x11\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "ldrb r0, [r7, #8]\n\t"
            "movs r1, #2\n\t"
            "str r1, [sp]\n\t"
            "movs r1, #0xff\n\t"
            "str r1, [sp, #4]\n\t"
            "movs r1, #0\n\t"
            "str r1, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "adds r2, r4, #0\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldrb r0, [r7, #8]\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "add sp, #0x10\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D0764: .4byte 0x085CB7EA\n\t"
            "_081D0768: .4byte gStringVar4\n\t"
            ".syntax divided");
}
#else
void PrintRibbbonsSummaryMonInfo(struct Pokenav_RibbonsSummaryMenu *menu)
{
    const u8 *genderTxt;
    u8 *txtPtr;
    u8 level, gender;
    u16 windowId = menu->nameWindowId;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    GetMonNicknameLevelGender(gStringVar3, &level, &gender);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar3, 0, 1, TEXT_SKIP_DRAW, NULL);
    switch (gender)
    {
    case MON_MALE:
        genderTxt = sText_MaleSymbol;
        break;
    case MON_FEMALE:
        genderTxt = sText_FemaleSymbol;
        break;
    default:
        genderTxt = sGenderlessIconString;
        break;
    }

    txtPtr = StringCopy(gStringVar1, genderTxt);
    *(txtPtr++) = CHAR_SLASH;
    *(txtPtr++) = CHAR_EXTRA_SYMBOL;
    *(txtPtr++) = CHAR_LV_2;
    ConvertIntToDecimalStringN(txtPtr, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar1, 60, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}
#endif

#else
void PrintRibbbonsSummaryMonInfo(struct Pokenav_RibbonsSummaryMenu *menu)
{
    const u8 *genderTxt;
    u8 *txtPtr;
    u8 level, gender;
    u16 windowId = menu->nameWindowId;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    GetMonNicknameLevelGender(gStringVar3, &level, &gender);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar3, 0, 1, TEXT_SKIP_DRAW, NULL);
    switch (gender)
    {
    case MON_MALE:
        genderTxt = sText_MaleSymbol;
        break;
    case MON_FEMALE:
        genderTxt = sText_FemaleSymbol;
        break;
    default:
        genderTxt = sGenderlessIconString;
        break;
    }

    txtPtr = StringCopy(gStringVar1, genderTxt);
    *(txtPtr++) = CHAR_SLASH;
    *(txtPtr++) = CHAR_EXTRA_SYMBOL;
    *(txtPtr++) = CHAR_LV_2;
    ConvertIntToDecimalStringN(txtPtr, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar1, 60, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(windowId, COPYWIN_GFX);
}
#endif



#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
__attribute__((naked)) void AddRibbonListIndexWindow(struct Pokenav_RibbonsSummaryMenu *menu)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "adds r5, r0, #0\n\t"
            "ldr r4, _081D07B4\n\t"
            "adds r0, r4, #0\n\t"
            "bl AddWindow\n\t"
            "strh r0, [r5, #0xc]\n\t"
            "adds r4, #8\n\t"
            "adds r0, r4, #0\n\t"
            "bl AddWindow\n\t"
            "strh r0, [r5, #0xe]\n\t"
            "ldrb r0, [r5, #0xc]\n\t"
            "movs r1, #0x11\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "ldrb r0, [r5, #0xe]\n\t"
            "movs r1, #0x11\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "ldrb r0, [r5, #0xc]\n\t"
            "bl PutWindowTilemap\n\t"
            "ldrb r0, [r5, #0xe]\n\t"
            "bl PutWindowTilemap\n\t"
            "ldrh r0, [r5, #0xe]\n\t"
            "bl sub_081D07B8\n\t"
            "adds r0, r5, #0\n\t"
            "bl PrintRibbonsMonListIndex\n\t"
            "pop {r4, r5}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D07B4: .4byte 0x085F7248\n\t"
            ".syntax divided");
}
#else
void AddRibbonListIndexWindow(struct Pokenav_RibbonsSummaryMenu *menu)
{
    menu->listIdxWindowId = AddWindow(sRibbonMonListIndexWindowTemplate);
    FillWindowPixelBuffer(menu->listIdxWindowId, PIXEL_FILL(1));
    PutWindowTilemap(menu->listIdxWindowId);
    PrintRibbonsMonListIndex(menu);
}
#endif

#else
void AddRibbonListIndexWindow(struct Pokenav_RibbonsSummaryMenu *menu)
{
    menu->listIdxWindowId = AddWindow(sRibbonMonListIndexWindowTemplate);
    FillWindowPixelBuffer(menu->listIdxWindowId, PIXEL_FILL(1));
    PutWindowTilemap(menu->listIdxWindowId);
    PrintRibbonsMonListIndex(menu);
}
#endif


#ifndef NONMATCHING
// JP 0x081D07B8: prints the list index row above the ribbons list.
// JP-only function (no US counterpart) kept as asm.
__attribute__((naked)) u32 sub_081D07B8(s32 state)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, lr}\n\t"
            "mov r6, r8\n\t"
            "push {r6}\n\t"
            "sub sp, #0xc\n\t"
            "adds r4, r0, #0\n\t"
            "lsls r4, r4, #0x18\n\t"
            "lsrs r4, r4, #0x18\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #0x11\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "ldr r6, _081D0818\n\t"
            "movs r0, #0\n\t"
            "mov r8, r0\n\t"
            "movs r0, #0xba\n\t"
            "strb r0, [r6]\n\t"
            "adds r5, r6, #1\n\t"
            "bl GetRibbonsSummaryMonListCount\n\t"
            "adds r1, r0, #0\n\t"
            "adds r0, r5, #0\n\t"
            "movs r2, #1\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "movs r0, #2\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #0xff\n\t"
            "str r0, [sp, #4]\n\t"
            "mov r0, r8\n\t"
            "str r0, [sp, #8]\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #1\n\t"
            "adds r2, r6, #0\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "add sp, #0xc\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D0818: .4byte gStringVar1\n\t"
            ".syntax divided");
}

#else
u32 sub_081D07B8(s32 state)
{
    u8 windowId = state;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    gStringVar1[0] = 0xBA;
    ConvertIntToDecimalStringN(&gStringVar1[1], GetRibbonsSummaryMonListCount(), STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar1, 0, 2, 0xFF, NULL);
    CopyWindowToVram(windowId, COPYWIN_GFX);
    return 0;
}
#endif

#ifndef NONMATCHING
// JP naked asm: prints only the current index (JP layout), unlike US which
// also prints "/count" centered; byte-exact asm stays default.
__attribute__((naked)) void PrintRibbonsMonListIndex(struct Pokenav_RibbonsSummaryMenu *menu)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "sub sp, #0xc\n\t"
            "adds r5, r0, #0\n\t"
            "bl GetRibbonsSummaryCurrentIndex\n\t"
            "adds r1, r0, #0\n\t"
            "adds r1, #1\n\t"
            "ldr r4, _081D0860\n\t"
            "adds r0, r4, #0\n\t"
            "movs r2, #1\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "ldrb r0, [r5, #0xc]\n\t"
            "movs r1, #2\n\t"
            "str r1, [sp]\n\t"
            "movs r1, #0xff\n\t"
            "str r1, [sp, #4]\n\t"
            "movs r1, #0\n\t"
            "str r1, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "adds r2, r4, #0\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldrb r0, [r5, #0xc]\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "add sp, #0xc\n\t"
            "pop {r4, r5}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D0860: .4byte gStringVar1\n\t"
            ".syntax divided");
}
#else
void PrintRibbonsMonListIndex(struct Pokenav_RibbonsSummaryMenu *menu)
{
    u32 id = GetRibbonsSummaryCurrentIndex() + 1;
    ConvertIntToDecimalStringN(gStringVar1, id, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized(menu->listIdxWindowId, FONT_NORMAL, gStringVar1, 0, 2, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(menu->listIdxWindowId, COPYWIN_GFX);
}
#endif

static void ResetSpritesAndDrawMonFrontPic(struct Pokenav_RibbonsSummaryMenu *menu)
{
    u16 species;
    u32 personality, otId;

    GetMonSpeciesPersonalityOtId(&species, &personality, &otId);
    ResetAllPicSprites();
    menu->monSpriteId = DrawRibbonsMonFrontPic(MON_SPRITE_X_ON, MON_SPRITE_Y);
    PokenavFillPalette(15, 0);
}

static void DestroyRibbonsMonFrontPic(struct Pokenav_RibbonsSummaryMenu *menu)
{
    FreeAndDestroyMonPicSprite(menu->monSpriteId);
}

// x and y arguments are ignored
// y is always given as MON_SPRITE_Y
// x is given as either MON_SPRITE_X_ON or MON_SPRITE_X_OFF (but ignored and MON_SPRITE_X_ON is used)
static u16 DrawRibbonsMonFrontPic(s32 x, s32 y)
{
    u16 species, spriteId;
    u32 personality, otId;

    GetMonSpeciesPersonalityOtId(&species, &personality, &otId);
    spriteId = CreateMonPicSprite_HandleDeoxys(species, otId, personality, TRUE, MON_SPRITE_X_ON, MON_SPRITE_Y, 15, TAG_NONE);
    gSprites[spriteId].oam.priority = 0;
    return spriteId;
}

static void SlideMonSpriteOff(struct Pokenav_RibbonsSummaryMenu *menu)
{
    StartMonSpriteSlide(&gSprites[menu->monSpriteId], MON_SPRITE_X_ON, MON_SPRITE_X_OFF, 6);
}

static void SlideMonSpriteOn(struct Pokenav_RibbonsSummaryMenu *menu)
{
    // Switch to new mon sprite
    FreeAndDestroyMonPicSprite(menu->monSpriteId);
    menu->monSpriteId = DrawRibbonsMonFrontPic(MON_SPRITE_X_OFF, MON_SPRITE_Y);

    // Slide on
    StartMonSpriteSlide(&gSprites[menu->monSpriteId], MON_SPRITE_X_OFF, MON_SPRITE_X_ON, 6);
}

// Is Pokémon summary sprite still sliding off/on
static bool32 IsMonSpriteAnimating(struct Pokenav_RibbonsSummaryMenu *menu)
{
    return (gSprites[menu->monSpriteId].callback != SpriteCallbackDummy);
}

#define sCurrX    data[0]
#define sMoveIncr data[1]
#define sTime     data[2]
#define sDestX    data[3]

static void StartMonSpriteSlide(struct Sprite *sprite, s32 startX, s32 destX, s32 time)
{
    u32 delta = destX - startX;

    sprite->x = startX;
    sprite->sCurrX = startX << 4;
    sprite->sMoveIncr = (delta << 4) / time;
    sprite->sTime = time;
    sprite->sDestX = destX;

    sprite->callback = SpriteCB_MonSpriteSlide;
}

static void SpriteCB_MonSpriteSlide(struct Sprite *sprite)
{
    if (sprite->sTime != 0)
    {
        sprite->sTime--;
        sprite->sCurrX += sprite->sMoveIncr;
        sprite->x = sprite->sCurrX >> 4;
        if (sprite->x <= MON_SPRITE_X_OFF)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }
    else
    {
        sprite->x = sprite->sDestX;
        sprite->callback = SpriteCallbackDummy;
    }
}

#undef sCurrX
#undef sMoveIncr
#undef sTime
#undef sDestX

static void DrawAllRibbonsSmall(struct Pokenav_RibbonsSummaryMenu *menu)
{
    u32 *ribbonIds;

    ClearRibbonsSummaryBg();

    ribbonIds = GetNormalRibbonIds(&sRibbonDraw_Total);
    for (sRibbonDraw_Current = 0; sRibbonDraw_Current < sRibbonDraw_Total; sRibbonDraw_Current++)
        DrawRibbonSmall(sRibbonDraw_Current, *(ribbonIds++));

    ribbonIds = GetGiftRibbonIds(&sRibbonDraw_Total);
    for (sRibbonDraw_Current = 0; sRibbonDraw_Current < sRibbonDraw_Total; sRibbonDraw_Current++)
        DrawRibbonSmall(sRibbonDraw_Current + GIFT_RIBBON_START_POS, *(ribbonIds++));

    CopyBgTilemapBufferToVram(1);
}

// Redundant, the same FillBg is called in LoopedTask_OpenRibbonsSummaryMenu
static void ClearRibbonsSummaryBg(void)
{
    FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 32, 20);
}

static void DrawRibbonSmall(u32 i, u32 ribbonId)
{
    u16 bgData[4];
    u32 destX = (i % RIBBONS_PER_ROW) * 2 + 11;
    u32 destY = (i / RIBBONS_PER_ROW) * 2 + 4;

    BufferSmallRibbonGfxData(bgData, ribbonId);
    CopyToBgTilemapBufferRect(1, bgData, destX, destY, 2, 2);
}

// Below correspond to a ribbon icon in ribbons/icons.png and ribbons/icons_big.png; 0 at top, 11 at bottom
enum {
    RIBBONGFX_CHAMPION,
    RIBBONGFX_CONTEST_NORMAL,
    RIBBONGFX_CONTEST_SUPER,
    RIBBONGFX_CONTEST_HYPER,
    RIBBONGFX_CONTEST_MASTER,
    RIBBONGFX_WINNING,
    RIBBONGFX_VICTORY,
    RIBBONGFX_ARTIST,
    RIBBONGFX_EFFORT,
    RIBBONGFX_GIFT_1,
    RIBBONGFX_GIFT_2,
    RIBBONGFX_GIFT_3,
};

#define TO_PAL_OFFSET(palNum) ((palNum) - PALTAG_RIBBON_ICONS_1)


#undef TO_PAL_OFFSET

static void BufferSmallRibbonGfxData(u16 *dst, u32 ribbonId)
{
    u16 palNum = sRibbonGfxData[ribbonId].palNumOffset + 2;
    u16 tileNum = (sRibbonGfxData[ribbonId].tileNumOffset * 2) + 1;

    dst[0] = tileNum | (palNum << 12);
    dst[1] = tileNum | (palNum << 12) | 0x400;
    dst[2] = (tileNum + 1) | (palNum << 12);
    dst[3] = (tileNum + 1) | (palNum << 12) | 0x400;
}







enum {
    RIBBONANIM_NORMAL,
    RIBBONANIM_ZOOM_IN,
    RIBBONANIM_ZOOM_OUT,
};



// Create dummy sprite to be used for the zoomed in version of the selected ribbon
static void CreateBigRibbonSprite(struct Pokenav_RibbonsSummaryMenu *menu)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&sSpriteSheet_RibbonIconsBig);
    Pokenav_AllocAndLoadPalettes(sSpritePalettes_RibbonIcons);

    spriteId = CreateSprite(&sSpriteTemplate_RibbonIconBig, 0, 0, 0);
    menu->bigRibbonSprite = &gSprites[spriteId];
    menu->bigRibbonSprite->invisible = TRUE;
}

#define sInvisibleWhenDone data[0]

static void UpdateAndZoomInSelectedRibbon(struct Pokenav_RibbonsSummaryMenu *menu)
{
    u32 ribbonId;
    s32 position = GetSelectedPosition();
    s32 x = (position % RIBBONS_PER_ROW) * 16 + 96;
    s32 y = (position / RIBBONS_PER_ROW) * 16 + 40;

    menu->bigRibbonSprite->x = x;
    menu->bigRibbonSprite->y = y;

    // Set new selected ribbon's gfx data
    ribbonId = GetRibbonId();
    menu->bigRibbonSprite->oam.tileNum = (sRibbonGfxData[ribbonId].tileNumOffset * 16) + GetSpriteTileStartByTag(GFXTAG_RIBBON_ICONS_BIG);
    menu->bigRibbonSprite->oam.paletteNum = IndexOfSpritePaletteTag(sRibbonGfxData[ribbonId].palNumOffset + PALTAG_RIBBON_ICONS_1);

    // Start zoom in animation
    StartSpriteAffineAnim(menu->bigRibbonSprite, RIBBONANIM_ZOOM_IN);
    menu->bigRibbonSprite->invisible = FALSE;
    menu->bigRibbonSprite->sInvisibleWhenDone = FALSE;
    menu->bigRibbonSprite->callback = SpriteCB_WaitForRibbonAnimation;
}

// Start animation to zoom out of selected ribbon
static void ZoomOutSelectedRibbon(struct Pokenav_RibbonsSummaryMenu *menu)
{
    menu->bigRibbonSprite->sInvisibleWhenDone = TRUE;
    StartSpriteAffineAnim(menu->bigRibbonSprite, RIBBONANIM_ZOOM_OUT);
    menu->bigRibbonSprite->callback = SpriteCB_WaitForRibbonAnimation;
}

static bool32 IsRibbonAnimating(struct Pokenav_RibbonsSummaryMenu *menu)
{
    return (menu->bigRibbonSprite->callback != SpriteCallbackDummy);
}

static void SpriteCB_WaitForRibbonAnimation(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        sprite->invisible = sprite->sInvisibleWhenDone;
        sprite->callback = SpriteCallbackDummy;
    }
}
