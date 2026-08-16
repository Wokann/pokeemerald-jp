#include "global.h"
#include "sprite.h"
#include "battle_affine.h"

// 0x82D2A68 - pokejump digit palette (sSpritePalette_Digits in pokejump3.h).
const u16 sDigitPalette[] =
{
    0x0000, 0x0000, 0x6739, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// 0x82D2A88 - pokejump digit LZ gfx (sSpriteSheet_Digits in pokejump3.h).
const u32 sDigitGfx[] =
{
    0x00016010, 0x00000020, 0x00211101, 0x11022210,
    0x10021102, 0x12031021, 0x22102100, 0x02211120,
    0x22222200, 0x10001E20, 0x00232021, 0x03001270,
    0x03000B10, 0x21111110, 0x30222030, 0x020B0020,
    0x00122211, 0x11022221, 0x21111021, 0x0200224F,
    0x1F001100, 0x1F501E00, 0x11622B00, 0x53101400,
    0x00112112, 0x11141240, 0x3F002211, 0x115F3002,
    0x3000FB02, 0x01207D20, 0x2F003B20, 0x001F3000,
    0x5F00EE0F, 0x07005D00, 0x403FF022, 0x001F207F,
    0x208710FB, 0x101F80C3, 0x229F404F, 0x6B003A00,
    0x005A00FF, 0x605E4072, 0xF03310BF, 0x401F703F,
    0xCB00FC17, 0xBF902101, 0x9F300140, 0x000013B0,
    0x0002C010, 0xC0000020, 0x00211001, 0x12002100,
    0x00221002, 0x90021021, 0x012003B0, 0x21121500,
    0x20300002, 0x7036E022, 0x0000023F, 0x0300BA11,
    0x10030012, 0x1103D00B, 0xF8225F00, 0x7FF03FF0,
    0x73006F00, 0x00223000, 0x00225810, 0x06000209,
    0x11111E00, 0x22203221, 0x016040F0, 0x3B001111,
    0x3B40D222, 0x00100300, 0x7022208C, 0x00BF11C3,
    0x4F00224F, 0x405039F0, 0xBC006800, 0x00CD0310,
    0x10351087, 0x20030022, 0x81101277, 0x003B00FF,
    0x3038F05D, 0x002700BE, 0x1031007F, 0x00014A0B,
    0x500212B3, 0x0D00108B, 0x00117F20, 0xE0BEF0C8,
    0x403F00BF, 0xF00F6043, 0x01F0FFBF, 0xFB301F51,
    0x35110320, 0x0E507300, 0xF0FE0320, 0x307FF07F,
    0xF00FD06F, 0xC03FF07F, 0x00F9212F, 0xF0FF402F,
    0xD001F03F, 0x0102114E, 0x2FF0C04E, 0x00000140,
    0x02008000, 0x00000800, 0x02008800, 0x00000800,
    0x02009000, 0x00000800, 0x02009800, 0x00000800,
    0x0200A000, 0x00000800, 0x0200A800, 0x00000800,
    0x0200B000, 0x00000800, 0x0200B800, 0x00000800,
    0x0200C000, 0x00000800, 0x0200C800, 0x00000800,
    0x0200D000, 0x00000800, 0x0200D800, 0x00000800,
    0x0200E000, 0x00000800, 0x0200E800, 0x00000800,
    0x0200F000, 0x00000800, 0x0200F800, 0x00000800,
    0x08D66524, 0x00000800, 0x08D66D24, 0x00000800,
    0x08D67524, 0x00000800, 0x08D67D24, 0x00000800,
    0x08D68524, 0x00000800, 0x08D68D24, 0x00000800,
    0x08D69524, 0x00000800, 0x08D69D24, 0x00000800,
    0x08D6A524, 0x00000800, 0x08D6AD24, 0x00000800,
    0x08D6B524, 0x00000800, 0x08D6BD24, 0x00000800,
    0x08D6C524, 0x00000800, 0x08D6CD24, 0x00000800,
    0x08D6D524, 0x00000800, 0x08D6DD24, 0x00000800,
    0x08D6E524, 0x00000800, 0x08D6ED24, 0x00000800,
    0x08D6F524, 0x00000800, 0x08D6FD24, 0x00000800,
    0x08D70524, 0x00000800, 0x08D70D24, 0x00000800,
    0x08D71524, 0x00000800, 0x08D71D24, 0x00000800,
    0x08D72524, 0x00000800, 0x08D72D24, 0x00000800,
    0x08D73524, 0x00000800, 0x08D73D24, 0x00000800,
    0x08D74524, 0x00000800, 0x08D74D24, 0x00000800,
    0x08D75524, 0x00000800, 0x08D75D24, 0x00000800,
    0x08D76524, 0x00000800, 0x08D76D24, 0x00000800,
};

// 0x82D2DC8 - general anim frames (referenced by the asm gMonFrontPicAnims table).
const union AnimCmd sAnim_GeneralFrame0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

// 0x82D2DD0
const union AnimCmd sAnim_GeneralFrame3[] =
{
    ANIMCMD_FRAME(3, 0),
    ANIMCMD_END
};

// 0x82D2DD8 - battler affine anims (values match pokeemerald data.c).
static const union AffineAnimCmd sAffineAnim_Battler_Normal[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_Flipped[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_Emerge[] =
{
    AFFINEANIMCMD_FRAME(0x28, 0x28, 0, 0),
    AFFINEANIMCMD_FRAME(0x12, 0x12, 0, 12),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_Return[] =
{
    AFFINEANIMCMD_FRAME(-0x2, -0x2, 0, 18),
    AFFINEANIMCMD_FRAME(-0x10, -0x10, 0, 15),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_HorizontalSquishLoop[] =
{
    AFFINEANIMCMD_FRAME(0xA0, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x4, 0x0, 0, 8),
    AFFINEANIMCMD_FRAME(-0x4, 0x0, 0, 8),
    AFFINEANIMCMD_JUMP(1)
};

static const union AffineAnimCmd sAffineAnim_Battler_Grow[] =
{
    AFFINEANIMCMD_FRAME(0x2, 0x2, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_Shrink[] =
{
    AFFINEANIMCMD_FRAME(-0x2, -0x2, 0, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_BigToSmall[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-0x10, -0x10, 0, 9),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_GrowLarge[] =
{
    AFFINEANIMCMD_FRAME(0x4, 0x4, 0, 63),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_TipRight[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -3, 5),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 3, 5),
    AFFINEANIMCMD_END
};

// 0x82D2EA8
const union AffineAnimCmd *const gAffineAnims_BattleSpritePlayerSide[] =
{
    sAffineAnim_Battler_Normal,
    sAffineAnim_Battler_Emerge,
    sAffineAnim_Battler_Return,
    sAffineAnim_Battler_HorizontalSquishLoop,
    sAffineAnim_Battler_Grow,
    sAffineAnim_Battler_Shrink,
    sAffineAnim_Battler_GrowLarge,
    sAffineAnim_Battler_TipRight,
    sAffineAnim_Battler_BigToSmall,
};

// 0x82D2ECC
static const union AffineAnimCmd sAffineAnim_Battler_SpinShrink[] =
{
    AFFINEANIMCMD_FRAME(-0x4, -0x4, 4, 63),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_TipLeft[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 3, 5),
    AFFINEANIMCMD_FRAME(0x0, 0x0, -3, 5),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_RotateUpAndBack[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, -5, 20),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 0, 20),
    AFFINEANIMCMD_FRAME(0x0, 0x0, 5, 20),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Battler_Spin[] =
{
    AFFINEANIMCMD_FRAME(0x0, 0x0, 9, 110),
    AFFINEANIMCMD_END
};

// 0x82D2F24
const union AffineAnimCmd *const gAffineAnims_BattleSpriteOpponentSide[] =
{
    sAffineAnim_Battler_Normal,
    sAffineAnim_Battler_Emerge,
    sAffineAnim_Battler_Return,
    sAffineAnim_Battler_HorizontalSquishLoop,
    sAffineAnim_Battler_Grow,
    sAffineAnim_Battler_Shrink,
    sAffineAnim_Battler_SpinShrink,
    sAffineAnim_Battler_TipLeft,
    sAffineAnim_Battler_RotateUpAndBack,
    sAffineAnim_Battler_BigToSmall,
    sAffineAnim_Battler_Spin,
};

// 0x82D2F50
const union AffineAnimCmd *const gAffineAnims_BattleSpriteContest[] =
{
    sAffineAnim_Battler_Flipped,
    sAffineAnim_Battler_Emerge,
    sAffineAnim_Battler_Return,
    sAffineAnim_Battler_HorizontalSquishLoop,
    sAffineAnim_Battler_Grow,
    sAffineAnim_Battler_Shrink,
    sAffineAnim_Battler_SpinShrink,
    sAffineAnim_Battler_TipLeft,
    sAffineAnim_Battler_RotateUpAndBack,
    sAffineAnim_Battler_BigToSmall,
    sAffineAnim_Battler_Spin,
};

// 0x82D2F7C - mon-pic anims (referenced by the asm gAnims_MonPic table).
const union AnimCmd sAnim_MonPic_0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

const union AnimCmd sAnim_MonPic_1[] =
{
    ANIMCMD_FRAME(1, 0),
    ANIMCMD_END
};

const union AnimCmd sAnim_MonPic_2[] =
{
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_END
};

const union AnimCmd sAnim_MonPic_3[] =
{
    ANIMCMD_FRAME(3, 0),
    ANIMCMD_END
};
