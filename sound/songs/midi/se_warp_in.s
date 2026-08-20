.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong45_Part0
sSong45_Part0: @ 0x08868D1C
	.byte	KEYSH , 0
	.byte	TEMPO , 55
	.byte	VOICE , 90
	.byte	VOL , 90
	.byte	N06, En4, 127
	.byte	W03
	.byte	W03
	.byte	N03, En4, 16
	.byte	W03
	.byte	N06, En4, 112
	.byte	W03
	.byte	W03
	.byte	N03, En4, 16
	.byte	W03
	.byte	N06, En4, 88
	.byte	W03
	.byte	W03
	.byte	N03, En4, 16
	.byte	W03
	.byte	N06, En4, 64
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868D45, 0x3
	.globl sSongHeader_45
sSongHeader_45: @ 0x08868D48
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong45_Part0  @ parts
