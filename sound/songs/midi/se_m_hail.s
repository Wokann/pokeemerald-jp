.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong242_Part0
sSong242_Part0: @ 0x0886EE88
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 3
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	N01, Fn4, 112
	.byte	W04
	.byte	PAN , 70
	.byte	N02, Ds5, 40
	.byte	W02
	.byte	W02
	.byte	PAN , 59
	.byte	N01, Gn4, 112
	.byte	W01
	.byte	PAN , 64
	.byte	N01, Ds5
	.byte	W03
	.byte	W01
	.byte	PAN , 70
	.byte	N02, Ds5, 20
	.byte	W03
	.byte	PAN , 59
	.byte	N01, Gn4, 64
	.byte	W02
	.byte	PAN , 64
	.byte	N01, Ds5
	.byte	W03
	.byte	PAN , 75
	.byte	N02, Ds5, 20
	.byte	W03
	.byte	W01
	.byte	PAN , 51
	.byte	N01, Gn4, 64
	.byte	W01
	.byte	PAN , 64
	.byte	N01, Ds5
	.byte	W04
	.byte	FINE
	.globl sSong242_Part1
sSong242_Part1: @ 0x0886EECD
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	N01, Dn4, 40
	.byte	W04
	.byte	Bn3
	.byte	W02
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	W01
	.byte	Bn3, 32
	.byte	W05
	.byte	Dn4
	.byte	W03
	.byte	Bn3, 12
	.byte	W03
	.byte	W02
	.byte	Dn4
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86EEEB, 0x1
	.globl sSongHeader_242
sSongHeader_242: @ 0x0886EEEC
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886EE88, 0x0886EECD  @ parts
