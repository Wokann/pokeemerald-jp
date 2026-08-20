.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong35_Part0
sSong35_Part0: @ 0x08868ACC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 122
	.byte	VOL , 100
	.byte	N01, Ds3, 127
	.byte	W02
	.byte	VOICE , 126
	.byte	N01, Gs4
	.byte	W01
	.byte	W03
	.byte	W01
	.byte	Gs4, 88
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868AE3, 0x1
	.globl sSongHeader_35
sSongHeader_35: @ 0x08868AE4
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong35_Part0  @ parts
