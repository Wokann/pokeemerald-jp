.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong5_Part0
sSong5_Part0: @ 0x088684A0
	.byte	KEYSH , 0
	.byte	TEMPO , 150
	.byte	VOICE , 87
	.byte	VOL , 80
	.byte	BEND , 77
	.byte	N03, As5, 68
	.byte	W03
	.byte	Gn6, 127
	.byte	W03
	.byte	Gn6, 68
	.byte	W03
	.byte	Gn6, 127
	.byte	W03
	.byte	VOICE , 88
	.byte	N06, Gn6, 68
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8684BE, 0x2
	.globl sSongHeader_5
sSongHeader_5: @ 0x088684C0
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong5_Part0  @ parts
