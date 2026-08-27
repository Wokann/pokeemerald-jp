BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "へへ！　あたち　ポケモンの\n"
	.string "きもち　わかるの！\p"
	.string "ね！　ポケモン　みちて！　みちて！$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "ぷー！　けち！！$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "ふんふん⋯⋯\p"
	.string "このこ　たたかうの　ちゅき！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "たたかうよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "ふんふん⋯⋯\p"
	.string "このこ　ずるいの　ちゅき！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "ちかえし　してやる！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "ふんふん⋯⋯\p"
	.string "このこ　たたかうの　ちゅき！　って！\n"
	.string "だけど　あんまし　いたいいたい　だと\l"
	.string "じぶんが　ちんぱい　なるよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "ふんふん⋯⋯\p"
	.string "このこ　たたかうの　ちゅき！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "たたかうよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "ふんふん⋯⋯\p"
	.string "このこ　じぶん　だいじ！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "ちかえし　してやる！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "ふんふん⋯⋯\p"
	.string "このこ　ずるいの　ちゅき！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "じぶんが　ちんぱい　なるよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "ふんふん⋯⋯\p"
	.string "このこ　たたかうの　ちゅき！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "たたかうよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "ふんふん⋯⋯\p"
	.string "このこ　ずるいの　ちゅき！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "ちかえし　してやる！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "ふんふん⋯⋯\p"
	.string "このこ　たたかうの　ちゅき！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "じぶんが　ちんぱい　なるよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "ふんふん⋯⋯\p"
	.string "このこ　ずるいの　ちゅき！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "ずるいのが　いい！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "ふんふん⋯⋯\p"
	.string "このこ　たたかうの　ちゅき！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "ずるいの　するよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "ふんふん⋯⋯\p"
	.string "このこ　たたかうの　ちゅき！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "たたかうよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "ふんふん⋯⋯\p"
	.string "このこ　ずるいの　ちゅき！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "ずるいのが　いい！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "ふんふん⋯⋯\p"
	.string "このこ　ずるいの　ちゅき！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "じぶんが　ちんぱい　なるよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "ふんふん⋯⋯\p"
	.string "このこ　じぶん　だいじ！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "じぶん　だいじ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "ふんふん⋯⋯\p"
	.string "このこ　じぶん　だいじ！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "ずるいの　するよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "ふんふん⋯⋯\p"
	.string "このこ　じぶん　だいじ！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "じぶん　だいじ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "ふんふん⋯⋯\p"
	.string "このこ　ずるいの　ちゅき！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "ずるいのが　いい！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "ふんふん⋯⋯\p"
	.string "このこ　じぶん　だいじ！　って！\n"
	.string "いっぱい　いたいいたい　でも\l"
	.string "じぶん　だいじ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "ふんふん⋯⋯\p"
	.string "このこ　じぶん　だいじ！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "ちかえし　してやる！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "ふんふん⋯⋯\p"
	.string "このこ　たたかうの　ちゅき！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "ずるいの　するよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "ふんふん⋯⋯\p"
	.string "このこ　じぶん　だいじ！　って！\n"
	.string "でも　あんまし　いたいいたい　だと\l"
	.string "ずるいの　するよ！　って！$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "たまごは　ねんね　してる　から\n"
	.string "おはなち　できない　よぉ！$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "ポケモンの　きもちが　わかるとは\n"
	.string "あの　おじょうちゃん　なかなか\l"
	.string "シャレた　ことを　もうしますな！$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "じぶん　あのこが　すごく　だいじなことを\n"
	.string "いっている　きが　するで　あります！$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "ぼく　ちってるぜ！\p"
	.string "あのこ　あかい　おうちで\n"
	.string "よく　あそんでる！$"
