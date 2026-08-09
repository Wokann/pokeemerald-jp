#include "global.h"
#include "sprite.h"

void StoreSpriteCallbackInData6(struct Sprite *sprite, void (*callback)(struct Sprite *))
{
    sprite->data[6] = (u32)(callback) & 0xffff;
    sprite->data[7] = (u32)(callback) >> 16;
}
