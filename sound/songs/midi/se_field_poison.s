.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong79_Part0
sSong79_Part0: @ 0x08869580
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 16
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N02, Ds3, 100
	.byte	W04
	.byte	N02
	.byte	W05
	.byte	N02
	.byte	W05
	.byte	N02
	.byte	W05
	.byte	N02
	.byte	W05
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869599, 0x3
	.globl sSongHeader_79
sSongHeader_79: @ 0x0886959C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong79_Part0  @ parts
