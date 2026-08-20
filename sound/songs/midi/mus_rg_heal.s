.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong493_Part0
sSong493_Part0: @ 0x088DA5B4
	.byte	VOL , 90
	.byte	KEYSH , 0
	.byte	TEMPO , 73
	.byte	VOICE , 2
	.byte	N24, Bn4, 64
	.byte	W24
	.byte	N24
	.byte	W24
	.byte	N12
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	N48, En5
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong493_Part1
sSong493_Part1: @ 0x088DA5CB
	.byte	VOL , 90
	.byte	KEYSH , 0
	.byte	VOICE , 3
	.byte	N12, En2, 92
	.byte	W24
	.byte	N12
	.byte	W24
	.byte	N12
	.byte	W12
	.byte	Gs2
	.byte	W12
	.byte	N36, En2
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSongHeader_493
sSongHeader_493: @ 0x088DA5E0
	.byte 0x02, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte 0x0862BA90  @ tone
	.4byte sSong493_Part0, sSong493_Part1  @ parts
