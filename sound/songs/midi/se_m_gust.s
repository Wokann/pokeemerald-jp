.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong132_Part0
sSong132_Part0: @ 0x0886AA80
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 64
	.byte	BEND , 64
	.byte	N24, Cn3, 108
	.byte	W03
	.byte	VOL , 79
	.byte	BEND , 86
	.byte	W02
	.byte	72
	.byte	W01
	.byte	VOL , 84
	.byte	PAN , 60
	.byte	W03
	.byte	VOL , 91
	.byte	BEND , 64
	.byte	W03
	.byte	VOL , 100
	.byte	PAN , 56
	.byte	W03
	.byte	VOL , 110
	.byte	W03
	.byte	PAN , 52
	.byte	W06
	.byte	PAN , 47
	.byte	BEND , 64
	.byte	N48, Cn3, 108
	.byte	W03
	.byte	BEND , 57
	.byte	W03
	.byte	PAN , 55
	.byte	BEND , 52
	.byte	W03
	.byte	44
	.byte	W03
	.byte	PAN , 61
	.byte	W03
	.byte	70
	.byte	BEND , 51
	.byte	W03
	.byte	PAN , 74
	.byte	W03
	.byte	BEND , 58
	.byte	W03
	.byte	PAN , 80
	.byte	W03
	.byte	BEND , 70
	.byte	W03
	.byte	PAN , 77
	.byte	BEND , 75
	.byte	W03
	.byte	84
	.byte	W03
	.byte	PAN , 72
	.byte	W03
	.byte	64
	.byte	BEND , 76
	.byte	W03
	.byte	PAN , 56
	.byte	BEND , 71
	.byte	W03
	.byte	PAN , 53
	.byte	W03
	.byte	GOTO , 174, 170
	.byte	W06
	.byte	8
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AAEF, 0x1
	.globl sSongHeader_132
sSongHeader_132: @ 0x0886AAF0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong132_Part0  @ parts
