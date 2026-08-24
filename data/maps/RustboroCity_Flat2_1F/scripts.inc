@ RustboroCity_Flat2_1F scripts (JP map g11 m13 @ 0x08203F99)

RustboroCity_Flat2_1F_MapScripts::
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman::
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	@ JP uses the waitdooranim opcode (0xC5) where US uses waitmoncry.
	waitmoncry_jp
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere: @ 0x08203FB6
	.string "ここには　デボン　コーポレーションの\n"
	.string "しゃいんの　みなさんが　すんでるのですよ$"

RustboroCity_Flat2_1F_Text_Skitty: @ 0x08203FDE
	.string "エネコ“ぎゃー！！$"

	@ Rustboro City Flat2 2F and later unstructured script owners begin here.
	.incbin "baserom_jp.gba", 0x203fe8, 0x3b6
