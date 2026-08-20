.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong464_Part0
sSong464_Part0: @ 0x088C0610
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 19
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	VOL , 79
	.byte	PAN , 32
	.byte	TIE , 74, 100
	.byte	W60
	.byte	MOD , 5
	.byte	W36
	.byte	0
	.byte	W96
	.byte	W96
	.byte	W84
	.byte	EOT
	.byte	W12
	.byte	TIE
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	EOT
	.byte	TIE
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	VOL , 77
	.byte	W02
	.byte	75
	.byte	W04
	.byte	72
	.byte	W02
	.byte	70
	.byte	W04
	.byte	68
	.byte	W02
	.byte	65
	.byte	W04
	.byte	63
	.byte	W02
	.byte	60
	.byte	W04
	.byte	59
	.byte	W02
	.byte	56
	.byte	W04
	.byte	55
	.byte	W02
	.byte	53
	.byte	W04
	.byte	48
	.byte	W02
	.byte	47
	.byte	W04
	.byte	43
	.byte	W02
	.byte	38
	.byte	W04
	.byte	38
	.byte	W02
	.byte	36
	.byte	W04
	.byte	31
	.byte	W02
	.byte	30
	.byte	W04
	.byte	27
	.byte	W02
	.byte	25
	.byte	W04
	.byte	22
	.byte	W02
	.byte	18
	.byte	W04
	.byte	16
	.byte	W02
	.byte	13
	.byte	W04
	.byte	9
	.byte	W02
	.byte	8
	.byte	W04
	.byte	6
	.byte	W02
	.byte	1
	.byte	W10
	.byte	EOT
	.byte	FINE
	.globl sSong464_Part1
sSong464_Part1: @ 0x088C0675
	.byte	KEYSH , 0
	.byte	VOICE , 19
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	PAN , 100
	.byte	VOL , 79
	.byte	N96, Dn3, 100
	.byte	W96
	.byte	TIE
	.byte	W96
	.byte	W96
	.byte	EOT
	.byte	N84
	.byte	W96
	.byte	N96
	.byte	W96
	.byte	TIE
	.byte	W96
	.byte	W96
	.byte	EOT
	.byte	N96
	.byte	W96
	.byte	N96
	.byte	W96
	.byte	TIE
	.byte	W96
	.byte	W96
	.byte	EOT
	.byte	TIE
	.byte	W96
	.byte	VOL , 77
	.byte	W02
	.byte	75
	.byte	W04
	.byte	72
	.byte	W02
	.byte	70
	.byte	W04
	.byte	68
	.byte	W02
	.byte	65
	.byte	W04
	.byte	63
	.byte	W02
	.byte	60
	.byte	W04
	.byte	59
	.byte	W02
	.byte	56
	.byte	W04
	.byte	55
	.byte	W02
	.byte	53
	.byte	W04
	.byte	48
	.byte	W02
	.byte	47
	.byte	W04
	.byte	43
	.byte	W02
	.byte	38
	.byte	W04
	.byte	38
	.byte	W02
	.byte	36
	.byte	W04
	.byte	31
	.byte	W02
	.byte	30
	.byte	W04
	.byte	27
	.byte	W02
	.byte	25
	.byte	W04
	.byte	22
	.byte	W02
	.byte	18
	.byte	W04
	.byte	16
	.byte	W02
	.byte	13
	.byte	W04
	.byte	9
	.byte	W02
	.byte	8
	.byte	W04
	.byte	6
	.byte	W02
	.byte	1
	.byte	W10
	.byte	EOT
	.byte	FINE
	.globl sSong464_Part2
sSong464_Part2: @ 0x088C06DA
	.byte	KEYSH , 0
	.byte	VOICE , 20
	.byte	BENDR , 12
	.byte	LFOS , 38
	.byte	PAN , 70
	.byte	VOL , 90
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	N12, Dn3, 96
	.byte	W12
	.byte	N84, En3
	.byte	W12
	.byte	VOL , 79
	.byte	MOD , 1
	.byte	W72
	.byte	VOL , 90
	.byte	MOD , 0
	.byte	N12, Fn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Dn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Fn3
	.byte	W12
	.byte	Dn3
	.byte	W12
	.byte	TIE , 64
	.byte	W12
	.byte	VOL , 79
	.byte	MOD , 1
	.byte	W12
	.byte	W96
	.byte	EOT
	.byte	VOL , 90
	.byte	MOD , 0
	.byte	N12, Fn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Dn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Fn3
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	N24, An3
	.byte	W12
	.byte	VOL , 79
	.byte	MOD , 1
	.byte	W12
	.byte	N12
	.byte	W12
	.byte	VOL , 90
	.byte	MOD , 0
	.byte	N12, As3
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	Fn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Fn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Dn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Fn3
	.byte	W12
	.byte	Dn3
	.byte	W12
	.byte	TIE , 64
	.byte	W12
	.byte	VOL , 79
	.byte	MOD , 1
	.byte	W12
	.byte	W96
	.byte	EOT
	.byte	MOD , 0
	.byte	VOL , 90
	.byte	N12, Fn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Dn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Fn3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	TIE , 62
	.byte	W12
	.byte	VOL , 79
	.byte	MOD , 1
	.byte	W12
	.byte	VOL , 77
	.byte	W02
	.byte	75
	.byte	W04
	.byte	72
	.byte	W02
	.byte	70
	.byte	W04
	.byte	68
	.byte	W02
	.byte	65
	.byte	W04
	.byte	63
	.byte	W02
	.byte	60
	.byte	W04
	.byte	59
	.byte	W02
	.byte	56
	.byte	W04
	.byte	55
	.byte	W02
	.byte	53
	.byte	W04
	.byte	48
	.byte	W02
	.byte	47
	.byte	W04
	.byte	43
	.byte	W02
	.byte	38
	.byte	W04
	.byte	38
	.byte	W02
	.byte	36
	.byte	W04
	.byte	31
	.byte	W02
	.byte	30
	.byte	W04
	.byte	27
	.byte	W02
	.byte	25
	.byte	W04
	.byte	22
	.byte	W02
	.byte	18
	.byte	W04
	.byte	16
	.byte	W02
	.byte	13
	.byte	W04
	.byte	9
	.byte	W02
	.byte	8
	.byte	W04
	.byte	6
	.byte	W02
	.byte	1
	.byte	W10
	.byte	EOT
	.byte	MOD , 0
	.byte	FINE
	.globl sSong464_Part3
sSong464_Part3: @ 0x088C07AF
	.byte	KEYSH , 0
	.byte	VOICE , 19
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	PAN , 80
	.byte	VOL , 90
	.byte	N96, Gn2, 120
	.byte	W12
	.byte	VOL , 79
	.byte	W48
	.byte	MOD , 5
	.byte	W36
	.byte	MOD , 0
	.byte	VOL , 90
	.byte	N96, An2, 120
	.byte	W12
	.byte	VOL , 79
	.byte	W84
	.byte	PEND
	.byte	90
	.byte	N96, As2
	.byte	W12
	.byte	VOL , 79
	.byte	W48
	.byte	MOD , 5
	.byte	W36
	.byte	0
	.byte	VOL , 90
	.byte	N84, Gn2
	.byte	W12
	.byte	VOL , 79
	.byte	W36
	.byte	MOD , 5
	.byte	W36
	.byte	0
	.byte	W12
	.byte	VOL , 90
	.byte	N96, Gn2, 120
	.byte	W12
	.byte	VOL , 79
	.byte	W48
	.byte	MOD , 5
	.byte	W36
	.byte	PEND
	.byte	PATT , 197, 7
	.byte	W12
	.byte	8
	.byte	PATT , 233, 7
	.byte	W12
	.byte	8
	.byte	MOD , 0
	.byte	VOL , 90
	.byte	N96, An2, 120
	.byte	W12
	.byte	VOL , 79
	.byte	W48
	.byte	MOD , 5
	.byte	W36
	.byte	0
	.byte	VOL , 90
	.byte	N96, Gn2
	.byte	W12
	.byte	VOL , 79
	.byte	W84
	.byte	90
	.byte	N96, An2
	.byte	W12
	.byte	VOL , 79
	.byte	W48
	.byte	MOD , 5
	.byte	W36
	.byte	0
	.byte	VOL , 90
	.byte	N96, Gn2
	.byte	W12
	.byte	VOL , 79
	.byte	W48
	.byte	MOD , 5
	.byte	W36
	.byte	0
	.byte	VOL , 90
	.byte	TIE , 50
	.byte	W12
	.byte	VOL , 79
	.byte	W48
	.byte	MOD , 5
	.byte	W36
	.byte	VOL , 77
	.byte	W02
	.byte	75
	.byte	W04
	.byte	72
	.byte	W02
	.byte	70
	.byte	W04
	.byte	68
	.byte	W02
	.byte	65
	.byte	W04
	.byte	63
	.byte	W02
	.byte	60
	.byte	W04
	.byte	59
	.byte	W02
	.byte	56
	.byte	W04
	.byte	55
	.byte	W02
	.byte	53
	.byte	W04
	.byte	48
	.byte	W02
	.byte	47
	.byte	W04
	.byte	43
	.byte	W02
	.byte	38
	.byte	W04
	.byte	38
	.byte	W02
	.byte	36
	.byte	W04
	.byte	31
	.byte	W02
	.byte	30
	.byte	W04
	.byte	27
	.byte	W02
	.byte	25
	.byte	W04
	.byte	22
	.byte	W02
	.byte	18
	.byte	W04
	.byte	16
	.byte	W02
	.byte	13
	.byte	W04
	.byte	9
	.byte	W02
	.byte	8
	.byte	W04
	.byte	6
	.byte	W02
	.byte	1
	.byte	W10
	.byte	EOT
	.byte	FINE
	.globl sSong464_Part4
sSong464_Part4: @ 0x088C0878
	.byte	KEYSH , 0
	.byte	VOICE , 80
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	PAN , 64
	.byte	VOL , 55
	.byte	BEND , 65
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 2
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 127
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 64
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	PAN , 127
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 2
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 64
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 64
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 2
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 127
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 64
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	PAN , 127
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 2
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 64
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PEND
	.byte	PATT , 177, 8
	.byte	W12
	.byte	GsM2
	.byte	PAN , 64
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 2
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 127
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 64
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	PAN , 127
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 2
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 64
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT , 177, 8
	.byte	W12
	.byte	8
	.byte	PATT , 177, 8
	.byte	W12
	.byte	8
	.byte	PATT , 177, 8
	.byte	W12
	.byte	8
	.byte	PAN , 64
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 2
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 127
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	PAN , 64
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	PAN , 127
	.byte	N09, Dn1, 52
	.byte	W12
	.byte	PAN , 2
	.byte	N21, Dn1, 64
	.byte	W12
	.byte	PAN , 64
	.byte	W12
	.byte	W96
	.byte	FINE
	.globl sSong464_Part5
sSong464_Part5: @ 0x088C094D
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	PAN , 64
	.byte	VOL , 79
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	PEND
	.byte	PATT , 114, 9
	.byte	W12
	.byte	GsM2
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT , 114, 9
	.byte	W12
	.byte	GsM2
	.byte	PATT , 114, 9
	.byte	W12
	.byte	GsM2
	.byte	PATT , 114, 9
	.byte	W12
	.byte	GsM2
	.byte	N09, Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	Dn1, 64
	.byte	W12
	.byte	Dn1, 52
	.byte	W12
	.byte	N21, Dn1, 64
	.byte	W24
	.byte	W96
	.byte	FINE
	.globl sSong464_Part6
sSong464_Part6: @ 0x088C09D3
	.byte	KEYSH , 0
	.byte	VOICE , 82
	.byte	VOL , 56
	.byte	PAN , 64
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	BEND , 64
	.byte	TIE , 62, 100
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte	EOT
	.byte	W12
	.byte	N12, Dn4
	.byte	W12
	.byte	N84, En4
	.byte	W84
	.byte	N12, Fn4, 100
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	TIE , 76
	.byte	W24
	.byte	PEND
	.byte	W96
	.byte	EOT
	.byte	N12, Fn4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	Gn4
	.byte	W12
	.byte	N24, An4
	.byte	W24
	.byte	N12
	.byte	W12
	.byte	As4
	.byte	W12
	.byte	An4
	.byte	W12
	.byte	Gn4
	.byte	W12
	.byte	An4
	.byte	W12
	.byte	Gn4
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	PATT , 240, 9
	.byte	W12
	.byte	GsM2
	.byte	W96
	.byte	EOT , 76
	.byte	N12, Fn4, 100
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Dn4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Fn4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	N48, Dn4
	.byte	W12
	.byte	VOL , 45
	.byte	W12
	.byte	34
	.byte	W12
	.byte	22
	.byte	W12
	.byte	11
	.byte	W24
	.byte	1
	.byte	W48
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8C0A49, 0x3
	.globl sSongHeader_464
sSongHeader_464: @ 0x088C0A4C
	.byte 0x07, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte 0x0861F190  @ tone
	.4byte sSong464_Part0, sSong464_Part1, sSong464_Part2, sSong464_Part3, sSong464_Part4, sSong464_Part5, sSong464_Part6  @ parts
