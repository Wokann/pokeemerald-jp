.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong232_Part0
sSong232_Part0: @ 0x0886E5BC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 65
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, Gn3, 112
	.byte	W01
	.byte	PAN , 57
	.byte	BEND , 47
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 28
	.byte	W01
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, Gn4
	.byte	W02
	.byte	PAN , 57
	.byte	BEND , 79
	.byte	W01
	.byte	PAN , 72
	.byte	BEND , 92
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, Gn4, 64
	.byte	W01
	.byte	PAN , 57
	.byte	BEND , 79
	.byte	W02
	.byte	PAN , 72
	.byte	BEND , 92
	.byte	W03
	.byte	FINE
	.globl sSong232_Part1
sSong232_Part1: @ 0x0886E5FD
	.byte	KEYSH , 0
	.byte	VOICE , 57
	.byte	VOL , 110
	.byte	N03, En3, 52
	.byte	W03
	.byte	W01
	.byte	N03
	.byte	W02
	.byte	W03
	.byte	En3, 32
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSongHeader_232
sSongHeader_232: @ 0x0886E610
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E5BC, 0x0886E5FD  @ parts
