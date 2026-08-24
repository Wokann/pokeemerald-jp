@ FortreeCity_House3 scripts (JP map g12 m6 @ 0x082050D0)

FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Maniac::
	msgbox FortreeCity_House3_Text_MetStevenHadAmazingPokemon, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_SchoolKidM::
	msgbox FortreeCity_House3_Text_OhYouHavePokedex, MSGBOX_NPC
	end

FortreeCity_House3_Text_MetStevenHadAmazingPokemon: @ 0x082050E3
	.string "ポケモンずかんで\n"
	.string "おもいだした　ことが　あるよ\p"
	.string "めずらしい　いしを　さがしてるとき\n"
	.string "ダイゴって　トレーナーと　であったけど\l"
	.string "あいつの　ポケモン　すごいね！\p"
	.string "めずらしい　だけでなく\n"
	.string "おそろしいほど　きたえられてた！\p"
	.string "もしかしたら　この　まちの\n"
	.string "ジムリーダーよりも　つよいかも⋯⋯$"

FortreeCity_House3_Text_OhYouHavePokedex: @ 0x0820516E
	.string "きみの　もっている　それ　なに？\p"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "へー　ポケモンずかん　っていうんだ？\n"
	.string "すごいねえ！$"
