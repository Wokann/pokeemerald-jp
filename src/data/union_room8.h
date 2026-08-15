#include "global.h"

// Wait-for-activity and show-card texts
ALIGNED(4) const u8 sText_WaitForBattleMale[] = _(
    "たいせんだね！\n"
    "よーし　ちょっと　まってて！");

ALIGNED(4) const u8 sText_WaitForChatMale[] = _(
    "チャットだね！\n"
    "わかった　ちょっと　まってて！");

ALIGNED(4) const u8 sText_ShowTrainerCardMale[] = _(
    "わかった！　じゃあ　あいさつがわりに\n"
    "トレーナーカードを　みせてあげるよ");

ALIGNED(4) const u8 sText_WaitForBattleFemale[] = _(
    "たいせんね！\n"
    "よーし　ちょっと　まってて！");

ALIGNED(4) const u8 sText_WaitForChatFemale[] = _(
    "チャットね！\n"
    "わかったわ　ちょっと　まってて！");

ALIGNED(4) const u8 sText_ShowTrainerCardFemale[] = _(
    "じゃあ　あいさつの　かわりに\n"
    "トレーナーカードを　みせてあげるね");

const u8 *const sText_WaitOrShowCardTexts[][4] = {
    { sText_WaitForBattleMale, sText_WaitForChatMale, NULL, sText_ShowTrainerCardMale },
    { sText_WaitForBattleFemale, sText_WaitForChatFemale, NULL, sText_ShowTrainerCardFemale },
};

