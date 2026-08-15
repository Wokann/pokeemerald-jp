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


	.globl gUnknown_82F3E80
gUnknown_82F3E80: @ 0x82F3E80
	.incbin "baserom_jp.gba", 0x2f3e80, 0x14
	.globl gUnknown_82F3E94
gUnknown_82F3E94: @ 0x82F3E94
	.incbin "baserom_jp.gba", 0x2f3e94, 0x16
	.globl gUnknown_82F3EAA
gUnknown_82F3EAA: @ 0x82F3EAA
	.string "コうこいらこぇとスみヌんäずボっぎト$$"
	.globl gUnknown_82F3EBE
gUnknown_82F3EBE: @ 0x82F3EBE
	.string "コうこいらいぇいらこぇとスみヌんäずボクぎヤ$$"
	.globl gUnknown_82F3ED6
gUnknown_82F3ED6: @ 0x82F3ED6
	.string "こいろいづついほボれヤょどぢzぺヌコゆニ$$"
	.globl gUnknown_82F3EEC
gUnknown_82F3EEC: @ 0x82F3EEC
	.string "こいろいづいテいづついほボれヤょテぎどぶzコヌフゆン$$"
	.globl gUnknown_82F3F08
gUnknown_82F3F08: @ 0x82F3F08
	.string "わいんいゃせろはざらやぇ？ずせぱチカゅツ$$"
	.globl gUnknown_82F3F1E
gUnknown_82F3F1E: @ 0x82F3F1E
	.string "わいんいゃいざうöツ$$"
	.globl gUnknown_82F3F2A
gUnknown_82F3F2A: @ 0x82F3F2A
	.string "ダいソせがはうよ:ぇめずAぼぎカ$$"
	.globl gUnknown_82F3F3C
gUnknown_82F3F3C: @ 0x82F3F3C
	.string "ダいソいがいソせがはうよ:ょめばAカぎニ$$"
	.globl gUnknown_82F3F52
gUnknown_82F3F52: @ 0x82F3F52
	.string "がいソいういぢいぢば9ニ$$"
	.globl gUnknown_82F3F60
gUnknown_82F3F60: @ 0x82F3F60
	.string "トい$$"
	.globl gUnknown_82F3F64
gUnknown_82F3F64: @ 0x82F3F64
	.incbin "baserom_jp.gba", 0x2f3f64, 0x1a
	.globl gUnknown_82F3F7E
gUnknown_82F3F7E: @ 0x82F3F7E
	.incbin "baserom_jp.gba", 0x2f3f7e, 0x1a
	.globl gUnknown_82F3F98
gUnknown_82F3F98: @ 0x82F3F98
	.string "づいろいヤせいはどよGわぬぉuずぢぼzっ,カkツ$$"
	.globl gUnknown_82F3FB2
gUnknown_82F3FB2: @ 0x82F3FB2
	.string "づいろいヤいヤせいはどよGわぬぉuぢぢイzシ,ニkヨ$$"
	.globl gUnknown_82F3FCE
gUnknown_82F3FCE: @ 0x82F3FCE
	.string "づいろいヤいヤせいはどよGわぬぉuぢぢイzシ,ニkヨ$$"
	.globl gUnknown_82F3FEA
gUnknown_82F3FEA: @ 0x82F3FEA
	.string "にいぼしもにぽほぷめぺよぉんrざぱぼなコ$$"
	.globl gUnknown_82F4000
gUnknown_82F4000: @ 0x82F4000
	.string "にいぼいもいぼしもにぽほぷめぺよぉぃrぢぱエなフ$$"
	.globl gUnknown_82F401A
gUnknown_82F401A: @ 0x82F401A
	.string "にいぽいrいぱい$$"
	.globl gUnknown_82F4024
gUnknown_82F4024: @ 0x82F4024
	.string "りいぃしャねぉよじぇもざミぶヌカぎツ$$"
	.globl gUnknown_82F4038
gUnknown_82F4038: @ 0x82F4038
	.string "りいぃいャいぃしャねぉよじぇもざミぴヌセぎホ$$"
	.globl gUnknown_82F4050
gUnknown_82F4050: @ 0x82F4050
	.string "むいマいわすクにjみリれSゃセぜケぶベイよシ$$"
	.globl gUnknown_82F4068
gUnknown_82F4068: @ 0x82F4068
	.string "むいマいわうクいわすクにjみリれSげセぱケコベハよワ$$"
	.globl gUnknown_82F4084
gUnknown_82F4084: @ 0x82F4084
	.string "むいマいわうクいわすクにjみリれSげセぱケコベハよワ$$"
	.globl gUnknown_82F40A0
gUnknown_82F40A0: @ 0x82F40A0
	.string "むいをこらつゃふぬよウぇやずチぴエサンハ$$"
	.globl gUnknown_82F40B6
gUnknown_82F40B6: @ 0x82F40B6
	.string "むいをいらいゃいをこらつゃふぬよウぇやずチぴまっエナンン$$"
	.globl gUnknown_82F40D4
gUnknown_82F40D4: @ 0x82F40D4
	.string "ーいのうむいをしがほスりぇげへでュカセタ$$"
	.globl gUnknown_82F40EA
gUnknown_82F40EA: @ 0x82F40EA
	.string "ーいのうむいをいをしがほスりぇげへでホぼュシセフ$$"
	.globl gUnknown_82F4104
gUnknown_82F4104: @ 0x82F4104
	.string "ぜうむいエしぃにぅみカれWゃMぞゥぴヌクFト$$"
	.globl gUnknown_82F411C
gUnknown_82F411C: @ 0x82F411C
	.string "ぜうむいエいぃいエしぃにぅみカれWゃMば0クヌハFワ$$"
	.globl gUnknown_82F4138
gUnknown_82F4138: @ 0x82F4138
	.string "ぞいふしろにまみはろXゃせずチぶ2イTシ$$"
	.globl gUnknown_82F414E
gUnknown_82F414E: @ 0x82F414E
	.incbin "baserom_jp.gba", 0x2f414e, 0x14
	.globl gUnknown_82F4162
gUnknown_82F4162: @ 0x82F4162
	.incbin "baserom_jp.gba", 0x2f4162, 0x18
	.globl gUnknown_82F417A
gUnknown_82F417A: @ 0x82F417A
	.string "へいをつJめずれピげやぼげイgツ$$"
	.globl gUnknown_82F418C
gUnknown_82F418C: @ 0x82F418C
	.string "へいをいJいずいをつJめずれピげべどやエげニgィ$$"
	.globl gUnknown_82F41A6
gUnknown_82F41A6: @ 0x82F41A6
	.string "ゴいあいハくぇたワはヒよヌゃビでBカかヒ$$"
	.globl gUnknown_82F41BC
gUnknown_82F41BC: @ 0x82F41BC
	.string "ゴいあいハいハくぇたワはヒよヌゃビでBセかロ$$"
	.globl gUnknown_82F41D4
gUnknown_82F41D4: @ 0x82F41D4
	.string "むいホいぃつずめ♀ぇろぢィイげツ$$"
	.globl gUnknown_82F41E6
gUnknown_82F41E6: @ 0x82F41E6
	.string "ホいぃいずい♀いEぢォイ$$"
	.globl gUnknown_82F41F4
gUnknown_82F41F4: @ 0x82F41F4
	.string "ソいレい'たZはーみナれヘぎゲぢHぶ$$"
	.globl gUnknown_82F4208
gUnknown_82F4208: @ 0x82F4208
	.string "ソいレい'い'たZはーみナれどぉヘずゲぺHタ$$"
	.globl gUnknown_82F4220
gUnknown_82F4220: @ 0x82F4220
	.string "ソいレい'い'たZはーみナれどぉヘずゲぺHタ$$"
	.globl gUnknown_82F4238
gUnknown_82F4238: @ 0x82F4238
	.string "むいヌいとつクはハれテぇOぢなぼsコぶテよメ$$"
	.globl gUnknown_82F4250
gUnknown_82F4250: @ 0x82F4250
	.incbin "baserom_jp.gba", 0x2f4250, 0x16
	.globl gUnknown_82F4266
gUnknown_82F4266: @ 0x82F4266
	.incbin "baserom_jp.gba", 0x2f4266, 0x1a
	.globl gUnknown_82F4280
gUnknown_82F4280: @ 0x82F4280
	.string "ダいろこさねハみオぁぬょしで♀イブコ$$"
	.globl gUnknown_82F4294
gUnknown_82F4294: @ 0x82F4294
	.string "ダいろいさいろこさねハみオぁぬょしぴ♀ツブメ$$"
	.globl gUnknown_82F42AC
gUnknown_82F42AC: @ 0x82F42AC
	.string "しうむいヌたぅほWれリょSぞムぼゥエベシÜツ$$"
	.globl gUnknown_82F42C4
gUnknown_82F42C4: @ 0x82F42C4
	.string "しうむいヌいぅいヌたぅほWれリょSでムイゥタベフÜヨ$$"
	.globl gUnknown_82F42E0
gUnknown_82F42E0: @ 0x82F42E0
	.string "ザい{B_COPY_VAR_1}ソいモせべはスよぺぇぷずぽぼぴカ$$"
	.globl gUnknown_82F42F6
gUnknown_82F42F6: @ 0x82F42F6
	.string "ザいソいスいぬよルず$$"
	.globl gUnknown_82F4302
gUnknown_82F4302: @ 0x82F4302
	.string "をいらこヲつへはろめヤれパぇテげTぢゆぼLイよコ$$"
	.globl gUnknown_82F431C
gUnknown_82F431C: @ 0x82F431C
	.string "をいらいヲいへいらこヲつへはろめヤれパぇテぞTぺゆシLハよレ$$"
	.globl gUnknown_82F433C
gUnknown_82F433C: @ 0x82F433C
	.string "ぬうねいタしひにはみねるヤれギゃ9ずGぶQイのシ‘ニ$$"
	.globl gUnknown_82F4358
gUnknown_82F4358: @ 0x82F4358
	.string "ぬうえいチせpは¥りけゃくゃきゃびだおぴKクでト$$"
	.globl gUnknown_82F4372
gUnknown_82F4372: @ 0x82F4372
	.string "レいぃせマねはゆぬんもげぇでなっヌコまヌ$$"
	.globl gUnknown_82F4388
gUnknown_82F4388: @ 0x82F4388
	.string "ゴいむいロつリめワれフぇメぢベイHコかテ$$"
	.globl gUnknown_82F439E
gUnknown_82F439E: @ 0x82F439E
	.string "ゴいむいロいリいロつリめワれフぇメぢベクHニかユ$$"
	.globl gUnknown_82F43B8
gUnknown_82F43B8: @ 0x82F43B8
	.string "ほいらいぬとまほ,ぃセごみぴやカケネlメ$$"
	.globl gUnknown_82F43CE
gUnknown_82F43CE: @ 0x82F43CE
	.string "ほいらいぬいまいぬとまほ,ぃセごみぴやシケヤlャ$$"
	.globl gUnknown_82F43E8
gUnknown_82F43E8: @ 0x82F43E8
	.string "あいをいらこまてガはうめヒんぁげルばマイムツよメ$$"
	.globl gUnknown_82F4402
gUnknown_82F4402: @ 0x82F4402
	.string "てうャいぽくびとぼはぷよにわとぎぶずぺぼなっだス$$"
	.globl gUnknown_82F441C
gUnknown_82F441C: @ 0x82F441C
	.incbin "baserom_jp.gba", 0x2f441c, 0x16
	.globl gUnknown_82F4432
