#include "global.h"
#include "walda_phrase.h"
#include "constants/characters.h"
#include "string_util.h"
#include "event_data.h"
#include "naming_screen.h"
#include "main.h"
#include "new_game.h"
#include "overworld.h"
#include "pokemon_storage_system.h"
#include "field_screen_effect.h"

// Default phrase used when the player confirms an empty naming screen.
const u8 gText_Peekaboo[] __attribute__((section(".rodata.walda_phrase_peekaboo"))) =
{
    0x02, 0x15, 0x02, 0x02, 0x15, 0x02, 0x46, 0x01, 0xAE, EOS
};

static void CB2_HandleGivenWaldaPhrase(void);
static u32 GetWaldaPhraseInputCase(u8 *);
static bool32 TryCalculateWallpaper(u16 *, u16 *, u8 *, u8 *, u16, const u8 *);
static void SetWallpaperDataFromLetter(u8 *, const u8 *, u32, u32, u32);
static void RotateWallpaperDataLeft(u8 *, u32, u32);
static void MaskWallpaperData(u8 *, u32, u8);

enum
{
    PHRASE_CHANGED,
    PHRASE_NO_CHANGE,
    PHRASE_EMPTY
};

u16 TryBufferWaldaPhrase(void)
{
    if (IsWaldaPhraseEmpty())
        return FALSE;

    StringCopy(gStringVar1, GetWaldaPhrasePtr());
    return TRUE;
}

void DoWaldaNamingScreen(void)
{
    StringCopy(gStringVar2, GetWaldaPhrasePtr());
    DoNamingScreen(NAMING_SCREEN_WALDA, gStringVar2, 0, 0, 0, CB2_HandleGivenWaldaPhrase);
}

static void CB2_HandleGivenWaldaPhrase(void)
{
    gSpecialVar_0x8004 = GetWaldaPhraseInputCase(gStringVar2);

    switch (gSpecialVar_0x8004)
    {
    case PHRASE_EMPTY:
        if (IsWaldaPhraseEmpty())
            SetWaldaPhrase(gText_Peekaboo);
        else
            gSpecialVar_0x8004 = PHRASE_NO_CHANGE;
        break;
    case PHRASE_CHANGED:
        SetWaldaPhrase(gStringVar2);
        break;
    case PHRASE_NO_CHANGE:
        break;
    }

    StringCopy(gStringVar1, GetWaldaPhrasePtr());
    gFieldCallback = FieldCB_ContinueScriptHandleMusic;
    SetMainCallback2(CB2_ReturnToField);
}

static u32 GetWaldaPhraseInputCase(u8 *inputPtr)
{
    // No input given
    if (inputPtr[0] == EOS)
        return PHRASE_EMPTY;

    // Input given is the same as saved phrase
    if (StringCompare(inputPtr, GetWaldaPhrasePtr()) == 0)
        return PHRASE_NO_CHANGE;

    // Input is new phrase
    return PHRASE_CHANGED;
}

u16 TryGetWallpaperWithWaldaPhrase(void)
{
    u16 backgroundClr, foregroundClr;
    u8 patternId, iconId;
    u16 trainerId = GetTrainerId(gSaveBlock2Ptr->playerTrainerId);

    gSpecialVar_Result = TryCalculateWallpaper(&backgroundClr, &foregroundClr, &iconId, &patternId, trainerId, GetWaldaPhrasePtr());

    if (gSpecialVar_Result)
    {
        SetWaldaWallpaperPatternId(patternId);
        SetWaldaWallpaperIconId(iconId);
        SetWaldaWallpaperColors(backgroundClr, foregroundClr);
    }

    SetWaldaWallpaperLockedOrUnlocked(gSpecialVar_Result);
    return (bool8)gSpecialVar_Result;
}

// JP uses a 12-letter phrase.  Each letter contributes 6 bits, so the whole
// phrase exactly fills the 9-byte (72-bit) wallpaper data array.
#define JP_WALDA_PHRASE_LENGTH 12
#define WALLPAPER_DATA_SIZE 9
#define BITS_PER_LETTER 6

static bool32 TryCalculateWallpaper(u16 *backgroundClr, u16 *foregroundClr, u8 *iconId, u8 *patternId, u16 trainerId, const u8 *phrase)
{
    u8 data[WALLPAPER_DATA_SIZE];
    u8 charsByTableId[JP_WALDA_PHRASE_LENGTH];
    s32 i;

    // Reject any phrase that does not use the full length
    if (StringLength(phrase) != JP_WALDA_PHRASE_LENGTH)
        return FALSE;

    // JP maps each letter to its table id by subtracting 1 from its char code
    for (i = 0; i < JP_WALDA_PHRASE_LENGTH; i++)
        charsByTableId[i] = phrase[i] - 1;

    // Use the given phrase to populate the wallpaper data array
    for (i = 0; i < JP_WALDA_PHRASE_LENGTH; i++)
        SetWallpaperDataFromLetter(data, charsByTableId, BITS_PER_LETTER * i, 2 + 8 * i, BITS_PER_LETTER);

    // Perform some relatively arbitrary changes to the wallpaper data using the last byte (KEY)
    RotateWallpaperDataLeft(data, WALLPAPER_DATA_SIZE, 21);
    RotateWallpaperDataLeft(data, WALLPAPER_DATA_SIZE - 1, data[8] & 0xF);
    MaskWallpaperData(data, WALLPAPER_DATA_SIZE - 1, data[8] >> 4);

    // Reject the results of any phrase that are 'incompatible' with the player's trainer id
    if (data[6] != (data[0] ^ data[2] ^ data[4] ^ (trainerId >> 8)))
        return FALSE;
    if (data[7] != (data[1] ^ data[3] ^ data[5] ^ (trainerId & 0xFF)))
        return FALSE;

    // Successful phrase, save resulting wallpaper
    memcpy(backgroundClr, &data[0], 2);
    memcpy(foregroundClr, &data[2], 2);
    *iconId = data[4];
    *patternId = data[5];

    return TRUE;
}

static void RotateWallpaperDataLeft(u8 *data, u32 size, u32 numShifts)
{
    s32 j;
    u8 temp1, temp2;

    while (numShifts--)
    {
        temp1 = (data[0] & (1 << 7)) >> 7;

        for (j = size - 1; j >= 0; j--)
        {
            temp2 = (data[j] & (1 << 7)) >> 7;
            data[j] <<= 1;
            data[j] |= temp1;
            temp1 = temp2;
        }
    }
}

static void MaskWallpaperData(u8 *data, u32 size, u8 mask)
{
    u32 i;

    mask |= (mask << 4);

    for (i = 0; i < size; i++)
        data[i] ^= mask;
}

static bool8 GetWallpaperDataBit(const u8 *data, u32 bitNum)
{
    u32 i = bitNum / 8;
    u32 flag = (1 << 7) >> (bitNum % 8);

    return (data[i] & flag) != 0;
}

static void SetWallpaperDataBit(u8 *data, u32 bitNum)
{
    u32 i = bitNum / 8;
    u8 flag = (1 << 7) >> (bitNum % 8);

    data[i] |= flag;
}

static void ClearWallpaperDataBit(u8 *data, u32 bitNum)
{
    u32 i = bitNum / 8;
    u8 mask = ~((1 << 7) >> (bitNum % 8));

    data[i] &= mask;
}

static void SetWallpaperDataFromLetter(u8 *data, const u8 *letterTableIds, u32 setOffset, u32 getOffset, u32 numBits)
{
    u32 i;

    for (i = 0; i < numBits; i++)
    {
        if (GetWallpaperDataBit(letterTableIds, getOffset + i))
            SetWallpaperDataBit(data, setOffset + i);
        else
            ClearWallpaperDataBit(data, setOffset + i);
    }
}
