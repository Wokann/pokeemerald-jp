.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong174_Part0
sSong174_Part0: @ 0x0886BFA0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 39
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 95
	.byte	BEND , 64
	.byte	N01, An5, 100
	.byte	W01
	.byte	Fn5, 64
	.byte	W01
	.byte	N06, Gn5, 100
	.byte	W01
	.byte	VOL , 85
	.byte	PAN , 51
	.byte	W01
	.byte	VOL , 59
	.byte	PAN , 75
	.byte	W02
	.byte	VOL , 33
	.byte	PAN , 50
	.byte	W01
	.byte	VOL , 5
	.byte	PAN , 75
	.byte	W03
	.byte	VOL , 95
	.byte	PAN , 65
	.byte	N01, An5
	.byte	W02
	.byte	Fn5, 64
	.byte	W01
	.byte	N19, Gn5, 100
	.byte	W01
	.byte	PAN , 51
	.byte	W01
	.byte	75
	.byte	W01
	.byte	50
	.byte	W02
	.byte	75
	.byte	W01
	.byte	51
	.byte	W01
	.byte	75
	.byte	VOL , 85
	.byte	W01
	.byte	PAN , 50
	.byte	VOL , 77
	.byte	W01
	.byte	PAN , 75
	.byte	VOL , 69
	.byte	W02
	.byte	PAN , 51
	.byte	VOL , 59
	.byte	W01
	.byte	PAN , 75
	.byte	VOL , 52
	.byte	W01
	.byte	PAN , 50
	.byte	VOL , 41
	.byte	W01
	.byte	33
	.byte	PAN , 75
	.byte	W01
	.byte	VOL , 23
	.byte	PAN , 50
	.byte	W02
	.byte	VOL , 14
	.byte	PAN , 75
	.byte	W01
	.byte	VOL , 5
	.byte	PAN , 51
	.byte	W05
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C017, 0x1
	.globl sSongHeader_174
sSongHeader_174: @ 0x0886C018
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong174_Part0  @ parts
