.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong137_Part0
sSong137_Part0: @ 0x0886AC2C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 3
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	N01, Ds4, 112
	.byte	W04
	.byte	PAN , 70
	.byte	N01, Bn4, 40
	.byte	W04
	.byte	PAN , 59
	.byte	N01, Ds4, 112
	.byte	W01
	.byte	PAN , 64
	.byte	N01, Bn4
	.byte	W15
	.byte	FINE
	.globl sSong137_Part1
sSong137_Part1: @ 0x0886AC4C
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	N01, Dn4, 40
	.byte	W04
	.byte	Bn3
	.byte	W02
	.byte	PAN , 57
	.byte	W02
	.byte	73
	.byte	W01
	.byte	N01, Dn4
	.byte	W01
	.byte	PAN , 57
	.byte	W14
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AC66, 0x2
	.globl sSongHeader_137
sSongHeader_137: @ 0x0886AC68
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886AC2C, 0x0886AC4C  @ parts
