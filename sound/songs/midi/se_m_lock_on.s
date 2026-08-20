.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong210_Part0
sSong210_Part0: @ 0x0886D5F8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 40
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N01, Cn4, 100
	.byte	W01
	.byte	Gn3, 64
	.byte	W01
	.byte	N03, Bn3, 100
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 70
	.byte	W01
	.byte	PAN , 59
	.byte	BEND , 58
	.byte	W02
	.byte	PAN , 70
	.byte	BEND , 70
	.byte	N01, Cn4
	.byte	W01
	.byte	Gn3, 64
	.byte	W02
	.byte	PAN , 59
	.byte	BEND , 58
	.byte	N01, Bn3, 100
	.byte	W01
	.byte	Gn3, 64
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N06, Bn3, 100
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D639, 0x3
	.globl sSongHeader_210
sSongHeader_210: @ 0x0886D63C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong210_Part0  @ parts
