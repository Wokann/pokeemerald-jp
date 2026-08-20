.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong390_Part0
sSong390_Part0: @ 0x08881A64
	.byte	KEYSH , 0
	.byte	TEMPO , 72
	.byte	W09
	.byte	VOICE , 56
	.byte	VOL , 90
	.byte	PAN , 70
	.byte	N03, Cs3, 84
	.byte	W03
	.byte	Fn3
	.byte	W03
	.byte	Fs3
	.byte	W03
	.byte	Gs3
	.byte	W03
	.byte	An3
	.byte	W03
	.byte	N06, As3, 112
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Fs3
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12, Cs4
	.byte	W03
	.byte	MOD , 6
	.byte	W09
	.byte	0
	.byte	N06, En4
	.byte	W06
	.byte	Fn4
	.byte	W06
	.byte	N12, Fs4
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong390_Part1
sSong390_Part1: @ 0x08881A9B
	.byte	KEYSH , 0
	.byte	W24
	.byte	VOICE , 60
	.byte	VOL , 90
	.byte	PAN , 48
	.byte	N24, Fs2, 80
	.byte	W24
	.byte	N06
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N12, Fs3
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	As3
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong390_Part2
sSong390_Part2: @ 0x08881AB7
	.byte	KEYSH , 0
	.byte	W24
	.byte	VOICE , 47
	.byte	VOL , 90
	.byte	PAN , 60
	.byte	W48
	.byte	N03, Ds2, 120
	.byte	W03
	.byte	Ds2, 92
	.byte	W03
	.byte	Ds2, 96
	.byte	W03
	.byte	Ds2, 100
	.byte	W03
	.byte	N06, Ds2, 108
	.byte	W06
	.byte	Ds2, 116
	.byte	W06
	.byte	N24, Fs2, 120
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong390_Part3
sSong390_Part3: @ 0x08881ADB
	.byte	KEYSH , 0
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	W24
	.byte	VOICE , 90
	.byte	VOL , 90
	.byte	PAN , 64
	.byte	N03, Fs5, 40
	.byte	W12
	.byte	Cs5
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	Fs5
	.byte	W12
	.byte	Cs5
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W12
	.byte	En5
	.byte	W06
	.byte	Fn5
	.byte	W06
	.byte	Fs5
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong390_Part4
sSong390_Part4: @ 0x08881B01
	.byte	KEYSH , 0
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	BEND , 64
	.byte	W24
	.byte	VOICE , 83
	.byte	VOL , 90
	.byte	PAN , 112
	.byte	N06, Fs3, 52
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N06, Cs3
	.byte	W12
	.byte	N03
	.byte	W06
	.byte	N03
	.byte	W06
	.byte	N12, Fs4
	.byte	W03
	.byte	MOD , 6
	.byte	W09
	.byte	0
	.byte	N06, Gs4
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	N12, As4
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong390_Part5
sSong390_Part5: @ 0x08881B31
	.byte	KEYSH , 0
	.byte	W24
	.byte	VOICE , 88
	.byte	VOL , 90
	.byte	N12, Fs1, 80
	.byte	W24
	.byte	N12
	.byte	W24
	.byte	N12
	.byte	W12
	.byte	N06, En1
	.byte	W06
	.byte	Fn1
	.byte	W06
	.byte	N12, Fs1
	.byte	W24
	.byte	W24
	.byte	FINE
	.globl sSong390_Part6
sSong390_Part6: @ 0x08881B4A
	.byte	KEYSH , 0
	.byte	W24
	.byte	VOICE , 0
	.byte	VOL , 90
	.byte	N06, En1, 100
	.byte	N72, Bn2, 92
	.byte	W24
	.byte	N06, En1, 100
	.byte	W12
	.byte	N06
	.byte	W06
	.byte	N06
	.byte	W06
	.byte	N03, En1, 112
	.byte	W03
	.byte	En1, 80
	.byte	W03
	.byte	En1, 84
	.byte	W03
	.byte	En1, 92
	.byte	W03
	.byte	N06, En1, 96
	.byte	W06
	.byte	En1, 108
	.byte	W06
	.byte	N09, En1, 100
	.byte	N24, Bn2, 92
	.byte	W24
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x881B7D, 0x3
	.globl sSongHeader_390
sSongHeader_390: @ 0x08881B80
	.byte 0x07, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_085FF648  @ tone
	.4byte 0x08881A64, 0x08881A9B, 0x08881AB7, 0x08881ADB, 0x08881B01, 0x08881B31, 0x08881B4A  @ parts
