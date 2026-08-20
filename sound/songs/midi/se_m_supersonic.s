.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong184_Part0
sSong184_Part0: @ 0x0886C4B4
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 43
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	VOL , 61
	.byte	BEND , 60
	.byte	N07, Gs4, 127
	.byte	W01
	.byte	PAN , 70
	.byte	VOL , 75
	.byte	BEND , 63
	.byte	W01
	.byte	PAN , 57
	.byte	VOL , 93
	.byte	BEND , 66
	.byte	W01
	.byte	PAN , 73
	.byte	VOL , 110
	.byte	BEND , 68
	.byte	W01
	.byte	PAN , 52
	.byte	BEND , 71
	.byte	W02
	.byte	W02
	.byte	VOL , 0
	.byte	PAN , 64
	.byte	BEND , 60
	.byte	N32
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 63
	.byte	W01
	.byte	PAN , 57
	.byte	VOL , 36
	.byte	BEND , 66
	.byte	W02
	.byte	PAN , 73
	.byte	VOL , 67
	.byte	BEND , 63
	.byte	W01
	.byte	PAN , 51
	.byte	VOL , 84
	.byte	BEND , 60
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 58
	.byte	W01
	.byte	PAN , 58
	.byte	VOL , 92
	.byte	BEND , 56
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 57
	.byte	W02
	.byte	PAN , 70
	.byte	VOL , 99
	.byte	BEND , 60
	.byte	W01
	.byte	PAN , 57
	.byte	BEND , 63
	.byte	W01
	.byte	VOL , 105
	.byte	PAN , 73
	.byte	BEND , 66
	.byte	W01
	.byte	VOL , 110
	.byte	PAN , 51
	.byte	BEND , 63
	.byte	W01
	.byte	PAN , 63
	.byte	BEND , 60
	.byte	W02
	.byte	VOL , 46
	.byte	PAN , 64
	.byte	BEND , 63
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 66
	.byte	W01
	.byte	VOL , 67
	.byte	PAN , 57
	.byte	BEND , 63
	.byte	W01
	.byte	PAN , 73
	.byte	BEND , 60
	.byte	W01
	.byte	VOL , 84
	.byte	PAN , 51
	.byte	BEND , 58
	.byte	W02
	.byte	VOL , 100
	.byte	PAN , 70
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 110
	.byte	PAN , 58
	.byte	BEND , 57
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 60
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 63
	.byte	W01
	.byte	VOL , 101
	.byte	PAN , 57
	.byte	BEND , 66
	.byte	W02
	.byte	VOL , 85
	.byte	PAN , 73
	.byte	BEND , 63
	.byte	W01
	.byte	VOL , 75
	.byte	PAN , 51
	.byte	BEND , 60
	.byte	W01
	.byte	VOL , 48
	.byte	PAN , 63
	.byte	BEND , 58
	.byte	W01
	.byte	VOL , 24
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 6
	.byte	BEND , 57
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C591, 0x3
	.globl sSongHeader_184
sSongHeader_184: @ 0x0886C594
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong184_Part0  @ parts
