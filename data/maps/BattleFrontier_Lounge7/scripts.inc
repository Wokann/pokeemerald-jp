@ BattleFrontier_Lounge7 scripts (JP map g26 m49 @ 0x08239778)

BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor:: @ 0x08239779
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor:: @ 0x0823979A
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove:: @ 0x082397A8
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	@ JP omits the US VAR_0x8006 redraw state and waits explicitly for this menu.
	special_no_wait ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, BattleFrontier_Lounge7_EventScript_Softboiled
	goto_if_eq VAR_0x8000, 0x1, BattleFrontier_Lounge7_EventScript_SeismicToss
	goto_if_eq VAR_0x8000, 0x2, BattleFrontier_Lounge7_EventScript_DreamEater
	goto_if_eq VAR_0x8000, 0x3, BattleFrontier_Lounge7_EventScript_MegaPunch
	goto_if_eq VAR_0x8000, 0x4, BattleFrontier_Lounge7_EventScript_MegaKick
	goto_if_eq VAR_0x8000, 0x5, BattleFrontier_Lounge7_EventScript_BodySlam
	goto_if_eq VAR_0x8000, 0x6, BattleFrontier_Lounge7_EventScript_RockSlide
	goto_if_eq VAR_0x8000, 0x7, BattleFrontier_Lounge7_EventScript_Counter
	goto_if_eq VAR_0x8000, 0x8, BattleFrontier_Lounge7_EventScript_ThunderWave
	goto_if_eq VAR_0x8000, 0x9, BattleFrontier_Lounge7_EventScript_SwordsDance
	goto_if_eq VAR_0x8000, 0xA, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	goto_if_eq VAR_0x8000, 0x7F, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove:: @ 0x0823984E
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	special_no_wait ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, BattleFrontier_Lounge7_EventScript_Softboiled
	goto_if_eq VAR_0x8000, 0x1, BattleFrontier_Lounge7_EventScript_SeismicToss
	goto_if_eq VAR_0x8000, 0x2, BattleFrontier_Lounge7_EventScript_DreamEater
	goto_if_eq VAR_0x8000, 0x3, BattleFrontier_Lounge7_EventScript_MegaPunch
	goto_if_eq VAR_0x8000, 0x4, BattleFrontier_Lounge7_EventScript_MegaKick
	goto_if_eq VAR_0x8000, 0x5, BattleFrontier_Lounge7_EventScript_BodySlam
	goto_if_eq VAR_0x8000, 0x6, BattleFrontier_Lounge7_EventScript_RockSlide
	goto_if_eq VAR_0x8000, 0x7, BattleFrontier_Lounge7_EventScript_Counter
	goto_if_eq VAR_0x8000, 0x8, BattleFrontier_Lounge7_EventScript_ThunderWave
	goto_if_eq VAR_0x8000, 0x9, BattleFrontier_Lounge7_EventScript_SwordsDance
	goto_if_eq VAR_0x8000, 0xA, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	goto_if_eq VAR_0x8000, 0x7F, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled:: @ 0x082398F1
	setvar VAR_0x8008, 0x10
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss:: @ 0x082398FC
	setvar VAR_0x8008, 0x18
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater:: @ 0x08239907
	setvar VAR_0x8008, 0x18
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch:: @ 0x08239912
	setvar VAR_0x8008, 0x18
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick:: @ 0x0823991D
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam:: @ 0x08239928
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide:: @ 0x08239933
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter:: @ 0x0823993E
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave:: @ 0x08239949
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance:: @ 0x08239954
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor:: @ 0x0823995F
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor:: @ 0x08239980
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove:: @ 0x0823998E
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	special_no_wait ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	goto_if_eq VAR_0x8000, 0x1, BattleFrontier_Lounge7_EventScript_Snore
	goto_if_eq VAR_0x8000, 0x2, BattleFrontier_Lounge7_EventScript_MudSlap
	goto_if_eq VAR_0x8000, 0x3, BattleFrontier_Lounge7_EventScript_Swift
	goto_if_eq VAR_0x8000, 0x4, BattleFrontier_Lounge7_EventScript_IcyWind
	goto_if_eq VAR_0x8000, 0x5, BattleFrontier_Lounge7_EventScript_Endure
	goto_if_eq VAR_0x8000, 0x6, BattleFrontier_Lounge7_EventScript_PsychUp
	goto_if_eq VAR_0x8000, 0x7, BattleFrontier_Lounge7_EventScript_IcePunch
	goto_if_eq VAR_0x8000, 0x8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	goto_if_eq VAR_0x8000, 0x9, BattleFrontier_Lounge7_EventScript_FirePunch
	goto_if_eq VAR_0x8000, 0xA, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	goto_if_eq VAR_0x8000, 0x7F, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove:: @ 0x08239A34
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	special_no_wait ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	copyvar VAR_0x8000, VAR_RESULT
	goto_if_eq VAR_0x8000, 0x0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	goto_if_eq VAR_0x8000, 0x1, BattleFrontier_Lounge7_EventScript_Snore
	goto_if_eq VAR_0x8000, 0x2, BattleFrontier_Lounge7_EventScript_MudSlap
	goto_if_eq VAR_0x8000, 0x3, BattleFrontier_Lounge7_EventScript_Swift
	goto_if_eq VAR_0x8000, 0x4, BattleFrontier_Lounge7_EventScript_IcyWind
	goto_if_eq VAR_0x8000, 0x5, BattleFrontier_Lounge7_EventScript_Endure
	goto_if_eq VAR_0x8000, 0x6, BattleFrontier_Lounge7_EventScript_PsychUp
	goto_if_eq VAR_0x8000, 0x7, BattleFrontier_Lounge7_EventScript_IcePunch
	goto_if_eq VAR_0x8000, 0x8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	goto_if_eq VAR_0x8000, 0x9, BattleFrontier_Lounge7_EventScript_FirePunch
	goto_if_eq VAR_0x8000, 0xA, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	goto_if_eq VAR_0x8000, 0x7F, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl:: @ 0x08239AD7
	setvar VAR_0x8008, 0x10
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore:: @ 0x08239AE2
	setvar VAR_0x8008, 0x18
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap:: @ 0x08239AED
	setvar VAR_0x8008, 0x18
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift:: @ 0x08239AF8
	setvar VAR_0x8008, 0x18
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind:: @ 0x08239B03
	setvar VAR_0x8008, 0x18
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure:: @ 0x08239B0E
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp:: @ 0x08239B19
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch:: @ 0x08239B24
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch:: @ 0x08239B2F
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch:: @ 0x08239B3A
	setvar VAR_0x8008, 0x30
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect:: @ 0x08239B45
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon:: @ 0x08239B55
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection:: @ 0x08239B5F
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove:: @ 0x08239BA6
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen 0x1
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove:: @ 0x08239BDA
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor:: @ 0x08239BEB
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman:: @ 0x08239BF4
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "ぶはははっ！\p"
	.string "あたしゃ　こうみえても　わかいころは\n"
	.string "そりゃー　つよい　トレーナーでよー\p"
	.string "さいきょうの　おとなの　おねえさんと　して\n"
	.string "もー　バリバリ　いわしとったわ！\p"
	.string "⋯⋯　⋯　⋯⋯ん？\p"
	.string "なんじゃ　あんた　しんじとらんのかっ！？\p"
	.string "あたしゃ　むこうの　くちだけ　ばあさんとは\n"
	.string "さいのうが　ちがうんじゃっ！\p"
	.string "しょうこに　あんたの　ポケモンに\n"
	.string "すぺしゃる　かつ　きゅーとな　わざの\l"
	.string "かずかずを　おしえたろうかいなっ！！\p"
	.string "まあ　じゅぎょうりょう　ちゅう　ことで\n"
	.string "ちいと　ばかし　バトルポイントを\l"
	.string "いただくがのう！$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "ぶはははっ！\p"
	.string "あたしゃの\n"
	.string "すぺしゃる　かつ　きゅーとな　わざを\l"
	.string "おそわりに　きたんかー！？$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "ほれほれー　どのわざを　おぼえたいんじゃ？$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "{STR_VAR_1}　が　ええのんか！\n"
	.string "{STR_VAR_2}　BP　じゃが　ええんじゃの！？$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "ほいじゃあ　わざを　おぼえさせる\n"
	.string "ポケモンを　きめて　おくれ！$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "なんじゃ⋯⋯\n"
	.string "あんた　バトルポイントが　たりんぞ！$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "あたしゃの　すごさが　わかったかいっ！！\n"
	.string "じゃあ　バトルポイントは　いただくぞぃ！$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "なんじゃ？　やめるんか⋯⋯\p"
	.string "あたしゃの　すごさを　しりたかったら\n"
	.string "いつでも　くるが　ええぞぃ！$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "いひひひっ！\p"
	.string "あたしゃ　こうみえても　わかいころは\n"
	.string "そりゃー　つよい　トレーナーでよー\p"
	.string "むてきの　ビキニの　おねえさんと　して\n"
	.string "もー　ブイブイ　いわしとったわ！\p"
	.string "⋯⋯　⋯⋯　⋯⋯ん？\p"
	.string "なんじゃ　あんた　しんじとらんのかっ！？\p"
	.string "あたしゃ　むこうの　くちだけ　ばあさんと\n"
	.string "ちがって　じつりょくが　あるんじゃっ！\p"
	.string "しょうこに　あんたの　ポケモンに\n"
	.string "はーど　かつ　ぷりてぃな　わざの\l"
	.string "かずかずを　おしえたろうかいなっ！\p"
	.string "まあ　じゅぎょうりょう　ちゅう　ことで\n"
	.string "ちいと　ばかし　バトルポイントを\l"
	.string "いただくがのう！$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "いひひひっ！\p"
	.string "あたしゃの\n"
	.string "はーど　かつ　ぷりてぃな　わざを\l"
	.string "おそわりに　きたんかー！？$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "あの　ふたりって　おたがいの\n"
	.string "わるぐち　いい　あってる　から\l"
	.string "なかが　わるいとか　おもって　ないか？\p"
	.string "でも　ほんとに　そう　だったら　いっしょに\n"
	.string "こんなところに　いたり　しないよな$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "わたしが　まだ　たんぱんこぞう　だったころ\n"
	.string "つよく　うつくしい　かのじょ　たちは\l"
	.string "トレーナー　みんなの　アイドル　でした\p"
	.string "いまも　その　わざの　キレは\n"
	.string "おとろえる　どころか\l"
	.string "ますます　みがきが　かかっている　ようです\p"
	.string "だが⋯⋯　なぜか　こう　おもうのです⋯⋯\p"
	.string "じかんと　いうものは\n"
	.string "ざんこくな　もの　ですね⋯⋯$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "キズついた　からだを\n"
	.string "たいりょくの\n"
	.string "はんぶん　かいふく$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "いんりょくを　りよう\n"
	.string "レベル　ぶんの\n"
	.string "ダメージを　あたえる$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "ねている　てきに\n"
	.string "あたえた　ダメージの\n"
	.string "はんぶんを　かいふく$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "ものすごい　ちからを\n"
	.string "こめた　パンチで\n"
	.string "てきを　こうげき$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "ものすごい　ちからを\n"
	.string "こめた　キックで\n"
	.string "てきを　こうげき$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "たおれこみ　こうげき\n"
	.string "てきを　まひ　させる\n"
	.string "ことが　ある$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "いわで　こうげき\n"
	.string "てきを　ひるませる\n"
	.string "ことが　ある$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "ぶつりこうげきの\n"
	.string "ダメージを\n"
	.string "ばいにして　かえす$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "よわい　でんげきを\n"
	.string "ぶつけて　あいてを\n"
	.string "まひ　させる$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "たたかいの　おどりで\n"
	.string "こうげきを　グーンと\n"
	.string "あげる$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "からだを　まるめて\n"
	.string "ぼうぎょを　あげる$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "ねている　とき　だけ\n"
	.string "つかえる　わざ\n"
	.string "いびきで　こうげき$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "ドロを　かけて\n"
	.string "めいちゅうりつを\n"
	.string "さげる$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "だれも　よけることの\n"
	.string "できない　ほしがたの\n"
	.string "こうせんで　こうげき$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "すごい　れいきで\n"
	.string "こうげき\n"
	.string "すばやさを　さげる$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "そのターンで\n"
	.string "こうげき　されても\n"
	.string "たいりょくが1のこる$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "あいての\n"
	.string "ほじょこうかを\n"
	.string "じぶんに　コピーする$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "つめたい　パンチで\n"
	.string "てきを　こおらせる\n"
	.string "ことが　ある$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "でんげき　パンチで\n"
	.string "てきを　まひさせる\n"
	.string "ことが　ある$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "ほのおの　パンチで\n"
	.string "てきを　やけどさせる\n"
	.string "ことが　ある$"
