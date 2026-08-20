.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong68_Part0
sSong68_Part0: @ 0x08869300
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 48
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Bn5, 112
	.byte	W06
	.byte	W06
	.byte	N06, Bn5, 40
	.byte	W06
	.byte	FINE
	.globl sSong68_Part1
sSong68_Part1: @ 0x08869314
	.byte	KEYSH , 0
	.byte	VOICE , 17
	.byte	VOL , 110
	.byte	BEND , 57
	.byte	N12, Fs6, 60
	.byte	W06
	.byte	W06
	.byte	N06, Fs6, 32
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x869326, 0x2
	.globl sSongHeader_68
sSongHeader_68: @ 0x08869328
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x08869300, 0x08869314  @ parts
