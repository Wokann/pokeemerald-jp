.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong200_Part0
sSong200_Part0: @ 0x0886CC84
	.byte	KEYSH , 0
	.byte	TEMPO , 95
	.byte	VOICE , 45
	.byte	BENDR , 8
	.byte	VOL , 36
	.byte	PAN , 64
	.byte	BEND , 20
	.byte	N12, Gs2, 127
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 70
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 67
	.byte	PAN , 58
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 78
	.byte	PAN , 64
	.byte	BEND , 91
	.byte	W01
	.byte	VOL , 105
	.byte	PAN , 70
	.byte	BEND , 108
	.byte	W02
	.byte	PAN , 58
	.byte	BEND , 127
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 108
	.byte	W01
	.byte	VOL , 86
	.byte	PAN , 70
	.byte	BEND , 92
	.byte	W01
	.byte	VOL , 55
	.byte	PAN , 58
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 33
	.byte	BEND , 69
	.byte	W02
	.byte	VOICE , 37
	.byte	VOL , 105
	.byte	N02, Gs3, 80
	.byte	W01
	.byte	BEND , 80
	.byte	W01
	.byte	VOICE , 45
	.byte	VOL , 36
	.byte	PAN , 64
	.byte	BEND , 20
	.byte	N12, As2, 127
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 70
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 67
	.byte	PAN , 58
	.byte	BEND , 81
	.byte	W02
	.byte	VOL , 78
	.byte	PAN , 64
	.byte	BEND , 91
	.byte	W01
	.byte	VOL , 105
	.byte	PAN , 75
	.byte	BEND , 108
	.byte	W01
	.byte	PAN , 53
	.byte	BEND , 127
	.byte	W01
	.byte	PAN , 64
	.byte	BEND , 108
	.byte	W01
	.byte	VOL , 86
	.byte	PAN , 75
	.byte	BEND , 92
	.byte	W02
	.byte	VOL , 55
	.byte	PAN , 53
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 33
	.byte	BEND , 69
	.byte	W01
	.byte	VOICE , 37
	.byte	VOL , 105
	.byte	N02, As3, 56
	.byte	W01
	.byte	BEND , 80
	.byte	W01
	.byte	VOICE , 45
	.byte	VOL , 36
	.byte	BEND , 20
	.byte	N12, Gs2, 80
	.byte	W02
	.byte	VOL , 52
	.byte	PAN , 64
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 67
	.byte	PAN , 70
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 78
	.byte	PAN , 58
	.byte	BEND , 91
	.byte	W01
	.byte	VOL , 105
	.byte	PAN , 64
	.byte	BEND , 108
	.byte	W01
	.byte	PAN , 70
	.byte	BEND , 127
	.byte	W02
	.byte	PAN , 58
	.byte	BEND , 108
	.byte	W01
	.byte	VOL , 86
	.byte	PAN , 64
	.byte	BEND , 92
	.byte	W01
	.byte	VOL , 55
	.byte	PAN , 70
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 33
	.byte	PAN , 58
	.byte	BEND , 69
	.byte	W01
	.byte	VOICE , 37
	.byte	VOL , 105
	.byte	N02, Gs3, 24
	.byte	W02
	.byte	BEND , 80
	.byte	W01
	.byte	VOICE , 45
	.byte	VOL , 36
	.byte	BEND , 20
	.byte	N12, As2, 40
	.byte	W01
	.byte	VOL , 52
	.byte	PAN , 64
	.byte	BEND , 44
	.byte	W01
	.byte	VOL , 67
	.byte	PAN , 70
	.byte	BEND , 81
	.byte	W01
	.byte	VOL , 78
	.byte	PAN , 58
	.byte	BEND , 91
	.byte	W02
	.byte	VOL , 105
	.byte	PAN , 64
	.byte	BEND , 108
	.byte	W01
	.byte	PAN , 75
	.byte	BEND , 127
	.byte	W01
	.byte	PAN , 53
	.byte	BEND , 108
	.byte	W01
	.byte	VOL , 86
	.byte	PAN , 64
	.byte	BEND , 92
	.byte	W01
	.byte	VOL , 55
	.byte	PAN , 75
	.byte	BEND , 81
	.byte	W02
	.byte	VOL , 33
	.byte	BEND , 69
	.byte	W01
	.byte	VOICE , 37
	.byte	VOL , 105
	.byte	N02, As3, 16
	.byte	W01
	.byte	BEND , 80
	.byte	W04
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86CDC9, 0x3
	.globl sSongHeader_200
sSongHeader_200: @ 0x0886CDCC
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong200_Part0  @ parts
