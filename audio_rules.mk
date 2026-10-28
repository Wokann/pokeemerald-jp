# Generate editable sound sources with the same formats as pokeemerald.
JP_DIRECT_SOUND_WAVS := $(wildcard sound/direct_sound_samples/*.wav sound/direct_sound_samples/cries/*.wav)
JP_DIRECT_SOUND_ASSETS := $(patsubst %.wav,%.bin,$(JP_DIRECT_SOUND_WAVS))

# Compressed cries retain the original DPCM lookahead and tail length.
sound/direct_sound_samples/cries/%.bin: sound/direct_sound_samples/cries/%.wav | tools
	$(WAV2AGB) -b -c -l 1 --no-pad $< $@

# Instruments and the Japanese Bard vowels are uncompressed PCM.
sound/%.bin: sound/%.wav | tools
	$(WAV2AGB) -b $< $@

$(OBJ_DIR)/data/sound_data.o: sound/direct_sound_data.inc $(JP_DIRECT_SOUND_ASSETS) audio_rules.mk

JP_VOICEGROUP_INCLUDES := $(wildcard sound/voicegroups/*.inc sound/voicegroups/drumsets/*.inc sound/voicegroups/keysplits/*.inc)
JP_PROGRAMMABLE_WAVES := $(wildcard sound/programmable_wave_samples/*.pcm)

$(OBJ_DIR)/data/sound_data.o: asm/macros/m4a.inc asm/macros/music_voice.inc sound/voice_groups.inc sound/cry_tables.inc sound/keysplit_tables.inc sound/programmable_wave_data.inc sound/music_player_table.inc sound/song_table.inc $(JP_VOICEGROUP_INCLUDES) $(JP_PROGRAMMABLE_WAVES)
