#include "global.h"
#include "bg.h"
#include "data.h"
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
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "window.h"
#include "constants/songs.h"

#define CONDITION_MONS_LOADED 3

struct Pokenav_ConditionMenu
{
    u32 monPal[CONDITION_MONS_LOADED][0x20];
    u8 fill[0x180];
    u32 monPicGfx[CONDITION_MONS_LOADED][MON_PIC_SIZE];
    bool8 inSearchMode;
    s16 toLoadListIndex;
    u32 (*callback)(struct Pokenav_ConditionMenu *);
    u8 fill2[0x18];
    u8 locationText[CONDITION_MONS_LOADED][24];
    u8 nameText[CONDITION_MONS_LOADED][64];
    struct ConditionGraph graph;
    u8 numSparkles[CONDITION_MONS_LOADED];
    u8 monMarks[CONDITION_MONS_LOADED];
    s8 loadId;
    s8 nextLoadIdDown;
    s8 nextLoadIdUp;
    s8 toLoadId;
    u8 state;
};

static void InitPartyConditionListParameters(void);
static void InitSearchResultsConditionList(void);
static u32 HandleConditionMenuInput(struct Pokenav_ConditionMenu *);
static u32 GetConditionReturnCallback(struct Pokenav_ConditionMenu *);
static u32 OpenMarkingsMenu(struct Pokenav_ConditionMenu *);
static u8 ConditionGraphHandleDpadInput(struct Pokenav_ConditionMenu *);
static u8 SwitchConditionSummaryIndex(bool8);
static void CopyMonNameGenderLocation(s16, u8);
static void GetMonConditionGraphData(s16, u8);
static void ConditionGraphDrawMonPic(s16, u8);



// JP ROM data tables (defined at fixed addresses in ld_script_jp.txt).
extern const struct BgTemplate sMenuBgTemplates[3];
extern const u32 gPokenavCondition_Gfx[];
extern const u32 sConditionGraphData_Gfx[];
extern const u32 gPokenavCondition_Tilemap[];
extern const u32 gPokenavOptions_Tilemap[];
extern const u16 gPokenavCondition_Pal[];
extern const u16 gConditionText_Pal[];
extern const u32 sConditionGraphData_Tilemap[];
extern const u16 gConditionGraphData_Pal[];
extern const struct WindowTemplate sMonNameGenderWindowTemplate;
extern const struct WindowTemplate sListIndexWindowTemplate;
extern const struct WindowTemplate sUnusedWindowTemplate1;
extern const struct WindowTemplate sUnusedWindowTemplate2;
extern const LoopedTask sLoopedTaskFuncs[];

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

static u32 LoopedTask_OpenConditionGraphMenu(s32);
static u32 GetConditionGraphMenuLoopedTaskActive(void);
static u32 LoopedTask_ExitConditionGraphMenu(s32);
static bool32 IsSearchResultLoopedTaskActive(void);

bool32 PokenavCallback_Init_ConditionGraph_Party(void)
{
    struct Pokenav_ConditionMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU, sizeof(struct Pokenav_ConditionMenu));

    if (menu == NULL)
        return FALSE;

    ConditionGraph_Init(&menu->graph);
    InitPartyConditionListParameters();
    gKeyRepeatStartDelay = 20;
    menu->callback = HandleConditionMenuInput;
    return TRUE;
}

bool32 PokenavCallback_Init_ConditionGraph_Search(void)
{
    struct Pokenav_ConditionMenu *menu = AllocSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU, sizeof(struct Pokenav_ConditionMenu));

    if (menu == NULL)
        return FALSE;

    ConditionGraph_Init(&menu->graph);
    InitSearchResultsConditionList();
    gKeyRepeatStartDelay = 20;
    menu->callback = HandleConditionMenuInput;
    return TRUE;
}

u32 GetConditionGraphMenuCallback(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);

    return menu->callback(menu);
}

static u32 HandleConditionMenuInput(struct Pokenav_ConditionMenu *menu)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    u32 ret = ConditionGraphHandleDpadInput(menu);

    if (ret == CONDITION_FUNC_NONE)
    {
        if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            menu->callback = GetConditionReturnCallback;
            ret = CONDITION_FUNC_RETURN;
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (!menu->inSearchMode)
            {
                // In Party mode, pressing A only applies to the Cancel button
                if (monListPtr->currIndex == monListPtr->listCount - 1)
                {
                    // Cancel
                    PlaySE(SE_SELECT);
                    menu->callback = GetConditionReturnCallback;
                    ret = CONDITION_FUNC_RETURN;
                }
            }
            else
            {
                // In Search mode pressing A brings up the markings menu
                PlaySE(SE_SELECT);
                ret = CONDITION_FUNC_ADD_MARKINGS;
                menu->callback = OpenMarkingsMenu;
            }
        }
    }

    return ret;
}

static u32 OpenMarkingsMenu(struct Pokenav_ConditionMenu *menu)
{
    struct PokenavMonList *monListPtr;
    u8 markings;
    u32 ret = CONDITION_FUNC_NONE, boxId, monId;

    if (!HandleMonMarkingsMenuInput())
    {
        menu->monMarks[menu->loadId] = GetMonMarkingsData();
        monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
        boxId = monListPtr->monData[monListPtr->currIndex].boxId;
        monId = monListPtr->monData[monListPtr->currIndex].monId;
        markings = menu->monMarks[menu->loadId];

        if (boxId == TOTAL_BOXES_COUNT)
            SetMonData(&gPlayerParty[monId], MON_DATA_MARKINGS, &markings);
        else
            SetBoxMonDataAt(boxId, monId, MON_DATA_MARKINGS, &markings);

        menu->callback = HandleConditionMenuInput;
        ret = CONDITION_FUNC_CLOSE_MARKINGS;
    }

    return ret;
}

static u32 GetConditionReturnCallback(struct Pokenav_ConditionMenu *menu)
{
    if (!menu->inSearchMode)
        return POKENAV_CONDITION_MENU;
    else
        return POKENAV_RETURN_CONDITION_SEARCH;
}

void FreeConditionGraphMenuSubstruct1(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    if (!menu->inSearchMode)
        FreePokenavSubstruct(POKENAV_SUBSTRUCT_MON_LIST);

    FreePokenavSubstruct(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
}

static u8 ConditionGraphHandleDpadInput(struct Pokenav_ConditionMenu *menu)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    u8 ret = CONDITION_FUNC_NONE;

    if (JOY_HELD(DPAD_UP))
    {
        // Prevent input wrapping in search mode
        if (!menu->inSearchMode || monListPtr->currIndex != 0)
        {
            PlaySE(SE_SELECT);
            ret = SwitchConditionSummaryIndex(TRUE);
        }
    }
    else if (JOY_HELD(DPAD_DOWN))
    {
        // Prevent input wrapping in search mode
        if (!menu->inSearchMode || monListPtr->currIndex < monListPtr->listCount - 1)
        {
            PlaySE(SE_SELECT);
            ret = SwitchConditionSummaryIndex(FALSE);
        }
    }

    return ret;
}

static u8 SwitchConditionSummaryIndex(u8 moveUp)
{
    u16 newLoadId;
    bool8 wasNotLastMon, isNotLastMon;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    newLoadId = (moveUp) ? menu->nextLoadIdUp : menu->nextLoadIdDown;
    ConditionGraph_SetNewPositions(&menu->graph, menu->graph.savedPositions[menu->loadId], menu->graph.savedPositions[newLoadId]);
    wasNotLastMon = (monListPtr->currIndex != (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1));
    if (moveUp)
    {
        menu->nextLoadIdUp = menu->nextLoadIdDown;
        menu->nextLoadIdDown = menu->loadId;
        menu->loadId = newLoadId;
        menu->toLoadId = menu->nextLoadIdUp;

        monListPtr->currIndex = (monListPtr->currIndex == 0) ? monListPtr->listCount - 1 : monListPtr->currIndex - 1;
        menu->toLoadListIndex = (monListPtr->currIndex != 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1;
    }
    else
    {
        menu->nextLoadIdDown = menu->nextLoadIdUp;
        menu->nextLoadIdUp = menu->loadId;
        menu->loadId = newLoadId;
        menu->toLoadId = menu->nextLoadIdDown;

        monListPtr->currIndex = (monListPtr->currIndex < monListPtr->listCount - 1) ? monListPtr->currIndex + 1 : 0;
        menu->toLoadListIndex = (monListPtr->currIndex < monListPtr->listCount - 1) ? monListPtr->currIndex + 1 : 0;
    }

    isNotLastMon = (monListPtr->currIndex != (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1));

    if (!wasNotLastMon)
        return CONDITION_FUNC_NO_TRANSITION;
    else if (!isNotLastMon)
        return CONDITION_FUNC_SLIDE_MON_OUT;
    else
        return CONDITION_FUNC_SLIDE_MON_IN;
}

bool32 LoadConditionGraphMenuGfx(void)
{
    s32 var;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    switch (menu->state)
    {
    case 0:
        CopyMonNameGenderLocation(monListPtr->currIndex, 0);
        break;
    case 1:
        GetMonConditionGraphData(monListPtr->currIndex, 0);
        break;
    case 2:
        ConditionGraphDrawMonPic(monListPtr->currIndex, 0);
        break;
    case 3:
        if (monListPtr->listCount == 1)
        {
            menu->loadId = 0;
            menu->nextLoadIdDown = 0;
            menu->nextLoadIdUp = 0;
            menu->state = 0;
            return TRUE;
        }
        else
        {
            menu->loadId = 0;
            menu->nextLoadIdDown = 1;
            menu->nextLoadIdUp = 2;
        }
        break;
    // These were probably ternaries just like cases 7-9, but couldn't match it any other way.
    case 4:
        var = monListPtr->currIndex + 1;
        if (var >= monListPtr->listCount)
            var = 0;
        CopyMonNameGenderLocation(var, 1);
        break;
    case 5:
        var = monListPtr->currIndex + 1;
        if (var >= monListPtr->listCount)
            var = 0;
        GetMonConditionGraphData(var, 1);
        break;
    case 6:
        var = monListPtr->currIndex + 1;
        if (var >= monListPtr->listCount)
            var = 0;
        ConditionGraphDrawMonPic(var, 1);
        break;
    case 7:
        CopyMonNameGenderLocation((monListPtr->currIndex - 1 >= 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1, 2);
        break;
    case 8:
        GetMonConditionGraphData((monListPtr->currIndex - 1 >= 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1, 2);
        break;
    case 9:
        ConditionGraphDrawMonPic((monListPtr->currIndex - 1 >= 0) ? monListPtr->currIndex - 1 : monListPtr->listCount - 1, 2);
        menu->state = 0;
        return TRUE;
    }

    menu->state++;
    return FALSE;
}

bool32 LoadNextConditionMenuMonData(u8 mode)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);

    switch (mode)
    {
    case CONDITION_LOAD_MON_INFO:
        CopyMonNameGenderLocation(menu->toLoadListIndex, menu->toLoadId);
        break;
    case CONDITION_LOAD_GRAPH:
        GetMonConditionGraphData(menu->toLoadListIndex, menu->toLoadId);
        break;
    case CONDITION_LOAD_MON_PIC:
        ConditionGraphDrawMonPic(menu->toLoadListIndex, menu->toLoadId);
        return TRUE;
    }

    return FALSE;
}

__attribute__((naked)) void sub_081CCD0C(u8 *dest, const u8 *src, u16 count)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, lr}\n\t"
            "adds r4, r0, #0\n\t"
            "lsls r2, r2, #0x10\n\t"
            "lsrs r2, r2, #0x10\n\t"
            "b _081CCD24\n\t"
            "_081CCD16:\n\t"
            "strb r3, [r4]\n\t"
            "adds r1, #1\n\t"
            "adds r4, #1\n\t"
            "lsls r0, r2, #0x10\n\t"
            "ldr r2, _081CCD60\n\t"
            "adds r0, r0, r2\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "_081CCD24:\n\t"
            "ldrb r3, [r1]\n\t"
            "adds r0, r3, #0\n\t"
            "cmp r0, #0xff\n\t"
            "bne _081CCD16\n\t"
            "adds r1, r2, #0\n\t"
            "lsls r0, r1, #0x10\n\t"
            "ldr r2, _081CCD60\n\t"
            "adds r0, r0, r2\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "lsls r1, r1, #0x10\n\t"
            "cmp r1, #0\n\t"
            "ble _081CCD52\n\t"
            "movs r3, #0\n\t"
            "_081CCD3E:\n\t"
            "strb r3, [r4]\n\t"
            "adds r4, #1\n\t"
            "adds r1, r2, #0\n\t"
            "lsls r0, r1, #0x10\n\t"
            "ldr r2, _081CCD60\n\t"
            "adds r0, r0, r2\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "lsls r1, r1, #0x10\n\t"
            "cmp r1, #0\n\t"
            "bgt _081CCD3E\n\t"
            "_081CCD52:\n\t"
            "movs r0, #0xff\n\t"
            "strb r0, [r4]\n\t"
            "adds r0, r4, #0\n\t"
            "pop {r4}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            "_081CCD60: .4byte 0xFFFF0000");
}

__attribute__((naked)) void sub_081CCD64(u8 *dest, u16 boxId, u8 unused)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "adds r5, r0, #0\n\t"
            "adds r4, r1, #0\n\t"
            "lsls r4, r4, #0x10\n\t"
            "lsrs r4, r4, #0x10\n\t"
            "lsls r2, r2, #0x18\n\t"
            "lsrs r2, r2, #0x18\n\t"
            "mov sl, r2\n\t"
            "movs r0, #0x12\n\t"
            "bl GetSubstructPtr\n\t"
            "lsls r4, r4, #2\n\t"
            "adds r0, r0, r4\n\t"
            "ldrb r4, [r0, #4]\n\t"
            "mov r8, r4\n\t"
            "ldrb r6, [r0, #5]\n\t"
            "mov sb, r6\n\t"
            "movs r0, #0xfc\n\t"
            "strb r0, [r5]\n\t"
            "adds r5, #1\n\t"
            "movs r0, #4\n\t"
            "strb r0, [r5]\n\t"
            "adds r5, #1\n\t"
            "movs r0, #8\n\t"
            "strb r0, [r5]\n\t"
            "adds r5, #1\n\t"
            "movs r0, #0\n\t"
            "strb r0, [r5]\n\t"
            "adds r5, #1\n\t"
            "movs r0, #9\n\t"
            "strb r0, [r5]\n\t"
            "adds r5, #1\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r6, #0\n\t"
            "movs r2, #0x2d\n\t"
            "movs r3, #0\n\t"
            "bl GetBoxOrPartyMonData\n\t"
            "cmp r0, #0\n\t"
            "beq _081CCDD0\n\t"
            "ldr r1, _081CCDCC\n\t"
            "adds r0, r5, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0xc\n\t"
            "bl StringCopyPadded\n\t"
            "b _081CCF6C\n\t"
            ".align 2, 0\n\t"
            "_081CCDCC: .4byte 0x085C8C62\n\t"
            "_081CCDD0:\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r6, #0\n\t"
            "movs r2, #2\n\t"
            "adds r3, r5, #0\n\t"
            "bl GetBoxOrPartyMonData\n\t"
            "adds r0, r5, #0\n\t"
            "bl StringGet_Nickname\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r6, #0\n\t"
            "movs r2, #0xb\n\t"
            "movs r3, #0\n\t"
            "bl GetBoxOrPartyMonData\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r7, r0, #0x10\n\t"
            "cmp r4, #0xe\n\t"
            "bne _081CCE20\n\t"
            "movs r0, #0x64\n\t"
            "adds r4, r6, #0\n\t"
            "muls r4, r0, r4\n\t"
            "ldr r0, _081CCE1C\n\t"
            "adds r4, r4, r0\n\t"
            "adds r0, r4, #0\n\t"
            "movs r1, #0x38\n\t"
            "bl GetMonData3\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r0, r0, #0x10\n\t"
            "mov r8, r0\n\t"
            "adds r0, r4, #0\n\t"
            "bl GetMonGender\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r6, r0, #0x18\n\t"
            "b _081CCE3E\n\t"
            ".align 2, 0\n\t"
            "_081CCE1C: .4byte 0x02024190\n\t"
            "_081CCE20:\n\t"
            "mov r0, r8\n\t"
            "mov r1, sb\n\t"
            "bl GetBoxedMonPtr\n\t"
            "adds r4, r0, #0\n\t"
            "bl GetBoxMonGender\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r6, r0, #0x18\n\t"
            "adds r0, r4, #0\n\t"
            "bl GetLevelFromBoxMonExp\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "mov r8, r0\n\t"
            "_081CCE3E:\n\t"
            "cmp r7, #0x1d\n\t"
            "beq _081CCE46\n\t"
            "cmp r7, #0x20\n\t"
            "bne _081CCE5C\n\t"
            "_081CCE46:\n\t"
            "lsls r1, r7, #1\n\t"
            "adds r1, r1, r7\n\t"
            "lsls r1, r1, #1\n\t"
            "ldr r0, _081CCE64\n\t"
            "adds r1, r1, r0\n\t"
            "adds r0, r5, #0\n\t"
            "bl StringCompare\n\t"
            "cmp r0, #0\n\t"
            "bne _081CCE5C\n\t"
            "movs r6, #0xff\n\t"
            "_081CCE5C:\n\t"
            "adds r3, r5, #0\n\t"
            "movs r4, #0\n\t"
            "b _081CCE70\n\t"
            ".align 2, 0\n\t"
            "_081CCE64: .4byte 0x082EA31C\n\t"
            "_081CCE68:\n\t"
            "adds r3, #1\n\t"
            "adds r0, r4, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r4, r0, #0x10\n\t"
            "_081CCE70:\n\t"
            "ldrb r0, [r3]\n\t"
            "cmp r0, #0xff\n\t"
            "bne _081CCE68\n\t"
            "adds r1, r4, #0\n\t"
            "adds r0, r1, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r4, r0, #0x10\n\t"
            "cmp r1, #4\n\t"
            "bhi _081CCE94\n\t"
            "movs r2, #0\n\t"
            "_081CCE84:\n\t"
            "strb r2, [r3]\n\t"
            "adds r3, #1\n\t"
            "adds r1, r4, #0\n\t"
            "adds r0, r1, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r4, r0, #0x10\n\t"
            "cmp r1, #4\n\t"
            "bls _081CCE84\n\t"
            "_081CCE94:\n\t"
            "movs r0, #0\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "cmp r6, #0\n\t"
            "beq _081CCEA4\n\t"
            "cmp r6, #0xfe\n\t"
            "beq _081CCECA\n\t"
            "b _081CCEEE\n\t"
            "_081CCEA4:\n\t"
            "movs r1, #0xfc\n\t"
            "strb r1, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #1\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #4\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "strb r1, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #3\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #5\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #0xb5\n\t"
            "b _081CCEEE\n\t"
            "_081CCECA:\n\t"
            "movs r1, #0xfc\n\t"
            "strb r1, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #1\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #6\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "strb r1, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #3\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #7\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #0xb6\n\t"
            "_081CCEEE:\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #0xfc\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #4\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #8\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r5, #0\n\t"
            "strb r5, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #9\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #0xba\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #0xf9\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #5\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "adds r4, r3, #0\n\t"
            "adds r0, r4, #0\n\t"
            "mov r1, r8\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "adds r3, r0, #0\n\t"
            "subs r4, r3, r4\n\t"
            "lsls r4, r4, #0x10\n\t"
            "lsrs r4, r4, #0x10\n\t"
            "strb r5, [r3]\n\t"
            "adds r3, #1\n\t"
            "mov r0, sl\n\t"
            "cmp r0, #0\n\t"
            "bne _081CCF66\n\t"
            "movs r0, #3\n\t"
            "subs r0, r0, r4\n\t"
            "lsls r0, r0, #0x10\n\t"
            "ldr r1, _081CCF7C\n\t"
            "adds r0, r0, r1\n\t"
            "lsrs r4, r0, #0x10\n\t"
            "ldr r0, _081CCF80\n\t"
            "cmp r4, r0\n\t"
            "beq _081CCF66\n\t"
            "movs r2, #0\n\t"
            "adds r1, r0, #0\n\t"
            "_081CCF58:\n\t"
            "strb r2, [r3]\n\t"
            "adds r3, #1\n\t"
            "subs r0, r4, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r4, r0, #0x10\n\t"
            "cmp r4, r1\n\t"
            "bne _081CCF58\n\t"
            "_081CCF66:\n\t"
            "movs r0, #0xff\n\t"
            "strb r0, [r3]\n\t"
            "adds r0, r3, #0\n\t"
            "_081CCF6C:\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            "_081CCF7C: .4byte 0xFFFF0000\n\t"
            "_081CCF80: .4byte 0x0000FFFF\n\t"
            ".syntax divided");
}

__attribute__((naked)) void CopyMonNameGenderLocation(s16 listId, u8 loadId)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, r8\n\t"
            "push {r7}\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r0, r0, #0x10\n\t"
            "mov r8, r0\n\t"
            "lsls r1, r1, #0x18\n\t"
            "lsrs r6, r1, #0x18\n\t"
            "movs r0, #0xb\n\t"
            "bl GetSubstructPtr\n\t"
            "adds r5, r0, #0\n\t"
            "movs r0, #0x12\n\t"
            "bl GetSubstructPtr\n\t"
            "adds r7, r0, #0\n\t"
            "mov r1, r8\n\t"
            "lsls r0, r1, #0x10\n\t"
            "asrs r4, r0, #0x10\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #0\n\t"
            "beq _081CCFBA\n\t"
            "ldrh r2, [r7]\n\t"
            "cmp r4, r2\n\t"
            "bne _081CCFC2\n\t"
            "b _081CD060\n\t"
            "_081CCFBA:\n\t"
            "ldrh r0, [r7]\n\t"
            "subs r0, #1\n\t"
            "cmp r4, r0\n\t"
            "beq _081CD060\n\t"
            "_081CCFC2:\n\t"
            "lsls r0, r6, #6\n\t"
            "ldr r1, _081CD024\n\t"
            "adds r0, r0, r1\n\t"
            "adds r0, r5, r0\n\t"
            "mov r2, r8\n\t"
            "lsls r4, r2, #0x10\n\t"
            "lsrs r1, r4, #0x10\n\t"
            "movs r2, #0\n\t"
            "bl sub_081CCD64\n\t"
            "asrs r4, r4, #0xe\n\t"
            "adds r4, r7, r4\n\t"
            "ldrb r3, [r4, #4]\n\t"
            "lsls r0, r6, #1\n\t"
            "adds r0, r0, r6\n\t"
            "lsls r4, r0, #3\n\t"
            "ldr r1, _081CD028\n\t"
            "adds r0, r5, r1\n\t"
            "adds r0, r0, r4\n\t"
            "movs r2, #0\n\t"
            "movs r1, #0xfc\n\t"
            "strb r1, [r0]\n\t"
            "ldr r1, _081CD02C\n\t"
            "adds r0, r5, r1\n\t"
            "adds r0, r0, r4\n\t"
            "movs r1, #4\n\t"
            "strb r1, [r0]\n\t"
            "ldr r1, _081CD030\n\t"
            "adds r0, r5, r1\n\t"
            "adds r0, r0, r4\n\t"
            "movs r1, #8\n\t"
            "strb r1, [r0]\n\t"
            "ldr r1, _081CD034\n\t"
            "adds r0, r5, r1\n\t"
            "adds r0, r0, r4\n\t"
            "strb r2, [r0]\n\t"
            "ldr r2, _081CD038\n\t"
            "adds r0, r5, r2\n\t"
            "adds r0, r0, r4\n\t"
            "movs r1, #9\n\t"
            "strb r1, [r0]\n\t"
            "cmp r3, #0xe\n\t"
            "bne _081CD044\n\t"
            "adds r0, r4, r5\n\t"
            "ldr r1, _081CD03C\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r1, _081CD040\n\t"
            "b _081CD054\n\t"
            ".align 2, 0\n\t"
            "_081CD024: .4byte 0x00006368\n\t"
            "_081CD028: .4byte 0x00006320\n\t"
            "_081CD02C: .4byte 0x00006321\n\t"
            "_081CD030: .4byte 0x00006322\n\t"
            "_081CD034: .4byte 0x00006323\n\t"
            "_081CD038: .4byte 0x00006324\n\t"
            "_081CD03C: .4byte 0x00006325\n\t"
            "_081CD040: .4byte 0x085CB7C6\n\t"
            "_081CD044:\n\t"
            "adds r4, r4, r5\n\t"
            "ldr r2, _081CD05C\n\t"
            "adds r4, r4, r2\n\t"
            "adds r0, r3, #0\n\t"
            "bl GetBoxNamePtr\n\t"
            "adds r1, r0, #0\n\t"
            "adds r0, r4, #0\n\t"
            "_081CD054:\n\t"
            "movs r2, #8\n\t"
            "bl sub_081CCD0C\n\t"
            "b _081CD0BC\n\t"
            ".align 2, 0\n\t"
            "_081CD05C: .4byte 0x00006325\n\t"
            "_081CD060:\n\t"
            "movs r1, #0\n\t"
            "lsls r4, r6, #6\n\t"
            "lsls r0, r6, #1\n\t"
            "mov r8, r0\n\t"
            "adds r3, r4, #0\n\t"
            "ldr r0, _081CD0C8\n\t"
            "adds r2, r5, r0\n\t"
            "movs r7, #0\n\t"
            "_081CD070:\n\t"
            "adds r0, r1, r3\n\t"
            "adds r0, r2, r0\n\t"
            "strb r7, [r0]\n\t"
            "adds r0, r1, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r1, r0, #0x10\n\t"
            "cmp r1, #0xb\n\t"
            "bls _081CD070\n\t"
            "adds r1, r1, r4\n\t"
            "ldr r2, _081CD0C8\n\t"
            "adds r0, r5, r2\n\t"
            "adds r0, r0, r1\n\t"
            "movs r1, #0xff\n\t"
            "strb r1, [r0]\n\t"
            "movs r1, #0\n\t"
            "mov r2, r8\n\t"
            "adds r0, r2, r6\n\t"
            "lsls r3, r0, #3\n\t"
            "ldr r0, _081CD0CC\n\t"
            "adds r2, r5, r0\n\t"
            "movs r4, #0\n\t"
            "_081CD09A:\n\t"
            "adds r0, r1, r3\n\t"
            "adds r0, r2, r0\n\t"
            "strb r4, [r0]\n\t"
            "adds r0, r1, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r1, r0, #0x10\n\t"
            "cmp r1, #7\n\t"
            "bls _081CD09A\n\t"
            "mov r2, r8\n\t"
            "adds r0, r2, r6\n\t"
            "lsls r0, r0, #3\n\t"
            "adds r0, r1, r0\n\t"
            "ldr r2, _081CD0CC\n\t"
            "adds r1, r5, r2\n\t"
            "adds r1, r1, r0\n\t"
            "movs r0, #0xff\n\t"
            "strb r0, [r1]\n\t"
            "_081CD0BC:\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081CD0C8: .4byte 0x00006368\n\t"
            "_081CD0CC: .4byte 0x00006320\n\t"
            ".syntax divided");
}

static void InitPartyConditionListParameters(void)
{
    u16 i, count;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = AllocSubstruct(POKENAV_SUBSTRUCT_MON_LIST, sizeof(struct PokenavMonList));

    menu->inSearchMode = FALSE;
    for (i = 0, count = 0; i < CalculatePlayerPartyCount(); i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG))
        {
            monListPtr->monData[count].boxId = TOTAL_BOXES_COUNT;
            monListPtr->monData[count].monId = i;
            monListPtr->monData[count].data = 0;
            count++;
        }
    }

    monListPtr->monData[count].boxId = 0;
    monListPtr->monData[count].monId = 0;
    monListPtr->monData[count].data = 0;
    monListPtr->currIndex = 0;
    monListPtr->listCount = count + 1;
    menu->state = 0;
}

static void InitSearchResultsConditionList(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    menu->inSearchMode = TRUE;
    menu->state = 0;
}

static void GetMonConditionGraphData(s16 listId, u8 loadId)
{
    u16 boxId, monId, i;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    if (listId != (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1))
    {
        boxId = monListPtr->monData[listId].boxId;
        monId = monListPtr->monData[listId].monId;
        menu->graph.conditions[loadId][CONDITION_COOL] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_COOL, NULL);
        menu->graph.conditions[loadId][CONDITION_TOUGH] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_TOUGH, NULL);
        menu->graph.conditions[loadId][CONDITION_SMART] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SMART, NULL);
        menu->graph.conditions[loadId][CONDITION_CUTE] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_CUTE, NULL);
        menu->graph.conditions[loadId][CONDITION_BEAUTY] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_BEAUTY, NULL);
        menu->numSparkles[loadId] = GET_NUM_CONDITION_SPARKLES(GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL));
        menu->monMarks[loadId] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_MARKINGS, NULL);
        ConditionGraph_CalcPositions(menu->graph.conditions[loadId], menu->graph.savedPositions[loadId]);
    }
    else
    {
        // Set empty graph point
        for (i = 0; i < CONDITION_COUNT; i++)
        {
            menu->graph.conditions[loadId][i] = 0;
            menu->graph.savedPositions[loadId][i].x = CONDITION_GRAPH_CENTER_X;
            menu->graph.savedPositions[loadId][i].y = CONDITION_GRAPH_CENTER_Y;
        }
    }
}

static void ConditionGraphDrawMonPic(s16 listId, u8 loadId)
{
    u16 boxId, monId, species;
    u32 personality, tid;
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);

    if (listId == (IsConditionMenuSearchMode() ? monListPtr->listCount : monListPtr->listCount - 1))
        return;

    boxId = monListPtr->monData[listId].boxId;
    monId = monListPtr->monData[listId].monId;
    species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES_OR_EGG, NULL);
    tid = GetBoxOrPartyMonData(boxId, monId, MON_DATA_OT_ID, NULL);
    personality = GetBoxOrPartyMonData(boxId, monId, MON_DATA_PERSONALITY, NULL);
    LoadSpecialPokePic(&gMonFrontPicTable[species], menu->monPicGfx[loadId], species, personality, TRUE);
    LZ77UnCompWram(GetMonSpritePalFromSpeciesAndPersonality(species, tid, personality), menu->monPal[loadId]);
}

u16 GetMonListCount(void)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->listCount;
}

u16 GetConditionGraphCurrentListIndex(void)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->currIndex;
}

struct ConditionGraph *GetConditionGraphPtr(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return &menu->graph;
}

u8 GetConditionGraphMenuCurrentLoadIndex(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->loadId;
}

u8 GetConditionGraphMenuToLoadListIndex(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->toLoadListIndex;
}

void *GetConditionMonPicGfx(u8 loadId)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->monPicGfx[loadId];
}

void *GetConditionMonPal(u8 loadId)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->monPal[loadId];
}

u8 GetConditionGraphMenuToLoadId(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->toLoadId;
}

u8 *GetConditionMonNameText(u8 loadId)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->nameText[loadId];
}

u8 *GetConditionMonLocationText(u8 loadId)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->locationText[loadId];
}

u16 GetConditionMonDataBuffer(void)
{
    struct PokenavMonList *monListPtr = GetSubstructPtr(POKENAV_SUBSTRUCT_MON_LIST);
    return monListPtr->monData[monListPtr->currIndex].data;
}

bool32 IsConditionMenuSearchMode(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    if (menu->inSearchMode == TRUE)
        return TRUE;
    else
        return FALSE;
}

u8 TryGetMonMarkId(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    if (menu->inSearchMode == TRUE)
        return menu->monMarks[menu->loadId];
    else
        return 0;
}

u8 GetNumConditionMonSparkles(void)
{
    struct Pokenav_ConditionMenu *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU);
    return menu->numSparkles[menu->loadId];
}

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

__attribute__((naked)) bool32 IsSearchResultLoopedTaskActive(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {lr}\n\t"
            "movs r0, #0xc\n\t"
            "bl GetSubstructPtr\n\t"
            "ldr r1, _081CD5DC\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r0, [r0]\n\t"
            "bl _call_via_r0\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            "_081CD5DC: .4byte 0x00001810\n\t"
            ".syntax divided");
}

// JP-only alias: the `bx r1` at the end of IsSearchResultLoopedTaskActive is
// also labeled sub_081CD5D8 (0x081CD5D8) in the JP ROM.  No separate code.
__asm__(".set sub_081CD5D8, IsSearchResultLoopedTaskActive + 0x14");

static u32 GetConditionGraphMenuLoopedTaskActive(void)
{
    struct Pokenav_ConditionMenuGfx *menu = GetSubstructPtr(POKENAV_SUBSTRUCT_CONDITION_GRAPH_MENU_GFX);
    return IsLoopedTaskActive(menu->loopedTaskId);
}

__attribute__((naked)) u32 LoopedTask_OpenConditionGraphMenu(s32 state)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, lr}\n\t"
            "sub sp, #0xc\n\t"
            "adds r4, r0, #0\n\t"
            "movs r0, #0xc\n\t"
            "bl GetSubstructPtr\n\t"
            "adds r5, r0, #0\n\t"
            "cmp r4, #0x14\n\t"
            "bls _081CD608\n\t"
            "b _081CDA24\n\t"
            "_081CD608:\n\t"
            "lsls r0, r4, #2\n\t"
            "ldr r1, _081CD614\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r0, [r0]\n\t"
            "mov pc, r0\n\t"
            ".align 2, 0\n\t"
            "_081CD614: .4byte 0x081CD618\n\t"
            "_081CD618: @ jump table\n\t"
            ".4byte _081CD66C @ case 0\n\t"
            ".4byte _081CD678 @ case 1\n\t"
            ".4byte _081CD6F4 @ case 2\n\t"
            ".4byte _081CD718 @ case 3\n\t"
            ".4byte _081CD790 @ case 4\n\t"
            ".4byte _081CD7D4 @ case 5\n\t"
            ".4byte _081CD810 @ case 6\n\t"
            ".4byte _081CD878 @ case 7\n\t"
            ".4byte _081CD880 @ case 8\n\t"
            ".4byte _081CD886 @ case 9\n\t"
            ".4byte _081CD896 @ case 10\n\t"
            ".4byte _081CD8A6 @ case 11\n\t"
            ".4byte _081CD8B6 @ case 12\n\t"
            ".4byte _081CD8CC @ case 13\n\t"
            ".4byte _081CD928 @ case 14\n\t"
            ".4byte _081CD94C @ case 15\n\t"
            ".4byte _081CD978 @ case 16\n\t"
            ".4byte _081CD99C @ case 17\n\t"
            ".4byte _081CD9AA @ case 18\n\t"
            ".4byte _081CD9BA @ case 19\n\t"
            ".4byte _081CD9C2 @ case 20\n\t"
            "_081CD66C:\n\t"
            "bl LoadConditionGraphMenuGfx\n\t"
            "cmp r0, #1\n\t"
            "beq _081CD676\n\t"
            "b _081CDA20\n\t"
            "_081CD676:\n\t"
            "b _081CD710\n\t"
            "_081CD678:\n\t"
            "ldr r0, _081CD6E0\n\t"
            "movs r1, #3\n\t"
            "bl InitBgTemplates\n\t"
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
            "movs r0, #3\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgX\n\t"
            "movs r0, #3\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "bl ChangeBgY\n\t"
            "ldr r1, _081CD6E4\n\t"
            "movs r0, #0\n\t"
            "bl SetGpuReg\n\t"
            "ldr r1, _081CD6E8\n\t"
            "movs r0, #0x50\n\t"
            "bl SetGpuReg\n\t"
            "ldr r1, _081CD6EC\n\t"
            "movs r0, #0x52\n\t"
            "bl SetGpuReg\n\t"
            "ldr r1, _081CD6F0\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #3\n\t"
            "b _081CD708\n\t"
            ".align 2, 0\n\t"
            "_081CD6E0: .4byte 0x085F5964\n\t"
            "_081CD6E4: .4byte 0x00007940\n\t"
            "_081CD6E8: .4byte 0x00000844\n\t"
            "_081CD6EC: .4byte 0x0000040B\n\t"
            "_081CD6F0: .4byte 0x085F4E6C\n\t"
            "_081CD6F4:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "beq _081CD702\n\t"
            "b _081CDA20\n\t"
            "_081CD702:\n\t"
            "ldr r1, _081CD714\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #2\n\t"
            "_081CD708:\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0\n\t"
            "bl DecompressAndCopyTileDataToVram\n\t"
            "_081CD710:\n\t"
            "movs r0, #0\n\t"
            "b _081CDA26\n\t"
            ".align 2, 0\n\t"
            "_081CD714: .4byte 0x085F57EC\n\t"
            "_081CD718:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "beq _081CD724\n\t"
            "b _081CDA20\n\t"
            "_081CD724:\n\t"
            "ldr r0, _081CD778\n\t"
            "adds r4, r5, #4\n\t"
            "adds r1, r4, #0\n\t"
            "bl LZ77UnCompVram\n\t"
            "movs r0, #3\n\t"
            "adds r1, r4, #0\n\t"
            "bl SetBgTilemapBuffer\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "bne _081CD752\n\t"
            "ldr r1, _081CD77C\n\t"
            "movs r0, #9\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #4\n\t"
            "str r0, [sp, #4]\n\t"
            "movs r0, #3\n\t"
            "movs r2, #0\n\t"
            "movs r3, #5\n\t"
            "bl CopyToBgTilemapBufferRect\n\t"
            "_081CD752:\n\t"
            "movs r0, #3\n\t"
            "bl CopyBgTilemapBufferToVram\n\t"
            "ldr r0, _081CD780\n\t"
            "movs r1, #0x10\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "ldr r0, _081CD784\n\t"
            "movs r1, #0xf0\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "ldr r0, _081CD788\n\t"
            "adds r1, r5, r0\n\t"
            "ldr r0, _081CD78C\n\t"
            "strh r0, [r1]\n\t"
            "b _081CD710\n\t"
            ".align 2, 0\n\t"
            "_081CD778: .4byte 0x085F5600\n\t"
            "_081CD77C: .4byte 0x085F58FC\n\t"
            "_081CD780: .4byte 0x085F4E0C\n\t"
            "_081CD784: .4byte 0x085F4E4C\n\t"
            "_081CD788: .4byte 0x00001814\n\t"
            "_081CD78C: .4byte 0x0000FFB0\n\t"
            "_081CD790:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "beq _081CD79C\n\t"
            "b _081CDA20\n\t"
            "_081CD79C:\n\t"
            "ldr r0, _081CD7C8\n\t"
            "ldr r1, _081CD7CC\n\t"
            "adds r4, r5, r1\n\t"
            "adds r1, r4, #0\n\t"
            "bl LZ77UnCompVram\n\t"
            "movs r0, #2\n\t"
            "adds r1, r4, #0\n\t"
            "bl SetBgTilemapBuffer\n\t"
            "movs r0, #2\n\t"
            "bl CopyBgTilemapBufferToVram\n\t"
            "ldr r0, _081CD7D0\n\t"
            "movs r1, #0x30\n\t"
            "movs r2, #0x20\n\t"
            "bl CopyPaletteIntoBufferUnfaded\n\t"
            "movs r0, #2\n\t"
            "bl ConditionGraph_InitWindow\n\t"
            "b _081CD710\n\t"
            ".align 2, 0\n\t"
            "_081CD7C8: .4byte 0x085F5800\n\t"
            "_081CD7CC: .4byte 0x00001004\n\t"
            "_081CD7D0: .4byte 0x085F4E2C\n\t"
            "_081CD7D4:\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #1\n\t"
            "bl BgDmaFill\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0x11\n\t"
            "movs r2, #1\n\t"
            "movs r3, #1\n\t"
            "bl BgDmaFill\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp, #8]\n\t"
            "ldr r2, _081CD808\n\t"
            "adds r4, r5, r2\n\t"
            "ldr r2, _081CD80C\n\t"
            "add r0, sp, #8\n\t"
            "adds r1, r4, #0\n\t"
            "bl CpuSet\n\t"
            "movs r0, #1\n\t"
            "adds r1, r4, #0\n\t"
            "bl SetBgTilemapBuffer\n\t"
            "b _081CD710\n\t"
            ".align 2, 0\n\t"
            "_081CD808: .4byte 0x00000804\n\t"
            "_081CD80C: .4byte 0x05000200\n\t"
            "_081CD810:\n\t"
            "bl FreeTempTileDataBuffersIfPossible\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "beq _081CD81C\n\t"
            "b _081CDA20\n\t"
            "_081CD81C:\n\t"
            "ldr r0, _081CD85C\n\t"
            "bl AddWindow\n\t"
            "movs r2, #0xc1\n\t"
            "lsls r2, r2, #5\n\t"
            "adds r1, r5, r2\n\t"
            "strb r0, [r1]\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "bne _081CD856\n\t"
            "ldr r0, _081CD860\n\t"
            "bl AddWindow\n\t"
            "ldr r2, _081CD864\n\t"
            "adds r1, r5, r2\n\t"
            "strb r0, [r1]\n\t"
            "ldr r0, _081CD868\n\t"
            "bl AddWindow\n\t"
            "ldr r2, _081CD86C\n\t"
            "adds r1, r5, r2\n\t"
            "strb r0, [r1]\n\t"
            "ldr r0, _081CD870\n\t"
            "bl AddWindow\n\t"
            "ldr r2, _081CD874\n\t"
            "adds r1, r5, r2\n\t"
            "strb r0, [r1]\n\t"
            "_081CD856:\n\t"
            "bl DeactivateAllTextPrinters\n\t"
            "b _081CD710\n\t"
            ".align 2, 0\n\t"
            "_081CD85C: .4byte 0x085F5970\n\t"
            "_081CD860: .4byte 0x085F5978\n\t"
            "_081CD864: .4byte 0x00001821\n\t"
            "_081CD868: .4byte 0x085F5980\n\t"
            "_081CD86C: .4byte 0x00001822\n\t"
            "_081CD870: .4byte 0x085F5988\n\t"
            "_081CD874: .4byte 0x00001823\n\t"
            "_081CD878:\n\t"
            "movs r0, #0\n\t"
            "bl CreateConditionMonPic\n\t"
            "b _081CD710\n\t"
            "_081CD880:\n\t"
            "bl CreateMonMarkingsOrPokeballIndicators\n\t"
            "b _081CD710\n\t"
            "_081CD886:\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "beq _081CD890\n\t"
            "b _081CD710\n\t"
            "_081CD890:\n\t"
            "bl CopyUnusedConditionWindowsToVram\n\t"
            "b _081CD710\n\t"
            "_081CD896:\n\t"
            "bl GetConditionGraphMenuCurrentLoadIndex\n\t"
            "adds r1, r0, #0\n\t"
            "lsls r1, r1, #0x18\n\t"
            "asrs r1, r1, #8\n\t"
            "lsrs r1, r1, #0x10\n\t"
            "movs r0, #0\n\t"
            "b _081CD8C4\n\t"
            "_081CD8A6:\n\t"
            "bl GetConditionGraphMenuCurrentLoadIndex\n\t"
            "adds r1, r0, #0\n\t"
            "lsls r1, r1, #0x18\n\t"
            "asrs r1, r1, #8\n\t"
            "lsrs r1, r1, #0x10\n\t"
            "movs r0, #1\n\t"
            "b _081CD8C4\n\t"
            "_081CD8B6:\n\t"
            "bl GetConditionGraphMenuCurrentLoadIndex\n\t"
            "adds r1, r0, #0\n\t"
            "lsls r1, r1, #0x18\n\t"
            "asrs r1, r1, #8\n\t"
            "lsrs r1, r1, #0x10\n\t"
            "movs r0, #2\n\t"
            "_081CD8C4:\n\t"
            "movs r2, #1\n\t"
            "bl UpdateConditionGraphMenuWindows\n\t"
            "b _081CD710\n\t"
            "_081CD8CC:\n\t"
            "bl GetConditionGraphMenuCurrentLoadIndex\n\t"
            "adds r1, r0, #0\n\t"
            "lsls r1, r1, #0x18\n\t"
            "asrs r1, r1, #8\n\t"
            "lsrs r1, r1, #0x10\n\t"
            "movs r0, #3\n\t"
            "movs r2, #1\n\t"
            "bl UpdateConditionGraphMenuWindows\n\t"
            "cmp r0, #1\n\t"
            "beq _081CD8E6\n\t"
            "b _081CDA20\n\t"
            "_081CD8E6:\n\t"
            "movs r1, #0xc1\n\t"
            "lsls r1, r1, #5\n\t"
            "adds r0, r5, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "bl PutWindowTilemap\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "beq _081CD8FC\n\t"
            "b _081CD710\n\t"
            "_081CD8FC:\n\t"
            "ldr r2, _081CD91C\n\t"
            "adds r0, r5, r2\n\t"
            "ldrb r0, [r0]\n\t"
            "bl PutWindowTilemap\n\t"
            "ldr r1, _081CD920\n\t"
            "adds r0, r5, r1\n\t"
            "ldrb r0, [r0]\n\t"
            "bl PutWindowTilemap\n\t"
            "ldr r2, _081CD924\n\t"
            "adds r0, r5, r2\n\t"
            "ldrb r0, [r0]\n\t"
            "bl PutWindowTilemap\n\t"
            "b _081CD710\n\t"
            ".align 2, 0\n\t"
            "_081CD91C: .4byte 0x00001821\n\t"
            "_081CD920: .4byte 0x00001822\n\t"
            "_081CD924: .4byte 0x00001823\n\t"
            "_081CD928:\n\t"
            "movs r0, #1\n\t"
            "bl ShowBg\n\t"
            "movs r0, #2\n\t"
            "bl HideBg\n\t"
            "movs r0, #3\n\t"
            "bl ShowBg\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "beq _081CD944\n\t"
            "b _081CD710\n\t"
            "_081CD944:\n\t"
            "movs r0, #4\n\t"
            "bl PrintHelpBarText\n\t"
            "b _081CD710\n\t"
            "_081CD94C:\n\t"
            "movs r0, #1\n\t"
            "bl PokenavFadeScreen\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #0\n\t"
            "beq _081CD95C\n\t"
            "b _081CD710\n\t"
            "_081CD95C:\n\t"
            "movs r0, #6\n\t"
            "bl LoadLeftHeaderGfxForIndex\n\t"
            "movs r0, #1\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "bl ShowLeftHeaderGfx\n\t"
            "movs r0, #6\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "bl ShowLeftHeaderGfx\n\t"
            "b _081CD710\n\t"
            "_081CD978:\n\t"
            "bl IsPaletteFadeActive\n\t"
            "cmp r0, #0\n\t"
            "bne _081CDA20\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #0\n\t"
            "bne _081CD990\n\t"
            "bl AreLeftHeaderSpritesMoving\n\t"
            "cmp r0, #0\n\t"
            "bne _081CDA20\n\t"
            "_081CD990:\n\t"
            "ldr r0, _081CD998\n\t"
            "bl SetVBlankCallback_\n\t"
            "b _081CD710\n\t"
            ".align 2, 0\n\t"
            "_081CD998: .4byte 0x081CE579\n\t"
            "_081CD99C:\n\t"
            "bl DoConditionGraphEnterTransition\n\t"
            "bl GetConditionGraphPtr\n\t"
            "bl ConditionGraph_InitResetScanline\n\t"
            "b _081CD710\n\t"
            "_081CD9AA:\n\t"
            "bl GetConditionGraphPtr\n\t"
            "bl ConditionGraph_ResetScanline\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081CDA20\n\t"
            "b _081CD710\n\t"
            "_081CD9BA:\n\t"
            "movs r0, #1\n\t"
            "bl ToggleGraphData\n\t"
            "b _081CD710\n\t"
            "_081CD9C2:\n\t"
            "bl GetConditionGraphPtr\n\t"
            "ldr r2, _081CDA14\n\t"
            "adds r1, r5, r2\n\t"
            "bl ConditionMenu_UpdateMonEnter\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _081CDA20\n\t"
            "ldr r0, _081CDA18\n\t"
            "adds r6, r5, r0\n\t"
            "adds r0, r6, #0\n\t"
            "bl ResetConditionSparkleSprites\n\t"
            "bl IsConditionMenuSearchMode\n\t"
            "cmp r0, #1\n\t"
            "beq _081CD9F8\n\t"
            "bl GetConditionGraphCurrentListIndex\n\t"
            "adds r4, r0, #0\n\t"
            "bl GetMonListCount\n\t"
            "lsls r4, r4, #0x10\n\t"
            "lsls r0, r0, #0x10\n\t"
            "cmp r4, r0\n\t"
            "beq _081CDA24\n\t"
            "_081CD9F8:\n\t"
            "ldr r1, _081CDA1C\n\t"
            "adds r0, r5, r1\n\t"
            "ldrb r4, [r0]\n\t"
            "bl GetNumConditionMonSparkles\n\t"
            "adds r2, r0, #0\n\t"
            "lsls r2, r2, #0x18\n\t"
            "lsrs r2, r2, #0x18\n\t"
            "adds r0, r6, #0\n\t"
            "adds r1, r4, #0\n\t"
            "bl CreateConditionSparkleSprites\n\t"
            "b _081CDA24\n\t"
            ".align 2, 0\n\t"
            "_081CDA14: .4byte 0x00001814\n\t"
            "_081CDA18: .4byte 0x000028E0\n\t"
            "_081CDA1C: .4byte 0x00001816\n\t"
            "_081CDA20:\n\t"
            "movs r0, #2\n\t"
            "b _081CDA26\n\t"
            "_081CDA24:\n\t"
            "movs r0, #4\n\t"
            "_081CDA26:\n\t"
            "add sp, #0xc\n\t"
            "pop {r4, r5, r6}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            ".syntax divided");
}

static u32 LoopedTask_ExitConditionGraphMenu(s32 state)
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
