@ RustboroCity_PokemonSchool scripts (JP map g11 m4 @ 0x08202C1A)

RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard:: @ 0x08202C1B
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic:: @ 0x08202C2A
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison:: @ 0x08202C89
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis:: @ 0x08202C97
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep:: @ 0x08202CA5
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn:: @ 0x08202CB3
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze:: @ 0x08202CC1
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect:: @ 0x08202CCF
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1:: @ 0x08202CD1
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2:: @ 0x08202CDA
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy:: @ 0x08202CE3
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass:: @ 0x08202CEC
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM:: @ 0x08202CF5
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook:: @ 0x08202CFE
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher:: @ 0x08202D07
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast:: @ 0x08202D57
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest:: @ 0x08202D62
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw:: @ 0x08202D6D
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott:: @ 0x08202DB2
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready:: @ 0x08202DE1
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge:: @ 0x08202DF4
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge:: @ 0x08202E02
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge:: @ 0x08202E10
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents:: @ 0x08202E1A
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges: @ 0x08202E24
	.string "こくばんに\n"
	.string "ポケモンが　たたかってるときに　おこる\l"
	.string "たいちょうの　へんかに　ついて　かかれてる$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic: @ 0x08202E54
	.string "どの　こうもくを　みますか？$"

RustboroCity_PokemonSchool_Text_ExplainPoison: @ 0x08202E63
	.string "どくを　うけると\n"
	.string "たいりょくが　へっていきます\p"
	.string "せんとうのあとも　どくは　のこるので\n"
	.string "あるくたびに　たいりょくが　へります\l"
	.string "どくけしで　なおしましょう$"

RustboroCity_PokemonSchool_Text_ExplainParalysis: @ 0x08202EAF
	.string "まひすると　すばやさが　さがり\n"
	.string "ときどき　わざが　だせなくなります\p"
	.string "たたかい　おわっても　まひした　ままです\n"
	.string "まひなおしで　なおしましょう$"

RustboroCity_PokemonSchool_Text_ExplainSleep: @ 0x08202EF5
	.string "ねむって　しまうと\n"
	.string "その　あいだ　こうげき　できません\p"
	.string "じぶんで　めざめることも　ありますが\n"
	.string "ねむったまま　せんとうが　おわると\l"
	.string "ずっと　ねむっています\p"
	.string "ねむけざましで　おこして　あげましょう$"

RustboroCity_PokemonSchool_Text_ExplainBurn: @ 0x08202F56
	.string "やけどは　こうげきりょくが　さがるだけでなく\n"
	.string "たいりょくも　どんどん　へっていきます\p"
	.string "せんとうが　おわっても　やけどの　ままです\n"
	.string "やけどなおしで　なおしましょう$"

RustboroCity_PokemonSchool_Text_ExplainFreeze: @ 0x08202FA7
	.string "こおって　しまうと　なにも　できなくなります\p"
	.string "たたかい　おわっても　こおりついた　ままです\n"
	.string "こおりなおしで　とかしましょう$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw: @ 0x08202FE5
	.string "べんきょうを　しない　せいとは\n"
	.string "わたくしの　ツメの　あかを\l"
	.string "せんじて　のませるのです！\p"
	.string "きみが　べんきょう　する　しないは\n"
	.string "この　どうぐを　つかいこなせるか　どうかで\l"
	.string "わかること　でしょう！$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw: @ 0x08203045
	.string "ポケモンに　せんせいのツメを　もたせると\n"
	.string "ときどき　ですが　すばやくなって\l"
	.string "せんせい　こうげきを　するのです！\p"
	.string "このように　ポケモンに　もたせる\n"
	.string "どうぐの　こと　だけでも\l"
	.string "べんきょう　することは　いっぱい　なのです！$"

RustboroCity_PokemonSchool_Text_TradingRightNow: @ 0x082030B2
	.string "いま　ともだちと\n"
	.string "ポケモンを　こうかん　してるんだ！$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot: @ 0x082030CD
	.string "ほしかった　タネボーちゃん　が\n"
	.string "やっと　てに　はいるよ！$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems: @ 0x082030EA
	.string "ポケモンも　どうぐ　もてるけど\n"
	.string "キズぐすりとか　どくけしとか\l"
	.string "ひとが　つくった　どうぐは\l"
	.string "つかいかたが　わからない　みたい$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself: @ 0x08203128
	.string "ポケモンの　わざで\n"
	.string "こんらん　することが　あるでしょ？\p"
	.string "こんらん　すると　たまに　まちがえて\n"
	.string "じぶんを　こうげき　しちゃうの⋯⋯\p"
	.string "でも　いちどでも　せんとうから　はなれると\n"
	.string "もとに　もどるわよ！$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry: @ 0x0820318A
	.string "⋯⋯ポケモンに　きのみを　もたせると\n"
	.string "じぶんで　たいりょくを　かいふくする\p"
	.string "ポケモンが　もてる　どうぐは\n"
	.string "ほかにも　たくさん⋯⋯\p"
	.string "ノートを　ちゃんと　とるのは\n"
	.string "たいへんだなあ⋯⋯$"

RustboroCity_PokemonSchool_Text_StudentsNotes: @ 0x082031E4
	.string "このこの　ノートだ⋯⋯\p"
	.string "ポケモンは　モンスターボールで　つかまえて\n"
	.string "どうじに　6ぴき　もちあるける\p"
	.string "そうして　つかまえた　ポケモンを\n"
	.string "そだてて　たたかわせる　ひとを\l"
	.string "ポケモントレーナーと　いう\p"
	.string "トレーナーの　もくひょうは\n"
	.string "かくちの　ポケモンジムに　いる\l"
	.string "つよい　トレーナーに　かつこと！$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut: @ 0x08203274
	.string "おや？　きみとは　たしか\n"
	.string "トウカシティで　あった　きがするね\p"
	.string "わたしの　なまえは　エニシダ\p"
	.string "ポケモンしょうぶの　さいのうを　もった\n"
	.string "ゆうしゅうな　じんざいを　もとめて\l"
	.string "かくちを　たびして　いるのさ\p"
	.string "スクールを　のぞきにきた　ということは\n"
	.string "きみも　トレーナー？\p"
	.string "ならば　まずは　いあいぎりを\n"
	.string "ポケモンに　おぼえさせると　いいね！\p"
	.string "いあいぎりは　たしか　このまちの\n"
	.string "だれかが　もっていた　はずだよ$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown: @ 0x08203339
	.string "エニシダ“うーん　ここに　いる\n"
	.string "せいとさん　たちの　さいのうは\l"
	.string "まだまだ　みちすう！　これから　だな！$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge: @ 0x0820336D
	.string "エニシダ“ん　それは⋯⋯\n"
	.string "ストーンバッジ　だね\l"
	.string "なかなか　やるじゃ　ないか！\p"
	.string "だけど　できれば\n"
	.string "たたかっている　ところを　みたかったな\l"
	.string "リーグバッジ　だけでは　きみが\l"
	.string "どんな　トレーナー　なのかは\l"
	.string "よく　わからない　からね$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge: @ 0x082033DD
	.string "おや？　きみとは　たしか\n"
	.string "トウカシティで　あった　きがするね\p"
	.string "わたしの　なまえは　エニシダ\p"
	.string "ポケモンしょうぶの　さいのうを　もった\n"
	.string "ゆうしゅうな　じんざいを　もとめて\l"
	.string "かくちを　たびして　いるのさ\p"
	.string "きみの　それは⋯⋯\n"
	.string "ストーンバッジ　だね\l"
	.string "トレーナーに　なりたてに　しては　やるね\p"
	.string "だけど　できれば\n"
	.string "たたかっている　ところを　みたかったな\l"
	.string "リーグバッジ　だけでは　きみが\l"
	.string "どんな　トレーナー　なのかは\l"
	.string "よく　わからない　からね$"
