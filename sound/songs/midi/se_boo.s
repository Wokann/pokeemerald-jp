.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong22_Part0
sSong22_Part0: @ 0x08868864
	.byte	KEYSH , 0
	.byte	TEMPO , 50
	.byte	VOICE , 5
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N03, Cn3, 127
	.byte	W03
	.byte	Cn2, 112
	.byte	W03
	.byte	W03
	.byte	Cn2, 24
	.byte	W03
	.byte	FINE
	.globl sSongHeader_22
sSongHeader_22: @ 0x0886887C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong22_Part0  @ parts
