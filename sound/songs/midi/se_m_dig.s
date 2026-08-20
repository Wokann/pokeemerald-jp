.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong175_Part0
sSong175_Part0: @ 0x0886C024
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 115
	.byte	BEND , 64
	.byte	N01, Cn2, 112
	.byte	W01
	.byte	VOICE , 26
	.byte	N02, Cn3, 127
	.byte	W01
	.byte	PAN , 69
	.byte	BEND , 68
	.byte	W01
	.byte	80
	.byte	N03
	.byte	W01
	.byte	PAN , 56
	.byte	BEND , 92
	.byte	W02
	.byte	109
	.byte	W01
	.byte	VOICE , 36
	.byte	PAN , 76
	.byte	BEND , 64
	.byte	N02, Cn3, 56
	.byte	W02
	.byte	W03
	.byte	PAN , 52
	.byte	N02, Cn3, 36
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C05D, 0x3
	.globl sSongHeader_175
sSongHeader_175: @ 0x0886C060
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong175_Part0  @ parts
