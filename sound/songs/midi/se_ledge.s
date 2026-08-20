.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong10_Part0
sSong10_Part0: @ 0x08868554
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 85
	.byte	VOL , 100
	.byte	BEND , 58
	.byte	N02, Ds2, 80
	.byte	W02
	.byte	VOICE , 86
	.byte	N06, Gn3, 127
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86856B, 0x1
	.globl sSongHeader_10
sSongHeader_10: @ 0x0886856C
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong10_Part0  @ parts
