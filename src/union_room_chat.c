#include "global.h"
#include "dynamic_placeholder_text_util.h"
#include "malloc.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "save.h"
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

// JP keyboard max row per page (0x082C508C, in data/data_b.s): {9, 9, 7, 9, 9}
extern const u8 gUnknown_82C508C[];
#define sKeyboardPageMaxRow gUnknown_82C508C

// JP kana case-toggle table (0x082C5091, in data/data_b.s, 0xEF bytes).
extern const u8 gUnknown_82C5091[];
#define sCaseToggleTable gUnknown_82C5091

// JP keyboard text pointer table (0x082C5180, in data/data_b.s),
// [page][row] with 4 pages x 10 rows of u8 pointers.
extern const u8 *const gUnknown_82C5180[][UNION_ROOM_KB_ROW_COUNT];
#define sUnionRoomKeyboardText gUnknown_82C5180

enum {
    CHAT_MESSAGE_NONE,
    CHAT_MESSAGE_CHAT,
    CHAT_MESSAGE_JOIN,
    CHAT_MESSAGE_LEAVE,
    CHAT_MESSAGE_DROP,
    CHAT_MESSAGE_DISBAND,
};

// Chat state, EWRAM 0x02022938 (see sym_ewram_jp.txt).
extern EWRAM_DATA struct UnionRoomChat *sChat;

extern void SetChatFunction(u16 funcId);
extern bool8 TryAllocDisplay(void);
extern void RunDisplaySubtasks(void);
extern bool32 IsDisplaySubtask0Active(void);
extern void Task_ReceiveChatMessage(u8 taskId);
extern void StartDisplaySubtask(u16 subtaskId, u8 assignId);
extern bool8 IsDisplaySubtaskActive(u8 id);
extern s8 ProcessMenuInput(void);
extern void FreeDisplay(void);

// JP chat message templates (0x085CC663 / 0x085CC672).
extern const u8 gUnknown_85CC663[];
extern const u8 gUnknown_85CC672[];

// JP default registered chat texts (0x085CC769+).
extern const u8 gUnknown_85CC769[];
extern const u8 gUnknown_85CC76F[];
extern const u8 gUnknown_85CC774[];
extern const u8 gUnknown_85CC779[];
extern const u8 gUnknown_85CC77E[];
extern const u8 gUnknown_85CC783[];
extern const u8 gUnknown_85CC787[];
extern const u8 gUnknown_85CC78C[];
extern const u8 gUnknown_85CC792[];
extern const u8 gUnknown_85CC798[];

u8 *GetRegisteredTextByRow(int row);
u8 *GetLastCharOfMessagePtr(void);
u16 GetNumOverflowCharsInMessage(void);
static u8 *GetEndOfMessagePtr(void);
bool32 ProcessReceivedChatMessage(u8 *dest, u8 *recvMessage);
u8 GetCurrentKeyboardPage(void);
void GetCurrentKeyboardColAndRow(u8 *col, u8 *row);
u8 *GetMessageEntryBuffer(void);
int GetLengthOfMessageEntry(void);
void GetBufferSelectionRegion(u32 *x, u32 *width);
u8 *GetLimitedMessageStartPtr(void);
u32 GetLimitedMessageStartPos(void);
u8 *GetLastReceivedMessage(void);
u8 GetReceivedPlayerIndex(void);
u8 GetTextEntryCursorPosition(void);
u8 *GetChatHostName(void);

static void InitUnionRoomChat(struct UnionRoomChat *);
static void CB2_LoadInterface(void);
static void VBlankCB_UnionRoomChatMain(void);
static void CB2_UnionRoomChatMain(void);
static void Task_HandlePlayerInput(u8 taskId);
static void Chat_Join(void);
static void Chat_HandleInput(void);
static void Chat_Switch(void);
static void Chat_AskQuitChatting(void);
static void Chat_Exit(void);
static void Chat_Drop(void);
static void Chat_Disbanded(void);
static void Chat_SendMessage(void);
static void Chat_Register(void);
static void Chat_SaveAndExit(void);
void SetChatFunction(u16 funcId);
static bool32 HandleDPadInput(void);

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

static void Chat_Exit(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (!FuncIsActiveTask(Task_ReceiveChatMessage))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState++;
        }
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_EXITING_CHAT, 0);
            sChat->funcState++;
        }
        break;
    case 2:
        if (!IsDisplaySubtaskActive(0))
        {
            PrepareSendBuffer_Drop(sChat->sendMessageBuffer);
            sChat->funcState++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished() && !Rfu_IsPlayerExchangeActive() && SendBlock(0, sChat->sendMessageBuffer, sizeof(sChat->sendMessageBuffer)))
            sChat->funcState++;
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 1) && !Rfu_IsPlayerExchangeActive())
            sChat->funcState++;
        break;
    case 5:
        if (IsLinkTaskFinished() && !Rfu_IsPlayerExchangeActive())
        {
            SetCloseLinkCallback();
            sChat->exitDelayTimer = 0;
            sChat->funcState++;
        }
        break;
    case 6:
        if (sChat->exitDelayTimer <= 0x95)
            sChat->exitDelayTimer++;

        if (!gReceivedRemoteLinkPlayers)
            sChat->funcState++;
        break;
    case 7:
        if (sChat->exitDelayTimer > 0x95)
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        else
            sChat->exitDelayTimer++;
        break;
    }
}

static void Chat_Drop(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (!FuncIsActiveTask(Task_ReceiveChatMessage))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState++;
        }
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0) && IsLinkTaskFinished() && !Rfu_IsPlayerExchangeActive())
        {
            SetCloseLinkCallback();
            sChat->exitDelayTimer = 0;
            sChat->funcState++;
        }
        break;
    case 2:
        if (sChat->exitDelayTimer <= 0x95)
            sChat->exitDelayTimer++;

        if (!gReceivedRemoteLinkPlayers)
            sChat->funcState++;
        break;
    case 3:
        if (sChat->exitDelayTimer > 0x95)
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        else
            sChat->exitDelayTimer++;
        break;
    }
}

static void Chat_Disbanded(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (!FuncIsActiveTask(Task_ReceiveChatMessage))
        {
            if (sChat->multiplayerId)
                StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);

            sChat->funcState++;
        }
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
        {
            if (sChat->multiplayerId)
                StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_LEADER_LEFT, 0);

            sChat->funcState++;
        }
        break;
    case 2:
        if (IsDisplaySubtaskActive(0) != TRUE && IsLinkTaskFinished() && !Rfu_IsPlayerExchangeActive())
        {
            SetCloseLinkCallback();
            sChat->exitDelayTimer = 0;
            sChat->funcState++;
        }
        break;
    case 3:
        if (sChat->exitDelayTimer <= 0x95)
            sChat->exitDelayTimer++;

        if (!gReceivedRemoteLinkPlayers)
            sChat->funcState++;
        break;
    case 4:
        if (sChat->exitDelayTimer > 0x95)
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        else
            sChat->exitDelayTimer++;
        break;
    }
}

static void Chat_SendMessage(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (!gReceivedRemoteLinkPlayers)
        {
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
            break;
        }

        PrepareSendBuffer_Chat(sChat->sendMessageBuffer);
        sChat->funcState++;
        // fall through
    case 1:
        if (IsLinkTaskFinished() == TRUE && !Rfu_IsPlayerExchangeActive() && SendBlock(0, sChat->sendMessageBuffer, sizeof(sChat->sendMessageBuffer)))
            sChat->funcState++;
        break;
    case 2:
        ResetMessageEntryBuffer();
        StartDisplaySubtask(CHATDISPLAY_FUNC_UPDATE_MSG, 0);
        sChat->funcState++;
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState++;
        break;
    case 4:
        if (IsLinkTaskFinished())
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    }
}

static void Chat_Register(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (ChatMessageIsNotEmpty())
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_REGISTER_TEXT, 0);
            sChat->funcState = 2;
        }
        else
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_INPUT_TEXT, 0);
            sChat->funcState = 5;
        }
        break;
    case 1:
        if (JOY_NEW(A_BUTTON))
        {
            RegisterTextAtRow();
            StartDisplaySubtask(CHATDISPLAY_FUNC_RETURN_TO_KB, 0);
            sChat->funcState = 3;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_CANCEL_REGISTER, 0);
            sChat->funcState = 4;
        }
        else if (HandleDPadInput())
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_MOVE_KB_CURSOR, 0);
            sChat->funcState = 2;
        }
        break;
    case 2:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 1;
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_CANCEL_REGISTER, 0);
            sChat->funcState = 4;
        }
        break;
    case 4:
        if (!IsDisplaySubtaskActive(0))
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    case 5:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 6;
        break;
    case 6:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 4;
        }
        break;
    }
}

static void Chat_SaveAndExit(void)
{
    s8 input;

    switch (sChat->funcState)
    {
    case 0:
        if (!sChat->changedRegisteredTexts)
        {
            sChat->funcState = 12;
        }
        else
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 1;
        }
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_SAVE, 0);
            sChat->funcState = 2;
        }
        break;
    case 2:
        input = ProcessMenuInput();
        switch (input)
        {
        case MENU_B_PRESSED:
        case 1:
            sChat->funcState = 12;
            break;
        case 0:
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 3;
            break;
        }
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_OVERWRITE_SAVE, 0);
            sChat->funcState = 4;
        }
        break;
    case 4:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 5;
        break;
    case 5:
        input = ProcessMenuInput();
        switch (input)
        {
        case MENU_B_PRESSED:
        case 1:
            sChat->funcState = 12;
            break;
        case 0:
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 6;
            break;
        }
        break;
    case 6:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_SAVING, 0);
            SaveRegisteredTexts();
            sChat->funcState = 7;
        }
        break;
    case 7:
        if (!IsDisplaySubtaskActive(0))
        {
            SetContinueGameWarpStatusToDynamicWarp();
            TrySavingData(SAVE_NORMAL);
            sChat->funcState = 8;
        }
        break;
    case 8:
        StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_SAVED_GAME, 0);
        sChat->funcState = 9;
        break;
    case 9:
        if (!IsDisplaySubtaskActive(0))
        {
            PlaySE(SE_SAVE);
            ClearContinueGameWarpStatus();
            sChat->funcState = 10;
        }
        break;
    case 10:
        sChat->afterSaveTimer = 0;
        sChat->funcState = 11;
        break;
    case 11:
        sChat->afterSaveTimer++;
        if (sChat->afterSaveTimer > 120)
            sChat->funcState = 12;
        break;
    case 12:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
        sChat->funcState = 13;
        break;
    case 13:
        if (!gPaletteFade.active)
        {
            FreeDisplay();
            FreeUnionRoomChat();
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    }
}

// Non-static so the still-asm functions can reach it via the
// `sub_0801E9F8 = SetChatFunction` ld alias.
void SetChatFunction(u16 funcId)
{
    sChat->funcId = funcId;
    sChat->funcState = 0;
}

static bool32 HandleDPadInput(void)
{
    do
    {
        if (JOY_REPEAT(DPAD_UP))
        {
            if (sChat->currentRow > 0)
                sChat->currentRow--;
            else
                sChat->currentRow = sKeyboardPageMaxRow[sChat->currentPage];
            break;
        }
        if (JOY_REPEAT(DPAD_DOWN))
        {
            if (sChat->currentRow < sKeyboardPageMaxRow[sChat->currentPage])
                sChat->currentRow++;
            else
                sChat->currentRow = 0;
            break;
        }
        if (sChat->currentPage != UNION_ROOM_KB_PAGE_REGISTER)
        {
            if (JOY_REPEAT(DPAD_LEFT))
            {
                if (sChat->currentCol > 0)
                    sChat->currentCol--;
                else
                    sChat->currentCol = 4;
                break;
            }
            else if (JOY_REPEAT(DPAD_RIGHT))
            {
                if (sChat->currentCol < 4)
                    sChat->currentCol++;
                else
                    sChat->currentCol = 0;
                break;
            }
        }
        return FALSE;
    } while (0);

    return TRUE;
}

static void AppendTextToMessage(void)
{
    int i;
    const u8 *charsStr;
    int strLength;
    u8 *str;

    if (sChat->currentPage != UNION_ROOM_KB_PAGE_REGISTER)
    {
        // Going to append a single character
        charsStr = sUnionRoomKeyboardText[sChat->currentPage][sChat->currentRow];
        for (i = 0; i < sChat->currentCol; i++)
        {
            if (*charsStr == CHAR_EXTRA_SYMBOL)
                charsStr++;
            charsStr++;
        }

        strLength = 1;
    }
    else
    {
        // Going to append the registered text string (JP appends it as-is)
        charsStr = sChat->registeredTexts[sChat->currentRow];
        strLength = StringLength_Multibyte(charsStr);
    }

    sChat->lastBufferCursorPos = sChat->bufferCursorPos;
    if (!charsStr)
        return;

    str = GetEndOfMessagePtr();
    while (--strLength != -1 && sChat->bufferCursorPos < MAX_MESSAGE_LENGTH)
    {
        if (*charsStr == CHAR_EXTRA_SYMBOL)
        {
            *str = *charsStr;
            charsStr++;
            str++;
        }

        *str = *charsStr;
        charsStr++;
        str++;

        sChat->bufferCursorPos++;
    }

    *str = EOS;
}

static void DeleteLastMessageCharacter(void)
{
    sChat->lastBufferCursorPos = sChat->bufferCursorPos;
    if (sChat->bufferCursorPos)
    {
        u8 *str = GetLastCharOfMessagePtr();
        *str = EOS;
        sChat->bufferCursorPos--;
    }
}

static void SwitchCaseOfLastMessageCharacter(void)
{
    u8 *str;
    u8 character;

    sChat->lastBufferCursorPos = sChat->bufferCursorPos - 1;
    str = GetLastCharOfMessagePtr();
    if (*str != CHAR_EXTRA_SYMBOL)
    {
        if (*str <= 0xEE)
        {
            character = sCaseToggleTable[*str];
            if (character)
                *str = character;
        }
    }
}

static bool32 ChatMessageIsNotEmpty(void)
{
    if (sChat->bufferCursorPos)
        return TRUE;
    else
        return FALSE;
}

static void RegisterTextAtRow(void)
{
    u8 *src = GetLimitedMessageStartPtr();
    StringCopy(sChat->registeredTexts[sChat->currentRow], src);
    sChat->changedRegisteredTexts = TRUE;
}

static void ResetMessageEntryBuffer(void)
{
    sChat->messageEntryBuffer[0] = EOS;
    sChat->lastBufferCursorPos = MAX_MESSAGE_LENGTH;
    sChat->bufferCursorPos = 0;
}

static void SaveRegisteredTexts(void)
{
    int i;
    for (i = 0; i < UNION_ROOM_KB_ROW_COUNT; i++)
        StringCopy(gSaveBlock1Ptr->registeredTexts[i], sChat->registeredTexts[i]);
}

// Non-static so the still-asm functions can reach it via the
// `sub_0801EC7C = GetRegisteredTextByRow` ld alias.
u8 *GetRegisteredTextByRow(int row)
{
    return sChat->registeredTexts[row];
}

static u8 *GetEndOfMessagePtr(void)
{
    u8 *str = sChat->messageEntryBuffer;
    while (*str != EOS)
        str++;

    return str;
}

// Non-static so the still-asm functions can reach it via the
// `sub_0801ECB8 = GetLastCharOfMessagePtr` ld alias.
u8 *GetLastCharOfMessagePtr(void)
{
    u8 *currChar = sChat->messageEntryBuffer;
    u8 *lastChar = currChar;
    while (*currChar != EOS)
    {
        lastChar = currChar;
        if (*currChar == CHAR_EXTRA_SYMBOL)
            currChar++;
        currChar++;
    }

    return lastChar;
}

// Non-static so the still-asm functions can reach it via the
// `sub_0801ECE8 = GetNumOverflowCharsInMessage` ld alias.
u16 GetNumOverflowCharsInMessage(void)
{
    u8 *str;
    u32 i, numChars, strLength;

    strLength = StringLength_Multibyte(sChat->messageEntryBuffer);
    str = sChat->messageEntryBuffer;
    numChars = 0;
    if (strLength > 10)
    {
        strLength -= 10;
        for (i = 0; i < strLength; i++)
        {
            if (*str == CHAR_EXTRA_SYMBOL)
                str++;

            str++;
            numChars++;
        }
    }

    return numChars;
}

static void PrepareSendBuffer_Null(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_NONE;
}

static void PrepareSendBuffer_Join(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_JOIN;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    buffer[1 + (PLAYER_NAME_LENGTH + 1)] = sChat->multiplayerId;
}

static void PrepareSendBuffer_Chat(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_CHAT;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    StringCopy(&buffer[1 + (PLAYER_NAME_LENGTH + 1)], sChat->messageEntryBuffer);
}

static void PrepareSendBuffer_Leave(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_LEAVE;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    buffer[1 + (PLAYER_NAME_LENGTH + 1)] = sChat->multiplayerId;
    RfuSetNormalDisconnectMode();
}

static void PrepareSendBuffer_Drop(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_DROP;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    buffer[1 + (PLAYER_NAME_LENGTH + 1)] = sChat->multiplayerId;
}

static void PrepareSendBuffer_Disband(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_DISBAND;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    buffer[1 + (PLAYER_NAME_LENGTH + 1)] = sChat->multiplayerId;
}

// Non-static so the still-asm functions can reach it via the
// `sub_0801EE08 = ProcessReceivedChatMessage` ld alias.
bool32 ProcessReceivedChatMessage(u8 *dest, u8 *recvMessage)
{
    u8 *tempStr;
    u8 cmd = *recvMessage;
    u8 *name = recvMessage + 1;
    recvMessage = name;
    recvMessage += PLAYER_NAME_LENGTH + 1;

    switch (cmd)
    {
    case CHAT_MESSAGE_JOIN:
        if (sChat->multiplayerId != name[PLAYER_NAME_LENGTH + 1])
        {
            DynamicPlaceholderTextUtil_Reset();
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, name);
            DynamicPlaceholderTextUtil_ExpandPlaceholders(dest, gUnknown_85CC663);
            return TRUE;
        }
        break;
    case CHAT_MESSAGE_CHAT:
        tempStr = StringCopyPadded(dest, name, 0, 5);
        *(tempStr++) = CHAR_COLON;
        StringCopy(tempStr, recvMessage);
        return TRUE;
    case CHAT_MESSAGE_DISBAND:
        StringCopy(sChat->hostName, name);
        // fall through
    case CHAT_MESSAGE_LEAVE:
        if (sChat->multiplayerId != *recvMessage)
        {
            DynamicPlaceholderTextUtil_Reset();
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, name);
            DynamicPlaceholderTextUtil_ExpandPlaceholders(dest, gUnknown_85CC672);
            return TRUE;
        }
        break;
    }

    return FALSE;
}

// The remaining accessors are non-static so the still-asm functions can
// reach them via the sub_0801EEB0..sub_0801EFE0 ld aliases.
u8 GetCurrentKeyboardPage(void)
{
    return sChat->currentPage;
}

void GetCurrentKeyboardColAndRow(u8 *col, u8 *row)
{
    *col = sChat->currentCol;
    *row = sChat->currentRow;
}

u8 *GetMessageEntryBuffer(void)
{
    return sChat->messageEntryBuffer;
}

int GetLengthOfMessageEntry(void)
{
    u8 *str = GetMessageEntryBuffer();
    return StringLength_Multibyte(str);
}

void GetBufferSelectionRegion(u32 *x, u32 *width)
{
    int diff = sChat->bufferCursorPos - sChat->lastBufferCursorPos;
    if (diff < 0)
    {
        diff = -diff;
        *x = sChat->bufferCursorPos;
    }
    else
    {
        *x = sChat->lastBufferCursorPos;
    }
    *width = diff;
}

u8 *GetLimitedMessageStartPtr(void)
{
    u32 numChars = (u16)GetNumOverflowCharsInMessage();
    u8 *str = sChat->messageEntryBuffer;
    while (numChars != 0)
    {
        if (*str == CHAR_EXTRA_SYMBOL)
            str++;
        str++;
        numChars--;
    }
    return str;
}

u32 GetLimitedMessageStartPos(void)
{
    u16 numChars = GetNumOverflowCharsInMessage();
    u8 *str = sChat->messageEntryBuffer;
    u16 pos = 0;
    u32 i = 0;
    for (; i < numChars; i++)
    {
        if (*str == CHAR_EXTRA_SYMBOL)
            str++;
        str++;
        pos++;
    }
    return pos;
}

u8 *GetLastReceivedMessage(void)
{
    return sChat->receivedMessage;
}

u8 GetReceivedPlayerIndex(void)
{
    return sChat->receivedPlayerIndex;
}

u8 GetTextEntryCursorPosition(void)
{
    return sChat->bufferCursorPos;
}

// JP-only: classify the last typed character for the kana input mode
// (0 = kana range, 1 = katakana range, 2/3 = other ranges).
u8 sub_0801EFA4(void)
{
    s32 ch = *GetLastCharOfMessagePtr();
    if ((u8)(ch - 1) <= 0x4F)
        return 0;
    if ((u8)(ch - 0x51) <= 0x4F)
        return 1;
    if ((u8)(ch + 0x45) <= 0x33)
        return 2;
    return 3;
}

u8 *GetChatHostName(void)
{
    return sChat->hostName;
}

void InitUnionRoomChatRegisteredTexts(void)
{
    StringCopy(&gSaveBlock1Ptr->registeredTexts[0], gUnknown_85CC769);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[1], gUnknown_85CC76F);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[2], gUnknown_85CC774);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[3], gUnknown_85CC779);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[4], gUnknown_85CC77E);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[5], gUnknown_85CC783);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[6], gUnknown_85CC787);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[7], gUnknown_85CC78C);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[8], gUnknown_85CC792);
    StringCopy(&gSaveBlock1Ptr->registeredTexts[9], gUnknown_85CC798);
}
