.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong16_Part0
sSong16_Part0: @ 0x088686E4
	.byte	KEYSH , 0
	.byte	TEMPO , 45
	.byte	VOICE , 90
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N09, Cn4, 100
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.globl sSong16_Part1
sSong16_Part1: @ 0x088686F7
	.byte	KEYSH , 0
	.byte	VOICE , 124
	.byte	BENDR , 12
	.byte	VOL , 82
	.byte	BEND , 64
	.byte	N05, Gs4, 60
	.byte	W03
	.byte	VOL , 94
	.byte	W03
	.byte	103
	.byte	N22
	.byte	W03
	.byte	VOL , 110
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.globl sSong16_Part2
sSong16_Part2: @ 0x08868712
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 110
	.byte	N06, Cn3, 80
	.byte	W06
	.byte	N18, Cn3, 92
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.globl sSongHeader_16
sSongHeader_16: @ 0x08868724
	.byte 0x03, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x088686E4, 0x088686F7, 0x08868712  @ parts
