@ AquaHideout_B1F scripts (JP map g24 m24 @ 0x08217CB0)

AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnResume:: @ 0x08217CBB
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode:: @ 0x08217CC5
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition:: @ 0x08217CD9
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
	end

AquaHideout_B1F_EventScript_ShowElectrode1:: @ 0x08217CEC
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	return

AquaHideout_B1F_EventScript_ShowElectrode2:: @ 0x08217CF0
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	return

AquaHideout_B1F_EventScript_Electrode1:: @ 0x08217CF4
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 0x1E
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 0x28
	waitmoncry_jp
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode1:: @ 0x08217D38
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Electrode2:: @ 0x08217D41
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 0x1E
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 0x28
	waitmoncry_jp
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode2:: @ 0x08217D85
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Grunt2:: @ 0x08217D8E
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt2Defeated:: @ 0x08217DA9
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3:: @ 0x08217DB9
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt3Defeated:: @ 0x08217DD4
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5:: @ 0x08217DDE
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt7:: @ 0x08217DF5
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_7, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_Grunt2Intro: @ 0x08217E0C
	.string "アジトの　ひみつを　しりたけりゃ\n"
	.string "おれを　たおす　ことだな！$"

AquaHideout_B1F_Text_Grunt2Defeat: @ 0x08217E2B
	.string "ぜんぜん　かてません⋯⋯！$"

AquaHideout_B1F_Text_Grunt2PostBattle: @ 0x08217E39
	.string "アジトの　ひみつ？\p"
	.string "それはな⋯⋯　いちばん　おくに\n"
	.string "せんすいていが　あるって　ことよ！\p"
	.string "だが　いまごろは　いひひひ⋯⋯！$"

AquaHideout_B1F_Text_Grunt3Intro: @ 0x08217E76
	.string "ねんりょうの　ほきゅう　オッケイ！\n"
	.string "おやつも　ほきゅう　オッケイ！\p"
	.string "あとは　ジャマものを　ぶっとばす　だけ！$"

AquaHideout_B1F_Text_Grunt3Defeat: @ 0x08217EAD
	.string "こっぴどく　やられたーっ！$"

AquaHideout_B1F_Text_Grunt3PostBattle: @ 0x08217EBB
	.string "ふん！　これで　いいんだ\p"
	.string "おまえの　ジャマをする　というのが\n"
	.string "おれの　にんむ　だったのさ$"

AquaHideout_B1F_Text_Grunt5Intro: @ 0x08217EE8
	.string "はーあ　アジトで　るすばんも\n"
	.string "たいくつ　だから　あいて　してあげるわー$"

AquaHideout_B1F_Text_Grunt5Defeat: @ 0x08217F0C
	.string "はーあ　まけたわー$"

AquaHideout_B1F_Text_Grunt5PostBattle: @ 0x08217F16
	.string "あんまり　うろちょろ　してると\n"
	.string "ほかの　アクアだんに　やられるかもよー$"

AquaHideout_B1F_Text_Grunt7Intro: @ 0x08217F3A
	.string "ちょっと　そこの　あんた！\p"
	.string "アクアだんと　マグマだんの　ユニフォーム\n"
	.string "どっちが　かっこいいと　おもう？$"

AquaHideout_B1F_Text_Grunt7Defeat: @ 0x08217F6E
	.string "かっこよく　まけたわ⋯⋯$"

AquaHideout_B1F_Text_Grunt7PostBattle: @ 0x08217F7B
	.string "ユニフォームが　かっこいいと\n"
	.string "しょうぶに　まけても　えになる　でしょ？$"
