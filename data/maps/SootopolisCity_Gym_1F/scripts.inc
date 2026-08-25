@ SootopolisCity_Gym_1F scripts (JP map g15 m0 @ 0x0820E224)

SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:: @ 0x0820E239
	setvar VAR_ICE_STEP_COUNT, 0x1
	end

SootopolisCity_Gym_1F_OnResume:: @ 0x0820E23F
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:: @ 0x0820E242
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles:: @ 0x0820E24B
	goto_if_lt VAR_ICE_STEP_COUNT, 0x8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 0x1C, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 0x43, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 0x8, 0x4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 0x8, 0x5, METATILE_SootopolisGym_Stairs, FALSE

SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs:: @ 0x0820E27E
	setmetatile 0x8, 0xA, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 0x8, 0xB, METATILE_SootopolisGym_Stairs, FALSE

SootopolisCity_Gym_1F_EventScript_OpenFirstStairs:: @ 0x0820E290
	setmetatile 0x8, 0xF, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 0x8, 0x10, METATILE_SootopolisGym_Stairs, FALSE

SootopolisCity_Gym_1F_EventScript_StopCheckingStairs:: @ 0x0820E2A2
	return

SootopolisCity_Gym_1F_OnFrame:: @ 0x0820E2A3
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs:: @ 0x0820E2C5
	addvar VAR_ICE_STEP_COUNT, 0x1
	delay 0x28
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs:: @ 0x0820E2D9
	addvar VAR_ICE_STEP_COUNT, 0x1
	delay 0x28
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs:: @ 0x0820E2ED
	addvar VAR_ICE_STEP_COUNT, 0x1
	delay 0x28
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce:: @ 0x0820E301
	lockall
	delay 0x14
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 0x3C
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan:: @ 0x0820E31C
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated:: @ 0x0820E35A
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 0x6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 0x8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 0x1E
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 0x1E
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse:: @ 0x0820E3AC
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2:: @ 0x0820E3CF
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge:: @ 0x0820E3F3
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch:: @ 0x0820E3FD
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide:: @ 0x0820E418
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory:: @ 0x0820E42D
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue:: @ 0x0820E437
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue:: @ 0x0820E447
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified:: @ 0x0820E457
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue:: @ 0x0820E461
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice: @ 0x0820E46B
	.string "げんき　しとぉや！！\n"
	.string "チャンピオンを　めざす　{PLAYER}！！\p"
	.string "ルネシティの　ジムリーダー　アダンは\n"
	.string "みずタイプ　ポケモンを　つかいこなす！\p"
	.string "そして　アダンがいる　ところ　までは\n"
	.string "こおりの　ゆかが　ゆくてを　さえぎる⋯⋯\p"
	.string "ごめんな！　きみに　おしえて\n"
	.string "あげられるのは　ここまで　なんだ⋯⋯！\p"
	.string "あとは　じぶんで　きばってくれッ！$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory: @ 0x0820E50B
	.string "ホウエンで　いちばん　つよいと　いわれる\n"
	.string "アダンに　かったのかあ！！\p"
	.string "よし！　きみの\n"
	.string "トレーナーカードを　みたまえ！\p"
	.string "すべての　バッジが　そろっているなら\n"
	.string "いよいよ　ポケモンリーグ　ちょうせんだ！$"

SootopolisCity_Gym_1F_Text_JuanIntro: @ 0x0820E56E
	.string "ユーは　しっていますか？\p"
	.string "ミクリに　ポケモンを　おしえたのは\n"
	.string "なにをかくそう　このアダン⋯⋯\l"
	.string "すなわち　わたくし　だということを\p"
	.string "いちどは　ジムリーダーから　みをひき\n"
	.string "このジムも　かれに　まかせて　いましたが\l"
	.string "ちょっとした　リーズン⋯⋯\l"
	.string "すなわち　りゆうが　できましてね\l"
	.string "もういちど　カムバック　したのです\p"
	.string "⋯⋯おっと\n"
	.string "おしゃべりは　これくらいにして\l"
	.string "そろそろ　しょうぶを　はじめましょう\p"
	.string "さあ　ぞんぶんに　ごらんなさい\n"
	.string "わたしと　ポケモンが　おりなす\l"
	.string "みずの　イリュージョンを！$"

SootopolisCity_Gym_1F_Text_JuanDefeat: @ 0x0820E65F
	.string "たははは！　ユー　アー　ウィナー！\n"
	.string "すなわち　わたくしの　まけです\p"
	.string "ユーには　だれにも　まけない\n"
	.string "さいのうの　きらめきが　かんじられます！\p"
	.string "しかし　わたくしや　ミクリに　くらべると\n"
	.string "ちょっと　はなやかさが　たりませんな！\p"
	.string "わたしの　ふくでも\n"
	.string "かして　あげましょうか？\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "はっはっは　ジョークですよ！\n"
	.string "ユーには　ふくの　かわりに\l"
	.string "この　レインバッジを　さしあげましょう！$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge: @ 0x0820E729
	.string "{PLAYER}は　アダンから\n"
	.string "レインバッジを　もらった！$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis: @ 0x0820E741
	.string "レインバッジを　もっていると\n"
	.string "すべての　ポケモンが\l"
	.string "ユーに　たいして　すなおに　なるでしょう\p"
	.string "はげしく　ながれる　たきも\n"
	.string "ひでんわざ　たきのぼりを　つかって\l"
	.string "のぼれる　ように　してくれます\p"
	.string "それから　わたくしとの　しょうぶを\n"
	.string "わすれないように　これを⋯⋯$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse: @ 0x0820E7C1
	.string "ユーに　わたした　その　わざマシン\n"
	.string "なかみは　みずのはどう\p"
	.string "つかうと　ときおり　ちょうおんぱで\n"
	.string "あいてを　こんらん　させるのです！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

SootopolisCity_Gym_1F_Text_RegisteredJuan: @ 0x0820E80C
	.string "ジムリーダー　アダンを\n"
	.string "ポケナビに　とうろく　した！$"

SootopolisCity_Gym_1F_Text_JuanPostBattle: @ 0x0820E827
	.string "ホウエンで　あつめられる\n"
	.string "すべての　ジムバッジを　てにいれた\l"
	.string "トレーナーが　いくべき　ばしょ\p"
	.string "それが　ポケモンリーグ\p"
	.string "ポケモンリーグに　いくならば\n"
	.string "ホウエンちほうの　さいはて\l"
	.string "サイユウという　しまに　むかうのです$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge: @ 0x0820E892
	.string "ホウエンで　あつめられる\n"
	.string "ジムバッジは　あと　ひとつ\p"
	.string "ユーが　ポケモンリーグに　いどむ　つもりなら\n"
	.string "ヒワマキの　ポケモンジムで\l"
	.string "のこりの　バッジを　てにいれるのです$"

SootopolisCity_Gym_1F_Text_GymStatue: @ 0x0820E8E5
	.string "ルネシティ　ポケモンジム$"

SootopolisCity_Gym_1F_Text_GymStatueCertified: @ 0x0820E8F2
	.string "ルネシティ　ポケモンジム\p"
	.string "アダン　にんてい　トレーナー！\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch: @ 0x0820E912
	.string "アダン“いつもの　サイレンス⋯⋯\n"
	.string "しずけさを　とりもどした　このジムに\p"
	.string "またもや　わかき　タイフーンが\n"
	.string "うでだめしに　あらわれましたね！\p"
	.string "いいですとも！\p"
	.string "なんどでも　ユーの　あいてを\n"
	.string "して　さしあげましょう！$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat: @ 0x0820E97B
	.string "たははは！　ユー　アー　ウィナー！\n"
	.string "またしても　わたくしの　まけです$"

SootopolisCity_Gym_1F_Text_JuanPostRematch: @ 0x0820E99E
	.string "アダン“わたしの　でしに　なれと　いっても\n"
	.string "きっと　ユーは　ことわる　でしょうね\p"
	.string "せめて　わたしが　きている　コートを\n"
	.string "プレゼント　したいの　ですが⋯⋯\l"
	.string "おそらく　ユーは　うけとらない　でしょう\p"
	.string "それが　ジェントルマン　というものです\n"
	.string "ほっほっほっほ！$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons: @ 0x0820EA1D
	.string "アダン“いつもの　サイレンス⋯⋯\n"
	.string "しずけさを　とりもどした　このジムに\p"
	.string "またもや　わかき　タイフーンが\n"
	.string "うでだめしに　あらわれましたね！\p"
	.string "いいですとも！\n"
	.string "なんどでも　ユーの　あいてを⋯⋯\p"
	.string "⋯⋯アハン？\n"
	.string "ユーは　たたかえる　ポケモンを\l"
	.string "1ひきしか　もっていない　ようですね\p"
	.string "ねがわくば　2ひき　いじょうの\n"
	.string "ポケモンを　もってきて　プリーズ$"
