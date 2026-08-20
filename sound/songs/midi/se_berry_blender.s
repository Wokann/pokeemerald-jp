.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong53_Part0
sSong53_Part0: @ 0x08868F84
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 15
	.byte	VOL , 90
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	TIE , 55, 100
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	EOT
	.byte	GOTO , 134, 143
	.byte	W06
	.byte	GsM2
	.byte	W48
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868F9E, 0x2
	.globl sSongHeader_53
sSongHeader_53: @ 0x08868FA0
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong53_Part0  @ parts
