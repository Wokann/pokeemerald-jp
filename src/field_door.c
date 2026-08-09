#include "global.h"

struct DoorGraphics;

extern void DrawClosedDoorTiles(const struct DoorGraphics *gfx, u32 x, u32 y);

static void DrawClosedDoor(const struct DoorGraphics *gfx, u32 x, u32 y)
{
    DrawClosedDoorTiles(gfx, x, y);
}
