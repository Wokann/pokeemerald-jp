.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong65_Part0
sSong65_Part0: @ 0x08869258
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 48
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Fn5, 112
	.byte	W06
	.byte	W06
	.byte	N06, Fn5, 40
	.byte	W06
	.byte	FINE
	.globl sSong65_Part1
sSong65_Part1: @ 0x0886926C
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Cn6, 60
	.byte	W06
	.byte	W06
	.byte	N06, Cn6, 32
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86927E, 0x2
	.globl sSongHeader_65
sSongHeader_65: @ 0x08869280
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869258, 0x0886926C  @ parts
