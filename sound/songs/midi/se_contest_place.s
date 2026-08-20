.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong24_Part0
sSong24_Part0: @ 0x088688AC
	.byte	KEYSH , 0
	.byte	TEMPO , 72
	.byte	VOICE , 80
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	W06
	.byte	N06, Cn3, 112
	.byte	W06
	.byte	N15, Gn3
	.byte	W12
	.byte	W03
	.byte	PAN , 16
	.byte	N09, Gn3, 24
	.byte	W09
	.byte	FINE
	.globl sSong24_Part1
sSong24_Part1: @ 0x088688C6
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	W06
	.byte	N06, Gn2, 112
	.byte	W06
	.byte	N15, Cn3
	.byte	W12
	.byte	W03
	.byte	PAN , 112
	.byte	N09, Cn3, 24
	.byte	W09
	.byte	FINE
	.globl sSong24_Part2
sSong24_Part2: @ 0x088688DE
	.byte	KEYSH , 0
	.byte	VOICE , 47
	.byte	VOL , 110
	.byte	N06, Cn3, 24
	.byte	W06
	.byte	Cn2, 127
	.byte	W06
	.byte	N15, Gn2
	.byte	W12
	.byte	W12
	.byte	FINE
	.globl sSongHeader_24
sSongHeader_24: @ 0x088688F0
	.byte 0x03, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x088688AC, 0x088688C6, 0x088688DE  @ parts
