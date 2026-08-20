.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong265_Part0
sSong265_Part0: @ 0x0886FAC8
	.byte	KEYSH , 0
	.byte	TEMPO , 46
	.byte	VOICE , 116
	.byte	VOL , 127
	.byte	PAN , 2
	.byte	N32, Fn3, 127
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE
	.globl sSong265_Part1
sSong265_Part1: @ 0x0886FAD9
	.byte	KEYSH , 0
	.byte	VOICE , 117
	.byte	VOL , 127
	.byte	PAN , 127
	.byte	BEND , 65
	.byte	N32, An3, 100
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86FAEA, 0x2
	.globl sSongHeader_265
sSongHeader_265: @ 0x0886FAEC
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886FAC8, 0x0886FAD9  @ parts
