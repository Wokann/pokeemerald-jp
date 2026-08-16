#ifndef POKEEMERALD_JP_MINIGAME_COUNTDOWN_H
#define POKEEMERALD_JP_MINIGAME_COUNTDOWN_H

#include "global.h"
#include "sprite.h"

// 321 countdown sprite/table data (0x82D1F54..0x82D254C)

extern const struct CompressedSpriteSheet sSpriteSheet_321Start_Static[];
extern const struct SpritePalette sSpritePalette_321Start_Static[];
extern const struct SpriteTemplate sSpriteTemplate_StaticCountdown[];
extern const TaskFunc sStaticCountdownFuncs[][4];
extern const struct CompressedSpriteSheet s321StartGfxSheet;
extern const struct SpritePalette s321StartPalette;
extern const struct SpriteTemplate sSpriteTemplate_Number;
extern const struct SpriteTemplate sSpriteTemplate_Start;

#endif // POKEEMERALD_JP_MINIGAME_COUNTDOWN_H
