MauvilleCity_House1_MapScripts::
    .byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
    msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
    @ ITEM_HM06 is ROCK SMASH in the JP item ID table.
    giveitem ITEM_HM06
    setflag FLAG_RECEIVED_HM_ROCK_SMASH
    setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
    msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
    release
    end

MauvilleCity_House1_EventScript_ReceivedRockSmash:
    msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
    release
    end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
    .string "ほっほう！\p"
    .string "ぼくのことを　いわくだきオヤジ\n"
    .string "なんて　よぶひとが　いるらしいけど\l"
    .string "しつれい　しちゃうね！\p"
    .string "ぼくは　まだ　オヤジ　じゃないよ\n"
    .string "せめて　いわくだきにいさん　と\l"
    .string "よんでほしい　ものだね！\p"
    .string "ほっほう！\p"
    .string "それはそれとして　きみの　ポケモン\n"
    .string "なかなか　つよそうだな！\p"
    .string "よし　きにいった！\n"
    .string "この　ひでんマシンを　あげよう！$"

MauvilleCity_House1_Text_ExplainRockSmash:
    .string "それは　ひでんマシン‘いわくだき’！\p"
    .string "きみの　いくてを　ふさぐ\n"
    .string "じゃまな　おおいわが　あっても\p"
    .string "その　ひでんを　つかうことで\n"
    .string "くだいて　しまえるのだ！\p"
    .string "がんばって　いわを　くだきたまえ！\n"
    .string "ほっほう！$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
    .string "そうそう\n"
    .string "いわを　くだくと　かくれていた\l"
    .string "ポケモンが　とびでることも　あるからね！\p"
    .string "ほっほう！$"
