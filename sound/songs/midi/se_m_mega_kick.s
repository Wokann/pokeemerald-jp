.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong140_Part0
sSong140_Part0: @ 0x0886AD50
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 63
	.byte	BEND , 16
	.byte	N72, Fn4, 108
	.byte	W02
	.byte	VOL , 68
	.byte	BEND , 21
	.byte	W01
	.byte	PAN , 69
	.byte	W01
	.byte	BEND , 26
	.byte	W02
	.byte	PAN , 79
	.byte	VOL , 70
	.byte	W01
	.byte	BEND , 30
	.byte	W02
	.byte	PAN , 70
	.byte	VOL , 75
	.byte	BEND , 34
	.byte	W03
	.byte	PAN , 63
	.byte	BEND , 36
	.byte	W01
	.byte	VOL , 78
	.byte	W01
	.byte	BEND , 40
	.byte	W01
	.byte	PAN , 55
	.byte	W01
	.byte	VOL , 85
	.byte	BEND , 43
	.byte	W02
	.byte	PAN , 49
	.byte	W01
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 90
	.byte	W01
	.byte	PAN , 55
	.byte	BEND , 52
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 56
	.byte	W02
	.byte	61
	.byte	W01
	.byte	PAN , 69
	.byte	W01
	.byte	BEND , 66
	.byte	W02
	.byte	PAN , 79
	.byte	W01
	.byte	BEND , 69
	.byte	W02
	.byte	PAN , 70
	.byte	BEND , 73
	.byte	W03
	.byte	PAN , 63
	.byte	BEND , 75
	.byte	W02
	.byte	78
	.byte	W01
	.byte	PAN , 55
	.byte	W01
	.byte	BEND , 83
	.byte	W02
	.byte	PAN , 49
	.byte	W01
	.byte	BEND , 87
	.byte	W02
	.byte	PAN , 55
	.byte	BEND , 91
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 93
	.byte	W02
	.byte	97
	.byte	W01
	.byte	PAN , 69
	.byte	W01
	.byte	BEND , 99
	.byte	W02
	.byte	VOL , 74
	.byte	PAN , 79
	.byte	W01
	.byte	BEND , 102
	.byte	W02
	.byte	VOL , 58
	.byte	PAN , 70
	.byte	BEND , 106
	.byte	W03
	.byte	VOL , 47
	.byte	PAN , 63
	.byte	BEND , 109
	.byte	W02
	.byte	112
	.byte	W01
	.byte	VOL , 34
	.byte	PAN , 55
	.byte	W01
	.byte	BEND , 114
	.byte	W02
	.byte	VOL , 22
	.byte	PAN , 49
	.byte	W01
	.byte	BEND , 118
	.byte	W02
	.byte	VOL , 6
	.byte	PAN , 55
	.byte	BEND , 122
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AE0A, 0x2
	.globl sSongHeader_140
sSongHeader_140: @ 0x0886AE0C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong140_Part0  @ parts
