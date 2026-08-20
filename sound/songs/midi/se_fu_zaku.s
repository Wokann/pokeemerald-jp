.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong37_Part0
sSong37_Part0: @ 0x08868B14
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 126
	.byte	VOL , 120
	.byte	N01, Cn3, 68
	.byte	W01
	.byte	En3, 64
	.byte	W01
	.byte	Gn3
	.byte	W03
	.byte	N02, An2, 48
	.byte	W08
	.byte	N01, Cn3, 68
	.byte	W01
	.byte	En3, 64
	.byte	W01
	.byte	Gn3
	.byte	W03
	.byte	N02, An2, 48
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868B37, 0x1
	.globl sSongHeader_37
sSongHeader_37: @ 0x08868B38
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong37_Part0  @ parts
