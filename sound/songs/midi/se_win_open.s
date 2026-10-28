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
	.globl se_win_open
se_win_open: @ 0x088684DC
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_rs_sfx_1  @ tone
	.4byte sSong6_Part0  @ parts
