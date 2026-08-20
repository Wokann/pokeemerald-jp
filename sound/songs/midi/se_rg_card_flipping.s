.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong250_Part0
sSong250_Part0: @ 0x0886F468
	.byte	KEYSH , 0
	.byte	TEMPO , 91
	.byte	VOICE , 125
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	PAN , 64
	.byte	VOL , 16
	.byte	BEND , 66
	.byte	N24, Gn5, 88
	.byte	W03
	.byte	VOL , 32
	.byte	W03
	.byte	48
	.byte	W03
	.byte	64
	.byte	W03
	.byte	80
	.byte	W03
	.byte	96
	.byte	W03
	.byte	112
	.byte	W03
	.byte	127
	.byte	W03
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F491, 0x3
	.globl sSongHeader_250
sSongHeader_250: @ 0x0886F494
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte sSong250_Part0  @ parts
