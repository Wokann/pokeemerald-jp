.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong376_Part0
sSong376_Part0: @ 0x0887CE9C
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 47
	.byte	VOL , 80
	.byte	PAN , 56
	.byte	N24, Dn2, 127
	.byte	W48
	.byte	FINE
	.globl sSong376_Part1
sSong376_Part1: @ 0x0887CEAB
	.byte	KEYSH , 0
	.byte	VOICE , 80
	.byte	VOL , 80
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	PAN , 64
	.byte	N06, Gn4, 80
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	Dn4
	.byte	W30
	.byte	FINE
	.globl sSong376_Part2
sSong376_Part2: @ 0x0887CEC3
	.byte	KEYSH , 0
	.byte	VOICE , 82
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 80
	.byte	BEND , 66
	.byte	W06
	.byte	N06, Gn4, 32
	.byte	W06
	.byte	Dn4
	.byte	W06
	.byte	Gn4
	.byte	W06
	.byte	Dn4
	.byte	W24
	.byte	FINE
	.globl sSong376_Part3
sSong376_Part3: @ 0x0887CEDC
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 80
	.byte	PAN , 87
	.byte	N48, Bn2, 100
	.byte	W48
	.byte	FINE
	.incbin "baserom_jp.gba", 0x87CEE9, 0x3
	.globl sSongHeader_376
sSongHeader_376: @ 0x0887CEEC
	.byte 0x04, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08602EC4  @ tone
	.4byte 0x0887CE9C, 0x0887CEAB, 0x0887CEC3, 0x0887CEDC  @ parts
