.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong206_Part0
sSong206_Part0: @ 0x0886D1CC
	.byte	KEYSH , 0
	.byte	TEMPO , 90
	.byte	VOICE , 16
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N06, Ds6, 100
	.byte	W01
	.byte	BEND , 53
	.byte	W01
	.byte	PAN , 69
	.byte	VOL , 90
	.byte	BEND , 44
	.byte	W01
	.byte	PAN , 58
	.byte	VOL , 77
	.byte	BEND , 27
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 37
	.byte	BEND , 17
	.byte	W02
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N06
	.byte	W01
	.byte	PAN , 69
	.byte	BEND , 53
	.byte	W01
	.byte	PAN , 58
	.byte	VOL , 90
	.byte	BEND , 44
	.byte	W01
	.byte	PAN , 72
	.byte	VOL , 77
	.byte	BEND , 27
	.byte	W01
	.byte	PAN , 54
	.byte	VOL , 37
	.byte	BEND , 17
	.byte	W02
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N06, Ds6, 56
	.byte	W01
	.byte	PAN , 69
	.byte	BEND , 53
	.byte	W01
	.byte	PAN , 58
	.byte	VOL , 90
	.byte	BEND , 44
	.byte	W01
	.byte	PAN , 72
	.byte	VOL , 77
	.byte	BEND , 27
	.byte	W01
	.byte	PAN , 54
	.byte	VOL , 37
	.byte	BEND , 17
	.byte	W02
	.byte	FINE
	.globl sSong206_Part1
sSong206_Part1: @ 0x0886D239
	.byte	KEYSH , 0
	.byte	VOICE , 53
	.byte	VOL , 100
	.byte	W02
	.byte	N06, Cn6, 40
	.byte	W04
	.byte	W02
	.byte	N04, Cn6, 32
	.byte	W04
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D24B, 0x1
	.globl sSongHeader_206
sSongHeader_206: @ 0x0886D24C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886D1CC, 0x0886D239  @ parts
