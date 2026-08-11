#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "menu_specialized.h"
#include "mon_markings.h"
#include "palette.h"
#include "pokenav.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"
#include "constants/songs.h"

typedef u8 ALIGNED(4) TilemapBuffer[BG_SCREEN_SIZE];

struct Pokenav_ConditionMenuGfx
{
    u32 loopedTaskId;
    TilemapBuffer tilemapBuffers[3];
    u8 filler[2];
    u8 partyPokeballSpriteIds[PARTY_SIZE + 1];
    u32 (*callback)(void);
    s16 monTransitionX;
    u8 monPicSpriteId;
    u16 monPalIndex;
    u16 monGfxTileStart;
    void *monGfxPtr;
    u8 nameGenderWindowId;
    u8 listIndexWindowId;
    u8 unusedWindowId1;
    u8 unusedWindowId2;
    struct MonMarkingsMenu marksMenu;
    struct Sprite *monMarksSprite;
    struct Sprite *conditionSparkleSprites[MAX_CONDITION_SPARKLES];
    u8 windowModeState;
    u8 filler2[0xFA3];
};

struct Pokenav_SearchResultsGfx
{
    bool32 (*callback)(void);
    u32 loopedTaskId;
    u16 winid;
    bool32 fromGraph;
    u8 buff[BG_SCREEN_SIZE];
};

struct Pokenav_SearchResults
{
    u32 (*callback)(struct Pokenav_SearchResults *);
    u32 loopedTaskId;
    u8 fill1[4];
    s32 boxId;
    s32 monId;
    u32 conditionDataId;
    bool32 returnFromGraph;
    bool32 saveResultsList;
    struct PokenavMonList *monList;
};

struct Pokenav_RibbonsMonList
{
    u32 (*callback)(struct Pokenav_RibbonsMonList *);
    u32 loopedTaskId;
    u16 winid;
    s32 boxId;
    s32 monId;
    u32 changeBgs;
    u32 saveMonList;
    struct PokenavMonList *monList;
};

struct Pokenav_RibbonsMonMenu
{
    bool32 (*callback)(void);
    u32 loopedTaskId;
    u16 winid;
    bool32 fromSummary;
    u8 buff[BG_SCREEN_SIZE];
};

extern u8 sInitialLoadId; // JP IWRAM, bound in ld_script_jp.txt
extern const u8 gText_SearchResultRank[]; // JP 0x085CB81B, bound in ld_script_jp.txt
extern const struct BgTemplate sSearchResultsBgTemplates[]; // JP 0x085F5BA0
extern const struct BgTemplate sRibbonsMonListBgTemplates[]; // JP 0x085F5DA4

// JP sign-extends the u8 load id at call sites (pokeemerald gfx.c declared it s8).
extern s8 GetConditionGraphMenuCurrentLoadIndex(void);


// Naked-function prototypes so C callers use the right argument types.
void CreateConditionMonPic(u8 id);
bool32 UpdateConditionGraphMenuWindows(u8 mode, u16 bufferIndex, bool8 winMode);
static void PrintSearchResultListMenuItems(struct Pokenav_SearchResultsGfx *gfx);
static void BufferSearchMonListItem(struct PokenavMonListItem *item, u8 *dest);
static u32 LoopedTask_OpenConditionSearchResults(s32 state);
static void CreateSearchResultsList(void);
static u32 GetMonRibbonListLoopTaskFunc(s32 state);
static u32 LoopedTask_OpenRibbonsMonList(s32 state);
static void DrawListIndexNumber(u16 windowId, u16 index);
static void AddRibbonsMonListWindow(struct Pokenav_RibbonsMonMenu *menu);
static void CreateRibbonMonsList(void);
static void BufferRibbonMonInfoText(u8 windowId, u16 index);
static bool32 IsRibbonsMonListLoopedTaskActive(void);
static u32 LoopedTask_MoveSearchListCursorUp(s32 state);
static u32 LoopedTask_MoveSearchListCursorDown(s32 state);
static u32 LoopedTask_MoveSearchListPageUp(s32 state);
static u32 LoopedTask_MoveSearchListPageDown(s32 state);
static u32 LoopedTask_RibbonsListMoveCursorUp(s32 state);
static u32 LoopedTask_RibbonsListMoveCursorDown(s32 state);
static u32 LoopedTask_RibbonsListMovePageUp(s32 state);
static u32 LoopedTask_RibbonsListMovePageDown(s32 state);
static void UpdateIndexNumberDisplay(u8 windowId, u16 index);

static u32 LoopedTask_TransitionMons(s32 state);
static u32 LoopedTask_MoveCursorNoTransition(s32 state);
static u32 LoopedTask_SlideMonOut(s32 state);
static u32 LoopedTask_OpenMonMarkingsWindow(s32 state);
static u32 LoopedTask_CloseMonMarkingsWindow(s32 state);
void CopyUnusedConditionWindowsToVram(void);
static void SpriteCB_PartyPokeball(struct Sprite *sprite);
static void HighlightCurrentPartyIndexPokeball(struct Sprite *sprite);
static void MonMarkingsCallback(struct Sprite *sprite);
void CreateMonMarkingsOrPokeballIndicators(void);
static void FreeConditionMenuGfx(struct Pokenav_ConditionMenuGfx *menu);
static void FreeConditionGraphMenuSubstruct2(void);
static void MonPicGfxSpriteCallback(struct Sprite *sprite);
void CreateConditionMonPic(u8 id);
void VBlankCB_PokenavConditionGraph(void);
static void SetExitVBlank(void);
void ToggleGraphData(bool8 showBg);
void DoConditionGraphEnterTransition(void);
void DoConditionGraphExitTransition(void);
u8 GetMonMarkingsData(void);
static bool32 PokenavCallback_Init_ConditionSearch(void);
static bool32 PokenavCallback_Init_ReturnToMonSearchList(void);
static u32 GetConditionSearchResultsCallback(void);
static void FreeSearchResultSubstruct1(void);
static bool32 HandleConditionSearchInput_WaitSetup(struct Pokenav_SearchResults *menu);
static u32 HandleConditionSearchInput(struct Pokenav_SearchResults *menu);
static u32 ReturnToConditionSearchList(struct Pokenav_SearchResults *menu);
static u32 OpenConditionGraphFromSearchList(struct Pokenav_SearchResults *menu);
static u32 GetReturningFromGraph(void);
static struct PokenavMonListItem * GetSearchResultsMonDataList(void);
static u16 GetSearchResultsMonListCount(void);
static s32 GetSearchResultsSelectedMonRank(void);
static u16 GetSearchResultsCurrentListIndex(void);
static u32 BuildPartyMonSearchResults(s32 state);
static u32 InitBoxMonSearchResults(s32 state);
static u32 BuildBoxMonSearchResults(s32 state);
static u32 ConvertConditionsToListRanks(s32 state);
static void InsertMonListItem(struct Pokenav_SearchResults *menu, struct PokenavMonListItem *item);
static bool32 OpenConditionSearchResults(void);
static bool32 OpenConditionSearchListFromGraph(void);
static void CreateSearchResultsLoopedTask(s32 idx);
static bool32 GetSearchResultCurrentLoopedTaskActive(void);
static void FreeSearchResultSubstruct2(void);
static u32 LoopedTask_ExitConditionSearchMenu(s32 state);
static u32 LoopedTask_SelectSearchResult(s32 state);
static void AddSearchResultListMenuWindow(struct Pokenav_SearchResultsGfx *gfx);
static bool32 PokenavCallback_Init_MonRibbonList(void);
static bool32 PokenavCallback_Init_RibbonsMonListFromSummary(void);
static u32 GetRibbonsMonListCallback(void);
static void FreeRibbonsMonList(void);
static u32 HandleRibbonsMonListInput_WaitListInit(struct Pokenav_RibbonsMonList *list);
static u32 HandleRibbonsMonListInput(struct Pokenav_RibbonsMonList *list);
static u32 RibbonsMonMenu_ReturnToMainMenu(struct Pokenav_RibbonsMonList *list);
static u32 RibbonsMonMenu_ToSummaryScreen(struct Pokenav_RibbonsMonList *list);
static u32 UpdateMonListBgs(void);
static s32 GetRibbonsMonListCount(void);
static s32 GetRibbonListMenuCurrIndex(void);
static u32 GetConditionSearchLoopedTask(s32 state);
static u32 BuildPartyMonRibbonList(s32 state);
static u32 InitBoxMonRibbonList(s32 state);
static u32 BuildBoxMonRibbonList(s32 state);
static bool32 OpenRibbonsMonList(void);
static bool32 OpenRibbonsMonListFromRibbonsSummary(void);
static void CreateRibbonsMonListLoopedTask(s32 idx);
static bool32 GetRibbonsMonCurrentLoopedTaskActive(void);
static void FreeRibbonsMonMenu(void);
static u32 LoopedTask_RibbonsListReturnToMainMenu(s32 state);
static u32 LoopedTask_RibbonsListOpenSummary(s32 state);

// JP ROM data tables (defined at fixed addresses in ld_script_jp.txt).
extern const struct BgTemplate sMenuBgTemplates[3];
extern const u32 gPokenavCondition_Gfx[];
extern const u32 sConditionGraphData_Gfx[];
extern const u32 gPokenavCondition_Tilemap[];
extern const u16 gPokenavOptions_Tilemap[];
extern const u16 gPokenavCondition_Pal[];
extern const u16 gConditionText_Pal[];
extern const u32 sConditionGraphData_Tilemap[];
extern const u16 gConditionGraphData_Pal[];
extern const struct WindowTemplate sMonNameGenderWindowTemplate;
extern const struct WindowTemplate sListIndexWindowTemplate;
extern const struct WindowTemplate sUnusedWindowTemplate1;
extern const struct WindowTemplate sUnusedWindowTemplate2;
extern const LoopedTask sLoopedTaskFuncs[];
extern const u32 sSearchMonDataIds[];
extern const LoopedTask sConditionSearchLoopedTaskFuncs[];
extern const u16 sConditionSearchResultFramePal[];
extern const u32 sConditionSearchResultTiles[];
extern const u32 sConditionSearchResultTilemap[];
extern const u16 sListBg_Pal[];
extern const struct BgTemplate sConditionSearchResultBgTemplates[];
extern const LoopedTask sSearchResultLoopTaskFuncs[];
extern const struct WindowTemplate sSearchResultListMenuWindowTemplate;
extern const u8 sText_MaleSymbol[];
extern const u8 sText_FemaleSymbol[];
extern const u8 sText_NoGenderSymbol[];
extern const u16 sPokenavMonMarkings_Pal[];
extern const LoopedTask sMonRibbonListLoopTaskFuncs[];
extern const u16 sMonRibbonListFramePal[];
extern const u32 sMonRibbonListFrameTiles[];
extern const u32 sMonRibbonListFrameTilemap[];
extern const u16 sMonRibbonListUi_Pal[];
extern const struct BgTemplate sMonRibbonListBgTemplates[];
extern const LoopedTask sRibbonsMonMenuLoopTaskFuncs[];
extern const struct WindowTemplate sRibbonsMonListWindowTemplate;
extern const struct SpriteSheet sConditionSelectionSpriteSheets[];
extern const struct SpriteTemplate sConditionSelectionSpriteTemplate;
extern const struct SpritePalette sConditionSelectionSpritePalettes[];

static u32 LoopedTask_TransitionMons(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    struct ConditionGraph *graph = GetConditionGraphPtr();

    switch (state)
    {
    case 0:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_INFO);
        return LT_INC_AND_CONTINUE;
    case 1:
        LoadNextConditionMenuMonData(CONDITION_LOAD_GRAPH);
        return LT_INC_AND_CONTINUE;
    case 2:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_PIC);
        DestroyConditionSparkleSprites(menu->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 3:
        ConditionGraph_TryUpdate(graph);
        return LT_INC_AND_CONTINUE;
    case 4:
        if (!MoveConditionMonOffscreen(&menu->monTransitionX))
        {
            CreateConditionMonPic(GetConditionGraphMenuCurrentLoadIndex());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    case 5:
        UpdateConditionGraphMenuWindows(0, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphMenuWindows(1, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        UpdateConditionGraphMenuWindows(2, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 8:
        if (UpdateConditionGraphMenuWindows(3, GetConditionGraphMenuCurrentLoadIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 9:
        graph = GetConditionGraphPtr();
        if (!ConditionMenu_UpdateMonEnter(graph, &menu->monTransitionX))
        {
            ResetConditionSparkleSprites(menu->conditionSparkleSprites);
            if (IsConditionMenuSearchMode() != TRUE && GetConditionGraphCurrentListIndex() == GetMonListCount())
                return LT_INC_AND_CONTINUE;

            CreateConditionSparkleSprites(menu->conditionSparkleSprites, menu->monPicSpriteId, GetNumConditionMonSparkles());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_MoveCursorNoTransition(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (state)
    {
    case 0:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_INFO);
        return LT_INC_AND_CONTINUE;
    case 1:
        LoadNextConditionMenuMonData(CONDITION_LOAD_GRAPH);
        return LT_INC_AND_CONTINUE;
    case 2:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_PIC);
        return LT_INC_AND_CONTINUE;
    case 3:
        CreateConditionMonPic(GetConditionGraphMenuCurrentLoadIndex());
        return LT_INC_AND_CONTINUE;
    case 4:
        UpdateConditionGraphMenuWindows(0, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 5:
        UpdateConditionGraphMenuWindows(1, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphMenuWindows(2, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        if (UpdateConditionGraphMenuWindows(3, GetConditionGraphMenuCurrentLoadIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 8:
        if (!ConditionMenu_UpdateMonEnter(GetConditionGraphPtr(), &menu->monTransitionX))
        {
            ResetConditionSparkleSprites(menu->conditionSparkleSprites);
            CreateConditionSparkleSprites(menu->conditionSparkleSprites, menu->monPicSpriteId, GetNumConditionMonSparkles());
            return LT_INC_AND_CONTINUE;
        }
        return LT_PAUSE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_SlideMonOut(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (state)
    {
    case 0:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_INFO);
        return LT_INC_AND_CONTINUE;
    case 1:
        LoadNextConditionMenuMonData(CONDITION_LOAD_GRAPH);
        return LT_INC_AND_CONTINUE;
    case 2:
        LoadNextConditionMenuMonData(CONDITION_LOAD_MON_PIC);
        DestroyConditionSparkleSprites(menu->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 3:
        if (!ConditionMenu_UpdateMonExit(GetConditionGraphPtr(), &menu->monTransitionX))
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    case 4:
        UpdateConditionGraphMenuWindows(0, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 5:
        UpdateConditionGraphMenuWindows(1, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 6:
        UpdateConditionGraphMenuWindows(2, GetConditionGraphMenuCurrentLoadIndex(), FALSE);
        return LT_INC_AND_CONTINUE;
    case 7:
        if (UpdateConditionGraphMenuWindows(3, GetConditionGraphMenuCurrentLoadIndex(), FALSE) == TRUE)
            return LT_INC_AND_CONTINUE;
        return LT_PAUSE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_OpenMonMarkingsWindow(s32 state)
{
    switch (state)
    {
    case 0:
        OpenMonMarkingsMenu(TryGetMonMarkId(), 176, 32);
        return LT_INC_AND_CONTINUE;
    case 1:
        PrintHelpBarText(HELPBAR_CONDITION_MARKINGS);
        return LT_INC_AND_CONTINUE;
    case 2:
        if (WaitForHelpBar() == TRUE)
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}

static u32 LoopedTask_CloseMonMarkingsWindow(s32 state)
{
    switch (state)
    {
    case 0:
        FreeMonMarkingsMenu();
        return LT_INC_AND_CONTINUE;
    case 1:
        PrintHelpBarText(HELPBAR_CONDITION_MON_STATUS);
        return LT_INC_AND_CONTINUE;
    case 2:
        if (WaitForHelpBar() == TRUE)
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}

static u8 UNUSED *UnusedPrintNumberString(u8 *dst, u16 num)
{
    u8 *txtPtr = ConvertIntToDecimalStringN(dst, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    txtPtr = StringCopy(txtPtr, gText_Number2);

    return txtPtr;
}

__attribute__((naked)) bool32 UpdateConditionGraphMenuWindows(u8 mode, u16 bufferIndex, bool8 winMode)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "sub sp, #0x1c\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r7, r0, #0x18\n\t"
            "lsls r1, r1, #0x10\n\t"
            "lsrs r5, r1, #0x10\n\t"
            "lsls r2, r2, #0x18\n\t"
            "lsrs r4, r2, #0x18\n\t"
            "movs r0, #0xc\n\t"
            "bl GetSubstructPtr\n\t"
            "adds r6, r0, #0\n\t"
            "cmp r7, #1\n\t"
            "beq _081CDF10\n\t"
            "cmp r7, #1\n\t"
            "bgt _081CDEDA\n\t"
            "cmp r7, #0\n\t"
            "beq _081CDEE4\n\t"
            "b _081CE05C\n\t"
            "_081CDEDA:\n\t"
            "cmp r7, #2\n\t"
            "beq _081CDF52\n\t"
            "cmp r7, #3\n\t"
            "beq _081CDFD4\n\t"
            "b _081CE05C\n\t"
            "_081CDEE4:\n\t"
            "movs r1, #0xc1\n\t"
            "lsls r1, r1, #5\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "movs r1, #0\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "beq _081CDEFC\n\t"
            "b _081CE05C\n\t"
            "_081CDEFC:\n\t"
            "ldr r1, _081CDF0C\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "movs r1, #0\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "b _081CE05C\n\t"
            ".align 2, 0\n\t"
            "_081CDF0C: .4byte 0x00001821\n\t"
            "_081CDF10:\n\t"
            "bl GetConditionGraphCurrentListIndex\n\t"
            "adds r4, r0, #0\n\t"
            "lsls r4, r4, #0x10\n\t"
            "lsrs r4, r4, #0x10\n\t"
            "bl GetMonListCount\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r0, r0, #0x10\n\t"
            "subs r0, #1\n\t"
            "cmp r4, r0\n\t"
            "bne _081CDF32\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "beq _081CDF32\n\t"
            "b _081CE05C\n\t"
            "_081CDF32:\n\t"
            "lsls r0, r5, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "bl GetConditionMonNameText\n\t"
            "adds r2, r0, #0\n\t"
            "movs r1, #0xc1\n\t"
            "lsls r1, r1, #5\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "movs r1, #2\n\t"
            "str r1, [sp]\n\t"
            "movs r1, #0\n\t"
            "str r1, [sp, #4]\n\t"
            "str r1, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "b _081CDFC4\n\t"
            "_081CDF52:\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "beq _081CDF5C\n\t"
            "b _081CE05C\n\t"
            "_081CDF5C:\n\t"
            "lsls r0, r5, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "bl GetConditionMonLocationText\n\t"
            "adds r2, r0, #0\n\t"
            "movs r1, #0xc1\n\t"
            "lsls r1, r1, #5\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "movs r1, #0x12\n\t"
            "str r1, [sp]\n\t"
            "movs r5, #0\n\t"
            "str r5, [sp, #4]\n\t"
            "str r5, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "add r1, sp, #0xc\n\t"
            "movs r0, #0xfc\n\t"
            "strb r0, [r1]\n\t"
            "movs r0, #4\n\t"
            "strb r0, [r1, #1]\n\t"
            "movs r0, #8\n\t"
            "strb r0, [r1, #2]\n\t"
            "adds r0, r1, #0\n\t"
            "strb r5, [r0, #3]\n\t"
            "movs r0, #9\n\t"
            "strb r0, [r1, #4]\n\t"
            "mov r4, sp\n\t"
            "adds r4, #0x11\n\t"
            "bl GetConditionMonDataBuffer\n\t"
            "adds r1, r0, #0\n\t"
            "lsls r1, r1, #0x10\n\t"
            "lsrs r1, r1, #0x10\n\t"
            "adds r0, r4, #0\n\t"
            "bl UnusedPrintNumberString\n\t"
            "ldr r4, _081CDFCC\n\t"
            "adds r0, r4, #0\n\t"
            "add r1, sp, #0xc\n\t"
            "bl StringExpandPlaceholders\n\t"
            "ldr r1, _081CDFD0\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "str r7, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r5, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "adds r2, r4, #0\n\t"
            "_081CDFC4:\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "b _081CE05C\n\t"
            ".align 2, 0\n\t"
            "_081CDFCC: .4byte gStringVar4\n\t"
            "_081CDFD0: .4byte 0x00001821\n\t"
            "_081CDFD4:\n\t"
            "ldr r1, _081CDFE4\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "cmp r0, #0\n\t"
            "beq _081CDFE8\n\t"
            "cmp r0, #1\n\t"
            "beq _081CE024\n\t"
            "b _081CE05C\n\t"
            ".align 2, 0\n\t"
            "_081CDFE4: .4byte 0x00002908\n\t"
            "_081CDFE8:\n\t"
            "cmp r4, #0\n\t"
            "beq _081CDFFC\n\t"
            "movs r1, #0xc1\n\t"
            "lsls r1, r1, #5\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "movs r1, #3\n\t"
            "bl CopyWindowToVram\n\t"
            "b _081CE00A\n\t"
            "_081CDFFC:\n\t"
            "movs r1, #0xc1\n\t"
            "lsls r1, r1, #5\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "_081CE00A:\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "bne _081CE048\n\t"
            "ldr r0, _081CE020\n\t"
            "adds r1, r6, r0\n\t"
            "ldrb r0, [r1]\n\t"
            "adds r0, #1\n\t"
            "strb r0, [r1]\n\t"
            "b _081CE05C\n\t"
            ".align 2, 0\n\t"
            "_081CE020: .4byte 0x00002908\n\t"
            "_081CE024:\n\t"
            "cmp r4, #0\n\t"
            "beq _081CE03C\n\t"
            "ldr r1, _081CE038\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "movs r1, #3\n\t"
            "bl CopyWindowToVram\n\t"
            "b _081CE048\n\t"
            ".align 2, 0\n\t"
            "_081CE038: .4byte 0x00001821\n\t"
            "_081CE03C:\n\t"
            "ldr r1, _081CE054\n\t"
            "adds r0, r6, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "_081CE048:\n\t"
            "ldr r0, _081CE058\n\t"
            "adds r1, r6, r0\n\t"
            "movs r0, #0\n\t"
            "strb r0, [r1]\n\t"
            "movs r0, #1\n\t"
            "b _081CE05E\n\t"
            ".align 2, 0\n\t"
            "_081CE054: .4byte 0x00001821\n\t"
            "_081CE058: .4byte 0x00002908\n\t"
            "_081CE05C:\n\t"
            "movs r0, #0\n\t"
            "_081CE05E:\n\t"
            "add sp, #0x1c\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            ".syntax divided");
}

void CopyUnusedConditionWindowsToVram(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    CopyWindowToVram(menu->unusedWindowId1, COPYWIN_FULL);
    CopyWindowToVram(menu->unusedWindowId2, COPYWIN_FULL);
}

static void SpriteCB_PartyPokeball(struct Sprite *sprite)
{
    if (sprite->data[0] == GetConditionGraphCurrentListIndex())
        StartSpriteAnim(sprite, CONDITION_ICON_SELECTED);
    else
        StartSpriteAnim(sprite, CONDITION_ICON_UNSELECTED);
}

void HighlightCurrentPartyIndexPokeball(struct Sprite *sprite)
{
    if (GetConditionGraphCurrentListIndex() == GetMonListCount() - 1)
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(TAG_CONDITION_BALL);
    else
        sprite->oam.paletteNum = IndexOfSpritePaletteTag(TAG_CONDITION_CANCEL);
}

void MonMarkingsCallback(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, TryGetMonMarkId());
}

void CreateMonMarkingsOrPokeballIndicators(void)
{
    struct SpriteSheet sprSheets[4];
    struct SpriteTemplate sprTemplate;
    struct SpritePalette sprPals[3];
    struct SpriteSheet sprSheet;
    struct Sprite *sprite;
    u16 i, spriteId;
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    LoadConditionSelectionIcons(sprSheets, &sprTemplate, sprPals);
    if (IsConditionMenuSearchMode() == TRUE)
    {
        // Search Mode, load markings menu
        menu->marksMenu.baseTileTag = TAG_CONDITION_MARKINGS_MENU;
        menu->marksMenu.basePaletteTag = TAG_CONDITION_MARKINGS_MENU;
        InitMonMarkingsMenu(&menu->marksMenu);
        BufferMonMarkingsMenuTiles();
        sprite = CreateMonMarkingAllCombosSprite(TAG_CONDITION_MON_MARKINGS, TAG_CONDITION_MON_MARKINGS, sPokenavMonMarkings_Pal);
        sprite->oam.priority = 3;
        sprite->x = 192;
        sprite->y = 32;
        sprite->callback = MonMarkingsCallback;
        menu->monMarksSprite = sprite;
        PokenavFillPalette(IndexOfSpritePaletteTag(TAG_CONDITION_MON_MARKINGS), 0);
    }
    else
    {
        // Party Mode, load Pokéball selection icons
        LoadSpriteSheets(sprSheets);
        Pokenav_AllocAndLoadPalettes(sprPals);

        // Add icons for occupied slots
        for (i = 0; i < GetMonListCount() - 1; i++)
        {
            spriteId = CreateSprite(&sprTemplate, 226, (i * 20) + 8, 0);
            if (spriteId != MAX_SPRITES)
            {
                menu->partyPokeballSpriteIds[i] = spriteId;
                gSprites[spriteId].data[0] = i;
                gSprites[spriteId].callback = SpriteCB_PartyPokeball;
            }
            else
            {
                menu->partyPokeballSpriteIds[i] = SPRITE_NONE;
            }
        }

        // Add icons for empty slots
        sprTemplate.tileTag = TAG_CONDITION_BALL_PLACEHOLDER;
        sprTemplate.callback = SpriteCallbackDummy;
        for (; i < PARTY_SIZE; i++)
        {
            spriteId = CreateSprite(&sprTemplate, 230, (i * 20) + 8, 0);
            if (spriteId != MAX_SPRITES)
            {
                menu->partyPokeballSpriteIds[i] = spriteId;
                gSprites[spriteId].oam.size = 0;
            }
            else
            {
                menu->partyPokeballSpriteIds[i] = SPRITE_NONE;
            }
        }

        // Add cancel icon
        sprTemplate.tileTag = TAG_CONDITION_CANCEL;
        sprTemplate.callback = HighlightCurrentPartyIndexPokeball;
        spriteId = CreateSprite(&sprTemplate, 222, (i * 20) + 8, 0);
        if (spriteId != MAX_SPRITES)
        {
            menu->partyPokeballSpriteIds[i] = spriteId;
            gSprites[spriteId].oam.shape = SPRITE_SHAPE(32x16);
            gSprites[spriteId].oam.size = SPRITE_SIZE(32x16);
        }
        else
        {
            menu->partyPokeballSpriteIds[i] = SPRITE_NONE;
        }
    }

    LoadConditionSparkle(&sprSheet, &sprPals[0]);
    LoadSpriteSheet(&sprSheet);
    sprPals[1].data = NULL;
    Pokenav_AllocAndLoadPalettes(sprPals);
}

static void FreeConditionMenuGfx(struct Pokenav_ConditionMenuGfx *menu)
{
    u8 i;

    if (IsConditionMenuSearchMode() == TRUE)
    {
        DestroySprite(menu->monMarksSprite);
        FreeSpriteTilesByTag(TAG_CONDITION_MARKINGS_MENU);
        FreeSpriteTilesByTag(TAG_CONDITION_MON_MARKINGS);
        FreeSpritePaletteByTag(TAG_CONDITION_MARKINGS_MENU);
        FreeSpritePaletteByTag(TAG_CONDITION_MON_MARKINGS);
    }
    else
    {
        for (i = 0; i < PARTY_SIZE + 1; i++)
            DestroySprite(&gSprites[menu->partyPokeballSpriteIds[i]]);

        FreeSpriteTilesByTag(TAG_CONDITION_BALL);
        FreeSpriteTilesByTag(TAG_CONDITION_CANCEL);
        FreeSpriteTilesByTag(TAG_CONDITION_BALL_PLACEHOLDER);
        FreeSpritePaletteByTag(TAG_CONDITION_BALL);
        FreeSpritePaletteByTag(TAG_CONDITION_CANCEL);
    }

    if (menu->monPicSpriteId != SPRITE_NONE)
    {
        DestroySprite(&gSprites[menu->monPicSpriteId]);
        FreeSpriteTilesByTag(TAG_CONDITION_MON);
        FreeSpritePaletteByTag(TAG_CONDITION_MON);
    }
}

void FreeConditionGraphMenuSubstruct2(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    RemoveWindow(menu->nameGenderWindowId);
    if (IsConditionMenuSearchMode() == TRUE)
    {
        RemoveWindow(menu->listIndexWindowId);
        RemoveWindow(menu->unusedWindowId1);
        RemoveWindow(menu->unusedWindowId2);
    }
    else
    {
        SetLeftHeaderSpritesInvisibility();
    }

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG0_ON | DISPCNT_OBJ_1D_MAP);
    FreeConditionMenuGfx(menu);
    SetExitVBlank();
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
}

void MonPicGfxSpriteCallback(struct Sprite *sprite)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    sprite->x = menu->monTransitionX + 38;
}

void CreateConditionMonPic(u8 id)
{
    struct SpriteTemplate sprTemplate;
    struct SpriteSheet sprSheet;
    struct SpritePalette sprPal;
    u8 spriteId;
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    if (menu->monPicSpriteId == SPRITE_NONE)
    {
        LoadConditionMonPicTemplate(&sprSheet, &sprTemplate, &sprPal);
        sprSheet.data = GetConditionMonPicGfx(id);
        sprPal.data = GetConditionMonPal(id);
        menu->monPalIndex = LoadSpritePalette(&sprPal);
        menu->monGfxTileStart = LoadSpriteSheet(&sprSheet);
        spriteId = CreateSprite(&sprTemplate, 38, 104, 0);
        menu->monPicSpriteId = spriteId;
        if (spriteId == MAX_SPRITES)
        {
            FreeSpriteTilesByTag(TAG_CONDITION_MON);
            FreeSpritePaletteByTag(TAG_CONDITION_MON);
            menu->monPicSpriteId = SPRITE_NONE;
        }
        else
        {
            menu->monPicSpriteId = spriteId;
            gSprites[menu->monPicSpriteId].callback = MonPicGfxSpriteCallback;
            menu->monGfxPtr = (void *)VRAM + BG_VRAM_SIZE + (menu->monGfxTileStart * 32);
            menu->monPalIndex = OBJ_PLTT_ID(menu->monPalIndex);
        }
    }
    else
    {
        DmaCopy16Defvars(3, GetConditionMonPicGfx(id), menu->monGfxPtr, MON_PIC_SIZE);
        LoadPalette(GetConditionMonPal(id), menu->monPalIndex, PLTT_SIZE_4BPP);
    }
}

void VBlankCB_PokenavConditionGraph(void)
{
    struct ConditionGraph *graph = GetConditionGraphPtr();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ConditionGraph_Draw(graph);
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void SetExitVBlank(void)
{
    SetPokenavVBlankCallback();
}

void ToggleGraphData(bool8 showBg)
{
    if (showBg)
        ShowBg(2);
    else
        HideBg(2);
}

void DoConditionGraphEnterTransition(void)
{
    struct ConditionGraph *graph = GetConditionGraphPtr();
    u8 id = GetConditionGraphMenuCurrentLoadIndex();

    sInitialLoadId = id;
    ConditionGraph_SetNewPositions(graph, graph->savedPositions[CONDITION_GRAPH_LOAD_MAX - 1], graph->savedPositions[id]);
    ConditionGraph_TryUpdate(graph);
}

void DoConditionGraphExitTransition(void)
{
    struct ConditionGraph *graph = GetConditionGraphPtr();

    if (IsConditionMenuSearchMode() || GetConditionGraphCurrentListIndex() != GetMonListCount() - 1)
        ConditionGraph_SetNewPositions(graph, graph->savedPositions[GetConditionGraphMenuCurrentLoadIndex()], graph->savedPositions[CONDITION_GRAPH_LOAD_MAX - 1]);
}

u8 GetMonMarkingsData(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    if (IsConditionMenuSearchMode() == 1)
        return menu->marksMenu.markings;
    else
        return 0;
}

bool32 PokenavCallback_Init_ConditionSearch(void)
{
    struct Pokenav_SearchResults *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS, sizeof(struct Pokenav_SearchResults));
    if (menu == NULL)
        return FALSE;

    menu->monList = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavMonList));
    if (menu->monList == NULL)
        return FALSE;

    menu->callback = HandleConditionSearchInput_WaitSetup;
    menu->loopedTaskId = CreateLoopedTask(GetConditionSearchLoopedTask, 1);
    menu->returnFromGraph = FALSE;
    menu->conditionDataId = sSearchMonDataIds[GetSelectedConditionSearch()];
    return TRUE;
}

bool32 PokenavCallback_Init_ReturnToMonSearchList(void)
{
    struct Pokenav_SearchResults *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS, sizeof(struct Pokenav_SearchResults));
    if (menu == NULL)
        return FALSE;

    menu->monList = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    menu->callback = HandleConditionSearchInput;
    menu->returnFromGraph = TRUE;
    menu->conditionDataId = sSearchMonDataIds[GetSelectedConditionSearch()];
    return TRUE;
}

u32 GetConditionSearchResultsCallback(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->callback(menu);
}

void FreeSearchResultSubstruct1(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    if (!menu->saveResultsList)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
}

static bool32 HandleConditionSearchInput_WaitSetup(struct Pokenav_SearchResults *menu)
{
    if (!IsLoopedTaskActive(menu->loopedTaskId))
        menu->callback = HandleConditionSearchInput;
    return FALSE;
}

__attribute__((naked)) u32 HandleConditionSearchInput(struct Pokenav_SearchResults *menu)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "adds r4, r0, #0\n\t"
            "ldr r2, _081CE778\n\t"
            "ldrh r1, [r2, #0x30]\n\t"
            "movs r0, #0x40\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "beq _081CE77C\n\t"
            "movs r0, #1\n\t"
            "b _081CE7DA\n\t"
            ".align 2, 0\n\t"
            "_081CE778: .4byte gMain\n\t"
            "_081CE77C:\n\t"
            "movs r0, #0x80\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "beq _081CE788\n\t"
            "movs r0, #2\n\t"
            "b _081CE7DA\n\t"
            "_081CE788:\n\t"
            "ldrh r1, [r2, #0x2e]\n\t"
            "movs r0, #0x20\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "beq _081CE796\n\t"
            "movs r0, #3\n\t"
            "b _081CE7DA\n\t"
            "_081CE796:\n\t"
            "movs r0, #0x10\n\t"
            "ands r0, r1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r2, #0\n\t"
            "beq _081CE7A6\n\t"
            "movs r0, #4\n\t"
            "b _081CE7DA\n\t"
            "_081CE7A6:\n\t"
            "movs r0, #2\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "beq _081CE7BC\n\t"
            "str r2, [r4, #0x1c]\n\t"
            "ldr r0, _081CE7B8\n\t"
            "str r0, [r4]\n\t"
            "movs r0, #5\n\t"
            "b _081CE7DA\n\t"
            ".align 2, 0\n\t"
            "_081CE7B8: .4byte ReturnToConditionSearchList + 1\n\t"
            "_081CE7BC:\n\t"
            "movs r5, #1\n\t"
            "adds r0, r5, #0\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "bne _081CE7CA\n\t"
            "movs r0, #0\n\t"
            "b _081CE7DA\n\t"
            "_081CE7CA:\n\t"
            "bl PokenavList_GetSelectedIndex\n\t"
            "ldr r1, [r4, #0x20]\n\t"
            "strh r0, [r1, #2]\n\t"
            "str r5, [r4, #0x1c]\n\t"
            "ldr r0, _081CE7E0\n\t"
            "str r0, [r4]\n\t"
            "movs r0, #6\n\t"
            "_081CE7DA:\n\t"
            "pop {r4, r5}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            "_081CE7E0: .4byte OpenConditionGraphFromSearchList + 1\n\t"
            ".syntax divided");
}

static u32 ReturnToConditionSearchList(struct Pokenav_SearchResults *menu)
{
    return POKENAV_CONDITION_SEARCH_MENU;
}

static u32 OpenConditionGraphFromSearchList(struct Pokenav_SearchResults *menu)
{
    return POKENAV_CONDITION_GRAPH_SEARCH;
}

static u32 GetReturningFromGraph(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->returnFromGraph;
}

static struct PokenavMonListItem * GetSearchResultsMonDataList(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->monList->monData;
}

static u16 GetSearchResultsMonListCount(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->monList->listCount;
}

static s32 GetSearchResultsSelectedMonRank(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 i = PokenavList_GetSelectedIndex();
    return menu->monList->monData[i].data;
}

static u16 GetSearchResultsCurrentListIndex(void)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    return menu->monList->currIndex;
}

static u32 GetConditionSearchLoopedTask(s32 state)
{
    return sConditionSearchLoopedTaskFuncs[state](state);
}

static u32 BuildPartyMonSearchResults(s32 state)
{
    s32 i;
    struct PokenavMonListItem item;
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);

    menu->monList->listCount = 0;
    menu->monList->currIndex = 0;
    item.boxId = TOTAL_BOXES_COUNT;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *pokemon = &gPlayerParty[i];
        if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
            return LT_INC_AND_CONTINUE;
        if (!GetMonData(pokemon, MON_DATA_SANITY_IS_EGG))
        {
            item.monId = i;
            item.data = GetMonData(pokemon, menu->conditionDataId);
            InsertMonListItem(menu, &item);
        }
    }

    return LT_INC_AND_CONTINUE;
}

static u32 InitBoxMonSearchResults(s32 state)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    menu->monId = 0;
    menu->boxId = 0;
    return LT_INC_AND_CONTINUE;
}

static u32 BuildBoxMonSearchResults(s32 state)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 boxId = menu->boxId;
    s32 monId = menu->monId;
    s32 boxCount = 0;
    struct PokenavMonListItem item;

    while (boxId < TOTAL_BOXES_COUNT)
    {
        while (monId < IN_BOX_COUNT)
        {
            if (CheckBoxMonSanityAt(boxId, monId))
            {
                item.boxId = boxId;
                item.monId = monId;
                item.data = GetBoxMonDataAt(boxId, monId, menu->conditionDataId);
                InsertMonListItem(menu, &item);
            }
            boxCount++;
            monId++;
            if (boxCount > TOTAL_BOXES_COUNT)
            {
                menu->boxId = boxId;
                menu->monId = monId;
                return LT_CONTINUE;
            }
        }
        monId = 0;
        boxId++;
    }

    return LT_INC_AND_CONTINUE;
}

static u32 ConvertConditionsToListRanks(s32 state)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    s32 listCount = menu->monList->listCount;
    s32 prevCondition = menu->monList->monData[0].data;
    s32 i;
    menu->monList->monData[0].data = 1;
    for (i = 1; i < listCount; i++)
    {
        if (menu->monList->monData[i].data == prevCondition)
        {
            // Same condition value as prev, share rank
            menu->monList->monData[i].data = menu->monList->monData[i - 1].data;
        }
        else
        {
            prevCondition = menu->monList->monData[i].data;
            menu->monList->monData[i].data = i + 1;
        }
    }
    menu->returnFromGraph = TRUE;
    return LT_FINISH;
}

static void InsertMonListItem(struct Pokenav_SearchResults *menu, struct PokenavMonListItem *item)
{
    u32 left = 0;
    u32 right = menu->monList->listCount;
    u32 insertionIdx = left + (right - left) / 2;

    while (right != insertionIdx)
    {
        if (item->data > menu->monList->monData[insertionIdx].data)
            right = insertionIdx;
        else
            left = insertionIdx + 1;
        insertionIdx = left + (right - left) / 2;
    }
    for (right = menu->monList->listCount; right > insertionIdx; right--)
        menu->monList->monData[right] = menu->monList->monData[right - 1];
    menu->monList->monData[insertionIdx] = *item;
    menu->monList->listCount++;
}

bool32 OpenConditionSearchResults(void)
{
    struct Pokenav_SearchResultsGfx *gfx = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX, sizeof(struct Pokenav_SearchResultsGfx));
    if (gfx == NULL)
        return FALSE;
    gfx->loopedTaskId = CreateLoopedTask(LoopedTask_OpenConditionSearchResults, 1);
    gfx->callback = GetSearchResultCurrentLoopedTaskActive;
    gfx->fromGraph = FALSE;
    return TRUE;
}

bool32 OpenConditionSearchListFromGraph(void)
{
    struct Pokenav_SearchResultsGfx *gfx = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX, sizeof(struct Pokenav_SearchResultsGfx));
    if (gfx == NULL)
        return FALSE;
    gfx->loopedTaskId = CreateLoopedTask(LoopedTask_OpenConditionSearchResults, 1);
    gfx->callback = GetSearchResultCurrentLoopedTaskActive;
    gfx->fromGraph = TRUE;
    return TRUE;
}

void CreateSearchResultsLoopedTask(s32 idx)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    gfx->loopedTaskId = CreateLoopedTask(sSearchResultLoopTaskFuncs[idx], 1);
    gfx->callback = GetSearchResultCurrentLoopedTaskActive;
}

#ifndef NONMATCHING
// Verified: agbcc -O2 loads the substruct pointer differently, so the
// byte-exact naked asm stays the default.
__attribute__((naked)) bool32 IsRibbonsMonListLoopedTaskActive(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {lr}\n\t"
            "movs r0, #8\n\t"
            "bl GetSubstructPtr\n\t"
            "ldr r0, [r0]\n\t"
            "bl _call_via_r0\n\t"
            "pop {r1}\n\t"
            ".syntax divided");
}
#else
bool32 IsRibbonsMonListLoopedTaskActive(void)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    return gfx->callback();
}
#endif


__attribute__((naked)) u32 sub_081CEB14(s32 state)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            ".syntax divided");
}

bool32 GetSearchResultCurrentLoopedTaskActive(void)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    return IsLoopedTaskActive(gfx->loopedTaskId);
}

void FreeSearchResultSubstruct2(void)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    DestroyPokenavList();
    RemoveWindow(gfx->winid);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
}

__attribute__((naked)) u32 LoopedTask_OpenConditionSearchResults(s32 state)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "sub sp, #4\n\t"
            "adds r4, r0, #0\n\t"
            "movs r0, #8\n\t"
            "bl GetSubstructPtr\n\t"
            "adds r5, r0, #0\n\t"
            "cmp r4, #5\n\t"
            "bls _081CEB60\n\t"
            "b _081CECA2\n\t"
            "_081CEB60:\n\t"
            "lsls r0, r4, #2\n\t"
            "ldr r1, _081CEB6C\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r0, [r0]\n\t"
            "mov pc, r0\n\t"
            ".align 2, 0\n\t"
            "_081CEB6C: .4byte _081CEB70\n\t"
            "_081CEB70: @ jump table\n\t"
            ".4byte _081CEB88 @ case 0\n\t"
            ".4byte _081CEBE0 @ case 1\n\t"
            ".4byte _081CEBF4 @ case 2\n\t"
            ".4byte _081CEC14 @ case 3\n\t"
            ".4byte _081CEC2A @ case 4\n\t"
            ".4byte _081CEC8E @ case 5\n\t"
            "_081CEB88:\n\t"
            "ldr r0, _081CEBD0\n\t"
            "movs r1, #2\n\t"
            "bl InitBgTemplates\n\t"
            "ldr r1, _081CEBD4\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #1\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0\n\t"
            "bl DecompressAndCopyTileDataToVram\n\t"
            "adds r1, r5, #0\n\t"
            "adds r1, #0x10\n\t"
            "movs r0, #1\n\t"
            "bl SetBgTilemapBuffer\n\t"
            "ldr r1, _081CEBD8\n\t"
            "movs r0, #1\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0\n\t"
            "bl CopyToBgTilemapBuffer\n\t"
            "movs r0, #1\n\t"
            "bl CopyBgTilemapBufferToVram\n\t"
            "ldr r0, _081CEBDC\n\t"
            "movs r1, #0x10\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "movs r0, #1\n\t"
            "bl CopyBgTilemapBufferToVram\n\t"
            "_081CEBCC:\n\t"
            "movs r0, #0\n\t"
            "b _081CECA4\n\t"
            ".align 2, 0\n\t"
            "_081CEBD0: .4byte sConditionSearchResultBgTemplates\n\t"
            "_081CEBD4: .4byte sConditionSearchResultTiles\n\t"
            "_081CEBD8: .4byte sConditionSearchResultTilemap\n\t"
            "_081CEBDC: .4byte sConditionSearchResultFramePal\n\t"
            "_081CEBE0:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081CEC9E\n\t"
            "bl GetReturningFromGraph\n\t"
            "cmp r0, #0\n\t"
            "beq _081CEC9E\n\t"
            "b _081CEBCC\n\t"
            "_081CEBF4:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081CEC9E\n\t"
            "ldr r0, _081CEC10\n\t"
            "movs r1, #0x20\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "bl CreateSearchResultsList\n\t"
            "b _081CEBCC\n\t"
            ".align 2, 0\n\t"
            "_081CEC10: .4byte sListBg_Pal\n\t"
            "_081CEC14:\n\t"
            "bl IsCreatePokenavListTaskActive\n\t"
            "cmp r0, #0\n\t"
            "bne _081CEC9E\n\t"
            "adds r0, r5, #0\n\t"
            "bl AddSearchResultListMenuWindow\n\t"
            "movs r0, #3\n\t"
            "bl PrintHelpBarText\n\t"
            "b _081CEBCC\n\t"
            "_081CEC2A:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081CEC9E\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgX\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgY\n\t"
            "movs r0, #1\n\t"
            "bl ShowBg\n\t"
            "movs r0, #2\n\t"
            "bl ShowBg\n\t"
            "movs r0, #3\n\t"
            "bl HideBg\n\t"
            "ldr r0, [r5, #0xc]\n\t"
            "cmp r0, #0\n\t"
            "bne _081CEC86\n\t"
            "bl GetSelectedConditionSearch\n\t"
            "adds r4, r0, #0\n\t"
            "adds r4, #8\n\t"
            "lsls r4, r4, #0x18\n\t"
            "lsrs r4, r4, #0x18\n\t"
            "adds r0, r4, #0\n\t"
            "bl LoadLeftHeaderGfxForIndex\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "bl ShowLeftHeaderGfx\n\t"
            "movs r0, #1\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "bl ShowLeftHeaderGfx\n\t"
            "_081CEC86:\n\t"
            "movs r0, #1\n\t"
            "bl PokenavFadeScreen\n\t"
            "b _081CEBCC\n\t"
            "_081CEC8E:\n\t"
            "bl IsPaletteFadeActive\n\t"
            "cmp r0, #0\n\t"
            "bne _081CEC9E\n\t"
            "bl AreLeftHeaderSpritesMoving\n\t"
            "cmp r0, #0\n\t"
            "beq _081CECA2\n\t"
            "_081CEC9E:\n\t"
            "movs r0, #2\n\t"
            "b _081CECA4\n\t"
            "_081CECA2:\n\t"
            "movs r0, #4\n\t"
            "_081CECA4:\n\t"
            "add sp, #4\n\t"
            "pop {r4, r5}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".syntax divided");
}

static u32 LoopedTask_MoveSearchListCursorUp(s32 state)
{
    struct Pokenav_SearchResultsGfx *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        switch (PokenavList_MoveCursorUp())
        {
        case 0:
            return LT_FINISH;
        case 1:
            return LT_SET_STATE(2);
        case 2:
        default:
            return LT_INC_AND_PAUSE;
        }
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(ptr);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveSearchListCursorDown(s32 state)
{
    struct Pokenav_SearchResultsGfx *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        switch (PokenavList_MoveCursorDown())
        {
        case 0:
            return LT_FINISH;
        case 1:
            return LT_SET_STATE(2);
        case 2:
        default:
            return LT_INC_AND_PAUSE;
        }
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(ptr);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveSearchListPageUp(s32 state)
{
    struct Pokenav_SearchResultsGfx *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        switch (PokenavList_PageUp())
        {
        case 0:
            return LT_FINISH;
        case 1:
            return LT_SET_STATE(2);
        case 2:
        default:
            return LT_INC_AND_PAUSE;
        }
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(ptr);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_MoveSearchListPageDown(s32 state)
{
    struct Pokenav_SearchResultsGfx *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        switch (PokenavList_PageDown())
        {
        case 0:
            return LT_FINISH;
        case 1:
            return LT_SET_STATE(2);
        case 2:
        default:
            return LT_INC_AND_PAUSE;
        }
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        PrintSearchResultListMenuItems(ptr);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_ExitConditionSearchMenu(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        SetLeftHeaderSpritesInvisibility();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_SelectSearchResult(s32 state)
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
        break;
    }
    return LT_FINISH;
}

static void AddSearchResultListMenuWindow(struct Pokenav_SearchResultsGfx *gfx)
{
    gfx->winid = AddWindow(&sSearchResultListMenuWindowTemplate);
    PutWindowTilemap(gfx->winid);
    CopyWindowToVram(gfx->winid, COPYWIN_MAP);
    PrintSearchResultListMenuItems(gfx);
}

#ifndef NONMATCHING
// JP naked asm: byte-exact search-result list row printer; C form differs,
// so asm stays default.
__attribute__((naked)) void PrintSearchResultListMenuItems(struct Pokenav_SearchResultsGfx *gfx)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, lr}\n\t"
            "sub sp, #0xc\n\t"
            "adds r6, r0, #0\n\t"
            "bl GetSearchResultsSelectedMonRank\n\t"
            "adds r5, r0, #0\n\t"
            "bl DynamicPlaceholderTextUtil_Reset\n\t"
            "ldr r4, _081CEF40\n\t"
            "movs r0, #0\n\t"
            "adds r1, r4, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r5, #0\n\t"
            "movs r2, #1\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "ldr r4, _081CEF44\n\t"
            "ldr r1, _081CEF48\n\t"
            "adds r0, r4, #0\n\t"
            "bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
            "ldrb r0, [r6, #8]\n\t"
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
            "ldrb r0, [r6, #8]\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "add sp, #0xc\n\t"
            "pop {r4, r5, r6}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081CEF40: .4byte gStringVar1\n\t"
            "_081CEF44: .4byte gStringVar2\n\t"
            "_081CEF48: .4byte 0x085CB81B\n\t"
            ".syntax divided");
}
#else
void PrintSearchResultListMenuItems(struct Pokenav_SearchResultsGfx *gfx)
{
    s32 rank = GetSearchResultsSelectedMonRank();
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    ConvertIntToDecimalStringN(gStringVar1, rank, STR_CONV_MODE_RIGHT_ALIGN, 3);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar2, gText_SearchResultRank);
    AddTextPrinterParameterized(gfx->winid, FONT_NORMAL, gStringVar2, 0, 2, 0xFF, NULL);
    CopyWindowToVram(gfx->winid, COPYWIN_GFX);
}
#endif


#ifndef NONMATCHING
// JP naked asm: builds the search-results list template on the stack; C form
// differs, so asm stays default.
__attribute__((naked)) void CreateSearchResultsList(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, lr}\n\t"
            "sub sp, #0x18\n\t"
            "bl GetSearchResultsMonDataList\n\t"
            "str r0, [sp]\n\t"
            "bl GetSearchResultsMonListCount\n\t"
            "mov r1, sp\n\t"
            "movs r4, #0\n\t"
            "strh r0, [r1, #4]\n\t"
            "movs r0, #4\n\t"
            "strb r0, [r1, #8]\n\t"
            "bl GetSearchResultsCurrentListIndex\n\t"
            "mov r1, sp\n\t"
            "strh r0, [r1, #6]\n\t"
            "movs r0, #0xe\n\t"
            "strb r0, [r1, #9]\n\t"
            "movs r0, #0xf\n\t"
            "strb r0, [r1, #0xa]\n\t"
            "movs r0, #1\n\t"
            "strb r0, [r1, #0xb]\n\t"
            "movs r0, #8\n\t"
            "strb r0, [r1, #0xc]\n\t"
            "movs r0, #2\n\t"
            "strb r0, [r1, #0xd]\n\t"
            "ldr r0, _081CEF98\n\t"
            "str r0, [sp, #0x10]\n\t"
            "str r4, [sp, #0x14]\n\t"
            "ldr r0, _081CEF9C\n\t"
            "movs r2, #0\n\t"
            "bl CreatePokenavList\n\t"
            "add sp, #0x18\n\t"
            "pop {r4}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081CEF98: .4byte BufferSearchMonListItem + 1\n\t"
            "_081CEF9C: .4byte 0x085F5BA0\n\t"
            ".syntax divided");
}
#else
void CreateSearchResultsList(void)
{
    struct PokenavListTemplate template;

    template.list = GetSearchResultsMonDataList();
    template.count = GetSearchResultsMonListCount();
    template.startIndex = GetSearchResultsCurrentListIndex();
    template.itemSize = 4;
    template.item_X = 0xE;
    template.windowWidth = 0xF;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 2;
    template.bufferItemFunc = BufferSearchMonListItem;
    template.iconDrawFunc = NULL;
    CreatePokenavList(sSearchResultsBgTemplates, &template, 0);
}
#endif


__attribute__((naked)) void BufferSearchMonListItem(struct PokenavMonListItem *item, u8 *dest)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, r8\n\t"
            "push {r7}\n\t"
            "adds r4, r0, #0\n\t"
            "mov r8, r1\n\t"
            "bl DynamicPlaceholderTextUtil_Reset\n\t"
            "ldrb r0, [r4]\n\t"
            "cmp r0, #0xe\n\t"
            "bne _081CEFE8\n\t"
            "ldrb r1, [r4, #1]\n\t"
            "movs r0, #0x64\n\t"
            "adds r4, r1, #0\n\t"
            "muls r4, r0, r4\n\t"
            "ldr r0, _081CEFE0\n\t"
            "adds r4, r4, r0\n\t"
            "adds r0, r4, #0\n\t"
            "bl GetMonGender\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r7, r0, #0x18\n\t"
            "adds r0, r4, #0\n\t"
            "bl GetLevelFromMonExp\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r5, r0, #0x18\n\t"
            "ldr r2, _081CEFE4\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #2\n\t"
            "bl GetMonData3\n\t"
            "b _081CF00E\n\t"
            ".align 2, 0\n\t"
            "_081CEFE0: .4byte gPlayerParty\n\t"
            "_081CEFE4: .4byte gStringVar3\n\t"
            "_081CEFE8:\n\t"
            "ldrb r0, [r4]\n\t"
            "ldrb r1, [r4, #1]\n\t"
            "bl GetBoxedMonPtr\n\t"
            "adds r4, r0, #0\n\t"
            "bl GetBoxMonGender\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r7, r0, #0x18\n\t"
            "adds r0, r4, #0\n\t"
            "bl GetLevelFromBoxMonExp\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r5, r0, #0x18\n\t"
            "ldr r2, _081CF060\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #2\n\t"
            "bl GetBoxMonData\n\t"
            "_081CF00E:\n\t"
            "ldr r4, _081CF060\n\t"
            "adds r0, r4, #0\n\t"
            "bl StringGet_Nickname\n\t"
            "ldr r6, _081CF064\n\t"
            "adds r0, r6, #0\n\t"
            "adds r1, r4, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #5\n\t"
            "bl StringCopyPadded\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r5, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "ldr r5, _081CF068\n\t"
            "adds r0, r5, #0\n\t"
            "adds r1, r4, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl StringCopyPadded\n\t"
            "movs r0, #0\n\t"
            "adds r1, r6, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "movs r0, #1\n\t"
            "adds r1, r5, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "cmp r7, #0xfe\n\t"
            "beq _081CF070\n\t"
            "cmp r7, #0xfe\n\t"
            "bgt _081CF078\n\t"
            "cmp r7, #0\n\t"
            "bne _081CF078\n\t"
            "ldr r1, _081CF06C\n\t"
            "b _081CF07A\n\t"
            ".align 2, 0\n\t"
            "_081CF060: .4byte gStringVar3\n\t"
            "_081CF064: .4byte gStringVar1\n\t"
            "_081CF068: .4byte gStringVar2\n\t"
            "_081CF06C: .4byte 0x085CB7D6\n\t"
            "_081CF070:\n\t"
            "ldr r1, _081CF074\n\t"
            "b _081CF07A\n\t"
            ".align 2, 0\n\t"
            "_081CF074: .4byte 0x085CB7EA\n\t"
            "_081CF078:\n\t"
            "ldr r1, _081CF08C\n\t"
            "_081CF07A:\n\t"
            "mov r0, r8\n\t"
            "bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081CF08C: .4byte 0x085CB7FE\n\t"
            ".syntax divided");
}

bool32 PokenavCallback_Init_MonRibbonList(void)
{
    struct Pokenav_RibbonsMonList *list = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST, sizeof(struct Pokenav_RibbonsMonList));
    if (list == NULL)
        return FALSE;

    list->monList = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavMonList));
    if (list->monList == NULL)
        return FALSE;

    list->callback = HandleRibbonsMonListInput_WaitListInit;
    list->loopedTaskId = CreateLoopedTask(GetMonRibbonListLoopTaskFunc, 1);
    list->changeBgs = 0;
    return TRUE;
}

bool32 PokenavCallback_Init_RibbonsMonListFromSummary(void)
{
    struct Pokenav_RibbonsMonList *list = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST, sizeof(struct Pokenav_RibbonsMonList));
    if (list == NULL)
        return FALSE;

    list->monList = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    list->callback = HandleRibbonsMonListInput;
    list->changeBgs = 1;
    return TRUE;
}

u32 GetRibbonsMonListCallback(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->callback(list);
}

void FreeRibbonsMonList(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    if (!list->saveMonList)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
}

static u32 HandleRibbonsMonListInput_WaitListInit(struct Pokenav_RibbonsMonList *list)
{
    if (!IsLoopedTaskActive(list->loopedTaskId))
        list->callback = HandleRibbonsMonListInput;
    return 0;
}

__attribute__((naked)) u32 HandleRibbonsMonListInput(struct Pokenav_RibbonsMonList *list)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "adds r4, r0, #0\n\t"
            "ldr r2, _081CF170\n\t"
            "ldrh r1, [r2, #0x30]\n\t"
            "movs r0, #0x40\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "beq _081CF174\n\t"
            "movs r0, #1\n\t"
            "b _081CF1D2\n\t"
            ".align 2, 0\n\t"
            "_081CF170: .4byte gMain\n\t"
            "_081CF174:\n\t"
            "movs r0, #0x80\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "beq _081CF180\n\t"
            "movs r0, #2\n\t"
            "b _081CF1D2\n\t"
            "_081CF180:\n\t"
            "ldrh r1, [r2, #0x2e]\n\t"
            "movs r0, #0x20\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "beq _081CF18E\n\t"
            "movs r0, #3\n\t"
            "b _081CF1D2\n\t"
            "_081CF18E:\n\t"
            "movs r0, #0x10\n\t"
            "ands r0, r1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r2, #0\n\t"
            "beq _081CF19E\n\t"
            "movs r0, #4\n\t"
            "b _081CF1D2\n\t"
            "_081CF19E:\n\t"
            "movs r0, #2\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "beq _081CF1B4\n\t"
            "str r2, [r4, #0x18]\n\t"
            "ldr r0, _081CF1B0\n\t"
            "str r0, [r4]\n\t"
            "movs r0, #5\n\t"
            "b _081CF1D2\n\t"
            ".align 2, 0\n\t"
            "_081CF1B0: .4byte RibbonsMonMenu_ReturnToMainMenu + 1\n\t"
            "_081CF1B4:\n\t"
            "movs r5, #1\n\t"
            "adds r0, r5, #0\n\t"
            "ands r0, r1\n\t"
            "cmp r0, #0\n\t"
            "bne _081CF1C2\n\t"
            "movs r0, #0\n\t"
            "b _081CF1D2\n\t"
            "_081CF1C2:\n\t"
            "bl PokenavList_GetSelectedIndex\n\t"
            "ldr r1, [r4, #0x1c]\n\t"
            "strh r0, [r1, #2]\n\t"
            "str r5, [r4, #0x18]\n\t"
            "ldr r0, _081CF1D8\n\t"
            "str r0, [r4]\n\t"
            "movs r0, #6\n\t"
            "_081CF1D2:\n\t"
            "pop {r4, r5}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            "_081CF1D8: .4byte RibbonsMonMenu_ToSummaryScreen + 1\n\t"
            ".syntax divided");
}

static u32 RibbonsMonMenu_ReturnToMainMenu(struct Pokenav_RibbonsMonList *list)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_RIBBONS;
}

static u32 RibbonsMonMenu_ToSummaryScreen(struct Pokenav_RibbonsMonList *list)
{
    return POKENAV_RIBBONS_SUMMARY_SCREEN;
}

static u32 UpdateMonListBgs(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->changeBgs;
}

static struct PokenavMonListItem *GetMonRibbonMonListData(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->monList->monData;
}

static s32 GetRibbonsMonListCount(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->monList->listCount;
}

static s32 UNUSED GetMonRibbonSelectedMonData(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    s32 idx = PokenavList_GetSelectedIndex();
    return list->monList->monData[idx].data;
}

static s32 GetRibbonListMenuCurrIndex(void)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    return list->monList->currIndex;
}

static u32 GetMonRibbonListLoopTaskFunc(s32 state)
{
    return sMonRibbonListLoopTaskFuncs[state](state);
}

static u32 BuildPartyMonRibbonList(s32 state)
{
    s32 i;
    struct PokenavMonListItem item;
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);

    list->monList->listCount = 0;
    list->monList->currIndex = 0;
    item.boxId = TOTAL_BOXES_COUNT;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *pokemon = &gPlayerParty[i];
        if (!GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES))
            return LT_INC_AND_CONTINUE;
        if (!GetMonData(pokemon, MON_DATA_SANITY_IS_EGG) && !GetMonData(pokemon, MON_DATA_SANITY_IS_BAD_EGG))
        {
            u32 ribbonCount = GetMonData(pokemon, MON_DATA_RIBBON_COUNT);
            if (ribbonCount != 0)
            {
                item.monId = i;
                item.data = ribbonCount;
                sub_081CF3C0(list, &item);
            }
        }
    }

    return LT_INC_AND_CONTINUE;
}

static u32 InitBoxMonRibbonList(s32 state)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    list->monId = 0;
    list->boxId = 0;
    return LT_INC_AND_CONTINUE;
}

static u32 BuildBoxMonRibbonList(s32 state)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    s32 boxId = list->boxId;
    s32 monId = list->monId;
    s32 boxCount = 0;
    struct PokenavMonListItem item;

    while (boxId < TOTAL_BOXES_COUNT)
    {
        while (monId < IN_BOX_COUNT)
        {
            if (CheckBoxMonSanityAt(boxId, monId))
            {
                u32 ribbonCount = GetBoxMonDataAt(boxId, monId, MON_DATA_RIBBON_COUNT);
                if (ribbonCount != 0)
                {
                    item.boxId = boxId;
                    item.monId = monId;
                    item.data = ribbonCount;
                    sub_081CF3C0(list, &item);
                }
            }
            boxCount++;
            monId++;
            if (boxCount > TOTAL_BOXES_COUNT)
            {
                list->boxId = boxId;
                list->monId = monId;
                return LT_CONTINUE;
            }
        }
        monId = 0;
        boxId++;
    }

    list->changeBgs = 1;
    return LT_FINISH;
}

__attribute__((naked)) void sub_081CF3C0(struct Pokenav_SearchResults *menu, struct PokenavMonListItem *item)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "adds r5, r0, #0\n\t"
            "adds r7, r1, #0\n\t"
            "movs r1, #0\n\t"
            "ldr r0, [r5, #0x1c]\n\t"
            "ldrh r2, [r0]\n\t"
            "lsrs r3, r2, #1\n\t"
            "cmp r2, r3\n\t"
            "beq _081CF3F0\n\t"
            "adds r6, r0, #0\n\t"
            "ldrh r4, [r7, #2]\n\t"
            "_081CF3D6:\n\t"
            "lsls r0, r3, #2\n\t"
            "adds r0, r6, r0\n\t"
            "ldrh r0, [r0, #6]\n\t"
            "cmp r4, r0\n\t"
            "bls _081CF3E4\n\t"
            "adds r2, r3, #0\n\t"
            "b _081CF3E6\n\t"
            "_081CF3E4:\n\t"
            "adds r1, r3, #1\n\t"
            "_081CF3E6:\n\t"
            "subs r0, r2, r1\n\t"
            "lsrs r0, r0, #1\n\t"
            "adds r3, r1, r0\n\t"
            "cmp r2, r3\n\t"
            "bne _081CF3D6\n\t"
            "_081CF3F0:\n\t"
            "ldr r0, [r5, #0x1c]\n\t"
            "ldrh r2, [r0]\n\t"
            "lsls r6, r3, #2\n\t"
            "cmp r2, r3\n\t"
            "bls _081CF414\n\t"
            "lsls r0, r2, #2\n\t"
            "subs r4, r0, #4\n\t"
            "_081CF3FE:\n\t"
            "ldr r0, [r5, #0x1c]\n\t"
            "lsls r1, r2, #2\n\t"
            "adds r0, #4\n\t"
            "adds r1, r0, r1\n\t"
            "adds r0, r0, r4\n\t"
            "ldr r0, [r0]\n\t"
            "str r0, [r1]\n\t"
            "subs r4, #4\n\t"
            "subs r2, #1\n\t"
            "cmp r2, r3\n\t"
            "bhi _081CF3FE\n\t"
            "_081CF414:\n\t"
            "ldr r0, [r5, #0x1c]\n\t"
            "adds r0, #4\n\t"
            "adds r0, r0, r6\n\t"
            "ldr r1, [r7]\n\t"
            "str r1, [r0]\n\t"
            "ldr r1, [r5, #0x1c]\n\t"
            "ldrh r0, [r1]\n\t"
            "adds r0, #1\n\t"
            "strh r0, [r1]\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".syntax divided");
}

static bool32 UNUSED PlayerHasRibbonsMon(void)
{
    s32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (!GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES))
            continue;
        if (GetMonData(mon, MON_DATA_SANITY_IS_EGG))
            continue;
        if (GetMonData(mon, MON_DATA_RIBBONS))
            return TRUE;
    }

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            if (!CheckBoxMonSanityAt(i, j))
                continue;
            if (GetBoxMonDataAt(i, j, MON_DATA_RIBBONS))
                return TRUE;
        }
    }

    return FALSE;
}

bool32 OpenRibbonsMonList(void)
{
    struct Pokenav_RibbonsMonMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU, sizeof(struct Pokenav_RibbonsMonMenu));
    if (menu == NULL)
        return FALSE;
    menu->loopedTaskId = CreateLoopedTask(LoopedTask_OpenRibbonsMonList, 1);
    menu->callback = GetRibbonsMonCurrentLoopedTaskActive;
    menu->fromSummary = FALSE;
    return TRUE;
}

bool32 OpenRibbonsMonListFromRibbonsSummary(void)
{
    struct Pokenav_RibbonsMonMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU, sizeof(struct Pokenav_RibbonsMonMenu));
    if (menu == NULL)
        return FALSE;
    menu->loopedTaskId = CreateLoopedTask(LoopedTask_OpenRibbonsMonList, 1);
    menu->callback = GetRibbonsMonCurrentLoopedTaskActive;
    menu->fromSummary = TRUE;
    return TRUE;
}

void CreateRibbonsMonListLoopedTask(s32 idx)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    menu->loopedTaskId = CreateLoopedTask(sRibbonsMonMenuLoopTaskFuncs[idx], 1);
    menu->callback = GetRibbonsMonCurrentLoopedTaskActive;
}

#ifndef NONMATCHING
// Verified: agbcc -O2 loads the menu pointer differently, so the byte-exact
// naked asm stays the default.
__attribute__((naked)) bool32 IsRibbonsSummaryLoopedTaskActive(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {lr}\n\t"
            "movs r0, #0xa\n\t"
            "bl GetSubstructPtr\n\t"
            "ldr r0, [r0]\n\t"
            "bl _call_via_r0\n\t"
            "pop {r1}\n\t"
            ".syntax divided");
}
#else
bool32 IsRibbonsSummaryLoopedTaskActive(void)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    return menu->callback();
}
#endif


__attribute__((naked)) u32 sub_081CF554(s32 state)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            ".syntax divided");
}

bool32 GetRibbonsMonCurrentLoopedTaskActive(void)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    return IsLoopedTaskActive(menu->loopedTaskId);
}

void FreeRibbonsMonMenu(void)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    DestroyPokenavList();
    RemoveWindow(menu->winid);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
}

__attribute__((naked)) u32 LoopedTask_OpenRibbonsMonList(s32 state)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "sub sp, #4\n\t"
            "adds r4, r0, #0\n\t"
            "movs r0, #0xa\n\t"
            "bl GetSubstructPtr\n\t"
            "adds r5, r0, #0\n\t"
            "cmp r4, #5\n\t"
            "bls _081CF5A0\n\t"
            "b _081CF6C6\n\t"
            "_081CF5A0:\n\t"
            "lsls r0, r4, #2\n\t"
            "ldr r1, _081CF5AC\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r0, [r0]\n\t"
            "mov pc, r0\n\t"
            ".align 2, 0\n\t"
            "_081CF5AC: .4byte _081CF5B0\n\t"
            "_081CF5B0: @ jump table\n\t"
            ".4byte _081CF5C8 @ case 0\n\t"
            ".4byte _081CF61C @ case 1\n\t"
            ".4byte _081CF64A @ case 2\n\t"
            ".4byte _081CF668 @ case 3\n\t"
            ".4byte _081CF678 @ case 4\n\t"
            ".4byte _081CF6B2 @ case 5\n\t"
            "_081CF5C8:\n\t"
            "ldr r0, _081CF60C\n\t"
            "movs r1, #2\n\t"
            "bl InitBgTemplates\n\t"
            "ldr r1, _081CF610\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #1\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0\n\t"
            "bl DecompressAndCopyTileDataToVram\n\t"
            "adds r1, r5, #0\n\t"
            "adds r1, #0x10\n\t"
            "movs r0, #1\n\t"
            "bl SetBgTilemapBuffer\n\t"
            "ldr r1, _081CF614\n\t"
            "movs r0, #1\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0\n\t"
            "bl CopyToBgTilemapBuffer\n\t"
            "ldr r0, _081CF618\n\t"
            "movs r1, #0x10\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "movs r0, #1\n\t"
            "bl CopyBgTilemapBufferToVram\n\t"
            "_081CF606:\n\t"
            "movs r0, #0\n\t"
            "b _081CF6C8\n\t"
            ".align 2, 0\n\t"
            "_081CF60C: .4byte sMonRibbonListBgTemplates\n\t"
            "_081CF610: .4byte sMonRibbonListFrameTiles\n\t"
            "_081CF614: .4byte sMonRibbonListFrameTilemap\n\t"
            "_081CF618: .4byte sMonRibbonListFramePal\n\t"
            "_081CF61C:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081CF6C2\n\t"
            "bl UpdateMonListBgs\n\t"
            "cmp r0, #0\n\t"
            "beq _081CF6C2\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgX\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgY\n\t"
            "movs r0, #1\n\t"
            "bl ShowBg\n\t"
            "b _081CF606\n\t"
            "_081CF64A:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081CF6C2\n\t"
            "ldr r0, _081CF664\n\t"
            "movs r1, #0x20\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "bl CreateRibbonMonsList\n\t"
            "b _081CF606\n\t"
            ".align 2, 0\n\t"
            "_081CF664: .4byte sMonRibbonListUi_Pal\n\t"
            "_081CF668:\n\t"
            "bl IsCreatePokenavListTaskActive\n\t"
            "cmp r0, #0\n\t"
            "bne _081CF6C2\n\t"
            "adds r0, r5, #0\n\t"
            "bl DrawListIndexNumber\n\t"
            "b _081CF606\n\t"
            "_081CF678:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081CF6C2\n\t"
            "movs r0, #2\n\t"
            "bl ShowBg\n\t"
            "movs r0, #3\n\t"
            "bl HideBg\n\t"
            "movs r0, #9\n\t"
            "bl PrintHelpBarText\n\t"
            "movs r0, #1\n\t"
            "bl PokenavFadeScreen\n\t"
            "ldr r0, [r5, #0xc]\n\t"
            "cmp r0, #0\n\t"
            "bne _081CF606\n\t"
            "movs r0, #2\n\t"
            "bl LoadLeftHeaderGfxForIndex\n\t"
            "movs r0, #2\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "bl ShowLeftHeaderGfx\n\t"
            "b _081CF606\n\t"
            "_081CF6B2:\n\t"
            "bl IsPaletteFadeActive\n\t"
            "cmp r0, #0\n\t"
            "bne _081CF6C2\n\t"
            "bl AreLeftHeaderSpritesMoving\n\t"
            "cmp r0, #0\n\t"
            "beq _081CF6C6\n\t"
            "_081CF6C2:\n\t"
            "movs r0, #2\n\t"
            "b _081CF6C8\n\t"
            "_081CF6C6:\n\t"
            "movs r0, #4\n\t"
            "_081CF6C8:\n\t"
            "add sp, #4\n\t"
            "pop {r4, r5}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".syntax divided");
}

static u32 LoopedTask_RibbonsListMoveCursorUp(s32 state)
{
    struct Pokenav_RibbonsMonMenu *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        switch (PokenavList_MoveCursorUp())
        {
        case 0:
            return LT_FINISH;
        case 1:
            return LT_SET_STATE(2);
        case 2:
        default:
            return LT_INC_AND_PAUSE;
        }
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        AddRibbonsMonListWindow(ptr);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListMoveCursorDown(s32 state)
{
    struct Pokenav_RibbonsMonMenu *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        switch (PokenavList_MoveCursorDown())
        {
        case 0:
            return LT_FINISH;
        case 1:
            return LT_SET_STATE(2);
        case 2:
        default:
            return LT_INC_AND_PAUSE;
        }
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        AddRibbonsMonListWindow(ptr);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListMovePageUp(s32 state)
{
    struct Pokenav_RibbonsMonMenu *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        switch (PokenavList_PageUp())
        {
        case 0:
            return LT_FINISH;
        case 1:
            return LT_SET_STATE(2);
        case 2:
        default:
            return LT_INC_AND_PAUSE;
        }
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        AddRibbonsMonListWindow(ptr);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListMovePageDown(s32 state)
{
    struct Pokenav_RibbonsMonMenu *ptr = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        switch (PokenavList_PageDown())
        {
        case 0:
            return LT_FINISH;
        case 1:
            return LT_SET_STATE(2);
        case 2:
        default:
            return LT_INC_AND_PAUSE;
        }
    case 1:
        if (PokenavList_IsMoveWindowTaskActive())
            return LT_PAUSE;
        // fallthrough
    case 2:
        AddRibbonsMonListWindow(ptr);
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListReturnToMainMenu(s32 state)
{
    switch (state)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        SetLeftHeaderSpritesInvisibility();
        break;
    }
    return LT_FINISH;
}

static u32 LoopedTask_RibbonsListOpenSummary(s32 state)
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
        break;
    }
    return LT_FINISH;
}

__attribute__((naked)) void DrawListIndexNumber(u16 windowId, u16 index)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, lr}\n\t"
            "sub sp, #0xc\n\t"
            "adds r5, r0, #0\n\t"
            "ldr r0, _081CF94C\n\t"
            "bl AddWindow\n\t"
            "movs r6, #0\n\t"
            "strh r0, [r5, #8]\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "bl PutWindowTilemap\n\t"
            "bl GetRibbonsMonListCount\n\t"
            "adds r1, r0, #0\n\t"
            "ldr r4, _081CF950\n\t"
            "adds r0, r4, #0\n\t"
            "movs r2, #1\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "bl DynamicPlaceholderTextUtil_Reset\n\t"
            "movs r0, #0\n\t"
            "adds r1, r4, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "ldr r4, _081CF954\n\t"
            "ldr r1, _081CF958\n\t"
            "adds r0, r4, #0\n\t"
            "bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
            "ldrb r0, [r5, #8]\n\t"
            "movs r1, #2\n\t"
            "str r1, [sp]\n\t"
            "movs r1, #0xff\n\t"
            "str r1, [sp, #4]\n\t"
            "str r6, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "adds r2, r4, #0\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldrb r0, [r5, #8]\n\t"
            "movs r1, #1\n\t"
            "bl CopyWindowToVram\n\t"
            "adds r0, r5, #0\n\t"
            "bl AddRibbonsMonListWindow\n\t"
            "add sp, #0xc\n\t"
            "pop {r4, r5, r6}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081CF94C: .4byte sRibbonsMonListWindowTemplate\n\t"
            "_081CF950: .4byte gStringVar1\n\t"
            "_081CF954: .4byte gStringVar2\n\t"
            "_081CF958: .4byte 0x085F5DCC\n\t"
            ".syntax divided");
}

__attribute__((naked)) void AddRibbonsMonListWindow(struct Pokenav_RibbonsMonMenu *menu)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "sub sp, #0xc\n\t"
            "adds r5, r0, #0\n\t"
            "bl PokenavList_GetSelectedIndex\n\t"
            "adds r1, r0, #0\n\t"
            "ldr r4, _081CF9A0\n\t"
            "adds r1, #1\n\t"
            "adds r0, r4, #0\n\t"
            "movs r2, #1\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "ldrb r0, [r5, #8]\n\t"
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
            "ldrb r0, [r5, #8]\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "add sp, #0xc\n\t"
            "pop {r4, r5}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081CF9A0: .4byte gStringVar1\n\t"
            ".syntax divided");
}


#ifndef NONMATCHING
// JP naked asm: builds the ribbons-mon-list template on the stack; C form
// differs, so asm stays default.
__attribute__((naked)) void CreateRibbonMonsList(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, lr}\n\t"
            "sub sp, #0x18\n\t"
            "bl GetMonRibbonMonListData\n\t"
            "str r0, [sp]\n\t"
            "bl GetRibbonsMonListCount\n\t"
            "mov r1, sp\n\t"
            "movs r4, #0\n\t"
            "strh r0, [r1, #4]\n\t"
            "movs r0, #4\n\t"
            "strb r0, [r1, #8]\n\t"
            "bl GetRibbonListMenuCurrIndex\n\t"
            "mov r1, sp\n\t"
            "strh r0, [r1, #6]\n\t"
            "movs r0, #0xe\n\t"
            "strb r0, [r1, #9]\n\t"
            "movs r0, #0x10\n\t"
            "strb r0, [r1, #0xa]\n\t"
            "movs r0, #1\n\t"
            "strb r0, [r1, #0xb]\n\t"
            "movs r0, #8\n\t"
            "strb r0, [r1, #0xc]\n\t"
            "movs r0, #2\n\t"
            "strb r0, [r1, #0xd]\n\t"
            "ldr r0, _081CF9F0\n\t"
            "str r0, [sp, #0x10]\n\t"
            "str r4, [sp, #0x14]\n\t"
            "ldr r0, _081CF9F4\n\t"
            "movs r2, #0\n\t"
            "bl CreatePokenavList\n\t"
            "add sp, #0x18\n\t"
            "pop {r4}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081CF9F0: .4byte BufferRibbonMonInfoText + 1\n\t"
            "_081CF9F4: .4byte 0x085F5DA4\n\t"
            ".syntax divided");
}
#else
void CreateRibbonMonsList(void)
{
    struct PokenavListTemplate template;

    template.list = GetMonRibbonMonListData();
    template.count = GetRibbonsMonListCount();
    template.startIndex = GetRibbonListMenuCurrIndex();
    template.itemSize = 4;
    template.item_X = 0xE;
    template.windowWidth = 0x10;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 2;
    template.bufferItemFunc = BufferRibbonMonInfoText;
    template.iconDrawFunc = NULL;
    CreatePokenavList(sRibbonsMonListBgTemplates, &template, 0);
}
#endif


__attribute__((naked)) void BufferRibbonMonInfoText(u8 windowId, u16 index)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sb\n\t"
            "mov r6, r8\n\t"
            "push {r6, r7}\n\t"
            "mov sb, r1\n\t"
            "adds r7, r0, #0\n\t"
            "bl DynamicPlaceholderTextUtil_Reset\n\t"
            "ldrb r0, [r7]\n\t"
            "cmp r0, #0xe\n\t"
            "bne _081CFA44\n\t"
            "ldrb r1, [r7, #1]\n\t"
            "movs r0, #0x64\n\t"
            "adds r4, r1, #0\n\t"
            "muls r4, r0, r4\n\t"
            "ldr r0, _081CFA3C\n\t"
            "adds r4, r4, r0\n\t"
            "adds r0, r4, #0\n\t"
            "bl GetMonGender\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r6, r0, #0x18\n\t"
            "adds r0, r4, #0\n\t"
            "bl GetLevelFromMonExp\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r5, r0, #0x18\n\t"
            "ldr r2, _081CFA40\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #2\n\t"
            "bl GetMonData3\n\t"
            "b _081CFA6A\n\t"
            ".align 2, 0\n\t"
            "_081CFA3C: .4byte gPlayerParty\n\t"
            "_081CFA40: .4byte gStringVar3\n\t"
            "_081CFA44:\n\t"
            "ldrb r0, [r7]\n\t"
            "ldrb r1, [r7, #1]\n\t"
            "bl GetBoxedMonPtr\n\t"
            "adds r4, r0, #0\n\t"
            "bl GetBoxMonGender\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r6, r0, #0x18\n\t"
            "adds r0, r4, #0\n\t"
            "bl GetLevelFromBoxMonExp\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r5, r0, #0x18\n\t"
            "ldr r2, _081CFAD0\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #2\n\t"
            "bl GetBoxMonData\n\t"
            "_081CFA6A:\n\t"
            "ldr r4, _081CFAD0\n\t"
            "adds r0, r4, #0\n\t"
            "bl StringGet_Nickname\n\t"
            "ldr r0, _081CFAD4\n\t"
            "mov r8, r0\n\t"
            "adds r1, r4, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #5\n\t"
            "bl StringCopyPadded\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r5, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "ldr r5, _081CFAD8\n\t"
            "adds r0, r5, #0\n\t"
            "adds r1, r4, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl StringCopyPadded\n\t"
            "ldrh r1, [r7, #2]\n\t"
            "adds r0, r4, #0\n\t"
            "movs r2, #1\n\t"
            "movs r3, #2\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "movs r0, #0\n\t"
            "mov r1, r8\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "movs r0, #1\n\t"
            "adds r1, r5, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "movs r0, #2\n\t"
            "adds r1, r4, #0\n\t"
            "bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
            "cmp r6, #0xfe\n\t"
            "beq _081CFAE0\n\t"
            "cmp r6, #0xfe\n\t"
            "bgt _081CFAE8\n\t"
            "cmp r6, #0\n\t"
            "bne _081CFAE8\n\t"
            "ldr r1, _081CFADC\n\t"
            "b _081CFAEA\n\t"
            ".align 2, 0\n\t"
            "_081CFAD0: .4byte gStringVar3\n\t"
            "_081CFAD4: .4byte gStringVar1\n\t"
            "_081CFAD8: .4byte gStringVar2\n\t"
            "_081CFADC: .4byte 0x085F5DD3\n\t"
            "_081CFAE0:\n\t"
            "ldr r1, _081CFAE4\n\t"
            "b _081CFAEA\n\t"
            ".align 2, 0\n\t"
            "_081CFAE4: .4byte 0x085F5DEB\n\t"
            "_081CFAE8:\n\t"
            "ldr r1, _081CFAFC\n\t"
            "_081CFAEA:\n\t"
            "mov r0, sb\n\t"
            "bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
            "pop {r3, r4}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081CFAFC: .4byte 0x085F5E03\n\t"
            ".syntax divided");
}
