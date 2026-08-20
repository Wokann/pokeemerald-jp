.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong238_Part0
sSong238_Part0: @ 0x0886EB34
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 41
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 70
	.byte	BEND , 64
	.byte	N02, Cn4, 127
	.byte	W03
	.byte	VOL , 104
	.byte	W03
	.byte	93
	.byte	PAN , 58
	.byte	N02, Cn5
	.byte	W03
	.byte	VOL , 110
	.byte	W01
	.byte	VOICE , 22
	.byte	PAN , 64
	.byte	N24, Cn4, 60
	.byte	W02
	.byte	W02
	.byte	BEND , 64
	.byte	W04
	.byte	65
	.byte	W03
	.byte	65
	.byte	W01
	.byte	VOL , 105
	.byte	W02
	.byte	BEND , 64
	.byte	W01
	.byte	VOL , 103
	.byte	W02
	.byte	91
	.byte	BEND , 64
	.byte	W03
	.byte	VOL , 77
	.byte	BEND , 63
	.byte	W02
	.byte	VOL , 61
	.byte	BEND , 62
	.byte	W01
	.byte	VOL , 38
	.byte	W01
	.byte	15
	.byte	BEND , 61
	.byte	W02
	.byte	FINE
	.globl sSong238_Part1
sSong238_Part1: @ 0x0886EB81
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 110
	.byte	N02, Cn3, 60
	.byte	W03
	.byte	Gn2
	.byte	W03
	.byte	Gs4
	.byte	W04
	.byte	Gs4, 20
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86EB97, 0x1
	.globl sSongHeader_238
sSongHeader_238: @ 0x0886EB98
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886EB34, 0x0886EB81  @ parts
