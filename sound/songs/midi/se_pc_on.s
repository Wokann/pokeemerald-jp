.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong4_Part0
sSong4_Part0: @ 0x0886845C
	.byte	KEYSH , 0
	.byte	TEMPO , 72
	.byte	VOICE , 4
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 100
	.byte	BEND , 53
	.byte	N12, Cn6, 112
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	N04, Cn5, 80
	.byte	W03
	.byte	W01
	.byte	Cn4
	.byte	W02
	.byte	W02
	.byte	Gn4
	.byte	W01
	.byte	W03
	.byte	Cn4
	.byte	W03
	.byte	W01
	.byte	Cn5
	.byte	W02
	.byte	W02
	.byte	Cn4
	.byte	W01
	.byte	W03
	.byte	Cn6, 100
	.byte	W03
	.byte	W01
	.byte	Cn4, 80
	.byte	W02
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868493, 0x1
	.globl sSongHeader_4
sSongHeader_4: @ 0x08868494
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong4_Part0  @ parts
