#ifndef POKEEMERALD_JP_DODRIO2_H
#define POKEEMERALD_JP_DODRIO2_H

#include "global.h"
#include "dodrio_berry_picking.h"
#include "link.h"
#include "sprite.h"

// Dodrio sprite/rank data (0x82CEA6C..0x82CECF0)

extern const u8 gUnknown_85CCA7C[];        // JP text region (asm)
extern const u16 sDodrioNormalPal[];       // 0x82CB6BC (asm)
extern const u16 sDodrioShinyPal[];        // 0x82CB6DC (asm)
extern const u8 gUnknown_82CB6FC[];        // 0x82CB6FC: status pal + berry pal (asm)
extern const u32 sBerry_Gfx[];             // 0x82CB73C (asm); cloud pal is its last 0x20 bytes

void LoadGfx(void);
void ShowNames(void);
void sub_080295A4(void);
void Msg_WantToPlayAgain(void);
void Msg_SavingDontTurnOff(void);
void Msg_CommunicationStandby(void);
void EraseMessage(void);
void Msg_SomeoneDroppedOut(void);
void StopGfxFuncs(void);
void GfxIdle(void);
void SpriteCB_Cloud(struct Sprite *sprite);
void nullsub_15(void);

// 0x82CEA6C - the four OamData entries match pokeemerald's
// sOamData_Dodrio / sOamData_16x16_Priority0 / sOamData_Berry / sOamData_Cloud.
const struct OamData sOamData_Dodrio[] =
{
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
        .priority = 2,
        .paletteNum = 0,
        .affineParam = 0,
    },
    {
        .y = 0,
        .affineMode = ST_OAM_AFFINE_OFF,
        .objMode = ST_OAM_OBJ_NORMAL,
        .mosaic = FALSE,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(16x16),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(16x16),
        .tileNum = 0,
        .priority = 0,
        .paletteNum = 0,
        .affineParam = 0,
    },
    {
        .y = 0,
        .affineMode = ST_OAM_AFFINE_OFF,
        .objMode = ST_OAM_OBJ_NORMAL,
        .mosaic = FALSE,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(16x16),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(16x16),
        .tileNum = 0,
        .priority = 2,
        .paletteNum = 0,
        .affineParam = 0,
    },
    {
        .y = 0,
        .affineMode = ST_OAM_AFFINE_OFF,
        .objMode = ST_OAM_OBJ_NORMAL,
        .mosaic = FALSE,
        .bpp = ST_OAM_4BPP,
        .shape = SPRITE_SHAPE(64x32),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(64x32),
        .tileNum = 0,
        .priority = 3,
        .paletteNum = 0,
        .affineParam = 0,
    },
};

// 0x82CEA8C - dodrio head animations.
static const union AnimCmd sAnim_Dodrio_Normal[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd sAnim_Dodrio_PickRight[] =
{
    ANIMCMD_FRAME(64, 20),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd sAnim_Dodrio_PickMiddle[] =
{
    ANIMCMD_FRAME(128, 20),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd sAnim_Dodrio_PickLeft[] =
{
    ANIMCMD_FRAME(192, 20),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd sAnim_Dodrio_Down[] =
{
    ANIMCMD_FRAME(256, 20),
    ANIMCMD_JUMP(0)
};

// 0x82CEAB4
const union AnimCmd *const sAnims_Dodrio[] =
{
    sAnim_Dodrio_Normal,
    sAnim_Dodrio_PickRight,
    sAnim_Dodrio_PickMiddle,
    sAnim_Dodrio_PickLeft,
    sAnim_Dodrio_Down,
};

// 0x82CEAC8 - status bar animations.
static const union AnimCmd sAnims_StatusBar_Yellow[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd sAnims_StatusBar_Gray[] =
{
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd sAnims_StatusBar_Red[] =
{
    ANIMCMD_FRAME(8, 20),
    ANIMCMD_JUMP(0)
};

// 0x82CEAE0
static const union AnimCmd *const sAnims_StatusBar[] =
{
    sAnims_StatusBar_Yellow,
    sAnims_StatusBar_Gray,
    sAnims_StatusBar_Red,
};

// 0x82CEAEC - nine berry animations (JP game has nine berry tiles).
static const union AnimCmd sAnim_Berry_0[] = { ANIMCMD_FRAME(0, 20), ANIMCMD_JUMP(0) };
static const union AnimCmd sAnim_Berry_1[] = { ANIMCMD_FRAME(4, 20), ANIMCMD_JUMP(0) };
static const union AnimCmd sAnim_Berry_2[] = { ANIMCMD_FRAME(8, 20), ANIMCMD_JUMP(0) };
static const union AnimCmd sAnim_Berry_3[] = { ANIMCMD_FRAME(12, 20), ANIMCMD_JUMP(0) };
static const union AnimCmd sAnim_Berry_4[] = { ANIMCMD_FRAME(16, 20), ANIMCMD_JUMP(0) };
static const union AnimCmd sAnim_Berry_5[] = { ANIMCMD_FRAME(20, 20), ANIMCMD_JUMP(0) };
static const union AnimCmd sAnim_Berry_6[] = { ANIMCMD_FRAME(24, 20), ANIMCMD_JUMP(0) };
static const union AnimCmd sAnim_Berry_7[] = { ANIMCMD_FRAME(28, 20), ANIMCMD_JUMP(0) };
static const union AnimCmd sAnim_Berry_8[] = { ANIMCMD_FRAME(32, 20), ANIMCMD_JUMP(0) };

// 0x82CEB34
static const union AnimCmd *const sAnims_Berry[] =
{
    sAnim_Berry_0,
    sAnim_Berry_1,
    sAnim_Berry_2,
    sAnim_Berry_3,
    sAnim_Berry_4,
    sAnim_Berry_5,
    sAnim_Berry_6,
    sAnim_Berry_7,
    sAnim_Berry_8,
};

// 0x82CEB58
static const union AnimCmd sAnim_Cloud[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0)
};
static const union AnimCmd *const sAnims_Cloud[] = { sAnim_Cloud };

// 0x82CEB64
const struct SpritePalette sDodrioNormalSpritePalette =
{
    .data = sDodrioNormalPal,
    .tag = 0,
};
const struct SpritePalette sDodrioShinySpritePalette =
{
    .data = sDodrioShinyPal,
    .tag = 1,
};
const struct SpritePalette sStatusPalette =
{
    .data = (const u16 *)gUnknown_82CB6FC,
    .tag = 2,
};

// 0x82CEB7C
const struct SpriteTemplate sStatusSpriteTemplate =
{
    .tileTag = 1,
    .paletteTag = 2,
    .oam = &sOamData_Dodrio[1],
    .anims = sAnims_StatusBar,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = nullsub_15,
};

// 0x82CEB94 - unlabeled 12 bytes between the status template and sBerryPalette.
const u8 gUnknown_82CEB94[] =
{
    0xD4, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0xFB, 0x00, 0x00
};

// 0x82CEBA0 - berry palette data is the second half of gUnknown_82CB6FC.
const struct SpritePalette sBerryPalette =
{
    .data = (const u16 *)(gUnknown_82CB6FC + 0x20),
    .tag = 3,
};

// 0x82CEBA8
const s16 sBerryIconXCoords[NUM_BERRY_TYPES] = { 88, 128, 168, 208 };

// 0x82CEBB0
const struct SpriteTemplate sBerrySpriteTemplate =
{
    .tileTag = 2,
    .paletteTag = 3,
    .oam = &sOamData_Dodrio[2],
    .anims = sAnims_Berry,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// 0x82CEBC8
const struct SpriteTemplate sBerryIconSpriteTemplate =
{
    .tileTag = 2,
    .paletteTag = 3,
    .oam = &sOamData_Dodrio[1],
    .anims = sAnims_Berry,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// 0x82CEBE0
const u8 sCloudDurations[] = { 0x1E, 0x14 };

// 0x82CEBE2
const s16 sCloudPositions[NUM_CLOUDS][2] =
{
    { 230, 55 },
    { 30, 74 },
};

// 0x82CEBEA
const u8 gUnknown_82CEBEA[] = { 0x00, 0x00 };

// 0x82CEBEC - cloud palette data is the last 0x20 bytes of sBerry_Gfx.
const struct SpritePalette sCloudPalette =
{
    .data = (const u16 *)((const u8 *)sBerry_Gfx + 0x1B4),
    .tag = 6,
};

// 0x82CEBF4
const struct SpriteTemplate sCloudSpriteTemplate =
{
    .tileTag = 5,
    .paletteTag = 6,
    .oam = &sOamData_Dodrio[3],
    .anims = sAnims_Cloud,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Cloud,
};

// 0x82CEC0C
const u8 sDodrioTextColorTable[][3] =
{
    { 1, 2, 3 },
    { 1, 4, 5 },
    { 1, 8, 9 },
    { 1, 6, 7 },
};

// 0x82CEC18 - same values as pokeemerald; agbcc pads each WinCoords to 4 bytes.
const struct WinCoords sNameWindowCoords_1Player[] = { { 12, 6 } };
const struct WinCoords sNameWindowCoords_2Players[] = { { 9, 10 }, { 15, 6 } };
const struct WinCoords sNameWindowCoords_3Players[] = { { 12, 6 }, { 18, 10 }, { 6, 10 } };
const struct WinCoords sNameWindowCoords_4Players[] = { { 9, 10 }, { 15, 6 }, { 21, 10 }, { 3, 6 } };
const struct WinCoords sNameWindowCoords_5Players[] = { { 12, 6 }, { 18, 10 }, { 23, 6 }, { 1, 6 }, { 6, 10 } };

// 0x82CEC54
const struct WinCoords *const sNameWindowCoords[] =
{
    sNameWindowCoords_1Player,
    sNameWindowCoords_2Players,
    sNameWindowCoords_3Players,
    sNameWindowCoords_4Players,
    sNameWindowCoords_5Players,
};

// 0x82CEC68 - JP ranking number labels "1:".."5:" (mid94 text region).
const u8 *const sRankingTexts[] =
{
    gUnknown_85CCA7C + 0x2FB,
    gUnknown_85CCA7C + 0x2FE,
    gUnknown_85CCA7C + 0x301,
    gUnknown_85CCA7C + 0x304,
    gUnknown_85CCA7C + 0x307,
};

// 0x82CEC7C - JP values differ from US (last X coord 220 vs 212, Y coords differ).
const u16 sResultsXCoords[] = { 92, 132, 172, 220 };
const u16 sResultsYCoords[] = { 30, 45, 60, 75, 90 };
const u16 sRankingYCoords[] = { 12, 28, 44, 60, 76 };

// 0x82CEC98
const struct GfxFunc sGfxFuncs[] =
{
    { GFXFUNC_LOAD,              LoadGfx },
    { GFXFUNC_SHOW_NAMES,        ShowNames },
    { GFXFUNC_SHOW_RESULTS,      sub_080295A4 },
    { GFXFUNC_MSG_PLAY_AGAIN,    Msg_WantToPlayAgain },
    { GFXFUNC_MSG_SAVING,        Msg_SavingDontTurnOff },
    { GFXFUNC_MSG_COMM_STANDBY,  Msg_CommunicationStandby },
    { GFXFUNC_ERASE_MSG,         EraseMessage },
    { GFXFUNC_MSG_PLAYER_DROPPED, Msg_SomeoneDroppedOut },
    { GFXFUNC_STOP,              StopGfxFuncs },
    { GFXFUNC_IDLE,              GfxIdle },
};

// 0x82CECE8 - ranking display order (5 entries padded to 8 bytes).
const u8 sRankingOrder[] = { 0, 1, 2, 3, 4, 0, 0, 0 };

#endif // POKEEMERALD_JP_DODRIO2_H
