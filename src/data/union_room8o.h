#include "global.h"
#include "list_menu.h"
#include "window.h"
#include "text.h"

// Mystery-gift window templates, list menus and JP texts
// (0x82C24D4..0x82C26C4)

// 0x82C24D4
const struct WindowTemplate sWindowTemplate_YesNoMsg_Wide = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00E5,
};

// 0x82C24DC
const struct WindowTemplate sWindowTemplate_YesNoMsg = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 20,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00E5,
};

// 0x82C24E4
const struct WindowTemplate sWindowTemplate_GiftSelect = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 19,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x00E5,
};

// 0x82C24EC
const struct WindowTemplate sWindowTemplate_ThreeOptions = {
    .bg = 0,
    .tilemapLeft = 8,
    .tilemapTop = 6,
    .width = 14,
    .height = 6,
    .paletteNum = 12,
    .baseBlock = 0x0155,
};

// 0x82C24F4
const struct WindowTemplate sWindowTemplate_YesNoBox = {
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 15,
    .width = 5,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x0155,
};

// 0x82C24FC (JP width 6, US 7)
const struct WindowTemplate sWindowTemplate_GiftSelect_3Options = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 11,
    .width = 6,
    .height = 8,
    .paletteNum = 12,
    .baseBlock = 0x0155,
};

// 0x82C2504 (JP width 6, US 7)
const struct WindowTemplate sWindowTemplate_GiftSelect_2Options = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 13,
    .width = 6,
    .height = 6,
    .paletteNum = 12,
    .baseBlock = 0x0155,
};

// 0x82C250C (JP width 6, US 7)
const struct WindowTemplate sWindowTemplate_GiftSelect_1Option = {
    .bg = 0,
    .tilemapLeft = 22,
    .tilemapTop = 15,
    .width = 6,
    .height = 4,
    .paletteNum = 12,
    .baseBlock = 0x0155,
};

// 0x82C2514..0x82C253C: list-menu item texts
ALIGNED(4) const u8 sText_MgWonderCards[] = _("ふしぎなカード");
ALIGNED(4) const u8 sText_MgWonderNews[] = _("ふしぎなニュース");
ALIGNED(4) const u8 sText_MgWirelessCommunication[] = _("ジョイスポット");
ALIGNED(4) const u8 sText_MgFriend2[] = _("ともだち");
ALIGNED(4) const u8 sText_MgCancel2[] = _("やめる");

// 0x82C253C
const struct ListMenuItem sListMenuItems_CardsOrNews[] = {
    { sText_MgWonderCards, 0 },
    { sText_MgWonderNews, 1 },
    { sText_MgCancel2, LIST_CANCEL },
};

// 0x82C2554
const struct ListMenuItem sListMenuItems_WirelessOrFriend[] = {
    { sText_MgWirelessCommunication, 0 },
    { sText_MgFriend2, 1 },
    { sText_MgCancel2, LIST_CANCEL },
};

// 0x82C256C
const struct ListMenuTemplate sListMenuTemplate_ThreeOptions = {
    .items = NULL,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 11,
    .cursor_X = 1,
    .upText_Y = 2,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW,
};

// 0x82C2584..0x82C2594
ALIGNED(4) const u8 sText_MgReceive[] = _("よみこむ");
ALIGNED(4) const u8 sText_MgSend[] = _("おくる");
ALIGNED(4) const u8 sText_MgToss[] = _("すてる");

// 0x82C2594
const struct ListMenuItem sListMenuItems_ReceiveSendToss[] = {
    { sText_MgReceive, 0 },
    { sText_MgSend, 1 },
    { sText_MgToss, 2 },
    { sText_MgCancel2, LIST_CANCEL },
};

// 0x82C25B4
const struct ListMenuItem sListMenuItems_ReceiveToss[] = {
    { sText_MgReceive, 0 },
    { sText_MgToss, 2 },
    { sText_MgCancel2, LIST_CANCEL },
};

// 0x82C25CC
const struct ListMenuItem sListMenuItems_ReceiveSend[] = {
    { sText_MgReceive, 0 },
    { sText_MgSend, 1 },
    { sText_MgCancel2, LIST_CANCEL },
};

// 0x82C25E4
const struct ListMenuItem sListMenuItems_Receive[] = {
    { sText_MgReceive, 0 },
    { sText_MgCancel2, LIST_CANCEL },
};

// 0x82C25F4
const struct ListMenuTemplate sListMenu_ReceiveSendToss = {
    .items = sListMenuItems_ReceiveSendToss,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 4,
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 10,
    .cursor_X = 1,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW,
};

// 0x82C260C
const struct ListMenuTemplate sListMenu_ReceiveToss = {
    .items = sListMenuItems_ReceiveToss,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 10,
    .cursor_X = 1,
    .upText_Y = 2,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW,
};

// 0x82C2624
const struct ListMenuTemplate sListMenu_ReceiveSend = {
    .items = sListMenuItems_ReceiveSend,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 10,
    .cursor_X = 1,
    .upText_Y = 2,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW,
};

// 0x82C263C
const struct ListMenuTemplate sListMenu_Receive = {
    .items = sListMenuItems_Receive,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 2,
    .maxShowed = 2,
    .windowId = 0,
    .header_X = 0,
    .item_X = 10,
    .cursor_X = 1,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 1,
    .itemVerticalPadding = 1,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW,
};

// 0x82C2654..0x82C26B4: JP-only mystery-gift info texts and their table
ALIGNED(4) const u8 sJPText_MgReadWirelessEvents[] = _(
    "ワイヤレスで　いろいろな　できごとを\n"
    "よみこみます");
ALIGNED(4) const u8 sJPText_MgViewCards[] = _(
    "もっている　ふしぎなカードを\n"
    "みることが　できます");
ALIGNED(4) const u8 sJPText_MgViewNews[] = _(
    "おくられてきた　ニュースを\n"
    "みることが　できます");
ALIGNED(4) const u8 sJPText_MgReturnToTitle[] = _("タイトルに　もどります");

// 0x82C26B4
const u8 *const sJPText_MgTexts[] = {
    sJPText_MgReadWirelessEvents,
    sJPText_MgViewCards,
    sJPText_MgViewNews,
    sJPText_MgReturnToTitle,
};
