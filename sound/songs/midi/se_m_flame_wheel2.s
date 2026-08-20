.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong145_Part0
sSong145_Part0: @ 0x0886AFC4
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 29
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N48, Cn4, 127
	.byte	W06
	.byte	PAN , 68
	.byte	W03
	.byte	BEND , 66
	.byte	W03
	.byte	PAN , 74
	.byte	W03
	.byte	BEND , 69
	.byte	W03
	.byte	VOL , 98
	.byte	PAN , 68
	.byte	W03
	.byte	BEND , 67
	.byte	W03
	.byte	VOL , 88
	.byte	PAN , 64
	.byte	W03
	.byte	BEND , 59
	.byte	W03
	.byte	VOL , 68
	.byte	PAN , 59
	.byte	W03
	.byte	71
	.byte	BEND , 55
	.byte	W03
	.byte	VOL , 44
	.byte	PAN , 64
	.byte	W03
	.byte	BEND , 49
	.byte	W03
	.byte	VOL , 13
	.byte	BEND , 40
	.byte	W03
	.byte	24
	.byte	W03
	.byte	FINE
	.globl sSong145_Part1
sSong145_Part1: @ 0x0886B00B
	.byte	KEYSH , 0
	.byte	VOICE , 27
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	N48, Gn2, 32
	.byte	W18
	.byte	VOL , 98
	.byte	W06
	.byte	88
	.byte	W06
	.byte	68
	.byte	W06
	.byte	44
	.byte	W06
	.byte	13
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B023, 0x1
	.globl sSongHeader_145
sSongHeader_145: @ 0x0886B024
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886AFC4, 0x0886B00B  @ parts
