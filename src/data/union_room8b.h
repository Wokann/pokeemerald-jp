#include "global.h"

// Start-activity and battle-declined texts
ALIGNED(4) const u8 sText_WaitForChatMale2[] = _(
    "チャットだね！\n"
    "わかった　ちょっと　まってて！");

ALIGNED(4) const u8 sText_DoneWaitingBattleMale[] = _(
    "またせたね！\n"
    "それじゃあ　たいせん　しようか！{PAUSE 60}");

ALIGNED(4) const u8 sText_DoneWaitingChatMale[] = _(
    "よし！　じゃあ　いっしょに\n"
    "チャット　しようぜ！{PAUSE 60}");

ALIGNED(4) const u8 sText_DoneWaitingBattleFemale[] = _(
    "おまたせ！\n"
    "それじゃあ　はじめましょう！{PAUSE 60}");

ALIGNED(4) const u8 sText_DoneWaitingChatFemale[] = _(
    "おまたせ！　じゃあ　いっしょに\n"
    "チャット　しましょう！{PAUSE 60}");

ALIGNED(4) const u8 sText_TradeWillBeStarted[] = _(
    "こうかんを\n"
    "かいし　します{PAUSE 60}");

ALIGNED(4) const u8 sText_BattleWillBeStarted[] = _(
    "たいせんを\n"
    "かいし　します！{PAUSE 60}");

ALIGNED(4) const u8 sText_EnteringChat[] = _(
    "チャットを\n"
    "かいし　します！{PAUSE 60}");

const u8 *const sStartActivityTexts[][2][3] = {
    {
        { sText_BattleWillBeStarted, sText_EnteringChat, sText_TradeWillBeStarted },
        { sText_BattleWillBeStarted, sText_EnteringChat, sText_TradeWillBeStarted },
    }, {
        { sText_DoneWaitingBattleMale, sText_DoneWaitingChatMale, sText_TradeWillBeStarted },
        { sText_DoneWaitingBattleFemale, sText_DoneWaitingChatFemale, sText_TradeWillBeStarted },
    }
};

ALIGNED(4) const u8 sText_BattleDeclinedMale[] = _(
    "ごめん！　ちょっと　ポケモンの\n"
    "ちょうしが　わるい　みたいなんだ\lまた　こんど　たいせん　しよう\p");

ALIGNED(4) const u8 sText_BattleDeclinedFemale[] = _(
    "ごめんなさい！\n"
    "ちょっと　ポケモンの　ちょうしが\lわるい　みたいなの⋯⋯\pまた　こんど\n"
    "たいせん　しようね！\p");

const u8 *const sBattleDeclinedTexts[] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale,
};

ALIGNED(4) const u8 sText_ShowTrainerCardDeclinedMale[] = _(
    "あれ！？　トレーナーカードが\n"
    "みあたらない　なあ\lごめん！　またこんどね\p");

ALIGNED(4) const u8 sText_ShowTrainerCardDeclinedFemale[] = _(
    "あれ！？　トレーナーカード\n"
    "どこ　いったかな？⋯⋯\lごめん！　またこんどね\p");

const u8 *const sShowTrainerCardDeclinedTexts[] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale,
};

ALIGNED(4) const u8 sText_IfYouWantToDoSomethingMale[] = _(
    "なにか　したくなったら\n"
    "また　こえを　かけてくれよ\p");

ALIGNED(4) const u8 sText_IfYouWantToDoSomethingFemale[] = _(
    "なにか　したくなったら\n"
    "また　こえを　かけてね！\p");

const u8 *const sIfYouWantToDoSomethingTexts[] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale,
};

