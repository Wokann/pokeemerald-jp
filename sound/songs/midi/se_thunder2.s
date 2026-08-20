.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong88_Part0
sSong88_Part0: @ 0x088697EC
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 18
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 99
	.byte	TIE , 50, 112
	.byte	W03
	.byte	BEND , 75
	.byte	W03
	.byte	64
	.byte	W03
	.byte	70
	.byte	W06
	.byte	64
	.byte	W09
	.byte	W15
	.byte	64
	.byte	W06
	.byte	60
	.byte	W03
	.byte	W06
	.byte	51
	.byte	W09
	.byte	46
	.byte	W09
	.byte	VOL , 102
	.byte	BEND , 39
	.byte	W09
	.byte	VOL , 97
	.byte	BEND , 26
	.byte	W09
	.byte	VOL , 92
	.byte	BEND , 19
	.byte	W06
	.byte	W03
	.byte	VOL , 83
	.byte	W06
	.byte	BEND , 12
	.byte	W03
	.byte	VOL , 64
	.byte	W06
	.byte	47
	.byte	W06
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86982E, 0x2
	.globl sSongHeader_88
sSongHeader_88: @ 0x08869830
	.byte 0x01, 0x00, 0x03, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong88_Part0  @ parts
