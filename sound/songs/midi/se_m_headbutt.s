.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong162_Part0
sSong162_Part0: @ 0x0886B8B4
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 25
	.byte	BEND , 16
	.byte	N07, Cn1, 127
	.byte	W01
	.byte	VOL , 41
	.byte	BEND , 33
	.byte	W01
	.byte	PAN , 71
	.byte	VOL , 57
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 79
	.byte	BEND , 64
	.byte	W01
	.byte	PAN , 75
	.byte	VOL , 110
	.byte	BEND , 78
	.byte	W02
	.byte	96
	.byte	W01
	.byte	PAN , 78
	.byte	W01
	.byte	VOL , 25
	.byte	BEND , 16
	.byte	N07, Dn1
	.byte	W01
	.byte	PAN , 83
	.byte	VOL , 41
	.byte	BEND , 33
	.byte	W01
	.byte	VOL , 57
	.byte	BEND , 48
	.byte	W02
	.byte	PAN , 64
	.byte	VOL , 79
	.byte	BEND , 64
	.byte	W01
	.byte	VOL , 110
	.byte	BEND , 78
	.byte	W01
	.byte	PAN , 56
	.byte	BEND , 96
	.byte	W02
	.byte	PAN , 53
	.byte	W03
	.byte	49
	.byte	W05
	.byte	VOL , 110
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B90F, 0x1
	.globl sSongHeader_162
sSongHeader_162: @ 0x0886B910
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong162_Part0  @ parts
