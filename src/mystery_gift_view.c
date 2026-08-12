#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "malloc.h"
#include "menu.h"
#include "palette.h"
#include "pokemon_icon.h"
#include "string_util.h"
#include "text.h"
#include "text_window.h"
#include "mystery_gift.h"
#include "mystery_gift_menu.h"
#include "constants/mystery_gift.h"

#define TAG_STAMP_SHADOW 0x8000

struct WonderGfx
{
    u8 titleTextPal:4;
    u8 bodyTextPal:4;
    u8 footerTextPal:4;
    u8 stampShadowPal:4;
    const u32 *tiles;
    const u32 *map;
    const u16 *pal;
};

enum {
    CARD_WIN_HEADER,
    CARD_WIN_BODY,
    CARD_WIN_FOOTER,
    CARD_WIN_COUNT
};

struct CardStatTextData
{
    u8 width; // 0x00
    u8 nameText[0x15]; // 0x01
    u8 statText[4]; // 0x16
    u8 pad[2]; // 0x1A
};

struct WonderCardData
{
    struct WonderCard card; // 0x000
    struct WonderCardMetadata cardMetadata; // 0x0A4
    const struct WonderGfx *gfx; // 0x0C8
    u8 enterExitState; // 0x0CC
    u8 statDisplayIndex; // 0x0CD
    u16 windowIds[CARD_WIN_COUNT]; // 0x0CE
    u8 monIconSpriteId; // 0x0D4
    u8 stampSpriteIds[MAX_STAMP_CARD_STAMPS][2]; // 0x0D5: [i][0] shadow, [i][1] mon
    u8 titleText[WONDER_CARD_TITLE_LENGTH + 1]; // 0x0E3
    u8 subtitleText[WONDER_CARD_SUBTITLE_LENGTH + 1]; // 0x0F6
    u8 idNumberText[7]; // 0x104
    u8 bodyText[WONDER_CARD_BODY_TEXT_LINES][WONDER_CARD_BODY_LENGTH + 1]; // 0x10B
    u8 footerLine1Text[WONDER_CARD_FOOTER_LENGTH + 1]; // 0x15F
    u8 footerLine2Text[WONDER_CARD_FOOTER_LENGTH + 1]; // 0x174
    u8 padding[3]; // 0x189
    struct CardStatTextData statTextData[8]; // 0x18C
    u8 bgTilemapBuffer[0x1000]; // 0x26C
};

struct WonderNewsData
{
    struct WonderNews news; // 0x000
    const struct WonderGfx *gfx; // 0x0E0
    u8 arrowsRemoved:1; // 0x0E4 bit 0
    u8 enterExitState:7; // 0x0E4 bits 1-7
    u8 arrowTaskId; // 0x0E5
    bool8 scrolling:1; // 0x0E6 bit 0
    u8 scrollIncrement:7; // 0x0E6 bits 1-7
    bool8 scrollingDown:1; // 0x0E7 bit 0
    u8 scrollTotal:7; // 0x0E7 bits 1-7
    u16 scrollEnd; // 0x0E8
    u16 scrollOffset; // 0x0EA
    u16 windowIds[2]; // 0x0EC
    u16 unk_F0; // 0x0F0
    u8 titleText[WONDER_NEWS_TEXT_LENGTH + 1]; // 0x0F2
    u8 bodyText[WONDER_NEWS_BODY_TEXT_LINES][WONDER_NEWS_TEXT_LENGTH + 1]; // 0x107
    u8 unk_1D9[3]; // 0x1D9
    u8 unk_1DC[8]; // 0x1DC (scroll arrow template data)
    u16 unk_1E4; // 0x1E4 (body line count beyond 7)
    u8 unk_1E6[6]; // 0x1E6
    u8 bgTilemapBuffer[0x1000]; // 0x1EC
};

extern EWRAM_DATA struct WonderCardData *gWonderCardData; // 0x02022928
extern EWRAM_DATA struct WonderNewsData *gWonderNewsData; // 0x0202292C
extern const struct WonderGfx gUnknown_82C428C[]; // card gfx table
extern const struct WonderGfx gUnknown_82C49F4[]; // news gfx table
extern const u8 gUnknown_82C4324[]; // news scroll arrow template data
extern const u8 gUnknown_82C333C[]; // card text color table (3-byte entries)
extern const u8 gUnknown_82C3344[]; // card footer text offsets
extern const struct WindowTemplate gUnknown_82C3348[]; // card window templates
extern const struct CompressedSpriteSheet gUnknown_82C422C; // stamp shadow compressed sheet
extern const struct SpritePalette gUnknown_82C4234[]; // stamp shadow palettes
extern const struct SpriteTemplate gUnknown_82C4274; // stamp shadow template
extern const u8 gUnknown_82C430C[]; // news text color table (3-byte entries)
extern const struct WindowTemplate gUnknown_82C4314[]; // news window templates
extern const struct OamData gUnknown_84FD040;

extern void sub_0801CA6C(void); // UpdateNewsScroll (still in asm)
extern void sub_0801C8B4(void); // BufferNewsText (still in asm)
extern void sub_0801C95C(void); // DrawNewsWindows (still in asm)



bool32 InitWonderCardResources(struct WonderCard *card, struct WonderCardMetadata *metadata)
{
    if (card == NULL || metadata == NULL)
        return FALSE;
    gWonderCardData = AllocZeroed(sizeof(*gWonderCardData));
    if (gWonderCardData == NULL)
        return FALSE;
    memcpy(&gWonderCardData->card, card, sizeof(struct WonderCard));
    gWonderCardData->cardMetadata = *metadata;
    if (gWonderCardData->card.bgType >= NUM_WONDER_BGS)
        gWonderCardData->card.bgType = 0;
    if (gWonderCardData->card.type >= CARD_TYPE_COUNT)
        gWonderCardData->card.type = 0;
    if (gWonderCardData->card.maxStamps > MAX_STAMP_CARD_STAMPS)
        gWonderCardData->card.maxStamps = 0;
    gWonderCardData->gfx = &gUnknown_82C428C[gWonderCardData->card.bgType];
    return TRUE;
}

void DestroyWonderCardResources(void)
{
    if (gWonderCardData != NULL)
    {
        memset(gWonderCardData, 0, sizeof(*gWonderCardData));
        Free(gWonderCardData);
        gWonderCardData = NULL;
    }
}

static void BufferCardText(void)
{
    u16 i = 0;
    u16 charsUntilStat;
    u16 stats[3] = {0, 0, 0};

    memcpy(gWonderCardData->titleText, gWonderCardData->card.titleText, WONDER_CARD_TITLE_LENGTH);
    gWonderCardData->titleText[WONDER_CARD_TITLE_LENGTH] = EOS;
    memcpy(gWonderCardData->subtitleText, gWonderCardData->card.subtitleText, WONDER_CARD_SUBTITLE_LENGTH);
    gWonderCardData->subtitleText[WONDER_CARD_SUBTITLE_LENGTH] = EOS;

    if (gWonderCardData->card.idNumber > 999999)
        gWonderCardData->card.idNumber = 999999;
    ConvertIntToDecimalStringN(gWonderCardData->idNumberText, gWonderCardData->card.idNumber, STR_CONV_MODE_LEFT_ALIGN, 6);

    for (i = 0; i < WONDER_CARD_BODY_TEXT_LINES; i++)
    {
        memcpy(gWonderCardData->bodyText[i], gWonderCardData->card.bodyText[i], WONDER_CARD_BODY_LENGTH);
        gWonderCardData->bodyText[i][WONDER_CARD_BODY_LENGTH] = EOS;
    }

    memcpy(gWonderCardData->footerLine1Text, gWonderCardData->card.footerLine1Text, WONDER_CARD_FOOTER_LENGTH);
    gWonderCardData->footerLine1Text[WONDER_CARD_FOOTER_LENGTH] = EOS;

    switch (gWonderCardData->card.type)
    {
    case CARD_TYPE_GIFT:
        memcpy(gWonderCardData->footerLine2Text, gWonderCardData->card.footerLine2Text, WONDER_CARD_FOOTER_LENGTH);
        gWonderCardData->footerLine2Text[WONDER_CARD_FOOTER_LENGTH] |= EOS;
        break;
    case CARD_TYPE_STAMP:
        gWonderCardData->footerLine2Text[0] |= EOS;
        break;
    case CARD_TYPE_LINK_STAT:
        gWonderCardData->footerLine2Text[0] |= EOS;
        stats[0] = gWonderCardData->cardMetadata.battlesWon < MAX_WONDER_CARD_STAT ? gWonderCardData->cardMetadata.battlesWon : MAX_WONDER_CARD_STAT;
        stats[1] = gWonderCardData->cardMetadata.battlesLost < MAX_WONDER_CARD_STAT ? gWonderCardData->cardMetadata.battlesLost : MAX_WONDER_CARD_STAT;
        stats[2] = gWonderCardData->cardMetadata.numTrades < MAX_WONDER_CARD_STAT ? gWonderCardData->cardMetadata.numTrades : MAX_WONDER_CARD_STAT;

        for (i = 0; i < ARRAY_COUNT(gWonderCardData->statTextData); i++)
        {
            memset(gWonderCardData->statTextData[i].statText, EOS, sizeof(gWonderCardData->statTextData[i].statText));
            memset(gWonderCardData->statTextData[i].nameText, EOS, sizeof(gWonderCardData->statTextData[i].nameText));
        }

        for (i = 0, charsUntilStat = 0; i < WONDER_CARD_FOOTER_LENGTH; i++)
        {
            if (gWonderCardData->card.footerLine2Text[i] != CHAR_DYNAMIC)
            {
                gWonderCardData->statTextData[gWonderCardData->statDisplayIndex].nameText[charsUntilStat] = gWonderCardData->card.footerLine2Text[i];
                charsUntilStat++;
            }
            else
            {
                u8 id = gWonderCardData->card.footerLine2Text[i + 1];
                if (id >= ARRAY_COUNT(stats))
                {
                    i += 2;
                }
                else
                {
                    ConvertIntToDecimalStringN(gWonderCardData->statTextData[gWonderCardData->statDisplayIndex].statText, stats[id], STR_CONV_MODE_LEADING_ZEROS, 3);
                    gWonderCardData->statTextData[gWonderCardData->statDisplayIndex].width = gWonderCardData->card.footerLine2Text[i + 2];
                    if (gWonderCardData->statTextData[gWonderCardData->statDisplayIndex].width
                        > GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_LETTER_SPACING) + GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_MAX_LETTER_WIDTH))
                        gWonderCardData->statTextData[gWonderCardData->statDisplayIndex].width
                            = GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_LETTER_SPACING) + GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_MAX_LETTER_WIDTH);
                    gWonderCardData->statDisplayIndex++;
                    if (gWonderCardData->statDisplayIndex > ARRAY_COUNT(gWonderCardData->statTextData) - 1)
                        break;
                    charsUntilStat = 0;
                    i += 2;
                }
            }
        }
        break;
    }
}

static void DrawCardWindow(u8 whichWindow)
{
    s8 i = 0;
    s32 windowId = gWonderCardData->windowIds[whichWindow];

    PutWindowTilemap(windowId);
    FillWindowPixelBuffer(windowId, 0);

    switch (whichWindow)
    {
    case CARD_WIN_HEADER:
    {
        u8 x;

        AddTextPrinterParameterized3(windowId, FONT_SHORT_COPY_1, 0, 1, &gUnknown_82C333C[gWonderCardData->gfx->titleTextPal * 3], i, gWonderCardData->titleText);
        x = (u8)(WONDER_CARD_SUBTITLE_LENGTH * ((u8)GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_LETTER_SPACING) + (u8)GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_MAX_LETTER_WIDTH))
               - StringLength(gWonderCardData->subtitleText) * ((u8)GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_LETTER_SPACING) + (u8)GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_MAX_LETTER_WIDTH)));
        AddTextPrinterParameterized3(windowId, FONT_SHORT_COPY_1, x, 0x11, &gUnknown_82C333C[gWonderCardData->gfx->titleTextPal * 3], i, gWonderCardData->subtitleText);

        if (gWonderCardData->card.idNumber != 0)
        {
            x = (u8)(((u8)GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_LETTER_SPACING) + (u8)GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_MAX_LETTER_WIDTH)) * WONDER_CARD_SUBTITLE_LENGTH + 6);
            AddTextPrinterParameterized3(windowId, FONT_SMALL, x, 0x11, &gUnknown_82C333C[gWonderCardData->gfx->titleTextPal * 3], i, gWonderCardData->idNumberText);
        }
        break;
    }
    case CARD_WIN_BODY:
        for (; i < WONDER_CARD_BODY_TEXT_LINES; i++)
            AddTextPrinterParameterized3(windowId, FONT_SHORT_COPY_1, 2, (u8)(i * 16 + 2), &gUnknown_82C333C[gWonderCardData->gfx->bodyTextPal * 3], 0, gWonderCardData->bodyText[i]);
        break;
    case CARD_WIN_FOOTER:
        AddTextPrinterParameterized3(windowId, FONT_SHORT_COPY_1, 2, gUnknown_82C3344[gWonderCardData->card.type], &gUnknown_82C333C[gWonderCardData->gfx->footerTextPal * 3], i, gWonderCardData->footerLine1Text);
        if (gWonderCardData->card.type != CARD_TYPE_LINK_STAT)
        {
            AddTextPrinterParameterized3(windowId, FONT_SHORT_COPY_1, 2, gUnknown_82C3344[gWonderCardData->card.type] + 0x10, &gUnknown_82C333C[gWonderCardData->gfx->footerTextPal * 3], i, gWonderCardData->footerLine2Text);
        }
        else
        {
            u16 x = 0xDE;
            s32 xMinusGap;

            for (i = gWonderCardData->statDisplayIndex; i >= 0; i--)
            {
                if (gWonderCardData->statTextData[i].statText[0] != EOS)
                {
                    xMinusGap = x - 0x18;
                    x = xMinusGap - gWonderCardData->statTextData[i].width;
                    AddTextPrinterParameterized3(windowId, FONT_SMALL, (u8)x, gUnknown_82C3344[gWonderCardData->card.type] + 0x10, &gUnknown_82C333C[gWonderCardData->gfx->footerTextPal * 3], 0, gWonderCardData->statTextData[i].statText);
                }
                x = x - (StringLength(gWonderCardData->statTextData[i].nameText) * ((u8)GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_LETTER_SPACING) + (u8)GetFontAttribute(FONT_SHORT_COPY_1, FONTATTR_MAX_LETTER_WIDTH)));
                AddTextPrinterParameterized3(windowId, FONT_SHORT_COPY_1, (u8)x, gUnknown_82C3344[gWonderCardData->card.type] + 0x10, &gUnknown_82C333C[gWonderCardData->gfx->footerTextPal * 3], 0, gWonderCardData->statTextData[i].nameText);
            }
        }
        break;
    }

    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void CreateCardSprites(void)
{
    u8 i = 0;

    gWonderCardData->monIconSpriteId = SPRITE_NONE;

    if (gWonderCardData->cardMetadata.iconSpecies != SPECIES_NONE)
    {
        gWonderCardData->monIconSpriteId = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(gWonderCardData->cardMetadata.iconSpecies), SpriteCallbackDummy, 0xDC, 0x14, 0, 0);
        {
            struct Sprite *sprite;
            s32 byteVal;
            s32 oamAttr;
            u32 spriteBase = (u32)gSprites;
            sprite = (struct Sprite *)(spriteBase + gWonderCardData->monIconSpriteId * 0x44);
            byteVal = ((u8 *)&sprite->oam)[5];
            oamAttr = ~0xC;
            oamAttr &= byteVal;
            ((u8 *)&sprite->oam)[5] = oamAttr | 8;
        }
    }

    if (gWonderCardData->card.maxStamps != 0 && gWonderCardData->card.type == CARD_TYPE_STAMP)
    {
        LoadCompressedSpriteSheetUsingHeap(&gUnknown_82C422C);
        LoadSpritePalette(&gUnknown_82C4234[gWonderCardData->gfx->stampShadowPal]);
        for (; i < gWonderCardData->card.maxStamps; i++)
        {
            gWonderCardData->stampSpriteIds[i][0] |= SPRITE_NONE;
            gWonderCardData->stampSpriteIds[i][1] |= SPRITE_NONE;
            gWonderCardData->stampSpriteIds[i][0] = CreateSprite(&gUnknown_82C4274, 0xD8 - 0x20 * i, 0x90, 8);
            if (gWonderCardData->cardMetadata.stampData[STAMP_SPECIES][i] != SPECIES_NONE)
                gWonderCardData->stampSpriteIds[i][1] = CreateMonIconNoPersonality(GetIconSpeciesNoPersonality(gWonderCardData->cardMetadata.stampData[STAMP_SPECIES][i]), SpriteCallbackDummy, 0xD8 - 0x20 * i, 0x88, 0, 0);
        }
    }
}

static void DestroyCardSprites(void)
{
    u8 i = 0;

    if (gWonderCardData->monIconSpriteId != SPRITE_NONE)
        FreeAndDestroyMonIconSprite(&gSprites[gWonderCardData->monIconSpriteId]);

    if (gWonderCardData->card.maxStamps != 0 && gWonderCardData->card.type == CARD_TYPE_STAMP)
    {
        for (; i < gWonderCardData->card.maxStamps; i++)
        {
            if (gWonderCardData->stampSpriteIds[i][0] != SPRITE_NONE)
            {
                DestroySprite(&gSprites[gWonderCardData->stampSpriteIds[i][0]]);
                if (gWonderCardData->stampSpriteIds[i][0] != SPRITE_NONE)
                    FreeAndDestroyMonIconSprite(&gSprites[gWonderCardData->stampSpriteIds[i][1]]);
            }
        }
        FreeSpriteTilesByTag(TAG_STAMP_SHADOW);
        FreeSpritePaletteByTag(TAG_STAMP_SHADOW);
    }
}

bool32 InitWonderNewsResources(struct WonderNews *news)
{
    if (news == NULL)
        return FALSE;
    gWonderNewsData = AllocZeroed(sizeof(*gWonderNewsData));
    if (gWonderNewsData == NULL)
        return FALSE;
    memcpy(gWonderNewsData, news, sizeof(struct WonderNews));
    if (gWonderNewsData->news.bgType >= NUM_WONDER_BGS)
        gWonderNewsData->news.bgType = 0;
    gWonderNewsData->gfx = &gUnknown_82C49F4[gWonderNewsData->news.bgType];
    gWonderNewsData->arrowTaskId = TASK_NONE;
    return TRUE;
}

void DestroyWonderNewsResources(void)
{
    if (gWonderNewsData != NULL)
    {
        memset(gWonderNewsData, 0, sizeof(*gWonderNewsData));
        Free(gWonderNewsData);
        gWonderNewsData = NULL;
    }
}

s32 FadeToWonderNewsMenu(void)
{
    if (gWonderNewsData == NULL)
        return -1;

    switch (gWonderNewsData->enterExitState)
    {
    case 0:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        break;
    case 1:
        if (UpdatePaletteFade() != 0)
            return 0;
        ChangeBgY(0, 0, 0);
        ChangeBgY(1, 0, 0);
        ChangeBgY(2, 0, 0);
        ChangeBgY(3, 0, 0);
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(28, 152));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x1E, 0x14);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        DecompressAndCopyTileDataToVram(3, gWonderNewsData->gfx->tiles, 0, 8, 0);
        gWonderNewsData->windowIds[0] = AddWindow(&gUnknown_82C4314[0]);
        gWonderNewsData->windowIds[1] = AddWindow(&gUnknown_82C4314[1]);
        break;
    case 3:
        if (FreeTempTileDataBuffersIfPossible() != 0)
            return 0;
        LoadPalette(GetTextWindowPalette(1), 0x20, 0x20);
        gPaletteFade.bufferTransferDisabled = TRUE;
        LoadPalette(gWonderNewsData->gfx->pal, 0x10, 0x20);
        LZ77UnCompWram(gWonderNewsData->gfx->map, gWonderNewsData->bgTilemapBuffer);
        CopyRectToBgTilemapBufferRect(1, gWonderNewsData->bgTilemapBuffer, 0, 0, 0x1E, 3, 0, 0, 0x1E, 3, 1, 8, 0);
        CopyRectToBgTilemapBufferRect(3, gWonderNewsData->bgTilemapBuffer, 0, 3, 0x1E, 0x17, 0, 3, 0x1E, 0x17, 1, 8, 0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(3);
        break;
    case 4:
        sub_0801C8B4();
        break;
    case 5:
        sub_0801C95C();
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(2);
        break;
    case 6:
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        gPaletteFade.bufferTransferDisabled = FALSE;
        gWonderNewsData->arrowTaskId = AddScrollIndicatorArrowPair((const struct ScrollArrowsTemplate *)&gWonderNewsData->unk_1DC, &gWonderNewsData->scrollOffset);
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        UpdatePaletteFade();
        break;
    default:
        if (UpdatePaletteFade() == 0)
        {
            gWonderNewsData->enterExitState = 0;
            return 1;
        }
        return 0;
    }

    gWonderNewsData->enterExitState++;
    return 0;
}

s32 FadeOutFromWonderNews(void)
{
    if (gWonderNewsData == NULL)
        return -1;

    switch (gWonderNewsData->enterExitState)
    {
    case 0:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        break;
    case 1:
        if (UpdatePaletteFade() != 0)
            return 0;
        ChangeBgY(2, 0, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x1E, 0x18);
        FillBgTilemapBufferRect_Palette0(3, 0, 0, 0, 0x1E, 0x18);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        CopyBgTilemapBufferToVram(3);
        break;
    case 3:
        HideBg(1);
        HideBg(2);
        RemoveWindow(gWonderNewsData->windowIds[1]);
        RemoveWindow(gWonderNewsData->windowIds[0]);
        break;
    case 4:
        ChangeBgY(2, 0, 0);
        ChangeBgY(3, 0, 0);
        if (gWonderNewsData->arrowTaskId != SPRITE_NONE)
        {
            RemoveScrollIndicatorArrowPair(gWonderNewsData->arrowTaskId);
            gWonderNewsData->arrowTaskId = SPRITE_NONE;
        }
        break;
    case 5:
        PrintMysteryGiftOrEReaderTopMenu(gGiftIsFromEReader);
        MG_DrawCheckerboardPattern(3);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(3);
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        break;
    default:
        if (UpdatePaletteFade() == 0)
        {
            gWonderNewsData->enterExitState = 0;
            return 1;
        }
        return 0;
    }

    gWonderNewsData->enterExitState++;
    return 0;
}

void WonderNews_RemoveScrollIndicatorArrowPair(void)
{
    if (!gWonderNewsData->arrowsRemoved && gWonderNewsData->arrowTaskId != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(gWonderNewsData->arrowTaskId);
        gWonderNewsData->arrowTaskId = 0xFF;
        gWonderNewsData->arrowsRemoved = TRUE;
    }
}

void WonderNews_AddScrollIndicatorArrowPair(void)
{
    if (gWonderNewsData->arrowsRemoved)
    {
        gWonderNewsData->arrowTaskId = AddScrollIndicatorArrowPair((const struct ScrollArrowsTemplate *)&gWonderNewsData->unk_1DC, &gWonderNewsData->scrollOffset);
        gWonderNewsData->arrowsRemoved = FALSE;
    }
}

u32 WonderNews_GetInput(u16 input)
{
    if (gWonderNewsData->scrolling)
    {
        sub_0801CA6C();
        return 0xFF;
    }

    switch (input)
    {
    case 1:
        return 0;
    case 2:
        return 1;
    case 0x40:
        if (gWonderNewsData->scrollOffset == 0 || gWonderNewsData->arrowsRemoved)
            return 0xFF;
        gWonderNewsData->scrollingDown = FALSE;
        break;
    case 0x80:
        if (gWonderNewsData->scrollOffset == gWonderNewsData->scrollEnd || gWonderNewsData->arrowsRemoved)
            return 0xFF;
        gWonderNewsData->scrollingDown = TRUE;
        break;
    default:
        return 0xFF;
    }

    gWonderNewsData->scrolling = TRUE;
    gWonderNewsData->scrollIncrement = 2;
    gWonderNewsData->scrollTotal = 0;
    if (!gWonderNewsData->scrollingDown)
        return 2;
    return 3;
}

s32 FadeToWonderCardMenu(void)
{
    if (gWonderCardData == NULL)
        return -1;

    switch (gWonderCardData->enterExitState)
    {
    case 0:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        break;
    case 1:
        if (UpdatePaletteFade() == 0)
            break;
        return 0;
    case 2:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x1E, 0x14);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        DecompressAndCopyTileDataToVram(2, gWonderCardData->gfx->tiles, 0, 8, 0);
        gWonderCardData->windowIds[0] = AddWindow(&gUnknown_82C3348[0]);
        gWonderCardData->windowIds[1] = AddWindow(&gUnknown_82C3348[1]);
        gWonderCardData->windowIds[2] = AddWindow(&gUnknown_82C3348[2]);
        break;
    case 3:
        if (FreeTempTileDataBuffersIfPossible() != 0)
            return 0;
        LoadPalette(GetTextWindowPalette(1), 0x20, 0x20);
        gPaletteFade.bufferTransferDisabled = TRUE;
        LoadPalette(gWonderCardData->gfx->pal, 0x10, 0x20);
        LZ77UnCompWram(gWonderCardData->gfx->map, gWonderCardData->bgTilemapBuffer);
        CopyRectToBgTilemapBufferRect(2, gWonderCardData->bgTilemapBuffer, 0, 0, 0x1E, 0x14, 0, 0, 0x1E, 0x14, 1, 8, 0);
        CopyBgTilemapBufferToVram(2);
        break;
    case 4:
        BufferCardText();
        break;
    case 5:
        DrawCardWindow(0);
        DrawCardWindow(1);
        DrawCardWindow(2);
        CopyBgTilemapBufferToVram(1);
        break;
    case 6:
        LoadMonIconPalettes();
        break;
    case 7:
        ShowBg(1);
        ShowBg(2);
        gPaletteFade.bufferTransferDisabled = FALSE;
        CreateCardSprites();
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        UpdatePaletteFade();
        break;
    default:
        if (UpdatePaletteFade() == 0)
        {
            gWonderCardData->enterExitState = 0;
            return 1;
        }
        return 0;
    }

    gWonderCardData->enterExitState++;
    return 0;
}

s32 FadeOutFromWonderCard(bool32 useCancel)
{
    if (gWonderCardData == NULL)
        return -1;

    switch (gWonderCardData->enterExitState)
    {
    case 0:
        BeginNormalPaletteFade(-1, 0, 0, 0x10, 0);
        break;
    case 1:
        if (UpdatePaletteFade() != 0)
            return 0;
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 0, 0x1E, 0x14);
        FillBgTilemapBufferRect_Palette0(2, 0, 0, 0, 0x1E, 0x14);
        CopyBgTilemapBufferToVram(0);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        break;
    case 3:
        HideBg(1);
        HideBg(2);
        RemoveWindow(gWonderCardData->windowIds[2]);
        RemoveWindow(gWonderCardData->windowIds[1]);
        RemoveWindow(gWonderCardData->windowIds[0]);
        break;
    case 4:
        DestroyCardSprites();
        FreeMonIconPalettes();
        break;
    case 5:
        PrintMysteryGiftOrEReaderTopMenu(gGiftIsFromEReader);
        CopyBgTilemapBufferToVram(0);
        BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
        break;
    default:
        if (UpdatePaletteFade() == 0)
        {
            gWonderCardData->enterExitState = 0;
            return 1;
        }
        return 0;
    }

    gWonderCardData->enterExitState++;
    return 0;
}
