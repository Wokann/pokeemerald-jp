.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong127_Part0
sSong127_Part0: @ 0x0886A840
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 20
	.byte	BEND , 64
	.byte	TIE , 67, 64
	.byte	W03
	.byte	VOL , 37
	.byte	W03
	.byte	53
	.byte	W03
	.byte	60
	.byte	W03
	.byte	71
	.byte	W03
	.byte	81
	.byte	W03
	.byte	93
	.byte	W03
	.byte	110
	.byte	W03
	.byte	PAN , 67
	.byte	W06
	.byte	75
	.byte	W12
	.byte	84
	.byte	W06
	.byte	89
	.byte	W12
	.byte	78
	.byte	W06
	.byte	72
	.byte	W06
	.byte	W06
	.byte	61
	.byte	W12
	.byte	48
	.byte	W06
	.byte	W06
	.byte	38
	.byte	W12
	.byte	48
	.byte	W06
	.byte	VOL , 104
	.byte	PAN , 59
	.byte	W03
	.byte	VOL , 101
	.byte	W03
	.byte	98
	.byte	PAN , 70
	.byte	W03
	.byte	VOL , 93
	.byte	W03
	.byte	90
	.byte	PAN , 78
	.byte	W03
	.byte	VOL , 86
	.byte	W03
	.byte	83
	.byte	W03
	.byte	77
	.byte	W03
	.byte	73
	.byte	PAN , 88
	.byte	W03
	.byte	VOL , 66
	.byte	W03
	.byte	58
	.byte	W03
	.byte	44
	.byte	W03
	.byte	32
	.byte	PAN , 79
	.byte	W03
	.byte	VOL , 16
	.byte	W03
	.byte	1
	.byte	PAN , 68
	.byte	W06
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A8AA, 0x2
	.globl sSongHeader_127
sSongHeader_127: @ 0x0886A8AC
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong127_Part0  @ parts
