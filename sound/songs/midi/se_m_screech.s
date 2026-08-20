.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong181_Part0
sSong181_Part0: @ 0x0886C2B4
	.byte	VOL , 110
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 44
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N21, Fs5, 112
	.byte	W01
	.byte	PAN , 59
	.byte	W01
	.byte	54
	.byte	VOL , 15
	.byte	W01
	.byte	PAN , 60
	.byte	VOL , 41
	.byte	W01
	.byte	PAN , 64
	.byte	VOL , 69
	.byte	W02
	.byte	PAN , 68
	.byte	W01
	.byte	74
	.byte	VOL , 84
	.byte	W01
	.byte	PAN , 68
	.byte	W01
	.byte	VOL , 97
	.byte	PAN , 64
	.byte	W01
	.byte	59
	.byte	W02
	.byte	VOL , 110
	.byte	PAN , 54
	.byte	W01
	.byte	60
	.byte	W01
	.byte	64
	.byte	W01
	.byte	68
	.byte	W01
	.byte	74
	.byte	W02
	.byte	VOL , 100
	.byte	PAN , 68
	.byte	W01
	.byte	VOL , 84
	.byte	PAN , 64
	.byte	W01
	.byte	VOL , 55
	.byte	W02
	.byte	BEND , 64
	.byte	W02
	.byte	FINE
	.globl sSong181_Part1
sSong181_Part1: @ 0x0886C306
	.byte	VOL , 110
	.byte	KEYSH , 0
	.byte	VOICE , 42
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N21, Fn6, 64
	.byte	W06
	.byte	PAN , 64
	.byte	W03
	.byte	64
	.byte	W03
	.byte	W03
	.byte	64
	.byte	W03
	.byte	W01
	.byte	64
	.byte	W03
	.byte	BEND , 64
	.byte	W02
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C323, 0x1
	.globl sSongHeader_181
sSongHeader_181: @ 0x0886C324
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886C2B4, 0x0886C306  @ parts
