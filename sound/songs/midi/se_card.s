.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong54_Part0
sSong54_Part0: @ 0x08868FAC
	.byte	KEYSH , 0
	.byte	TEMPO , 90
	.byte	VOICE , 12
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N02, Bn3, 104
	.byte	W10
	.byte	BEND , 1
	.byte	W05
	.byte	VOICE , 11
	.byte	BEND , 11
	.byte	N48, Cn4, 88
	.byte	W04
	.byte	BEND , 22
	.byte	W04
	.byte	32
	.byte	W04
	.byte	43
	.byte	W05
	.byte	53
	.byte	W04
	.byte	63
	.byte	W04
	.byte	74
	.byte	W04
	.byte	84
	.byte	W05
	.byte	95
	.byte	W04
	.byte	105
	.byte	W04
	.byte	116
	.byte	W04
	.byte	126
	.byte	W11
	.byte	VOICE , 12
	.byte	BEND , 64
	.byte	W04
	.byte	N02, Bn3, 104
	.byte	W20
	.byte	FINE
	.globl sSong54_Part1
sSong54_Part1: @ 0x08868FE6
	.byte	KEYSH , 0
	.byte	VOICE , 124
	.byte	VOL , 100
	.byte	N02, Cn4, 127
	.byte	W02
	.byte	VOICE , 121
	.byte	N08, Gs4
	.byte	W13
	.byte	N48, Gs4, 52
	.byte	W52
	.byte	VOL , 25
	.byte	N08, Gs4, 127
	.byte	W01
	.byte	VOL , 43
	.byte	W02
	.byte	66
	.byte	W03
	.byte	85
	.byte	W01
	.byte	92
	.byte	W01
	.byte	VOICE , 124
	.byte	VOL , 96
	.byte	W01
	.byte	100
	.byte	N02, Cn4
	.byte	W20
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869012, 0x2
	.globl sSongHeader_54
sSongHeader_54: @ 0x08869014
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x08868FAC, 0x08868FE6  @ parts
