.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong71_Part0
sSong71_Part0: @ 0x088693A0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 26
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 95
	.byte	BEND , 64
	.byte	N01, Cn3, 127
	.byte	W03
	.byte	W03
	.byte	Gn3
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8693B6, 0x2
	.globl sSongHeader_71
sSongHeader_71: @ 0x088693B8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong71_Part0  @ parts
