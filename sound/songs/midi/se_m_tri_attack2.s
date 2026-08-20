.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong221_Part0
sSong221_Part0: @ 0x0886DEDC
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 18
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N09, An3, 127
	.byte	W03
	.byte	BEND , 85
	.byte	W03
	.byte	64
	.byte	W03
	.byte	70
	.byte	N15, An3, 120
	.byte	W03
	.byte	BEND , 66
	.byte	W01
	.byte	PAN , 74
	.byte	W02
	.byte	BEND , 55
	.byte	W03
	.byte	PAN , 55
	.byte	BEND , 35
	.byte	W06
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N09, Cn3, 127
	.byte	W06
	.byte	BEND , 56
	.byte	W03
	.byte	49
	.byte	N60, Cs3, 124
	.byte	W03
	.byte	BEND , 60
	.byte	W03
	.byte	PAN , 74
	.byte	W06
	.byte	64
	.byte	BEND , 56
	.byte	W03
	.byte	W03
	.byte	PAN , 55
	.byte	W03
	.byte	BEND , 51
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 42
	.byte	W06
	.byte	VOL , 103
	.byte	PAN , 74
	.byte	W03
	.byte	BEND , 32
	.byte	W03
	.byte	PAN , 64
	.byte	W03
	.byte	VOL , 95
	.byte	BEND , 26
	.byte	W03
	.byte	PAN , 55
	.byte	W05
	.byte	BEND , 19
	.byte	W01
	.byte	VOL , 66
	.byte	PAN , 64
	.byte	W05
	.byte	74
	.byte	W01
	.byte	BEND , 12
	.byte	W03
	.byte	VOL , 21
	.byte	W02
	.byte	PAN , 64
	.byte	W04
	.byte	FINE
	.globl sSong221_Part1
sSong221_Part1: @ 0x0886DF53
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 110
	.byte	N06, Cn3, 60
	.byte	W09
	.byte	N15
	.byte	W15
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86DF63, 0x1
	.globl sSongHeader_221
sSongHeader_221: @ 0x0886DF64
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886DEDC, 0x0886DF53  @ parts
