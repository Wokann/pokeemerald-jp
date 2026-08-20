.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong535_Part0
sSong535_Part0: @ 0x088FDC90
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 0
	.byte	VOL , 85
	.byte	N03, En1, 48
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N06, En1, 120
	.byte	W12
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	En1, 84
	.byte	W06
	.byte	En1, 120
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	N03
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
	.byte	PEND
	.byte	N06, En1, 120
	.byte	W12
	.byte	N06
	.byte	W18
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	En1, 84
	.byte	W06
	.byte	En1, 120
	.byte	W12
	.byte	N03
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
	.byte	PEND
	.byte	PATT , 162, 220
	.byte	W15
	.byte	GsM2
	.byte	PATT , 196, 220
	.byte	W15
	.byte	GsM2
	.byte	GOTO , 162, 220
	.byte	W15
	.byte	GsM2
	.byte	FINE
	.globl sSongHeader_535
sSongHeader_535: @ 0x088FDCF8
	.byte 0x01, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte 0x086390E0  @ tone
	.4byte sSong535_Part0  @ parts
