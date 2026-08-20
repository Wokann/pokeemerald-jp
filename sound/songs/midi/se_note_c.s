.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong62_Part0
sSong62_Part0: @ 0x088691B0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 48
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Cn5, 112
	.byte	W06
	.byte	W06
	.byte	N06, Cn5, 40
	.byte	W06
	.byte	FINE
	.globl sSong62_Part1
sSong62_Part1: @ 0x088691C4
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Gn5, 60
	.byte	W06
	.byte	W06
	.byte	N06, Gn5, 32
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8691D6, 0x2
	.globl sSongHeader_62
sSongHeader_62: @ 0x088691D8
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x088691B0, 0x088691C4  @ parts
