@ AbandonedShip_Rooms2_1F scripts (JP map g24 m62 @ 0x0821AE1A)

AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan:: @ 0x0821AE1B
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan:: @ 0x0821AE4B
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch:: @ 0x0821AE64
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira:: @ 0x0821AE7F
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira:: @ 0x0821AEAF
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch:: @ 0x0821AEC8
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani:: @ 0x0821AEE3
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison:: @ 0x0821AEFA
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro: @ 0x0821AF11
	.string "フミ“おたから　さがしていたら\n"
	.string "トレーナー　はっけん！$"

AbandonedShip_Rooms2_1F_Text_DanDefeat: @ 0x0821AF2D
	.string "フミ“ぼくたち　ふたりの　ちからでも\n"
	.string "かてなかったのか⋯⋯$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle: @ 0x0821AF4B
	.string "フミ“おたから　みつからないんだよね⋯⋯\n"
	.string "もう　だれかが　もっていったのかな？$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons: @ 0x0821AF73
	.string "フミ“ポケモン　2ひき　いないんだね\n"
	.string "それだと　ぼくたちには　かてないよ！$"

AbandonedShip_Rooms2_1F_Text_KiraIntro: @ 0x0821AF99
	.string "ナツ“あら？　おたから　さがしていたのに\n"
	.string "トレーナー　はっけん　しちゃった！$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat: @ 0x0821AFC0
	.string "ナツ“つよいんだ！$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle: @ 0x0821AFCA
	.string "ナツ“おたから　どこかな？\n"
	.string "みつかったら　なに　かおうか　きめてるのよ！$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons: @ 0x0821AFEF
	.string "ナツ“あら　ポケモン　2ひき　いないの？\n"
	.string "じゃあ　しょうぶは　おあずけね！$"

AbandonedShip_Rooms2_1F_Text_KiraRegister: @ 0x0821B015
	.string "ナツ“もう　くやしいな！\n"
	.string "あなたなんて　とうろく　しちゃうんだから！$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro: @ 0x0821B038
	.string "フミ“ずっと　おたから　さがしていて\n"
	.string "ポケモンも　つよく　なったんだよねー！\l"
	.string "ちょっと　あいて　してみてよ$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat: @ 0x0821B06E
	.string "フミ“あいかわらず　つよいな！$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch: @ 0x0821B07E
	.string "フミ“おたからは　みつからないし\n"
	.string "ポケモンは　まけるし　いえに　かえりたいよ\p"
	.string "でも　そんなこと　いうと\n"
	.string "かのじょ　おこりだすからな⋯⋯$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons: @ 0x0821B0C2
	.string "フミ“ポケモン　2ひき　いないんだね\n"
	.string "それだと　ぼくたちには　かてないよ！$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro: @ 0x0821B0E8
	.string "ナツ“あら？　また　であったわね！\n"
	.string "あたしたちと　いっしょで　あきらめずに\l"
	.string "おたから　さがしているのね！\p"
	.string "しょうぶして　まけた　ほうは\n"
	.string "あきらめることに　しない？$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat: @ 0x0821B13A
	.string "ナツ“また　まけちゃった⋯⋯$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch: @ 0x0821B149
	.string "ナツ“もっと　ポケモン　そだてて\n"
	.string "おたから　みつけるまで　かえらないわよ！$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons: @ 0x0821B16F
	.string "ナツ“あら　ポケモン　2ひき　いないの？\n"
	.string "じゃあ　しょうぶは　おあずけね！$"

AbandonedShip_Rooms2_1F_Text_JaniIntro: @ 0x0821B195
	.string "およぐの　ヘタだけど\n"
	.string "しょうぶは　つよいもーん$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat: @ 0x0821B1AD
	.string "あれ　だめだったかあ$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle: @ 0x0821B1B8
	.string "ふねの　なかを　はだしで　あるくと\n"
	.string "ちょっと　きもちわるいなあ$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro: @ 0x0821B1D8
	.string "つよさも　やさしさも\n"
	.string "これ　トレーナーの　たから！$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat: @ 0x0821B1F2
	.string "おお　あなたには\n"
	.string "キラリと　ひかるものが　あるな$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle: @ 0x0821B20B
	.string "ふねの　どこかの　へやに\n"
	.string "キラリと　ひかるものが　あったんだが⋯⋯$"
