#include "global.h"
#include "battle_anim.h"

// The JP ROM places AnimOverheatFlame_Step (US battle_anim_dragon.c) in
// the dark.s region; it is decompiled here so the module follows the US
// pokeemerald file layout.

void AnimOverheatFlame_Step(struct Sprite *sprite)
{
    sprite->data[4] += sprite->data[1];
    sprite->data[5] += sprite->data[2];
    sprite->x2 = sprite->data[4] / 10;
    sprite->y2 = sprite->data[5] / 10;
    if (++sprite->data[0] > sprite->data[3])
        DestroyAnimSprite(sprite);
}
