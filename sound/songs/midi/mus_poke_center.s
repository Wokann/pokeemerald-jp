.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong400_Part0
sSong400_Part0: @ 0x08886A94
	.byte	KEYSH , 0
	.byte	TEMPO , 52
	.byte	VOICE , 2
	.byte	PAN , 64
	.byte	VOL , 29
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	N12, An3, 112
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	N24, Dn3
	.byte	W24
	.byte	N12, Fs3
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	N24, Gs3
	.byte	W24
	.byte	N12, Fs3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	N24, Fn3
	.byte	W24
	.byte	Gs3
	.byte	W24
	.byte	N12, An3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	Cs3, 100
	.byte	W12
	.byte	En3, 96
	.byte	W12
	.byte	An2
	.byte	W12
	.byte	Gs2
	.byte	W12
	.byte	GOTO , 159, 106
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong400_Part1
sSong400_Part1: @ 0x08886AE4
	.byte	KEYSH , 0
	.byte	VOICE , 73
	.byte	VOL , 3
	.byte	LFOS , 44
	.byte	MOD , 1
	.byte	PAN , 57
	.byte	N72, En3, 120
	.byte	W03
	.byte	VOL , 8
	.byte	W02
	.byte	9
	.byte	W07
	.byte	10
	.byte	W02
	.byte	10
	.byte	W03
	.byte	11
	.byte	W03
	.byte	14
	.byte	W04
	.byte	15
	.byte	W02
	.byte	16
	.byte	W03
	.byte	17
	.byte	W03
	.byte	19
	.byte	W04
	.byte	21
	.byte	W02
	.byte	22
	.byte	W03
	.byte	23
	.byte	W03
	.byte	26
	.byte	W04
	.byte	28
	.byte	W02
	.byte	34
	.byte	W03
	.byte	41
	.byte	W03
	.byte	44
	.byte	W01
	.byte	52
	.byte	W03
	.byte	60
	.byte	W02
	.byte	62
	.byte	W01
	.byte	73
	.byte	W02
	.byte	70
	.byte	W01
	.byte	80
	.byte	W02
	.byte	76
	.byte	W01
	.byte	86
	.byte	W03
	.byte	78
	.byte	N02, Gs3, 112
	.byte	W02
	.byte	An3
	.byte	W02
	.byte	N08, Gs3
	.byte	W09
	.byte	N06, Fs3
	.byte	W05
	.byte	Gs3
	.byte	W06
	.byte	VOL , 92
	.byte	W32
	.byte	W01
	.byte	N03, Ds4, 72
	.byte	W03
	.byte	N06, En4, 112
	.byte	W12
	.byte	En4, 16
	.byte	W12
	.byte	En4, 108
	.byte	W12
	.byte	N02, Dn4, 112
	.byte	W02
	.byte	En4
	.byte	W02
	.byte	N08, Dn4
	.byte	W09
	.byte	N06, Cs4
	.byte	W05
	.byte	An3
	.byte	W06
	.byte	Bn3
	.byte	W12
	.byte	N12, Gs3, 92
	.byte	W06
	.byte	MOD , 5
	.byte	W06
	.byte	1
	.byte	N12, Gs3, 16
	.byte	W48
	.byte	N06, Fs3, 112
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	W32
	.byte	W01
	.byte	N03, Cn4, 68
	.byte	W03
	.byte	N06, Cs4, 112
	.byte	W12
	.byte	Cs4, 16
	.byte	W12
	.byte	Bn3, 112
	.byte	W12
	.byte	Bn3, 16
	.byte	W12
	.byte	Gs3, 112
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	N24, Cs4
	.byte	W06
	.byte	MOD , 5
	.byte	W18
	.byte	1
	.byte	N06, En3
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	Gs3
	.byte	W09
	.byte	N03, As3, 76
	.byte	W03
	.byte	N06, An3, 112
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	VOL , 92
	.byte	W32
	.byte	W01
	.byte	N03, Ds5, 72
	.byte	W03
	.byte	N06, En5, 112
	.byte	W12
	.byte	En5, 16
	.byte	W12
	.byte	Dn5, 92
	.byte	W12
	.byte	Dn5, 16
	.byte	W12
	.byte	Cs5, 92
	.byte	W12
	.byte	Bn4, 112
	.byte	W12
	.byte	N12, Gs4, 92
	.byte	W12
	.byte	MOD , 1
	.byte	N12, Gs4, 16
	.byte	W48
	.byte	N02, Bn4, 112
	.byte	W02
	.byte	Cs5
	.byte	W02
	.byte	N08, Bn4
	.byte	W09
	.byte	N06, As4
	.byte	W05
	.byte	Bn4
	.byte	W06
	.byte	Gs4
	.byte	W24
	.byte	N06
	.byte	W09
	.byte	N03, Cn5, 68
	.byte	W03
	.byte	N06, Cs5, 112
	.byte	W12
	.byte	Cs5, 16
	.byte	W12
	.byte	Bn4, 112
	.byte	W12
	.byte	Bn4, 16
	.byte	W12
	.byte	Gs4, 112
	.byte	W12
	.byte	N24, An3
	.byte	W12
	.byte	MOD , 5
	.byte	W12
	.byte	N03, Gs3, 64
	.byte	W03
	.byte	An3
	.byte	W03
	.byte	As3
	.byte	W03
	.byte	Bn3
	.byte	W03
	.byte	Cn4
	.byte	W03
	.byte	Cs4
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	Ds4
	.byte	W03
	.byte	MOD , 1
	.byte	N24, En4, 88
	.byte	W12
	.byte	MOD , 5
	.byte	W12
	.byte	N03, Fn4, 64
	.byte	W03
	.byte	Fs4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	Gs4
	.byte	W03
	.byte	An4, 68
	.byte	W03
	.byte	As4, 76
	.byte	W03
	.byte	Bn4, 80
	.byte	W03
	.byte	Cn5, 92
	.byte	W03
	.byte	MOD , 1
	.byte	VOL , 69
	.byte	PAN , 62
	.byte	N48, Cs5, 112
	.byte	W36
	.byte	MOD , 7
	.byte	W12
	.byte	2
	.byte	N36, En5
	.byte	W24
	.byte	MOD , 7
	.byte	W12
	.byte	0
	.byte	N06, Cn5
	.byte	W06
	.byte	Cs5
	.byte	W06
	.byte	N12, Dn5
	.byte	W12
	.byte	En5
	.byte	W12
	.byte	Dn5
	.byte	W12
	.byte	Cs5
	.byte	W12
	.byte	Bn4
	.byte	W18
	.byte	N06, Gs4
	.byte	W06
	.byte	N02, Cs5
	.byte	W02
	.byte	Dn5
	.byte	W02
	.byte	N08, Cs5
	.byte	W09
	.byte	N06, Bn4
	.byte	W05
	.byte	An4
	.byte	W06
	.byte	Bn4
	.byte	W06
	.byte	En4
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	Bn4
	.byte	W06
	.byte	En4
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	Dn5
	.byte	W06
	.byte	An4
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N12, Dn5
	.byte	W12
	.byte	N09, Gs4
	.byte	W09
	.byte	N03, Cn5
	.byte	W03
	.byte	N12, Cs5
	.byte	W12
	.byte	Dn5
	.byte	W12
	.byte	Cs5
	.byte	W12
	.byte	Bn4
	.byte	W12
	.byte	N06, An4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	N02, En5
	.byte	W02
	.byte	Fs5
	.byte	W02
	.byte	N08, En5
	.byte	W09
	.byte	N06, Cs5
	.byte	W05
	.byte	Bn4
	.byte	W06
	.byte	VOL , 69
	.byte	W06
	.byte	N06, En4
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	Bn4
	.byte	W06
	.byte	Cs5
	.byte	W06
	.byte	Dn5
	.byte	W06
	.byte	En5
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	Bn4
	.byte	W06
	.byte	Cs5
	.byte	W06
	.byte	Dn5
	.byte	W06
	.byte	En5
	.byte	W06
	.byte	Fs5
	.byte	W06
	.byte	Gs5
	.byte	W06
	.byte	VOL , 60
	.byte	N06, An5
	.byte	W06
	.byte	Gs5
	.byte	W06
	.byte	Fs5
	.byte	W06
	.byte	En5
	.byte	W06
	.byte	Dn5
	.byte	W06
	.byte	Cs5
	.byte	W06
	.byte	Bn4
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	Fs5
	.byte	W06
	.byte	En5
	.byte	W06
	.byte	Dn5
	.byte	W06
	.byte	Cs5
	.byte	W06
	.byte	Bn4
	.byte	W06
	.byte	Cs5
	.byte	W06
	.byte	Dn5
	.byte	W06
	.byte	Fs5
	.byte	W06
	.byte	VOL , 81
	.byte	N03, Ds5, 96
	.byte	W03
	.byte	N21, En5
	.byte	W09
	.byte	MOD , 6
	.byte	W12
	.byte	1
	.byte	N12, Dn5
	.byte	W12
	.byte	Cs5
	.byte	W12
	.byte	N48, Dn5
	.byte	W24
	.byte	MOD , 7
	.byte	W24
	.byte	1
	.byte	N12, Cs5
	.byte	W12
	.byte	Dn5
	.byte	W12
	.byte	Cs5
	.byte	W12
	.byte	Bn4
	.byte	W12
	.byte	VOL , 23
	.byte	N24, An4
	.byte	W03
	.byte	VOL , 28
	.byte	W03
	.byte	32
	.byte	W03
	.byte	40
	.byte	W03
	.byte	47
	.byte	MOD , 6
	.byte	W03
	.byte	VOL , 57
	.byte	W03
	.byte	69
	.byte	W03
	.byte	77
	.byte	W03
	.byte	MOD , 1
	.byte	N02, Gs4
	.byte	W02
	.byte	An4
	.byte	W02
	.byte	N08, Gs4
	.byte	W09
	.byte	N06, Fs4
	.byte	W05
	.byte	Gs4
	.byte	W06
	.byte	GOTO , 56, 107
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong400_Part2
sSong400_Part2: @ 0x08886D24
	.byte	KEYSH , 0
	.byte	VOICE , 45
	.byte	PAN , 32
	.byte	VOL , 79
	.byte	XCMD , 8 , 12
	.byte	9 , 8
	.byte	LFOS , 44
	.byte	W96
	.byte	N06, An3, 92
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Cs4, 112
	.byte	W12
	.byte	Cs4, 20
	.byte	W60
	.byte	W12
	.byte	Dn4, 112
	.byte	W12
	.byte	Dn4, 16
	.byte	W12
	.byte	Bn3, 112
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	En3
	.byte	W06
	.byte	Bn2
	.byte	W30
	.byte	Gs3, 92
	.byte	W06
	.byte	Bn2
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Gs3, 112
	.byte	W12
	.byte	Gs3, 16
	.byte	W60
	.byte	VOL , 75
	.byte	W12
	.byte	N06, En4, 112
	.byte	W12
	.byte	Fs4
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	An4
	.byte	W12
	.byte	Gs4
	.byte	W06
	.byte	En4
	.byte	W06
	.byte	Fs4
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	VOL , 67
	.byte	N06, An3, 92
	.byte	W06
	.byte	En3, 112
	.byte	W06
	.byte	Gs3, 92
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Cs4, 112
	.byte	W06
	.byte	En4
	.byte	W06
	.byte	An4
	.byte	W12
	.byte	An4, 16
	.byte	W12
	.byte	En5, 100
	.byte	W12
	.byte	En5, 16
	.byte	W12
	.byte	An4, 112
	.byte	W12
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	Gs4, 16
	.byte	W12
	.byte	En4, 112
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	As3
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	Gs3, 92
	.byte	W06
	.byte	Bn2
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Gs3, 112
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Gs4
	.byte	W12
	.byte	Gs4, 16
	.byte	W12
	.byte	Dn5, 112
	.byte	W12
	.byte	Dn5, 16
	.byte	W12
	.byte	Bn4, 112
	.byte	W12
	.byte	An4
	.byte	W12
	.byte	An4, 16
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO , 52, 109
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong400_Part3
sSong400_Part3: @ 0x08886DD9
	.byte	KEYSH , 0
	.byte	VOICE , 48
	.byte	LFOS , 44
	.byte	VOL , 82
	.byte	PAN , 32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte	N06, Cs3, 56
	.byte	W06
	.byte	Bn2
	.byte	W06
	.byte	An2
	.byte	W06
	.byte	Cn3
	.byte	W06
	.byte	N03, Dn3, 48
	.byte	W03
	.byte	N32, Cs3, 56
	.byte	W21
	.byte	VOL , 78
	.byte	W02
	.byte	70
	.byte	W03
	.byte	62
	.byte	W03
	.byte	60
	.byte	W04
	.byte	82
	.byte	N12, En2
	.byte	W12
	.byte	An2
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Dn3
	.byte	W12
	.byte	Cs3
	.byte	W12
	.byte	N36, Dn3
	.byte	W24
	.byte	VOL , 78
	.byte	W02
	.byte	70
	.byte	W03
	.byte	62
	.byte	W03
	.byte	60
	.byte	W04
	.byte	82
	.byte	N12, Bn2
	.byte	W12
	.byte	N02, Gs2
	.byte	W02
	.byte	An2
	.byte	W02
	.byte	N08, Gs2
	.byte	W09
	.byte	N06, Gn2
	.byte	W05
	.byte	Gs2
	.byte	W06
	.byte	N12, Ds2
	.byte	W12
	.byte	En2
	.byte	W12
	.byte	N03, Cn3, 48
	.byte	W03
	.byte	N32, Bn2, 56
	.byte	W21
	.byte	VOL , 78
	.byte	W02
	.byte	70
	.byte	W03
	.byte	62
	.byte	W03
	.byte	60
	.byte	W04
	.byte	82
	.byte	N12, Gs2
	.byte	W12
	.byte	Dn3
	.byte	W12
	.byte	En3, 60
	.byte	W12
	.byte	Fs3, 64
	.byte	W12
	.byte	Gs3, 68
	.byte	W12
	.byte	PAN , 20
	.byte	VOL , 57
	.byte	N06, Dn4, 64
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	VOL , 49
	.byte	N06, Cs4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	En4, 96
	.byte	W06
	.byte	Gs3, 64
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	En4, 96
	.byte	W06
	.byte	Gs3, 64
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	An3, 64
	.byte	W06
	.byte	En4, 96
	.byte	W06
	.byte	An3, 64
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	Fs3, 64
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	Fs3, 64
	.byte	W06
	.byte	Bn3, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Bn3, 96
	.byte	W06
	.byte	Dn3, 64
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Bn3, 96
	.byte	W06
	.byte	Dn3, 64
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	Fn3, 64
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	Fn3, 64
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Bn3, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	An3, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	En4, 96
	.byte	W06
	.byte	Gs3, 64
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	En4, 96
	.byte	W06
	.byte	Gs3, 64
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	An3, 64
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	An3, 64
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	Fs3, 64
	.byte	W06
	.byte	En4, 96
	.byte	W06
	.byte	Fs3, 64
	.byte	W06
	.byte	Fs4, 96
	.byte	W06
	.byte	An3, 64
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Fs4, 96
	.byte	W06
	.byte	An3, 64
	.byte	W06
	.byte	En4, 96
	.byte	W06
	.byte	Dn3, 64
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	Dn3, 64
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	Dn3, 64
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	Fn3, 64
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	Fn3, 64
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	Fn3
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Dn4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Cs4, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Bn3, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	An3, 96
	.byte	W06
	.byte	En3, 64
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	VOL , 81
	.byte	N06, An3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	GOTO , 228, 109
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong400_Part4
sSong400_Part4: @ 0x08886FCF
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	PAN , 64
	.byte	LFOS , 44
	.byte	VOL , 92
	.byte	MOD , 2
	.byte	XCMD , 8 , 12
	.byte	9 , 8
	.byte	N03, Cs5, 68
	.byte	W06
	.byte	Cs5, 16
	.byte	W06
	.byte	En5, 68
	.byte	W06
	.byte	En5, 16
	.byte	W06
	.byte	An4, 68
	.byte	W06
	.byte	An4, 20
	.byte	W06
	.byte	Gs4, 68
	.byte	W06
	.byte	Gs4, 16
	.byte	W06
	.byte	Fs4, 68
	.byte	W06
	.byte	Fs4, 16
	.byte	W06
	.byte	Gs4, 68
	.byte	W06
	.byte	Gs4, 16
	.byte	W06
	.byte	An4, 68
	.byte	W06
	.byte	An4, 16
	.byte	W06
	.byte	Bn4, 68
	.byte	W06
	.byte	Bn4, 16
	.byte	W06
	.byte	W96
	.byte	VOICE , 4
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	VOL , 46
	.byte	N48, En3, 76
	.byte	W48
	.byte	N24, An3, 88
	.byte	W24
	.byte	N04, Dn3, 112
	.byte	W04
	.byte	En3
	.byte	W04
	.byte	Fs3
	.byte	W04
	.byte	Gs3
	.byte	W04
	.byte	An3
	.byte	W04
	.byte	Bn3
	.byte	W04
	.byte	PAN , 127
	.byte	N48, Cs4
	.byte	W24
	.byte	MOD , 10
	.byte	W24
	.byte	2
	.byte	N36, En4
	.byte	W24
	.byte	MOD , 10
	.byte	W12
	.byte	2
	.byte	N06, Cn4
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	N12, Dn4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	Cs4
	.byte	W12
	.byte	Bn3
	.byte	W18
	.byte	N06, Gs3
	.byte	W06
	.byte	N02, Cs4
	.byte	W02
	.byte	Dn4
	.byte	W02
	.byte	N08, Cs4
	.byte	W09
	.byte	N06, Bn3
	.byte	W05
	.byte	An3
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Ds3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	N12, Gs3
	.byte	W12
	.byte	N06, Bn3
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	Gn3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	N12, Bn3
	.byte	W12
	.byte	N06, Dn4
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	N12, En4
	.byte	W12
	.byte	Fs4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	N06, Cs4
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	N02, En4
	.byte	W02
	.byte	Fs4
	.byte	W02
	.byte	N08, En4
	.byte	W09
	.byte	N06, Cs4
	.byte	W05
	.byte	Bn3
	.byte	W06
	.byte	N48, Cs4
	.byte	W24
	.byte	MOD , 11
	.byte	W24
	.byte	2
	.byte	N48, En4
	.byte	W24
	.byte	MOD , 11
	.byte	W24
	.byte	2
	.byte	N06, Dn4
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	Dn3
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	En4
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	N03, Gn4
	.byte	W03
	.byte	N21, Gs4
	.byte	W09
	.byte	MOD , 8
	.byte	W12
	.byte	2
	.byte	N12, Fs4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	VOL , 34
	.byte	N24, An4
	.byte	W12
	.byte	MOD , 9
	.byte	W12
	.byte	2
	.byte	N24, Gs4
	.byte	W12
	.byte	MOD , 11
	.byte	W12
	.byte	2
	.byte	N12, En4
	.byte	W12
	.byte	Fs4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	N24, Cs4
	.byte	W12
	.byte	MOD , 9
	.byte	W12
	.byte	2
	.byte	W24
	.byte	GOTO , 17, 112
	.byte	W08
	.byte	8
	.byte	FINE
	.globl sSong400_Part5
sSong400_Part5: @ 0x08887106
	.byte	KEYSH , 0
	.byte	VOICE , 3
	.byte	PAN , 1
	.byte	VOL , 69
	.byte	N03, En4, 96
	.byte	W06
	.byte	En4, 16
	.byte	W06
	.byte	An4, 80
	.byte	W06
	.byte	An4, 16
	.byte	W06
	.byte	Cs4, 64
	.byte	W06
	.byte	Cs4, 20
	.byte	W06
	.byte	Bn3, 64
	.byte	W06
	.byte	Bn3, 16
	.byte	W06
	.byte	An3, 64
	.byte	W06
	.byte	An3, 16
	.byte	W06
	.byte	Bn3, 64
	.byte	W06
	.byte	Bn3, 16
	.byte	W06
	.byte	Cs4, 72
	.byte	W06
	.byte	Cs4, 16
	.byte	W06
	.byte	En4, 80
	.byte	W06
	.byte	En4, 16
	.byte	W06
	.byte	VOL , 69
	.byte	N06, An4, 68
	.byte	W06
	.byte	En4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	Cs5
	.byte	W06
	.byte	VOICE , 6
	.byte	PAN , 127
	.byte	W03
	.byte	N03, Ds5
	.byte	W03
	.byte	N06, En5
	.byte	W12
	.byte	En5, 16
	.byte	W12
	.byte	En5, 64
	.byte	W12
	.byte	N02, Dn5, 68
	.byte	W02
	.byte	En5
	.byte	W02
	.byte	N08, Dn5
	.byte	W09
	.byte	N06, Cs5
	.byte	W05
	.byte	An4
	.byte	W06
	.byte	Bn4
	.byte	W06
	.byte	PAN , 1
	.byte	W03
	.byte	VOICE , 3
	.byte	W03
	.byte	N06, Dn5
	.byte	W12
	.byte	Dn5, 16
	.byte	W12
	.byte	Bn4, 68
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	En4
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	VOICE , 6
	.byte	PAN , 127
	.byte	N06, Fs4
	.byte	W12
	.byte	Gn4
	.byte	W12
	.byte	VOICE , 3
	.byte	PAN , 1
	.byte	N06, Gs4
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	En4
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	VOICE , 6
	.byte	PAN , 127
	.byte	W03
	.byte	N03, Cn5
	.byte	W03
	.byte	N06, Cs5
	.byte	W12
	.byte	Cs5, 16
	.byte	W12
	.byte	Bn4, 68
	.byte	W12
	.byte	Bn4, 16
	.byte	W12
	.byte	Gs4, 68
	.byte	W12
	.byte	An4
	.byte	W12
	.byte	VOICE , 3
	.byte	PAN , 64
	.byte	N24, Cs5
	.byte	W36
	.byte	VOL , 57
	.byte	W21
	.byte	N03, As4, 96
	.byte	W03
	.byte	N06, An4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	Fs4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	VOL , 44
	.byte	N06, An3
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	An3
	.byte	W06
	.byte	Cs4
	.byte	W09
	.byte	N03, Ds4
	.byte	W03
	.byte	N06, En4
	.byte	W12
	.byte	En4, 16
	.byte	W12
	.byte	Dn4, 96
	.byte	W12
	.byte	Dn4, 16
	.byte	W12
	.byte	Cs4, 96
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	Dn4, 16
	.byte	W12
	.byte	Bn3, 96
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Ds3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Gs3
	.byte	W06
	.byte	Bn2
	.byte	W06
	.byte	En3
	.byte	W06
	.byte	Fs3
	.byte	W06
	.byte	Gs3
	.byte	W09
	.byte	N03, Cn4
	.byte	W03
	.byte	N06, Cs4
	.byte	W12
	.byte	Cs4, 16
	.byte	W12
	.byte	Bn3, 96
	.byte	W12
	.byte	Bn3, 16
	.byte	W12
	.byte	Gs3, 96
	.byte	W12
	.byte	N12, An3, 112
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	An3, 96
	.byte	W12
	.byte	Bn3, 112
	.byte	W12
	.byte	N04, Cs4, 80
	.byte	W04
	.byte	Dn4, 84
	.byte	W04
	.byte	En4, 92
	.byte	W04
	.byte	Fs4, 96
	.byte	W04
	.byte	Gs4, 100
	.byte	W04
	.byte	An4, 108
	.byte	W04
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO , 63, 113
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong400_Part6
sSong400_Part6: @ 0x08887249
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 92
	.byte	XCMD , 8 , 9
	.byte	9 , 8
	.byte	LFOS , 44
	.byte	PAN , 64
	.byte	W96
	.byte	N06, An1, 127
	.byte	W06
	.byte	An1, 36
	.byte	W30
	.byte	N03, An1, 127
	.byte	W06
	.byte	En1
	.byte	W18
	.byte	N06, En2
	.byte	W06
	.byte	En2, 36
	.byte	W18
	.byte	An1, 127
	.byte	W06
	.byte	An1, 36
	.byte	W06
	.byte	PEND
	.byte	N06, Bn1, 127
	.byte	W06
	.byte	Bn1, 36
	.byte	W30
	.byte	N03, Bn1, 127
	.byte	W06
	.byte	En1
	.byte	W18
	.byte	N06, Dn2
	.byte	W06
	.byte	Dn2, 36
	.byte	W18
	.byte	En1, 127
	.byte	W06
	.byte	Fs1
	.byte	W06
	.byte	PEND
	.byte	Bn1
	.byte	W06
	.byte	Bn1, 36
	.byte	W30
	.byte	N03, Bn1, 127
	.byte	W06
	.byte	Gs1
	.byte	W18
	.byte	N06, Dn2
	.byte	W06
	.byte	Dn2, 36
	.byte	W18
	.byte	Gs1, 127
	.byte	W06
	.byte	Gs1, 36
	.byte	W06
	.byte	An1, 127
	.byte	W06
	.byte	An1, 36
	.byte	W30
	.byte	N03, An1, 127
	.byte	W06
	.byte	En1
	.byte	W06
	.byte	An1
	.byte	W06
	.byte	En1
	.byte	W06
	.byte	N06, Cs2
	.byte	W06
	.byte	Cs2, 36
	.byte	W18
	.byte	Cs2, 127
	.byte	W06
	.byte	Cs2, 36
	.byte	W06
	.byte	PATT , 89, 114
	.byte	W08
	.byte	GsM2
	.byte	PATT , 115, 114
	.byte	W08
	.byte	GsM2
	.byte	N06, Bn1, 127
	.byte	W06
	.byte	Bn1, 36
	.byte	W30
	.byte	N03, Bn1, 127
	.byte	W06
	.byte	Gs1
	.byte	W18
	.byte	N06, Dn2
	.byte	W06
	.byte	Dn2, 36
	.byte	W18
	.byte	Dn2, 127
	.byte	W06
	.byte	Dn2, 36
	.byte	W06
	.byte	An1, 127
	.byte	W06
	.byte	An1, 36
	.byte	W30
	.byte	N03, An1, 127
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	En1
	.byte	W06
	.byte	N06, En2
	.byte	W06
	.byte	En2, 36
	.byte	W18
	.byte	En2, 127
	.byte	W06
	.byte	Gs1
	.byte	W06
	.byte	N24, An1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, An1, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N03, En1, 127
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Cs2
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, Cs2, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N06, An1, 127
	.byte	W12
	.byte	N24, Dn2
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, Dn2, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N03, An1, 127
	.byte	W06
	.byte	Dn2
	.byte	W06
	.byte	N06, En1
	.byte	W06
	.byte	N03, En2
	.byte	W12
	.byte	N06, En1
	.byte	W06
	.byte	Fs1
	.byte	W06
	.byte	Fs1, 36
	.byte	W06
	.byte	Gn1, 127
	.byte	W06
	.byte	Gn1, 36
	.byte	W06
	.byte	N24, Gs1, 127
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, Gs1, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N03, En1, 127
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Bn1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	92
	.byte	MOD , 0
	.byte	N24, Gs1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	92
	.byte	MOD , 0
	.byte	N24, An1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, An1, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N03, An1, 127
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Cs2
	.byte	W06
	.byte	N03, En2
	.byte	W12
	.byte	N06, En1
	.byte	W06
	.byte	Fs1
	.byte	W06
	.byte	Fs1, 36
	.byte	W06
	.byte	Gs1, 127
	.byte	W06
	.byte	Gs1, 36
	.byte	W06
	.byte	N24, An1, 127
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, An1, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N03, En1, 127
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Cs2
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, Cs2, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N03, An1, 127
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N24, Bn1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, Bn1, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N06, En1, 127
	.byte	W12
	.byte	Dn1
	.byte	W06
	.byte	N03, Dn2
	.byte	W12
	.byte	N06, Dn1
	.byte	W06
	.byte	Fs1
	.byte	W12
	.byte	An1
	.byte	W12
	.byte	N24, Gs1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	MOD , 0
	.byte	N06, Gs1, 36
	.byte	W09
	.byte	VOL , 92
	.byte	W03
	.byte	N06, En1, 127
	.byte	W12
	.byte	N24, Bn1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	92
	.byte	MOD , 0
	.byte	N24, Gs1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	92
	.byte	MOD , 0
	.byte	N12, An1
	.byte	W06
	.byte	VOL , 87
	.byte	W03
	.byte	81
	.byte	W03
	.byte	75
	.byte	N06, An1, 36
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	63
	.byte	W03
	.byte	57
	.byte	W03
	.byte	52
	.byte	W09
	.byte	92
	.byte	W03
	.byte	N03, An1, 127
	.byte	W06
	.byte	En1
	.byte	W06
	.byte	N06, Cs2
	.byte	W06
	.byte	N03, En2
	.byte	W12
	.byte	N06, En1
	.byte	W06
	.byte	Fs1
	.byte	W06
	.byte	Fs1, 36
	.byte	W06
	.byte	Gs1, 127
	.byte	W06
	.byte	Gs1, 36
	.byte	W06
	.byte	GOTO , 89, 114
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong400_Part7
sSong400_Part7: @ 0x088874F8
	.byte	KEYSH , 0
	.byte	VOICE , 45
	.byte	VOL , 75
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte	N06, Gs3, 112
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	Cs4
	.byte	W12
	.byte	Bn3
	.byte	W06
	.byte	Gs3
	.byte	W06
	.byte	An3
	.byte	W12
	.byte	Bn3
	.byte	W12
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
	.byte	W96
	.byte	W96
	.byte	GOTO , 255, 116
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong400_Part8
sSong400_Part8: @ 0x08887527
	.byte	KEYSH , 0
	.byte	VOICE , 127
	.byte	PAN , 64
	.byte	VOL , 37
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 80
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 80
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 88
	.byte	W04
	.byte	Gn4, 64
	.byte	W04
	.byte	N01
	.byte	W04
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 88
	.byte	W04
	.byte	Gn4, 64
	.byte	W04
	.byte	N01
	.byte	W04
	.byte	Fn3, 96
	.byte	W06
	.byte	Gs4, 112
	.byte	W06
	.byte	N01, Gn4, 112
	.byte	W06
	.byte	Gn4, 72
	.byte	W06
	.byte	Gn4, 88
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 84
	.byte	W12
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 80
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	PEND
	.byte	PATT , 96, 117
	.byte	W08
	.byte	GsM2
	.byte	PATT , 96, 117
	.byte	W08
	.byte	GsM2
	.byte	N01, Gn4, 112
	.byte	W06
	.byte	Gn4, 72
	.byte	W06
	.byte	Gn4, 88
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 88
	.byte	W04
	.byte	Gn4, 64
	.byte	W04
	.byte	N01
	.byte	W04
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	PATT , 96, 117
	.byte	W08
	.byte	GsM2
	.byte	N01, Gn4, 112
	.byte	W06
	.byte	Gn4, 72
	.byte	W06
	.byte	Gn4, 88
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 88
	.byte	W04
	.byte	Gn4, 64
	.byte	W04
	.byte	N01
	.byte	W04
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N12
	.byte	W12
	.byte	N01, Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	PATT , 96, 117
	.byte	W08
	.byte	GsM2
	.byte	N01, Gn4, 112
	.byte	W06
	.byte	Gn4, 72
	.byte	W06
	.byte	Gn4, 88
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 84
	.byte	W12
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 88
	.byte	W04
	.byte	Gn4, 64
	.byte	W04
	.byte	N01
	.byte	W04
	.byte	N06, Gs4, 112
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N01, Gn4, 112
	.byte	W06
	.byte	Gn4, 72
	.byte	W06
	.byte	Gn4, 88
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 88
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	PEND
	.byte	PATT , 41, 118
	.byte	W08
	.byte	GsM2
	.byte	PATT , 41, 118
	.byte	W08
	.byte	GsM2
	.byte	PATT , 41, 118
	.byte	W08
	.byte	GsM2
	.byte	PATT , 41, 118
	.byte	W08
	.byte	GsM2
	.byte	PATT , 41, 118
	.byte	W08
	.byte	GsM2
	.byte	N12, Gs4, 112
	.byte	W36
	.byte	N01, Gn4, 88
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 88
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N12
	.byte	W12
	.byte	N12
	.byte	W48
	.byte	N12
	.byte	W12
	.byte	N01, Gn4, 84
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	N12, Gs4, 112
	.byte	W12
	.byte	N01, Gn4, 80
	.byte	W06
	.byte	Gn4, 64
	.byte	W06
	.byte	GOTO , 96, 117
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8876A9, 0x3
	.globl sSongHeader_400
sSongHeader_400: @ 0x088876AC
	.byte 0x09, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08608BD0  @ tone
	.4byte 0x08886A94, 0x08886AE4, 0x08886D24, 0x08886DD9, 0x08886FCF, 0x08887106, 0x08887249, 0x088874F8, 0x08887527  @ parts
