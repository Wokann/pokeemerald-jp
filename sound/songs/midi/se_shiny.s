.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong102_Part0
sSong102_Part0: @ 0x08869BB4
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 46
	.byte	VOL , 95
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 65
	.byte	N03, Cn6, 127
	.byte	W01
	.byte	PAN , 66
	.byte	BEND , 66
	.byte	W01
	.byte	68
	.byte	W01
	.byte	65
	.byte	N06, Gn6
	.byte	W01
	.byte	PAN , 64
	.byte	W02
	.byte	W03
	.byte	BEND , 65
	.byte	N03, Cn6, 104
	.byte	W01
	.byte	PAN , 62
	.byte	BEND , 66
	.byte	W02
	.byte	68
	.byte	W01
	.byte	65
	.byte	N06, Gn6
	.byte	W01
	.byte	PAN , 64
	.byte	W04
	.byte	W01
	.byte	BEND , 65
	.byte	N03, Cs6, 80
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 66
	.byte	W01
	.byte	68
	.byte	W01
	.byte	65
	.byte	N06, Gs6
	.byte	W02
	.byte	PAN , 64
	.byte	W04
	.byte	BEND , 65
	.byte	N03, Cs6, 48
	.byte	W02
	.byte	PAN , 59
	.byte	BEND , 66
	.byte	W01
	.byte	68
	.byte	W01
	.byte	65
	.byte	N06, Gs6
	.byte	W01
	.byte	PAN , 64
	.byte	W03
	.byte	W02
	.byte	68
	.byte	BEND , 65
	.byte	N03, Cs6, 32
	.byte	W01
	.byte	BEND , 66
	.byte	W01
	.byte	68
	.byte	W02
	.byte	64
	.byte	N06, Gs6
	.byte	W06
	.byte	FINE
	.globl sSongHeader_102
sSongHeader_102: @ 0x08869C24
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong102_Part0  @ parts
