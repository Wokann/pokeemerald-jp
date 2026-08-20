.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong83_Part0
sSong83_Part0: @ 0x0886968C
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 18
	.byte	BEND , 64
	.byte	N24, Cn3, 60
	.byte	W03
	.byte	VOL , 33
	.byte	W03
	.byte	48
	.byte	W03
	.byte	55
	.byte	W03
	.byte	65
	.byte	W03
	.byte	74
	.byte	W03
	.byte	85
	.byte	W03
	.byte	100
	.byte	W03
	.byte	N36, Cn3, 60
	.byte	W24
	.byte	W12
	.byte	GOTO , 173, 150
	.byte	W06
	.byte	GsM2
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8696B9, 0x3
	.globl sSongHeader_83
sSongHeader_83: @ 0x088696BC
	.byte 0x01, 0x00, 0x02, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong83_Part0  @ parts
