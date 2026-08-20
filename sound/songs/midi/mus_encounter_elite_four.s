.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong450_Part0
sSong450_Part0: @ 0x088B4B48
	.byte	KEYSH , 0
	.byte	TEMPO , 67
	.byte	VOICE , 127
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 51
	.byte	PAN , 126
	.byte	W24
	.byte	W12
	.byte	N03, Gn5, 72
	.byte	W06
	.byte	N03
	.byte	W18
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W18
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W18
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	PEND
	.byte	PATT , 87, 75
	.byte	W11
	.byte	GsM2
	.byte	PATT , 87, 75
	.byte	W11
	.byte	GsM2
	.byte	PATT , 87, 75
	.byte	W11
	.byte	GsM2
	.byte	PATT , 87, 75
	.byte	W11
	.byte	GsM2
	.byte	PATT , 87, 75
	.byte	W11
	.byte	GsM2
	.byte	PATT , 87, 75
	.byte	W11
	.byte	GsM2
	.byte	PATT , 87, 75
	.byte	W11
	.byte	GsM2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO , 87, 75
	.byte	W11
	.byte	GsM2
	.byte	FINE
	.globl sSong450_Part1
sSong450_Part1: @ 0x088B4B98
	.byte	KEYSH , 0
	.byte	VOICE , 38
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	PAN , 64
	.byte	VOL , 78
	.byte	W24
	.byte	VOICE , 38
	.byte	BEND , 59
	.byte	N12, Bn0, 112
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N03, Fs1
	.byte	W06
	.byte	N06, Bn0
	.byte	W06
	.byte	N12, Fn1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N06, Bn0
	.byte	W12
	.byte	N12, As1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N12, Fs1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N06, Bn0
	.byte	W06
	.byte	N03, Cn1
	.byte	W06
	.byte	BEND , 60
	.byte	N12
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N12, Bn0
	.byte	W12
	.byte	N03, Fs1
	.byte	W06
	.byte	N06, Bn0
	.byte	W06
	.byte	N12, Fn1
	.byte	W12
	.byte	N06, Bn0
	.byte	W36
	.byte	BEND , 58
	.byte	N24, Cn1
	.byte	W06
	.byte	BEND , 64
	.byte	W18
	.byte	59
	.byte	N12, Bn0
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N03, Fs1
	.byte	W06
	.byte	N06, Bn0
	.byte	W06
	.byte	N12, Fn1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N06, Bn0
	.byte	W12
	.byte	N12, As1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N12, Fs1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N06, Bn0
	.byte	W06
	.byte	N03, Cn1
	.byte	W06
	.byte	BEND , 60
	.byte	N12
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N12, Bn0
	.byte	W12
	.byte	N03, Fs1
	.byte	W06
	.byte	N06, Bn0
	.byte	W06
	.byte	N12, Fn1
	.byte	W12
	.byte	N06, Bn0
	.byte	W36
	.byte	BEND , 58
	.byte	N06
	.byte	W06
	.byte	BEND , 64
	.byte	N06, Cn1
	.byte	W06
	.byte	En1
	.byte	W06
	.byte	Fs1
	.byte	W06
	.byte	BEND , 59
	.byte	N12, Dn1, 112
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N03, An1
	.byte	W06
	.byte	N06, Dn1
	.byte	W06
	.byte	N12, Gs1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N06, Dn1
	.byte	W12
	.byte	N12, Cs2
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N12, An1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N06, Dn1
	.byte	W06
	.byte	N03, Ds1
	.byte	W06
	.byte	BEND , 60
	.byte	N12
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	PEND
	.byte	N12, Dn1
	.byte	W12
	.byte	N03, An1
	.byte	W06
	.byte	N06, Dn1
	.byte	W06
	.byte	N12, Gs1
	.byte	W12
	.byte	N06, Dn1
	.byte	W24
	.byte	N03, An0
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	BEND , 58
	.byte	N24, Ds1
	.byte	W06
	.byte	BEND , 64
	.byte	W18
	.byte	PATT , 68, 76
	.byte	W11
	.byte	8
	.byte	BEND , 59
	.byte	N12, Dn1, 112
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N03, An1
	.byte	W06
	.byte	N06, Dn1
	.byte	W06
	.byte	N12, Gs1
	.byte	W06
	.byte	BEND , 68
	.byte	W06
	.byte	64
	.byte	N06, Dn1
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	Cn1
	.byte	W12
	.byte	An0
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	As0
	.byte	W18
	.byte	BEND , 59
	.byte	N06, Dn1, 112
	.byte	W06
	.byte	BEND , 64
	.byte	N03, Dn2
	.byte	W06
	.byte	An1
	.byte	W06
	.byte	N06, Dn2
	.byte	W06
	.byte	Cs1
	.byte	W06
	.byte	BEND , 68
	.byte	N03, Cs2
	.byte	W06
	.byte	BEND , 64
	.byte	N03, Gs1
	.byte	W06
	.byte	N06, Cs2
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	BEND , 68
	.byte	N03, Cn2
	.byte	W06
	.byte	BEND , 64
	.byte	N03, Gn1
	.byte	W06
	.byte	BEND , 68
	.byte	N06, Cn2
	.byte	W06
	.byte	BEND , 64
	.byte	N03, Bn0
	.byte	W03
	.byte	Cn1
	.byte	W03
	.byte	Bn0
	.byte	W03
	.byte	Cn1
	.byte	W03
	.byte	BEND , 60
	.byte	N03, Bn0
	.byte	W03
	.byte	Cn1
	.byte	W03
	.byte	BEND , 64
	.byte	N03, Bn0
	.byte	W03
	.byte	Cn1
	.byte	W03
	.byte	PEND
	.byte	N06, Dn1
	.byte	W06
	.byte	N03, Dn2
	.byte	W06
	.byte	An1
	.byte	W06
	.byte	N06, Dn2
	.byte	W06
	.byte	Cs1
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Gs1
	.byte	W06
	.byte	N06, Cs2
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	N03, Cn2
	.byte	W06
	.byte	Gn1
	.byte	W06
	.byte	N06, Cn2
	.byte	W06
	.byte	BEND , 58
	.byte	N03, Bn0
	.byte	W03
	.byte	Cn1
	.byte	W03
	.byte	BEND , 64
	.byte	N03, Bn0
	.byte	W03
	.byte	Cn1
	.byte	W03
	.byte	Bn0
	.byte	W03
	.byte	Cn1
	.byte	W03
	.byte	Bn0
	.byte	W03
	.byte	Cn1
	.byte	W03
	.byte	PATT , 189, 76
	.byte	W11
	.byte	GsM2
	.byte	N06, An0, 112
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N12, As0
	.byte	W12
	.byte	N03, An0
	.byte	W06
	.byte	An1
	.byte	W06
	.byte	N12, An0
	.byte	W12
	.byte	N24, An1
	.byte	W03
	.byte	BEND , 58
	.byte	W02
	.byte	52
	.byte	W03
	.byte	44
	.byte	W04
	.byte	36
	.byte	W02
	.byte	26
	.byte	W03
	.byte	16
	.byte	W03
	.byte	5
	.byte	W04
	.byte	GOTO , 169, 75
	.byte	W11
	.byte	8
	.byte	FINE
	.globl sSong450_Part2
sSong450_Part2: @ 0x088B4D6E
	.byte	KEYSH , 0
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 68
	.byte	PAN , 63
	.byte	W24
	.byte	VOICE , 13
	.byte	PAN , 32
	.byte	VOL , 64
	.byte	W12
	.byte	N03, Bn5, 88
	.byte	W03
	.byte	N06, Bn5, 36
	.byte	W09
	.byte	PAN , 41
	.byte	N03, An5, 96
	.byte	W03
	.byte	N06, An5, 36
	.byte	W09
	.byte	PAN , 57
	.byte	N03, Gn5, 96
	.byte	W03
	.byte	N06, Gn5, 36
	.byte	W09
	.byte	PAN , 84
	.byte	N03, Fs5, 96
	.byte	W03
	.byte	Fs5, 36
	.byte	W03
	.byte	En5, 96
	.byte	W03
	.byte	N06, En5, 36
	.byte	W09
	.byte	N03, Dn5, 96
	.byte	W03
	.byte	N06, Dn5, 36
	.byte	W03
	.byte	PAN , 92
	.byte	W06
	.byte	N03, Fs5, 96
	.byte	W03
	.byte	Fs5, 36
	.byte	W03
	.byte	N12, Bn4, 96
	.byte	W12
	.byte	VOICE , 24
	.byte	PAN , 38
	.byte	VOL , 73
	.byte	MOD , 8
	.byte	N12, Bn1, 112
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Cn2
	.byte	W12
	.byte	MOD , 19
	.byte	W12
	.byte	8
	.byte	N09, An1
	.byte	W09
	.byte	N03, As1
	.byte	W03
	.byte	VOICE , 24
	.byte	MOD , 0
	.byte	PAN , 96
	.byte	VOL , 58
	.byte	W12
	.byte	N03, Bn5
	.byte	W03
	.byte	N06, Bn5, 36
	.byte	W09
	.byte	PAN , 93
	.byte	N03, An5, 112
	.byte	W03
	.byte	N06, An5, 36
	.byte	W06
	.byte	PAN , 80
	.byte	W03
	.byte	N03, Gn5, 112
	.byte	W03
	.byte	N06, Gn5, 36
	.byte	W09
	.byte	PAN , 48
	.byte	N03, Fs5, 112
	.byte	W03
	.byte	Fs5, 36
	.byte	W03
	.byte	En5, 112
	.byte	W03
	.byte	N06, En5, 36
	.byte	W09
	.byte	N03, Dn5, 112
	.byte	W03
	.byte	N06, Dn5, 36
	.byte	W03
	.byte	PAN , 37
	.byte	W06
	.byte	N03, As4, 112
	.byte	W03
	.byte	As4, 36
	.byte	W03
	.byte	N12, Fs5, 112
	.byte	W12
	.byte	VOICE , 56
	.byte	PAN , 37
	.byte	VOL , 73
	.byte	MOD , 8
	.byte	N12, Bn1
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W03
	.byte	PAN , 37
	.byte	W03
	.byte	VOICE , 17
	.byte	VOL , 68
	.byte	N03, Cn4, 64
	.byte	W03
	.byte	Cs4
	.byte	W03
	.byte	PAN , 50
	.byte	N03, Dn4
	.byte	W03
	.byte	En4
	.byte	W03
	.byte	PAN , 64
	.byte	N03, Dn4
	.byte	W03
	.byte	En4
	.byte	W03
	.byte	PAN , 82
	.byte	N03, Fs4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	PAN , 96
	.byte	N03, Fs4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	An4
	.byte	W03
	.byte	As4
	.byte	W03
	.byte	VOICE , 13
	.byte	MOD , 0
	.byte	PAN , 32
	.byte	VOL , 64
	.byte	W12
	.byte	N03, Dn6, 80
	.byte	W03
	.byte	N06, Dn6, 36
	.byte	W09
	.byte	PAN , 40
	.byte	N03, Cn6, 96
	.byte	W03
	.byte	N06, Cn6, 36
	.byte	W09
	.byte	PAN , 56
	.byte	N03, As5, 96
	.byte	W03
	.byte	N06, As5, 36
	.byte	W09
	.byte	PAN , 83
	.byte	N03, An5, 96
	.byte	W03
	.byte	An5, 36
	.byte	W03
	.byte	Gn5, 96
	.byte	W03
	.byte	N06, Gn5, 36
	.byte	W09
	.byte	N03, Fn5, 96
	.byte	W03
	.byte	N06, Fn5, 36
	.byte	W03
	.byte	PAN , 96
	.byte	W06
	.byte	N03, An5, 96
	.byte	W03
	.byte	An5, 36
	.byte	W03
	.byte	N12, Dn5, 96
	.byte	W12
	.byte	VOICE , 24
	.byte	PAN , 37
	.byte	VOL , 74
	.byte	MOD , 9
	.byte	N12, Dn2, 112
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12, Ds2
	.byte	W03
	.byte	MOD , 15
	.byte	W09
	.byte	VOICE , 24
	.byte	VOL , 68
	.byte	PAN , 88
	.byte	MOD , 9
	.byte	N03, An5, 88
	.byte	W03
	.byte	As5, 68
	.byte	W03
	.byte	An5, 64
	.byte	W06
	.byte	Gn5, 88
	.byte	W06
	.byte	Fn5, 76
	.byte	W06
	.byte	VOICE , 24
	.byte	MOD , 0
	.byte	PAN , 96
	.byte	VOL , 58
	.byte	W12
	.byte	N03, Dn6, 92
	.byte	W03
	.byte	N06, Dn6, 36
	.byte	W09
	.byte	PAN , 85
	.byte	N03, Cn6, 96
	.byte	W03
	.byte	N06, Cn6, 36
	.byte	W09
	.byte	PAN , 72
	.byte	N03, As5, 112
	.byte	W03
	.byte	N06, As5, 36
	.byte	W09
	.byte	PAN , 48
	.byte	N03, An5, 112
	.byte	W03
	.byte	An5, 36
	.byte	W03
	.byte	Gn5, 112
	.byte	W03
	.byte	N06, Gn5, 36
	.byte	W09
	.byte	N03, Fn5, 112
	.byte	W03
	.byte	N06, Fn5, 36
	.byte	W03
	.byte	PAN , 37
	.byte	W06
	.byte	N03, Cs5, 112
	.byte	W03
	.byte	Cs5, 36
	.byte	W03
	.byte	N12, An5, 112
	.byte	W12
	.byte	VOICE , 56
	.byte	PAN , 37
	.byte	VOL , 74
	.byte	MOD , 9
	.byte	N12, Dn2
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	VOICE , 17
	.byte	VOL , 68
	.byte	PAN , 115
	.byte	N03, Ds4, 64
	.byte	W03
	.byte	En4
	.byte	W03
	.byte	PAN , 94
	.byte	N03, Fn4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	PAN , 64
	.byte	N03, Fn4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	PAN , 47
	.byte	N03, An4
	.byte	W03
	.byte	PAN , 41
	.byte	N03, As4
	.byte	W03
	.byte	An4
	.byte	W03
	.byte	PAN , 26
	.byte	N03, As4
	.byte	W03
	.byte	Cn5
	.byte	W03
	.byte	Cs5
	.byte	W03
	.byte	VOICE , 24
	.byte	MOD , 0
	.byte	PAN , 52
	.byte	BEND , 58
	.byte	N03, An4, 112
	.byte	W06
	.byte	BEND , 64
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gs4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gn4
	.byte	W06
	.byte	N06, As3
	.byte	W06
	.byte	N12, Gn4
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	Gn4
	.byte	W12
	.byte	VOICE , 56
	.byte	PAN , 38
	.byte	MOD , 8
	.byte	VOL , 78
	.byte	N03, An2
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gs2
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gn2
	.byte	W06
	.byte	N06, As1
	.byte	W06
	.byte	N12, Gn2
	.byte	W12
	.byte	N24, As2
	.byte	W12
	.byte	MOD , 21
	.byte	W12
	.byte	VOICE , 38
	.byte	MOD , 10
	.byte	PAN , 64
	.byte	VOL , 55
	.byte	N03, An4, 92
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gs4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gn4
	.byte	W06
	.byte	N06, As3
	.byte	W06
	.byte	N12, Gn4, 76
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	Gn4
	.byte	W12
	.byte	MOD , 0
	.byte	N06, An4, 84
	.byte	W06
	.byte	N03, An3
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06, An3
	.byte	W06
	.byte	N03, An4
	.byte	W12
	.byte	An3
	.byte	W06
	.byte	N06, Gs3
	.byte	W06
	.byte	N03, An3
	.byte	W12
	.byte	VOICE , 17
	.byte	PAN , 108
	.byte	VOL , 60
	.byte	N03, An4, 72
	.byte	W03
	.byte	Gs4
	.byte	W03
	.byte	PAN , 91
	.byte	N03, Gn4
	.byte	W03
	.byte	Fs4
	.byte	W03
	.byte	PAN , 51
	.byte	N03, Fn4
	.byte	W03
	.byte	En4
	.byte	W03
	.byte	PAN , 24
	.byte	N03, Ds4
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	GOTO , 121, 77
	.byte	W11
	.byte	GsM2
	.byte	PAN , 70
	.byte	FINE
	.globl sSong450_Part3
sSong450_Part3: @ 0x088B5054
	.byte	KEYSH , 0
	.byte	VOICE , 126
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	PAN , 2
	.byte	VOL , 27
	.byte	W24
	.byte	N06, En5, 112
	.byte	W24
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W24
	.byte	PEND
	.byte	PATT , 97, 80
	.byte	W11
	.byte	GsM2
	.byte	PATT , 97, 80
	.byte	W11
	.byte	GsM2
	.byte	PATT , 97, 80
	.byte	W11
	.byte	GsM2
	.byte	PATT , 97, 80
	.byte	W11
	.byte	GsM2
	.byte	PATT , 97, 80
	.byte	W11
	.byte	GsM2
	.byte	PATT , 97, 80
	.byte	W11
	.byte	GsM2
	.byte	PATT , 97, 80
	.byte	W11
	.byte	GsM2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO , 97, 80
	.byte	W11
	.byte	GsM2
	.byte	FINE
	.globl sSong450_Part4
sSong450_Part4: @ 0x088B5099
	.byte	KEYSH , 0
	.byte	VOICE , 83
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	VOL , 39
	.byte	PAN , 3
	.byte	W24
	.byte	MOD , 2
	.byte	BEND , 64
	.byte	N12, Fs2, 112
	.byte	W12
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Gn2
	.byte	W12
	.byte	MOD , 8
	.byte	W12
	.byte	0
	.byte	N09, En2
	.byte	W09
	.byte	N03, Fn2
	.byte	W03
	.byte	MOD , 2
	.byte	N12, Fs2
	.byte	W12
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Gn2
	.byte	W12
	.byte	MOD , 7
	.byte	W12
	.byte	N03, Fs2, 64
	.byte	W03
	.byte	MOD , 0
	.byte	N03, Fn2
	.byte	W03
	.byte	En2
	.byte	W03
	.byte	Ds2
	.byte	W03
	.byte	MOD , 2
	.byte	N12, An2, 112
	.byte	W12
	.byte	N03, Gs2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Gs2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, Gs2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Gs2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	PEND
	.byte	N12
	.byte	W12
	.byte	N03, Gs2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Gs2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, As2
	.byte	W12
	.byte	MOD , 7
	.byte	W12
	.byte	0
	.byte	N06, Gn2
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	PATT , 60, 81
	.byte	W11
	.byte	GsM2
	.byte	N12, An2, 112
	.byte	W12
	.byte	N03, Gs2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Gs2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	As2
	.byte	W12
	.byte	Cn3
	.byte	W06
	.byte	As2
	.byte	W06
	.byte	Cn3
	.byte	W12
	.byte	Dn3
	.byte	W06
	.byte	BEND , 64
	.byte	N03, Fn4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, En4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Ds4
	.byte	W06
	.byte	N06, Gn3
	.byte	W06
	.byte	N12, Ds4
	.byte	W12
	.byte	Cs4
	.byte	W12
	.byte	Ds4
	.byte	W12
	.byte	N03, Fn4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, En4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Ds4
	.byte	W06
	.byte	N06, Gn3
	.byte	W06
	.byte	N12, Ds4
	.byte	W12
	.byte	N24, En4
	.byte	W12
	.byte	MOD , 7
	.byte	W12
	.byte	2
	.byte	N03, Fn4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, En4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Ds4
	.byte	W06
	.byte	N06, Gn3
	.byte	W06
	.byte	N12, Ds4
	.byte	W12
	.byte	Cs4
	.byte	W12
	.byte	Ds4
	.byte	W12
	.byte	N06, En4
	.byte	W06
	.byte	N03, En3
	.byte	W06
	.byte	En4
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06, En3
	.byte	W06
	.byte	N03, En4
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	En4
	.byte	W03
	.byte	Ds4
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	Cs4
	.byte	W03
	.byte	Cn4
	.byte	W03
	.byte	Bn3
	.byte	W03
	.byte	As3
	.byte	W03
	.byte	An3
	.byte	W03
	.byte	GOTO , 171, 80
	.byte	W11
	.byte	GsM2
	.byte	FINE
	.globl sSong450_Part5
sSong450_Part5: @ 0x088B5224
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	VOL , 39
	.byte	PAN , 127
	.byte	W24
	.byte	W12
	.byte	N03, Fs5, 112
	.byte	W12
	.byte	En5
	.byte	W12
	.byte	Dn5
	.byte	W12
	.byte	Cs5
	.byte	W06
	.byte	Bn4
	.byte	W12
	.byte	An4
	.byte	W12
	.byte	Cs5
	.byte	W06
	.byte	N12, Fs4
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	N03, Fn3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Fn3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Gn3
	.byte	W24
	.byte	N09, En3
	.byte	W09
	.byte	N03, Fn3
	.byte	W03
	.byte	W12
	.byte	Fs5
	.byte	W12
	.byte	En5
	.byte	W12
	.byte	Dn5
	.byte	W12
	.byte	Cs5
	.byte	W06
	.byte	Bn4
	.byte	W12
	.byte	An4
	.byte	W12
	.byte	En4
	.byte	W06
	.byte	N12, Bn4
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	N03, Fn3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Fn3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	Gn3
	.byte	W03
	.byte	Gs3
	.byte	W03
	.byte	An3
	.byte	W03
	.byte	As3
	.byte	W03
	.byte	An3
	.byte	W03
	.byte	As3
	.byte	W03
	.byte	Cn4
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	Cn4
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	En4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	W12
	.byte	An5
	.byte	W12
	.byte	Gn5
	.byte	W12
	.byte	Fn5
	.byte	W12
	.byte	En5
	.byte	W06
	.byte	Dn5
	.byte	W12
	.byte	Cn5
	.byte	W12
	.byte	En5
	.byte	W06
	.byte	N12, An4
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	N03, Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12, As3
	.byte	W12
	.byte	N03, Dn5
	.byte	W03
	.byte	Ds5
	.byte	W03
	.byte	Dn5
	.byte	W06
	.byte	Cn5
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	W12
	.byte	An5
	.byte	W12
	.byte	Gn5
	.byte	W12
	.byte	Fn5
	.byte	W12
	.byte	En5
	.byte	W06
	.byte	Dn5
	.byte	W12
	.byte	Cn5
	.byte	W12
	.byte	Gn4
	.byte	W06
	.byte	N12, Dn5
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	N03, Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	As3
	.byte	W03
	.byte	Bn3
	.byte	W03
	.byte	Cn4
	.byte	W03
	.byte	Cs4
	.byte	W03
	.byte	Cn4
	.byte	W03
	.byte	Cs4
	.byte	W03
	.byte	Ds4
	.byte	W03
	.byte	Fn4
	.byte	W03
	.byte	Ds4
	.byte	W03
	.byte	Fn4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	As4
	.byte	W03
	.byte	VOL , 54
	.byte	N06, An5
	.byte	W06
	.byte	An5, 36
	.byte	W06
	.byte	An5, 112
	.byte	W06
	.byte	An5, 36
	.byte	W06
	.byte	PAN , 3
	.byte	W06
	.byte	N06, An5, 112
	.byte	W06
	.byte	An5, 36
	.byte	W12
	.byte	PAN , 127
	.byte	N06, An5, 112
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	An5
	.byte	W06
	.byte	PAN , 3
	.byte	N06, An5, 36
	.byte	W12
	.byte	An5, 112
	.byte	W06
	.byte	An5, 36
	.byte	W06
	.byte	PAN , 127
	.byte	N06, An5, 112
	.byte	W06
	.byte	An5, 36
	.byte	W06
	.byte	An5, 112
	.byte	W06
	.byte	An5, 36
	.byte	W06
	.byte	PAN , 3
	.byte	W06
	.byte	N06, An5, 112
	.byte	W06
	.byte	An5, 36
	.byte	W12
	.byte	PAN , 127
	.byte	N06, An5, 112
	.byte	W06
	.byte	An5, 36
	.byte	W06
	.byte	An4, 112
	.byte	W06
	.byte	An5
	.byte	W06
	.byte	PAN , 3
	.byte	N06, An5, 36
	.byte	W12
	.byte	An5, 112
	.byte	W06
	.byte	An5, 36
	.byte	W06
	.byte	PEND
	.byte	PATT , 71, 83
	.byte	W11
	.byte	GsM2
	.byte	PAN , 127
	.byte	N06, An4, 112
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	PAN , 3
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	PAN , 127
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	VOL , 39
	.byte	N03, Cs5
	.byte	W03
	.byte	Cn5
	.byte	W03
	.byte	Bn4
	.byte	W03
	.byte	As4
	.byte	W03
	.byte	An4
	.byte	W03
	.byte	Gs4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	Fs4
	.byte	W03
	.byte	GOTO , 54, 82
	.byte	W11
	.byte	GsM2
	.byte	PAN , 127
	.byte	FINE
	.globl sSong450_Part6
sSong450_Part6: @ 0x088B53B2
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	PAN , 64
	.byte	VOL , 66
	.byte	N06, Cn1, 112
	.byte	N24, An2, 76
	.byte	W06
	.byte	N06, Cn1, 112
	.byte	W06
	.byte	N03, Dn1
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N06
	.byte	W06
	.byte	N48, An2, 112
	.byte	W18
	.byte	N06, Cn1
	.byte	W06
	.byte	En1
	.byte	W12
	.byte	Cn1
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	Cn1, 96
	.byte	W06
	.byte	En1, 112
	.byte	W12
	.byte	Cn1
	.byte	W12
	.byte	PEND
	.byte	N06, Cn1, 112
	.byte	W18
	.byte	N06
	.byte	W06
	.byte	En1
	.byte	W12
	.byte	Cn1
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	Cn1, 96
	.byte	W06
	.byte	En1, 112
	.byte	W12
	.byte	Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT , 204, 83
	.byte	W11
	.byte	GsM2
	.byte	PATT , 226, 83
	.byte	W11
	.byte	GsM2
	.byte	N48, An2, 112
	.byte	W18
	.byte	N06, Cn1
	.byte	W06
	.byte	En1
	.byte	W12
	.byte	Cn1
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	Cn1, 96
	.byte	W06
	.byte	En1, 112
	.byte	W24
	.byte	PEND
	.byte	W18
	.byte	Cn1
	.byte	W06
	.byte	En1
	.byte	W12
	.byte	Cn1
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	Cn1, 96
	.byte	W06
	.byte	En1, 112
	.byte	W24
	.byte	PATT , 1, 84
	.byte	W11
	.byte	GsM2
	.byte	N06, Cn1, 112
	.byte	W18
	.byte	N06
	.byte	W06
	.byte	En1
	.byte	W12
	.byte	Cn1
	.byte	W12
	.byte	N06
	.byte	W18
	.byte	En1
	.byte	W06
	.byte	N06
	.byte	W24
	.byte	N06, En1, 112
	.byte	W06
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	Cn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En1
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	PEND
	.byte	PATT , 57, 84
	.byte	W11
	.byte	GsM2
	.byte	PATT , 57, 84
	.byte	W11
	.byte	GsM2
	.byte	N06, En1, 112
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W12
	.byte	Cn1
	.byte	W06
	.byte	En1
	.byte	W12
	.byte	Cn1
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N03, En1
	.byte	N24, An2
	.byte	W03
	.byte	N03, En1
	.byte	W21
	.byte	GOTO , 204, 83
	.byte	W11
	.byte	GsM2
	.byte	FINE
	.globl sSong450_Part7
sSong450_Part7: @ 0x088B547A
	.byte	KEYSH , 0
	.byte	VOICE , 84
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 52
	.byte	W24
	.byte	MOD , 8
	.byte	BEND , 60
	.byte	N12, Bn1, 112
	.byte	W03
	.byte	MOD , 2
	.byte	W03
	.byte	BEND , 64
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N18, Cn2
	.byte	W06
	.byte	MOD , 15
	.byte	W12
	.byte	0
	.byte	N03, Bn1
	.byte	W03
	.byte	As1
	.byte	W03
	.byte	N09, An1
	.byte	W09
	.byte	N03, As1
	.byte	W03
	.byte	MOD , 2
	.byte	N12, Bn1
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Bn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Cn2
	.byte	W06
	.byte	MOD , 14
	.byte	W18
	.byte	N03, Bn1, 88
	.byte	W03
	.byte	MOD , 0
	.byte	N03, As1
	.byte	W03
	.byte	An1
	.byte	W03
	.byte	Gs1
	.byte	W03
	.byte	MOD , 2
	.byte	N12, Dn2, 112
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Ds2
	.byte	W03
	.byte	MOD , 13
	.byte	W21
	.byte	N06, Cn2
	.byte	W03
	.byte	MOD , 3
	.byte	W03
	.byte	N06, Cs2
	.byte	W06
	.byte	N12, Dn2
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	BEND , 64
	.byte	N12
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, Cs2
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En2
	.byte	W12
	.byte	Fn2
	.byte	W06
	.byte	En2
	.byte	W06
	.byte	Fn2
	.byte	W12
	.byte	Gn2
	.byte	W06
	.byte	BEND , 60
	.byte	N03, An2
	.byte	W06
	.byte	BEND , 64
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gs2
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gn2
	.byte	W06
	.byte	N06, As1
	.byte	W06
	.byte	N12, Gn2
	.byte	W12
	.byte	Fn2
	.byte	W12
	.byte	Gn2
	.byte	W12
	.byte	N03, An2
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gs2
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gn2
	.byte	W06
	.byte	N06, As1
	.byte	W06
	.byte	N12, Gn2
	.byte	W12
	.byte	N24, As2
	.byte	W12
	.byte	MOD , 16
	.byte	W12
	.byte	2
	.byte	N03, An2
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gs2
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gn2
	.byte	W06
	.byte	N06, As1
	.byte	W06
	.byte	N12, Gn2
	.byte	W12
	.byte	Fn2
	.byte	W12
	.byte	Gn2
	.byte	W12
	.byte	N06, An2
	.byte	W06
	.byte	N03, An1
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	N06, An1
	.byte	W06
	.byte	N03, An2
	.byte	W12
	.byte	An1
	.byte	W12
	.byte	N03
	.byte	W36
	.byte	GOTO , 140, 84
	.byte	W11
	.byte	GsM2
	.byte	FINE
	.globl sSong450_Part8
sSong450_Part8: @ 0x088B5620
	.byte	KEYSH , 0
	.byte	VOICE , 47
	.byte	PAN , 64
	.byte	VOL , 49
	.byte	N06, Bn1, 112
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PAN , 87
	.byte	N06, Bn2
	.byte	W06
	.byte	N03, Fs1
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	PAN , 34
	.byte	N12, Bn1, 112
	.byte	W60
	.byte	N06, Fs1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PAN , 90
	.byte	N06, Bn1
	.byte	W24
	.byte	PAN , 96
	.byte	N06
	.byte	W12
	.byte	PAN , 32
	.byte	N06, Fs1
	.byte	W06
	.byte	PAN , 96
	.byte	N06, Bn1
	.byte	W12
	.byte	PAN , 16
	.byte	N06, Fs1
	.byte	W06
	.byte	PAN , 96
	.byte	N06, Bn1
	.byte	W12
	.byte	PAN , 32
	.byte	N06, Fs1
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	PAN , 95
	.byte	N03, Cn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, An1
	.byte	W12
	.byte	PAN , 64
	.byte	N12, Bn1
	.byte	W48
	.byte	PAN , 87
	.byte	N06, As1
	.byte	W12
	.byte	PAN , 33
	.byte	N06, Fs1
	.byte	W12
	.byte	PAN , 87
	.byte	N06, Bn1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PAN , 35
	.byte	N12, Fs1
	.byte	W03
	.byte	PAN , 33
	.byte	W09
	.byte	86
	.byte	N06, Bn1
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	PAN , 31
	.byte	N06, Fn1
	.byte	W06
	.byte	PAN , 86
	.byte	N06, Bn1
	.byte	W06
	.byte	Fn1
	.byte	W03
	.byte	PAN , 32
	.byte	W09
	.byte	N06, Fs1
	.byte	W06
	.byte	PAN , 86
	.byte	N06, Bn1
	.byte	W06
	.byte	PAN , 33
	.byte	N06, Fs1
	.byte	W12
	.byte	PAN , 99
	.byte	N06, Bn1
	.byte	W12
	.byte	PAN , 31
	.byte	N06, Fs1
	.byte	W12
	.byte	PAN , 87
	.byte	N12, Dn2
	.byte	W36
	.byte	PAN , 28
	.byte	W12
	.byte	86
	.byte	N06, An2
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	PAN , 27
	.byte	N06, An2
	.byte	W12
	.byte	PAN , 86
	.byte	N06, Dn3
	.byte	W12
	.byte	PAN , 28
	.byte	N06, An2
	.byte	W06
	.byte	N03, An1
	.byte	W06
	.byte	PAN , 90
	.byte	N12, Dn2
	.byte	W48
	.byte	N06, An2
	.byte	W12
	.byte	As2
	.byte	W12
	.byte	An2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PAN , 29
	.byte	N06, Ds2
	.byte	W12
	.byte	N12, Dn2
	.byte	W48
	.byte	PAN , 89
	.byte	N06, Dn3
	.byte	W12
	.byte	PAN , 29
	.byte	N06, An2
	.byte	W12
	.byte	PAN , 87
	.byte	N06, Dn3
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PAN , 29
	.byte	N06, An2
	.byte	W12
	.byte	PAN , 20
	.byte	N06
	.byte	W12
	.byte	An2, 52
	.byte	W12
	.byte	An2, 84
	.byte	W12
	.byte	An2, 96
	.byte	W12
	.byte	An2, 112
	.byte	W12
	.byte	An2, 127
	.byte	W12
	.byte	An2, 112
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	PAN , 32
	.byte	N06, An2, 112
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PAN , 103
	.byte	N06, Dn2
	.byte	W12
	.byte	PAN , 32
	.byte	N06, Gs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PAN , 103
	.byte	N06, Cs2
	.byte	W12
	.byte	PAN , 32
	.byte	N06, Gn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PAN , 103
	.byte	N06, Cn2
	.byte	W12
	.byte	PAN , 16
	.byte	N24, As2
	.byte	W24
	.byte	PEND
	.byte	PATT , 31, 87
	.byte	W11
	.byte	GsM2
	.byte	N06, An2, 112
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	Cs2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	Cn2
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N12, As2
	.byte	W12
	.byte	PAN , 112
	.byte	N12
	.byte	W12
	.byte	PAN , 97
	.byte	N06, An2
	.byte	W06
	.byte	PAN , 17
	.byte	N06, An1
	.byte	W06
	.byte	PAN , 96
	.byte	N03, An2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	PAN , 17
	.byte	N06, An1
	.byte	W06
	.byte	PAN , 96
	.byte	N06, An2
	.byte	W06
	.byte	N06
	.byte	W12
	.byte	PAN , 21
	.byte	N06, An1
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	PAN , 99
	.byte	N06, An2
	.byte	W24
	.byte	GOTO , 56, 86
	.byte	W11
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8B579F, 0x1
	.globl sSongHeader_450
sSongHeader_450: @ 0x088B57A0
	.byte 0x09, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_0861A99C  @ tone
	.4byte 0x088B4B48, 0x088B4B98, 0x088B4D6E, 0x088B5054, 0x088B5099, 0x088B5224, 0x088B53B2, 0x088B547A, 0x088B5620  @ parts
