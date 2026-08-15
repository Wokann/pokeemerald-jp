#include "global.h"

// Chat/trainer-card/trade reaction texts
ALIGNED(4) const u8 sText_LearnedSomethingMale[] = _(
    "なるほど！\n"
    "へー　ふむふむ\p");

ALIGNED(4) const u8 sText_ThatsFunnyMale[] = _(
    "また　へんなこと　いって\n"
    "あんまり　わらわせるなよ！\p");

ALIGNED(4) const u8 sText_RandomChatMale1[] = _(
    "へー\n"
    "そんなことが　あったんだ\p");

ALIGNED(4) const u8 sText_RandomChatMale2[] = _(
    "⋯⋯ふんふん　なに？\n"
    "と　いうことは　こういうことか？\p");

ALIGNED(4) const u8 sText_LearnedSomethingFemale[] = _(
    "⋯⋯え？\n"
    "そんなこと　しらなかったわ！\p");

ALIGNED(4) const u8 sText_ThatsFunnyFemale[] = _(
    "あはは！\n"
    "なにそれ！\p");

ALIGNED(4) const u8 sText_RandomChatFemale1[] = _(
    "あっ　そうそう！\n"
    "そのことよ！\p");

ALIGNED(4) const u8 sText_RandomChatFemale2[] = _(
    "つまりね⋯⋯\n"
    "うん！　それそれ！\p");

const u8 *const sChatReactionTexts[][4] = {
    { sText_LearnedSomethingMale, sText_ThatsFunnyMale, sText_RandomChatMale1, sText_RandomChatMale2 },
    { sText_LearnedSomethingFemale, sText_ThatsFunnyFemale, sText_RandomChatFemale1, sText_RandomChatFemale2 },
};

ALIGNED(4) const u8 sText_ShowedTrainerCardMale1[] = _(
    "いま　あいさつがわりに\n"
    "トレーナーカードを　みせてるんだ\p");

ALIGNED(4) const u8 sText_ShowedTrainerCardMale2[] = _(
    "これからも\n"
    "よろしく！\p");

ALIGNED(4) const u8 sText_ShowedTrainerCardFemale1[] = _(
    "いま　あいさつの　かわりに\n"
    "トレーナーカードを　みせあってるの\p");

ALIGNED(4) const u8 sText_ShowedTrainerCardFemale2[] = _(
    "これからも\n"
    "よろしくね！\p");

const u8 *const sTrainerCardReactionTexts[][2] = {
    { sText_ShowedTrainerCardMale1, sText_ShowedTrainerCardMale2 },
    { sText_ShowedTrainerCardFemale1, sText_ShowedTrainerCardFemale2 },
};

ALIGNED(4) const u8 sText_MaleTraded1[] = _(
    "やった！\n"
    "このポケモン　ほしかったんだ！\p");

ALIGNED(4) const u8 sText_MaleTraded2[] = _(
    "さがしてた　ポケモンを\n"
    "やっと　こうかんして　もらったよ\p\n"
    "");

ALIGNED(4) const u8 sText_FemaleTraded1[] = _(
    "いまね　ポケモンの\n"
    "こうかんを　してるの！\p");

ALIGNED(4) const u8 sText_FemaleTraded2[] = _(
    "ほしい　ポケモンが\n"
    "やっと　こうかんして　もらえたわ！\p");

const u8 *const sTradeReactionTexts[][4] = {
    { sText_MaleTraded1, sText_MaleTraded2, NULL, NULL },
    { sText_FemaleTraded1, sText_FemaleTraded2, NULL, NULL },
};

