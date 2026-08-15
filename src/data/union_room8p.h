#include "global.h"

// Mystery-gift JP texts (Mg/Mevent/Stamp messages)
ALIGNED(4) const u8 sJPText_MgDontHaveCard[] = _(
    "ふしぎなカードを　もっていないので\n"
    "あたらしく　カードを　よみこみます");

ALIGNED(4) const u8 sJPText_MgDontHaveNews[] = _(
    "ふしぎなニュースを　もっていないので\n"
    "あたらしく　ニュースを　よみこみます");

ALIGNED(4) const u8 sJPText_MgWhereCard[] = _(
    "どちらから　ふしぎなカードを\n"
    "よみこみ　ますか？");

ALIGNED(4) const u8 sJPText_MgWhereNews[] = _(
    "どちらから　ふしぎなニュースを\n"
    "よみこみ　ますか？$　　つうしん　たいき　ちゅう　です\n"
    ",,,Bボタンで　キャンセル　します");

ALIGNED(4) const u8 sJPText_MgCommunicating[] = _("つうしん　しています,,,");

ALIGNED(4) const u8 sJPText_MgCommCompleted[] = _("つうしんが　しゅうりょう　しました");

ALIGNED(4) const u8 sJPText_MeventMsg11[] = _("つうしんに　しっぱい　しました");

ALIGNED(4) const u8 sJPText_MeventMsg9[] = _("つうしんを　キャンセル　しました");

ALIGNED(4) const u8 sJPText_MgThrowAwayCard[] = _(
    "いまの　ふしぎなカードを　すてて\n"
    "あたらしい　カードを　よみこみますか？");

ALIGNED(4) const u8 sJPText_MgHaventReceived[] = _(
    "まだ　カードの　おくりものを　もらって\n"
    "ませんが　ほんとうに　よみこみますか？");

ALIGNED(4) const u8 sJPText_MeventMsg2a[] = _(
    "{B_COPY_VAR_1}から　ふしぎなカードが\n"
    "おくられて　きました！");

ALIGNED(4) const u8 sJPText_MeventMsg3a[] = _(
    "{B_COPY_VAR_1}から　ニュースが\n"
    "おくられて　きました！");

ALIGNED(4) const u8 sJPText_MeventMsg2b[] = _(
    "あたらしい　ふしぎなカードが\n"
    "おくられて　きました！");

ALIGNED(4) const u8 sJPText_MeventMsg3b[] = _(
    "あたらしい　ニュースが\n"
    "おくられて　きました！");

ALIGNED(4) const u8 sJPText_MeventMsg4[] = _(
    "あたらしい　スタンプが\n"
    "おくられて　きました！");

ALIGNED(4) const u8 sJPText_MeventMsg12[] = _(
    "あたらしい　トレーナーが\n"
    "おくられて　きました！");

ALIGNED(4) const u8 sJPText_MeventMsg5[] = _(
    "おなじ　ふしぎなカードを\n"
    "すでに　もっています");

ALIGNED(4) const u8 sJPText_MeventMsg7[] = _(
    "おなじ　ニュースを\n"
    "すでに　もっています");

ALIGNED(4) const u8 sJPText_MeventMsg6[] = _(
    "おなじ　スタンプを\n"
    "すでに　もっています");

ALIGNED(4) const u8 sJPText_MeventMsg8[] = _(
    "スタンプが　いっぱい　なので\n"
    "もう　おせません！");

ALIGNED(4) const u8 sJPText_MeventMsg1[] = _(
    "じぶんの　きろくを\n"
    "ジョイスポットに　よみこませ　ました！");

ALIGNED(4) const u8 sJPText_MeventMsg10b[] = _(
    "この　あいて　からは　ふしぎなカードを\n"
    "うけとれません！");

ALIGNED(4) const u8 sJPText_MeventMsg10a[] = _(
    "この　あいて　からは　ニュースを\n"
    "うけとれません！");

ALIGNED(4) const u8 sJPText_MeventMsg0[] = _(
    "なにも　おくられて\n"
    "きません　でした");

ALIGNED(4) const u8 gText_WhatToDoWithCards[] = _("カードを　どうしますか？");

ALIGNED(4) const u8 gText_WhatToDoWithNews[] = _("ニュースを　どうしますか？");

ALIGNED(4) const u8 sJPText_MgSendingCard[] = _(
    "ふしぎなカード　を\n"
    "おくって　います,,,");

ALIGNED(4) const u8 sJPText_MgSendingNews[] = _(
    "ニュースを\n"
    "おくって　います,,,");

ALIGNED(4) const u8 sJPText_StampMsg2[] = _(
    "{B_COPY_VAR_1}に　ふしぎなカードを\n"
    "おくり　ました！");

ALIGNED(4) const u8 sJPText_StampMsg3[] = _(
    "{B_COPY_VAR_1}に　ニュース　を\n"
    "おくり　ました！");

ALIGNED(4) const u8 sJPText_StampMsg4[] = _(
    "{B_COPY_VAR_1}に　スタンプ　を\n"
    "おくり　ました！");

ALIGNED(4) const u8 sJPText_StampMsg12[] = _("{B_COPY_VAR_1}に　おくりものを　しました！");

ALIGNED(4) const u8 sJPText_StampMsg5[] = _(
    "あいてが　おなじ\n"
    "ふしぎなカードを　もっています！");

ALIGNED(4) const u8 sJPText_StampMsg7[] = _(
    "あいてが　おなじ\n"
    "ニュースを　もっています！");

ALIGNED(4) const u8 sJPText_StampMsg6[] = _(
    "あいてが　おなじ\n"
    "スタンプを　もっています！");

ALIGNED(4) const u8 sJPText_StampMsg9[] = _(
    "あいてが　つうしんを　\n"
    "キャンセル　しました");

ALIGNED(4) const u8 sJPText_StampMsg14[] = _(
    "この　あいて　には\n"
    "ふしぎなおくりものを　わたせません");

ALIGNED(4) const u8 sText_DiscardWonderCard[] = _(
    "カードをすてると　できごとも\n"
    "なくなりますが　よいですか？");

ALIGNED(4) const u8 sText_DiscardWonderNews[] = _(
    "ほんとうに　ニュースを\n"
    "すてても　よいですか？");

ALIGNED(4) const u8 sJPText_MgDiscardConfirm[] = _(
    "おくりものを　もらってません\n"
    "が　ほんとうに　すてますか？");

ALIGNED(4) const u8 sText_SavingGame1[] = _(
    "レポートを　かいています\n"
    "しばらく　おまちください");

ALIGNED(4) const u8 sText_SavingGame2[] = _(
    "レポートを　かきこみました！\n"
    "Aボタンを　おしてください");

ALIGNED(4) const u8 sText_WasThrownAwayWonderCard[] = _("ふしぎなカードを　すてました");

ALIGNED(4) const u8 sText_WasThrownAwayWonderNews[] = _("ニュースを　すてました");

ALIGNED(4) const u8 gText_MysteryGift[] = _("ふしぎなおくりもの");

ALIGNED(4) const u8 gText_PickOKExit[20] = _("{DPAD_UPDOWN}えらぶ　{A_BUTTON}けってい　{B_BUTTON}やめる");

