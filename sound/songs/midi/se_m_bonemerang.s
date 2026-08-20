.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong187_Part0
sSong187_Part0: @ 0x0886C63C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 24
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N01, Cn5, 127
	.byte	W01
	.byte	PAN , 74
	.byte	N01, Cn6
	.byte	W01
	.byte	PAN , 64
	.byte	N01, Cn5
	.byte	W04
	.byte	N01
	.byte	W01
	.byte	PAN , 53
	.byte	N01, Cn6
	.byte	W01
	.byte	PAN , 64
	.byte	N01, Cn5
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C665, 0x3
	.globl sSongHeader_187
sSongHeader_187: @ 0x0886C668
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong187_Part0  @ parts
