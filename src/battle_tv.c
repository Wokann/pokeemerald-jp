#include "global.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_tv.h"
#include "tv.h"
#include "constants/battle.h"
#include "constants/pokemon.h"
#include "constants/moves.h"

// this file's functions (first batch: JP tail functions)
// AddMovePoints (0x0817E530) still lives in asm/battle_tv.s; the US static
// helper is referenced as a global symbol by the still-asm callers there.
extern void AddMovePoints(u8 caseId, u16 arg1, u8 arg2, u8 arg3);

#define TABLE_END ((u16)-1)

enum {
    PTS_MOVE_EFFECT,
    PTS_EFFECTIVENESS,
    PTS_SET_UP, // Broadly. Used by Wish, Future Sight, Ingrain, etc.
    PTS_RAIN,
    PTS_SUN,
    PTS_SANDSTORM,
    PTS_HAIL,
    PTS_ELECTRIC,
    PTS_STATUS_DMG,
    PTS_STATUS,
    PTS_SPIKES,
    PTS_WATER_SPORT,
    PTS_MUD_SPORT,
    PTS_REFLECT,
    PTS_LIGHT_SCREEN,
    PTS_SAFEGUARD,
    PTS_MIST,
    PTS_BREAK_WALL,
    PTS_CRITICAL_HIT,
    PTS_FAINT,
    PTS_FAINT_SET_UP,
    PTS_FLINCHED,
    PTS_STAT_INCREASE_1,
    PTS_STAT_INCREASE_2,
    PTS_STAT_DECREASE_SELF,
    PTS_STAT_DECREASE_1,
    PTS_STAT_DECREASE_2,
    PTS_STAT_INCREASE_NOT_SELF,
};

enum {
    FNT_NONE,
    FNT_CURSE,
    FNT_LEECH_SEED,
    FNT_POISON,
    FNT_BURN,
    FNT_NIGHTMARE,
    FNT_WRAP,
    FNT_SPIKES,
    FNT_FUTURE_SIGHT,
    FNT_DOOM_DESIRE,
    FNT_PERISH_SONG,
    FNT_DESTINY_BOND,
    FNT_CONFUSION,
    FNT_EXPLOSION,
    FNT_RECOIL,
    FNT_OTHER,
};

// JP data tables stay in the ROM data region; bound via ld aliases.
extern const u16 sSpecialBattleStrings[];
extern const u16 sVariableDmgMoves[];

bool8 IsNotSpecialBattleString(u16 stringId)
{
    s32 i = 0;

    do
    {
        if (sSpecialBattleStrings[i] == stringId)
            break;
        i++;
    } while (sSpecialBattleStrings[i] != TABLE_END);

    if (sSpecialBattleStrings[i] == TABLE_END)
        return TRUE;
    else
        return FALSE;
}

void BattleTv_SetDataBasedOnMove(u16 move, u16 weatherFlags, struct DisableStruct *disableStructPtr)
{
    struct BattleTv *tvPtr;
    u32 atkSide, defSide;
    u8 moveSlot;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    tvPtr = &gBattleStruct->tv;

    atkSide = GetBattlerSide(gBattlerAttacker);
    defSide = GetBattlerSide(gBattlerTarget);
    moveSlot = GetBattlerMoveSlotId(gBattlerAttacker, move);

    if (moveSlot >= MAX_MON_MOVES)
    {
        tvPtr->side[atkSide].faintCause = FNT_OTHER;
        return;
    }

    tvPtr->pos[defSide][GetBattlerPosition(gBattlerAttacker) / 2].attackedByMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
    tvPtr->pos[defSide][GetBattlerPosition(gBattlerAttacker) / 2].attackedByMoveSlot = moveSlot;
    tvPtr->side[atkSide].usedMoveSlot = moveSlot;
    AddMovePoints(PTS_MOVE_EFFECT, moveSlot, gBattleMoves[move].effect, 0);
    AddPointsBasedOnWeather(weatherFlags, move, moveSlot);
    if (disableStructPtr->chargeTimer != 0)
        AddMovePoints(PTS_ELECTRIC, move, moveSlot, 0);

    if (move == MOVE_WISH)
    {
        tvPtr->side[atkSide].wishMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide].wishMoveSlot = moveSlot;
    }
    if (move == MOVE_SELF_DESTRUCT || move == MOVE_EXPLOSION)
    {
        tvPtr->side[atkSide ^ BIT_SIDE].explosionMonId = gBattlerPartyIndexes[gBattlerAttacker] + 1;
        tvPtr->side[atkSide ^ BIT_SIDE].explosionMoveSlot = moveSlot;
        tvPtr->side[atkSide ^ BIT_SIDE].faintCause = FNT_EXPLOSION;
        tvPtr->side[atkSide ^ BIT_SIDE].explosion = TRUE;
    }

    AddMovePoints(PTS_REFLECT,      gBattleMoves[move].type, gBattleMoves[move].power, 0);
    AddMovePoints(PTS_LIGHT_SCREEN, gBattleMoves[move].type, gBattleMoves[move].power, 0);
    AddMovePoints(PTS_WATER_SPORT,  gBattleMoves[move].type, 0,                        0);
    AddMovePoints(PTS_MUD_SPORT,    gBattleMoves[move].type, 0,                        0);
}

void BattleTv_SetDataBasedOnAnimation(u8 animationId)
{
    struct BattleTv *tvPtr;
    u32 atkSide;

    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
        return;

    tvPtr = &gBattleStruct->tv;
    atkSide = GetBattlerSide(gBattlerAttacker);
    switch (animationId)
    {
    case B_ANIM_FUTURE_SIGHT_HIT:
        if (tvPtr->side[atkSide].futureSightMonId != 0)
        {
            AddMovePoints(PTS_SET_UP, 0, atkSide,
                        (tvPtr->side[atkSide].futureSightMonId - 1) * 4 + tvPtr->side[atkSide].futureSightMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_FUTURE_SIGHT;
        }
        break;
    case B_ANIM_DOOM_DESIRE_HIT:
        if (tvPtr->side[atkSide].doomDesireMonId != 0)
        {
            AddMovePoints(PTS_SET_UP, 1, atkSide,
                        (tvPtr->side[atkSide].doomDesireMonId - 1) * 4 + tvPtr->side[atkSide].doomDesireMoveSlot);
            tvPtr->side[atkSide].faintCause = FNT_DOOM_DESIRE;
        }
        break;
    }
}

bool8 ShouldCalculateDamage(u16 move, s32 *dmg, u16 *powerOverride)
{
    if (gBattleMoves[move].power == 0)
    {
        *dmg = 0;
        return FALSE;
    }
    else
    {
        s32 i = 0;
        do
        {
            if (move == sVariableDmgMoves[i])
                break;
            i++;
        } while (sVariableDmgMoves[i] != TABLE_END);

        if (sVariableDmgMoves[i] != TABLE_END)
        {
            *dmg = 0;
            return FALSE;
        }
        else if (move == MOVE_PSYWAVE)
        {
            *dmg = gBattleMons[gBattlerAttacker].level;
            *dmg /= 2;
            return FALSE;
        }
        else if (move == MOVE_MAGNITUDE)
        {
            *powerOverride = 10;
            return TRUE;
        }
        else
        {
            return TRUE;
        }
    }
}

void BattleTv_ClearExplosionFaintCause(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        struct BattleTv *tvPtr = &gBattleStruct->tv;

        tvPtr->side[B_SIDE_PLAYER].faintCause = FNT_NONE;
        tvPtr->side[B_SIDE_OPPONENT].faintCause = FNT_NONE;

        tvPtr->side[B_SIDE_PLAYER].faintCauseMonId = 0;
        tvPtr->side[B_SIDE_OPPONENT].faintCauseMonId = 0;

        tvPtr->side[B_SIDE_PLAYER].explosionMonId = 0;
        tvPtr->side[B_SIDE_OPPONENT].explosionMonId = 0;

        tvPtr->side[B_SIDE_PLAYER].explosionMoveSlot = 0;
        tvPtr->side[B_SIDE_OPPONENT].explosionMoveSlot = 0;

        tvPtr->side[B_SIDE_PLAYER].explosion = FALSE;
        tvPtr->side[B_SIDE_OPPONENT].explosion = FALSE;
    }
}

u8 GetBattlerMoveSlotId(u8 battler, u16 move)
{
    s32 i;
    struct Pokemon *party;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    i = 0;
    while (1)
    {
        if (i >= MAX_MON_MOVES)
            break;
        if (GetMonData3(&party[gBattlerPartyIndexes[battler]], MON_DATA_MOVE1 + i, NULL) == move)
            break;
        i++;
    }

    return i;
}

void AddPointsBasedOnWeather(u16 weatherFlags, u16 move, u8 moveSlot)
{
    if (weatherFlags & B_WEATHER_RAIN)
        AddMovePoints(PTS_RAIN, move, moveSlot, 0);
    else if (weatherFlags & B_WEATHER_SUN)
        AddMovePoints(PTS_SUN, move, moveSlot, 0);
    else if (weatherFlags & B_WEATHER_SANDSTORM)
        AddMovePoints(PTS_SANDSTORM, move, moveSlot, 0);
    else if (weatherFlags & B_WEATHER_HAIL)
        AddMovePoints(PTS_HAIL, move, moveSlot, 0);
}

void AddPointsOnFainting(bool8 targetFainted)
{
    struct BattleTv *tvPtr = &gBattleStruct->tv;
    u32 atkSide = GetBattlerSide(gBattlerAttacker);
    u32 defSide = GetBattlerSide(gBattlerTarget);
    u32 atkArrId = tvPtr->side[atkSide].faintCauseMonId;
    s32 i;

    if (tvPtr->side[atkSide].faintCause != FNT_NONE)
    {
        switch (tvPtr->side[atkSide].faintCause)
        {
        case FNT_CURSE:
            if (tvPtr->pos[atkSide][atkArrId].curseMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].curseMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].curseMoveSlot);
            }
            break;
        case FNT_LEECH_SEED:
            if (tvPtr->pos[atkSide][atkArrId].leechSeedMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].leechSeedMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].leechSeedMoveSlot);
            }
            break;
        case FNT_POISON:
            if (tvPtr->mon[atkSide][atkArrId].psnMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].psnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].psnMoveSlot);
            }
            if (tvPtr->mon[atkSide][atkArrId].badPsnMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].badPsnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].badPsnMoveSlot);
            }
            break;
        case FNT_BURN:
            if (tvPtr->mon[atkSide][atkArrId].brnMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->mon[atkSide][atkArrId].brnMonId - 1) * 4 + tvPtr->mon[atkSide][atkArrId].brnMoveSlot);
            }
            break;
        case FNT_NIGHTMARE:
            if (tvPtr->pos[atkSide][atkArrId].nightmareMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].nightmareMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].nightmareMoveSlot);
            }
            break;
        case FNT_WRAP:
            if (tvPtr->pos[atkSide][atkArrId].wrapMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->pos[atkSide][atkArrId].wrapMonId - 1) * 4 + tvPtr->pos[atkSide][atkArrId].wrapMoveSlot);
            }
            break;
        case FNT_SPIKES:
            if (tvPtr->side[atkSide].spikesMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide].spikesMonId - 1) * 4 + tvPtr->side[atkSide].spikesMoveSlot);
            }
            break;
        case FNT_FUTURE_SIGHT:
            if (tvPtr->side[atkSide].futureSightMonId != 0)
            {
                AddMovePoints(PTS_FAINT_SET_UP, 0, atkSide,
                (tvPtr->side[atkSide].futureSightMonId - 1) * 4 + tvPtr->side[atkSide].futureSightMoveSlot);
            }
            break;
        case FNT_DOOM_DESIRE:
            if (tvPtr->side[atkSide].doomDesireMonId != 0)
            {
                AddMovePoints(PTS_FAINT_SET_UP, 0, atkSide,
                (tvPtr->side[atkSide].doomDesireMonId - 1) * 4 + tvPtr->side[atkSide].doomDesireMoveSlot);
            }
            break;
        case FNT_PERISH_SONG:
            if (tvPtr->side[atkSide].perishSong
                && tvPtr->side[atkSide].perishSongMonId - 1 != gBattlerPartyIndexes[gBattlerAttacker])
            {
                AddMovePoints(PTS_FAINT, 0, atkSide,
                (tvPtr->side[atkSide].perishSongMonId - 1) * 4 + tvPtr->side[atkSide].perishSongMoveSlot);
            }
            if (tvPtr->side[atkSide ^ BIT_SIDE].perishSong)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].perishSongMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].perishSongMoveSlot);
            }
            break;
        case FNT_DESTINY_BOND:
            if (tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].destinyBondMoveSlot);
            }
            break;
        case FNT_CONFUSION:
            for (i = 0; i < 2; i++)
            {
                if (tvPtr->pos[atkSide][i].confusionMonId != 0)
                {
                    AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                    (tvPtr->pos[atkSide][i].confusionMonId - 1) * 4 + tvPtr->pos[atkSide][i].confusionMoveSlot);
                }
            }
            break;
        case FNT_EXPLOSION:
            if (tvPtr->side[atkSide].explosion)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide,
                (tvPtr->side[atkSide].explosionMonId - 1) * 4 + tvPtr->side[atkSide].explosionMoveSlot);
            }
            if (tvPtr->side[atkSide ^ BIT_SIDE].explosion)
            {
                AddMovePoints(PTS_FAINT, 0, atkSide ^ BIT_SIDE,
                (tvPtr->side[atkSide ^ BIT_SIDE].explosionMonId - 1) * 4 + tvPtr->side[atkSide ^ BIT_SIDE].explosionMoveSlot);
            }
            break;
        case FNT_RECOIL:
            if (targetFainted == TRUE)
            {
                AddMovePoints(PTS_FAINT_SET_UP, 0, atkSide,
                (gBattlerPartyIndexes[gBattlerAttacker]) * 4 + tvPtr->side[atkSide].usedMoveSlot);
            }
            break;
        case FNT_OTHER:
            break;
        }
    }
    else
    {
        if (tvPtr->side[defSide].faintCause == FNT_SPIKES)
        {
            if (tvPtr->side[defSide].spikesMonId != 0)
            {
                AddMovePoints(PTS_FAINT, 0, defSide ^ BIT_SIDE,
                (tvPtr->side[defSide].spikesMonId - 1) * 4 + tvPtr->side[defSide].spikesMoveSlot);
            }
        }
        else
        {
            AddMovePoints(PTS_FAINT_SET_UP, 0, atkSide,
            (gBattlerPartyIndexes[gBattlerAttacker]) * 4 + tvPtr->side[atkSide].usedMoveSlot);
        }
    }
}

void TrySetBattleSeminarShow(void)
{
    s32 i;
    s32 dmgByMove[MAX_MON_MOVES];
    u16 powerOverride;
    u16 currMoveSaved;

    if (gBattleTypeFlags & (BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        return;
    else if (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT)
        return;
    else if (gBattleMons[gBattlerAttacker].statStages[STAT_ACC] < DEFAULT_STAT_STAGE)
        return;
    else if (gBattleMons[gBattlerTarget].statStages[STAT_EVASION] > DEFAULT_STAT_STAGE)
        return;
    else if (gCurrentMove == MOVE_HIDDEN_POWER || gCurrentMove == MOVE_WEATHER_BALL)
        return;
    else if (gBattleTypeFlags & (BATTLE_TYPE_PALACE | BATTLE_TYPE_PIKE | BATTLE_TYPE_PYRAMID))
        return;
    else if (gBattleMoves[gBattleMons[gBattlerAttacker].moves[gMoveSelectionCursor[gBattlerAttacker]]].power == 0)
        return;

    i = 0;
    currMoveSaved = gBattleMons[gBattlerAttacker].moves[gMoveSelectionCursor[gBattlerAttacker]];
    do
    {
        if (currMoveSaved == sVariableDmgMoves[i])
            break;
        i++;
    } while (sVariableDmgMoves[i] != TABLE_END);

    if (sVariableDmgMoves[i] != TABLE_END)
        return;

    dmgByMove[gMoveSelectionCursor[gBattlerAttacker]] = gBattleMoveDamage;
    currMoveSaved = gCurrentMove;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gCurrentMove = gBattleMons[gBattlerAttacker].moves[i];
        powerOverride = 0;
        if (ShouldCalculateDamage(gCurrentMove, &dmgByMove[i], &powerOverride))
        {
            u8 moveResultFlags;
            u16 sideStatus = gSideStatuses[GET_BATTLER_SIDE(gBattlerTarget)];
            gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBattlerAttacker], &gBattleMons[gBattlerTarget], gCurrentMove,
                                                    sideStatus, powerOverride,
                                                    0, gBattlerAttacker, gBattlerTarget);

            if (gStatuses3[gBattlerAttacker] & STATUS3_CHARGED_UP && gBattleMoves[gCurrentMove].type == TYPE_ELECTRIC)
                gBattleMoveDamage *= 2;
            if (gProtectStructs[gBattlerAttacker].helpingHand)
                gBattleMoveDamage = gBattleMoveDamage * 15 / 10;

            moveResultFlags = TypeCalc(gCurrentMove, gBattlerAttacker, gBattlerTarget);
            dmgByMove[i] = gBattleMoveDamage;
            if (dmgByMove[i] == 0 && !(moveResultFlags & MOVE_RESULT_NO_EFFECT))
                dmgByMove[i] = 1;
        }
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (i != gMoveSelectionCursor[gBattlerAttacker] && dmgByMove[i] > dmgByMove[gMoveSelectionCursor[gBattlerAttacker]])
        {
            u16 opponentSpecies, playerSpecies;
            s32 bestMoveId;

            if (gMoveSelectionCursor[gBattlerAttacker] != 0)
                bestMoveId = 0;
            else
                bestMoveId = 1;

            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (i != gMoveSelectionCursor[gBattlerAttacker] && dmgByMove[i] > dmgByMove[bestMoveId])
                    bestMoveId = i;
            }

            opponentSpecies = GetMonData3(&gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]], MON_DATA_SPECIES, NULL);
            playerSpecies   = GetMonData3(&gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]], MON_DATA_SPECIES, NULL);
            TryPutBattleSeminarOnAir(opponentSpecies, playerSpecies, gMoveSelectionCursor[gBattlerAttacker], gBattleMons[gBattlerAttacker].moves, gBattleMons[gBattlerAttacker].moves[bestMoveId]);
            break;
        }
    }

    gBattleMoveDamage = dmgByMove[gMoveSelectionCursor[gBattlerAttacker]];
    gCurrentMove = currMoveSaved;
}
