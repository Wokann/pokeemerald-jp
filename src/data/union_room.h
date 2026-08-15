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

