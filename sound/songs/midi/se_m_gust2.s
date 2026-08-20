.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong133_Part0
sSong133_Part0: @ 0x0886AAFC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N24, Cn3, 108
	.byte	W02
	.byte	PAN , 45
	.byte	W04
	.byte	64
	.byte	W01
	.byte	VOL , 97
	.byte	W01
	.byte	PAN , 80
	.byte	W01
	.byte	VOL , 84
	.byte	W03
	.byte	76
	.byte	PAN , 66
	.byte	W02
	.byte	VOL , 55
	.byte	PAN , 56
	.byte	W02
	.byte	VOL , 39
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 25
	.byte	W01
	.byte	PAN , 72
	.byte	W01
	.byte	VOL , 13
	.byte	W03
	.byte	7
	.byte	PAN , 64
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AB39, 0x3
	.globl sSongHeader_133
sSongHeader_133: @ 0x0886AB3C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong133_Part0  @ parts
