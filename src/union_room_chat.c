#include "global.h"
#include "malloc.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "union_room_chat.h"
#include "constants/characters.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define MAX_MESSAGE_LENGTH 15

enum {
    CHAT_FUNC_JOIN,
    CHAT_FUNC_HANDLE_INPUT,
    CHAT_FUNC_SWITCH,
    CHAT_FUNC_ASK_QUIT,
    CHAT_FUNC_SEND,
    CHAT_FUNC_REGISTER,
    CHAT_FUNC_EXIT,
    CHAT_FUNC_DROP,
    CHAT_FUNC_DISBANDED,
    CHAT_FUNC_SAVE_AND_EXIT,
};

enum {
    CHAT_EXIT_NONE,
    CHAT_EXIT_ONLY_LEADER,
    CHAT_EXIT_DROPPED,
    CHAT_EXIT_DISBANDED,
};

enum {
    CHATDISPLAY_FUNC_LOAD_GFX,
    CHATDISPLAY_FUNC_MOVE_KB_CURSOR,
    CHATDISPLAY_FUNC_CURSOR_BLINK,
    CHATDISPLAY_FUNC_SHOW_KB_SWAP_MENU,
    CHATDISPLAY_FUNC_HIDE_KB_SWAP_MENU,
    CHATDISPLAY_FUNC_SWITCH_PAGES,
    CHATDISPLAY_FUNC_ASK_QUIT_CHATTING,
    CHATDISPLAY_FUNC_DESTROY_YESNO,
    CHATDISPLAY_FUNC_UPDATE_MSG,
    CHATDISPLAY_FUNC_ASK_REGISTER_TEXT,
    CHATDISPLAY_FUNC_CANCEL_REGISTER,
    CHATDISPLAY_FUNC_RETURN_TO_KB,
    CHATDISPLAY_FUNC_SCROLL_CHAT,
    CHATDISPLAY_FUNC_PRINT_INPUT_TEXT,
    CHATDISPLAY_FUNC_ASK_SAVE,
    CHATDISPLAY_FUNC_ASK_OVERWRITE_SAVE,
    CHATDISPLAY_FUNC_PRINT_SAVING,
    CHATDISPLAY_FUNC_PRINT_SAVED_GAME,
    CHATDISPLAY_FUNC_PRINT_EXITING_CHAT,
    CHATDISPLAY_FUNC_PRINT_LEADER_LEFT,
    CHATDISPLAY_FUNC_ASK_CONFIRM_LEADER_LEAVE,
};

// JP keyboard page indices. The register page is page 4; pages 0-2 are the
// text keyboards and the swap menu offers up to five choices.
#define UNION_ROOM_KB_PAGE_REGISTER 4

struct UnionRoomChat
{
    u32 filler1;
    u16 funcId;
    u16 funcState;
    u16 filler2;
    u16 exitDelayTimer;
    u8 filler3;
    u8 linkPlayerCount;
    u8 handleInputTask;
    u8 receiveMessagesTask;
    u8 currentPage;
    u8 currentCol;
    u8 currentRow;
    u8 multiplayerId;
    u8 lastBufferCursorPos;
    u8 bufferCursorPos;
    u8 receivedPlayerIndex;
    u8 exitType; // CHAT_EXIT_*
    bool8 changedRegisteredTexts;
    u8 afterSaveTimer;
    u8 messageEntryBuffer[2 * MAX_MESSAGE_LENGTH + 1];
    u8 receivedMessage[64];
    u8 hostName[64];
    u8 registeredTexts[UNION_ROOM_KB_ROW_COUNT][21];
    u8 filler4[5];
    u8 sendMessageBuffer[40];
    u16 tryQuitAgainTimer;
    u16 filler5;
};

// Chat main function table (0x082C5064, in data/data_b.s).
extern void (*const gUnknown_82C5064[])(void);

// Chat state, EWRAM 0x02022938 (see sym_ewram_jp.txt).
extern EWRAM_DATA struct UnionRoomChat *sChat;

extern void PrepareSendBuffer_Join(u8 *buffer);
extern void PrepareSendBuffer_Null(u8 *buffer);
extern void SetChatFunction(u16 funcId);
extern bool8 TryAllocDisplay(void);
extern void RunDisplaySubtasks(void);
extern bool32 IsDisplaySubtask0Active(void);
extern void Task_ReceiveChatMessage(u8 taskId);
extern void DeleteLastMessageCharacter(void);
extern void AppendTextToMessage(void);
extern void SwitchCaseOfLastMessageCharacter(void);
extern bool32 HandleDPadInput(void);
extern void StartDisplaySubtask(u16 subtaskId, u8 assignId);
extern bool8 IsDisplaySubtaskActive(u8 id);
extern s8 ProcessMenuInput(void);
extern void PrepareSendBuffer_Disband(u8 *buffer);
extern void PrepareSendBuffer_Leave(u8 *buffer);

static void InitUnionRoomChat(struct UnionRoomChat *);
static void CB2_LoadInterface(void);
static void VBlankCB_UnionRoomChatMain(void);
static void CB2_UnionRoomChatMain(void);
static void Task_HandlePlayerInput(u8 taskId);
static void Chat_Join(void);
static void Chat_HandleInput(void);
static void Chat_Switch(void);
static void Chat_AskQuitChatting(void);

void EnterUnionRoomChat(void)
{
    sChat = Alloc(sizeof(*sChat));
    InitUnionRoomChat(sChat);
    gKeyRepeatStartDelay = 20;
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_LoadInterface);
}

static void InitUnionRoomChat(struct UnionRoomChat *chat)
{
    int i;

    chat->funcId = CHAT_FUNC_JOIN;
    chat->funcState = 0;
    chat->currentPage = 0;
    chat->currentCol = 0;
    chat->currentRow = 0;
    chat->lastBufferCursorPos = 0;
    chat->bufferCursorPos = 0;
    chat->receivedPlayerIndex = 0;
    chat->messageEntryBuffer[0] = EOS;
    chat->linkPlayerCount = GetLinkPlayerCount();
    chat->multiplayerId = GetMultiplayerId();
    chat->exitType = CHAT_EXIT_NONE;
    chat->changedRegisteredTexts = FALSE;
    PrepareSendBuffer_Null(chat->sendMessageBuffer);
    for (i = 0; i < UNION_ROOM_KB_ROW_COUNT; i++)
        StringCopy(chat->registeredTexts[i], gSaveBlock1Ptr->registeredTexts[i]);
}

// Non-static so the still-asm functions can reach it via the
// `sub_0801DC54 = FreeUnionRoomChat` ld alias.
void FreeUnionRoomChat(void)
{
    DestroyTask(sChat->handleInputTask);
    DestroyTask(sChat->receiveMessagesTask);
    Free(sChat);
}

static void CB2_LoadInterface(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        TryAllocDisplay();
        gMain.state++;
        break;
    case 1:
        RunDisplaySubtasks();
        if (!IsDisplaySubtask0Active())
        {
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
            SetVBlankCallback(VBlankCB_UnionRoomChatMain);
            gMain.state++;
        }
        break;
    case 2:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_UnionRoomChatMain);
            sChat->handleInputTask = CreateTask(Task_HandlePlayerInput, 8);
            sChat->receiveMessagesTask = CreateTask(Task_ReceiveChatMessage, 7);
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(DISPLAY_WIDTH - 8, DISPLAY_HEIGHT - 10);
        }
        break;
    }
}

static void VBlankCB_UnionRoomChatMain(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void CB2_UnionRoomChatMain(void)
{
    RunTasks();
    RunDisplaySubtasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_HandlePlayerInput(u8 taskId)
{
    // If exitType is not CHAT_EXIT_NONE, begin exit function.
    // Otherwise just call main function below.
    switch (sChat->exitType)
    {
    case CHAT_EXIT_ONLY_LEADER:
        SetChatFunction(CHAT_FUNC_EXIT);
        sChat->exitType = CHAT_EXIT_NONE;
        break;
    case CHAT_EXIT_DROPPED:
        SetChatFunction(CHAT_FUNC_DROP);
        sChat->exitType = CHAT_EXIT_NONE;
        break;
    case CHAT_EXIT_DISBANDED:
        SetChatFunction(CHAT_FUNC_DISBANDED);
        sChat->exitType = CHAT_EXIT_NONE;
        break;
    }

    gUnknown_82C5064[sChat->funcId]();
}

static void Chat_Join(void)
{
    switch (sChat->funcState)
    {
    case 0:
        PrepareSendBuffer_Join(sChat->sendMessageBuffer);
        sChat->funcState++;
        // fall through
    case 1:
        if (IsLinkTaskFinished() && !Rfu_IsPlayerExchangeActive())
        {
            if (SendBlock(0, sChat->sendMessageBuffer, sizeof(sChat->sendMessageBuffer)))
                sChat->funcState++;
        }
        break;
    case 2:
        if (IsLinkTaskFinished())
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    }
}

static void Chat_HandleInput(void)
{
    bool8 updateMsgActive, cursorBlinkActive;

    switch (sChat->funcState)
    {
    case 0:
        if (JOY_NEW(START_BUTTON))
        {
            if (sChat->bufferCursorPos)
                SetChatFunction(CHAT_FUNC_SEND);
        }
        else if (JOY_NEW(SELECT_BUTTON))
        {
            SetChatFunction(CHAT_FUNC_SWITCH);
        }
        else if (JOY_REPEAT(B_BUTTON))
        {
            if (sChat->bufferCursorPos)
            {
                DeleteLastMessageCharacter();
                StartDisplaySubtask(CHATDISPLAY_FUNC_UPDATE_MSG, 0);
                sChat->funcState = 1;
            }
            else
            {
                SetChatFunction(CHAT_FUNC_ASK_QUIT);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            AppendTextToMessage();
            StartDisplaySubtask(CHATDISPLAY_FUNC_UPDATE_MSG, 0);
            StartDisplaySubtask(CHATDISPLAY_FUNC_CURSOR_BLINK, 1);
            sChat->funcState = 1;
        }
        else if (JOY_NEW(R_BUTTON))
        {
            if (sChat->currentPage != UNION_ROOM_KB_PAGE_REGISTER)
            {
                SwitchCaseOfLastMessageCharacter();
                StartDisplaySubtask(CHATDISPLAY_FUNC_UPDATE_MSG, 0);
                sChat->funcState = 1;
            }
            else
            {
                SetChatFunction(CHAT_FUNC_REGISTER);
            }
        }
        else if (HandleDPadInput())
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_MOVE_KB_CURSOR, 0);
            sChat->funcState = 1;
        }
        break;
    case 1:
        updateMsgActive = IsDisplaySubtaskActive(0);
        cursorBlinkActive = IsDisplaySubtaskActive(1);
        if (!updateMsgActive && !cursorBlinkActive)
            sChat->funcState = 0;
        break;
    }
}

static void Chat_Switch(void)
{
    s16 input;
    bool32 shouldSwitchPages;

    switch (sChat->funcState)
    {
    case 0:
        StartDisplaySubtask(CHATDISPLAY_FUNC_SHOW_KB_SWAP_MENU, 0);
        sChat->funcState++;
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState++;
        break;
    case 2:
        input = Menu_ProcessInput();
        switch (input)
        {
        default:
            StartDisplaySubtask(CHATDISPLAY_FUNC_HIDE_KB_SWAP_MENU, 0);
            shouldSwitchPages = TRUE;
            // The JP swap menu does not allow switching to the 5th page.
            if (sChat->currentPage == input || input == 5)
                shouldSwitchPages = FALSE;
            break;
        case MENU_NOTHING_CHOSEN:
            if (JOY_NEW(SELECT_BUTTON))
            {
                PlaySE(SE_SELECT);
                Menu_MoveCursor(1);
            }
            return;
        case MENU_B_PRESSED:
            StartDisplaySubtask(CHATDISPLAY_FUNC_HIDE_KB_SWAP_MENU, 0);
            sChat->funcState = 3;
            return;
        }

        if (!shouldSwitchPages)
        {
            sChat->funcState = 3;
            return;
        }

        sChat->currentCol = 0;
        sChat->currentRow = 0;
        StartDisplaySubtask(CHATDISPLAY_FUNC_SWITCH_PAGES, 1);
        sChat->currentPage = input;
        sChat->funcState = 4;
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    case 4:
        if (!IsDisplaySubtaskActive(0) && !IsDisplaySubtaskActive(1))
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    }
}

static void Chat_AskQuitChatting(void)
{
    s8 input;

    switch (sChat->funcState)
    {
    case 0:
        StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_QUIT_CHATTING, 0);
        sChat->funcState = 1;
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 2;
        break;
    case 2:
        input = ProcessMenuInput();
        switch (input)
        {
        case MENU_B_PRESSED:
        case 1:
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 3;
            break;
        case 0:
            if (sChat->multiplayerId == 0)
            {
                PrepareSendBuffer_Disband(sChat->sendMessageBuffer);
                StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
                sChat->funcState = 9;
            }
            else
            {
                PrepareSendBuffer_Leave(sChat->sendMessageBuffer);
                sChat->funcState = 4;
            }
            break;
        }
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    case 9:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_CONFIRM_LEADER_LEAVE, 0);
            sChat->funcState = 10;
        }
        break;
    case 10:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 8;
        break;
    case 8:
        input = ProcessMenuInput();
        switch (input)
        {
        case MENU_B_PRESSED:
        case 1:
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 3;
            break;
        case 0:
            Rfu_StopPartnerSearch();
            PrepareSendBuffer_Disband(sChat->sendMessageBuffer);
            sChat->funcState = 4;
            sChat->tryQuitAgainTimer = 0;
            break;
        }
        break;
    case 4:
        if (IsLinkTaskFinished() && !Rfu_IsPlayerExchangeActive() && SendBlock(0, sChat->sendMessageBuffer, sizeof(sChat->sendMessageBuffer)))
        {
            if (!sChat->multiplayerId)
                sChat->funcState = 6;
            else
                sChat->funcState = 5;
        }

        if (!gReceivedRemoteLinkPlayers)
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        break;
    case 5:
        if (!gReceivedRemoteLinkPlayers)
        {
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        }
        else if (++sChat->tryQuitAgainTimer > 300)
        {
            sChat->tryQuitAgainTimer = 0;
            sChat->funcState = 4;
        }
        break;
    }
}
