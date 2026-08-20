.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong267_Part0
sSong267_Part0: @ 0x0886FB40
	.byte	KEYSH , 0
	.byte	TEMPO , 49
	.byte	PAN , 64
	.byte	VOL , 127
	.byte	W19
	.byte	TEMPO , 56
	.byte	VOICE , 38
	.byte	MOD , 2
	.byte	N04, Gs1, 120
	.byte	W02
	.byte	MOD , 7
	.byte	W03
	.byte	1
	.byte	N04, Cn2
	.byte	W02
	.byte	MOD , 7
	.byte	W02
	.byte	1
	.byte	N04, En2
	.byte	W03
	.byte	MOD , 7
	.byte	W02
	.byte	1
	.byte	N04, Gs2
	.byte	W03
	.byte	MOD , 7
	.byte	W02
	.byte	1
	.byte	N04, Cn3
	.byte	W02
	.byte	MOD , 7
	.byte	W03
	.byte	1
	.byte	N04, Ds3
	.byte	W02
	.byte	MOD , 7
	.byte	W03
	.byte	1
	.byte	N04, En3, 96
	.byte	W02
	.byte	MOD , 7
	.byte	W02
	.byte	PAN , 2
	.byte	MOD , 1
	.byte	N04, En4, 32
	.byte	W03
	.byte	MOD , 7
	.byte	W02
	.byte	PAN , 127
	.byte	MOD , 1
	.byte	N04, En3, 48
	.byte	W03
	.byte	MOD , 7
	.byte	W02
	.byte	PAN , 2
	.byte	MOD , 1
	.byte	N04, En4, 12
	.byte	W02
	.byte	MOD , 7
	.byte	W03
	.byte	PAN , 127
	.byte	MOD , 1
	.byte	N04, En3, 32
	.byte	W02
	.byte	MOD , 7
	.byte	W03
	.byte	PAN , 2
	.byte	MOD , 1
	.byte	N04, En4, 8
	.byte	W02
	.byte	MOD , 7
	.byte	W02
	.byte	2
	.byte	W03
	.byte	FINE
	.globl sSong267_Part1
sSong267_Part1: @ 0x0886FBBB
	.byte	KEYSH , 0
	.byte	PAN , 64
	.byte	VOL , 112
	.byte	W19
	.byte	VOICE , 100
	.byte	W12
	.byte	W07
	.byte	N04, Cn4, 112
	.byte	W05
	.byte	As4
	.byte	W07
	.byte	Gs5, 64
	.byte	W05
	.byte	Ds6, 48
	.byte	W07
	.byte	Gn6, 32
	.byte	W05
	.byte	W12
	.byte	FINE
	.globl sSong267_Part2
sSong267_Part2: @ 0x0886FBD7
	.byte	KEYSH , 0
	.byte	VOICE , 125
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	MOD , 2
	.byte	VOL , 86
	.byte	BEND , 7
	.byte	N09, Cn5, 64
	.byte	W01
	.byte	BEND , 19
	.byte	W01
	.byte	34
	.byte	W01
	.byte	46
	.byte	W01
	.byte	53
	.byte	W02
	.byte	64
	.byte	W03
	.byte	N01, Gn5, 96
	.byte	W10
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86FC03, 0x1
	.globl sSongHeader_267
sSongHeader_267: @ 0x0886FC04
	.byte 0x03, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886FB40, 0x0886FBBB, 0x0886FBD7  @ parts
