#include "global.h"
#include "strings.h"
#include "battle_pyramid_bag.h"
#include "item_menu.h"
#include "constants/songs.h"

#define STRINGS_FISHING_BITE __attribute__((section(".rodata.strings_fishing_bite"), aligned(1)))
#define STRINGS_FISHING_MESSAGES __attribute__((section(".rodata.strings_fishing_messages"), aligned(1)))
#define STRINGS_SAVING_STATUS __attribute__((section(".rodata.strings_saving_status"), aligned(1)))
#define STRINGS_DECIMAL_POINT __attribute__((section(".rodata.strings_decimal_point"), aligned(1)))
#define STRINGS_QUESTION_MARKS __attribute__((section(".rodata.strings_question_marks"), aligned(1)))
#define STRINGS_CONTEST_RESULTS __attribute__((section(".rodata.strings_contest_results"), aligned(1)))

#define STRINGS_EREADER_TEXT __attribute__((section(".rodata.strings_ereader_text"), aligned(1)))
#define STRINGS_MINIGAME_TEXT __attribute__((section(".rodata.strings_minigame_text"), aligned(1)))
#define STRINGS_SHARED_MISC_TEXT __attribute__((section(".rodata.strings_shared_misc_text"), aligned(1)))
#define STRINGS_FRONTIER_RECORD_TEXT __attribute__((section(".rodata.strings_frontier_record_text"), aligned(1)))
#define STRINGS_BATTLE_FACTORY_SWAP_TEXT __attribute__((section(".rodata.strings_battle_factory_swap_text"), aligned(1)))
#define STRINGS_POKENAV_SHARED_TEXT __attribute__((section(".rodata.strings_pokenav_shared_text"), aligned(1)))
#define STRINGS_CHAT_PROFILE_TEXT __attribute__((section(".rodata.strings_chat_profile_text"), aligned(1)))
#define STRINGS_EGG_HATCH_TEXT __attribute__((section(".rodata.strings_egg_hatch_text")))
#define STRINGS_BERRY_CRUSH_TEXT __attribute__((section(".rodata.strings_berry_crush_text")))
#define STRINGS_FRONTIER_PASS_TEXT __attribute__((section(".rodata.strings_frontier_pass_text"), aligned(1)))
#define STRINGS_MYSTERY_EVENT_TEXT __attribute__((section(".rodata.strings_mystery_event_text"), aligned(1)))
#define STRINGS_TRAINER_STATUS_TEXT __attribute__((section(".rodata.strings_trainer_status_text"), aligned(1)))
#define STRINGS_INTERFACE_TEXT __attribute__((section(".rodata.strings_interface_text"), aligned(1)))
#define STRINGS_COMMON __attribute__((section(".rodata.strings_common")))
#define STRINGS_BIRCH_MENU __attribute__((section(".rodata.strings_birch_menu"), aligned(1)))
#define STRINGS_POKEDEX __attribute__((section(".rodata.strings_pokedex"), aligned(1)))
#define STRINGS_HOF_TEXT __attribute__((section(".rodata.strings_hall_of_fame"), aligned(1)))
#define STRINGS_POKEBLOCK_TEXT __attribute__((section(".rodata.strings_pokeblock_text"), aligned(1)))
#define STRINGS_SHOP_TEXT __attribute__((section(".rodata.strings_shop_text"), aligned(1)))
#define STRINGS_PARTY_MENU_TEXT __attribute__((section(".rodata.strings_party_menu_text"), aligned(1)))
#define STRINGS_TRADE_TEXT_PREFIX __attribute__((section(".rodata.strings_trade_text_prefix"), aligned(1)))
#define STRINGS_TRADE_TEXT_BODY_START __attribute__((section(".rodata.strings_trade_text_body"), aligned(4)))
#define STRINGS_TRADE_TEXT_BODY __attribute__((section(".rodata.strings_trade_text_body"), aligned(1)))
#define STRINGS_SUMMARY_TEXT __attribute__((section(".rodata.strings_summary_text"), aligned(1)))
#define STRINGS_MAIN_MENU __attribute__((section(".rodata.strings_main_menu")))
#define STRINGS_NAMING_SCREEN_TEXT __attribute__((section(".rodata.strings_naming_screen_text"), aligned(1)))
#define STRINGS_NAMING_SCREEN_LEGACY __attribute__((section(".rodata.strings_naming_screen_legacy"), aligned(1)))
#define STRINGS_EASY_CHAT_MESSAGES __attribute__((section(".rodata.strings_easy_chat_messages"), aligned(1)))
#define STRINGS_EASY_CHAT __attribute__((section(".rodata.strings_easy_chat")))
#define STRINGS_SCRIPT_MENU_TEXT __attribute__((section(".rodata.strings_script_menu_text"), aligned(1)))
#define STRINGS_ELEVATOR_TEXT __attribute__((section(".rodata.strings_elevator_text"), aligned(1)))
#define STRINGS_MENU_PRICE_TEXT __attribute__((section(".rodata.strings_menu_price_text"), aligned(1)))
#define STRINGS_POKENAV_STORAGE __attribute__((section(".rodata.strings_pokenav_storage"), aligned(1)))
#define STRINGS_CLEAR_SAVE __attribute__((section(".rodata.strings_clear_save")))
#define STRINGS_DAYCARE __attribute__((section(".rodata.strings_daycare")))
#define STRINGS_BAG_RETURN_TEXT __attribute__((section(".rodata.strings_bag_return_text"), aligned(1)))
#define STRINGS_BAG_RETURN_TABLES __attribute__((section(".rodata.strings_bag_return_tables")))
#define STRINGS_ITEM_MENU_TEXT __attribute__((section(".rodata.strings_item_menu_text"), aligned(1)))
#define STRINGS_MENU_YES_NO __attribute__((section(".rodata.strings_menu_yes_no"), aligned(1)))
#define STRINGS_MENU_SELECTOR_ARROW3 __attribute__((section(".rodata.strings_menu_selector_arrow3"), aligned(1)))
#define STRINGS_BATTLE_FACTORY_SELECTION __attribute__((section(".rodata.strings_battle_factory_selection"), aligned(1)))
#define STRINGS_DECORATION_TEXT __attribute__((section(".rodata.strings_decoration_text"), aligned(1)))
#define STRINGS_PC_TEXT __attribute__((section(".rodata.strings_pc_text"), aligned(1)))
#define STRINGS_SHARED_NAME_TEXT __attribute__((section(".rodata.strings_shared_name_text"), aligned(1)))
#define STRINGS_MOVE_RELEARNER_TEXT __attribute__((section(".rodata.strings_move_relearner_text"), aligned(1), used))
#define STRINGS_DIPLOMA_TEXT __attribute__((section(".rodata.strings_diploma_text"), aligned(1), used))
#define STRINGS_EXPANDED_PLACEHOLDER_TEXT __attribute__((section(".rodata.strings_expanded_placeholder_text"), aligned(1), used))
#define STRINGS_POKEMON_NAMES_TEXT __attribute__((section(".rodata.strings_pokemon_names_text"), aligned(1), used))

STRINGS_FISHING_BITE const u8 gText_OhABite[] = _("ひいてる　ひいてる！！");
STRINGS_FISHING_MESSAGES const u8 gText_PokemonOnHook[] = _("ポケモンを　つりあげた！{PAUSE_UNTIL_PRESS}");
STRINGS_FISHING_MESSAGES const u8 gText_NotEvenANibble[] = _("つれないなあ···{PAUSE_UNTIL_PRESS}");
STRINGS_FISHING_MESSAGES const u8 gText_ItGotAway[] = _("にげられて　しまった···{PAUSE_UNTIL_PRESS}");
STRINGS_SAVING_STATUS const u8 gText_SavingPlayer[] = _("しゅじんこう");
STRINGS_SAVING_STATUS const u8 gText_SavingBadges[] = _("もっているバッジ");
STRINGS_SAVING_STATUS const u8 gText_SavingPokedex[] = _("ポケモンずかん");
STRINGS_SAVING_STATUS const u8 gText_SavingTime[8] = _("プレイじかん");
STRINGS_DECIMAL_POINT const u8 gText_DecimalPoint[] = _(",");
STRINGS_QUESTION_MARKS const u8 gText_ThreeQuestionMarks[] = _("？？？");
STRINGS_CONTEST_RESULTS const u8 gText_CDot[] = _("C,");
STRINGS_CONTEST_RESULTS const u8 gText_BDot[] = _("B,");
STRINGS_CONTEST_RESULTS const u8 gText_AnnouncingResults[] = _("けっか　はっぴょう！");
STRINGS_CONTEST_RESULTS const u8 gText_PreliminaryResults[] = _("1じしんさの　けっか！");
STRINGS_CONTEST_RESULTS const u8 gText_Round2Results[] = _("2じしんさの　けっか！");
STRINGS_CONTEST_RESULTS const u8 gText_ContestantsMonWon[] = _("ゆうしょう！　{STR_VAR_1}の　{STR_VAR_2}！");
STRINGS_CONTEST_RESULTS const u8 gText_CommunicationStandby[] = _("つうしんたいきちゅう");
STRINGS_CONTEST_RESULTS const u8 gText_ColorDarkGray[] = _("{COLOR 0x02}");
STRINGS_CONTEST_RESULTS const u8 gText_ColorDynamic6WhiteDynamic5[] = _("{COLOR_HIGHLIGHT_SHADOW 0x0F 0x01 0x0E}");

const u8 gText_ExpandedPlaceholder_Empty[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("");
const u8 gText_ExpandedPlaceholder_Kun[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("くん");
const u8 gText_ExpandedPlaceholder_Chan[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("ちゃん");
const u8 gText_ExpandedPlaceholder_Sapphire[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("サファイア");
const u8 gText_ExpandedPlaceholder_Ruby[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("ルビー");
const u8 gText_ExpandedPlaceholder_Emerald[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("エメラルド");
const u8 gText_ExpandedPlaceholder_Aqua[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("アクア");
const u8 gText_ExpandedPlaceholder_Magma[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("マグマ");
const u8 gText_ExpandedPlaceholder_Archie[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("アオギリ");
const u8 gText_ExpandedPlaceholder_Maxie[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("マツブサ");
const u8 gText_ExpandedPlaceholder_Kyogre[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("カイオーガ");
const u8 gText_ExpandedPlaceholder_Groudon[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("グラードン");
const u8 gText_ExpandedPlaceholder_Brendan[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("ユウキ");
const u8 gText_ExpandedPlaceholder_May[] STRINGS_EXPANDED_PLACEHOLDER_TEXT = _("ハルカ");

const u8 gText_EggNickname[] STRINGS_POKEMON_NAMES_TEXT = _("タマゴ");
const u8 gText_Pokemon[] STRINGS_POKEMON_NAMES_TEXT = _("ポケモン");
const u8 gText_ProfBirchMatchCallName[] STRINGS_POKEMON_NAMES_TEXT = _("オダマキ");

const u8 gText_Diploma_1[] STRINGS_DIPLOMA_TEXT = _("プレイヤー");
const u8 gText_Diploma_2[] STRINGS_DIPLOMA_TEXT = _("さま");
const u8 gText_Diploma_Hoenn[] STRINGS_DIPLOMA_TEXT = _("ホウエン");
const u8 gText_Diploma_National[] STRINGS_DIPLOMA_TEXT = _("ぜんこく");
const u8 gText_Diploma_3[] STRINGS_DIPLOMA_TEXT = _(
    "　　　　　ポケモンずかんを\n"
    "みごと　かんせい　させた\n"
    "いだいなこうせきを　たたえ\n"
    "ここに　しょうめい　します");
const u8 gText_Diploma_4[] STRINGS_DIPLOMA_TEXT = _("{COLOR 4}{SHADOW 5}ゲームフリーク");

const u8 gText_TeachWhichMoveToPkmn[] STRINGS_MOVE_RELEARNER_TEXT = _("{STR_VAR_1}に　どのわざを　おぼえさせる？");
const u8 gText_MoveRelearnerTeachMoveConfirm[] STRINGS_MOVE_RELEARNER_TEXT = _("{STR_VAR_2}を　おぼえさせますか？");
const u8 gText_MoveRelearnerPkmnLearnedMove[] STRINGS_MOVE_RELEARNER_TEXT = _(
    "{STR_VAR_1}は　あたらしく\n"
    "{STR_VAR_2}を　おぼえた！");
const u8 gText_MoveRelearnerPkmnTryingToLearnMove[] STRINGS_MOVE_RELEARNER_TEXT = _(
    "{STR_VAR_1}は　あたらしく　\n"
    "{STR_VAR_2}を　おぼえたい⋯！\p"
    "しかし　{STR_VAR_1}は　わざを　4つ\n"
    "おぼえているので　せいいっぱいだ！\p"
    "{STR_VAR_2}の　かわりに　ほかの　わざを\n"
    "わすれさせますか？");
const u8 gText_MoveRelearnerStopTryingToTeachMove[] STRINGS_MOVE_RELEARNER_TEXT = _(
    "それでは⋯⋯　{STR_VAR_2}を\n"
    "おぼえるのを　あきらめますか？");
const u8 gText_MoveRelearnerAndPoof[] STRINGS_MOVE_RELEARNER_TEXT = _(
    "{PAUSE 32}1　{PAUSE 15}2の　{PAUSE 15}⋯{PAUSE 15}⋯{PAUSE 15}⋯　"
    "{PAUSE 15}{PLAY_SE SE_BALL_BOUNCE_1}ポカン！\p");
const u8 gText_MoveRelearnerPkmnForgotMoveAndLearnedNew[] STRINGS_MOVE_RELEARNER_TEXT = _(
    "{STR_VAR_1}は　{STR_VAR_3}の　つかいかたを\n"
    "きれいに　わすれた！\p"
    "そして⋯！\p"
    "{STR_VAR_1}は　あたらしく\n"
    "{STR_VAR_2}を　おぼえた！");
const u8 gText_MoveRelearnedPkmnDidNotLearnMove[] STRINGS_MOVE_RELEARNER_TEXT = _("{STR_VAR_1}は　{STR_VAR_2}を　おぼえずに　おわった！");
const u8 gText_MoveRelearnerGiveUp[] STRINGS_MOVE_RELEARNER_TEXT = _(
    "{STR_VAR_1}に　わざを　おぼえさせるのを\n"
    "あきらめますか？");
const u8 gText_MoveRelearnerWhichMoveToForget[] STRINGS_MOVE_RELEARNER_TEXT = _(
    "どの　わざを\n"
    "わすれさせたい？\p");

STRINGS_MENU_YES_NO const u8 gText_YesNo[] = _("はい\nいいえ");
STRINGS_MENU_SELECTOR_ARROW3 const u8 gText_SelectorArrow3[] = _("▶");

STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_RentalPkmn2[] = _("ポケモンレンタル");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_SelectFirstPkmn[] = _("1ばんめのポケモンを　えらんでください");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_SelectSecondPkmn[] = _("2ばんめのポケモンを　えらんでください");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_SelectThirdPkmn[] = _("3ばんめのポケモンを　えらんでください");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_Rent[] = _("レンタルする");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_Summary[] = _("つよさをみる");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_Others2[] = _("べつのにする");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_Deselect[] = _("はずす");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_TheseThreePkmnOkay[] = _("いじょうの　3ひきで　よろしいですか？");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_Yes2[] = _("はい");
STRINGS_BATTLE_FACTORY_SELECTION const u8 gText_No2[] = _("いいえ");

STRINGS_DECORATION_TEXT const u8 gText_ApostropheSBase[] = _("　きち");

STRINGS_DECORATION_TEXT const u8 gText_OkayToDeleteFromRegistry[] = _(
    "{STR_VAR_1}　の　とうろくを\n"
    "かいじょ　しても　よろしい　ですか？");

STRINGS_DECORATION_TEXT const u8 gText_RegisteredDataDeleted[] = _("とうろくを　かいじょ　しました{PAUSE_UNTIL_PRESS}");

STRINGS_DECORATION_TEXT const u8 gText_NoRegistry[] = _("とうろく　リストは　ありません{PAUSE_UNTIL_PRESS}");
STRINGS_DECORATION_TEXT const u8 gText_DelRegist[] = _("とうろく　かいじょ");

STRINGS_DECORATION_TEXT const u8 gText_Var3Var1SlashVar2[] = _("{STR_VAR_3}{STR_VAR_1}/{STR_VAR_2}");

STRINGS_DECORATION_TEXT const u8 gText_Decorate[] = _("グッズを　おく");

STRINGS_DECORATION_TEXT const u8 gText_PutAway[] = _("グッズを　もどす");

STRINGS_DECORATION_TEXT const u8 gText_Toss2[] = _("グッズを　すてる");

STRINGS_DECORATION_TEXT const u8 gText_Color161Shadow161[] = _("{COLOR 161}{SHADOW 161}");

STRINGS_DECORATION_TEXT const u8 gText_PutOutSelectedDecorItem[] = _("えらんだ　グッズを　へやに　おきます！");

STRINGS_DECORATION_TEXT const u8 gText_StoreChosenDecorInPC[] = _("えらんだ　グッズを　パソコンに　もどします！");

STRINGS_DECORATION_TEXT const u8 gText_ThrowAwayUnwantedDecors[] = _("いらなくなった　グッズを　すてます！");

STRINGS_DECORATION_TEXT const u8 gText_NoDecorations[] = _("グッズは　ありません！{PAUSE_UNTIL_PRESS}");

STRINGS_DECORATION_TEXT const u8 gText_Desk[] = _("つくえ");

STRINGS_DECORATION_TEXT const u8 gText_Chair[] = _("いす");

STRINGS_DECORATION_TEXT const u8 gText_Plant[] = _("はちうえ");

STRINGS_DECORATION_TEXT const u8 gText_Ornament[] = _("おきもの");

STRINGS_DECORATION_TEXT const u8 gText_Mat[] = _("マット");

STRINGS_DECORATION_TEXT const u8 gText_Poster[] = _("ポスター");

STRINGS_DECORATION_TEXT const u8 gText_Doll[] = _("ぬいぐるみ");

STRINGS_DECORATION_TEXT const u8 gText_Cushion[] = _("クッション");

STRINGS_DECORATION_TEXT const u8 gText_Gold[] = _("きん");

STRINGS_DECORATION_TEXT const u8 gText_Silver[] = _("ぎん");

STRINGS_DECORATION_TEXT const u8 gText_PlaceItHere[] = _("ここに　おきますか？");

STRINGS_DECORATION_TEXT const u8 gText_CantBePlacedHere[] = _("ここには　おけません！");

STRINGS_DECORATION_TEXT const u8 gText_CancelDecorating[] = _("おくのを　やめますか？");

STRINGS_DECORATION_TEXT const u8 gText_InUseAlready[] = _("すでに　おかれて　います！");

STRINGS_DECORATION_TEXT const u8 gText_NoMoreDecorations[] = _(
    "これいじょう　おけません\n"
    "ひみつきちに　おけるのは　{STR_VAR_1}こ　までです");

STRINGS_DECORATION_TEXT const u8 gText_NoMoreDecorations2[] = _(
    "これいじょう　おけません\n"
    "へやに　おけるのは　{STR_VAR_1}こ　までです");

STRINGS_DECORATION_TEXT const u8 gText_MustBePlacedOnDesk[] = _(
    "ここには　おけません！\n"
    "つくえの　うえなどに　おいてください！");

STRINGS_DECORATION_TEXT const u8 gText_CantPlaceInRoom[] = _(
    "この　グッズは\n"
    "じぶんの　へやには　おけません！");
STRINGS_DECORATION_TEXT const u8 gText_CantThrowAwayInUse[] = _(
    "このグッズは　おかれて　いるので\n"
    "すてる　ことが　できません！");
STRINGS_DECORATION_TEXT const u8 gText_DecorationWillBeDiscarded[] = _(
    "{STR_VAR_1}　は　なくなりますが\n"
    "よろしい　ですか？");
STRINGS_DECORATION_TEXT const u8 gText_DecorationThrownAway[] = _("グッズを　すてました！");
STRINGS_DECORATION_TEXT const u8 gText_StopPuttingAwayDecorations[] = _("もどすのを　やめますか？");
STRINGS_DECORATION_TEXT const u8 gText_NoDecorationHere[] = _("ここに　グッズは　ありません！");
STRINGS_DECORATION_TEXT const u8 gText_ReturnDecorationToPC[] = _("このグッズを　パソコンに　もどしますか？");
STRINGS_DECORATION_TEXT const u8 gText_DecorationReturnedToPC[] = _("グッズを　パソコンに　もどしました！");
STRINGS_DECORATION_TEXT const u8 gText_NoDecorationsInUse[] = _("グッズは　おかれて　いません！{PAUSE_UNTIL_PRESS}");
STRINGS_DECORATION_TEXT const u8 gText_Tristan[] = _("ヒロミ");
STRINGS_DECORATION_TEXT const u8 gText_Philip[] = _("ユウリ");
STRINGS_DECORATION_TEXT const u8 gText_Dennis[] = _("ヨシオ");
STRINGS_DECORATION_TEXT const u8 gText_Roberto[] = _("サダハル");
STRINGS_DECORATION_TEXT const u8 gText_TurnOff[] = _("せつぞくを　きる");
STRINGS_DECORATION_TEXT const u8 gText_Decoration[] = _("もようがえ");
STRINGS_DECORATION_TEXT const u8 gText_ItemStorage[] = _("どうぐ　あずかり");

STRINGS_PC_TEXT const u8 gText_Mailbox[] = _("メールボックス");
STRINGS_PC_TEXT const u8 gText_DepositItem[] = _("どうぐを　あずける");
STRINGS_PC_TEXT const u8 gText_WithdrawItem[] = _("どうぐを　ひきだす");
STRINGS_PC_TEXT const u8 gText_TossItem[] = _("どうぐを　すてる");
STRINGS_PC_TEXT const u8 gText_StoreItemsInPC[] = _(
    "パソコン　に\n"
    "どうぐを　あずけます");
STRINGS_PC_TEXT const u8 gText_TakeOutItemsFromPC[] = _(
    "パソコン　から\n"
    "どうぐを　ひきだします");
STRINGS_PC_TEXT const u8 gText_ThrowAwayItemsInPC[] = _(
    "パソコン　に　あずけている\n"
    "どうぐを　すてます");
STRINGS_PC_TEXT const u8 gText_NoItems[] = _("なにも　ありません！{PAUSE_UNTIL_PRESS}");
STRINGS_PC_TEXT const u8 gText_NoRoomInBag[] = _(
    "これいじょう\n"
    "バッグに　はいりません");
STRINGS_PC_TEXT const u8 gText_WithdrawHowManyItems[] = _(
    "{STR_VAR_1}を\n"
    "いくつ　ひきだしますか？");
STRINGS_PC_TEXT const u8 gText_WithdrawXItems[] = _(
    "{STR_VAR_1}を\n"
    "{STR_VAR_2}コ　ひきだしました");
STRINGS_PC_TEXT const u8 gText_Read[] = _("ないようを　よむ");
STRINGS_PC_TEXT const u8 gText_MoveToBag[] = _("バッグに　もどす");
STRINGS_PC_TEXT const u8 gText_Give2[] = _("ポケモンに　もたせる");
STRINGS_PC_TEXT const u8 gText_NoMailHere[] = _("メールは　1つうも　ありません{PAUSE_UNTIL_PRESS}");
STRINGS_PC_TEXT const u8 gText_WhatToDoWithVar1sMail[] = _(
    "{STR_VAR_1}　の\n"
    "メールを　どうしますか？");
STRINGS_PC_TEXT const u8 gText_MessageWillBeLost[] = _(
    "ないようは　きえてしまいますが\n"
    "よろしいですか？");
STRINGS_PC_TEXT const u8 gText_BagIsFull[] = _("バッグが　いっぱいです！{PAUSE_UNTIL_PRESS}");
STRINGS_PC_TEXT const u8 gText_MailToBagMessageErased[] = _(
    "ないようを　けした　メールを\n"
    "バッグに　いれました{PAUSE_UNTIL_PRESS}");

STRINGS_SHARED_NAME_TEXT const u8 gText_Dad[] = _("パパ");
STRINGS_SHARED_NAME_TEXT const u8 gText_Mom[] = _("ママ");
STRINGS_SHARED_NAME_TEXT const u8 gText_Wallace[] = _("ミクリ");
STRINGS_SHARED_NAME_TEXT const u8 gText_Steven[] = _("ダイゴ");
STRINGS_SHARED_NAME_TEXT const u8 gText_Brawly[] = _("トウキ");
STRINGS_SHARED_NAME_TEXT const u8 gText_Winona[] = _("ナギ");
STRINGS_SHARED_NAME_TEXT const u8 gText_Phoebe[] = _("フヨウ");
STRINGS_SHARED_NAME_TEXT const u8 gText_Glacia[] = _("プリム");

STRINGS_SCRIPT_MENU_TEXT const u8 gText_Petalburg[] = _("トウカ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Slateport[] = _("カイナ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Littleroot[] = _("ミシロ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Lilycove[] = _("ミナモ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Dewford[] = _("ムロ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Enter2[] = _("さんか　する");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Info2[] = _("せつめいをきく");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_WhatsAContest[] = _("ポケモンコンテストって？");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TypesOfContests[] = _("コンテストの　しゅるい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Ranks[] = _("ランクに　ついて");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Judging[] = _("しんさいんに　ついて");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_CoolnessContest[] = _("かっこよさコンテスト");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BeautyContest[] = _("うつくしさコンテスト");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_CutenessContest[] = _("かわいさコンテスト");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SmartnessContest[] = _("かしこさコンテスト");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_ToughnessContest[] = _("たくましさコンテスト");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Decoration2[] = _("もようがえ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PackUp[] = _("ひっこし");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Count[] = _("カウント");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Registry[] = _("とうろく　リスト");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Information[] = _("とうろく　せつめい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Mach[] = _("マッハ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Acro[] = _("ダート");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Psn[] = _("どく");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Par[] = _("まひ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Slp[] = _("ねむり");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Brn[] = _("やけど");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Frz[] = _("こおり");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Toxic[] = _("どくどく");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Ok3[] = _("ふつう");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Quit[] = _("よむのを　やめる");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SawIt[] = _("みました");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_NotYet[] = _("これから");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Yes[] = _("はい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_No[] = _("いいえ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Info4[] = _("せつめい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SingleBattle[] = _("シングルバトル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_DoubleBattle[] = _("ダブルバトル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MultiBattle[] = _("マルチバトル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MrBriney[] = _("ハギ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Challenge[] = _("ちょうせんする");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Info3[] = _("せつめいをきく");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Lv50[] = _("レベル50");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_OpenLevel[] = _("オープンレベル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_FreshWaterAndPrice[] = _("おいしいみず　200¥");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SodaPopAndPrice[] = _("サイコソーダ　300¥");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_LemonadeAndPrice[] = _("ミックスオレ　350¥");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_HowToRide[] = _("はしりかた");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_HowToTurn[] = _("まがるコツ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SandySlopes[] = _("すなのさか");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Wheelies[] = _("ウイリー");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BunnyHops[] = _("ダニエル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Jump[] = _("ジャンプ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Satisfied[] = _("まんぞく");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Dissatisfied[] = _("ふまん");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_DeepSeaTooth[] = _("しんかいのキバ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_DeepSeaScale[] = _("しんかいのウロコ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BlueFlute2[] = _("あおいビードロ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_YellowFlute2[] = _("きいろビードロ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_RedFlute2[] = _("あかいビードロ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_WhiteFlute2[] = _("しろいビードロ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BlackFlute2[] = _("くろいビードロ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_GlassChair[] = _("ガラスのいす");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_GlassDesk[] = _("ガラスのつくえ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TreeckoDollAndPrice[] = _("キモリドール　　　1000まい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TorchicDollAndPrice[] = _("アチャモドール　　1000まい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MudkipDollAndPrice[] = _("ミズゴロウドール　1000まい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_50CoinsAndPrice[] = _("　50まい　　1000¥");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_500CoinsAndPrice[] = _("500まい　10000¥");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Excellent2[] = _("ばつぐん");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_NotSoGood[] = _("あんまり");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_RedShard[] = _("あかいかけら");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_YellowShard[] = _("きいろいかけら");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BlueShard[] = _("あおいかけら");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_GreenShard[] = _("みどりのかけら");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattleFrontier[] = _("バトルフロンティア");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Right[] = _("みぎ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Left[] = _("ひだり");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TM32AndPrice[] = _("わざマシン32　　1500まい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TM29AndPrice[] = _("わざマシン29　　3500まい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TM35AndPrice[] = _("わざマシン35　　4000まい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TM24AndPrice[] = _("わざマシン24　　4000まい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TM13AndPrice[] = _("わざマシン13　　4000まい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Cool[] = _("かっこよさ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Beauty[] = _("うつくしさ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Cute[] = _("かわいさ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Smart[] = _("かしこさ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Tough[] = _("たくましさ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Normal[] = _("ノーマル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Super[] = _("スーパー");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Hyper[] = _("ハイパー");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Master[] = _("マスター");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Cool2[] = _("かっこいい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Beauty2[] = _("うつくしい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Cute2[] = _("かわいい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Smart2[] = _("かしこそうな");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Tough2[] = _("たくましい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Items[] = _("どうぐ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Key_Items[] = _("たいせつなもの");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Poke_Balls[] = _("ボール");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TMs_Hms[] = _("わざマシン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Berries2[] = _("きのみ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SomeonesPC[] = _("だれかのパソコン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_LanettesPC[] = _("マユミのパソコン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PlayersPC[] = _("{PLAYER}のパソコン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_HallOfFame[] = _("でんどういり");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_LogOff[] = _("スイッチをきる");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Opponent[] = _("たいせん　あいて");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Tourney_Tree[] = _("トーナメントひょう");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_ReadyToStart[] = _("じゅんび　かんりょう");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_NormalRank[] = _("ノーマルランク");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SuperRank[] = _("スーパーランク");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_HyperRank[] = _("ハイパーランク");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MasterRank[] = _("マスターランク");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Single2[] = _("シングル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Double2[] = _("ダブル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Multi[] = _("マルチ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MultiLink[] = _("つうしん　マルチ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattleBag[] = _("バトルバッグ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_HeldItem[] = _("もたせたどうぐ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_LinkContest[] = _("つうしんコンテスト");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_AboutE_Mode[] = _("エメラルドモードについて");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_AboutG_Mode[] = _("グローバルモードについて");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_E_Mode[] = _("エメラルドモード");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_G_Mode[] = _("グローバルモード");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MenuOptionPokedex[] = _("ずかん");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MenuOptionPokemon[] = _("ポケモン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MenuOptionBag[] = _("バッグ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MenuOptionPokenav[] = _("ポケナビ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Blank[] = _("　　　　　"); // JP uses five full-width spaces here.
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MenuOptionSave[] = _("レポート");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MenuOptionOption[] = _("せってい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MenuOptionExit[] = _("とじる");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_5BP[] = _("　5BP");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_10BP[] = _("10BP");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_15BP[] = _("15BP");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_RedTent[] = _("あかいテント");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BlueTent[] = _("あおいテント");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SouthernIsland[] = _("みなみのことう");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BirthIsland[] = _("たんじょうのしま");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_FarawayIsland[] = _("さいはてのことう");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_NavelRock[] = _("へそのいわ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_ClawFossil[] = _("ツメのかせき");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_RootFossil[] = _("ねっこのかせき");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_No4[] = _("いいえ　");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_IllBattleNow[] = _("これからしょうぶだ！");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_IWon[] = _("しょうぶにかった！");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_ILost[] = _("しょうぶにまけた！");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_IWontTell[] = _("おしえない");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TradeCenter[] = _("トレードセンター");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Colosseum[] = _("コロシアム");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_RecordCorner[] = _("レコードコーナー");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BerryCrush3[] = _("きのみクラッシュ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_EmptyLinkService[] = _("ぐるぐるこうかん"); // JP retains the Spin Trade menu text.
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PokemonJump[] = _("ミニポケモンでジャンプ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_DodrioBerryPicking[] = _("ドードリオのきのみどり");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BecomeLeader[] = _("リーダーになる");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_JoinGroup[] = _("グループにはいる");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TwoStyles[] = _("2つのコース");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Lv50_3[] = _("レベル50");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_OpenLevel2[] = _("オープンレベル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MonTypeAndNo[] = _("ポケモンのしゅるいとかず");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_HoldItems[] = _("もたせるどうぐ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Symbols2[] = _("シンボル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Record3[] = _("たいせんのきろく");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattlePts[] = _("バトルポイント");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TowerInfo[] = _("タワーについて");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattleMon[] = _("つれていくポケモン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattleSalon[] = _("バトルサロン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_MultiLink2[] = _("つうしんマルチ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattleRules[] = _("バトルでの　ちゅうい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_JudgeMind[] = _("はんてい‘こころ’");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_JudgeSkill[] = _("はんてい‘わざ’");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_JudgeBody[] = _("はんてい‘からだ’");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Matchup[] = _("くみあわせ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_TourneyTree[] = _("トーナメントひょう");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_DoubleKO[] = _("ダブルノックアウト");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BasicRules[] = _("きほんルール");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SwapPartners[] = _("トレード　あいて");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SwapNumber[] = _("トレード　かいすう");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_SwapNotes[] = _("トレード　ちゅうい");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_OpenLevel3[] = _("オープンレベル");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattleBasics[] = _("たたかいのきほん");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PokemonNature[] = _("ポケモンのせいかく");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PokemonMoves[] = _("ポケモンのわざ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Underpowered[] = _("ちからをはっきできない");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_WhenInDanger[] = _("ピンチになったら");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PyramidPokemon[] = _("ピラミッドの　ポケモン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PyramidTrainers[] = _("ピラミッドの　トレーナー");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PyramidMaze[] = _("ピラミッドの　めいろ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattleBag2[] = _("バトルバッグ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PokenavAndBag[] = _("ポケナビと　バッグ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_HeldItems[] = _("もたせた　どうぐ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_PokemonOrder[] = _("ポケモンの　じゅんばん");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattlePokemon[] = _("でてくるポケモン");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_BattleTrainers[] = _("たたかう　トレーナー");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_GoOn[] = _("つづける");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Record2[] = _("きろくする");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Rest[] = _("やすむ");
STRINGS_SCRIPT_MENU_TEXT const u8 gText_Retire[] = _("リタイア");

STRINGS_INTERFACE_TEXT const u8 gText_99TimesPlus[] = _("99かい　いじょう");
STRINGS_INTERFACE_TEXT const u8 gText_1MinutePlus[] = _("1ぷん　いじょう");
STRINGS_INTERFACE_TEXT const u8 gText_SpaceSeconds[] = _("びょう");
STRINGS_INTERFACE_TEXT const u8 gText_SpaceTimes[] = _("かい");
// JP uses a comma as the decimal separator.
STRINGS_INTERFACE_TEXT const u8 gText_Dot[] = _(","); // Unused
STRINGS_INTERFACE_TEXT const u8 gText_BigGuy[] = _("おにいちゃん");
STRINGS_INTERFACE_TEXT const u8 gText_BigGirl[] = _("おねえちゃん");
STRINGS_INTERFACE_TEXT const u8 gText_Son[] = _("むすこ");
STRINGS_INTERFACE_TEXT const u8 gText_Daughter[] = _("むすめ");
STRINGS_INTERFACE_TEXT const u8 gText_BlueFlute[] = _("あおいビードロ");
STRINGS_INTERFACE_TEXT const u8 gText_YellowFlute[] = _("きいろビードロ");
STRINGS_INTERFACE_TEXT const u8 gText_RedFlute[] = _("あかいビードロ");
STRINGS_INTERFACE_TEXT const u8 gText_WhiteFlute[] = _("しろいビードロ");
STRINGS_INTERFACE_TEXT const u8 gText_BlackFlute[] = _("くろいビードロ");
STRINGS_INTERFACE_TEXT const u8 gText_PrettyChair[] = _("きれいなイス");
STRINGS_INTERFACE_TEXT const u8 gText_PrettyDesk[] = _("きれいなつくえ");
STRINGS_INTERFACE_TEXT const u8 gText_1F[] = _("1かい");
STRINGS_INTERFACE_TEXT const u8 gText_2F[] = _("2かい");
STRINGS_INTERFACE_TEXT const u8 gText_3F[] = _("3かい");
STRINGS_INTERFACE_TEXT const u8 gText_4F[] = _("4かい");
STRINGS_INTERFACE_TEXT const u8 gText_5F[] = _("5かい");
STRINGS_INTERFACE_TEXT const u8 gText_6F[] = _("6かい");
STRINGS_INTERFACE_TEXT const u8 gText_7F[] = _("7かい");
STRINGS_INTERFACE_TEXT const u8 gText_8F[] = _("8かい");
STRINGS_INTERFACE_TEXT const u8 gText_9F[] = _("9かい");
STRINGS_INTERFACE_TEXT const u8 gText_10F[] = _("10かい");
STRINGS_INTERFACE_TEXT const u8 gText_11F[] = _("11かい");
STRINGS_INTERFACE_TEXT const u8 gText_B1F[] = _("ビ1かい");
STRINGS_INTERFACE_TEXT const u8 gText_B2F[] = _("ビ2かい");
STRINGS_INTERFACE_TEXT const u8 gText_B3F[] = _("ビ3かい");
STRINGS_INTERFACE_TEXT const u8 gText_B4F[] = _("ビ4かい");
STRINGS_INTERFACE_TEXT const u8 gText_Rooftop[] = _("おくじょう");

STRINGS_SHARED_MISC_TEXT const u8 gText_WasEnhanced[] = _("に　みがきが　かかった！");

STRINGS_SHARED_MISC_TEXT const u8 gText_NothingChanged[] = _("なにも　かわらなかった！");

STRINGS_SHARED_MISC_TEXT const u8 gText_WontEatAnymore[] = _("もう　これいじょう　たべない　みたい⋯");

STRINGS_SHARED_MISC_TEXT const u8 gText_SaveFailedCheckingBackup[] = _(
    "レポートの　かきこみに　しっぱいしました\n"
    "バックアップカートリッジの　けんさをします\n"
    "しばらくおまちください{COLOR 4}“1ふんほど　かかります”");

STRINGS_SHARED_MISC_TEXT const u8 gText_BackupMemoryDamaged[] = _(
    "バックアップきのうの　こしょう　または　じゅみょうが\n"
    "きました。セーブすることは　できませんが　このまま\n"
    "ゲームを　あそぶことはできます");

STRINGS_SHARED_MISC_TEXT const u8 gText_GamePlayCannotBeContinued[] = _(
    "{COLOR 4}“このまま　ぼうけんをつづけることは　できません\n"
    "タイトルに　もどります”");

STRINGS_SHARED_MISC_TEXT const u8 gText_CheckCompleted[] = _(
    "けんさが　しゅうりょうしました！\n"
    "もういちど　レポートを　かきこみます\n"
    "しばらくおまちください");

STRINGS_SHARED_MISC_TEXT const u8 gText_SaveCompleteGameCannotContinue[] = _(
    "レポートの　かきこみは　しゅうりょうしました\n"
    "{COLOR 4}“このまま　ぼうけんをつづけることは　できません\n"
    "タイトルに　もどります”");

STRINGS_SHARED_MISC_TEXT const u8 gText_SaveCompletePressA[] = _(
    "レポートの　かきこみは　しゅうりょうしました\n"
    "{COLOR 4}“Aボタンを　おしてください”");

STRINGS_SHARED_MISC_TEXT const u8 gText_Ferry[] = _("れんらくせん");

STRINGS_SHARED_MISC_TEXT const u8 gText_SecretBase[] = _("ひみつきち");

STRINGS_SHARED_MISC_TEXT const u8 gText_Hideout[] = _("アジト");

STRINGS_SHARED_MISC_TEXT const u8 gText_ResetRTCConfirmCancel[] = _(
    "RTCを　リセットします\n"
    "Aで　けってい　Bで　キャンセル");

STRINGS_SHARED_MISC_TEXT const u8 gText_PresentTime[] = _("げんざいの　ゲームない　じかん");

STRINGS_SHARED_MISC_TEXT const u8 gText_PreviousTime[] = _("ぜんかいの　ゲームない　じかん");

STRINGS_SHARED_MISC_TEXT const u8 gText_PleaseResetTime[] = _("じかんを　さいせってい　してください");

STRINGS_SHARED_MISC_TEXT const u8 gText_ClockHasBeenReset[] = _(
    "じかんを　さいせってい　しました！\n"
    "レポートを　かいています　おまちください");

STRINGS_SHARED_MISC_TEXT const u8 gText_SaveCompleted[] = _("レポートを　かきこみました！");

STRINGS_SHARED_MISC_TEXT const u8 gText_SaveFailed[] = _(
    "レポートの　かきこみに\n"
    "しっぱい　しました⋯");

STRINGS_SHARED_MISC_TEXT const u8 gText_NoSaveFileCantSetTime[] = _(
    "レポートが　ないので\n"
    "じかんの　せっていは　できません！");

STRINGS_SHARED_MISC_TEXT const u8 gText_InGameClockUsable[] = _(
    "ゲームない　じかんの　しゅうせい　システムが\n"
    "つかえる　ように　なりました！");

STRINGS_SHARED_MISC_TEXT const u8 gText_Slots[] = _("スロット");

STRINGS_SHARED_MISC_TEXT const u8 gText_Roulette[] = _("ルーレット");

STRINGS_SHARED_MISC_TEXT const u8 gText_Good[] = _("いい");

STRINGS_SHARED_MISC_TEXT const u8 gText_VeryGood[] = _("おいしい");

STRINGS_SHARED_MISC_TEXT const u8 gText_Excellent[] = _("さいこう");

STRINGS_SHARED_MISC_TEXT const u8 gText_SoSo[] = _("いまいち");

STRINGS_SHARED_MISC_TEXT const u8 gText_Bad[] = _("まずい");

STRINGS_SHARED_MISC_TEXT const u8 gText_TheWorst[] = _("さいあく");

STRINGS_SHARED_MISC_TEXT const u8 gText_Spicy2[] = _("から");

STRINGS_SHARED_MISC_TEXT const u8 gText_Dry2[] = _("しぶ");

STRINGS_SHARED_MISC_TEXT const u8 gText_Sweet2[] = _("あま");

STRINGS_SHARED_MISC_TEXT const u8 gText_Bitter2[] = _("にが");

STRINGS_SHARED_MISC_TEXT const u8 gText_Sour2[] = _("すっぱ");

STRINGS_SHARED_MISC_TEXT const u8 gText_Single[] = _("シングル");

STRINGS_SHARED_MISC_TEXT const u8 gText_Double[] = _("ダブル");

STRINGS_SHARED_MISC_TEXT const u8 gText_Jackpot[] = _("とく");
STRINGS_SHARED_MISC_TEXT const u8 gText_0Pts[] = _("　　0てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_10Pts[] = _("　10てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_20Pts[] = _("　20てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_30Pts[] = _("　30てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_40Pts[] = _("　40てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_50Pts[] = _("　50てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_60Pts[] = _("　60てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_70Pts[] = _("　70てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_80Pts[] = _("　80てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_90Pts[] = _("　90てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_100Pts[] = _("100てん");
STRINGS_SHARED_MISC_TEXT const u8 gText_QuestionMark[] = _("　　？");

STRINGS_SHARED_MISC_TEXT const u8 gText_KissPoster16BP[] = _("キッスポスター　　　16BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_KissCushion32BP[] = _("キッスクッション　　32BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_SmoochumDoll32BP[] = _("ムチュールドール　　32BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_TogepiDoll48BP[] = _("トゲピードール　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_MeowthDoll48BP[] = _("ニャースドール　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_ClefairyDoll48BP[] = _("ピッピドール　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_DittoDoll48BP[] = _("メタモンドール　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_CyndaquilDoll80BP[] = _("ヒノアラシドール　　80BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_ChikoritaDoll80BP[] = _("チコリータドール　　80BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_TotodileDoll80BP[] = _("ワニノコドール　　　80BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_LaprasDoll128BP[] = _("ラプラスドール　　128BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_SnorlaxDoll128BP[] = _("カビゴンドール　　128BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_VenusaurDoll256BP[] = _("フシギバナドール　256BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_CharizardDoll256BP[] = _("リザードンドール　256BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_BlastoiseDoll256BP[] = _("カメックスドール　256BP");

STRINGS_SHARED_MISC_TEXT const u8 gText_Protein1BP[] = _("タウリン　　　　　　　1BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_Calcium1BP[] = _("リゾチウム　　　　　　1BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_Iron1BP[] = _("ブロムヘキシン　　　　1BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_Zinc1BP[] = _("キトサン　　　　　　　1BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_Carbos1BP[] = _("インドメタシン　　　　1BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_HpUp1BP[] = _("マックスアップ　　　　1BP");

STRINGS_SHARED_MISC_TEXT const u8 gText_Leftovers48BP[] = _("たべのこし　　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_WhiteHerb48BP[] = _("しろいハーブ　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_QuickClaw48BP[] = _("せんせいのツメ　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_MentalHerb48BP[] = _("メンタルハーブ　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_BrightPowder64BP[] = _("ひかりのこな　　　　64BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_ChoiceBand64BP[] = _("こだわりハチマキ　　64BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_KingsRock64BP[] = _("おうじゃのしるし　　64BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_FocusBand64BP[] = _("きあいのハチマキ　　64BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_ScopeLens64BP[] = _("ピントレンズ　　　　64BP");

STRINGS_SHARED_MISC_TEXT const u8 gText_Softboiled16BP[] = _("タマゴうみ　　　　16BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_SeismicToss24BP[] = _("ちきゅうなげ　　　24BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_DreamEater24BP[] = _("ゆめくい　　　　　24BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_MegaPunch24BP[] = _("メガトンパンチ　　24BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_MegaKick48BP[] = _("メガトンキック　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_BodySlam48BP[] = _("のしかかり　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_RockSlide48BP[] = _("いわなだれ　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_Counter48BP[] = _("カウンター　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_ThunderWave48BP[] = _("でんじは　　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_SwordsDance48BP[] = _("つるぎのまい　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_DefenseCurl16BP[] = _("まるくなる　　　　16BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_Snore24BP[] = _("いびき　　　　　　24BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_MudSlap24BP[] = _("どろかけ　　　　　24BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_Swift24BP[] = _("スピードスター　　24BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_IcyWind24BP[] = _("こごえるかぜ　　　24BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_Endure48BP[] = _("こらえる　　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_PsychUp48BP[] = _("じこあんじ　　　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_IcePunch48BP[] = _("れいとうパンチ　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_ThunderPunch48BP[] = _("かみなりパンチ　　48BP");
STRINGS_SHARED_MISC_TEXT const u8 gText_FirePunch48BP[] = _("ほのおのパンチ　　48BP");

STRINGS_TRAINER_STATUS_TEXT const u8 gText_PkmnFainted_FldPsn[] = _(
    "{STR_VAR_1}は\n"
    "ちからつきた\p");

STRINGS_TRAINER_STATUS_TEXT const u8 gText_Marco[] = _("コウジ");

STRINGS_TRAINER_STATUS_TEXT const u8 gText_TrainerCardName[] = _("なまえ");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_TrainerCardIDNo[] = _("IDNo,");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_TrainerCardMoney[] = _("おこづかい");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_PokeDollar[] = _("¥"); // Unused
STRINGS_TRAINER_STATUS_TEXT const u8 gText_TrainerCardPokedex[] = _("ポケモンずかん");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_EmptyString6[] = _("ひき"); // JP Trainer Card caught-Pokémon suffix.
STRINGS_TRAINER_STATUS_TEXT const u8 gText_Colon2[] = _(":");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_Points[] = _("てん"); // Unused

STRINGS_TRAINER_STATUS_TEXT const u8 gText_TrainerCardTime[] = _("プレイじかん");
STRINGS_TRAINER_STATUS_TEXT const u8 gJPText_BattlePoints[] = _("ゲームポイント"); // Unused
STRINGS_TRAINER_STATUS_TEXT const u8 gText_Var1sTrainerCard[] = _("のトレーナーカード");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_HallOfFameDebut[] = _("はじめてのでんどういり　");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_LinkBattles[] = _("つうしんたいせん");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_LinkCableBattles[] = _("ケーブルたいせん");

STRINGS_TRAINER_STATUS_TEXT const u8 gText_WinsLosses[] = _("かち　　　　　まけ");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_PokemonTrades[] = _("ポケモンつうしんこうかん");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_UnionTradesAndBattles[] = _("ユニオンたいせんとこうかん");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BerryCrush[] = _("きのみクラッシュ");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_WaitingTrainerFinishReading[] = _(
    "あいてが　カードを　みおわるのを\n"
    "まっています");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_PokeblocksWithFriends[] = _("ともだちと　つくった　ポロック");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_NumPokeblocks[] = _("{STR_VAR_1}{COLOR 2}{SHADOW 3}こ");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_WonContestsWFriends[] = _("ともだちとコンテスト　ゆうしょう");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BattlePtsWon[] = _("かちとった　バトルポイント");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_NumBP[] = _("{STR_VAR_1}{COLOR 2}{SHADOW 3}BP");

// Japanese Trainer Cards combine this header with its two column labels.
STRINGS_TRAINER_STATUS_TEXT const u8 gJPText_BattleTowerWinsStraightHeader[] = _("バトルタワー　　かち　　　　　　かちぬき");

STRINGS_TRAINER_STATUS_TEXT const u8 gText_WinsStraight[] = _("{STR_VAR_1}　　　　　　{STR_VAR_2}");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BattleTower[] = _("バトルタワー");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BattleDome[] = _("バトルドーム");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BattlePalace[] = _("バトルパレス");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BattleFactory[] = _("バトルファクトリー");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BattleArena[] = _("バトルアリーナ");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BattlePike[] = _("バトルチューブ");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_BattlePyramid[] = _("バトルピラミッド");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_FacilitySingle[] = _("　{STR_VAR_1}　シングル");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_FacilityDouble[] = _("{STR_VAR_1}　ダブル");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_FacilityMulti[] = _("　{STR_VAR_1}　マルチ");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_FacilityLink[] = _("　{STR_VAR_1}　つうしん");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_Facility[] = _("{STR_VAR_1}");

STRINGS_TRAINER_STATUS_TEXT const u8 gText_Give[] = _("もたせるべき");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_NoNeed[] = _("もたせない");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_ColorLightShadowDarkGray[] = _("{COLOR 3}{SHADOW 2}");
STRINGS_TRAINER_STATUS_TEXT const u8 gText_ColorBlue[] = _("{COLOR 8}");

// The final 0xFF is the COLOR parameter and also the StringCopy terminator.
// __() is required here so that charmap_jp does not append a second EOS.
STRINGS_TRAINER_STATUS_TEXT const u8 gText_ColorTransparent[] = __("{HIGHLIGHT 0}{COLOR 255}");

STRINGS_CHAT_PROFILE_TEXT const u8 gText_Hiragana[] = _("ひらがな");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Katakana[] = _("カタカナ");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_ABC[] = _("ABC");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Symbols[] = _("きごう");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Register2[] = _("とうろく");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Exit2[] = _("とじる");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_QuitChatting[] = _("チャットを　やめますか？");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_RegisterTextWhere[] = _("どこに　とうろくしますか？");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_RegisterTextHere[] = _("ここに　とうろくしますか？");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_InputText[] = _("ことばを　いれて　ください！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_F700JoinedChat[] = _("{DYNAMIC 0}さんが　さんかしました！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_F700LeftChat[] = _("{DYNAMIC 0}さんが　ぬけました");
STRINGS_CHAT_PROFILE_TEXT const u8 gJPText_PlayersXPokemon[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめ:");
STRINGS_CHAT_PROFILE_TEXT const u8 gJPText_PlayersXPokmonDoesNotExist[] = _("{DYNAMIC 0}の{DYNAMIC 1}ひきめは　いません");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_ExitingChat[] = _(
    "さんかしゃが　いなくなったので\n"
    "しゅうりょうします！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_LeaderLeftEndingChat[] = _(
    "リーダーの　{DYNAMIC 0}さんが\n"
    "ぬけたので　かいさんします！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_RegisteredTextChangedOKToSave[] = _(
    "とうろくが　かわりました\n"
    "ポケモンレポートに　かきこみますか？");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_AlreadySavedFile_Chat[] = _(
    "まえに　かかれた　レポートに\n"
    "うえから　かいても　いいですか？");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_SavingDontTurnOff_Chat[] = _(
    "ポケモンレポートに　かきこんでいます\n"
    "でんげんを　きらないで　ください");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_PlayerSavedGame_Chat[] = _(
    "{DYNAMIC 0}　は\n"
    "レポートに　しっかり　かきのこした！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_IfLeaderLeavesChatEnds[] = _(
    "リーダーが　やめると　かいさん\n"
    "になりますが　よろしいですか？");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Hello[] = _("こんにちは");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Pokemon2[] = _("ポケモン");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Trade[] = _("こうかん");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Battle[] = _("たいせん");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Lets[] = _("しよう！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Ok[] = _("OK！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_Sorry[] = _("ごめん⋯");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_YaySmileEmoji[] = _("わーい{EMOJI_BIGSMILE}");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_ThankYou[] = _("サンキュー");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_ByeBye[] = _("バイバイ！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallSteven_Strategy[] = _("あいての　じゃくてんを　つく！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallSteven_Pokemon[] = _("さいきょうの　はがねポケモン");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle[] = _("めずらしい　いしの　ためなら");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle[] = _("たきだって　のぼって　いくよ");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle[] = _("けっきょく　ボクが　いちばん");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle[] = _("つよくて　すごいんだよね");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallBrendan_Strategy[] = _("ポケモンの　ちしきで　しょうぶ");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallBrendan_Pokemon[] = _("いろんな　ポケモンを　つかうぜ");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallBrendan_Intro1[] = _("とうさんより　すごい　ポケモン");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallBrendan_Intro2[] = _("はかせに　なって　みせるさ！");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallMay_Strategy[] = _("しょうぶは　とくいじゃないかも");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallMay_Pokemon[] = _("どんな　ポケモンでも　つかうわ");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallMay_Intro1[] = _("ポケモン　つれて　おとうさんの");
STRINGS_CHAT_PROFILE_TEXT const u8 gText_MatchCallMay_Intro2[] = _("けんきゅうを　おてつだい！");

STRINGS_EGG_HATCH_TEXT const u8 gText_HatchedFromEgg[] = _(
    "タマゴが　かえって\n"
    "{STR_VAR_1}が　うまれた！");
STRINGS_EGG_HATCH_TEXT const u8 gText_NicknameHatchPrompt[] = _(
    "うまれた　{STR_VAR_1}に\n"
    "ニックネームを　つけますか？");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_ReadyPickBerry[] = _(
    "きのみクラッシュを　はじめます\n"
    "つかう　きのみを　えらんでください\p");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_WaitForAllChooseBerry[] = _(
    "ほかの　メンバーが　きのみを\n"
    "えらぶまで　おまちください");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_EndedWithXUnitsPowder[] = _(
    "{PAUSE_MUSIC}{PLAY_BGM MUS_LEVEL_UP}サラサラな　こなが\n"
    "{STR_VAR_1}　できた！{RESUME_MUSIC}\p"
    "ごうけいで　こなの　りょうが\n"
    "{STR_VAR_2}　になった！\p");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_RecordingGameResults[] = _(
    "ゲームの　けっかを\n"
    "ポケモンレポートに　かきこんでいます\l"
    "しばらく　おまちください");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_PlayBerryCrushAgain[] = _(
    "きのみクラッシュで　もういちど\n"
    "あそびますか？");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_YouHaveNoBerries[] = _(
    "つかう　きのみが　ありません\n"
    "ゲームを　しゅうりょうします");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_MemberDroppedOut[] = _(
    "ぬけた　メンバーが　いるので\n"
    "ゲームを　しゅうりょうします");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_TimesUpNoGoodPowder[] = _(
    "じかんぎれ　です\p"
    "よいこな　が\n"
    "できあがり　ませんでした\p");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_CommunicationStandby2[] = _("つうしんたいきちゅう");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_1DotBlueF700[] = _("1,{COLOR 8}{SHADOW 9}{DYNAMIC 0}");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_1DotF700[] = _("1,{DYNAMIC 0}");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_SpaceTimes2[] = _("かい");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_XDotY[] = _("{STR_VAR_1},{STR_VAR_2}");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_Var1Berry[] = _("{STR_VAR_1}のみ");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_TimeColon[] = _("じかん");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_PressingSpeed[] = _("おすはやさ");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_Silkiness[] = _("サラサラぐあい");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_StrVar1[] = _("{STR_VAR_1}");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_SpaceMin[] = _("ふん");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_XDotY2[] = _("{STR_VAR_1},{STR_VAR_2}");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_SpaceSec[] = _("びょう");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_XDotY3[] = _("{STR_VAR_1},{STR_VAR_2}");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_TimesPerSec[] = _("かい/びょう");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_Var1Percent[] = _("{STR_VAR_1}パーセント");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_PressesRankings[] = _("おした　かいすう　ランキング");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_CrushingResults[] = _("つぶした　けっか");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_NeatnessRankings[] = _("ていねいさ　ランキング");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_CoopRankings[] = _("たすけあい　ランキング");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_PressingPowerRankings[] = _("おすつよさ　ランキング");
// JP also aligns the final two ranking labels; the last slot has three zero pad bytes.
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_BerryCrush2[] = _("きのみクラッシュ");
ALIGNED(4) STRINGS_BERRY_CRUSH_TEXT const u8 gText_PressingSpeedRankings[16] = _("おすはやさ　ランキング！");

STRINGS_FRONTIER_PASS_TEXT const u8 gText_Var1Players[] = _("{STR_VAR_1}にんよう");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_SymbolsEarned[] = _("てにいれた　シンボル");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleRecord[] = _("たいせんの　きろく");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePoints[] = _("バトルポイント");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_UnusedCancel[] = _("とじる");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_EmptyString7[] = _("");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_CheckFrontierMap[] = _("バトルフロンティアの　マップを　みます");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_CheckTrainerCard[] = _("トレーナーカードを　みます");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_ViewRecordedBattle[] = _("きろくした　たいせんを　みます");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_PutAwayFrontierPass[] = _("フロンティアパスを　とじます");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_CurrentBattlePoints[] = _("いま　たまっている　バトルポイントです");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_CollectedSymbols[] = _("ここに　シンボルを　あつめます");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleTowerAbilitySymbol[] = _("バトルタワー　アビリティシンボル");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleDomeTacticsSymbol[] = _("バトルドーム　タクティクスシンボル");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePalaceSpiritsSymbol[] = _("バトルパレス　スピリットシンボル");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleArenaGutsSymbol[] = _("バトルアリーナ　ガッツシンボル");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleFactoryKnowledgeSymbol[] = _("バトルファクトリー　ノウレッジシンボル");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePikeLuckSymbol[] = _("バトルチューブ　ラックシンボル");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePyramidBraveSymbol[] = _("バトルピラミッド　ブレイブシンボル");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_ThereIsNoBattleRecord[] = _("げんざい　たいせんきろくは　ありません");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleTower3[] = _("バトルタワー");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleDome2[] = _("バトルドーム");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePalace2[] = _("バトルパレス");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleArena2[] = _("バトルアリーナ");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleFactory2[] = _("バトルファクトリー");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePike2[] = _("バトルチューブ");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePyramid2[] = _("バトルピラミッド");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleTowerDesc[] = _(
    "かちぬき　ひたすら　うえを　めざす。\n"
    "さいのうを　ためされる。");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleDomeDesc[] = _(
    "トーナメントを　かちぬく。\n"
    "せんじゅつを　ためされる。");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePalaceDesc[] = _(
    "しょうぶを　みまもる。\n"
    "ポケモンとの　きずなを　ためされる。");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleArenaDesc[] = _(
    "つよい　ポケモンの　チームで　しょうりする。\n"
    "とうしを　ためされる。");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattleFactoryDesc[] = _(
    "レンタルポケモンで　しょうりする。\n"
    "ちしきを　ためされる。");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePikeDesc[] = _(
    "3つの　みちから　1つえらび　かちすすむ。\n"
    "うんを　ためされる。");
STRINGS_FRONTIER_PASS_TEXT const u8 gText_BattlePyramidDesc[] = _(
    "ちょうじょうを　めざし　ぼうけんする。\n"
    "ゆうきを　ためされる。");

STRINGS_MINIGAME_TEXT const u8 gText_ContinueMenuPlayer[] = _("しゅじんこう　{STR_VAR_1}");
STRINGS_MINIGAME_TEXT const u8 gText_ContinueMenuTime[] = _("プレイじかん　{STR_VAR_1}:{STR_VAR_2}");
STRINGS_MINIGAME_TEXT const u8 gText_ContinueMenuPokedex[] = _("ポケモンずかん　{STR_VAR_1}ひき");
STRINGS_MINIGAME_TEXT const u8 gText_ContinueMenuBadges[] = _("もっているバッジ　{STR_VAR_1}こ");
STRINGS_MINIGAME_TEXT const u8 gText_Powder[] = _("きのみのこな");
STRINGS_MINIGAME_TEXT const u8 gText_BerryPickingRecords[] = _("ドードリオのきのみどりの　きろく");
STRINGS_MINIGAME_TEXT const u8 gText_BerriesPicked[] = _("きのみをとった　かいすう");
STRINGS_MINIGAME_TEXT const u8 gText_BestScore[] = _("さいこう　とくてん");
STRINGS_MINIGAME_TEXT const u8 gText_BerriesInRowFivePlayers[] = _(
    "5にんで　きのみを\n"
    "つづけてとった　かいすう");
STRINGS_MINIGAME_TEXT const u8 gText_BerryPickingResults[] = _("きのみの　けっか　はっぴょう！！");
STRINGS_MINIGAME_TEXT const u8 gText_10P30P50P50P[] = _("10P　　30P　　50P　　{EMOJI_MINUS}50P");
STRINGS_MINIGAME_TEXT const u8 gText_AnnouncingRankings[] = _("じゅんいの　はっぴょう！！");
STRINGS_MINIGAME_TEXT const u8 gText_AnnouncingPrizes[] = _("しょうひんの　はっぴょう！！");
STRINGS_MINIGAME_TEXT const u8 gText_1Colon[] = _("1:");
STRINGS_MINIGAME_TEXT const u8 gText_2Colon[] = _("2:");
STRINGS_MINIGAME_TEXT const u8 gText_3Colon[] = _("3:");
STRINGS_MINIGAME_TEXT const u8 gText_4Colon[] = _("4:");
STRINGS_MINIGAME_TEXT const u8 gText_5Colon[] = _("5:");
STRINGS_MINIGAME_TEXT const u8 gText_FirstPlacePrize[] = _(
    "1ばんに　なった　ひとに\n"
    "{DYNAMIC 0}を　プレゼント！！");
STRINGS_MINIGAME_TEXT const u8 gText_CantHoldAnyMore[] = _("{DYNAMIC 0}は　いっぱいです⋯");
STRINGS_MINIGAME_TEXT const u8 gText_FilledStorageSpace[] = _("{DYNAMIC 0}が　いっぱいになってしまった！");
STRINGS_MINIGAME_TEXT const u8 gText_WantToPlayAgain[] = _("もういちど　あそびますか？");
STRINGS_MINIGAME_TEXT const u8 gText_SomeoneDroppedOut[] = _(
    "だれかが　ぬけました\n"
    "つうしんを　しゅうりょう　します");
STRINGS_MINIGAME_TEXT const u8 gText_SpacePoints[] = _("てん");
STRINGS_MINIGAME_TEXT const u8 gText_CommunicationStandby3[] = _("つうしん　たいきちゅうです");
STRINGS_MINIGAME_TEXT const u8 gText_SpacePoints2[] = _("てん");
STRINGS_MINIGAME_TEXT const u8 gText_SpaceTimes3[] = _("かい");
STRINGS_MINIGAME_TEXT const u8 gText_PkmnJumpRecords[] = _("ミニポケモンでジャンプの　きろく");
STRINGS_MINIGAME_TEXT const u8 gText_JumpsInARow[] = _("さいこう　ジャンプかいすう");
STRINGS_MINIGAME_TEXT const u8 gText_BestScore2[] = _("さいこう　とくてん");
STRINGS_MINIGAME_TEXT const u8 gText_ExcellentsInARow[] = _("れんぞく　EXCELLENT");
STRINGS_MINIGAME_TEXT const u8 gText_AwesomeWonF701F700[] = _(
    "せいせきが　よかったので\n"
    "{DYNAMIC 0}を　{DYNAMIC 1}こ　プレゼント！");
STRINGS_MINIGAME_TEXT const u8 gText_FilledStorageSpace2[] = _(
    "{DYNAMIC 0}が　いっぱいに\n"
    "なってしまった！");
STRINGS_MINIGAME_TEXT const u8 gText_CantHoldMore[] = _("{DYNAMIC 0}は　いっぱいです⋯");
STRINGS_MINIGAME_TEXT const u8 gText_WantToPlayAgain2[] = _("もういちど　あそびますか？");
STRINGS_MINIGAME_TEXT const u8 gText_SomeoneDroppedOut2[] = _(
    "だれかがぬけました\n"
    "つうしんを　しゅうりょうします");
STRINGS_MINIGAME_TEXT const u8 gText_CommunicationStandby4[] = _("つうしん　たいきちゅう");
STRINGS_MINIGAME_TEXT const u8 gText_LinkContestResults[] = _("{PLAYER}の　つうしん　コンテスト　せいせき");
STRINGS_MINIGAME_TEXT const u8 gText_1st[] = _("1い");
STRINGS_MINIGAME_TEXT const u8 gText_2nd[] = _("2い");
STRINGS_MINIGAME_TEXT const u8 gText_3rd[] = _("3い");
STRINGS_MINIGAME_TEXT const u8 gText_4th[] = _("4い");
STRINGS_MINIGAME_TEXT const u8 gText_Friend[] = _("someone");
STRINGS_MINIGAME_TEXT const u8 gText_Pokemon3[] = _("pokemon");

STRINGS_EREADER_TEXT const u8 gJPText_MysteryGift[] = _("ふしぎなもらいもの");
STRINGS_EREADER_TEXT const u8 gJPText_DecideStop[] = _("{A_BUTTON}けってい　{B_BUTTON}やめる");
STRINGS_EREADER_TEXT const u8 gJPText_ReceiveMysteryGiftWithEReader[] = _(
    "カードeリーダー{PLUS}　で\n"
    "ふしぎなもらいものを　よみこみます");
STRINGS_EREADER_TEXT const u8 gJPText_SelectConnectFromEReaderMenu[] = _(
    "カードeリーダー{PLUS}の　メニューから\n"
    "‘つうしん’を　えらび");
STRINGS_EREADER_TEXT const u8 gJPText_SelectConnectWithGBA[] = _(
    "‘ゲームボーイアドバンスとつうしん’\n"
    "を　せんたく　してください");
STRINGS_EREADER_TEXT const u8 gJPText_SelectConnectAndPressA[] = _(
    "カードeリーダー{PLUS}の　‘つうしん’を\n"
    "えらんで　Aボタンを　おしてください"); // Unused
STRINGS_EREADER_TEXT const u8 gJPText_LinkIsIncorrect[] = _("せつぞくが　まちがっています");
STRINGS_EREADER_TEXT const u8 gJPText_CardReadingHasBeenHalted[] = _(
    "カードの　よみこみを\n"
    "ちゅうし　しました");
STRINGS_EREADER_TEXT const u8 gJPText_UnableConnectWithEReader[] = _(
    "カードeリーダー{PLUS}と\n"
    "つうしん　できません"); // Unused
STRINGS_EREADER_TEXT const u8 gJPText_Connecting[] = _("つうしん　ちゅう　です");
STRINGS_EREADER_TEXT const u8 gJPText_ConnectionErrorCheckLink[] = _(
    "つうしん　エラーです\n"
    "せつぞくを　たしかめて　ください");
STRINGS_EREADER_TEXT const u8 gJPText_ConnectionErrorTryAgain[] = _(
    "つうしん　エラーです\n"
    "はじめから　やりなおして　ください"); // Link error
STRINGS_EREADER_TEXT const u8 gJPText_AllowEReaderToLoadCard[] = _(
    "カードeリーダー{PLUS}　に\n"
    "カードを　よみこませて　ください");
STRINGS_EREADER_TEXT const u8 gJPText_ConnectionComplete[] = _("つうしん　しゅうりょう！");
STRINGS_EREADER_TEXT const u8 gJPText_NewTrainerHasComeToHoenn[] = _(
    "あらたな　トレーナーが\n"
    "ホウエンに　やってきた！");
STRINGS_EREADER_TEXT const u8 gJPText_PleaseWaitAMoment[] = _("しばらく　おまちください");
STRINGS_EREADER_TEXT const u8 gJPText_WriteErrorUnableToSaveData[] = _(
    "かきこみ　エラー　です\n"
    "データが　ほぞん　できませんでした");

STRINGS_MYSTERY_EVENT_TEXT const u8 gText_LinkStandby2[] = _(
    "つうしん　たいき　ちゅう　です\n"
    "⋯⋯Bボタンで　キャンセル　します");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_PressAToLoadEvent[] = _(
    "Aボタンで　できごとを　よみこみます\n"
    "⋯⋯Bボタンで　キャンセル　します");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_LoadingEvent[] = _("できごとを　よみこみちゅう！！");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_DontRemoveCableTurnOff[] = _(
    "つうしんケーブルを　ぬかないで　ください\n"
    "でんげんを　きらないで　ください");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_EventSafelyLoaded[] = _(
    "できごとの　よみこみが\n"
    "せいじょうに　しゅうりょう　しました");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_MysteryEventIncorrectDevice[] = _(
    "せつぞく　できない　ききの　ようです\n"
    "ただしい　ききと　やりなおしてください");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_LoadErrorEndingSession[] = _(
    "エラーがはっせいしました\n"
    "しゅうりょうします");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_MysteryEventPressA[] = _("Aボタンを　おしてください");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_MysteryEventConnected[] = _("つながりました");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_MysteryEventDataReceived[] = _("データを　じゅしんしました");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_MysteryEventSaveFailed[] = _("セーブできませんでした");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_MysteryEventSaveSucceeded[] = _("セーブできました");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_MysteryEventLoadFailed[] = _("ロードできませんでした");
STRINGS_MYSTERY_EVENT_TEXT const u8 gText_MysteryEventLoadSucceeded[] = _("ロードできました");

STRINGS_FRONTIER_RECORD_TEXT const u8 gText_3Dashes[] = _("ーーー");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_SingleBattleRoomResults[] = _("　{PLAYER}　の　シングル　バトルルーム　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_DoubleBattleRoomResults[] = _("　　{PLAYER}　の　ダブル　バトルルーム　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_MultiBattleRoomResults[] = _("　　{PLAYER}　の　マルチ　バトルルーム　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_LinkMultiBattleRoomResults[] = _("{PLAYER}　の　つうしんマルチ　バトルルーム　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_SingleBattleTourneyResults[] = _("{PLAYER}　の　シングル　バトルトーナメント　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_DoubleBattleTourneyResults[] = _("{PLAYER}　の　ダブル　バトルトーナメント　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_SingleBattleHallResults[] = _("{PLAYER}　の　シングル　バトルホール　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_DoubleBattleHallResults[] = _("{PLAYER}　の　ダブル　バトルホール　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_BattleChoiceResults[] = _("{PLAYER}　の　バトルゲーム　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_SetKOTourneyResults[] = _("{PLAYER}　の　かちぬきチームバトル　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_BattleSwapSingleResults[] = _("{PLAYER}　の　バトルトレード　シングル　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_BattleSwapDoubleResults[] = _("{PLAYER}　の　バトルトレード　ダブル　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_BattleQuestResults[] = _("{PLAYER}　の　バトルアドベンチャー　せいせき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_Lv502[] = _("レベル　50");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_OpenLv[] = _("オープンレベル");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_WinStreak[] = _("{STR_VAR_1}れんしょう");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_Current[] = _("げんざい");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_Record[] = _("さいこう");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_Prev[] = _("ぜんかい");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_FrontierBattle[] = _("バトル");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_RentalSwap[] = _("レンタル/こうかん");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_Total[] = _("つうさん");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_ClearStreak[] = _("{STR_VAR_1}れんぱ");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_Championships[] = _("{STR_VAR_1}かい　ゆうしょう");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_RoomsCleared[] = _("{STR_VAR_1}へや　とっぱ");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_TimesCleared[] = _("{STR_VAR_1}かい　クリア");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_KOsInARow[] = _("{STR_VAR_1}にんぬき");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_TimesVar1[] = _("{STR_VAR_1}かい");
STRINGS_FRONTIER_RECORD_TEXT const u8 gText_FloorsCleared[] = _("{STR_VAR_1}だん　せいは");

STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_PkmnSwap[] = _("ポケモンこうかん　　　　　");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_SelectPkmnToSwap[] = _("てばなすポケモンを　えらんでください");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_SelectPkmnToAccept[] = _("うけとるポケモンを　えらんでください");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_Swap[] = _("てばなす");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_Summary2[] = _("つよさをみる");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_Rechoose[] = _("べつのにする");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_QuitSwapping[] = _("こうかんを　ちゅうし　しますか？");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_Yes3[] = _("はい");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_No3[] = _("いいえ");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_PkmnForSwap[] = _("てばなすポケモン");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_Cancel3[] = _("ちゅうし");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_Swap2[] = _("てばなす");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_Accept[] = _("うけとる");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_AcceptThisPkmn[] = _("このポケモンを　うけとりますか？");
STRINGS_BATTLE_FACTORY_SWAP_TEXT const u8 gText_4Spaces[] = _("　　　　");

STRINGS_DAYCARE const u8 gDaycareText_GetAlongVeryWell[] = _("2ひきの　なかは\nとっても　よい　ようじゃ");
STRINGS_DAYCARE const u8 gDaycareText_GetAlong[] = _("2ひきの　なかは\nまずまずの　ようじゃ");
STRINGS_DAYCARE const u8 gDaycareText_DontLikeOther[] = _("2ひきの　なかは\nそれほど　よくないがなぁ");
STRINGS_DAYCARE const u8 gDaycareText_PlayOther[] = _("2ひきは　おたがいに\nちがう　ポケモンたちと\lあそんでおるがなあ");

STRINGS_BAG_RETURN_TEXT const u8 gText_TheField[] = _("フィールド");
STRINGS_BAG_RETURN_TEXT const u8 gText_TheBattle[] = _("せんとう");
STRINGS_BAG_RETURN_TEXT const u8 gText_ThePokemonList[] = _("ポケモンリスト");
STRINGS_BAG_RETURN_TEXT const u8 gText_TheShop[] = _("ショップ");
STRINGS_BAG_RETURN_TEXT const u8 gText_ThePC[] = _("パソコン");

STRINGS_BAG_RETURN_TABLES const u8 *const gBagMenu_ReturnToStrings[] =
{
    [ITEMMENULOCATION_FIELD]               = gText_TheField,
    [ITEMMENULOCATION_BATTLE]              = gText_TheBattle,
    [ITEMMENULOCATION_PARTY]               = gText_ThePokemonList,
    [ITEMMENULOCATION_SHOP]                = gText_TheShop,
    [ITEMMENULOCATION_BERRY_TREE]          = gText_TheField,
    [ITEMMENULOCATION_BERRY_BLENDER_CRUSH] = gText_TheField,
    [ITEMMENULOCATION_ITEMPC]              = gText_ThePC,
    [ITEMMENULOCATION_FAVOR_LADY]          = gText_TheField,
    [ITEMMENULOCATION_QUIZ_LADY]           = gText_TheField,
    [ITEMMENULOCATION_APPRENTICE]          = gText_TheField,
    [ITEMMENULOCATION_WALLY]               = gText_TheBattle,
    [ITEMMENULOCATION_PCBOX]               = gText_ThePC
};

STRINGS_BAG_RETURN_TABLES const u8 *const gPyramidBagMenu_ReturnToStrings[] =
{
    [PYRAMIDBAG_LOC_FIELD]       = gText_TheField,
    [PYRAMIDBAG_LOC_BATTLE]      = gText_TheBattle,
    [PYRAMIDBAG_LOC_PARTY]       = gText_ThePokemonList,
    [PYRAMIDBAG_LOC_CHOOSE_TOSS] = gText_TheField
};

STRINGS_ITEM_MENU_TEXT const u8 gText_ReturnToVar1[] = _("{B_COPY_VAR_1}へ\nもどります");
STRINGS_ITEM_MENU_TEXT const u8 gText_ItemsPocket[] = _("　ど　う　ぐ　　");
STRINGS_ITEM_MENU_TEXT const u8 gText_PokeBallsPocket[] = _("モンスターボール");
STRINGS_ITEM_MENU_TEXT const u8 gText_TMHMPocket[] = _("　わざマシン　　");
STRINGS_ITEM_MENU_TEXT const u8 gText_BerriesPocket[] = _("　き　の　み　　");
STRINGS_ITEM_MENU_TEXT const u8 gText_KeyItemsPocket[] = _("たいせつなもの　");
STRINGS_ITEM_MENU_TEXT const u8 gText_NumberItem_TMBerry[] = _("{NO}{STR_VAR_1}{STR_VAR_2}");
STRINGS_ITEM_MENU_TEXT const u8 gText_NumberItem_HM[] = _("　　{STR_VAR_1}{STR_VAR_2}");
STRINGS_ITEM_MENU_TEXT const u8 gText_SizeSlash[] = _("おおきさ");
STRINGS_ITEM_MENU_TEXT const u8 gText_FirmSlash[] = _("かたさ");
STRINGS_ITEM_MENU_TEXT const u8 gText_Var1DotVar2[] = _("{STR_VAR_1},{STR_VAR_2}cm");
STRINGS_ITEM_MENU_TEXT const u8 gBerryFirmnessString_VerySoft[] = _("とても　やわらかい");
STRINGS_ITEM_MENU_TEXT const u8 gBerryFirmnessString_Soft[] = _("やわらかい");
STRINGS_ITEM_MENU_TEXT const u8 gBerryFirmnessString_Hard[] = _("かたい");
STRINGS_ITEM_MENU_TEXT const u8 gBerryFirmnessString_VeryHard[] = _("とても　かたい");
STRINGS_ITEM_MENU_TEXT const u8 gBerryFirmnessString_SuperHard[] = _("とてつもなく　かたい");

STRINGS_POKEBLOCK_TEXT const u8 gText_Spicy[] = _("からい");
STRINGS_POKEBLOCK_TEXT const u8 gText_Dry[] = _("しぶい");
STRINGS_POKEBLOCK_TEXT const u8 gText_Sweet[] = _("あまい");
STRINGS_POKEBLOCK_TEXT const u8 gText_Bitter[] = _("にがい");
STRINGS_POKEBLOCK_TEXT const u8 gText_Sour[] = _("すっぱい");
STRINGS_POKEBLOCK_TEXT const u8 gText_Tasty[] = _("うまい"); // Unused
STRINGS_POKEBLOCK_TEXT const u8 gText_Feel[] = _("こまかさ"); // Unused
STRINGS_POKEBLOCK_TEXT const u8 gText_StowCase[] = _("ケースをしまう");
STRINGS_POKEBLOCK_TEXT const u8 gText_LvVar1[] = _("{LV_2}{STR_VAR_1}");
STRINGS_POKEBLOCK_TEXT const u8 gText_ThrowAwayVar1[] = _(
    "{STR_VAR_1}を\n"
    "すてても　よろしいですか？");
STRINGS_POKEBLOCK_TEXT const u8 gText_Var1ThrownAway[] = _(
    "{STR_VAR_1}を\n"
    "すてました");
STRINGS_POKEBLOCK_TEXT const u8 gText_Var1AteTheVar2[] = _(
    "{STR_VAR_1}は　{STR_VAR_2}を\n"
    "たべた！{PAUSE_UNTIL_PRESS}");
STRINGS_POKEBLOCK_TEXT const u8 gText_Var1HappilyAteVar2[] = _(
    "{STR_VAR_1}は　{STR_VAR_2}を\n"
    "よろこんで　たべた！{PAUSE_UNTIL_PRESS}");
STRINGS_POKEBLOCK_TEXT const u8 gText_Var1DisdainfullyAteVar2[] = _(
    "{STR_VAR_1}は　{STR_VAR_2}を\n"
    "いやそうに　たべた！{PAUSE_UNTIL_PRESS}");

STRINGS_POKEDEX const u8 gText_ThisIsAPokemon[] = _(
    "ポケットモンスター\n"
    "⋯⋯すなわち　ポケモン{PAUSE 96}\p");

STRINGS_POKEDEX const u8 gText_5MarksPokemon[] = _("？？？？？ポケモン");

STRINGS_POKEDEX const u8 gText_UnkHeight[] = _("？？？,？m");

STRINGS_POKEDEX const u8 gText_UnkWeight[] = _("？？？,？kg");

STRINGS_POKEDEX const u8 gText_EmptyPkmnCategory[] = _("　　　　　ポケモン");

STRINGS_POKEDEX const u8 gText_EmptyHeight[] = _("　　　,　m");

STRINGS_POKEDEX const u8 gText_EmptyWeight[] = _("　　　,　kg");

STRINGS_POKEDEX const u8 gText_EmptyPokedexInfo1[] = _("の");

STRINGS_POKEDEX const u8 gText_CryOf[] = _("なきごえ");

STRINGS_POKEDEX const u8 gText_EmptyPokedexInfo2[] = _("と");

STRINGS_POKEDEX const u8 gText_SizeComparedTo[] = _("の　おおきさくらべ");

STRINGS_POKEDEX const u8 gText_PokedexRegistration[] = _("ポケモンずかんの　とうろく　かんりょう！");

STRINGS_POKEDEX const u8 gText_SearchingPleaseWait[] = _("けんさくを　しています⋯⋯");

STRINGS_POKEDEX const u8 gText_SearchCompleted[] = _("けんさくが　しゅうりょう　しました！");

STRINGS_POKEDEX const u8 gText_NoMatchingPkmnWereFound[] = _("がいとう　する　ポケモンは　いませんでした⋯⋯");

STRINGS_POKEDEX const u8 gText_SearchForPkmnBasedOnParameters[] = _(
    "じょうけんを　していして\n"
    "ポケモンの　けんさくを　します");

STRINGS_POKEDEX const u8 gText_SwitchPokedexListings[] = _("ずかんリストの　ならびを　きりかえます");

STRINGS_POKEDEX const u8 gText_ReturnToPokedex[] = _("ずかんに　もどります");

STRINGS_POKEDEX const u8 gText_SelectPokedexMode[] = _("ずかんモードを　してい　します");

STRINGS_POKEDEX const u8 gText_SelectPokedexListingMode[] = _("ずかんの　ならびを　してい　します");

STRINGS_POKEDEX const u8 gText_ListByFirstLetter[] = _(
    "なまえの　さいしょの　もじを　してい　します\n"
    "　/みつけたポケモンのみ");

STRINGS_POKEDEX const u8 gText_ListByBodyColor[] = _(
    "からだの　いろを　してい　します\n"
    "　/みつけたポケモンのみ");

STRINGS_POKEDEX const u8 gText_ListByType[] = _(
    "タイプを　してい　します\n"
    "　/つかまえたポケモンのみ");

STRINGS_POKEDEX const u8 gText_ExecuteSearchSwitch[] = _("けんさく/きりかえを　じっこうします");

STRINGS_POKEDEX const u8 gText_DexHoennTitle[] = _("ホウエン　ずかん");

STRINGS_POKEDEX const u8 gText_DexNatTitle[] = _("ぜんこく　ずかん");

STRINGS_POKEDEX const u8 gText_DexSortNumericalTitle[] = _("ばんごう　じゅん");

STRINGS_POKEDEX const u8 gText_DexSortAtoZTitle[] = _("ごじゅうおん　じゅん");

STRINGS_POKEDEX const u8 gText_DexSortHeaviestTitle[] = _("おもい　じゅん");

STRINGS_POKEDEX const u8 gText_DexSortLightestTitle[] = _("かるい　じゅん");

STRINGS_POKEDEX const u8 gText_DexSortTallestTitle[] = _("たかい　じゅん");

STRINGS_POKEDEX const u8 gText_DexSortSmallestTitle[] = _("ひくい　じゅん");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaABC[] = _("あいうえお");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaDEF[] = _("かきくけこ");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaGHI[] = _("さしすせそ");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaJKL[] = _("たちつてと");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaMNO[] = _("なにぬねの");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaPQR[] = _("はひふへほ");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaSTU[] = _("まみむめも");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaVWX[] = _("らりるれろ");

STRINGS_POKEDEX const u8 gText_DexSearchAlphaYZ[] = _("やゆよわをん");

STRINGS_POKEDEX const u8 gText_DexSearchColorRed[] = _("あか");

STRINGS_POKEDEX const u8 gText_DexSearchColorBlue[] = _("あお");

STRINGS_POKEDEX const u8 gText_DexSearchColorYellow[] = _("きいろ");

STRINGS_POKEDEX const u8 gText_DexSearchColorGreen[] = _("みどり");

STRINGS_POKEDEX const u8 gText_DexSearchColorBlack[] = _("くろ");

STRINGS_POKEDEX const u8 gText_DexSearchColorBrown[] = _("ちゃいろ");

STRINGS_POKEDEX const u8 gText_DexSearchColorPurple[] = _("むらさき");

STRINGS_POKEDEX const u8 gText_DexSearchColorGray[] = _("はいいろ");

STRINGS_POKEDEX const u8 gText_DexSearchColorWhite[] = _("しろ");

STRINGS_POKEDEX const u8 gText_DexSearchColorPink[] = _("ピンク");

STRINGS_POKEDEX const u8 gText_DexHoennDescription[] = _("ホウエンちほう　ばん　ポケモンずかん");

STRINGS_POKEDEX const u8 gText_DexNatDescription[] = _("ぜんこく　ばん　ポケモンずかん");

STRINGS_POKEDEX const u8 gText_DexSortNumericalDescription[] = _(
    "ポケモンを\n"
    "ばんごうじゅんで　ひょうじ　します");

STRINGS_POKEDEX const u8 gText_DexSortAtoZDescription[] = _(
    "みつけたポケモンの　なまえを\n"
    "ごじゅうおんじゅんで　ひょうじ　します");

STRINGS_POKEDEX const u8 gText_DexSortHeaviestDescription[] = _(
    "つかまえたポケモンを\n"
    "おもい　じゅんばんで　ひょうじ　します");

STRINGS_POKEDEX const u8 gText_DexSortLightestDescription[] = _(
    "つかまえたポケモンを\n"
    "かるい　じゅんばんで　ひょうじ　します");

STRINGS_POKEDEX const u8 gText_DexSortTallestDescription[] = _(
    "つかまえたポケモンを\n"
    "しんちょうのたかい　じゅんばんで　ひょうじ　します");

STRINGS_POKEDEX const u8 gText_DexSortSmallestDescription[] = _(
    "つかまえたポケモンを\n"
    "しんちょうのひくい　じゅんばんで　ひょうじ　します");

STRINGS_POKEDEX const u8 gText_DexEmptyString[] = _("");

STRINGS_POKEDEX const u8 gText_DexSearchDontSpecify[] = _("してい　しない");

STRINGS_POKEDEX const u8 gText_DexSearchTypeNone[] = _("なし");
STRINGS_POKEDEX const u8 gText_SelectorArrow[] = _("▶");
STRINGS_POKEDEX const u8 gText_EmptySpace[] = _("　"); // Unused

STRINGS_HOF_TEXT const u8 gText_WelcomeToHOF[] = _("でんどういり　おめでとう！");
STRINGS_HOF_TEXT const u8 gText_HOFDexRating[] = _(
    "みつけた　ポケモン　{STR_VAR_1}！\n"
    "つかまえた　ポケモン　{STR_VAR_2}！\p"
    "オダマキはかせの\n"
    "ポケモンずかん　ひょうか！\p"
    "オダマキ“どれどれ\p");
STRINGS_HOF_TEXT const u8 gText_HOFDexSaving[] = _(
    "ここまでの　レポートを　かきしるしています！\n"
    "でんげんを　きらないでください");
STRINGS_HOF_TEXT const u8 gText_HOFCorrupted[] = _("でんどういりの　きろくが　こわれています！");
// This JP-only leading space has no terminator and precedes the referenced text.
STRINGS_HOF_TEXT const u8 gHofNumberLeadingSpace[] = {0x00};
STRINGS_HOF_TEXT const u8 gText_HOFNumber[] = _("だい{STR_VAR_1}かい　でんどういり！");
STRINGS_HOF_TEXT const u8 gText_LeagueChamp[] = _("リーグ　チャンピオン！　おめでとう！");
STRINGS_HOF_TEXT const u8 gText_HOFUnusedEmpty[] = _("");
STRINGS_HOF_TEXT const u8 gText_Number[] = _("No,");
STRINGS_HOF_TEXT const u8 gText_Level[] = _("Lv");
STRINGS_HOF_TEXT const u8 gText_IdNumberSlash[] = _("IDNo,/"); // Unused

STRINGS_BIRCH_MENU const u8 gText_Name[] = _("なまえ");
STRINGS_BIRCH_MENU const u8 gText_IDNumber[] = _("IDNo,");
STRINGS_BIRCH_MENU const u8 gText_BirchInTrouble[] = _(
    "オダマキはかせが　ピンチだ！\n"
    "ポケモンを　だして　たすけてあげよう！");
STRINGS_BIRCH_MENU const u8 gText_ConfirmStarterChoice[] = _("このポケモンにしますか？");
STRINGS_BIRCH_MENU const u8 gText_Pokemon4[] = _("ポケモン");
STRINGS_BIRCH_MENU const u8 gText_FlyToWhere[] = _("どこへ　とびますか？");
STRINGS_BIRCH_MENU const u8 gMenuText_Use[] = _("つかう");
STRINGS_BIRCH_MENU const u8 gMenuText_Toss[] = _("すてる");
STRINGS_BIRCH_MENU const u8 gMenuText_Register[] = _("とうろく");
STRINGS_BIRCH_MENU const u8 gMenuText_Give[] = _("もたせる");
STRINGS_BIRCH_MENU const u8 gMenuText_CheckTag[] = _("タグをみる");

STRINGS_SHOP_TEXT const u8 gText_ShopBuy[] = _("かいに　きた");
STRINGS_SHOP_TEXT const u8 gText_ShopSell[] = _("うりに　きた");
STRINGS_SHOP_TEXT const u8 gText_ShopQuit[] = _("なんでもないです");

STRINGS_SHOP_TEXT const u8 gText_InBagVar1[] = _("もってるかず　{STR_VAR_1}コ");

STRINGS_SHOP_TEXT const u8 gText_QuitShopping[] = _("かいもの　を　やめます");

STRINGS_SHOP_TEXT const u8 gText_Var1CertainlyHowMany[] = _(
    "{STR_VAR_1}　を\n"
    "いくつ　おかいあげに　なりますか？");

STRINGS_SHOP_TEXT const u8 gText_Var1CertainlyHowMany2[] = _(
    "{STR_VAR_1}　‘{STR_VAR_2}'　を\n"
    "いくつ　おかいあげに　なりますか？");

STRINGS_SHOP_TEXT const u8 gText_Var1AndYouWantedVar2[] = _(
    "{STR_VAR_1}を　{STR_VAR_2}コで\n"
    "{STR_VAR_3}¥　おかいあげですか？");

STRINGS_SHOP_TEXT const u8 gText_Var1IsItThatllBeVar2[] = _(
    "{STR_VAR_1}　だね！\n"
    "{STR_VAR_2}¥　だけど　かうかい？");

STRINGS_SHOP_TEXT const u8 gText_YouWantedVar1ThatllBeVar2[] = _(
    "{STR_VAR_1}　ですね！\n"
    "{STR_VAR_2}¥　だけど　かいますか？");

STRINGS_SHOP_TEXT const u8 gText_HereYouGoThankYou[] = _(
    "はい　まいど！\n"
    "ありがとう　ございます");

STRINGS_SHOP_TEXT const u8 gText_ThankYouIllSendItHome[] = _(
    "どうも　ありがとう！\n"
    "じたくの　パソコンに　おくって　おきますね！");

STRINGS_SHOP_TEXT const u8 gText_ThanksIllSendItHome[] = _(
    "どうも　ありがとう！\n"
    "じたくの　パソコンに　おくって　おくね！");

STRINGS_SHOP_TEXT const u8 gText_YouDontHaveMoney[] = _("おかねが　たりないですよ！{PAUSE_UNTIL_PRESS}");

STRINGS_SHOP_TEXT const u8 gText_NoMoreRoomForThis[] = _(
    "それ　いじょう\n"
    "もちきれない　ですよ！{PAUSE_UNTIL_PRESS}");

STRINGS_SHOP_TEXT const u8 gText_SpaceForVar1Full[] = _(
    "{STR_VAR_1}　を\n"
    "いれる　ばしょが　いっぱいです{PAUSE_UNTIL_PRESS}");

STRINGS_SHOP_TEXT const u8 gText_AnythingElseICanHelp[] = _(
    "その　ほかに　わたしどもで\n"
    "なにか　おちからに　なれることは？");

STRINGS_SHOP_TEXT const u8 gText_CanIHelpWithAnythingElse[] = _(
    "その　ほかに\n"
    "なにか　ちからに　なれることは？");

STRINGS_SHOP_TEXT const u8 gText_ThrowInPremierBall[] = _(
    "プレミアボール　1コ\n"
    "おまけ　しておきますね！{PAUSE_UNTIL_PRESS}");

STRINGS_SHOP_TEXT const u8 gText_CantBuyKeyItem[] = _(
    "{STR_VAR_2}を\n"
    "かいとるわけには　いきません！{PAUSE_UNTIL_PRESS}");

STRINGS_SHOP_TEXT const u8 gText_HowManyToSell[] = _(
    "{STR_VAR_2}を\n"
    "いくつ　うりますか？");

STRINGS_SHOP_TEXT const u8 gText_ICanPayVar1[] = _(
    "{STR_VAR_1}¥で　ひきとらせて　いただきます\n"
    "よろしいですか？");

STRINGS_SHOP_TEXT const u8 gText_TurnedOverVar1ForVar2[] = _(
    "{STR_VAR_2}　を　わたして\n"
    "{STR_VAR_1}¥　うけとった！");

STRINGS_SHOP_TEXT const u8 gText_PokedollarVar1[] = _("{STR_VAR_1}¥");

STRINGS_PARTY_MENU_TEXT const u8 gText_Shift[] = _("いれかえる");
STRINGS_PARTY_MENU_TEXT const u8 gText_SendOut[] = _("せんとうにだす");
STRINGS_PARTY_MENU_TEXT const u8 gText_Switch2[] = _("ならびかえ");
STRINGS_PARTY_MENU_TEXT const u8 gText_Summary5[] = _("つよさをみる");
STRINGS_PARTY_MENU_TEXT const u8 gText_Moves[] = _("つかえるわざ");
STRINGS_PARTY_MENU_TEXT const u8 gText_Enter[] = _("さんかする");
STRINGS_PARTY_MENU_TEXT const u8 gText_NoEntry[] = _("さんかしない");
STRINGS_PARTY_MENU_TEXT const u8 gText_Take2[] = _("メールを　とる");
STRINGS_PARTY_MENU_TEXT const u8 gText_Read2[] = _("メールを　よむ");
STRINGS_PARTY_MENU_TEXT const u8 gText_Trade4[] = _("こうかんする");

STRINGS_PARTY_MENU_TEXT const u8 gText_HP3[] = _("たいりょく");

STRINGS_PARTY_MENU_TEXT const u8 gText_SpAtk3[] = _("とくこう");

STRINGS_PARTY_MENU_TEXT const u8 gText_SpDef3[] = _("とくぼう");

STRINGS_PARTY_MENU_TEXT const u8 gText_WontHaveEffect[] = _("つかっても　こうかがないよ{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_CantBeUsedOnPkmn[] = _(
    "そのポケモンには\n"
    "つかえません！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnCantSwitchOut[] = _(
    "{STR_VAR_1}を　もどすことが\n"
    "できない！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnAlreadyInBattle[] = _(
    "{STR_VAR_1}は　すでに\n"
    "せんとうに　でています{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnAlreadySelected[] = _(
    "{STR_VAR_1}は　すでに\n"
    "せんたく　されています{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnHasNoEnergy[] = _(
    "{STR_VAR_1}は　たたかうための\n"
    "げんきが　のこっていません！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_CantSwitchWithAlly[] = _(
    "{STR_VAR_1}の　ポケモンは　じぶんの\n"
    "ポケモンと　いれかえることは　できません！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_EggCantBattle[] = _(
    "タマゴを\n"
    "せんとうに　だすことは　できません！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_CantUseUntilNewBadge[] = _(
    "あたらしい　バッジを　てにするまで\n"
    "まだ　つかえません{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_NoMoreThanVar1Pkmn[] = _(
    "さんか　できる　ポケモンは\n"
    "{STR_VAR_1}ひき　まで　です！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_SendMailToPC[] = _(
    "とった　メールを　パソコンに\n"
    "てんそうしますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_MailSentToPC[] = _(
    "メールを　パソコンに\n"
    "てんそうしました{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PCMailboxFull[] = _(
    "パソコンの　メールボックスが\n"
    "いっぱいです！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_MailMessageWillBeLost[] = _(
    "メールを　とると　メッセージが\n"
    "きえてしまいますが　よろしいですか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_RemoveMailBeforeItem[] = _(
    "メールを　はずさないと\n"
    "どうぐは　もてません！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnWasGivenItem[] = _(
    "{STR_VAR_1}に\n"
    "{STR_VAR_2}を　もたせた！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnAlreadyHoldingItemSwitch[] = _(
    "{STR_VAR_1}は　すでに\n"
    "{STR_VAR_2}を　もっています\p"
    "もっている　どうぐを\n"
    "とりかえますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnNotHolding[] = _(
    "{STR_VAR_1}は　なにも\n"
    "どうぐを　もって　いません！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_ReceivedItemFromPkmn[] = _(
    "{STR_VAR_1}から\n"
    "{STR_VAR_2}を　あずかりました！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_MailTakenFromPkmn[] = _(
    "ポケモンから　メールを\n"
    "とりました！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_SwitchedPkmnItem[] = _(
    "{STR_VAR_2}を　あずかって\n"
    "あらたに　{STR_VAR_1}を　もたせました！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnHoldingItemCantHoldMail[] = _(
    "すでに　どうぐを　もっているので\n"
    "メールを　もたせることが　できません{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_MailTransferredFromMailbox[] = _("ボックスから　メールを　うつしました{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_BagFullCouldNotRemoveItem[] = _(
    "バッグが　いっぱいで\n"
    "ポケモンの　どうぐを　うけとれません！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnLearnedMove3[] = _(
    "{STR_VAR_1}は　あたらしく\n"
    "{STR_VAR_2}を　おぼえた！");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnCantLearnMove[] = _(
    "{STR_VAR_1}と　{STR_VAR_2}は\n"
    "あいしょうが　わるかった！\p"
    "{STR_VAR_2}は　おぼえられない！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnNeedsToReplaceMove[] = _(
    "{STR_VAR_1}は　あたらしく\n"
    "{STR_VAR_2}を　おぼえたい⋯⋯！\p"
    "しかし　{STR_VAR_1}は　わざを　4つ\n"
    "おぼえるので　せいいっぱいだ！\p"
    "{STR_VAR_2}の　かわりに\n"
    "ほかの　わざを　わすれさせますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_StopLearningMove2[] = _(
    "それでは⋯⋯　{STR_VAR_2}を\n"
    "おぼえるのを　あきらめますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_MoveNotLearned[] = _(
    "{STR_VAR_1}は　{STR_VAR_2}を\n"
    "おぼえずに　おわった！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_WhichMoveToForget[] = _(
    "どの　わざを\n"
    "わすれさせたい？{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_12PoofForgotMove[] = _(
    "1　{PAUSE 15}2の　{PAUSE 15}⋯{PAUSE 15}⋯{PAUSE 15}⋯　{PAUSE 15}{PLAY_SE 56}　ポカン！\p"
    "{STR_VAR_1}は　{STR_VAR_2}の\n"
    "つかいかたを　きれいに　わすれた！\p"
    "そして⋯⋯！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnAlreadyKnows[] = _(
    "{STR_VAR_1}は　すでに\n"
    "{STR_VAR_2}を　おぼえています{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnHPRestoredByVar2[] = _(
    "{STR_VAR_1}の　たいりょくが\n"
    "{STR_VAR_2}　かいふくした{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnCuredOfPoison[] = _(
    "{STR_VAR_1}の　どくは\n"
    "きれい　さっぱり　なくなった！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnCuredOfParalysis[] = _(
    "{STR_VAR_1}の　からだの\n"
    "しびれが　とれた{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnWokeUp2[] = _(
    "{STR_VAR_1}は\n"
    "めを　さました{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnBurnHealed[] = _(
    "{STR_VAR_1}の\n"
    "やけどが　なおった{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnThawedOut[] = _(
    "{STR_VAR_1}の　からだの\n"
    "こおりが　とけた{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PPWasRestored[] = _(
    "わざポイントが\n"
    "かいふくした！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnRegainhedHealth[] = _(
    "{STR_VAR_1}は\n"
    "げんきを　とりもどした！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnBecameHealthy[] = _(
    "{STR_VAR_1}は\n"
    "けんこうになった！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_MovesPPIncreased[] = _(
    "{STR_VAR_1}の\n"
    "わざポイントが　ふえた！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnElevatedToLvVar2[] = _(
    "{STR_VAR_1}の\n"
    "レベルが　{STR_VAR_2}になった！");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnBaseVar2StatIncreased[] = _(
    "{STR_VAR_1}の　{STR_VAR_2}の\n"
    "きそ　ポイントが　あがった！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnFriendlyBaseVar2Fell[] = _(
    "{STR_VAR_1}が　ちょっと　なついた！\n"
    "{STR_VAR_2}の　きそポイントが　さがった！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnAdoresBaseVar2Fell[] = _(
    "{STR_VAR_1}は　さいこうに　なついている！\n"
    "{STR_VAR_2}の　きそポイントが　さがった！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnFriendlyBaseVar2CantFall[] = _(
    "{STR_VAR_1}は　ちょっと　なついた！\n"
    "{STR_VAR_2}の　きそポイントは　もうさがらない！{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnSnappedOutOfConfusion[] = _(
    "{STR_VAR_1}の\n"
    "こんらんが　とけた{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnGotOverInfatuation[] = _(
    "{STR_VAR_1}の\n"
    "メロメロが　とけた{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_ThrowAwayItem[] = _(
    "{STR_VAR_1}を\n"
    "すてても　よろしいですか");

STRINGS_PARTY_MENU_TEXT const u8 gText_ItemThrownAway[] = _(
    "{STR_VAR_1}を\n"
    "すてました{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_TeachWhichPokemon2[] = _("どのポケモンに　おぼえさせますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_ChoosePokemon[] = _("ポケモンを　えらんで　ください");

STRINGS_PARTY_MENU_TEXT const u8 gText_MoveToWhere[] = _("どこに　いどうしますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_TeachWhichPokemon[] = _("どのポケモンに　おしえますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_UseOnWhichPokemon[] = _("どのポケモンに　つかいますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_GiveToWhichPokemon[] = _("どのポケモンに　もたせますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_DoWhatWithPokemon[] = _("{STR_VAR_1}を　どうする？");

STRINGS_PARTY_MENU_TEXT const u8 gText_NothingToCut[] = _("きれるものが　ありません！");

STRINGS_PARTY_MENU_TEXT const u8 gText_CantSurfHere[] = _("ここでは　のれません");

STRINGS_PARTY_MENU_TEXT const u8 gText_AlreadySurfing[] = _("すでに　なみのり　しています");

STRINGS_PARTY_MENU_TEXT const u8 gText_CantUseHere[] = _("ここでは　つかえません");

STRINGS_PARTY_MENU_TEXT const u8 gText_RestoreWhichMove[] = _("どれを　かいふくする？");

STRINGS_PARTY_MENU_TEXT const u8 gText_BoostPP[] = _("どれを　ふやす？");

STRINGS_PARTY_MENU_TEXT const u8 gText_DoWhatWithItem[] = _("もちものを　どうしますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_NoPokemonForBattle[] = _("これでは　たたかえません！");

STRINGS_PARTY_MENU_TEXT const u8 gText_ChoosePokemon2[] = _("どのポケモンを　あずけますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_NotEnoughHp[] = _("たいりょくが　たりません⋯⋯");

STRINGS_PARTY_MENU_TEXT const u8 gText_PokemonAreNeeded[] = _("{STR_VAR_1}ひき　そろっていません");

STRINGS_PARTY_MENU_TEXT const u8 gText_PokemonCantBeSame[] = _("おなじ　ポケモンが　います！");

STRINGS_PARTY_MENU_TEXT const u8 gText_NoIdenticalHoldItems[] = _("おなじ　どうぐを　もってます");

STRINGS_PARTY_MENU_TEXT const u8 gText_CurrentIsTooFast[] = _("ながれが　はやくて　ダメだ！");

STRINGS_PARTY_MENU_TEXT const u8 gText_DoWhatWithMail[] = _("メールを　どうしますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_ChoosePokemonCancel[] = _("ポケモンか　もどるを　せんたく");

STRINGS_PARTY_MENU_TEXT const u8 gText_ChoosePokemonConfirm[] = _("ポケモンを　えらんで　けってい");

STRINGS_PARTY_MENU_TEXT const u8 gText_EnjoyCycling[] = _("サイクリングを　たのしもう！");

STRINGS_PARTY_MENU_TEXT const u8 gText_InUseAlready_PM[] = _("すでに　つかっています！");

STRINGS_PARTY_MENU_TEXT const u8 gText_AlreadyHoldingOne[] = _(
    "{STR_VAR_1}は\n"
    "{STR_VAR_2}を　もっています");

STRINGS_PARTY_MENU_TEXT const u8 gText_NoUse[] = _("つかえません");

// JP labels an eligible but unselected party member as not participating, unlike US "ABLE".
STRINGS_PARTY_MENU_TEXT const u8 gText_NotParticipating[] = _("さんかしない");

STRINGS_PARTY_MENU_TEXT const u8 gText_First_PM[] = _("いちばんめ");

STRINGS_PARTY_MENU_TEXT const u8 gText_Second_PM[] = _("にばんめ");

STRINGS_PARTY_MENU_TEXT const u8 gText_Third_PM[] = _("さんばんめ");

STRINGS_PARTY_MENU_TEXT const u8 gText_Able2[] = _("でられます");

STRINGS_PARTY_MENU_TEXT const u8 gText_NotAble[] = _("でられません");

STRINGS_PARTY_MENU_TEXT const u8 gText_Able3[] = _("おぼえられる！");

STRINGS_PARTY_MENU_TEXT const u8 gText_NotAble2[] = _("おぼえられない");

STRINGS_PARTY_MENU_TEXT const u8 gText_Learned[] = _("もうおぼえてる");

STRINGS_PARTY_MENU_TEXT const u8 gText_Have[] = _("もっている");

STRINGS_PARTY_MENU_TEXT const u8 gText_DontHave[] = _("もっていない");

STRINGS_PARTY_MENU_TEXT const u8 gText_Fourth[] = _("よんばんめ");

STRINGS_PARTY_MENU_TEXT const u8 gText_PkmnCantParticipate[] = _("その　ポケモンは　さんか　できません{PAUSE_UNTIL_PRESS}");

STRINGS_PARTY_MENU_TEXT const u8 gText_CancelParticipation[] = _("さんかを　やめますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_CancelBattle[] = _("たいせんを　やめますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_ReturnToWaitingRoom[] = _("ひかえしつに　もどりますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_CancelChallenge[] = _("ちょうせんを　やめますか？");

STRINGS_PARTY_MENU_TEXT const u8 gText_EscapeFromHere[] = _(
    "ここを　だっしゅつ　して\n"
    "{STR_VAR_1}に　もどる？");

STRINGS_PARTY_MENU_TEXT const u8 gText_ReturnToHealingSpot[] = _(
    "さいごに　やすんだ\n"
    "{STR_VAR_1}に　テレポートする？");

STRINGS_PARTY_MENU_TEXT const u8 gText_PauseUntilPress[] = _("{PAUSE_UNTIL_PRESS}");

STRINGS_TRADE_TEXT_PREFIX const u8 gJPText_AreYouSureYouWantToSpinTradeMon[] = _(
    "{STR_VAR_1}を　ぐるぐるこうかんに\n"
    "だして　よろしいですか？");

STRINGS_TRADE_TEXT_BODY_START const u8 gText_OnlyPkmnForBattle[] = _(
    "そのポケモンを　こうかんすると\n"
    "せんとうできなくなっちゃうよ！");

STRINGS_TRADE_TEXT_BODY const u8 gText_PkmnCantBeTradedNow[] = _(
    "その　ポケモンは　いま\n"
    "こうかんに　だせません");

STRINGS_TRADE_TEXT_BODY const u8 gText_EggCantBeTradedNow[] = _(
    "タマゴは　いま\n"
    "こうかんに　だせません");

STRINGS_TRADE_TEXT_BODY const u8 gText_OtherTrainersPkmnCantBeTraded[] = _(
    "あいての　ポケモンとは\n"
    "いまは　こうかん　できません");

STRINGS_TRADE_TEXT_BODY const u8 gText_OtherTrainerCantAcceptPkmn[] = _(
    "　いまは　そのポケモンを　\n"
    "あいては　うけとることが　できません");

STRINGS_TRADE_TEXT_BODY const u8 gText_CantTradeWithTrainer[] = _(
    "その　あいてとは　いまは　\n"
    "こうかん　できません");

STRINGS_TRADE_TEXT_BODY const u8 gText_NotPkmnOtherTrainerWants[] = _(
    "　　　あいての　ほしがっている　タイプの\n"
    "ポケモンでは　ありません");

STRINGS_TRADE_TEXT_BODY const u8 gText_ThatIsntAnEgg[] = _("　それは　タマゴでは　ありません");

STRINGS_SUMMARY_TEXT const u8 gText_Register[] = _("とうろくする");

STRINGS_SUMMARY_TEXT const u8 gText_Attack3[] = _("こうげき");

STRINGS_SUMMARY_TEXT const u8 gText_Defense3[] = _("ぼうぎょ");

STRINGS_SUMMARY_TEXT const u8 gText_SpAtk4[] = _("とくこう");

STRINGS_SUMMARY_TEXT const u8 gText_SpDef4[] = _("とくぼう");

STRINGS_SUMMARY_TEXT const u8 gText_Speed2[] = _("すばやさ");

STRINGS_SUMMARY_TEXT const u8 gText_HP4[] = _("HP");

STRINGS_SUMMARY_TEXT const u8 gText_Remaining[] = _("あと");

STRINGS_SUMMARY_TEXT const u8 gText_OTSlash[] = _("おや/");

STRINGS_SUMMARY_TEXT const u8 gText_RentalPkmn[] = _("レンタルポケモン");

STRINGS_SUMMARY_TEXT const u8 gText_TypeSlash[] = _("タイプ/");

STRINGS_SUMMARY_TEXT const u8 gText_Power[] = _("いりょく");

STRINGS_SUMMARY_TEXT const u8 gText_Accuracy2[] = _("めいちゅう");

STRINGS_SUMMARY_TEXT const u8 gText_Appeal[] = _("アピール");

STRINGS_SUMMARY_TEXT const u8 gText_Jam[] = _("ぼうがい");

STRINGS_SUMMARY_TEXT const u8 gText_Status[] = _("じょうたい");

STRINGS_SUMMARY_TEXT const u8 gText_ExpPoints[] = _("げんざいのけいけんち");

STRINGS_SUMMARY_TEXT const u8 gText_NextLv[] = _("レベルアップまで");

STRINGS_SUMMARY_TEXT const u8 gText_RibbonsVar1[] = _("げんざい　{STR_VAR_1}こ");

// The following empty string supplies the EOS for this JP nature suffix.
STRINGS_SUMMARY_TEXT const u8 gText_NatureAdjectiveEnding[] = __("な");
STRINGS_SUMMARY_TEXT const u8 gText_EmptyString5[] = _("");
STRINGS_SUMMARY_TEXT const u8 gText_Events[] = _("イベント");

STRINGS_SUMMARY_TEXT const u8 gText_Switch[] = _("いれかえ");

STRINGS_SUMMARY_TEXT const u8 gText_PkmnInfo[] = _("ポケモンじょうほう");

STRINGS_SUMMARY_TEXT const u8 gText_PkmnSkills[] = _("ポケモンのうりょく");

STRINGS_SUMMARY_TEXT const u8 gText_BattleMoves[] = _("たたかうわざ");

STRINGS_SUMMARY_TEXT const u8 gText_ContestMoves[] = _("コンテストわざ");

STRINGS_SUMMARY_TEXT const u8 gText_Info[] = _("きりかえ");

STRINGS_SUMMARY_TEXT const u8 gText_EggWillTakeALongTime[] = _(
    "この　タマゴは\n"
    "うまれるまで　かなり　かかりそう");

STRINGS_SUMMARY_TEXT const u8 gText_EggWillTakeSomeTime[] = _(
    "なにが　うまれて　くるのかな？\n"
    "うまれる　まで　まだまだ　かかりそう");

STRINGS_SUMMARY_TEXT const u8 gText_EggWillHatchSoon[] = _(
    "ときどき　うごいて　いるようだ\n"
    "うまれる　まで　もうちょっと　かな？");

STRINGS_SUMMARY_TEXT const u8 gText_EggAboutToHatch[] = _(
    "なかから　おとが　きこえてくる\n"
    "もうすぐ　うまれそう！");

STRINGS_SUMMARY_TEXT const u8 gText_HMMovesCantBeForgotten2[] = _(
    "それは　たいせつなわざです\n"
    "わすれさせることは　できません！");

STRINGS_SUMMARY_TEXT const u8 gText_XNatureMetAtYZ[] = _(
    "{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}せいかく　{LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}のとき\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}で　であった");

STRINGS_SUMMARY_TEXT const u8 gText_XNatureHatchedAtYZ[] = _(
    "{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}せいかく　{LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}のとき\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}で　かえった");

STRINGS_SUMMARY_TEXT const u8 gText_XNatureObtainedInTrade[] = _(
    "{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}せいかく\n"
    "つうしんこうかんに　よって　であった");

STRINGS_SUMMARY_TEXT const u8 gText_XNatureFatefulEncounter[] = _(
    "{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}せいかく　{LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}のとき\n"
    "うんめいてきな　であいを　した");

STRINGS_SUMMARY_TEXT const u8 gText_XNatureProbablyMetAt[] = _(
    "{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}せいかく　{LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}のとき\n"
    "{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}で　あったようだ");

STRINGS_SUMMARY_TEXT const u8 gText_XNature[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}せいかく");

STRINGS_SUMMARY_TEXT const u8 gText_XNatureMetSomewhereAt[] = _(
    "{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}せいかく　{LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}のとき\n"
    "どこかで　であった");

STRINGS_SUMMARY_TEXT const u8 gText_XNatureHatchedSomewhereAt[] = _(
    "{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1}{DYNAMIC 5}せいかく　{LV_2}{DYNAMIC 0}{DYNAMIC 3}{DYNAMIC 1}のとき\n"
    "どこかで　かえった");

STRINGS_SUMMARY_TEXT const u8 gText_OddEggFoundByCouple[] = _(
    "そだてや　ふうふ　から　もらった\n"
    "ふしぎな　ポケモンのタマゴ");

STRINGS_SUMMARY_TEXT const u8 gText_PeculiarEggNicePlace[] = _(
    "ステキな　ばしょで　てにいれた\n"
    "ふしぎな　ふしぎな　ポケモンのタマゴ");

STRINGS_SUMMARY_TEXT const u8 gText_PeculiarEggTrade[] = _(
    "つうしんこうかんで　てにいれた\n"
    "ふしぎな　ポケモンのタマゴ");

STRINGS_SUMMARY_TEXT const u8 gText_EggFromHotSprings[] = _(
    "おんせんばあさん　から　もらった\n"
    "ふしぎな　ポケモンのタマゴ");

STRINGS_SUMMARY_TEXT const u8 gText_EggFromTraveler[] = _(
    "たびの　おじさん　から　もらった\n"
    "ふしぎな　ポケモンのタマゴ");

STRINGS_COMMON const u8 gMenuText_Confirm[] = _("けってい");
STRINGS_COMMON const u8 gMenuText_Walk[] = _("おりる");
STRINGS_COMMON const u8 gText_Cancel[] = _("もどる");
STRINGS_COMMON const u8 gText_Cancel2[] = _("やめる");
STRINGS_COMMON const u8 gMenuText_Show[] = _("みせる");
STRINGS_COMMON const u8 gText_EmptyString2[] = _("");
STRINGS_COMMON const u8 gText_Cancel7[] = _("キャンセル"); // Unused
STRINGS_COMMON const u8 gText_Item[] = _("もちもの");
STRINGS_COMMON const u8 gText_Mail[] = _("メール");
STRINGS_COMMON const u8 gText_Take[] = _("あずかる");
STRINGS_COMMON const u8 gText_Store[] = _("あずける");
STRINGS_COMMON const u8 gMenuText_Check[] = _("みる");
STRINGS_COMMON const u8 gText_None[] = _("なし");
STRINGS_COMMON const u8 gMenuText_Deselect[] = _("かいじょ");
STRINGS_COMMON const u8 gText_ThreeMarks[] = _("？？？");
STRINGS_COMMON const u8 gText_FiveMarks[] = _("？？？？？");
STRINGS_COMMON const u8 gText_Slash[] = _("/");
STRINGS_COMMON const u8 gText_OneDash[] = _("ー");
STRINGS_COMMON const u8 gText_TwoDashes[] = _("ーー");
STRINGS_COMMON const u8 gText_ThreeDashes[] = _("ーーー");
STRINGS_COMMON const u8 gText_MaleSymbol[] = _("♂");
STRINGS_COMMON const u8 gText_FemaleSymbol[] = _("♀");
STRINGS_COMMON const u8 gText_LevelSymbol[] = _("{LV_2}");
// The JP text has no CLEAR control after the NO symbol.
STRINGS_COMMON const u8 gText_NumberClear01[] = _("{NO}");
STRINGS_COMMON const u8 gText_PlusSymbol[] = _("{PLUS}"); // Unused
STRINGS_COMMON const u8 gText_RightArrow[] = _("{RIGHT_ARROW_2}"); // Unused
STRINGS_COMMON const u8 gText_IDNumber2[] = _("{ID}{NO}");
STRINGS_COMMON const u8 gText_Space[] = _("　");
STRINGS_COMMON const u8 gText_SelectorArrow2[] = _("▶");
STRINGS_COMMON const u8 gText_GoBackPrevMenu[] = _("まえに　もどります！");
STRINGS_COMMON const u8 gText_WhatWouldYouLike[] = _("なにを　しますか？");
STRINGS_COMMON const u8 gMenuText_Give2[] = _("あげる");
STRINGS_COMMON const u8 gText_xVar1[] = _("×{STR_VAR_1}");

STRINGS_COMMON const u8 gText_Berry2[] = _("のみ");

STRINGS_COMMON const u8 gText_Coins[] = _("{STR_VAR_1}まい");

STRINGS_COMMON const u8 gText_CloseBag[] = _("バッグをとじる");

STRINGS_COMMON const u8 gText_Var1IsSelected[] = _(
    "{STR_VAR_1}を\n"
    "どうしますか？");

STRINGS_COMMON const u8 gText_CantWriteMail[] = _(
    "ここで　メールを\n"
    "かくことは　できません！");

STRINGS_COMMON const u8 gText_NoPokemon[] = _("ポケモンが　いませんよ！");

STRINGS_COMMON const u8 gText_MoveVar1Where[] = _(
    "{STR_VAR_1}を\n"
    "どこに　いれますか？");

STRINGS_COMMON const u8 gText_Var1CantBeHeld[] = _(
    "{STR_VAR_1}を\n"
    "もたせることは　できません！");

STRINGS_COMMON const u8 gText_Var1CantBeHeldHere[] = _(
    "ここでは　{STR_VAR_1}を\n"
    "もたせることは　できません！");

STRINGS_COMMON const u8 gText_DepositHowManyVar1[] = _(
    "{STR_VAR_1}　を\n"
    "いくつ　あずけますか？");

STRINGS_COMMON const u8 gText_DepositedVar2Var1s[] = _(
    "{STR_VAR_1}　を\n"
    "{STR_VAR_2}コ　あずけました");

STRINGS_COMMON const u8 gText_NoRoomForItems[] = _(
    "これいじょう\n"
    "あずけられません！");

STRINGS_COMMON const u8 gText_CantStoreImportantItems[] = _(
    "たいせつな　どうぐは\n"
    "パソコンに　\n"
    "いれられません！");

STRINGS_COMMON const u8 gText_TooImportantToToss[] = _(
    "これは　とても\n"
    "たいせつなモノ　なので\n"
    "すてられません！");

STRINGS_COMMON const u8 gText_TossHowManyVar1s[] = _(
    "{STR_VAR_1}を\n"
    "いくつ　すてますか？");

STRINGS_COMMON const u8 gText_ThrewAwayVar2Var1s[] = _(
    "{STR_VAR_1}を\n"
    "{STR_VAR_2}コ　すてました");

STRINGS_COMMON const u8 gText_ConfirmTossItems[] = _(
    "{STR_VAR_1}を\n"
    "{STR_VAR_2}コ　すてても\n"
    "よろしいですか？");

STRINGS_COMMON const u8 gText_DadsAdvice[] = _(
    "おとうさんの　ことば⋯⋯\n"
    "{PLAYER}！　こういうものには\l"
    "つかいどきが　あるんだ！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_CantDismountBike[] = _("ここでは　おりられない！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_ItemFinderNearby[] = _(
    "おっ！\n"
    "マシンが　はんのう　しているぞ！\p"
    "ちかくに　どうぐが　うまってる！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_ItemFinderOnTop[] = _(
    "マシンが　あしもとで\n"
    "すごく　はんのう　しているぞ！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_ItemFinderNothing[] = _(
    "⋯⋯　⋯⋯　ふう！\n"
    "⋯⋯　なんにも　はんのう　しない{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_CoinCase[] = _(
    "あなたの　コイン\n"
    "{STR_VAR_1}まい{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_BootedUpTM[] = _("わざマシンを　きどうした！");

STRINGS_COMMON const u8 gText_BootedUpHM[] = _("ひでんマシンを　きどうした！");

STRINGS_COMMON const u8 gText_TMHMContainedVar1[] = _(
    "なかには　{STR_VAR_1}が\n"
    "きろくされていた！\p"
    "{STR_VAR_1}を\n"
    "ポケモンに　おぼえさせますか？");

STRINGS_COMMON const u8 gText_PlayerUsedVar2[] = _(
    "{PLAYER}は\n"
    "{STR_VAR_2}を　つかった！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_RepelEffectsLingered[] = _(
    "まだ　まえに　つかった　スプレーの\n"
    "こうかが　のこってます！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_UsedVar2WildLured[] = _(
    "{PLAYER}は\n"
    "{STR_VAR_2}を　つかった！\p"
    "ポケモンと\n"
    "そうぐう　しやすくなった！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_UsedVar2WildRepelled[] = _(
    "{PLAYER}は\n"
    "{STR_VAR_2}を　つかった！\p"
    "ポケモンと\n"
    "そうぐう　しにくくなった！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_BoxFull[] = _("ボックスが　いっぱい　です！{PAUSE_UNTIL_PRESS}");

STRINGS_COMMON const u8 gText_PowderQty[] = _("こなの　りょう　{STR_VAR_1}{PAUSE_UNTIL_PRESS}");

STRINGS_NAMING_SCREEN_TEXT const u8 gText_YourName[] = _("あなた　の　なまえは？");
STRINGS_NAMING_SCREEN_TEXT const u8 gText_BoxName[] = _("ボックス　の　なまえは？");
STRINGS_NAMING_SCREEN_TEXT const u8 gText_PkmnsNickname[] = _("{STR_VAR_1}　の　ニックネームは？");
STRINGS_NAMING_SCREEN_TEXT const u8 gText_TellHimTheWords[] = _("おじさんに　ことばを　おしえよう");
// Font 0 renders the JP character-transform hint as ゛゜大小.
STRINGS_NAMING_SCREEN_TEXT const u8 gText_NamingScreenInstructions[] = _("{DPAD_NONE}いどう　　{R_BUTTON}{JP_DAKUTEN}{JP_HANDAKUTEN}{JP_BIG}{JP_SMALL}　　{A_BUTTON}けってい　{B_BUTTON}もどる　");
STRINGS_NAMING_SCREEN_LEGACY const u8 gJPText_NamingScreenTransferredToPC[] = _("{STR_VAR_1}は　パソコンへ　てんそうされた！");

STRINGS_MAIN_MENU const u8 gText_MainMenuNewGame[] = _("さいしょから　はじめる");
STRINGS_MAIN_MENU const u8 gText_MainMenuContinue[] = _("つづきから　はじめる");
STRINGS_MAIN_MENU const u8 gText_MainMenuOption[] = _("せっていを　かえる");
STRINGS_MAIN_MENU const u8 gText_MainMenuMysteryGift[] = _("ふしぎな　おくりもの");
STRINGS_MAIN_MENU const u8 gText_MainMenuMysteryGift2[] = _("ふしぎな　もらいもの");
STRINGS_MAIN_MENU const u8 gText_MainMenuMysteryEvents[] = _("ふしぎな　できごと");
STRINGS_MAIN_MENU const u8 gText_WirelessNotConnected[] = _(
    "ワイヤレスアダプタ　が\n"
    "つながっていません");
STRINGS_MAIN_MENU const u8 gText_MysteryGiftCantUse[] = _(
    "ワイヤレスアダプタ　を　さしたまま\n"
    "ふしぎなもらいもの　は　できません");
STRINGS_MAIN_MENU const u8 gText_MysteryEventsCantUse[] = _(
    "ワイヤレスアダプタ　を　さしたまま\n"
    "ふしぎなできごと　は　できません");
STRINGS_MAIN_MENU const u8 gText_UpdatingSaveExternalData[] = _(
    "がいぶデータにより　レポートを　こうしんします\n"
    "しばらく　おまちください"); // Unused
STRINGS_MAIN_MENU const u8 gText_SaveFileUpdated[] = _("レポートが　こうしんされました！"); // Unused

STRINGS_MAIN_MENU const u8 gText_SaveFileCorrupted[] = _(
    "レポートが　せいかくに　かかれていないので\n"
    "そのまえのレポートを　よみます！");
STRINGS_MAIN_MENU const u8 gText_SaveFileErased[] = _("レポートの　ないようが　きえてしまった！");
STRINGS_MAIN_MENU const u8 gJPText_No1MSubCircuit[] = _("1Mサブきばんが　ささっていません！");
STRINGS_MAIN_MENU const u8 gText_BatteryRunDry[] = _(
    "でんちぎれの　ために\n"
    "とけいが　うごかなくなりました\p"
    "とけいに　かんけいする　できごとは　おきませんが\n"
    "ゲームを　つづけて　あそぶことは　できます");
STRINGS_MAIN_MENU const u8 gText_Player[] = _("しゅじんこう"); // Unused
STRINGS_MAIN_MENU const u8 gText_Pokedex[] = _("ポケモンずかん"); // Unused
STRINGS_MAIN_MENU const u8 gText_Time[] = _("プレイじかん");
STRINGS_MAIN_MENU const u8 gText_Badges[] = _("もっているバッジ"); // Unused
STRINGS_MAIN_MENU const u8 gText_AButton[] = _("エーボタン"); // Unused
STRINGS_MAIN_MENU const u8 gText_BButton[] = _("ビーボタン"); // Unused
STRINGS_MAIN_MENU const u8 gText_RButton[] = _("アールボタン"); // Unused
STRINGS_MAIN_MENU const u8 gText_LButton[] = _("エルボタン"); // Unused
STRINGS_MAIN_MENU const u8 gText_Start[] = _("スタートボタン"); // Unused
STRINGS_MAIN_MENU const u8 gText_Select[] = _("セレクトボタン"); // Unused
STRINGS_MAIN_MENU const u8 gText_ControlPad[] = _("じゅうじボタン"); // Unused
STRINGS_MAIN_MENU const u8 gText_LButtonRButton[] = _("Lボタン　Rボタン"); // Unused
STRINGS_MAIN_MENU const u8 gText_Controls[] __attribute__((aligned(4))) = _("そうさ　せつめい"); // Unused
STRINGS_MAIN_MENU const u8 gText_PickOk[] __attribute__((aligned(4))) = _("{DPAD_UPDOWN}えらぶ　{A_BUTTON}けってい"); // Unused
STRINGS_MAIN_MENU const u8 gText_Next[] __attribute__((aligned(4))) = _("{A_BUTTON}つぎ"); // Unused
STRINGS_MAIN_MENU const u8 gText_NextBack[] __attribute__((aligned(4))) = _("{A_BUTTON}つぎ　{B_BUTTON}もどる"); // Unused
STRINGS_MAIN_MENU const u8 gText_PickNextCancel[] __attribute__((aligned(4))) = _("{DPAD_UPDOWN}えらぶ　{A_BUTTON}つぎ　{B_BUTTON}おわる");
STRINGS_MAIN_MENU const u8 gText_PickCancel[] __attribute__((aligned(4))) = _("{DPAD_UPDOWN}えらぶ　{A_BUTTON}{B_BUTTON}おわる");
STRINGS_MAIN_MENU const u8 gText_AButtonExit[] __attribute__((aligned(4))) = _("{A_BUTTON}おわる");
STRINGS_MAIN_MENU const u8 gText_BirchBoy[] = _("おとこ");
STRINGS_MAIN_MENU const u8 gText_BirchGirl[] = _("おんな");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Itsuo[] = __("イツオ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Gyoku[] = __("ギョク$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Kei[] = __("ケイ$$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Shuusaku[] = _("シュウサク");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Seigo[] = __("セイゴ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Daisaku[] = __("ダイサク$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Takahito[] = __("タカヒト$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Tatsuya[] = __("タツヤ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Daniel[] = __("ダニエル$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Teruki[] = __("テルキ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Tom[] = __("トム$$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Tomoya[] = __("トモヤ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Hitoshi[] = __("ヒトシ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Hiroaki[] = __("ヒロアキ$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Yukihiko[] = __("ユキヒコ$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Raldo[] = __("ラルド$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Rikuya[] = __("リクヤ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Richard[] = _("リチャード");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Ryuu[] = __("リュウ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Ryouta[] = __("リョウタ$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Aiko[] = __("アイコ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Ayana[] = __("アヤナ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Ann[] = __("アン$$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Emii[] = _("エミィ");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Kaori[] = __("カオリ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Karen[] = __("カレン$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Kyouko[] = __("キョウコ$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Sae[] = __("サエ$$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Sui[] = __("スイ$$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Juri[] = __("ジュリ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Chiemi[] = __("チエミ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Chiyoko[] = __("チヨコ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Teruko[] = __("テルコ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Nanae[] = __("ナナエ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Hina[] = __("ヒナ$$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Makiko[] = __("マキコ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Misako[] = __("ミサコ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Mutsumi[] = __("ムツミ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Monica[] = __("モニカ$$$");
STRINGS_MAIN_MENU const u8 gText_DefaultName_Yuume[] = __("ユウメ$$$");

STRINGS_POKENAV_SHARED_TEXT const u8 gText_NatureSlash[] = _("せいかく/");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_TrainerCloseBy[] = _(
    "ちかくに　いるみたいだから\n"
    "ちょくせつ　あって　はなそう！");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_InParty[] = _("てもちポケモン");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_Number2[] = _("ばんめ");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_Ribbons[] = _("リボン");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_PokemonMaleLv[] = _("{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 5 1 6}♂{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_PokemonFemaleLv[] = _("{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 7 1 8}♀{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_PokemonNoGenderLv[] = _("{DYNAMIC 0}　　/{LV_2}{DYNAMIC 1}");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_Unknown[] = _("ふめい");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_Call[] = _("よびだし");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_Check[] = _("しょうさい");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_Cancel6[] = _("もどる");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_NumberIndex[] = _("{DYNAMIC 0}ばんめ");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_RibbonsF700[] = _("リボン　{DYNAMIC 0}こ");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_PokemonMaleLv2[] = _("{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 5 1 6}♂{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_PokemonFemaleLv2[] = _("{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 7 1 8}♀{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ");
STRINGS_POKENAV_SHARED_TEXT const u8 gText_PokemonNoGenderLv2[] = _("{DYNAMIC 0}　　/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ");

STRINGS_EASY_CHAT const u8 gText_CombineFourWordsOrPhrases[] = _("4つの　ことばを　くみあわせて");
STRINGS_EASY_CHAT const u8 gText_AndMakeYourProfile[] = _("プロフィールを　つくろう！");
// The JP UI combines the two US prompts into one EOS-terminated string.
STRINGS_EASY_CHAT const u8 gText_CombineSixWordsAndMakeAMessage[] = _("6つの　ことばで　メッセージを　つくろう！");
// JP-only input constraint; the English UI has no corresponding text entry.
STRINGS_EASY_CHAT const u8 gText_SevenCharacterWordsPerLine[] = _("7もじの　ことばは　1ぎょうに　2つまで！");
STRINGS_EASY_CHAT const u8 gText_FindWordsThatDescribeYour[] = _("いまの　きもちに　ぴったりあう");
STRINGS_EASY_CHAT const u8 gText_FeelingsRightNow[] = _("ことばを　みつけよう！");
STRINGS_EASY_CHAT const u8 gText_WithFourPhrases[] = _("4つの　ことばで"); // Unused
STRINGS_EASY_CHAT const u8 gText_CombineNineWordsOrPhrases[] = _("9つの　ことばを　くみあわせて");
STRINGS_EASY_CHAT const u8 gText_AndMakeAMessage2[] = _("メッセージを　つくろう！");
STRINGS_EASY_CHAT const u8 gText_ChangeJustOneWordOrPhrase[] = _("ことばを　1つだけ　いれかえて");
STRINGS_EASY_CHAT const u8 gText_AndImproveTheBardsSong[] = _("オヤジのうたを　よくして　あげよう！");
STRINGS_EASY_CHAT const u8 gText_YourProfile[] = _("プロフィールは");
STRINGS_EASY_CHAT const u8 gText_YourFeelingAtTheBattlesStart[] = _("たいせんが　はじまるときの　きもちは");
STRINGS_EASY_CHAT const u8 gText_WhatYouSayIfYouWin[] = _("たいせんに　かったときの　あいさつは");
STRINGS_EASY_CHAT const u8 gText_WhatYouSayIfYouLose[] = _("たいせんに　まけたときの　あいさつは");
STRINGS_EASY_CHAT const u8 gText_TheAnswer[] = _("こたえは");
STRINGS_EASY_CHAT const u8 gText_TheMailMessage[] = _("メールに　のせる　メッセージは");
STRINGS_EASY_CHAT const u8 gText_TheMailSalutation[] = _("はがきに　のせる　あいさつは"); // Unused
STRINGS_EASY_CHAT const u8 gText_TheBardsSong2[] = _("あたらしい　うたは");
STRINGS_EASY_CHAT const u8 gText_CombineTwoWordsOrPhrases[] = _("2つの　ことばを　くみあわせて");
STRINGS_EASY_CHAT const u8 gText_AndMakeATrendySaying[] = _("はやらせたい　ことばを　つくろう！");
STRINGS_EASY_CHAT const u8 gText_TheTrendySaying[] = _("はやらせたい　ことばは");
STRINGS_EASY_CHAT const u8 gText_IsAsShownOkay[] = _("これで　いいですか？");
STRINGS_EASY_CHAT const u8 gText_CombineTwoWordsOrPhrases2[] = _("2つの　ことばを　くみあわせて");
STRINGS_EASY_CHAT const u8 gText_ToTeachHerAGoodSaying[] = _("いい　ことばを　おしえてあげよう！");
STRINGS_EASY_CHAT const u8 gText_FindWordsWhichFit[] = _("トレーナーの　イメージに");
STRINGS_EASY_CHAT const u8 gText_TheTrainersImage[] = _("ぴったりの　ことばを　みつけよう！");
STRINGS_EASY_CHAT const u8 gText_TheImage[] = _("イメージは");
STRINGS_EASY_CHAT const u8 gText_OutOfTheListedChoices[] = _("ことばの　なかから");
STRINGS_EASY_CHAT const u8 gText_SelectTheAnswerToTheQuiz[] = _("クイズの　こたえを　えらぼう！");
STRINGS_EASY_CHAT const u8 gText_AndCreateAQuiz[] = _("クイズを　つくろう！");
STRINGS_EASY_CHAT const u8 gText_PickAWordOrPhraseAnd[] = _("ことばの　なかから　ひとつを　えらんで");
STRINGS_EASY_CHAT const u8 gText_SetTheQuizAnswer[] = _("クイズの　こたえを　つくろう！");
STRINGS_EASY_CHAT const u8 gText_TheAnswerColon[] = _("こたえは");
STRINGS_EASY_CHAT const u8 gText_TheQuizColon[] = _("クイズは"); // Unused
STRINGS_EASY_CHAT const u8 gText_ApprenticePhrase[] = _("でしの　きめゼリフは");
// Easy Chat prompts retain the JP text boundaries and original ROM order.
STRINGS_EASY_CHAT const u8 gText_QuitEditing[] = _("へんしゅうを　やめますか？");
STRINGS_EASY_CHAT const u8 gText_StopGivingPkmnMail[] = _("メールを　もたせるのを　やめますか？");
STRINGS_EASY_CHAT const u8 gText_AndFillOutTheQuestionnaire[] = _("ショップの　アンケートに　こたえよう！");
STRINGS_EASY_CHAT const u8 gText_LetsReplyToTheInterview[] = _("インタビューに　こたえよう！");
STRINGS_EASY_CHAT const u8 gText_AllTextBeingEditedWill[] = _("へんしゅうちゅうの　ことばを");
STRINGS_EASY_CHAT const u8 gText_BeDeletedThatOkay[] = _("ぜんぶ　けしても　いいですか？");
STRINGS_EASY_CHAT const u8 gText_QuitEditing2[] = _("へんしゅうを　やめますか？"); // Unused
STRINGS_EASY_CHAT const u8 gText_EditedTextWillNotBeSaved[] = _("へんしゅうした　ことばは　ほぞん"); // Unused
STRINGS_EASY_CHAT const u8 gText_IsThatOkay[] = _("されませんが　いいですか？"); // Unused
STRINGS_EASY_CHAT const u8 gText_PleaseEnterPhraseOrWord[] = _("なにか　ことばを　いれてください！"); // Unused
STRINGS_EASY_CHAT const u8 gText_EntireTextCantBeDeleted[] = _("ことばを　ぜんぶ　けすことは　できません！");
STRINGS_EASY_CHAT const u8 gText_OnlyOnePhrase[] = _("かえられる　ことばは　1つ　までです！");
STRINGS_EASY_CHAT const u8 gText_OriginalSongWillBeUsed[] = _("うたを　もとに　もどします！");
STRINGS_EASY_CHAT const u8 gText_ThatsTrendyAlready[] = _("それは　もう　はやっています！"); // Unused
STRINGS_EASY_CHAT const u8 gText_CombineTwoWordsOrPhrases3[] = _("2つの　ことばを　くみあわせてください！");
STRINGS_EASY_CHAT const u8 gText_QuitGivingInfo[] = _("ことばを　おしえるのを　やめますか？"); // Unused
STRINGS_EASY_CHAT const u8 gText_StopGivingPkmnMail2[] = _("メールを　もたせるのを　やめますか？"); // Unused
STRINGS_EASY_CHAT const u8 gText_CreateAQuiz2[] = _("もんだいを　つくってください！"); // Unused
STRINGS_EASY_CHAT const u8 gText_SetTheAnswer[] = _("こたえを　えらんでください！"); // Unused
STRINGS_EASY_CHAT const u8 gText_CancelSelection[] = _("もとにもどして　いいですか？"); // Unused
STRINGS_EASY_CHAT const u8 gText_Profile[] = _("プロフィール");
STRINGS_EASY_CHAT const u8 gText_AtTheBattlesStart[] = _("たいせんが　はじまるとき");
STRINGS_EASY_CHAT const u8 gText_UponWinningABattle[] = _("たいせんに　かったとき");
STRINGS_EASY_CHAT const u8 gText_UponLosingABattle[] = _("たいせんに　まけたとき");
STRINGS_EASY_CHAT const u8 gText_TheBardsSong[] = _("オヤジのうた");
STRINGS_EASY_CHAT const u8 gText_WhatsHipAndHappening[] = _("はやっている　ものは？");
STRINGS_EASY_CHAT const u8 gText_Interview[] = _("インタビュー");
STRINGS_EASY_CHAT const u8 gText_GoodSaying[] = _("いい　ことば");
STRINGS_EASY_CHAT const u8 gText_FansQuestion[] = _("ファンのしつもん");
STRINGS_EASY_CHAT const u8 gJPText_WhatIsTheQuizAnswer[] = _("クイズの　こたえは？"); // Unused
STRINGS_EASY_CHAT const u8 gText_ApprenticesPhrase[] = _("でしの　きめゼリフ");
STRINGS_EASY_CHAT const u8 gText_Questionnaire[] = _("アンケート");
// The remaining Easy Chat prompts follow immediately in the JP ROM.
STRINGS_EASY_CHAT_MESSAGES const u8 gText_YouCannotQuitHere[] = _("ここでは　とちゅうで");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_SectionMustBeCompleted[] = _("やめることは　できません！");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_F700sQuiz[] = _("{DYNAMIC 0}さんの　クイズ");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_Lady[] = _("おねえ");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_AfterYouHaveReadTheQuiz[] = _("もんだいを　よんだら");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_QuestionPressTheAButton[] = _("Aボタンを　おしてね！");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_TheQuizAnswerIs[] = _("クイズの　こたえは？");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_LikeToQuitQuiz[] = _("クイズの　チャレンジを");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_ChallengeQuestionMark[] = _("あきらめますか？");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_IsThisQuizOK[] = _("クイズは　これで　いいですか？");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_CreateAQuiz[] = _("もんだいを　つくってください！");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_SelectTheAnswer[] = _("こたえを　えらんでください！");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_LyricsCantBeDeleted[] = _("かしを　けすことは　できません！");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_PokemonLeague[] = _("ポケモン　リーグ");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_PokemonCenter[] = _("ポケモンセンター");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_GetsAPokeBlockQuestion[] = _("に　ポロックを　あげますか？");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_Coolness[] = _("かっこよさ");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_Beauty3[] = _("うつくしさ");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_Cuteness[] = _("かわいさ");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_Smartness[] = _("かしこさ");
STRINGS_EASY_CHAT_MESSAGES const u8 gText_Toughness[] = _("たくましさ");

STRINGS_ELEVATOR_TEXT const u8 gText_ElevatorNowOn[] = _("げんざいのフロア");
STRINGS_MENU_PRICE_TEXT const u8 gText_BP[] = _("BP");
STRINGS_MENU_PRICE_TEXT const u8 gText_EnergyPowder50[] = _("ちからのこな　　{FONT_SMALL}　　50");
STRINGS_MENU_PRICE_TEXT const u8 gText_EnergyRoot80[] = _("ちからのねっこ　{FONT_SMALL}　　80");
STRINGS_MENU_PRICE_TEXT const u8 gText_HealPowder50[] = _("ばんのうごな　　{FONT_SMALL}　　50");
STRINGS_MENU_PRICE_TEXT const u8 gText_RevivalHerb300[] = _("ふっかつそう　　{FONT_SMALL}　300");
STRINGS_MENU_PRICE_TEXT const u8 gText_Protein1000[] = _("タウリン　　　　{FONT_SMALL}1000");
STRINGS_MENU_PRICE_TEXT const u8 gText_Iron1000[] = _("ブロムヘキシン　{FONT_SMALL}1000");
STRINGS_MENU_PRICE_TEXT const u8 gText_Carbos1000[] = _("インドメタシン　{FONT_SMALL}1000");
STRINGS_MENU_PRICE_TEXT const u8 gText_Calcium1000[] = _("リゾチウム　　　{FONT_SMALL}1000");
STRINGS_MENU_PRICE_TEXT const u8 gText_Zinc1000[] = _("キトサン　　　　{FONT_SMALL}1000");
STRINGS_MENU_PRICE_TEXT const u8 gText_HPUp1000[] = _("マックスアップ　{FONT_SMALL}1000");
STRINGS_MENU_PRICE_TEXT const u8 gText_PPUp3000[] = _("ポイントアップ　{FONT_SMALL}3000");
STRINGS_MENU_PRICE_TEXT const u8 gText_RankingHall[] = _("ランキングホール");
STRINGS_MENU_PRICE_TEXT const u8 gText_ExchangeService[] = _("ひきかえサービス");
STRINGS_MENU_PRICE_TEXT const u8 gText_LilycoveCity[] = _("ミナモシティ");
STRINGS_MENU_PRICE_TEXT const u8 gText_SlateportCity[] = _("カイナシティ");
STRINGS_MENU_PRICE_TEXT const u8 gText_CaveOfOrigin[] = _("めざめのほこら");
STRINGS_MENU_PRICE_TEXT const u8 gText_MtPyre[] = _("おくりびやま");
STRINGS_MENU_PRICE_TEXT const u8 gText_SkyPillar[] = _("そらのはしら");
STRINGS_MENU_PRICE_TEXT const u8 gText_DontRemember[] = _("おぼえていない");
STRINGS_POKENAV_STORAGE const u8 gText_Exit[] = _("やめる");
STRINGS_POKENAV_STORAGE const u8 gText_ExitFromBox[] = _("ボックスを　しゅうりょうしますか？　");
STRINGS_POKENAV_STORAGE const u8 gText_WhatDoYouWantToDo[] = _("このボックスを　どうしますか？");
STRINGS_POKENAV_STORAGE const u8 gText_PleasePickATheme[] = _("どの　テーマにしますか？");
STRINGS_POKENAV_STORAGE const u8 gText_PickTheWallpaper[] = _("どの　かべがみにしますか？");
STRINGS_POKENAV_STORAGE const u8 gText_PkmnIsSelected[] = _("{DYNAMIC 0}を　どうしますか？");
STRINGS_POKENAV_STORAGE const u8 gText_JumpToWhichBox[] = _("どの　ボックスに　ジャンプしますか？");
STRINGS_POKENAV_STORAGE const u8 gText_DepositInWhichBox[] = _("どの　ボックスに　あずけますか？");
STRINGS_POKENAV_STORAGE const u8 gText_PkmnWasDeposited[] = _("{DYNAMIC 0}を　あずけました");
STRINGS_POKENAV_STORAGE const u8 gText_BoxIsFull2[] = _("このボックスは　いっぱいだ！");
STRINGS_POKENAV_STORAGE const u8 gText_ReleaseThisPokemon[] = _("ほんとうに　にがしますか？");
STRINGS_POKENAV_STORAGE const u8 gText_PkmnWasReleased[] = _("{DYNAMIC 0}を　そとに　にがしてあげた");
STRINGS_POKENAV_STORAGE const u8 gText_ByeByePkmn[] = _("ばいばい　{DYNAMIC 0}！");
STRINGS_POKENAV_STORAGE const u8 gText_MarkYourPkmn[] = _("マーキングしてください");
STRINGS_POKENAV_STORAGE const u8 gText_ThatsYourLastPkmn[] = _("たたかうポケモンが　いなくなります！");
STRINGS_POKENAV_STORAGE const u8 gText_YourPartysFull[] = _("てもちが　いっぱいです！");
STRINGS_POKENAV_STORAGE const u8 gText_YoureHoldingAPkmn[] = _("ポケモンを　つかんだままですよ！");
STRINGS_POKENAV_STORAGE const u8 gText_WhichOneWillYouTake[] = _("つれていく　ポケモンを　えらんで！");
STRINGS_POKENAV_STORAGE const u8 gText_YouCantReleaseAnEgg[] = _("タマゴを　にがすことは　できません！");
STRINGS_POKENAV_STORAGE const u8 gText_ContinueBoxOperations[] = _("ボックスそうさを　つづけますか？");
STRINGS_POKENAV_STORAGE const u8 gText_PkmnCameBack[] = _("{DYNAMIC 0}は　かえってきた！");
STRINGS_POKENAV_STORAGE const u8 gText_WasItWorriedAboutYou[] = _("しんぱい　だったのかな⋯⋯");
STRINGS_POKENAV_STORAGE const u8 gText_FourEllipsesExclamation[] = _("⋯⋯⋯⋯⋯！");
STRINGS_POKENAV_STORAGE const u8 gText_PleaseRemoveTheMail[] = _("メールを　はずして　ください！");
STRINGS_POKENAV_STORAGE const u8 gText_GiveToAPkmn[] = _("どうぐを　もたせますか？");
STRINGS_POKENAV_STORAGE const u8 gText_PlacedItemInBag[] = _("{DYNAMIC 0}を　バッグへいれた！");
STRINGS_POKENAV_STORAGE const u8 gText_BagIsFull2[] = _("バッグが　いっぱいです！");
STRINGS_POKENAV_STORAGE const u8 gText_PutItemInBag[] = _("どうぐを　バッグに　いれますか？");
STRINGS_POKENAV_STORAGE const u8 gText_ItemIsNowHeld[] = _("{DYNAMIC 0}を　もたせた！");
STRINGS_POKENAV_STORAGE const u8 gText_ChangedToNewItem[] = _("{DYNAMIC 0}と　とりかえた！");
STRINGS_POKENAV_STORAGE const u8 gText_MailCantBeStored[] = _("メールを　あずかることは　できません！");
STRINGS_POKENAV_STORAGE const u8 gPCText_Cancel[] = _("やめる　　　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Store[] = _("あずける　　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Withdraw[] = _("つれていく　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Shift[] = _("いれかえる　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Move[] = _("つかむ　　　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Place[] = _("ここにおく　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Summary[] = _("ようすをみる");
STRINGS_POKENAV_STORAGE const u8 gPCText_Release[] = _("にがす　　　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Mark[] = _("マーキング　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Name[] = _("なまえ　　　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Jump[] = _("ジャンプ");
STRINGS_POKENAV_STORAGE const u8 gPCText_Wallpaper[] = _("かべがみ　　");
STRINGS_POKENAV_STORAGE const u8 gPCText_Take[] = _("あずかる");
STRINGS_POKENAV_STORAGE const u8 gPCText_Give[] = _("もたせる");
STRINGS_POKENAV_STORAGE const u8 gPCText_Switch[] = _("とりかえる");
STRINGS_POKENAV_STORAGE const u8 gPCText_Bag[] = _("バッグへ");
STRINGS_POKENAV_STORAGE const u8 gPCText_Info[] = _("せつめい");
STRINGS_POKENAV_STORAGE const u8 gPCText_Scenery1[] = _("ふうけい1");
STRINGS_POKENAV_STORAGE const u8 gPCText_Scenery2[] = _("ふうけい2");
STRINGS_POKENAV_STORAGE const u8 gPCText_Scenery3[] = _("ふうけい3");
STRINGS_POKENAV_STORAGE const u8 gPCText_Etcetera[] = _("エトセトラ");
STRINGS_POKENAV_STORAGE const u8 gPCText_Friends[] = _("だいすき");
STRINGS_POKENAV_STORAGE const u8 gPCText_Forest[] = _("もり");
STRINGS_POKENAV_STORAGE const u8 gPCText_City[] = _("シティ");
STRINGS_POKENAV_STORAGE const u8 gPCText_Desert[] = _("さばく");
STRINGS_POKENAV_STORAGE const u8 gPCText_Savanna[] = _("サバンナ");
STRINGS_POKENAV_STORAGE const u8 gPCText_Crag[] = _("いわやま");
STRINGS_POKENAV_STORAGE const u8 gPCText_Volcano[] = _("かざん");
STRINGS_POKENAV_STORAGE const u8 gPCText_Snow[] = _("ゆきやま");
STRINGS_POKENAV_STORAGE const u8 gPCText_Cave[] = _("どうくつ");
STRINGS_POKENAV_STORAGE const u8 gPCText_Beach[] = _("うみべ");
STRINGS_POKENAV_STORAGE const u8 gPCText_Seafloor[] = _("かいてい");
STRINGS_POKENAV_STORAGE const u8 gPCText_River[] = _("かわ");
STRINGS_POKENAV_STORAGE const u8 gPCText_Sky[] = _("そら");
STRINGS_POKENAV_STORAGE const u8 gPCText_PolkaDot[] = _("みずたま");
STRINGS_POKENAV_STORAGE const u8 gPCText_Pokecenter[] = _("ポケセン");
STRINGS_POKENAV_STORAGE const u8 gPCText_Machine[] = _("きかい");
STRINGS_POKENAV_STORAGE const u8 gPCText_Simple[] = _("シンプル");
STRINGS_POKENAV_STORAGE const u8 gText_WhatWouldYouLikeToDo[] = _("なにを　しますか？");
STRINGS_POKENAV_STORAGE const u8 gText_WithdrawPokemon[] = _("ポケモンを　つれていく");
STRINGS_POKENAV_STORAGE const u8 gText_DepositPokemon[] = _("ポケモンを　あずける　");
STRINGS_POKENAV_STORAGE const u8 gText_MovePokemon[] = _("ボックスを　せいりする");
STRINGS_POKENAV_STORAGE const u8 gText_MoveItems[] = _("どうぐせいり");
STRINGS_POKENAV_STORAGE const u8 gText_SeeYa[] = _("さようなら");
STRINGS_POKENAV_STORAGE const u8 gText_WithdrawMonDescription[] = _(
    "ボックスに　あずけている　ポケモンを　\n"
    "てもちに　くわえる　ことが　できます　");
STRINGS_POKENAV_STORAGE const u8 gText_DepositMonDescription[] = _(
    "てもちの　ポケモンを　　　　　　　　　\n"
    "ボックスに　あずける　ことが　できます");
STRINGS_POKENAV_STORAGE const u8 gText_MoveMonDescription[] = _(
    "ボックスに　あずけている　ポケモンや　\n"
    "てもちの　ポケモンを　せいり　できます");
STRINGS_POKENAV_STORAGE const u8 gText_MoveItemsDescription[] = _(
    "ポケモンが　もっている　どうぐを\n"
    "せいり　できます");
STRINGS_POKENAV_STORAGE const u8 gText_SeeYaDescription[] = _(
    "ひとつ　まえの　メニューに　もどります\n"
    "　　　　　　　　　　　　　　　　　　　");
STRINGS_POKENAV_STORAGE const u8 gText_JustOnePkmn[] = _(
    "てもちポケモンが　1ひきしかいません！\n"
    "　　　　　　　　　　　　　　　　　　　");
STRINGS_POKENAV_STORAGE const u8 gText_PartyFull[] = _(
    "てもちポケモンが　いっぱいです！　　　\n"
    "　　　　　　　　　　　　　　　　　　　");
STRINGS_POKENAV_STORAGE const u8 gText_Box[] = _("ボックス");
STRINGS_POKENAV_STORAGE const u8 gText_CheckMapOfHoenn[] = _("ホウエンちほうの　マップを　みます");
STRINGS_POKENAV_STORAGE const u8 gText_CheckPokemonInDetail[] = _("ポケモンを　くわしく　しらべます");
STRINGS_POKENAV_STORAGE const u8 gText_CallRegisteredTrainer[] = _("とうろくした　ひとを　よびだします");
STRINGS_POKENAV_STORAGE const u8 gText_CheckObtainedRibbons[] = _("てにいれた　きねんリボンを　みます");
STRINGS_POKENAV_STORAGE const u8 gText_PutAwayPokenav[] = _("ポケナビを　しまいます");
STRINGS_POKENAV_STORAGE const u8 gText_NoRibbonWinners[] = _("リボンを　もっている　ポケモンが　いません");
STRINGS_POKENAV_STORAGE const u8 gText_NoTrainersRegistered[] = _("トレーナーが　とうろく　されていません");
STRINGS_POKENAV_STORAGE const u8 gText_CheckPartyPokemonInDetail[] = _("てもちポケモンを　くわしく　しらべます");
STRINGS_POKENAV_STORAGE const u8 gText_CheckAllPokemonInDetail[] = _("すべてのポケモンを　くわしく　しらべます");
STRINGS_POKENAV_STORAGE const u8 gText_ReturnToPokenavMenu[] = _("ポケナビの　メニューに　もどります");
STRINGS_POKENAV_STORAGE const u8 gText_FindCoolPokemon[] = _("かっこいい　ポケモンを　みつけます");
STRINGS_POKENAV_STORAGE const u8 gText_FindBeautifulPokemon[] = _("うつくしい　ポケモンを　みつけます");
STRINGS_POKENAV_STORAGE const u8 gText_FindCutePokemon[] = _("かわいい　ポケモンを　みつけます");
STRINGS_POKENAV_STORAGE const u8 gText_FindSmartPokemon[] = _("かしこい　ポケモンを　みつけます");
STRINGS_POKENAV_STORAGE const u8 gText_FindToughPokemon[] = _("たくましい　ポケモンを　みつけます");
STRINGS_POKENAV_STORAGE const u8 gText_ReturnToConditionMenu[] = _("コンディションの　メニューに　もどります");
STRINGS_POKENAV_STORAGE const u8 gText_NumberRegistered[] = _("とうろく　にんずう");
STRINGS_POKENAV_STORAGE const u8 gText_NumberOfBattles[] = _("たいせん　かいすう");
STRINGS_POKENAV_STORAGE const u8 gText_Detail[] = _("しょうさい");
STRINGS_POKENAV_STORAGE const u8 gText_Call2[] = _("よびだす");
STRINGS_POKENAV_STORAGE const u8 gText_UnusedExit[] = _("やめる");
STRINGS_POKENAV_STORAGE const u8 gText_CantCallOpponentHere[] = _(
    "ここでは　あいてを　よびだす　ことが\n"
    "できないようだ");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavMatchCall_Strategy[] = _("さくせん");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavMatchCall_TrainerPokemon[] = _("もってる　ポケモン");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavMatchCall_SelfIntroduction[] = _("じこしょうかい");
STRINGS_POKENAV_STORAGE const u8 gText_Pokenav_ClearButtonList[] = _("　　　　　　　　　　　　　　　　");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavMap_ZoomedOutButtons[] = _("{A_BUTTON}かくだい　{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavMap_ZoomedInButtons[] = _("{A_BUTTON}ぜんたい　{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavCondition_MonListButtons[] = _("{A_BUTTON}コンディションをみる　{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavCondition_MonStatusButtons[] = _("{A_BUTTON}マーキング　{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavCondition_MarkingButtons[] = _("{A_BUTTON}マークをえらぶ　{B_BUTTON}やめる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavMatchCall_TrainerListButtons[] = _("{A_BUTTON}メニュー　{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavMatchCall_CallMenuButtons[] = _("{A_BUTTON}けってい　{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavMatchCall_CheckTrainerButtons[] = _("{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavRibbons_MonListButtons[] = _("{A_BUTTON}リボンをみる　{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavRibbons_RibbonListButtons[] = _("{A_BUTTON}しょうさい　{B_BUTTON}もどる");
STRINGS_POKENAV_STORAGE const u8 gText_PokenavRibbons_RibbonCheckButtons[] = _("{B_BUTTON}もどる");

STRINGS_CLEAR_SAVE const u8 gText_ClearAllSaveData[] = _(
    "すべての　セーブデータエリアを\n"
    "クリア　しますか？");
STRINGS_CLEAR_SAVE const u8 gText_ClearingData[22] = _(
    "クリア　しています\n"
    "おまち　ください");

#define STRINGS_SLOT_MACHINE __attribute__((section(".rodata.strings_slot_machine"), aligned(1)))

STRINGS_SLOT_MACHINE const u8 gText_QuitTheGame[] = _("ゲームを　やめますか？");
STRINGS_SLOT_MACHINE const u8 gText_YouveGot9999Coins[] = _(
    "コインが　9999まい\n"
    "たまって　います");
STRINGS_SLOT_MACHINE const u8 gText_YouveRunOutOfCoins[] = _(
    "コインが　ありません\n"
    "ゲームを　しゅうりょうします");
STRINGS_SLOT_MACHINE const u8 gText_YouDontHaveThreeCoins[] = _("コインが　3まい　ありません！");
STRINGS_SLOT_MACHINE const u8 gText_ReelTimeHelp[] = __(
    "BDタイム\n"
    "じっくり　ねらえば　どんな　マークも\n"
    "とめられる　チャンスゲームだ！\n"
    "ちゅうせん　された　かいすうだけ\n"
    "BDタイムが　つづくぞ！\n"
    "ビッグボーナスがでると　しゅうりょう$　");

#undef STRINGS_SLOT_MACHINE

#define STRINGS_BATTLE_RECORDS __attribute__((section(".rodata.strings_battle_records"), aligned(1)))

STRINGS_BATTLE_RECORDS const u8 gText_PlayersBattleResults[] = _("{PLAYER}　の　たいせん　せいせき");
STRINGS_BATTLE_RECORDS const u8 gText_TotalRecordWLD[] = _("{STR_VAR_1}しょう　{STR_VAR_2}はい　{STR_VAR_3}ひきわけ");
STRINGS_BATTLE_RECORDS const u8 gText_WinLoseDraw[] = _("かち　　　　まけ　　　ひきわけ");

#undef STRINGS_BATTLE_RECORDS
