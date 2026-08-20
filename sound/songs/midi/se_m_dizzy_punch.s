.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong176_Part0
sSong176_Part0: @ 0x0886C06C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 19
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 5
	.byte	BEND , 64
	.byte	N07, Bn5, 80
	.byte	W01
	.byte	VOL , 55
	.byte	PAN , 75
	.byte	BEND , 67
	.byte	W01
	.byte	VOL , 67
	.byte	PAN , 86
	.byte	BEND , 64
	.byte	W01
	.byte	VOL , 90
	.byte	PAN , 64
	.byte	BEND , 58
	.byte	W01
	.byte	PAN , 52
	.byte	BEND , 50
	.byte	W02
	.byte	VOL , 4
	.byte	PAN , 42
	.byte	BEND , 41
	.byte	W01
	.byte	PAN , 51
	.byte	BEND , 64
	.byte	N04, Cn6
	.byte	W01
	.byte	VOL , 66
	.byte	PAN , 64
	.byte	BEND , 65
	.byte	W01
	.byte	VOL , 90
	.byte	PAN , 75
	.byte	BEND , 67
	.byte	W01
	.byte	VOL , 4
	.byte	PAN , 85
	.byte	BEND , 69
	.byte	W14
	.byte	VOL , 90
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C0BE, 0x2
	.globl sSongHeader_176
sSongHeader_176: @ 0x0886C0C0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong176_Part0  @ parts
