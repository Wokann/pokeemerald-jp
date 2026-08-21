// JP Credits text and page table; values are reconstructed from baserom_jp.gba.

enum
{
    PAGE_TITLE,
    PAGE_DIRECTOR,
    PAGE_ART_DIRECTOR,
    PAGE_WORLD_DIRECTOR,
    PAGE_LEAD_PROGRAMMER,
    PAGE_PROGRAMMERS_1,
    PAGE_PROGRAMMERS_2,
    PAGE_PROGRAMMERS_3,
    PAGE_PROGRAMMERS_4,
    PAGE_GRAPHIC_DESIGNERS_1,
    PAGE_GRAPHIC_DESIGNERS_2,
    PAGE_GRAPHIC_DESIGNERS_3,
    PAGE_MUSIC_COMPOSITION,
    PAGE_SOUND_EFFECTS,
    PAGE_GAME_DESIGNERS_1,
    PAGE_GAME_DESIGNERS_2,
    PAGE_GAME_DESIGNERS_3,
    PAGE_SCENARIO_PLOT,
    PAGE_SCENARIO,
    PAGE_SCRIPT_DESIGNERS,
    PAGE_MAP_DESIGNERS,
    PAGE_BATTLE_FRONTIER_DATA,
    PAGE_PARAMETRIC_DESIGNERS,
    PAGE_POKEDEX_TEXT,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS,
    PAGE_PKMN_DESIGNERS_1,
    PAGE_PKMN_DESIGNERS_2,
    PAGE_PKMN_DESIGNERS_3,
    PAGE_PKMN_DESIGNERS_4,
    PAGE_SUPPORT_PROGRAMMERS,
    PAGE_NCL_PRODUCT_TESTING,
    PAGE_SPECIAL_THANKS_1,
    PAGE_SPECIAL_THANKS_2,
    PAGE_SPECIAL_THANKS_3,
    PAGE_SPECIAL_THANKS_4,
    PAGE_SPECIAL_THANKS_5,
    PAGE_BRAILLE_CODE_CHECK,
    PAGE_INFORMATION_SUPERVISORS,
    PAGE_ARTWORK,
    PAGE_COORDINATORS,
    PAGE_TASK_MANAGERS,
    PAGE_PRODUCERS,
    PAGE_EXECUTIVE_DIRECTOR,
    PAGE_EXECUTIVE_PRODUCERS_1,
    PAGE_EXECUTIVE_PRODUCERS_2,
    PAGE_COUNT,
};

#define ENTRIES_PER_PAGE 5

CREDITS_STATIC_DATA
static const u8 sCreditsText_EmptyString[] = _("");

CREDITS_STATIC_DATA
static const u8 sCreditsText_PkmnEmeraldVersion[] = _("ポケットモンスター　エメラルド");

CREDITS_STATIC_DATA
static const u8 sCreditsText_Credits[] = _("スタッフリスト");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ExecutiveDirector[] = _("エグゼクティブ　ディレクター");

CREDITS_STATIC_DATA
static const u8 sCreditsText_Director[] = _("ディレクター");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ArtDirector[] = _("アート　ディレクター");

CREDITS_STATIC_DATA
static const u8 sCreditsText_BattleDirector[] = _("バトル　ディレクター");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MainProgrammer[] = _("メイン　プログラム");

CREDITS_STATIC_DATA
static const u8 sCreditsText_BattleSystemPgrms[] = _("バトル　システム　プログラム");

CREDITS_STATIC_DATA
static const u8 sCreditsText_FieldSystemPgrms[] = _("フィールド　システム　プログラム");

CREDITS_STATIC_DATA
static const u8 sCreditsText_Programmers[] = _("プログラム");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MainGraphicDesigner[] = _("メイン　グラフィック　デザイン");

CREDITS_STATIC_DATA
static const u8 sCreditsText_GraphicDesigners[] = _("グラフィック　デザイン");

CREDITS_STATIC_DATA
static const u8 sCreditsText_PkmnDesigners[] = _("ポケモン　デザイン");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MusicComposition[] = _("おんがく");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SoundEffectsAndPkmnVoices[] = _("サウンド　エフェクト/ポケモン　ボイス");

CREDITS_STATIC_DATA
static const u8 sCreditsText_GameDesigners[] = _("ゲーム　デザイン");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ScenarioPlot[] = _("シナリオプロット");

CREDITS_STATIC_DATA
static const u8 sCreditsText_Scenario[] = _("シナリオ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ScriptDesigners[] = _("スクリプト　せってい");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MapDesigners[] = _("マップ　デザイン");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MapDataDesigners[] = _("マップデータ　せってい");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ParametricDesigners[] = _("パラメーター　せってい");

CREDITS_STATIC_DATA
static const u8 sCreditsText_PokedexText[] = _("ずかん　テキスト");

CREDITS_STATIC_DATA
static const u8 sCreditsText_EnvAndToolPgrms[] = _("かんきょう/ツール　プログラム");

CREDITS_STATIC_DATA
static const u8 sCreditsText_NCLProductTesting[] = _("デバッグプレイ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SpecialThanks[] = _("スペシャルサンクス");

CREDITS_STATIC_DATA
static const u8 sCreditsText_Coordinators[] = _("コーディネーター");

CREDITS_STATIC_DATA
static const u8 sCreditsText_Producers[] = _("プロデューサー");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ExecProducers[] = _("エグゼクティブ　プロデューサー");

CREDITS_STATIC_DATA
static const u8 sCreditsText_InfoSupervisors[] = _("じょうほう　かんり");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TaskManagers[] = _("ファンクション　マネージャー");

CREDITS_STATIC_DATA
static const u8 sCreditsText_BrailleCodeCheck[] = _("てんじ　かんしゅう");

CREDITS_STATIC_DATA
static const u8 sCreditsText_WorldDirector[] = _("ワールド　ディレクター");

CREDITS_STATIC_DATA
static const u8 sCreditsText_BattleFrontierData[] = _("バトルフロンティア　データ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SupportProgrammers[] = _("プログラム　サポート");

CREDITS_STATIC_DATA
static const u8 sCreditsText_Artwork[] = _("アート　ワーク");

CREDITS_STATIC_DATA
static const u8 sCreditsText_LeadProgrammer[] = _("プログラム　リーダー");

CREDITS_STATIC_DATA
static const u8 sCreditsText_LeadGraphicArtist[] = _("グラフィック　リーダー");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SatoshiTajiri[] = _("たじり　さとし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_JunichiMasuda[] = _("ますだ　じゅんいち");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KenSugimori[] = _("すぎもり　けん");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ShigekiMorimoto[] = _("もりもと　しげき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TetsuyaWatanabe[] = _("わたなべ　てつや");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HisashiSogabe[] = _("そがべ　ひさし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SosukeTamada[] = _("たまだ　そうすけ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AkitoMori[] = _("もり　あきと");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KeitaKagaya[] = _("かがや　けいた");

CREDITS_STATIC_DATA
static const u8 sCreditsText_YoshinoriMatsuda[] = _("まつだ　よしのり");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HiroyukiNakamura[] = _("なかむら　ひろゆき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MasaoTaya[] = _("たや　まさお");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SatoshiNohara[] = _("のはら　さとし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TomomichiOhta[] = _("おおた　ともみち");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MiyukiIwasawa[] = _("いわさわ　みゆき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TakenoriOhta[] = _("おおた　たけのり");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HironobuYoshida[] = _("よしだ　ひろのぶ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MotofumiFujiwara[] = _("ふじわら　もとふみ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SatoshiOhta[] = _("おおた　さとし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AsukaIwashita[] = _("いわした　あすか");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AimiTomita[] = _("とみた　あいみ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TakaoUnno[] = _("うんの　たかお");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KanakoEo[] = _("えお　かなこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_JunOkutani[] = _("おくたに　じゅん");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AtsukoNishida[] = _("にしだ　あつこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MuneoSaito[] = _("さいとう　むねお");

CREDITS_STATIC_DATA
static const u8 sCreditsText_RenaYoshikawa[] = _("よしかわ　れな");

CREDITS_STATIC_DATA
static const u8 sCreditsText_GoIchinose[] = _("いちのせ　ごう");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MorikazuAoki[] = _("あおき　もりかず");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KojiNishino[] = _("にしの　こうじ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KenjiMatsushima[] = _("まつしま　けんじ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TetsujiOhta[] = _("おおた　てつじ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HitomiSato[] = _("さとう　ひとみ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TakeshiKawachimaru[] = _("かわちまる　たけし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TeruyukiShimoyamada[] = _("しもやまだ　てるゆき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ShigeruOhmori[] = _("おおもり　しげる");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TadashiTakahashi[] = _("たかはし　ただし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ToshinobuMatsumiya[] = _("まつみや　としのぶ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AkihitoTomisawa[] = _("とみさわ　あきひと");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HirokiEnomoto[] = _("えのもと　ひろき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KazuyukiTerada[] = _("てらだ　かずゆき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_YuriSakurai[] = _("さくらい　ゆうり");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HiromiSagawa[] = _("さがわ　ひろみ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KenjiTominaga[] = _("とみなが　けんじ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_YoshioTajiri[] = _("たじり　よしお");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TeikoSasaki[] = _("ささき　ていこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SachikoHamano[] = _("はまの　さちこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ChieMatsumiya[] = _("まつみや　ちえ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AkikoShinozaki[] = _("しのざき　あきこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AstukoFujii[] = _("ふじい　あつこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_NozomuSaito[] = _("さいとう　のぞむ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KenkichiToyama[] = _("とやま　けんきち");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SuguruNakatsui[] = _("なかつい　すぐる");

CREDITS_STATIC_DATA
static const u8 sCreditsText_YumiFunasaka[] = _("ふなさか　ゆみ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_NaokoYanase[] = _("やなせ　なおこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_NCLSuperMarioClub[] = _("スーパーマリオクラブ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AtsushiTada[] = _("ただ　あつし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TakahiroOhnishi[] = _("おおにし　たかひろ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_NorihideOkamura[] = _("おかむら　のりひで");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HiroNakamura[] = _("なかむら　ひろき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HiroyukiUesugi[] = _("うえすぎ　ひろゆき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TerukiMurakawa[] = _("むらかわ　てるき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AkiraKinashi[] = _("きなし　あきら");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MichikoTakizawa[] = _("たきざわ　みちこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MakikoTakada[] = _("たかだ　まきこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TakanaoKondo[] = _("こんどう　たかなお");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AiMashima[] = _("ましま　あい");

CREDITS_STATIC_DATA
static const u8 sCreditsText_GakujiNomoto[] = _("のもと　がくじ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TakehiroIzushi[] = _("いずし　たけひろ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HitoshiYamagami[] = _("やまがみ　ひとし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KyokoWatanabe[] = _("わたなべ　きょうこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TakaoNakano[] = _("なかの　たかお");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HiroyukiJinnai[] = _("じんない　ひろゆき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_HiroakiTsuru[] = _("つる　ひろあき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TsunekazIshihara[] = _("いしはら　つねかず");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SatoruIwata[] = _("いわた　さとる");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KazuyaSuyama[] = _("すやま　かずや");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SatoshiMitsuhara[] = _("みつはら　さとし");

CREDITS_STATIC_DATA
static const u8 sCreditsText_JapanBrailleLibrary[] = _("にっぽんてんじとしょかん");

CREDITS_STATIC_DATA
static const u8 sCreditsText_TomotakaKomura[] = _("こむら　ともたか");

CREDITS_STATIC_DATA
static const u8 sCreditsText_MikikoOhhashi[] = _("おおはし　みきこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_DaisukeHoshino[] = _("ほしの　だいすけ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KenjiroIto[] = _("いとう　けんじろう");

CREDITS_STATIC_DATA
static const u8 sCreditsText_RuiKawaguchi[] = _("かわぐち　るい");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ShunsukeKohori[] = _("こほり　しゅんすけ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_SachikoNakamichi[] = _("なかみち　さちこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_FujikoNomura[] = _("のむら　ふじこ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_KazukiYoshihara[] = _("よしはら　かずき");

CREDITS_STATIC_DATA
static const u8 sCreditsText_RetsujiNomoto[] = _("のもと　れつじ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_AzusaTajima[] = _("たじま　あずさ");

CREDITS_STATIC_DATA
static const u8 sCreditsText_ShusakuEgami[] = _("えがみ　しゅうさく");

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_EmptyString = { 0, FALSE, sCreditsText_EmptyString };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_PkmnEmeraldVersion = { 7, TRUE, sCreditsText_PkmnEmeraldVersion };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_Credits = { 11, TRUE, sCreditsText_Credits };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ExecutiveDirector = { 8, TRUE, sCreditsText_ExecutiveDirector };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_Director = { 12, TRUE, sCreditsText_Director };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ArtDirector = { 10, TRUE, sCreditsText_ArtDirector };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_BattleDirector = { 10, TRUE, sCreditsText_BattleDirector };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MainProgrammer = { 10, TRUE, sCreditsText_MainProgrammer };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_BattleSystemPgrms = { 8, TRUE, sCreditsText_BattleSystemPgrms };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_FieldSystemPgrms = { 7, TRUE, sCreditsText_FieldSystemPgrms };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_Programmers = { 12, TRUE, sCreditsText_Programmers };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MainGraphicDesigner = { 7, TRUE, sCreditsText_MainGraphicDesigner };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_GraphicDesigners = { 9, TRUE, sCreditsText_GraphicDesigners };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_PkmnDesigners = { 10, TRUE, sCreditsText_PkmnDesigners };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MusicComposition = { 13, TRUE, sCreditsText_MusicComposition };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SoundEffectsAndPkmnVoices = { 4, TRUE, sCreditsText_SoundEffectsAndPkmnVoices };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_GameDesigners = { 11, TRUE, sCreditsText_GameDesigners };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ScenarioPlot = { 11, TRUE, sCreditsText_ScenarioPlot };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_Scenario = { 13, TRUE, sCreditsText_Scenario };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ScriptDesigners = { 10, TRUE, sCreditsText_ScriptDesigners };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MapDesigners = { 11, TRUE, sCreditsText_MapDesigners };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MapDataDesigners = { 9, TRUE, sCreditsText_MapDataDesigners };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ParametricDesigners = { 9, TRUE, sCreditsText_ParametricDesigners };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_PokedexText = { 11, TRUE, sCreditsText_PokedexText };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_EnvAndToolPgrms = { 6, TRUE, sCreditsText_EnvAndToolPgrms };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_NCLProductTesting = { 11, TRUE, sCreditsText_NCLProductTesting };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SpecialThanks = { 10, TRUE, sCreditsText_SpecialThanks };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_Coordinators = { 11, TRUE, sCreditsText_Coordinators };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_Producers = { 11, TRUE, sCreditsText_Producers };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ExecProducers = { 7, TRUE, sCreditsText_ExecProducers };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_InfoSupervisors = { 10, TRUE, sCreditsText_InfoSupervisors };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TaskManagers = { 8, TRUE, sCreditsText_TaskManagers };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_BrailleCodeCheck = { 10, TRUE, sCreditsText_BrailleCodeCheck };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_WorldDirector = { 10, TRUE, sCreditsText_WorldDirector };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_BattleFrontierData = { 8, TRUE, sCreditsText_BattleFrontierData };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SupportProgrammers = { 10, TRUE, sCreditsText_SupportProgrammers };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_Artwork = { 12, TRUE, sCreditsText_Artwork };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_LeadProgrammer = { 10, TRUE, sCreditsText_LeadProgrammer };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_LeadGraphicArtist = { 9, TRUE, sCreditsText_LeadGraphicArtist };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SatoshiTajiri = { 11, FALSE, sCreditsText_SatoshiTajiri };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_JunichiMasuda = { 11, FALSE, sCreditsText_JunichiMasuda };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KenSugimori = { 11, FALSE, sCreditsText_KenSugimori };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ShigekiMorimoto = { 11, FALSE, sCreditsText_ShigekiMorimoto };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TetsuyaWatanabe = { 11, FALSE, sCreditsText_TetsuyaWatanabe };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HisashiSogabe = { 11, FALSE, sCreditsText_HisashiSogabe };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SosukeTamada = { 11, FALSE, sCreditsText_SosukeTamada };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AkitoMori = { 11, FALSE, sCreditsText_AkitoMori };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KeitaKagaya = { 11, FALSE, sCreditsText_KeitaKagaya };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_YoshinoriMatsuda = { 11, FALSE, sCreditsText_YoshinoriMatsuda };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HiroyukiNakamura = { 11, FALSE, sCreditsText_HiroyukiNakamura };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MasaoTaya = { 11, FALSE, sCreditsText_MasaoTaya };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SatoshiNohara = { 11, FALSE, sCreditsText_SatoshiNohara };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TomomichiOhta = { 11, FALSE, sCreditsText_TomomichiOhta };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MiyukiIwasawa = { 11, FALSE, sCreditsText_MiyukiIwasawa };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TakenoriOhta = { 11, FALSE, sCreditsText_TakenoriOhta };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HironobuYoshida = { 11, FALSE, sCreditsText_HironobuYoshida };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MotofumiFujiwara = { 11, FALSE, sCreditsText_MotofumiFujiwara };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SatoshiOhta = { 11, FALSE, sCreditsText_SatoshiOhta };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AsukaIwashita = { 11, FALSE, sCreditsText_AsukaIwashita };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AimiTomita = { 11, FALSE, sCreditsText_AimiTomita };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TakaoUnno = { 11, FALSE, sCreditsText_TakaoUnno };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KanakoEo = { 11, FALSE, sCreditsText_KanakoEo };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_JunOkutani = { 11, FALSE, sCreditsText_JunOkutani };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AtsukoNishida = { 11, FALSE, sCreditsText_AtsukoNishida };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MuneoSaito = { 11, FALSE, sCreditsText_MuneoSaito };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_RenaYoshikawa = { 11, FALSE, sCreditsText_RenaYoshikawa };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_GoIchinose = { 11, FALSE, sCreditsText_GoIchinose };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MorikazuAoki = { 11, FALSE, sCreditsText_MorikazuAoki };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KojiNishino = { 11, FALSE, sCreditsText_KojiNishino };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KenjiMatsushima = { 11, FALSE, sCreditsText_KenjiMatsushima };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TetsujiOhta = { 11, FALSE, sCreditsText_TetsujiOhta };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HitomiSato = { 11, FALSE, sCreditsText_HitomiSato };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TakeshiKawachimaru = { 11, FALSE, sCreditsText_TakeshiKawachimaru };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TeruyukiShimoyamada = { 11, FALSE, sCreditsText_TeruyukiShimoyamada };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ShigeruOhmori = { 11, FALSE, sCreditsText_ShigeruOhmori };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TadashiTakahashi = { 11, FALSE, sCreditsText_TadashiTakahashi };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ToshinobuMatsumiya = { 11, FALSE, sCreditsText_ToshinobuMatsumiya };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AkihitoTomisawa = { 11, FALSE, sCreditsText_AkihitoTomisawa };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HirokiEnomoto = { 11, FALSE, sCreditsText_HirokiEnomoto };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KazuyukiTerada = { 11, FALSE, sCreditsText_KazuyukiTerada };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_YuriSakurai = { 11, FALSE, sCreditsText_YuriSakurai };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HiromiSagawa = { 11, FALSE, sCreditsText_HiromiSagawa };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KenjiTominaga = { 11, FALSE, sCreditsText_KenjiTominaga };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_YoshioTajiri = { 11, FALSE, sCreditsText_YoshioTajiri };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TeikoSasaki = { 11, FALSE, sCreditsText_TeikoSasaki };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SachikoHamano = { 11, FALSE, sCreditsText_SachikoHamano };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ChieMatsumiya = { 11, FALSE, sCreditsText_ChieMatsumiya };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AkikoShinozaki = { 11, FALSE, sCreditsText_AkikoShinozaki };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AstukoFujii = { 11, FALSE, sCreditsText_AstukoFujii };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_NozomuSaito = { 11, FALSE, sCreditsText_NozomuSaito };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KenkichiToyama = { 11, FALSE, sCreditsText_KenkichiToyama };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SuguruNakatsui = { 11, FALSE, sCreditsText_SuguruNakatsui };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_YumiFunasaka = { 11, FALSE, sCreditsText_YumiFunasaka };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_NaokoYanase = { 11, FALSE, sCreditsText_NaokoYanase };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_NCLSuperMarioClub = { 11, FALSE, sCreditsText_NCLSuperMarioClub };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AtsushiTada = { 11, FALSE, sCreditsText_AtsushiTada };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TakahiroOhnishi = { 11, FALSE, sCreditsText_TakahiroOhnishi };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_NorihideOkamura = { 11, FALSE, sCreditsText_NorihideOkamura };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HiroNakamura = { 11, FALSE, sCreditsText_HiroNakamura };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HiroyukiUesugi = { 11, FALSE, sCreditsText_HiroyukiUesugi };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TerukiMurakawa = { 11, FALSE, sCreditsText_TerukiMurakawa };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AkiraKinashi = { 11, FALSE, sCreditsText_AkiraKinashi };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MichikoTakizawa = { 11, FALSE, sCreditsText_MichikoTakizawa };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MakikoTakada = { 11, FALSE, sCreditsText_MakikoTakada };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TakanaoKondo = { 11, FALSE, sCreditsText_TakanaoKondo };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AiMashima = { 11, FALSE, sCreditsText_AiMashima };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_GakujiNomoto = { 11, FALSE, sCreditsText_GakujiNomoto };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TakehiroIzushi = { 11, FALSE, sCreditsText_TakehiroIzushi };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HitoshiYamagami = { 11, FALSE, sCreditsText_HitoshiYamagami };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KyokoWatanabe = { 11, FALSE, sCreditsText_KyokoWatanabe };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TakaoNakano = { 11, FALSE, sCreditsText_TakaoNakano };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HiroyukiJinnai = { 11, FALSE, sCreditsText_HiroyukiJinnai };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_HiroakiTsuru = { 11, FALSE, sCreditsText_HiroakiTsuru };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TsunekazIshihara = { 11, FALSE, sCreditsText_TsunekazIshihara };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SatoruIwata = { 11, FALSE, sCreditsText_SatoruIwata };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KazuyaSuyama = { 11, FALSE, sCreditsText_KazuyaSuyama };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SatoshiMitsuhara = { 11, FALSE, sCreditsText_SatoshiMitsuhara };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_JapanBrailleLibrary = { 9, FALSE, sCreditsText_JapanBrailleLibrary };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_TomotakaKomura = { 11, FALSE, sCreditsText_TomotakaKomura };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_MikikoOhhashi = { 11, FALSE, sCreditsText_MikikoOhhashi };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_DaisukeHoshino = { 11, FALSE, sCreditsText_DaisukeHoshino };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KenjiroIto = { 11, FALSE, sCreditsText_KenjiroIto };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_RuiKawaguchi = { 11, FALSE, sCreditsText_RuiKawaguchi };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ShunsukeKohori = { 11, FALSE, sCreditsText_ShunsukeKohori };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_SachikoNakamichi = { 11, FALSE, sCreditsText_SachikoNakamichi };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_FujikoNomura = { 11, FALSE, sCreditsText_FujikoNomura };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_KazukiYoshihara = { 11, FALSE, sCreditsText_KazukiYoshihara };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_RetsujiNomoto = { 11, FALSE, sCreditsText_RetsujiNomoto };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_AzusaTajima = { 11, FALSE, sCreditsText_AzusaTajima };

CREDITS_STATIC_DATA
static const struct CreditsEntry sCreditsEntry_ShusakuEgami = { 11, FALSE, sCreditsText_ShusakuEgami };

#define _ &sCreditsEntry_EmptyString
CREDITS_STATIC_DATA
static const struct CreditsEntry *const sCreditsEntryPointerTable[PAGE_COUNT][ENTRIES_PER_PAGE] =
{
    [PAGE_TITLE] = {
        _,
        &sCreditsEntry_PkmnEmeraldVersion,
        &sCreditsEntry_Credits,
        _,
        _,
    },
    [PAGE_DIRECTOR] = {
        _,
        &sCreditsEntry_Director,
        &sCreditsEntry_ShigekiMorimoto,
        _,
        _,
    },
    [PAGE_ART_DIRECTOR] = {
        _,
        &sCreditsEntry_ArtDirector,
        &sCreditsEntry_KenSugimori,
        _,
        _,
    },
    [PAGE_WORLD_DIRECTOR] = {
        _,
        &sCreditsEntry_WorldDirector,
        &sCreditsEntry_JunichiMasuda,
        _,
        _,
    },
    [PAGE_LEAD_PROGRAMMER] = {
        &sCreditsEntry_LeadProgrammer,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_LeadGraphicArtist,
        &sCreditsEntry_MotofumiFujiwara,
        _,
    },
    [PAGE_PROGRAMMERS_1] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_TomomichiOhta,
        &sCreditsEntry_NozomuSaito,
        _,
    },
    [PAGE_PROGRAMMERS_2] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_AkitoMori,
        &sCreditsEntry_HiroyukiNakamura,
        &sCreditsEntry_MasaoTaya,
        _,
    },
    [PAGE_PROGRAMMERS_3] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_SatoshiNohara,
        &sCreditsEntry_MiyukiIwasawa,
        &sCreditsEntry_YoshinoriMatsuda,
        &sCreditsEntry_KeitaKagaya,
    },
    [PAGE_PROGRAMMERS_4] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_TetsuyaWatanabe,
        &sCreditsEntry_SosukeTamada,
        &sCreditsEntry_TakenoriOhta,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_1] = {
        _,
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_MotofumiFujiwara,
        &sCreditsEntry_SatoshiOhta,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_2] = {
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_KenkichiToyama,
        &sCreditsEntry_AsukaIwashita,
        &sCreditsEntry_TakaoUnno,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_3] = {
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_KenSugimori,
        &sCreditsEntry_HironobuYoshida,
        &sCreditsEntry_AimiTomita,
        &sCreditsEntry_KanakoEo,
    },
    [PAGE_MUSIC_COMPOSITION] = {
        &sCreditsEntry_MusicComposition,
        &sCreditsEntry_GoIchinose,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_MorikazuAoki,
        &sCreditsEntry_HitomiSato,
    },
    [PAGE_SOUND_EFFECTS] = {
        _,
        &sCreditsEntry_SoundEffectsAndPkmnVoices,
        &sCreditsEntry_GoIchinose,
        &sCreditsEntry_MorikazuAoki,
        _,
    },
    [PAGE_GAME_DESIGNERS_1] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_ShigekiMorimoto,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_TakeshiKawachimaru,
        &sCreditsEntry_AkihitoTomisawa,
    },
    [PAGE_GAME_DESIGNERS_2] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_SuguruNakatsui,
        &sCreditsEntry_TetsujiOhta,
        &sCreditsEntry_HitomiSato,
        &sCreditsEntry_KenjiMatsushima,
    },
    [PAGE_GAME_DESIGNERS_3] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_KojiNishino,
        &sCreditsEntry_ShigeruOhmori,
        &sCreditsEntry_TadashiTakahashi,
    },
    [PAGE_SCENARIO_PLOT] = {
        &sCreditsEntry_ScenarioPlot,
        &sCreditsEntry_AkihitoTomisawa,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_KojiNishino,
        _,
    },
    [PAGE_SCENARIO] = {
        &sCreditsEntry_Scenario,
        &sCreditsEntry_AkihitoTomisawa,
        &sCreditsEntry_HitomiSato,
        &sCreditsEntry_ToshinobuMatsumiya,
        _,
    },
    [PAGE_SCRIPT_DESIGNERS] = {
        &sCreditsEntry_ScriptDesigners,
        &sCreditsEntry_TomomichiOhta,
        &sCreditsEntry_SatoshiNohara,
        _,
        _,
    },
    [PAGE_MAP_DESIGNERS] = {
        &sCreditsEntry_MapDesigners,
        &sCreditsEntry_SuguruNakatsui,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_ShigeruOhmori,
        &sCreditsEntry_TetsujiOhta,
    },
    [PAGE_BATTLE_FRONTIER_DATA] = {
        _,
        &sCreditsEntry_BattleFrontierData,
        &sCreditsEntry_TetsujiOhta,
        _,
        _,
    },
    [PAGE_PARAMETRIC_DESIGNERS] = {
        &sCreditsEntry_ParametricDesigners,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_ShigekiMorimoto,
        &sCreditsEntry_TetsujiOhta,
        &sCreditsEntry_KojiNishino,
    },
    [PAGE_POKEDEX_TEXT] = {
        _,
        &sCreditsEntry_PokedexText,
        &sCreditsEntry_KenjiMatsushima,
        _,
        _,
    },
    [PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS] = {
        &sCreditsEntry_EnvAndToolPgrms,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_SosukeTamada,
        &sCreditsEntry_HiroyukiNakamura,
        &sCreditsEntry_AkitoMori,
    },
    [PAGE_PKMN_DESIGNERS_1] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_KenSugimori,
        &sCreditsEntry_MotofumiFujiwara,
        &sCreditsEntry_ShigekiMorimoto,
        _,
    },
    [PAGE_PKMN_DESIGNERS_2] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_HironobuYoshida,
        &sCreditsEntry_SatoshiOhta,
        &sCreditsEntry_AsukaIwashita,
        _,
    },
    [PAGE_PKMN_DESIGNERS_3] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_TakaoUnno,
        &sCreditsEntry_KanakoEo,
        &sCreditsEntry_AimiTomita,
        _,
    },
    [PAGE_PKMN_DESIGNERS_4] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_AtsukoNishida,
        &sCreditsEntry_MuneoSaito,
        &sCreditsEntry_RenaYoshikawa,
        &sCreditsEntry_JunOkutani,
    },
    [PAGE_SUPPORT_PROGRAMMERS] = {
        _,
        &sCreditsEntry_SupportProgrammers,
        &sCreditsEntry_SatoshiMitsuhara,
        &sCreditsEntry_DaisukeHoshino,
        _,
    },
    [PAGE_NCL_PRODUCT_TESTING] = {
        _,
        &sCreditsEntry_NCLProductTesting,
        &sCreditsEntry_NCLSuperMarioClub,
        _,
        _,
    },
    [PAGE_SPECIAL_THANKS_1] = {
        _,
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_KenjiTominaga,
        &sCreditsEntry_HirokiEnomoto,
        _,
    },
    [PAGE_SPECIAL_THANKS_2] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_HiroNakamura,
        &sCreditsEntry_HiroyukiUesugi,
        &sCreditsEntry_TerukiMurakawa,
        _,
    },
    [PAGE_SPECIAL_THANKS_3] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_KazuyaSuyama,
        &sCreditsEntry_KenjiroIto,
        &sCreditsEntry_MichikoTakizawa,
        &sCreditsEntry_MakikoTakada,
    },
    [PAGE_SPECIAL_THANKS_4] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_MikikoOhhashi,
        &sCreditsEntry_TakanaoKondo,
        &sCreditsEntry_RuiKawaguchi,
        _,
    },
    [PAGE_SPECIAL_THANKS_5] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_TakahiroOhnishi,
        &sCreditsEntry_NorihideOkamura,
        &sCreditsEntry_ShunsukeKohori,
        _,
    },
    [PAGE_BRAILLE_CODE_CHECK] = {
        _,
        &sCreditsEntry_BrailleCodeCheck,
        &sCreditsEntry_JapanBrailleLibrary,
        _,
        _,
    },
    [PAGE_INFORMATION_SUPERVISORS] = {
        &sCreditsEntry_InfoSupervisors,
        &sCreditsEntry_KazuyukiTerada,
        &sCreditsEntry_YuriSakurai,
        &sCreditsEntry_YumiFunasaka,
        &sCreditsEntry_NaokoYanase,
    },
    [PAGE_ARTWORK] = {
        _,
        &sCreditsEntry_Artwork,
        &sCreditsEntry_SachikoNakamichi,
        &sCreditsEntry_FujikoNomura,
        _,
    },
    [PAGE_COORDINATORS] = {
        &sCreditsEntry_Coordinators,
        &sCreditsEntry_KazukiYoshihara,
        &sCreditsEntry_AkiraKinashi,
        &sCreditsEntry_RetsujiNomoto,
        _,
    },
    [PAGE_TASK_MANAGERS] = {
        _,
        &sCreditsEntry_TaskManagers,
        &sCreditsEntry_AzusaTajima,
        &sCreditsEntry_ShusakuEgami,
        _,
    },
    [PAGE_PRODUCERS] = {
        &sCreditsEntry_Producers,
        &sCreditsEntry_HiroyukiJinnai,
        &sCreditsEntry_HitoshiYamagami,
        &sCreditsEntry_GakujiNomoto,
        &sCreditsEntry_HiroakiTsuru,
    },
    [PAGE_EXECUTIVE_DIRECTOR] = {
        _,
        &sCreditsEntry_ExecutiveDirector,
        &sCreditsEntry_SatoshiTajiri,
        _,
        _,
    },
    [PAGE_EXECUTIVE_PRODUCERS_1] = {
        _,
        &sCreditsEntry_ExecProducers,
        &sCreditsEntry_SatoruIwata,
        _,
        _,
    },
    [PAGE_EXECUTIVE_PRODUCERS_2] = {
        _,
        &sCreditsEntry_ExecProducers,
        &sCreditsEntry_TsunekazIshihara,
        _,
        _,
    },
};
#undef _
