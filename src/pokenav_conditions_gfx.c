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
