#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_main.h"
#include "battle_ai_script_commands.h"
#include "battle_script_commands.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "battle_util.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/moves.h"
#include "data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "util.h"

extern const u8 *gUnknown_203A804;
extern u8 gUnknown_203A808;
extern bool8 BattleAIStackPop(void);
extern const u8 *const gBattleAI_ScriptsTable[];
extern const void (*const gUnknown_858F64C[])(void);

void BattleAI_DoAIProcessing(void);
void RecordLastUsedMoveByTarget(void);
void sub_081339A0(const u8 *var);

#define AI_ACTION_DONE          0x01
#define AI_ACTION_FLEE          0x02
#define AI_ACTION_WATCH         0x04
#define AI_ACTION_DO_NOT_ATTACK 0x08

struct TrainerJp
{
    u8 filler0[10];
    u16 items[MAX_TRAINER_ITEMS];
    u8 filler1[14];
};

extern const struct TrainerJp gTrainersJp[] __asm__("gTrainers");

void BattleAI_HandleItemUseBeforeAISetup(u8 defaultScoreMoves)
{
    s32 i;
    u8 *data = (u8 *)gBattleResources->battleHistory;

    for (i = 0; i < sizeof(struct BattleHistory); i++)
        data[i] = 0;

    if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
     && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_BATTLE_TOWER
                            | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_SECRET_BASE | BATTLE_TYPE_FRONTIER
                            | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_RECORDED_LINK)))
    {
        for (i = 0; i < MAX_TRAINER_ITEMS; i++)
        {
            if (gTrainersJp[gTrainerBattleOpponent_A].items[i] != ITEM_NONE)
            {
                gBattleResources->battleHistory->trainerItems[gBattleResources->battleHistory->itemsNo] = gTrainersJp[gTrainerBattleOpponent_A].items[i];
                gBattleResources->battleHistory->itemsNo++;
            }
        }
    }

    BattleAI_SetupAIData(defaultScoreMoves);
}

void BattleAI_SetupAIData(u8 defaultScoreMoves)
{
    s32 i;
    u8 *data = (u8 *)gBattleResources->ai;
    u8 moveLimitations;

    for (i = 0; i < sizeof(struct AI_ThinkingStruct); i++)
        data[i] = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (defaultScoreMoves & 1)
            gBattleResources->ai->score[i] = 100;
        else
            gBattleResources->ai->score[i] = 0;

        defaultScoreMoves >>= 1;
    }

    moveLimitations = CheckMoveLimitations(gActiveBattler, 0, MOVE_LIMITATIONS_ALL);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBitTable[i] & moveLimitations)
            gBattleResources->ai->score[i] = 0;

        gBattleResources->ai->simulatedRNG[i] = 100 - (Random() % 16);
    }

    gBattleResources->AI_ScriptsStack->size = 0;
    gUnknown_203A808 = gActiveBattler;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        gBattlerTarget = (Random() & BIT_FLANK) + BATTLE_OPPOSITE(GetBattlerSide(gActiveBattler));
        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
            gBattlerTarget ^= BIT_FLANK;
    }
    else
    {
        gBattlerTarget = BATTLE_OPPOSITE(gUnknown_203A808);
    }

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        gBattleResources->ai->aiFlags = GetAiScriptsInRecordedBattle();
    else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        gBattleResources->ai->aiFlags = AI_SCRIPT_SAFARI;
    else if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
        gBattleResources->ai->aiFlags = AI_SCRIPT_ROAMING;
    else if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        gBattleResources->ai->aiFlags = AI_SCRIPT_FIRST_BATTLE;
    else if (gBattleTypeFlags & BATTLE_TYPE_FACTORY)
        gBattleResources->ai->aiFlags = GetAiScriptsInBattleFactory();
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_SECRET_BASE))
        gBattleResources->ai->aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT;
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        gBattleResources->ai->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags | gTrainers[gTrainerBattleOpponent_B].aiFlags;
    else
        gBattleResources->ai->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        gBattleResources->ai->aiFlags |= AI_SCRIPT_DOUBLE_BATTLE;
}

__attribute__((naked)) u8 BattleAI_ChooseMoveOrAction()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _08130C00\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08130C04\n\t"
        "	bl ChooseMoveOrAction_Doubles\n\t"
        "	b _08130C08\n\t"
        "	.align 2, 0\n\t"
        "_08130C00: .4byte gBattleTypeFlags\n\t"
        "_08130C04:\n\t"
        "	bl ChooseMoveOrAction_Singles\n\t"
        "_08130C08:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

u8 ChooseMoveOrAction_Singles(void)
{
    u8 currentMoveArray[MAX_MON_MOVES];
    u8 consideredMoveArray[MAX_MON_MOVES];
    u8 numOfBestMoves;
    s32 i;

    RecordLastUsedMoveByTarget();

    while (gBattleResources->ai->aiFlags != 0)
    {
        if (gBattleResources->ai->aiFlags & 1)
        {
            gBattleResources->ai->aiState = 0;
            BattleAI_DoAIProcessing();
        }
        gBattleResources->ai->aiFlags >>= 1;
        gBattleResources->ai->aiLogicId++;
        gBattleResources->ai->movesetIndex = 0;
    }

    if (gBattleResources->ai->aiAction & AI_ACTION_FLEE)
        return 4;
    if (gBattleResources->ai->aiAction & AI_ACTION_WATCH)
        return 5;

    numOfBestMoves = 1;
    currentMoveArray[0] = gBattleResources->ai->score[0];
    consideredMoveArray[0] = 0;

    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gUnknown_203A808].moves[i] != MOVE_NONE)
        {
            if (currentMoveArray[0] == gBattleResources->ai->score[i])
            {
                currentMoveArray[numOfBestMoves] = gBattleResources->ai->score[i];
                consideredMoveArray[numOfBestMoves++] = i;
            }
            if (currentMoveArray[0] < gBattleResources->ai->score[i])
            {
                numOfBestMoves = 1;
                currentMoveArray[0] = gBattleResources->ai->score[i];
                consideredMoveArray[0] = i;
            }
        }
    }

    return consideredMoveArray[Random() % numOfBestMoves];
}

u8 ChooseMoveOrAction_Doubles(void)
{
    s32 i;
    s32 j;
    s32 scriptsToRun;
    s16 bestMovePointsForTarget[MAX_BATTLERS_COUNT];
    s8 mostViableTargetsArray[MAX_BATTLERS_COUNT];
    u8 actionOrMoveIndex[MAX_BATTLERS_COUNT];
    u8 mostViableMovesScores[MAX_MON_MOVES];
    u8 mostViableMovesIndices[MAX_MON_MOVES];
    s32 mostViableTargetsNo;
    s32 mostViableMovesNo;
    s16 mostMovePoints;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (i == gUnknown_203A808 || gBattleMons[i].hp == 0)
        {
            actionOrMoveIndex[i] = 0xFF;
            bestMovePointsForTarget[i] = -1;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
                BattleAI_SetupAIData(gBattleStruct->palaceFlags >> MAX_BATTLERS_COUNT);
            else
                BattleAI_SetupAIData(ALL_MOVES_MASK);

            gBattlerTarget = i;

            if ((i & BIT_SIDE) != (gUnknown_203A808 & BIT_SIDE))
                RecordLastUsedMoveByTarget();

            gBattleResources->ai->aiLogicId = 0;
            gBattleResources->ai->movesetIndex = 0;
            scriptsToRun = gBattleResources->ai->aiFlags;
            while (scriptsToRun != 0)
            {
                if (scriptsToRun & 1)
                {
                    gBattleResources->ai->aiState = 0;
                    BattleAI_DoAIProcessing();
                }
                scriptsToRun >>= 1;
                gBattleResources->ai->aiLogicId++;
                gBattleResources->ai->movesetIndex = 0;
            }

            if (gBattleResources->ai->aiAction & AI_ACTION_FLEE)
            {
                actionOrMoveIndex[i] = 4;
            }
            else if (gBattleResources->ai->aiAction & AI_ACTION_WATCH)
            {
                actionOrMoveIndex[i] = 5;
            }
            else
            {
                mostViableMovesScores[0] = gBattleResources->ai->score[0];
                mostViableMovesIndices[0] = 0;
                mostViableMovesNo = 1;
                for (j = 1; j < MAX_MON_MOVES; j++)
                {
                    if (gBattleMons[gUnknown_203A808].moves[j] != MOVE_NONE)
                    {
                        if (mostViableMovesScores[0] == gBattleResources->ai->score[j])
                        {
                            mostViableMovesScores[mostViableMovesNo] = gBattleResources->ai->score[j];
                            mostViableMovesIndices[mostViableMovesNo] = j;
                            mostViableMovesNo++;
                        }
                        if (mostViableMovesScores[0] < gBattleResources->ai->score[j])
                        {
                            mostViableMovesScores[0] = gBattleResources->ai->score[j];
                            mostViableMovesIndices[0] = j;
                            mostViableMovesNo = 1;
                        }
                    }
                }
                actionOrMoveIndex[i] = mostViableMovesIndices[Random() % mostViableMovesNo];
                bestMovePointsForTarget[i] = mostViableMovesScores[0];

                if (i == BATTLE_PARTNER(gUnknown_203A808) && bestMovePointsForTarget[i] < 100)
                {
                    bestMovePointsForTarget[i] = -1;
                    mostViableMovesScores[0] = mostViableMovesScores[0];
                }
            }
        }
    }

    mostMovePoints = bestMovePointsForTarget[0];
    mostViableTargetsArray[0] = 0;
    mostViableTargetsNo = 1;

    for (i = 1; i < MAX_BATTLERS_COUNT; i++)
    {
        if (mostMovePoints == bestMovePointsForTarget[i])
        {
            mostViableTargetsArray[mostViableTargetsNo] = i;
            mostViableTargetsNo++;
        }
        if (mostMovePoints < bestMovePointsForTarget[i])
        {
            mostMovePoints = bestMovePointsForTarget[i];
            mostViableTargetsArray[0] = i;
            mostViableTargetsNo = 1;
        }
    }

    gBattlerTarget = mostViableTargetsArray[Random() % mostViableTargetsNo];
    return actionOrMoveIndex[gBattlerTarget];
}

void BattleAI_DoAIProcessing(void)
{
    while (gBattleResources->ai->aiState != 2)
    {
        switch (gBattleResources->ai->aiState)
        {
        case 3:
            break;
        case 0:
            gUnknown_203A804 = gBattleAI_ScriptsTable[gBattleResources->ai->aiLogicId];
            if (gBattleMons[gUnknown_203A808].pp[gBattleResources->ai->movesetIndex] == 0)
                gBattleResources->ai->moveConsidered = 0;
            else
                gBattleResources->ai->moveConsidered = gBattleMons[gUnknown_203A808].moves[gBattleResources->ai->movesetIndex];
            gBattleResources->ai->aiState++;
            break;
        case 1:
            if (gBattleResources->ai->moveConsidered != 0)
                gUnknown_858F64C[*gUnknown_203A804]();
            else
            {
                gBattleResources->ai->score[gBattleResources->ai->movesetIndex] = 0;
                gBattleResources->ai->aiAction |= AI_ACTION_DONE;
            }

            if (gBattleResources->ai->aiAction & AI_ACTION_DONE)
            {
                gBattleResources->ai->movesetIndex++;
                if (gBattleResources->ai->movesetIndex < MAX_MON_MOVES
                 && !(gBattleResources->ai->aiAction & AI_ACTION_DO_NOT_ATTACK))
                    gBattleResources->ai->aiState = 0;
                else
                    gBattleResources->ai->aiState++;
                gBattleResources->ai->aiAction &= ~AI_ACTION_DONE;
            }
            break;
        }
    }
}

__attribute__((naked)) void RecordLastUsedMoveByTarget(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	movs r7, #0\n\t"
        "	ldr r4, _081310F4\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, [r0, #0x18]\n\t"
        "	ldr r3, _081310F8\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r5, _081310FC\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrh r0, [r2]\n\t"
        "	mov r8, r4\n\t"
        "	mov ip, r3\n\t"
        "	ldrh r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _08131118\n\t"
        "	adds r6, r5, #0\n\t"
        "	movs r5, #0\n\t"
        "_081310D4:\n\t"
        "	mov r1, r8\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r4, [r0, #0x18]\n\t"
        "	mov r0, ip\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r3, r1, #4\n\t"
        "	adds r0, r5, r3\n\t"
        "	adds r2, r4, r0\n\t"
        "	ldrh r0, [r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08131100\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r2]\n\t"
        "	b _08131118\n\t"
        "	.align 2, 0\n\t"
        "_081310F4: .4byte gBattleResources\n\t"
        "_081310F8: .4byte gBattlerTarget\n\t"
        "_081310FC: .4byte gLastMoves\n\t"
        "_08131100:\n\t"
        "	adds r5, #2\n\t"
        "	adds r7, #1\n\t"
        "	cmp r7, #3\n\t"
        "	bgt _08131118\n\t"
        "	adds r0, r5, r3\n\t"
        "	adds r0, r4, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r6\n\t"
        "	ldrh r0, [r0]\n\t"
        "	ldrh r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bne _081310D4\n\t"
        "_08131118:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void ClearBattlerMoveHistory(u8 battler)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        gBattleResources->battleHistory->usedMoves[battler].moves[i] = MOVE_NONE;
}

void RecordAbilityBattle(u8 battler, u8 abilityId)
{
    gBattleResources->battleHistory->abilities[battler] = abilityId;
}

void ClearBattlerAbilityHistory(u8 battler)
{
    gBattleResources->battleHistory->abilities[battler] = ABILITY_NONE;
}

void RecordItemEffectBattle(u8 battler, u8 itemEffect)
{
    gBattleResources->battleHistory->itemEffects[battler] = itemEffect;
}

void ClearBattlerItemEffectHistory(u8 battler)
{
    gBattleResources->battleHistory->itemEffects[battler] = 0;
}

void BattleAICmd_if_random_less_than(void)
{
    u16 random = Random();

    if (random % 256 < gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_random_greater_than(void)
{
    u16 random = Random();

    if (random % 256 > gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_random_equal(void)
{
    u16 random = Random();

    if (random % 256 == gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_random_not_equal(void)
{
    u16 random = Random();

    if (random % 256 != gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_score(void)
{
    gBattleResources->ai->score[gBattleResources->ai->movesetIndex] += gUnknown_203A804[1];

    if (gBattleResources->ai->score[gBattleResources->ai->movesetIndex] < 0)
        gBattleResources->ai->score[gBattleResources->ai->movesetIndex] = 0;

    gUnknown_203A804 += 2;
}

void BattleAICmd_if_hp_less_than(void)
{
    u16 battler;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if ((u32)(100 * gBattleMons[battler].hp / gBattleMons[battler].maxHP) < gUnknown_203A804[2])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
    else
        gUnknown_203A804 += 7;
}

void BattleAICmd_if_hp_more_than(void)
{
    u16 battler;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if ((u32)(100 * gBattleMons[battler].hp / gBattleMons[battler].maxHP) > gUnknown_203A804[2])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
    else
        gUnknown_203A804 += 7;
}

void BattleAICmd_if_hp_equal(void)
{
    u16 battler;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if ((u32)(100 * gBattleMons[battler].hp / gBattleMons[battler].maxHP) == gUnknown_203A804[2])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
    else
        gUnknown_203A804 += 7;
}

void BattleAICmd_if_hp_not_equal(void)
{
    u16 battler;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if ((u32)(100 * gBattleMons[battler].hp / gBattleMons[battler].maxHP) != gUnknown_203A804[2])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
    else
        gUnknown_203A804 += 7;
}

void BattleAICmd_if_status(void)
{
    u16 battler;
    u32 status;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    status = T1_READ_32(gUnknown_203A804 + 2);

    if (gBattleMons[battler].status1 & status)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
    else
        gUnknown_203A804 += 10;
}

void BattleAICmd_if_not_status(void)
{
    u16 battler;
    u32 status;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    status = T1_READ_32(gUnknown_203A804 + 2);

    if (!(gBattleMons[battler].status1 & status))
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
    else
        gUnknown_203A804 += 10;
}

void BattleAICmd_if_status2(void)
{
    u16 battler;
    u32 status;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    status = T1_READ_32(gUnknown_203A804 + 2);

    if (gBattleMons[battler].status2 & status)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
    else
        gUnknown_203A804 += 10;
}

void BattleAICmd_if_not_status2(void)
{
    u16 battler;
    u32 status;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    status = T1_READ_32(gUnknown_203A804 + 2);

    if (!(gBattleMons[battler].status2 & status))
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
    else
        gUnknown_203A804 += 10;
}

void BattleAICmd_if_status3(void)
{
    u16 battler;
    u32 status;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    status = T1_READ_32(gUnknown_203A804 + 2);

    if (gStatuses3[battler] & status)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
    else
        gUnknown_203A804 += 10;
}

void BattleAICmd_if_not_status3(void)
{
    u16 battler;
    u32 status;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    status = T1_READ_32(gUnknown_203A804 + 2);

    if (!(gStatuses3[battler] & status))
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
    else
        gUnknown_203A804 += 10;
}

void BattleAICmd_if_side_affecting(void)
{
    u16 battler;
    u32 side, status;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    side = GET_BATTLER_SIDE(battler);
    status = T1_READ_32(gUnknown_203A804 + 2);

    if (gSideStatuses[side] & status)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
    else
        gUnknown_203A804 += 10;
}

void BattleAICmd_if_not_side_affecting(void)
{
    u16 battler;
    u32 side, status;

    if (gUnknown_203A804[1] == 1)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    side = GET_BATTLER_SIDE(battler);
    status = T1_READ_32(gUnknown_203A804 + 2);

    if (!(gSideStatuses[side] & status))
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
    else
        gUnknown_203A804 += 10;
}

void BattleAICmd_if_less_than(void)
{
    if (gBattleResources->ai->funcResult < gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_more_than(void)
{
    if (gBattleResources->ai->funcResult > gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_equal(void)
{
    if (gBattleResources->ai->funcResult == gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_not_equal(void)
{
    if (gBattleResources->ai->funcResult != gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_less_than_ptr(void)
{
    const u8 *value = T1_READ_PTR(gUnknown_203A804 + 1);

    if (gBattleResources->ai->funcResult < *value)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 5);
    else
        gUnknown_203A804 += 9;
}

void BattleAICmd_if_more_than_ptr(void)
{
    const u8 *value = T1_READ_PTR(gUnknown_203A804 + 1);

    if (gBattleResources->ai->funcResult > *value)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 5);
    else
        gUnknown_203A804 += 9;
}

void BattleAICmd_if_equal_ptr(void)
{
    const u8 *value = T1_READ_PTR(gUnknown_203A804 + 1);

    if (gBattleResources->ai->funcResult == *value)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 5);
    else
        gUnknown_203A804 += 9;
}

void BattleAICmd_if_not_equal_ptr(void)
{
    const u8 *value = T1_READ_PTR(gUnknown_203A804 + 1);

    if (gBattleResources->ai->funcResult != *value)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 5);
    else
        gUnknown_203A804 += 9;
}

void BattleAICmd_if_move(void)
{
    u16 move = T1_READ_16(gUnknown_203A804 + 1);

    if (gBattleResources->ai->moveConsidered == move)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
    else
        gUnknown_203A804 += 7;
}

void BattleAICmd_if_not_move(void)
{
    u16 move = T1_READ_16(gUnknown_203A804 + 1);

    if (gBattleResources->ai->moveConsidered != move)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
    else
        gUnknown_203A804 += 7;
}

void BattleAICmd_if_in_bytes(void)
{
    const u8 *ptr = T1_READ_PTR(gUnknown_203A804 + 1);

    while (*ptr != 0xFF)
    {
        if (gBattleResources->ai->funcResult == *ptr)
        {
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 5);
            return;
        }
        ptr++;
    }
    gUnknown_203A804 += 9;
}

void BattleAICmd_if_not_in_bytes(void)
{
    const u8 *ptr = T1_READ_PTR(gUnknown_203A804 + 1);

    while (*ptr != 0xFF)
    {
        if (gBattleResources->ai->funcResult == *ptr)
        {
            gUnknown_203A804 += 9;
            return;
        }
        ptr++;
    }
    gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 5);
}

void BattleAICmd_if_in_hwords(void)
{
    const u16 *ptr = (const u16 *)T1_READ_PTR(gUnknown_203A804 + 1);

    while (*ptr != 0xFFFF)
    {
        if (gBattleResources->ai->funcResult == *ptr)
        {
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 5);
            return;
        }
        ptr++;
    }
    gUnknown_203A804 += 9;
}

void BattleAICmd_if_not_in_hwords(void)
{
    const u16 *ptr = (const u16 *)T1_READ_PTR(gUnknown_203A804 + 1);

    while (*ptr != 0xFFFF)
    {
        if (gBattleResources->ai->funcResult == *ptr)
        {
            gUnknown_203A804 += 9;
            return;
        }
        ptr++;
    }
    gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 5);
}

void BattleAICmd_if_user_has_attacking_move(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gUnknown_203A808].moves[i] != 0
            && gBattleMoves[gBattleMons[gUnknown_203A808].moves[i]].power != 0)
            break;
    }

    if (i == MAX_MON_MOVES)
        gUnknown_203A804 += 5;
    else
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
}

void BattleAICmd_if_user_has_no_attacking_moves(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[gUnknown_203A808].moves[i] != 0
         && gBattleMoves[gBattleMons[gUnknown_203A808].moves[i]].power != 0)
            break;
    }

    if (i != MAX_MON_MOVES)
        gUnknown_203A804 += 5;
    else
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
}

void BattleAICmd_get_turn_count(void)
{
    gBattleResources->ai->funcResult = gBattleResults.battleTurnCounter;
    gUnknown_203A804 += 1;
}

void BattleAICmd_get_type(void)
{
    u8 typeVar = gUnknown_203A804[1];

    switch (typeVar)
    {
    case AI_TYPE1_USER:
        gBattleResources->ai->funcResult = gBattleMons[gUnknown_203A808].types[0];
        break;
    case AI_TYPE1_TARGET:
        gBattleResources->ai->funcResult = gBattleMons[gBattlerTarget].types[0];
        break;
    case AI_TYPE2_USER:
        gBattleResources->ai->funcResult = gBattleMons[gUnknown_203A808].types[1];
        break;
    case AI_TYPE2_TARGET:
        gBattleResources->ai->funcResult = gBattleMons[gBattlerTarget].types[1];
        break;
    case AI_TYPE_MOVE:
        gBattleResources->ai->funcResult = gBattleMoves[gBattleResources->ai->moveConsidered].type;
        break;
    }

    gUnknown_203A804 += 2;
}

u8 BattleAI_GetWantedBattler(u8 wantedBattler)
{
    switch (wantedBattler)
    {
    case AI_USER:
        return gUnknown_203A808;
    case AI_TARGET:
    default:
        return gBattlerTarget;
    case AI_USER_PARTNER:
        return BATTLE_PARTNER(gUnknown_203A808);
    case AI_TARGET_PARTNER:
        return BATTLE_PARTNER(gBattlerTarget);
    }
}

void BattleAICmd_is_of_type(void)
{
    u8 battler = BattleAI_GetWantedBattler(gUnknown_203A804[1]);

    if (IS_BATTLER_OF_TYPE(battler, gUnknown_203A804[2]))
        gBattleResources->ai->funcResult = TRUE;
    else
        gBattleResources->ai->funcResult = FALSE;

    gUnknown_203A804 += 3;
}

void BattleAICmd_get_considered_move_power(void)
{
    gBattleResources->ai->funcResult = gBattleMoves[gBattleResources->ai->moveConsidered].power;
    gUnknown_203A804 += 1;
}

__attribute__((naked)) void BattleAICmd_get_how_powerful_move_is(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x14\n\t"
        "	movs r3, #0\n\t"
        "	ldr r0, _081320BC\n\t"
        "	ldrh r1, [r0]\n\t"
        "	ldr r5, _081320C0\n\t"
        "	ldr r6, _081320C4\n\t"
        "	ldr r2, _081320C8\n\t"
        "	cmp r1, r5\n\t"
        "	beq _08131FBA\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r0, [r0, #0x14]\n\t"
        "	ldrh r1, [r0, #2]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r4, [r0]\n\t"
        "	ldr r1, _081320BC\n\t"
        "_08131FAA:\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _08131FBA\n\t"
        "	adds r1, #2\n\t"
        "	adds r3, #1\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, r5\n\t"
        "	bne _08131FAA\n\t"
        "_08131FBA:\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r0, [r0, #0x14]\n\t"
        "	ldrh r1, [r0, #2]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _08131FD0\n\t"
        "	b _0813215A\n\t"
        "_08131FD0:\n\t"
        "	lsls r0, r3, #1\n\t"
        "	ldr r1, _081320BC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r3, [r0]\n\t"
        "	ldr r0, _081320C0\n\t"
        "	cmp r3, r0\n\t"
        "	beq _08131FE0\n\t"
        "	b _0813215A\n\t"
        "_08131FE0:\n\t"
        "	ldr r0, _081320CC\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0]\n\t"
        "	ldr r0, _081320D0\n\t"
        "	ldr r0, [r0]\n\t"
        "	strb r1, [r0, #0x13]\n\t"
        "	ldr r0, _081320D4\n\t"
        "	movs r2, #1\n\t"
        "	strb r2, [r0, #0xe]\n\t"
        "	ldr r0, _081320D8\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _081320DC\n\t"
        "	strb r2, [r0]\n\t"
        "	movs r6, #0\n\t"
        "	mov sb, r3\n\t"
        "	ldr r2, _081320BC\n\t"
        "	ldrh r2, [r2]\n\t"
        "	str r2, [sp, #0x10]\n\t"
        "_08132004:\n\t"
        "	movs r3, #0\n\t"
        "	ldr r5, _081320E0\n\t"
        "	lsls r4, r6, #1\n\t"
        "	ldr r7, _081320E4\n\t"
        "	lsls r0, r6, #2\n\t"
        "	mov r8, r0\n\t"
        "	adds r1, r6, #1\n\t"
        "	mov sl, r1\n\t"
        "	ldr r2, [sp, #0x10]\n\t"
        "	cmp r2, sb\n\t"
        "	beq _08132048\n\t"
        "	ldr r2, _081320C4\n\t"
        "	ldrb r1, [r7]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r0, r4, r0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r2, [r0]\n\t"
        "	ldr r1, _081320BC\n\t"
        "_08132038:\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r2, r0\n\t"
        "	beq _08132048\n\t"
        "	adds r1, #2\n\t"
        "	adds r3, #1\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, sb\n\t"
        "	bne _08132038\n\t"
        "_08132048:\n\t"
        "	ldrb r1, [r7]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r0, r4, r0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r1, r0, r1\n\t"
        "	ldrh r0, [r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081320F4\n\t"
        "	lsls r0, r3, #1\n\t"
        "	ldr r2, _081320BC\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, sb\n\t"
        "	bne _081320F4\n\t"
        "	ldr r0, _081320C4\n\t"
        "	ldrh r2, [r1]\n\t"
        "	lsls r1, r2, #1\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #1]\n\t"
        "	cmp r0, #1\n\t"
        "	bls _081320F4\n\t"
        "	ldr r5, _081320E8\n\t"
        "	strh r2, [r5]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r4, _081320EC\n\t"
        "	ldrb r1, [r4]\n\t"
        "	bl AI_CalcDmg\n\t"
        "	ldrh r0, [r5]\n\t"
        "	ldrb r1, [r7]\n\t"
        "	ldrb r2, [r4]\n\t"
        "	bl TypeCalc\n\t"
        "	mov r4, sp\n\t"
        "	add r4, r8\n\t"
        "	ldr r2, _081320F0\n\t"
        "	ldr r0, _081320C8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #0x14]\n\t"
        "	adds r0, #0x18\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	ldr r0, [r2]\n\t"
        "	muls r0, r1, r0\n\t"
        "	movs r1, #0x64\n\t"
        "	bl __divsi3\n\t"
        "	str r0, [r4]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081320FC\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [r4]\n\t"
        "	b _081320FC\n\t"
        "	.align 2, 0\n\t"
        "_081320BC: .4byte gUnknown_858F7D8\n\t"
        "_081320C0: .4byte 0x0000FFFF\n\t"
        "_081320C4: .4byte gBattleMoves\n\t"
        "_081320C8: .4byte gBattleResources\n\t"
        "_081320CC: .4byte gDynamicBasePower\n\t"
        "_081320D0: .4byte gBattleStruct\n\t"
        "_081320D4: .4byte gBattleScripting\n\t"
        "_081320D8: .4byte gMoveResultFlags\n\t"
        "_081320DC: .4byte gCritMultiplier\n\t"
        "_081320E0: .4byte gBattleMons\n\t"
        "_081320E4: .4byte gUnknown_203A808\n\t"
        "_081320E8: .4byte gCurrentMove\n\t"
        "_081320EC: .4byte gBattlerTarget\n\t"
        "_081320F0: .4byte gBattleMoveDamage\n\t"
        "_081320F4:\n\t"
        "	mov r1, sp\n\t"
        "	add r1, r8\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "_081320FC:\n\t"
        "	mov r6, sl\n\t"
        "	cmp r6, #3\n\t"
        "	bgt _08132104\n\t"
        "	b _08132004\n\t"
        "_08132104:\n\t"
        "	movs r6, #0\n\t"
        "	ldr r2, _08132148\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r0, [r0, #0x14]\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sp\n\t"
        "	ldr r1, [sp]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r5, _0813214C\n\t"
        "	cmp r1, r0\n\t"
        "	bgt _0813213A\n\t"
        "	adds r4, r2, #0\n\t"
        "	mov r3, sp\n\t"
        "_08132120:\n\t"
        "	adds r3, #4\n\t"
        "	adds r6, #1\n\t"
        "	cmp r6, #3\n\t"
        "	bgt _0813213A\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r0, [r0, #0x14]\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sp\n\t"
        "	ldr r1, [r3]\n\t"
        "	ldr r0, [r0]\n\t"
        "	cmp r1, r0\n\t"
        "	ble _08132120\n\t"
        "_0813213A:\n\t"
        "	cmp r6, #4\n\t"
        "	bne _08132150\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r1, [r0, #0x14]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [r1, #8]\n\t"
        "	b _08132164\n\t"
        "	.align 2, 0\n\t"
        "_08132148: .4byte gBattleResources\n\t"
        "_0813214C: .4byte gUnknown_203A804\n\t"
        "_08132150:\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r1, [r0, #0x14]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [r1, #8]\n\t"
        "	b _08132164\n\t"
        "_0813215A:\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r1, [r0, #0x14]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r5, _0813217C\n\t"
        "_08132164:\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r5]\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0813217C: .4byte gUnknown_203A804\n\t"
        ".syntax divided\n\t"
    );
}

void BattleAICmd_get_last_used_battler_move(void)
{
    if (gUnknown_203A804[1] == AI_USER)
        gBattleResources->ai->funcResult = gLastMoves[gUnknown_203A808];
    else
        gBattleResources->ai->funcResult = gLastMoves[gBattlerTarget];

    gUnknown_203A804 += 2;
}

void BattleAICmd_if_equal_(void)
{
    if (gUnknown_203A804[1] == gBattleResources->ai->funcResult)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_not_equal_(void)
{
    if (gUnknown_203A804[1] != gBattleResources->ai->funcResult)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_user_goes(void)
{
    if (GetWhoStrikesFirst(gUnknown_203A808, gBattlerTarget, TRUE) == gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_user_doesnt_go(void)
{
    if (GetWhoStrikesFirst(gUnknown_203A808, gBattlerTarget, TRUE) != gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_nullsub_2B(void) {}
void BattleAICmd_nullsub_32(void) {}
void BattleAICmd_count_usable_party_mons(void)
{
    u8 battler;
    u8 battlerOnField1;
    u8 battlerOnField2;
    struct Pokemon *party;
    s32 i;

    gBattleResources->ai->funcResult = 0;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u32 position;

        battlerOnField1 = gBattlerPartyIndexes[battler];
        position = BATTLE_PARTNER(GetBattlerPosition(battler));
        battlerOnField2 = gBattlerPartyIndexes[GetBattlerAtPosition(position)];
    }
    else
    {
        battlerOnField1 = gBattlerPartyIndexes[battler];
        battlerOnField2 = gBattlerPartyIndexes[battler];
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i != battlerOnField1 && i != battlerOnField2
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
        {
            gBattleResources->ai->funcResult++;
        }
    }

    gUnknown_203A804 += 2;
}

void BattleAICmd_get_considered_move(void)
{
    gBattleResources->ai->funcResult = gBattleResources->ai->moveConsidered;
    gUnknown_203A804 += 1;
}

void BattleAICmd_get_considered_move_effect(void)
{
    gBattleResources->ai->funcResult = gBattleMoves[gBattleResources->ai->moveConsidered].effect;
    gUnknown_203A804 += 1;
}

void BattleAICmd_get_ability(void)
{
    u8 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if (gActiveBattler != battler)
    {
        if (gBattleResources->battleHistory->abilities[battler] != ABILITY_NONE)
        {
            gBattleResources->ai->funcResult = gBattleResources->battleHistory->abilities[battler];
            gUnknown_203A804 += 2;
            return;
        }

        if (gBattleMons[battler].ability == ABILITY_SHADOW_TAG
         || gBattleMons[battler].ability == ABILITY_MAGNET_PULL
         || gBattleMons[battler].ability == ABILITY_ARENA_TRAP)
        {
            gBattleResources->ai->funcResult = gBattleMons[battler].ability;
            gUnknown_203A804 += 2;
            return;
        }

        if (gSpeciesInfo[gBattleMons[battler].species].abilities[0] != ABILITY_NONE)
        {
            if (gSpeciesInfo[gBattleMons[battler].species].abilities[1] != ABILITY_NONE)
            {
                if (Random() & 1)
                    gBattleResources->ai->funcResult = gSpeciesInfo[gBattleMons[battler].species].abilities[0];
                else
                    gBattleResources->ai->funcResult = gSpeciesInfo[gBattleMons[battler].species].abilities[1];
            }
            else
            {
                gBattleResources->ai->funcResult = gSpeciesInfo[gBattleMons[battler].species].abilities[0];
            }
        }
        else
        {
            gBattleResources->ai->funcResult = gSpeciesInfo[gBattleMons[battler].species].abilities[1];
        }
    }
    else
    {
        gBattleResources->ai->funcResult = gBattleMons[battler].ability;
    }

    gUnknown_203A804 += 2;
}

void BattleAICmd_check_ability(void)
{
    u32 battler = BattleAI_GetWantedBattler(gUnknown_203A804[1]);
    u32 ability = gUnknown_203A804[2];

    if (gUnknown_203A804[1] == AI_TARGET || gUnknown_203A804[1] == AI_TARGET_PARTNER)
    {
        if (gBattleResources->battleHistory->abilities[battler] != ABILITY_NONE)
        {
            ability = gBattleResources->battleHistory->abilities[battler];
            gBattleResources->ai->funcResult = ability;
        }
        else if (gBattleMons[battler].ability == ABILITY_SHADOW_TAG
              || gBattleMons[battler].ability == ABILITY_MAGNET_PULL
              || gBattleMons[battler].ability == ABILITY_ARENA_TRAP)
        {
            ability = gBattleMons[battler].ability;
        }
        else if (gSpeciesInfo[gBattleMons[battler].species].abilities[0] != ABILITY_NONE)
        {
            if (gSpeciesInfo[gBattleMons[battler].species].abilities[1] != ABILITY_NONE)
            {
                u8 abilityDummyVariable = ability;

                if (gSpeciesInfo[gBattleMons[battler].species].abilities[0] != abilityDummyVariable
                 && gSpeciesInfo[gBattleMons[battler].species].abilities[1] != abilityDummyVariable)
                {
                    ability = gSpeciesInfo[gBattleMons[battler].species].abilities[0];
                }
                else
                {
                    ability = ABILITY_NONE;
                }
            }
            else
            {
                ability = gSpeciesInfo[gBattleMons[battler].species].abilities[0];
            }
        }
        else
        {
            ability = gSpeciesInfo[gBattleMons[battler].species].abilities[1];
        }
    }
    else
    {
        ability = gBattleMons[battler].ability;
    }

    if (ability == ABILITY_NONE)
        gBattleResources->ai->funcResult = 2;
    else if (ability == gUnknown_203A804[2])
        gBattleResources->ai->funcResult = 1;
    else
        gBattleResources->ai->funcResult = 0;

    gUnknown_203A804 += 3;
}

void BattleAICmd_get_highest_type_effectiveness(void)
{
    s32 i;
    u8 *dynamicMoveType;

    gDynamicBasePower = 0;
    dynamicMoveType = &gBattleStruct->dynamicMoveType;
    *dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    gBattleResources->ai->funcResult = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gBattleMoveDamage = 40;
        gCurrentMove = gBattleMons[gUnknown_203A808].moves[i];

        if (gCurrentMove != MOVE_NONE)
        {
            TypeCalc(gCurrentMove, gUnknown_203A808, gBattlerTarget);

            if (gBattleMoveDamage == 120)
                gBattleMoveDamage = AI_EFFECTIVENESS_x2;
            if (gBattleMoveDamage == 240)
                gBattleMoveDamage = AI_EFFECTIVENESS_x4;
            if (gBattleMoveDamage == 30)
                gBattleMoveDamage = AI_EFFECTIVENESS_x0_5;
            if (gBattleMoveDamage == 15)
                gBattleMoveDamage = AI_EFFECTIVENESS_x0_25;

            if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
                gBattleMoveDamage = AI_EFFECTIVENESS_x0;

            if (gBattleResources->ai->funcResult < gBattleMoveDamage)
                gBattleResources->ai->funcResult = gBattleMoveDamage;
        }
    }

    gUnknown_203A804 += 1;
}

void BattleAICmd_if_type_effectiveness(void)
{
    u8 damageVar;

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;

    gBattleMoveDamage = AI_EFFECTIVENESS_x1;
    gCurrentMove = gBattleResources->ai->moveConsidered;
    TypeCalc(gCurrentMove, gUnknown_203A808, gBattlerTarget);

    if (gBattleMoveDamage == 120)
        gBattleMoveDamage = AI_EFFECTIVENESS_x2;
    if (gBattleMoveDamage == 240)
        gBattleMoveDamage = AI_EFFECTIVENESS_x4;
    if (gBattleMoveDamage == 30)
        gBattleMoveDamage = AI_EFFECTIVENESS_x0_5;
    if (gBattleMoveDamage == 15)
        gBattleMoveDamage = AI_EFFECTIVENESS_x0_25;

    if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
        gBattleMoveDamage = AI_EFFECTIVENESS_x0;

    damageVar = gBattleMoveDamage;

    if (damageVar == gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_nullsub_33(void) {}
void BattleAICmd_nullsub_52(void) {}

void BattleAICmd_if_status_in_party(void)
{
    struct Pokemon *party;
    s32 i;
    u32 statusToCompareTo;
    u8 battler;

    switch (gUnknown_203A804[1])
    {
    case AI_USER:
        battler = gUnknown_203A808;
        break;
    default:
        battler = gBattlerTarget;
        break;
    }

    party = (GetBattlerSide(battler) == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;
    statusToCompareTo = T1_READ_32(gUnknown_203A804 + 2);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

        if (species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && status == statusToCompareTo)
        {
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 6);
            return;
        }
    }

    gUnknown_203A804 += 10;
}

__attribute__((naked)) void BattleAICmd_if_status_not_in_party(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	ldr r0, _08132904\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0813290C\n\t"
        "	ldr r0, _08132908\n\t"
        "	b _0813290E\n\t"
        "	.align 2, 0\n\t"
        "_08132904: .4byte gUnknown_203A804\n\t"
        "_08132908: .4byte gUnknown_203A808\n\t"
        "_0813290C:\n\t"
        "	ldr r0, _081329B8\n\t"
        "_0813290E:\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _081329BC\n\t"
        "	mov sl, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08132922\n\t"
        "	ldr r0, _081329C0\n\t"
        "	mov sl, r0\n\t"
        "_08132922:\n\t"
        "	ldr r2, _081329C4\n\t"
        "	ldr r1, [r2]\n\t"
        "	ldrb r7, [r1, #2]\n\t"
        "	ldrb r0, [r1, #3]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r7, r0\n\t"
        "	ldrb r0, [r1, #4]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	orrs r7, r0\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r7, r0\n\t"
        "	movs r1, #0\n\t"
        "	mov r8, r1\n\t"
        "	mov sb, r2\n\t"
        "_08132940:\n\t"
        "	movs r0, #0x64\n\t"
        "	mov r4, r8\n\t"
        "	muls r4, r0, r4\n\t"
        "	add r4, sl\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x37\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r5, #0\n\t"
        "	beq _08132984\n\t"
        "	movs r1, #0xce\n\t"
        "	lsls r1, r1, #1\n\t"
        "	cmp r5, r1\n\t"
        "	beq _08132984\n\t"
        "	cmp r6, #0\n\t"
        "	beq _08132984\n\t"
        "	cmp r0, r7\n\t"
        "	bne _08132984\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	adds r0, #0xa\n\t"
        "	str r0, [r1]\n\t"
        "_08132984:\n\t"
        "	movs r0, #1\n\t"
        "	add r8, r0\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #5\n\t"
        "	ble _08132940\n\t"
        "	ldr r3, _081329C4\n\t"
        "	ldr r2, [r3]\n\t"
        "	ldrb r1, [r2, #6]\n\t"
        "	ldrb r0, [r2, #7]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r1, r0\n\t"
        "	ldrb r0, [r2, #8]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	orrs r1, r0\n\t"
        "	ldrb r0, [r2, #9]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r1, r0\n\t"
        "	str r1, [r3]\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081329B8: .4byte gBattlerTarget\n\t"
        "_081329BC: .4byte gEnemyParty\n\t"
        "_081329C0: .4byte gPlayerParty\n\t"
        "_081329C4: .4byte gUnknown_203A804\n\t"
        ".syntax divided\n\t"
    );
}

void BattleAICmd_get_weather(void)
{
    if (gBattleWeather & B_WEATHER_RAIN)
        gBattleResources->ai->funcResult = AI_WEATHER_RAIN;
    if (gBattleWeather & B_WEATHER_SANDSTORM)
        gBattleResources->ai->funcResult = AI_WEATHER_SANDSTORM;
    if (gBattleWeather & B_WEATHER_SUN)
        gBattleResources->ai->funcResult = AI_WEATHER_SUN;
    if (gBattleWeather & B_WEATHER_HAIL)
        gBattleResources->ai->funcResult = AI_WEATHER_HAIL;

    gUnknown_203A804 += 1;
}

void BattleAICmd_if_effect(void)
{
    if (gBattleMoves[gBattleResources->ai->moveConsidered].effect == gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_not_effect(void)
{
    if (gBattleMoves[gBattleResources->ai->moveConsidered].effect != gUnknown_203A804[1])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void BattleAICmd_if_stat_level_less_than(void)
{
    u32 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if (gBattleMons[battler].statStages[gUnknown_203A804[2]] < gUnknown_203A804[3])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
    else
        gUnknown_203A804 += 8;
}

void BattleAICmd_if_stat_level_more_than(void)
{
    u32 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if (gBattleMons[battler].statStages[gUnknown_203A804[2]] > gUnknown_203A804[3])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
    else
        gUnknown_203A804 += 8;
}

void BattleAICmd_if_stat_level_equal(void)
{
    u32 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if (gBattleMons[battler].statStages[gUnknown_203A804[2]] == gUnknown_203A804[3])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
    else
        gUnknown_203A804 += 8;
}

void BattleAICmd_if_stat_level_not_equal(void)
{
    u32 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if (gBattleMons[battler].statStages[gUnknown_203A804[2]] != gUnknown_203A804[3])
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
    else
        gUnknown_203A804 += 8;
}

void BattleAICmd_if_can_faint(void)
{
    if (gBattleMoves[gBattleResources->ai->moveConsidered].power < 2)
    {
        gUnknown_203A804 += 5;
        return;
    }

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = gBattleResources->ai->moveConsidered;
    AI_CalcDmg(gUnknown_203A808, gBattlerTarget);
    TypeCalc(gCurrentMove, gUnknown_203A808, gBattlerTarget);

    gBattleMoveDamage = gBattleMoveDamage * gBattleResources->ai->simulatedRNG[gBattleResources->ai->movesetIndex] / 100;

    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    if (gBattleMons[gBattlerTarget].hp <= gBattleMoveDamage)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
    else
        gUnknown_203A804 += 5;
}

void BattleAICmd_if_cant_faint(void)
{
    if (gBattleMoves[gBattleResources->ai->moveConsidered].power < 2)
    {
        gUnknown_203A804 += 5;
        return;
    }

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    gCurrentMove = gBattleResources->ai->moveConsidered;
    AI_CalcDmg(gUnknown_203A808, gBattlerTarget);
    TypeCalc(gCurrentMove, gUnknown_203A808, gBattlerTarget);

    gBattleMoveDamage = gBattleMoveDamage * gBattleResources->ai->simulatedRNG[gBattleResources->ai->movesetIndex] / 100;

    if (gBattleMons[gBattlerTarget].hp > gBattleMoveDamage)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
    else
        gUnknown_203A804 += 5;
}

void BattleAICmd_if_has_move(void)
{
    s32 i;
    const u16 *movePtr = (const u16 *)(gUnknown_203A804 + 2);

    switch (gUnknown_203A804[1])
    {
    case AI_USER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gUnknown_203A808].moves[i] == *movePtr)
                break;
        }

        if (i == MAX_MON_MOVES)
            gUnknown_203A804 += 8;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
        break;
    case AI_USER_PARTNER:
        if (gBattleMons[BATTLE_PARTNER(gUnknown_203A808)].hp == 0)
        {
            gUnknown_203A804 += 8;
            break;
        }
        else
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gBattleMons[BATTLE_PARTNER(gUnknown_203A808)].moves[i] == *movePtr)
                    break;
            }
        }

        if (i == MAX_MON_MOVES)
            gUnknown_203A804 += 8;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleResources->battleHistory->usedMoves[gBattlerTarget].moves[i] == *movePtr)
                break;
        }

        if (i == MAX_MON_MOVES)
            gUnknown_203A804 += 8;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
        break;
    }
}

void BattleAICmd_if_doesnt_have_move(void)
{
    s32 i;
    const u16 *movePtr = (const u16 *)(gUnknown_203A804 + 2);

    switch (gUnknown_203A804[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gUnknown_203A808].moves[i] == *movePtr)
                break;
        }

        if (i != MAX_MON_MOVES)
            gUnknown_203A804 += 8;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleResources->battleHistory->usedMoves[gBattlerTarget].moves[i] == *movePtr)
                break;
        }

        if (i != MAX_MON_MOVES)
            gUnknown_203A804 += 8;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
        break;
    }
}

void BattleAICmd_if_has_move_with_effect(void)
{
    s32 i;

    switch (gUnknown_203A804[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gUnknown_203A808].moves[i] != MOVE_NONE
             && gBattleMoves[gBattleMons[gUnknown_203A808].moves[i]].effect == gUnknown_203A804[2])
                break;
        }

        if (i == MAX_MON_MOVES)
            gUnknown_203A804 += 7;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gUnknown_203A808].moves[i] != MOVE_NONE
             && gBattleMoves[gBattleResources->battleHistory->usedMoves[gBattlerTarget].moves[i]].effect == gUnknown_203A804[2])
                break;
        }

        if (i == MAX_MON_MOVES)
            gUnknown_203A804 += 7;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
        break;
    }
}

void BattleAICmd_if_doesnt_have_move_with_effect(void)
{
    s32 i;

    switch (gUnknown_203A804[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[gUnknown_203A808].moves[i] != MOVE_NONE
             && gBattleMoves[gBattleMons[gUnknown_203A808].moves[i]].effect == gUnknown_203A804[2])
                break;
        }

        if (i != MAX_MON_MOVES)
            gUnknown_203A804 += 7;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleResources->battleHistory->usedMoves[gBattlerTarget].moves[i] != MOVE_NONE
             && gBattleMoves[gBattleResources->battleHistory->usedMoves[gBattlerTarget].moves[i]].effect == gUnknown_203A804[2])
                break;
        }

        if (i != MAX_MON_MOVES)
            gUnknown_203A804 += 7;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
        break;
    }
}

void BattleAICmd_if_any_move_disabled_or_encored(void)
{
    u8 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if (gUnknown_203A804[2] == 0)
    {
        if (gDisableStructs[battler].disabledMove == MOVE_NONE)
            gUnknown_203A804 += 7;
        else
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
    }
    else if (gUnknown_203A804[2] != 1)
    {
        gUnknown_203A804 += 7;
    }
    else
    {
        if (gDisableStructs[battler].encoredMove != MOVE_NONE)
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 3);
        else
            gUnknown_203A804 += 7;
    }
}

void BattleAICmd_if_curr_move_disabled_or_encored(void)
{
    switch (gUnknown_203A804[1])
    {
    case 0:
        if (gDisableStructs[gActiveBattler].disabledMove == gBattleResources->ai->moveConsidered)
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
        else
            gUnknown_203A804 += 6;
        break;
    case 1:
        if (gDisableStructs[gActiveBattler].encoredMove == gBattleResources->ai->moveConsidered)
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
        else
            gUnknown_203A804 += 6;
        break;
    default:
        gUnknown_203A804 += 6;
        break;
    }
}

void BattleAICmd_flee(void)
{
    gBattleResources->ai->aiAction |= AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK;
}

void BattleAICmd_if_random_safari_flee(void)
{
    u8 safariFleeRate = gBattleStruct->safariEscapeFactor * 5;

    if ((u8)(Random() % 100) < safariFleeRate)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
    else
        gUnknown_203A804 += 5;
}

void BattleAICmd_watch(void)
{
    gBattleResources->ai->aiAction |= AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK;
}

void BattleAICmd_get_hold_effect(void)
{
    u8 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    if (gActiveBattler != battler)
        gBattleResources->ai->funcResult = GetItemHoldEffect(gBattleResources->battleHistory->itemEffects[battler]);
    else
        gBattleResources->ai->funcResult = GetItemHoldEffect(gBattleMons[battler].item);

    gUnknown_203A804 += 2;
}

void BattleAICmd_if_holds_item(void)
{
    u8 battler = BattleAI_GetWantedBattler(gUnknown_203A804[1]);
    u16 item;
    u8 itemLo;
    u8 itemHi;

    if ((battler & BIT_SIDE) == (gUnknown_203A808 & BIT_SIDE))
        item = gBattleMons[battler].item;
    else
        item = gBattleResources->battleHistory->itemEffects[battler];

    itemHi = gUnknown_203A804[2];
    itemLo = gUnknown_203A804[3];

    if ((itemLo | itemHi) == item)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 4);
    else
        gUnknown_203A804 += 8;
}

void BattleAICmd_get_gender(void)
{
    u8 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    gBattleResources->ai->funcResult = GetGenderFromSpeciesAndPersonality(gBattleMons[battler].species, gBattleMons[battler].personality);
    gUnknown_203A804 += 2;
}

void BattleAICmd_is_first_turn_for(void)
{
    u8 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    gBattleResources->ai->funcResult = gDisableStructs[battler].isFirstTurn;
    gUnknown_203A804 += 2;
}

void BattleAICmd_get_stockpile_count(void)
{
    u8 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    gBattleResources->ai->funcResult = gDisableStructs[battler].stockpileCounter;
    gUnknown_203A804 += 2;
}

void BattleAICmd_is_double_battle(void)
{
    gBattleResources->ai->funcResult = gBattleTypeFlags & BATTLE_TYPE_DOUBLE;
    gUnknown_203A804 += 1;
}

void BattleAICmd_get_used_held_item(void)
{
    u8 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    gBattleResources->ai->funcResult = *(u8 *)&gBattleStruct->usedHeldItems[battler];
    gUnknown_203A804 += 2;
}

void BattleAICmd_get_move_type_from_result(void)
{
    gBattleResources->ai->funcResult = gBattleMoves[gBattleResources->ai->funcResult].type;
    gUnknown_203A804 += 1;
}

void BattleAICmd_get_move_power_from_result(void)
{
    gBattleResources->ai->funcResult = gBattleMoves[gBattleResources->ai->funcResult].power;
    gUnknown_203A804 += 1;
}

void BattleAICmd_get_move_effect_from_result(void)
{
    gBattleResources->ai->funcResult = gBattleMoves[gBattleResources->ai->funcResult].effect;
    gUnknown_203A804 += 1;
}

void BattleAICmd_get_protect_count(void)
{
    u8 battler;

    if (gUnknown_203A804[1] == AI_USER)
        battler = gUnknown_203A808;
    else
        battler = gBattlerTarget;

    gBattleResources->ai->funcResult = gDisableStructs[battler].protectUses;
    gUnknown_203A804 += 2;
}

void BattleAICmd_nullsub_53(void) {}
void BattleAICmd_nullsub_54(void) {}
void BattleAICmd_nullsub_55(void) {}
void BattleAICmd_nullsub_56(void) {}
void BattleAICmd_nullsub_57(void) {}
void BattleAICmd_nullsub_2A(void) {}

void BattleAICmd_call(void)
{
    sub_081339A0(gUnknown_203A804 + 5);
    gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
}

void BattleAICmd_goto(void)
{
    gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
}

void BattleAICmd_end(void)
{
    if (BattleAIStackPop() == 0)
        gBattleResources->ai->aiAction |= AI_ACTION_DONE;
}

void BattleAICmd_if_level_cond(void)
{
    switch (gUnknown_203A804[1])
    {
    case 0:
        if (gBattleMons[gUnknown_203A808].level > gBattleMons[gBattlerTarget].level)
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
        else
            gUnknown_203A804 += 6;
        break;
    case 1:
        if (gBattleMons[gUnknown_203A808].level < gBattleMons[gBattlerTarget].level)
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
        else
            gUnknown_203A804 += 6;
        break;
    case 2:
        if (gBattleMons[gUnknown_203A808].level == gBattleMons[gBattlerTarget].level)
            gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
        else
            gUnknown_203A804 += 6;
        break;
    }
}

void BattleAICmd_if_target_taunted(void)
{
    if (gDisableStructs[gBattlerTarget].tauntTimer != 0)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
    else
        gUnknown_203A804 += 5;
}

void BattleAICmd_if_target_not_taunted(void)
{
    if (gDisableStructs[gBattlerTarget].tauntTimer == 0)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
    else
        gUnknown_203A804 += 5;
}

void BattleAICmd_if_target_is_ally(void)
{
    if ((gUnknown_203A808 & BIT_SIDE) == (gBattlerTarget & BIT_SIDE))
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 1);
    else
        gUnknown_203A804 += 5;
}

void BattleAICmd_if_flash_fired(void)
{
    u8 battler = BattleAI_GetWantedBattler(gUnknown_203A804[1]);

    if (gBattleResources->flags->flags[battler] & RESOURCE_FLAG_FLASH_FIRE)
        gUnknown_203A804 = T1_READ_PTR(gUnknown_203A804 + 2);
    else
        gUnknown_203A804 += 6;
}

void sub_081339A0(const u8 *var)
{
    gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size++] = var;
}

void AIStackPushVar_cursor(void)
{
    gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size++] = gUnknown_203A804;
}
