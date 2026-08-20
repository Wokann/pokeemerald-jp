.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong116_Part0
sSong116_Part0: @ 0x0886A458
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 119
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 100
	.byte	BEND , 65
	.byte	N02, Gs4, 40
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A46B, 0x1
	.globl sSongHeader_116
sSongHeader_116: @ 0x0886A46C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong116_Part0  @ parts
