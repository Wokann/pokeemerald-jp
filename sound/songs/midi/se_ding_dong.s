.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong73_Part0
sSong73_Part0: @ 0x08869414
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 15
	.byte	BENDR , 2
	.byte	VOL , 90
	.byte	BEND , 65
	.byte	N24, Ds4, 92
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	BEND , 79
	.byte	N36, Bn3
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong73_Part1
sSong73_Part1: @ 0x0886943D
	.byte	KEYSH , 0
	.byte	VOICE , 14
	.byte	VOL , 90
	.byte	BEND , 65
	.byte	N24, Ds4, 72
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	BEND , 79
	.byte	N36, Bn3
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869462, 0x2
	.globl sSongHeader_73
sSongHeader_73: @ 0x08869464
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte 0x08869414, 0x0886943D  @ parts
