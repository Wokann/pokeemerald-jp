.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong378_Part0
sSong378_Part0: @ 0x0887D480
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	W12
	.byte	VOICE , 13
	.byte	VOL , 90
	.byte	N06, En3, 68
	.byte	W06
	.byte	Bn3
	.byte	W06
	.byte	En4
	.byte	W06
	.byte	Bn4
	.byte	W06
	.byte	N12, Ds5, 88
	.byte	W09
	.byte	Cn5
	.byte	W12
	.byte	As4
	.byte	W12
	.byte	Gn4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	N06, En5
	.byte	W12
	.byte	N12
	.byte	W24
	.byte	W03
	.byte	W24
	.byte	FINE
	.globl sSong378_Part1
sSong378_Part1: @ 0x0887D4A7
	.byte	KEYSH , 0
	.byte	W12
	.byte	VOICE , 13
	.byte	VOL , 90
	.byte	W03
	.byte	N06, Gs3, 68
	.byte	W06
	.byte	Cs4
	.byte	W06
	.byte	Gs4
	.byte	W06
	.byte	Cs5
	.byte	W03
	.byte	W03
	.byte	N12, En5, 88
	.byte	W09
	.byte	Cs5
	.byte	W12
	.byte	Bn4
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	N06, En5
	.byte	W12
	.byte	N12
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong378_Part2
sSong378_Part2: @ 0x0887D4CD
	.byte	KEYSH , 0
	.byte	W12
	.byte	BEND , 65
	.byte	W24
	.byte	VOICE , 13
	.byte	VOL , 90
	.byte	PAN , 16
	.byte	W12
	.byte	N12, En5, 12
	.byte	W09
	.byte	Cs5
	.byte	W12
	.byte	Bn4
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	N06, En5
	.byte	W12
	.byte	N12
	.byte	W15
	.byte	W24
	.byte	FINE
	.globl sSong378_Part3
sSong378_Part3: @ 0x0887D4ED
	.byte	KEYSH , 0
	.byte	W12
	.byte	BEND , 62
	.byte	W24
	.byte	VOICE , 13
	.byte	VOL , 90
	.byte	PAN , 112
	.byte	W24
	.byte	N12, En5, 12
	.byte	W09
	.byte	Cs5
	.byte	W12
	.byte	Bn4
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	N06, En5
	.byte	W12
	.byte	N12
	.byte	W03
	.byte	W24
	.byte	FINE
	.globl sSong378_Part4
sSong378_Part4: @ 0x0887D50D
	.byte	KEYSH , 0
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	W12
	.byte	VOICE , 84
	.byte	VOL , 90
	.byte	W21
	.byte	N12, En2, 72
	.byte	W03
	.byte	W56
	.byte	W01
	.byte	En3
	.byte	W12
	.byte	En4
	.byte	W24
	.byte	W03
	.byte	W24
	.byte	FINE
	.globl sSong378_Part5
sSong378_Part5: @ 0x0887D527
	.byte	KEYSH , 0
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	W12
	.byte	VOICE , 85
	.byte	VOL , 90
	.byte	BEND , 72
	.byte	W24
	.byte	N12, En2, 52
	.byte	W60
	.byte	En3
	.byte	W12
	.byte	En4
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSongHeader_378
sSongHeader_378: @ 0x0887D540
	.byte 0x06, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_085FF648  @ tone
	.4byte 0x0887D480, 0x0887D4A7, 0x0887D4CD, 0x0887D4ED, 0x0887D50D, 0x0887D527  @ parts
