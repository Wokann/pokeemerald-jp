.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong255_Part0
sSong255_Part0: @ 0x0886F5EC
	.byte	KEYSH , 0
	.byte	TEMPO , 62
	.byte	VOICE , 8
	.byte	VOL , 80
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N30, Cn3, 120
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F601, 0x3
	.globl sSongHeader_255
sSongHeader_255: @ 0x0886F604
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte sSong255_Part0  @ parts
