.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong198_Part0
sSong198_Part0: @ 0x0886CBA8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 41
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	N01, Cn4, 127
	.byte	W01
	.byte	N03, Cn5
	.byte	W01
	.byte	PAN , 69
	.byte	W01
	.byte	58
	.byte	W01
	.byte	VOICE , 3
	.byte	PAN , 64
	.byte	N01, Gs4, 112
	.byte	W02
	.byte	W03
	.byte	PAN , 71
	.byte	N01, Dn5, 96
	.byte	W03
	.byte	W02
	.byte	PAN , 64
	.byte	N01, Gs4, 84
	.byte	W04
	.byte	W01
	.byte	PAN , 56
	.byte	N01, Dn5, 68
	.byte	W05
	.byte	PAN , 71
	.byte	N01, Gs4, 52
	.byte	W04
	.byte	PAN , 56
	.byte	N01, Dn5, 32
	.byte	W02
	.byte	W06
	.byte	FINE
	.globl sSong198_Part1
sSong198_Part1: @ 0x0886CBE9
	.byte	KEYSH , 0
	.byte	VOICE , 4
	.byte	VOL , 110
	.byte	PAN , 64
	.byte	N01, Cn3, 64
	.byte	W01
	.byte	N03, Gn3
	.byte	W05
	.byte	W01
	.byte	N02, En4, 40
	.byte	W05
	.byte	Gn3
	.byte	W04
	.byte	En4, 32
	.byte	W02
	.byte	W03
	.byte	Gn3
	.byte	W03
	.byte	W02
	.byte	En4, 20
	.byte	W04
	.byte	W01
	.byte	Gn3
	.byte	W05
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86CC0D, 0x3
	.globl sSongHeader_198
sSongHeader_198: @ 0x0886CC10
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886CBA8, 0x0886CBE9  @ parts
