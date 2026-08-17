#include "global.h"
#include "list_menu.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "constants/songs.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "window.h"

extern const struct SpriteTemplate sSpriteTemplate_ScrollArrowIndicator;
extern const struct SpriteTemplate sSpriteTemplate_RedArrowCursor;
extern const u32 gUnknown_85DFC30[];
extern const u32 gUnknown_85DFBF0[];
extern const u32 gUnknown_85DFB80[];
extern const u16 gUnknown_85DFB60[];
extern void Task_ScrollIndicatorArrowPair(u8 taskId);
extern const struct {
    u8 animNum:4;
    u8 bounceDir:4;
    u8 multiplier;
    u16 frequency;
} sScrollIndicatorTemplates[];
extern const struct Subsprite sSubsprite_RedOutline1;
extern const struct Subsprite sSubsprite_RedOutline2;
extern const struct Subsprite sSubsprite_RedOutline3;
extern const struct Subsprite sSubsprite_RedOutline4;
extern const struct Subsprite sSubsprite_RedOutline5;
extern const struct Subsprite sSubsprite_RedOutline6;
extern const struct Subsprite sSubsprite_RedOutline7;
extern const struct Subsprite sSubsprite_RedOutline8;
// Cursors after this point are created using a sprite with their own task.
// This allows them to have idle animations. Cursors prior to this are simply printed text.
#define CURSOR_OBJECT_START CURSOR_RED_OUTLINE

extern struct {
    u8 cursorPal:4;
    u8 fillValue:4;
    u8 cursorShadowPal:4;
    u8 lettersSpacing:6;
    u8 field_2_2:6; // unused
    u8 fontId:7;
    bool8 enabled:1;
} gListMenuOverride;

void Task_RedArrowCursor(void) {}
static void ListMenuCallSelectionChangedCallback(struct ListMenu *list, u8 onInit);
u8 ListMenuInitInternal(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow);
static __attribute__((naked)) void ListMenuPrintEntries(struct ListMenu *list, u16 startIndex, u16 yOffset, u16 count);
static __attribute__((naked)) void ListMenuDrawCursor(struct ListMenu *list);
static __attribute__((naked)) void ListMenuErasePrintedCursor(struct ListMenu *list, u16 selectedRow);
static u8 ListMenuUpdateSelectedRowIndexAndScrollOffset(struct ListMenu *list, bool8 movingDown);
static bool8 ListMenuChangeSelection(struct ListMenu *list, bool8 updateCursorAndCallCallback, u8 count, bool8 movingDown);
void ListMenuRemoveCursorObject(u8 taskId, u32 cursorObjId);
u8 ListMenuAddCursorObjectInternal(struct CursorStruct *cursor, u32 cursorObjId);
void ListMenuUpdateRedOutlineCursorObject(u8 taskId, u16 x, u16 y);
void ListMenuUpdateRedArrowCursorObject(u8 taskId, u16 x, u16 y);

struct ScrollIndicatorPair
{
    u8 field_0;
    u16 *scrollOffset;
    u16 fullyUpThreshold;
    u16 fullyDownThreshold;
    u8 topSpriteId;
    u8 bottomSpriteId;
    u16 tileTag;
    u16 palTag;
};

struct RedOutlineCursor
{
    struct SubspriteTable subspriteTable;
    struct Subsprite *subspritesPtr; // not a const pointer
    u8 spriteId;
    u16 tileTag;
    u16 palTag;
};

struct RedArrowCursor
{
    u8 spriteId;
    u16 tileTag;
    u16 palTag;
};

__attribute__((naked)) s32 DoMysteryGiftListMenu(const struct WindowTemplate *windowTemplate, const struct ListMenuTemplate *listMenuTemplate, u8 drawMode, u16 tileNum, u16 palOffset)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #8\n\t"
        "	mov ip, r0\n\t"
        "	str r1, [sp]\n\t"
        "	ldr r0, [sp, #0x28]\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	mov sl, r6\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r7, r3, #0x10\n\t"
        "	str r7, [sp, #4]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	ldr r5, _081AE1C4\n\t"
        "	ldrb r4, [r5, #4]\n\t"
        "	cmp r4, #1\n\t"
        "	beq _081AE1CC\n\t"
        "	cmp r4, #1\n\t"
        "	ble _081AE16A\n\t"
        "	cmp r4, #2\n\t"
        "	beq _081AE230\n\t"
        "_081AE16A:\n\t"
        "	mov r0, ip\n\t"
        "	bl AddWindow\n\t"
        "	strb r0, [r5, #5]\n\t"
        "	cmp r6, #1\n\t"
        "	beq _081AE188\n\t"
        "	cmp r6, #2\n\t"
        "	bne _081AE198\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	mov r1, sb\n\t"
        "	lsls r2, r1, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl LoadUserWindowBorderGfx\n\t"
        "_081AE188:\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	mov r3, r8\n\t"
        "	lsrs r2, r3, #0x14\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r1, [sp, #4]\n\t"
        "	bl DrawTextBorderOuter\n\t"
        "_081AE198:\n\t"
        "	ldr r0, _081AE1C8\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldr r1, [sp]\n\t"
        "	ldm r1!, {r3, r4, r5}\n\t"
        "	stm r2!, {r3, r4, r5}\n\t"
        "	ldm r1!, {r3, r4, r5}\n\t"
        "	stm r2!, {r3, r4, r5}\n\t"
        "	ldr r4, _081AE1C4\n\t"
        "	ldrb r1, [r4, #5]\n\t"
        "	strb r1, [r0, #0x10]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ListMenuInit\n\t"
        "	strb r0, [r4, #6]\n\t"
        "	ldrb r0, [r4, #5]\n\t"
        "	movs r1, #1\n\t"
        "	bl CopyWindowToVram\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r4, #4]\n\t"
        "	b _081AE248\n\t"
        "	.align 2, 0\n\t"
        "_081AE1C4: .4byte gUnknown_203CB50\n\t"
        "_081AE1C8: .4byte gMultiuseListMenuTemplate\n\t"
        "_081AE1CC:\n\t"
        "	ldrb r0, [r5, #6]\n\t"
        "	bl ListMenu_ProcessInput\n\t"
        "	str r0, [r5]\n\t"
        "	ldr r1, _081AE208\n\t"
        "	ldrh r0, [r1, #0x2e]\n\t"
        "	ands r4, r0\n\t"
        "	cmp r4, #0\n\t"
        "	beq _081AE1E2\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r5, #4]\n\t"
        "_081AE1E2:\n\t"
        "	ldrh r1, [r1, #0x2e]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081AE1F6\n\t"
        "	movs r0, #2\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	str r0, [r5]\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r5, #4]\n\t"
        "_081AE1F6:\n\t"
        "	ldrb r0, [r5, #4]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _081AE248\n\t"
        "	cmp r6, #0\n\t"
        "	bne _081AE20C\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	b _081AE21E\n\t"
        "	.align 2, 0\n\t"
        "_081AE208: .4byte gMain\n\t"
        "_081AE20C:\n\t"
        "	mov r4, sl\n\t"
        "	cmp r4, #0\n\t"
        "	blt _081AE21E\n\t"
        "	cmp r4, #2\n\t"
        "	bgt _081AE21E\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	movs r1, #0\n\t"
        "	bl ClearStdWindowAndFrame\n\t"
        "_081AE21E:\n\t"
        "	ldr r0, _081AE22C\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	movs r1, #1\n\t"
        "	bl CopyWindowToVram\n\t"
        "	b _081AE248\n\t"
        "	.align 2, 0\n\t"
        "_081AE22C: .4byte gUnknown_203CB50\n\t"
        "_081AE230:\n\t"
        "	ldrb r0, [r5, #6]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl DestroyListMenuTask\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	bl RemoveWindow\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r5, #4]\n\t"
        "	ldr r0, [r5]\n\t"
        "	b _081AE24C\n\t"
        "_081AE248:\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "_081AE24C:\n\t"
        "	add sp, #8\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

u8 ListMenuInit(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow)
{
    u8 taskId = ListMenuInitInternal(listMenuTemplate, scrollOffset, selectedRow);
    PutWindowTilemap(listMenuTemplate->windowId);
    CopyWindowToVram(listMenuTemplate->windowId, COPYWIN_GFX);

    return taskId;
}

u8 ListMenuInitInRect(struct ListMenuTemplate *listMenuTemplate, struct ListMenuWindowRect *rect, u16 scrollOffset, u16 selectedRow)
{
    s32 i;

    u8 taskId = ListMenuInitInternal(listMenuTemplate, scrollOffset, selectedRow);
    for (i = 0; rect[i].palNum != 0xFF; i++)
    {
        PutWindowRectTilemapOverridePalette(listMenuTemplate->windowId,
                                            rect[i].x,
                                            rect[i].y,
                                            rect[i].width,
                                            rect[i].height,
                                            rect[i].palNum);
    }
    CopyWindowToVram(listMenuTemplate->windowId, COPYWIN_GFX);

    return taskId;
}

s32 ListMenu_ProcessInput(u8 listTaskId)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;

    if (JOY_NEW(A_BUTTON))
    {
        return list->template.items[list->scrollOffset + list->selectedRow].id;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        return LIST_CANCEL;
    }
    else if (JOY_REPEAT(DPAD_UP))
    {
        ListMenuChangeSelection(list, TRUE, 1, FALSE);
        return LIST_NOTHING_CHOSEN;
    }
    else if (JOY_REPEAT(DPAD_DOWN))
    {
        ListMenuChangeSelection(list, TRUE, 1, TRUE);
        return LIST_NOTHING_CHOSEN;
    }
    else // try to move by one window scroll
    {
        bool16 rightButton, leftButton;
        switch (list->template.scrollMultiple)
        {
        case LIST_NO_MULTIPLE_SCROLL:
        default:
            leftButton = FALSE;
            rightButton = FALSE;
            break;
        case LIST_MULTIPLE_SCROLL_DPAD:
            // note: JOY_REPEAT won't match here
            leftButton = JOY_REPEAT(DPAD_LEFT);
            rightButton = JOY_REPEAT(DPAD_RIGHT);
            break;
        case LIST_MULTIPLE_SCROLL_L_R:
            // same as above
            leftButton = JOY_REPEAT(L_BUTTON);
            rightButton = JOY_REPEAT(R_BUTTON);
            break;
        }

        if (leftButton)
        {
            ListMenuChangeSelection(list, TRUE, list->template.maxShowed, FALSE);
            return LIST_NOTHING_CHOSEN;
        }
        else if (rightButton)
        {
            ListMenuChangeSelection(list, TRUE, list->template.maxShowed, TRUE);
            return LIST_NOTHING_CHOSEN;
        }
        else
        {
            return LIST_NOTHING_CHOSEN;
        }
    }
}
void DestroyListMenuTask(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;

    if (scrollOffset != NULL)
        *scrollOffset = list->scrollOffset;
    if (selectedRow != NULL)
        *selectedRow = list->selectedRow;

    if (list->taskId != TASK_NONE)
        ListMenuRemoveCursorObject(list->taskId, list->template.cursorKind - CURSOR_OBJECT_START);

    DestroyTask(listTaskId);
}

void RedrawListMenu(u8 listTaskId)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;

    FillWindowPixelBuffer(list->template.windowId, PIXEL_FILL(list->template.fillValue));
    ListMenuPrintEntries(list, list->scrollOffset, 0, list->template.maxShowed);
    ListMenuDrawCursor(list);
    CopyWindowToVram(list->template.windowId, COPYWIN_GFX);
}

void ChangeListMenuPals(u8 listTaskId, u8 cursorPal, u8 fillValue, u8 cursorShadowPal)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;

    list->template.cursorPal = cursorPal;
    list->template.fillValue = fillValue;
    list->template.cursorShadowPal = cursorShadowPal;
}

void ChangeListMenuCoords(u8 listTaskId, u8 x, u8 y)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;

    SetWindowAttribute(list->template.windowId, WINDOW_TILEMAP_LEFT, x);
    SetWindowAttribute(list->template.windowId, WINDOW_TILEMAP_TOP, y);
}

s32 ListMenuTestInput(struct ListMenuTemplate *template, u32 scrollOffset, u32 selectedRow, u16 keys, u16 *newScrollOffset, u16 *newSelectedRow)
{
    struct ListMenu list;

    list.template = *template;
    list.scrollOffset = scrollOffset;
    list.selectedRow = selectedRow;
    list.unk_1C = 0;
    list.unk_1D = 0;

    if (keys == DPAD_UP)
        ListMenuChangeSelection(&list, FALSE, 1, FALSE);
    if (keys == DPAD_DOWN)
        ListMenuChangeSelection(&list, FALSE, 1, TRUE);

    if (newScrollOffset != NULL)
        *newScrollOffset = list.scrollOffset;
    if (newSelectedRow != NULL)
        *newSelectedRow = list.selectedRow;

    return LIST_NOTHING_CHOSEN;
}
void ListMenuGetCurrentItemArrayId(u8 listTaskId, u16 *arrayId)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;

    if (arrayId != NULL)
        *arrayId = list->scrollOffset + list->selectedRow;
}

void ListMenuGetScrollAndRow(u8 listTaskId, u16 *scrollOffset, u16 *selectedRow)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;

    if (scrollOffset != NULL)
        *scrollOffset = list->scrollOffset;
    if (selectedRow != NULL)
        *selectedRow = list->selectedRow;
}

u16 ListMenuGetYCoordForPrintingArrowCursor(u8 listTaskId)
{
    struct ListMenu *list = (void *) gTasks[listTaskId].data;
    u8 yMultiplier = GetFontAttribute(list->template.fontId, 1) + list->template.itemVerticalPadding;

    return list->selectedRow * yMultiplier + list->template.upText_Y;
}

__attribute__((naked)) u8 ListMenuInitInternal(struct ListMenuTemplate *listMenuTemplate, u16 scrollOffset, u16 selectedRow)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r6, r2, #0\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	lsls r6, r6, #0x10\n\t"
        "	lsrs r6, r6, #0x10\n\t"
        "	ldr r0, _081AE67C\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _081AE680\n\t"
        "	adds r7, r0, r1\n\t"
        "	adds r0, r7, #0\n\t"
        "	ldm r4!, {r1, r2, r3}\n\t"
        "	stm r0!, {r1, r2, r3}\n\t"
        "	ldm r4!, {r1, r2, r3}\n\t"
        "	stm r0!, {r1, r2, r3}\n\t"
        "	movs r1, #0\n\t"
        "	strh r5, [r7, #0x18]\n\t"
        "	strh r6, [r7, #0x1a]\n\t"
        "	strb r1, [r7, #0x1c]\n\t"
        "	strb r1, [r7, #0x1d]\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r7, #0x1e]\n\t"
        "	strb r1, [r7, #0x1f]\n\t"
        "	ldr r3, _081AE684\n\t"
        "	ldrb r1, [r7, #0x14]\n\t"
        "	movs r5, #0xf\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	ldrb r4, [r3]\n\t"
        "	movs r2, #0x10\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r0, r4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	ldrb r1, [r7, #0x15]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ands r0, r5\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	ldrb r0, [r7, #0x15]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	ands r5, r0\n\t"
        "	ldrb r0, [r3, #1]\n\t"
        "	ands r2, r0\n\t"
        "	orrs r2, r5\n\t"
        "	strb r2, [r3, #1]\n\t"
        "	ldrb r1, [r7, #0x16]\n\t"
        "	lsls r1, r1, #0x1d\n\t"
        "	lsrs r1, r1, #0x11\n\t"
        "	ldr r0, [r3]\n\t"
        "	ldr r2, _081AE688\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r3]\n\t"
        "	ldrb r0, [r7, #0x17]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r0, r0, #0x1a\n\t"
        "	strb r0, [r3, #3]\n\t"
        "	ldrh r0, [r7, #0xc]\n\t"
        "	ldrh r1, [r7, #0xe]\n\t"
        "	cmp r0, r1\n\t"
        "	bhs _081AE644\n\t"
        "	strh r0, [r7, #0xe]\n\t"
        "_081AE644:\n\t"
        "	ldrb r0, [r7, #0x10]\n\t"
        "	ldrb r2, [r7, #0x15]\n\t"
        "	lsls r2, r2, #0x1c\n\t"
        "	lsrs r1, r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldrh r1, [r7, #0x18]\n\t"
        "	ldrh r3, [r7, #0xe]\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ListMenuPrintEntries\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl ListMenuDrawCursor\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ListMenuCallSelectionChangedCallback\n\t"
        "	mov r0, r8\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081AE67C: .4byte 0x081AE131\n\t"
        "_081AE680: .4byte gUnknown_3005B68\n\t"
        "_081AE684: .4byte gUnknown_3006040\n\t"
        "_081AE688: .4byte 0xFFFC0FFF\n\t"
        ".syntax divided\n\t"
    );
}

static void ListMenuPrint(struct ListMenu *list, const u8 *str, u8 x, u8 y)
{
    u8 colors[3];
    if (gListMenuOverride.enabled)
    {
        colors[0] = gListMenuOverride.fillValue;
        colors[1] = gListMenuOverride.cursorPal;
        colors[2] = gListMenuOverride.cursorShadowPal;
        AddTextPrinterParameterized4(list->template.windowId,
                                     gListMenuOverride.fontId,
                                     x, y,
                                     gListMenuOverride.lettersSpacing,
                                     0, colors, TEXT_SKIP_DRAW, str);

        gListMenuOverride.enabled = FALSE;
    }
    else
    {
        colors[0] = list->template.fillValue;
        colors[1] = list->template.cursorPal;
        colors[2] = list->template.cursorShadowPal;
        AddTextPrinterParameterized4(list->template.windowId,
                                     list->template.fontId,
                                     x, y,
                                     list->template.lettersSpacing,
                                     0, colors, TEXT_SKIP_DRAW, str);
    }
}


static __attribute__((naked)) void ListMenuPrintEntries(struct ListMenu *list, u16 startIndex, u16 yOffset, u16 count)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	mov sb, r1\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	str r2, [sp]\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r3, r3, #0x10\n\t"
        "	mov sl, r3\n\t"
        "	ldrb r0, [r4, #0x17]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r0, r0, #0x1a\n\t"
        "	movs r1, #1\n\t"
        "	bl GetFontAttribute\n\t"
        "	ldrb r1, [r4, #0x16]\n\t"
        "	lsls r1, r1, #0x1a\n\t"
        "	lsrs r1, r1, #0x1d\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	mov r8, r0\n\t"
        "	cmp r8, sl\n\t"
        "	bge _081AE7E8\n\t"
        "_081AE782:\n\t"
        "	ldr r0, [r4]\n\t"
        "	mov r2, sb\n\t"
        "	lsls r1, r2, #3\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldr r2, [r0, #4]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	cmp r2, r0\n\t"
        "	beq _081AE79A\n\t"
        "	ldrb r6, [r4, #0x12]\n\t"
        "	b _081AE79C\n\t"
        "_081AE79A:\n\t"
        "	ldrb r6, [r4, #0x11]\n\t"
        "_081AE79C:\n\t"
        "	ldr r0, [sp]\n\t"
        "	add r0, r8\n\t"
        "	ldr r2, [sp, #4]\n\t"
        "	adds r1, r0, #0\n\t"
        "	muls r1, r2, r1\n\t"
        "	ldrb r0, [r4, #0x14]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	adds r7, r2, #0\n\t"
        "	ldr r3, [r4, #8]\n\t"
        "	cmp r3, #0\n\t"
        "	beq _081AE7C6\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, r5, r1\n\t"
        "	ldr r1, [r1, #4]\n\t"
        "	bl _call_via_r3\n\t"
        "_081AE7C6:\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl ListMenuPrint\n\t"
        "	mov r0, sb\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	movs r0, #1\n\t"
        "	add r8, r0\n\t"
        "	cmp r8, sl\n\t"
        "	blt _081AE782\n\t"
        "_081AE7E8:\n\t"
        "	add sp, #8\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

static __attribute__((naked)) void ListMenuDrawCursor(struct ListMenu *list)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldrb r0, [r6, #0x17]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r0, r0, #0x1a\n\t"
        "	movs r1, #1\n\t"
        "	bl GetFontAttribute\n\t"
        "	ldrb r1, [r6, #0x16]\n\t"
        "	lsls r1, r1, #0x1a\n\t"
        "	lsrs r1, r1, #0x1d\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrb r1, [r6, #0x13]\n\t"
        "	mov r8, r1\n\t"
        "	ldrh r1, [r6, #0x1a]\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldrb r0, [r6, #0x14]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldrb r0, [r6, #0x17]\n\t"
        "	lsrs r0, r0, #6\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081AE8E4\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _081AE83E\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081AE848\n\t"
        "	b _081AE8E4\n\t"
        "_081AE83E:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _081AE85C\n\t"
        "	cmp r0, #3\n\t"
        "	beq _081AE8A4\n\t"
        "	b _081AE8E4\n\t"
        "_081AE848:\n\t"
        "	ldr r1, _081AE858\n\t"
        "	adds r0, r6, #0\n\t"
        "	mov r2, r8\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl ListMenuPrint\n\t"
        "	b _081AE8E4\n\t"
        "	.align 2, 0\n\t"
        "_081AE858: .4byte gText_SelectorArrow2\n\t"
        "_081AE85C:\n\t"
        "	ldrb r0, [r6, #0x1e]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _081AE86C\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl ListMenuAddCursorObject\n\t"
        "	strb r0, [r6, #0x1e]\n\t"
        "_081AE86C:\n\t"
        "	ldrb r5, [r6, #0x1e]\n\t"
        "	ldrb r0, [r6, #0x10]\n\t"
        "	movs r1, #1\n\t"
        "	bl GetWindowAttribute\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x13\n\t"
        "	ldr r0, _081AE8A0\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldrb r0, [r6, #0x10]\n\t"
        "	movs r1, #2\n\t"
        "	bl GetWindowAttribute\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #3\n\t"
        "	adds r2, r2, r7\n\t"
        "	subs r2, #1\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl ListMenuUpdateCursorObject\n\t"
        "	b _081AE8E4\n\t"
        "	.align 2, 0\n\t"
        "_081AE8A0: .4byte 0xFFFF0000\n\t"
        "_081AE8A4:\n\t"
        "	ldrb r0, [r6, #0x1e]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _081AE8B4\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ListMenuAddCursorObject\n\t"
        "	strb r0, [r6, #0x1e]\n\t"
        "_081AE8B4:\n\t"
        "	ldrb r5, [r6, #0x1e]\n\t"
        "	ldrb r0, [r6, #0x10]\n\t"
        "	movs r1, #1\n\t"
        "	bl GetWindowAttribute\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #3\n\t"
        "	add r4, r8\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldrb r0, [r6, #0x10]\n\t"
        "	movs r1, #2\n\t"
        "	bl GetWindowAttribute\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #3\n\t"
        "	adds r2, r2, r7\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl ListMenuUpdateCursorObject\n\t"
        "_081AE8E4:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

static u8 ListMenuAddCursorObject(struct ListMenu *list, u32 cursorObjId)
{
    struct CursorStruct cursor;

    cursor.left = 0;
    cursor.top = DISPLAY_HEIGHT;
    cursor.rowWidth = GetWindowAttribute(list->template.windowId, WINDOW_WIDTH) * 8 + 2;
    cursor.rowHeight = GetFontAttribute(list->template.fontId, FONTATTR_MAX_LETTER_HEIGHT) + 2;
    cursor.tileTag = 0x4000;
    cursor.palTag = TAG_NONE;
    cursor.palNum = 15;

    return ListMenuAddCursorObjectInternal(&cursor, cursorObjId);
}

static __attribute__((naked)) void ListMenuErasePrintedCursor(struct ListMenu *list, u16 selectedRow)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #8\n\t"
        "	adds r7, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	mov r8, r1\n\t"
        "	ldrb r1, [r7, #0x17]\n\t"
        "	lsrs r0, r1, #6\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081AE9CC\n\t"
        "	lsls r0, r1, #0x1a\n\t"
        "	lsrs r0, r0, #0x1a\n\t"
        "	movs r1, #1\n\t"
        "	bl GetFontAttribute\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r0, [r7, #0x16]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r0, r0, #0x1d\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldrb r0, [r7, #0x17]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r0, r0, #0x1a\n\t"
        "	movs r1, #0\n\t"
        "	bl GetMenuCursorDimensionByFont\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldrb r0, [r7, #0x17]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r0, r0, #0x1a\n\t"
        "	movs r1, #1\n\t"
        "	bl GetMenuCursorDimensionByFont\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrb r6, [r7, #0x10]\n\t"
        "	ldrb r2, [r7, #0x15]\n\t"
        "	lsls r2, r2, #0x1c\n\t"
        "	lsrs r1, r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldrb r2, [r7, #0x13]\n\t"
        "	mov r3, r8\n\t"
        "	muls r3, r4, r3\n\t"
        "	adds r4, r3, #0\n\t"
        "	ldrb r3, [r7, #0x14]\n\t"
        "	lsls r3, r3, #0x1c\n\t"
        "	lsrs r3, r3, #0x1c\n\t"
        "	adds r3, r3, r4\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r3, r3, #0x10\n\t"
        "	str r5, [sp]\n\t"
        "	str r0, [sp, #4]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl FillWindowPixelRect\n\t"
        "_081AE9CC:\n\t"
        "	add sp, #8\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

static u8 ListMenuUpdateSelectedRowIndexAndScrollOffset(struct ListMenu *list, bool8 movingDown)
{
    u16 selectedRow = list->selectedRow;
    u16 scrollOffset = list->scrollOffset;
    u16 newRow;
    u32 newScroll;

    if (!movingDown)
    {
        if (list->template.maxShowed == 1)
            newRow = 0;
        else
            newRow = list->template.maxShowed - ((list->template.maxShowed / 2) + (list->template.maxShowed % 2)) - 1;

        if (scrollOffset == 0)
        {
            while (selectedRow != 0)
            {
                selectedRow--;
                if (list->template.items[scrollOffset + selectedRow].id != LIST_HEADER)
                {
                    list->selectedRow = selectedRow;
                    return 1;
                }
            }

            return 0;
        }
        else
        {
            while (selectedRow > newRow)
            {
                selectedRow--;
                if (list->template.items[scrollOffset + selectedRow].id != LIST_HEADER)
                {
                    list->selectedRow = selectedRow;
                    return 1;
                }
            }

            newScroll = scrollOffset - 1;
        }
    }
    else
    {
        if (list->template.maxShowed == 1)
            newRow = 0;
        else
            newRow = ((list->template.maxShowed / 2) + (list->template.maxShowed % 2));

        if (scrollOffset == list->template.totalItems - list->template.maxShowed)
        {
            while (selectedRow < list->template.maxShowed - 1)
            {
                selectedRow++;
                if (list->template.items[scrollOffset + selectedRow].id != LIST_HEADER)
                {
                    list->selectedRow = selectedRow;
                    return 1;
                }
            }

            return 0;
        }
        else
        {
            while (selectedRow < newRow)
            {
                selectedRow++;
                if (list->template.items[scrollOffset + selectedRow].id != LIST_HEADER)
                {
                    list->selectedRow = selectedRow;
                    return 1;
                }
            }

            newScroll = scrollOffset + 1;
        }
    }

    list->selectedRow = newRow;
    list->scrollOffset = newScroll;
    return 2;
}

static void ListMenuScroll(struct ListMenu *list, u8 count, bool8 movingDown)
{
    if (count >= list->template.maxShowed)
    {
        FillWindowPixelBuffer(list->template.windowId, PIXEL_FILL(list->template.fillValue));
        ListMenuPrintEntries(list, list->scrollOffset, 0, list->template.maxShowed);
    }
    else
    {
        u8 yMultiplier = GetFontAttribute(list->template.fontId, FONTATTR_MAX_LETTER_HEIGHT) + list->template.itemVerticalPadding;

        if (!movingDown)
        {
            u16 y, width, height;

            ScrollWindow(list->template.windowId, 1, count * yMultiplier, PIXEL_FILL(list->template.fillValue));
            ListMenuPrintEntries(list, list->scrollOffset, 0, count);

            y = (list->template.maxShowed * yMultiplier) + list->template.upText_Y;
            width = GetWindowAttribute(list->template.windowId, WINDOW_WIDTH) * 8;
            height = (GetWindowAttribute(list->template.windowId, WINDOW_HEIGHT) * 8) - y;
            FillWindowPixelRect(list->template.windowId,
                                PIXEL_FILL(list->template.fillValue),
                                0, y, width, height);
        }
        else
        {
            u16 width;

            ScrollWindow(list->template.windowId, 0, count * yMultiplier, PIXEL_FILL(list->template.fillValue));
            ListMenuPrintEntries(list, list->scrollOffset + (list->template.maxShowed - count), list->template.maxShowed - count, count);

            width = GetWindowAttribute(list->template.windowId, WINDOW_WIDTH) * 8;
            FillWindowPixelRect(list->template.windowId,
                                PIXEL_FILL(list->template.fillValue),
                                0, 0, width, list->template.upText_Y);
        }
    }
}
static bool8 ListMenuChangeSelection(struct ListMenu *list, bool8 updateCursorAndCallCallback, u8 count, bool8 movingDown)
{
    u16 oldSelectedRow;
    u8 selectionChange, i, cursorCount;

    oldSelectedRow = list->selectedRow;
    cursorCount = 0;
    selectionChange = 0;
    for (i = 0; i < count; i++)
    {
        do
        {
            u8 ret = ListMenuUpdateSelectedRowIndexAndScrollOffset(list, movingDown);
            selectionChange |= ret;
            if (ret != 2)
                break;
            cursorCount++;
        } while (list->template.items[list->scrollOffset + list->selectedRow].id == LIST_HEADER);
    }

    if (updateCursorAndCallCallback)
    {
        switch (selectionChange)
        {
        case 0:
        default:
            return TRUE;
        case 1:
            ListMenuErasePrintedCursor(list, oldSelectedRow);
            ListMenuDrawCursor(list);
            ListMenuCallSelectionChangedCallback(list, FALSE);
            CopyWindowToVram(list->template.windowId, COPYWIN_GFX);
            break;
        case 2:
        case 3:
            ListMenuErasePrintedCursor(list, oldSelectedRow);
            ListMenuScroll(list, cursorCount, movingDown);
            ListMenuDrawCursor(list);
            ListMenuCallSelectionChangedCallback(list, FALSE);
            CopyWindowToVram(list->template.windowId, COPYWIN_GFX);
            break;
        }
    }

    return FALSE;
}

static void ListMenuCallSelectionChangedCallback(struct ListMenu *list, u8 onInit)
{
    if (list->template.moveCursorFunc != NULL)
        list->template.moveCursorFunc(list->template.items[list->scrollOffset + list->selectedRow].id, onInit, list);
}

void ListMenuOverrideSetColors(u8 cursorPal, u8 fillValue, u8 cursorShadowPal)
{
    gListMenuOverride.cursorPal = cursorPal;
    gListMenuOverride.fillValue = fillValue;
    gListMenuOverride.cursorShadowPal = cursorShadowPal;
    gListMenuOverride.enabled = TRUE;
}


void ListMenuDefaultCursorMoveFunc(s32 itemIndex, bool8 onInit, struct ListMenu *list)
{
    if (!onInit)
        PlaySE(SE_SELECT);
}

u32 ListMenuGetUnkIndicatorsStructFields(u8 taskId, u8 field)
{
    struct ListMenu *list = (void *) gTasks[taskId].data;

    switch (field)
    {
    case 0:
    case 1:
        return (u32) list->template.moveCursorFunc;
    case 2:
        return list->template.totalItems;
    case 3:
        return list->template.maxShowed;
    case 4:
        return list->template.windowId;
    case 5:
        return list->template.header_X;
    case 6:
        return list->template.item_X;
    case 7:
        return list->template.cursor_X;
    case 8:
        return list->template.upText_Y;
    case 9:
        return list->template.cursorPal;
    case 10:
        return list->template.fillValue;
    case 11:
        return list->template.cursorShadowPal;
    case 12:
        return list->template.lettersSpacing;
    case 13:
        return list->template.itemVerticalPadding;
    case 14:
        return list->template.scrollMultiple;
    case 15:
        return list->template.fontId;
    case 16:
        return list->template.cursorKind;
    default:
        return -1;
    }
}

void ListMenuSetUnkIndicatorsStructField(u8 taskId, u8 field, u32 value)
{
    struct ListMenu *list = (void *) gTasks[taskId].data;

    switch (field)
    {
    case 0:
    case 1:
        list->template.moveCursorFunc = (void (*)(s32, bool8, struct ListMenu *)) value;
        break;
    case 2:
        list->template.totalItems = value;
        break;
    case 3:
        list->template.maxShowed = value;
        break;
    case 4:
        list->template.windowId = value;
        break;
    case 5:
        list->template.header_X = value;
        break;
    case 6:
        list->template.item_X = value;
        break;
    case 7:
        list->template.cursor_X = value;
        break;
    case 8:
        list->template.upText_Y = value;
        break;
    case 9:
        list->template.cursorPal = value;
        break;
    case 10:
        list->template.fillValue = value;
        break;
    case 11:
        list->template.cursorShadowPal = value;
        break;
    case 12:
        list->template.lettersSpacing = value;
        break;
    case 13:
        list->template.itemVerticalPadding = value;
        break;
    case 14:
        list->template.scrollMultiple = value;
        break;
    case 15:
        list->template.fontId = value;
        break;
    case 16:
        list->template.cursorKind = value;
        break;
    }
}

#define tState data[0]
#define tAnimNum data[1]
#define tBounceDir data[2]
#define tMultiplier data[3]
#define tFrequency data[4]
#define tSinePos data[5]

void SpriteCallback_ScrollIndicatorArrow(struct Sprite *sprite)
{
    s32 multiplier;

    switch (sprite->tState)
    {
    case 0:
        StartSpriteAnim(sprite, sprite->tAnimNum);
        sprite->tState++;
        break;
    case 1:
        switch (sprite->tBounceDir)
        {
        case 0:
            multiplier = sprite->tMultiplier;
            sprite->x2 = (gSineTable[(u8)(sprite->tSinePos)] * multiplier) / 256;
            break;
        case 1:
            multiplier = sprite->tMultiplier;
            sprite->y2 = (gSineTable[(u8)(sprite->tSinePos)] * multiplier) / 256;
            break;
        }
        sprite->tSinePos += sprite->tFrequency;
        break;
    }
}

#undef tState
#undef tAnimNum
#undef tBounceDir
#undef tMultiplier
#undef tFrequency
#undef tSinePos

#define tState data[0]
#define tAnimNum data[1]
#define tBounceDir data[2]
#define tMultiplier data[3]
#define tFrequency data[4]
#define tSinePos data[5]

u8 AddScrollIndicatorArrowObject(u8 arrowDir, u8 x, u8 y, u16 tileTag, u16 palTag)
{
    u8 spriteId;
    struct SpriteTemplate spriteTemplate;

    spriteTemplate = sSpriteTemplate_ScrollArrowIndicator;
    spriteTemplate.tileTag = tileTag;
    spriteTemplate.paletteTag = palTag;

    spriteId = CreateSprite(&spriteTemplate, x, y, 0);
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].tState = 0;
    gSprites[spriteId].tAnimNum = sScrollIndicatorTemplates[arrowDir].animNum;
    gSprites[spriteId].tBounceDir = sScrollIndicatorTemplates[arrowDir].bounceDir;
    gSprites[spriteId].tMultiplier = sScrollIndicatorTemplates[arrowDir].multiplier;
    gSprites[spriteId].tFrequency = sScrollIndicatorTemplates[arrowDir].frequency;
    gSprites[spriteId].tSinePos = 0;

    return spriteId;
}

#undef tState
#undef tAnimNum
#undef tBounceDir
#undef tMultiplier
#undef tFrequency
#undef tSinePos


u8 AddScrollIndicatorArrowPair(const struct ScrollArrowsTemplate *arrowInfo, u16 *scrollOffset)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePal;
    struct ScrollIndicatorPair *data;
    u8 taskId;

    spriteSheet.data = gUnknown_85DFB80;
    spriteSheet.size = 0x100;
    spriteSheet.tag = arrowInfo->tileTag;
    LoadCompressedSpriteSheet(&spriteSheet);

    if (arrowInfo->palTag == TAG_NONE)
    {
        LoadPalette(gUnknown_85DFB60, OBJ_PLTT_ID(arrowInfo->palNum), PLTT_SIZE_4BPP);
    }
    else
    {
        spritePal.data = gUnknown_85DFB60;
        spritePal.tag = arrowInfo->palTag;
        LoadSpritePalette(&spritePal);
    }

    taskId = CreateTask(Task_ScrollIndicatorArrowPair, 0);
    data = (void *) gTasks[taskId].data;

    data->field_0 = 0;
    data->scrollOffset = scrollOffset;
    data->fullyUpThreshold = arrowInfo->fullyUpThreshold;
    data->fullyDownThreshold = arrowInfo->fullyDownThreshold;
    data->tileTag = arrowInfo->tileTag;
    data->palTag = arrowInfo->palTag;
    data->topSpriteId = AddScrollIndicatorArrowObject(arrowInfo->firstArrowType, arrowInfo->firstX, arrowInfo->firstY, arrowInfo->tileTag, arrowInfo->palTag);
    data->bottomSpriteId = AddScrollIndicatorArrowObject(arrowInfo->secondArrowType, arrowInfo->secondX, arrowInfo->secondY, arrowInfo->tileTag, arrowInfo->palTag);

    if (arrowInfo->palTag == TAG_NONE)
    {
        gSprites[data->topSpriteId].oam.paletteNum = arrowInfo->palNum;
        gSprites[data->bottomSpriteId].oam.paletteNum = arrowInfo->palNum;
    }

    return taskId;
}


__attribute__((naked)) u8 AddScrollIndicatorArrowPairParameterized(u32 arrowType, s32 commonPos, s32 firstPos, s32 secondPos, s32 fullyDownThreshold, s32 tileTag, s32 palTag, u16 *scrollOffset)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	subs r0, #2\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _081AF19C\n\t"
        "	ldr r0, _081AF198\n\t"
        "	movs r1, #2\n\t"
        "	strb r1, [r0]\n\t"
        "	strb r4, [r0, #1]\n\t"
        "	strb r2, [r0, #2]\n\t"
        "	movs r1, #3\n\t"
        "	strb r1, [r0, #3]\n\t"
        "	strb r4, [r0, #4]\n\t"
        "	strb r3, [r0, #5]\n\t"
        "	b _081AF1AE\n\t"
        "	.align 2, 0\n\t"
        "_081AF198: .4byte gTempScrollArrowTemplate\n\t"
        "_081AF19C:\n\t"
        "	ldr r0, _081AF1D8\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	strb r2, [r0, #1]\n\t"
        "	strb r4, [r0, #2]\n\t"
        "	movs r1, #1\n\t"
        "	strb r1, [r0, #3]\n\t"
        "	strb r3, [r0, #4]\n\t"
        "	strb r4, [r0, #5]\n\t"
        "_081AF1AE:\n\t"
        "	adds r2, r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2, #6]\n\t"
        "	ldr r0, [sp, #8]\n\t"
        "	strh r0, [r2, #8]\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	strh r0, [r2, #0xa]\n\t"
        "	ldr r0, [sp, #0x10]\n\t"
        "	strh r0, [r2, #0xc]\n\t"
        "	strb r1, [r2, #0xe]\n\t"
        "	adds r0, r2, #0\n\t"
        "	ldr r1, [sp, #0x14]\n\t"
        "	bl AddScrollIndicatorArrowPair\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081AF1D8: .4byte gTempScrollArrowTemplate\n\t"
        ".syntax divided\n\t"
    );
}

void Task_ScrollIndicatorArrowPair(u8 taskId)
{
    struct ScrollIndicatorPair *data = (void *) gTasks[taskId].data;
    u16 currItem = (*data->scrollOffset);

    if (currItem == data->fullyUpThreshold && currItem != 0xFFFF)
        gSprites[data->topSpriteId].invisible = TRUE;
    else
        gSprites[data->topSpriteId].invisible = FALSE;

    if (currItem == data->fullyDownThreshold)
        gSprites[data->bottomSpriteId].invisible = TRUE;
    else
        gSprites[data->bottomSpriteId].invisible = FALSE;
}

void Task_ScrollIndicatorArrowPairOnMainMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    struct ScrollIndicatorPair *scrollData = (void *) data;

    if (data[15])
    {
        gSprites[scrollData->topSpriteId].invisible = FALSE;
        gSprites[scrollData->bottomSpriteId].invisible = TRUE;
    }
    else
    {
        gSprites[scrollData->topSpriteId].invisible = TRUE;
        gSprites[scrollData->bottomSpriteId].invisible = FALSE;
    }
}

void RemoveScrollIndicatorArrowPair(u8 taskId)
{
    struct ScrollIndicatorPair *data = (void *) gTasks[taskId].data;

    if (data->tileTag != TAG_NONE)
        FreeSpriteTilesByTag(data->tileTag);
    if (data->palTag != TAG_NONE)
        FreeSpritePaletteByTag(data->palTag);

    DestroySprite(&gSprites[data->topSpriteId]);
    DestroySprite(&gSprites[data->bottomSpriteId]);
    DestroyTask(taskId);
}

u8 ListMenuAddCursorObjectInternal(struct CursorStruct *cursor, u32 cursorObjId)
{
    switch (cursorObjId)
    {
    case CURSOR_RED_OUTLINE - CURSOR_OBJECT_START:
    default:
        return ListMenuAddRedOutlineCursorObject(cursor);
    case CURSOR_RED_ARROW - CURSOR_OBJECT_START:
        return ListMenuAddRedArrowCursorObject(cursor);
    }
}


void ListMenuUpdateCursorObject(u8 taskId, u16 x, u16 y, u32 cursorObjId)
{
    switch (cursorObjId)
    {
    case CURSOR_RED_OUTLINE - CURSOR_OBJECT_START:
        ListMenuUpdateRedOutlineCursorObject(taskId, x, y);
        break;
    case CURSOR_RED_ARROW - CURSOR_OBJECT_START:
        ListMenuUpdateRedArrowCursorObject(taskId, x, y);
        break;
    }
}

void ListMenuRemoveCursorObject(u8 taskId, u32 cursorObjId)
{
    switch (cursorObjId)
    {
    case CURSOR_RED_OUTLINE - CURSOR_OBJECT_START:
        ListMenuRemoveRedOutlineCursorObject(taskId);
        break;
    case CURSOR_RED_ARROW - CURSOR_OBJECT_START:
        ListMenuRemoveRedArrowCursorObject(taskId);
        break;
    }
}


void Task_RedOutlineCursor(void) {}
u8 ListMenuGetRedOutlineCursorSpriteCount(u16 rowWidth, u16 rowHeight)
{
    s32 i;
    s32 count = 4;

    if (rowWidth > 16)
    {
        for (i = 8; i < (rowWidth - 8); i += 8)
            count += 2;
    }
    if (rowHeight > 16)
    {
        for (i = 8; i < (rowHeight - 8); i += 8)
            count += 2;
    }

    return count;
}

void ListMenuSetUpRedOutlineCursorSpriteOamTable(u16 rowWidth, u16 rowHeight, struct Subsprite *subsprites)
{
    s32 i, j, id = 0;

    subsprites[id] = sSubsprite_RedOutline1;
    subsprites[id].x = 136;
    subsprites[id].y = 136;
    id++;

    subsprites[id] = sSubsprite_RedOutline2;
    subsprites[id].x = rowWidth + 128;
    subsprites[id].y = 136;
    id++;

    subsprites[id] = sSubsprite_RedOutline7;
    subsprites[id].x = 136;
    subsprites[id].y = rowHeight + 128;
    id++;

    subsprites[id] = sSubsprite_RedOutline8;
    subsprites[id].x = rowWidth + 128;
    subsprites[id].y = rowHeight + 128;
    id++;

    if (rowWidth > 16)
    {
        for (i = 8; i < rowWidth - 8; i += 8)
        {
            subsprites[id] = sSubsprite_RedOutline3;
            subsprites[id].x = i - 120;
            subsprites[id].y = -120;
            id++;

            subsprites[id] = sSubsprite_RedOutline6;
            subsprites[id].x = i - 120;
            subsprites[id].y = rowHeight + 128;
            id++;
        }
    }

    if (rowHeight > 16)
    {
        for (j = 8; j < rowHeight - 8; j += 8)
        {
            subsprites[id] = sSubsprite_RedOutline4;
            subsprites[id].x = 136;
            subsprites[id].y = j - 120;
            id++;

            subsprites[id] = sSubsprite_RedOutline5;
            subsprites[id].x = rowWidth + 128;
            subsprites[id].y = j - 120;
            id++;
        }
    }
}


u8 ListMenuAddRedOutlineCursorObject(struct CursorStruct *cursor)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePal;
    struct RedOutlineCursor *data;
    struct SpriteTemplate spriteTemplate;
    u8 taskId;

    spriteSheet.data = gUnknown_85DFBF0;
    spriteSheet.size = 0x100;
    spriteSheet.tag = cursor->tileTag;
    LoadCompressedSpriteSheet(&spriteSheet);

    if (cursor->palTag == TAG_NONE)
    {
        LoadPalette(gUnknown_85DFB60, OBJ_PLTT_ID(cursor->palNum), PLTT_SIZE_4BPP);
    }
    else
    {
        spritePal.data = gUnknown_85DFB60;
        spritePal.tag = cursor->palTag;
        LoadSpritePalette(&spritePal);
    }

    taskId = CreateTask(Task_RedOutlineCursor, 0);
    data = (void *) gTasks[taskId].data;

    data->tileTag = cursor->tileTag;
    data->palTag = cursor->palTag;
    data->subspriteTable.subspriteCount = ListMenuGetRedOutlineCursorSpriteCount(cursor->rowWidth, cursor->rowHeight);
    data->subspriteTable.subsprites = data->subspritesPtr = Alloc(data->subspriteTable.subspriteCount * 4);
    ListMenuSetUpRedOutlineCursorSpriteOamTable(cursor->rowWidth, cursor->rowHeight, data->subspritesPtr);

    spriteTemplate = gDummySpriteTemplate;
    spriteTemplate.tileTag = cursor->tileTag;
    spriteTemplate.paletteTag = cursor->palTag;

    data->spriteId = CreateSprite(&spriteTemplate, cursor->left + 120, cursor->top + 120, 0);
    SetSubspriteTables(&gSprites[data->spriteId], &data->subspriteTable);
    gSprites[data->spriteId].oam.priority = 0;
    gSprites[data->spriteId].subpriority = 0;
    gSprites[data->spriteId].subspriteTableNum = 0;

    if (cursor->palTag == TAG_NONE)
    {
        gSprites[data->spriteId].oam.paletteNum = cursor->palNum;
    }

    return taskId;
}


void ListMenuUpdateRedOutlineCursorObject(u8 taskId, u16 x, u16 y)
{
    struct RedOutlineCursor *data = (void *) gTasks[taskId].data;

    gSprites[data->spriteId].x = x + 120;
    gSprites[data->spriteId].y = y + 120;
}

void ListMenuRemoveRedOutlineCursorObject(u8 taskId)
{
    struct RedOutlineCursor *data = (void *) gTasks[taskId].data;

    Free(data->subspritesPtr);

    if (data->tileTag != TAG_NONE)
        FreeSpriteTilesByTag(data->tileTag);
    if (data->palTag != TAG_NONE)
        FreeSpritePaletteByTag(data->palTag);

    DestroySprite(&gSprites[data->spriteId]);
    DestroyTask(taskId);
}

void SpriteCallback_RedArrowCursor(struct Sprite *sprite)
{
    sprite->x2 = gSineTable[(u8)(sprite->data[0])] / 64;
    sprite->data[0] += 8;
}

void ListMenuDummyTask(void) {}
u8 ListMenuAddRedArrowCursorObject(struct CursorStruct *cursor)
{
    struct CompressedSpriteSheet spriteSheet;
    struct SpritePalette spritePal;
    struct RedArrowCursor *data;
    struct SpriteTemplate spriteTemplate;
    u8 taskId;

    spriteSheet.data = gUnknown_85DFC30;
    spriteSheet.size = 0x80;
    spriteSheet.tag = cursor->tileTag;
    LoadCompressedSpriteSheet(&spriteSheet);

    if (cursor->palTag == TAG_NONE)
    {
        LoadPalette(gUnknown_85DFB60, OBJ_PLTT_ID(cursor->palNum), PLTT_SIZE_4BPP);
    }
    else
    {
        spritePal.data = gUnknown_85DFB60;
        spritePal.tag = cursor->palTag;
        LoadSpritePalette(&spritePal);
    }

    taskId = CreateTask(ListMenuDummyTask, 0);
    data = (void *) gTasks[taskId].data;

    data->tileTag = cursor->tileTag;
    data->palTag = cursor->palTag;

    spriteTemplate = sSpriteTemplate_RedArrowCursor;
    spriteTemplate.tileTag = cursor->tileTag;
    spriteTemplate.paletteTag = cursor->palTag;

    data->spriteId = CreateSprite(&spriteTemplate, cursor->left, cursor->top, 0);
    gSprites[data->spriteId].x2 = 8;
    gSprites[data->spriteId].y2 = 8;

    if (cursor->palTag == TAG_NONE)
    {
        gSprites[data->spriteId].oam.paletteNum = cursor->palNum;
    }

    return taskId;
}


void ListMenuUpdateRedArrowCursorObject(u8 taskId, u16 x, u16 y)
{
    struct RedArrowCursor *data = (void *) gTasks[taskId].data;

    gSprites[data->spriteId].x = x;
    gSprites[data->spriteId].y = y;
}

void ListMenuRemoveRedArrowCursorObject(u8 taskId)
{
    struct RedArrowCursor *data = (void *) gTasks[taskId].data;

    if (data->tileTag != TAG_NONE)
        FreeSpriteTilesByTag(data->tileTag);
    if (data->palTag != TAG_NONE)
        FreeSpritePaletteByTag(data->palTag);

    DestroySprite(&gSprites[data->spriteId]);
    DestroyTask(taskId);
}
