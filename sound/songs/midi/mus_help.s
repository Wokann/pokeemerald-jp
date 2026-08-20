.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong410_Part0
sSong410_Part0: @ 0x0889313C
	.byte	KEYSH , 0
	.byte	TEMPO , 68
	.byte	VOICE , 60
	.byte	PAN , 64
	.byte	VOL , 49
	.byte	N03, Dn5, 112
	.byte	W03
	.byte	Ds5
	.byte	W03
	.byte	N06, Gn5
	.byte	W06
	.byte	Fs5
	.byte	W06
	.byte	Fn5
	.byte	W06
	.byte	Ds5
	.byte	W12
	.byte	Dn5
	.byte	W12
	.byte	Cn5
	.byte	W12
	.byte	Bn4
	.byte	W18
	.byte	TEMPO , 56
	.byte	N24, As4
	.byte	W15
	.byte	TEMPO , 78
	.byte	W09
	.byte	W12
	.byte	N09, Gn4, 112
	.byte	W09
	.byte	N06, Gn4, 36
	.byte	W09
	.byte	N03, Gn4, 112
	.byte	W03
	.byte	N06, Gn4, 36
	.byte	W24
	.byte	W03
	.byte	N09, Gs4, 112
	.byte	W09
	.byte	N06, Gs4, 36
	.byte	W09
	.byte	N03, Gs4, 112
	.byte	W03
	.byte	N06, Gs4, 36
	.byte	W15
	.byte	PEND
	.byte	W12
	.byte	N09, An4, 112
	.byte	W09
	.byte	N06, An4, 36
	.byte	W09
	.byte	N03, An4, 112
	.byte	W03
	.byte	N06, An4, 36
	.byte	W24
	.byte	W03
	.byte	N09, Gs4, 112
	.byte	W09
	.byte	N06, Gs4, 36
	.byte	W09
	.byte	N03, Gs4, 112
	.byte	W03
	.byte	N06, Gs4, 36
	.byte	W15
	.byte	PATT , 99, 49
	.byte	W09
	.byte	GsM2
	.byte	W12
	.byte	N09, An4, 112
	.byte	W09
	.byte	N06, An4, 36
	.byte	W09
	.byte	N03, An4, 112
	.byte	W03
	.byte	N06, An4, 36
	.byte	W24
	.byte	W03
	.byte	N03, As4, 124
	.byte	W06
	.byte	As4, 112
	.byte	W06
	.byte	As4, 104
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	As4, 116
	.byte	W06
	.byte	GOTO , 99, 49
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong410_Part1
sSong410_Part1: @ 0x088931D4
	.byte	KEYSH , 0
	.byte	VOICE , 38
	.byte	PAN , 71
	.byte	VOL , 78
	.byte	W06
	.byte	W66
	.byte	N06, Gn2, 112
	.byte	W06
	.byte	N24, Gn1
	.byte	W24
	.byte	N12, Cn1, 112
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	Cn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	Cn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	PEND
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	PATT , 229, 49
	.byte	W09
	.byte	GsM2
	.byte	N12, Cn1, 112
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Gn1
	.byte	W12
	.byte	N03, Gn2, 124
	.byte	W12
	.byte	Gn1, 104
	.byte	W06
	.byte	Bn1, 112
	.byte	W06
	.byte	Fn2, 104
	.byte	W06
	.byte	Gn2, 112
	.byte	W06
	.byte	GOTO , 229, 49
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong410_Part2
sSong410_Part2: @ 0x08893246
	.byte	KEYSH , 0
	.byte	VOICE , 73
	.byte	PAN , 18
	.byte	VOL , 39
	.byte	W06
	.byte	N06, Bn4, 112
	.byte	W06
	.byte	As4
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	Gn4
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	Ds4
	.byte	W12
	.byte	Dn4
	.byte	W18
	.byte	N24, Fn4
	.byte	W24
	.byte	W12
	.byte	N09, Cn4, 112
	.byte	W18
	.byte	N03
	.byte	W30
	.byte	N09, Cs4
	.byte	W18
	.byte	N03
	.byte	W18
	.byte	PEND
	.byte	W12
	.byte	N09, Dn4
	.byte	W18
	.byte	N03
	.byte	W30
	.byte	N09, Cs4
	.byte	W18
	.byte	N03
	.byte	W18
	.byte	PATT , 98, 50
	.byte	W09
	.byte	GsM2
	.byte	W12
	.byte	N09, Dn4, 112
	.byte	W18
	.byte	N03
	.byte	W30
	.byte	Fn4, 124
	.byte	W06
	.byte	Fn4, 112
	.byte	W06
	.byte	Fn4, 104
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	Fn4, 116
	.byte	W06
	.byte	GOTO , 98, 50
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong410_Part3
sSong410_Part3: @ 0x0889329A
	.byte	KEYSH , 0
	.byte	VOICE , 87
	.byte	PAN , 64
	.byte	VOL , 48
	.byte	LFOS , 44
	.byte	XCMD , 8 , 12
	.byte	8 , 22
	.byte	BENDR , 12
	.byte	BEND , 66
	.byte	W06
	.byte	W66
	.byte	N06, Gn2, 112
	.byte	W06
	.byte	N24, Gn1
	.byte	W24
	.byte	N12, Cn1, 112
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	Cn1
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	Cn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	PEND
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	PATT , 182, 50
	.byte	W09
	.byte	GsM2
	.byte	N12, Cn1, 112
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Cn1
	.byte	W12
	.byte	N03, Cn2
	.byte	W12
	.byte	N12, Gn1
	.byte	W12
	.byte	N03, Gn2, 124
	.byte	W12
	.byte	Gn1, 104
	.byte	W06
	.byte	Bn1, 112
	.byte	W06
	.byte	Fn2, 104
	.byte	W06
	.byte	Gn2, 112
	.byte	W06
	.byte	GOTO , 182, 50
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong410_Part4
sSong410_Part4: @ 0x08893317
	.byte	KEYSH , 0
	.byte	VOICE , 82
	.byte	PAN , 127
	.byte	LFOS , 44
	.byte	XCMD , 8 , 12
	.byte	8 , 22
	.byte	BENDR , 12
	.byte	VOL , 50
	.byte	W06
	.byte	W66
	.byte	N06, Bn2, 84
	.byte	W06
	.byte	N24, Gn3, 88
	.byte	W24
	.byte	PAN , 2
	.byte	N03, Gn3, 96
	.byte	W06
	.byte	Ds3, 48
	.byte	W06
	.byte	Cn3
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	PAN , 127
	.byte	N03, Gn3, 96
	.byte	W06
	.byte	Ds3, 48
	.byte	W06
	.byte	Cn3
	.byte	W06
	.byte	Gn2
	.byte	W06
	.byte	PAN , 2
	.byte	N03, Gs3, 96
	.byte	W06
	.byte	En3, 48
	.byte	W06
	.byte	Cs3
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	PAN , 127
	.byte	N03, Gs3, 96
	.byte	W06
	.byte	En3, 48
	.byte	W06
	.byte	Cs3
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	PEND
	.byte	PAN , 2
	.byte	N03, An3, 96
	.byte	W06
	.byte	Fn3, 48
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	PAN , 127
	.byte	N03, An3, 96
	.byte	W06
	.byte	Fn3, 48
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	PAN , 2
	.byte	N03, Gs3, 96
	.byte	W06
	.byte	En3, 48
	.byte	W06
	.byte	Cs3
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	PAN , 127
	.byte	N03, Gs3, 96
	.byte	W06
	.byte	En3, 48
	.byte	W06
	.byte	Cs3
	.byte	W06
	.byte	Gs2
	.byte	W06
	.byte	PATT , 50, 51
	.byte	W09
	.byte	GsM2
	.byte	PAN , 2
	.byte	N03, An3, 96
	.byte	W06
	.byte	Fn3, 48
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	PAN , 127
	.byte	N03, An3, 96
	.byte	W06
	.byte	Fn3, 48
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	PAN , 64
	.byte	N04, As3, 100
	.byte	W08
	.byte	Fn3, 84
	.byte	W08
	.byte	Bn2
	.byte	W08
	.byte	N03, Gn2, 112
	.byte	W06
	.byte	Bn2
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	GOTO , 50, 51
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong410_Part5
sSong410_Part5: @ 0x088933D5
	.byte	KEYSH , 0
	.byte	VOICE , 80
	.byte	LFOS , 44
	.byte	XCMD , 8 , 12
	.byte	8 , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 40
	.byte	W06
	.byte	W66
	.byte	N06, Gn3, 112
	.byte	W06
	.byte	N24, Bn3
	.byte	W24
	.byte	N12, Ds3, 112
	.byte	W18
	.byte	N06
	.byte	W30
	.byte	N12, En3
	.byte	W18
	.byte	N06
	.byte	W30
	.byte	PEND
	.byte	N12, Fn3
	.byte	W18
	.byte	N06
	.byte	W30
	.byte	N12, En3
	.byte	W18
	.byte	N06
	.byte	W30
	.byte	PATT , 239, 51
	.byte	W09
	.byte	GsM2
	.byte	N12, Fn3, 112
	.byte	W18
	.byte	N06
	.byte	W42
	.byte	N03, Bn3, 124
	.byte	W06
	.byte	Bn3, 112
	.byte	W06
	.byte	Bn3, 104
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	Bn3, 116
	.byte	W06
	.byte	GOTO , 239, 51
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.globl sSong410_Part6
sSong410_Part6: @ 0x08893425
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	PAN , 64
	.byte	VOL , 62
	.byte	W06
	.byte	N06, En1, 112
	.byte	W06
	.byte	En1, 80
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En1, 92
	.byte	W12
	.byte	En1, 80
	.byte	W12
	.byte	En1, 88
	.byte	W12
	.byte	En1, 112
	.byte	W12
	.byte	Cn1
	.byte	W06
	.byte	Dn1
	.byte	N24, An2
	.byte	W12
	.byte	N06, En1
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06, Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	Fs1, 96
	.byte	W06
	.byte	Fs1, 68
	.byte	W06
	.byte	Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	Fs1, 96
	.byte	W06
	.byte	Fs1, 68
	.byte	W06
	.byte	Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	N12, As1, 112
	.byte	W12
	.byte	N06, Fs1
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	Fs1, 96
	.byte	W06
	.byte	Fs1, 68
	.byte	W06
	.byte	PEND
	.byte	Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	Fs1, 96
	.byte	W06
	.byte	Fs1, 68
	.byte	W06
	.byte	Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	Fs1, 96
	.byte	W06
	.byte	Fs1, 68
	.byte	W06
	.byte	Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	N12, As1, 112
	.byte	W12
	.byte	N06, Fs1
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	En1, 127
	.byte	W06
	.byte	Fs1, 68
	.byte	W06
	.byte	PATT , 78, 52
	.byte	W09
	.byte	GsM2
	.byte	N06, Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	Fs1, 96
	.byte	W06
	.byte	Fs1, 68
	.byte	W06
	.byte	Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	Fs1, 96
	.byte	W06
	.byte	Fs1, 68
	.byte	W06
	.byte	Fs1, 112
	.byte	W06
	.byte	Fs1, 72
	.byte	W06
	.byte	N12, As1, 96
	.byte	W12
	.byte	N06, Fs1, 112
	.byte	W06
	.byte	Fs1, 108
	.byte	W06
	.byte	N12, As1, 112
	.byte	W12
	.byte	GOTO , 78, 52
	.byte	W09
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8934E5, 0x3
	.globl sSongHeader_410
sSongHeader_410: @ 0x088934E8
	.byte 0x07, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_0860C368  @ tone
	.4byte 0x0889313C, 0x088931D4, 0x08893246, 0x0889329A, 0x08893317, 0x088933D5, 0x08893425  @ parts
