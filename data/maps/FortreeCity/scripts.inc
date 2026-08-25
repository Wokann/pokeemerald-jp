@ FortreeCity scripts (JP map g0 m4 @ 0x081DFDEE)

FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition::
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume::
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	@ JP opcode 0xC5 is waitdooranim here; US uses waitmoncry.
	waitdooranim
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee: @ 0x081DFEBE
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky: @ 0x081DFEC0
	.string "だれも　しんじて　くれないけど\n"
	.string "おおきな　ポケモンが　からだを　くねらせ\l"
	.string "そらを　とんでいるのを　みたんだ⋯⋯\p"
	.string "そいつは　131ばん　すいどうの　ほうへ\n"
	.string "とんでいったよ⋯⋯\p"
	.string "⋯⋯ところで\n"
	.string "なんか　きみ　コゲくさいね\p"
	.string "かざんに　でも　いってきた？$"

FortreeCity_Text_SomethingBlockingGym: @ 0x081DFF3B
	.string "ポケモンジムに　いきたいのに\n"
	.string "なにかが　みちを　ふさいでいるのよ！\p"
	.string "せっかく　120ばん　どうろで\n"
	.string "ポケモン　そだてて　きたのに！$"

FortreeCity_Text_ThisTimeIllBeatWinona: @ 0x081DFF7D
	.string "あたしの　じまんの　ポケモンで\n"
	.string "こんどこそ　ナギさんに　かってみせるわ！$"

FortreeCity_Text_TreesGrowByDrinkingRainwater: @ 0x081DFFA2
	.string "あめが　じめんに　すいこまれて\n"
	.string "その　みずを　すって　きがそだつ⋯⋯\p"
	.string "みずと　つちが　りょうほう　あるから\n"
	.string "この　ヒワマキシティも　あるのよね$"

FortreeCity_Text_EveryoneHealthyAndLively: @ 0x081DFFEA
	.string "このまちは　きのうえに\n"
	.string "いえを　たてて　くらしている⋯⋯\p"
	.string "そのせいか　みんな　げんきで\n"
	.string "イキイキと　している　のですよ\p"
	.string "わしも　このまちに　きてから\n"
	.string "30ねんほど　わかがえった　きぶんです$"

FortreeCity_Text_BugPokemonComeThroughWindow: @ 0x081E0049
	.string "きのうえで　くらすのは　いいんだけど\p"
	.string "ときどき　まどの　そとから\n"
	.string "むしポケモンが　はいって　きたりして\l"
	.string "びっくり　しちゃうんだよね$"

FortreeCity_Text_PokemonThatEvolveWhenTraded: @ 0x081E008B
	.string "ともだちと　こうかんを　すると\n"
	.string "しんか　する　ポケモンが　いるんだって！$"

FortreeCity_Text_SomethingUnseeable: @ 0x081E00B0
	.string "みえない　なにかが　いるようだ$"

FortreeCity_Text_UnseeableUseDevonScope: @ 0x081E00C0
	.string "みえない　なにかが　いるようだ\p"
	.string "デボンスコープを　つかいますか？$"

FortreeCity_Text_UsedDevonScopePokemonFled: @ 0x081E00E1
	.string "{PLAYER}は\n"
	.string "デボンスコープを　つかった！\p"
	.string "とうめいに　なっていた\n"
	.string "ポケモンの　すがたが　まるわかりだ！\p"
	.string "ポケモンは\n"
	.string "おどろいて　にげだした！$"

FortreeCity_Text_CitySign: @ 0x081E0126
	.string "ここは　ヒワマキ　シティ\n"
	.string "きの　うえで　しぜんと　たわむれる　まち$"

FortreeCity_Text_GymSign: @ 0x081E0148
	.string "ヒワマキ　シティ　ポケモンジム\n"
	.string "リーダー　ナギ\l"
	.string "せかいに　はばたく　とりつかい！$"
