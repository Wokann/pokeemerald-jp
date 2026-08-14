#include "global.h"
#include "decompress.h"
#include "sprite.h"
#include "util.h"

static void SpriteCB_SmokescreenImpactMain(struct Sprite *);
static void SpriteCB_SmokescreenImpact(struct Sprite *);

// These tables live in the JP ROM data region and are bound via ld aliases.
extern const struct CompressedSpriteSheet sSmokescreenImpactSpriteSheet;
extern const struct CompressedSpritePalette sSmokescreenImpactSpritePalette;
extern const struct SpriteTemplate sSmokescreenImpactSpriteTemplate;

// JP stores the active-sprite count in data[0] and the persist flag in
// data[1], unlike US pokeemerald which uses data[1] for both.
#define sActiveSprites data[0]
#define sPersist       data[1]
#define sMainSpriteId data[0]

u8 SmokescreenImpact(s16 x, s16 y, bool8 persist)
{
    u8 mainSpriteId;
    u8 spriteId1, spriteId2, spriteId3, spriteId4;
    struct Sprite *mainSprite;

    if (GetSpriteTileStartByTag(sSmokescreenImpactSpriteSheet.tag) == 0xFFFF)
    {
        LoadCompressedSpriteSheetUsingHeap(&sSmokescreenImpactSpriteSheet);
        LoadCompressedSpritePaletteUsingHeap(&sSmokescreenImpactSpritePalette);
    }

    mainSpriteId = CreateInvisibleSpriteWithCallback(SpriteCB_SmokescreenImpactMain);
    mainSprite = &gSprites[mainSpriteId];
    mainSprite->sPersist = persist;

    // Top left sprite
    spriteId1 = CreateSprite(&sSmokescreenImpactSpriteTemplate, x - 16, y - 16, 2);
    gSprites[spriteId1].sMainSpriteId = mainSpriteId;
    mainSprite->sActiveSprites++;
    AnimateSprite(&gSprites[spriteId1]);

    // Top right sprite
    spriteId2 = CreateSprite(&sSmokescreenImpactSpriteTemplate, x, y - 16, 2);
    gSprites[spriteId2].sMainSpriteId = mainSpriteId;
    mainSprite->sActiveSprites++;
    StartSpriteAnim(&gSprites[spriteId2], 1);
    AnimateSprite(&gSprites[spriteId2]);

    // Bottom left sprite
    spriteId3 = CreateSprite(&sSmokescreenImpactSpriteTemplate, x - 16, y, 2);
    gSprites[spriteId3].sMainSpriteId = mainSpriteId;
    mainSprite->sActiveSprites++;
    StartSpriteAnim(&gSprites[spriteId3], 2);
    AnimateSprite(&gSprites[spriteId3]);

    // Bottom right sprite
    spriteId4 = CreateSprite(&sSmokescreenImpactSpriteTemplate, x, y, 2);
    gSprites[spriteId4].sMainSpriteId = mainSpriteId;
    mainSprite->sActiveSprites++;
    StartSpriteAnim(&gSprites[spriteId4], 3);
    AnimateSprite(&gSprites[spriteId4]);

    return mainSpriteId;
}

static void SpriteCB_SmokescreenImpactMain(struct Sprite *sprite)
{
    if (sprite->sActiveSprites == 0)
    {
        FreeSpriteTilesByTag(sSmokescreenImpactSpriteSheet.tag);
        FreeSpritePaletteByTag(sSmokescreenImpactSpritePalette.tag);
        if (!sprite->sPersist)
            DestroySprite(sprite);
        else
            sprite->callback = SpriteCallbackDummy;
    }
}

static void SpriteCB_SmokescreenImpact(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        gSprites[sprite->sMainSpriteId].sActiveSprites--;
        DestroySprite(sprite);
    }
}
