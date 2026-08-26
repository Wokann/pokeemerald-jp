	lockall
	delay 0x14
	applymovement 0xFF, 0x8264371
	waitmovement 0x0
	playse 0x2B
	delay 0x3C
	special DoFallWarp
	end
	.incbin "baserom_jp.gba", 0x264371, 0x10394
BerryBlender_Text_BlendWithTheBlendMaster: @ 0x08274705
	.incbin "baserom_jp.gba", 0x274705, 0x256
BerryBlender_Text_WhoaAwesome: @ 0x0827495B
	.incbin "baserom_jp.gba", 0x27495b, 0x6
BerryBlender_Text_WickedlyFast: @ 0x08274961
	.incbin "baserom_jp.gba", 0x274961, 0x5
BerryBlender_Text_WhatAnExpert: @ 0x08274966
	.incbin "baserom_jp.gba", 0x274966, 0x6
BerryBlender_Text_MadeAmazingPokeblocksWithMaster: @ 0x0827496C
	.incbin "baserom_jp.gba", 0x27496c, 0x24
BerryBlender_Text_QualitiesOfBlendMaster: @ 0x08274990
	.incbin "baserom_jp.gba", 0x274990, 0x51
BerryBlender_Text_MasterWorksOnSkillsInMountains: @ 0x082749E1
	.incbin "baserom_jp.gba", 0x2749e1, 0x3c2
	.globl gJPText_00274DA3
gJPText_00274DA3: @ 0x08274DA3
	.string "では　バトルテントへ\n"
	.string "おつれいたしますぞ！$"

	.globl gJPText_00274DB9
gJPText_00274DB9: @ 0x08274DB9
	.string "おきゃくじん！\p"
	.string "ぜんかい　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたな？\p"
	.string "ざんねんですが　その　ばあい\n"
	.string "ちょうせんは　むこうと　なりますぞ！\p"
	.string "また　はじめから\n"
	.string "ちょうせん　してくだされ！！$"

	.globl gJPText_00274E1B
gJPText_00274E1B: @ 0x08274E1B
	.string "3にんぬき　たっせい\n"
	.string "おみごとで　ございました！$"

	.globl gJPText_00274E34
gJPText_00274E34: @ 0x08274E34
	.string "レポートを　かきますので\n"
	.string "おまちくだされ！$"

	.globl gJPText_00274E4A
gJPText_00274E4A: @ 0x08274E4A
	.string "3にんぬきを　たっせい　されましたので\n"
	.string "この　しょうひんを　おうけとり　くだされ！$"

	.globl gJPText_00274E74
gJPText_00274E74: @ 0x08274E74
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "{B_COPY_VAR_1}を　もらった！$"

	.globl gJPText_00274E82
gJPText_00274E82: @ 0x08274E82
	.string "⋯⋯おおっ！\n"
	.string "どうぐが　いっぱいの　ようですな！\p"
	.string "どうぐを　せいりしてから\n"
	.string "また　おこしくだされ！$"

	.globl gJPText_00274EB4
gJPText_00274EB4: @ 0x08274EB4
	.string "おつかれさまでした！\p"
	.string "レポートを　かきますので\n"
	.string "おまちくだされ！$"

	.globl gJPText_00274ED5
gJPText_00274ED5: @ 0x08274ED5
	.string "またの　ちょうせんを\n"
	.string "おまちして　おりますぞ！$"

	.globl gJPText_00274EED
gJPText_00274EED: @ 0x08274EED
	.string "おまちしておりました！\p"
	.string "バトルテントに　おつれする　まえに\n"
	.string "レポートを　かきますので　おまちくだされ！$"

	.incbin "baserom_jp.gba", 0x274f21, 0x182
	.globl gJPText_002750A3
gJPText_002750A3: @ 0x082750A3
	.string "おのれの　こころと　ポケモンを　きたえたら\n"
	.string "また　くるがよい⋯⋯$"

	.incbin "baserom_jp.gba", 0x2750c4, 0x1a6
	.globl gJPText_0027526A
gJPText_0027526A: @ 0x0827526A
	.string "それでは\n"
	.string "わしに　ついてこい⋯⋯$"

	.globl gJPText_0027527B
gJPText_0027527B: @ 0x0827527B
	.string "よいものを　みせて　もらった\p"
	.string "それでは　レポートを　かこう⋯⋯\n"
	.string "しばし　またれよ⋯⋯$"

	.globl gJPText_002752A6
gJPText_002752A6: @ 0x082752A6
	.string "3にんぬき　たっせい　とは⋯⋯\p"
	.string "おぬしと　ポケモンの　こころの　きずなは\n"
	.string "まことの　ようじゃな⋯⋯$"

	.globl gJPText_002752D8
gJPText_002752D8: @ 0x082752D8
	.string "レポートに　かくぞ\n"
	.string "しばし　またれよ⋯⋯$"

	.globl gJPText_002752ED
gJPText_002752ED: @ 0x082752ED
	.string "3にんぬきの　あかしに\n"
	.string "こちらを　さしあげよう⋯⋯$"

	.incbin "baserom_jp.gba", 0x275307, 0x196
	.globl gJPText_0027549D
gJPText_0027549D: @ 0x0827549D
	.string "またの　ごりようを　おまちしていますよ！$"

	.incbin "baserom_jp.gba", 0x2754b2, 0x63
	.globl gJPText_00275515
gJPText_00275515: @ 0x08275515
	.string "さあさあ　こちらに　どうぞ！$"

	.globl gJPText_00275524
gJPText_00275524: @ 0x08275524
	.string "おつかれさまでした！\p"
	.string "レンタルポケモンと\n"
	.string "おあずかり　していた　ポケモンを\l"
	.string "こうかん　します！\p"
	.string "レポートを　かきますので\n"
	.string "しょうしょう　おまちください！$"

	.incbin "baserom_jp.gba", 0x275571, 0x25
	.globl gJPText_00275596
gJPText_00275596: @ 0x08275596
	.string "3れんしょう　おめでとう　ございます！\p"
	.string "レンタルポケモンと\n"
	.string "おあずかり　していた　ポケモンを\l"
	.string "こうかん　します！\p"
	.string "レポートを　かきますので\n"
	.string "しょうしょう　おまちください！$"

	.globl gJPText_002755EC
gJPText_002755EC: @ 0x082755EC
	.string "3れんしょうを　きねんして\n"
	.string "こちらを　さしあげます！$"

	.globl gJPText_00275607
gJPText_00275607: @ 0x08275607
	.string "おやや？\n"
	.string "どうぐが　いっぱい　ですねー\p"
	.string "どうぐを　せいり　してから\n"
	.string "また　きてください！$"

	.globl gJPText_00275634
gJPText_00275634: @ 0x08275634
	.string "おまちして　おりましたよ！\p"
	.string "ちょうせんを　さいかいする　まえに\n"
	.string "レポートを　かきます！$"

	.globl gJPText_00275660
gJPText_00275660: @ 0x08275660
	.string "おきゃくさまー！！\p"
	.string "ぜんかい　ちゃんと　レポートを　かいて\n"
	.string "しゅうりょう　しませんでしたね！\p"
	.string "ざんねんですが\n"
	.string "ちょうせんは　むこうと　なります！$"

	.incbin "baserom_jp.gba", 0x2756a9, 0x1606
