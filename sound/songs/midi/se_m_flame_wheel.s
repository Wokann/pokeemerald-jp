.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong144_Part0
sSong144_Part0: @ 0x0886AF40
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 22
	.byte	BEND , 64
	.byte	N30, Dn4, 127
	.byte	W01
	.byte	VOL , 49
	.byte	W01
	.byte	71
	.byte	W01
	.byte	95
	.byte	BEND , 72
	.byte	W01
	.byte	VOL , 110
	.byte	W02
	.byte	PAN , 69
	.byte	BEND , 80
	.byte	W01
	.byte	VOL , 95
	.byte	W02
	.byte	88
	.byte	PAN , 64
	.byte	BEND , 71
	.byte	W01
	.byte	VOL , 93
	.byte	W02
	.byte	110
	.byte	PAN , 59
	.byte	BEND , 64
	.byte	W02
	.byte	VOL , 86
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 55
	.byte	W01
	.byte	VOL , 63
	.byte	W02
	.byte	37
	.byte	BEND , 40
	.byte	W03
	.byte	VOL , 13
	.byte	BEND , 18
	.byte	W03
	.byte	W24
	.byte	FINE
	.globl sSong144_Part1
sSong144_Part1: @ 0x0886AF8B
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	PAN , 64
	.byte	VOL , 22
	.byte	N30, Gn2, 32
	.byte	W01
	.byte	VOL , 49
	.byte	W01
	.byte	71
	.byte	W01
	.byte	95
	.byte	W01
	.byte	110
	.byte	W03
	.byte	95
	.byte	W02
	.byte	88
	.byte	W01
	.byte	93
	.byte	W02
	.byte	110
	.byte	W02
	.byte	86
	.byte	W02
	.byte	63
	.byte	W02
	.byte	37
	.byte	W03
	.byte	13
	.byte	W03
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AFB2, 0x2
	.globl sSongHeader_144
sSongHeader_144: @ 0x0886AFB4
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886AF40, 0x0886AF8B  @ parts
