.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong430_Part0
sSong430_Part0: @ 0x088A5AB4
	.byte	KEYSH , 0
	.byte	TEMPO , 59
	.byte	VOICE , 127
	.byte	PAN , 64
	.byte	VOL , 39
	.byte	N03, En5, 112
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	VOICE , 126
	.byte	N09, Gn5, 100
	.byte	W12
	.byte	VOICE , 127
	.byte	N03, En5, 112
	.byte	W12
	.byte	VOICE , 126
	.byte	N09, Gn5
	.byte	W12
	.byte	VOICE , 127
	.byte	N03, En5, 112
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	VOICE , 126
	.byte	N09, Gn5, 100
	.byte	W12
	.byte	VOICE , 127
	.byte	N03, En5, 112
	.byte	W12
	.byte	VOICE , 126
	.byte	N09, Gn5
	.byte	W12
	.byte	PEND
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	PATT , 219, 90
	.byte	W10
	.byte	GsM2
	.byte	GOTO , 182, 90
	.byte	W10
	.byte	GsM2
	.byte	FINE
	.globl sSong430_Part1
sSong430_Part1: @ 0x088A5B5B
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	PAN , 64
	.byte	VOL , 36
	.byte	LFOS , 44
	.byte	BENDR , 2
	.byte	W96
	.byte	W72
	.byte	N03, Ds4, 112
	.byte	W03
	.byte	Fn4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	An4
	.byte	W03
	.byte	As4
	.byte	W03
	.byte	Bn4
	.byte	W03
	.byte	Cn5
	.byte	W03
	.byte	Dn5
	.byte	W03
	.byte	PEND
	.byte	TIE , 87
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Fn5
	.byte	W06
	.byte	Gn4
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Fn5
	.byte	W06
	.byte	N03, Gn4
	.byte	W12
	.byte	Ds5
	.byte	W06
	.byte	W96
	.byte	W60
	.byte	N12
	.byte	W12
	.byte	N03, Gn5
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	Cn5
	.byte	W06
	.byte	N06, Fn5
	.byte	W06
	.byte	TIE , 87
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Fn5
	.byte	W06
	.byte	Gn4
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Fn5
	.byte	W06
	.byte	N03, Gn4
	.byte	W12
	.byte	Gn5
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	VOICE , 17
	.byte	N18, Fn5
	.byte	W18
	.byte	TIE , 84
	.byte	W78
	.byte	W48
	.byte	EOT
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Fn4
	.byte	W06
	.byte	Cn4
	.byte	W06
	.byte	N18, Dn5
	.byte	W18
	.byte	N12, Ds5
	.byte	W12
	.byte	N03, Gs4
	.byte	W06
	.byte	N12, Dn5
	.byte	W12
	.byte	N03, Gs4
	.byte	W06
	.byte	N12, Cs5
	.byte	W12
	.byte	N03, Gs4
	.byte	W06
	.byte	N12, Cn5
	.byte	W12
	.byte	N03, Gs4
	.byte	W06
	.byte	N03
	.byte	W03
	.byte	As4
	.byte	W03
	.byte	Cn5
	.byte	W03
	.byte	As4
	.byte	W03
	.byte	N11, Gs4
	.byte	W12
	.byte	N48, Fn4
	.byte	W54
	.byte	N06, Ds4
	.byte	W06
	.byte	N03, Ds3
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Ds3
	.byte	W06
	.byte	N06, Cn4
	.byte	W06
	.byte	N03, Ds3
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	N96, Ds5
	.byte	W96
	.byte	N06, Gn5
	.byte	W06
	.byte	N03, Fn5
	.byte	W06
	.byte	N06, Ds5
	.byte	W06
	.byte	N03, Dn5
	.byte	W12
	.byte	N06, Cn5
	.byte	W12
	.byte	N03, Dn5
	.byte	W06
	.byte	Fn5
	.byte	W06
	.byte	Gn4
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Fn5
	.byte	W06
	.byte	N03, Gn4
	.byte	W12
	.byte	Ds5
	.byte	W06
	.byte	W96
	.byte	PATT , 104, 91
	.byte	W10
	.byte	GsM2
	.byte	N36, Ds5, 112
	.byte	W36
	.byte	W03
	.byte	N03, En5
	.byte	W03
	.byte	Fn5
	.byte	W03
	.byte	Fs5
	.byte	W03
	.byte	N15, Gn5
	.byte	W15
	.byte	N03, Fs5
	.byte	W03
	.byte	N15, Gn5
	.byte	W15
	.byte	N03, Fs5
	.byte	W03
	.byte	N60, Gn5
	.byte	W12
	.byte	W48
	.byte	N03, Fn5
	.byte	W06
	.byte	Gn4
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Fn5
	.byte	W06
	.byte	N03, Gn4
	.byte	W12
	.byte	Ds5
	.byte	W06
	.byte	GOTO , 93, 91
	.byte	W10
	.byte	GsM2
	.byte	FINE
	.globl sSong430_Part2
sSong430_Part2: @ 0x088A5C5B
	.byte	KEYSH , 0
	.byte	VOICE , 36
	.byte	LFOS , 44
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	VOL , 84
	.byte	BEND , 64
	.byte	N12, Cn1, 112
	.byte	W18
	.byte	N03, Cn1, 88
	.byte	W18
	.byte	N12, Bn1, 124
	.byte	W06
	.byte	BEND , 96
	.byte	W06
	.byte	64
	.byte	W48
	.byte	N06, Cn1, 112
	.byte	W12
	.byte	N12, Cn1, 88
	.byte	W24
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	VOICE , 35
	.byte	W12
	.byte	N06, Gn1, 92
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	An1
	.byte	W12
	.byte	Gn1
	.byte	W06
	.byte	PEND
	.byte	VOICE , 36
	.byte	BEND , 64
	.byte	N12, Cn1, 112
	.byte	W18
	.byte	N03, Cn1, 88
	.byte	W18
	.byte	N12, Bn1, 124
	.byte	W06
	.byte	BEND , 96
	.byte	W06
	.byte	64
	.byte	W48
	.byte	PEND
	.byte	PATT , 122, 92
	.byte	W10
	.byte	8
	.byte	PATT , 151, 92
	.byte	W10
	.byte	8
	.byte	PATT , 122, 92
	.byte	W10
	.byte	8
	.byte	PATT , 151, 92
	.byte	W10
	.byte	8
	.byte	PATT , 122, 92
	.byte	W10
	.byte	8
	.byte	PATT , 151, 92
	.byte	W10
	.byte	8
	.byte	N06, Cn1, 112
	.byte	W12
	.byte	N12, Cn1, 88
	.byte	W24
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06, Fn2, 112
	.byte	W12
	.byte	Ds2
	.byte	W12
	.byte	Cn2
	.byte	W12
	.byte	Ds2
	.byte	W06
	.byte	VOICE , 36
	.byte	BEND , 64
	.byte	N12, Fn1, 112
	.byte	W18
	.byte	N03, Fn1, 88
	.byte	W18
	.byte	N12, En2, 124
	.byte	W06
	.byte	BEND , 96
	.byte	W06
	.byte	64
	.byte	W48
	.byte	PEND
	.byte	N06, Fn1, 112
	.byte	W12
	.byte	N12, Fn1, 88
	.byte	W24
	.byte	N03, Fn2, 80
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	VOICE , 35
	.byte	W12
	.byte	N06, Cn2, 92
	.byte	W12
	.byte	N03, Ds2
	.byte	W06
	.byte	Dn2
	.byte	W12
	.byte	Cn2
	.byte	W06
	.byte	PATT , 227, 92
	.byte	W10
	.byte	GsM2
	.byte	N06, Fn1, 112
	.byte	W12
	.byte	N12, Fn1, 88
	.byte	W24
	.byte	N03, Fn2, 80
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Fn1, 112
	.byte	W06
	.byte	N03, Fn2
	.byte	W12
	.byte	Fn1, 76
	.byte	W06
	.byte	N12, En2, 124
	.byte	W06
	.byte	BEND , 99
	.byte	W06
	.byte	64
	.byte	W12
	.byte	PATT , 151, 92
	.byte	W10
	.byte	8
	.byte	PATT , 122, 92
	.byte	W10
	.byte	8
	.byte	PATT , 151, 92
	.byte	W10
	.byte	8
	.byte	PATT , 122, 92
	.byte	W10
	.byte	8
	.byte	PATT , 151, 92
	.byte	W10
	.byte	8
	.byte	PATT , 122, 92
	.byte	W10
	.byte	8
	.byte	GOTO , 93, 92
	.byte	W10
	.byte	8
	.byte	FINE
	.globl sSong430_Part3
sSong430_Part3: @ 0x088A5D5F
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	PAN , 64
	.byte	VOL , 39
	.byte	LFOS , 44
	.byte	BENDR , 2
	.byte	W96
	.byte	W72
	.byte	N03, Cn4, 112
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	Ds4
	.byte	W03
	.byte	Fn4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	An4
	.byte	W03
	.byte	As4
	.byte	W03
	.byte	Bn4
	.byte	W03
	.byte	PEND
	.byte	TIE , 84
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Ds5
	.byte	W06
	.byte	Ds4
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Ds5
	.byte	W06
	.byte	N03, Ds4
	.byte	W12
	.byte	Cn5
	.byte	W06
	.byte	W96
	.byte	W60
	.byte	N12, Gn4
	.byte	W12
	.byte	N03, Cn5
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	N06, Bn4
	.byte	W06
	.byte	TIE , 84
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Ds5
	.byte	W06
	.byte	Ds4
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Ds5
	.byte	W06
	.byte	N03, Ds4
	.byte	W12
	.byte	Ds5
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	N18
	.byte	W18
	.byte	N84, Gs4
	.byte	W78
	.byte	W06
	.byte	N06, As4
	.byte	W06
	.byte	N03, Cn4
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N18, As4
	.byte	W18
	.byte	N06, Gs4
	.byte	W18
	.byte	N06
	.byte	W06
	.byte	N03, Cn4
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	N18, Cn5
	.byte	W18
	.byte	N12
	.byte	W12
	.byte	N03, Ds4
	.byte	W06
	.byte	N12, Bn4
	.byte	W12
	.byte	N03, Ds4
	.byte	W06
	.byte	N12, As4
	.byte	W12
	.byte	N03, Ds4
	.byte	W06
	.byte	N12, Gs4
	.byte	W12
	.byte	N03, Ds4
	.byte	W06
	.byte	Fn4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	Gs4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	N12, Fn4
	.byte	W12
	.byte	N24, Cn4
	.byte	W30
	.byte	N06, Ds4
	.byte	W06
	.byte	N03, Gs3
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06, Cn4
	.byte	W06
	.byte	N03, Cn3
	.byte	W06
	.byte	As3
	.byte	W06
	.byte	Cn3
	.byte	W06
	.byte	N06, Gs3
	.byte	W06
	.byte	N03, Cn3
	.byte	W06
	.byte	As3
	.byte	W06
	.byte	N48, Cn5
	.byte	W54
	.byte	N06, Fn5
	.byte	W12
	.byte	Ds5
	.byte	W12
	.byte	Cn5
	.byte	W12
	.byte	Dn5
	.byte	W06
	.byte	Ds5
	.byte	W06
	.byte	N03, Dn5
	.byte	W06
	.byte	N06, Cn5
	.byte	W06
	.byte	N03, Bn4
	.byte	W12
	.byte	N06, Gn4
	.byte	W12
	.byte	As4
	.byte	W06
	.byte	N03, Ds5
	.byte	W06
	.byte	Ds4
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Ds5
	.byte	W06
	.byte	N03, Ds4
	.byte	W12
	.byte	Cn5
	.byte	W06
	.byte	W96
	.byte	PATT , 108, 93
	.byte	W10
	.byte	GsM2
	.byte	N96, Cn5, 112
	.byte	W96
	.byte	N03, Gn4
	.byte	W06
	.byte	N06, Fn5
	.byte	W06
	.byte	N03, Gn4
	.byte	W06
	.byte	N06, Ds5
	.byte	W06
	.byte	N03, Gn4
	.byte	W06
	.byte	N06, Cn5
	.byte	W06
	.byte	N03, Gn4
	.byte	W06
	.byte	N06, Dn5
	.byte	W06
	.byte	N03, Ds5
	.byte	W06
	.byte	Ds4
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Ds5
	.byte	W06
	.byte	N03, Ds4
	.byte	W12
	.byte	Cn5
	.byte	W06
	.byte	GOTO , 97, 93
	.byte	W10
	.byte	GsM2
	.byte	FINE
	.globl sSong430_Part4
sSong430_Part4: @ 0x088A5E78
	.byte	KEYSH , 0
	.byte	VOICE , 56
	.byte	LFOS , 44
	.byte	BENDR , 2
	.byte	VOL , 42
	.byte	PAN , 64
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	MOD , 30
	.byte	BEND , 64
	.byte	N03, Bn1, 92
	.byte	W06
	.byte	Cn2, 84
	.byte	W06
	.byte	N06, Cn2, 127
	.byte	W06
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N06, Bn1, 92
	.byte	W06
	.byte	N03, Cn2, 84
	.byte	W06
	.byte	N06, Cn2, 96
	.byte	W06
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N02, Cn2, 112
	.byte	W04
	.byte	Cn2, 84
	.byte	W04
	.byte	Cn2, 96
	.byte	W04
	.byte	N06, Bn1, 120
	.byte	W06
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N06, Cn2, 96
	.byte	W06
	.byte	N03, Cn2, 84
	.byte	W06
	.byte	N06, Bn1, 96
	.byte	W06
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	BEND , 64
	.byte	N03, Cn2, 96
	.byte	W06
	.byte	Cn2, 84
	.byte	W06
	.byte	N06, Cn2, 116
	.byte	W06
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	Ds2, 112
	.byte	W06
	.byte	Ds2, 76
	.byte	W06
	.byte	N06, Dn2, 112
	.byte	W06
	.byte	N03, Ds2, 80
	.byte	W06
	.byte	BEND , 64
	.byte	N48, Gn2, 112
	.byte	W15
	.byte	BEND , 64
	.byte	W02
	.byte	57
	.byte	W03
	.byte	54
	.byte	W04
	.byte	51
	.byte	W05
	.byte	44
	.byte	W03
	.byte	41
	.byte	W04
	.byte	35
	.byte	W02
	.byte	26
	.byte	W03
	.byte	17
	.byte	W03
	.byte	2
	.byte	W04
	.byte	MOD , 2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W03
	.byte	VOL , 31
	.byte	W92
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO , 122, 94
	.byte	W10
	.byte	8
	.byte	FINE
	.globl sSong430_Part5
sSong430_Part5: @ 0x088A5F21
	.byte	KEYSH , 0
	.byte	VOICE , 80
	.byte	PAN , 3
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 2
	.byte	VOL , 37
	.byte	BEND , 64
	.byte	W96
	.byte	W72
	.byte	N03, An1, 112
	.byte	W03
	.byte	Bn1
	.byte	W03
	.byte	Cn2
	.byte	W03
	.byte	Dn2
	.byte	W03
	.byte	En2
	.byte	W03
	.byte	Fn2
	.byte	W03
	.byte	Gn2
	.byte	W03
	.byte	An2
	.byte	W03
	.byte	PEND
	.byte	TIE , 58
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Cn3
	.byte	W06
	.byte	Ds2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Cn3
	.byte	W06
	.byte	N03, Ds2
	.byte	W12
	.byte	Gn2
	.byte	W06
	.byte	VOICE , 84
	.byte	N03, Dn2, 92
	.byte	W06
	.byte	Ds2, 84
	.byte	W06
	.byte	N06, Ds2, 127
	.byte	W06
	.byte	N03, Ds2, 80
	.byte	W06
	.byte	N06, Dn2, 92
	.byte	W06
	.byte	N03, Ds2, 84
	.byte	W06
	.byte	N06, Ds2, 96
	.byte	W06
	.byte	N03, Ds2, 80
	.byte	W06
	.byte	N02, Ds2, 112
	.byte	W04
	.byte	Ds2, 84
	.byte	W04
	.byte	Ds2, 96
	.byte	W04
	.byte	N06, Dn2, 120
	.byte	W06
	.byte	N03, Ds2, 80
	.byte	W06
	.byte	N06, Ds2, 96
	.byte	W06
	.byte	N03, Ds2, 84
	.byte	W06
	.byte	N06, Dn2, 96
	.byte	W06
	.byte	N03, Ds2, 80
	.byte	W06
	.byte	VOICE , 80
	.byte	N03, Ds2, 96
	.byte	W06
	.byte	Ds2, 84
	.byte	W06
	.byte	N06, Ds2, 116
	.byte	W06
	.byte	N03, Ds2, 80
	.byte	W06
	.byte	Gn2, 112
	.byte	W06
	.byte	Gn2, 76
	.byte	W06
	.byte	N06, Fs2, 112
	.byte	W06
	.byte	N03, Gn2, 80
	.byte	W06
	.byte	N24, Cn3, 112
	.byte	W24
	.byte	N03, An1
	.byte	W03
	.byte	Bn1
	.byte	W03
	.byte	Cn2
	.byte	W03
	.byte	Dn2
	.byte	W03
	.byte	En2
	.byte	W03
	.byte	Fn2
	.byte	W03
	.byte	Gn2
	.byte	W03
	.byte	An2
	.byte	W03
	.byte	N36, As2
	.byte	W36
	.byte	W03
	.byte	N03, Cn3
	.byte	W03
	.byte	Cs3
	.byte	W03
	.byte	Dn3
	.byte	W03
	.byte	N36, Ds3
	.byte	W36
	.byte	W03
	.byte	N03, Gn3
	.byte	W03
	.byte	Gs3
	.byte	W03
	.byte	An3
	.byte	W03
	.byte	N48, As3
	.byte	W48
	.byte	N03, Cn4
	.byte	W06
	.byte	Ds3
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Cn4
	.byte	W06
	.byte	N03, Ds3
	.byte	W12
	.byte	Cn4
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	TIE , 58
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Cn3
	.byte	W06
	.byte	Ds2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Cn3
	.byte	W06
	.byte	N03, Ds2
	.byte	W12
	.byte	Gn2
	.byte	W06
	.byte	W96
	.byte	PATT , 53, 95
	.byte	W10
	.byte	GsM2
	.byte	TIE , 58, 112
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Cn3
	.byte	W06
	.byte	Ds2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Cn3
	.byte	W06
	.byte	N03, Ds2
	.byte	W12
	.byte	Gn2
	.byte	W06
	.byte	GOTO , 35, 95
	.byte	W10
	.byte	GsM2
	.byte	FINE
	.globl sSong430_Part6
sSong430_Part6: @ 0x088A6037
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	PAN , 127
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 2
	.byte	VOL , 37
	.byte	W96
	.byte	W72
	.byte	N03, Ds2, 112
	.byte	W03
	.byte	Fn2
	.byte	W03
	.byte	Gn2
	.byte	W03
	.byte	An2
	.byte	W03
	.byte	As2
	.byte	W03
	.byte	Bn2
	.byte	W03
	.byte	Cn3
	.byte	W03
	.byte	Dn3
	.byte	W03
	.byte	PEND
	.byte	TIE , 63
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Fn3
	.byte	W06
	.byte	Gn2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Fn3
	.byte	W06
	.byte	N03, Gn2
	.byte	W12
	.byte	Ds3
	.byte	W06
	.byte	PAN , 64
	.byte	N12, Cn1
	.byte	W18
	.byte	N03, Cn1, 88
	.byte	W18
	.byte	N12, Bn1, 124
	.byte	W60
	.byte	N06, Cn1, 112
	.byte	W12
	.byte	N12, Cn1, 88
	.byte	W24
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N03
	.byte	W18
	.byte	N06, Gn1, 92
	.byte	W12
	.byte	PAN , 127
	.byte	N03, Ds2, 112
	.byte	W03
	.byte	Fn2
	.byte	W03
	.byte	Gn2
	.byte	W03
	.byte	An2
	.byte	W03
	.byte	As2
	.byte	W03
	.byte	Bn2
	.byte	W03
	.byte	Cn3
	.byte	W03
	.byte	Dn3
	.byte	W03
	.byte	N36, Ds3
	.byte	W36
	.byte	W03
	.byte	N03, Gn3
	.byte	W03
	.byte	Gs3
	.byte	W03
	.byte	An3
	.byte	W03
	.byte	N36, As3
	.byte	W36
	.byte	W03
	.byte	N03, Cn4
	.byte	W03
	.byte	Cs4
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	N48, Ds4
	.byte	W48
	.byte	N03, Fn4
	.byte	W06
	.byte	Gn3
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Fn4
	.byte	W06
	.byte	N03, Gn3
	.byte	W12
	.byte	Gn4
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	TIE , 63
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Fn3
	.byte	W06
	.byte	Gn2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Fn3
	.byte	W06
	.byte	N03, Gn2
	.byte	W12
	.byte	Ds3
	.byte	W06
	.byte	W96
	.byte	PATT , 73, 96
	.byte	W10
	.byte	GsM2
	.byte	TIE , 63, 112
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	N03, Fn3
	.byte	W06
	.byte	Gn2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Fn3
	.byte	W06
	.byte	N03, Gn2
	.byte	W12
	.byte	Ds3
	.byte	W06
	.byte	GOTO , 57, 96
	.byte	W10
	.byte	GsM2
	.byte	FINE
	.globl sSong430_Part7
sSong430_Part7: @ 0x088A6107
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	PAN , 64
	.byte	VOL , 79
	.byte	N06, Cn1, 112
	.byte	W18
	.byte	Cn1, 64
	.byte	W06
	.byte	En1, 112
	.byte	W24
	.byte	Cn1
	.byte	W06
	.byte	En1, 64
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	Cn1, 68
	.byte	W06
	.byte	En1, 92
	.byte	W12
	.byte	Cn1, 64
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06, Cn1, 112
	.byte	W12
	.byte	Cn1, 120
	.byte	W12
	.byte	En1, 112
	.byte	W24
	.byte	Cn1
	.byte	W06
	.byte	En1, 64
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	Cn1, 68
	.byte	W06
	.byte	En1, 104
	.byte	W12
	.byte	Cn1, 64
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PEND
	.byte	N06, Cn1, 112
	.byte	W18
	.byte	Cn1, 64
	.byte	W06
	.byte	En1, 112
	.byte	W24
	.byte	Cn1
	.byte	W06
	.byte	En1, 64
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	Cn1, 68
	.byte	W06
	.byte	En1, 92
	.byte	W12
	.byte	Cn1, 64
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PEND
	.byte	PATT , 43, 97
	.byte	W10
	.byte	GsM2
	.byte	N06, Cn1, 112
	.byte	W18
	.byte	Cn1, 64
	.byte	W06
	.byte	En1, 112
	.byte	W24
	.byte	Cn1
	.byte	W06
	.byte	En1, 100
	.byte	W06
	.byte	Cn1, 64
	.byte	W06
	.byte	Cn1, 68
	.byte	W06
	.byte	En1, 92
	.byte	W12
	.byte	Cn1, 64
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06, Cn1, 112
	.byte	W12
	.byte	Cn1, 120
	.byte	W12
	.byte	En1, 112
	.byte	W24
	.byte	Cn1
	.byte	W06
	.byte	En1, 64
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	Cn1, 68
	.byte	W06
	.byte	En1, 104
	.byte	W09
	.byte	N03, En1, 64
	.byte	W03
	.byte	N06, En1, 120
	.byte	W06
	.byte	Cn1, 64
	.byte	W06
	.byte	PEND
	.byte	PATT , 72, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 43, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 72, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 43, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 72, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 43, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 72, 97
	.byte	W10
	.byte	GsM2
	.byte	N06, Cn1, 112
	.byte	W12
	.byte	Cn1, 120
	.byte	W12
	.byte	En1, 112
	.byte	W24
	.byte	Cn1
	.byte	W06
	.byte	En1, 64
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	Cn1, 68
	.byte	W06
	.byte	Dn1, 84
	.byte	W06
	.byte	Dn1, 80
	.byte	W06
	.byte	En1, 84
	.byte	W06
	.byte	Cn1, 64
	.byte	W06
	.byte	PATT , 72, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 43, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 72, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 135, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 72, 97
	.byte	W10
	.byte	GsM2
	.byte	PATT , 43, 97
	.byte	W10
	.byte	GsM2
	.byte	GOTO , 9, 97
	.byte	W10
	.byte	GsM2
	.byte	FINE
	.globl sSong430_Part8
sSong430_Part8: @ 0x088A6211
	.byte	KEYSH , 0
	.byte	VOICE , 82
	.byte	PAN , 64
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 2
	.byte	VOL , 42
	.byte	BEND , 65
	.byte	N12, Cn1, 112
	.byte	W18
	.byte	N03, Cn1, 88
	.byte	W18
	.byte	N12, Bn1, 124
	.byte	W60
	.byte	N06, Cn1, 112
	.byte	W03
	.byte	VOICE , 82
	.byte	W09
	.byte	N12, Cn1, 88
	.byte	W24
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N03
	.byte	W18
	.byte	N06, Gn1, 92
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	An1
	.byte	W12
	.byte	Gn1
	.byte	W06
	.byte	N12, Cn1, 112
	.byte	W18
	.byte	N03, Cn1, 88
	.byte	W18
	.byte	N12, Bn1, 124
	.byte	W60
	.byte	PEND
	.byte	N06, Cn1, 112
	.byte	W12
	.byte	N12, Cn1, 88
	.byte	W24
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N03
	.byte	W18
	.byte	N06, Gn1, 92
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	An1
	.byte	W12
	.byte	Gn1
	.byte	W06
	.byte	PEND
	.byte	VOICE , 83
	.byte	VOL , 32
	.byte	BEND , 64
	.byte	N03, Bn2
	.byte	W06
	.byte	Cn3, 84
	.byte	W06
	.byte	N06, Cn3, 127
	.byte	W06
	.byte	N03, Cn3, 80
	.byte	W06
	.byte	N06, Bn2, 92
	.byte	W06
	.byte	N03, Cn3, 84
	.byte	W06
	.byte	N06, Cn3, 96
	.byte	W06
	.byte	N03, Cn3, 80
	.byte	W06
	.byte	N02, Cn3, 112
	.byte	W04
	.byte	Cn3, 84
	.byte	W04
	.byte	Cn3, 96
	.byte	W04
	.byte	N06, Bn2, 120
	.byte	W06
	.byte	N03, Cn3, 80
	.byte	W06
	.byte	N06, Cn3, 96
	.byte	W06
	.byte	N03, Cn3, 84
	.byte	W06
	.byte	N06, Bn2, 96
	.byte	W06
	.byte	N03, Cn3, 80
	.byte	W06
	.byte	BEND , 64
	.byte	N03, Cn3, 96
	.byte	W06
	.byte	Cn3, 84
	.byte	W06
	.byte	N06, Cn3, 116
	.byte	W06
	.byte	N03, Cn3, 80
	.byte	W06
	.byte	Ds3, 112
	.byte	W06
	.byte	Ds3, 76
	.byte	W06
	.byte	N06, Dn3, 112
	.byte	W06
	.byte	N03, Ds3, 80
	.byte	W06
	.byte	BEND , 64
	.byte	N48, Gn3, 112
	.byte	W15
	.byte	BEND , 64
	.byte	W02
	.byte	57
	.byte	W03
	.byte	54
	.byte	W04
	.byte	51
	.byte	W05
	.byte	44
	.byte	W03
	.byte	41
	.byte	W04
	.byte	35
	.byte	W02
	.byte	26
	.byte	W03
	.byte	17
	.byte	W03
	.byte	2
	.byte	W04
	.byte	VOICE , 82
	.byte	VOL , 43
	.byte	BEND , 67
	.byte	N12, Cn1
	.byte	W18
	.byte	N03, Cn1, 88
	.byte	W18
	.byte	N12, Bn1, 124
	.byte	W60
	.byte	PATT , 89, 98
	.byte	W10
	.byte	GsM2
	.byte	PATT , 76, 98
	.byte	W10
	.byte	GsM2
	.byte	N06, Cn1, 112
	.byte	W12
	.byte	N12, Cn1, 88
	.byte	W24
	.byte	N03, Cn2, 80
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06, Fn2, 112
	.byte	W12
	.byte	Ds2
	.byte	W12
	.byte	Cn2
	.byte	W12
	.byte	Ds2
	.byte	W06
	.byte	N12, Fn1, 112
	.byte	W18
	.byte	N03, Fn1, 88
	.byte	W18
	.byte	N12, En2, 124
	.byte	W60
	.byte	PEND
	.byte	N06, Fn1, 112
	.byte	W12
	.byte	N12, Fn1, 88
	.byte	W24
	.byte	N03, Fn2, 80
	.byte	W06
	.byte	N03
	.byte	W18
	.byte	N06, Cn2, 92
	.byte	W12
	.byte	N03, Ds2
	.byte	W06
	.byte	Dn2
	.byte	W12
	.byte	Cn2
	.byte	W06
	.byte	PATT , 38, 99
	.byte	W10
	.byte	GsM2
	.byte	N06, Fn1, 112
	.byte	W12
	.byte	N12, Fn1, 88
	.byte	W24
	.byte	N03, Fn2, 80
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Fn1, 112
	.byte	W06
	.byte	N03, Fn2
	.byte	W12
	.byte	Fn1, 76
	.byte	W06
	.byte	N12, En2, 124
	.byte	W24
	.byte	PATT , 76, 98
	.byte	W10
	.byte	GsM2
	.byte	PATT , 89, 98
	.byte	W10
	.byte	GsM2
	.byte	PATT , 76, 98
	.byte	W10
	.byte	GsM2
	.byte	PATT , 89, 98
	.byte	W10
	.byte	GsM2
	.byte	PATT , 76, 98
	.byte	W10
	.byte	GsM2
	.byte	PATT , 89, 98
	.byte	W10
	.byte	GsM2
	.byte	GOTO , 19, 98
	.byte	W10
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8A6391, 0x3
	.globl sSongHeader_430
sSongHeader_430: @ 0x088A6394
	.byte 0x09, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08613994  @ tone
	.4byte 0x088A5AB4, 0x088A5B5B, 0x088A5C5B, 0x088A5D5F, 0x088A5E78, 0x088A5F21, 0x088A6037, 0x088A6107, 0x088A6211  @ parts
