.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong123_Part0
sSong123_Part0: @ 0x0886A718
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 6
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N06, Cn3, 127
	.byte	W01
	.byte	BEND , 55
	.byte	W01
	.byte	43
	.byte	W01
	.byte	PAN , 58
	.byte	BEND , 24
	.byte	W01
	.byte	0
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N06, En3
	.byte	W01
	.byte	BEND , 55
	.byte	W01
	.byte	43
	.byte	W01
	.byte	PAN , 71
	.byte	BEND , 24
	.byte	W01
	.byte	0
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N09, An2
	.byte	W01
	.byte	BEND , 55
	.byte	W01
	.byte	45
	.byte	W01
	.byte	35
	.byte	W01
	.byte	VOL , 86
	.byte	BEND , 25
	.byte	W02
	.byte	VOL , 69
	.byte	BEND , 19
	.byte	W01
	.byte	VOL , 53
	.byte	BEND , 8
	.byte	W01
	.byte	VOL , 20
	.byte	BEND , 0
	.byte	W04
	.byte	0
	.byte	FINE
	.globl sSong123_Part1
sSong123_Part1: @ 0x0886A76D
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 110
	.byte	PAN , 73
	.byte	N03, Gs2, 52
	.byte	W06
	.byte	PAN , 57
	.byte	N03
	.byte	W06
	.byte	PAN , 64
	.byte	N03
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A787, 0x1
	.globl sSongHeader_123
sSongHeader_123: @ 0x0886A788
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A718, 0x0886A76D  @ parts
