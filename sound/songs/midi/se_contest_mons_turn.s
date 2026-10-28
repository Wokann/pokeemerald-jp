.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong101_Part0
sSong101_Part0: @ 0x08869B88
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 14
	.byte	VOL , 90
	.byte	BEND , 57
	.byte	N02, Cn5, 112
	.byte	W02
	.byte	Cn6
	.byte	W04
	.byte	W01
	.byte	Cn6, 60
	.byte	W05
	.byte	W02
	.byte	Cn5, 112
	.byte	W02
	.byte	Cn6
	.byte	W02
	.byte	W03
	.byte	Cn6, 60
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869BA7, 0x1
	.globl se_contest_mons_turn
se_contest_mons_turn: @ 0x08869BA8
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_rs_sfx_2  @ tone
	.4byte sSong101_Part0  @ parts
