#include "global.h"

struct ObjectEvent;
struct Sprite;

extern void SetUpReflection(struct ObjectEvent *objEvent, struct Sprite *sprite, u8 mode);

void GroundEffect_IceReflection(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    SetUpReflection(objEvent, sprite, TRUE);
}
