.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong249_Part0
sSong249_Part0: @ 0x0886F43C
	.byte	KEYSH , 0
	.byte	TEMPO , 91
	.byte	VOICE , 125
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	PAN , 64
	.byte	VOL , 127
	.byte	BEND , 66
	.byte	N01, Cn4, 127
	.byte	W03
	.byte	VOICE , 124
	.byte	N01, Cn5, 64
	.byte	W21
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F459, 0x3
	.globl sSongHeader_249
sSongHeader_249: @ 0x0886F45C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte sSong249_Part0  @ parts
