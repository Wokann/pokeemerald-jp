.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong180_Part0
sSong180_Part0: @ 0x0886C260
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 24
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N01, Cn6, 127
	.byte	W01
	.byte	Gn6, 112
	.byte	W01
	.byte	VOICE , 38
	.byte	VOL , 58
	.byte	N08, Gn4
	.byte	W01
	.byte	VOL , 68
	.byte	PAN , 72
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 75
	.byte	PAN , 56
	.byte	BEND , 16
	.byte	W02
	.byte	VOL , 83
	.byte	PAN , 72
	.byte	BEND , 46
	.byte	W01
	.byte	VOL , 90
	.byte	PAN , 56
	.byte	BEND , 74
	.byte	W01
	.byte	VOL , 101
	.byte	PAN , 73
	.byte	BEND , 103
	.byte	W01
	.byte	VOL , 110
	.byte	PAN , 56
	.byte	BEND , 127
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C2A7, 0x1
	.globl sSongHeader_180
sSongHeader_180: @ 0x0886C2A8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong180_Part0  @ parts
