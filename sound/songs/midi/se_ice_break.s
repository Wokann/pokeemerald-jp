.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong41_Part0
sSong41_Part0: @ 0x08868BF0
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 3
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N01, Gn3, 120
	.byte	W03
	.byte	W01
	.byte	Cn4
	.byte	W01
	.byte	BEND , 76
	.byte	W01
	.byte	86
	.byte	W01
	.byte	N01, Cn5, 112
	.byte	W01
	.byte	BEND , 99
	.byte	W01
	.byte	W01
	.byte	110
	.byte	W01
	.byte	118
	.byte	N01, Cn4, 104
	.byte	W01
	.byte	W01
	.byte	BEND , 127
	.byte	W01
	.byte	N01, Cn5, 96
	.byte	W01
	.byte	FINE
	.globl sSong41_Part1
sSong41_Part1: @ 0x08868C1E
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 100
	.byte	N01, Gs3, 64
	.byte	W03
	.byte	W01
	.byte	N01
	.byte	W02
	.byte	Fn4
	.byte	W03
	.byte	Gs3
	.byte	W03
	.byte	Fn4
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868C32, 0x2
	.globl sSongHeader_41
sSongHeader_41: @ 0x08868C34
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08868BF0, 0x08868C1E  @ parts
