#include "global.h"
#include "battle_anim.h"
#include "bg.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "trig.h"
#include "constants/battle_anim.h"
#include "constants/songs.h"

extern u8 gAnimVisualTaskCount;
extern const struct SpriteTemplate gThoughtBubbleSpriteTemplate;
extern const union AffineAnimCmd sAffineAnims_Torment[];
extern const union AffineAnimCmd DefenseCurlDeformMonAffineAnimCmds[];
extern const union AffineAnimCmd gStockpileDeformMonAffineAnimCmds[];
extern const union AffineAnimCmd gSpitUpDeformMonAffineAnimCmds[];
extern const union AffineAnimCmd gSwallowDeformMonAffineAnimCmds[];
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
void AnimTask_StockpileDeformMon(u8 taskId);
void AnimTask_SpitUpDeformMon(u8 taskId);
void AnimTask_SwallowDeformMon(u8 taskId);

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
