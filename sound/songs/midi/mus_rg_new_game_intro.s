.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong536_Part0
sSong536_Part0: @ 0x088FDD04
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 56
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	PAN , 87
	.byte	VOL , 67
	.byte	W96
	.byte	W96
	.byte	N06, Gn3, 120
	.byte	W96
	.byte	W72
	.byte	N24, Fs3
	.byte	W24
	.byte	N06, Gn3
	.byte	W96
	.byte	W96
	.byte	GOTO , 6, 221
	.byte	W15
	.byte	GsM2
	.byte	FINE
	.globl sSong536_Part1
sSong536_Part1: @ 0x088FDD26
	.byte	KEYSH , 0
	.byte	VOICE , 58
	.byte	BENDR , 12
	.byte	LFOS , 44
	.byte	VOL , 88
	.byte	PAN , 64
	.byte	N12, Gn1, 120
	.byte	W36
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W48
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W24
	.byte	N24, Fs1
	.byte	W24
	.byte	N12, Gn1, 120
	.byte	W36
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W48
	.byte	PEND
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W24
	.byte	N24, Dn1
	.byte	W24
	.byte	PATT , 73, 221
	.byte	W15
	.byte	GsM2
	.byte	N06, Gn1, 120
	.byte	W12
	.byte	N06
	.byte	W18
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N12
	.byte	W24
	.byte	N24, Dn1
	.byte	W24
	.byte	GOTO , 40, 221
	.byte	W15
	.byte	GsM2
	.byte	FINE
	.globl sSong536_Part2
sSong536_Part2: @ 0x088FDD7B
	.byte	KEYSH , 0
	.byte	VOICE , 48
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	PAN , 48
	.byte	VOL , 70
	.byte	W96
	.byte	W96
	.byte	N06, Bn2, 120
	.byte	W96
	.byte	W72
	.byte	N24, As2
	.byte	W24
	.byte	N06, Bn2
	.byte	W96
	.byte	W96
	.byte	GOTO , 125, 221
	.byte	W15
	.byte	GsM2
	.byte	FINE
	.globl sSong536_Part3
sSong536_Part3: @ 0x088FDD9B
	.byte	KEYSH , 0
	.byte	VOICE , 47
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 86
	.byte	PAN , 64
	.byte	N12, Gn2, 120
	.byte	W96
	.byte	W96
	.byte	N12
	.byte	W96
	.byte	W96
	.byte	N12
	.byte	W96
	.byte	W96
	.byte	GOTO , 157, 221
	.byte	W15
	.byte	GsM2
	.byte	FINE
	.globl sSong536_Part4
sSong536_Part4: @ 0x088FDDB8
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	VOL , 50
	.byte	PAN , 64
	.byte	N12, Gn1, 120
	.byte	W36
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W48
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W24
	.byte	N24, Fs1
	.byte	W24
	.byte	N12, Gn1, 120
	.byte	W36
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12
	.byte	W48
	.byte	PEND
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W24
	.byte	N24, Dn1
	.byte	W24
	.byte	PATT , 224, 221
	.byte	W15
	.byte	GsM2
	.byte	N06, Gn1, 120
	.byte	W12
	.byte	N06
	.byte	W18
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N12
	.byte	W24
	.byte	N24, Dn1
	.byte	W24
	.byte	GOTO , 186, 221
	.byte	W15
	.byte	GsM2
	.byte	FINE
	.globl sSong536_Part5
sSong536_Part5: @ 0x088FDE12
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 85
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
	.byte	N06, En1, 120
	.byte	W12
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N12
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
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N06
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
	.byte	PATT , 88, 222
	.byte	W15
	.byte	GsM2
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
	.byte	GOTO , 20, 222
	.byte	W15
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8FDEC7, 0x1
	.globl sSongHeader_536
sSongHeader_536: @ 0x088FDEC8
	.byte 0x06, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte 0x086390E0  @ tone
	.4byte sSong536_Part0, sSong536_Part1, sSong536_Part2, sSong536_Part3, sSong536_Part4, sSong536_Part5  @ parts
