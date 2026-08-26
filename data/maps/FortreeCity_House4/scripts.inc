@ FortreeCity_House4 scripts (JP map g12 m7 @ 0x082051A2)

FortreeCity_House4_MapScripts::
	.byte 0

@ JP uses the waitdooranim opcode (0xC5) where US uses waitmoncry.

FortreeCity_House4_EventScript_Woman:: @ 0x082051A3
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy:: @ 0x082051AC
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand:: @ 0x082051E6
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned:: @ 0x082051FA
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb:: @ 0x08205228
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull:: @ 0x08205242
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry_jp
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether: @ 0x08205255
	.string "ポケモンと　いることで\n"
	.string "なかの　いい　ともだちが　ふえていく⋯⋯\p"
	.string "こうして　せかいは　つながって　いくのね！\n"
	.string "すてきだわ！$"

FortreeCity_House4_Text_GoBirdPokemon: @ 0x08205293
	.string "それっ！\n"
	.string "ゆけっ　とりポケモン$"

FortreeCity_House4_Text_AskedWingullToRunErrand: @ 0x082052A3
	.string "えへへ　キャモメに\n"
	.string "ちょっと　おつかいを　たのんだのさ$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb: @ 0x082052BF
	.string "よーし！\n"
	.string "おかえり　キャモメ！\p"
	.string "あれえ？　なに　もってるんだ？\p"
	.string "メンタルハーブ　かあ⋯⋯\n"
	.string "どこかで　ひろったんだな\p"
	.string "でも　ぼく　トレーナーじゃ　ないからな\n"
	.string "きみに　あげるよ！$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull: @ 0x08205317
	.string "キャモメの　おかげで\n"
	.string "とおくの　ともだちとも　なかよし　なのさ！$"

FortreeCity_House4_Text_Wingull: @ 0x08205338
	.string "キャモメ“ぴひょー！$"
