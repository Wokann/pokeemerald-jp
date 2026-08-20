.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong108_Part0
sSong108_Part0: @ 0x0886A02C
	.byte	KEYSH , 0
	.byte	TEMPO , 50
	.byte	VOICE , 4
	.byte	BENDR , 12
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 40
	.byte	BEND , 68
	.byte	N01, Gn4, 127
	.byte	W01
	.byte	Gn4, 20
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A045, 0x3
	.globl sSongHeader_108
sSongHeader_108: @ 0x0886A048
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong108_Part0  @ parts
