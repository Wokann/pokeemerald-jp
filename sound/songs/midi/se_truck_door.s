.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong52_Part0
sSong52_Part0: @ 0x08868F4C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 8
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N03, Cn2, 92
	.byte	W06
	.byte	N01, Cn3
	.byte	W02
	.byte	N02, Cn4
	.byte	W04
	.byte	FINE
	.globl sSong52_Part1
sSong52_Part1: @ 0x08868F61
	.byte	VOL , 110
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	N03, Cn2, 32
	.byte	W05
	.byte	N01, Cn4
	.byte	W01
	.byte	W02
	.byte	N02
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868F72, 0x2
	.globl sSongHeader_52
sSongHeader_52: @ 0x08868F74
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08868F4C, 0x08868F61  @ parts
