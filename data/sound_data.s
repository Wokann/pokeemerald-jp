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
	.4byte DirectSoundWaveData_classical_choir_voice_ahhs  @ voice 28 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 28 a/d/s/r
	.globl gVoicegroup_085FDC68
gVoicegroup_085FDC68: @ 0x085FDC68
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 0
	.4byte DirectSoundWaveData_sd90_classical_oboe  @ voice 0 wav
	.byte 0xFF, 0xA5, 0x9A, 0x7F  @ voice 0 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 1
	.4byte DirectSoundWaveData_unused_sd90_oboe  @ voice 1 wav
	.byte 0xFF, 0xA5, 0x9A, 0x7F  @ voice 1 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 2
	.4byte DirectSoundWaveData_unused_guitar_separates_power_chord  @ voice 2 wav
	.byte 0xFF, 0xA5, 0xCE, 0x7F  @ voice 2 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 3
	.4byte DirectSoundWaveData_unused_sc88pro_unison_slap  @ voice 3 wav
	.byte 0xFF, 0xA5, 0xCE, 0x7F  @ voice 3 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 4
	.4byte DirectSoundWaveData_unknown_snare  @ voice 4 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 4 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 5
	.4byte DirectSoundWaveData_ethnic_flavours_ohtsuzumi  @ voice 5 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 5 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x00  @ voice 6
	.4byte DirectSoundWaveData_ethnic_flavours_hyoushigi  @ voice 6 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 6 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 7
	.4byte DirectSoundWaveData_sc88pro_rnd_kick  @ voice 7 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 7 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 8
	.4byte 0x00000002  @ voice 8 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 8 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 9
	.4byte DirectSoundWaveData_sc88pro_rnd_snare  @ voice 9 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 9 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 10
	.4byte DirectSoundWaveData_sc88pro_tr909_hand_clap  @ voice 10 wav
	.byte 0xFF, 0xFF, 0xFF, 0x7F  @ voice 10 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 11
	.4byte DirectSoundWaveData_sc88pro_orchestra_snare  @ voice 11 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 11 a/d/s/r
	.byte 0x00, 0x30, 0x00, 0xAC  @ voice 12
	.4byte DirectSoundWaveData_unused_sc55_tom  @ voice 12 wav
	.byte 0xFF, 0xD2, 0x4D, 0xCC  @ voice 12 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xCF  @ voice 13
	.4byte DirectSoundWaveData_unknown_close_hihat  @ voice 13 wav
	.byte 0xFF, 0x7F, 0x00, 0xBC  @ voice 13 a/d/s/r
	.byte 0x00, 0x33, 0x00, 0xB6  @ voice 14
	.4byte DirectSoundWaveData_unused_sc55_tom  @ voice 14 wav
	.byte 0xFF, 0xD8, 0x4D, 0xCC  @ voice 14 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 15
	.4byte 0x00000002  @ voice 15 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 15 a/d/s/r
	.byte 0x00, 0x36, 0x00, 0xC0  @ voice 16
	.4byte DirectSoundWaveData_unused_sc55_tom  @ voice 16 wav
	.byte 0xFF, 0xD8, 0x4D, 0xCC  @ voice 16 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xCF  @ voice 17
	.4byte DirectSoundWaveData_unknown_open_hihat  @ voice 17 wav
	.byte 0xFF, 0xF2, 0x8D, 0x00  @ voice 17 a/d/s/r
	.byte 0x00, 0x39, 0x00, 0xC5  @ voice 18
	.4byte DirectSoundWaveData_unused_sc55_tom  @ voice 18 wav
	.byte 0xFF, 0xD2, 0x4D, 0xCC  @ voice 18 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0xCF  @ voice 19
	.4byte DirectSoundWaveData_unused_sc55_tom  @ voice 19 wav
	.byte 0xFF, 0xCC, 0x4D, 0xCC  @ voice 19 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 20
	.4byte 0x00000002  @ voice 20 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 20 a/d/s/r
	.byte 0x00, 0x3E, 0x00, 0xD4  @ voice 21
	.4byte DirectSoundWaveData_unused_sc55_tom  @ voice 21 wav
	.byte 0xFF, 0xCC, 0x4D, 0xCC  @ voice 21 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 22
	.4byte 0x00000002  @ voice 22 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 22 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 23
	.4byte 0x00000002  @ voice 23 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 23 a/d/s/r
	.byte 0x08, 0x46, 0x00, 0xB1  @ voice 24
	.4byte DirectSoundWaveData_unknown_bell  @ voice 24 wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ voice 24 a/d/s/r
	.byte 0x08, 0x20, 0x00, 0xA2  @ voice 25
	.4byte DirectSoundWaveData_sc88pro_tambourine  @ voice 25 wav
	.byte 0xFF, 0x7F, 0x4D, 0xCC  @ voice 25 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0x8E  @ voice 26
	.4byte DirectSoundWaveData_trinity_cymbal_crash  @ voice 26 wav
	.byte 0xFF, 0xEB, 0x00, 0xA5  @ voice 26 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 27
	.4byte 0x00000002  @ voice 27 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 27 a/d/s/r
	.byte 0x08, 0x1E, 0x00, 0xB6  @ voice 28
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 28 wav
	.byte 0xFF, 0xF6, 0x00, 0xD8  @ voice 28 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 29
	.4byte 0x00000002  @ voice 29 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 29 a/d/s/r
	.byte 0x08, 0x1E, 0x00, 0xB6  @ voice 30
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 30 wav
	.byte 0xFF, 0xF6, 0x00, 0xD8  @ voice 30 a/d/s/r
	.byte 0x08, 0x1E, 0x00, 0xC0  @ voice 31
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 31 wav
	.byte 0x08, 0x00, 0xFF, 0xD8  @ voice 31 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 32
	.4byte 0x00000002  @ voice 32 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 32 a/d/s/r
	.byte 0x08, 0x48, 0x00, 0xE8  @ voice 33
	.4byte DirectSoundWaveData_sc88pro_mute_high_conga  @ voice 33 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 33 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 34
	.4byte 0x00000002  @ voice 34 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 34 a/d/s/r
	.byte 0x08, 0x48, 0x00, 0xDE  @ voice 35
	.4byte DirectSoundWaveData_sc88pro_open_low_conga  @ voice 35 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 35 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 36
	.4byte DirectSoundWaveData_drum_and_percussion_kick  @ voice 36 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 36 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 37
	.4byte DirectSoundWaveData_sd90_solo_snare  @ voice 37 wav
	.byte 0xFF, 0xB4, 0xAF, 0xE4  @ voice 37 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 38
	.4byte DirectSoundWaveData_sd90_solo_snare  @ voice 38 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 38 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 39
	.4byte DirectSoundWaveData_sc88pro_tr909_hand_clap  @ voice 39 wav
	.byte 0xFF, 0xFF, 0xFF, 0x7F  @ voice 39 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 40
	.4byte DirectSoundWaveData_sc88pro_orchestra_snare  @ voice 40 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 40 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0x98  @ voice 41
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 41 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 41 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD0  @ voice 42
	.4byte DirectSoundWaveData_sc88pro_orchestra_snare  @ voice 42 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 42 a/d/s/r
	.byte 0x00, 0x44, 0x00, 0xA2  @ voice 43
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 43 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 43 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 44
	.4byte DirectSoundWaveData_sc88pro_rnd_snare  @ voice 44 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 44 a/d/s/r
	.byte 0x00, 0x48, 0x00, 0xAC  @ voice 45
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 45 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 45 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 46
	.4byte DirectSoundWaveData_sc88pro_rnd_snare  @ voice 46 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 46 a/d/s/r
	.byte 0x00, 0x4C, 0x00, 0xD4  @ voice 47
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 47 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 47 a/d/s/r
	.byte 0x00, 0x50, 0x00, 0xDE  @ voice 48
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 48 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 48 a/d/s/r
	.byte 0x08, 0x21, 0x00, 0xD9  @ voice 49
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 49 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 49 a/d/s/r
	.byte 0x00, 0x54, 0x00, 0xE8  @ voice 50
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 50 wav
	.byte 0xFF, 0x00, 0xFF, 0xEB  @ voice 50 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 51
	.4byte 0x00000002  @ voice 51 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 51 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 52
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 52 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 52 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 53
	.4byte DirectSoundWaveData_dance_drums_ride_bell  @ voice 53 wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ voice 53 a/d/s/r
	.globl gVoicegroup_085FDEF0
gVoicegroup_085FDEF0: @ 0x085FDEF0
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 0
	.4byte DirectSoundWaveData_sc88pro_tambourine  @ voice 0 wav
	.byte 0xFF, 0x7F, 0x4D, 0xCC  @ voice 0 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x8E  @ voice 1
	.4byte DirectSoundWaveData_trinity_cymbal_crash  @ voice 1 wav
	.byte 0xFF, 0xE7, 0x00, 0xBC  @ voice 1 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD9  @ voice 2
	.4byte DirectSoundWaveData_sd90_cowbell  @ voice 2 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 2 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x9D  @ voice 3
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 3 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 3 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 4
	.4byte 0x00000002  @ voice 4 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 4 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 5
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 5 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 5 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 6
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 6 wav
	.byte 0x08, 0x00, 0xFF, 0xD8  @ voice 6 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xDE  @ voice 7
	.4byte DirectSoundWaveData_unused_heart_of_asia_indian_drum  @ voice 7 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 7 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 8
	.4byte DirectSoundWaveData_sc88pro_mute_high_conga  @ voice 8 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 8 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 9
	.4byte DirectSoundWaveData_sc88pro_open_low_conga  @ voice 9 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 9 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xDA  @ voice 10
	.4byte DirectSoundWaveData_sc88pro_open_low_conga  @ voice 10 wav
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
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 26 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 26 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xCF  @ voice 27
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 27 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 27 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA7  @ voice 28
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 28 wav
	.byte 0xFF, 0xA5, 0x67, 0xBC  @ voice 28 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 29
	.4byte DirectSoundWaveData_sc88pro_jingle_bell  @ voice 29 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 29 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 30
	.4byte 0x00000002  @ voice 30 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 30 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 31
	.4byte 0x00000002  @ voice 31 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 31 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xE8  @ voice 32
	.4byte DirectSoundWaveData_ethnic_flavours_atarigane  @ voice 32 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 32 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 33
	.4byte DirectSoundWaveData_sc88pro_taiko  @ voice 33 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 33 a/d/s/r
	.byte 0x00, 0x32, 0x00, 0xD4  @ voice 34
	.4byte DirectSoundWaveData_ethnic_flavours_kotsuzumi  @ voice 34 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 34 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xD4  @ voice 35
	.4byte DirectSoundWaveData_ethnic_flavours_kotsuzumi  @ voice 35 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 35 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 36
	.4byte DirectSoundWaveData_sc88pro_taiko  @ voice 36 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 36 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 37
	.4byte DirectSoundWaveData_sd90_solo_snare  @ voice 37 wav
	.byte 0xFF, 0xB4, 0xAF, 0xE4  @ voice 37 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 38
	.4byte DirectSoundWaveData_sd90_solo_snare  @ voice 38 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 38 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 39
	.4byte DirectSoundWaveData_sc88pro_tr909_hand_clap  @ voice 39 wav
	.byte 0xFF, 0xFF, 0xFF, 0x7F  @ voice 39 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 40
	.4byte DirectSoundWaveData_sc88pro_orchestra_snare  @ voice 40 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 40 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0x98  @ voice 41
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 41 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 41 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD0  @ voice 42
	.4byte DirectSoundWaveData_sc88pro_orchestra_snare  @ voice 42 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 42 a/d/s/r
	.byte 0x00, 0x44, 0x00, 0xA2  @ voice 43
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 43 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 43 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 44
	.4byte DirectSoundWaveData_sc88pro_rnd_snare  @ voice 44 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 44 a/d/s/r
	.byte 0x00, 0x48, 0x00, 0xAC  @ voice 45
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 45 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 45 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 46
	.4byte 0x00000002  @ voice 46 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 46 a/d/s/r
	.byte 0x00, 0x4C, 0x00, 0xD4  @ voice 47
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 47 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 47 a/d/s/r
	.byte 0x00, 0x50, 0x00, 0xDE  @ voice 48
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 48 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 48 a/d/s/r
	.byte 0x08, 0x21, 0x00, 0xD9  @ voice 49
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 49 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 49 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xE8  @ voice 50
	.4byte DirectSoundWaveData_sc88pro_taiko  @ voice 50 wav
	.byte 0xFF, 0x00, 0xFF, 0xEB  @ voice 50 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 51
	.4byte 0x00000002  @ voice 51 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 51 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 52
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 52 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 52 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 53
	.4byte DirectSoundWaveData_dance_drums_ride_bell  @ voice 53 wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ voice 53 a/d/s/r
	.globl gVoicegroup_085FE178
gVoicegroup_085FE178: @ 0x085FE178
	.byte 0x08, 0x42, 0x00, 0xA2  @ voice 0
	.4byte DirectSoundWaveData_sc88pro_tambourine  @ voice 0 wav
	.byte 0xFF, 0x7F, 0x4D, 0xCC  @ voice 0 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x8E  @ voice 1
	.4byte DirectSoundWaveData_trinity_cymbal_crash  @ voice 1 wav
	.byte 0xFF, 0xE7, 0x00, 0xBC  @ voice 1 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD9  @ voice 2
	.4byte DirectSoundWaveData_sd90_cowbell  @ voice 2 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 2 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x9D  @ voice 3
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 3 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 3 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 4
	.4byte 0x00000002  @ voice 4 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 4 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 5
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 5 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 5 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 6
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 6 wav
	.byte 0x08, 0x00, 0xFF, 0xD8  @ voice 6 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xDE  @ voice 7
	.4byte DirectSoundWaveData_unused_heart_of_asia_indian_drum  @ voice 7 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 7 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 8
	.4byte DirectSoundWaveData_sc88pro_mute_high_conga  @ voice 8 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 8 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA2  @ voice 9
	.4byte DirectSoundWaveData_sc88pro_open_low_conga  @ voice 9 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 9 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xDA  @ voice 10
	.4byte DirectSoundWaveData_sc88pro_open_low_conga  @ voice 10 wav
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
	.4byte DirectSoundWaveData_ethnic_flavours_hyoushigi  @ voice 21 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 21 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 22
	.4byte DirectSoundWaveData_ethnic_flavours_ohtsuzumi  @ voice 22 wav
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
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 26 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 26 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xCF  @ voice 27
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 27 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 27 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xA7  @ voice 28
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 28 wav
	.byte 0xFF, 0xA5, 0x67, 0xBC  @ voice 28 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 29
	.4byte DirectSoundWaveData_sc88pro_jingle_bell  @ voice 29 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 29 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 30
	.4byte 0x00000002  @ voice 30 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 30 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 31
	.4byte 0x00000002  @ voice 31 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 31 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xE8  @ voice 32
	.4byte DirectSoundWaveData_ethnic_flavours_atarigane  @ voice 32 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 32 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 33
	.4byte DirectSoundWaveData_sc88pro_taiko  @ voice 33 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 33 a/d/s/r
	.byte 0x00, 0x32, 0x00, 0xD4  @ voice 34
	.4byte DirectSoundWaveData_ethnic_flavours_kotsuzumi  @ voice 34 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 34 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xD4  @ voice 35
	.4byte DirectSoundWaveData_ethnic_flavours_kotsuzumi  @ voice 35 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 35 a/d/s/r
	.byte 0x00, 0x3E, 0x00, 0xC0  @ voice 36
	.4byte DirectSoundWaveData_drum_and_percussion_kick  @ voice 36 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 36 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 37
	.4byte DirectSoundWaveData_sd90_solo_snare  @ voice 37 wav
	.byte 0xFF, 0xB4, 0xAF, 0xE4  @ voice 37 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 38
	.4byte DirectSoundWaveData_sd90_solo_snare  @ voice 38 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 38 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xB6  @ voice 39
	.4byte DirectSoundWaveData_sc88pro_tr909_hand_clap  @ voice 39 wav
	.byte 0xFF, 0xFF, 0xFF, 0x7F  @ voice 39 a/d/s/r
	.byte 0x00, 0x41, 0x00, 0xC0  @ voice 40
	.4byte DirectSoundWaveData_sc88pro_orchestra_snare  @ voice 40 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 40 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0x98  @ voice 41
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 41 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 41 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xD0  @ voice 42
	.4byte DirectSoundWaveData_sc88pro_orchestra_snare  @ voice 42 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 42 a/d/s/r
	.byte 0x00, 0x44, 0x00, 0xA2  @ voice 43
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 43 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 43 a/d/s/r
	.byte 0x08, 0x3C, 0x00, 0xC0  @ voice 44
	.4byte DirectSoundWaveData_sc88pro_rnd_snare  @ voice 44 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 44 a/d/s/r
	.byte 0x00, 0x48, 0x00, 0xAC  @ voice 45
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 45 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 45 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 46
	.4byte 0x00000002  @ voice 46 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 46 a/d/s/r
	.byte 0x00, 0x4C, 0x00, 0xD4  @ voice 47
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 47 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 47 a/d/s/r
	.byte 0x00, 0x50, 0x00, 0xDE  @ voice 48
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ voice 48 wav
	.byte 0xFF, 0x00, 0xFF, 0xE2  @ voice 48 a/d/s/r
	.byte 0x00, 0x38, 0x00, 0xD9  @ voice 49
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 49 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 49 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xE8  @ voice 50
	.4byte DirectSoundWaveData_sc88pro_taiko  @ voice 50 wav
	.byte 0xFF, 0x00, 0xFF, 0xEB  @ voice 50 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 51
	.4byte 0x00000002  @ voice 51 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 51 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 52
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 52 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 52 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0x98  @ voice 53
	.4byte DirectSoundWaveData_dance_drums_ride_bell  @ voice 53 wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ voice 53 a/d/s/r
	.byte 0x08, 0x42, 0x00, 0xA2  @ voice 54
	.4byte DirectSoundWaveData_sc88pro_tambourine  @ voice 54 wav
	.byte 0xFF, 0x7F, 0x4D, 0xCC  @ voice 54 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0x8E  @ voice 55
	.4byte DirectSoundWaveData_trinity_cymbal_crash  @ voice 55 wav
	.byte 0xFF, 0xE7, 0x00, 0xBC  @ voice 55 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xD9  @ voice 56
	.4byte DirectSoundWaveData_sd90_cowbell  @ voice 56 wav
	.byte 0xFF, 0x00, 0xFF, 0xF2  @ voice 56 a/d/s/r
	.byte 0x00, 0x3C, 0x00, 0x9D  @ voice 57
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 57 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 57 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 58
	.4byte 0x00000002  @ voice 58 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 58 a/d/s/r
	.byte 0x00, 0x3A, 0x00, 0xB6  @ voice 59
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 59 wav
	.byte 0xFF, 0xEB, 0x00, 0xE7  @ voice 59 a/d/s/r
	.byte 0x00, 0x3E, 0x00, 0xB6  @ voice 60
	.4byte DirectSoundWaveData_sc88pro_orchestra_cymbal_crash  @ voice 60 wav
	.byte 0x08, 0x00, 0xFF, 0xD8  @ voice 60 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xDE  @ voice 61
	.4byte DirectSoundWaveData_unused_heart_of_asia_indian_drum  @ voice 61 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 61 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xA2  @ voice 62
	.4byte DirectSoundWaveData_sc88pro_mute_high_conga  @ voice 62 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 62 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xA2  @ voice 63
	.4byte DirectSoundWaveData_sc88pro_open_low_conga  @ voice 63 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 63 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xDA  @ voice 64
	.4byte DirectSoundWaveData_sc88pro_open_low_conga  @ voice 64 wav
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
	.4byte DirectSoundWaveData_ethnic_flavours_hyoushigi  @ voice 75 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 75 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xC0  @ voice 76
	.4byte DirectSoundWaveData_ethnic_flavours_ohtsuzumi  @ voice 76 wav
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
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 80 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 80 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xCF  @ voice 81
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 81 wav
	.byte 0xFF, 0xF2, 0x67, 0xBC  @ voice 81 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xA7  @ voice 82
	.4byte DirectSoundWaveData_sd90_open_triangle  @ voice 82 wav
	.byte 0xFF, 0xA5, 0x67, 0xBC  @ voice 82 a/d/s/r
	.byte 0x08, 0x40, 0x00, 0xC0  @ voice 83
	.4byte DirectSoundWaveData_sc88pro_jingle_bell  @ voice 83 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 83 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 84
	.4byte 0x00000002  @ voice 84 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 84 a/d/s/r
	.byte 0x01, 0x3C, 0x00, 0x00  @ voice 85
	.4byte 0x00000002  @ voice 85 wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ voice 85 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xE8  @ voice 86
	.4byte DirectSoundWaveData_ethnic_flavours_atarigane  @ voice 86 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 86 a/d/s/r
	.byte 0x00, 0x3F, 0x00, 0xC0  @ voice 87
	.4byte DirectSoundWaveData_sc88pro_taiko  @ voice 87 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 87 a/d/s/r
	.byte 0x00, 0x32, 0x00, 0xD4  @ voice 88
	.4byte DirectSoundWaveData_ethnic_flavours_kotsuzumi  @ voice 88 wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ voice 88 a/d/s/r
	.byte 0x00, 0x40, 0x00, 0xD4  @ voice 89
	.4byte DirectSoundWaveData_ethnic_flavours_kotsuzumi  @ voice 89 wav
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
	.4byte DirectSoundWaveData_bicycle_bell  @ wav
	.byte 0xFF, 0xF9, 0x00, 0xA5  @ attack, decay, sustain, release
	.incbin "sound/tone_data/gToneData_08625214_voice.bin"

	.globl gJP_CryTable_Normal_0
gJP_CryTable_Normal_0: @ 0x08625814
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte Cry_Bulbasaur  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte Cry_Ivysaur  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte Cry_Venusaur  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte Cry_Charmander  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte Cry_Charmeleon  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte Cry_Charizard  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte Cry_Squirtle  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte Cry_Wartortle  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte Cry_Blastoise  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte Cry_Caterpie  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte Cry_Metapod  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte Cry_Butterfree  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte Cry_Weedle  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte Cry_Kakuna  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte Cry_Beedrill  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte Cry_Pidgey  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte Cry_Pidgeotto  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte Cry_Pidgeot  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte Cry_Rattata  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte Cry_Raticate  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte Cry_Spearow  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte Cry_Fearow  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte Cry_Ekans  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte Cry_Arbok  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte Cry_Pikachu  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte Cry_Raichu  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte Cry_Sandshrew  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte Cry_Sandslash  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte Cry_NidoranF  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte Cry_Nidorina  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte Cry_Nidoqueen  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte Cry_NidoranM  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte Cry_Nidorino  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte Cry_Nidoking  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte Cry_Clefairy  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte Cry_Clefable  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte Cry_Vulpix  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte Cry_Ninetales  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte Cry_Jigglypuff  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte Cry_Wigglytuff  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte Cry_Zubat  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte Cry_Golbat  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte Cry_Oddish  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte Cry_Gloom  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte Cry_Vileplume  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte Cry_Paras  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte Cry_Parasect  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte Cry_Venonat  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte Cry_Venomoth  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte Cry_Diglett  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte Cry_Dugtrio  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte Cry_Meowth  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte Cry_Persian  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte Cry_Psyduck  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte Cry_Golduck  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte Cry_Mankey  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte Cry_Primeape  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte Cry_Growlithe  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte Cry_Arcanine  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte Cry_Poliwag  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte Cry_Poliwhirl  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte Cry_Poliwrath  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte Cry_Abra  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte Cry_Kadabra  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte Cry_Alakazam  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte Cry_Machop  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte Cry_Machoke  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte Cry_Machamp  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte Cry_Bellsprout  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte Cry_Weepinbell  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte Cry_Victreebel  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte Cry_Tentacool  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte Cry_Tentacruel  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte Cry_Geodude  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte Cry_Graveler  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte Cry_Golem  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte Cry_Ponyta  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte Cry_Rapidash  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte Cry_Slowpoke  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte Cry_Slowbro  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte Cry_Magnemite  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte Cry_Magneton  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte Cry_Farfetchd  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte Cry_Doduo  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte Cry_Dodrio  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte Cry_Seel  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte Cry_Dewgong  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte Cry_Grimer  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte Cry_Muk  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte Cry_Shellder  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte Cry_Cloyster  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte Cry_Gastly  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte Cry_Haunter  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte Cry_Gengar  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte Cry_Onix  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte Cry_Drowzee  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte Cry_Hypno  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte Cry_Krabby  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte Cry_Kingler  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte Cry_Voltorb  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte Cry_Electrode  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte Cry_Exeggcute  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte Cry_Exeggutor  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte Cry_Cubone  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte Cry_Marowak  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte Cry_Hitmonlee  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte Cry_Hitmonchan  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte Cry_Lickitung  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte Cry_Koffing  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte Cry_Weezing  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte Cry_Rhyhorn  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte Cry_Rhydon  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte Cry_Chansey  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte Cry_Tangela  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte Cry_Kangaskhan  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte Cry_Horsea  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte Cry_Seadra  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte Cry_Goldeen  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte Cry_Seaking  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte Cry_Staryu  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte Cry_Starmie  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte Cry_MrMime  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte Cry_Scyther  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte Cry_Jynx  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte Cry_Electabuzz  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte Cry_Magmar  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte Cry_Pinsir  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte Cry_Tauros  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Normal_1
gJP_CryTable_Normal_1: @ 0x08625E14
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte Cry_Magikarp  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte Cry_Gyarados  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte Cry_Lapras  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte Cry_Ditto  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte Cry_Eevee  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte Cry_Vaporeon  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte Cry_Jolteon  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte Cry_Flareon  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte Cry_Porygon  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte Cry_Omanyte  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte Cry_Omastar  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte Cry_Kabuto  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte Cry_Kabutops  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte Cry_Aerodactyl  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte Cry_Snorlax  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte Cry_Articuno  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte Cry_Zapdos  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte Cry_Moltres  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte Cry_Dratini  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte Cry_Dragonair  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte Cry_Dragonite  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte Cry_Mewtwo  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte Cry_Mew  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte Cry_Chikorita  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte Cry_Bayleef  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte Cry_Meganium  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte Cry_Cyndaquil  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte Cry_Quilava  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte Cry_Typhlosion  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte Cry_Totodile  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte Cry_Croconaw  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte Cry_Feraligatr  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte Cry_Sentret  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte Cry_Furret  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte Cry_Hoothoot  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte Cry_Noctowl  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte Cry_Ledyba  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte Cry_Ledian  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte Cry_Spinarak  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte Cry_Ariados  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte Cry_Crobat  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte Cry_Chinchou  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte Cry_Lanturn  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte Cry_Pichu  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte Cry_Cleffa  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte Cry_Igglybuff  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte Cry_Togepi  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte Cry_Togetic  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte Cry_Natu  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte Cry_Xatu  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte Cry_Mareep  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte Cry_Flaaffy  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte Cry_Ampharos  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte Cry_Bellossom  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte Cry_Marill  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte Cry_Azumarill  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte Cry_Sudowoodo  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte Cry_Politoed  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte Cry_Hoppip  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte Cry_Skiploom  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte Cry_Jumpluff  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte Cry_Aipom  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte Cry_Sunkern  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte Cry_Sunflora  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte Cry_Yanma  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte Cry_Wooper  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte Cry_Quagsire  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte Cry_Espeon  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte Cry_Umbreon  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte Cry_Murkrow  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte Cry_Slowking  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte Cry_Misdreavus  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte Cry_Unown  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte Cry_Wobbuffet  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte Cry_Girafarig  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte Cry_Pineco  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte Cry_Forretress  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte Cry_Dunsparce  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte Cry_Gligar  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte Cry_Steelix  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte Cry_Snubbull  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte Cry_Granbull  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte Cry_Qwilfish  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte Cry_Scizor  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte Cry_Shuckle  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte Cry_Heracross  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte Cry_Sneasel  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte Cry_Teddiursa  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte Cry_Ursaring  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte Cry_Slugma  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte Cry_Magcargo  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte Cry_Swinub  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte Cry_Piloswine  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte Cry_Corsola  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte Cry_Remoraid  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte Cry_Octillery  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte Cry_Delibird  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte Cry_Mantine  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte Cry_Skarmory  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte Cry_Houndour  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte Cry_Houndoom  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte Cry_Kingdra  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte Cry_Phanpy  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte Cry_Donphan  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte Cry_Porygon2  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte Cry_Stantler  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte Cry_Smeargle  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte Cry_Tyrogue  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte Cry_Hitmontop  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte Cry_Smoochum  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte Cry_Elekid  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte Cry_Magby  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte Cry_Miltank  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte Cry_Blissey  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte Cry_Raikou  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte Cry_Entei  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte Cry_Suicune  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte Cry_Larvitar  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte Cry_Pupitar  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte Cry_Tyranitar  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte Cry_Lugia  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte Cry_HoOh  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte Cry_Celebi  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte Cry_Kecleon  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte Cry_Roselia  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte Cry_Torkoal  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte Cry_Electrike  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte Cry_Manectric  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Normal_2
gJP_CryTable_Normal_2: @ 0x08626414
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte Cry_Duskull  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte Cry_Latias  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte Cry_Wynaut  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte Cry_Seviper  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte Cry_Sharpedo  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte Cry_Zangoose  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte Cry_Azurill  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte Cry_Swablu  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte Cry_Altaria  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte Cry_Unused265  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte Cry_Taillow  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte Cry_Swellow  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte Cry_Unused268  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte Cry_Spinda  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte Cry_Torchic  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte Cry_Combusken  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte Cry_Blaziken  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte Cry_Treecko  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte Cry_Grovyle  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte Cry_Sceptile  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte Cry_Mudkip  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte Cry_Marshtomp  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte Cry_Swampert  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte Cry_Pelipper  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte Cry_Wingull  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte Cry_Banette  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte Cry_Shuppet  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte Cry_Lotad  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte Cry_Lombre  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte Cry_Ludicolo  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte Cry_Seedot  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte Cry_Nuzleaf  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte Cry_Shiftry  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte Cry_Carvanha  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte Cry_Wurmple  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte Cry_Silcoon  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte Cry_Beautifly  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte Cry_Cascoon  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte Cry_Dustox  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte Cry_Ralts  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte Cry_Kirlia  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte Cry_Gardevoir  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte Cry_Slakoth  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte Cry_Vigoroth  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte Cry_Slaking  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte Cry_Nincada  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte Cry_Ninjask  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte Cry_Shedinja  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte Cry_Makuhita  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte Cry_Hariyama  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte Cry_Nosepass  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte Cry_Glalie  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte Cry_Plusle  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte Cry_Minun  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte Cry_Surskit  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte Cry_Masquerain  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte Cry_Skitty  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte Cry_Delcatty  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte Cry_Gulpin  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte Cry_Swalot  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte Cry_Numel  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte Cry_Camerupt  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte Cry_Barboach  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte Cry_Whiscash  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte Cry_Corphish  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte Cry_Crawdaunt  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte Cry_Spoink  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte Cry_Grumpig  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte Cry_Trapinch  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte Cry_Vibrava  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte Cry_Flygon  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte Cry_Cacnea  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte Cry_Cacturne  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte Cry_Baltoy  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte Cry_Claydol  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte Cry_Lunatone  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte Cry_Solrock  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte Cry_Feebas  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte Cry_Milotic  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte Cry_Absol  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte Cry_Meditite  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte Cry_Medicham  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte Cry_Spheal  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte Cry_Sealeo  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte Cry_Walrein  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte Cry_Clamperl  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte Cry_Huntail  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte Cry_Gorebyss  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte Cry_Lileep  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte Cry_Cradily  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte Cry_Anorith  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte Cry_Armaldo  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte Cry_Beldum  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte Cry_Metang  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte Cry_Metagross  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte Cry_Bagon  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte Cry_Shelgon  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte Cry_Regirock  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte Cry_Regice  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte Cry_Registeel  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte Cry_Castform  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte Cry_Volbeat  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte Cry_Illumise  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte Cry_Poochyena  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte Cry_Mightyena  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte Cry_Dusclops  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte Cry_Sableye  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte Cry_Mawile  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte Cry_Aron  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte Cry_Lairon  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte Cry_Aggron  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte Cry_Relicanth  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte Cry_Luvdisc  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte Cry_Groudon  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte Cry_Kyogre  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte Cry_Rayquaza  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte Cry_Salamence  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte Cry_Breloom  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte Cry_Shroomish  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte Cry_Linoone  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte Cry_Tropius  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte Cry_Wailmer  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte Cry_Zigzagoon  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte Cry_Exploud  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte Cry_Loudred  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte Cry_Wailord  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte Cry_Whismur  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte Cry_Snorunt  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Normal_3
gJP_CryTable_Normal_3: @ 0x08626A14
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte Cry_Latios  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte Cry_Jirachi  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte Cry_Deoxys  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x20, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte Cry_Chimecho  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release

	.globl gJP_CryTable_Reverse_0
gJP_CryTable_Reverse_0: @ 0x08626A44
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte Cry_Bulbasaur  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte Cry_Ivysaur  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte Cry_Venusaur  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte Cry_Charmander  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte Cry_Charmeleon  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte Cry_Charizard  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte Cry_Squirtle  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte Cry_Wartortle  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte Cry_Blastoise  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte Cry_Caterpie  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte Cry_Metapod  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte Cry_Butterfree  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte Cry_Weedle  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte Cry_Kakuna  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte Cry_Beedrill  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte Cry_Pidgey  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte Cry_Pidgeotto  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte Cry_Pidgeot  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte Cry_Rattata  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte Cry_Raticate  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte Cry_Spearow  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte Cry_Fearow  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte Cry_Ekans  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte Cry_Arbok  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte Cry_Pikachu  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte Cry_Raichu  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte Cry_Sandshrew  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte Cry_Sandslash  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte Cry_NidoranF  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte Cry_Nidorina  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte Cry_Nidoqueen  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte Cry_NidoranM  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte Cry_Nidorino  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte Cry_Nidoking  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte Cry_Clefairy  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte Cry_Clefable  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte Cry_Vulpix  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte Cry_Ninetales  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte Cry_Jigglypuff  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte Cry_Wigglytuff  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte Cry_Zubat  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte Cry_Golbat  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte Cry_Oddish  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte Cry_Gloom  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte Cry_Vileplume  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte Cry_Paras  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte Cry_Parasect  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte Cry_Venonat  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte Cry_Venomoth  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte Cry_Diglett  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte Cry_Dugtrio  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte Cry_Meowth  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte Cry_Persian  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte Cry_Psyduck  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte Cry_Golduck  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte Cry_Mankey  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte Cry_Primeape  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte Cry_Growlithe  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte Cry_Arcanine  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte Cry_Poliwag  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte Cry_Poliwhirl  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte Cry_Poliwrath  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte Cry_Abra  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte Cry_Kadabra  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte Cry_Alakazam  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte Cry_Machop  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte Cry_Machoke  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte Cry_Machamp  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte Cry_Bellsprout  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte Cry_Weepinbell  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte Cry_Victreebel  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte Cry_Tentacool  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte Cry_Tentacruel  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte Cry_Geodude  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte Cry_Graveler  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte Cry_Golem  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte Cry_Ponyta  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte Cry_Rapidash  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte Cry_Slowpoke  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte Cry_Slowbro  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte Cry_Magnemite  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte Cry_Magneton  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte Cry_Farfetchd  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte Cry_Doduo  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte Cry_Dodrio  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte Cry_Seel  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte Cry_Dewgong  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte Cry_Grimer  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte Cry_Muk  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte Cry_Shellder  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte Cry_Cloyster  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte Cry_Gastly  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte Cry_Haunter  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte Cry_Gengar  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte Cry_Onix  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte Cry_Drowzee  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte Cry_Hypno  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte Cry_Krabby  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte Cry_Kingler  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte Cry_Voltorb  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte Cry_Electrode  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte Cry_Exeggcute  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte Cry_Exeggutor  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte Cry_Cubone  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte Cry_Marowak  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte Cry_Hitmonlee  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte Cry_Hitmonchan  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte Cry_Lickitung  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte Cry_Koffing  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte Cry_Weezing  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte Cry_Rhyhorn  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte Cry_Rhydon  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte Cry_Chansey  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte Cry_Tangela  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte Cry_Kangaskhan  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte Cry_Horsea  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte Cry_Seadra  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte Cry_Goldeen  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte Cry_Seaking  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte Cry_Staryu  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte Cry_Starmie  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte Cry_MrMime  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte Cry_Scyther  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte Cry_Jynx  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte Cry_Electabuzz  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte Cry_Magmar  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte Cry_Pinsir  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte Cry_Tauros  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Reverse_1
gJP_CryTable_Reverse_1: @ 0x08627044
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte Cry_Magikarp  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte Cry_Gyarados  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte Cry_Lapras  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte Cry_Ditto  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte Cry_Eevee  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte Cry_Vaporeon  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte Cry_Jolteon  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte Cry_Flareon  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte Cry_Porygon  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte Cry_Omanyte  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte Cry_Omastar  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte Cry_Kabuto  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte Cry_Kabutops  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte Cry_Aerodactyl  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte Cry_Snorlax  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte Cry_Articuno  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte Cry_Zapdos  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte Cry_Moltres  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte Cry_Dratini  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte Cry_Dragonair  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte Cry_Dragonite  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte Cry_Mewtwo  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte Cry_Mew  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte Cry_Chikorita  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte Cry_Bayleef  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte Cry_Meganium  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte Cry_Cyndaquil  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte Cry_Quilava  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte Cry_Typhlosion  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte Cry_Totodile  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte Cry_Croconaw  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte Cry_Feraligatr  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte Cry_Sentret  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte Cry_Furret  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte Cry_Hoothoot  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte Cry_Noctowl  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte Cry_Ledyba  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte Cry_Ledian  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte Cry_Spinarak  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte Cry_Ariados  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte Cry_Crobat  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte Cry_Chinchou  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte Cry_Lanturn  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte Cry_Pichu  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte Cry_Cleffa  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte Cry_Igglybuff  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte Cry_Togepi  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte Cry_Togetic  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte Cry_Natu  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte Cry_Xatu  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte Cry_Mareep  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte Cry_Flaaffy  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte Cry_Ampharos  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte Cry_Bellossom  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte Cry_Marill  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte Cry_Azumarill  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte Cry_Sudowoodo  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte Cry_Politoed  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte Cry_Hoppip  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte Cry_Skiploom  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte Cry_Jumpluff  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte Cry_Aipom  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte Cry_Sunkern  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte Cry_Sunflora  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte Cry_Yanma  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte Cry_Wooper  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte Cry_Quagsire  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte Cry_Espeon  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte Cry_Umbreon  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte Cry_Murkrow  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte Cry_Slowking  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte Cry_Misdreavus  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte Cry_Unown  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte Cry_Wobbuffet  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte Cry_Girafarig  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte Cry_Pineco  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte Cry_Forretress  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte Cry_Dunsparce  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte Cry_Gligar  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte Cry_Steelix  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte Cry_Snubbull  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte Cry_Granbull  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte Cry_Qwilfish  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte Cry_Scizor  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte Cry_Shuckle  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte Cry_Heracross  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte Cry_Sneasel  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte Cry_Teddiursa  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte Cry_Ursaring  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte Cry_Slugma  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte Cry_Magcargo  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte Cry_Swinub  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte Cry_Piloswine  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte Cry_Corsola  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte Cry_Remoraid  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte Cry_Octillery  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte Cry_Delibird  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte Cry_Mantine  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte Cry_Skarmory  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte Cry_Houndour  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte Cry_Houndoom  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte Cry_Kingdra  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte Cry_Phanpy  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte Cry_Donphan  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte Cry_Porygon2  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte Cry_Stantler  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte Cry_Smeargle  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte Cry_Tyrogue  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte Cry_Hitmontop  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte Cry_Smoochum  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte Cry_Elekid  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte Cry_Magby  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte Cry_Miltank  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte Cry_Blissey  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte Cry_Raikou  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte Cry_Entei  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte Cry_Suicune  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte Cry_Larvitar  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte Cry_Pupitar  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte Cry_Tyranitar  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte Cry_Lugia  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte Cry_HoOh  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte Cry_Celebi  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte Cry_Kecleon  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte Cry_Roselia  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte Cry_Torkoal  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte Cry_Electrike  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte Cry_Manectric  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Reverse_2
gJP_CryTable_Reverse_2: @ 0x08627644
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte Cry_Duskull  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte Cry_Latias  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte Cry_Wynaut  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte Cry_Seviper  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte Cry_Sharpedo  @ [  4] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte Cry_Zangoose  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte Cry_Azurill  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte Cry_Swablu  @ [  7] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte Cry_Altaria  @ [  8] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte Cry_Unused265  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  9] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte Cry_Taillow  @ [ 10] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 10] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte Cry_Swellow  @ [ 11] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 11] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte Cry_Unused268  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 12] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte Cry_Spinda  @ [ 13] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 13] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte Cry_Torchic  @ [ 14] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 14] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte Cry_Combusken  @ [ 15] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte Cry_Blaziken  @ [ 16] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte Cry_Treecko  @ [ 17] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 17] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 18] type, key, length, pan_sweep
	.4byte Cry_Grovyle  @ [ 18] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 18] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 19] type, key, length, pan_sweep
	.4byte Cry_Sceptile  @ [ 19] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 19] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 20] type, key, length, pan_sweep
	.4byte Cry_Mudkip  @ [ 20] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 20] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 21] type, key, length, pan_sweep
	.4byte Cry_Marshtomp  @ [ 21] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 21] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 22] type, key, length, pan_sweep
	.4byte Cry_Swampert  @ [ 22] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 22] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 23] type, key, length, pan_sweep
	.4byte Cry_Pelipper  @ [ 23] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 23] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 24] type, key, length, pan_sweep
	.4byte Cry_Wingull  @ [ 24] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 24] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 25] type, key, length, pan_sweep
	.4byte Cry_Banette  @ [ 25] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 25] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 26] type, key, length, pan_sweep
	.4byte Cry_Shuppet  @ [ 26] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 26] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 27] type, key, length, pan_sweep
	.4byte Cry_Lotad  @ [ 27] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 27] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 28] type, key, length, pan_sweep
	.4byte Cry_Lombre  @ [ 28] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 28] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 29] type, key, length, pan_sweep
	.4byte Cry_Ludicolo  @ [ 29] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 29] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 30] type, key, length, pan_sweep
	.4byte Cry_Seedot  @ [ 30] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 30] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 31] type, key, length, pan_sweep
	.4byte Cry_Nuzleaf  @ [ 31] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 31] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 32] type, key, length, pan_sweep
	.4byte Cry_Shiftry  @ [ 32] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 32] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 33] type, key, length, pan_sweep
	.4byte Cry_Carvanha  @ [ 33] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 33] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 34] type, key, length, pan_sweep
	.4byte Cry_Wurmple  @ [ 34] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 34] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 35] type, key, length, pan_sweep
	.4byte Cry_Silcoon  @ [ 35] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 35] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 36] type, key, length, pan_sweep
	.4byte Cry_Beautifly  @ [ 36] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 36] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 37] type, key, length, pan_sweep
	.4byte Cry_Cascoon  @ [ 37] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 37] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 38] type, key, length, pan_sweep
	.4byte Cry_Dustox  @ [ 38] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 38] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 39] type, key, length, pan_sweep
	.4byte Cry_Ralts  @ [ 39] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 39] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 40] type, key, length, pan_sweep
	.4byte Cry_Kirlia  @ [ 40] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 40] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 41] type, key, length, pan_sweep
	.4byte Cry_Gardevoir  @ [ 41] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 41] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 42] type, key, length, pan_sweep
	.4byte Cry_Slakoth  @ [ 42] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 42] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 43] type, key, length, pan_sweep
	.4byte Cry_Vigoroth  @ [ 43] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 43] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 44] type, key, length, pan_sweep
	.4byte Cry_Slaking  @ [ 44] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 44] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 45] type, key, length, pan_sweep
	.4byte Cry_Nincada  @ [ 45] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 45] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 46] type, key, length, pan_sweep
	.4byte Cry_Ninjask  @ [ 46] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 46] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 47] type, key, length, pan_sweep
	.4byte Cry_Shedinja  @ [ 47] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 47] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 48] type, key, length, pan_sweep
	.4byte Cry_Makuhita  @ [ 48] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 48] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 49] type, key, length, pan_sweep
	.4byte Cry_Hariyama  @ [ 49] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 49] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 50] type, key, length, pan_sweep
	.4byte Cry_Nosepass  @ [ 50] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 50] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte Cry_Glalie  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 51] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte Cry_Plusle  @ [ 52] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 52] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 53] type, key, length, pan_sweep
	.4byte Cry_Minun  @ [ 53] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 53] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 54] type, key, length, pan_sweep
	.4byte Cry_Surskit  @ [ 54] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 54] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 55] type, key, length, pan_sweep
	.4byte Cry_Masquerain  @ [ 55] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 55] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 56] type, key, length, pan_sweep
	.4byte Cry_Skitty  @ [ 56] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 56] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 57] type, key, length, pan_sweep
	.4byte Cry_Delcatty  @ [ 57] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 57] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 58] type, key, length, pan_sweep
	.4byte Cry_Gulpin  @ [ 58] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 58] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 59] type, key, length, pan_sweep
	.4byte Cry_Swalot  @ [ 59] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 59] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 60] type, key, length, pan_sweep
	.4byte Cry_Numel  @ [ 60] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 60] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 61] type, key, length, pan_sweep
	.4byte Cry_Camerupt  @ [ 61] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 61] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 62] type, key, length, pan_sweep
	.4byte Cry_Barboach  @ [ 62] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 62] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 63] type, key, length, pan_sweep
	.4byte Cry_Whiscash  @ [ 63] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 63] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 64] type, key, length, pan_sweep
	.4byte Cry_Corphish  @ [ 64] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 64] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 65] type, key, length, pan_sweep
	.4byte Cry_Crawdaunt  @ [ 65] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 65] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 66] type, key, length, pan_sweep
	.4byte Cry_Spoink  @ [ 66] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 66] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 67] type, key, length, pan_sweep
	.4byte Cry_Grumpig  @ [ 67] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 67] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 68] type, key, length, pan_sweep
	.4byte Cry_Trapinch  @ [ 68] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 68] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 69] type, key, length, pan_sweep
	.4byte Cry_Vibrava  @ [ 69] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 69] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 70] type, key, length, pan_sweep
	.4byte Cry_Flygon  @ [ 70] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 70] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 71] type, key, length, pan_sweep
	.4byte Cry_Cacnea  @ [ 71] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 71] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 72] type, key, length, pan_sweep
	.4byte Cry_Cacturne  @ [ 72] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 72] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 73] type, key, length, pan_sweep
	.4byte Cry_Baltoy  @ [ 73] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 73] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 74] type, key, length, pan_sweep
	.4byte Cry_Claydol  @ [ 74] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 74] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 75] type, key, length, pan_sweep
	.4byte Cry_Lunatone  @ [ 75] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 75] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 76] type, key, length, pan_sweep
	.4byte Cry_Solrock  @ [ 76] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 76] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 77] type, key, length, pan_sweep
	.4byte Cry_Feebas  @ [ 77] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 77] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 78] type, key, length, pan_sweep
	.4byte Cry_Milotic  @ [ 78] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 78] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 79] type, key, length, pan_sweep
	.4byte Cry_Absol  @ [ 79] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 79] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 80] type, key, length, pan_sweep
	.4byte Cry_Meditite  @ [ 80] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 80] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 81] type, key, length, pan_sweep
	.4byte Cry_Medicham  @ [ 81] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 81] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 82] type, key, length, pan_sweep
	.4byte Cry_Spheal  @ [ 82] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 82] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 83] type, key, length, pan_sweep
	.4byte Cry_Sealeo  @ [ 83] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 83] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 84] type, key, length, pan_sweep
	.4byte Cry_Walrein  @ [ 84] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 84] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 85] type, key, length, pan_sweep
	.4byte Cry_Clamperl  @ [ 85] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 85] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 86] type, key, length, pan_sweep
	.4byte Cry_Huntail  @ [ 86] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 86] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 87] type, key, length, pan_sweep
	.4byte Cry_Gorebyss  @ [ 87] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 87] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 88] type, key, length, pan_sweep
	.4byte Cry_Lileep  @ [ 88] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 88] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 89] type, key, length, pan_sweep
	.4byte Cry_Cradily  @ [ 89] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 89] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 90] type, key, length, pan_sweep
	.4byte Cry_Anorith  @ [ 90] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 90] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 91] type, key, length, pan_sweep
	.4byte Cry_Armaldo  @ [ 91] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 91] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 92] type, key, length, pan_sweep
	.4byte Cry_Beldum  @ [ 92] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 92] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 93] type, key, length, pan_sweep
	.4byte Cry_Metang  @ [ 93] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 93] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 94] type, key, length, pan_sweep
	.4byte Cry_Metagross  @ [ 94] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 94] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 95] type, key, length, pan_sweep
	.4byte Cry_Bagon  @ [ 95] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 95] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 96] type, key, length, pan_sweep
	.4byte Cry_Shelgon  @ [ 96] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 96] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 97] type, key, length, pan_sweep
	.4byte Cry_Regirock  @ [ 97] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 97] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 98] type, key, length, pan_sweep
	.4byte Cry_Regice  @ [ 98] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 98] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [ 99] type, key, length, pan_sweep
	.4byte Cry_Registeel  @ [ 99] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [ 99] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [100] type, key, length, pan_sweep
	.4byte Cry_Castform  @ [100] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [100] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [101] type, key, length, pan_sweep
	.4byte Cry_Volbeat  @ [101] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [101] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [102] type, key, length, pan_sweep
	.4byte Cry_Illumise  @ [102] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [102] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [103] type, key, length, pan_sweep
	.4byte Cry_Poochyena  @ [103] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [103] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [104] type, key, length, pan_sweep
	.4byte Cry_Mightyena  @ [104] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [104] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [105] type, key, length, pan_sweep
	.4byte Cry_Dusclops  @ [105] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [105] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [106] type, key, length, pan_sweep
	.4byte Cry_Sableye  @ [106] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [106] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [107] type, key, length, pan_sweep
	.4byte Cry_Mawile  @ [107] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [107] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [108] type, key, length, pan_sweep
	.4byte Cry_Aron  @ [108] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [108] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [109] type, key, length, pan_sweep
	.4byte Cry_Lairon  @ [109] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [109] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [110] type, key, length, pan_sweep
	.4byte Cry_Aggron  @ [110] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [110] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [111] type, key, length, pan_sweep
	.4byte Cry_Relicanth  @ [111] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [111] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [112] type, key, length, pan_sweep
	.4byte Cry_Luvdisc  @ [112] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [112] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [113] type, key, length, pan_sweep
	.4byte Cry_Groudon  @ [113] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [113] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [114] type, key, length, pan_sweep
	.4byte Cry_Kyogre  @ [114] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [114] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [115] type, key, length, pan_sweep
	.4byte Cry_Rayquaza  @ [115] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [115] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [116] type, key, length, pan_sweep
	.4byte Cry_Salamence  @ [116] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [116] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [117] type, key, length, pan_sweep
	.4byte Cry_Breloom  @ [117] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [117] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [118] type, key, length, pan_sweep
	.4byte Cry_Shroomish  @ [118] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [118] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [119] type, key, length, pan_sweep
	.4byte Cry_Linoone  @ [119] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [119] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [120] type, key, length, pan_sweep
	.4byte Cry_Tropius  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte Cry_Wailmer  @ [121] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [121] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [122] type, key, length, pan_sweep
	.4byte Cry_Zigzagoon  @ [122] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [122] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [123] type, key, length, pan_sweep
	.4byte Cry_Exploud  @ [123] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [123] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [124] type, key, length, pan_sweep
	.4byte Cry_Loudred  @ [124] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [124] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [125] type, key, length, pan_sweep
	.4byte Cry_Wailord  @ [125] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [125] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [126] type, key, length, pan_sweep
	.4byte Cry_Whismur  @ [126] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [126] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [127] type, key, length, pan_sweep
	.4byte Cry_Snorunt  @ [127] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [127] attack, decay, sustain, release

	.globl gJP_CryTable_Reverse_3
gJP_CryTable_Reverse_3: @ 0x08627C44
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  0] type, key, length, pan_sweep
	.4byte Cry_Latios  @ [  0] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  0] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  1] type, key, length, pan_sweep
	.4byte Cry_Jirachi  @ [  1] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  1] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  2] type, key, length, pan_sweep
	.4byte Cry_Deoxys  @ [  2] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  2] attack, decay, sustain, release
	.byte 0x30, 0x3C, 0x00, 0x00  @ [  3] type, key, length, pan_sweep
	.4byte Cry_Chimecho  @ [  3] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  3] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [  4] type, key, length, pan_sweep
	.4byte 0x00000002  @ [  4] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [  4] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [  5] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_sc88pro_mute_high_conga  @ [  5] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  5] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [  6] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_sc88pro_open_low_conga  @ [  6] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [  6] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [  7] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_sc88pro_tr909_hand_clap  @ [  7] wav
	.byte 0xFF, 0xE2, 0x19, 0x00  @ [  7] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [  8] type, key, length, pan_sweep
	.4byte 0x00000002  @ [  8] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [  8] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [  9] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_unknown_1  @ [  9] wav
	.byte 0xFF, 0x00, 0xFF, 0xA5  @ [  9] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 10] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_dance_drums_ride_bell  @ [ 10] wav
	.byte 0xFF, 0xA5, 0x67, 0xE7  @ [ 10] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 11] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_sd90_open_triangle  @ [ 11] wav
	.byte 0xFF, 0xCC, 0x80, 0xF9  @ [ 11] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 12] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_register_noise  @ [ 12] wav
	.byte 0xFF, 0x00, 0xFF, 0x4C  @ [ 12] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 13] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_unknown_18  @ [ 13] wav
	.byte 0xFF, 0x00, 0xCE, 0xCC  @ [ 13] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 14] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_ethnic_flavours_ohtsuzumi  @ [ 14] wav
	.byte 0xFF, 0x00, 0xCE, 0x26  @ [ 14] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 15] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_ethnic_flavours_hyoushigi  @ [ 15] wav
	.byte 0xFF, 0x00, 0xCE, 0x00  @ [ 15] attack, decay, sustain, release
	.byte 0x01, 0x3C, 0x00, 0x00  @ [ 16] type, key, length, pan_sweep
	.4byte 0x00000002  @ [ 16] wav
	.byte 0x00, 0x00, 0x0F, 0x00  @ [ 16] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 17] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_sc88pro_xylophone  @ [ 17] wav
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
	.4byte DirectSoundWaveData_sc88pro_nylon_str_guitar  @ [ 28] wav
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
	.4byte DirectSoundWaveData_sd90_special_scream_drive  @ [ 35] wav
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
	.4byte DirectSoundWaveData_sc88pro_synth_bass  @ [ 42] wav
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
	.4byte DirectSoundWaveData_sc88pro_harp  @ [ 50] wav
	.byte 0xFF, 0xFC, 0x00, 0xCC  @ [ 50] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 51] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_sc88pro_accordion_duplicate  @ [ 51] wav
	.byte 0xFF, 0x00, 0xFF, 0xA5  @ [ 51] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [ 52] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_sc88pro_square_wave  @ [ 52] wav
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
	.4byte DirectSoundWaveData_sc88pro_taiko  @ [120] wav
	.byte 0xFF, 0x00, 0xFF, 0x00  @ [120] attack, decay, sustain, release
	.byte 0x00, 0x3C, 0x00, 0x00  @ [121] type, key, length, pan_sweep
	.4byte DirectSoundWaveData_sd90_ambient_tom  @ [121] wav
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
	.include "sound/direct_sound_data.inc"
