#include "global.h"
#include "constants/decorations.h"
#include "constants/mauville_old_man.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "script.h"
#include "constants/songs.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "script_menu.h"

extern const u8 *const sDefaultTraderNames[NUM_TRADER_ITEMS];
extern const u8 sDefaultTraderDecorations[NUM_TRADER_ITEMS];
extern const struct WindowTemplate sTraderWindowTemplate;

// JP asm name of the 7-arg menu initializer in asm/menu.s (US:
// InitMenuInUpperLeftCornerNormal takes 3 args and delegates; JP passes
// windowId, fontId, x, y, extra, itemCount, initialCursorPos).
u8 sub_081984B0(u8 windowId, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7);

// JP-only script special with no pokeemerald counterpart: it pops one
// entry off a save-scoped decoration offer list (0x0202414C -> +0x1C
// array, index at +0x20) and stores it at 0x0203A804.  Kept in
// asm/trader_jp_only.s because agbcc cannot reproduce its literal-pool
// layout from C.
bool8 ScrSpecial_TraderMenuGiveDecoration(void);

void TraderSetup(void)
{
    u8 i;
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;

    trader->id = MAUVILLE_MAN_TRADER;
    trader->alreadyTraded = FALSE;

    for (i = 0; i < NUM_TRADER_ITEMS; i++)
    {
        StringCopy(trader->playerNames[i], sDefaultTraderNames[i]);
        trader->decorations[i] = sDefaultTraderDecorations[i];
        trader->language[i] = LANGUAGE_JAPANESE;
    }
}

void Trader_ResetFlag(void)
{
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;
    trader->alreadyTraded = FALSE;
}

#define tWindowId data[3]

void CreateAvailableDecorationsMenu(u8 taskId)
{
    u8 i;
    s16 *data = gTasks[taskId].data;
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;

    tWindowId = AddWindow(&sTraderWindowTemplate);
    DrawStdFrameWithCustomTileAndPalette(tWindowId, FALSE, 0x214, 14);
    for (i = 0; i < NUM_TRADER_ITEMS; i++)
    {
        if (trader->decorations[i] > NUM_DECORATIONS)
            AddTextPrinterParameterized(tWindowId, FONT_NORMAL, gText_FiveMarks, 8, 16 * i + 2, TEXT_SKIP_DRAW, NULL);
        else
            AddTextPrinterParameterized(tWindowId, FONT_NORMAL, gDecorations[trader->decorations[i]].name, 8, 16 * i + 2, TEXT_SKIP_DRAW, NULL);
    }
    AddTextPrinterParameterized(tWindowId, FONT_NORMAL, gText_Exit, 8, 16 * i + 2, TEXT_SKIP_DRAW, NULL);
    sub_081984B0(tWindowId, 1, 0, 2, 16, NUM_TRADER_ITEMS + 1, 0);
    ScheduleBgCopyTilemapToVram(0);
}

void Task_BufferDecorSelectionAndCloseWindow(u8 taskId, u8 decorationId)
{
    s16 *data = gTasks[taskId].data;
    if (decorationId > NUM_DECORATIONS)
        gSpecialVar_0x8004 = 0xFFFF;
    else
        gSpecialVar_0x8004 = decorationId;

    ClearStdWindowAndFrameToTransparent(tWindowId, FALSE);
    ClearWindowTilemap(tWindowId);
    RemoveWindow(tWindowId);
    ScheduleBgCopyTilemapToVram(0);
    DestroyTask(taskId);
    ScriptContext_Enable();
}

void Task_HandleGetDecorationMenuInput(u8 taskId)
{
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;
    s8 input = Menu_ProcessInput();

    switch (input)
    {
        case MENU_NOTHING_CHOSEN:
            break;
        case MENU_B_PRESSED:
        case NUM_TRADER_ITEMS: // EXIT
            PlaySE(SE_SELECT);
            Task_BufferDecorSelectionAndCloseWindow(taskId, 0);
            break;
        default:
            PlaySE(SE_SELECT);
            gSpecialVar_0x8005 = input;
            StringCopy(gStringVar1, trader->playerNames[input]);
            Task_BufferDecorSelectionAndCloseWindow(taskId, trader->decorations[input]);
            break;
    }
}

void GetTraderTradedFlag(void)
{
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;
    gSpecialVar_Result = trader->alreadyTraded;
}

void DoesPlayerHaveNoDecorations(void)
{
    u8 i;

    for (i = 0; i < DECORCAT_COUNT; i++)
    {
        if (GetNumOwnedDecorationsInCategory(i))
        {
            gSpecialVar_Result = FALSE;
            return;
        }
    }
    gSpecialVar_Result = TRUE;
}

void IsDecorationCategoryFull(void)
{
    gSpecialVar_Result = FALSE;
    if (gDecorations[gSpecialVar_0x8004].category != gDecorations[gSpecialVar_0x8006].category
        && GetFirstEmptyDecorSlot(gDecorations[gSpecialVar_0x8004].category) == -1)
    {
        CopyDecorationCategoryName(gStringVar2, gDecorations[gSpecialVar_0x8004].category);
        gSpecialVar_Result = TRUE;
    }
}

void TraderShowDecorationMenu(void)
{
    CreateTask(ShowDecorationCategoriesWindow, 0);
}

void DecorationItemsMenuAction_Trade(u8 taskId)
{
    if (IsSelectedDecorInThePC() == TRUE)
    {
        gSpecialVar_0x8006 = gCurDecorationItems[gCurDecorationIndex];
        StringCopy(gStringVar3, gDecorations[gSpecialVar_0x8004].name);
        StringCopy(gStringVar2, gDecorations[gSpecialVar_0x8006].name);
    }
    else
    {
        gSpecialVar_0x8006 = 0xFFFF;
    }
    DestroyTask(taskId);
    ScriptContext_Enable();
}

void ExitTraderMenu(u8 taskId)
{
    gSpecialVar_0x8006 = 0;
    DestroyTask(taskId);
    ScriptContext_Enable();
}

void TraderDoDecorationTrade(void)
{
    struct MauvilleOldManTrader *trader = &gSaveBlock1Ptr->oldMan.trader;

    DecorationRemove(gSpecialVar_0x8006);
    DecorationAdd(gSpecialVar_0x8004);
    StringCopy(trader->playerNames[gSpecialVar_0x8005], gSaveBlock2Ptr->playerName);
    trader->decorations[gSpecialVar_0x8005] = gSpecialVar_0x8006;
    trader->language[gSpecialVar_0x8005] = LANGUAGE_JAPANESE;
    trader->alreadyTraded = TRUE;
}

void TraderMenuGetDecoration(void)
{
    u8 taskId = CreateTask(Task_HandleGetDecorationMenuInput, 0);
    CreateAvailableDecorationsMenu(taskId);
}
