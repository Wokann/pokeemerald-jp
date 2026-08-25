@ LilycoveCity_House3 scripts (JP map g13 m14 @ 0x0820A065)

LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:: @ 0x0820A06B
	random 0x4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF:: @ 0x0820A074
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn:: @ 0x0820A09E
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man:: @ 0x0820A0B3
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1:: @ 0x0820A0CA
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2:: @ 0x0820A0FE
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3:: @ 0x0820A132
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4:: @ 0x0820A166
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle:: @ 0x0820A19A
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords:: @ 0x0820A1A4
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries:: @ 0x0820A1AE
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest:: @ 0x0820A1B8
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks: @ 0x0820A1C2
	.string "あら　あら　あら！　あなた　わかいのに\n"
	.string "ひとりたび？　えらいわねえー！\l"
	.string "うちのこ　たちにも　みならわせたいわあ\p"
	.string "おばさんは　ポロックめいじん！\n"
	.string "ちょいと　ほんきを　だせば\l"
	.string "すごく　いい　ポロックを　つくれるのよー！\p"
	.string "ポロックめいじんの　おばさんが\n"
	.string "いろいろと　おしえてあげようか？$"

LilycoveCity_House3_Text_OhAreYouSure: @ 0x0820A24F
	.string "あらあ　そう？\n"
	.string "なんでも　じぶん　ひとりだけで\l"
	.string "がんばろうと　しちゃ　ダメよー！$"

LilycoveCity_House3_Text_ExplainPokeblocks: @ 0x0820A278
	.string "あらあ　すなおな　いいコねえー！\n"
	.string "じゃ　ちょっとながいけど　ききなさいよ\p"
	.string "いい？\p"
	.string "ポロックには　なめらかさって　もんが　あるの\n"
	.string "ポロックを　みれば　わかるでしょ？\l"
	.string "この　すうじが　ひくいほど　なめらかなの！\l"
	.string "ここ　まちがっちゃ　ダメよ！\p"
	.string "なめらかさの　すうじが　ひくくて\n"
	.string "レベルが　たかいのが　いい　ポロック！\l"
	.string "いい　ポロックは　たくさん\l"
	.string "ポケモンが　たべて　くれるんだから！\p"
	.string "それと　いい？\p"
	.string "なめらかな　ポロックが　つくりたかったら\n"
	.string "けちらないで　いろんな　しゅるいの\l"
	.string "きのみで　つくってみるのよ！\l"
	.string "まぜた　きのみによって　なめらかさが\l"
	.string "ちがって　くるんだから！\p"
	.string "それと　いい？\p"
	.string "なるべく　おおぜいで　つくったほうが\n"
	.string "なめらかな　ポロックが　できるのよ！\l"
	.string "だれでも　いいから　おねがいして\l"
	.string "いっしょに　つくって　もらいなさいよ！\p"
	.string "さてと　このくらい　おぼえて　おけば\n"
	.string "あなたも　いちにんまえに　なれるわよ！\p"
	.string "だいすきな　ポケモンと　なめらか　ポロック\n"
	.string "そして　なかよし　かぞくが　いれば\l"
	.string "このよは　しあわせ！\l"
	.string "あなたも　がんばりなさいな！$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets: @ 0x0820A44F
	.string "よつごが　うまれた　ときは\n"
	.string "すごく　ビックリ　したが\l"
	.string "みんなで　なかよく　あそんでいる　すがたを\l"
	.string "みていると　しあわせ　きぶんに　なるよ！$"

LilycoveCity_House3_Text_GoingToWinMultiBattles: @ 0x0820A495
	.string "マルチバトル　してるけど\n"
	.string "ぼくが　かつに　きまってるぜ！$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner: @ 0x0820A4B2
	.string "レコードコーナーで　まぜまくる！\n"
	.string "って　なにが　まざってるんだ？$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender: @ 0x0820A4D3
	.string "きのみブレンダーで\n"
	.string "とびっきりの　ポロック　つくっちゃうぜ！$"

LilycoveCity_House3_Text_GoingToEnterContest: @ 0x0820A4F2
	.string "ポケモンの　たくましさ　じまん　したいから\n"
	.string "みんなで　コンテスト　してるんだ！$"
