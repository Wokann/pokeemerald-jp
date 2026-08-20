.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong8_Part0
sSong8_Part0: @ 0x08868504
	.byte	KEYSH , 0
	.byte	TEMPO , 55
	.byte	VOICE , 127
	.byte	VOL , 80
	.byte	N03, Dn3, 127
	.byte	W06
	.byte	N12, Fs3
	.byte	W18
	.byte	FINE
	.globl sSongHeader_8
sSongHeader_8: @ 0x08868514
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong8_Part0  @ parts
