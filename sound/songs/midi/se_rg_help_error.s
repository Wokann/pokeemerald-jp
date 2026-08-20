.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong259_Part0
sSong259_Part0: @ 0x0886F7A8
	.byte	KEYSH , 0
	.byte	TEMPO , 210
	.byte	VOICE , 24
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 96
	.byte	N04, Dn4, 120
	.byte	W06
	.byte	PAN , 0
	.byte	N04, Dn4, 32
	.byte	W06
	.byte	PAN , 63
	.byte	N04, Fs4, 96
	.byte	W06
	.byte	PAN , 127
	.byte	N04, Fs4, 32
	.byte	W06
	.byte	VOICE , 92
	.byte	PAN , 64
	.byte	VOL , 125
	.byte	N04, An1, 112
	.byte	W10
	.byte	MOD , 8
	.byte	W02
	.byte	N06, An1, 88
	.byte	W06
	.byte	An1, 24
	.byte	W06
	.byte	MOD , 0
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F7E3, 0x1
	.globl sSongHeader_259
sSongHeader_259: @ 0x0886F7E4
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte sSong259_Part0  @ parts
