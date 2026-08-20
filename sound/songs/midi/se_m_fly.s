.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong158_Part0
sSong158_Part0: @ 0x0886B628
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 90
	.byte	BEND , 64
	.byte	N01, En2, 127
	.byte	W01
	.byte	VOL , 55
	.byte	PAN , 74
	.byte	BEND , 48
	.byte	N07, An1
	.byte	W01
	.byte	VOL , 71
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	W01
	.byte	VOL , 86
	.byte	PAN , 55
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	BEND , 97
	.byte	W02
	.byte	PAN , 74
	.byte	BEND , 118
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 127
	.byte	W02
	.byte	VOL , 90
	.byte	PAN , 74
	.byte	BEND , 65
	.byte	N04
	.byte	W01
	.byte	VOL , 54
	.byte	PAN , 64
	.byte	BEND , 102
	.byte	W02
	.byte	VOL , 83
	.byte	PAN , 55
	.byte	BEND , 112
	.byte	W01
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	BEND , 127
	.byte	W03
	.byte	VOL , 90
	.byte	BEND , 64
	.byte	N01, Ds2, 104
	.byte	W02
	.byte	PAN , 74
	.byte	VOL , 55
	.byte	BEND , 48
	.byte	N07, Gs1, 100
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 71
	.byte	BEND , 64
	.byte	W01
	.byte	PAN , 55
	.byte	VOL , 86
	.byte	BEND , 81
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 97
	.byte	W01
	.byte	PAN , 74
	.byte	BEND , 118
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 127
	.byte	W02
	.byte	PAN , 74
	.byte	VOL , 90
	.byte	BEND , 65
	.byte	N04
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 54
	.byte	BEND , 102
	.byte	W01
	.byte	PAN , 55
	.byte	VOL , 83
	.byte	BEND , 112
	.byte	W02
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 127
	.byte	W03
	.byte	VOL , 90
	.byte	BEND , 64
	.byte	N01, Dn2, 88
	.byte	W01
	.byte	PAN , 74
	.byte	VOL , 55
	.byte	BEND , 48
	.byte	N07, Gn1, 60
	.byte	W02
	.byte	PAN , 64
	.byte	VOL , 71
	.byte	BEND , 64
	.byte	W01
	.byte	PAN , 55
	.byte	VOL , 86
	.byte	BEND , 81
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 97
	.byte	W01
	.byte	PAN , 74
	.byte	BEND , 118
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 127
	.byte	W03
	.byte	PAN , 74
	.byte	VOL , 90
	.byte	BEND , 65
	.byte	N04
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 54
	.byte	BEND , 102
	.byte	W01
	.byte	PAN , 55
	.byte	VOL , 83
	.byte	BEND , 112
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 127
	.byte	W02
	.byte	FINE
	.globl sSong158_Part1
sSong158_Part1: @ 0x0886B71C
	.byte	KEYSH , 0
	.byte	VOICE , 25
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	N08, Cn2, 40
	.byte	W01
	.byte	VOL , 72
	.byte	W01
	.byte	87
	.byte	W01
	.byte	110
	.byte	W01
	.byte	89
	.byte	W02
	.byte	49
	.byte	W01
	.byte	14
	.byte	W02
	.byte	110
	.byte	N04, Gn4
	.byte	W01
	.byte	VOL , 84
	.byte	W02
	.byte	110
	.byte	W02
	.byte	55
	.byte	W02
	.byte	110
	.byte	N08, Cn2, 32
	.byte	W02
	.byte	VOL , 72
	.byte	W01
	.byte	87
	.byte	W01
	.byte	110
	.byte	W01
	.byte	89
	.byte	W01
	.byte	49
	.byte	W02
	.byte	14
	.byte	W02
	.byte	110
	.byte	N04, Gn4
	.byte	W01
	.byte	VOL , 84
	.byte	W01
	.byte	110
	.byte	W03
	.byte	55
	.byte	W02
	.byte	110
	.byte	N08, Cn2, 20
	.byte	W01
	.byte	VOL , 72
	.byte	W02
	.byte	87
	.byte	W01
	.byte	110
	.byte	W01
	.byte	89
	.byte	W01
	.byte	49
	.byte	W01
	.byte	14
	.byte	W03
	.byte	110
	.byte	N04, Gn4
	.byte	W01
	.byte	VOL , 84
	.byte	W01
	.byte	110
	.byte	W03
	.byte	55
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B77A, 0x2
	.globl sSongHeader_158
sSongHeader_158: @ 0x0886B77C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886B628, 0x0886B71C  @ parts
