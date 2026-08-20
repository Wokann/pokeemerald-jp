.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong40_Part0
sSong40_Part0: @ 0x08868BB4
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 3
	.byte	VOL , 90
	.byte	BEND , 80
	.byte	N03, En3, 112
	.byte	W01
	.byte	BEND , 102
	.byte	W01
	.byte	126
	.byte	W02
	.byte	N12, En4
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	FINE
	.globl sSong40_Part1
sSong40_Part1: @ 0x08868BCD
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 90
	.byte	N03, Gs3, 96
	.byte	W04
	.byte	N12, Gs4
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868BDD, 0x3
	.globl sSongHeader_40
sSongHeader_40: @ 0x08868BE0
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08868BB4, 0x08868BCD  @ parts
