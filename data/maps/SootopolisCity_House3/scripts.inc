@ SootopolisCity_House3 scripts (JP map g15 m7 @ 0x0820F479)

SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman:: @ 0x0820F47A
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans:: @ 0x0820F499
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl:: @ 0x0820F4A3
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou: @ 0x0820F4AC
	.string "あなた　ポケモン　トレーナーね？\p"
	.string "ルネシティの　アダンさまは\n"
	.string "おでしさんの　ミクリさま　より\l"
	.string "さらに　たくさんの　ファンが　いるのよ！\p"
	.string "あなたに　ファンは　いるのかしら？$"

SootopolisCity_House3_Text_YouMustBePrettyStrong: @ 0x0820F502
	.string "へえー\n"
	.string "じゃあ　けっこう　つよいのね！$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder: @ 0x0820F516
	.string "あららん⋯⋯\n"
	.string "それは　ちょっと　さみしいわね\p"
	.string "ファンが　できるよう　がんばりなさいよ！$"

SootopolisCity_House3_Text_TrainerFanClubWasWild: @ 0x0820F542
	.string "ねっしんな　ファンは　ホウエン　いがいの\n"
	.string "ちいきからも　やってくるの！\p"
	.string "あたしが　ミナモの\n"
	.string "トレーナー　ファンクラブに　いったときも\l"
	.string "とっても　すごかったもの！$"
