@ LilycoveCity_CoveLilyMotel_2F scripts (JP map g13 m1 @ 0x08205887)

LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex:
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare:
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma:
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott:
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex: @ 0x08205929
	.string "ぼくは　ゲーム　デザイナー\p"
	.string "へー\n"
	.string "ポケモンずかん　あつめてるの？\p"
	.string "ぜんぶ　あつめるの\n"
	.string "たいへん　だけど　がんばって！\p"
	.string "もし　ぜんぶ　あつめたら　おしえてよ！$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis: @ 0x08205978
	.string "すごいなー！\n"
	.string "いやー　すごいよ　きみ！！\p"
	.string "この　ポケモンずかん\n"
	.string "ぜんぶ　あつまって　いるんだね！\l"
	.string "それだけ　ポケモンを　あいしてるんだね！\p"
	.string "かんどう　しました！\n"
	.string "きみを　ひょうしょう　させてもらいますね！$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer: @ 0x082059DF
	.string "おれさま？\p"
	.string "プログラマーだよ！　こっちの\n"
	.string "スロットは　どんなのか　たのしみだな！$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist: @ 0x08205A08
	.string "おれ　グラフィッカー！\n"
	.string "ホウエンの　ポケモンは　おもしろいね$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute: @ 0x08205A27
	.string "うきわガール　かわいい　でしょ！\n"
	.string "うきわガールと　しょうぶ　なんて⋯⋯\p"
	.string "くー！　たまらんー！\p"
	.string "ふたごちゃん　かわいい　でしょ！\n"
	.string "ふたごちゃんと　2たい2　なんて⋯⋯\p"
	.string "くー！　たまらんー！$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart: @ 0x08205A85
	.string "なんだか　しおかぜが　こころを　くすぐって\n"
	.string "きもち　いいですね！$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy: @ 0x08205AA6
	.string "いつ　どこで　たいせんや　しょうぶを\n"
	.string "いどまれるか　わからないからな\l"
	.string "ゲームボーイ　アドバンスは　てばなせないよ！$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles: @ 0x08205AE0
	.string "エニシダ“⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯ズ\p"
	.string "⋯⋯　⋯⋯　⋯⋯！\n"
	.string "あ　ああ　{PLAYER}{KUN}\l"
	.string "ごめんごめん　ひるね　してたんだ\p"
	.string "ポケモンコンテスト　ってのが\n"
	.string "どんな　ものか　みに　きたんだ\l"
	.string "なかなか　おもしろそう　だけど⋯⋯\p"
	.string "まあ　わたしは　やっぱり\n"
	.string "じゅんすいに　たたかって　つよい\l"
	.string "トレーナーが　すき　だけどね\p"
	.string "うん　{PLAYER}{KUN}は\n"
	.string "ジムに　コンテストに　バトルテント\l"
	.string "なんでも　たのしんで　くれよ！$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy: @ 0x08205BA3
	.string "エニシダ“コンテストに　かつための\n"
	.string "せんりゃくを　ねるのも\l"
	.string "つよい　トレーナーに　なるための\l"
	.string "ほうほうの　ひとつでは　あるね$"
