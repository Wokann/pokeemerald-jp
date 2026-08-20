.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong262_Part0
sSong262_Part0: @ 0x0886F994
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 92
	.byte	BENDR , 12
	.byte	VOL , 127
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
	.incbin "baserom_jp.gba", 0x86F9B7, 0x1
	.globl sSongHeader_262
sSongHeader_262: @ 0x0886F9B8
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong262_Part0  @ parts
