#include "global.h"
#include "malloc.h"
#include "battle_main.h"
#include "contest_effect.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "menu.h"
#include "international_string_util.h"
#include "menu.h"
#include "menu_specialized.h"
#include "move_relearner.h"
#include "palette.h"
#include "player_pc.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/songs.h"
#include "gba/io_reg.h"

extern const struct CompressedSpriteSheet gMonFrontPicTable[];

extern EWRAM_DATA u8 sMailboxWindowIds[MAILBOXWIN_COUNT];
extern EWRAM_DATA struct ListMenuItem *sMailboxList;
extern const struct WindowTemplate sWindowTemplates_MailboxMenu[MAILBOXWIN_COUNT];
extern const struct ScanlineEffectParams sConditionGraphScanline;
extern const u8 sConditionToLineLength[MAX_CONDITION + 1];
extern const struct WindowTemplate sMoveRelearnerWindowTemplates[6];
extern const struct WindowTemplate sMoveRelearnerYesNoMenuTemplate;
extern const struct ListMenuTemplate sMoveRelearnerMovesListTemplate;
extern const struct SpriteTemplate sSpriteTemplate_ConditionSparkle;
extern const s16 sConditionSparkleCoords[MAX_CONDITION_SPARKLES][2];

static void MailboxMenu_MoveCursorFunc(s32, bool8, struct ListMenu *);
static void ConditionGraph_CalcRightHalf(struct ConditionGraph *);
static void ConditionGraph_CalcLeftHalf(struct ConditionGraph *);
static void SetNextConditionSparkle(struct Sprite *);
static void SpriteCB_ConditionSparkle(struct Sprite *);
static void ShowAllConditionSparkles(struct Sprite *);

//--------------
// Mailbox menu
//--------------

bool8 MailboxMenu_Alloc(u8 count)
{
    u8 i;

    // + 1 to count for 'Cancel'
    sMailboxList = Alloc((count + 1) * sizeof(*sMailboxList));
    if (sMailboxList == NULL)
        return FALSE;

    for (i = 0; i < ARRAY_COUNT(sMailboxWindowIds); i++)
        sMailboxWindowIds[i] = WINDOW_NONE;

    return TRUE;
}

u8 MailboxMenu_AddWindow(u8 windowIdx)
{
    if (sMailboxWindowIds[windowIdx] == WINDOW_NONE)
    {
        // JP build has no MAILBOXWIN_OPTIONS width adjustment.
        sMailboxWindowIds[windowIdx] = AddWindow(&sWindowTemplates_MailboxMenu[windowIdx]);
        SetStandardWindowBorderStyle(sMailboxWindowIds[windowIdx], FALSE);
    }
    return sMailboxWindowIds[windowIdx];
}

void MailboxMenu_RemoveWindow(u8 windowIdx)
{
    ClearStdWindowAndFrameToTransparent(sMailboxWindowIds[windowIdx], FALSE);
    ClearWindowTilemap(sMailboxWindowIds[windowIdx]);
    RemoveWindow(sMailboxWindowIds[windowIdx]);
    sMailboxWindowIds[windowIdx] = WINDOW_NONE;
}

static u8 UNUSED MailboxMenu_GetWindowId(u8 windowIdx)
{
    return sMailboxWindowIds[windowIdx];
}

// JP 0x081D13F4: the JP build lays the list item names out inside a
// separate 0x28-per-entry block (base at 0x03005AEC) and leaves
// itemPrintFunc unset, so this is kept as asm.
__attribute__((naked)) u8 MailboxMenu_CreateList(struct PlayerPCItemPageStruct *page)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "adds r7, r0, #0\n\t"
            "movs r3, #0\n\t"
            "ldr r0, _081D14A8\n\t"
            "mov r8, r0\n\t"
            "ldr r1, _081D14AC\n\t"
            "mov sb, r1\n\t"
            "ldr r6, _081D14B0\n\t"
            "ldr r0, _081D14B4\n\t"
            "mov sl, r0\n\t"
            "ldrb r1, [r7, #5]\n\t"
            "cmp r3, r1\n\t"
            "bhs _081D1440\n\t"
            "mov ip, r8\n\t"
            "ldr r5, _081D14B8\n\t"
            "ldr r4, _081D14BC\n\t"
            "_081D141C:\n\t"
            "mov r0, ip\n\t"
            "ldr r2, [r0]\n\t"
            "lsls r0, r3, #3\n\t"
            "adds r2, r0, r2\n\t"
            "adds r0, r0, r3\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r0, r0, r4\n\t"
            "ldr r1, [r5]\n\t"
            "adds r1, r1, r0\n\t"
            "adds r1, #0x12\n\t"
            "str r1, [r2]\n\t"
            "str r3, [r2, #4]\n\t"
            "adds r0, r3, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r3, r0, #0x10\n\t"
            "ldrb r1, [r7, #5]\n\t"
            "cmp r3, r1\n\t"
            "blo _081D141C\n\t"
            "_081D1440:\n\t"
            "mov r0, r8\n\t"
            "ldr r2, [r0]\n\t"
            "lsls r0, r3, #3\n\t"
            "adds r0, r0, r2\n\t"
            "mov r1, sb\n\t"
            "str r1, [r0]\n\t"
            "movs r1, #2\n\t"
            "rsbs r1, r1, #0\n\t"
            "str r1, [r0, #4]\n\t"
            "str r2, [r6]\n\t"
            "ldrb r0, [r7, #5]\n\t"
            "adds r0, #1\n\t"
            "movs r4, #0\n\t"
            "movs r5, #0\n\t"
            "strh r0, [r6, #0xc]\n\t"
            "mov r1, sl\n\t"
            "ldrb r0, [r1, #1]\n\t"
            "strb r0, [r6, #0x10]\n\t"
            "strb r4, [r6, #0x11]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0\n\t"
            "bl GetFontAttribute\n\t"
            "strb r0, [r6, #0x12]\n\t"
            "strb r4, [r6, #0x13]\n\t"
            "movs r0, #8\n\t"
            "strh r0, [r6, #0xe]\n\t"
            "movs r0, #0x2a\n\t"
            "strb r0, [r6, #0x14]\n\t"
            "movs r0, #0x31\n\t"
            "strb r0, [r6, #0x15]\n\t"
            "ldr r0, _081D14C0\n\t"
            "str r0, [r6, #4]\n\t"
            "str r5, [r6, #8]\n\t"
            "movs r0, #1\n\t"
            "strb r0, [r6, #0x17]\n\t"
            "movs r0, #0\n\t"
            "strb r0, [r6, #0x16]\n\t"
            "ldrh r1, [r7, #2]\n\t"
            "ldrh r2, [r7]\n\t"
            "adds r0, r6, #0\n\t"
            "bl ListMenuInit\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            "_081D14A8: .4byte sMailboxList\n\t"
            "_081D14AC: .4byte gText_Exit\n\t"
            "_081D14B0: .4byte gMultiuseListMenuTemplate\n\t"
            "_081D14B4: .4byte sMailboxWindowIds\n\t"
            "_081D14B8: .4byte gSaveBlock1Ptr\n\t"
            "_081D14BC: .4byte 0x00002CB8\n\t"
            "_081D14C0: .4byte MailboxMenu_MoveCursorFunc\n\t"
            ".syntax divided\n");
}

static void MailboxMenu_MoveCursorFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (onInit != TRUE)
        PlaySE(SE_SELECT);
}

void MailboxMenu_AddScrollArrows(struct PlayerPCItemPageStruct *page)
{
    page->scrollIndicatorTaskId = AddScrollIndicatorArrowPairParameterized(2, 0xC8, 12, 0x94, page->count - page->pageItems + 1, 0x6E, 0x6E, &page->itemsAbove);
}

void MailboxMenu_Free(void)
{
    Free(sMailboxList);
}

//---------------------------------------
// Condition graph
//
// This is the graph in the Pokénav and
// Pokéblock case that shows a Pokémon's
// conditions (Beauty, Tough, etc.).
// It works by using scanlines to
// selectively reveal a bg that has been
// filled with the graph color.
//---------------------------------------

#define SHIFT_RIGHT_ADJUSTED(n, s) (((n) >> (s)) + (((n) >> ((s) - 1)) & 1))

void ConditionGraph_Init(struct ConditionGraph *graph)
{
    u8 i, j;

    for (j = 0; j < CONDITION_COUNT; j++)
    {
        for (i = 0; i < CONDITION_GRAPH_UPDATE_STEPS; i++)
        {
            graph->newPositions[i][j].x = 0;
            graph->newPositions[i][j].y = 0;
        }

        for (i = 0; i < CONDITION_GRAPH_LOAD_MAX; i++)
        {
            graph->conditions[i][j] = 0;
            graph->savedPositions[i][j].x = CONDITION_GRAPH_CENTER_X;
            graph->savedPositions[i][j].y = CONDITION_GRAPH_CENTER_Y;
        }

        graph->curPositions[j].x = 0;
        graph->curPositions[j].y = 0;
    }

    graph->needsDraw = FALSE;
    graph->updateCounter = 0;
}

// Fills the newPositions array with incremental positions between
// old and new for the graph transition when switching between Pokémon.
void ConditionGraph_SetNewPositions(struct ConditionGraph *graph, struct UCoords16 *old, struct UCoords16 *new)
{
    u16 i, j;
    s32 coord, increment;

    for (i = 0; i < CONDITION_COUNT; i++)
    {
        coord = old[i].x << 8;
        increment = ((new[i].x - old[i].x) << 8) / CONDITION_GRAPH_UPDATE_STEPS;
        for (j = 0; j < CONDITION_GRAPH_UPDATE_STEPS - 1; j++)
        {
            graph->newPositions[j][i].x = SHIFT_RIGHT_ADJUSTED(coord, 8);
            coord += increment;
        }
        graph->newPositions[j][i].x = new[i].x;

        coord = old[i].y << 8;
        increment = ((new[i].y - old[i].y) << 8) / CONDITION_GRAPH_UPDATE_STEPS;
        for (j = 0; j < CONDITION_GRAPH_UPDATE_STEPS - 1; j++)
        {
            graph->newPositions[j][i].y = SHIFT_RIGHT_ADJUSTED(coord, 8);
            coord += increment;
        }
        graph->newPositions[j][i].y = new[i].y;
    }

    graph->updateCounter = 0;
}

bool8 ConditionGraph_TryUpdate(struct ConditionGraph *graph)
{
    if (graph->updateCounter < CONDITION_GRAPH_UPDATE_STEPS)
    {
        ConditionGraph_Update(graph);
        return (++graph->updateCounter != CONDITION_GRAPH_UPDATE_STEPS);
    }
    else
    {
        return FALSE;
    }
}

void ConditionGraph_InitResetScanline(struct ConditionGraph *graph)
{
    graph->scanlineResetState = 0;
}

bool8 ConditionGraph_ResetScanline(struct ConditionGraph *graph)
{
    struct ScanlineEffectParams params;

    switch (graph->scanlineResetState)
    {
    case 0:
        ScanlineEffect_Clear();
        graph->scanlineResetState++;
        return TRUE;
    case 1:
        params = sConditionGraphScanline;
        ScanlineEffect_SetParams(params);
        graph->scanlineResetState++;
        return FALSE;
    default:
        return FALSE;
    }
}

void ConditionGraph_Draw(struct ConditionGraph *graph)
{
    u16 i;

    if (!graph->needsDraw)
        return;

    ConditionGraph_CalcRightHalf(graph);
    ConditionGraph_CalcLeftHalf(graph);

    for (i = 0; i < CONDITION_GRAPH_HEIGHT; i++)
    {
        // Draw right half
        gScanlineEffectRegBuffers[1][(i + CONDITION_GRAPH_TOP_Y - 1) * 2 + 0] = // double assignment
        gScanlineEffectRegBuffers[0][(i + CONDITION_GRAPH_TOP_Y - 1) * 2 + 0] = (graph->scanlineRight[i][0] << 8) | (graph->scanlineRight[i][1]);
        // Draw left half
        gScanlineEffectRegBuffers[1][(i + CONDITION_GRAPH_TOP_Y - 1) * 2 + 1] = // double assignment
        gScanlineEffectRegBuffers[0][(i + CONDITION_GRAPH_TOP_Y - 1) * 2 + 1] = (graph->scanlineLeft[i][0] << 8) | (graph->scanlineLeft[i][1]);
    }

    graph->needsDraw = FALSE;
}

void ConditionGraph_InitWindow(u8 bg)
{
    u32 flags;

    if (bg >= NUM_BACKGROUNDS)
        bg = 0;

    // Unset the WINOUT flag for the bg.
    flags = (WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ) & ~(1 << bg);

    // Set limits for graph data
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE( 0, DISPLAY_WIDTH)); // Right side horizontal
    SetGpuReg(REG_OFFSET_WIN1H, WIN_RANGE( 0, CONDITION_GRAPH_CENTER_X)); // Left side horizontal
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(CONDITION_GRAPH_TOP_Y, CONDITION_GRAPH_BOTTOM_Y)); // Right side vertical
    SetGpuReg(REG_OFFSET_WIN1V, WIN_RANGE(CONDITION_GRAPH_TOP_Y, CONDITION_GRAPH_BOTTOM_Y)); // Left side vertical
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, flags);
}

void ConditionGraph_Update(struct ConditionGraph *graph)
{
    u16 i;
    for (i = 0; i < CONDITION_COUNT; i++)
        graph->curPositions[i] = graph->newPositions[graph->updateCounter][i];

    graph->needsDraw = TRUE;
}

static void ConditionGraph_CalcLine(struct ConditionGraph *graph, u16 *scanline, struct UCoords16 *pos1, struct UCoords16 *pos2, bool8 dir, u16 *overflowScanline)
{
    u16 i, height, top, bottom, x2;
    u16 *ptr;
    s32 x, xIncrement = 0;

    if (pos1->y < pos2->y)
    {
        top = pos1->y;
        bottom = pos2->y;
        x = pos1->x << 10;
        x2 = pos2->x;
        height = bottom - top;
        if (height != 0)
            xIncrement = ((x2 - pos1->x) << 10) / height;
    }
    else
    {
        bottom = pos1->y;
        top = pos2->y;
        x = pos2->x << 10;
        x2 = pos1->x;
        height = bottom - top;
        if (height != 0)
            xIncrement = ((x2 - pos2->x) << 10) / height;
    }

    height++;
    if (overflowScanline == NULL)
    {
        scanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        for (i = 0; i < height; i++)
        {
            scanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir;
            x += xIncrement;
            scanline += 2;
        }

        ptr = scanline - 2;
    }
    else if (xIncrement > 0)
    {
        overflowScanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        // Less readable than the other loops, but it has to be written this way to match.
        for (i = 0; i < height; overflowScanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir, x += xIncrement, overflowScanline += 2, i++)
        {
            if (x >= (CONDITION_GRAPH_CENTER_X << 10))
                break;
        }

        graph->bottom = top + i;
        scanline += (graph->bottom - CONDITION_GRAPH_TOP_Y) * 2;
        for (; i < height; i++)
        {
            scanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir;
            x += xIncrement;
            scanline += 2;
        }

        ptr = scanline - 2;
    }
    else if (xIncrement < 0)
    {
        scanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        for (i = 0; i < height; i++)
        {
            scanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir;
            if (x < (CONDITION_GRAPH_CENTER_X << 10))
            {
                scanline[dir] = CONDITION_GRAPH_CENTER_X;
                break;
            }
            x += xIncrement;
            scanline += 2;
        }

        graph->bottom = top + i;
        overflowScanline += (graph->bottom - CONDITION_GRAPH_TOP_Y) * 2;
        for (; i < height; i++)
        {
            overflowScanline[dir] = SHIFT_RIGHT_ADJUSTED(x, 10) + dir;
            x += xIncrement;
            overflowScanline += 2;
        }

        ptr = overflowScanline - 2;
    }
    else
    {
        graph->bottom = top;
        scanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        overflowScanline += (top - CONDITION_GRAPH_TOP_Y) * 2;
        scanline[1] = pos1->x + 1;
        overflowScanline[0] = pos2->x;
        overflowScanline[1] = CONDITION_GRAPH_CENTER_X;
        return;
    }

    ptr[dir] = dir + x2;
}

// JP 0x081D1AEC: kept as asm (compiler register allocation differs from US).
#ifndef NONMATCHING
// JP naked asm: compiler register allocation differs from US; byte-exact asm stays default.
__attribute__((naked)) static void ConditionGraph_CalcRightHalf(struct ConditionGraph *graph)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "sub sp, #8\n\t"
            "adds r4, r0, #0\n\t"
            "movs r0, #0x97\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r2, r4, r0\n\t"
            "movs r3, #0x99\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r1, r4, r3\n\t"
            "ldrh r0, [r2]\n\t"
            "ldrh r3, [r1]\n\t"
            "cmp r0, r3\n\t"
            "bhs _081D1B28\n\t"
            "adds r7, r0, #0\n\t"
            "movs r0, #0xa0\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r1, r4, r0\n\t"
            "movs r3, #0x96\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r2, r4, r3\n\t"
            "subs r0, #0x10\n\t"
            "adds r3, r4, r0\n\t"
            "movs r0, #1\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp, #4]\n\t"
            "adds r0, r4, #0\n\t"
            "bl ConditionGraph_CalcLine\n\t"
            "b _081D1B48\n\t"
            "_081D1B28:\n\t"
            "ldrh r7, [r1]\n\t"
            "movs r2, #0xa0\n\t"
            "lsls r2, r2, #1\n\t"
            "adds r1, r4, r2\n\t"
            "movs r3, #0x98\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r2, r4, r3\n\t"
            "movs r0, #0x96\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r3, r4, r0\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp]\n\t"
            "str r0, [sp, #4]\n\t"
            "adds r0, r4, #0\n\t"
            "bl ConditionGraph_CalcLine\n\t"
            "_081D1B48:\n\t"
            "movs r1, #0xa0\n\t"
            "lsls r1, r1, #1\n\t"
            "adds r5, r4, r1\n\t"
            "movs r3, #0x98\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r2, r4, r3\n\t"
            "movs r0, #0x9a\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r6, r4, r0\n\t"
            "movs r0, #1\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp, #4]\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r5, #0\n\t"
            "adds r3, r6, #0\n\t"
            "bl ConditionGraph_CalcLine\n\t"
            "movs r2, #0\n\t"
            "movs r1, #0x9b\n\t"
            "lsls r1, r1, #1\n\t"
            "adds r0, r4, r1\n\t"
            "movs r3, #0x9d\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r1, r4, r3\n\t"
            "ldrh r0, [r0]\n\t"
            "ldrh r1, [r1]\n\t"
            "cmp r0, r1\n\t"
            "bhi _081D1B84\n\t"
            "movs r2, #1\n\t"
            "_081D1B84:\n\t"
            "movs r0, #0x9c\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r3, r4, r0\n\t"
            "str r2, [sp]\n\t"
            "movs r1, #0x92\n\t"
            "lsls r1, r1, #2\n\t"
            "adds r0, r4, r1\n\t"
            "str r0, [sp, #4]\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r5, #0\n\t"
            "adds r2, r6, #0\n\t"
            "bl ConditionGraph_CalcLine\n\t"
            "movs r2, #0x38\n\t"
            "cmp r2, r7\n\t"
            "bhs _081D1BC6\n\t"
            "adds r6, r5, #0\n\t"
            "movs r3, #0\n\t"
            "movs r0, #0xa1\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r5, r4, r0\n\t"
            "_081D1BAE:\n\t"
            "adds r0, r2, #0\n\t"
            "subs r0, #0x38\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r1, r6, r0\n\t"
            "strh r3, [r1]\n\t"
            "adds r0, r5, r0\n\t"
            "strh r3, [r0]\n\t"
            "adds r0, r2, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r2, r7\n\t"
            "blo _081D1BAE\n\t"
            "_081D1BC6:\n\t"
            "movs r1, #0x97\n\t"
            "lsls r1, r1, #1\n\t"
            "adds r0, r4, r1\n\t"
            "ldrh r2, [r0]\n\t"
            "movs r3, #0xd4\n\t"
            "lsls r3, r3, #2\n\t"
            "adds r0, r4, r3\n\t"
            "ldrh r1, [r0]\n\t"
            "cmp r2, r1\n\t"
            "bhi _081D1BFA\n\t"
            "movs r1, #0xa0\n\t"
            "lsls r1, r1, #1\n\t"
            "adds r3, r4, r1\n\t"
            "movs r5, #0x9b\n\t"
            "adds r1, r0, #0\n\t"
            "_081D1BE4:\n\t"
            "adds r0, r2, #0\n\t"
            "subs r0, #0x38\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r0, r3, r0\n\t"
            "strh r5, [r0]\n\t"
            "adds r0, r2, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "ldrh r0, [r1]\n\t"
            "cmp r2, r0\n\t"
            "bls _081D1BE4\n\t"
            "_081D1BFA:\n\t"
            "movs r2, #0x9b\n\t"
            "lsls r2, r2, #1\n\t"
            "adds r1, r4, r2\n\t"
            "movs r3, #0xd4\n\t"
            "lsls r3, r3, #2\n\t"
            "adds r0, r4, r3\n\t"
            "ldrh r0, [r0]\n\t"
            "ldrh r1, [r1]\n\t"
            "cmp r0, r1\n\t"
            "bhs _081D1C10\n\t"
            "adds r0, r1, #0\n\t"
            "_081D1C10:\n\t"
            "adds r0, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r2, #0x79\n\t"
            "bhi _081D1C40\n\t"
            "movs r0, #0xa0\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r5, r4, r0\n\t"
            "movs r3, #0\n\t"
            "movs r1, #0xa1\n\t"
            "lsls r1, r1, #1\n\t"
            "adds r4, r4, r1\n\t"
            "_081D1C28:\n\t"
            "adds r0, r2, #0\n\t"
            "subs r0, #0x38\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r1, r5, r0\n\t"
            "strh r3, [r1]\n\t"
            "adds r0, r4, r0\n\t"
            "strh r3, [r0]\n\t"
            "adds r0, r2, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r2, #0x79\n\t"
            "bls _081D1C28\n\t"
            "_081D1C40:\n\t"
            "add sp, #8\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".syntax divided\n");
}

// JP 0x081D1C48: kept as asm (compiler register allocation differs from US).
__attribute__((naked)) static void ConditionGraph_CalcLeftHalf(struct ConditionGraph *graph)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "sub sp, #8\n\t"
            "adds r4, r0, #0\n\t"
            "movs r0, #0x97\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r2, r4, r0\n\t"
            "movs r3, #0x9f\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r1, r4, r3\n\t"
            "ldrh r0, [r2]\n\t"
            "ldrh r3, [r1]\n\t"
            "cmp r0, r3\n\t"
            "bhs _081D1C84\n\t"
            "adds r7, r0, #0\n\t"
            "movs r0, #0x92\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r1, r4, r0\n\t"
            "movs r3, #0x96\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r2, r4, r3\n\t"
            "movs r0, #0x9e\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r3, r4, r0\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp]\n\t"
            "str r0, [sp, #4]\n\t"
            "adds r0, r4, #0\n\t"
            "bl ConditionGraph_CalcLine\n\t"
            "b _081D1CA6\n\t"
            "_081D1C84:\n\t"
            "ldrh r7, [r1]\n\t"
            "movs r2, #0x92\n\t"
            "lsls r2, r2, #2\n\t"
            "adds r1, r4, r2\n\t"
            "movs r3, #0x9e\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r2, r4, r3\n\t"
            "movs r0, #0x96\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r3, r4, r0\n\t"
            "movs r0, #1\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp, #4]\n\t"
            "adds r0, r4, #0\n\t"
            "bl ConditionGraph_CalcLine\n\t"
            "_081D1CA6:\n\t"
            "movs r1, #0x92\n\t"
            "lsls r1, r1, #2\n\t"
            "adds r5, r4, r1\n\t"
            "movs r3, #0x9e\n\t"
            "lsls r3, r3, #1\n\t"
            "adds r2, r4, r3\n\t"
            "movs r0, #0x9c\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r3, r4, r0\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp]\n\t"
            "str r0, [sp, #4]\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r5, #0\n\t"
            "bl ConditionGraph_CalcLine\n\t"
            "movs r2, #0x38\n\t"
            "cmp r2, r7\n\t"
            "bhs _081D1CEC\n\t"
            "adds r6, r5, #0\n\t"
            "movs r3, #0\n\t"
            "ldr r1, _081D1D6C\n\t"
            "adds r5, r4, r1\n\t"
            "_081D1CD4:\n\t"
            "adds r0, r2, #0\n\t"
            "subs r0, #0x38\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r1, r6, r0\n\t"
            "strh r3, [r1]\n\t"
            "adds r0, r5, r0\n\t"
            "strh r3, [r0]\n\t"
            "adds r0, r2, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r2, r7\n\t"
            "blo _081D1CD4\n\t"
            "_081D1CEC:\n\t"
            "movs r2, #0x97\n\t"
            "lsls r2, r2, #1\n\t"
            "adds r0, r4, r2\n\t"
            "ldrh r2, [r0]\n\t"
            "movs r3, #0xd4\n\t"
            "lsls r3, r3, #2\n\t"
            "adds r0, r4, r3\n\t"
            "ldrh r1, [r0]\n\t"
            "cmp r2, r1\n\t"
            "bhi _081D1D1E\n\t"
            "ldr r1, _081D1D6C\n\t"
            "adds r3, r4, r1\n\t"
            "movs r5, #0x9b\n\t"
            "adds r1, r0, #0\n\t"
            "_081D1D08:\n\t"
            "adds r0, r2, #0\n\t"
            "subs r0, #0x38\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r0, r3, r0\n\t"
            "strh r5, [r0]\n\t"
            "adds r0, r2, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "ldrh r0, [r1]\n\t"
            "cmp r2, r0\n\t"
            "bls _081D1D08\n\t"
            "_081D1D1E:\n\t"
            "movs r1, #0x9d\n\t"
            "lsls r1, r1, #1\n\t"
            "adds r0, r4, r1\n\t"
            "ldrh r0, [r0]\n\t"
            "adds r1, r0, #1\n\t"
            "movs r2, #0xd4\n\t"
            "lsls r2, r2, #2\n\t"
            "adds r0, r4, r2\n\t"
            "ldrh r0, [r0]\n\t"
            "cmp r0, r1\n\t"
            "bge _081D1D36\n\t"
            "adds r0, r1, #0\n\t"
            "_081D1D36:\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r2, #0x79\n\t"
            "bhi _081D1D62\n\t"
            "movs r3, #0x92\n\t"
            "lsls r3, r3, #2\n\t"
            "adds r5, r4, r3\n\t"
            "movs r3, #0\n\t"
            "ldr r0, _081D1D6C\n\t"
            "adds r4, r4, r0\n\t"
            "_081D1D4A:\n\t"
            "adds r0, r2, #0\n\t"
            "subs r0, #0x38\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r1, r5, r0\n\t"
            "strh r3, [r1]\n\t"
            "adds r0, r4, r0\n\t"
            "strh r3, [r0]\n\t"
            "adds r0, r2, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r2, #0x79\n\t"
            "bls _081D1D4A\n\t"
            "_081D1D62:\n\t"
            "add sp, #8\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D1D6C: .4byte 0x0000024A\n\t"
            ".syntax divided\n");
}
#else
static void ConditionGraph_CalcRightHalf(struct ConditionGraph *graph)
{
    u16 i, y, bottom;

    // Calculate Cool -> Beauty line
    if (graph->curPositions[GRAPH_COOL].y < graph->curPositions[GRAPH_BEAUTY].y)
    {
        y = graph->curPositions[GRAPH_COOL].y;
        ConditionGraph_CalcLine(graph, graph->scanlineRight[0], &graph->curPositions[GRAPH_COOL], &graph->curPositions[GRAPH_BEAUTY], TRUE, NULL);
    }
    else
    {
        y = graph->curPositions[GRAPH_BEAUTY].y;
        ConditionGraph_CalcLine(graph, graph->scanlineRight[0], &graph->curPositions[GRAPH_BEAUTY], &graph->curPositions[GRAPH_COOL], FALSE, NULL);
    }

    // Calculate Beauty -> Cute line
    // No need for conditional, positions on the Beauty line are always above the Cute line
    ConditionGraph_CalcLine(graph, graph->scanlineRight[0], &graph->curPositions[GRAPH_BEAUTY], &graph->curPositions[GRAPH_CUTE], TRUE, NULL);

    // Calculate Cute -> Smart line (includes left scanline because this crosses the halfway point)
    i = (graph->curPositions[GRAPH_CUTE].y <= graph->curPositions[GRAPH_SMART].y);
    ConditionGraph_CalcLine(graph, graph->scanlineRight[0], &graph->curPositions[GRAPH_CUTE], &graph->curPositions[GRAPH_SMART], i, graph->scanlineLeft[0]);

    // Clear down to new top
    for (i = CONDITION_GRAPH_TOP_Y; i < y; i++)
    {
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] = 0;
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][1] = 0;
    }

    for (i = graph->curPositions[GRAPH_COOL].y; i <= graph->bottom; i++)
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] = CONDITION_GRAPH_CENTER_X;

    // Clear after new bottom
    bottom = max(graph->bottom, graph->curPositions[GRAPH_CUTE].y);
    for (i = bottom + 1; i <= CONDITION_GRAPH_BOTTOM_Y; i++)
    {
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] = 0;
        graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][1] = 0;
    }

    for (i = CONDITION_GRAPH_TOP_Y; i <= CONDITION_GRAPH_BOTTOM_Y; i++)
    {
        if (graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] == 0
         && graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][1] != 0)
            graph->scanlineRight[i - CONDITION_GRAPH_TOP_Y][0] = CONDITION_GRAPH_CENTER_X;
    }
}
static void ConditionGraph_CalcLeftHalf(struct ConditionGraph *graph)
{
    s32 i, y, bottom;

    // Calculate Cool -> Tough line
    if (graph->curPositions[GRAPH_COOL].y < graph->curPositions[GRAPH_TOUGH].y)
    {
        y = graph->curPositions[GRAPH_COOL].y;
        ConditionGraph_CalcLine(graph, graph->scanlineLeft[0], &graph->curPositions[GRAPH_COOL], &graph->curPositions[GRAPH_TOUGH], FALSE, NULL);
    }
    else
    {
        y = graph->curPositions[GRAPH_TOUGH].y;
        ConditionGraph_CalcLine(graph, graph->scanlineLeft[0], &graph->curPositions[GRAPH_TOUGH], &graph->curPositions[GRAPH_COOL], TRUE, NULL);
    }

    // Calculate Tough -> Smart line
    // No need for conditional, positions on the Tough line are always above the Smart line
    ConditionGraph_CalcLine(graph, graph->scanlineLeft[0], &graph->curPositions[GRAPH_TOUGH], &graph->curPositions[GRAPH_SMART], FALSE, NULL);

    // Clear down to new top
    for (i = CONDITION_GRAPH_TOP_Y; i < y; i++)
    {
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][0] = 0;
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][1] = 0;
    }

    for (i = graph->curPositions[GRAPH_COOL].y; i <= graph->bottom; i++)
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][1] = CONDITION_GRAPH_CENTER_X;

    // Clear after new bottom
    bottom = max(graph->bottom, graph->curPositions[GRAPH_SMART].y + 1);
    for (i = bottom; i <= CONDITION_GRAPH_BOTTOM_Y; i++)
    {
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][0] = 0;
        graph->scanlineLeft[i - CONDITION_GRAPH_TOP_Y][1] = 0;
    }

    for (i = 0; i < CONDITION_GRAPH_HEIGHT; i++)
    {
        if (graph->scanlineLeft[i][0] >= graph->scanlineLeft[i][1])
        {
            graph->scanlineLeft[i][1] = 0;
            graph->scanlineLeft[i][0] = 0;
        }
    }
}
#endif


void ConditionGraph_CalcPositions(u8 *conditions, struct UCoords16 *positions)
{
    u8 lineLength, sinIdx;
    s8 posIdx;
    u16 i;

    // Cool is straight up-and-down (not angled), so no need for Sin
    lineLength = sConditionToLineLength[*(conditions++)];
    positions[GRAPH_COOL].x = CONDITION_GRAPH_CENTER_X;
    positions[GRAPH_COOL].y = CONDITION_GRAPH_CENTER_Y - lineLength;

    sinIdx = 64;
    posIdx = GRAPH_COOL;
    for (i = 1; i < CONDITION_COUNT; i++)
    {
        sinIdx += 51;
        if (--posIdx < 0)
            posIdx = CONDITION_COUNT - 1;

        if (posIdx == GRAPH_CUTE)
            sinIdx++;

        lineLength = sConditionToLineLength[*(conditions++)];
        positions[posIdx].x = CONDITION_GRAPH_CENTER_X + ((lineLength * gSineTable[64 + sinIdx]) >> 8);
        positions[posIdx].y = CONDITION_GRAPH_CENTER_Y - ((lineLength * gSineTable[sinIdx]) >> 8);

        if (posIdx <= GRAPH_CUTE && (lineLength != 32 || posIdx != GRAPH_CUTE))
            positions[posIdx].x++;
    }
}

//----------------
// Move relearner
//----------------

void InitMoveRelearnerWindows(bool8 useContestWindow)
{
    u8 i;

    InitWindows(sMoveRelearnerWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 1, BG_PLTT_ID(14));
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);

    for (i = 0; i < ARRAY_COUNT(sMoveRelearnerWindowTemplates) - 1; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(1));

    if (!useContestWindow)
    {
        PutWindowTilemap(RELEARNERWIN_DESC_BATTLE);
        DrawStdFrameWithCustomTileAndPalette(RELEARNERWIN_DESC_BATTLE, FALSE, 0x1, 0xE);
    }
    else
    {
        PutWindowTilemap(RELEARNERWIN_DESC_CONTEST);
        DrawStdFrameWithCustomTileAndPalette(RELEARNERWIN_DESC_CONTEST, FALSE, 1, 0xE);
    }
    PutWindowTilemap(RELEARNERWIN_MOVE_LIST);
    PutWindowTilemap(RELEARNERWIN_MSG);
    DrawStdFrameWithCustomTileAndPalette(RELEARNERWIN_MOVE_LIST, FALSE, 1, 0xE);
    DrawStdFrameWithCustomTileAndPalette(RELEARNERWIN_MSG, FALSE, 1, 0xE);
    sub_081D1EE0();
    ScheduleBgCopyTilemapToVram(1);
}

// JP 0x081D1EE0: prints the eight static hint lines in the move
// relearner window. The US build calls an empty dummy here instead.
// Texts (decoded with tools/decode_jp_text.py from the JP ROM):
//   0x085F7C50: "たたかうわざ" (battle moves)
//   0x085F7C5F: "タイプ/" (type/)
//   0x085F7C64: "PP/"
//   0x085F7C68: "いりょく/" (power/)
//   0x085F7C6E: "{MUS_RG_SEVII_DUNGEON}めいちゅう/" (accuracy/)
//   0x085F7C57: "コンテストわざ" (contest moves)
//   0x085F7C75: "アピール" (appeal)
//   0x085F7C7A: "ぼうがい{PH_CLOTH_SOLO}" (jam)
__attribute__((naked)) void sub_081D1EE0(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, lr}\n\t"
            "mov r6, sl\n\t"
            "mov r5, sb\n\t"
            "mov r4, r8\n\t"
            "push {r4, r5, r6}\n\t"
            "sub sp, #0xc\n\t"
            "ldr r2, _081D1FB8\n\t"
            "movs r0, #2\n\t"
            "mov sb, r0\n\t"
            "str r0, [sp]\n\t"
            "movs r5, #0xff\n\t"
            "str r5, [sp, #4]\n\t"
            "movs r4, #0\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0x30\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r0, _081D1FBC\n\t"
            "mov sl, r0\n\t"
            "movs r0, #0x1a\n\t"
            "mov r8, r0\n\t"
            "str r0, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "mov r2, sl\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r2, _081D1FC0\n\t"
            "mov r0, r8\n\t"
            "str r0, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0x50\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r2, _081D1FC4\n\t"
            "movs r6, #0x2a\n\t"
            "str r6, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "movs r3, #8\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r2, _081D1FC8\n\t"
            "str r6, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0x48\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r2, _081D1FCC\n\t"
            "mov r0, sb\n\t"
            "str r0, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0x2c\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "mov r0, r8\n\t"
            "str r0, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #1\n\t"
            "mov r2, sl\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r2, _081D1FD0\n\t"
            "str r6, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r2, _081D1FD4\n\t"
            "str r6, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0x50\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "add sp, #0xc\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D1FB8: .4byte 0x085F7C50\n\t"
            "_081D1FBC: .4byte 0x085F7C5F\n\t"
            "_081D1FC0: .4byte 0x085F7C68\n\t"
            "_081D1FC4: .4byte 0x085F7C64\n\t"
            "_081D1FC8: .4byte 0x085F7C6E\n\t"
            "_081D1FCC: .4byte 0x085F7C57\n\t"
            "_081D1FD0: .4byte 0x085F7C75\n\t"
            "_081D1FD4: .4byte 0x085F7C7A\n\t"
            ".syntax divided\n");
}

u8 LoadMoveRelearnerMovesList(const struct ListMenuItem *items, u16 numChoices)
{
    gMultiuseListMenuTemplate = sMoveRelearnerMovesListTemplate;
    gMultiuseListMenuTemplate.totalItems = numChoices;
    gMultiuseListMenuTemplate.items = items;

    if (numChoices < 6)
        gMultiuseListMenuTemplate.maxShowed = numChoices;
    else
        gMultiuseListMenuTemplate.maxShowed = 6;

    return gMultiuseListMenuTemplate.maxShowed;
}

// JP 0x081D200C: the JP build merges the cursor SE, the battle move
// description and the contest move description into one callback that
// redraws both windows with FillWindowPixelRect. Kept as asm.
__attribute__((naked)) void sub_081D200C(u32 chosenMove, bool8 onInit)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, r8\n\t"
            "push {r7}\n\t"
            "sub sp, #0x14\n\t"
            "adds r7, r0, #0\n\t"
            "lsls r1, r1, #0x18\n\t"
            "lsrs r1, r1, #0x18\n\t"
            "cmp r1, #1\n\t"
            "beq _081D2024\n\t"
            "movs r0, #5\n\t"
            "bl PlaySE\n\t"
            "_081D2024:\n\t"
            "movs r6, #0x20\n\t"
            "str r6, [sp]\n\t"
            "movs r4, #0x10\n\t"
            "str r4, [sp, #4]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #0x11\n\t"
            "movs r2, #0x20\n\t"
            "movs r3, #0x1a\n\t"
            "bl FillWindowPixelRect\n\t"
            "movs r5, #0x18\n\t"
            "str r5, [sp]\n\t"
            "str r4, [sp, #4]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #0x11\n\t"
            "movs r2, #0x78\n\t"
            "movs r3, #0x1a\n\t"
            "bl FillWindowPixelRect\n\t"
            "str r4, [sp]\n\t"
            "str r4, [sp, #4]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #0x11\n\t"
            "movs r2, #0x20\n\t"
            "movs r3, #0x2a\n\t"
            "bl FillWindowPixelRect\n\t"
            "str r5, [sp]\n\t"
            "str r4, [sp, #4]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #0x11\n\t"
            "movs r2, #0x78\n\t"
            "movs r3, #0x2a\n\t"
            "bl FillWindowPixelRect\n\t"
            "movs r5, #0x90\n\t"
            "str r5, [sp]\n\t"
            "str r6, [sp, #4]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #0x11\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0x42\n\t"
            "bl FillWindowPixelRect\n\t"
            "movs r0, #0x28\n\t"
            "str r0, [sp]\n\t"
            "str r4, [sp, #4]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0x11\n\t"
            "movs r2, #0x20\n\t"
            "movs r3, #0x1a\n\t"
            "bl FillWindowPixelRect\n\t"
            "str r5, [sp]\n\t"
            "str r6, [sp, #4]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #0x11\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0x42\n\t"
            "bl FillWindowPixelRect\n\t"
            "movs r0, #2\n\t"
            "rsbs r0, r0, #0\n\t"
            "cmp r7, r0\n\t"
            "bne _081D20B8\n\t"
            "movs r0, #0\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "movs r0, #1\n\t"
            "movs r1, #2\n\t"
            "bl CopyWindowToVram\n\t"
            "b _081D21E4\n\t"
            "_081D20B8:\n\t"
            "ldr r1, _081D20F4\n\t"
            "lsls r4, r7, #1\n\t"
            "adds r0, r4, r7\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r5, r0, r1\n\t"
            "ldrb r0, [r5, #2]\n\t"
            "lsls r2, r0, #2\n\t"
            "adds r2, r2, r0\n\t"
            "ldr r0, _081D20F8\n\t"
            "adds r2, r2, r0\n\t"
            "movs r0, #0x1a\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #0xff\n\t"
            "str r0, [sp, #4]\n\t"
            "movs r0, #0\n\t"
            "str r0, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0x20\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldrb r0, [r5, #1]\n\t"
            "adds r6, r4, #0\n\t"
            "cmp r0, #1\n\t"
            "bhi _081D2100\n\t"
            "ldr r1, _081D20FC\n\t"
            "add r0, sp, #0xc\n\t"
            "bl StringCopy\n\t"
            "b _081D210C\n\t"
            ".align 2, 0\n\t"
            "_081D20F4: .4byte 0x082ED220\n\t"
            "_081D20F8: .4byte gTypeNames\n\t"
            "_081D20FC: .4byte 0x085C9406\n\t"
            "_081D2100:\n\t"
            "ldrb r1, [r5, #1]\n\t"
            "add r0, sp, #0xc\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "_081D210C:\n\t"
            "movs r0, #0x1a\n\t"
            "str r0, [sp]\n\t"
            "movs r5, #0xff\n\t"
            "str r5, [sp, #4]\n\t"
            "movs r4, #0\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "add r2, sp, #0xc\n\t"
            "movs r3, #0x78\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r1, _081D215C\n\t"
            "adds r0, r6, r7\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r6, r0, r1\n\t"
            "ldrb r1, [r6, #4]\n\t"
            "add r0, sp, #0xc\n\t"
            "movs r2, #0\n\t"
            "movs r3, #2\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "movs r0, #0x2a\n\t"
            "str r0, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "add r2, sp, #0xc\n\t"
            "movs r3, #0x20\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldrb r0, [r6, #3]\n\t"
            "cmp r0, #0\n\t"
            "bne _081D2164\n\t"
            "ldr r1, _081D2160\n\t"
            "add r0, sp, #0xc\n\t"
            "bl StringCopy\n\t"
            "b _081D2170\n\t"
            ".align 2, 0\n\t"
            "_081D215C: .4byte 0x082ED220\n\t"
            "_081D2160: .4byte 0x085C9406\n\t"
            "_081D2164:\n\t"
            "ldrb r1, [r6, #3]\n\t"
            "add r0, sp, #0xc\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "_081D2170:\n\t"
            "movs r0, #0x2a\n\t"
            "str r0, [sp]\n\t"
            "movs r0, #0xff\n\t"
            "mov r8, r0\n\t"
            "str r0, [sp, #4]\n\t"
            "movs r5, #0\n\t"
            "str r5, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "add r2, sp, #0xc\n\t"
            "movs r3, #0x78\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "lsls r4, r7, #3\n\t"
            "subs r2, r4, r7\n\t"
            "lsls r2, r2, #3\n\t"
            "ldr r0, _081D21F8\n\t"
            "adds r2, r2, r0\n\t"
            "movs r6, #0x42\n\t"
            "str r6, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r5, [sp, #8]\n\t"
            "movs r0, #0\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r1, _081D21FC\n\t"
            "ldr r0, _081D2200\n\t"
            "adds r4, r4, r0\n\t"
            "ldrb r0, [r4, #1]\n\t"
            "lsls r0, r0, #0x1d\n\t"
            "lsrs r0, r0, #0x1b\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r2, [r0]\n\t"
            "movs r0, #0x1a\n\t"
            "str r0, [sp]\n\t"
            "mov r0, r8\n\t"
            "str r0, [sp, #4]\n\t"
            "str r5, [sp, #8]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0x20\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r1, _081D2204\n\t"
            "ldrb r0, [r4]\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r2, [r0]\n\t"
            "str r6, [sp]\n\t"
            "str r5, [sp, #4]\n\t"
            "str r5, [sp, #8]\n\t"
            "movs r0, #1\n\t"
            "movs r1, #1\n\t"
            "movs r3, #0\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "_081D21E4:\n\t"
            "adds r0, r7, #0\n\t"
            "bl MoveRelearnerShowHideHearts\n\t"
            "add sp, #0x14\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D21F8: .4byte 0x085E7FFC\n\t"
            "_081D21FC: .4byte 0x08560CAC\n\t"
            "_081D2200: .4byte gContestMoves\n\t"
            "_081D2204: .4byte 0x08560BB4\n\t"
            ".syntax divided\n");
}

void MoveRelearnerPrintMessage(u8 *str)
{
    u8 speed;

    FillWindowPixelBuffer(RELEARNERWIN_MSG, PIXEL_FILL(1));
    gTextFlags.canABSpeedUpPrint = TRUE;
    speed = GetPlayerTextSpeedDelay();
    AddTextPrinterParameterized2(RELEARNERWIN_MSG, FONT_NORMAL, str, speed, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, 3);
}

bool16 MoveRelearnerRunTextPrinters(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(RELEARNERWIN_MSG);
}

// JP 0x081D2264: the JP build calls the JP-only 4-arg helper
// sub_08198D44 with (template, 1, 1, 0xE) instead of the US
// CreateYesNoMenu(template, 1, 0xE, 0).
__attribute__((naked)) void MoveRelearnerCreateYesNoMenu(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {lr}\n\t"
            "ldr r0, _081D2278\n\t"
            "movs r1, #1\n\t"
            "movs r2, #1\n\t"
            "movs r3, #0xe\n\t"
            "bl sub_08198D44\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D2278: .4byte sMoveRelearnerYesNoMenuTemplate\n\t"
            ".syntax divided\n");
}

//----------------
// Condition menu
//----------------

s32 GetBoxOrPartyMonData(u16 boxId, u16 monId, s32 request, u8 *dst)
{
    s32 ret;

    if (boxId == TOTAL_BOXES_COUNT) // Party mon.
    {
        if (request == MON_DATA_NICKNAME || request == MON_DATA_OT_NAME)
            ret = GetMonData(&gPlayerParty[monId], request, dst);
        else
            ret = GetMonData(&gPlayerParty[monId], request);
    }
    else
    {
        if (request == MON_DATA_NICKNAME || request == MON_DATA_OT_NAME)
            ret = GetAndCopyBoxMonDataAt(boxId, monId, request, dst);
        else
            ret = GetBoxMonDataAt(boxId, monId, request);
    }

    return ret;
}

// Gets the name/gender/level string for the condition menu
// JP 0x081D22E4: kept as asm (compiler register allocation differs from US).
__attribute__((naked)) static u8 *GetConditionMenuMonString(u8 *dst, u16 boxId, u16 monId)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, r8\n\t"
            "push {r7}\n\t"
            "adds r5, r0, #0\n\t"
            "lsls r1, r1, #0x10\n\t"
            "lsrs r4, r1, #0x10\n\t"
            "lsls r2, r2, #0x10\n\t"
            "lsrs r6, r2, #0x10\n\t"
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
            "beq _081D2334\n\t"
            "ldr r1, _081D2330\n\t"
            "adds r0, r5, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #0xc\n\t"
            "bl StringCopyPadded\n\t"
            "b _081D24A2\n\t"
            ".align 2, 0\n\t"
            "_081D2330: .4byte gText_EggNickname\n\t"
            "_081D2334:\n\t"
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
            "bne _081D2384\n\t"
            "movs r0, #0x64\n\t"
            "adds r4, r6, #0\n\t"
            "muls r4, r0, r4\n\t"
            "ldr r0, _081D2380\n\t"
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
            "b _081D23A6\n\t"
            ".align 2, 0\n\t"
            "_081D2380: .4byte gPlayerParty\n\t"
            "_081D2384:\n\t"
            "lsls r0, r4, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "lsls r1, r6, #0x18\n\t"
            "lsrs r1, r1, #0x18\n\t"
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
            "_081D23A6:\n\t"
            "cmp r7, #0x1d\n\t"
            "beq _081D23AE\n\t"
            "cmp r7, #0x20\n\t"
            "bne _081D23C4\n\t"
            "_081D23AE:\n\t"
            "lsls r1, r7, #1\n\t"
            "adds r1, r1, r7\n\t"
            "lsls r1, r1, #1\n\t"
            "ldr r0, _081D23CC\n\t"
            "adds r1, r1, r0\n\t"
            "adds r0, r5, #0\n\t"
            "bl StringCompare\n\t"
            "cmp r0, #0\n\t"
            "bne _081D23C4\n\t"
            "movs r6, #0xff\n\t"
            "_081D23C4:\n\t"
            "adds r3, r5, #0\n\t"
            "movs r2, #0\n\t"
            "b _081D23D8\n\t"
            ".align 2, 0\n\t"
            "_081D23CC: .4byte gSpeciesNamesJP\n\t"
            "_081D23D0:\n\t"
            "adds r3, #1\n\t"
            "adds r0, r2, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "_081D23D8:\n\t"
            "ldrb r0, [r3]\n\t"
            "cmp r0, #0xff\n\t"
            "bne _081D23D0\n\t"
            "adds r1, r2, #0\n\t"
            "adds r0, r1, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r1, #4\n\t"
            "bhi _081D23FC\n\t"
            "movs r4, #0\n\t"
            "_081D23EC:\n\t"
            "strb r4, [r3]\n\t"
            "adds r3, #1\n\t"
            "adds r1, r2, #0\n\t"
            "adds r0, r1, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r2, r0, #0x10\n\t"
            "cmp r1, #4\n\t"
            "bls _081D23EC\n\t"
            "_081D23FC:\n\t"
            "movs r0, #0\n\t"
            "strb r0, [r3]\n\t"
            "adds r3, #1\n\t"
            "cmp r6, #0\n\t"
            "beq _081D240C\n\t"
            "cmp r6, #0xfe\n\t"
            "beq _081D2432\n\t"
            "b _081D2456\n\t"
            "_081D240C:\n\t"
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
            "b _081D2456\n\t"
            "_081D2432:\n\t"
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
            "_081D2456:\n\t"
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
            "movs r4, #0\n\t"
            "strb r4, [r3]\n\t"
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
            "adds r0, r3, #0\n\t"
            "mov r1, r8\n\t"
            "movs r2, #0\n\t"
            "movs r3, #3\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "adds r3, r0, #0\n\t"
            "strb r4, [r3]\n\t"
            "adds r3, #1\n\t"
            "movs r0, #0xff\n\t"
            "strb r0, [r3]\n\t"
            "adds r0, r3, #0\n\t"
            "_081D24A2:\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".syntax divided\n");
}

// Buffers the string in src to dest up to n chars. If src is less than n chars, fill with spaces
static u8 *BufferConditionMenuSpacedStringN(u8 *dst, const u8 *src, s16 n)
{
    while (*src != EOS)
    {
        *(dst++) = *(src++);
        n--;
    }
    while (n-- > 0)
        *(dst++) = CHAR_SPACE;

    *dst = EOS;
    return dst;
}

void GetConditionMenuMonNameAndLocString(u8 *locationDst, u8 *nameDst, u16 boxId, u16 monId, u16 partyId, u16 numMons, bool8 excludesCancel)
{
    u16 i;
    u16 box = boxId;
    u16 mon = monId;

    // In this and the below 2 functions, numMons is passed as the number of menu selections (which includes Cancel)
    // To indicate that the Cancel needs to be subtracted they pass an additional bool
    // Unclear why they didn't just subtract 1 when it gets passed instead
    if (!excludesCancel)
        numMons--;

    if (partyId != numMons)
    {
        GetConditionMenuMonString(nameDst, box, mon);
        locationDst[0] = EXT_CTRL_CODE_BEGIN;
        locationDst[1] = EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW;
        locationDst[2] = TEXT_COLOR_BLUE;
        locationDst[3] = TEXT_COLOR_TRANSPARENT;
        locationDst[4] = TEXT_COLOR_LIGHT_BLUE;
        if (box == TOTAL_BOXES_COUNT) // Party mon.
            BufferConditionMenuSpacedStringN(&locationDst[5], gText_InParty, BOX_NAME_LENGTH);
        else
            BufferConditionMenuSpacedStringN(&locationDst[5], GetBoxNamePtr(box), BOX_NAME_LENGTH);
    }
    else
    {
        for (i = 0; i < POKEMON_NAME_LENGTH + 2; i++)
            nameDst[i] = CHAR_SPACE;
        nameDst[i] = EOS;
        for (i = 0; i < BOX_NAME_LENGTH; i++)
            locationDst[i] = CHAR_SPACE;
        locationDst[i] = EOS;
    }
}

void GetConditionMenuMonConditions(struct ConditionGraph *graph, u8 *numSparkles, u16 boxId, u16 monId, u16 partyId, u16 id, u16 numMons, bool8 excludesCancel)
{
    u16 i;

    if (!excludesCancel)
        numMons--;

    if (partyId != numMons)
    {
        graph->conditions[id][CONDITION_COOL] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_COOL, NULL);
        graph->conditions[id][CONDITION_TOUGH] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_TOUGH, NULL);
        graph->conditions[id][CONDITION_SMART] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SMART, NULL);
        graph->conditions[id][CONDITION_CUTE] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_CUTE, NULL);
        graph->conditions[id][CONDITION_BEAUTY] = GetBoxOrPartyMonData(boxId, monId, MON_DATA_BEAUTY, NULL);

        numSparkles[id] = GET_NUM_CONDITION_SPARKLES(GetBoxOrPartyMonData(boxId, monId, MON_DATA_SHEEN, NULL));

        ConditionGraph_CalcPositions(graph->conditions[id], graph->savedPositions[id]);
    }
    else
    {
        for (i = 0; i < CONDITION_COUNT; i++)
        {
            graph->conditions[id][i] = 0;
            graph->savedPositions[id][i].x = CONDITION_GRAPH_CENTER_X;
            graph->savedPositions[id][i].y = CONDITION_GRAPH_CENTER_Y;
        }
    }
}

void GetConditionMenuMonGfx(void *tilesDst, void *palDst, u16 boxId, u16 monId, u16 partyId, u16 numMons, bool8 excludesCancel)
{
    if (!excludesCancel)
        numMons--;

    if (partyId != numMons)
    {
        u16 species = GetBoxOrPartyMonData(boxId, monId, MON_DATA_SPECIES_OR_EGG, NULL);
        u32 trainerId = GetBoxOrPartyMonData(boxId, monId, MON_DATA_OT_ID, NULL);
        u32 personality = GetBoxOrPartyMonData(boxId, monId, MON_DATA_PERSONALITY, NULL);

        LoadSpecialPokePic(&gMonFrontPicTable[species], tilesDst, species, personality, TRUE);
        LZ77UnCompWram(GetMonSpritePalFromSpeciesAndPersonality(species, trainerId, personality), palDst);
    }
}

bool8 MoveConditionMonOnscreen(s16 *x)
{
    *x += 24;
    if (*x > 0)
        *x = 0;

    return (*x != 0);
}

bool8 MoveConditionMonOffscreen(s16 *x)
{
    *x -= 24;
    if (*x < -80)
        *x = -80;

    return (*x != -80);
}

bool8 ConditionMenu_UpdateMonEnter(struct ConditionGraph *graph, s16 *x)
{
    bool8 graphUpdating = ConditionGraph_TryUpdate(graph);
    bool8 monUpdating = MoveConditionMonOnscreen(x);

    return (graphUpdating || monUpdating);
}

bool8 ConditionMenu_UpdateMonExit(struct ConditionGraph *graph, s16 *x)
{
    bool8 graphUpdating = ConditionGraph_TryUpdate(graph);
    bool8 monUpdating = MoveConditionMonOffscreen(x);

    return (graphUpdating || monUpdating);
}

// Just loads the generic data, up to the caller to load the actual sheet/pal for the specific mon
// JP 0x081D2800: kept as asm (JP data layout differs from US).
__attribute__((naked)) void LoadConditionMonPicTemplate(struct SpriteSheet *sheet, struct SpriteTemplate *template, struct SpritePalette *pal)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "sub sp, #0x20\n\t"
            "ldr r3, _081D2840\n\t"
            "ldr r4, [r3]\n\t"
            "ldr r5, [r3, #4]\n\t"
            "str r4, [sp, #0x18]\n\t"
            "str r5, [sp, #0x1c]\n\t"
            "mov r4, sp\n\t"
            "ldr r3, _081D2844\n\t"
            "ldm r3!, {r5, r6, r7}\n\t"
            "stm r4!, {r5, r6, r7}\n\t"
            "ldm r3!, {r5, r6, r7}\n\t"
            "stm r4!, {r5, r6, r7}\n\t"
            "ldr r3, _081D2848\n\t"
            "ldr r4, [r3, #4]\n\t"
            "ldr r3, [r3]\n\t"
            "ldr r5, [sp, #0x18]\n\t"
            "ldr r6, [sp, #0x1c]\n\t"
            "str r5, [r0]\n\t"
            "str r6, [r0, #4]\n\t"
            "mov r0, sp\n\t"
            "ldm r0!, {r5, r6, r7}\n\t"
            "stm r1!, {r5, r6, r7}\n\t"
            "ldm r0!, {r5, r6, r7}\n\t"
            "stm r1!, {r5, r6, r7}\n\t"
            "str r3, [r2]\n\t"
            "str r4, [r2, #4]\n\t"
            "add sp, #0x20\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D2840: .4byte 0x085FA898\n\t"
            "_081D2844: .4byte 0x085FA8A0\n\t"
            "_081D2848: .4byte 0x085FA8B8\n\t"
            ".syntax divided\n");
}

// JP 0x081D284C: kept as asm (JP data layout differs from US).
__attribute__((naked)) void LoadConditionSelectionIcons(struct SpriteSheet *sheets, struct SpriteTemplate *template, struct SpritePalette *pals)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, r8\n\t"
            "push {r7}\n\t"
            "sub sp, #0x50\n\t"
            "adds r5, r0, #0\n\t"
            "mov ip, r1\n\t"
            "mov r8, r2\n\t"
            "mov r1, sp\n\t"
            "ldr r0, _081D28D4\n\t"
            "ldm r0!, {r2, r3, r4}\n\t"
            "stm r1!, {r2, r3, r4}\n\t"
            "ldm r0!, {r2, r6, r7}\n\t"
            "stm r1!, {r2, r6, r7}\n\t"
            "ldm r0!, {r3, r4}\n\t"
            "stm r1!, {r3, r4}\n\t"
            "add r3, sp, #0x20\n\t"
            "adds r1, r3, #0\n\t"
            "ldr r0, _081D28D8\n\t"
            "ldm r0!, {r2, r6, r7}\n\t"
            "stm r1!, {r2, r6, r7}\n\t"
            "ldm r0!, {r4, r6, r7}\n\t"
            "stm r1!, {r4, r6, r7}\n\t"
            "add r2, sp, #0x38\n\t"
            "adds r1, r2, #0\n\t"
            "ldr r0, _081D28DC\n\t"
            "ldm r0!, {r4, r6, r7}\n\t"
            "stm r1!, {r4, r6, r7}\n\t"
            "ldm r0!, {r4, r6, r7}\n\t"
            "stm r1!, {r4, r6, r7}\n\t"
            "movs r4, #0\n\t"
            "_081D2888:\n\t"
            "lsls r0, r4, #3\n\t"
            "add r0, sp\n\t"
            "ldr r1, [r0, #4]\n\t"
            "ldr r0, [r0]\n\t"
            "stm r5!, {r0, r1}\n\t"
            "adds r0, r4, #1\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r4, r0, #0x18\n\t"
            "cmp r4, #3\n\t"
            "bls _081D2888\n\t"
            "mov r1, ip\n\t"
            "adds r0, r2, #0\n\t"
            "ldm r0!, {r2, r4, r5}\n\t"
            "stm r1!, {r2, r4, r5}\n\t"
            "ldm r0!, {r2, r6, r7}\n\t"
            "stm r1!, {r2, r6, r7}\n\t"
            "movs r4, #0\n\t"
            "_081D28AA:\n\t"
            "lsls r0, r4, #3\n\t"
            "adds r0, r3, r0\n\t"
            "ldr r1, [r0, #4]\n\t"
            "ldr r0, [r0]\n\t"
            "mov r5, r8\n\t"
            "adds r5, #8\n\t"
            "mov r8, r5\n\t"
            "subs r5, #8\n\t"
            "stm r5!, {r0, r1}\n\t"
            "adds r0, r4, #1\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r4, r0, #0x18\n\t"
            "cmp r4, #2\n\t"
            "bls _081D28AA\n\t"
            "add sp, #0x50\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D28D4: .4byte 0x085FA8C0\n\t"
            "_081D28D8: .4byte 0x085FA8E0\n\t"
            "_081D28DC: .4byte 0x085FA8F8\n\t"
            ".syntax divided\n");
}

#define sSparkleId           data[0]
#define sDelayTimer          data[1]
#define sNumExtraSparkles    data[2]
#define sCurSparkleId        data[3]
#define sMonSpriteId         data[4]
#define sNextSparkleSpriteId data[5]

// JP 0x081D28E0: kept as asm (JP data layout differs from US).
__attribute__((naked)) void LoadConditionSparkle(struct SpriteSheet *sheet, struct SpritePalette *pal)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, lr}\n\t"
            "ldr r2, _081D28FC\n\t"
            "ldr r4, [r2]\n\t"
            "ldr r5, [r2, #4]\n\t"
            "ldr r2, _081D2900\n\t"
            "ldr r3, [r2, #4]\n\t"
            "ldr r2, [r2]\n\t"
            "str r4, [r0]\n\t"
            "str r5, [r0, #4]\n\t"
            "str r2, [r1]\n\t"
            "str r3, [r1, #4]\n\t"
            "pop {r4, r5}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D28FC: .4byte 0x085FA910\n\t"
            "_081D2900: .4byte 0x085FA918\n\t"
            ".syntax divided\n");
}

static void SpriteCB_ConditionSparkle_DoNextAfterDelay(struct Sprite *sprite)
{
    if (++sprite->sDelayTimer > 60)
    {
        sprite->sDelayTimer = 0;
        SetNextConditionSparkle(sprite);
    }
}

static void SpriteCB_ConditionSparkle_WaitForAllAnim(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        sprite->sDelayTimer = 0;
        sprite->callback = SpriteCB_ConditionSparkle_DoNextAfterDelay;
    }
}

static void SetConditionSparklePosition(struct Sprite *sprite)
{
    struct Sprite *mon = &gSprites[sprite->sMonSpriteId];

    if (mon != NULL)
    {
        sprite->x = mon->x + mon->x2 + sConditionSparkleCoords[sprite->sSparkleId][0];
        sprite->y = mon->y + mon->y2 + sConditionSparkleCoords[sprite->sSparkleId][1];
    }
    else
    {
        sprite->x = sConditionSparkleCoords[sprite->sSparkleId][0] + 40;
        sprite->y = sConditionSparkleCoords[sprite->sSparkleId][1] + 104;
    }
}

static void InitConditionSparkles(u8 count, bool8 allowFirstShowAll, struct Sprite **sprites)
{
    u16 i;

    for (i = 0; i < MAX_CONDITION_SPARKLES; i++)
    {
        if (sprites[i] != NULL)
        {
            sprites[i]->sSparkleId = i;
            sprites[i]->sDelayTimer = (i * 16) + 1;
            sprites[i]->sNumExtraSparkles = count;
            sprites[i]->sCurSparkleId = i;
            if (!allowFirstShowAll || count != MAX_CONDITION_SPARKLES - 1)
            {
                sprites[i]->callback = SpriteCB_ConditionSparkle;
            }
            else
            {
                SetConditionSparklePosition(sprites[i]);
                ShowAllConditionSparkles(sprites[i]);
                sprites[i]->callback = SpriteCB_ConditionSparkle_WaitForAllAnim;
                sprites[i]->invisible = FALSE;
            }
        }
    }
}

static void SetNextConditionSparkle(struct Sprite *sprite)
{
    u16 i;
    u8 id = sprite->sNextSparkleSpriteId;
    for (i = 0; i < sprite->sNumExtraSparkles + 1; i++)
    {
        gSprites[id].sDelayTimer = (gSprites[id].sSparkleId * 16) + 1;
        gSprites[id].callback = SpriteCB_ConditionSparkle;
        id = gSprites[id].sNextSparkleSpriteId;
    }
}

void ResetConditionSparkleSprites(struct Sprite **sprites)
{
    u8 i;

    for (i = 0; i < MAX_CONDITION_SPARKLES; i++)
        sprites[i] = NULL;
}

void CreateConditionSparkleSprites(struct Sprite **sprites, u8 monSpriteId, u8 _count)
{
    u16 i, spriteId, firstSpriteId = 0;
    u8 count = _count;

    for (i = 0; i < count + 1; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_ConditionSparkle, 0, 0, 0);
        if (spriteId != MAX_SPRITES)
        {
            sprites[i] = &gSprites[spriteId];
            sprites[i]->invisible = TRUE;
            sprites[i]->sMonSpriteId = monSpriteId;
            if (i != 0)
                sprites[i - 1]->sNextSparkleSpriteId = spriteId;
            else
                firstSpriteId = spriteId;
        }
        else
        {
            break;
        }
    }

    sprites[count]->sNextSparkleSpriteId = firstSpriteId;
    InitConditionSparkles(count, TRUE, sprites);
}

void DestroyConditionSparkleSprites(struct Sprite **sprites)
{
    u16 i;

    for (i = 0; i < MAX_CONDITION_SPARKLES; i++)
    {
        if (sprites[i] != NULL)
        {
            DestroySprite(sprites[i]);
            sprites[i] = NULL;
        }
        else
        {
            break;
        }
    }
}

void FreeConditionSparkles(struct Sprite **sprites)
{
    DestroyConditionSparkleSprites(sprites);
    FreeSpriteTilesByTag(TAG_CONDITION_SPARKLE);
    FreeSpritePaletteByTag(TAG_CONDITION_SPARKLE);
}

static void SpriteCB_ConditionSparkle(struct Sprite *sprite)
{
    // Delay, then do sparkle anim
    if (sprite->sDelayTimer != 0)
    {
        if (--sprite->sDelayTimer != 0)
            return;

        SeekSpriteAnim(sprite, 0);
        sprite->invisible = FALSE;
    }

    SetConditionSparklePosition(sprite);

    // Set up next sparkle
    if (sprite->animEnded)
    {
        sprite->invisible = TRUE;
        if (sprite->sCurSparkleId == sprite->sNumExtraSparkles)
        {
            if (sprite->sCurSparkleId == MAX_CONDITION_SPARKLES - 1)
            {
                ShowAllConditionSparkles(sprite);
                sprite->callback = SpriteCB_ConditionSparkle_WaitForAllAnim;
            }
            else
            {
                sprite->callback = SpriteCB_ConditionSparkle_DoNextAfterDelay;
            }
        }
        else
        {
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

static void ShowAllConditionSparkles(struct Sprite *sprite)
{
    u8 i, id = sprite->sNextSparkleSpriteId;

    for (i = 0; i < sprite->sNumExtraSparkles + 1; i++)
    {
        SeekSpriteAnim(&gSprites[id], 0);
        gSprites[id].invisible = FALSE;
        id = gSprites[id].sNextSparkleSpriteId;
    }
}

#undef sSparkleId
#undef sDelayTimer
#undef sNumExtraSparkles
#undef sCurSparkleId
#undef sMonSpriteId
#undef sNextSparkleSpriteId

// JP 0x081D2C70: the JP build allocates registers differently from the
// US C port, so this is kept as asm.
__attribute__((naked)) void DrawLevelUpWindowPg1(u16 windowId, u16 *statsBefore, u16 *statsAfter, u8 bgClr, u8 fgClr, u8 shadowClr)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #0x2c\n\t"
            "mov r8, r0\n\t"
            "adds r6, r1, #0\n\t"
            "adds r5, r2, #0\n\t"
            "adds r4, r3, #0\n\t"
            "ldr r3, [sp, #0x4c]\n\t"
            "ldr r0, [sp, #0x50]\n\t"
            "mov sb, r0\n\t"
            "lsls r4, r4, #0x18\n\t"
            "lsrs r4, r4, #0x18\n\t"
            "lsls r3, r3, #0x18\n\t"
            "lsrs r3, r3, #0x18\n\t"
            "mov r1, sb\n\t"
            "lsls r1, r1, #0x18\n\t"
            "lsrs r1, r1, #0x18\n\t"
            "mov sb, r1\n\t"
            "mov r0, r8\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "mov r8, r0\n\t"
            "lsls r1, r4, #4\n\t"
            "orrs r1, r4\n\t"
            "lsls r1, r1, #0x18\n\t"
            "lsrs r1, r1, #0x18\n\t"
            "str r3, [sp, #0x28]\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "add r2, sp, #0xc\n\t"
            "ldrh r0, [r5]\n\t"
            "ldrh r1, [r6]\n\t"
            "subs r0, r0, r1\n\t"
            "strh r0, [r2]\n\t"
            "ldrh r0, [r5, #2]\n\t"
            "ldrh r1, [r6, #2]\n\t"
            "subs r0, r0, r1\n\t"
            "strh r0, [r2, #2]\n\t"
            "ldrh r0, [r5, #4]\n\t"
            "ldrh r1, [r6, #4]\n\t"
            "subs r0, r0, r1\n\t"
            "strh r0, [r2, #4]\n\t"
            "ldrh r0, [r5, #8]\n\t"
            "ldrh r1, [r6, #8]\n\t"
            "subs r0, r0, r1\n\t"
            "strh r0, [r2, #6]\n\t"
            "ldrh r0, [r5, #0xa]\n\t"
            "ldrh r1, [r6, #0xa]\n\t"
            "subs r0, r0, r1\n\t"
            "strh r0, [r2, #8]\n\t"
            "ldrh r0, [r5, #6]\n\t"
            "ldrh r1, [r6, #6]\n\t"
            "subs r0, r0, r1\n\t"
            "strh r0, [r2, #0xa]\n\t"
            "add r0, sp, #0x24\n\t"
            "strb r4, [r0]\n\t"
            "ldr r3, [sp, #0x28]\n\t"
            "strb r3, [r0, #1]\n\t"
            "mov r1, sb\n\t"
            "strb r1, [r0, #2]\n\t"
            "movs r7, #0\n\t"
            "mov sl, r0\n\t"
            "movs r0, #1\n\t"
            "rsbs r0, r0, #0\n\t"
            "mov sb, r0\n\t"
            "add r6, sp, #0x18\n\t"
            "_081D2CFA:\n\t"
            "lsls r0, r7, #4\n\t"
            "subs r0, r0, r7\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r5, r0, #0x18\n\t"
            "mov r1, sl\n\t"
            "str r1, [sp]\n\t"
            "mov r0, sb\n\t"
            "str r0, [sp, #4]\n\t"
            "ldr r1, _081D2DA8\n\t"
            "lsls r0, r7, #2\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r0, [r0]\n\t"
            "str r0, [sp, #8]\n\t"
            "mov r0, r8\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "adds r3, r5, #0\n\t"
            "bl AddTextPrinterParameterized3\n\t"
            "lsls r0, r7, #1\n\t"
            "mov r4, sp\n\t"
            "adds r4, r4, r0\n\t"
            "adds r4, #0xc\n\t"
            "movs r1, #0\n\t"
            "ldrsh r0, [r4, r1]\n\t"
            "ldr r1, _081D2DAC\n\t"
            "cmp r0, #0\n\t"
            "blt _081D2D34\n\t"
            "ldr r1, _081D2DB0\n\t"
            "_081D2D34:\n\t"
            "adds r0, r6, #0\n\t"
            "bl StringCopy\n\t"
            "mov r0, sl\n\t"
            "str r0, [sp]\n\t"
            "mov r1, sb\n\t"
            "str r1, [sp, #4]\n\t"
            "str r6, [sp, #8]\n\t"
            "mov r0, r8\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0x36\n\t"
            "adds r3, r5, #0\n\t"
            "bl AddTextPrinterParameterized3\n\t"
            "movs r0, #0\n\t"
            "ldrsh r1, [r4, r0]\n\t"
            "adds r0, r1, #0\n\t"
            "cmp r1, #0\n\t"
            "bge _081D2D5C\n\t"
            "rsbs r0, r1, #0\n\t"
            "_081D2D5C:\n\t"
            "movs r4, #8\n\t"
            "cmp r0, #9\n\t"
            "bgt _081D2D64\n\t"
            "movs r4, #0x10\n\t"
            "_081D2D64:\n\t"
            "cmp r1, #0\n\t"
            "bge _081D2D6A\n\t"
            "rsbs r1, r1, #0\n\t"
            "_081D2D6A:\n\t"
            "adds r0, r6, #0\n\t"
            "movs r2, #0\n\t"
            "movs r3, #2\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "adds r2, r4, #0\n\t"
            "adds r2, #0x36\n\t"
            "mov r1, sl\n\t"
            "str r1, [sp]\n\t"
            "mov r0, sb\n\t"
            "str r0, [sp, #4]\n\t"
            "str r6, [sp, #8]\n\t"
            "mov r0, r8\n\t"
            "movs r1, #1\n\t"
            "adds r3, r5, #0\n\t"
            "bl AddTextPrinterParameterized3\n\t"
            "adds r0, r7, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r7, r0, #0x10\n\t"
            "cmp r7, #5\n\t"
            "bls _081D2CFA\n\t"
            "add sp, #0x2c\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D2DA8: .4byte 0x085FA9CC\n\t"
            "_081D2DAC: .4byte 0x085FA9C7\n\t"
            "_081D2DB0: .4byte 0x085FA9C4\n\t"
            ".syntax divided\n");
}

// JP 0x081D2DB4: kept as asm (compiler register allocation differs from US).
__attribute__((naked)) void DrawLevelUpWindowPg2(u16 windowId, u16 *currStats, u8 bgClr, u8 fgClr, u8 shadowClr)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #0x2c\n\t"
            "mov r8, r0\n\t"
            "adds r5, r1, #0\n\t"
            "adds r4, r2, #0\n\t"
            "adds r6, r3, #0\n\t"
            "ldr r2, [sp, #0x4c]\n\t"
            "lsls r4, r4, #0x18\n\t"
            "lsrs r4, r4, #0x18\n\t"
            "lsls r6, r6, #0x18\n\t"
            "lsrs r6, r6, #0x18\n\t"
            "lsls r2, r2, #0x18\n\t"
            "lsrs r2, r2, #0x18\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r0, r0, #0x18\n\t"
            "mov r8, r0\n\t"
            "lsls r1, r4, #4\n\t"
            "orrs r1, r4\n\t"
            "lsls r1, r1, #0x18\n\t"
            "lsrs r1, r1, #0x18\n\t"
            "str r2, [sp, #0x28]\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "add r1, sp, #0xc\n\t"
            "ldrh r0, [r5]\n\t"
            "strh r0, [r1]\n\t"
            "ldrh r0, [r5, #2]\n\t"
            "strh r0, [r1, #2]\n\t"
            "ldrh r0, [r5, #4]\n\t"
            "strh r0, [r1, #4]\n\t"
            "ldrh r0, [r5, #8]\n\t"
            "strh r0, [r1, #6]\n\t"
            "ldrh r0, [r5, #0xa]\n\t"
            "strh r0, [r1, #8]\n\t"
            "ldrh r0, [r5, #6]\n\t"
            "strh r0, [r1, #0xa]\n\t"
            "add r0, sp, #0x24\n\t"
            "strb r4, [r0]\n\t"
            "strb r6, [r0, #1]\n\t"
            "ldr r2, [sp, #0x28]\n\t"
            "strb r2, [r0, #2]\n\t"
            "movs r6, #0\n\t"
            "add r1, sp, #0x18\n\t"
            "mov sb, r1\n\t"
            "mov r7, r8\n\t"
            "mov sl, r0\n\t"
            "movs r2, #1\n\t"
            "rsbs r2, r2, #0\n\t"
            "mov r8, r2\n\t"
            "_081D2E1E:\n\t"
            "lsls r1, r6, #1\n\t"
            "mov r0, sp\n\t"
            "adds r0, r0, r1\n\t"
            "adds r0, #0xc\n\t"
            "movs r2, #0\n\t"
            "ldrsh r0, [r0, r2]\n\t"
            "movs r5, #3\n\t"
            "cmp r0, #0x63\n\t"
            "bgt _081D2E38\n\t"
            "movs r5, #1\n\t"
            "cmp r0, #9\n\t"
            "ble _081D2E38\n\t"
            "movs r5, #2\n\t"
            "_081D2E38:\n\t"
            "mov r0, sp\n\t"
            "adds r0, r0, r1\n\t"
            "adds r0, #0xc\n\t"
            "movs r2, #0\n\t"
            "ldrsh r1, [r0, r2]\n\t"
            "mov r0, sb\n\t"
            "movs r2, #0\n\t"
            "adds r3, r5, #0\n\t"
            "bl ConvertIntToDecimalStringN\n\t"
            "movs r4, #3\n\t"
            "subs r4, r4, r5\n\t"
            "lsls r4, r4, #0x13\n\t"
            "lsrs r4, r4, #0x10\n\t"
            "lsls r5, r6, #4\n\t"
            "subs r5, r5, r6\n\t"
            "lsls r5, r5, #0x18\n\t"
            "lsrs r5, r5, #0x18\n\t"
            "mov r0, sl\n\t"
            "str r0, [sp]\n\t"
            "mov r1, r8\n\t"
            "str r1, [sp, #4]\n\t"
            "ldr r1, _081D2EB4\n\t"
            "lsls r0, r6, #2\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r0, [r0]\n\t"
            "str r0, [sp, #8]\n\t"
            "adds r0, r7, #0\n\t"
            "movs r1, #1\n\t"
            "movs r2, #0\n\t"
            "adds r3, r5, #0\n\t"
            "bl AddTextPrinterParameterized3\n\t"
            "adds r4, #0x36\n\t"
            "lsls r4, r4, #0x18\n\t"
            "lsrs r4, r4, #0x18\n\t"
            "mov r2, sl\n\t"
            "str r2, [sp]\n\t"
            "mov r0, r8\n\t"
            "str r0, [sp, #4]\n\t"
            "mov r1, sb\n\t"
            "str r1, [sp, #8]\n\t"
            "adds r0, r7, #0\n\t"
            "movs r1, #1\n\t"
            "adds r2, r4, #0\n\t"
            "adds r3, r5, #0\n\t"
            "bl AddTextPrinterParameterized3\n\t"
            "adds r0, r6, #1\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r6, r0, #0x10\n\t"
            "cmp r6, #5\n\t"
            "bls _081D2E1E\n\t"
            "add sp, #0x2c\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081D2EB4: .4byte 0x085FA9CC\n\t"
            ".syntax divided\n");
}

void GetMonLevelUpWindowStats(struct Pokemon *mon, u16 *currStats)
{
    currStats[STAT_HP]    = GetMonData(mon, MON_DATA_MAX_HP);
    currStats[STAT_ATK]   = GetMonData(mon, MON_DATA_ATK);
    currStats[STAT_DEF]   = GetMonData(mon, MON_DATA_DEF);
    currStats[STAT_SPEED] = GetMonData(mon, MON_DATA_SPEED);
    currStats[STAT_SPATK] = GetMonData(mon, MON_DATA_SPATK);
    currStats[STAT_SPDEF] = GetMonData(mon, MON_DATA_SPDEF);
}
