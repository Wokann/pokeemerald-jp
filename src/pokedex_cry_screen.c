#include "global.h"
#include "bg.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "palette.h"
#include "pokedex_cry_screen.h"
#include "sound.h"
#include "trig.h"
#include "window.h"

// Cry meter needle positions
//
//          0
//    32   .  .  -32
//      .        .
// 64  .          . -64
//     .          .
//      .        .
//    96   .  .  -96
//         127
//
#define MIN_NEEDLE_POS  32
#define MAX_NEEDLE_POS -32

#define NEEDLE_MOVE_INCREMENT  5

#define WAVEFORM_WINDOW_HEIGHT 56

#define TAG_NEEDLE 0x2000

struct PokedexCryMeterNeedle {
    s8 rotation;
    s8 targetRotation;
    u8 moveIncrement;
    u16 spriteId;
};

struct PokedexCryScreen
{
    u8 cryWaveformBuffer[16];
    u8 cryState;
    u8 playhead;
    u8 waveformPreviousY;
    u16 unk; // Never read
    u8 playStartPos;
    u16 species;
    u8 cryOverrideCountdown;
    u8 cryRepeatDelay;
};

static void PlayCryScreenCry(u16);
static void BufferCryWaveformSegment(void);
static void DrawWaveformFlatline(void);
static void AdvancePlayhead(u8);
static void DrawWaveformSegment(u8, u8);
static void DrawWaveformWindow(u8);
static void ShiftWaveformOver(u8, s16, bool8);
static void SpriteCB_CryMeterNeedle(struct Sprite *);
static void SetCryMeterNeedleTarget(s8);

// IWRAM common
extern COMMON_DATA u8 gDexCryScreenState;

// EWRAM vars
extern EWRAM_DATA struct PokedexCryScreen *sDexCryScreen;
extern EWRAM_DATA u8 *sCryWaveformWindowTiledata;
extern EWRAM_DATA struct PokedexCryMeterNeedle *sCryMeterNeedle;

extern const u16 sCryMeter_Pal[];
extern const u8 sCryMeter_Gfx[];
extern const u16 sWaveformOffsets[][72];
extern const u16 sCryScreenBg_Pal[];
extern const u8 sCryScreenBg_Gfx[];
extern const u8 sWaveformTileDataNybbleMasks[];
extern const u8 sWaveformColor[][16];
extern const struct SpriteTemplate sCryMeterNeedleSpriteTemplate;
extern const struct SpriteSheet sCryMeterNeedleSpriteSheets[];
extern const struct SpritePalette sCryMeterNeedleSpritePalettes[];


bool8 LoadCryWaveformWindow(struct CryScreenWindow *window, u8 windowId)
{
    u8 i;
    u8 finished = FALSE;

    switch (gDexCryScreenState)
    {
    case 0:
        if (!sDexCryScreen)
        {
            sDexCryScreen = AllocZeroed(sizeof(*sDexCryScreen));
            sCryWaveformWindowTiledata = (u8 *)GetWindowAttribute(windowId, WINDOW_TILE_DATA);
        }

        sDexCryScreen->unk = window->unk0;
        sDexCryScreen->playStartPos = window->yPos;
        sDexCryScreen->cryOverrideCountdown = 0;
        sDexCryScreen->cryRepeatDelay = 0;
        sDexCryScreen->cryState = 0;
        sDexCryScreen->waveformPreviousY = WAVEFORM_WINDOW_HEIGHT / 2;
        sDexCryScreen->playhead = 0;
        ShiftWaveformOver(windowId, -8 * window->xPos, TRUE); // Does nothing
        for (i = 0; i < 224; i++)
            CopyToWindowPixelBuffer(windowId, sCryScreenBg_Gfx, TILE_SIZE_4BPP, i);

        gDexCryScreenState++;
        break;
    case 1:
        for (i = 0; i < sDexCryScreen->playStartPos * 8; i++)
            DrawWaveformSegment(i, 0);

        gDexCryScreenState++;
        break;
    case 2:
        DrawWaveformWindow(windowId);
        LoadPalette(sCryScreenBg_Pal, BG_PLTT_ID(window->paletteNo), PLTT_SIZE_4BPP);
        finished = TRUE;
        break;
    }

    return finished;
}

void UpdateCryWaveformWindow(u8 windowId)
{
    u8 waveformIdx;

    DrawWaveformWindow(windowId);
    AdvancePlayhead(windowId);

    // Cry cant be replayed until this counter is done
    if (sDexCryScreen->cryRepeatDelay)
        sDexCryScreen->cryRepeatDelay--;

    // Once a cry replay has started, it waits for this countdown before playing
    if (sDexCryScreen->cryOverrideCountdown)
    {
        sDexCryScreen->cryOverrideCountdown--;
        if (!sDexCryScreen->cryOverrideCountdown)
        {
            PlayCryScreenCry(sDexCryScreen->species);
            DrawWaveformFlatline();
            return;
        }
    }

    // No cry playing
    if (sDexCryScreen->cryState == 0)
    {
        DrawWaveformFlatline();
        return;
    }

    // Cry playing, buffer waveform
    if (sDexCryScreen->cryState == 1)
    {
        BufferCryWaveformSegment();
    }
    else if (sDexCryScreen->cryState > 8)
    {
        // Buffered waveform exhausted, end or buffer more
        if (!IsCryPlaying())
        {
            DrawWaveformFlatline();
            sDexCryScreen->cryState = 0;
            return;
        }

        BufferCryWaveformSegment();
        sDexCryScreen->cryState = 1;
    }

    // Draw cry
    waveformIdx = 2 * (sDexCryScreen->cryState - 1);
    DrawWaveformSegment(sDexCryScreen->playStartPos * 8 + sDexCryScreen->playhead - 2, sDexCryScreen->cryWaveformBuffer[waveformIdx]);
    DrawWaveformSegment(sDexCryScreen->playStartPos * 8 + sDexCryScreen->playhead - 1, sDexCryScreen->cryWaveformBuffer[waveformIdx + 1]);
    sDexCryScreen->cryState++;
}

void CryScreenPlayButton(u16 species)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE && !sDexCryScreen->cryOverrideCountdown)
    {
        if (!sDexCryScreen->cryRepeatDelay)
        {
            sDexCryScreen->cryRepeatDelay = 4;
            if (IsCryPlaying() == TRUE)
            {
                StopCry();
                sDexCryScreen->species = species;
                sDexCryScreen->cryOverrideCountdown = 2;
            }
            else
            {
                PlayCryScreenCry(species);
            }
        }
    }
}

static void PlayCryScreenCry(u16 species)
{
    PlayCry_NormalNoDucking(species, 0, CRY_VOLUME_RS, CRY_PRIORITY_NORMAL);
    sDexCryScreen->cryState = 1;
}

static void BufferCryWaveformSegment(void)
{
    u8 i;
    s8 *baseBuffer;
    s8 *buffer;

    if (gPcmDmaCounter < 2)
        baseBuffer = gSoundInfo.pcmBuffer;
    else
        baseBuffer = gSoundInfo.pcmBuffer + (gSoundInfo.pcmDmaPeriod + 1 - gPcmDmaCounter) * gSoundInfo.pcmSamplesPerVBlank;

    buffer = baseBuffer + PCM_DMA_BUF_SIZE;
    for (i = 0; i < ARRAY_COUNT(sDexCryScreen->cryWaveformBuffer); i++)
        sDexCryScreen->cryWaveformBuffer[i] = buffer[i * 2] * 2;
}

static void DrawWaveformFlatline(void)
{
    DrawWaveformSegment(sDexCryScreen->playStartPos * 8 + sDexCryScreen->playhead - 2, 0);
    DrawWaveformSegment(sDexCryScreen->playStartPos * 8 + sDexCryScreen->playhead - 1, 0);
}

static void AdvancePlayhead(u8 windowId)
{
    u8 i;
    u16 offset;

    ShiftWaveformOver(windowId, sDexCryScreen->playhead, FALSE);
    sDexCryScreen->playhead += 2;
    offset = (sDexCryScreen->playhead / 8 + sDexCryScreen->playStartPos + 1) % 32;
    for (i = 0; i < 7; i++)
        CopyToWindowPixelBuffer(windowId, sCryScreenBg_Gfx, TILE_SIZE_4BPP, offset + (i * TILE_SIZE_4BPP));
}

// Waveform segments are drawn in alternate vertical slices
// Note that the waveform isnt put on screen until DrawWaveformWindow
static void DrawWaveformSegment(u8 position, u8 amplitude)
{
    // Position is a bitfield containing the play start pos, the playhead pos, and which vertical slice half to draw
    #define PLAY_START_POS (position >> 3)
    #define PLAYHEAD_POS   (position & ((1 << 3) - 1))
    #define VERT_SLICE     (position & 1)

    u8 currentPointY;
    u8 nybble;
    u16 offset;
    u16 temp;
    u8 y;

    temp = (amplitude + 127) * 256;
    y = temp / 1152.0;
    if (y > WAVEFORM_WINDOW_HEIGHT - 1)
        y = WAVEFORM_WINDOW_HEIGHT - 1;
    currentPointY = y;
    nybble = VERT_SLICE;
    if (y > sDexCryScreen->waveformPreviousY)
    {
        // Current point lower than previous point, draw point and draw line up to previous
        do
        {
            offset = sWaveformOffsets[PLAYHEAD_POS][y] + PLAY_START_POS * TILE_SIZE_4BPP;
            sCryWaveformWindowTiledata[offset] &= sWaveformTileDataNybbleMasks[nybble];
            sCryWaveformWindowTiledata[offset] |= sWaveformColor[nybble][((y / 3) - 1) & 0x0F];
            y--;
        } while (y > sDexCryScreen->waveformPreviousY);
    }
    else
    {
        // Current point higher than previous point, draw point and draw line down to previous
        do
        {
            offset = sWaveformOffsets[PLAYHEAD_POS][y] + PLAY_START_POS * TILE_SIZE_4BPP;
            sCryWaveformWindowTiledata[offset] &= sWaveformTileDataNybbleMasks[nybble];
            sCryWaveformWindowTiledata[offset] |= sWaveformColor[nybble][((y / 3) - 1) & 0x0F];
            y++;
        } while (y < sDexCryScreen->waveformPreviousY);
    }

    sDexCryScreen->waveformPreviousY = currentPointY;
}

static void DrawWaveformWindow(u8 windowId)
{
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

// rsVertical is leftover from a very different version of this function in RS
// In RS, when TRUE it would use VOFS and when FALSE it would use HOFS (only FALSE was used)
// Here when TRUE it does nothing
static void ShiftWaveformOver(u8 windowId, s16 offset, bool8 rsVertical)
{
    if (!rsVertical)
    {
        u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
        ChangeBgX(bg, offset << 8, BG_COORD_SET);
    }
}

bool8 LoadCryMeter(struct CryScreenWindow *window, u8 windowId)
{
    bool8 finished = FALSE;

    switch (gDexCryScreenState)
    {
    case 0:
        if (!sCryMeterNeedle)
            sCryMeterNeedle = AllocZeroed(sizeof(*sCryMeterNeedle));

        CopyToWindowPixelBuffer(windowId, sCryMeter_Gfx, 0, 0);
        LoadPalette(sCryMeter_Pal, BG_PLTT_ID(window->paletteNo), PLTT_SIZE_4BPP);
        gDexCryScreenState++;
        break;
    case 1:
        LoadSpriteSheets(sCryMeterNeedleSpriteSheets);
        LoadSpritePalettes(sCryMeterNeedleSpritePalettes);
        sCryMeterNeedle->spriteId = CreateSprite(&sCryMeterNeedleSpriteTemplate, 40 + window->xPos * 8, 56 + window->yPos * 8, 1);
        sCryMeterNeedle->rotation = MIN_NEEDLE_POS;
        sCryMeterNeedle->targetRotation = MIN_NEEDLE_POS;
        sCryMeterNeedle->moveIncrement = 0;
        finished = TRUE;
        break;
    }

    return finished;
}

void FreeCryScreen(void)
{
    FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(gSprites[sCryMeterNeedle->spriteId].oam.paletteNum));
    DestroySprite(gSprites + sCryMeterNeedle->spriteId);
    FREE_AND_SET_NULL(sDexCryScreen);
    FREE_AND_SET_NULL(sCryMeterNeedle);
}

static void SpriteCB_CryMeterNeedle(struct Sprite *sprite)
{
    u16 i;
    s8 peakAmplitude;
    s16 x;
    s16 y;
    struct ObjAffineSrcData affine;
    struct OamMatrix matrix;
    u8 amplitude;

    gSprites[sCryMeterNeedle->spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[sCryMeterNeedle->spriteId].oam.affineParam = 0;

    // While no cry is playing, cryState is 0
    // While cry is playing, cryState loops 1-8
    switch (sDexCryScreen->cryState)
    {
    case 0:
        sCryMeterNeedle->targetRotation = MIN_NEEDLE_POS;
        if (sCryMeterNeedle->rotation > 0)
        {
            if (sCryMeterNeedle->moveIncrement != 1)
                sCryMeterNeedle->moveIncrement--;
        }
        else
        {
            sCryMeterNeedle->moveIncrement = NEEDLE_MOVE_INCREMENT;
        }
        break;
    case 2:
        peakAmplitude = 0;
        for (i = 0; i < ARRAY_COUNT(sDexCryScreen->cryWaveformBuffer); i++)
        {
            if (peakAmplitude < sDexCryScreen->cryWaveformBuffer[i])
                peakAmplitude = sDexCryScreen->cryWaveformBuffer[i];
        }
        SetCryMeterNeedleTarget(peakAmplitude * 208 / 256);
        break;
    case 6:
        // To introduce some randomness, needle jumps to set pos in waveform rather than peak
        amplitude = sDexCryScreen->cryWaveformBuffer[10];
        SetCryMeterNeedleTarget(amplitude * 208 / 256);
        break;
    }

    if (sCryMeterNeedle->rotation == sCryMeterNeedle->targetRotation)
    {
        // Empty, needle has reached target
    }
    else if (sCryMeterNeedle->rotation < sCryMeterNeedle->targetRotation)
    {
        // Rotate needle left
        sCryMeterNeedle->rotation += sCryMeterNeedle->moveIncrement;
        if (sCryMeterNeedle->rotation > sCryMeterNeedle->targetRotation)
        {
            sCryMeterNeedle->rotation = sCryMeterNeedle->targetRotation;
            sCryMeterNeedle->targetRotation = 0;
        }
    }
    else
    {
        // Rotate needle right
        sCryMeterNeedle->rotation -= sCryMeterNeedle->moveIncrement;
        if (sCryMeterNeedle->rotation < sCryMeterNeedle->targetRotation)
        {
            sCryMeterNeedle->rotation = sCryMeterNeedle->targetRotation;
            sCryMeterNeedle->targetRotation = 0;
        }
    }

    affine.xScale = 256;
    affine.yScale = 256;
    affine.rotation = sCryMeterNeedle->rotation * 256;
    ObjAffineSet(&affine, &matrix, 1, 2);
    SetOamMatrix(0, matrix.a, matrix.b, matrix.c, matrix.d);
    x = gSineTable[((sCryMeterNeedle->rotation + 0x7F) & 0xFF)];
    y = gSineTable[((sCryMeterNeedle->rotation + 0x7F) & 0xFF) + 64];
    sprite->x2 = x * 24 / 256;
    sprite->y2 = y * 24 / 256;
}

static void SetCryMeterNeedleTarget(s8 offset)
{
    u16 rotation = (MIN_NEEDLE_POS - offset) & 0xFF;

    // Min is positive, max is negative. Make sure needle hasnt moved out of bounds
    if (rotation > MIN_NEEDLE_POS && rotation < (u8)MAX_NEEDLE_POS)
        rotation = (u8)MAX_NEEDLE_POS;

    sCryMeterNeedle->targetRotation = rotation;
    sCryMeterNeedle->moveIncrement = NEEDLE_MOVE_INCREMENT;
}
