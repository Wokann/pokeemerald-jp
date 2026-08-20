.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong380_Part0
sSong380_Part0: @ 0x0887DAF0
	.byte	KEYSH , 0
	.byte	TEMPO , 69
	.byte	VOICE , 17
	.byte	LFOS , 40
	.byte	VOL , 80
	.byte	PAN , 64
	.byte	N06, Ds5, 56
	.byte	W06
	.byte	Cn5
	.byte	W06
	.byte	Ds5
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	Cn5
	.byte	W06
	.byte	Ds5
	.byte	W24
	.byte	Ds4, 80
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	N09, Cn5, 80
	.byte	W18
	.byte	Ds5
	.byte	W18
	.byte	N21, As4
	.byte	W09
	.byte	MOD , 7
	.byte	W12
	.byte	0
	.byte	W03
	.byte	N06
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	N09, Gn4
	.byte	W18
	.byte	Gs4
	.byte	W18
	.byte	N21, As4
	.byte	W09
	.byte	MOD , 8
	.byte	W12
	.byte	0
	.byte	N03, Fs4
	.byte	W03
	.byte	N12, Gn4
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	Ds4
	.byte	W12
	.byte	N09, Fs4
	.byte	W18
	.byte	N18, Cs5
	.byte	W18
	.byte	N48, As4
	.byte	W12
	.byte	MOD , 8
	.byte	W36
	.byte	0
	.byte	W12
	.byte	N09, Fs4
	.byte	W18
	.byte	N18, Cs5
	.byte	W18
	.byte	N24, As4
	.byte	W09
	.byte	MOD , 8
	.byte	W15
	.byte	0
	.byte	N06, Ds4
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	As3
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	N12, An4
	.byte	W18
	.byte	Gn4
	.byte	W18
	.byte	N09, Fn4
	.byte	W09
	.byte	N03, En4
	.byte	W03
	.byte	N12, Fn4
	.byte	W18
	.byte	Dn4
	.byte	W18
	.byte	N09, Cn4
	.byte	W09
	.byte	N03, En4
	.byte	W03
	.byte	N09, Fn4
	.byte	W18
	.byte	N12, Cn5
	.byte	W12
	.byte	N03, Fn4
	.byte	W03
	.byte	Gs4
	.byte	W03
	.byte	N24, An4
	.byte	W09
	.byte	MOD , 7
	.byte	W15
	.byte	0
	.byte	N06, Ds4
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Cn4
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Fn4
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	As3
	.byte	W12
	.byte	N03, As4
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N06, Gs4
	.byte	W06
	.byte	As4
	.byte	W24
	.byte	Gs4
	.byte	W12
	.byte	As4
	.byte	W24
	.byte	N06
	.byte	W18
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	Fn5
	.byte	W12
	.byte	Dn5
	.byte	W24
	.byte	Fn4
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	GOTO , 19, 219
	.byte	W07
	.byte	GsM2
	.byte	FINE
	.globl sSong380_Part1
sSong380_Part1: @ 0x0887DBC8
	.byte	KEYSH , 0
	.byte	VOICE , 36
	.byte	VOL , 80
	.byte	W48
	.byte	PAN , 72
	.byte	N06, Ds1, 116
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N15
	.byte	W18
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Ds1, 116
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Ds2
	.byte	W06
	.byte	N12, Ds1
	.byte	W12
	.byte	N03, As1
	.byte	W12
	.byte	N12, Ds1
	.byte	W12
	.byte	N03, Gn1
	.byte	W06
	.byte	Ds1
	.byte	W06
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Gn1
	.byte	W06
	.byte	Cn2
	.byte	W06
	.byte	N12, Ds2
	.byte	W12
	.byte	N03, Ds1
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N12, As1
	.byte	W12
	.byte	Gs1
	.byte	W12
	.byte	N06, Fs1
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Fs2
	.byte	W06
	.byte	N12, Fs1
	.byte	W12
	.byte	N03, Cs2
	.byte	W12
	.byte	N12, Fs1
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	Fs1
	.byte	W06
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, As1
	.byte	W06
	.byte	Ds2
	.byte	W06
	.byte	N12, Fs2
	.byte	W12
	.byte	N03, Fs1
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N12, Gs1
	.byte	W12
	.byte	Fs1
	.byte	W12
	.byte	N06, Fn1
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N03, Fn2
	.byte	W06
	.byte	N12, Fn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Fn1
	.byte	W12
	.byte	N03, An1
	.byte	W06
	.byte	Fn1
	.byte	W06
	.byte	N06
	.byte	W18
	.byte	N06
	.byte	W18
	.byte	N15
	.byte	W18
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N12, Ds1
	.byte	W12
	.byte	Cn1
	.byte	W12
	.byte	N03, As0
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N18
	.byte	W18
	.byte	N03, As1
	.byte	W06
	.byte	As0
	.byte	W06
	.byte	N06
	.byte	W12
	.byte	N03, Gs1
	.byte	W06
	.byte	As1
	.byte	W06
	.byte	N06, As0
	.byte	W12
	.byte	N03, Gs1
	.byte	W06
	.byte	As1
	.byte	W06
	.byte	N12, As0
	.byte	W12
	.byte	N03, As1
	.byte	W06
	.byte	N06, As0
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	As1
	.byte	W06
	.byte	N48, As0
	.byte	W48
	.byte	GOTO , 221, 219
	.byte	W07
	.byte	GsM2
	.byte	FINE
	.globl sSong380_Part2
sSong380_Part2: @ 0x0887DC9C
	.byte	KEYSH , 0
	.byte	VOICE , 56
	.byte	VOL , 80
	.byte	PAN , 15
	.byte	BEND , 64
	.byte	N06, Gn4, 68
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	Gn4
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	Gn4
	.byte	W48
	.byte	W96
	.byte	W72
	.byte	PAN , 56
	.byte	N09, As2, 112
	.byte	W12
	.byte	Cn3
	.byte	W12
	.byte	N84, Cs3
	.byte	W12
	.byte	VOL , 74
	.byte	W12
	.byte	68
	.byte	W12
	.byte	60
	.byte	W06
	.byte	52
	.byte	W06
	.byte	46
	.byte	W09
	.byte	51
	.byte	W06
	.byte	56
	.byte	W06
	.byte	61
	.byte	W06
	.byte	68
	.byte	W06
	.byte	75
	.byte	W06
	.byte	80
	.byte	W03
	.byte	N03, Bn2
	.byte	W03
	.byte	Cn3
	.byte	W03
	.byte	N09, Cs3
	.byte	W18
	.byte	N12, Ds3
	.byte	W18
	.byte	N56, Cs3
	.byte	W21
	.byte	VOL , 77
	.byte	W09
	.byte	74
	.byte	W09
	.byte	63
	.byte	W06
	.byte	48
	.byte	W06
	.byte	35
	.byte	W03
	.byte	18
	.byte	W06
	.byte	W48
	.byte	80
	.byte	N12, Fn3
	.byte	W18
	.byte	Dn3
	.byte	W18
	.byte	N09, Cn3
	.byte	W12
	.byte	N09
	.byte	W18
	.byte	N12, An3
	.byte	W18
	.byte	N18, Fn3
	.byte	W09
	.byte	VOL , 74
	.byte	W03
	.byte	51
	.byte	W06
	.byte	80
	.byte	N03, Cn3
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N12, An2
	.byte	W12
	.byte	Cn3
	.byte	W12
	.byte	W96
	.byte	N06, As2
	.byte	W18
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	Fn3
	.byte	W12
	.byte	Dn3
	.byte	W48
	.byte	GOTO , 180, 220
	.byte	W07
	.byte	GsM2
	.byte	FINE
	.globl sSong380_Part3
sSong380_Part3: @ 0x0887DD27
	.byte	KEYSH , 0
	.byte	VOICE , 80
	.byte	VOL , 80
	.byte	XCMD , 8 , 13
	.byte	9 , 10
	.byte	PAN , 64
	.byte	N06, As5, 52
	.byte	W06
	.byte	Gn5
	.byte	W06
	.byte	As5
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	Gn5
	.byte	W06
	.byte	As5
	.byte	W48
	.byte	VOICE , 82
	.byte	PAN , 64
	.byte	N09, Gn4, 52
	.byte	W18
	.byte	Cn5
	.byte	W18
	.byte	N18, Gn4
	.byte	W18
	.byte	VOICE , 7
	.byte	PAN , 16
	.byte	N03, Cn4, 60
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	Ds3
	.byte	W06
	.byte	Cn4
	.byte	W06
	.byte	As3
	.byte	W06
	.byte	Cn4
	.byte	W06
	.byte	VOICE , 82
	.byte	PAN , 64
	.byte	N09, Ds4, 52
	.byte	W18
	.byte	Fn4
	.byte	W18
	.byte	N18, Gn4
	.byte	W18
	.byte	VOICE , 7
	.byte	PAN , 15
	.byte	N06, Cn3, 60
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N12, As3
	.byte	W12
	.byte	Cn4
	.byte	W12
	.byte	VOICE , 82
	.byte	PAN , 63
	.byte	N09, Cs4, 52
	.byte	W18
	.byte	N12, As4
	.byte	W18
	.byte	N18, Fs4
	.byte	W18
	.byte	VOICE , 7
	.byte	PAN , 16
	.byte	N03, Ds4, 60
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	VOICE , 82
	.byte	N09, Cs4, 52
	.byte	W03
	.byte	PAN , 63
	.byte	W15
	.byte	N12, As4
	.byte	W18
	.byte	N18, Fs4
	.byte	W18
	.byte	VOICE , 7
	.byte	PAN , 16
	.byte	N03, Ds3, 60
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Cs3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	As3
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	N12, Fn3, 72
	.byte	W18
	.byte	Ds3
	.byte	W18
	.byte	N09, Dn3
	.byte	W12
	.byte	N12, Cn3
	.byte	W18
	.byte	As2
	.byte	W18
	.byte	N09, An2
	.byte	W12
	.byte	VOICE , 82
	.byte	PAN , 64
	.byte	N09, Cn4, 52
	.byte	W18
	.byte	N12, An4
	.byte	W18
	.byte	N18, Fn4
	.byte	W18
	.byte	VOICE , 7
	.byte	PAN , 15
	.byte	N03, Ds3, 60
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N12, Cn3
	.byte	W12
	.byte	Ds3
	.byte	W12
	.byte	VOICE , 82
	.byte	PAN , 64
	.byte	N06, Fn3, 52
	.byte	W12
	.byte	N03, Fn4
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N06, Dn4
	.byte	W06
	.byte	Fn4
	.byte	W24
	.byte	Dn4
	.byte	W12
	.byte	Fn4
	.byte	W24
	.byte	VOICE , 7
	.byte	PAN , 16
	.byte	N06, Fn4, 60
	.byte	W18
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	Dn5
	.byte	W12
	.byte	As4
	.byte	W48
	.byte	GOTO , 66, 221
	.byte	W07
	.byte	GsM2
	.byte	FINE
	.globl sSong380_Part4
sSong380_Part4: @ 0x0887DE19
	.byte	KEYSH , 0
	.byte	VOICE , 56
	.byte	VOL , 80
	.byte	XCMD , 8 , 13
	.byte	9 , 10
	.byte	PAN , 112
	.byte	N06, Ds4, 68
	.byte	W06
	.byte	Cn4
	.byte	W06
	.byte	Ds4
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	Cn4
	.byte	W06
	.byte	Ds4
	.byte	W48
	.byte	VOICE , 2
	.byte	PAN , 111
	.byte	N03, Ds3, 60
	.byte	W06
	.byte	N06, Cn4
	.byte	W06
	.byte	N03, Gn3
	.byte	W06
	.byte	N06, As3
	.byte	W06
	.byte	PAN , 16
	.byte	N03, Ds3
	.byte	W06
	.byte	N06, Cn4
	.byte	W06
	.byte	N03, Gn3
	.byte	W06
	.byte	N06, As3
	.byte	W06
	.byte	VOICE , 8
	.byte	W06
	.byte	PAN , 112
	.byte	N03, Gn3
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	VOICE , 2
	.byte	N03, Ds3
	.byte	W06
	.byte	N06, Cn4
	.byte	W06
	.byte	N03, Gn3
	.byte	W06
	.byte	N06, As3
	.byte	W06
	.byte	PAN , 16
	.byte	N03, Ds3
	.byte	W06
	.byte	N06, Cn4
	.byte	W06
	.byte	N03, Gn3
	.byte	W06
	.byte	N06, As3
	.byte	W06
	.byte	VOICE , 8
	.byte	W06
	.byte	PAN , 112
	.byte	N06, Gn2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N12, Ds3
	.byte	W12
	.byte	Fn3
	.byte	W12
	.byte	VOICE , 2
	.byte	N03, Fs3
	.byte	W06
	.byte	N06, Ds4
	.byte	W06
	.byte	N03, As3
	.byte	W06
	.byte	N06, Cs4
	.byte	W06
	.byte	PAN , 16
	.byte	N03, Fs3
	.byte	W06
	.byte	N06, Ds4
	.byte	W06
	.byte	N03, As3
	.byte	W06
	.byte	N06, Cs4
	.byte	W06
	.byte	VOICE , 8
	.byte	W06
	.byte	PAN , 112
	.byte	N03, As3
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	VOICE , 2
	.byte	N03, Fs3
	.byte	W06
	.byte	N06, Ds4
	.byte	W06
	.byte	N03, As3
	.byte	W06
	.byte	N06, Cs4
	.byte	W06
	.byte	PAN , 16
	.byte	N03, Fs3
	.byte	W06
	.byte	N06, Ds4
	.byte	W06
	.byte	N03, As3
	.byte	W06
	.byte	N06, Cs4
	.byte	W06
	.byte	VOICE , 8
	.byte	W06
	.byte	PAN , 112
	.byte	N03, As2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	Cs3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	N12, Cn4, 72
	.byte	W18
	.byte	As3
	.byte	W18
	.byte	N09, An3
	.byte	W12
	.byte	N12
	.byte	W18
	.byte	Gn3
	.byte	W18
	.byte	N09, Fn3
	.byte	W12
	.byte	VOICE , 2
	.byte	N03, Fn2, 60
	.byte	W06
	.byte	N06, Ds3
	.byte	W06
	.byte	N03, An2
	.byte	W06
	.byte	N06, Cn3
	.byte	W06
	.byte	PAN , 16
	.byte	N03, Fn2
	.byte	W06
	.byte	N06, Ds3
	.byte	W06
	.byte	N03, An2
	.byte	W06
	.byte	N06, Cn3
	.byte	W06
	.byte	VOICE , 8
	.byte	W06
	.byte	PAN , 112
	.byte	N03, An2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N12, Fn2
	.byte	W12
	.byte	An2
	.byte	W12
	.byte	N03, As2
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	PAN , 64
	.byte	N03, As2
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	PAN , 16
	.byte	N03, As2
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	PAN , 64
	.byte	N03, As2
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	PAN , 112
	.byte	N06, Dn4
	.byte	W18
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	As4
	.byte	W12
	.byte	Fn4
	.byte	W48
	.byte	GOTO , 52, 222
	.byte	W07
	.byte	GsM2
	.byte	FINE
	.globl sSong380_Part5
sSong380_Part5: @ 0x0887DF5D
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	VOL , 80
	.byte	PAN , 64
	.byte	W72
	.byte	N06, Ds4, 48
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	N09, Cn5, 48
	.byte	W18
	.byte	Ds5
	.byte	W18
	.byte	N21, As4
	.byte	W09
	.byte	MOD , 7
	.byte	W12
	.byte	0
	.byte	W03
	.byte	N06
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	N09, Gn4
	.byte	W18
	.byte	Gs4
	.byte	W18
	.byte	N21, As4
	.byte	W09
	.byte	MOD , 8
	.byte	W12
	.byte	0
	.byte	N03, Fs4
	.byte	W03
	.byte	N12, Gn4
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	Ds4
	.byte	W12
	.byte	N09, Fs4
	.byte	W18
	.byte	N18, Cs5
	.byte	W18
	.byte	N48, As4
	.byte	W12
	.byte	MOD , 8
	.byte	W36
	.byte	0
	.byte	W12
	.byte	N09, Fs4
	.byte	W18
	.byte	N18, Cs5
	.byte	W18
	.byte	N24, As4
	.byte	W09
	.byte	MOD , 8
	.byte	W15
	.byte	0
	.byte	N06, Ds4
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	As3
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	Ds4
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	N12, An4
	.byte	W18
	.byte	Gn4
	.byte	W18
	.byte	N09, Fn4
	.byte	W09
	.byte	N03, En4
	.byte	W03
	.byte	N12, Fn4
	.byte	W18
	.byte	Dn4
	.byte	W18
	.byte	N09, Cn4
	.byte	W09
	.byte	N03, En4
	.byte	W03
	.byte	N09, Fn4
	.byte	W18
	.byte	N12, Cn5
	.byte	W12
	.byte	N03, Fn4
	.byte	W03
	.byte	Gs4
	.byte	W03
	.byte	N24, An4
	.byte	W09
	.byte	MOD , 7
	.byte	W15
	.byte	0
	.byte	N06, Ds4
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Cn4
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Fn4
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	As3
	.byte	W12
	.byte	N03, As4
	.byte	W06
	.byte	N12
	.byte	W12
	.byte	N06, Gs4
	.byte	W06
	.byte	As4
	.byte	W24
	.byte	Gs4
	.byte	W12
	.byte	As4
	.byte	W24
	.byte	N06
	.byte	W18
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	Fn5
	.byte	W12
	.byte	Dn5
	.byte	W24
	.byte	Fn4
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	GOTO , 112, 223
	.byte	W07
	.byte	GsM2
	.byte	FINE
	.globl sSong380_Part6
sSong380_Part6: @ 0x0887E025
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 80
	.byte	N48, An2, 80
	.byte	W72
	.byte	N06, En1, 64
	.byte	W06
	.byte	En1, 76
	.byte	W06
	.byte	En1, 88
	.byte	W06
	.byte	En1, 104
	.byte	W06
	.byte	N06, Cn1, 120
	.byte	N96, An2, 80
	.byte	W12
	.byte	N06, Fs1, 60
	.byte	W12
	.byte	En1, 112
	.byte	W12
	.byte	Fs1, 60
	.byte	W06
	.byte	Cn1, 120
	.byte	W06
	.byte	Fs1, 60
	.byte	W12
	.byte	Cn1, 120
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	En1, 112
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06, Cn1, 120
	.byte	W12
	.byte	Fs1, 60
	.byte	W12
	.byte	En1, 112
	.byte	W12
	.byte	Fs1, 60
	.byte	W06
	.byte	Cn1, 120
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	Cn1, 120
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	Cn1, 120
	.byte	W06
	.byte	En1, 112
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	N12, As1, 68
	.byte	W12
	.byte	PEND
	.byte	N06, Cn1, 120
	.byte	W12
	.byte	Fs1, 60
	.byte	W12
	.byte	En1, 112
	.byte	W12
	.byte	Fs1, 60
	.byte	W06
	.byte	Cn1, 120
	.byte	W06
	.byte	Fs1, 60
	.byte	W12
	.byte	Cn1, 120
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	En1, 112
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PATT , 99, 224
	.byte	W07
	.byte	GsM2
	.byte	N06, Cn1, 120
	.byte	N48, An2, 80
	.byte	W12
	.byte	N06, Fs1, 60
	.byte	W12
	.byte	En1, 112
	.byte	W12
	.byte	Fs1, 60
	.byte	W06
	.byte	Cn1, 120
	.byte	W06
	.byte	Fs1, 60
	.byte	W12
	.byte	Cn1, 120
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	En1, 112
	.byte	W06
	.byte	Fs1, 60
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	PATT , 99, 224
	.byte	W07
	.byte	GsM2
	.byte	N06, En1, 112
	.byte	N96, An2, 80
	.byte	W12
	.byte	N06, Cn1, 120
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En1, 112
	.byte	W12
	.byte	Cn1, 120
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En1, 112
	.byte	W12
	.byte	Cn1, 120
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En1, 112
	.byte	W12
	.byte	Cn1, 120
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En1, 112
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	Cn1, 120
	.byte	W06
	.byte	En1, 112
	.byte	W18
	.byte	Cn1, 120
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En1, 112
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	GOTO , 60, 224
	.byte	W07
	.byte	GsM2
	.byte	FINE
	.globl sSongHeader_380
sSongHeader_380: @ 0x0887E124
	.byte 0x07, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_086038C0  @ tone
	.4byte 0x0887DAF0, 0x0887DBC8, 0x0887DC9C, 0x0887DD27, 0x0887DE19, 0x0887DF5D, 0x0887E025  @ parts
