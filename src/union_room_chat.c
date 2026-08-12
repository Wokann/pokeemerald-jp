#include "global.h"
#include "malloc.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "union_room_chat.h"
#include "constants/characters.h"
#include "constants/rgb.h"

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

static void InitUnionRoomChat(struct UnionRoomChat *);
static void CB2_LoadInterface(void);
static void VBlankCB_UnionRoomChatMain(void);
static void CB2_UnionRoomChatMain(void);
static void Task_HandlePlayerInput(u8 taskId);
static void Chat_Join(void);

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
