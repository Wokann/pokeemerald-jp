.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong211_Part0
sSong211_Part0: @ 0x0886D648
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 46
	.byte	VOL , 100
	.byte	BENDR , 4
	.byte	PAN , 64
	.byte	MOD , 6
	.byte	BEND , 67
	.byte	N01, Ds6, 92
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	N20, Gn6, 100
	.byte	W21
	.byte	N01, Ds6, 56
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	N20, Gn6, 64
	.byte	W03
	.byte	PAN , 70
	.byte	W04
	.byte	60
	.byte	W05
	.byte	70
	.byte	W05
	.byte	60
	.byte	W04
	.byte	PEND
	.byte	PAN , 64
	.byte	N01, Gs5, 92
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	Cn5
	.byte	W01
	.byte	N20, Cn6, 100
	.byte	W21
	.byte	PEND
	.byte	PAN , 80
	.byte	N01, Gs5, 56
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	Cn5
	.byte	W01
	.byte	N20, Cn6, 64
	.byte	W21
	.byte	PEND
	.byte	PAN , 48
	.byte	N01, Gs5, 40
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	Cn5
	.byte	W01
	.byte	N20, Cn6
	.byte	W21
	.byte	PEND
	.byte	PAN , 96
	.byte	N01, Gs5, 20
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	Cn5
	.byte	W01
	.byte	PAN , 32
	.byte	N20, Cn6
	.byte	W21
	.byte	PEND
	.byte	PAN , 64
	.byte	N01, Ds6, 92
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	N20, Gn6, 100
	.byte	W21
	.byte	PATT , 100, 214
	.byte	W06
	.byte	GsM2
	.byte	PATT , 122, 214
	.byte	W06
	.byte	GsM2
	.byte	PATT , 137, 214
	.byte	W06
	.byte	GsM2
	.byte	PATT , 152, 214
	.byte	W06
	.byte	GsM2
	.byte	PATT , 166, 214
	.byte	W06
	.byte	GsM2
	.byte	FINE
	.globl sSong211_Part1
sSong211_Part1: @ 0x0886D6DE
	.byte	KEYSH , 0
	.byte	VOICE , 55
	.byte	PAN , 64
	.byte	VOL , 39
	.byte	BEND , 60
	.byte	W10
	.byte	N01, Ds6, 112
	.byte	W02
	.byte	Dn6
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	N04, Gn6
	.byte	W05
	.byte	Gn6, 96
	.byte	W05
	.byte	PAN , 114
	.byte	N04, Gn6, 80
	.byte	W04
	.byte	PAN , 16
	.byte	N04, Gn6, 64
	.byte	W05
	.byte	PAN , 114
	.byte	N04, Gn6, 48
	.byte	W05
	.byte	PAN , 15
	.byte	N04, Gn6, 32
	.byte	W10
	.byte	PEND
	.byte	PAN , 64
	.byte	W10
	.byte	N01, Gs5, 112
	.byte	W02
	.byte	Gn5
	.byte	W01
	.byte	Cn5
	.byte	W01
	.byte	N04, Cn6
	.byte	W05
	.byte	Cn6, 96
	.byte	W05
	.byte	PEND
	.byte	PAN , 114
	.byte	N04, Cn6, 80
	.byte	W04
	.byte	PAN , 16
	.byte	N04, Cn6, 64
	.byte	W05
	.byte	PAN , 114
	.byte	N04, Cn6, 48
	.byte	W05
	.byte	PAN , 15
	.byte	N04, Cn6, 32
	.byte	W10
	.byte	PEND
	.byte	W24
	.byte	W24
	.byte	PAN , 64
	.byte	W10
	.byte	N01, Ds6, 112
	.byte	W02
	.byte	Dn6
	.byte	W01
	.byte	Gn5
	.byte	W01
	.byte	N04, Gn6
	.byte	W05
	.byte	Gn6, 96
	.byte	W05
	.byte	PATT , 247, 214
	.byte	W06
	.byte	GsM2
	.byte	PATT , 16, 215
	.byte	W06
	.byte	GsM2
	.byte	PATT , 34, 215
	.byte	W06
	.byte	GsM2
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSongHeader_211
sSongHeader_211: @ 0x0886D760
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886D648, 0x0886D6DE  @ parts
