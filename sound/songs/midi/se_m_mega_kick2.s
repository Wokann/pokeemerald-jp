.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong141_Part0
sSong141_Part0: @ 0x0886AE18
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 6
	.byte	VOL , 110
	.byte	BENDR , 12
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N04, En3, 127
	.byte	W01
	.byte	BEND , 51
	.byte	W01
	.byte	PAN , 74
	.byte	BEND , 26
	.byte	W01
	.byte	PAN , 55
	.byte	BEND , 0
	.byte	W03
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, An2
	.byte	W01
	.byte	PAN , 71
	.byte	BEND , 36
	.byte	W01
	.byte	0
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N03, Cn3, 60
	.byte	W01
	.byte	PAN , 58
	.byte	BEND , 36
	.byte	W02
	.byte	0
	.byte	W02
	.byte	PAN , 64
	.byte	BEND , 64
	.byte	N10, Gn2, 127
	.byte	W01
	.byte	BEND , 56
	.byte	W01
	.byte	VOL , 101
	.byte	PAN , 58
	.byte	BEND , 49
	.byte	W02
	.byte	44
	.byte	W01
	.byte	VOL , 83
	.byte	PAN , 70
	.byte	BEND , 40
	.byte	W01
	.byte	34
	.byte	W01
	.byte	VOL , 58
	.byte	PAN , 64
	.byte	BEND , 25
	.byte	W01
	.byte	11
	.byte	W02
	.byte	VOL , 25
	.byte	BEND , 0
	.byte	W24
	.byte	FINE
	.globl sSong141_Part1
sSong141_Part1: @ 0x0886AE80
	.byte	KEYSH , 0
	.byte	VOICE , 5
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	VOL , 110
	.byte	PAN , 73
	.byte	N03, Gs2, 92
	.byte	W06
	.byte	PAN , 57
	.byte	N03, Gs2, 52
	.byte	W03
	.byte	N03
	.byte	W05
	.byte	VOICE , 27
	.byte	PAN , 64
	.byte	N13
	.byte	W04
	.byte	VOL , 101
	.byte	W02
	.byte	83
	.byte	W02
	.byte	58
	.byte	W02
	.byte	W01
	.byte	25
	.byte	W23
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86AEAA, 0x2
	.globl sSongHeader_141
sSongHeader_141: @ 0x0886AEAC
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886AE18, 0x0886AE80  @ parts
