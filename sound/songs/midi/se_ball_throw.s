.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong61_Part0
sSong61_Part0: @ 0x08869170
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	VOL , 120
	.byte	BEND , 76
	.byte	N06, An2, 127
	.byte	W03
	.byte	VOL , 78
	.byte	BEND , 84
	.byte	W03
	.byte	VOL , 120
	.byte	BEND , 100
	.byte	N18, Cn3
	.byte	W02
	.byte	BEND , 99
	.byte	W03
	.byte	96
	.byte	W02
	.byte	90
	.byte	W03
	.byte	VOL , 102
	.byte	BEND , 82
	.byte	W02
	.byte	VOL , 68
	.byte	BEND , 71
	.byte	W03
	.byte	VOL , 34
	.byte	BEND , 55
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8691A3, 0x1
	.globl sSongHeader_61
sSongHeader_61: @ 0x088691A4
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong61_Part0  @ parts
