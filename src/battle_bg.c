#include "global.h"
#include "main.h"
#include "sprite.h"
#include "battle_main.h"

// JP: these two unused functions sit right after the digit_obj_util module
// (0x08035460 / 0x080354A0), before the battle_bg asm functions.
static void UNUSED CB2_UnusedBattleInit(void);

static void UNUSED UnusedBattleInit(void)
{
    u8 spriteId;

    ResetSpriteData();
    spriteId = CreateSprite(&gUnusedBattleInitSprite, 0, 0, 0);
    gSprites[spriteId].invisible = TRUE;
    SetMainCallback2(CB2_UnusedBattleInit);
}

static void UNUSED CB2_UnusedBattleInit(void)
{
    AnimateSprites();
    BuildOamBuffer();
}
