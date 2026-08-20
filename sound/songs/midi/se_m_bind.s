.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong170_Part0
sSong170_Part0: @ 0x0886BBF8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 38
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N05, Fs2, 127
	.byte	W01
	.byte	PAN , 59
	.byte	BEND , 61
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 59
	.byte	W01
	.byte	PAN , 56
	.byte	BEND , 55
	.byte	W01
	.byte	PAN , 75
	.byte	BEND , 52
	.byte	W06
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N11
	.byte	W02
	.byte	BEND , 54
	.byte	W01
	.byte	58
	.byte	W01
	.byte	PAN , 59
	.byte	BEND , 60
	.byte	W01
	.byte	64
	.byte	W01
	.byte	PAN , 68
	.byte	BEND , 61
	.byte	W02
	.byte	67
	.byte	W01
	.byte	PAN , 56
	.byte	BEND , 55
	.byte	W01
	.byte	43
	.byte	W01
	.byte	PAN , 75
	.byte	BEND , 36
	.byte	W03
	.byte	FINE
	.globl sSongHeader_170
sSongHeader_170: @ 0x0886BC44
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong170_Part0  @ parts
