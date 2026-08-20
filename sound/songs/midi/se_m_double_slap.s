.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong134_Part0
sSong134_Part0: @ 0x0886AB48
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	PAN , 73
	.byte	BEND , 64
	.byte	N02, Bn3, 112
	.byte	W04
	.byte	PAN , 55
	.byte	N02, Fn5, 64
	.byte	W02
	.byte	PAN , 64
	.byte	N02, Bn3, 36
	.byte	W03
	.byte	VOICE , 18
	.byte	N02, Cn6, 96
	.byte	W15
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AB6D, 0x3
	.globl sSongHeader_134
sSongHeader_134: @ 0x0886AB70
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong134_Part0  @ parts
