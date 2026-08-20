.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong78_Part0
sSong78_Part0: @ 0x08869550
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N01, Cn4, 112
	.byte	W01
	.byte	VOICE , 26
	.byte	W01
	.byte	N01, Fn4, 127
	.byte	W01
	.byte	W01
	.byte	VOICE , 36
	.byte	W02
	.byte	N01, Cn3, 56
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869572, 0x2
	.globl sSongHeader_78
sSongHeader_78: @ 0x08869574
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong78_Part0  @ parts
