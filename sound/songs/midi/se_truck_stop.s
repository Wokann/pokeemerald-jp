.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong50_Part0
sSong50_Part0: @ 0x08868EAC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 10
	.byte	VOL , 127
	.byte	BEND , 64
	.byte	TIE , 61, 127
	.byte	W09
	.byte	BEND , 55
	.byte	W09
	.byte	46
	.byte	W06
	.byte	W09
	.byte	38
	.byte	W09
	.byte	30
	.byte	W06
	.byte	W06
	.byte	21
	.byte	W05
	.byte	VOL , 123
	.byte	W04
	.byte	BEND , 10
	.byte	W02
	.byte	VOL , 117
	.byte	W06
	.byte	110
	.byte	W01
	.byte	BEND , 0
	.byte	W08
	.byte	VOL , 101
	.byte	W06
	.byte	89
	.byte	W09
	.byte	77
	.byte	W01
	.byte	W05
	.byte	60
	.byte	W09
	.byte	48
	.byte	W06
	.byte	36
	.byte	W04
	.byte	W03
	.byte	23
	.byte	W06
	.byte	8
	.byte	W09
	.byte	0
	.byte	W01
	.byte	EOT
	.byte	W05
	.byte	FINE
	.globl sSong50_Part1
sSong50_Part1: @ 0x08868EED
	.byte	KEYSH , 0
	.byte	VOICE , 13
	.byte	VOL , 90
	.byte	W06
	.byte	N09, Gs6, 24
	.byte	W18
	.byte	W05
	.byte	N15
	.byte	W19
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong50_Part2
sSong50_Part2: @ 0x08868F00
	.byte	KEYSH , 0
	.byte	VOICE , 12
	.byte	VOL , 90
	.byte	W06
	.byte	N09, An6, 24
	.byte	W18
	.byte	W05
	.byte	N15
	.byte	W19
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868F13, 0x1
	.globl sSongHeader_50
sSongHeader_50: @ 0x08868F14
	.byte 0x03, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08868EAC, 0x08868EED, 0x08868F00  @ parts
