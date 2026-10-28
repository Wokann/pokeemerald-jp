.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong31_Part0
sSong31_Part0: @ 0x088689C4
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 5
	.byte	BENDR , 12
	.byte	VOL , 80
	.byte	BEND , 64
	.byte	N06, Gn5, 127
	.byte	W06
	.byte	N18, Ds5
	.byte	W18
	.byte	FINE
	.globl se_success
se_success: @ 0x088689D8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_rs_sfx_1  @ tone
	.4byte sSong31_Part0  @ parts
