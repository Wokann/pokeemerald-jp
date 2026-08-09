typedef unsigned int u32;
typedef signed short s16;

struct Sprite {
    unsigned char pad[0x2E];
    s16 data[8];
};

void StoreSpriteCallbackInData6(struct Sprite *sprite, void (*callback)(struct Sprite *))
{
    sprite->data[6] = (u32)(callback) & 0xffff;
    sprite->data[7] = (u32)(callback) >> 16;
}
