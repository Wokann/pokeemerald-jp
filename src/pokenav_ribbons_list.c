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

static u32 HandleRibbonsMonListInput(struct Pokenav_RibbonsMonList *list)
{
    if (JOY_REPEAT(DPAD_UP))
    {
        return RIBBONS_MON_LIST_FUNC_MOVE_UP;
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        return RIBBONS_MON_LIST_FUNC_MOVE_DOWN;
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        return RIBBONS_MON_LIST_FUNC_PAGE_UP;
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        return RIBBONS_MON_LIST_FUNC_PAGE_DOWN;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        // Exiting back to main ribbons-mon list
        list->saveMonList = FALSE;
        list->callback = RibbonsMonMenu_ReturnToMainMenu;
        return RIBBONS_MON_LIST_FUNC_EXIT;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        // Opening the ribbons summary screen
        list->monList->currIndex = PokenavList_GetSelectedIndex();
        list->saveMonList = TRUE;
        list->callback = RibbonsMonMenu_ToSummaryScreen;
        return RIBBONS_MON_LIST_FUNC_OPEN_RIBBONS_SUMMARY;
    }
    else
    {
        return RIBBONS_MON_LIST_FUNC_NONE;
    }
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

u32 BuildPartyMonRibbonList(s32 state)
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
                InsertRibbonsMonListItem(list, &item);
            }
        }
    }

    return LT_INC_AND_CONTINUE;
}

u32 InitBoxMonRibbonList(s32 state)
{
    struct Pokenav_RibbonsMonList *list = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_LIST);
    list->monId = 0;
    list->boxId = 0;
    return LT_INC_AND_CONTINUE;
}

u32 BuildBoxMonRibbonList(s32 state)
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
                    InsertRibbonsMonListItem(list, &item);
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

static void InsertRibbonsMonListItem(struct Pokenav_RibbonsMonList *list, struct PokenavMonListItem *item)
{
    u32 left = 0;
    u32 right = list->monList->listCount;
    u32 insertionIdx = left + (right - left) / 2;

    while (right != insertionIdx)
    {
        if (item->data > list->monList->monData[insertionIdx].data)
            right = insertionIdx;
        else
            left = insertionIdx + 1;
        insertionIdx = left + (right - left) / 2;
    }
    for (right = list->monList->listCount; right > insertionIdx; right--)
        list->monList->monData[right] = list->monList->monData[right - 1];
    list->monList->monData[insertionIdx] = *item;
    list->monList->listCount++;
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

bool32 IsRibbonsSummaryLoopedTaskActive(void)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    return menu->callback();
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

static u32 LoopedTask_OpenRibbonsMonList(s32 state)
{
    struct Pokenav_RibbonsMonMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_RIBBONS_MON_MENU);
    switch (state)
    {
    case 0:
        InitBgTemplates(sMonRibbonListBgTemplates, 2);
        DecompressAndCopyTileDataToVram(1, sMonRibbonListFrameTiles, 0, 0, 0);
        SetBgTilemapBuffer(1, menu->buff);
        CopyToBgTilemapBuffer(1, sMonRibbonListFrameTilemap, 0, 0);
        CopyPaletteIntoBufferUnfaded(sMonRibbonListFramePal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        CopyBgTilemapBufferToVram(1);
        return LT_INC_AND_PAUSE;
    case 1:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        if (!UpdateMonListBgs())
            return LT_PAUSE;
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ShowBg(1);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        CopyPaletteIntoBufferUnfaded(sMonRibbonListUi_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        CreateRibbonMonsList();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsCreatePokenavListTaskActive())
            return LT_PAUSE;
        DrawListIndexNumber(menu);
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        ShowBg(2);
        HideBg(3);
        PrintHelpBarText(HELPBAR_RIBBONS_MON_LIST);
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        if (!menu->fromSummary)
        {
            LoadLeftHeaderGfxForIndex(POKENAV_GFX_RIBBONS_MENU);
            ShowLeftHeaderGfx(POKENAV_GFX_RIBBONS_MENU, TRUE, FALSE);
        }
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

u32 LoopedTask_RibbonsListMoveCursorUp(s32 state)
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

u32 LoopedTask_RibbonsListMoveCursorDown(s32 state)
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

u32 LoopedTask_RibbonsListMovePageUp(s32 state)
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

u32 LoopedTask_RibbonsListMovePageDown(s32 state)
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

u32 LoopedTask_RibbonsListReturnToMainMenu(s32 state)
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

u32 LoopedTask_RibbonsListOpenSummary(s32 state)
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

static void DrawListIndexNumber(struct Pokenav_RibbonsMonMenu *menu)
{
    s32 listCount;

    menu->winid = AddWindow(&sRibbonsMonListWindowTemplate);
    PutWindowTilemap(menu->winid);
    listCount = GetRibbonsMonListCount();
    ConvertIntToDecimalStringN(gStringVar1, listCount, STR_CONV_MODE_RIGHT_ALIGN, 3);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar2, gText_RibbonsMonListCount);
    AddTextPrinterParameterized(menu->winid, FONT_NORMAL, gStringVar2, 0, 2, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(menu->winid, COPYWIN_MAP);
    AddRibbonsMonListWindow(menu);
}

static void AddRibbonsMonListWindow(struct Pokenav_RibbonsMonMenu *menu)
{
    s32 listIndex = PokenavList_GetSelectedIndex();

    ConvertIntToDecimalStringN(gStringVar1, listIndex + 1, STR_CONV_MODE_RIGHT_ALIGN, 3);
    AddTextPrinterParameterized(menu->winid, FONT_NORMAL, gStringVar1, 0, 2, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(menu->winid, COPYWIN_GFX);
}


void CreateRibbonMonsList(void)
{
    struct PokenavListTemplate template;

    template.list = GetMonRibbonMonListData();
    template.count = GetRibbonsMonListCount();
    template.itemSize = 4;
    template.startIndex = GetRibbonListMenuCurrIndex();
    template.item_X = 0xE;
    template.windowWidth = 0x10;
    template.listTop = 1;
    template.maxShowed = 8;
    template.fillValue = 2;
    template.bufferItemFunc = BufferRibbonMonInfoText;
    template.iconDrawFunc = NULL;
    CreatePokenavList(&sMonRibbonListBgTemplates[1], &template, 0);
}


static void BufferRibbonMonInfoText(struct PokenavListItem *listItem, u8 *dest)
{
    u8 gender;
    u8 level;
    const u8 *genderStr;
    struct PokenavMonListItem *item = (struct PokenavMonListItem *)listItem;

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
    StringCopyPadded(gStringVar1, gStringVar3, CHAR_SPACE, 5);
    ConvertIntToDecimalStringN(gStringVar3, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringCopyPadded(gStringVar2, gStringVar3, CHAR_SPACE, 3);
    ConvertIntToDecimalStringN(gStringVar3, item->data, STR_CONV_MODE_RIGHT_ALIGN, 2);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gStringVar1);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, gStringVar2);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gStringVar3);
    switch (gender)
    {
    case MON_MALE:
        genderStr = sText_RibbonsMonListItemMale;
        break;
    case MON_FEMALE:
        genderStr = sText_RibbonsMonListItemFemale;
        break;
    case MON_GENDERLESS:
    default:
        genderStr = sText_RibbonsMonListItemUnknown;
        break;
    }
    DynamicPlaceholderTextUtil_ExpandPlaceholders(dest, genderStr);
}
