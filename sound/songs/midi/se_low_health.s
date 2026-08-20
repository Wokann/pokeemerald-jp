.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong90_Part0
sSong90_Part0: @ 0x0886987C
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 15
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 100
	.byte	BEND , 81
	.byte	N12, Dn4, 80
	.byte	W12
	.byte	BEND , 95
	.byte	N12, An3
	.byte	W12
	.byte	W12
	.byte	GOTO , 126, 152
	.byte	W06
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86989B, 0x1
	.globl sSongHeader_90
sSongHeader_90: @ 0x0886989C
	.byte 0x01, 0x00, 0x03, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong90_Part0  @ parts
