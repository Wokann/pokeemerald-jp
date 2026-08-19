#ifndef POKENAV_CONDITIONS_GFX_TAIL
#include "global.h"
#include "bg.h"
#include "window.h"
#include "pokenav.h"

// JP conditions data tables (defined at fixed addresses in ld_script_jp.txt).
// Global (not static) because they are referenced from
// pokenav_conditions.c and pokenav_conditions_tail.c.
const struct BgTemplate sMenuBgTemplates[3] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1D,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x1E,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

// JP window layouts differ from pokeemerald (width/baseBlock).
const struct WindowTemplate sMonNameGenderWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 1,
    .width = 12,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 2
};

const struct WindowTemplate sListIndexWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x32
};

const struct WindowTemplate sUnusedWindowTemplate1 =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 0x1C,
    .width = 5,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x40
};

const struct WindowTemplate sUnusedWindowTemplate2 =
{
    .bg = 1,
    .tilemapLeft = 13,
    .tilemapTop = 0x1C,
    .width = 3,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x40
};

u32 LoopedTask_TransitionMons(s32);
u32 LoopedTask_ExitConditionGraphMenu(s32);
u32 LoopedTask_MoveCursorNoTransition(s32);
u32 LoopedTask_SlideMonOut(s32);
u32 LoopedTask_OpenMonMarkingsWindow(s32);
u32 LoopedTask_CloseMonMarkingsWindow(s32);

const LoopedTask sLoopedTaskFuncs[] =
{
    [CONDITION_FUNC_NONE]           = NULL,
    [CONDITION_FUNC_SLIDE_MON_IN]   = LoopedTask_TransitionMons,
    [CONDITION_FUNC_RETURN]         = LoopedTask_ExitConditionGraphMenu,
    [CONDITION_FUNC_NO_TRANSITION]  = LoopedTask_MoveCursorNoTransition,
    [CONDITION_FUNC_SLIDE_MON_OUT]  = LoopedTask_SlideMonOut,
    [CONDITION_FUNC_ADD_MARKINGS]   = LoopedTask_OpenMonMarkingsWindow,
    [CONDITION_FUNC_CLOSE_MARKINGS] = LoopedTask_CloseMonMarkingsWindow,
};

// Condition search results
u32 BuildPartyMonSearchResults(s32);
u32 InitBoxMonSearchResults(s32);
u32 BuildBoxMonSearchResults(s32);
u32 ConvertConditionsToListRanks(s32);

const u32 sSearchMonDataIds[] = {MON_DATA_COOL, MON_DATA_BEAUTY, MON_DATA_CUTE, MON_DATA_SMART, MON_DATA_TOUGH};

const LoopedTask sConditionSearchLoopedTaskFuncs[] =
{
    BuildPartyMonSearchResults,
    InitBoxMonSearchResults,
    BuildBoxMonSearchResults,
    ConvertConditionsToListRanks
};

// Condition search result screen.
const u16 sConditionSearchResultFramePal[] = INCBIN_U16("graphics/pokenav_conditions/sConditionSearchResultFramePal.bin");
const u32 sConditionSearchResultTiles[] = INCBIN_U32("graphics/pokenav_conditions/sConditionSearchResultTiles.bin");
const u32 sConditionSearchResultTilemap[] = INCBIN_U32("graphics/pokenav_conditions/sConditionSearchResultTilemap.bin");
const u16 sListBg_Pal[] = INCBIN_U16("graphics/list_ui/sListBg_Pal.bin");

const struct BgTemplate sConditionSearchResultBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x07,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

u32 LoopedTask_MoveSearchListCursorUp(s32);
u32 LoopedTask_MoveSearchListCursorDown(s32);
u32 LoopedTask_MoveSearchListPageUp(s32);
u32 LoopedTask_MoveSearchListPageDown(s32);
u32 LoopedTask_ExitConditionSearchMenu(s32);
u32 LoopedTask_SelectSearchResult(s32);

// Indices into sSearchResultLoopTaskFuncs, matching JP conditions_tail.c.
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

const LoopedTask sSearchResultLoopTaskFuncs[] =
{
    [CONDITION_SEARCH_FUNC_NONE]       = NULL,
    [CONDITION_SEARCH_FUNC_MOVE_UP]    = LoopedTask_MoveSearchListCursorUp,
    [CONDITION_SEARCH_FUNC_MOVE_DOWN]  = LoopedTask_MoveSearchListCursorDown,
    [CONDITION_SEARCH_FUNC_PAGE_UP]    = LoopedTask_MoveSearchListPageUp,
    [CONDITION_SEARCH_FUNC_PAGE_DOWN]  = LoopedTask_MoveSearchListPageDown,
    [CONDITION_SEARCH_FUNC_EXIT]       = LoopedTask_ExitConditionSearchMenu,
    [CONDITION_SEARCH_FUNC_SELECT_MON] = LoopedTask_SelectSearchResult
};

const struct WindowTemplate sSearchResultListMenuWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 20
};

// Ribbons mon list.
u32 BuildPartyMonRibbonList(s32);
u32 InitBoxMonRibbonList(s32);
u32 BuildBoxMonRibbonList(s32);

const LoopedTask sMonRibbonListLoopTaskFuncs[] =
{
    BuildPartyMonRibbonList,
    InitBoxMonRibbonList,
    BuildBoxMonRibbonList
};

const u16 sMonRibbonListFramePal[] = INCBIN_U16("graphics/pokemon_summary/sMonRibbonListFramePal.bin");
const u32 sMonRibbonListFrameTiles[] = INCBIN_U32("graphics/pokemon_summary/sMonRibbonListFrameTiles.bin");
const u32 sMonRibbonListFrameTilemap[] = INCBIN_U32("graphics/pokemon_summary/sMonRibbonListFrameTilemap.bin");
const u16 sMonRibbonListUi_Pal[] = INCBIN_U16("graphics/pokemon_summary/sMonRibbonListUi_Pal.bin");

const struct BgTemplate sMonRibbonListBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x07,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

u32 LoopedTask_RibbonsListMoveCursorUp(s32);
u32 LoopedTask_RibbonsListMoveCursorDown(s32);
u32 LoopedTask_RibbonsListMovePageUp(s32);
u32 LoopedTask_RibbonsListMovePageDown(s32);
u32 LoopedTask_RibbonsListReturnToMainMenu(s32);
u32 LoopedTask_RibbonsListOpenSummary(s32);

// Indices into sRibbonsMonMenuLoopTaskFuncs, matching JP conditions_tail.c.
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

const LoopedTask sRibbonsMonMenuLoopTaskFuncs[] =
{
    [RIBBONS_MON_LIST_FUNC_NONE]                 = NULL,
    [RIBBONS_MON_LIST_FUNC_MOVE_UP]              = LoopedTask_RibbonsListMoveCursorUp,
    [RIBBONS_MON_LIST_FUNC_MOVE_DOWN]            = LoopedTask_RibbonsListMoveCursorDown,
    [RIBBONS_MON_LIST_FUNC_PAGE_UP]              = LoopedTask_RibbonsListMovePageUp,
    [RIBBONS_MON_LIST_FUNC_PAGE_DOWN]            = LoopedTask_RibbonsListMovePageDown,
    [RIBBONS_MON_LIST_FUNC_EXIT]                 = LoopedTask_RibbonsListReturnToMainMenu,
    [RIBBONS_MON_LIST_FUNC_OPEN_RIBBONS_SUMMARY] = LoopedTask_RibbonsListOpenSummary
};

const struct WindowTemplate sRibbonsMonListWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 1,
    .tilemapTop = 6,
    .width = 7,
    .height = 2,
    .paletteNum = 1,
    .baseBlock = 20
};

// Ribbons mon list texts.
const u8 gText_RibbonsMonListCount[] = _("　　　/{DYNAMIC 0}");
const u8 sText_RibbonsMonListItemMale[] = _("{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 5 1 6}♂{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ");
const u8 sText_RibbonsMonListItemFemale[] = _("{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 7 1 8}♀{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ");
// JP text carries its own $ and trailing full-width spaces (no auto terminator).
const u8 sText_RibbonsMonListItemUnknown[] = __("{DYNAMIC 0}　　/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ$　　");

struct RibbonData { u8 numBits; u8 numRibbons; u8 ribbonId; bool8 isGiftRibbon; };
const struct RibbonData sRibbonData[] =
{
    {1, 1, CHAMPION_RIBBON,      FALSE},
    {3, 4, COOL_RIBBON_NORMAL,   FALSE},
    {3, 4, BEAUTY_RIBBON_NORMAL, FALSE},
    {3, 4, CUTE_RIBBON_NORMAL,   FALSE},
    {3, 4, SMART_RIBBON_NORMAL,  FALSE},
    {3, 4, TOUGH_RIBBON_NORMAL,  FALSE},
    {1, 1, WINNING_RIBBON,       FALSE},
    {1, 1, VICTORY_RIBBON,       FALSE},
    {1, 1, ARTIST_RIBBON,        FALSE},
    {1, 1, EFFORT_RIBBON,        FALSE},
    {1, 1, MARINE_RIBBON,        TRUE},
    {1, 1, LAND_RIBBON,          TRUE},
    {1, 1, SKY_RIBBON,           TRUE},
    {1, 1, COUNTRY_RIBBON,       TRUE},
    {1, 1, NATIONAL_RIBBON,      TRUE},
    {1, 1, EARTH_RIBBON,         TRUE},
    {1, 1, WORLD_RIBBON,         TRUE},
};
#else
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

static u32 LoopedTask_OpenConditionGraphMenu(s32);
static u32 GetConditionGraphMenuLoopedTaskActive(void);
u32 LoopedTask_ExitConditionGraphMenu(s32);
bool32 OpenConditionGraphMenu(void)
{
    struct Pokenav_ConditionMenuGfx *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX, sizeof(struct Pokenav_ConditionMenuGfx));

    if (menu == NULL)
        return FALSE;

    menu->monPicSpriteId = SPRITE_NONE;
    menu->loopedTaskId = CreateLoopedTask(LoopedTask_OpenConditionGraphMenu, 1);
    menu->callback = GetConditionGraphMenuLoopedTaskActive;
    menu->windowModeState = 0;
    return TRUE;
}

void CreateConditionGraphMenuLoopedTask(s32 id)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    menu->loopedTaskId = CreateLoopedTask(sLoopedTaskFuncs[id], 1);
    menu->callback = GetConditionGraphMenuLoopedTaskActive;
}

bool32 IsSearchResultLoopedTaskActive(void)
{
    // JP: POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX, callback at +0x1810
    u8 *gfx = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    return ((bool32 (*)(void))*(u32 *)(gfx + 0x1810))();
}


// JP-only alias: the `bx r1` at the end of IsSearchResultLoopedTaskActive is
// also labeled sub_081CD5D8 (0x081CD5D8) in the JP ROM.  No separate code.
__asm__(".set sub_081CD5D8, IsSearchResultLoopedTaskActive + 0x14");

static u32 GetConditionGraphMenuLoopedTaskActive(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    return IsLoopedTaskActive(menu->loopedTaskId);
}

static u32 LoopedTask_OpenConditionGraphMenu(s32 state)
{
    u32 zero;
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (state)
    {
    case 0:
        if (LoadConditionGraphMenuGfx() != TRUE)
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 1:
        InitBgTemplates(sMenuBgTemplates, ARRAY_COUNT(sMenuBgTemplates));
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG3_ON);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(11, 4));
        DecompressAndCopyTileDataToVram(3, gPokenavCondition_Gfx, 0, 0, 0);
        return LT_INC_AND_PAUSE;
    case 2:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        DecompressAndCopyTileDataToVram(2, sConditionGraphData_Gfx, 0, 0, 0);
        return LT_INC_AND_PAUSE;
    case 3:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        LZ77UnCompVram(gPokenavCondition_Tilemap, menu->tilemapBuffers[0]);
        SetBgTilemapBuffer(3, menu->tilemapBuffers[0]);
        if (IsConditionMenuSearchMode() == TRUE)
            CopyToBgTilemapBufferRect(3, gPokenavOptions_Tilemap, 0, 5, 9, 4);
        CopyBgTilemapBufferToVram(3);
        CopyPaletteIntoBufferUnfaded(gPokenavCondition_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        CopyPaletteIntoBufferUnfaded(gConditionText_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        menu->monTransitionX = -80;
        return LT_INC_AND_PAUSE;
    case 4:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        LZ77UnCompVram(sConditionGraphData_Tilemap, menu->tilemapBuffers[2]);
        SetBgTilemapBuffer(2, menu->tilemapBuffers[2]);
        CopyBgTilemapBufferToVram(2);
        CopyPaletteIntoBufferUnfaded(gConditionGraphData_Pal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
        ConditionGraph_InitWindow(2);
        return LT_INC_AND_PAUSE;
    case 5:
        BgDmaFill(1, 0, 0, 1);
        BgDmaFill(1, 17, 1, 1);
        zero = 0;
        CpuSet(&zero, menu->tilemapBuffers[1], OBJ_PLTT);
        SetBgTilemapBuffer(1, menu->tilemapBuffers[1]);
        return LT_INC_AND_PAUSE;
    case 6:
        if (FreeTempTileDataBuffersIfPossible())
            return LT_PAUSE;
        menu->nameGenderWindowId = AddWindow(&sMonNameGenderWindowTemplate);
        if (IsConditionMenuSearchMode() == TRUE)
        {
            menu->listIndexWindowId = AddWindow(&sListIndexWindowTemplate);
            menu->unusedWindowId1 = AddWindow(&sUnusedWindowTemplate1);
            menu->unusedWindowId2 = AddWindow(&sUnusedWindowTemplate2);
        }
        DeactivateAllTextPrinters();
        return LT_INC_AND_PAUSE;
    case 7:
        CreateConditionMonPic(0);
        return LT_INC_AND_PAUSE;
    case 8:
        CreateMonMarkingsOrPokeballIndicators();
        return LT_INC_AND_PAUSE;
    case 9:
        if (IsConditionMenuSearchMode() == TRUE)
            CopyUnusedConditionWindowsToVram();
        return LT_INC_AND_PAUSE;
    case 10:
        UpdateConditionGraphMenuWindows(0, (u16)(s8)GetConditionGraphMenuCurrentLoadIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 11:
        UpdateConditionGraphMenuWindows(1, (u16)(s8)GetConditionGraphMenuCurrentLoadIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 12:
        UpdateConditionGraphMenuWindows(2, (u16)(s8)GetConditionGraphMenuCurrentLoadIndex(), TRUE);
        return LT_INC_AND_PAUSE;
    case 13:
        if (UpdateConditionGraphMenuWindows(3, (u16)(s8)GetConditionGraphMenuCurrentLoadIndex(), TRUE) != TRUE)
            return LT_PAUSE;
        PutWindowTilemap(menu->nameGenderWindowId);
        if (IsConditionMenuSearchMode() == TRUE)
        {
            PutWindowTilemap(menu->listIndexWindowId);
            PutWindowTilemap(menu->unusedWindowId1);
            PutWindowTilemap(menu->unusedWindowId2);
        }
        return LT_INC_AND_PAUSE;
    case 14:
        ShowBg(1);
        HideBg(2);
        ShowBg(3);
        if (IsConditionMenuSearchMode() == TRUE)
            PrintHelpBarText(HELPBAR_CONDITION_MON_STATUS);
        return LT_INC_AND_PAUSE;
    case 15:
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        if (!IsConditionMenuSearchMode())
        {
            LoadLeftHeaderGfxForIndex(POKENAV_GFX_PARTY_MENU);
            ShowLeftHeaderGfx(POKENAV_GFX_CONDITION_MENU, TRUE, FALSE);
            ShowLeftHeaderGfx(POKENAV_GFX_PARTY_MENU, TRUE, FALSE);
        }
        return LT_INC_AND_PAUSE;
    case 16:
        if (IsPaletteFadeActive())
            return LT_PAUSE;
        if (!IsConditionMenuSearchMode() && AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        SetVBlankCallback_(VBlankCB_PokenavConditionGraph);
        return LT_INC_AND_PAUSE;
    case 17:
        DoConditionGraphEnterTransition();
        ConditionGraph_InitResetScanline(GetConditionGraphPtr());
        return LT_INC_AND_PAUSE;
    case 18:
        if (ConditionGraph_ResetScanline(GetConditionGraphPtr()))
            return LT_PAUSE;
        return LT_INC_AND_PAUSE;
    case 19:
        ToggleGraphData(TRUE);
        return LT_INC_AND_PAUSE;
    case 20:
        if (!ConditionMenu_UpdateMonEnter(GetConditionGraphPtr(), &menu->monTransitionX))
        {
            ResetConditionSparkleSprites(menu->conditionSparkleSprites);
            if (IsConditionMenuSearchMode() == TRUE || GetConditionGraphCurrentListIndex() != GetMonListCount())
                CreateConditionSparkleSprites(menu->conditionSparkleSprites, menu->monPicSpriteId, GetNumConditionMonSparkles());
            return LT_FINISH;
        }
        return LT_PAUSE;
    }
    return LT_FINISH;
}

u32 LoopedTask_ExitConditionGraphMenu(s32 state)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (state)
    {
    case 0:
        DoConditionGraphExitTransition();
        DestroyConditionSparkleSprites(menu->conditionSparkleSprites);
        return LT_INC_AND_CONTINUE;
    case 1:
        if (ConditionMenu_UpdateMonExit(GetConditionGraphPtr(), &menu->monTransitionX))
            return 2;
        ToggleGraphData(FALSE);
        return LT_INC_AND_CONTINUE;
    case 2:
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        if (!IsConditionMenuSearchMode())
            SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 3:
        if (IsPaletteFadeActive() || MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;
        FreeConditionSparkles(menu->conditionSparkleSprites);
        HideBg(1);
        HideBg(2);
        HideBg(3);
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}
u32 LoopedTask_TransitionMons(s32 state)
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

u32 LoopedTask_MoveCursorNoTransition(s32 state)
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

u32 LoopedTask_SlideMonOut(s32 state)
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

u32 LoopedTask_OpenMonMarkingsWindow(s32 state)
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

u32 LoopedTask_CloseMonMarkingsWindow(s32 state)
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

bool32 UpdateConditionGraphMenuWindows(u8 mode, u16 bufferIndex, bool8 winMode)
{
    u8 text[16];
    const u8 *str;
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);

    switch (mode)
    {
    case 0:
        FillWindowPixelBuffer(menu->nameGenderWindowId, 0);
        if (IsConditionMenuSearchMode() == TRUE)
            FillWindowPixelBuffer(menu->listIndexWindowId, 0);
        break;
    case 1:
        if (GetConditionGraphCurrentListIndex() != GetMonListCount() - 1 || IsConditionMenuSearchMode() == TRUE)
        {
            str = GetConditionMonNameText(bufferIndex);
            AddTextPrinterParameterized(menu->nameGenderWindowId, FONT_NORMAL, str, 0, 2, 0, NULL);
        }
        break;
    case 2:
        if (IsConditionMenuSearchMode() == TRUE)
        {
            str = GetConditionMonLocationText(bufferIndex);
            AddTextPrinterParameterized(menu->nameGenderWindowId, FONT_NORMAL, str, 0, 18, 0, NULL);
            text[0] = EXT_CTRL_CODE_BEGIN;
            text[1] = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
            text[2] = TEXT_COLOR_BLUE;
            text[3] = TEXT_COLOR_TRANSPARENT;
            text[4] = TEXT_COLOR_LIGHT_BLUE;
            UnusedPrintNumberString(&text[5], GetConditionMonDataBuffer());
            StringExpandPlaceholders(gStringVar4, text);
            AddTextPrinterParameterized(menu->listIndexWindowId, FONT_NORMAL, gStringVar4, 0, 2, 0, NULL);
        }
        break;
    case 3:
        switch (menu->windowModeState)
        {
        case 0:
            if (winMode)
                CopyWindowToVram(menu->nameGenderWindowId, COPYWIN_FULL);
            else
                CopyWindowToVram(menu->nameGenderWindowId, COPYWIN_GFX);

            if (IsConditionMenuSearchMode() == TRUE)
            {
                menu->windowModeState++;
                return FALSE;
            }
            else
            {
                menu->windowModeState = 0;
                return TRUE;
            }
        case 1:
            if (winMode)
                CopyWindowToVram(menu->listIndexWindowId, COPYWIN_FULL);
            else
                CopyWindowToVram(menu->listIndexWindowId, COPYWIN_GFX);

            menu->windowModeState = 0;
            return TRUE;
        }
    }

    return FALSE;
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

#endif
