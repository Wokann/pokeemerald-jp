.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong182_Part0
sSong182_Part0: @ 0x0886C334
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 9
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	VOL , 24
	.byte	BEND , 47
	.byte	N78, Bn4, 80
	.byte	W01
	.byte	VOL , 32
	.byte	PAN , 70
	.byte	W01
	.byte	VOL , 38
	.byte	PAN , 57
	.byte	W01
	.byte	VOL , 48
	.byte	PAN , 73
	.byte	W01
	.byte	VOL , 66
	.byte	PAN , 51
	.byte	W02
	.byte	VOL , 78
	.byte	PAN , 70
	.byte	W01
	.byte	VOL , 94
	.byte	PAN , 58
	.byte	W01
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	W01
	.byte	70
	.byte	W01
	.byte	57
	.byte	W02
	.byte	PAN , 73
	.byte	W01
	.byte	51
	.byte	W01
	.byte	70
	.byte	W01
	.byte	58
	.byte	W01
	.byte	64
	.byte	W02
	.byte	PEND
	.byte	PAN , 70
	.byte	W01
	.byte	57
	.byte	W01
	.byte	73
	.byte	W01
	.byte	51
	.byte	W01
	.byte	70
	.byte	W02
	.byte	PEND
	.byte	58
	.byte	W01
	.byte	64
	.byte	W01
	.byte	70
	.byte	W01
	.byte	57
	.byte	W01
	.byte	73
	.byte	W02
	.byte	51
	.byte	W01
	.byte	70
	.byte	W01
	.byte	58
	.byte	W01
	.byte	64
	.byte	W01
	.byte	70
	.byte	W02
	.byte	57
	.byte	W01
	.byte	73
	.byte	W01
	.byte	51
	.byte	W01
	.byte	70
	.byte	W01
	.byte	58
	.byte	W02
	.byte	64
	.byte	W01
	.byte	70
	.byte	W01
	.byte	57
	.byte	W01
	.byte	73
	.byte	W01
	.byte	51
	.byte	W02
	.byte	70
	.byte	W01
	.byte	58
	.byte	W01
	.byte	64
	.byte	W01
	.byte	70
	.byte	W01
	.byte	57
	.byte	W02
	.byte	PATT , 109, 195
	.byte	W06
	.byte	8
	.byte	PATT , 121, 195
	.byte	W06
	.byte	8
	.byte	PAN , 58
	.byte	W01
	.byte	64
	.byte	W01
	.byte	70
	.byte	W01
	.byte	VOL , 103
	.byte	PAN , 57
	.byte	W01
	.byte	VOL , 91
	.byte	PAN , 73
	.byte	W02
	.byte	VOL , 72
	.byte	PAN , 51
	.byte	W01
	.byte	VOL , 58
	.byte	PAN , 70
	.byte	W01
	.byte	VOL , 38
	.byte	PAN , 58
	.byte	W01
	.byte	VOL , 15
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 7
	.byte	PAN , 70
	.byte	W02
	.byte	FINE
	.globl sSongHeader_182
sSongHeader_182: @ 0x0886C3EC
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong182_Part0  @ parts
