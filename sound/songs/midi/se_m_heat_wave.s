.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong240_Part0
sSong240_Part0: @ 0x0886ED28
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 23
	.byte	BEND , 64
	.byte	TIE , 77, 127
	.byte	W01
	.byte	VOL , 51
	.byte	W01
	.byte	75
	.byte	W01
	.byte	99
	.byte	BEND , 72
	.byte	W01
	.byte	VOL , 115
	.byte	W02
	.byte	PAN , 70
	.byte	BEND , 80
	.byte	W01
	.byte	VOL , 99
	.byte	W02
	.byte	92
	.byte	BEND , 71
	.byte	W01
	.byte	VOL , 97
	.byte	W02
	.byte	105
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W03
	.byte	VOL , 110
	.byte	BEND , 55
	.byte	W03
	.byte	PAN , 56
	.byte	BEND , 40
	.byte	W03
	.byte	VOL , 115
	.byte	BEND , 26
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 23
	.byte	W04
	.byte	19
	.byte	W02
	.byte	PAN , 70
	.byte	W02
	.byte	BEND , 25
	.byte	W04
	.byte	PAN , 64
	.byte	W03
	.byte	BEND , 29
	.byte	W03
	.byte	PAN , 56
	.byte	W03
	.byte	BEND , 34
	.byte	W03
	.byte	PAN , 64
	.byte	W03
	.byte	BEND , 38
	.byte	W03
	.byte	PAN , 70
	.byte	W01
	.byte	BEND , 42
	.byte	W05
	.byte	PAN , 64
	.byte	BEND , 46
	.byte	W04
	.byte	51
	.byte	W02
	.byte	PAN , 56
	.byte	W06
	.byte	64
	.byte	W06
	.byte	70
	.byte	W03
	.byte	BEND , 57
	.byte	W03
	.byte	PAN , 64
	.byte	W04
	.byte	BEND , 61
	.byte	W02
	.byte	PAN , 56
	.byte	VOL , 113
	.byte	W04
	.byte	110
	.byte	W02
	.byte	PAN , 64
	.byte	W02
	.byte	BEND , 57
	.byte	W02
	.byte	VOL , 105
	.byte	W02
	.byte	PAN , 70
	.byte	W03
	.byte	VOL , 98
	.byte	BEND , 53
	.byte	W03
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 91
	.byte	W03
	.byte	81
	.byte	BEND , 49
	.byte	W02
	.byte	PAN , 56
	.byte	W02
	.byte	VOL , 74
	.byte	W01
	.byte	BEND , 42
	.byte	W03
	.byte	PAN , 64
	.byte	VOL , 63
	.byte	W01
	.byte	BEND , 34
	.byte	W01
	.byte	VOL , 50
	.byte	W02
	.byte	40
	.byte	BEND , 25
	.byte	W02
	.byte	PAN , 70
	.byte	W01
	.byte	VOL , 28
	.byte	BEND , 12
	.byte	W02
	.byte	VOL , 17
	.byte	W03
	.byte	EOT
	.byte	FINE
	.globl sSong240_Part1
sSong240_Part1: @ 0x0886EDED
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	PAN , 64
	.byte	VOL , 23
	.byte	N30, Gn2, 32
	.byte	W01
	.byte	VOL , 51
	.byte	W01
	.byte	75
	.byte	W01
	.byte	99
	.byte	W01
	.byte	115
	.byte	W03
	.byte	99
	.byte	W02
	.byte	92
	.byte	W01
	.byte	97
	.byte	W02
	.byte	115
	.byte	W12
	.byte	PAN , 64
	.byte	W12
	.byte	W12
	.byte	64
	.byte	W12
	.byte	W12
	.byte	64
	.byte	W12
	.byte	W12
	.byte	64
	.byte	W12
	.byte	W12
	.byte	64
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86EE1A, 0x2
	.globl sSongHeader_240
sSongHeader_240: @ 0x0886EE1C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886ED28, 0x0886EDED  @ parts
