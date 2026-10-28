.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong253_Part0
sSong253_Part0: @ 0x0886F568
	.byte	KEYSH , 0
	.byte	TEMPO , 211
	.byte	VOICE , 80
	.byte	VOL , 64
	.byte	BEND , 64
	.byte	N02, Dn4, 84
	.byte	W02
	.byte	BEND , 81
	.byte	N03, Fs4, 80
	.byte	W01
	.byte	BEND , 24
	.byte	W03
	.byte	FINE
	.globl sSong253_Part1
sSong253_Part1: @ 0x0886F580
	.byte	KEYSH , 0
	.byte	VOICE , 2
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 127
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N04, En3, 127
	.byte	W03
	.byte	W01
	.byte	VOICE , 2
	.byte	N02, Bn3
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F59A, 0x2
	.globl se_rg_bag_pocket
se_rg_bag_pocket: @ 0x0886F59C
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_frlg_sfx  @ tone
	.4byte 0x0886F568, 0x0886F580  @ parts
