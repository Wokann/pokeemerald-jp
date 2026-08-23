@ Route108 scripts (JP map g0 m23 @ 0x081E85A0)

Route108_MapScripts::
	.byte 0

Route108_EventScript_Jerome::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_JEROME, 0x0, 0x0825AB71, 0x0825AB93
	msgbox 0x0825ABAB, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Matthew::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_MATTHEW, 0x0, 0x0825ABCF, 0x0825ABEB
	msgbox 0x0825ABFF, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Tara::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_TARA, 0x0, 0x0825AC1E, 0x0825AC43
	msgbox 0x0825AC4F, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Missy::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_MISSY, 0x0, 0x0825AC75, 0x0825AC96
	msgbox 0x0825ACAE, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Carolina::
	trainerbattle TRAINER_BATTLE_SINGLE, TRAINER_CAROLINA, 0x0, 0x0825AD8F, 0x0825ADAB
	msgbox 0x0825ADB8, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Cory::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_CORY_1, 0x0, 0x0825ACCB, 0x0825ACED, Route108_EventScript_CoryRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, 0x1, Route108_EventScript_CoryRematch
	msgbox 0x0825ACFC, MSGBOX_DEFAULT
	release
	end

Route108_EventScript_CoryRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	msgbox 0x0825AD14, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0x2E4
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, 0x2E4
	callstd 0x8
	release
	end

Route108_EventScript_CoryRematch::
	trainerbattle TRAINER_BATTLE_REMATCH, TRAINER_CORY_1, 0x0, 0x0825AD3A, 0x0825AD58
	msgbox 0x0825AD6B, MSGBOX_AUTOCLOSE
	end
