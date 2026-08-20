.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong72_Part0
sSong72_Part0: @ 0x088693C4
	.byte	KEYSH , 0
	.byte	TEMPO , 64
	.byte	VOICE , 89
	.byte	BENDR , 12
	.byte	VOL , 90
	.byte	BEND , 63
	.byte	N03, Fs2, 127
	.byte	W03
	.byte	N01, Ds3
	.byte	W03
	.byte	VOICE , 6
	.byte	N03, Gs3, 100
	.byte	W03
	.byte	W01
	.byte	N18, Fn5, 72
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong72_Part1
sSong72_Part1: @ 0x088693E9
	.byte	KEYSH , 0
	.byte	VOICE , 14
	.byte	VOL , 90
	.byte	BEND , 56
	.byte	N03, Gs3, 100
	.byte	W03
	.byte	W03
	.byte	Gs3, 60
	.byte	W03
	.byte	W01
	.byte	N18, Fn5
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSongHeader_72
sSongHeader_72: @ 0x08869404
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x088693C4, 0x088693E9  @ parts
