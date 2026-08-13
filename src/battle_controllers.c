#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "battle_util.h"
#include "cable_club.h"
#include "link.h"
#include "party_menu.h"
#include "pokemon.h"
#include "recorded_battle.h"
#include "task.h"

extern void RecordedBattle_RestoreSavedParties(void);
static void InitLinkBtlControllers(void);
static void InitSinglePlayerBtlControllers(void);
static void SetBattlePartyIds(void);
static void Task_HandleSendLinkBuffersData(u8 taskId);
static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId);
static void CreateTasksForSendRecvLinkBuffers(void);
extern u8 sLinkSendTaskId;
extern u8 sLinkReceiveTaskId;
extern u8 sUnused;
extern const u32 gBitTable[];

void HandleLinkBattleSetup(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        if (gWirelessCommType)
            SetWirelessCommType1();
        if (!gReceivedRemoteLinkPlayers)
            OpenLink();
        CreateTask(Task_WaitForLinkPlayerConnection, 0);
        CreateTasksForSendRecvLinkBuffers();
    }
}

void SetUpBattleVarsAndBirchZigzagoon(void)
{
    s32 i;

    gBattleMainFunc = BeginBattleIntroDummy;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        gBattlerControllerFuncs[i] = BattleControllerDummy;
        gBattlerPositions[i] = 0xFF;
        gActionSelectionCursor[i] = 0;
        gMoveSelectionCursor[i] = 0;
    }

    HandleLinkBattleSetup();
    gBattleControllerExecFlags = 0;
    ClearBattleAnimationVars();
    ClearBattleMonForms();
    BattleAI_HandleItemUseBeforeAISetup(0xF);

    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        ZeroEnemyPartyMons();
        CreateMon(&gEnemyParty[0], SPECIES_ZIGZAGOON, 2, USE_RANDOM_IVS, 0, 0, OT_ID_PLAYER_ID, 0);
        i = 0;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &i);
    }

    // Below are never read
    gUnusedFirstBattleVar1 = 0;
    gUnusedFirstBattleVar2 = 0;
}

void InitBattleControllers(void)
{
    s32 i;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        RecordedBattle_Init(B_RECORD_MODE_RECORDING);
    else
        RecordedBattle_Init(B_RECORD_MODE_PLAYBACK);

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        RecordedBattle_RestoreSavedParties();

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        InitLinkBtlControllers();
    else
        InitSinglePlayerBtlControllers();

    SetBattlePartyIds();

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (i = 0; i < gBattlersCount; i++)
            BufferBattlePartyCurrentOrderBySide(i, 0);
    }

    for (i = 0; i < sizeof(gBattleStruct->tvMovePoints); i++)
        *((u8 *)(&gBattleStruct->tvMovePoints) + i) = 0;

    for (i = 0; i < sizeof(gBattleStruct->tv); i++)
        *((u8 *)(&gBattleStruct->tv) + i) = 0;
}

static void InitSinglePlayerBtlControllers(void)
{
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        gBattleMainFunc = BeginBattleIntro;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToRecordedPlayer;
            gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToOpponent;
            gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToPlayerPartner;
            gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToOpponent;
            gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;
        }
        else
        {
            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToOpponent;
            gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToPlayerPartner;
            gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToOpponent;
            gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;
        }

        gBattlersCount = MAX_BATTLERS_COUNT;

        BufferBattlePartyCurrentOrderBySide(0, 0);
        BufferBattlePartyCurrentOrderBySide(1, 0);
        BufferBattlePartyCurrentOrderBySide(2, 1);
        BufferBattlePartyCurrentOrderBySide(3, 1);

        gBattlerPartyIndexes[0] = 0;
        gBattlerPartyIndexes[1] = 0;
        gBattlerPartyIndexes[2] = 3;
        gBattlerPartyIndexes[3] = 3;
    }
    else if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gBattleMainFunc = BeginBattleIntro;

        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToSafari;
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToWally;
        else
            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToPlayer;

        gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

        gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToOpponent;
        gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

        gBattlersCount = 2;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER)
                {
                    gBattleMainFunc = BeginBattleIntro;

                    gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToRecordedPlayer;
                    gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

                    gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToRecordedOpponent;
                    gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

                    gBattlersCount = 2;
                }
                else // see how the banks are switched
                {
                    gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToRecordedPlayer;
                    gBattlerPositions[B_BATTLER_1] = B_POSITION_PLAYER_LEFT;

                    gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToRecordedOpponent;
                    gBattlerPositions[B_BATTLER_0] = B_POSITION_OPPONENT_LEFT;

                    gBattlersCount = 2;
                }
            }
            else
            {
                gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToRecordedPlayer;
                gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

                gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToOpponent;
                gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;
            }
        }
    }
    else
    {
        gBattleMainFunc = BeginBattleIntro;

        gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToPlayer;
        gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

        gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToOpponent;
        gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

        gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToPlayer;
        gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;

        gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToOpponent;
        gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;

        gBattlersCount = MAX_BATTLERS_COUNT;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
            {
                gBattleMainFunc = BeginBattleIntro;

                gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToRecordedPlayer;
                gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

                gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToOpponent;
                gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

                gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToRecordedPlayer;
                gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;

                gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToOpponent;
                gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;

                gBattlersCount = MAX_BATTLERS_COUNT;

                BufferBattlePartyCurrentOrderBySide(0, 0);
                BufferBattlePartyCurrentOrderBySide(1, 0);
                BufferBattlePartyCurrentOrderBySide(2, 1);
                BufferBattlePartyCurrentOrderBySide(3, 1);

                gBattlerPartyIndexes[0] = 0;
                gBattlerPartyIndexes[1] = 0;
                gBattlerPartyIndexes[2] = 3;
                gBattlerPartyIndexes[3] = 3;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                u8 multiplayerId;

                for (multiplayerId = gRecordedBattleMultiplayerId, i = 0; i < MAX_LINK_PLAYERS; i++)
                {
                    switch (gLinkPlayers[i].id)
                    {
                    case 0:
                    case 3:
                        BufferBattlePartyCurrentOrderBySide(gLinkPlayers[i].id, 0);
                        break;
                    case 1:
                    case 2:
                        BufferBattlePartyCurrentOrderBySide(gLinkPlayers[i].id, 1);
                        break;
                    }

                    if (i == multiplayerId)
                    {
                        gBattlerControllerFuncs[gLinkPlayers[i].id] = SetControllerToRecordedPlayer;
                        switch (gLinkPlayers[i].id)
                        {
                        case 0:
                        case 3:
                            gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_PLAYER_LEFT;
                            gBattlerPartyIndexes[gLinkPlayers[i].id] = 0;
                            break;
                        case 1:
                        case 2:
                            gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_PLAYER_RIGHT;
                            gBattlerPartyIndexes[gLinkPlayers[i].id] = 3;
                            break;
                        }
                    }
                    else if ((!(gLinkPlayers[i].id & 1) && !(gLinkPlayers[multiplayerId].id & 1))
                            || ((gLinkPlayers[i].id & 1) && (gLinkPlayers[multiplayerId].id & 1)))
                    {
                        gBattlerControllerFuncs[gLinkPlayers[i].id] = SetControllerToRecordedPlayer;
                        switch (gLinkPlayers[i].id)
                        {
                        case 0:
                        case 3:
                            gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_PLAYER_LEFT;
                            gBattlerPartyIndexes[gLinkPlayers[i].id] = 0;
                            break;
                        case 1:
                        case 2:
                            gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_PLAYER_RIGHT;
                            gBattlerPartyIndexes[gLinkPlayers[i].id] = 3;
                            break;
                        }
                    }
                    else
                    {
                        gBattlerControllerFuncs[gLinkPlayers[i].id] = SetControllerToRecordedOpponent;
                        switch (gLinkPlayers[i].id)
                        {
                        case 0:
                        case 3:
                            gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_OPPONENT_LEFT;
                            gBattlerPartyIndexes[gLinkPlayers[i].id] = 0;
                            break;
                        case 1:
                        case 2:
                            gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_OPPONENT_RIGHT;
                            gBattlerPartyIndexes[gLinkPlayers[i].id] = 3;
                            break;
                        }
                    }
                }
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_IS_MASTER)
            {
                gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToRecordedPlayer;
                gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

                gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToRecordedPlayer;
                gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;

                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                {
                  gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToRecordedOpponent;
                  gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

                  gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToRecordedOpponent;
                  gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;
                }
                else
                {
                  gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToOpponent;
                  gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

                  gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToOpponent;
                  gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;
                }
            }
            else
            {
                gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToRecordedPlayer;
                gBattlerPositions[B_BATTLER_1] = B_POSITION_PLAYER_LEFT;

                gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToRecordedPlayer;
                gBattlerPositions[B_BATTLER_3] = B_POSITION_PLAYER_RIGHT;

                if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
                {
                    gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToRecordedOpponent;
                    gBattlerPositions[B_BATTLER_0] = B_POSITION_OPPONENT_LEFT;

                    gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToRecordedOpponent;
                    gBattlerPositions[B_BATTLER_2] = B_POSITION_OPPONENT_RIGHT;
                }
                else
                {
                    gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToOpponent;
                    gBattlerPositions[B_BATTLER_0] = B_POSITION_OPPONENT_LEFT;

                    gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToOpponent;
                    gBattlerPositions[B_BATTLER_2] = B_POSITION_OPPONENT_RIGHT;
                }
            }
        }
    }
}

static void InitLinkBtlControllers(void)
{
    s32 i;
    u8 multiplayerId;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_IS_MASTER)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToLinkOpponent;
            gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

            gBattlersCount = 2;
        }
        else
        {
            gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_1] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToLinkOpponent;
            gBattlerPositions[B_BATTLER_0] = B_POSITION_OPPONENT_LEFT;

            gBattlersCount = 2;
        }
    }
    else if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_IS_MASTER)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToLinkOpponent;
            gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToLinkOpponent;
            gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;

            gBattlersCount = MAX_BATTLERS_COUNT;
        }
        else
        {
            gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_1] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToLinkOpponent;
            gBattlerPositions[B_BATTLER_0] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_3] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToLinkOpponent;
            gBattlerPositions[B_BATTLER_2] = B_POSITION_OPPONENT_RIGHT;

            gBattlersCount = MAX_BATTLERS_COUNT;
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_IS_MASTER)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToOpponent;
            gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToLinkPartner;
            gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToOpponent;
            gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;

            gBattlersCount = MAX_BATTLERS_COUNT;
        }
        else
        {
            gBattlerControllerFuncs[B_BATTLER_0] = SetControllerToLinkPartner;
            gBattlerPositions[B_BATTLER_0] = B_POSITION_PLAYER_LEFT;

            gBattlerControllerFuncs[B_BATTLER_1] = SetControllerToLinkOpponent;
            gBattlerPositions[B_BATTLER_1] = B_POSITION_OPPONENT_LEFT;

            gBattlerControllerFuncs[B_BATTLER_2] = SetControllerToPlayer;
            gBattlerPositions[B_BATTLER_2] = B_POSITION_PLAYER_RIGHT;

            gBattlerControllerFuncs[B_BATTLER_3] = SetControllerToLinkOpponent;
            gBattlerPositions[B_BATTLER_3] = B_POSITION_OPPONENT_RIGHT;

            gBattlersCount = MAX_BATTLERS_COUNT;
        }

        BufferBattlePartyCurrentOrderBySide(0, 0);
        BufferBattlePartyCurrentOrderBySide(1, 0);
        BufferBattlePartyCurrentOrderBySide(2, 1);
        BufferBattlePartyCurrentOrderBySide(3, 1);
        gBattlerPartyIndexes[0] = 0;
        gBattlerPartyIndexes[1] = 0;
        gBattlerPartyIndexes[2] = 3;
        gBattlerPartyIndexes[3] = 3;
    }
    else
    {
        multiplayerId = GetMultiplayerId();

        if (gBattleTypeFlags & BATTLE_TYPE_IS_MASTER)
            gBattleMainFunc = BeginBattleIntro;

        for (i = 0; i < MAX_LINK_PLAYERS; i++)
        {
            switch (gLinkPlayers[i].id)
            {
            case 0:
            case 3:
                BufferBattlePartyCurrentOrderBySide(gLinkPlayers[i].id, 0);
                break;
            case 1:
            case 2:
                BufferBattlePartyCurrentOrderBySide(gLinkPlayers[i].id, 1);
                break;
            }

            if (i == multiplayerId)
            {
                gBattlerControllerFuncs[gLinkPlayers[i].id] = SetControllerToPlayer;
                switch (gLinkPlayers[i].id)
                {
                case 0:
                case 3:
                    gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_PLAYER_LEFT;
                    gBattlerPartyIndexes[gLinkPlayers[i].id] = 0;
                    break;
                case 1:
                case 2:
                    gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_PLAYER_RIGHT;
                    gBattlerPartyIndexes[gLinkPlayers[i].id] = 3;
                    break;
                }
            }
            else
            {
                if ((!(gLinkPlayers[i].id & 1) && !(gLinkPlayers[multiplayerId].id & 1))
                 || ((gLinkPlayers[i].id & 1) && (gLinkPlayers[multiplayerId].id & 1)))
                {
                    gBattlerControllerFuncs[gLinkPlayers[i].id] = SetControllerToLinkPartner;
                    switch (gLinkPlayers[i].id)
                    {
                    case 0:
                    case 3:
                        gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_PLAYER_LEFT;
                        gBattlerPartyIndexes[gLinkPlayers[i].id] = 0;
                        break;
                    case 1:
                    case 2:
                        gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_PLAYER_RIGHT;
                        gBattlerPartyIndexes[gLinkPlayers[i].id] = 3;
                        break;
                    }
                }
                else
                {
                    gBattlerControllerFuncs[gLinkPlayers[i].id] = SetControllerToLinkOpponent;
                    switch (gLinkPlayers[i].id)
                    {
                    case 0:
                    case 3:
                        gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_OPPONENT_LEFT;
                        gBattlerPartyIndexes[gLinkPlayers[i].id] = 0;
                        break;
                    case 1:
                    case 2:
                        gBattlerPositions[gLinkPlayers[i].id] = B_POSITION_OPPONENT_RIGHT;
                        gBattlerPartyIndexes[gLinkPlayers[i].id] = 3;
                        break;
                    }
                }
            }
        }

        gBattlersCount = MAX_BATTLERS_COUNT;
    }
}

static void SetBattlePartyIds(void)
{
    s32 i, j;

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (i = 0; i < gBattlersCount; i++)
        {
            for (j = 0; j < PARTY_SIZE; j++)
            {
                if (i < 2)
                {
                    if (GET_BATTLER_SIDE2(i) == B_SIDE_PLAYER)
                    {
                        if (GetMonData(&gPlayerParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
                         && !GetMonData(&gPlayerParty[j], MON_DATA_IS_EGG))
                        {
                            gBattlerPartyIndexes[i] = j;
                            break;
                        }
                    }
                    else
                    {
                        if (GetMonData(&gEnemyParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
                         && !GetMonData(&gEnemyParty[j], MON_DATA_IS_EGG))
                        {
                            gBattlerPartyIndexes[i] = j;
                            break;
                        }
                    }
                }
                else
                {
                    if (GET_BATTLER_SIDE2(i) == B_SIDE_PLAYER)
                    {
                        if (GetMonData(&gPlayerParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES) != SPECIES_NONE
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
                         && !GetMonData(&gPlayerParty[j], MON_DATA_IS_EGG)
                         && gBattlerPartyIndexes[i - 2] != j)
                        {
                            gBattlerPartyIndexes[i] = j;
                            break;
                        }
                    }
                    else
                    {
                        if (GetMonData(&gEnemyParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
                         && !GetMonData(&gEnemyParty[j], MON_DATA_IS_EGG)
                         && gBattlerPartyIndexes[i - 2] != j)
                        {
                            gBattlerPartyIndexes[i] = j;
                            break;
                        }
                    }
                }
            }
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            gBattlerPartyIndexes[1] = 0, gBattlerPartyIndexes[3] = 3;
    }
}

void PrepareBufferDataTransfer(u8 bufferId, u8 *data, u16 size)
{
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        PrepareBufferDataTransferLink(bufferId, size, data);
    }
    else
    {
        switch (bufferId)
        {
        case B_COMM_TO_CONTROLLER:
            for (i = 0; i < size; data++, i++)
                gBattleBufferA[gActiveBattler][i] = *data;
            break;
        case B_COMM_TO_ENGINE:
            for (i = 0; i < size; data++, i++)
                gBattleBufferB[gActiveBattler][i] = *data;
            break;
        }
    }
}

#define tInitialDelayTimer      data[10]
#define tState                  data[11]
#define tCurrentBlock_WrapFrom  data[12]
#define tBlockSendDelayTimer    data[13]
#define tCurrentBlock_End       data[14]
#define tCurrentBlock_Start     data[15]

static void CreateTasksForSendRecvLinkBuffers(void)
{
    sLinkSendTaskId = CreateTask(Task_HandleSendLinkBuffersData, 0);
    gTasks[sLinkSendTaskId].tState                 = 0;
    gTasks[sLinkSendTaskId].tCurrentBlock_WrapFrom = 0;
    gTasks[sLinkSendTaskId].tBlockSendDelayTimer   = 0;
    gTasks[sLinkSendTaskId].tCurrentBlock_End      = 0;
    gTasks[sLinkSendTaskId].tCurrentBlock_Start    = 0;

    sLinkReceiveTaskId = CreateTask(Task_HandleCopyReceivedLinkBuffersData, 0);
    gTasks[sLinkReceiveTaskId].tCurrentBlock_WrapFrom = 0;
    gTasks[sLinkReceiveTaskId].tBlockSendDelayTimer   = 0;
    gTasks[sLinkReceiveTaskId].tCurrentBlock_End      = 0;
    gTasks[sLinkReceiveTaskId].tCurrentBlock_Start    = 0;

    sUnused = 0;
}

enum
{
    LINK_BUFF_BUFFER_ID,
    LINK_BUFF_ACTIVE_BATTLER,
    LINK_BUFF_ATTACKER,
    LINK_BUFF_TARGET,
    LINK_BUFF_SIZE_LO,
    LINK_BUFF_SIZE_HI,
    LINK_BUFF_ABSENT_BATTLER_FLAGS,
    LINK_BUFF_EFFECT_BATTLER,
    LINK_BUFF_DATA,
};

void PrepareBufferDataTransferLink(u8 bufferId, u16 size, u8 *data)
{
    s32 alignedSize;
    s32 i;

    alignedSize = size - size % 4 + 4;
    if (gTasks[sLinkSendTaskId].tCurrentBlock_End + alignedSize + LINK_BUFF_DATA + 1 > BATTLE_BUFFER_LINK_SIZE)
    {
        gTasks[sLinkSendTaskId].tCurrentBlock_WrapFrom = gTasks[sLinkSendTaskId].tCurrentBlock_End;
        gTasks[sLinkSendTaskId].tCurrentBlock_End      = 0;
    }

    #define BYTE_TO_SEND(offset) \
        gLinkBattleSendBuffer[gTasks[sLinkSendTaskId].tCurrentBlock_End + offset]

    BYTE_TO_SEND(LINK_BUFF_BUFFER_ID)            = bufferId;
    BYTE_TO_SEND(LINK_BUFF_ACTIVE_BATTLER)       = gActiveBattler;
    BYTE_TO_SEND(LINK_BUFF_ATTACKER)             = gBattlerAttacker;
    BYTE_TO_SEND(LINK_BUFF_TARGET)               = gBattlerTarget;
    BYTE_TO_SEND(LINK_BUFF_SIZE_LO)              = alignedSize;
    BYTE_TO_SEND(LINK_BUFF_SIZE_HI)              = (alignedSize & 0x0000FF00) >> 8;
    BYTE_TO_SEND(LINK_BUFF_ABSENT_BATTLER_FLAGS) = gAbsentBattlerFlags;
    BYTE_TO_SEND(LINK_BUFF_EFFECT_BATTLER)       = gEffectBattler;

    for (i = 0; i < size; i++)
        BYTE_TO_SEND(LINK_BUFF_DATA + i) = data[i];

    #undef BYTE_TO_SEND

    gTasks[sLinkSendTaskId].tCurrentBlock_End = gTasks[sLinkSendTaskId].tCurrentBlock_End + alignedSize + LINK_BUFF_DATA;
}

enum {
   SENDTASK_STATE_INITIALIZE        = 0,
   SENDTASK_STATE_INITIAL_DELAY     = 1,
   SENDTASK_STATE_COUNT_PLAYERS     = 2,
   SENDTASK_STATE_BEGIN_SEND_BLOCK  = 3,
   SENDTASK_STATE_FINISH_SEND_BLOCK = 4,
   SENDTASK_STATE_UNUSED_STATE      = 5,
};

static void Task_HandleSendLinkBuffersData(u8 taskId)
{
    u16 numPlayers;
    u16 blockSize;

    #define BYTE_TO_SEND(offset) \
        gLinkBattleSendBuffer[gTasks[taskId].tCurrentBlock_Start + offset]

    switch (gTasks[taskId].tState)
    {
    case SENDTASK_STATE_INITIALIZE:
        gTasks[taskId].tInitialDelayTimer = 100;
        gTasks[taskId].tState++;
        break;
    case SENDTASK_STATE_INITIAL_DELAY:
        gTasks[taskId].tInitialDelayTimer--;
        if (gTasks[taskId].tInitialDelayTimer == 0)
            gTasks[taskId].tState++;
        break;
    case SENDTASK_STATE_COUNT_PLAYERS:
        if (gWirelessCommType)
        {
            gTasks[taskId].tState++;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                numPlayers = 2;
            else
                numPlayers = (gBattleTypeFlags & BATTLE_TYPE_MULTI) ? 4 : 2;

            if (GetLinkPlayerCount_2() >= numPlayers)
            {
                if (IsLinkMaster())
                {
                    CheckShouldAdvanceLinkState();
                    gTasks[taskId].tState++;
                }
                else
                {
                    gTasks[taskId].tState++;
                }
            }
        }
        break;
    case SENDTASK_STATE_BEGIN_SEND_BLOCK:
        if (gTasks[taskId].tCurrentBlock_Start != gTasks[taskId].tCurrentBlock_End)
        {
            if (gTasks[taskId].tBlockSendDelayTimer == 0)
            {
                if (gTasks[taskId].tCurrentBlock_Start >  gTasks[taskId].tCurrentBlock_End
                 && gTasks[taskId].tCurrentBlock_Start == gTasks[taskId].tCurrentBlock_WrapFrom)
                {
                    gTasks[taskId].tCurrentBlock_WrapFrom = 0;
                    gTasks[taskId].tCurrentBlock_Start    = 0;
                }
                blockSize = (BYTE_TO_SEND(LINK_BUFF_SIZE_LO) | (BYTE_TO_SEND(LINK_BUFF_SIZE_HI) << 8)) + LINK_BUFF_DATA;
                SendBlock(BitmaskAllOtherLinkPlayers(), &BYTE_TO_SEND(0), blockSize);
                gTasks[taskId].tState++;
            }
            else
            {
                gTasks[taskId].tBlockSendDelayTimer--;
                break;
            }
        }
        break;
    case SENDTASK_STATE_FINISH_SEND_BLOCK:
        if (IsLinkTaskFinished())
        {
            blockSize = BYTE_TO_SEND(LINK_BUFF_SIZE_LO) | (BYTE_TO_SEND(LINK_BUFF_SIZE_HI) << 8);
            gTasks[taskId].tBlockSendDelayTimer = 1;
            gTasks[taskId].tCurrentBlock_Start  = gTasks[taskId].tCurrentBlock_Start + blockSize + LINK_BUFF_DATA;
            gTasks[taskId].tState = SENDTASK_STATE_BEGIN_SEND_BLOCK;
        }
        break;
    case SENDTASK_STATE_UNUSED_STATE:
        if (--gTasks[taskId].tBlockSendDelayTimer == 0)
        {
            gTasks[taskId].tBlockSendDelayTimer = 1;
            gTasks[taskId].tState = SENDTASK_STATE_BEGIN_SEND_BLOCK;
        }
        break;
    }

    #undef BYTE_TO_SEND
}

void TryReceiveLinkBattleData(void)
{
    u8 i;
    s32 j;
    u8 *recvBuffer;

    if (gReceivedRemoteLinkPlayers && (gBattleTypeFlags & BATTLE_TYPE_LINK_IN_BATTLE))
    {
        DestroyTask_RfuIdle();
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            if (GetBlockReceivedStatus() & gBitTable[i])
            {
                ResetBlockReceivedFlag(i);
                recvBuffer = (u8 *)gBlockRecvBuffer[i];
                {
                    u8 *dest, *src;
                    u16 dataSize = gBlockRecvBuffer[i][2];

                    if (gTasks[sLinkReceiveTaskId].tCurrentBlock_End + 9 + dataSize > 0x1000)
                    {
                        gTasks[sLinkReceiveTaskId].tCurrentBlock_WrapFrom = gTasks[sLinkReceiveTaskId].tCurrentBlock_End;
                        gTasks[sLinkReceiveTaskId].tCurrentBlock_End = 0;
                    }

                    dest = &gLinkBattleRecvBuffer[gTasks[sLinkReceiveTaskId].tCurrentBlock_End];
                    src = recvBuffer;

                    for (j = 0; j < dataSize + 8; j++)
                        dest[j] = src[j];

                    gTasks[sLinkReceiveTaskId].tCurrentBlock_End = gTasks[sLinkReceiveTaskId].tCurrentBlock_End + dataSize + 8;
                }
            }
        }
    }
}

static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId)
{
    u16 blockSize;
    u8 battler;
    u8 playerId;

    #define BYTE_TO_RECEIVE(offset) \
        gLinkBattleRecvBuffer[gTasks[taskId].tCurrentBlock_Start + offset]

    if (gTasks[taskId].tCurrentBlock_Start != gTasks[taskId].tCurrentBlock_End)
    {
        if (gTasks[taskId].tCurrentBlock_Start >  gTasks[taskId].tCurrentBlock_End
         && gTasks[taskId].tCurrentBlock_Start == gTasks[taskId].tCurrentBlock_WrapFrom)
        {
            gTasks[taskId].tCurrentBlock_WrapFrom = 0;
            gTasks[taskId].tCurrentBlock_Start    = 0;
        }
        battler = BYTE_TO_RECEIVE(LINK_BUFF_ACTIVE_BATTLER);
        blockSize = BYTE_TO_RECEIVE(LINK_BUFF_SIZE_LO) | (BYTE_TO_RECEIVE(LINK_BUFF_SIZE_HI) << 8);

        switch (BYTE_TO_RECEIVE(0))
        {
        case B_COMM_TO_CONTROLLER:
            if (IS_BATTLE_CONTROLLER_ACTIVE_ON_LOCAL(battler))
                return;

            memcpy(gBattleBufferA[battler], &BYTE_TO_RECEIVE(LINK_BUFF_DATA), blockSize);
            MarkBattlerReceivedLinkData(battler);

            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
            {
                gBattlerAttacker    = BYTE_TO_RECEIVE(LINK_BUFF_ATTACKER);
                gBattlerTarget      = BYTE_TO_RECEIVE(LINK_BUFF_TARGET);
                gAbsentBattlerFlags = BYTE_TO_RECEIVE(LINK_BUFF_ABSENT_BATTLER_FLAGS);
                gEffectBattler      = BYTE_TO_RECEIVE(LINK_BUFF_EFFECT_BATTLER);
            }
            break;
        case B_COMM_TO_ENGINE:
            memcpy(gBattleBufferB[battler], &gLinkBattleRecvBuffer[gTasks[taskId].tCurrentBlock_Start + LINK_BUFF_DATA], blockSize);
            break;
        case B_COMM_CONTROLLER_IS_DONE:
            playerId = BYTE_TO_RECEIVE(LINK_BUFF_DATA);
            MARK_BATTLE_CONTROLLER_IDLE_FOR_PLAYER(battler, playerId);
            break;
        }

        gTasks[taskId].tCurrentBlock_Start = gTasks[taskId].tCurrentBlock_Start + blockSize + LINK_BUFF_DATA;
    }

    #undef BYTE_TO_RECEIVE
}

#undef tInitialDelayTimer
#undef tState
#undef tCurrentBlock_WrapFrom
#undef tBlockSendDelayTimer
#undef tCurrentBlock_End
#undef tCurrentBlock_Start
