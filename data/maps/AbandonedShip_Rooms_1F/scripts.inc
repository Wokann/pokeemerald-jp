@ AbandonedShip_Rooms_1F scripts (JP map g24 m56 @ 0x0821A9FD)

AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman:: @ 0x0821A9FE
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius:: @ 0x0821AA07
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia:: @ 0x0821AA1E
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia:: @ 0x0821AA4A
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch:: @ 0x0821AA69
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround: @ 0x0821AA80
	.string "こういった　ふねは　めずらしいので\n"
	.string "けんがく　しておるのですよ\p"
	.string "フムフム⋯⋯\n"
	.string "ほかにも　へやが　ありそうですな$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro: @ 0x0821AAB8
	.string "あら　こんな　ところまで　きて\n"
	.string "キミも　ものずきね！$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat: @ 0x0821AAD3
	.string "ものずき　だけじゃ　なくて\n"
	.string "つよいのか⋯⋯$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle: @ 0x0821AAE9
	.string "となりのへやの　おじさん\n"
	.string "けんがく　だなんて　あやしいわ\p"
	.string "わたしに　きが　あるんじゃない　かしら$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister: @ 0x0821AB1A
	.string "つよい　トレーナーの　キミを\n"
	.string "きねんに　とうろく　させて　ちょうだいね！$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro: @ 0x0821AB3F
	.string "こんな　ところまで　なんども　きて\n"
	.string "ほんとに　ものずきね　キミって！$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat: @ 0x0821AB62
	.string "ちょっと　つよすぎない？$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch: @ 0x0821AB6F
	.string "あの　おじさん　ぜったい\n"
	.string "わたしの　ことを　みているのよ！\l"
	.string "わざとらしすぎるわ！$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro: @ 0x0821AB98
	.string "わーっ！\n"
	.string "みつかった⋯⋯　って　あれ？$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat: @ 0x0821ABAC
	.string "なんだ\n"
	.string "かあちゃん　じゃ　なかったのか$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle: @ 0x0821ABC0
	.string "かあちゃんに　しかられて\n"
	.string "ここまで　にげて　きたんだ\l"
	.string "ボクが　ここに　いるのは　ないしょだぞ！$"
