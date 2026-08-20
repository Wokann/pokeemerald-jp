.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong87_Part0
sSong87_Part0: @ 0x08869784
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 18
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N09, En3, 112
	.byte	W03
	.byte	BEND , 85
	.byte	W03
	.byte	64
	.byte	W03
	.byte	70
	.byte	N15, En3, 120
	.byte	W03
	.byte	BEND , 66
	.byte	W03
	.byte	55
	.byte	W03
	.byte	35
	.byte	W06
	.byte	64
	.byte	N09, Gn2
	.byte	W06
	.byte	BEND , 56
	.byte	W03
	.byte	49
	.byte	TIE , 56, 112
	.byte	W03
	.byte	BEND , 60
	.byte	W09
	.byte	56
	.byte	W03
	.byte	W06
	.byte	51
	.byte	W03
	.byte	42
	.byte	W09
	.byte	32
	.byte	W06
	.byte	VOL , 102
	.byte	BEND , 26
	.byte	W09
	.byte	VOL , 97
	.byte	W09
	.byte	92
	.byte	BEND , 19
	.byte	W06
	.byte	W03
	.byte	VOL , 83
	.byte	W06
	.byte	BEND , 12
	.byte	W03
	.byte	VOL , 72
	.byte	W09
	.byte	63
	.byte	W03
	.byte	W06
	.byte	57
	.byte	W06
	.byte	46
	.byte	W12
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8697DE, 0x2
	.globl sSongHeader_87
sSongHeader_87: @ 0x088697E0
	.byte 0x01, 0x00, 0x03, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong87_Part0  @ parts
