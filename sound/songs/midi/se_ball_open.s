.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong15_Part0
sSong15_Part0: @ 0x0886868C
	.byte	KEYSH , 0
	.byte	TEMPO , 45
	.byte	VOICE , 86
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N02, Gn1, 100
	.byte	W03
	.byte	N05, Fn2
	.byte	W03
	.byte	W03
	.byte	N06, Fn2, 52
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong15_Part1
sSong15_Part1: @ 0x088686A4
	.byte	KEYSH , 0
	.byte	VOICE , 0
	.byte	VOL , 100
	.byte	BENDR , 12
	.byte	BEND , 64
	.byte	N03, Gn3, 52
	.byte	W03
	.byte	Cn2, 112
	.byte	W03
	.byte	W03
	.byte	Cn1, 92
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong15_Part2
sSong15_Part2: @ 0x088686BB
	.byte	KEYSH , 0
	.byte	VOICE , 124
	.byte	VOL , 100
	.byte	N03, Gn3, 52
	.byte	W03
	.byte	N06, Gs4
	.byte	W03
	.byte	W03
	.byte	Gs4, 20
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8686CE, 0x2
	.globl sSongHeader_15
sSongHeader_15: @ 0x088686D0
	.byte 0x03, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x0886868C, 0x088686A4, 0x088686BB  @ parts
