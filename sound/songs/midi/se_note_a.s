.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong67_Part0
sSong67_Part0: @ 0x088692C8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 48
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, An5, 112
	.byte	W06
	.byte	W06
	.byte	N06, An5, 40
	.byte	W06
	.byte	FINE
	.globl sSong67_Part1
sSong67_Part1: @ 0x088692DC
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, En6, 60
	.byte	W06
	.byte	W06
	.byte	N06, En6, 32
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8692EE, 0x2
	.globl sSongHeader_67
sSongHeader_67: @ 0x088692F0
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x088692C8, 0x088692DC  @ parts
