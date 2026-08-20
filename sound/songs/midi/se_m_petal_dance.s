.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong202_Part0
sSong202_Part0: @ 0x0886CEAC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 46
	.byte	VOL , 95
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	W03
	.byte	N06, Dn6, 112
	.byte	W03
	.byte	W03
	.byte	An5, 104
	.byte	W03
	.byte	W03
	.byte	Dn6, 100
	.byte	W03
	.byte	W03
	.byte	An5
	.byte	W03
	.byte	W03
	.byte	PAN , 60
	.byte	N06, Dn6, 96
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 92
	.byte	W03
	.byte	W03
	.byte	PAN , 68
	.byte	N06, Dn6, 88
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 84
	.byte	W03
	.byte	W03
	.byte	PAN , 60
	.byte	N06, Dn6, 80
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 76
	.byte	W03
	.byte	W03
	.byte	PAN , 68
	.byte	N06, Dn6
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 72
	.byte	W03
	.byte	W03
	.byte	PAN , 60
	.byte	N06, Dn6, 68
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 64
	.byte	W03
	.byte	W03
	.byte	PAN , 68
	.byte	N06, Dn6, 60
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 56
	.byte	W03
	.byte	W03
	.byte	PAN , 56
	.byte	N06, Dn6, 52
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 48
	.byte	W03
	.byte	W03
	.byte	PAN , 72
	.byte	N06, Dn6, 44
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 40
	.byte	W03
	.byte	W03
	.byte	PAN , 56
	.byte	N06, Dn6, 36
	.byte	W03
	.byte	W03
	.byte	PAN , 64
	.byte	N06, An5, 32
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong202_Part1
sSong202_Part1: @ 0x0886CF49
	.byte	KEYSH , 0
	.byte	VOICE , 53
	.byte	BENDR , 2
	.byte	VOL , 43
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	N06, En6, 108
	.byte	W03
	.byte	W03
	.byte	Bn5, 104
	.byte	W03
	.byte	W03
	.byte	En6, 100
	.byte	W03
	.byte	W03
	.byte	Bn5, 96
	.byte	W03
	.byte	W03
	.byte	En6, 92
	.byte	W03
	.byte	W03
	.byte	Bn5, 88
	.byte	W03
	.byte	W03
	.byte	En6
	.byte	W03
	.byte	W03
	.byte	Bn5, 84
	.byte	W03
	.byte	W03
	.byte	En6, 80
	.byte	W03
	.byte	W03
	.byte	Bn5, 76
	.byte	W03
	.byte	W03
	.byte	En6, 72
	.byte	W03
	.byte	W03
	.byte	Bn5, 68
	.byte	W03
	.byte	W03
	.byte	En6, 64
	.byte	W03
	.byte	W03
	.byte	Bn5
	.byte	W03
	.byte	W03
	.byte	En6, 60
	.byte	W03
	.byte	W03
	.byte	Bn5, 56
	.byte	W03
	.byte	W03
	.byte	En6, 52
	.byte	W03
	.byte	W03
	.byte	Bn5, 48
	.byte	W03
	.byte	W03
	.byte	En6, 44
	.byte	W03
	.byte	W03
	.byte	Bn5, 40
	.byte	W03
	.byte	W03
	.byte	En6, 36
	.byte	W03
	.byte	W03
	.byte	Bn5, 32
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86CFAE, 0x2
	.globl sSongHeader_202
sSongHeader_202: @ 0x0886CFB0
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886CEAC, 0x0886CF49  @ parts
