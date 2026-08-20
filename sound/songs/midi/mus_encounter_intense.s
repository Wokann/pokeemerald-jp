.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong416_Part0
sSong416_Part0: @ 0x0889A94C
	.byte	KEYSH , 0
	.byte	TEMPO , 70
	.byte	VOICE , 127
	.byte	LFOS , 44
	.byte	PAN , 127
	.byte	VOL , 50
	.byte	W24
	.byte	N12, En4, 112
	.byte	W12
	.byte	N06, En4, 60
	.byte	W12
	.byte	N12, En4, 112
	.byte	W12
	.byte	N06, En4, 60
	.byte	W12
	.byte	N12, En4, 112
	.byte	W12
	.byte	N06, En4, 60
	.byte	W12
	.byte	N12, En4, 112
	.byte	W12
	.byte	N06, En4, 64
	.byte	W12
	.byte	PEND
	.byte	N12, En4, 112
	.byte	W12
	.byte	N06, En4, 60
	.byte	W12
	.byte	N12, En4, 112
	.byte	W12
	.byte	N06, En4, 60
	.byte	W12
	.byte	N12, En4, 112
	.byte	W12
	.byte	N06, En4, 60
	.byte	W12
	.byte	N12, En4, 112
	.byte	W24
	.byte	PEND
	.byte	PATT , 89, 169
	.byte	W09
	.byte	GsM2
	.byte	W72
	.byte	N06, En4, 112
	.byte	W06
	.byte	N06
	.byte	W18
	.byte	PEND
	.byte	PATT , 89, 169
	.byte	W09
	.byte	GsM2
	.byte	PATT , 122, 169
	.byte	W09
	.byte	GsM2
	.byte	PATT , 89, 169
	.byte	W09
	.byte	GsM2
	.byte	PATT , 156, 169
	.byte	W09
	.byte	GsM2
	.byte	GOTO , 89, 169
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong416_Part1
sSong416_Part1: @ 0x0889A9BE
	.byte	KEYSH , 0
	.byte	VOICE , 126
	.byte	LFOS , 44
	.byte	PAN , 127
	.byte	VOL , 67
	.byte	W24
	.byte	W96
	.byte	W84
	.byte	N12, Gn4, 108
	.byte	W12
	.byte	W96
	.byte	W84
	.byte	Gn4, 112
	.byte	W12
	.byte	W96
	.byte	W84
	.byte	Gn4, 108
	.byte	W12
	.byte	W96
	.byte	W84
	.byte	Gn4, 112
	.byte	W12
	.byte	GOTO , 201, 169
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong416_Part2
sSong416_Part2: @ 0x0889A9E4
	.byte	KEYSH , 0
	.byte	VOICE , 38
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	PAN , 64
	.byte	VOL , 78
	.byte	W24
	.byte	BEND , 62
	.byte	N08, Fn1, 112
	.byte	W03
	.byte	BEND , 64
	.byte	W09
	.byte	N02, Ds1
	.byte	W06
	.byte	BEND , 50
	.byte	N08, Cn2
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	MOD , 11
	.byte	W06
	.byte	N02, Ds1
	.byte	W06
	.byte	N08, Fn1
	.byte	W12
	.byte	MOD , 2
	.byte	N02, Ds1
	.byte	W06
	.byte	N08, Fn1
	.byte	W12
	.byte	N02, Ds1
	.byte	W06
	.byte	BEND , 43
	.byte	N08, Fn1
	.byte	W03
	.byte	BEND , 78
	.byte	W03
	.byte	64
	.byte	W06
	.byte	N03, Cn1
	.byte	W06
	.byte	N06, Fn0
	.byte	W06
	.byte	BEND , 62
	.byte	N08, Fn1
	.byte	W03
	.byte	BEND , 64
	.byte	W09
	.byte	N02, Ds1
	.byte	W06
	.byte	BEND , 82
	.byte	N08, Cn2
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	MOD , 11
	.byte	W06
	.byte	N02, Ds1
	.byte	W06
	.byte	N08, Fn1
	.byte	W12
	.byte	MOD , 2
	.byte	N02, Ds1
	.byte	W06
	.byte	N08, Fn1
	.byte	W12
	.byte	N02, Ds1
	.byte	W06
	.byte	BEND , 88
	.byte	N08, Fn1
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N03, Cn1
	.byte	W06
	.byte	N06, Fn0
	.byte	W06
	.byte	BEND , 62
	.byte	N08, Fn1
	.byte	W03
	.byte	BEND , 64
	.byte	W09
	.byte	N02, Ds1
	.byte	W06
	.byte	BEND , 50
	.byte	N08, Cn1
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	MOD , 11
	.byte	W06
	.byte	N02, Ds1
	.byte	W06
	.byte	N08, Fn1
	.byte	W12
	.byte	MOD , 2
	.byte	N02, Ds1
	.byte	W06
	.byte	N08, Fn1
	.byte	W12
	.byte	N02, Ds1
	.byte	W06
	.byte	BEND , 43
	.byte	N08, Fn1
	.byte	W03
	.byte	BEND , 78
	.byte	W03
	.byte	64
	.byte	W06
	.byte	N03, Cn1
	.byte	W06
	.byte	N06, Fn0
	.byte	W06
	.byte	BEND , 64
	.byte	N06, Ds1
	.byte	W06
	.byte	Fn1
	.byte	W12
	.byte	Ds1
	.byte	W06
	.byte	Fn1
	.byte	W12
	.byte	Ds1
	.byte	W06
	.byte	Fn1
	.byte	W12
	.byte	Ds1
	.byte	W06
	.byte	Fn1
	.byte	W06
	.byte	Ds1
	.byte	W06
	.byte	Fn1
	.byte	W12
	.byte	N12, Gs1
	.byte	W03
	.byte	BEND , 62
	.byte	W02
	.byte	42
	.byte	W03
	.byte	20
	.byte	W04
	.byte	62
	.byte	N08, Fs1
	.byte	W03
	.byte	BEND , 64
	.byte	W09
	.byte	N02, En1
	.byte	W06
	.byte	BEND , 50
	.byte	N08, Cs2
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	MOD , 11
	.byte	W06
	.byte	N02, En1
	.byte	W06
	.byte	N08, Fs1
	.byte	W12
	.byte	MOD , 2
	.byte	N02, En1
	.byte	W06
	.byte	N08, Fs1
	.byte	W12
	.byte	N02, En1
	.byte	W06
	.byte	BEND , 43
	.byte	N08, Fs1
	.byte	W03
	.byte	BEND , 78
	.byte	W03
	.byte	64
	.byte	W06
	.byte	N03, Cs1
	.byte	W06
	.byte	N06, Fs0
	.byte	W06
	.byte	BEND , 62
	.byte	N08, Fs1
	.byte	W03
	.byte	BEND , 64
	.byte	W09
	.byte	N02, En1
	.byte	W06
	.byte	BEND , 82
	.byte	N08, Cs2
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	MOD , 11
	.byte	W06
	.byte	N02, En1
	.byte	W06
	.byte	N08, Fs1
	.byte	W12
	.byte	MOD , 2
	.byte	N02, En1
	.byte	W06
	.byte	N08, Fs1
	.byte	W12
	.byte	N02, En1
	.byte	W06
	.byte	BEND , 88
	.byte	N08, Fs1
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N03, Cs1
	.byte	W06
	.byte	N06, Fs0
	.byte	W06
	.byte	BEND , 62
	.byte	N08, Fs1
	.byte	W03
	.byte	BEND , 64
	.byte	W09
	.byte	N02, En1
	.byte	W06
	.byte	BEND , 50
	.byte	N08, Cs1
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	MOD , 11
	.byte	W06
	.byte	N02, En1
	.byte	W06
	.byte	N08, Fs1
	.byte	W12
	.byte	MOD , 2
	.byte	N02, En1
	.byte	W06
	.byte	N08, Fs1
	.byte	W12
	.byte	N02, En1
	.byte	W06
	.byte	BEND , 43
	.byte	N08, Fs1
	.byte	W03
	.byte	BEND , 78
	.byte	W03
	.byte	64
	.byte	W06
	.byte	N03, Cs1
	.byte	W06
	.byte	N06, Fs0
	.byte	W06
	.byte	BEND , 64
	.byte	N06, En1
	.byte	W06
	.byte	Fs1
	.byte	W12
	.byte	En1
	.byte	W06
	.byte	Fs1
	.byte	W12
	.byte	En1
	.byte	W06
	.byte	Fs1
	.byte	W12
	.byte	En1
	.byte	W06
	.byte	Fs1
	.byte	W06
	.byte	En1
	.byte	W06
	.byte	Fs1
	.byte	W12
	.byte	N12, An1
	.byte	W03
	.byte	BEND , 62
	.byte	W02
	.byte	42
	.byte	W03
	.byte	20
	.byte	W04
	.byte	GOTO , 241, 169
	.byte	W09
	.byte	8
	.byte	BEND , 64
	.byte	FINE
	.globl sSong416_Part3
sSong416_Part3: @ 0x0889AB81
	.byte	KEYSH , 0
	.byte	VOICE , 56
	.byte	LFOS , 70
	.byte	VOL , 68
	.byte	PAN , 34
	.byte	W18
	.byte	BENDR , 12
	.byte	W06
	.byte	VOL , 68
	.byte	BEND , 64
	.byte	N36, Gs2, 112
	.byte	W18
	.byte	BEND , 46
	.byte	W02
	.byte	24
	.byte	W04
	.byte	MOD , 16
	.byte	BEND , 0
	.byte	W12
	.byte	MOD , 0
	.byte	BEND , 64
	.byte	W06
	.byte	N09, Cn2
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Ds2
	.byte	W12
	.byte	N03, En2
	.byte	W06
	.byte	En2, 72
	.byte	W06
	.byte	N06, Fn2, 112
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	BEND , 0
	.byte	N36, Gs2
	.byte	W24
	.byte	MOD , 16
	.byte	BEND , 64
	.byte	W12
	.byte	MOD , 0
	.byte	W06
	.byte	N09, Cn2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, Ds2
	.byte	W12
	.byte	N03, Fn2
	.byte	W06
	.byte	En2, 92
	.byte	W06
	.byte	N06, Fn2, 112
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	BEND , 64
	.byte	N06, Cn2
	.byte	W06
	.byte	N03, Cn2, 64
	.byte	W06
	.byte	Cn2, 80
	.byte	W06
	.byte	Cn2, 64
	.byte	W06
	.byte	BEND , 48
	.byte	N18, Gs2, 112
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	MOD , 16
	.byte	W06
	.byte	0
	.byte	W06
	.byte	N03, Fn2
	.byte	W06
	.byte	En2
	.byte	W06
	.byte	Fn2
	.byte	W06
	.byte	N06, Ds2
	.byte	W12
	.byte	N03, En2
	.byte	W06
	.byte	En2, 72
	.byte	W06
	.byte	N06, Fn2, 112
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	BEND , 64
	.byte	N06
	.byte	W06
	.byte	Gs2
	.byte	W12
	.byte	Gn2
	.byte	W06
	.byte	Gs2
	.byte	W12
	.byte	Gn2
	.byte	W06
	.byte	Gs2
	.byte	W12
	.byte	Gn2
	.byte	W06
	.byte	Gs2
	.byte	W12
	.byte	VOL , 65
	.byte	N06, Gn2
	.byte	W02
	.byte	VOL , 58
	.byte	W03
	.byte	51
	.byte	W01
	.byte	N06, Gs2
	.byte	W02
	.byte	VOL , 47
	.byte	W04
	.byte	40
	.byte	N12, Fn2
	.byte	W02
	.byte	VOL , 25
	.byte	W03
	.byte	1
	.byte	W04
	.byte	BEND , 2
	.byte	W03
	.byte	VOL , 68
	.byte	BEND , 64
	.byte	N36, An2
	.byte	W18
	.byte	BEND , 46
	.byte	W02
	.byte	24
	.byte	W04
	.byte	MOD , 16
	.byte	BEND , 0
	.byte	W12
	.byte	MOD , 0
	.byte	BEND , 64
	.byte	W06
	.byte	N09, Cs2
	.byte	W06
	.byte	BEND , 64
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, En2
	.byte	W12
	.byte	VOL , 68
	.byte	N03, Fn2
	.byte	W06
	.byte	Fn2, 72
	.byte	W06
	.byte	N06, Fs2, 112
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	BEND , 0
	.byte	N36, An2
	.byte	W24
	.byte	MOD , 16
	.byte	BEND , 64
	.byte	W12
	.byte	MOD , 0
	.byte	W06
	.byte	N09, Cs2
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N06, En2
	.byte	W12
	.byte	N03, Fs2
	.byte	W06
	.byte	Fn2, 92
	.byte	W06
	.byte	N06, Fs2, 112
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	BEND , 64
	.byte	N06, Cs2
	.byte	W06
	.byte	N03, Cs2, 64
	.byte	W06
	.byte	Cs2, 80
	.byte	W06
	.byte	Cs2, 64
	.byte	W06
	.byte	BEND , 48
	.byte	N18, An2, 112
	.byte	W03
	.byte	BEND , 64
	.byte	W03
	.byte	MOD , 16
	.byte	W06
	.byte	0
	.byte	W06
	.byte	N03, Fs2
	.byte	W06
	.byte	Fn2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N06, En2
	.byte	W12
	.byte	N03, Fn2
	.byte	W06
	.byte	Fn2, 72
	.byte	W06
	.byte	N06, Fs2, 112
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	BEND , 64
	.byte	N06
	.byte	W06
	.byte	An2
	.byte	W12
	.byte	Gs2
	.byte	W06
	.byte	An2
	.byte	W12
	.byte	Gs2
	.byte	W06
	.byte	An2
	.byte	W12
	.byte	Gs2
	.byte	W06
	.byte	An2
	.byte	W12
	.byte	VOL , 65
	.byte	N06, Gs2
	.byte	W02
	.byte	VOL , 58
	.byte	W03
	.byte	51
	.byte	W01
	.byte	N06, An2
	.byte	W02
	.byte	VOL , 47
	.byte	W04
	.byte	40
	.byte	N12, Fs2
	.byte	W02
	.byte	VOL , 25
	.byte	W03
	.byte	1
	.byte	W04
	.byte	BEND , 2
	.byte	W03
	.byte	GOTO , 143, 171
	.byte	W09
	.byte	8
	.byte	FINE
	.globl sSong416_Part4
sSong416_Part4: @ 0x0889ACF6
	.byte	KEYSH , 0
	.byte	VOICE , 83
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	PAN , 2
	.byte	VOL , 53
	.byte	BEND , 64
	.byte	W18
	.byte	BENDR , 12
	.byte	W06
	.byte	BEND , 64
	.byte	N03, Fn3, 112
	.byte	W06
	.byte	Fn3, 52
	.byte	W06
	.byte	Ds3, 96
	.byte	W06
	.byte	Fn3, 40
	.byte	W06
	.byte	Fn3, 112
	.byte	W12
	.byte	Fn3, 88
	.byte	W06
	.byte	Fn3, 40
	.byte	W06
	.byte	Fn3, 112
	.byte	W06
	.byte	Fn3, 52
	.byte	W06
	.byte	Ds3, 96
	.byte	W06
	.byte	Fn3, 44
	.byte	W06
	.byte	Fn3, 112
	.byte	W06
	.byte	Fn3, 52
	.byte	W06
	.byte	Fn3, 76
	.byte	W06
	.byte	Fn3, 44
	.byte	W06
	.byte	N04, Fn3, 112
	.byte	W04
	.byte	N01, Fn3, 84
	.byte	W04
	.byte	N01
	.byte	W04
	.byte	N03, Ds3, 112
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	Fn3, 88
	.byte	W06
	.byte	Fn3, 40
	.byte	W06
	.byte	Fn3, 112
	.byte	W06
	.byte	Fn3, 52
	.byte	W06
	.byte	Ds3, 96
	.byte	W06
	.byte	Fn3, 44
	.byte	W06
	.byte	Fn3, 112
	.byte	W06
	.byte	Fn3, 56
	.byte	W06
	.byte	Ds3, 100
	.byte	W06
	.byte	Fn3, 44
	.byte	W06
	.byte	Fn3, 112
	.byte	W06
	.byte	Fn3, 52
	.byte	W06
	.byte	Ds3, 96
	.byte	W06
	.byte	Fn3, 40
	.byte	W06
	.byte	Fn3, 112
	.byte	W12
	.byte	Fn3, 88
	.byte	W06
	.byte	Fn3, 40
	.byte	W06
	.byte	Fn3, 112
	.byte	W06
	.byte	Fn3, 52
	.byte	W06
	.byte	Ds3, 96
	.byte	W06
	.byte	Fn3, 44
	.byte	W06
	.byte	Fn3, 112
	.byte	W06
	.byte	Fn3, 52
	.byte	W06
	.byte	Fn3, 76
	.byte	W06
	.byte	Fn3, 44
	.byte	W06
	.byte	N96, Fn5, 92
	.byte	W03
	.byte	BEND , 62
	.byte	W03
	.byte	60
	.byte	W09
	.byte	59
	.byte	W06
	.byte	57
	.byte	W09
	.byte	56
	.byte	W15
	.byte	52
	.byte	W09
	.byte	51
	.byte	W09
	.byte	48
	.byte	W06
	.byte	48
	.byte	W03
	.byte	40
	.byte	W06
	.byte	38
	.byte	W06
	.byte	33
	.byte	W06
	.byte	25
	.byte	W03
	.byte	14
	.byte	W03
	.byte	64
	.byte	N03, Fs3, 112
	.byte	W06
	.byte	Fs3, 52
	.byte	W06
	.byte	En3, 96
	.byte	W06
	.byte	Fs3, 40
	.byte	W06
	.byte	Fs3, 112
	.byte	W12
	.byte	Fs3, 88
	.byte	W06
	.byte	Fs3, 40
	.byte	W06
	.byte	Fs3, 112
	.byte	W06
	.byte	Fs3, 52
	.byte	W06
	.byte	En3, 96
	.byte	W06
	.byte	Fs3, 44
	.byte	W06
	.byte	Fs3, 112
	.byte	W06
	.byte	Fs3, 52
	.byte	W06
	.byte	Fs3, 76
	.byte	W06
	.byte	Fs3, 44
	.byte	W06
	.byte	N04, Fs3, 112
	.byte	W04
	.byte	N01, Fs3, 84
	.byte	W04
	.byte	N01
	.byte	W04
	.byte	N03, En3, 112
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	Fs3, 88
	.byte	W06
	.byte	Fs3, 40
	.byte	W06
	.byte	Fs3, 112
	.byte	W06
	.byte	Fs3, 52
	.byte	W06
	.byte	En3, 96
	.byte	W06
	.byte	Fs3, 44
	.byte	W06
	.byte	Fs3, 112
	.byte	W06
	.byte	Fs3, 56
	.byte	W06
	.byte	En3, 100
	.byte	W06
	.byte	Fs3, 44
	.byte	W06
	.byte	Fs3, 112
	.byte	W06
	.byte	Fs3, 52
	.byte	W06
	.byte	En3, 96
	.byte	W06
	.byte	Fs3, 40
	.byte	W06
	.byte	Fs3, 112
	.byte	W12
	.byte	Fs3, 88
	.byte	W06
	.byte	Fs3, 40
	.byte	W06
	.byte	Fs3, 112
	.byte	W06
	.byte	Fs3, 52
	.byte	W06
	.byte	En3, 96
	.byte	W06
	.byte	Fs3, 44
	.byte	W06
	.byte	Fs3, 112
	.byte	W06
	.byte	Fs3, 52
	.byte	W06
	.byte	Fs3, 76
	.byte	W06
	.byte	Fs3, 44
	.byte	W06
	.byte	N96, Fs5, 92
	.byte	W03
	.byte	BEND , 62
	.byte	W03
	.byte	60
	.byte	W09
	.byte	59
	.byte	W06
	.byte	57
	.byte	W09
	.byte	56
	.byte	W15
	.byte	52
	.byte	W09
	.byte	51
	.byte	W09
	.byte	48
	.byte	W06
	.byte	48
	.byte	W03
	.byte	40
	.byte	W06
	.byte	38
	.byte	W06
	.byte	33
	.byte	W06
	.byte	25
	.byte	W03
	.byte	14
	.byte	W03
	.byte	GOTO , 11, 173
	.byte	W09
	.byte	8
	.byte	BEND , 64
	.byte	FINE
	.globl sSong416_Part5
sSong416_Part5: @ 0x0889AE6E
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	PAN , 127
	.byte	VOL , 37
	.byte	BENDR , 12
	.byte	BEND , 66
	.byte	W24
	.byte	BEND , 66
	.byte	N36, Fn3, 112
	.byte	W18
	.byte	BEND , 46
	.byte	W02
	.byte	24
	.byte	W04
	.byte	MOD , 11
	.byte	BEND , 1
	.byte	W12
	.byte	65
	.byte	W06
	.byte	N09, Gs2
	.byte	W06
	.byte	MOD , 2
	.byte	BEND , 66
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, As2
	.byte	W12
	.byte	N03, Bn2
	.byte	W06
	.byte	Bn2, 72
	.byte	W06
	.byte	N06, Cn3, 112
	.byte	W06
	.byte	Ds3
	.byte	W06
	.byte	BEND , 0
	.byte	N36, Fn3
	.byte	W24
	.byte	BEND , 66
	.byte	W18
	.byte	N09, Gs2
	.byte	W06
	.byte	BEND , 65
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, As2
	.byte	W12
	.byte	N03, Cn3
	.byte	W06
	.byte	Bn2, 92
	.byte	W06
	.byte	N06, Cn3, 112
	.byte	W06
	.byte	Ds3
	.byte	W06
	.byte	BEND , 66
	.byte	N06, Fn2
	.byte	W06
	.byte	N03, Fn2, 64
	.byte	W06
	.byte	Fn2, 92
	.byte	W06
	.byte	Fn2, 64
	.byte	W06
	.byte	MOD , 11
	.byte	BEND , 50
	.byte	N18, Fn3, 112
	.byte	W03
	.byte	BEND , 66
	.byte	W15
	.byte	N03, Cn3
	.byte	W06
	.byte	MOD , 2
	.byte	N03, Bn2
	.byte	W06
	.byte	Cn3
	.byte	W06
	.byte	N06, As2
	.byte	W12
	.byte	N03, Bn2
	.byte	W06
	.byte	Bn2, 72
	.byte	W06
	.byte	N06, Cn3, 112
	.byte	W06
	.byte	Ds3
	.byte	W06
	.byte	BEND , 66
	.byte	N06
	.byte	W06
	.byte	Fn3
	.byte	W12
	.byte	Ds3
	.byte	W06
	.byte	Fn3
	.byte	W12
	.byte	Ds3
	.byte	W06
	.byte	Fn3
	.byte	W12
	.byte	Ds3
	.byte	W06
	.byte	Fn3
	.byte	W12
	.byte	Ds3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	N12, Gs2
	.byte	W06
	.byte	BEND , 0
	.byte	W06
	.byte	66
	.byte	N36, Fs3
	.byte	W18
	.byte	BEND , 46
	.byte	W02
	.byte	24
	.byte	W04
	.byte	MOD , 11
	.byte	BEND , 1
	.byte	W12
	.byte	65
	.byte	W06
	.byte	N09, An2
	.byte	W06
	.byte	MOD , 2
	.byte	BEND , 66
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Bn2
	.byte	W12
	.byte	N03, Cn3
	.byte	W06
	.byte	Cn3, 72
	.byte	W06
	.byte	N06, Cs3, 112
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	BEND , 0
	.byte	N36, Fs3
	.byte	W24
	.byte	BEND , 66
	.byte	W18
	.byte	N09, An2
	.byte	W06
	.byte	BEND , 65
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Bn2
	.byte	W12
	.byte	N03, Cs3
	.byte	W06
	.byte	Cn3, 92
	.byte	W06
	.byte	N06, Cs3, 112
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	BEND , 66
	.byte	N06, Fs2
	.byte	W06
	.byte	N03, Fs2, 64
	.byte	W06
	.byte	Fs2, 92
	.byte	W06
	.byte	Fs2, 64
	.byte	W06
	.byte	MOD , 11
	.byte	BEND , 50
	.byte	N18, Fs3, 112
	.byte	W03
	.byte	BEND , 66
	.byte	W15
	.byte	N03, Cs3
	.byte	W06
	.byte	MOD , 2
	.byte	N03, Cn3
	.byte	W06
	.byte	Cs3
	.byte	W06
	.byte	N06, Bn2
	.byte	W12
	.byte	N03, Cn3
	.byte	W06
	.byte	Cn3, 72
	.byte	W06
	.byte	N06, Cs3, 112
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	BEND , 66
	.byte	N06
	.byte	W06
	.byte	Fs3
	.byte	W12
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W12
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W12
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W12
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	N12, An2
	.byte	W06
	.byte	BEND , 0
	.byte	W06
	.byte	GOTO , 130, 174
	.byte	W09
	.byte	8
	.byte	FINE
	.globl sSong416_Part6
sSong416_Part6: @ 0x0889AFB8
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 76
	.byte	N04, En1, 112
	.byte	N04, Fs2
	.byte	W04
	.byte	En1, 84
	.byte	N04, Fs2, 52
	.byte	W04
	.byte	En1, 84
	.byte	N04, Fs2, 52
	.byte	W04
	.byte	N06, Dn1, 112
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2, 44
	.byte	W06
	.byte	N06, Cn1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Fs2, 48
	.byte	W06
	.byte	Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Fs2, 48
	.byte	W06
	.byte	Cn1, 112
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2, 44
	.byte	W06
	.byte	Fs2, 112
	.byte	W06
	.byte	Cn1
	.byte	N06, Fs2, 48
	.byte	W06
	.byte	Cn1, 84
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Cn1
	.byte	N06, Fs2, 48
	.byte	W06
	.byte	Cn1, 72
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	PEND
	.byte	N06, Cn1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Fs2, 48
	.byte	W06
	.byte	Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Fs2, 48
	.byte	W06
	.byte	Cn1, 112
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2, 44
	.byte	W06
	.byte	Fs2, 112
	.byte	W06
	.byte	Cn1
	.byte	N06, Fs2, 48
	.byte	W06
	.byte	Cn1, 112
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Fs2, 48
	.byte	W06
	.byte	Cn1, 84
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	PEND
	.byte	N06, Cn1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Fs2, 48
	.byte	W06
	.byte	Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Fs2, 48
	.byte	W06
	.byte	Cn1, 112
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2, 44
	.byte	W06
	.byte	Fs2, 112
	.byte	W06
	.byte	Cn1
	.byte	N06, Fs2, 48
	.byte	W06
	.byte	Cn1, 84
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	En1, 112
	.byte	N06, Fs2
	.byte	W06
	.byte	Cn1
	.byte	N06, Fs2, 48
	.byte	W06
	.byte	Dn1, 120
	.byte	N06, Fs2, 76
	.byte	W06
	.byte	Fs2, 44
	.byte	W06
	.byte	PEND
	.byte	N06, Cn1, 112
	.byte	W06
	.byte	Dn1
	.byte	N18, An2
	.byte	W12
	.byte	N06, Cn1
	.byte	W06
	.byte	Dn1
	.byte	N18, An2, 80
	.byte	W12
	.byte	N06, Cn1, 112
	.byte	W06
	.byte	Dn1
	.byte	N18, An2
	.byte	W12
	.byte	N06, Cn1
	.byte	W06
	.byte	Dn1
	.byte	N12, An2, 80
	.byte	W06
	.byte	N06, Cn1
	.byte	W06
	.byte	Fs1, 112
	.byte	N24, An2
	.byte	W06
	.byte	N06, Fs1, 80
	.byte	W06
	.byte	N12, As1, 112
	.byte	W12
	.byte	PEND
	.byte	PATT , 221, 175
	.byte	W09
	.byte	GsM2
	.byte	PATT , 37, 176
	.byte	W09
	.byte	GsM2
	.byte	PATT , 107, 176
	.byte	W09
	.byte	GsM2
	.byte	PATT , 179, 176
	.byte	W09
	.byte	GsM2
	.byte	GOTO , 221, 175
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong416_Part7
sSong416_Part7: @ 0x0889B0FE
	.byte	KEYSH , 0
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	PAN , 64
	.byte	VOL , 70
	.byte	W24
	.byte	BEND , 64
	.byte	N36, Fn2, 112
	.byte	W18
	.byte	BEND , 46
	.byte	W02
	.byte	24
	.byte	W04
	.byte	MOD , 11
	.byte	BEND , 1
	.byte	W12
	.byte	64
	.byte	W06
	.byte	N09, Gs1
	.byte	W06
	.byte	MOD , 2
	.byte	BEND , 64
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, As1
	.byte	W12
	.byte	N03, Bn1
	.byte	W06
	.byte	Bn1, 72
	.byte	W06
	.byte	N06, Cn2, 112
	.byte	W06
	.byte	Ds2
	.byte	W06
	.byte	BEND , 0
	.byte	N36, Fn2
	.byte	W24
	.byte	MOD , 11
	.byte	BEND , 64
	.byte	W18
	.byte	N09, Gs1
	.byte	W06
	.byte	MOD , 2
	.byte	BEND , 64
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, As1
	.byte	W12
	.byte	N03, Cn2
	.byte	W06
	.byte	Bn1, 92
	.byte	W06
	.byte	N06, Cn2, 112
	.byte	W06
	.byte	Ds2
	.byte	W06
	.byte	BEND , 64
	.byte	N06, Fn1
	.byte	W06
	.byte	N03, Fn1, 64
	.byte	W06
	.byte	Fn1, 92
	.byte	W06
	.byte	Fn1, 64
	.byte	W06
	.byte	MOD , 11
	.byte	BEND , 50
	.byte	N18, Fn2, 112
	.byte	W03
	.byte	BEND , 64
	.byte	W15
	.byte	N03, Cn2
	.byte	W06
	.byte	MOD , 2
	.byte	N03, Bn1
	.byte	W06
	.byte	Cn2
	.byte	W06
	.byte	N06, As1
	.byte	W12
	.byte	N03, Bn1
	.byte	W06
	.byte	Bn1, 72
	.byte	W06
	.byte	N06, Cn2, 112
	.byte	W06
	.byte	Ds2
	.byte	W06
	.byte	BEND , 64
	.byte	N06
	.byte	W06
	.byte	Fn2
	.byte	W12
	.byte	Ds2
	.byte	W06
	.byte	Fn2
	.byte	W12
	.byte	Ds2
	.byte	W06
	.byte	Fn2
	.byte	W12
	.byte	Ds2
	.byte	W06
	.byte	Fn2
	.byte	W12
	.byte	Ds2
	.byte	W06
	.byte	Fn2
	.byte	W06
	.byte	N12, Gs1
	.byte	W06
	.byte	BEND , 0
	.byte	W06
	.byte	64
	.byte	N36, Fs2
	.byte	W18
	.byte	BEND , 46
	.byte	W02
	.byte	24
	.byte	W04
	.byte	MOD , 11
	.byte	BEND , 1
	.byte	W12
	.byte	64
	.byte	W06
	.byte	N09, An1
	.byte	W06
	.byte	MOD , 2
	.byte	BEND , 64
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Bn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W06
	.byte	Cn2, 72
	.byte	W06
	.byte	N06, Cs2, 112
	.byte	W06
	.byte	En2
	.byte	W06
	.byte	BEND , 0
	.byte	N36, Fs2
	.byte	W24
	.byte	MOD , 11
	.byte	BEND , 64
	.byte	W18
	.byte	N09, An1
	.byte	W06
	.byte	MOD , 2
	.byte	BEND , 64
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Bn1
	.byte	W12
	.byte	N03, Cs2
	.byte	W06
	.byte	Cn2, 92
	.byte	W06
	.byte	N06, Cs2, 112
	.byte	W06
	.byte	En2
	.byte	W06
	.byte	BEND , 64
	.byte	N06, Fs1
	.byte	W06
	.byte	N03, Fs1, 64
	.byte	W06
	.byte	Fs1, 92
	.byte	W06
	.byte	Fs1, 64
	.byte	W06
	.byte	MOD , 11
	.byte	BEND , 50
	.byte	N18, Fs2, 112
	.byte	W03
	.byte	BEND , 64
	.byte	W15
	.byte	N03, Cs2
	.byte	W06
	.byte	MOD , 2
	.byte	N03, Cn2
	.byte	W06
	.byte	Cs2
	.byte	W06
	.byte	N06, Bn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W06
	.byte	Cn2, 72
	.byte	W06
	.byte	N06, Cs2, 112
	.byte	W06
	.byte	En2
	.byte	W06
	.byte	BEND , 64
	.byte	N06
	.byte	W06
	.byte	Fs2
	.byte	W12
	.byte	En2
	.byte	W06
	.byte	Fs2
	.byte	W12
	.byte	En2
	.byte	W06
	.byte	Fs2
	.byte	W12
	.byte	En2
	.byte	W06
	.byte	Fs2
	.byte	W12
	.byte	En2
	.byte	W06
	.byte	Fs2
	.byte	W06
	.byte	N12, An1
	.byte	W06
	.byte	BEND , 0
	.byte	W06
	.byte	GOTO , 16, 177
	.byte	W09
	.byte	8
	.byte	FINE
	.incbin "baserom_jp.gba", 0x89B24E, 0x2
	.globl sSongHeader_416
sSongHeader_416: @ 0x0889B250
	.byte 0x08, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_0860E594  @ tone
	.4byte 0x0889A94C, 0x0889A9BE, 0x0889A9E4, 0x0889AB81, 0x0889ACF6, 0x0889AE6E, 0x0889AFB8, 0x0889B0FE  @ parts
