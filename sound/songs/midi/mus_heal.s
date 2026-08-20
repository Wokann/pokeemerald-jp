.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong368_Part0
sSong368_Part0: @ 0x08879EB8
	.byte	KEYSH , 0
	.byte	TEMPO , 66
	.byte	VOICE , 46
	.byte	VOL , 90
	.byte	PAN , 64
	.byte	N12, Bn4, 112
	.byte	W12
	.byte	N06, Bn4, 52
	.byte	W12
	.byte	N12, Bn4, 112
	.byte	W12
	.byte	N06, Bn4, 52
	.byte	W12
	.byte	N12, Bn4, 112
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	En5
	.byte	W12
	.byte	N06, En5, 52
	.byte	W12
	.byte	W24
	.byte	FINE
	.globl sSong368_Part1
sSong368_Part1: @ 0x08879EE0
	.byte	KEYSH , 0
	.byte	VOICE , 46
	.byte	VOL , 90
	.byte	PAN , 112
	.byte	N06, En4, 80
	.byte	W12
	.byte	En4, 20
	.byte	W12
	.byte	En4, 80
	.byte	W12
	.byte	En4, 20
	.byte	W12
	.byte	En4, 80
	.byte	W12
	.byte	En4, 20
	.byte	W12
	.byte	Bn4, 80
	.byte	W12
	.byte	Bn4, 20
	.byte	W12
	.byte	W24
	.byte	FINE
	.globl sSong368_Part2
sSong368_Part2: @ 0x08879F03
	.byte	KEYSH , 0
	.byte	VOICE , 46
	.byte	VOL , 90
	.byte	PAN , 17
	.byte	W12
	.byte	N06, Gs3, 80
	.byte	W12
	.byte	Gs3, 24
	.byte	W12
	.byte	Gs3, 80
	.byte	W12
	.byte	Gs3, 24
	.byte	W12
	.byte	Gs3, 80
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	En3, 24
	.byte	W12
	.byte	W24
	.byte	FINE
	.globl sSong368_Part3
sSong368_Part3: @ 0x08879F23
	.byte	VOL , 90
	.byte	KEYSH , 0
	.byte	VOICE , 100
	.byte	PAN , 64
	.byte	W12
	.byte	N03, En5, 80
	.byte	W06
	.byte	PAN , 16
	.byte	N03, En5, 24
	.byte	W06
	.byte	PAN , 64
	.byte	N03, En5, 80
	.byte	W06
	.byte	PAN , 112
	.byte	N03, En5, 24
	.byte	W06
	.byte	VOICE , 101
	.byte	PAN , 64
	.byte	N03, En4, 80
	.byte	W06
	.byte	PAN , 16
	.byte	N03, En4, 24
	.byte	W30
	.byte	VOICE , 100
	.byte	PAN , 64
	.byte	N03, En5, 80
	.byte	W06
	.byte	PAN , 112
	.byte	N03, En5, 24
	.byte	W18
	.byte	PAN , 64
	.byte	N03, En5, 72
	.byte	W06
	.byte	En5, 28
	.byte	W18
	.byte	FINE
	.globl sSongHeader_368
sSongHeader_368: @ 0x08879F68
	.byte 0x04, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_085FF648  @ tone
	.4byte 0x08879EB8, 0x08879EE0, 0x08879F03, 0x08879F23  @ parts
