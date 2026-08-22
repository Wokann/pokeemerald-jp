#include "global.h"
#include "graphics.h"
#include "battle.h"
#include "battle_bg.h"
#include "battle_main.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "window.h"
#include "constants/global.h"
#include "constants/map_types.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"

struct BattleBackground
{
    const void *tileset;
    const void *tilemap;
    const void *entryTileset;
    const void *entryTilemap;
    const void *palette;
};

#define TAG_VS_LETTERS 10000
#define BATTLE_BG_ENVIRONMENT_DATA __attribute__((section(".rodata.battle_bg_environment_data")))

extern const struct BgTemplate gBattleBgTemplates[];
extern const struct WindowTemplate *const gBattleWindowTemplates[];
extern const struct SpriteTemplate sVsLetter_V_SpriteTemplate;
extern const struct SpriteTemplate sVsLetter_S_SpriteTemplate;
extern const struct CompressedSpriteSheet sVsLettersSpriteSheet;
extern const u32 gBattleTextboxTiles[];
extern const u32 gBattleTextboxTilemap[];
extern const u32 gBattleTextboxPalette[];
extern const u32 gBattleWindowTextPalette[];
extern const u8 gGameVersion; // JP: 0x03 = VERSION_EMERALD
extern const u32 gBattleVSFrame_Gfx[];
extern const u32 gVsLettersGfx[];
extern const u32 gBattleVSFrame_Pal[];
extern const u32 gBattleVSFrame_Tilemap[];
extern const u32 gBattleEnvironmentAnimTiles_Building[];
extern const u32 gBattleEnvironmentAnimTilemap_Building[];
extern const u32 gBattleEnvironmentAnimTiles_Cave[];
extern const u32 gBattleEnvironmentAnimTilemap_Cave[];
extern const u32 gBattleEnvironmentAnimTiles_Underwater[];
extern const u32 gBattleEnvironmentAnimTilemap_Underwater[];
extern const u32 gBattleEnvironmentAnimTiles_Rayquaza[];
extern const u32 gBattleEnvironmentAnimTilemap_Rayquaza[];
extern const u32 gMultiBattleIntroBg_Opponent_Tilemap[];
extern const u32 gMultiBattleIntroBg_Player_Tilemap[];
extern const u8 gText_Win[];
extern const u8 gText_Loss[];
extern const u8 gText_Draw[];

static const struct BattleBackground sBattleEnvironmentTable[] BATTLE_BG_ENVIRONMENT_DATA =
{
    [BATTLE_ENVIRONMENT_GRASS] =
    {
        .tileset = gBattleEnvironmentTiles_TallGrass,
        .tilemap = gBattleEnvironmentTilemap_TallGrass,
        .entryTileset = gBattleEnvironmentAnimTiles_TallGrass,
        .entryTilemap = gBattleEnvironmentAnimTilemap_TallGrass,
        .palette = gBattleEnvironmentPalette_TallGrass,
    },
    [BATTLE_ENVIRONMENT_LONG_GRASS] =
    {
        .tileset = gBattleEnvironmentTiles_LongGrass,
        .tilemap = gBattleEnvironmentTilemap_LongGrass,
        .entryTileset = gBattleEnvironmentAnimTiles_LongGrass,
        .entryTilemap = gBattleEnvironmentAnimTilemap_LongGrass,
        .palette = gBattleEnvironmentPalette_LongGrass,
    },
    [BATTLE_ENVIRONMENT_SAND] =
    {
        .tileset = gBattleEnvironmentTiles_Sand,
        .tilemap = gBattleEnvironmentTilemap_Sand,
        .entryTileset = gBattleEnvironmentAnimTiles_Sand,
        .entryTilemap = gBattleEnvironmentAnimTilemap_Sand,
        .palette = gBattleEnvironmentPalette_Sand,
    },
    [BATTLE_ENVIRONMENT_UNDERWATER] =
    {
        .tileset = gBattleEnvironmentTiles_Underwater,
        .tilemap = gBattleEnvironmentTilemap_Underwater,
        .entryTileset = gBattleEnvironmentAnimTiles_Underwater,
        .entryTilemap = gBattleEnvironmentAnimTilemap_Underwater,
        .palette = gBattleEnvironmentPalette_Underwater,
    },
    [BATTLE_ENVIRONMENT_WATER] =
    {
        .tileset = gBattleEnvironmentTiles_Water,
        .tilemap = gBattleEnvironmentTilemap_Water,
        .entryTileset = gBattleEnvironmentAnimTiles_Water,
        .entryTilemap = gBattleEnvironmentAnimTilemap_Water,
        .palette = gBattleEnvironmentPalette_Water,
    },
    [BATTLE_ENVIRONMENT_POND] =
    {
        .tileset = gBattleEnvironmentTiles_PondWater,
        .tilemap = gBattleEnvironmentTilemap_PondWater,
        .entryTileset = gBattleEnvironmentAnimTiles_PondWater,
        .entryTilemap = gBattleEnvironmentAnimTilemap_PondWater,
        .palette = gBattleEnvironmentPalette_PondWater,
    },
    [BATTLE_ENVIRONMENT_MOUNTAIN] =
    {
        .tileset = gBattleEnvironmentTiles_Rock,
        .tilemap = gBattleEnvironmentTilemap_Rock,
        .entryTileset = gBattleEnvironmentAnimTiles_Rock,
        .entryTilemap = gBattleEnvironmentAnimTilemap_Rock,
        .palette = gBattleEnvironmentPalette_Rock,
    },
    [BATTLE_ENVIRONMENT_CAVE] =
    {
        .tileset = gBattleEnvironmentTiles_Cave,
        .tilemap = gBattleEnvironmentTilemap_Cave,
        .entryTileset = gBattleEnvironmentAnimTiles_Cave,
        .entryTilemap = gBattleEnvironmentAnimTilemap_Cave,
        .palette = gBattleEnvironmentPalette_Cave,
    },
    [BATTLE_ENVIRONMENT_BUILDING] =
    {
        .tileset = gBattleEnvironmentTiles_Building,
        .tilemap = gBattleEnvironmentTilemap_Building,
        .entryTileset = gBattleEnvironmentAnimTiles_Building,
        .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
        .palette = gBattleEnvironmentPalette_Building,
    },
    [BATTLE_ENVIRONMENT_PLAIN] =
    {
        .tileset = gBattleEnvironmentTiles_Building,
        .tilemap = gBattleEnvironmentTilemap_Building,
        .entryTileset = gBattleEnvironmentAnimTiles_Building,
        .entryTilemap = gBattleEnvironmentAnimTilemap_Building,
        .palette = gBattleEnvironmentPalette_Plain,
    },
};

#undef BATTLE_BG_ENVIRONMENT_DATA

// JP globals (sym files) and helpers still in asm.
extern u8 gBattleTerrain;
extern u16 gTrainerBattleOpponent_A;
extern u16 gPartnerTrainerId;
extern void sub_0814FA04(const u8 *text, u8 windowId); // JP BattlePutTextOnWindow equivalent

// JP: this battle-type combo (0x023F0902) selects the building / frontier
// style battle background (differs from US pokeemerald's flag set).
#define JP_BATTLE_BG_FLAGS (BATTLE_TYPE_LINK | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER \
                            | BATTLE_TYPE_DOME | BATTLE_TYPE_PALACE | BATTLE_TYPE_ARENA \
                            | BATTLE_TYPE_FACTORY | BATTLE_TYPE_PIKE | BATTLE_TYPE_PYRAMID \
                            | BATTLE_TYPE_RECORDED_LINK)

static void DrawLinkBattleParticipantPokeballs(u8 taskId, u8 multiplayerId, u8 bgId, u8 destX, u8 destY);
static void DrawLinkBattleVsScreenOutcomeText(void);

// JP: these two unused functions sit right after the digit_obj_util module
// (0x08035460 / 0x080354A0), before the battle_bg functions.
static void UNUSED CB2_UnusedBattleInit(void);

static void UNUSED UnusedBattleInit(void)
{
    u8 spriteId;

    ResetSpriteData();
    spriteId = CreateSprite(&gUnusedBattleInitSprite, 0, 0, 0);
    gSprites[spriteId].invisible = TRUE;
    SetMainCallback2(CB2_UnusedBattleInit);
}

static void UNUSED CB2_UnusedBattleInit(void)
{
    AnimateSprites();
    BuildOamBuffer();
}

void BattleInitBgsAndWindows(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gBattleBgTemplates, 4); // JP ROM has 4 entries

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        gBattleScripting.windowsType = B_WIN_TYPE_ARENA;
        SetBgTilemapBuffer(1, gBattleAnimBgTilemapBuffer);
        SetBgTilemapBuffer(2, gBattleAnimBgTilemapBuffer);
    }
    else
    {
        gBattleScripting.windowsType = B_WIN_TYPE_NORMAL;
    }

    InitWindows(gBattleWindowTemplates[gBattleScripting.windowsType]);
    DeactivateAllTextPrinters();
}

void InitBattleBgsVideo(void)
{
    DisableInterrupts(INTR_FLAG_HBLANK);
    EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    BattleInitBgsAndWindows();
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

void LoadBattleMenuWindowGfx(void)
{
    LoadUserWindowBorderGfx(2, 0x12, BG_PLTT_ID(1));
    LoadUserWindowBorderGfx(2, 0x22, BG_PLTT_ID(1));
    LoadCompressedPalette(gBattleWindowTextPalette, BG_PLTT_ID(5), PLTT_SIZE_4BPP);

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
    {
        // Load graphics for the Battle Arena referee's mid-battle messages.
        Menu_LoadStdPalAt(BG_PLTT_ID(7));
        LoadMessageBoxGfx(0, 0x30, BG_PLTT_ID(7));
        gPlttBufferUnfaded[BG_PLTT_ID(7) + 6] = 0;
        CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(7) + 6], &gPlttBufferFaded[BG_PLTT_ID(7) + 6], PLTT_SIZEOF(1));
    }
}

void DrawMainBattleBackground(void)
{
    if (gBattleTypeFlags & JP_BATTLE_BG_FLAGS)
    {
        LZDecompressWram(gBattleEnvironmentTiles_Building, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressWram(gBattleEnvironmentTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleEnvironmentPalette_Frontier, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
    {
        LZDecompressWram(gBattleEnvironmentTiles_Cave, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressWram(gBattleEnvironmentTilemap_Cave, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleEnvironmentPalette_Groudon, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE)
    {
        LZDecompressWram(gBattleEnvironmentTiles_Water, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressWram(gBattleEnvironmentTilemap_Water, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleEnvironmentPalette_Kyogre, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_RAYQUAZA)
    {
        LZDecompressWram(gBattleEnvironmentTiles_Rayquaza, (void *)(BG_CHAR_ADDR(2)));
        LZDecompressWram(gBattleEnvironmentTilemap_Rayquaza, (void *)(BG_SCREEN_ADDR(26)));
        LoadCompressedPalette(gBattleEnvironmentPalette_Rayquaza, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;

            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressWram(gBattleEnvironmentTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressWram(gBattleEnvironmentTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                LoadCompressedPalette(gBattleEnvironmentPalette_BuildingLeader, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                LoadCompressedPalette(gBattleEnvironmentPalette_StadiumWallace, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                return;
            }
        }

        switch ((u8)GetCurrentMapBattleScene())
        {
        default:
        case MAP_BATTLE_SCENE_NORMAL:
            LZDecompressWram(sBattleEnvironmentTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(sBattleEnvironmentTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(sBattleEnvironmentTable[gBattleTerrain].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_GYM:
            LZDecompressWram(gBattleEnvironmentTiles_Building, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(gBattleEnvironmentTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_BuildingGym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_MAGMA:
            LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_StadiumMagma, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_AQUA:
            LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_StadiumAqua, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_SIDNEY:
            LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_StadiumSidney, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_PHOEBE:
            LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_StadiumPhoebe, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_GLACIA:
            LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_StadiumGlacia, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_DRAKE:
            LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_StadiumDrake, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        case MAP_BATTLE_SCENE_FRONTIER:
            LZDecompressWram(gBattleEnvironmentTiles_Building, (void *)(BG_CHAR_ADDR(2)));
            LZDecompressWram(gBattleEnvironmentTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
            LoadCompressedPalette(gBattleEnvironmentPalette_Frontier, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            break;
        }
    }
}

void LoadBattleTextboxAndBackground(void)
{
    // JP builds the address 0x08C00000 with movs/lsls (raw constant, not a symbol).
    LZDecompressWram((const u32 *)0x08C00000, (void *)(BG_CHAR_ADDR(0)));
    CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
    CopyBgTilemapBufferToVram(0);
    LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
    LoadBattleMenuWindowGfx();
    DrawMainBattleBackground();
}

static void DrawLinkBattleParticipantPokeballs(u8 taskId, u8 multiplayerId, u8 bgId, u8 destX, u8 destY)
{
    s32 i;
    u16 pokeballStatuses = 0;
    u16 tiles[6];

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gTasks[taskId].data[5] != 0)
        {
            switch (multiplayerId)
            {
            case 0:
                pokeballStatuses = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            case 2:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                pokeballStatuses = 0x3F & gTasks[taskId].data[4];
                break;
            }
        }
        else
        {
            switch (multiplayerId)
            {
            case 0:
                pokeballStatuses = 0x3F & gTasks[taskId].data[3];
                break;
            case 1:
                pokeballStatuses = 0x3F & gTasks[taskId].data[4];
                break;
            case 2:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[3]) >> 6;
                break;
            case 3:
                pokeballStatuses = (0xFC0 & gTasks[taskId].data[4]) >> 6;
                break;
            }
        }

        for (i = 0; i < 3; i++)
            tiles[i] = ((pokeballStatuses & (3 << (i * 2))) >> (i * 2)) + 0x6001;

        CopyToBgTilemapBufferRect_ChangePalette(bgId, tiles, destX, destY, 3, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
    else
    {
        if (multiplayerId == gBattleScripting.multiplayerId)
            pokeballStatuses = gTasks[taskId].data[3];
        else
            pokeballStatuses = gTasks[taskId].data[4];

        for (i = 0; i < 6; i++)
            tiles[i] = ((pokeballStatuses & (3 << (i * 2))) >> (i * 2)) + 0x6001;

        CopyToBgTilemapBufferRect_ChangePalette(bgId, tiles, destX, destY, 6, 1, 0x11);
        CopyBgTilemapBufferToVram(bgId);
    }
}

static void DrawLinkBattleVsScreenOutcomeText(void)
{
    if (gBattleOutcome == B_OUTCOME_DREW)
    {
        sub_0814FA04(gText_Draw, B_WIN_VS_OUTCOME_DRAW);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleOutcome == B_OUTCOME_WON)
        {
            switch (gLinkPlayers[gBattleScripting.multiplayerId].id)
            {
            case 0:
                sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 1:
                sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 2:
                sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 3:
                sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            }
        }
        else
        {
            switch (gLinkPlayers[gBattleScripting.multiplayerId].id)
            {
            case 0:
                sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 1:
                sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            case 2:
                sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
                sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
                break;
            case 3:
                sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_LEFT);
                sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
                break;
            }
        }
    }
    else if (gBattleOutcome == B_OUTCOME_WON)
    {
        if (gLinkPlayers[gBattleScripting.multiplayerId].id != 0)
        {
            sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
            sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
        }
        else
        {
            sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_LEFT);
            sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
        }
    }
    else
    {
        if (gLinkPlayers[gBattleScripting.multiplayerId].id != 0)
        {
            sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_LEFT);
            sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_RIGHT);
        }
        else
        {
            sub_0814FA04(gText_Win, B_WIN_VS_OUTCOME_RIGHT);
            sub_0814FA04(gText_Loss, B_WIN_VS_OUTCOME_LEFT);
        }
    }
}

void InitLinkBattleVsScreen(u8 taskId)
{
    u8 *name;
    s32 i, palId;
    u8 buffer[PLAYER_NAME_LENGTH + 1];
    u32 taskData;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        {
            // JP iterates the name pointer (name is at offset 0x08 of LinkPlayer,
            // id is a u16 at 0x18, so id sits at name + 0x10).
            taskData = taskId * 4;
            name = gLinkPlayers[0].name;
            for (i = MAX_LINK_PLAYERS - 1; i >= 0; i--)
            {
                StringCopy7(buffer, name);
                switch (*(u16 *)(name + 0x10))
                {
                case 0:
                    sub_0814FA04(buffer, B_WIN_VS_MULTI_PLAYER_1);
                    DrawLinkBattleParticipantPokeballs(taskId, *(u8 *)(name + 0x10), 1, 2, 4);
                    break;
                case 1:
                    sub_0814FA04(buffer, B_WIN_VS_MULTI_PLAYER_2);
                    DrawLinkBattleParticipantPokeballs(taskId, *(u8 *)(name + 0x10), 2, 2, 4);
                    break;
                case 2:
                    sub_0814FA04(buffer, B_WIN_VS_MULTI_PLAYER_3);
                    DrawLinkBattleParticipantPokeballs(taskId, *(u8 *)(name + 0x10), 1, 2, 8);
                    break;
                case 3:
                    sub_0814FA04(buffer, B_WIN_VS_MULTI_PLAYER_4);
                    DrawLinkBattleParticipantPokeballs(taskId, *(u8 *)(name + 0x10), 2, 2, 8);
                    break;
                }
                name += sizeof(struct LinkPlayer);
            }
        }
        else
        {
            u8 playerId = gBattleScripting.multiplayerId;
            u8 opponentId = playerId ^ BIT_SIDE;
            u8 opponentId_copy = opponentId;

            if (gLinkPlayers[playerId].id != 0)
                opponentId = playerId, playerId = opponentId_copy;

            StringCopy7(buffer, gLinkPlayers[playerId].name);
            sub_0814FA04(buffer, B_WIN_VS_PLAYER);

            StringCopy7(buffer, gLinkPlayers[opponentId].name);
            sub_0814FA04(buffer, B_WIN_VS_OPPONENT);

            DrawLinkBattleParticipantPokeballs(taskId, playerId, 1, 2, 7);
            DrawLinkBattleParticipantPokeballs(taskId, opponentId, 2, 2, 7);
            taskData = taskId * 4;
        }
        {
            // JP tail: gTasks[taskId].data[0]++, using taskData (r6) + taskId (r7).
            u8 *taskBase = (u8 *)gTasks;
            u8 *task = taskBase + ((taskData + taskId) << 3);
            *(u16 *)(task + 8) += 1;
        }
        break;
    case 1:
        palId = AllocSpritePalette(TAG_VS_LETTERS);
        gPlttBufferUnfaded[OBJ_PLTT_ID(palId) + 15] = gPlttBufferFaded[OBJ_PLTT_ID(palId) + 15] = RGB_WHITE;
        gBattleStruct->linkBattleVsSpriteId_V = CreateSprite(&sVsLetter_V_SpriteTemplate, 111, 80, 0);
        gBattleStruct->linkBattleVsSpriteId_S = CreateSprite(&sVsLetter_S_SpriteTemplate, 129, 80, 0);
        gSprites[gBattleStruct->linkBattleVsSpriteId_V].invisible = TRUE;
        gSprites[gBattleStruct->linkBattleVsSpriteId_S].invisible = TRUE;
        gTasks[taskId].data[0]++;
        break;
    case 2:
        if (gTasks[taskId].data[5] != 0)
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG1_Y = -36;
            gBattle_BG2_Y = -36;
        }
        else
        {
            gBattle_BG1_X = -(20) - (Sin2(gTasks[taskId].data[1]) / 32);
            gBattle_BG1_Y = (Cos2(gTasks[taskId].data[1]) / 32) - 164;
            gBattle_BG2_X = -(140) - (Sin2(gTasks[taskId].data[2]) / 32);
            gBattle_BG2_Y = (Cos2(gTasks[taskId].data[2]) / 32) - 164;
        }

        if (gTasks[taskId].data[2] != 0)
        {
            gTasks[taskId].data[2] -= 2;
            gTasks[taskId].data[1] += 2;
        }
        else
        {
            if (gTasks[taskId].data[5] != 0)
                DrawLinkBattleVsScreenOutcomeText();

            PlaySE(SE_M_HARDEN);
            DestroyTask(taskId);
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].invisible = FALSE;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].invisible = FALSE;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].oam.tileNum += 0x40;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[0] = 0;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[0] = 1;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[1] = gSprites[gBattleStruct->linkBattleVsSpriteId_V].x;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[1] = gSprites[gBattleStruct->linkBattleVsSpriteId_S].x;
            gSprites[gBattleStruct->linkBattleVsSpriteId_V].data[2] = 0;
            gSprites[gBattleStruct->linkBattleVsSpriteId_S].data[2] = 0;
        }
        break;
    }
}

void DrawBattleEntryBackground(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        LZDecompressWram(gBattleVSFrame_Gfx, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressWram(gVsLettersGfx, (void *)OBJ_VRAM0);
        LoadCompressedPalette(gBattleVSFrame_Pal, BG_PLTT_ID(6), PLTT_SIZE_4BPP);
        SetBgAttribute(1, BG_ATTR_SCREENSIZE, 1);
        SetGpuReg(REG_OFFSET_BG1CNT, 0x5C04);
        CopyToBgTilemapBuffer(1, gBattleVSFrame_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(2, gBattleVSFrame_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_OBJ | WININ_WIN0_CLR);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        gBattle_BG1_Y = 0xFF5C;
        gBattle_BG2_Y = 0xFF5C;
        LoadCompressedSpriteSheetUsingHeap(&sVsLettersSpriteSheet);
    }
    else if (gBattleTypeFlags & JP_BATTLE_BG_FLAGS)
    {
        if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) || gPartnerTrainerId == TRAINER_STEVEN_PARTNER)
        {
            LZDecompressWram(gBattleEnvironmentAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressWram(gBattleEnvironmentAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
        }
        else
        {
            // Set up bg for the multi battle intro where both teams slide in facing the screen.
            // Note Steven's multi battle (which has a dedicated back pic) is excluded above.
            SetBgAttribute(1, BG_ATTR_CHARBASEINDEX, 2);
            SetBgAttribute(2, BG_ATTR_CHARBASEINDEX, 2);
            CopyToBgTilemapBuffer(1, gMultiBattleIntroBg_Opponent_Tilemap, 0, 0);
            CopyToBgTilemapBuffer(2, gMultiBattleIntroBg_Player_Tilemap, 0, 0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
    {
        LZDecompressWram(gBattleEnvironmentAnimTiles_Cave, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressWram(gBattleEnvironmentAnimTilemap_Cave, (void *)(BG_SCREEN_ADDR(28)));
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE)
    {
        LZDecompressWram(gBattleEnvironmentAnimTiles_Underwater, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressWram(gBattleEnvironmentAnimTilemap_Underwater, (void *)(BG_SCREEN_ADDR(28)));
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_RAYQUAZA)
    {
        LZDecompressWram(gBattleEnvironmentAnimTiles_Rayquaza, (void *)(BG_CHAR_ADDR(1)));
        LZDecompressWram(gBattleEnvironmentAnimTilemap_Rayquaza, (void *)(BG_SCREEN_ADDR(28)));
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;

            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressWram(gBattleEnvironmentAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressWram(gBattleEnvironmentAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressWram(gBattleEnvironmentAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
                LZDecompressWram(gBattleEnvironmentAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
                return;
            }
        }

        if ((u8)GetCurrentMapBattleScene() == MAP_BATTLE_SCENE_NORMAL)
        {
            LZDecompressWram(sBattleEnvironmentTable[gBattleTerrain].entryTileset, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressWram(sBattleEnvironmentTable[gBattleTerrain].entryTilemap, (void *)(BG_SCREEN_ADDR(28)));
        }
        else
        {
            LZDecompressWram(gBattleEnvironmentAnimTiles_Building, (void *)(BG_CHAR_ADDR(1)));
            LZDecompressWram(gBattleEnvironmentAnimTilemap_Building, (void *)(BG_SCREEN_ADDR(28)));
        }
    }
}

bool8 LoadChosenBattleElement(u8 caseId)
{
    bool8 ret = FALSE;

    switch (caseId)
    {
    case 0:
        LZDecompressWram((const u32 *)0x08C00000, (void *)(BG_CHAR_ADDR(0)));
        break;
    case 1:
        CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
        CopyBgTilemapBufferToVram(0);
        break;
    case 2:
        LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
        break;
    case 3:
        if (gBattleTypeFlags & JP_BATTLE_BG_FLAGS)
        {
            LZDecompressWram(gBattleEnvironmentTiles_Building, (void *)(BG_CHAR_ADDR(2)));
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_GROUDON)
        {
            LZDecompressWram(gBattleEnvironmentTiles_Cave, (void *)(BG_CHAR_ADDR(2)));
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;

                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressWram(gBattleEnvironmentTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                    break;
                }
            }

            switch ((u8)GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LZDecompressWram(sBattleEnvironmentTable[gBattleTerrain].tileset, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_GYM:
                LZDecompressWram(gBattleEnvironmentTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LZDecompressWram(gBattleEnvironmentTiles_Stadium, (void *)(BG_CHAR_ADDR(2)));
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LZDecompressWram(gBattleEnvironmentTiles_Building, (void *)(BG_CHAR_ADDR(2)));
                break;
            }
        }
        break;
    case 4:
        if (gBattleTypeFlags & JP_BATTLE_BG_FLAGS)
        {
            LZDecompressWram(gBattleEnvironmentTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
        {
            if (gGameVersion == VERSION_RUBY)
                LZDecompressWram(gBattleEnvironmentTilemap_Cave, (void *)(BG_SCREEN_ADDR(26)));
            else
                LZDecompressWram(gBattleEnvironmentTilemap_Water, (void *)(BG_SCREEN_ADDR(26)));
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;

                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LZDecompressWram(gBattleEnvironmentTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                    break;
                }
            }

            switch ((u8)GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LZDecompressWram(sBattleEnvironmentTable[gBattleTerrain].tilemap, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_GYM:
                LZDecompressWram(gBattleEnvironmentTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LZDecompressWram(gBattleEnvironmentTilemap_Stadium, (void *)(BG_SCREEN_ADDR(26)));
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LZDecompressWram(gBattleEnvironmentTilemap_Building, (void *)(BG_SCREEN_ADDR(26)));
                break;
            }
        }
        break;
    case 5:
        if (gBattleTypeFlags & JP_BATTLE_BG_FLAGS)
        {
            LoadCompressedPalette(gBattleEnvironmentPalette_Frontier, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
        {
            if (gGameVersion == VERSION_RUBY)
                LoadCompressedPalette(gBattleEnvironmentPalette_Groudon, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
            else
                LoadCompressedPalette(gBattleEnvironmentPalette_Kyogre, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
            {
                u8 trainerClass = gTrainers[gTrainerBattleOpponent_A].trainerClass;

                if (trainerClass == TRAINER_CLASS_LEADER)
                {
                    LoadCompressedPalette(gBattleEnvironmentPalette_BuildingLeader, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                    break;
                }
                else if (trainerClass == TRAINER_CLASS_CHAMPION)
                {
                    LoadCompressedPalette(gBattleEnvironmentPalette_StadiumWallace, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                    break;
                }
            }

            switch ((u8)GetCurrentMapBattleScene())
            {
            default:
            case MAP_BATTLE_SCENE_NORMAL:
                LoadCompressedPalette(sBattleEnvironmentTable[gBattleTerrain].palette, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_GYM:
                LoadCompressedPalette(gBattleEnvironmentPalette_BuildingGym, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_MAGMA:
                LoadCompressedPalette(gBattleEnvironmentPalette_StadiumMagma, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_AQUA:
                LoadCompressedPalette(gBattleEnvironmentPalette_StadiumAqua, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_SIDNEY:
                LoadCompressedPalette(gBattleEnvironmentPalette_StadiumSidney, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_PHOEBE:
                LoadCompressedPalette(gBattleEnvironmentPalette_StadiumPhoebe, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_GLACIA:
                LoadCompressedPalette(gBattleEnvironmentPalette_StadiumGlacia, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_DRAKE:
                LoadCompressedPalette(gBattleEnvironmentPalette_StadiumDrake, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            case MAP_BATTLE_SCENE_FRONTIER:
                LoadCompressedPalette(gBattleEnvironmentPalette_Frontier, BG_PLTT_ID(2), 3 * PLTT_SIZE_4BPP);
                break;
            }
        }
        break;
    case 6:
        LoadBattleMenuWindowGfx();
        break;
    default:
        ret = TRUE;
        break;
    }

    return ret;
}
