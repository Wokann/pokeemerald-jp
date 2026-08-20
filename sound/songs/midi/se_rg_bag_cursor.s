.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong252_Part0
sSong252_Part0: @ 0x0886F530
	.byte	KEYSH , 0
	.byte	TEMPO , 155
	.byte	VOICE , 10
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 127
	.byte	BEND , 66
	.byte	N01, Cs4, 72
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong252_Part1
sSong252_Part1: @ 0x0886F546
	.byte	VOL , 127
	.byte	KEYSH , 0
	.byte	VOICE , 124
	.byte	N01, Cs5, 72
	.byte	W01
	.byte	Ds5, 104
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F556, 0x2
	.globl sSongHeader_252
sSongHeader_252: @ 0x0886F558
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886F530, 0x0886F546  @ parts
