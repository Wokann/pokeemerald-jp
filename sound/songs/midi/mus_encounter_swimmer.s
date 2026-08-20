.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong385_Part0
sSong385_Part0: @ 0x088805F8
	.byte	KEYSH , 0
	.byte	TEMPO , 71
	.byte	VOICE , 46
	.byte	VOL , 80
	.byte	PAN , 55
	.byte	W03
	.byte	N06, Dn5, 92
	.byte	W06
	.byte	N24, Ds5
	.byte	W24
	.byte	W03
	.byte	VOICE , 45
	.byte	N06, Fs3, 68
	.byte	W06
	.byte	An3, 76
	.byte	W06
	.byte	Bn3, 84
	.byte	W06
	.byte	Ds4, 92
	.byte	W06
	.byte	Fs4, 100
	.byte	W06
	.byte	An4, 108
	.byte	W06
	.byte	N12, Bn4
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	Cs4
	.byte	W12
	.byte	Fs4
	.byte	W12
	.byte	Bn4
	.byte	W12
	.byte	Cs5
	.byte	W12
	.byte	VOICE , 60
	.byte	VOL , 80
	.byte	PAN , 68
	.byte	N30, Ds4, 112
	.byte	W36
	.byte	N12, Cs4
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	Fs3
	.byte	W24
	.byte	An3
	.byte	W24
	.byte	Cs4
	.byte	W24
	.byte	N68, Bn3, 112
	.byte	W32
	.byte	W01
	.byte	VOL , 75
	.byte	W06
	.byte	70
	.byte	W06
	.byte	62
	.byte	W06
	.byte	53
	.byte	W06
	.byte	42
	.byte	W06
	.byte	27
	.byte	W03
	.byte	9
	.byte	W06
	.byte	PEND
	.byte	80
	.byte	N30, Ds4
	.byte	W36
	.byte	N12, En4
	.byte	W12
	.byte	Ds4
	.byte	W12
	.byte	Cs4
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	Cs4
	.byte	W24
	.byte	Ds4
	.byte	W24
	.byte	Cs4
	.byte	W24
	.byte	PATT , 80, 6
	.byte	W08
	.byte	GsM2
	.byte	GOTO , 45, 6
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong385_Part1
sSong385_Part1: @ 0x0888068D
	.byte	VOL , 80
	.byte	KEYSH , 0
	.byte	VOICE , 33
	.byte	N72, Bn0, 120
	.byte	W72
	.byte	VOL , 80
	.byte	N24, Fs1
	.byte	W24
	.byte	En1
	.byte	W24
	.byte	Ds1
	.byte	W24
	.byte	VOL , 80
	.byte	N48, En1, 120
	.byte	W48
	.byte	N12, Bn0
	.byte	W24
	.byte	N48, En1, 120
	.byte	W48
	.byte	N12, Bn0
	.byte	W24
	.byte	PEND
	.byte	N12, Fs1, 120
	.byte	W24
	.byte	N12
	.byte	W24
	.byte	N24, Cs1
	.byte	W24
	.byte	PEND
	.byte	N12, Bn0, 120
	.byte	W24
	.byte	Ds1
	.byte	W24
	.byte	N24, Fs1
	.byte	W24
	.byte	PEND
	.byte	PATT , 169, 6
	.byte	W08
	.byte	GsM2
	.byte	PATT , 169, 6
	.byte	W08
	.byte	GsM2
	.byte	PATT , 177, 6
	.byte	W08
	.byte	GsM2
	.byte	PATT , 187, 6
	.byte	W08
	.byte	GsM2
	.byte	GOTO , 160, 6
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong385_Part2
sSong385_Part2: @ 0x088806DF
	.byte	VOL , 80
	.byte	KEYSH , 0
	.byte	VOICE , 46
	.byte	PAN , 73
	.byte	N06, Cs5, 92
	.byte	W06
	.byte	N42, Bn4
	.byte	W18
	.byte	BEND , 64
	.byte	W48
	.byte	VOICE , 48
	.byte	VOL , 80
	.byte	PAN , 56
	.byte	N24, Fs2, 72
	.byte	W24
	.byte	Gs2
	.byte	W24
	.byte	An2
	.byte	W24
	.byte	VOICE , 48
	.byte	VOL , 80
	.byte	N30, Bn2, 72
	.byte	W36
	.byte	N12, Gs2
	.byte	W12
	.byte	Bn2
	.byte	W12
	.byte	Cs3
	.byte	W12
	.byte	Ds3
	.byte	W12
	.byte	Cs3
	.byte	W12
	.byte	Ds3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	Ds3
	.byte	W12
	.byte	Cs3
	.byte	W24
	.byte	Fs3
	.byte	W24
	.byte	An3
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Gs3
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Fs4
	.byte	W12
	.byte	En4
	.byte	W12
	.byte	Ds4
	.byte	W12
	.byte	VOICE , 60
	.byte	N21, Bn2, 72
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W03
	.byte	29
	.byte	W03
	.byte	VOICE , 48
	.byte	VOL , 80
	.byte	N06, Bn2, 92
	.byte	W24
	.byte	Ds3
	.byte	W24
	.byte	PEND
	.byte	PATT , 46, 7
	.byte	W08
	.byte	GsM2
	.byte	VOICE , 60
	.byte	N21, An2, 72
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W03
	.byte	29
	.byte	W03
	.byte	VOICE , 48
	.byte	VOL , 80
	.byte	N06, An2, 92
	.byte	W24
	.byte	Fs3
	.byte	W24
	.byte	VOICE , 48
	.byte	N12, Bn2, 72
	.byte	W12
	.byte	As2
	.byte	W12
	.byte	Bn2
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Ds3
	.byte	W12
	.byte	GOTO , 255, 6
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong385_Part3
sSong385_Part3: @ 0x0888077C
	.byte	KEYSH , 0
	.byte	VOICE , 80
	.byte	VOL , 80
	.byte	PAN , 112
	.byte	XCMD , 8 , 13
	.byte	9 , 8
	.byte	N06, Bn2, 52
	.byte	W24
	.byte	Bn3
	.byte	W24
	.byte	N06
	.byte	W24
	.byte	VOICE , 4
	.byte	VOL , 80
	.byte	N21, Ds3, 60
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, En3
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Fs3
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	VOICE , 80
	.byte	VOL , 80
	.byte	N21, Gs3, 60
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Gs4, 52
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Gs3, 60
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Gs4, 52
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Gs3, 60
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N12, Cs4, 52
	.byte	W12
	.byte	Fs2, 60
	.byte	W12
	.byte	Fs4, 52
	.byte	W12
	.byte	Fs2, 60
	.byte	W12
	.byte	An4, 52
	.byte	W12
	.byte	Fs2, 60
	.byte	W12
	.byte	N24, An4, 52
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N12, Fs2, 60
	.byte	W12
	.byte	Bn2
	.byte	W12
	.byte	Cs3
	.byte	W12
	.byte	Ds3
	.byte	W12
	.byte	N21, En3, 60
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	80
	.byte	N12, En3, 40
	.byte	W12
	.byte	Bn3
	.byte	W12
	.byte	Gs4
	.byte	W12
	.byte	Ds5
	.byte	W12
	.byte	PEND
	.byte	PATT , 41, 8
	.byte	W08
	.byte	GsM2
	.byte	N21, Ds3, 60
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	80
	.byte	N12, Ds3, 40
	.byte	W12
	.byte	An3
	.byte	W12
	.byte	Fs4
	.byte	W12
	.byte	Cs5
	.byte	W12
	.byte	N21, Fs4, 60
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	80
	.byte	N21, Fs3
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	80
	.byte	N21, Bn3
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	GOTO , 182, 7
	.byte	W08
	.byte	8
	.byte	FINE
	.globl sSong385_Part4
sSong385_Part4: @ 0x08880882
	.byte	KEYSH , 0
	.byte	VOICE , 81
	.byte	VOL , 80
	.byte	XCMD , 8 , 13
	.byte	9 , 8
	.byte	PAN , 64
	.byte	N06, Fs2, 52
	.byte	W24
	.byte	Fs3
	.byte	W24
	.byte	N06
	.byte	W24
	.byte	VOICE , 5
	.byte	VOL , 80
	.byte	N21, Fs3, 60
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Gs3
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, An3
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	VOICE , 81
	.byte	VOL , 80
	.byte	N21, Bn3, 60
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Bn4, 52
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Bn3, 60
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Bn4, 52
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N21, Bn3, 60
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N12, Fs4, 52
	.byte	W12
	.byte	An2, 60
	.byte	W12
	.byte	An4, 52
	.byte	W12
	.byte	An2, 60
	.byte	W12
	.byte	Cs5, 52
	.byte	W12
	.byte	An2, 60
	.byte	W12
	.byte	N24, Bn4, 52
	.byte	W12
	.byte	VOL , 76
	.byte	W03
	.byte	65
	.byte	W03
	.byte	41
	.byte	W06
	.byte	80
	.byte	N12, An2, 60
	.byte	W12
	.byte	Ds3
	.byte	W12
	.byte	En3
	.byte	W12
	.byte	Fs3
	.byte	W12
	.byte	N21, Gs3, 60
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	80
	.byte	W06
	.byte	N12, Gs3, 40
	.byte	W12
	.byte	Ds4
	.byte	W12
	.byte	Bn4
	.byte	W12
	.byte	N06, Gs5
	.byte	W06
	.byte	PEND
	.byte	PATT , 47, 9
	.byte	W08
	.byte	GsM2
	.byte	N21, Fs3, 60
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	80
	.byte	W06
	.byte	N12, Fs3, 40
	.byte	W12
	.byte	Cs4
	.byte	W12
	.byte	An4
	.byte	W12
	.byte	N06, Fs5
	.byte	W06
	.byte	N21, An4, 60
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	80
	.byte	N21, An3
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	80
	.byte	N21, Ds4
	.byte	W12
	.byte	VOL , 75
	.byte	W03
	.byte	62
	.byte	W03
	.byte	47
	.byte	W06
	.byte	GOTO , 188, 8
	.byte	W08
	.byte	8
	.byte	FINE
	.globl sSong385_Part5
sSong385_Part5: @ 0x0888098C
	.byte	KEYSH , 0
	.byte	VOL , 80
	.byte	W72
	.byte	W72
	.byte	VOICE , 73
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	N12, Fs5, 48
	.byte	W12
	.byte	En5
	.byte	W12
	.byte	Fs5
	.byte	W12
	.byte	Bn5
	.byte	W12
	.byte	An5
	.byte	W12
	.byte	Gs5
	.byte	W12
	.byte	W72
	.byte	W72
	.byte	An4
	.byte	W24
	.byte	Bn4
	.byte	W24
	.byte	An4
	.byte	W24
	.byte	Fs5
	.byte	W12
	.byte	En5
	.byte	W12
	.byte	Fs5
	.byte	W12
	.byte	An5
	.byte	W12
	.byte	Gs5
	.byte	W12
	.byte	Fs5
	.byte	W12
	.byte	GOTO , 146, 9
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong385_Part6
sSong385_Part6: @ 0x088809BF
	.byte	KEYSH , 0
	.byte	W72
	.byte	VOICE , 126
	.byte	PAN , 16
	.byte	VOL , 75
	.byte	N12, Gs4, 40
	.byte	W24
	.byte	VOICE , 127
	.byte	N06, Gs4, 52
	.byte	W36
	.byte	VOICE , 126
	.byte	N12, Gs4, 40
	.byte	W12
	.byte	VOICE , 127
	.byte	N06, Gs4, 52
	.byte	W12
	.byte	Gs4, 40
	.byte	W12
	.byte	Gs4, 52
	.byte	W12
	.byte	Gs4, 40
	.byte	W12
	.byte	Gs4, 52
	.byte	W12
	.byte	Gs4, 40
	.byte	W12
	.byte	PEND
	.byte	N06, Gs4, 52
	.byte	W12
	.byte	Gs4, 40
	.byte	W12
	.byte	Gs4, 52
	.byte	W12
	.byte	Gs4, 40
	.byte	W12
	.byte	Gs4, 52
	.byte	W12
	.byte	Gs4, 40
	.byte	W12
	.byte	PEND
	.byte	PATT , 238, 9
	.byte	W08
	.byte	GsM2
	.byte	N06, Gs4, 52
	.byte	W12
	.byte	Gs4, 40
	.byte	W12
	.byte	Gs4, 52
	.byte	W12
	.byte	Gs4, 40
	.byte	W12
	.byte	Gs4, 52
	.byte	W12
	.byte	VOICE , 126
	.byte	N06, Gs4, 40
	.byte	W12
	.byte	PEND
	.byte	PATT , 216, 9
	.byte	W08
	.byte	GsM2
	.byte	PATT , 238, 9
	.byte	W08
	.byte	GsM2
	.byte	PATT , 238, 9
	.byte	W08
	.byte	GsM2
	.byte	PATT , 7, 10
	.byte	W08
	.byte	GsM2
	.byte	GOTO , 216, 9
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.globl sSong385_Part7
sSong385_Part7: @ 0x08880A38
	.byte	KEYSH , 0
	.byte	VOL , 80
	.byte	W72
	.byte	N06, Cn1, 112
	.byte	W24
	.byte	N06
	.byte	W24
	.byte	N06
	.byte	W06
	.byte	N03, En1, 52
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N06, En1, 88
	.byte	W12
	.byte	VOICE , 0
	.byte	N06, Cn1, 112
	.byte	W24
	.byte	En1, 88
	.byte	W24
	.byte	Cn1, 112
	.byte	W12
	.byte	En1, 88
	.byte	W12
	.byte	N06, Cn1, 112
	.byte	W24
	.byte	En1, 88
	.byte	W24
	.byte	Cn1, 112
	.byte	W06
	.byte	N03, En1, 52
	.byte	W03
	.byte	N03
	.byte	W03
	.byte	N06, En1, 88
	.byte	W12
	.byte	PEND
	.byte	N06, Cn1, 112
	.byte	W24
	.byte	En1, 88
	.byte	W12
	.byte	Cn1, 112
	.byte	W12
	.byte	N06
	.byte	W12
	.byte	En1, 88
	.byte	W12
	.byte	PEND
	.byte	PATT , 94, 10
	.byte	W08
	.byte	GsM2
	.byte	N06, Cn1, 112
	.byte	W24
	.byte	En1, 88
	.byte	W24
	.byte	Cn1, 112
	.byte	W12
	.byte	En1, 88
	.byte	W12
	.byte	PATT , 94, 10
	.byte	W08
	.byte	GsM2
	.byte	PATT , 115, 10
	.byte	W08
	.byte	GsM2
	.byte	PATT , 94, 10
	.byte	W08
	.byte	GsM2
	.byte	GOTO , 79, 10
	.byte	W08
	.byte	GsM2
	.byte	FINE
	.incbin "baserom_jp.gba", 0x880AAA, 0x2
	.globl sSongHeader_385
sSongHeader_385: @ 0x08880AAC
	.byte 0x08, 0x00, 0x00, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08605834  @ tone
	.4byte 0x088805F8, 0x0888068D, 0x088806DF, 0x0888077C, 0x08880882, 0x0888098C, 0x088809BF, 0x08880A38  @ parts
