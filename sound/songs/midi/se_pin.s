.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong21_Part0
sSong21_Part0: @ 0x08868838
	.byte	KEYSH , 0
	.byte	TEMPO , 50
	.byte	VOICE , 5
	.byte	BENDR , 12
	.byte	VOL , 60
	.byte	BEND , 64
	.byte	N03, Gn5, 127
	.byte	W03
	.byte	Gn6, 112
	.byte	W03
	.byte	Gn6, 24
	.byte	W03
	.byte	Gn6, 68
	.byte	W03
	.byte	Gn6, 24
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868855, 0x3
	.globl sSongHeader_21
sSongHeader_21: @ 0x08868858
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong21_Part0  @ parts
