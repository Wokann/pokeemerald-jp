#include "global.h"
#include "berry_powder.h"
#include "bg.h"
#include "event_data.h"
#include "load_save.h"
#include "menu.h"
#include "palette.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"

#define MAX_BERRY_POWDER 99999

// JP ROM data (the vendor window id stays in EWRAM; the UNUSED bg/window
// templates are unreferenced and stay in the ROM data region)
extern u8 sBerryPowderVendorWindowId;
extern const u8 gText_Powder[];

static u32 DecryptBerryPowder(u32 *powder)
{
    return *powder ^ gSaveBlock2Ptr->encryptionKey;
}

void SetBerryPowder(u32 *powder, u32 amount)
{
    *powder = amount ^ gSaveBlock2Ptr->encryptionKey;
}

void ApplyNewEncryptionKeyToBerryPowder(u32 encryptionKey)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    ApplyNewEncryptionKeyToWord(powder, encryptionKey);
}

static bool8 HasEnoughBerryPowder_(u32 cost)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    if (DecryptBerryPowder(powder) < cost)
        return FALSE;
    else
        return TRUE;
}

bool8 HasEnoughBerryPowder(void)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    if (DecryptBerryPowder(powder) < gSpecialVar_0x8004)
        return FALSE;
    else
        return TRUE;
}

bool8 GiveBerryPowder(u32 amountToAdd)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    u32 amount = DecryptBerryPowder(powder) + amountToAdd;
    if (amount > MAX_BERRY_POWDER)
    {
        SetBerryPowder(powder, MAX_BERRY_POWDER);
        return FALSE;
    }
    else
    {
        SetBerryPowder(powder, amount);
        return TRUE;
    }
}

static bool8 UNUSED TakeBerryPowder_(u32 cost)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    if (!HasEnoughBerryPowder_(cost))
        return FALSE;

    SetBerryPowder(powder, DecryptBerryPowder(powder) - cost);
    return TRUE;
}

bool8 TakeBerryPowder(void)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    if (!HasEnoughBerryPowder_(gSpecialVar_0x8004))
        return FALSE;

    SetBerryPowder(powder, DecryptBerryPowder(powder) - gSpecialVar_0x8004);
    return TRUE;
}

u32 GetBerryPowder(void)
{
    u32 *powder = &gSaveBlock2Ptr->berryCrush.berryPowderAmount;
    return DecryptBerryPowder(powder);
}

static void PrintBerryPowderAmount(u8 windowId, int amount, u8 x, u8 y, u8 speed)
{
    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_RIGHT_ALIGN, 5);
    AddTextPrinterParameterized(windowId, FONT_SMALL, gStringVar1, x, y, speed, NULL); // JP variant: small font
}

static void DrawPlayerPowderAmount(u8 windowId, u16 baseTileOffset, u8 paletteNum, u32 amount)
{
    DrawStdFrameWithCustomTileAndPalette(windowId, FALSE, baseTileOffset, paletteNum);
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gText_Powder, 0, 0, TEXT_SKIP_DRAW, NULL); // JP variant: y=0
    PrintBerryPowderAmount(windowId, amount, 16, 12, 0); // JP variant: (16,12) position
}

void PrintPlayerBerryPowderAmount(void)
{
    u32 amount = GetBerryPowder();
    PrintBerryPowderAmount(sBerryPowderVendorWindowId, amount, 16, 12, 0); // JP variant: (16,12) position
}

void DisplayBerryPowderVendorMenu(void)
{
    struct WindowTemplate template;
    SetWindowTemplateFields(&template, 0, 1, 1, 7, 3, 15, 0x20); // JP variant: height 3, baseBlock 0x20
    sBerryPowderVendorWindowId = AddWindow(&template);
    FillWindowPixelBuffer(sBerryPowderVendorWindowId, PIXEL_FILL(0));
    PutWindowTilemap(sBerryPowderVendorWindowId);
    LoadUserWindowBorderGfx_(sBerryPowderVendorWindowId, 0x21D, BG_PLTT_ID(13));
    DrawPlayerPowderAmount(sBerryPowderVendorWindowId, 0x21D, 13, GetBerryPowder());
}

void RemoveBerryPowderVendorMenu(void)
{
    ClearWindowTilemap(sBerryPowderVendorWindowId);
    ClearStdWindowAndFrameToTransparent(sBerryPowderVendorWindowId, TRUE);
    RemoveWindow(sBerryPowderVendorWindowId);
}
