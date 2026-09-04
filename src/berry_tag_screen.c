#include "global.h"
#include "berry_tag_screen.h"
#include "berry.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "main.h"
#include "malloc.h"
#include "menu_helpers.h"
#include "menu.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "decompress.h"
#include "bg.h"
#include "palette.h"
#include "graphics.h"
#include "save.h"
#include "string_util.h"

// JP ROM layout matches pokeemerald's struct plus a trailing 2-byte
// padding, giving sizeof(*sBerryTag) == 0x180C (matches AllocZeroed size).
struct BerryTagScreenStruct
{
    u16 tilemapBuffers[3][0x400];
    u16 berryId;
    u8 berrySpriteId;
    u8 flavorCircleIds[FLAVOR_COUNT];
    u16 gfxState;
    u16 unused;
};

// Address defined in ld_script_jp.txt (ABSOLUTE 0x0203B9C0).
extern struct BerryTagScreenStruct *sBerryTag;
#define BG_TILE 0x42
#define tBerryY data[0]
#define tBgOp data[1]
#define BERRY_TAG_SCREEN_DATA __attribute__((section(".rodata.berry_tag_screen_data")))

extern const u8 gUnknown_85C9786[];

// These JP tables occupy 0x085CD068-0x085CD0DC in the original ROM.
// Keep their source order and JP-specific window geometry byte-exact.
static BERRY_TAG_SCREEN_DATA const struct BgTemplate sBackgroundTemplates[] =
{
    { .bg = 0, .charBaseIndex = 0, .mapBaseIndex = 31, .screenSize = 0, .paletteMode = 0, .priority = 0, .baseTile = 0 },
    { .bg = 1, .charBaseIndex = 0, .mapBaseIndex = 30, .screenSize = 0, .paletteMode = 0, .priority = 1, .baseTile = 0 },
    { .bg = 2, .charBaseIndex = 0, .mapBaseIndex = 29, .screenSize = 0, .paletteMode = 0, .priority = 2, .baseTile = 0 },
    { .bg = 3, .charBaseIndex = 0, .mapBaseIndex = 28, .screenSize = 0, .paletteMode = 0, .priority = 3, .baseTile = 0 },
};

static BERRY_TAG_SCREEN_DATA const u16 sFontPalette[] =
{
    0x7FFF, 0x7FFF, 0x318C, 0x675A, 0x043C, 0x3AFF, 0x0664, 0x4BD2,
    0x6546, 0x7B14, 0x0000, 0x0000, 0x0000, 0x2217, 0x0088, 0x577D,
};

static BERRY_TAG_SCREEN_DATA const u8 sTextColors[2][3] =
{
    { 0, 2, 3 },
    { 15, 14, 13 },
};

static BERRY_TAG_SCREEN_DATA const struct WindowTemplate sWindowTemplates[] =
{
    { .bg = 1, .tilemapLeft = 11, .tilemapTop = 4, .width = 7, .height = 2, .paletteNum = 15, .baseBlock = 69 },
    { .bg = 1, .tilemapLeft = 11, .tilemapTop = 7, .width = 15, .height = 4, .paletteNum = 15, .baseBlock = 83 },
    { .bg = 1, .tilemapLeft = 4, .tilemapTop = 14, .width = 22, .height = 4, .paletteNum = 15, .baseBlock = 143 },
    { .bg = 0, .tilemapLeft = 3, .tilemapTop = 0, .width = 6, .height = 2, .paletteNum = 15, .baseBlock = 231 },
    DUMMY_WIN_TEMPLATE,
};

// The shared text block has not yet been split into individual text owners.
static BERRY_TAG_SCREEN_DATA const u8 *const sBerryFirmnessStrings[] =
{
    &gUnknown_85C9786[8],
    &gUnknown_85C9786[18],
    &gUnknown_85C9786[24],
    &gUnknown_85C9786[28],
    &gUnknown_85C9786[36],
};

void bag_menu_mail_related(void);
void PrintTextInBerryTagScreen(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed, u8 colorStructId);
void CB2_InitBerryTagScreen(void);
bool8 InitBerryTagScreen(void);
void AddBerryTagTextToBg0(void);
bool8 LoadBerryTagGfx(void);
void PrintMysteryMenuText(void);
void PrintBerrySize(void);
void PrintAllBerryData(void);
void CreateBerrySprite(void);
void CreateFlavorCircleSprites(void);
void SetFlavorCirclesVisiblity(void);
void Task_HandleInput(u8 taskId);
void Task_CloseBerryTagScreen(u8 taskId);
void Task_DisplayAnotherBerry(u8 taskId);
void HandleBagCursorPositionChange(s8 toMove);
void TryChangeDisplayedBerry(u8 taskId, s8 toMove);
void sub_0817804C(void);
void PrintBerryNumberAndName(void);
void PrintBerryFirmness(void);
void PrintBerryDescription1(void);
void PrintBerryDescription2(void);
extern const u8 gUnknown_85C97BD[];
extern const u8 gUnknown_85C97B5[];
extern const u8 gUnknown_85C977D[];
extern const u8 gUnknown_85C9782[];
extern const u8 gUnknown_85C93F5[];

void DoBerryTagScreen(void)
{
    sBerryTag = AllocZeroed(sizeof(*sBerryTag));
    sBerryTag->berryId = ItemIdToBerryType(gSpecialVar_ItemId);
    SetMainCallback2(CB2_InitBerryTagScreen);
}

void CB2_BerryTagScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

void VblankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitBerryTagScreen(void)
{
    while (1)
    {
        if (MenuHelpers_ShouldWaitForLinkRecv() == TRUE)
            break;
        if (InitBerryTagScreen() == TRUE)
            break;
        if (MenuHelpers_IsLinkActive() == TRUE)
            break;
    }
}

bool8 InitBerryTagScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = TRUE;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        if (!MenuHelpers_IsLinkActive())
            ResetTasks();
        gMain.state++;
        break;
    case 6:
        AddBerryTagTextToBg0();
        sBerryTag->gfxState = 0;
        gMain.state++;
        break;
    case 7:
        if (LoadBerryTagGfx())
            gMain.state++;
        break;
    case 8:
        PrintMysteryMenuText();
        gMain.state++;
        break;
    case 9:
        PrintBerrySize();
        gMain.state++;
        break;
    case 10:
        PrintAllBerryData();
        gMain.state++;
        break;
    case 11:
        CreateBerrySprite();
        gMain.state++;
        break;
    case 12:
        CreateFlavorCircleSprites();
        SetFlavorCirclesVisiblity();
        gMain.state++;
        break;
    case 13:
        CreateTask(Task_HandleInput, 0);
        gMain.state++;
        break;
    case 14:
        BlendPalettes(PALETTES_ALL, 0x10, RGB_BLACK);
        gMain.state++;
        break;
    case 15:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VblankCB);
        SetMainCallback2(CB2_BerryTagScreen);
        return TRUE;
    }

    return FALSE;
}

void AddBerryTagTextToBg0(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBackgroundTemplates, ARRAY_COUNT(sBackgroundTemplates));
    SetBgTilemapBuffer(2, sBerryTag->tilemapBuffers[0]);
    SetBgTilemapBuffer(3, sBerryTag->tilemapBuffers[1]);
    ResetAllBgsCoordinates();
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

bool8 LoadBerryTagGfx(void)
{
    u16 i;

    switch (sBerryTag->gfxState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, gBerryCheck_Gfx, 0, 0, 0);
        sBerryTag->gfxState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressVram(gBerryTag_Gfx, sBerryTag->tilemapBuffers[0]);
            sBerryTag->gfxState++;
        }
        break;
    case 2:
        LZDecompressVram(gBerryTag_Tilemap, sBerryTag->tilemapBuffers[2]);
        sBerryTag->gfxState++;
        break;
    case 3:
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            for (i = 0; i < ARRAY_COUNT(sBerryTag->tilemapBuffers[1]); i++)
                sBerryTag->tilemapBuffers[1][i] = (4 << 12) | BG_TILE;
        }
        else
        {
            for (i = 0; i < ARRAY_COUNT(sBerryTag->tilemapBuffers[1]); i++)
                sBerryTag->tilemapBuffers[1][i] = (5 << 12) | BG_TILE;
        }
        sBerryTag->gfxState++;
        break;
    case 4:
        LoadCompressedPalette(gBerryCheck_Pal, BG_PLTT_ID(0), 6 * PLTT_SIZE_4BPP);
        sBerryTag->gfxState++;
        break;
    case 5:
        LoadCompressedSpriteSheet(&gBerryCheckCircleSpriteSheet);
        sBerryTag->gfxState++;
        break;
    default:
        LoadCompressedSpritePalette(&gBerryCheckCirclePaletteTable);
        return TRUE;
    }

    return FALSE;
}

void PrintMysteryMenuText(void)
{
    u16 i;

    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(sFontPalette, 0xF0, sizeof(sFontPalette));
    for (i = 0; i < 4; i++)
        PutWindowTilemap(i);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
}

void PrintTextInBerryTagScreen(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed, u8 colorStructId)
{
    AddTextPrinterParameterized4(windowId, 1, x, y, 0, 0, sTextColors[colorStructId], speed, text);
}

void PrintBerrySize(void)
{
    memcpy(GetBgTilemapBuffer(0), sBerryTag->tilemapBuffers[2], 0x800);
    FillWindowPixelBuffer(3, 0xFF);
    PrintTextInBerryTagScreen(3, gUnknown_85C97BD, 0, 2, 0, 1);
    PutWindowTilemap(3);
    ScheduleBgCopyTilemapToVram(0);
}


void PrintAllBerryData(void)
{
    PrintBerryNumberAndName();
    sub_0817804C();
    PrintBerryFirmness();
    PrintBerryDescription1();
    PrintBerryDescription2();
}

void PrintBerryNumberAndName(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);

    ConvertIntToDecimalStringN(gStringVar1, sBerryTag->berryId, 2, 2);
    StringCopy(gStringVar2, berry->name);
    StringExpandPlaceholders(gStringVar4, gUnknown_85C97B5);
    PrintTextInBerryTagScreen(0, gStringVar4, 0, 2, 0, 0);
}

void sub_0817804C(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);

    AddTextPrinterParameterized(1, 1, gUnknown_85C977D, 0, 2, 0xFF, NULL);
    if (berry->size != 0)
    {
        ConvertIntToDecimalStringN(gStringVar1, berry->size / 10, 0, 2);
        ConvertIntToDecimalStringN(gStringVar2, berry->size % 10, 0, 2);
        StringExpandPlaceholders(gStringVar4, gUnknown_85C9786);
        AddTextPrinterParameterized(1, 1, gStringVar4, 0x28, 2, 0, NULL);
    }
    else
    {
        AddTextPrinterParameterized(1, 1, gUnknown_85C93F5, 0x28, 2, 0, NULL);
    }
}

void PrintBerryFirmness(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);

    AddTextPrinterParameterized(1, 1, gUnknown_85C9782, 0, 0x12, 0xFF, NULL);
    if (berry->firmness != 0)
        AddTextPrinterParameterized(1, 1, sBerryFirmnessStrings[berry->firmness - 1], 0x28, 0x12, 0, NULL);
    else
        AddTextPrinterParameterized(1, 1, gUnknown_85C93F5, 0x28, 0x12, 0, NULL);
}

void PrintBerryDescription1(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);

    AddTextPrinterParameterized(2, 1, berry->description1, 0, 2, 0, NULL);
}

void PrintBerryDescription2(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);

    AddTextPrinterParameterized(2, 1, berry->description2, 0, 0x12, 0, NULL);
}

void CreateBerrySprite(void)
{
    sBerryTag->berrySpriteId = CreateBerryTagSprite(sBerryTag->berryId - 1, 56, 64);
}

void DestroyBerrySprite(void)
{
    DestroySprite(&gSprites[sBerryTag->berrySpriteId]);
    FreeBerryTagSpritePalette();
}

void CreateFlavorCircleSprites(void)
{
    sBerryTag->flavorCircleIds[FLAVOR_SPICY] = CreateBerryFlavorCircleSprite(60);
    sBerryTag->flavorCircleIds[FLAVOR_DRY] = CreateBerryFlavorCircleSprite(92);
    sBerryTag->flavorCircleIds[FLAVOR_SWEET] = CreateBerryFlavorCircleSprite(124);
    sBerryTag->flavorCircleIds[FLAVOR_BITTER] = CreateBerryFlavorCircleSprite(156);
    sBerryTag->flavorCircleIds[FLAVOR_SOUR] = CreateBerryFlavorCircleSprite(188);
}

void SetFlavorCirclesVisiblity(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);

    if (berry->spicy)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SPICY]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SPICY]].invisible = TRUE;

    if (berry->dry)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_DRY]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_DRY]].invisible = TRUE;

    if (berry->sweet)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SWEET]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SWEET]].invisible = TRUE;

    if (berry->bitter)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_BITTER]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_BITTER]].invisible = TRUE;

    if (berry->sour)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SOUR]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SOUR]].invisible = TRUE;
}

void DestroyFlavorCircleSprites(void)
{
    u16 i;

    for (i = 0; i < FLAVOR_COUNT; i++)
        DestroySprite(&gSprites[sBerryTag->flavorCircleIds[i]]);
}

void PrepareToCloseBerryTagScreen(u8 taskId)
{
    PlaySE(SE_SELECT);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_CloseBerryTagScreen;
}

void Task_CloseBerryTagScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyBerrySprite();
        DestroyFlavorCircleSprites();
        Free(sBerryTag);
        FreeAllWindowBuffers();
        SetMainCallback2(bag_menu_mail_related);
        DestroyTask(taskId);
    }
}

void Task_HandleInput(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u16 arrowKeys = JOY_REPEAT(DPAD_ANY);
        if (arrowKeys == DPAD_UP)
            TryChangeDisplayedBerry(taskId, -1);
        else if (arrowKeys == DPAD_DOWN)
            TryChangeDisplayedBerry(taskId, 1);
        else if (JOY_NEW(A_BUTTON | B_BUTTON))
            PrepareToCloseBerryTagScreen(taskId);
    }
}

void TryChangeDisplayedBerry(u8 taskId, s8 toMove)
{
    s16 *data = gTasks[taskId].data;
    s16 currPocketPosition = gBagPosition.scrollPosition[BERRIES_POCKET] + gBagPosition.cursorPosition[BERRIES_POCKET];
    u32 newPocketPosition = currPocketPosition + toMove;
    if (newPocketPosition < ITEM_TO_BERRY(MAX_BERRY_INDEX) && BagGetItemIdByPocketPosition(POCKET_BERRIES, newPocketPosition) != ITEM_NONE)
    {
        if (toMove < 0)
            tBgOp = BG_COORD_SUB;
        else
            tBgOp = BG_COORD_ADD;

        tBerryY = 0;
        PlaySE(SE_SELECT);
        HandleBagCursorPositionChange(toMove);
        gTasks[taskId].func = Task_DisplayAnotherBerry;
    }
}

void HandleBagCursorPositionChange(s8 toMove)
{
    u16 *scrollPos = &gBagPosition.scrollPosition[BERRIES_POCKET];
    u16 *cursorPos = &gBagPosition.cursorPosition[BERRIES_POCKET];
    if (toMove > 0)
    {
        if (*cursorPos < 4 || BagGetItemIdByPocketPosition(POCKET_BERRIES, *scrollPos + 8) == 0)
            *cursorPos += toMove;
        else
            *scrollPos += toMove;
    }
    else
    {
        if (*cursorPos > 3 || *scrollPos == 0)
            *cursorPos += toMove;
        else
            *scrollPos += toMove;
    }

    sBerryTag->berryId = ItemIdToBerryType(BagGetItemIdByPocketPosition(POCKET_BERRIES, *scrollPos + *cursorPos));
}

void Task_DisplayAnotherBerry(u8 taskId)
{
    u16 i;
    s16 y;
    s16 *data = gTasks[taskId].data;

    tBerryY += 0x10;
    tBerryY &= 0xFF;
    if (tBgOp == BG_COORD_ADD)
    {
        switch (tBerryY)
        {
        case 0x30:
            FillWindowPixelBuffer(0, 0);
            break;
        case 0x40:
            PrintBerryNumberAndName();
            break;
        case 0x50:
            DestroyBerrySprite();
            CreateBerrySprite();
            break;
        case 0x60:
            FillWindowPixelBuffer(1, 0);
            break;
        case 0x70:
            sub_0817804C();
            break;
        case 0x80:
            PrintBerryFirmness();
            break;
        case 0x90:
            SetFlavorCirclesVisiblity();
            break;
        case 0xA0:
            FillWindowPixelBuffer(2, 0);
            break;
        case 0xB0:
            PrintBerryDescription1();
            break;
        case 0xC0:
            PrintBerryDescription2();
            break;
        }
    }
    else
    {
        switch (tBerryY)
        {
        case 0x30:
            FillWindowPixelBuffer(2, 0);
            break;
        case 0x40:
            PrintBerryDescription2();
            break;
        case 0x50:
            PrintBerryDescription1();
            break;
        case 0x60:
            SetFlavorCirclesVisiblity();
            break;
        case 0x70:
            FillWindowPixelBuffer(1, 0);
            break;
        case 0x80:
            PrintBerryFirmness();
            break;
        case 0x90:
            sub_0817804C();
            break;
        case 0xA0:
            DestroyBerrySprite();
            CreateBerrySprite();
            break;
        case 0xB0:
            FillWindowPixelBuffer(0, 0);
            break;
        case 0xC0:
            PrintBerryNumberAndName();
            break;
        }
    }

    if (tBgOp == BG_COORD_ADD)
        y = -tBerryY;
    else
        y = tBerryY;

    gSprites[sBerryTag->berrySpriteId].y2 = y;
    for (i = 0; i < FLAVOR_COUNT; i++)
        gSprites[sBerryTag->flavorCircleIds[i]].y2 = y;

    ChangeBgY(1, 0x1000, tBgOp);
    ChangeBgY(2, 0x1000, tBgOp);

    if (tBerryY == 0)
        gTasks[taskId].func = Task_HandleInput;
}
