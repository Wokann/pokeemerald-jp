.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong139_Part0
sSong139_Part0: @ 0x0886ACFC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 6
	.byte	VOL , 120
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, Cn3, 127
	.byte	W01
	.byte	PAN , 54
	.byte	BEND , 37
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 17
	.byte	W01
	.byte	0
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 65
	.byte	N02, Dn3, 84
	.byte	W02
	.byte	BEND , 32
	.byte	W18
	.byte	FINE
	.globl sSong139_Part1
sSong139_Part1: @ 0x0886AD26
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 120
	.byte	PAN , 73
	.byte	N03, An2, 52
	.byte	W04
	.byte	N02
	.byte	W02
	.byte	PAN , 56
	.byte	W18
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AD3D, 0x3
	.globl sSongHeader_139
sSongHeader_139: @ 0x0886AD40
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886ACFC, 0x0886AD26  @ parts
