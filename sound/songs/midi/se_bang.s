.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong20_Part0
sSong20_Part0: @ 0x088687F0
	.byte	KEYSH , 0
	.byte	TEMPO , 120
	.byte	VOICE , 2
	.byte	BENDR , 12
	.byte	VOL , 110
	.byte	BEND , 64
	.byte	N03, En2, 127
	.byte	W03
	.byte	Dn2
	.byte	W03
	.byte	N06, Gn1
	.byte	W06
	.byte	N60, An2
	.byte	W12
	.byte	W24
	.byte	VOL , 94
	.byte	BEND , 59
	.byte	W03
	.byte	VOL , 81
	.byte	W03
	.byte	71
	.byte	BEND , 52
	.byte	W03
	.byte	VOL , 47
	.byte	W03
	.byte	32
	.byte	BEND , 45
	.byte	W03
	.byte	VOL , 20
	.byte	W03
	.byte	7
	.byte	BEND , 36
	.byte	W03
	.byte	VOL , 0
	.byte	BEND , 27
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868829, 0x3
	.globl sSongHeader_20
sSongHeader_20: @ 0x0886882C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong20_Part0  @ parts
