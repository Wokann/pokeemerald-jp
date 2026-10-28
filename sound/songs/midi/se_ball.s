.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong23_Part0
sSong23_Part0: @ 0x08868888
	.byte	KEYSH , 0
	.byte	TEMPO , 64
	.byte	VOICE , 7
	.byte	BENDR , 12
	.byte	VOL , 70
	.byte	BEND , 66
	.byte	N04, Fn2, 127
	.byte	W04
	.byte	N01, Dn3
	.byte	W02
	.byte	VOICE , 8
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86889E, 0x2
	.globl se_ball
se_ball: @ 0x088688A0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_rs_sfx_1  @ tone
	.4byte sSong23_Part0  @ parts
