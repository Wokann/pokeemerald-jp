.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong105_Part0
sSong105_Part0: @ 0x08869DDC
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 60
	.byte	BENDR , 12
	.byte	VOL , 25
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	TIE , 59, 127
	.byte	W01
	.byte	PAN , 66
	.byte	W01
	.byte	69
	.byte	W01
	.byte	VOL , 34
	.byte	W01
	.byte	PAN , 66
	.byte	W02
	.byte	64
	.byte	W01
	.byte	VOL , 46
	.byte	PAN , 62
	.byte	W01
	.byte	60
	.byte	W02
	.byte	VOL , 56
	.byte	PAN , 62
	.byte	W02
	.byte	64
	.byte	W01
	.byte	66
	.byte	W01
	.byte	69
	.byte	W01
	.byte	VOL , 70
	.byte	W01
	.byte	PAN , 66
	.byte	W02
	.byte	64
	.byte	W01
	.byte	VOL , 80
	.byte	PAN , 62
	.byte	W01
	.byte	60
	.byte	W02
	.byte	VOL , 88
	.byte	PAN , 62
	.byte	W02
	.byte	64
	.byte	W01
	.byte	66
	.byte	W01
	.byte	VOL , 96
	.byte	PAN , 69
	.byte	W02
	.byte	66
	.byte	W02
	.byte	VOL , 100
	.byte	PAN , 64
	.byte	W01
	.byte	62
	.byte	W01
	.byte	60
	.byte	W02
	.byte	62
	.byte	W02
	.byte	PAN , 64
	.byte	W01
	.byte	66
	.byte	W01
	.byte	69
	.byte	W02
	.byte	66
	.byte	W02
	.byte	64
	.byte	W01
	.byte	62
	.byte	W01
	.byte	60
	.byte	W02
	.byte	62
	.byte	W02
	.byte	PEND
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	PATT , 55, 158
	.byte	W06
	.byte	8
	.byte	VOL , 96
	.byte	PAN , 64
	.byte	W01
	.byte	66
	.byte	W01
	.byte	69
	.byte	W01
	.byte	VOL , 92
	.byte	W01
	.byte	PAN , 66
	.byte	W02
	.byte	64
	.byte	W01
	.byte	VOL , 84
	.byte	PAN , 62
	.byte	W01
	.byte	60
	.byte	W02
	.byte	VOL , 72
	.byte	PAN , 62
	.byte	W02
	.byte	64
	.byte	W01
	.byte	66
	.byte	W01
	.byte	VOL , 63
	.byte	PAN , 69
	.byte	W02
	.byte	VOL , 52
	.byte	PAN , 66
	.byte	W02
	.byte	64
	.byte	W01
	.byte	VOL , 37
	.byte	PAN , 62
	.byte	W01
	.byte	60
	.byte	W01
	.byte	VOL , 22
	.byte	W01
	.byte	12
	.byte	PAN , 62
	.byte	W02
	.byte	EOT , 59
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869EE1, 0x3
	.globl sSongHeader_105
sSongHeader_105: @ 0x08869EE4
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong105_Part0  @ parts
