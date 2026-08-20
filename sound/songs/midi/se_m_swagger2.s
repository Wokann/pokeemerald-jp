.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong194_Part0
sSong194_Part0: @ 0x0886CA2C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 56
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 65
	.byte	BEND , 72
	.byte	N01, Cs6, 112
	.byte	W01
	.byte	BEND , 64
	.byte	N01, Dn6, 100
	.byte	W01
	.byte	Dn6, 60
	.byte	W04
	.byte	BEND , 56
	.byte	N01, Ds6, 112
	.byte	W01
	.byte	BEND , 64
	.byte	N01, En6, 100
	.byte	W01
	.byte	En6, 60
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86CA57, 0x1
	.globl sSongHeader_194
sSongHeader_194: @ 0x0886CA58
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong194_Part0  @ parts
