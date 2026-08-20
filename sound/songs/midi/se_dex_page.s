.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong109_Part0
sSong109_Part0: @ 0x0886A054
	.byte	KEYSH , 0
	.byte	TEMPO , 50
	.byte	VOICE , 4
	.byte	BENDR , 12
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 90
	.byte	BEND , 68
	.byte	N01, Cn5, 64
	.byte	W01
	.byte	Cn5, 20
	.byte	W01
	.byte	Cn5, 64
	.byte	W01
	.byte	Cn5, 20
	.byte	W01
	.byte	Cn6, 64
	.byte	W02
	.byte	Cn6, 20
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A079, 0x3
	.globl sSongHeader_109
sSongHeader_109: @ 0x0886A07C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong109_Part0  @ parts
