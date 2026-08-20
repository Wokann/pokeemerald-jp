.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"



	.globl gUnknown_85FCBF9



	.globl voicegroup_dummy
voicegroup_dummy: @ 0x085FD824
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_085FD824_voice.bin"
	.globl gVoicegroup_085FDB0C
gVoicegroup_085FDB0C: @ 0x085FDB0C
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 0
	.4byte 0x00000002  @ voice 0 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 0 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 1
	.4byte 0x00000002  @ voice 1 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 1 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 2
	.4byte 0x00000002  @ voice 2 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 2 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 3
	.4byte 0x00000002  @ voice 3 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 3 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 4
	.4byte 0x00000002  @ voice 4 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 4 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 5
	.4byte 0x00000002  @ voice 5 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 5 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 6
	.4byte 0x00000002  @ voice 6 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 6 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 7
	.4byte 0x00000002  @ voice 7 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 7 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 8
	.4byte 0x00000002  @ voice 8 wav
	.byte 0x00, 0x01, 0x06, 0x00  @ voice 8 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 9
	.4byte 0x00000002  @ voice 9 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 9 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 10
	.4byte 0x00000002  @ voice 10 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 10 a/d/s/r
	.byte 0x03, 0x3C, 0x00, 0x00  @ voice 11
	.4byte 0x0863C0EC  @ voice 11 wav
	.byte 0x00, 0x07, 0x0F, 0x01  @ voice 11 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 12
	.4byte 0x00000002  @ voice 12 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 12 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 13
	.4byte 0x00000002  @ voice 13 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 13 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 14
	.4byte 0x00000002  @ voice 14 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 14 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 15
	.4byte 0x00000002  @ voice 15 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 15 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 16
	.4byte 0x00000002  @ voice 16 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 16 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 17
	.4byte 0x00000002  @ voice 17 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 17 a/d/s/r
	.byte 0x02, 0x3C, 0x00, 0x00  @ voice 18
	.4byte 0x00000002  @ voice 18 wav
	.byte 0x00, 0x01, 0x06, 0x00  @ voice 18 a/d/s/r
	.byte 0x03, 0x3C, 0x00, 0x00  @ voice 19
	.4byte 0x0863C10C  @ voice 19 wav
	.byte 0x00, 0x07, 0x0F, 0x01  @ voice 19 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 20
	.4byte 0x00000002  @ voice 20 wav
	.byte 0x00, 0x01, 0x06, 0x00  @ voice 20 a/d/s/r
	.byte 0x02, 0x3C, 0x00, 0x00  @ voice 21
	.4byte 0x00000003  @ voice 21 wav
	.byte 0x00, 0x01, 0x06, 0x00  @ voice 21 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 22
	.4byte 0x00000002  @ voice 22 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 22 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 23
	.4byte 0x00000002  @ voice 23 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 23 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 24
	.4byte 0x00000002  @ voice 24 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 24 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 25
	.4byte 0x00000000  @ voice 25 wav
	.byte 0x00, 0x01, 0x06, 0x00  @ voice 25 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 26
	.4byte 0x00000002  @ voice 26 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 26 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 27
	.4byte 0x00000002  @ voice 27 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 27 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 28
	.4byte 0x08641F0C  @ voice 28 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 28 a/d/s/r
	.globl gVoicegroup_085FDC68
gVoicegroup_085FDC68: @ 0x085FDC68
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 0
	.4byte 0x086435BC  @ voice 0 wav
	.byte 0xFF, 0xA5, 0x9A, 0x7F  @ voice 0 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 1
	.4byte 0x08644900  @ voice 1 wav
	.byte 0xFF, 0xA5, 0x9A, 0x7F  @ voice 1 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 2
	.4byte 0x086453A4  @ voice 2 wav
	.byte 0xFF, 0xA5, 0xCE, 0x7F  @ voice 2 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 3
	.4byte 0x086466B8  @ voice 3 wav
	.byte 0xFF, 0xA5, 0xCE, 0x7F  @ voice 3 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 4
	.4byte 0x08649CB4  @ voice 4 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 4 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 5
	.4byte 0x0864A18C  @ voice 5 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 5 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 6
	.4byte 0x0864BA68  @ voice 6 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 6 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 7
	.4byte 0x0864CD90  @ voice 7 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 7 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 8
	.4byte 0x00000002  @ voice 8 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 8 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 9
	.4byte 0x0864D230  @ voice 9 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 9 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 10
	.4byte 0x0864D924  @ voice 10 wav
	.byte 0xFF, 0xFF, 0xFF, 0x7F  @ voice 10 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 11
	.4byte 0x0864E1B4  @ voice 11 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 11 a/d/s/r
	.byte 0x00, 0x30, 0x00, 0xAC  @ voice 12
	.4byte 0x0864EA2C  @ voice 12 wav
	.byte 0xFF, 0xD2, 0x4D, 0xCC  @ voice 12 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xCF  @ voice 13
	.4byte 0x0864FA6C  @ voice 13 wav
	.byte 0xFF, 0x7F, 0x00, 0xBC  @ voice 13 a/d/s/r
	.byte 0x00, 0x33, 0x00, 0xB6  @ voice 14
	.4byte 0x0864EA2C  @ voice 14 wav
	.byte 0xFF, 0xD8, 0x4D, 0xCC  @ voice 14 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 15
	.4byte 0x00000002  @ voice 15 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 15 a/d/s/r
	.byte 0x00, 0x36, 0x00, 0xC0  @ voice 16
	.4byte 0x0864EA2C  @ voice 16 wav
	.byte 0xFF, 0xD8, 0x4D, 0xCC  @ voice 16 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xCF  @ voice 17
	.4byte 0x0864FE80  @ voice 17 wav
	.byte 0xFF, 0xF2, 0x8D, 0x00  @ voice 17 a/d/s/r
	.byte 0x00, 0x39, 0x00, 0xC5  @ voice 18
	.4byte 0x0864EA2C  @ voice 18 wav
	.byte 0xFF, 0xD2, 0x4D, 0xCC  @ voice 18 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0xCF  @ voice 19
	.4byte 0x0864EA2C  @ voice 19 wav
	.byte 0xFF, 0xCC, 0x4D, 0xCC  @ voice 19 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 20
	.4byte 0x00000002  @ voice 20 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 20 a/d/s/r
	.byte 0x00, 0x3E, 0x00, 0xD4  @ voice 21
	.4byte 0x0864EA2C  @ voice 21 wav
	.byte 0xFF, 0xCC, 0x4D, 0xCC  @ voice 21 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 22
	.4byte 0x00000002  @ voice 22 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 22 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 23
	.4byte 0x00000002  @ voice 23 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 23 a/d/s/r
	.byte 0x08, 0x46, 0x00, 0xB1  @ voice 24
	.4byte 0x08650CB0  @ voice 24 wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ voice 24 a/d/s/r
	.byte 0x08, 0x20, 0x00, 0xA2  @ voice 25
	.4byte 0x08651C44  @ voice 25 wav
	.byte 0xFF, 0x7F, 0x4D, 0xCC  @ voice 25 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0x8E  @ voice 26
	.4byte 0x086524F8  @ voice 26 wav
	.byte 0xFF, 0xEB, 0x00, 0xA5  @ voice 26 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 27
	.4byte 0x00000002  @ voice 27 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 27 a/d/s/r
	.byte 0x08, 0x1E, 0x00, 0xB6  @ voice 28
	.4byte 0x08652DDC  @ voice 28 wav
	.byte 0xFF, 0xF6, 0x00, 0xD8  @ voice 28 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 29
	.4byte 0x00000002  @ voice 29 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 29 a/d/s/r
	.byte 0x08, 0x1E, 0x00, 0xB6  @ voice 30
	.4byte 0x08652DDC  @ voice 30 wav
	.byte 0xFF, 0xF6, 0x00, 0xD8  @ voice 30 a/d/s/r
	.byte 0x08, 0x1E, 0x00, 0xC0  @ voice 31
	.4byte 0x08652DDC  @ voice 31 wav
	.byte 0x08, 0x00, 0xFF, 0xD8  @ voice 31 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 32
	.4byte 0x00000002  @ voice 32 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 32 a/d/s/r
	.byte 0x08, 0x48, 0x00, 0xE8  @ voice 33
	.4byte 0x08653D08  @ voice 33 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 33 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 34
	.4byte 0x00000002  @ voice 34 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 34 a/d/s/r
	.byte 0x08, 0x48, 0x00, 0xDE  @ voice 35
	.4byte 0x08654220  @ voice 35 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 35 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 36
	.4byte 0x086547E8  @ voice 36 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 36 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 37
	.4byte 0x08655700  @ voice 37 wav
	.byte 0xFF, 0xB4, 0xAF, 0xE4  @ voice 37 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 38
	.4byte 0x08655700  @ voice 38 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 38 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 39
	.4byte 0x0864D924  @ voice 39 wav
	.byte 0xFF, 0xFF, 0xFF, 0x7F  @ voice 39 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 40
	.4byte 0x0864E1B4  @ voice 40 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 40 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0x98  @ voice 41
	.4byte 0x08657074  @ voice 41 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 41 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD0  @ voice 42
	.4byte 0x0864E1B4  @ voice 42 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 42 a/d/s/r
	.byte 0x00, 0x44, 0x00, 0xA2  @ voice 43
	.4byte 0x08657074  @ voice 43 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 43 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 44
	.4byte 0x0864D230  @ voice 44 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 44 a/d/s/r
	.byte 0x00, 0x48, 0x00, 0xAC  @ voice 45
	.4byte 0x08657074  @ voice 45 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 45 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 46
	.4byte 0x0864D230  @ voice 46 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 46 a/d/s/r
	.byte 0x00, 0x4C, 0x00, 0xD4  @ voice 47
	.4byte 0x08657074  @ voice 47 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 47 a/d/s/r
	.byte 0x00, 0x50, 0x00, 0xDE  @ voice 48
	.4byte 0x08657074  @ voice 48 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 48 a/d/s/r
	.byte 0x08, 0x21, 0x00, 0xD9  @ voice 49
	.4byte 0x08652DDC  @ voice 49 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 49 a/d/s/r
	.byte 0x00, 0x54, 0x00, 0xE8  @ voice 50
	.4byte 0x08657074  @ voice 50 wav
	.byte 0xFF, 0x00, 0xFF, 0xEB  @ voice 50 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 51
	.4byte 0x00000002  @ voice 51 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 51 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 52
	.4byte 0x08652DDC  @ voice 52 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 52 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 53
	.4byte 0x08659150  @ voice 53 wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ voice 53 a/d/s/r
	.globl gVoicegroup_085FDEF0
gVoicegroup_085FDEF0: @ 0x085FDEF0
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 0
	.4byte 0x08651C44  @ voice 0 wav
	.byte 0xFF, 0x7F, 0x4D, 0xCC  @ voice 0 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x8E  @ voice 1
	.4byte 0x086524F8  @ voice 1 wav
	.byte 0xFF, 0xE7, 0x00, 0xBC  @ voice 1 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD9  @ voice 2
	.4byte 0x08660980  @ voice 2 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 2 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x9D  @ voice 3
	.4byte 0x08652DDC  @ voice 3 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 3 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 4
	.4byte 0x00000002  @ voice 4 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 4 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 5
	.4byte 0x08652DDC  @ voice 5 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 5 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 6
	.4byte 0x08652DDC  @ voice 6 wav
	.byte 0x08, 0x00, 0xFF, 0xD8  @ voice 6 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xDE  @ voice 7
	.4byte 0x08661338  @ voice 7 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 7 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 8
	.4byte 0x08653D08  @ voice 8 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 8 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 9
	.4byte 0x08654220  @ voice 9 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 9 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xDA  @ voice 10
	.4byte 0x08654220  @ voice 10 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 10 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 11
	.4byte 0x00000002  @ voice 11 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 11 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 12
	.4byte 0x00000002  @ voice 12 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 12 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 13
	.4byte 0x00000002  @ voice 13 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 13 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 14
	.4byte 0x00000002  @ voice 14 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 14 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 15
	.4byte 0x00000002  @ voice 15 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 15 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 16
	.4byte 0x00000002  @ voice 16 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 16 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 17
	.4byte 0x00000002  @ voice 17 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 17 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 18
	.4byte 0x00000002  @ voice 18 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 18 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 19
	.4byte 0x00000002  @ voice 19 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 19 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 20
	.4byte 0x00000002  @ voice 20 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 20 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 21
	.4byte 0x00000002  @ voice 21 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 21 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 22
	.4byte 0x00000002  @ voice 22 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 22 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 23
	.4byte 0x00000002  @ voice 23 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 23 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 24
	.4byte 0x00000002  @ voice 24 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 24 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 25
	.4byte 0x00000002  @ voice 25 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 25 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA7  @ voice 26
	.4byte 0x086621B8  @ voice 26 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 26 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xCF  @ voice 27
	.4byte 0x086621B8  @ voice 27 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 27 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA7  @ voice 28
	.4byte 0x086621B8  @ voice 28 wav
	.byte 0xFF, 0xA5, 0x67, 0xBC  @ voice 28 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 29
	.4byte 0x0866302C  @ voice 29 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 29 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 30
	.4byte 0x00000002  @ voice 30 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 30 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 31
	.4byte 0x00000002  @ voice 31 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 31 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xE8  @ voice 32
	.4byte 0x08664840  @ voice 32 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 32 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 33
	.4byte 0x08665DE4  @ voice 33 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 33 a/d/s/r
	.byte 0x00, 0x32, 0x00, 0xD4  @ voice 34
	.4byte 0x086673C8  @ voice 34 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 34 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xD4  @ voice 35
	.4byte 0x086673C8  @ voice 35 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 35 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 36
	.4byte 0x08665DE4  @ voice 36 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 36 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 37
	.4byte 0x08655700  @ voice 37 wav
	.byte 0xFF, 0xB4, 0xAF, 0xE4  @ voice 37 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 38
	.4byte 0x08655700  @ voice 38 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 38 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 39
	.4byte 0x0864D924  @ voice 39 wav
	.byte 0xFF, 0xFF, 0xFF, 0x7F  @ voice 39 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 40
	.4byte 0x0864E1B4  @ voice 40 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 40 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0x98  @ voice 41
	.4byte 0x08657074  @ voice 41 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 41 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD0  @ voice 42
	.4byte 0x0864E1B4  @ voice 42 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 42 a/d/s/r
	.byte 0x00, 0x44, 0x00, 0xA2  @ voice 43
	.4byte 0x08657074  @ voice 43 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 43 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 44
	.4byte 0x0864D230  @ voice 44 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 44 a/d/s/r
	.byte 0x00, 0x48, 0x00, 0xAC  @ voice 45
	.4byte 0x08657074  @ voice 45 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 45 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 46
	.4byte 0x00000002  @ voice 46 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 46 a/d/s/r
	.byte 0x00, 0x4C, 0x00, 0xD4  @ voice 47
	.4byte 0x08657074  @ voice 47 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 47 a/d/s/r
	.byte 0x00, 0x50, 0x00, 0xDE  @ voice 48
	.4byte 0x08657074  @ voice 48 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 48 a/d/s/r
	.byte 0x08, 0x21, 0x00, 0xD9  @ voice 49
	.4byte 0x08652DDC  @ voice 49 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 49 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xE8  @ voice 50
	.4byte 0x08665DE4  @ voice 50 wav
	.byte 0xFF, 0x00, 0xFF, 0xEB  @ voice 50 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 51
	.4byte 0x00000002  @ voice 51 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 51 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 52
	.4byte 0x08652DDC  @ voice 52 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 52 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 53
	.4byte 0x08659150  @ voice 53 wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ voice 53 a/d/s/r
	.globl gVoicegroup_085FE178
gVoicegroup_085FE178: @ 0x085FE178
	.byte 0x08, 0x42, 0x00, 0xA2  @ voice 0
	.4byte 0x08651C44  @ voice 0 wav
	.byte 0xFF, 0x7F, 0x4D, 0xCC  @ voice 0 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x8E  @ voice 1
	.4byte 0x086524F8  @ voice 1 wav
	.byte 0xFF, 0xE7, 0x00, 0xBC  @ voice 1 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD9  @ voice 2
	.4byte 0x08660980  @ voice 2 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 2 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x9D  @ voice 3
	.4byte 0x08652DDC  @ voice 3 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 3 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 4
	.4byte 0x00000002  @ voice 4 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 4 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 5
	.4byte 0x08652DDC  @ voice 5 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 5 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 6
	.4byte 0x08652DDC  @ voice 6 wav
	.byte 0x08, 0x00, 0xFF, 0xD8  @ voice 6 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xDE  @ voice 7
	.4byte 0x08661338  @ voice 7 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 7 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 8
	.4byte 0x08653D08  @ voice 8 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 8 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 9
	.4byte 0x08654220  @ voice 9 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 9 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xDA  @ voice 10
	.4byte 0x08654220  @ voice 10 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 10 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 11
	.4byte 0x00000002  @ voice 11 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 11 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 12
	.4byte 0x00000002  @ voice 12 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 12 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 13
	.4byte 0x00000002  @ voice 13 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 13 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 14
	.4byte 0x00000002  @ voice 14 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 14 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 15
	.4byte 0x00000002  @ voice 15 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 15 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 16
	.4byte 0x00000002  @ voice 16 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 16 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 17
	.4byte 0x00000002  @ voice 17 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 17 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 18
	.4byte 0x00000002  @ voice 18 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 18 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 19
	.4byte 0x00000002  @ voice 19 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 19 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 20
	.4byte 0x00000002  @ voice 20 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 20 a/d/s/r
	.byte 0x08, 0x3D, 0x00, 0xD4  @ voice 21
	.4byte 0x0864BA68  @ voice 21 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 21 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 22
	.4byte 0x0864A18C  @ voice 22 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 22 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 23
	.4byte 0x00000002  @ voice 23 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 23 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 24
	.4byte 0x00000002  @ voice 24 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 24 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 25
	.4byte 0x00000002  @ voice 25 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 25 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA7  @ voice 26
	.4byte 0x086621B8  @ voice 26 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 26 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xCF  @ voice 27
	.4byte 0x086621B8  @ voice 27 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 27 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA7  @ voice 28
	.4byte 0x086621B8  @ voice 28 wav
	.byte 0xFF, 0xA5, 0x67, 0xBC  @ voice 28 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 29
	.4byte 0x0866302C  @ voice 29 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 29 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 30
	.4byte 0x00000002  @ voice 30 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 30 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 31
	.4byte 0x00000002  @ voice 31 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 31 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xE8  @ voice 32
	.4byte 0x08664840  @ voice 32 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 32 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 33
	.4byte 0x08665DE4  @ voice 33 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 33 a/d/s/r
	.byte 0x00, 0x32, 0x00, 0xD4  @ voice 34
	.4byte 0x086673C8  @ voice 34 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 34 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xD4  @ voice 35
	.4byte 0x086673C8  @ voice 35 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 35 a/d/s/r
	.byte 0x00, 0x3E, 0x00, 0xC0  @ voice 36
	.4byte 0x086547E8  @ voice 36 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 36 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 37
	.4byte 0x08655700  @ voice 37 wav
	.byte 0xFF, 0xB4, 0xAF, 0xE4  @ voice 37 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 38
	.4byte 0x08655700  @ voice 38 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 38 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 39
	.4byte 0x0864D924  @ voice 39 wav
	.byte 0xFF, 0xFF, 0xFF, 0x7F  @ voice 39 a/d/s/r
	.byte 0x00, 0x41, 0x00, 0xC0  @ voice 40
	.4byte 0x0864E1B4  @ voice 40 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 40 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0x98  @ voice 41
	.4byte 0x08657074  @ voice 41 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 41 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD0  @ voice 42
	.4byte 0x0864E1B4  @ voice 42 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 42 a/d/s/r
	.byte 0x00, 0x44, 0x00, 0xA2  @ voice 43
	.4byte 0x08657074  @ voice 43 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 43 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 44
	.4byte 0x0864D230  @ voice 44 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 44 a/d/s/r
	.byte 0x00, 0x48, 0x00, 0xAC  @ voice 45
	.4byte 0x08657074  @ voice 45 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 45 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 46
	.4byte 0x00000002  @ voice 46 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 46 a/d/s/r
	.byte 0x00, 0x4C, 0x00, 0xD4  @ voice 47
	.4byte 0x08657074  @ voice 47 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 47 a/d/s/r
	.byte 0x00, 0x50, 0x00, 0xDE  @ voice 48
	.4byte 0x08657074  @ voice 48 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 48 a/d/s/r
	.byte 0x00, 0x38, 0x00, 0xD9  @ voice 49
	.4byte 0x08652DDC  @ voice 49 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 49 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xE8  @ voice 50
	.4byte 0x08665DE4  @ voice 50 wav
	.byte 0xFF, 0x00, 0xFF, 0xEB  @ voice 50 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 51
	.4byte 0x00000002  @ voice 51 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 51 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 52
	.4byte 0x08652DDC  @ voice 52 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 52 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 53
	.4byte 0x08659150  @ voice 53 wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ voice 53 a/d/s/r
	.byte 0x08, 0x42, 0x00, 0xA2  @ voice 54
	.4byte 0x08651C44  @ voice 54 wav
	.byte 0xFF, 0x7F, 0x4D, 0xCC  @ voice 54 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0x8E  @ voice 55
	.4byte 0x086524F8  @ voice 55 wav
	.byte 0xFF, 0xE7, 0x00, 0xBC  @ voice 55 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xD9  @ voice 56
	.4byte 0x08660980  @ voice 56 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 56 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x9D  @ voice 57
	.4byte 0x08652DDC  @ voice 57 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 57 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 58
	.4byte 0x00000002  @ voice 58 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 58 a/d/s/r
	.byte 0x00, 0x3A, 0x00, 0xB6  @ voice 59
	.4byte 0x08652DDC  @ voice 59 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 59 a/d/s/r
	.byte 0x00, 0x3E, 0x00, 0xB6  @ voice 60
	.4byte 0x08652DDC  @ voice 60 wav
	.byte 0x08, 0x00, 0xFF, 0xD8  @ voice 60 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xDE  @ voice 61
	.4byte 0x08661338  @ voice 61 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 61 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xA2  @ voice 62
	.4byte 0x08653D08  @ voice 62 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 62 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xA2  @ voice 63
	.4byte 0x08654220  @ voice 63 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 63 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xDA  @ voice 64
	.4byte 0x08654220  @ voice 64 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 64 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 65
	.4byte 0x00000002  @ voice 65 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 65 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 66
	.4byte 0x00000002  @ voice 66 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 66 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 67
	.4byte 0x00000002  @ voice 67 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 67 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 68
	.4byte 0x00000002  @ voice 68 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 68 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 69
	.4byte 0x00000002  @ voice 69 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 69 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 70
	.4byte 0x00000002  @ voice 70 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 70 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 71
	.4byte 0x00000002  @ voice 71 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 71 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 72
	.4byte 0x00000002  @ voice 72 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 72 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 73
	.4byte 0x00000002  @ voice 73 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 73 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 74
	.4byte 0x00000002  @ voice 74 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 74 a/d/s/r
	.byte 0x00, 0x3D, 0x00, 0xD4  @ voice 75
	.4byte 0x0864BA68  @ voice 75 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 75 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xC0  @ voice 76
	.4byte 0x0864A18C  @ voice 76 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 76 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 77
	.4byte 0x00000002  @ voice 77 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 77 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 78
	.4byte 0x00000002  @ voice 78 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 78 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 79
	.4byte 0x00000002  @ voice 79 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 79 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xA7  @ voice 80
	.4byte 0x086621B8  @ voice 80 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 80 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xCF  @ voice 81
	.4byte 0x086621B8  @ voice 81 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 81 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xA7  @ voice 82
	.4byte 0x086621B8  @ voice 82 wav
	.byte 0xFF, 0xA5, 0x67, 0xBC  @ voice 82 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 83
	.4byte 0x0866302C  @ voice 83 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 83 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 84
	.4byte 0x00000002  @ voice 84 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 84 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 85
	.4byte 0x00000002  @ voice 85 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 85 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xE8  @ voice 86
	.4byte 0x08664840  @ voice 86 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 86 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 87
	.4byte 0x08665DE4  @ voice 87 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 87 a/d/s/r
	.byte 0x00, 0x32, 0x00, 0xD4  @ voice 88
	.4byte 0x086673C8  @ voice 88 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 88 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xD4  @ voice 89
	.4byte 0x086673C8  @ voice 89 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 89 a/d/s/r
	.incbin "baserom_jp.gba", 0x5FE5B0, 0x6A8
	.globl gToneData_085FEC58
gToneData_085FEC58: @ 0x085FEC58
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08604358  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_085FEC58_voice.bin"
	.globl gToneData_085FF048
gToneData_085FF048: @ 0x085FF048
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08601F58  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_085FF048_voice.bin"
	.globl gToneData_085FF648
gToneData_085FF648: @ 0x085FF648
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_085FF648_voice.bin"
	.globl gToneData_085FFB10
gToneData_085FFB10: @ 0x085FFB10
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_085FFB10_voice.bin"
	.globl gToneData_085FFF48
gToneData_085FFF48: @ 0x085FFF48
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_085FFF48_voice.bin"
	.globl gToneData_08600344
gToneData_08600344: @ 0x08600344
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08600794  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08600344_voice.bin"
	.globl gToneData_08600AA0
gToneData_08600AA0: @ 0x08600AA0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08600AA0_voice.bin"
	.globl gToneData_08600EE4
gToneData_08600EE4: @ 0x08600EE4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08600EE4_voice.bin"
	.globl gToneData_086014E4
gToneData_086014E4: @ 0x086014E4
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086014E4_voice.bin"
	.globl gToneData_086018E0
gToneData_086018E0: @ 0x086018E0
	.byte 0x40, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x085FE5B0  @ wav
	.byte 0x54, 0xBF, 0x63, 0x08  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086018E0_voice.bin"
	.globl gToneData_08601CF4
gToneData_08601CF4: @ 0x08601CF4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08601CF4_voice.bin"
	.globl gToneData_08602264
gToneData_08602264: @ 0x08602264
	.byte 0x40, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x085FE5B0  @ wav
	.byte 0x54, 0xBF, 0x63, 0x08  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08602264_voice.bin"
	.globl gToneData_08602690
gToneData_08602690: @ 0x08602690
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08602690_voice.bin"
	.globl gToneData_08602AD4
gToneData_08602AD4: @ 0x08602AD4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08602AD4_voice.bin"
	.globl gToneData_08602EC4
gToneData_08602EC4: @ 0x08602EC4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08602EC4_voice.bin"
	.globl gToneData_086032C0
gToneData_086032C0: @ 0x086032C0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086032C0_voice.bin"
	.globl gToneData_086038C0
gToneData_086038C0: @ 0x086038C0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086038C0_voice.bin"
	.globl gToneData_08603CA4
gToneData_08603CA4: @ 0x08603CA4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08603CA4_voice.bin"
	.globl gToneData_086040C4
gToneData_086040C4: @ 0x086040C4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08604358  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086040C4_voice.bin"
	.globl gToneData_08604664
gToneData_08604664: @ 0x08604664
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08600794  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08604664_voice.bin"
	.globl gToneData_08604C64
gToneData_08604C64: @ 0x08604C64
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08604C64_voice.bin"
	.globl gToneData_08605048
gToneData_08605048: @ 0x08605048
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08605048_voice.bin"
	.globl gToneData_08605438
gToneData_08605438: @ 0x08605438
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08604358  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08605438_voice.bin"
	.globl gToneData_08605834
gToneData_08605834: @ 0x08605834
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08605834_voice.bin"
	.globl gToneData_08605E34
gToneData_08605E34: @ 0x08605E34
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08604358  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08605E34_voice.bin"
	.globl gToneData_08606260
gToneData_08606260: @ 0x08606260
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08606260_voice.bin"
	.globl gToneData_08606638
gToneData_08606638: @ 0x08606638
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08606638_voice.bin"
	.globl gToneData_08606C38
gToneData_08606C38: @ 0x08606C38
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08606C38_voice.bin"
	.globl gToneData_08607238
gToneData_08607238: @ 0x08607238
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08607238_voice.bin"
	.globl gToneData_08607838
gToneData_08607838: @ 0x08607838
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08607838_voice.bin"
	.globl gToneData_08607E38
gToneData_08607E38: @ 0x08607E38
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08607E38_voice.bin"
	.globl gToneData_08608204
gToneData_08608204: @ 0x08608204
	.byte 0x40, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x085FE5B0  @ wav
	.byte 0x54, 0xBF, 0x63, 0x08  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08608204_voice.bin"
	.globl gToneData_086085D0
gToneData_086085D0: @ 0x086085D0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086085D0_voice.bin"
	.globl gToneData_08608BD0
gToneData_08608BD0: @ 0x08608BD0
	.byte 0x40, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x085FE5B0  @ wav
	.byte 0x54, 0xBF, 0x63, 0x08  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08608BD0_voice.bin"
	.globl gToneData_086091D0
gToneData_086091D0: @ 0x086091D0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086091D0_voice.bin"
	.globl gToneData_086097D0
gToneData_086097D0: @ 0x086097D0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086097D0_voice.bin"
	.globl gToneData_08609BF0
gToneData_08609BF0: @ 0x08609BF0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08609BF0_voice.bin"
	.globl gToneData_0860A1F0
gToneData_0860A1F0: @ 0x0860A1F0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860A1F0_voice.bin"
	.globl gToneData_0860A7F0
gToneData_0860A7F0: @ 0x0860A7F0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860A7F0_voice.bin"
	.globl gToneData_0860AB68
gToneData_0860AB68: @ 0x0860AB68
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860AB68_voice.bin"
	.globl gToneData_0860B168
gToneData_0860B168: @ 0x0860B168
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860B168_voice.bin"
	.globl gToneData_0860B768
gToneData_0860B768: @ 0x0860B768
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860B768_voice.bin"
	.globl gToneData_0860BD68
gToneData_0860BD68: @ 0x0860BD68
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860BD68_voice.bin"
	.globl gToneData_0860C368
gToneData_0860C368: @ 0x0860C368
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860C368_voice.bin"
	.globl gToneData_0860C968
gToneData_0860C968: @ 0x0860C968
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860C968_voice.bin"
	.globl gToneData_0860CF68
gToneData_0860CF68: @ 0x0860CF68
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860CF68_voice.bin"
	.globl gToneData_0860D568
gToneData_0860D568: @ 0x0860D568
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860D568_voice.bin"
	.globl gToneData_0860D994
gToneData_0860D994: @ 0x0860D994
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860D994_voice.bin"
	.globl gToneData_0860DF94
gToneData_0860DF94: @ 0x0860DF94
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860DF94_voice.bin"
	.globl gToneData_0860E594
gToneData_0860E594: @ 0x0860E594
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860E594_voice.bin"
	.globl gToneData_0860EB94
gToneData_0860EB94: @ 0x0860EB94
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860EB94_voice.bin"
	.globl gToneData_0860F194
gToneData_0860F194: @ 0x0860F194
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860F194_voice.bin"
	.globl gToneData_0860F794
gToneData_0860F794: @ 0x0860F794
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860F794_voice.bin"
	.globl gToneData_0860FD94
gToneData_0860FD94: @ 0x0860FD94
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0860FD94_voice.bin"
	.globl gToneData_08610394
gToneData_08610394: @ 0x08610394
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08610394_voice.bin"
	.globl gToneData_08610994
gToneData_08610994: @ 0x08610994
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08610994_voice.bin"
	.globl gToneData_08610F94
gToneData_08610F94: @ 0x08610F94
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08610F94_voice.bin"
	.globl gToneData_08611594
gToneData_08611594: @ 0x08611594
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08611594_voice.bin"
	.globl gToneData_08611B94
gToneData_08611B94: @ 0x08611B94
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08611B94_voice.bin"
	.globl gToneData_08612194
gToneData_08612194: @ 0x08612194
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08612194_voice.bin"
	.globl gToneData_08612794
gToneData_08612794: @ 0x08612794
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08612794_voice.bin"
	.globl gToneData_08612D94
gToneData_08612D94: @ 0x08612D94
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08612D94_voice.bin"
	.globl gToneData_08613394
gToneData_08613394: @ 0x08613394
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08613394_voice.bin"
	.globl gToneData_08613994
gToneData_08613994: @ 0x08613994
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08613994_voice.bin"
	.globl gToneData_08613F94
gToneData_08613F94: @ 0x08613F94
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08613F94_voice.bin"
	.globl gToneData_08614594
gToneData_08614594: @ 0x08614594
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08614594_voice.bin"
	.globl gToneData_08614B94
gToneData_08614B94: @ 0x08614B94
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08614B94_voice.bin"
	.globl gToneData_08615194
gToneData_08615194: @ 0x08615194
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08615194_voice.bin"
	.globl gToneData_08615794
gToneData_08615794: @ 0x08615794
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08615794_voice.bin"
	.globl gToneData_086157AC
gToneData_086157AC: @ 0x086157AC
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086157AC_voice.bin"
	.globl gToneData_08615DAC
gToneData_08615DAC: @ 0x08615DAC
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08615DAC_voice.bin"
	.globl gToneData_0861619C
gToneData_0861619C: @ 0x0861619C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861619C_voice.bin"
	.globl gToneData_0861679C
gToneData_0861679C: @ 0x0861679C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861679C_voice.bin"
	.globl gToneData_08616D9C
gToneData_08616D9C: @ 0x08616D9C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08616D9C_voice.bin"
	.globl gToneData_0861739C
gToneData_0861739C: @ 0x0861739C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861739C_voice.bin"
	.globl gToneData_0861799C
gToneData_0861799C: @ 0x0861799C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861799C_voice.bin"
	.globl gToneData_08617F9C
gToneData_08617F9C: @ 0x08617F9C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08617F9C_voice.bin"
	.globl gToneData_0861859C
gToneData_0861859C: @ 0x0861859C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861859C_voice.bin"
	.globl gToneData_08618B9C
gToneData_08618B9C: @ 0x08618B9C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08618B9C_voice.bin"
	.globl gToneData_0861919C
gToneData_0861919C: @ 0x0861919C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861919C_voice.bin"
	.globl gToneData_0861979C
gToneData_0861979C: @ 0x0861979C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861979C_voice.bin"
	.globl gToneData_08619D9C
gToneData_08619D9C: @ 0x08619D9C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08619D9C_voice.bin"
	.globl gToneData_0861A39C
gToneData_0861A39C: @ 0x0861A39C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861A39C_voice.bin"
	.globl gToneData_0861A99C
gToneData_0861A99C: @ 0x0861A99C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861A99C_voice.bin"
	.globl gToneData_0861AF9C
gToneData_0861AF9C: @ 0x0861AF9C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861AF9C_voice.bin"
	.globl gToneData_0861B59C
gToneData_0861B59C: @ 0x0861B59C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861B59C_voice.bin"
	.globl gToneData_0861BB9C
gToneData_0861BB9C: @ 0x0861BB9C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861BB9C_voice.bin"
	.globl gToneData_0861C19C
gToneData_0861C19C: @ 0x0861C19C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861C19C_voice.bin"
	.globl gToneData_0861C79C
gToneData_0861C79C: @ 0x0861C79C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861C79C_voice.bin"
	.globl gToneData_0861CCC4
gToneData_0861CCC4: @ 0x0861CCC4
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861CCC4_voice.bin"
	.globl gToneData_0861D09C
gToneData_0861D09C: @ 0x0861D09C
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861D09C_voice.bin"
	.globl gToneData_0861D69C
gToneData_0861D69C: @ 0x0861D69C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDEF0  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861D69C_voice.bin"
	.globl gToneData_0861DBAC
gToneData_0861DBAC: @ 0x0861DBAC
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861DBAC_voice.bin"
	.globl gToneData_0861DF90
gToneData_0861DF90: @ 0x0861DF90
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861DF90_voice.bin"
	.globl gToneData_0861E590
gToneData_0861E590: @ 0x0861E590
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861E590_voice.bin"
	.globl gToneData_0861EB90
gToneData_0861EB90: @ 0x0861EB90
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FE178  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861EB90_voice.bin"
	.globl gToneData_0861F190
gToneData_0861F190: @ 0x0861F190
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FE178  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861F190_voice.bin"
	.globl gToneData_0861F574
gToneData_0861F574: @ 0x0861F574
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861F574_voice.bin"
	.globl gToneData_0861FB74
gToneData_0861FB74: @ 0x0861FB74
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0861FB74_voice.bin"
	.globl gToneData_08620174
gToneData_08620174: @ 0x08620174
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDEF0  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08620174_voice.bin"
	.globl gToneData_08620774
gToneData_08620774: @ 0x08620774
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08620774_voice.bin"
	.globl gToneData_08620D74
gToneData_08620D74: @ 0x08620D74
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08620D74_voice.bin"
	.globl gToneData_08621374
gToneData_08621374: @ 0x08621374
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08621374_voice.bin"
	.globl gToneData_08621974
gToneData_08621974: @ 0x08621974
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08621974_voice.bin"
	.globl gToneData_08621F74
gToneData_08621F74: @ 0x08621F74
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08621F74_voice.bin"
	.globl gToneData_0862234C
gToneData_0862234C: @ 0x0862234C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862234C_voice.bin"
	.globl gToneData_08622790
gToneData_08622790: @ 0x08622790
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08622790_voice.bin"
	.globl gToneData_08622BD4
gToneData_08622BD4: @ 0x08622BD4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08622BD4_voice.bin"
	.globl gToneData_08623018
gToneData_08623018: @ 0x08623018
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08623018_voice.bin"
	.globl gToneData_08623420
gToneData_08623420: @ 0x08623420
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08623420_voice.bin"
	.globl gToneData_08623810
gToneData_08623810: @ 0x08623810
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08623810_voice.bin"
	.globl gToneData_08623E10
gToneData_08623E10: @ 0x08623E10
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08623E10_voice.bin"
	.globl gToneData_08624224
gToneData_08624224: @ 0x08624224
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08624224_voice.bin"
	.globl gToneData_08624614
gToneData_08624614: @ 0x08624614
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08624614_voice.bin"
	.globl gToneData_08624C14
gToneData_08624C14: @ 0x08624C14
	.byte 0x00, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte DirectSoundWaveData_unknown_synth_snare  @ wav
	.byte 0xFF, 0xF9, 0x67, 0xA5  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08624C14_voice.bin"
	.globl gToneData_08625214
gToneData_08625214: @ 0x08625214
	.byte 0x08, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x086AB7F0  @ wav
	.byte 0xFF, 0xF9, 0x00, 0xA5  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08625214_voice.bin"

	.globl gJP_CryTable_Normal_0
gJP_CryTable_Normal_0: @ 0x08625814
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte 0x086CDE28  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte 0x086CEEB4  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte 0x086CFF44  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte 0x086D129C  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte 0x086D210C  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte 0x086D2F8C  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte 0x086D42D4  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte 0x086D5148  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte 0x086D6288  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte 0x086D75D0  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte 0x086D7E28  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte 0x086D9578  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte 0x086D9F80  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte 0x086DAFC4  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte 0x086DC200  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte 0x086DD55C  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte 0x086DD944  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte 0x086DE84C  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte 0x086DF980  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte 0x086E0160  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte 0x086E0AE4  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte 0x086E1C88  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte 0x086E2DC4  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte 0x086E4110  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte 0x086E5468  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte 0x086E6510  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte 0x086E7CD0  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte 0x086E8624  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte 0x086E93B4  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte 0x086E9D64  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte 0x086EAA2C  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte 0x086EBB0C  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte 0x086EC574  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte 0x086ED188  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte 0x086EE9F4  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte 0x086EF264  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte 0x086EFCF4  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte 0x086F14C4  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte 0x086F2D30  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte 0x086F3294  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte 0x086F395C  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte 0x086F4CC8  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte 0x086F602C  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte 0x086F6EC8  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte 0x086F7B44  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte 0x086F94E0  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte 0x086FB0D4  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte 0x086FCF3C  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte 0x086FDEBC  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte 0x086FEEC0  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte 0x08700230  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte 0x0870159C  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte 0x08701F2C  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte 0x08703208  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte 0x08703F30  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte 0x08704A78  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte 0x08705AD8  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte 0x08706B08  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte 0x0870786C  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte 0x087089A8  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte 0x087094C4  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte 0x08709B6C  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte 0x0870A690  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte 0x0870BDF4  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte 0x0870D8DC  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte 0x0870F878  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte 0x087105DC  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte 0x0871136C  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte 0x087123F4  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte 0x08712B80  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte 0x08713A20  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte 0x08714D6C  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte 0x08715D5C  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte 0x08717458  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte 0x08718C0C  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte 0x0871A7F4  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte 0x0871B620  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte 0x0871C530  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte 0x0871D7D0  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte 0x0871DF38  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte 0x0871ECA8  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte 0x0871FFEC  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte 0x087217D4  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte 0x08721F50  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte 0x08723294  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte 0x0872460C  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte 0x087257FC  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte 0x08726D20  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte 0x087277A8  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte 0x08728668  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte 0x087295DC  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte 0x0872AAA0  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte 0x0872C1F0  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte 0x0872D970  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte 0x0872E830  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte 0x087300F4  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte 0x08731E0C  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte 0x08733B10  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte 0x0873535C  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte 0x08736BB4  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte 0x08738478  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte 0x08739DB0  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte 0x0873B090  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte 0x0873D074  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte 0x0873DF94  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte 0x0873EE04  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte 0x087400B0  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte 0x08741288  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte 0x087421B0  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte 0x0874360C  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte 0x08744BB8  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte 0x08745F24  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte 0x08747390  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte 0x0874825C  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte 0x08749178  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte 0x0874A42C  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte 0x0874ADA8  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte 0x0874B614  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte 0x0874BFEC  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte 0x0874D344  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte 0x0874E72C  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte 0x0874FC08  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte 0x08750EF8  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte 0x08751C54  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte 0x08754BC8  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte 0x08756AAC  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte 0x08757A28  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte 0x08758684  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Normal_1
gJP_CryTable_Normal_1: @ 0x08625E14
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte 0x087598D8  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte 0x0875ABE0  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte 0x0875C014  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte 0x0875CEE8  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte 0x0875DA04  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte 0x0875E83C  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte 0x0875FE54  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte 0x08760E28  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte 0x08761DAC  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte 0x087631B8  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte 0x08763F10  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte 0x08764C64  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte 0x087658B8  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte 0x08766674  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte 0x08767ED0  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte 0x0876840C  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte 0x08769BB4  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte 0x0876AB2C  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte 0x0876C2D8  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte 0x0876CE74  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte 0x0876DF1C  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte 0x0876F228  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte 0x08771090  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte 0x08772EF8  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte 0x08773438  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte 0x08773D04  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte 0x08774D3C  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte 0x08775440  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte 0x08776028  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte 0x08778638  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte 0x08779890  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte 0x0877ACCC  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte 0x0877C650  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte 0x0877CA78  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte 0x0877D0C0  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte 0x0877DBA4  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte 0x0877F0D4  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte 0x0877F7CC  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte 0x08780030  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte 0x08780D94  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte 0x087819E8  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte 0x08783118  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte 0x08783DC8  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte 0x08784854  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte 0x08784FA8  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte 0x08785598  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte 0x08785C94  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte 0x0878677C  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte 0x08786E7C  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte 0x0878790C  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte 0x087887D8  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte 0x08788F30  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte 0x08789CE4  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte 0x0878AD64  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte 0x0878BB7C  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte 0x0878C890  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte 0x0878D97C  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte 0x0878E9AC  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte 0x0878FBF0  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte 0x0879045C  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte 0x08791164  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte 0x087921A0  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte 0x08792FC0  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte 0x087937D4  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte 0x087947B4  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte 0x087958BC  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte 0x0879601C  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte 0x08796D7C  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte 0x08798130  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte 0x087990B0  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte 0x0879A174  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte 0x0879B958  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte 0x0879C4F8  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte 0x0879D220  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte 0x0879E6BC  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte 0x0879F570  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte 0x087A02D0  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte 0x087A16D8  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte 0x087A26B8  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte 0x087A32D8  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte 0x087A5900  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte 0x087A6774  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte 0x087A7F18  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte 0x087A8AB4  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte 0x087AA1B0  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte 0x087AABE4  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte 0x087ABE38  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte 0x087AC75C  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte 0x087AD7E8  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte 0x087AF5C0  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte 0x087B06D8  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte 0x087B1BE0  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte 0x087B2888  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte 0x087B357C  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte 0x087B425C  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte 0x087B4CEC  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte 0x087B6730  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte 0x087B7764  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte 0x087B872C  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte 0x087B9F34  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte 0x087BABDC  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte 0x087BBF8C  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte 0x087BCD64  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte 0x087BD8B4  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte 0x087BE9D8  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte 0x087BF990  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte 0x087C100C  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte 0x087C1A40  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte 0x087C2A68  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte 0x087C3848  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte 0x087C43FC  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte 0x087C4E88  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte 0x087C5CF8  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte 0x087C6BD4  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte 0x087C7C68  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte 0x087C8DD8  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte 0x087CA24C  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte 0x087CB494  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte 0x087CC144  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte 0x087CC9B4  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte 0x087CE114  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte 0x087D070C  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte 0x087D1DA0  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte 0x087D2C18  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte 0x087D3478  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte 0x087D3F38  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte 0x087D4884  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte 0x087D54E0  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Normal_2
gJP_CryTable_Normal_2: @ 0x08626414
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte 0x087D69E8  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte 0x087D7480  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte 0x087D80B0  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte 0x087D8E90  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte 0x087D9A30  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte 0x087DB13C  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte 0x087DBACC  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte 0x087DC534  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte 0x087DCACC  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte 0x087DD5E8  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte 0x087DDF3C  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte 0x087DE53C  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte 0x087DEE40  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte 0x087DFFF0  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte 0x087E0C5C  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte 0x087E1604  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte 0x087E32D8  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte 0x087E5258  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte 0x087E5E00  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte 0x087E7274  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte 0x087E8C90  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte 0x087E9414  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte 0x087EA518  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte 0x087EBB98  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte 0x087EC760  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte 0x087ED3A0  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte 0x087EE048  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte 0x087EE888  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte 0x087EECF0  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte 0x087EFB84  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte 0x087F0C54  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte 0x087F1480  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte 0x087F1FE8  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte 0x087F33AC  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte 0x087F3DC0  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte 0x087F468C  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte 0x087F56B8  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte 0x087F5EF0  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte 0x087F6F34  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte 0x087F7BE0  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte 0x087F85FC  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte 0x087F922C  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte 0x087FAA90  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte 0x087FB314  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte 0x087FC16C  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte 0x087FCB58  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte 0x087FD1C8  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte 0x087FDDF0  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte 0x087FE5A8  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte 0x087FED04  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte 0x087FFDBC  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte 0x08800B20  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte 0x08802004  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte 0x08802900  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte 0x08803908  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte 0x08804388  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte 0x0880573C  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte 0x08805E50  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte 0x08807368  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte 0x08807B6C  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte 0x08808CCC  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte 0x08809618  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte 0x0880AD38  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte 0x0880B674  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte 0x0880C770  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte 0x0880D374  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte 0x0880EC2C  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte 0x0880F36C  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte 0x0881000C  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte 0x08810A30  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte 0x08811834  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte 0x0881323C  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte 0x08813B2C  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte 0x088151DC  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte 0x08815E60  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte 0x088171C0  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte 0x088189BC  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte 0x088199E8  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte 0x0881A1BC  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte 0x0881C900  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte 0x0881D37C  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte 0x0881DB9C  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte 0x0881EC20  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte 0x0881F1D4  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte 0x0881FDAC  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte 0x088221F8  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte 0x08823448  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte 0x08824430  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte 0x08825A9C  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte 0x08826444  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte 0x08828174  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte 0x08828D2C  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte 0x0882A400  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte 0x0882ADA0  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte 0x0882C074  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte 0x0882E7EC  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte 0x0882EFC0  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte 0x088303C8  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte 0x088323A4  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte 0x088343A4  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte 0x08835AA8  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte 0x08836740  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte 0x088372C8  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte 0x088383E0  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte 0x08838D28  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte 0x0883A0B4  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte 0x0883AE6C  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte 0x0883BA10  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte 0x0883C590  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte 0x0883CEBC  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte 0x0883E394  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte 0x0883FD38  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte 0x08841168  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte 0x08841644  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte 0x08843B50  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte 0x08845F08  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte 0x08847C34  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte 0x08849550  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte 0x0884A210  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte 0x0884AAE8  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte 0x0884C984  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte 0x0884EA48  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte 0x088506A8  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte 0x08851238  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte 0x08852E80  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte 0x08853BA8  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte 0x088565B8  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte 0x08856DDC  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Normal_3
gJP_CryTable_Normal_3: @ 0x08626A14
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte 0x08857EE4  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte 0x088594DC  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte 0x0885A260  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte 0x0885B734  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release

	.globl gJP_CryTable_Reverse_0
gJP_CryTable_Reverse_0: @ 0x08626A44
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte 0x086CDE28  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte 0x086CEEB4  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte 0x086CFF44  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte 0x086D129C  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte 0x086D210C  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte 0x086D2F8C  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte 0x086D42D4  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte 0x086D5148  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte 0x086D6288  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte 0x086D75D0  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte 0x086D7E28  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte 0x086D9578  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte 0x086D9F80  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte 0x086DAFC4  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte 0x086DC200  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte 0x086DD55C  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte 0x086DD944  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte 0x086DE84C  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte 0x086DF980  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte 0x086E0160  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte 0x086E0AE4  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte 0x086E1C88  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte 0x086E2DC4  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte 0x086E4110  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte 0x086E5468  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte 0x086E6510  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte 0x086E7CD0  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte 0x086E8624  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte 0x086E93B4  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte 0x086E9D64  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte 0x086EAA2C  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte 0x086EBB0C  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte 0x086EC574  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte 0x086ED188  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte 0x086EE9F4  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte 0x086EF264  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte 0x086EFCF4  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte 0x086F14C4  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte 0x086F2D30  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte 0x086F3294  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte 0x086F395C  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte 0x086F4CC8  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte 0x086F602C  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte 0x086F6EC8  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte 0x086F7B44  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte 0x086F94E0  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte 0x086FB0D4  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte 0x086FCF3C  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte 0x086FDEBC  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte 0x086FEEC0  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte 0x08700230  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte 0x0870159C  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte 0x08701F2C  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte 0x08703208  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte 0x08703F30  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte 0x08704A78  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte 0x08705AD8  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte 0x08706B08  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte 0x0870786C  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte 0x087089A8  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte 0x087094C4  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte 0x08709B6C  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte 0x0870A690  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte 0x0870BDF4  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte 0x0870D8DC  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte 0x0870F878  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte 0x087105DC  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte 0x0871136C  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte 0x087123F4  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte 0x08712B80  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte 0x08713A20  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte 0x08714D6C  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte 0x08715D5C  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte 0x08717458  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte 0x08718C0C  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte 0x0871A7F4  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte 0x0871B620  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte 0x0871C530  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte 0x0871D7D0  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte 0x0871DF38  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte 0x0871ECA8  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte 0x0871FFEC  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte 0x087217D4  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte 0x08721F50  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte 0x08723294  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte 0x0872460C  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte 0x087257FC  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte 0x08726D20  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte 0x087277A8  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte 0x08728668  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte 0x087295DC  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte 0x0872AAA0  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte 0x0872C1F0  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte 0x0872D970  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte 0x0872E830  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte 0x087300F4  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte 0x08731E0C  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte 0x08733B10  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte 0x0873535C  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte 0x08736BB4  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte 0x08738478  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte 0x08739DB0  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte 0x0873B090  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte 0x0873D074  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte 0x0873DF94  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte 0x0873EE04  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte 0x087400B0  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte 0x08741288  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte 0x087421B0  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte 0x0874360C  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte 0x08744BB8  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte 0x08745F24  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte 0x08747390  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte 0x0874825C  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte 0x08749178  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte 0x0874A42C  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte 0x0874ADA8  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte 0x0874B614  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte 0x0874BFEC  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte 0x0874D344  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte 0x0874E72C  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte 0x0874FC08  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte 0x08750EF8  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte 0x08751C54  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte 0x08754BC8  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte 0x08756AAC  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte 0x08757A28  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte 0x08758684  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Reverse_1
gJP_CryTable_Reverse_1: @ 0x08627044
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte 0x087598D8  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte 0x0875ABE0  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte 0x0875C014  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte 0x0875CEE8  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte 0x0875DA04  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte 0x0875E83C  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte 0x0875FE54  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte 0x08760E28  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte 0x08761DAC  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte 0x087631B8  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte 0x08763F10  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte 0x08764C64  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte 0x087658B8  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte 0x08766674  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte 0x08767ED0  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte 0x0876840C  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte 0x08769BB4  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte 0x0876AB2C  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte 0x0876C2D8  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte 0x0876CE74  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte 0x0876DF1C  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte 0x0876F228  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte 0x08771090  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte 0x08772EF8  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte 0x08773438  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte 0x08773D04  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte 0x08774D3C  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte 0x08775440  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte 0x08776028  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte 0x08778638  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte 0x08779890  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte 0x0877ACCC  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte 0x0877C650  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte 0x0877CA78  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte 0x0877D0C0  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte 0x0877DBA4  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte 0x0877F0D4  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte 0x0877F7CC  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte 0x08780030  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte 0x08780D94  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte 0x087819E8  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte 0x08783118  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte 0x08783DC8  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte 0x08784854  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte 0x08784FA8  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte 0x08785598  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte 0x08785C94  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte 0x0878677C  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte 0x08786E7C  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte 0x0878790C  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte 0x087887D8  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte 0x08788F30  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte 0x08789CE4  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte 0x0878AD64  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte 0x0878BB7C  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte 0x0878C890  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte 0x0878D97C  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte 0x0878E9AC  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte 0x0878FBF0  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte 0x0879045C  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte 0x08791164  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte 0x087921A0  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte 0x08792FC0  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte 0x087937D4  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte 0x087947B4  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte 0x087958BC  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte 0x0879601C  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte 0x08796D7C  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte 0x08798130  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte 0x087990B0  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte 0x0879A174  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte 0x0879B958  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte 0x0879C4F8  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte 0x0879D220  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte 0x0879E6BC  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte 0x0879F570  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte 0x087A02D0  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte 0x087A16D8  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte 0x087A26B8  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte 0x087A32D8  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte 0x087A5900  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte 0x087A6774  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte 0x087A7F18  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte 0x087A8AB4  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte 0x087AA1B0  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte 0x087AABE4  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte 0x087ABE38  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte 0x087AC75C  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte 0x087AD7E8  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte 0x087AF5C0  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte 0x087B06D8  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte 0x087B1BE0  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte 0x087B2888  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte 0x087B357C  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte 0x087B425C  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte 0x087B4CEC  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte 0x087B6730  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte 0x087B7764  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte 0x087B872C  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte 0x087B9F34  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte 0x087BABDC  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte 0x087BBF8C  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte 0x087BCD64  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte 0x087BD8B4  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte 0x087BE9D8  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte 0x087BF990  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte 0x087C100C  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte 0x087C1A40  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte 0x087C2A68  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte 0x087C3848  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte 0x087C43FC  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte 0x087C4E88  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte 0x087C5CF8  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte 0x087C6BD4  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte 0x087C7C68  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte 0x087C8DD8  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte 0x087CA24C  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte 0x087CB494  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte 0x087CC144  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte 0x087CC9B4  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte 0x087CE114  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte 0x087D070C  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte 0x087D1DA0  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte 0x087D2C18  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte 0x087D3478  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte 0x087D3F38  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte 0x087D4884  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte 0x087D54E0  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Reverse_2
gJP_CryTable_Reverse_2: @ 0x08627644
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte 0x087D69E8  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte 0x087D7480  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte 0x087D80B0  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte 0x087D8E90  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte 0x087D9A30  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte 0x087DB13C  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte 0x087DBACC  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte 0x087DC534  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte 0x087DCACC  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte 0x087DD5E8  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte 0x087DDF3C  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte 0x087DE53C  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte 0x087DEE40  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte 0x087DFFF0  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte 0x087E0C5C  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte 0x087E1604  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte 0x087E32D8  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte 0x087E5258  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte 0x087E5E00  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte 0x087E7274  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte 0x087E8C90  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte 0x087E9414  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte 0x087EA518  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte 0x087EBB98  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte 0x087EC760  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte 0x087ED3A0  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte 0x087EE048  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte 0x087EE888  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte 0x087EECF0  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte 0x087EFB84  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte 0x087F0C54  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte 0x087F1480  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte 0x087F1FE8  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte 0x087F33AC  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte 0x087F3DC0  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte 0x087F468C  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte 0x087F56B8  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte 0x087F5EF0  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte 0x087F6F34  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte 0x087F7BE0  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte 0x087F85FC  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte 0x087F922C  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte 0x087FAA90  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte 0x087FB314  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte 0x087FC16C  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte 0x087FCB58  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte 0x087FD1C8  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte 0x087FDDF0  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte 0x087FE5A8  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte 0x087FED04  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte 0x087FFDBC  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte 0x08800B20  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte 0x08802004  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte 0x08802900  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte 0x08803908  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte 0x08804388  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte 0x0880573C  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte 0x08805E50  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte 0x08807368  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte 0x08807B6C  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte 0x08808CCC  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte 0x08809618  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte 0x0880AD38  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte 0x0880B674  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte 0x0880C770  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte 0x0880D374  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte 0x0880EC2C  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte 0x0880F36C  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte 0x0881000C  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte 0x08810A30  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte 0x08811834  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte 0x0881323C  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte 0x08813B2C  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte 0x088151DC  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte 0x08815E60  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte 0x088171C0  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte 0x088189BC  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte 0x088199E8  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte 0x0881A1BC  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte 0x0881C900  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte 0x0881D37C  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte 0x0881DB9C  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte 0x0881EC20  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte 0x0881F1D4  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte 0x0881FDAC  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte 0x088221F8  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte 0x08823448  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte 0x08824430  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte 0x08825A9C  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte 0x08826444  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte 0x08828174  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte 0x08828D2C  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte 0x0882A400  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte 0x0882ADA0  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte 0x0882C074  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte 0x0882E7EC  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte 0x0882EFC0  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte 0x088303C8  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte 0x088323A4  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte 0x088343A4  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte 0x08835AA8  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte 0x08836740  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte 0x088372C8  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte 0x088383E0  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte 0x08838D28  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte 0x0883A0B4  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte 0x0883AE6C  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte 0x0883BA10  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte 0x0883C590  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte 0x0883CEBC  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte 0x0883E394  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte 0x0883FD38  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte 0x08841168  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte 0x08841644  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte 0x08843B50  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte 0x08845F08  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte 0x08847C34  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte 0x08849550  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte 0x0884A210  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte 0x0884AAE8  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte 0x0884C984  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte 0x0884EA48  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte 0x088506A8  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte 0x08851238  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte 0x08852E80  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte 0x08853BA8  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte 0x088565B8  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte 0x08856DDC  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Reverse_3
gJP_CryTable_Reverse_3: @ 0x08627C44
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte 0x08857EE4  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte 0x088594DC  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte 0x0885A260  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte 0x0885B734  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte 0x00000002  @ [  4] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte 0x08653D08  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte 0x08654220  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte 0x0864D924  @ [  7] wav
	.byte 0xFF, 0xE2, 0x19, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte 0x00000002  @ [  8] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte 0x086AD150  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0xA5  @ [  9] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte 0x08659150  @ [ 10] wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ [ 10] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte 0x086621B8  @ [ 11] wav
	.byte 0xFF, 0xCC, 0x80, 0xF9  @ [ 11] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte 0x0885C144  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x4C  @ [ 12] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte 0x0885E0A4  @ [ 13] wav
	.byte 0xFF, 0x00, 0xCE, 0xCC  @ [ 13] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte 0x0864A18C  @ [ 14] wav
	.byte 0xFF, 0x00, 0xCE, 0x26  @ [ 14] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte 0x0864BA68  @ [ 15] wav
	.byte 0xFF, 0x00, 0xCE, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 16] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte 0x086C59C8  @ [ 17] wav
	.byte 0xFF, 0xEB, 0x00, 0xD8  @ [ 17] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 18] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 19] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 20] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 21] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 22] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 23] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 24] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 25] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 26] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 27] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte 0x0885FB44  @ [ 28] wav
	.byte 0xFF, 0xA5, 0x80, 0xCC  @ [ 28] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 29] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 30] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 31] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 32] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 33] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 34] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte 0x08861AB4  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0xA5  @ [ 35] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 36] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 37] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 38] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 39] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 40] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 41] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte 0x0863FDC8  @ [ 42] wav
	.byte 0xFF, 0xFC, 0x00, 0x73  @ [ 42] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 43] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 44] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 45] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 46] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 47] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 48] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 49] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte 0x086C4F98  @ [ 50] wav
	.byte 0xFF, 0xFC, 0x00, 0xCC  @ [ 50] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte 0x086C8804  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0xA5  @ [ 51] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte 0x086A9BDC  @ [ 52] wav
	.byte 0xFF, 0xCC, 0x00, 0x7F  @ [ 52] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 53] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x09, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 54] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 55] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 56] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 57] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 58] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 59] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 60] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 61] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x40, 0x00, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte 0x085FEC28  @ [ 62] wav
	.byte 0x38, 0xC0, 0x63, 0x08  @ [ 62] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 63] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 64] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 65] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 66] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 67] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 68] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 69] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 70] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 71] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 72] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 73] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 74] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 75] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 76] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 77] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 78] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 79] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 80] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 81] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 82] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 83] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x09, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 84] wav
	.byte 0x00, 0x00, 0x0A, 0x04  @ [ 84] attack, decay, sustain, release
	.byte 0x09, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte 0x00000003  @ [ 85] wav
	.byte 0x00, 0x00, 0x0A, 0x03  @ [ 85] attack, decay, sustain, release
	.byte 0x09, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 86] wav
	.byte 0x00, 0x00, 0x0A, 0x01  @ [ 86] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 87] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 88] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 89] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 90] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 91] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 92] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 93] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 94] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 95] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x09, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte 0x00000000  @ [ 96] wav
	.byte 0x00, 0x00, 0x0F, 0x01  @ [ 96] attack, decay, sustain, release
	.byte 0x09, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte 0x00000000  @ [ 97] wav
	.byte 0x00, 0x02, 0x05, 0x06  @ [ 97] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 98] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 99] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte 0x00000002  @ [100] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte 0x00000002  @ [101] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte 0x00000002  @ [102] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte 0x00000002  @ [103] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x09, 0x3C, 0x00, 0x1D  @ [104] type, key, length, pan_sweep
	.4byte 0x00000002  @ [104] wav
	.byte 0x00, 0x02, 0x00, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x09, 0x3C, 0x00, 0x16  @ [105] type, key, length, pan_sweep
	.4byte 0x00000002  @ [105] wav
	.byte 0x00, 0x02, 0x00, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte 0x00000002  @ [106] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte 0x00000002  @ [107] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte 0x00000002  @ [108] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte 0x00000002  @ [109] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte 0x00000002  @ [110] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte 0x00000002  @ [111] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte 0x00000002  @ [112] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte 0x00000002  @ [113] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte 0x00000002  @ [114] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte 0x00000002  @ [115] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte 0x00000002  @ [116] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte 0x00000002  @ [117] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte 0x00000002  @ [118] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte 0x00000002  @ [119] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte 0x08665DE4  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte 0x08657074  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ [121] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte 0x00000002  @ [122] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte 0x00000002  @ [123] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte 0x00000002  @ [124] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte 0x00000002  @ [125] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte 0x00000002  @ [126] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x0C, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte 0x00000000  @ [127] wav
	.byte 0x00, 0x01, 0x09, 0x02  @ [127] attack, decay, sustain, release

	.globl gUnknown_8628244
gUnknown_8628244: @ 0x08628244
	.incbin "baserom_jp.gba", 0x628244, 0x630
	.globl gToneData_08628874
gToneData_08628874: @ 0x08628874
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08628874_voice.bin"
	.globl gToneData_08628E74
gToneData_08628E74: @ 0x08628E74
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08628E74_voice.bin"
	.globl gToneData_08629474
gToneData_08629474: @ 0x08629474
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08629474_voice.bin"
	.globl gToneData_08629A74
gToneData_08629A74: @ 0x08629A74
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08629A74_voice.bin"
	.globl gToneData_08629EAC
gToneData_08629EAC: @ 0x08629EAC
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08629EAC_voice.bin"
	.globl gToneData_0862A290
gToneData_0862A290: @ 0x0862A290
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862A290_voice.bin"
	.globl gToneData_0862A890
gToneData_0862A890: @ 0x0862A890
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862A890_voice.bin"
	.globl gToneData_0862AE90
gToneData_0862AE90: @ 0x0862AE90
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862AE90_voice.bin"
	.globl gToneData_0862B490
gToneData_0862B490: @ 0x0862B490
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862B490_voice.bin"
	.globl gToneData_0862BA90
gToneData_0862BA90: @ 0x0862BA90
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862BA90_voice.bin"
	.globl gToneData_0862BAC0
gToneData_0862BAC0: @ 0x0862BAC0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862BAC0_voice.bin"
	.globl gToneData_0862C0C0
gToneData_0862C0C0: @ 0x0862C0C0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862C0C0_voice.bin"
	.globl gToneData_0862C4B0
gToneData_0862C4B0: @ 0x0862C4B0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862C4B0_voice.bin"
	.globl gToneData_0862CAB0
gToneData_0862CAB0: @ 0x0862CAB0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862CAB0_voice.bin"
	.globl gToneData_0862D0B0
gToneData_0862D0B0: @ 0x0862D0B0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862D0B0_voice.bin"
	.globl gToneData_0862D6B0
gToneData_0862D6B0: @ 0x0862D6B0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862D6B0_voice.bin"
	.globl gToneData_0862DCB0
gToneData_0862DCB0: @ 0x0862DCB0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862DCB0_voice.bin"
	.globl gToneData_0862E0A0
gToneData_0862E0A0: @ 0x0862E0A0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862E0A0_voice.bin"
	.globl gToneData_0862E6A0
gToneData_0862E6A0: @ 0x0862E6A0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x0863BB58  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862E6A0_voice.bin"
	.globl gToneData_0862EAFC
gToneData_0862EAFC: @ 0x0862EAFC
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862EAFC_voice.bin"
	.globl gToneData_0862F0FC
gToneData_0862F0FC: @ 0x0862F0FC
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862F0FC_voice.bin"
	.globl gToneData_0862F51C
gToneData_0862F51C: @ 0x0862F51C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862F51C_voice.bin"
	.globl gToneData_0862FB1C
gToneData_0862FB1C: @ 0x0862FB1C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0862FB1C_voice.bin"
	.globl gToneData_0863011C
gToneData_0863011C: @ 0x0863011C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0863011C_voice.bin"
	.globl gToneData_08630578
gToneData_08630578: @ 0x08630578
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08630578_voice.bin"
	.globl gToneData_08630B78
gToneData_08630B78: @ 0x08630B78
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08630B78_voice.bin"
	.globl gToneData_08631178
gToneData_08631178: @ 0x08631178
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08631178_voice.bin"
	.globl gToneData_08631778
gToneData_08631778: @ 0x08631778
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08631778_voice.bin"
	.globl gToneData_08631D78
gToneData_08631D78: @ 0x08631D78
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08631D78_voice.bin"
	.globl gToneData_08632378
gToneData_08632378: @ 0x08632378
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08632378_voice.bin"
	.globl gToneData_08632798
gToneData_08632798: @ 0x08632798
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08632798_voice.bin"
	.globl gToneData_08632D98
gToneData_08632D98: @ 0x08632D98
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08632D98_voice.bin"
	.globl gToneData_086331F4
gToneData_086331F4: @ 0x086331F4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086331F4_voice.bin"
	.globl gToneData_086337F4
gToneData_086337F4: @ 0x086337F4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086337F4_voice.bin"
	.globl gToneData_08633DF4
gToneData_08633DF4: @ 0x08633DF4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08633DF4_voice.bin"
	.globl gToneData_086343F4
gToneData_086343F4: @ 0x086343F4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086343F4_voice.bin"
	.globl gToneData_086349F4
gToneData_086349F4: @ 0x086349F4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086349F4_voice.bin"
	.globl gToneData_08634FF4
gToneData_08634FF4: @ 0x08634FF4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08634FF4_voice.bin"
	.globl gToneData_086355F4
gToneData_086355F4: @ 0x086355F4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086355F4_voice.bin"
	.globl gToneData_08635BF4
gToneData_08635BF4: @ 0x08635BF4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08635BF4_voice.bin"
	.globl gToneData_08635FE4
gToneData_08635FE4: @ 0x08635FE4
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDB0C  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08635FE4_voice.bin"
	.globl gToneData_08636428
gToneData_08636428: @ 0x08636428
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08636428_voice.bin"
	.globl gToneData_08636A28
gToneData_08636A28: @ 0x08636A28
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08636A28_voice.bin"
	.globl gToneData_08637028
gToneData_08637028: @ 0x08637028
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08637028_voice.bin"
	.globl gToneData_08637784
gToneData_08637784: @ 0x08637784
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08637C34  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08637784_voice.bin"
	.globl gToneData_0863806C
gToneData_0863806C: @ 0x0863806C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08637C34  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0863806C_voice.bin"
	.globl gToneData_0863848C
gToneData_0863848C: @ 0x0863848C
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x08637C34  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0863848C_voice.bin"
	.globl gToneData_086388AC
gToneData_086388AC: @ 0x086388AC
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086388AC_voice.bin"
	.globl gToneData_08638EAC
gToneData_08638EAC: @ 0x08638EAC
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08638EAC_voice.bin"
	.globl gToneData_086390E0
gToneData_086390E0: @ 0x086390E0
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_086390E0_voice.bin"
	.globl gToneData_08639500
gToneData_08639500: @ 0x08639500
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08639500_voice.bin"
	.globl gToneData_08639B00
gToneData_08639B00: @ 0x08639B00
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08639B00_voice.bin"
	.globl gToneData_08639F08
gToneData_08639F08: @ 0x08639F08
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08639F08_voice.bin"
	.globl gToneData_0863A508
gToneData_0863A508: @ 0x0863A508
	.byte 0x01, 0x3C, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte 0x00000002  @ wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0863A508_voice.bin"
	.globl gToneData_0863AB08
gToneData_0863AB08: @ 0x0863AB08
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0863AB08_voice.bin"
	.globl gToneData_0863B108
gToneData_0863B108: @ 0x0863B108
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0863B108_voice.bin"
	.globl gToneData_0863B708
gToneData_0863B708: @ 0x0863B708
	.byte 0x80, 0x00, 0x00, 0x00  @ type, key, length, pan_sweep
	.4byte gVoicegroup_085FDC68  @ wav
	.byte 0x00, 0x00, 0x00, 0x00  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_0863B708_voice.bin"
	.globl gUnknown_863C27C
gUnknown_863C27C: @ 0x863C27C
	.incbin "baserom_jp.gba", 0x63c27c, 0x30

	.globl gUnknown_863C2AC
	.globl gSongTable
gSongTable: @ 0x0863C2AC
	@ struct Song { const struct SongHeader *header; u16 ms; u16 pad; }
	.4byte 0x088683E0  @ song 0 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08868400  @ song 1 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886842C  @ song 2 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868450  @ song 3 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868494  @ song 4 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088684C0  @ song 5 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088684DC  @ song 6 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088684F8  @ song 7 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08868514  @ song 8 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868548  @ song 9 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886856C  @ song 10 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868588  @ song 11 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088685B4  @ song 12 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868600  @ song 13 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886867C  @ song 14 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088686D0  @ song 15 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868724  @ song 16 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868774  @ song 17 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868790  @ song 18 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088687E4  @ song 19 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886882C  @ song 20 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868858  @ song 21 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886887C  @ song 22 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088688A0  @ song 23 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088688F0  @ song 24 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08868918  @ song 25 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868938  @ song 26 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868958  @ song 27 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868978  @ song 28 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868998  @ song 29 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088689B8  @ song 30 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088689D8  @ song 31 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868A08  @ song 32 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868A9C  @ song 33 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868AC0  @ song 34 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868AE4  @ song 35 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868B08  @ song 36 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868B38  @ song 37 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868B5C  @ song 38 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868BA8  @ song 39 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868BE0  @ song 40 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868C34  @ song 41 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868C70  @ song 42 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868CC8  @ song 43 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868D0C  @ song 44 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08868D48  @ song 45 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868D88  @ song 46 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868DB4  @ song 47 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868DF0  @ song 48 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868E9C  @ song 49 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868F14  @ song 50 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868F40  @ song 51 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08868F74  @ song 52 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08868FA0  @ song 53 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869014  @ song 54 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886905C  @ song 55 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869088  @ song 56 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088690B4  @ song 57 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088690E0  @ song 58 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886910C  @ song 59 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869160  @ song 60 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088691A4  @ song 61 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x088691D8  @ song 62 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869210  @ song 63 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869248  @ song 64 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869280  @ song 65 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088692B8  @ song 66 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088692F0  @ song 67 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869328  @ song 68 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869360  @ song 69 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869394  @ song 70 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088693B8  @ song 71 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869404  @ song 72 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869464  @ song 73 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869498  @ song 74 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088694C8  @ song 75 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869500  @ song 76 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869544  @ song 77 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869574  @ song 78 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886959C  @ song 79 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869604  @ song 80 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869640  @ song 81 header
	.2byte 0x0003, 0x0003  @ ms, pad
	.4byte 0x08869680  @ song 82 header
	.2byte 0x0003, 0x0003  @ ms, pad
	.4byte 0x088696BC  @ song 83 header
	.2byte 0x0003, 0x0003  @ ms, pad
	.4byte 0x088696FC  @ song 84 header
	.2byte 0x0003, 0x0003  @ ms, pad
	.4byte 0x08869738  @ song 85 header
	.2byte 0x0003, 0x0003  @ ms, pad
	.4byte 0x08869778  @ song 86 header
	.2byte 0x0003, 0x0003  @ ms, pad
	.4byte 0x088697E0  @ song 87 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869830  @ song 88 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886986C  @ song 89 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886989C  @ song 90 header
	.2byte 0x0003, 0x0003  @ ms, pad
	.4byte 0x088698E8  @ song 91 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886990C  @ song 92 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08869960  @ song 93 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088699F4  @ song 94 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869A30  @ song 95 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869A54  @ song 96 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869AB8  @ song 97 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869B20  @ song 98 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869B48  @ song 99 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869B7C  @ song 100 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869BA8  @ song 101 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869C24  @ song 102 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869CE4  @ song 103 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869DCC  @ song 104 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869EE4  @ song 105 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x08869F08  @ song 106 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A01C  @ song 107 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A048  @ song 108 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A07C  @ song 109 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A0E0  @ song 110 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A148  @ song 111 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A344  @ song 112 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A3D0  @ song 113 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A420  @ song 114 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A44C  @ song 115 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A46C  @ song 116 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886A4A8  @ song 117 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A53C  @ song 118 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886A5A8  @ song 119 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A5F0  @ song 120 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A6B4  @ song 121 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A708  @ song 122 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A788  @ song 123 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A7C0  @ song 124 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A7F4  @ song 125 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A834  @ song 126 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A8AC  @ song 127 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A92C  @ song 128 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886A984  @ song 129 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AA28  @ song 130 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AA74  @ song 131 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AAF0  @ song 132 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886AB3C  @ song 133 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886AB70  @ song 134 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886ABBC  @ song 135 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AC1C  @ song 136 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AC68  @ song 137 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886ACEC  @ song 138 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AD40  @ song 139 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AE0C  @ song 140 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AEAC  @ song 141 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AEE8  @ song 142 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AF34  @ song 143 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886AFB4  @ song 144 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B024  @ song 145 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B0F8  @ song 146 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B19C  @ song 147 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B20C  @ song 148 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B280  @ song 149 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B360  @ song 150 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886B39C  @ song 151 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B404  @ song 152 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886B480  @ song 153 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B4CC  @ song 154 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B514  @ song 155 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B57C  @ song 156 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B618  @ song 157 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B77C  @ song 158 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B7E4  @ song 159 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B828  @ song 160 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B8A4  @ song 161 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B910  @ song 162 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886B990  @ song 163 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886BA10  @ song 164 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886BAAC  @ song 165 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886BAF8  @ song 166 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886BB38  @ song 167 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886BBB0  @ song 168 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886BBEC  @ song 169 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886BC44  @ song 170 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886BD0C  @ song 171 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886BE3C  @ song 172 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886BF8C  @ song 173 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C018  @ song 174 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C060  @ song 175 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C0C0  @ song 176 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C10C  @ song 177 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C194  @ song 178 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C250  @ song 179 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C2A8  @ song 180 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C324  @ song 181 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C3EC  @ song 182 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C4A8  @ song 183 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C594  @ song 184 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C5D4  @ song 185 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C630  @ song 186 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C668  @ song 187 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C71C  @ song 188 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C7BC  @ song 189 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C824  @ song 190 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C948  @ song 191 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886C9C4  @ song 192 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CA20  @ song 193 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CA58  @ song 194 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CAA8  @ song 195 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CB34  @ song 196 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CB98  @ song 197 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CC10  @ song 198 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CC78  @ song 199 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CDCC  @ song 200 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886CEA0  @ song 201 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886CFB0  @ song 202 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D094  @ song 203 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D174  @ song 204 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D1C0  @ song 205 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D24C  @ song 206 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D3DC  @ song 207 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D57C  @ song 208 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D5EC  @ song 209 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886D63C  @ song 210 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D760  @ song 211 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D7E0  @ song 212 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D8D0  @ song 213 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D934  @ song 214 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886D990  @ song 215 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886DA44  @ song 216 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886DC40  @ song 217 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886DD60  @ song 218 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886DE5C  @ song 219 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886DECC  @ song 220 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886DF64  @ song 221 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886DF9C  @ song 222 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E074  @ song 223 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886E14C  @ song 224 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E1F8  @ song 225 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E290  @ song 226 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E328  @ song 227 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E3D0  @ song 228 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E41C  @ song 229 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E518  @ song 230 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E5AC  @ song 231 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E610  @ song 232 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E6AC  @ song 233 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886E8B4  @ song 234 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886E9B0  @ song 235 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886EAA0  @ song 236 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886EB24  @ song 237 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886EB98  @ song 238 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886ED18  @ song 239 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886EE1C  @ song 240 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886EE7C  @ song 241 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886EEEC  @ song 242 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F008  @ song 243 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0886F0AC  @ song 244 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F21C  @ song 245 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F350  @ song 246 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F3D4  @ song 247 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F42C  @ song 248 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F45C  @ song 249 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F494  @ song 250 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F520  @ song 251 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F558  @ song 252 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F59C  @ song 253 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F5DC  @ song 254 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F604  @ song 255 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F6BC  @ song 256 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F730  @ song 257 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F79C  @ song 258 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F7E4  @ song 259 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F8C4  @ song 260 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F984  @ song 261 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886F9B8  @ song 262 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886FA58  @ song 263 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886FAB8  @ song 264 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886FAEC  @ song 265 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886FB30  @ song 266 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886FC04  @ song 267 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886FCE0  @ song 268 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0886FD20  @ song 269 header
	.2byte 0x0001, 0x0001  @ ms, pad
	.4byte 0x0863D424  @ song 270 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 271 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 272 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 273 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 274 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 275 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 276 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 277 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 278 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 279 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 280 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 281 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 282 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 283 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 284 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 285 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 286 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 287 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 288 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 289 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 290 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 291 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 292 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 293 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 294 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 295 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 296 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 297 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 298 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 299 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 300 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 301 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 302 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 303 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 304 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 305 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 306 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 307 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 308 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 309 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 310 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 311 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 312 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 313 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 314 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 315 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 316 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 317 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 318 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 319 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 320 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 321 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 322 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 323 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 324 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 325 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 326 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 327 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 328 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 329 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 330 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 331 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 332 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 333 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 334 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 335 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 336 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 337 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 338 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 339 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 340 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 341 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 342 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 343 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 344 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 345 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 346 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 347 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 348 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0863D424  @ song 349 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08870718  @ song 350 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08870AF0  @ song 351 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08870F24  @ song 352 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08871454  @ song 353 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08872344  @ song 354 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08872ED8  @ song 355 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088731BC  @ song 356 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887377C  @ song 357 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08874154  @ song 358 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08874A20  @ song 359 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08875598  @ song 360 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08876834  @ song 361 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088772F8  @ song 362 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08877BE4  @ song 363 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088785E4  @ song 364 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08879488  @ song 365 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08879DA8  @ song 366 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08879E9C  @ song 367 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08879F68  @ song 368 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0887A234  @ song 369 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0887A388  @ song 370 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0887A524  @ song 371 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0887A6B0  @ song 372 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0887B174  @ song 373 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887C01C  @ song 374 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887CE78  @ song 375 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887CEEC  @ song 376 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0887D45C  @ song 377 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887D540  @ song 378 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0887DAC8  @ song 379 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887E124  @ song 380 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887EA60  @ song 381 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887F394  @ song 382 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0887FA44  @ song 383 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088805CC  @ song 384 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08880AAC  @ song 385 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088813D0  @ song 386 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088814B0  @ song 387 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08881814  @ song 388 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08881A40  @ song 389 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08881B80  @ song 390 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08881C7C  @ song 391 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x08882290  @ song 392 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08882B18  @ song 393 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0888345C  @ song 394 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08883DD8  @ song 395 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0888467C  @ song 396 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08884CC0  @ song 397 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08885770  @ song 398 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08886A6C  @ song 399 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088876AC  @ song 400 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08888A74  @ song 401 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0888A77C  @ song 402 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0888BF60  @ song 403 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0888D220  @ song 404 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0888E474  @ song 405 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08890934  @ song 406 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08890FA4  @ song 407 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08892198  @ song 408 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08893114  @ song 409 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088934E8  @ song 410 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08894AEC  @ song 411 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08895C78  @ song 412 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08898A7C  @ song 413 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08899C18  @ song 414 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0889A91C  @ song 415 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0889B250  @ song 416 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0889BF20  @ song 417 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0889D664  @ song 418 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0889E4A0  @ song 419 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0889EAD8  @ song 420 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0889F7D4  @ song 421 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A05DC  @ song 422 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A0EA4  @ song 423 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A1374  @ song 424 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A19E8  @ song 425 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A310C  @ song 426 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A3F58  @ song 427 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A46E8  @ song 428 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A5A84  @ song 429 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A6394  @ song 430 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A719C  @ song 431 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A7E4C  @ song 432 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088A9C88  @ song 433 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088ABEDC  @ song 434 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088AC23C  @ song 435 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088ACDD4  @ song 436 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088ADC90  @ song 437 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088AE4A4  @ song 438 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088AEAB0  @ song 439 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088AF974  @ song 440 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B04D4  @ song 441 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B10F8  @ song 442 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B1758  @ song 443 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B1A34  @ song 444 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B2B10  @ song 445 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B2F74  @ song 446 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B3730  @ song 447 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B4610  @ song 448 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B4B18  @ song 449 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B57A0  @ song 450 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B5D24  @ song 451 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B63AC  @ song 452 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B6930  @ song 453 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088B7A18  @ song 454 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088BA044  @ song 455 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088BA568  @ song 456 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088BB90C  @ song 457 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088BC59C  @ song 458 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088BC8A4  @ song 459 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088BC9C8  @ song 460 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088BEC64  @ song 461 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088BF05C  @ song 462 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088C05E4  @ song 463 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088C0A4C  @ song 464 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088C1D80  @ song 465 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088C2144  @ song 466 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088C363C  @ song 467 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088C4AB8  @ song 468 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088C6968  @ song 469 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088C705C  @ song 470 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088C97A8  @ song 471 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088CAC64  @ song 472 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088CAEC4  @ song 473 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088CB980  @ song 474 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088CCBE8  @ song 475 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088CDC8C  @ song 476 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088CEABC  @ song 477 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088CF9AC  @ song 478 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D02C0  @ song 479 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D09B0  @ song 480 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D1658  @ song 481 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D2288  @ song 482 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D3120  @ song 483 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D3614  @ song 484 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D4550  @ song 485 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D6174  @ song 486 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D6B80  @ song 487 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D6E18  @ song 488 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088D7918  @ song 489 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D898C  @ song 490 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088D9860  @ song 491 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DA58C  @ song 492 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DA5E0  @ song 493 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DB1F4  @ song 494 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DB5B4  @ song 495 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DB96C  @ song 496 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DBE14  @ song 497 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DC8D0  @ song 498 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DDAE8  @ song 499 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088DEF38  @ song 500 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088E0174  @ song 501 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088E4184  @ song 502 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088E4C0C  @ song 503 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088E547C  @ song 504 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088E63B8  @ song 505 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088E712C  @ song 506 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088E7E6C  @ song 507 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088E9950  @ song 508 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088EC4C4  @ song 509 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088ED640  @ song 510 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088EFE10  @ song 511 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F0674  @ song 512 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F0E10  @ song 513 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F179C  @ song 514 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F21FC  @ song 515 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F34A0  @ song 516 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F3E18  @ song 517 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F46E4  @ song 518 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F5DD8  @ song 519 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F6814  @ song 520 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F7394  @ song 521 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F8514  @ song 522 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F8A4C  @ song 523 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088F993C  @ song 524 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FA750  @ song 525 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FB640  @ song 526 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FBE7C  @ song 527 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FC650  @ song 528 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FC850  @ song 529 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088FCA50  @ song 530 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088FCDC0  @ song 531 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088FCF30  @ song 532 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x088FD834  @ song 533 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FDC6C  @ song 534 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FDCF8  @ song 535 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FDEC8  @ song 536 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FDF84  @ song 537 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FEEF8  @ song 538 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x088FFE74  @ song 539 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x089008D0  @ song 540 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08900D50  @ song 541 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08901C7C  @ song 542 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08903080  @ song 543 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08903570  @ song 544 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08904430  @ song 545 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890564C  @ song 546 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08906540  @ song 547 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08907568  @ song 548 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x08908498  @ song 549 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890865C  @ song 550 header
	.2byte 0x0002, 0x0002  @ ms, pad
	.4byte 0x0890A7E4  @ song 551 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890B95C  @ song 552 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890CC14  @ song 553 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890D058  @ song 554 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890D9A0  @ song 555 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890E3A0  @ song 556 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890EBE0  @ song 557 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.4byte 0x0890ECBC  @ song 558 header
	.2byte 0x0000, 0x0000  @ ms, pad
	.globl gUnknown_863D424
gUnknown_863D424: @ 0x0863D424
	.globl sSongHeader_270
sSongHeader_270: @ 0x0863D424
	.byte 0x00, 0x00, 0x00, 0x00  @ trackCount, blockCount, priority, reverb
	.4byte 0x40000000  @ tone
	.globl DirectSoundWaveData_sc88pro_glockenspiel
	.set DirectSoundWaveData_sc88pro_glockenspiel, sSongHeader_270 + 4  @ 0x0863D428
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_glockenspiel.bin"
	.incbin "baserom_jp.gba", 0x63DACA, 0x2
	.globl DirectSoundWaveData_sc88pro_organ2
DirectSoundWaveData_sc88pro_organ2: @ 0x0863DACC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_organ2.bin"
	.incbin "baserom_jp.gba", 0x63E2C3, 0x1
	.globl DirectSoundWaveData_sc88pro_fretless_bass
DirectSoundWaveData_sc88pro_fretless_bass: @ 0x0863E2C4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_fretless_bass.bin"
	.incbin "baserom_jp.gba", 0x63EE8C, 0x4
	.globl DirectSoundWaveData_sc88pro_slap_bass
DirectSoundWaveData_sc88pro_slap_bass: @ 0x0863EE90
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_slap_bass.bin"
	.incbin "baserom_jp.gba", 0x63FDC6, 0x2
	.globl DirectSoundWaveData_sc88pro_synth_bass
DirectSoundWaveData_sc88pro_synth_bass: @ 0x0863FDC8
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_synth_bass.bin"
	.incbin "baserom_jp.gba", 0x640A39, 0x3
	.globl DirectSoundWaveData_sc88pro_timpani_with_snare
DirectSoundWaveData_sc88pro_timpani_with_snare: @ 0x08640A3C
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_timpani_with_snare.bin"
	.incbin "baserom_jp.gba", 0x641F09, 0x3
	.globl DirectSoundWaveData_classical_choir_voice_ahhs
DirectSoundWaveData_classical_choir_voice_ahhs: @ 0x08641F0C
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_classical_choir_voice_ahhs.bin"
	.incbin "baserom_jp.gba", 0x6435B8, 0x4
	.globl DirectSoundWaveData_sd90_classical_oboe
DirectSoundWaveData_sd90_classical_oboe: @ 0x086435BC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_classical_oboe.bin"
	.incbin "baserom_jp.gba", 0x6448FC, 0x4
	.globl DirectSoundWaveData_unused_sd90_oboe
DirectSoundWaveData_unused_sd90_oboe: @ 0x08644900
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unused_sd90_oboe.bin"
	.incbin "baserom_jp.gba", 0x6453A3, 0x1
	.globl DirectSoundWaveData_unused_guitar_separates_power_chord
DirectSoundWaveData_unused_guitar_separates_power_chord: @ 0x086453A4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unused_guitar_separates_power_chord.bin"
	.incbin "baserom_jp.gba", 0x6466B6, 0x2
	.globl DirectSoundWaveData_unused_sc88pro_unison_slap
DirectSoundWaveData_unused_sc88pro_unison_slap: @ 0x086466B8
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unused_sc88pro_unison_slap.bin"
	.incbin "baserom_jp.gba", 0x649CB0, 0x4D7C
	.globl DirectSoundWaveData_unused_sc55_tom
DirectSoundWaveData_unused_sc55_tom: @ 0x0864EA2C
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unused_sc55_tom.bin"
	.incbin "baserom_jp.gba", 0x64FA69, 0x417
	.globl DirectSoundWaveData_unknown_open_hihat
DirectSoundWaveData_unknown_open_hihat: @ 0x0864FE80
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_open_hihat.bin"
	.incbin "baserom_jp.gba", 0x650CAD, 0x3
	.globl DirectSoundWaveData_unknown_bell
DirectSoundWaveData_unknown_bell: @ 0x08650CB0
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_bell.bin"
	.incbin "baserom_jp.gba", 0x651C43, 0x8B5
	.globl DirectSoundWaveData_trinity_cymbal_crash
DirectSoundWaveData_trinity_cymbal_crash: @ 0x086524F8
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_trinity_cymbal_crash.bin"
	.incbin "baserom_jp.gba", 0x652DD9, 0x3
	.globl DirectSoundWaveData_sc88pro_orchestra_cymbal_crash
DirectSoundWaveData_sc88pro_orchestra_cymbal_crash: @ 0x08652DDC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_orchestra_cymbal_crash.bin"
	.incbin "baserom_jp.gba", 0x653D04, 0x147B8
	.globl DirectSoundWaveData_sc88pro_piano1_48
DirectSoundWaveData_sc88pro_piano1_48: @ 0x086684BC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_piano1_48.bin"
	.incbin "baserom_jp.gba", 0x669418, 0x4
	.globl DirectSoundWaveData_sc88pro_piano1_60
DirectSoundWaveData_sc88pro_piano1_60: @ 0x0866941C
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_piano1_60.bin"
	.incbin "baserom_jp.gba", 0x66AA79, 0x3
	.globl DirectSoundWaveData_sc88pro_piano1_72
DirectSoundWaveData_sc88pro_piano1_72: @ 0x0866AA7C
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_piano1_72.bin"
	.incbin "baserom_jp.gba", 0x66BFD5, 0x3
	.globl DirectSoundWaveData_sc88pro_piano1_84
DirectSoundWaveData_sc88pro_piano1_84: @ 0x0866BFD8
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_piano1_84.bin"
	.incbin "baserom_jp.gba", 0x66CB61, 0x3
	.globl DirectSoundWaveData_sc88pro_string_ensemble_60
DirectSoundWaveData_sc88pro_string_ensemble_60: @ 0x0866CB64
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_string_ensemble_60.bin"
	.incbin "baserom_jp.gba", 0x670107, 0x1
	.globl DirectSoundWaveData_sc88pro_string_ensemble_72
DirectSoundWaveData_sc88pro_string_ensemble_72: @ 0x08670108
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_string_ensemble_72.bin"
	.incbin "baserom_jp.gba", 0x672422, 0x2
	.globl DirectSoundWaveData_sc88pro_string_ensemble_84
DirectSoundWaveData_sc88pro_string_ensemble_84: @ 0x08672424
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_string_ensemble_84.bin"
	.incbin "baserom_jp.gba", 0x675AEC, 0x4
	.globl DirectSoundWaveData_sc88pro_trumpet_60
DirectSoundWaveData_sc88pro_trumpet_60: @ 0x08675AF0
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_trumpet_60.bin"
	.incbin "baserom_jp.gba", 0x676E3D, 0x3
	.globl DirectSoundWaveData_sc88pro_trumpet_72
DirectSoundWaveData_sc88pro_trumpet_72: @ 0x08676E40
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_trumpet_72.bin"
	.incbin "baserom_jp.gba", 0x67834E, 0x2
	.globl DirectSoundWaveData_sc88pro_trumpet_84
DirectSoundWaveData_sc88pro_trumpet_84: @ 0x08678350
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_trumpet_84.bin"
	.incbin "baserom_jp.gba", 0x67976C, 0x10A0
	.globl DirectSoundWaveData_sc88pro_tuba_51
DirectSoundWaveData_sc88pro_tuba_51: @ 0x0867A80C
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_tuba_51.bin"
	.incbin "baserom_jp.gba", 0x67B864, 0x4
	.globl DirectSoundWaveData_sc88pro_french_horn_60
DirectSoundWaveData_sc88pro_french_horn_60: @ 0x0867B868
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_french_horn_60.bin"
	.incbin "baserom_jp.gba", 0x6827FB, 0x1
	.globl DirectSoundWaveData_sc88pro_french_horn_72
DirectSoundWaveData_sc88pro_french_horn_72: @ 0x086827FC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_french_horn_72.bin"
	.incbin "baserom_jp.gba", 0x686D7D, 0x3
	.globl DirectSoundWaveData_sc88pro_flute
DirectSoundWaveData_sc88pro_flute: @ 0x08686D80
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_flute.bin"
	.incbin "baserom_jp.gba", 0x6874E2, 0x2
	.globl DirectSoundWaveData_sc88pro_fingered_bass
DirectSoundWaveData_sc88pro_fingered_bass: @ 0x086874E4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_fingered_bass.bin"
	.incbin "baserom_jp.gba", 0x689131, 0x3
	.globl DirectSoundWaveData_unknown_koto_high
DirectSoundWaveData_unknown_koto_high: @ 0x08689134
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_koto_high.bin"
	.incbin "baserom_jp.gba", 0x68A937, 0x1
	.globl DirectSoundWaveData_sd90_classical_shakuhachi
DirectSoundWaveData_sd90_classical_shakuhachi: @ 0x0868A938
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_classical_shakuhachi.bin"
	.incbin "baserom_jp.gba", 0x68E4EC, 0x4
	.globl DirectSoundWaveData_unknown_koto_low
DirectSoundWaveData_unknown_koto_low: @ 0x0868E4F0
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_koto_low.bin"
	.incbin "baserom_jp.gba", 0x690725, 0x3
	.globl DirectSoundWaveData_sd90_classical_overdrive_guitar
DirectSoundWaveData_sd90_classical_overdrive_guitar: @ 0x08690728
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_classical_overdrive_guitar.bin"
	.incbin "baserom_jp.gba", 0x692594, 0x4
	.globl DirectSoundWaveData_sd90_classical_distortion_guitar_high
DirectSoundWaveData_sd90_classical_distortion_guitar_high: @ 0x08692598
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_classical_distortion_guitar_high.bin"
	.incbin "baserom_jp.gba", 0x695587, 0x1
	.globl DirectSoundWaveData_sd90_classical_distortion_guitar_low
DirectSoundWaveData_sd90_classical_distortion_guitar_low: @ 0x08695588
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_classical_distortion_guitar_low.bin"
	.incbin "baserom_jp.gba", 0x6981D8, 0x4
	.globl DirectSoundWaveData_heart_of_asia_gamelan
DirectSoundWaveData_heart_of_asia_gamelan: @ 0x086981DC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_heart_of_asia_gamelan.bin"
	.incbin "baserom_jp.gba", 0x69C75B, 0x1
	.globl DirectSoundWaveData_sc88pro_church_organ3_low
DirectSoundWaveData_sc88pro_church_organ3_low: @ 0x0869C75C
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_church_organ3_low.bin"
	.incbin "baserom_jp.gba", 0x69F0A0, 0x4
	.globl DirectSoundWaveData_sc88pro_church_organ3_high
DirectSoundWaveData_sc88pro_church_organ3_high: @ 0x0869F0A4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_church_organ3_high.bin"
	.incbin "baserom_jp.gba", 0x6A0801, 0x3
	.globl DirectSoundWaveData_unknown_female_voice
DirectSoundWaveData_unknown_female_voice: @ 0x086A0804
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_female_voice.bin"
	.incbin "baserom_jp.gba", 0x6A1E46, 0x2
	.globl DirectSoundWaveData_unused_unknown_male_voice
DirectSoundWaveData_unused_unknown_male_voice: @ 0x086A1E48
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unused_unknown_male_voice.bin"
	.incbin "baserom_jp.gba", 0x6A42EC, 0x4
	.globl DirectSoundWaveData_sd90_classical_detuned_ep1_low
DirectSoundWaveData_sd90_classical_detuned_ep1_low: @ 0x086A42F0
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_classical_detuned_ep1_low.bin"
	.incbin "baserom_jp.gba", 0x6A6956, 0x2
	.globl DirectSoundWaveData_sd90_classical_detuned_ep1_high
DirectSoundWaveData_sd90_classical_detuned_ep1_high: @ 0x086A6958
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_classical_detuned_ep1_high.bin"
	.incbin "baserom_jp.gba", 0x6A7CFF, 0x14D1
	.globl DirectSoundWaveData_unknown_synth_snare
DirectSoundWaveData_unknown_synth_snare: @ 0x086A91D0
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_synth_snare.bin"
	.incbin "baserom_jp.gba", 0x6A9BDA, 0x2
	.globl DirectSoundWaveData_sc88pro_square_wave
DirectSoundWaveData_sc88pro_square_wave: @ 0x086A9BDC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_square_wave.bin"
	.incbin "baserom_jp.gba", 0x6AB7EF, 0x2E25
	.globl DirectSoundWaveData_sc88pro_pizzicato_strings
DirectSoundWaveData_sc88pro_pizzicato_strings: @ 0x086AE614
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_pizzicato_strings.bin"
	.incbin "baserom_jp.gba", 0x6AED4C, 0x4
	.globl DirectSoundWaveData_unknown_2
DirectSoundWaveData_unknown_2: @ 0x086AED50
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_2.bin"
	.incbin "baserom_jp.gba", 0x6B093F, 0x1
	.globl DirectSoundWaveData_unknown_3
DirectSoundWaveData_unknown_3: @ 0x086B0940
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_3.bin"
	.incbin "baserom_jp.gba", 0x6B1CF2, 0x2
	.globl DirectSoundWaveData_unknown_4
DirectSoundWaveData_unknown_4: @ 0x086B1CF4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_4.bin"
	.incbin "baserom_jp.gba", 0x6B4374, 0x4
	.globl DirectSoundWaveData_sc88pro_wind
DirectSoundWaveData_sc88pro_wind: @ 0x086B4378
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_wind.bin"
	.incbin "baserom_jp.gba", 0x6B55B9, 0x1013
	.globl DirectSoundWaveData_unknown_5
DirectSoundWaveData_unknown_5: @ 0x086B65CC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_5.bin"
	.incbin "baserom_jp.gba", 0x6B78D0, 0x4
	.globl DirectSoundWaveData_unknown_6
DirectSoundWaveData_unknown_6: @ 0x086B78D4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_6.bin"
	.incbin "baserom_jp.gba", 0x6B99DC, 0x4
	.globl DirectSoundWaveData_trinity_30303_mega_bass
DirectSoundWaveData_trinity_30303_mega_bass: @ 0x086B99E0
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_trinity_30303_mega_bass.bin"
	.incbin "baserom_jp.gba", 0x6BB9BA, 0x2
	.globl DirectSoundWaveData_unknown_7
DirectSoundWaveData_unknown_7: @ 0x086BB9BC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_7.bin"
	.incbin "baserom_jp.gba", 0x6BDBCB, 0x1
	.globl DirectSoundWaveData_unknown_8
DirectSoundWaveData_unknown_8: @ 0x086BDBCC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_8.bin"
	.incbin "baserom_jp.gba", 0x6BE396, 0x2
	.globl DirectSoundWaveData_sc88pro_tubular_bell
DirectSoundWaveData_sc88pro_tubular_bell: @ 0x086BE398
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_tubular_bell.bin"
	.incbin "baserom_jp.gba", 0x6BFD07, 0x1
	.globl DirectSoundWaveData_unknown_9
DirectSoundWaveData_unknown_9: @ 0x086BFD08
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_9.bin"
	.incbin "baserom_jp.gba", 0x6C1CB4, 0x4
	.globl DirectSoundWaveData_trinity_big_boned
DirectSoundWaveData_trinity_big_boned: @ 0x086C1CB8
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_trinity_big_boned.bin"
	.incbin "baserom_jp.gba", 0x6C4F96, 0x2
	.globl DirectSoundWaveData_sc88pro_harp
DirectSoundWaveData_sc88pro_harp: @ 0x086C4F98
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_harp.bin"
	.incbin "baserom_jp.gba", 0x6C59C7, 0x1
	.globl DirectSoundWaveData_sc88pro_xylophone
DirectSoundWaveData_sc88pro_xylophone: @ 0x086C59C8
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_xylophone.bin"
	.incbin "baserom_jp.gba", 0x6C63FA, 0x2
	.globl DirectSoundWaveData_unknown_10
DirectSoundWaveData_unknown_10: @ 0x086C63FC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_10.bin"
	.incbin "baserom_jp.gba", 0x6C7F38, 0x4
	.globl DirectSoundWaveData_unknown_11
DirectSoundWaveData_unknown_11: @ 0x086C7F3C
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_11.bin"
	.incbin "baserom_jp.gba", 0x6C8803, 0x1
	.globl DirectSoundWaveData_sc88pro_accordion_duplicate
DirectSoundWaveData_sc88pro_accordion_duplicate: @ 0x086C8804
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_accordion_duplicate.bin"
	.incbin "baserom_jp.gba", 0x6C9BD2, 0x2
	.globl DirectSoundWaveData_unknown_12
DirectSoundWaveData_unknown_12: @ 0x086C9BD4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_12.bin"
	.incbin "baserom_jp.gba", 0x6CA7E3, 0x1
	.globl DirectSoundWaveData_unknown_13
DirectSoundWaveData_unknown_13: @ 0x086CA7E4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_13.bin"
	.incbin "baserom_jp.gba", 0x6CB372, 0x2
	.globl DirectSoundWaveData_unknown_14
DirectSoundWaveData_unknown_14: @ 0x086CB374
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_14.bin"
	.incbin "baserom_jp.gba", 0x6CBE0F, 0x1
	.globl DirectSoundWaveData_unknown_15
DirectSoundWaveData_unknown_15: @ 0x086CBE10
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_15.bin"
	.incbin "baserom_jp.gba", 0x6CC757, 0x1
	.globl DirectSoundWaveData_unknown_16
DirectSoundWaveData_unknown_16: @ 0x086CC758
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_16.bin"
	.incbin "baserom_jp.gba", 0x6CD19E, 0x2
	.globl DirectSoundWaveData_unknown_17
DirectSoundWaveData_unknown_17: @ 0x086CD1A0
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_17.bin"
	.incbin "baserom_jp.gba", 0x6CDE26, 0x19027E
	.globl DirectSoundWaveData_unknown_18
DirectSoundWaveData_unknown_18: @ 0x0885E0A4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_unknown_18.bin"
	.incbin "baserom_jp.gba", 0x85FB42, 0x2
	.globl DirectSoundWaveData_sc88pro_nylon_str_guitar
DirectSoundWaveData_sc88pro_nylon_str_guitar: @ 0x0885FB44
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sc88pro_nylon_str_guitar.bin"
	.incbin "baserom_jp.gba", 0x861AB1, 0x3
	.globl DirectSoundWaveData_sd90_special_scream_drive
DirectSoundWaveData_sd90_special_scream_drive: @ 0x08861AB4
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_special_scream_drive.bin"
	.incbin "baserom_jp.gba", 0x8632EB, 0x13D1
	.globl DirectSoundWaveData_steinway_b_piano
DirectSoundWaveData_steinway_b_piano: @ 0x088646BC
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_steinway_b_piano.bin"
	.incbin "baserom_jp.gba", 0x86587C, 0x4
	.globl DirectSoundWaveData_sd90_classical_whistle
DirectSoundWaveData_sd90_classical_whistle: @ 0x08865880
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_classical_whistle.bin"
	.incbin "baserom_jp.gba", 0x8662DC, 0x4
	.globl DirectSoundWaveData_sd90_enhanced_delay_shaku
DirectSoundWaveData_sd90_enhanced_delay_shaku: @ 0x088662E0
	.incbin "sound/direct_sound_samples/DirectSoundWaveData_sd90_enhanced_delay_shaku.bin"
	.incbin "baserom_jp.gba", 0x8683DE, 0x2
