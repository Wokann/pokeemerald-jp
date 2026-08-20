.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong248_Part0
sSong248_Part0: @ 0x0886F3E4
	.byte	KEYSH , 0
	.byte	TEMPO , 55
	.byte	VOICE , 127
	.byte	VOL , 100
	.byte	N03, Fn2, 100
	.byte	N03, As2, 127
	.byte	W06
	.byte	N08, Fs3, 96
	.byte	W06
	.byte	VOL , 88
	.byte	W03
	.byte	54
	.byte	W03
	.byte	68
	.byte	W06
	.byte	FINE
	.globl sSong248_Part1
sSong248_Part1: @ 0x0886F3FF
	.byte	KEYSH , 0
	.byte	VOICE , 92
	.byte	BENDR , 12
	.byte	VOL , 43
	.byte	BEND , 64
	.byte	W04
	.byte	14
	.byte	N10, Bn5, 52
	.byte	W02
	.byte	BEND , 19
	.byte	W01
	.byte	41
	.byte	W01
	.byte	62
	.byte	W01
	.byte	86
	.byte	W01
	.byte	92
	.byte	W01
	.byte	105
	.byte	W01
	.byte	VOL , 29
	.byte	BEND , 117
	.byte	W01
	.byte	124
	.byte	W02
	.byte	VOL , 18
	.byte	BEND , 127
	.byte	W09
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F429, 0x3
	.globl sSongHeader_248
sSongHeader_248: @ 0x0886F42C
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886F3E4, 0x0886F3FF  @ parts
