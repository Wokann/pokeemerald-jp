#include "global.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "metatile_behavior.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"
#include "constants/field_effects.h"
#include "constants/songs.h"

#define OBJ_EVENT_PAL_TAG_NONE 0x11FF // duplicate of define in event_object_movement.c

static void UpdateObjectReflectionSprite(struct Sprite *);
static void LoadObjectReflectionPalette(struct ObjectEvent *objectEvent, struct Sprite *sprite);
static void LoadObjectHighBridgeReflectionPalette(struct ObjectEvent *, u8);
static void LoadObjectRegularReflectionPalette(struct ObjectEvent *, u8);
void UpdateGrassFieldEffectSubpriority(struct Sprite *, u8, u8);
static void FadeFootprintsTireTracks_Step0(struct Sprite *);
static void FadeFootprintsTireTracks_Step1(struct Sprite *);
static void UpdateFeetInFlowingWaterFieldEffect(struct Sprite *);

static void SynchronizeSurfAnim(struct ObjectEvent *, struct Sprite *);
static void SynchronizeSurfPosition(struct ObjectEvent *, struct Sprite *);
static void UpdateBobbingEffect(struct ObjectEvent *, struct Sprite *, struct Sprite *);
static void SpriteCB_UnderwaterSurfBlob(struct Sprite *);
static u32 ShowDisguiseFieldEffect(u8, u8, u8);

// Data used by all the field effects that share UpdateJumpImpactEffect
#define sJumpElevation  data[0]
#define sJumpFldEff     data[1]

// Data used by all the field effects that share WaitFieldEffectSpriteAnim
#define sWaitFldEff  data[0]

// Sprite data for FLDEFF_SURF_BLOB
#define sBitfield     data[0]
#define sPlayerOffset data[1]
#define sPlayerObjId  data[2]
#define sVelocity     data[3]
#define sTimer        data[4]
#define sIntervalIdx  data[5]
#define sPrevX        data[6]
#define sPrevY        data[7]

u8 GetSurfBlob_BobState(struct Sprite *);
u8 GetSurfBlob_DontSyncAnim(struct Sprite *);
u8 GetSurfBlob_HasPlayerOffset(struct Sprite *);
void UpdateSurfBlobFieldEffect(struct Sprite *sprite)
{
    struct ObjectEvent *playerObj = &gObjectEvents[sprite->sPlayerObjId];
    struct Sprite *playerSprite = &gSprites[playerObj->spriteId];
    SynchronizeSurfAnim(playerObj, sprite);
    SynchronizeSurfPosition(playerObj, sprite);
    UpdateBobbingEffect(playerObj, playerSprite, sprite);
    sprite->oam.priority = playerSprite->oam.priority;
}

static void SynchronizeSurfAnim(struct ObjectEvent *playerObj, struct Sprite *sprite)
{
    // Indexes into sAnimTable_SurfBlob
    u8 surfBlobDirectionAnims[9];
    // JP ROM data at 0x085ACA68
    extern const u8 sSurfBlobDirectionAnims[9];
    memcpy(surfBlobDirectionAnims, sSurfBlobDirectionAnims, sizeof(surfBlobDirectionAnims));

    if (!GetSurfBlob_DontSyncAnim(sprite))
        StartSpriteAnimIfDifferent(sprite, surfBlobDirectionAnims[playerObj->movementDirection]);
}

void SynchronizeSurfPosition(struct ObjectEvent *playerObj, struct Sprite *sprite)
{
    u8 i;
    s16 x = playerObj->currentCoords.x;
    s16 y = playerObj->currentCoords.y;
    s32 spriteY = sprite->y2;

    if (spriteY == 0 && (x != sprite->sPrevX || y != sprite->sPrevY))
    {
        // Player is moving while surfing, update position.
        sprite->sIntervalIdx = 0;
        sprite->sPrevX = x;
        sprite->sPrevY = y;
        for (i = DIR_SOUTH; i <= DIR_EAST; i++, x = sprite->sPrevX, y = sprite->sPrevY)
        {
            MoveCoords(i, &x, &y);
            if (MapGridGetElevationAt(x, y) == ELEVATION_DEFAULT)
            {
                // While dismounting the surf blob bobs at a slower rate
                sprite->sIntervalIdx++;
                break;
            }
        }
    }
}

static void UpdateBobbingEffect(struct ObjectEvent *playerObj, struct Sprite *playerSprite, struct Sprite *sprite)
{
    // The frame interval at which to update the blob's y movement.
    // Normally every 4th frame, but every 8th frame while dismounting.
    u16 intervals[2];
    u8 bobState;
    // JP ROM data at 0x085ACA72
    extern const u16 sBobbingIntervals[2];
    memcpy(intervals, sBobbingIntervals, sizeof(intervals));

    bobState = GetSurfBlob_BobState(sprite);
    if (bobState != BOB_NONE)
    {
        // Update vertical position of surf blob
        if (((u16)(++sprite->sTimer) & intervals[sprite->sIntervalIdx]) == 0)
            sprite->y2 += sprite->sVelocity;

        // Reverse bob direction
        if ((sprite->sTimer & 15) == 0)
            sprite->sVelocity = -sprite->sVelocity;

        if (bobState != BOB_JUST_MON)
        {
            // Update vertical position of player
            if (!GetSurfBlob_HasPlayerOffset(sprite))
                playerSprite->y2 = sprite->y2;
            else
                playerSprite->y2 = sprite->sPlayerOffset + sprite->y2;
            sprite->x = playerSprite->x;
            sprite->y = playerSprite->y + 8;
        }
    }
}

#undef sBitfield
#undef sPlayerOffset
#undef sPlayerObjId
#undef sVelocity
#undef sTimer
#undef sIntervalIdx
#undef sPrevX
#undef sPrevY

#define sSpriteId data[0]
#define sBobY     data[1]
#define sTimer    data[2]

u8 StartUnderwaterSurfBlobBobbing(u8 blobSpriteId)
{
    // Create a dummy sprite with its own callback
    // that tracks the actual surf blob sprite and
    // makes it bob up and down underwater
    u8 spriteId = CreateSpriteAtEnd(&gDummySpriteTemplate, 0, 0, -1);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->callback = SpriteCB_UnderwaterSurfBlob;
    sprite->invisible = TRUE;
    sprite->sSpriteId = blobSpriteId;
    sprite->sBobY = 1;
    return spriteId;
}

static void SpriteCB_UnderwaterSurfBlob(struct Sprite *sprite)
{
    struct Sprite *blobSprite = &gSprites[sprite->sSpriteId];

    // Update vertical position of surf blob
    if (((sprite->sTimer++) & 3) == 0)
        blobSprite->y2 += sprite->sBobY;
    // Reverse direction
    if ((sprite->sTimer & 15) == 0)
        sprite->sBobY = -sprite->sBobY;
}

#undef sSpriteId
#undef sBobY
#undef sTimer

u32 FldEff_Dust(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 12);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_GROUND_IMPACT_DUST], gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sJumpElevation = gFieldEffectArguments[2];
        sprite->sJumpFldEff = FLDEFF_DUST;
    }
    return 0;
}

// Sprite data for FLDEFF_SAND_PILE
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sPrevX    data[3]
#define sPrevY    data[4]

u32 FldEff_SandPile(void)
{
    u8 objectEventId = GetObjectEventIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SAND_PILE], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[objectEvent->spriteId].oam.priority;
        sprite->sLocalId = gFieldEffectArguments[0];
        sprite->sMapNum = gFieldEffectArguments[1];
        sprite->sMapGroup = gFieldEffectArguments[2];
        sprite->sPrevX = gSprites[objectEvent->spriteId].x;
        sprite->sPrevY = gSprites[objectEvent->spriteId].y;
        sprite->y2 = (graphicsInfo->height >> 1) - 2;
        SeekSpriteAnim(sprite, 2);
    }
    return 0;
}

void UpdateSandPileFieldEffect(struct Sprite *sprite)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId) || !gObjectEvents[objectEventId].inSandPile)
    {
        FieldEffectStop(sprite, FLDEFF_SAND_PILE);
    }
    else
    {
        s16 parentY = gSprites[gObjectEvents[objectEventId].spriteId].y;
        s16 parentX = gSprites[gObjectEvents[objectEventId].spriteId].x;
        if (parentX != sprite->sPrevX || parentY != sprite->sPrevY)
        {
            sprite->sPrevX = parentX;
            sprite->sPrevY = parentY;
            if (sprite->animEnded)
                StartSpriteAnim(sprite, 0);
        }
        sprite->x = parentX;
        sprite->y = parentY;
        sprite->subpriority = gSprites[gObjectEvents[objectEventId].spriteId].subpriority;
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sPrevX
#undef sPrevY

u32 FldEff_Bubbles(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 0);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_BUBBLES], gFieldEffectArguments[0], gFieldEffectArguments[1], 82);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = 1;
    }
    return 0;
}

#define sY data[0]

void UpdateBubblesFieldEffect(struct Sprite *sprite)
{
    // Move up 1 every other frame.
    sprite->sY += ((1 << 8) / 2);
    sprite->sY &= (1 << 8);
    sprite->y -= sprite->sY >> 8;
    UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    if (sprite->invisible || sprite->animEnded)
        FieldEffectStop(sprite, FLDEFF_BUBBLES);
}

#undef sY

u32 FldEff_BerryTreeGrowthSparkle(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 4);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPARKLE], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->oam.paletteNum = 5;
        sprite->sWaitFldEff = FLDEFF_BERRY_TREE_GROWTH_SPARKLE;
    }
    return 0;
}

// Sprite data for FLDEFF_TREE_DISGUISE / FLDEFF_MOUNTAIN_DISGUISE / FLDEFF_SAND_DISGUISE
#define sState      data[0]
#define sFldEff     data[1]
#define sLocalId    data[2]
#define sMapNum     data[3]
#define sMapGroup   data[4]
#define sReadyToEnd data[7]

u32 ShowTreeDisguiseFieldEffect(void)
{
    return ShowDisguiseFieldEffect(FLDEFF_TREE_DISGUISE, FLDEFFOBJ_TREE_DISGUISE, 4);
}

u32 ShowMountainDisguiseFieldEffect(void)
{
    return ShowDisguiseFieldEffect(FLDEFF_MOUNTAIN_DISGUISE, FLDEFFOBJ_MOUNTAIN_DISGUISE, 3);
}

u32 ShowSandDisguiseFieldEffect(void)
{
    return ShowDisguiseFieldEffect(FLDEFF_SAND_DISGUISE, FLDEFFOBJ_SAND_DISGUISE, 2);
}

static u32 ShowDisguiseFieldEffect(u8 fldEff, u8 fldEffObj, u8 paletteNum)
{
    u8 spriteId;

    if (TryGetObjectEventIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2], &spriteId))
    {
        FieldEffectActiveListRemove(fldEff);
        return MAX_SPRITES;
    }
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[fldEffObj], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled ++;
        sprite->oam.paletteNum = paletteNum;
        sprite->sFldEff = fldEff;
        sprite->sLocalId = gFieldEffectArguments[0];
        sprite->sMapNum = gFieldEffectArguments[1];
        sprite->sMapGroup = gFieldEffectArguments[2];
    }
    return spriteId;
}

void UpdateDisguiseFieldEffect(struct Sprite *sprite)
{
    u8 objectEventId;
    const struct ObjectEventGraphicsInfo *graphicsInfo;
    struct Sprite *linkedSprite;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId))
        FieldEffectStop(sprite, sprite->sFldEff);

    graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[objectEventId].graphicsId);
    linkedSprite = &gSprites[gObjectEvents[objectEventId].spriteId];
    sprite->invisible = linkedSprite->invisible;
    sprite->x = linkedSprite->x;
    sprite->y = (graphicsInfo->height >> 1) + linkedSprite->y - 16;
    sprite->subpriority = linkedSprite->subpriority - 1;

    if (sprite->sState == 1)
    {
        sprite->sState++;
        StartSpriteAnim(sprite, 1);
    }

    if (sprite->sState == 2 && sprite->animEnded)
        sprite->sReadyToEnd = TRUE;

    if (sprite->sState == 3)
        FieldEffectStop(sprite, sprite->sFldEff);
}

void StartRevealDisguise(struct ObjectEvent *objectEvent)
{
    if (objectEvent->directionSequenceIndex == 1)
        gSprites[objectEvent->fieldEffectSpriteId].sState++;
}

bool8 UpdateRevealDisguise(struct ObjectEvent *objectEvent)
{
    struct Sprite *sprite;

    if (objectEvent->directionSequenceIndex == 2)
        return TRUE;

    if (objectEvent->directionSequenceIndex == 0)
        return TRUE;

    sprite = &gSprites[objectEvent->fieldEffectSpriteId];
    if (sprite->sReadyToEnd)
    {
        objectEvent->directionSequenceIndex = 2;
        sprite->sState++;
        return TRUE;
    }
    return FALSE;
}

#undef sState
#undef sFldEff
#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sReadyToEnd

// Sprite data for FLDEFF_SPARKLE
#define sFinished data[0]
#define sEndTimer data[1]

u32 FldEff_Sparkle(void)
{
    u8 spriteId;

    gFieldEffectArguments[0] += MAP_OFFSET;
    gFieldEffectArguments[1] += MAP_OFFSET;
    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SMALL_SPARKLE], gFieldEffectArguments[0], gFieldEffectArguments[1], 82);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.priority = gFieldEffectArguments[2];
        gSprites[spriteId].coordOffsetEnabled = TRUE;
    }
    return 0;
}

void UpdateSparkleFieldEffect(struct Sprite *sprite)
{
    if (!sprite->sFinished)
    {
        if (sprite->animEnded)
        {
            sprite->invisible = TRUE;
            sprite->sFinished++;
        }
    }

    if (sprite->sFinished && ++sprite->sEndTimer > 34)
        FieldEffectStop(sprite, FLDEFF_SPARKLE);
}

#undef sFinished
#undef sEndTimer

#define sTimer       data[0]
#define sMoveTimer   data[1]
#define sState       data[2]
#define sVelocity    data[3]
#define sStartY      data[4]
#define sCounter     data[5]
#define sAnimCounter data[6]
#define sAnimState   data[7]

// Same as InitSpriteForFigure8Anim
static void InitRayquazaForFigure8Anim(struct Sprite *sprite)
{
    sprite->sAnimCounter = 0;
    sprite->sAnimState = 0;
}

// Only different from AnimateSpriteInFigure8 by the addition of SetGpuReg to move the spotlight
static bool8 AnimateRayquazaInFigure8(struct Sprite *sprite)
{
    bool8 finished = FALSE;

    switch (sprite->sAnimState)
    {
    case 0:
        sprite->x2 += GetFigure8XOffset(sprite->sAnimCounter);
        sprite->y2 += GetFigure8YOffset(sprite->sAnimCounter);
        break;
    case 1:
        sprite->x2 -= GetFigure8XOffset((FIGURE_8_LENGTH - 1) - sprite->sAnimCounter);
        sprite->y2 += GetFigure8YOffset((FIGURE_8_LENGTH - 1) - sprite->sAnimCounter);
        break;
    case 2:
        sprite->x2 -= GetFigure8XOffset(sprite->sAnimCounter);
        sprite->y2 += GetFigure8YOffset(sprite->sAnimCounter);
        break;
    case 3:
        sprite->x2 += GetFigure8XOffset((FIGURE_8_LENGTH - 1) - sprite->sAnimCounter);
        sprite->y2 += GetFigure8YOffset((FIGURE_8_LENGTH - 1) - sprite->sAnimCounter);
        break;
    }

    // Update spotlight to sweep left and right with Rayquaza
    SetGpuReg(REG_OFFSET_BG0HOFS, -sprite->x2);

    if (++sprite->sAnimCounter == FIGURE_8_LENGTH)
    {
        sprite->sAnimCounter = 0;
        sprite->sAnimState++;
    }
    if (sprite->sAnimState == 4)
    {
        sprite->y2 = 0;
        sprite->x2 = 0;
        finished = TRUE;
    }

    return finished;
}

void UpdateRayquazaSpotlightEffect(struct Sprite *sprite)
{
    u8 i, j;

    switch (sprite->sState)
    {
        case 0:
            SetGpuReg(REG_OFFSET_BG0VOFS, DISPLAY_WIDTH / 2 - (sprite->sTimer / 3));
            if (sprite->sTimer == 96)
            {
                for (i = 0; i < 3; i++)
                {
                    for (j = 12; j < 18; j++)
                    {
                        ((u16 *)(BG_SCREEN_ADDR(31)))[i * 32 + j] = 0xBFF4 + i * 6 + j + 1;
                    }
                }
            }
            if (sprite->sTimer > 311)
            {
                sprite->sState = 1;
                sprite->sTimer = 0;
            }
            break;
        case 1:
            sprite->y = (gSineTable[sprite->sTimer / 3] >> 2) + sprite->sStartY;
            if (sprite->sTimer == 189)
            {
                sprite->sState = 2;
                sprite->sCounter = 0;
                sprite->sTimer = 0;
            }
            break;
        case 2:
            if (sprite->sTimer == 60)
            {
                sprite->sCounter++;
                sprite->sTimer = 0;
            }
            if (sprite->sCounter == 7)
            {
                sprite->sCounter = 0;
                sprite->sState = 3;
            }
            break;
        case 3:
            if (sprite->y2 == 0)
            {
                sprite->sTimer = 0;
                sprite->sState++;
            }
            if (sprite->sTimer == 5)
            {
                sprite->sTimer = 0;
                if (sprite->y2 > 0)
                    sprite->y2--;
                else
                    sprite->y2++;
            }
            break;
        case 4:
            if (sprite->sTimer == 60)
            {
                sprite->sState = 5;
                sprite->sTimer = 0;
                sprite->sCounter = 0;
            }
            break;
        case 5:
            InitRayquazaForFigure8Anim(sprite);
            sprite->sState = 6;
            sprite->sTimer = 0;
            break;
        case 6:
            if (AnimateRayquazaInFigure8(sprite))
            {
                sprite->sTimer = 0;
                if (++sprite->sCounter <= 2)
                {
                    InitRayquazaForFigure8Anim(sprite);
                }
                else
                {
                    sprite->sCounter = 0;
                    sprite->sState = 7;
                }
            }
            break;
        case 7:
            if (sprite->sTimer == 30)
            {
                sprite->sState = 8;
                sprite->sTimer = 0;
            }
            break;
        case 8:
            for (i = 0; i < 15; i++)
            {
                for (j = 12; j < 18; j++)
                {
                    ((u16 *)(BG_SCREEN_ADDR(31)))[i * 32 + j] = 0;
                }
            }
            SetGpuReg(REG_OFFSET_BG0VOFS, 0);
            FieldEffectStop(sprite, FLDEFF_RAYQUAZA_SPOTLIGHT);
            break;
    }

    if (sprite->sState == 1)
    {
        // Update movement
        if ((sprite->sMoveTimer & 7) == 0)
            sprite->y2 += sprite->sVelocity;
        // Reverse direction
        if ((sprite->sMoveTimer & 15) == 0)
            sprite->sVelocity = -sprite->sVelocity;
        sprite->sMoveTimer++;
    }

    sprite->sTimer++;
}

#undef sTimer
#undef sMoveTimer
#undef sState
#undef sStartY
#undef sVelocity
#undef sCounter
#undef sAnimCounter
#undef sAnimState

void UpdateJumpImpactEffect(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        FieldEffectStop(sprite, sprite->sJumpFldEff);
    }
    else
    {
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
        SetObjectSubpriorityByElevation(sprite->sJumpElevation, sprite, 0);
    }
}

void WaitFieldEffectSpriteAnim(struct Sprite *sprite)
{
    if (sprite->animEnded)
        FieldEffectStop(sprite, sprite->sWaitFldEff);
    else
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
}

void UpdateGrassFieldEffectSubpriority(struct Sprite *sprite, u8 elevation, u8 subpriority)
{
    u8 i;
    s16 var, xhi, lyhi, yhi, ylo;

    SetObjectSubpriorityByElevation(elevation, sprite, subpriority);
    for (i = 0; i < OBJECT_EVENTS_COUNT; i ++)
    {
        struct ObjectEvent *objectEvent = &gObjectEvents[i];
        if (objectEvent->active)
        {
            const struct ObjectEventGraphicsInfo UNUSED *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
            struct Sprite *linkedSprite = &gSprites[objectEvent->spriteId];

            xhi = sprite->x + sprite->centerToCornerVecX;
            var = sprite->x - sprite->centerToCornerVecX;
            if (xhi < linkedSprite->x && var > linkedSprite->x)
            {
                lyhi = linkedSprite->y + linkedSprite->centerToCornerVecY;
                var = linkedSprite->y;
                ylo = sprite->y - sprite->centerToCornerVecY;
                yhi = ylo + linkedSprite->centerToCornerVecY;
                if ((lyhi < yhi || lyhi < ylo) && var > yhi && sprite->subpriority <= linkedSprite->subpriority)
                {
                    sprite->subpriority = linkedSprite->subpriority + 2;
                    break;
                }
            }
        }
    }
}

// JP ROM data (see ld_script_jp.txt)
extern const s8 sFigure8XOffsets[FIGURE_8_LENGTH];
extern const s8 sFigure8YOffsets[FIGURE_8_LENGTH];
