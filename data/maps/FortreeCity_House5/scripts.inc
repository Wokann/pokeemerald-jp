@ FortreeCity_House5 scripts (JP map g12 m8 @ 0x08205343)

FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	@ JP uses the waitdooranim opcode (0xC5) where US uses waitmoncry.
	waitmoncry_jp
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat: @ 0x08205369
	.string "ヒワマキの　ツリーハウスって　さいこう！\n"
	.string "ポケモンと　いっしょに　くらすなら\l"
	.string "いちばんの　まちだと　おもっているわ！$"

FortreeCity_House5_Text_AdaptedToNature: @ 0x082053A4
	.string "ポケモンも　ひとも\n"
	.string "しぜんに　あわせて　くらしてきたからな\p"
	.string "いまさら　じぶんらの　つごうに\n"
	.string "しぜんを　あわせなくて　いいんだよ$"

FortreeCity_House5_Text_Zigzagoon: @ 0x082053E4
	.string "ジグザグマ“ぶふう！！$"
