.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong193_Part0
sSong193_Part0: @ 0x0886C9D4
	.byte	KEYSH , 0
	.byte	TEMPO , 95
	.byte	VOICE , 2
	.byte	BENDR , 8
	.byte	PAN , 64
	.byte	VOL , 28
	.byte	BEND , 64
	.byte	N15, An1, 127
	.byte	W01
	.byte	VOL , 60
	.byte	W01
	.byte	111
	.byte	W01
	.byte	120
	.byte	W01
	.byte	BEND , 61
	.byte	W02
	.byte	PAN , 69
	.byte	BEND , 58
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 109
	.byte	PAN , 73
	.byte	BEND , 54
	.byte	W01
	.byte	PAN , 55
	.byte	BEND , 50
	.byte	W01
	.byte	VOL , 95
	.byte	PAN , 64
	.byte	BEND , 45
	.byte	W02
	.byte	VOL , 71
	.byte	BEND , 35
	.byte	W01
	.byte	VOL , 41
	.byte	BEND , 26
	.byte	W01
	.byte	VOL , 15
	.byte	BEND , 12
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86CA1D, 0x3
	.globl sSongHeader_193
sSongHeader_193: @ 0x0886CA20
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong193_Part0  @ parts
