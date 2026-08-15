#include "global.h"

// Battle-busy, level-requirement and reaction texts
ALIGNED(4) const u8 sText_TrainerBattleBusy[] = _(
    "あ！　ごめん\n"
    "ほかに　ようじが　あるから\lまたこんどね\p");

ALIGNED(4) const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _(
    "たいせんを　するためには\n"
    "レベル30より　ひくい　ポケモンが\l2ひき　ひつよう　だよ\p");

ALIGNED(4) const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _(
    "たいせんを　するためには\n"
    "レベル30　よりひくい　ポケモンが\l2ひき　ひつようです\p");

ALIGNED(4) const u8 sText_DeclineChatMale[] = _(
    "そうか\n"
    "また　いつでも　おいでよ！\p");

ALIGNED(4) const u8 stext_DeclineChatFemale[] = _(
    "そう⋯⋯\n"
    "また　いつでも　きてね！\p");

const u8 *const sDeclineChatTexts[] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale,
};

ALIGNED(4) const u8 sText_ChatDeclinedMale[] = _(
    "あっ　ごめん！\n"
    "やっぱり　いま　つごうがわるいんだ\lまた　こんど　チャット　しような\p");

ALIGNED(4) const u8 sText_ChatDeclinedFemale[] = _(
    "ごめん！\n"
    "やっぱり　いま　つごうが　わるいの\lまた　こんど　チャット　しようね\p");

const u8 *const sChatDeclinedTexts[] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale,
};

ALIGNED(4) const u8 sText_YoureToughMale[] = _(
    "おー！\n"
    "なかなか　てごわいな！\p");

ALIGNED(4) const u8 sText_UsedGoodMoveMale[] = _(
    "ここで　そんな　わざを\n"
    "だして　くるなんて　やるな！\p");

ALIGNED(4) const u8 sText_BattleSurpriseMale[] = _(
    "さすがだ！\n"
    "そんな　たたかいかたも　あるのか！\p");

ALIGNED(4) const u8 sText_SwitchedMonsMale[] = _(
    "この　ポケモンを\n"
    "こんな　ばめんで　だしてくるとは！\p");

ALIGNED(4) const u8 sText_YoureToughFemale[] = _(
    "その　ポケモン\n"
    "すごくよく　そだてられてるね！\p");

ALIGNED(4) const u8 sText_UsedGoodMoveFemale[] = _(
    "そうよ！\n"
    "そこで　このわざよ！！\p");

ALIGNED(4) const u8 sText_BattleSurpriseFemale[] = _(
    "すごい！\n"
    "そんな　たたかいかたも　あるのね！\p");

ALIGNED(4) const u8 sText_SwitchedMonsFemale[] = _(
    "ポケモン　いれかえの　タイミングが\n"
    "ぜつみょうね！\p");

const u8 *const sBattleReactionTexts[][4] = {
    { sText_YoureToughMale, sText_UsedGoodMoveMale, sText_BattleSurpriseMale, sText_SwitchedMonsMale },
    { sText_YoureToughFemale, sText_UsedGoodMoveFemale, sText_BattleSurpriseFemale, sText_SwitchedMonsFemale },
};

