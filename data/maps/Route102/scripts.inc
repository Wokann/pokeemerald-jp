@ Route102 scripts (JP map g0 m17 @ 0x081E6824)

Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0x0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_WatchMeCatchPokemon: @ 0x081E693C
	.string "ミツル“{PLAYER}さん⋯⋯\n"
	.string "ポケモンって　こういう　くさむらに\l"
	.string "いたり　するんでしょ⋯⋯？\p"
	.string "ぼくが　じょうずに　つかまえられるか\n"
	.string "そこで　みてて　くださいね⋯⋯\p"
	.string "⋯⋯うわっ！！$"

Route102_Text_WallyIDidIt: @ 0x081E6992
	.string "ミツル“やった⋯⋯　ぼくの⋯⋯\n"
	.string "ぼくの　ポケモンだ⋯⋯！！$"

Route102_Text_LetsGoBack: @ 0x081E69B0
	.string "{PLAYER}さん　ありがとう！\n"
	.string "ジムに　もどろうよ！$"

Route102_Text_ImNotVeryTall: @ 0x081E69C7
	.string "ぼく⋯⋯　せが　ひくいから\n"
	.string "くさむらを　あるくと　もぐっちゃうんだ\p"
	.string "ハッパが　はなの　あなに　はいって\n"
	.string "ふぁ　ふぁ　ふぁ　ふぁ⋯⋯\p"
	.string "ぶわっくしょーん！$"

Route102_Text_CatchWholeBunchOfPokemon: @ 0x081E6A13
	.string "ポケモン　たくさん　つかまえよーっと！$"

Route102_Text_RouteSignOldale: @ 0x081E6A27
	.string "ここは　102ばん　どうろ\n"
	.string "{ESCAPE 0x03}　コトキタウン$"

Route102_Text_RouteSignPetalburg: @ 0x081E6A40
	.string "ここは　102ばん　どうろ\n"
	.string "{ESCAPE 0x02}　トウカシティ$"
