@ VerdanturfTown scripts (JP map g0 m14 @ 0x081E6059)

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen:
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen:
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "わたしの　パパが　いってたの\p"
	.string "この　トンネルって　おーきな　おとに\n"
	.string "はんのうして　さわぎだす　おくびょうな\l"
	.string "ポケモンが　いっぱい　なんだって！\p"
	.string "だから　かいはつ　こうじ　やめたんだけど\n"
	.string "おとこの　ひとが　ひとりで\l"
	.string "トンネルを　ほろうと　してるんだって！$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "あいする　ひとの　ために\n"
	.string "どうくつを　ほっていた　ひとが　いるの！\p"
	.string "なんだか　すごーい！$"

VerdanturfTown_Text_AirCleanHere:
	.string "かざむきの　かんけいで　このまち　には\n"
	.string "かざんばいが　とんでくることは　ない！\p"
	.string "くうきの　おいしい　このまちで　くらせば\n"
	.string "からだが　じょうぶでない　ひとでも\l"
	.string "きっと　げんきに　なれる　はずさ！$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "ぼくと　ぼくの　ポケモン\n"
	.string "さいきん　すごく　ちょうしが　よくてね\p"
	.string "バトルテント　デビュー　させたくて\n"
	.string "この　まちに　きたんだ！$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "フレンドリィ　ショップの　となりに\n"
	.string "どうくつが　あるだろ？\p"
	.string "なかを　ふさいでいる　いわを　こわし\n"
	.string "とおれるように　しようと　がんばっている\l"
	.string "やつが　いるらしいんだ！\p"
	.string "とおれるように　なると　いいのに⋯⋯\n"
	.string "カナズミにも　いきやすく　なるから！$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "フレンドリィ　ショップの　となりの\n"
	.string "どうくつが　とおれるように　なっただろ！\p"
	.string "カナズミまで　デボンの　しんせいひんを\n"
	.string "かいに　いきやすくなって　うれしいよ！$"

VerdanturfTown_Text_TownSign:
	.string "ここは　シダケ　タウン\n"
	.string "くさの　においの　かぜふく　こうげん$"

VerdanturfTown_Text_WandasHouse:
	.string "‘ミチルの　いえ’$"

VerdanturfTown_Text_BattleTentSign:
	.string "バトルテント　シダケタウン　かいじょう\n"
	.string "みまもれ！　ポケモンバトル$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "カナズミと　シダケを　むすぶ\n"
	.string "‘カナシダ　トンネル’\p"
	.string "かいつう　こうじは　ちゅうしに　なりました$"
