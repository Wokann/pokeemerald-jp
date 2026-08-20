.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong225_Part0
sSong225_Part0: @ 0x0886E15C
	.byte	KEYSH , 0
	.byte	TEMPO , 90
	.byte	VOICE , 16
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N06, An6, 100
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
	.byte	N02, An6, 56
	.byte	W01
	.byte	PAN , 69
	.byte	W01
	.byte	58
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N06, An6, 100
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 53
	.byte	W01
	.byte	PAN , 54
	.byte	VOL , 90
	.byte	BEND , 44
	.byte	W02
	.byte	PAN , 65
	.byte	VOL , 77
	.byte	BEND , 27
	.byte	W01
	.byte	PAN , 69
	.byte	VOL , 37
	.byte	BEND , 17
	.byte	W01
	.byte	PAN , 58
	.byte	N02, An6, 56
	.byte	W01
	.byte	PAN , 72
	.byte	W01
	.byte	54
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N06, An6, 72
	.byte	W02
	.byte	PAN , 64
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
	.byte	PAN , 72
	.byte	VOL , 37
	.byte	BEND , 17
	.byte	W01
	.byte	PAN , 54
	.byte	W02
	.byte	W06
	.byte	FINE
	.globl sSong225_Part1
sSong225_Part1: @ 0x0886E1E1
	.byte	KEYSH , 0
	.byte	VOICE , 53
	.byte	VOL , 100
	.byte	W02
	.byte	N06, Fs6, 40
	.byte	W04
	.byte	W04
	.byte	N06
	.byte	W02
	.byte	W06
	.byte	W01
	.byte	Fs6, 32
	.byte	W05
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86E1F6, 0x2
	.globl sSongHeader_225
sSongHeader_225: @ 0x0886E1F8
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E15C, 0x0886E1E1  @ parts
