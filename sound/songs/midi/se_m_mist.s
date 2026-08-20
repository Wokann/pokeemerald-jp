.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong168_Part0
sSong168_Part0: @ 0x0886BB44
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 7
	.byte	BEND , 65
	.byte	N18, Cn5, 52
	.byte	W01
	.byte	VOL , 20
	.byte	PAN , 80
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 41
	.byte	PAN , 50
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 70
	.byte	PAN , 80
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 93
	.byte	PAN , 50
	.byte	BEND , 64
	.byte	W02
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 72
	.byte	W01
	.byte	PAN , 80
	.byte	BEND , 80
	.byte	W01
	.byte	PAN , 50
	.byte	W01
	.byte	VOL , 98
	.byte	PAN , 80
	.byte	BEND , 74
	.byte	W01
	.byte	VOL , 85
	.byte	PAN , 50
	.byte	BEND , 68
	.byte	W02
	.byte	VOL , 69
	.byte	PAN , 64
	.byte	BEND , 57
	.byte	W01
	.byte	VOL , 51
	.byte	PAN , 80
	.byte	BEND , 42
	.byte	W01
	.byte	PAN , 50
	.byte	VOL , 38
	.byte	BEND , 36
	.byte	W01
	.byte	VOL , 17
	.byte	BEND , 32
	.byte	W01
	.byte	VOL , 4
	.byte	BEND , 26
	.byte	W08
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86BBAF, 0x1
	.globl sSongHeader_168
sSongHeader_168: @ 0x0886BBB0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong168_Part0  @ parts
