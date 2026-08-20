.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong258_Part0
sSong258_Part0: @ 0x0886F73C
	.byte	KEYSH , 0
	.byte	TEMPO , 210
	.byte	VOICE , 24
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 95
	.byte	PAN , 112
	.byte	N04, Dn5, 92
	.byte	W06
	.byte	PAN , 0
	.byte	N04, Dn5, 32
	.byte	W06
	.byte	PAN , 96
	.byte	N04, An4, 96
	.byte	W06
	.byte	PAN , 127
	.byte	N04, An4, 32
	.byte	W06
	.byte	PAN , 96
	.byte	N04, Fs4, 92
	.byte	W06
	.byte	PAN , 0
	.byte	N04, Fs4, 32
	.byte	W06
	.byte	PAN , 80
	.byte	N04, En4, 92
	.byte	W06
	.byte	PAN , 127
	.byte	N04, En4, 32
	.byte	W06
	.byte	PAN , 25
	.byte	N04, Dn4, 96
	.byte	W06
	.byte	PAN , 127
	.byte	N04, Dn4, 32
	.byte	W06
	.byte	PAN , 0
	.byte	N04
	.byte	W06
	.byte	PAN , 127
	.byte	N04, Dn4, 16
	.byte	W06
	.byte	PAN , 0
	.byte	N04, Dn4, 12
	.byte	W06
	.byte	PAN , 127
	.byte	N04, Dn4, 4
	.byte	W18
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F79B, 0x1
	.globl sSongHeader_258
sSongHeader_258: @ 0x0886F79C
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte sSong258_Part0  @ parts
