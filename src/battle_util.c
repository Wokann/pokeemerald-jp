#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_scripts.h"
#include "battle_script_commands.h"
#include "battle_util.h"
#include "item.h"
#include "link.h"
#include "random.h"
#include "sound.h"
#include "safari_zone.h"
#include "util.h"
#include "constants/battle_script_commands.h"
#include "constants/battle.h"
#include "constants/global.h"
#include "constants/abilities.h"
#include "constants/battle_anim.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/characters.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/weather.h"

extern const u16 sSoundMovesTable[];
extern const u8 *const gBattlescriptsForBallThrow[];
extern const u8 *const gBattlescriptsForRunningByItem[];
extern const u8 *const gBattlescriptsForUsingItem[];
extern const u8 *const gBattlescriptsForSafariActions[];
extern const u8 sPkblToEscapeFactor[][3];
extern const u8 sGoNearCounterToCatchFactor[];
extern const u8 sGoNearCounterToEscapeFactor[];
extern void (*const sTurnActionsFuncsTable[])(void); // JP data 0x082EC600 (14 B_ACTION_* entries)
void sub_0803DCCC(void);

u8 GetBattlerForBattleScript(u8 caseId)
{
    u8 ret = 0;
    switch (caseId)
    {
    case BS_TARGET:
        ret = gBattlerTarget;
        break;
    case BS_ATTACKER:
        ret = gBattlerAttacker;
        break;
    case BS_EFFECT_BATTLER:
        ret = gEffectBattler;
        break;
    case BS_BATTLER_0:
        ret = 0;
        break;
    case BS_SCRIPTING:
        ret = gBattleScripting.battler;
        break;
    case BS_FAINTED:
    case BS_FAINTED_LINK_MULTIPLE_1:
        ret = gBattlerFainted;
        break;
    case BS_ATTACKER_WITH_PARTNER:
    case BS_FAINTED_LINK_MULTIPLE_2:
    case BS_ATTACKER_SIDE:
    case BS_NOT_ATTACKER_SIDE:
    case BS_PLAYER1:
        ret = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        break;
    case BS_OPPONENT1:
        ret = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        break;
    case BS_PLAYER2:
        ret = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        break;
    case BS_OPPONENT2:
        ret = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
        break;
    }
    return ret;
}

void PressurePPLose(u8 target, u8 attacker, u16 move)
{
    int moveIndex;

    if (gBattleMons[target].ability != ABILITY_PRESSURE)
        return;

    for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (gBattleMons[attacker].moves[moveIndex] == move)
            break;
    }

    if (moveIndex == MAX_MON_MOVES)
        return;

    if (gBattleMons[attacker].pp[moveIndex] != 0)
        gBattleMons[attacker].pp[moveIndex]--;

    if (MOVE_IS_PERMANENT(attacker, moveIndex))
    {
        gActiveBattler = attacker;
        BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_PPMOVE1_BATTLE + moveIndex, 0, 1, &gBattleMons[gActiveBattler].pp[moveIndex]);
        MarkBattlerForControllerExec(gActiveBattler);
    }
}

void PressurePPLoseOnUsingImprison(u8 attacker)
{
    int i, j;
    int imprisonPos = MAX_MON_MOVES;
    u8 atkSide = GetBattlerSide(attacker);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (atkSide != GetBattlerSide(i) && gBattleMons[i].ability == ABILITY_PRESSURE)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[attacker].moves[j] == MOVE_IMPRISON)
                    break;
            }
            if (j != MAX_MON_MOVES)
            {
                imprisonPos = j;
                if (gBattleMons[attacker].pp[j] != 0)
                    gBattleMons[attacker].pp[j]--;
            }
        }
    }

    if (imprisonPos != MAX_MON_MOVES && MOVE_IS_PERMANENT(attacker, imprisonPos))
    {
        gActiveBattler = attacker;
        BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_PPMOVE1_BATTLE + imprisonPos, 0, 1, &gBattleMons[gActiveBattler].pp[imprisonPos]);
        MarkBattlerForControllerExec(gActiveBattler);
    }
}

void PressurePPLoseOnUsingPerishSong(u8 attacker)
{
    int i, j;
    int perishSongPos = MAX_MON_MOVES;

    for (i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].ability == ABILITY_PRESSURE && i != attacker)
        {
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (gBattleMons[attacker].moves[j] == MOVE_PERISH_SONG)
                    break;
            }
            if (j != MAX_MON_MOVES)
            {
                perishSongPos = j;
                if (gBattleMons[attacker].pp[j] != 0)
                    gBattleMons[attacker].pp[j]--;
            }
        }
    }

    if (perishSongPos != MAX_MON_MOVES && MOVE_IS_PERMANENT(attacker, perishSongPos))
    {
        gActiveBattler = attacker;
        BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_PPMOVE1_BATTLE + perishSongPos, 0, 1, &gBattleMons[gActiveBattler].pp[perishSongPos]);
        MarkBattlerForControllerExec(gActiveBattler);
    }
}

void MarkAllBattlersForControllerExec(void)
{
    int i;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        for (i = 0; i < gBattlersCount; i++)
            MARK_BATTLE_CONTROLLER_MESSAGE_OUTBOUND_OVER_LINK(i);
    }
    else
    {
        for (i = 0; i < gBattlersCount; i++)
            MARK_BATTLE_CONTROLLER_ACTIVE_ON_LOCAL(i);
    }
}

void MarkBattlerForControllerExec(u8 battler)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        MARK_BATTLE_CONTROLLER_MESSAGE_OUTBOUND_OVER_LINK(battler);
    else
        MARK_BATTLE_CONTROLLER_ACTIVE_ON_LOCAL(battler);
}

void MarkBattlerReceivedLinkData(u8 battler)
{
    s32 i;

    for (i = 0; i < GetLinkPlayerCount(); i++)
        MARK_BATTLE_CONTROLLER_ACTIVE_FOR_PLAYER(battler, i);

    MARK_BATTLE_CONTROLLER_MESSAGE_SYNCHRONIZED_OVER_LINK(battler);
}

void CancelMultiTurnMoves(u8 battler)
{
    gBattleMons[battler].status2 &= ~STATUS2_MULTIPLETURNS;
    gBattleMons[battler].status2 &= ~STATUS2_LOCK_CONFUSE;
    gBattleMons[battler].status2 &= ~STATUS2_UPROAR;
    gBattleMons[battler].status2 &= ~STATUS2_BIDE;

    gStatuses3[battler] &= ~STATUS3_SEMI_INVULNERABLE;

    gDisableStructs[battler].rolloutTimer = 0;
    gDisableStructs[battler].furyCutterCounter = 0;
}

bool8 WasUnableToUseMove(u8 battler)
{
    if (gProtectStructs[battler].prlzImmobility
        || gProtectStructs[battler].targetNotAffected
        || gProtectStructs[battler].usedImprisonedMove
        || gProtectStructs[battler].loveImmobility
        || gProtectStructs[battler].usedDisabledMove
        || gProtectStructs[battler].usedTauntedMove
        || gProtectStructs[battler].flag2Unknown
        || gProtectStructs[battler].flinchImmobility
        || gProtectStructs[battler].confusionSelfDmg)
        return TRUE;
    else
        return FALSE;
}

void PrepareStringBattle(u16 stringId, u8 battler)
{
    gActiveBattler = battler;
    BtlController_EmitPrintString(B_COMM_TO_CONTROLLER, stringId);
    MarkBattlerForControllerExec(gActiveBattler);
}

void ResetSentPokesToOpponentValue(void)
{
    s32 i;
    u32 bits = 0;

    gSentPokesToOpponent[0] = 0;
    gSentPokesToOpponent[1] = 0;

    for (i = 0; i < gBattlersCount; i += 2)
        bits |= gBitTable[gBattlerPartyIndexes[i]];

    for (i = 1; i < gBattlersCount; i += 2)
        gSentPokesToOpponent[(i & BIT_FLANK) >> 1] = bits;
}

void OpponentSwitchInResetSentPokesToOpponentValue(u8 battler)
{
    s32 i = 0;
    u32 bits = 0;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        u8 flank = ((battler & BIT_FLANK) >> 1);
        gSentPokesToOpponent[flank] = 0;

        for (i = 0; i < gBattlersCount; i += 2)
        {
            if (!(gAbsentBattlerFlags & gBitTable[i]))
                bits |= gBitTable[gBattlerPartyIndexes[i]];
        }
        gSentPokesToOpponent[flank] = bits;
    }
}

void UpdateSentPokesToOpponentValue(u8 battler)
{
    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        OpponentSwitchInResetSentPokesToOpponentValue(battler);
    }
    else
    {
        s32 i;
        for (i = 1; i < gBattlersCount; i++)
            gSentPokesToOpponent[(i & BIT_FLANK) >> 1] |= gBitTable[gBattlerPartyIndexes[battler]];
    }
}

void BattleScriptPush(const u8 *bsPtr)
{
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = bsPtr;
}

void BattleScriptPushCursor(void)
{
    gBattleResources->battleScriptsStack->ptr[gBattleResources->battleScriptsStack->size++] = gBattlescriptCurrInstr;
}

void HandleAction_RunBattleScript(void)
{
    gBattlescriptCurrInstr = gBattleResources->battleScriptsStack->ptr[--gBattleResources->battleScriptsStack->size];
}

u8 TrySetCantSelectMoveBattleScript(void)
{
    u8 limitations = 0;
    u16 move = gBattleMons[gActiveBattler].moves[gBattleBufferB[gActiveBattler][2]];
    u8 holdEffect;
    u16 *choicedMove = &gBattleStruct->choicedMove[gActiveBattler];

    if (gDisableStructs[gActiveBattler].disabledMove == move && move != MOVE_NONE)
    {
        gBattleScripting.battler = gActiveBattler;
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingDisabledMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingDisabledMove;
            limitations = 1;
        }
    }

    if (move == gLastMoves[gActiveBattler] && move != MOVE_STRUGGLE && (gBattleMons[gActiveBattler].status2 & STATUS2_TORMENT))
    {
        CancelMultiTurnMoves(gActiveBattler);
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingTormentedMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingTormentedMove;
            limitations++;
        }
    }

    if (gDisableStructs[gActiveBattler].tauntTimer != 0 && gBattleMoves[move].power == 0)
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveTauntInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveTaunt;
            limitations++;
        }
    }

    if (GetImprisonedMovesCount(gActiveBattler, move))
    {
        gCurrentMove = move;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gPalaceSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingImprisonedMoveInPalace;
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingImprisonedMove;
            limitations++;
        }
    }

    if (gBattleMons[gActiveBattler].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[gActiveBattler].holdEffect;
    else
        holdEffect = GetItemHoldEffect(gBattleMons[gActiveBattler].item);

    gPotentialItemEffectBattler = gActiveBattler;

    if (holdEffect == HOLD_EFFECT_CHOICE_BAND && *choicedMove != MOVE_NONE && *choicedMove != MOVE_UNAVAILABLE && *choicedMove != move)
    {
        gCurrentMove = *choicedMove;
        gLastUsedItem = gBattleMons[gActiveBattler].item;
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingNotAllowedMoveChoiceItem;
            limitations++;
        }
    }

    if (gBattleMons[gActiveBattler].pp[gBattleBufferB[gActiveBattler][2]] == 0)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
        {
            gProtectStructs[gActiveBattler].palaceUnableToUseMove = TRUE;
        }
        else
        {
            gSelectionBattleScripts[gActiveBattler] = BattleScript_SelectingMoveWithNoPP;
            limitations++;
        }
    }

    return limitations;
}

u8 CheckMoveLimitations(u8 battler, u8 unusableMoves, u8 check)
{
    u8 holdEffect;
    u16 *choicedMove = &gBattleStruct->choicedMove[battler];
    s32 i;

    if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY)
        holdEffect = gEnigmaBerries[battler].holdEffect;
    else
        holdEffect = GetItemHoldEffect(gBattleMons[battler].item);

    gPotentialItemEffectBattler = battler;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        // No move
        if (gBattleMons[battler].moves[i] == MOVE_NONE && check & MOVE_LIMITATION_ZEROMOVE)
            unusableMoves |= gBitTable[i];
        // No PP
        if (gBattleMons[battler].pp[i] == 0 && check & MOVE_LIMITATION_PP)
            unusableMoves |= gBitTable[i];
        // Disable
        if (gBattleMons[battler].moves[i] == gDisableStructs[battler].disabledMove && check & MOVE_LIMITATION_DISABLED)
            unusableMoves |= gBitTable[i];
        // Torment
        if (gBattleMons[battler].moves[i] == gLastMoves[battler] && check & MOVE_LIMITATION_TORMENTED && gBattleMons[battler].status2 & STATUS2_TORMENT)
            unusableMoves |= gBitTable[i];
        // Taunt
        if (gDisableStructs[battler].tauntTimer && check & MOVE_LIMITATION_TAUNT && gBattleMoves[gBattleMons[battler].moves[i]].power == 0)
            unusableMoves |= gBitTable[i];
        // Imprison
        if (GetImprisonedMovesCount(battler, gBattleMons[battler].moves[i]) && check & MOVE_LIMITATION_IMPRISON)
            unusableMoves |= gBitTable[i];
        // Encore
        if (gDisableStructs[battler].encoreTimer && gDisableStructs[battler].encoredMove != gBattleMons[battler].moves[i])
            unusableMoves |= gBitTable[i];
        // Choice Band
        if (holdEffect == HOLD_EFFECT_CHOICE_BAND && *choicedMove != MOVE_NONE && *choicedMove != MOVE_UNAVAILABLE && *choicedMove != gBattleMons[battler].moves[i])
            unusableMoves |= gBitTable[i];
    }
    return unusableMoves;
}

bool8 AreAllMovesUnusable(void)
{
    u8 unusable = CheckMoveLimitations(gActiveBattler, 0, MOVE_LIMITATIONS_ALL);

    if (unusable == ALL_MOVES_MASK) // All moves are unusable.
    {
        gProtectStructs[gActiveBattler].noValidMoves = TRUE;
        gSelectionBattleScripts[gActiveBattler] = BattleScript_NoMovesLeft;
    }
    else
    {
        gProtectStructs[gActiveBattler].noValidMoves = FALSE;
    }

    return (unusable == ALL_MOVES_MASK);
}

u8 GetImprisonedMovesCount(u8 battler, u16 move)
{
    s32 i;
    u8 imprisonedMoves = 0;
    u8 battlerSide = GetBattlerSide(battler);

    for (i = 0; i < gBattlersCount; i++)
    {
        if (battlerSide != GetBattlerSide(i) && gStatuses3[i] & STATUS3_IMPRISONED_OTHERS)
        {
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                if (move == gBattleMons[i].moves[j])
                    break;
            }
            if (j < MAX_MON_MOVES)
                imprisonedMoves++;
        }
    }

    return imprisonedMoves;
}

enum
{
    ENDTURN_ORDER,
    ENDTURN_REFLECT,
    ENDTURN_LIGHT_SCREEN,
    ENDTURN_MIST,
    ENDTURN_SAFEGUARD,
    ENDTURN_WISH,
    ENDTURN_RAIN,
    ENDTURN_SANDSTORM,
    ENDTURN_SUN,
    ENDTURN_HAIL,
    ENDTURN_FIELD_COUNT,
};

u8 DoFieldEndTurnEffects(void)
{
    u8 effect = 0;
    s32 i;

    for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount && gAbsentBattlerFlags & gBitTable[gBattlerAttacker]; gBattlerAttacker++)
    {
    }
    for (gBattlerTarget = 0; gBattlerTarget < gBattlersCount && gAbsentBattlerFlags & gBitTable[gBattlerTarget]; gBattlerTarget++)
    {
    }

    do
    {
        u8 side;

        switch (gBattleStruct->turnCountersTracker)
        {
        case ENDTURN_ORDER:
            for (i = 0; i < gBattlersCount; i++)
            {
                gBattlerByTurnOrder[i] = i;
            }
            for (i = 0; i < gBattlersCount - 1; i++)
            {
                s32 j;
                for (j = i + 1; j < gBattlersCount; j++)
                {
                    if (GetWhoStrikesFirst(gBattlerByTurnOrder[i], gBattlerByTurnOrder[j], FALSE))
                        SwapTurnOrder(i, j);
                }
            }

            *(&gBattleStruct->turnCountersTracker) = gBattleStruct->turnCountersTracker + 1;
            gBattleStruct->turnSideTracker = 0;
            // fall through
        case ENDTURN_REFLECT:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].reflectBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_REFLECT)
                {
                    if (--gSideTimers[side].reflectTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_REFLECT;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
                        gBattleTextBuff1[1] = B_BUFF_MOVE;
                        gBattleTextBuff1[2] = MOVE_REFLECT;
                        gBattleTextBuff1[3] = 0;
                        gBattleTextBuff1[4] |= B_BUFF_EOS;
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_LIGHT_SCREEN:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].lightscreenBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_LIGHTSCREEN)
                {
                    if (--gSideTimers[side].lightscreenTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_LIGHTSCREEN;
                        BattleScriptExecute(BattleScript_SideStatusWoreOff);
                        gBattleCommunication[MULTISTRING_CHOOSER] = side;
                        gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
                        gBattleTextBuff1[1] = B_BUFF_MOVE;
                        gBattleTextBuff1[2] = MOVE_LIGHT_SCREEN;
                        gBattleTextBuff1[3] = 0;
                        gBattleTextBuff1[4] |= B_BUFF_EOS;
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_MIST:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].mistBattlerId;
                if (gSideTimers[side].mistTimer != 0 && --gSideTimers[side].mistTimer == 0)
                {
                    gSideStatuses[side] &= ~SIDE_STATUS_MIST;
                    BattleScriptExecute(BattleScript_SideStatusWoreOff);
                    gBattleCommunication[MULTISTRING_CHOOSER] = side;
                    gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
                    gBattleTextBuff1[1] = B_BUFF_MOVE;
                    gBattleTextBuff1[2] = MOVE_MIST;
                    gBattleTextBuff1[3] = 0;
                    gBattleTextBuff1[4] |= B_BUFF_EOS;
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_SAFEGUARD:
            while (gBattleStruct->turnSideTracker < 2)
            {
                side = gBattleStruct->turnSideTracker;
                gActiveBattler = gBattlerAttacker = gSideTimers[side].safeguardBattlerId;
                if (gSideStatuses[side] & SIDE_STATUS_SAFEGUARD)
                {
                    if (--gSideTimers[side].safeguardTimer == 0)
                    {
                        gSideStatuses[side] &= ~SIDE_STATUS_SAFEGUARD;
                        BattleScriptExecute(BattleScript_SafeguardEnds);
                        effect++;
                    }
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
                gBattleStruct->turnSideTracker = 0;
            }
            break;
        case ENDTURN_WISH:
            while (gBattleStruct->turnSideTracker < gBattlersCount)
            {
                gActiveBattler = gBattlerByTurnOrder[gBattleStruct->turnSideTracker];
                if (gWishFutureKnock.wishCounter[gActiveBattler] != 0
                 && --gWishFutureKnock.wishCounter[gActiveBattler] == 0
                 && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattlerTarget = gActiveBattler;
                    BattleScriptExecute(BattleScript_WishComesTrue);
                    effect++;
                }
                gBattleStruct->turnSideTracker++;
                if (effect != 0)
                    break;
            }
            if (effect == 0)
            {
                gBattleStruct->turnCountersTracker++;
            }
            break;
        case ENDTURN_RAIN:
            if (gBattleWeather & B_WEATHER_RAIN)
            {
                if (!(gBattleWeather & B_WEATHER_RAIN_PERMANENT))
                {
                    if (--gWishFutureKnock.weatherDuration == 0)
                    {
                        gBattleWeather &= ~B_WEATHER_RAIN_TEMPORARY;
                        gBattleWeather &= ~B_WEATHER_RAIN_DOWNPOUR;
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_STOPPED;
                    }
                    else if (gBattleWeather & B_WEATHER_RAIN_DOWNPOUR)
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOWNPOUR_CONTINUES;
                    }
                    else
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_CONTINUES;
                    }
                }
                else if (gBattleWeather & B_WEATHER_RAIN_DOWNPOUR)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOWNPOUR_CONTINUES;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_RAIN_CONTINUES;
                }

                BattleScriptExecute(BattleScript_RainContinuesOrEnds);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SANDSTORM:
            if (gBattleWeather & B_WEATHER_SANDSTORM)
            {
                if (!(gBattleWeather & B_WEATHER_SANDSTORM_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~B_WEATHER_SANDSTORM_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SANDSTORM;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_SUN:
            if (gBattleWeather & B_WEATHER_SUN)
            {
                if (!(gBattleWeather & B_WEATHER_SUN_PERMANENT) && --gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~B_WEATHER_SUN_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SunlightFaded;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_SunlightContinues;
                }

                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_HAIL:
            if (gBattleWeather & B_WEATHER_HAIL)
            {
                if (--gWishFutureKnock.weatherDuration == 0)
                {
                    gBattleWeather &= ~B_WEATHER_HAIL_TEMPORARY;
                    gBattlescriptCurrInstr = BattleScript_SandStormHailEnds;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_DamagingWeatherContinues;
                }

                gBattleScripting.animArg1 = B_ANIM_HAIL_CONTINUES;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_HAIL;
                BattleScriptExecute(gBattlescriptCurrInstr);
                effect++;
            }
            gBattleStruct->turnCountersTracker++;
            break;
        case ENDTURN_FIELD_COUNT:
            effect++;
            break;
        }
    } while (effect == 0);
    return (gBattleMainFunc != BattleTurnPassed);
}

enum
{
    ENDTURN_INGRAIN,
    ENDTURN_ABILITIES,
    ENDTURN_ITEMS1,
    ENDTURN_LEECH_SEED,
    ENDTURN_POISON,
    ENDTURN_BAD_POISON,
    ENDTURN_BURN,
    ENDTURN_NIGHTMARES,
    ENDTURN_CURSE,
    ENDTURN_WRAP,
    ENDTURN_UPROAR,
    ENDTURN_THRASH,
    ENDTURN_DISABLE,
    ENDTURN_ENCORE,
    ENDTURN_LOCK_ON,
    ENDTURN_CHARGE,
    ENDTURN_TAUNT,
    ENDTURN_YAWN,
    ENDTURN_ITEMS2,
    ENDTURN_BATTLER_COUNT
};

u8 DoBattlerEndTurnEffects(void)
{
    u8 effect = 0;

    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_IGNORE_BIDE);
    while (gBattleStruct->turnEffectsBattlerId < gBattlersCount && gBattleStruct->turnEffectsTracker <= ENDTURN_BATTLER_COUNT)
    {
        gActiveBattler = gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->turnEffectsBattlerId];
        if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
        {
            gBattleStruct->turnEffectsBattlerId++;
        }
        else
        {
            switch (gBattleStruct->turnEffectsTracker)
            {
            case ENDTURN_INGRAIN:  // ingrain
                if ((gStatuses3[gActiveBattler] & STATUS3_ROOTED)
                 && gBattleMons[gActiveBattler].hp != gBattleMons[gActiveBattler].maxHP
                 && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_IngrainTurnHeal);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_ABILITIES:  // end turn abilities
                if (AbilityBattleEffects(ABILITYEFFECT_ENDTURN, gActiveBattler, 0, 0, 0))
                    effect++;
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_ITEMS1:  // item effects
                if (ItemBattleEffects(ITEMEFFECT_NORMAL, gActiveBattler, FALSE))
                    effect++;
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_ITEMS2:  // item effects again
                if (ItemBattleEffects(ITEMEFFECT_NORMAL, gActiveBattler, TRUE))
                    effect++;
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_LEECH_SEED:  // leech seed
                if ((gStatuses3[gActiveBattler] & STATUS3_LEECHSEED)
                 && gBattleMons[gStatuses3[gActiveBattler] & STATUS3_LEECHSEED_BATTLER].hp != 0
                 && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattlerTarget = gStatuses3[gActiveBattler] & STATUS3_LEECHSEED_BATTLER; // Notice gBattlerTarget is actually the HP receiver.
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    gBattleScripting.animArg1 = gBattlerTarget;
                    gBattleScripting.animArg2 = gBattlerAttacker;
                    BattleScriptExecute(BattleScript_LeechSeedTurnDrain);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_POISON:  // poison
                if ((gBattleMons[gActiveBattler].status1 & STATUS1_POISON) && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_BAD_POISON:  // toxic poison
                if ((gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_POISON) && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if ((gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
                        gBattleMons[gActiveBattler].status1 += STATUS1_TOXIC_TURN(1);
                    gBattleMoveDamage *= (gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_COUNTER) >> 8;
                    BattleScriptExecute(BattleScript_PoisonTurnDmg);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_BURN:  // burn
                if ((gBattleMons[gActiveBattler].status1 & STATUS1_BURN) && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 8;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_BurnTurnDmg);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_NIGHTMARES:  // spooky nightmares
                if ((gBattleMons[gActiveBattler].status2 & STATUS2_NIGHTMARE) && gBattleMons[gActiveBattler].hp != 0)
                {
                    if (gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
                    {
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 4;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        BattleScriptExecute(BattleScript_NightmareTurnDmg);
                        effect++;
                    }
                    else
                    {
                        gBattleMons[gActiveBattler].status2 &= ~STATUS2_NIGHTMARE;
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_CURSE:  // curse
                if ((gBattleMons[gActiveBattler].status2 & STATUS2_CURSED) && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 4;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptExecute(BattleScript_CurseTurnDmg);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_WRAP:  // wrap
                if ((gBattleMons[gActiveBattler].status2 & STATUS2_WRAPPED) && gBattleMons[gActiveBattler].hp != 0)
                {
                    gBattleMons[gActiveBattler].status2 -= STATUS2_WRAPPED_TURN(1);
                    if (gBattleMons[gActiveBattler].status2 & STATUS2_WRAPPED)  // damaged by wrap
                    {
                        gBattleScripting.animArg1 = *(gBattleStruct->wrappedMove + gActiveBattler * 2 + 0);
                        gBattleScripting.animArg2 = *(gBattleStruct->wrappedMove + gActiveBattler * 2 + 1);
                        gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
                        gBattleTextBuff1[1] = B_BUFF_MOVE;
                        gBattleTextBuff1[2] = *(gBattleStruct->wrappedMove + gActiveBattler * 2 + 0);
                        gBattleTextBuff1[3] = *(gBattleStruct->wrappedMove + gActiveBattler * 2 + 1);
                        gBattleTextBuff1[4] = EOS;
                        gBattlescriptCurrInstr = BattleScript_WrapTurnDmg;
                        gBattleMoveDamage = gBattleMons[gActiveBattler].maxHP / 16;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                    }
                    else  // broke free
                    {
                        gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
                        gBattleTextBuff1[1] = B_BUFF_MOVE;
                        gBattleTextBuff1[2] = *(gBattleStruct->wrappedMove + gActiveBattler * 2 + 0);
                        gBattleTextBuff1[3] = *(gBattleStruct->wrappedMove + gActiveBattler * 2 + 1);
                        gBattleTextBuff1[4] = EOS;
                        gBattlescriptCurrInstr = BattleScript_WrapEnds;
                    }
                    BattleScriptExecute(gBattlescriptCurrInstr);
                    effect++;
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_UPROAR:  // uproar
                if (gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR)
                {
                    for (gBattlerAttacker = 0; gBattlerAttacker < gBattlersCount; gBattlerAttacker++)
                    {
                        if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
                         && gBattleMons[gBattlerAttacker].ability != ABILITY_SOUNDPROOF)
                        {
                            gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_SLEEP;
                            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
                            gBattleCommunication[MULTISTRING_CHOOSER] = 1;
                            BattleScriptExecute(BattleScript_MonWokeUpInUproar);
                            gActiveBattler = gBattlerAttacker;
                            BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                            MarkBattlerForControllerExec(gActiveBattler);
                            break;
                        }
                    }
                    if (gBattlerAttacker != gBattlersCount)
                    {
                        effect = 2;  // a Pokémon was awaken
                        break;
                    }
                    else
                    {
                        gBattlerAttacker = gActiveBattler;
                        gBattleMons[gActiveBattler].status2 -= STATUS2_UPROAR_TURN(1);
                        if (WasUnableToUseMove(gActiveBattler))
                        {
                            CancelMultiTurnMoves(gActiveBattler);
                            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_ENDS;
                        }
                        else if (gBattleMons[gActiveBattler].status2 & STATUS2_UPROAR)
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_CONTINUES;
                            gBattleMons[gActiveBattler].status2 |= STATUS2_MULTIPLETURNS;
                        }
                        else
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_UPROAR_ENDS;
                            CancelMultiTurnMoves(gActiveBattler);
                        }
                        BattleScriptExecute(BattleScript_PrintUproarOverTurns);
                        effect = 1;
                    }
                }
                if (effect != 2)
                    gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_THRASH:  // thrash
                if (gBattleMons[gActiveBattler].status2 & STATUS2_LOCK_CONFUSE)
                {
                    gBattleMons[gActiveBattler].status2 -= STATUS2_LOCK_CONFUSE_TURN(1);
                    if (WasUnableToUseMove(gActiveBattler))
                        CancelMultiTurnMoves(gActiveBattler);
                    else if (!(gBattleMons[gActiveBattler].status2 & STATUS2_LOCK_CONFUSE)
                     && (gBattleMons[gActiveBattler].status2 & STATUS2_MULTIPLETURNS))
                    {
                        gBattleMons[gActiveBattler].status2 &= ~STATUS2_MULTIPLETURNS;
                        if (!(gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION))
                        {
                            gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_CONFUSION | MOVE_EFFECT_AFFECTS_USER;
                            SetMoveEffect(TRUE, 0);
                            if (gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION)
                                BattleScriptExecute(BattleScript_ThrashConfuses);
                            effect++;
                        }
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_DISABLE:  // disable
                if (gDisableStructs[gActiveBattler].disableTimer != 0)
                {
                    s32 i;
                    for (i = 0; i < MAX_MON_MOVES; i++)
                    {
                        if (gDisableStructs[gActiveBattler].disabledMove == gBattleMons[gActiveBattler].moves[i])
                            break;
                    }
                    if (i == MAX_MON_MOVES)  // Pokémon does not have the disabled move anymore
                    {
                        gDisableStructs[gActiveBattler].disabledMove = MOVE_NONE;
                        gDisableStructs[gActiveBattler].disableTimer = 0;
                    }
                    else if (--gDisableStructs[gActiveBattler].disableTimer == 0)  // disable ends
                    {
                        gDisableStructs[gActiveBattler].disabledMove = MOVE_NONE;
                        BattleScriptExecute(BattleScript_DisabledNoMore);
                        effect++;
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_ENCORE:  // encore
                if (gDisableStructs[gActiveBattler].encoreTimer != 0)
                {
                    if (gBattleMons[gActiveBattler].moves[gDisableStructs[gActiveBattler].encoredMovePos] != gDisableStructs[gActiveBattler].encoredMove)  // Pokémon does not have the encored move anymore
                    {
                        gDisableStructs[gActiveBattler].encoredMove = MOVE_NONE;
                        gDisableStructs[gActiveBattler].encoreTimer = 0;
                    }
                    else if (--gDisableStructs[gActiveBattler].encoreTimer == 0
                     || gBattleMons[gActiveBattler].pp[gDisableStructs[gActiveBattler].encoredMovePos] == 0)
                    {
                        gDisableStructs[gActiveBattler].encoredMove = MOVE_NONE;
                        gDisableStructs[gActiveBattler].encoreTimer = 0;
                        BattleScriptExecute(BattleScript_EncoredNoMore);
                        effect++;
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_LOCK_ON:  // lock-on decrement
                if (gStatuses3[gActiveBattler] & STATUS3_ALWAYS_HITS)
                    gStatuses3[gActiveBattler] -= STATUS3_ALWAYS_HITS_TURN(1);
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_CHARGE:  // charge
                if (gDisableStructs[gActiveBattler].chargeTimer && --gDisableStructs[gActiveBattler].chargeTimer == 0)
                    gStatuses3[gActiveBattler] &= ~STATUS3_CHARGED_UP;
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_TAUNT:  // taunt
                if (gDisableStructs[gActiveBattler].tauntTimer)
                    gDisableStructs[gActiveBattler].tauntTimer--;
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_YAWN:  // yawn
                if (gStatuses3[gActiveBattler] & STATUS3_YAWN)
                {
                    gStatuses3[gActiveBattler] -= STATUS3_YAWN_TURN(1);
                    if (!(gStatuses3[gActiveBattler] & STATUS3_YAWN) && !(gBattleMons[gActiveBattler].status1 & STATUS1_ANY)
                     && gBattleMons[gActiveBattler].ability != ABILITY_VITAL_SPIRIT
                     && gBattleMons[gActiveBattler].ability != ABILITY_INSOMNIA && !UproarWakeUpCheck(gActiveBattler))
                    {
                        CancelMultiTurnMoves(gActiveBattler);
                        gBattleMons[gActiveBattler].status1 |= STATUS1_SLEEP_TURN((Random() & 3) + 2); // 2-5 turns of sleep
                        BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                        MarkBattlerForControllerExec(gActiveBattler);
                        gEffectBattler = gActiveBattler;
                        BattleScriptExecute(BattleScript_YawnMakesAsleep);
                        effect++;
                    }
                }
                gBattleStruct->turnEffectsTracker++;
                break;
            case ENDTURN_BATTLER_COUNT:  // done
                gBattleStruct->turnEffectsTracker = 0;
                gBattleStruct->turnEffectsBattlerId++;
                break;
            }
            if (effect != 0)
                return effect;
        }
    }
    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_IGNORE_BIDE);
    return 0;
}

bool8 HandleWishPerishSongOnTurnEnd(void)
{
    gHitMarker |= (HITMARKER_GRUDGE | HITMARKER_IGNORE_BIDE);

    switch (gBattleStruct->wishPerishSongState)
    {
    case 0:
        while (gBattleStruct->wishPerishSongBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattleStruct->wishPerishSongBattlerId;
            if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
            {
                gBattleStruct->wishPerishSongBattlerId++;
                continue;
            }

            gBattleStruct->wishPerishSongBattlerId++;
            if (gWishFutureKnock.futureSightCounter[gActiveBattler] != 0
             && --gWishFutureKnock.futureSightCounter[gActiveBattler] == 0
             && gBattleMons[gActiveBattler].hp != 0)
            {
                if (gWishFutureKnock.futureSightMove[gActiveBattler] == MOVE_FUTURE_SIGHT)
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FUTURE_SIGHT;
                else
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOOM_DESIRE;

                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gWishFutureKnock.futureSightMove[gActiveBattler]);

                gBattlerTarget = gActiveBattler;
                gBattlerAttacker = gWishFutureKnock.futureSightAttacker[gActiveBattler];
                gBattleMoveDamage = gWishFutureKnock.futureSightDmg[gActiveBattler];
                gSpecialStatuses[gBattlerTarget].shellBellDmg = IGNORE_SHELL_BELL;
                BattleScriptExecute(BattleScript_MonTookFutureAttack);

                if (gWishFutureKnock.futureSightCounter[gActiveBattler] == 0
                 && gWishFutureKnock.futureSightCounter[BATTLE_PARTNER(gActiveBattler)] == 0)
                {
                    gSideStatuses[GET_BATTLER_SIDE(gBattlerTarget)] &= ~SIDE_STATUS_FUTUREATTACK;
                }
                return TRUE;
            }
        }
        *(&gBattleStruct->wishPerishSongState) = 1;
        gBattleStruct->wishPerishSongBattlerId = 0;
    case 1:
        while (gBattleStruct->wishPerishSongBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattlerAttacker = gBattlerByTurnOrder[gBattleStruct->wishPerishSongBattlerId];
            if (gAbsentBattlerFlags & gBitTable[gActiveBattler])
            {
                gBattleStruct->wishPerishSongBattlerId++;
                continue;
            }
            gBattleStruct->wishPerishSongBattlerId++;
            if (gStatuses3[gActiveBattler] & STATUS3_PERISH_SONG)
            {
                PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gDisableStructs[gActiveBattler].perishSongTimer);
                if (gDisableStructs[gActiveBattler].perishSongTimer == 0)
                {
                    gStatuses3[gActiveBattler] &= ~STATUS3_PERISH_SONG;
                    gBattleMoveDamage = gBattleMons[gActiveBattler].hp;
                    gBattlescriptCurrInstr = BattleScript_PerishSongTakesLife;
                }
                else
                {
                    gDisableStructs[gActiveBattler].perishSongTimer--;
                    gBattlescriptCurrInstr = BattleScript_PerishSongCountGoesDown;
                }
                BattleScriptExecute(gBattlescriptCurrInstr);
                return TRUE;
            }
        }
        *(&gBattleStruct->wishPerishSongState) = 2;
        gBattleStruct->wishPerishSongBattlerId = 0;
    case 2:
        if ((gBattleTypeFlags & BATTLE_TYPE_ARENA)
         && gBattleStruct->arenaTurnCounter == 2
         && gBattleMons[0].hp != 0 && gBattleMons[1].hp != 0)
        {
            s32 i;

            for (i = 0; i < 2; i++)
                CancelMultiTurnMoves(i);

            gBattlescriptCurrInstr = BattleScript_ArenaDoJudgment;
            BattleScriptExecute(BattleScript_ArenaDoJudgment);
            gBattleStruct->wishPerishSongState++;
            return TRUE;
        }
        break;
    }

    gHitMarker &= ~(HITMARKER_GRUDGE | HITMARKER_IGNORE_BIDE);

    return FALSE;
}

#define FAINTED_ACTIONS_MAX_CASE 7

bool8 HandleFaintedMonActions(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        return FALSE;
    do
    {
        s32 i;
        switch (gBattleStruct->faintedActionsState)
        {
        case 0:
            gBattleStruct->faintedActionsBattlerId = 0;
            gBattleStruct->faintedActionsState++;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gAbsentBattlerFlags & gBitTable[i] && !HasNoMonsToSwitch(i, PARTY_SIZE, PARTY_SIZE))
                    gAbsentBattlerFlags &= ~(gBitTable[i]);
            }
            // fall through
        case 1:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->faintedActionsBattlerId;
                if (gBattleMons[gBattleStruct->faintedActionsBattlerId].hp == 0
                 && !(gBattleStruct->givenExpMons & gBitTable[gBattlerPartyIndexes[gBattleStruct->faintedActionsBattlerId]])
                 && !(gAbsentBattlerFlags & gBitTable[gBattleStruct->faintedActionsBattlerId]))
                {
                    BattleScriptExecute(BattleScript_GiveExp);
                    gBattleStruct->faintedActionsState = 2;
                    return TRUE;
                }
            } while (++gBattleStruct->faintedActionsBattlerId != gBattlersCount);
            gBattleStruct->faintedActionsState = 3;
            break;
        case 2:
            OpponentSwitchInResetSentPokesToOpponentValue(gBattlerFainted);
            if (++gBattleStruct->faintedActionsBattlerId == gBattlersCount)
                gBattleStruct->faintedActionsState = 3;
            else
                gBattleStruct->faintedActionsState = 1;
            break;
        case 3:
            gBattleStruct->faintedActionsBattlerId = 0;
            gBattleStruct->faintedActionsState++;
            // fall through
        case 4:
            do
            {
                gBattlerFainted = gBattlerTarget = gBattleStruct->faintedActionsBattlerId;
                if (gBattleMons[gBattleStruct->faintedActionsBattlerId].hp == 0
                 && !(gAbsentBattlerFlags & gBitTable[gBattleStruct->faintedActionsBattlerId]))
                {
                    BattleScriptExecute(BattleScript_HandleFaintedMon);
                    gBattleStruct->faintedActionsState = 5;
                    return TRUE;
                }
            } while (++gBattleStruct->faintedActionsBattlerId != gBattlersCount);
            gBattleStruct->faintedActionsState = 6;
            break;
        case 5:
            if (++gBattleStruct->faintedActionsBattlerId == gBattlersCount)
                gBattleStruct->faintedActionsState = 6;
            else
                gBattleStruct->faintedActionsState = 4;
            break;
        case 6:
            if (AbilityBattleEffects(ABILITYEFFECT_INTIMIDATE1, 0, 0, 0, 0)
             || AbilityBattleEffects(ABILITYEFFECT_TRACE, 0, 0, 0, 0)
             || ItemBattleEffects(ITEMEFFECT_NORMAL, 0, TRUE)
             || AbilityBattleEffects(ABILITYEFFECT_FORECAST, 0, 0, 0, 0))
                return TRUE;
            gBattleStruct->faintedActionsState++;
            break;
        case FAINTED_ACTIONS_MAX_CASE:
            break;
        }
    } while (gBattleStruct->faintedActionsState != FAINTED_ACTIONS_MAX_CASE);
    return FALSE;
}

void TryClearRageStatuses(void)
{
    s32 i;
    for (i = 0; i < gBattlersCount; i++)
    {
        if ((gBattleMons[i].status2 & STATUS2_RAGE) && gChosenMoveByBattler[i] != MOVE_RAGE)
            gBattleMons[i].status2 &= ~STATUS2_RAGE;
    }
}

enum
{
    CANCELER_FLAGS,
    CANCELER_ASLEEP,
    CANCELER_FROZEN,
    CANCELER_TRUANT,
    CANCELER_RECHARGE,
    CANCELER_FLINCH,
    CANCELER_DISABLED,
    CANCELER_TAUNTED,
    CANCELER_IMPRISONED,
    CANCELER_CONFUSED,
    CANCELER_PARALYZED,
    CANCELER_IN_LOVE,
    CANCELER_BIDE,
    CANCELER_THAW,
    CANCELER_END,
};

u8 AtkCanceler_UnableToUseMove(void)
{
    u8 effect = 0;
    s32 *bideDmg = &gBattleScripting.bideDmg;
    do
    {
        switch (gBattleStruct->atkCancelerTracker)
        {
        case CANCELER_FLAGS: // flags clear
            gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_DESTINY_BOND;
            gStatuses3[gBattlerAttacker] &= ~STATUS3_GRUDGE;
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_ASLEEP: // check being asleep
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
            {
                if (UproarWakeUpCheck(gBattlerAttacker))
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_SLEEP;
                    gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP_UPROAR;
                    gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                    effect = 2;
                }
                else
                {
                    u8 toSub;
                    if (gBattleMons[gBattlerAttacker].ability == ABILITY_EARLY_BIRD)
                        toSub = 2;
                    else
                        toSub = 1;
                    if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP) < toSub)
                        gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_SLEEP;
                    else
                        gBattleMons[gBattlerAttacker].status1 -= toSub;
                    if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP)
                    {
                        if (gCurrentMove != MOVE_SNORE && gCurrentMove != MOVE_SLEEP_TALK)
                        {
                            gBattlescriptCurrInstr = BattleScript_MoveUsedIsAsleep;
                            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                            effect = 2;
                        }
                    }
                    else
                    {
                        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_NIGHTMARE;
                        BattleScriptPushCursor();
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP;
                        gBattlescriptCurrInstr = BattleScript_MoveUsedWokeUp;
                        effect = 2;
                    }
                }
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_FROZEN: // check being frozen
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_FREEZE)
            {
                if (Random() % 5)
                {
                    if (gBattleMoves[gCurrentMove].effect != EFFECT_THAW_HIT) // unfreezing via a move effect happens in case 13
                    {
                        gBattlescriptCurrInstr = BattleScript_MoveUsedIsFrozen;
                        gHitMarker |= HITMARKER_NO_ATTACKSTRING;
                    }
                    else
                    {
                        gBattleStruct->atkCancelerTracker++;
                        break;
                    }
                }
                else // unfreeze
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_FREEZE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
                }
                effect = 2;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_TRUANT: // truant
            if (gBattleMons[gBattlerAttacker].ability == ABILITY_TRUANT && gDisableStructs[gBattlerAttacker].truantCounter)
            {
                CancelMultiTurnMoves(gBattlerAttacker);
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LOAFING;
                gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
                gMoveResultFlags |= MOVE_RESULT_MISSED;
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_RECHARGE: // recharge
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_RECHARGE)
            {
                gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_RECHARGE;
                gDisableStructs[gBattlerAttacker].rechargeTimer = 0;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedMustRecharge;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_FLINCH: // flinch
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_FLINCHED)
            {
                gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_FLINCHED;
                gProtectStructs[gBattlerAttacker].flinchImmobility = 1;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedFlinched;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_DISABLED: // disabled move
            if (gDisableStructs[gBattlerAttacker].disabledMove == gCurrentMove && gDisableStructs[gBattlerAttacker].disabledMove != MOVE_NONE)
            {
                gProtectStructs[gBattlerAttacker].usedDisabledMove = 1;
                gBattleScripting.battler = gBattlerAttacker;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_TAUNTED: // taunt
            if (gDisableStructs[gBattlerAttacker].tauntTimer && gBattleMoves[gCurrentMove].power == 0)
            {
                gProtectStructs[gBattlerAttacker].usedTauntedMove = 1;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsTaunted;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_IMPRISONED: // imprisoned
            if (GetImprisonedMovesCount(gBattlerAttacker, gCurrentMove))
            {
                gProtectStructs[gBattlerAttacker].usedImprisonedMove = 1;
                CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsImprisoned;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_CONFUSED: // confusion
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
            {
                gBattleMons[gBattlerAttacker].status2 -= STATUS2_CONFUSION_TURN(1);
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_CONFUSION)
                {
                    if (Random() & 1)
                    {
                        // The MULTISTRING_CHOOSER is used here as a bool to signal
                        // to BattleScript_MoveUsedIsConfused whether or not damage was taken
                        gBattleCommunication[MULTISTRING_CHOOSER] = FALSE;
                        BattleScriptPushCursor();
                    }
                    else // confusion dmg
                    {
                        gBattleCommunication[MULTISTRING_CHOOSER] = TRUE;
                        gBattlerTarget = gBattlerAttacker;
                        gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBattlerAttacker], &gBattleMons[gBattlerAttacker], MOVE_POUND, 0, 40, 0, gBattlerAttacker, gBattlerAttacker);
                        gProtectStructs[gBattlerAttacker].confusionSelfDmg = 1;
                        gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    }
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfused;
                }
                else // snapped out of confusion
                {
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfusedNoMore;
                }
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_PARALYZED: // paralysis
            if ((gBattleMons[gBattlerAttacker].status1 & STATUS1_PARALYSIS) && (Random() % 4) == 0)
            {
                gProtectStructs[gBattlerAttacker].prlzImmobility = 1;
                // This is removed in FRLG and Emerald for some reason
                //CancelMultiTurnMoves(gBattlerAttacker);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
                gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_IN_LOVE: // infatuation
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
            {
                gBattleScripting.battler = CountTrailingZeroBits((gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION) >> 0x10);
                if (Random() & 1)
                {
                    BattleScriptPushCursor();
                }
                else
                {
                    BattleScriptPush(BattleScript_MoveUsedIsInLoveCantAttack);
                    gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
                    gProtectStructs[gBattlerAttacker].loveImmobility = 1;
                    CancelMultiTurnMoves(gBattlerAttacker);
                }
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsInLove;
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_BIDE: // bide
            if (gBattleMons[gBattlerAttacker].status2 & STATUS2_BIDE)
            {
                gBattleMons[gBattlerAttacker].status2 -= STATUS2_BIDE_TURN(1);
                if (gBattleMons[gBattlerAttacker].status2 & STATUS2_BIDE)
                {
                    gBattlescriptCurrInstr = BattleScript_BideStoringEnergy;
                }
                else
                {
                    // This is removed in FRLG and Emerald for some reason
                    //gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_MULTIPLETURNS;
                    if (gBideDmg[gBattlerAttacker])
                    {
                        gCurrentMove = MOVE_BIDE;
                        *bideDmg = gBideDmg[gBattlerAttacker] * 2;
                        gBattlerTarget = gBideTarget[gBattlerAttacker];
                        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
                            gBattlerTarget = GetMoveTarget(MOVE_BIDE, MOVE_TARGET_SELECTED + 1);
                        gBattlescriptCurrInstr = BattleScript_BideAttack;
                    }
                    else
                    {
                        gBattlescriptCurrInstr = BattleScript_BideNoEnergyToAttack;
                    }
                }
                effect = 1;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_THAW: // move thawing
            if (gBattleMons[gBattlerAttacker].status1 & STATUS1_FREEZE)
            {
                if (gBattleMoves[gCurrentMove].effect == EFFECT_THAW_HIT)
                {
                    gBattleMons[gBattlerAttacker].status1 &= ~STATUS1_FREEZE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_MoveUsedUnfroze;
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED_BY_MOVE;
                }
                effect = 2;
            }
            gBattleStruct->atkCancelerTracker++;
            break;
        case CANCELER_END:
            break;
        }

    } while (gBattleStruct->atkCancelerTracker != CANCELER_END && effect == 0);

    if (effect == 2)
    {
        gActiveBattler = gBattlerAttacker;
        BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
        MarkBattlerForControllerExec(gActiveBattler);
    }
    return effect;
}

bool8 HasNoMonsToSwitch(u8 battler, u8 partyIdBattlerOn1, u8 partyIdBattlerOn2)
{
    u8 playerId, flankId;
    struct Pokemon *party;
    s32 i;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            party = gPlayerParty;
        else
            party = gEnemyParty;

        playerId = ((battler & BIT_FLANK) / 2);
        for (i = playerId * MULTI_PARTY_SIZE; i < playerId * MULTI_PARTY_SIZE + MULTI_PARTY_SIZE; i++)
        {
            if (GetMonData2(&party[i], MON_DATA_HP) != 0
             && GetMonData2(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
             && GetMonData2(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
                break;
        }
        return (i == playerId * MULTI_PARTY_SIZE + MULTI_PARTY_SIZE);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
        {
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
            {
                party = gPlayerParty;
                flankId = GetBattlerMultiplayerId(battler);
                playerId = GetLinkTrainerFlankId(flankId);
            }
            else
            {
                party = gEnemyParty;
                if (battler == 1)
                    playerId = 0;
                else
                    playerId = 1;
            }
        }
        else
        {
            flankId = GetBattlerMultiplayerId(battler);

            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                party = gPlayerParty;
            else
                party = gEnemyParty;

            playerId = GetLinkTrainerFlankId(flankId);
        }

        for (i = playerId * MULTI_PARTY_SIZE; i < playerId * MULTI_PARTY_SIZE + MULTI_PARTY_SIZE; i++)
        {
            if (GetMonData2(&party[i], MON_DATA_HP) != 0
             && GetMonData2(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
             && GetMonData2(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
                break;
        }
        return (i == playerId * MULTI_PARTY_SIZE + MULTI_PARTY_SIZE);
    }
    else if ((gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS) && GetBattlerSide(battler) == B_SIDE_OPPONENT)
    {
        party = gEnemyParty;

        if (battler == 1)
            playerId = 0;
        else
            playerId = MULTI_PARTY_SIZE;

        for (i = playerId; i < playerId + MULTI_PARTY_SIZE; i++)
        {
            if (GetMonData2(&party[i], MON_DATA_HP) != 0
             && GetMonData2(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
             && GetMonData2(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
                break;
        }
        return (i == playerId + 3);
    }
    else
    {
        if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        {
            flankId = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
            playerId = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            party = gEnemyParty;
        }
        else
        {
            flankId = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
            playerId = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            party = gPlayerParty;
        }

        if (partyIdBattlerOn1 == PARTY_SIZE)
            partyIdBattlerOn1 = gBattlerPartyIndexes[flankId];
        if (partyIdBattlerOn2 == PARTY_SIZE)
            partyIdBattlerOn2 = gBattlerPartyIndexes[playerId];

        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData2(&party[i], MON_DATA_HP) != 0
             && GetMonData2(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
             && GetMonData2(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
             && i != partyIdBattlerOn1 && i != partyIdBattlerOn2
             && i != *(gBattleStruct->monToSwitchIntoId + flankId) && i != playerId[gBattleStruct->monToSwitchIntoId])
                break;
        }
        return (i == PARTY_SIZE);
    }
}

u8 CastformDataTypeChange(u8 battler)
{
    u8 formChange = 0;
    if (gBattleMons[battler].species != SPECIES_CASTFORM || gBattleMons[battler].ability != ABILITY_FORECAST || gBattleMons[battler].hp == 0)
        return 0; // No change
    if (!WEATHER_HAS_EFFECT && !IS_BATTLER_OF_TYPE(battler, TYPE_NORMAL))
    {
        SET_BATTLER_TYPE(battler, TYPE_NORMAL);
        return CASTFORM_NORMAL + 1;
    }
    if (!WEATHER_HAS_EFFECT)
        return 0; // No change
    if (!(gBattleWeather & (B_WEATHER_RAIN | B_WEATHER_SUN | B_WEATHER_HAIL)) && !IS_BATTLER_OF_TYPE(battler, TYPE_NORMAL))
    {
        SET_BATTLER_TYPE(battler, TYPE_NORMAL);
        formChange = CASTFORM_NORMAL + 1;
    }
    if (gBattleWeather & B_WEATHER_SUN && !IS_BATTLER_OF_TYPE(battler, TYPE_FIRE))
    {
        SET_BATTLER_TYPE(battler, TYPE_FIRE);
        formChange = CASTFORM_FIRE + 1;
    }
    if (gBattleWeather & B_WEATHER_RAIN && !IS_BATTLER_OF_TYPE(battler, TYPE_WATER))
    {
        SET_BATTLER_TYPE(battler, TYPE_WATER);
        formChange = CASTFORM_WATER + 1;
    }
    if (gBattleWeather & B_WEATHER_HAIL && !IS_BATTLER_OF_TYPE(battler, TYPE_ICE))
    {
        SET_BATTLER_TYPE(battler, TYPE_ICE);
        formChange = CASTFORM_ICE + 1;
    }
    return formChange;
}

u8 AbilityBattleEffects(u8 caseID, u8 battler, u8 ability, u8 special, u16 moveArg)
{
    u8 effect = 0;
    struct Pokemon *pokeAtk;
    struct Pokemon *pokeDef;
    u16 speciesAtk;
    u16 speciesDef;
    u32 pidAtk;
    u32 pidDef;

    if (gBattlerAttacker >= gBattlersCount)
        gBattlerAttacker = battler;

    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        pokeAtk = &gPlayerParty[gBattlerPartyIndexes[gBattlerAttacker]];
    else
        pokeAtk = &gEnemyParty[gBattlerPartyIndexes[gBattlerAttacker]];

    if (gBattlerTarget >= gBattlersCount)
        gBattlerTarget = battler;

    if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
        pokeDef = &gPlayerParty[gBattlerPartyIndexes[gBattlerTarget]];
    else
        pokeDef = &gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]];

    speciesAtk = GetMonData2(pokeAtk, MON_DATA_SPECIES);
    pidAtk = GetMonData2(pokeAtk, MON_DATA_PERSONALITY);

    speciesDef = GetMonData2(pokeDef, MON_DATA_SPECIES);
    pidDef = GetMonData2(pokeDef, MON_DATA_PERSONALITY);

    if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI)) // Why isn't that check done at the beginning?
    {
        u8 moveType;
        s32 i;
        u16 move;
        u8 side;
        u8 target1;

        if (special)
            gLastUsedAbility = special;
        else
            gLastUsedAbility = gBattleMons[battler].ability;

        if (moveArg)
            move = moveArg;
        else
            move = gCurrentMove;

        GET_MOVE_TYPE(move, moveType);

        switch (caseID)
        {
        case ABILITYEFFECT_ON_SWITCHIN: // 0
            if (gBattlerAttacker >= gBattlersCount)
                gBattlerAttacker = battler;
            switch (gLastUsedAbility)
            {
            case ABILITYEFFECT_SWITCH_IN_WEATHER:
                if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                {
                    u8 weather = GetCurrentWeather();
                    switch (weather)
                    {
                    case WEATHER_RAIN:
                    case WEATHER_RAIN_THUNDERSTORM:
                    case WEATHER_DOWNPOUR:
                        if (!(gBattleWeather & B_WEATHER_RAIN))
                        {
                            gBattleWeather = (B_WEATHER_RAIN_TEMPORARY | B_WEATHER_RAIN_PERMANENT);
                            gBattleScripting.animArg1 = B_ANIM_RAIN_CONTINUES;
                            gBattleScripting.battler = battler;
                            effect++;
                        }
                        break;
                    case WEATHER_SANDSTORM:
                        if (!(gBattleWeather & B_WEATHER_SANDSTORM))
                        {
                            gBattleWeather = B_WEATHER_SANDSTORM;
                            gBattleScripting.animArg1 = B_ANIM_SANDSTORM_CONTINUES;
                            gBattleScripting.battler = battler;
                            effect++;
                        }
                        break;
                    case WEATHER_DROUGHT:
                        if (!(gBattleWeather & B_WEATHER_SUN))
                        {
                            gBattleWeather = B_WEATHER_SUN;
                            gBattleScripting.animArg1 = B_ANIM_SUN_CONTINUES;
                            gBattleScripting.battler = battler;
                            effect++;
                        }
                        break;
                    }
                }
                if (effect != 0)
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = GetCurrentWeather();
                    BattleScriptPushCursorAndCallback(BattleScript_OverworldWeatherStarts);
                }
                break;
            case ABILITY_DRIZZLE:
                if (!(gBattleWeather & B_WEATHER_RAIN_PERMANENT))
                {
                    gBattleWeather = (B_WEATHER_RAIN_PERMANENT | B_WEATHER_RAIN_TEMPORARY);
                    BattleScriptPushCursorAndCallback(BattleScript_DrizzleActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
                break;
            case ABILITY_SAND_STREAM:
                if (!(gBattleWeather & B_WEATHER_SANDSTORM_PERMANENT))
                {
                    gBattleWeather = B_WEATHER_SANDSTORM;
                    BattleScriptPushCursorAndCallback(BattleScript_SandstreamActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
                break;
            case ABILITY_DROUGHT:
                if (!(gBattleWeather & B_WEATHER_SUN_PERMANENT))
                {
                    gBattleWeather = B_WEATHER_SUN;
                    BattleScriptPushCursorAndCallback(BattleScript_DroughtActivates);
                    gBattleScripting.battler = battler;
                    effect++;
                }
                break;
            case ABILITY_INTIMIDATE:
                if (!(gSpecialStatuses[battler].intimidatedMon))
                {
                    gStatuses3[battler] |= STATUS3_INTIMIDATE_POKES;
                    gSpecialStatuses[battler].intimidatedMon = 1;
                }
                break;
            case ABILITY_FORECAST:
                effect = CastformDataTypeChange(battler);
                if (effect != 0)
                {
                    BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
                    gBattleScripting.battler = battler;
                    *(&gBattleStruct->formToChangeInto) = effect - 1;
                }
                break;
            case ABILITY_TRACE:
                if (!(gSpecialStatuses[battler].traced))
                {
                    gStatuses3[battler] |= STATUS3_TRACE;
                    gSpecialStatuses[battler].traced = 1;
                }
                break;
            case ABILITY_CLOUD_NINE:
            case ABILITY_AIR_LOCK:
                {
                    // that's a weird choice for a variable, why not use i or battler?
                    for (target1 = 0; target1 < gBattlersCount; target1++)
                    {
                        effect = CastformDataTypeChange(target1);
                        if (effect != 0)
                        {
                            BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
                            gBattleScripting.battler = target1;
                            *(&gBattleStruct->formToChangeInto) = effect - 1;
                            break;
                        }
                    }
                }
                break;
            }
            break;
        case ABILITYEFFECT_ENDTURN: // 1
            if (gBattleMons[battler].hp != 0)
            {
                gBattlerAttacker = battler;
                switch (gLastUsedAbility)
                {
                case ABILITY_RAIN_DISH:
                    if (WEATHER_HAS_EFFECT && (gBattleWeather & B_WEATHER_RAIN)
                     && gBattleMons[battler].maxHP > gBattleMons[battler].hp)
                    {
                        gLastUsedAbility = ABILITY_RAIN_DISH; // why
                        BattleScriptPushCursorAndCallback(BattleScript_RainDishActivates);
                        gBattleMoveDamage = gBattleMons[battler].maxHP / 16;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                        effect++;
                    }
                    break;
                case ABILITY_SHED_SKIN:
                    if ((gBattleMons[battler].status1 & STATUS1_ANY) && (Random() % 3) == 0)
                    {
                        if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON))
                            StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                            StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                            StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        if (gBattleMons[battler].status1 & STATUS1_BURN)
                            StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                            StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        gBattleMons[battler].status1 = 0;
                        gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;  // fix nightmare glitch
                        gBattleScripting.battler = gActiveBattler = battler;
                        BattleScriptPushCursorAndCallback(BattleScript_ShedSkinActivates);
                        BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                        MarkBattlerForControllerExec(gActiveBattler);
                        effect++;
                    }
                    break;
                case ABILITY_SPEED_BOOST:
                    if (gBattleMons[battler].statStages[STAT_SPEED] < MAX_STAT_STAGE && gDisableStructs[battler].isFirstTurn != 2)
                    {
                        gBattleMons[battler].statStages[STAT_SPEED]++;
                        gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + STAT_SPEED;
                        gBattleScripting.animArg2 = 0;
                        BattleScriptPushCursorAndCallback(BattleScript_SpeedBoostActivates);
                        gBattleScripting.battler = battler;
                        effect++;
                    }
                    break;
                case ABILITY_TRUANT:
                    gDisableStructs[gBattlerAttacker].truantCounter ^= 1;
                    break;
                }
            }
            break;
        case ABILITYEFFECT_MOVES_BLOCK: // 2
            if (gLastUsedAbility == ABILITY_SOUNDPROOF)
            {
                for (i = 0; sSoundMovesTable[i] != 0xFFFF; i++)
                {
                    if (sSoundMovesTable[i] == move)
                        break;
                }
                if (sSoundMovesTable[i] != 0xFFFF)
                {
                    if (gBattleMons[gBattlerAttacker].status2 & STATUS2_MULTIPLETURNS)
                        gHitMarker |= HITMARKER_NO_PPDEDUCT;
                    gBattlescriptCurrInstr = BattleScript_SoundproofProtected;
                    effect = 1;
                }
            }
            break;
        case ABILITYEFFECT_ABSORBING: // 3
            if (move)
            {
                switch (gLastUsedAbility)
                {
                case ABILITY_VOLT_ABSORB:
                    if (moveType == TYPE_ELECTRIC && gBattleMoves[move].power != 0)
                    {
                        if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain;
                        else
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain_PPLoss;

                        effect = 1;
                    }
                    break;
                case ABILITY_WATER_ABSORB:
                    if (moveType == TYPE_WATER && gBattleMoves[move].power != 0)
                    {
                        if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain;
                        else
                            gBattlescriptCurrInstr = BattleScript_MoveHPDrain_PPLoss;

                        effect = 1;
                    }
                    break;
                case ABILITY_FLASH_FIRE:
                    if (moveType == TYPE_FIRE && !(gBattleMons[battler].status1 & STATUS1_FREEZE))
                    {
                        if (!(gBattleResources->flags->flags[battler] & RESOURCE_FLAG_FLASH_FIRE))
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_BOOST;
                            if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                            else
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;

                            gBattleResources->flags->flags[battler] |= RESOURCE_FLAG_FLASH_FIRE;
                            effect = 2;
                        }
                        else
                        {
                            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FLASH_FIRE_NO_BOOST;
                            if (gProtectStructs[gBattlerAttacker].notFirstStrike)
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost;
                            else
                                gBattlescriptCurrInstr = BattleScript_FlashFireBoost_PPLoss;

                            effect = 2;
                        }
                    }
                    break;
                }
                if (effect == 1)
                {
                    if (gBattleMons[battler].maxHP == gBattleMons[battler].hp)
                    {
                        if ((gProtectStructs[gBattlerAttacker].notFirstStrike))
                            gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless;
                        else
                            gBattlescriptCurrInstr = BattleScript_MonMadeMoveUseless_PPLoss;
                    }
                    else
                    {
                        gBattleMoveDamage = gBattleMons[battler].maxHP / 4;
                        if (gBattleMoveDamage == 0)
                            gBattleMoveDamage = 1;
                        gBattleMoveDamage *= -1;
                    }
                }
            }
            break;
        case ABILITYEFFECT_ON_DAMAGE: // Contact abilities and Color Change
            switch (gLastUsedAbility)
            {
            case ABILITY_COLOR_CHANGE:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                 && move != MOVE_STRUGGLE
                 && gBattleMoves[move].power != 0
                 && TARGET_TURN_DAMAGED
                 && !IS_BATTLER_OF_TYPE(battler, moveType)
                 && gBattleMons[battler].hp != 0)
                {
                    SET_BATTLER_TYPE(battler, moveType);
                    PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ColorChangeActivates;
                    effect++;
                }
                break;
            case ABILITY_ROUGH_SKIN:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                 && gBattleMons[gBattlerAttacker].hp != 0
                 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                 && TARGET_TURN_DAMAGED
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT))
                {
                    gBattleMoveDamage = gBattleMons[gBattlerAttacker].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_RoughSkinActivates;
                    effect++;
                }
                break;
            case ABILITY_EFFECT_SPORE:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                 && gBattleMons[gBattlerAttacker].hp != 0
                 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                 && TARGET_TURN_DAMAGED
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && (Random() % 10) == 0)
                {
                    do
                    {
                        // Pick either MOVE_EFFECT_SLEEP, MOVE_EFFECT_POISON or MOVE_EFFECT_BURN
                        gBattleCommunication[MOVE_EFFECT_BYTE] = Random() & 3;
                    } while (gBattleCommunication[MOVE_EFFECT_BYTE] == 0);
                    // Replace MOVE_EFFECT_BURN with MOVE_EFFECT_PARALYSIS
                    if (gBattleCommunication[MOVE_EFFECT_BYTE] == MOVE_EFFECT_BURN)
                        gBattleCommunication[MOVE_EFFECT_BYTE] += (MOVE_EFFECT_PARALYSIS - MOVE_EFFECT_BURN);

                    gBattleCommunication[MOVE_EFFECT_BYTE] += MOVE_EFFECT_AFFECTS_USER;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ApplySecondaryEffect;
                    gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                    effect++;
                }
                break;
            case ABILITY_POISON_POINT:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                 && gBattleMons[gBattlerAttacker].hp != 0
                 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                 && TARGET_TURN_DAMAGED
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && (Random() % 3) == 0)
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_POISON;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ApplySecondaryEffect;
                    gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                    effect++;
                }
                break;
            case ABILITY_STATIC:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                 && gBattleMons[gBattlerAttacker].hp != 0
                 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                 && TARGET_TURN_DAMAGED
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && (Random() % 3) == 0)
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_PARALYSIS;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ApplySecondaryEffect;
                    gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                    effect++;
                }
                break;
            case ABILITY_FLAME_BODY:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                 && gBattleMons[gBattlerAttacker].hp != 0
                 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && TARGET_TURN_DAMAGED
                 && (Random() % 3) == 0)
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_BURN;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ApplySecondaryEffect;
                    gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                    effect++;
                }
                break;
            case ABILITY_CUTE_CHARM:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                 && gBattleMons[gBattlerAttacker].hp != 0
                 && !gProtectStructs[gBattlerAttacker].confusionSelfDmg
                 && (gBattleMoves[move].flags & FLAG_MAKES_CONTACT)
                 && TARGET_TURN_DAMAGED
                 && gBattleMons[gBattlerTarget].hp != 0
                 && (Random() % 3) == 0
                 && gBattleMons[gBattlerAttacker].ability != ABILITY_OBLIVIOUS
                 && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != GetGenderFromSpeciesAndPersonality(speciesDef, pidDef)
                 && !(gBattleMons[gBattlerAttacker].status2 & STATUS2_INFATUATION)
                 && GetGenderFromSpeciesAndPersonality(speciesAtk, pidAtk) != MON_GENDERLESS
                 && GetGenderFromSpeciesAndPersonality(speciesDef, pidDef) != MON_GENDERLESS)
                {
                    gBattleMons[gBattlerAttacker].status2 |= STATUS2_INFATUATED_WITH(gBattlerTarget);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_CuteCharmActivates;
                    effect++;
                }
                break;
            }
            break;
        case ABILITYEFFECT_IMMUNITY: // 5
            for (battler = 0; battler < gBattlersCount; battler++)
            {
                switch (gBattleMons[battler].ability)
                {
                case ABILITY_IMMUNITY:
                    if (gBattleMons[battler].status1 & (STATUS1_POISON | STATUS1_TOXIC_POISON | STATUS1_TOXIC_COUNTER))
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        effect = 1;
                    }
                    break;
                case ABILITY_OWN_TEMPO:
                    if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                        effect = 2;
                    }
                    break;
                case ABILITY_LIMBER:
                    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        effect = 1;
                    }
                    break;
                case ABILITY_INSOMNIA:
                case ABILITY_VITAL_SPIRIT:
                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        effect = 1;
                    }
                    break;
                case ABILITY_WATER_VEIL:
                    if (gBattleMons[battler].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        effect = 1;
                    }
                    break;
                case ABILITY_MAGMA_ARMOR:
                    if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        effect = 1;
                    }
                    break;
                case ABILITY_OBLIVIOUS:
                    if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
                        effect = 3;
                    }
                    break;
                }
                if (effect != 0)
                {
                    switch (effect)
                    {
                    case 1: // status cleared
                        gBattleMons[battler].status1 = 0;
                        break;
                    case 2: // get rid of confusion
                        gBattleMons[battler].status2 &= ~STATUS2_CONFUSION;
                        break;
                    case 3: // get rid of infatuation
                        gBattleMons[battler].status2 &= ~STATUS2_INFATUATION;
                        break;
                    }

                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_AbilityCuredStatus;
                    gBattleScripting.battler = battler;
                    gActiveBattler = battler;
                    BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                    return effect;
                }
            }
            break;
        case ABILITYEFFECT_FORECAST: // 6
            for (battler = 0; battler < gBattlersCount; battler++)
            {
                if (gBattleMons[battler].ability == ABILITY_FORECAST)
                {
                    effect = CastformDataTypeChange(battler);
                    if (effect != 0)
                    {
                        BattleScriptPushCursorAndCallback(BattleScript_CastformChange);
                        gBattleScripting.battler = battler;
                        *(&gBattleStruct->formToChangeInto) = effect - 1;
                        return effect;
                    }
                }
            }
            break;
        case ABILITYEFFECT_SYNCHRONIZE: // 7
            if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONIZE_EFFECT))
            {
                gHitMarker &= ~HITMARKER_SYNCHRONIZE_EFFECT;
                gBattleStruct->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (gBattleStruct->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gBattleStruct->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleCommunication[MOVE_EFFECT_BYTE] = gBattleStruct->synchronizeMoveEffect + MOVE_EFFECT_AFFECTS_USER;
                gBattleScripting.battler = gBattlerTarget;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITYEFFECT_ATK_SYNCHRONIZE: // 8
            if (gLastUsedAbility == ABILITY_SYNCHRONIZE && (gHitMarker & HITMARKER_SYNCHRONIZE_EFFECT))
            {
                gHitMarker &= ~HITMARKER_SYNCHRONIZE_EFFECT;
                gBattleStruct->synchronizeMoveEffect &= ~(MOVE_EFFECT_AFFECTS_USER | MOVE_EFFECT_CERTAIN);
                if (gBattleStruct->synchronizeMoveEffect == MOVE_EFFECT_TOXIC)
                    gBattleStruct->synchronizeMoveEffect = MOVE_EFFECT_POISON;

                gBattleCommunication[MOVE_EFFECT_BYTE] = gBattleStruct->synchronizeMoveEffect;
                gBattleScripting.battler = gBattlerAttacker;
                BattleScriptPushCursor();
                gBattlescriptCurrInstr = BattleScript_SynchronizeActivates;
                gHitMarker |= HITMARKER_STATUS_ABILITY_EFFECT;
                effect++;
            }
            break;
        case ABILITYEFFECT_INTIMIDATE1: // 9
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].ability == ABILITY_INTIMIDATE && gStatuses3[i] & STATUS3_INTIMIDATE_POKES)
                {
                    gLastUsedAbility = ABILITY_INTIMIDATE;
                    gStatuses3[i] &= ~STATUS3_INTIMIDATE_POKES;
                    BattleScriptPushCursorAndCallback(BattleScript_IntimidateActivatesEnd3);
                    gBattleStruct->intimidateBattler = i;
                    effect++;
                    break;
                }
            }
            break;
        case ABILITYEFFECT_TRACE: // 11
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].ability == ABILITY_TRACE && (gStatuses3[i] & STATUS3_TRACE))
                {
                    u8 target2;
                    side = BATTLE_OPPOSITE(GetBattlerPosition(i)) & BIT_SIDE; // side of the opposing Pokémon
                    target1 = GetBattlerAtPosition(side);
                    target2 = GetBattlerAtPosition(side + BIT_FLANK);
                    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                    {
                        if (gBattleMons[target1].ability != ABILITY_NONE && gBattleMons[target1].hp != 0
                         && gBattleMons[target2].ability != ABILITY_NONE && gBattleMons[target2].hp != 0)
                        {
                            gActiveBattler = GetBattlerAtPosition(((Random() & 1) * 2) | side);
                            gBattleMons[i].ability = gBattleMons[gActiveBattler].ability;
                            gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                            effect++;
                        }
                        else if (gBattleMons[target1].ability != ABILITY_NONE && gBattleMons[target1].hp != 0)
                        {
                            gActiveBattler = target1;
                            gBattleMons[i].ability = gBattleMons[gActiveBattler].ability;
                            gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                            effect++;
                        }
                        else if (gBattleMons[target2].ability != ABILITY_NONE && gBattleMons[target2].hp != 0)
                        {
                            gActiveBattler = target2;
                            gBattleMons[i].ability = gBattleMons[gActiveBattler].ability;
                            gLastUsedAbility = gBattleMons[gActiveBattler].ability;
                            effect++;
                        }
                    }
                    else
                    {
                        gActiveBattler = target1;
                        if (gBattleMons[target1].ability && gBattleMons[target1].hp)
                        {
                            gBattleMons[i].ability = gBattleMons[target1].ability;
                            gLastUsedAbility = gBattleMons[target1].ability;
                            effect++;
                        }
                    }
                    if (effect != 0)
                    {
                        BattleScriptPushCursorAndCallback(BattleScript_TraceActivates);
                        gStatuses3[i] &= ~STATUS3_TRACE;
                        gBattleScripting.battler = i;

                        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, gActiveBattler, gBattlerPartyIndexes[gActiveBattler])
                        PREPARE_ABILITY_BUFFER(gBattleTextBuff2, gLastUsedAbility)
                        break;
                    }
                }
            }
            break;
        case ABILITYEFFECT_INTIMIDATE2: // 10
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].ability == ABILITY_INTIMIDATE && (gStatuses3[i] & STATUS3_INTIMIDATE_POKES))
                {
                    gLastUsedAbility = ABILITY_INTIMIDATE;
                    gStatuses3[i] &= ~STATUS3_INTIMIDATE_POKES;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_IntimidateActivates;
                    gBattleStruct->intimidateBattler = i;
                    effect++;
                    break;
                }
            }
            break;
        case ABILITYEFFECT_CHECK_OTHER_SIDE: // 12
            side = GetBattlerSide(battler);
            for (i = 0; i < gBattlersCount; i++)
            {
                if (GetBattlerSide(i) != side && gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        case ABILITYEFFECT_CHECK_BATTLER_SIDE: // 13
            side = GetBattlerSide(battler);
            for (i = 0; i < gBattlersCount; i++)
            {
                if (GetBattlerSide(i) == side && gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        case ABILITYEFFECT_FIELD_SPORT: // 14
            switch (gLastUsedAbility)
            {
            case ABILITYEFFECT_MUD_SPORT:
                for (i = 0; i < gBattlersCount; i++)
                {
                    if (gStatuses3[i] & STATUS3_MUDSPORT)
                        effect = i + 1;
                }
                break;
            case ABILITYEFFECT_WATER_SPORT:
                for (i = 0; i < gBattlersCount; i++)
                {
                    if (gStatuses3[i] & STATUS3_WATERSPORT)
                        effect = i + 1;
                }
                break;
            default:
                for (i = 0; i < gBattlersCount; i++)
                {
                    if (gBattleMons[i].ability == ability)
                    {
                        gLastUsedAbility = ability;
                        effect = i + 1;
                    }
                }
                break;
            }
            break;
        case ABILITYEFFECT_CHECK_ON_FIELD: // 19
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].ability == ability && gBattleMons[i].hp != 0)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        case ABILITYEFFECT_CHECK_FIELD_EXCEPT_BATTLER: // 15
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].ability == ability && i != battler)
                {
                    gLastUsedAbility = ability;
                    effect = i + 1;
                }
            }
            break;
        case ABILITYEFFECT_COUNT_OTHER_SIDE: // 16
            side = GetBattlerSide(battler);
            for (i = 0; i < gBattlersCount; i++)
            {
                if (GetBattlerSide(i) != side && gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect++;
                }
            }
            break;
        case ABILITYEFFECT_COUNT_BATTLER_SIDE: // 17
            side = GetBattlerSide(battler);
            for (i = 0; i < gBattlersCount; i++)
            {
                if (GetBattlerSide(i) == side && gBattleMons[i].ability == ability)
                {
                    gLastUsedAbility = ability;
                    effect++;
                }
            }
            break;
        case ABILITYEFFECT_COUNT_ON_FIELD: // 18
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].ability == ability && i != battler)
                {
                    gLastUsedAbility = ability;
                    effect++;
                }
            }
            break;
        }

        if (effect && caseID < ABILITYEFFECT_CHECK_OTHER_SIDE && gLastUsedAbility != 0xFF)
            RecordAbilityBattle(battler, gLastUsedAbility);
    }

    return effect;
}

void BattleScriptExecute(const u8 *BS_ptr)
{
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = RunBattleScriptCommands_PopCallbacksStack;
    gCurrentActionFuncId = 0;
}

void BattleScriptPushCursorAndCallback(const u8 *BS_ptr)
{
    BattleScriptPushCursor();
    gBattlescriptCurrInstr = BS_ptr;
    gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size++] = gBattleMainFunc;
    gBattleMainFunc = sub_0803DCCC;
}

enum
{
    ITEM_NO_EFFECT,
    ITEM_STATUS_CHANGE,
    ITEM_EFFECT_OTHER,
    ITEM_PP_CHANGE,
    ITEM_HP_CHANGE,
    ITEM_STATS_CHANGE,
};

#define TRY_EAT_CONFUSE_BERRY(flavor)                                                       \
    if (gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2 && !moveTurn)         \
    {                                                                                       \
        PREPARE_FLAVOR_BUFFER(gBattleTextBuff1, flavor);                                    \
        gBattleMoveDamage = gBattleMons[battler].maxHP / battlerHoldEffectParam;          \
        if (gBattleMoveDamage == 0)                                                         \
            gBattleMoveDamage = 1;                                                          \
        if (gBattleMons[battler].hp + gBattleMoveDamage > gBattleMons[battler].maxHP)   \
            gBattleMoveDamage = gBattleMons[battler].maxHP - gBattleMons[battler].hp;   \
        gBattleMoveDamage *= -1;                                                            \
        if (GetFlavorRelationByPersonality(gBattleMons[battler].personality, flavor) < 0) \
            BattleScriptExecute(BattleScript_BerryConfuseHealEnd2);                         \
        else                                                                                \
            BattleScriptExecute(BattleScript_ItemHealHP_RemoveItem);                        \
        effect = ITEM_HP_CHANGE;                                                            \
    }

#define TRY_EAT_STAT_UP_BERRY(stat)                                                         \
    if (gBattleMons[battler].hp <= gBattleMons[battler].maxHP / battlerHoldEffectParam  \
    && !moveTurn && gBattleMons[battler].statStages[stat] < MAX_STAT_STAGE)               \
    {                                                                                       \
        PREPARE_STAT_BUFFER(gBattleTextBuff1, stat);                                        \
        gEffectBattler = battler;                                                         \
        SET_STATCHANGER(stat, 1, FALSE);                                                    \
        gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + (stat);                               \
        gBattleScripting.animArg2 = 0;                                                      \
        BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);                               \
        effect = ITEM_STATS_CHANGE;                                                         \
    }

u8 ItemBattleEffects(u8 caseID, u8 battler, bool8 moveTurn)
{
    int i = 0;
    u8 effect = ITEM_NO_EFFECT;
    u8 changedPP = 0;
    u8 battlerHoldEffect, atkHoldEffect, UNUSED defHoldEffect;
    u8 battlerHoldEffectParam, atkHoldEffectParam, UNUSED defHoldEffectParam;
    u16 atkItem, defItem;

    gLastUsedItem = gBattleMons[battler].item;
    if (gLastUsedItem == ITEM_ENIGMA_BERRY)
    {
        battlerHoldEffect = gEnigmaBerries[battler].holdEffect;
        battlerHoldEffectParam = gEnigmaBerries[battler].holdEffectParam;
    }
    else
    {
        battlerHoldEffect = GetItemHoldEffect(gLastUsedItem);
        battlerHoldEffectParam = GetItemHoldEffectParam(gLastUsedItem);
    }

    atkItem = gBattleMons[gBattlerAttacker].item;
    if (atkItem == ITEM_ENIGMA_BERRY)
    {
        atkHoldEffect = gEnigmaBerries[gBattlerAttacker].holdEffect;
        atkHoldEffectParam = gEnigmaBerries[gBattlerAttacker].holdEffectParam;
    }
    else
    {
        atkHoldEffect = GetItemHoldEffect(atkItem);
        atkHoldEffectParam = GetItemHoldEffectParam(atkItem);
    }

    // def variables are unused
    defItem = gBattleMons[gBattlerTarget].item;
    if (defItem == ITEM_ENIGMA_BERRY)
    {
        defHoldEffect = gEnigmaBerries[gBattlerTarget].holdEffect;
        defHoldEffectParam = gEnigmaBerries[gBattlerTarget].holdEffectParam;
    }
    else
    {
        defHoldEffect = GetItemHoldEffect(defItem);
        defHoldEffectParam = GetItemHoldEffectParam(defItem);
    }

    switch (caseID)
    {
    case ITEMEFFECT_ON_SWITCH_IN:
        switch (battlerHoldEffect)
        {
        case HOLD_EFFECT_DOUBLE_PRIZE:
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                gBattleStruct->moneyMultiplier = 2;
            break;
        case HOLD_EFFECT_RESTORE_STATS:
            for (i = 0; i < NUM_BATTLE_STATS; i++)
            {
                if (gBattleMons[battler].statStages[i] < DEFAULT_STAT_STAGE)
                {
                    gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE;
                    effect = ITEM_STATS_CHANGE;
                }
            }
            if (effect != 0)
            {
                gBattleScripting.battler = battler;
                gPotentialItemEffectBattler = battler;
                gActiveBattler = gBattlerAttacker = battler;
                BattleScriptExecute(BattleScript_WhiteHerbEnd2);
            }
            break;
        }
        break;
    case ITEMEFFECT_NORMAL:
        if (gBattleMons[battler].hp)
        {
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_RESTORE_HP:
                if (gBattleMons[battler].hp <= gBattleMons[battler].maxHP / 2 && !moveTurn)
                {
                    gBattleMoveDamage = battlerHoldEffectParam;
                    if (gBattleMons[battler].hp + battlerHoldEffectParam > gBattleMons[battler].maxHP)
                        gBattleMoveDamage = gBattleMons[battler].maxHP - gBattleMons[battler].hp;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_ItemHealHP_RemoveItem);
                    effect = ITEM_HP_CHANGE;
                }
                break;
            case HOLD_EFFECT_RESTORE_PP:
                if (!moveTurn)
                {
                    struct Pokemon *mon;
                    u8 ppBonuses;
                    u16 move;

                    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                        mon = &gPlayerParty[gBattlerPartyIndexes[battler]];
                    else
                        mon = &gEnemyParty[gBattlerPartyIndexes[battler]];
                    for (i = 0; i < MAX_MON_MOVES; i++)
                    {
                        move = GetMonData2(mon, MON_DATA_MOVE1 + i);
                        changedPP = GetMonData2(mon, MON_DATA_PP1 + i);
                        ppBonuses = GetMonData2(mon, MON_DATA_PP_BONUSES);
                        if (move && changedPP == 0)
                            break;
                    }
                    if (i != MAX_MON_MOVES)
                    {
                        u8 maxPP = CalculatePPWithBonus(move, ppBonuses, i);
                        if (changedPP + battlerHoldEffectParam > maxPP)
                            changedPP = maxPP;
                        else
                            changedPP = changedPP + battlerHoldEffectParam;

                        PREPARE_MOVE_BUFFER(gBattleTextBuff1, move);

                        BattleScriptExecute(BattleScript_BerryPPHealEnd2);
                        BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, i + REQUEST_PPMOVE1_BATTLE, 0, 1, &changedPP);
                        MarkBattlerForControllerExec(gActiveBattler);
                        effect = ITEM_PP_CHANGE;
                    }
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battler].statStages[i] < DEFAULT_STAT_STAGE)
                    {
                        gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect != 0)
                {
                    gBattleScripting.battler = battler;
                    gPotentialItemEffectBattler = battler;
                    gActiveBattler = gBattlerAttacker = battler;
                    BattleScriptExecute(BattleScript_WhiteHerbEnd2);
                }
                break;
            case HOLD_EFFECT_LEFTOVERS:
                if (gBattleMons[battler].hp < gBattleMons[battler].maxHP && !moveTurn)
                {
                    gBattleMoveDamage = gBattleMons[battler].maxHP / 16;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = 1;
                    if (gBattleMons[battler].hp + gBattleMoveDamage > gBattleMons[battler].maxHP)
                        gBattleMoveDamage = gBattleMons[battler].maxHP - gBattleMons[battler].hp;
                    gBattleMoveDamage *= -1;
                    BattleScriptExecute(BattleScript_ItemHealHP_End2);
                    effect = ITEM_HP_CHANGE;
                    RecordItemEffectBattle(battler, battlerHoldEffect);
                }
                break;
            case HOLD_EFFECT_CONFUSE_SPICY:
                TRY_EAT_CONFUSE_BERRY(FLAVOR_SPICY);
                break;
            case HOLD_EFFECT_CONFUSE_DRY:
                TRY_EAT_CONFUSE_BERRY(FLAVOR_DRY);
                break;
            case HOLD_EFFECT_CONFUSE_SWEET:
                TRY_EAT_CONFUSE_BERRY(FLAVOR_SWEET);
                break;
            case HOLD_EFFECT_CONFUSE_BITTER:
                TRY_EAT_CONFUSE_BERRY(FLAVOR_BITTER);
                break;
            case HOLD_EFFECT_CONFUSE_SOUR:
                TRY_EAT_CONFUSE_BERRY(FLAVOR_SOUR);
                break;
            case HOLD_EFFECT_ATTACK_UP:
                if (gBattleMons[battler].hp <= gBattleMons[battler].maxHP / battlerHoldEffectParam
                && !moveTurn && gBattleMons[battler].statStages[STAT_ATK] < MAX_STAT_STAGE)
                {
                    PREPARE_STAT_BUFFER(gBattleTextBuff1, STAT_ATK);
                    PREPARE_STRING_BUFFER(gBattleTextBuff2, STRINGID_STATROSE); // Only the Attack stat-up berry has this
                    gEffectBattler = battler;
                    SET_STATCHANGER(STAT_ATK, 1, FALSE);
                    gBattleScripting.animArg1 = STAT_ANIM_PLUS1 + STAT_ATK;
                    gBattleScripting.animArg2 = 0;
                    BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                    effect = ITEM_STATS_CHANGE;
                }
                break;
            case HOLD_EFFECT_DEFENSE_UP:
                TRY_EAT_STAT_UP_BERRY(STAT_DEF);
                break;
            case HOLD_EFFECT_SPEED_UP:
                TRY_EAT_STAT_UP_BERRY(STAT_SPEED);
                break;
            case HOLD_EFFECT_SP_ATTACK_UP:
                TRY_EAT_STAT_UP_BERRY(STAT_SPATK);
                break;
            case HOLD_EFFECT_SP_DEFENSE_UP:
                TRY_EAT_STAT_UP_BERRY(STAT_SPDEF);
                break;
            case HOLD_EFFECT_CRITICAL_UP:
                if (gBattleMons[battler].hp <= gBattleMons[battler].maxHP / battlerHoldEffectParam && !moveTurn
                    && !(gBattleMons[battler].status2 & STATUS2_FOCUS_ENERGY))
                {
                    gBattleMons[battler].status2 |= STATUS2_FOCUS_ENERGY;
                    BattleScriptExecute(BattleScript_BerryFocusEnergyEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_RANDOM_STAT_UP:
                if (!moveTurn && gBattleMons[battler].hp <= gBattleMons[battler].maxHP / battlerHoldEffectParam)
                {
                    for (i = 0; i < NUM_STATS - 1; i++)
                    {
                        if (gBattleMons[battler].statStages[STAT_ATK + i] < MAX_STAT_STAGE)
                            break;
                    }
                    if (i != NUM_STATS - 1)
                    {
                        do
                        {
                            i = Random() % (NUM_STATS - 1);
                        } while (gBattleMons[battler].statStages[STAT_ATK + i] == MAX_STAT_STAGE);

                        PREPARE_STAT_BUFFER(gBattleTextBuff1, i + 1);

                        gBattleTextBuff2[0] = B_BUFF_PLACEHOLDER_BEGIN;
                        gBattleTextBuff2[1] = B_BUFF_STRING;
                        gBattleTextBuff2[2] = STRINGID_STATSHARPLY;
                        gBattleTextBuff2[3] = STRINGID_STATSHARPLY >> 8;
                        gBattleTextBuff2[4] = B_BUFF_STRING;
                        gBattleTextBuff2[5] = STRINGID_STATROSE;
                        gBattleTextBuff2[6] = STRINGID_STATROSE >> 8;
                        gBattleTextBuff2[7] = EOS;

                        gEffectBattler = battler;
                        SET_STATCHANGER(i + 1, 2, FALSE);
                        gBattleScripting.animArg1 = STAT_ANIM_PLUS2 + (i + 1);
                        gBattleScripting.animArg2 = 0;
                        BattleScriptExecute(BattleScript_BerryStatRaiseEnd2);
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                break;
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                {
                    gBattleMons[battler].status1 &= ~STATUS1_PARALYSIS;
                    BattleScriptExecute(BattleScript_BerryCurePrlzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[battler].status1 & STATUS1_PSN_ANY)
                {
                    gBattleMons[battler].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptExecute(BattleScript_BerryCurePsnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    gBattleMons[battler].status1 &= ~STATUS1_BURN;
                    BattleScriptExecute(BattleScript_BerryCureBrnEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                {
                    gBattleMons[battler].status1 &= ~STATUS1_FREEZE;
                    BattleScriptExecute(BattleScript_BerryCureFrzEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleMons[battler].status1 &= ~STATUS1_SLEEP;
                    gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                    BattleScriptExecute(BattleScript_BerryCureSlpEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    gBattleMons[battler].status2 &= ~STATUS2_CONFUSION;
                    BattleScriptExecute(BattleScript_BerryCureConfusionEnd2);
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if (gBattleMons[battler].status1 & STATUS1_ANY || gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    i = 0;
                    if (gBattleMons[battler].status1 & STATUS1_PSN_ANY)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_BURN)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);
                        i++;
                    }
                    if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);
                        i++;
                    }
                    if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                    {
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);
                        i++;
                    }
                    if (i <= 1)
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    else
                        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_NORMALIZED_STATUS;
                    gBattleMons[battler].status1 = 0;
                    gBattleMons[battler].status2 &= ~STATUS2_CONFUSION;
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_ATTRACT:
                if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
                {
                    gBattleMons[battler].status2 &= ~STATUS2_INFATUATION;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
                    BattleScriptExecute(BattleScript_BerryCureChosenStatusEnd2);
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            }
            if (effect != 0)
            {
                gBattleScripting.battler = battler;
                gPotentialItemEffectBattler = battler;
                gActiveBattler = gBattlerAttacker = battler;
                switch (effect)
                {
                case ITEM_STATUS_CHANGE:
                    BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[battler].status1);
                    MarkBattlerForControllerExec(gActiveBattler);
                    break;
                case ITEM_PP_CHANGE:
                    if (MOVE_IS_PERMANENT(battler, i))
                        gBattleMons[battler].pp[i] = changedPP;
                    break;
                }
            }
        }
        break;
    case ITEMEFFECT_DUMMY:
        break;
    case ITEMEFFECT_MOVE_END:
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            gLastUsedItem = gBattleMons[battler].item;
            if (gBattleMons[battler].item == ITEM_ENIGMA_BERRY)
            {
                battlerHoldEffect = gEnigmaBerries[battler].holdEffect;
                battlerHoldEffectParam = gEnigmaBerries[battler].holdEffectParam;
            }
            else
            {
                battlerHoldEffect = GetItemHoldEffect(gLastUsedItem);
                battlerHoldEffectParam = GetItemHoldEffectParam(gLastUsedItem);
            }
            switch (battlerHoldEffect)
            {
            case HOLD_EFFECT_CURE_PAR:
                if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                {
                    gBattleMons[battler].status1 &= ~STATUS1_PARALYSIS;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureParRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_PSN:
                if (gBattleMons[battler].status1 & STATUS1_PSN_ANY)
                {
                    gBattleMons[battler].status1 &= ~(STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER);
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCurePsnRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_BRN:
                if (gBattleMons[battler].status1 & STATUS1_BURN)
                {
                    gBattleMons[battler].status1 &= ~STATUS1_BURN;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureBrnRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_FRZ:
                if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                {
                    gBattleMons[battler].status1 &= ~STATUS1_FREEZE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureFrzRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_SLP:
                if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                {
                    gBattleMons[battler].status1 &= ~STATUS1_SLEEP;
                    gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureSlpRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_CURE_CONFUSION:
                if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    gBattleMons[battler].status2 &= ~STATUS2_CONFUSION;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_BerryCureConfusionRet;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_ATTRACT:
                if (gBattleMons[battler].status2 & STATUS2_INFATUATION)
                {
                    gBattleMons[battler].status2 &= ~STATUS2_INFATUATION;
                    StringCopy(gBattleTextBuff1, gStatusConditionString_LoveJpn);
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    gBattlescriptCurrInstr = BattleScript_BerryCureChosenStatusRet;
                    effect = ITEM_EFFECT_OTHER;
                }
                break;
            case HOLD_EFFECT_CURE_STATUS:
                if (gBattleMons[battler].status1 & STATUS1_ANY || gBattleMons[battler].status2 & STATUS2_CONFUSION)
                {
                    if (gBattleMons[battler].status1 & STATUS1_PSN_ANY)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_PoisonJpn);

                    if (gBattleMons[battler].status1 & STATUS1_SLEEP)
                    {
                        gBattleMons[battler].status2 &= ~STATUS2_NIGHTMARE;
                        StringCopy(gBattleTextBuff1, gStatusConditionString_SleepJpn);
                    }

                    if (gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ParalysisJpn);

                    if (gBattleMons[battler].status1 & STATUS1_BURN)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_BurnJpn);

                    if (gBattleMons[battler].status1 & STATUS1_FREEZE)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_IceJpn);

                    if (gBattleMons[battler].status2 & STATUS2_CONFUSION)
                        StringCopy(gBattleTextBuff1, gStatusConditionString_ConfusionJpn);

                    gBattleMons[battler].status1 = 0;
                    gBattleMons[battler].status2 &= ~STATUS2_CONFUSION;
                    BattleScriptPushCursor();
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PROBLEM;
                    gBattlescriptCurrInstr = BattleScript_BerryCureChosenStatusRet;
                    effect = ITEM_STATUS_CHANGE;
                }
                break;
            case HOLD_EFFECT_RESTORE_STATS:
                for (i = 0; i < NUM_BATTLE_STATS; i++)
                {
                    if (gBattleMons[battler].statStages[i] < DEFAULT_STAT_STAGE)
                    {
                        gBattleMons[battler].statStages[i] = DEFAULT_STAT_STAGE;
                        effect = ITEM_STATS_CHANGE;
                    }
                }
                if (effect != 0)
                {
                    gBattleScripting.battler = battler;
                    gPotentialItemEffectBattler = battler;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_WhiteHerbRet;
                    return effect;
                }
                break;
            }
            if (effect != 0)
            {
                gBattleScripting.battler = battler;
                gPotentialItemEffectBattler = battler;
                gActiveBattler = battler;
                BtlController_EmitSetMonData(B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[gActiveBattler].status1);
                MarkBattlerForControllerExec(gActiveBattler);
                break;
            }
        }
        break;
    case ITEMEFFECT_KINGSROCK_SHELLBELL:
        if (gBattleMoveDamage)
        {
            switch (atkHoldEffect)
            {
            case HOLD_EFFECT_FLINCH:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && TARGET_TURN_DAMAGED
                    && (Random() % 100) < atkHoldEffectParam
                    && gBattleMoves[gCurrentMove].flags & FLAG_KINGS_ROCK_AFFECTED
                    && gBattleMons[gBattlerTarget].hp)
                {
                    gBattleCommunication[MOVE_EFFECT_BYTE] = MOVE_EFFECT_FLINCH;
                    BattleScriptPushCursor();
                    SetMoveEffect(FALSE, 0);
                    HandleAction_RunBattleScript();
                }
                break;
            case HOLD_EFFECT_SHELL_BELL:
                if (!(gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
                    && gSpecialStatuses[gBattlerTarget].shellBellDmg != 0
                    && gSpecialStatuses[gBattlerTarget].shellBellDmg != IGNORE_SHELL_BELL
                    && gBattlerAttacker != gBattlerTarget
                    && gBattleMons[gBattlerAttacker].hp != gBattleMons[gBattlerAttacker].maxHP
                    && gBattleMons[gBattlerAttacker].hp != 0)
                {
                    gLastUsedItem = atkItem;
                    gPotentialItemEffectBattler = gBattlerAttacker;
                    gBattleScripting.battler = gBattlerAttacker;
                    gBattleMoveDamage = (gSpecialStatuses[gBattlerTarget].shellBellDmg / atkHoldEffectParam) * -1;
                    if (gBattleMoveDamage == 0)
                        gBattleMoveDamage = -1;
                    gSpecialStatuses[gBattlerTarget].shellBellDmg = 0;
                    BattleScriptPushCursor();
                    gBattlescriptCurrInstr = BattleScript_ItemHealHP_Ret;
                    effect++;
                }
                break;
            }
        }
        break;
    }

    return effect;
}

void ClearFuryCutterDestinyBondGrudge(u8 battler)
{
    gDisableStructs[battler].furyCutterCounter = 0;
    gBattleMons[battler].status2 &= ~STATUS2_DESTINY_BOND;
    gStatuses3[battler] &= ~STATUS3_GRUDGE;
}

void sub_080454F4(void)
{
    if (gBattleControllerExecFlags == 0)
        gBattleScriptingCommandsTable[*gBattlescriptCurrInstr]();
}

u8 GetMoveTarget(u16 move, u8 setTarget)
{
    u8 targetBattler = 0;
    u8 moveTarget;
    u8 side;

    if (setTarget != NO_TARGET_OVERRIDE)
        moveTarget = setTarget - 1;
    else
        moveTarget = gBattleMoves[move].target;

    switch (moveTarget)
    {
    case MOVE_TARGET_SELECTED:
        side = BATTLE_OPPOSITE(GetBattlerSide(gBattlerAttacker));
        if (gSideTimers[side].followmeTimer && gBattleMons[gSideTimers[side].followmeTarget].hp)
        {
            targetBattler = gSideTimers[side].followmeTarget;
        }
        else
        {
            side = GetBattlerSide(gBattlerAttacker);
            do
            {
                targetBattler = Random() % gBattlersCount;
            } while (targetBattler == gBattlerAttacker || side == GetBattlerSide(targetBattler) || gAbsentBattlerFlags & gBitTable[targetBattler]);
            if (gBattleMoves[move].type == TYPE_ELECTRIC
                && AbilityBattleEffects(ABILITYEFFECT_COUNT_OTHER_SIDE, gBattlerAttacker, ABILITY_LIGHTNING_ROD, 0, 0)
                && gBattleMons[targetBattler].ability != ABILITY_LIGHTNING_ROD)
            {
                targetBattler ^= BIT_FLANK;
                RecordAbilityBattle(targetBattler, gBattleMons[targetBattler].ability);
                gSpecialStatuses[targetBattler].lightningRodRedirected = 1;
            }
        }
        break;
    case MOVE_TARGET_DEPENDS:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
    case MOVE_TARGET_OPPONENTS_FIELD:
        targetBattler = GetBattlerAtPosition(BATTLE_OPPOSITE(GET_BATTLER_SIDE(gBattlerAttacker)));
        if (gAbsentBattlerFlags & gBitTable[targetBattler])
            targetBattler ^= BIT_FLANK;
        break;
    case MOVE_TARGET_RANDOM:
        side = BATTLE_OPPOSITE(GetBattlerSide(gBattlerAttacker));
        if (gSideTimers[side].followmeTimer && gBattleMons[gSideTimers[side].followmeTarget].hp)
        {
            targetBattler = gSideTimers[side].followmeTarget;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && moveTarget & MOVE_TARGET_RANDOM)
        {
            if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
            {
                if (Random() & 1)
                    targetBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
                else
                    targetBattler = GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT);
            }
            else
            {
                if (Random() & 1)
                    targetBattler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
                else
                    targetBattler = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
            }
            if (gAbsentBattlerFlags & gBitTable[targetBattler])
                targetBattler ^= BIT_FLANK;
        }
        else
        {
            targetBattler = GetBattlerAtPosition(BATTLE_OPPOSITE(GET_BATTLER_SIDE(gBattlerAttacker)));
        }
        break;
    case MOVE_TARGET_USER_OR_SELECTED:
    case MOVE_TARGET_USER:
        targetBattler = gBattlerAttacker;
        break;
    }

    *(gBattleStruct->moveTarget + gBattlerAttacker) = targetBattler;

    return targetBattler;
}

bool32 IsBattlerModernFatefulEncounter(u8 battler)
{
    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        return TRUE;
    if (GetMonData3(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES, NULL) != SPECIES_DEOXYS
        && GetMonData3(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES, NULL) != SPECIES_MEW)
            return TRUE;
    return GetMonData3(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_MODERN_FATEFUL_ENCOUNTER, NULL);
}

u8 IsMonDisobedient(void)
{
    s32 rnd;
    s32 calc;
    u8 obedienceLevel = 0;

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        return DISOBEDIENCE_OBEDIENT;
    if (GetBattlerSide(gBattlerAttacker) == B_SIDE_OPPONENT)
        return DISOBEDIENCE_OBEDIENT;

    if (IsBattlerModernFatefulEncounter(gBattlerAttacker)) // only false if illegal Mew or Deoxys
    {
        u8 badgeFlag;
        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gBattlerAttacker) == 2)
            return DISOBEDIENCE_OBEDIENT;
        if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
            return DISOBEDIENCE_OBEDIENT;
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            return DISOBEDIENCE_OBEDIENT;
        if (!IsOtherTrainer(gBattleMons[gBattlerAttacker].otId, gBattleMons[gBattlerAttacker].otName))
            return DISOBEDIENCE_OBEDIENT;
        badgeFlag = FlagGet(FLAG_BADGE08_GET);
        if (badgeFlag)
            return DISOBEDIENCE_OBEDIENT;

        obedienceLevel = 10;

        badgeFlag = FlagGet(FLAG_BADGE02_GET);
        if (badgeFlag)
            obedienceLevel = 30;
        badgeFlag = FlagGet(FLAG_BADGE04_GET);
        if (badgeFlag)
            obedienceLevel = 50;
        badgeFlag = FlagGet(FLAG_BADGE06_GET);
        if (badgeFlag)
            obedienceLevel = 70;
    }

    if (gBattleMons[gBattlerAttacker].level <= obedienceLevel)
        return DISOBEDIENCE_OBEDIENT;
    rnd = (Random() & 255);
    calc = (gBattleMons[gBattlerAttacker].level + obedienceLevel) * rnd >> 8;
    if (calc < obedienceLevel)
        return DISOBEDIENCE_OBEDIENT;

    // is not obedient
    if (gCurrentMove == MOVE_RAGE)
        gBattleMons[gBattlerAttacker].status2 &= ~STATUS2_RAGE;
    if (gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP && (gCurrentMove == MOVE_SNORE || gCurrentMove == MOVE_SLEEP_TALK))
    {
        gBattlescriptCurrInstr = BattleScript_IgnoresWhileAsleep;
        return DISOBEDIENCE_IGNORED;
    }

    rnd = (Random() & 255);
    calc = (gBattleMons[gBattlerAttacker].level + obedienceLevel) * rnd >> 8;
    if (calc < obedienceLevel)
    {
        calc = CheckMoveLimitations(gBattlerAttacker, gBitTable[gCurrMovePos], MOVE_LIMITATIONS_ALL);
        if (calc == ALL_MOVES_MASK) // all moves cannot be used
        {
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = MOD(Random(), NUM_LOAF_STRINGS);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            return DISOBEDIENCE_IGNORED;
        }
        else // use a random move
        {
            do
            {
                gCurrMovePos = gChosenMovePos = MOD(Random(), MAX_MON_MOVES);
            } while (gBitTable[gCurrMovePos] & calc);

            gCalledMove = gBattleMons[gBattlerAttacker].moves[gCurrMovePos];
            gBattlescriptCurrInstr = BattleScript_IgnoresAndUsesRandomMove;
            gBattlerTarget = GetMoveTarget(gCalledMove, NO_TARGET_OVERRIDE);
            gHitMarker |= HITMARKER_DISOBEDIENT_MOVE;
            return DISOBEDIENCE_OTHER;
        }
    }
    else
    {
        obedienceLevel = gBattleMons[gBattlerAttacker].level - obedienceLevel;

        calc = (Random() & 255);
        if (calc < obedienceLevel && !(gBattleMons[gBattlerAttacker].status1 & STATUS1_ANY) && gBattleMons[gBattlerAttacker].ability != ABILITY_VITAL_SPIRIT && gBattleMons[gBattlerAttacker].ability != ABILITY_INSOMNIA)
        {
            // try putting asleep
            int i;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (gBattleMons[i].status2 & STATUS2_UPROAR)
                    break;
            }
            if (i == gBattlersCount)
            {
                gBattlescriptCurrInstr = BattleScript_IgnoresAndFallsAsleep;
                return DISOBEDIENCE_IGNORED;
            }
        }
        calc -= obedienceLevel;
        if (calc < obedienceLevel)
        {
            gBattleMoveDamage = CalculateBaseDamage(&gBattleMons[gBattlerAttacker], &gBattleMons[gBattlerAttacker], MOVE_POUND, 0, 40, 0, gBattlerAttacker, gBattlerAttacker);
            gBattlerTarget = gBattlerAttacker;
            gBattlescriptCurrInstr = BattleScript_IgnoresAndHitsItself;
            gHitMarker |= HITMARKER_UNABLE_TO_USE_MOVE;
            return DISOBEDIENCE_OTHER;
        }
        else
        {
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = MOD(Random(), NUM_LOAF_STRINGS);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            return DISOBEDIENCE_IGNORED;
        }
    }
}

__attribute__((naked)) void sub_0803DCCC(void)
{
    __asm__(".syntax unified\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0803DCEC\n\t"
        "	ldr r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803DCE8\n\t"
        "	ldr r1, _0803DCF0\n\t"
        "	ldr r0, _0803DCF4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl _call_via_r0\n\t"
        "_0803DCE8:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803DCEC: .4byte gBattleControllerExecFlags\n\t"
        "_0803DCF0: .4byte gBattleScriptingCommandsTable\n\t"
        "_0803DCF4: .4byte gBattlescriptCurrInstr\n\t"
        ".syntax divided\n\t"
    );
}
void HandleAction_Switch(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gActionSelectionCursor[gBattlerAttacker] = 0;
    gMoveSelectionCursor[gBattlerAttacker] = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, *(gBattleStruct->battlerPartyIndexes + gBattlerAttacker))

    gBattleScripting.battler = gBattlerAttacker;
    gBattlescriptCurrInstr = BattleScript_ActionSwitch;
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;

    if (gBattleResults.playerSwitchesCounter < 255)
        gBattleResults.playerSwitchesCounter++;
}

void HandleAction_Run(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];

    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
    {
        gCurrentTurnActionNumber = gBattlersCount;

        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_LOST;
            }
            else
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                    gBattleOutcome |= B_OUTCOME_WON;
            }
        }

        gBattleOutcome |= B_OUTCOME_LINK_BATTLE_RAN;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else
    {
        if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
        {
            if (!TryRunFromBattle(gBattlerAttacker)) // failed to run away
            {
                ClearFuryCutterDestinyBondGrudge(gBattlerAttacker);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_ESCAPE_2;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
        }
        else
        {
            if (gBattleMons[gBattlerAttacker].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ATTACKER_CANT_ESCAPE;
                gBattlescriptCurrInstr = BattleScript_PrintFailedToRunString;
                gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
            }
            else
            {
                gCurrentTurnActionNumber = gBattlersCount;
                gBattleOutcome = B_OUTCOME_MON_FLED;
            }
        }
    }
}

void HandleAction_WatchesCarefully(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[0];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_SafariZoneBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gNumSafariBalls--;
    gLastUsedItem = ITEM_SAFARI_BALL;
    gBattlescriptCurrInstr = gBattlescriptsForBallThrow[ITEM_SAFARI_BALL];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_ThrowPokeblock(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattleCommunication[MULTISTRING_CHOOSER] = gBattleBufferB[gBattlerAttacker][1] - 1;
    gLastUsedItem = gBattleBufferB[gBattlerAttacker][2];

    if (gBattleResults.pokeblockThrows < 255)
        gBattleResults.pokeblockThrows++;
    if (gBattleStruct->safariPkblThrowCounter < 3)
        gBattleStruct->safariPkblThrowCounter++;
    if (gBattleStruct->safariEscapeFactor > 1)
    {
        if (gBattleStruct->safariEscapeFactor < sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]])
            gBattleStruct->safariEscapeFactor = 1;
        else
            gBattleStruct->safariEscapeFactor -= sPkblToEscapeFactor[gBattleStruct->safariPkblThrowCounter][gBattleCommunication[MULTISTRING_CHOOSER]];
    }

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[2];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_GoNear(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    gBattleStruct->safariCatchFactor += sGoNearCounterToCatchFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariCatchFactor > 20)
        gBattleStruct->safariCatchFactor = 20;

    gBattleStruct->safariEscapeFactor += sGoNearCounterToEscapeFactor[gBattleStruct->safariGoNearCounter];
    if (gBattleStruct->safariEscapeFactor > 20)
        gBattleStruct->safariEscapeFactor = 20;

    if (gBattleStruct->safariGoNearCounter < 3)
    {
        gBattleStruct->safariGoNearCounter++;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CREPT_CLOSER;
    }
    else
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CANT_GET_CLOSER;
    }
    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[1];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
}

void HandleAction_SafariZoneRun(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    PlaySE(SE_FLEE);
    gCurrentTurnActionNumber = gBattlersCount;
    gBattleOutcome = B_OUTCOME_RAN;
}

void HandleAction_WallyBallThrow(void)
{
    gBattlerAttacker = gBattlerByTurnOrder[gCurrentTurnActionNumber];
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker])

    gBattlescriptCurrInstr = gBattlescriptsForSafariActions[3];
    gCurrentActionFuncId = B_ACTION_EXEC_SCRIPT;
    gActionsByTurnOrder[1] = B_ACTION_FINISHED;
}

void HandleAction_NothingIsFainted(void)
{
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_STATUS_ABILITY_EFFECT | HITMARKER_IGNORE_ON_AIR
                    | HITMARKER_IGNORE_UNDERGROUND | HITMARKER_IGNORE_UNDERWATER | HITMARKER_PASSIVE_HP_UPDATE
                    | HITMARKER_OBEYS | HITMARKER_WAKE_UP_CLEAR | HITMARKER_SYNCHRONIZE_EFFECT
                    | HITMARKER_CHARGING | HITMARKER_NEVER_SET);
}

void HandleAction_ActionFinished(void)
{
    *(gBattleStruct->monToSwitchIntoId + gBattlerByTurnOrder[gCurrentTurnActionNumber]) = PARTY_SIZE;
    gCurrentTurnActionNumber++;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    SpecialStatusesClear();
    gHitMarker &= ~(HITMARKER_DESTINYBOND | HITMARKER_IGNORE_SUBSTITUTE | HITMARKER_ATTACKSTRING_PRINTED
                    | HITMARKER_NO_PPDEDUCT | HITMARKER_STATUS_ABILITY_EFFECT | HITMARKER_IGNORE_ON_AIR
                    | HITMARKER_IGNORE_UNDERGROUND | HITMARKER_IGNORE_UNDERWATER | HITMARKER_PASSIVE_HP_UPDATE
                    | HITMARKER_OBEYS | HITMARKER_WAKE_UP_CLEAR | HITMARKER_SYNCHRONIZE_EFFECT
                    | HITMARKER_CHARGING | HITMARKER_NEVER_SET);

    gCurrentMove = 0;
    gBattleMoveDamage = 0;
    gMoveResultFlags = 0;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;
    gLastLandedMoves[gBattlerAttacker] = 0;
    gLastResultingMoves[gBattlerAttacker] = 0; // JP: uses gLastResultingMoves (US: gLastHitByType)
    gBattleStruct->dynamicMoveType = 0;
    gDynamicBasePower = 0;
    gBattleScripting.moveendState = 0;
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleScripting.multihitMoveEffect = 0;
    gBattleResources->battleScriptsStack->size = 0;
}







__attribute__((naked)) void HandleAction_UseItem(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	ldr r4, _0803E5AC\n\t"
        "	ldr r2, _0803E5B0\n\t"
        "	ldr r1, _0803E5B4\n\t"
        "	ldr r0, _0803E5B8\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r2]\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r0, _0803E5BC\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0]\n\t"
        "	ldr r0, _0803E5C0\n\t"
        "	strh r1, [r0]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl ClearFuryCutterDestinyBondGrudge\n\t"
        "	ldr r5, _0803E5C4\n\t"
        "	ldr r2, _0803E5C8\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r1, r1, #9\n\t"
        "	adds r0, r2, #1\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldrb r3, [r0]\n\t"
        "	adds r2, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r3, r0\n\t"
        "	strh r3, [r5]\n\t"
        "	cmp r3, #0xc\n\t"
        "	bhi _0803E5D8\n\t"
        "	ldr r2, _0803E5CC\n\t"
        "	ldr r1, _0803E5D0\n\t"
        "	ldrh r0, [r5]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r2]\n\t"
        "	ldr r0, _0803E5D4\n\t"
        "	mov sl, r0\n\t"
        "	b _0803E836\n\t"
        "	.align 2, 0\n\t"
        "_0803E5AC: .4byte gBattlerAttacker\n\t"
        "_0803E5B0: .4byte gBattlerTarget\n\t"
        "_0803E5B4: .4byte gBattlerByTurnOrder\n\t"
        "_0803E5B8: .4byte gCurrentTurnActionNumber\n\t"
        "_0803E5BC: .4byte gBattle_BG0_X\n\t"
        "_0803E5C0: .4byte gBattle_BG0_Y\n\t"
        "_0803E5C4: .4byte gLastUsedItem\n\t"
        "_0803E5C8: .4byte gBattleBufferB\n\t"
        "_0803E5CC: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E5D0: .4byte gBattlescriptsForBallThrow\n\t"
        "_0803E5D4: .4byte gCurrentActionFuncId\n\t"
        "_0803E5D8:\n\t"
        "	adds r0, r3, #0\n\t"
        "	subs r0, #0x50\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _0803E600\n\t"
        "	ldr r0, _0803E5F4\n\t"
        "	ldr r1, _0803E5F8\n\t"
        "	ldr r1, [r1]\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r1, _0803E5FC\n\t"
        "	mov sl, r1\n\t"
        "	b _0803E836\n\t"
        "	.align 2, 0\n\t"
        "_0803E5F4: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E5F8: .4byte gBattlescriptsForRunningByItem\n\t"
        "_0803E5FC: .4byte gCurrentActionFuncId\n\t"
        "_0803E600:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E628\n\t"
        "	ldr r0, _0803E61C\n\t"
        "	ldr r1, _0803E620\n\t"
        "	ldr r1, [r1]\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r2, _0803E624\n\t"
        "	mov sl, r2\n\t"
        "	b _0803E836\n\t"
        "	.align 2, 0\n\t"
        "_0803E61C: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E620: .4byte gBattlescriptsForUsingItem\n\t"
        "_0803E624: .4byte gCurrentActionFuncId\n\t"
        "_0803E628:\n\t"
        "	ldr r3, _0803E660\n\t"
        "	ldrb r0, [r4]\n\t"
        "	strb r0, [r3, #0x17]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	ldr r2, _0803E664\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	subs r0, #1\n\t"
        "	mov r8, r4\n\t"
        "	ldr r1, _0803E668\n\t"
        "	mov sb, r1\n\t"
        "	ldr r6, _0803E66C\n\t"
        "	mov ip, r3\n\t"
        "	adds r7, r2, #0\n\t"
        "	ldr r2, _0803E670\n\t"
        "	mov sl, r2\n\t"
        "	cmp r0, #4\n\t"
        "	bls _0803E654\n\t"
        "	b _0803E81E\n\t"
        "_0803E654:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0803E674\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0803E660: .4byte gBattleScripting\n\t"
        "_0803E664: .4byte gBattleStruct\n\t"
        "_0803E668: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E66C: .4byte gBattlescriptsForUsingItem\n\t"
        "_0803E670: .4byte gCurrentActionFuncId\n\t"
        "_0803E674: .4byte 0x0803E678\n\t"
        "_0803E678: @ jump table\n\t"
        "	.4byte _0803E81E @ case 0\n\t"
        "	.4byte _0803E81E @ case 1\n\t"
        "	.4byte _0803E68C @ case 2\n\t"
        "	.4byte _0803E720 @ case 3\n\t"
        "	.4byte _0803E7F0 @ case 4\n\t"
        "_0803E68C:\n\t"
        "	ldr r5, _0803E6C4\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r5, #5]\n\t"
        "	ldr r2, _0803E6C8\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r7]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	mov r8, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E6D8\n\t"
        "	movs r0, #0x3e\n\t"
        "	ands r0, r1\n\t"
        "	ldr r1, _0803E6CC\n\t"
        "	mov sb, r1\n\t"
        "	ldr r6, _0803E6D0\n\t"
        "	ldr r2, _0803E6D4\n\t"
        "	mov sl, r2\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E6BE\n\t"
        "	b _0803E81E\n\t"
        "_0803E6BE:\n\t"
        "	movs r0, #5\n\t"
        "	strb r0, [r5, #5]\n\t"
        "	b _0803E81E\n\t"
        "	.align 2, 0\n\t"
        "_0803E6C4: .4byte gBattleCommunication\n\t"
        "_0803E6C8: .4byte gBattlerAttacker\n\t"
        "_0803E6CC: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E6D0: .4byte gBattlescriptsForUsingItem\n\t"
        "_0803E6D4: .4byte gCurrentActionFuncId\n\t"
        "_0803E6D8:\n\t"
        "	ldr r0, _0803E714\n\t"
        "	mov sb, r0\n\t"
        "	ldr r6, _0803E718\n\t"
        "	ldr r1, _0803E71C\n\t"
        "	mov sl, r1\n\t"
        "	mov r4, r8\n\t"
        "	adds r3, r7, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "_0803E6E8:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsrs r1, r1, #1\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xc6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r2, #5]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r2, #5]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E6E8\n\t"
        "	b _0803E81E\n\t"
        "	.align 2, 0\n\t"
        "_0803E714: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E718: .4byte gBattlescriptsForUsingItem\n\t"
        "_0803E71C: .4byte gCurrentActionFuncId\n\t"
        "_0803E720:\n\t"
        "	ldr r3, _0803E754\n\t"
        "	movs r0, #4\n\t"
        "	strb r0, [r3, #5]\n\t"
        "	ldr r2, _0803E758\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r7]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r6, #0xc6\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	mov r8, r2\n\t"
        "	cmp r5, #0\n\t"
        "	beq _0803E768\n\t"
        "	movs r0, #5\n\t"
        "	strb r0, [r3, #5]\n\t"
        "	ldr r2, _0803E75C\n\t"
        "	mov sb, r2\n\t"
        "	ldr r6, _0803E760\n\t"
        "	ldr r0, _0803E764\n\t"
        "	mov sl, r0\n\t"
        "	b _0803E81E\n\t"
        "	.align 2, 0\n\t"
        "_0803E754: .4byte gBattleCommunication\n\t"
        "_0803E758: .4byte gBattlerAttacker\n\t"
        "_0803E75C: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E760: .4byte gBattlescriptsForUsingItem\n\t"
        "_0803E764: .4byte gCurrentActionFuncId\n\t"
        "_0803E768:\n\t"
        "	ldr r3, _0803E7DC\n\t"
        "	movs r4, #0xfd\n\t"
        "	strb r4, [r3]\n\t"
        "	movs r0, #5\n\t"
        "	strb r0, [r3, #1]\n\t"
        "	movs r2, #1\n\t"
        "	strb r2, [r3, #2]\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r3, #3]\n\t"
        "	ldr r1, _0803E7E0\n\t"
        "	strb r4, [r1]\n\t"
        "	strb r5, [r1, #1]\n\t"
        "	movs r0, #0xd2\n\t"
        "	strb r0, [r1, #2]\n\t"
        "	strb r5, [r1, #3]\n\t"
        "	subs r0, #0xd3\n\t"
        "	strb r0, [r1, #4]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ands r2, r0\n\t"
        "	ldr r1, _0803E7E4\n\t"
        "	mov sb, r1\n\t"
        "	ldr r6, _0803E7E8\n\t"
        "	ldr r0, _0803E7EC\n\t"
        "	mov sl, r0\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0803E7CC\n\t"
        "	mov r5, r8\n\t"
        "	adds r4, r7, #0\n\t"
        "	adds r2, r3, #0\n\t"
        "_0803E7A2:\n\t"
        "	ldrb r1, [r5]\n\t"
        "	lsrs r1, r1, #1\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xc6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r2, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r2, #2]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E7A2\n\t"
        "_0803E7CC:\n\t"
        "	ldrb r0, [r3, #2]\n\t"
        "	adds r0, #0xe\n\t"
        "	movs r1, #0\n\t"
        "	mov r2, ip\n\t"
        "	strb r0, [r2, #0x10]\n\t"
        "	strb r1, [r2, #0x11]\n\t"
        "	b _0803E81E\n\t"
        "	.align 2, 0\n\t"
        "_0803E7DC: .4byte gBattleTextBuff1\n\t"
        "_0803E7E0: .4byte gBattleTextBuff2\n\t"
        "_0803E7E4: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E7E8: .4byte gBattlescriptsForUsingItem\n\t"
        "_0803E7EC: .4byte gCurrentActionFuncId\n\t"
        "_0803E7F0:\n\t"
        "	ldr r0, _0803E804\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E80C\n\t"
        "	ldr r1, _0803E808\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	b _0803E810\n\t"
        "	.align 2, 0\n\t"
        "_0803E804: .4byte gBattleTypeFlags\n\t"
        "_0803E808: .4byte gBattleCommunication\n\t"
        "_0803E80C:\n\t"
        "	ldr r0, _0803E84C\n\t"
        "	strb r1, [r0, #5]\n\t"
        "_0803E810:\n\t"
        "	ldr r0, _0803E850\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _0803E854\n\t"
        "	mov sb, r1\n\t"
        "	ldr r6, _0803E858\n\t"
        "	ldr r2, _0803E85C\n\t"
        "	mov sl, r2\n\t"
        "_0803E81E:\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	ldr r1, [r7]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov r2, sb\n\t"
        "	str r0, [r2]\n\t"
        "_0803E836:\n\t"
        "	movs r0, #0xa\n\t"
        "	mov r1, sl\n\t"
        "	strb r0, [r1]\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803E84C: .4byte gBattleCommunication\n\t"
        "_0803E850: .4byte gBattlerAttacker\n\t"
        "_0803E854: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E858: .4byte gBattlescriptsForUsingItem\n\t"
        "_0803E85C: .4byte gCurrentActionFuncId\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) bool8 TryRunFromBattle(u8 battler)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	movs r7, #0\n\t"
        "	ldr r1, _0803E88C\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r1, r0, r1\n\t"
        "	ldrh r0, [r1, #0x2e]\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bne _0803E894\n\t"
        "	ldr r1, _0803E890\n\t"
        "	lsls r0, r5, #3\n\t"
        "	subs r0, r0, r5\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	b _0803E89E\n\t"
        "	.align 2, 0\n\t"
        "_0803E88C: .4byte gBattleMons\n\t"
        "_0803E890: .4byte gEnigmaBerries\n\t"
        "_0803E894:\n\t"
        "	ldrh r0, [r1, #0x2e]\n\t"
        "	bl sub_080D6CF8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "_0803E89E:\n\t"
        "	ldr r0, _0803E8CC\n\t"
        "	strb r5, [r0]\n\t"
        "	cmp r1, #0x25\n\t"
        "	bne _0803E8DC\n\t"
        "	ldr r2, _0803E8D0\n\t"
        "	ldr r1, _0803E8D4\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0x2e]\n\t"
        "	strh r0, [r2]\n\t"
        "	ldr r0, _0803E8D8\n\t"
        "	lsls r2, r5, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldrb r1, [r2, #1]\n\t"
        "	movs r0, #0x19\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #1]\n\t"
        "	b _0803E9B0\n\t"
        "	.align 2, 0\n\t"
        "_0803E8CC: .4byte gPotentialItemEffectBattler\n\t"
        "_0803E8D0: .4byte gLastUsedItem\n\t"
        "_0803E8D4: .4byte gBattleMons\n\t"
        "_0803E8D8: .4byte gProtectStructs\n\t"
        "_0803E8DC:\n\t"
        "	ldr r0, _0803E968\n\t"
        "	mov sl, r0\n\t"
        "	movs r2, #0x58\n\t"
        "	mov sb, r2\n\t"
        "	mov r0, sb\n\t"
        "	muls r0, r5, r0\n\t"
        "	add r0, sl\n\t"
        "	mov r8, r0\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r6, [r0]\n\t"
        "	cmp r6, #0x32\n\t"
        "	bne _0803E99C\n\t"
        "	bl CurrentBattlePyramidLocation\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E978\n\t"
        "	ldr r4, _0803E96C\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, #0x6c\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	bl GetPyramidRunMultiplier\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	mov r2, r8\n\t"
        "	ldrh r0, [r2, #6]\n\t"
        "	muls r0, r1, r0\n\t"
        "	movs r2, #1\n\t"
        "	adds r1, r5, #0\n\t"
        "	eors r1, r2\n\t"
        "	mov r2, sb\n\t"
        "	muls r2, r1, r2\n\t"
        "	adds r1, r2, #0\n\t"
        "	add r1, sl\n\t"
        "	ldrh r1, [r1, #6]\n\t"
        "	bl __divsi3\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, #0x6c\n\t"
        "	ldrb r2, [r1]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	subs r1, r1, r2\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl Random\n\t"
        "	movs r1, #0xff\n\t"
        "	ands r1, r0\n\t"
        "	cmp r4, r1\n\t"
        "	bhi _0803E94C\n\t"
        "	b _0803EA52\n\t"
        "_0803E94C:\n\t"
        "	ldr r0, _0803E970\n\t"
        "	strb r6, [r0]\n\t"
        "	ldr r0, _0803E974\n\t"
        "	lsls r2, r5, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldrb r1, [r2, #1]\n\t"
        "	movs r0, #0x19\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x10\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #1]\n\t"
        "	b _0803E9B0\n\t"
        "	.align 2, 0\n\t"
        "_0803E968: .4byte gBattleMons\n\t"
        "_0803E96C: .4byte gBattleStruct\n\t"
        "_0803E970: .4byte gLastUsedAbility\n\t"
        "_0803E974: .4byte gProtectStructs\n\t"
        "_0803E978:\n\t"
        "	ldr r0, _0803E994\n\t"
        "	strb r6, [r0]\n\t"
        "	ldr r0, _0803E998\n\t"
        "	lsls r2, r5, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldrb r1, [r2, #1]\n\t"
        "	movs r0, #0x19\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x10\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #1]\n\t"
        "	b _0803E9B0\n\t"
        "	.align 2, 0\n\t"
        "_0803E994: .4byte gLastUsedAbility\n\t"
        "_0803E998: .4byte gProtectStructs\n\t"
        "_0803E99C:\n\t"
        "	ldr r1, _0803E9B8\n\t"
        "	ldr r2, [r1]\n\t"
        "	ldr r0, _0803E9BC\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E9C0\n\t"
        "	movs r0, #8\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0803E9C0\n\t"
        "_0803E9B0:\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	b _0803EA52\n\t"
        "	.align 2, 0\n\t"
        "_0803E9B8: .4byte gBattleTypeFlags\n\t"
        "_0803E9BC: .4byte 0x043F0100\n\t"
        "_0803E9C0:\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803EA46\n\t"
        "	bl CurrentBattlePyramidLocation\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E9FC\n\t"
        "	bl GetPyramidRunMultiplier\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	ldr r4, _0803E9F8\n\t"
        "	movs r3, #0x58\n\t"
        "	adds r0, r5, #0\n\t"
        "	muls r0, r3, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r0, [r0, #6]\n\t"
        "	muls r0, r1, r0\n\t"
        "	movs r2, #1\n\t"
        "	adds r1, r5, #0\n\t"
        "	eors r1, r2\n\t"
        "	muls r1, r3, r1\n\t"
        "	adds r1, r1, r4\n\t"
        "	b _0803EA1A\n\t"
        "	.align 2, 0\n\t"
        "_0803E9F8: .4byte gBattleMons\n\t"
        "_0803E9FC:\n\t"
        "	ldr r3, _0803EA74\n\t"
        "	movs r2, #0x58\n\t"
        "	adds r0, r5, #0\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r4, r0, r3\n\t"
        "	movs r1, #1\n\t"
        "	adds r0, r5, #0\n\t"
        "	eors r0, r1\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r1, r0, r3\n\t"
        "	ldrh r0, [r4, #6]\n\t"
        "	ldrh r2, [r1, #6]\n\t"
        "	cmp r0, r2\n\t"
        "	bhs _0803EA40\n\t"
        "	lsls r0, r0, #7\n\t"
        "_0803EA1A:\n\t"
        "	ldrh r1, [r1, #6]\n\t"
        "	bl __divsi3\n\t"
        "	ldr r1, _0803EA78\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, #0x6c\n\t"
        "	ldrb r2, [r1]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	subs r1, r1, r2\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl Random\n\t"
        "	movs r1, #0xff\n\t"
        "	ands r1, r0\n\t"
        "	cmp r4, r1\n\t"
        "	bls _0803EA46\n\t"
        "_0803EA40:\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "_0803EA46:\n\t"
        "	ldr r0, _0803EA78\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r1, #0x6c\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "_0803EA52:\n\t"
        "	cmp r7, #0\n\t"
        "	beq _0803EA64\n\t"
        "	ldr r1, _0803EA7C\n\t"
        "	ldr r0, _0803EA80\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803EA84\n\t"
        "	movs r0, #4\n\t"
        "	strb r0, [r1]\n\t"
        "_0803EA64:\n\t"
        "	adds r0, r7, #0\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0803EA74: .4byte gBattleMons\n\t"
        "_0803EA78: .4byte gBattleStruct\n\t"
        "_0803EA7C: .4byte gCurrentTurnActionNumber\n\t"
        "_0803EA80: .4byte gBattlersCount\n\t"
        "_0803EA84: .4byte gBattleOutcome\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void HandleAction_UseMove(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	movs r0, #4\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r6, _0803DD38\n\t"
        "	ldr r1, _0803DD3C\n\t"
        "	ldr r0, _0803DD40\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r6]\n\t"
        "	ldr r1, _0803DD44\n\t"
        "	ldr r3, [r1]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x91\n\t"
        "	ldrb r2, [r0]\n\t"
        "	ldr r1, _0803DD48\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0803DD50\n\t"
        "	ldr r1, _0803DD4C\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0803E47C\n\t"
        "	.align 2, 0\n\t"
        "_0803DD38: .4byte gBattlerAttacker\n\t"
        "_0803DD3C: .4byte gBattlerByTurnOrder\n\t"
        "_0803DD40: .4byte gCurrentTurnActionNumber\n\t"
        "_0803DD44: .4byte gBattleStruct\n\t"
        "_0803DD48: .4byte gBitTable\n\t"
        "_0803DD4C: .4byte gCurrentActionFuncId\n\t"
        "_0803DD50:\n\t"
        "	ldr r1, _0803DDC8\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803DDCC\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1, #0xe]\n\t"
        "	ldr r5, _0803DDD0\n\t"
        "	adds r0, r3, r5\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, _0803DDD4\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, _0803DDD8\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, _0803DDDC\n\t"
        "	strb r2, [r0, #6]\n\t"
        "	ldr r2, _0803DDE0\n\t"
        "	ldr r0, _0803DDE4\n\t"
        "	mov sb, r0\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r3, _0803DDE8\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x80\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov r5, sb\n\t"
        "	strb r0, [r5]\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r1, _0803DDEC\n\t"
        "	ldrb r4, [r6]\n\t"
        "	lsls r0, r4, #4\n\t"
        "	adds r3, r0, r1\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r0, r1, #0x1d\n\t"
        "	mov r8, r2\n\t"
        "	cmp r0, #0\n\t"
        "	bge _0803DDFC\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	ldr r2, _0803DDF0\n\t"
        "	ldr r1, _0803DDF4\n\t"
        "	movs r0, #0xa5\n\t"
        "	strh r0, [r1]\n\t"
        "	strh r0, [r2]\n\t"
        "	ldr r2, _0803DDF8\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "	movs r0, #0xa5\n\t"
        "	movs r1, #0\n\t"
        "	bl GetMoveTarget\n\t"
        "	ldrb r1, [r6]\n\t"
        "	ldr r3, _0803DDE8\n\t"
        "	ldr r2, [r3]\n\t"
        "	b _0803DF56\n\t"
        "	.align 2, 0\n\t"
        "_0803DDC8: .4byte gCritMultiplier\n\t"
        "_0803DDCC: .4byte gBattleScripting\n\t"
        "_0803DDD0: .4byte SPECIAL_WonderNews_GetRewardInfo\n\t"
        "_0803DDD4: .4byte gMoveResultFlags\n\t"
        "_0803DDD8: .4byte gMultiHitCounter\n\t"
        "_0803DDDC: .4byte gBattleCommunication\n\t"
        "_0803DDE0: .4byte gCurrMovePos\n\t"
        "_0803DDE4: .4byte gChosenMovePos\n\t"
        "_0803DDE8: .4byte gBattleStruct\n\t"
        "_0803DDEC: .4byte gProtectStructs\n\t"
        "_0803DDF0: .4byte gCurrentMove\n\t"
        "_0803DDF4: .4byte gChosenMove\n\t"
        "_0803DDF8: .4byte gHitMarker\n\t"
        "_0803DDFC:\n\t"
        "	ldr r5, _0803DE34\n\t"
        "	mov sl, r5\n\t"
        "	movs r0, #0x58\n\t"
        "	adds r5, r4, #0\n\t"
        "	muls r5, r0, r5\n\t"
        "	mov r0, sl\n\t"
        "	adds r0, #0x50\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #5\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803DE22\n\t"
        "	movs r7, #0x80\n\t"
        "	lsls r7, r7, #0xf\n\t"
        "	ands r7, r1\n\t"
        "	cmp r7, #0\n\t"
        "	beq _0803DE44\n\t"
        "_0803DE22:\n\t"
        "	ldr r3, _0803DE38\n\t"
        "	ldr r2, _0803DE3C\n\t"
        "	ldr r1, _0803DE40\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r2]\n\t"
        "	strh r0, [r3]\n\t"
        "	b _0803DF7C\n\t"
        "	.align 2, 0\n\t"
        "_0803DE34: .4byte gBattleMons\n\t"
        "_0803DE38: .4byte gCurrentMove\n\t"
        "_0803DE3C: .4byte gChosenMove\n\t"
        "_0803DE40: .4byte gLastPrintedMoves\n\t"
        "_0803DE44:\n\t"
        "	ldr r1, _0803DE98\n\t"
        "	mov ip, r1\n\t"
        "	lsls r0, r4, #3\n\t"
        "	subs r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	ldrh r3, [r0, #6]\n\t"
        "	adds r1, r3, #0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803DF1C\n\t"
        "	ldrb r2, [r0, #0xc]\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r5\n\t"
        "	mov r4, sl\n\t"
        "	adds r4, #0xc\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0803DEA8\n\t"
        "	ldr r2, _0803DE9C\n\t"
        "	ldr r0, _0803DEA0\n\t"
        "	strh r3, [r0]\n\t"
        "	strh r3, [r2]\n\t"
        "	ldrb r1, [r6]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	ldrb r0, [r0, #0xc]\n\t"
        "	mov r3, sb\n\t"
        "	strb r0, [r3]\n\t"
        "	mov r5, r8\n\t"
        "	strb r0, [r5]\n\t"
        "	ldrh r0, [r2]\n\t"
        "	movs r1, #0\n\t"
        "	bl GetMoveTarget\n\t"
        "	ldrb r1, [r6]\n\t"
        "	ldr r3, _0803DEA4\n\t"
        "	ldr r2, [r3]\n\t"
        "	b _0803DF56\n\t"
        "	.align 2, 0\n\t"
        "_0803DE98: .4byte gDisableStructs\n\t"
        "_0803DE9C: .4byte gCurrentMove\n\t"
        "_0803DEA0: .4byte gChosenMove\n\t"
        "_0803DEA4: .4byte gBattleStruct\n\t"
        "_0803DEA8:\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803DF1C\n\t"
        "	cmp r1, r0\n\t"
        "	beq _0803DF1C\n\t"
        "	mov r5, sb\n\t"
        "	strb r2, [r5]\n\t"
        "	mov r0, r8\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r3, _0803DF10\n\t"
        "	ldr r2, _0803DF14\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r5, #0x58\n\t"
        "	muls r1, r5, r1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r2]\n\t"
        "	strh r0, [r3]\n\t"
        "	ldrb r1, [r6]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	movs r2, #0\n\t"
        "	strh r7, [r0, #6]\n\t"
        "	ldrb r1, [r6]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	strb r2, [r0, #0xc]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, ip\n\t"
        "	ldrb r2, [r1, #0xe]\n\t"
        "	movs r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #0xe]\n\t"
        "	ldrh r0, [r3]\n\t"
        "	movs r1, #0\n\t"
        "	bl GetMoveTarget\n\t"
        "	ldrb r1, [r6]\n\t"
        "	ldr r3, _0803DF18\n\t"
        "	ldr r2, [r3]\n\t"
        "	b _0803DF56\n\t"
        "	.align 2, 0\n\t"
        "_0803DF10: .4byte gCurrentMove\n\t"
        "_0803DF14: .4byte gChosenMove\n\t"
        "_0803DF18: .4byte gBattleStruct\n\t"
        "_0803DF1C:\n\t"
        "	ldr r3, _0803DF5C\n\t"
        "	mov r5, r8\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r4, _0803DF60\n\t"
        "	ldrb r2, [r4]\n\t"
        "	movs r1, #0x58\n\t"
        "	muls r1, r2, r1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r3, #0xc\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldr r1, _0803DF64\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r2, r2, r1\n\t"
        "	ldrh r3, [r0]\n\t"
        "	ldrh r2, [r2]\n\t"
        "	cmp r3, r2\n\t"
        "	beq _0803DF74\n\t"
        "	ldr r1, _0803DF68\n\t"
        "	ldr r0, _0803DF6C\n\t"
        "	strh r3, [r0]\n\t"
        "	strh r3, [r1]\n\t"
        "	ldrh r0, [r1]\n\t"
        "	movs r1, #0\n\t"
        "	bl GetMoveTarget\n\t"
        "	ldrb r1, [r4]\n\t"
        "	ldr r2, _0803DF70\n\t"
        "	ldr r2, [r2]\n\t"
        "_0803DF56:\n\t"
        "	adds r1, r1, r2\n\t"
        "	strb r0, [r1, #0xc]\n\t"
        "	b _0803DF7C\n\t"
        "	.align 2, 0\n\t"
        "_0803DF5C: .4byte gBattleMons\n\t"
        "_0803DF60: .4byte gBattlerAttacker\n\t"
        "_0803DF64: .4byte gChosenMoveByBattler\n\t"
        "_0803DF68: .4byte gCurrentMove\n\t"
        "_0803DF6C: .4byte gChosenMove\n\t"
        "_0803DF70: .4byte gBattleStruct\n\t"
        "_0803DF74:\n\t"
        "	ldr r1, _0803DFA8\n\t"
        "	ldr r0, _0803DFAC\n\t"
        "	strh r3, [r0]\n\t"
        "	strh r3, [r1]\n\t"
        "_0803DF7C:\n\t"
        "	ldr r2, _0803DFB0\n\t"
        "	ldr r1, _0803DFB4\n\t"
        "	ldrb r3, [r1]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r3, r0\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0, #0x28]\n\t"
        "	mov r8, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803DFC4\n\t"
        "	adds r0, r3, #0\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803DFBC\n\t"
        "	ldr r0, _0803DFB8\n\t"
        "	ldr r1, _0803DFA8\n\t"
        "	ldrh r1, [r1]\n\t"
        "	strh r1, [r0, #0x22]\n\t"
        "	b _0803DFC4\n\t"
        "	.align 2, 0\n\t"
        "_0803DFA8: .4byte gCurrentMove\n\t"
        "_0803DFAC: .4byte gChosenMove\n\t"
        "_0803DFB0: .4byte gBattleMons\n\t"
        "_0803DFB4: .4byte gBattlerAttacker\n\t"
        "_0803DFB8: .4byte gBattleResults\n\t"
        "_0803DFBC:\n\t"
        "	ldr r0, _0803E028\n\t"
        "	ldr r1, _0803E02C\n\t"
        "	ldrh r1, [r1]\n\t"
        "	strh r1, [r0, #0x24]\n\t"
        "_0803DFC4:\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl GetBattlerSide\n\t"
        "	movs r1, #1\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r1, _0803E030\n\t"
        "	lsls r0, r6, #1\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r5, r0, r1\n\t"
        "	ldrb r0, [r5, #8]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E040\n\t"
        "	ldr r2, _0803E034\n\t"
        "	ldr r0, _0803E02C\n\t"
        "	ldrh r1, [r0]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #6]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E040\n\t"
        "	mov r3, r8\n\t"
        "	ldrb r0, [r3]\n\t"
        "	bl GetBattlerSide\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r0, [r5, #9]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0803E040\n\t"
        "	ldr r1, _0803E038\n\t"
        "	ldrb r2, [r5, #9]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0x28]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E040\n\t"
        "	ldr r0, _0803E03C\n\t"
        "	strb r2, [r0]\n\t"
        "	b _0803E3AA\n\t"
        "	.align 2, 0\n\t"
        "_0803E028: .4byte gBattleResults\n\t"
        "_0803E02C: .4byte gCurrentMove\n\t"
        "_0803E030: .4byte gSideTimers\n\t"
        "_0803E034: .4byte gBattleMoves\n\t"
        "_0803E038: .4byte gBattleMons\n\t"
        "_0803E03C: .4byte gBattlerTarget\n\t"
        "_0803E040:\n\t"
        "	ldr r0, _0803E15C\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	ldr r5, _0803E160\n\t"
        "	mov r8, r5\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E052\n\t"
        "	b _0803E320\n\t"
        "_0803E052:\n\t"
        "	ldr r1, _0803E164\n\t"
        "	lsls r0, r6, #1\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r5, [r0, #8]\n\t"
        "	cmp r5, #0\n\t"
        "	beq _0803E064\n\t"
        "	b _0803E270\n\t"
        "_0803E064:\n\t"
        "	ldr r2, _0803E168\n\t"
        "	ldr r0, _0803E16C\n\t"
        "	ldrh r1, [r0]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r4, r0, r2\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E080\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	cmp r0, #0x10\n\t"
        "	bne _0803E080\n\t"
        "	b _0803E270\n\t"
        "_0803E080:\n\t"
        "	ldr r3, _0803E170\n\t"
        "	ldr r2, _0803E160\n\t"
        "	ldrb r6, [r2]\n\t"
        "	ldr r0, _0803E174\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldrb r1, [r0, #0xc]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov r8, r2\n\t"
        "	cmp r0, #0x1f\n\t"
        "	bne _0803E0A0\n\t"
        "	b _0803E270\n\t"
        "_0803E0A0:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	cmp r0, #0xd\n\t"
        "	beq _0803E0A8\n\t"
        "	b _0803E270\n\t"
        "_0803E0A8:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r1, _0803E178\n\t"
        "	strb r5, [r1]\n\t"
        "	ldr r0, _0803E17C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	bhs _0803E120\n\t"
        "	adds r4, r1, #0\n\t"
        "_0803E0C0:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r6, r0\n\t"
        "	beq _0803E10E\n\t"
        "	ldr r0, _0803E160\n\t"
        "	ldrb r1, [r0]\n\t"
        "	ldr r0, _0803E174\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #0xc]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _0803E10E\n\t"
        "	ldr r1, _0803E170\n\t"
        "	ldrb r2, [r4]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0x1f\n\t"
        "	bne _0803E10E\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl GetBattlerTurnOrderNum\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r3, [sp]\n\t"
        "	cmp r0, r3\n\t"
        "	bhs _0803E10E\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerTurnOrderNum\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp]\n\t"
        "_0803E10E:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r1, _0803E17C\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	blo _0803E0C0\n\t"
        "_0803E120:\n\t"
        "	ldr r5, [sp]\n\t"
        "	cmp r5, #4\n\t"
        "	beq _0803E128\n\t"
        "	b _0803E222\n\t"
        "_0803E128:\n\t"
        "	ldr r2, _0803E168\n\t"
        "	ldr r0, _0803E180\n\t"
        "	ldrh r1, [r0]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #6]\n\t"
        "	ands r5, r0\n\t"
        "	cmp r5, #0\n\t"
        "	beq _0803E1A8\n\t"
        "	ldr r0, _0803E160\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E188\n\t"
        "	bl Random\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E184\n\t"
        "	movs r0, #1\n\t"
        "	b _0803E19A\n\t"
        "	.align 2, 0\n\t"
        "_0803E15C: .4byte gBattleTypeFlags\n\t"
        "_0803E160: .4byte gBattlerAttacker\n\t"
        "_0803E164: .4byte gSideTimers\n\t"
        "_0803E168: .4byte gBattleMoves\n\t"
        "_0803E16C: .4byte gCurrentMove\n\t"
        "_0803E170: .4byte gBattleMons\n\t"
        "_0803E174: .4byte gBattleStruct\n\t"
        "_0803E178: .4byte gActiveBattler\n\t"
        "_0803E17C: .4byte gBattlersCount\n\t"
        "_0803E180: .4byte gChosenMove\n\t"
        "_0803E184:\n\t"
        "	movs r0, #3\n\t"
        "	b _0803E19A\n\t"
        "_0803E188:\n\t"
        "	bl Random\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E198\n\t"
        "	movs r0, #0\n\t"
        "	b _0803E19A\n\t"
        "_0803E198:\n\t"
        "	movs r0, #2\n\t"
        "_0803E19A:\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0803E1A4\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0803E1B8\n\t"
        "	.align 2, 0\n\t"
        "_0803E1A4: .4byte gBattlerTarget\n\t"
        "_0803E1A8:\n\t"
        "	ldr r2, _0803E1F0\n\t"
        "	ldr r0, _0803E1F4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, _0803E1F8\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #0xc]\n\t"
        "	strb r0, [r2]\n\t"
        "_0803E1B8:\n\t"
        "	ldr r7, _0803E1FC\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, _0803E200\n\t"
        "	mov r8, r1\n\t"
        "	ldr r5, _0803E1F0\n\t"
        "	ldrb r1, [r5]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, r8\n\t"
        "	ldr r1, [r1]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E1D2\n\t"
        "	b _0803E3AA\n\t"
        "_0803E1D2:\n\t"
        "	ldr r6, _0803E1F4\n\t"
        "	ldrb r0, [r6]\n\t"
        "	bl GetBattlerSide\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0803E204\n\t"
        "	ldrb r0, [r5]\n\t"
        "	b _0803E398\n\t"
        "	.align 2, 0\n\t"
        "_0803E1F0: .4byte gBattlerTarget\n\t"
        "_0803E1F4: .4byte gBattlerAttacker\n\t"
        "_0803E1F8: .4byte gBattleStruct\n\t"
        "_0803E1FC: .4byte gAbsentBattlerFlags\n\t"
        "_0803E200: .4byte gBitTable\n\t"
        "_0803E204:\n\t"
        "	ldrb r0, [r6]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	movs r1, #1\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	strb r0, [r5]\n\t"
        "	ldrb r1, [r7]\n\t"
        "	ldrb r2, [r5]\n\t"
        "	lsls r0, r2, #2\n\t"
        "	add r0, r8\n\t"
        "	b _0803E38E\n\t"
        "_0803E222:\n\t"
        "	ldr r4, _0803E25C\n\t"
        "	ldr r0, _0803E260\n\t"
        "	ldr r3, [sp]\n\t"
        "	adds r0, r3, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _0803E264\n\t"
        "	movs r1, #0x58\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r1, r1, r2\n\t"
        "	adds r1, #0x20\n\t"
        "	ldrb r1, [r1]\n\t"
        "	bl RecordAbilityBattle\n\t"
        "	ldr r2, _0803E268\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #2\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, _0803E26C\n\t"
        "	ldrb r0, [r4]\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0803E3AA\n\t"
        "	.align 2, 0\n\t"
        "_0803E25C: .4byte gActiveBattler\n\t"
        "_0803E260: .4byte gBattlerByTurnOrder\n\t"
        "_0803E264: .4byte gBattleMons\n\t"
        "_0803E268: .4byte gSpecialStatuses\n\t"
        "_0803E26C: .4byte gBattlerTarget\n\t"
        "_0803E270:\n\t"
        "	ldr r0, _0803E2B4\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r4, #1\n\t"
        "	ands r0, r4\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E320\n\t"
        "	ldr r2, _0803E2B8\n\t"
        "	ldr r0, _0803E2BC\n\t"
        "	ldrh r1, [r0]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0, #6]\n\t"
        "	movs r0, #4\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E320\n\t"
        "	mov r5, r8\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E2C4\n\t"
        "	bl Random\n\t"
        "	adds r1, r4, #0\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E2C0\n\t"
        "	movs r0, #1\n\t"
        "	b _0803E2D6\n\t"
        "	.align 2, 0\n\t"
        "_0803E2B4: .4byte gBattleTypeFlags\n\t"
        "_0803E2B8: .4byte gBattleMoves\n\t"
        "_0803E2BC: .4byte gChosenMove\n\t"
        "_0803E2C0:\n\t"
        "	movs r0, #3\n\t"
        "	b _0803E2D6\n\t"
        "_0803E2C4:\n\t"
        "	bl Random\n\t"
        "	adds r1, r4, #0\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E2D4\n\t"
        "	movs r0, #0\n\t"
        "	b _0803E2D6\n\t"
        "_0803E2D4:\n\t"
        "	movs r0, #2\n\t"
        "_0803E2D6:\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0803E310\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _0803E314\n\t"
        "	ldrb r1, [r0]\n\t"
        "	ldr r2, _0803E318\n\t"
        "	ldr r5, _0803E310\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E3AA\n\t"
        "	ldr r0, _0803E31C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerSide\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0803E3AA\n\t"
        "	ldrb r0, [r5]\n\t"
        "	b _0803E398\n\t"
        "	.align 2, 0\n\t"
        "_0803E310: .4byte gBattlerTarget\n\t"
        "_0803E314: .4byte gAbsentBattlerFlags\n\t"
        "_0803E318: .4byte gBitTable\n\t"
        "_0803E31C: .4byte gBattlerAttacker\n\t"
        "_0803E320:\n\t"
        "	ldr r5, _0803E360\n\t"
        "	mov r2, r8\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ldr r1, _0803E364\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #0xc]\n\t"
        "	strb r0, [r5]\n\t"
        "	ldr r6, _0803E368\n\t"
        "	ldrb r1, [r6]\n\t"
        "	ldr r7, _0803E36C\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E3AA\n\t"
        "	ldrb r0, [r2]\n\t"
        "	bl GetBattlerSide\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0803E370\n\t"
        "	ldrb r0, [r5]\n\t"
        "	b _0803E398\n\t"
        "	.align 2, 0\n\t"
        "_0803E360: .4byte gBattlerTarget\n\t"
        "_0803E364: .4byte gBattleStruct\n\t"
        "_0803E368: .4byte gAbsentBattlerFlags\n\t"
        "_0803E36C: .4byte gBitTable\n\t"
        "_0803E370:\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	movs r1, #1\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	strb r0, [r5]\n\t"
        "	ldrb r1, [r6]\n\t"
        "	ldrb r2, [r5]\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "_0803E38E:\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E3AA\n\t"
        "	adds r0, r2, #0\n\t"
        "_0803E398:\n\t"
        "	bl GetBattlerPosition\n\t"
        "	movs r1, #2\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	strb r0, [r5]\n\t"
        "_0803E3AA:\n\t"
        "	ldr r0, _0803E3E0\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #0xa\n\t"
        "	ands r1, r2\n\t"
        "	adds r5, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803E448\n\t"
        "	ldr r0, _0803E3E4\n\t"
        "	ldr r4, _0803E3E8\n\t"
        "	ldrb r2, [r4]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #2]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	bge _0803E448\n\t"
        "	ldr r1, _0803E3EC\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0x28]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803E3F4\n\t"
        "	ldr r1, _0803E3F0\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0803E47C\n\t"
        "	.align 2, 0\n\t"
        "_0803E3E0: .4byte gBattleTypeFlags\n\t"
        "_0803E3E4: .4byte gProtectStructs\n\t"
        "_0803E3E8: .4byte gBattlerAttacker\n\t"
        "_0803E3EC: .4byte gBattleMons\n\t"
        "_0803E3F0: .4byte gCurrentActionFuncId\n\t"
        "_0803E3F4:\n\t"
        "	ldr r3, _0803E420\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldr r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E42C\n\t"
        "	ldr r1, _0803E424\n\t"
        "	movs r2, #0\n\t"
        "	movs r0, #4\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	ldr r1, _0803E428\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r1]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	str r2, [r0]\n\t"
        "	b _0803E464\n\t"
        "	.align 2, 0\n\t"
        "_0803E420: .4byte gPalaceSelectionBattleScripts\n\t"
        "_0803E424: .4byte gBattleCommunication\n\t"
        "_0803E428: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E42C:\n\t"
        "	ldr r1, _0803E43C\n\t"
        "	movs r0, #4\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	ldr r1, _0803E440\n\t"
        "	ldr r0, _0803E444\n\t"
        "	str r0, [r1]\n\t"
        "	b _0803E464\n\t"
        "	.align 2, 0\n\t"
        "_0803E43C: .4byte gBattleCommunication\n\t"
        "_0803E440: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E444: .4byte BattleScript_MoveUsedLoafingAround\n\t"
        "_0803E448:\n\t"
        "	ldr r4, _0803E490\n\t"
        "	ldr r3, _0803E494\n\t"
        "	ldr r2, _0803E498\n\t"
        "	ldr r0, _0803E49C\n\t"
        "	ldrh r1, [r0]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r4]\n\t"
        "_0803E464:\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xb\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803E478\n\t"
        "	ldr r0, _0803E4A0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl BattleArena_AddMindPoints\n\t"
        "_0803E478:\n\t"
        "	ldr r1, _0803E4A4\n\t"
        "	movs r0, #0xa\n\t"
        "_0803E47C:\n\t"
        "	strb r0, [r1]\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803E490: .4byte gBattlescriptCurrInstr\n\t"
        "_0803E494: .4byte gBattleScriptsForMoveEffects\n\t"
        "_0803E498: .4byte gBattleMoves\n\t"
        "_0803E49C: .4byte gCurrentMove\n\t"
        "_0803E4A0: .4byte gBattlerAttacker\n\t"
        "_0803E4A4: .4byte gCurrentActionFuncId\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void HandleAction_TryFinish(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x1c\n\t"
        "	ldr r0, _0803BAD4\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0, #4]\n\t"
        "	ldr r0, _0803BAD8\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _0803BADC\n\t"
        "	bl _0803C956\n\t"
        "	.align 2, 0\n\t"
        "_0803BAD4: .4byte gBattleCommunication\n\t"
        "_0803BAD8: .4byte gActiveBattler\n\t"
        "_0803BADC: .4byte gBattlersCount\n\t"
        ".syntax divided\n\t"
    );
}
