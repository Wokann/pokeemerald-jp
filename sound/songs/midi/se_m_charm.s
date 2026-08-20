.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong212_Part0
sSong212_Part0: @ 0x0886D770
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 37
	.byte	BENDR , 24
	.byte	PAN , 64
	.byte	VOL , 25
	.byte	BEND , 75
	.byte	N02, Fn4, 127
	.byte	W01
	.byte	VOL , 42
	.byte	PAN , 68
	.byte	BEND , 69
	.byte	W01
	.byte	VOL , 62
	.byte	PAN , 60
	.byte	BEND , 64
	.byte	N15
	.byte	W01
	.byte	VOL , 77
	.byte	PAN , 64
	.byte	BEND , 69
	.byte	W01
	.byte	VOL , 84
	.byte	PAN , 68
	.byte	BEND , 76
	.byte	W02
	.byte	VOL , 96
	.byte	PAN , 60
	.byte	BEND , 84
	.byte	W01
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	BEND , 89
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 94
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 98
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 104
	.byte	W02
	.byte	VOL , 94
	.byte	PAN , 68
	.byte	W01
	.byte	VOL , 85
	.byte	PAN , 60
	.byte	BEND , 101
	.byte	W01
	.byte	VOL , 66
	.byte	PAN , 64
	.byte	BEND , 100
	.byte	W01
	.byte	VOL , 49
	.byte	PAN , 68
	.byte	BEND , 98
	.byte	W01
	.byte	VOL , 32
	.byte	PAN , 60
	.byte	BEND , 96
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D7DE, 0x2
	.globl sSongHeader_212
sSongHeader_212: @ 0x0886D7E0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong212_Part0  @ parts
