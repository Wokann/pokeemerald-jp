.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong558_Part0
sSong558_Part0: @ 0x0890EC00
	.byte	KEYSH , 0
	.byte	TEMPO , 72
	.byte	VOICE , 1
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 59
	.byte	W24
	.byte	N06, Cn2, 88
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	Gn1
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	An1
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	Bn1
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	PEND
	.byte	PATT , 13, 236
	.byte	W16
	.byte	GsM2
	.byte	GOTO , 13, 236
	.byte	W16
	.byte	GsM2
	.byte	FINE
	.globl sSong558_Part1
sSong558_Part1: @ 0x0890EC2B
	.byte	KEYSH , 0
	.byte	VOICE , 1
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 45
	.byte	BEND , 64
	.byte	W24
	.byte	W12
	.byte	N06, En3, 88
	.byte	W24
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W12
	.byte	PEND
	.byte	PATT , 56, 236
	.byte	W16
	.byte	GsM2
	.byte	GOTO , 56, 236
	.byte	W16
	.byte	GsM2
	.byte	FINE
	.globl sSong558_Part2
sSong558_Part2: @ 0x0890EC4F
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	VOL , 45
	.byte	BEND , 66
	.byte	W24
	.byte	N06, Cn2, 48
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	Gn1
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	An1
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	Bn1
	.byte	W12
	.byte	Gn3
	.byte	W12
	.byte	PEND
	.byte	PATT , 97, 236
	.byte	W16
	.byte	GsM2
	.byte	GOTO , 97, 236
	.byte	W16
	.byte	GsM2
	.byte	FINE
	.globl sSong558_Part3
sSong558_Part3: @ 0x0890EC7F
	.byte	KEYSH , 0
	.byte	VOICE , 127
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 34
	.byte	BEND , 64
	.byte	N03, Cn4, 120
	.byte	W06
	.byte	PAN , 0
	.byte	N03, Cn5
	.byte	W06
	.byte	PAN , 127
	.byte	N12, Gn4
	.byte	W12
	.byte	PAN , 64
	.byte	TIE , 72, 64
	.byte	W24
	.byte	BEND , 73
	.byte	W09
	.byte	54
	.byte	W09
	.byte	64
	.byte	W54
	.byte	73
	.byte	W24
	.byte	56
	.byte	W24
	.byte	64
	.byte	W48
	.byte	EOT
	.byte	GOTO , 160, 236
	.byte	W16
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x90ECBA, 0x2
	.globl sSongHeader_558
sSongHeader_558: @ 0x0890ECBC
	.byte 0x04, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte 0x0863A508  @ tone
	.4byte sSong558_Part0, sSong558_Part1, sSong558_Part2, sSong558_Part3  @ parts
	.incbin "baserom_jp.gba", 0x90ECD4, 0x80
