#include "global.h"
#include "berry.h"
#include "decompress.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "menu_helpers.h"
#include "sprite.h"
#include "window.h"
#include "constants/items.h"

enum
{
    TAG_BAG_GFX = 100,
    TAG_ROTATING_BALL_GFX,
    TAG_ITEM_ICON,
    TAG_ITEM_ICON_ALT,
};

#define TAG_BERRY_CHECK_CIRCLE_GFX 10000
#define TAG_BERRY_PIC_PAL 30020

struct CompressedTilesPal
{
    const u32 *tiles;
    const u32 *pal;
};

void SpriteCB_SwitchPocketRotatingBallInit(struct Sprite *sprite);

#define ITEM_MENU_ICONS_DATA __attribute__((section(".rodata.item_menu_icons_mid57a")))

ITEM_MENU_ICONS_DATA static const u16 sRotatingBall_Pal[16] = INCBIN_U16("graphics/bag/rotating_ball.gbapal");
ITEM_MENU_ICONS_DATA static const u8 sRotatingBall_Gfx[0x80] = INCBIN_U8("graphics/bag/rotating_ball.4bpp");
ITEM_MENU_ICONS_DATA static const u8 sCherryUnused[0x480] = INCBIN_U8("graphics/unused/cherry.4bpp");
ITEM_MENU_ICONS_DATA static const u16 sCherryUnused_Pal[16] = INCBIN_U16("graphics/unused/cherry.gbapal");

ITEM_MENU_ICONS_DATA static const struct OamData sBagOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sSpriteAnim_Bag_Closed[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sSpriteAnim_Bag_Items[] =
{
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sSpriteAnim_Bag_KeyItems[] =
{
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sSpriteAnim_Bag_Pokeballs[] =
{
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sSpriteAnim_Bag_TMsHMs[] =
{
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sSpriteAnim_Bag_Berries[] =
{
    ANIMCMD_FRAME(320, 4),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd *const sBagSpriteAnimTable[] =
{
    [POCKET_NONE]       = sSpriteAnim_Bag_Closed,
    [POCKET_ITEMS]      = sSpriteAnim_Bag_Items,
    [POCKET_POKE_BALLS] = sSpriteAnim_Bag_Pokeballs,
    [POCKET_TM_HM]      = sSpriteAnim_Bag_TMsHMs,
    [POCKET_BERRIES]    = sSpriteAnim_Bag_Berries,
    [POCKET_KEY_ITEMS]  = sSpriteAnim_Bag_KeyItems,
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd sSpriteAffineAnim_BagNormal[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd sSpriteAffineAnim_BagShake[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 254, 2),
    AFFINEANIMCMD_FRAME(0, 0, 2, 4),
    AFFINEANIMCMD_FRAME(0, 0, 254, 4),
    AFFINEANIMCMD_FRAME(0, 0, 2, 2),
    AFFINEANIMCMD_END,
};

enum
{
    ANIM_BAG_NORMAL,
    ANIM_BAG_SHAKE,
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd *const sBagAffineAnimCmds[] =
{
    [ANIM_BAG_NORMAL] = sSpriteAffineAnim_BagNormal,
    [ANIM_BAG_SHAKE]  = sSpriteAffineAnim_BagShake,
};

ITEM_MENU_ICONS_DATA const struct CompressedSpriteSheet gBagMaleSpriteSheet =
{
    gBagMaleTiles, 0x3000, TAG_BAG_GFX,
};

ITEM_MENU_ICONS_DATA const struct CompressedSpriteSheet gBagFemaleSpriteSheet =
{
    gBagFemaleTiles, 0x3000, TAG_BAG_GFX,
};

ITEM_MENU_ICONS_DATA const struct CompressedSpritePalette gBagPaletteTable =
{
    gBagPalette, TAG_BAG_GFX,
};

ITEM_MENU_ICONS_DATA static const struct SpriteTemplate sBagSpriteTemplate =
{
    .tileTag = TAG_BAG_GFX,
    .paletteTag = TAG_BAG_GFX,
    .oam = &sBagOamData,
    .anims = sBagSpriteAnimTable,
    .images = NULL,
    .affineAnims = sBagAffineAnimCmds,
    .callback = SpriteCallbackDummy,
};

ITEM_MENU_ICONS_DATA static const struct OamData sRotatingBallOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 4,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sSpriteAffineAnim_RotatingBallStationary[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd *const sRotatingBallSpriteAnimTable[] =
{
    sSpriteAffineAnim_RotatingBallStationary,
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd sSpriteAffineAnim_RotatingBallRotation1[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 8, 16),
    AFFINEANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd sSpriteAffineAnim_RotatingBallRotation2[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 248, 16),
    AFFINEANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd *const sRotatingBallAnimCmds[] =
{
    sSpriteAffineAnim_RotatingBallRotation1,
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd *const sRotatingBallAnimCmds_FullRotation[] =
{
    sSpriteAffineAnim_RotatingBallRotation2,
};

ITEM_MENU_ICONS_DATA static const struct SpriteSheet sRotatingBallTable =
{
    sRotatingBall_Gfx, sizeof(sRotatingBall_Gfx), TAG_ROTATING_BALL_GFX,
};

ITEM_MENU_ICONS_DATA static const struct SpritePalette sRotatingBallPaletteTable =
{
    sRotatingBall_Pal, TAG_ROTATING_BALL_GFX,
};

ITEM_MENU_ICONS_DATA static const struct SpriteTemplate sRotatingBallSpriteTemplate =
{
    .tileTag = TAG_ROTATING_BALL_GFX,
    .paletteTag = TAG_ROTATING_BALL_GFX,
    .oam = &sRotatingBallOamData,
    .anims = sRotatingBallSpriteAnimTable,
    .images = NULL,
    .affineAnims = sRotatingBallAnimCmds,
    .callback = SpriteCB_SwitchPocketRotatingBallInit,
};

ITEM_MENU_ICONS_DATA static const struct OamData sBerryPicOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 7,
    .affineParam = 0,
};

ITEM_MENU_ICONS_DATA static const struct OamData sBerryPicRotatingOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 7,
    .affineParam = 0,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sAnim_BerryPic[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd *const sBerryPicSpriteAnimTable[] =
{
    sAnim_BerryPic,
};

ITEM_MENU_ICONS_DATA static const struct SpriteFrameImage sBerryPicSpriteImageTable[] =
{
    {&gDecompressionBuffer[0], 0x800},
};

ITEM_MENU_ICONS_DATA static const struct SpriteTemplate sBerryPicSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = sBerryPicSpriteImageTable,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd sSpriteAffineAnim_BerryPicRotation1[] =
{
    AFFINEANIMCMD_FRAME(-1, -1, 253, 96),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(-2, -2, 255, 64),
    AFFINEANIMCMD_FRAME(-8, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -8, 0, 16),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0),
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd sSpriteAffineAnim_BerryPicRotation2[] =
{
    AFFINEANIMCMD_FRAME(-1, -1, 3, 96),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(-2, -2, 1, 64),
    AFFINEANIMCMD_FRAME(-8, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -8, 0, 16),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0),
};

ITEM_MENU_ICONS_DATA static const union AffineAnimCmd *const sBerryPicRotatingAnimCmds[] =
{
    sSpriteAffineAnim_BerryPicRotation1,
    sSpriteAffineAnim_BerryPicRotation2,
};

ITEM_MENU_ICONS_DATA static const struct SpriteTemplate sBerryPicRotatingSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicRotatingOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = sBerryPicSpriteImageTable,
    .affineAnims = sBerryPicRotatingAnimCmds,
    .callback = SpriteCallbackDummy,
};

ITEM_MENU_ICONS_DATA static const struct CompressedTilesPal sBerryPicTable[] =
{
    [ITEM_TO_BERRY(ITEM_CHERI_BERRY)  - 1] = {gBerryPic_Cheri,  gBerryPalette_Cheri},
    [ITEM_TO_BERRY(ITEM_CHESTO_BERRY) - 1] = {gBerryPic_Chesto, gBerryPalette_Chesto},
    [ITEM_TO_BERRY(ITEM_PECHA_BERRY)  - 1] = {gBerryPic_Pecha,  gBerryPalette_Pecha},
    [ITEM_TO_BERRY(ITEM_RAWST_BERRY)  - 1] = {gBerryPic_Rawst,  gBerryPalette_Rawst},
    [ITEM_TO_BERRY(ITEM_ASPEAR_BERRY) - 1] = {gBerryPic_Aspear, gBerryPalette_Aspear},
    [ITEM_TO_BERRY(ITEM_LEPPA_BERRY)  - 1] = {gBerryPic_Leppa,  gBerryPalette_Leppa},
    [ITEM_TO_BERRY(ITEM_ORAN_BERRY)   - 1] = {gBerryPic_Oran,   gBerryPalette_Oran},
    [ITEM_TO_BERRY(ITEM_PERSIM_BERRY) - 1] = {gBerryPic_Persim, gBerryPalette_Persim},
    [ITEM_TO_BERRY(ITEM_LUM_BERRY)    - 1] = {gBerryPic_Lum,    gBerryPalette_Lum},
    [ITEM_TO_BERRY(ITEM_SITRUS_BERRY) - 1] = {gBerryPic_Sitrus, gBerryPalette_Sitrus},
    [ITEM_TO_BERRY(ITEM_FIGY_BERRY)   - 1] = {gBerryPic_Figy,   gBerryPalette_Figy},
    [ITEM_TO_BERRY(ITEM_WIKI_BERRY)   - 1] = {gBerryPic_Wiki,   gBerryPalette_Wiki},
    [ITEM_TO_BERRY(ITEM_MAGO_BERRY)   - 1] = {gBerryPic_Mago,   gBerryPalette_Mago},
    [ITEM_TO_BERRY(ITEM_AGUAV_BERRY)  - 1] = {gBerryPic_Aguav,  gBerryPalette_Aguav},
    [ITEM_TO_BERRY(ITEM_IAPAPA_BERRY) - 1] = {gBerryPic_Iapapa, gBerryPalette_Iapapa},
    [ITEM_TO_BERRY(ITEM_RAZZ_BERRY)   - 1] = {gBerryPic_Razz,   gBerryPalette_Razz},
    [ITEM_TO_BERRY(ITEM_BLUK_BERRY)   - 1] = {gBerryPic_Bluk,   gBerryPalette_Bluk},
    [ITEM_TO_BERRY(ITEM_NANAB_BERRY)  - 1] = {gBerryPic_Nanab,  gBerryPalette_Nanab},
    [ITEM_TO_BERRY(ITEM_WEPEAR_BERRY) - 1] = {gBerryPic_Wepear, gBerryPalette_Wepear},
    [ITEM_TO_BERRY(ITEM_PINAP_BERRY)  - 1] = {gBerryPic_Pinap,  gBerryPalette_Pinap},
    [ITEM_TO_BERRY(ITEM_POMEG_BERRY)  - 1] = {gBerryPic_Pomeg,  gBerryPalette_Pomeg},
    [ITEM_TO_BERRY(ITEM_KELPSY_BERRY) - 1] = {gBerryPic_Kelpsy, gBerryPalette_Kelpsy},
    [ITEM_TO_BERRY(ITEM_QUALOT_BERRY) - 1] = {gBerryPic_Qualot, gBerryPalette_Qualot},
    [ITEM_TO_BERRY(ITEM_HONDEW_BERRY) - 1] = {gBerryPic_Hondew, gBerryPalette_Hondew},
    [ITEM_TO_BERRY(ITEM_GREPA_BERRY)  - 1] = {gBerryPic_Grepa,  gBerryPalette_Grepa},
    [ITEM_TO_BERRY(ITEM_TAMATO_BERRY) - 1] = {gBerryPic_Tamato, gBerryPalette_Tamato},
    [ITEM_TO_BERRY(ITEM_CORNN_BERRY)  - 1] = {gBerryPic_Cornn,  gBerryPalette_Cornn},
    [ITEM_TO_BERRY(ITEM_MAGOST_BERRY) - 1] = {gBerryPic_Magost, gBerryPalette_Magost},
    [ITEM_TO_BERRY(ITEM_RABUTA_BERRY) - 1] = {gBerryPic_Rabuta, gBerryPalette_Rabuta},
    [ITEM_TO_BERRY(ITEM_NOMEL_BERRY)  - 1] = {gBerryPic_Nomel,  gBerryPalette_Nomel},
    [ITEM_TO_BERRY(ITEM_SPELON_BERRY) - 1] = {gBerryPic_Spelon, gBerryPalette_Spelon},
    [ITEM_TO_BERRY(ITEM_PAMTRE_BERRY) - 1] = {gBerryPic_Pamtre, gBerryPalette_Pamtre},
    [ITEM_TO_BERRY(ITEM_WATMEL_BERRY) - 1] = {gBerryPic_Watmel, gBerryPalette_Watmel},
    [ITEM_TO_BERRY(ITEM_DURIN_BERRY)  - 1] = {gBerryPic_Durin,  gBerryPalette_Durin},
    [ITEM_TO_BERRY(ITEM_BELUE_BERRY)  - 1] = {gBerryPic_Belue,  gBerryPalette_Belue},
    [ITEM_TO_BERRY(ITEM_LIECHI_BERRY) - 1] = {gBerryPic_Liechi, gBerryPalette_Liechi},
    [ITEM_TO_BERRY(ITEM_GANLON_BERRY) - 1] = {gBerryPic_Ganlon, gBerryPalette_Ganlon},
    [ITEM_TO_BERRY(ITEM_SALAC_BERRY)  - 1] = {gBerryPic_Salac,  gBerryPalette_Salac},
    [ITEM_TO_BERRY(ITEM_PETAYA_BERRY) - 1] = {gBerryPic_Petaya, gBerryPalette_Petaya},
    [ITEM_TO_BERRY(ITEM_APICOT_BERRY) - 1] = {gBerryPic_Apicot, gBerryPalette_Apicot},
    [ITEM_TO_BERRY(ITEM_LANSAT_BERRY) - 1] = {gBerryPic_Lansat, gBerryPalette_Lansat},
    [ITEM_TO_BERRY(ITEM_STARF_BERRY)  - 1] = {gBerryPic_Starf,  gBerryPalette_Starf},
    [ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) - 1] = {gBerryPic_Enigma, gBerryPalette_Enigma},
};

ITEM_MENU_ICONS_DATA const struct CompressedSpriteSheet gBerryCheckCircleSpriteSheet =
{
    gBerryCheckCircle_Gfx, 0x800, TAG_BERRY_CHECK_CIRCLE_GFX,
};

ITEM_MENU_ICONS_DATA const struct CompressedSpritePalette gBerryCheckCirclePaletteTable =
{
    gBerryCheck_Pal, TAG_BERRY_CHECK_CIRCLE_GFX,
};

ITEM_MENU_ICONS_DATA static const struct OamData sBerryCheckCircleOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd sSpriteAnim_BerryCheckCircle[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

ITEM_MENU_ICONS_DATA static const union AnimCmd *const sBerryCheckCircleSpriteAnimTable[] =
{
    sSpriteAnim_BerryCheckCircle,
};

ITEM_MENU_ICONS_DATA static const struct SpriteTemplate sBerryCheckCircleSpriteTemplate =
{
    .tileTag = TAG_BERRY_CHECK_CIRCLE_GFX,
    .paletteTag = TAG_BERRY_CHECK_CIRCLE_GFX,
    .oam = &sBerryCheckCircleOamData,
    .anims = sBerryCheckCircleSpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

#undef ITEM_MENU_ICONS_DATA


__attribute__((naked)) void RemoveBagSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _080D4578\n\t"
        "	ldr r2, _080D457C\n\t"
        "	adds r1, r4, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r5, r0, r1\n\t"
        "	ldrb r0, [r5]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _080D4572\n\t"
        "	adds r4, #0x64\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpriteTilesByTag\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpritePaletteByTag\n\t"
        "	ldrb r1, [r5]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r4, _080D4580\n\t"
        "	adds r0, r0, r4\n\t"
        "	bl FreeSpriteOamMatrix\n\t"
        "	ldrb r1, [r5]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	bl DestroySprite\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r5]\n\t"
        "_080D4572:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4578: .4byte gUnknown_203CB20\n\t"
        "_080D457C: .4byte 0x00000804\n\t"
        "_080D4580: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void AddBagVisualSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r0, _080D45B0\n\t"
        "	ldr r4, [r0]\n\t"
        "	ldr r0, _080D45B4\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldr r0, _080D45B8\n\t"
        "	movs r1, #0x44\n\t"
        "	movs r2, #0x42\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	strb r0, [r4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl SetBagVisualPocketId\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D45B0: .4byte gUnknown_203CB20\n\t"
        "_080D45B4: .4byte 0x00000804\n\t"
        "_080D45B8: .4byte sBagSpriteTemplate\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetBagVisualPocketId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	ldr r0, _080D45F4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r2, _080D45F8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r2, [r0]\n\t"
        "	lsls r0, r2, #4\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r2, _080D45FC\n\t"
        "	adds r2, r0, r2\n\t"
        "	cmp r1, #0\n\t"
        "	beq _080D4608\n\t"
        "	ldr r0, _080D4600\n\t"
        "	strh r0, [r2, #0x26]\n\t"
        "	ldr r0, _080D4604\n\t"
        "	str r0, [r2, #0x1c]\n\t"
        "	adds r0, r3, #1\n\t"
        "	strh r0, [r2, #0x2e]\n\t"
        "	adds r0, r2, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	b _080D4614\n\t"
        "	.align 2, 0\n\t"
        "_080D45F4: .4byte gUnknown_203CB20\n\t"
        "_080D45F8: .4byte 0x00000804\n\t"
        "_080D45FC: .4byte gSprites\n\t"
        "_080D4600: .4byte 0x0000FFFB\n\t"
        "_080D4604: .4byte SpriteCB_BagVisualSwitchingPockets + 1\n\t"
        "_080D4608:\n\t"
        "	adds r1, r3, #1\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "_080D4614:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpriteCB_BagVisualSwitchingPockets(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r1, [r4, #0x26]\n\t"
        "	movs r2, #0x26\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080D462C\n\t"
        "	adds r0, r1, #1\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	b _080D463C\n\t"
        "_080D462C:\n\t"
        "	ldrh r1, [r4, #0x2e]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	ldr r0, _080D4644\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "_080D463C:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4644: .4byte SpriteCallbackDummy + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ShakeBagVisual(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _080D4680\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080D4684\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080D4688\n\t"
        "	adds r4, r0, r1\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x3f\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080D4678\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl StartSpriteAffineAnim\n\t"
        "	ldr r0, _080D468C\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "_080D4678:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4680: .4byte gUnknown_203CB20\n\t"
        "_080D4684: .4byte 0x00000804\n\t"
        "_080D4688: .4byte gSprites\n\t"
        "_080D468C: .4byte SpriteCB_ShakeBagVisual + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpriteCB_ShakeBagVisual(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r0, #0x3f\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080D46AC\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl StartSpriteAffineAnim\n\t"
        "	ldr r0, _080D46B4\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "_080D46AC:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D46B4: .4byte SpriteCallbackDummy + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void AddSwitchPocketRotatingBallSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	ldr r0, _080D46F8\n\t"
        "	ldr r4, [r0]\n\t"
        "	ldr r0, _080D46FC\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldr r0, _080D4700\n\t"
        "	bl LoadSpriteSheet\n\t"
        "	ldr r0, _080D4704\n\t"
        "	bl LoadSpritePalette\n\t"
        "	ldr r0, _080D4708\n\t"
        "	movs r1, #0x10\n\t"
        "	movs r2, #0x10\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r2, _080D470C\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r5, [r0, #0x2e]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D46F8: .4byte gUnknown_203CB20\n\t"
        "_080D46FC: .4byte 0x00000805\n\t"
        "_080D4700: .4byte sRotatingBallTable\n\t"
        "_080D4704: .4byte sRotatingBallPaletteTable\n\t"
        "_080D4708: .4byte sRotatingBallSpriteTemplate\n\t"
        "_080D470C: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void UpdateSwitchPocketRotatingBallCoords(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldrh r2, [r0, #0x30]\n\t"
        "	ldrh r1, [r0, #0x34]\n\t"
        "	adds r1, #1\n\t"
        "	movs r3, #1\n\t"
        "	ands r1, r3\n\t"
        "	subs r2, r2, r1\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r1, #0x28\n\t"
        "	strb r2, [r1]\n\t"
        "	ldrh r2, [r0, #0x30]\n\t"
        "	ldrh r1, [r0, #0x34]\n\t"
        "	adds r1, #1\n\t"
        "	ands r1, r3\n\t"
        "	subs r2, r2, r1\n\t"
        "	adds r0, #0x29\n\t"
        "	strb r2, [r0]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpriteCB_SwitchPocketRotatingBallInit(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r1, [r4, #1]\n\t"
        "	movs r0, #4\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #1]\n\t"
        "	movs r0, #0x2e\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r1, r0\n\t"
        "	bne _080D475C\n\t"
        "	ldr r0, _080D4758\n\t"
        "	b _080D475E\n\t"
        "	.align 2, 0\n\t"
        "_080D4758: .4byte sRotatingBallAnimCmds\n\t"
        "_080D475C:\n\t"
        "	ldr r0, _080D4790\n\t"
        "_080D475E:\n\t"
        "	str r0, [r4, #0x10]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl InitSpriteAffineAnim\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x28\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	strh r0, [r4, #0x30]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x29\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	strh r0, [r4, #0x30]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl UpdateSwitchPocketRotatingBallCoords\n\t"
        "	ldr r0, _080D4794\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4790: .4byte sRotatingBallAnimCmds_FullRotation\n\t"
        "_080D4794: .4byte SpriteCB_SwitchPocketRotatingBallContinue + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpriteCB_SwitchPocketRotatingBallContinue(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl UpdateSwitchPocketRotatingBallCoords\n\t"
        "	movs r1, #0x34\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x10\n\t"
        "	bne _080D47B6\n\t"
        "	movs r0, #1\n\t"
        "	bl RemoveBagSprite\n\t"
        "_080D47B6:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void AddBagItemIconSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r4, r1, #0x18\n\t"
        "	ldr r0, _080D4810\n\t"
        "	ldr r2, _080D4814\n\t"
        "	adds r1, r4, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r5, r0, r1\n\t"
        "	ldrb r0, [r5]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _080D480A\n\t"
        "	adds r4, #0x66\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpriteTilesByTag\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpritePaletteByTag\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl AddItemIconSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0x40\n\t"
        "	beq _080D480A\n\t"
        "	strb r2, [r5]\n\t"
        "	ldr r1, _080D4818\n\t"
        "	lsls r0, r2, #4\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0x18\n\t"
        "	strh r1, [r0, #0x24]\n\t"
        "	movs r1, #0x58\n\t"
        "	strh r1, [r0, #0x26]\n\t"
        "_080D480A:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4810: .4byte gUnknown_203CB20\n\t"
        "_080D4814: .4byte 0x00000806\n\t"
        "_080D4818: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}
__attribute__((naked)) void RemoveBagItemIconSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0x12\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl RemoveBagSprite\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}



__attribute__((naked)) void sub_080D4830(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080D4844\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080D4848\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	bl sub_08122350\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4844: .4byte gUnknown_203CB20\n\t"
        "_080D4848: .4byte 0x00000808\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080D484C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r0, _080D4868\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080D486C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	bl sub_08122408\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4868: .4byte gUnknown_203CB20\n\t"
        "_080D486C: .4byte 0x00000808\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080D4870(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r3, r0, #0\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	ldr r0, _080D4894\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080D4898\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r3, r3, #4\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xd\n\t"
        "	adds r3, r3, r1\n\t"
        "	lsrs r3, r3, #0x10\n\t"
        "	movs r1, #0x88\n\t"
        "	movs r2, #0x78\n\t"
        "	bl sub_08122454\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4894: .4byte gUnknown_203CB20\n\t"
        "_080D4898: .4byte 0x00000808\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080D489C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #4\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl memset\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r4, r4, r0\n\t"
        "	movs r7, #0\n\t"
        "_080D48BA:\n\t"
        "	adds r4, #0x20\n\t"
        "	movs r5, #0\n\t"
        "	adds r1, r7, #1\n\t"
        "	mov r8, r1\n\t"
        "_080D48C2:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	movs r2, #0x20\n\t"
        "	bl memcpy\n\t"
        "	adds r4, #0x20\n\t"
        "	adds r6, #0x20\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #5\n\t"
        "	bls _080D48C2\n\t"
        "	cmp r7, #5\n\t"
        "	beq _080D48E0\n\t"
        "	adds r4, #0x20\n\t"
        "_080D48E0:\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	cmp r7, #5\n\t"
        "	bls _080D48BA\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void LoadBerryGfx(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r4, r0, #0\n\t"
        "	cmp r4, #0x2a\n\t"
        "	bne _080D4906\n\t"
        "	bl IsEnigmaBerryValid\n\t"
        "_080D4906:\n\t"
        "	ldr r5, _080D4944\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r0, r5, #4\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r1, _080D4948\n\t"
        "	ldr r0, [sp, #4]\n\t"
        "	ands r0, r1\n\t"
        "	ldr r1, _080D494C\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [sp, #4]\n\t"
        "	mov r0, sp\n\t"
        "	bl LoadCompressedSpritePalette\n\t"
        "	adds r4, r4, r5\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r4, _080D4950\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl LZDecompressVram\n\t"
        "	ldr r0, _080D4954\n\t"
        "	adds r1, r4, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_080D489C\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D4944: .4byte sBerryPicTable\n\t"
        "_080D4948: .4byte 0xFFFF0000\n\t"
        "_080D494C: .4byte 0x00007544\n\t"
        "_080D4950: .4byte gUnknown_201D000\n\t"
        "_080D4954: .4byte 0xFFFFF000\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreateBerryTagSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r5, r2, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	bl LoadBerryGfx\n\t"
        "	ldr r0, _080D498C\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0x10\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	asrs r5, r5, #0x10\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080D498C: .4byte sBerryPicSpriteTemplate\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FreeBerryTagSpritePalette(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080D499C\n\t"
        "	bl FreeSpritePaletteByTag\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080D499C: .4byte 0x00007544\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void LoadSpinningBerryPicGfx(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r6, r2, #0\n\t"
        "	mov r8, r3\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r6, r6, #0x18\n\t"
        "	lsrs r6, r6, #0x18\n\t"
        "	mov r0, r8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	ldr r0, _080D4A04\n\t"
        "	bl FreeSpritePaletteByTag\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl LoadBerryGfx\n\t"
        "	ldr r0, _080D4A08\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	adds r4, r1, #0\n\t"
        "	mov r0, r8\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080D49F6\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080D4A0C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	bl StartSpriteAffineAnim\n\t"
        "_080D49F6:\n\t"
        "	adds r0, r4, #0\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080D4A04: .4byte 0x00007544\n\t"
        "_080D4A08: .4byte sBerryPicRotatingSpriteTemplate\n\t"
        "_080D4A0C: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreateBerryFlavorCircleSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldr r0, _080D4A2C\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	movs r2, #0x63\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080D4A2C: .4byte sBerryCheckCircleSpriteTemplate\n\t"
        ".syntax divided\n\t"
    );
}
