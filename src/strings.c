#include "global.h"
#include "strings.h"
#include "battle_pyramid_bag.h"
#include "item_menu.h"
#include "constants/songs.h"

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
#define STRINGS_SUMMARY_EGG_TEXT __attribute__((section(".rodata.strings_summary_egg_text"), aligned(1)))
#define STRINGS_MAIN_MENU __attribute__((section(".rodata.strings_main_menu")))
#define STRINGS_EASY_CHAT __attribute__((section(".rodata.strings_easy_chat")))
#define STRINGS_POKENAV_STORAGE __attribute__((section(".rodata.strings_pokenav_storage")))
#define STRINGS_CLEAR_SAVE __attribute__((section(".rodata.strings_clear_save")))
#define STRINGS_DAYCARE __attribute__((section(".rodata.strings_daycare")))
#define STRINGS_BAG_RETURN_TEXT __attribute__((section(".rodata.strings_bag_return_text"), aligned(1)))
#define STRINGS_BAG_RETURN_TABLES __attribute__((section(".rodata.strings_bag_return_tables")))
#define STRINGS_ITEM_MENU_TEXT __attribute__((section(".rodata.strings_item_menu_text"), aligned(1)))
#define STRINGS_MENU_YES_NO __attribute__((section(".rodata.strings_menu_yes_no"), aligned(1)))
#define STRINGS_MENU_SELECTOR_ARROW3 __attribute__((section(".rodata.strings_menu_selector_arrow3"), aligned(1)))
#define STRINGS_BATTLE_FACTORY_SELECTION __attribute__((section(".rodata.strings_battle_factory_selection"), aligned(1)))
#define STRINGS_DECORATION_TEXT __attribute__((section(".rodata.strings_decoration_text"), aligned(1)))
#define STRINGS_MOVE_RELEARNER_TEXT __attribute__((section(".rodata.strings_move_relearner_text"), aligned(1), used))
#define STRINGS_DIPLOMA_TEXT __attribute__((section(".rodata.strings_diploma_text"), aligned(1), used))
#define STRINGS_EXPANDED_PLACEHOLDER_TEXT __attribute__((section(".rodata.strings_expanded_placeholder_text"), aligned(1), used))
#define STRINGS_POKEMON_NAMES_TEXT __attribute__((section(".rodata.strings_pokemon_names_text"), aligned(1), used))

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

STRINGS_SUMMARY_EGG_TEXT const u8 gText_OddEggFoundByCouple[] = _(
    "そだてや　ふうふ　から　もらった\n"
    "ふしぎな　ポケモンのタマゴ");

STRINGS_SUMMARY_EGG_TEXT const u8 gText_PeculiarEggNicePlace[] = _(
    "ステキな　ばしょで　てにいれた\n"
    "ふしぎな　ふしぎな　ポケモンのタマゴ");

STRINGS_SUMMARY_EGG_TEXT const u8 gText_PeculiarEggTrade[] = _(
    "つうしんこうかんで　てにいれた\n"
    "ふしぎな　ポケモンのタマゴ");

STRINGS_SUMMARY_EGG_TEXT const u8 gText_EggFromHotSprings[] = _(
    "おんせんばあさん　から　もらった\n"
    "ふしぎな　ポケモンのタマゴ");

STRINGS_SUMMARY_EGG_TEXT const u8 gText_EggFromTraveler[] = _(
    "たびの　おじさん　から　もらった\n"
    "ふしぎな　ポケモンのタマゴ");

STRINGS_COMMON const u8 gMenuText_Confirm[] = _("けってい");
STRINGS_COMMON const u8 gMenuText_Walk[] = _("おりる");
STRINGS_COMMON const u8 gText_Cancel[] = _("もどる");
STRINGS_COMMON const u8 gText_Exit[] = _("やめる");
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
STRINGS_COMMON const u8 gUnknown_85C942E[] = {0x15, 0x16, 0x2D, 0x00, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0x01, 0x3A, 0x29, 0xFF};

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
STRINGS_MAIN_MENU const u8 gText_BirchBoy[] = {0x05, 0x14, 0x0A, 0xFF};
STRINGS_MAIN_MENU const u8 gText_BirchGirl[] = {0x05, 0x2E, 0x15, 0xFF};
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

STRINGS_EASY_CHAT const u8 gText_SearchResultRank[] = _("{DYNAMIC 0}ばんめ");
// Easy Chat and PokéNav strings are kept in their original JP ROM order.
STRINGS_EASY_CHAT const u8 gText_RibbonsF700[] = _("リボン　{DYNAMIC 0}こ");
// JP charmap color operands: 5/1/6 = LIGHT_RED/WHITE/GREEN; 2/1/3 = DARK_GRAY/WHITE/LIGHT_GRAY.
STRINGS_EASY_CHAT const u8 gText_PokemonMaleLv2[] = _("{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 5 1 6}♂{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ"); // Unused
STRINGS_EASY_CHAT const u8 gText_PokemonFemaleLv2[] = _("{DYNAMIC 0}　{COLOR_HIGHLIGHT_SHADOW 7 1 8}♀{COLOR_HIGHLIGHT_SHADOW 2 1 3}/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ"); // Unused
STRINGS_EASY_CHAT const u8 gText_PokemonNoGenderLv2[] = _("{DYNAMIC 0}　　/{LV_2}{DYNAMIC 1}　{DYNAMIC 2}こ"); // Unused
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
// JP kana keyboard rows; these have no one-string US counterpart.
STRINGS_EASY_CHAT const u8 gJPText_EasyChatKanaRow1[] = _("あいうえお　なにぬねの　やゆよ　わ");
STRINGS_EASY_CHAT const u8 gJPText_EasyChatKanaRow2[] = _("かきくけこ　はひふへほ　そのた");
STRINGS_EASY_CHAT const u8 gJPText_EasyChatKanaRow3[] = _("さしすせそ　まみむめも");
STRINGS_EASY_CHAT const u8 gJPText_EasyChatKanaRow4[] = _("たちつてと　らりるれろ");
// The remaining Easy Chat prompts follow immediately in the JP ROM.
STRINGS_EASY_CHAT const u8 gText_YouCannotQuitHere[] = _("ここでは　とちゅうで");
STRINGS_EASY_CHAT const u8 gText_SectionMustBeCompleted[] = _("やめることは　できません！");
STRINGS_EASY_CHAT const u8 gText_F700sQuiz[] = _("{DYNAMIC 0}さんの　クイズ");
STRINGS_EASY_CHAT const u8 gText_Lady[] = _("おねえ");
STRINGS_EASY_CHAT const u8 gText_AfterYouHaveReadTheQuiz[] = _("もんだいを　よんだら");
STRINGS_EASY_CHAT const u8 gText_QuestionPressTheAButton[] = _("Aボタンを　おしてね！");
STRINGS_EASY_CHAT const u8 gText_TheQuizAnswerIs[] = _("クイズの　こたえは？");
STRINGS_EASY_CHAT const u8 gText_LikeToQuitQuiz[] = _("クイズの　チャレンジを");
STRINGS_EASY_CHAT const u8 gText_ChallengeQuestionMark[] = _("あきらめますか？");
STRINGS_EASY_CHAT const u8 gText_IsThisQuizOK[] = _("クイズは　これで　いいですか？");
STRINGS_EASY_CHAT const u8 gText_CreateAQuiz[] = _("もんだいを　つくってください！");
STRINGS_EASY_CHAT const u8 gText_SelectTheAnswer[] = _("こたえを　えらんでください！");
STRINGS_EASY_CHAT const u8 gText_LyricsCantBeDeleted[] = _("かしを　けすことは　できません！");
STRINGS_EASY_CHAT const u8 gText_PokemonLeague[] = _("ポケモン　リーグ");
STRINGS_EASY_CHAT const u8 gText_PokemonCenter[] = _("ポケモンセンター");
STRINGS_EASY_CHAT const u8 gText_GetsAPokeBlockQuestion[] = _("に　ポロックを　あげますか？");
STRINGS_EASY_CHAT const u8 gText_Coolness[] = _("かっこよさ");
STRINGS_EASY_CHAT const u8 gText_Beauty3[] = _("うつくしさ");
STRINGS_EASY_CHAT const u8 gText_Cuteness[] = _("かわいさ");
STRINGS_EASY_CHAT const u8 gText_Smartness[] = _("かしこさ");
STRINGS_EASY_CHAT const u8 gText_Toughness[] = _("たくましさ");

// Existing naked routines address later region_texts100 strings from this base.
__asm__(".global gUnknown_85CBD12\n"
        ".set gUnknown_85CBD12, gText_GetsAPokeBlockQuestion");

// S.S. Tidal's Slateport destination is embedded in this fixed-width Pokenav text block.
__asm__(".global gText_SlateportCity\n"
        ".set gText_SlateportCity, gUnknown_85CB0C8 + 0xCC");

STRINGS_POKENAV_STORAGE const u8 gText_ElevatorNowOn[] = _("げんざいのフロア");
STRINGS_POKENAV_STORAGE const u8 gUnknown_85CB0C8[] = {0xBC, 0xCA, 0xFF, 0x11, 0x06, 0x27, 0x19, 0x0A, 0x15, 0x00, 0x00, 0xFC, 0x06, 0x00, 0x00, 0x00, 0xA6, 0xA1, 0xFF, 0x11, 0x06, 0x27, 0x19, 0x18, 0x50, 0x0A, 0x00, 0xFC, 0x06, 0x00, 0x00, 0x00, 0xA9, 0xA1, 0xFF, 0x46, 0x2E, 0x19, 0x03, 0x3B, 0x15, 0x00, 0x00, 0xFC, 0x06, 0x00, 0x00, 0x00, 0xA6, 0xA1, 0xFF, 0x1C, 0x50, 0x06, 0x12, 0x0F, 0x03, 0x00, 0x00, 0xFC, 0x06, 0x00, 0x00, 0xA4, 0xA1, 0xA1, 0xFF, 0x60, 0x53, 0x78, 0x7E, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x06, 0x00, 0xA2, 0xA1, 0xA1, 0xA1, 0xFF, 0x98, 0x7B, 0x71, 0x6D, 0x57, 0x5C, 0x7E, 0x00, 0xFC, 0x06, 0x00, 0xA2, 0xA1, 0xA1, 0xA1, 0xFF, 0x52, 0x7E, 0x95, 0x72, 0x60, 0x5C, 0x7E, 0x00, 0xFC, 0x06, 0x00, 0xA2, 0xA1, 0xA1, 0xA1, 0xFF, 0x78, 0x90, 0x61, 0x53, 0x71, 0x00, 0x00, 0x00, 0xFC, 0x06, 0x00, 0xA2, 0xA1, 0xA1, 0xA1, 0xFF, 0x57, 0x64, 0x5B, 0x7E, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x06, 0x00, 0xA2, 0xA1, 0xA1, 0xA1, 0xFF, 0x6F, 0xA0, 0x58, 0x5D, 0x51, 0xA0, 0x9D, 0x00, 0xFC, 0x06, 0x00, 0xA2, 0xA1, 0xA1, 0xA1, 0xFF, 0x9F, 0x52, 0x7E, 0x64, 0x51, 0xA0, 0x9D, 0x00, 0xFC, 0x06, 0x00, 0xA4, 0xA1, 0xA1, 0xA1, 0xFF, 0x77, 0x7E, 0x57, 0x7E, 0x89, 0x6E, 0xAE, 0x79, 0xFF, 0x1B, 0x07, 0x06, 0x04, 0x5B, 0xAE, 0x97, 0x5D, 0xFF, 0x70, 0x65, 0x73, 0x5C, 0x63, 0x80, 0xFF, 0x56, 0x52, 0x65, 0x5C, 0x63, 0x80, 0xFF, 0x22, 0x3C, 0x22, 0x19, 0x1E, 0x0A, 0x27, 0xFF, 0x05, 0x08, 0x28, 0x47, 0x24, 0x1F, 0xFF, 0x0F, 0x27, 0x19, 0x1A, 0x0C, 0x27, 0xFF, 0x05, 0x4A, 0x04, 0x13, 0x02, 0x15, 0x02, 0xFF};
STRINGS_POKENAV_STORAGE const u8 gUnknown_85CB1B9[] = {0x24, 0x22, 0x29, 0xFF, 0x9A, 0xA0, 0x58, 0x5D, 0x2D, 0x00, 0x0C, 0x35, 0x03, 0x28, 0x36, 0x03, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0x00, 0xFF, 0x0A, 0x19, 0x9A, 0xA0, 0x58, 0x5D, 0x2D, 0x00, 0x45, 0x03, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0x45, 0x19, 0x00, 0x63, 0xAE, 0x6F, 0x16, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0x45, 0x19, 0x00, 0x06, 0x49, 0x37, 0x20, 0x16, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0xF7, 0x00, 0x2D, 0x00, 0x45, 0x03, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0x45, 0x19, 0x00, 0x9A, 0xA0, 0x58, 0x5D, 0x16, 0x00, 0x8D, 0x84, 0x7E, 0x9D, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0x45, 0x19, 0x00, 0x9A, 0xA0, 0x58, 0x5D, 0x16, 0x00, 0x01, 0x3E, 0x09, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0xF7, 0x00, 0x2D, 0x00, 0x01, 0x3E, 0x09, 0x1F, 0x0C, 0x10, 0xFF, 0x0A, 0x19, 0x9A, 0xA0, 0x58, 0x5D, 0x1A, 0x00, 0x02, 0x50, 0x4B, 0x02, 0x41, 0xAB, 0xFF, 0x1E, 0x2E, 0x14, 0x03, 0x16, 0x00, 0x16, 0x37, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0xF7, 0x00, 0x2D, 0x00, 0x0F, 0x14, 0x16, 0x00, 0x16, 0x37, 0x0C, 0x13, 0x01, 0x3A, 0x10, 0xFF, 0x46, 0x02, 0x46, 0x02, 0x00, 0xF7, 0x00, 0xAB, 0xFF, 0x6F, 0xAE, 0x57, 0x7E, 0x89, 0x0C, 0x13, 0x08, 0x41, 0x0B, 0x02, 0xFF, 0x10, 0x10, 0x06, 0x03, 0x9F, 0x59, 0x73, 0x7E, 0x37, 0x00, 0x02, 0x15, 0x08, 0x15, 0x28, 0x1F, 0x0D, 0xAB, 0xFF, 0x13, 0x23, 0x11, 0x37, 0x00, 0x02, 0x50, 0x4B, 0x02, 0x44, 0x0D, 0xAB, 0xFF, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x12, 0x06, 0x2E, 0x41, 0x1F, 0x1F, 0x44, 0x0D, 0x26, 0xAB, 0xFF, 0x12, 0x2A, 0x13, 0x02, 0x08, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x04, 0x27, 0x2E, 0x44, 0xAB, 0xFF, 0x60, 0x6F, 0x8B, 0x2D, 0x00, 0x16, 0x37, 0x0D, 0x0A, 0x14, 0x1A, 0x00, 0x44, 0x07, 0x1F, 0x0E, 0x2E, 0xAB, 0xFF, 0x9A, 0xA0, 0x58, 0x5D, 0x0F, 0x03, 0x0B, 0x2D, 0x00, 0x12, 0x43, 0x09, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0xF7, 0x00, 0x1A, 0x00, 0x06, 0x04, 0x50, 0x13, 0x07, 0x10, 0xAB, 0xFF, 0x0C, 0x2E, 0x4B, 0x02, 0x00, 0x41, 0x50, 0x10, 0x19, 0x06, 0x15, 0xB0, 0xB0, 0xFF, 0xB0, 0xB0, 0xB0, 0xB0, 0xB0, 0xAB, 0xFF, 0x72, 0xAE, 0x79, 0x2D, 0x00, 0x1A, 0x3E, 0x0C, 0x13, 0x00, 0x08, 0x41, 0x0B, 0x02, 0xAB, 0xFF, 0x45, 0x03, 0x39, 0x2D, 0x00, 0x23, 0x10, 0x0E, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0xF7, 0x00, 0x2D, 0x00, 0x96, 0xA0, 0x89, 0x1D, 0x02, 0x2A, 0x10, 0xAB, 0xFF, 0x96, 0xA0, 0x89, 0x37, 0x00, 0x02, 0x50, 0x4B, 0x02, 0x44, 0x0D, 0xAB, 0xFF, 0x45, 0x03, 0x39, 0x2D, 0x00, 0x96, 0xA0, 0x89, 0x16, 0x00, 0x02, 0x2A, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0xF7, 0x00, 0x2D, 0x00, 0x23, 0x10, 0x0E, 0x10, 0xAB, 0xFF, 0xF7, 0x00, 0x14, 0x00, 0x14, 0x28, 0x06, 0x04, 0x10, 0xAB, 0xFF, 0x72, 0xAE, 0x79, 0x2D, 0x00, 0x01, 0x3E, 0x06, 0x29, 0x0A, 0x14, 0x1A, 0x00, 0x44, 0x07, 0x1F, 0x0E, 0x2E, 0xAB, 0xFF, 0x24, 0x22, 0x29, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x3E, 0x09, 0x29, 0x00, 0x00, 0xFF, 0x12, 0x2A, 0x13, 0x02, 0x08, 0x00, 0xFF, 0x02, 0x2A, 0x06, 0x04, 0x29, 0x00, 0xFF, 0x12, 0x06, 0x21, 0x00, 0x00, 0x00, 0xFF, 0x0A, 0x0A, 0x16, 0x05, 0x08, 0x00, 0xFF, 0x26, 0x03, 0x0D, 0x2D, 0x20, 0x29, 0xFF, 0x16, 0x37, 0x0D, 0x00, 0x00, 0x00, 0xFF, 0x6F, 0xAE, 0x57, 0x7E, 0x89, 0x00, 0xFF, 0x15, 0x1F, 0x04, 0x00, 0x00, 0x00, 0xFF, 0x8D, 0x84, 0x7E, 0x9D, 0xFF, 0x06, 0x49, 0x37, 0x20, 0x00, 0x00, 0xFF, 0x01, 0x3E, 0x06, 0x29, 0xFF, 0x23, 0x10, 0x0E, 0x29, 0xFF, 0x14, 0x28, 0x06, 0x04, 0x29, 0xFF, 0x96, 0xA0, 0x89, 0x1D, 0xFF, 0x0E, 0x12, 0x22, 0x02, 0xFF, 0x1C, 0x03, 0x09, 0x02, 0xA2, 0xFF, 0x1C, 0x03, 0x09, 0x02, 0xA3, 0xFF, 0x1C, 0x03, 0x09, 0x02, 0xA4, 0xFF, 0x54, 0x64, 0x5E, 0x64, 0x77, 0xFF, 0x41, 0x02, 0x0D, 0x07, 0xFF, 0x23, 0x28, 0xFF, 0x5C, 0x63, 0x80, 0xFF, 0x0B, 0x46, 0x08, 0xFF, 0x5B, 0x96, 0x7E, 0x65, 0xFF, 0x02, 0x2C, 0x24, 0x1F, 0xFF, 0x06, 0x3C, 0x2E, 0xFF, 0x25, 0x07, 0x24, 0x1F, 0xFF, 0x45, 0x03, 0x08, 0x12, 0xFF, 0x03, 0x20, 0x49, 0xFF, 0x06, 0x02, 0x13, 0x02, 0xFF, 0x06, 0x2C, 0xFF, 0x0F, 0x27, 0xFF, 0x20, 0x3E, 0x10, 0x1F, 0xFF, 0x9F, 0x59, 0x5E, 0x7E, 0xFF, 0x07, 0x06, 0x02, 0xFF, 0x5C, 0x7E, 0x9D, 0x79, 0xFF, 0x15, 0x16, 0x2D, 0x00, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x12, 0x2A, 0x13, 0x02, 0x08, 0xFF, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x01, 0x3E, 0x09, 0x29, 0x00, 0xFF, 0x9A, 0xA0, 0x58, 0x5D, 0x2D, 0x00, 0x0E, 0x02, 0x28, 0x0D, 0x29, 0xFF, 0x45, 0x03, 0x39, 0x0E, 0x02, 0x28, 0xFF, 0x0B, 0x26, 0x03, 0x15, 0x27, 0xFF, 0x9A, 0xA0, 0x58, 0x5D, 0x16, 0x00, 0x01, 0x3E, 0x09, 0x13, 0x02, 0x29, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0xFE, 0x13, 0x23, 0x11, 0x16, 0x00, 0x08, 0x2C, 0x04, 0x29, 0x00, 0x0A, 0x14, 0x37, 0x00, 0x44, 0x07, 0x1F, 0x0D, 0x00, 0xFF, 0x13, 0x23, 0x11, 0x19, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x9A, 0xA0, 0x58, 0x5D, 0x16, 0x00, 0x01, 0x3E, 0x09, 0x29, 0x00, 0x0A, 0x14, 0x37, 0x00, 0x44, 0x07, 0x1F, 0x0D, 0xFF, 0x9A, 0xA0, 0x58, 0x5D, 0x16, 0x00, 0x01, 0x3E, 0x09, 0x13, 0x02, 0x29, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x24, 0x00, 0xFE, 0x13, 0x23, 0x11, 0x19, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x0E, 0x02, 0x28, 0x00, 0x44, 0x07, 0x1F, 0x0D, 0xFF, 0x9F, 0x59, 0x73, 0x7E, 0x37, 0x00, 0x23, 0x50, 0x13, 0x02, 0x29, 0x00, 0x45, 0x03, 0x39, 0x2D, 0xFE, 0x0E, 0x02, 0x28, 0x00, 0x44, 0x07, 0x1F, 0x0D, 0xFF, 0x1B, 0x14, 0x12, 0x00, 0x1F, 0x04, 0x19, 0x00, 0x72, 0x66, 0x85, 0xAE, 0x16, 0x00, 0x23, 0x45, 0x28, 0x1F, 0x0D, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
STRINGS_POKENAV_STORAGE const u8 gUnknown_85CB534[] = {0x13, 0x23, 0x11, 0x9F, 0x59, 0x73, 0x7E, 0x37, 0x00, 0xA2, 0x1B, 0x07, 0x0C, 0x06, 0x02, 0x1F, 0x0E, 0x2E, 0xAB, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
STRINGS_POKENAV_STORAGE const u8 gUnknown_85CB55C[] = {0x13, 0x23, 0x11, 0x9F, 0x59, 0x73, 0x7E, 0x37, 0x00, 0x02, 0x50, 0x4B, 0x02, 0x44, 0x0D, 0xAB, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};
STRINGS_POKENAV_STORAGE const u8 gUnknown_85CB584[] = {0x9A, 0xA0, 0x58, 0x5D, 0xFF, 0x6E, 0x53, 0x54, 0x7E, 0x11, 0x1E, 0x03, 0x19, 0x00, 0x6F, 0xA0, 0x9D, 0x2D, 0x00, 0x20, 0x1F, 0x0D, 0xFF, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x08, 0x2C, 0x0C, 0x08, 0x00, 0x0C, 0x27, 0x49, 0x1F, 0x0D, 0xFF, 0x14, 0x03, 0x2B, 0x08, 0x0C, 0x10, 0x00, 0x1B, 0x14, 0x2D, 0x00, 0x26, 0x47, 0x41, 0x0C, 0x1F, 0x0D, 0xFF, 0x13, 0x16, 0x02, 0x2A, 0x10, 0x00, 0x07, 0x18, 0x2E, 0x78, 0x9A, 0x7E, 0x2D, 0x00, 0x20, 0x1F, 0x0D, 0xFF, 0x9F, 0x59, 0x65, 0x97, 0x2D, 0x00, 0x0C, 0x1F, 0x02, 0x1F, 0x0D, 0xFF};
STRINGS_POKENAV_STORAGE const u8 gText_NoRibbonWinners[] = {0x78, 0x9A, 0x7E, 0x2D, 0x00, 0x23, 0x50, 0x13, 0x02, 0x29, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x37, 0x00, 0x02, 0x1F, 0x0E, 0x2E, 0xFF, 0x64, 0x7A, 0xAE, 0x65, 0xAE, 0x37, 0x00, 0x14, 0x03, 0x2B, 0x08, 0x00, 0x0B, 0x2A, 0x13, 0x02, 0x1F, 0x0E, 0x2E, 0xFF, 0x13, 0x23, 0x11, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x08, 0x2C, 0x0C, 0x08, 0x00, 0x0C, 0x27, 0x49, 0x1F, 0x0D, 0xFF, 0x0D, 0x49, 0x13, 0x19, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x08, 0x2C, 0x0C, 0x08, 0x00, 0x0C, 0x27, 0x49, 0x1F, 0x0D, 0xFF, 0x9F, 0x59, 0x65, 0x97, 0x19, 0x00, 0x72, 0x66, 0x85, 0xAE, 0x16, 0x00, 0x23, 0x45, 0x28, 0x1F, 0x0D, 0xFF, 0x06, 0x50, 0x0A, 0x02, 0x02, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x20, 0x12, 0x09, 0x1F, 0x0D, 0xFF, 0x03, 0x12, 0x08, 0x0C, 0x02, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x20, 0x12, 0x09, 0x1F, 0x0D, 0xFF, 0x06, 0x2C, 0x02, 0x02, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x20, 0x12, 0x09, 0x1F, 0x0D, 0xFF, 0x06, 0x0C, 0x0A, 0x02, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x20, 0x12, 0x09, 0x1F, 0x0D, 0xFF, 0x10, 0x08, 0x1F, 0x0C, 0x02, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0x2D, 0x00, 0x20, 0x12, 0x09, 0x1F, 0x0D, 0xFF, 0x5A, 0x7E, 0x94, 0x80, 0x5C, 0x86, 0x7E, 0x19, 0x00, 0x72, 0x66, 0x85, 0xAE, 0x16, 0x00, 0x23, 0x45, 0x28, 0x1F, 0x0D, 0xFF};
STRINGS_POKENAV_STORAGE const u8 gText_NumberRegistered[] = {0x14, 0x03, 0x2B, 0x08, 0x00, 0x16, 0x2E, 0x3E, 0x03, 0xFF};
STRINGS_POKENAV_STORAGE const u8 gText_NumberOfBattles[] = {0x10, 0x02, 0x0E, 0x2E, 0x00, 0x06, 0x02, 0x0D, 0x03, 0xFF, 0x0C, 0x36, 0x03, 0x0B, 0x02, 0xFF, 0x26, 0x47, 0x41, 0x0D, 0xFF, 0x24, 0x22, 0x29, 0xFF, 0x0A, 0x0A, 0x44, 0x1A, 0x00, 0x01, 0x02, 0x13, 0x2D, 0x00, 0x26, 0x47, 0x41, 0x0D, 0x00, 0x0A, 0x14, 0x37, 0xFE, 0x44, 0x07, 0x15, 0x02, 0x26, 0x03, 0x41, 0xFF, 0x0B, 0x08, 0x0E, 0x2E, 0xFF, 0x23, 0x50, 0x13, 0x29, 0x00, 0x9F, 0x59, 0x73, 0x7E, 0xFF, 0x3D, 0x0A, 0x0C, 0x36, 0x03, 0x06, 0x02, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xF8, 0x00, 0x06, 0x08, 0x41, 0x02, 0x00, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x00, 0x3F, 0x2E, 0x10, 0x02, 0x00, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x00, 0x5A, 0x7E, 0x94, 0x80, 0x5C, 0x86, 0x7E, 0x2D, 0x20, 0x29, 0x00, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x00, 0x6F, 0xAE, 0x57, 0x7E, 0x89, 0x00, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x00, 0x6F, 0xAE, 0x58, 0x2D, 0x04, 0x27, 0x48, 0x00, 0xF8, 0x01, 0x24, 0x22, 0x29, 0xFF, 0xF8, 0x00, 0x72, 0x66, 0x85, 0xAE, 0x00, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x00, 0x09, 0x50, 0x13, 0x02, 0x00, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x00, 0x78, 0x9A, 0x7E, 0x2D, 0x20, 0x29, 0x00, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x00, 0x0C, 0x36, 0x03, 0x0B, 0x02, 0x00, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF, 0xF8, 0x01, 0x23, 0x45, 0x29, 0xFF};

STRINGS_CLEAR_SAVE const u8 gText_ClearAllSaveData[] = {0x0D, 0x49, 0x13, 0x19, 0x00, 0x5E, 0xAE, 0x98, 0x94, 0xAE, 0x60, 0x54, 0x78, 0x51, 0x2D, 0xFE, 0x58, 0x78, 0x51, 0x00, 0x0C, 0x1F, 0x0D, 0x06, 0xAC, 0xFF};
STRINGS_CLEAR_SAVE const u8 gText_ClearingData[] = {0x58, 0x78, 0x51, 0x00, 0x0C, 0x13, 0x02, 0x1F, 0x0D, 0xFE, 0x05, 0x1F, 0x11, 0x00, 0x08, 0x41, 0x0B, 0x02, 0xFF, 0x00, 0x00, 0x00};
