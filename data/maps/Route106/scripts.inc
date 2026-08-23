@ Route106 scripts (JP map g0 m21 @ 0x081E83CA)

Route106_MapScripts::
	.byte 0

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_DOUGLAS, 0x0, 0x0825A72C, 0x0825A754
	msgbox 0x0825A75E, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_KYLA, 0x0, 0x0825A775, 0x0825A797
	msgbox 0x0825A7AB, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELLIOT_1, 0x0, 0x0825A5D9, 0x0825A5F1, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, 0x1, Route106_EventScript_ElliotRematch
	msgbox 0x0825A60D, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox 0x0825A631, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0x153
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 0x153
	callstd 0x8
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle TRAINER_BATTLE_REMATCH, TRAINER_ELLIOT_1, 0x0, 0x0825A657, 0x0825A679
	msgbox 0x0825A68A, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_NED, 0x0, 0x0825A6B0, 0x0825A6F8
	msgbox 0x0825A714, MSGBOX_AUTOCLOSE
	end

Route106_Text_TrainerTips: @ 0x081E847B
	.string "おとくな　けいじばん！！\p"
	.string "ポケモンを　うまく　つりあげる　コツは\n"
	.string "ビックリ　したら　Aボタン！$"
