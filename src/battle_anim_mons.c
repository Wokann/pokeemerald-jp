#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "contest.h"
#include "data.h"
#include "pokemon.h"
#include "sprite.h"
#include <stdint.h>

#define IS_DOUBLE_BATTLE() ((gBattleTypeFlags & BATTLE_TYPE_DOUBLE) != 0)

extern const struct UCoords8 sBattlerCoords[][MAX_BATTLERS_COUNT];
extern const u8 sCastformBackSpriteYCoords[];
extern const u8 sCastformElevations[];
extern const struct MonCoords gCastformFrontSpriteCoords[];

void TranslateSpriteInCircle(struct Sprite *sprite);
void TranslateSpriteInGrowingCircle(struct Sprite *sprite);
void TranslateSpriteInEllipse(struct Sprite *sprite);
void WaitAnimForDuration(struct Sprite *sprite);
void ConvertPosDataToTranslateLinearData(struct Sprite *sprite);
void TranslateSpriteLinear(struct Sprite *sprite);
void TranslateSpriteLinearFixedPoint(struct Sprite *sprite);
void TranslateSpriteLinearById(struct Sprite *sprite);
void TranslateSpriteLinearByIdFixedPoint(struct Sprite *sprite);
void TranslateSpriteLinearAndFlicker(struct Sprite *sprite);
void DestroySpriteAndMatrix(struct Sprite *sprite);
void RunStoredCallbackWhenAffineAnimEnds(struct Sprite *sprite);
void RunStoredCallbackWhenAnimEnds(struct Sprite *sprite);
void DestroyAnimSpriteAndDisableBlend(struct Sprite *sprite);
void DestroyAnimVisualTaskAndDisableBlend(u8 taskId);
void SetSpriteCoordsToAnimAttackerCoords(struct Sprite *sprite);
void SetAnimSpriteInitialXOffset(struct Sprite *sprite, s16 xOffset);
void InitAnimArcTranslation(struct Sprite *sprite);
bool8 TranslateAnimHorizontalArc(struct Sprite *sprite);
bool8 TranslateAnimVerticalArc(struct Sprite *sprite);
void SetSpritePrimaryCoordsFromSecondaryCoords(struct Sprite *sprite);
void InitSpritePosToAnimTarget(struct Sprite *sprite, bool8 respectMonPicOffsets);
void InitSpritePosToAnimAttacker(struct Sprite *sprite, bool8 respectMonPicOffsets);
u8 GetBattlerSide(u8 battler);
u8 GetBattlerPosition(u8 battler);
u8 GetBattlerAtPosition(u8 position);
bool8 IsBattlerSpritePresent(u8 battler);
bool8 IsDoubleBattle(void);
void GetBattleAnimBg1Data(struct BattleAnimBgData *out);
void GetBattleAnimBgData(struct BattleAnimBgData *out, u32 bgId);
void GetBgDataForTransform(struct BattleAnimBgData *out, u8 battler);
void ClearBattleAnimBg(u32 bgId);
void AnimLoadCompressedBgGfx(u32 bgId, const u32 *src, u32 tilesOffset);
void AnimLoadCompressedBgTilemap(u32 bgId, const void *src);
void AnimLoadCompressedBgTilemapHandleContest(struct BattleAnimBgData *data, const void *src, bool32 largeScreen);
u8 GetBattleBgPaletteNum(void);
void UpdateAnimBg3ScreenSize(bool8 largeScreenSize);
void InitSpriteDataForLinearTranslation(struct Sprite *sprite);

void StoreSpriteCallbackInData6(struct Sprite *sprite, void (*callback)(struct Sprite *))
{
    sprite->data[6] = (u32)(callback) & 0xffff;
    sprite->data[7] = (u32)(callback) >> 16;
}

void SetCallbackToStoredInData6(struct Sprite *sprite)
{
    u32 callback = (u16)sprite->data[6] | (sprite->data[7] << 16);
    sprite->callback = (void (*)(struct Sprite *))callback;
}

u8 GetAnimBattlerSpriteId(u8 animBattler)
{
    u8 *sprites;

    if (animBattler == ANIM_ATTACKER)
    {
        if (IsBattlerSpritePresent(gBattleAnimAttacker))
        {
            sprites = gBattlerSpriteIds;
            return sprites[gBattleAnimAttacker];
        }
        else
        {
            return SPRITE_NONE;
        }
    }
    else if (animBattler == ANIM_TARGET)
    {
        if (IsBattlerSpritePresent(gBattleAnimTarget))
        {
            sprites = gBattlerSpriteIds;
            return sprites[gBattleAnimTarget];
        }
        else
        {
            return SPRITE_NONE;
        }
    }
    else if (animBattler == ANIM_ATK_PARTNER)
    {
        if (!IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimAttacker)))
            return SPRITE_NONE;
        else
            return gBattlerSpriteIds[BATTLE_PARTNER(gBattleAnimAttacker)];
    }
    else
    {
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimTarget)))
            return gBattlerSpriteIds[BATTLE_PARTNER(gBattleAnimTarget)];
        else
            return SPRITE_NONE;
    }
}

u8 GetBattlerSpriteCoord(u8 battler, u8 coordType)
{
    u8 retVal;
    u16 species;
    struct BattleSpriteInfo *spriteInfo;

    if (IsContest() && coordType == BATTLER_COORD_Y_PIC_OFFSET && battler == 3)
        coordType = BATTLER_COORD_Y;

    switch (coordType)
    {
    case BATTLER_COORD_X:
    case BATTLER_COORD_X_2:
        retVal = sBattlerCoords[IS_DOUBLE_BATTLE()][GetBattlerPosition(battler)].x;
        break;
    case BATTLER_COORD_Y:
        retVal = sBattlerCoords[IS_DOUBLE_BATTLE()][GetBattlerPosition(battler)].y;
        break;
    case BATTLER_COORD_Y_PIC_OFFSET:
    case BATTLER_COORD_Y_PIC_OFFSET_DEFAULT:
    default:
        if (IsContest())
        {
            if (gContestResources->moveAnim->hasTargetAnim)
                species = gContestResources->moveAnim->targetSpecies;
            else
                species = gContestResources->moveAnim->species;
        }
        else
        {
            if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            {
                spriteInfo = gBattleSpritesDataPtr->battlerData;
                if (!spriteInfo[battler].transformSpecies)
                    species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);
                else
                    species = spriteInfo[battler].transformSpecies;
            }
            else
            {
                spriteInfo = gBattleSpritesDataPtr->battlerData;
                if (!spriteInfo[battler].transformSpecies)
                    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);
                else
                    species = spriteInfo[battler].transformSpecies;
            }
        }
        if (coordType == BATTLER_COORD_Y_PIC_OFFSET)
            retVal = GetBattlerSpriteFinal_Y(battler, species, TRUE);
        else
            retVal = GetBattlerSpriteFinal_Y(battler, species, FALSE);
        break;
    }

    return retVal;
}

u8 GetBattlerYDelta(u8 battler, u16 species)
{
    u16 letter;
    u32 personality;
    struct BattleSpriteInfo *spriteInfo;
    u8 ret;
    u16 coordSpecies;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER || IsContest())
    {
        if (species == SPECIES_UNOWN)
        {
            if (IsContest())
            {
                if (gContestResources->moveAnim->hasTargetAnim)
                    personality = gContestResources->moveAnim->targetPersonality;
                else
                    personality = gContestResources->moveAnim->personality;
            }
            else
            {
                spriteInfo = gBattleSpritesDataPtr->battlerData;
                if (!spriteInfo[battler].transformSpecies)
                    personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);
                else
                    personality = gTransformedPersonalities[battler];
            }
            letter = GET_UNOWN_LETTER(personality);
            if (!letter)
                coordSpecies = species;
            else
                coordSpecies = letter + SPECIES_UNOWN_B - 1;
            ret = gMonBackPicCoords[coordSpecies].y_offset;
        }
        else if (species == SPECIES_CASTFORM)
        {
            ret = sCastformBackSpriteYCoords[gBattleMonForms[battler]];
        }
        else if (species > NUM_SPECIES)
        {
            ret = gMonBackPicCoords[0].y_offset;
        }
        else
        {
            ret = gMonBackPicCoords[species].y_offset;
        }
    }
    else
    {
        if (species == SPECIES_UNOWN)
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battler].transformSpecies)
                personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);
            else
                personality = gTransformedPersonalities[battler];
            letter = GET_UNOWN_LETTER(personality);
            if (!letter)
                coordSpecies = species;
            else
                coordSpecies = letter + SPECIES_UNOWN_B - 1;
            ret = gMonFrontPicCoords[coordSpecies].y_offset;
        }
        else if (species == SPECIES_CASTFORM)
        {
            ret = gCastformFrontSpriteCoords[gBattleMonForms[battler]].y_offset;
        }
        else if (species > NUM_SPECIES)
        {
            ret = gMonFrontPicCoords[0].y_offset;
        }
        else
        {
            ret = gMonFrontPicCoords[species].y_offset;
        }
    }
    return ret;
}

u8 GetBattlerElevation(u8 battler, u16 species)
{
    u8 ret = 0;
    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        if (!IsContest())
        {
            if (species == SPECIES_CASTFORM)
                ret = sCastformElevations[gBattleMonForms[battler]];
            else if (species > NUM_SPECIES)
                ret = gEnemyMonElevation[0];
            else
                ret = gEnemyMonElevation[species];
        }
    }
    return ret;
}

u8 GetBattlerSpriteFinal_Y(u8 battler, u16 species, bool8 a3)
{
    u16 offset;
    u8 y;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER || IsContest())
    {
        offset = GetBattlerYDelta(battler, species);
    }
    else
    {
        offset = GetBattlerYDelta(battler, species);
        offset -= GetBattlerElevation(battler, species);
    }
    y = offset + sBattlerCoords[IS_DOUBLE_BATTLE()][GetBattlerPosition(battler)].y;
    if (a3)
    {
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            y += 8;
        if (y > DISPLAY_HEIGHT - MON_PIC_HEIGHT + 8)
            y = DISPLAY_HEIGHT - MON_PIC_HEIGHT + 8;
    }
    return y;
}

u8 GetBattlerSpriteCoord2(u8 battler, u8 coordType)
{
    u16 species;
    struct BattleSpriteInfo *spriteInfo;

    if (coordType == BATTLER_COORD_Y_PIC_OFFSET || coordType == BATTLER_COORD_Y_PIC_OFFSET_DEFAULT)
    {
        if (IsContest())
        {
            if (gContestResources->moveAnim->hasTargetAnim)
                species = gContestResources->moveAnim->targetSpecies;
            else
                species = gContestResources->moveAnim->species;
        }
        else
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battler].transformSpecies)
                species = gAnimBattlerSpecies[battler];
            else
                species = spriteInfo[battler].transformSpecies;
        }
        if (coordType == BATTLER_COORD_Y_PIC_OFFSET)
            return GetBattlerSpriteFinal_Y(battler, species, TRUE);
        else
            return GetBattlerSpriteFinal_Y(battler, species, FALSE);
    }
    else
    {
        return GetBattlerSpriteCoord(battler, coordType);
    }
}

u8 GetBattlerSpriteDefault_Y(u8 battler)
{
    return GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET_DEFAULT);
}

u8 GetSubstituteSpriteDefault_Y(u8 battler)
{
    u16 y;
    if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y) + 16;
    else
        y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y) + 17;
    return y;
}

u8 GetBattlerYCoordWithElevation(u8 battler)
{
    u16 species;
    u8 y;
    struct BattleSpriteInfo *spriteInfo;

    y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y);
    if (!IsContest())
    {
        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battler].transformSpecies)
                species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);
            else
                species = spriteInfo[battler].transformSpecies;
        }
        else
        {
            spriteInfo = gBattleSpritesDataPtr->battlerData;
            if (!spriteInfo[battler].transformSpecies)
                species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);
            else
                species = spriteInfo[battler].transformSpecies;
        }
        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            y -= GetBattlerElevation(battler, species);
    }
    return y;
}

// Sprite data for TranslateSpriteInCircle/Ellipse and related
#define sCirclePos    data[0]
#define sAmplitude    data[1]
#define sCircleSpeed  data[2]
#define sDuration     data[3]

void TranslateSpriteInCircle(struct Sprite *sprite)
{
    if (sprite->sDuration)
    {
        sprite->x2 = Sin(sprite->sCirclePos, sprite->sAmplitude);
        sprite->y2 = Cos(sprite->sCirclePos, sprite->sAmplitude);
        sprite->sCirclePos += sprite->sCircleSpeed;
        if (sprite->sCirclePos >= 0x100)
            sprite->sCirclePos -= 0x100;
        else if (sprite->sCirclePos < 0)
            sprite->sCirclePos += 0x100;
        sprite->sDuration--;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

// TranslateSpriteInGrowingCircle
#define sAmplitudeSpeed  data[4]
#define sAmplitudeChange data[5]

void TranslateSpriteInGrowingCircle(struct Sprite *sprite)
{
    if (sprite->sDuration)
    {
        sprite->x2 = Sin(sprite->sCirclePos, (s16)((sprite->sAmplitudeChange >> 8) + (u16)sprite->sAmplitude));
        sprite->y2 = Cos(sprite->sCirclePos, (s16)((sprite->sAmplitudeChange >> 8) + (u16)sprite->sAmplitude));
        sprite->sCirclePos += sprite->sCircleSpeed;
        sprite->sAmplitudeChange += sprite->sAmplitudeSpeed;
        if (sprite->sCirclePos >= 0x100)
            sprite->sCirclePos -= 0x100;
        else if (sprite->sCirclePos < 0)
            sprite->sCirclePos += 0x100;
        sprite->sDuration--;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

// TranslateSpriteInEllipse
#define sAmplitudeX sAmplitude
#define sAmplitudeY data[4]

void TranslateSpriteInEllipse(struct Sprite *sprite)
{
    if (sprite->sDuration)
    {
        sprite->x2 = Sin(sprite->sCirclePos, sprite->sAmplitudeX);
        sprite->y2 = Cos(sprite->sCirclePos, sprite->sAmplitudeY);
        sprite->sCirclePos += sprite->sCircleSpeed;
        if (sprite->sCirclePos >= 0x100)
            sprite->sCirclePos -= 0x100;
        else if (sprite->sCirclePos < 0)
            sprite->sCirclePos += 0x100;
        sprite->sDuration--;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

// TranslateSpriteInLissajousCurve
#define sCirclePosX   sCirclePos
#define sCircleSpeedX sCircleSpeed
#define sCirclePosY   data[4]
#define sCircleSpeedY data[5]

// Exact shape depends on arguments. Can move in a figure-8-like pattern, or circular, etc.
static void UNUSED TranslateSpriteInLissajousCurve(struct Sprite *sprite)
{
    if (sprite->sDuration)
    {
        sprite->x2 = Sin(sprite->sCirclePosX, sprite->sAmplitude);
        sprite->y2 = Cos(sprite->sCirclePosY, sprite->sAmplitude);
        sprite->sCirclePosX += sprite->sCircleSpeedX;
        sprite->sCirclePosY += sprite->sCircleSpeedY;

        if (sprite->sCirclePosX >= 0x100)
            sprite->sCirclePosX -= 0x100;
        else if (sprite->sCirclePosX < 0)
            sprite->sCirclePosX += 0x100;

        if (sprite->sCirclePosY >= 0x100)
            sprite->sCirclePosY -= 0x100;
        else if (sprite->sCirclePosY < 0)
            sprite->sCirclePosY += 0x100;

        sprite->sDuration--;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

#undef sCirclePos
#undef sAmplitude
#undef sCircleSpeed
#undef sDuration
#undef sAmplitudeSpeed
#undef sAmplitudeChange
#undef sAmplitudeX
#undef sAmplitudeY
#undef sCirclePosX
#undef sCircleSpeedX
#undef sCirclePosY
#undef sCircleSpeedY

// Simply waits until the sprite's data[0] hits zero.
// This is used to let sprite anims or affine anims to run for a designated
// duration.
void WaitAnimForDuration(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
        sprite->data[0]--;
    else
        SetCallbackToStoredInData6(sprite);
}

// Sprite data for ConvertPosDataToTranslateLinearData
#define sStepsX  data[0]
#define sStartX  data[1]
#define sTargetX data[2]
#define sStartY  data[3]
#define sTargetY data[4]

// Sprite data for TranslateSpriteLinear
#define sMoveSteps data[0]
#define sSpeedX    data[1]
#define sSpeedY    data[2]

// Functionally unused
static void AnimPosToTranslateLinear(struct Sprite *sprite)
{
    ConvertPosDataToTranslateLinearData(sprite);
    sprite->callback = TranslateSpriteLinear;
    sprite->callback(sprite);
}

void ConvertPosDataToTranslateLinearData(struct Sprite *sprite)
{
    s16 old;
    int xDiff;

    if (sprite->sStartX > sprite->sTargetX)
        sprite->sStepsX = -sprite->sStepsX;
    xDiff = sprite->sTargetX - sprite->sStartX;
    old = sprite->sStepsX;
    sprite->sMoveSteps = abs(xDiff / sprite->sStepsX);
    sprite->sSpeedY = (sprite->sTargetY - sprite->sStartY) / sprite->sMoveSteps;
    sprite->sSpeedX = old;
}

void TranslateSpriteLinear(struct Sprite *sprite)
{
    if (sprite->sMoveSteps > 0)
    {
        sprite->sMoveSteps--;
        sprite->x2 += sprite->sSpeedX;
        sprite->y2 += sprite->sSpeedY;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void TranslateSpriteLinearFixedPoint(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        sprite->x2 = sprite->data[3] >> 8;
        sprite->y2 = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

static void TranslateSpriteLinearFixedPointIconFrame(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        sprite->x2 = sprite->data[3] >> 8;
        sprite->y2 = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }

    UpdateMonIconFrame(sprite);
}

static void UNUSED TranslateSpriteToBattleTargetPos(struct Sprite *sprite)
{
    sprite->sStartX = sprite->x + sprite->x2;
    sprite->sStartY = sprite->y + sprite->y2;
    sprite->sTargetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->sTargetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->callback = AnimPosToTranslateLinear;
}

// Same as TranslateSpriteLinear but takes an id to specify which sprite to move
void TranslateSpriteLinearById(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        gSprites[sprite->data[3]].x2 += sprite->data[1];
        gSprites[sprite->data[3]].y2 += sprite->data[2];
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void TranslateSpriteLinearByIdFixedPoint(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->data[3] += sprite->data[1];
        sprite->data[4] += sprite->data[2];
        gSprites[sprite->data[5]].x2 = sprite->data[3] >> 8;
        gSprites[sprite->data[5]].y2 = sprite->data[4] >> 8;
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

void TranslateSpriteLinearAndFlicker(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->x2 = sprite->data[2] >> 8;
        sprite->data[2] += sprite->data[1];
        sprite->y2 = sprite->data[4] >> 8;
        sprite->data[4] += sprite->data[3];
        if (sprite->data[0] % sprite->data[5] == 0)
        {
            if (sprite->data[5])
                sprite->invisible ^= 1;
        }
    }
    else
    {
        SetCallbackToStoredInData6(sprite);
    }
}

#undef sMoveSteps
#undef sSpeedX
#undef sSpeedY

void DestroySpriteAndMatrix(struct Sprite *sprite)
{
    FreeSpriteOamMatrix(sprite);
    DestroyAnimSprite(sprite);
}

static void UNUSED TranslateSpriteToBattleAttackerPos(struct Sprite *sprite)
{
    sprite->sStartX = sprite->x + sprite->x2;
    sprite->sStartY = sprite->y + sprite->y2;
    sprite->sTargetX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->sTargetY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->callback = AnimPosToTranslateLinear;
}

#undef sStepsX
#undef sStartX
#undef sTargetX
#undef sStartY
#undef sTargetY

static void UNUSED EndUnkPaletteAnim(struct Sprite *sprite)
{
    PaletteStruct_ResetById(sprite->data[5]);
    DestroySpriteAndMatrix(sprite);
}

void RunStoredCallbackWhenAffineAnimEnds(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        SetCallbackToStoredInData6(sprite);
}

void RunStoredCallbackWhenAnimEnds(struct Sprite *sprite)
{
    if (sprite->animEnded)
        SetCallbackToStoredInData6(sprite);
}

void DestroyAnimSpriteAndDisableBlend(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

void DestroyAnimVisualTaskAndDisableBlend(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimVisualTask(taskId);
}

void SetSpriteCoordsToAnimAttackerCoords(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
}

void SetAnimSpriteInitialXOffset(struct Sprite *sprite, s16 xOffset)
{
    u16 attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    u16 targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);

    if (attackerX > targetX)
    {
        sprite->x -= xOffset;
    }
    else if (attackerX < targetX)
    {
        sprite->x += xOffset;
    }
    else
    {
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            sprite->x -= xOffset;
        else
            sprite->x += xOffset;
    }
}

void InitAnimArcTranslation(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitAnimLinearTranslation(sprite);
    sprite->data[6] = 0x8000 / sprite->data[0];
    sprite->data[7] = 0;
}


void SetSpritePrimaryCoordsFromSecondaryCoords(struct Sprite *sprite)
{
    sprite->x += sprite->x2;
    sprite->y += sprite->y2;
    sprite->x2 = 0;
    sprite->y2 = 0;
}

void InitSpritePosToAnimTarget(struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    // Battle anim sprites are automatically created at the anim target's center, which
    // is why there is no else clause for the "respectMonPicOffsets" check.
    if (!respectMonPicOffsets)
    {
        sprite->x = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_Y);
    }
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

void InitSpritePosToAnimAttacker(struct Sprite *sprite, bool8 respectMonPicOffsets)
{
    if (!respectMonPicOffsets)
    {
        sprite->x = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    }
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
}

u8 GetBattlerSide(u8 battler)
{
    return GET_BATTLER_SIDE2(battler);
}

u8 GetBattlerPosition(u8 battler)
{
    return gBattlerPositions[battler];
}

u8 GetBattlerAtPosition(u8 position)
{
    u8 i;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattlerPositions[i] == position)
            break;
    }
    return i;
}

bool8 IsBattlerSpritePresent(u8 battler)
{
    if (IsContest())
    {
        if (gBattleAnimAttacker == battler)
            return TRUE;
        else if (gBattleAnimTarget == battler)
            return TRUE;
        else
            return FALSE;
    }
    else
    {
        if (gBattlerPositions[battler] == 0xff)
        {
            return FALSE;
        }
        else if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) != 0)
                return TRUE;
        }
        else
        {
            if (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) != 0)
                return TRUE;
        }
    }
    return FALSE;
}

bool8 IsDoubleBattle(void)
{
    return IS_DOUBLE_BATTLE();
}

#define BG_ANIM_PAL_1        8
#define BG_ANIM_PAL_2        9
#define BG_ANIM_PAL_CONTEST 14

void GetBattleAnimBg1Data(struct BattleAnimBgData *out)
{
    if (IsContest())
    {
        out->bgTiles = gBattleAnimBgTileBuffer;
        out->bgTilemap = (u16 *)gBattleAnimBgTilemapBuffer;
        out->paletteId = BG_ANIM_PAL_CONTEST;
        out->bgId = 1;
        out->tilesOffset = 0;
        out->unused = 0;
    }
    else
    {
        out->bgTiles = gBattleAnimBgTileBuffer;
        out->bgTilemap = (u16 *)gBattleAnimBgTilemapBuffer;
        out->paletteId = BG_ANIM_PAL_1;
        out->bgId = 1;
        out->tilesOffset = 0x200;
        out->unused = 0;
    }
}

void GetBattleAnimBgData(struct BattleAnimBgData *out, u32 bgId)
{
    if (IsContest())
    {
        out->bgTiles = gBattleAnimBgTileBuffer;
        out->bgTilemap = (u16 *)gBattleAnimBgTilemapBuffer;
        out->paletteId = BG_ANIM_PAL_CONTEST;
        out->bgId = 1;
        out->tilesOffset = 0;
        out->unused = 0;
    }
    else if (bgId == 1)
    {
        GetBattleAnimBg1Data(out);
    }
    else
    {
        out->bgTiles = gBattleAnimBgTileBuffer;
        out->bgTilemap = (u16 *)gBattleAnimBgTilemapBuffer;
        out->paletteId = BG_ANIM_PAL_2;
        out->bgId = 2;
        out->tilesOffset = 0x300;
        out->unused = 0;
    }
}

void GetBgDataForTransform(struct BattleAnimBgData *out, u8 battler)
{
    out->bgTiles = gBattleAnimBgTileBuffer;
    out->bgTilemap = (u16 *)gBattleAnimBgTilemapBuffer;
    if (IsContest())
    {
        out->paletteId = BG_ANIM_PAL_CONTEST;
        out->bgId = 1;
        out->tilesOffset = 0;
        out->unused = 0;
    }
    else if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == 1)
    {
        out->paletteId = BG_ANIM_PAL_1;
        out->bgId = 1;
        out->tilesOffset = 0x200;
        out->unused = 0;
    }
    else
    {
        out->paletteId = BG_ANIM_PAL_2;
        out->bgId = 2;
        out->tilesOffset = 0x300;
        out->unused = 0;
    }
}

void ClearBattleAnimBg(u32 bgId)
{
    struct BattleAnimBgData bgAnimData;

    GetBattleAnimBgData(&bgAnimData, bgId);
    CpuFill32(0, bgAnimData.bgTiles, 0x2000);
    LoadBgTiles(bgAnimData.bgId, bgAnimData.bgTiles, 0x2000, bgAnimData.tilesOffset);
    FillBgTilemapBufferRect(bgAnimData.bgId, 0, 0, 0, 32, 64, 17);
    CopyBgTilemapBufferToVram(bgAnimData.bgId);
}

void AnimLoadCompressedBgGfx(u32 bgId, const u32 *src, u32 tilesOffset)
{
    u32 tmp = 0;
    CpuSet(&tmp, gBattleAnimBgTileBuffer, 0x05000800);
    // JP decompresses to VRAM instead of Wram.
    LZDecompressVram(src, gBattleAnimBgTileBuffer);
    LoadBgTiles((u8)bgId, gBattleAnimBgTileBuffer, 0x2000, (u16)tilesOffset);
}

static void InitAnimBgTilemapBuffer(u32 bgId, const void *src)
{
    FillBgTilemapBufferRect((u8)bgId, 0, 0, 0, 32, 64, 17);
    CopyToBgTilemapBuffer((u8)bgId, src, 0, 0);
}

void AnimLoadCompressedBgTilemap(u32 bgId, const void *src)
{
    InitAnimBgTilemapBuffer(bgId, src);
    CopyBgTilemapBufferToVram((u8)bgId);
}

void AnimLoadCompressedBgTilemapHandleContest(struct BattleAnimBgData *data, const void *src, bool32 largeScreen)
{
    InitAnimBgTilemapBuffer(data->bgId, src);
    if (IsContest() == TRUE)
        RelocateBattleBgPal(data->paletteId, data->bgTilemap, 0, largeScreen);
    CopyBgTilemapBufferToVram(data->bgId);
}

u8 GetBattleBgPaletteNum(void)
{
    if (IsContest())
        return 1;
    else
        return 2;
}

void UpdateAnimBg3ScreenSize(bool8 largeScreenSize)
{
    if (!largeScreenSize || IsContest())
    {
        SetAnimBgAttribute(3, BG_ANIM_SCREEN_SIZE, 0);
        SetAnimBgAttribute(3, BG_ANIM_AREA_OVERFLOW_MODE, 1);
    }
    else
    {
        SetAnimBgAttribute(3, BG_ANIM_SCREEN_SIZE, 1);
        SetAnimBgAttribute(3, BG_ANIM_AREA_OVERFLOW_MODE, 0);
    }
}

void InitSpriteDataForLinearTranslation(struct Sprite *sprite)
{
    s16 x = (sprite->data[2] - sprite->data[1]) << 8;
    s16 y = (sprite->data[4] - sprite->data[3]) << 8;
    sprite->data[1] = x / sprite->data[0];
    sprite->data[2] = y / sprite->data[0];
    sprite->data[4] = 0;
    sprite->data[3] = 0;
}

void Trade_MoveSelectedMonToTarget(struct Sprite *sprite)
{
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;
    InitSpriteDataForLinearTranslation(sprite);
    sprite->callback = TranslateSpriteLinearFixedPointIconFrame;
    sprite->callback(sprite);
}
