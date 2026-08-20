.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong244_Part0
sSong244_Part0: @ 0x0886F018
	.byte	KEYSH , 0
	.byte	TEMPO , 85
	.byte	VOICE , 37
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 110
	.byte	BEND , 60
	.byte	N03, Gn4, 100
	.byte	W06
	.byte	PAN , 80
	.byte	N03, Gn4, 56
	.byte	W03
	.byte	PAN , 64
	.byte	N03, An5, 100
	.byte	W03
	.byte	W03
	.byte	PAN , 49
	.byte	N03, An5, 56
	.byte	W03
	.byte	PAN , 64
	.byte	N03, Cn6, 100
	.byte	W06
	.byte	PAN , 80
	.byte	N03, Cn6, 56
	.byte	W03
	.byte	PAN , 64
	.byte	N03, Gn4, 72
	.byte	W03
	.byte	W03
	.byte	PAN , 48
	.byte	N03, Gn4, 28
	.byte	W03
	.byte	PAN , 64
	.byte	N03, An5, 72
	.byte	W06
	.byte	PAN , 80
	.byte	N03, An5, 28
	.byte	W03
	.byte	PAN , 64
	.byte	N03, Cn6, 72
	.byte	W03
	.byte	W03
	.byte	PAN , 48
	.byte	N03, Cn6, 28
	.byte	W03
	.byte	W06
	.byte	FINE
	.globl sSong244_Part1
sSong244_Part1: @ 0x0886F071
	.byte	KEYSH , 0
	.byte	VOICE , 47
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	MOD , 20
	.byte	VOL , 44
	.byte	BEND , 62
	.byte	W03
	.byte	N03, Gn3, 112
	.byte	W03
	.byte	W03
	.byte	Gn3, 68
	.byte	W03
	.byte	An4, 112
	.byte	W06
	.byte	An4, 68
	.byte	W03
	.byte	Cn5, 112
	.byte	W03
	.byte	W03
	.byte	Cn5, 68
	.byte	W03
	.byte	Gn3, 80
	.byte	W06
	.byte	Gn3, 36
	.byte	W03
	.byte	An4, 80
	.byte	W03
	.byte	W03
	.byte	An4, 36
	.byte	W03
	.byte	Cn5, 80
	.byte	W06
	.byte	Cn5, 36
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F0AA, 0x2
	.globl sSongHeader_244
sSongHeader_244: @ 0x0886F0AC
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886F018, 0x0886F071  @ parts
