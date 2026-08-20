.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong236_Part0
sSong236_Part0: @ 0x0886E9C0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 61
	.byte	BENDR , 44
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 66
	.byte	N36, En3, 96
	.byte	W12
	.byte	PAN , 60
	.byte	BEND , 66
	.byte	W12
	.byte	PAN , 54
	.byte	BEND , 68
	.byte	W12
	.byte	PAN , 60
	.byte	BEND , 69
	.byte	N36, Fn3
	.byte	W12
	.byte	PAN , 64
	.byte	BEND , 70
	.byte	W12
	.byte	PAN , 70
	.byte	BEND , 71
	.byte	W12
	.byte	PAN , 73
	.byte	BEND , 72
	.byte	N36, En3, 88
	.byte	W12
	.byte	PAN , 69
	.byte	BEND , 72
	.byte	W12
	.byte	PAN , 64
	.byte	BEND , 73
	.byte	W12
	.byte	PAN , 60
	.byte	BEND , 74
	.byte	N60, Fs3, 56
	.byte	W12
	.byte	PAN , 54
	.byte	BEND , 75
	.byte	W12
	.byte	PAN , 60
	.byte	BEND , 76
	.byte	W04
	.byte	VOL , 103
	.byte	W04
	.byte	97
	.byte	W04
	.byte	PAN , 64
	.byte	BEND , 76
	.byte	W01
	.byte	VOL , 91
	.byte	W05
	.byte	81
	.byte	W03
	.byte	72
	.byte	W03
	.byte	PAN , 70
	.byte	BEND , 77
	.byte	W01
	.byte	VOL , 62
	.byte	W02
	.byte	51
	.byte	W03
	.byte	39
	.byte	W02
	.byte	24
	.byte	W02
	.byte	12
	.byte	W02
	.byte	FINE
	.globl sSong236_Part1
sSong236_Part1: @ 0x0886EA33
	.byte	KEYSH , 0
	.byte	VOICE , 22
	.byte	BENDR , 44
	.byte	PAN , 65
	.byte	VOL , 38
	.byte	BEND , 65
	.byte	TIE , 67, 100
	.byte	W03
	.byte	VOL , 50
	.byte	W04
	.byte	62
	.byte	W02
	.byte	BEND , 63
	.byte	W01
	.byte	VOL , 65
	.byte	W04
	.byte	74
	.byte	W04
	.byte	78
	.byte	BEND , 62
	.byte	W03
	.byte	VOL , 86
	.byte	W03
	.byte	95
	.byte	W03
	.byte	105
	.byte	W01
	.byte	BEND , 60
	.byte	W03
	.byte	VOL , 110
	.byte	W13
	.byte	BEND , 62
	.byte	W04
	.byte	W10
	.byte	63
	.byte	W10
	.byte	64
	.byte	W04
	.byte	W03
	.byte	65
	.byte	W10
	.byte	65
	.byte	W11
	.byte	W02
	.byte	66
	.byte	W14
	.byte	67
	.byte	W08
	.byte	VOL , 105
	.byte	W03
	.byte	101
	.byte	W05
	.byte	96
	.byte	W04
	.byte	BEND , 66
	.byte	W01
	.byte	VOL , 91
	.byte	W03
	.byte	86
	.byte	W05
	.byte	78
	.byte	W03
	.byte	W02
	.byte	68
	.byte	W01
	.byte	BEND , 65
	.byte	W04
	.byte	VOL , 58
	.byte	W03
	.byte	48
	.byte	W04
	.byte	37
	.byte	BEND , 64
	.byte	W04
	.byte	VOL , 23
	.byte	W01
	.byte	BEND , 63
	.byte	W02
	.byte	VOL , 12
	.byte	W03
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86EA9E, 0x2
	.globl sSongHeader_236
sSongHeader_236: @ 0x0886EAA0
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E9C0, 0x0886EA33  @ parts
