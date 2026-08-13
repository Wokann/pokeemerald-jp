#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "cable_club.h"
#include "link.h"
#include "party_menu.h"
#include "pokemon.h"
#include "recorded_battle.h"
#include "task.h"

extern void CreateTasksForSendRecvLinkBuffers(void);
extern void RecordedBattle_RestoreSavedParties(void);
static void InitLinkBtlControllers(void);
static void InitSinglePlayerBtlControllers(void);
static void SetBattlePartyIds(void);

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
