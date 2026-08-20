.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong264_Part0
sSong264_Part0: @ 0x0886FA68
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 10
	.byte	VOL , 110
	.byte	BEND , 56
	.byte	W01
	.byte	N01, Ds3, 112
	.byte	W04
	.byte	Gs1
	.byte	W01
	.byte	Bn1, 56
	.byte	W04
	.byte	Bn1, 24
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.globl sSong264_Part1
sSong264_Part1: @ 0x0886FA83
	.byte	KEYSH , 0
	.byte	VOICE , 82
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	BEND , 64
	.byte	N01, Cs3, 64
	.byte	W01
	.byte	Fs4, 32
	.byte	W01
	.byte	BEND , 64
	.byte	N01, Gs5, 28
	.byte	W01
	.byte	BEND , 127
	.byte	W01
	.byte	1
	.byte	N01, Cs3, 36
	.byte	W01
	.byte	BEND , 127
	.byte	W01
	.byte	1
	.byte	N01, Bn4, 52
	.byte	W02
	.byte	BEND , 64
	.byte	W02
	.byte	N01, Cs1
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86FAB6, 0x2
	.globl sSongHeader_264
sSongHeader_264: @ 0x0886FAB8
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886FA68, 0x0886FA83  @ parts
