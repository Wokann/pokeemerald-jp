.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong201_Part0
sSong201_Part0: @ 0x0886CDD8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 24
	.byte	VOL , 25
	.byte	PAN , 64
	.byte	BEND , 127
	.byte	TIE , 72, 112
	.byte	W04
	.byte	VOL , 40
	.byte	W02
	.byte	PAN , 60
	.byte	BEND , 116
	.byte	W03
	.byte	VOL , 55
	.byte	W03
	.byte	PAN , 54
	.byte	BEND , 105
	.byte	W03
	.byte	VOL , 80
	.byte	W03
	.byte	PAN , 59
	.byte	BEND , 94
	.byte	W06
	.byte	PAN , 64
	.byte	BEND , 86
	.byte	W01
	.byte	VOL , 100
	.byte	W05
	.byte	PAN , 68
	.byte	BEND , 127
	.byte	W06
	.byte	PAN , 75
	.byte	BEND , 116
	.byte	W06
	.byte	PAN , 68
	.byte	BEND , 105
	.byte	W04
	.byte	97
	.byte	W02
	.byte	PAN , 64
	.byte	W03
	.byte	BEND , 89
	.byte	W03
	.byte	PAN , 60
	.byte	W03
	.byte	BEND , 86
	.byte	W03
	.byte	PAN , 54
	.byte	W06
	.byte	59
	.byte	BEND , 81
	.byte	W06
	.byte	PAN , 64
	.byte	BEND , 73
	.byte	W06
	.byte	PAN , 68
	.byte	W02
	.byte	BEND , 68
	.byte	W04
	.byte	PAN , 75
	.byte	W06
	.byte	68
	.byte	BEND , 64
	.byte	W06
	.byte	PAN , 64
	.byte	W06
	.byte	60
	.byte	W02
	.byte	BEND , 61
	.byte	W04
	.byte	PAN , 54
	.byte	W06
	.byte	59
	.byte	W04
	.byte	BEND , 59
	.byte	W02
	.byte	PAN , 64
	.byte	W06
	.byte	68
	.byte	W02
	.byte	BEND , 57
	.byte	W04
	.byte	PAN , 75
	.byte	W06
	.byte	68
	.byte	W01
	.byte	BEND , 54
	.byte	W05
	.byte	PAN , 64
	.byte	W03
	.byte	BEND , 51
	.byte	W03
	.byte	PAN , 60
	.byte	W06
	.byte	54
	.byte	BEND , 46
	.byte	W03
	.byte	VOL , 89
	.byte	W03
	.byte	PAN , 59
	.byte	W02
	.byte	VOL , 74
	.byte	BEND , 39
	.byte	W04
	.byte	PAN , 64
	.byte	W02
	.byte	VOL , 62
	.byte	W01
	.byte	BEND , 32
	.byte	W03
	.byte	PAN , 68
	.byte	W01
	.byte	VOL , 45
	.byte	W01
	.byte	BEND , 24
	.byte	W04
	.byte	VOL , 28
	.byte	PAN , 75
	.byte	BEND , 15
	.byte	W03
	.byte	0
	.byte	W01
	.byte	VOL , 10
	.byte	W02
	.byte	PAN , 68
	.byte	W02
	.byte	VOL , 5
	.byte	W04
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86CE9E, 0x2
	.globl sSongHeader_201
sSongHeader_201: @ 0x0886CEA0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong201_Part0  @ parts
