@ LilycoveCity_LilycoveMuseum_2F scripts (JP map g13 m3 @ 0x082061E6)

LilycoveCity_LilycoveMuseum_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_LilycoveMuseum_2F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_LilycoveMuseum_2F_OnFrame
	.byte 0

LilycoveCity_LilycoveMuseum_2F_OnLoad: @ 0x082061F1
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting:: @ 0x08206200
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting:: @ 0x0820620F
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting:: @ 0x0820621E
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting:: @ 0x0820622D
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCoolPainting:: @ 0x08206237
	setmetatile 10, 6, METATILE_LilycoveMuseum_Painting2_Left, TRUE
	setmetatile 11, 6, METATILE_LilycoveMuseum_Painting2_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckBeautyPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetBeautyPainting:: @ 0x0820624F
	setmetatile 18, 6, METATILE_LilycoveMuseum_Painting1_Left, TRUE
	setmetatile 19, 6, METATILE_LilycoveMuseum_Painting1_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckCutePainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetCutePainting:: @ 0x08206267
	setmetatile 14, 10, METATILE_LilycoveMuseum_Painting3_Left, TRUE
	setmetatile 15, 10, METATILE_LilycoveMuseum_Painting3_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckSmartPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetSmartPainting:: @ 0x0820627F
	setmetatile 6, 10, METATILE_LilycoveMuseum_Painting0_Left, TRUE
	setmetatile 7, 10, METATILE_LilycoveMuseum_Painting0_Right, TRUE
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_CheckToughPainting
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SetToughPainting:: @ 0x08206297
	setmetatile 2, 6, METATILE_LilycoveMuseum_Painting4_Left, TRUE
	setmetatile 3, 6, METATILE_LilycoveMuseum_Painting4_Right, TRUE
	end

LilycoveCity_LilycoveMuseum_2F_OnFrame: @ 0x082062AA
	map_script_2 VAR_LILYCOVE_MUSEUM_2F_STATE, 0, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall
	.2byte 0

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowExhibitHall:: @ 0x082062B4
	lockall
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit, MSGBOX_SIGN
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Movement_PlayerWalkInPlaceLeft:
	walk_in_place_faster_left
	step_end

LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall:
	face_up
	delay_16
	step_end

LilycoveCity_LilycoveMuseum_2F_EventScript_Curator:: @ 0x08206312
	lockall
	goto_if_set FLAG_RECEIVED_GLASS_ORNAMENT, LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 2, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 3, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 4, LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting
	case 5, LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_AddedPainting:: @ 0x08206366
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ThankPlayer:: @ 0x0820636F
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer, MSGBOX_DEFAULT
	applymovement LOCALID_MUSEUM_2F_CURATOR, LilycoveCity_LilycoveMuseum_2F_Movement_FaceExhibitHall
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests, MSGBOX_DEFAULT
	goto LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_GiveGlassOrnament:: @ 0x08206396
	applymovement LOCALID_MUSEUM_2F_CURATOR, Common_Movement_FacePlayer
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude, MSGBOX_DEFAULT
	givedecoration DECOR_GLASS_ORNAMENT
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament
	setflag FLAG_RECEIVED_GLASS_ORNAMENT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_NoRoomForGlassOrnament:: @ 0x082063BD
	call Common_EventScript_NoRoomForDecor
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ReceivedGlassOrnament:: @ 0x082063CD
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit, MSGBOX_NPC
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CutePainting:: @ 0x082063D7
	lockall
	goto_if_set FLAG_CUTE_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ToughPainting:: @ 0x082063EA
	lockall
	goto_if_set FLAG_TOUGH_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_CoolPainting:: @ 0x082063FD
	lockall
	goto_if_set FLAG_COOL_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_BeautyPainting:: @ 0x08206410
	lockall
	goto_if_set FLAG_BEAUTY_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_SmartPainting:: @ 0x08206423
	lockall
	goto_if_set FLAG_SMART_PAINTING_MADE, LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_Girl:: @ 0x08206436
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ExpertM:: @ 0x0820643F
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_RichBoy:: @ 0x08206448
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCoolPainting:: @ 0x08206451
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_COOL
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowBeautyPainting:: @ 0x0820645F
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_BEAUTY
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowCutePainting:: @ 0x0820646D
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_CUTE
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowSmartPainting:: @ 0x0820647B
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_SMART
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_ShowToughPainting:: @ 0x08206489
	msgbox LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon, MSGBOX_SIGN
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_MUSEUM_TOUGH
	releaseall
	end

LilycoveCity_LilycoveMuseum_2F_Text_ThisIsExhibitHall: @ 0x08206497
	.string "ここは　とくべつ　てんじしつ　です$"

LilycoveCity_LilycoveMuseum_2F_Text_ExplainExhibitHall: @ 0x082064A9
	.string "ごらんの　とおり　まだ\n"
	.string "えが　かざられて　おりません\p"
	.string "ここには　1かいに　あるような\n"
	.string "いわゆる　めいが　といった　ものとは\l"
	.string "ちがう　えを　かざりたいの　ですよ！\p"
	.string "ふるい　めいが　ばかりが\n"
	.string "げいじゅつ　なのでは　ありません！\p"
	.string "この　てんじしつ　には⋯⋯\p"
	.string "いまにも　ポケモンが　とびだして　きそうな\n"
	.string "モダンで　いきいきとした　さくひんを\l"
	.string "かざって　みたいのです！$"

LilycoveCity_LilycoveMuseum_2F_Text_PleaseObtainPaintingsForExhibit: @ 0x0820655D
	.string "つい　ながながと　しつれい　しました\p"
	.string "あなたは　まだ　おわかいし\n"
	.string "たびを　なさって　いる　ようだから\p"
	.string "いきいきとした　ポケモンや\n"
	.string "それを　えがいた　すてきな　さくひんに\l"
	.string "であわれる　かも　しれません！\p"
	.string "もし　そんな　さくひんに　であったら\n"
	.string "そのえを　ここに　かざれる　ように\l"
	.string "あなたから　おねがい　して　くださると\l"
	.string "たいへん　うれしいです$"

LilycoveCity_LilycoveMuseum_2F_Text_WishToFillExhibit: @ 0x08206607
	.string "この　てんじしつ　には\n"
	.string "げんだいの　いきいき　とした　ポケモンの\l"
	.string "えを　かざりたい　ものです$"

LilycoveCity_LilycoveMuseum_2F_Text_ThanksAddedNewPainting: @ 0x08206636
	.string "おかげさまで　えを\n"
	.string "かざる　ことが　できましたよ！\p"
	.string "あなたの　ポケモン　なんですって　ね！\n"
	.string "ほんとうに　すばらしい　です！\p"
	.string "どうも　ありがとう⋯⋯！$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYouPlayer: @ 0x08206681
	.string "あ　あなた！　{PLAYER}さん！$"

LilycoveCity_LilycoveMuseum_2F_Text_PaintingsAttractedMoreGuests: @ 0x0820668E
	.string "どうです　みて　ください！\n"
	.string "この　すばらしい　さくひん　たちを！\p"
	.string "どれも　おたがいに\n"
	.string "ひけをとらない　すばらしさ！\p"
	.string "この　えの　おかげで　びじゅつかんに\n"
	.string "こられる　かたも　ふえたんです！\p"
	.string "ほんとうに　ありがとう　{PLAYER}さん！\n"
	.string "わたしの　ゆめが　かないました！$"

LilycoveCity_LilycoveMuseum_2F_Text_TokenOfGratitude: @ 0x0820670F
	.string "⋯⋯これは　わたしからの\n"
	.string "おれいの　きもち　です！$"

LilycoveCity_LilycoveMuseum_2F_Text_KeepThisForYou: @ 0x08206729
	.string "それでは　また　いらした　ときに\n"
	.string "さしあげましょう$"

LilycoveCity_LilycoveMuseum_2F_Text_HonorToHaveYouVisit: @ 0x08206743
	.string "やあ　これは　{PLAYER}さん！\p"
	.string "おいそがしい　たびの　あいまに\n"
	.string "おたちより　くださって　こうえいです！\p"
	.string "どうぞ　ごゆっくり　おすごしくださいね$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPinkPictureFrame: @ 0x08206788
	.string "ももいろの　かざりが　ついた　がくぶちだ！$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsYellowPictureFrame: @ 0x0820679E
	.string "きいろの　かざりが　ついた　がくぶちだ！$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsBluePictureFrame: @ 0x082067B3
	.string "あおい　かざりが　ついた　がくぶちだ！$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsRedPictureFrame: @ 0x082067C7
	.string "あかい　かざりが　ついた　がくぶちだ！$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsGreenPictureFrame: @ 0x082067DB
	.string "みどりいろの　かざりが　ついた　がくぶちだ！$"

LilycoveCity_LilycoveMuseum_2F_Text_ItsPaintingOfPokemon: @ 0x082067F2
	.string "ポケモンの　えが　かざってある！$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsSurprisedMe: @ 0x08206803
	.string "ひさしぶりに　きて　みたら　2かいにも\n"
	.string "えが　かざって　あって　びっくり！\p"
	.string "いいなあ　あたしの　ポケモンも\n"
	.string "こんなふうに　すてきに　かいて　ほしいな$"

LilycoveCity_LilycoveMuseum_2F_Text_NewPaintingsRatherAmusing: @ 0x0820684E
	.string "ほう⋯⋯　ここが　さいきん　わだいの\n"
	.string "ポケモンの　えが　ある　ところか⋯⋯\p"
	.string "なるほど　あたらしい　えが　いっぱいで\n"
	.string "なかなか　おもしろい　のう⋯⋯$"

LilycoveCity_LilycoveMuseum_2F_Text_ThesePaintingsOfYourPokemon: @ 0x08206898
	.string "へえー！　これって\n"
	.string "きみの　ポケモンの　えなんだ！\p"
	.string "それって　トレーナー　として\n"
	.string "さいこうの　しあわせ　だよな！$"
