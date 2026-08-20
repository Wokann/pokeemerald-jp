.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong192_Part0
sSong192_Part0: @ 0x0886C958
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 18
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N02, En3, 124
	.byte	W02
	.byte	As3
	.byte	W04
	.byte	W01
	.byte	N03, En3, 92
	.byte	W05
	.byte	W04
	.byte	PAN , 58
	.byte	N02, En3, 76
	.byte	W02
	.byte	W01
	.byte	PAN , 70
	.byte	N02, As3
	.byte	W05
	.byte	PAN , 64
	.byte	N03, En3, 52
	.byte	W06
	.byte	W03
	.byte	PAN , 52
	.byte	N02, En3, 56
	.byte	W03
	.byte	PAN , 74
	.byte	N02, As3
	.byte	W04
	.byte	PAN , 64
	.byte	N03, En3, 32
	.byte	W02
	.byte	W06
	.byte	W01
	.byte	PAN , 48
	.byte	N02, En3, 44
	.byte	W02
	.byte	PAN , 80
	.byte	N02, As3
	.byte	W03
	.byte	W02
	.byte	PAN , 64
	.byte	N03, En3, 20
	.byte	W04
	.byte	FINE
	.globl sSong192_Part1
sSong192_Part1: @ 0x0886C9AB
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 110
	.byte	N01, Cn3, 40
	.byte	W03
	.byte	En3
	.byte	W03
	.byte	W01
	.byte	Gn3
	.byte	W05
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C9C3, 0x1
	.globl sSongHeader_192
sSongHeader_192: @ 0x0886C9C4
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886C958, 0x0886C9AB  @ parts
