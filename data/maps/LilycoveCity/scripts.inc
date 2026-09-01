@ LilycoveCity scripts (JP map g0 m5 @ 0x081E0171)

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition::
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad::
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	copyvar VAR_0x8000, VAR_0x8004
	goto_if_eq VAR_0x8000, 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	copyvar VAR_0x8000, VAR_STARTER_MON
	goto_if_eq VAR_0x8000, 0, LilycoveCity_EventScript_BattleMayTreecko
	goto_if_eq VAR_0x8000, 1, LilycoveCity_EventScript_BattleMayTorchic
	goto_if_eq VAR_0x8000, 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	copyvar VAR_0x8000, VAR_STARTER_MON
	goto_if_eq VAR_0x8000, 0, LilycoveCity_EventScript_BattleBrendanTreecko
	goto_if_eq VAR_0x8000, 1, LilycoveCity_EventScript_BattleBrendanTorchic
	goto_if_eq VAR_0x8000, 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectarg 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle: @ 0x081E0696
	.string "ハルカ“あら！？\n"
	.string "{PLAYER}{KUN}も　おかいもの？\p"
	.string "あたし　ぬいぐるみとか　ポスター\n"
	.string "いっぱい　かっちゃった！\p"
	.string "もちろん　ポケモン　いっぱい　つかまえたし\n"
	.string "ちゃんと　そだてて　いるんだから！\p"
	.string "あたし　としては　{PLAYER}{KUN}が\n"
	.string "ポケモン　そだててるか　しんぱい　だな\p"
	.string "しょうぶ　してあげるから\n"
	.string "{PLAYER}{KUN}の　ポケモン　みせてよ！$"

LilycoveCity_Text_MayNotRaisingPokemon: @ 0x081E0733
	.string "ハルカ“えー　なんで？\n"
	.string "{PLAYER}{KUN}　ポケモン　そだててないの？\p"
	.string "それじゃあ　トレーナーとして\n"
	.string "まだまだ　ね！$"

LilycoveCity_Text_MayBattleMe: @ 0x081E0769
	.string "ハルカ“しょうぶ　してあげるから\n"
	.string "{PLAYER}{KUN}の　ポケモン　みせてよ！$"

LilycoveCity_Text_MayWontBeBeaten: @ 0x081E078B
	.string "ハルカ“あたしの　そだてた　ポケモンが\n"
	.string "{PLAYER}{KUN}の　ポケモンに\l"
	.string "まけるわけ　ないんだから！$"

LilycoveCity_Text_MayDefeat: @ 0x081E07B9
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "103ばん　どうろで\n"
	.string "{PLAYER}{KUN}と　しょうぶ　したこと\l"
	.string "おもいだしちゃった！\p"
	.string "あの　しょうぶが　あったから\n"
	.string "{PLAYER}{KUN}　ここまで\l"
	.string "つよく　なったんだね！$"

LilycoveCity_Text_MayGoingBackToLittleroot: @ 0x081E080D
	.string "ハルカ“あたし　そろそろ\n"
	.string "ミシロタウンに　かえる　つもりなの\p"
	.string "いろいろ　ポケモン　つかまえて\n"
	.string "ずかんも　けっこう　できてきたから\l"
	.string "おとうさんに　みせるんだ！$"

LilycoveCity_Text_MayYouGoingToCollectBadges: @ 0x081E085C
	.string "{PLAYER}{KUN}は　どうするの？\p"
	.string "あちこちの　ジムバッジを　あつめて\n"
	.string "ポケモンリーグ　ちょうせん　するの？\p"
	.string "じゃあ　あたし　{PLAYER}{KUN}が\n"
	.string "バッジを　あつめている　あいだに\l"
	.string "ポケモンずかんを　かんせい　させちゃお！\p"
	.string "じゃね！$"

LilycoveCity_Text_MayYouGoingToPokemonLeague: @ 0x081E08C7
	.string "{PLAYER}{KUN}は　どうするの？\p"
	.string "ポケモンリーグ　ちょうせん　するの？\p"
	.string "それとも　ポケモンずかん\l"
	.string "かんせい　させるの？\p"
	.string "ポケモンしょうぶ　じゃ　まけちゃったけど\n"
	.string "ずかんは　あたしの　ほうが\l"
	.string "さきに　かんせい　させるんだから！\p"
	.string "じゃね！$"

LilycoveCity_Text_MayYouGoingToBattleFrontier: @ 0x081E0939
	.string "{PLAYER}{KUN}は　どうするの？\p"
	.string "バトルフロンティアに　ちょうせん　する？\n"
	.string "それとも　ずかんを　かんせい　させる？\p"
	.string "ポケモンしょうぶ　じゃ　まけちゃったけど\n"
	.string "ずかんは　あたしの　ほうが\l"
	.string "さきに　かんせい　させるんだから！\p"
	.string "じゃね！$"

LilycoveCity_Text_BrendanShoppingLetsBattle: @ 0x081E09A9
	.string "ユウキ“なんだ　{PLAYER}か\p"
	.string "オレ　とうさんに　たのまれた\n"
	.string "かいものを　してたんだ\l"
	.string "べつに　ぬいぐるみ　なんか　かってないよ\p"
	.string "それよりも　ひさしぶりに　あったんだ\p"
	.string "どっちが　うまく\n"
	.string "ポケモン　そだてているか\l"
	.string "しょうぶ　してやろうか？$"

LilycoveCity_Text_BrendanNoConfidence: @ 0x081E0A1B
	.string "ユウキ“なんだよ\n"
	.string "じしんが　ないのかよ$"

LilycoveCity_Text_BrendanBattleMe: @ 0x081E0A2F
	.string "ユウキ“どっちが　うまく\n"
	.string "ポケモン　そだてているか\l"
	.string "しょうぶ　してやろうか？$"

LilycoveCity_Text_BrendanWontBeBeaten: @ 0x081E0A56
	.string "ユウキ“まあ　オレが\n"
	.string "{PLAYER}に　まけるわけ　ないんだけど$"

LilycoveCity_Text_BrendanDefeat: @ 0x081E0A72
	.string "ふうん⋯⋯\n"
	.string "かなり　そだててるんだな\p"
	.string "ちょっと　くやしいな\n"
	.string "トレーナーとしては　オレの　ほうが\l"
	.string "センパイ　だったのに⋯⋯$"

LilycoveCity_Text_BrendanGoingBackToLittleroot: @ 0x081E0AAF
	.string "ユウキ“オレ⋯⋯\n"
	.string "ミシロタウンに　もどるつもり　なんだ\p"
	.string "とうさんの　てつだいで　つくっている\n"
	.string "ポケモンずかんも　けっこう　できてきたし\l"
	.string "いちど　とうさんに　みせておかないと$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges: @ 0x081E0B06
	.string "{PLAYER}は　どうする？\p"
	.string "やっぱり　ぜんぶの　ジムバッジ　あつめて\n"
	.string "ポケモンリーグ　ちょうせん　するのか？\p"
	.string "オレも　そうしようかな\p"
	.string "まあ　いいや\n"
	.string "とにかく　がんばれよ！$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague: @ 0x081E0B58
	.string "{PLAYER}は　どうする？\p"
	.string "そんなに　つよいんだから\n"
	.string "ポケモンリーグに　ちょうせん　するのか？\p"
	.string "オレだって　もうちょっと\n"
	.string "ポケモン　そだてれば　{PLAYER}よりも\l"
	.string "つよくなれる　はずだからな\p"
	.string "まあ　いいや\n"
	.string "とにかく　がんばれよ！$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier: @ 0x081E0BC3
	.string "{PLAYER}は　どうする？\p"
	.string "バトルフロンティアに　ちょうせん　する？\n"
	.string "それとも　ずかんを　かんせい　させる？\p"
	.string "そんなに　つよいんだから\n"
	.string "バトルフロンティアに　ちょうせん　するか？\p"
	.string "オレだって　もうちょっと\n"
	.string "ポケモン　そだてれば　{PLAYER}よりも\l"
	.string "つよくなれる　はずだからな\l"
	.string "バトルフロンティアに　いってみようかな？\p"
	.string "まあ　いいや\n"
	.string "とにかく　がんばれよ！$"

LilycoveCity_Text_MovedLootIntoHideoutToday: @ 0x081E0C6D
	.string "ふふふ⋯⋯\p"
	.string "きょうも　うばった　ブツを\n"
	.string "アジトに　はこびこんだぞ⋯⋯\p"
	.string "なっ　なんだ　おまえ！\n"
	.string "いっ　いまのは　ひとりごと　だぞ！$"

LilycoveCity_Text_ChanceToDoBigThings: @ 0x081E0CAE
	.string "リーダーが　なに　かんがえてるのか\n"
	.string "したっぱの　オレには　わからんが\p"
	.string "アクアだんに　いると\n"
	.string "すごいこと　できそうだぜ！\p"
	.string "なっ　なんだ　おまえ！\n"
	.string "いっ　いまのは　ひとりごと　だぞ！$"

LilycoveCity_Text_DontGoNearCaveInCove: @ 0x081E0D08
	.string "おい　おまえ！\p"
	.string "いりえに　ある\n"
	.string "どうくつには　ちかづくなよ！\p"
	.string "なぜって？　りゆうは　どうでも　いいんだ！\n"
	.string "おとなの　いうこと　きけよな！！$"

LilycoveCity_Text_IfWorldBecomesOurs: @ 0x081E0D4E
	.string "この　ひろい　せかい　すべてが\n"
	.string "おれら　アクアだんの　ものに　なったら\l"
	.string "ポケモンも　しあわせに　なれるはずだ！$"

LilycoveCity_Text_WailmerLeapOutOfWater: @ 0x081E0D86
	.string "それっ！　ホエルコ！\n"
	.string "そこで　すいめんから　ジャンプするのだ！$"

LilycoveCity_Text_GetLostMessingUpTraining: @ 0x081E0DA6
	.string "⋯⋯ん？　なんだ　おまえは？\p"
	.string "トレーニングの　じゃまに　なるから\n"
	.string "あっちに　いっててくれ！$"

LilycoveCity_Text_ContestHallInTown: @ 0x081E0DD4
	.string "この　まちに　ポケモンコンテストの\n"
	.string "かいじょうが　あるんだな！\p"
	.string "ということは　よく　そだった　ポケモンが\n"
	.string "いっぱい　あつまって　いるんだな！\p"
	.string "わしの　ハートは　わくわく　なんだな！$"

LilycoveCity_Text_StrangeCaveInCove: @ 0x081E0E2F
	.string "まちの　はずれの　いりえに\n"
	.string "おかしな　どうくつが　あるの　みた？$"

LilycoveCity_Text_GoingToMoveDeleterForHMs: @ 0x081E0E50
	.string "あたしの　ポケモン\n"
	.string "コンテストの　ために　あたらしい　わざを\l"
	.string "おぼえさせる　つもりなの！\p"
	.string "だからね　わざわすれ　じいさんに　たのんで\n"
	.string "ひでんわざを　わすれさせて　もらうのよ！$"

LilycoveCity_Text_ImFromKanto: @ 0x081E0EA8
	.string "ぼくは　カントーから　きました！\p"
	.string "ホウエン　ちほうは　みずと　みどりに\n"
	.string "あふれた　うつくしい　ところ　ですね！\p"
	.string "⋯⋯ん？　ということは？\p"
	.string "この　とち　だけに　せいそくする\n"
	.string "めずらしい　ポケモンが　いるのかも？$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer: @ 0x081E0F11
	.string "アクアだんの　れんちゅうが\n"
	.string "いりえで　ホエルコを\l"
	.string "トレーニング　してるんだよ！\p"
	.string "おいらたち　ふなのり\n"
	.string "このままじゃ　うみに　でられないよ！$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut: @ 0x081E0F57
	.string "あんた　しってるかい？\p"
	.string "だれかが　アクアだんを\n"
	.string "けちらしてくれた　らしいんだ！\p"
	.string "おかげで　ホエルコ　いなくなって\n"
	.string "うみに　でられるように　なったよ！$"

LilycoveCity_Text_SomeoneStoleMyPokemon: @ 0x081E0FA2
	.string "うみべの　やどで　なみの　おとを\n"
	.string "ききながら　のんびり　おひるね\l"
	.string "⋯⋯を　していたら\p"
	.string "わたしの　ポケモン　とられちゃった！\p"
	.string "はんにんは　だれー！？\n"
	.string "アクアだん？　アクアだん　なのー！？$"

LilycoveCity_Text_MissingPokemonCameBack: @ 0x081E0FFF
	.string "いなくなってた　わたしの　ポケモン\n"
	.string "いつのまにか　かえってきたの！$"

LilycoveCity_Text_ImArtDealer: @ 0x081E1021
	.string "わたしは　ガショウ　です！\p"
	.string "いや　そういう　なまえ　なのではなく\n"
	.string "かちのある　えを　かったり　うったりする\l"
	.string "しょくぎょうの　なまえ　なんです！\p"
	.string "このまちの　びじゅつかんに　すばらしい\n"
	.string "めいが　が　あると　きいたの　ですが⋯⋯$"

LilycoveCity_Text_SeaRemainsForeverYoung: @ 0x081E1092
	.string "わしらが　しわくちゃに　なっても\n"
	.string "このうみは　いつまでも　わかわかしく\l"
	.string "いのちの　かがやきに　あふれとる\p"
	.string "ふほほ　ふほほほほ⋯⋯$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed: @ 0x081E10D3
	.string "60ねんまえ　ここで　おじいしゃんが\n"
	.string "わしに　プロポーズ　してくれた　ときから\l"
	.string "このうみは　うつくしいまま　ですのじゃ\p"
	.string "むふふ　むふふふふ⋯⋯$"

LilycoveCity_Text_TeamAquaRenovatedCavern: @ 0x081E111B
	.string "この　いりえの　ところに　おかしな\n"
	.string "どうくつの　いりぐちが　ある　じゃろう？\p"
	.string "いぜんは　てんねんの　どうくつ　だったが\n"
	.string "アクアだん　とかいう　れんちゅうが\l"
	.string "かいぞうして　あんなふうに　したんじゃ！\p"
	.string "‘しぜんを　あいする　アクアだん！’\n"
	.string "⋯⋯と　いっておるが\p"
	.string "いうことと　やることが　ちがっとる！$"

LilycoveCity_Text_TeamAquaLotGoneForGood: @ 0x081E11AF
	.string "いりえに　あった　どうくつ⋯⋯\n"
	.string "いつのまにやら　カラッポに　なっておる\p"
	.string "アクアだんの　れんちゅう\n"
	.string "どこかへ　いって　しまったらしい　のう$"

LilycoveCity_Text_CitySign: @ 0x081E11F4
	.string "ここは　ミナモ　シティ\n"
	.string "りくちの　さいはて　うみの　はじまり$"

LilycoveCity_Text_ContestHallSign: @ 0x081E1213
	.string "ポケモンコンテスト　かいじょう\n"
	.string "あつまれ！　ポケモン　トレーナー$"

LilycoveCity_Text_MotelSign: @ 0x081E1234
	.string "‘みんしゅく　モナミ’\n"
	.string "ミナモのモナミ　と　おぼえて　ください$"

LilycoveCity_Text_MuseumSign: @ 0x081E1254
	.string "‘ミナモ　びじゅつかん’\n"
	.string "ポケモン　めいがてん　かいさい　ちゅう！$"

LilycoveCity_Text_MuseumSignPlayersExhibit: @ 0x081E1276
	.string "‘ミナモ　びじゅつかん’\p"
	.string "{PLAYER}の　ポケモン　コレクション\n"
	.string "かいさい　ちゅう！$"

LilycoveCity_Text_HarborSignUnderConstruction: @ 0x081E129D
	.string "‘ミナモ　シティ　ふねのりば’\p"
	.string "れんらくせん　タイドリップごう　は\n"
	.string "カイナシティにて　けんぞう　ちゅう！\p"
	.string "もう　しばらく　おまちください！$"

LilycoveCity_Text_HarborSign: @ 0x081E12E3
	.string "‘ミナモ　シティ　ふねのりば’\p"
	.string "れんらくせん　タイドリップごうで\n"
	.string "ふねの　たびを　おたのしみ　ください！$"

LilycoveCity_Text_TrainerFanClubSign: @ 0x081E1318
	.string "‘ポケモン　トレーナー　ファンクラブ’\p"
	.string "かんばんに　いろんな　トレーナーの\n"
	.string "なまえが　らくがき　されている⋯⋯$"

LilycoveCity_Text_DepartmentStoreSign: @ 0x081E1350
	.string "‘ミナモ　デパート’\p"
	.string "グッズ　いっぱい！　ドキドキ　いっぱい！\n"
	.string "なにかが　みつかる　すてきな　ところ$"

LilycoveCity_Text_MoveDeletersHouseSign: @ 0x081E1383
	.string "‘わざわすれ　じいさんの　いえ’\n"
	.string "ポケモンの　わざ　わすれさせます$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender: @ 0x081E13A5
	.string "きのみブレンダー　っていう\n"
	.string "マシンを　しってるかい？$"

LilycoveCity_Text_FasterSpinBetterPokeblocks: @ 0x081E13C0
	.string "みんなで　こうそくで　まわし　まくるんだ\p"
	.string "すっげー　はやいと\n"
	.string "すっげー　いいポロックが　できるらしいぜ！$"

LilycoveCity_Text_ExplainBerryBlender: @ 0x081E13F5
	.string "ポロックっていう　おかしが　できるんだぜ\p"
	.string "いいポロックを　つくると　ポケモンの\n"
	.string "コンディションも　ぐーんと　アップさ！$"

LilycoveCity_Text_HeardTowerCalledSkyPillar: @ 0x081E1431
	.string "あのな　どこかの　すいどうに\n"
	.string "そらのはしら　とかいう　とうが\l"
	.string "たってる　らしいぜ$"

LilycoveCity_Text_SawTallTowerOnRoute131: @ 0x081E145A
	.string "オレな　131ばん　すいどうの　あたりで\n"
	.string "たかーい　とうを　みたんだけど\l"
	.string "もしかして　それって⋯⋯？$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon: @ 0x081E148D
	.string "ぼくら　しんこん　りょこうで\n"
	.string "このまちに　きたばかり　なんだけど\p"
	.string "ドラゴンタイプの　ポケモンが\n"
	.string "そらを　とんで　いくのを　みたんだよ！\p"
	.string "ホウエン　ちほうには\n"
	.string "あんな　かっこいい　ポケモンが\l"
	.string "せいそく　してるのかい？$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon: @ 0x081E14F9
	.string "わたしたちの　しんこん　りょこうは\n"
	.string "かくちの　めずらしい　ポケモンを\l"
	.string "できるだけ　たくさん　みること　なんです\p"
	.string "この　まちに　とうちゃく　したら\n"
	.string "いきなり　めずらしい　ポケモンが　みられて\l"
	.string "とても　ハッピー　だわ！$"
