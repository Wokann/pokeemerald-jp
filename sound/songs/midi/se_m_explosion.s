.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong178_Part0
sSong178_Part0: @ 0x0886C118
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 41
	.byte	VOL , 125
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N01, Ds3, 127
	.byte	W01
	.byte	As2
	.byte	W02
	.byte	PAN , 56
	.byte	N02, Gn3
	.byte	W01
	.byte	PAN , 71
	.byte	W03
	.byte	64
	.byte	N01, Ds3
	.byte	W01
	.byte	As2
	.byte	W02
	.byte	N54, Fn3
	.byte	W11
	.byte	BEND , 67
	.byte	W03
	.byte	W02
	.byte	PAN , 70
	.byte	BEND , 71
	.byte	W04
	.byte	PAN , 64
	.byte	W01
	.byte	BEND , 74
	.byte	W02
	.byte	PAN , 56
	.byte	W01
	.byte	BEND , 80
	.byte	W03
	.byte	PAN , 64
	.byte	W01
	.byte	BEND , 84
	.byte	W02
	.byte	PAN , 71
	.byte	W02
	.byte	BEND , 89
	.byte	W02
	.byte	PAN , 64
	.byte	W04
	.byte	56
	.byte	BEND , 84
	.byte	W03
	.byte	PAN , 70
	.byte	W01
	.byte	BEND , 74
	.byte	W03
	.byte	PAN , 56
	.byte	W02
	.byte	BEND , 67
	.byte	W01
	.byte	PAN , 71
	.byte	W04
	.byte	56
	.byte	W10
	.byte	FINE
	.globl sSong178_Part1
sSong178_Part1: @ 0x0886C177
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 125
	.byte	PAN , 64
	.byte	BEND , 65
	.byte	N02, Cn3, 52
	.byte	W01
	.byte	VOL , 74
	.byte	W06
	.byte	125
	.byte	N02
	.byte	W01
	.byte	VOL , 74
	.byte	W16
	.byte	W24
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C191, 0x3
	.globl sSongHeader_178
sSongHeader_178: @ 0x0886C194
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886C118, 0x0886C177  @ parts
