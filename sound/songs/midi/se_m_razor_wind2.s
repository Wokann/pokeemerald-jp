.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong160_Part0
sSong160_Part0: @ 0x0886B7F4
	.byte	KEYSH , 0
	.byte	TEMPO , 125
	.byte	VOICE , 22
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 90
	.byte	BEND , 64
	.byte	N14, An4, 108
	.byte	W03
	.byte	PAN , 69
	.byte	BEND , 70
	.byte	W01
	.byte	VOL , 80
	.byte	W02
	.byte	PAN , 79
	.byte	BEND , 65
	.byte	W01
	.byte	VOL , 64
	.byte	W02
	.byte	PAN , 70
	.byte	VOL , 38
	.byte	BEND , 55
	.byte	W02
	.byte	30
	.byte	W01
	.byte	PAN , 63
	.byte	VOL , 11
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86B825, 0x3
	.globl sSongHeader_160
sSongHeader_160: @ 0x0886B828
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong160_Part0  @ parts
