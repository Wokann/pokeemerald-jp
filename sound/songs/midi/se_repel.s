.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong47_Part0
sSong47_Part0: @ 0x08868D94
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 123
	.byte	VOL , 90
	.byte	N03, Cn4, 84
	.byte	W03
	.byte	VOL , 62
	.byte	N32, Gs4
	.byte	W03
	.byte	VOL , 68
	.byte	W03
	.byte	72
	.byte	W03
	.byte	78
	.byte	W03
	.byte	85
	.byte	W03
	.byte	90
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868DB3, 0x1
	.globl sSongHeader_47
sSongHeader_47: @ 0x08868DB4
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong47_Part0  @ parts
