.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong66_Part0
sSong66_Part0: @ 0x08869290
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 48
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Gn5, 112
	.byte	W06
	.byte	W06
	.byte	N06, Gn5, 40
	.byte	W06
	.byte	FINE
	.globl sSong66_Part1
sSong66_Part1: @ 0x088692A4
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Dn6, 60
	.byte	W06
	.byte	W06
	.byte	N06, Dn6, 32
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8692B6, 0x2
	.globl sSongHeader_66
sSongHeader_66: @ 0x088692B8
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869290, 0x088692A4  @ parts
