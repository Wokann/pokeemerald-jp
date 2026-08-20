.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong213_Part0
sSong213_Part0: @ 0x0886D7EC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 18
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 34
	.byte	BEND , 64
	.byte	N66, Cn5, 127
	.byte	W01
	.byte	PAN , 62
	.byte	W01
	.byte	VOL , 43
	.byte	PAN , 64
	.byte	W01
	.byte	66
	.byte	BEND , 62
	.byte	W01
	.byte	VOL , 58
	.byte	PAN , 64
	.byte	W02
	.byte	62
	.byte	W01
	.byte	VOL , 70
	.byte	PAN , 60
	.byte	BEND , 60
	.byte	W01
	.byte	PAN , 62
	.byte	W01
	.byte	VOL , 76
	.byte	PAN , 64
	.byte	W01
	.byte	66
	.byte	BEND , 58
	.byte	W02
	.byte	VOL , 90
	.byte	PAN , 68
	.byte	W01
	.byte	66
	.byte	W01
	.byte	64
	.byte	BEND , 56
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	62
	.byte	W02
	.byte	64
	.byte	BEND , 51
	.byte	W01
	.byte	PAN , 66
	.byte	W01
	.byte	64
	.byte	W01
	.byte	62
	.byte	BEND , 49
	.byte	W01
	.byte	PAN , 60
	.byte	W02
	.byte	62
	.byte	W01
	.byte	64
	.byte	BEND , 45
	.byte	W01
	.byte	PAN , 66
	.byte	W01
	.byte	68
	.byte	BEND , 42
	.byte	W01
	.byte	PAN , 66
	.byte	W02
	.byte	64
	.byte	BEND , 45
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	62
	.byte	BEND , 47
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	66
	.byte	W02
	.byte	64
	.byte	BEND , 45
	.byte	W01
	.byte	PAN , 62
	.byte	W01
	.byte	60
	.byte	W01
	.byte	62
	.byte	BEND , 42
	.byte	W01
	.byte	PAN , 64
	.byte	W02
	.byte	66
	.byte	BEND , 36
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 40
	.byte	W01
	.byte	PAN , 66
	.byte	W01
	.byte	VOL , 84
	.byte	PAN , 64
	.byte	W01
	.byte	64
	.byte	W02
	.byte	62
	.byte	W01
	.byte	VOL , 78
	.byte	PAN , 64
	.byte	W01
	.byte	66
	.byte	BEND , 37
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 70
	.byte	PAN , 62
	.byte	W02
	.byte	60
	.byte	W01
	.byte	VOL , 55
	.byte	PAN , 62
	.byte	BEND , 35
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 46
	.byte	PAN , 66
	.byte	W01
	.byte	68
	.byte	BEND , 33
	.byte	W02
	.byte	VOL , 36
	.byte	PAN , 66
	.byte	W01
	.byte	64
	.byte	W01
	.byte	VOL , 24
	.byte	PAN , 64
	.byte	BEND , 28
	.byte	W01
	.byte	PAN , 62
	.byte	W01
	.byte	VOL , 13
	.byte	PAN , 64
	.byte	BEND , 22
	.byte	W02
	.byte	VOL , 5
	.byte	PAN , 66
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D8CD, 0x3
	.globl sSongHeader_213
sSongHeader_213: @ 0x0886D8D0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong213_Part0  @ parts
