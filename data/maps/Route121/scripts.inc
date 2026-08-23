@ Route121 scripts (JP map g0 m36 @ 0x081EE0D9)

Route121_MapScripts::
	.byte 0

Route121_EventScript_001EE0DA::
	loadword 0x0, Route121_Text_AheadLoomsMtPyre
	callstd 0x2
	end

Route121_EventScript_001EE0E3::
	loadword 0x0, Route121_Text_MtPyrePierSign
	callstd 0x3
	end

Route121_EventScript_001EE0EC::
	loadword 0x0, Route121_Text_SafariZoneSign
	callstd 0x3
	end

Route121_EventScript_001EE0F5::
	lockall
	playbgm 0x1A3, 0x0
	applymovement 0xD, 0x0824363B
	waitmovement 0x0
	loadword 0x0, Route121_Text_OkayMoveOutToMtPyre
	callstd 0x4
	closemessage
	applymovement 0xC, 0x081EE136
	applymovement 0xD, 0x081EE13F
	applymovement 0xE, 0x081EE148
	waitmovement 0x0
	fadedefaultbgm
	removeobject 0xC
	removeobject 0xD
	removeobject 0xE
	setvar 0x4074, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1ee136, 0x201

Route121_Text_OkayMoveOutToMtPyre::
	.string "よし！\n"
	.string "おれたちも　おくりびやまに　むかうぞ！$"

Route121_Text_AheadLoomsMtPyre::
	.string "このさきに　あるのは　おくりびやま⋯⋯\p"
	.string "じゅみょうを　おえた　ポケモンたちの\n"
	.string "たましいが　まつられる　ところ⋯⋯$"

Route121_Text_MtPyrePierSign::
	.string "おくりびやま　さんばし\p"
	.string "⋯⋯ながい　あいだ　つかわれて　いないのか\n"
	.string "もじが　きえそうに　なっている$"

Route121_Text_SafariZoneSign::
	.string "めずらしい　ポケモン　たくさん！\n"
	.string "‘サファリゾーン’$"
