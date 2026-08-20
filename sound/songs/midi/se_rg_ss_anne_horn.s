.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong256_Part0
sSong256_Part0: @ 0x0886F610
	.byte	KEYSH , 0
	.byte	TEMPO , 82
	.byte	VOICE , 9
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	PAN , 64
	.byte	VOL , 96
	.byte	MOD , 1
	.byte	N04, En2, 127
	.byte	W04
	.byte	N10, En2, 104
	.byte	W20
	.byte	W10
	.byte	PAN , 0
	.byte	TIE , 52, 127
	.byte	W08
	.byte	PAN , 16
	.byte	W06
	.byte	W02
	.byte	32
	.byte	W08
	.byte	48
	.byte	W08
	.byte	64
	.byte	W06
	.byte	80
	.byte	W06
	.byte	95
	.byte	W06
	.byte	112
	.byte	W06
	.byte	127
	.byte	W06
	.byte	W18
	.byte	111
	.byte	W06
	.byte	104
	.byte	W06
	.byte	94
	.byte	W06
	.byte	74
	.byte	W06
	.byte	53
	.byte	W06
	.byte	39
	.byte	W06
	.byte	30
	.byte	W06
	.byte	14
	.byte	W06
	.byte	0
	.byte	W06
	.byte	W18
	.byte	VOL , 80
	.byte	PAN , 12
	.byte	W06
	.byte	VOL , 72
	.byte	PAN , 23
	.byte	W06
	.byte	VOL , 64
	.byte	PAN , 35
	.byte	W06
	.byte	VOL , 53
	.byte	PAN , 46
	.byte	W06
	.byte	VOL , 48
	.byte	PAN , 79
	.byte	W06
	.byte	VOL , 42
	.byte	PAN , 89
	.byte	W06
	.byte	VOL , 32
	.byte	PAN , 104
	.byte	W02
	.byte	VOL , 24
	.byte	W04
	.byte	16
	.byte	PAN , 111
	.byte	W04
	.byte	VOL , 8
	.byte	W02
	.byte	EOT
	.byte	VOL , 0
	.byte	W06
	.byte	FINE
	.globl sSong256_Part1
sSong256_Part1: @ 0x0886F687
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	PAN , 64
	.byte	MOD , 15
	.byte	VOL , 48
	.byte	N04, En1, 127
	.byte	W04
	.byte	N10, En1, 104
	.byte	W20
	.byte	W10
	.byte	TIE , 40, 127
	.byte	W14
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W18
	.byte	VOL , 42
	.byte	W06
	.byte	36
	.byte	W06
	.byte	32
	.byte	W06
	.byte	26
	.byte	W06
	.byte	23
	.byte	W06
	.byte	15
	.byte	W06
	.byte	13
	.byte	W06
	.byte	8
	.byte	W06
	.byte	EOT
	.byte	VOL , 0
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F6BA, 0x2
	.globl sSongHeader_256
sSongHeader_256: @ 0x0886F6BC
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886F610, 0x0886F687  @ parts
