#include "global.h"
#include "battle.h"
#include "title_screen.h"
#include "sprite.h"
#include "gba/m4a_internal.h"
#include "clear_save_data_menu.h"
#include "decompress.h"
#include "event_data.h"
#include "intro.h"
#include "m4a.h"
#include "main.h"
#include "main_menu.h"
#include "palette.h"
#include "reset_rtc_screen.h"
#include "berry_fix_program.h"
#include "sound.h"
#include "task.h"
#include "scanline_effect.h"
#include "gpu_regs.h"
#include "trig.h"
#include "graphics.h"
#include "constants/rgb.h"
#include "constants/songs.h"

enum {
    TAG_VERSION = 1000,
    TAG_PRESS_START_COPYRIGHT,
    TAG_LOGO_SHINE,
};

#define VERSION_BANNER_RIGHT_TILEOFFSET 64
#define VERSION_BANNER_LEFT_X 162
#define VERSION_BANNER_RIGHT_X 210
#define VERSION_BANNER_Y -16
#define VERSION_BANNER_Y_GOAL 48
#define START_BANNER_X 128

#define CLEAR_SAVE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_UP)
#define RESET_RTC_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON | DPAD_LEFT)
#define BERRY_UPDATE_BUTTON_COMBO (B_BUTTON | SELECT_BUTTON)
#define A_B_START_SELECT (A_BUTTON | B_BUTTON | START_BUTTON | SELECT_BUTTON)

static void MainCB2(void);
static void Task_TitleScreenPhase1(u8);
static void Task_TitleScreenPhase3(u8);
static void CB2_GoToMainMenu(void);
static void CB2_GoToClearSaveDataScreen(void);
static void CB2_GoToResetRtcScreen(void);
static void CB2_GoToBerryFixScreen(void);
static void CB2_GoToCopyrightScreen(void);
static void UpdateLegendaryMarkingColor(u8);

static void SpriteCB_VersionBannerLeft(struct Sprite *sprite);
static void SpriteCB_VersionBannerRight(struct Sprite *sprite);
static void SpriteCB_PressStartCopyrightBanner(struct Sprite *sprite);
static void SpriteCB_PokemonLogoShine(struct Sprite *sprite);

// JP note: Task_TitleScreenPhase2's register allocation (taskId in r4,
// subpixel position in r5) cannot be reproduced by agbcc; it stays in
// asm/title_screen_phase2.s.
extern void Task_TitleScreenPhase2(u8 taskId);

// JP note: the title-screen tables and graphics live in the JP ROM data
// region (0x0851xxxx) and are bound via ld aliases.
extern const u16 gTitleScreenAlphaBlend[64];
extern const u32 gTitleScreenPokemonLogoGfx[];
extern const u32 gTitleScreenPokemonLogoTilemap[];
extern const u16 gTitleScreenBgPalettes[];
extern const u32 gTitleScreenCloudsTilemap[];
extern const struct SpriteTemplate sVersionBannerLeftSpriteTemplate;
extern const struct SpriteTemplate sVersionBannerRightSpriteTemplate;
extern const struct SpriteTemplate sStartCopyrightBannerSpriteTemplate;
extern const struct SpriteTemplate sPokemonLogoShineSpriteTemplate;
extern const struct CompressedSpriteSheet sSpriteSheet_EmeraldVersion[];
extern const struct CompressedSpriteSheet sSpriteSheet_PressStart[];
extern const struct CompressedSpriteSheet sPokemonLogoShineSpriteSheet[];
extern const struct SpritePalette sSpritePalette_PressStart[];
extern const u32 sTitleScreenRayquazaGfx[];
extern const u32 sTitleScreenRayquazaTilemap[];
extern const u32 sTitleScreenCloudsGfx[];

// The "Press Start" and copyright graphics are each 5 32x8 segments long
#define NUM_PRESS_START_FRAMES 5
#define NUM_COPYRIGHT_FRAMES 5

// Task data for the main title screen tasks (Task_TitleScreenPhase#)
#define tCounter    data[0]
#define tSkipToNext data[1]
#define tPointless  data[2] // Incremented but never used to do anything.
#define tBg2Y       data[3]
#define tBg1Y       data[4]

// Sprite data for sVersionBannerLeftSpriteTemplate / sVersionBannerRightSpriteTemplate
#define sAlphaBlendIdx data[0]
#define sParentTaskId  data[1]

static void SpriteCB_VersionBannerLeft(struct Sprite *sprite)
{
    if (gTasks[sprite->sParentTaskId].tSkipToNext)
    {
        sprite->oam.objMode = ST_OAM_OBJ_NORMAL;
        sprite->y = VERSION_BANNER_Y_GOAL;
    }
    else
    {
        if (sprite->y != VERSION_BANNER_Y_GOAL)
            sprite->y++;
        if (sprite->sAlphaBlendIdx != 0)
            sprite->sAlphaBlendIdx--;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTitleScreenAlphaBlend[sprite->sAlphaBlendIdx]);
    }
}

static void SpriteCB_VersionBannerRight(struct Sprite *sprite)
{
    if (gTasks[sprite->sParentTaskId].tSkipToNext)
    {
        sprite->oam.objMode = ST_OAM_OBJ_NORMAL;
        sprite->y = VERSION_BANNER_Y_GOAL;
    }
    else
    {
        if (sprite->y != VERSION_BANNER_Y_GOAL)
            sprite->y++;
    }
}

// Sprite data for SpriteCB_PressStartCopyrightBanner
#define sAnimate data[0]
#define sTimer   data[1]

static void SpriteCB_PressStartCopyrightBanner(struct Sprite *sprite)
{
    if (sprite->sAnimate == TRUE)
    {
        // Alternate between hidden and shown every 16th frame
        if (++sprite->sTimer & 16)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
    }
}

void CreatePressStartBanner(s16 x, s16 y)
{
    u8 i;
    u8 spriteId;

    x -= 64;
    for (i = 0; i < NUM_PRESS_START_FRAMES; i++, x += 32)
    {
        spriteId = CreateSprite(&sStartCopyrightBannerSpriteTemplate, x, y, 0);
        StartSpriteAnim(&gSprites[spriteId], i);
        gSprites[spriteId].sAnimate = TRUE;
    }
}

void CreateCopyrightBanner(s16 x, s16 y)
{
    u8 i;
    u8 spriteId;

    x -= 64;
    for (i = 0; i < NUM_COPYRIGHT_FRAMES; i++, x += 32)
    {
        spriteId = CreateSprite(&sStartCopyrightBannerSpriteTemplate, x, y, 0);
        StartSpriteAnim(&gSprites[spriteId], i + NUM_PRESS_START_FRAMES);
    }
}

#undef sAnimate
#undef sTimer

// Defines for SpriteCB_PokemonLogoShine
enum {
    SHINE_MODE_SINGLE_NO_BG_COLOR,
    SHINE_MODE_DOUBLE,
    SHINE_MODE_SINGLE,
};

#define SHINE_SPEED  4

#define sMode     data[0]
#define sBgColor  data[1]

static void SpriteCB_PokemonLogoShine(struct Sprite *sprite)
{
    if (sprite->x < DISPLAY_WIDTH + 32)
    {
        // In any mode except SHINE_MODE_SINGLE_NO_BG_COLOR the background
        // color will change, in addition to the shine sprite moving.
        if (sprite->sMode != SHINE_MODE_SINGLE_NO_BG_COLOR)
        {
            u16 backgroundColor;

            if (sprite->x < DISPLAY_WIDTH / 2)
            {
                // Brighten background color
                if (sprite->sBgColor < 31)
                    sprite->sBgColor++;
                if (sprite->sBgColor < 31)
                    sprite->sBgColor++;
            }
            else
            {
                // Darken background color
                if (sprite->sBgColor != 0)
                    sprite->sBgColor--;
                if (sprite->sBgColor != 0)
                    sprite->sBgColor--;
            }

            backgroundColor = _RGB(sprite->sBgColor, sprite->sBgColor, sprite->sBgColor);

            // Flash the background green for 4 frames of movement.
            // Otherwise use the updating color.
            if (sprite->x == DISPLAY_WIDTH / 2 + (3 * SHINE_SPEED)
             || sprite->x == DISPLAY_WIDTH / 2 + (4 * SHINE_SPEED)
             || sprite->x == DISPLAY_WIDTH / 2 + (5 * SHINE_SPEED)
             || sprite->x == DISPLAY_WIDTH / 2 + (6 * SHINE_SPEED))
                gPlttBufferFaded[0] = RGB(24, 31, 12);
            else
                gPlttBufferFaded[0] = backgroundColor;
        }

        sprite->x += SHINE_SPEED;
    }
    else
    {
        // Sprite has moved fully offscreen
        gPlttBufferFaded[0] = RGB_BLACK;
        DestroySprite(sprite);
    }
}

static void SpriteCB_PokemonLogoShine_Fast(struct Sprite *sprite)
{
    if (sprite->x < DISPLAY_WIDTH + 32)
        sprite->x += SHINE_SPEED * 2;
    else
        DestroySprite(sprite);
}

static void StartPokemonLogoShine(u8 mode)
{
    u8 spriteId;

    switch (mode)
    {
    case SHINE_MODE_SINGLE_NO_BG_COLOR:
    case SHINE_MODE_SINGLE:
        // Create one regular shine sprite.
        // If mode is SHINE_MODE_SINGLE it will also change the background color.
        spriteId = CreateSprite(&sPokemonLogoShineSpriteTemplate, 0, 68, 0);
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_WINDOW;
        gSprites[spriteId].sMode = mode;
        break;
    case SHINE_MODE_DOUBLE:
        // Create an invisible sprite with mode set to update the background color
        spriteId = CreateSprite(&sPokemonLogoShineSpriteTemplate, 0, 68, 0);
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_WINDOW;
        gSprites[spriteId].sMode = mode;
        gSprites[spriteId].invisible = TRUE;

        // Create two faster shine sprites
        spriteId = CreateSprite(&sPokemonLogoShineSpriteTemplate, 0, 68, 0);
        gSprites[spriteId].callback = SpriteCB_PokemonLogoShine_Fast;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_WINDOW;

        spriteId = CreateSprite(&sPokemonLogoShineSpriteTemplate, -80, 68, 0);
        gSprites[spriteId].callback = SpriteCB_PokemonLogoShine_Fast;
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_WINDOW;
        break;
    }
}

#undef sMode
#undef sBgColor

static void VBlankCB(void)
{
    ScanlineEffect_InitHBlankDmaTransfer();
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
}

void CB2_InitTitleScreen(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        *((u16 *)PLTT) = RGB_WHITE;
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
        DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
        DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
        ResetPaletteFade();
        gMain.state = 1;
        break;
    case 1:
        // bg2
        LZ77UnCompVram(gTitleScreenPokemonLogoGfx, (void *)(BG_CHAR_ADDR(0)));
        LZ77UnCompVram(gTitleScreenPokemonLogoTilemap, (void *)(BG_SCREEN_ADDR(9)));
        // JP loads a larger background palette (9 palettes) plus one extra
        // palette slot for the legendary marking color.
        LoadPalette(gTitleScreenBgPalettes, BG_PLTT_ID(0), 0x120);
        // bg3
        LZ77UnCompVram(sTitleScreenRayquazaGfx, (void *)(BG_CHAR_ADDR(2)));
        LZ77UnCompVram(sTitleScreenRayquazaTilemap, (void *)(BG_SCREEN_ADDR(26)));
        LoadPalette(&gTitleScreenBgPalettes[0x50], BG_PLTT_ID(14), PLTT_SIZE_4BPP);
        // bg1
        LZ77UnCompVram(sTitleScreenCloudsGfx, (void *)(BG_CHAR_ADDR(3)));
        LZ77UnCompVram(gTitleScreenCloudsTilemap, (void *)(BG_SCREEN_ADDR(27)));
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 9;
        LoadCompressedSpriteSheet(&sSpriteSheet_EmeraldVersion[0]);
        LoadCompressedSpriteSheet(&sSpriteSheet_PressStart[0]);
        LoadCompressedSpriteSheet(&sPokemonLogoShineSpriteSheet[0]);
        LoadPalette(gTitleScreenBgPalettes, OBJ_PLTT_ID(0), 0x120);
        LoadSpritePalette(&sSpritePalette_PressStart[0]);
        gMain.state = 2;
        break;
    case 2:
    {
        u8 taskId = CreateTask(Task_TitleScreenPhase1, 0);

        gTasks[taskId].tCounter = 256;
        gTasks[taskId].tSkipToNext = FALSE;
        gTasks[taskId].tPointless = -16;
        gTasks[taskId].tBg2Y = -32;
        gMain.state = 3;
        break;
    }
    case 3:
        BeginNormalPaletteFade(PALETTES_ALL, 1, 16, 0, RGB_WHITEALPHA);
        SetVBlankCallback(VBlankCB);
        gMain.state = 4;
        break;
    case 4:
        PanFadeAndZoomScreen(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, 0x100, 0);
        // JP starts the background at x=-16 (US uses -29).
        SetGpuReg(REG_OFFSET_BG2X_L, -16 * 256);
        SetGpuReg(REG_OFFSET_BG2X_H, -1);
        SetGpuReg(REG_OFFSET_BG2Y_L, -32 * 256);
        SetGpuReg(REG_OFFSET_BG2Y_H, -1);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WINOBJ_ALL);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 12);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(26) | BGCNT_16COLOR | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(3) | BGCNT_SCREENBASE(27) | BGCNT_16COLOR | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(9) | BGCNT_256COLOR | BGCNT_AFF256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_OBJ_ON
                                    | DISPCNT_WIN0_ON
                                    | DISPCNT_OBJWIN_ON);
        m4aSongNumStart(MUS_TITLE);
        gMain.state = 5;
        break;
    case 5:
        if (!UpdatePaletteFade())
        {
            StartPokemonLogoShine(SHINE_MODE_SINGLE_NO_BG_COLOR);
            ScanlineEffect_InitWave(0, DISPLAY_HEIGHT, 4, 4, 0, SCANLINE_EFFECT_REG_BG1HOFS, TRUE);
            SetMainCallback2(MainCB2);
        }
        break;
    }
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

// Shine the PokÃ©mon logo two more times, and fade in the version banner
static void Task_TitleScreenPhase1(u8 taskId)
{
    // Skip to next phase when A, B, Start, or Select is pressed
    if (JOY_NEW(A_B_START_SELECT) || gTasks[taskId].tSkipToNext)
    {
        gTasks[taskId].tSkipToNext = TRUE;
        gTasks[taskId].tCounter = 0;
    }

    if (gTasks[taskId].tCounter != 0)
    {
        u16 frameNum = gTasks[taskId].tCounter;
        if (frameNum == 176)
            StartPokemonLogoShine(SHINE_MODE_DOUBLE);
        else if (frameNum == 64)
            StartPokemonLogoShine(SHINE_MODE_SINGLE);

        gTasks[taskId].tCounter--;
    }
    else
    {
        u8 spriteId;

        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        SetGpuReg(REG_OFFSET_BLDY, 0);

        // Create left side of version banner (JP positions it at x=162).
        spriteId = CreateSprite(&sVersionBannerLeftSpriteTemplate, VERSION_BANNER_LEFT_X, VERSION_BANNER_Y, 0);
        gSprites[spriteId].sAlphaBlendIdx = ARRAY_COUNT(gTitleScreenAlphaBlend);
        gSprites[spriteId].sParentTaskId = taskId;

        // Create right side of version banner (JP positions it at x=210).
        spriteId = CreateSprite(&sVersionBannerRightSpriteTemplate, VERSION_BANNER_RIGHT_X, VERSION_BANNER_Y, 0);
        gSprites[spriteId].sParentTaskId = taskId;

        gTasks[taskId].tCounter = 144;
        gTasks[taskId].func = Task_TitleScreenPhase2;
    }
}

#undef sParentTaskId
#undef sAlphaBlendIdx

// Show Rayquaza silhouette and process main title screen input
static void Task_TitleScreenPhase3(u8 taskId)
{
    if (JOY_NEW(A_BUTTON) || JOY_NEW(START_BUTTON))
    {
        FadeOutBGMTemporarily(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITEALPHA);
        SetMainCallback2(CB2_GoToMainMenu);
    }
    else if (JOY_HELD(CLEAR_SAVE_BUTTON_COMBO) == CLEAR_SAVE_BUTTON_COMBO)
    {
        SetMainCallback2(CB2_GoToClearSaveDataScreen);
    }
    else if (JOY_HELD(RESET_RTC_BUTTON_COMBO) == RESET_RTC_BUTTON_COMBO
      && CanResetRTC() == TRUE)
    {
        FadeOutBGMTemporarily(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_GoToResetRtcScreen);
    }
    else if (JOY_HELD(BERRY_UPDATE_BUTTON_COMBO) == BERRY_UPDATE_BUTTON_COMBO)
    {
        FadeOutBGMTemporarily(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_GoToBerryFixScreen);
    }
    else
    {
        // JP also resets the background X offset here (US only resets Y).
        SetGpuReg(REG_OFFSET_BG2X_L, 0);
        SetGpuReg(REG_OFFSET_BG2X_H, 0);
        SetGpuReg(REG_OFFSET_BG2Y_L, 0);
        SetGpuReg(REG_OFFSET_BG2Y_H, 0);
        if (++gTasks[taskId].tCounter & 1)
        {
            gTasks[taskId].tBg1Y++;
            gBattle_BG1_Y = gTasks[taskId].tBg1Y / 2;
            gBattle_BG1_X = 0;
        }
        UpdateLegendaryMarkingColor(gTasks[taskId].tCounter);
        if ((gMPlayInfo_BGM.status & 0xFFFF) == 0)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITEALPHA);
            SetMainCallback2(CB2_GoToCopyrightScreen);
        }
    }
}

static void CB2_GoToMainMenu(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitMainMenu);
}

static void CB2_GoToCopyrightScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitCopyrightScreenAfterTitleScreen);
}

static void CB2_GoToClearSaveDataScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitClearSaveDataScreen);
}

static void CB2_GoToResetRtcScreen(void)
{
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitResetRtcScreen);
}

static void CB2_GoToBerryFixScreen(void)
{
    if (!UpdatePaletteFade())
    {
        m4aMPlayAllStop();
        SetMainCallback2(CB2_InitBerryFixProgram);
    }
}

static void UpdateLegendaryMarkingColor(u8 frameNum)
{
    if ((frameNum % 4) == 0) // Change color every 4th frame
    {
        s32 intensity = Cos(frameNum, Q_8_8(0.5)) + Q_8_8(0.5);
        u32 r = 31 - Q_8_8_TO_INT(intensity * 31);
        u32 g = 31 - Q_8_8_TO_INT(intensity * 22);
        u32 b = 12;

        u16 color = RGB(r, g, b);
        LoadPalette(&color, BG_PLTT_ID(14) + 15, sizeof(color));
   }
}

#undef tCounter
#undef tSkipToNext
#undef tPointless
#undef tBg2Y
#undef tBg1Y
