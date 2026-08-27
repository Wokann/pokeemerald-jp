Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "えっ　なにを　してるかって？\p"
	.string "ポケモンの　わざを　つかって\n"
	.string "ここに　ぼくだけの　へやを\l"
	.string "つくろうと　おもってね！\p"
	.string "そうだっ　この　わざマシンを　あげるから\n"
	.string "きみも　つくって　みるかい？$"

Route111_Text_ExplainSecretPower:
	.string "ツルが　おちそうな　きにむかって\n"
	.string "ひみつのちからを　つかってごらん！\l"
	.string "ツルが　おちてきて　きのうえに　のぼれるよ！\p"
	.string "それでね　うえには　ひろいへやが　あるから\n"
	.string "ぼくは　そこに　すきなものを　おくんだ！\l"
	.string "じぶんだけの　ひみつのへや⋯\l"
	.string "そう　ひみつきちさ！\l"
	.string "きみも　つくると　いいよー\p"
	.string "そうそう　ひみつきちを　つくれる　ばしょは\n"
	.string "きのうえ　だけじゃ　ないよ！\p"
	.string "ちいさな　くぼみがある　かべなんかにも\n"
	.string "ひみつのちからを　つかって　みるといいよ！\p"
	.string "ぼくも　ほかの　ばしょを　さがして　みるね\n"
	.string "それじゃ！$"

Route111_Text_DontWantThis:
	.string "そう　いらないんだ⋯\n"
	.string "ほしくなったら　また　こえかけてね！$"

Route111_Text_DontHaveAnyRoom:
	.string "あれ？\n"
	.string "それいじょうは　もてない　みたいだよ\p"
	.string "また　こんど　とりに　きてね！$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

SecretBase_EventScript_DollInteract::
	special CheckInteractedWithFriendsDollDecor
	end

SecretBase_EventScript_CushionInteract::
	special CheckInteractedWithFriendsCushionDecor
	end
