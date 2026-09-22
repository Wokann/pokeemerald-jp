@ Record Mixing Lights resources retained in the original mid60 tail-prefix
@ section. Keep their JP physical order and exact bytes until regenerated
@ graphics and precisely placed C data can replace these named owners.

sRecordMixLights_Gfx: @ 0x0856A290
	.incbin "baserom_jp.gba", 0x56a290, 0x180

sRecordMixLights_Pal: @ 0x0856A410
	.incbin "baserom_jp.gba", 0x56a410, 0x20

sPicTable_RecordMixLights: @ 0x0856A430
	.incbin "baserom_jp.gba", 0x56a430, 0x18

	.globl sSpritePalette_RecordMixLights
sSpritePalette_RecordMixLights: @ 0x0856A448
	.incbin "baserom_jp.gba", 0x56a448, 0x8

sAnim_RecordMixLights: @ 0x0856A450
	.incbin "baserom_jp.gba", 0x56a450, 0x10

sAnimTable_RecordMixLights: @ 0x0856A460
	.incbin "baserom_jp.gba", 0x56a460, 0x4

	.globl sSpriteTemplate_RecordMixLights
sSpriteTemplate_RecordMixLights: @ 0x0856A464
	.incbin "baserom_jp.gba", 0x56a464, 0x18
