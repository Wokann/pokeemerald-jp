#include "global.h"
#include "bg.h"
#include "menu.h"
#include "window.h"

// Union-room chat windows/tasks data (0x82C55BC..0x82C588A)

extern const u8 sKeyboardFunctionTexts[];
extern const u8 gUnknown_85CC663[];
extern bool32 Display_LoadGfx(u8 *), Display_ShowKeyboardSwapMenu(u8 *), Display_HideKeyboardSwapMenu(u8 *), Display_SwitchPages(u8 *), Display_MoveKeyboardCursor(u8 *), Display_AskQuitChatting(u8 *), Display_DestroyYesNoDialog(u8 *), Display_UpdateMessageBuffer(u8 *), Display_AskRegisterText(u8 *), Display_CancelRegister(u8 *), Display_ReturnToKeyboard(u8 *), Display_ScrollChat(u8 *), Display_AnimateKeyboardCursor(u8 *), Display_PrintInputText(u8 *), Display_PrintExitingChat(u8 *), Display_PrintLeaderLeft(u8 *), Display_AskSave(u8 *), Display_AskOverwriteSave(u8 *), Display_PrintSavingDontTurnOff(u8 *), Display_PrintSavedTheGame(u8 *), Display_AskConfirmLeaderLeave(u8 *);

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

// 0x82C55BC (BG tilemap, copied to bg 2)
const u16 sKeyboardBg2Tilemap[] = { 0x0010, 0x0005, 0x0120, 0x7000, 0x2501, 0x0F00, 0x1000, 0x0000, 0x0011, 0x0012, 0x0024, 0x0013, 0x1400, 0x1500, 0x1600, 0x1700, 0x0000, 0x0018, 0x0019, 0x001A, 0x201B, 0x1C00, 0x1500, 0x001E, 0x001F, 0x0220, 0x2100, 0x2200, 0x2300, 0x0D00, 0xAB00, 0x0100, 0x1002, 0x0401, 0x0150, 0x200A, 0xF013, 0x8F01, 0x01F0, 0x0000, 0xF00B, 0xF03F, 0xF03F, 0xF001, 0xFF3F, 0x3FF0, 0x01F0, 0x01F0, 0x3FF0, 0x3FF0, 0x01F0, 0x3FF0, 0x3FF0, 0xF0FF, 0xF001, 0xF001, 0xF03F, 0xF03F, 0xF001, 0xF03F, 0xF03F, 0xFF01, 0x01F0, 0x3FF0, 0x3FF0, 0x01F0, 0x3FF0, 0x3FF0, 0x26F0, 0x01F0, 0xF0FF, 0xF03F, 0xF03F, 0xF001, 0xF03F, 0xF03F, 0xF03F, 0xF001, 0xFF3F, 0x3FF0, 0x01F0, 0x01F0, 0x3FF0, 0x3FF0, 0x01F0, 0x3FF0, 0x3FF0, 0xF0FF, 0xF001, 0xF001, 0xF03F, 0xF03F, 0xF001, 0x303F, 0x603F, 0xF701, 0x3FF0, 0x01F0, 0x3FF0, 0x7D50, 0xF003, 0xF03F, 0xF001, 0x8B3F, 0x3F60, 0x0004, 0x000E, 0x0501, 0x01F0, 0x0180, 0x0614, 0x0C00, 0x0140, 0xE00D, 0x073F, 0x5B00, 0x001D, 0x0801, 0x01F0, 0x0180, 0x5009, 0x00EB, 0x802F, 0x3F10 };

// 0x82C56B4
const u16 sChatMessagesWindow_Pal[] = { 0x0000, 0x0000, 0x7FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 };

// 0x82C56D4
const u16 sUnionRoomChatInterfacePal[] = { 0x0000, 0x7FDE, 0x0000, 0x7339, 0x0346, 0x6B9B, 0x7C00, 0x6F59, 0x001F, 0x635B, 0x02FF, 0x6F9C, 0x6318, 0x1085, 0x0000, 0x1CE7 };

// 0x82C56F4
// 0x82C56F4 (the JP 4th entry has a set bit14 not expressible via the
// struct fields, so keep the raw u16 pairs)
const u16 sChatBgTemplates[] = {
    0x0070, 0x0000,
    0x11FD, 0x0000,
    0x217A, 0x0000,
    0x70F7, 0x0000,
};

// 0x82C5704 (JP heights/base differ from US)
const struct WindowTemplate sWinTemplates[] = {
    { .bg = 3, .tilemapLeft = 8, .tilemapTop = 1, .width = 21, .height = 18, .paletteNum = 15, .baseBlock = 0x0001 },
    { .bg = 1, .tilemapLeft = 9, .tilemapTop = 18, .width = 15, .height = 2, .paletteNum = 12, .baseBlock = 0x0074 },
    { .bg = 1, .tilemapLeft = 0, .tilemapTop = 2, .width = 6, .height = 14, .paletteNum = 7, .baseBlock = 0x0020 },
    { .bg = 0, .tilemapLeft = 1, .tilemapTop = 2, .width = 7, .height = 10, .paletteNum = 14, .baseBlock = 0x0013 },
    DUMMY_WIN_TEMPLATE,
};

// 0x82C572C
const struct SubtaskInfo sDisplaySubtasks[] = {
    { 0, Display_LoadGfx },
    { 3, Display_ShowKeyboardSwapMenu },
    { 4, Display_HideKeyboardSwapMenu },
    { 5, Display_SwitchPages },
    { 1, Display_MoveKeyboardCursor },
    { 6, Display_AskQuitChatting },
    { 7, Display_DestroyYesNoDialog },
    { 8, Display_UpdateMessageBuffer },
    { 9, Display_AskRegisterText },
    { 10, Display_CancelRegister },
    { 11, Display_ReturnToKeyboard },
    { 12, Display_ScrollChat },
    { 2, Display_AnimateKeyboardCursor },
    { 13, Display_PrintInputText },
    { 18, Display_PrintExitingChat },
    { 19, Display_PrintLeaderLeft },
    { 14, Display_AskSave },
    { 15, Display_AskOverwriteSave },
    { 16, Display_PrintSavingDontTurnOff },
    { 17, Display_PrintSavedTheGame },
    { 20, Display_AskConfirmLeaderLeave },
};

// 0x82C57D4: standard chat messages; first four rows are inside
// sKeyboardFunctionTexts, the rest inside gUnknown_85CC663.
const struct MessageWindowInfo sDisplayStdMessages[] = {
    { sKeyboardFunctionTexts + 0x1B, 1, 0, 0, 1, 2, 0, 0 },
    { sKeyboardFunctionTexts + 0x28, 1, 0, 0, 1, 2, 0, 0 },
    { sKeyboardFunctionTexts + 0x36, 1, 0, 0, 1, 2, 0, 0 },
    { sKeyboardFunctionTexts + 0x44, 1, 0, 0, 1, 2, 0, 0 },
    { gUnknown_85CC663 + 0x34, 2, 0, 0, 1, 2, 0, 0 },
    { gUnknown_85CC663 + 0x4F, 2, 0, 0, 0, 2, 1, 0 },
    { gUnknown_85CC663 + 0x6A, 2, 0, 0, 1, 2, 0, 1 },
    { gUnknown_85CC663 + 0x8A, 2, 0, 0, 1, 2, 0, 1 },
    { gUnknown_85CC663 + 0xAA, 2, 0, 0, 1, 2, 0, 1 },
    { gUnknown_85CC663 + 0xCE, 2, 0, 0, 1, 2, 1, 1 },
    { gUnknown_85CC663 + 0xE6, 2, 0, 0, 1, 2, 0, 1 },
};

// 0x82C5858: page title texts inside sKeyboardFunctionTexts
const struct MenuAction sKeyboardPageTitleTexts[6] = {
    { sKeyboardFunctionTexts + 0x00, NULL },
    { sKeyboardFunctionTexts + 0x05, NULL },
    { sKeyboardFunctionTexts + 0x0A, NULL },
    { sKeyboardFunctionTexts + 0x0E, NULL },
    { sKeyboardFunctionTexts + 0x12, NULL },
    { sKeyboardFunctionTexts + 0x17, NULL },
};

