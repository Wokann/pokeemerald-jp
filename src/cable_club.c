#include "global.h"
#include "cable_club.h"
#include "constants/songs.h"
#include "data.h"
#include "event_data.h"
#include "field_message_box.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "string_util.h"
#include "trainer_card.h"
#include "window.h"

#define tMinPlayers data[1]
#define tMaxPlayers data[2]
#define tNumPlayers data[3]
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
void Task_LinkupFailed(u8 taskId);
void Task_LinkupConnectionError(u8 taskId);

extern const struct WindowTemplate sWindowTemplate_LinkPlayerCount;
extern const u8 gText_ConfirmLinkWhenPlayersReady[];
extern const u8 gText_ConfirmStartLinkWithXPlayers[];
extern const u8 gText_AwaitingLinkup[];
extern struct Pokemon gUnknown_202412C[];
extern void TrainerCard_GenerateCardForPlayer(struct TrainerCard *trainerCard);

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

__attribute__((naked)) void Task_StopLinkup(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _080B25C0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B25BA\n\t"
        "	ldr r0, _080B25C4\n\t"
        "	lsls r4, r5, #2\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	bl ClearLinkPlayerCountWindow\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	ldrb r0, [r4, #0x12]\n\t"
        "	bl RemoveWindow\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B25BA:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B25C0: .4byte gReceivedRemoteLinkPlayers\n\t"
        "_080B25C4: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_LinkupFailed(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r1, _080B2600\n\t"
        "	movs r0, #5\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080B2604\n\t"
        "	lsls r4, r5, #2\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	bl ClearLinkPlayerCountWindow\n\t"
        "	bl StopFieldMessage\n\t"
        "	ldrb r0, [r4, #0x12]\n\t"
        "	bl RemoveWindow\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2600: .4byte gSpecialVar_Result\n\t"
        "_080B2604: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_LinkupConnectionError(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r1, _080B2640\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080B2644\n\t"
        "	lsls r4, r5, #2\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	bl ClearLinkPlayerCountWindow\n\t"
        "	ldrb r0, [r4, #0x12]\n\t"
        "	bl RemoveWindow\n\t"
        "	bl HideFieldMessageBox\n\t"
        "	bl ScriptContext_Enable\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2640: .4byte gSpecialVar_Result\n\t"
        "_080B2644: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 TryLinkTimeout(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _080B266C\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r2, r1, r2\n\t"
        "	ldrh r0, [r2, #0x10]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r2, #0x10]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	movs r1, #0x96\n\t"
        "	lsls r1, r1, #0x12\n\t"
        "	cmp r0, r1\n\t"
        "	bgt _080B2670\n\t"
        "	movs r0, #0\n\t"
        "	b _080B2676\n\t"
        "	.align 2, 0\n\t"
        "_080B266C: .4byte gTasks\n\t"
        "_080B2670:\n\t"
        "	ldr r0, _080B267C\n\t"
        "	str r0, [r2]\n\t"
        "	movs r0, #1\n\t"
        "_080B2676:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080B267C: .4byte Task_LinkupConnectionError + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2680(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	movs r3, #2\n\t"
        "	movs r2, #2\n\t"
        "	ldr r0, _080B2698\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B26B8\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _080B269C\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B26A6\n\t"
        "	b _080B2710\n\t"
        "	.align 2, 0\n\t"
        "_080B2698: .4byte gSpecialVar_0x8004\n\t"
        "_080B269C:\n\t"
        "	cmp r0, #5\n\t"
        "	beq _080B26C8\n\t"
        "	cmp r0, #9\n\t"
        "	beq _080B26DC\n\t"
        "	b _080B2710\n\t"
        "_080B26A6:\n\t"
        "	movs r3, #2\n\t"
        "	ldr r1, _080B26B0\n\t"
        "	ldr r4, _080B26B4\n\t"
        "	b _080B270C\n\t"
        "	.align 2, 0\n\t"
        "_080B26B0: .4byte gLinkType\n\t"
        "_080B26B4: .4byte 0x00002233\n\t"
        "_080B26B8:\n\t"
        "	movs r3, #2\n\t"
        "	ldr r1, _080B26C0\n\t"
        "	ldr r4, _080B26C4\n\t"
        "	b _080B270C\n\t"
        "	.align 2, 0\n\t"
        "_080B26C0: .4byte gLinkType\n\t"
        "_080B26C4: .4byte 0x00002244\n\t"
        "_080B26C8:\n\t"
        "	movs r3, #4\n\t"
        "	movs r2, #4\n\t"
        "	ldr r1, _080B26D4\n\t"
        "	ldr r4, _080B26D8\n\t"
        "	b _080B270C\n\t"
        "	.align 2, 0\n\t"
        "_080B26D4: .4byte gLinkType\n\t"
        "_080B26D8: .4byte 0x00002255\n\t"
        "_080B26DC:\n\t"
        "	movs r3, #2\n\t"
        "	ldr r0, _080B26F8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080B26FC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B2708\n\t"
        "	ldr r1, _080B2700\n\t"
        "	ldr r4, _080B2704\n\t"
        "	b _080B270C\n\t"
        "	.align 2, 0\n\t"
        "_080B26F8: .4byte gSaveBlock2Ptr\n\t"
        "_080B26FC: .4byte 0x00000CA9\n\t"
        "_080B2700: .4byte gLinkType\n\t"
        "_080B2704: .4byte 0x00002266\n\t"
        "_080B2708:\n\t"
        "	ldr r1, _080B2720\n\t"
        "	ldr r4, _080B2724\n\t"
        "_080B270C:\n\t"
        "	adds r0, r4, #0\n\t"
        "	strh r0, [r1]\n\t"
        "_080B2710:\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl CreateLinkupTask\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2720: .4byte gLinkType\n\t"
        "_080B2724: .4byte 0x00002277\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2728(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080B2744\n\t"
        "	ldr r2, _080B2748\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _080B274C\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #2\n\t"
        "	bl CreateLinkupTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2744: .4byte gLinkType\n\t"
        "_080B2748: .4byte 0x00001133\n\t"
        "_080B274C: .4byte gBattleTypeFlags\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2750(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080B2774\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _080B2778\n\t"
        "	ldr r2, _080B277C\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _080B2780\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #4\n\t"
        "	bl CreateLinkupTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2774: .4byte gSpecialVar_Result\n\t"
        "_080B2778: .4byte gLinkType\n\t"
        "_080B277C: .4byte 0x00003311\n\t"
        "_080B2780: .4byte gBattleTypeFlags\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2784(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080B27A0\n\t"
        "	ldr r2, _080B27A4\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _080B27A8\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #4\n\t"
        "	bl CreateLinkupTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B27A0: .4byte gLinkType\n\t"
        "_080B27A4: .4byte 0x00004411\n\t"
        "_080B27A8: .4byte gBattleTypeFlags\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B27AC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080B27C8\n\t"
        "	ldr r2, _080B27CC\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _080B27D0\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #4\n\t"
        "	movs r1, #4\n\t"
        "	bl CreateLinkupTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B27C8: .4byte gLinkType\n\t"
        "_080B27CC: .4byte 0x00006601\n\t"
        "_080B27D0: .4byte gBattleTypeFlags\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B27D4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080B27F0\n\t"
        "	ldr r2, _080B27F4\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _080B27F8\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #4\n\t"
        "	bl CreateLinkupTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B27F0: .4byte gLinkType\n\t"
        "_080B27F4: .4byte 0x00006602\n\t"
        "_080B27F8: .4byte gBattleTypeFlags\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 CreateTask_ReestablishCableClubLink()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080B2810\n\t"
        "	bl FuncIsActiveTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2814\n\t"
        "	movs r0, #0xff\n\t"
        "	b _080B28E0\n\t"
        "	.align 2, 0\n\t"
        "_080B2810: .4byte sub_080B28F0 + 1\n\t"
        "_080B2814:\n\t"
        "	ldr r0, _080B2828\n\t"
        "	ldrh r0, [r0]\n\t"
        "	subs r0, #1\n\t"
        "	cmp r0, #8\n\t"
        "	bhi _080B28D4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080B282C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2828: .4byte gSpecialVar_0x8004\n\t"
        "_080B282C: .4byte _080B2830\n\t"
        "_080B2830:\n\t"
        "	.4byte _080B2854\n\t"
        "	.4byte _080B2864\n\t"
        "	.4byte _080B28BC\n\t"
        "	.4byte _080B28CC\n\t"
        "	.4byte _080B2874\n\t"
        "	.4byte _080B28D4\n\t"
        "	.4byte _080B28D4\n\t"
        "	.4byte _080B28D4\n\t"
        "	.4byte _080B2884\n\t"
        "_080B2854:\n\t"
        "	ldr r1, _080B285C\n\t"
        "	ldr r2, _080B2860\n\t"
        "	b _080B28D0\n\t"
        "	.align 2, 0\n\t"
        "_080B285C: .4byte gLinkType\n\t"
        "_080B2860: .4byte 0x00002233\n\t"
        "_080B2864:\n\t"
        "	ldr r1, _080B286C\n\t"
        "	ldr r2, _080B2870\n\t"
        "	b _080B28D0\n\t"
        "	.align 2, 0\n\t"
        "_080B286C: .4byte gLinkType\n\t"
        "_080B2870: .4byte 0x00002244\n\t"
        "_080B2874:\n\t"
        "	ldr r1, _080B287C\n\t"
        "	ldr r2, _080B2880\n\t"
        "	b _080B28D0\n\t"
        "	.align 2, 0\n\t"
        "_080B287C: .4byte gLinkType\n\t"
        "_080B2880: .4byte 0x00002255\n\t"
        "_080B2884:\n\t"
        "	ldr r0, _080B289C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080B28A0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B28AC\n\t"
        "	ldr r1, _080B28A4\n\t"
        "	ldr r2, _080B28A8\n\t"
        "	b _080B28D0\n\t"
        "	.align 2, 0\n\t"
        "_080B289C: .4byte gSaveBlock2Ptr\n\t"
        "_080B28A0: .4byte 0x00000CA9\n\t"
        "_080B28A4: .4byte gLinkType\n\t"
        "_080B28A8: .4byte 0x00002266\n\t"
        "_080B28AC:\n\t"
        "	ldr r1, _080B28B4\n\t"
        "	ldr r2, _080B28B8\n\t"
        "	b _080B28D0\n\t"
        "	.align 2, 0\n\t"
        "_080B28B4: .4byte gLinkType\n\t"
        "_080B28B8: .4byte 0x00002277\n\t"
        "_080B28BC:\n\t"
        "	ldr r1, _080B28C4\n\t"
        "	ldr r2, _080B28C8\n\t"
        "	b _080B28D0\n\t"
        "	.align 2, 0\n\t"
        "_080B28C4: .4byte gLinkType\n\t"
        "_080B28C8: .4byte 0x00001111\n\t"
        "_080B28CC:\n\t"
        "	ldr r1, _080B28E4\n\t"
        "	ldr r2, _080B28E8\n\t"
        "_080B28D0:\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "_080B28D4:\n\t"
        "	ldr r0, _080B28EC\n\t"
        "	movs r1, #0x50\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "_080B28E0:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080B28E4: .4byte gLinkType\n\t"
        "_080B28E8: .4byte 0x00003322\n\t"
        "_080B28EC: .4byte sub_080B28F0 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B28F0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _080B291C\n\t"
        "	adds r4, r1, r0\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r2, [r4, r3]\n\t"
        "	cmp r2, #0\n\t"
        "	bne _080B2924\n\t"
        "	bl OpenLink\n\t"
        "	bl ResetLinkPlayers\n\t"
        "	ldr r0, _080B2920\n\t"
        "	movs r1, #0x50\n\t"
        "	bl CreateTask\n\t"
        "	b _080B2930\n\t"
        "	.align 2, 0\n\t"
        "_080B291C: .4byte gUnknown_3005B68\n\t"
        "_080B2920: .4byte Task_WaitForLinkPlayerConnection + 1\n\t"
        "_080B2924:\n\t"
        "	cmp r2, #9\n\t"
        "	ble _080B2930\n\t"
        "	subs r0, #8\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldr r1, _080B293C\n\t"
        "	str r1, [r0]\n\t"
        "_080B2930:\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B293C: .4byte sub_080B2940 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2940(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r5, r4, #0\n\t"
        "	bl GetLinkPlayerCount_2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bls _080B2986\n\t"
        "	bl IsLinkMaster\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080B2978\n\t"
        "	ldr r0, _080B2970\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _080B2974\n\t"
        "	b _080B2984\n\t"
        "	.align 2, 0\n\t"
        "_080B2970: .4byte gTasks\n\t"
        "_080B2974: .4byte sub_080B2994 + 1\n\t"
        "_080B2978:\n\t"
        "	ldr r0, _080B298C\n\t"
        "	lsls r1, r5, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _080B2990\n\t"
        "_080B2984:\n\t"
        "	str r0, [r1]\n\t"
        "_080B2986:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B298C: .4byte gTasks\n\t"
        "_080B2990: .4byte sub_080B29CC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2994(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	bl GetSavedPlayerCount\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl GetLinkPlayerCount_2\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	bne _080B29BE\n\t"
        "	bl CheckShouldAdvanceLinkState\n\t"
        "	ldr r0, _080B29C4\n\t"
        "	lsls r1, r5, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _080B29C8\n\t"
        "	str r0, [r1]\n\t"
        "_080B29BE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B29C4: .4byte gTasks\n\t"
        "_080B29C8: .4byte sub_080B29CC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B29CC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _080B29FC\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080B29F4\n\t"
        "	bl IsLinkPlayerDataExchangeComplete\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080B29F4\n\t"
        "	bl sub_0800A6DC\n\t"
        "	bl StartSendingKeysToLink\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B29F4:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B29FC: .4byte gReceivedRemoteLinkPlayers\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2A00(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl SaveGame\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2A0C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B2A30\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _080B2A1C\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B2A26\n\t"
        "	b _080B2A52\n\t"
        "_080B2A1C:\n\t"
        "	cmp r0, #5\n\t"
        "	beq _080B2A3C\n\t"
        "	cmp r0, #9\n\t"
        "	beq _080B2A4C\n\t"
        "	b _080B2A52\n\t"
        "_080B2A26:\n\t"
        "	ldr r1, _080B2A2C\n\t"
        "	movs r0, #0xa\n\t"
        "	b _080B2A50\n\t"
        "	.align 2, 0\n\t"
        "_080B2A2C: .4byte gBattleTypeFlags\n\t"
        "_080B2A30:\n\t"
        "	ldr r1, _080B2A38\n\t"
        "	movs r0, #0xb\n\t"
        "	b _080B2A50\n\t"
        "	.align 2, 0\n\t"
        "_080B2A38: .4byte gBattleTypeFlags\n\t"
        "_080B2A3C:\n\t"
        "	bl ReducePlayerPartyToSelectedMons\n\t"
        "	ldr r1, _080B2A48\n\t"
        "	movs r0, #0x4b\n\t"
        "	b _080B2A50\n\t"
        "	.align 2, 0\n\t"
        "_080B2A48: .4byte gBattleTypeFlags\n\t"
        "_080B2A4C:\n\t"
        "	ldr r1, _080B2A58\n\t"
        "	ldr r0, _080B2A5C\n\t"
        "_080B2A50:\n\t"
        "	str r0, [r1]\n\t"
        "_080B2A52:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2A58: .4byte gBattleTypeFlags\n\t"
        "_080B2A5C: .4byte SPECIAL_Script_FadeOutMapMusic\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2A60(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080B2A84\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #5\n\t"
        "	bhi _080B2B4C\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080B2A88\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2A84: .4byte gTasks\n\t"
        "_080B2A88: .4byte _080B2A8C\n\t"
        "_080B2A8C:\n\t"
        "	.4byte _080B2AA4\n\t"
        "	.4byte _080B2AC4\n\t"
        "	.4byte _080B2AD4\n\t"
        "	.4byte _080B2AE4\n\t"
        "	.4byte _080B2AEA\n\t"
        "	.4byte _080B2B00\n\t"
        "_080B2AA4:\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	bl FadeScreen\n\t"
        "	ldr r1, _080B2ABC\n\t"
        "	ldr r2, _080B2AC0\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	bl ClearLinkCallback_2\n\t"
        "	b _080B2AF2\n\t"
        "	.align 2, 0\n\t"
        "_080B2ABC: .4byte gLinkType\n\t"
        "_080B2AC0: .4byte 0x00002211\n\t"
        "_080B2AC4:\n\t"
        "	ldr r0, _080B2AD0\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	b _080B2AEE\n\t"
        "	.align 2, 0\n\t"
        "_080B2AD0: .4byte gPaletteFade\n\t"
        "_080B2AD4:\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x14\n\t"
        "	ble _080B2B4C\n\t"
        "	b _080B2AF2\n\t"
        "_080B2AE4:\n\t"
        "	bl SetCloseLinkCallback\n\t"
        "	b _080B2AF2\n\t"
        "_080B2AEA:\n\t"
        "	ldr r0, _080B2AFC\n\t"
        "	ldrb r0, [r0]\n\t"
        "_080B2AEE:\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B2B4C\n\t"
        "_080B2AF2:\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	b _080B2B4C\n\t"
        "	.align 2, 0\n\t"
        "_080B2AFC: .4byte gReceivedRemoteLinkPlayers\n\t"
        "_080B2B00:\n\t"
        "	ldr r0, _080B2B14\n\t"
        "	ldr r0, [r0, #4]\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2B1C\n\t"
        "	ldr r0, _080B2B18\n\t"
        "	bl PlayMapChosenOrBattleBGM\n\t"
        "	b _080B2B24\n\t"
        "	.align 2, 0\n\t"
        "_080B2B14: .4byte gLinkPlayers\n\t"
        "_080B2B18: .4byte SPECIAL_DoDeoxysRockInteraction\n\t"
        "_080B2B1C:\n\t"
        "	movs r0, #0xee\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl PlayMapChosenOrBattleBGM\n\t"
        "_080B2B24:\n\t"
        "	ldr r0, _080B2B54\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl sub_080B2A0C\n\t"
        "	bl CleanupOverworldWindowsAndTilemaps\n\t"
        "	ldr r1, _080B2B58\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #4\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080B2B5C\n\t"
        "	bl SetMainCallback2\n\t"
        "	ldr r1, _080B2B60\n\t"
        "	ldr r0, _080B2B64\n\t"
        "	str r0, [r1, #8]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B2B4C:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2B54: .4byte gSpecialVar_0x8004\n\t"
        "_080B2B58: .4byte gTrainerBattleOpponent_A\n\t"
        "_080B2B5C: .4byte CB2_InitBattle + 1\n\t"
        "_080B2B60: .4byte gMain\n\t"
        "_080B2B64: .4byte CB2_ReturnFromCableClubBattle + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2B68(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080B2B8C\n\t"
        "	adds r5, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #7\n\t"
        "	bls _080B2B82\n\t"
        "	b _080B2CDA\n\t"
        "_080B2B82:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080B2B90\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2B8C: .4byte gUnknown_3005B68\n\t"
        "_080B2B90: .4byte _080B2B94\n\t"
        "_080B2B94:\n\t"
        "	.4byte _080B2BB4\n\t"
        "	.4byte _080B2BD8\n\t"
        "	.4byte _080B2BF0\n\t"
        "	.4byte _080B2C04\n\t"
        "	.4byte _080B2C58\n\t"
        "	.4byte _080B2C6C\n\t"
        "	.4byte _080B2C76\n\t"
        "	.4byte _080B2C86\n\t"
        "_080B2BB4:\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	bl FadeScreen\n\t"
        "	ldr r0, _080B2BD0\n\t"
        "	ldr r2, _080B2BD4\n\t"
        "	adds r1, r2, #0\n\t"
        "	strh r1, [r0]\n\t"
        "	bl ClearLinkCallback_2\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r5]\n\t"
        "	b _080B2CDA\n\t"
        "	.align 2, 0\n\t"
        "_080B2BD0: .4byte gLinkType\n\t"
        "_080B2BD4: .4byte 0x00002211\n\t"
        "_080B2BD8:\n\t"
        "	ldr r0, _080B2BEC\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2BE6\n\t"
        "	b _080B2CDA\n\t"
        "_080B2BE6:\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5]\n\t"
        "	b _080B2CDA\n\t"
        "	.align 2, 0\n\t"
        "_080B2BEC: .4byte gPaletteFade\n\t"
        "_080B2BF0:\n\t"
        "	ldr r1, _080B2C00\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #0x1c\n\t"
        "	bl SendBlock\n\t"
        "	movs r0, #3\n\t"
        "	strh r0, [r5]\n\t"
        "	b _080B2CDA\n\t"
        "	.align 2, 0\n\t"
        "_080B2C00: .4byte gLocalLinkPlayer\n\t"
        "_080B2C04:\n\t"
        "	bl GetBlockReceivedStatus\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl sub_0800A59C\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	bne _080B2CDA\n\t"
        "	movs r4, #0\n\t"
        "	ldr r6, _080B2C1C\n\t"
        "	b _080B2C40\n\t"
        "	.align 2, 0\n\t"
        "_080B2C1C: .4byte gLinkPlayers\n\t"
        "_080B2C20:\n\t"
        "	lsls r1, r4, #8\n\t"
        "	ldr r2, _080B2C54\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldm r1!, {r2, r3, r7}\n\t"
        "	stm r0!, {r2, r3, r7}\n\t"
        "	ldm r1!, {r2, r3, r7}\n\t"
        "	stm r0!, {r2, r3, r7}\n\t"
        "	ldr r1, [r1]\n\t"
        "	str r1, [r0]\n\t"
        "	lsls r0, r4, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl ResetBlockReceivedFlag\n\t"
        "	adds r6, #0x1c\n\t"
        "	adds r4, #1\n\t"
        "_080B2C40:\n\t"
        "	bl GetLinkPlayerCount\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	blt _080B2C20\n\t"
        "	movs r0, #4\n\t"
        "	strh r0, [r5]\n\t"
        "	b _080B2CDA\n\t"
        "	.align 2, 0\n\t"
        "_080B2C54: .4byte gBlockRecvBuffer\n\t"
        "_080B2C58:\n\t"
        "	ldrh r0, [r5, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #2]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x14\n\t"
        "	ble _080B2CDA\n\t"
        "	movs r0, #5\n\t"
        "	strh r0, [r5]\n\t"
        "	b _080B2CDA\n\t"
        "_080B2C6C:\n\t"
        "	bl SetLinkStandbyCallback\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r5]\n\t"
        "	b _080B2CDA\n\t"
        "_080B2C76:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2CDA\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r5]\n\t"
        "	b _080B2CDA\n\t"
        "_080B2C86:\n\t"
        "	ldr r0, _080B2C9C\n\t"
        "	ldr r0, [r0, #4]\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2CA4\n\t"
        "	ldr r0, _080B2CA0\n\t"
        "	bl PlayMapChosenOrBattleBGM\n\t"
        "	b _080B2CAC\n\t"
        "	.align 2, 0\n\t"
        "_080B2C9C: .4byte gLinkPlayers\n\t"
        "_080B2CA0: .4byte SPECIAL_DoDeoxysRockInteraction\n\t"
        "_080B2CA4:\n\t"
        "	movs r0, #0xee\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl PlayMapChosenOrBattleBGM\n\t"
        "_080B2CAC:\n\t"
        "	ldr r1, _080B2CE0\n\t"
        "	ldr r0, _080B2CE4\n\t"
        "	str r0, [r1, #0x14]\n\t"
        "	ldr r0, _080B2CE8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl sub_080B2A0C\n\t"
        "	bl CleanupOverworldWindowsAndTilemaps\n\t"
        "	ldr r1, _080B2CEC\n\t"
        "	movs r3, #0x80\n\t"
        "	lsls r3, r3, #4\n\t"
        "	adds r0, r3, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080B2CF0\n\t"
        "	bl SetMainCallback2\n\t"
        "	ldr r1, _080B2CF4\n\t"
        "	ldr r0, _080B2CF8\n\t"
        "	str r0, [r1, #8]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_080B2CDA:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2CE0: .4byte gLinkPlayers\n\t"
        "_080B2CE4: .4byte 0x00002211\n\t"
        "_080B2CE8: .4byte gSpecialVar_0x8004\n\t"
        "_080B2CEC: .4byte gTrainerBattleOpponent_A\n\t"
        "_080B2CF0: .4byte CB2_InitBattle + 1\n\t"
        "_080B2CF4: .4byte gMain\n\t"
        "_080B2CF8: .4byte CB2_ReturnFromCableClubBattle + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080B2CFC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _080B2D18\n\t"
        "	movs r1, #0x87\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrb r0, [r4]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080B2D3A\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080B2D1C\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2D22\n\t"
        "	b _080B2D5A\n\t"
        "	.align 2, 0\n\t"
        "_080B2D18: .4byte gMain\n\t"
        "_080B2D1C:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080B2D54\n\t"
        "	b _080B2D5A\n\t"
        "_080B2D22:\n\t"
        "	bl SetCloseLinkCallback\n\t"
        "	bl sub_08009C40\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B2D34\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r4]\n\t"
        "	b _080B2D5A\n\t"
        "_080B2D34:\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r4]\n\t"
        "	b _080B2D5A\n\t"
        "_080B2D3A:\n\t"
        "	ldr r0, _080B2D4C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B2D5A\n\t"
        "	ldr r0, _080B2D50\n\t"
        "	bl SetMainCallback2\n\t"
        "	b _080B2D5A\n\t"
        "	.align 2, 0\n\t"
        "_080B2D4C: .4byte gReceivedRemoteLinkPlayers\n\t"
        "_080B2D50: .4byte CB2_ReturnToField + 1\n\t"
        "_080B2D54:\n\t"
        "	ldr r0, _080B2D64\n\t"
        "	bl SetMainCallback2\n\t"
        "_080B2D5A:\n\t"
        "	bl RunTasks\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B2D64: .4byte CB2_ReturnToField + 1\n\t"
        ".syntax divided\n\t"
    );
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
        "_080B2E24: .4byte sub_080B2CFC + 1\n\t"
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
        "_080B30EC: .4byte sub_080B2B68 + 1\n\t"
        "_080B30F0:\n\t"
        "	ldr r0, _080B30FC\n\t"
        "	bl sub_080B2F30\n\t"
        "_080B30F6:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B30FC: .4byte sub_080B2A60 + 1\n\t"
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
