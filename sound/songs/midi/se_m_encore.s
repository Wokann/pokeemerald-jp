.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong222_Part0
sSong222_Part0: @ 0x0886DF74
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 59
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N06, En3, 127
	.byte	W01
	.byte	PAN , 72
	.byte	W01
	.byte	55
	.byte	W01
	.byte	78
	.byte	W01
	.byte	54
	.byte	W02
	.byte	64
	.byte	N03, An3, 48
	.byte	W01
	.byte	PAN , 80
	.byte	W01
	.byte	48
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86DF9A, 0x2
	.globl sSongHeader_222
sSongHeader_222: @ 0x0886DF9C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong222_Part0  @ parts
