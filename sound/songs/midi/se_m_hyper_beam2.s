.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong247_Part0
sSong247_Part0: @ 0x0886F360
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 45
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, Gn3, 92
	.byte	W01
	.byte	BEND , 75
	.byte	W01
	.byte	92
	.byte	W01
	.byte	64
	.byte	N02, Cs4
	.byte	W01
	.byte	BEND , 94
	.byte	W02
	.byte	64
	.byte	N03, As3
	.byte	W01
	.byte	BEND , 75
	.byte	W01
	.byte	92
	.byte	W01
	.byte	64
	.byte	N02, En4
	.byte	W01
	.byte	BEND , 94
	.byte	W02
	.byte	PAN , 71
	.byte	BEND , 64
	.byte	N03, Gn3, 40
	.byte	W01
	.byte	BEND , 75
	.byte	W01
	.byte	92
	.byte	W01
	.byte	64
	.byte	N02, Cs4
	.byte	W01
	.byte	BEND , 94
	.byte	W02
	.byte	PAN , 57
	.byte	BEND , 64
	.byte	N03, As3, 16
	.byte	W01
	.byte	BEND , 75
	.byte	W01
	.byte	92
	.byte	W01
	.byte	64
	.byte	N02, En4
	.byte	W01
	.byte	BEND , 94
	.byte	W02
	.byte	FINE
	.globl sSong247_Part1
sSong247_Part1: @ 0x0886F3B7
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 110
	.byte	N01, Cn3, 32
	.byte	W02
	.byte	N01
	.byte	W04
	.byte	N01
	.byte	W02
	.byte	N01
	.byte	W04
	.byte	N01, Cn3, 20
	.byte	W02
	.byte	N01
	.byte	W04
	.byte	PEND
	.byte	PATT , 199, 243
	.byte	W06
	.byte	GsM2
	.byte	FINE
	.globl sSongHeader_247
sSongHeader_247: @ 0x0886F3D4
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886F360, 0x0886F3B7  @ parts
