.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong18_Part0
sSong18_Part0: @ 0x08868780
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 1
	.byte	VOL , 95
	.byte	N12, Cn2, 127
	.byte	W12
	.byte	VOL , 0
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86878F, 0x1
	.globl sSongHeader_18
sSongHeader_18: @ 0x08868790
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong18_Part0  @ parts
