.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong185_Part0
sSong185_Part0: @ 0x0886C5A0
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 6
	.byte	BENDR , 12
	.byte	VOL , 115
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N19, An2, 127
	.byte	W01
	.byte	BEND , 58
	.byte	W01
	.byte	54
	.byte	W01
	.byte	50
	.byte	W01
	.byte	52
	.byte	W02
	.byte	50
	.byte	W01
	.byte	46
	.byte	W01
	.byte	VOL , 108
	.byte	BEND , 44
	.byte	W01
	.byte	42
	.byte	W01
	.byte	VOL , 94
	.byte	W03
	.byte	78
	.byte	W01
	.byte	62
	.byte	W01
	.byte	40
	.byte	W01
	.byte	27
	.byte	W02
	.byte	12
	.byte	W06
	.byte	FINE
	.globl sSongHeader_185
sSongHeader_185: @ 0x0886C5D4
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong185_Part0  @ parts
