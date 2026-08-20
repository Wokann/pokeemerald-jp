.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong120_Part0
sSong120_Part0: @ 0x0886A5B8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 28
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	BEND , 80
	.byte	N03, Gs3, 80
	.byte	W01
	.byte	BEND , 102
	.byte	W01
	.byte	126
	.byte	W02
	.byte	N17, Gs4, 96
	.byte	W03
	.byte	PAN , 70
	.byte	W02
	.byte	64
	.byte	W03
	.byte	56
	.byte	W02
	.byte	64
	.byte	W02
	.byte	70
	.byte	W03
	.byte	64
	.byte	W05
	.byte	FINE
	.globl sSong120_Part1
sSong120_Part1: @ 0x0886A5DF
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	N01, En4, 60
	.byte	W04
	.byte	N17, Gs4, 96
	.byte	W20
	.byte	FINE
	.globl sSongHeader_120
sSongHeader_120: @ 0x0886A5F0
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A5B8, 0x0886A5DF  @ parts
