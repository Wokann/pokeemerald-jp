.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong48_Part0
sSong48_Part0: @ 0x08868DC0
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 9
	.byte	VOL , 90
	.byte	BEND , 64
	.byte	N03, Gn4, 112
	.byte	W03
	.byte	Dn4
	.byte	W03
	.byte	Gn4
	.byte	W03
	.byte	N21, Gn5
	.byte	W03
	.byte	W03
	.byte	VOL , 81
	.byte	BEND , 70
	.byte	W03
	.byte	VOL , 72
	.byte	BEND , 84
	.byte	W03
	.byte	VOL , 46
	.byte	BEND , 101
	.byte	W03
	.byte	VOL , 24
	.byte	BEND , 127
	.byte	W03
	.byte	VOL , 7
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868DEE, 0x2
	.globl sSongHeader_48
sSongHeader_48: @ 0x08868DF0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong48_Part0  @ parts
