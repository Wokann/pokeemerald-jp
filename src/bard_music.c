#include "global.h"
#include "m4a.h"
#include "gba/m4a_internal.h"

// JP-only word voice helpers (no US pokeemerald counterpart): the old man
// in Mauville reads word data out of the JP ROM tables below, which are
// bound via ld aliases.
struct WordPhoneme
{
    s16 phoneme;
    u16 song;
};

struct WordInfo
{
    u8 pad0[0x14];
    u16 field14; // song/volume
    s16 field16; // pitch index
    s16 field18; // sound table row
    s16 field1A; // sound table column
    s16 field1C; // retry counter
};

extern const struct WordPhoneme sWordPhonemes[];
extern const s16 *const sWordSounds[];

void CalcWordPitch(struct WordInfo *word, u16 pitch, u16 volume)
{
    word->field16 = 0;
    word->field18 = pitch - 1;
    word->field1A = volume;
    word->field1C = 0;
}

// JP byte-exact: agbcc folds `phoneme < -2 || phoneme > 0` into a u16
// range check, but the JP ROM uses two signed comparisons; keep naked asm.
__attribute__((naked)) void GetWordPhonemes(struct WordInfo *word, u8 phonemeId)
{
    __asm__(".syntax unified\n\t"
        "push {r4, lr}\n\t"
        "adds r4, r0, #0\n\t"
        "lsls r1, r1, #0x18\n\t"
        "lsrs r1, r1, #0x18\n\t"
        "ldr r2, _0817C6E0\n\t"
        "lsls r0, r1, #1\n\t"
        "adds r0, #1\n\t"
        "lsls r0, r0, #1\n\t"
        "adds r0, r0, r2\n\t"
        "ldrh r0, [r0]\n\t"
        "strh r0, [r4, #0x14]\n\t"
        "lsls r1, r1, #2\n\t"
        "adds r1, r1, r2\n\t"
        "ldrh r0, [r1]\n\t"
        "movs r2, #0\n\t"
        "ldrsh r1, [r1, r2]\n\t"
        "movs r2, #2\n\t"
        "rsbs r2, r2, #0\n\t"
        "cmp r1, r2\n\t"
        "bne _0817C6E8\n\t"
        "ldr r0, _0817C6E4\n\t"
        "bl m4aMPlayStop\n\t"
        "b _0817C6F0\n\t"
        ".align 2, 0\n\t"
        "_0817C6E0: .4byte sWordPhonemes\n\t"
        "_0817C6E4: .4byte gMPlayInfo_SE1\n\t"
        "_0817C6E8:\n\t"
        "cmp r1, r2\n\t"
        "blt _0817C6F8\n\t"
        "cmp r1, #0\n\t"
        "bgt _0817C6F8\n\t"
        "_0817C6F0:\n\t"
        "ldrh r0, [r4, #0x1c]\n\t"
        "adds r0, #1\n\t"
        "strh r0, [r4, #0x1c]\n\t"
        "b _0817C6FC\n\t"
        "_0817C6F8:\n\t"
        "bl m4aSongNumStart\n\t"
        "_0817C6FC:\n\t"
        "pop {r4}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".syntax divided\n\t"
    );
}

void GetWordSounds(struct WordInfo *word)
{
    if (word->field1C != 0)
    {
        word->field1C = 0;
    }
    else
    {
        s16 pitch;
        const s16 *soundData;

        m4aMPlayVolumeControl(&gMPlayInfo_SE1, TRACKS_ALL, word->field14);
        soundData = sWordSounds[word->field18 * 5 + word->field1A];
        pitch = soundData[word->field16];
        m4aMPlayPitchControl(&gMPlayInfo_SE1, TRACKS_ALL, pitch);
    }
    word->field16++;
}
