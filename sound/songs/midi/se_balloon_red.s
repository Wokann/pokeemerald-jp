.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong74_Part0
sSong74_Part0: @ 0x08869474
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	VOL , 105
	.byte	BEND , 64
	.byte	N06, Cn4, 127
	.byte	W06
	.byte	VOICE , 23
	.byte	N02, Cn3, 112
	.byte	W07
	.byte	N01, Cn4
	.byte	W05
	.byte	Cn3, 100
	.byte	W02
	.byte	Gn3, 92
	.byte	W02
	.byte	Cn3, 72
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869497, 0x1
	.globl sSongHeader_74
sSongHeader_74: @ 0x08869498
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong74_Part0  @ parts
