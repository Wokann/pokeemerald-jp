.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong367_Part0
sSong367_Part0: @ 0x08879DD4
	.byte	KEYSH , 0
	.byte	TEMPO , 87
	.byte	VOICE , 46
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 90
	.byte	PAN , 112
	.byte	W08
	.byte	N04, Bn3, 100
	.byte	W08
	.byte	N04
	.byte	W08
	.byte	N04
	.byte	W08
	.byte	N24, Gs4
	.byte	W10
	.byte	MOD , 5
	.byte	W54
	.byte	FINE
	.globl sSong367_Part1
sSong367_Part1: @ 0x08879DF3
	.byte	KEYSH , 0
	.byte	VOICE , 46
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 90
	.byte	W08
	.byte	PAN , 48
	.byte	N04, En4, 100
	.byte	W08
	.byte	PAN , 80
	.byte	N04
	.byte	W08
	.byte	PAN , 48
	.byte	N04
	.byte	W08
	.byte	PAN , 64
	.byte	N24, Bn4
	.byte	W10
	.byte	MOD , 5
	.byte	W54
	.byte	FINE
	.globl sSong367_Part2
sSong367_Part2: @ 0x08879E16
	.byte	KEYSH , 0
	.byte	VOICE , 46
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 90
	.byte	PAN , 16
	.byte	W08
	.byte	N04, Gs3, 68
	.byte	W08
	.byte	N04
	.byte	W08
	.byte	N04
	.byte	W08
	.byte	N24, En4
	.byte	W10
	.byte	MOD , 5
	.byte	W54
	.byte	FINE
	.globl sSong367_Part3
sSong367_Part3: @ 0x08879E33
	.byte	KEYSH , 0
	.byte	VOICE , 84
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 90
	.byte	W08
	.byte	N04, Bn3, 48
	.byte	W04
	.byte	Bn3, 20
	.byte	W04
	.byte	Bn3, 48
	.byte	W04
	.byte	Bn3, 20
	.byte	W04
	.byte	Bn3, 48
	.byte	W04
	.byte	Bn3, 20
	.byte	W04
	.byte	N24, Gs4, 48
	.byte	W10
	.byte	MOD , 5
	.byte	W03
	.byte	VOL , 71
	.byte	W03
	.byte	48
	.byte	W03
	.byte	25
	.byte	W03
	.byte	10
	.byte	W03
	.byte	0
	.byte	W36
	.byte	W03
	.byte	FINE
	.globl sSong367_Part4
sSong367_Part4: @ 0x08879E66
	.byte	KEYSH , 0
	.byte	VOICE , 85
	.byte	XCMD , 8 , 8
	.byte	9 , 8
	.byte	VOL , 90
	.byte	W08
	.byte	N04, En4, 48
	.byte	W04
	.byte	En4, 20
	.byte	W04
	.byte	En4, 48
	.byte	W04
	.byte	En4, 20
	.byte	W04
	.byte	En4, 48
	.byte	W04
	.byte	En4, 20
	.byte	W04
	.byte	N24, Bn4, 48
	.byte	W10
	.byte	MOD , 5
	.byte	W03
	.byte	VOL , 71
	.byte	W03
	.byte	48
	.byte	W03
	.byte	25
	.byte	W03
	.byte	10
	.byte	W03
	.byte	0
	.byte	W36
	.byte	W03
	.byte	FINE
	.incbin "baserom_jp.gba", 0x879E99, 0x3
	.globl sSongHeader_367
sSongHeader_367: @ 0x08879E9C
	.byte 0x05, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_085FF648  @ tone
	.4byte 0x08879DD4, 0x08879DF3, 0x08879E16, 0x08879E33, 0x08879E66  @ parts
