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
