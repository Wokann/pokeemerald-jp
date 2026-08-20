.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong1_Part0
sSong1_Part0: @ 0x088683E8
	.byte	KEYSH , 0
	.byte	TEMPO , 66
	.byte	VOICE , 91
	.byte	VOL , 100
	.byte	BEND , 58
	.byte	N02, Cn3, 112
	.byte	W04
	.byte	N02
	.byte	W04
	.byte	VOICE , 90
	.byte	N15
	.byte	W16
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8683FD, 0x3
	.globl sSongHeader_1
sSongHeader_1: @ 0x08868400
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong1_Part0  @ parts
