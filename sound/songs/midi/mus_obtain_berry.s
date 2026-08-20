.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong387_Part0
sSong387_Part0: @ 0x088813FC
	.byte	KEYSH , 0
	.byte	W12
	.byte	TEMPO , 70
	.byte	VOICE , 13
	.byte	PAN , 54
	.byte	VOL , 90
	.byte	N04, Fn4, 92
	.byte	W04
	.byte	Fn4, 80
	.byte	W04
	.byte	N04
	.byte	W04
	.byte	Cn4, 92
	.byte	W04
	.byte	Cn4, 80
	.byte	W04
	.byte	N04
	.byte	W04
	.byte	Cn5, 92
	.byte	W08
	.byte	Dn5
	.byte	W08
	.byte	Cn5
	.byte	W08
	.byte	Fn5
	.byte	W04
	.byte	Fn5, 80
	.byte	W04
	.byte	N04
	.byte	W04
	.byte	N04
	.byte	W36
	.byte	FINE
	.globl sSong387_Part1
sSong387_Part1: @ 0x08881429
	.byte	KEYSH , 0
	.byte	W12
	.byte	VOICE , 13
	.byte	PAN , 95
	.byte	VOL , 90
	.byte	W24
	.byte	N04, Gn4, 92
	.byte	W08
	.byte	As4
	.byte	W08
	.byte	Gn4
	.byte	W08
	.byte	N16, An4
	.byte	W48
	.byte	FINE
	.globl sSong387_Part2
sSong387_Part2: @ 0x0888143F
	.byte	KEYSH , 0
	.byte	W12
	.byte	VOICE , 1
	.byte	VOL , 90
	.byte	PAN , 32
	.byte	N24, Fn3, 80
	.byte	W24
	.byte	N04, Gn3
	.byte	W08
	.byte	N04
	.byte	W08
	.byte	N04
	.byte	W08
	.byte	N16, Fn3
	.byte	W48
	.byte	FINE
	.globl sSong387_Part3
sSong387_Part3: @ 0x08881457
	.byte	KEYSH , 0
	.byte	W12
	.byte	VOICE , 1
	.byte	VOL , 90
	.byte	PAN , 64
	.byte	N24, An2, 80
	.byte	W24
	.byte	N04, As2
	.byte	W08
	.byte	N04
	.byte	W08
	.byte	N04
	.byte	W08
	.byte	N16, An2
	.byte	W48
	.byte	FINE
	.globl sSong387_Part4
sSong387_Part4: @ 0x0888146F
	.byte	KEYSH , 0
	.byte	W12
	.byte	VOICE , 100
	.byte	VOL , 90
	.byte	PAN , 64
	.byte	N04, Cn5, 60
	.byte	W08
	.byte	PAN , 15
	.byte	N04, Cn5, 20
	.byte	W16
	.byte	VOICE , 101
	.byte	PAN , 63
	.byte	N04, As3, 60
	.byte	W08
	.byte	Gn3
	.byte	W08
	.byte	PAN , 114
	.byte	N04, Gn3, 20
	.byte	W08
	.byte	VOICE , 100
	.byte	PAN , 64
	.byte	N04, An3, 60
	.byte	W08
	.byte	PAN , 16
	.byte	N04, An3, 20
	.byte	W16
	.byte	VOICE , 101
	.byte	PAN , 64
	.byte	N04, An3, 60
	.byte	W08
	.byte	PAN , 114
	.byte	N04, An3, 20
	.byte	W16
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8814AF, 0x1
	.globl sSongHeader_387
sSongHeader_387: @ 0x088814B0
	.byte 0x05, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_085FF648  @ tone
	.4byte 0x088813FC, 0x08881429, 0x0888143F, 0x08881457, 0x0888146F  @ parts
