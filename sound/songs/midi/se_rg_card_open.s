.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong251_Part0
sSong251_Part0: @ 0x0886F4A0
	.byte	KEYSH , 0
	.byte	TEMPO , 87
	.byte	VOICE , 46
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 112
	.byte	PAN , 64
	.byte	VOL , 112
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, An5, 112
	.byte	W03
	.byte	VOL , 64
	.byte	N03, Bn5
	.byte	W03
	.byte	VOL , 112
	.byte	PAN , 16
	.byte	N06, En6
	.byte	W03
	.byte	VOL , 64
	.byte	W03
	.byte	112
	.byte	PAN , 112
	.byte	N06, En6, 40
	.byte	W03
	.byte	VOL , 64
	.byte	W03
	.byte	PAN , 16
	.byte	VOL , 97
	.byte	N06, En6, 32
	.byte	W03
	.byte	VOL , 64
	.byte	W03
	.byte	PAN , 112
	.byte	VOL , 96
	.byte	N06, En6, 24
	.byte	W03
	.byte	VOL , 64
	.byte	W03
	.byte	PAN , 16
	.byte	VOL , 80
	.byte	N06, En6, 16
	.byte	W03
	.byte	VOL , 64
	.byte	W03
	.byte	PAN , 112
	.byte	VOL , 80
	.byte	N06, En6, 12
	.byte	W03
	.byte	VOL , 48
	.byte	W03
	.byte	N06, En6, 8
	.byte	W03
	.byte	VOL , 2
	.byte	W03
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong251_Part1
sSong251_Part1: @ 0x0886F509
	.byte	KEYSH , 0
	.byte	VOICE , 124
	.byte	PAN , 64
	.byte	VOL , 64
	.byte	N03, Cn5, 92
	.byte	W06
	.byte	Cn5, 32
	.byte	W18
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F51D, 0x3
	.globl sSongHeader_251
sSongHeader_251: @ 0x0886F520
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886F4A0, 0x0886F509  @ parts
