.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong229_Part0
sSong229_Part0: @ 0x0886E3E0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 41
	.byte	VOL , 100
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N01, Dn5, 127
	.byte	W01
	.byte	Gn4
	.byte	W01
	.byte	N09, En5
	.byte	W02
	.byte	PAN , 70
	.byte	W02
	.byte	VOL , 92
	.byte	PAN , 56
	.byte	W01
	.byte	VOL , 83
	.byte	PAN , 70
	.byte	W01
	.byte	VOL , 71
	.byte	PAN , 56
	.byte	BEND , 60
	.byte	W01
	.byte	VOL , 46
	.byte	PAN , 75
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 22
	.byte	PAN , 52
	.byte	BEND , 49
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86E41A, 0x2
	.globl sSongHeader_229
sSongHeader_229: @ 0x0886E41C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong229_Part0  @ parts
