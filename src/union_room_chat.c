#include "global.h"
#include "bg.h"
#include "dynamic_placeholder_text_util.h"
#include "graphics.h"
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
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "union_room_chat.h"
#include "window.h"
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
    WIN_CHAT_HISTORY,
    WIN_TEXT_ENTRY,
    WIN_KEYBOARD,
    WIN_SWAP_MENU,
};

enum {
    STDMESSAGE_QUIT_CHATTING,
    STDMESSAGE_REGISTER_WHERE,
    STDMESSAGE_REGISTER_HERE,
    STDMESSAGE_INPUT_TEXT,
    STDMESSAGE_EXITING_CHAT,
    STDMESSAGE_LEADER_LEFT,
    STDMESSAGE_ASK_SAVE,
    STDMESSAGE_ASK_OVERWRITE,
    STDMESSAGE_SAVING_NO_OFF,
    STDMESSAGE_SAVED_THE_GAME,
    STDMESSAGE_WARN_LEADER_LEAVE,
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

struct UnionRoomChatDisplay_Subtask
{
    bool32 (*callback)(u8 *);
    bool8 active;
    u8 state;
};

struct UnionRoomChatDisplay
{
    struct UnionRoomChatDisplay_Subtask subtasks[3];
    u16 yesNoMenuWindowId;
    u16 currLine;
    u16 scrollCount;
    u16 messageWindowId;
    s16 bg1hofs;
    u8 expandedPlaceholdersBuffer[0x106];
    u8 bg0Buffer[BG_SCREEN_SIZE];
    u8 bg1Buffer[BG_SCREEN_SIZE];
    u8 bg3Buffer[BG_SCREEN_SIZE];
    u8 bg2Buffer[BG_SCREEN_SIZE];
    u8 textEntryTiles[TILE_SIZE_4BPP * 2];
};

struct SubtaskInfo
{
    u16 idx;
    bool32 (*callback)(u8 *);
};

struct MessageWindowInfo
{
    const u8 *text;
    u8 boxType;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    bool8 hasPlaceholders;
    bool8 useWiderBox;
};

struct UnionRoomChatSprites
{
    struct Sprite *keyboardCursor;
    struct Sprite *textEntryArrow;
    struct Sprite *textEntryCursor;
    struct Sprite *rButtonIcon;
    struct Sprite *rButtonLabel;
    u16 cursorBlinkTimer;
};

#define PALTAG_INTERFACE 0

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

// JP "YES"/"NO" menu texts (0x085CAAD8 / 0x085CAADB).
extern const u8 gText_Yes[];
extern const u8 gText_No[];

// JP standard chat message templates (0x082C57D4, in data/data_b.s).
extern const struct MessageWindowInfo gUnknown_82C57D4[];
// JP keyboard swap menu title text (0x082C5858).
extern const u8 gUnknown_82C5858[];

// JP union room chat graphics data.
extern const u8 gUnknown_82C5220[];
extern const u8 gUnknown_82C5240[];
extern const u8 gUnknown_82C529C[];
extern const u8 gUnknown_82C5348[];
extern const u8 gUnknown_82C5368[];
extern const u8 gUnknown_82C5388[];
extern const u8 gUnknown_82C55BC[];
extern const u8 gUnknown_82C56B4[];
extern const u8 gUnknown_82C56D4[];
extern const u16 gStandardMenuPalette[];

// JP union room chat sprite resources.
extern const struct CompressedSpriteSheet gUnknown_82C5D4C[];
extern const struct SpritePalette gUnknown_82C5D74;
extern const struct SpriteTemplate gUnknown_82C5DB4;
extern const struct SpriteTemplate gUnknown_82C5DD4;
extern const struct SpriteTemplate gUnknown_82C5DEC;
extern const struct SpriteTemplate gUnknown_82C5E44;
extern const struct SpriteTemplate gUnknown_82C5E5C;
extern const u16 gUnknown_82C588A[];

u8 *GetRegisteredTextByRow(int row);
u8 *GetLastCharOfMessagePtr(void);
u16 GetNumOverflowCharsInMessage(void);
static u8 *GetEndOfMessagePtr(void);
static void AppendTextToMessage(void);
static void DeleteLastMessageCharacter(void);
static void SwitchCaseOfLastMessageCharacter(void);
static bool32 ChatMessageIsNotEmpty(void);
static void RegisterTextAtRow(void);
static void ResetMessageEntryBuffer(void);
static void SaveRegisteredTexts(void);
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
int GetTextEntryCursorPosition(void);
u8 *GetChatHostName(void);
void Task_ReceiveChatMessage(u8 taskId);

extern EWRAM_DATA struct UnionRoomChatDisplay *sDisplay;
extern EWRAM_DATA struct UnionRoomChatSprites *sSprites;
extern const struct BgTemplate gUnknown_82C56F4[];
extern const struct WindowTemplate gUnknown_82C5704[];
extern const struct SubtaskInfo gUnknown_82C572C[];
extern bool32 Display_Dummy(u8 *state);
extern bool32 TryAllocSprites(void);
extern void FreeSprites(void);
extern void InitScanlineEffect(void);
extern void ResetGpuBgState(void);
extern void SetBgTilemapBuffers(void);
extern void ClearBg0(void);
extern void LoadKeyboardWindowGfx(void);
extern void LoadChatWindowGfx(void);
extern void LoadChatUnkPalette(void);
extern void LoadChatMessagesWindow(void);
extern void DrawKeyboardWindow(void);
extern void LoadKeyboardSwapWindow(void);
extern void LoadTextEntryWindow(void);
extern void CreateKeyboardCursorSprite(void);
extern void CreateTextEntrySprites(void);
extern void CreateRButtonSprites(void);
extern void ShowKeyboardSwapMenu(void);
extern void HideKeyboardSwapMenu(void);
extern void SetKeyboardCursorInvisibility(bool32 invisible);
extern bool32 SlideKeyboardPageOut(void);
extern bool32 SlideKeyboardPageIn(void);
extern void PrintCurrentKeyboardPage(void);
extern void MoveKeyboardCursor(void);
extern void UpdateRButtonLabel(void);
extern void AddStdMessageWindow(int msgId, u16 bg0vofs);
extern void AddYesNoMenuAt(u8 x, u8 y, u8 windowId);
extern void HideStdMessageWindow(void);
extern void HideYesNoMenuWindow(void);
extern void DestroyStdMessageWindow(void);
extern void DestroyYesNoMenuWindow(void);
extern void UpdateSlidingKeyboard(s16 hofs);
extern void FinishSlidingKeyboard(s16 hofs);
extern void sub_08198964(u8 a1, u8 a2, u8 a3, u8 a4, const u8 *text);
extern void FillTextEntryWindow(u16 x, u16 width, u8 fillValue);
extern void DrawTextEntryMessage(u16 x, u8 *str, u8 bgColor, u8 fgColor, u8 shadowColor);
extern void SetRegisteredTextPalette(bool32 enabled);
extern void PrintChatMessage(u16 x, u8 *str, u8 colorIdx);
extern void StartKeyboardCursorAnim(void);
extern bool32 TryKeyboardCursorReopen(void);

bool8 TryAllocDisplay(void);
bool32 IsDisplaySubtask0Active(void);
void FreeDisplay(void);
void InitDisplay(struct UnionRoomChatDisplay *display);
void ResetDisplaySubtasks(void);
void RunDisplaySubtasks(void);
void StartDisplaySubtask(u16 subtaskId, u8 assignId);
bool8 IsDisplaySubtaskActive(u8 id);
bool32 Display_LoadGfx(u8 *state);
bool32 Display_ShowKeyboardSwapMenu(u8 *state);
bool32 Display_HideKeyboardSwapMenu(u8 *state);
bool32 Display_SwitchPages(u8 *state);
bool32 Display_MoveKeyboardCursor(u8 *state);
bool32 Display_AskQuitChatting(u8 *state);
bool32 Display_DestroyYesNoDialog(u8 *state);
bool32 Display_UpdateMessageBuffer(u8 *state);
bool32 Display_AskRegisterText(u8 *state);
bool32 Display_CancelRegister(u8 *state);
bool32 Display_ReturnToKeyboard(u8 *state);
bool32 Display_ScrollChat(u8 *state);
bool32 Display_AnimateKeyboardCursor(u8 *state);
bool32 Display_PrintInputText(u8 *state);
bool32 Display_PrintExitingChat(u8 *state);
bool32 Display_PrintLeaderLeft(u8 *state);
bool32 Display_AskSave(u8 *state);
bool32 Display_AskOverwriteSave(u8 *state);
bool32 Display_PrintSavingDontTurnOff(u8 *state);
bool32 Display_PrintSavedTheGame(u8 *state);
bool32 Display_AskConfirmLeaderLeave(u8 *state);
void AddYesNoMenuAt(u8 left, u8 top, u8 initialCursorPos);
void HideYesNoMenuWindow(void);
void DestroyYesNoMenuWindow(void);
s8 ProcessMenuInput(void);
void HideStdMessageWindow(void);
void DestroyStdMessageWindow(void);
void FillTextEntryWindow(u16 x, u16 width, u8 fillValue);
u8 sub_081984B0(u8 windowId, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6, u8 a7);
void AddStdMessageWindow(int msgId, u16 bg0vofs);
void DrawTextEntryMessage(u16 x, u8 *str, u8 bgColor, u8 fgColor, u8 shadowColor);
void PrintCurrentKeyboardPage(void);
bool32 SlideKeyboardPageOut(void);
bool32 SlideKeyboardPageIn(void);
void ShowKeyboardSwapMenu(void);
void HideKeyboardSwapMenu(void);
void PrintChatMessage(u16 row, u8 *str, u8 colorIdx);
void ResetGpuBgState(void);
void SetBgTilemapBuffers(void);
void ClearBg0(void);
void LoadKeyboardWindowGfx(void);
void LoadChatWindowGfx(void);
void LoadChatUnkPalette(void);
void LoadChatMessagesWindow(void);
void DrawKeyboardWindow(void);
void LoadTextEntryWindow(void);
void LoadKeyboardSwapWindow(void);
void InitScanlineEffect(void);
void UpdateSlidingKeyboard(s16 hofs);
void FinishSlidingKeyboard(s16 hofs);
bool32 TryAllocSprites(void);
void FreeSprites(void);
void CreateKeyboardCursorSprite(void);
void SetKeyboardCursorInvisibility(bool32 invisible);
void MoveKeyboardCursor(void);
void SetRegisteredTextPalette(bool32 registering);
void StartKeyboardCursorAnim(void);
bool32 TryKeyboardCursorReopen(void);
void CreateTextEntrySprites(void);
void CreateRButtonSprites(void);
void UpdateRButtonLabel(void);
static void SpriteCB_TextEntryCursor(struct Sprite *sprite);
static void SpriteCB_TextEntryArrow(struct Sprite *sprite);
static void PrepareSendBuffer_Null(u8 *buffer);
static void PrepareSendBuffer_Join(u8 *buffer);
static void PrepareSendBuffer_Chat(u8 *buffer);
static void PrepareSendBuffer_Leave(u8 *buffer);
static void PrepareSendBuffer_Drop(u8 *buffer);
static void PrepareSendBuffer_Disband(u8 *buffer);

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

int GetTextEntryCursorPosition(void)
{
    return sChat->bufferCursorPos;
}

// JP-only: classify the last typed character for the kana input mode
// (0 = kana range, 1 = katakana range, 2/3 = other ranges).
int sub_0801EFA4(void)
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

#define tState               data[0]
#define tI                   data[1]
#define tCurrLinkPlayer      data[2]
#define tBlockReceivedStatus data[3]
#define tLinkPlayerCount     data[4]
#define tNextState           data[5]

// Non-static so the still-asm functions can reach it via the
// `sub_0801F0C4 = Task_ReceiveChatMessage` ld alias.
void Task_ReceiveChatMessage(u8 taskId)
{
    u8 *buffer;
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!gReceivedRemoteLinkPlayers)
        {
            DestroyTask(taskId);
            return;
        }

        tState = 1;
        // fall through
    case 1:
        tLinkPlayerCount = GetLinkPlayerCount();
        if (sChat->linkPlayerCount != tLinkPlayerCount)
        {
            tState = 2;
            sChat->linkPlayerCount = tLinkPlayerCount;
            return;
        }

        tBlockReceivedStatus = GetBlockReceivedStatus();
        if (!tBlockReceivedStatus && Rfu_IsPlayerExchangeActive())
            return;

        tI = 0;
        tState = 3;
        // fall through
    case 3:
        for (; tI < MAX_RFU_PLAYERS && ((tBlockReceivedStatus >> tI) & 1) == 0; tI++)
            ;

        if (tI == MAX_RFU_PLAYERS)
        {
            tState = 1;
            return;
        }

        tCurrLinkPlayer = tI;
        ResetBlockReceivedFlag(tCurrLinkPlayer);
        buffer = (u8 *)gBlockRecvBuffer[tI];
        switch (buffer[0])
        {
            default:
            case CHAT_MESSAGE_CHAT:    tNextState = 3; break;
            case CHAT_MESSAGE_JOIN:    tNextState = 3; break;
            case CHAT_MESSAGE_LEAVE:   tNextState = 4; break;
            case CHAT_MESSAGE_DROP:    tNextState = 5; break;
            case CHAT_MESSAGE_DISBAND: tNextState = 6; break;
        }

        if (ProcessReceivedChatMessage(sChat->receivedMessage, (u8 *)gBlockRecvBuffer[tI]))
        {
            sChat->receivedPlayerIndex = tI;
            StartDisplaySubtask(CHATDISPLAY_FUNC_SCROLL_CHAT, 2);
            tState = 7;
        }
        else
        {
            tState = tNextState;
        }

        tI++;
        break;
    case 7:
        if (!IsDisplaySubtaskActive(2))
            tState = tNextState;
        break;
    case 4:
        if (!sChat->multiplayerId && tCurrLinkPlayer)
        {
            if (GetLinkPlayerCount() == 2)
            {
                Rfu_StopPartnerSearch();
                sChat->exitType = CHAT_EXIT_ONLY_LEADER;
                DestroyTask(taskId);
                return;
            }
            Rfu_DisconnectPlayerById(tCurrLinkPlayer);
        }

        tState = 3;
        break;
    case 5:
        if (sChat->multiplayerId)
            sChat->exitType = CHAT_EXIT_DROPPED;

        DestroyTask(taskId);
        break;
    case 6:
        sChat->exitType = CHAT_EXIT_DISBANDED;
        DestroyTask(taskId);
        break;
    case 2:
        if (!Rfu_IsPlayerExchangeActive())
        {
            if (!sChat->multiplayerId)
                SetUnionRoomChatPlayerData(sChat->linkPlayerCount);

            tState = 1;
        }
        break;
    }
}

#undef tNextState
#undef tLinkPlayerCount
#undef tBlockReceivedStatus
#undef tCurrLinkPlayer
#undef tI
#undef tState

// The display subsystem helpers are non-static so the still-asm functions
// can reach them via the sub_0801F2E0..sub_0801F454 ld aliases.
bool8 TryAllocDisplay(void)
{
    sDisplay = Alloc(sizeof(*sDisplay));
    if (sDisplay && TryAllocSprites())
    {
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, gUnknown_82C56F4, 4);
        InitWindows(gUnknown_82C5704);
        ResetTempTileDataBuffers();
        InitScanlineEffect();
        InitDisplay(sDisplay);
        ResetDisplaySubtasks();
        StartDisplaySubtask(CHATDISPLAY_FUNC_LOAD_GFX, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool32 IsDisplaySubtask0Active(void)
{
    return IsDisplaySubtaskActive(0);
}

void FreeDisplay(void)
{
    FreeSprites();
    if (sDisplay)
    {
        Free(sDisplay);
        sDisplay = NULL;
    }

    FreeAllWindowBuffers();
    gScanlineEffect.state = 3;
}

void InitDisplay(struct UnionRoomChatDisplay *display)
{
    display->yesNoMenuWindowId = WINDOW_NONE;
    display->messageWindowId = WINDOW_NONE;
    display->currLine = 0;
}

void ResetDisplaySubtasks(void)
{
    int i;

    if (!sDisplay)
        return;

    for (i = 0; i < (int)ARRAY_COUNT(sDisplay->subtasks); i++)
    {
        sDisplay->subtasks[i].callback = Display_Dummy;
        sDisplay->subtasks[i].active = FALSE;
        sDisplay->subtasks[i].state = 0;
    }
}

void RunDisplaySubtasks(void)
{
    int i;

    if (!sDisplay)
        return;

    for (i = 0; i < (int)ARRAY_COUNT(sDisplay->subtasks); i++)
    {
        sDisplay->subtasks[i].active =
            sDisplay->subtasks[i].callback(&sDisplay->subtasks[i].state);
    }
}

void StartDisplaySubtask(u16 subtaskId, u8 assignId)
{
    u32 i;

    sDisplay->subtasks[assignId].callback = Display_Dummy;
    for (i = 0; i < 21; i++)
    {
        if (gUnknown_82C572C[i].idx == subtaskId)
        {
            sDisplay->subtasks[assignId].callback = gUnknown_82C572C[i].callback;
            sDisplay->subtasks[assignId].active = TRUE;
            sDisplay->subtasks[assignId].state = 0;
            break;
        }
    }
}

bool8 IsDisplaySubtaskActive(u8 id)
{
    return sDisplay->subtasks[id].active;
}

bool32 Display_LoadGfx(u8 *state)
{
    if (FreeTempTileDataBuffersIfPossible() == TRUE)
        return TRUE;

    switch (*state)
    {
    case 0:
        ResetGpuBgState();
        SetBgTilemapBuffers();
        break;
    case 1:
        ClearBg0();
        break;
    case 2:
        LoadKeyboardWindowGfx();
        break;
    case 3:
        LoadChatWindowGfx();
        break;
    case 4:
        LoadChatUnkPalette();
        break;
    case 5:
        LoadChatMessagesWindow();
        DrawKeyboardWindow();
        LoadKeyboardSwapWindow();
        LoadTextEntryWindow();
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CreateKeyboardCursorSprite();
            CreateTextEntrySprites();
            CreateRButtonSprites();
        }
        break;
    default:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 Display_ShowKeyboardSwapMenu(u8 *state)
{
    switch (*state)
    {
    case 0:
        ShowKeyboardSwapMenu();
        CopyWindowToVram(WIN_SWAP_MENU, COPYWIN_FULL);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

bool32 Display_HideKeyboardSwapMenu(u8 *state)
{
    switch (*state)
    {
    case 0:
        HideKeyboardSwapMenu();
        CopyWindowToVram(WIN_SWAP_MENU, COPYWIN_FULL);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

bool32 Display_SwitchPages(u8 *state)
{
    switch (*state)
    {
    case 0:
        SetKeyboardCursorInvisibility(TRUE);
        if (SlideKeyboardPageOut())
            return TRUE;

        PrintCurrentKeyboardPage();
        CopyWindowToVram(WIN_KEYBOARD, COPYWIN_GFX);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;
        break;
    case 2:
        if (SlideKeyboardPageIn())
            return TRUE;

        MoveKeyboardCursor();
        SetKeyboardCursorInvisibility(FALSE);
        UpdateRButtonLabel();
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 Display_MoveKeyboardCursor(u8 *state)
{
    MoveKeyboardCursor();
    return FALSE;
}

bool32 Display_AskQuitChatting(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_QUIT_CHATTING, 0);
        AddYesNoMenuAt(23, 11, 1);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

bool32 Display_DestroyYesNoDialog(u8 *state)
{
    switch (*state)
    {
    case 0:
        HideStdMessageWindow();
        HideYesNoMenuWindow();
        CopyBgTilemapBufferToVram(0);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        DestroyStdMessageWindow();
        DestroyYesNoMenuWindow();
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 Display_UpdateMessageBuffer(u8 *state)
{
    u32 x, width;
    u8 *str;

    switch (*state)
    {
    case 0:
        GetBufferSelectionRegion(&x, &width);
        FillTextEntryWindow(x, width, 0);
        str = GetMessageEntryBuffer();
        DrawTextEntryMessage(0, str, 3, 1, 2);
        CopyWindowToVram(WIN_TEXT_ENTRY, COPYWIN_GFX);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            UpdateRButtonLabel();
            return FALSE;
        }
        return TRUE;
    }

    (*state)++;
    return TRUE;
}

bool32 Display_AskRegisterText(u8 *state)
{
    u16 x;
    u8 *str;
    u16 length;

    switch (*state)
    {
    case 0:
        x = GetLimitedMessageStartPos();
        str = GetLimitedMessageStartPtr();
        length = StringLength_Multibyte(str);
        FillTextEntryWindow(x, length, PIXEL_FILL(6));
        DrawTextEntryMessage(x, str, 0, 4, 5);
        CopyWindowToVram(WIN_TEXT_ENTRY, COPYWIN_GFX);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            AddStdMessageWindow(STDMESSAGE_REGISTER_WHERE, 16);
            CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        }
        else
        {
            return TRUE;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetRegisteredTextPalette(TRUE);
        else
            return TRUE;
        break;
    case 3:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 Display_CancelRegister(u8 *state)
{
    u16 x;
    u8 *str;
    u16 length;

    switch (*state)
    {
    case 0:
        x = GetLimitedMessageStartPos();
        str = GetLimitedMessageStartPtr();
        length = StringLength_Multibyte(str);
        FillTextEntryWindow(x, length, PIXEL_FILL(0));
        DrawTextEntryMessage(x, str, 3, 1, 2);
        CopyWindowToVram(WIN_TEXT_ENTRY, COPYWIN_GFX);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            HideStdMessageWindow();
            CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        }
        else
        {
            return TRUE;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetRegisteredTextPalette(FALSE);
            DestroyStdMessageWindow();
        }
        else
        {
            return TRUE;
        }
        break;
    case 3:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

bool32 Display_ReturnToKeyboard(u8 *state)
{
    switch (*state)
    {
    case 0:
        PrintCurrentKeyboardPage();
        CopyWindowToVram(WIN_KEYBOARD, COPYWIN_GFX);
        (*state)++;
        return TRUE;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            return FALSE;
        return TRUE;
    default:
        return TRUE;
    }
}

bool32 Display_ScrollChat(u8 *state)
{
    u16 row;
    u8 *str;
    u8 colorIdx;

    switch (*state)
    {
    case 0:
        row = sDisplay->currLine;
        str = GetLastReceivedMessage();
        colorIdx = GetReceivedPlayerIndex();
        PrintChatMessage(row, str, colorIdx);
        CopyWindowToVram(WIN_CHAT_HISTORY, COPYWIN_GFX);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        // JP allows up to 11 lines (US stops at 9).
        if (sDisplay->currLine <= 10)
        {
            sDisplay->currLine++;
            *state = 4;
            return FALSE;
        }
        else
        {
            sDisplay->scrollCount = 0;
            (*state)++;
        }
        // fall through
    case 2:
        // JP scrolls by 4 pixels (US uses 5).
        ScrollWindow(WIN_CHAT_HISTORY, 0, 4, PIXEL_FILL(1));
        CopyWindowToVram(WIN_CHAT_HISTORY, COPYWIN_GFX);
        sDisplay->scrollCount++;
        (*state)++;
        // fall through
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        if (sDisplay->scrollCount < 3)
        {
            (*state)--;
            return TRUE;
        }
        break;
    case 4:
        return FALSE;
    default:
        return TRUE;
    }

    (*state)++;
    return TRUE;
}

bool32 Display_AnimateKeyboardCursor(u8 *state)
{
    switch (*state)
    {
    case 0:
        StartKeyboardCursorAnim();
        (*state)++;
        break;
    case 1:
        return TryKeyboardCursorReopen();
    }

    return TRUE;
}

bool32 Display_PrintInputText(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_INPUT_TEXT, 16);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 Display_PrintExitingChat(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_EXITING_CHAT, 0);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 Display_PrintLeaderLeft(u8 *state)
{
    switch (*state)
    {
    case 0:
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, GetChatHostName());
        AddStdMessageWindow(STDMESSAGE_LEADER_LEFT, 0);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 Display_AskSave(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_ASK_SAVE, 0);
        AddYesNoMenuAt(23, 10, 1);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 Display_AskOverwriteSave(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_ASK_OVERWRITE, 0);
        AddYesNoMenuAt(23, 10, 1);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 Display_PrintSavingDontTurnOff(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_SAVING_NO_OFF, 0);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 Display_PrintSavedTheGame(u8 *state)
{
    switch (*state)
    {
    case 0:
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, (const u8 *)gSaveBlock2Ptr);
        AddStdMessageWindow(STDMESSAGE_SAVED_THE_GAME, 0);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 Display_AskConfirmLeaderLeave(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_WARN_LEADER_LEAVE, 0);
        AddYesNoMenuAt(23, 10, 1);
        CopyWindowToVram(sDisplay->messageWindowId, COPYWIN_FULL);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

bool32 Display_Dummy(u8 *state)
{
    return FALSE;
}

void AddYesNoMenuAt(u8 left, u8 top, u8 initialCursorPos)
{
    struct WindowTemplate template;
    template.bg = 0;
    template.tilemapLeft = left;
    template.tilemapTop = top;
    template.width = 6;
    template.height = 4;
    template.paletteNum = 14;
    template.baseBlock = 0x59; // JP Yes/No window base block (US uses 0x52)
    sDisplay->yesNoMenuWindowId = AddWindow(&template);
    if (sDisplay->yesNoMenuWindowId != WINDOW_NONE)
    {
        FillWindowPixelBuffer(sDisplay->yesNoMenuWindowId, PIXEL_FILL(1));
        PutWindowTilemap(sDisplay->yesNoMenuWindowId);
        AddTextPrinterParameterized(sDisplay->yesNoMenuWindowId, FONT_NORMAL, gText_Yes, 10, 2, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(sDisplay->yesNoMenuWindowId, FONT_NORMAL, gText_No, 10, 16, TEXT_SKIP_DRAW, NULL);
        DrawTextBorderOuter(sDisplay->yesNoMenuWindowId, 1, 13);
        sub_081984B0(sDisplay->yesNoMenuWindowId, 1, 0, 2, 14, 2, initialCursorPos);
    }
}

void HideYesNoMenuWindow(void)
{
    if (sDisplay->yesNoMenuWindowId != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(sDisplay->yesNoMenuWindowId, FALSE);
        ClearWindowTilemap(sDisplay->yesNoMenuWindowId);
    }
}

void DestroyYesNoMenuWindow(void)
{
    if (sDisplay->yesNoMenuWindowId != WINDOW_NONE)
    {
        RemoveWindow(sDisplay->yesNoMenuWindowId);
        sDisplay->yesNoMenuWindowId = WINDOW_NONE;
    }
}

s8 ProcessMenuInput(void)
{
    return Menu_ProcessInput();
}

void HideStdMessageWindow(void)
{
    if (sDisplay->messageWindowId != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(sDisplay->messageWindowId, FALSE);
        ClearWindowTilemap(sDisplay->messageWindowId);
    }

    ChangeBgY(0, 0, BG_COORD_SET);
}

void DestroyStdMessageWindow(void)
{
    if (sDisplay->messageWindowId != WINDOW_NONE)
    {
        RemoveWindow(sDisplay->messageWindowId);
        sDisplay->messageWindowId = WINDOW_NONE;
    }
}

void FillTextEntryWindow(u16 x, u16 width, u8 fillValue)
{
    FillWindowPixelRect(WIN_TEXT_ENTRY, fillValue, x * 8, 1, width * 8, 14);
}

void AddStdMessageWindow(int msgId, u16 bg0vofs)
{
    const u8 *str;
    int windowId;
    struct WindowTemplate template;
    template.bg = 0;
    template.tilemapLeft = 8;
    template.tilemapTop = 16;
    template.width = 21;
    template.height = 4;
    template.paletteNum = 14;
    template.baseBlock = 0x71; // JP standard message window base block (US uses 0x6A)
    if (gUnknown_82C57D4[msgId].useWiderBox)
    {
        template.tilemapLeft -= 7;
        template.width += 7;
    }

    sDisplay->messageWindowId = AddWindow(&template);
    windowId = sDisplay->messageWindowId;
    if (sDisplay->messageWindowId == WINDOW_NONE)
        return;

    if (gUnknown_82C57D4[msgId].hasPlaceholders)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(sDisplay->expandedPlaceholdersBuffer, gUnknown_82C57D4[msgId].text);
        str = sDisplay->expandedPlaceholdersBuffer;
    }
    else
    {
        str = gUnknown_82C57D4[msgId].text;
    }

    ChangeBgY(0, bg0vofs * 256, BG_COORD_SET);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (gUnknown_82C57D4[msgId].boxType == 1)
    {
        DrawTextBorderInner(windowId, 0xA, 2);
        AddTextPrinterParameterized5(
            windowId,
            FONT_NORMAL,
            str,
            gUnknown_82C57D4[msgId].x + 8,
            gUnknown_82C57D4[msgId].y + 8,
            TEXT_SKIP_DRAW,
            NULL,
            gUnknown_82C57D4[msgId].letterSpacing,
            gUnknown_82C57D4[msgId].lineSpacing);
    }
    else
    {
        DrawTextBorderOuter(windowId, 0xA, 2);
        AddTextPrinterParameterized5(
            windowId,
            FONT_NORMAL,
            str,
            gUnknown_82C57D4[msgId].x,
            gUnknown_82C57D4[msgId].y,
            TEXT_SKIP_DRAW,
            NULL,
            gUnknown_82C57D4[msgId].letterSpacing,
            gUnknown_82C57D4[msgId].lineSpacing);
    }

    sDisplay->messageWindowId = windowId;
}

// JP draws the message text directly with FONT_SMALL (no EXT_CTRL_CODE
// letter-spacing prefix and no FillTextEntryWindow pre-fill, unlike US).
void DrawTextEntryMessage(u16 x, u8 *str, u8 bgColor, u8 fgColor, u8 shadowColor)
{
    u8 color[3];
    color[0] = bgColor;
    color[1] = fgColor;
    color[2] = shadowColor;
    StringLength_Multibyte(str); // JP computes the length but does not use it
    AddTextPrinterParameterized3(WIN_TEXT_ENTRY, FONT_SMALL, x * 8, 1, color, -1, str);
}

// JP prints the keyboard rows at x=6 with 11px row spacing and renders
// the register page from sDisplay->expandedPlaceholdersBuffer.
void PrintCurrentKeyboardPage(void)
{
    u8 page;
    int i;
    u16 top;
    u8 color[3];

    FillWindowPixelBuffer(WIN_KEYBOARD, PIXEL_FILL(15));
    page = GetCurrentKeyboardPage();
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_5;
    color[2] = TEXT_DYNAMIC_COLOR_4;
    if (page != UNION_ROOM_KB_PAGE_REGISTER)
    {
        for (i = 0, top = 0; i < UNION_ROOM_KB_ROW_COUNT; i++, top += 11)
        {
            if (!sUnionRoomKeyboardText[page][i])
                return;

            AddTextPrinterParameterized3(WIN_KEYBOARD, FONT_SMALL, 6, top, color, -1, sUnionRoomKeyboardText[page][i]);
        }
    }
    else
    {
        for (i = 0, top = 0; i < UNION_ROOM_KB_ROW_COUNT; i++, top += 11)
        {
            StringCopyN_Multibyte(sDisplay->expandedPlaceholdersBuffer, GetRegisteredTextByRow(i), 5);
            AddTextPrinterParameterized3(WIN_KEYBOARD, FONT_SMALL, 6, top, color, -1, sDisplay->expandedPlaceholdersBuffer);
        }
    }
}

bool32 SlideKeyboardPageOut(void)
{
    if (sDisplay->bg1hofs <= 0x37)
    {
        sDisplay->bg1hofs += 12;
        if (sDisplay->bg1hofs > 0x37)
            sDisplay->bg1hofs = 0x38;
        if (sDisplay->bg1hofs <= 0x37)
        {
            UpdateSlidingKeyboard(sDisplay->bg1hofs);
            return TRUE;
        }
    }

    FinishSlidingKeyboard(sDisplay->bg1hofs);
    return FALSE;
}

bool32 SlideKeyboardPageIn(void)
{
    if (sDisplay->bg1hofs > 0)
    {
        sDisplay->bg1hofs -= 12;
        if (sDisplay->bg1hofs <= 0)
            sDisplay->bg1hofs = 0;
        if (sDisplay->bg1hofs > 0)
        {
            UpdateSlidingKeyboard(sDisplay->bg1hofs);
            return TRUE;
        }
    }

    FinishSlidingKeyboard(sDisplay->bg1hofs);
    return FALSE;
}

void ShowKeyboardSwapMenu(void)
{
    FillWindowPixelBuffer(WIN_SWAP_MENU, PIXEL_FILL(1));
    DrawTextBorderOuter(WIN_SWAP_MENU, 1, 13);
    sub_08198964(WIN_SWAP_MENU, 1, 13, 6, gUnknown_82C5858);
    sub_081984B0(WIN_SWAP_MENU, 1, 0, 0, 13, 6, GetCurrentKeyboardPage());
    PutWindowTilemap(WIN_SWAP_MENU);
}

void HideKeyboardSwapMenu(void)
{
    ClearStdWindowAndFrameToTransparent(WIN_SWAP_MENU, FALSE);
    ClearWindowTilemap(WIN_SWAP_MENU);
}

// JP chat history rows are 12px apart (US uses 15) and print with FONT_SMALL.
void PrintChatMessage(u16 row, u8 *str, u8 colorIdx)
{
    u8 color[3];
    color[0] = TEXT_COLOR_WHITE;
    color[1] = colorIdx * 2 + 2;
    color[2] = colorIdx * 2 + 3;
    FillWindowPixelRect(WIN_CHAT_HISTORY, PIXEL_FILL(1), 0, row * 12, 168, 12);
    AddTextPrinterParameterized3(WIN_CHAT_HISTORY, FONT_SMALL, 0, row * 12, color, -1, str);
}

void ResetGpuBgState(void)
{
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(64, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT - 16));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG2 | WININ_WIN0_BG3
                              | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
}

void SetBgTilemapBuffers(void)
{
    SetBgTilemapBuffer(0, sDisplay->bg0Buffer);
    SetBgTilemapBuffer(1, sDisplay->bg1Buffer);
    SetBgTilemapBuffer(3, sDisplay->bg3Buffer);
    SetBgTilemapBuffer(2, sDisplay->bg2Buffer);
}

void ClearBg0(void)
{
    RequestDma3Fill(0, (void *)BG_CHAR_ADDR(0), 0x20, 1);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    CopyBgTilemapBufferToVram(0);
}

void LoadKeyboardWindowGfx(void)
{
    LoadPalette(gUnknown_82C5220, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
    LoadPalette(gUnknown_82C5348, BG_PLTT_ID(12), PLTT_SIZE_4BPP);
    DecompressAndCopyTileDataToVram(1, gUnknown_82C5240, 0, 0, 0);
    CopyToBgTilemapBuffer(1, gUnknown_82C529C, 0, 0);
    CopyBgTilemapBufferToVram(1);
}

void LoadChatWindowGfx(void)
{
    u8 *ptr;

    LoadPalette(gUnknown_82C5368, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    ptr = DecompressAndCopyTileDataToVram(2, gUnknown_82C5388, 0, 0, 0);
    if (ptr)
    {
        CpuFastCopy(&ptr[0x11 * TILE_SIZE_4BPP], &sDisplay->textEntryTiles[TILE_SIZE_4BPP * 0], TILE_SIZE_4BPP);
        CpuFastCopy(&ptr[0x21 * TILE_SIZE_4BPP], &sDisplay->textEntryTiles[TILE_SIZE_4BPP * 1], TILE_SIZE_4BPP);
    }

    CopyToBgTilemapBuffer(2, gUnknown_82C55BC, 0, 0);
    CopyBgTilemapBufferToVram(2);
}

void LoadChatUnkPalette(void)
{
    LoadPalette(gUnknown_82C56B4, BG_PLTT_ID(8), 0x20);
    RequestDma3Fill(0, (void *)BG_CHAR_ADDR(1) + TILE_SIZE_4BPP, TILE_SIZE_4BPP, 1);
}

void LoadChatMessagesWindow(void)
{
    LoadPalette(gUnknown_82C56D4, BG_PLTT_ID(15), 0x20);
    PutWindowTilemap(WIN_CHAT_HISTORY);
    FillWindowPixelBuffer(WIN_CHAT_HISTORY, PIXEL_FILL(1));
    CopyWindowToVram(WIN_CHAT_HISTORY, COPYWIN_FULL);
}

void DrawKeyboardWindow(void)
{
    PutWindowTilemap(WIN_KEYBOARD);
    PrintCurrentKeyboardPage();
    CopyWindowToVram(WIN_KEYBOARD, COPYWIN_FULL);
}

void LoadTextEntryWindow(void)
{
    int i;
    u8 unused[2];
    unused[0] = 0;
    unused[1] = 0xFF;

    for (i = 0; i < MAX_MESSAGE_LENGTH; i++)
        BlitBitmapToWindow(WIN_TEXT_ENTRY, sDisplay->textEntryTiles, i * 8, 0, 8, 16);

    FillWindowPixelBuffer(WIN_TEXT_ENTRY, PIXEL_FILL(0));
    PutWindowTilemap(WIN_TEXT_ENTRY);
    CopyWindowToVram(WIN_TEXT_ENTRY, COPYWIN_FULL);
}

void LoadKeyboardSwapWindow(void)
{
    FillWindowPixelBuffer(WIN_SWAP_MENU, PIXEL_FILL(1));
    LoadUserWindowBorderGfx(WIN_SWAP_MENU, 1, BG_PLTT_ID(13));
    LoadUserWindowBorderGfx_(WIN_SWAP_MENU, 0xA, BG_PLTT_ID(2));
    LoadPalette(gStandardMenuPalette, BG_PLTT_ID(14), PLTT_SIZE_4BPP);
}

void InitScanlineEffect(void)
{
    struct ScanlineEffectParams params;
    params.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    params.dmaDest = &REG_BG1HOFS;
    params.initState = 1;
    params.unused9 = 0;
    sDisplay->bg1hofs = 0;
    CpuFastFill(0, gScanlineEffectRegBuffers, sizeof(gScanlineEffectRegBuffers));
    ScanlineEffect_SetParams(params);
}

void UpdateSlidingKeyboard(s16 hofs)
{
    CpuFill16(hofs, gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], 0x120);
    CpuFill16(0,       gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer] + 0x90, 0x20);
}

void FinishSlidingKeyboard(s16 hofs)
{
    CpuFill16(hofs, gScanlineEffectRegBuffers[0],         0x120);
    CpuFill16(0,       gScanlineEffectRegBuffers[0] +  0x90, 0x20);
    CpuFill16(hofs, gScanlineEffectRegBuffers[0] + 0x3C0, 0x120);
    CpuFill16(0,       gScanlineEffectRegBuffers[0] + 0x450, 0x20);
}

bool32 TryAllocSprites(void)
{
    u32 i;
    for (i = 0; i < 5; i++)
        LoadCompressedSpriteSheet(&gUnknown_82C5D4C[i]);

    LoadSpritePalette(&gUnknown_82C5D74);
    sSprites = Alloc(sizeof(*sSprites));
    if (!sSprites)
        return FALSE;

    return TRUE;
}

void FreeSprites(void)
{
    if (sSprites)
        Free(sSprites);
}

void CreateKeyboardCursorSprite(void)
{
    u8 spriteId = CreateSprite(&gUnknown_82C5DB4, 10, 24, 0);
    sSprites->keyboardCursor = &gSprites[spriteId];
}

void SetKeyboardCursorInvisibility(bool32 invisible)
{
    sSprites->keyboardCursor->invisible = invisible;
}

// JP keyboard cursor rows are 11px apart (US uses 12).
void MoveKeyboardCursor(void)
{
    u8 x, y;
    u8 page = GetCurrentKeyboardPage();
    GetCurrentKeyboardColAndRow(&x, &y);
    if (page != UNION_ROOM_KB_PAGE_REGISTER)
    {
        StartSpriteAnim(sSprites->keyboardCursor, 0);
        sSprites->keyboardCursor->x = x * 8 + 10;
        sSprites->keyboardCursor->y = y * 11 + 24;
    }
    else
    {
        StartSpriteAnim(sSprites->keyboardCursor, 2);
        sSprites->keyboardCursor->x = 24;
        sSprites->keyboardCursor->y = y * 11 + 24;
    }
}

void SetRegisteredTextPalette(bool32 registering)
{
    const u16 *palette = &gUnknown_82C588A[registering * 2];
    u8 index = IndexOfSpritePaletteTag(PALTAG_INTERFACE);
    LoadPalette(palette, OBJ_PLTT_ID(index) + 1, PLTT_SIZEOF(2));
}

void StartKeyboardCursorAnim(void)
{
    if (GetCurrentKeyboardPage() != UNION_ROOM_KB_PAGE_REGISTER)
        StartSpriteAnim(sSprites->keyboardCursor, 1);
    else
        StartSpriteAnim(sSprites->keyboardCursor, 3);

    sSprites->cursorBlinkTimer = 0;
}

bool32 TryKeyboardCursorReopen(void)
{
    if (sSprites->cursorBlinkTimer > 3)
        return FALSE;

    if (++sSprites->cursorBlinkTimer > 3)
    {
        if (GetCurrentKeyboardPage() != UNION_ROOM_KB_PAGE_REGISTER)
            StartSpriteAnim(sSprites->keyboardCursor, 0);
        else
            StartSpriteAnim(sSprites->keyboardCursor, 2);

        return FALSE;
    }

    return TRUE;
}

void CreateTextEntrySprites(void)
{
    u8 spriteId = CreateSprite(&gUnknown_82C5DD4, 76, 152, 2);
    sSprites->textEntryCursor = &gSprites[spriteId];
    spriteId = CreateSprite(&gUnknown_82C5DEC, 64, 152, 1);
    sSprites->textEntryArrow = &gSprites[spriteId];
}

static void SpriteCB_TextEntryCursor(struct Sprite *sprite)
{
    int pos = GetTextEntryCursorPosition();
    if (pos == MAX_MESSAGE_LENGTH)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->x = pos * 8 + 76;
    }
}

static void SpriteCB_TextEntryArrow(struct Sprite *sprite)
{
    if (++sprite->data[0] > 4)
    {
        sprite->data[0] = 0;
        if (++sprite->x2 > 4)
            sprite->x2 = 0;
    }
}

void CreateRButtonSprites(void)
{
    u8 spriteId = CreateSprite(&gUnknown_82C5E44, 8, 152, 3);
    sSprites->rButtonIcon = &gSprites[spriteId];
    spriteId = CreateSprite(&gUnknown_82C5E5C, 32, 152, 4);
    sSprites->rButtonLabel = &gSprites[spriteId];
    sSprites->rButtonLabel->invisible = TRUE;
}

void UpdateRButtonLabel(void)
{
    if (GetCurrentKeyboardPage() == UNION_ROOM_KB_PAGE_REGISTER)
    {
        if (GetLengthOfMessageEntry() != 0)
        {
            sSprites->rButtonLabel->invisible = FALSE;
            StartSpriteAnim(sSprites->rButtonLabel, 3);
        }
        else
        {
            sSprites->rButtonLabel->invisible = TRUE;
        }
    }
    else
    {
        int anim = sub_0801EFA4();
        if (anim == 3)
        {
            sSprites->rButtonLabel->invisible = TRUE;
        }
        else
        {
            sSprites->rButtonLabel->invisible = FALSE;
            StartSpriteAnim(sSprites->rButtonLabel, anim);
        }
    }
}
