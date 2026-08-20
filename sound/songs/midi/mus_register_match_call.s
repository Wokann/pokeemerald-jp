.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong460_Part0
sSong460_Part0: @ 0x088BC8D0
	.byte	KEYSH , 0
	.byte	TEMPO , 48
	.byte	VOICE , 13
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 90
	.byte	PAN , 48
	.byte	W12
	.byte	N02, Fs5, 100
	.byte	W02
	.byte	Gn5
	.byte	W02
	.byte	Gs5
	.byte	W02
	.byte	N04, An5
	.byte	W06
	.byte	W02
	.byte	N01, Dn6
	.byte	W04
	.byte	N04, An5
	.byte	W04
	.byte	N02, Dn6
	.byte	W04
	.byte	En6
	.byte	W04
	.byte	N04, Fs6
	.byte	W04
	.byte	Fs6, 52
	.byte	W02
	.byte	W02
	.byte	Fs6, 16
	.byte	W22
	.byte	FINE
	.globl sSong460_Part1
sSong460_Part1: @ 0x088BC901
	.byte	KEYSH , 0
	.byte	VOICE , 82
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	PAN , 64
	.byte	VOL , 45
	.byte	W12
	.byte	N02, An3, 100
	.byte	W02
	.byte	Fs3
	.byte	W02
	.byte	En3
	.byte	W02
	.byte	Dn3
	.byte	W06
	.byte	W02
	.byte	N01, An2
	.byte	W04
	.byte	N02, Fs2
	.byte	W04
	.byte	Dn2
	.byte	W02
	.byte	MOD , 8
	.byte	W02
	.byte	N02
	.byte	W04
	.byte	Dn2, 96
	.byte	W04
	.byte	Dn2, 32
	.byte	W02
	.byte	W24
	.byte	MOD , 1
	.byte	FINE
	.globl sSong460_Part2
sSong460_Part2: @ 0x088BC934
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	LFOS , 51
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	VOL , 34
	.byte	MOD , 4
	.byte	PAN , 2
	.byte	W12
	.byte	N02, Cs4, 100
	.byte	W02
	.byte	Dn4
	.byte	W02
	.byte	Ds4
	.byte	W02
	.byte	N04, Gn4
	.byte	W06
	.byte	W02
	.byte	N01, An4
	.byte	W04
	.byte	N04, Fs4
	.byte	W04
	.byte	N02, Dn4
	.byte	W04
	.byte	Fs4
	.byte	W04
	.byte	N04, An4, 96
	.byte	W04
	.byte	An4, 52
	.byte	W02
	.byte	W02
	.byte	An4, 16
	.byte	W22
	.byte	FINE
	.globl sSong460_Part3
sSong460_Part3: @ 0x088BC96B
	.byte	KEYSH , 0
	.byte	VOICE , 80
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	VOL , 34
	.byte	MOD , 2
	.byte	PAN , 127
	.byte	BEND , 64
	.byte	W12
	.byte	N02, Fs4, 100
	.byte	W02
	.byte	Gn4
	.byte	W02
	.byte	Gs4
	.byte	W02
	.byte	N04, An4
	.byte	W06
	.byte	W02
	.byte	N01, Dn5
	.byte	W04
	.byte	N04, An4
	.byte	W04
	.byte	N02, Dn5
	.byte	W04
	.byte	En5
	.byte	W04
	.byte	N04, Fs5
	.byte	W04
	.byte	Fs5, 52
	.byte	W02
	.byte	W02
	.byte	Fs5, 16
	.byte	W22
	.byte	FINE
	.globl sSong460_Part4
sSong460_Part4: @ 0x088BC9A3
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	PAN , 64
	.byte	VOL , 86
	.byte	W12
	.byte	W06
	.byte	N04, En3, 100
	.byte	W06
	.byte	W02
	.byte	N02, Dn3
	.byte	W04
	.byte	N04, Bn4, 48
	.byte	W04
	.byte	Gs2, 60
	.byte	W04
	.byte	Gs2, 40
	.byte	W04
	.byte	Fs2, 68
	.byte	W04
	.byte	N02, Fs2, 44
	.byte	W02
	.byte	W24
	.byte	FINE
	.globl sSongHeader_460
sSongHeader_460: @ 0x088BC9C8
	.byte 0x05, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte 0x0861DBAC  @ tone
	.4byte sSong460_Part0, sSong460_Part1, sSong460_Part2, sSong460_Part3, sSong460_Part4  @ parts
