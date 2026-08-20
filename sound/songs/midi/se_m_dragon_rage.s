.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong171_Part0
sSong171_Part0: @ 0x0886BC50
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	PAN , 69
	.byte	VOL , 21
	.byte	BEND , 64
	.byte	N10, An2, 127
	.byte	W02
	.byte	VOL , 47
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 88
	.byte	W02
	.byte	PAN , 59
	.byte	W01
	.byte	VOL , 120
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 21
	.byte	BEND , 74
	.byte	N10, Bn2
	.byte	W02
	.byte	PAN , 69
	.byte	W01
	.byte	VOL , 47
	.byte	W02
	.byte	PAN , 64
	.byte	VOL , 88
	.byte	W03
	.byte	PAN , 59
	.byte	VOL , 120
	.byte	W03
	.byte	PAN , 62
	.byte	VOL , 21
	.byte	BEND , 82
	.byte	N10, Cs3
	.byte	W03
	.byte	PAN , 69
	.byte	VOL , 47
	.byte	W02
	.byte	88
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 120
	.byte	W02
	.byte	PAN , 59
	.byte	W02
	.byte	VOL , 20
	.byte	BEND , 93
	.byte	N10, Dn3
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 47
	.byte	W02
	.byte	PAN , 69
	.byte	W01
	.byte	VOL , 88
	.byte	W02
	.byte	PAN , 64
	.byte	VOL , 120
	.byte	W03
	.byte	PAN , 59
	.byte	W01
	.byte	VOL , 21
	.byte	BEND , 101
	.byte	N10, En3
	.byte	W02
	.byte	PAN , 62
	.byte	VOL , 46
	.byte	W03
	.byte	PAN , 69
	.byte	VOL , 102
	.byte	W02
	.byte	120
	.byte	W01
	.byte	PAN , 64
	.byte	W03
	.byte	59
	.byte	VOL , 20
	.byte	BEND , 106
	.byte	N20, Fs3
	.byte	W02
	.byte	VOL , 47
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 88
	.byte	W02
	.byte	PAN , 69
	.byte	W01
	.byte	VOL , 120
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 99
	.byte	BEND , 114
	.byte	W02
	.byte	PAN , 59
	.byte	W01
	.byte	VOL , 74
	.byte	W01
	.byte	BEND , 120
	.byte	W01
	.byte	PAN , 62
	.byte	VOL , 53
	.byte	W03
	.byte	34
	.byte	BEND , 127
	.byte	W01
	.byte	VOL , 15
	.byte	W23
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86BD0A, 0x2
	.globl sSongHeader_171
sSongHeader_171: @ 0x0886BD0C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong171_Part0  @ parts
