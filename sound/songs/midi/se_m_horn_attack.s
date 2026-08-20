.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong166_Part0
sSong166_Part0: @ 0x0886BAB8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 21
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 65
	.byte	N01, Bn5, 127
	.byte	W02
	.byte	VOICE , 18
	.byte	N01, Cn4
	.byte	W02
	.byte	VOICE , 36
	.byte	N06, Gn5, 40
	.byte	W02
	.byte	VOL , 58
	.byte	PAN , 80
	.byte	BEND , 69
	.byte	W01
	.byte	VOL , 71
	.byte	PAN , 50
	.byte	BEND , 77
	.byte	W01
	.byte	VOL , 84
	.byte	PAN , 80
	.byte	BEND , 85
	.byte	W01
	.byte	VOL , 97
	.byte	PAN , 50
	.byte	BEND , 97
	.byte	W01
	.byte	VOL , 110
	.byte	W14
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86BAF5, 0x3
	.globl sSongHeader_166
sSongHeader_166: @ 0x0886BAF8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong166_Part0  @ parts
