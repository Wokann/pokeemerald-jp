.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong214_Part0
sSong214_Part0: @ 0x0886D8DC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 26
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N03, Gn2, 127
	.byte	W03
	.byte	PAN , 70
	.byte	N03, Fs2, 120
	.byte	W04
	.byte	PAN , 58
	.byte	N03, Fn2, 116
	.byte	W03
	.byte	PAN , 75
	.byte	N03, En2, 112
	.byte	W04
	.byte	PAN , 53
	.byte	N03, Ds2, 108
	.byte	W04
	.byte	PAN , 64
	.byte	N03, Dn2, 100
	.byte	W06
	.byte	FINE
	.globl sSong214_Part1
sSong214_Part1: @ 0x0886D90D
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	N02, Fn2, 72
	.byte	W02
	.byte	N01
	.byte	W01
	.byte	N02, Gn2
	.byte	W03
	.byte	N01, Gs2, 60
	.byte	W01
	.byte	N02, Cn3, 40
	.byte	W03
	.byte	Cn3, 32
	.byte	W04
	.byte	N01, Cn3, 28
	.byte	W04
	.byte	Cn3, 20
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86D931, 0x3
	.globl sSongHeader_214
sSongHeader_214: @ 0x0886D934
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886D8DC, 0x0886D90D  @ parts
