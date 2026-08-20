.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong99_Part0
sSong99_Part0: @ 0x08869B30
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N02, Gn3, 112
	.byte	W04
	.byte	Gn4, 64
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869B46, 0x2
	.globl sSongHeader_99
sSongHeader_99: @ 0x08869B48
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong99_Part0  @ parts
