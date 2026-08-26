@ MeteorFalls_1F_2R scripts (JP map g24 m1 @ 0x08213079)

MeteorFalls_1F_2R_MapScripts::
	.byte 0

MeteorFalls_1F_2R_EventScript_Nicolas:: @ 0x0821307A
	trainerbattle_single TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasIntro, MeteorFalls_1F_2R_Text_NicolasDefeat, MeteorFalls_1F_2R_EventScript_RegisterNicolas
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchNicolas
	msgbox MeteorFalls_1F_2R_Text_NicolasPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterNicolas:: @ 0x082130A6
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MeteorFalls_1F_2R_Text_NicolasRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NICOLAS_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchNicolas:: @ 0x082130C5
	trainerbattle_rematch TRAINER_NICOLAS_1, MeteorFalls_1F_2R_Text_NicolasRematchIntro, MeteorFalls_1F_2R_Text_NicolasRematchDefeat
	msgbox MeteorFalls_1F_2R_Text_NicolasPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_John:: @ 0x082130DC
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnIntro, MeteorFalls_1F_2R_Text_JohnDefeat, MeteorFalls_1F_2R_Text_JohnNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJohn
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJohn
	msgbox MeteorFalls_1F_2R_Text_JohnPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJohn:: @ 0x0821310C
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJohn:: @ 0x08213125
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JohnRematchIntro, MeteorFalls_1F_2R_Text_JohnRematchDefeat, MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JohnPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_EventScript_Jay:: @ 0x08213140
	trainerbattle_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayIntro, MeteorFalls_1F_2R_Text_JayDefeat, MeteorFalls_1F_2R_Text_JayNotEnoughMons, MeteorFalls_1F_2R_EventScript_RegisterJay
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MeteorFalls_1F_2R_EventScript_RematchJay
	msgbox MeteorFalls_1F_2R_Text_JayPostBattle, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_2R_EventScript_RegisterJay:: @ 0x08213170
	msgbox MeteorFalls_1F_2R_Text_JohnRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOHN_AND_JAY_1
	release
	end

MeteorFalls_1F_2R_EventScript_RematchJay:: @ 0x08213189
	trainerbattle_rematch_double TRAINER_JOHN_AND_JAY_1, MeteorFalls_1F_2R_Text_JayRematchIntro, MeteorFalls_1F_2R_Text_JayRematchDefeat, MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons
	msgbox MeteorFalls_1F_2R_Text_JayPostRematch, MSGBOX_AUTOCLOSE
	end

MeteorFalls_1F_2R_Text_NicolasIntro: @ 0x082131A4
	.string "ここは　オレたち\n"
	.string "ドラゴンつかいの　しゅぎょうの　ばしょ！\p"
	.string "チャンピオンも　くる　ばしょ　といったら\n"
	.string "その　すごさ　わかるだろうか！？$"

MeteorFalls_1F_2R_Text_NicolasDefeat: @ 0x082131E8
	.string "くっ！\n"
	.string "これほど　つよいとは⋯⋯！$"

MeteorFalls_1F_2R_Text_NicolasPostBattle: @ 0x082131FA
	.string "まだまだ　みちは　ながく　けわしい\p"
	.string "オレと　オレの　ポケモンが\n"
	.string "いちばんに　なれるのは　いつだろう⋯⋯$"

MeteorFalls_1F_2R_Text_NicolasRegister: @ 0x0821322E
	.string "きみの　つよさを　もっと　しりたい\n"
	.string "ポケナビに　とうろく　させてくれ！$"

MeteorFalls_1F_2R_Text_NicolasRematchIntro: @ 0x08213252
	.string "あれから　いちばん　めざして\n"
	.string "かなり　じぶんたちを　きたえた⋯⋯\p"
	.string "どれほど　つよくなったか\n"
	.string "きみで　たしかめさせて　もらおうッ！$"

MeteorFalls_1F_2R_Text_NicolasRematchDefeat: @ 0x08213293
	.string "くっ！\n"
	.string "これほど　つよいとは⋯⋯！$"

MeteorFalls_1F_2R_Text_NicolasPostRematch: @ 0x082132A5
	.string "あいかわらず　ポケモンを　きたえてるな\p"
	.string "きみが　その　つよさで　あるかぎり\n"
	.string "オレも　つよくなれるよ！$"

MeteorFalls_1F_2R_Text_JohnIntro: @ 0x082132D8
	.string "ゲン“わしらは　いつも　ふうふで\n"
	.string "ポケモンを　しておるからのう\l"
	.string "しょうぶにも　じしんが　あるんじゃよ$"

MeteorFalls_1F_2R_Text_JohnDefeat: @ 0x0821330B
	.string "ゲン“おやおや\n"
	.string "まけたよ　ばあさん$"

MeteorFalls_1F_2R_Text_JohnPostBattle: @ 0x0821331D
	.string "ゲン“けっこんして　50ねん⋯⋯\n"
	.string "そういや　いちども　ばあさんに\l"
	.string "ポケモンしょうぶで　かってないのう$"

MeteorFalls_1F_2R_Text_JohnNotEnoughMons: @ 0x08213350
	.string "ゲン“おやおや\n"
	.string "わかい　トレーナー　じゃな！\p"
	.string "わしらと　しょうぶ　してくれるのなら\n"
	.string "ポケモンを　もっと　つれてきなされ$"

MeteorFalls_1F_2R_Text_JohnRegister: @ 0x0821338C
	.string "ゲン“わかい　トレーナーさん⋯⋯\n"
	.string "また　きかいが　あれば\l"
	.string "わしらと　たたかって　くれんかのう$"

MeteorFalls_1F_2R_Text_JayIntro: @ 0x082133BB
	.string "ハツ“けっこんして　50ねん⋯⋯\n"
	.string "わたしら　ふうふの　きずなは\l"
	.string "どんな　ものでも　きれませんよ$"

MeteorFalls_1F_2R_Text_JayDefeat: @ 0x082133EB
	.string "ハツ“おやおや\n"
	.string "まけましたよ　じいさん$"

MeteorFalls_1F_2R_Text_JayPostBattle: @ 0x082133FF
	.string "ハツ“けっこんして　50ねん⋯⋯\n"
	.string "ふうふげんかに　なるたび\l"
	.string "ポケモンしょうぶを　していましたねえ$"

MeteorFalls_1F_2R_Text_JayNotEnoughMons: @ 0x08213430
	.string "ハツ“おやおや\n"
	.string "わかい　トレーナーさん　ですねえ\p"
	.string "わしらと　しょうぶ　してくれるのなら\n"
	.string "ポケモンを　もっと　つれておいで$"

MeteorFalls_1F_2R_Text_JohnRematchIntro: @ 0x0821346D
	.string "ゲン“わしらは　いつも　ふうふで\n"
	.string "ポケモンを　たのしんでおる　からのう\l"
	.string "しょうぶにも　じしんが　あるんじゃよ$"

MeteorFalls_1F_2R_Text_JohnRematchDefeat: @ 0x082134A4
	.string "ゲン“おやおや\n"
	.string "まけたよ　ばあさん$"

MeteorFalls_1F_2R_Text_JohnPostRematch: @ 0x082134B6
	.string "ゲン“けっこんして　50ねん⋯⋯\n"
	.string "そういや　まいにち　まいにち\l"
	.string "ばあさんと　しょうぶ　していたのう$"

MeteorFalls_1F_2R_Text_JohnRematchNotEnoughMons: @ 0x082134E8
	.string "ゲン“おやおや\n"
	.string "わかい　トレーナー　じゃな！\p"
	.string "わしらと　しょうぶ　してくれるのなら\n"
	.string "ポケモンを　もっと　つれてきなされ$"

MeteorFalls_1F_2R_Text_JayRematchIntro: @ 0x08213524
	.string "ハツ“けっこんして　50ねん⋯⋯\n"
	.string "おたがいを　ささえあってきた\l"
	.string "わたしら　ふうふは　つよいですよ$"

MeteorFalls_1F_2R_Text_JayRematchDefeat: @ 0x08213555
	.string "ハツ“おやおや\n"
	.string "まけましたよ　じいさん$"

MeteorFalls_1F_2R_Text_JayPostRematch: @ 0x08213569
	.string "ハツ“けっこんして　50ねん⋯⋯\n"
	.string "いろんなことが　ありましたねえ\p"
	.string "これからも　じいさんと　いっしょに\n"
	.string "たのしいことが　つづくと　いいですわねえ$"

MeteorFalls_1F_2R_Text_JayRematchNotEnoughMons: @ 0x082135B1
	.string "ハツ“おやおや\n"
	.string "わかい　トレーナーさん　ですねえ\p"
	.string "わしらと　しょうぶ　してくれるのなら\n"
	.string "ポケモンを　もっと　つれておいで$"
