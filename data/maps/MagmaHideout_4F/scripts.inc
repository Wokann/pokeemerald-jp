@ MagmaHideout_4F scripts (JP map g24 m91 @ 0x0821C880)

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie:: @ 0x0821C881
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	delay 30
	applywaitmovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:: @ 0x0821C993
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:: @ 0x0821C99E
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:: @ 0x0821C9A1
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11:: @ 0x0821C9AD
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12:: @ 0x0821C9C4
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13:: @ 0x0821C9DB
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha:: @ 0x0821C9F2
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:: @ 0x0821CA09
	.string "オレも　グラードンを　みたいのに\n"
	.string "まだ　シッポすら　みせて　もらえなくて\p"
	.string "イライラ　してるんだ⋯⋯\p"
	.string "あっ！\n"
	.string "グラードンのこと　いっちゃった！$"

MagmaHideout_4F_Text_Grunt11Defeat:: @ 0x0821CA50
	.string "やっぱり　れいせいな　きもちを\n"
	.string "うしなって　いたら　かてないな⋯⋯$"

MagmaHideout_4F_Text_Grunt11PostBattle:: @ 0x0821CA72
	.string "そういえば　グラードンには\n"
	.string "シッポなんて　あるんだろうか⋯⋯？$"

MagmaHideout_4F_Text_Grunt12Intro:: @ 0x0821CA92
	.string "ふはは　もうすぐ！　もうすぐだ！\n"
	.string "オレたちの　もくてきが　じつげん　する！$"

MagmaHideout_4F_Text_Grunt12Defeat:: @ 0x0821CAB8
	.string "ぐうう　ここまで　きていながら！$"

MagmaHideout_4F_Text_Grunt12PostBattle:: @ 0x0821CAC9
	.string "マツブサさまー！\n"
	.string "しんにゅうしゃが　そっちにー！$"

MagmaHideout_4F_Text_Grunt13Intro:: @ 0x0821CAE2
	.string "まだまだー！\n"
	.string "かんたんには　おくへ　いかせない！$"

MagmaHideout_4F_Text_Grunt13Defeat:: @ 0x0821CAFB
	.string "オレって　たおすの　かんたん　だった？$"

MagmaHideout_4F_Text_Grunt13PostBattle:: @ 0x0821CB0F
	.string "も　もう　ひとしょうぶ⋯⋯　がくっ$"

MagmaHideout_4F_Text_TabithaIntro:: @ 0x0821CB21
	.string "ウヒョ！\n"
	.string "ここまで　きたんだから　おしえて　やろう\p"
	.string "そうさ　このさきには\n"
	.string "グラードンが　ねむって　いるのさ！\p"
	.string "マツブサさまは　たったいま\n"
	.string "グラードンの　ところへ　いった！\p"
	.string "もうすぐ　ねむりから　めをさますぞ！\n"
	.string "ウヒョ！　ウヒョヒョ！$"

MagmaHideout_4F_Text_TabithaDefeat:: @ 0x0821CB96
	.string "やられちまったい⋯⋯　ウヒョ$"

MagmaHideout_4F_Text_TabithaPostBattle:: @ 0x0821CBA5
	.string "⋯⋯と　こんな　ぐあいに　おまえと\n"
	.string "あそんで　やっている　あいだに\l"
	.string "マツブサさまが　グラードンを⋯⋯　ウヒョ$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:: @ 0x0821CBDC
	.string "マツブサ“マグマに　ねむる　グラードンよ\n"
	.string "なにをしても　めざめなかった　おまえが\l"
	.string "もとめて　いたのは　あいいろのたま⋯⋯\p"
	.string "そうなんだろう？\p"
	.string "さあ　ここに　もってきて　やったぞ\n"
	.string "この　かがやきで　めを　さませ！\p"
	.string "そして　ほんとうの　ちからを\n"
	.string "わたしに　みせて　おくれ！$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:: @ 0x0821CC62
	.string "マツブサ“⋯⋯グラードン！\n"
	.string "いったい　どうしたと　いうんだ！？\p"
	.string "あいいろのたまでは　だめだと　いうのか？\p"
	.string "グラードンよ！\n"
	.string "どこへ　きえて　しまったんだ⋯⋯$"

MagmaHideout_4F_Text_MaxieOhItWasYou:: @ 0x0821CCB0
	.string "マツブサ“おまえか！\p"
	.string "あっちでも　こっちでも　ちょこちょこと\n"
	.string "うろつき　まわって　いたようだが\p"
	.string "なるほど　おまえが　なにか\n"
	.string "こざいくを　していたんだな⋯⋯！$"

MagmaHideout_4F_Text_MaxieDefeat:: @ 0x0821CCFF
	.string "おまえは　なぜ　そんなに\n"
	.string "ポケモンを　うまく　あつかえるのだ⋯⋯$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:: @ 0x0821CD20
	.string "マツブサ“グラードンが　にげだしたの　には\n"
	.string "なにか　わけがある⋯⋯\l"
	.string "そう　いいたいの　だろう？\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "ふん⋯⋯\n"
	.string "それぐらい　わたしも　わかっていたさ\p"
	.string "グラードンが　いなくなって　しまえば\n"
	.string "もう　こんな　やまに　ようはない\p"
	.string "わたしは　グラードンを　おいかけるから\n"
	.string "おまえとも　ここで　おわかれだな！$"
