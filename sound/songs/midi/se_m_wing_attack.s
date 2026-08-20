.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong157_Part0
sSong157_Part0: @ 0x0886B58C
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 40
	.byte	BEND , 32
	.byte	N10, An1, 127
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 74
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 68
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W01
	.byte	VOL , 82
	.byte	PAN , 55
	.byte	BEND , 72
	.byte	W01
	.byte	VOL , 105
	.byte	PAN , 64
	.byte	BEND , 83
	.byte	W02
	.byte	PAN , 74
	.byte	BEND , 92
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 102
	.byte	W01
	.byte	PAN , 55
	.byte	BEND , 113
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 127
	.byte	W05
	.byte	VOL , 40
	.byte	BEND , 65
	.byte	N06
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 74
	.byte	BEND , 102
	.byte	W01
	.byte	VOL , 79
	.byte	PAN , 64
	.byte	BEND , 112
	.byte	W02
	.byte	VOL , 105
	.byte	PAN , 55
	.byte	BEND , 127
	.byte	W01
	.byte	PAN , 64
	.byte	W05
	.byte	FINE
	.globl sSong157_Part1
sSong157_Part1: @ 0x0886B5ED
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	PAN , 64
	.byte	VOL , 52
	.byte	N10, Gn2, 40
	.byte	W01
	.byte	VOL , 69
	.byte	W01
	.byte	83
	.byte	W01
	.byte	105
	.byte	W01
	.byte	85
	.byte	W02
	.byte	52
	.byte	W01
	.byte	29
	.byte	W01
	.byte	12
	.byte	W06
	.byte	VOICE , 25
	.byte	VOL , 52
	.byte	N06, Gs4
	.byte	W01
	.byte	VOL , 81
	.byte	W01
	.byte	105
	.byte	W03
	.byte	52
	.byte	W05
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B617, 0x1
	.globl sSongHeader_157
sSongHeader_157: @ 0x0886B618
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B58C, 0x0886B5ED  @ parts
