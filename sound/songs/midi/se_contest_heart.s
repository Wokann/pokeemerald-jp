.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong96_Part0
sSong96_Part0: @ 0x08869A40
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 14
	.byte	VOL , 90
	.byte	BEND , 57
	.byte	N02, Cn5, 112
	.byte	W02
	.byte	N09, Gn4
	.byte	W04
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869A53, 0x1
	.globl sSongHeader_96
sSongHeader_96: @ 0x08869A54
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong96_Part0  @ parts
