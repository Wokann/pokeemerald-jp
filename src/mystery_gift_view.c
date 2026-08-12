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
    u8 stampShadowSpriteIds[MAX_STAMP_CARD_STAMPS]; // 0x0D5
    u8 stampMonSpriteIds[MAX_STAMP_CARD_STAMPS]; // 0x0DC
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

extern void sub_0801BCA4(u8 whichWindow); // DrawCardWindow (still in asm)
extern void sub_0801C04C(void); // CreateCardSprites (still in asm)
extern void sub_0801C17C(void); // DestroyCardSprites (still in asm)
extern void sub_0801CA6C(void); // UpdateNewsScroll (still in asm)
#define DrawCardWindow sub_0801BCA4
#define CreateCardSprites sub_0801C04C
#define DestroyCardSprites sub_0801C17C



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
