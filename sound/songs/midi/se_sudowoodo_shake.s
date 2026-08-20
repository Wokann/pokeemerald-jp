.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

sSong269_Part0: @ 0x886FCF4
.byte	KEYSH , 0
.byte	TEMPO , 50
.byte	VOICE , 127
.byte	PAN , 64
.byte	VOL , 77
.byte	N03, Cn5, 96
.byte	W06
.byte	N01, Gn5, 64
.byte	W06
.byte	N03, Cn5, 100
.byte	W06
.byte	N01, Gn5, 64
.byte	W06
.byte	N03, Cn5, 96
.byte	W06
.byte	N01, Gn5, 64
.byte	W06
.byte	PEND
.byte	PATT , 14, 253
.byte	W06
.byte	8
.byte	FINE
.byte	0, 0, 0
	.globl sSongHeader_269
sSongHeader_269: @ 0x0886FD20
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte sSong269_Part0  @ parts
