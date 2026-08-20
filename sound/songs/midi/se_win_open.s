.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong6_Part0
sSong6_Part0: @ 0x088684CC
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 127
	.byte	VOL , 110
	.byte	N03, Ds3, 127
	.byte	W03
	.byte	N15, Gn4
	.byte	W21
	.byte	FINE
	.globl sSongHeader_6
sSongHeader_6: @ 0x088684DC
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong6_Part0  @ parts
