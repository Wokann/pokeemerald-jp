.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong196_Part0
sSong196_Part0: @ 0x0886CAB4
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 52
	.byte	VOL , 127
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, As3, 120
	.byte	W01
	.byte	BEND , 56
	.byte	W01
	.byte	48
	.byte	W01
	.byte	63
	.byte	N12, As2, 127
	.byte	W03
	.byte	PAN , 68
	.byte	BEND , 72
	.byte	W02
	.byte	PAN , 60
	.byte	BEND , 75
	.byte	W01
	.byte	82
	.byte	W01
	.byte	PAN , 74
	.byte	BEND , 92
	.byte	W02
	.byte	99
	.byte	W01
	.byte	PAN , 54
	.byte	W02
	.byte	64
	.byte	BEND , 64
	.byte	N03, As3, 108
	.byte	W01
	.byte	BEND , 56
	.byte	W02
	.byte	47
	.byte	W01
	.byte	63
	.byte	N12, As2
	.byte	W02
	.byte	PAN , 68
	.byte	BEND , 72
	.byte	W03
	.byte	PAN , 60
	.byte	BEND , 75
	.byte	W01
	.byte	82
	.byte	W01
	.byte	PAN , 74
	.byte	BEND , 92
	.byte	W01
	.byte	99
	.byte	W01
	.byte	PAN , 54
	.byte	W03
	.byte	64
	.byte	BEND , 64
	.byte	N03, As3, 72
	.byte	W01
	.byte	BEND , 56
	.byte	W01
	.byte	48
	.byte	W01
	.byte	63
	.byte	N12, As2
	.byte	W03
	.byte	PAN , 68
	.byte	BEND , 72
	.byte	W02
	.byte	PAN , 60
	.byte	BEND , 75
	.byte	W01
	.byte	82
	.byte	W02
	.byte	PAN , 74
	.byte	BEND , 92
	.byte	W01
	.byte	99
	.byte	W01
	.byte	PAN , 54
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86CB33, 0x1
	.globl sSongHeader_196
sSongHeader_196: @ 0x0886CB34
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong196_Part0  @ parts
