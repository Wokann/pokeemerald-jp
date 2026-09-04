@ SeafloorCavern_Room9 scripts (JP map g24 m36 @ 0x082189FD)

SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre:: @ 0x082189FE
	lockall
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0x0
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0x0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0x0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	resetweather
	special Script_FadeOutMapMusic
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	setvar VAR_RESULT, 0x1
	playse SE_M_DETECT
	setfieldeffectarg 0, 16
	setfieldeffectarg 1, 42
	setfieldeffectarg 2, 0
	dofieldeffect FLDEFF_SPARKLE
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0x0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0x0
	delay 0x96
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	waitstate
	delay 0x3C
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0x0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0x0
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	delay 0x4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 0x1E
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 0x14
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0x0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0x0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0x0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 0x1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 0x1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 0x2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 0x1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
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

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere: @ 0x08218C94
	.string "アオギリ“⋯⋯まつんだ！$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou: @ 0x08218CA1
	.string "アオギリ“ふふふ⋯⋯\n"
	.string "やはり　おまえ　だったか$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre: @ 0x08218CB9
	.string "アオギリ“どうだ　みてみろ！\p"
	.string "ちょう　こだいポケモン　カイオーガが\n"
	.string "しずかに　ねむる　うつくしい　すがたを！\p"
	.string "おれは　この　ひが　くるのを\n"
	.string "ながい　あいだ　まっていた⋯⋯$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear: @ 0x08218D0F
	.string "アオギリ“それにしても　まさか\n"
	.string "ここまで　くいついて　くるとはな！\p"
	.string "だが　それも　もう　おわり\n"
	.string "おれの　もくてき　たっせいの　ため\l"
	.string "おまえには　ここで　きえてもらう！$"

SeafloorCavern_Room9_Text_ArchieDefeat: @ 0x08218D63
	.string "なにっ！？\n"
	.string "おまえ　ごときに　おれが⋯⋯？$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb: @ 0x08218D79
	.string "アオギリ“フフフ⋯⋯\p"
	.string "さすが　というべきか⋯⋯\n"
	.string "おまえの　その　ちからは　みとめよう！\p"
	.string "だが⋯⋯！\n"
	.string "おれには　これが　ある！\p"
	.string "この　べにいろのたまが　あれば\n"
	.string "カイオーガを⋯⋯$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself: @ 0x08218DD1
	.string "べにいろのたまが⋯⋯\n"
	.string "かってに　かがやき　はじめた⋯⋯！？$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo: @ 0x08218DEF
	.string "アオギリ“⋯⋯！？\p"
	.string "おれは　なにも　していないのに\n"
	.string "なぜ　べにいろのたまが⋯⋯？\p"
	.string "カイオーガは　どこへ　きえた？$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside: @ 0x08218E28
	.string "アオギリ“そとに　いる\n"
	.string "だんいん　からの　れんらくか$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard: @ 0x08218E43
	.string "アオギリ“どうした⋯⋯？\p"
	.string "ふうむ⋯⋯\n"
	.string "おおあめが　ふっている⋯⋯\p"
	.string "そうだろう⋯⋯　それこそが\n"
	.string "われわれ　アクアだんの　もくてき\l"
	.string "うみを　ふやすために　カイオーガを\l"
	.string "めざめさせた　りゆう　なのだからな\p"
	.string "なんだと！\p"
	.string "よそう　いじょうの　あめで\n"
	.string "このままでは　われわれも　キケンだと？\p"
	.string "そんな　ばかな⋯⋯\n"
	.string "とにかく　ようすを　みているんだ！$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear: @ 0x08218EEB
	.string "アオギリ“おかしい⋯⋯\p"
	.string "べにいろのたまで　カイオーガが　めざめる\n"
	.string "そして　コントロール　できるはず⋯⋯\p"
	.string "なのに⋯⋯　どうして⋯⋯\n"
	.string "カイオーガは　いなくなった！？\p"
	.string "なぜなんだ！？$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought: @ 0x08218F44
	.string "マツブサ“なんてことだ⋯⋯\p"
	.string "アオギリよ⋯⋯　おまえらも\n"
	.string "カイオーガを　めざめさせて　しまったな！\p"
	.string "このまま　えいえんに\n"
	.string "おおあめが　ふりつづけたら\l"
	.string "せかいは　いったい　どうなる！\p"
	.string "すべての　だいちは\n"
	.string "みずの　そこに　しずむぞ⋯⋯$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty: @ 0x08218FB7
	.string "アオギリ“な　なんだと！？\n"
	.string "かってな　ことを　いわないでくれ！\p"
	.string "おまえら　マグマだんこそ　グラードンを\n"
	.string "おこらせて　しまった　じゃないか！\p"
	.string "おれは　この　べにいろのたまさえ　あれば\n"
	.string "カイオーガを　コントロール　できるはず⋯⋯\p"
	.string "できる　はず　なんだ⋯⋯$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue: @ 0x08219035
	.string "マツブサ“とにかく　いまは　ここで\n"
	.string "いいあらそいを　している　ひまはない！\p"
	.string "そとに　でて　たしかめると　いい！\n"
	.string "めのまえに　ひろがっているのが\l"
	.string "われわれの　のぞんだ　せかいか　どうか！$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer: @ 0x08219092
	.string "マツブサ“{PLAYER}⋯⋯　おまえも\n"
	.string "はやく　そとに　でるんだ！$"
