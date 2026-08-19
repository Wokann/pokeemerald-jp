#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "menu.h"
#include "random.h"
#include "palette.h"
#include "palette_util.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "window.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

struct MirageTowerPulseBlend
{
    u8 taskId;
    struct PulseBlend pulseBlend;
};

struct MetatileCoords
{
    u8 x;
    u8 y;
    u16 metatileId;
};

struct BgRegOffsets
{
    u16 bgHOFS;
    u16 bgVOFS;
};

struct FallAnim_Tower
{
    u8 *disintegrateRand;
    u8 disintegrateIdx;
};

struct FallAnim_Fossil
{
    u8 *frameImageTiles;
    struct SpriteFrameImage *frameImage;
    u8 spriteId;
    u16 *disintegrateRand;
    u16 disintegrateIdx;
};

#define TAG_CEILING_CRUMBLE 4000

// JP sMirageTower_Gfx is 0x920 bytes (73 tiles); the tables are in data/data.s
// so their sizes cannot be taken with sizeof.
#define MIRAGE_TOWER_GFX_LENGTH 2336
#define FOSSIL_GFX_LENGTH 0x80
#define FOSSIL_DISINTEGRATE_LENGTH 0x100

static void PlayerDescendMirageTower(u8);
static void DoScreenShake(u8);
static void IncrementCeilingCrumbleFinishedCount(void);
static void WaitCeilingCrumble(u8);
static void FinishCeilingCrumbleTask(u8);
static void CreateCeilingCrumbleSprites(void);
static void SpriteCB_CeilingCrumble(struct Sprite *);
static void DoMirageTowerDisintegration(u8);
static void InitMirageTowerShake(u8);
static void Task_FossilFallAndSink(u8);

// JP data tables (data/data.s)
extern const u8 sMirageTower_Gfx[];
extern const u16 sMirageTowerTilemap[];
extern const u8 sFossil_Gfx[];
extern const u8 sMirageTowerCrumbles_Gfx[];
extern const s16 sCeilingCrumblePositions[][3];
extern const struct SpriteSheet sCeilingCrumbleSpriteSheets[];
extern const struct MetatileCoords sInvisibleMirageTowerMetatiles[];
extern const struct SpriteTemplate sSpriteTemplate_FallingFossil;
extern const struct PulseBlendPaletteSettings gMirageTowerPulseBlendSettings;
extern const struct SpriteTemplate sSpriteTemplate_CeilingCrumbleSmall;
extern const struct SpriteTemplate sSpriteTemplate_CeilingCrumbleLarge;

// JP state variables live at fixed addresses supplied by ld_script_jp.txt.
extern u8 *sMirageTowerGfxBuffer;        // 0x0203CBD0
extern u8 *sMirageTowerTilemapBuffer;    // 0x0203CBD4
extern struct FallAnim_Fossil *sFallingFossil;   // 0x0203CBD8
extern struct FallAnim_Tower *sFallingTower;     // 0x0203CBDC
extern struct BgRegOffsets *sBgShakeOffsets;     // 0x0203CBE0
extern struct MirageTowerPulseBlend *sMirageTowerPulseBlend; // 0x0203CBE4

__attribute__((naked)) void SpriteCB_FallingFossil(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, lr}\n\t"
        "sub sp, #4\n\t"
        "adds r5, r0, #0\n\t"
        "ldr r0, _081BEEFC\n\t"
        "ldr r0, [r0]\n\t"
        "ldrh r0, [r0, #0x10]\n\t"
        "cmp r0, #0xff\n\t"
        "bls _081BEF04\n\t"
        "ldr r0, _081BEF00\n\t"
        "str r0, [r5, #0x1c]\n\t"
        "b _081BEF4C\n\t"
        ".align 2, 0\n\t"
        "_081BEEFC: .4byte sFallingFossil\n\t"
        "_081BEF00: .4byte SpriteCallbackDummy + 1\n\t"
        "_081BEF04:\n\t"
        "ldrh r1, [r5, #0x22]\n\t"
        "movs r2, #0x22\n\t"
        "ldrsh r0, [r5, r2]\n\t"
        "cmp r0, #0x5f\n\t"
        "ble _081BEF48\n\t"
        "movs r4, #0\n\t"
        "_081BEF10:\n\t"
        "ldr r0, _081BEF44\n\t"
        "ldr r3, [r0]\n\t"
        "ldr r0, [r3]\n\t"
        "ldrh r1, [r3, #0x10]\n\t"
        "adds r2, r1, #1\n\t"
        "strh r2, [r3, #0x10]\n\t"
        "lsls r1, r1, #0x10\n\t"
        "ldr r2, [r3, #0xc]\n\t"
        "lsrs r1, r1, #0xf\n\t"
        "adds r1, r1, r2\n\t"
        "ldrh r1, [r1]\n\t"
        "movs r2, #0\n\t"
        "str r2, [sp]\n\t"
        "movs r3, #0x10\n\t"
        "bl UpdateDisintegrationEffect\n\t"
        "adds r0, r4, #1\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r4, r0, #0x18\n\t"
        "cmp r4, #1\n\t"
        "bls _081BEF10\n\t"
        "adds r0, r5, #0\n\t"
        "movs r1, #0\n\t"
        "bl StartSpriteAnim\n\t"
        "b _081BEF4C\n\t"
        ".align 2, 0\n\t"
        "_081BEF44: .4byte sFallingFossil\n\t"
        "_081BEF48:\n\t"
        "adds r0, r1, #1\n\t"
        "strh r0, [r5, #0x22]\n\t"
        "_081BEF4C:\n\t"
        "add sp, #4\n\t"
        "pop {r4, r5}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void UpdateDisintegrationEffect(u8 *dest, u16 counter, u8 bits, u8 size, bool8 mask)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, r7, lr}\n\t"
        "mov r7, sl\n\t"
        "mov r6, sb\n\t"
        "mov r5, r8\n\t"
        "push {r5, r6, r7}\n\t"
        "sub sp, #8\n\t"
        "str r0, [sp]\n\t"
        "mov sl, r1\n\t"
        "adds r6, r2, #0\n\t"
        "mov r8, r3\n\t"
        "ldr r0, [sp, #0x28]\n\t"
        "mov sb, r0\n\t"
        "lsls r1, r1, #0x10\n\t"
        "lsrs r1, r1, #0x10\n\t"
        "mov sl, r1\n\t"
        "lsls r6, r6, #0x18\n\t"
        "lsrs r6, r6, #0x18\n\t"
        "mov r0, r8\n\t"
        "lsls r0, r0, #0x18\n\t"
        "mov r8, r0\n\t"
        "lsrs r7, r0, #0x18\n\t"
        "mov r1, sb\n\t"
        "lsls r1, r1, #0x18\n\t"
        "lsrs r1, r1, #0x18\n\t"
        "mov sb, r1\n\t"
        "mov r0, sl\n\t"
        "adds r1, r7, #0\n\t"
        "bl __divsi3\n\t"
        "adds r5, r0, #0\n\t"
        "lsls r5, r5, #0x18\n\t"
        "lsrs r4, r5, #0x18\n\t"
        "ldr r3, _081BF01C\n\t"
        "strh r4, [r3]\n\t"
        "mov r0, sl\n\t"
        "adds r1, r7, #0\n\t"
        "str r3, [sp, #4]\n\t"
        "bl __modsi3\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r2, r0, #0x18\n\t"
        "ldr r3, [sp, #4]\n\t"
        "strh r2, [r3, #2]\n\t"
        "movs r1, #7\n\t"
        "ands r4, r1\n\t"
        "ands r2, r1\n\t"
        "strh r4, [r3, #4]\n\t"
        "strh r2, [r3, #6]\n\t"
        "lsrs r0, r0, #0x1b\n\t"
        "lsrs r5, r5, #0x1b\n\t"
        "strh r0, [r3, #8]\n\t"
        "strh r5, [r3, #0xa]\n\t"
        "mov r1, r8\n\t"
        "lsrs r1, r1, #0x1b\n\t"
        "lsls r1, r1, #6\n\t"
        "mov r8, r1\n\t"
        "mov r1, r8\n\t"
        "muls r1, r5, r1\n\t"
        "lsls r0, r0, #6\n\t"
        "adds r1, r1, r0\n\t"
        "lsls r1, r1, #0x10\n\t"
        "lsrs r1, r1, #0x10\n\t"
        "strh r1, [r3, #0xc]\n\t"
        "lsls r4, r4, #3\n\t"
        "adds r4, r4, r2\n\t"
        "adds r1, r1, r4\n\t"
        "lsls r4, r1, #0x10\n\t"
        "lsrs r4, r4, #0x11\n\t"
        "strh r1, [r3, #0xe]\n\t"
        "movs r1, #1\n\t"
        "mov r0, sl\n\t"
        "ands r1, r0\n\t"
        "movs r2, #1\n\t"
        "eors r1, r2\n\t"
        "lsls r0, r1, #2\n\t"
        "lsls r6, r0\n\t"
        "eors r1, r2\n\t"
        "lsls r1, r1, #2\n\t"
        "movs r0, #0xf\n\t"
        "lsls r0, r1\n\t"
        "orrs r6, r0\n\t"
        "lsls r6, r6, #0x18\n\t"
        "lsrs r6, r6, #0x18\n\t"
        "mov r1, sb\n\t"
        "lsls r1, r1, #5\n\t"
        "mov sb, r1\n\t"
        "add sb, r4\n\t"
        "ldr r1, [sp]\n\t"
        "add r1, sb\n\t"
        "ldrb r0, [r1]\n\t"
        "ands r6, r0\n\t"
        "strb r6, [r1]\n\t"
        "add sp, #8\n\t"
        "pop {r3, r4, r5}\n\t"
        "mov r8, r3\n\t"
        "mov sb, r4\n\t"
        "mov sl, r5\n\t"
        "pop {r4, r5, r6, r7}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_081BF01C: .4byte gUnknown_30012A0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 IsMirageTowerVisible(void)
{
    if (!(gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ROUTE111) && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ROUTE111)))
        return FALSE;
    return FlagGet(FLAG_MIRAGE_TOWER_VISIBLE);
}

static void UpdateMirageTowerPulseBlend(u8 taskId)
{
    UpdatePulseBlend(&sMirageTowerPulseBlend->pulseBlend);
}

void ClearMirageTowerPulseBlend(void)
{
    sMirageTowerPulseBlend = NULL;
}

void TryStartMirageTowerPulseBlendEffect(void)
{
    if (sMirageTowerPulseBlend)
    {
        sMirageTowerPulseBlend = NULL;
        return;
    }

    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(MAP_ROUTE111)
     || gSaveBlock1Ptr->location.mapNum != MAP_NUM(MAP_ROUTE111)
     || !FlagGet(FLAG_MIRAGE_TOWER_VISIBLE))
        return;

    sMirageTowerPulseBlend = AllocZeroed(sizeof(*sMirageTowerPulseBlend));
    InitPulseBlend(&sMirageTowerPulseBlend->pulseBlend);
    InitPulseBlendPaletteSettings(&sMirageTowerPulseBlend->pulseBlend, &gMirageTowerPulseBlendSettings);
    MarkUsedPulseBlendPalettes(&sMirageTowerPulseBlend->pulseBlend, 0x1, TRUE);
    sMirageTowerPulseBlend->taskId = CreateTask(UpdateMirageTowerPulseBlend, 0xFF);
}

void ClearMirageTowerPulseBlendEffect(void)
{
    if (gSaveBlock1Ptr->location.mapGroup != MAP_GROUP(MAP_ROUTE111)
     || gSaveBlock1Ptr->location.mapNum   != MAP_NUM(MAP_ROUTE111)
     || !FlagGet(FLAG_MIRAGE_TOWER_VISIBLE)
     || sMirageTowerPulseBlend == NULL)
        return;

    if (FuncIsActiveTask(UpdateMirageTowerPulseBlend))
        DestroyTask(sMirageTowerPulseBlend->taskId);

    UnmarkUsedPulseBlendPalettes(&sMirageTowerPulseBlend->pulseBlend, 0x1, TRUE);
    UnloadUsedPulseBlendPalettes(&sMirageTowerPulseBlend->pulseBlend, 0x1, TRUE);
    FREE_AND_SET_NULL(sMirageTowerPulseBlend);
}

void SetMirageTowerVisibility(void)
{
    u16 rand;
    bool8 visible;

    if (VarGet(VAR_MIRAGE_TOWER_STATE))
    {
        // Mirage Tower event has already been completed, hide it
        FlagClear(FLAG_MIRAGE_TOWER_VISIBLE);
        return;
    }

    rand = Random();
    visible = rand & 1;
    if (FlagGet(FLAG_FORCE_MIRAGE_TOWER_VISIBLE) == TRUE)
        visible = TRUE;

    if (visible)
    {
        FlagSet(FLAG_MIRAGE_TOWER_VISIBLE);
        TryStartMirageTowerPulseBlendEffect();
        return;
    }

    FlagClear(FLAG_MIRAGE_TOWER_VISIBLE);
}

void StartPlayerDescendMirageTower(void)
{
    CreateTask(PlayerDescendMirageTower, 8);
}

// As the tower disintegrates, a duplicate object event of the player
// is created at the top of the tower and moved down to show the player falling
static void PlayerDescendMirageTower(u8 taskId)
{
    u8 objectEventId;
    struct ObjectEvent *fallingPlayer;
    struct ObjectEvent *player;

    TryGetObjectEventIdByLocalIdAndMap(LOCALID_ROUTE111_PLAYER_FALLING, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectEventId);
    fallingPlayer = &gObjectEvents[objectEventId];
    gSprites[fallingPlayer->spriteId].y2 += 4;
    player = &gObjectEvents[gPlayerAvatar.objectEventId];
    if ((gSprites[fallingPlayer->spriteId].y + gSprites[fallingPlayer->spriteId].y2) >=
        (gSprites[player->spriteId].y + gSprites[player->spriteId].y2))
    {
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

#define tXShakeOffset data[0]
#define tTimer        data[1]
#define tNumShakes    data[2]
#define tShakeDelay   data[3]
#define tYShakeOffset data[4]

static void StartScreenShake(u8 yShakeOffset, u8 xShakeOffset, u8 numShakes, u8 shakeDelay)
{
    u8 taskId = CreateTask(DoScreenShake, 9);
    gTasks[taskId].tXShakeOffset = xShakeOffset;
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].tNumShakes = numShakes;
    gTasks[taskId].tShakeDelay = shakeDelay;
    gTasks[taskId].tYShakeOffset = yShakeOffset;
    SetCameraPanningCallback(NULL);
    PlaySE(SE_M_STRENGTH);
}

static void DoScreenShake(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    tTimer++;
    if (tTimer % tShakeDelay == 0)
    {
        tTimer = 0;
        tNumShakes--;
        tXShakeOffset = -tXShakeOffset;
        tYShakeOffset = -tYShakeOffset;
        SetCameraPanning(tXShakeOffset, tYShakeOffset);
        if (tNumShakes == 0)
        {
            IncrementCeilingCrumbleFinishedCount();
            DestroyTask(taskId);
            InstallCameraPanAheadCallback();
        }
    }
}

#undef tXShakeOffset
#undef tTimer
#undef tNumShakes
#undef tShakeDelay
#undef tYShakeOffset

static void IncrementCeilingCrumbleFinishedCount(void)
{
    u8 taskId = FindTaskIdByFunc(WaitCeilingCrumble);
    if (taskId != TASK_NONE)
        gTasks[taskId].data[0]++;
}

void DoMirageTowerCeilingCrumble(void)
{
    LoadSpriteSheets(sCeilingCrumbleSpriteSheets);
    CreateCeilingCrumbleSprites();
    CreateTask(WaitCeilingCrumble, 8);
    StartScreenShake(2, 1, 16, 3);
}

static void WaitCeilingCrumble(u8 taskId)
{
    u16 *data = (u16*)gTasks[taskId].data;
    data[1]++;
    // Either wait 1000 frames, or until all 16 crumble sprites and the one screen-shake task are completed.
    if (data[1] == 1000 || data[0] == 17)
        gTasks[taskId].func = FinishCeilingCrumbleTask;
}

static void FinishCeilingCrumbleTask(u8 taskId)
{
    FreeSpriteTilesByTag(TAG_CEILING_CRUMBLE);
    DestroyTask(taskId);
    ScriptContext_Enable();
}

#define sIndex   data[0]
#define sYOffset data[1]

static void CreateCeilingCrumbleSprites(void)
{
    u8 i;
    u8 spriteId;

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_CeilingCrumbleLarge, sCeilingCrumblePositions[i][0] + 120, sCeilingCrumblePositions[i][1], 8);
        gSprites[spriteId].oam.priority = 0;
        // These sprites use color index 11 from the player's sprite palette. This probably wasn't intentional.
        // The palettes for Brendan and May have different shades of green at this index, so the color of these sprites changes
        // depending on the player's gender (and neither shade of green particularly fits a crumbling yellow/brown ceiling).
        gSprites[spriteId].oam.paletteNum = PALSLOT_PLAYER;
        gSprites[spriteId].sIndex = i;
    }
    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_CeilingCrumbleSmall, sCeilingCrumblePositions[i][0] + 115, sCeilingCrumblePositions[i][1] - 3, 8);
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].oam.paletteNum = PALSLOT_PLAYER;
        gSprites[spriteId].sIndex = i;
    }
}

static void SpriteCB_CeilingCrumble(struct Sprite *sprite)
{
    sprite->sYOffset += 2;
    sprite->y2 = sprite->sYOffset / 2;
    if ((sprite->y + sprite->y2) >  sCeilingCrumblePositions[sprite->sIndex][2])
    {
        DestroySprite(sprite);
        IncrementCeilingCrumbleFinishedCount();
    }
}

#undef sIndex
#undef sYOffset

static void SetInvisibleMirageTowerMetatiles(void)
{
    u8 i;
    for (i = 0; i < 18; i++)
        MapGridSetMetatileIdAt(sInvisibleMirageTowerMetatiles[i].x + MAP_OFFSET,
                               sInvisibleMirageTowerMetatiles[i].y + MAP_OFFSET,
                               sInvisibleMirageTowerMetatiles[i].metatileId);
    DrawWholeMapView();
}

void StartMirageTowerDisintegration(void)
{
    CreateTask(DoMirageTowerDisintegration, 9);
}

void StartMirageTowerShake(void)
{
    // JP swaps the two starts vs US: this function creates the fossil
    // fall-and-sink task and StartMirageTowerFossilFallAndSink creates the
    // shake task.
    CreateTask(Task_FossilFallAndSink, 9);
}

void StartMirageTowerFossilFallAndSink(void)
{
    CreateTask(InitMirageTowerShake, 9);
}

static void SetBgShakeOffsets(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, sBgShakeOffsets->bgHOFS);
    SetGpuReg(REG_OFFSET_BG0VOFS, sBgShakeOffsets->bgVOFS);
}

static void UpdateBgShake(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        sBgShakeOffsets->bgHOFS = -sBgShakeOffsets->bgHOFS;
        gTasks[taskId].data[0] = 2;
        SetBgShakeOffsets();
    }
    else
    {
        gTasks[taskId].data[0]--;
    }
}

#define tState data[0]

static void InitMirageTowerShake(u8 taskId)
{
    u8 zero;

    switch (gTasks[taskId].tState)
    {
    case 0:
        FreeAllWindowBuffers();
        SetBgAttribute(0, BG_ATTR_PRIORITY, 2);
        gTasks[taskId].tState++;
        break;
    case 1:
        sMirageTowerGfxBuffer = (u8 *)AllocZeroed(MIRAGE_TOWER_GFX_LENGTH);
        sMirageTowerTilemapBuffer = (u8 *)AllocZeroed(BG_SCREEN_SIZE);
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        gTasks[taskId].tState++;
        break;
    case 2:
        CpuSet(sMirageTower_Gfx, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH / 2);
        LoadBgTiles(0, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH, 0);
        gTasks[taskId].tState++;
        break;
    case 3:
        SetBgTilemapBuffer(0, sMirageTowerTilemapBuffer);
        CopyToBgTilemapBufferRect_ChangePalette(0, sMirageTowerTilemap, 12, 29, 6, 12, 17);
        CopyBgTilemapBufferToVram(0);
        gTasks[taskId].tState++;
        break;
    case 4:
        ShowBg(0);
        gTasks[taskId].tState++;
        break;
    case 5:
        SetInvisibleMirageTowerMetatiles();
        gTasks[taskId].tState++;
        break;
    case 6:
        sBgShakeOffsets = Alloc(sizeof(*sBgShakeOffsets));
        zero = 0;
        sBgShakeOffsets->bgHOFS = 2;
        sBgShakeOffsets->bgVOFS = zero;
        CreateTask(UpdateBgShake, 10);
        DestroyTask(taskId);
        ScriptContext_Enable();
        break;
    }
}

#define OUTER_BUFFER_LENGTH 0x60
#define INNER_BUFFER_LENGTH 0x30
static void DoMirageTowerDisintegration(u8 taskId)
{
    u8 bgShakeTaskId, j;
    u16 i;
    u8 index;

    switch (gTasks[taskId].tState)
    {
    case 1:
        sFallingTower = AllocZeroed(OUTER_BUFFER_LENGTH * sizeof(struct FallAnim_Tower));
        break;
    case 3:
        if (gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
        {
            if (gTasks[taskId].data[1] > 1)
            {
                // Initialize disintegration pattern
                index = gTasks[taskId].data[3];
                sFallingTower[index].disintegrateRand = Alloc(INNER_BUFFER_LENGTH);
                for (i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                    sFallingTower[index].disintegrateRand[i] = i;

                // Randomize disintegration pattern
                for (i = 0; i <= (INNER_BUFFER_LENGTH - 1); i++)
                {
                    u16 rand1, rand2, temp;
                    rand1 = Random() % INNER_BUFFER_LENGTH;
                    rand2 = Random() % INNER_BUFFER_LENGTH;
                    SWAP(sFallingTower[index].disintegrateRand[rand2], sFallingTower[index].disintegrateRand[rand1], temp);
                }
                if (gTasks[taskId].data[3] <= (OUTER_BUFFER_LENGTH - 1))
                    gTasks[taskId].data[3]++;
                gTasks[taskId].data[1] = 0;
            }
            gTasks[taskId].data[1]++;
        }
        index = gTasks[taskId].data[3];
        for (i = (u8)(gTasks[taskId].data[2]); i < index; i++)
        {
            for (j = 0; j < 1; j++)
            {
                UpdateDisintegrationEffect(sMirageTowerGfxBuffer,
                            (OUTER_BUFFER_LENGTH - 1 - i) * INNER_BUFFER_LENGTH + sFallingTower[i].disintegrateRand[sFallingTower[i].disintegrateIdx++],
                            0, INNER_BUFFER_LENGTH, 1);
            }
            if (sFallingTower[i].disintegrateIdx > (INNER_BUFFER_LENGTH - 1))
            {
                FREE_AND_SET_NULL(sFallingTower[i].disintegrateRand);
                gTasks[taskId].data[2]++;
                if ((i % 2) == 1)
                    sBgShakeOffsets->bgVOFS--;
            }
        }
        LoadBgTiles(0, sMirageTowerGfxBuffer, MIRAGE_TOWER_GFX_LENGTH, 0);
        if (sFallingTower[OUTER_BUFFER_LENGTH - 1].disintegrateIdx > INNER_BUFFER_LENGTH - 1)
            break;
        return;
    case 4:
        UnsetBgTilemapBuffer(0);
        bgShakeTaskId = FindTaskIdByFunc(UpdateBgShake);
        if (bgShakeTaskId != TASK_NONE)
            DestroyTask(bgShakeTaskId);
        sBgShakeOffsets->bgVOFS = sBgShakeOffsets->bgHOFS = 0;
        SetBgShakeOffsets();
        break;
    case 5:
        FREE_AND_SET_NULL(sBgShakeOffsets);
        FREE_AND_SET_NULL(sFallingTower);
        FREE_AND_SET_NULL(sMirageTowerGfxBuffer);
        FREE_AND_SET_NULL(sMirageTowerTilemapBuffer);
        break;
    case 6:
        SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2));
        SetGpuRegBits(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0));
        SetBgAttribute(0, BG_ATTR_PRIORITY, 0);
        InitStandardTextBoxWindows();
        break;
    case 7:
        ShowBg(0);
        break;
    case 8:
        DestroyTask(taskId);
        ScriptContext_Enable();
        break;
    }
    gTasks[taskId].tState++;
}

static void Task_FossilFallAndSink(u8 taskId)
{
    u16 i;
    u8 *buffer;

    switch (gTasks[taskId].tState)
    {
    case 1:
        sFallingFossil = AllocZeroed(sizeof(*sFallingFossil));
        sFallingFossil->frameImageTiles = AllocZeroed(FOSSIL_GFX_LENGTH);
        sFallingFossil->frameImage = AllocZeroed(sizeof(*sFallingFossil->frameImage));
        sFallingFossil->disintegrateRand = AllocZeroed(FOSSIL_DISINTEGRATE_LENGTH * sizeof(u16));
        sFallingFossil->disintegrateIdx = 0;
        break;
    case 2:
        buffer = sFallingFossil->frameImageTiles;
        for (i = 0; i < FOSSIL_GFX_LENGTH; i++, buffer++)
            *buffer = sFossil_Gfx[i];
        break;
    case 3:
        sFallingFossil->frameImage->data = sFallingFossil->frameImageTiles;
        sFallingFossil->frameImage->size = FOSSIL_GFX_LENGTH;
        break;
    case 4:
        {
            struct SpriteTemplate fossilTemplate = sSpriteTemplate_FallingFossil;
            fossilTemplate.images = sFallingFossil->frameImage;
            sFallingFossil->spriteId = CreateSprite(&fossilTemplate, 128, -16, 1);
            gSprites[sFallingFossil->spriteId].centerToCornerVecX = 0;
            gSprites[sFallingFossil->spriteId].data[0] = gSprites[sFallingFossil->spriteId].x;
            gSprites[sFallingFossil->spriteId].data[1] = 1;
        }
    case 5:
        // Initialize disintegration pattern
        for (i = 0; i < FOSSIL_DISINTEGRATE_LENGTH; i++)
            sFallingFossil->disintegrateRand[i] = i;
        break;
    case 6:
        // Randomize disintegration pattern
        for (i = 0; i < FOSSIL_DISINTEGRATE_LENGTH * sizeof(u16); i++)
        {
            u16 rand1, rand2, temp;
            rand1 = Random() % FOSSIL_DISINTEGRATE_LENGTH;
            rand2 = Random() % FOSSIL_DISINTEGRATE_LENGTH;
            SWAP(sFallingFossil->disintegrateRand[rand2], sFallingFossil->disintegrateRand[rand1], temp);
        }
        gSprites[sFallingFossil->spriteId].callback = SpriteCB_FallingFossil;
        break;
    case 7:
        // Wait for fossil to finish falling / disintegrating
        if (gSprites[sFallingFossil->spriteId].callback != SpriteCallbackDummy)
            return;
        DestroySprite(&gSprites[sFallingFossil->spriteId]);
        FREE_AND_SET_NULL(sFallingFossil->disintegrateRand);
        FREE_AND_SET_NULL(sFallingFossil->frameImage);
        FREE_AND_SET_NULL(sFallingFossil->frameImageTiles);
        FREE_AND_SET_NULL(sFallingFossil);
        break;
    case 8:
        ScriptContext_Enable();
        break;
    }
    gTasks[taskId].tState++;
}
