.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong34_Part0
sSong34_Part0: @ 0x08868AA8
	.byte	KEYSH , 0
	.byte	TEMPO , 90
	.byte	VOICE , 85
	.byte	VOL , 90
	.byte	BEND , 58
	.byte	N02, Cn3, 80
	.byte	W02
	.byte	VOICE , 86
	.byte	N03, Cn4, 127
	.byte	W01
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868ABE, 0x2
	.globl sSongHeader_34
sSongHeader_34: @ 0x08868AC0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong34_Part0  @ parts
