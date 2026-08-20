.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong138_Part0
sSong138_Part0: @ 0x0886AC78
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 18
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 96
	.byte	N06, Gn3, 127
	.byte	W02
	.byte	PAN , 56
	.byte	W01
	.byte	BEND , 64
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 96
	.byte	N04, Cn3
	.byte	W02
	.byte	PAN , 73
	.byte	W01
	.byte	BEND , 52
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N01, Gn3
	.byte	W02
	.byte	Bn2
	.byte	W02
	.byte	N13, Gn3
	.byte	W02
	.byte	VOL , 96
	.byte	W01
	.byte	85
	.byte	W01
	.byte	BEND , 41
	.byte	W01
	.byte	VOL , 66
	.byte	W01
	.byte	BEND , 24
	.byte	W01
	.byte	VOL , 36
	.byte	W01
	.byte	BEND , 10
	.byte	W02
	.byte	VOL , 12
	.byte	W01
	.byte	BEND , 0
	.byte	W21
	.byte	FINE
	.globl sSong138_Part1
sSong138_Part1: @ 0x0886ACC4
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 110
	.byte	PAN , 57
	.byte	N02, En3, 52
	.byte	W04
	.byte	PAN , 74
	.byte	N02, En3, 44
	.byte	W04
	.byte	PAN , 57
	.byte	N02, En3, 36
	.byte	W04
	.byte	PAN , 74
	.byte	N02, En3, 28
	.byte	W04
	.byte	PAN , 57
	.byte	N02, En3, 20
	.byte	W08
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86ACEA, 0x2
	.globl sSongHeader_138
sSongHeader_138: @ 0x0886ACEC
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886AC78, 0x0886ACC4  @ parts
