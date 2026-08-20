.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong38_Part0
sSong38_Part0: @ 0x08868B44
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 126
	.byte	VOL , 110
	.byte	N01, An2, 112
	.byte	W01
	.byte	En3
	.byte	W01
	.byte	Gn3
	.byte	W01
	.byte	W02
	.byte	N02, Cn3, 92
	.byte	W01
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868B5B, 0x1
	.globl sSongHeader_38
sSongHeader_38: @ 0x08868B5C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong38_Part0  @ parts
