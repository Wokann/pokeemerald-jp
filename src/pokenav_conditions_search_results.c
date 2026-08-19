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

// Indices into sSearchResultLoopTaskFuncs, matching US pokeemerald.
enum
{
    CONDITION_SEARCH_FUNC_NONE,
    CONDITION_SEARCH_FUNC_MOVE_UP,
    CONDITION_SEARCH_FUNC_MOVE_DOWN,
    CONDITION_SEARCH_FUNC_PAGE_UP,
    CONDITION_SEARCH_FUNC_PAGE_DOWN,
    CONDITION_SEARCH_FUNC_EXIT,
    CONDITION_SEARCH_FUNC_SELECT_MON
};

// Indices into sRibbonsMonMenuLoopTaskFuncs, matching US pokeemerald.
enum
{
    RIBBONS_MON_LIST_FUNC_NONE,
    RIBBONS_MON_LIST_FUNC_MOVE_UP,
    RIBBONS_MON_LIST_FUNC_MOVE_DOWN,
    RIBBONS_MON_LIST_FUNC_PAGE_UP,
    RIBBONS_MON_LIST_FUNC_PAGE_DOWN,
    RIBBONS_MON_LIST_FUNC_EXIT,
    RIBBONS_MON_LIST_FUNC_OPEN_RIBBONS_SUMMARY
};

extern u8 sInitialLoadId; // JP IWRAM, bound in ld_script_jp.txt
extern const u8 gText_SearchResultRank[]; // JP 0x085CB81B, bound in ld_script_jp.txt

// JP sign-extends the u8 load id at call sites (pokeemerald gfx.c declared it s8).
extern s8 GetConditionGraphMenuCurrentLoadIndex(void);

// libgcc trampoline agbcc emits for indirect calls.
void _call_via_r0(void);


// Naked-function prototypes so C callers use the right argument types.
void CreateConditionMonPic(u8 id);
bool32 UpdateConditionGraphMenuWindows(u8 mode, u16 bufferIndex, bool8 winMode);
static void PrintSearchResultListMenuItems(struct Pokenav_SearchResultsGfx *gfx);
static void BufferSearchMonListItem(struct PokenavMonListItem *item, u8 *dest);
static u32 LoopedTask_OpenConditionSearchResults(s32 state);
static void CreateSearchResultsList(void);
static u32 GetMonRibbonListLoopTaskFunc(s32 state);
static u32 LoopedTask_OpenRibbonsMonList(s32 state);
static void DrawListIndexNumber(struct Pokenav_RibbonsMonMenu *menu);
static void AddRibbonsMonListWindow(struct Pokenav_RibbonsMonMenu *menu);
static void CreateRibbonMonsList(void);
static void BufferRibbonMonInfoText(struct PokenavListItem *listItem, u8 *dest);
bool32 IsRibbonsMonListLoopedTaskActive(void);
u32 LoopedTask_MoveSearchListCursorUp(s32 state);
u32 LoopedTask_MoveSearchListCursorDown(s32 state);
u32 LoopedTask_MoveSearchListPageUp(s32 state);
u32 LoopedTask_MoveSearchListPageDown(s32 state);
u32 LoopedTask_RibbonsListMoveCursorUp(s32 state);
u32 LoopedTask_RibbonsListMoveCursorDown(s32 state);
u32 LoopedTask_RibbonsListMovePageUp(s32 state);
u32 LoopedTask_RibbonsListMovePageDown(s32 state);
static void UpdateIndexNumberDisplay(u8 windowId, u16 index);

u32 LoopedTask_TransitionMons(s32 state);
u32 LoopedTask_MoveCursorNoTransition(s32 state);
u32 LoopedTask_SlideMonOut(s32 state);
u32 LoopedTask_OpenMonMarkingsWindow(s32 state);
u32 LoopedTask_CloseMonMarkingsWindow(s32 state);
void CopyUnusedConditionWindowsToVram(void);
static void SpriteCB_PartyPokeball(struct Sprite *sprite);
static void HighlightCurrentPartyIndexPokeball(struct Sprite *sprite);
static void MonMarkingsCallback(struct Sprite *sprite);
void CreateMonMarkingsOrPokeballIndicators(void);
static void FreeConditionMenuGfx(struct Pokenav_ConditionMenuGfx *menu);
void FreeConditionGraphMenuSubstruct2(void);
static void MonPicGfxSpriteCallback(struct Sprite *sprite);
void CreateConditionMonPic(u8 id);
void VBlankCB_PokenavConditionGraph(void);
static void SetExitVBlank(void);
void ToggleGraphData(bool8 showBg);
void DoConditionGraphEnterTransition(void);
void DoConditionGraphExitTransition(void);
u8 GetMonMarkingsData(void);
bool32 PokenavCallback_Init_ConditionSearch(void);
bool32 PokenavCallback_Init_ReturnToMonSearchList(void);
u32 GetConditionSearchResultsCallback(void);
void FreeSearchResultSubstruct1(void);
static bool32 HandleConditionSearchInput_WaitSetup(struct Pokenav_SearchResults *menu);
static u32 HandleConditionSearchInput(struct Pokenav_SearchResults *menu);
static u32 ReturnToConditionSearchList(struct Pokenav_SearchResults *menu);
static u32 OpenConditionGraphFromSearchList(struct Pokenav_SearchResults *menu);
static u32 GetReturningFromGraph(void);
static struct PokenavMonListItem * GetSearchResultsMonDataList(void);
static u16 GetSearchResultsMonListCount(void);
static s32 GetSearchResultsSelectedMonRank(void);
static u16 GetSearchResultsCurrentListIndex(void);
u32 BuildPartyMonSearchResults(s32 state);
u32 InitBoxMonSearchResults(s32 state);
u32 BuildBoxMonSearchResults(s32 state);
u32 ConvertConditionsToListRanks(s32 state);
static void InsertMonListItem(struct Pokenav_SearchResults *menu, struct PokenavMonListItem *item);
static void InsertRibbonsMonListItem(struct Pokenav_RibbonsMonList *list, struct PokenavMonListItem *item);
bool32 OpenConditionSearchResults(void);
bool32 OpenConditionSearchListFromGraph(void);
void CreateSearchResultsLoopedTask(s32 idx);
static bool32 GetSearchResultCurrentLoopedTaskActive(void);
void FreeSearchResultSubstruct2(void);
u32 LoopedTask_ExitConditionSearchMenu(s32 state);
u32 LoopedTask_SelectSearchResult(s32 state);
static void AddSearchResultListMenuWindow(struct Pokenav_SearchResultsGfx *gfx);
bool32 PokenavCallback_Init_MonRibbonList(void);
bool32 PokenavCallback_Init_RibbonsMonListFromSummary(void);
u32 GetRibbonsMonListCallback(void);
void FreeRibbonsMonList(void);
static u32 HandleRibbonsMonListInput_WaitListInit(struct Pokenav_RibbonsMonList *list);
static u32 HandleRibbonsMonListInput(struct Pokenav_RibbonsMonList *list);
static u32 RibbonsMonMenu_ReturnToMainMenu(struct Pokenav_RibbonsMonList *list);
static u32 RibbonsMonMenu_ToSummaryScreen(struct Pokenav_RibbonsMonList *list);
static u32 UpdateMonListBgs(void);
static s32 GetRibbonsMonListCount(void);
static s32 GetRibbonListMenuCurrIndex(void);
static u32 GetConditionSearchLoopedTask(s32 state);
u32 BuildPartyMonRibbonList(s32 state);
u32 InitBoxMonRibbonList(s32 state);
u32 BuildBoxMonRibbonList(s32 state);
bool32 OpenRibbonsMonList(void);
bool32 OpenRibbonsMonListFromRibbonsSummary(void);
void CreateRibbonsMonListLoopedTask(s32 idx);
static bool32 GetRibbonsMonCurrentLoopedTaskActive(void);
void FreeRibbonsMonMenu(void);
u32 LoopedTask_RibbonsListReturnToMainMenu(s32 state);
u32 LoopedTask_RibbonsListOpenSummary(s32 state);

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
extern const u8 sText_ConditionSearchMonMale[];    // JP 0x085CB7D6, "{STR_VAR_1} {COLOR}♂..."
extern const u8 sText_ConditionSearchMonFemale[];  // JP 0x085CB7EA
extern const u8 sText_ConditionSearchMonUnknown[]; // JP 0x085CB7FE
extern const u8 gText_RibbonsMonListCount[];       // JP 0x085F5DCC
extern const u8 sText_RibbonsMonListItemMale[];    // JP 0x085F5DD3
extern const u8 sText_RibbonsMonListItemFemale[];  // JP 0x085F5DEB
extern const u8 sText_RibbonsMonListItemUnknown[]; // JP 0x085F5E03
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

static u32 HandleConditionSearchInput(struct Pokenav_SearchResults *menu)
{
    if (JOY_REPEAT(DPAD_UP))
    {
        return CONDITION_SEARCH_FUNC_MOVE_UP;
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        return CONDITION_SEARCH_FUNC_MOVE_DOWN;
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        return CONDITION_SEARCH_FUNC_PAGE_UP;
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        return CONDITION_SEARCH_FUNC_PAGE_DOWN;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        // Exiting back to main search menu
        menu->saveResultsList = FALSE;
        menu->callback = ReturnToConditionSearchList;
        return CONDITION_SEARCH_FUNC_EXIT;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        // Entering graph menu
        menu->monList->currIndex = PokenavList_GetSelectedIndex();
        menu->saveResultsList = TRUE;
        menu->callback = OpenConditionGraphFromSearchList;
        return CONDITION_SEARCH_FUNC_SELECT_MON;
    }
    else
    {
        return CONDITION_SEARCH_FUNC_NONE;
    }
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

u32 BuildPartyMonSearchResults(s32 state)
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

u32 InitBoxMonSearchResults(s32 state)
{
    struct Pokenav_SearchResults *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS);
    menu->monId = 0;
    menu->boxId = 0;
    return LT_INC_AND_CONTINUE;
}

u32 BuildBoxMonSearchResults(s32 state)
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

u32 ConvertConditionsToListRanks(s32 state)
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

bool32 IsRibbonsMonListLoopedTaskActive(void)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    return gfx->callback();
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

static u32 LoopedTask_OpenConditionSearchResults(s32 state)
{
    struct Pokenav_SearchResultsGfx *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_SEARCH_RESULTS_GFX);
    switch (state)
    {
    case 0:
        InitBgTemplates(sConditionSearchResultBgTemplates, 2);
        DecompressAndCopyTileDataToVram(1, sConditionSearchResultTiles, 0, 0, 0);
        SetBgTilemapBuffer(1, gfx->buff);
        CopyToBgTilemapBuffer(1, sConditionSearchResultTilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyPaletteIntoBufferUnfaded(sConditionSearchResultFramePal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        if (!GetReturningFromGraph())
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        CopyPaletteIntoBufferUnfaded(sListBg_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        CreateSearchResultsList();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsCreatePokenavListTaskActive())
            return LT_PAUSE;
        AddSearchResultListMenuWindow(gfx);
        PrintHelpBarText(HELPBAR_CONDITION_MON_LIST);
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ShowBg(1);
        ShowBg(2);
        HideBg(3);
        if (!gfx->fromGraph)
        {
            u8 searchGfxId = GetSelectedConditionSearch() + POKENAV_MENUITEM_CONDITION_SEARCH_COOL;
            LoadLeftHeaderGfxForIndex(searchGfxId);
            ShowLeftHeaderGfx(searchGfxId, TRUE, FALSE);
            ShowLeftHeaderGfx(POKENAV_GFX_CONDITION_MENU, TRUE, FALSE);
        }
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        return LT_INC_AND_PAUSE;
    case 5:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        break;
    }
    return LT_FINISH;
}

u32 LoopedTask_MoveSearchListCursorUp(s32 state)
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

u32 LoopedTask_MoveSearchListCursorDown(s32 state)
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

u32 LoopedTask_MoveSearchListPageUp(s32 state)
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

u32 LoopedTask_MoveSearchListPageDown(s32 state)
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

u32 LoopedTask_ExitConditionSearchMenu(s32 state)
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

u32 LoopedTask_SelectSearchResult(s32 state)
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


void CreateSearchResultsList(void)
{
    struct PokenavListTemplate template;

    template.list = GetSearchResultsMonDataList();
    template.count = GetSearchResultsMonListCount();
    template.itemSize = 4;
    template.startIndex = GetSearchResultsCurrentListIndex();
    template.item_X = 0xE;
    template.windowWidth = 0xF;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 2;
    template.bufferItemFunc = BufferSearchMonListItem;
    template.iconDrawFunc = NULL;
    CreatePokenavList(&sConditionSearchResultBgTemplates[1], &template, 0);
}


static void BufferSearchMonListItem(struct PokenavMonListItem *item, u8 *dest)
{
    u8 gender;
    u8 level;
    const u8 *genderStr;

    DynamicPlaceholderTextUtil_Reset();
    if (item->boxId == TOTAL_BOXES_COUNT)
    {
        struct Pokemon *mon = &gPlayerParty[item->monId];
        gender = GetMonGender(mon);
        level = GetLevelFromMonExp(mon);
        GetMonData(mon, MON_DATA_NICKNAME, gStringVar3);
    }
    else
    {
        struct BoxPokemon *boxMon = GetBoxedMonPtr(item->boxId, item->monId);
        gender = GetBoxMonGender(boxMon);
        level = GetLevelFromBoxMonExp(boxMon);
        GetBoxMonData(boxMon, MON_DATA_NICKNAME, gStringVar3);
    }
    StringGet_Nickname(gStringVar3);
    StringCopyPadded(gStringVar1, gStringVar3, 0, 5);
    ConvertIntToDecimalStringN(gStringVar3, level, 0, 3);
    StringCopyPadded(gStringVar2, gStringVar3, 0, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
    switch (gender)
    {
    case MON_MALE:
        genderStr = sText_ConditionSearchMonMale;
        break;
    case MON_FEMALE:
        genderStr = sText_ConditionSearchMonFemale;
        break;
    case MON_GENDERLESS:
    default:
        genderStr = sText_ConditionSearchMonUnknown;
        break;
    }
    DynamicPlaceholderTextUtil_ExpandPlaceholders(dest, genderStr);
}
