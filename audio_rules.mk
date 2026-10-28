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
