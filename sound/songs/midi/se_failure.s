.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong32_Part0
sSong32_Part0: @ 0x088689E4
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 92
	.byte	BENDR , 12
	.byte	VOL , 120
	.byte	BEND , 64
	.byte	N03, Cn2, 127
	.byte	W03
	.byte	Cn2, 20
	.byte	W03
	.byte	N18, Cn2, 127
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	N09, Cn2, 20
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868A07, 0x1
	.globl sSongHeader_32
sSongHeader_32: @ 0x08868A08
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong32_Part0  @ parts
