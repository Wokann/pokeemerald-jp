.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong7_Part0
sSong7_Part0: @ 0x088684E8
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 89
	.byte	VOL , 80
	.byte	BEND , 64
	.byte	N18, Gn1, 127
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8684F7, 0x1
	.globl sSongHeader_7
sSongHeader_7: @ 0x088684F8
	.byte 0x01, 0x00, 0x02, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong7_Part0  @ parts
