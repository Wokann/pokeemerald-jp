.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong39_Part0
sSong39_Part0: @ 0x08868B68
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 126
	.byte	VOL , 127
	.byte	N08, An2, 112
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	N01, Gs2
	.byte	W01
	.byte	W01
	.byte	N08, An2, 96
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W01
	.byte	N01, Gs2, 92
	.byte	W01
	.byte	N08, An2, 80
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	N01, Gs2, 76
	.byte	W01
	.byte	N08, An2, 64
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	N01, Gs2, 60
	.byte	W02
	.byte	N09, An2, 48
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	N01, Gs2, 40
	.byte	W01
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868BA7, 0x1
	.globl sSongHeader_39
sSongHeader_39: @ 0x08868BA8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong39_Part0  @ parts
