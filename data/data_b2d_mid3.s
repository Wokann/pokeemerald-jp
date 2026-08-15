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


	.globl gUnknown_82F4720
gUnknown_82F4720: @ 0x82F4720
	.incbin "baserom_jp.gba", 0x2f4720, 0x18
	.globl gUnknown_82F4738
gUnknown_82F4738: @ 0x82F4738
	.string "あいゾとおりヨざセっüト$$"
	.globl gUnknown_82F4746
gUnknown_82F4746: @ 0x82F4746
	.string "むいをいぱたモねぷほwわめげムぶgカぴト$$"
	.globl gUnknown_82F475C
gUnknown_82F475C: @ 0x82F475C
	.string "むいをいぱいモいぱたモねぷほwんめずムぺgセぴホ$$"
	.globl gUnknown_82F4776
gUnknown_82F4776: @ 0x82F4776
	.string "むいをいぱいモいぱたモねぷほwんめずムイgニぴレ$$"
	.globl gUnknown_82F4790
gUnknown_82F4790: @ 0x82F4790
	.string "むいろいフしゃねツよ？ょゥぶゅシ$$"
	.globl gUnknown_82F47A2
gUnknown_82F47A2: @ 0x82F47A2
	.string "むいろいフいフしゃねツれ？ずゥエゅフ$$"
	.globl gUnknown_82F47B6
gUnknown_82F47B6: @ 0x82F47B6
	.string "むいろいフいゃいフしゃねツれ？ずゥコゅリ$$"
	.globl gUnknown_82F47CC
gUnknown_82F47CC: @ 0x82F47CC
	.string "こいろいテせがはわり,ょ2ばヌカぎネ$$"
	.globl gUnknown_82F47E0
gUnknown_82F47E0: @ 0x82F47E0
	.string "こいろいテいテせがはわれ,ぎ2ぼヌコぎホ$$"
	.globl gUnknown_82F47F6
gUnknown_82F47F6: @ 0x82F47F6
	.string "こいろいテいがいテせがはわれ,ぎ2ぴヌセぎヤ$$"
	.globl gUnknown_82F480E
gUnknown_82F480E: @ 0x82F480E
	.string "こいマくツせボねせもなぃこぜピっュツ$$"
	.globl gUnknown_82F4822
gUnknown_82F4822: @ 0x82F4822
	.string "こいマいツいマくツせボねせらなぎこぱピタュヨ$$"
	.globl gUnknown_82F483A
gUnknown_82F483A: @ 0x82F483A
	.string "むいをいGしぞにソみモわやぎスでゲタ$$"
	.globl gUnknown_82F484E
gUnknown_82F484E: @ 0x82F484E
	.string "むいをいGいぞいGしぞにソみモぇやぢスイゲメ$$"
	.globl gUnknown_82F4866
gUnknown_82F4866: @ 0x82F4866
	.string "むいぃたえほムわモわgわnげゥぶチカよト$$"
	.globl gUnknown_82F487C
gUnknown_82F487C: @ 0x82F487C
	.string "むいぃいぃたえほムぃモぃgぃnぢゥエチニよリ$$"
	.globl gUnknown_82F4894
gUnknown_82F4894: @ 0x82F4894
	.string "りいアい,しャにナめジんボざ8ぼチコセハ$$"
	.globl gUnknown_82F48AA
gUnknown_82F48AA: @ 0x82F48AA
	.string "りいアい,いャい,しャにナめジぇボで8カチハセン$$"
	.globl gUnknown_82F48C4
gUnknown_82F48C4: @ 0x82F48C4
	.string "ヌいジいぃいょうぃしょぬわみちれヘぎげびZエぅテメミ$$"
	.globl gUnknown_82F48E0
gUnknown_82F48E0: @ 0x82F48E0
	.string "ダいカいぃこ·はがめWぇヘげやぼぎイしテ$$"
	.globl gUnknown_82F48F6
gUnknown_82F48F6: @ 0x82F48F6
	.string "ダいカいぃいぃこ·はがめWぇヘぞやカぎトしロ$$"
	.globl gUnknown_82F490E
gUnknown_82F490E: @ 0x82F490E
	.string "エいRいらしカた/に$$"
	.globl gUnknown_82F491A
gUnknown_82F491A: @ 0x82F491A
	.string "あいRいoくぁた/は$$"
	.globl gUnknown_82F4926
gUnknown_82F4926: @ 0x82F4926
	.string "ぁいRいマくあつ/ふ$$"
	.globl gUnknown_82F4932
gUnknown_82F4932: @ 0x82F4932
	.string "をいRいヨし/にのむoれこゅちぜgぶよイ$$"
	.globl gUnknown_82F4948
gUnknown_82F4948: @ 0x82F4948
	.string "をいRいヨし/にのむoれこゅちぜgぶよイ$$"
	.globl gUnknown_82F495E
gUnknown_82F495E: @ 0x82F495E
	.incbin "baserom_jp.gba", 0x2f495e, 0x12
	.globl gUnknown_82F4970
gUnknown_82F4970: @ 0x82F4970
	.incbin "baserom_jp.gba", 0x2f4970, 0x12
	.globl gUnknown_82F4982
gUnknown_82F4982: @ 0x82F4982
	.string "むいをいエつカみ”んムざキぼ$$"
	.globl gUnknown_82F4992
gUnknown_82F4992: @ 0x82F4992
	.string "むいをいエいエつカや”ょムぶキコ$$"
	.globl gUnknown_82F49A4
gUnknown_82F49A4: @ 0x82F49A4
	.string "むいをいエいカいエつカや”ょけざムエキメ$$"
	.globl gUnknown_82F49BA
gUnknown_82F49BA: @ 0x82F49BA
	.string "びいrいぺいケうっクぴホ$$"
	.globl gUnknown_82F49C8
gUnknown_82F49C8: @ 0x82F49C8
	.string "むいマからしがとSほじれよぎ:ぶぎコ$$"
	.globl gUnknown_82F49DC
gUnknown_82F49DC: @ 0x82F49DC
	.string "むいマいらいがいマからしがとSほじぃよで:コぎメ$$"
	.globl gUnknown_82F49F6
gUnknown_82F49F6: @ 0x82F49F6
	.string "クいニい·つづめプぇぽづ×イなツよメ$$"
	.globl gUnknown_82F4A0A
gUnknown_82F4A0A: @ 0x82F4A0A
	.string "がいソいういIいIばUニ$$"
	.globl gUnknown_82F4A18
gUnknown_82F4A18: @ 0x82F4A18
	.string "バいwこらこむとぷはぺほぽめべり”ぇぶざ$$"
	.globl gUnknown_82F4A2E
gUnknown_82F4A2E: @ 0x82F4A2E
	.string "バいwいらいむいwこらこむとぷはぺほぽめべわ”げぶぶ$$"
	.globl gUnknown_82F4A4A
gUnknown_82F4A4A: @ 0x82F4A4A
	.string "バいwいらいむいwこらこむとぷはぺほぽめべわ”ぢぶク$$"
	.globl gUnknown_82F4A66
gUnknown_82F4A66: @ 0x82F4A66
	.string "こいらいふしょひnやだぉボずゥぴヌカチト$$"
	.globl gUnknown_82F4A7C
gUnknown_82F4A7C: @ 0x82F4A7C
	.string "びいぼしぶはてゆひぉÄざwぼPエ$$"
	.globl gUnknown_82F4A8E
gUnknown_82F4A8E: @ 0x82F4A8E
	.string "びいあいぼしぱはてゆぱぉÄざっぼぴエ$$"
	.globl gUnknown_82F4AA2
gUnknown_82F4AA2: @ 0x82F4AA2
	.incbin "baserom_jp.gba", 0x2f4aa2, 0x16
