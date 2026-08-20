.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong69_Part0
sSong69_Part0: @ 0x08869338
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 48
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Cn6, 112
	.byte	W06
	.byte	W06
	.byte	N06, Cn6, 40
	.byte	W06
	.byte	FINE
	.globl sSong69_Part1
sSong69_Part1: @ 0x0886934C
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Gn6, 60
	.byte	W06
	.byte	W06
	.byte	N06, Gn6, 32
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86935E, 0x2
	.globl sSongHeader_69
sSongHeader_69: @ 0x08869360
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869338, 0x0886934C  @ parts
