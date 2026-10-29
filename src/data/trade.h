#define GFXTAG_MENU_TEXT       200 // Used as a base tag in CB2_CreateTradeMenu and CB2_ReturnToTradeMenu
#define GFXTAG_CURSOR          300
#define GFXTAG_LINK_MON_GLOW   5550
#define GFXTAG_LINK_MON_SHADOW 5552
#define GFXTAG_CABLE_END       5554
#define GFXTAG_GBA_SCREEN      5556
#define GFXTAG_POKEBALL        5557

#define PALTAG_CURSOR    2345
#define PALTAG_MENU_TEXT 4925
#define PALTAG_LINK_MON  5551
#define PALTAG_GBA       5555
#define PALTAG_POKEBALL  5558


#define TRADE_DATA(name) __attribute__((section(".rodata.trade." #name), aligned(1)))

static const u32 sUnusedStructSizes[] TRADE_DATA(sUnusedStructSizes) =
{
    sizeof(struct SaveBlock2),
    sizeof(struct SaveBlock1),
    sizeof(struct MapHeader),
    sizeof(struct Mail),
    sizeof(struct Pokemon),
    0x00000528,
};

static const u16 sTradeMovesBoxTilemap[] TRADE_DATA(sTradeMovesBoxTilemap) = INCBIN_U16("graphics/trade/moves_box_map.bin");

static const u16 sTradePartyBoxTilemap[] TRADE_DATA(sTradePartyBoxTilemap) = INCBIN_U16("graphics/trade/party_box_map.bin");

static const u8 sTradeStripesBG2Tilemap[] TRADE_DATA(sTradeStripesBG2Tilemap) = INCBIN_U8("graphics/trade/stripes_bg2_map.bin");

static const u8 sTradeStripesBG3Tilemap[] TRADE_DATA(sTradeStripesBG3Tilemap) = INCBIN_U8("graphics/trade/stripes_bg3_map.bin");

static const struct OamData sOamData_MenuText TRADE_DATA(sOamData_MenuText) =
{
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 1,
};

static const struct OamData sOamData_Cursor TRADE_DATA(sOamData_Cursor) =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1,
};

static const union AnimCmd sAnim_Cursor_Normal[] TRADE_DATA(sAnim_Cursor_Normal) =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cursor_OnCancel[] TRADE_DATA(sAnim_Cursor_OnCancel) =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Cursor[] TRADE_DATA(sAnims_Cursor) =
{
    sAnim_Cursor_Normal,
    sAnim_Cursor_OnCancel,
};

static const struct SpriteSheet sCursor_SpriteSheet TRADE_DATA(sCursor_SpriteSheet) =
{
    .data = gTradeCursor_Gfx,
    .size = 0x800,
    .tag = GFXTAG_CURSOR,
};

static const struct SpritePalette sCursor_SpritePalette TRADE_DATA(sCursor_SpritePalette) =
{
    .data = gTradeCursor_Pal,
    .tag = PALTAG_CURSOR,
};

static const union AnimCmd sAnim_MenuText_0[] TRADE_DATA(sAnim_MenuText_0) =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_1[] TRADE_DATA(sAnim_MenuText_1) =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_2[] TRADE_DATA(sAnim_MenuText_2) =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_3[] TRADE_DATA(sAnim_MenuText_3) =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_4[] TRADE_DATA(sAnim_MenuText_4) =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_5[] TRADE_DATA(sAnim_MenuText_5) =
{
    ANIMCMD_FRAME(40, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_MenuText[] TRADE_DATA(sAnims_MenuText) =
{
    sAnim_MenuText_0,
    sAnim_MenuText_1,
    sAnim_MenuText_2,
    sAnim_MenuText_3,
    sAnim_MenuText_4,
    sAnim_MenuText_5,
};

static const struct SpriteTemplate sSpriteTemplate_Cursor TRADE_DATA(sSpriteTemplate_Cursor) =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_CURSOR,
    .oam = &sOamData_Cursor,
    .anims = sAnims_Cursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_MenuText TRADE_DATA(sSpriteTemplate_MenuText) =
{
    .tileTag = GFXTAG_MENU_TEXT,
    .paletteTag = PALTAG_MENU_TEXT,
    .oam = &sOamData_MenuText,
    .anims = sAnims_MenuText,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const u16 sMenuText_Pal[] TRADE_DATA(sMenuText_Pal) = INCGFX_U16("graphics/trade/text.pal", ".gbapal");

static const struct SpritePalette sSpritePalette_MenuText TRADE_DATA(sSpritePalette_MenuText) =
{
    .data = sMenuText_Pal,
    .tag = PALTAG_MENU_TEXT,
};

static const u8 sCursorMoveDestinations[(PARTY_SIZE * 2) + 1][4][PARTY_SIZE] TRADE_DATA(sCursorMoveDestinations) =
{
    {
        {4,  2, 12, 12, 0, 0},
        {2,  4, 12, 12, 0, 0},
        {7,  6,  1,  0, 0, 0},
        {1,  6,  7,  0, 0, 0},
    },
    {
        {5,  3, 12, 12, 0, 0},
        {3,  5, 12, 12, 0, 0},
        {0,  7,  6,  1, 0, 0},
        {6,  7,  0,  1, 0, 0},
    },
    {
        {0,  0, 0, 0, 0, 0},
        {4,  0, 0, 0, 0, 0},
        {9,  8, 7, 6, 0, 0},
        {3,  1, 0, 0, 0, 0},
    },
    {
        {1,  1, 1, 1, 0, 0},
        {5,  1, 1, 1, 0, 0},
        {2,  9, 8, 7, 0, 0},
        {8,  9, 6, 6, 0, 0},
    },
    {
        {2,  2,  2,  2, 0, 0},
        {0,  0,  0,  0, 0, 0},
        {11, 10, 9,  8, 7, 6},
        {5,  3,  1,  0, 0, 0},
    },
    {
        {3,  3, 3, 3, 0, 0},
        {1,  1, 1, 1, 0, 0},
        {4,  4, 4, 4, 0, 0},
        {10, 8, 6, 0, 0, 0},
    },
    {
        {10, 8, 12, 0, 0, 0},
        {8, 10, 12, 0, 0, 0},
        {1,  0,  0, 0, 0, 0},
        {7,  0,  1, 0, 0, 0},
    },
    {
        {12, 0, 0, 0, 0, 0},
        {9, 12, 0, 0, 0, 0},
        {6,  0, 0, 0, 0, 0},
        {0,  0, 0, 0, 0, 0},
    },
    {
        {6,  0, 0, 0, 0, 0},
        {10, 6, 0, 0, 0, 0},
        {3,  2, 1, 0, 0, 0},
        {9,  7, 0, 0, 0, 0},
    },
    {
        {7,  0, 0, 0, 0, 0},
        {11, 12, 0, 0, 0, 0},
        {8,  0, 0, 0, 0, 0},
        {2,  1, 0, 0, 0, 0},
    },
    {
        {8,  0, 0, 0, 0, 0},
        {6,  0, 0, 0, 0, 0},
        {5,  4, 3, 2, 1, 0},
        {11, 9, 7, 0, 0, 0},
    },
    {
        {9,  0, 0, 0, 0, 0},
        {12, 0, 0, 0, 0, 0},
        {10, 0, 0, 0, 0, 0},
        {4,  2, 0, 0, 0, 0},
    },
    {
        {11, 9, 7, 6, 0, 0},
        {7,  6, 0, 0, 0, 0},
        {12, 0, 0, 0, 0, 0},
        {12, 0, 0, 0, 0, 0},
    },
};

static const u8 sTradeMonSpriteCoords[(PARTY_SIZE * 2) + 1][2] TRADE_DATA(sTradeMonSpriteCoords) =
{
    { 1,  5},
    { 8,  5},
    { 1, 10},
    { 8, 10},
    { 1, 15},
    { 8, 15},
    {16,  5},
    {23,  5},
    {16, 10},
    {23, 10},
    {16, 15},
    {23, 15},
    {23, 18},
};

static const u8 sTradeMonLevelCoords[PARTY_SIZE * 2][2] TRADE_DATA(sTradeMonLevelCoords) =
{
    { 5,  4},
    {12,  4},
    { 5,  9},
    {12,  9},
    { 5, 14},
    {12, 14},
    {20,  4},
    {27,  4},
    {20,  9},
    {27,  9},
    {20, 14},
    {27, 14},
};

static const u8 sTradeMonBoxCoords[PARTY_SIZE * 2][2] TRADE_DATA(sTradeMonBoxCoords) =
{
    { 1,  3},
    { 8,  3},
    { 1,  8},
    { 8,  8},
    { 1, 13},
    { 8, 13},
    {16,  3},
    {23,  3},
    {16,  8},
    {23,  8},
    {16, 13},
    {23, 13},
};

static const u8 sUnusedCoords[][2] TRADE_DATA(sUnusedCoords) =
{
    { 0, 14},
    {15, 29},
    { 3,  5},
    { 3,  7},
    {18,  5},
    {18,  7},
    { 8,  7},
    {22, 12},
    { 8,  7},
    {22, 12},
    { 6,  7},
    {24, 12},
    { 6,  7},
    {24, 12},
    { 8,  7},
    {22, 12},
    { 7,  7},
    {23, 12},
};

static const u8 sText_EmptyString[] TRADE_DATA(sText_EmptyString) = _("");

static const u8 sText_UnusedTextFormat[] TRADE_DATA(sText_UnusedTextFormat) = _("{COLOR 0x01}{HIGHLIGHT 0x00}{SHADOW 0x02}");

const u8 gText_MaleSymbol4[] TRADE_DATA(gText_MaleSymbol4) = _("♂");

const u8 gText_FemaleSymbol4[] TRADE_DATA(gText_FemaleSymbol4) = _("♀");

const u8 gText_GenderlessSymbol[] TRADE_DATA(gText_GenderlessSymbol) = _("");

static const u8 sText_UnusedEmpty[] TRADE_DATA(sText_UnusedEmpty) = _("");

static const u8 sText_SpaceMove[] TRADE_DATA(sText_SpaceMove) = _("わざ");

static const u8 sText_NewLine[] TRADE_DATA(sText_NewLine) = _("\n");

static const u8 sText_Slash[] TRADE_DATA(sText_Slash) = _("/");

static const u8 sText_Lv[] TRADE_DATA(sText_Lv) = _("Lv");

static const u8 sText_ThreeDashes[] TRADE_DATA(sText_ThreeDashes) = _("ーーー");

static const u8 sText_FourQuestionMarks[] TRADE_DATA(sText_FourQuestionMarks) = _("？？？？");

static const u8 sText_TradeAnd[] TRADE_DATA(sText_TradeAnd) = _("と　");

static const u8 sText_IsThisTradeOkay[] TRADE_DATA(sText_IsThisTradeOkay) = _("を　こうかんしますか？");

static const u8 sText_Cancel[] TRADE_DATA(sText_Cancel) = _("やめる");

static const u8 sText_ChooseAPkmn[] TRADE_DATA(sText_ChooseAPkmn) = _("ポケモンを　えらんで　ください");

static const u8 sText_Summary[] TRADE_DATA(sText_Summary) = _("つよさをみる");

static const u8 sText_Trade[] TRADE_DATA(sText_Trade) = _("こうかんにだす");

static const u8 sText_CancelTrade[] TRADE_DATA(sText_CancelTrade) = _("こうかん　を　やめますか？");

static const u8 sText_PressBButtonToQuit[] TRADE_DATA(sText_PressBButtonToQuit) = _("Bボタン　で　もどります");

static const u8 *const sActionTexts[] TRADE_DATA(sActionTexts) =
{
    [TEXT_CANCEL]       = sText_Cancel,
    [TEXT_CHOOSE_MON]   = sText_ChooseAPkmn,
    [TEXT_SUMMARY]      = sText_Summary,
    [TEXT_TRADE]        = sText_Trade,
    [TEXT_CANCEL_TRADE] = sText_CancelTrade,
    [TEXT_JP_QUIT]      = sText_PressBButtonToQuit,
};

static const u8 sText_Summary2[] TRADE_DATA(sText_Summary2) = _("ステータスをみる");

static const u8 sText_Trade2[] TRADE_DATA(sText_Trade2) = _("こうかんにだす");

static const struct MenuAction sSelectTradeMonActions[] TRADE_DATA(sSelectTradeMonActions) =
{
    {sText_Summary2, {Task_DrawSelectionSummary}},
    {sText_Trade2,   {Task_DrawSelectionTrade}},
};

static const u8 sText_CommunicationStandby[] TRADE_DATA(sText_CommunicationStandby) = _("{COLOR 0x02}{HIGHLIGHT 0x01}{SHADOW 0x03}つうしんたいきちゅう！\nしばらくおまちください");

static const u8 sText_TheTradeHasBeenCanceled[] TRADE_DATA(sText_TheTradeHasBeenCanceled) = _("{COLOR 0x02}{HIGHLIGHT 0x01}{SHADOW 0x03}こうかんは\nキャンセル　されました！");

static const u8 sText_OnlyPkmnForBattle[] TRADE_DATA(sText_OnlyPkmnForBattle) = _("{COLOR 0x02}{HIGHLIGHT 0x01}{SHADOW 0x03}そのポケモンを　こうかんすると\nせんとうできなくなっちゃうよ！");

static const u8 sText_WaitingForYourFriend[] TRADE_DATA(sText_WaitingForYourFriend) = _("{COLOR 0x02}{HIGHLIGHT 0x01}{SHADOW 0x03}ともだちの　しゅうりょうを\nまっています⋯⋯");

static const u8 sText_YourFriendWantsToTrade[] TRADE_DATA(sText_YourFriendWantsToTrade) = _("ともだちは　ポケモンの\nこうかんを　したいようです！");

static const u8 *const sMessages[] TRADE_DATA(sMessages) =
{
    [MSG_STANDBY]                    = sText_CommunicationStandby,
    [MSG_CANCELED]                   = sText_TheTradeHasBeenCanceled,
    [MSG_ONLY_MON1]                  = sText_OnlyPkmnForBattle,
    [MSG_ONLY_MON2]                  = gText_OnlyPkmnForBattle,
    [MSG_WAITING_FOR_FRIEND]         = sText_WaitingForYourFriend,
    [MSG_FRIEND_WANTS_TO_TRADE]      = sText_YourFriendWantsToTrade,
    [MSG_MON_CANT_BE_TRADED]         = gText_PkmnCantBeTradedNow,
    [MSG_EGG_CANT_BE_TRADED]         = gText_EggCantBeTradedNow,
    [MSG_FRIENDS_MON_CANT_BE_TRADED] = gText_OtherTrainersPkmnCantBeTraded,
};

static const u8 sTradeTextColors[] TRADE_DATA(sTradeTextColors) =
{
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_DARK_GRAY,
};

static const struct BgTemplate sBgTemplates[] TRADE_DATA(sBgTemplates) =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 5,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sWindowTemplates[] TRADE_DATA(sWindowTemplates) =
{
    { .bg = 0, .tilemapLeft = 7,  .tilemapTop = 7,  .width = 16, .height = 4, .paletteNum = 15, .baseBlock = 30  },
    { .bg = 0, .tilemapLeft = 19, .tilemapTop = 15, .width = 10, .height = 4, .paletteNum = 15, .baseBlock = 94  },
    { .bg = 0, .tilemapLeft = 1,  .tilemapTop = 5,  .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 134 },
    { .bg = 0, .tilemapLeft = 8,  .tilemapTop = 5,  .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 146 },
    { .bg = 0, .tilemapLeft = 1,  .tilemapTop = 10, .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 158 },
    { .bg = 0, .tilemapLeft = 8,  .tilemapTop = 10, .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 170 },
    { .bg = 0, .tilemapLeft = 1,  .tilemapTop = 15, .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 182 },
    { .bg = 0, .tilemapLeft = 8,  .tilemapTop = 15, .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 194 },
    { .bg = 0, .tilemapLeft = 16, .tilemapTop = 5,  .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 206 },
    { .bg = 0, .tilemapLeft = 23, .tilemapTop = 5,  .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 218 },
    { .bg = 0, .tilemapLeft = 16, .tilemapTop = 10, .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 230 },
    { .bg = 0, .tilemapLeft = 23, .tilemapTop = 10, .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 242 },
    { .bg = 0, .tilemapLeft = 16, .tilemapTop = 15, .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 254 },
    { .bg = 0, .tilemapLeft = 23, .tilemapTop = 15, .width = 6,  .height = 2, .paletteNum = 13, .baseBlock = 266 },
    { .bg = 0, .tilemapLeft = 2,  .tilemapTop = 5,  .width = 12, .height = 2, .paletteNum = 13, .baseBlock = 278 },
    { .bg = 0, .tilemapLeft = 3,  .tilemapTop = 8,  .width = 11, .height = 8, .paletteNum = 15, .baseBlock = 302 },
    { .bg = 0, .tilemapLeft = 17, .tilemapTop = 5,  .width = 12, .height = 2, .paletteNum = 15, .baseBlock = 390 },
    { .bg = 0, .tilemapLeft = 18, .tilemapTop = 8,  .width = 11, .height = 8, .paletteNum = 15, .baseBlock = 414 },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sTradeYesNoWindowTemplate TRADE_DATA(sTradeYesNoWindowTemplate) =
{
    .bg = 0,
    .tilemapLeft = 23,
    .tilemapTop = 13,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 502
};

// JP retains these trade diagnostics at this position.
static const u8 sTradeDebugTextPool[140] TRADE_DATA(sTradeDebugTextPool) = __(
    "K　START$"
    "かいめの　そうしん$"
    "　　　かいめの　じゅしん$"
    "　　　ポケモンアイコンセット$"
    "　OBJテキストセット$"
    "　　セルセット$"
    "　　　　　　　OBJテキストADD$"
    "　　システムメッセージADD$"
    "はいけいセット$"
    "　　　　　こうかんせいりつ　　　　　$"
    "だめだたらしいよ　　　　　$");

static const u8 sSelectedMonLevelGenderCoords[2][2] TRADE_DATA(sSelectedMonLevelGenderCoords) =
{
    [TRADE_PLAYER]  = {4,  3},
    [TRADE_PARTNER] = {19, 3}
};

static const u16 sPokeball_Pal[] TRADE_DATA(sPokeball_Pal) = INCGFX_U16("graphics/trade/pokeball.png", ".gbapal");

static const u8 sPokeball_Gfx[] TRADE_DATA(sPokeball_Gfx) = INCGFX_U8("graphics/trade/pokeball.png", ".4bpp");

static const u8 sPokeballSymbol_Gfx[] TRADE_DATA(sPokeballSymbol_Gfx) = INCGFX_U8("graphics/trade/pokeball_symbol.png", ".8bpp");

static const u16 sCableCloseup_Map[] TRADE_DATA(sCableCloseup_Map) = INCBIN_U16("graphics/trade/crossing_highlight_cable.bin");

static const u16 sPokeballSymbol_Map[] TRADE_DATA(sPokeballSymbol_Map) = INCBIN_U16("graphics/trade/pokeball_symbol_map.bin");

static const u16 sUnusedPal1[] TRADE_DATA(sUnusedPal1) = INCGFX_U16("graphics/trade/unused1.pal", ".gbapal");

static const u16 sGba_Pal[] TRADE_DATA(sGba_Pal) = INCGFX_U16("graphics/trade/gba.pal", ".gbapal");

static const u16 sUnusedPal2[] TRADE_DATA(sUnusedPal2) = INCGFX_U16("graphics/trade/unused2.pal", ".gbapal");

static const u16 sWirelessSignalNone_Pal_Unused[] TRADE_DATA(sWirelessSignalNone_Pal_Unused) = INCGFX_U16("graphics/trade/wireless_signal_none.pal", ".gbapal");

static const u16 sLinkMon_Pal[] TRADE_DATA(sLinkMon_Pal) = INCGFX_U16("graphics/trade/link_mon.pal", ".gbapal");

static const u8 sLinkMonGlow_Gfx[] TRADE_DATA(sLinkMonGlow_Gfx) = INCGFX_U8("graphics/trade/link_mon_glow.png", ".4bpp");

static const u8 sLinkMonShadow_Gfx[] TRADE_DATA(sLinkMonShadow_Gfx) = INCGFX_U8("graphics/trade/link_mon_shadow.png", ".4bpp");

static const u8 sCableEnd_Gfx[] TRADE_DATA(sCableEnd_Gfx) = INCGFX_U8("graphics/trade/cable_end.png", ".4bpp");

static const u8 sGbaScreen_Gfx[] TRADE_DATA(sGbaScreen_Gfx) = INCGFX_U8("graphics/trade/gba_screen.png", ".4bpp");

const u16 gTradePlatform_Tilemap[] TRADE_DATA(gTradePlatform_Tilemap) = INCBIN_U16("graphics/trade/platform.bin");

static const u8 sGbaAffine_Gfx[] TRADE_DATA(sGbaAffine_Gfx) = INCGFX_U8("graphics/trade/gba_affine.png", ".8bpp");

static const u8 sEmptyGfx[64] TRADE_DATA(sEmptyGfx) = {};

static const u8 sGbaAffineMapCable[] TRADE_DATA(sGbaAffineMapCable) = INCBIN_U8("graphics/trade/gba_affine_map_cable.bin");

static const u8 sGbaAffineMapWireless[] TRADE_DATA(sGbaAffineMapWireless) = INCBIN_U8("graphics/trade/gba_affine_map_wireless.bin");

static const u16 sGbaMapWireless[] TRADE_DATA(sGbaMapWireless) = INCBIN_U16("graphics/trade/gba_map_wireless.bin");

static const u16 sGbaMapCable[] TRADE_DATA(sGbaMapCable) = INCBIN_U16("graphics/trade/gba_map_cable.bin");

static const u32 sWirelessCloseup_Map[] TRADE_DATA(sWirelessCloseup_Map) = INCGFX_U32("graphics/trade/crossing_highlight_wireless.bin", ".lz");

static const u16 sWirelessSignalSend_Pal[] TRADE_DATA(sWirelessSignalSend_Pal) = INCGFX_U16("graphics/trade/wireless_signal_send.pal", ".gbapal");

static const u16 sWirelessSignalRecv_Pal[] TRADE_DATA(sWirelessSignalRecv_Pal) = INCGFX_U16("graphics/trade/wireless_signal_receive.pal", ".gbapal");

static const u16 sWirelessSignalNone_Pal[] TRADE_DATA(sWirelessSignalNone_Pal) = INCGFX_U16("graphics/trade/wireless_signal_none.pal", ".gbapal");

static const u32 sWirelessSignal_Gfx[] TRADE_DATA(sWirelessSignal_Gfx) = INCGFX_U32("graphics/trade/wireless_signal.png", ".4bpp.lz");

static const u32 sWirelessSignal_Tilemap[] TRADE_DATA(sWirelessSignal_Tilemap) = INCGFX_U32("graphics/trade/wireless_signal.bin", ".lz");

static const struct OamData sOamData_Pokeball TRADE_DATA(sOamData_Pokeball) =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16)
};

static const union AnimCmd sAnim_Pokeball_SpinOnce[] TRADE_DATA(sAnim_Pokeball_SpinOnce) =
{
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_FRAME( 4, 3),
    ANIMCMD_FRAME( 8, 3),
    ANIMCMD_FRAME(12, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(20, 3),
    ANIMCMD_FRAME(24, 3),
    ANIMCMD_FRAME(28, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(36, 3),
    ANIMCMD_FRAME(40, 3),
    ANIMCMD_FRAME(44, 3),
    ANIMCMD_LOOP(1),
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pokeball_SpinTwice[] TRADE_DATA(sAnim_Pokeball_SpinTwice) =
{
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_FRAME( 4, 3),
    ANIMCMD_FRAME( 8, 3),
    ANIMCMD_FRAME(12, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(20, 3),
    ANIMCMD_FRAME(24, 3),
    ANIMCMD_FRAME(28, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(36, 3),
    ANIMCMD_FRAME(40, 3),
    ANIMCMD_FRAME(44, 3),
    ANIMCMD_LOOP(2),
    ANIMCMD_FRAME( 0, 3),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Pokeball[] TRADE_DATA(sAnims_Pokeball) =
{
    sAnim_Pokeball_SpinOnce,
    sAnim_Pokeball_SpinTwice
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Normal[] TRADE_DATA(sAffineAnim_Pokeball_Normal) =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 1),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Squish[] TRADE_DATA(sAffineAnim_Pokeball_Squish) =
{
    AFFINEANIMCMD_FRAME(-8, 0, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Pokeball_Unsquish[] TRADE_DATA(sAffineAnim_Pokeball_Unsquish) =
{
    AFFINEANIMCMD_FRAME(0x60, 0x100, 0,  0),
    AFFINEANIMCMD_FRAME(   0,     0, 0,  5),
    AFFINEANIMCMD_FRAME(   8,     0, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sAffineAnims_Pokeball[] TRADE_DATA(sAffineAnims_Pokeball) =
{
    sAffineAnim_Pokeball_Normal,
    sAffineAnim_Pokeball_Squish,
    sAffineAnim_Pokeball_Unsquish
};

static const struct SpriteSheet sPokeBallSpriteSheet TRADE_DATA(sPokeBallSpriteSheet) =
{
    .data = sPokeball_Gfx,
    .size = sizeof(sPokeball_Gfx),
    .tag = GFXTAG_POKEBALL
};

static const struct SpritePalette sPokeBallSpritePalette TRADE_DATA(sPokeBallSpritePalette) =
{
    .data = sPokeball_Pal,
    .tag = PALTAG_POKEBALL
};

static const struct SpriteTemplate sSpriteTemplate_Pokeball TRADE_DATA(sSpriteTemplate_Pokeball) =
{
    .tileTag = GFXTAG_POKEBALL,
    .paletteTag = PALTAG_POKEBALL,
    .oam = &sOamData_Pokeball,
    .anims = sAnims_Pokeball,
    .images = NULL,
    .affineAnims = sAffineAnims_Pokeball,
    .callback = SpriteCB_BouncingPokeball
};

static const struct OamData sOamData_LinkMonGlow TRADE_DATA(sOamData_LinkMonGlow) =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_BLEND,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1
};

static const union AnimCmd sAnim_LinkMonGlow[] TRADE_DATA(sAnim_LinkMonGlow) =
{
    ANIMCMD_FRAME(0, 5, .hFlip = TRUE, .vFlip = TRUE), // ? The graphic is a perfect circle, no need to flip
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_LinkMonGlow[] TRADE_DATA(sAnims_LinkMonGlow) =
{
    sAnim_LinkMonGlow
};

static const union AffineAnimCmd sAffineAnim_LinkMonGlow[] TRADE_DATA(sAffineAnim_LinkMonGlow) =
{
    AFFINEANIMCMD_FRAME(-10, -10, 0, 5),
    AFFINEANIMCMD_FRAME(10, 10, 0, 5),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sAffineAnims_LinkMonGlow[] TRADE_DATA(sAffineAnims_LinkMonGlow) =
{
    sAffineAnim_LinkMonGlow
};

static const struct SpriteSheet sSpriteSheet_LinkMonGlow TRADE_DATA(sSpriteSheet_LinkMonGlow) =
{
    .data = sLinkMonGlow_Gfx,
    .size = sizeof(sLinkMonGlow_Gfx),
    .tag = GFXTAG_LINK_MON_GLOW
};

static const struct SpritePalette sSpritePalette_LinkMon TRADE_DATA(sSpritePalette_LinkMon) =
{
    .data = sLinkMon_Pal,
    .tag = PALTAG_LINK_MON
};

static const struct SpritePalette sSpritePalette_Gba TRADE_DATA(sSpritePalette_Gba) =
{
    .data = sGba_Pal,
    .tag = PALTAG_GBA
};

static const struct SpriteTemplate sSpriteTemplate_LinkMonGlow TRADE_DATA(sSpriteTemplate_LinkMonGlow) =
{
    .tileTag = GFXTAG_LINK_MON_GLOW,
    .paletteTag = PALTAG_LINK_MON,
    .oam = &sOamData_LinkMonGlow,
    .anims = sAnims_LinkMonGlow,
    .images = NULL,
    .affineAnims = sAffineAnims_LinkMonGlow,
    .callback = SpriteCB_LinkMonGlow
};

static const struct OamData sOamData_LinkMonShadow TRADE_DATA(sOamData_LinkMonShadow) =
{
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 1
};

static const union AnimCmd sAnim_LinkMonShadow_Big[] TRADE_DATA(sAnim_LinkMonShadow_Big) =
{
    ANIMCMD_FRAME(0, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd sAnim_LinkMonShadow_Small[] TRADE_DATA(sAnim_LinkMonShadow_Small) =
{
    ANIMCMD_FRAME(8, 5, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_LinkMonShadow[] TRADE_DATA(sAnims_LinkMonShadow) =
{
    [ANIM_LINKMON_BIG]   = sAnim_LinkMonShadow_Big,
    [ANIM_LINKMON_SMALL] = sAnim_LinkMonShadow_Small
};

static const struct SpriteSheet sSpriteSheet_LinkMonShadow TRADE_DATA(sSpriteSheet_LinkMonShadow) =
{
    .data = sLinkMonShadow_Gfx,
    .size = 0x300,
    .tag = GFXTAG_LINK_MON_SHADOW
};

static const struct SpriteTemplate sSpriteTemplate_LinkMonShadow TRADE_DATA(sSpriteTemplate_LinkMonShadow) =
{
    .tileTag = GFXTAG_LINK_MON_SHADOW,
    .paletteTag = PALTAG_LINK_MON,
    .oam = &sOamData_LinkMonShadow,
    .anims = sAnims_LinkMonShadow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_LinkMonShadow
};

static const struct OamData sOamData_CableEnd TRADE_DATA(sOamData_CableEnd) =
{
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 1
};

static const union AnimCmd sAnim_CableEnd[] TRADE_DATA(sAnim_CableEnd) =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_CableEnd[] TRADE_DATA(sAnims_CableEnd) =
{
    sAnim_CableEnd
};

static const struct SpriteSheet sSpriteSheet_CableEnd TRADE_DATA(sSpriteSheet_CableEnd) =
{
    .data = sCableEnd_Gfx,
    .size = 0x100,
    .tag = GFXTAG_CABLE_END
};

static const struct SpriteTemplate sSpriteTemplate_CableEnd TRADE_DATA(sSpriteTemplate_CableEnd) =
{
    .tileTag = GFXTAG_CABLE_END,
    .paletteTag = PALTAG_GBA,
    .oam = &sOamData_CableEnd,
    .anims = sAnims_CableEnd,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CableEndSending
};

static const struct OamData sOamData_GbaScreen TRADE_DATA(sOamData_GbaScreen) =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd sAnim_GbaScreen_Long[] TRADE_DATA(sAnim_GbaScreen_Long) =
{
    ANIMCMD_FRAME( 0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME( 0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_LOOP(8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_GbaScreen_Short[] TRADE_DATA(sAnim_GbaScreen_Short) =
{
    ANIMCMD_FRAME( 0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(64, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME(32, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_FRAME( 0, 2, .vFlip = TRUE, .hFlip = TRUE),
    ANIMCMD_LOOP(2),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_GbaScreen_Long[] TRADE_DATA(sAnims_GbaScreen_Long) =
{
    sAnim_GbaScreen_Long
};

static const union AnimCmd *const sAnims_GbaScreen_Short[] TRADE_DATA(sAnims_GbaScreen_Short) =
{
    sAnim_GbaScreen_Short
};

static const struct SpriteSheet sSpriteSheet_GbaScreen TRADE_DATA(sSpriteSheet_GbaScreen) =
{
    .data = sGbaScreen_Gfx,
    .size = sizeof(sGbaScreen_Gfx),
    .tag = GFXTAG_GBA_SCREEN
};

static const struct SpriteTemplate sSpriteTemplate_GbaScreenFlash_Long TRADE_DATA(sSpriteTemplate_GbaScreenFlash_Long) =
{
    .tileTag = GFXTAG_GBA_SCREEN,
    .paletteTag = PALTAG_GBA,
    .oam = &sOamData_GbaScreen,
    .anims = sAnims_GbaScreen_Long,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_GbaScreen
};

static const struct SpriteTemplate sSpriteTemplate_GbaScreenFlash_Short TRADE_DATA(sSpriteTemplate_GbaScreenFlash_Short) =
{
    .tileTag = GFXTAG_GBA_SCREEN,
    .paletteTag = PALTAG_GBA,
    .oam = &sOamData_GbaScreen,
    .anims = sAnims_GbaScreen_Short,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_GbaScreen
};

static const u16 sLinkMonShadow_Pal[] TRADE_DATA(sLinkMonShadow_Pal) = INCGFX_U16("graphics/trade/link_mon_shadow.pal", ".gbapal");

static const union AffineAnimCmd sAffineAnim_CrossingMonPic[] TRADE_DATA(sAffineAnim_CrossingMonPic) =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sAffineAnims_CrossingMonPics[] TRADE_DATA(sAffineAnims_CrossingMonPics) =
{
    sAffineAnim_CrossingMonPic
};

static const struct InGameTrade sIngameTrades[] TRADE_DATA(sIngameTrades) =
{
    {
        .nickname = _("セブン"),
        .species = SPECIES_SEEDOT,
        .ivs = {5, 4, 5, 4, 4, 4},
        .abilityNum = 1,
        .otId = 38726,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 132,
        .heldItem = ITEM_CHESTO_BERRY,
        .mailNum = 0xFF,
        .otName = _("マッチャン"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_RALTS,
    },
    {
        .nickname = _("プラプラ"),
        .species = SPECIES_PLUSLE,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 73996,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 111,
        .heldItem = ITEM_WOOD_MAIL,
        .mailNum = 0,
        .otName = _("アッキー"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_VOLBEAT,
    },
    {
        .nickname = _("ゴロー"),
        .species = SPECIES_HORSEA,
        .ivs = {5, 4, 4, 4, 5, 4},
        .abilityNum = 0,
        .otId = 46285,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 127,
        .heldItem = ITEM_WAVE_MAIL,
        .mailNum = 1,
        .otName = _("ソガチン"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_BAGON,
    },
    {
        .nickname = _("チー"),
        .species = SPECIES_MEOWTH,
        .ivs = {4, 5, 4, 5, 4, 4},
        .abilityNum = 0,
        .otId = 91481,
        .conditions = {5, 5, 5, 30, 5},
        .personality = 139,
        .heldItem = ITEM_RETRO_MAIL,
        .mailNum = 2,
        .otName = _("マリッペ"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_SKITTY,
    },
};

static const u16 sIngameTradeMail[][MAIL_WORDS_COUNT + 1] TRADE_DATA(sIngameTradeMail) =
{
    {0x0161, 0x0829, 0x1033, 0x0182, 0x1034, 0x270E, 0x140C, 0x1239, 0x081A, 0x0000},
    {0x018B, 0x1619, 0x1042, 0x2A74, 0x0E29, 0x180F, 0x140C, 0x1621, 0x1032, 0x0000},
    {0x013B, 0x0800, 0x0C01, 0x2A34, 0x1034, 0x262D, 0x1421, 0x0418, 0x103E, 0x0000},
};

static const struct WindowTemplate sTradeSequenceWindowTemplates[] TRADE_DATA(sTradeSequenceWindowTemplates) =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 0,
        .baseBlock = 64
    },
    DUMMY_WIN_TEMPLATE
};

const struct WindowTemplate gTradeEvolutionSceneYesNoWindowTemplate TRADE_DATA(gTradeEvolutionSceneYesNoWindowTemplate) =
{
    .bg = 0,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 188
};

static const struct BgTemplate sTradeSequenceBgTemplates[] TRADE_DATA(sTradeSequenceBgTemplates) =
{
    {
        .bg = 0,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 5,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 18,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 6,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const s8 sTradeBallVerticalVelocityTable[] TRADE_DATA(sTradeBallVerticalVelocityTable) =
{
     0,  0,  1,  0,  1,  0,  1,  1,  1,
     1,  2,  2,  2,  2,  3,  3,  3,  3,
     4,  4,  4,  4, -4, -4, -4, -3, -3,
    -3, -3, -2, -2, -2, -2, -1, -1, -1,
    -1,  0, -1,  0, -1,  0,  0,  0,  0,
     0,  1,  0,  1,  0,  1,  1,  1,  1,
     2,  2,  2,  2,  3,  3,  3,  3,  4,
     4,  4,  4, -4, -3, -3, -2, -2, -1,
    -1, -1,  0, -1,  0,  0,  0,  0,  0,
     0,  1,  0,  1,  1,  1,  2,  2,  3,
     3,  4, -4, -3, -2, -1, -1, -1,  0,
     0,  0,  0,  1,  0,  1,  1,  2,  3
};

static const u8 sWirelessSignalAnimParams[][2] TRADE_DATA(sWirelessSignalAnimParams) =
{
    { 0,  1},
    { 1,  1},
    { 2,  1},
    { 3,  1},
    { 4,  1},
    { 5,  2},
    { 6,  2},
    { 7,  2},
    { 8,  2},
    { 9,  2},
    {10,  3},
    {11,  3},
    {12,  3},
    {13,  4},
    {14,  5},
    {15,  2},
    { 0,  1},
    { 1,  1},
    { 2,  1},
    { 3,  1},
    { 4,  1},
    { 5,  2},
    { 6,  2},
    { 7,  2},
    { 8,  2},
    { 9,  2},
    {10,  3},
    {11,  3},
    {12,  3},
    {13,  4},
    {14,  5},
    {16,  1},
    {16, -1},
    {}
};
