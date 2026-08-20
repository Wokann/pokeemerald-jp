.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong9_Part0
sSong9_Part0: @ 0x08868520
	.byte	KEYSH , 0
	.byte	TEMPO , 60
	.byte	VOICE , 126
	.byte	VOL , 120
	.byte	N02, An2, 68
	.byte	W02
	.byte	Cn3, 127
	.byte	W01
	.byte	W01
	.byte	En4, 68
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	An2
	.byte	W02
	.byte	Cn3, 100
	.byte	W01
	.byte	W01
	.byte	En4, 68
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	An2, 32
	.byte	W02
	.byte	Cn3, 52
	.byte	W01
	.byte	W03
	.byte	FINE
	.globl sSongHeader_9
sSongHeader_9: @ 0x08868548
	.byte 0x01, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong9_Part0  @ parts
