.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong81_Part0
sSong81_Part0: @ 0x08869610
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 36
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	VOL , 15
	.byte	BEND , 64
	.byte	N24, Gn3, 60
	.byte	W03
	.byte	VOL , 27
	.byte	W03
	.byte	39
	.byte	W03
	.byte	44
	.byte	W03
	.byte	52
	.byte	W03
	.byte	59
	.byte	W03
	.byte	68
	.byte	W03
	.byte	80
	.byte	W03
	.byte	N60, Gn3, 60
	.byte	W24
	.byte	W24
	.byte	W12
	.byte	GOTO , 49, 150
	.byte	W06
	.byte	GsM2
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86963E, 0x2
	.globl sSongHeader_81
sSongHeader_81: @ 0x08869640
	.byte 0x01, 0x00, 0x02, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong81_Part0  @ parts
