.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong155_Part0
sSong155_Part0: @ 0x0886B4D8
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 18
	.byte	BENDR , 12
	.byte	PAN , 78
	.byte	VOL , 42
	.byte	BEND , 103
	.byte	N10, Gn5, 92
	.byte	W01
	.byte	VOL , 55
	.byte	W01
	.byte	71
	.byte	BEND , 87
	.byte	W01
	.byte	PAN , 49
	.byte	VOL , 86
	.byte	BEND , 64
	.byte	W01
	.byte	VOL , 110
	.byte	BEND , 41
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 30
	.byte	W01
	.byte	9
	.byte	W01
	.byte	0
	.byte	W02
	.byte	VOICE , 21
	.byte	BEND , 127
	.byte	N01, Cn5
	.byte	W02
	.byte	Gn5
	.byte	W02
	.byte	Gn5, 64
	.byte	W10
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B513, 0x1
	.globl sSongHeader_155
sSongHeader_155: @ 0x0886B514
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong155_Part0  @ parts
