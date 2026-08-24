#include "global.h"

extern bool32 sIsSummaryAnim;
extern void (*const sMonAnimFunctions[])(struct Sprite *sprite);
extern const u8 gUnknown_85D3328[];
extern const u8 gUnknown_85D34E0[][2];
extern const union AffineAnimCmd *const gUnknown_85D37C8[];
extern const s8 gUnknown_85D37D0[][3];
extern const s8 gUnknown_85D381E[][3];
#include "pokemon_animation.h"
#include "sprite.h"
#include "task.h"
#include "main.h"

struct PokemonAnimData
{
    u16 delay;
    s16 speed;
    s16 runs;
    s16 rotation;
    s16 data;
    s16 unused;
};

extern struct PokemonAnimData gUnknown_3001240[];
extern u8 gUnknown_3001270;
void SpriteCB_SetDummyOnAnimEnd(struct Sprite *sprite);
extern void SpriteCB_SetDummyOnAnimEnd_Thumb(struct Sprite *sprite) __asm__("SpriteCB_SetDummyOnAnimEnd + 1");
extern void CircleCounterclockwise_Thumb(struct Sprite *sprite) __asm__("CircleCounterclockwise + 1");
void BackAndLunge_0(struct Sprite *sprite);
void BackAndLunge_1(struct Sprite *sprite);
void BackAndLunge_2(struct Sprite *sprite);
void BackAndLunge_3(struct Sprite *sprite);
void BackAndLunge_4(struct Sprite *sprite);
void BackFlip_0(struct Sprite *sprite);
void BackFlip_1(struct Sprite *sprite);
void BackFlip_2(struct Sprite *sprite);
void BackFlipBig_0(struct Sprite *sprite);
void BackFlipBig_1(struct Sprite *sprite);
void BackFlipBig_2(struct Sprite *sprite);
void FrontFlip_0(struct Sprite *sprite);
void FrontFlip_1(struct Sprite *sprite);
void FrontFlip_2(struct Sprite *sprite);
void TumblingFrontFlip(struct Sprite *sprite);
void Figure8(struct Sprite *sprite);
void RotateUpSlamDown_0(struct Sprite *sprite);
void RotateUpSlamDown_1(struct Sprite *sprite);
void RotateUpSlamDown_2(struct Sprite *sprite);
void HorizontalJumpsVerticalStretch_0(struct Sprite *sprite);
void HorizontalJumpsVerticalStretch_2(struct Sprite *sprite);
void TipHopForward_0(struct Sprite *sprite);
void TipHopForward_1(struct Sprite *sprite);
void TipHopForward_2(struct Sprite *sprite);
void TipAndShake_0(struct Sprite *sprite);
void TipAndShake_1(struct Sprite *sprite);
void TipAndShake_2(struct Sprite *sprite);
void TipAndShake_3(struct Sprite *sprite);
void SpringRising_0(struct Sprite *sprite);
void SpringRising_1(struct Sprite *sprite);

void MonAnimDummySpriteCallback(struct Sprite *sprite) {}
void SetPosForRotation(struct Sprite *sprite, u16 index, s16 amplitudeX, s16 amplitudeY)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern s16 Cos(s16 index, s16 amplitude);
    s16 xAdder;
    s16 yAdder;

    amplitudeX *= -1;
    amplitudeY *= -1;

    xAdder = Cos(index, amplitudeX) - Sin(index, amplitudeY);
    yAdder = Cos(index, amplitudeY) + Sin(index, amplitudeX);

    amplitudeX *= -1;
    amplitudeY *= -1;

    sprite->x2 = xAdder + amplitudeX;
    sprite->y2 = yAdder + amplitudeY;
}
u8 GetSpeciesBackAnimSet(u16 species)
{
    if (gUnknown_85D3328[species] != 0)
        return gUnknown_85D3328[species] - 1;
    else
        return 0;
}

void Task_HandleMonAnimation(u8 taskId)
{
    u32 i;
    struct Sprite *sprite = (struct Sprite *)((gTasks[taskId].data[1] << 16) | gTasks[taskId].data[2]);

    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[4] = sprite->data[0];
        gTasks[taskId].data[5] = sprite->data[2];
        sprite->data[1] = 1;
        sprite->data[0] = 0;

        for (i = 2; i < 8; i++)
            sprite->data[i] = 0;

        sprite->callback = sMonAnimFunctions[gTasks[taskId].data[3]];
        sIsSummaryAnim = FALSE;
        gTasks[taskId].data[0]++;
    }

    if (sprite->callback == SpriteCallbackDummy)
    {
        sprite->data[0] = gTasks[taskId].data[4];
        sprite->data[2] = gTasks[taskId].data[5];
        sprite->data[1] = 0;
        DestroyTask(taskId);
    }
}

void LaunchAnimationTaskForFrontSprite(struct Sprite *sprite, u8 frontAnimId)
{
    extern void Task_HandleMonAnimation_Thumb(u8 taskId) __asm__("Task_HandleMonAnimation + 1");
    u8 taskId = CreateTask(Task_HandleMonAnimation_Thumb, 128);

    gTasks[taskId].data[1] = (u32)sprite >> 16;
    gTasks[taskId].data[2] = (u32)sprite;
    gTasks[taskId].data[3] = frontAnimId;
}
void StartMonSummaryAnimation(struct Sprite *sprite, u8 frontAnimId)
{
    sIsSummaryAnim = TRUE;
    sprite->callback = sMonAnimFunctions[frontAnimId];
}

void LaunchAnimationTaskForBackSprite(struct Sprite *sprite, u8 backAnimSet)
{
    extern void Task_HandleMonAnimation_Thumb(u8 taskId) __asm__("Task_HandleMonAnimation + 1");
    extern u16 gBattlerPartyIndexes[];
    extern const u8 gUnknown_85D378F[];
    extern const u8 gUnknown_85D3744[];
    u8 nature;
    u8 taskId;
    u8 animId;
    u8 battler;

    taskId = CreateTask(Task_HandleMonAnimation_Thumb, 128);
    gTasks[taskId].data[1] = (u32)sprite >> 16;
    gTasks[taskId].data[2] = (u32)sprite;
    battler = sprite->data[0];
    nature = GetNature(&gPlayerParty[gBattlerPartyIndexes[battler]]);
    animId = 3 * backAnimSet + gUnknown_85D378F[nature];
    gTasks[taskId].data[3] = gUnknown_85D3744[animId];
}
void SetSpriteCB_MonAnimDummy(struct Sprite *sprite)
{
    sprite->callback = MonAnimDummySpriteCallback;
}

void SetAffineData(struct Sprite *sprite, s16 xScale, s16 yScale, u16 rotation)
{
    u8 matrixNum;
    struct ObjAffineSrcData affineSrcData;
    struct OamMatrix dest;

    affineSrcData.xScale = xScale;
    affineSrcData.yScale = yScale;
    affineSrcData.rotation = rotation;
    matrixNum = sprite->oam.matrixNum;

    ObjAffineSet(&affineSrcData, &dest, 1, 2);
    gOamMatrices[matrixNum].a = dest.a;
    gOamMatrices[matrixNum].b = dest.b;
    gOamMatrices[matrixNum].c = dest.c;
    gOamMatrices[matrixNum].d = dest.d;
}

void HandleStartAffineAnim(struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    sprite->affineAnims = gUnknown_85D37C8;

    if (sIsSummaryAnim == TRUE)
        InitSpriteAffineAnim(sprite);

    if (sprite->data[1] == 0)
        StartSpriteAffineAnim(sprite, 1);
    else
        StartSpriteAffineAnim(sprite, 0);

    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    sprite->affineAnimPaused = TRUE;
}

void HandleSetAffineData(struct Sprite *sprite, s16 xScale, s16 yScale, u16 rotation)
{
    if (sprite->data[1] == 0)
    {
        xScale = -xScale;
        rotation = -rotation;
    }

    SetAffineData(sprite, xScale, yScale, rotation);
}

void TryFlipX(struct Sprite *sprite)
{
    if (sprite->data[1] == 0)
    {
        s16 xOffset = sprite->x2;

        sprite->x2 = -xOffset;
    }
}

bool32 sub_0817F5D0(u8 id)
{
    if (id >= 4)
    {
        return FALSE;
    }
    else
    {
        gUnknown_3001240[id].rotation = 0;
        gUnknown_3001240[id].delay = 0;
        gUnknown_3001240[id].runs = 1;
        gUnknown_3001240[id].speed = 0;
        gUnknown_3001240[id].data = 0;
        return TRUE;
    }
}

u8 AddNewAnim(void)
{
    gUnknown_3001270 = (gUnknown_3001270 + 1) % 4;
    sub_0817F5D0(gUnknown_3001270);
    return gUnknown_3001270;
}

void ResetSpriteAfterAnim(struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);

    if (sIsSummaryAnim == TRUE)
    {
        if (sprite->data[1] == 0)
            sprite->hFlip = TRUE;
        else
            sprite->hFlip = FALSE;

        FreeOamMatrix(sprite->oam.matrixNum);
        sprite->oam.matrixNum |= (sprite->hFlip << 3);
        sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    }
}

void Anim_CircularStretchTwice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 var = (sprite->data[2] * 512 / 40) % 256;

        sprite->data[4] = Sin(var, 32) + 256;
        sprite->data[5] = Cos(var, 32) + 256;
        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void Anim_HorizontalVibrate(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        sprite->x2 = 0;
    }
    else
    {
        s8 sign;

        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->x2 = Sin((sprite->data[2] * 128 / 40) % 256, 6) * sign;
    }

    sprite->data[2]++;
}

void HorizontalSlide(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[2] > sprite->data[0])
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        sprite->x2 = Sin((s16)((sprite->data[2] * 384 / sprite->data[0]) % 256), 6);
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

void Anim_HorizontalSlide(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    HorizontalSlide(sprite);
    sprite->callback = HorizontalSlide;
}

void VerticalSlide(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[2] > sprite->data[0])
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = -(Sin((s16)((sprite->data[2] * 384 / sprite->data[0]) % 256), 6));
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}


void Anim_VerticalSlide(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    VerticalSlide(sprite);
    sprite->callback = VerticalSlide;
}

void VerticalJumps(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 384)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s16 divCounter = counter / 128;

        switch (divCounter)
        {
        case 0:
        case 1:
            sprite->y2 = -(Sin((s16)(counter % 128), (s16)(sprite->data[0] * 2)));
            break;
        case 2:
        case 3:
            counter -= 256;
            sprite->y2 = -(Sin((s16)counter, (s16)(sprite->data[0] * 3)));
            break;
        }
    }

    sprite->data[2] += 12;
}

void Anim_VerticalJumps_Big(struct Sprite *sprite)
{
    sprite->data[0] = 4;
    VerticalJumps(sprite);
    sprite->callback = VerticalJumps;
}

void Anim_VerticalJumpsHorizontalJumps(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 768)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s16 divCounter = counter / 128;

        switch (divCounter)
        {
        case 0:
        case 1:
            sprite->x2 = 0;
            break;
        case 2:
            counter = 0;
            break;
        case 3:
            sprite->x2 = -(counter % 128 * 8) / 128;
            break;
        case 4:
            sprite->x2 = counter % 128 / 8 - 8;
            break;
        case 5:
            sprite->x2 = -(counter % 128 * 8) / 128 + 8;
            break;
        }

        sprite->y2 = -(Sin((s16)(counter % 128), 8));
    }

    sprite->data[2] += 12;
}

void Anim_GrowVibrate(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] * 256 / 40) % 256;

        if (sprite->data[2] % 2 == 0)
        {
            sprite->data[4] = Sin(index, 32) + 256;
            sprite->data[5] = Sin(index, 32) + 256;
        }
        else
        {
            sprite->data[4] = Sin(index, 8) + 256;
            sprite->data[5] = Sin(index, 8) + 256;
        }

        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void Zigzag(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[2] == 0)
        sprite->data[3] = 0;

    if (gUnknown_85D37D0[sprite->data[3]][2] == sprite->data[2])
    {
        if (gUnknown_85D37D0[sprite->data[3]][2] == 0)
        {
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[3]++;
            sprite->data[2] = 0;
        }
    }

    if (gUnknown_85D37D0[sprite->data[3]][2] == 0)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->x2 += gUnknown_85D37D0[sprite->data[3]][0];
        sprite->y2 += gUnknown_85D37D0[sprite->data[3]][1];
        sprite->data[2]++;
        TryFlipX(sprite);
    }
}

void Anim_ZigzagFast(struct Sprite *sprite)
{
    Zigzag(sprite);
    sprite->callback = Zigzag;
}

void HorizontalShake(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 2304)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        sprite->x2 = Sin((s16)(counter % 256), sprite->data[7]);
    }

    sprite->data[2] += sprite->data[0];
}

void Anim_HorizontalShake(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sprite->data[7] = 3;
    HorizontalShake(sprite);
    sprite->callback = HorizontalShake;
}

void VerticalShake(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 2304)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = Sin((s16)(counter % 256), 3);
    }

    sprite->data[2] += sprite->data[0];
}

void Anim_VerticalShake(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    VerticalShake(sprite);
    sprite->callback = VerticalShake;
}

void Anim_CircularVibrate(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern s16 Cos(s16 index, s16 amplitude);
    s8 sign;
    s32 index;
    s32 amplitude;

    if (sprite->data[2] > 512)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        amplitude = Sin(sprite->data[2] / 4, 8);
        index = sprite->data[2] % 256;

        sprite->y2 = Sin(index, amplitude) * sign;
        sprite->x2 = Cos(index, amplitude) * sign;
    }

    sprite->data[2] += 9;
}
void Twist(struct Sprite *sprite)
{
    s16 id = sprite->data[0];

    if (gUnknown_3001240[id].delay != 0)
    {
        gUnknown_3001240[id].delay--;
    }
    else
    {
        if (sprite->data[2] == 0 && gUnknown_3001240[id].data == 0)
        {
            HandleStartAffineAnim(sprite);
            gUnknown_3001240[id].data++;
        }

        if (sprite->data[2] > gUnknown_3001240[id].rotation)
        {
            HandleSetAffineData(sprite, 256, 256, 0);
            if (gUnknown_3001240[id].runs > 1)
            {
                gUnknown_3001240[id].runs--;
                gUnknown_3001240[id].delay = 10;
                sprite->data[2] = 0;
            }
            else
            {
                ResetSpriteAfterAnim(sprite);
                sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            }
        }
        else
        {
            sprite->data[6] = Sin((s16)(sprite->data[2] % 256), 4096);
            HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
        }

        sprite->data[2] += 16;
    }
}

void Anim_Twist(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 512;
    gUnknown_3001240[id].delay = 0;
    Twist(sprite);
    sprite->callback = Twist;
}

void Spin(struct Sprite *sprite)
{
    u8 id = sprite->data[0];

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > gUnknown_3001240[id].delay)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = (65536 / gUnknown_3001240[id].data) * sprite->data[2];
        HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
    }

    sprite->data[2]++;
}

void Anim_Spin_Long(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].delay = 60;
    gUnknown_3001240[id].data = 20;
    Spin(sprite);
    sprite->callback = Spin;
}

void CircleCounterclockwise(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern s16 Cos(s16 index, s16 amplitude);
    u8 id = sprite->data[0];

    TryFlipX(sprite);

    if (sprite->data[2] > gUnknown_3001240[id].rotation)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
    }
    else
    {
        s16 index = (sprite->data[2] + 192) % 256;

        sprite->x2 = -(Cos(index, gUnknown_3001240[id].data * 2));
        sprite->y2 = Sin(index, gUnknown_3001240[id].data) + gUnknown_3001240[id].data;
    }

    sprite->data[2] += gUnknown_3001240[id].speed;
    TryFlipX(sprite);
}
void Anim_CircleCounterclockwise(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 512;
    gUnknown_3001240[id].data = 6;
    gUnknown_3001240[id].speed = 24;
    CircleCounterclockwise(sprite);
    sprite->callback = CircleCounterclockwise_Thumb;
}
void Anim_GlowBlack(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);

    if (sprite->data[2] > 128)
    {
        BlendPalette((u16)sprite->data[7], 16, 0, 0);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 16);
        BlendPalette((u16)sprite->data[7], 16, (u8)sprite->data[6], 0);
    }

    sprite->data[2]++;
}

void Anim_HorizontalStretch(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index2 = (sprite->data[2] * 128) / 40;
        if (sprite->data[2] >= 10 && sprite->data[2] <= 29)
        {
            sprite->data[7] += 51;
            index1 = 0xFF & sprite->data[7];
        }

        if (!sprite->data[1])
            sprite->data[4] = (Sin(index2, 40) - 256) + Sin(index1, 16);
        else
            sprite->data[4] = (256 - Sin(index2, 40)) - Sin(index1, 16);

        sprite->data[5] = Sin(index2, 16) + 256;
        SetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void Anim_VerticalStretch(struct Sprite *sprite)
{
    s16 posY = 0, index1 = 0, index2 = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->y2 = posY;
    }
    else
    {
        index2 = (sprite->data[2] * 128) / 40;
        if (sprite->data[2] >= 10 && sprite->data[2] <= 29)
        {
            sprite->data[7] += 51;
            index1 = 0xFF & sprite->data[7];
        }

        if (!sprite->data[1])
            sprite->data[4] = -(Sin(index2, 16)) - 256;
        else
            sprite->data[4] = Sin(index2, 16) + 256;

        sprite->data[5] = (256 - Sin(index2, 40)) - Sin(index1, 8);

        if (sprite->data[5] != 256)
            posY = (256 - sprite->data[5]) / 8;
        sprite->y2 = -(posY);
        SetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void VerticalShakeTwice(struct Sprite *sprite)
{
    u8 index = sprite->data[2];
    u8 var7 = sprite->data[6];
    u8 var5 = gUnknown_85D34E0[sprite->data[5]][0];
    u8 var6 = gUnknown_85D34E0[sprite->data[5]][1];
    u8 amplitude = 0;

    if (var5 != (u8)-2)
        amplitude = (var6 - var7) * var5 / var6;
    else
        amplitude = 0;

    if (var5 == (u8)-1)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = Sin(index, amplitude);

        if (var7 == var6)
        {
            sprite->data[5]++;
            sprite->data[6] = 0;
        }
        else
        {
            sprite->data[2] += sprite->data[0];
            sprite->data[6]++;
        }
    }
}

void Anim_VerticalShakeTwice(struct Sprite *sprite)
{
    sprite->data[0] = 48;
    VerticalShakeTwice(sprite);
    sprite->callback = VerticalShakeTwice;
}

void Anim_TipMoveForward(struct Sprite *sprite)
{
    u8 counter = 0;

    TryFlipX(sprite);
    counter = sprite->data[2];

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 35)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->x2 = 0;
    }
    else
    {
        s16 index = ((counter - 10) * 128) / 20;

        if (counter < 10)
            HandleSetAffineData(sprite, 256, 256, counter / 2 * 512);
        else if (counter >= 10 && counter <= 29)
            sprite->x2 = -(Sin(index, 5));
        else
            HandleSetAffineData(sprite, 256, 256, (35 - counter) / 2 * 1024);
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

void Anim_HorizontalPivot(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / 100;

        sprite->y2 = Sin(index, 10);
        HandleSetAffineData(sprite, 256, 256, Sin(index, 3276));
    }

    sprite->data[2]++;
}

void VerticalSlideWobble(struct Sprite *sprite)
{
    s32 var = 0;
    s16 index = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->y2 = Sin(index, sprite->data[0]);
        HandleSetAffineData(sprite, 256, 256, Sin((s16)var, 3276));
    }

    sprite->data[2]++;
}

void Anim_VerticalSlideWobble(struct Sprite *sprite)
{
    sprite->data[0] = 10;
    VerticalSlideWobble(sprite);
    sprite->callback = VerticalSlideWobble;
}

void RisingWobble(struct Sprite *sprite)
{
    s32 var = 0;
    s16 index = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->y2 = -(Sin(index / 2, (s16)(sprite->data[0] * 2)));
        HandleSetAffineData(sprite, 256, 256, Sin((s16)var, 3276));
    }

    sprite->data[2]++;
}

void Anim_RisingWobble(struct Sprite *sprite)
{
    sprite->data[0] = 5;
    RisingWobble(sprite);
    sprite->callback = RisingWobble;
}

void Anim_HorizontalSlideWobble(struct Sprite *sprite)
{
    s32 var;
    s16 index = 0;

    TryFlipX(sprite);
    var = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->x2 = Sin(index, 8);
        HandleSetAffineData(sprite, 256, 256, Sin((s16)var, 3276));
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

void VerticalSquishBounce(struct Sprite *sprite)
{
    s16 posY = 0;

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[3] = 0;
    }

    TryFlipX(sprite);

    if (sprite->data[2] > sprite->data[0] * 3)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 yScale = Sin(sprite->data[4], 32) + 256;

        if (sprite->data[2] > sprite->data[0] && sprite->data[2] < sprite->data[0] * 2)
            sprite->data[3] += 128 / sprite->data[0];

        if (yScale > 256)
            posY = (256 - yScale) / 8;

        sprite->y2 = -(Sin(sprite->data[3], 10)) - posY;
        HandleSetAffineData(sprite, 256 - Sin(sprite->data[4], 32), yScale, 0);
        sprite->data[2]++;
        sprite->data[4] = (sprite->data[4] + 128 / sprite->data[0]) & 0xFF;
    }

    TryFlipX(sprite);
}

void Anim_VerticalSquishBounce(struct Sprite *sprite)
{
    sprite->data[0] = 16;
    VerticalSquishBounce(sprite);
    sprite->callback = VerticalSquishBounce;
}

void ShrinkGrow(struct Sprite *sprite)
{
    s16 posY = 0;

    if (sprite->data[2] > (128 / sprite->data[6]) * sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 yScale = Sin(sprite->data[4], 32) + 256;

        if (yScale > 256)
            posY = (256 - yScale) / 8;

        sprite->y2 = -posY;
        HandleSetAffineData(sprite, Sin(sprite->data[4], 48) + 256, yScale, 0);
        sprite->data[2]++;
        sprite->data[4] = (sprite->data[4] + sprite->data[6]) & 0xFF;
    }
}

void Anim_ShrinkGrow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 3;
        sprite->data[6] = 8;
    }

    ShrinkGrow(sprite);
}

void BounceRotateToSides(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern const s8 gUnknown_85D37EE[][8][3];
    s16 var;
    u8 structId;
    s8 r9;
    s16 r10;
    s16 r7;
    u32 arrId;

    TryFlipX(sprite);
    structId = sprite->data[0];
    var = gUnknown_3001240[structId].rotation;
    r9 = gUnknown_85D37EE[gUnknown_3001240[structId].data][sprite->data[4]][0];
    r10 = gUnknown_85D37EE[gUnknown_3001240[structId].data][sprite->data[4]][1] - r9;
    arrId = gUnknown_3001240[structId].data;
    r7 = sprite->data[3];

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    if (gUnknown_85D37EE[arrId][sprite->data[4]][2] == 0)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
    }
    else
    {
        u16 rotation;

        sprite->y2 = -(Sin(r7 * 128 / gUnknown_85D37EE[arrId][sprite->data[4]][2], 10));
        sprite->x2 = (r10 * r7 / gUnknown_85D37EE[arrId][sprite->data[4]][2]) + r9;
        rotation = -(var * sprite->x2) / 8;
        HandleSetAffineData(sprite, 256, 256, rotation);

        if (r7 == gUnknown_85D37EE[arrId][sprite->data[4]][2])
        {
            sprite->data[4]++;
            sprite->data[3] = 0;
        }
        else
        {
            sprite->data[3]++;
        }
    }

    TryFlipX(sprite);
}
void Anim_BounceRotateToSides(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 4096;
    gUnknown_3001240[id].data = sprite->data[6];
    BounceRotateToSides(sprite);
    sprite->callback = BounceRotateToSides;
}

void Anim_GlowOrange(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);

    if (sprite->data[2] > 128)
    {
        BlendPalette((u16)sprite->data[7], 16, 0, 0x2DF);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette((u16)sprite->data[7], 16, (u8)sprite->data[6], 0x2DF);
    }

    sprite->data[2] += 2;
}

void Anim_GlowRed(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);

    if (sprite->data[2] > 128)
    {
        BlendPalette((u16)sprite->data[7], 16, 0, 0x1F);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette((u16)sprite->data[7], 16, (u8)sprite->data[6], 0x1F);
    }

    sprite->data[2] += 2;
}

void Anim_GlowBlue(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);

    if (sprite->data[2] > 128)
    {
        BlendPalette((u16)sprite->data[7], 16, 0, 0x7C00);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette((u16)sprite->data[7], 16, (u8)sprite->data[6], 0x7C00);
    }

    sprite->data[2] += 2;
}

void Anim_GlowYellow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);

    if (sprite->data[2] > 128)
    {
        BlendPalette((u16)sprite->data[7], 16, 0, 0x3FF);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette((u16)sprite->data[7], 16, (u8)sprite->data[6], 0x3FF);
    }

    sprite->data[2] += 2;
}

void Anim_GlowPurple(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);

    if (sprite->data[2] > 128)
    {
        BlendPalette((u16)sprite->data[7], 16, 0, 0x6018);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette((u16)sprite->data[7], 16, (u8)sprite->data[6], 0x6018);
    }

    sprite->data[2] += 2;
}
void Anim_BackAndLunge(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = BackAndLunge_0;
}

void BackAndLunge_0(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (++sprite->x2 > 7)
    {
        sprite->x2 = 8;
        sprite->data[7] = 2;
        sprite->callback = BackAndLunge_1;
    }

    TryFlipX(sprite);
}

void BackAndLunge_1(struct Sprite *sprite)
{
    s16 subResult;
    u8 var;

    TryFlipX(sprite);
    sprite->x2 -= sprite->data[7];
    sprite->data[7]++;

    if (sprite->x2 <= 0)
    {
        var = sprite->data[7];
        sprite->data[6] = 0;
        subResult = sprite->x2;

        do
        {
            subResult -= var;
            sprite->data[6]++;
            var++;
        } while (subResult > -8);

        sprite->data[5] = 1;
        sprite->callback = BackAndLunge_2;
    }

    TryFlipX(sprite);
}

void BackAndLunge_2(struct Sprite *sprite)
{
    u8 rotation;

    TryFlipX(sprite);
    sprite->x2 -= sprite->data[7];
    sprite->data[7]++;
    rotation = (sprite->data[5] * 6) / sprite->data[6];

    if (++sprite->data[5] > sprite->data[6])
        sprite->data[5] = sprite->data[6];

    HandleSetAffineData(sprite, 256, 256, rotation * 256);

    if (sprite->x2 < -8)
    {
        sprite->x2 = -8;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[2] = rotation;
        sprite->callback = BackAndLunge_3;
    }

    TryFlipX(sprite);
}

void BackAndLunge_3(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[3] > 11)
    {
        sprite->data[2] -= 2;

        if (sprite->data[2] < 0)
            sprite->data[2] = 0;

        HandleSetAffineData(sprite, 256, 256, sprite->data[2] << 8);

        if (sprite->data[2] == 0)
            sprite->callback = BackAndLunge_4;
    }
    else
    {
        sprite->x2 += sprite->data[4];
        sprite->data[4] *= -1;
        sprite->data[3]++;
    }

    TryFlipX(sprite);
}

void BackAndLunge_4(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 += 2;

    if (sprite->x2 > 0)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    TryFlipX(sprite);
}

void Anim_BackFlip(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    sprite->callback = BackFlip_0;
}

void BackFlip_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2++;
    sprite->y2--;

    if (sprite->x2 % 2 == 0 && sprite->data[3] <= 0)
        sprite->data[3] = 10;

    if (sprite->x2 > 7)
    {
        sprite->x2 = 8;
        sprite->y2 = -8;
        sprite->data[4] = 0;
        sprite->callback = BackFlip_1;
    }

    TryFlipX(sprite);
}

void BackFlip_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 = Cos(sprite->data[4], 16) - 8;
    sprite->y2 = Sin(sprite->data[4], 16) - 8;

    if (sprite->data[4] > 63)
    {
        sprite->data[2] = 160;
        sprite->data[3] = 10;
        sprite->callback = BackFlip_2;
    }

    sprite->data[4] += 8;

    if (sprite->data[4] > 64)
        sprite->data[4] = 64;

    TryFlipX(sprite);
}

void BackFlip_2(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[3] > 0)
    {
        sprite->data[3]--;
    }
    else
    {
        u32 rotation;

        sprite->x2 = Cos(sprite->data[2], 5) - 4;
        sprite->y2 = -(Sin(sprite->data[2], 5)) + 4;
        sprite->data[2] -= 4;
        rotation = sprite->data[2] - 32;
        HandleSetAffineData(sprite, 256, 256, rotation * 512);

        if (sprite->data[2] <= 32)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
    }

    TryFlipX(sprite);
}

void Anim_Flicker(struct Sprite *sprite)
{
    if (sprite->data[3] > 0)
    {
        sprite->data[3]--;
    }
    else
    {
        sprite->data[4] = (sprite->data[4] == 0) ? TRUE : FALSE;
        sprite->invisible = sprite->data[4];

        if (++sprite->data[2] > 19)
        {
            sprite->invisible = FALSE;
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }

        sprite->data[3] = 2;
    }
}

void Anim_BackFlipBig(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = BackFlipBig_0;
}

void BackFlipBig_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2--;
    sprite->y2++;

    if (sprite->x2 <= -16)
    {
        sprite->x2 = -16;
        sprite->y2 = 16;
        sprite->callback = BackFlipBig_1;
        sprite->data[2] = 160;
    }

    TryFlipX(sprite);
}

void BackFlipBig_1(struct Sprite *sprite)
{
    u32 rotation;

    TryFlipX(sprite);
    sprite->data[2] -= 4;
    sprite->x2 = Cos(sprite->data[2], 22);
    sprite->y2 = -(Sin(sprite->data[2], 22));
    rotation = sprite->data[2] - 32;
    HandleSetAffineData(sprite, 256, 256, rotation * 512);

    if (sprite->data[2] <= 32)
        sprite->callback = BackFlipBig_2;

    TryFlipX(sprite);
}

void BackFlipBig_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2--;
    sprite->y2++;

    if (sprite->x2 <= 0)
    {
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    TryFlipX(sprite);
}

void Anim_FrontFlip(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = FrontFlip_0;
}

void FrontFlip_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2++;
    sprite->y2--;

    if (sprite->x2 > 15)
    {
        sprite->data[2] = 0;
        sprite->callback = FrontFlip_1;
    }

    TryFlipX(sprite);
}

void FrontFlip_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[2] += 16;

    if (sprite->x2 <= -16)
    {
        sprite->x2 = -16;
        sprite->y2 = 16;
        sprite->data[2] = 0;
        sprite->callback = FrontFlip_2;
    }
    else
    {
        sprite->x2 -= 2;
        sprite->y2 += 2;
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[2] << 8);
    TryFlipX(sprite);
}

void FrontFlip_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2++;
    sprite->y2--;

    if (sprite->x2 >= 0)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    TryFlipX(sprite);
}


void Anim_TumblingFrontFlip(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].speed = 2;
    TumblingFrontFlip(sprite);
    sprite->callback = TumblingFrontFlip;
}

void TumblingFrontFlip(struct Sprite *sprite)
{
    if (gUnknown_3001240[sprite->data[0]].delay != 0)
    {
        gUnknown_3001240[sprite->data[0]].delay--;
    }
    else
    {
        TryFlipX(sprite);
        if (sprite->data[2] == 0)
        {
            sprite->data[2]++;
            HandleStartAffineAnim(sprite);
            sprite->data[7] = gUnknown_3001240[sprite->data[0]].speed;
            sprite->data[3] = -1;
            sprite->data[4] = -1;
            sprite->data[5] = 0;
            sprite->data[6] = 0;
        }

        sprite->x2 += (sprite->data[7] * 2 * sprite->data[3]);
        sprite->y2 += (sprite->data[7] * sprite->data[4]);
        sprite->data[6] += 8;
        if (sprite->x2 <= -16 || sprite->x2 >= 16)
        {
            sprite->x2 = sprite->data[3] * 16;
            sprite->data[3] *= -1;
            sprite->data[5]++;
        }
        else if (sprite->y2 <= -16 || sprite->y2 >= 16)
        {
            sprite->y2 = sprite->data[4] * 16;
            sprite->data[4] *= -1;
            sprite->data[5]++;
        }

        if (sprite->data[5] > 5 && sprite->x2 <= 0)
        {
            sprite->x2 = 0;
            sprite->y2 = 0;
            if (gUnknown_3001240[sprite->data[0]].runs > 1)
            {
                gUnknown_3001240[sprite->data[0]].runs--;
                sprite->data[5] = 0;
                sprite->data[6] = 0;
                gUnknown_3001240[sprite->data[0]].delay = 10;
            }
            else
            {
                ResetSpriteAfterAnim(sprite);
                sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            }
        }

        HandleSetAffineData(sprite, 256, 256, sprite->data[6] << 8);
        TryFlipX(sprite);
    }
}

void Anim_Figure8(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[6] = 0;
    sprite->data[7] = 0;
    sprite->callback = Figure8;
}

void Figure8(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[6] += 4;
    sprite->x2 = -(Sin(sprite->data[6], 16));
    sprite->y2 = -(Sin((sprite->data[6] * 2) & 0xFF, 8));

    if (sprite->data[6] > 192 && sprite->data[7] == 1)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->data[7]++;
    }
    else if (sprite->data[6] > 64 && sprite->data[7] == 0)
    {
        HandleSetAffineData(sprite, -256, 256, 0);
        sprite->data[7]++;
    }

    if (sprite->data[6] > 255)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    TryFlipX(sprite);
}

void Anim_FlashYellow(struct Sprite *sprite)
{
    extern const u8 gUnknown_85D34C4[][2];

    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = (sprite->oam.paletteNum << 4) + 256;
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
    }

    if (gUnknown_85D34C4[sprite->data[6]][1] == (u8)-1)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
    }
    else
    {
        if (sprite->data[4] == 1)
        {
            if (gUnknown_85D34C4[sprite->data[6]][0])
                BlendPalette((u16)sprite->data[7], 16, 16, 0x3FF);
            else
                BlendPalette((u16)sprite->data[7], 16, 0, 0x3FF);

            sprite->data[4] = 0;
        }

        if (gUnknown_85D34C4[sprite->data[6]][1] == sprite->data[5])
        {
            sprite->data[4] = 1;
            sprite->data[5] = 0;
            sprite->data[6]++;
        }
        else
        {
            sprite->data[5]++;
        }
    }
}

void SwingConcave(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    TryFlipX(sprite);
    if (sprite->data[2] > gUnknown_3001240[sprite->data[0]].data)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        if (gUnknown_3001240[sprite->data[0]].runs > 1)
        {
            gUnknown_3001240[sprite->data[0]].runs--;
            sprite->data[2] = 0;
        }
        else
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / gUnknown_3001240[sprite->data[0]].data;

        sprite->x2 = -(Sin(index, 10));
        HandleSetAffineData(sprite, 256, 256, Sin(index, 3276));
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

void Anim_SwingConcave_FastShort(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].data = 50;
    SwingConcave(sprite);
    sprite->callback = SwingConcave;
}

void SwingConvex(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    TryFlipX(sprite);
    if (sprite->data[2] > gUnknown_3001240[sprite->data[0]].data)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        if (gUnknown_3001240[sprite->data[0]].runs > 1)
        {
            gUnknown_3001240[sprite->data[0]].runs--;
            sprite->data[2] = 0;
        }
        else
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / gUnknown_3001240[sprite->data[0]].data;

        sprite->x2 = -(Sin(index, 10));
        HandleSetAffineData(sprite, 256, 256, -(Sin(index, 3276)));
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}

void Anim_SwingConvex_FastShort(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].data = 50;
    SwingConvex(sprite);
    sprite->callback = SwingConvex;
}

void Anim_RotateUpSlamDown(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[6] = -(14 * sprite->centerToCornerVecX / 10);
    sprite->data[7] = 128;
    sprite->callback = RotateUpSlamDown_0;
}

void RotateUpSlamDown_0(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern s16 Cos(s16 index, s16 amplitude);
    extern void RotateUpSlamDown_1_Thumb(struct Sprite *sprite) __asm__("RotateUpSlamDown_1 + 1");

    TryFlipX(sprite);
    sprite->data[7]--;
    sprite->x2 = sprite->data[6] + Cos(sprite->data[7], sprite->data[6]);
    sprite->y2 = -(Sin(sprite->data[7], sprite->data[6]));
    HandleSetAffineData(sprite, 256, 256, (sprite->data[7] - 128) << 8);

    if (sprite->data[7] <= 120)
    {
        sprite->data[7] = 120;
        sprite->data[3] = 0;
        sprite->callback = RotateUpSlamDown_1_Thumb;
    }

    TryFlipX(sprite);
}
void RotateUpSlamDown_1(struct Sprite *sprite)
{
    if (sprite->data[3] == 20)
    {
        sprite->callback = RotateUpSlamDown_2;
        sprite->data[3] = 0;
    }

    sprite->data[3]++;
}

void RotateUpSlamDown_2(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern s16 Cos(s16 index, s16 amplitude);
    extern void Anim_VerticalShake_Thumb(struct Sprite *sprite) __asm__("Anim_VerticalShake + 1");

    TryFlipX(sprite);
    sprite->data[7] += 2;
    sprite->x2 = sprite->data[6] + Cos(sprite->data[7], sprite->data[6]);
    sprite->y2 = -(Sin(sprite->data[7], sprite->data[6]));
    HandleSetAffineData(sprite, 256, 256, (sprite->data[7] - 128) << 8);

    if (sprite->data[7] >= 128)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->data[2] = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = Anim_VerticalShake_Thumb;
    }

    TryFlipX(sprite);
}
void DeepVerticalSquishBounce(struct Sprite *sprite)
{
    if (gUnknown_3001240[sprite->data[0]].delay != 0)
    {
        gUnknown_3001240[sprite->data[0]].delay--;
    }
    else
    {
        if (sprite->data[2] == 0)
        {
            HandleStartAffineAnim(sprite);
            sprite->data[4] = 0;
            sprite->data[5] = 0;
            sprite->data[2] = 1;
        }

        if (sprite->data[5] == 0)
        {
            sprite->data[7] = Sin(sprite->data[4], 256);
            sprite->y2 = Sin(sprite->data[4], 16);
            sprite->data[6] = Sin(sprite->data[4], 32);
            HandleSetAffineData(sprite, 256 - sprite->data[6], 256 + sprite->data[7], 0);

            if (sprite->data[4] == 128)
            {
                sprite->data[4] = 0;
                sprite->data[5] = 1;
            }
        }
        else if (sprite->data[5] == 1)
        {
            sprite->data[7] = Sin(sprite->data[4], 32);
            sprite->y2 = -Sin(sprite->data[4], 8);
            sprite->data[6] = Sin(sprite->data[4], 128);
            HandleSetAffineData(sprite, 256 + sprite->data[6], 256 - sprite->data[7], 0);

            if (sprite->data[4] == 128)
            {
                if (gUnknown_3001240[sprite->data[0]].runs > 1)
                {
                    gUnknown_3001240[sprite->data[0]].runs--;
                    gUnknown_3001240[sprite->data[0]].delay = 10;
                    sprite->data[4] = 0;
                    sprite->data[5] = 0;
                }
                else
                {
                    HandleSetAffineData(sprite, 256, 256, 0);
                    ResetSpriteAfterAnim(sprite);
                    sprite->callback = SpriteCB_SetDummyOnAnimEnd;
                }
            }
        }

        sprite->data[4] += gUnknown_3001240[sprite->data[0]].rotation;
    }
}

void Anim_DeepVerticalSquishBounce(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 4;
    DeepVerticalSquishBounce(sprite);
    sprite->callback = DeepVerticalSquishBounce;
}

void Anim_HorizontalJumps(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    TryFlipX(sprite);
    if (counter > 512)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        switch (sprite->data[2] / 128)
        {
        case 0:
            sprite->x2 = -(counter % 128 * 8) / 128;
            break;
        case 1:
            sprite->x2 = (counter % 128 / 16) - 8;
            break;
        case 2:
            sprite->x2 = counter % 128 / 16;
            break;
        case 3:
            sprite->x2 = -(counter % 128 * 8) / 128 + 8;
            break;
        }
        sprite->y2 = -(Sin((s16)(counter % 128), 8));
    }

    sprite->data[2] += 12;
    TryFlipX(sprite);
}

void Anim_HorizontalJumpsVerticalStretch(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].data = -1;
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    HorizontalJumpsVerticalStretch_0(sprite);
    sprite->callback = HorizontalJumpsVerticalStretch_0;
}

void HorizontalJumpsVerticalStretch_0(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern void HorizontalJumpsVerticalStretch_1_Thumb(struct Sprite *sprite) __asm__("HorizontalJumpsVerticalStretch_1 + 1");

    if (gUnknown_3001240[sprite->data[0]].delay != 0)
    {
        gUnknown_3001240[sprite->data[0]].delay--;
    }
    else
    {
        s32 counter;

        TryFlipX(sprite);
        counter = sprite->data[2];
        if (sprite->data[2] > 128)
        {
            sprite->data[2] = 0;
            sprite->callback = HorizontalJumpsVerticalStretch_1_Thumb;
        }
        else
        {
            s32 var = 8 * gUnknown_3001240[sprite->data[0]].data;

            sprite->x2 = var * (counter % 128) / 128;
            sprite->y2 = -(Sin(counter % 128, 8));
            sprite->data[2] += 12;
        }

        TryFlipX(sprite);
    }
}
void HorizontalJumpsVerticalStretch_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 48)
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->y2 = 0;
        sprite->data[2] = 0;
        sprite->callback = HorizontalJumpsVerticalStretch_2;
    }
    else
    {
        s16 yDelta;
        s16 yScale = Sin(sprite->data[4], 64) + 256;

        if (sprite->data[2] >= 16 && sprite->data[2] <= 31)
        {
            sprite->data[3] += 8;
            sprite->x2 -= gUnknown_3001240[sprite->data[0]].data;
        }

        yDelta = 0;
        if (yScale > 256)
            yDelta = (256 - yScale) / 8;

        sprite->y2 = -(Sin(sprite->data[3], 20)) - yDelta;
        HandleSetAffineData(sprite, 256 - Sin(sprite->data[4], 32), yScale, 0);
        sprite->data[2]++;
        sprite->data[4] += 8;
        sprite->data[4] &= 0xFF;
    }

    TryFlipX(sprite);
}

void HorizontalJumpsVerticalStretch_2(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern void HorizontalJumpsVerticalStretch_0_Thumb(struct Sprite *sprite) __asm__("HorizontalJumpsVerticalStretch_0 + 1");

    s32 counter;

    TryFlipX(sprite);
    counter = sprite->data[2];
    if (counter > 128)
    {
        if (gUnknown_3001240[sprite->data[0]].runs > 1)
        {
            gUnknown_3001240[sprite->data[0]].runs--;
            gUnknown_3001240[sprite->data[0]].delay = 10;
            sprite->data[3] = 0;
            sprite->data[2] = 0;
            sprite->data[4] = 0;
            sprite->callback = HorizontalJumpsVerticalStretch_0_Thumb;
        }
        else
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        }

        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s32 var = gUnknown_3001240[sprite->data[0]].data;

        sprite->x2 = var * ((counter % 128) * 8) / 128 + 8 * -var;
        sprite->y2 = -(Sin(counter % 128, 8));
    }

    sprite->data[2] += 12;
    TryFlipX(sprite);
}

void RotateToSides(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    TryFlipX(sprite);
    if (sprite->data[7] > 254)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (gUnknown_3001240[sprite->data[0]].runs > 1)
        {
            gUnknown_3001240[sprite->data[0]].runs--;
            sprite->data[2] = 0;
            sprite->data[7] = 0;
        }
        else
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }

        TryFlipX(sprite);
    }
    else
    {
        u16 rotation;

        sprite->x2 = -(Sin(sprite->data[7], 16));
        rotation = Sin(sprite->data[7], 32);
        HandleSetAffineData(sprite, 256, 256, rotation << 8);
        sprite->data[7] += gUnknown_3001240[sprite->data[0]].rotation;
        TryFlipX(sprite);
    }
}

void Anim_RotateToSides_Fast(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 4;
    RotateToSides(sprite);
    sprite->callback = RotateToSides;
}

void Anim_RotateUpToSides(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
    }

    TryFlipX(sprite);
    if (sprite->data[7] > 254)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        TryFlipX(sprite);
    }
    else
    {
        u16 rotation;

        sprite->x2 = -(Sin(sprite->data[7], 16));
        sprite->y2 = -(Sin((s16)(sprite->data[7] % 128), 16));
        rotation = Sin(sprite->data[7], 32);
        HandleSetAffineData(sprite, 256, 256, rotation << 8);
        sprite->data[7] += 8;
        TryFlipX(sprite);
    }
}

void Anim_FlickerIncreasing(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = 0;

    if (sprite->data[2] == sprite->data[7])
    {
        sprite->data[7] = 0;
        sprite->data[2]++;
        sprite->invisible = FALSE;
    }
    else
    {
        sprite->data[7]++;
        sprite->invisible = TRUE;
    }

    if (sprite->data[2] > 10)
    {
        sprite->invisible = FALSE;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
}

void Anim_TipHopForward(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->callback = TipHopForward_0;
}

void TipHopForward_0(struct Sprite *sprite)
{
    if (sprite->data[7] > 31)
    {
        sprite->data[7] = 32;
        sprite->data[2] = 0;
        sprite->callback = TipHopForward_1;
    }
    else
    {
        sprite->data[7] += 4;
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[7] << 8);
}

void TipHopForward_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 512)
    {
        sprite->callback = TipHopForward_2;
        sprite->data[6] = 0;
    }
    else
    {
        sprite->x2 = -(sprite->data[2] * 16) / 512;
        sprite->y2 = -(Sin(sprite->data[2] % 128, 4));
        sprite->data[2] += 12;
    }

    TryFlipX(sprite);
}

void TipHopForward_2(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    TryFlipX(sprite);
    sprite->data[7] -= 2;
    if (sprite->data[7] < 0)
    {
        sprite->data[7] = 0;
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
    }
    else
    {
        sprite->x2 = -(Sin(sprite->data[7] * 2, 16));
    }

    HandleSetAffineData(sprite, 256, 256, sprite->data[7] << 8);
    TryFlipX(sprite);
}
void Anim_PivotShake(struct Sprite *sprite)
{
    u16 rotation;

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    TryFlipX(sprite);
    if (sprite->data[7] > 255)
    {
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[7] = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[7] += 16;
        sprite->x2 = -(Sin(sprite->data[7] % 128, 8));
        sprite->y2 = -(Sin(sprite->data[7] % 128, 8));
    }

    rotation = Sin(sprite->data[7] % 128, 16);
    HandleSetAffineData(sprite, 256, 256, rotation << 8);
    TryFlipX(sprite);
}

void Anim_TipAndShake(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->data[4] = 0;
    sprite->callback = TipAndShake_0;
}

void TipAndShake_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[7] > 24)
    {
        if (++sprite->data[4] > 4)
        {
            sprite->data[4] = 0;
            sprite->callback = TipAndShake_1;
        }
    }
    else
    {
        sprite->data[7] += 2;
        sprite->x2 = Sin(sprite->data[7], 8);
        sprite->y2 = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    TryFlipX(sprite);
}

void TipAndShake_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[7] > 32)
    {
        sprite->data[6] = 1;
        sprite->callback = TipAndShake_2;
    }
    else
    {
        sprite->data[7] += 2;
        sprite->x2 = Sin(sprite->data[7], 8);
        sprite->y2 = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    TryFlipX(sprite);
}

void TipAndShake_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->data[7] += (sprite->data[6] * 4);
    if (sprite->data[5] > 9)
    {
        sprite->data[7] = 32;
        sprite->callback = TipAndShake_3;
    }

    sprite->x2 = Sin(sprite->data[7], 8);
    sprite->y2 = -(Sin(sprite->data[7], 8));
    if (sprite->data[7] <= 28 || sprite->data[7] >= 36)
    {
        sprite->data[6] *= -1;
        sprite->data[5]++;
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    TryFlipX(sprite);
}

void TipAndShake_3(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[7] <= 0)
    {
        sprite->data[7] = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[7] -= 2;
        sprite->x2 = Sin(sprite->data[7], 8);
        sprite->y2 = -(Sin(sprite->data[7], 8));
    }

    HandleSetAffineData(sprite, 256, 256, -(sprite->data[7]) << 8);
    TryFlipX(sprite);
}

void Anim_VibrateToCorners(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    s8 sign;

    TryFlipX(sprite);
    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        sprite->x2 = 0;
    }
    else
    {
        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        if ((sprite->data[2] % 4) / 2 == 0)
        {
            sprite->x2 = Sin((sprite->data[2] * 128 / 40) % 256, 16) * sign;
            sprite->y2 = -(sprite->x2);
        }
        else
        {
            sprite->x2 = -(Sin((sprite->data[2] * 128 / 40) % 256, 16)) * sign;
            sprite->y2 = sprite->x2;
        }
    }

    sprite->data[2]++;
    TryFlipX(sprite);
}
void Anim_GrowInStages(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern s16 Cos(s16 index, s16 amplitude);

    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[5] = 0;
        sprite->data[6] = 0;
        sprite->data[7] = 0;
        sprite->data[2]++;
    }

    if (sprite->data[6] > 0)
    {
        sprite->data[6]--;
        if (sprite->data[5] != 3)
        {
            s16 scale = (8 * sprite->data[6]) / 20;

            scale = Sin(sprite->data[7] - scale, 64);
            HandleSetAffineData(sprite, 256 - scale, 256 - scale, 0);
        }
    }
    else
    {
        s16 var;

        if (sprite->data[5] == 3)
        {
            if (sprite->data[7] > 63)
            {
                sprite->data[7] = 64;
                HandleSetAffineData(sprite, 256, 256, 0);
                ResetSpriteAfterAnim(sprite);
                sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
            }

            var = Cos(sprite->data[7], 64);
        }
        else
        {
            var = Sin(sprite->data[7], 64);
            if (sprite->data[7] > 63)
            {
                sprite->data[5] = 3;
                sprite->data[6] = 10;
                sprite->data[7] = 0;
            }
            else
            {
                if (var > 48 && sprite->data[5] == 1)
                {
                    sprite->data[5] = 2;
                    sprite->data[6] = 20;
                }
                else if (var > 16 && sprite->data[5] == 0)
                {
                    sprite->data[5] = 1;
                    sprite->data[6] = 20;
                }
            }
        }

        sprite->data[7] += 2;
        HandleSetAffineData(sprite, 256 - var, 256 - var, 0);
    }

    TryFlipX(sprite);
}
void Anim_VerticalSpring(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 yScale;

        sprite->y2 = Sin(sprite->data[7] % 256, 8);
        sprite->data[7] += 8;
        yScale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256, yScale + 256, 0);
    }
}

void Anim_VerticalRepeatedSpring(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 256)
    {
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
    }
    else
    {
        s16 yScale;

        sprite->y2 = Sin(sprite->data[7], 16);
        sprite->data[7] += 4;
        yScale = Sin((sprite->data[7] % 64) * 2, 128);
        HandleSetAffineData(sprite, 256, yScale + 256, 0);
    }
}

void Anim_SpringRising(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->callback = SpringRising_0;
    sprite->data[7] = 0;
}

void SpringRising_0(struct Sprite *sprite)
{
    s16 yScale;

    sprite->data[7] += 8;
    if (sprite->data[7] > 63)
    {
        sprite->data[7] = 0;
        sprite->data[6] = 0;
        sprite->callback = SpringRising_1;
        yScale = Sin(64, 128);
    }
    else
    {
        yScale = Sin(sprite->data[7], 128);
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
}


void SpringRising_1(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern s16 Cos(s16 index, s16 amplitude);
    extern void SpringRising_2_Thumb(struct Sprite *sprite) __asm__("SpringRising_2 + 1");
    s16 yScale;

    sprite->data[7] += 4;
    if (sprite->data[7] > 95)
    {
        yScale = Cos(0, 128);
        sprite->data[7] = 0;
        sprite->data[6]++;
    }
    else
    {
        s16 sign;
        s16 index;

        sprite->y2 = -(sprite->data[6] * 4) - Sin(sprite->data[7], 8);
        if (sprite->data[7] > 63)
        {
            sign = -1;
            index = sprite->data[7] - 64;
        }
        else
        {
            sign = 1;
            index = 0;
        }

        yScale = Cos((index * 2) + sprite->data[7], 128) * sign;
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
    if (sprite->data[6] == 3)
    {
        sprite->data[7] = 0;
        sprite->callback = SpringRising_2_Thumb;
    }
}

void SpringRising_2(struct Sprite *sprite)
{
    s16 yScale;

    sprite->data[7] += 8;
    yScale = Cos(sprite->data[7], 128);
    sprite->y2 = -(Cos(sprite->data[7], 12));
    if (sprite->data[7] > 63)
    {
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
    }

    HandleSetAffineData(sprite, 256, 256 + yScale, 0);
}

void HorizontalSpring(struct Sprite *sprite)
{
    if (sprite->data[7] > sprite->data[5])
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        HandleSetAffineData(sprite, 256, 256, 0);
    }
    else
    {
        s16 xScale;

        sprite->x2 = Sin(sprite->data[7] % 256, sprite->data[4]);
        sprite->data[7] += sprite->data[6];
        xScale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256 + xScale, 256, 0);
    }
}

void Anim_HorizontalSpring(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 8;
    }

    HorizontalSpring(sprite);
}

void HorizontalRepeatedSpring(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern void SpriteCB_SetDummyOnAnimEnd_Thumb(struct Sprite *sprite)
        __asm__("SpriteCB_SetDummyOnAnimEnd + 1");

    if (sprite->data[7] > sprite->data[5])
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        HandleSetAffineData(sprite, 256, 256, 0);
    }
    else
    {
        s16 xScale;

        sprite->x2 = Sin(sprite->data[7] % 256, sprite->data[4]);
        sprite->data[7] += sprite->data[6];
        xScale = Sin((sprite->data[7] % 64) * 2, 128);
        HandleSetAffineData(sprite, 256 + xScale, 256, 0);
    }
}

void Anim_HorizontalRepeatedSpring_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 256;
        sprite->data[4] = 16;
    }

    HorizontalRepeatedSpring(sprite);
}

void Anim_HorizontalSlideShrink(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->x2 = Sin(sprite->data[7] % 256, 8);
        sprite->data[7] += 8;
        scale = Sin(sprite->data[7] % 128, 96);
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    TryFlipX(sprite);
}

void Anim_LungeGrow(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->x2 = -(Sin((sprite->data[7] % 256) / 2, 16));
        sprite->data[7] += 8;
        scale = -(Sin((sprite->data[7] % 256) / 2, 64));
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    TryFlipX(sprite);
}

void Anim_CircleIntoBackground(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
    }

    if (sprite->data[7] > 512)
    {
        sprite->x2 = 0;
        ResetSpriteAfterAnim(sprite);
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 scale;

        sprite->x2 = -(Sin(sprite->data[7] % 256, 8));
        sprite->data[7] += 8;
        scale = Sin((sprite->data[7] % 256) / 2, 96);
        HandleSetAffineData(sprite, 256 + scale, 256 + scale, 0);
    }

    TryFlipX(sprite);
}

void Anim_RapidHorizontalHops(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 caseVar = (sprite->data[2] / 512) % 4;

        switch (caseVar)
        {
        case 0:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->x2 = (sprite->data[2] % 512 / 32) - 16;
            break;
        case 2:
            sprite->x2 = (sprite->data[2] % 512) / 32;
            break;
        case 3:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        }

        sprite->y2 = -(Sin(sprite->data[2] % 128, 4));
        sprite->data[2] += 24;
    }

    TryFlipX(sprite);
}

void Anim_FourPetal(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern s16 Cos(s16 index, s16 amplitude);

    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        sprite->data[6] = 0;
        sprite->data[7] = 64;
        sprite->data[2]++;
    }

    sprite->data[7] += 8;
    if (sprite->data[6] == 4)
    {
        if (sprite->data[7] > 63)
        {
            sprite->data[7] = 0;
            sprite->data[6]++;
        }
    }
    else
    {
        if (sprite->data[7] > 127)
        {
            sprite->data[7] = 0;
            sprite->data[6]++;
        }
    }

    switch (sprite->data[6])
    {
    case 1:
        sprite->x2 = -(Cos(sprite->data[7], 8));
        sprite->y2 = Sin(sprite->data[7], 8) - 8;
        break;
    case 2:
        sprite->x2 = Sin(sprite->data[7] + 128, 8) + 8;
        sprite->y2 = -(Cos(sprite->data[7], 8));
        break;
    case 3:
        sprite->x2 = Cos(sprite->data[7], 8);
        sprite->y2 = Sin(sprite->data[7] + 128, 8) + 8;
        break;
    case 0:
    case 4:
        sprite->x2 = Sin(sprite->data[7], 8) - 8;
        sprite->y2 = Cos(sprite->data[7], 8);
        break;
    default:
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        break;
    }

    TryFlipX(sprite);
}

void Anim_VerticalSquishBounce_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 32;
    VerticalSquishBounce(sprite);
    sprite->callback = VerticalSquishBounce;
}

void Anim_HorizontalSlide_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 80;
    HorizontalSlide(sprite);
    sprite->callback = HorizontalSlide;
}

void Anim_VerticalSlide_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 80;
    VerticalSlide(sprite);
    sprite->callback = VerticalSlide;
}

void Anim_BounceRotateToSides_Small(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 2048;
    gUnknown_3001240[id].data = sprite->data[6];
    BounceRotateToSides(sprite);
    sprite->callback = BounceRotateToSides;
}

void Anim_BounceRotateToSides_Slow(struct Sprite *sprite)
{
    sprite->data[6] = 1;
    Anim_BounceRotateToSides(sprite);
}

void Anim_BounceRotateToSides_SmallSlow(struct Sprite *sprite)
{
    sprite->data[6] = 1;
    Anim_BounceRotateToSides_Small(sprite);
}

void Anim_ZigzagSlow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[0] = 0;

    if (sprite->data[0] <= 0)
    {
        Zigzag(sprite);
        sprite->data[0] = 1;
    }
    else
    {
        sprite->data[0]--;
    }
}

void Anim_HorizontalShake_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    sprite->data[7] = 3;
    HorizontalShake(sprite);
    sprite->callback = HorizontalShake;
}

void Anim_VertialShake_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    VerticalShake(sprite);
    sprite->callback = VerticalShake;
}


void Anim_Twist_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 1024;
    gUnknown_3001240[id].delay = 0;
    gUnknown_3001240[id].runs = 2;
    Twist(sprite);
    sprite->callback = Twist;
}

void Anim_CircleCounterclockwise_Slow(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 512;
    gUnknown_3001240[id].data = 3;
    gUnknown_3001240[id].speed = 12;
    CircleCounterclockwise(sprite);
    sprite->callback = CircleCounterclockwise;
}

void Anim_VerticalShakeTwice_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 24;
    VerticalShakeTwice(sprite);
    sprite->callback = VerticalShakeTwice;
}

void Anim_VerticalSlideWobble_Small(struct Sprite *sprite)
{
    sprite->data[0] = 5;
    VerticalSlideWobble(sprite);
    sprite->callback = VerticalSlideWobble;
}

void Anim_VerticalJumps_Small(struct Sprite *sprite)
{
    sprite->data[0] = 3;
    VerticalJumps(sprite);
    sprite->callback = VerticalJumps;
}

void Anim_Spin(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].delay = 60;
    gUnknown_3001240[id].data = 30;
    Spin(sprite);
    sprite->callback = Spin;
}

void Anim_TumblingFrontFlip_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].speed = 1;
    gUnknown_3001240[id].runs = 2;
    TumblingFrontFlip(sprite);
    sprite->callback = TumblingFrontFlip;
}

void Anim_DeepVerticalSquishBounce_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 4;
    gUnknown_3001240[id].runs = 2;
    DeepVerticalSquishBounce(sprite);
    sprite->callback = DeepVerticalSquishBounce;
}

void Anim_HorizontalJumpsVerticalStretch_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].data = 1;
    gUnknown_3001240[id].runs = 2;
    HandleStartAffineAnim(sprite);
    sprite->data[3] = 0;
    HorizontalJumpsVerticalStretch_0(sprite);
    sprite->callback = HorizontalJumpsVerticalStretch_0;
}

void Anim_RotateToSides(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 2;
    RotateToSides(sprite);
    sprite->callback = RotateToSides;
}

void Anim_RotateToSides_Twice(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 4;
    gUnknown_3001240[id].runs = 2;
    RotateToSides(sprite);
    sprite->callback = RotateToSides;
}

void Anim_SwingConcave(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].data = 100;
    SwingConcave(sprite);
    sprite->callback = SwingConcave;
}

void Anim_SwingConcave_Fast(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].data = 50;
    gUnknown_3001240[id].runs = 2;
    SwingConcave(sprite);
    sprite->callback = SwingConcave;
}

void Anim_SwingConvex(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].data = 100;
    SwingConvex(sprite);
    sprite->callback = SwingConvex;
}

void Anim_SwingConvex_Fast(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].data = 50;
    gUnknown_3001240[id].runs = 2;
    SwingConvex(sprite);
    sprite->callback = SwingConvex;
}

void VerticalShakeBack(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];
    s32 yOffset;

    if (counter > 2304)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        yOffset = 0;
    }
    else
    {
        yOffset = Sin((s16)((counter + 192) % 256), sprite->data[7]) + (u16)sprite->data[7];
    }

    sprite->y2 = yOffset;
    sprite->data[2] += sprite->data[0];
}

void Anim_VerticalShakeBack(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sprite->data[7] = 3;
    VerticalShakeBack(sprite);
    sprite->callback = VerticalShakeBack;
}

void Anim_VerticalShakeBack_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 30;
    sprite->data[7] = 3;
    VerticalShakeBack(sprite);
    sprite->callback = VerticalShakeBack;
}

void Anim_VerticalShakeHorizontalSlide_Slow(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;

        switch (divCase)
        {
        case 0:
            sprite->x2 = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->x2 = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->y2 = Sin(sprite->data[2] % 128, 4);
        sprite->data[2] += 24;
    }

    TryFlipX(sprite);
}

void VerticalStretchBothEnds(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;

    if (sprite->data[5] > sprite->data[6])
    {
        sprite->y2 = 0;
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude, cmpVal1, cmpVal2;
        s16 xScale, yScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        if (sprite->data[1] == 0)
            xScale = -256 - Sin(index2, 16);
        else
            xScale = 256 + Sin(index2, 16);

        amplitude = sprite->data[3];
        yScale = 256 - Sin(index2, amplitude) - Sin(index1, amplitude / 5);
        SetAffineData(sprite, xScale, yScale, 0);
        sprite->data[5]++;
    }
}


void Anim_VerticalStretchBothEnds_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    VerticalStretchBothEnds(sprite);
}

void HorizontalStretchFar(struct Sprite *sprite)
{
    s16 index1 = 0, index2;

    if (sprite->data[5] > sprite->data[6])
    {
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude, cmpVal1, cmpVal2;
        s16 xScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        amplitude = sprite->data[3];

        if (sprite->data[1] == 0)
            xScale = -256 + Sin(index2, amplitude) + Sin(index1, amplitude / 5 * 2);
        else
            xScale = 256 - Sin(index2, amplitude) - Sin(index1, amplitude / 5 * 2);

        SetAffineData(sprite, xScale, 256, 0);
        sprite->data[5]++;
    }
}

void Anim_HorizontalStretchFar_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    HorizontalStretchFar(sprite);
}

void VerticalShakeLowTwice(struct Sprite *sprite)
{
    u8 var6, var7;
    u8 var8 = sprite->data[2];
    u8 var9 = sprite->data[6];
    u8 var5 = gUnknown_85D34E0[sprite->data[5]][0];
    if (var5 != (u8)-1)
        var5 = sprite->data[7];

    var6 = gUnknown_85D34E0[sprite->data[5]][1];
    var7 = 0;
    if (gUnknown_85D34E0[sprite->data[5]][0] != (u8)-2)
        var7 = (var6 - var9) * var5 / var6;
    else
        var7 = 0;

    if (var5 == (u8)-1)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->y2 = 0;
    }
    else
    {
        sprite->y2 = Sin((var8 + 192) % 256, var7) + var7;
        if (var9 == var6)
        {
            sprite->data[5]++;
            sprite->data[6] = 0;
        }
        else
        {
            sprite->data[2] += sprite->data[0];
            sprite->data[6]++;
        }
    }
}

void Anim_VerticalShakeLowTwice(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    sprite->data[7] = 6;
    VerticalShakeLowTwice(sprite);
    sprite->callback = VerticalShakeLowTwice;
}

void Anim_HorizontalShake_Fast(struct Sprite *sprite)
{
    sprite->data[0] = 70;
    sprite->data[7] = 6;
    HorizontalShake(sprite);
    sprite->callback = HorizontalShake;
}

void Anim_HorizontalSlide_Fast(struct Sprite *sprite)
{
    sprite->data[0] = 20;
    HorizontalSlide(sprite);
    sprite->callback = HorizontalSlide;
}

void Anim_HorizontalVibrate_Fast(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        sprite->x2 = 0;
    }
    else
    {
        s8 sign;

        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->x2 = Sin((sprite->data[2] * 128 / 40) % 256, 9) * sign;
    }

    sprite->data[2]++;
}

void Anim_HorizontalVibrate_Fastest(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        sprite->x2 = 0;
    }
    else
    {
        s8 sign;

        if (!(sprite->data[2] & 1))
            sign = 1;
        else
            sign = -1;

        sprite->x2 = Sin((sprite->data[2] * 128 / 40) % 256, 12) * sign;
    }

    sprite->data[2]++;
}

void Anim_VerticalShakeBack_Fast(struct Sprite *sprite)
{
    sprite->data[0] = 70;
    sprite->data[7] = 6;
    VerticalShakeBack(sprite);
    sprite->callback = VerticalShakeBack;
}

void Anim_VerticalShakeLowTwice_Slow(struct Sprite *sprite)
{
    sprite->data[0] = 24;
    sprite->data[7] = 6;
    VerticalShakeLowTwice(sprite);
    sprite->callback = VerticalShakeLowTwice;
}

void Anim_VerticalShakeLowTwice_Fast(struct Sprite *sprite)
{
    sprite->data[0] = 56;
    sprite->data[7] = 9;
    VerticalShakeLowTwice(sprite);
    sprite->callback = VerticalShakeLowTwice;
}

void Anim_CircleCounterclockwise_Long(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = AddNewAnim();

    gUnknown_3001240[id].rotation = 1024;
    gUnknown_3001240[id].data = 6;
    gUnknown_3001240[id].speed = 24;
    CircleCounterclockwise(sprite);
    sprite->callback = CircleCounterclockwise;
}

void GrowStutter(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    s16 index1 = 0;
    s16 index2 = 0;

    if (sprite->data[5] > sprite->data[6])
    {
        sprite->y2 = 0;
        sprite->data[5] = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        if (sprite->data[4] <= 1)
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        }
        else
        {
            sprite->data[4]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        u8 amplitude;
        u8 cmpVal1;
        u8 cmpVal2;
        s16 xScale;
        s16 yScale;

        index2 = (sprite->data[5] * 128) / sprite->data[6];
        cmpVal1 = sprite->data[6] / 4;
        cmpVal2 = cmpVal1 * 3;
        if (sprite->data[5] >= cmpVal1 && sprite->data[5] < cmpVal2)
        {
            sprite->data[7] += 51;
            index1 = sprite->data[7] & 0xFF;
        }

        amplitude = sprite->data[3];
        if (sprite->data[1] == 0)
            xScale = Sin(index2, amplitude) + (Sin(index1, amplitude / 5 * 2) - 256);
        else
            xScale = 256 - Sin(index1, amplitude / 5 * 2) - Sin(index2, amplitude);

        yScale = 256 - Sin(index1, amplitude / 5) - Sin(index2, amplitude);
        SetAffineData(sprite, xScale, yScale, 0);
        sprite->data[5]++;
    }
}

void Anim_GrowStutter_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 40;
        sprite->data[3] = 40;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    GrowStutter(sprite);
}

void Anim_VerticalShakeHorizontalSlide(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    TryFlipX(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;

        switch (divCase)
        {
        case 0:
            sprite->x2 = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->x2 = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->y2 = Sin(sprite->data[2] % 128, 4);
        sprite->data[2] += 48;
    }

    TryFlipX(sprite);
}
void Anim_VerticalShakeHorizontalSlide_Fast(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    TryFlipX(sprite);
    if (sprite->data[2] > 2048)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        sprite->data[6] = 0;
    }
    else
    {
        s16 divCase = (sprite->data[2] / 512) % 4;

        switch (divCase)
        {
        case 0:
            sprite->x2 = (sprite->data[2] % 512) / 32;
            break;
        case 2:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512;
            break;
        case 1:
            sprite->x2 = -(sprite->data[2] % 512 * 16) / 512 + 16;
            break;
        case 3:
            sprite->x2 = (sprite->data[2] % 512) / 32 - 16;
            break;
        }

        sprite->y2 = Sin(sprite->data[2] % 96, 4);
        sprite->data[2] += 64;
    }

    TryFlipX(sprite);
}

void TriangleDown(struct Sprite *sprite)
{
    TryFlipX(sprite);

    if (sprite->data[2] == 0)
        sprite->data[3] = 0;

    if (gUnknown_85D381E[sprite->data[3]][2] / sprite->data[5] == sprite->data[2])
    {
        sprite->data[3]++;
        sprite->data[2] = 0;
    }

    if (gUnknown_85D381E[sprite->data[3]][2] / sprite->data[5] == 0)
    {
        if (--sprite->data[6] == 0)
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        else
            sprite->data[2] = 0;
    }
    else
    {
        s32 amplitude = sprite->data[5];

        sprite->x2 += gUnknown_85D381E[sprite->data[3]][0] * amplitude;
        sprite->y2 += gUnknown_85D381E[sprite->data[3]][1] * sprite->data[5];
        sprite->data[2]++;
        TryFlipX(sprite);
    }
}

void Anim_TriangleDown_Slow(struct Sprite *sprite)
{
    sprite->data[5] = 1;
    sprite->data[6] = 1;
    TriangleDown(sprite);
    sprite->callback = TriangleDown;
}

void Anim_TriangleDown(struct Sprite *sprite)
{
    sprite->data[5] = 2;
    sprite->data[6] = 1;
    TriangleDown(sprite);
    sprite->callback = TriangleDown;
}

void Anim_TriangleDown_Fast(struct Sprite *sprite)
{
    sprite->data[5] = 2;
    sprite->data[6] = 2;
    TriangleDown(sprite);
    sprite->callback = TriangleDown;
}

void Grow(struct Sprite *sprite)
{
    if (sprite->data[7] > 255)
    {
        if (sprite->data[5] <= 1)
        {
            ResetSpriteAfterAnim(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            HandleSetAffineData(sprite, 256, 256, 0);
        }
        else
        {
            sprite->data[5]--;
            sprite->data[7] = 0;
        }
    }
    else
    {
        s16 scale;

        sprite->data[7] += sprite->data[6];
        if (sprite->data[7] > 256)
            sprite->data[7] = 256;

        scale = Sin(sprite->data[7] / 2, 64);
        HandleSetAffineData(sprite, 256 - scale, 256 - scale, 0);
    }
}

void Anim_Grow(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 1;
    }

    Grow(sprite);
    TryFlipX(sprite);
}

void Anim_Grow_Twice(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 2;
    }

    Grow(sprite);
    TryFlipX(sprite);
}

void Anim_HorizontalSpring_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 16;
    }

    HorizontalSpring(sprite);
}

void Anim_HorizontalSpring_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 4;
        sprite->data[5] = 256;
        sprite->data[4] = 16;
    }

    HorizontalSpring(sprite);
}

void Anim_HorizontalRepeatedSpring_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 16;
    }

    HorizontalRepeatedSpring(sprite);
}

void Anim_HorizontalRepeatedSpring(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[2]++;
        sprite->data[7] = 0;
        sprite->data[6] = 8;
        sprite->data[5] = 512;
        sprite->data[4] = 8;
    }

    HorizontalRepeatedSpring(sprite);
}

void Anim_ShrinkGrow_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 5;
        sprite->data[6] = 8;
    }

    ShrinkGrow(sprite);
}

void Anim_ShrinkGrow_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 3;
        sprite->data[6] = 4;
    }

    ShrinkGrow(sprite);
}
void Anim_VerticalStretchBothEnds(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[7] = 0;
    }

    VerticalStretchBothEnds(sprite);
}

void Anim_VerticalStretchBothEnds_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[7] = 0;
    }

    VerticalStretchBothEnds(sprite);
}
void Anim_HorizontalStretchFar_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    HorizontalStretchFar(sprite);
}

void Anim_HorizontalStretchFar(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    HorizontalStretchFar(sprite);
}
void Anim_GrowStutter_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 2;
        sprite->data[6] = 20;
        sprite->data[3] = 70;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    GrowStutter(sprite);
}

void Anim_GrowStutter(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        HandleStartAffineAnim(sprite);
        sprite->data[4] = 1;
        sprite->data[6] = 30;
        sprite->data[3] = 60;
        sprite->data[5] = 0;
        sprite->data[7] = 0;
    }

    GrowStutter(sprite);
}
void ConcaveArc(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    if (sprite->data[7] > 255)
    {
        if (sprite->data[6] <= 1)
        {
            sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
            sprite->x2 = 0;
            sprite->y2 = 0;
        }
        else
        {
            sprite->data[7] %= 256;
            sprite->data[6]--;
        }
    }
    else
    {
        sprite->x2 = -(Sin(sprite->data[7], sprite->data[5]));
        sprite->y2 = Sin((sprite->data[7] + 192) % 256, sprite->data[4]);
        if (sprite->y2 > 0)
            sprite->y2 *= -1;

        sprite->y2 += sprite->data[4];
        sprite->data[7] += sprite->data[3];
    }
}

void Anim_ConcaveArcLarge_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 4;
    }

    ConcaveArc(sprite);
}

void Anim_ConcaveArcLarge(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 6;
    }

    ConcaveArc(sprite);
}

void Anim_ConcaveArcLarge_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 12;
        sprite->data[4] = 12;
        sprite->data[3] = 8;
    }

    ConcaveArc(sprite);
}
void ConvexDoubleArc(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    if (sprite->data[7] > 256)
    {
        if (sprite->data[6] <= sprite->data[4])
        {
            sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
        }
        else
        {
            sprite->data[4]++;
            sprite->data[7] = 0;
        }

        sprite->x2 = 0;
        sprite->y2 = 0;
    }
    else
    {
        s16 posX;

        if (sprite->data[7] > 159)
        {
            if (sprite->data[7] > 256)
                sprite->data[7] = 256;

            sprite->y2 = -(Sin(sprite->data[7] % 256, 8));
        }
        else if (sprite->data[7] > 95)
        {
            sprite->y2 = Sin(96, 6) - Sin((sprite->data[7] - 96) * 2, 4);
        }
        else
        {
            sprite->y2 = Sin(sprite->data[7], 6);
        }

        posX = -(Sin(sprite->data[7] / 2, sprite->data[5]));
        if (sprite->data[4] % 2 == 0)
            posX *= -1;

        sprite->x2 = posX;
        sprite->data[7] += sprite->data[3];
    }
}

void Anim_ConvexDoubleArc_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 4;
    }

    ConvexDoubleArc(sprite);
}

void Anim_ConvexDoubleArc(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 6;
    }

    ConvexDoubleArc(sprite);
}

void Anim_ConvexDoubleArc_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 3;
        sprite->data[7] = 0;
        sprite->data[5] = 16;
        sprite->data[4] = 1;
        sprite->data[3] = 8;
    }

    ConvexDoubleArc(sprite);
}
void Anim_ConcaveArcSmall_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 4;
    }

    ConcaveArc(sprite);
}

void Anim_ConcaveArcSmall(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 1;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 6;
    }

    ConcaveArc(sprite);
}

void Anim_ConcaveArcSmall_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[2] = 1;
        sprite->data[6] = 2;
        sprite->data[7] = 0;
        sprite->data[5] = 4;
        sprite->data[4] = 6;
        sprite->data[3] = 8;
    }

    ConcaveArc(sprite);
}
void SetHorizontalDip(struct Sprite *sprite)
{
    u16 index = Sin((s16)((sprite->data[2] * 128) / sprite->data[7]), sprite->data[5]);

    sprite->data[6] = -(index << 8);
    sub_0817F29C(sprite, index, sprite->data[4], 0);
    HandleSetAffineData(sprite, 256, 256, sprite->data[6]);
}

void Anim_HorizontalDip(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 60;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 1;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            sub_0817F628(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        SetHorizontalDip(sprite);
    }

    sprite->data[2]++;
}

void Anim_HorizontalDip_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 90;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 1;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            sub_0817F628(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        SetHorizontalDip(sprite);
    }

    sprite->data[2]++;
}

void Anim_HorizontalDip_Twice(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->data[7] = 30;
        sprite->data[5] = 8;
        sprite->data[4] = -32;
        sprite->data[3] = 2;
        sprite->data[0] = 0;
    }

    if (sprite->data[2] > sprite->data[7])
    {
        HandleSetAffineData(sprite, 256, 256, 0);
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0]++;
        if (sprite->data[3] <= sprite->data[0])
        {
            sub_0817F628(sprite);
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            return;
        }
        else
        {
            sprite->data[2] = 0;
        }
    }
    else
    {
        SetHorizontalDip(sprite);
    }

    sprite->data[2]++;
}

void ShrinkGrowVibrate(struct Sprite *sprite)
{
    if (sprite->data[2] > sprite->data[7])
    {
        sprite->y2 = 0;
        HandleSetAffineData(sprite, 256, 256, 0);
        ResetSpriteAfterAnim(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s8 sinY;
        u16 y;
        s16 index = ((u16)(sprite->data[2] % sprite->data[6] * 256) / sprite->data[6]) % 256;

        if (sprite->data[2] % 2 == 0)
        {
            sprite->data[4] = Sin(index, 32) + 256;
            sprite->data[5] = Sin(index, 32) + 256;
            sinY = Sin(index, 32);
        }
        else
        {
            sprite->data[4] = Sin(index, 8) + 256;
            sprite->data[5] = Sin(index, 8) + 256;
            sinY = Sin(index, 8);
        }

        y = sinY / 8;
        sprite->y2 = y;
        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void Anim_ShrinkGrowVibrate_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->y2 += 2;
        sprite->data[6] = 40;
        sprite->data[7] = 80;
    }

    ShrinkGrowVibrate(sprite);
}

void Anim_ShrinkGrowVibrate(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->y2 += 2;
        sprite->data[6] = 40;
        sprite->data[7] = 40;
    }

    ShrinkGrowVibrate(sprite);
}

void Anim_ShrinkGrowVibrate_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        HandleStartAffineAnim(sprite);
        sprite->y2 += 2;
        sprite->data[6] = 80;
        sprite->data[7] = 80;
    }

    ShrinkGrowVibrate(sprite);
}

void JoltRight_0(struct Sprite *sprite);
void JoltRight_1(struct Sprite *sprite);
void JoltRight_2(struct Sprite *sprite);
void JoltRight_3(struct Sprite *sprite);

void JoltRight(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 -= sprite->data[2];
    if (sprite->x2 <= -sprite->data[6])
    {
        sprite->x2 = -sprite->data[6];
        sprite->data[7] = 2;
        sprite->callback = JoltRight_0;
    }

    TryFlipX(sprite);
}

void JoltRight_0(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 += sprite->data[7];
    sprite->data[7]++;
    if (sprite->x2 >= 0)
        sprite->callback = JoltRight_1;

    TryFlipX(sprite);
}

void JoltRight_1(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 += sprite->data[7];
    sprite->data[7]++;
    if (sprite->x2 > sprite->data[6])
    {
        sprite->x2 = sprite->data[6];
        sprite->callback = JoltRight_2;
    }

    TryFlipX(sprite);
}

void JoltRight_2(struct Sprite *sprite)
{
    TryFlipX(sprite);
    if (sprite->data[3] >= sprite->data[5])
    {
        sprite->callback = JoltRight_3;
    }
    else
    {
        sprite->x2 += sprite->data[4];
        sprite->data[4] *= -1;
        sprite->data[3]++;
    }

    TryFlipX(sprite);
}

void JoltRight_3(struct Sprite *sprite)
{
    TryFlipX(sprite);
    sprite->x2 -= 2;
    if (sprite->x2 <= 0)
    {
        sprite->x2 = 0;
        sub_0817F628(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }

    TryFlipX(sprite);
}

void Anim_JoltRight_Fast(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 4;
    sprite->data[6] = 12;
    sprite->data[5] = 16;
    sprite->data[4] = 4;
    sprite->data[3] = 0;
    sprite->data[2] = 2;
    sprite->callback = JoltRight;
}

void Anim_JoltRight(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 2;
    sprite->data[6] = 8;
    sprite->data[5] = 12;
    sprite->data[4] = 2;
    sprite->data[3] = 0;
    sprite->data[2] = 1;
    sprite->callback = JoltRight;
}

void Anim_JoltRight_Slow(struct Sprite *sprite)
{
    HandleStartAffineAnim(sprite);
    sprite->data[7] = 0;
    sprite->data[6] = 6;
    sprite->data[5] = 6;
    sprite->data[4] = 2;
    sprite->data[3] = 0;
    sprite->data[2] = 1;
    sprite->callback = JoltRight;
}

void sub_0818461C(struct Sprite *sprite)
{
    sprite->x2 = sprite->data[1];

    if (sprite->data[0] > 1)
    {
        s16 velocity = sprite->data[1];

        sprite->data[1] = -velocity;
        sprite->data[0] = 0;
    }
    else
    {
        sprite->data[0]++;
    }
}

void ShakeFlashYellow(struct Sprite *sprite)
{
    extern const u8 *const gUnknown_85D38DC[];
    const u8 *array = gUnknown_85D38DC[sprite->data[3]];

    sub_0818461C(sprite);
    if (array[sprite->data[6] * 4 + 1] == (u8)-1)
    {
        sprite->x2 = 0;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
    }
    else
    {
        if (sprite->data[4] == 1)
        {
            if (array[sprite->data[6] * 4])
                BlendPalette((u16)sprite->data[7], 16, 16, 0x3FF);
            else
                BlendPalette((u16)sprite->data[7], 16, 0, 0x3FF);

            sprite->data[4] = 0;
        }

        if (array[sprite->data[6] * 4 + 1] == sprite->data[5])
        {
            sprite->data[4] = 1;
            sprite->data[5] = 0;
            sprite->data[6]++;
        }
        else
        {
            sprite->data[5]++;
        }
    }
}

extern void BackAnimBlendYellow(struct Sprite *sprite);

void Anim_ShakeFlashYellow_Fast(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 0;
    }

    BackAnimBlendYellow(sprite);
}

void Anim_ShakeFlashYellow(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 1;
    }

    BackAnimBlendYellow(sprite);
}

void Anim_ShakeFlashYellow_Slow(struct Sprite *sprite)
{
    if (++sprite->data[2] == 1)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[6] = 0;
        sprite->data[5] = 0;
        sprite->data[4] = 0;
        sprite->data[3] = 2;
    }

    BackAnimBlendYellow(sprite);
}

void ShakeGlow_Blend(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);
    extern const u16 gUnknown_85D38E8[];

    if (sprite->data[2] > 127)
    {
        BlendPalette((u16)sprite->data[7], 16, 0, 0x1F);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd_Thumb;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 12);
        BlendPalette((u16)sprite->data[7], 16, (u8)sprite->data[6], gUnknown_85D38E8[sprite->data[1]]);
    }
}
void ShakeGlow_Move(struct Sprite *sprite)
{
    extern s16 Sin(s16 index, s16 amplitude);

    if (sprite->data[3] < sprite->data[4])
    {
        TryFlipX(sprite);
        if (sprite->data[5] > sprite->data[0])
        {
            if (++sprite->data[3] < sprite->data[4])
                sprite->data[5] = 0;

            sprite->x2 = 0;
        }
        else
        {
            s8 sign = 1 - (sprite->data[3] % 2 * 2);

            sprite->x2 = sign * Sin((sprite->data[5] * 384 / sprite->data[0]) % 256, 6);
            sprite->data[5]++;
        }

        TryFlipX(sprite);
    }
}

extern void BackAnimBlend(struct Sprite *sprite);
extern void sub_081847E0(struct Sprite *sprite);

void Anim_ShakeGlowRed_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = 0;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void Anim_ShakeGlowRed(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 0;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void Anim_ShakeGlowRed_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 0;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void Anim_ShakeGlowGreen_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = 1;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void Anim_ShakeGlowGreen(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 1;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void Anim_ShakeGlowGreen_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 1;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void Anim_ShakeGlowBlue_Fast(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 10;
        sprite->data[5] = 0;
        sprite->data[4] = 2;
        sprite->data[3] = 0;
        sprite->data[1] = 2;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void Anim_ShakeGlowBlue(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 20;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 2;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void Anim_ShakeGlowBlue_Slow(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
    {
        sprite->data[7] = 256 + (sprite->oam.paletteNum << 4);
        sprite->data[0] = 80;
        sprite->data[5] = 0;
        sprite->data[4] = 1;
        sprite->data[3] = 0;
        sprite->data[1] = 2;
    }

    if (sprite->data[2] % 2 == 0)
        BackAnimBlend(sprite);

    if (sprite->data[2] >= (128 - sprite->data[0] * sprite->data[4]) / 2)
        sub_081847E0(sprite);

    sprite->data[2]++;
}

void SpriteCB_SetDummyOnAnimEnd(struct Sprite *sprite)
{
    if (sprite->animEnded)
        sprite->callback = SpriteCallbackDummy;
}
