.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong218_Part0
sSong218_Part0: @ 0x0886DC50
	.byte	KEYSH , 0
	.byte	TEMPO , 75
	.byte	VOICE , 31
	.byte	VOL , 110
	.byte	BENDR , 24
	.byte	PAN , 64
	.byte	BEND , 27
	.byte	N06, Gn0, 127
	.byte	W01
	.byte	BEND , 48
	.byte	W01
	.byte	64
	.byte	W01
	.byte	91
	.byte	W01
	.byte	110
	.byte	W02
	.byte	VOICE , 23
	.byte	PAN , 75
	.byte	N01, Cn1
	.byte	W01
	.byte	PAN , 54
	.byte	N01, Cn2
	.byte	W01
	.byte	VOICE , 31
	.byte	PAN , 70
	.byte	BEND , 27
	.byte	N06, Dn1
	.byte	W01
	.byte	BEND , 48
	.byte	W01
	.byte	64
	.byte	W02
	.byte	91
	.byte	W01
	.byte	110
	.byte	W01
	.byte	VOICE , 23
	.byte	PAN , 63
	.byte	N01, Fn1
	.byte	W01
	.byte	PAN , 54
	.byte	N01, Fn2
	.byte	W01
	.byte	VOICE , 31
	.byte	PAN , 64
	.byte	BEND , 27
	.byte	N02, Gn0
	.byte	W02
	.byte	BEND , 48
	.byte	W01
	.byte	64
	.byte	W01
	.byte	PAN , 69
	.byte	BEND , 91
	.byte	N02
	.byte	W01
	.byte	BEND , 110
	.byte	W01
	.byte	VOICE , 23
	.byte	PAN , 74
	.byte	N01, Cn1
	.byte	W02
	.byte	PAN , 55
	.byte	N01, Cn2
	.byte	W01
	.byte	VOICE , 31
	.byte	PAN , 64
	.byte	BEND , 27
	.byte	N06, Dn1
	.byte	W01
	.byte	BEND , 48
	.byte	W01
	.byte	64
	.byte	W01
	.byte	91
	.byte	W02
	.byte	110
	.byte	W01
	.byte	VOICE , 23
	.byte	PAN , 69
	.byte	N01, Cn1
	.byte	W01
	.byte	PAN , 56
	.byte	N01, Cn2
	.byte	W01
	.byte	VOICE , 31
	.byte	PAN , 64
	.byte	BEND , 27
	.byte	N06, Gn0, 112
	.byte	W01
	.byte	BEND , 48
	.byte	W02
	.byte	64
	.byte	W01
	.byte	91
	.byte	W01
	.byte	110
	.byte	W01
	.byte	VOICE , 23
	.byte	PAN , 75
	.byte	N01, Cn1, 100
	.byte	W01
	.byte	PAN , 54
	.byte	N01, Cn2, 96
	.byte	W02
	.byte	VOICE , 31
	.byte	PAN , 70
	.byte	BEND , 27
	.byte	N06, Dn1
	.byte	W01
	.byte	BEND , 48
	.byte	W01
	.byte	64
	.byte	W01
	.byte	91
	.byte	W01
	.byte	110
	.byte	W02
	.byte	VOICE , 23
	.byte	PAN , 63
	.byte	N01, Fn1, 84
	.byte	W01
	.byte	PAN , 54
	.byte	N01, Fn2
	.byte	W01
	.byte	VOICE , 31
	.byte	PAN , 64
	.byte	BEND , 27
	.byte	N02, Gn0, 80
	.byte	W01
	.byte	BEND , 48
	.byte	W01
	.byte	64
	.byte	W02
	.byte	PAN , 69
	.byte	BEND , 91
	.byte	N02, Gn0, 72
	.byte	W01
	.byte	BEND , 110
	.byte	W01
	.byte	VOICE , 23
	.byte	PAN , 74
	.byte	N01, Cn1, 68
	.byte	W01
	.byte	PAN , 55
	.byte	N01, Cn2
	.byte	W01
	.byte	VOICE , 31
	.byte	PAN , 64
	.byte	BEND , 27
	.byte	N06, Dn1, 64
	.byte	W02
	.byte	BEND , 48
	.byte	W01
	.byte	64
	.byte	W01
	.byte	91
	.byte	W01
	.byte	110
	.byte	W01
	.byte	VOICE , 23
	.byte	PAN , 69
	.byte	N01, Cn1, 56
	.byte	W02
	.byte	PAN , 56
	.byte	N01, Cn2, 52
	.byte	W06
	.byte	FINE
	.incbin "baserom_jp.gba", 0x86DD5F, 0x1
	.globl sSongHeader_218
sSongHeader_218: @ 0x0886DD60
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08625214  @ tone
	.4byte sSong218_Part0  @ parts
