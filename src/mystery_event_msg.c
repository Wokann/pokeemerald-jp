#include "global.h"

#define MYSTERY_EVENT_MSG __attribute__((section(".rodata.mystery_event_msg")))

const u8 gText_MysteryEventBerry[] MYSTERY_EVENT_MSG = _(
    "{B_COPY_VAR_2}のみを　てに　いれた！\n"
    "トウカジムの　パパから　うけとろう！");

const u8 gText_MysteryEventBerryTransform[] MYSTERY_EVENT_MSG = _(
    "{B_COPY_VAR_1}のみは\n"
    "{B_COPY_VAR_2}のみに　へんかした！");

const u8 gText_MysteryEventBerryObtained[] MYSTERY_EVENT_MSG = _(
    "{B_COPY_VAR_1}のみは　すでに\n"
    "はいっていた");

const u8 gText_MysteryEventSpecialRibbon[] MYSTERY_EVENT_MSG = _(
    "てもちのポケモンに\n"
    "とくべつなリボンが　あたえられた！");

const u8 sMEScrCmdEnableresetrtcText[] MYSTERY_EVENT_MSG = _(
    "ずかんに　ぜんこくモードが\n"
    "ついか　された！");

const u8 gText_MysteryEventRareWord[] MYSTERY_EVENT_MSG = _(
    "めずらしい　ことばを　ついかしました");

const u8 gText_MysteryEventSentOver[] MYSTERY_EVENT_MSG = _(
    "{B_COPY_VAR_1}が　おくられてきた！");

const u8 gText_MysteryEventFullParty[] MYSTERY_EVENT_MSG = _(
    "てもちが　いっぱいなので\n"
    "{B_COPY_VAR_1}は　もらえなかった⋯");

const u8 gText_MysteryEventNewTrainer[] MYSTERY_EVENT_MSG = _(
    "あらたな　トレーナーが\n"
    "ホウエンに　やってきた");

const u8 gText_MysteryEventNewAdversaryInBattleTower[] MYSTERY_EVENT_MSG = _(
    "バトルタワーに　あらたな\n"
    "たいせんしゃが　あらわれた！");

const u8 gText_MysteryEventCantBeUsed[] MYSTERY_EVENT_MSG = _(
    "このデータは　このバージョンでは\n"
    "しよう　できません");

#undef MYSTERY_EVENT_MSG
