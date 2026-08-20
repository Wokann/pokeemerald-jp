.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong118_Part0
sSong118_Part0: @ 0x0886A4B4
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 18
	.byte	VOL , 120
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 96
	.byte	N06, Dn3, 127
	.byte	W02
	.byte	PAN , 56
	.byte	W01
	.byte	BEND , 64
	.byte	W01
	.byte	PAN , 48
	.byte	W02
	.byte	64
	.byte	BEND , 96
	.byte	N06, Dn2, 104
	.byte	W02
	.byte	PAN , 73
	.byte	W01
	.byte	BEND , 52
	.byte	W01
	.byte	PAN , 80
	.byte	W02
	.byte	64
	.byte	BEND , 64
	.byte	N21, Dn3, 127
	.byte	W03
	.byte	PAN , 56
	.byte	W03
	.byte	49
	.byte	W01
	.byte	BEND , 51
	.byte	W02
	.byte	PAN , 57
	.byte	W01
	.byte	BEND , 41
	.byte	W02
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	BEND , 24
	.byte	W01
	.byte	VOL , 86
	.byte	W01
	.byte	BEND , 10
	.byte	W01
	.byte	PAN , 74
	.byte	VOL , 68
	.byte	W02
	.byte	37
	.byte	BEND , 0
	.byte	W01
	.byte	PAN , 80
	.byte	W02
	.byte	VOL , 17
	.byte	W01
	.byte	PAN , 74
	.byte	W15
	.byte	FINE
	.globl sSong118_Part1
sSong118_Part1: @ 0x0886A514
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 120
	.byte	PAN , 57
	.byte	N02, En3, 48
	.byte	W05
	.byte	PAN , 74
	.byte	N02, En3, 40
	.byte	W06
	.byte	PAN , 57
	.byte	N02, En3, 32
	.byte	W07
	.byte	PAN , 74
	.byte	N02, En3, 24
	.byte	W06
	.byte	PAN , 57
	.byte	N02, En3, 16
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A539, 0x3
	.globl sSongHeader_118
sSongHeader_118: @ 0x0886A53C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A4B4, 0x0886A514  @ parts
