MauvilleCity_BikeShop_MapScripts::
    .byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
    goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
    msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
    msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
    goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
    end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
    msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
    goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
    end

MauvilleCity_BikeShop_EventScript_ChooseBike::
    message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
    waitmessage
    multichoice 21, 8, MULTI_BIKE, TRUE
    switch VAR_RESULT
    case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
    case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
    end

MauvilleCity_BikeShop_EventScript_NotFar::
    setflag FLAG_DECLINED_BIKE
    msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
    release
    end

MauvilleCity_BikeShop_EventScript_YesFar::
    setflag FLAG_RECEIVED_BIKE
    goto MauvilleCity_BikeShop_EventScript_ChooseBike
    end

MauvilleCity_BikeShop_EventScript_GetMachBike::
    msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
    giveitem ITEM_MACH_BIKE
    goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
    end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
    msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
    giveitem ITEM_ACRO_BIKE
    goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
    end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
    msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
    special SwapRegisteredBike
    release
    end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
    msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
    goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
    end

@ If the player does not have a bike on them Rydel assumes its stored in the PC.
MauvilleCity_BikeShop_EventScript_SwitchBikes::
    msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
    checkitem ITEM_ACRO_BIKE
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
    checkitem ITEM_MACH_BIKE
    goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
    msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
    release
    end

MauvilleCity_BikeShop_EventScript_KeepBike::
    msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
    release
    end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
    incrementgamestat GAME_STAT_TRADED_BIKES
    msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
    removeitem ITEM_ACRO_BIKE
    giveitem ITEM_MACH_BIKE
    goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
    end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
    incrementgamestat GAME_STAT_TRADED_BIKES
    msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
    removeitem ITEM_MACH_BIKE
    giveitem ITEM_ACRO_BIKE
    goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
    end

MauvilleCity_BikeShop_EventScript_Assistant::
    msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
    end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
    message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
    waitmessage
    goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
    end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
    multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
    switch VAR_RESULT
    case 0, MauvilleCity_BikeShop_EventScript_HowToRide
    case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
    case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
    case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
    case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
    end

MauvilleCity_BikeShop_EventScript_HowToRide::
    message MauvilleCity_BikeShop_Text_HowToRideMachBike
    waitmessage
    goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
    end

MauvilleCity_BikeShop_EventScript_HowToTurn::
    message MauvilleCity_BikeShop_Text_HowToTurnMachBike
    waitmessage
    goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
    end

MauvilleCity_BikeShop_EventScript_SandySlopes::
    message MauvilleCity_BikeShop_Text_SandySlopes
    waitmessage
    goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
    end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
    release
    end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
    message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
    waitmessage
    goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
    end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
    multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
    switch VAR_RESULT
    case 0, MauvilleCity_BikeShop_EventScript_Wheelies
    case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
    case 2, MauvilleCity_BikeShop_EventScript_Jumps
    case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
    case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
    end

MauvilleCity_BikeShop_EventScript_Wheelies::
    message MauvilleCity_BikeShop_Text_Wheelies
    waitmessage
    goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
    end

MauvilleCity_BikeShop_EventScript_BunnyHops::
    message MauvilleCity_BikeShop_Text_BunnyHops
    waitmessage
    goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
    end

MauvilleCity_BikeShop_EventScript_Jumps::
    message MauvilleCity_BikeShop_Text_Jumps
    waitmessage
    goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
    end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
    release
    end

MauvilleCity_BikeShop_Text_RydelGreeting:
    .string "⋯⋯おや？　こりゃまた　ずいぶん\n"
    .string "げんきそうな　おきゃくさんが　きたのう！\p"
    .string "わたしは　ひとよんで　ミスターカゼノ\n"
    .string "この　サイクルショップの　オーナーさ！$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
    .string "カゼノ“きみの　ランニングシューズ\n"
    .string "ものすごく　よごれて　いるけど\l"
    .string "どこか　とおくから　やってきたのかい？$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
    .string "カゼノ“そうかい？\n"
    .string "じゃあ　わたしの　じてんしゃは\l"
    .string "ひつよう　なさそうだね$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
    .string "カゼノ“フムフム⋯⋯\p"
    .string "なんと　ミシロタウンから　はるばると！？\n"
    .string "すごい　とおく　じゃないか？\p"
    .string "わたしの　じてんしゃが　あれば\n"
    .string "ここちよい　かぜを　かんじながら\l"
    .string "らくに　いろんな　ところへ　いけるのに！\p"
    .string "よーし！\n"
    .string "きみに　じてんしゃを　あげよう！\p"
    .string "いや　ちょっと　まて！\p"
    .string "じてんしゃ　には　2しゅるいの\n"
    .string "タイプが　あるのを　わすれとった！\p"
    .string "それはな⋯⋯\n"
    .string "マッハじてんしゃと　ダートじてんしゃだ！\p"
    .string "マッハじてんしゃは\n"
    .string "ぜんしんで　かぜを　かんじたい　ひとに！\p"
    .string "ダートじてんしゃは\n"
    .string "テクニックを　たのしみたい　ひとに！\p"
    .string "おじさん　しんせつ　だから\n"
    .string "きみの　すきな　ほうを　あげちゃうよ！\p"
    .string "さあ！　どちらを　えらぶ？$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
    .string "{PLAYER}は\n"
    .string "マッハじてんしゃを　えらんだ！$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
    .string "{PLAYER}は\n"
    .string "ダートじてんしゃを　えらんだ！$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
    .string "カゼノ“もしも　べつの　タイプと\n"
    .string "こうかん　したくなった　ときには\l"
    .string "いつでも　わたしに　こえを　かけてくれ！$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
    .string "カゼノ“おや？　ちがう　タイプの\n"
    .string "じてんしゃに　のりかえたく　なったのかな？$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
    .string "カゼノ“じゃあ　きみが　いま　もっている\n"
    .string "じてんしゃを　こうかん　してあげよう！$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
    .string "{PLAYER}は　マッハじてんしゃを\n"
    .string "ダートじてんしゃに　かえてもらった！$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
    .string "{PLAYER}は　ダートじてんしゃを\n"
    .string "マッハじてんしゃに　かえてもらった！$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
    .string "カゼノ“そうか　そうか！\n"
    .string "きにいってくれて　うれしいぞ！$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
    .string "⋯⋯おや？\n"
    .string "きみに　あげた　じてんしゃ　どうした？\p"
    .string "そうか　パソコンに　あずけてあるのか\p"
    .string "パソコンから　とりだして　もってきたら\n"
    .string "こうかんして　あげる　からな！\p"
    .string "きみの　ぼうけんに⋯⋯\n"
    .string "おいかぜが　ふくことを　いのってるよ！$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
    .string "ぼくは　ここで　はたらき　ながら\n"
    .string "じてんしゃの　べんきょうを　してるんだ\p"
    .string "じてんしゃの　のりかたで\n"
    .string "なにか　わからないことが　あったら\p"
    .string "おくのへやに　かいせつしょが　あるから\n"
    .string "それを　よんでみると　いいよ！$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
    .string "マッハじてんしゃの\n"
    .string "かいせつしょが　おいてある！\p"
    .string "どの　ページを　よもうかな？$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
    .string "じてんしゃに　のって　じゅうじボタンを\n"
    .string "おしたほうに　じてんしゃは　はしります！\p"
    .string "すこし　はしっていく　うちに\n"
    .string "スピードが　あがっていく　でしょう！\p"
    .string "とまりたいときは　じゅうじボタンから\n"
    .string "てを　はなせば　スピードが　おちて\l"
    .string "しぜんに　とまって　くれるはずです！\p"
    .string "⋯⋯べつの　ページを　よみますか？$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
    .string "マッハじてんしゃは　スピードが　はやくて\n"
    .string "きゅうに　とまることは　できません\p"
    .string "だから　かどを　まがるときには\n"
    .string "ちょっとした　コツが　ひつようです！\p"
    .string "まがりたい　かどの　すこし　てまえで\n"
    .string "じゅうじボタンから　てを　はなして\l"
    .string "スピードを　おとして　まがりましょう！\p"
    .string "⋯⋯べつの　ページを　よみますか？$"

MauvilleCity_BikeShop_Text_SandySlopes:
    .string "ホウエンちほうには　ところどころに\n"
    .string "ちいさな　すなのさかが　あります！\p"
    .string "そこは　すなが　くずれやすい　ために\n"
    .string "ふつうは　のぼることが　できませんが\p"
    .string "マッハじてんしゃに　のっていれば\n"
    .string "のぼることが　できるのです！\p"
    .string "⋯⋯べつの　ページを　よみますか？$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
    .string "ダートじてんしゃの\n"
    .string "かいせつしょが　おいてある！\p"
    .string "どの　ページを　よもうかな？$"

MauvilleCity_BikeShop_Text_Wheelies:
    .string "じてんしゃに　のって　Bボタンを　おすと\n"
    .string "そのばで　ぜんりんが　もちあがります！\p"
    .string "そのままで　じゅうじボタンを　おせば\n"
    .string "ぜんりんを　あげた　じょうたいで\l"
    .string "はしることが　できるのです！\p"
    .string "それが　ウイリーという　テクニック！\p"
    .string "⋯⋯べつの　ページを　よみますか？$"

MauvilleCity_BikeShop_Text_BunnyHops:
    .string "Bボタンを　おしたままに　していると\n"
    .string "ウイリーしながら　そのばで　ピョンピョン\l"
    .string "とびはねることが　できます！\p"
    .string "それが　ダニエルという　テクニック！\p"
    .string "ダニエルのまま　はしることも　できます！\p"
    .string "⋯⋯べつの　ページを　よみますか？$"

MauvilleCity_BikeShop_Text_Jumps:
    .string "ダートじてんしゃに　のっているとき\n"
    .string "じゅうじボタンと　Bボタンを\l"
    .string "どうじに　おすと　ジャンプします！\p"
    .string "よこへ　おせば　よこに　ジャンプ！\p"
    .string "うしろへ　おせば　ジャンプしながら\n"
    .string "ほうこうを　かえることが　できます！\p"
    .string "⋯⋯べつの　ページを　よみますか？$"
