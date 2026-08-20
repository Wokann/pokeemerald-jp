.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong173_Part0
sSong173_Part0: @ 0x0886BE50
	.byte	KEYSH , 0
	.byte	TEMPO , 50
	.byte	VOICE , 73
	.byte	BENDR , 12
	.byte	LFOS , 40
	.byte	PAN , 71
	.byte	VOL , 25
	.byte	BEND , 64
	.byte	W03
	.byte	VOL , 29
	.byte	W03
	.byte	33
	.byte	N48, An3, 112
	.byte	W03
	.byte	VOL , 40
	.byte	W03
	.byte	45
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 51
	.byte	W03
	.byte	56
	.byte	W03
	.byte	62
	.byte	W03
	.byte	72
	.byte	W03
	.byte	81
	.byte	W03
	.byte	92
	.byte	W03
	.byte	100
	.byte	W09
	.byte	82
	.byte	W03
	.byte	52
	.byte	W03
	.byte	25
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 29
	.byte	W03
	.byte	33
	.byte	N72, Gs3
	.byte	W03
	.byte	VOL , 40
	.byte	W03
	.byte	45
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 51
	.byte	W03
	.byte	56
	.byte	W03
	.byte	62
	.byte	W03
	.byte	72
	.byte	W03
	.byte	81
	.byte	W03
	.byte	92
	.byte	W03
	.byte	100
	.byte	W15
	.byte	W03
	.byte	87
	.byte	W03
	.byte	75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	48
	.byte	W03
	.byte	33
	.byte	W03
	.byte	25
	.byte	W03
	.byte	10
	.byte	W24
	.byte	W03
	.byte	FINE
	.globl sSong173_Part1
sSong173_Part1: @ 0x0886BEB5
	.byte	KEYSH , 0
	.byte	VOICE , 73
	.byte	VOL , 25
	.byte	PAN , 47
	.byte	N48, Cn4, 100
	.byte	W03
	.byte	VOL , 29
	.byte	W03
	.byte	33
	.byte	W03
	.byte	40
	.byte	W03
	.byte	45
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 51
	.byte	W03
	.byte	56
	.byte	W03
	.byte	62
	.byte	W03
	.byte	72
	.byte	W03
	.byte	81
	.byte	W03
	.byte	92
	.byte	W03
	.byte	100
	.byte	W09
	.byte	82
	.byte	W03
	.byte	52
	.byte	W03
	.byte	25
	.byte	MOD , 0
	.byte	N72, Bn3
	.byte	W03
	.byte	VOL , 29
	.byte	W03
	.byte	33
	.byte	W03
	.byte	40
	.byte	W03
	.byte	45
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 51
	.byte	W03
	.byte	56
	.byte	W03
	.byte	62
	.byte	W03
	.byte	72
	.byte	W03
	.byte	81
	.byte	W03
	.byte	92
	.byte	W03
	.byte	100
	.byte	W15
	.byte	W03
	.byte	87
	.byte	W03
	.byte	75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	48
	.byte	W03
	.byte	33
	.byte	W03
	.byte	25
	.byte	W03
	.byte	10
	.byte	W24
	.byte	W03
	.byte	FINE
	.globl sSong173_Part2
sSong173_Part2: @ 0x0886BF10
	.byte	KEYSH , 0
	.byte	VOICE , 73
	.byte	PAN , 80
	.byte	VOL , 25
	.byte	BEND , 71
	.byte	W06
	.byte	N48, An3, 80
	.byte	W03
	.byte	VOL , 29
	.byte	W03
	.byte	PAN , 48
	.byte	VOL , 33
	.byte	W03
	.byte	40
	.byte	W03
	.byte	45
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 51
	.byte	W03
	.byte	PAN , 80
	.byte	VOL , 56
	.byte	W03
	.byte	62
	.byte	W03
	.byte	72
	.byte	W03
	.byte	81
	.byte	W03
	.byte	PAN , 48
	.byte	VOL , 92
	.byte	W03
	.byte	100
	.byte	W09
	.byte	PAN , 80
	.byte	VOL , 82
	.byte	W03
	.byte	52
	.byte	W03
	.byte	25
	.byte	MOD , 0
	.byte	N72, Gs3
	.byte	W03
	.byte	VOL , 29
	.byte	W03
	.byte	PAN , 48
	.byte	VOL , 33
	.byte	W03
	.byte	40
	.byte	W03
	.byte	45
	.byte	MOD , 8
	.byte	W03
	.byte	VOL , 51
	.byte	W03
	.byte	PAN , 80
	.byte	VOL , 56
	.byte	W03
	.byte	62
	.byte	W03
	.byte	72
	.byte	W03
	.byte	81
	.byte	W03
	.byte	PAN , 48
	.byte	VOL , 92
	.byte	W03
	.byte	100
	.byte	W09
	.byte	PAN , 80
	.byte	W09
	.byte	VOL , 87
	.byte	W03
	.byte	75
	.byte	PAN , 48
	.byte	W03
	.byte	VOL , 62
	.byte	W03
	.byte	48
	.byte	W03
	.byte	33
	.byte	W03
	.byte	25
	.byte	PAN , 80
	.byte	W03
	.byte	VOL , 10
	.byte	W21
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86BF8B, 0x1
	.globl sSongHeader_173
sSongHeader_173: @ 0x0886BF8C
	.byte 0x03, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886BE50, 0x0886BEB5, 0x0886BF10  @ parts
