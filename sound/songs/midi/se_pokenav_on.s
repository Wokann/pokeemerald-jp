.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong110_Part0
sSong110_Part0: @ 0x0886A088
	.byte	KEYSH , 0
	.byte	TEMPO , 72
	.byte	VOICE , 4
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 100
	.byte	BEND , 58
	.byte	N02, Cn4, 60
	.byte	W02
	.byte	N01, Cn4, 32
	.byte	W01
	.byte	N02, Gn4, 60
	.byte	W03
	.byte	N01, Gn4, 32
	.byte	W01
	.byte	N02, Cn4, 60
	.byte	W02
	.byte	Cn4, 32
	.byte	W03
	.byte	Cn5, 60
	.byte	W02
	.byte	Cn5, 32
	.byte	W04
	.byte	FINE
	.globl sSong110_Part1
sSong110_Part1: @ 0x0886A0B5
	.byte	KEYSH , 0
	.byte	VOICE , 14
	.byte	VOL , 50
	.byte	BEND , 62
	.byte	W01
	.byte	N02, Cn4, 60
	.byte	W02
	.byte	N01, Cn4, 32
	.byte	W01
	.byte	N02, Gn4, 60
	.byte	W02
	.byte	W01
	.byte	N01, Gn4, 32
	.byte	W01
	.byte	N02, Cn4, 60
	.byte	W02
	.byte	Cn4, 32
	.byte	W02
	.byte	W01
	.byte	Cn5, 60
	.byte	W02
	.byte	Cn5, 32
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A0DE, 0x2
	.globl sSongHeader_110
sSongHeader_110: @ 0x0886A0E0
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x0886A088, 0x0886A0B5  @ parts
