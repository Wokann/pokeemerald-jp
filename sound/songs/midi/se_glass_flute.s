.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong117_Part0
sSong117_Part0: @ 0x0886A478
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 28
	.byte	VOL , 26
	.byte	BENDR , 8
	.byte	BEND , 64
	.byte	N01, En3, 116
	.byte	W01
	.byte	VOL , 105
	.byte	BEND , 60
	.byte	N01, Bn2
	.byte	W01
	.byte	BEND , 67
	.byte	N01, Cn3
	.byte	W04
	.byte	W04
	.byte	BEND , 64
	.byte	N04, Bn3
	.byte	W02
	.byte	VOL , 26
	.byte	BEND , 57
	.byte	W01
	.byte	VOL , 105
	.byte	BEND , 51
	.byte	W01
	.byte	41
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86A4A7, 0x1
	.globl sSongHeader_117
sSongHeader_117: @ 0x0886A4A8
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong117_Part0  @ parts
