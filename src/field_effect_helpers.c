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
static void UpdateAshFieldEffect_Wait(struct Sprite *);
static void UpdateAshFieldEffect_Show(struct Sprite *);
static void UpdateAshFieldEffect_End(struct Sprite *);

// Data used by all the field effects that share UpdateJumpImpactEffect
#define sJumpElevation  data[0]
#define sJumpFldEff     data[1]

// Data used by all the field effects that share WaitFieldEffectSpriteAnim
#define sWaitFldEff  data[0]

#define sReflectionObjEventId       data[0]
#define sReflectionObjEventLocalId  data[1]
#define sReflectionVerticalOffset   data[2]
#define sIsStillReflection          data[7]

void SetUpReflection(struct ObjectEvent *objectEvent, struct Sprite *sprite, bool8 stillReflection)
{
    struct Sprite *reflectionSprite;

    reflectionSprite = &gSprites[CreateCopySpriteAt(sprite, sprite->x, sprite->y, 152)];
    reflectionSprite->callback = UpdateObjectReflectionSprite;
    reflectionSprite->oam.priority = 3;
    reflectionSprite->oam.paletteNum = gReflectionEffectPaletteMap[reflectionSprite->oam.paletteNum];
    reflectionSprite->usingSheet = TRUE;
    reflectionSprite->anims = gDummySpriteAnimTable;
    StartSpriteAnim(reflectionSprite, 0);
    reflectionSprite->affineAnims = gDummySpriteAffineAnimTable;
    reflectionSprite->affineAnimBeginning = TRUE;
    reflectionSprite->subspriteMode = SUBSPRITES_OFF;
    reflectionSprite->sReflectionObjEventId = sprite->data[0];
    reflectionSprite->sReflectionObjEventLocalId = objectEvent->localId;
    reflectionSprite->sIsStillReflection = stillReflection;
    LoadObjectReflectionPalette(objectEvent, reflectionSprite);

    if (!stillReflection)
        reflectionSprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
}

static s16 GetReflectionVerticalOffset(struct ObjectEvent *objectEvent)
{
    return GetObjectEventGraphicsInfo(objectEvent->graphicsId)->height - 2;
}

static void LoadObjectReflectionPalette(struct ObjectEvent *objectEvent, struct Sprite *reflectionSprite)
{
    u8 bridgeType;
    u16 bridgeReflectionVerticalOffsets[3];
    // JP ROM data at 0x085ACA40
    extern const u16 sBridgeReflectionVerticalOffsets[3];
    memcpy(bridgeReflectionVerticalOffsets, sBridgeReflectionVerticalOffsets, sizeof(bridgeReflectionVerticalOffsets));
    reflectionSprite->sReflectionVerticalOffset = 0;
    if (!GetObjectEventGraphicsInfo(objectEvent->graphicsId)->disableReflectionPaletteLoad
     && ((bridgeType = MetatileBehavior_GetBridgeType(objectEvent->previousMetatileBehavior))
      || (bridgeType = MetatileBehavior_GetBridgeType(objectEvent->currentMetatileBehavior))))
    {
        reflectionSprite->sReflectionVerticalOffset = bridgeReflectionVerticalOffsets[bridgeType - 1];
        LoadObjectHighBridgeReflectionPalette(objectEvent, reflectionSprite->oam.paletteNum);
    }
    else
    {
        LoadObjectRegularReflectionPalette(objectEvent, reflectionSprite->oam.paletteNum);
    }
}

static void LoadObjectRegularReflectionPalette(struct ObjectEvent *objectEvent, u8 paletteIndex)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    if (graphicsInfo->reflectionPaletteTag != OBJ_EVENT_PAL_TAG_NONE)
    {
        if (graphicsInfo->paletteSlot == PALSLOT_PLAYER)
            LoadPlayerObjectReflectionPalette(graphicsInfo->paletteTag, paletteIndex);
        else if (graphicsInfo->paletteSlot == PALSLOT_NPC_SPECIAL)
            LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag, paletteIndex);
        else
            PatchObjectPalette(GetObjectPaletteTag(paletteIndex), paletteIndex);
        UpdateSpritePaletteWithWeather(paletteIndex);
    }
}

// When walking on a bridge high above water (Route 120), the reflection is a solid dark blue color.
// This is so the sprite blends in with the dark water metatile underneath the bridge.
static void LoadObjectHighBridgeReflectionPalette(struct ObjectEvent *objectEvent, u8 paletteNum)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    if (graphicsInfo->reflectionPaletteTag != OBJ_EVENT_PAL_TAG_NONE)
    {
        PatchObjectPalette(graphicsInfo->reflectionPaletteTag, paletteNum);
        UpdateSpritePaletteWithWeather(paletteNum);
    }
}

static void UpdateObjectReflectionSprite(struct Sprite *reflectionSprite)
{
    struct ObjectEvent *objectEvent = &gObjectEvents[reflectionSprite->sReflectionObjEventId];
    struct Sprite *mainSprite = &gSprites[objectEvent->spriteId];
    if (!objectEvent->active || !objectEvent->hasReflection || objectEvent->localId != reflectionSprite->sReflectionObjEventLocalId)
    {
        reflectionSprite->inUse = FALSE;
    }
    else
    {
        reflectionSprite->oam.paletteNum = gReflectionEffectPaletteMap[mainSprite->oam.paletteNum];
        reflectionSprite->oam.shape = mainSprite->oam.shape;
        reflectionSprite->oam.size = mainSprite->oam.size;
        reflectionSprite->oam.matrixNum = mainSprite->oam.matrixNum | ST_OAM_VFLIP;
        reflectionSprite->oam.tileNum = mainSprite->oam.tileNum;
        reflectionSprite->subspriteTables = mainSprite->subspriteTables;
        reflectionSprite->subspriteTableNum = mainSprite->subspriteTableNum;
        reflectionSprite->invisible = mainSprite->invisible;
        reflectionSprite->x = mainSprite->x;
        reflectionSprite->y = mainSprite->y + GetReflectionVerticalOffset(objectEvent) + reflectionSprite->sReflectionVerticalOffset;
        reflectionSprite->centerToCornerVecX = mainSprite->centerToCornerVecX;
        reflectionSprite->centerToCornerVecY = mainSprite->centerToCornerVecY;
        reflectionSprite->x2 = mainSprite->x2;
        reflectionSprite->y2 = -mainSprite->y2;
        reflectionSprite->coordOffsetEnabled = mainSprite->coordOffsetEnabled;

        if (objectEvent->hideReflection == TRUE)
            reflectionSprite->invisible = TRUE;

        if (reflectionSprite->sIsStillReflection == FALSE)
        {
            // Sets the reflection sprite's rot/scale matrix to the appropriate
            // matrix based on whether or not the main sprite is horizontally flipped.
            // If the sprite is facing to the east, then it is flipped, and its matrixNum is 8.
            reflectionSprite->oam.matrixNum = 0;
            if (mainSprite->oam.matrixNum & ST_OAM_HFLIP)
                reflectionSprite->oam.matrixNum = 1;
        }
    }
}

#undef sReflectionObjEventId
#undef sReflectionObjEventLocalId
#undef sReflectionVerticalOffset
#undef sIsStillReflection

extern const struct SpriteTemplate *const gFieldEffectObjectTemplatePointers[];

#define sPrevX data[0]
#define sPrevY data[1]

u8 CreateWarpArrowSprite(void)
{
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_ARROW], 0, 0, 82);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->invisible = TRUE;
    }
    return spriteId;
}

void SetSpriteInvisible(u8 spriteId)
{
    gSprites[spriteId].invisible = TRUE;
}

void ShowWarpArrowSprite(u8 spriteId, u8 direction, s16 x, s16 y)
{
    struct Sprite *sprite = &gSprites[spriteId];
    if (sprite->invisible || sprite->sPrevX != x || sprite->sPrevY != y)
    {
        s16 x2, y2;
        SetSpritePosToMapCoords(x, y, &x2, &y2);
        sprite = &gSprites[spriteId];
        sprite->x = x2 + 8;
        sprite->y = y2 + 8;
        sprite->invisible = FALSE;
        sprite->sPrevX = x;
        sprite->sPrevY = y;
        StartSpriteAnim(sprite, direction - 1);
    }
}

#undef sPrevX
#undef sPrevY

// JP ROM data (see ld_script_jp.txt)
extern const u8 sShadowEffectTemplateIds[4];
extern const u16 gShadowVerticalOffsets[4];

// Sprite data for FLDEFF_SHADOW
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sYOffset  data[3]

u32 FldEff_Shadow(void)
{
    u8 objectEventId = GetObjectEventIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[objectEventId].graphicsId);
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[sShadowEffectTemplateIds[graphicsInfo->shadowSize]], 0, 0, 148);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].sLocalId = gFieldEffectArguments[0];
        gSprites[spriteId].sMapNum = gFieldEffectArguments[1];
        gSprites[spriteId].sMapGroup = gFieldEffectArguments[2];
        gSprites[spriteId].sYOffset = (graphicsInfo->height >> 1) - gShadowVerticalOffsets[graphicsInfo->shadowSize];
    }
    return 0;
}

void UpdateShadowFieldEffect(struct Sprite *sprite)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId))
    {
        FieldEffectStop(sprite, FLDEFF_SHADOW);
    }
    else
    {
        struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
        struct Sprite *linkedSprite = &gSprites[objectEvent->spriteId];
        sprite->oam.priority = linkedSprite->oam.priority;
        sprite->x = linkedSprite->x;
        sprite->y = linkedSprite->y + sprite->sYOffset;
        if (!objectEvent->active || !objectEvent->hasShadow
         || MetatileBehavior_IsPokeGrass(objectEvent->currentMetatileBehavior)
         || MetatileBehavior_IsSurfableWaterOrUnderwater(objectEvent->currentMetatileBehavior)
         || MetatileBehavior_IsSurfableWaterOrUnderwater(objectEvent->previousMetatileBehavior)
         || MetatileBehavior_IsReflective(objectEvent->currentMetatileBehavior)
         || MetatileBehavior_IsReflective(objectEvent->previousMetatileBehavior))
        {
            FieldEffectStop(sprite, FLDEFF_SHADOW);
        }
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sYOffset

// Sprite data for FLDEFF_TALL_GRASS and FLDEFF_LONG_GRASS
#define sElevation   data[0]
#define sX           data[1]
#define sY           data[2]
#define sMapNum      data[3]      // Lower 8 bits
#define sLocalId     data[3] >> 8 // Upper 8 bits
#define sMapGroup    data[4]
#define sCurrentMap  data[5]
#define sObjectMoved data[7]

u32 FldEff_TallGrass(void)
{
    u8 spriteId;
    s16 x = gFieldEffectArguments[0];
    s16 y = gFieldEffectArguments[1];
    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_TALL_GRASS], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sElevation = gFieldEffectArguments[2];
        sprite->sX = gFieldEffectArguments[0];
        sprite->sY = gFieldEffectArguments[1];
        sprite->sMapNum = gFieldEffectArguments[4]; // Also sLocalId
        sprite->sMapGroup = gFieldEffectArguments[5];
        sprite->sCurrentMap = gFieldEffectArguments[6];

        if (gFieldEffectArguments[7])
            SeekSpriteAnim(sprite, 4); // Skip to end of anim
    }
    return 0;
}

void UpdateTallGrassFieldEffect(struct Sprite *sprite)
{
    u8 metatileBehavior;
    u8 localId;
    u8 objectEventId;
    u8 mapNum = sprite->sCurrentMap >> 8;
    u8 mapGroup = sprite->sCurrentMap;

    if (gCamera.active && (gSaveBlock1Ptr->location.mapNum != mapNum || gSaveBlock1Ptr->location.mapGroup != mapGroup))
    {
        sprite->sX -= gCamera.x;
        sprite->sY -= gCamera.y;
        sprite->sCurrentMap = ((u8)gSaveBlock1Ptr->location.mapNum << 8) | (u8)gSaveBlock1Ptr->location.mapGroup;
    }
    localId = sprite->sLocalId;
    mapNum = sprite->sMapNum;
    mapGroup = sprite->sMapGroup;
    metatileBehavior = MapGridGetMetatileBehaviorAt(sprite->sX, sprite->sY);

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId)
     || !MetatileBehavior_IsTallGrass(metatileBehavior)
     || (sprite->sObjectMoved && sprite->animEnded))
    {
        FieldEffectStop(sprite, FLDEFF_TALL_GRASS);
    }
    else
    {
        // Check if the object that triggered the effect has moved away
        struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
        if ((objectEvent->currentCoords.x != sprite->sX || objectEvent->currentCoords.y != sprite->sY)
        && (objectEvent->previousCoords.x != sprite->sX || objectEvent->previousCoords.y != sprite->sY))
            sprite->sObjectMoved = TRUE;

        // Metatile behavior var re-used as subpriority
        metatileBehavior = 0;
        if (sprite->animCmdIndex == 0)
            metatileBehavior = 4;

        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
        UpdateGrassFieldEffectSubpriority(sprite, sprite->sElevation, metatileBehavior);
    }
}

u32 FldEff_JumpTallGrass(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 12);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_JUMP_TALL_GRASS], gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sJumpElevation = gFieldEffectArguments[2];
        sprite->sJumpFldEff = FLDEFF_JUMP_TALL_GRASS;
    }
    return 0;
}

u8 FindTallGrassFieldEffectSpriteId(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < MAX_SPRITES; i ++)
    {
        if (gSprites[i].inUse)
        {
            struct Sprite *sprite = &gSprites[i];
            if (sprite->callback == UpdateTallGrassFieldEffect
                && (x == sprite->sX && y == sprite->sY)
                && localId == (u8)(sprite->sLocalId)
                && mapNum == (sprite->sMapNum & 0xFF)
                && mapGroup == sprite->sMapGroup)
                return i;
        }
    }
    return MAX_SPRITES;
}

u32 FldEff_LongGrass(void)
{
    u8 spriteId;
    s16 x = gFieldEffectArguments[0];
    s16 y = gFieldEffectArguments[1];
    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_LONG_GRASS], x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = ElevationToPriority(gFieldEffectArguments[2]);
        sprite->sElevation = gFieldEffectArguments[2];
        sprite->sX = gFieldEffectArguments[0];
        sprite->sY = gFieldEffectArguments[1];
        sprite->sMapNum = gFieldEffectArguments[4]; // Also sLocalId
        sprite->sMapGroup = gFieldEffectArguments[5];
        sprite->sCurrentMap = gFieldEffectArguments[6];

        if (gFieldEffectArguments[7])
            SeekSpriteAnim(sprite, 6); // Skip to end of anim
    }
    return 0;
}

void UpdateLongGrassFieldEffect(struct Sprite *sprite)
{
    u8 metatileBehavior;
    u8 localId;
    u8 objectEventId;
    u8 mapNum = sprite->sCurrentMap >> 8;
    u8 mapGroup = sprite->sCurrentMap;

    if (gCamera.active && (gSaveBlock1Ptr->location.mapNum != mapNum || gSaveBlock1Ptr->location.mapGroup != mapGroup))
    {
        sprite->sX -= gCamera.x;
        sprite->sY -= gCamera.y;
        sprite->sCurrentMap = ((u8)gSaveBlock1Ptr->location.mapNum << 8) | (u8)gSaveBlock1Ptr->location.mapGroup;
    }
    localId = sprite->sLocalId;
    mapNum = sprite->sMapNum;
    mapGroup = sprite->sMapGroup;
    metatileBehavior = MapGridGetMetatileBehaviorAt(sprite->sX, sprite->sY);
    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId)
     || !MetatileBehavior_IsLongGrass(metatileBehavior)
     || (sprite->sObjectMoved && sprite->animEnded))
    {
        FieldEffectStop(sprite, FLDEFF_LONG_GRASS);
    }
    else
    {
        // Check if the object that triggered the effect has moved away
        struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
        if ((objectEvent->currentCoords.x != sprite->sX || objectEvent->currentCoords.y != sprite->sY)
         && (objectEvent->previousCoords.x != sprite->sX || objectEvent->previousCoords.y != sprite->sY))
            sprite->sObjectMoved = TRUE;

        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
        UpdateGrassFieldEffectSubpriority(sprite, sprite->sElevation, 0);
    }
}

#undef sElevation
#undef sX
#undef sY
#undef sMapNum
#undef sLocalId
#undef sMapGroup
#undef sCurrentMap
#undef sObjectMoved

// Effectively unused as it's not possible in vanilla to jump onto long grass (no adjacent ledges, and can't ride the Acro Bike in it).
// The graphics for this effect do not visually correspond to long grass either. Perhaps these graphics were its original design?
u32 FldEff_JumpLongGrass(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_JUMP_LONG_GRASS], gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sJumpElevation = gFieldEffectArguments[2];
        sprite->sJumpFldEff = FLDEFF_JUMP_LONG_GRASS;
    }
    return 0;
}

// Sprite data for FLDEFF_SHORT_GRASS
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sPrevX    data[3]
#define sPrevY    data[4]

u32 FldEff_ShortGrass(void)
{
    u8 objectEventId = GetObjectEventIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SHORT_GRASS], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &(gSprites[spriteId]);
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[objectEvent->spriteId].oam.priority;
        sprite->sLocalId = gFieldEffectArguments[0];
        sprite->sMapNum = gFieldEffectArguments[1];
        sprite->sMapGroup = gFieldEffectArguments[2];
        sprite->sPrevX = gSprites[objectEvent->spriteId].x;
        sprite->sPrevY = gSprites[objectEvent->spriteId].y;
    }
    return 0;
}

void UpdateShortGrassFieldEffect(struct Sprite *sprite)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId) || !gObjectEvents[objectEventId].inShortGrass)
    {
        FieldEffectStop(sprite, FLDEFF_SHORT_GRASS);
    }
    else
    {
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[objectEventId].graphicsId);
        struct Sprite *linkedSprite = &gSprites[gObjectEvents[objectEventId].spriteId];
        s16 parentY = linkedSprite->y;
        s16 parentX = linkedSprite->x;
        if (parentX != sprite->sPrevX || parentY != sprite->sPrevY)
        {
            // Parent sprite moved, try to restart the animation
            sprite->sPrevX = parentX;
            sprite->sPrevY = parentY;
            if (sprite->animEnded)
                StartSpriteAnim(sprite, 0);
        }
        sprite->x = parentX;
        sprite->y = parentY;
        // Offset the grass sprite halfway down the parent sprite.
        sprite->y2 = (graphicsInfo->height >> 1) - 8;
        sprite->subpriority = linkedSprite->subpriority - 1;
        sprite->oam.priority = linkedSprite->oam.priority;
        UpdateObjectEventSpriteInvisibility(sprite, linkedSprite->invisible);
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sPrevX
#undef sPrevY

// Sprite data for FLDEFF_SAND_FOOTPRINTS, FLDEFF_DEEP_SAND_FOOTPRINTS, and FLDEFF_BIKE_TIRE_TRACKS
#define sState   data[0]
#define sTimer   data[1]
#define sFldEff  data[7]

u32 FldEff_SandFootprints(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SAND_FOOTPRINTS], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sFldEff = FLDEFF_SAND_FOOTPRINTS;
        StartSpriteAnim(sprite, gFieldEffectArguments[4]);
    }
    return 0;
}

u32 FldEff_DeepSandFootprints(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_DEEP_SAND_FOOTPRINTS], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sFldEff = FLDEFF_DEEP_SAND_FOOTPRINTS;
        StartSpriteAnim(sprite, gFieldEffectArguments[4]);
    }
    return spriteId;
}

u32 FldEff_BikeTireTracks(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_BIKE_TIRE_TRACKS], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sFldEff = FLDEFF_BIKE_TIRE_TRACKS;
        StartSpriteAnim(sprite, gFieldEffectArguments[4]);
    }
    return spriteId;
}

extern void (*const gFadeFootprintsTireTracksFuncs[])(struct Sprite *);

void UpdateFootprintsTireTracksFieldEffect(struct Sprite *sprite)
{
    gFadeFootprintsTireTracksFuncs[sprite->sState](sprite);
}

static void FadeFootprintsTireTracks_Step0(struct Sprite *sprite)
{
    // Wait 40 frames before the flickering starts.
    if (++sprite->sTimer > 40)
        sprite->sState = 1;

    UpdateObjectEventSpriteInvisibility(sprite, FALSE);
}

static void FadeFootprintsTireTracks_Step1(struct Sprite *sprite)
{
    sprite->invisible ^= 1;
    sprite->sTimer++;
    UpdateObjectEventSpriteInvisibility(sprite, sprite->invisible);
    if (sprite->sTimer > 56)
        FieldEffectStop(sprite, sprite->sFldEff);
}

#undef sState
#undef sTimer
#undef sFldEff

// Sprite data for FLDEFF_SPLASH
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]

u32 FldEff_Splash(void)
{
    u8 objectEventId = GetObjectEventIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPLASH], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *linkedSprite;
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        linkedSprite = &gSprites[objectEvent->spriteId];
        sprite->oam.priority = linkedSprite->oam.priority;
        sprite->sLocalId = gFieldEffectArguments[0];
        sprite->sMapNum = gFieldEffectArguments[1];
        sprite->sMapGroup = gFieldEffectArguments[2];
        sprite->y2 = (graphicsInfo->height >> 1) - 4;
        PlaySE(SE_PUDDLE);
    }
    return 0;
}

void UpdateSplashFieldEffect(struct Sprite *sprite)
{
    u8 objectEventId;

    if (sprite->animEnded || TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId))
    {
        FieldEffectStop(sprite, FLDEFF_SPLASH);
    }
    else
    {
        sprite->x = gSprites[gObjectEvents[objectEventId].spriteId].x;
        sprite->y = gSprites[gObjectEvents[objectEventId].spriteId].y;
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup

u32 FldEff_JumpSmallSplash(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 12);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_JUMP_SMALL_SPLASH], gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sJumpElevation = gFieldEffectArguments[2];
        sprite->sJumpFldEff = FLDEFF_JUMP_SMALL_SPLASH;
    }
    return 0;
}

u32 FldEff_JumpBigSplash(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_JUMP_BIG_SPLASH], gFieldEffectArguments[0], gFieldEffectArguments[1], 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sJumpElevation = gFieldEffectArguments[2];
        sprite->sJumpFldEff = FLDEFF_JUMP_BIG_SPLASH;
    }
    return 0;
}

// Sprite data for FLDEFF_FEET_IN_FLOWING_WATER
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sPrevX    data[3]
#define sPrevY    data[4]

u32 FldEff_FeetInFlowingWater(void)
{
    u8 objectEventId = GetObjectEventIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SPLASH], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->callback = UpdateFeetInFlowingWaterFieldEffect;
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[objectEvent->spriteId].oam.priority;
        sprite->sLocalId = gFieldEffectArguments[0];
        sprite->sMapNum = gFieldEffectArguments[1];
        sprite->sMapGroup = gFieldEffectArguments[2];
        sprite->sPrevX = -1;
        sprite->sPrevY = -1;
        sprite->y2 = (graphicsInfo->height >> 1) - 4;
        StartSpriteAnim(sprite, 1);
    }
    return 0;
}

static void UpdateFeetInFlowingWaterFieldEffect(struct Sprite *sprite)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId) || !gObjectEvents[objectEventId].inShallowFlowingWater)
    {
        FieldEffectStop(sprite, FLDEFF_FEET_IN_FLOWING_WATER);
    }
    else
    {
        struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
        struct Sprite *linkedSprite = &gSprites[objectEvent->spriteId];
        sprite->x = linkedSprite->x;
        sprite->y = linkedSprite->y;
        sprite->subpriority = linkedSprite->subpriority;
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
        if (objectEvent->currentCoords.x != sprite->sPrevX || objectEvent->currentCoords.y != sprite->sPrevY)
        {
            sprite->sPrevX = objectEvent->currentCoords.x;
            sprite->sPrevY = objectEvent->currentCoords.y;
            if (!sprite->invisible)
                PlaySE(SE_PUDDLE);
        }
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sPrevX
#undef sPrevY

u32 FldEff_Ripple(void)
{
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_RIPPLE], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sWaitFldEff = FLDEFF_RIPPLE;
    }
    return 0;
}

// Sprite data for FLDEFF_HOT_SPRINGS_WATER
#define sLocalId  data[0]
#define sMapNum   data[1]
#define sMapGroup data[2]
#define sPrevX    data[3]
#define sPrevY    data[4]

u32 FldEff_HotSpringsWater(void)
{
    u8 objectEventId = GetObjectEventIdByLocalIdAndMap(gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    struct ObjectEvent *objectEvent = &gObjectEvents[objectEventId];
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_HOT_SPRINGS_WATER], 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gSprites[objectEvent->spriteId].oam.priority;
        sprite->sLocalId = gFieldEffectArguments[0];
        sprite->sMapNum = gFieldEffectArguments[1];
        sprite->sMapGroup = gFieldEffectArguments[2];
        sprite->sPrevX = gSprites[objectEvent->spriteId].x; // Unused
        sprite->sPrevY = gSprites[objectEvent->spriteId].y; // Unused
    }
    return 0;
}

void UpdateHotSpringsWaterFieldEffect(struct Sprite *sprite)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(sprite->sLocalId, sprite->sMapNum, sprite->sMapGroup, &objectEventId) || !gObjectEvents[objectEventId].inHotSprings)
    {
        FieldEffectStop(sprite, FLDEFF_HOT_SPRINGS_WATER);
    }
    else
    {
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(gObjectEvents[objectEventId].graphicsId);
        struct Sprite *linkedSprite = &gSprites[gObjectEvents[objectEventId].spriteId];
        sprite->x = linkedSprite->x;
        sprite->y = (graphicsInfo->height >> 1) + linkedSprite->y - 8;
        sprite->subpriority = linkedSprite->subpriority - 1;
        UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    }
}

#undef sLocalId
#undef sMapNum
#undef sMapGroup
#undef sPrevX
#undef sPrevY

u32 FldEff_UnusedGrass(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_UNUSED_GRASS], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sWaitFldEff = FLDEFF_UNUSED_GRASS;
    }
    return 0;
}

u32 FldEff_UnusedGrass2(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_UNUSED_GRASS_2], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sWaitFldEff = FLDEFF_UNUSED_GRASS_2;
    }
    return 0;
}

u32 FldEff_UnusedSand(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_UNUSED_SAND], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sWaitFldEff = FLDEFF_UNUSED_SAND;
    }
    return 0;
}

u32 FldEff_WaterSurfacing(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_WATER_SURFACING], gFieldEffectArguments[0], gFieldEffectArguments[1], gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sWaitFldEff = FLDEFF_WATER_SURFACING;
    }
    return 0;
}

// Sprite data for FLDEFF_ASH
#define sState      data[0]
#define sX          data[1]
#define sY          data[2]
#define sMetatileId data[3]
#define sDelay      data[4]

void StartAshFieldEffect(s16 x, s16 y, u16 metatileId, s16 delay)
{
    gFieldEffectArguments[0] = x;
    gFieldEffectArguments[1] = y;
    gFieldEffectArguments[2] = 82; // subpriority
    gFieldEffectArguments[3] = 1; // priority
    gFieldEffectArguments[4] = metatileId;
    gFieldEffectArguments[5] = delay;
    FieldEffectStart(FLDEFF_ASH);
}

u32 FldEff_Ash(void)
{
    u8 spriteId;

    s16 x = gFieldEffectArguments[0];
    s16 y = gFieldEffectArguments[1];
    SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_ASH], x, y, gFieldEffectArguments[2]);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.priority = gFieldEffectArguments[3];
        sprite->sX = gFieldEffectArguments[0];
        sprite->sY = gFieldEffectArguments[1];
        sprite->sMetatileId = gFieldEffectArguments[4];
        sprite->sDelay = gFieldEffectArguments[5];
    }
    return 0;
}

extern void (*const gAshFieldEffectFuncs[])(struct Sprite *);

void UpdateAshFieldEffect(struct Sprite *sprite)
{
    gAshFieldEffectFuncs[sprite->sState](sprite);
}

static void UpdateAshFieldEffect_Wait(struct Sprite *sprite)
{
    sprite->invisible = TRUE;
    sprite->animPaused = TRUE;
    if (--sprite->sDelay == 0)
        sprite->sState = 1;
}

static void UpdateAshFieldEffect_Show(struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    sprite->animPaused = FALSE;
    MapGridSetMetatileIdAt(sprite->sX, sprite->sY, sprite->sMetatileId);
    CurrentMapDrawMetatileAt(sprite->sX, sprite->sY);
    gObjectEvents[gPlayerAvatar.objectEventId].triggerGroundEffectsOnMove = TRUE;
    sprite->sState = 2;
}

static void UpdateAshFieldEffect_End(struct Sprite *sprite)
{
    UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    if (sprite->animEnded)
        FieldEffectStop(sprite, FLDEFF_ASH);
}

#undef sState
#undef sX
#undef sY
#undef sMetatileId
#undef sDelay

// Sprite data for FLDEFF_SURF_BLOB
#define sBitfield     data[0]
#define sPlayerOffset data[1]
#define sPlayerObjId  data[2]
#define sVelocity     data[3]
#define sTimer        data[4]
#define sIntervalIdx  data[5]
#define sPrevX        data[6]
#define sPrevY        data[7]

u32 FldEff_SurfBlob(void)
{
    u8 spriteId;

    SetSpritePosToOffsetMapCoords((s16 *)&gFieldEffectArguments[0], (s16 *)&gFieldEffectArguments[1], 8, 8);
    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_SURF_BLOB], gFieldEffectArguments[0], gFieldEffectArguments[1], 150);
    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->oam.paletteNum = 0;
        sprite->sPlayerObjId = gFieldEffectArguments[2];
        sprite->sVelocity = -1;
        sprite->sPrevX = -1;
        sprite->sPrevY = -1;
    }
    FieldEffectActiveListRemove(FLDEFF_SURF_BLOB);
    return spriteId;
}


void SetSurfBlob_BobState(u8 spriteId, u8 state)
{
    gSprites[spriteId].sBitfield = (gSprites[spriteId].sBitfield & ~0xF) | (state & 0xF);
}

void SetSurfBlob_DontSyncAnim(u8 spriteId, bool8 dontSync)
{
    gSprites[spriteId].sBitfield = (gSprites[spriteId].sBitfield & ~0xF0) | ((dontSync & 0xF) << 4);
}

void SetSurfBlob_PlayerOffset(u8 spriteId, bool8 hasOffset, s16 offset)
{
    gSprites[spriteId].sBitfield = (gSprites[spriteId].sBitfield & ~0xF00) | ((hasOffset & 0xF) << 8);
    gSprites[spriteId].sPlayerOffset = offset;
}
