#include "global.h"

// Invitation and chat texts
ALIGNED(4) const u8 sText_ShowTrainerCard[] = _(
    "あいてが　トレーナーカードを\n"
    "みせて　きました\pこちらも　トレーナーカードを\n"
    "みせますか？");

ALIGNED(4) const u8 sText_BattleChallenge[] = _(
    "あいてが　たいせんを\n"
    "もうしこんで　きました\pたいせん　しますか？");

ALIGNED(4) const u8 sText_ChatInvitation[] = _(
    "あいてが　チャット　に\n"
    "さそって　きました\pいっしょに　チャット\n"
    "しますか？");

ALIGNED(4) const u8 sText_OfferToTradeMon[] = _(
    "とうろく　していた\n"
    "LV{DYNAMIC 0}の　{DYNAMIC 1}　と\pLV{DYNAMIC 2}の　{DYNAMIC 3}　の\n"
    "こうかん　もうしこみが　きています\pこうかん　しますか？");

ALIGNED(4) const u8 sText_OfferToTradeEgg[] = _(
    "とうろく　していた　タマゴの\n"
    "こうかん　もうしこみが　きています\lこうかん　しますか？");

ALIGNED(4) const u8 sText_ChatDropped[] = _("かいわが　きれました\p");

ALIGNED(4) const u8 sText_OfferDeclined1[] = _(
    "もうしこみを\n"
    "ことわり　ました\p");

ALIGNED(4) const u8 sText_OfferDeclined2[] = _(
    "おさそいを\n"
    "ことわり　ました\p");

ALIGNED(4) const u8 sText_ChatEnded[] = _("かいわを　きりました\p");

const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon,
};

ALIGNED(4) const u8 sText_JoinChatMale[] = _(
    "お！　いま　おれたち\n"
    "チャットちゅう　なんだ！\lよかったら　いっしょに　はいるかい？");

ALIGNED(4) const u8 sText_JoinChatFemale[] = _(
    "{B_COPY_VAR_1}‘お！　{MUS_RG_VS_TRAINER}\n"
    "いま　チャットちゅう　なんだ！\lよかったら　いっしょに　はいるかい？");

ALIGNED(4) const u8 sText_PlayerJoinChatMale[] = _(
    "あ！　いまね　わたしたち\n"
    "チャット　してるんだ\lよかったら　いっしょに　しない？");

ALIGNED(4) const u8 sText_PlayerJoinChatFemale[] = _(
    "{B_COPY_VAR_1}‘あ！　{MUS_RG_VS_TRAINER}\n"
    "いまね　チャット　してるんだ\lよかったら　いっしょに　しない？");

const u8 *const sJoinChatTexts[] = {
    sText_JoinChatMale,
    sText_PlayerJoinChatMale,
    sText_JoinChatFemale,
    sText_PlayerJoinChatFemale,
};

ALIGNED(4) const u8 sText_TrainerAppearsBusy[24] = _(
    "⋯⋯\n"
    "いまは　とりこみちゅうの　ようだ\p");

