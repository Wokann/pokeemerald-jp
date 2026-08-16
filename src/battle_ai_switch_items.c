#include "global.h"
#include "battle.h"
#include "battle_ai_switch_items.h"
#include "battle_controllers.h"
#include "constants/moves.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "data.h"
#include "pokemon.h"
#include "random.h"
#include "util.h"

// Forward declarations for the readable C branches (NONMATCHING).
bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng);
bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent);
bool8 ShouldUseItem(void);

bool8 ShouldSwitchIfPerishSong(void)
{
    if (gStatuses3[gActiveBattler] & STATUS3_PERISH_SONG
        && gDisableStructs[gActiveBattler].perishSongTimer == 0)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    return FALSE;
}

bool8 ShouldSwitchIfWonderGuard(void)
{
    u8 opposingPosition;
    u8 opposingBattler;
    u8 moveFlags;
    u8 battlerSide;
    s32 i, j;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party = NULL;
    u16 move;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        return FALSE;

    opposingPosition = BATTLE_OPPOSITE((u8)GetBattlerPosition(gActiveBattler));

    if (gBattleMons[(u8)GetBattlerAtPosition(opposingPosition)].ability != ABILITY_WONDER_GUARD)
        return FALSE;

    // Check if the active Pokémon has a super effective move.
    for (opposingBattler = GetBattlerAtPosition(opposingPosition), i = 0; i < MAX_MON_MOVES; i++)
    {
        move = gBattleMons[gActiveBattler].moves[i];
        if (move == MOVE_NONE)
            continue;

        moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
        if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            return FALSE;
    }

    // Get party information.
    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TOWER_LINK_MULTI))
    {
        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
            firstId = 0, lastId = PARTY_SIZE / 2;
        else
            firstId = PARTY_SIZE / 2, lastId = PARTY_SIZE;
    }
    else
    {
        firstId = 0, lastId = PARTY_SIZE;
    }

    battlerSide = GetBattlerSide(gActiveBattler);
    if (battlerSide == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    // Find a party Pokémon that has a super effective move.
    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[gActiveBattler])
            continue;

        GetMonData(&party[i], MON_DATA_SPECIES); // Unused return value.
        GetMonData(&party[i], MON_DATA_ABILITY_NUM); // Unused return value.

        for (opposingBattler = GetBattlerAtPosition(opposingPosition), j = 0; j < MAX_MON_MOVES; j++)
        {
            move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE && Random() % 3 < 2)
            {
                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
                return TRUE;
            }
        }
    }

    return FALSE;
}

bool8 FindMonThatAbsorbsOpponentsMove(void)
{
    u8 battlerIn1, battlerIn2;
    u8 absorbingTypeAbility;
    u8 battlerSide;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;

    if (HasSuperEffectiveMoveAgainstOpponents(TRUE) && Random() % 3 != 0)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == MOVE_NONE)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == MOVE_UNAVAILABLE)
        return FALSE;
    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[(u8)GetBattlerAtPosition(BATTLE_PARTNER((u8)GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER((u8)GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_FIRE)
        absorbingTypeAbility = ABILITY_FLASH_FIRE;
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_WATER)
        absorbingTypeAbility = ABILITY_WATER_ABSORB;
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_ELECTRIC)
        absorbingTypeAbility = ABILITY_VOLT_ABSORB;
    else
        return FALSE;

    if (gBattleMons[gActiveBattler].ability == absorbingTypeAbility)
        return FALSE;

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TOWER_LINK_MULTI))
    {
        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
            firstId = 0, lastId = PARTY_SIZE / 2;
        else
            firstId = PARTY_SIZE / 2, lastId = PARTY_SIZE;
    }
    else
    {
        firstId = 0, lastId = PARTY_SIZE;
    }

    battlerSide = GetBattlerSide(gActiveBattler);
    if (battlerSide == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species;
        u8 monAbility;

        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES);
        if (GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0)
            monAbility = gSpeciesInfo[species].abilities[1];
        else
            monAbility = gSpeciesInfo[species].abilities[0];

        if (absorbingTypeAbility == monAbility && Random() & 1)
        {
            // we found a mon.
            *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
            BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
            return TRUE;
        }
    }

    return FALSE;
}


bool8 ShouldSwitchIfNaturalCure(void)
{
    if (!(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP))
        return FALSE;
    if (gBattleMons[gActiveBattler].ability != ABILITY_NATURAL_CURE)
        return FALSE;
    if (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 2)
        return FALSE;

    if ((gLastLandedMoves[gActiveBattler] == MOVE_NONE
      || gLastLandedMoves[gActiveBattler] == MOVE_UNAVAILABLE)
     && Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0
          && Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 1))
        return TRUE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 1))
        return TRUE;

    if (Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    return FALSE;
}


bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng)
{
    u8 opposingPosition;
    u8 opposingBattler;
    s32 i;
    u8 moveFlags;
    u16 move;

    opposingPosition = BATTLE_OPPOSITE((u8)GetBattlerPosition(gActiveBattler));
    opposingBattler = GetBattlerAtPosition(opposingPosition);

    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;

    opposingBattler = GetBattlerAtPosition(BATTLE_PARTNER(opposingPosition));

    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }

    return FALSE;
}


bool8 AreStatsRaised(void)
{
    u8 buffedStatsValue = 0;
    s32 i;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[gActiveBattler].statStages[i] > DEFAULT_STAT_STAGE)
            buffedStatsValue += gBattleMons[gActiveBattler].statStages[i] - DEFAULT_STAT_STAGE;
    }

    return (buffedStatsValue > 3);
}


bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent)
{
    u8 battlerIn1, battlerIn2;
    u8 battlerSide;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u16 move;
    u8 moveFlags;

    if (gLastLandedMoves[gActiveBattler] == MOVE_NONE)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == MOVE_UNAVAILABLE)
        return FALSE;
    if (gLastHitBy[gActiveBattler] == 0xFF)
        return FALSE;
    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[(u8)GetBattlerAtPosition(BATTLE_PARTNER((u8)GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER((u8)GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TOWER_LINK_MULTI))
    {
        if ((gActiveBattler & BIT_FLANK) == 0)
            firstId = 0, lastId = PARTY_SIZE / 2;
        else
            firstId = PARTY_SIZE / 2, lastId = PARTY_SIZE;
    }
    else
    {
        firstId = 0, lastId = PARTY_SIZE;
    }

    battlerSide = GetBattlerSide(gActiveBattler);
    if (battlerSide == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species;
        u8 monAbility;

        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES);
        if (GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0)
            monAbility = gSpeciesInfo[species].abilities[1];
        else
            monAbility = gSpeciesInfo[species].abilities[0];

        moveFlags = AI_TypeCalc(gLastLandedMoves[gActiveBattler], species, monAbility);
        if (moveFlags & flags)
        {
            battlerIn1 = gLastHitBy[gActiveBattler];

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                if (move == 0)
                    continue;

                moveFlags = AI_TypeCalc(move, gBattleMons[battlerIn1].species, gBattleMons[battlerIn1].ability);
                if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE && Random() % moduloPercent == 0)
                {
                    *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                    BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}


bool8 ShouldSwitch(void)
{
    u8 battlerIn1, battlerIn2;
    u8 battlerSide;
    u8 *activeBattlerPtr; // Needed to match.
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;
    s32 availableToSwitch;

    if (gBattleMons[*(activeBattlerPtr = &gActiveBattler)].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
        return FALSE;
    if (gStatuses3[gActiveBattler] & STATUS3_ROOTED)
        return FALSE;
    if (ABILITY_ON_OPPOSING_FIELD(gActiveBattler, ABILITY_SHADOW_TAG))
        return FALSE;
    if (ABILITY_ON_OPPOSING_FIELD(gActiveBattler, ABILITY_ARENA_TRAP)) // Misses the flying type and Levitate check.
        return FALSE;
    if (ABILITY_ON_FIELD2(ABILITY_MAGNET_PULL))
    {
        if (IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_STEEL))
            return FALSE;
    }
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return FALSE;

    availableToSwitch = 0;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = *activeBattlerPtr;
        if (gAbsentBattlerFlags & gBitTable[(u8)GetBattlerAtPosition(BATTLE_PARTNER((u8)GetBattlerPosition(*activeBattlerPtr)))])
            battlerIn2 = *activeBattlerPtr;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER((u8)GetBattlerPosition(*activeBattlerPtr)));
    }
    else
    {
        battlerIn1 = *activeBattlerPtr;
        battlerIn2 = *activeBattlerPtr;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TOWER_LINK_MULTI))
    {
        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
            firstId = 0, lastId = PARTY_SIZE / 2;
        else
            firstId = PARTY_SIZE / 2, lastId = PARTY_SIZE;
    }
    else
    {
        firstId = 0, lastId = PARTY_SIZE;
    }

    battlerSide = GetBattlerSide(gActiveBattler);
    if (battlerSide == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;

        availableToSwitch++;
    }

    if (availableToSwitch == 0)
        return FALSE;
    if (ShouldSwitchIfPerishSong())
        return TRUE;
    if (ShouldSwitchIfWonderGuard())
        return TRUE;
    if (FindMonThatAbsorbsOpponentsMove())
        return TRUE;
    if (ShouldSwitchIfNaturalCure())
        return TRUE;
    if (HasSuperEffectiveMoveAgainstOpponents(FALSE))
        return FALSE;
    if (AreStatsRaised())
        return FALSE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 2)
        || FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 3))
        return TRUE;

    return FALSE;
}


void AI_TrySwitchOrUseItem(void)
{
    struct Pokemon *party;
    u8 battlerIn1, battlerIn2;
    u8 battlerSide;
    s32 firstId;
    s32 lastId; // + 1
    u8 battlerIdentity = GetBattlerPosition(gActiveBattler);

    battlerSide = GetBattlerSide(gActiveBattler);
    if (battlerSide == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (ShouldSwitch())
        {
            if (*(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) == PARTY_SIZE)
            {
                s32 monToSwitchId = GetMostSuitableMonToSwitchInto();
                if (monToSwitchId == PARTY_SIZE)
                {
                    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    {
                        battlerIn1 = GetBattlerAtPosition(battlerIdentity);
                        battlerIn2 = battlerIn1;
                    }
                    else
                    {
                        battlerIn1 = GetBattlerAtPosition(battlerIdentity);
                        battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(battlerIdentity));
                    }

                    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TOWER_LINK_MULTI))
                    {
                        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
                            firstId = 0, lastId = PARTY_SIZE / 2;
                        else
                            firstId = PARTY_SIZE / 2, lastId = PARTY_SIZE;
                    }
                    else
                    {
                        firstId = 0, lastId = PARTY_SIZE;
                    }

                    for (monToSwitchId = firstId; monToSwitchId < lastId; monToSwitchId++)
                    {
                        if (GetMonData(&party[monToSwitchId], MON_DATA_HP) == 0)
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn1])
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn2])
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
                            continue;

                        break;
                    }
                }

                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = monToSwitchId;
            }

            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler);
            return;
        }
        else if (ShouldUseItem())
        {
            return;
        }
    }

    BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_USE_MOVE, BATTLE_OPPOSITE(gActiveBattler) << 8);
}


void ModulateByTypeEffectiveness(u8 atkType, u8 defType1, u8 defType2, u8 *var)
{
    s32 i = 0;

    while (TYPE_EFFECT_ATK_TYPE(i) != TYPE_ENDTABLE)
    {
        if (TYPE_EFFECT_ATK_TYPE(i) == TYPE_FORESIGHT)
        {
            i += 3;
            continue;
        }
        else if (TYPE_EFFECT_ATK_TYPE(i) == atkType)
        {
            if (TYPE_EFFECT_DEF_TYPE(i) == defType1)
                *var = (*var * TYPE_EFFECT_MULTIPLIER(i)) / TYPE_MUL_NORMAL;
            if (TYPE_EFFECT_DEF_TYPE(i) == defType2 && defType1 != defType2)
                *var = (*var * TYPE_EFFECT_MULTIPLIER(i)) / TYPE_MUL_NORMAL;
        }
        i += 3;
    }
}


#ifndef NONMATCHING
__attribute__((naked)) u8 GetMostSuitableMonToSwitchInto(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x24\n\t"
        "	ldr r4, _080636B4\n\t"
        "	ldrb r2, [r4]\n\t"
        "	ldr r0, _080636B8\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r1, #0x5c\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #6\n\t"
        "	beq _08063696\n\t"
        "	b _08063A34\n\t"
        "_08063696:\n\t"
        "	ldr r0, _080636BC\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0xb\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080636C4\n\t"
        "	ldr r1, _080636C0\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _08063A34\n\t"
        "	.align 2, 0\n\t"
        "_080636B4: .4byte gActiveBattler\n\t"
        "_080636B8: .4byte gBattleStruct\n\t"
        "_080636BC: .4byte gBattleTypeFlags\n\t"
        "_080636C0: .4byte gBattlerPartyIndexes\n\t"
        "_080636C4:\n\t"
        "	movs r0, #1\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08063750\n\t"
        "	str r2, [sp, #0x10]\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl GetBattlerPosition\n\t"
        "	movs r5, #2\n\t"
        "	eors r0, r5\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _080636FC\n\t"
        "	ldrb r1, [r1]\n\t"
        "	ldr r2, _08063700\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08063704\n\t"
        "	ldrb r4, [r4]\n\t"
        "	str r4, [sp, #0x14]\n\t"
        "	b _0806371A\n\t"
        "	.align 2, 0\n\t"
        "_080636FC: .4byte gAbsentBattlerFlags\n\t"
        "_08063700: .4byte gBitTable\n\t"
        "_08063704:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r5\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #0x14]\n\t"
        "_0806371A:\n\t"
        "	bl Random\n\t"
        "	movs r3, #2\n\t"
        "	ands r0, r3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r0, _08063748\n\t"
        "	ldrb r1, [r0]\n\t"
        "	ldr r2, _0806374C\n\t"
        "	ldr r4, [sp, #4]\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0806376E\n\t"
        "	eors r4, r3\n\t"
        "	lsls r0, r4, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #4]\n\t"
        "	b _0806376E\n\t"
        "	.align 2, 0\n\t"
        "_08063748: .4byte gAbsentBattlerFlags\n\t"
        "_0806374C: .4byte gBitTable\n\t"
        "_08063750:\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl GetBattlerPosition\n\t"
        "	movs r1, #1\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldrb r4, [r4]\n\t"
        "	str r4, [sp, #0x14]\n\t"
        "	str r4, [sp, #0x10]\n\t"
        "_0806376E:\n\t"
        "	ldr r0, _08063790\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _08063794\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080637A6\n\t"
        "	ldr r2, _08063798\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0806379C\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0x18]\n\t"
        "	movs r1, #3\n\t"
        "	str r1, [sp, #0x1c]\n\t"
        "	b _080637B0\n\t"
        "	.align 2, 0\n\t"
        "_08063790: .4byte gBattleTypeFlags\n\t"
        "_08063794: .4byte 0x00808000\n\t"
        "_08063798: .4byte gActiveBattler\n\t"
        "_0806379C:\n\t"
        "	movs r4, #3\n\t"
        "	str r4, [sp, #0x18]\n\t"
        "	movs r0, #6\n\t"
        "	str r0, [sp, #0x1c]\n\t"
        "	b _080637B0\n\t"
        "_080637A6:\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #0x18]\n\t"
        "	movs r2, #6\n\t"
        "	str r2, [sp, #0x1c]\n\t"
        "	ldr r2, _0806389C\n\t"
        "_080637B0:\n\t"
        "	ldrb r0, [r2]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r4, _080638A0\n\t"
        "	str r4, [sp, #0x20]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080637C4\n\t"
        "	ldr r0, _080638A4\n\t"
        "	str r0, [sp, #0x20]\n\t"
        "_080637C4:\n\t"
        "	movs r1, #0\n\t"
        "	mov sb, r1\n\t"
        "_080637C8:\n\t"
        "	movs r2, #0\n\t"
        "	str r2, [sp, #8]\n\t"
        "	movs r4, #6\n\t"
        "	str r4, [sp, #0xc]\n\t"
        "	ldr r7, [sp, #0x18]\n\t"
        "	ldr r0, [sp, #0x1c]\n\t"
        "	cmp r7, r0\n\t"
        "	blt _080637DA\n\t"
        "	b _080638D6\n\t"
        "_080637DA:\n\t"
        "	lsls r0, r7, #2\n\t"
        "	ldr r1, _080638A8\n\t"
        "	adds r0, r0, r1\n\t"
        "	mov r8, r0\n\t"
        "	mov sl, sp\n\t"
        "_080637E4:\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r7, r0\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	adds r4, r2, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	cmp r5, #0\n\t"
        "	beq _080638BC\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080638BC\n\t"
        "	mov r4, r8\n\t"
        "	ldr r0, [r4]\n\t"
        "	mov r1, sb\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080638BC\n\t"
        "	ldr r1, _080638AC\n\t"
        "	ldr r2, [sp, #0x10]\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r7\n\t"
        "	beq _080638BC\n\t"
        "	ldr r4, [sp, #0x14]\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r7\n\t"
        "	beq _080638BC\n\t"
        "	ldr r0, _080638B0\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r2, r1\n\t"
        "	adds r0, #0x5c\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r7, r0\n\t"
        "	beq _080638BC\n\t"
        "	adds r0, r4, r1\n\t"
        "	adds r0, #0x5c\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r7, r0\n\t"
        "	beq _080638BC\n\t"
        "	ldr r1, _080638B4\n\t"
        "	lsls r0, r5, #3\n\t"
        "	subs r0, r0, r5\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r5, [r0, #6]\n\t"
        "	ldrb r6, [r0, #7]\n\t"
        "	movs r0, #0xa\n\t"
        "	mov r1, sl\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0x58\n\t"
        "	ldr r2, [sp, #4]\n\t"
        "	adds r4, r2, #0\n\t"
        "	muls r4, r0, r4\n\t"
        "	ldr r0, _080638B8\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x21\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	mov r3, sp\n\t"
        "	bl ModulateByTypeEffectiveness\n\t"
        "	adds r4, #0x22\n\t"
        "	ldrb r0, [r4]\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	mov r3, sp\n\t"
        "	bl ModulateByTypeEffectiveness\n\t"
        "	ldr r2, [sp, #8]\n\t"
        "	mov r1, sl\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r2, r1\n\t"
        "	bhs _080638CA\n\t"
        "	mov r2, sl\n\t"
        "	ldrb r2, [r2]\n\t"
        "	str r2, [sp, #8]\n\t"
        "	lsls r0, r7, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	b _080638CA\n\t"
        "	.align 2, 0\n\t"
        "_0806389C: .4byte gActiveBattler\n\t"
        "_080638A0: .4byte gEnemyParty\n\t"
        "_080638A4: .4byte gPlayerParty\n\t"
        "_080638A8: .4byte gBitTable\n\t"
        "_080638AC: .4byte gBattlerPartyIndexes\n\t"
        "_080638B0: .4byte gBattleStruct\n\t"
        "_080638B4: .4byte gSpeciesInfo\n\t"
        "_080638B8: .4byte gBattleMons\n\t"
        "_080638BC:\n\t"
        "	mov r4, r8\n\t"
        "	ldr r0, [r4]\n\t"
        "	mov r1, sb\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "_080638CA:\n\t"
        "	movs r2, #4\n\t"
        "	add r8, r2\n\t"
        "	adds r7, #1\n\t"
        "	ldr r4, [sp, #0x1c]\n\t"
        "	cmp r7, r4\n\t"
        "	blt _080637E4\n\t"
        "_080638D6:\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	cmp r0, #6\n\t"
        "	beq _08063938\n\t"
        "	movs r7, #0\n\t"
        "	movs r0, #0x64\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	adds r5, r1, #0\n\t"
        "	muls r5, r0, r5\n\t"
        "_080638E6:\n\t"
        "	adds r1, r7, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	adds r0, r2, r5\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	cmp r4, #0\n\t"
        "	beq _0806390E\n\t"
        "	ldr r0, _08063930\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	ldr r2, [sp, #4]\n\t"
        "	bl TypeCalc\n\t"
        "	movs r1, #2\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08063914\n\t"
        "_0806390E:\n\t"
        "	adds r7, #1\n\t"
        "	cmp r7, #3\n\t"
        "	ble _080638E6\n\t"
        "_08063914:\n\t"
        "	cmp r7, #4\n\t"
        "	beq _0806391A\n\t"
        "	b _08063A32\n\t"
        "_0806391A:\n\t"
        "	ldr r4, [sp, #0xc]\n\t"
        "	lsls r0, r4, #2\n\t"
        "	ldr r1, _08063934\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov r2, sb\n\t"
        "	orrs r2, r0\n\t"
        "	lsls r0, r2, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	b _0806393C\n\t"
        "	.align 2, 0\n\t"
        "_08063930: .4byte gActiveBattler\n\t"
        "_08063934: .4byte gBitTable\n\t"
        "_08063938:\n\t"
        "	movs r4, #0x3f\n\t"
        "	mov sb, r4\n\t"
        "_0806393C:\n\t"
        "	mov r0, sb\n\t"
        "	cmp r0, #0x3f\n\t"
        "	beq _08063944\n\t"
        "	b _080637C8\n\t"
        "_08063944:\n\t"
        "	ldr r0, _08063A44\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0]\n\t"
        "	ldr r0, _08063A48\n\t"
        "	ldr r0, [r0]\n\t"
        "	strb r1, [r0, #0x13]\n\t"
        "	ldr r0, _08063A4C\n\t"
        "	movs r2, #1\n\t"
        "	strb r2, [r0, #0xe]\n\t"
        "	ldr r0, _08063A50\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _08063A54\n\t"
        "	strb r2, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r2, #6\n\t"
        "	str r2, [sp, #0xc]\n\t"
        "	ldr r7, [sp, #0x18]\n\t"
        "	ldr r4, [sp, #0x1c]\n\t"
        "	cmp r7, r4\n\t"
        "	bge _08063A32\n\t"
        "_0806396E:\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r6, r7, #0\n\t"
        "	muls r6, r0, r6\n\t"
        "	ldr r0, [sp, #0x20]\n\t"
        "	adds r4, r0, r6\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	adds r1, r7, #1\n\t"
        "	mov sl, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063A2A\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063A2A\n\t"
        "	ldr r1, _08063A58\n\t"
        "	ldr r2, [sp, #0x10]\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r7\n\t"
        "	beq _08063A2A\n\t"
        "	ldr r4, [sp, #0x14]\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r7\n\t"
        "	beq _08063A2A\n\t"
        "	ldr r0, _08063A48\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r2, r1\n\t"
        "	adds r0, #0x5c\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r7, r0\n\t"
        "	beq _08063A2A\n\t"
        "	adds r0, r4, r1\n\t"
        "	adds r0, #0x5c\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r7, r0\n\t"
        "	beq _08063A2A\n\t"
        "	movs r5, #0\n\t"
        "	mov sb, r6\n\t"
        "	ldr r0, _08063A5C\n\t"
        "	mov r8, r0\n\t"
        "	ldr r6, _08063A60\n\t"
        "_080639D2:\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	ldr r0, [sp, #0x20]\n\t"
        "	add r0, sb\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	movs r0, #0\n\t"
        "	mov r1, r8\n\t"
        "	str r0, [r1]\n\t"
        "	cmp r4, #0\n\t"
        "	beq _08063A0E\n\t"
        "	ldr r0, _08063A64\n\t"
        "	lsls r1, r4, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08063A0E\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [sp, #4]\n\t"
        "	bl AI_CalcDmg\n\t"
        "	ldrb r1, [r6]\n\t"
        "	adds r0, r4, #0\n\t"
        "	ldr r2, [sp, #4]\n\t"
        "	bl TypeCalc\n\t"
        "_08063A0E:\n\t"
        "	mov r2, r8\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r4, [sp, #8]\n\t"
        "	cmp r4, r0\n\t"
        "	bge _08063A24\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #8]\n\t"
        "	lsls r0, r7, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "_08063A24:\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #3\n\t"
        "	ble _080639D2\n\t"
        "_08063A2A:\n\t"
        "	mov r7, sl\n\t"
        "	ldr r0, [sp, #0x1c]\n\t"
        "	cmp r7, r0\n\t"
        "	blt _0806396E\n\t"
        "_08063A32:\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "_08063A34:\n\t"
        "	add sp, #0x24\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08063A44: .4byte gDynamicBasePower\n\t"
        "_08063A48: .4byte gBattleStruct\n\t"
        "_08063A4C: .4byte gBattleScripting\n\t"
        "_08063A50: .4byte gMoveResultFlags\n\t"
        "_08063A54: .4byte gCritMultiplier\n\t"
        "_08063A58: .4byte gBattlerPartyIndexes\n\t"
        "_08063A5C: .4byte gBattleMoveDamage\n\t"
        "_08063A60: .4byte gActiveBattler\n\t"
        "_08063A64: .4byte gBattleMoves\n\t"
        ".syntax divided\n\t"
    );
}
#else
u8 GetMostSuitableMonToSwitchInto(void)
{
    u8 opposingBattler;
#ifdef BUGFIX
    s32 bestDmg;
#else
    u8 bestDmg; // Note: should be changed to s32 since it is also used for the actual damage done later
#endif
    u8 bestMonId;
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u8 invalidMons;
    u16 move;

    if (*(gBattleStruct->monToSwitchIntoId + gActiveBattler) != PARTY_SIZE)
        return *(gBattleStruct->monToSwitchIntoId + gActiveBattler);
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return gBattlerPartyIndexes[gActiveBattler] + 1;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[(u8)GetBattlerAtPosition(BATTLE_PARTNER((u8)GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER((u8)GetBattlerPosition(gActiveBattler)));

        // UB: It considers the opponent only player's side even though it can battle alongside player.
        opposingBattler = Random() & BIT_FLANK;
        if (gAbsentBattlerFlags & gBitTable[opposingBattler])
            opposingBattler ^= BIT_FLANK;
    }
    else
    {
        opposingBattler = GetBattlerAtPosition(BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler)));
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_TOWER_LINK_MULTI))
    {
        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
            firstId = 0, lastId = PARTY_SIZE / 2;
        else
            firstId = PARTY_SIZE / 2, lastId = PARTY_SIZE;
    }
    else
    {
        firstId = 0, lastId = PARTY_SIZE;
    }

    battlerSide = GetBattlerSide(gActiveBattler);
    if (battlerSide == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    invalidMons = 0;

    while (invalidMons != (1 << PARTY_SIZE) - 1) // All mons are invalid.
    {
        bestDmg = TYPE_MUL_NO_EFFECT;
        bestMonId = PARTY_SIZE;
        // Find the mon whose type is the most suitable offensively.
        for (i = firstId; i < lastId; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
            if (species != SPECIES_NONE
                && GetMonData(&party[i], MON_DATA_HP) != 0
                && !(gBitTable[i] & invalidMons)
                && gBattlerPartyIndexes[battlerIn1] != i
                && gBattlerPartyIndexes[battlerIn2] != i
                && i != *(gBattleStruct->monToSwitchIntoId + battlerIn1)
                && i != *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            {
                u8 type1 = gSpeciesInfo[species].types[0];
                u8 type2 = gSpeciesInfo[species].types[1];
                u8 typeDmg = TYPE_MUL_NORMAL;
                ModulateByTypeEffectiveness(gBattleMons[opposingBattler].types[0], type1, type2, &typeDmg);
                ModulateByTypeEffectiveness(gBattleMons[opposingBattler].types[1], type1, type2, &typeDmg);

                /* Possible bug: this comparison gives the type that takes the most damage, when
                a "good" AI would want to select the type that takes the least damage. Unknown if this
                is a legitimate mistake or if it's an intentional, if weird, design choice */
                if (bestDmg < typeDmg)
                {
                    bestDmg = typeDmg;
                    bestMonId = i;
                }
            }
            else
            {
                invalidMons |= gBitTable[i];
            }
        }

        // Ok, we know the mon has the right typing but does it have at least one super effective move?
        if (bestMonId != PARTY_SIZE)
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                move = GetMonData(&party[bestMonId], MON_DATA_MOVE1 + i);
                if (move != MOVE_NONE && TypeCalc(move, gActiveBattler, opposingBattler) & MOVE_RESULT_SUPER_EFFECTIVE)
                    break;
            }

            if (i != MAX_MON_MOVES)
                return bestMonId; // Has both the typing and at least one super effective move.

            invalidMons |= gBitTable[bestMonId]; // Sorry buddy, we want something better.
        }
        else
        {
            invalidMons = (1 << PARTY_SIZE) - 1; // No viable mon to switch.
        }
    }

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    bestDmg = 0;
    bestMonId = PARTY_SIZE;

    // If we couldn't find the best mon in terms of typing, find the one that deals most damage.
    for (i = firstId; i < lastId; i++)
    {
        if ((u16)(GetMonData(&party[i], MON_DATA_SPECIES)) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (gBattlerPartyIndexes[battlerIn1] == i)
            continue;
        if (gBattlerPartyIndexes[battlerIn2] == i)
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            gBattleMoveDamage = 0;
            if (move != MOVE_NONE && gBattleMoves[move].power != 1)
            {
                AI_CalcDmg(gActiveBattler, opposingBattler);
                TypeCalc(move, gActiveBattler, opposingBattler);
            }
            if (bestDmg < gBattleMoveDamage)
            {
                bestDmg = gBattleMoveDamage;
                bestMonId = i;
            }
        }
    }

    return bestMonId;
}
#endif


u8 GetAI_ItemType(u8 itemId, const u8 *itemEffect) // NOTE: should take u16 as item Id argument
{
    if (itemId == ITEM_FULL_RESTORE)
        return AI_ITEM_FULL_RESTORE;
    else if (itemEffect[4] & ITEM4_HEAL_HP)
        return AI_ITEM_HEAL_HP;
    else if (itemEffect[3] & ITEM3_STATUS_ALL)
        return AI_ITEM_CURE_CONDITION;
    else if (itemEffect[0] & (ITEM0_DIRE_HIT | ITEM0_X_ATTACK) || itemEffect[1] != 0 || itemEffect[2] != 0)
        return AI_ITEM_X_STAT;
    else if (itemEffect[3] & ITEM3_GUARD_SPEC)
        return AI_ITEM_GUARD_SPEC;
    else
        return AI_ITEM_NOT_RECOGNIZABLE;
}


#ifndef NONMATCHING
__attribute__((naked)) bool8 ShouldUseItem(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	movs r0, #0\n\t"
        "	mov sl, r0\n\t"
        "	movs r7, #0\n\t"
        "	ldr r0, _08063BAC\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063AF6\n\t"
        "	ldr r0, _08063BB0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #2\n\t"
        "	bne _08063AF6\n\t"
        "	b _08063F60\n\t"
        "_08063AF6:\n\t"
        "	ldr r0, _08063BB0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r5, _08063BB4\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08063B08\n\t"
        "	ldr r5, _08063BB8\n\t"
        "_08063B08:\n\t"
        "	movs r1, #0\n\t"
        "	mov r8, r1\n\t"
        "_08063B0C:\n\t"
        "	movs r0, #0x64\n\t"
        "	mov r2, r8\n\t"
        "	muls r2, r0, r2\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r4, r5, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063B48\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063B48\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	movs r1, #0xce\n\t"
        "	lsls r1, r1, #1\n\t"
        "	cmp r0, r1\n\t"
        "	beq _08063B48\n\t"
        "	mov r0, sl\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "_08063B48:\n\t"
        "	movs r0, #1\n\t"
        "	add r8, r0\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #5\n\t"
        "	ble _08063B0C\n\t"
        "	movs r2, #0\n\t"
        "	mov r8, r2\n\t"
        "_08063B56:\n\t"
        "	ldr r1, _08063BBC\n\t"
        "	mov r0, r8\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063B72\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r0, [r0, #0x18]\n\t"
        "	adds r0, #0x50\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov r2, r8\n\t"
        "	subs r0, r0, r2\n\t"
        "	adds r0, #1\n\t"
        "	cmp sl, r0\n\t"
        "	ble _08063B72\n\t"
        "	b _08063F54\n\t"
        "_08063B72:\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r0, [r0, #0x18]\n\t"
        "	mov r2, r8\n\t"
        "	lsls r1, r2, #1\n\t"
        "	adds r0, #0x48\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	mov sb, r0\n\t"
        "	str r1, [sp]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08063B8A\n\t"
        "	b _08063F54\n\t"
        "_08063B8A:\n\t"
        "	ldr r1, _08063BC0\n\t"
        "	subs r0, #0xd\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08063B9A\n\t"
        "	b _08063F54\n\t"
        "_08063B9A:\n\t"
        "	mov r0, sb\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bne _08063BCC\n\t"
        "	ldr r0, _08063BC4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _08063BC8\n\t"
        "	adds r5, r0, r1\n\t"
        "	b _08063BCE\n\t"
        "	.align 2, 0\n\t"
        "_08063BAC: .4byte gBattleTypeFlags\n\t"
        "_08063BB0: .4byte gActiveBattler\n\t"
        "_08063BB4: .4byte gEnemyParty\n\t"
        "_08063BB8: .4byte gPlayerParty\n\t"
        "_08063BBC: .4byte gBattleResources\n\t"
        "_08063BC0: .4byte gUnknown_82EEF14\n\t"
        "_08063BC4: .4byte gSaveBlock1Ptr\n\t"
        "_08063BC8: .4byte 0x00003214\n\t"
        "_08063BCC:\n\t"
        "	adds r5, r1, #0\n\t"
        "_08063BCE:\n\t"
        "	mov r2, sb\n\t"
        "	lsls r0, r2, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetAI_ItemType\n\t"
        "	ldr r4, _08063C08\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsrs r1, r1, #1\n\t"
        "	ldr r3, _08063C0C\n\t"
        "	ldr r2, [r3]\n\t"
        "	adds r1, r1, r2\n\t"
        "	adds r1, #0xc4\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	subs r0, #1\n\t"
        "	cmp r0, #5\n\t"
        "	bls _08063BFE\n\t"
        "	b _08063F08\n\t"
        "_08063BFE:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08063C10\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_08063C08: .4byte gActiveBattler\n\t"
        "_08063C0C: .4byte gBattleStruct\n\t"
        "_08063C10: .4byte _08063C14\n\t"
        "_08063C14:\n\t"
        "	.4byte _08063C2C\n\t"
        "	.4byte _08063C58\n\t"
        "	.4byte _08063CA0\n\t"
        "	.4byte _08063DF8\n\t"
        "	.4byte _08063ED8\n\t"
        "	.4byte _08063F60\n\t"
        "_08063C2C:\n\t"
        "	ldr r2, _08063C50\n\t"
        "	ldr r0, _08063C54\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r1, [r0, #0x2c]\n\t"
        "	ldrh r0, [r0, #0x28]\n\t"
        "	lsrs r1, r1, #2\n\t"
        "	cmp r0, r1\n\t"
        "	blo _08063C44\n\t"
        "	b _08063F08\n\t"
        "_08063C44:\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08063C4A\n\t"
        "	b _08063F08\n\t"
        "_08063C4A:\n\t"
        "	movs r7, #1\n\t"
        "	b _08063F0C\n\t"
        "	.align 2, 0\n\t"
        "_08063C50: .4byte gBattleMons\n\t"
        "_08063C54: .4byte gActiveBattler\n\t"
        "_08063C58:\n\t"
        "	mov r0, sb\n\t"
        "	movs r1, #4\n\t"
        "	movs r2, #4\n\t"
        "	bl GetItemEffectParamOffset\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	bne _08063C6C\n\t"
        "	b _08063F08\n\t"
        "_08063C6C:\n\t"
        "	ldr r2, _08063C98\n\t"
        "	ldr r0, _08063C9C\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r1, r0, r2\n\t"
        "	ldrh r2, [r1, #0x28]\n\t"
        "	cmp r2, #0\n\t"
        "	bne _08063C80\n\t"
        "	b _08063F08\n\t"
        "_08063C80:\n\t"
        "	ldrh r3, [r1, #0x2c]\n\t"
        "	lsrs r0, r3, #2\n\t"
        "	cmp r2, r0\n\t"
        "	blo _08063C4A\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, r3, r0\n\t"
        "	adds r1, r5, r4\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bgt _08063C96\n\t"
        "	b _08063F08\n\t"
        "_08063C96:\n\t"
        "	b _08063C4A\n\t"
        "	.align 2, 0\n\t"
        "_08063C98: .4byte gBattleMons\n\t"
        "_08063C9C: .4byte gActiveBattler\n\t"
        "_08063CA0:\n\t"
        "	ldr r3, _08063DEC\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r2, _08063DF0\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r1, [r5, #3]\n\t"
        "	movs r6, #0x20\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063CE4\n\t"
        "	ldr r1, _08063DF4\n\t"
        "	ldrb r4, [r3]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r4, r0\n\t"
        "	adds r1, #0x4c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #7\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063CE4\n\t"
        "	lsrs r1, r4, #1\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xc6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r7, #1\n\t"
        "_08063CE4:\n\t"
        "	ldrb r1, [r5, #3]\n\t"
        "	movs r6, #0x10\n\t"
        "	movs r0, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063D1E\n\t"
        "	ldr r1, _08063DF4\n\t"
        "	ldrb r4, [r3]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r4, r0\n\t"
        "	adds r1, #0x4c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08063D0E\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08063D1E\n\t"
        "_08063D0E:\n\t"
        "	lsrs r1, r4, #1\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xc6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r7, #1\n\t"
        "_08063D1E:\n\t"
        "	ldrb r1, [r5, #3]\n\t"
        "	movs r6, #8\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063D50\n\t"
        "	ldr r1, _08063DF4\n\t"
        "	ldrb r4, [r3]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r4, r0\n\t"
        "	adds r1, #0x4c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063D50\n\t"
        "	lsrs r1, r4, #1\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xc6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r7, #1\n\t"
        "_08063D50:\n\t"
        "	ldrb r1, [r5, #3]\n\t"
        "	movs r6, #4\n\t"
        "	movs r0, #4\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063D82\n\t"
        "	ldr r1, _08063DF4\n\t"
        "	ldrb r4, [r3]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r4, r0\n\t"
        "	adds r1, #0x4c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x20\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063D82\n\t"
        "	lsrs r1, r4, #1\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xc6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r7, #1\n\t"
        "_08063D82:\n\t"
        "	ldrb r1, [r5, #3]\n\t"
        "	movs r6, #2\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063DB4\n\t"
        "	ldr r1, _08063DF4\n\t"
        "	ldrb r4, [r3]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r4, r0\n\t"
        "	adds r1, #0x4c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063DB4\n\t"
        "	lsrs r1, r4, #1\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xc6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r7, #1\n\t"
        "_08063DB4:\n\t"
        "	ldrb r1, [r5, #3]\n\t"
        "	movs r4, #1\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08063DC2\n\t"
        "	b _08063F08\n\t"
        "_08063DC2:\n\t"
        "	ldr r1, _08063DF4\n\t"
        "	ldrb r3, [r3]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r3, r0\n\t"
        "	adds r1, #0x50\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #7\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08063DDA\n\t"
        "	b _08063F08\n\t"
        "_08063DDA:\n\t"
        "	lsrs r1, r3, #1\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xc6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	orrs r0, r4\n\t"
        "	strb r0, [r1]\n\t"
        "	b _08063C4A\n\t"
        "	.align 2, 0\n\t"
        "_08063DEC: .4byte gActiveBattler\n\t"
        "_08063DF0: .4byte gBattleStruct\n\t"
        "_08063DF4: .4byte gBattleMons\n\t"
        "_08063DF8:\n\t"
        "	ldr r4, _08063ECC\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r3, _08063ED0\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, _08063ED4\n\t"
        "	ldrb r2, [r4]\n\t"
        "	lsls r0, r2, #3\n\t"
        "	subs r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #0x16]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063F08\n\t"
        "	ldrb r1, [r5]\n\t"
        "	movs r6, #0xf\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063E38\n\t"
        "	lsrs r2, r2, #1\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r2, r2, r0\n\t"
        "	adds r2, #0xc6\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #1\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "_08063E38:\n\t"
        "	ldrb r1, [r5, #1]\n\t"
        "	movs r7, #0xf0\n\t"
        "	adds r0, r7, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063E56\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #2\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "_08063E56:\n\t"
        "	ldrb r1, [r5, #1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063E72\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "_08063E72:\n\t"
        "	ldrb r1, [r5, #2]\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063E8E\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #8\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "_08063E8E:\n\t"
        "	ldrb r1, [r5, #2]\n\t"
        "	adds r0, r7, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063EAA\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x20\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "_08063EAA:\n\t"
        "	ldrb r1, [r5]\n\t"
        "	movs r0, #0x30\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08063EB6\n\t"
        "	b _08063C4A\n\t"
        "_08063EB6:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	b _08063C4A\n\t"
        "	.align 2, 0\n\t"
        "_08063ECC: .4byte gActiveBattler\n\t"
        "_08063ED0: .4byte gBattleStruct\n\t"
        "_08063ED4: .4byte gDisableStructs\n\t"
        "_08063ED8:\n\t"
        "	ldr r4, _08063F40\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	ldr r2, _08063F44\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #0x16]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08063F08\n\t"
        "	ldr r0, _08063F48\n\t"
        "	lsls r1, r3, #1\n\t"
        "	adds r1, r1, r3\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #4]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08063F08\n\t"
        "	b _08063C4A\n\t"
        "_08063F08:\n\t"
        "	cmp r7, #0\n\t"
        "	beq _08063F54\n\t"
        "_08063F0C:\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	bl BtlController_EmitTwoReturnValues\n\t"
        "	ldr r0, _08063F40\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, _08063F4C\n\t"
        "	ldr r1, [r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc0\n\t"
        "	mov r1, sb\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _08063F50\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #0x18]\n\t"
        "	adds r0, #0x48\n\t"
        "	ldr r2, [sp]\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	b _08063F62\n\t"
        "	.align 2, 0\n\t"
        "_08063F40: .4byte gActiveBattler\n\t"
        "_08063F44: .4byte gDisableStructs\n\t"
        "_08063F48: .4byte gSideTimers\n\t"
        "_08063F4C: .4byte gBattleStruct\n\t"
        "_08063F50: .4byte gBattleResources\n\t"
        "_08063F54:\n\t"
        "	movs r0, #1\n\t"
        "	add r8, r0\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #3\n\t"
        "	bgt _08063F60\n\t"
        "	b _08063B56\n\t"
        "_08063F60:\n\t"
        "	movs r0, #0\n\t"
        "_08063F62:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}
#else
bool8 ShouldUseItem(void)
{
    struct Pokemon *party;
    s32 i;
    u8 validMons = 0;
    bool8 shouldUse = FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_RIGHT)
        return FALSE;

    battlerSide = GetBattlerSide(gActiveBattler);
    if (battlerSide == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) != 0
            && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
            && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
        {
            validMons++;
        }
    }

    for (i = 0; i < MAX_TRAINER_ITEMS; i++)
    {
        u16 item;
        const u8 *itemEffects;
        u8 paramOffset;
        u8 battlerSide;

        if (i != 0 && validMons > (gBattleResources->battleHistory->itemsNo - i) + 1)
            continue;
        item = gBattleResources->battleHistory->trainerItems[i];
        if (item == ITEM_NONE)
            continue;
        if (gItemEffectTable[item - ITEM_POTION] == NULL)
            continue;

        if (item == ITEM_ENIGMA_BERRY)
            itemEffects = gSaveBlock1Ptr->enigmaBerry.itemEffect;
        else
            itemEffects = gItemEffectTable[item - ITEM_POTION];

        *(gBattleStruct->AI_itemType + gActiveBattler / 2) = GetAI_ItemType(item, itemEffects);

        switch (*(gBattleStruct->AI_itemType + gActiveBattler / 2))
        {
        case AI_ITEM_FULL_RESTORE:
            if (gBattleMons[gActiveBattler].hp >= gBattleMons[gActiveBattler].maxHP / 4)
                break;
            if (gBattleMons[gActiveBattler].hp == 0)
                break;
            shouldUse = TRUE;
            break;
        case AI_ITEM_HEAL_HP:
            paramOffset = GetItemEffectParamOffset(item, 4, ITEM4_HEAL_HP);
            if (paramOffset == 0)
                break;
            if (gBattleMons[gActiveBattler].hp == 0)
                break;
            if (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 4 || gBattleMons[gActiveBattler].maxHP - gBattleMons[gActiveBattler].hp > itemEffects[paramOffset])
                shouldUse = TRUE;
            break;
        case AI_ITEM_CURE_CONDITION:
            *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) = 0;
            if (itemEffects[3] & ITEM3_SLEEP && gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_HEAL_SLEEP);
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_POISON && (gBattleMons[gActiveBattler].status1 & STATUS1_POISON
                                               || gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_POISON))
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_HEAL_POISON);
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_BURN && gBattleMons[gActiveBattler].status1 & STATUS1_BURN)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_HEAL_BURN);
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_FREEZE && gBattleMons[gActiveBattler].status1 & STATUS1_FREEZE)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_HEAL_FREEZE);
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_PARALYSIS && gBattleMons[gActiveBattler].status1 & STATUS1_PARALYSIS)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_HEAL_PARALYSIS);
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_CONFUSION && gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_HEAL_CONFUSION);
                shouldUse = TRUE;
            }
            break;
        case AI_ITEM_X_STAT:
            *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) = 0;
            if (gDisableStructs[gActiveBattler].isFirstTurn == 0)
                break;
            if (itemEffects[0] & ITEM0_X_ATTACK)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_X_ATTACK);
            if (itemEffects[1] & ITEM1_X_DEFEND)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_X_DEFEND);
            if (itemEffects[1] & ITEM1_X_SPEED)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_X_SPEED);
            if (itemEffects[2] & ITEM2_X_SPATK)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_X_SPATK);
            if (itemEffects[2] & ITEM2_X_ACCURACY)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_X_ACCURACY);
            if (itemEffects[0] & ITEM0_DIRE_HIT)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= (1 << AI_DIRE_HIT);
            shouldUse = TRUE;
            break;
        case AI_ITEM_GUARD_SPEC:
            battlerSide = GetBattlerSide(gActiveBattler);
            if (gDisableStructs[gActiveBattler].isFirstTurn != 0 && gSideTimers[battlerSide].mistTimer == 0)
                shouldUse = TRUE;
            break;
        case AI_ITEM_NOT_RECOGNIZABLE:
            return FALSE;
        }

        if (shouldUse)
        {
            BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_USE_ITEM, 0);
            *(gBattleStruct->chosenItem + (gActiveBattler / 2) * 2) = item;
            gBattleResources->battleHistory->trainerItems[i] = ITEM_NONE;
            return shouldUse;
        }
    }

    return FALSE;
}
#endif

