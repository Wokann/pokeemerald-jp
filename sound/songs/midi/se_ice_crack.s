.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong42_Part0
sSong42_Part0: @ 0x08868C44
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 9
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N01, Gn5, 88
	.byte	W01
	.byte	N01
	.byte	W02
	.byte	Cn6, 72
	.byte	W03
	.byte	Cn6, 56
	.byte	W03
	.byte	FINE
	.globl sSong42_Part1
sSong42_Part1: @ 0x08868C5B
	.byte	KEYSH , 0
	.byte	VOICE , 122
	.byte	VOL , 100
	.byte	N01, Gn2, 112
	.byte	W02
	.byte	VOICE , 123
	.byte	W01
	.byte	N01, Gs4, 96
	.byte	W03
	.byte	Gs4, 112
	.byte	W03
	.byte	FINE
	.globl sSongHeader_42
sSongHeader_42: @ 0x08868C70
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x08868C44, 0x08868C5B  @ parts
