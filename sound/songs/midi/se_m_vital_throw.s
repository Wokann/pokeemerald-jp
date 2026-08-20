.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong122_Part0
sSong122_Part0: @ 0x0886A6C4
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 22
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 80
	.byte	BEND , 110
	.byte	N09, Cn3, 127
	.byte	W03
	.byte	VOL , 104
	.byte	PAN , 64
	.byte	BEND , 87
	.byte	W03
	.byte	VOL , 93
	.byte	PAN , 48
	.byte	BEND , 49
	.byte	W03
	.byte	VOICE , 21
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N03, Gn4
	.byte	W06
	.byte	PAN , 80
	.byte	N03, Cn5
	.byte	W09
	.byte	FINE
	.globl sSong122_Part1
sSong122_Part1: @ 0x0886A6F3
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 110
	.byte	W09
	.byte	PAN , 72
	.byte	N03, Cn3, 52
	.byte	W06
	.byte	PAN , 57
	.byte	N03
	.byte	W09
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A705, 0x3
	.globl sSongHeader_122
sSongHeader_122: @ 0x0886A708
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886A6C4, 0x0886A6F3  @ parts
