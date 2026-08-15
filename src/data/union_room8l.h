#include "global.h"

// Trainer-card info texts and glad-to-meet table
ALIGNED(4) const u8 sText_TrainerCardInfoPage1[] = _(
    "{DYNAMIC 0}の　{DYNAMIC 1}の\n"
    "トレーナーカードを　みせてもらった\l{DYNAMIC 2}\pポケモンずかん　{DYNAMIC 3}\n"
    "プレイ　じかん　{DYNAMIC 4}:{DYNAMIC 5}\p");

ALIGNED(4) const u8 sText_TrainerCardInfoPage2[] = _(
    "たいせん　かち{DYNAMIC 0}　まけ{DYNAMIC 2}\n"
    "こうかん　{DYNAMIC 3}かい\p‘{DYNAMIC 4}　{DYNAMIC 5}\n"
    "　{DYNAMIC 6}　{DYNAMIC 7}\p${DYNAMIC 1}‘これからも　よろしく！{PAUSE 60}$　　{DYNAMIC 1}‘これからも　よろしくね！{PAUSE 60}");

const u8 *const sGladToMeetYouTexts[2] = {
    sText_TrainerCardInfoPage2 + 0x28,
    sText_TrainerCardInfoPage2 + 0x3C,
};

ALIGNED(4) const u8 sText_FinishedCheckingPlayersTrainerCard[] = _(
    "{DYNAMIC 1}の　トレーナーカードを\n"
    "みおわった！{PAUSE 60}");

