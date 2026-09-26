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

// JP note: the EWRAM pointer is fixed by sym_ewram_jp.txt.
extern struct MailRead *sMailRead;

// JP mail-reader data at 0x0857AEB4-0x0857B0B8. Keep this in a dedicated
// ordered section: the surrounding mid61 raw data and menu-helper data have
// separate physical owners.
#define MAIL_DATA __attribute__((section(".rodata.mail_data"), aligned(1)))

// The JP mail graphics are still raw assets, so retain their verified ROM
// addresses rather than introducing unresolved US-only graphics symbols.
#define MAIL_PALETTE_ORANGE ((const u16 *)0x08DBEAC0)
#define MAIL_TILES_ORANGE   ((const u32 *)0x08DBEC40)
#define MAIL_TILEMAP_ORANGE ((const u32 *)0x08DBFE4C)
#define MAIL_PALETTE_HARBOR ((const u16 *)0x08DBEAE0)
#define MAIL_TILES_HARBOR   ((const u32 *)0x08DBEDE0)
#define MAIL_TILEMAP_HARBOR ((const u32 *)0x08DBFF24)
#define MAIL_PALETTE_GLITTER ((const u16 *)0x08DBEB00)
#define MAIL_TILES_GLITTER   ((const u32 *)0x08DBEF1C)
#define MAIL_TILEMAP_GLITTER ((const u32 *)0x08DC0004)
#define MAIL_PALETTE_MECH ((const u16 *)0x08DBEB20)
#define MAIL_TILES_MECH   ((const u32 *)0x08DBF12C)
#define MAIL_TILEMAP_MECH ((const u32 *)0x08DC0110)
#define MAIL_PALETTE_WOOD ((const u16 *)0x08DBEB40)
#define MAIL_TILES_WOOD   ((const u32 *)0x08DBF204)
#define MAIL_TILEMAP_WOOD ((const u32 *)0x08DC01EC)
#define MAIL_PALETTE_WAVE ((const u16 *)0x08DBEB60)
#define MAIL_TILES_WAVE   ((const u32 *)0x08DBF3FC)
#define MAIL_TILEMAP_WAVE ((const u32 *)0x08DC02DC)
#define MAIL_PALETTE_BEAD ((const u16 *)0x08DBEB80)
#define MAIL_TILES_BEAD   ((const u32 *)0x08DBF57C)
#define MAIL_TILEMAP_BEAD ((const u32 *)0x08DC03BC)
#define MAIL_PALETTE_SHADOW ((const u16 *)0x08DBEBA0)
#define MAIL_TILES_SHADOW   ((const u32 *)0x08DBF624)
#define MAIL_TILEMAP_SHADOW ((const u32 *)0x08DC049C)
#define MAIL_PALETTE_TROPIC ((const u16 *)0x08DBEBC0)
#define MAIL_TILES_TROPIC   ((const u32 *)0x08DBF7B4)
#define MAIL_TILEMAP_TROPIC ((const u32 *)0x08DC05A8)
#define MAIL_PALETTE_DREAM ((const u16 *)0x08DBEBE0)
#define MAIL_TILES_DREAM   ((const u32 *)0x08DBF8F4)
#define MAIL_TILEMAP_DREAM ((const u32 *)0x08DC0698)
#define MAIL_PALETTE_FAB ((const u16 *)0x08DBEC00)
#define MAIL_TILES_FAB   ((const u32 *)0x08DBFA5C)
#define MAIL_TILEMAP_FAB ((const u32 *)0x08DC0790)
#define MAIL_PALETTE_RETRO ((const u16 *)0x08DBEC20)
#define MAIL_TILES_RETRO   ((const u32 *)0x08DBFBAC)
#define MAIL_TILEMAP_RETRO ((const u32 *)0x08DC08A8)

const struct BgTemplate sMailBgTemplates[] MAIL_DATA =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
};

const struct WindowTemplate sMailWindowTemplates[] MAIL_DATA =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 4,
        .width = 24,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 1,
    },
    {
        .bg = 0,
        .tilemapLeft = 15,
        .tilemapTop = 15,
        .width = 13,
        .height = 3,
        .paletteNum = 15,
        .baseBlock = 0xF2,
    },
    DUMMY_WIN_TEMPLATE,
};

// The fourth byte is the original alignment byte before the u16 table.
const u8 sMailTextColors[4] MAIL_DATA = { 0, 10, 11, 0 };

const u16 sMailBgColors[][2] MAIL_DATA =
{
    { 0x6ACD, 0x51A5 },
    { 0x45FC, 0x38D4 },
};

const struct MailGraphics sMailGraphics[] MAIL_DATA =
{
    {
        .palette = MAIL_PALETTE_ORANGE,
        .tiles = MAIL_TILES_ORANGE,
        .tileMap = MAIL_TILEMAP_ORANGE,
        .unused = 0x2C0,
        .textColor = 0x294A,
        .textShadow = 0x6739,
    },
    {
        .palette = MAIL_PALETTE_HARBOR,
        .tiles = MAIL_TILES_HARBOR,
        .tileMap = MAIL_TILEMAP_HARBOR,
        .unused = 0x2E0,
        .textColor = 0x7FFF,
        .textShadow = 0x4631,
    },
    {
        .palette = MAIL_PALETTE_GLITTER,
        .tiles = MAIL_TILES_GLITTER,
        .tileMap = MAIL_TILEMAP_GLITTER,
        .unused = 0x400,
        .textColor = 0x294A,
        .textShadow = 0x6739,
    },
    {
        .palette = MAIL_PALETTE_MECH,
        .tiles = MAIL_TILES_MECH,
        .tileMap = MAIL_TILEMAP_MECH,
        .unused = 0x1E0,
        .textColor = 0x7FFF,
        .textShadow = 0x4631,
    },
    {
        .palette = MAIL_PALETTE_WOOD,
        .tiles = MAIL_TILES_WOOD,
        .tileMap = MAIL_TILEMAP_WOOD,
        .unused = 0x2E0,
        .textColor = 0x7FFF,
        .textShadow = 0x4631,
    },
    {
        .palette = MAIL_PALETTE_WAVE,
        .tiles = MAIL_TILES_WAVE,
        .tileMap = MAIL_TILEMAP_WAVE,
        .unused = 0x300,
        .textColor = 0x294A,
        .textShadow = 0x6739,
    },
    {
        .palette = MAIL_PALETTE_BEAD,
        .tiles = MAIL_TILES_BEAD,
        .tileMap = MAIL_TILEMAP_BEAD,
        .unused = 0x140,
        .textColor = 0x7FFF,
        .textShadow = 0x4631,
    },
    {
        .palette = MAIL_PALETTE_SHADOW,
        .tiles = MAIL_TILES_SHADOW,
        .tileMap = MAIL_TILEMAP_SHADOW,
        .unused = 0x300,
        .textColor = 0x7FFF,
        .textShadow = 0x4631,
    },
    {
        .palette = MAIL_PALETTE_TROPIC,
        .tiles = MAIL_TILES_TROPIC,
        .tileMap = MAIL_TILEMAP_TROPIC,
        .unused = 0x220,
        .textColor = 0x294A,
        .textShadow = 0x6739,
    },
    {
        .palette = MAIL_PALETTE_DREAM,
        .tiles = MAIL_TILES_DREAM,
        .tileMap = MAIL_TILEMAP_DREAM,
        .unused = 0x340,
        .textColor = 0x294A,
        .textShadow = 0x6739,
    },
    {
        .palette = MAIL_PALETTE_FAB,
        .tiles = MAIL_TILES_FAB,
        .tileMap = MAIL_TILEMAP_FAB,
        .unused = 0x2A0,
        .textColor = 0x294A,
        .textShadow = 0x6739,
    },
    {
        .palette = MAIL_PALETTE_RETRO,
        .tiles = MAIL_TILES_RETRO,
        .tileMap = MAIL_TILEMAP_RETRO,
        .unused = 0x520,
        .textColor = 0x294A,
        .textShadow = 0x6739,
    },
};

static const struct MailLineLayout sLineLayouts_Wide[] MAIL_DATA =
{
    { .numEasyChatWords = 3, .xOffset = 0, .height = 16, .unused = { 0, 0 } },
    { .numEasyChatWords = 3, .xOffset = 0, .height = 16, .unused = { 0, 0 } },
    { .numEasyChatWords = 3, .xOffset = 0, .height = 16, .unused = { 0, 0 } },
};

const struct MailLayout sMailLayouts_Wide[] MAIL_DATA =
{
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 8, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 4, .lines = sLineLayouts_Wide },
    { .numLines = 3, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Wide },
};

static const struct MailLineLayout sLineLayouts_Tall[] MAIL_DATA =
{
    { .numEasyChatWords = 2, .xOffset = 0, .height = 16, .unused = { 0, 0 } },
    { .numEasyChatWords = 2, .xOffset = 0, .height = 16, .unused = { 0, 0 } },
    { .numEasyChatWords = 2, .xOffset = 0, .height = 16, .unused = { 0, 0 } },
    { .numEasyChatWords = 2, .xOffset = 0, .height = 16, .unused = { 0, 0 } },
    { .numEasyChatWords = 1, .xOffset = 0, .height = 16, .unused = { 0, 0 } },
};

const struct MailLayout sMailLayouts_Tall[] MAIL_DATA =
{
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 8, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 8, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 8, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 8, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
    { .numLines = 5, .signatureYPos = 0, .signatureWidth = 0, .wordsYPos = 2, .wordsXPos = 0, .lines = sLineLayouts_Tall },
};

const u8 sMailFromText[] MAIL_DATA = { 0x00, 0x26, 0x28, 0xFF };

#undef MAIL_PALETTE_ORANGE
#undef MAIL_TILES_ORANGE
#undef MAIL_TILEMAP_ORANGE
#undef MAIL_PALETTE_HARBOR
#undef MAIL_TILES_HARBOR
#undef MAIL_TILEMAP_HARBOR
#undef MAIL_PALETTE_GLITTER
#undef MAIL_TILES_GLITTER
#undef MAIL_TILEMAP_GLITTER
#undef MAIL_PALETTE_MECH
#undef MAIL_TILES_MECH
#undef MAIL_TILEMAP_MECH
#undef MAIL_PALETTE_WOOD
#undef MAIL_TILES_WOOD
#undef MAIL_TILEMAP_WOOD
#undef MAIL_PALETTE_WAVE
#undef MAIL_TILES_WAVE
#undef MAIL_TILEMAP_WAVE
#undef MAIL_PALETTE_BEAD
#undef MAIL_TILES_BEAD
#undef MAIL_TILEMAP_BEAD
#undef MAIL_PALETTE_SHADOW
#undef MAIL_TILES_SHADOW
#undef MAIL_TILEMAP_SHADOW
#undef MAIL_PALETTE_TROPIC
#undef MAIL_TILES_TROPIC
#undef MAIL_TILEMAP_TROPIC
#undef MAIL_PALETTE_DREAM
#undef MAIL_TILES_DREAM
#undef MAIL_TILEMAP_DREAM
#undef MAIL_PALETTE_FAB
#undef MAIL_TILES_FAB
#undef MAIL_TILEMAP_FAB
#undef MAIL_PALETTE_RETRO
#undef MAIL_TILES_RETRO
#undef MAIL_TILEMAP_RETRO
#undef MAIL_DATA

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
