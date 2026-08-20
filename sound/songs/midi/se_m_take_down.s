.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong152_Part0
sSong152_Part0: @ 0x0886B3A8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 105
	.byte	BEND , 16
	.byte	N10, Gn0, 127
	.byte	W02
	.byte	PAN , 71
	.byte	BEND , 32
	.byte	W01
	.byte	48
	.byte	W01
	.byte	PAN , 75
	.byte	BEND , 64
	.byte	W02
	.byte	79
	.byte	W01
	.byte	PAN , 78
	.byte	W01
	.byte	BEND , 96
	.byte	W01
	.byte	PAN , 83
	.byte	W03
	.byte	64
	.byte	VOL , 105
	.byte	BEND , 32
	.byte	N10
	.byte	W02
	.byte	PAN , 56
	.byte	BEND , 48
	.byte	W01
	.byte	64
	.byte	W01
	.byte	PAN , 53
	.byte	BEND , 80
	.byte	W02
	.byte	96
	.byte	W01
	.byte	PAN , 49
	.byte	W01
	.byte	BEND , 112
	.byte	W01
	.byte	PAN , 44
	.byte	W03
	.byte	64
	.byte	VOL , 105
	.byte	BEND , 48
	.byte	N10
	.byte	W02
	.byte	BEND , 64
	.byte	W01
	.byte	80
	.byte	W01
	.byte	96
	.byte	W02
	.byte	111
	.byte	W02
	.byte	127
	.byte	W16
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B402, 0x2
	.globl sSongHeader_152
sSongHeader_152: @ 0x0886B404
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong152_Part0  @ parts
