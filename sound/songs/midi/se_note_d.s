.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong63_Part0
sSong63_Part0: @ 0x088691E8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 48
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Dn5, 112
	.byte	W06
	.byte	W06
	.byte	N06, Dn5, 40
	.byte	W06
	.byte	FINE
	.globl sSong63_Part1
sSong63_Part1: @ 0x088691FC
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, An5, 60
	.byte	W06
	.byte	W06
	.byte	N06, An5, 32
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86920E, 0x2
	.globl sSongHeader_63
sSongHeader_63: @ 0x08869210
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x088691E8, 0x088691FC  @ parts
