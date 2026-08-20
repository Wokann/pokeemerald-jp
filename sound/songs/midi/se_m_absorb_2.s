.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong179_Part0
sSong179_Part0: @ 0x0886C1A4
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 46
	.byte	VOL , 110
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	BEND , 79
	.byte	W01
	.byte	N02, Dn6, 112
	.byte	W02
	.byte	Cs6
	.byte	W03
	.byte	PAN , 72
	.byte	N02, An5
	.byte	W02
	.byte	Fs5
	.byte	W01
	.byte	W01
	.byte	Dn5
	.byte	W02
	.byte	PAN , 57
	.byte	W01
	.byte	N02, Dn5, 104
	.byte	W02
	.byte	Cs5, 100
	.byte	W03
	.byte	PAN , 64
	.byte	N02, An4, 96
	.byte	W02
	.byte	Fs4, 92
	.byte	W01
	.byte	W01
	.byte	Dn4, 88
	.byte	W02
	.byte	PAN , 79
	.byte	W01
	.byte	N02, Dn6
	.byte	W02
	.byte	Cs6, 84
	.byte	W03
	.byte	An5, 80
	.byte	W02
	.byte	Fs5, 76
	.byte	W01
	.byte	W01
	.byte	Dn5, 72
	.byte	W02
	.byte	PAN , 48
	.byte	W01
	.byte	N02, Dn6, 68
	.byte	W02
	.byte	Cs6, 64
	.byte	W03
	.byte	An5, 60
	.byte	W02
	.byte	Fs5, 56
	.byte	W01
	.byte	W01
	.byte	Dn5, 52
	.byte	W02
	.byte	W03
	.byte	FINE
	.globl sSong179_Part1
sSong179_Part1: @ 0x0886C203
	.byte	KEYSH , 0
	.byte	VOICE , 53
	.byte	BENDR , 2
	.byte	VOL , 43
	.byte	BEND , 79
	.byte	N02, An6, 112
	.byte	W02
	.byte	Fs6
	.byte	W01
	.byte	W01
	.byte	Dn6
	.byte	W02
	.byte	W01
	.byte	Cs6
	.byte	W02
	.byte	An5
	.byte	W03
	.byte	N02
	.byte	W02
	.byte	Fs5, 104
	.byte	W01
	.byte	W01
	.byte	Dn5, 100
	.byte	W02
	.byte	W01
	.byte	Cs5, 96
	.byte	W02
	.byte	An4, 92
	.byte	W03
	.byte	An6, 88
	.byte	W02
	.byte	Fs6, 84
	.byte	W01
	.byte	W01
	.byte	Dn6, 80
	.byte	W02
	.byte	W01
	.byte	Cs6, 76
	.byte	W02
	.byte	An5, 72
	.byte	W03
	.byte	An6, 68
	.byte	W02
	.byte	Fs6, 64
	.byte	W01
	.byte	W01
	.byte	Dn6, 60
	.byte	W02
	.byte	W01
	.byte	Cs6, 56
	.byte	W02
	.byte	An5, 52
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C24F, 0x1
	.globl sSongHeader_179
sSongHeader_179: @ 0x0886C250
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886C1A4, 0x0886C203  @ parts
