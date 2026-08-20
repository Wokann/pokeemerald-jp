.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong199_Part0
sSong199_Part0: @ 0x0886CC20
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N03, Gn2, 127
	.byte	W02
	.byte	PAN , 67
	.byte	BEND , 66
	.byte	W01
	.byte	VOICE , 23
	.byte	N02, Cn3, 104
	.byte	W01
	.byte	PAN , 61
	.byte	BEND , 69
	.byte	W02
	.byte	VOICE , 36
	.byte	N02, Cn2, 127
	.byte	W01
	.byte	PAN , 71
	.byte	W01
	.byte	VOICE , 23
	.byte	BEND , 68
	.byte	N06, Cn3, 104
	.byte	W01
	.byte	PAN , 58
	.byte	BEND , 64
	.byte	W01
	.byte	59
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 52
	.byte	W01
	.byte	41
	.byte	W01
	.byte	VOICE , 36
	.byte	BEND , 64
	.byte	N03, An2, 100
	.byte	W04
	.byte	PAN , 69
	.byte	N03, Bn2, 76
	.byte	W03
	.byte	PAN , 58
	.byte	N02, Cs3, 40
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86CC76, 0x2
	.globl sSongHeader_199
sSongHeader_199: @ 0x0886CC78
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong199_Part0  @ parts
