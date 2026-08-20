.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong100_Part0
sSong100_Part0: @ 0x08869B54
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	VOL , 49
	.byte	BEND , 0
	.byte	N03, Cn6, 112
	.byte	W01
	.byte	VOL , 68
	.byte	BEND , 63
	.byte	W01
	.byte	VOL , 90
	.byte	BEND , 127
	.byte	W01
	.byte	VOL , 69
	.byte	BEND , 64
	.byte	N02, Cn6, 40
	.byte	W01
	.byte	VOL , 90
	.byte	BEND , 127
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869B7A, 0x2
	.globl sSongHeader_100
sSongHeader_100: @ 0x08869B7C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong100_Part0  @ parts
