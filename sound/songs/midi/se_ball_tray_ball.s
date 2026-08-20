.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong115_Part0
sSong115_Part0: @ 0x0886A430
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 16
	.byte	VOL , 110
	.byte	BEND , 65
	.byte	N03, Gs4, 72
	.byte	W01
	.byte	BEND , 62
	.byte	W01
	.byte	VOL , 58
	.byte	BEND , 54
	.byte	W01
	.byte	VOL , 28
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A44A, 0x2
	.globl sSongHeader_115
sSongHeader_115: @ 0x0886A44C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong115_Part0  @ parts
