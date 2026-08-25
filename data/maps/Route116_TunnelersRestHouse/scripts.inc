@ Route116_TunnelersRestHouse scripts (JP map g21 m0 @ 0x08212820)

Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:: @ 0x08212826
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1:: @ 0x0821282A
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2:: @ 0x08212833
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3:: @ 0x0821283C
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened:: @ 0x08212851
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring: @ 0x0821285B
	.string "あの　カナシダトンネル⋯⋯\p"
	.string "はじめは　たくさんの　にんげんと\n"
	.string "さいしんの　キカイで　ほりすすんでいた\p"
	.string "だが　そのまま　ほりすすむと\n"
	.string "あたりの　ポケモンに\l"
	.string "あくえいきょうを　あたえる　らしくてね\p"
	.string "で　おれら　どうしようもなく\n"
	.string "ここで　ぼんやりと　しているわけさ$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf: @ 0x082128DD
	.string "どうしても　シダケに　いきたい\n"
	.string "やつが　じぶんの　ちから　だけで\l"
	.string "トンネルを　ほっているよ\p"
	.string "にんげんの　ちからで　すこしずつ　ほれば\n"
	.string "ポケモンを　おどろかせなくて　すむし\l"
	.string "まわりの　しぜんにも　わるい　えいきょうを\l"
	.string "あたえないで　すむって　いってな$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel: @ 0x0821295A
	.string "トンネルを　つかわずに　ここから\n"
	.string "シダケに　いくなら　うみを　わたり\l"
	.string "ムロから　カイナ　そして\l"
	.string "キンセツを　とおって　いくしか　ないな！$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough: @ 0x0821299F
	.string "なんでも　シダケ　までの\n"
	.string "トンネルが　つうじた　らしいぞ！\p"
	.string "ねがい　つづければ\n"
	.string "いつかは　かなう　って　ことなんだな！$"
