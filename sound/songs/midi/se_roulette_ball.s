.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong92_Part0
sSong92_Part0: @ 0x088698F8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 63
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	TIE , 62, 127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	EOT
	.byte	FINE
	.globl se_roulette_ball
se_roulette_ball: @ 0x0886990C
	.byte 0x01, 0x00, 0x02, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_rs_sfx_2  @ tone
	.4byte sSong92_Part0  @ parts
