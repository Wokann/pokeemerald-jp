.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong3_Part0
sSong3_Part0: @ 0x08868438
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 6
	.byte	VOL , 100
	.byte	BEND , 56
	.byte	N04, Cn3, 112
	.byte	W04
	.byte	Cn2
	.byte	W02
	.byte	W02
	.byte	Cn1
	.byte	W04
	.byte	Cn1, 24
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86844F, 0x1
	.globl sSongHeader_3
sSongHeader_3: @ 0x08868450
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong3_Part0  @ parts
