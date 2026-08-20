.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong17_Part0
sSong17_Part0: @ 0x08868738
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 126
	.byte	VOL , 90
	.byte	N03, Fn4, 120
	.byte	W03
	.byte	Gs4, 112
	.byte	W03
	.byte	N02, Fs3
	.byte	W03
	.byte	N03, Gs4, 72
	.byte	W03
	.byte	N02, Fs3, 96
	.byte	W03
	.byte	N03, Gs4, 56
	.byte	W03
	.byte	N02, Fs3, 80
	.byte	W03
	.byte	N03, Gs4, 40
	.byte	W03
	.byte	N02, Fs3, 64
	.byte	W03
	.byte	N03, Gs4, 24
	.byte	W03
	.byte	N02, Fs3, 48
	.byte	W03
	.byte	N03, Gs4, 20
	.byte	W03
	.byte	Fs3, 28
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868772, 0x2
	.globl sSongHeader_17
sSongHeader_17: @ 0x08868774
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong17_Part0  @ parts
