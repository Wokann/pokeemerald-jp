.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong183_Part0
sSong183_Part0: @ 0x0886C3F8
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 9
	.byte	BENDR , 2
	.byte	PAN , 64
	.byte	VOL , 26
	.byte	BEND , 41
	.byte	N09, Dn5, 127
	.byte	W01
	.byte	VOL , 34
	.byte	PAN , 70
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 42
	.byte	PAN , 57
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 73
	.byte	W01
	.byte	VOL , 72
	.byte	PAN , 51
	.byte	BEND , 46
	.byte	W02
	.byte	VOL , 85
	.byte	PAN , 70
	.byte	BEND , 43
	.byte	W01
	.byte	VOL , 102
	.byte	PAN , 58
	.byte	BEND , 41
	.byte	W01
	.byte	VOL , 120
	.byte	BEND , 40
	.byte	W02
	.byte	VOL , 26
	.byte	PAN , 64
	.byte	BEND , 41
	.byte	N09, Dn5, 100
	.byte	W02
	.byte	VOL , 34
	.byte	PAN , 70
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 42
	.byte	PAN , 57
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 73
	.byte	W01
	.byte	VOL , 72
	.byte	PAN , 51
	.byte	BEND , 46
	.byte	W01
	.byte	VOL , 85
	.byte	PAN , 70
	.byte	BEND , 43
	.byte	W02
	.byte	VOL , 102
	.byte	PAN , 58
	.byte	BEND , 41
	.byte	W01
	.byte	VOL , 120
	.byte	BEND , 40
	.byte	W02
	.byte	VOL , 26
	.byte	PAN , 64
	.byte	BEND , 41
	.byte	N09, Dn5, 80
	.byte	W01
	.byte	VOL , 34
	.byte	PAN , 70
	.byte	BEND , 44
	.byte	W02
	.byte	VOL , 42
	.byte	PAN , 57
	.byte	BEND , 48
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 73
	.byte	W01
	.byte	VOL , 72
	.byte	PAN , 51
	.byte	BEND , 46
	.byte	W01
	.byte	VOL , 85
	.byte	PAN , 70
	.byte	BEND , 43
	.byte	W01
	.byte	VOL , 102
	.byte	PAN , 58
	.byte	BEND , 41
	.byte	W02
	.byte	VOL , 120
	.byte	BEND , 40
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86C4A6, 0x2
	.globl sSongHeader_183
sSongHeader_183: @ 0x0886C4A8
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong183_Part0  @ parts
