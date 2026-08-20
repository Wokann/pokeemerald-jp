.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong172_Part0
sSong172_Part0: @ 0x0886BD18
	.byte	KEYSH , 0
	.byte	TEMPO , 50
	.byte	VOICE , 73
	.byte	BENDR , 12
	.byte	LFOS , 40
	.byte	PAN , 64
	.byte	VOL , 95
	.byte	BEND , 64
	.byte	N44, Gn4, 112
	.byte	W15
	.byte	MOD , 7
	.byte	W06
	.byte	VOL , 83
	.byte	W06
	.byte	69
	.byte	W06
	.byte	50
	.byte	W06
	.byte	24
	.byte	W06
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	N21, Fn5
	.byte	W12
	.byte	VOL , 86
	.byte	MOD , 7
	.byte	W03
	.byte	VOL , 75
	.byte	W03
	.byte	55
	.byte	W03
	.byte	26
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	N21, Ds5
	.byte	W12
	.byte	VOL , 86
	.byte	MOD , 7
	.byte	W03
	.byte	VOL , 75
	.byte	W03
	.byte	55
	.byte	W03
	.byte	26
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	N66, Gn4
	.byte	W24
	.byte	MOD , 7
	.byte	W18
	.byte	VOL , 83
	.byte	W06
	.byte	69
	.byte	W06
	.byte	50
	.byte	W06
	.byte	24
	.byte	W06
	.byte	MOD , 0
	.byte	W30
	.byte	FINE
	.globl sSong172_Part1
sSong172_Part1: @ 0x0886BD76
	.byte	KEYSH , 0
	.byte	VOICE , 73
	.byte	LFOS , 40
	.byte	VOL , 95
	.byte	BEND , 73
	.byte	W12
	.byte	PAN , 76
	.byte	N44, Gn4, 60
	.byte	W15
	.byte	MOD , 7
	.byte	W06
	.byte	VOL , 83
	.byte	W06
	.byte	69
	.byte	W06
	.byte	50
	.byte	W03
	.byte	W03
	.byte	24
	.byte	W06
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	PAN , 52
	.byte	N21, Fn5
	.byte	W12
	.byte	VOL , 86
	.byte	MOD , 7
	.byte	W03
	.byte	VOL , 75
	.byte	W03
	.byte	55
	.byte	W03
	.byte	26
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	PAN , 76
	.byte	N21, Ds5
	.byte	W12
	.byte	VOL , 86
	.byte	MOD , 7
	.byte	W03
	.byte	VOL , 75
	.byte	W03
	.byte	55
	.byte	W03
	.byte	26
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	PAN , 52
	.byte	N66, Gn4
	.byte	W24
	.byte	MOD , 7
	.byte	W12
	.byte	W06
	.byte	VOL , 83
	.byte	W06
	.byte	69
	.byte	W06
	.byte	50
	.byte	W06
	.byte	24
	.byte	W06
	.byte	MOD , 0
	.byte	W18
	.byte	FINE
	.globl sSong172_Part2
sSong172_Part2: @ 0x0886BDD9
	.byte	KEYSH , 0
	.byte	VOICE , 73
	.byte	LFOS , 40
	.byte	VOL , 95
	.byte	BEND , 56
	.byte	W24
	.byte	PAN , 47
	.byte	N44, Gn4, 40
	.byte	W15
	.byte	MOD , 7
	.byte	W06
	.byte	VOL , 83
	.byte	W03
	.byte	W03
	.byte	69
	.byte	W06
	.byte	50
	.byte	W06
	.byte	24
	.byte	W06
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	PAN , 81
	.byte	N21, Fn5
	.byte	W12
	.byte	VOL , 86
	.byte	MOD , 7
	.byte	W03
	.byte	VOL , 75
	.byte	W03
	.byte	55
	.byte	W03
	.byte	26
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	PAN , 47
	.byte	N21, Ds5
	.byte	W12
	.byte	VOL , 86
	.byte	MOD , 7
	.byte	W03
	.byte	VOL , 75
	.byte	W03
	.byte	55
	.byte	W03
	.byte	26
	.byte	MOD , 0
	.byte	W03
	.byte	VOL , 95
	.byte	PAN , 81
	.byte	N66, Gn4
	.byte	W24
	.byte	MOD , 7
	.byte	W18
	.byte	VOL , 83
	.byte	W06
	.byte	69
	.byte	W06
	.byte	50
	.byte	W06
	.byte	24
	.byte	W06
	.byte	MOD , 0
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86BE3B, 0x1
	.globl sSongHeader_172
sSongHeader_172: @ 0x0886BE3C
	.byte 0x03, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886BD18, 0x0886BD76, 0x0886BDD9  @ parts
