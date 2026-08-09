#include "global.h"
#include "sprite.h"

typedef long intptr_t;

void StorePointerInVars(s16 *lo, s16 *hi, const void *ptr)
{
    *lo = ((intptr_t) ptr) & 0xffff;
    *hi = (((intptr_t) ptr) >> 16) & 0xffff;
}

void StoreSpriteCallbackInData6(struct Sprite *sprite, void (*callback)(struct Sprite *))
{
    sprite->data[6] = (u32)(callback) & 0xffff;
    sprite->data[7] = (u32)(callback) >> 16;
}

void SetCallbackToStoredInData6(struct Sprite *sprite)
{
    u32 callback = (u16)sprite->data[6] | (sprite->data[7] << 16);
    sprite->callback = (void (*)(struct Sprite *))callback;
}

extern void DestroySpriteAndFreeResources(void *sprite);

void DestroySpriteAndFreeResources_(void *sprite)
{
    DestroySpriteAndFreeResources(sprite);
}
