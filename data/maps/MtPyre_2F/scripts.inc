@ MtPyre_2F scripts (JP map g24 m16 @ 0x08216230)

MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:: @ 0x08216240
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman:: @ 0x0821624B
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM:: @ 0x08216254
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark:: @ 0x0821625D
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke:: @ 0x08216274
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez:: @ 0x0821628F
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah:: @ 0x082162AA
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander:: @ 0x082162C1
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty: @ 0x082162D8
	.string "かわいかった　エネコとの　おもいで⋯⋯\n"
	.string "おもいだすだけで　なみだが　あふれる⋯⋯$"

MtPyre_2F_Text_TumbledFromFloorAbove: @ 0x08216301
	.string "アイタタタ⋯⋯　ゆかの　そこかしこに\n"
	.string "あなが　あいているのに　きづかないで\l"
	.string "おじさん　うえから　おちてしまったよ$"

MtPyre_2F_Text_MarkIntro: @ 0x0821633A
	.string "おまえも　ポケモン　さがしに　きたのか？\n"
	.string "あとから　きた　くせに　なまいきだ！$"

MtPyre_2F_Text_MarkDefeat: @ 0x08216362
	.string "ふええええええっ！\n"
	.string "ゆるして　くださいーっ！$"

MtPyre_2F_Text_MarkPostBattle: @ 0x08216379
	.string "めったに　ひとが　はいらない　やま　だから\n"
	.string "めずらしい　ポケモンが　いると　おもってさ$"

MtPyre_2F_Text_LukeIntro: @ 0x082163A5
	.string "テル“きもだめし　するんだ！\n"
	.string "ぼくの　かっこいい　ところ　みれば\l"
	.string "かのじょ　もっと　ほれるからね！\p"
	.string "そうだ！　きみを　たおして\n"
	.string "かっこいい　ところ　みせちゃおう！$"

MtPyre_2F_Text_LukeDefeat: @ 0x082163F7
	.string "テル“あっちゃー$"

MtPyre_2F_Text_LukePostBattle: @ 0x08216400
	.string "テル“まけちゃったけど　だいじょうぶ！\n"
	.string "ぼくが　いるからさ\l"
	.string "きもだめし　なんて　へっちゃら　だよ！$"

MtPyre_2F_Text_LukeNotEnoughMons: @ 0x08216432
	.string "テル“ぼくと　しょうぶ　するなら\n"
	.string "もっと　ポケモン　つれてきなよ！\p"
	.string "そうでないと　かのじょの　まえで\n"
	.string "いいところ　みせられない　じゃないか！$"

MtPyre_2F_Text_DezIntro: @ 0x08216479
	.string "マコ“かれしと　きもだめしに　きたの\n"
	.string "すっごく　こわいけど\l"
	.string "かれしが　いるから　だいじょうぶ！\p"
	.string "そうだ！　あなたを　たおす\n"
	.string "かれしの　かっこいい　ところ　みせて！$"

MtPyre_2F_Text_DezDefeat: @ 0x082164CB
	.string "マコ“あーん　こわーい！$"

MtPyre_2F_Text_DezPostBattle: @ 0x082164D8
	.string "マコ“あたしたち　ラブラブだから\n"
	.string "まけても　へいき　なんだもん！$"

MtPyre_2F_Text_DezNotEnoughMons: @ 0x082164F9
	.string "マコ“あたしたちと　たたかいたいなら\n"
	.string "せめて　2ひきは　ポケモン　いないと\p"
	.string "あたしの　かれし　つよいんだから\n"
	.string "いっぴきじゃ　はなしに　ならないわ$"

MtPyre_2F_Text_LeahIntro: @ 0x08216542
	.string "みかけぬ　かおね⋯⋯\n"
	.string "なにも　おきない　うちに　かえりなさい！$"

MtPyre_2F_Text_LeahDefeat: @ 0x08216562
	.string "むん⋯⋯　てごわいのね$"

MtPyre_2F_Text_LeahPostBattle: @ 0x0821656E
	.string "ひい　おばあさまの　だい　から\n"
	.string "ここで　トレーナーを　やっているの⋯⋯\l"
	.string "この　やまを　まもっていくわ⋯⋯$"

MtPyre_2F_Text_ZanderIntro: @ 0x082165A3
	.string "ぎっ　ぎゃああああっ！\n"
	.string "でたあああっ！$"

MtPyre_2F_Text_ZanderDefeat: @ 0x082165B7
	.string "ま　まけたああああっ！$"

MtPyre_2F_Text_ZanderPostBattle: @ 0x082165C3
	.string "な　なにかが　うごく　たびに\n"
	.string "ビクっと　するよ\l"
	.string "ここで　しゅぎょう　するんじゃ　なかったよ$"
