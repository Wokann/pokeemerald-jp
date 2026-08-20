.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong164_Part0
sSong164_Part0: @ 0x0886B99C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 115
	.byte	BEND , 64
	.byte	TIE , 55, 127
	.byte	W06
	.byte	PAN , 60
	.byte	W06
	.byte	54
	.byte	W06
	.byte	59
	.byte	W06
	.byte	64
	.byte	W06
	.byte	68
	.byte	W06
	.byte	75
	.byte	W06
	.byte	68
	.byte	W06
	.byte	64
	.byte	W06
	.byte	60
	.byte	W06
	.byte	54
	.byte	W06
	.byte	59
	.byte	W06
	.byte	64
	.byte	W06
	.byte	68
	.byte	W06
	.byte	75
	.byte	W02
	.byte	VOL , 103
	.byte	W04
	.byte	PAN , 68
	.byte	W01
	.byte	VOL , 85
	.byte	W05
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 71
	.byte	W05
	.byte	52
	.byte	PAN , 60
	.byte	W04
	.byte	VOL , 32
	.byte	W02
	.byte	PAN , 54
	.byte	W03
	.byte	VOL , 11
	.byte	W03
	.byte	PAN , 59
	.byte	W01
	.byte	VOL , 6
	.byte	W05
	.byte	EOT
	.byte	FINE
	.globl sSong164_Part1
sSong164_Part1: @ 0x0886B9EF
	.byte	KEYSH , 0
	.byte	VOL , 58
	.byte	N14, Gn3, 80
	.byte	W01
	.byte	VOICE , 25
	.byte	VOL , 76
	.byte	W01
	.byte	89
	.byte	W01
	.byte	100
	.byte	W01
	.byte	115
	.byte	W06
	.byte	90
	.byte	W02
	.byte	76
	.byte	W01
	.byte	58
	.byte	W11
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86BA0D, 0x3
	.globl sSongHeader_164
sSongHeader_164: @ 0x0886BA10
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B99C, 0x0886B9EF  @ parts
