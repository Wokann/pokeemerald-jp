.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong209_Part0
sSong209_Part0: @ 0x0886D58C
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 54
	.byte	VOL , 100
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 65
	.byte	N03, As5, 127
	.byte	W01
	.byte	PAN , 66
	.byte	BEND , 66
	.byte	W01
	.byte	68
	.byte	W01
	.byte	65
	.byte	N06, Bn5
	.byte	W01
	.byte	PAN , 64
	.byte	W02
	.byte	W03
	.byte	BEND , 65
	.byte	N03, As5, 104
	.byte	W01
	.byte	PAN , 62
	.byte	BEND , 66
	.byte	W02
	.byte	68
	.byte	W01
	.byte	65
	.byte	N06, Bn5
	.byte	W01
	.byte	PAN , 64
	.byte	W04
	.byte	W01
	.byte	BEND , 65
	.byte	N03, As5, 80
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 66
	.byte	W01
	.byte	68
	.byte	W01
	.byte	65
	.byte	N06, Bn5
	.byte	W02
	.byte	PAN , 64
	.byte	W04
	.byte	BEND , 65
	.byte	N03, As5, 48
	.byte	W02
	.byte	PAN , 59
	.byte	BEND , 66
	.byte	W01
	.byte	68
	.byte	W01
	.byte	65
	.byte	N06, Bn5
	.byte	W01
	.byte	PAN , 64
	.byte	W03
	.byte	W06
	.byte	FINE
	.globl sSongHeader_209
sSongHeader_209: @ 0x0886D5EC
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong209_Part0  @ parts
