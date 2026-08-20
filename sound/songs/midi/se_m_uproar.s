.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong241_Part0
sSong241_Part0: @ 0x0886EE2C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 60
	.byte	BENDR , 12
	.byte	VOL , 25
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N24, Gs2, 127
	.byte	W01
	.byte	PAN , 66
	.byte	VOL , 51
	.byte	W01
	.byte	PAN , 69
	.byte	VOL , 74
	.byte	W01
	.byte	89
	.byte	BEND , 65
	.byte	W01
	.byte	PAN , 66
	.byte	VOL , 100
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	62
	.byte	BEND , 68
	.byte	W01
	.byte	PAN , 60
	.byte	W02
	.byte	62
	.byte	BEND , 69
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	66
	.byte	W01
	.byte	69
	.byte	W02
	.byte	66
	.byte	W02
	.byte	64
	.byte	W01
	.byte	VOL , 85
	.byte	PAN , 62
	.byte	W01
	.byte	60
	.byte	VOL , 62
	.byte	W01
	.byte	33
	.byte	W01
	.byte	PAN , 62
	.byte	VOL , 11
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86EE7B, 0x1
	.globl sSongHeader_241
sSongHeader_241: @ 0x0886EE7C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong241_Part0  @ parts
