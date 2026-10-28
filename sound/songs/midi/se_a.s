.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong25_Part0
sSong25_Part0: @ 0x08868904
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 122
	.byte	BENDR , 12
	.byte	VOL , 95
	.byte	BEND , 64
	.byte	N72, Cn3, 127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl se_a
se_a: @ 0x08868918
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_rs_sfx_2  @ tone
	.4byte sSong25_Part0  @ parts
