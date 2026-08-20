.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong111_Part0
sSong111_Part0: @ 0x0886A0F0
	.byte	KEYSH , 0
	.byte	TEMPO , 72
	.byte	VOICE , 4
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 100
	.byte	BEND , 58
	.byte	N02, Gn4, 60
	.byte	W02
	.byte	N01, Gn4, 32
	.byte	W01
	.byte	N02, Dn4, 60
	.byte	W03
	.byte	N01, Dn4, 32
	.byte	W01
	.byte	N02, Gn4, 60
	.byte	W02
	.byte	Gn4, 32
	.byte	W03
	.byte	Gn3, 60
	.byte	W02
	.byte	Gn3, 32
	.byte	W04
	.byte	FINE
	.globl sSong111_Part1
sSong111_Part1: @ 0x0886A11D
	.byte	KEYSH , 0
	.byte	VOICE , 14
	.byte	VOL , 50
	.byte	BEND , 62
	.byte	W01
	.byte	N02, Gn4, 60
	.byte	W02
	.byte	N01, Gn4, 32
	.byte	W01
	.byte	N02, Dn4, 60
	.byte	W02
	.byte	W01
	.byte	N01, Dn4, 32
	.byte	W01
	.byte	N02, Gn4, 60
	.byte	W02
	.byte	Gn4, 32
	.byte	W02
	.byte	W01
	.byte	Gn3, 60
	.byte	W02
	.byte	Gn3, 32
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A146, 0x2
	.globl sSongHeader_111
sSongHeader_111: @ 0x0886A148
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x0886A0F0, 0x0886A11D  @ parts
