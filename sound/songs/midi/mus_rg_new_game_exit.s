.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong537_Part0
sSong537_Part0: @ 0x088FDEE8
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 56
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	PAN , 92
	.byte	VOL , 67
	.byte	W24
	.byte	N06, Gn3, 120
	.byte	W24
	.byte	W48
	.byte	FINE
	.globl sSong537_Part1
sSong537_Part1: @ 0x088FDEFD
	.byte	KEYSH , 0
	.byte	VOICE , 60
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 81
	.byte	W24
	.byte	N06, Bn3, 120
	.byte	W24
	.byte	W48
	.byte	FINE
	.globl sSong537_Part2
sSong537_Part2: @ 0x088FDF10
	.byte	KEYSH , 0
	.byte	VOICE , 58
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	VOL , 88
	.byte	PAN , 64
	.byte	N24, Fs1, 120
	.byte	W48
	.byte	W48
	.byte	FINE
	.globl sSong537_Part3
sSong537_Part3: @ 0x088FDF22
	.byte	KEYSH , 0
	.byte	VOICE , 48
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	PAN , 40
	.byte	VOL , 67
	.byte	W24
	.byte	N06, Bn2, 120
	.byte	W24
	.byte	W48
	.byte	FINE
	.globl sSong537_Part4
sSong537_Part4: @ 0x088FDF35
	.byte	KEYSH , 0
	.byte	VOICE , 47
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 86
	.byte	PAN , 66
	.byte	W24
	.byte	N15, Gn2, 120
	.byte	W24
	.byte	W48
	.byte	FINE
	.globl sSong537_Part5
sSong537_Part5: @ 0x088FDF48
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	VOL , 50
	.byte	PAN , 64
	.byte	N24, Fs1, 120
	.byte	W24
	.byte	N06, Gn1
	.byte	W24
	.byte	W48
	.byte	FINE
	.globl sSong537_Part6
sSong537_Part6: @ 0x088FDF62
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 86
	.byte	N03, En1, 120
	.byte	W03
	.byte	En1, 48
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N06, En1, 120
	.byte	N48, An2, 96
	.byte	W24
	.byte	W48
	.byte	FINE
	.globl sSongHeader_537
sSongHeader_537: @ 0x088FDF84
	.byte 0x07, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte 0x086390E0  @ tone
	.4byte sSong537_Part0, sSong537_Part1, sSong537_Part2, sSong537_Part3, sSong537_Part4, sSong537_Part5, sSong537_Part6  @ parts
