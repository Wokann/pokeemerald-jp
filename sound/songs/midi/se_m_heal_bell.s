.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong195_Part0
sSong195_Part0: @ 0x0886CA64
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 51
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	VOL , 90
	.byte	BEND , 68
	.byte	N03, As5, 100
	.byte	W01
	.byte	PAN , 51
	.byte	W01
	.byte	75
	.byte	W01
	.byte	65
	.byte	N01, An5
	.byte	W01
	.byte	MOD , 7
	.byte	N18, Bn5
	.byte	W02
	.byte	PAN , 75
	.byte	W01
	.byte	MOD , 0
	.byte	PAN , 50
	.byte	W01
	.byte	75
	.byte	W01
	.byte	51
	.byte	W01
	.byte	75
	.byte	W02
	.byte	50
	.byte	W01
	.byte	75
	.byte	W01
	.byte	51
	.byte	W01
	.byte	75
	.byte	W01
	.byte	MOD , 7
	.byte	PAN , 50
	.byte	W02
	.byte	75
	.byte	W01
	.byte	50
	.byte	W01
	.byte	75
	.byte	W01
	.byte	51
	.byte	W03
	.byte	FINE
	.globl sSongHeader_195
sSongHeader_195: @ 0x0886CAA8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong195_Part0  @ parts
