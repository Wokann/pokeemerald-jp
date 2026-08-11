#include "global.h"
#include "bg.h"
#include "cable_club.h"
#include "constants/songs.h"
#include "event_data.h"
#include "link.h"
#include "link_rfu.h"
#include "list_menu.h"
#include "malloc.h"
#include "menu.h"
#include "script.h"
#include "save_location.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "union_room.h"
#include "window.h"

#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity) (capacity & 0x0F)
#define GROUP_MIN(capacity) (capacity >> 4)
#define GROUP_MIN2(capacity) (capacity & 0xF0) // Unnecessary to have both, but needed to match

// States for Task_TryBecomeLinkLeader
enum {
    LL_STATE_INIT,
    LL_STATE_INIT2 = 3,
    LL_STATE_GET_AWAITING_PLAYERS_TEXT,
    LL_STATE_PRINT_AWAITING_PLAYERS,
    LL_STATE_AWAIT_PLAYERS,
    LL_STATE_ACCEPT_NEW_MEMBER_PROMPT,
    LL_STATE_WAIT_DISCONNECT_CHILD = 9,
    LL_STATE_MEMBER_LEFT,
    LL_STATE_ACCEPT_NEW_MEMBER_PROMPT_HANDLE_INPUT,
    LL_STATE_UPDATE_AFTER_JOIN_REQUEST,
    LL_STATE_ACCEPTED_FINAL_MEMBER,
    LL_STATE_WAIT_AND_CONFIRM_MEMBERS,
    LL_STATE_MEMBERS_OK_PROMPT,
    LL_STATE_MEMBERS_OK_PROMPT_HANDLE_INPUT,
    LL_STATE_CONFIRMED_MEMBERS,
    LL_STATE_FINAL_MEMBER_CHECK,
    LL_STATE_CANCEL_PROMPT,
    LL_STATE_CANCEL_PROMPT_HANDLE_INPUT,
    LL_STATE_SHUTDOWN_AND_RETRY,
    LL_STATE_RETRY,
    LL_STATE_SHUTDOWN_AND_FAIL,
    LL_STATE_FAILED,
    LL_STATE_TRY_START_ACTIVITY = 26,
    LL_STATE_MEMBER_DISCONNECTED = 29,
    LL_STATE_CANCEL_WITH_MSG
};

// Color types for PrintUnionRoomText
enum {
    UR_COLOR_DEFAULT,
    UR_COLOR_RED,
    UR_COLOR_GREEN,
    UR_COLOR_WHITE,
    UR_COLOR_CANCEL,
    UR_COLOR_TRADE_BOARD_SELF,
    UR_COLOR_TRADE_BOARD_OTHER,
};

// States for Task_TryJoinLinkGroup
enum {
    LG_STATE_INIT,
    LG_STATE_CHOOSE_LEADER_MSG,
    LG_STATE_INIT_WINDOWS,
    LG_STATE_CHOOSE_LEADER_HANDLE_INPUT,
    LG_STATE_ASK_JOIN_GROUP = 5,
    LG_STATE_MAIN,
    LG_STATE_ASK_LEAVE_GROUP,
    LG_STATE_ASK_LEAVE_GROUP_HANDLE_INPUT,
    LG_STATE_WAIT_LEAVE_GROUP,
    LG_STATE_CANCEL_CHOOSE_LEADER,
    LG_STATE_CANCELED,
    LG_STATE_RFU_ERROR,
    LG_STATE_RFU_ERROR_SHUTDOWN,
    LG_STATE_DISCONNECTED,
    LG_STATE_RETRY_CONNECTION,
    LG_STATE_TRADE_NOT_READY = 18,
    LG_STATE_TRADE_NOT_READY_RETRY,
    LG_STATE_READY_START_ACTIVITY,
    LG_STATE_START_ACTIVITY,
    LG_STATE_SHUTDOWN = 23,
};

// JP: RAM data bound via sym_*_jp.txt (JP uses fixed IWRAM/EWRAM addresses
// instead of US COMMON_DATA / EWRAM_DATA definitions).
extern EWRAM_DATA u8 gPlayerCurrActivity;
extern EWRAM_DATA u8 sPlayerActivityGroupSize;
extern EWRAM_DATA union
{
    struct WirelessLink_Leader *leader;
    struct WirelessLink_Group *group;
    struct WirelessLink_URoom *uRoom;
} sWirelessLinkMain;
extern IWRAM_DATA struct WirelessLink_Leader *sLeader;
extern IWRAM_DATA struct WirelessLink_Group *sGroup;

// JP: ROM data bound via ld_script_jp.txt.
extern const u8 *const sPlayersNeededOrModeTexts[][5];
extern const u8 sText_ID[];
extern const u8 sText_AwaitingCommunication[];
extern const u8 sText_AwaitingLinkPressStart[];
extern const u8 sText_BButtonCancel[];
extern const u8 sText_AreTheseMembersOK[];
extern const u8 sText_CancelModeWithTheseMembers[];
extern const u8 sText_ModeWithTheseMembersWillBeCanceled[];
extern const u8 sText_AnOKWasSentToPlayer[];
extern const u8 sText_PlayerContactedYouForXAccept[];
extern const u8 sText_PlayerContactedYouShareX[];
extern const u8 sText_PlayerContactedYouAddToMembers[];
extern const u8 sText_OfferDeclined1[];
extern const u8 sText_OfferDeclined2[];
extern const u8 sText_AwaitingPlayersResponse[];
extern const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[];
extern const u8 sText_PlayerSentBackOK[];
extern const u8 sText_PlayerOKdRegistration[];
extern const u8 sText_ChooseJoinCancel[];
extern const u8 sText_AwaitingOtherMembers[];
extern const u8 sText_QuitBeingMember[];
extern const u8 *const sPlayerUnavailableTexts[];
extern const struct RfuPlayerData sUnionRoomPlayer_DummyRfu;
extern const u8 *const sChooseTrainerTexts[];
extern const u8 *const sCantTransmitToTrainerTexts[];
extern const u8 *const sPlayerDisconnectedTexts[];
extern const u32 sLinkGroupToActivityAndCapacity[];
extern const u8 sLinkGroupToURoomActivity[];
extern const u8 *const sLinkGroupActivityNameTexts[];
extern const struct WindowTemplate sWindowTemplate_BButtonCancel;
extern const struct WindowTemplate sWindowTemplate_PlayerList;
extern const struct WindowTemplate sWindowTemplate_5PlayerList;
extern const struct WindowTemplate sWindowTemplate_NumPlayerMode;
extern const struct WindowTemplate sWindowTemplate_GroupList;
extern const struct WindowTemplate sWindowTemplate_PlayerNameAndId;
extern const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers;
extern const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups;

// JP: these helpers are still in asm/union_room.s; referenced by their sub_
// names until converted.
extern void PrintUnionRoomText(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 colorIdx);
extern u16 ReadAsU16(const u8 *ptr);
extern s8 UnionRoomHandleYesNo(u8 *textState, bool32 noActionButton);
extern bool8 PrintOnTextbox(u8 *textState, const u8 *str);
extern u8 CreateTask_ListenForCompatiblePartners(struct RfuIncomingPlayerList *list, u32 arg1);
extern void CreateTask_RunScriptAndFadeToActivity(void);
extern u8 LeaderUpdateGroupMembership(struct RfuPlayerList *playerList);
extern void PrintGroupCandidateOnWindow(u8 windowId, u8 fontId, u8 y, struct RfuPlayer *player, u8 colorIdx, u8 id);
extern u32 GetNewIncomingPlayerId(struct RfuPlayer *player, struct RfuIncomingPlayer *incomingPlayers);
extern u8 TryAddIncomingPlayerToList(struct RfuPlayer *players, struct RfuIncomingPlayer *incomingPlayer, u8 maxPlayers);
extern u8 GetNewLeaderCandidate(void);
extern void SendLeaveGroupNotice(void);
extern void JoinGroup_EnableScriptContexts(void);

static void Task_TryBecomeLinkLeader(u8 taskId);
static void Leader_DestroyResources(struct WirelessLink_Leader *data);
bool8 Leader_SetStateIfMemberListChanged(struct WirelessLink_Leader *data, u32 joinedState, u32 droppedState);
u8 LeaderPrunePlayerList(struct RfuPlayerList *playerList);
void TryJoinLinkGroup(void);
static void Task_TryJoinLinkGroup(u8 taskId);
static u32 IsTryingToTradeAcrossVersionTooSoon(struct WirelessLink_Group *group, s32 playerId);
static void AskToJoinRfuGroup(struct WirelessLink_Group *data, s32 id);
static void Task_ListenToWireless(u8 taskId);

void Task_Idle(u8 taskId)
{
}

void PrintNumPlayersWaitingForMsg(u8 windowId, u8 capacityCode, u8 stringId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    switch (capacityCode << 8)
    {
    case LINK_GROUP_CAPACITY(0, 2):
        PrintUnionRoomText(windowId, FONT_NORMAL, sPlayersNeededOrModeTexts[0][stringId - 1], 2, 3, UR_COLOR_DEFAULT);
        break;
    case LINK_GROUP_CAPACITY(0, 4):
        PrintUnionRoomText(windowId, FONT_NORMAL, sPlayersNeededOrModeTexts[1][stringId - 1], 2, 3, UR_COLOR_DEFAULT);
        break;
    case LINK_GROUP_CAPACITY(2, 5):
        PrintUnionRoomText(windowId, FONT_NORMAL, sPlayersNeededOrModeTexts[2][stringId - 1], 2, 3, UR_COLOR_DEFAULT);
        break;
    case LINK_GROUP_CAPACITY(3, 5):
        PrintUnionRoomText(windowId, FONT_NORMAL, sPlayersNeededOrModeTexts[3][stringId - 1], 2, 3, UR_COLOR_DEFAULT);
        break;
    case LINK_GROUP_CAPACITY(2, 4):
        PrintUnionRoomText(windowId, FONT_NORMAL, sPlayersNeededOrModeTexts[4][stringId - 1], 2, 3, UR_COLOR_DEFAULT);
        break;
    }

    CopyWindowToVram(windowId, COPYWIN_GFX);
}

void PrintPlayerNameAndIdOnWindow(u8 windowId)
{
    u8 text[8];
    u8 numBuf[12];
    u8 text2[12];

    StringCopyN_Multibyte(text, gSaveBlock2Ptr->playerName, 5);
    PrintUnionRoomText(windowId, FONT_NORMAL, text, 2, 3, UR_COLOR_DEFAULT);
    StringCopy(text2, sText_ID);
    ConvertIntToDecimalStringN(numBuf, ReadAsU16(gSaveBlock2Ptr->playerTrainerId), STR_CONV_MODE_LEADING_ZEROS, 5);
    StringAppend(text2, numBuf);
    PrintUnionRoomText(windowId, FONT_NORMAL, text2, 2, 16, UR_COLOR_DEFAULT);
}

void GetAwaitingCommunicationText(u8 *dst, u8 activity)
{
    switch (activity)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_TRADE:
    case ACTIVITY_WONDER_CARD_DUP:
    case ACTIVITY_WONDER_NEWS_DUP:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_BATTLE_TOWER_OPEN:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
    case ACTIVITY_BATTLE_TOWER:
        // BUG: argument *dst isn't used, instead it always prints to gStringVar4
        // not an issue in practice since Gamefreak never used any other arguments here besides gStringVar4
        StringExpandPlaceholders(gStringVar4, sText_AwaitingCommunication);
        break;
    }
}

bool32 IsActivityWithVariableGroupSize(u32 activity)
{
    switch (activity)
    {
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        return TRUE;
    default:
        return FALSE;
    }
}

void TryBecomeLinkLeader(void)
{
    u8 taskId;
    struct WirelessLink_Leader *data;

    taskId = CreateTask(Task_TryBecomeLinkLeader, 0);
    sWirelessLinkMain.leader = data = (void *)(gTasks[taskId].data);
    sLeader = data;

    data->state = LL_STATE_INIT;
    data->textState = 0;
    gSpecialVar_Result = LINKUP_ONGOING;
}

static void Task_TryBecomeLinkLeader(u8 taskId)
{
    u32 id, val;
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;

    switch (data->state)
    {
    case LL_STATE_INIT:
        if (gSpecialVar_0x8004 == LINK_GROUP_BATTLE_TOWER && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
            gSpecialVar_0x8004++;
        gPlayerCurrActivity = sLinkGroupToActivityAndCapacity[gSpecialVar_0x8004];
        sPlayerActivityGroupSize = sLinkGroupToActivityAndCapacity[gSpecialVar_0x8004] >> 8;
        SetHostRfuGameData(gPlayerCurrActivity, 0, FALSE);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_LinkLeader(GROUP_MAX(sPlayerActivityGroupSize));
        data->state = LL_STATE_INIT2;
        break;
    case LL_STATE_INIT2:
        data->incomingPlayerList = AllocZeroed(RFU_CHILD_MAX * sizeof(struct RfuIncomingPlayer));
        data->playerList = AllocZeroed(MAX_RFU_PLAYERS * sizeof(struct RfuPlayer));
        data->playerListBackup = AllocZeroed(MAX_RFU_PLAYERS * sizeof(struct RfuPlayer));
        ClearIncomingPlayerList(data->incomingPlayerList, RFU_CHILD_MAX);
        ClearRfuPlayerList(data->playerList->players, MAX_RFU_PLAYERS);
        CopyHostRfuGameDataAndUsername(&data->playerList->players[0].rfu.data, data->playerList->players[0].rfu.name);
        data->playerList->players[0].timeoutCounter = 0;
        data->playerList->players[0].groupScheduledAnim = UNION_ROOM_SPAWN_IN;
        data->playerList->players[0].useRedText = FALSE;
        data->playerList->players[0].newPlayerCountdown = 0;
        data->listenTaskId = CreateTask_ListenForCompatiblePartners(data->incomingPlayerList, 0xFF);
        data->bButtonCancelWindowId = AddWindow(&sWindowTemplate_BButtonCancel);
        switch (GROUP_MAX(sPlayerActivityGroupSize))
        {
        case 2:
        case 3:
        case 4:
            data->listWindowId = AddWindow(&sWindowTemplate_PlayerList);
            break;
        case 5:
            data->listWindowId = AddWindow(&sWindowTemplate_5PlayerList);
            break;
        }
        data->nPlayerModeWindowId = AddWindow(&sWindowTemplate_NumPlayerMode);

        FillWindowPixelBuffer(data->bButtonCancelWindowId, PIXEL_FILL(2));
        PrintUnionRoomText(data->bButtonCancelWindowId, FONT_NORMAL, sText_BButtonCancel, 8, 2, UR_COLOR_CANCEL);
        PutWindowTilemap(data->bButtonCancelWindowId);
        CopyWindowToVram(data->bButtonCancelWindowId, COPYWIN_GFX);

        DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = sListMenuTemplate_PossibleGroupMembers;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        DrawStdWindowFrame(data->nPlayerModeWindowId, FALSE);
        PutWindowTilemap(data->nPlayerModeWindowId);
        CopyWindowToVram(data->nPlayerModeWindowId, COPYWIN_GFX);

        CopyBgTilemapBufferToVram(0);
        data->playerCount = 1;
        data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
        break;
    case LL_STATE_GET_AWAITING_PLAYERS_TEXT:
        StringCopy(gStringVar1, sLinkGroupActivityNameTexts[gPlayerCurrActivity]);
        if (GROUP_MIN(sPlayerActivityGroupSize) != 0)
        {
            if (data->playerCount > GROUP_MIN(sPlayerActivityGroupSize) - 1 && GROUP_MAX(sPlayerActivityGroupSize) != 0)
                StringExpandPlaceholders(gStringVar4, sText_AwaitingLinkPressStart);
            else
                StringExpandPlaceholders(gStringVar4, sText_AwaitingCommunication);
        }
        else
        {
            GetAwaitingCommunicationText(gStringVar4, gPlayerCurrActivity);
        }

        PrintNumPlayersWaitingForMsg(data->nPlayerModeWindowId, sPlayerActivityGroupSize, data->playerCount);
        data->state = LL_STATE_PRINT_AWAITING_PLAYERS;
        break;
    case LL_STATE_PRINT_AWAITING_PLAYERS:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = LL_STATE_AWAIT_PLAYERS;
        break;
    case LL_STATE_AWAIT_PLAYERS:
        Leader_SetStateIfMemberListChanged(data, LL_STATE_ACCEPT_NEW_MEMBER_PROMPT, LL_STATE_MEMBER_LEFT);
        if (JOY_NEW(B_BUTTON))
        {
            if (data->playerCount == 1)
                data->state = LL_STATE_SHUTDOWN_AND_FAIL;
            else if (GROUP_MIN2(sPlayerActivityGroupSize) != 0)
                data->state = LL_STATE_CANCEL_WITH_MSG;
            else
                data->state = LL_STATE_CANCEL_PROMPT;
        }
        if (GROUP_MIN(sPlayerActivityGroupSize) != 0
            && data->playerCount > GROUP_MIN(sPlayerActivityGroupSize) - 1
            && GROUP_MAX(sPlayerActivityGroupSize) != 0
            && IsRfuCommunicatingWithAllChildren()
            && JOY_NEW(START_BUTTON))
        {
            data->state = LL_STATE_MEMBERS_OK_PROMPT;
            LinkRfu_StopManagerAndFinalizeSlots();
        }
        if (data->state == LL_STATE_AWAIT_PLAYERS && RfuTryDisconnectLeavingChildren())
        {
            // At least 1 group member has left or is trying to leave
            data->state = LL_STATE_WAIT_DISCONNECT_CHILD;
        }
        break;
    case LL_STATE_WAIT_DISCONNECT_CHILD:
        // Resume after ensuring all members trying to leave have left
        if (!RfuTryDisconnectLeavingChildren())
        {
            data->state = LL_STATE_AWAIT_PLAYERS;
            data->playerCount = LeaderPrunePlayerList(data->playerList);
        }
        break;
    case LL_STATE_MEMBER_LEFT:
        // BUG: sPlayerActivityGroupSize was meant below, not gPlayerCurrActivity
        //      This will be false for all but ACTIVITY_BATTLE_DOUBLE and ACTIVITY_DECLINE
        //      All this changes is which of two texts gets printed
        id = (GROUP_MAX(gPlayerCurrActivity) == 2) ? 1 : 0;
        if (PrintOnTextbox(&data->textState, sPlayerUnavailableTexts[id]))
        {
            data->playerCount = LeaderPrunePlayerList(data->playerList);
            RedrawListMenu(data->listTaskId);
            data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
        }
        break;
    case LL_STATE_MEMBER_DISCONNECTED:
        id = (GROUP_MAX(sPlayerActivityGroupSize) == 2) ? 0 : 1;
        if (PrintOnTextbox(&data->textState, sPlayerUnavailableTexts[id]))
        {
            data->state = LL_STATE_SHUTDOWN_AND_RETRY;
        }
        break;
    case LL_STATE_ACCEPT_NEW_MEMBER_PROMPT:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            data->state = LL_STATE_ACCEPT_NEW_MEMBER_PROMPT_HANDLE_INPUT;
        }
        break;
    case LL_STATE_ACCEPT_NEW_MEMBER_PROMPT_HANDLE_INPUT:
        switch (UnionRoomHandleYesNo(&data->textState, HasTrainerLeftPartnersList(ReadAsU16(data->playerList->players[data->playerCount].rfu.data.compatibility.playerTrainerId), data->playerList->players[data->playerCount].rfu.name)))
        {
        case 0: // YES
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
            data->joinRequestAnswer = RFU_STATUS_JOIN_GROUP_OK;
            SendRfuStatusToPartner(data->joinRequestAnswer, ReadAsU16(data->playerList->players[data->playerCount].rfu.data.compatibility.playerTrainerId), data->playerList->players[data->playerCount].rfu.name);
            data->state = LL_STATE_UPDATE_AFTER_JOIN_REQUEST;
            break;
        case 1: // NO
        case MENU_B_PRESSED:
            data->joinRequestAnswer = RFU_STATUS_JOIN_GROUP_NO;
            SendRfuStatusToPartner(data->joinRequestAnswer, ReadAsU16(data->playerList->players[data->playerCount].rfu.data.compatibility.playerTrainerId), data->playerList->players[data->playerCount].rfu.name);
            data->state = LL_STATE_UPDATE_AFTER_JOIN_REQUEST;
            break;
        case -3:
            data->state = LL_STATE_WAIT_DISCONNECT_CHILD;
            break;
        }
        break;
    case LL_STATE_UPDATE_AFTER_JOIN_REQUEST:
        val = WaitSendRfuStatusToPartner(ReadAsU16(data->playerList->players[data->playerCount].rfu.data.compatibility.playerTrainerId), data->playerList->players[data->playerCount].rfu.name);
        if (val == 1) // Send complete
        {
            if (data->joinRequestAnswer == RFU_STATUS_JOIN_GROUP_OK)
            {
                // Sent "OK"
                data->playerList->players[data->playerCount].newPlayerCountdown = 0;
                RedrawListMenu(data->listTaskId);
                data->playerCount++;
                if (data->playerCount == GROUP_MAX(sPlayerActivityGroupSize))
                {
                    if (GROUP_MIN2(sPlayerActivityGroupSize) != 0 || data->playerCount == RFU_CHILD_MAX)
                    {
                        data->state = LL_STATE_MEMBERS_OK_PROMPT;
                    }
                    else
                    {
                        StringCopy7(gStringVar1, data->playerList->players[data->playerCount - 1].rfu.name);
                        StringExpandPlaceholders(gStringVar4, sText_AnOKWasSentToPlayer);
                        data->state = LL_STATE_ACCEPTED_FINAL_MEMBER;
                    }

                    LinkRfu_StopManagerAndFinalizeSlots();
                    PrintNumPlayersWaitingForMsg(data->nPlayerModeWindowId, sPlayerActivityGroupSize, data->playerCount);
                }
                else
                {
                    data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
                }
            }
            else // Member disconnected
            {
                RequestDisconnectSlotByTrainerNameAndId(data->playerList->players[data->playerCount].rfu.name, ReadAsU16(data->playerList->players[data->playerCount].rfu.data.compatibility.playerTrainerId));
                data->playerList->players[data->playerCount].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
                LeaderPrunePlayerList(data->playerList);
                RedrawListMenu(data->listTaskId);
                data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
            }

            data->joinRequestAnswer = 0;
        }
        else if (val == 2)
        {
            // Disconnect
            RfuSetStatus(RFU_STATUS_OK, 0);
            data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
        }
        break;
    case LL_STATE_ACCEPTED_FINAL_MEMBER:
        if (PrintOnTextbox(&data->textState, gStringVar4))
            data->state = LL_STATE_WAIT_AND_CONFIRM_MEMBERS;
        break;
    case LL_STATE_WAIT_AND_CONFIRM_MEMBERS:
        if (++data->delayTimerAfterOk > 120)
            data->state = LL_STATE_CONFIRMED_MEMBERS;
        break;
    case LL_STATE_MEMBERS_OK_PROMPT:
        if (PrintOnTextbox(&data->textState, sText_AreTheseMembersOK))
            data->state = LL_STATE_MEMBERS_OK_PROMPT_HANDLE_INPUT;
        break;
    case LL_STATE_MEMBERS_OK_PROMPT_HANDLE_INPUT:
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0: // YES
            data->state = LL_STATE_CONFIRMED_MEMBERS;
            break;
        case 1: // NO
        case MENU_B_PRESSED:
            if (GROUP_MIN2(sPlayerActivityGroupSize) != 0)
                data->state = LL_STATE_CANCEL_WITH_MSG;
            else
                data->state = LL_STATE_CANCEL_PROMPT;
            break;
        }
        break;
    case LL_STATE_CANCEL_PROMPT:
        if (PrintOnTextbox(&data->textState, sText_CancelModeWithTheseMembers))
            data->state = LL_STATE_CANCEL_PROMPT_HANDLE_INPUT;
        break;
    case LL_STATE_CANCEL_PROMPT_HANDLE_INPUT:
        switch (UnionRoomHandleYesNo(&data->textState, FALSE))
        {
        case 0: // YES
            data->state = LL_STATE_SHUTDOWN_AND_FAIL;
            break;
        case 1: // NO
        case MENU_B_PRESSED:
            if (GROUP_MIN2(sPlayerActivityGroupSize) != 0)
                data->state = LL_STATE_MEMBERS_OK_PROMPT;
            else if (data->playerCount == GROUP_MAX(sPlayerActivityGroupSize))
                data->state = LL_STATE_MEMBERS_OK_PROMPT;
            else
                data->state = LL_STATE_GET_AWAITING_PLAYERS_TEXT;
            break;
        }
        break;
    case LL_STATE_CONFIRMED_MEMBERS:
        if (!Leader_SetStateIfMemberListChanged(data, LL_STATE_ACCEPT_NEW_MEMBER_PROMPT, LL_STATE_MEMBER_DISCONNECTED))
            data->state = LL_STATE_FINAL_MEMBER_CHECK;
        break;
    case LL_STATE_FINAL_MEMBER_CHECK:
        if (LmanAcceptSlotFlagIsNotZero())
        {
            if (WaitRfuState(FALSE))
            {
                data->state = LL_STATE_TRY_START_ACTIVITY;
            }
            else
            {
                if (++data->memberConfirmTimeout > 300)
                {
                    data->state = LL_STATE_MEMBER_DISCONNECTED;
                    data->textState = 0;
                }
            }
        }
        else
        {
            data->state = LL_STATE_MEMBER_DISCONNECTED;
            data->textState = 0;
        }
        break;
    case LL_STATE_CANCEL_WITH_MSG:
        if (PrintOnTextbox(&data->textState, sText_ModeWithTheseMembersWillBeCanceled))
            data->state = LL_STATE_SHUTDOWN_AND_FAIL;
        break;
    case LL_STATE_SHUTDOWN_AND_RETRY:
    case LL_STATE_SHUTDOWN_AND_FAIL:
        DestroyWirelessStatusIndicatorSprite();
        LinkRfu_Shutdown();
        Leader_DestroyResources(data);
        data->state++; // LL_STATE_RETRY or LL_STATE_FAILED
        break;
    case LL_STATE_FAILED:
        ScriptContext_Enable();
        DestroyTask(taskId);
        gSpecialVar_Result = LINKUP_FAILED;
        break;
    case LL_STATE_RETRY:
        ScriptContext_Enable();
        DestroyTask(taskId);
        gSpecialVar_Result = LINKUP_RETRY_ROLE_ASSIGN;
        break;
    case LL_STATE_TRY_START_ACTIVITY:
        if (RfuHasErrored())
        {
            data->state = LL_STATE_MEMBER_DISCONNECTED;
        }
        else
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (IsActivityWithVariableGroupSize(gPlayerCurrActivity))
                    GetOtherPlayersInfoFlags();
                UpdateGameData_GroupLockedIn(TRUE);
                CreateTask_RunScriptAndFadeToActivity();
                Leader_DestroyResources(data);
                DestroyTask(taskId);
            }
        }
        break;
    }
}

static void Leader_DestroyResources(struct WirelessLink_Leader *data)
{
    ClearWindowTilemap(data->nPlayerModeWindowId);
    ClearStdWindowAndFrame(data->nPlayerModeWindowId, FALSE);
    DestroyListMenuTask(data->listTaskId, 0, 0);
    ClearWindowTilemap(data->bButtonCancelWindowId);
    ClearStdWindowAndFrame(data->listWindowId, FALSE);
    CopyBgTilemapBufferToVram(0);
    RemoveWindow(data->nPlayerModeWindowId);
    RemoveWindow(data->listWindowId);
    RemoveWindow(data->bButtonCancelWindowId);
    DestroyTask(data->listenTaskId);

    Free(data->playerListBackup);
    Free(data->playerList);
    Free(data->incomingPlayerList);
}

void Leader_GetAcceptNewMemberPrompt(u8 *dst, u8 activity)
{
    switch (activity)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_TRADE:
    case ACTIVITY_BATTLE_TOWER_OPEN:
    case ACTIVITY_BATTLE_TOWER:
        StringExpandPlaceholders(dst, sText_PlayerContactedYouForXAccept);
        break;
    case ACTIVITY_WONDER_CARD_DUP:
    case ACTIVITY_WONDER_NEWS_DUP:
        StringExpandPlaceholders(dst, sText_PlayerContactedYouShareX);
        break;
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        StringExpandPlaceholders(dst, sText_PlayerContactedYouAddToMembers);
        break;
    }
}

void GetYouDeclinedTheOfferMessage(u8 *dst, u8 activity)
{
    switch (activity)
    {
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
    case ACTIVITY_TRADE | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_OfferDeclined1);
        break;
    case ACTIVITY_CHAT | IN_UNION_ROOM:
    case ACTIVITY_CARD | IN_UNION_ROOM:
        StringExpandPlaceholders(dst, sText_OfferDeclined2);
        break;
    }
}

void GetYouAskedToJoinGroupPleaseWaitMessage(u8 *dst, u8 activity)
{
    switch (activity)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_TRADE:
    case ACTIVITY_BATTLE_TOWER:
    case ACTIVITY_BATTLE_TOWER_OPEN:
    case ACTIVITY_WONDER_CARD_DUP:
    case ACTIVITY_WONDER_NEWS_DUP:
        StringExpandPlaceholders(dst, sText_AwaitingPlayersResponse);
        break;
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        StringExpandPlaceholders(dst, sText_PlayerHasBeenAskedToRegisterYouPleaseWait);
        break;
    }
}

void GetGroupLeaderSentAnOKMessage(u8 *dst, u8 activity)
{
    switch (activity)
    {
    case ACTIVITY_BATTLE_SINGLE:
    case ACTIVITY_BATTLE_DOUBLE:
    case ACTIVITY_TRADE:
    case ACTIVITY_BATTLE_TOWER:
    case ACTIVITY_BATTLE_TOWER_OPEN:
    case ACTIVITY_WONDER_CARD_DUP:
    case ACTIVITY_WONDER_NEWS_DUP:
        StringExpandPlaceholders(dst, sText_PlayerSentBackOK);
        break;
    case ACTIVITY_BATTLE_MULTI:
    case ACTIVITY_POKEMON_JUMP:
    case ACTIVITY_BERRY_CRUSH:
    case ACTIVITY_BERRY_PICK:
    case ACTIVITY_RECORD_CORNER:
    case ACTIVITY_BERRY_BLENDER:
    case ACTIVITY_CONTEST_COOL:
    case ACTIVITY_CONTEST_BEAUTY:
    case ACTIVITY_CONTEST_CUTE:
    case ACTIVITY_CONTEST_SMART:
    case ACTIVITY_CONTEST_TOUGH:
        StringExpandPlaceholders(dst, sText_PlayerOKdRegistration);
        break;
    }
}

bool8 Leader_SetStateIfMemberListChanged(struct WirelessLink_Leader *data, u32 joinedState, u32 droppedState)
{
    switch (LeaderUpdateGroupMembership(data->playerList))
    {
    case UNION_ROOM_SPAWN_IN:
        PlaySE(SE_PC_LOGIN);
        RedrawListMenu(data->listTaskId);
        StringCopy7(gStringVar2, &data->playerList->players[data->playerCount].rfu.name);
        Leader_GetAcceptNewMemberPrompt(gStringVar4, gPlayerCurrActivity);
        data->state = joinedState;
        break;
    case UNION_ROOM_SPAWN_OUT:
        RfuSetStatus(RFU_STATUS_OK, 0);
        RedrawListMenu(data->listTaskId);
        data->state = droppedState;
        return TRUE;
    }

    return FALSE;
}

static void ItemPrintFunc_PossibleGroupMembers(u8 windowId, u32 id, u8 y)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    u8 colorIdx = UR_COLOR_DEFAULT;

    switch (data->playerList->players[id].groupScheduledAnim)
    {
    case UNION_ROOM_SPAWN_IN:
        if (data->playerList->players[id].newPlayerCountdown != 0)
            colorIdx = UR_COLOR_GREEN;
        break;
    case UNION_ROOM_SPAWN_OUT:
        colorIdx = UR_COLOR_RED;
        break;
    }

    PrintGroupCandidateOnWindow(windowId, 1, y, &data->playerList->players[id], colorIdx, id);
}

u8 LeaderUpdateGroupMembership(struct RfuPlayerList *list)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    u8 ret = UNION_ROOM_SPAWN_NONE;
    u8 i;
    s32 id;

    for (i = 1; i < MAX_RFU_PLAYERS; i++)
    {
        u16 var = data->playerList->players[i].groupScheduledAnim;
        if (var == UNION_ROOM_SPAWN_IN)
        {
            id = GetNewIncomingPlayerId(&data->playerList->players[i], data->incomingPlayerList->players);
            if (id != 0xFF)
            {
                // New incoming player
                data->playerList->players[i].rfu = data->incomingPlayerList->players[id].rfu;
                data->playerList->players[i].timeoutCounter = 1;
            }
            else
            {
                // No new incoming player
                data->playerList->players[i].groupScheduledAnim = UNION_ROOM_SPAWN_OUT;
                ret = UNION_ROOM_SPAWN_OUT;
            }
        }
    }

    for (id = 0; id < RFU_CHILD_MAX; id++)
        TryAddIncomingPlayerToList(data->playerList->players, &data->incomingPlayerList->players[id], MAX_RFU_PLAYERS);

    if (ret != UNION_ROOM_SPAWN_OUT)
    {
        for (id = 0; id < MAX_RFU_PLAYERS; id++)
        {
            if (data->playerList->players[id].newPlayerCountdown != 0)
                ret = UNION_ROOM_SPAWN_IN;
        }
    }

    return ret;
}

u8 LeaderPrunePlayerList(struct RfuPlayerList *list)
{
    struct WirelessLink_Leader *data = sWirelessLinkMain.leader;
    u8 copiedCount;
    s32 i;
    u8 playerCount;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        data->playerListBackup->players[i] = data->playerList->players[i];

    copiedCount = 0;
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (data->playerListBackup->players[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
        {
            data->playerList->players[copiedCount] = data->playerListBackup->players[i];
            copiedCount++;
        }
    }

    playerCount = copiedCount;
    for (; copiedCount < MAX_RFU_PLAYERS; copiedCount++)
    {
        data->playerList->players[copiedCount].rfu = sUnionRoomPlayer_DummyRfu;
        data->playerList->players[copiedCount].timeoutCounter = 0;
        data->playerList->players[copiedCount].groupScheduledAnim = UNION_ROOM_SPAWN_NONE;
        data->playerList->players[copiedCount].useRedText = FALSE;
        data->playerList->players[copiedCount].newPlayerCountdown = 0;
    }

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (data->playerList->players[i].groupScheduledAnim != UNION_ROOM_SPAWN_IN)
            continue;
        if (data->playerList->players[i].newPlayerCountdown != 64)
            continue;

        playerCount = i;
        break;
    }

    return playerCount;
}

void TryJoinLinkGroup(void)
{
    u8 taskId;
    struct WirelessLink_Group *data;

    taskId = CreateTask(Task_TryJoinLinkGroup, 0);
    sWirelessLinkMain.group = data = (void *)(gTasks[taskId].data);
    sGroup = data;

    data->state = LG_STATE_INIT;
    data->textState = 0;
    gSpecialVar_Result = LINKUP_ONGOING;
}

static void Task_TryJoinLinkGroup(u8 taskId)
{
    s32 id;
    struct WirelessLink_Group *data = sWirelessLinkMain.group;

    switch (data->state)
    {
    case LG_STATE_INIT:
        if (gSpecialVar_0x8004 == LINK_GROUP_BATTLE_TOWER && gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_OPEN)
            gSpecialVar_0x8004++;
        gPlayerCurrActivity = sLinkGroupToURoomActivity[gSpecialVar_0x8004];
        SetHostRfuGameData(gPlayerCurrActivity, 0, FALSE);
        SetWirelessCommType1();
        OpenLink();
        InitializeRfuLinkManager_JoinGroup();
        data->incomingPlayerList = AllocZeroed(RFU_CHILD_MAX * sizeof(struct RfuIncomingPlayer));
        data->playerList = AllocZeroed(MAX_RFU_PLAYER_LIST_SIZE * sizeof(struct RfuPlayer));
        data->state = LG_STATE_CHOOSE_LEADER_MSG;
        break;
    case LG_STATE_CHOOSE_LEADER_MSG:
        if (PrintOnTextbox(&data->textState, sChooseTrainerTexts[gSpecialVar_0x8004]))
            data->state = LG_STATE_INIT_WINDOWS;
        break;
    case LG_STATE_INIT_WINDOWS:
        ClearIncomingPlayerList(data->incomingPlayerList, RFU_CHILD_MAX);
        ClearRfuPlayerList(data->playerList->players, MAX_RFU_PLAYER_LIST_SIZE);
        data->listenTaskId = CreateTask_ListenForCompatiblePartners(data->incomingPlayerList, gSpecialVar_0x8004);
        data->bButtonCancelWindowId = AddWindow(&sWindowTemplate_BButtonCancel);
        data->listWindowId = AddWindow(&sWindowTemplate_GroupList);
        data->playerNameAndIdWindowId = AddWindow(&sWindowTemplate_PlayerNameAndId);

        FillWindowPixelBuffer(data->bButtonCancelWindowId, PIXEL_FILL(2));
        PrintUnionRoomText(data->bButtonCancelWindowId, FONT_NORMAL, sText_ChooseJoinCancel, 8, 2, UR_COLOR_CANCEL);
        PutWindowTilemap(data->bButtonCancelWindowId);
        CopyWindowToVram(data->bButtonCancelWindowId, COPYWIN_GFX);

        DrawStdWindowFrame(data->listWindowId, FALSE);
        gMultiuseListMenuTemplate = sListMenuTemplate_UnionRoomGroups;
        gMultiuseListMenuTemplate.windowId = data->listWindowId;
        data->listTaskId = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);

        DrawStdWindowFrame(data->playerNameAndIdWindowId, FALSE);
        PutWindowTilemap(data->playerNameAndIdWindowId);
        PrintPlayerNameAndIdOnWindow(data->playerNameAndIdWindowId);
        CopyWindowToVram(data->playerNameAndIdWindowId, COPYWIN_GFX);

        CopyBgTilemapBufferToVram(0);
        data->leaderId = 0;
        data->state = LG_STATE_CHOOSE_LEADER_HANDLE_INPUT;
        break;
    case LG_STATE_CHOOSE_LEADER_HANDLE_INPUT:
        id = GetNewLeaderCandidate();
        switch (id)
        {
        case 1:
            PlaySE(SE_PC_LOGIN);
            RedrawListMenu(data->listTaskId);
            break;
        case 0:
            id = ListMenu_ProcessInput(data->listTaskId);
            if (JOY_NEW(A_BUTTON) && id != LIST_NOTHING_CHOSEN)
            {
                // Needed to match
                u32 UNUSED activity = data->playerList->players[id].rfu.data.activity;

                if (data->playerList->players[id].groupScheduledAnim == UNION_ROOM_SPAWN_IN && !data->playerList->players[id].rfu.data.startedActivity)
                {
                    u32 readyStatus = IsTryingToTradeAcrossVersionTooSoon(data, id);
                    if (readyStatus == UR_TRADE_READY)
                    {
                        // Trading is allowed, or not trading at all
                        AskToJoinRfuGroup(data, id);
                        data->state = LG_STATE_ASK_JOIN_GROUP;
                        PlaySE(SE_POKENAV_ON);
                    }
                    else
                    {
                        StringCopy(gStringVar4, sCantTransmitToTrainerTexts[readyStatus - 1]);
                        data->state = LG_STATE_TRADE_NOT_READY;
                        PlaySE(SE_POKENAV_ON);
                    }
                }
                else
                {
                    PlaySE(SE_WALL_HIT);
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                data->state = LG_STATE_CANCEL_CHOOSE_LEADER;
            }
            break;
        default:
            RedrawListMenu(data->listTaskId);
            break;
        }
        break;
    case LG_STATE_ASK_JOIN_GROUP:
        GetYouAskedToJoinGroupPleaseWaitMessage(gStringVar4, gPlayerCurrActivity);
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            StringCopy7(gStringVar1, &data->playerList->players[data->leaderId].rfu.name);
            data->state = LG_STATE_MAIN;
        }
        break;
    case LG_STATE_MAIN:
        if (gReceivedRemoteLinkPlayers)
        {
            gPlayerCurrActivity = data->playerList->players[data->leaderId].rfu.data.activity;
            RfuSetStatus(RFU_STATUS_OK, 0);
            switch (gPlayerCurrActivity)
            {
            case ACTIVITY_BATTLE_SINGLE:
            case ACTIVITY_BATTLE_DOUBLE:
            case ACTIVITY_BATTLE_MULTI:
            case ACTIVITY_TRADE:
            case ACTIVITY_CHAT:
            case ACTIVITY_POKEMON_JUMP:
            case ACTIVITY_BERRY_CRUSH:
            case ACTIVITY_BERRY_PICK:
            case ACTIVITY_SPIN_TRADE:
            case ACTIVITY_BATTLE_TOWER:
            case ACTIVITY_BATTLE_TOWER_OPEN:
            case ACTIVITY_RECORD_CORNER:
            case ACTIVITY_BERRY_BLENDER:
            case ACTIVITY_WONDER_CARD_DUP:
            case ACTIVITY_WONDER_NEWS_DUP:
            case ACTIVITY_CONTEST_COOL:
            case ACTIVITY_CONTEST_BEAUTY:
            case ACTIVITY_CONTEST_CUTE:
            case ACTIVITY_CONTEST_SMART:
            case ACTIVITY_CONTEST_TOUGH:
                data->state = LG_STATE_READY_START_ACTIVITY;
                return;
            }
        }

        switch (RfuGetStatus())
        {
        case RFU_STATUS_FATAL_ERROR:
            data->state = LG_STATE_RFU_ERROR;
            break;
        case RFU_STATUS_CONNECTION_ERROR:
        case RFU_STATUS_JOIN_GROUP_NO:
        case RFU_STATUS_LEAVE_GROUP:
            data->state = LG_STATE_DISCONNECTED;
            break;
        case RFU_STATUS_JOIN_GROUP_OK:
            GetGroupLeaderSentAnOKMessage(gStringVar4, gPlayerCurrActivity);
            if (PrintOnTextbox(&data->textState, gStringVar4))
            {
                if (gPlayerCurrActivity == ACTIVITY_BATTLE_TOWER || gPlayerCurrActivity == ACTIVITY_BATTLE_TOWER_OPEN)
                {
                    RfuSetStatus(RFU_STATUS_ACK_JOIN_GROUP, 0);
                }
                else
                {
                    RfuSetStatus(RFU_STATUS_WAIT_ACK_JOIN_GROUP, 0);
                    StringCopy(gStringVar1, sLinkGroupActivityNameTexts[gPlayerCurrActivity]);
                    StringExpandPlaceholders(gStringVar4, sText_AwaitingOtherMembers);
                }
            }
            break;
        case RFU_STATUS_WAIT_ACK_JOIN_GROUP:
            if (data->delayBeforePrint > 240)
            {
                if (PrintOnTextbox(&data->textState, gStringVar4))
                {
                    RfuSetStatus(RFU_STATUS_ACK_JOIN_GROUP, 0);
                    data->delayBeforePrint = 0;
                }
            }
            else
            {
                switch (gPlayerCurrActivity)
                {
                case ACTIVITY_BATTLE_SINGLE:
                case ACTIVITY_BATTLE_DOUBLE:
                case ACTIVITY_TRADE:
                case ACTIVITY_BATTLE_TOWER:
                case ACTIVITY_BATTLE_TOWER_OPEN:
                    break;
                default:
                    data->delayBeforePrint++;
                    break;
                }
            }
            break;
        }

        if (RfuGetStatus() == RFU_STATUS_OK && JOY_NEW(B_BUTTON))
            data->state = LG_STATE_ASK_LEAVE_GROUP;
        break;
    case LG_STATE_ASK_LEAVE_GROUP:
        if (PrintOnTextbox(&data->textState, sText_QuitBeingMember))
            data->state = LG_STATE_ASK_LEAVE_GROUP_HANDLE_INPUT;
        break;
    case LG_STATE_ASK_LEAVE_GROUP_HANDLE_INPUT:
        switch (UnionRoomHandleYesNo(&data->textState, RfuGetStatus()))
        {
        case 0: // YES
            SendLeaveGroupNotice();
            data->state = LG_STATE_WAIT_LEAVE_GROUP;
            RedrawListMenu(data->listTaskId);
            break;
        case 1: // NO
        case MENU_B_PRESSED:
            data->state = LG_STATE_ASK_JOIN_GROUP;
            RedrawListMenu(data->listTaskId);
            break;
        case -3:
            data->state = LG_STATE_MAIN;
            RedrawListMenu(data->listTaskId);
            break;
        }
        break;
    case LG_STATE_WAIT_LEAVE_GROUP:
        if (RfuGetStatus())
            data->state = LG_STATE_MAIN;
        break;
    case LG_STATE_CANCEL_CHOOSE_LEADER: // next: LG_STATE_CANCELED
    case LG_STATE_RFU_ERROR:            // next: LG_STATE_RFU_ERROR_SHUTDOWN
    case LG_STATE_DISCONNECTED:         // next: LG_STATE_RETRY_CONNECTION
    case LG_STATE_TRADE_NOT_READY:      // next: LG_STATE_TRADE_NOT_READY_RETRY
    case LG_STATE_READY_START_ACTIVITY: // next: LG_STATE_START_ACTIVITY
        ClearWindowTilemap(data->playerNameAndIdWindowId);
        ClearStdWindowAndFrame(data->playerNameAndIdWindowId, FALSE);
        DestroyListMenuTask(data->listTaskId, 0, 0);
        ClearWindowTilemap(data->bButtonCancelWindowId);
        ClearStdWindowAndFrame(data->listWindowId, FALSE);
        CopyBgTilemapBufferToVram(0);
        RemoveWindow(data->playerNameAndIdWindowId);
        RemoveWindow(data->listWindowId);
        RemoveWindow(data->bButtonCancelWindowId);
        DestroyTask(data->listenTaskId);
        Free(data->playerList);
        Free(data->incomingPlayerList);
        data->state++;
        break;
    case LG_STATE_RFU_ERROR_SHUTDOWN:
        DestroyWirelessStatusIndicatorSprite();
        if (PrintOnTextbox(&data->textState, sPlayerDisconnectedTexts[RfuGetStatus()]))
        {
            gSpecialVar_Result = LINKUP_CONNECTION_ERROR;
            data->state = LG_STATE_SHUTDOWN;
        }
        break;
    case LG_STATE_CANCELED:
        DestroyWirelessStatusIndicatorSprite();
        gSpecialVar_Result = LINKUP_FAILED;
        data->state = LG_STATE_SHUTDOWN;
        break;
    case LG_STATE_RETRY_CONNECTION:
        // Failure from disconnection
        // Happens if player or required member(s) leave group
        // or if player is rejected from joining group
        DestroyWirelessStatusIndicatorSprite();
        if (PrintOnTextbox(&data->textState, sPlayerDisconnectedTexts[RfuGetStatus()]))
        {
            gSpecialVar_Result = LINKUP_RETRY_ROLE_ASSIGN;
            data->state = LG_STATE_SHUTDOWN;
        }
        break;
    case LG_STATE_TRADE_NOT_READY_RETRY:
        if (PrintOnTextbox(&data->textState, gStringVar4))
        {
            gSpecialVar_Result = LINKUP_RETRY_ROLE_ASSIGN;
            data->state = LG_STATE_SHUTDOWN;
        }
        break;
    case LG_STATE_SHUTDOWN:
        DestroyTask(taskId);
        JoinGroup_EnableScriptContexts();
        LinkRfu_Shutdown();
        break;
    case LG_STATE_START_ACTIVITY:
        CreateTask_RunScriptAndFadeToActivity();
        DestroyTask(taskId);
        break;
    }
}

static u32 IsTryingToTradeAcrossVersionTooSoon(struct WirelessLink_Group *data, s32 id)
{
    struct RfuPlayer *partner = &data->playerList->players[id];

    if (gPlayerCurrActivity == ACTIVITY_TRADE && partner->rfu.data.compatibility.version != VERSION_EMERALD)
    {
        if (!(gSaveBlock2Ptr->specialSaveWarpFlags & CHAMPION_SAVEWARP))
            return UR_TRADE_PLAYER_NOT_READY;
        else if (partner->rfu.data.compatibility.canLinkNationally)
            return UR_TRADE_READY;
    }
    else
    {
        return UR_TRADE_READY;
    }

    return UR_TRADE_PARTNER_NOT_READY;
}

static void AskToJoinRfuGroup(struct WirelessLink_Group *data, s32 id)
{
    data->leaderId = id;
    LoadWirelessStatusIndicatorSpriteGfx();
    CreateWirelessStatusIndicatorSprite(0, 0);
    RedrawListMenu(data->listTaskId);
    StringCopy7(gStringVar1, &data->playerList->players[data->leaderId].rfu.name);
    UpdateGameData_SetActivity(sLinkGroupToURoomActivity[gSpecialVar_0x8004], 0, TRUE);
    CreateTask_RfuReconnectWithParent(data->playerList->players[data->leaderId].rfu.name, ReadAsU16(data->playerList->players[data->leaderId].rfu.data.compatibility.playerTrainerId));
}

u8 CreateTask_ListenToWireless(void)
{
    u8 taskId;
    struct WirelessLink_Group *data;

    taskId = CreateTask(Task_ListenToWireless, 0);
    sWirelessLinkMain.group = data = (void *)(gTasks[taskId].data);

    data->state = 0;
    data->textState = 0;

    sGroup = data;

    return taskId;
}
