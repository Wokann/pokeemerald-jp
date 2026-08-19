#include "global.h"
#include "diploma.h"
#include "palette.h"
#include "main.h"
#include "gpu_regs.h"
#include "scanline_effect.h"
#include "task.h"
#include "malloc.h"
#include "decompress.h"
#include "bg.h"
#include "window.h"
#include "string_util.h"
#include "text.h"
#include "overworld.h"
#include "menu.h"
#include "pokedex.h"
#include "constants/rgb.h"
#include "gba/macro.h"

extern const u16 sDiplomaPalettes[][16];
extern const u32 sDiplomaTilemap[];
extern const u32 sDiplomaTiles[];
extern const u16 gStandardMenuPalette[];
extern u8 *sDiplomaTilemapPtr;
extern const u8 gText_Diploma_1[];
extern const u8 gText_Diploma_2[];
extern const u8 gText_Diploma_3[];
extern const u8 gText_Diploma_National[];
extern const u8 gText_Diploma_Hoenn[];
extern const u8 gText_Diploma_4[];

__attribute__((section(".rodata.diploma")))
const u8 gText_Diploma_NameTemplate[] = {0xFC, 0x01, 0x04, 0xFC, 0x03, 0x05, EOS, 0};

__attribute__((section(".rodata.diploma")))
static const struct BgTemplate sDiplomaBgTemplates[2] =
{
    {0, 1, 31, 0, 0, 0, 0},
    {1, 0, 6, 1, 0, 1, 0},
};

__attribute__((section(".rodata.diploma")))
static const struct WindowTemplate sDiplomaWinTemplates[2] =
{
    {0, 8, 2, 13, 16, 15, 1},
    DUMMY_WIN_TEMPLATE,
};

__attribute__((section(".rodata.diploma")))
static const u8 sDiplomaTextColors[4] = {0, 2, 3, 0};

__attribute__((section(".rodata.diploma")))
const u8 gUnknown_85C8C24[] = {EOS};

__attribute__((section(".rodata.diploma")))
const u8 gUnknown_85C8C25[] = {0x08, 0x2E, EOS};

__attribute__((section(".rodata.diploma")))
const u8 gUnknown_85C8C28[] = {0x11, 0x34, 0x2E, EOS, 0x5B, 0x6C, 0x7F, 0x52, 0x51, EOS, 0x79, 0x97, 0xAE, EOS};
void VBlankCB_SelectScreen(void);
bool16 HasAllMons(void);

static void MainCB2(void);
static void Task_DiplomaFadeIn(u8);
static void Task_DiplomaWaitForKeyPress(u8);
static void Task_DiplomaFadeOut(u8);
static void DisplayDiplomaText(void);
static void InitDiplomaBg(void);
static void InitDiplomaWindow(void);
static void PrintDiplomaText(u8 *, u8, u8);

void CB2_ShowDiploma(void)
{
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
    LoadPalette(sDiplomaPalettes, BG_PLTT_ID(0), 0x40);
    sDiplomaTilemapPtr = Alloc(0x1000);
    InitDiplomaBg();
    InitDiplomaWindow();
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(1, &sDiplomaTiles, 0, 0, 0);
    while (FreeTempTileDataBuffersIfPossible())
        ;
    LZDecompressVram(sDiplomaTilemap, sDiplomaTilemapPtr);
    CopyBgTilemapBufferToVram(1);
    DisplayDiplomaText();
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB_SelectScreen);
    SetMainCallback2(MainCB2);
    CreateTask(Task_DiplomaFadeIn, 0);
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_DiplomaFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_DiplomaWaitForKeyPress;
}

static void Task_DiplomaWaitForKeyPress(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_DiplomaFadeOut;
    }
}

static void Task_DiplomaFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Free(sDiplomaTilemapPtr);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        SetMainCallback2(CB2_ReturnToFieldFadeFromBlack);
    }
}

static void DisplayDiplomaText(void)
{
    u8 buffer[12];
    u8 i;

    PrintDiplomaText(gText_Diploma_1, 0, 2);
    StringCopy(buffer, gText_Diploma_NameTemplate);
    for (i = 0; i < 5; i++)
        buffer[i + 6] = gSaveBlock2Ptr->playerName[i];
    buffer[i + 6] = EOS;
    PrintDiplomaText(buffer, 0x30, 2);
    PrintDiplomaText(gText_Diploma_2, 0x58, 2);
    PrintDiplomaText(gText_Diploma_3, 0, 0x22);
    if (HasAllMons())
    {
        SetGpuReg(REG_OFFSET_BG1HOFS, 0x100);
        PrintDiplomaText(gText_Diploma_National, 0, 0x22);
    }
    else
    {
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        PrintDiplomaText(gText_Diploma_Hoenn, 0, 0x22);
    }
    PrintDiplomaText(gText_Diploma_4, 0x30, 0x72);
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void InitDiplomaBg(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sDiplomaBgTemplates, ARRAY_COUNT(sDiplomaBgTemplates));
    SetBgTilemapBuffer(1, sDiplomaTilemapPtr);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void InitDiplomaWindow(void)
{
    InitWindows(sDiplomaWinTemplates);
    DeactivateAllTextPrinters();
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
}

static void PrintDiplomaText(u8 *text, u8 x, u8 y)
{
    u8 color[3];

    memcpy(color, sDiplomaTextColors, 3);
    AddTextPrinterParameterized4(0, FONT_NORMAL, x, y, 0, 0, color, TEXT_SKIP_DRAW, text);
}
