#include "global.h"
#include "cable_club.h"
#include "event_data.h"
#include "link.h"
#include "link_rfu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "union_room.h"
#include "window.h"

#define LINK_GROUP_CAPACITY(min, max) (((min) << 12) | ((max) << 8))

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

// JP: RAM data bound via sym_*_jp.txt (JP uses fixed IWRAM/EWRAM addresses
// instead of US COMMON_DATA / EWRAM_DATA definitions).
extern EWRAM_DATA u8 gPlayerCurrActivity;
extern EWRAM_DATA union
{
    struct WirelessLink_Leader *leader;
    struct WirelessLink_Group *group;
    struct WirelessLink_URoom *uRoom;
} sWirelessLinkMain;
extern IWRAM_DATA struct WirelessLink_Leader *sLeader;

// JP: ROM data bound via ld_script_jp.txt.
extern const u8 *const sPlayersNeededOrModeTexts[][5];
extern const u8 sText_ID[];
extern const u8 sText_AwaitingCommunication[];

// JP: these helpers are still in asm/union_room.s; referenced by their sub_
// names until converted.
extern void PrintUnionRoomText(u8 windowId, u8 fontId, const u8 *str, u8 x, u8 y, u8 colorIdx);
extern u16 ReadAsU16(const u8 *ptr);

static void Task_TryBecomeLinkLeader(u8 taskId);

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
