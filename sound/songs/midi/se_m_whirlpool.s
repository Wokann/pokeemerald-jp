.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong165_Part0
sSong165_Part0: @ 0x0886BA20
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 115
	.byte	BEND , 46
	.byte	TIE , 50, 127
	.byte	W03
	.byte	BEND , 52
	.byte	W03
	.byte	PAN , 59
	.byte	W02
	.byte	BEND , 56
	.byte	W04
	.byte	PAN , 54
	.byte	W01
	.byte	BEND , 61
	.byte	W03
	.byte	66
	.byte	W02
	.byte	PAN , 51
	.byte	W04
	.byte	BEND , 69
	.byte	W02
	.byte	PAN , 48
	.byte	W04
	.byte	BEND , 78
	.byte	W02
	.byte	PAN , 50
	.byte	W06
	.byte	55
	.byte	BEND , 82
	.byte	W06
	.byte	PAN , 58
	.byte	W01
	.byte	BEND , 88
	.byte	W05
	.byte	PAN , 64
	.byte	W06
	.byte	67
	.byte	W06
	.byte	71
	.byte	W06
	.byte	75
	.byte	BEND , 81
	.byte	W06
	.byte	PAN , 80
	.byte	BEND , 74
	.byte	W06
	.byte	PAN , 75
	.byte	W01
	.byte	BEND , 69
	.byte	W05
	.byte	PAN , 70
	.byte	W02
	.byte	VOL , 103
	.byte	W01
	.byte	BEND , 64
	.byte	W03
	.byte	PAN , 68
	.byte	W01
	.byte	VOL , 85
	.byte	W01
	.byte	BEND , 59
	.byte	W04
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 71
	.byte	W02
	.byte	BEND , 56
	.byte	W03
	.byte	VOL , 52
	.byte	PAN , 60
	.byte	W03
	.byte	BEND , 52
	.byte	W01
	.byte	VOL , 32
	.byte	W02
	.byte	PAN , 54
	.byte	W03
	.byte	VOL , 11
	.byte	BEND , 45
	.byte	W03
	.byte	PAN , 49
	.byte	W01
	.byte	VOL , 6
	.byte	W01
	.byte	BEND , 36
	.byte	W04
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86BAAB, 0x1
	.globl sSongHeader_165
sSongHeader_165: @ 0x0886BAAC
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong165_Part0  @ parts
