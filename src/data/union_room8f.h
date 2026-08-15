#include "global.h"

// Trade-requirement texts and ChooseTrainer
ALIGNED(4) const u8 sText_DontHaveEggTrainerWants[] = _(
    "{B_COPY_VAR_1}の　ほしがっている\n"
    "タマゴを　もっていません\p");

ALIGNED(4) const u8 sText_PlayerCantTradeForYourMon[] = _(
    "いまは　{B_COPY_VAR_1}は　あなたの\n"
    "ポケモンと　こうかんできません\p");

ALIGNED(4) const u8 sText_CantTradeForPartnersMon[] = _(
    "{B_COPY_VAR_1}の　ポケモンとは\n"
    "いまは　こうかんできません\p");

const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon,
};

ALIGNED(4) const u8 sText_TradeOfferRejected[] = _(
    "こうかんを\n"
    "ことわられ　ました\p");

ALIGNED(4) const u8 sText_EggTrade[] = _("タマゴのこうかん");

ALIGNED(4) const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}えらぶ:{A_BUTTON}さんかする:{B_BUTTON}やめる");

ALIGNED(4) const u8 sText_ChooseTrainer[16] = _("ともだちを　えらんでください");

