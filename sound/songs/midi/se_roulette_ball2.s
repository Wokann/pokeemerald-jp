.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong93_Part0
sSong93_Part0: @ 0x08869918
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 63
	.byte	BENDR , 6
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N72, Dn3, 127
	.byte	W06
	.byte	VOL , 107
	.byte	BEND , 61
	.byte	W06
	.byte	VOL , 106
	.byte	BEND , 59
	.byte	W06
	.byte	VOL , 104
	.byte	BEND , 57
	.byte	W06
	.byte	VOL , 102
	.byte	BEND , 54
	.byte	W06
	.byte	VOL , 97
	.byte	BEND , 52
	.byte	W06
	.byte	VOL , 90
	.byte	BEND , 50
	.byte	W06
	.byte	VOL , 73
	.byte	BEND , 45
	.byte	W06
	.byte	VOL , 58
	.byte	BEND , 40
	.byte	W06
	.byte	VOL , 40
	.byte	BEND , 35
	.byte	W06
	.byte	VOL , 25
	.byte	BEND , 29
	.byte	W06
	.byte	VOL , 12
	.byte	BEND , 18
	.byte	W06
	.byte	FINE
	.globl sSongHeader_93
sSongHeader_93: @ 0x08869960
	.byte 0x01, 0x00, 0x02, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong93_Part0  @ parts
