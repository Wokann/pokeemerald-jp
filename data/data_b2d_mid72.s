.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

gUnknown_85C8D44: @ 0x85C8D44
	.string "レポートが　せいかくに　かかれていないので\n"
	.string "そのまえのレポートを　よみます！$"
	.globl gUnknown_85C8D6B
gUnknown_85C8D6B: @ 0x85C8D6B
	.string "レポートの　ないようが　きえてしまった！$"
	.globl gUnknown_85C8D80
gUnknown_85C8D80: @ 0x85C8D80
	.string "1Mサブきばんが　ささっていません！$"
	.globl gUnknown_85C8D93
gUnknown_85C8D93: @ 0x85C8D93
	.string "でんちぎれの　ために\n"
	.string "とけいが　うごかなくなりました\p"
	.string "とけいに　かんけいする　できごとは　おきませんが\n"
	.string "ゲームを　つづけて　あそぶことは　できます$しゅじんこう$ポケモンずかん$"
	.globl gUnknown_85C8DEC
gUnknown_85C8DEC: @ 0x85C8DEC
	.string "プレイじかん$もっているバッジ$エーボタン$ビーボタン$アールボタン$エルボタン$スタートボタン$セレクトボタン$じゅうじボタン$Lボタン　Rボタン$　そうさ　せつめい$　　　{DPAD_UPDOWN}えらぶ　{A_BUTTON}けってい$　　　{A_BUTTON}つぎ$　　　{A_BUTTON}つぎ　{B_BUTTON}もどる$　"

	.globl gUnknown_85C8E68
gUnknown_85C8E68: @ 0x85C8E68
	.string "{DPAD_UPDOWN}えらぶ　{A_BUTTON}つぎ　{B_BUTTON}おわる$　　　"

	.globl gUnknown_85C8E7C
gUnknown_85C8E7C: @ 0x85C8E7C
	.string "{DPAD_UPDOWN}えらぶ　{A_BUTTON}{B_BUTTON}おわる$　　"

	.globl gUnknown_85C8E8C
gUnknown_85C8E8C: @ 0x85C8E8C
	.string "{A_BUTTON}おわる$"
	.globl gText_BirchBoy
gText_BirchBoy: @ 0x85C8E92
	.string "おとこ$"
	.globl gText_BirchGirl
gText_BirchGirl: @ 0x85C8E96
	.string "おんな$"
	.globl gText_DefaultName_Itsuo
gText_DefaultName_Itsuo: @ 0x85C8E9A
	.string "イツオ$$$"
	.globl gText_DefaultName_Gyoku
gText_DefaultName_Gyoku: @ 0x85C8EA0
	.string "ギョク$$$"
	.globl gText_DefaultName_Kei
gText_DefaultName_Kei: @ 0x85C8EA6
	.string "ケイ$$$$"
	.globl gText_DefaultName_Shuusaku
gText_DefaultName_Shuusaku: @ 0x85C8EAC
	.string "シュウサク$"
	.globl gText_DefaultName_Seigo
gText_DefaultName_Seigo: @ 0x85C8EB2
	.string "セイゴ$$$"
	.globl gText_DefaultName_Daisaku
gText_DefaultName_Daisaku: @ 0x85C8EB8
	.string "ダイサク$$"
	.globl gText_DefaultName_Takahito
gText_DefaultName_Takahito: @ 0x85C8EBE
	.string "タカヒト$$"
	.globl gText_DefaultName_Tatsuya
gText_DefaultName_Tatsuya: @ 0x85C8EC4
	.string "タツヤ$$$"
	.globl gText_DefaultName_Daniel
gText_DefaultName_Daniel: @ 0x85C8ECA
	.string "ダニエル$$"
	.globl gText_DefaultName_Teruki
gText_DefaultName_Teruki: @ 0x85C8ED0
	.string "テルキ$$$"
	.globl gText_DefaultName_Tom
gText_DefaultName_Tom: @ 0x85C8ED6
	.string "トム$$$$"
	.globl gText_DefaultName_Tomoya
gText_DefaultName_Tomoya: @ 0x85C8EDC
	.string "トモヤ$$$"
	.globl gText_DefaultName_Hitoshi
gText_DefaultName_Hitoshi: @ 0x85C8EE2
	.string "ヒトシ$$$"
	.globl gText_DefaultName_Hiroaki
gText_DefaultName_Hiroaki: @ 0x85C8EE8
	.string "ヒロアキ$$"
	.globl gText_DefaultName_Yukihiko
gText_DefaultName_Yukihiko: @ 0x85C8EEE
	.string "ユキヒコ$$"
	.globl gText_DefaultName_Raldo
gText_DefaultName_Raldo: @ 0x85C8EF4
	.string "ラルド$$$"
	.globl gText_DefaultName_Rikuya
gText_DefaultName_Rikuya: @ 0x85C8EFA
	.string "リクヤ$$$"
	.globl gText_DefaultName_Richard
gText_DefaultName_Richard: @ 0x85C8F00
	.string "リチャード$"
	.globl gText_DefaultName_Ryuu
gText_DefaultName_Ryuu: @ 0x85C8F06
	.string "リュウ$$$"
	.globl gText_DefaultName_Ryouta
gText_DefaultName_Ryouta: @ 0x85C8F0C
	.string "リョウタ$$"
	.globl gText_DefaultName_Aiko
gText_DefaultName_Aiko: @ 0x85C8F12
	.string "アイコ$$$"
	.globl gText_DefaultName_Ayana
gText_DefaultName_Ayana: @ 0x85C8F18
	.string "アヤナ$$$"
	.globl gText_DefaultName_Ann
gText_DefaultName_Ann: @ 0x85C8F1E
	.string "アン$$$$"
	.globl gText_DefaultName_Emii
gText_DefaultName_Emii: @ 0x85C8F24
	.string "エミィ$"
	.globl gText_DefaultName_Kaori
gText_DefaultName_Kaori: @ 0x85C8F28
	.string "カオリ$$$"
	.globl gText_DefaultName_Karen
gText_DefaultName_Karen: @ 0x85C8F2E
	.string "カレン$$$"
	.globl gText_DefaultName_Kyouko
gText_DefaultName_Kyouko: @ 0x85C8F34
	.string "キョウコ$$"
	.globl gText_DefaultName_Sae
gText_DefaultName_Sae: @ 0x85C8F3A
	.string "サエ$$$$"
	.globl gText_DefaultName_Sui
gText_DefaultName_Sui: @ 0x85C8F40
	.string "スイ$$$$"
	.globl gText_DefaultName_Juri
gText_DefaultName_Juri: @ 0x85C8F46
	.string "ジュリ$$$"
	.globl gText_DefaultName_Chiemi
gText_DefaultName_Chiemi: @ 0x85C8F4C
	.string "チエミ$$$"
	.globl gText_DefaultName_Chiyoko
gText_DefaultName_Chiyoko: @ 0x85C8F52
	.string "チヨコ$$$"
	.globl gText_DefaultName_Teruko
gText_DefaultName_Teruko: @ 0x85C8F58
	.string "テルコ$$$"
	.globl gText_DefaultName_Nanae
gText_DefaultName_Nanae: @ 0x85C8F5E
	.string "ナナエ$$$"
	.globl gText_DefaultName_Hina
gText_DefaultName_Hina: @ 0x85C8F64
	.string "ヒナ$$$$"
	.globl gText_DefaultName_Makiko
gText_DefaultName_Makiko: @ 0x85C8F6A
	.string "マキコ$$$"
	.globl gText_DefaultName_Misako
gText_DefaultName_Misako: @ 0x85C8F70
	.string "ミサコ$$$"
	.globl gText_DefaultName_Mutsumi
gText_DefaultName_Mutsumi: @ 0x85C8F76
	.string "ムツミ$$$"
	.globl gText_DefaultName_Monica
gText_DefaultName_Monica: @ 0x85C8F7C
	.string "モニカ$$$"
	.globl gText_DefaultName_Yuume
gText_DefaultName_Yuume: @ 0x85C8F82
	.string "ユウメ$$$"
	.globl gUnknown_85C8F88
