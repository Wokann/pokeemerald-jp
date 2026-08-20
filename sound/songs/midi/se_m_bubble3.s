.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong126_Part0
sSong126_Part0: @ 0x0886A804
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 23
	.byte	VOL , 95
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N12, Gn2, 127
	.byte	W06
	.byte	PAN , 47
	.byte	BEND , 70
	.byte	W01
	.byte	80
	.byte	W02
	.byte	PAN , 80
	.byte	BEND , 89
	.byte	W01
	.byte	95
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 63
	.byte	W03
	.byte	N06
	.byte	W03
	.byte	BEND , 70
	.byte	W01
	.byte	77
	.byte	W05
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A831, 0x3
	.globl sSongHeader_126
sSongHeader_126: @ 0x0886A834
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong126_Part0  @ parts
