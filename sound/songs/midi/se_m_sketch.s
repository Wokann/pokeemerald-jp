.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong205_Part0
sSong205_Part0: @ 0x0886D180
	.byte	KEYSH , 0
	.byte	TEMPO , 90
	.byte	VOICE , 38
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N02, Gn4, 127
	.byte	W01
	.byte	VOL , 74
	.byte	BEND , 53
	.byte	W01
	.byte	VOICE , 31
	.byte	VOL , 40
	.byte	BEND , 63
	.byte	N03, Cs5
	.byte	W01
	.byte	VOL , 64
	.byte	PAN , 58
	.byte	BEND , 52
	.byte	W01
	.byte	VOL , 86
	.byte	PAN , 68
	.byte	BEND , 48
	.byte	W02
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N02, As5
	.byte	W01
	.byte	BEND , 76
	.byte	W01
	.byte	VOL , 0
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D1BE, 0x2
	.globl sSongHeader_205
sSongHeader_205: @ 0x0886D1C0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong205_Part0  @ parts
