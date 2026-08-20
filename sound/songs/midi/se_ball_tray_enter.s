.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong114_Part0
sSong114_Part0: @ 0x0886A3E0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 32
	.byte	VOL , 16
	.byte	BEND , 65
	.byte	N09, Gn5, 32
	.byte	W01
	.byte	VOL , 63
	.byte	W01
	.byte	98
	.byte	W01
	.byte	110
	.byte	W01
	.byte	99
	.byte	BEND , 69
	.byte	W02
	.byte	VOL , 63
	.byte	BEND , 77
	.byte	W01
	.byte	VOL , 22
	.byte	BEND , 85
	.byte	W01
	.byte	VOL , 9
	.byte	BEND , 97
	.byte	W04
	.byte	FINE
	.globl sSong114_Part1
sSong114_Part1: @ 0x0886A40D
	.byte	KEYSH , 0
	.byte	VOICE , 71
	.byte	PAN , 96
	.byte	VOL , 110
	.byte	BEND , 65
	.byte	N09, Fs4, 60
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A41D, 0x3
	.globl sSongHeader_114
sSongHeader_114: @ 0x0886A420
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A3E0, 0x0886A40D  @ parts
