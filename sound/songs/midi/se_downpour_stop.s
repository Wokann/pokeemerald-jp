.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong84_Part0
sSong84_Part0: @ 0x088696C8
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N24, Cn3, 60
	.byte	W03
	.byte	VOL , 96
	.byte	W03
	.byte	93
	.byte	W03
	.byte	90
	.byte	W03
	.byte	85
	.byte	W03
	.byte	81
	.byte	W03
	.byte	73
	.byte	W03
	.byte	62
	.byte	W03
	.byte	55
	.byte	N24
	.byte	W03
	.byte	VOL , 48
	.byte	W03
	.byte	42
	.byte	W03
	.byte	33
	.byte	W03
	.byte	25
	.byte	W03
	.byte	18
	.byte	W03
	.byte	12
	.byte	W03
	.byte	7
	.byte	W03
	.byte	FINE
	.globl sSongHeader_84
sSongHeader_84: @ 0x088696FC
	.byte 0x01, 0x00, 0x02, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong84_Part0  @ parts
