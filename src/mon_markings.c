#include "global.h"
#include "dma3.h"
#include "graphics.h"
#include "main.h"
#include "window.h"
#include "list_menu.h"
#include "mon_markings.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "text_window.h"

#define ANIM_CURSOR (NUM_MON_MARKINGS * 2)
#define ANIM_TEXT   (ANIM_CURSOR + 1)

#define SELECTION_OK NUM_MON_MARKINGS
#define SELECTION_CANCEL (SELECTION_OK + 1)

static void CreateMonMarkingsMenuSprites(s16, s16, u16, u16);
static void SpriteCB_Dummy(struct Sprite *);
static void SpriteCB_Marking(struct Sprite *);
static void SpriteCB_Cursor(struct Sprite *);
static struct Sprite *CreateMarkingComboSprite(u16, u16, const u16 *, u16);

// JP ROM data tables (the US sources define these statically).
extern const u16 sMonMarkings_Pal[];
extern const ALIGNED(4) u8 sMonMarkings_Gfx[];
extern const u8 gMonMarkingsMenu_Gfx[];
extern const u16 gMonMarkingsMenu_Pal[];
extern const struct OamData sOamData_MenuWindow;
extern const struct OamData sOamData_8x8;
extern const struct OamData sOamData_MarkingCombo;
extern const union AnimCmd *const sAnims_MenuWindow[];
extern const union AnimCmd *const sAnims_MenuSprite[];
extern const union AnimCmd *const sAnims_MarkingCombo[];

extern struct MonMarkingsMenu *sMenu;

#define sMarkingId data[0]
#define sCursorYOffset data[0]

void InitMonMarkingsMenu(struct MonMarkingsMenu *ptr)
{
    sMenu = ptr;
}

static void BufferMenuWindowTiles(void)
{
    const struct TilesPal *frame = GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType);
    sMenu->frameTiles = frame->tiles;
    sMenu->framePalette = frame->pal;
    sMenu->tileLoadState = 0;
    CpuFill16(0, sMenu->windowSpriteTiles, sizeof(sMenu->windowSpriteTiles));
}

static bool8 BufferMenuFrameTiles(void)
{
    u16 i;
    u8 *dest = sMenu->windowSpriteTiles + sMenu->tileLoadState * 0x100;

    switch (sMenu->tileLoadState)
    {
    case 0:
        CpuFastCopy(sMenu->frameTiles, dest, TILE_SIZE_4BPP);
        for (i = 0; i < 6; i++)
            CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP, dest + TILE_SIZE_4BPP * (i + 1), TILE_SIZE_4BPP);

        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 2, dest + TILE_SIZE_4BPP * 7, TILE_SIZE_4BPP);
        sMenu->tileLoadState++;
        break;
    default:
        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 3, dest, TILE_SIZE_4BPP);
        for (i = 0; i < 6; i++)
            CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 4, dest + TILE_SIZE_4BPP * (i + 1), TILE_SIZE_4BPP);

        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 5, dest + TILE_SIZE_4BPP * 7, TILE_SIZE_4BPP);
        sMenu->tileLoadState++;
        break;
    case 13:
        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 6, dest, TILE_SIZE_4BPP);
        for (i = 0; i < 6; i++)
            CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 7, dest + TILE_SIZE_4BPP * (i + 1), TILE_SIZE_4BPP);

        CpuFastCopy(sMenu->frameTiles + TILE_SIZE_4BPP * 8, dest + TILE_SIZE_4BPP * 7, TILE_SIZE_4BPP);
        sMenu->tileLoadState++;
        return FALSE;
    case 14:
        return FALSE;
    }

    return TRUE;
}

void BufferMonMarkingsMenuTiles(void)
{
    BufferMenuWindowTiles();
    while (BufferMenuFrameTiles());
}

void OpenMonMarkingsMenu(u8 markings, s16 x, s16 y)
{
    u16 i;
    sMenu->cursorPos = 0;
    sMenu->markings = markings;
    for (i = 0; i < NUM_MON_MARKINGS; i++)
        sMenu->markingsArray[i] = (sMenu->markings >> i) & 1;
    CreateMonMarkingsMenuSprites(x, y, sMenu->baseTileTag, sMenu->basePaletteTag);
}

void FreeMonMarkingsMenu(void)
{
    u16 i;

    for (i = 0; i < 2; i++)
    {
        FreeSpriteTilesByTag(sMenu->baseTileTag + i);
        FreeSpritePaletteByTag(sMenu->basePaletteTag + i);
    }
    for (i = 0; i < ARRAY_COUNT(sMenu->windowSprites); i++)
    {
        if (!sMenu->windowSprites[i])
            return;
        DestroySprite(sMenu->windowSprites[i]);
        sMenu->windowSprites[i] = NULL;
    }
    for (i = 0; i < NUM_MON_MARKINGS; i++)
    {
        if (!sMenu->markingSprites[i])
            return;
        DestroySprite(sMenu->markingSprites[i]);
        sMenu->markingSprites[i] = NULL;
    }
    if (sMenu->cursorSprite)
    {
        DestroySprite(sMenu->cursorSprite);
        sMenu->cursorSprite = NULL;
    }
    if (sMenu->textSprite)
    {
        DestroySprite(sMenu->textSprite);
        sMenu->textSprite = NULL;
    }
}

bool8 HandleMonMarkingsMenuInput(void)
{
    u16 i;

    if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        if (--sMenu->cursorPos < 0)
            sMenu->cursorPos = SELECTION_CANCEL;
        return TRUE;
    }

    if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        if (++sMenu->cursorPos > SELECTION_CANCEL)
            sMenu->cursorPos = 0;
        return TRUE;
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        switch (sMenu->cursorPos)
        {
        case SELECTION_OK:
            sMenu->markings = 0;
            for (i = 0; i < NUM_MON_MARKINGS; i++)
                sMenu->markings |= sMenu->markingsArray[i] << i;
            return FALSE;
        case SELECTION_CANCEL:
            return FALSE;
        }

        sMenu->markingsArray[sMenu->cursorPos] = !sMenu->markingsArray[sMenu->cursorPos];
        return TRUE;
    }

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        return FALSE;
    }

    return TRUE;
}

static void CreateMonMarkingsMenuSprites(s16 x, s16 y, u16 baseTileTag, u16 basePaletteTag)
{
    u16 i;
    u8 spriteId;

    struct SpriteSheet sheets[] =
    {
        { sMenu->windowSpriteTiles, 0x1000, baseTileTag },
        { gMonMarkingsMenu_Gfx, 0x320, baseTileTag + 1 },
        {}
    };

    struct SpritePalette palettes[] =
    {
        { sMenu->framePalette, basePaletteTag },
        { gMonMarkingsMenu_Pal, basePaletteTag + 1},
        {}
    };

    struct SpriteTemplate template =
    {
        .tileTag = baseTileTag,
        .paletteTag = basePaletteTag,
        .oam = &sOamData_MenuWindow,
        .anims = sAnims_MenuWindow,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_Dummy,
    };

    LoadSpriteSheets(sheets);
    LoadSpritePalettes(palettes);

    // Create window sprites
    for (i = 0; i < ARRAY_COUNT(sMenu->windowSprites); i++)
    {
        spriteId = CreateSprite(&template, x + 32, y + 32, 1);
        if (spriteId != MAX_SPRITES)
        {
            sMenu->windowSprites[i] = &gSprites[spriteId];
            StartSpriteAnim(&gSprites[spriteId], i);
        }
        else
        {
            sMenu->windowSprites[i] = NULL;
            return;
        }
    }
    sMenu->windowSprites[1]->y = y + 96;

    // Create marking sprites
    template.tileTag++;
    template.paletteTag++;
    template.anims = sAnims_MenuSprite;
    template.callback = SpriteCB_Marking;
    template.oam = &sOamData_8x8;
    for (i = 0; i < NUM_MON_MARKINGS; i++)
    {
        spriteId = CreateSprite(&template, x + 32, y + 16 + 16 * i, 0);
        if (spriteId != MAX_SPRITES)
        {
            sMenu->markingSprites[i] = &gSprites[spriteId];
            gSprites[spriteId].sMarkingId = i;
        }
        else
        {
            sMenu->markingSprites[i] = NULL;
            return;
        }
    }

    // Create OK/Cancel text sprite
    template.callback = SpriteCallbackDummy;
    spriteId = CreateSprite(&template, 0, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        sMenu->textSprite = &gSprites[spriteId];
        sMenu->textSprite->oam.shape = SPRITE_SHAPE(32x32);
        sMenu->textSprite->oam.size = SPRITE_SIZE(32x32);
        StartSpriteAnim(sMenu->textSprite, ANIM_TEXT);
        sMenu->textSprite->x = x + 32;
        sMenu->textSprite->y = y + 80;
        CalcCenterToCornerVec(sMenu->textSprite, SPRITE_SHAPE(32x16), SPRITE_SIZE(32x16), ST_OAM_AFFINE_OFF);
    }
    else
    {
        sMenu->textSprite = NULL;
    }

    // Create cursor sprite
    template.callback = SpriteCB_Cursor;
    spriteId = CreateSprite(&template, x + 12, 0, 0);
    if (spriteId != MAX_SPRITES)
    {
        sMenu->cursorSprite = &gSprites[spriteId];
        sMenu->cursorSprite->sCursorYOffset = y + 16;
        StartSpriteAnim(sMenu->cursorSprite, ANIM_CURSOR);
    }
    else
    {
        sMenu->cursorSprite = NULL;
    }
}

static void SpriteCB_Dummy(struct Sprite *sprite)
{
}

static void SpriteCB_Marking(struct Sprite *sprite)
{
    if (sMenu->markingsArray[sprite->sMarkingId])
        StartSpriteAnim(sprite, 2 * sprite->sMarkingId + 1); // Set marking 'on'
    else
        StartSpriteAnim(sprite, 2 * sprite->sMarkingId); // Set marking 'off'
}

#undef sMarkingId

static void SpriteCB_Cursor(struct Sprite *sprite)
{
    sprite->y = (16 * sMenu->cursorPos) + sprite->sCursorYOffset;
}

#undef sCursorYOffset

// Creates a mon marking combination sprite with a spritesheet that holds every possible combination, used by the summary screen / PokÃ©nav
struct Sprite *CreateMonMarkingAllCombosSprite(u16 tileTag, u16 paletteTag, const u16 *palette)
{
    if (!palette)
        palette = sMonMarkings_Pal;
    return CreateMarkingComboSprite(tileTag, paletteTag, palette, 1 << NUM_MON_MARKINGS);
}

// Creates a mon marking combination sprite with a spritesheet that holds only one combination, used for the currently selected PC mon
struct Sprite *CreateMonMarkingComboSprite(u16 tileTag, u16 paletteTag, const u16 *palette)
{
    if (!palette)
        palette = sMonMarkings_Pal;
    return CreateMarkingComboSprite(tileTag, paletteTag, palette, 1);
}

static struct Sprite *CreateMarkingComboSprite(u16 tileTag, u16 paletteTag, const u16 *palette, u16 size)
{
    u8 spriteId;
    struct SpriteTemplate template;
    struct SpriteSheet sheet = { sMonMarkings_Gfx, 0x80, tileTag };
    struct SpritePalette sprPalette = { palette, paletteTag };

    template.tileTag = tileTag;
    template.paletteTag = paletteTag;
    template.oam = &sOamData_MarkingCombo;
    template.anims = sAnims_MarkingCombo;
    template.images = NULL;
    template.affineAnims = gDummySpriteAffineAnimTable;
    template.callback = SpriteCB_Dummy;

    sheet.size = size * 0x80;

    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&sprPalette);

    spriteId = CreateSprite(&template, 0, 0, 0);
    if (spriteId != MAX_SPRITES)
        return &gSprites[spriteId];
    else
        return NULL;
}

// Update what combination is shown, used for sprites created with CreateMonMarkingComboSprite
void UpdateMonMarkingTiles(u8 markings, void *dest)
{
    RequestDma3Copy(&sMonMarkings_Gfx[markings * 0x80], dest, 0x80, 0x10);
}
