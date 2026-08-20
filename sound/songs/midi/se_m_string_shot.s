.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong129_Part0
sSong129_Part0: @ 0x0886A93C
	.byte	KEYSH , 0
	.byte	TEMPO , 125
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N48, Fn4, 108
	.byte	W03
	.byte	PAN , 69
	.byte	BEND , 70
	.byte	W03
	.byte	PAN , 79
	.byte	BEND , 76
	.byte	W03
	.byte	PAN , 70
	.byte	BEND , 85
	.byte	W02
	.byte	72
	.byte	W01
	.byte	PAN , 63
	.byte	W03
	.byte	55
	.byte	BEND , 56
	.byte	W03
	.byte	PAN , 49
	.byte	BEND , 50
	.byte	W03
	.byte	PAN , 55
	.byte	BEND , 56
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W06
	.byte	VOL , 90
	.byte	W03
	.byte	71
	.byte	W03
	.byte	58
	.byte	W03
	.byte	41
	.byte	W03
	.byte	27
	.byte	W03
	.byte	7
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A983, 0x1
	.globl sSongHeader_129
sSongHeader_129: @ 0x0886A984
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong129_Part0  @ parts
