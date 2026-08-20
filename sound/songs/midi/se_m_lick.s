.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong188_Part0
sSong188_Part0: @ 0x0886C674
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 31
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 59
	.byte	N32, Cn3, 127
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 55
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 51
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 44
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 39
	.byte	W02
	.byte	PAN , 68
	.byte	BEND , 25
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 58
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 61
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 70
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 67
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 73
	.byte	W01
	.byte	PAN , 60
	.byte	BEND , 70
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 76
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 72
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 80
	.byte	W02
	.byte	PAN , 60
	.byte	VOL , 102
	.byte	BEND , 76
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 80
	.byte	W01
	.byte	PAN , 68
	.byte	VOL , 97
	.byte	BEND , 82
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 78
	.byte	W01
	.byte	PAN , 60
	.byte	VOL , 92
	.byte	BEND , 82
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 84
	.byte	W01
	.byte	PAN , 68
	.byte	VOL , 88
	.byte	BEND , 81
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 76
	.byte	W01
	.byte	PAN , 60
	.byte	VOL , 81
	.byte	BEND , 80
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 64
	.byte	BEND , 76
	.byte	W02
	.byte	PAN , 68
	.byte	VOL , 49
	.byte	BEND , 78
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 25
	.byte	BEND , 75
	.byte	W05
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C719, 0x3
	.globl sSongHeader_188
sSongHeader_188: @ 0x0886C71C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong188_Part0  @ parts
