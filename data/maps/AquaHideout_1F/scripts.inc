@ AquaHideout_1F scripts (JP map g24 m23 @ 0x08217935)

AquaHideout_1F_MapScripts::
	.byte 0

AquaHideout_1F_EventScript_HideoutEntranceGrunt1:: @ 0x08217936
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1:: @ 0x08217954
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1:: @ 0x0821795E
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2:: @ 0x08217968
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2:: @ 0x08217986
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2:: @ 0x08217990
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1:: @ 0x0821799A
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated:: @ 0x082179B5
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething: @ 0x082179BF
	.string "なんだ　なんだ！\n"
	.string "おれたち　アクアだんに　なんの　ようだ！\p"
	.string "リーダーだったら　いま　だいじな　ものを\n"
	.string "ぶんどりに　でかけていて　るすだぞ！\p"
	.string "⋯⋯どこに　いったのか　だって？\p"
	.string "わはははっ！　そんな　だいじな　ことを\n"
	.string "おしえられる　わけ　ないだろうが！$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe: @ 0x08217A3C
	.string "なんだ　なんだ！\n"
	.string "おまえは　マグマだんの　したっぱか！？\p"
	.string "マグマだんめ　アジトで　すごいポケモンを\n"
	.string "めざめさせる　つもり　らしいな！\p"
	.string "えーい！　アジトは\n"
	.string "いったい　どこに　あるって　いうんだ！$"

AquaHideout_1F_Text_BossWentToJackASubmarine: @ 0x08217A9D
	.string "なんだ　なんだ！\n"
	.string "おれたち　アクアだんに　なんの　ようだ！\p"
	.string "リーダーだったら　いま　せんすいていを\n"
	.string "ぶんどりに　でかけていて　るすだぞ！\p"
	.string "⋯⋯どこに　いったのか　だって？\p"
	.string "わはははっ！　そんな　だいじな　ことを\n"
	.string "おしえられる　わけ　ないだろうが！$"

AquaHideout_1F_Text_BossIsOnRoute122: @ 0x08217B19
	.string "なんだ　なんだ！\n"
	.string "おれたち　アクアだんに　なんの　ようだ！\p"
	.string "リーダーは　いま　122ばん　すいどうの\n"
	.string "おくりびやまに　むかっていて　るすだぞ！\p"
	.string "⋯⋯なにしに　いったのか　だって？\p"
	.string "わはははっ！　そんな　だいじな　ことを\n"
	.string "おしえられる　わけ　ないだろうが！$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney: @ 0x08217B99
	.string "なんだ　なんだ！\n"
	.string "おまえは　マグマだんの　したっぱか！？\p"
	.string "えんとつやまには　マグマだんが　ねらう\n"
	.string "すごい　ポケモンが　いるらしいな！\p"
	.string "えーい！　そいつは\n"
	.string "いったい　どんな　ポケモン　なんだ！$"

AquaHideout_1F_Text_BossIsInSlateportCity: @ 0x08217BF9
	.string "なんだ　なんだ！\n"
	.string "おれたち　アクアだんに　なんの　ようだ！\p"
	.string "リーダーは　いま　カイナシティに\n"
	.string "むかっていて　るすだぞ！\p"
	.string "⋯⋯なにしに　いったのか　だって？\p"
	.string "わはははっ！　そんな　だいじな　ことを\n"
	.string "おしえられる　わけ　ないだろうが！$"

AquaHideout_1F_Text_Grunt1Intro: @ 0x08217C6D
	.string "ややや！\n"
	.string "あやしい　じんぶつを　はっけーん！$"

AquaHideout_1F_Text_Grunt1Defeat: @ 0x08217C84
	.string "うーむ　まけちまったかー！$"

AquaHideout_1F_Text_Grunt1PostBattle: @ 0x08217C92
	.string "しょうぶには　まけたが\n"
	.string "おれは　やくめを　はたしたのだ⋯⋯$"
