#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gba/defines.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/weather.h"

#define GOING_DOWN gSpecialVar_0x8004

struct CableCarData
{
    u8 bgTaskId;
    u8 state;
    u8 weather;
    u16 weatherDelay;
    u16 timer;
    u8 bg0HorizontalOffset;
    u8 bg0VerticalOffset;
    u8 unused0[2];
    u8 bg1HorizontalOffset;
    u8 bg1VerticalOffset;
    u8 unused1[6];
    u8 bg3HorizontalOffset;
    u8 bg3VerticalOffset;
    u8 unused2[2];
    u8 groundTileIdx;
    u8 groundSegmentXStart;
    u8 groundSegmentYStart;
    u8 groundTilemapOffset;
    u8 groundTimer; // Incremented, but does nothing
    u8 groundXOffset;
    u8 groundYOffset;
    u8 groundXBase;
    u8 groundYBase;
    u16 groundTileBuffer[9][12];
    u8 unused3[2];
    u16 bgTilemapBuffers[4][BG_SCREEN_SIZE];
    u16 *groundTilemap;
    u16 *treesTilemap;
    u16 *bgMountainsTilemap;
    u16 *pylonTopTilemap;
    u16 *pylonPoleTilemap;
};

// JP: no EWRAM_DATA attribute (breaks agbcc struct tag parsing); ld alias
// sCableCar = gUnknown_203A878 places the pointer at the JP ROM address.
extern struct CableCarData *sCableCar;

extern void CB2_LoadCableCar(void);




extern const struct BgTemplate sCableCarBgTemplates[];
extern const u16 sCableCarGround_Tilemap[];
extern const u16 sCableCarTrees_Tilemap[];
extern const u16 sCableCarBgMountains_Tilemap[];
extern const u16 sCableCarPylonTop_Tilemap[];
extern const u16 sCableCarPylonPole_Tilemap[];
extern const struct CompressedSpriteSheet sCableCarSpriteSheets[];
extern const struct SpritePalette sCableCarSpritePalettes[];
extern const u32 gCableCarBg_Gfx[];
extern const u16 gCableCarBg_Pal[];

void CB2_CableCar(void);
extern void Task_CableCar(u8 taskId);
extern void Task_AnimateBgGoingUp(u8 taskId);
extern void Task_AnimateBgGoingDown(u8 taskId);
extern void VBlankCB_CableCar(void);
extern void CreateCableCarSprites(void);
extern void SetBgRegs(bool8 value);
extern void InitGroundTilemapData(u8 mode);

void CB2_LoadCableCar(void)
{
    u8 i = 0;
    u32 sizeOut = 0;

    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        SetBgRegs(FALSE);
        ScanlineEffect_Stop();
        DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
        DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
        DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
        sCableCar = AllocZeroed(sizeof(*sCableCar));
        gMain.state++;
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetTempTileDataBuffers();
        StartWeather();
        for (i = 0; i < NUM_ASH_SPRITES; i++)
            gWeatherPtr->sprites.s2.ashSprites[i] = NULL;

        InitMapMusic();
        ResetMapMusic();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sCableCarBgTemplates, 4);
        SetBgTilemapBuffer(0, sCableCar->bgTilemapBuffers[0]);
        SetBgTilemapBuffer(1, sCableCar->bgTilemapBuffers[1]);
        SetBgTilemapBuffer(2, sCableCar->bgTilemapBuffers[2]);
        SetBgTilemapBuffer(3, sCableCar->bgTilemapBuffers[3]);
        gSpriteCoordOffsetX = gSpriteCoordOffsetY = 0;
        gMain.state++;
        break;
    case 2:
        for (i = 0; i < 3; i++)
            LoadCompressedSpriteSheet(&sCableCarSpriteSheets[i]);

        LoadSpritePalettes(sCableCarSpritePalettes);
        sCableCar->groundTilemap = malloc_and_decompress(sCableCarGround_Tilemap, &sizeOut);
        sCableCar->treesTilemap = malloc_and_decompress(sCableCarTrees_Tilemap, &sizeOut);
        sCableCar->bgMountainsTilemap = malloc_and_decompress(sCableCarBgMountains_Tilemap, &sizeOut);
        sCableCar->pylonPoleTilemap = malloc_and_decompress(sCableCarPylonPole_Tilemap, &sizeOut);
        sCableCar->pylonTopTilemap = sCableCarPylonTop_Tilemap;
        DecompressAndCopyTileDataToVram(0, gCableCarBg_Gfx, 0, 0, 0);
        gMain.state++;
        break;
    case 3:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            LoadPalette(gCableCarBg_Pal, BG_PLTT_ID(0), 4 * PLTT_SIZE_4BPP);
            gMain.state++;
        }
        break;
    case 4:
        CreateCableCarSprites();
        RunTasks();
        gMain.state++;
        break;
    case 5:
        if (sCableCar->weather == WEATHER_VOLCANIC_ASH)
        {
            gMain.state++;
        }
        else if (gWeatherPtr->sprites.s2.ashSprites[0])
        {
            for (i = 0; i < NUM_ASH_SPRITES; i++)
            {
                if (gWeatherPtr->sprites.s2.ashSprites[i])
                    gWeatherPtr->sprites.s2.ashSprites[i]->oam.priority = 0;
            }

            gMain.state++;
        }
        break;
    case 6:
        CopyToBgTilemapBufferRect_ChangePalette(1, sCableCar->treesTilemap, 0, 17, 32, 15, 17);
        CopyToBgTilemapBufferRect_ChangePalette(2, sCableCar->bgMountainsTilemap, 0, 0, 30, 20, 17);
        CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonTopTilemap, 0, 0, 5, 2, 17);
        CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonPoleTilemap, 0, 2, 2, 20, 17);
        gMain.state++;
        break;
    case 7:
        InitGroundTilemapData(GOING_DOWN);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x48,  0, 14, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x6C, 12, 17, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x90, 24, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +   0x0,  0, 17, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x24,  0, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +   0x0, 12, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x24, 12, 23, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +   0x0, 24, 23, 12, 3, 17);
        gMain.state++;
        break;
    case 8:
        BeginNormalPaletteFade(PALETTES_ALL, 3, 16, 0, RGB_BLACK);
        FadeInNewBGM(MUS_CABLE_CAR, 1);
        SetBgRegs(TRUE);
        gMain.state++;
        break;
    case 9:
        IntrEnable(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_CableCar);
        SetMainCallback2(CB2_CableCar);
        CreateTask(Task_CableCar, 0);
        if (!GOING_DOWN)
            sCableCar->bgTaskId = CreateTask(Task_AnimateBgGoingUp, 1);
        else
            sCableCar->bgTaskId = CreateTask(Task_AnimateBgGoingDown, 1);
        break;
    }
}

static void Task_LoadCableCar(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_LoadCableCar);
        DestroyTask(taskId);
    }
}
void CableCar(void)
{
    LockPlayerFieldControls();
    CreateTask(Task_LoadCableCar, 1);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}

void CB2_CableCar(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    MapMusicMain();
}
