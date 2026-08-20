.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong260_Part0
sSong260_Part0: @ 0x0886F7F0
	.byte	KEYSH , 0
	.byte	TEMPO , 131
	.byte	VOICE , 123
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	PAN , 64
	.byte	VOL , 40
	.byte	BEND , 66
	.byte	N02, Cn2, 120
	.byte	W08
	.byte	N04, Cn5
	.byte	W16
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong260_Part1
sSong260_Part1: @ 0x0886F810
	.byte	KEYSH , 0
	.byte	VOICE , 31
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 80
	.byte	PAN , 64
	.byte	BEND , 0
	.byte	TIE , 76, 32
	.byte	W24
	.byte	W04
	.byte	BEND , 9
	.byte	W02
	.byte	14
	.byte	W02
	.byte	25
	.byte	W02
	.byte	32
	.byte	W02
	.byte	41
	.byte	W02
	.byte	46
	.byte	W02
	.byte	55
	.byte	W02
	.byte	62
	.byte	W02
	.byte	80
	.byte	W02
	.byte	87
	.byte	W02
	.byte	96
	.byte	W02
	.byte	103
	.byte	W02
	.byte	112
	.byte	W02
	.byte	120
	.byte	W02
	.byte	127
	.byte	W16
	.byte	W24
	.byte	W24
	.byte	VOL , 70
	.byte	W04
	.byte	66
	.byte	W06
	.byte	60
	.byte	W06
	.byte	55
	.byte	W08
	.byte	49
	.byte	W06
	.byte	44
	.byte	W06
	.byte	40
	.byte	W06
	.byte	35
	.byte	W06
	.byte	30
	.byte	W04
	.byte	24
	.byte	W02
	.byte	20
	.byte	W02
	.byte	15
	.byte	W04
	.byte	10
	.byte	W06
	.byte	0
	.byte	W06
	.byte	EOT
	.byte	FINE
	.globl sSong260_Part2
sSong260_Part2: @ 0x0886F863
	.byte	KEYSH , 0
	.byte	VOICE , 50
	.byte	VOL , 69
	.byte	PAN , 0
	.byte	W24
	.byte	127
	.byte	N01, Fs4, 64
	.byte	W06
	.byte	Gs4
	.byte	W03
	.byte	PAN , 0
	.byte	W07
	.byte	N01, En5
	.byte	W05
	.byte	Fs5
	.byte	W03
	.byte	PAN , 127
	.byte	W10
	.byte	N01, Dn5
	.byte	W03
	.byte	Cn5
	.byte	W07
	.byte	PAN , 0
	.byte	W04
	.byte	N01, Fs3
	.byte	W03
	.byte	Gs3
	.byte	W09
	.byte	PAN , 127
	.byte	W04
	.byte	N01, Bn4
	.byte	W04
	.byte	Dn5
	.byte	W04
	.byte	PAN , 0
	.byte	W09
	.byte	N01, Fs5
	.byte	W09
	.byte	Cs5
	.byte	W06
	.byte	PAN , 127
	.byte	W02
	.byte	N01, Cs4, 36
	.byte	W02
	.byte	As3
	.byte	W08
	.byte	Fs3
	.byte	W03
	.byte	Gs3
	.byte	W09
	.byte	PAN , 0
	.byte	W03
	.byte	N01, Dn5, 28
	.byte	W03
	.byte	Cn5
	.byte	W06
	.byte	Fs4
	.byte	W03
	.byte	Cn4
	.byte	W04
	.byte	Gn3
	.byte	W05
	.byte	PAN , 127
	.byte	W06
	.byte	N01, Gn4, 20
	.byte	W02
	.byte	An4
	.byte	W16
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F8C1, 0x3
	.globl sSongHeader_260
sSongHeader_260: @ 0x0886F8C4
	.byte 0x03, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886F7F0, 0x0886F810, 0x0886F863  @ parts
