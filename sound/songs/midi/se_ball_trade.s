.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong60_Part0
sSong60_Part0: @ 0x0886911C
	.byte	KEYSH , 0
	.byte	VOICE , 13
	.byte	BENDR , 12
	.byte	VOL , 12
	.byte	BEND , 113
	.byte	N06, Gn4, 80
	.byte	W01
	.byte	VOL , 44
	.byte	BEND , 86
	.byte	W01
	.byte	VOL , 75
	.byte	BEND , 84
	.byte	W01
	.byte	VOL , 87
	.byte	BEND , 97
	.byte	W01
	.byte	VOL , 100
	.byte	BEND , 118
	.byte	W01
	.byte	127
	.byte	W01
	.byte	W03
	.byte	N03, Gn4, 40
	.byte	W03
	.byte	FINE
	.globl sSong60_Part1
sSong60_Part1: @ 0x08869146
	.byte	KEYSH , 0
	.byte	VOICE , 123
	.byte	VOL , 59
	.byte	N06, Gs4, 52
	.byte	W01
	.byte	VOL , 72
	.byte	W01
	.byte	90
	.byte	W01
	.byte	100
	.byte	W03
	.byte	W03
	.byte	N03, Gs4, 24
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86915D, 0x3
	.globl sSongHeader_60
sSongHeader_60: @ 0x08869160
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x0886911C, 0x08869146  @ parts
