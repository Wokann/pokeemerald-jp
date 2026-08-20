.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong215_Part0
sSong215_Part0: @ 0x0886D944
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 18
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N02, En3, 127
	.byte	W03
	.byte	N01, As3
	.byte	W03
	.byte	N02, Gn3
	.byte	W03
	.byte	N01, Cs4
	.byte	W03
	.byte	PAN , 71
	.byte	N02, En3, 72
	.byte	W03
	.byte	N01, As3
	.byte	W03
	.byte	PAN , 57
	.byte	N02, Gn3, 40
	.byte	W03
	.byte	N01, Cs4
	.byte	W03
	.byte	FINE
	.globl sSong215_Part1
sSong215_Part1: @ 0x0886D972
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 110
	.byte	N01, Cn3, 40
	.byte	W02
	.byte	N01
	.byte	W04
	.byte	N01
	.byte	W02
	.byte	N01
	.byte	W04
	.byte	N01, Cn3, 20
	.byte	W02
	.byte	N01
	.byte	W04
	.byte	PEND
	.byte	PATT , 130, 217
	.byte	W06
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D98F, 0x1
	.globl sSongHeader_215
sSongHeader_215: @ 0x0886D990
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886D944, 0x0886D972  @ parts
