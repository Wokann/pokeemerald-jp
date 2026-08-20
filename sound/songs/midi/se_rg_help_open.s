.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong257_Part0
sSong257_Part0: @ 0x0886F6CC
	.byte	KEYSH , 0
	.byte	TEMPO , 210
	.byte	VOICE , 24
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 96
	.byte	PAN , 16
	.byte	N04, Dn4, 96
	.byte	W06
	.byte	PAN , 0
	.byte	N04, Dn4, 32
	.byte	W06
	.byte	PAN , 32
	.byte	N04, Fs4, 96
	.byte	W06
	.byte	PAN , 127
	.byte	N04, Fs4, 32
	.byte	W06
	.byte	PAN , 32
	.byte	N04, An4, 96
	.byte	W06
	.byte	PAN , 0
	.byte	N04, An4, 32
	.byte	W06
	.byte	PAN , 48
	.byte	N04, Cs5, 96
	.byte	W06
	.byte	PAN , 127
	.byte	N04, Cs5, 32
	.byte	W06
	.byte	PAN , 96
	.byte	N04, Dn5, 76
	.byte	W06
	.byte	PAN , 0
	.byte	N04, Dn5, 32
	.byte	W06
	.byte	PAN , 127
	.byte	N04, Dn5, 24
	.byte	W06
	.byte	PAN , 0
	.byte	N04, Dn5, 16
	.byte	W06
	.byte	PAN , 127
	.byte	N04, Dn5, 8
	.byte	W06
	.byte	PAN , 0
	.byte	N04, Dn5, 4
	.byte	W18
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F72D, 0x3
	.globl sSongHeader_257
sSongHeader_257: @ 0x0886F730
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte sSong257_Part0  @ parts
