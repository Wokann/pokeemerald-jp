.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong237_Part0
sSong237_Part0: @ 0x0886EAB0
	.byte	VOL , 110
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 61
	.byte	BENDR , 44
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N48, Cn4, 108
	.byte	W02
	.byte	BEND , 63
	.byte	W01
	.byte	64
	.byte	W03
	.byte	64
	.byte	W01
	.byte	64
	.byte	W02
	.byte	64
	.byte	W01
	.byte	64
	.byte	W02
	.byte	PAN , 60
	.byte	W01
	.byte	BEND , 64
	.byte	W01
	.byte	65
	.byte	W02
	.byte	65
	.byte	W02
	.byte	65
	.byte	W02
	.byte	65
	.byte	W01
	.byte	65
	.byte	W03
	.byte	PAN , 54
	.byte	BEND , 65
	.byte	W01
	.byte	66
	.byte	W02
	.byte	66
	.byte	W03
	.byte	65
	.byte	W02
	.byte	66
	.byte	W01
	.byte	65
	.byte	W03
	.byte	PAN , 60
	.byte	BEND , 65
	.byte	W01
	.byte	65
	.byte	W02
	.byte	65
	.byte	W01
	.byte	64
	.byte	W02
	.byte	64
	.byte	W01
	.byte	63
	.byte	W01
	.byte	63
	.byte	W01
	.byte	61
	.byte	W01
	.byte	61
	.byte	W02
	.byte	FINE
	.globl sSong237_Part1
sSong237_Part1: @ 0x0886EB04
	.byte	KEYSH , 0
	.byte	VOICE , 66
	.byte	BENDR , 44
	.byte	PAN , 65
	.byte	VOL , 110
	.byte	N48, Dn3, 20
	.byte	W24
	.byte	W03
	.byte	VOL , 103
	.byte	W04
	.byte	96
	.byte	W03
	.byte	83
	.byte	W04
	.byte	67
	.byte	W04
	.byte	49
	.byte	W03
	.byte	23
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86EB21, 0x3
	.globl sSongHeader_237
sSongHeader_237: @ 0x0886EB24
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886EAB0, 0x0886EB04  @ parts
