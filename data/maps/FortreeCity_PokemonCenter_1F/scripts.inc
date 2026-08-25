@ FortreeCity_PokemonCenter_1F scripts (JP map g12 m2 @ 0x08204C5D)

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

	.globl FortreeCity_PokemonCenter_1F_EventScript_00204C6C
FortreeCity_PokemonCenter_1F_EventScript_00204C6C: @ 0x08204C6C
FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

	.globl FortreeCity_PokemonCenter_1F_EventScript_00204C7A
FortreeCity_PokemonCenter_1F_EventScript_00204C7A: @ 0x08204C7A
FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

	.globl FortreeCity_PokemonCenter_1F_EventScript_00204C83
FortreeCity_PokemonCenter_1F_EventScript_00204C83: @ 0x08204C83
FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

	.globl FortreeCity_PokemonCenter_1F_EventScript_00204C8C
FortreeCity_PokemonCenter_1F_EventScript_00204C8C: @ 0x08204C8C
FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone: @ 0x08204C95
	.string "きみぃ\n"
	.string "ポケモンずかん　つくっておるのか？\p"
	.string "ふむぅ　121ばん　どうろの\n"
	.string "サファリゾーンに　いっては　どうかな？$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat: @ 0x08204CCE
	.string "レコードコーナー　つかってるかい？\p"
	.string "レコードって　きろくの　ことだろ\n"
	.string "きろくが　いろいろ　まざるって⋯⋯\p"
	.string "よく　わかんないけど　すごいよな！\n"
	.string "ワクワク　しちゃうよ！$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav: @ 0x08204D21
	.string "おっ　ポケナビ　もってるな！\n"
	.string "おれと　おんなじ　だ\p"
	.string "ポケナビの　エントリーコール　つかうと\n"
	.string "もういちど　しょうぶ　したがってる\l"
	.string "トレーナーが　わかったり\l"
	.string "いつでも　はなしが　できるってのが\l"
	.string "すぐれもの　だよな！　さすが　デボンだぜ！$"
