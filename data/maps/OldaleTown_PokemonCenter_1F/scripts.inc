@ OldaleTown_PokemonCenter_1F scripts (JP map g2 m2 @ 0x081F29A2)

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:: @ 0x081F29AD
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse:: @ 0x081F29B6
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman:: @ 0x081F29C4
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy:: @ 0x081F29CD
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl:: @ 0x081F29D6
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable:: @ 0x081F29EB
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC: @ 0x081F29F5
	.string "すみっこに　おいてある　パソコンは\n"
	.string "ポケモントレーナーの　ための　ものなんだ\p"
	.string "きみも　じゆうに　つかって　いいんだよ！$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat: @ 0x081F2A31
	.string "ポケモンセンターって　すごいよな！\p"
	.string "ポケモン　なんびき　あずけても\n"
	.string "おかねが　かからないから\l"
	.string "どんな　ときでも　あんしん　だよね！$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable: @ 0x081F2A73
	.string "2かいの　ポケモン　ワイヤレス　クラブは\n"
	.string "つい　さいきん　できたの\p"
	.string "でも　まだ\n"
	.string "ちょうせいちゅう　ですって$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub: @ 0x081F2AA9
	.string "2かいの　ポケモン　ワイヤレス　クラブは\n"
	.string "つい　さいきん　できたの\p"
	.string "あたし　さっそく\n"
	.string "ポケモンこうかん　しちゃった！$"
