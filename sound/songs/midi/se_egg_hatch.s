.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong113_Part0
sSong113_Part0: @ 0x0886A354
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 21
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 120
	.byte	BEND , 65
	.byte	N01, Bn5, 127
	.byte	W01
	.byte	Cn5, 100
	.byte	W01
	.byte	VOICE , 18
	.byte	N01, Cn4, 127
	.byte	W02
	.byte	VOICE , 36
	.byte	N19, Cn6, 40
	.byte	W02
	.byte	VOL , 63
	.byte	BEND , 69
	.byte	W01
	.byte	VOL , 77
	.byte	BEND , 77
	.byte	W01
	.byte	VOL , 91
	.byte	BEND , 85
	.byte	W01
	.byte	VOL , 106
	.byte	BEND , 97
	.byte	W01
	.byte	VOL , 120
	.byte	W05
	.byte	109
	.byte	W01
	.byte	102
	.byte	W02
	.byte	84
	.byte	W01
	.byte	68
	.byte	W01
	.byte	56
	.byte	W01
	.byte	24
	.byte	W01
	.byte	10
	.byte	W02
	.byte	FINE
	.globl sSong113_Part1
sSong113_Part1: @ 0x0886A39B
	.byte	KEYSH , 0
	.byte	VOL , 120
	.byte	PAN , 64
	.byte	BEND , 65
	.byte	W07
	.byte	VOICE , 46
	.byte	N01, Cn6, 100
	.byte	W02
	.byte	BEND , 68
	.byte	N01, Gn5, 88
	.byte	W03
	.byte	BEND , 72
	.byte	N01, Cn6, 72
	.byte	W02
	.byte	BEND , 80
	.byte	N01, Gn5, 56
	.byte	W02
	.byte	BEND , 87
	.byte	N01, Cn6, 40
	.byte	W03
	.byte	BEND , 97
	.byte	N01, Gn5, 28
	.byte	W02
	.byte	BEND , 117
	.byte	N01, Cn6, 12
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A3CF, 0x1
	.globl sSongHeader_113
sSongHeader_113: @ 0x0886A3D0
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A354, 0x0886A39B  @ parts
