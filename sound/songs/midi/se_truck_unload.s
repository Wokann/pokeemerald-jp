.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong51_Part0
sSong51_Part0: @ 0x08868F28
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 120
	.byte	VOL , 127
	.byte	N06, Bn3, 28
	.byte	W03
	.byte	W03
	.byte	N21, Gs4
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868F3F, 0x1
	.globl sSongHeader_51
sSongHeader_51: @ 0x08868F40
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong51_Part0  @ parts
