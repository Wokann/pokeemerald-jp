typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;

struct Sprite {
    unsigned char pad0[0x1C];
    void (*callback)(struct Sprite *);
    unsigned char pad1[0x2E - 0x20];
    s16 data[8];
};

void SetCallbackToStoredInData6(struct Sprite *sprite)
{
    u32 callback = (u16)sprite->data[6] | (sprite->data[7] << 16);
    sprite->callback = (void (*)(struct Sprite *))callback;
}
