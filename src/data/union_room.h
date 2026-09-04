#include "global.h"

// RFU assert and debug strings (JP-specific section at 0x82C053C)
const char sAssertFile_rfu[8] = {"rfu.c"};

const char sAssertExpr_RfuFuncNull[20] = {"Rfu.RfuFunc == NULL"};

const char sAssertExpr_SizeLe252[12] = {"size<=252"};

const char sASCII_PokemonSioInfo[15] = {"PokemonSioInfo"};

ALIGNED(4) const u8 sJPText_Akito[] = _("あきと");

const char sASCII_LinkLossDisconnect[] = {"LINK LOSS DISCONNECT!"};

ALIGNED(4) const char sASCII_LinkLossRecoveryNow[] = {"LINK LOSS RECOVERY NOW"};

ALIGNED(4) const char sASCII_30Spaces[] = {"                              "};

const char sASCII_15Spaces[] = {"               "};

const char sASCII_8Spaces[] = {"        "};

const char sASCII_Space[] = {" "};

const char sASCII_Asterisk[] = {"*"};

const char sASCII_NowSlot[] = {"NOWSLOT"};

const char sASCII_ClockCmds[][12] = {
    "           ",
    "CLOCK DRIFT",
    "BUSY SEND  ",
    "CMD REJECT ",
    "CLOCK SLAVE",
};

const char sASCII_ChildParentSearch[][8] = {
    "CHILD ",
    "PARENT",
    "SEARCH",
};

const u8 sText_EmptyString[] = {0xFF, 0x00, 0x00, 0x00};

ALIGNED(4) const u8 sText_Colon[] = _(":");

ALIGNED(4) const u8 sText_ID[] = _("{ID}");

ALIGNED(4) const u8 sText_PleaseStartOver[] = _(
    "もういちど　さいしょから\n"
    "てつづきを　やりなおして　ください");

ALIGNED(4) const u8 sText_WirelessSearchCanceled[] = _(
    "ジョイスポットの　けんさくを\n"
    "ちゅうししました$ともだちからの　れんらくを\n"
    "まっています");

ALIGNED(4) const u8 sText_AwaitingCommunication[28] = _(
    "{B_COPY_VAR_1}！\n"
    "ともだちからの　れんらくを　まっています");

// Keep these JP link-group texts in their original ROM order after the
// wireless debug data. The separate section preserves the former mid1 slot.
#define UNION_ROOM_LINK_WAITING_DATA __attribute__((section(".rodata.union_room_link_waiting_data"), aligned(1)))
#define UNION_ROOM_LINK_WAITING_DATA_ALIGNED __attribute__((section(".rodata.union_room_link_waiting_data"), aligned(4)))

const u8 sText_AwaitingLinkPressStart[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _(
    "{B_COPY_VAR_1}！　れんらくまち！\n"
    "にんずうが　そろったら　STARTボタン");

static const u8 sJPText_SingleBattle[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("シングルバトルを　かいさいする");
static const u8 sJPText_DoubleBattle[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("ダブルバトルを　かいさいする");
static const u8 sJPText_MultiBattle[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("マルチバトルを　かいさいする");
static const u8 sJPText_TradePokemon[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("ポケモンこうかんを　かいさいする");
static const u8 sJPText_Chat[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("チャットを　かいさいする");
static const u8 sJPText_DistWonderCard[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("ふしぎなカードをくばる");
static const u8 sJPText_DistWonderNews[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("ふしぎなニュースをくばる");
static const u8 sJPText_DistMysteryEvent[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("ふしぎなできごとを　かいさいする");
static const u8 sJPText_HoldPokemonJump[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("なわとびを　かいさいする");
static const u8 sJPText_HoldBerryCrush[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("きのみマッシャーを　かいさいする");
static const u8 sJPText_HoldBerryPicking[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("きのみどりを　かいさいする");
static const u8 sJPText_HoldSpinTrade[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("ぐるぐるこうかんを　かいさいする");
static const u8 sJPText_HoldSpinShop[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = _("ぐるぐるショップを　かいさいする");

// Unused in JP, but the pointer table is part of the original Union Room data.
static const u8 *const sJPLinkGroupActionTexts[] UNION_ROOM_LINK_WAITING_DATA_ALIGNED = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop,
};

const u8 sText_1PlayerNeeded[] UNION_ROOM_LINK_WAITING_DATA = _("あと1にん\nひつよう");
const u8 sText_2PlayersNeeded[] UNION_ROOM_LINK_WAITING_DATA = _("あと2にん\nひつよう");
const u8 sText_3PlayersNeeded[] UNION_ROOM_LINK_WAITING_DATA = _("あと3にん\nひつよう");
const u8 sText_4PlayersNeeded[] UNION_ROOM_LINK_WAITING_DATA = _("あと4にん\nひつよう");
const u8 sText_2PlayerMode[] UNION_ROOM_LINK_WAITING_DATA = _("2にん\nプレイ");
const u8 sText_3PlayerMode[] UNION_ROOM_LINK_WAITING_DATA = _("3にん\nプレイ");
const u8 sText_4PlayerMode[] UNION_ROOM_LINK_WAITING_DATA = _("4にん\nプレイ");
const u8 sText_5PlayerMode[] UNION_ROOM_LINK_WAITING_DATA = _("5にん\nプレイ");

#undef UNION_ROOM_LINK_WAITING_DATA_ALIGNED
#undef UNION_ROOM_LINK_WAITING_DATA
