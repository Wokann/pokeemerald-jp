@ Route107 scripts (JP map g0 m22 @ 0x081E84AB)

Route107_MapScripts::
	.byte 0

Route107_EventScript_Darrin::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_DARRIN, 0x0, 0x0825A7CD, 0x0825A7F7
	msgbox 0x0825A80B, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Tony::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_TONY_1, 0x0, 0x0825A835, 0x0825A854, Route107_EventScript_TonyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, 0x1, Route107_EventScript_TonyRematch
	msgbox 0x0825A86A, MSGBOX_DEFAULT
	release
	end

Route107_EventScript_TonyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox 0x0825A89D, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0x9B
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 0x9B
	callstd 0x8
	release
	end

Route107_EventScript_TonyRematch::
	trainerbattle TRAINER_BATTLE_REMATCH, TRAINER_TONY_1, 0x0, 0x0825A8BB, 0x0825A8E1
	msgbox 0x0825A909, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Denise::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_DENISE, 0x0, 0x0825A945, 0x0825A95F
	msgbox 0x0825A967, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Beth::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_BETH, 0x0, 0x0825A98C, 0x0825A9B0
	msgbox 0x0825A9C4, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Lisa::
	trainerbattle TRAINER_BATTLE_DOUBLE, TRAINER_LISA_AND_RAY, 0x0, 0x0825A9E5, 0x0825AA08, 0x0825AA4B
	msgbox 0x0825AA20, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Ray::
	trainerbattle TRAINER_BATTLE_DOUBLE, TRAINER_LISA_AND_RAY, 0x0, 0x0825AA6E, 0x0825AAAE, 0x0825AAF5
	msgbox 0x0825AAC7, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Camron::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_CAMRON, 0x0, 0x0825AB15, 0x0825AB36
	msgbox 0x0825AB45, MSGBOX_AUTOCLOSE
	end
