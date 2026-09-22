#include "global.h"
#include "battle.h"
#include "egg_hatch.h"
#include "bg.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "dma3.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "naming_screen.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trade.h"
#include "trig.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define GFXTAG_EGG       12345
#define GFXTAG_EGG_SHARD 23456
#define PALTAG_EGG       54321

#define EGG_X (DISPLAY_WIDTH / 2)
#define EGG_Y (DISPLAY_HEIGHT / 2 - 5)

struct EggHatchData
{
    u8 eggSpriteId;
    u8 monSpriteId;
    u8 state;
    u8 delayTimer;
    u8 eggPartyId;
    u8 unused_5;
    u8 unused_6;
    u8 eggShardVelocityId;
    u8 windowId;
    u8 unused_9;
    u8 unused_A;
    u16 species;
    u8 textColor[3];
};

extern struct EggHatchData *gUnknown_3000DE0;

#define sEggHatchData gUnknown_3000DE0

#define EGG_HATCH_STATIC_DATA __attribute__((section(".rodata.egg_hatch_static_data"), aligned(1)))
#define EGG_HATCH_GRAPHICS_DATA __attribute__((section(".rodata.egg_hatch_graphics"), aligned(1)))

static void SpriteCB_EggShard(struct Sprite *sprite);
static void CreatedHatchedMon(struct Pokemon *egg, struct Pokemon *temp);
static void AddHatchedMonToParty(u8 id);
static bool8 sub_08070FA4(struct DayCare *daycare, u8 daycareId);
static u8 EggHatchCreateMonSprite(u8 useAlt, u8 state, u8 partyId, u16 *speciesLoc);
static void VBlankCB_EggHatch(void);
static void Task_EggHatch(u8 taskId);
static void CB2_EggHatch_0(void);
static void CB2_EggHatch_1(void);
static void EggHatchSetMonNickname(void);
static void Task_EggHatchPlayBGM(u8 taskId);
static void SpriteCB_Egg_0(struct Sprite *sprite);
static void SpriteCB_Egg_1(struct Sprite *sprite);
static void SpriteCB_Egg_2(struct Sprite *sprite);
static void SpriteCB_Egg_3(struct Sprite *sprite);
static void SpriteCB_Egg_4(struct Sprite *sprite);
static void SpriteCB_Egg_5(struct Sprite *sprite);
static void CreateRandomEggShardSprite(void);
static void CreateEggShardSprite(u8 x, u8 y, s16 velocityX, s16 velocityY, s16 acceleration, u8 spriteAnimIndex);
static void EggHatchPrintMessage(u8 windowId, u8 *string, u8 x, u8 y, u8 speed);

extern void GetBoxMonNick(struct Pokemon *mon, u8 *dest);
extern void GetMonNick(struct BoxPokemon *mon, u8 *dest);
extern void CreateYesNoMenuAtPos(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
extern const u16 gUnknown_8305D24[];
extern const u16 gUnknown_8305D84[];
extern const u16 gUnknown_8304D04[];
extern const u8 gUnknown_85CC874[];
extern const u8 gUnknown_85CC888[];

static const u16 sEggPalette[] EGG_HATCH_GRAPHICS_DATA = INCGFX_U16("graphics/pokemon/egg/normal.pal", ".gbapal");
static const u8 sEggHatchTiles[] EGG_HATCH_GRAPHICS_DATA = INCGFX_U8("graphics/pokemon/egg/hatch.png", ".4bpp");
static const u8 sEggShardTiles[] EGG_HATCH_GRAPHICS_DATA = INCGFX_U8("graphics/pokemon/egg/shard.png", ".4bpp");

static const struct OamData sOamData_Egg EGG_HATCH_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_Egg_Normal[] EGG_HATCH_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_Egg_Cracked1[] EGG_HATCH_STATIC_DATA =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_Egg_Cracked2[] EGG_HATCH_STATIC_DATA =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_Egg_Cracked3[] EGG_HATCH_STATIC_DATA =
{
    ANIMCMD_FRAME(48, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sSpriteAnimTable_Egg[] EGG_HATCH_STATIC_DATA =
{
    sSpriteAnim_Egg_Normal,
    sSpriteAnim_Egg_Cracked1,
    sSpriteAnim_Egg_Cracked2,
    sSpriteAnim_Egg_Cracked3,
};

enum
{
    EGG_ANIM_NORMAL,
    EGG_ANIM_CRACKED_1,
    EGG_ANIM_CRACKED_2,
    EGG_ANIM_CRACKED_3,
};

const struct SpriteSheet sEggHatch_Sheet EGG_HATCH_STATIC_DATA =
{
    .data = sEggHatchTiles,
    .size = 0x800,
    .tag = GFXTAG_EGG,
};

const struct SpriteSheet sEggShards_Sheet EGG_HATCH_STATIC_DATA =
{
    .data = sEggShardTiles,
    .size = 0x80,
    .tag = GFXTAG_EGG_SHARD,
};

const struct SpritePalette sEgg_SpritePalette EGG_HATCH_STATIC_DATA =
{
    .data = sEggPalette,
    .tag = PALTAG_EGG,
};

const struct SpriteTemplate sSpriteTemplate_Egg EGG_HATCH_STATIC_DATA =
{
    .tileTag = GFXTAG_EGG,
    .paletteTag = PALTAG_EGG,
    .oam = &sOamData_Egg,
    .anims = sSpriteAnimTable_Egg,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sOamData_EggShard EGG_HATCH_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_EggShard0[] EGG_HATCH_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_EggShard1[] EGG_HATCH_STATIC_DATA =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_EggShard2[] EGG_HATCH_STATIC_DATA =
{
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_END,
};

static const union AnimCmd sSpriteAnim_EggShard3[] EGG_HATCH_STATIC_DATA =
{
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sSpriteAnimTable_EggShard[] EGG_HATCH_STATIC_DATA =
{
    sSpriteAnim_EggShard0,
    sSpriteAnim_EggShard1,
    sSpriteAnim_EggShard2,
    sSpriteAnim_EggShard3,
};

const struct SpriteTemplate sSpriteTemplate_EggShard EGG_HATCH_STATIC_DATA =
{
    .tileTag = GFXTAG_EGG_SHARD,
    .paletteTag = PALTAG_EGG,
    .oam = &sOamData_EggShard,
    .anims = sSpriteAnimTable_EggShard,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_EggShard,
};

const struct BgTemplate sBgTemplates_EggHatch[] EGG_HATCH_STATIC_DATA =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 24,
        .screenSize = 3,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 8,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
};

const struct WindowTemplate sWinTemplates_EggHatch[] EGG_HATCH_STATIC_DATA =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 64,
    },
    DUMMY_WIN_TEMPLATE,
};

const struct WindowTemplate sYesNoWinTemplate EGG_HATCH_STATIC_DATA =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 424,
};

const s16 sEggShardVelocities[][2] EGG_HATCH_STATIC_DATA =
{
    {Q_8_8(-1.5),       Q_8_8(-3.75)},
    {Q_8_8(-5),         Q_8_8(-3)},
    {Q_8_8(3.5),        Q_8_8(-3)},
    {Q_8_8(-4),         Q_8_8(-3.75)},
    {Q_8_8(2),          Q_8_8(-1.5)},
    {Q_8_8(-0.5),       Q_8_8(-6.75)},
    {Q_8_8(5),          Q_8_8(-2.25)},
    {Q_8_8(-1.5),       Q_8_8(-3.75)},
    {Q_8_8(4.5),        Q_8_8(-1.5)},
    {Q_8_8(-1),         Q_8_8(-6.75)},
    {Q_8_8(4),          Q_8_8(-2.25)},
    {Q_8_8(-3.5),       Q_8_8(-3.75)},
    {Q_8_8(1),          Q_8_8(-1.5)},
    {Q_8_8(-3.515625),  Q_8_8(-6.75)},
    {Q_8_8(4.5),        Q_8_8(-2.25)},
    {Q_8_8(-0.5),       Q_8_8(-7.5)},
    {Q_8_8(1),          Q_8_8(-4.5)},
    {Q_8_8(-2.5),       Q_8_8(-2.25)},
    {Q_8_8(2.5),        Q_8_8(-7.5)},
};

static void CreatedHatchedMon(struct Pokemon *egg, struct Pokemon *temp)
{
    u16 species;
    u32 personality, pokerus;
    u8 i, friendship, language, gameMet, markings, isModernFatefulEncounter;
    u16 moves[MAX_MON_MOVES];
    u32 ivs[NUM_STATS];

    species = GetMonData3(egg, MON_DATA_SPECIES);

    for (i = 0; i < MAX_MON_MOVES; i++)
        moves[i] = GetMonData3(egg, MON_DATA_MOVE1 + i);

    personality = GetMonData3(egg, MON_DATA_PERSONALITY);

    for (i = 0; i < NUM_STATS; i++)
        ivs[i] = GetMonData3(egg, MON_DATA_HP_IV + i);

    language = GetMonData3(egg, MON_DATA_LANGUAGE);
    gameMet = GetMonData3(egg, MON_DATA_MET_GAME);
    markings = GetMonData3(egg, MON_DATA_MARKINGS);
    pokerus = GetMonData3(egg, MON_DATA_POKERUS);
    isModernFatefulEncounter = GetMonData3(egg, MON_DATA_MODERN_FATEFUL_ENCOUNTER);

    CreateMon(temp, species, EGG_HATCH_LEVEL, USE_RANDOM_IVS, TRUE, personality, OT_ID_PLAYER_ID, 0);

    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonData(temp, MON_DATA_MOVE1 + i, &moves[i]);

    for (i = 0; i < NUM_STATS; i++)
        SetMonData(temp, MON_DATA_HP_IV + i, &ivs[i]);

    SetMonData(temp, MON_DATA_LANGUAGE, &language);
    SetMonData(temp, MON_DATA_MET_GAME, &gameMet);
    SetMonData(temp, MON_DATA_MARKINGS, &markings);

    friendship = 120;
    SetMonData(temp, MON_DATA_FRIENDSHIP, &friendship);
    SetMonData(temp, MON_DATA_POKERUS, &pokerus);
    SetMonData(temp, MON_DATA_MODERN_FATEFUL_ENCOUNTER, &isModernFatefulEncounter);

    *egg = *temp;
}

static void AddHatchedMonToParty(u8 id)
{
    u8 isEgg = 0x46;
    u16 species;
    // The JP name table uses 5-character strings, but mon nickname storage
    // retains the 10-character international layout used by this routine.
    u8 name[POKEMON_NAME_STORAGE_LENGTH + 1];
    u16 ball;
    u16 metLevel;
    metloc_u8_t metLocation;
    struct Pokemon *mon = &gPlayerParty[id];

    CreatedHatchedMon(mon, &gEnemyParty[0]);
    SetMonData(mon, MON_DATA_IS_EGG, &isEgg);

    species = GetMonData3(mon, MON_DATA_SPECIES);
    GetSpeciesName(name, species);
    SetMonData(mon, MON_DATA_NICKNAME, name);

    species = HoennToNationalOrder(species);
    GetSetPokedexFlag(species, FLAG_SET_SEEN);
    GetSetPokedexFlag(species, FLAG_SET_CAUGHT);

    GetBoxMonNick(mon, gStringVar1);

    ball = ITEM_POKE_BALL;
    SetMonData(mon, MON_DATA_POKEBALL, &ball);

    metLevel = 0;
    SetMonData(mon, MON_DATA_MET_LEVEL, &metLevel);

    metLocation = GetCurrentRegionMapSectionId();
    SetMonData(mon, MON_DATA_MET_LOCATION, &metLocation);

    GiveMonInitialMoveset(mon);
    CalculateMonStats(mon);
}

void ScriptHatchMon(void)
{
    AddHatchedMonToParty(gSpecialVar_0x8004);
}

static bool8 sub_08070FA4(struct DayCare *daycare, u8 daycareId)
{
    u8 nickname[max(32, POKEMON_NAME_BUFFER_SIZE)];
    struct DaycareMon *daycareMon = &daycare->mons[daycareId];

    GetMonNick(&daycareMon->mon, nickname);
    if (daycareMon->mail.message.itemId != ITEM_NONE
        && (StringCompare(nickname, daycareMon->mail.monName) != 0
         || StringCompare(gSaveBlock2Ptr->playerName, daycareMon->mail.otName) != 0))
    {
        StringCopy(gStringVar1, nickname);
        StringCopy(gStringVar2, daycareMon->mail.otName);
        StringCopy(gStringVar3, daycareMon->mail.monName);
        return TRUE;
    }
    return FALSE;
}

bool8 CheckDaycareMonReceivedMail(void)
{
    return sub_08070FA4(&gSaveBlock1Ptr->daycare, gSpecialVar_0x8004);
}

static u8 EggHatchCreateMonSprite(u8 useAlt, u8 state, u8 partyId, u16 *speciesLoc)
{
    u8 position = 0;
    u8 spriteId = 0;
    struct Pokemon *mon = NULL;

    if (useAlt == FALSE)
    {
        mon = &gPlayerParty[partyId];
        position = B_POSITION_OPPONENT_LEFT;
    }
    if (useAlt == TRUE)
    {
        mon = &gPlayerParty[partyId];
        position = B_POSITION_OPPONENT_RIGHT;
    }
    switch (state)
    {
    case 0:
        {
            u16 species = GetMonData3(mon, MON_DATA_SPECIES);
            u32 pid = GetMonData3(mon, MON_DATA_PERSONALITY);
            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species],
                                                      gMonSpritesGfxPtr->sprites.ptr[(useAlt * 2) + B_POSITION_OPPONENT_LEFT],
                                                      species, pid);
            LoadCompressedSpritePalette(GetMonSpritePalStruct(mon));
            *speciesLoc = species;
        }
        break;
    case 1:
        SetMultiuseSpriteTemplateToPokemon(GetMonSpritePalStruct(mon)->tag, position);
        spriteId = CreateSprite(&gMultiuseSpriteTemplate, EGG_X, EGG_Y, 6);
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        break;
    }
    return spriteId;
}

static void VBlankCB_EggHatch(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void EggHatch(void)
{
    LockPlayerFieldControls();
    CreateTask(Task_EggHatch, 10);
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_EggHatch(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_EggHatch_0);
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        DestroyTask(taskId);
    }
}

static void CB2_EggHatch_0(void)
{
    switch (gMain.state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, 0);

        sEggHatchData = Alloc(sizeof(*sEggHatchData));
        AllocateMonSpritesGfx();
        sEggHatchData->eggPartyId = gSpecialVar_0x8004;
        sEggHatchData->eggShardVelocityId = 0;

        SetVBlankCallback(VBlankCB_EggHatch);
        gSpecialVar_0x8005 = GetCurrentMapMusic();

        ResetTempTileDataBuffers();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates_EggHatch, ARRAY_COUNT(sBgTemplates_EggHatch));

        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);

        SetBgAttribute(1, BG_ATTR_PRIORITY, 2);
        SetBgTilemapBuffer(1, Alloc(0x1000));
        SetBgTilemapBuffer(0, Alloc(0x2000));

        DeactivateAllTextPrinters();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        ResetSpriteData();
        ResetTasks();
        ScanlineEffect_Stop();
        m4aSoundVSyncOn();
        gMain.state++;
        break;
    case 1:
        InitWindows(sWinTemplates_EggHatch);
        sEggHatchData->windowId = 0;
        gMain.state++;
        break;
    case 2:
        DecompressAndLoadBgGfxUsingHeap(0, (const u32 *)0x08C00000, 0, 0, 0);
        CopyToBgTilemapBuffer(0, gBattleTextboxTilemap, 0, 0);
        LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 3:
        LoadSpriteSheet(&sEggHatch_Sheet);
        LoadSpriteSheet(&sEggShards_Sheet);
        LoadSpritePalette(&sEgg_SpritePalette);
        gMain.state++;
        break;
    case 4:
        CopyBgTilemapBufferToVram(0);
        AddHatchedMonToParty(sEggHatchData->eggPartyId);
        gMain.state++;
        break;
    case 5:
        EggHatchCreateMonSprite(FALSE, 0, sEggHatchData->eggPartyId, &sEggHatchData->species);
        gMain.state++;
        break;
    case 6:
        sEggHatchData->monSpriteId = EggHatchCreateMonSprite(FALSE, 1, sEggHatchData->eggPartyId, &sEggHatchData->species);
        gMain.state++;
        break;
    case 7:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        LoadPalette(gUnknown_8305D24, BG_PLTT_ID(1), 5 * PLTT_SIZE_4BPP);
        LoadBgTiles(1, gUnknown_8305D84, 0x1300, 0);
        CopyToBgTilemapBuffer(1, gUnknown_8304D04, 0x1000, 0);
        CopyBgTilemapBufferToVram(1);
        gMain.state++;
        break;
    case 8:
        SetMainCallback2(CB2_EggHatch_1);
        sEggHatchData->state = 0;
        break;
    }
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void EggHatchSetMonNickname(void)
{
    SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_NICKNAME, gStringVar3);
    FreeMonSpritesGfx();
    Free(sEggHatchData);
    SetMainCallback2(CB2_ReturnToField);
}

#define tTimer data[0]

static void Task_EggHatchPlayBGM(u8 taskId)
{
    if (gTasks[taskId].tTimer == 0)
    {
        StopMapMusic();
        PlayRainStoppingSoundEffect();
    }

    if (gTasks[taskId].tTimer == 1)
        PlayBGM(MUS_EVOLUTION_INTRO);

    if (gTasks[taskId].tTimer > 60)
    {
        PlayBGM(MUS_EVOLUTION);
        DestroyTask(taskId);
    }
    gTasks[taskId].tTimer++;
}

#undef tTimer

static void CB2_EggHatch_1(void)
{
    u16 species;
    u8 gender;
    u32 personality;

    switch (sEggHatchData->state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        sEggHatchData->eggSpriteId = CreateSprite(&sSpriteTemplate_Egg, EGG_X, EGG_Y, 5);
        ShowBg(0);
        ShowBg(1);
        sEggHatchData->state++;
        CreateTask(Task_EggHatchPlayBGM, 5);
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            FillWindowPixelBuffer(sEggHatchData->windowId, PIXEL_FILL(0));
            sEggHatchData->delayTimer = 0;
            sEggHatchData->state++;
        }
        break;
    case 2:
        if (++sEggHatchData->delayTimer > 30)
        {
            sEggHatchData->state++;
            gSprites[sEggHatchData->eggSpriteId].callback = SpriteCB_Egg_0;
        }
        break;
    case 3:
        if (gSprites[sEggHatchData->eggSpriteId].callback == SpriteCallbackDummy)
        {
            species = GetMonData3(&gPlayerParty[sEggHatchData->eggPartyId], MON_DATA_SPECIES);
            DoMonFrontSpriteAnimation(&gSprites[sEggHatchData->monSpriteId], species, FALSE, 1);
            sEggHatchData->state++;
        }
        break;
    case 4:
        if (gSprites[sEggHatchData->monSpriteId].callback == SpriteCallbackDummy)
            sEggHatchData->state++;
        break;
    case 5:
        GetBoxMonNick(&gPlayerParty[sEggHatchData->eggPartyId], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gUnknown_85CC874);
        EggHatchPrintMessage(sEggHatchData->windowId, gStringVar4, 0, 3, TEXT_SKIP_DRAW);
        PlayFanfare(MUS_EVOLVED);
        sEggHatchData->state++;
        PutWindowTilemap(sEggHatchData->windowId);
        CopyWindowToVram(sEggHatchData->windowId, COPYWIN_FULL);
        break;
    case 6:
        if (IsFanfareTaskInactive())
            sEggHatchData->state++;
        break;
    case 7:
        if (IsFanfareTaskInactive())
            sEggHatchData->state++;
        break;
    case 8:
        GetBoxMonNick(&gPlayerParty[sEggHatchData->eggPartyId], gStringVar1);
        StringExpandPlaceholders(gStringVar4, gUnknown_85CC888);
        EggHatchPrintMessage(sEggHatchData->windowId, gStringVar4, 0, 2, 1);
        sEggHatchData->state++;
        break;
    case 9:
        if (!IsTextPrinterActive(sEggHatchData->windowId))
        {
            LoadUserWindowBorderGfx(sEggHatchData->windowId, 0x140, BG_PLTT_ID(14));
            CreateYesNoMenuAtPos(&sYesNoWinTemplate, FONT_NORMAL, 2, 2, 0x140, 14, 0);
            sEggHatchData->state++;
        }
        break;
    case 10:
        switch (Menu_ProcessInputNoWrapClearOnChoose())
        {
        case 0:
            GetBoxMonNick(&gPlayerParty[sEggHatchData->eggPartyId], gStringVar3);
            species = GetMonData3(&gPlayerParty[sEggHatchData->eggPartyId], MON_DATA_SPECIES);
            gender = GetMonGender(&gPlayerParty[sEggHatchData->eggPartyId]);
            personality = GetMonData3(&gPlayerParty[sEggHatchData->eggPartyId], MON_DATA_PERSONALITY, NULL);
            DoNamingScreen(NAMING_SCREEN_NICKNAME, gStringVar3, species, gender, personality, EggHatchSetMonNickname);
            break;
        case 1:
        case MENU_B_PRESSED:
            sEggHatchData->state++;
            break;
        }
        break;
    case 11:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sEggHatchData->state++;
        break;
    case 12:
        if (!gPaletteFade.active)
        {
            FreeMonSpritesGfx();
            RemoveWindow(sEggHatchData->windowId);
            UnsetBgTilemapBuffer(0);
            UnsetBgTilemapBuffer(1);
            Free(sEggHatchData);
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    }

    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

#define sTimer      data[0]
#define sSinIdx     data[1]
#define sDelayTimer data[2]

static void SpriteCB_Egg_0(struct Sprite *sprite)
{
    if (++sprite->sTimer > 20)
    {
        sprite->callback = SpriteCB_Egg_1;
        sprite->sTimer = 0;
    }
    else
    {
        sprite->sSinIdx = (sprite->sSinIdx + 20) & 0xFF;
        sprite->x2 = Sin(sprite->sSinIdx, 1);
        if (sprite->sTimer == 15)
        {
            PlaySE(SE_BALL);
            StartSpriteAnim(sprite, EGG_ANIM_CRACKED_1);
            CreateRandomEggShardSprite();
        }
    }
}

static void SpriteCB_Egg_1(struct Sprite *sprite)
{
    if (++sprite->sDelayTimer > 30)
    {
        if (++sprite->sTimer > 20)
        {
            sprite->callback = SpriteCB_Egg_2;
            sprite->sTimer = 0;
            sprite->sDelayTimer = 0;
        }
        else
        {
            sprite->sSinIdx = (sprite->sSinIdx + 20) & 0xFF;
            sprite->x2 = Sin(sprite->sSinIdx, 2);
            if (sprite->sTimer == 15)
            {
                PlaySE(SE_BALL);
                StartSpriteAnim(sprite, EGG_ANIM_CRACKED_2);
            }
        }
    }
}

static void SpriteCB_Egg_2(struct Sprite *sprite)
{
    if (++sprite->sDelayTimer > 30)
    {
        if (++sprite->sTimer > 38)
        {
            u16 UNUSED species;
            sprite->callback = SpriteCB_Egg_3;
            sprite->sTimer = 0;
            species = GetMonData3(&gPlayerParty[sEggHatchData->eggPartyId], MON_DATA_SPECIES);
            gSprites[sEggHatchData->monSpriteId].x2 = 0;
            gSprites[sEggHatchData->monSpriteId].y2 = 0;
        }
        else
        {
            sprite->sSinIdx = (sprite->sSinIdx + 20) & 0xFF;
            sprite->x2 = Sin(sprite->sSinIdx, 2);
            if (sprite->sTimer == 15)
            {
                PlaySE(SE_BALL);
                StartSpriteAnim(sprite, EGG_ANIM_CRACKED_2);
                CreateRandomEggShardSprite();
                CreateRandomEggShardSprite();
            }
            if (sprite->sTimer == 30)
                PlaySE(SE_BALL);
        }
    }
}

static void SpriteCB_Egg_3(struct Sprite *sprite)
{
    if (++sprite->sTimer > 50)
    {
        sprite->callback = SpriteCB_Egg_4;
        sprite->sTimer = 0;
    }
}

static void SpriteCB_Egg_4(struct Sprite *sprite)
{
    s16 i;

    if (sprite->sTimer == 0)
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_WHITEALPHA);

    if ((u32)sprite->sTimer < 4)
    {
        for (i = 0; i < 4; i++)
            CreateRandomEggShardSprite();
    }

    sprite->sTimer++;

    if (!gPaletteFade.active)
    {
        PlaySE(SE_EGG_HATCH);
        sprite->invisible = TRUE;
        sprite->callback = SpriteCB_Egg_5;
        sprite->sTimer = 0;
    }
}

static void SpriteCB_Egg_5(struct Sprite *sprite)
{
    if (sprite->sTimer == 0)
    {
        gSprites[sEggHatchData->monSpriteId].invisible = FALSE;
        StartSpriteAffineAnim(&gSprites[sEggHatchData->monSpriteId], BATTLER_AFFINE_EMERGE);
    }

    if (sprite->sTimer == 8)
        BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_WHITEALPHA);

    if (sprite->sTimer <= 9)
        gSprites[sEggHatchData->monSpriteId].y--;

    if (sprite->sTimer > 40)
        sprite->callback = SpriteCallbackDummy;

    sprite->sTimer++;
}

#undef sTimer
#undef sSinIdx
#undef sDelayTimer

#define sVelocX data[1]
#define sVelocY data[2]
#define sAccelY data[3]
#define sDeltaX data[4]
#define sDeltaY data[5]

static void SpriteCB_EggShard(struct Sprite *sprite)
{
    sprite->sDeltaX += sprite->sVelocX;
    sprite->sDeltaY += sprite->sVelocY;

    sprite->x2 = sprite->sDeltaX / 256;
    sprite->y2 = sprite->sDeltaY / 256;

    sprite->sVelocY += sprite->sAccelY;

    if (sprite->y + sprite->y2 > sprite->y + 20 && sprite->sVelocY > 0)
        DestroySprite(sprite);
}

static void CreateRandomEggShardSprite(void)
{
    u16 spriteAnimIndex;
    s16 velocityX = sEggShardVelocities[sEggHatchData->eggShardVelocityId][0];
    s16 velocityY = sEggShardVelocities[sEggHatchData->eggShardVelocityId][1];

    sEggHatchData->eggShardVelocityId++;
    spriteAnimIndex = Random() % ARRAY_COUNT(sSpriteAnimTable_EggShard);
    CreateEggShardSprite(EGG_X, EGG_Y - 15, velocityX, velocityY, 100, spriteAnimIndex);
}

static void CreateEggShardSprite(u8 x, u8 y, s16 velocityX, s16 velocityY, s16 acceleration, u8 spriteAnimIndex)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_EggShard, x, y, 4);

    gSprites[spriteId].sVelocX = velocityX;
    gSprites[spriteId].sVelocY = velocityY;
    gSprites[spriteId].sAccelY = acceleration;
    StartSpriteAnim(&gSprites[spriteId], spriteAnimIndex);
}

static void EggHatchPrintMessage(u8 windowId, u8 *string, u8 x, u8 y, u8 speed)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(15));
    sEggHatchData->textColor[0] = 0;
    sEggHatchData->textColor[1] = 5;
    sEggHatchData->textColor[2] = 6;
    AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, y, 0, 0, sEggHatchData->textColor, speed, string);
}

u8 GetEggStepsToSubtract(void)
{
    u8 count;
    u8 i;

    for (count = CalculatePlayerPartyCount(), i = 0; i < count; i++)
    {
        if (!GetMonData3(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG))
        {
            u8 ability = GetMonAbility(&gPlayerParty[i]);

            if (ability == ABILITY_MAGMA_ARMOR || ability == ABILITY_FLAME_BODY)
                return 2;
        }
    }
    return 1;
}

u16 CountPartyAliveNonEggMons(void)
{
    u16 aliveNonEggMonsCount = CountStorageNonEggMons();

    aliveNonEggMonsCount += CountPartyAliveNonEggMonsExcept(PARTY_SIZE);
    return aliveNonEggMonsCount;
}

#undef sVelocX
#undef sVelocY
#undef sAccelY
#undef sDeltaX
#undef sDeltaY
