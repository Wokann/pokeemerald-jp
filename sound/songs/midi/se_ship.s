.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

	.globl sSong19_Part0
sSong19_Part0: @ 0x0886879C
	.byte	KEYSH , 0
	.byte	TEMPO , 110
	.byte	VOICE , 123
	.byte	VOL , 75
	.byte	N03, Ds3, 127
	.byte	W03
	.byte	TIE , 72
	.byte	W21
	.byte	W24
	.byte	W18
	.byte	VOL , 75
	.byte	W06
	.byte	71
	.byte	W05
	.byte	67
	.byte	W03
	.byte	62
	.byte	W04
	.byte	59
	.byte	W05
	.byte	57
	.byte	W03
	.byte	54
	.byte	W04
	.byte	W02
	.byte	50
	.byte	W03
	.byte	49
	.byte	W03
	.byte	44
	.byte	W04
	.byte	41
	.byte	W02
	.byte	38
	.byte	W03
	.byte	35
	.byte	W03
	.byte	32
	.byte	W04
	.byte	28
	.byte	W02
	.byte	24
	.byte	W03
	.byte	21
	.byte	W03
	.byte	18
	.byte	W04
	.byte	14
	.byte	W02
	.byte	11
	.byte	W03
	.byte	9
	.byte	W03
	.byte	6
	.byte	W04
	.byte	3
	.byte	W02
	.byte	1
	.byte	W22
	.byte	EOT
	.byte	FINE
	.incbin "baserom_jp.gba", 0x8687E1, 0x3
	.globl sSongHeader_19
sSongHeader_19: @ 0x088687E4
	.byte 0x01, 0x00, 0x04, 0xB2  @ trackCount, blockCount, priority, reverb
	.4byte gToneData_08624C14  @ tone
	.4byte sSong19_Part0  @ parts
