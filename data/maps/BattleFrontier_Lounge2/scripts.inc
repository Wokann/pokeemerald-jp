BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "やあやあ　ぼくは　バトルフロンティアいちの\n"
	.string "じょうほうつう！\p"
	.string "フロンティアマニアって　よんでくれよ！\p"
	.string "きみ　トレーナーだろ？\p"
	.string "ぼくが　あつめた　バトルフロンティアの\n"
	.string "ホットな　じょうほうを　おしえて　あげるよ！$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "やあやあ　また　ぼくの　じょうほうを\n"
	.string "ききに　きたんだね！　しかたないなー！$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "どう？　どう？　どう？\p"
	.string "ぼくの　じょうほうは　もちろん\n"
	.string "すごーく　さんこうに　なってるだろ？$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "そうだねぇ⋯⋯\p"
	.string "いまは　{STR_VAR_1}が\n"
	.string "アッつい　みたいだね！$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "そうだねぇ⋯⋯\p"
	.string "いまは　バトルタワー{STR_VAR_1}が\n"
	.string "アッつい　みたいだね！$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "しってるかい？\p"
	.string "あそこは　エニシダが\n"
	.string "フロンティアブレーンって　よんでる\l"
	.string "トレーナーの　うちの　ひとり⋯⋯\l"
	.string "タワータイクーンって　いう\l"
	.string "なぞの　トレーナーが　おさめてるのさ！$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "きみは　タワータイクーンと\n"
	.string "たたかったこと　あるかい？\p"
	.string "やつは　あいての　ちからを　はかるとき\n"
	.string "エスパーの　ねんりきポケモン！\l"
	.string "ほのおの　かざんポケモン！\l"
	.string "ノーマルの　いねむりポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "きみは　ほんきの　タワータイクーンと\n"
	.string "たたかったこと　あるかい？\p"
	.string "やつは　ほんとの　ちからで　たたかうとき\n"
	.string "ドラゴンと　エスパーの　むげんポケモン！\l"
	.string "でんきの　いかづちポケモン！\l"
	.string "ノーマルの　いねむりポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "しってるかい？\p"
	.string "あそこは　エニシダが\n"
	.string "フロンティアブレーンって　よんでる\l"
	.string "トレーナーの　うちの　ひとり⋯⋯\l"
	.string "ドームスーパースターって　いう\l"
	.string "どハデな　トレーナーが　おさめてるのさ！$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "きみは　ドームスーパースターと\n"
	.string "たたかったこと　あるかい？\p"
	.string "やつは　あいての　ちからを　なめてるとき\n"
	.string "ドラゴンと　ひこうの　ドラゴンポケモン！\l"
	.string "みずと　じめんの　ぬまうおポケモン！\l"
	.string "ほのおと　ひこうの　かえんポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "きみは　ほんきの　ドームスーパースターと\n"
	.string "たたかったこと　あるかい？\p"
	.string "やつは　じぶんの　せんりゃくを　みせるとき\n"
	.string "ドラゴンと　エスパーの　むげんポケモン！\l"
	.string "みずと　じめんの　ぬまうおポケモン！\l"
	.string "はがねと　エスパーの　てつあしポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "しってるかい？\p"
	.string "あそこは　エニシダが\n"
	.string "フロンティアブレーンって　よんでる\l"
	.string "トレーナーの　うちの　ひとり⋯⋯\l"
	.string "ファクトリーヘッドって　いう\l"
	.string "やばい　トレーナーが　おさめてるのさ！$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "きみは　もう　ファクトリーヘッドと\n"
	.string "たたかったこと　あるかい？\p"
	.string "あいつが　つかう　ポケモンは\n"
	.string "レンタルポケモンの\l"
	.string "なかから　どれか　3ひき！\l"
	.string "きみと　ほぼ　おなじ　じょうけん　らしいぜ！$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "きみは　ほんきの　ファクトリーヘッドと\n"
	.string "たたかったこと　あるかい？\p"
	.string "あいつは　ほんきで　たたかう　ときでも\n"
	.string "レンタルポケモンの\l"
	.string "なかから　どれか　3ひき！\l"
	.string "きみと　ほとんど　おなじ　じょうけんで\l"
	.string "たたかう　らしいぜ！$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "しってるかい？\p"
	.string "あそこには　エニシダが\n"
	.string "フロンティアブレーンって　よんでる\l"
	.string "トレーナーの　うちの　ひとり⋯⋯\l"
	.string "チューブクイーンって　いう\l"
	.string "こわーい　トレーナーが　おさめてるのさ！$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "きみは　チューブクイーンと\n"
	.string "たたかったこと　あるかい？\p"
	.string "やつは　きげんの　いいとき\n"
	.string "どくの　キバへびポケモン！\l"
	.string "むしと　いわの　はっこうポケモン！\l"
	.string "みずの　いつくしみポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "きみは　ほんきの　チューブクイーンと\n"
	.string "たたかったこと　あるかい？\p"
	.string "やつは　ほんきで　おこったとき\n"
	.string "どくの　キバへびポケモン！\l"
	.string "はがねと　じめんの　てつへびポケモン！\l"
	.string "みずと　ひこうの　きょうあくポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "しってるかい？\p"
	.string "あそこには　エニシダが\n"
	.string "フロンティアブレーンって　よんでる\l"
	.string "トレーナーの　うちの　ひとり⋯⋯\l"
	.string "アリーナキャプテンって　いう\l"
	.string "かわいい　トレーナーが　おさめてるのさ！$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "きみは　もう　アリーナキャプテンと\n"
	.string "たたかったこと　あるかい？\p"
	.string "あのこは　あいての　ちからを　うかがうとき\n"
	.string "むしと　かくとうの　1ぽんヅノポケモン！\l"
	.string "あくの　げっこうポケモン！\l"
	.string "むしと　ゴーストの　ぬけがらポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "きみは　ほんきの　アリーナキャプテンと\n"
	.string "たたかったこと　あるかい？\p"
	.string "あのこは　マジで　たたかう　とき\n"
	.string "あくの　げっこうポケモン！\l"
	.string "ゴーストと　どくの　シャドーポケモン！\l"
	.string "くさと　かくとうの　きのこポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "あそこには　エニシダが\n"
	.string "フロンティアブレーンって　よんでる\l"
	.string "トレーナーの　うちの　ひとり⋯⋯\l"
	.string "パレスガーディアンって　いう\l"
	.string "あやしい　トレーナーが　おさめてるのさ！$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "きみは　パレスガーディアンと\n"
	.string "たたかったこと　あるかい？\p"
	.string "やつは　あいての　こころを　ためすとき\n"
	.string "どくと　ひこうの　こうもりポケモン！\l"
	.string "ノーマルの　ものぐさポケモン\l"
	.string "みずと　こおりの　のりものポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "きみは　ほんきの　パレスガーディアンと\n"
	.string "たたかったこと　あるかい？\p"
	.string "やつが　てかげんぬきで　たたかうときは\n"
	.string "ほのおの　でんせつポケモン！\l"
	.string "ノーマルの　ものぐさポケモン\l"
	.string "みずの　オーロラポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "しってるかい？\p"
	.string "あそこには　エニシダが\n"
	.string "フロンティアブレーンって　よんでる\l"
	.string "トレーナーの　うちの　ひとり⋯⋯\l"
	.string "ピラミッドキングって　いう\l"
	.string "アツーい　トレーナーが　おさめてるのさ！$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "きみは　もう　ピラミッドキングと\n"
	.string "たたかったこと　あるかい？\p"
	.string "かれは　あいての　ちからを　ためすとき\n"
	.string "いわの　いわやまポケモン！\l"
	.string "こおりの　ひょうざんポケモン！\l"
	.string "はがねの　くろがねポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "きみは　ほんきの　ピラミッドキングと\n"
	.string "たたかったこと　あるかい？\p"
	.string "かれに　あつい　ちからが　みなぎるときは\n"
	.string "こおりと　ひこうの　れいとうポケモン！\l"
	.string "でんきと　ひこうの　でんげきポケモン！\l"
	.string "ほのおと　ひこうの　かえんポケモンの\l"
	.string "3ひきを　つかってくる　らしいぜ！$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "ダブルバトルが　できる　ばしょは\n"
	.string "いくつか　あるけど　やっぱり　きほんは\l"
	.string "バトルタワーの　ダブル　バトルルーム！\p"
	.string "まずは　ここから　バトルフロンティアでの\n"
	.string "ダブルバトルを　まなんで　いくと　いいぜ！$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "ここでの　たたかいには\n"
	.string "ちゅうい　しなよ！\p"
	.string "ダブルバトル　ならではの　せんぽうで\n"
	.string "たたかう　トレーナーも　いるみたいだぜ！$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "ここの　たたかいで\n"
	.string "ダブルバトルに　じしんが　ついたら\l"
	.string "ほかの　ダブルバトルが　できる　ばしょに\l"
	.string "チャレンジ　してみると　いいかもな！$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "バトルサロンには\n"
	.string "いろんな　トレーナーが　あつまるんだぜ！\p"
	.string "もしかしたら　きみの　ともだちや\n"
	.string "でしにも　あえるかも　しれないな！\l"
	.string "よーく　さがして　みると　いいぜ！$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "ともだちが　あつまったら\n"
	.string "つうしんマルチ　バトルルーム！！\p"
	.string "つよい　ともだちと　いっしょに　あそべば\n"
	.string "つよい　トレーナーたち　との\l"
	.string "たたかいが　まってるぜ！$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "すっげえ　じょうほうりょくー！！\n"
	.string "やっぱ　センパイは　ちがうっすよー$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "すっげえ　かんさつりょくー！！\n"
	.string "やっぱ　センパイは　ちがうっすわー$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "すっげえ　せっとくりょくー！！\n"
	.string "やっぱ　センパイは　ちがうっすねー$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "なによ　ここ⋯⋯\n"
	.string "ちょっと　こわい⋯⋯$"
