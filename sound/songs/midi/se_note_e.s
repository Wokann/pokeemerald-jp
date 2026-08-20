.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong64_Part0
sSong64_Part0: @ 0x08869220
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 48
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, En5, 112
	.byte	W06
	.byte	W06
	.byte	N06, En5, 40
	.byte	W06
	.byte	FINE
	.globl sSong64_Part1
sSong64_Part1: @ 0x08869234
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Bn5, 60
	.byte	W06
	.byte	W06
	.byte	N06, Bn5, 32
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869246, 0x2
	.globl sSongHeader_64
sSongHeader_64: @ 0x08869248
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869220, 0x08869234  @ parts
