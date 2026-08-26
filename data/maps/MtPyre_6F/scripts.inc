@ MtPyre_6F scripts (JP map g24 m20 @ 0x08216986)

MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie:: @ 0x08216987
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie:: @ 0x082169B3
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie:: @ 0x082169D2
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric:: @ 0x082169E9
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro: @ 0x08216A00
	.string "ここに　いると⋯⋯\n"
	.string "なにかの　ちからが　はいってくるの⋯⋯$"

MtPyre_6F_Text_ValerieDefeat: @ 0x08216A1E
	.string "ちからが　ぬけていく⋯⋯$"

MtPyre_6F_Text_ValeriePostBattle: @ 0x08216A2B
	.string "ここに　ねむっている　ポケモンたちの\n"
	.string "ちからが　はいって　くるのかもよ⋯⋯？$"

MtPyre_6F_Text_ValerieRegister: @ 0x08216A52
	.string "ふふふふ　しょうぶには　まけたけど\n"
	.string "わたし⋯⋯　こんな　ことが　できるの⋯⋯\p"
	.string "あなたの　ポケナビに　いっさい　てを\n"
	.string "ふれなくても⋯⋯　きえーいっ⋯⋯！$"

MtPyre_6F_Text_ValerieRematchIntro: @ 0x08216A9E
	.string "あなたの　うしろ⋯⋯\n"
	.string "なにが　いるの⋯⋯？$"

MtPyre_6F_Text_ValerieRematchDefeat: @ 0x08216AB4
	.string "なにかが　きえたわ⋯⋯$"

MtPyre_6F_Text_ValeriePostRematch: @ 0x08216AC0
	.string "ここに　ねむっている　ポケモンたち⋯⋯\n"
	.string "ときどき　あそんでいる　みたいなの⋯⋯$"

MtPyre_6F_Text_CedricIntro: @ 0x08216AE8
	.string "きみ　まいごなのか？\n"
	.string "おれが　きた　からには　あんしんだ！$"

MtPyre_6F_Text_CedricDefeat: @ 0x08216B06
	.string "まいご　じゃ　なかったか？$"

MtPyre_6F_Text_CedricPostBattle: @ 0x08216B14
	.string "まいごの　トレーナーは　あわてて　いるから\n"
	.string "かてる　きが　するんだよな\p"
	.string "ずるいから　もう　やめとくよ⋯⋯$"
