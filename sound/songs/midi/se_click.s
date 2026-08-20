.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong36_Part0
sSong36_Part0: @ 0x08868AF0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 126
	.byte	VOL , 110
	.byte	N01, Gs3, 127
	.byte	W01
	.byte	Cn4, 68
	.byte	W02
	.byte	W02
	.byte	N03, Gs4, 127
	.byte	W01
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868B06, 0x2
	.globl sSongHeader_36
sSongHeader_36: @ 0x08868B08
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong36_Part0  @ parts
