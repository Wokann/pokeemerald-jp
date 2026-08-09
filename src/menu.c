#include "global.h"

extern void FreeAllWindowBuffers(void);
extern u8 sStartMenuWindowId;
extern u8 sMapNamePopupWindowId;

void FreeAllOverworldWindowBuffers(void)
{
    FreeAllWindowBuffers();
}

u8 GetStartMenuWindowId(void)
{
    return sStartMenuWindowId;
}

u8 GetMapNamePopUpWindowId(void)
{
    return sMapNamePopupWindowId;
}
