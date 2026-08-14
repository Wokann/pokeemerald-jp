#include "global.h"
#include "mail.h"
#include "constants/items.h"
#include "overworld.h"
#include "task.h"
#include "scanline_effect.h"
#include "palette.h"
#include "text.h"
#include "menu.h"
#include "menu_helpers.h"
#include "text_window.h"
#include "string_util.h"
#include "international_string_util.h"
#include "strings.h"
#include "gpu_regs.h"
#include "bg.h"
#include "pokemon_icon.h"
#include "malloc.h"
#include "easy_chat.h"
#include "graphics.h"
#include "constants/rgb.h"

// Bead and Dream mail feature an icon of the PokÃ©mon holding it.
enum {
    ICON_TYPE_NONE,
    ICON_TYPE_BEAD,
    ICON_TYPE_DREAM,
};

// JP note: the JP struct MailRead differs from US pokeemerald. The JP
// message lines are 24 bytes each (8 lines), the EWRAM layout puts the
// bg tilemap buffers at 0xEC/0x10EC and the whole struct is 0x20EC bytes.
struct MailRead
{
    /*0x000*/ u8 message[8][24];
    /*0x0C0*/ u8 playerName[12];
    /*0x0CC*/ MainCallback exitCallback;
    /*0x0D0*/ MainCallback callback;
    /*0x0D4*/ struct Mail *mail;
    /*0x0D8*/ bool8 hasText;
    /*0x0D9*/ u8 signatureWidth;
    /*0x0DA*/ u8 mailType;
    /*0x0DB*/ u8 iconType;
    /*0x0DC*/ u8 monIconSpriteId;
    /*0x0DD*/ u8 international;
    /*0x0DE*/ u8 language;
    /*0x0DF*/ u8 unused;
    /*0x0E0*/ u8 * (*parserSingle)(u8 *dest, u16 word);
    /*0x0E4*/ u8 * (*parserMultiple)(u8 *dest, const u16 *src, u16 length1, u16 length2);
    /*0x0E8*/ const struct MailLayout *layout;
    /*0x0EC*/ u8 bg1TilemapBuffer[0x1000];
    /*0x10EC*/ u8 bg2TilemapBuffer[0x1000];
};

// JP note: struct MailLayout is 8 bytes and packs signatureYPos into the
// low nibble of byte 1 and signatureWidth into the high nibble. Each
// MailLineLayout entry is 4 bytes (the JP ROM pads it).
struct MailLineLayout
{
    u8 numEasyChatWords:2;
    u8 xOffset:6;
    u8 height;
    u8 unused[2];
};

struct MailLayout
{
    u8 numLines;
    u8 signatureYPos:4;
    u8 signatureWidth:4;
    u8 wordsYPos;
    u8 wordsXPos;
    const struct MailLineLayout *lines;
};

struct MailGraphics
{
    const u16 *palette;
    const u32 *tiles;
    const u32 *tileMap;
    u32 unused;
    u16 textColor;
    u16 textShadow;
};

// JP note: EWRAM pointer and all static tables live in the JP ROM data
// region; they are bound via ld aliases in ld_script_jp.txt.
extern struct MailRead *sMailRead;
extern const struct BgTemplate sMailBgTemplates[];
extern const struct WindowTemplate sMailWindowTemplates[];
extern const u8 sMailTextColors[];
extern const u16 sMailBgColors[][2];
extern const struct MailGraphics sMailGraphics[];
extern const struct MailLayout sMailLayouts_Wide[];
extern const struct MailLayout sMailLayouts_Tall[];
extern const u8 sMailFromText[];

static void CB2_InitMailRead(void);
static void BufferMailText(void);
static void PrintMailText(void);
static void VBlankCB_MailRead(void);
static void CB2_MailRead(void);
static void CB2_WaitForPaletteExitOnKeyPress(void);
static void CB2_ExitOnKeyPress(void);
static void CB2_ExitMailReadFreeVars(void);

void ReadMail(struct Mail *mail, MainCallback exitCallback, bool8 hasText)
{
    u16 buffer[2];
    u16 species;

    sMailRead = AllocZeroed(sizeof(*sMailRead));
    sMailRead->international = TRUE;
    sMailRead->language = 0; // JP: Japanese (GAME_LANGUAGE)
    sMailRead->parserSingle = CopyEasyChatWord;
    sMailRead->parserMultiple = ConvertEasyChatWordsToString;
    if (IS_ITEM_MAIL(mail->itemId))
    {
        sMailRead->mailType = ITEM_TO_MAIL(mail->itemId);
    }
    else
    {
        sMailRead->mailType = ITEM_TO_MAIL(FIRST_MAIL_INDEX);
        hasText = FALSE;
    }
    switch (sMailRead->language)
    {
    case 0:
    default:
        sMailRead->layout = &sMailLayouts_Wide[sMailRead->mailType];
        break;
    case 1:
        sMailRead->layout = &sMailLayouts_Tall[sMailRead->mailType];
        break;
    }
    species = MailSpeciesToSpecies(mail->species, buffer);
    if (species > SPECIES_NONE && species < NUM_SPECIES)
    {
        switch (sMailRead->mailType)
        {
        default:
            sMailRead->iconType = ICON_TYPE_NONE;
            break;
        case ITEM_TO_MAIL(ITEM_BEAD_MAIL):
            sMailRead->iconType = ICON_TYPE_BEAD;
            break;
        case ITEM_TO_MAIL(ITEM_DREAM_MAIL):
            sMailRead->iconType = ICON_TYPE_DREAM;
            break;
        }
    }
    else
    {
        sMailRead->iconType = ICON_TYPE_NONE;
    }
    sMailRead->mail = mail;
    sMailRead->exitCallback = exitCallback;
    sMailRead->hasText = hasText;
    SetMainCallback2(CB2_InitMailRead);
}

static bool8 MailReadBuildGraphics(void)
{
    u16 icon;

    switch (gMain.state)
    {
        case 0:
            SetVBlankCallback(NULL);
            ScanlineEffect_Stop();
            SetGpuReg(REG_OFFSET_DISPCNT, 0);
            break;
        case 1:
            CpuFill16(0, (void *)OAM, OAM_SIZE);
            break;
        case 2:
            ResetPaletteFade();
            break;
        case 3:
            ResetTasks();
            break;
        case 4:
            ResetSpriteData();
            break;
        case 5:
            FreeAllSpritePalettes();
            ResetTempTileDataBuffers();
            SetGpuReg(REG_OFFSET_BG0HOFS, 0);
            SetGpuReg(REG_OFFSET_BG0VOFS, 0);
            SetGpuReg(REG_OFFSET_BG1HOFS, 0);
            SetGpuReg(REG_OFFSET_BG1VOFS, 0);
            SetGpuReg(REG_OFFSET_BG2VOFS, 0);
            SetGpuReg(REG_OFFSET_BG2HOFS, 0);
            SetGpuReg(REG_OFFSET_BG3HOFS, 0);
            SetGpuReg(REG_OFFSET_BG3VOFS, 0);
            SetGpuReg(REG_OFFSET_BLDCNT,  0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            break;
        case 6:
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sMailBgTemplates, 3);
            SetBgTilemapBuffer(1, sMailRead->bg1TilemapBuffer);
            SetBgTilemapBuffer(2, sMailRead->bg2TilemapBuffer);
            break;
        case 7:
            InitWindows(sMailWindowTemplates);
            DeactivateAllTextPrinters();
            break;
        case 8:
            DecompressAndCopyTileDataToVram(1, sMailGraphics[sMailRead->mailType].tiles, 0, 0, 0);
            break;
        case 9:
            if (FreeTempTileDataBuffersIfPossible())
                return FALSE;
            break;
        case 10:
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT);
            FillBgTilemapBufferRect_Palette0(2, 1, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT);
            CopyToBgTilemapBuffer(1, sMailGraphics[sMailRead->mailType].tileMap, 0, 0);
            break;
        case 11:
            CopyBgTilemapBufferToVram(0);
            CopyBgTilemapBufferToVram(1);
            CopyBgTilemapBufferToVram(2);
            break;
        case 12:
            LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
            gPlttBufferUnfaded[BG_PLTT_ID(15) + 10] = sMailGraphics[sMailRead->mailType].textColor;
            gPlttBufferFaded[BG_PLTT_ID(15) + 10] = sMailGraphics[sMailRead->mailType].textColor;
            gPlttBufferUnfaded[BG_PLTT_ID(15) + 11] = sMailGraphics[sMailRead->mailType].textShadow;
            gPlttBufferFaded[BG_PLTT_ID(15) + 11] = sMailGraphics[sMailRead->mailType].textShadow;

            LoadPalette(sMailGraphics[sMailRead->mailType].palette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            gPlttBufferUnfaded[BG_PLTT_ID(0) + 10] = sMailBgColors[gSaveBlock2Ptr->playerGender][0];
            gPlttBufferFaded[BG_PLTT_ID(0) + 10] = sMailBgColors[gSaveBlock2Ptr->playerGender][0];
            gPlttBufferUnfaded[BG_PLTT_ID(0) + 11] = sMailBgColors[gSaveBlock2Ptr->playerGender][1];
            gPlttBufferFaded[BG_PLTT_ID(0) + 11] = sMailBgColors[gSaveBlock2Ptr->playerGender][1];
            break;
        case 13:
            if (sMailRead->hasText)
                BufferMailText();
            break;
        case 14:
            if (sMailRead->hasText)
            {
                PrintMailText();
                RunTextPrinters();
            }
            break;
        case 15:
            if (Overworld_IsRecvQueueAtMax() == TRUE)
                return FALSE;
            break;
        case 16:
            SetVBlankCallback(VBlankCB_MailRead);
            gPaletteFade.bufferTransferDisabled = TRUE;
            break;
        case 17:
            icon = GetIconSpeciesNoPersonality(sMailRead->mail->species);
            switch (sMailRead->iconType)
            {
            case ICON_TYPE_BEAD:
                LoadMonIconPalette(icon);
                sMailRead->monIconSpriteId = CreateMonIconNoPersonality(icon, SpriteCallbackDummy, 96, 128, 0, FALSE);
                break;
            case ICON_TYPE_DREAM:
                LoadMonIconPalette(icon);
                sMailRead->monIconSpriteId = CreateMonIconNoPersonality(icon, SpriteCallbackDummy, 40, 128, 0, FALSE);
                break;
            }
            break;
        case 18:
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            gPaletteFade.bufferTransferDisabled = FALSE;
            sMailRead->callback = CB2_WaitForPaletteExitOnKeyPress;
            return TRUE;
        default:
            return FALSE;
    }
    gMain.state++;
    return FALSE;
}

static void CB2_InitMailRead(void)
{
    do
    {
        if (MailReadBuildGraphics() == TRUE)
        {
            SetMainCallback2(CB2_MailRead);
            break;
        }
    } while (MenuHelpers_IsLinkActive() != TRUE);
}

static void BufferMailText(void)
{
    u16 i;
    u8 numWords;
    u8 *ptr;
    u8 fromText[4];

    // JP "From" text stored as raw 4 bytes in the ROM data region.
    memcpy(fromText, sMailFromText, 4);

    // Convert the easy chat words to strings line by line and buffer them to message
    numWords = 0;
    for (i = 0; i < sMailRead->layout->numLines; i++)
    {
        ConvertEasyChatWordsToString(sMailRead->message[i], &sMailRead->mail->words[numWords], sMailRead->layout->lines[i].numEasyChatWords, 1);
        numWords += sMailRead->layout->lines[i].numEasyChatWords;
    }

    // Buffer the signature
    ptr = StringCopy(sMailRead->playerName, sMailRead->mail->playerName);
    if (!sMailRead->language)
    {
        StringCopy(ptr, fromText);
        sMailRead->signatureWidth = sMailRead->layout->signatureWidth - (StringLength(sMailRead->playerName) * 8 - 96);
    }
    else
    {
        sMailRead->signatureWidth = sMailRead->layout->signatureWidth;
    }
}

static void PrintMailText(void)
{
    u16 i;
    u8 y;

    y = 0;
    PutWindowTilemap(0);
    PutWindowTilemap(1);
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    for (i = 0; i < sMailRead->layout->numLines; i++)
    {
        if (sMailRead->message[i][0] == EOS || sMailRead->message[i][0] == CHAR_SPACE)
            continue;

        AddTextPrinterParameterized3(0, FONT_NORMAL, sMailRead->layout->lines[i].xOffset + sMailRead->layout->wordsXPos, y + sMailRead->layout->wordsYPos, sMailTextColors, 0, sMailRead->message[i]);
        y += sMailRead->layout->lines[i].height;
    }
    // JP prints the signature in window 1 directly from playerName (the
    // "From" text was already appended by BufferMailText).
    AddTextPrinterParameterized3(1, FONT_NORMAL, sMailRead->signatureWidth, sMailRead->layout->signatureYPos, sMailTextColors, 0, sMailRead->playerName);
    CopyWindowToVram(0, COPYWIN_FULL);
    CopyWindowToVram(1, COPYWIN_FULL);
}

static void VBlankCB_MailRead(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_MailRead(void)
{
    if (sMailRead->iconType != ICON_TYPE_NONE)
    {
        AnimateSprites();
        BuildOamBuffer();
    }
    sMailRead->callback();
}

static void CB2_WaitForPaletteExitOnKeyPress(void)
{
    if (!UpdatePaletteFade())
    {
        sMailRead->callback = CB2_ExitOnKeyPress;
    }
}

static void CB2_ExitOnKeyPress(void)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        sMailRead->callback = CB2_ExitMailReadFreeVars;
    }
}

static void CB2_ExitMailReadFreeVars(void)
{
    if (!UpdatePaletteFade())
    {
        SetMainCallback2(sMailRead->exitCallback);
        switch (sMailRead->iconType)
        {
        case ICON_TYPE_BEAD:
        case ICON_TYPE_DREAM:
            FreeMonIconPalette(GetIconSpeciesNoPersonality(sMailRead->mail->species));
            FreeAndDestroyMonIconSprite(&gSprites[sMailRead->monIconSpriteId]);
        }
        memset(sMailRead, 0, sizeof(*sMailRead));
        ResetPaletteFade();
        UnsetBgTilemapBuffer(0);
        UnsetBgTilemapBuffer(1);
        ResetBgsAndClearDma3BusyFlags(0);
        FreeAllWindowBuffers();
        FREE_AND_SET_NULL(sMailRead);
    }
}
