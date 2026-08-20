.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong190_Part0
sSong190_Part0: @ 0x0886C7CC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 45
	.byte	VOL , 100
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	BEND , 59
	.byte	N06, Cn3, 112
	.byte	W01
	.byte	BEND , 74
	.byte	W01
	.byte	101
	.byte	W01
	.byte	119
	.byte	W03
	.byte	PAN , 55
	.byte	BEND , 59
	.byte	N06, Cs3, 96
	.byte	W01
	.byte	BEND , 74
	.byte	W01
	.byte	101
	.byte	W01
	.byte	119
	.byte	W03
	.byte	PAN , 71
	.byte	BEND , 59
	.byte	N06, Dn3, 80
	.byte	W01
	.byte	BEND , 74
	.byte	W01
	.byte	101
	.byte	W01
	.byte	119
	.byte	W03
	.byte	PAN , 50
	.byte	BEND , 59
	.byte	N06, Ds3, 60
	.byte	W01
	.byte	BEND , 74
	.byte	W01
	.byte	101
	.byte	W01
	.byte	119
	.byte	W03
	.byte	PAN , 78
	.byte	BEND , 59
	.byte	N06, En3, 40
	.byte	W01
	.byte	BEND , 74
	.byte	W01
	.byte	101
	.byte	W01
	.byte	119
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C822, 0x2
	.globl sSongHeader_190
sSongHeader_190: @ 0x0886C824
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong190_Part0  @ parts
