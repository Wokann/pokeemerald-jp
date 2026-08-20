.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong98_Part0
sSong98_Part0: @ 0x08869AC8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 25
	.byte	VOL , 12
	.byte	BEND , 64
	.byte	N12, Gs4, 60
	.byte	W01
	.byte	VOL , 22
	.byte	W01
	.byte	33
	.byte	W01
	.byte	46
	.byte	W01
	.byte	58
	.byte	W02
	.byte	70
	.byte	W02
	.byte	60
	.byte	W01
	.byte	42
	.byte	W01
	.byte	22
	.byte	W02
	.byte	FINE
	.globl sSong98_Part1
sSong98_Part1: @ 0x08869AE8
	.byte	KEYSH , 0
	.byte	VOICE , 15
	.byte	VOL , 12
	.byte	BEND , 64
	.byte	N12, Fn3, 100
	.byte	W01
	.byte	VOL , 22
	.byte	BEND , 60
	.byte	W01
	.byte	VOL , 33
	.byte	BEND , 57
	.byte	W01
	.byte	VOL , 46
	.byte	BEND , 54
	.byte	W01
	.byte	VOL , 58
	.byte	BEND , 49
	.byte	W02
	.byte	VOL , 70
	.byte	BEND , 41
	.byte	W01
	.byte	33
	.byte	W01
	.byte	VOL , 60
	.byte	BEND , 25
	.byte	W01
	.byte	VOL , 42
	.byte	BEND , 16
	.byte	W01
	.byte	VOL , 22
	.byte	BEND , 9
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869B1F, 0x1
	.globl sSongHeader_98
sSongHeader_98: @ 0x08869B20
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869AC8, 0x08869AE8  @ parts
