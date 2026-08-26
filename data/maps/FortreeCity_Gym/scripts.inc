@ FortreeCity_Gym scripts (JP map g12 m1 @ 0x0820439E)

FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3.

FortreeCity_Gym_OnTransition:: @ 0x082043A9
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:: @ 0x082043AD
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

FortreeCity_Gym_EventScript_InitRotatingGates:: @ 0x082043B7
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona:: @ 0x082043BB
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated:: @ 0x082043F0
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2:: @ 0x08204439
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce:: @ 0x0820445D
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch:: @ 0x08204480
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared:: @ 0x0820449B
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo:: @ 0x082044B2
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint:: @ 0x082044C9
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley:: @ 0x082044E0
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto:: @ 0x082044F7
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius:: @ 0x0820450E
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide:: @ 0x08204525
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory:: @ 0x0820453A
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue:: @ 0x08204544
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue:: @ 0x08204554
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified:: @ 0x08204564
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue:: @ 0x0820456E
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice: @ 0x08204578
	.string "げんき　しとぉや！！\n"
	.string "チャンピオンを　めざす　{PLAYER}！！\p"
	.string "ヒワマキシティ　ジムの　リーダー　ナギは\n"
	.string "ひこうタイプ　ポケモンの　つかいてだ！\p"
	.string "この　かいてんとびら　だらけの\n"
	.string "ジムの　おくで\p"
	.string "かのじょは　あらたな　チャレンジャーが\n"
	.string "はばたこうと　するのを　まっている！\p"
	.string "じゃ　きばってこォー！！$"

FortreeCity_Gym_Text_GymGuidePostVictory: @ 0x08204609
	.string "えんやっと　きみは　はばたいたッ！$"

FortreeCity_Gym_Text_JaredIntro: @ 0x0820461B
	.string "かれいな　とりポケモンの　たたかいを\n"
	.string "みせて　やるぜっ！$"

FortreeCity_Gym_Text_JaredDefeat: @ 0x08204638
	.string "きみ⋯⋯　つよいんだな⋯⋯$"

FortreeCity_Gym_Text_JaredPostBattle: @ 0x08204646
	.string "トレーナーは　あたまの　かいてんも\n"
	.string "はやく　なければ　つとまらないぜ！\p"
	.string "きみは　リーダーの　ところまで\n"
	.string "ちゃんと　たどりつく　ことが　できるかい？$"

FortreeCity_Gym_Text_EdwardoIntro: @ 0x08204690
	.string "とりポケモンを　あいする　ものは\n"
	.string "この　ジムを　もくひょうと　している！\p"
	.string "ヒワマキ　ジムの　いちいん　として\n"
	.string "まける　わけには　いかないんだ！$"

FortreeCity_Gym_Text_EdwardoDefeat: @ 0x082046D8
	.string "オレには　にが　おもすぎたか⋯⋯！$"

FortreeCity_Gym_Text_EdwardoPostBattle: @ 0x082046EA
	.string "せかいは　ひろい\n"
	.string "つよい　トレーナーは　たくさん　いる\p"
	.string "オレも　ここで　しゅぎょうを　つづけて\n"
	.string "つよくなって　みせるよ！$"

FortreeCity_Gym_Text_FlintIntro: @ 0x08204727
	.string "ジムリーダーの　ナギさんの\n"
	.string "てを　わずらわせるまでも　ない！\p"
	.string "きみの　あいては　オレで　じゅうぶん！$"

FortreeCity_Gym_Text_FlintDefeat: @ 0x0820475A
	.string "ナギさん⋯⋯　まけました⋯⋯！$"

FortreeCity_Gym_Text_FlintPostBattle: @ 0x0820476A
	.string "ナギさんは　かわいくて　つよい⋯⋯\n"
	.string "ほんと　さいこうの　リーダーだよ！\p"
	.string "⋯⋯ポッ$"

FortreeCity_Gym_Text_AshleyIntro: @ 0x08204793
	.string "ナギさんの　おしえを　うけた　あたし！\n"
	.string "そう　かんたんに　たおされないわ！$"

FortreeCity_Gym_Text_AshleyDefeat: @ 0x082047B9
	.string "たおされ　ちゃった⋯⋯$"

FortreeCity_Gym_Text_AshleyPostBattle: @ 0x082047C5
	.string "ナギさんが　いてくれるから\n"
	.string "ヒワマキの　ひとは　あんしんして　くらせるの$"

FortreeCity_Gym_Text_HumbertoIntro: @ 0x082047EA
	.string "ナギさまが　たたかわれる　ときの\n"
	.string "あの　りりしい　おかお⋯⋯\p"
	.string "おまえ　なんかにゃ　みせられないぜ！$"

FortreeCity_Gym_Text_HumbertoDefeat: @ 0x0820481C
	.string "うう！\n"
	.string "おれでは　とめられ　なかった$"

FortreeCity_Gym_Text_HumbertoPostBattle: @ 0x0820482F
	.string "ナギさまに　みとれて\n"
	.string "ボロまけ　しないように\l"
	.string "ちゅういするんだな！$"

FortreeCity_Gym_Text_DariusIntro: @ 0x08204851
	.string "ひこうタイプ　って　いっても\n"
	.string "いろんな　ポケモンが　いるんだぜ！\l"
	.string "おまえ　それ　わかってる？$"

FortreeCity_Gym_Text_DariusDefeat: @ 0x08204880
	.string "なかなか　わかってるな！$"

FortreeCity_Gym_Text_DariusPostBattle: @ 0x0820488D
	.string "ぼくは　まけたけど\n"
	.string "ナギ　リーダーの　ポケモンは\l"
	.string "ほんと　てごわいぞ！$"

FortreeCity_Gym_Text_WinonaIntro: @ 0x082048B1
	.string "わたしは　この　ヒワマキ　ジムで\n"
	.string "リーダーを　している　ナギ⋯⋯\p"
	.string "とりポケモンと　こころを　かよわし\n"
	.string "いっしょに　おおぞらを　まい⋯⋯\p"
	.string "どんな　くるしい　しょうぶも\n"
	.string "ゆうがに　かってみせる⋯⋯\p"
	.string "さあ　わたしと　ポケモンが　おりなす\n"
	.string "かれいな　まいを　みせましょう！$"

FortreeCity_Gym_Text_WinonaDefeat: @ 0x08204936
	.string "わたしより　かれいに\n"
	.string "ポケモンを　たたかわせる　ひと⋯⋯\l"
	.string "はじめて　であいました⋯⋯\p"
	.string "その　じつりょくを　みとめ\n"
	.string "この　ジムバッジを　おわたしします！$"

FortreeCity_Gym_Text_ReceivedFeatherBadge: @ 0x08204982
	.string "{PLAYER}は　ナギから\n"
	.string "フェザーバッジを　もらった！$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis: @ 0x0820499A
	.string "フェザーバッジを　つけてると\n"
	.string "ひとから　もらった　ポケモンでも\l"
	.string "レベル70までの　ポケモンなら\l"
	.string "いうことを　すなおに　きいてくれます！\p"
	.string "ひでんわざの　そらをとぶ　を\n"
	.string "つかえる　ようにも　なります！\p"
	.string "そして　これを\n"
	.string "あなたに　プレゼント　します$"

FortreeCity_Gym_Text_ExplainAerialAce: @ 0x08204A14
	.string "わざマシン40の　なかみは\n"
	.string "つばめがえし！\p"
	.string "その　すばやさ⋯⋯\n"
	.string "どんな　ポケモンでも\l"
	.string "よけることは　できないでしょう！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

FortreeCity_Gym_Text_RegisteredWinona: @ 0x08204A59
	.string "ジムリーダー　ナギを\n"
	.string "ポケナビに　とうろく　した！$"

FortreeCity_Gym_Text_WinonaPostBattle: @ 0x08204A73
	.string "あなたには　まけました　けど\p"
	.string "わたしは　これからも\n"
	.string "とりポケモンに　こだわって　いきます$"

FortreeCity_Gym_Text_GymStatue: @ 0x08204AA0
	.string "ヒワマキシティ　ポケモンジム$"

FortreeCity_Gym_Text_GymStatueCertified: @ 0x08204AAF
	.string "ヒワマキシティ　ポケモンジム\p"
	.string "ナギ　にんてい　トレーナー！\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch: @ 0x08204AD0
	.string "ナギ“ひとは　ちじょうに　いる　かぎり\n"
	.string "いんりょくから　のがれることは　できない\p"
	.string "でも　ぜんりょくで　はばたけば\n"
	.string "そらを　とぶことは　できるのです\p"
	.string "チャンピオンにまで　のぼりつめた\n"
	.string "あなたの　じつりょく\l"
	.string "もういちど　みせて　いただきますわ！$"

FortreeCity_Gym_Text_WinonaRematchDefeat: @ 0x08204B49
	.string "やはり　とどかなかった⋯⋯$"

FortreeCity_Gym_Text_WinonaPostRematch: @ 0x08204B57
	.string "ナギ“たとえ　しょうぶに　まけても\n"
	.string "こころの　つばさが　おれて　いなければ\l"
	.string "なんどでも　うかび　あがれる⋯⋯\p"
	.string "わたしは　そう　しんじて　いますよ！$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons: @ 0x08204BA1
	.string "ナギ“ひとは　ちじょうに　いる　かぎり\n"
	.string "いんりょくから　のがれることは　できない\p"
	.string "でも　ぜんりょくで　はばたけば\n"
	.string "そらを　とぶことは　できるのです\p"
	.string "チャンピオンにまで　のぼりつめた\n"
	.string "あなたの　じつりょく\l"
	.string "もういちど　みせて　いただきますわ！\n"
	.string "⋯⋯あら？　たたかえる　ポケモンを\n"
	.string "1ひきしか　もっていませんね\p"
	.string "せめて　2ひき　いじょうの\n"
	.string "ポケモンを　もって　また　きてください$"
