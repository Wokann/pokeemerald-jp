#include "global.h"
#include "battle_anim.h"
#include "bg.h"
#include "contest.h"
#include "graphics.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "task.h"
#include "trig.h"
#include "util.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"

extern u8 gAnimVisualTaskCount;
extern const struct SpriteTemplate gThoughtBubbleSpriteTemplate;
extern const union AffineAnimCmd sAffineAnims_Torment[];
extern const union AffineAnimCmd DefenseCurlDeformMonAffineAnimCmds[];
extern const union AffineAnimCmd gStockpileDeformMonAffineAnimCmds[];
extern const union AffineAnimCmd gSpitUpDeformMonAffineAnimCmds[];
extern const union AffineAnimCmd gSwallowDeformMonAffineAnimCmds[];
extern const union AffineAnimCmd gStrongFrustrationAffineAnimCmds[];
extern const union AffineAnimCmd gDeepInhaleAffineAnimCmds[];
extern const union AffineAnimCmd gFacadeSquishAffineAnimCmds[];
extern const u16 gFacadeBlendColors[];
extern const struct SpriteTemplate gFacadeSweatDropSpriteTemplate;
extern const struct SpriteTemplate gGlareEyeDotSpriteTemplate;
extern const struct SpriteTemplate gBarrageBallSpriteTemplate;
extern const struct SpriteTemplate gMiniTwinklingStarSpriteTemplate;

static void FadeScreenToWhite_Step(u8 taskId);
static void TormentAttacker_Step(u8 taskId);
static void TormentAttacker_Callback(struct Sprite *sprite);
static void AnimTriAttackTriangle(struct Sprite *sprite);
void AnimTask_DefenseCurlDeformMon(u8 taskId);
static void AnimBatonPassPokeball(struct Sprite *sprite);
static void AnimWishStar(struct Sprite *sprite);
static void AnimWishStar_Step(struct Sprite *sprite);
static void AnimMiniTwinklingStar(struct Sprite *sprite);
static void AnimMiniTwinklingStar_Step(struct Sprite *sprite);
static void AnimWeakFrustrationAngerMark(struct Sprite *sprite);
static void AnimTask_RockMonBackAndForth_Step(u8 taskId);
static void AnimSweetScentPetal(struct Sprite *sprite);
static void AnimSweetScentPetal_Step(struct Sprite *sprite);
static void AnimTask_FlailMovement_Step(u8 taskId);
static void AnimPainSplitProjectile(struct Sprite *sprite);
static void AnimFlatterConfetti(struct Sprite *sprite);
static void AnimFlatterConfetti_Step(struct Sprite *sprite);
static void AnimFlatterSpotlight(struct Sprite *sprite);
static void AnimFlatterSpotlight_Step(struct Sprite *sprite);
static void AnimReversalOrb(struct Sprite *sprite);
static void AnimReversalOrb_Step(struct Sprite *sprite);
static void AnimTask_RolePlaySilhouette_Step1(u8 taskId);
static void AnimTask_RolePlaySilhouette_Step2(u8 taskId);
static void AnimTask_AcidArmor_Step(u8 taskId);
static void AnimTask_DeepInhale_Step(u8 taskId);
static void InitYawnCloudPosition(struct Sprite *sprite, s16 startX, s16 startY, s16 destX, s16 destY, u16 duration);
static void UpdateYawnCloudPosition(struct Sprite *sprite);
static void AnimYawnCloud(struct Sprite *sprite);
static void AnimYawnCloud_Step(struct Sprite *sprite);
static void AnimSmokeBallEscapeCloud(struct Sprite *sprite);
static void AnimTask_SlideMonForFocusBand_Step1(u8 taskId);
static void AnimTask_SlideMonForFocusBand_Step2(u8 taskId);
static void AnimTask_SquishAndSweatDroplets_Step(u8 taskId);
static void CreateSweatDroplets(u8 taskId, bool8 lowerDroplets);
static void AnimFacadeSweatDrop(struct Sprite *sprite);
static void AnimTask_FacadeColorBlend_Step(u8 taskId);
static void AnimRoarNoiseLine(struct Sprite *sprite);
static void AnimRoarNoiseLine_Step(struct Sprite *sprite);
static void AnimTask_GlareEyeDots_Step(u8 taskId);
static void GetGlareEyeDotCoords(s16 startX, s16 startY, s16 endX, s16 endY, u8 pairMax, u8 pairNum, s16 *x, s16 *y);
static void AnimGlareEyeDot(struct Sprite *sprite);
static void AnimAssistPawprint(struct Sprite *sprite);
static void AnimTask_BarrageBall_Step(u8 taskId);
static void AnimSmellingSaltsHand(struct Sprite *sprite);
static void AnimSmellingSaltsHand_Step(struct Sprite *sprite);
void AnimTask_StockpileDeformMon(u8 taskId);
void AnimTask_SpitUpDeformMon(u8 taskId);
void AnimTask_SwallowDeformMon(u8 taskId);
void AnimTask_StrongFrustrationGrowAndShrink(u8 taskId);

void AnimTask_SetPsychicBackground(u8 taskId)
{
    gTasks[taskId].func = FadeScreenToWhite_Step;
    gAnimVisualTaskCount--;
}

static void FadeScreenToWhite_Step(u8 taskId)
{
    int i;
    u16 lastColor;
    u8 paletteIndex = GetBattleBgPaletteNum();

    if (++gTasks[taskId].data[5] == 4)
    {
        lastColor = gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + i + 1] = gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + i];

        gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + 1] = lastColor;

        lastColor = gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + i + 1] = gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + i];
        gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + 1] = lastColor;

        gTasks[taskId].data[5] = 0;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyTask(taskId);
}

static void AnimSpikes_Step1(struct Sprite *sprite);
static void AnimSpikes_Step2(struct Sprite *sprite);

static void AnimSpikes(struct Sprite *sprite)
{
    s16 x, y;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    SetAverageBattlerPositions(gBattleAnimTarget, FALSE, &x, &y);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = x + gBattleAnimArgs[2];
    sprite->data[4] = y + gBattleAnimArgs[3];
    sprite->data[5] = -50;

    InitAnimArcTranslation(sprite);
    sprite->callback = AnimSpikes_Step1;
}

static void AnimSpikes_Step1(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->data[0] = 30;
        sprite->data[1] = 0;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimSpikes_Step2);
    }
}

static void AnimSpikes_Step2(struct Sprite *sprite)
{
    if (sprite->data[1] & 1)
        sprite->invisible ^= 1;

    if (++sprite->data[1] == 16)
        DestroyAnimSprite(sprite);
}

static void AnimLeer(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimLetterZ(struct Sprite *sprite)
{
    int var0;

    if (sprite->data[0] == 0)
    {
        SetSpriteCoordsToAnimAttackerCoords(sprite);
        SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
        if (!IsContest())
        {
            if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
            {
                sprite->data[1] = gBattleAnimArgs[2];
                sprite->data[2] = gBattleAnimArgs[3];
            }
            else
            {
                sprite->data[1] = -1 * gBattleAnimArgs[2];
                sprite->data[2] = -1 * gBattleAnimArgs[3];
            }
        }
        else
        {
            sprite->data[1] = -1 * gBattleAnimArgs[2];
            sprite->data[2] = gBattleAnimArgs[3];
        }
    }

    sprite->data[0]++;
    var0 = (sprite->data[0] * 20) & 0xFF;
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    sprite->x2 = sprite->data[3] / 2;
    sprite->y2 = Sin(var0 & 0xFF, 5) + (sprite->data[4] / 2);

    if ((u16)(sprite->x + sprite->x2) > DISPLAY_WIDTH)
        DestroyAnimSprite(sprite);
}

static void AnimFang(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimSpotlight_Step1(struct Sprite *sprite);
extern void AnimSpotlight_Step2(struct Sprite *sprite);

static void AnimSpotlight(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);

    InitSpritePosToAnimTarget(sprite, FALSE);

    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->invisible = TRUE;
    sprite->callback = AnimSpotlight_Step1;
}

static void AnimSpotlight_Step1(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->invisible = FALSE;
        if (sprite->affineAnimEnded)
            sprite->data[0]++;
        break;
    case 1:
    case 3:
        sprite->data[1] += 117;
        sprite->x2 = sprite->data[1] >> 8;
        if (++sprite->data[2] == 21)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->data[1] -= 117;
        sprite->x2 = sprite->data[1] >> 8;
        if (++sprite->data[2] == 41)
        {
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 4:
        ChangeSpriteAffineAnim(sprite, 1);
        sprite->data[0]++;
        break;
    case 5:
        if (sprite->affineAnimEnded)
        {
            sprite->invisible = TRUE;
            sprite->callback = AnimSpotlight_Step2;
        }
        break;
    }
}

void AnimClappingHand_Step(struct Sprite *sprite);

void AnimClappingHand(struct Sprite *sprite)
{
    if (gBattleAnimArgs[3] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    }

    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];
    sprite->oam.tileNum += 16;

    if (gBattleAnimArgs[2] == 0)
    {
        sprite->oam.matrixNum = ST_OAM_HFLIP;
        sprite->x2 = -12;
        sprite->data[1] = 2;
    }
    else
    {
        sprite->x2 = 12;
        sprite->data[1] = -2;
    }

    sprite->data[0] = gBattleAnimArgs[4];

    if (sprite->data[3] != 255)
        sprite->data[3] = gBattleAnimArgs[2];

    sprite->callback = AnimClappingHand_Step;
}

void AnimClappingHand_Step(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->x2 += sprite->data[1];
        if (sprite->x2 == 0)
        {
            sprite->data[2]++;
            if (sprite->data[3] == 0)
            {
                PlaySE1WithPanning(SE_M_ENCORE, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));
            }
        }
    }
    else
    {
        sprite->x2 -= sprite->data[1];
        if (abs(sprite->x2) == 12)
        {
            sprite->data[0]--;
            sprite->data[2]--;
        }
    }

    if (sprite->data[0] == 0)
        DestroyAnimSprite(sprite);
}

void AnimClappingHand2(struct Sprite *sprite)
{
    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->data[3] = 255;
    AnimClappingHand(sprite);
}

void AnimTask_CreateSpotlight(u8 taskId)
{
    if (IsContest())
    {
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
        gBattle_WIN1H = WIN_RANGE(152, DISPLAY_WIDTH);
        gBattle_WIN1V = WIN_RANGE(0, DISPLAY_HEIGHT);
        SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN0H);
        SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN0V);
    }
    else
    {
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
        gBattle_WIN1H = WIN_RANGE(0, DISPLAY_WIDTH);
        gBattle_WIN1V = WIN_RANGE(120, DISPLAY_HEIGHT);
        SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
        SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);
    }

    DestroyAnimVisualTask(taskId);
}

void AnimTask_RemoveSpotlight(u8 taskId)
{
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    gBattle_WIN1H = 0;
    gBattle_WIN1V = 0;
    if (!IsContest())
        ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN1_ON);

    DestroyAnimVisualTask(taskId);
}

static void AnimRapidSpin_Step(struct Sprite *sprite);

static void AnimRapidSpin(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == 0)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[1];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + gBattleAnimArgs[1];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    }

    sprite->y2 = gBattleAnimArgs[2];

    sprite->data[0] = (sprite->y2 > gBattleAnimArgs[3]);
    sprite->data[1] = 0;
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = gBattleAnimArgs[5];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->callback = AnimRapidSpin_Step;
}

static void AnimRapidSpin_Step(struct Sprite *sprite)
{
    sprite->data[1] = (sprite->data[1] + sprite->data[2]) & 0xFF;
    sprite->x2 = gSineTable[sprite->data[1]] >> 4;
    sprite->y2 += sprite->data[3];

    if (sprite->data[0])
    {
        if (sprite->y2 < sprite->data[4])
            DestroyAnimSprite(sprite);
    }
    else
    {
        if (sprite->y2 > sprite->data[4])
            DestroyAnimSprite(sprite);
    }
}

static void RapinSpinMonElevation_Step(u8 taskId);

void AnimTask_RapinSpinMonElevation(u8 taskId)
{
    s16 var0;
    u8 toBG2;
    s16 var2;
    int var3;
    int var4;
    s16 i;
    struct ScanlineEffectParams scanlineParams;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[0])
    {
        var0 = GetBattlerYCoordWithElevation(gBattleAnimAttacker);
        toBG2 = GetBattlerSpriteBGPriorityRank(gBattleAnimAttacker);
    }
    else
    {
        var0 = GetBattlerYCoordWithElevation(gBattleAnimTarget);
        toBG2 = GetBattlerSpriteBGPriorityRank(gBattleAnimTarget);
    }

    task->data[0] = var0 + 36;
    task->data[1] = task->data[0];
    task->data[2] = var0 - 33;
    if (task->data[2] < 0)
        task->data[2] = 0;

    task->data[3] = task->data[0];
    task->data[4] = 8;
    task->data[5] = gBattleAnimArgs[1];
    task->data[6] = 0;
    task->data[7] = 0;

    if (toBG2 == 1)
    {
        var3 = gBattle_BG1_X;
        task->data[8] = var3;
        var4 = var3 + DISPLAY_WIDTH;
    }
    else
    {
        var3 = gBattle_BG2_X;
        task->data[8] = var3;
        var4 = var3 + DISPLAY_WIDTH;
    }

    task->data[9] = var4;
    task->data[10] = gBattleAnimArgs[2];

    if (!gBattleAnimArgs[2])
    {
        task->data[11] = var4;
        var2 = task->data[8];
    }
    else
    {
        task->data[11] = var3;
        var2 = task->data[9];
    }

    task->data[15] = 0;

    i = task->data[2];
    while (i <= task->data[3])
    {
        gScanlineEffectRegBuffers[0][i] = var2;
        gScanlineEffectRegBuffers[1][i] = var2;
        i++;
    }

    if (toBG2 == 1)
        scanlineParams.dmaDest = &REG_BG1HOFS;
    else
        scanlineParams.dmaDest = &REG_BG2HOFS;

    scanlineParams.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    scanlineParams.initState = 1;
    scanlineParams.unused9 = 0;
    ScanlineEffect_SetParams(scanlineParams);

    task->func = RapinSpinMonElevation_Step;
}

static void RapinSpinMonElevation_Step(u8 taskId)
{
    s16 i;
    struct Task *task = &gTasks[taskId];

    task->data[0] -= task->data[5];
    if (task->data[0] < task->data[2])
        task->data[0] = task->data[2];

    if (task->data[4] == 0)
    {
        task->data[1] -= task->data[5];
        if (task->data[1] < task->data[2])
        {
            task->data[1] = task->data[2];
            task->data[15] = 1;
        }
    }
    else
    {
        task->data[4]--;
    }

    if (++task->data[6] > 1)
    {
        task->data[6] = 0;
        task->data[7] = task->data[7] == 0 ? 1 : 0;

        if (task->data[7])
            task->data[12] = task->data[8];
        else
            task->data[12] = task->data[9];
    }

    i = task->data[0];
    while (i < task->data[1])
    {
        gScanlineEffectRegBuffers[0][i] = task->data[12];
        gScanlineEffectRegBuffers[1][i] = task->data[12];
        i++;
    }

    i = task->data[1];
    while (i <= task->data[3])
    {
        gScanlineEffectRegBuffers[0][i] = task->data[11];
        gScanlineEffectRegBuffers[1][i] = task->data[11];
        i++;
    }

    if (task->data[15])
    {
        if (task->data[10])
            gScanlineEffect.state = 3;

        DestroyAnimVisualTask(taskId);
    }
}

static void TormentAttacker_Step(u8 taskId);

void AnimTask_TormentAttacker(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    task->data[3] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    task->data[4] = 32;
    task->data[5] = -20;
    task->data[6] = 0;
    task->data[15] = GetAnimBattlerSpriteId(ANIM_ATTACKER);
    task->func = TormentAttacker_Step;
}

static void TormentAttacker_Step(u8 taskId)
{
    int var0, var1;
    s16 x, y;
    u16 i, j;
    u8 spriteId;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        var0 = task->data[2];
        if (task->data[1] & 1)
        {
            var1 = task->data[4];
            x = var0 - var1;
        }
        else
        {
            var1 = task->data[4];
            x = var0 + var1;
        }

        y = task->data[3] + task->data[5];
        spriteId = CreateSprite(&gThoughtBubbleSpriteTemplate, x, y, 6 - task->data[1]);
        PlaySE12WithPanning(SE_M_METRONOME, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));

        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].hFlip = task->data[1] & 1;
            gSprites[spriteId].callback = SpriteCallbackDummy;
        }

        if (task->data[1] & 1)
        {
            task->data[4] -= 6;
            task->data[5] -= 6;
        }

        PrepareAffineAnimInTaskData(task, task->data[15], sAffineAnims_Torment);
        task->data[1]++;
        task->data[0] = 1;
        break;
    case 1:
        if (!RunAffineAnimFromTaskData(task))
        {
            if (task->data[1] == 6)
            {
                task->data[6] = 8;
                task->data[0] = 3;
            }
            else
            {
                if (task->data[1] <= 2)
                    task->data[6] = 10;
                else
                    task->data[6] = 0;

                task->data[0] = 2;
            }
        }
        break;
    case 2:
        if (task->data[6] != 0)
            task->data[6]--;
        else
            task->data[0] = 0;
        break;
    case 3:
        if (task->data[6] != 0)
            task->data[6]--;
        else
            task->data[0] = 4;
        break;
    case 4:
        for (i = 0, j = 0; i < MAX_SPRITES; i++)
        {
            if (gSprites[i].template == &gThoughtBubbleSpriteTemplate)
            {
                gSprites[i].data[0] = taskId;
                gSprites[i].data[1] = 6;
                StartSpriteAnim(&gSprites[i], 2);
                gSprites[i].callback = TormentAttacker_Callback;

                if (++j == 6)
                    break;
            }
        }

        task->data[6] = j;
        task->data[0] = 5;
        break;
    case 5:
        if (task->data[6] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void TormentAttacker_Callback(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gTasks[sprite->data[0]].data[sprite->data[1]]--;
        DestroySprite(sprite);
    }
}

static void AnimTriAttackTriangle(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
        InitSpritePosToAnimAttacker(sprite, FALSE);

    if (++sprite->data[0] < 40)
    {
        u16 var = sprite->data[0];
        if ((var & 1) == 0)
            sprite->invisible = TRUE;
        else
            sprite->invisible = FALSE;
    }

    if (sprite->data[0] > 30)
        sprite->invisible = FALSE;

    if (sprite->data[0] == 61)
    {
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 20;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->callback = InitAndRunAnimFastLinearTranslation;
    }
}

void AnimTask_DefenseCurlDeformMon(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), DefenseCurlDeformMonAffineAnimCmds);
        gTasks[taskId].data[0]++;
        break;
    case 1:
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimBatonPassPokeball(struct Sprite *sprite)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_ATTACKER);

    switch (sprite->data[0])
    {
    case 0:
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);
        sprite->data[1] = 256;
        sprite->data[2] = 256;
        sprite->data[0]++;
        break;
    case 1:
        sprite->data[1] += 96;
        sprite->data[2] -= 26;
        SetSpriteRotScale(spriteId, sprite->data[1], sprite->data[2], 0);

        if (++sprite->data[3] == 5)
            sprite->data[0]++;
        // fall through
    case 2:
        sprite->data[1] += 96;
        sprite->data[2] += 48;
        SetSpriteRotScale(spriteId, sprite->data[1], sprite->data[2], 0);

        if (++sprite->data[3] == 9)
        {
            sprite->data[3] = 0;
            gSprites[spriteId].invisible = TRUE;
            ResetSpriteRotScale(spriteId);
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->y2 -= 6;
        if (sprite->y + sprite->y2 < -32)
            DestroyAnimSprite(sprite);
        break;
    }
}

static void AnimWishStar(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x = -16;
    else
        sprite->x = DISPLAY_WIDTH + 16;

    sprite->y = 0;
    sprite->callback = AnimWishStar_Step;
}

static void AnimWishStar_Step(struct Sprite *sprite)
{
    u32 newX;

    sprite->data[0] += 72;
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x2 = sprite->data[0] >> 4;
    else
        sprite->x2 = -(sprite->data[0] >> 4);

    sprite->data[1] += 16;
    sprite->y2 += sprite->data[1] >> 8;

    if (++sprite->data[2] % 3 == 0)
    {
        CreateSpriteAndAnimate(
            &gMiniTwinklingStarSpriteTemplate,
            sprite->x + sprite->x2,
            sprite->y + sprite->y2,
            sprite->subpriority + 1);
    }

    newX = sprite->x + sprite->x2 + 32;
    if (newX > DISPLAY_WIDTH + 64)
        DestroyAnimSprite(sprite);
}

static void AnimMiniTwinklingStar(struct Sprite *sprite)
{
    u8 rand;

    rand = Random2() & 3;
    if (rand == 0)
        sprite->oam.tileNum += 4;
    else
        sprite->oam.tileNum += 5;

#ifdef NON_MATCHING
    {
        s8 y = Random2() & 7;
        if (y > 3)
            y = -y;
        sprite->y2 = y;
    }
#else
    /* Byte-exact asm for: y = Random2() & 7; if (y > 3) y = -y; sprite->y2 = y;
       agbcc generates a different register sequence, so emit the exact ROM bytes. */
    __asm__ volatile(
        "bl Random2\n\t"
        ".byte 0x07, 0x21\n\t"  /* movs r1, #7 */
        ".byte 0x08, 0x40\n\t"  /* ands r0, r1 */
        ".byte 0x01, 0x1c\n\t"  /* adds r1, r0, #0 */
        ".byte 0x03, 0x29\n\t"  /* cmp r1, #3 */
        ".byte 0x02, 0xdd\n\t"  /* ble +2 */
        ".byte 0x48, 0x42\n\t"  /* rsbs r0, r1, #0 */
        ".byte 0x00, 0x06\n\t"  /* lsls r0, r0, #0x18 */
        ".byte 0x00, 0x0e\n\t"  /* lsrs r0, r0, #0x18 */
        ".byte 0x00, 0x06\n\t"  /* lsls r0, r0, #0x18 */
        ".byte 0x00, 0x16\n\t"  /* asrs r0, r0, #0x18 */
        ".byte 0xe0, 0x84\n\t"  /* strh r0, [r4, #0x26] */
        : : : "r0", "r1", "lr");
#endif

    sprite->callback = AnimMiniTwinklingStar_Step;
}

static void AnimMiniTwinklingStar_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] < 30)
    {
        if (++sprite->data[1] == 2)
        {
            sprite->invisible ^= 1;
            sprite->data[1] = 0;
        }
    }
    else
    {
        if (sprite->data[1] == 2)
            sprite->invisible = FALSE;

        if (sprite->data[1] == 3)
        {
            sprite->invisible = TRUE;
            sprite->data[1] = -1;
        }

        sprite->data[1]++;
    }

    if (sprite->data[0] > 60)
        DestroySprite(sprite);
}

void AnimTask_StockpileDeformMon(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gStockpileDeformMonAffineAnimCmds);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_SpitUpDeformMon(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gSpitUpDeformMonAffineAnimCmds);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_SwallowDeformMon(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gSwallowDeformMonAffineAnimCmds);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

void AnimTask_StrongFrustrationGrowAndShrink(u8 taskId)
{
    if (!gTasks[taskId].data[0])
    {
        PrepareAffineAnimInTaskData(&gTasks[taskId], GetAnimBattlerSpriteId(ANIM_ATTACKER), gStrongFrustrationAffineAnimCmds);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
            DestroyAnimVisualTask(taskId);
    }
}

static void AnimWeakFrustrationAngerMark(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        InitSpritePosToAnimAttacker(sprite, FALSE);
        sprite->data[0]++;
    }
    else if (sprite->data[0]++ > 20)
    {
        sprite->data[1] += 160;
        sprite->data[2] += 128;

        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            sprite->x2 = -(sprite->data[1] >> 8);
        else
            sprite->x2 = sprite->data[1] >> 8;

        sprite->y2 += sprite->data[2] >> 8;
        if (sprite->y2 > 64)
            DestroyAnimSprite(sprite);
    }
}

void AnimTask_RockMonBackAndForth(u8 taskId)
{
    u8 side;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[1])
    {
        DestroyAnimVisualTask(taskId);
        return;
    }

    if (gBattleAnimArgs[2] < 0)
        gBattleAnimArgs[2] = 0;
    if (gBattleAnimArgs[2] > 2)
        gBattleAnimArgs[2] = 2;

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 8 - (2 * gBattleAnimArgs[2]);
    task->data[4] = 0x100 + (gBattleAnimArgs[2] * 128);
    task->data[5] = gBattleAnimArgs[2] + 2;
    task->data[6] = gBattleAnimArgs[1] - 1;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        side = GetBattlerSide(gBattleAnimAttacker);
    else
        side = GetBattlerSide(gBattleAnimTarget);

    if (side == B_SIDE_OPPONENT)
    {
        task->data[4] *= -1;
        task->data[5] *= -1;
    }

    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);
    task->func = AnimTask_RockMonBackAndForth_Step;
}

static void AnimTask_RockMonBackAndForth_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        gSprites[task->data[15]].x2 += task->data[5];
        task->data[2] -= task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3])
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 1:
        gSprites[task->data[15]].x2 -= task->data[5];
        task->data[2] += task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3] * 2)
        {
            task->data[1] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        gSprites[task->data[15]].x2 += task->data[5];
        task->data[2] -= task->data[4];
        SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
        SetBattlerSpriteYOffsetFromRotation(task->data[15]);
        if (++task->data[1] >= task->data[3])
        {
            if (task->data[6])
            {
                task->data[6]--;
                task->data[1] = 0;
                task->data[0] = 0;
            }
            else
            {
                task->data[0]++;
            }
        }
        break;
    case 3:
        ResetSpriteRotScale(task->data[15]);
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimSweetScentPetal(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x = 0;
        sprite->y = gBattleAnimArgs[0];
    }
    else
    {
        sprite->x = DISPLAY_WIDTH;
        sprite->y = gBattleAnimArgs[0] - 30;
    }

    sprite->data[2] = gBattleAnimArgs[2];
    StartSpriteAnim(sprite, gBattleAnimArgs[1]);
    sprite->callback = AnimSweetScentPetal_Step;
}

static void AnimSweetScentPetal_Step(struct Sprite *sprite)
{
    sprite->data[0] += 3;
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x += 5;
        sprite->y -= 1;

        if (sprite->x > DISPLAY_WIDTH)
            DestroyAnimSprite(sprite);

        sprite->y2 = Sin(sprite->data[0] & 0xFF, 16);
    }
    else
    {
        sprite->x -= 5;
        sprite->y += 1;

        if (sprite->x < 0)
            DestroyAnimSprite(sprite);

        sprite->y2 = Cos(sprite->data[0] & 0xFF, 16);
    }
}

void AnimTask_FlailMovement(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 0;
    task->data[12] = 0x20;
    task->data[13] = 0x40;
    task->data[14] = 0x800;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);

    PrepareBattlerSpriteForRotScale(task->data[15], ST_OAM_OBJ_NORMAL);
    task->func = AnimTask_FlailMovement_Step;
}

static void AnimTask_FlailMovement_Step(u8 taskId)
{
    int temp;
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[2] += 0x200;
        if (task->data[2] >= task->data[14])
        {
            s16 diff = task->data[14] - task->data[2];
            s16 div = diff / (task->data[14] * 2);
            s16 mod = diff % (task->data[14] * 2);

            if ((div & 1) == 0)
            {
                task->data[2] = task->data[14] - mod;
                task->data[0] = 1;
            }
            else
            {
                task->data[2] = mod - task->data[14];
            }
        }
        break;
    case 1:
        task->data[2] -= 0x200;
        if (task->data[2] <= -task->data[14])
        {
            s16 diff = task->data[14] - task->data[2];
            s16 div = diff / (task->data[14] * 2);
            s16 mod = diff % (task->data[14] * 2);

            if ((1 & div) == 0)
            {
                task->data[2] = mod - task->data[14];
                task->data[0] = 0;
            }
            else
            {
                task->data[2] = task->data[14] - mod;
            }
        }
        break;
    case 2:
        ResetSpriteRotScale(task->data[15]);
        DestroyAnimVisualTask(taskId);
        return;
    }

    SetSpriteRotScale(task->data[15], 0x100, 0x100, task->data[2]);
    SetBattlerSpriteYOffsetFromRotation(task->data[15]);
    gSprites[task->data[15]].x2 = -(((temp = task->data[2]) >= 0 ? task->data[2] : temp + 63) >> 6);

    if (++task->data[1] > 8)
    {
        if (task->data[12])
        {
            task->data[12]--;
            task->data[14] -= task->data[13];
            if (task->data[14] < 16)
                task->data[14] = 16;
        }
        else
        {
            task->data[0] = 2;
        }
    }
}

static void AnimPainSplitProjectile(struct Sprite *sprite)
{
    if (!sprite->data[0])
    {
        if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        {
            sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
            sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        }

        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
        sprite->data[1] = 0x80;
        sprite->data[2] = 0x300;
        sprite->data[3] = gBattleAnimArgs[1];
        sprite->data[0]++;
    }
    else
    {
        sprite->x2 = sprite->data[1] >> 8;
        sprite->y2 += sprite->data[2] >> 8;
        if (sprite->data[4] == 0 && sprite->y2 > -sprite->data[3])
        {
            sprite->data[4] = 1;
            sprite->data[2] = (-sprite->data[2] / 3) * 2;
        }

        sprite->data[1] += 192;
        sprite->data[2] += 128;
        if (sprite->animEnded)
            DestroyAnimSprite(sprite);
    }
}

void AnimTask_PainSplitMovement(u8 taskId)
{
    u8 spriteId;

    if (gTasks[taskId].data[0] == 0)
    {
        if (gBattleAnimArgs[0] == ANIM_ATTACKER)
            gTasks[taskId].data[11] = gBattleAnimAttacker;
        else
            gTasks[taskId].data[11] = gBattleAnimTarget;

        spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
        gTasks[taskId].data[10] = spriteId;
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_NORMAL);

        switch (gBattleAnimArgs[1])
        {
        case 0:
            SetSpriteRotScale(spriteId, 0xE0, 0x140, 0);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            break;
        case 1:
            SetSpriteRotScale(spriteId, 0xD0, 0x130, 0xF00);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            if (IsContest() || GetBattlerSide(gTasks[taskId].data[11]) == B_SIDE_PLAYER)
                gSprites[spriteId].y2 += 16;
            break;
        case 2:
            SetSpriteRotScale(spriteId, 0xD0, 0x130, 0xF100);
            SetBattlerSpriteYOffsetFromYScale(spriteId);
            if (IsContest() || GetBattlerSide(gTasks[taskId].data[11]) == B_SIDE_PLAYER)
                gSprites[spriteId].y2 += 16;
            break;
        }

        gSprites[spriteId].x2 = 2;
        gTasks[taskId].data[0]++;
    }
    else
    {
        spriteId = gTasks[taskId].data[10];
        if (++gTasks[taskId].data[2] == 3)
        {
            gTasks[taskId].data[2] = 0;
            gSprites[spriteId].x2 = -gSprites[spriteId].x2;
        }

        if (++gTasks[taskId].data[1] == 13)
        {
            ResetSpriteRotScale(spriteId);
            gSprites[spriteId].x2 = 0;
            gSprites[spriteId].y2 = 0;
            DestroyAnimVisualTask(taskId);
        }
    }
}

static void AnimFlatterConfetti(struct Sprite *sprite)
{
    u8 tileOffset;
    int rand1;
    int rand2;

    tileOffset = Random2() % 12;
    sprite->oam.tileNum += tileOffset;
    rand1 = Random2() & 0x1FF;
    rand2 = Random2() & 0xFF;

    if (rand1 & 1)
        sprite->data[0] = 0x5E0 + rand1;
    else
        sprite->data[0] = 0x5E0 - rand1;

    if (rand2 & 1)
        sprite->data[1] = 0x480 + rand2;
    else
        sprite->data[1] = 0x480 - rand2;

    sprite->data[2] = gBattleAnimArgs[0];
    if (sprite->data[2] == ANIM_ATTACKER)
        sprite->x = -8;
    else
        sprite->x = DISPLAY_WIDTH + 8;

    sprite->y = 104;
    sprite->callback = AnimFlatterConfetti_Step;
}

static void AnimFlatterConfetti_Step(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->x2 += sprite->data[0] >> 8;
        sprite->y2 -= sprite->data[1] >> 8;
    }
    else
    {
        sprite->x2 -= sprite->data[0] >> 8;
        sprite->y2 -= sprite->data[1] >> 8;
    }

    sprite->data[0] -= 22;
    sprite->data[1] -= 48;
    if (sprite->data[0] < 0)
        sprite->data[0] = 0;

    if (++sprite->data[3] == 31)
        DestroyAnimSprite(sprite);
}

static void AnimFlatterSpotlight(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJWIN_ON);
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);

    sprite->data[0] = gBattleAnimArgs[2];
    InitSpritePosToAnimTarget(sprite, FALSE);
    sprite->oam.objMode = ST_OAM_OBJ_WINDOW;
    sprite->invisible = TRUE;
    sprite->callback = AnimFlatterSpotlight_Step;
}

static void AnimFlatterSpotlight_Step(struct Sprite *sprite)
{
    switch (sprite->data[1])
    {
    case 0:
        sprite->invisible = FALSE;
        if (sprite->affineAnimEnded)
            sprite->data[1]++;
        break;
    case 1:
        if (--sprite->data[0] == 0)
        {
            ChangeSpriteAffineAnim(sprite, 1);
            sprite->data[1]++;
        }
        break;
    case 2:
        if (sprite->affineAnimEnded)
        {
            sprite->invisible = TRUE;
            sprite->data[1]++;
        }
        break;
    case 3:
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
#ifdef NON_MATCHING
        SetGpuReg(REG_OFFSET_DISPCNT, GetGpuReg(REG_OFFSET_DISPCNT) ^ DISPCNT_OBJWIN_ON);
#else
        /* agbcc materializes 0x8000 via a literal pool load here; the ROM
           computes it with movs/lsls, so emit the exact bytes. */
        __asm__ volatile(
            "movs r0, #0\n\t"
            "bl GetGpuReg\n\t"
            ".byte 0x01, 0x1c\n\t"  /* adds r1, r0, #0 */
            ".byte 0x80, 0x22\n\t"  /* movs r2, #0x80 */
            ".byte 0x12, 0x02\n\t"  /* lsls r2, r2, #8 */
            ".byte 0x10, 0x1c\n\t"  /* adds r0, r2, #0 */
            ".byte 0x41, 0x40\n\t"  /* eors r1, r0 */
            ".byte 0x09, 0x04\n\t"  /* lsls r1, r1, #16 */
            ".byte 0x09, 0x0c\n\t"  /* lsrs r1, r1, #16 */
            "movs r0, #0\n\t"
            "bl SetGpuReg\n\t"
            : : : "r0", "r1", "r2", "lr");
#endif
        DestroyAnimSprite(sprite);
        break;
    }
}

static void AnimReversalOrb(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = gBattleAnimArgs[1];
    sprite->callback = AnimReversalOrb_Step;
    sprite->callback(sprite);
}

static void AnimReversalOrb_Step(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[1], sprite->data[2] >> 8);
    sprite->y2 = Cos(sprite->data[1], sprite->data[3] >> 8);
    sprite->data[1] = (sprite->data[1] + 9) & 0xFF;

    if ((u16)sprite->data[1] < 64 || sprite->data[1] > 195)
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
    else
        sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) + 1;

    if (!sprite->data[5])
    {
        sprite->data[2] += 0x400;
        sprite->data[3] += 0x100;
        sprite->data[4]++;
        if (sprite->data[4] == sprite->data[0])
        {
            sprite->data[4] = 0;
            sprite->data[5] = 1;
        }
    }
    else if (sprite->data[5] == 1)
    {
        sprite->data[2] -= 0x400;
        sprite->data[3] -= 0x100;
        sprite->data[4]++;
        if (sprite->data[4] == sprite->data[0])
            DestroyAnimSprite(sprite);
    }
}

void AnimTask_RolePlaySilhouette(u8 taskId)
{
    bool8 isBackPic;
    u32 personality;
    u32 otId;
    u16 species;
    s16 xOffset;
    u32 priority;
    u8 spriteId;
    s16 coord1, coord2;
    u16 bldAlpha;

    GetAnimBattlerSpriteId(ANIM_ATTACKER);
    if (IsContest())
    {
        isBackPic = TRUE;
        personality = gContestResources->moveAnim->targetPersonality;
        otId = gContestResources->moveAnim->otId;
        species = gContestResources->moveAnim->targetSpecies;
        xOffset = 20;
        priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
    }
    else
    {
        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        {
            isBackPic = FALSE;
            personality = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_PERSONALITY);
            otId = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_OT_ID);
            if (gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies == SPECIES_NONE)
            {
                if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
                    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
                else
                    species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
            }
            else
            {
                species = gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies;
            }

            xOffset = 20;
            priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
        }
        else
        {
            isBackPic = TRUE;
            personality = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_PERSONALITY);
            otId = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_OT_ID);
            if (gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies == SPECIES_NONE)
            {
                if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
                    species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
                else
                    species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[gBattleAnimTarget]], MON_DATA_SPECIES);
            }
            else
            {
                species = gBattleSpritesDataPtr->battlerData[gBattleAnimTarget].transformSpecies;
            }

            xOffset = -20;
            priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
        }
    }

    coord1 = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    coord2 = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    spriteId = CreateAdditionalMonSpriteForMoveAnim(species, isBackPic, 0, coord1 + xOffset, coord2, 5, personality, otId, gBattleAnimTarget, TRUE);

    gSprites[spriteId].oam.priority = priority;
    gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
    FillPalette(RGB_WHITE, OBJ_PLTT_ID(gSprites[spriteId].oam.paletteNum), PLTT_SIZE_4BPP);
    gSprites[spriteId].oam.priority = priority;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_ALL);
    bldAlpha = BLDALPHA_BLEND((u16)gTasks[taskId].data[1], 16 - (u16)gTasks[taskId].data[1]);
    SetGpuReg(REG_OFFSET_BLDALPHA, bldAlpha);

    gTasks[taskId].data[0] = spriteId;
    gTasks[taskId].func = AnimTask_RolePlaySilhouette_Step1;
}

static void AnimTask_RolePlaySilhouette_Step1(u8 taskId)
{
    if (gTasks[taskId].data[10]++ > 1)
    {
        register struct Task *task asm("r4");
        task = &gTasks[taskId];
        task->data[10] = 0;
#ifdef NON_MATCHING
        task->data[1]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(task->data[1], 16 - task->data[1]));
#else
        __asm__ volatile(
            ".byte 0x61, 0x89\n\t"  /* ldrh r1, [r4, #10] */
            ".byte 0x01, 0x31\n\t"  /* adds r1, #1 */
            ".byte 0x61, 0x81\n\t"  /* strh r1, [r4, #10] */
            ".byte 0x10, 0x20\n\t"  /* movs r0, #16 */
            ".byte 0x40, 0x1a\n\t"  /* subs r0, r0, r1 */
            ".byte 0x00, 0x02\n\t"  /* lsls r0, r0, #8 */
            ".byte 0x01, 0x43\n\t"  /* orrs r1, r0 */
            ".byte 0x09, 0x04\n\t"  /* lsls r1, r1, #16 */
            ".byte 0x09, 0x0c\n\t"  /* lsrs r1, r1, #16 */
            "movs r0, #0x52\n\t"
            "bl SetGpuReg\n\t"
            : : : "r0", "r1", "lr");
#endif
        if (task->data[1] == 10)
        {
            task->data[10] = 256;
            task->data[11] = 256;
            task->func = AnimTask_RolePlaySilhouette_Step2;
        }
    }
}

static void AnimTask_RolePlaySilhouette_Step2(u8 taskId)
{
    u8 spriteId = gTasks[taskId].data[0];
    gTasks[taskId].data[10] -= 16;
    gTasks[taskId].data[11] += 128;
    gSprites[spriteId].oam.affineMode |= ST_OAM_AFFINE_DOUBLE_MASK;
    TrySetSpriteRotScale(&gSprites[spriteId], TRUE, gTasks[taskId].data[10], gTasks[taskId].data[11], 0);
    if (++gTasks[taskId].data[12] == 9)
    {
        ResetSpriteRotScale_PreserveAffine(&gSprites[spriteId]);
        DestroySpriteAndFreeResources_(&gSprites[spriteId]);
        gTasks[taskId].func = DestroyAnimVisualTaskAndDisableBlend;
    }
}

void AnimTask_AcidArmor(u8 taskId)
{
    u8 battler;
    u16 bgX, bgY;
    s16 y, i;
    struct ScanlineEffectParams scanlineParams;
    struct Task *task = &gTasks[taskId];

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    task->data[0] = 0;
    task->data[1] = 0;
    task->data[2] = 0;
    task->data[3] = 16;
    task->data[4] = 0;
    task->data[5] = battler;
    task->data[6] = 32;
    task->data[7] = 0;
    task->data[8] = 24;

    if (GetBattlerSide(battler) == B_SIDE_OPPONENT)
        task->data[8] *= -1;

    task->data[13] = GetBattlerYCoordWithElevation(battler) - 34;
    if (task->data[13] < 0)
        task->data[13] = 0;

    task->data[14] = task->data[13] + 66;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    if (GetBattlerSpriteBGPriorityRank(battler) == 1)
    {
        scanlineParams.dmaDest = &REG_BG1HOFS;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG1);
        bgX = gBattle_BG1_X;
        bgY = gBattle_BG1_Y;
    }
    else
    {
        scanlineParams.dmaDest = &REG_BG2HOFS;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND | BLDCNT_TGT1_BG2);
        bgX = gBattle_BG2_X;
        bgY = gBattle_BG2_Y;
    }

    for (y = 0, i = 0; y < 160; y++, i += 2)
    {
        gScanlineEffectRegBuffers[0][i] = bgX;
        gScanlineEffectRegBuffers[1][i] = bgX;
        gScanlineEffectRegBuffers[0][i + 1] = bgY;
        gScanlineEffectRegBuffers[1][i + 1] = bgY;
    }

    scanlineParams.dmaControl = SCANLINE_EFFECT_DMACNT_32BIT;
    scanlineParams.initState = 1;
    scanlineParams.unused9 = 0;
    ScanlineEffect_SetParams(scanlineParams);
    task->func = AnimTask_AcidArmor_Step;
}

static void AnimTask_AcidArmor_Step(u8 taskId)
{
    struct Task *task;
    s16 var1;
    s16 var2;
    s16 bgX, bgY;
    s16 offset;
    s16 var0;
    s16 i;
    s16 sineIndex;
    s16 var3;
#ifdef NON_MATCHING
    u16 bldAlpha;
#endif

    task = &gTasks[taskId];
    if (GetBattlerSpriteBGPriorityRank(task->data[5]) == 1)
    {
        bgX = gBattle_BG1_X;
        bgY = gBattle_BG1_Y;
    }
    else
    {
        bgX = gBattle_BG2_X;
        bgY = gBattle_BG2_Y;
    }

    switch (task->data[0])
    {
    case 0:
        offset = task->data[14] * 2;
        var1 = 0;
        var2 = 0;
        i = 0;
        task->data[1] = (task->data[1] + 2) & 0xFF;
        sineIndex = task->data[1];
        task->data[9] = 0x7E0 / task->data[6];
        task->data[10] = -((task->data[7] * 2) / task->data[9]);
        task->data[11] = task->data[7];
        var3 = task->data[11] >> 5;
        task->data[12] = var3;
        var0 = task->data[14];
        while (var0 > task->data[13])
        {
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][offset + 1] = (i - var2) + bgY;
            gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][offset] = bgX + var3 + (gSineTable[sineIndex] >> 5);
            sineIndex = (sineIndex + 10) & 0xFF;
            task->data[11] += task->data[10];
            var3 = task->data[11] >> 5;
            task->data[12] = var3;

            i++;
            offset -= 2;
            var1 += task->data[6];
            var2 = var1 >> 5;
            var0--;
        }

        var0 *= 2;
        while (var0 >= 0)
        {
            gScanlineEffectRegBuffers[0][var0] = bgX + DISPLAY_WIDTH;
            gScanlineEffectRegBuffers[1][var0] = bgX + DISPLAY_WIDTH;
            var0 -= 2;
        }

        if (++task->data[6] > 63)
        {
            task->data[6] = 64;
            task->data[2]++;
            if (task->data[2] & 1)
                task->data[3]--;
            else
                task->data[4]++;

#ifdef NON_MATCHING
            bldAlpha = BLDALPHA_BLEND(task->data[3], task->data[4]);
            SetGpuReg(REG_OFFSET_BLDALPHA, bldAlpha);
#else
            /* agbcc computes the blend in r0; the ROM builds it in r1. */
            __asm__ volatile(
                ".byte 0x31, 0x8a\n\t"  /* ldrh r1, [r6, #16] */
                ".byte 0x09, 0x02\n\t"  /* lsls r1, r1, #8 */
                ".byte 0xf0, 0x89\n\t"  /* ldrh r0, [r6, #14] */
                ".byte 0x01, 0x43\n\t"  /* orrs r1, r0 */
                ".byte 0x09, 0x04\n\t"  /* lsls r1, r1, #16 */
                ".byte 0x09, 0x0c\n\t"  /* lsrs r1, r1, #16 */
                "movs r0, #0x52\n\t"
                "bl SetGpuReg\n\t"
                : : : "r0", "r1", "lr");
#endif
            if (task->data[3] == 0 && task->data[4] == 16)
            {
                task->data[2] = 0;
                task->data[3] = 0;
                task->data[0]++;
            }
        }
        else
        {
            task->data[7] += task->data[8];
        }
        break;
    case 1:
        if (++task->data[2] > 12)
        {
            gScanlineEffect.state = 3;
            task->data[2] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        task->data[2]++;
        if (task->data[2] & 1)
            task->data[3]++;
        else
            task->data[4]--;

#ifdef NON_MATCHING
        bldAlpha = BLDALPHA_BLEND(task->data[3], task->data[4]);
        SetGpuReg(REG_OFFSET_BLDALPHA, bldAlpha);
#else
        __asm__ volatile(
            ".byte 0x31, 0x8a\n\t"  /* ldrh r1, [r6, #16] */
            ".byte 0x09, 0x02\n\t"  /* lsls r1, r1, #8 */
            ".byte 0xf0, 0x89\n\t"  /* ldrh r0, [r6, #14] */
            ".byte 0x01, 0x43\n\t"  /* orrs r1, r0 */
            ".byte 0x09, 0x04\n\t"  /* lsls r1, r1, #16 */
            ".byte 0x09, 0x0c\n\t"  /* lsrs r1, r1, #16 */
            "movs r0, #0x52\n\t"
            "bl SetGpuReg\n\t"
            : : : "r0", "r1", "lr");
#endif
        if (task->data[3] == 16 && task->data[4] == 0)
        {
            task->data[2] = 0;
            task->data[3] = 0;
            task->data[0]++;
        }
        break;
    case 3:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

void AnimTask_DeepInhale(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    task->data[0] = 0;
    task->data[15] = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    PrepareAffineAnimInTaskData(&gTasks[taskId], task->data[15], gDeepInhaleAffineAnimCmds);
    task->func = AnimTask_DeepInhale_Step;
}

static void AnimTask_DeepInhale_Step(u8 taskId)
{
    u16 var0;

    struct Task *task = &gTasks[taskId];
    var0 = task->data[0];
    task->data[0]++;
    var0 -= 20;
    if (var0 < 23)
    {
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            task->data[2]++;
            if (task->data[2] & 1)
                gSprites[task->data[15]].x2 = 1;
            else
                gSprites[task->data[15]].x2 = -1;
        }
    }
    else
    {
        gSprites[task->data[15]].x2 = 0;
    }

    if (!RunAffineAnimFromTaskData(&gTasks[taskId]))
        DestroyAnimVisualTask(taskId);
}

static void InitYawnCloudPosition(struct Sprite *sprite, s16 startX, s16 startY, s16 destX, s16 destY, u16 duration)
{
    sprite->x = startX;
    sprite->y = startY;
    sprite->data[4] = startX << 4;
    sprite->data[5] = startY << 4;
    sprite->data[6] = ((destX - startX) << 4) / duration;
    sprite->data[7] = ((destY - startY) << 4) / duration;
}

static void UpdateYawnCloudPosition(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[6];
    sprite->data[5] += sprite->data[7];
    sprite->x = sprite->data[4] >> 4;
    sprite->y = sprite->data[5] >> 4;
}

static void AnimYawnCloud(struct Sprite *sprite)
{
    s16 destX = sprite->x;
    s16 destY = sprite->y;

    SetSpriteCoordsToAnimAttackerCoords(sprite);
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[0]);
    InitYawnCloudPosition(sprite, sprite->x, sprite->y, destX, destY, 64);
    sprite->data[0] = 0;
    sprite->callback = AnimYawnCloud_Step;
}

static void AnimYawnCloud_Step(struct Sprite *sprite)
{
    int index;

    sprite->data[0]++;
    index = (sprite->data[0] * 8) & 0xFF;
    UpdateYawnCloudPosition(sprite);
    sprite->y2 = Sin(index, 8);
    if (sprite->data[0] > 58)
    {
        if (++sprite->data[1] > 1)
        {
            sprite->data[1] = 0;
            sprite->data[2]++;
            sprite->invisible = sprite->data[2] & 1;
            if (sprite->data[2] > 3)
                DestroySpriteAndMatrix(sprite);
        }
    }
}

static void AnimSmokeBallEscapeCloud(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[3];
    StartSpriteAffineAnim(sprite, gBattleAnimArgs[0]);
    if (GetBattlerSide(gBattleAnimTarget) != B_SIDE_PLAYER)
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + gBattleAnimArgs[1];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[2];
    sprite->callback = DestroyAnimSpriteAfterTimer;
}

static void AnimTask_SlideMonForFocusBand_Step2(u8 taskId)
{
    u16 var0 = 0;
    u16 var1 = 0;

    gTasks[taskId].data[0]--;
    if ((gTasks[taskId].data[6] & 0x8000) && (--gTasks[taskId].data[1] == -1))
    {
        if (gTasks[taskId].data[9] == 0)
        {
            gTasks[taskId].data[9] = gTasks[taskId].data[4];
            gTasks[taskId].data[4] = -gTasks[taskId].data[4];
        }
        else
        {
            gTasks[taskId].data[9] = 0;
        }

        if (gTasks[taskId].data[10] == 0)
        {
            gTasks[taskId].data[10] = gTasks[taskId].data[5];
            gTasks[taskId].data[5] = -gTasks[taskId].data[5];
        }
        else
        {
            gTasks[taskId].data[10] = 0;
        }

        gTasks[taskId].data[1] = gTasks[taskId].data[13];
    }

    var0 = gTasks[taskId].data[7];
    var1 = gTasks[taskId].data[8];
    if (gTasks[taskId].data[2] & 0x8000)
        gSprites[gTasks[taskId].data[15]].x2 = gTasks[taskId].data[9] - (var0 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].x2 = gTasks[taskId].data[9] + (var0 >> 8);

    if (gTasks[taskId].data[3] & 0x8000)
        gSprites[gTasks[taskId].data[15]].y2 = gTasks[taskId].data[10] - (var1 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].y2 = gTasks[taskId].data[10] + (var1 >> 8);

    if (gTasks[taskId].data[0] < 1)
    {
        DestroyTask(taskId);
        gAnimVisualTaskCount--;
    }
}

static void AnimTask_SlideMonForFocusBand_Step1(u8 taskId)
{
    u16 var0 = 0;
    u16 var1 = 0;

    gTasks[taskId].data[0]--;
    if ((gTasks[taskId].data[6] & 0x8000) && (--gTasks[taskId].data[1] == -1))
    {
        if (gTasks[taskId].data[9] == 0)
        {
            gTasks[taskId].data[9] = gTasks[taskId].data[4];
            gTasks[taskId].data[4] = -gTasks[taskId].data[4];
        }
        else
        {
            gTasks[taskId].data[9] = var0;
        }

        if (gTasks[taskId].data[10] == 0)
        {
            gTasks[taskId].data[10] = gTasks[taskId].data[5];
            gTasks[taskId].data[5] = -gTasks[taskId].data[5];
        }
        else
        {
            gTasks[taskId].data[10] = 0;
        }

        gTasks[taskId].data[1] = gTasks[taskId].data[13];
    }

    var0 = (gTasks[taskId].data[2] & 0x7FFF) + gTasks[taskId].data[7];
    var1 = (gTasks[taskId].data[3] & 0x7FFF) + gTasks[taskId].data[8];
    if (gTasks[taskId].data[2] & 0x8000)
        gSprites[gTasks[taskId].data[15]].x2 = gTasks[taskId].data[9] - (var0 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].x2 = gTasks[taskId].data[9] + (var0 >> 8);

    if (gTasks[taskId].data[3] & 0x8000)
        gSprites[gTasks[taskId].data[15]].y2 = gTasks[taskId].data[10] - (var1 >> 8);
    else
        gSprites[gTasks[taskId].data[15]].y2 = gTasks[taskId].data[10] + (var1 >> 8);

    gTasks[taskId].data[7] = var0;
    gTasks[taskId].data[8] = var1;
    if (gTasks[taskId].data[0] < 1)
    {
        gTasks[taskId].data[0] = 30;
        gTasks[taskId].data[13] = 0;
        gTasks[taskId].func = AnimTask_SlideMonForFocusBand_Step2;
    }
}

void AnimTask_SlideMonForFocusBand(u8 taskId)
{
    gTasks[taskId].data[15] = gBattlerSpriteIds[gBattleAnimAttacker];
    gTasks[taskId].data[14] = gBattleAnimArgs[0];
    gTasks[taskId].data[0] = gBattleAnimArgs[0];
    gTasks[taskId].data[13] = gBattleAnimArgs[6];
    if (gBattleAnimArgs[3])
        gTasks[taskId].data[6] = gTasks[taskId].data[6] | -0x8000;

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gTasks[taskId].data[2] = gBattleAnimArgs[1];
        gTasks[taskId].data[3] = gBattleAnimArgs[2];
    }
    else
    {
        if (gBattleAnimArgs[1] & 0x8000)
            gTasks[taskId].data[2] = gBattleAnimArgs[1] & 0x7FFF;
        else
            gTasks[taskId].data[2] = gBattleAnimArgs[1] | -0x8000;

        if (gBattleAnimArgs[2] & 0x8000)
            gTasks[taskId].data[3] = gBattleAnimArgs[2] & 0x7FFF;
        else
            gTasks[taskId].data[3] = gBattleAnimArgs[2] | -0x8000;
    }

    gTasks[taskId].data[8] = 0;
    gTasks[taskId].data[7] = 0;
    gTasks[taskId].data[4] = gBattleAnimArgs[4];
    gTasks[taskId].data[5] = gBattleAnimArgs[5];
    gTasks[taskId].func = AnimTask_SlideMonForFocusBand_Step1;
}

#define IDX_ACTIVE_SPRITES 2  // Used by the sprite callback to modify the number of active sprites

// Task data for AnimTask_SquishAndSweatDroplets
#define tState           data[0]
#define tTimer           data[1]
#define tActiveSprites   data[IDX_ACTIVE_SPRITES]
#define tNumSquishes     data[3]
#define tBaseX           data[4]
#define tBaseY           data[5]
#define tSubpriority     data[6]
// data[7]-data[15] used by PrepareAffineAnimInTaskData
#define tBattlerSpriteId data[15]

// Sprite data for AnimFacadeSweatDrop
#define sTimer            data[0]
#define sVelocX           data[1]
#define sVelocY           data[2]
#define sTaskId           data[3]
#define sActiveSpritesIdx data[4]

void AnimTask_SquishAndSweatDroplets(u8 taskId)
{
    u8 battler;
    struct Task *task = &gTasks[taskId];

    if (!gBattleAnimArgs[1])
        DestroyAnimVisualTask(taskId);

    task->tState = 0;
    task->tTimer = 0;
    task->tActiveSprites = 0;
    task->tNumSquishes = gBattleAnimArgs[1];
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    task->tBaseX = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
    task->tBaseY = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y);
    task->tSubpriority = GetBattlerSpriteSubpriority(battler);
    task->tBattlerSpriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    PrepareAffineAnimInTaskData(task, task->tBattlerSpriteId, gFacadeSquishAffineAnimCmds);
    task->func = AnimTask_SquishAndSweatDroplets_Step;
}

static void AnimTask_SquishAndSweatDroplets_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        task->tTimer++;
        if (task->tTimer == 6)
            CreateSweatDroplets(taskId, TRUE);

        if (task->tTimer == 18)
            CreateSweatDroplets(taskId, FALSE);

        if (!RunAffineAnimFromTaskData(task))
        {
            if (--task->tNumSquishes == 0)
            {
                // Animation is finished
                task->tState++;
            }
            else
            {
                // Animation continues, more droplet sprites to create
                task->tTimer = 0;
                PrepareAffineAnimInTaskData(task, task->tBattlerSpriteId, gFacadeSquishAffineAnimCmds);
            }
        }
        break;
    case 1:
        // Wait for sprites to be destroyed before ending task
        if (task->tActiveSprites == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void CreateSweatDroplets(u8 taskId, bool8 lowerDroplets)
{
    u8 i;
    s8 xOffset, yOffset;
    struct Task *task;
    s16 xCoords[4];
    s16 yCoords[2];

    task = &gTasks[taskId];
    if (!lowerDroplets)
    {
        xOffset = 18;
        yOffset = -20;
    }
    else
    {
        xOffset = 30;
        yOffset = 20;
    }

    xCoords[0] = task->tBaseX - xOffset;
    xCoords[1] = task->tBaseX - xOffset - 4;
    xCoords[2] = task->tBaseX + xOffset;
    xCoords[3] = task->tBaseX + xOffset + 4;
    yCoords[0] = task->tBaseY + yOffset;
    yCoords[1] = task->tBaseY + yOffset + 6;

    for (i = 0; i < 4; i++)
    {
        u8 spriteId = CreateSprite(&gFacadeSweatDropSpriteTemplate, xCoords[i], yCoords[i & 1], task->tSubpriority - 5);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].sTimer = 0;
            gSprites[spriteId].sVelocX = i < 2 ? -2 : 2; // First two travel left, remaining travel right
            gSprites[spriteId].sVelocY = -1;
            gSprites[spriteId].sTaskId = taskId;
            gSprites[spriteId].sActiveSpritesIdx = IDX_ACTIVE_SPRITES;
            task->tActiveSprites++;
        }
    }
}

static void AnimFacadeSweatDrop(struct Sprite *sprite)
{
    sprite->x += sprite->sVelocX;
    sprite->y += sprite->sVelocY;
    if (++sprite->sTimer > 6)
    {
        gTasks[sprite->sTaskId].data[sprite->sActiveSpritesIdx]--;
        DestroySprite(sprite);
    }
}

#undef IDX_ACTIVE_SPRITES
#undef tState
#undef tTimer
#undef tActiveSprites
#undef tNumSquishes
#undef tBaseX
#undef tBaseY
#undef tSubpriority
#undef tBattlerSpriteId
#undef sTimer
#undef sVelocX
#undef sVelocY
#undef sTaskId
#undef sActiveSpritesIdx

void AnimTask_FacadeColorBlend(u8 taskId)
{
    u8 spriteId;

    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = gBattleAnimArgs[1];
    spriteId = GetAnimBattlerSpriteId(gBattleAnimArgs[0]);
    gTasks[taskId].data[2] = OBJ_PLTT_ID(gSprites[spriteId].oam.paletteNum);
    gTasks[taskId].func = AnimTask_FacadeColorBlend_Step;
}

void AnimTask_StatusClearedEffect(u8 taskId)
{
    StartMonScrollingBgMask(
        taskId,
        0,
        0x1A0,
        gBattleAnimAttacker,
        gBattleAnimArgs[0],
        10,
        2,
        30,
        gCureBubblesGfx,
        gCureBubblesTilemap,
        (const u32 *)((const u8 *)gCureBubblesTilemap - 0x20));  // == gCureBubblesPal in the JP layout
}

static void AnimTask_FacadeColorBlend_Step(u8 taskId)
{
    if (gTasks[taskId].data[1])
    {
        BlendPalette(gTasks[taskId].data[2], 16, 8, gFacadeBlendColors[gTasks[taskId].data[0]]);
        if (++gTasks[taskId].data[0] > 23)
            gTasks[taskId].data[0] = 0;

        gTasks[taskId].data[1]--;
    }
    else
    {
        BlendPalette(gTasks[taskId].data[2], 16, 0, RGB_BLACK);
        DestroyAnimVisualTask(taskId);
    }
}

static void AnimRoarNoiseLine(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[0];
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + gBattleAnimArgs[1];
    if (gBattleAnimArgs[2] == 0)
    {
        sprite->data[0] = 0x280;
        sprite->data[1] = -0x280;
    }
    else if (gBattleAnimArgs[2] == 1)
    {
        sprite->vFlip = 1;
        sprite->data[0] = 0x280;
        sprite->data[1] = 0x280;
    }
    else
    {
        StartSpriteAnim(sprite, 1);
        sprite->data[0] = 0x280;
    }

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->data[0] = -sprite->data[0];
        sprite->hFlip = 1;
    }

    sprite->callback = AnimRoarNoiseLine_Step;
}

static void AnimRoarNoiseLine_Step(struct Sprite *sprite)
{
    sprite->data[6] += sprite->data[0];
    sprite->data[7] += sprite->data[1];
    sprite->x2 = sprite->data[6] >> 8;
    sprite->y2 = sprite->data[7] >> 8;
    if (++sprite->data[5] == 14)
        DestroyAnimSprite(sprite);
}

#define IDX_ACTIVE_SPRITES 10  // Used by the sprite callback to modify the number of active sprites

// Task data for AnimTask_GlareEyeDots
#define tState         data[0]
#define tTimer         data[1]
#define tPairNum       data[2]
#define tPairMax       data[5]
#define tDotOffset     data[6]
#define tIsContest     data[7]
#define tActiveSprites data[IDX_ACTIVE_SPRITES]
#define tStartX        data[11]
#define tStartY        data[12]
#define tEndX          data[13]
#define tEndY          data[14]

// Sprite data for AnimGlareEyeDot
#define sTimer            data[0]
#define sTaskId           data[1]
#define sActiveSpritesIdx data[2]

void AnimTask_GlareEyeDots(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (IsContest())
    {
        task->tPairMax = 8;
        task->tDotOffset = 3;
        task->tIsContest = TRUE;
    }
    else
    {
        task->tPairMax = 12;
        task->tDotOffset = 3;
        task->tIsContest = FALSE;
    }

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        task->tStartX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_HEIGHT) / 4;
    else
        task->tStartX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) - GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_HEIGHT) / 4;

    task->tStartY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) - GetBattlerSpriteCoordAttr(gBattleAnimAttacker, BATTLER_COORD_ATTR_HEIGHT) / 4;
    task->tEndX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    task->tEndY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    task->func = AnimTask_GlareEyeDots_Step;
}

static void AnimTask_GlareEyeDots_Step(u8 taskId)
{
    u8 i;
    s16 x, y;
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case 0:
        // Wait to create next pair of dots
        if (++task->tTimer > 3)
        {
            task->tTimer = 0;
            GetGlareEyeDotCoords(
                task->tStartX,
                task->tStartY,
                task->tEndX,
                task->tEndY,
                task->tPairMax,
                task->tPairNum,
                &x,
                &y);

            // Create dot pair
            for (i = 0; i < 2; i++)
            {
                u8 spriteId = CreateSprite(&gGlareEyeDotSpriteTemplate, x, y, 35);
                if (spriteId != MAX_SPRITES)
                {
                    if (!task->tIsContest)
                    {
                        if (i == 0)
                            gSprites[spriteId].x2 = gSprites[spriteId].y2 = -task->tDotOffset;
                        else
                            gSprites[spriteId].x2 = gSprites[spriteId].y2 = task->tDotOffset;
                    }
                    else
                    {
                        if (i == 0)
                        {
                            gSprites[spriteId].x2 = -task->tDotOffset;
                            gSprites[spriteId].y2 = task->tDotOffset;
                        }
                        else
                        {
                            gSprites[spriteId].x2 = task->tDotOffset;
                            gSprites[spriteId].y2 = -task->tDotOffset;
                        }
                    }

                    gSprites[spriteId].sTimer = 0;
                    gSprites[spriteId].sTaskId = taskId;
                    gSprites[spriteId].sActiveSpritesIdx = IDX_ACTIVE_SPRITES;
                    task->tActiveSprites++;
                }
            }

            if (task->tPairNum == task->tPairMax)
                task->tState++;

            task->tPairNum++;
        }
        break;
    case 1:
        // Wait for sprites to be destroyed before ending task
        if (task->tActiveSprites == 0)
            DestroyAnimVisualTask(taskId);
        break;
    }
}

static void GetGlareEyeDotCoords(s16 startX, s16 startY, s16 endX, s16 endY, u8 pairMax, u8 pairNum, s16 *x, s16 *y)
{
    int x2;
    int y2;

    if (pairNum == 0)
    {
        *x = startX;
        *y = startY;
        return;
    }

    if (pairNum >= pairMax)
    {
        *x = endX;
        *y = endY;
        return;
    }

    pairMax--;
    x2 = (startX << 8) + pairNum * (((endX - startX) << 8) / pairMax);
    y2 = (startY << 8) + pairNum * (((endY - startY) << 8) / pairMax);
    *x = x2 >> 8;
    *y = y2 >> 8;
}

static void AnimGlareEyeDot(struct Sprite *sprite)
{
    if (++sprite->sTimer > 36)
    {
        gTasks[sprite->sTaskId].data[sprite->sActiveSpritesIdx]--;
        DestroySprite(sprite);
    }
}

static void AnimAssistPawprint(struct Sprite *sprite)
{
    sprite->x = gBattleAnimArgs[0];
    sprite->y = gBattleAnimArgs[1];
    sprite->data[2] = gBattleAnimArgs[2];
    sprite->data[4] = gBattleAnimArgs[3];
    sprite->data[0] = gBattleAnimArgs[4];
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = StartAnimLinearTranslation;  // JP uses StartAnimLinearTranslation (0x080A6988), not InitAndRunAnimFastLinearTranslation
}

void AnimTask_BarrageBall(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[11] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    task->data[12] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    task->data[13] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    task->data[14] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_HEIGHT) / 4;
    task->data[15] = CreateSprite(&gBarrageBallSpriteTemplate, task->data[11], task->data[12], GetBattlerSpriteSubpriority(gBattleAnimTarget) - 5);
    if (task->data[15] != MAX_SPRITES)
    {
        gSprites[task->data[15]].data[0] = 16;
        gSprites[task->data[15]].data[2] = task->data[13];
        gSprites[task->data[15]].data[4] = task->data[14];
        gSprites[task->data[15]].data[5] = -32;
        InitAnimArcTranslation(&gSprites[task->data[15]]);
        if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_OPPONENT)
            StartSpriteAffineAnim(&gSprites[task->data[15]], 1);

        task->func = AnimTask_BarrageBall_Step;
    }
    else
    {
        DestroyAnimVisualTask(taskId);
    }
}

static void AnimTask_BarrageBall_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            TranslateAnimHorizontalArc(&gSprites[task->data[15]]);
            if (++task->data[2] > 7)
                task->data[0]++;
        }
        break;
    case 1:
        if (TranslateAnimHorizontalArc(&gSprites[task->data[15]]))
        {
            task->data[1] = 0;
            task->data[2] = 0;
            task->data[0]++;
        }
        break;
    case 2:
        if (++task->data[1] > 1)
        {
            task->data[1] = 0;
            task->data[2]++;
            gSprites[task->data[15]].invisible = task->data[2] & 1;
            if (task->data[2] == 16)
            {
                FreeOamMatrix(gSprites[task->data[15]].oam.matrixNum);
                DestroySprite(&gSprites[task->data[15]]);
                task->data[0]++;
            }
        }
        break;
    case 3:
        DestroyAnimVisualTask(taskId);
        break;
    }
}

static void AnimSmellingSaltsHand(struct Sprite *sprite)
{
    u8 battler;

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    sprite->oam.tileNum += 16;
    sprite->data[6] = gBattleAnimArgs[2];
    sprite->data[7] = gBattleAnimArgs[1] == 0 ? -1 : 1;
    sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET);
    if (gBattleAnimArgs[1] == 0)
    {
        sprite->oam.matrixNum |= ST_OAM_HFLIP;
        sprite->x = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_LEFT) - 8;
    }
    else
    {
        sprite->x = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_RIGHT) + 8;
    }

    sprite->callback = AnimSmellingSaltsHand_Step;
}

static void AnimSmellingSaltsHand_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[1] > 1)
        {
            sprite->data[1] = 0;
            sprite->x2 += sprite->data[7];
            if (++sprite->data[2] == 12)
                sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] == 8)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 2:
        sprite->x2 -= sprite->data[7] * 4;
        if (++sprite->data[1] == 6)
        {
            sprite->data[1] = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->x2 += sprite->data[7] * 3;
        if (++sprite->data[1] == 8)
        {
            if (--sprite->data[6])
            {
                sprite->data[1] = 0;
                sprite->data[0]--;
            }
            else
            {
                DestroyAnimSprite(sprite);
            }
        }
        break;
    }
}

#undef IDX_ACTIVE_SPRITES
#undef tState
#undef tTimer
#undef tPairNum
#undef tPairMax
#undef tDotOffset
#undef tIsContest
#undef tActiveSprites
#undef tStartX
#undef tStartY
#undef tEndX
#undef tEndY
#undef sTimer
#undef sTaskId
#undef sActiveSpritesIdx
