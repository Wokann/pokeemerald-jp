// JP Trade resources retain original ROM order. Verified menu resources use
// their semantic names; only the unclassified JP-only suffix remains address-named.

#define TRADE_UNUSED_STRUCT_SIZES __attribute__((section(".rodata.trade_unused_struct_sizes"), aligned(1)))
#define TRADE_MENU_RESOURCES __attribute__((section(".rodata.trade_menu_resources"), aligned(1)))
#define TRADE_MENU_RESOURCES_AFTER_MON_BOX __attribute__((section(".rodata.trade_menu_resources_after_mon_box"), aligned(1)))
#define TRADE_ANIMATION_TEXT_RESOURCES __attribute__((section(".rodata.trade_animation_text_resources"), aligned(1)))
#define TRADE_ANIMATION_RESOURCES __attribute__((section(".rodata.trade_animation_resources"), aligned(1)))
#define TRADE_POST_ANIMATION_RESOURCES __attribute__((section(".rodata.trade_post_animation_resources"), aligned(1)))

#define GFXTAG_MENU_TEXT 200
#define GFXTAG_CURSOR    300

#define PALTAG_CURSOR    2345
#define PALTAG_MENU_TEXT 4925

// Exists unused in Ruby/Sapphire as well. The final literal is 0x528 in JP.
static const u32 sUnusedStructSizes[] TRADE_UNUSED_STRUCT_SIZES __attribute__((used)) =
{
    sizeof(struct SaveBlock2),
    sizeof(struct SaveBlock1),
    sizeof(struct MapHeader),
    sizeof(struct Mail),
    sizeof(struct Pokemon),
    0x00000528,
};

const u16 sTradeMovesBoxTilemap[] TRADE_MENU_RESOURCES = INCBIN_U16("graphics/trade/moves_box_map.bin");
const u16 sTradePartyBoxTilemap[] TRADE_MENU_RESOURCES = INCBIN_U16("graphics/trade/party_box_map.bin");
const u8 sTradeStripesBG2Tilemap[] TRADE_MENU_RESOURCES = INCBIN_U8("graphics/trade/stripes_bg2_map.bin");
const u8 sTradeStripesBG3Tilemap[] TRADE_MENU_RESOURCES = INCBIN_U8("graphics/trade/stripes_bg3_map.bin");

const u8 gTradeCursor_Gfx[] TRADE_MENU_RESOURCES_AFTER_MON_BOX = INCGFX_U8("graphics/trade/cursor.png", ".4bpp");

// This unreferenced JP palette is retained in place until its owner is known.
// The original ROM sets bit 15 in most entries, so preserve literal u16 data.
static const u16 sUnusedTradePalette[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    0x9999, 0x9999, 0x9999, 0x9999,
    0x9999, 0x9999, 0x9999, 0x9999,
    0x9999, 0x9999, 0x9999, 0x9999,
    0x9999, 0x0999, 0x9999, 0x0099,
};

static const struct OamData sOamData_MenuText TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 1,
};

static const struct OamData sOamData_Cursor TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1,
};

static const union AnimCmd sAnim_Cursor_Normal[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_Cursor_OnCancel[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_Cursor[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    sAnim_Cursor_Normal,
    sAnim_Cursor_OnCancel,
};

const struct SpriteSheet sCursor_SpriteSheet TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    .data = gTradeCursor_Gfx,
    .size = 0x800,
    .tag = GFXTAG_CURSOR,
};

const struct SpritePalette sCursor_SpritePalette TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    .data = &gTradeMenu_Pal[0x30],
    .tag = PALTAG_CURSOR,
};

static const union AnimCmd sAnim_MenuText_0[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_1[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_2[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_3[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    ANIMCMD_FRAME(24, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_4[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_MenuText_5[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    ANIMCMD_FRAME(40, 5),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_MenuText[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    sAnim_MenuText_0,
    sAnim_MenuText_1,
    sAnim_MenuText_2,
    sAnim_MenuText_3,
    sAnim_MenuText_4,
    sAnim_MenuText_5,
};

const struct SpriteTemplate sSpriteTemplate_Cursor TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_CURSOR,
    .oam = &sOamData_Cursor,
    .anims = sAnims_Cursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct SpriteTemplate sSpriteTemplate_MenuText TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    .tileTag = GFXTAG_MENU_TEXT,
    .paletteTag = PALTAG_MENU_TEXT,
    .oam = &sOamData_MenuText,
    .anims = sAnims_MenuText,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// The original JP menu-text palette also sets bit 15 in several entries.
// Literal u16 data avoids losing that byte-exact information during conversion.
static const u16 sMenuText_Pal[] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    0x0000, 0x2529, 0x001F, 0x03E0,
    0x7C00, 0x03FF, 0x7FE0, 0x7C1F,
    0x675A, 0x0000, 0x0000, 0x0000,
    0x7FFF, 0x0000, 0x39CE, 0x7FFF,
};

const struct SpritePalette sSpritePalette_MenuText TRADE_MENU_RESOURCES_AFTER_MON_BOX =
{
    .data = sMenuText_Pal,
    .tag = PALTAG_MENU_TEXT,
};

// This determines the next available party slot after D-Pad input. Positions
// 0-5 are the player, 6-11 are the partner, and 12 is Cancel.
const u8 sCursorMoveDestinations[(PARTY_SIZE * 2) + 1][4][PARTY_SIZE] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
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

const u8 sTradeMonSpriteCoords[(PARTY_SIZE * 2) + 1][2] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
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

const u8 sTradeMonLevelCoords[PARTY_SIZE * 2][2] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
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

const u8 sTradeMonBoxCoords[PARTY_SIZE * 2][2] TRADE_MENU_RESOURCES_AFTER_MON_BOX =
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

static const u8 sUnusedCoords[][2] TRADE_MENU_RESOURCES_AFTER_MON_BOX __attribute__((used)) =
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

const u8 sText_IsThisTradeOkay[] TRADE_ANIMATION_TEXT_RESOURCES = _("を　こうかんしますか？");
static const u8 sText_Cancel[] TRADE_ANIMATION_TEXT_RESOURCES = _("やめる");
static const u8 sText_ChooseAPkmn[] TRADE_ANIMATION_TEXT_RESOURCES = _("ポケモンを　えらんで　ください");
static const u8 sText_Summary[] TRADE_ANIMATION_TEXT_RESOURCES = _("つよさをみる");
static const u8 sText_Trade[] TRADE_ANIMATION_TEXT_RESOURCES = _("こうかんにだす");
static const u8 sText_CancelTrade[] TRADE_ANIMATION_TEXT_RESOURCES = _("こうかん　を　やめますか？");
static const u8 sJPText_PressBButtonToQuit[] TRADE_ANIMATION_TEXT_RESOURCES = _("Bボタン　で　もどります");

const u8 *const sActionTexts[] TRADE_ANIMATION_RESOURCES =
{
    [TEXT_CANCEL]       = sText_Cancel,
    [TEXT_CHOOSE_MON]   = sText_ChooseAPkmn,
    [TEXT_SUMMARY]      = sText_Summary,
    [TEXT_TRADE]        = sText_Trade,
    [TEXT_CANCEL_TRADE] = sText_CancelTrade,
    [TEXT_JP_QUIT]      = sJPText_PressBButtonToQuit,
};

static const u8 sText_Summary2[] TRADE_ANIMATION_RESOURCES = _("ステータスをみる");
static const u8 sText_Trade2[] TRADE_ANIMATION_RESOURCES = _("こうかんにだす");

const struct MenuAction sSelectTradeMonActions[] TRADE_ANIMATION_RESOURCES =
{
    {sText_Summary2, {Task_DrawSelectionSummary}},
    {sText_Trade2,   {Task_DrawSelectionTrade}},
};

static const u8 sText_CommunicationStandby[] TRADE_ANIMATION_RESOURCES = _("{COLOR 0x02}{HIGHLIGHT 0x01}{SHADOW 0x03}つうしんたいきちゅう！\nしばらくおまちください");
static const u8 sText_TheTradeHasBeenCanceled[] TRADE_ANIMATION_RESOURCES = _("{COLOR 0x02}{HIGHLIGHT 0x01}{SHADOW 0x03}こうかんは\nキャンセル　されました！");
static const u8 sText_OnlyPkmnForBattle[] TRADE_ANIMATION_RESOURCES = _("{COLOR 0x02}{HIGHLIGHT 0x01}{SHADOW 0x03}そのポケモンを　こうかんすると\nせんとうできなくなっちゃうよ！");
static const u8 sText_WaitingForYourFriend[] TRADE_ANIMATION_RESOURCES = _("{COLOR 0x02}{HIGHLIGHT 0x01}{SHADOW 0x03}ともだちの　しゅうりょうを\nまっています⋯⋯");
static const u8 sText_YourFriendWantsToTrade[] TRADE_ANIMATION_RESOURCES = _("ともだちは　ポケモンの\nこうかんを　したいようです！");

// These shared messages remain in their own text owner. Use its actual JP
// labels here instead of adding temporary aliases.
const u8 *const sTradeMessages[] TRADE_ANIMATION_RESOURCES =
{
    [MSG_STANDBY]                    = sText_CommunicationStandby,
    [MSG_CANCELED]                   = sText_TheTradeHasBeenCanceled,
    [MSG_ONLY_MON1]                  = sText_OnlyPkmnForBattle,
    [MSG_ONLY_MON2]                  = gUnknown_85CA294,
    [MSG_WAITING_FOR_FRIEND]         = sText_WaitingForYourFriend,
    [MSG_FRIEND_WANTS_TO_TRADE]      = sText_YourFriendWantsToTrade,
    [MSG_MON_CANT_BE_TRADED]         = gUnknown_85CA2B4,
    [MSG_EGG_CANT_BE_TRADED]         = gUnknown_85CA2CC,
    [MSG_FRIENDS_MON_CANT_BE_TRADED] = gUnknown_85CA2CC + 0x14,
};

const u8 sTradeTextColors[] TRADE_ANIMATION_RESOURCES =
{
    TEXT_COLOR_TRANSPARENT,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_DARK_GRAY,
};

const struct BgTemplate sTradeBgTemplates[] TRADE_ANIMATION_RESOURCES =
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

const struct WindowTemplate sTradeWindowTemplates[] TRADE_ANIMATION_RESOURCES =
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

const u8 gUnknown_8300CAC[0x94] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300cac.bin");
const u8 gUnknown_8300D40[0x2024] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8300d40.bin");
const u8 gUnknown_8302D64[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8302d64.bin");
const u8 gUnknown_8304D04[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8304d04.bin");
const u8 gUnknown_8305D24[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8305d24.bin");
const u8 gUnknown_8305D84[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8305d84.bin");
const u8 gUnknown_83071A4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/83071a4.bin");
const u8 gUnknown_83099E4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/83099e4.bin");
const u8 gUnknown_8309AE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8309ae4.bin");
const u8 gUnknown_8309BE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/8309be4.bin");
const u8 gUnknown_830ABE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830abe4.bin");
const u8 gUnknown_830BBE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830bbe4.bin");
const u8 gUnknown_830BCE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830bce4.bin");
const u8 gUnknown_830BEE4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830bee4.bin");
const u8 gUnknown_830C0E4[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830c0e4.bin");
const u8 gUnknown_830C104[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830c104.bin");
const u8 gUnknown_830C794[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830c794.bin");
const u8 gUnknown_830CF5C[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cf5c.bin");
const u8 gUnknown_830CF64[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cf64.bin");
const u8 gUnknown_830CF6C[0x48] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cf6c.bin");
const u8 gUnknown_830CFB4[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cfb4.bin");
const u8 gUnknown_830CFBC[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cfbc.bin");
const u8 gUnknown_830CFC4[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cfc4.bin");
const u8 gUnknown_830CFCC[0x38] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830cfcc.bin");
const u8 gUnknown_830D004[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d004.bin");
const u8 gUnknown_830D00C[0x2C] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d00c.bin");
const u8 gUnknown_830D038[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d038.bin");
const u8 gUnknown_830D040[0x70] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d040.bin");
const u8 gUnknown_830D0B0[0x8] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d0b0.bin");
const u8 gUnknown_830D0B8[0x18] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d0b8.bin");
const u8 gUnknown_830D0D0[0x18] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d0d0.bin");
const u8 gUnknown_830D0E8[] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d0e8.bin");
const u8 gUnknown_830D110[0x4] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d110.bin");
const u8 gUnknown_830D114[0xF0] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d114.bin");
const u8 gUnknown_830D204[0x3C] TRADE_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d204.bin");

// This short block follows region_texts49 and precedes the Berry Blender data.
const u8 gUnknown_830D26A[0x12] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d26a.bin");
const u8 gUnknown_830D27C[0x10] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/menu/830d27c.bin");
const u8 gUnknown_830D28C[0x8] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/menu/830d28c.bin");
const u8 gUnknown_830D294[0x10] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/menu/830d294.bin");
const u8 gUnknown_830D2A4[0x6C] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d2a4.bin");
const u8 gUnknown_830D310[0x44] TRADE_POST_ANIMATION_RESOURCES = INCBIN_U8("graphics/trade/jp/animation/830d310.bin");

#undef TRADE_UNUSED_STRUCT_SIZES
#undef TRADE_MENU_RESOURCES
#undef TRADE_MENU_RESOURCES_AFTER_MON_BOX
#undef TRADE_ANIMATION_RESOURCES
#undef TRADE_POST_ANIMATION_RESOURCES
