BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	@ JP encodes this Pokémon-cry wait with SCR_OP_WAITDOORANIM.
	waitmoncry_jp
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	@ JP proceeds directly to the encounter cry without closemessage.
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	@ JP encodes this Pokémon-cry wait with SCR_OP_WAITDOORANIM.
	waitmoncry_jp
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "ここは　バトルタワー！\n"
	.string "かちぬけ！　さいきょう　トレーナー！$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "ここは　バトルパレス！\n"
	.string "みまもれ！　ポケモンバトル！$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "ここは　バトルアリーナ！\n"
	.string "つどえ！　さいきょう　チーム！$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "ここは　バトルピラミッド！\n"
	.string "すすめ！　バトルアドベンチャー！$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "バトルフロンティア　ランキングホール\n"
	.string "きざめ！　さいこうの　きろく！$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "バトルポイント　ひきかえサービス　コーナー\n"
	.string "ひきかえろ！　キミの　バトルポイント！$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "うっひゃー　でかい！\p"
	.string "やはり　バトルタワーは\n"
	.string "とくべつ　って　かんじが　するな$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "わたしの　やぼうは\n"
	.string "バトルフロンティア　そして　ポケモンリーグ\l"
	.string "すべての　ちょうてんに　たつ　ことだ！\p"
	.string "そして　もし　それが　かなったら！\p"
	.string "とっ　となりの　いえの　ミミちゃんに\n"
	.string "おともだちに　なって　くださいって　いうぞ！$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "バトルピラミッドは　むずかし　すぎて\n"
	.string "どうしても　ちょうじょうに　まで　いけん！\p"
	.string "しかたが　ないから　いっそのこと\n"
	.string "そとがわを　のぼって　やろうかしら$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "くらやみが　だいすきな　わたし⋯⋯\n"
	.string "そう⋯⋯　わたしに　ふさわしい　のは⋯⋯\l"
	.string "やはり　この　バトルピラミッド⋯⋯\p"
	.string "ネ⋯⋯　あなたも　くらやみの　なかを\n"
	.string "ひっしに　さまよって　みない⋯⋯？$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "いっしゅうかん　ねないで　かんがえた\n"
	.string "オレの　さいきょう　チーム⋯⋯\l"
	.string "まけるきが　しねえぜ！\p"
	.string "ぃよーし　アリーナに　なぐりこみだー！$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "あんたも　エニシダさんに\n"
	.string "つれて　こられたの？\l"
	.string "あのひと　なんなんだろうね\p"
	.string "つよい　トレーナーを　みぬく　めは\n"
	.string "たしからしい　けど⋯⋯\l"
	.string "ほんにんが　たたかって　いる　ところは\l"
	.string "いちども　みたことが　ないんだよなあ$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ジグちゃん！　しんじてるからね！\p"
	.string "かったら　ジグちゃんの　すきな　おやつ\n"
	.string "なーんでも　つくって　あげるからね！$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ジグザグマは　ぼんやり　してる⋯⋯$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "お　おれは　でしゃばり　だ！\n"
	.string "オイあんた！　ぼうしが　ずれてるぜ！\l"
	.string "おっと　じめんに　ゴミが　おちてる！\l"
	.string "ああっと！　もうすぐ　ごはんだぜ！\p"
	.string "⋯⋯　⋯⋯バトルパレスで\n"
	.string "しょうぶを　ただ　みまもる　だけなんて\l"
	.string "おれに　できるだろーか⋯⋯？$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "こう　みえても　むかしは\n"
	.string "ジムリーダーに　かった　ことも　あるのよ\p"
	.string "もう　ひとはな　さかせて　みようかしらねぇ$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "じてんしゃも　はやいけど\n"
	.string "ポケモン　だって　じしんあるわ！\l"
	.string "めにも　とまらぬ　はやさで　かっちゃうわよ！$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "わたしのほうがねえー　パパより\n"
	.string "ポケモン　つよいんだよ！$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "むすめよ！\n"
	.string "がんばって　かちぬいて　こい！\l"
	.string "おまえは　ママ　そっくり　だから　つよいぞ！$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "バトルアリーナに　めちゃくちゃ\n"
	.string "ぷりてぃーな　こが　いるって　きいたから\l"
	.string "ここまで　がんばって　きたのにーっ！\p"
	.string "あせくさーくて　あつくるしーい\n"
	.string "かくとうか　ばっかり　だったよ！$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "ときどきねー　ここの　たてものに\n"
	.string "すっごく　つよそーな　ポケモン　つれて\l"
	.string "すっごく　えらそー　だけど\l"
	.string "けっこー　やさしそーな\l"
	.string "じーちゃんが　はいってくのよ！$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "きみは　しって　いるか！？\n"
	.string "バトルピラミッドの　でんせつを！！\p"
	.string "みなぎる　ゆうきを　もつ　トレーナー\n"
	.string "きんじとうの　いただきを　めざすとき\l"
	.string "おとこの　なかの　おとこ　あらわれる\p"
	.string "⋯⋯どうだ？　しらないだろー！\n"
	.string "だって　これ　さっき　おれが\l"
	.string "かんがえたんだ　もんな！\p"
	.string "なに？　どういう　いみ　かって？\n"
	.string "チッチッ！！　それは　おしえられないな！$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "くそーっ！\p"
	.string "いままで　だれにも　いちども\n"
	.string "まけたこと　なかった　この　ぼくが\l"
	.string "ても　あしも　でない　うえに\l"
	.string "さいのうが　ない　だと！？\p"
	.string "くそーっ！　くそーっ！　くそーっ！$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "このひと　バトルタワーに\n"
	.string "ちょうせん　している　ときに\l"
	.string "おそろしく　つよい　トレーナーと\l"
	.string "たたかった　みたい　なの⋯⋯\p"
	.string "あなたも　バトルタワーに\n"
	.string "ちょうせんする　ときは　ちゅういして⋯⋯$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "さて！　バトルポイントも　たまったし！\n"
	.string "また　おおきな　ぬいぐるみ　でも\l"
	.string "もらいに　いこーっと！$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "おほほほーいっ！\n"
	.string "ここが　ランキングホール　っスねー！\p"
	.string "わしも　ここに　なを　のこす　ような\n"
	.string "えいこうの　スーパー　チャンプに\l"
	.string "はやく　なりたい　っスよ！$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "もし　きみが　そばに　いてくれたら\n"
	.string "ぼくは　なんだって　できるのさ⋯⋯$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "ぁあん　やっぱ　ダーリンは　ス　テ　キ！\p"
	.string "⋯⋯　⋯⋯あー！\n"
	.string "もー！　わたし　たまんないっ！！\p"
	.string "いますぐ　ふたりで　マルチ　バトルルームに\n"
	.string "とつげき　しましょうよーっ！！\p"
	.string "バトルサロンで　いっしょに　なったら\n"
	.string "ふたりの　ラブパワーで\l"
	.string "どいつも　こいつも　ギタギタよ！\l"
	.string "ねぇー　ダーリン！！$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "バトルフロンティアには\n"
	.string "つよい　トレーナーだけでは　なく\l"
	.string "かわった　ちからを　もった　ひとたちも\l"
	.string "まねかれて　いるな⋯⋯\p"
	.string "⋯⋯エニシダと　いう　おとこ⋯⋯\p"
	.string "じつは　なにか　おおきな　もくてきが\n"
	.string "あって　ここを　つくったのかも　しれないぞ$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "もしもし　あんたさんは\n"
	.string "めは　いいほう　ですかい？\p"
	.string "あたしには　このさきの　きが　ときどき\n"
	.string "ぷるぷる　してる　ように　みえるんですわ⋯$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "もしもし　あんたさんは\n"
	.string "ものおぼえは　いいほう　ですかい？\p"
	.string "あたしには　このさきに　へんな　きが\n"
	.string "あった　ような　きが　するんですわ⋯$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "ぼぼぼ　ぼく　みちゃったんだっ！！\p"
	.string "このさきの　いわ　から　しっぽが　ながくって\n"
	.string "なんか　ベタベタした　ポケモンが\l"
	.string "ぼくの　こと　じーっと　のぞいてたんだっ！\p"
	.string "きっと　こわい　ポケモン　だよーっ！！$"
