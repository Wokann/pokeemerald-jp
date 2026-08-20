.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong75_Part0
sSong75_Part0: @ 0x088694A4
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	VOL , 105
	.byte	BEND , 64
	.byte	N03, Gn4, 127
	.byte	W04
	.byte	N01, Gn4, 112
	.byte	W02
	.byte	W02
	.byte	Gs3, 52
	.byte	W04
	.byte	VOICE , 23
	.byte	N02, Fn3, 112
	.byte	W04
	.byte	N01, Cn4, 72
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8694C7, 0x1
	.globl sSongHeader_75
sSongHeader_75: @ 0x088694C8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong75_Part0  @ parts
