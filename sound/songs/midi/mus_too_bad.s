.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong391_Part0
sSong391_Part0: @ 0x08881BA4
	.byte	KEYSH , 0
	.byte	TEMPO , 90
	.byte	VOL , 90
	.byte	W09
	.byte	VOICE , 73
	.byte	PAN , 65
	.byte	N06, Dn3, 88
	.byte	W06
	.byte	Dn4
	.byte	W09
	.byte	N03, As4
	.byte	W03
	.byte	N09, Bn4
	.byte	W09
	.byte	Bn3
	.byte	W12
	.byte	N03, Gs4
	.byte	W03
	.byte	N09, An4
	.byte	W09
	.byte	An3
	.byte	W12
	.byte	N03, Fn4
	.byte	W03
	.byte	N09, Fs4
	.byte	W09
	.byte	Fs3
	.byte	W12
	.byte	N03, Cs4
	.byte	W03
	.byte	N60, Dn4
	.byte	W09
	.byte	MOD , 32
	.byte	W21
	.byte	VOL , 85
	.byte	W06
	.byte	79
	.byte	W06
	.byte	73
	.byte	W03
	.byte	W03
	.byte	62
	.byte	W03
	.byte	45
	.byte	W03
	.byte	31
	.byte	W03
	.byte	14
	.byte	W12
	.byte	FINE
	.globl sSong391_Part1
sSong391_Part1: @ 0x08881BE7
	.byte	KEYSH , 0
	.byte	VOL , 90
	.byte	W09
	.byte	VOICE , 73
	.byte	PAN , 84
	.byte	W03
	.byte	N06, An3, 88
	.byte	W06
	.byte	An4
	.byte	W06
	.byte	W03
	.byte	N09
	.byte	W09
	.byte	An3
	.byte	W12
	.byte	W03
	.byte	Gn4
	.byte	W09
	.byte	Gn3
	.byte	W15
	.byte	En4
	.byte	W09
	.byte	En3
	.byte	W12
	.byte	N60, An3
	.byte	W12
	.byte	MOD , 32
	.byte	W21
	.byte	VOL , 85
	.byte	W06
	.byte	79
	.byte	W06
	.byte	73
	.byte	W03
	.byte	W03
	.byte	62
	.byte	W03
	.byte	45
	.byte	W03
	.byte	31
	.byte	W03
	.byte	14
	.byte	W12
	.byte	FINE
	.globl sSong391_Part2
sSong391_Part2: @ 0x08881C1C
	.byte	KEYSH , 0
	.byte	W24
	.byte	VOICE , 2
	.byte	VOL , 90
	.byte	N09, Dn2, 112
	.byte	W12
	.byte	Bn2
	.byte	W12
	.byte	Dn2
	.byte	W12
	.byte	An2
	.byte	W12
	.byte	Dn2
	.byte	W12
	.byte	Fs2
	.byte	W12
	.byte	N60, Dn2
	.byte	W32
	.byte	W01
	.byte	VOL , 85
	.byte	W06
	.byte	79
	.byte	W06
	.byte	73
	.byte	W03
	.byte	W03
	.byte	62
	.byte	W03
	.byte	45
	.byte	W03
	.byte	31
	.byte	W03
	.byte	14
	.byte	W12
	.byte	FINE
	.globl sSong391_Part3
sSong391_Part3: @ 0x08881C46
	.byte	KEYSH , 0
	.byte	XCMD , 8 , 10
	.byte	9 , 8
	.byte	W24
	.byte	VOICE , 90
	.byte	VOL , 90
	.byte	PAN , 16
	.byte	W03
	.byte	N06, Bn5, 52
	.byte	W21
	.byte	W03
	.byte	An5
	.byte	W24
	.byte	Fs5
	.byte	W24
	.byte	Dn5
	.byte	W44
	.byte	W01
	.byte	W24
	.byte	FINE
	.globl sSong391_Part4
sSong391_Part4: @ 0x08881C63
	.byte	KEYSH , 0
	.byte	W24
	.byte	VOICE , 0
	.byte	VOL , 90
	.byte	W03
	.byte	N03, En3, 64
	.byte	W21
	.byte	W03
	.byte	Dn3
	.byte	W24
	.byte	En3
	.byte	W21
	.byte	N03
	.byte	W03
	.byte	Dn3
	.byte	W44
	.byte	W01
	.byte	W24
	.byte	FINE
	.incbin "baserom_jp.gba", 0x881C7B, 0x1
	.globl sSongHeader_391
sSongHeader_391: @ 0x08881C7C
	.byte 0x05, 0x00, 0x05, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_085FF648  @ tone
	.4byte 0x08881BA4, 0x08881BE7, 0x08881C1C, 0x08881C46, 0x08881C63  @ parts
