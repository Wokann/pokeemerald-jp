#include "global.h"
#include "palette.h"
#include "palette_util.h"
#include "util.h"

void RouletteFlash_Reset(struct RouletteFlashUtil *flash)
{
    flash->enabled = 0;
    flash->flags = 0;
    memset(&flash->palettes, 0, sizeof(flash->palettes));
}

u8 RouletteFlash_Add(struct RouletteFlashUtil *flash, u8 id, const struct RouletteFlashSettings *settings)
{
    if (id >= ARRAY_COUNT(flash->palettes) || flash->palettes[id].available)
        return 0xFF;

    flash->palettes[id].settings.color = settings->color;
    flash->palettes[id].settings.paletteOffset = settings->paletteOffset;
    flash->palettes[id].settings.numColors = settings->numColors;
    flash->palettes[id].settings.delay = settings->delay;
    flash->palettes[id].settings.unk6 = settings->unk6;
    flash->palettes[id].settings.numFadeCycles = settings->numFadeCycles;
    flash->palettes[id].settings.unk7_5 = settings->unk7_5;
    flash->palettes[id].settings.colorDeltaDir = settings->colorDeltaDir;
    flash->palettes[id].state = 0;
    flash->palettes[id].available = TRUE;
    flash->palettes[id].fadeCycleCounter = 0;
    flash->palettes[id].delayCounter = 0;
    if (flash->palettes[id].settings.colorDeltaDir < 0)
        flash->palettes[id].colorDelta = -1;
    else
        flash->palettes[id].colorDelta = 1;

    return id;
}

u8 RouletteFlash_Remove(struct RouletteFlashUtil *flash, u8 id)
{
    if (id >= ARRAY_COUNT(flash->palettes))
        return 0xFF;
    if (!flash->palettes[id].available)
        return 0xFF;

    memset(&flash->palettes[id], 0, sizeof(flash->palettes[id]));
    return id;
}

u8 RouletteFlash_FadePalette(struct RouletteFlashPalette *pal)
{
    u8 i;
    u8 returnval;

    for (i = 0; i < pal->settings.numColors; i++)
    {
        struct PlttData *faded =   (struct PlttData *)&gPlttBufferFaded[pal->settings.paletteOffset + i];
        struct PlttData *unfaded = (struct PlttData *)&gPlttBufferUnfaded[pal->settings.paletteOffset + i];

        switch (pal->state)
        {
        case 1:
            // Fade color
            if (faded->r + pal->colorDelta >= 0 && faded->r + pal->colorDelta < 32)
                faded->r += pal->colorDelta;
            if (faded->g + pal->colorDelta >= 0 && faded->g + pal->colorDelta < 32)
                faded->g += pal->colorDelta;
            if (faded->b + pal->colorDelta >= 0 && faded->b + pal->colorDelta < 32)
                faded->b += pal->colorDelta;
            break;
        case 2:
            // Fade back to original color
            if (pal->colorDelta < 0)
            {
                if (faded->r + pal->colorDelta >= unfaded->r)
                    faded->r += pal->colorDelta;
                if (faded->g + pal->colorDelta >= unfaded->g)
                    faded->g += pal->colorDelta;
                if (faded->b + pal->colorDelta >= unfaded->b)
                    faded->b += pal->colorDelta;
            }
            else
            {
                if (faded->r + pal->colorDelta <= unfaded->r)
                    faded->r += pal->colorDelta;
                if (faded->g + pal->colorDelta <= unfaded->g)
                    faded->g += pal->colorDelta;
                if (faded->b + pal->colorDelta <= unfaded->b)
                    faded->b += pal->colorDelta;
            }
            break;
        }
    }
    if ((u32)pal->fadeCycleCounter++ != pal->settings.numFadeCycles)
    {
        returnval = 0;
    }
    else
    {
        pal->fadeCycleCounter = 0;
        pal->colorDelta *= -1;
        if (pal->state == 1)
            pal->state++;
        else
            pal->state--;
        returnval = 1;
    }
    return returnval;
}

u8 RouletteFlash_FlashPalette(struct RouletteFlashPalette *pal)
{
    u8 i = 0;
    switch (pal->state)
    {
    case 1:
        // Flash to color
        for (; i < pal->settings.numColors; i++)
            gPlttBufferFaded[pal->settings.paletteOffset + i] = pal->settings.color;
        pal->state++;
        break;
    case 2:
        // Restore to original color
        for (; i < pal->settings.numColors; i++)
            gPlttBufferFaded[pal->settings.paletteOffset + i] = gPlttBufferUnfaded[pal->settings.paletteOffset + i];
        pal->state--;
        break;
    }
    return 1;
}
