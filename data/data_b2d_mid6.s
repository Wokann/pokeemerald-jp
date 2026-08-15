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
