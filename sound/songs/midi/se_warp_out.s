.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong46_Part0
sSong46_Part0: @ 0x08868D54
	.byte	KEYSH , 0
	.byte	TEMPO , 55
	.byte	VOICE , 93
	.byte	XCMD , 8 , 9
	.byte	9 , 8
	.byte	VOL , 90
	.byte	N06, En5, 64
	.byte	W03
	.byte	W03
	.byte	N03, En5, 16
	.byte	W03
	.byte	N06, En5, 88
	.byte	W03
	.byte	W03
	.byte	N03, En5, 16
	.byte	W03
	.byte	N06, En5, 112
	.byte	W03
	.byte	W03
	.byte	N03, En5, 16
	.byte	W03
	.byte	N06, En5, 127
	.byte	W03
	.byte	W03
	.byte	N03, En5, 16
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x868D86, 0x2
	.globl sSongHeader_46
sSongHeader_46: @ 0x08868D88
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong46_Part0  @ parts
