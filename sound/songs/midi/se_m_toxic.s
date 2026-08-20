.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong148_Part0
sSong148_Part0: @ 0x0886B1AC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 31
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N02, Dn2, 127
	.byte	W01
	.byte	BEND , 96
	.byte	W01
	.byte	VOICE , 23
	.byte	BEND , 64
	.byte	N02, Gn1, 112
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 127
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N02, Cn2
	.byte	W02
	.byte	PAN , 57
	.byte	BEND , 80
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W01
	.byte	N01
	.byte	W01
	.byte	PAN , 72
	.byte	N01, Cn3
	.byte	W01
	.byte	VOICE , 31
	.byte	PAN , 48
	.byte	N01, Dn2
	.byte	W02
	.byte	VOICE , 23
	.byte	PAN , 64
	.byte	N01, Cn2
	.byte	W01
	.byte	VOICE , 31
	.byte	PAN , 80
	.byte	N01, Dn2, 96
	.byte	W01
	.byte	VOICE , 23
	.byte	PAN , 56
	.byte	BEND , 80
	.byte	N01, Cn3
	.byte	W02
	.byte	PAN , 72
	.byte	N01, Cn2
	.byte	W08
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B20B, 0x1
	.globl sSongHeader_148
sSongHeader_148: @ 0x0886B20C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong148_Part0  @ parts
