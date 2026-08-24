@ RustboroCity_Flat2_2F scripts (JP map g11 m14 @ 0x08203FE8)

RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays: @ 0x0820402B
	.string "デボンもな　むかしは\n"
	.string "ちいさな　ちいさな　かいしゃ　だったわい$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt: @ 0x0820404B
	.string "おとうさんは　かいしゃで　おしごと！\p"
	.string "これ　おとうさんが　つくったんだぜ！\n"
	.string "でも　ぼく　まだ　つかえないから　あげるよ$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo: @ 0x08204087
	.string "おとうさんは　かいしゃで　おしごと！\p"
	.string "ぼくも　おおきく　なったら\n"
	.string "デボンで　はたらくんだ！$"

	@ Rustboro City Flat2 3F and later unstructured script owners begin here.
	.incbin "baserom_jp.gba", 0x2040b5, 0x2e9
