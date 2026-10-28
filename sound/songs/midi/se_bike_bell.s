.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong11_Part0
sSong11_Part0: @ 0x08868578
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 0
	.byte	VOL , 90
	.byte	N96, Cn3, 127
	.byte	W96
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868585, 0x3
	.globl se_bike_bell
se_bike_bell: @ 0x08868588
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_rs_sfx_2  @ tone
	.4byte sSong11_Part0  @ parts
