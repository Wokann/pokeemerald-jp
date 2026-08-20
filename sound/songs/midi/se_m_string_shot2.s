.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong130_Part0
sSong130_Part0: @ 0x0886A990
	.byte	KEYSH , 0
	.byte	TEMPO , 125
	.byte	VOICE , 10
	.byte	BENDR , 12
	.byte	VOL , 105
	.byte	PAN , 63
	.byte	BEND , 64
	.byte	N09, En4, 112
	.byte	W03
	.byte	BEND , 70
	.byte	W03
	.byte	76
	.byte	W05
	.byte	72
	.byte	W01
	.byte	PAN , 80
	.byte	N09, Gn4
	.byte	W03
	.byte	BEND , 56
	.byte	W03
	.byte	50
	.byte	W06
	.byte	PAN , 64
	.byte	BEND , 53
	.byte	N09, En4
	.byte	W03
	.byte	BEND , 59
	.byte	W03
	.byte	65
	.byte	W05
	.byte	61
	.byte	W01
	.byte	PAN , 48
	.byte	N09, Gn4
	.byte	W03
	.byte	BEND , 45
	.byte	W03
	.byte	39
	.byte	W06
	.byte	PAN , 64
	.byte	BEND , 45
	.byte	N09, En4
	.byte	W03
	.byte	BEND , 51
	.byte	W03
	.byte	58
	.byte	W05
	.byte	54
	.byte	W01
	.byte	PAN , 80
	.byte	N09, Gn4, 96
	.byte	W03
	.byte	BEND , 37
	.byte	W03
	.byte	32
	.byte	W06
	.byte	PAN , 64
	.byte	BEND , 32
	.byte	N09, En4, 84
	.byte	W03
	.byte	BEND , 38
	.byte	W03
	.byte	45
	.byte	W05
	.byte	41
	.byte	W01
	.byte	PAN , 48
	.byte	N09, Gn4, 60
	.byte	W03
	.byte	BEND , 24
	.byte	W03
	.byte	19
	.byte	W06
	.byte	FINE
	.globl sSong130_Part1
sSong130_Part1: @ 0x0886A9FF
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 105
	.byte	PAN , 73
	.byte	N09, Cn3, 52
	.byte	W12
	.byte	PAN , 57
	.byte	N09, Gn2
	.byte	W12
	.byte	PAN , 73
	.byte	N09, Cn3, 52
	.byte	W12
	.byte	PAN , 58
	.byte	N09, Gn2
	.byte	W12
	.byte	PEND
	.byte	PATT , 16, 170
	.byte	W06
	.byte	GsM2
	.byte	PATT , 16, 170
	.byte	W06
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AA27, 0x1
	.globl sSongHeader_130
sSongHeader_130: @ 0x0886AA28
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A990, 0x0886A9FF  @ parts
