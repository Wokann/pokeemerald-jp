@ PetalburgWoods scripts (JP map g24 m11 @ 0x08214278)

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft:: @ 0x08214279
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight:: @ 0x0821431B
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro:: @ 0x082143C6
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle:: @ 0x082143DA
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull:: @ 0x0821441F
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish:: @ 0x0821442D
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher:: @ 0x08214449
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 0x1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1:: @ 0x082144B2
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2:: @ 0x082144BB
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl:: @ 0x082144C4
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed:: @ 0x082144F3
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1:: @ 0x082144FD
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2:: @ 0x08214506
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle:: @ 0x0821450F
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James:: @ 0x08214526
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, 0x0, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames:: @ 0x08214567
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames:: @ 0x08214578
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2:: @ 0x08214591
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2:: @ 0x082145A4
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch:: @ 0x082145BD
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound: @ 0x082145D4
	.string "うーん\n"
	.string "いないなあ⋯⋯$"

PetalburgWoods_Text_HaveYouSeenShroomish: @ 0x082145E0
	.string "ねえ　きみきみ　このあたりで\n"
	.string "キノココって　ポケモン　みなかった？\p"
	.string "おじさん　あの　ポケモン　すき　なのよね$"

PetalburgWoods_Text_IWasGoingToAmbushYou: @ 0x08214617
	.string "まちぶせ　していたのに\n"
	.string "いつまでも　トウカのもりで　うろうろと⋯⋯\p"
	.string "まちくたびれたから　きてやったぞ！$"

PetalburgWoods_Text_HandOverThosePapers: @ 0x0821464B
	.string "やい！　デボンの　けんきゅういん！\p"
	.string "その　しょるいを　こっちに　よこしやがれ！$"

PetalburgWoods_Text_YouHaveToHelpMe: @ 0x08214673
	.string "ひやー！\p"
	.string "きみ　ポケモントレーナー　だよね\n"
	.string "おじさんを　たすけてよぉ$"

PetalburgWoods_Text_NoOneCrossesTeamAqua: @ 0x08214696
	.string "⋯⋯ん？　なんだ　おまえ？\n"
	.string "そいつを　かばおう　ってのか？\p"
	.string "アクアだんの　じゃまを　する　やつは\n"
	.string "こどもでも　ようしゃ　しねえ！\l"
	.string "しょうぶ　しやがれ！$"

PetalburgWoods_Text_YoureKiddingMe: @ 0x082146E2
	.string "⋯⋯つ　つよい　じゃねーか！$"

PetalburgWoods_Text_YouveGotSomeNerve: @ 0x082146F1
	.string "むむむ⋯⋯　アクアだんの\n"
	.string "じゃまを　するとは　なんて　やつ！\l"
	.string "もう　いっかい　しょうぶ　しろ！\p"
	.string "⋯⋯と　いいたい　ところ　だが\n"
	.string "もう　てもちの　ポケモンは　いない\p"
	.string "それに　カナズミ　シティにも　アクアだんが\n"
	.string "ねらっている　ものが　あるからな！\p"
	.string "きょうは　これぐらいに　しといてやらぁ！$"

PetalburgWoods_Text_ThatWasAwfullyClose: @ 0x08214780
	.string "⋯⋯ふぅ\n"
	.string "あぶない　ところ　だった！\p"
	.string "きみの　おかげで　だいじな　しょるいを\n"
	.string "うばわれないで　すんだよ！\p"
	.string "⋯⋯そうだ！　おれいに\n"
	.string "スーパーボールを　あげちゃおう！$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro: @ 0x082147D2
	.string "⋯⋯そういえば　さっき　アクアだんは\n"
	.string "‘カナズミにも　ねらっている　ものがある’\l"
	.string "とか　いってたよね⋯⋯？$"

PetalburgWoods_Text_ICantBeWastingTime: @ 0x08214808
	.string "たいへんだ！！\n"
	.string "こうしちゃ　いられない！$"

PetalburgWoods_Text_YoureLoadedWithItems: @ 0x0821481D
	.string "どうぐ　いっぱいで\n"
	.string "スーパーボール　あげられないね$"

PetalburgWoods_Text_GoBugPokemonTeam: @ 0x08214837
	.string "ポケモン　いっぱい　つかまえた！\p"
	.string "そら　いけ！\n"
	.string "ぼくの　むしポケモン　チーム！$"

PetalburgWoods_Text_ICouldntWin: @ 0x0821485F
	.string "こんなに　ポケモン　いるのに\n"
	.string "かてなかったのか⋯⋯$"

PetalburgWoods_Text_ImOutOfPokeBalls: @ 0x08214879
	.string "たくさん　ポケモン　つかまえたら\n"
	.string "モンスターボール　なくなっちゃったよ$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon: @ 0x0821489D
	.string "むしポケモンを　がっこうに　もっていくと\n"
	.string "それだけで　にんきもの　だろ！？$"

PetalburgWoods_Text_CantBePopularIfILose: @ 0x082148C3
	.string "まけると　にんきものに　なれないや$"

PetalburgWoods_Text_PeopleRespectYou: @ 0x082148D5
	.string "でかい　むしポケモン　もってると\n"
	.string "それだけで　そんけー　されるだろ！？$"

PetalburgWoods_Text_IWantRematch1: @ 0x082148F9
	.string "むしポケモン　そだったら　また　しょうぶだ！\n"
	.string "ポケナビに　とうろく　するぞ$"

PetalburgWoods_Text_IWantRematch2: @ 0x0821491F
	.string "むしポケモン　そだったら　また　しょうぶだ！\n"
	.string "ポケナビに　とうろく　するぞ$"

PetalburgWoods_Text_MyPokemonHaveGrown: @ 0x08214945
	.string "ぼくの　むしポケモン　そだったぞ！\n"
	.string "これで　また　にんきもの　だぜ！$"

PetalburgWoods_Text_CantBePopularIfLose: @ 0x08214968
	.string "まけると　にんきものに　なれないや$"

PetalburgWoods_Text_IveBeenTrainingHard: @ 0x0821497A
	.string "つよい　ポケモン　もってると\n"
	.string "にんきものに　なれるだろ？\l"
	.string "だから　がんばって　そだててるのさ！$"

PetalburgWoods_Text_StayOutOfTallGrass: @ 0x082149AA
	.string "よお！　おまえの　ポケモン　げんき？\p"
	.string "てもちの　ポケモンが　よわっていて\n"
	.string "たたかわせたく　ないときは　なるべく\l"
	.string "くさむらを　よけて　あるくと　いいよ！$"

PetalburgWoods_Text_HiddenItemsExplanation: @ 0x082149F6
	.string "みえて　いなくても\n"
	.string "どうぐが　おちてることが　あるから\l"
	.string "あしもとを　しらべて　いるんだ！$"

PetalburgWoods_Text_TryUsingThisItem: @ 0x08214A23
	.string "それって　カナズミの　ジムバッジ！\p"
	.string "あなた　トレーナーなのね\n"
	.string "この　どうぐ　つかってみたら　どうかしら？$"

PetalburgWoods_Text_MiracleSeedExplanation: @ 0x08214A58
	.string "きせきのタネを\n"
	.string "ポケモンに　もたせてあげると　くさタイプの\l"
	.string "わざの　いりょくが　あがるのよ\p"
	.string "きせきのタネの　ほかにも\n"
	.string "ポケモンに　もたせると　べんりな\l"
	.string "どうぐが　あるらしいわね$"

PetalburgWoods_Text_TrainerTipsExperience: @ 0x08214AB1
	.string "おとくな　けいじばん！！\p"
	.string "しょうぶの　とき\n"
	.string "いちど　でも　かおをだした　ポケモンは\l"
	.string "けいけんちが　もらえます！\p"
	.string "よわい　ポケモンを　リストの　ひだりにして\n"
	.string "しょうぶのとき　すぐに　こうたい！\l"
	.string "これで　よわい　ポケモンも　そだちます！$"

PetalburgWoods_Text_TrainerTipsPP: @ 0x08214B26
	.string "おとくな　けいじばん！！\p"
	.string "ポケモンには　ヒットポイントの　ほかに\n"
	.string "わざを　くりだす　ちからの　もと\l"
	.string "パワーポイント　というものが　あります\p"
	.string "わざの　パワーポイントが　なくなったときも\n"
	.string "ポケモンセンターに　いきましょう！$"
