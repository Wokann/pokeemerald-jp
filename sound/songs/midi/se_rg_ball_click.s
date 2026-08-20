.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong254_Part0
sSong254_Part0: @ 0x0886F5AC
	.byte	KEYSH , 0
	.byte	TEMPO , 155
	.byte	VOICE , 3
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 100
	.byte	BEND , 64
	.byte	N02, Bn3, 120
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	En4, 127
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.globl sSong254_Part1
sSong254_Part1: @ 0x0886F5C9
	.byte	KEYSH , 0
	.byte	VOICE , 126
	.byte	VOL , 100
	.byte	W03
	.byte	W01
	.byte	N01, Cn2, 120
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86F5DB, 0x1
	.globl sSongHeader_254
sSongHeader_254: @ 0x0886F5DC
	.byte 0x02, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gJP_CryTable_Reverse_3 + 0x30  @ tone
	.4byte 0x0886F5AC, 0x0886F5C9  @ parts
