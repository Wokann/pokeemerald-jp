.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong263_Part0
sSong263_Part0: @ 0x0886F9C4
	.byte	KEYSH , 0
	.byte	TEMPO , 68
	.byte	VOICE , 13
	.byte	LFOS , 44
	.byte	BENDR , 12
	.byte	VOL , 120
	.byte	PAN , 48
	.byte	N01, An5, 64
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	An5
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	Fs6
	.byte	W02
	.byte	An5
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	An5
	.byte	W01
	.byte	Fs6
	.byte	W01
	.byte	An5
	.byte	W02
	.byte	N01
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	An5
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	Fs6
	.byte	W02
	.byte	An5
	.byte	W01
	.byte	Dn6
	.byte	W01
	.byte	An5
	.byte	W01
	.byte	Fs6
	.byte	W01
	.byte	An5
	.byte	W02
	.byte	FINE
	.globl sSong263_Part1
sSong263_Part1: @ 0x0886F9FD
	.byte	KEYSH , 0
	.byte	VOICE , 80
	.byte	LFOS , 44
	.byte	XCMD , 8 , 18
	.byte	8 , 16
	.byte	BENDR , 12
	.byte	VOL , 45
	.byte	MOD , 2
	.byte	PAN , 127
	.byte	BEND , 66
	.byte	N01, Dn5, 64
	.byte	W01
	.byte	Fs5
	.byte	W01
	.byte	PAN , 2
	.byte	N01, Dn5
	.byte	W01
	.byte	Fs5
	.byte	W01
	.byte	PAN , 127
	.byte	N01, An5
	.byte	W02
	.byte	Dn5
	.byte	W01
	.byte	PAN , 3
	.byte	N01, Fs5
	.byte	W01
	.byte	Dn5
	.byte	W01
	.byte	PAN , 127
	.byte	N01, An5
	.byte	W01
	.byte	Dn5
	.byte	W02
	.byte	PAN , 3
	.byte	N01
	.byte	W01
	.byte	Fs5
	.byte	W01
	.byte	PAN , 127
	.byte	N01, Dn5
	.byte	W01
	.byte	Fs5
	.byte	W01
	.byte	PAN , 3
	.byte	N01, An5
	.byte	W02
	.byte	Dn5
	.byte	W01
	.byte	PAN , 127
	.byte	N01, Fs5
	.byte	W01
	.byte	Dn5
	.byte	W01
	.byte	PAN , 3
	.byte	N01, An5
	.byte	W01
	.byte	Dn5
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86FA57, 0x1
	.globl sSongHeader_263
sSongHeader_263: @ 0x0886FA58
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886F9C4, 0x0886F9FD  @ parts
