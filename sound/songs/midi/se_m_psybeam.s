.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong189_Part0
sSong189_Part0: @ 0x0886C728
	.byte	KEYSH , 0
	.byte	TEMPO , 95
	.byte	VOICE , 45
	.byte	BENDR , 8
	.byte	PAN , 64
	.byte	VOL , 38
	.byte	MOD , 30
	.byte	BEND , 65
	.byte	N42, As2, 120
	.byte	W01
	.byte	PAN , 67
	.byte	W01
	.byte	69
	.byte	VOL , 57
	.byte	W01
	.byte	PAN , 73
	.byte	W01
	.byte	VOL , 71
	.byte	W02
	.byte	PAN , 69
	.byte	W01
	.byte	65
	.byte	VOL , 82
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	61
	.byte	VOL , 94
	.byte	W01
	.byte	PAN , 58
	.byte	W02
	.byte	54
	.byte	VOL , 110
	.byte	W02
	.byte	PAN , 58
	.byte	W01
	.byte	61
	.byte	W01
	.byte	64
	.byte	W02
	.byte	W06
	.byte	67
	.byte	W01
	.byte	69
	.byte	W01
	.byte	73
	.byte	W02
	.byte	69
	.byte	W02
	.byte	65
	.byte	VOL , 95
	.byte	W01
	.byte	PAN , 64
	.byte	W01
	.byte	61
	.byte	VOL , 83
	.byte	W01
	.byte	PAN , 58
	.byte	W01
	.byte	54
	.byte	VOL , 71
	.byte	W02
	.byte	W01
	.byte	PAN , 58
	.byte	VOL , 56
	.byte	W01
	.byte	PAN , 61
	.byte	W01
	.byte	VOL , 38
	.byte	W03
	.byte	PAN , 64
	.byte	FINE
	.globl sSong189_Part1
sSong189_Part1: @ 0x0886C78F
	.byte	KEYSH , 0
	.byte	VOICE , 47
	.byte	BENDR , 8
	.byte	PAN , 64
	.byte	VOL , 38
	.byte	MOD , 30
	.byte	BEND , 65
	.byte	N42, As1, 40
	.byte	W02
	.byte	VOL , 57
	.byte	W02
	.byte	71
	.byte	W02
	.byte	W01
	.byte	82
	.byte	W02
	.byte	94
	.byte	W03
	.byte	110
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	95
	.byte	W02
	.byte	83
	.byte	W02
	.byte	71
	.byte	W02
	.byte	W01
	.byte	56
	.byte	W02
	.byte	38
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C7BB, 0x1
	.globl sSongHeader_189
sSongHeader_189: @ 0x0886C7BC
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886C728, 0x0886C78F  @ parts
