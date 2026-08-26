@ PacifidlogTown_House1 scripts (JP map g7 m2 @ 0x081F793E)

PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man:: @ 0x081F793F
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman:: @ 0x081F7948
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory: @ 0x081F7951
	.string "ホウエンちほう　には\n"
	.string "いわ⋯⋯　こおり⋯⋯　はがね⋯⋯\p"
	.string "それぞれの　ちからを　つかさどる\n"
	.string "3びきの　ポケモンが\l"
	.string "それぞれ　どこかの　どうくつに　いる⋯⋯\p"
	.string "おれ　ちいさな　ころに\n"
	.string "そんな　はなしを　きいたことが　あるよ$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors: @ 0x081F79BE
	.string "‘むっつの　てんが\n"
	.string "　みっつの　とびらを　あける’\p"
	.string "おじいちゃんが　よく　いっていたけど\n"
	.string "いまだに　なんのことだか　わからないわ$"
