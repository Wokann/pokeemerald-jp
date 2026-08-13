@ PetalburgCity_WallysHouse scripts (JP map g8 m0 @ 0x081F810B)

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_MapScriptTable_001F8129
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_MapScriptTable_001F8116
	.byte 0

PetalburgCity_WallysHouse_MapScriptTable_001F8116::
	map_script_2 0x4057, 0x4, PetalburgCity_WallysHouse_EventScript_001F8120
	.2byte 0

PetalburgCity_WallysHouse_EventScript_001F8120::
	turnobject 0xFF, 0x4
	turnobject 0x1, 0x3
	end

PetalburgCity_WallysHouse_MapScriptTable_001F8129::
	map_script_2 0x4057, 0x4, PetalburgCity_WallysHouse_EventScript_001F8133
	.2byte 0

PetalburgCity_WallysHouse_EventScript_001F8133::
	lockall
	loadword 0x0, gJPText_001F82AE
	callstd 0x4
	setorcopyvar 0x8000, 0x155
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x7A
	loadword 0x0, gJPText_001F83BA
	callstd 0x4
	setvar 0x4057, 0x5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_001F815A::
	lock
	faceplayer
	checkflag 0x7E
	goto_if 0x1, PetalburgCity_WallysHouse_EventScript_001F818E
	checkflag 0x7A
	goto_if 0x1, PetalburgCity_WallysHouse_EventScript_001F8184
	checkflag 0x87
	goto_if 0x1, PetalburgCity_WallysHouse_EventScript_001F8198
	loadword 0x0, 0x081F81C1
	callstd 0x4
	setflag 0x87
	release
	end

PetalburgCity_WallysHouse_EventScript_001F8184::
	loadword 0x0, 0x081F83E2
	callstd 0x4
	release
	end

PetalburgCity_WallysHouse_EventScript_001F818E::
	loadword 0x0, 0x081F8400
	callstd 0x4
	release
	end

PetalburgCity_WallysHouse_EventScript_001F8198::
	loadword 0x0, 0x081F829E
	callstd 0x4
	release
	end

PetalburgCity_WallysHouse_EventScript_001F81A2::
	lock
	faceplayer
	checkflag 0x7A
	goto_if 0x1, PetalburgCity_WallysHouse_EventScript_001F81B7
	loadword 0x0, 0x081F8465
	callstd 0x4
	release
	end

PetalburgCity_WallysHouse_EventScript_001F81B7::
	loadword 0x0, 0x081F849F
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1f81c1, 0xed
	.globl gJPText_001F82AE
gJPText_001F82AE: @ 0x081F82AE
	.string "{MUS_RG_VS_TRAINER}{B_PLAYER_MON1_NAME}！\n"
	.string "むりに　よびだして　すまなかったね！\p"
	.string "ミツルは　シダケタウンに　いってから\n"
	.string "すっかり　げんきを　とりもどしたよ！\p"
	.string "それも　みんな　きみの　おかげさ！\p"
	.string "なにしろ　このまちを　でるときに\n"
	.string "ミツルが　ポケモンを　つかまえるのを\l"
	.string "てつだって　くれただろう？\p"
	.string "あのときの　ことが　ミツルは　とっても\n"
	.string "うれしかった　らしいんだ！\p"
	.string "いや　ミツル　だけじゃない\n"
	.string "ちちおやの　わたしも　うれしいよ！\p"
	.string "あのこに　きみの　ような\n"
	.string "やさしい　ともだちが　できたことが　ね！\p"
	.string "そのおれい　という　わけでは　ないけど\n"
	.string "これを　うけとって　くれないか！$"

	.globl gJPText_001F83BA
gJPText_001F83BA: @ 0x081F83BA
	.string "なみのりを　つかえるように　なれば\n"
	.string "いろんな　ばしょに　いけるように　なるよ！$"

	.incbin "baserom_jp.gba", 0x1f83e2, 0x13e
