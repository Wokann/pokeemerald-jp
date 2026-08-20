.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong220_Part0
sSong220_Part0: @ 0x0886DE6C
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 58
	.byte	BENDR , 24
	.byte	PAN , 64
	.byte	VOL , 19
	.byte	BEND , 32
	.byte	N16, Gn1, 127
	.byte	W01
	.byte	VOL , 43
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 72
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 92
	.byte	BEND , 71
	.byte	W01
	.byte	VOL , 109
	.byte	BEND , 83
	.byte	W02
	.byte	92
	.byte	W01
	.byte	104
	.byte	W01
	.byte	92
	.byte	W01
	.byte	VOL , 102
	.byte	BEND , 83
	.byte	W01
	.byte	VOL , 88
	.byte	BEND , 69
	.byte	W02
	.byte	VOL , 69
	.byte	BEND , 55
	.byte	W01
	.byte	VOL , 37
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 17
	.byte	BEND , 30
	.byte	W10
	.byte	FINE
	.globl sSong220_Part1
sSong220_Part1: @ 0x0886DEB2
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 110
	.byte	N02, Gs3, 32
	.byte	W02
	.byte	Gn3
	.byte	W02
	.byte	Fn3
	.byte	W03
	.byte	En3
	.byte	W02
	.byte	Dn3
	.byte	W03
	.byte	Cn3
	.byte	W02
	.byte	Gs2
	.byte	W10
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86DEC9, 0x3
	.globl sSongHeader_220
sSongHeader_220: @ 0x0886DECC
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886DE6C, 0x0886DEB2  @ parts
