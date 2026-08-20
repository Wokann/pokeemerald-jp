.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong80_Part0
sSong80_Part0: @ 0x088695A8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 38
	.byte	BENDR , 2
	.byte	VOL , 51
	.byte	BEND , 32
	.byte	TIE , 88, 80
	.byte	W01
	.byte	BEND , 38
	.byte	W01
	.byte	VOL , 56
	.byte	W01
	.byte	BEND , 43
	.byte	W01
	.byte	VOL , 62
	.byte	W02
	.byte	BEND , 49
	.byte	W01
	.byte	VOL , 69
	.byte	W01
	.byte	BEND , 57
	.byte	W01
	.byte	VOL , 75
	.byte	W01
	.byte	BEND , 64
	.byte	W02
	.byte	VOL , 85
	.byte	W02
	.byte	92
	.byte	W02
	.byte	100
	.byte	W08
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W03
	.byte	96
	.byte	W03
	.byte	88
	.byte	W03
	.byte	81
	.byte	BEND , 59
	.byte	W03
	.byte	VOL , 74
	.byte	BEND , 56
	.byte	W02
	.byte	VOL , 62
	.byte	BEND , 52
	.byte	W02
	.byte	VOL , 49
	.byte	BEND , 43
	.byte	W03
	.byte	VOL , 39
	.byte	BEND , 38
	.byte	W02
	.byte	VOL , 25
	.byte	BEND , 32
	.byte	W03
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869601, 0x3
	.globl sSongHeader_80
sSongHeader_80: @ 0x08869604
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong80_Part0  @ parts
