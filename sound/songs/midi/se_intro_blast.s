.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong103_Part0
sSong103_Part0: @ 0x08869C30
	.byte	KEYSH , 0
	.byte	TEMPO , 55
	.byte	VOICE , 123
	.byte	BENDR , 12
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N60, Gs2, 52
	.byte	W06
	.byte	W06
	.byte	BEND , 64
	.byte	W02
	.byte	65
	.byte	W04
	.byte	66
	.byte	W02
	.byte	67
	.byte	W02
	.byte	69
	.byte	W02
	.byte	W01
	.byte	70
	.byte	W02
	.byte	72
	.byte	W03
	.byte	73
	.byte	W02
	.byte	75
	.byte	W02
	.byte	77
	.byte	W02
	.byte	W01
	.byte	79
	.byte	W02
	.byte	81
	.byte	W03
	.byte	83
	.byte	W02
	.byte	88
	.byte	W02
	.byte	91
	.byte	W02
	.byte	W01
	.byte	94
	.byte	W02
	.byte	102
	.byte	W03
	.byte	107
	.byte	W02
	.byte	120
	.byte	W02
	.byte	127
	.byte	W02
	.byte	64
	.byte	N72, Gs3
	.byte	W04
	.byte	BEND , 64
	.byte	W02
	.byte	W01
	.byte	65
	.byte	W03
	.byte	66
	.byte	W02
	.byte	W01
	.byte	67
	.byte	W02
	.byte	69
	.byte	W03
	.byte	70
	.byte	W02
	.byte	72
	.byte	W02
	.byte	73
	.byte	W02
	.byte	VOL , 98
	.byte	W01
	.byte	BEND , 75
	.byte	W01
	.byte	VOL , 96
	.byte	W01
	.byte	BEND , 77
	.byte	W01
	.byte	VOL , 92
	.byte	W02
	.byte	BEND , 79
	.byte	W01
	.byte	VOL , 92
	.byte	W01
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 85
	.byte	W01
	.byte	BEND , 83
	.byte	W02
	.byte	VOL , 81
	.byte	W01
	.byte	BEND , 88
	.byte	W01
	.byte	VOL , 74
	.byte	W01
	.byte	BEND , 91
	.byte	W01
	.byte	VOL , 66
	.byte	W02
	.byte	BEND , 94
	.byte	W01
	.byte	VOL , 62
	.byte	W01
	.byte	BEND , 102
	.byte	W01
	.byte	VOL , 56
	.byte	W01
	.byte	BEND , 107
	.byte	W02
	.byte	VOL , 50
	.byte	W01
	.byte	BEND , 120
	.byte	W01
	.byte	VOL , 42
	.byte	W01
	.byte	BEND , 127
	.byte	W01
	.byte	VOL , 34
	.byte	W02
	.byte	W01
	.byte	29
	.byte	W02
	.byte	25
	.byte	W03
	.byte	23
	.byte	W02
	.byte	19
	.byte	W02
	.byte	14
	.byte	W02
	.byte	W01
	.byte	11
	.byte	W02
	.byte	5
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869CE2, 0x2
	.globl sSongHeader_103
sSongHeader_103: @ 0x08869CE4
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong103_Part0  @ parts
