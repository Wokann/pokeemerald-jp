.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong266_Part0
sSong266_Part0: @ 0x0886FAFC
	.byte	KEYSH , 0
	.byte	TEMPO , 46
	.byte	VOICE , 116
	.byte	VOL , 127
	.byte	PAN , 2
	.byte	N04, Fn3, 127
	.byte	W04
	.byte	VOICE , 10
	.byte	N04, Cn3
	.byte	W05
	.byte	VOICE , 116
	.byte	N32, Fn3
	.byte	W03
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE
	.globl sSong266_Part1
sSong266_Part1: @ 0x0886FB18
	.byte	KEYSH , 0
	.byte	VOICE , 117
	.byte	VOL , 127
	.byte	PAN , 127
	.byte	BEND , 65
	.byte	N04, Gn3, 100
	.byte	W04
	.byte	Dn3
	.byte	W05
	.byte	N32, Gn3
	.byte	W03
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86FB2F, 0x1
	.globl sSongHeader_266
sSongHeader_266: @ 0x0886FB30
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886FAFC, 0x0886FB18  @ parts
