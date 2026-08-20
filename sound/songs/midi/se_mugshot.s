.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong104_Part0
sSong104_Part0: @ 0x08869CF0
	.byte	KEYSH , 0
	.byte	TEMPO , 55
	.byte	VOICE , 66
	.byte	BENDR , 12
	.byte	VOL , 90
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N90, Gs3, 40
	.byte	W06
	.byte	W06
	.byte	BEND , 65
	.byte	W04
	.byte	67
	.byte	W02
	.byte	W04
	.byte	69
	.byte	W02
	.byte	W04
	.byte	72
	.byte	W02
	.byte	W03
	.byte	75
	.byte	W03
	.byte	W03
	.byte	82
	.byte	W03
	.byte	W02
	.byte	88
	.byte	W04
	.byte	94
	.byte	W02
	.byte	102
	.byte	W02
	.byte	107
	.byte	W02
	.byte	W01
	.byte	120
	.byte	W02
	.byte	127
	.byte	W03
	.byte	W03
	.byte	VOL , 83
	.byte	W03
	.byte	75
	.byte	W04
	.byte	68
	.byte	W02
	.byte	W01
	.byte	55
	.byte	W04
	.byte	42
	.byte	W01
	.byte	W03
	.byte	29
	.byte	W03
	.byte	17
	.byte	W03
	.byte	8
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.globl sSong104_Part1
sSong104_Part1: @ 0x08869D3A
	.byte	KEYSH , 0
	.byte	VOICE , 2
	.byte	VOL , 14
	.byte	PAN , 63
	.byte	BEND , 64
	.byte	TIE , 67, 100
	.byte	W01
	.byte	VOL , 19
	.byte	W01
	.byte	30
	.byte	W02
	.byte	37
	.byte	W02
	.byte	W02
	.byte	44
	.byte	W04
	.byte	49
	.byte	W04
	.byte	53
	.byte	W02
	.byte	W03
	.byte	58
	.byte	W03
	.byte	W02
	.byte	64
	.byte	W04
	.byte	68
	.byte	W03
	.byte	74
	.byte	W03
	.byte	W01
	.byte	BEND , 65
	.byte	W01
	.byte	VOL , 81
	.byte	W04
	.byte	BEND , 66
	.byte	W01
	.byte	VOL , 90
	.byte	W03
	.byte	BEND , 68
	.byte	W02
	.byte	W03
	.byte	69
	.byte	W03
	.byte	W01
	.byte	70
	.byte	W03
	.byte	70
	.byte	W02
	.byte	W02
	.byte	72
	.byte	W02
	.byte	74
	.byte	W02
	.byte	W01
	.byte	78
	.byte	W02
	.byte	81
	.byte	W03
	.byte	88
	.byte	W02
	.byte	94
	.byte	W01
	.byte	105
	.byte	W01
	.byte	110
	.byte	W02
	.byte	119
	.byte	W01
	.byte	124
	.byte	W01
	.byte	127
	.byte	W01
	.byte	VOL , 87
	.byte	W03
	.byte	85
	.byte	PAN , 60
	.byte	W02
	.byte	VOL , 78
	.byte	PAN , 68
	.byte	W02
	.byte	VOL , 75
	.byte	PAN , 58
	.byte	W02
	.byte	W01
	.byte	VOL , 69
	.byte	PAN , 70
	.byte	W02
	.byte	VOL , 59
	.byte	PAN , 44
	.byte	W03
	.byte	VOL , 49
	.byte	PAN , 86
	.byte	W02
	.byte	VOL , 41
	.byte	PAN , 27
	.byte	W02
	.byte	VOL , 30
	.byte	PAN , 101
	.byte	W02
	.byte	W01
	.byte	VOL , 19
	.byte	PAN , 16
	.byte	W02
	.byte	VOL , 10
	.byte	PAN , 112
	.byte	W01
	.byte	VOL , 4
	.byte	W02
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869DCB, 0x1
	.globl sSongHeader_104
sSongHeader_104: @ 0x08869DCC
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869CF0, 0x08869D3A  @ parts
