#include "global.h"
#include "battle.h"
#include "battle_main.h"
#include "battle_setup.h"
#include "cable_club.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "data.h"
#include "event_data.h"
#include "field_message_box.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "start_menu.h"
#include "string_util.h"
#include "trainer_card.h"
#include "window.h"

#define tState      data[0]
#define tMinPlayers data[1]
#define tMaxPlayers data[2]
#define tNumPlayers data[3]
#define tTimer      data[4]
#define tWindowId   data[5]

extern s16 gUnknown_3005B68[];

void sub_080B1C9C(u16 windowId, u32 numPlayers);
static void Task_LinkupStart(u8 taskId);
static void Task_LinkupAwaitConnection(u8 taskId);
static void Task_LinkupConfirmWhenReady(u8 taskId);
static void Task_LinkupAwaitConfirmation(u8 taskId);
static void Task_LinkupTryConfirmation(u8 taskId);
static void Task_LinkupConfirm(u8 taskId);
static void Task_LinkupExchangeDataWithLeader(u8 taskId);
static void Task_LinkupCheckStatusAfterConfirm(u8 taskId);
static void Task_LinkupAwaitTrainerCardData(u8 taskId);
static void Task_StopLinkup(u8 taskId);
static bool8 TryLinkTimeout(u8 taskId);
static void Task_ReestablishLink(u8 taskId);
static void Task_ReestablishLinkAwaitConnection(u8 taskId);
static void Task_ReestablishLinkLeader(u8 taskId);
static void Task_ReestablishLinkAwaitConfirmation(u8 taskId);
void Task_LinkupFailed(u8 taskId);
void Task_LinkupConnectionError(u8 taskId);

extern const struct WindowTemplate sWindowTemplate_LinkPlayerCount;
extern const u8 gText_ConfirmLinkWhenPlayersReady[];
extern const u8 gText_ConfirmStartLinkWithXPlayers[];
extern const u8 gText_AwaitingLinkup[];
extern struct Pokemon gUnknown_202412C[];
extern void TrainerCard_GenerateCardForPlayer(struct TrainerCard *trainerCard);
extern struct LinkPlayer gLocalLinkPlayer;

static void CreateLinkupTask(u8 minPlayers, u8 maxPlayers)
{
    if (FindTaskIdByFunc(Task_LinkupStart) == TASK_NONE)
    {
        u8 taskId1;

        taskId1 = CreateTask(Task_LinkupStart, 80);
        gTasks[taskId1].tMinPlayers = minPlayers;
        gTasks[taskId1].tMaxPlayers = maxPlayers;
    }
}

__attribute__((naked)) void sub_080B1C9C(u16 windowId, u32 numPlayers)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldr r0, _080B1CEC\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl SetStandardWindowBorderStyle\n\t"
        "	ldr r5, _080B1CF0\n\t"
        "	ldr r1, _080B1CF4\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r5, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B1CEC: .4byte gStringVar1\n\t"
        "_080B1CF0: .4byte gStringVar4\n\t"
        "_080B1CF4: .4byte sBadgeFlagsJp + 0x10\n\t"
        ".syntax divided\n\t"
    );
}

static void ClearLinkPlayerCountWindow(u16 windowId)
{
    ClearStdWindowAndFrame(windowId, FALSE);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void UpdateLinkPlayerCountDisplay(u8 taskId, u8 numPlayers)
{
    s16 *data = gUnknown_3005B68 + taskId * 20;

    if (numPlayers != tNumPlayers)
    {
        if (numPlayers <= 1)
            ClearLinkPlayerCountWindow(tWindowId);
        else
            sub_080B1C9C(tWindowId, numPlayers);
        tNumPlayers = numPlayers;
    }
}

static u32 ExchangeDataAndGetLinkupStatus(u8 minPlayers, u8 maxPlayers)
{
    switch (GetLinkPlayerDataExchangeStatusTimed(minPlayers, maxPlayers))
    {
    case EXCHANGE_COMPLETE:
        return LINKUP_SUCCESS;
    case EXCHANGE_DIFF_SELECTIONS:
        return LINKUP_DIFF_SELECTIONS;
    case EXCHANGE_PLAYER_NOT_READY:
        return LINKUP_PLAYER_NOT_READY;
    case EXCHANGE_PARTNER_NOT_READY:
        return LINKUP_PARTNER_NOT_READY;
    case EXCHANGE_WRONG_NUM_PLAYERS:
        ConvertIntToDecimalStringN(gStringVar1, GetLinkPlayerCount_2(), STR_CONV_MODE_LEFT_ALIGN, 1);
        return LINKUP_WRONG_NUM_PLAYERS;
    case EXCHANGE_STAT_7:
        return LINKUP_FAILED_CONTEST_GMODE;
    case EXCHANGE_TIMED_OUT:
    default:
        return LINKUP_ONGOING;
    }
}

static bool32 CheckLinkErrored(u8 taskId)
{
    if (HasLinkErrorOccurred() == TRUE)
    {
        gTasks[taskId].func = Task_LinkupConnectionError;
        return TRUE;
    }
    return FALSE;
}

static bool32 CheckLinkCanceledBeforeConnection(u8 taskId)
{
    if (JOY_NEW(B_BUTTON)
     && IsLinkConnectionEstablished() == FALSE)
    {
        gLinkType = 0;
        gTasks[taskId].func = Task_LinkupFailed;
        return TRUE;
    }
    return FALSE;
}

static bool32 CheckLinkCanceled(u8 taskId)
{
    if (IsLinkConnectionEstablished())
        SetSuppressLinkErrorMessage(TRUE);

    if (JOY_NEW(B_BUTTON))
    {
        gLinkType = 0;
        gTasks[taskId].func = Task_LinkupFailed;
        return TRUE;
    }
    return FALSE;
}

static bool32 CheckSioErrored(u8 taskId)
{
    if (GetSioMultiSI() == TRUE)
    {
        gTasks[taskId].func = Task_LinkupConnectionError;
        return TRUE;
    }
    return FALSE;
}

static void Task_DelayedBlockRequest(u8 taskId)
{
    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] == 10)
    {
        SendBlockRequest(BLOCK_REQ_SIZE_100);
        DestroyTask(taskId);
    }
}

static void Task_LinkupStart(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        OpenLinkTimed();
        ResetLinkPlayerCount();
        ResetLinkPlayers();
        tWindowId = AddWindow(&sWindowTemplate_LinkPlayerCount);
    }
    else if (data[0] > 9)
    {
        gTasks[taskId].func = Task_LinkupAwaitConnection;
    }
    data[0]++;
}

static void Task_LinkupAwaitConnection(u8 taskId)
{
    u32 playerCount = GetLinkPlayerCount_2();

    if (CheckLinkCanceledBeforeConnection(taskId) == TRUE
     || CheckLinkCanceled(taskId) == TRUE
     || playerCount < 2)
        return;

    SetSuppressLinkErrorMessage(TRUE);
    gTasks[taskId].data[3] = 0;
    if (IsLinkMaster() == TRUE)
    {
        PlaySE(SE_PIN);
        ShowFieldAutoScrollMessage(gText_ConfirmLinkWhenPlayersReady);
        gTasks[taskId].func = Task_LinkupConfirmWhenReady;
    }
    else
    {
        PlaySE(SE_BOO);
        ShowFieldAutoScrollMessage(gText_AwaitingLinkup);
        gTasks[taskId].func = Task_LinkupExchangeDataWithLeader;
    }
}

static void Task_LinkupConfirmWhenReady(u8 taskId)
{
    if (CheckLinkCanceledBeforeConnection(taskId) == TRUE
     || CheckSioErrored(taskId) == TRUE
     || CheckLinkErrored(taskId) == TRUE)
        return;

    if (GetFieldMessageBoxMode() == FIELD_MESSAGE_BOX_HIDDEN)
    {
        gTasks[taskId].tNumPlayers = 0;
        gTasks[taskId].func = Task_LinkupAwaitConfirmation;
    }
}

static void Task_LinkupAwaitConfirmation(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    s32 linkPlayerCount = GetLinkPlayerCount_2();

    if (CheckLinkCanceledBeforeConnection(taskId) == TRUE
     || CheckSioErrored(taskId) == TRUE
     || CheckLinkErrored(taskId) == TRUE)
        return;

    UpdateLinkPlayerCountDisplay(taskId, linkPlayerCount);

    if (!(JOY_NEW(A_BUTTON)))
        return;

    if (linkPlayerCount < tMinPlayers)
        return;

    SaveLinkPlayers(linkPlayerCount);
    ClearLinkPlayerCountWindow(tWindowId);
    ConvertIntToDecimalStringN(gStringVar1, linkPlayerCount, STR_CONV_MODE_LEFT_ALIGN, 1);
    ShowFieldAutoScrollMessage(gText_ConfirmStartLinkWithXPlayers);
    gTasks[taskId].func = Task_LinkupTryConfirmation;
}

static void Task_LinkupTryConfirmation(u8 taskId)
{
    if (CheckLinkCanceledBeforeConnection(taskId) == TRUE
     || CheckSioErrored(taskId) == TRUE
     || CheckLinkErrored(taskId) == TRUE)
        return;

    if (GetFieldMessageBoxMode() == FIELD_MESSAGE_BOX_HIDDEN)
    {
        if (GetSavedPlayerCount() != GetLinkPlayerCount_2())
        {
            ShowFieldAutoScrollMessage(gText_ConfirmLinkWhenPlayersReady);
            gTasks[taskId].func = Task_LinkupConfirmWhenReady;
        }
        else if (JOY_HELD(B_BUTTON))
        {
            ShowFieldAutoScrollMessage(gText_ConfirmLinkWhenPlayersReady);
            gTasks[taskId].func = Task_LinkupConfirmWhenReady;
        }
        else if (JOY_HELD(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            CheckShouldAdvanceLinkState();
            gTasks[taskId].func = Task_LinkupConfirm;
        }
    }
}

static void Task_LinkupConfirm(u8 taskId)
{
    u8 minPlayers = gTasks[taskId].tMinPlayers;
    u8 maxPlayers = gTasks[taskId].tMaxPlayers;

    if (CheckLinkErrored(taskId) == TRUE
     || TryLinkTimeout(taskId) == TRUE)
        return;

    if (GetLinkPlayerCount_2() != GetSavedPlayerCount())
    {
        gTasks[taskId].func = Task_LinkupConnectionError;
    }
    else
    {
        gSpecialVar_Result = ExchangeDataAndGetLinkupStatus(minPlayers, maxPlayers);
        if (gSpecialVar_Result != LINKUP_ONGOING)
            gTasks[taskId].func = Task_LinkupCheckStatusAfterConfirm;
    }
}

static void Task_LinkupExchangeDataWithLeader(u8 taskId)
{
    u8 minPlayers, maxPlayers;
    struct TrainerCard *card;

    minPlayers = gTasks[taskId].tMinPlayers;
    maxPlayers = gTasks[taskId].tMaxPlayers;

    if (CheckLinkCanceledBeforeConnection(taskId) == TRUE
     || CheckLinkErrored(taskId) == TRUE)
        return;

    gSpecialVar_Result = ExchangeDataAndGetLinkupStatus(minPlayers, maxPlayers);
    if (gSpecialVar_Result == LINKUP_ONGOING)
        return;
    if (gSpecialVar_Result == LINKUP_DIFF_SELECTIONS
     || gSpecialVar_Result == LINKUP_WRONG_NUM_PLAYERS)
    {
        SetCloseLinkCallback();
        HideFieldMessageBox();
        gTasks[taskId].func = Task_StopLinkup;
    }
    else if (gSpecialVar_Result == LINKUP_PLAYER_NOT_READY
          || gSpecialVar_Result == LINKUP_PARTNER_NOT_READY)
    {
        CloseLink();
        HideFieldMessageBox();
        gTasks[taskId].func = Task_StopLinkup;
    }
    else
    {
        gFieldLinkPlayerCount = GetLinkPlayerCount_2();
        gLocalLinkPlayerId = GetMultiplayerId();
        SaveLinkPlayers(gFieldLinkPlayerCount);
        card = (struct TrainerCard *)gBlockSendBuffer;
        TrainerCard_GenerateCardForPlayer(card);
        card->monSpecies[0] = GetMonData(&gUnknown_202412C[gSelectedOrderFromParty[0]], MON_DATA_SPECIES, NULL);
        card->monSpecies[1] = GetMonData(&gUnknown_202412C[gSelectedOrderFromParty[1]], MON_DATA_SPECIES, NULL);
        gTasks[taskId].func = Task_LinkupAwaitTrainerCardData;
    }
}

static void Task_LinkupCheckStatusAfterConfirm(u8 taskId)
{
    struct TrainerCard *card;

    if (CheckLinkErrored(taskId) == TRUE)
        return;

    if (gSpecialVar_Result == LINKUP_WRONG_NUM_PLAYERS)
    {
        if (!Link_AnyPartnersPlayingRubyOrSapphire())
        {
            SetCloseLinkCallback();
            HideFieldMessageBox();
            gTasks[taskId].func = Task_StopLinkup;
        }
        else
        {
            CloseLink();
            HideFieldMessageBox();
            gTasks[taskId].func = Task_StopLinkup;
        }
    }
    else if (gSpecialVar_Result == LINKUP_DIFF_SELECTIONS)
    {
        SetCloseLinkCallback();
        HideFieldMessageBox();
        gTasks[taskId].func = Task_StopLinkup;
    }
    else if (gSpecialVar_Result == LINKUP_PLAYER_NOT_READY
          || gSpecialVar_Result == LINKUP_PARTNER_NOT_READY)
    {
        CloseLink();
        HideFieldMessageBox();
        gTasks[taskId].func = Task_StopLinkup;
    }
    else
    {
        gFieldLinkPlayerCount = GetLinkPlayerCount_2();
        gLocalLinkPlayerId = GetMultiplayerId();
        SaveLinkPlayers(gFieldLinkPlayerCount);
        card = (struct TrainerCard *)gBlockSendBuffer;
        TrainerCard_GenerateCardForPlayer(card);
        card->monSpecies[0] = GetMonData(&gUnknown_202412C[gSelectedOrderFromParty[0]], MON_DATA_SPECIES, NULL);
        card->monSpecies[1] = GetMonData(&gUnknown_202412C[gSelectedOrderFromParty[1]], MON_DATA_SPECIES, NULL);
        gTasks[taskId].func = Task_LinkupAwaitTrainerCardData;
        SendBlockRequest(BLOCK_REQ_SIZE_100);
    }
}

bool32 AreBattleTowerLinkSpeciesSame(u16 *speciesList1, u16 *speciesList2)
{
    int i;
    int j;
    bool32 haveSameSpecies = FALSE;
    int numSameSpecies = 0;

    gStringVar1[0] = EOS;
    gStringVar2[0] = EOS;

    for (i = 0; i < FRONTIER_MULTI_PARTY_SIZE; i++)
    {
        for (j = 0; j < FRONTIER_MULTI_PARTY_SIZE; j++)
        {
            if (speciesList1[i] == speciesList2[j])
            {
                if (numSameSpecies == 0)
                {
                    StringCopy(gStringVar1, gSpeciesNames[speciesList1[i]]);
                    haveSameSpecies = TRUE;
                }

                if (numSameSpecies == 1)
                {
                    StringCopy(gStringVar2, gSpeciesNames[speciesList1[i]]);
                    haveSameSpecies = TRUE;
                }

                numSameSpecies++;
            }
        }
    }

    // var below is read by BattleFrontier_BattleTowerLobby_EventScript_AbortLink
    gSpecialVar_0x8005 = numSameSpecies;

    return haveSameSpecies;
}

static void FinishLinkup(u16 *linkupStatus, u32 taskId)
{
    struct TrainerCard *trainerCards = gTrainerCards;

    if (*linkupStatus == LINKUP_SUCCESS)
    {
        if (gLinkType == LINKTYPE_BATTLE_TOWER_50 || gLinkType == LINKTYPE_BATTLE_TOWER_OPEN)
        {
            if (AreBattleTowerLinkSpeciesSame(trainerCards[0].monSpecies, trainerCards[1].monSpecies))
            {
                // Unsuccessful battle tower linkup
                *linkupStatus = LINKUP_FAILED_BATTLE_TOWER;
                SetCloseLinkCallback();
                gTasks[taskId].func = Task_StopLinkup;
            }
            else
            {
                // Successful battle tower linkup
                ClearLinkPlayerCountWindow(gTasks[taskId].tWindowId);
                ScriptContext_Enable();
                DestroyTask(taskId);
            }
        }
        else
        {
            // Successful linkup
            ClearLinkPlayerCountWindow(gTasks[taskId].tWindowId);
            ScriptContext_Enable();
            DestroyTask(taskId);
        }
    }
    else
    {
        // Unsuccessful linkup
        SetCloseLinkCallback();
        gTasks[taskId].func = Task_StopLinkup;
    }
}

static void Task_LinkupAwaitTrainerCardData(u8 taskId)
{
    u8 index;

    if (CheckLinkErrored(taskId) == TRUE)
        return;

    if (GetBlockReceivedStatus() != GetSavedLinkPlayerCountAsBitFlags())
        return;

    for (index = 0; index < GetLinkPlayerCount(); index++)
    {
        CopyTrainerCardData(&gTrainerCards[index], (struct TrainerCard *)gBlockRecvBuffer[index], gLinkPlayers[index].version);
    }

    SetSuppressLinkErrorMessage(FALSE);
    ResetBlockReceivedFlags();
    FinishLinkup(&gSpecialVar_Result, taskId);
}

static void Task_StopLinkup(u8 taskId)
{
    if (!gReceivedRemoteLinkPlayers)
    {
        ClearLinkPlayerCountWindow(gTasks[taskId].tWindowId);
        ScriptContext_Enable();
        RemoveWindow(gTasks[taskId].tWindowId);
        DestroyTask(taskId);
    }
}

static void Task_LinkupFailed(u8 taskId)
{
    gSpecialVar_Result = LINKUP_FAILED;
    ClearLinkPlayerCountWindow(gTasks[taskId].tWindowId);
    StopFieldMessage();
    RemoveWindow(gTasks[taskId].tWindowId);
    ScriptContext_Enable();
    DestroyTask(taskId);
}

static void Task_LinkupConnectionError(u8 taskId)
{
    gSpecialVar_Result = LINKUP_CONNECTION_ERROR;
    ClearLinkPlayerCountWindow(gTasks[taskId].tWindowId);
    RemoveWindow(gTasks[taskId].tWindowId);
    HideFieldMessageBox();
    ScriptContext_Enable();
    DestroyTask(taskId);
}

static bool8 TryLinkTimeout(u8 taskId)
{
    gTasks[taskId].tTimer++;
    if (gTasks[taskId].tTimer > 600)
    {
        gTasks[taskId].func = Task_LinkupConnectionError;
        return TRUE;
    }

    return FALSE;
}

void TryBattleLinkup(void)
{
    u8 minPlayers = 2;
    u8 maxPlayers = 2;

    switch (gSpecialVar_0x8004)
    {
    case USING_SINGLE_BATTLE:
        minPlayers = 2;
        gLinkType = LINKTYPE_SINGLE_BATTLE;
        break;
    case USING_DOUBLE_BATTLE:
        minPlayers = 2;
        gLinkType = LINKTYPE_DOUBLE_BATTLE;
        break;
    case USING_MULTI_BATTLE:
        minPlayers = 4;
        maxPlayers = 4;
        gLinkType = LINKTYPE_MULTI_BATTLE;
        break;
    case USING_BATTLE_TOWER:
        minPlayers = 2;
        if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_50)
            gLinkType = LINKTYPE_BATTLE_TOWER_50;
        else
            gLinkType = LINKTYPE_BATTLE_TOWER_OPEN;
        break;
    }

    CreateLinkupTask(minPlayers, maxPlayers);
}

void TryTradeLinkup(void)
{
    gLinkType = LINKTYPE_TRADE_SETUP;
    gBattleTypeFlags = 0;
    CreateLinkupTask(2, 2);
}

void TryRecordMixLinkup(void)
{
    gSpecialVar_Result = LINKUP_ONGOING;
    gLinkType = LINKTYPE_RECORD_MIX_BEFORE;
    gBattleTypeFlags = 0;
    CreateLinkupTask(2, 4);
}

void TryBerryBlenderLinkup(void)
{
    gLinkType = LINKTYPE_BERRY_BLENDER_SETUP;
    gBattleTypeFlags = 0;
    CreateLinkupTask(2, 4);
}

void TryContestGModeLinkup(void)
{
    gLinkType = LINKTYPE_CONTEST_GMODE;
    gBattleTypeFlags = 0;
    CreateLinkupTask(4, 4);
}

void TryContestEModeLinkup(void)
{
    gLinkType = LINKTYPE_CONTEST_EMODE;
    gBattleTypeFlags = 0;
    CreateLinkupTask(2, 4);
}

u8 CreateTask_ReestablishCableClubLink(void)
{
    if (FuncIsActiveTask(Task_ReestablishLink) != FALSE)
        return TASK_NONE;

    switch (gSpecialVar_0x8004)
    {
    case USING_SINGLE_BATTLE:
        gLinkType = LINKTYPE_SINGLE_BATTLE;
        break;
    case USING_DOUBLE_BATTLE:
        gLinkType = LINKTYPE_DOUBLE_BATTLE;
        break;
    case USING_MULTI_BATTLE:
        gLinkType = LINKTYPE_MULTI_BATTLE;
        break;
    case USING_BATTLE_TOWER:
        if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_50)
            gLinkType = LINKTYPE_BATTLE_TOWER_50;
        else
            gLinkType = LINKTYPE_BATTLE_TOWER_OPEN;
        break;
    case USING_TRADE_CENTER:
        gLinkType = LINKTYPE_TRADE;
        break;
    case USING_RECORD_CORNER:
        gLinkType = LINKTYPE_RECORD_MIX_AFTER;
        break;
    }

    return CreateTask(Task_ReestablishLink, 80);
}

static void Task_ReestablishLink(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (data[0] == 0)
    {
        OpenLink();
        ResetLinkPlayers();
        CreateTask(Task_WaitForLinkPlayerConnection, 80);
    }
    else if (data[0] >= 10)
    {
        gTasks[taskId].func = Task_ReestablishLinkAwaitConnection;
    }
    data[0]++;
}

static void Task_ReestablishLinkAwaitConnection(u8 taskId)
{
    if (GetLinkPlayerCount_2() >= 2)
    {
        if (IsLinkMaster() == TRUE)
            gTasks[taskId].func = Task_ReestablishLinkLeader;
        else
            gTasks[taskId].func = Task_ReestablishLinkAwaitConfirmation;
    }
}

static void Task_ReestablishLinkLeader(u8 taskId)
{
    if (GetSavedPlayerCount() == GetLinkPlayerCount_2())
    {
        CheckShouldAdvanceLinkState();
        gTasks[taskId].func = Task_ReestablishLinkAwaitConfirmation;
    }
}

static void Task_ReestablishLinkAwaitConfirmation(u8 taskId)
{
    if (gReceivedRemoteLinkPlayers == TRUE
     && IsLinkPlayerDataExchangeComplete() == TRUE)
    {
        CheckLinkPlayersMatchSaved();
        StartSendingKeysToLink();
        DestroyTask(taskId);
    }
}

// Unused
void CableClubSaveGame(void)
{
    SaveGame();
}

static void SetLinkBattleTypeFlags(int linkService)
{
    switch (linkService)
    {
    case USING_SINGLE_BATTLE:
        gBattleTypeFlags = BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER;
        break;
    case USING_DOUBLE_BATTLE:
        gBattleTypeFlags = BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER;
        break;
    case USING_MULTI_BATTLE:
        ReducePlayerPartyToSelectedMons();
        gBattleTypeFlags = BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_MULTI;
        break;
    case USING_BATTLE_TOWER:
        gBattleTypeFlags = BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_DOUBLE | BATTLE_TYPE_LINK | BATTLE_TYPE_TRAINER | BATTLE_TYPE_MULTI;
        break;
    }
}

#define tTimer data[1]

static void Task_StartWiredCableClubBattle(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        FadeScreen(FADE_TO_BLACK, 0);
        gLinkType = LINKTYPE_BATTLE;
        ClearLinkCallback_2();
        task->tState++;
        break;
    case 1:
        if (!gPaletteFade.active)
            task->tState++;
        break;
    case 2:
        task->tTimer++;
        if (task->tTimer > 20)
            task->tState++;
        break;
    case 3:
        SetCloseLinkCallback();
        task->tState++;
        break;
    case 4:
        if (!gReceivedRemoteLinkPlayers)
            task->tState++;
        break;
    case 5:
        if (gLinkPlayers[0].trainerId & 1)
            PlayMapChosenOrBattleBGM(MUS_VS_GYM_LEADER);
        else
            PlayMapChosenOrBattleBGM(MUS_VS_TRAINER);

        SetLinkBattleTypeFlags(gSpecialVar_0x8004);
        CleanupOverworldWindowsAndTilemaps();
        gTrainerBattleOpponent_A = TRAINER_LINK_OPPONENT;
        SetMainCallback2(CB2_InitBattle);
        gMain.savedCallback = CB2_ReturnFromCableClubBattle;
        DestroyTask(taskId);
        break;
    }
}

static void Task_StartWirelessCableClubBattle(u8 taskId)
{
    int i;
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        FadeScreen(FADE_TO_BLACK, 0);
        gLinkType = LINKTYPE_BATTLE;
        ClearLinkCallback_2();
        tState = 1;
        break;
    case 1:
        if (!gPaletteFade.active)
            tState = 2;
        break;
    case 2:
        SendBlock(0, &gLocalLinkPlayer, sizeof(gLocalLinkPlayer));
        tState = 3;
        break;
    case 3:
        if (GetBlockReceivedStatus() == GetLinkPlayerCountAsBitFlags())
        {
            for (i = 0; i < GetLinkPlayerCount(); i++)
            {
                struct LinkPlayer *player = (struct LinkPlayer *)gBlockRecvBuffer[i];
                gLinkPlayers[i] = *player;
                ResetBlockReceivedFlag(i);
            }
            tState = 4;
        }
        break;
    case 4:
        tTimer++;
        if (tTimer > 20)
            tState = 5;
        break;
    case 5:
        SetLinkStandbyCallback();
        tState = 6;
        break;
    case 6:
        if (IsLinkTaskFinished())
        {
            tState = 7;
        }
        break;
    case 7:
        if (gLinkPlayers[0].trainerId & 1)
            PlayMapChosenOrBattleBGM(MUS_VS_GYM_LEADER);
        else
            PlayMapChosenOrBattleBGM(MUS_VS_TRAINER);

        gLinkPlayers[0].linkType = LINKTYPE_BATTLE;
        SetLinkBattleTypeFlags(gSpecialVar_0x8004);
        CleanupOverworldWindowsAndTilemaps();
        gTrainerBattleOpponent_A = TRAINER_LINK_OPPONENT;
        SetMainCallback2(CB2_InitBattle);
        gMain.savedCallback = CB2_ReturnFromCableClubBattle;
        DestroyTask(taskId);
        break;
    }
}

#undef tTimer

static void CB2_ReturnFromUnionRoomBattle(void)
{
    switch (gMain.state)
    {
    case 0:
        SetCloseLinkCallback();
        if (Link_AnyPartnersPlayingFRLG_JP())
            gMain.state = 2;
        else
            gMain.state = 1;
        break;
    case 1:
        if (!gReceivedRemoteLinkPlayers)
        {
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    case 2:
        SetMainCallback2(CB2_ReturnToField);
        break;
    }
    RunTasks();
}

__attribute__((naked)) void sub_080B2D68(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r2, _080B2DB8\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0x21\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "	bl Overworld_ResetMapMusic\n\t"
        "	bl LoadPlayerParty\n\t"
        "	bl SavePlayerBag\n\t"
        "	bl sub_0813BF34\n\t"
        "	ldr r0, _080B2DBC\n\t"
        "	ldrh r0, [r0]\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _080B2E0E\n\t"
        "	ldr r0, _080B2DC0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r5, #1\n\t"
        "	eors r0, r5\n\t"
        "	bl UpdatePlayerLinkBattleRecords\n\t"
        "	ldr r0, _080B2DC4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2E0E\n\t"
        "	ldr r0, _080B2DC8\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B2DCC\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B2DF0\n\t"
        "	b _080B2E0E\n\t"
        "	.align 2, 0\n\t"
        "_080B2DB8: .4byte gBattleTypeFlags\n\t"
        "_080B2DBC: .4byte gSpecialVar_0x8004\n\t"
        "_080B2DC0: .4byte gLocalLinkPlayerId\n\t"
        "_080B2DC4: .4byte gWirelessCommType\n\t"
        "_080B2DC8: .4byte gBattleOutcome\n\t"
        "_080B2DCC:\n\t"
        "	ldr r4, _080B2DEC\n\t"
        "	bl GetMultiplayerId\n\t"
        "	eors r0, r5\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r4, #4\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldr r1, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	bl MysteryGift_TryIncrementStat\n\t"
        "	b _080B2E0E\n\t"
        "	.align 2, 0\n\t"
        "_080B2DEC: .4byte gLinkPlayers\n\t"
        "_080B2DF0:\n\t"
        "	ldr r4, _080B2E1C\n\t"
        "	bl GetMultiplayerId\n\t"
        "	eors r0, r5\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r4, #4\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldr r1, [r1]\n\t"
        "	movs r0, #1\n\t"
        "	bl MysteryGift_TryIncrementStat\n\t"
        "_080B2E0E:\n\t"
        "	bl InUnionRoom\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080B2E28\n\t"
        "	ldr r1, _080B2E20\n\t"
        "	ldr r0, _080B2E24\n\t"
        "	b _080B2E2C\n\t"
        "	.align 2, 0\n\t"
        "_080B2E1C: .4byte gLinkPlayers\n\t"
        "_080B2E20: .4byte gMain\n\t"
        "_080B2E24: .4byte CB2_ReturnFromUnionRoomBattle + 1\n\t"
        "_080B2E28:\n\t"
        "	ldr r1, _080B2E3C\n\t"
        "	ldr r0, _080B2E40\n\t"
        "_080B2E2C:\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, _080B2E44\n\t"
        "	bl SetMainCallback2\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2E3C: .4byte gMain\n\t"
        "_080B2E40: .4byte CB2_ReturnToFieldFromMultiplayer + 1\n\t"
        "_080B2E44: .4byte sub_0809FDEC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CleanupLinkRoomState(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080B2E74\n\t"
        "	ldrh r1, [r0]\n\t"
        "	subs r0, r1, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #1\n\t"
        "	bls _080B2E62\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r0, #5\n\t"
        "	beq _080B2E62\n\t"
        "	cmp r0, #9\n\t"
        "	bne _080B2E6A\n\t"
        "_080B2E62:\n\t"
        "	bl LoadPlayerParty\n\t"
        "	bl SavePlayerBag\n\t"
        "_080B2E6A:\n\t"
        "	movs r0, #0x7f\n\t"
        "	bl SetWarpDestinationToDynamicWarp\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2E74: .4byte gSpecialVar_0x8004\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ExitLinkRoom(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl QueueExitLinkRoomKey\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2E84(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080B2EA8\n\t"
        "	adds r5, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B2EC8\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080B2EAC\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2EB6\n\t"
        "	b _080B2F28\n\t"
        "	.align 2, 0\n\t"
        "_080B2EA8: .4byte gTasks\n\t"
        "_080B2EAC:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B2EE8\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080B2F14\n\t"
        "	b _080B2F28\n\t"
        "_080B2EB6:\n\t"
        "	ldr r0, _080B2EC4\n\t"
        "	bl ShowFieldMessage\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	b _080B2F28\n\t"
        "	.align 2, 0\n\t"
        "_080B2EC4: .4byte gUnknown_8247C79\n\t"
        "_080B2EC8:\n\t"
        "	bl IsFieldMessageBoxHidden\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2F28\n\t"
        "	bl sub_08086BEC\n\t"
        "	ldr r0, _080B2EE4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl SetLocalLinkPlayerId\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	b _080B2F28\n\t"
        "	.align 2, 0\n\t"
        "_080B2EE4: .4byte gSpecialVar_0x8005\n\t"
        "_080B2EE8:\n\t"
        "	bl sub_08086B78\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B2EFA\n\t"
        "	cmp r0, #1\n\t"
        "	blo _080B2F28\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B2F0E\n\t"
        "	b _080B2F28\n\t"
        "_080B2EFA:\n\t"
        "	bl HideFieldMessageBox\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	bl sub_08086C28\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SwitchTaskToFollowupFunc\n\t"
        "	b _080B2F28\n\t"
        "_080B2F0E:\n\t"
        "	movs r0, #3\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	b _080B2F28\n\t"
        "_080B2F14:\n\t"
        "	bl sub_08086C00\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_081978F0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "	bl ScriptContext_Enable\n\t"
        "_080B2F28:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2F30(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r4, _080B2F54\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x50\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl SetTaskFuncWithFollowupFunc\n\t"
        "	bl ScriptContext_Stop\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2F54: .4byte sub_080B2E84 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2F58(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080B2F7C\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B2F9C\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080B2F80\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2F8A\n\t"
        "	b _080B2FE0\n\t"
        "	.align 2, 0\n\t"
        "_080B2F7C: .4byte gTasks\n\t"
        "_080B2F80:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B2FB0\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080B2FCC\n\t"
        "	b _080B2FE0\n\t"
        "_080B2F8A:\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	bl FadeScreen\n\t"
        "	bl ClearLinkCallback_2\n\t"
        "	b _080B2FC0\n\t"
        "_080B2F9C:\n\t"
        "	ldr r0, _080B2FAC\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B2FE0\n\t"
        "	b _080B2FC0\n\t"
        "	.align 2, 0\n\t"
        "_080B2FAC: .4byte gPaletteFade\n\t"
        "_080B2FB0:\n\t"
        "	ldr r1, _080B2FC8\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	bl m4aMPlayAllStop\n\t"
        "	bl SetCloseLinkCallback\n\t"
        "_080B2FC0:\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	b _080B2FE0\n\t"
        "	.align 2, 0\n\t"
        "_080B2FC8: .4byte gSelectedTradeMonPositions\n\t"
        "_080B2FCC:\n\t"
        "	ldr r0, _080B2FE8\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B2FE0\n\t"
        "	ldr r0, _080B2FEC\n\t"
        "	bl SetMainCallback2\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B2FE0:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2FE8: .4byte gReceivedRemoteLinkPlayers\n\t"
        "_080B2FEC: .4byte CB2_StartCreateTradeMenu + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2FF0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080B3014\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B3034\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080B3018\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B3022\n\t"
        "	b _080B3078\n\t"
        "	.align 2, 0\n\t"
        "_080B3014: .4byte gUnknown_3005B68\n\t"
        "_080B3018:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B3048\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080B3064\n\t"
        "	b _080B3078\n\t"
        "_080B3022:\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	bl FadeScreen\n\t"
        "	bl ClearLinkRfuCallback\n\t"
        "	b _080B3058\n\t"
        "_080B3034:\n\t"
        "	ldr r0, _080B3044\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B3078\n\t"
        "	b _080B3058\n\t"
        "	.align 2, 0\n\t"
        "_080B3044: .4byte gPaletteFade\n\t"
        "_080B3048:\n\t"
        "	ldr r1, _080B3060\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	bl m4aMPlayAllStop\n\t"
        "	bl SetLinkStandbyCallback\n\t"
        "_080B3058:\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4]\n\t"
        "	b _080B3078\n\t"
        "	.align 2, 0\n\t"
        "_080B3060: .4byte gSelectedTradeMonPositions\n\t"
        "_080B3064:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B3078\n\t"
        "	bl EvolutionSparkles_CircleInward\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B3078:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayerEnteredTradeSeat(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080B3094\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B309C\n\t"
        "	ldr r0, _080B3098\n\t"
        "	bl sub_080B2F30\n\t"
        "	b _080B30A2\n\t"
        "	.align 2, 0\n\t"
        "_080B3094: .4byte gWirelessCommType\n\t"
        "_080B3098: .4byte sub_080B2FF0 + 1\n\t"
        "_080B309C:\n\t"
        "	ldr r0, _080B30A8\n\t"
        "	bl sub_080B2F30\n\t"
        "_080B30A2:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B30A8: .4byte sub_080B2F58 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B30AC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080B30BC\n\t"
        "	movs r1, #0x50\n\t"
        "	bl CreateTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B30BC: .4byte sub_080B2F58 + 1\n\t"
        ".syntax divided\n\t"
    );
}

void nullsub_37(void) {}
__attribute__((naked)) void ColosseumPlayerSpotTriggered(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080B30E0\n\t"
        "	ldr r2, _080B30E4\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080B30E8\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B30F0\n\t"
        "	ldr r0, _080B30EC\n\t"
        "	bl sub_080B2F30\n\t"
        "	b _080B30F6\n\t"
        "	.align 2, 0\n\t"
        "_080B30E0: .4byte gLinkType\n\t"
        "_080B30E4: .4byte 0x00002211\n\t"
        "_080B30E8: .4byte gWirelessCommType\n\t"
        "_080B30EC: .4byte Task_StartWirelessCableClubBattle + 1\n\t"
        "_080B30F0:\n\t"
        "	ldr r0, _080B30FC\n\t"
        "	bl sub_080B2F30\n\t"
        "_080B30F6:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B30FC: .4byte Task_StartWiredCableClubBattle + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B3100(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080B3114\n\t"
        "	movs r1, #0x50\n\t"
        "	bl CreateTask\n\t"
        "	bl ScriptContext_Stop\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B3114: .4byte sub_080B2E84 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sp02A_crash_sound(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080B3128\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, _080B312C\n\t"
        "	bl ShowTrainerCardInLink\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B3128: .4byte gSpecialVar_0x8006\n\t"
        "_080B312C: .4byte CB2_ReturnToFieldContinueScriptPlayMapMusic + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool32 GetLinkTrainerCardColor(u8 linkPlayerIndex)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _080B316C\n\t"
        "	strh r4, [r0]\n\t"
        "	ldr r0, _080B3170\n\t"
        "	lsls r1, r4, #3\n\t"
        "	subs r1, r1, r4\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r2, _080B3174\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetTrainerCardStars\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0\n\t"
        "	beq _080B3180\n\t"
        "	ldr r0, _080B3178\n\t"
        "	lsls r1, r2, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _080B317C\n\t"
        "	adds r1, r1, r2\n\t"
        "	bl StringCopy\n\t"
        "	movs r0, #1\n\t"
        "	b _080B3182\n\t"
        "	.align 2, 0\n\t"
        "_080B316C: .4byte gSpecialVar_0x8006\n\t"
        "_080B3170: .4byte gStringVar1\n\t"
        "_080B3174: .4byte gUnknown_20226A8\n\t"
        "_080B3178: .4byte gStringVar2\n\t"
        "_080B317C: .4byte sBadgeFlagsJp + 0x1F\n\t"
        "_080B3180:\n\t"
        "	movs r0, #0\n\t"
        "_080B3182:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void task00_08081A90(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r5, r4, #0\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080B31E8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #8]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r0, #8]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	movs r0, #0x96\n\t"
        "	lsls r0, r0, #0x11\n\t"
        "	cmp r1, r0\n\t"
        "	ble _080B31BA\n\t"
        "	bl CloseLink\n\t"
        "	ldr r0, _080B31EC\n\t"
        "	bl SetMainCallback2\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B31BA:\n\t"
        "	ldr r0, _080B31F0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B31FE\n\t"
        "	ldr r0, _080B31F4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B31F8\n\t"
        "	bl sub_0800A624\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B31DE\n\t"
        "	bl CloseLink\n\t"
        "	ldr r0, _080B31EC\n\t"
        "	bl SetMainCallback2\n\t"
        "_080B31DE:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "	b _080B31FE\n\t"
        "	.align 2, 0\n\t"
        "_080B31E8: .4byte gTasks\n\t"
        "_080B31EC: .4byte CB2_LinkError + 1\n\t"
        "_080B31F0: .4byte gReceivedRemoteLinkPlayers\n\t"
        "_080B31F4: .4byte gWirelessCommType\n\t"
        "_080B31F8:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B31FE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B3204(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _080B3224\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B321C\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B321C:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B3224: .4byte gReceivedRemoteLinkPlayers\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B3228(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl SetCloseLinkCallback\n\t"
        "	ldr r1, _080B3248\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _080B324C\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B3248: .4byte gTasks\n\t"
        "_080B324C: .4byte sub_080B3204 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B3250(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080B3274\n\t"
        "	adds r5, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B32AC\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080B3278\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B3282\n\t"
        "	b _080B3310\n\t"
        "	.align 2, 0\n\t"
        "_080B3274: .4byte gUnknown_3005B68\n\t"
        "_080B3278:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B32C0\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080B32F6\n\t"
        "	b _080B3310\n\t"
        "_080B3282:\n\t"
        "	ldr r0, _080B3294\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B3298\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "	b _080B3310\n\t"
        "	.align 2, 0\n\t"
        "_080B3294: .4byte gWirelessCommType\n\t"
        "_080B3298:\n\t"
        "	bl OpenLink\n\t"
        "	ldr r0, _080B32A8\n\t"
        "	movs r1, #1\n\t"
        "	bl CreateTask\n\t"
        "	b _080B32EE\n\t"
        "	.align 2, 0\n\t"
        "_080B32A8: .4byte Task_WaitForLinkPlayerConnection + 1\n\t"
        "_080B32AC:\n\t"
        "	ldrh r0, [r5, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #2]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xb\n\t"
        "	ble _080B3310\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #2]\n\t"
        "	b _080B32EE\n\t"
        "_080B32C0:\n\t"
        "	bl GetLinkPlayerCount_2\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl GetSavedPlayerCount\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	blo _080B3310\n\t"
        "	bl IsLinkMaster\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B32EE\n\t"
        "	ldrh r0, [r5, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #2]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x1e\n\t"
        "	ble _080B3310\n\t"
        "	bl CheckShouldAdvanceLinkState\n\t"
        "_080B32EE:\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5]\n\t"
        "	b _080B3310\n\t"
        "_080B32F6:\n\t"
        "	ldr r0, _080B3318\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080B3310\n\t"
        "	bl IsLinkPlayerDataExchangeComplete\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080B3310\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B3310:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B3318: .4byte gReceivedRemoteLinkPlayers\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B331C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080B3334\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B332E\n\t"
        "	ldr r1, _080B3338\n\t"
        "	ldr r2, _080B333C\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "_080B332E:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B3334: .4byte gWirelessCommType\n\t"
        "_080B3338: .4byte gLinkType\n\t"
        "_080B333C: .4byte 0x00002288\n\t"
        ".syntax divided\n\t"
    );
}
