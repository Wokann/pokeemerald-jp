.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong97_Part0
sSong97_Part0: @ 0x08869A60
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 25
	.byte	VOL , 12
	.byte	BEND , 64
	.byte	N12, Gs4, 60
	.byte	W01
	.byte	VOL , 22
	.byte	W01
	.byte	33
	.byte	W01
	.byte	46
	.byte	W01
	.byte	58
	.byte	W02
	.byte	70
	.byte	W02
	.byte	60
	.byte	W01
	.byte	42
	.byte	W01
	.byte	22
	.byte	W02
	.byte	FINE
	.globl sSong97_Part1
sSong97_Part1: @ 0x08869A80
	.byte	KEYSH , 0
	.byte	VOICE , 15
	.byte	VOL , 12
	.byte	BEND , 64
	.byte	N12, Fn3, 100
	.byte	W01
	.byte	VOL , 22
	.byte	BEND , 67
	.byte	W01
	.byte	VOL , 33
	.byte	BEND , 70
	.byte	W01
	.byte	VOL , 46
	.byte	BEND , 73
	.byte	W01
	.byte	VOL , 58
	.byte	BEND , 76
	.byte	W02
	.byte	VOL , 70
	.byte	BEND , 81
	.byte	W01
	.byte	84
	.byte	W01
	.byte	VOL , 60
	.byte	BEND , 89
	.byte	W01
	.byte	VOL , 42
	.byte	BEND , 96
	.byte	W01
	.byte	VOL , 22
	.byte	BEND , 102
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869AB7, 0x1
	.globl sSongHeader_97
sSongHeader_97: @ 0x08869AB8
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869A60, 0x08869A80  @ parts
