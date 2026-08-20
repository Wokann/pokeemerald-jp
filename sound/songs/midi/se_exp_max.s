.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong91_Part0
sSong91_Part0: @ 0x088698A8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 46
	.byte	VOL , 94
	.byte	BENDR , 2
	.byte	LFOS , 40
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	N06, An5, 112
	.byte	W01
	.byte	N15, En6, 104
	.byte	W02
	.byte	W01
	.byte	MOD , 8
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte	0
	.byte	W02
	.byte	FINE
	.globl sSong91_Part1
sSong91_Part1: @ 0x088698CB
	.byte	KEYSH , 0
	.byte	VOICE , 53
	.byte	BENDR , 2
	.byte	VOL , 43
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	N06, An4, 108
	.byte	W01
	.byte	N12, Cs6, 104
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8698E5, 0x3
	.globl sSongHeader_91
sSongHeader_91: @ 0x088698E8
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x088698A8, 0x088698CB  @ parts
