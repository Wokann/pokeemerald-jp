.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong106_Part0
sSong106_Part0: @ 0x08869EF0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 8
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N01, Cn4, 92
	.byte	W03
	.byte	Cn5
	.byte	W03
	.byte	W03
	.byte	N02, En3, 127
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869F06, 0x2
	.globl sSongHeader_106
sSongHeader_106: @ 0x08869F08
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong106_Part0  @ parts
