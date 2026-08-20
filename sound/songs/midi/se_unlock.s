.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong44_Part0
sSong44_Part0: @ 0x08868CD4
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 8
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N01, Cn3, 127
	.byte	W02
	.byte	N02, Gn2
	.byte	W04
	.byte	N17, Cn3
	.byte	W06
	.byte	VOL , 98
	.byte	W01
	.byte	91
	.byte	W01
	.byte	81
	.byte	W02
	.byte	75
	.byte	W01
	.byte	60
	.byte	W01
	.byte	42
	.byte	W01
	.byte	25
	.byte	W02
	.byte	10
	.byte	W03
	.byte	FINE
	.globl sSong44_Part1
sSong44_Part1: @ 0x08868CFA
	.byte	VOL , 100
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	N01, Cn3, 64
	.byte	W02
	.byte	N02
	.byte	W04
	.byte	N02
	.byte	W18
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868D09, 0x3
	.globl sSongHeader_44
sSongHeader_44: @ 0x08868D0C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08868CD4, 0x08868CFA  @ parts
