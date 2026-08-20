.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong89_Part0
sSong89_Part0: @ 0x0886983C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 38
	.byte	BENDR , 2
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	TIE , 78, 80
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	EOT
	.byte	FINE
	.globl sSong89_Part1
sSong89_Part1: @ 0x08869856
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	VOL , 100
	.byte	TIE , 65, 32
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86986A, 0x2
	.globl sSongHeader_89
sSongHeader_89: @ 0x0886986C
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886983C, 0x08869856  @ parts
