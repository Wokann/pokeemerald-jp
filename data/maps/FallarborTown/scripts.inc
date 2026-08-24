@ FallarborTown scripts (JP map g0 m13 @ 0x081E5E63)

FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal:
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	@ JP opcode 0xC5 is a cry wait at this site; US uses SCR_OP_WAITMONCRY.
	waitmoncry_jp
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "なんだ　なんだ！？\p"
	.string "ソライシはかせの　いえに\n"
	.string "あやしげな　じんぶつが\l"
	.string "ではいり　しておった　ようだが⋯⋯$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "ここいら　いったいは\n"
	.string "むかしから　いんせきが　おおくてな\p"
	.string "りゅうせいのたきも　いんせきが　おちて\n"
	.string "できたとか　そう　いわれておる$"

FallarborTown_Text_MyPreciousAzurill:
	.string "ほら！　みてちょうだい！\n"
	.string "わたしの　たいせつな　ルリリ！\p"
	.string "ツヤツヤの　ナデナデの　フカフカよ！$"

FallarborTown_Text_Azurill:
	.string "ルリリ“るーりーるー$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "フエンタウンの　ジムリーダー\n"
	.string "アスナとは　たたかったかね？\p"
	.string "あのこの　おじいさんは　すごかったよ\n"
	.string "なんでも　ポケモンリーグの\l"
	.string "してんのう　だった　らしいからね\p"
	.string "きっと　アスナも　これから\n"
	.string "すばらしい　トレーナーに　なるだろうね$"

FallarborTown_Text_BattleTentSign:
	.string "バトルテント　ハジツゲタウン　かいじょう\n"
	.string "つどえ！　さいきょう　チーム$"

FallarborTown_Text_TownSign:
	.string "ここは　ハジツゲ　タウン\n"
	.string "ちいさな　はたけが　ある　のうそん$"

FallarborTown_Text_MoveTutorSign:
	.string "‘わざおしえマニアの　いえ’\n"
	.string "ポケモンの　わざ　おしえます！$"
