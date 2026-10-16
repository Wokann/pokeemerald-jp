#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "data.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "sprite.h"
#include "task.h"
#include "util.h"
#include "constants/battle_anim.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define BATTLE_ANIM_THROW_STATIC_DATA __attribute__((section(".rodata.battle_anim_throw_static_data")))
#define SPECIAL_FoundBlackGlasses 0x13B

struct CaptureStar
{
    s8 xOffset;
    s8 yOffset;
    s8 amplitude;
};

extern void PokeBallOpenParticleAnimation(u8 taskId);
extern u32 gUnknown_300601C;
extern u16 gUnknown_3006020;
extern u16 gUnknown_3006024;
extern bool8 gUnknown_202415D;
extern u32 sub_080A6E74(bool8, bool8, bool8, bool8, bool8, bool8, bool8);
extern u32 CosAsU32(s16 angle, s16 magnitude) __asm__("Cos");
extern void GreatBallOpenParticleAnimation(u8 taskId);
extern void SafariBallOpenParticleAnimation(u8 taskId);
extern void UltraBallOpenParticleAnimation(u8 taskId);
extern void MasterBallOpenParticleAnimation(u8 taskId);
extern void DiveBallOpenParticleAnimation(u8 taskId);
extern void RepeatBallOpenParticleAnimation(u8 taskId);
extern void TimerBallOpenParticleAnimation(u8 taskId);
extern void PremierBallOpenParticleAnimation(u8 taskId);
void SpriteCB_PokeBlock_Throw(struct Sprite *sprite);
void sub_08173180(struct Sprite *sprite);
void sub_081731B8(struct Sprite *sprite);
void sub_081731E4(struct Sprite *sprite);
void sub_08170CD4(u8 taskId);
void sub_08170E14(u8 taskId);
void sub_08170E8C(u8 taskId);
void sub_08170EE8(struct Sprite *sprite);
void sub_08170F18(struct Sprite *sprite);
void sub_08170FCC(struct Sprite *sprite);
void sub_08171024(struct Sprite *sprite);
void sub_08171170(struct Sprite *sprite);
void sub_081711B4(struct Sprite *sprite);
void sub_081712B8(struct Sprite *sprite);
void sub_08171304(struct Sprite *sprite);
void sub_08171598(struct Sprite *sprite);
void sub_081715DC(struct Sprite *sprite);
void sub_081716BC(struct Sprite *sprite);
void sub_081717D0(struct Sprite *sprite);
void sub_081717A4(struct Sprite *sprite);
void sub_08171890(struct Sprite *sprite);
void sub_081718C8(struct Sprite *sprite);
void sub_08171990(struct Sprite *sprite);
void sub_08171B44(u8 ballId);
void PokeBallOpenParticleAnimation_Step1(struct Sprite *sprite);
void PokeBallOpenParticleAnimation_Step2(struct Sprite *sprite);
void FanOutBallOpenParticles_Step1(struct Sprite *sprite);
void RepeatBallOpenParticleAnimation_Step1(struct Sprite *sprite);
void PremierBallOpenParticleAnimation_Step1(struct Sprite *sprite);
void DestroyBallOpenAnimationParticle(struct Sprite *sprite);
extern const struct SpriteTemplate gWishStarSpriteTemplate;
extern const struct SpriteTemplate gMiniTwinklingStarSpriteTemplate;
extern void sub_080A4044(bool8 toBG2);
extern void sub_080A63F8(struct BattleAnimBgData *out);
void sub_08171A90(struct Sprite *sprite);
void sub_08171ACC(struct Sprite *sprite);
void sub_08170618(u8 *paletteId1, u8 *paletteId2, u8 battler);
void sub_0817081C(u8 taskId);

BATTLE_ANIM_THROW_STATIC_DATA static const struct CaptureStar sCaptureStars[] =
{
    {
        .xOffset = 10,
        .yOffset = 2,
        .amplitude = -3,
    },
    {
        .xOffset = 15,
        .yOffset = 0,
        .amplitude = -4,
    },
    {
        .xOffset = -10,
        .yOffset = 2,
        .amplitude = -4,
    },
};

#define TAG_PARTICLES_POKEBALL    55020
#define TAG_PARTICLES_GREATBALL   55021
#define TAG_PARTICLES_SAFARIBALL  55022
#define TAG_PARTICLES_ULTRABALL   55023
#define TAG_PARTICLES_MASTERBALL  55024
#define TAG_PARTICLES_NETBALL     55025
#define TAG_PARTICLES_DIVEBALL    55026
#define TAG_PARTICLES_NESTBALL    55027
#define TAG_PARTICLES_REPEATBALL  55028
#define TAG_PARTICLES_TIMERBALL   55029
#define TAG_PARTICLES_LUXURYBALL  55030
#define TAG_PARTICLES_PREMIERBALL 55031

BATTLE_ANIM_THROW_STATIC_DATA static const struct CompressedSpriteSheet sBallParticleSpriteSheets[POKEBALL_COUNT] =
{
    [BALL_POKE]    = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_POKEBALL},
    [BALL_GREAT]   = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_GREATBALL},
    [BALL_SAFARI]  = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_SAFARIBALL},
    [BALL_ULTRA]   = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_ULTRABALL},
    [BALL_MASTER]  = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_MASTERBALL},
    [BALL_NET]     = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_NETBALL},
    [BALL_DIVE]    = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_DIVEBALL},
    [BALL_NEST]    = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_NESTBALL},
    [BALL_REPEAT]  = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_REPEATBALL},
    [BALL_TIMER]   = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_TIMERBALL},
    [BALL_LUXURY]  = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_LUXURYBALL},
    [BALL_PREMIER] = {gBattleAnimSpriteGfx_Particles, 0x100, TAG_PARTICLES_PREMIERBALL},
};

BATTLE_ANIM_THROW_STATIC_DATA static const struct CompressedSpritePalette sBallParticlePalettes[POKEBALL_COUNT] =
{
    [BALL_POKE]    = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_POKEBALL},
    [BALL_GREAT]   = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_GREATBALL},
    [BALL_SAFARI]  = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_SAFARIBALL},
    [BALL_ULTRA]   = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_ULTRABALL},
    [BALL_MASTER]  = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_MASTERBALL},
    [BALL_NET]     = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_NETBALL},
    [BALL_DIVE]    = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_DIVEBALL},
    [BALL_NEST]    = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_NESTBALL},
    [BALL_REPEAT]  = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_REPEATBALL},
    [BALL_TIMER]   = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_TIMERBALL},
    [BALL_LUXURY]  = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_LUXURYBALL},
    [BALL_PREMIER] = {gBattleAnimSpritePal_CircleImpact, TAG_PARTICLES_PREMIERBALL},
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd sAnim_RegularBall[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(0, 1, .hFlip = TRUE),
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_JUMP(0),
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd sAnim_MasterBall[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END,
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd sAnim_NetDiveBall[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END,
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd sAnim_NestBall[] =
{
    ANIMCMD_FRAME(5, 1),
    ANIMCMD_END,
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd sAnim_LuxuryPremierBall[] =
{
    ANIMCMD_FRAME(6, 4),
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_JUMP(0),
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd sAnim_UltraRepeatTimerBall[] =
{
    ANIMCMD_FRAME(7, 4),
    ANIMCMD_END,
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd *const sAnims_BallParticles[] =
{
    sAnim_RegularBall,
    sAnim_MasterBall,
    sAnim_NetDiveBall,
    sAnim_NestBall,
    sAnim_LuxuryPremierBall,
    sAnim_UltraRepeatTimerBall,
};

BATTLE_ANIM_THROW_STATIC_DATA static const u8 sBallParticleAnimNums[POKEBALL_COUNT] =
{
    [BALL_POKE]    = 0,
    [BALL_GREAT]   = 0,
    [BALL_SAFARI]  = 0,
    [BALL_ULTRA]   = 5,
    [BALL_MASTER]  = 1,
    [BALL_NET]     = 2,
    [BALL_DIVE]    = 2,
    [BALL_NEST]    = 3,
    [BALL_REPEAT]  = 5,
    [BALL_TIMER]   = 5,
    [BALL_LUXURY]  = 4,
    [BALL_PREMIER] = 4,
};

BATTLE_ANIM_THROW_STATIC_DATA static const TaskFunc sBallParticleAnimationFuncs[POKEBALL_COUNT] =
{
    [BALL_POKE]    = PokeBallOpenParticleAnimation,
    [BALL_GREAT]   = GreatBallOpenParticleAnimation,
    [BALL_SAFARI]  = SafariBallOpenParticleAnimation,
    [BALL_ULTRA]   = UltraBallOpenParticleAnimation,
    [BALL_MASTER]  = MasterBallOpenParticleAnimation,
    [BALL_NET]     = SafariBallOpenParticleAnimation,
    [BALL_DIVE]    = DiveBallOpenParticleAnimation,
    [BALL_NEST]    = UltraBallOpenParticleAnimation,
    [BALL_REPEAT]  = RepeatBallOpenParticleAnimation,
    [BALL_TIMER]   = TimerBallOpenParticleAnimation,
    [BALL_LUXURY]  = GreatBallOpenParticleAnimation,
    [BALL_PREMIER] = PremierBallOpenParticleAnimation,
};

BATTLE_ANIM_THROW_STATIC_DATA static const struct SpriteTemplate sBallParticleSpriteTemplates[POKEBALL_COUNT] =
{
    [BALL_POKE] = {
        .tileTag = TAG_PARTICLES_POKEBALL,
        .paletteTag = TAG_PARTICLES_POKEBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_GREAT] = {
        .tileTag = TAG_PARTICLES_GREATBALL,
        .paletteTag = TAG_PARTICLES_GREATBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_SAFARI] = {
        .tileTag = TAG_PARTICLES_SAFARIBALL,
        .paletteTag = TAG_PARTICLES_SAFARIBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_ULTRA] = {
        .tileTag = TAG_PARTICLES_ULTRABALL,
        .paletteTag = TAG_PARTICLES_ULTRABALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_MASTER] = {
        .tileTag = TAG_PARTICLES_MASTERBALL,
        .paletteTag = TAG_PARTICLES_MASTERBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_NET] = {
        .tileTag = TAG_PARTICLES_NETBALL,
        .paletteTag = TAG_PARTICLES_NETBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_DIVE] = {
        .tileTag = TAG_PARTICLES_DIVEBALL,
        .paletteTag = TAG_PARTICLES_DIVEBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_NEST] = {
        .tileTag = TAG_PARTICLES_NESTBALL,
        .paletteTag = TAG_PARTICLES_NESTBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_REPEAT] = {
        .tileTag = TAG_PARTICLES_REPEATBALL,
        .paletteTag = TAG_PARTICLES_REPEATBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_TIMER] = {
        .tileTag = TAG_PARTICLES_TIMERBALL,
        .paletteTag = TAG_PARTICLES_TIMERBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_LUXURY] = {
        .tileTag = TAG_PARTICLES_LUXURYBALL,
        .paletteTag = TAG_PARTICLES_LUXURYBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
    [BALL_PREMIER] = {
        .tileTag = TAG_PARTICLES_PREMIERBALL,
        .paletteTag = TAG_PARTICLES_PREMIERBALL,
        .oam = &gOamData_AffineOff_ObjNormal_8x8,
        .anims = sAnims_BallParticles,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
};

BATTLE_ANIM_THROW_STATIC_DATA const u16 gBallOpenFadeColors[] =
{
    [BALL_POKE] = RGB(31, 22, 30),
    [BALL_GREAT] = RGB(16, 23, 30),
    [BALL_SAFARI] = RGB(23, 30, 20),
    [BALL_ULTRA] = RGB(31, 31, 15),
    [BALL_MASTER] = RGB(23, 20, 28),
    [BALL_NET] = RGB(21, 31, 25),
    [BALL_DIVE] = RGB(12, 25, 30),
    [BALL_NEST] = RGB(30, 27, 10),
    [BALL_REPEAT] = RGB(31, 24, 16),
    [BALL_TIMER] = RGB(29, 30, 30),
    [BALL_LUXURY] = RGB(31, 17, 10),
    [BALL_PREMIER] = RGB(31, 9, 10),

    // ROM-resident unused values immediately following the Poké Ball colours.
    RGB_BLACK,
    RGB(1, 16, 0),
    RGB(3, 0, 1),
    RGB(1, 8, 0),
    RGB(0, 8, 0),
    RGB(3, 8, 1),
    RGB(6, 8, 1),
    RGB(4, 0, 0),
};

BATTLE_ANIM_THROW_STATIC_DATA const struct SpriteTemplate gPokeblockSpriteTemplate =
{
    .tileTag = ANIM_TAG_POKEBLOCK,
    .paletteTag = ANIM_TAG_POKEBLOCK,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PokeBlock_Throw,
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd sAnim_SafariRock[] =
{
    ANIMCMD_FRAME(64, 1),
    ANIMCMD_END,
};

BATTLE_ANIM_THROW_STATIC_DATA static const union AnimCmd *const sAnims_SafariRock[] =
{
    sAnim_SafariRock,
};

BATTLE_ANIM_THROW_STATIC_DATA static const struct SpriteTemplate sSafariRockSpriteTemplate =
{
    .tileTag = ANIM_TAG_ROCKS,
    .paletteTag = ANIM_TAG_ROCKS,
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_SafariRock,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PokeBlock_Throw,
};

void sub_08170444(u8 taskId);

void unref_sub_8170478(u8 taskId)
{
    struct BattleAnimBgData animBgData;
    u8 healthBoxSpriteId;
    u8 battler;
    u8 spriteId1;
    u8 spriteId2;
    u8 spriteId3;
    u8 spriteId4;

    battler = gBattleAnimAttacker;
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 0);
    SetAnimBgAttribute(1, BG_ANIM_SCREEN_SIZE, 0);
    SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 1);
    SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 1);

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];
    spriteId3 = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    spriteId4 = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    gSprites[healthBoxSpriteId].oam.priority = 1;
    gSprites[spriteId1].oam.priority = 1;
    gSprites[spriteId2].oam.priority = 1;
    gSprites[spriteId3] = gSprites[healthBoxSpriteId];
    gSprites[spriteId4] = gSprites[spriteId1];
    gSprites[spriteId3].oam.objMode = ST_OAM_OBJ_WINDOW;
    gSprites[spriteId4].oam.objMode = ST_OAM_OBJ_WINDOW;
    gSprites[spriteId3].callback = SpriteCallbackDummy;
    gSprites[spriteId4].callback = SpriteCallbackDummy;

    sub_080A63F8(&animBgData);
    AnimLoadCompressedBgTilemap(animBgData.bgId, UnusedLevelupAnimationTilemap);
    AnimLoadCompressedBgGfx(animBgData.bgId, UnusedLevelupAnimationGfx, animBgData.tilesOffset);
    LoadCompressedPalette(gCureBubblesPal, BG_PLTT_ID(animBgData.paletteId), PLTT_SIZE_4BPP);

    gBattle_BG1_X = -gSprites[spriteId3].x + 32;
    gBattle_BG1_Y = -gSprites[spriteId3].y - 32;
    gTasks[taskId].data[1] = 640;
    gTasks[taskId].data[0] = spriteId3;
    gTasks[taskId].data[2] = spriteId4;
    gTasks[taskId].func = sub_08170444;
}

void sub_08170444(u8 taskId)
{
    u8 spriteId1;
    u8 spriteId2;
    u8 battler;

    battler = gBattleAnimAttacker;
    gTasks[taskId].data[13] += gTasks[taskId].data[1];
    gBattle_BG1_Y += (u16)gTasks[taskId].data[13] >> 8;
    gTasks[taskId].data[13] &= 0xFF;

    switch (gTasks[taskId].data[15])
    {
    case 0:
        if (gTasks[taskId].data[11]++ > 1)
        {
            gTasks[taskId].data[11] = 0;
            gTasks[taskId].data[12]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[12], 16 - gTasks[taskId].data[12]));
            if (gTasks[taskId].data[12] == 8)
                gTasks[taskId].data[15]++;
        }
        break;
    case 1:
        if (++gTasks[taskId].data[10] == 30)
            gTasks[taskId].data[15]++;
        break;
    case 2:
        if (gTasks[taskId].data[11]++ > 1)
        {
            gTasks[taskId].data[11] = 0;
            gTasks[taskId].data[12]--;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[12], 16 - gTasks[taskId].data[12]));
            if (gTasks[taskId].data[12] == 0)
            {
                sub_080A4044(FALSE);
                gBattle_WIN0H = 0;
                gBattle_WIN0V = 0;
                SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
                SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
                if (!IsContest())
                    SetAnimBgAttribute(1, BG_ANIM_CHAR_BASE_BLOCK, 0);

                SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) ^ DISPCNT_OBJWIN_ON);
                SetGpuReg(REG_OFFSET_BLDCNT, 0);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
                DestroySprite(&gSprites[gTasks[taskId].data[0]]);
                DestroySprite(&gSprites[gTasks[taskId].data[2]]);
                SetAnimBgAttribute(1, BG_ANIM_AREA_OVERFLOW_MODE, 0);
                spriteId1 = gSprites[gHealthboxSpriteIds[battler]].oam.affineParam;
                spriteId2 = gSprites[gHealthboxSpriteIds[battler]].data[5];
                gSprites[gHealthboxSpriteIds[battler]].oam.priority = 1;
                gSprites[spriteId1].oam.priority = 1;
                gSprites[spriteId2].oam.priority = 1;
                DestroyAnimVisualTask(taskId);
            }
        }
        break;
    }
}

void sub_08170618(u8 *paletteId1, u8 *paletteId2, u8 battler)
{
    u8 healthBoxSpriteId;
    u8 spriteId1;
    u8 spriteId2;
    u16 offset1;
    u16 offset2;

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];
    *paletteId1 = AllocSpritePalette(TAG_HEALTHBOX_PALS_1);
    *paletteId2 = AllocSpritePalette(TAG_HEALTHBOX_PALS_2);

    offset1 = OBJ_PLTT_ID(gSprites[healthBoxSpriteId].oam.paletteNum);
    offset2 = OBJ_PLTT_ID(gSprites[spriteId2].oam.paletteNum);
    LoadPalette(&gPlttBufferUnfaded[offset1], OBJ_PLTT_ID(*paletteId1), PLTT_SIZE_4BPP);
    LoadPalette(&gPlttBufferUnfaded[offset2], OBJ_PLTT_ID(*paletteId2), PLTT_SIZE_4BPP);

    gSprites[healthBoxSpriteId].oam.paletteNum = *paletteId1;
    gSprites[spriteId1].oam.paletteNum = *paletteId1;
    gSprites[spriteId2].oam.paletteNum = *paletteId2;
}

void AnimTask_LoadHealthboxPalsForLevelUp(u8 taskId)
{
    u8 paletteId1;
    u8 paletteId2;

    sub_08170618(&paletteId1, &paletteId2, gBattleAnimAttacker);
    DestroyAnimVisualTask(taskId);
}

void sub_08170730(u8 battler)
{
    u8 healthBoxSpriteId;
    u8 spriteId1;
    u8 spriteId2;
    u8 paletteId1;
    u8 paletteId2;

    healthBoxSpriteId = gHealthboxSpriteIds[battler];
    spriteId1 = gSprites[healthBoxSpriteId].oam.affineParam;
    spriteId2 = gSprites[healthBoxSpriteId].data[5];

    FreeSpritePaletteByTag(TAG_HEALTHBOX_PALS_1);
    FreeSpritePaletteByTag(TAG_HEALTHBOX_PALS_2);
    paletteId1 = IndexOfSpritePaletteTag(TAG_HEALTHBOX_PAL);
    paletteId2 = IndexOfSpritePaletteTag(TAG_HEALTHBAR_PAL);
    gSprites[healthBoxSpriteId].oam.paletteNum = paletteId1;
    gSprites[spriteId1].oam.paletteNum = paletteId1;
    gSprites[spriteId2].oam.paletteNum = paletteId2;
}

void AnimTask_FreeHealthboxPalsForLevelUp(u8 taskId)
{
    sub_08170730(gBattleAnimAttacker);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_FlashHealthboxOnLevelUp(u8 taskId)
{
    gTasks[taskId].data[10] = gBattleAnimArgs[0];
    gTasks[taskId].data[11] = gBattleAnimArgs[1];
    gTasks[taskId].func = sub_0817081C;
}

void sub_0817081C(u8 taskId)
{
    u8 paletteNum;
    u32 paletteOffset;
    u32 colorOffset;

    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0]++ >= gTasks[taskId].data[11])
    {
        gTasks[taskId].data[0] = 0;
        paletteNum = IndexOfSpritePaletteTag(TAG_HEALTHBOX_PALS_1);
        colorOffset = gTasks[taskId].data[10] == 0 ? 6 : 2;
        switch (gTasks[taskId].data[1])
        {
        case 0:
            gTasks[taskId].data[2] += 2;
            if (gTasks[taskId].data[2] > 16)
                gTasks[taskId].data[2] = 16;

            paletteOffset = OBJ_PLTT_ID(paletteNum);
            BlendPalette(paletteOffset + colorOffset, 1, gTasks[taskId].data[2], RGB(20, 27, 31));
            if (gTasks[taskId].data[2] == 16)
                gTasks[taskId].data[1]++;
            break;
        case 1:
            gTasks[taskId].data[2] -= 2;
            if (gTasks[taskId].data[2] < 0)
                gTasks[taskId].data[2] = 0;

            paletteOffset = OBJ_PLTT_ID(paletteNum);
            BlendPalette(paletteOffset + colorOffset, 1, gTasks[taskId].data[2], RGB(20, 27, 31));
            if (gTasks[taskId].data[2] == 0)
                DestroyAnimVisualTask(taskId);
            break;
        }
    }
}

void AnimTask_SwitchOutShrinkMon(u8 taskId)
{
    u8 spriteId;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    switch (gTasks[taskId].data[0])
    {
    case 0:
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        gTasks[taskId].data[10] = 0x100;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[10] += 0x30;
        SetSpriteRotScale(spriteId, gTasks[taskId].data[10], gTasks[taskId].data[10], 0);
        SetBattlerSpriteYOffsetFromYScale(spriteId);
        if (gTasks[taskId].data[10] >= 0x2D0)
            gTasks[taskId].data[0]++;
        break;
    case 2:
        ResetSpriteRotScale(spriteId);
        gSprites[spriteId].invisible = TRUE;
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_SwitchOutBallEffect(u8 taskId)
{
    u8 spriteId;
    u16 ball;
    u8 ballId;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u32 selectedPalettes;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        ball = GetMonData3(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_POKEBALL);
    else
        ball = GetMonData3(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimAttacker]], MON_DATA_POKEBALL);

    ballId = ItemIdToBallId(ball);
    switch (gTasks[taskId].data[0])
    {
    case 0:
        x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
        priority = gSprites[spriteId].oam.priority;
        subpriority = gSprites[spriteId].subpriority;
        gTasks[taskId].data[10] = AnimateBallOpenParticles(x, y + 32, priority, subpriority, ballId);
        selectedPalettes = sub_080A6E74(TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
        gTasks[taskId].data[11] = LaunchBallFadeMonTask(FALSE, gBattleAnimAttacker, selectedPalettes, ballId);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!gTasks[gTasks[taskId].data[10]].isActive && !gTasks[gTasks[taskId].data[11]].isActive)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_LoadBallGfx(u8 taskId)
{
    u8 ballId = ItemIdToBallId(gLastUsedItem);

    LoadBallGfx(ballId);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_FreeBallGfx(u8 taskId)
{
    u8 ballId = ItemIdToBallId(gLastUsedItem);

    FreeBallGfx(ballId);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_IsBallBlockedByTrainer(u8 taskId)
{
    if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_TRAINER_BLOCK)
        gBattleAnimArgs[ARG_RET_ID] = -1;
    else
        gBattleAnimArgs[ARG_RET_ID] = 0;

    DestroyAnimVisualTask(taskId);
}

u8 ItemIdToBallId(u16 ballItem)
{
    switch (ballItem)
    {
    case ITEM_MASTER_BALL:
        return BALL_MASTER;
    case ITEM_ULTRA_BALL:
        return BALL_ULTRA;
    case ITEM_GREAT_BALL:
        return BALL_GREAT;
    case ITEM_SAFARI_BALL:
        return BALL_SAFARI;
    case ITEM_NET_BALL:
        return BALL_NET;
    case ITEM_DIVE_BALL:
        return BALL_DIVE;
    case ITEM_NEST_BALL:
        return BALL_NEST;
    case ITEM_REPEAT_BALL:
        return BALL_REPEAT;
    case ITEM_TIMER_BALL:
        return BALL_TIMER;
    case ITEM_LUXURY_BALL:
        return BALL_LUXURY;
    case ITEM_PREMIER_BALL:
        return BALL_PREMIER;
    case ITEM_POKE_BALL:
    default:
        return BALL_POKE;
    }
}

void AnimTask_ThrowBall(u8 taskId)
{
    u8 ballId;
    u8 spriteId;

    ballId = ItemIdToBallId(gLastUsedItem);
    spriteId = CreateSprite(&gBallSpriteTemplates[ballId], 32, 80, 29);
    gSprites[spriteId].data[0] = 34;
    gSprites[spriteId].data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    gSprites[spriteId].data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) - 16;
    gSprites[spriteId].callback = sub_08170EE8;
    gBattleSpritesDataPtr->animationData->wildMonInvisible = gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible;
    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].func = sub_08170CD4;
}

void sub_08170CD4(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[0];

    if ((u16)gSprites[spriteId].data[0] == 0xFFFF)
        DestroyAnimVisualTask(taskId);
}

void AnimTask_ThrowBall_StandingTrainer(u8 taskId)
{
    s16 x;
    s16 y;
    u8 ballId;
    u8 subpriority;
    u8 spriteId;

    if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
    {
        x = 32;
        y = 11;
    }
    else
    {
        x = 23;
        y = 5;
    }

    ballId = ItemIdToBallId(gLastUsedItem);
    subpriority = GetBattlerSpriteSubpriority(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)) + 1;
    spriteId = CreateSprite(&gBallSpriteTemplates[ballId], x + 32, y | 80, subpriority);
    gSprites[spriteId].data[0] = 34;
    gSprites[spriteId].data[1] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    gSprites[spriteId].data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) - 16;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].callback = SpriteCB_TrainerThrowObject;
    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].func = sub_08170E14;
}

void sub_08170E14(u8 taskId)
{
    if (gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].animCmdIndex == 1)
    {
        PlaySE12WithPanning(SE_BALL_THROW, 0);
        gSprites[gTasks[taskId].data[0]].callback = sub_08170EE8;
        CreateTask(sub_08170E8C, 10);
        gTasks[taskId].func = sub_08170CD4;
    }
}

void sub_08170E8C(u8 taskId)
{
    if (gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]].animEnded)
    {
        StartSpriteAnim(&gSprites[gBattlerSpriteIds[GetBattlerAtPosition(B_POSITION_PLAYER_LEFT)]], 0);
        DestroyTask(taskId);
    }
}

void sub_08170EE8(struct Sprite *sprite)
{
    u16 targetX = sprite->data[1];
    u16 targetY = sprite->data[2];

    sprite->data[1] = sprite->x;
    sprite->data[2] = targetX;
    sprite->data[3] = sprite->y;
    sprite->data[4] = targetY;
    sprite->data[5] = -40;
    InitAnimArcTranslation(sprite);
    sprite->callback = sub_08170F18;
}

void sub_08170F18(struct Sprite *sprite)
{
    s32 i;
    u8 ballId;

    if (TranslateAnimHorizontalArc(sprite))
    {
        if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == BALL_TRAINER_BLOCK)
        {
            sprite->callback = sub_08171A90;
        }
        else
        {
            StartSpriteAnim(sprite, 1);
            sprite->x += sprite->x2;
            sprite->y += sprite->y2;
            sprite->x2 = 0;
            sprite->y2 = 0;

            for (i = 0; i < 8; i++)
                sprite->data[i] = 0;

            sprite->data[5] = 0;
            sprite->callback = sub_08170FCC;

            ballId = ItemIdToBallId(gLastUsedItem);
            switch (ballId)
            {
            case 0 ... POKEBALL_COUNT - 1:
                AnimateBallOpenParticles(sprite->x, sprite->y - 5, 1, 28, ballId);
                LaunchBallFadeMonTask(FALSE, gBattleAnimTarget, 14, ballId);
                break;
            }
        }
    }
}

void sub_08170FCC(struct Sprite *sprite)
{
    if (++sprite->data[5] == 10)
    {
        sprite->data[5] = CreateTask(TaskDummy, 50);
        sprite->callback = sub_08171024;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] = 0;
    }
}

void sub_08171024(struct Sprite *sprite)
{
    u8 battlerSpriteId;
    u8 taskId;

    battlerSpriteId = gBattlerSpriteIds[gBattleAnimTarget];
    taskId = sprite->data[5];

    if (++gTasks[taskId].data[1] == 11)
        PlaySE(SE_BALL_TRADE);

    switch (gTasks[taskId].data[0])
    {
    case 0:
        PrepareBattlerSpriteForRotScale(battlerSpriteId, 0);
        gTasks[taskId].data[10] = 0x100;
        gUnknown_300601C = 28;
        gUnknown_3006024 = gSprites[battlerSpriteId].y + gSprites[battlerSpriteId].y2
                           - (sprite->y + sprite->y2);
        gUnknown_3006020 = ((u32)gUnknown_3006024 << 8) / 28;
        gTasks[taskId].data[2] = gUnknown_3006020;
        gTasks[taskId].data[0]++;
        break;
    case 1:
        gTasks[taskId].data[10] += 32;
        SetSpriteRotScale(battlerSpriteId, gTasks[taskId].data[10], gTasks[taskId].data[10], 0);
        gTasks[taskId].data[3] += gTasks[taskId].data[2];
        gSprites[battlerSpriteId].y2 = -gTasks[taskId].data[3] >> 8;
        if (gTasks[taskId].data[10] > 0x47F)
            gTasks[taskId].data[0]++;
        break;
    case 2:
        ResetSpriteRotScale(battlerSpriteId);
        gSprites[battlerSpriteId].invisible = TRUE;
        gTasks[taskId].data[0]++;
        break;
    default:
        if (gTasks[taskId].data[1] > 10)
        {
            DestroyTask(taskId);
            StartSpriteAnim(sprite, 2);
            sprite->data[5] = 0;
            sprite->callback = sub_08171170;
        }
        break;
    }
}

void sub_08171170(struct Sprite *sprite)
{
    s16 phase;
    u32 yOffset;

    if (sprite->animEnded)
    {
        sprite->data[3] = 0;
        sprite->data[4] = 40;
        sprite->data[5] = 0;
        phase = 0;
        yOffset = CosAsU32(phase, 40);
        yOffset += (u16)sprite->y;
        sprite->y = yOffset;
        sprite->y2 = -Cos(phase, sprite->data[4]);
        sprite->callback = sub_081711B4;
    }
}

void sub_081711B4(struct Sprite *sprite)
{
    bool8 r5 = FALSE;
    u32 yOffset;

    switch (sprite->data[3] & 0xFF)
    {
    case 0:
        sprite->y2 = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] += 4 + (sprite->data[3] >> 8);
        if (sprite->data[5] >= 64)
        {
            sprite->data[4] -= 10;
            sprite->data[3] += 0x101;
            if (sprite->data[3] >> 8 == 4)
                r5 = TRUE;

            switch (sprite->data[3] >> 8)
            {
            case 1:
                PlaySE(SE_BALL_BOUNCE_1);
                break;
            case 2:
                PlaySE(SE_BALL_BOUNCE_2);
                break;
            case 3:
                PlaySE(SE_BALL_BOUNCE_3);
                break;
            default:
                PlaySE(SE_BALL_BOUNCE_4);
                break;
            }
        }
        break;
    case 1:
        sprite->y2 = -Cos(sprite->data[5], sprite->data[4]);
        sprite->data[5] -= 4 + (sprite->data[3] >> 8);
        if (sprite->data[5] <= 0)
        {
            sprite->data[5] = 0;
            sprite->data[3] &= 0xFF00;
        }
        break;
    }

    if (r5)
    {
        sprite->data[3] = 0;
        yOffset = CosAsU32(64, 40);
        yOffset += (u16)sprite->y;
        sprite->y = yOffset;
        sprite->y2 = 0;
        if (gBattleSpritesDataPtr->animationData->ballThrowCaseId == 0)
        {
            sprite->data[5] = 0;
            sprite->callback = sub_08171598;
        }
        else
        {
            sprite->callback = sub_081712B8;
            sprite->data[4] = 1;
            sprite->data[5] = 0;
        }
    }
}

void sub_081712B8(struct Sprite *sprite)
{
    if (++sprite->data[3] == 31)
    {
        sprite->data[3] = 0;
        sprite->affineAnimPaused = TRUE;
        StartSpriteAffineAnim(sprite, 1);
        gBattleSpritesDataPtr->animationData->ballSubpx = 0;
        sprite->callback = sub_08171304;
        PlaySE(SE_BALL);
    }
}

// JP-specific seven-state capture/shake protocol uses ballSubpx. The US counterpart
// has a different state layout, so retain this naked implementation pending an exact match.
__attribute__((naked)) void sub_08171304(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	movs r1, #0xff\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #6\n\t"
        "	bls _08171314\n\t"
        "	b _0817154C\n\t"
        "_08171314:\n\t"
        "	lsls r0, r1, #2\n\t"
        "	ldr r1, _08171320\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_08171320: .4byte _08171324\n\t"
        "_08171324:\n\t"
        "	.4byte _08171340\n\t"
        "	.4byte _08171392\n\t"
        "	.4byte _081713D8\n\t"
        "	.4byte _08171438\n\t"
        "	.4byte _08171488\n\t"
        "	.4byte _081714EC\n\t"
        "	.4byte _0817154C\n\t"
        "_08171340:\n\t"
        "	ldr r1, _08171364\n\t"
        "	ldr r5, [r1]\n\t"
        "	ldr r2, [r5, #8]\n\t"
        "	ldrh r3, [r2, #0xc]\n\t"
        "	movs r6, #0xc\n\t"
        "	ldrsh r0, [r2, r6]\n\t"
        "	adds r6, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	ble _08171368\n\t"
        "	ldrh r0, [r4, #0x36]\n\t"
        "	ldrh r1, [r4, #0x24]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r4, #0x24]\n\t"
        "	ldr r1, [r5, #8]\n\t"
        "	ldrb r0, [r1, #0xc]\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	b _0817136E\n\t"
        "	.align 2, 0\n\t"
        "_08171364: .4byte gBattleSpritesDataPtr\n\t"
        "_08171368:\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xb0\n\t"
        "	strh r0, [r2, #0xc]\n\t"
        "_0817136E:\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #1\n\t"
        "	movs r3, #0\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #7\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xe\n\t"
        "	bhi _08171390\n\t"
        "	b _08171592\n\t"
        "_08171390:\n\t"
        "	b _08171428\n\t"
        "_08171392:\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08171444\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	ldrh r0, [r4, #0x36]\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r4, #0x36]\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r6, #0x36\n\t"
        "	ldrsh r0, [r4, r6]\n\t"
        "	cmp r0, #0\n\t"
        "	bge _081713CE\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #2\n\t"
        "	bl ChangeSpriteAffineAnim\n\t"
        "	b _08171592\n\t"
        "_081713CE:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ChangeSpriteAffineAnim\n\t"
        "	b _08171592\n\t"
        "_081713D8:\n\t"
        "	ldr r1, _081713FC\n\t"
        "	ldr r5, [r1]\n\t"
        "	ldr r2, [r5, #8]\n\t"
        "	ldrh r3, [r2, #0xc]\n\t"
        "	movs r6, #0xc\n\t"
        "	ldrsh r0, [r2, r6]\n\t"
        "	adds r6, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	ble _08171400\n\t"
        "	ldrh r0, [r4, #0x36]\n\t"
        "	ldrh r1, [r4, #0x24]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r4, #0x24]\n\t"
        "	ldr r1, [r5, #8]\n\t"
        "	ldrb r0, [r1, #0xc]\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	b _08171406\n\t"
        "	.align 2, 0\n\t"
        "_081713FC: .4byte gBattleSpritesDataPtr\n\t"
        "_08171400:\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xb0\n\t"
        "	strh r0, [r2, #0xc]\n\t"
        "_08171406:\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #1\n\t"
        "	movs r3, #0\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #0xc\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x18\n\t"
        "	bhi _08171428\n\t"
        "	b _08171592\n\t"
        "_08171428:\n\t"
        "	ldr r0, [r6]\n\t"
        "	ldr r0, [r0, #8]\n\t"
        "	strh r3, [r0, #0xc]\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	strh r3, [r4, #0x38]\n\t"
        "	b _08171592\n\t"
        "_08171438:\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r1, r0, #1\n\t"
        "	strh r1, [r4, #0x38]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08171452\n\t"
        "_08171444:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	b _08171592\n\t"
        "_08171452:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	ldrh r0, [r4, #0x36]\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r4, #0x36]\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r6, #0x36\n\t"
        "	ldrsh r0, [r4, r6]\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08171480\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #2\n\t"
        "	bl ChangeSpriteAffineAnim\n\t"
        "	b _08171488\n\t"
        "_08171480:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ChangeSpriteAffineAnim\n\t"
        "_08171488:\n\t"
        "	ldr r1, _081714AC\n\t"
        "	ldr r5, [r1]\n\t"
        "	ldr r2, [r5, #8]\n\t"
        "	ldrh r3, [r2, #0xc]\n\t"
        "	movs r6, #0xc\n\t"
        "	ldrsh r0, [r2, r6]\n\t"
        "	adds r6, r1, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	ble _081714B0\n\t"
        "	ldrh r0, [r4, #0x36]\n\t"
        "	ldrh r1, [r4, #0x24]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r4, #0x24]\n\t"
        "	ldr r1, [r5, #8]\n\t"
        "	ldrb r0, [r1, #0xc]\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	b _081714B6\n\t"
        "	.align 2, 0\n\t"
        "_081714AC: .4byte gBattleSpritesDataPtr\n\t"
        "_081714B0:\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xb0\n\t"
        "	strh r0, [r2, #0xc]\n\t"
        "_081714B6:\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #1\n\t"
        "	movs r3, #0\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #4\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #8\n\t"
        "	bls _08171592\n\t"
        "	ldr r0, [r6]\n\t"
        "	ldr r0, [r0, #8]\n\t"
        "	strh r3, [r0, #0xc]\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	strh r3, [r4, #0x38]\n\t"
        "	ldrh r0, [r4, #0x36]\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r4, #0x36]\n\t"
        "	b _08171592\n\t"
        "_081714EC:\n\t"
        "	movs r6, #0x80\n\t"
        "	lsls r6, r6, #1\n\t"
        "	adds r0, r6, #0\n\t"
        "	ldrh r1, [r4, #0x34]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r1, r0, #0x18\n\t"
        "	ldr r0, _0817151C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #8]\n\t"
        "	ldrb r0, [r0, #8]\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08171524\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x80\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r0, _08171520\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	b _08171592\n\t"
        "	.align 2, 0\n\t"
        "_0817151C: .4byte gBattleSpritesDataPtr\n\t"
        "_08171520: .4byte sub_08171598 + 1\n\t"
        "_08171524:\n\t"
        "	cmp r0, #4\n\t"
        "	bne _08171538\n\t"
        "	cmp r1, #3\n\t"
        "	bne _08171538\n\t"
        "	ldr r0, _08171534\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	b _0817153E\n\t"
        "	.align 2, 0\n\t"
        "_08171534: .4byte sub_081715BC + 1\n\t"
        "_08171538:\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "_0817153E:\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x80\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	b _08171592\n\t"
        "_0817154C:\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x1f\n\t"
        "	bne _08171592\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	ldrh r1, [r4, #0x34]\n\t"
        "	ldr r0, _08171580\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl StartSpriteAffineAnim\n\t"
        "	movs r6, #0x36\n\t"
        "	ldrsh r0, [r4, r6]\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08171584\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #2\n\t"
        "	bl StartSpriteAffineAnim\n\t"
        "	b _0817158C\n\t"
        "	.align 2, 0\n\t"
        "_08171580: .4byte 0xFFFFFF00\n\t"
        "_08171584:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl StartSpriteAffineAnim\n\t"
        "_0817158C:\n\t"
        "	movs r0, #0x17\n\t"
        "	bl PlaySE\n\t"
        "_08171592:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

void sub_08171598(struct Sprite *sprite)
{
    if (++sprite->data[5] == 31)
    {
        sprite->data[5] = 0;
        sprite->callback = sub_081718C8;
    }
}

void sub_081715BC(struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    sprite->callback = sub_081715DC;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

void sub_081715DC(struct Sprite *sprite)
{
    u8 *battler = &gBattleAnimTarget;

    sprite->data[4]++;
    if (sprite->data[4] == 40)
    {
        PlaySE(SE_RG_BALL_CLICK);
        BlendPalettes(0x10000 << sprite->oam.paletteNum, 6, RGB_BLACK);
        sub_081717D0(sprite);
    }
    else if (sprite->data[4] == 60)
    {
        BeginNormalPaletteFade(0x10000 << sprite->oam.paletteNum, 2, 6, 0, RGB_BLACK);
    }
    else if (sprite->data[4] == 95)
    {
        gUnknown_202415D = FALSE;
        UpdateOamPriorityInAllHealthboxes(1);
        m4aMPlayAllStop();
        PlaySE(MUS_RG_CAUGHT_INTRO);
    }
    else if (sprite->data[4] == SPECIAL_FoundBlackGlasses)
    {
        FreeOamMatrix(gSprites[gBattlerSpriteIds[*battler]].oam.matrixNum);
        DestroySprite(&gSprites[gBattlerSpriteIds[*battler]]);

        sprite->data[0] = 0;
        sprite->callback = sub_081716BC;
    }
}

void sub_081716BC(struct Sprite *sprite)
{
    u8 paletteIndex;

    switch (sprite->data[0])
    {
    case 0:
        sprite->data[1] = 0;
        sprite->data[2] = 0;
        sprite->oam.objMode = ST_OAM_OBJ_BLEND;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        paletteIndex = IndexOfSpritePaletteTag(sprite->template->paletteTag);
        BeginNormalPaletteFade(1 << (paletteIndex + 0x10), 0, 0, 16, RGB_WHITE);
        sprite->data[0]++;
        break;
    case 1:
        if (sprite->data[1]++ > 0)
        {
            sprite->data[1] = 0;
            sprite->data[2]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[2], sprite->data[2]));
            if (sprite->data[2] == 16)
                sprite->data[0]++;
        }
        break;
    case 2:
        sprite->invisible = TRUE;
        sprite->data[0]++;
        break;
    default:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            sprite->data[0] = 0;
            sprite->callback = sub_081717A4;
        }
        break;
    }
}

void sub_081717A4(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        sprite->data[0] = -1;
    }
    else
    {
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void sub_081717D0(struct Sprite *sprite)
{
    u32 i;
    u8 subpriority;

    if (sprite->subpriority)
    {
        subpriority = sprite->subpriority - 1;
    }
    else
    {
        subpriority = 0;
        sprite->subpriority = 1;
    }

    sub_08171B44(BALL_MASTER);
    for (i = 0; i < ARRAY_COUNT(sCaptureStars); i++)
    {
        u8 spriteId = CreateSprite(&sBallParticleSpriteTemplates[BALL_MASTER], sprite->x, sprite->y, subpriority);

        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[0] = 24;
            gSprites[spriteId].data[2] = sprite->x + sCaptureStars[i].xOffset;
            gSprites[spriteId].data[4] = sprite->y + sCaptureStars[i].yOffset;
            gSprites[spriteId].data[5] = sCaptureStars[i].amplitude;
            InitAnimArcTranslation(&gSprites[spriteId]);
            gSprites[spriteId].callback = sub_08171890;
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[BALL_MASTER]);
        }
    }
}

void sub_08171890(struct Sprite *sprite)
{
    sprite->invisible = !sprite->invisible;

    if (TranslateAnimHorizontalArc(sprite))
        DestroySprite(sprite);
}

void sub_081718C8(struct Sprite *sprite)
{
    u8 ballId;

    StartSpriteAnim(sprite, 1);
    StartSpriteAffineAnim(sprite, 0);
    sprite->callback = sub_08171990;

    ballId = ItemIdToBallId(gLastUsedItem);
    switch (ballId)
    {
    case 0 ... POKEBALL_COUNT - 1:
        AnimateBallOpenParticles(sprite->x, sprite->y - 5, 1, 28, ballId);
        LaunchBallFadeMonTask(TRUE, gBattleAnimTarget, 14, ballId);
        break;
    }

    gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible = FALSE;
    StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]], BATTLER_AFFINE_EMERGE);
    AnimateSprite(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]]);
    gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] = 4096;
}

void sub_08171990(struct Sprite *sprite)
{
    bool8 released = FALSE;

    if (sprite->animEnded)
        sprite->invisible = TRUE;

    if (gSprites[gBattlerSpriteIds[gBattleAnimTarget]].affineAnimEnded)
    {
        StartSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattleAnimTarget]], 0);
        released = TRUE;
    }
    else
    {
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] -= 288;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].y2 = gSprites[gBattlerSpriteIds[gBattleAnimTarget]].data[1] >> 8;
    }

    if (sprite->animEnded && released)
    {
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].y2 = 0;
        gSprites[gBattlerSpriteIds[gBattleAnimTarget]].invisible = gBattleSpritesDataPtr->animationData->wildMonInvisible;
        sprite->data[0] = 0;
        sprite->callback = sub_081717A4;
        gUnknown_202415D = FALSE;
        UpdateOamPriorityInAllHealthboxes(1);
    }
}

void sub_08171A90(struct Sprite *sprite)
{
    s32 i;
    s16 zero;
    void (*callback)(struct Sprite *);

    sprite->x += sprite->x2;
    sprite->y += sprite->y2;
    sprite->y2 = 0;
    sprite->x2 = 0;

    callback = sub_08171ACC;
    zero = 0;

    for (i = 5; i >= 0; i--)
        sprite->data[i] = zero;

    sprite->callback = callback;
}

void sub_08171ACC(struct Sprite *sprite)
{
    sprite->data[0] += 0x800;
    sprite->data[1] += 0x680;
    sprite->x2 -= sprite->data[1] >> 8;
    sprite->y2 += sprite->data[0] >> 8;
    sprite->data[0] &= 0xFF;
    sprite->data[1] &= 0xFF;

    if (sprite->y + sprite->y2 > 160 || sprite->x + sprite->x2 < -8)
    {
        sprite->data[0] = 0;
        sprite->callback = sub_081717A4;
        gUnknown_202415D = FALSE;
        UpdateOamPriorityInAllHealthboxes(1);
    }
}

void sub_08171B44(u8 ballId)
{
    if (GetSpriteTileStartByTag(sBallParticleSpriteSheets[ballId].tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheetUsingHeap(&sBallParticleSpriteSheets[ballId]);
        LoadCompressedSpritePaletteUsingHeap(&sBallParticlePalettes[ballId]);
    }
}

u8 AnimateBallOpenParticles(u8 x, u8 y, u8 priority, u8 subpriority, u8 ballId)
{
    u8 taskId;

    sub_08171B44(ballId);
    taskId = CreateTask(sBallParticleAnimationFuncs[ballId], 5);
    gTasks[taskId].data[1] = x;
    gTasks[taskId].data[2] = y;
    gTasks[taskId].data[3] = priority;
    gTasks[taskId].data[4] = subpriority;
    gTasks[taskId].data[15] = ballId;
    PlaySE(SE_BALL_OPEN);
    return taskId;
}

void sub_08171C04(void)
{
    if (gMain.inBattle)
        gBattleSpritesDataPtr->animationData->numBallParticles++;
}

void PokeBallOpenParticleAnimation(u8 taskId)
{
    u8 spriteId;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 var0;

    ballId = gTasks[taskId].data[15];
    if (gTasks[taskId].data[0] < 16)
    {
        x = gTasks[taskId].data[1];
        y = gTasks[taskId].data[2];
        priority = gTasks[taskId].data[3];
        subpriority = gTasks[taskId].data[4];

        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_08171C04();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = PokeBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;

            var0 = (u8)gTasks[taskId].data[0];
            if (var0 >= 8)
                var0 -= 8;

            gSprites[spriteId].data[0] = var0 * 32;
        }

        if (gTasks[taskId].data[0] == 15)
        {
            if (!gMain.inBattle)
                gSprites[spriteId].data[7] = 1;

            DestroyTask(taskId);
            return;
        }
    }

    gTasks[taskId].data[0]++;
}

void PokeBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
        sprite->callback = PokeBallOpenParticleAnimation_Step2;
    else
        sprite->data[1]--;
}

void PokeBallOpenParticleAnimation_Step2(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
    sprite->y2 = Cos(sprite->data[0], sprite->data[1]);
    sprite->data[1] += 2;
    if (sprite->data[1] == 50)
        DestroyBallOpenAnimationParticle(sprite);
}

void TimerBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_08171C04();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 10;
            gSprites[spriteId].data[5] = 2;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

void DiveBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_08171C04();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 10;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 2;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

void SafariBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_08171C04();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
            gSprites[spriteId].data[4] = 4;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

void UltraBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 10; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_08171C04();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 25;
            gSprites[spriteId].data[4] = 5;
            gSprites[spriteId].data[5] = 1;
            gSprites[spriteId].data[6] = 1;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

void GreatBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 spriteId;

    if (gTasks[taskId].data[7])
    {
        gTasks[taskId].data[7]--;
    }
    else
    {
        ballId = gTasks[taskId].data[15];
        x = gTasks[taskId].data[1];
        y = gTasks[taskId].data[2];
        priority = gTasks[taskId].data[3];
        subpriority = gTasks[taskId].data[4];

        for (i = 0; i < 8; i++)
        {
            spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
            if (spriteId != MAX_SPRITES)
            {
                sub_08171C04();
                StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
                gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
                gSprites[spriteId].oam.priority = priority;
                gSprites[spriteId].data[0] = i * 32;
                gSprites[spriteId].data[4] = 8;
                gSprites[spriteId].data[5] = 2;
                gSprites[spriteId].data[6] = 2;
            }
        }

        gTasks[taskId].data[7] = 8;
        if (++gTasks[taskId].data[0] == 2)
        {
            if (!gMain.inBattle)
                gSprites[spriteId].data[7] = 1;

            DestroyTask(taskId);
        }
    }
}

void FanOutBallOpenParticles_Step1(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
    sprite->y2 = Cos(sprite->data[0], sprite->data[2]);
    sprite->data[0] = (sprite->data[0] + sprite->data[4]) & 0xFF;
    sprite->data[1] += sprite->data[5];
    sprite->data[2] += sprite->data[6];
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

void RepeatBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 12; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_08171C04();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = RepeatBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 21;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

void RepeatBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
    sprite->y2 = Cos(sprite->data[0], (s16)Sin(sprite->data[0], sprite->data[2]));
    sprite->data[0] = (sprite->data[0] + 6) & 0xFF;
    sprite->data[1]++;
    sprite->data[2]++;
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

void MasterBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 j;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 8; i++)
        {
            spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
            if (spriteId != MAX_SPRITES)
            {
                sub_08171C04();
                StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
                gSprites[spriteId].callback = FanOutBallOpenParticles_Step1;
                gSprites[spriteId].oam.priority = priority;
                gSprites[spriteId].data[0] = i * 32;
                gSprites[spriteId].data[4] = 8;

                if (j == 0)
                {
                    gSprites[spriteId].data[5] = 2;
                    gSprites[spriteId].data[6] = 1;
                }
                else
                {
                    gSprites[spriteId].data[5] = 1;
                    gSprites[spriteId].data[6] = 2;
                }
            }
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

void PremierBallOpenParticleAnimation(u8 taskId)
{
    u8 i;
    u8 x;
    u8 y;
    u8 priority;
    u8 subpriority;
    u8 ballId;
    u8 spriteId;

    ballId = gTasks[taskId].data[15];
    x = gTasks[taskId].data[1];
    y = gTasks[taskId].data[2];
    priority = gTasks[taskId].data[3];
    subpriority = gTasks[taskId].data[4];

    for (i = 0; i < 8; i++)
    {
        spriteId = CreateSprite(&sBallParticleSpriteTemplates[ballId], x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            sub_08171C04();
            StartSpriteAnim(&gSprites[spriteId], sBallParticleAnimNums[ballId]);
            gSprites[spriteId].callback = PremierBallOpenParticleAnimation_Step1;
            gSprites[spriteId].oam.priority = priority;
            gSprites[spriteId].data[0] = i * 32;
        }
    }

    if (!gMain.inBattle)
        gSprites[spriteId].data[7] = 1;

    DestroyTask(taskId);
}

void PremierBallOpenParticleAnimation_Step1(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[0], sprite->data[1]);
    sprite->y2 = Cos(sprite->data[0], (s16)Sin(sprite->data[0] & 0x3F, sprite->data[2]));
    sprite->data[0] = (sprite->data[0] + 10) & 0xFF;
    sprite->data[1]++;
    sprite->data[2]++;
    if (++sprite->data[3] == 51)
        DestroyBallOpenAnimationParticle(sprite);
}

void DestroyBallOpenAnimationParticle(struct Sprite *sprite)
{
    s32 i;
    s32 j;

    if (!gMain.inBattle)
    {
        if (sprite->data[7] == 1)
            DestroySpriteAndFreeResources(sprite);
        else
            DestroySprite(sprite);
    }
    else
    {
        gBattleSpritesDataPtr->animationData->numBallParticles--;
        if (gBattleSpritesDataPtr->animationData->numBallParticles == 0)
        {
            for (i = 0; i < POKEBALL_COUNT; i++)
            {
                if (FuncIsActiveTask(sBallParticleAnimationFuncs[i]) == TRUE)
                    break;
            }

            if (i == POKEBALL_COUNT)
            {
                for (j = 0; j < POKEBALL_COUNT; j++)
                {
                    FreeSpriteTilesByTag(sBallParticleSpriteSheets[j].tag);
                    FreeSpritePaletteByTag(sBallParticlePalettes[j].tag);
                }
            }

            DestroySprite(sprite);
        }
        else
        {
            DestroySprite(sprite);
        }
    }
}

void sub_08172894(u8 taskId);
void sub_08172924(u8 taskId);
void sub_08172974(u8 taskId);

u8 LaunchBallFadeMonTask(bool8 unfadeLater, u8 spritePalNum, u32 selectedPalettes, u8 ballId)
{
    u8 taskId;

    taskId = CreateTask(sub_08172894, 5);
    gTasks[taskId].data[15] = ballId;
    gTasks[taskId].data[3] = spritePalNum;
    gTasks[taskId].data[10] = selectedPalettes;
    gTasks[taskId].data[11] = selectedPalettes >> 16;

    if (!unfadeLater)
    {
        BlendPalette(OBJ_PLTT_ID(spritePalNum), 16, 0, gBallOpenFadeColors[ballId]);
        gTasks[taskId].data[1] = 1;
    }
    else
    {
        BlendPalette(OBJ_PLTT_ID(spritePalNum), 16, 16, gBallOpenFadeColors[ballId]);
        gTasks[taskId].data[0] = 16;
        gTasks[taskId].data[1] = -1;
        gTasks[taskId].func = sub_08172924;
    }

    BeginNormalPaletteFade(selectedPalettes, 0, 0, 16, RGB_WHITE);
    return taskId;
}

void sub_08172894(u8 taskId)
{
    u8 ballId = gTasks[taskId].data[15];

    if (gTasks[taskId].data[2] <= 16)
    {
        BlendPalette(OBJ_PLTT_ID(gTasks[taskId].data[3]), 16, gTasks[taskId].data[0], gBallOpenFadeColors[ballId]);
        gTasks[taskId].data[0] += gTasks[taskId].data[1];
        gTasks[taskId].data[2]++;
    }
    else if (!gPaletteFade.active)
    {
        u32 selectedPalettes = (u16)gTasks[taskId].data[10] | ((u16)gTasks[taskId].data[11] << 16);

        BeginNormalPaletteFade(selectedPalettes, 0, 16, 0, RGB_WHITE);
        DestroyTask(taskId);
    }
}

void sub_08172924(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u32 selectedPalettes = (u16)gTasks[taskId].data[10] | ((u16)gTasks[taskId].data[11] << 16);

        BeginNormalPaletteFade(selectedPalettes, 0, 16, 0, RGB_WHITE);
        gTasks[taskId].func = sub_08172974;
    }
}

void sub_08172974(u8 taskId)
{
    u8 ballId = gTasks[taskId].data[15];

    if (gTasks[taskId].data[2] <= 16)
    {
        BlendPalette(OBJ_PLTT_ID(gTasks[taskId].data[3]), 16, gTasks[taskId].data[0], gBallOpenFadeColors[ballId]);
        gTasks[taskId].data[0] += gTasks[taskId].data[1];
        gTasks[taskId].data[2]++;
    }
    else
    {
        DestroyTask(taskId);
    }
}

void AnimTask_SwapMonSpriteToFromSubstitute(u8 taskId)
{
    u8 spriteId;
    u32 x;
    u32 done = FALSE;

    spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    switch (gTasks[taskId].data[10])
    {
    case 0:
        gTasks[taskId].data[11] = gBattleAnimArgs[0];
        gTasks[taskId].data[0] += 0x500;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gSprites[spriteId].x2 += gTasks[taskId].data[0] >> 8;
        else
            gSprites[spriteId].x2 -= gTasks[taskId].data[0] >> 8;

        gTasks[taskId].data[0] &= 0xFF;
        x = gSprites[spriteId].x + gSprites[spriteId].x2 + 32;
        if (x > DISPLAY_WIDTH + 64)
            gTasks[taskId].data[10]++;
        break;
    case 1:
        LoadBattleMonGfxAndAnimate(gBattleAnimAttacker, gTasks[taskId].data[11], spriteId);
        gTasks[taskId].data[10]++;
        break;
    case 2:
        gTasks[taskId].data[0] += 0x500;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gSprites[spriteId].x2 -= gTasks[taskId].data[0] >> 8;
        else
            gSprites[spriteId].x2 += gTasks[taskId].data[0] >> 8;

        gTasks[taskId].data[0] &= 0xFF;
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            if (gSprites[spriteId].x2 <= 0)
            {
                gSprites[spriteId].x2 = 0;
                done = TRUE;
            }
        }
        else
        {
            if (gSprites[spriteId].x2 >= 0)
            {
                gSprites[spriteId].x2 = 0;
                done = TRUE;
            }
        }

        if (done)
            DestroyAnimVisualTask(taskId);

        break;
    }
}

void AnimTask_SubstituteFadeToInvisible(u8 taskId)
{
    u8 spriteId;

    switch (gTasks[taskId].data[15])
    {
    case 0:
        if (GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker) == B_POSITION_OPPONENT_LEFT)
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
        else
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
        gTasks[taskId].data[15]++;
        break;
    case 1:
        if (gTasks[taskId].data[1]++ > 1)
        {
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - gTasks[taskId].data[0], gTasks[taskId].data[0]));
            if (gTasks[taskId].data[0] == 16)
                gTasks[taskId].data[15]++;
        }
        break;
    case 2:
        spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
        RequestDma3Fill(0, (void *)OBJ_VRAM0 + gSprites[spriteId].oam.tileNum * TILE_SIZE_4BPP, MON_PIC_SIZE, 1);
        ClearBehindSubstituteBit(gBattleAnimAttacker);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_IsAttackerBehindSubstitute(u8 taskId)
{
    gBattleAnimArgs[ARG_RET_ID] = gBattleSpritesDataPtr->battlerData[gBattleAnimAttacker].behindSubstitute;
    DestroyAnimVisualTask(taskId);
}

void AnimTask_SetTargetToEffectBattler(u8 taskId)
{
    gBattleAnimTarget = gEffectBattler;
    DestroyAnimVisualTask(taskId);
}

void sub_08172DD0(u8 taskId);
void sub_08172F94(u8 taskId);
void sub_08172FE0(struct Sprite *sprite);
void sub_08173034(struct Sprite *sprite);

void sub_08172CD4(u8 battler, struct Pokemon *mon)
{
    bool8 isShiny;
    u32 otId;
    u32 personality;
    u32 shinyValue;
    u8 taskCirc;
    u8 taskDgnl;

    isShiny = FALSE;
    gBattleSpritesDataPtr->healthBoxesData[battler].triedShinyMonAnim = TRUE;
    otId = GetMonData3(mon, MON_DATA_OT_ID);
    personality = GetMonData3(mon, MON_DATA_PERSONALITY);

    if (IsBattlerSpriteVisible(battler))
    {
        shinyValue = GET_SHINY_VALUE(otId, personality);
        if (shinyValue < SHINY_ODDS)
            isShiny = TRUE;

        if (isShiny)
        {
            if (GetSpriteTileStartByTag(ANIM_TAG_GOLD_STARS) == 0xFFFF)
            {
                LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[ANIM_TAG_GOLD_STARS - ANIM_SPRITES_START]);
                LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[ANIM_TAG_GOLD_STARS - ANIM_SPRITES_START]);
            }

            taskCirc = CreateTask(sub_08172DD0, 10);
            taskDgnl = CreateTask(sub_08172DD0, 10);
            gTasks[taskCirc].data[0] = battler;
            gTasks[taskDgnl].data[0] = battler;
            gTasks[taskCirc].data[1] = 0;
            gTasks[taskDgnl].data[1] = 1;
            return;
        }
    }

    gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = TRUE;
}

void sub_08172DD0(u8 taskId)
{
    u8 battler;
    u8 x;
    u8 y;
    u8 spriteId;
    u16 timer;
    s16 starIdx;
    s8 pan;

    if (gTasks[taskId].data[13] < 60)
    {
        gTasks[taskId].data[13]++;
        return;
    }

    if (gBattleSpritesDataPtr->animationData->numBallParticles)
        return;

    timer = gTasks[taskId].data[10]++;
    if (timer % 4)
        return;

    battler = gTasks[taskId].data[0];
    x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
    y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y);

    starIdx = gTasks[taskId].data[11];
    if (starIdx == 0)
    {
        spriteId = CreateSprite(&gWishStarSpriteTemplate, x, y, 5);
    }
    else if (starIdx >= 0 && gTasks[taskId].data[11] < 4)
    {
        spriteId = CreateSprite(&gMiniTwinklingStarSpriteTemplate, x, y, 5);
        gSprites[spriteId].oam.tileNum += 4;
    }
    else
    {
        spriteId = CreateSprite(&gMiniTwinklingStarSpriteTemplate, x, y, 5);
        gSprites[spriteId].oam.tileNum += 5;
    }

    if (gTasks[taskId].data[1] == 0)
    {
        gSprites[spriteId].callback = sub_08172FE0;
    }
    else
    {
        gSprites[spriteId].callback = sub_08173034;
        gSprites[spriteId].x2 = -32;
        gSprites[spriteId].y2 = 32;
        gSprites[spriteId].invisible = TRUE;
        if (gTasks[taskId].data[11] == 0)
        {
            if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                pan = -64;
            else
                pan = 63;

            PlaySE12WithPanning(SE_SHINY, pan);
        }
    }

    gSprites[spriteId].data[0] = taskId;
    gTasks[taskId].data[11]++;
    if (spriteId != MAX_SPRITES)
        gTasks[taskId].data[12]++;

    if (gTasks[taskId].data[11] == 5)
        gTasks[taskId].func = sub_08172F94;
}

void sub_08172F94(u8 taskId)
{
    u8 battler;

    if (gTasks[taskId].data[12] == 0)
    {
        if (gTasks[taskId].data[1] == 1)
        {
            battler = gTasks[taskId].data[0];
            gBattleSpritesDataPtr->healthBoxesData[battler].finishedShinyMonAnim = TRUE;
        }

        DestroyTask(taskId);
    }
}

void sub_08172FE0(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[1], 24);
    sprite->y2 = Cos(sprite->data[1], 24);
    sprite->data[1] += 12;
    if (sprite->data[1] > 255)
    {
        gTasks[sprite->data[0]].data[12]--;
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void sub_08173034(struct Sprite *sprite)
{
    if (sprite->data[1] < 4)
    {
        sprite->data[1]++;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->x2 += 5;
        sprite->y2 -= 5;
        if (sprite->x2 > 32)
        {
            gTasks[sprite->data[0]].data[12]--;
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
        }
    }
}

void AnimTask_LoadPokeblockGfx(u8 taskId)
{
    u8 UNUSED paletteIndex;

    LoadCompressedSpriteSheetUsingHeap(&gBattleAnimPicTable[ANIM_TAG_POKEBLOCK - ANIM_SPRITES_START]);
    LoadCompressedSpritePaletteUsingHeap(&gBattleAnimPaletteTable[ANIM_TAG_POKEBLOCK - ANIM_SPRITES_START]);
    paletteIndex = IndexOfSpritePaletteTag(ANIM_TAG_POKEBLOCK);
    DestroyAnimVisualTask(taskId);
}

void AnimTask_FreePokeblockGfx(u8 taskId)
{
    FreeSpriteTilesByTag(ANIM_TAG_POKEBLOCK);
    FreeSpritePaletteByTag(ANIM_TAG_POKEBLOCK);
    DestroyAnimVisualTask(taskId);
}

void SpriteCB_PokeBlock_Throw(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->data[0] = 30;
    sprite->data[2] = GetBattlerSpriteCoord(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), BATTLER_COORD_X) + gBattleAnimArgs[2];
    sprite->data[4] = GetBattlerSpriteCoord(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), BATTLER_COORD_Y) + gBattleAnimArgs[3];
    sprite->data[5] = -32;
    InitAnimArcTranslation(sprite);
    gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].callback = SpriteCB_TrainerThrowObject;
    sprite->callback = sub_08173180;
}

void sub_08173180(struct Sprite *sprite)
{
    if (gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].animCmdIndex == 1)
        sprite->callback = sub_081731B8;
}

void sub_081731B8(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->data[0] = 0;
        sprite->invisible = TRUE;
        sprite->callback = sub_081731E4;
    }
}

void sub_081731E4(struct Sprite *sprite)
{
    if (gSprites[gBattlerSpriteIds[gBattleAnimAttacker]].animEnded)
    {
        if (++sprite->data[0] > 0)
        {
            StartSpriteAnim(&gSprites[gBattlerSpriteIds[gBattleAnimAttacker]], 0);
            DestroyAnimSprite(sprite);
        }
    }
}

void AnimTask_SetAttackerTargetLeftPos(u8 taskId)
{
    switch (gBattleAnimArgs[0])
    {
    case 0:
        gBattleAnimAttacker = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        gBattleAnimTarget = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        break;
    case 1:
        gBattleAnimAttacker = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        gBattleAnimTarget = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        break;
    }

    DestroyAnimVisualTask(taskId);
}

void AnimTask_GetTrappedMoveAnimId(u8 taskId)
{
    if (gBattleSpritesDataPtr->animationData->animArg == MOVE_FIRE_SPIN)
        gBattleAnimArgs[0] = TRAP_ANIM_FIRE_SPIN;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_WHIRLPOOL)
        gBattleAnimArgs[0] = TRAP_ANIM_WHIRLPOOL;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_CLAMP)
        gBattleAnimArgs[0] = TRAP_ANIM_CLAMP;
    else if (gBattleSpritesDataPtr->animationData->animArg == MOVE_SAND_TOMB)
        gBattleAnimArgs[0] = TRAP_ANIM_SAND_TOMB;
    else
        gBattleAnimArgs[0] = TRAP_ANIM_BIND;

    DestroyAnimVisualTask(taskId);
}

void AnimTask_GetBattlersFromArg(u8 taskId)
{
    gBattleAnimAttacker = gBattleSpritesDataPtr->animationData->animArg;
    gBattleAnimTarget = gBattleSpritesDataPtr->animationData->animArg >> 8;
    DestroyAnimVisualTask(taskId);
}
