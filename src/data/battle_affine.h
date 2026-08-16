#ifndef POKEEMERALD_JP_BATTLE_AFFINE_H
#define POKEEMERALD_JP_BATTLE_AFFINE_H

#include "global.h"
#include "sprite.h"

// Digit gfx/pal and battler affine-anim data (0x82D2A68..0x82D2F9C)

extern const u16 sDigitPalette[];
extern const u32 sDigitGfx[];
extern const union AffineAnimCmd *const gAffineAnims_BattleSpritePlayerSide[];
extern const union AffineAnimCmd *const gAffineAnims_BattleSpriteOpponentSide[];
extern const union AffineAnimCmd *const gAffineAnims_BattleSpriteContest[];
extern const union AnimCmd sAnim_MonPic_0[];
extern const union AnimCmd sAnim_MonPic_1[];
extern const union AnimCmd sAnim_MonPic_2[];
extern const union AnimCmd sAnim_MonPic_3[];

#endif // POKEEMERALD_JP_BATTLE_AFFINE_H
