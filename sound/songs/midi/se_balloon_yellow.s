.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong76_Part0
sSong76_Part0: @ 0x088694D4
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	VOL , 105
	.byte	BEND , 64
	.byte	N02, Fn3, 127
	.byte	W02
	.byte	N01, Cn4, 112
	.byte	W02
	.byte	N03, Fn3, 52
	.byte	W02
	.byte	W02
	.byte	VOICE , 23
	.byte	N01, En4, 92
	.byte	W01
	.byte	Cn5
	.byte	W03
	.byte	Gn3
	.byte	W01
	.byte	En4
	.byte	W02
	.byte	En3, 48
	.byte	W01
	.byte	Bn3
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8694FF, 0x1
	.globl sSongHeader_76
sSongHeader_76: @ 0x08869500
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong76_Part0  @ parts
