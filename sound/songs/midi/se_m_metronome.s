.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong186_Part0
sSong186_Part0: @ 0x0886C5E0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 37
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 115
	.byte	BEND , 64
	.byte	N15, En3, 127
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 60
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 57
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 53
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 59
	.byte	W02
	.byte	PAN , 68
	.byte	BEND , 64
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 67
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 70
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 73
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 78
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 84
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 89
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 110
	.byte	W10
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C62F, 0x1
	.globl sSongHeader_186
sSongHeader_186: @ 0x0886C630
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong186_Part0  @ parts
