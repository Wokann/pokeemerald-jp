.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong169_Part0
sSong169_Part0: @ 0x0886BBBC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 18
	.byte	BENDR , 12
	.byte	VOL , 55
	.byte	PAN , 64
	.byte	BEND , 65
	.byte	N01, Cn6, 100
	.byte	W01
	.byte	VOL , 110
	.byte	W01
	.byte	VOICE , 36
	.byte	VOL , 55
	.byte	N02, Gn6, 80
	.byte	W01
	.byte	VOL , 110
	.byte	W04
	.byte	PAN , 84
	.byte	N01, Gn6, 24
	.byte	W03
	.byte	Gn6, 16
	.byte	W02
	.byte	PAN , 43
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86BBE9, 0x3
	.globl sSongHeader_169
sSongHeader_169: @ 0x0886BBEC
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong169_Part0  @ parts
