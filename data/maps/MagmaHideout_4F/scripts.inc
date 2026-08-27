@ MagmaHideout_4F scripts (JP map g24 m91 @ 0x0821C880)

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
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
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
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

MagmaHideout_4F_Movement_GroudonApproach::
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

MagmaHideout_4F_Movement_GroudonExit::
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround::
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

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro::
	.string "オレも　グラードンを　みたいのに\n"
	.string "まだ　シッポすら　みせて　もらえなくて\p"
	.string "イライラ　してるんだ⋯⋯\p"
	.string "あっ！\n"
	.string "グラードンのこと　いっちゃった！$"

MagmaHideout_4F_Text_Grunt11Defeat::
	.string "やっぱり　れいせいな　きもちを\n"
	.string "うしなって　いたら　かてないな⋯⋯$"

MagmaHideout_4F_Text_Grunt11PostBattle::
	.string "そういえば　グラードンには\n"
	.string "シッポなんて　あるんだろうか⋯⋯？$"

MagmaHideout_4F_Text_Grunt12Intro::
	.string "ふはは　もうすぐ！　もうすぐだ！\n"
	.string "オレたちの　もくてきが　じつげん　する！$"

MagmaHideout_4F_Text_Grunt12Defeat::
	.string "ぐうう　ここまで　きていながら！$"

MagmaHideout_4F_Text_Grunt12PostBattle::
	.string "マツブサさまー！\n"
	.string "しんにゅうしゃが　そっちにー！$"

MagmaHideout_4F_Text_Grunt13Intro::
	.string "まだまだー！\n"
	.string "かんたんには　おくへ　いかせない！$"

MagmaHideout_4F_Text_Grunt13Defeat::
	.string "オレって　たおすの　かんたん　だった？$"

MagmaHideout_4F_Text_Grunt13PostBattle::
	.string "も　もう　ひとしょうぶ⋯⋯　がくっ$"

MagmaHideout_4F_Text_TabithaIntro::
	.string "ウヒョ！\n"
	.string "ここまで　きたんだから　おしえて　やろう\p"
	.string "そうさ　このさきには\n"
	.string "グラードンが　ねむって　いるのさ！\p"
	.string "マツブサさまは　たったいま\n"
	.string "グラードンの　ところへ　いった！\p"
	.string "もうすぐ　ねむりから　めをさますぞ！\n"
	.string "ウヒョ！　ウヒョヒョ！$"

MagmaHideout_4F_Text_TabithaDefeat::
	.string "やられちまったい⋯⋯　ウヒョ$"

MagmaHideout_4F_Text_TabithaPostBattle::
	.string "⋯⋯と　こんな　ぐあいに　おまえと\n"
	.string "あそんで　やっている　あいだに\l"
	.string "マツブサさまが　グラードンを⋯⋯　ウヒョ$"

MagmaHideout_4F_Text_MaxieAwakenGroudon::
	.string "マツブサ“マグマに　ねむる　グラードンよ\n"
	.string "なにをしても　めざめなかった　おまえが\l"
	.string "もとめて　いたのは　あいいろのたま⋯⋯\p"
	.string "そうなんだろう？\p"
	.string "さあ　ここに　もってきて　やったぞ\n"
	.string "この　かがやきで　めを　さませ！\p"
	.string "そして　ほんとうの　ちからを\n"
	.string "わたしに　みせて　おくれ！$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong::
	.string "マツブサ“⋯⋯グラードン！\n"
	.string "いったい　どうしたと　いうんだ！？\p"
	.string "あいいろのたまでは　だめだと　いうのか？\p"
	.string "グラードンよ！\n"
	.string "どこへ　きえて　しまったんだ⋯⋯$"

MagmaHideout_4F_Text_MaxieOhItWasYou::
	.string "マツブサ“おまえか！\p"
	.string "あっちでも　こっちでも　ちょこちょこと\n"
	.string "うろつき　まわって　いたようだが\p"
	.string "なるほど　おまえが　なにか\n"
	.string "こざいくを　していたんだな⋯⋯！$"

MagmaHideout_4F_Text_MaxieDefeat::
	.string "おまえは　なぜ　そんなに\n"
	.string "ポケモンを　うまく　あつかえるのだ⋯⋯$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon::
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
