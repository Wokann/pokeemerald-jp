#include "global.h"
#include "constants/union_room.h"

// ChooseTrainer sub-texts and table
ALIGNED(4) const u8 sText_ChooseTrainerSingleBattle[] = _(
    "シングルバトルをする　ともだちを\n"
    "えらんでください");

ALIGNED(4) const u8 sText_ChooseTrainerDoubleBattle[] = _(
    "ダブルバトルをする　ともだちを\n"
    "えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderMultiBattle[] = _(
    "マルチバトル！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseTrainerToTradeWith[] = _(
    "ポケモンの　こうかんをする\n"
    "ともだちを　えらんでください");

ALIGNED(4) const u8 sText_ChooseTrainerToShareWonderCards[] = _(
    "ふしぎなカードを　くばっている\n"
    "ともだちを　えらんでください");

ALIGNED(4) const u8 sText_ChooseTrainerToShareWonderNews[] = _(
    "ふしぎなニュースを　くばっている\n"
    "ともだちを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderPokemonJump[] = _(
    "ミニポケモンでジャンプ！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderBerryCrush[] = _(
    "きのみクラッシュ！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderBerryPicking[] = _(
    "ドードリオのきのみどり！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderBerryBlender[] = _(
    "きのみブレンダー！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderRecordCorner[] = _(
    "レコードコーナー！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderCoolContest[] = _(
    "かっこよさコンテスト！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderBeautyContest[] = _(
    "うつくしさコンテスト！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderCuteContest[] = _(
    "かわいさコンテスト！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderSmartContest[] = _(
    "かしこさコンテスト！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderToughContest[] = _(
    "たくましさコンテスト！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderBattleTowerLv50[] = _(
    "バトルタワー　レベル50！\n"
    "リーダーを　えらんでください");

ALIGNED(4) const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _(
    "バトルタワー　オープンレベル！\n"
    "リーダーを　えらんでください");

const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE] = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE] = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE] = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE] = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP] = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH] = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING] = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD] = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS] = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT] = NULL,
    [LINK_GROUP_UNK_11] = NULL,
    [LINK_GROUP_RECORD_CORNER] = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER] = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14] = NULL,
    [LINK_GROUP_COOL_CONTEST] = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST] = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST] = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST] = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST] = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER] = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv,
};

