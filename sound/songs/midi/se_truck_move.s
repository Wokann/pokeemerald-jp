.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong49_Part0
sSong49_Part0: @ 0x08868DFC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 10
	.byte	VOL , 18
	.byte	BEND , 64
	.byte	N96, Cs3, 127
	.byte	W08
	.byte	VOL , 31
	.byte	W08
	.byte	42
	.byte	W08
	.byte	59
	.byte	W08
	.byte	74
	.byte	W08
	.byte	88
	.byte	W08
	.byte	106
	.byte	W08
	.byte	118
	.byte	W08
	.byte	127
	.byte	W32
	.byte	TIE , 61, 127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	EOT
	.byte	GOTO , 27, 142
	.byte	W06
	.byte	GsM2
	.byte	FINE
	.globl sSong49_Part1
sSong49_Part1: @ 0x08868E28
	.byte	KEYSH , 0
	.byte	VOICE , 11
	.byte	VOL , 18
	.byte	W08
	.byte	31
	.byte	W04
	.byte	N03, Fn2, 44
	.byte	W04
	.byte	VOL , 42
	.byte	W02
	.byte	N03, An2
	.byte	W06
	.byte	VOL , 59
	.byte	W06
	.byte	N03, Cs2, 52
	.byte	W02
	.byte	VOL , 74
	.byte	W08
	.byte	88
	.byte	W08
	.byte	106
	.byte	N03, Gn2, 44
	.byte	W08
	.byte	VOL , 118
	.byte	W08
	.byte	127
	.byte	W08
	.byte	N01, Bn2, 32
	.byte	W12
	.byte	N03, Fn2, 44
	.byte	W12
	.byte	W12
	.byte	N03, Fn2, 44
	.byte	W06
	.byte	An2, 32
	.byte	W12
	.byte	Cs2, 52
	.byte	W12
	.byte	An2, 32
	.byte	W06
	.byte	Gn2, 44
	.byte	W24
	.byte	N03
	.byte	W12
	.byte	Fn2
	.byte	W12
	.byte	Gn2
	.byte	W18
	.byte	Cs2, 52
	.byte	W12
	.byte	N01, Bn2, 32
	.byte	W06
	.byte	N03, Fn2, 44
	.byte	W24
	.byte	N03
	.byte	W18
	.byte	Cs2, 52
	.byte	W18
	.byte	Gn2, 44
	.byte	W18
	.byte	An2
	.byte	W12
	.byte	Cs2, 52
	.byte	W18
	.byte	Gn2, 44
	.byte	W12
	.byte	Fn2
	.byte	W18
	.byte	N01, Bn2, 32
	.byte	W06
	.byte	N03, Fn2, 44
	.byte	W12
	.byte	GOTO , 89, 142
	.byte	W06
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868E9B, 0x1
	.globl sSongHeader_49
sSongHeader_49: @ 0x08868E9C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08868DFC, 0x08868E28  @ parts
