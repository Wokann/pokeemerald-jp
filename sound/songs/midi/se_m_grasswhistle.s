.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong231_Part0
sSong231_Part0: @ 0x0886E528
	.byte	KEYSH , 0
	.byte	TEMPO , 50
	.byte	VOICE , 64
	.byte	BENDR , 2
	.byte	LFOS , 40
	.byte	PAN , 64
	.byte	VOL , 70
	.byte	BEND , 48
	.byte	N21, Gn5, 112
	.byte	W03
	.byte	BEND , 56
	.byte	W03
	.byte	64
	.byte	W03
	.byte	MOD , 10
	.byte	W03
	.byte	W09
	.byte	0
	.byte	W03
	.byte	N09, An5
	.byte	W12
	.byte	En5
	.byte	W12
	.byte	BEND , 50
	.byte	N66, Gn5
	.byte	W06
	.byte	BEND , 56
	.byte	W06
	.byte	60
	.byte	W06
	.byte	64
	.byte	W06
	.byte	MOD , 10
	.byte	W12
	.byte	W12
	.byte	W06
	.byte	VOL , 61
	.byte	W06
	.byte	51
	.byte	W06
	.byte	36
	.byte	W06
	.byte	18
	.byte	W12
	.byte	FINE
	.globl sSong231_Part1
sSong231_Part1: @ 0x0886E567
	.byte	KEYSH , 0
	.byte	VOICE , 64
	.byte	BENDR , 2
	.byte	LFOS , 40
	.byte	VOL , 70
	.byte	W12
	.byte	PAN , 76
	.byte	BEND , 48
	.byte	N21, Gn5, 72
	.byte	W03
	.byte	BEND , 56
	.byte	W03
	.byte	64
	.byte	W03
	.byte	MOD , 10
	.byte	W03
	.byte	W09
	.byte	0
	.byte	W03
	.byte	PAN , 52
	.byte	N09, An5
	.byte	W12
	.byte	PAN , 78
	.byte	N09, En5
	.byte	W12
	.byte	PAN , 49
	.byte	BEND , 50
	.byte	N66, Gn5
	.byte	W06
	.byte	BEND , 56
	.byte	W06
	.byte	60
	.byte	W06
	.byte	64
	.byte	W06
	.byte	MOD , 10
	.byte	W12
	.byte	W06
	.byte	VOL , 61
	.byte	W06
	.byte	51
	.byte	W06
	.byte	36
	.byte	W06
	.byte	18
	.byte	W12
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86E5AB, 0x1
	.globl sSongHeader_231
sSongHeader_231: @ 0x0886E5AC
	.byte 0x02, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte 0x0886E528, 0x0886E567  @ parts
