#include "global.h"
#include "text_window.h"
#include "string_util.h"
#include "constants/comparison_operators.h"

#define POKEBALL_GRAPHICS __attribute__((section(".rodata.pokeball_graphics"), aligned(1)))
#define POKEBALL_OPEN_GRAPHICS __attribute__((section(".rodata.pokeball_open_graphics"), aligned(1)))
#include "data/graphics/pokeballs.h"
#undef POKEBALL_OPEN_GRAPHICS
#undef POKEBALL_GRAPHICS

#define BATTLE_ENVIRONMENT_GRAPHICS __attribute__((section(".rodata.battle_environment_graphics"), aligned(1)))
#include "data/graphics/battle_environment.h"
#undef BATTLE_ENVIRONMENT_GRAPHICS

#define BATTLE_ANIM_A_BASE_GRAPHICS __attribute__((section(".rodata.battle_anim_a_base_graphics"), aligned(1)))

BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Bubble[] = INCBIN_U32("graphics/battle_anims/sprites/bubble.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Bone[] = INCBIN_U32("graphics/battle_anims/sprites/bone.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_AirWave[] = INCBIN_U32("graphics/battle_anims/sprites/air_wave.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Orb[] = INCBIN_U32("graphics/battle_anims/sprites/orb.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Sword[] = INCBIN_U32("graphics/battle_anims/sprites/sword.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Seed[] = INCBIN_U32("graphics/battle_anims/sprites/seed.4bpp.lz");

BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_RainDrops[] = INCBIN_U32("graphics/battle_anims/sprites/rain_drops.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Bone[] = INCBIN_U32("graphics/battle_anims/sprites/bone.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_AirWave[] = INCBIN_U32("graphics/battle_anims/sprites/air_wave.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Orb[] = INCBIN_U32("graphics/battle_anims/sprites/orb.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Sword[] = INCBIN_U32("graphics/battle_anims/sprites/sword.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Seed[] = INCBIN_U32("graphics/battle_anims/sprites/seed.gbapal.lz");

BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Needle[] = INCBIN_U32("graphics/battle_anims/sprites/needle.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Needle[] = INCBIN_U32("graphics/battle_anims/sprites/needle.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Explosion6[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_6.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Explosion6[] = INCBIN_U32("graphics/battle_anims/sprites/explosion_6.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_PinkOrb[] = INCBIN_U32("graphics/battle_anims/sprites/pink_orb.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_PinkOrb[] = INCBIN_U32("graphics/battle_anims/sprites/pink_orb.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_IceCube[] = INCBIN_U32("graphics/battle_anims/sprites/ice_cube.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_IceCube[] = INCBIN_U32("graphics/battle_anims/sprites/ice_cube.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Gust[] = INCBIN_U32("graphics/battle_anims/sprites/gust.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Gust[] = INCBIN_U32("graphics/battle_anims/sprites/gust.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Spark2[] = INCBIN_U32("graphics/battle_anims/sprites/spark_2.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Spark2[] = INCBIN_U32("graphics/battle_anims/sprites/spark_2.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Orange[] = INCBIN_U32("graphics/battle_anims/sprites/orange.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Orange[] = INCBIN_U32("graphics/battle_anims/sprites/orange.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Spikes[] = INCBIN_U32("graphics/battle_anims/sprites/spikes.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Spikes[] = INCBIN_U32("graphics/battle_anims/sprites/spikes.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_YellowBall[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_ball.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_YellowBall[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_ball.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_TiedBag[] = INCBIN_U32("graphics/battle_anims/sprites/tied_bag.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_TiedBag[] = INCBIN_U32("graphics/battle_anims/sprites/tied_bag.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_BlackSmoke[] = INCBIN_U32("graphics/battle_anims/sprites/black_smoke.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_BlackSmoke[] = INCBIN_U32("graphics/battle_anims/sprites/black_smoke.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_BlackBall[] = INCBIN_U32("graphics/battle_anims/sprites/black_ball.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_BlackBall[] = INCBIN_U32("graphics/battle_anims/sprites/black_ball.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Glass[] = INCBIN_U32("graphics/battle_anims/sprites/glass.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Glass[] = INCBIN_U32("graphics/battle_anims/sprites/glass.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_HornHit[] = INCBIN_U32("graphics/battle_anims/sprites/horn_hit.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_HornHit[] = INCBIN_U32("graphics/battle_anims/sprites/horn_hit.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_BlueShards[] = INCBIN_U32("graphics/battle_anims/sprites/blue_shards.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueShards[] = INCBIN_U32("graphics/battle_anims/sprites/blue_shards.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimUnusedPal_MusicNotes[] = INCBIN_U32("graphics/battle_anims/unused/music_notes.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimUnusedGfx_MusicNotes[] = INCBIN_U32("graphics/battle_anims/unused/music_notes.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Hit[] = INCBIN_U32("graphics/battle_anims/sprites/hit.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Hit[] = INCBIN_U32("graphics/battle_anims/sprites/hit.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Hit2[] = INCBIN_U32("graphics/battle_anims/sprites/hit_2.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_WavingHand[] = INCBIN_U32("graphics/battle_anims/sprites/waving_hand.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_WavingHand[] = INCBIN_U32("graphics/battle_anims/sprites/waving_hand.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_ClosingEye[] = INCBIN_U32("graphics/battle_anims/sprites/closing_eye.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_ClosingEye[] = INCBIN_U32("graphics/battle_anims/sprites/closing_eye.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueStar[] = INCBIN_U32("graphics/battle_anims/sprites/blue_star.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_BlueStar[] = INCBIN_U32("graphics/battle_anims/sprites/blue_star.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_BubbleBurst[] = INCBIN_U32("graphics/battle_anims/sprites/bubble_burst.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_BubbleBurst[] = INCBIN_U32("graphics/battle_anims/sprites/bubble_burst.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_HitDuplicate[] = INCBIN_U32("graphics/battle_anims/sprites/hit_duplicate.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_HitDuplicate[] = INCBIN_U32("graphics/battle_anims/sprites/hit_duplicate.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Leer[] = INCBIN_U32("graphics/battle_anims/sprites/leer.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Leer[] = INCBIN_U32("graphics/battle_anims/sprites/leer.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_BlueBurst[] = INCBIN_U32("graphics/battle_anims/sprites/blue_burst.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueBurst[] = INCBIN_U32("graphics/battle_anims/sprites/blue_burst.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_SmallEmber[] = INCBIN_U32("graphics/battle_anims/sprites/small_ember.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_SmallEmber[] = INCBIN_U32("graphics/battle_anims/sprites/small_ember.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_GraySmoke[] = INCBIN_U32("graphics/battle_anims/sprites/gray_smoke.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_GraySmoke[] = INCBIN_U32("graphics/battle_anims/sprites/gray_smoke.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Fire[] = INCBIN_U32("graphics/battle_anims/sprites/fire.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Fire[] = INCBIN_U32("graphics/battle_anims/sprites/fire.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_SpinningFire[] = INCBIN_U32("graphics/battle_anims/sprites/spinning_fire.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_FirePlume[] = INCBIN_U32("graphics/battle_anims/sprites/fire_plume.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_Lightning2[] = INCBIN_U32("graphics/battle_anims/sprites/lightning_2.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Lightning2[] = INCBIN_U32("graphics/battle_anims/sprites/lightning_2.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_Lightning[] = INCBIN_U32("graphics/battle_anims/sprites/lightning.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpriteGfx_SpinningBall[] = INCBIN_U32("graphics/battle_anims/unused/spinning_ball.4bpp.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_SpinningBall[] = INCBIN_U32("graphics/battle_anims/unused/spinning_ball.gbapal.lz");
BATTLE_ANIM_A_BASE_GRAPHICS const u32 gBattleAnimSpritePal_SpinningBall2[] = INCBIN_U32("graphics/battle_anims/unused/spinning_ball_2.gbapal.lz");

#undef BATTLE_ANIM_A_BASE_GRAPHICS

#define BATTLE_ANIM_A_CLAW_GRAPHICS __attribute__((section(".rodata.battle_anim_a_claw_graphics"), aligned(1)))

BATTLE_ANIM_A_CLAW_GRAPHICS const u32 gBattleAnimSpritePal_ClawSlash2[] = INCBIN_U32("graphics/battle_anims/sprites/claw_slash_2.gbapal.lz");
BATTLE_ANIM_A_CLAW_GRAPHICS const u32 gBattleAnimSpritePal_ClawSlash[] = INCBIN_U32("graphics/battle_anims/sprites/claw_slash.gbapal.lz");
BATTLE_ANIM_A_CLAW_GRAPHICS const u32 gBattleAnimSpriteGfx_ClawSlash2[] = INCBIN_U32("graphics/battle_anims/sprites/claw_slash_2.4bpp.lz");
BATTLE_ANIM_A_CLAW_GRAPHICS const u32 gBattleAnimSpriteGfx_ClawSlash[] = INCBIN_U32("graphics/battle_anims/sprites/claw_slash.4bpp.lz");
BATTLE_ANIM_A_CLAW_GRAPHICS const u32 gBattleAnimSpriteGfx_Scratch3[] = INCBIN_U32("graphics/battle_anims/sprites/scratch_3.4bpp.lz");
BATTLE_ANIM_A_CLAW_GRAPHICS const u32 gBattleAnimSpriteGfx_Scratch2[] = INCBIN_U32("graphics/battle_anims/sprites/scratch_2.4bpp.lz");

#undef BATTLE_ANIM_A_CLAW_GRAPHICS

#define BATTLE_ANIM_A_BURST_GRAPHICS __attribute__((section(".rodata.battle_anim_a_burst_graphics"), aligned(1)))

BATTLE_ANIM_A_BURST_GRAPHICS const u32 gBattleAnimSpriteGfx_BubbleBurst2[] = INCBIN_U32("graphics/battle_anims/sprites/bubble_burst_2.4bpp.lz");
BATTLE_ANIM_A_BURST_GRAPHICS const u32 gBattleAnimSpritePal_BubbleBurst2[] = INCBIN_U32("graphics/battle_anims/sprites/bubble_burst_2.gbapal.lz");
BATTLE_ANIM_A_BURST_GRAPHICS const u32 gBattleAnimSpriteGfx_IceChunk[] = INCBIN_U32("graphics/battle_anims/sprites/ice_chunk.4bpp.lz");
BATTLE_ANIM_A_BURST_GRAPHICS const u32 gBattleAnimSpritePal_IceChunk[] = INCBIN_U32("graphics/battle_anims/sprites/ice_chunk.gbapal.lz");
BATTLE_ANIM_A_BURST_GRAPHICS const u32 gBattleAnimSpritePal_Glass2[] = INCBIN_U32("graphics/battle_anims/sprites/glass_2.gbapal.lz");
BATTLE_ANIM_A_BURST_GRAPHICS const u32 gBattleAnimSpriteGfx_Glass2[] = INCBIN_U32("graphics/battle_anims/sprites/glass_2.4bpp.lz");
BATTLE_ANIM_A_BURST_GRAPHICS const u32 gBattleAnimSpritePal_PinkHeart2[] = INCBIN_U32("graphics/battle_anims/sprites/pink_heart_2.gbapal.lz");
BATTLE_ANIM_A_BURST_GRAPHICS const u32 gBattleAnimSpriteGfx_PinkHeart2[] = INCBIN_U32("graphics/battle_anims/sprites/pink_heart_2.4bpp.lz");

#undef BATTLE_ANIM_A_BURST_GRAPHICS

#define BATTLE_ANIM_A_BATTLE_BAR_AND_SAP_DRIP_GRAPHICS __attribute__((section(".rodata.battle_anim_a_battle_bar_and_sap_drip_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_BATTLE_BAR_AND_SAP_DRIP_GRAPHICS const u32 gBattleInterfaceGfx_BattleBar[] = INCBIN_U32("graphics/battle_interface/battle_bar.4bpp.lz");
BATTLE_ANIM_A_BATTLE_BAR_AND_SAP_DRIP_GRAPHICS const u32 gBattleAnimSpriteGfx_SapDrip[] = INCBIN_U32("graphics/battle_anims/sprites/sap_drip.png.4bpp.lz");
BATTLE_ANIM_A_BATTLE_BAR_AND_SAP_DRIP_GRAPHICS const u32 gBattleAnimSpritePal_SapDrip[] = INCBIN_U32("graphics/battle_anims/sprites/sap_drip.png.gbapal.lz");
BATTLE_ANIM_A_BATTLE_BAR_AND_SAP_DRIP_GRAPHICS const u32 gBattleAnimSpritePal_SapDrip2[] = INCBIN_U32("graphics/battle_anims/sprites/sap_drip_2.pal.gbapal.lz");

#undef BATTLE_ANIM_A_BATTLE_BAR_AND_SAP_DRIP_GRAPHICS

#define BATTLE_ANIM_A_UNUSED_WINDOW2_GRAPHICS __attribute__((section(".rodata.battle_anim_a_unused_window2_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_UNUSED_WINDOW2_GRAPHICS const u32 gBattleInterfaceGfx_UnusedWindow2[] = INCBIN_U32("graphics/battle_interface/unused_window2.png.4bpp.lz");
BATTLE_ANIM_A_UNUSED_WINDOW2_GRAPHICS const u32 gBattleInterfaceGfx_UnusedWindow2Bar[] = INCBIN_U32("graphics/battle_interface/unused_window2bar.png.4bpp.lz");

#undef BATTLE_ANIM_A_UNUSED_WINDOW2_GRAPHICS

#define BATTLE_ANIM_A_SPARKLE_GRAPHICS __attribute__((section(".rodata.battle_anim_a_sparkle_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_SPARKLE_GRAPHICS const u32 gBattleAnimSpriteGfx_Sparkle1[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_1.png.4bpp.lz");
BATTLE_ANIM_A_SPARKLE_GRAPHICS const u32 gBattleAnimSpritePal_Sparkle1[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_1.png.gbapal.lz");
BATTLE_ANIM_A_SPARKLE_GRAPHICS const u32 gBattleAnimSpritePal_Sparkle2[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_2.pal.gbapal.lz");

#undef BATTLE_ANIM_A_SPARKLE_GRAPHICS

#define BATTLE_ANIM_A_FOOT_AND_HAND_GRAPHICS __attribute__((section(".rodata.battle_anim_a_foot_and_hand_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_FOOT_AND_HAND_GRAPHICS const u32 gBattleAnimSpritePal_HumanoidFoot[] = INCBIN_U32("graphics/battle_anims/sprites/humanoid_foot.png.gbapal.lz");
BATTLE_ANIM_A_FOOT_AND_HAND_GRAPHICS const u32 gBattleAnimSpriteGfx_HumanoidFoot[] = INCBIN_U32("graphics/battle_anims/sprites/humanoid_foot.png.4bpp.lz");
BATTLE_ANIM_A_FOOT_AND_HAND_GRAPHICS const u32 gBattleAnimSpriteGfx_MonsterFoot[] = INCBIN_U32("graphics/battle_anims/sprites/monster_foot.png.4bpp.lz");
BATTLE_ANIM_A_FOOT_AND_HAND_GRAPHICS const u32 gBattleAnimSpriteGfx_HumanoidHand[] = INCBIN_U32("graphics/battle_anims/sprites/humanoid_hand.png.4bpp.lz");

#undef BATTLE_ANIM_A_FOOT_AND_HAND_GRAPHICS

#define BATTLE_ANIM_A_IMPACT_GRAPHICS __attribute__((section(".rodata.battle_anim_a_impact_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_IMPACT_GRAPHICS const u32 gBattleAnimSpriteGfx_SlamHit[] = INCBIN_U32("graphics/battle_anims/sprites/slam_hit.png.4bpp.lz");
BATTLE_ANIM_A_IMPACT_GRAPHICS const u32 gBattleAnimSpritePal_SlamHit[] = INCBIN_U32("graphics/battle_anims/sprites/slam_hit.png.gbapal.lz");
BATTLE_ANIM_A_IMPACT_GRAPHICS const u32 gBattleAnimSpriteGfx_RedFist[] = INCBIN_U32("graphics/battle_anims/sprites/red_fist.png.4bpp.lz");

#undef BATTLE_ANIM_A_IMPACT_GRAPHICS

#define BATTLE_ANIM_A_RING_AND_ROCKS_GRAPHICS __attribute__((section(".rodata.battle_anim_a_ring_and_rocks_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_RING_AND_ROCKS_GRAPHICS const u32 gBattleAnimSpriteGfx_Ring[] = INCBIN_U32("graphics/battle_anims/sprites/ring.png.4bpp.lz");
BATTLE_ANIM_A_RING_AND_ROCKS_GRAPHICS const u32 gBattleAnimSpritePal_Ring[] = INCBIN_U32("graphics/battle_anims/sprites/ring.png.gbapal.lz");
BATTLE_ANIM_A_RING_AND_ROCKS_GRAPHICS const u32 gBattleAnimSpriteGfx_Rocks[] = INCBIN_U32("graphics/battle_anims/sprites/rocks.png.4bpp.lz");
BATTLE_ANIM_A_RING_AND_ROCKS_GRAPHICS const u32 gBattleAnimSpritePal_Rocks[] = INCBIN_U32("graphics/battle_anims/sprites/rocks.png.gbapal.lz");

#undef BATTLE_ANIM_A_RING_AND_ROCKS_GRAPHICS

#define BATTLE_ANIM_A_UNUSED_Z_AND_YELLOW_GRAPHICS __attribute__((section(".rodata.battle_anim_a_unused_z_and_yellow_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_UNUSED_Z_AND_YELLOW_GRAPHICS const u32 gBattleAnimSpriteGfx_Z[] = INCBIN_U32("graphics/battle_anims/sprites/z.png.4bpp.lz");
BATTLE_ANIM_A_UNUSED_Z_AND_YELLOW_GRAPHICS const u32 gBattleAnimSpritePal_Z[] = INCBIN_U32("graphics/battle_anims/sprites/z.png.gbapal.lz");
BATTLE_ANIM_A_UNUSED_Z_AND_YELLOW_GRAPHICS const u32 gBattleAnimSpriteGfx_YellowUnk2[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_unk_2.png.4bpp.lz");
BATTLE_ANIM_A_UNUSED_Z_AND_YELLOW_GRAPHICS const u32 gBattleAnimSpritePal_YellowUnk2[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_unk_2.png.gbapal.lz");

#undef BATTLE_ANIM_A_UNUSED_Z_AND_YELLOW_GRAPHICS

#define BATTLE_ANIM_A_AIR_AND_LEAF_GRAPHICS __attribute__((section(".rodata.battle_anim_a_air_and_leaf_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_AIR_AND_LEAF_GRAPHICS const u32 gBattleAnimSpriteGfx_AirSlash[] = INCBIN_U32("graphics/battle_anims/sprites/air_slash.png.4bpp.lz");
BATTLE_ANIM_A_AIR_AND_LEAF_GRAPHICS const u32 gBattleAnimSpritePal_AirSlash[] = INCBIN_U32("graphics/battle_anims/sprites/air_slash.png.gbapal.lz");
BATTLE_ANIM_A_AIR_AND_LEAF_GRAPHICS const u32 gBattleAnimSpriteGfx_SpinningGreenOrbs[] = INCBIN_U32("graphics/battle_anims/sprites/spinning_green_orbs.png.4bpp.lz");
BATTLE_ANIM_A_AIR_AND_LEAF_GRAPHICS const u32 gBattleAnimSpritePal_SpinningGreenOrbs[] = INCBIN_U32("graphics/battle_anims/sprites/spinning_green_orbs.png.gbapal.lz");
BATTLE_ANIM_A_AIR_AND_LEAF_GRAPHICS const u32 gBattleAnimSpriteGfx_Leaf[] = INCBIN_U32("graphics/battle_anims/sprites/leaf.png.4bpp.lz");
BATTLE_ANIM_A_AIR_AND_LEAF_GRAPHICS const u32 gBattleAnimSpritePal_Leaf[] = INCBIN_U32("graphics/battle_anims/sprites/leaf.png.gbapal.lz");

#undef BATTLE_ANIM_A_AIR_AND_LEAF_GRAPHICS

#define BATTLE_ANIM_A_STATUS_PARTICLE_GRAPHICS __attribute__((section(".rodata.battle_anim_a_status_particle_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_STATUS_PARTICLE_GRAPHICS const u32 gBattleAnimSpriteGfx_PoisonPowder[] = INCBIN_U32("graphics/battle_anims/sprites/poison_powder.png.4bpp.lz");
BATTLE_ANIM_A_STATUS_PARTICLE_GRAPHICS const u32 gBattleAnimSpritePal_PoisonPowder[] = INCBIN_U32("graphics/battle_anims/sprites/poison_powder.png.gbapal.lz");
BATTLE_ANIM_A_STATUS_PARTICLE_GRAPHICS const u32 gBattleAnimSpriteGfx_BrownTriangle[] = INCBIN_U32("graphics/battle_anims/sprites/brown_triangle.png.4bpp.lz");
BATTLE_ANIM_A_STATUS_PARTICLE_GRAPHICS const u32 gBattleAnimSpritePal_BrownTriangle[] = INCBIN_U32("graphics/battle_anims/sprites/brown_triangle.png.gbapal.lz");
BATTLE_ANIM_A_STATUS_PARTICLE_GRAPHICS const u32 gBattleAnimSpriteGfx_Sparkle3[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_3.png.4bpp.lz");
BATTLE_ANIM_A_STATUS_PARTICLE_GRAPHICS const u32 gBattleAnimSpritePal_Sparkle3[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_3.png.gbapal.lz");

#undef BATTLE_ANIM_A_STATUS_PARTICLE_GRAPHICS

#define BATTLE_ANIM_A_REACTION_GRAPHICS __attribute__((section(".rodata.battle_anim_a_reaction_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpriteGfx_Sparkle4[] = INCBIN_U32("graphics/battle_anims/sprites/sparkle_4.png.4bpp.lz");
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpriteGfx_MusicNotes[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes.png.4bpp.lz");
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpritePal_MusicNotes[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes.png.gbapal.lz");
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpriteGfx_Duck[] = INCBIN_U32("graphics/battle_anims/sprites/duck.png.4bpp.lz");
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpritePal_Duck[] = INCBIN_U32("graphics/battle_anims/sprites/duck.png.gbapal.lz");
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpriteGfx_Alert[] = INCBIN_U32("graphics/battle_anims/sprites/alert.png.4bpp.lz");
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpritePal_Alert[] = INCBIN_U32("graphics/battle_anims/sprites/alert.png.gbapal.lz");
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpriteGfx_Shock4[] = INCBIN_U32("graphics/battle_anims/sprites/shock_4.png.4bpp.lz");
BATTLE_ANIM_A_REACTION_GRAPHICS const u32 gBattleAnimSpritePal_Shock4[] = INCBIN_U32("graphics/battle_anims/sprites/shock_4.png.gbapal.lz");

#undef BATTLE_ANIM_A_REACTION_GRAPHICS

#define BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS __attribute__((section(".rodata.battle_anim_a_shock_through_blue_lines_graphics"), aligned(1)))

// The JP LZ77 streams retain their original alignment padding.
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimSpriteGfx_Shock[] = INCBIN_U32("graphics/battle_anims/sprites/shock.png.4bpp.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimSpriteGfx_Bell2[] = INCBIN_U32("graphics/battle_anims/sprites/bell_2.png.4bpp.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimSpritePal_Bell2[] = INCBIN_U32("graphics/battle_anims/sprites/bell_2.png.gbapal.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimSpriteGfx_PinkGlove[] = INCBIN_U32("graphics/battle_anims/sprites/pink_glove.png.4bpp.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimSpritePal_PinkGlove[] = INCBIN_U32("graphics/battle_anims/sprites/pink_glove.png.gbapal.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u16 gBattleAnimUnused_Unknown1[] = INCBIN_U16("graphics/battle_anims/unused/unknown_1.bin");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u16 gBattleAnimUnused_Unknown2[] = INCBIN_U16("graphics/battle_anims/unused/unknown_2.bin");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u16 gBattleAnimUnused_Unknown3[] = INCBIN_U16("graphics/battle_anims/unused/unknown_3.bin");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimUnusedGfx_LineSketch2[] = INCBIN_U32("graphics/battle_anims/unused/line_sketch_2.png.8bpp.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimUnusedPal_LineSketch2[] = INCBIN_U32("graphics/battle_anims/unused/line_sketch_2.pal.gbapal.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimUnusedTilemap_LineSketch2[] = INCBIN_U32("graphics/battle_anims/unused/line_sketch_2.bin.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueLines[] = INCBIN_U32("graphics/battle_anims/sprites/blue_lines.png.4bpp.lz");
BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS const u32 gBattleAnimSpritePal_BlueLines[] = INCBIN_U32("graphics/battle_anims/sprites/blue_lines.png.gbapal.lz");

#undef BATTLE_ANIM_A_SHOCK_THROUGH_BLUE_LINES_GRAPHICS

// Pokédex.  These custom sections retain the JP ROM order while assigning the
// resources to pokeemerald's graphics owner and source hierarchy.
#define POKEDEX_GRAPHICS_PREFIX __attribute__((section(".rodata.pokedex_graphics_prefix"), aligned(1)))

POKEDEX_GRAPHICS_PREFIX const u16 gPokedexBgHoenn_Pal[] = INCBIN_U16("graphics/pokedex/bg_hoenn.gbapal");
POKEDEX_GRAPHICS_PREFIX const u16 gPokedexSearchResults_Pal[] = INCBIN_U16("graphics/pokedex/search_results_bg.gbapal");
POKEDEX_GRAPHICS_PREFIX const u16 gPokedexBgNational_Pal[] = INCBIN_U16("graphics/pokedex/bg_national.gbapal");
POKEDEX_GRAPHICS_PREFIX const u32 gPokedexStartMenuMain_Tilemap[] = INCBIN_U32("graphics/pokedex/start_menu_main.bin.lz");
POKEDEX_GRAPHICS_PREFIX const u32 gPokedexStartMenuSearchResults_Tilemap[] = INCBIN_U32("graphics/pokedex/start_menu_search_results.bin.lz");
POKEDEX_GRAPHICS_PREFIX const u32 gPokedexList_Tilemap[] = INCBIN_U32("graphics/pokedex/list.bin.lz");
POKEDEX_GRAPHICS_PREFIX const u32 gPokedexListUnderlay_Tilemap[] = INCBIN_U32("graphics/pokedex/list_underlay.bin.lz");

#undef POKEDEX_GRAPHICS_PREFIX

#define POKEDEX_GRAPHICS_SCREEN_TILEMAPS __attribute__((section(".rodata.pokedex_graphics_screen_tilemaps"), aligned(1)))

POKEDEX_GRAPHICS_SCREEN_TILEMAPS const u32 gPokedexInfoScreen_Tilemap[] = INCBIN_U32("graphics/pokedex/info_screen.bin.lz");
POKEDEX_GRAPHICS_SCREEN_TILEMAPS const u32 gPokedexCryScreen_Tilemap[] = INCBIN_U32("graphics/pokedex/cry_screen.bin.lz");
POKEDEX_GRAPHICS_SCREEN_TILEMAPS const u32 gPokedexSizeScreen_Tilemap[] = INCBIN_U32("graphics/pokedex/size_screen.bin.lz");
POKEDEX_GRAPHICS_SCREEN_TILEMAPS const u32 gPokedexScreenSelectBarMain_Tilemap[] = INCBIN_U32("graphics/pokedex/screen_select_bar_main.bin.lz");
POKEDEX_GRAPHICS_SCREEN_TILEMAPS const u32 gPokedexScreenSelectBarSubmenu_Tilemap[] = INCBIN_U32("graphics/pokedex/screen_select_bar_submenu.bin.lz");

#undef POKEDEX_GRAPHICS_SCREEN_TILEMAPS

#define POKEDEX_GRAPHICS_MENU_INTERFACE __attribute__((section(".rodata.pokedex_graphics_menu_interface"), aligned(1)))

POKEDEX_GRAPHICS_MENU_INTERFACE const u32 gPokedexMenu_Gfx[] = INCBIN_U32("graphics/pokedex/menu.4bpp.lz");
POKEDEX_GRAPHICS_MENU_INTERFACE const u32 gPokedexInterface_Gfx[] = INCBIN_U32("graphics/pokedex/interface.4bpp.lz");

#undef POKEDEX_GRAPHICS_MENU_INTERFACE

#define INTRO_COPYRIGHT_GRAPHICS __attribute__((section(".rodata.intro_copyright_graphics")))

INTRO_COPYRIGHT_GRAPHICS const u16 gIntroCopyright_Pal[16] = INCBIN_U16("graphics/intro/copyright.gbapal");
INTRO_COPYRIGHT_GRAPHICS const u32 gIntroCopyright_Gfx[] = INCBIN_U32("graphics/intro/copyright.4bpp.lz");
INTRO_COPYRIGHT_GRAPHICS const u32 gIntroCopyright_Tilemap[] = INCBIN_U32("graphics/intro/copyright.bin.lz");

#undef INTRO_COPYRIGHT_GRAPHICS

#define INTRO_SCENE_2_PLAYER_PALETTE __attribute__((section(".rodata.intro_scene_2_player_palette")))

// JP uses a different player palette from the current US source image.
INTRO_SCENE_2_PLAYER_PALETTE const u16 gIntroPlayer_Pal[] = INCBIN_U16("graphics/intro/scene_2/player.pal.gbapal");

#undef INTRO_SCENE_2_PLAYER_PALETTE

#define INTRO_SCENE_2_CHARACTER_GRAPHICS __attribute__((section(".rodata.intro_scene_2_character_graphics")))

// The JP LZ77 files retain their original stream-alignment padding.
INTRO_SCENE_2_CHARACTER_GRAPHICS const u16 gIntroVolbeat_Pal[] = INCBIN_U16("graphics/intro/scene_2/volbeat.png.gbapal");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u16 gIntroTorchic_Pal[] = INCBIN_U16("graphics/intro/scene_2/torchic.png.gbapal");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u16 gIntroManectric_Pal[] = INCBIN_U16("graphics/intro/scene_2/manectric.png.gbapal");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u16 gIntroFlygon_Pal[] = INCBIN_U16("graphics/intro/scene_2/flygon.png.gbapal");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u32 gIntroVolbeat_Gfx[] = INCBIN_U32("graphics/intro/scene_2/volbeat.png.4bpp.lz");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u32 gIntroTorchic_Gfx[] = INCBIN_U32("graphics/intro/scene_2/torchic.png.4bpp.lz");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u32 gIntroManectric_Gfx[] = INCBIN_U32("graphics/intro/scene_2/manectric.png.4bpp.lz");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u32 gIntroFlygon_Gfx[] = INCBIN_U32("graphics/intro/scene_2/flygon.png.4bpp.lz");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u32 gIntroBrendan_Gfx[] = INCBIN_U32("graphics/intro/scene_2/brendan.png.4bpp.lz");
INTRO_SCENE_2_CHARACTER_GRAPHICS const u32 gIntroMay_Gfx[] = INCBIN_U32("graphics/intro/scene_2/may.png.4bpp.lz");

#undef INTRO_SCENE_2_CHARACTER_GRAPHICS

#define INTRO_SCENE_3_GRAPHICS __attribute__((section(".rodata.intro_scene_3_graphics")))

// The JP LZ77 files retain their original stream-alignment padding.
INTRO_SCENE_3_GRAPHICS const u32 gIntroGroudon_Gfx[] = INCBIN_U32("graphics/intro/scene_3/groudon.8bpp.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroGroudon_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/groudon.bin.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroKyogre_Gfx[] = INCBIN_U32("graphics/intro/scene_3/kyogre.8bpp.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroKyogre_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/kyogre.bin.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroLegendBg_Gfx[] = INCBIN_U32("graphics/intro/scene_3/legend_bg.4bpp.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroGroudonBg_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/groudon_bg.bin.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroKyogreBg_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/kyogre_bg.bin.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroClouds_Gfx[] = INCBIN_U32("graphics/intro/scene_3/clouds.4bpp.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroCloudsLeft_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/clouds_left.bin.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroCloudsRight_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/clouds_right.bin.lz");
INTRO_SCENE_3_GRAPHICS const u32 gIntroCloudsSun_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/clouds_sun.bin.lz");

#undef INTRO_SCENE_3_GRAPHICS

#define INTRO_SCENE_3_LIGHTNING_GRAPHICS __attribute__((section(".rodata.intro_scene_3_lightning_graphics")))

// The JP LZ77 graphics stream retains its original stream-alignment padding.
INTRO_SCENE_3_LIGHTNING_GRAPHICS const u32 gIntroLightning_Gfx[] = INCBIN_U32("graphics/intro/scene_3/lightning.png.4bpp.lz");
INTRO_SCENE_3_LIGHTNING_GRAPHICS const u16 gIntroLightning_Pal[] = INCBIN_U16("graphics/intro/scene_3/lightning.png.gbapal");

#undef INTRO_SCENE_3_LIGHTNING_GRAPHICS

#define INTRO_SCENE_3_RAYQUAZA_GRAPHICS __attribute__((section(".rodata.intro_scene_3_rayquaza_graphics")))

// The JP LZ77 files retain their original stream-alignment padding.
INTRO_SCENE_3_RAYQUAZA_GRAPHICS const u32 gIntroRayquaza_Gfx[] = INCBIN_U32("graphics/intro/scene_3/rayquaza.4bpp.lz");
INTRO_SCENE_3_RAYQUAZA_GRAPHICS const u32 gIntroRayquaza_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/rayquaza.bin.lz");
INTRO_SCENE_3_RAYQUAZA_GRAPHICS const u32 gIntroUnused1_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/unused_1.bin.lz");
INTRO_SCENE_3_RAYQUAZA_GRAPHICS const u32 gIntroUnused2_Tilemap[] = INCBIN_U32("graphics/intro/scene_3/unused_2.bin.lz");
INTRO_SCENE_3_RAYQUAZA_GRAPHICS const u32 gIntroRayquazaClouds_Gfx[] = INCBIN_U32("graphics/intro/scene_3/rayquaza_clouds.4bpp.lz");
// The JP stream is 0x27A bytes; the following two ROM bytes are unrelated data.
INTRO_SCENE_3_RAYQUAZA_GRAPHICS const u8 gIntroRayquazaClouds_Tilemap[] = INCBIN_U8("graphics/intro/scene_3/rayquaza_clouds.bin.lz");

#undef INTRO_SCENE_3_RAYQUAZA_GRAPHICS

#define INTRO_SCENE_3_BUBBLES_GRAPHICS __attribute__((section(".rodata.intro_scene_3_bubbles_graphics")))

// The JP LZ77 graphics stream retains its original stream-alignment padding.
INTRO_SCENE_3_BUBBLES_GRAPHICS const u32 gIntroBubbles_Gfx[] = INCBIN_U32("graphics/intro/scene_3/bubbles.png.4bpp.lz");
INTRO_SCENE_3_BUBBLES_GRAPHICS const u16 gIntroBubbles_Pal[] = INCBIN_U16("graphics/intro/scene_3/bubbles.png.gbapal");

#undef INTRO_SCENE_3_BUBBLES_GRAPHICS

#define INTRO_SCENE_1_EFFECTS_GRAPHICS __attribute__((section(".rodata.intro_scene_1_effects_graphics")))

// The JP LZ77 graphics streams retain their original stream-alignment padding.
INTRO_SCENE_1_EFFECTS_GRAPHICS const u32 gIntroFlygonSilhouette_Gfx[] = INCBIN_U32("graphics/intro/scene_1/flygon.png.4bpp.lz");
INTRO_SCENE_1_EFFECTS_GRAPHICS const u32 gIntroSparkle_Gfx[] = INCBIN_U32("graphics/intro/scene_1/sparkle.png.4bpp.lz");

#undef INTRO_SCENE_1_EFFECTS_GRAPHICS

#define BATTLE_ANIM_SANDSTORM_RESOURCES __attribute__((section(".rodata.battle_anim_sandstorm_resources")))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_SANDSTORM_RESOURCES const u32 gBattleAnimSpriteGfx_FlyingDirt[] = INCBIN_U32("graphics/battle_anims/sprites/flying_dirt.4bpp.lz");
BATTLE_ANIM_SANDSTORM_RESOURCES const u32 gBattleAnimBgTilemap_Sandstorm[] = INCBIN_U32("graphics/battle_anims/backgrounds/sandstorm_brew.bin.lz");
BATTLE_ANIM_SANDSTORM_RESOURCES const u32 gBattleAnimBgImage_Sandstorm[] = INCBIN_U32("graphics/battle_anims/backgrounds/sandstorm_brew.4bpp.lz");
BATTLE_ANIM_SANDSTORM_RESOURCES const u32 gBattleAnimSpritePal_FlyingDirt[] = INCBIN_U32("graphics/battle_anims/sprites/flying_dirt.gbapal.lz");

#undef BATTLE_ANIM_SANDSTORM_RESOURCES

#define BATTLE_ANIM_METAL_SOUND_RESOURCES __attribute__((section(".rodata.battle_anim_metal_sound_resources")))

// The JP LZ77 palette stream retains its original two-byte alignment padding.
BATTLE_ANIM_METAL_SOUND_RESOURCES const u32 gBattleAnimSpriteGfx_MetalSoundWaves[] = INCBIN_U32("graphics/battle_anims/sprites/metal_sound_waves.4bpp.lz");
BATTLE_ANIM_METAL_SOUND_RESOURCES const u32 gBattleAnimSpritePal_MetalSoundWaves[] = INCBIN_U32("graphics/battle_anims/sprites/metal_sound_waves.gbapal.lz");

#undef BATTLE_ANIM_METAL_SOUND_RESOURCES

#define BATTLE_ANIM_ICE_RESOURCES __attribute__((section(".rodata.battle_anim_ice_resources")))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimBgImage_Ice[] = INCBIN_U32("graphics/battle_anims/backgrounds/ice.4bpp.lz");
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimBgPalette_Ice[] = INCBIN_U32("graphics/battle_anims/backgrounds/ice.gbapal.lz");
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimBgTilemap_Ice[] = INCBIN_U32("graphics/battle_anims/backgrounds/ice.bin.lz");
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimSpriteGfx_IcicleSpear[] = INCBIN_U32("graphics/battle_anims/sprites/icicle_spear.4bpp.lz");
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimSpritePal_IcicleSpear[] = INCBIN_U32("graphics/battle_anims/sprites/icicle_spear.gbapal.lz");

#undef BATTLE_ANIM_ICE_RESOURCES

#define CONTEST_NEXT_TURN_RESOURCES __attribute__((section(".rodata.contest_next_turn_resources")))

// The JP Next Turn banner is 32 pixels wide, unlike the 64-pixel US source asset.
CONTEST_NEXT_TURN_RESOURCES const u32 gContestNextTurnGfx[] = INCBIN_U32("graphics/contest/nextturn.4bpp.lz");
CONTEST_NEXT_TURN_RESOURCES const u8 gContestNextTurnNumbersGfx[] = INCBIN_U8("graphics/contest/nextturn_numbers.4bpp");
CONTEST_NEXT_TURN_RESOURCES const u8 gContestNextTurnRandomGfx[] = INCBIN_U8("graphics/contest/nextturn_random.4bpp");

#undef CONTEST_NEXT_TURN_RESOURCES

#define CONTEST_APPLAUSE_RESOURCES __attribute__((section(".rodata.contest_applause_resources")))

// The JP applause artwork retains its original compressed stream.
CONTEST_APPLAUSE_RESOURCES const u32 gContestApplauseGfx[] = INCBIN_U32("graphics/contest/applause.4bpp.lz");
CONTEST_APPLAUSE_RESOURCES const u8 gContestApplauseMeterGfx[] = INCBIN_U8("graphics/contest/applause_meter.4bpp");
CONTEST_APPLAUSE_RESOURCES const u16 gContestPal[] = INCBIN_U16("graphics/contest/nextturn.gbapal");

#undef CONTEST_APPLAUSE_RESOURCES

#define BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES __attribute__((section(".rodata.battle_anim_splash_through_protect_resources")))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Splash[] = INCBIN_U32("graphics/battle_anims/sprites/splash.4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpritePal_Splash[] = INCBIN_U32("graphics/battle_anims/sprites/splash.gbapal.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_SweatBead[] = INCBIN_U32("graphics/battle_anims/sprites/sweat_bead.4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Pokeblock[] = INCBIN_U32("graphics/battle_anims/sprites/pokeblock.4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpritePal_Pokeblock[] = INCBIN_U32("graphics/battle_anims/sprites/pokeblock.gbapal.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Gem1[] = INCBIN_U32("graphics/battle_anims/sprites/gem_1.4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Gem2[] = INCBIN_U32("graphics/battle_anims/sprites/gem_2.4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Gem3[] = INCBIN_U32("graphics/battle_anims/sprites/gem_3.4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpritePal_Gem1[] = INCBIN_U32("graphics/battle_anims/sprites/gem_1.gbapal.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimBgImage_InAir[] = INCBIN_U32("graphics/battle_anims/backgrounds/in_air.4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimBgPalette_InAir[] = INCBIN_U32("graphics/battle_anims/backgrounds/in_air.gbapal.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimBgTilemap_InAir[] = INCBIN_U32("graphics/battle_anims/backgrounds/in_air.bin.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Protect[] = INCBIN_U32("graphics/battle_anims/sprites/protect.4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpritePal_Protect[] = INCBIN_U32("graphics/battle_anims/sprites/protect.gbapal.lz");

#undef BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES

#define BATTLE_ANIM_MUDDY_WATER_RESOURCES __attribute__((section(".rodata.battle_anim_muddy_water_resources"), aligned(1)))

// The JP LZ77 stream retains its original stream-alignment padding.
BATTLE_ANIM_MUDDY_WATER_RESOURCES const u32 gBattleAnimBackgroundImageMuddyWater_Pal[] = INCBIN_U32("graphics/battle_anims/backgrounds/water_muddy.gbapal.lz");

#undef BATTLE_ANIM_MUDDY_WATER_RESOURCES

#define BATTLE_INTERFACE_BALL_STATUS_BAR_GRAPHICS __attribute__((section(".rodata.battle_interface_ball_status_bar_graphics"), aligned(1)))

// The JP LZ77 stream retains its original stream-alignment padding.
BATTLE_INTERFACE_BALL_STATUS_BAR_GRAPHICS const u32 gBattleInterface_BallStatusBarGfx[] = INCBIN_U32("graphics/battle_interface/ball_status_bar.4bpp.lz");

#undef BATTLE_INTERFACE_BALL_STATUS_BAR_GRAPHICS

#define EGG_ICON_GRAPHICS __attribute__((section(".rodata.egg_icon_graphics"), aligned(1)))

EGG_ICON_GRAPHICS const u8 gMonIcon_Egg[] = INCBIN_U8("graphics/pokemon/egg/icon.4bpp");

#undef EGG_ICON_GRAPHICS

#define BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES __attribute__((section(".rodata.battle_anim_ghost_and_solarbeam_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgImage_Ghost[] = INCBIN_U32("graphics/battle_anims/backgrounds/ghost.4bpp.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgPalette_Ghost[] = INCBIN_U32("graphics/battle_anims/backgrounds/ghost.gbapal.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgTilemap_Ghost[] = INCBIN_U32("graphics/battle_anims/backgrounds/ghost.bin.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimSpritePal_WhipHit[] = INCBIN_U32("graphics/battle_anims/sprites/whip_hit.gbapal.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgPalette_SolarBeam[] = INCBIN_U32("graphics/battle_anims/backgrounds/solarbeam.gbapal.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgTilemap_SolarBeam[] = INCBIN_U32("graphics/battle_anims/backgrounds/solarbeam.bin.lz");

#undef BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES

#define BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES __attribute__((section(".rodata.battle_anim_cosmic_and_slam_hit_2_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimBgPalette_Cosmic[] = INCBIN_U32("graphics/battle_anims/backgrounds/cosmic.gbapal.lz");
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimBgImage_Cosmic[] = INCBIN_U32("graphics/battle_anims/backgrounds/cosmic.4bpp.lz");
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimBgTilemap_Cosmic[] = INCBIN_U32("graphics/battle_anims/backgrounds/cosmic.bin.lz");
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimSpritePal_SlamHit2[] = INCBIN_U32("graphics/battle_anims/sprites/slam_hit_2.gbapal.lz");
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimSpriteGfx_SlamHit2[] = INCBIN_U32("graphics/battle_anims/sprites/slam_hit_2.4bpp.lz");

#undef BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES

#define BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES __attribute__((section(".rodata.battle_anim_fog_through_cross_impact_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimFogTilemap[] = INCBIN_U32("graphics/battle_anims/backgrounds/fog.bin.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_WeatherBall[] = INCBIN_U32("graphics/battle_anims/sprites/weather_ball.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_WeatherBall[] = INCBIN_U32("graphics/battle_anims/sprites/weather_ball.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgTilemap_ScaryFacePlayer[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_player.bin.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgTilemap_ScaryFaceOpponent[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_opponent.bin.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgTilemap_ScaryFaceContest[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face_contest.bin.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_Hail[] = INCBIN_U32("graphics/battle_anims/sprites/hail.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_Hail[] = INCBIN_U32("graphics/battle_anims/sprites/hail.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_GreenSpike[] = INCBIN_U32("graphics/battle_anims/sprites/green_spike.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_GreenSpike[] = INCBIN_U32("graphics/battle_anims/sprites/green_spike.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_WhiteCircleOfLight[] = INCBIN_U32("graphics/battle_anims/sprites/white_circle_of_light.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_GlowyBlueOrb[] = INCBIN_U32("graphics/battle_anims/sprites/glowy_blue_orb.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_Recycle[] = INCBIN_U32("graphics/battle_anims/sprites/recycle.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_Recycle[] = INCBIN_U32("graphics/battle_anims/sprites/recycle.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_RedParticles[] = INCBIN_U32("graphics/battle_anims/sprites/red_particles.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_RedParticles[] = INCBIN_U32("graphics/battle_anims/sprites/red_particles.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_DirtMound[] = INCBIN_U32("graphics/battle_anims/sprites/dirt_mound.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_DirtMound[] = INCBIN_U32("graphics/battle_anims/sprites/dirt_mound.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgImage_Fissure[] = INCBIN_U32("graphics/battle_anims/backgrounds/fissure.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgPalette_Fissure[] = INCBIN_U32("graphics/battle_anims/backgrounds/fissure.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgTilemap_Fissure[] = INCBIN_U32("graphics/battle_anims/backgrounds/fissure.bin.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_Bird[] = INCBIN_U32("graphics/battle_anims/sprites/bird.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_Bird[] = INCBIN_U32("graphics/battle_anims/sprites/bird.gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_CrossImpact[] = INCBIN_U32("graphics/battle_anims/sprites/cross_impact.4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_CrossImpact[] = INCBIN_U32("graphics/battle_anims/sprites/cross_impact.gbapal.lz");

#undef BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES

#define BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES __attribute__((section(".rodata.battle_anim_surf_and_white_shadow_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgImage_Surf[] = INCBIN_U32("graphics/battle_anims/backgrounds/water.4bpp.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgPalette_Surf[] = INCBIN_U32("graphics/battle_anims/backgrounds/water.gbapal.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgTilemap_SurfOpponent[] = INCBIN_U32("graphics/battle_anims/backgrounds/water_opponent.bin.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgTilemap_SurfPlayer[] = INCBIN_U32("graphics/battle_anims/backgrounds/water_player.bin.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgTilemap_SurfContest[] = INCBIN_U32("graphics/battle_anims/backgrounds/water_contest.bin.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimSpritePal_Slash2[] = INCBIN_U32("graphics/battle_anims/sprites/slash_2.gbapal.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimSpriteGfx_WhiteShadow[] = INCBIN_U32("graphics/battle_anims/sprites/white_shadow.4bpp.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimSpritePal_WhiteShadow[] = INCBIN_U32("graphics/battle_anims/sprites/white_shadow.gbapal.lz");

#undef BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES

#define PARTY_MENU_AND_STATUS_ICON_RESOURCES __attribute__((section(".rodata.party_menu_and_status_icon_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
PARTY_MENU_AND_STATUS_ICON_RESOURCES const u32 gPartyMenuBg_Gfx[] = INCBIN_U32("graphics/party_menu/bg.4bpp.lz");
PARTY_MENU_AND_STATUS_ICON_RESOURCES const u32 gPartyMenuBg_Pal[] = INCBIN_U32("graphics/party_menu/bg.gbapal.lz");
PARTY_MENU_AND_STATUS_ICON_RESOURCES const u32 gPartyMenuBg_Tilemap[] = INCBIN_U32("graphics/party_menu/bg.bin.lz");
PARTY_MENU_AND_STATUS_ICON_RESOURCES const u32 gPartyMenuPokeball_Gfx[] = INCBIN_U32("graphics/party_menu/pokeball.4bpp.lz");
PARTY_MENU_AND_STATUS_ICON_RESOURCES const u32 gPartyMenuPokeballSmall_Gfx[] = INCBIN_U32("graphics/party_menu/pokeball_small.4bpp.lz");
PARTY_MENU_AND_STATUS_ICON_RESOURCES const u32 gPartyMenuPokeball_Pal[] = INCBIN_U32("graphics/party_menu/pokeball.gbapal.lz");
PARTY_MENU_AND_STATUS_ICON_RESOURCES const u32 gStatusGfx_Icons[] = INCBIN_U32("graphics/interface/status_icons.4bpp.lz");
PARTY_MENU_AND_STATUS_ICON_RESOURCES const u32 gStatusPal_Icons[] = INCBIN_U32("graphics/interface/status_icons.gbapal.lz");

// Keep ROM-locked Party Menu consumers on their original symbol names.
__asm__(
    ".global gUnknown_8D967A0\n"
    ".set gUnknown_8D967A0, gPartyMenuBg_Gfx\n"
    ".global gUnknown_8D96A68\n"
    ".set gUnknown_8D96A68, gPartyMenuBg_Pal\n"
    ".global gUnknown_8D96B54\n"
    ".set gUnknown_8D96B54, gPartyMenuBg_Tilemap\n"
);

#undef PARTY_MENU_AND_STATUS_ICON_RESOURCES

#define MOVE_TYPES_RESOURCES __attribute__((section(".rodata.move_types_resources"), aligned(1)))

// JP type-label graphics retain their region-specific glyphs.
MOVE_TYPES_RESOURCES const u32 gMoveTypes_Gfx[] = INCBIN_U32("graphics/types/move_types.4bpp.lz");
MOVE_TYPES_RESOURCES const u32 gMoveTypes_Pal[] = INCBIN_U32("graphics/types/move_types.gbapal.lz");

#undef MOVE_TYPES_RESOURCES

#define SUMMARY_SCREEN_RESOURCES __attribute__((section(".rodata.summary_screen_resources"), aligned(1)))

// The JP Summary Screen streams retain their original region-specific graphics and tilemaps.
SUMMARY_SCREEN_RESOURCES const u32 gSummaryMoveSelect_Gfx[] = INCBIN_U32("graphics/summary_screen/move_select.4bpp.lz");
SUMMARY_SCREEN_RESOURCES const u32 gSummaryMoveSelect_Pal[] = INCBIN_U32("graphics/summary_screen/move_select.gbapal.lz");
SUMMARY_SCREEN_RESOURCES const u32 gSummaryScreen_Gfx[] = INCBIN_U32("graphics/summary_screen/tiles.4bpp.lz");
SUMMARY_SCREEN_RESOURCES const u32 gSummaryScreen_Pal[] = INCBIN_U32("graphics/summary_screen/tiles.gbapal.lz");
SUMMARY_SCREEN_RESOURCES const u32 gSummaryPage_Info_Tilemap[] = INCBIN_U32("graphics/summary_screen/page_info.bin.lz");
SUMMARY_SCREEN_RESOURCES const u32 gSummaryPage_Skills_Tilemap[] = INCBIN_U32("graphics/summary_screen/page_skills.bin.lz");
SUMMARY_SCREEN_RESOURCES const u32 gSummaryPage_BattleMoves_Tilemap[] = INCBIN_U32("graphics/summary_screen/page_battle_moves.bin.lz");
SUMMARY_SCREEN_RESOURCES const u32 gSummaryPage_ContestMoves_Tilemap[] = INCBIN_U32("graphics/summary_screen/page_contest_moves.bin.lz");
SUMMARY_SCREEN_RESOURCES const u32 gSummaryPage_InfoEgg_Tilemap[] = INCBIN_U32("graphics/summary_screen/page_info_egg.bin.lz");

// Keep the ROM-locked Summary Screen literal pools on their original names.
__asm__(
    ".global gUnknown_8D97C54\n"
    ".set gUnknown_8D97C54, gMoveTypes_Pal\n"
    ".global gUnknown_8D97DD0\n"
    ".set gUnknown_8D97DD0, gSummaryScreen_Gfx\n"
    ".global gUnknown_8D9879C\n"
    ".set gUnknown_8D9879C, gSummaryScreen_Pal\n"
    ".global gUnknown_8D9888C\n"
    ".set gUnknown_8D9888C, gSummaryPage_Info_Tilemap\n"
    ".global gUnknown_8D98A44\n"
    ".set gUnknown_8D98A44, gSummaryPage_Skills_Tilemap\n"
    ".global gUnknown_8D98BA8\n"
    ".set gUnknown_8D98BA8, gSummaryPage_BattleMoves_Tilemap\n"
    ".global gUnknown_8D98D14\n"
    ".set gUnknown_8D98D14, gSummaryPage_ContestMoves_Tilemap\n"
    ".global gUnknown_8D98E8C\n"
    ".set gUnknown_8D98E8C, gSummaryPage_InfoEgg_Tilemap\n"
);

#undef SUMMARY_SCREEN_RESOURCES

#define SHOP_MENU_RESOURCES __attribute__((section(".rodata.shop_menu_resources"), aligned(1)))

// Retain the JP Shop Menu graphics streams and their original alignment padding.
SHOP_MENU_RESOURCES const u32 gShopMenu_Gfx[] = INCBIN_U32("graphics/shop/menu.4bpp.lz");
SHOP_MENU_RESOURCES const u32 gShopMenu_Pal[] = INCBIN_U32("graphics/shop/menu.gbapal.lz");
SHOP_MENU_RESOURCES const u32 gShopMenu_Tilemap[] = INCBIN_U32("graphics/shop/menu.bin.lz");
SHOP_MENU_RESOURCES const u32 gShopMenuMoney_Gfx[] = INCBIN_U32("graphics/shop/money.4bpp.lz");

// Keep the ROM-locked Shop loader on its original symbol names.
__asm__(
    ".global gUnknown_8D9B1B4\n"
    ".set gUnknown_8D9B1B4, gShopMenu_Gfx\n"
    ".global gUnknown_8D9B2C0\n"
    ".set gUnknown_8D9B2C0, gShopMenu_Pal\n"
    ".global gUnknown_8D9B2E8\n"
    ".set gUnknown_8D9B2E8, gShopMenu_Tilemap\n"
);

#undef SHOP_MENU_RESOURCES

#define MON_ICON_PALETTES_DATA __attribute__((section(".rodata.mon_icon_palettes_mid57a")))

MON_ICON_PALETTES_DATA const u16 gMonIconPalettes[][16] = INCBIN_U16(
    "graphics/pokemon/icon_palettes/icon_palette_0.pal.gbapal",
    "graphics/pokemon/icon_palettes/icon_palette_1.pal.gbapal",
    "graphics/pokemon/icon_palettes/icon_palette_2.pal.gbapal");
#undef MON_ICON_PALETTES_DATA

#define POKEBLOCK_GRAPHICS __attribute__((section(".rodata.pokeblock_graphics")))

POKEBLOCK_GRAPHICS const u32 gMenuPokeblock_Gfx[] = INCBIN_U32("graphics/pokeblock/menu.png.4bpp.lz");
POKEBLOCK_GRAPHICS const u8 gMenuPokeblock_Pal[] = INCBIN_U8("graphics/pokeblock/menu.pal.gbapal.lz");
static const u16 sPokeblockGraphicsPadding POKEBLOCK_GRAPHICS __attribute__((used)) = 0;
POKEBLOCK_GRAPHICS const u32 gMenuPokeblockDevice_Gfx[] = INCBIN_U32("graphics/pokeblock/device.png.4bpp.lz");
POKEBLOCK_GRAPHICS const u32 gMenuPokeblockDevice_Pal[] = INCBIN_U32("graphics/pokeblock/device.png.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gMenuPokeblock_Tilemap[] = INCBIN_U32("graphics/pokeblock/menu.bin.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblock_Gfx[] = INCBIN_U32("graphics/pokeblock/pokeblock.png.4bpp.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockRed_Pal[] = INCBIN_U32("graphics/pokeblock/red.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockBlue_Pal[] = INCBIN_U32("graphics/pokeblock/blue.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockPink_Pal[] = INCBIN_U32("graphics/pokeblock/pink.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockGreen_Pal[] = INCBIN_U32("graphics/pokeblock/green.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockYellow_Pal[] = INCBIN_U32("graphics/pokeblock/yellow.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockPurple_Pal[] = INCBIN_U32("graphics/pokeblock/purple.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockIndigo_Pal[] = INCBIN_U32("graphics/pokeblock/indigo.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockBrown_Pal[] = INCBIN_U32("graphics/pokeblock/brown.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockLiteBlue_Pal[] = INCBIN_U32("graphics/pokeblock/liteblue.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockOlive_Pal[] = INCBIN_U32("graphics/pokeblock/olive.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockGray_Pal[] = INCBIN_U32("graphics/pokeblock/gray.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockBlack_Pal[] = INCBIN_U32("graphics/pokeblock/black.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockWhite_Pal[] = INCBIN_U32("graphics/pokeblock/white.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockGold_Pal[] = INCBIN_U32("graphics/pokeblock/gold.pal.gbapal.lz");
POKEBLOCK_GRAPHICS const u32 gPokeblockFeedBg_Tilemap[] = INCBIN_U32("graphics/pokeblock/feeding_bg.bin.lz");

#undef POKEBLOCK_GRAPHICS

#define BAG_GRAPHICS __attribute__((section(".rodata.bag_graphics")))

BAG_GRAPHICS const u32 gBagMaleTiles[] = INCBIN_U32("graphics/bag/bag_male.4bpp.lz");
BAG_GRAPHICS const u32 gBagFemaleTiles[] = INCBIN_U32("graphics/bag/bag_female.4bpp.lz");
BAG_GRAPHICS const u32 gBagPalette[] = INCBIN_U32("graphics/bag/bag.pal.gbapal.lz");

#undef BAG_GRAPHICS

#define BAG_MENU_RESOURCES __attribute__((section(".rodata.bag_menu_resources"), aligned(1)))

// Retain the JP Bag Menu streams and their original alignment padding.
BAG_MENU_RESOURCES const u32 gBagScreenMale_Pal[] = INCBIN_U32("graphics/bag/menu_male.pal.gbapal.lz");
BAG_MENU_RESOURCES const u32 gBagScreenFemale_Pal[] = INCBIN_U32("graphics/bag/menu_female.pal.gbapal.lz");
BAG_MENU_RESOURCES const u32 gBagScreen_Gfx[] = INCBIN_U32("graphics/bag/menu.4bpp.lz");
BAG_MENU_RESOURCES const u32 gBagScreen_GfxTileMap[] = INCBIN_U32("graphics/bag/menu.bin.lz");
BAG_MENU_RESOURCES const u32 gBattlePyramidBag_Gfx[] = INCBIN_U32("graphics/bag/bag_pyramid.4bpp.lz");
BAG_MENU_RESOURCES const u32 gBattlePyramidBag_Pal[] = INCBIN_U32("graphics/bag/bag_pyramid.pal.gbapal.lz");
BAG_MENU_RESOURCES const u32 gBattlePyramidBagTilemap[] = INCBIN_U32("graphics/bag/menu_pyramid.bin.lz");
BAG_MENU_RESOURCES const u32 gBattlePyramidBagInterface_Pal[] = INCBIN_U32("graphics/bag/menu_pyramid.pal.gbapal.lz");

// Keep the ROM-locked Bag menu loaders on their original address symbols.
__asm__(
    ".global gUnknown_8D9A734\n"
    ".set gUnknown_8D9A734, gBagScreenMale_Pal\n"
    ".global gUnknown_8D9A780\n"
    ".set gUnknown_8D9A780, gBagScreenFemale_Pal\n"
    ".global gUnknown_8D9A7CC\n"
    ".set gUnknown_8D9A7CC, gBagScreen_Gfx\n"
    ".global gUnknown_8D9AA84\n"
    ".set gUnknown_8D9AA84, gBagScreen_GfxTileMap\n"
    ".global gUnknown_8D9AFC8\n"
    ".set gUnknown_8D9AFC8, gBattlePyramidBag_Pal\n"
    ".global gUnknown_8D9AFFC\n"
    ".set gUnknown_8D9AFFC, gBattlePyramidBagTilemap\n"
    ".global gUnknown_8D9B13C\n"
    ".set gUnknown_8D9B13C, gBattlePyramidBagInterface_Pal\n"
);

#undef BAG_MENU_RESOURCES

#define SMOKESCREEN_IMPACT_GRAPHICS __attribute__((section(".rodata.smokescreen_impact_graphics"), aligned(1)))

SMOKESCREEN_IMPACT_GRAPHICS const u32 gSmokescreenImpactTiles[] = INCBIN_U32("graphics/battle_anims/sprites/smokescreen_impact.4bpp.lz");
SMOKESCREEN_IMPACT_GRAPHICS const u32 gSmokescreenImpactPalette[] = INCBIN_U32("graphics/battle_anims/sprites/smokescreen_impact.gbapal.lz");

#undef SMOKESCREEN_IMPACT_GRAPHICS

#define ENEMY_SHADOW_GRAPHICS __attribute__((section(".rodata.enemy_shadow_graphics"), aligned(1)))

ENEMY_SHADOW_GRAPHICS const u32 gEnemyMonShadow_Gfx[] = INCBIN_U32("graphics/battle_interface/enemy_mon_shadow.4bpp.lz");

#undef ENEMY_SHADOW_GRAPHICS

#define BERRY_BLENDER_BACKGROUND_GRAPHICS __attribute__((section(".rodata.berry_blender_background_graphics"), aligned(1)))

BERRY_BLENDER_BACKGROUND_GRAPHICS const u32 gBerryBlenderCenter_Gfx[] = INCBIN_U32("graphics/berry_blender/center.8bpp.lz");
BERRY_BLENDER_BACKGROUND_GRAPHICS const u32 gBerryBlenderOuter_Gfx[] = INCBIN_U32("graphics/berry_blender/outer.4bpp.lz");
BERRY_BLENDER_BACKGROUND_GRAPHICS const u8 gBerryBlenderOuter_Tilemap[] = INCBIN_U8("graphics/berry_blender/outer_map.bin.lz");

#undef BERRY_BLENDER_BACKGROUND_GRAPHICS

#define TRADE_MENU_GRAPHICS __attribute__((section(".rodata.trade_menu_graphics"), aligned(1)))

TRADE_MENU_GRAPHICS const u16 gTradeMenu_Pal[] = INCBIN_U16("graphics/trade/menu.gbapal");
TRADE_MENU_GRAPHICS const u8 gTradeMenu_Gfx[] = INCBIN_U8("graphics/trade/menu.4bpp");
TRADE_MENU_GRAPHICS const u16 gTradeMenu_Tilemap[] = INCBIN_U16("graphics/trade/menu.bin");

#undef TRADE_MENU_GRAPHICS

#define TRADE_MENU_MON_BOX_GRAPHICS __attribute__((section(".rodata.trade_menu_mon_box_graphics"), aligned(1)))

TRADE_MENU_MON_BOX_GRAPHICS const u16 gTradeMenuMonBox_Tilemap[] = INCBIN_U16("graphics/trade/menu_mon_box.bin");

#undef TRADE_MENU_MON_BOX_GRAPHICS

#define SWAP_LINE_GRAPHICS __attribute__((section(".rodata.swap_line_graphics"), aligned(1)))

SWAP_LINE_GRAPHICS const u32 gSwapLineGfx[] = INCBIN_U32("graphics/interface/swap_line.4bpp.lz");
SWAP_LINE_GRAPHICS const u32 gSwapLinePal[] = INCBIN_U32("graphics/interface/swap_line.gbapal.lz");

#undef SWAP_LINE_GRAPHICS

#define BERRY_CHECK_GRAPHICS __attribute__((section(".rodata.berry_check_graphics")))
#define BERRY_CHECK_PALETTE __attribute__((section(".rodata.berry_check_palette")))
#define BERRY_TAG_GRAPHICS __attribute__((section(".rodata.berry_tag_graphics")))
#define BERRY_GRAPHICS __attribute__((section(".rodata.berry_graphics")))

#include "data/graphics/berries.h"

#undef BERRY_CHECK_GRAPHICS
#undef BERRY_CHECK_PALETTE
#undef BERRY_TAG_GRAPHICS
#undef BERRY_GRAPHICS

#define BERRY_CRUSH_GRAPHICS __attribute__((section(".rodata.berry_crush_graphics")))

BERRY_CRUSH_GRAPHICS const u16 gBerryCrush_Crusher_Pal[] = INCBIN_U16("graphics/berry_crush/gBerryCrush_Crusher_Pal.bin");
BERRY_CRUSH_GRAPHICS const u32 gBerryCrush_Crusher_Gfx[] = INCBIN_U32("graphics/berry_crush/gBerryCrush_Crusher_Gfx.bin");

#undef BERRY_CRUSH_GRAPHICS


#define JP_CONTEST_GFX __attribute__((section(".rodata.jp_contest_graphics")))

JP_CONTEST_GFX const u32 gJPContestGfx1[] = INCBIN_U32("graphics/contest/japanese/composite_1.4bpp.lz");
JP_CONTEST_GFX const u32 gJPContestPal[] = INCBIN_U32("graphics/contest/japanese/palette.pal.gbapal.lz");
JP_CONTEST_GFX const u32 gJPContestBgTilemap[] = INCBIN_U32("graphics/contest/japanese/bg.bin.lz");
JP_CONTEST_GFX const u32 gJPContestWindowsTilemap[] = INCBIN_U32("graphics/contest/japanese/windows.bin.lz");
JP_CONTEST_GFX const u32 gJPContestGfx2[] = INCBIN_U32("graphics/contest/japanese/composite_2.4bpp.lz");
JP_CONTEST_GFX const u32 gContestInterfaceAudiencePalette[] = INCBIN_U32("graphics/contest/interface.png.gbapal.lz");
JP_CONTEST_GFX const u32 gContestAudienceTilemap[] = INCBIN_U32("graphics/contest/audience.bin.lz");
JP_CONTEST_GFX const u32 gContestInterfaceTilemap[] = INCBIN_U32("graphics/contest/interface.bin.lz");
JP_CONTEST_GFX const u32 gJPContestInterfaceTilemap[] = INCBIN_U32("graphics/contest/japanese/interface.bin.lz");
JP_CONTEST_GFX const u32 gJPContestAudienceTilemap[] = INCBIN_U32("graphics/contest/japanese/audience.bin.lz");
JP_CONTEST_GFX const u32 gContestCurtainTilemap[] = INCBIN_U32("graphics/contest/curtain.bin.lz");
JP_CONTEST_GFX const u32 gContestInterfaceGfx[] = INCBIN_U32("graphics/contest/interface.png.4bpp.lz");
JP_CONTEST_GFX const u32 gContestAudienceGfx[] = INCBIN_U32("graphics/contest/audience.png.4bpp.lz");
JP_CONTEST_GFX const u32 gContestFaces_Gfx[] = INCBIN_U32("graphics/contest/faces.png.4bpp.lz");
JP_CONTEST_GFX const u32 gContestJudgeSymbolsGfx[] = INCBIN_U32("graphics/contest/judge_symbols.png.4bpp.lz");
JP_CONTEST_GFX const u32 gContestJudgeSymbolsPal[] = INCBIN_U32("graphics/contest/judge_symbols.png.gbapal.lz");
JP_CONTEST_GFX const u8 gContestSliderHeart_Gfx[] = INCBIN_U8("graphics/contest/slider_heart.4bpp");
JP_CONTEST_GFX const u32 gJPContestVoltageGfx[] = INCBIN_U32("graphics/contest/japanese/voltage.4bpp.lz");
JP_CONTEST_GFX const u32 gJPContestVoltagePal[] = INCBIN_U32("graphics/contest/japanese/voltage.gbapal.lz");
JP_CONTEST_GFX const u32 gContestResults_Gfx[] = INCBIN_U32("graphics/contest/results_screen/tiles.4bpp.lz");
JP_CONTEST_GFX const u32 gContestResults_WinnerBanner_Tilemap[] = INCBIN_U32("graphics/contest/results_screen/winner_banner.bin.lz");
JP_CONTEST_GFX const u32 gContestResults_Interface_Tilemap[] = INCBIN_U32("graphics/contest/results_screen/interface.bin.lz");
JP_CONTEST_GFX const u32 gContestResults_Bg_Tilemap[] = INCBIN_U32("graphics/contest/results_screen/bg.bin.lz");
JP_CONTEST_GFX const u32 gContestResults_Pal[] = INCBIN_U32("graphics/contest/results_screen/tiles.png.gbapal.lz");

#undef JP_CONTEST_GFX

#define BATTLE_ANIM_POST_CONTEST_GFX __attribute__((section(".rodata.battle_anim_post_contest_graphics")))

BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Impact[] = INCBIN_U32("graphics/battle_anims/sprites/impact.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Impact[] = INCBIN_U32("graphics/battle_anims/sprites/impact.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Particles[] = INCBIN_U32("graphics/battle_anims/sprites/particles.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_CircleImpact[] = INCBIN_U32("graphics/battle_anims/sprites/circle_impact.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_CircleImpact[] = INCBIN_U32("graphics/battle_anims/sprites/circle_impact.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Scratch[] = INCBIN_U32("graphics/battle_anims/sprites/scratch.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_SharpTeeth[] = INCBIN_U32("graphics/battle_anims/sprites/sharp_teeth.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_SharpTeeth[] = INCBIN_U32("graphics/battle_anims/sprites/sharp_teeth.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Clamp[] = INCBIN_U32("graphics/battle_anims/sprites/clamp.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Cut[] = INCBIN_U32("graphics/battle_anims/sprites/cut.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_RainbowRings[] = INCBIN_U32("graphics/battle_anims/sprites/rainbow_rings.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_RainbowRings[] = INCBIN_U32("graphics/battle_anims/sprites/rainbow_rings.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_IceCrystals[] = INCBIN_U32("graphics/battle_anims/sprites/ice_crystals.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_IceCrystals[] = INCBIN_U32("graphics/battle_anims/sprites/ice_crystals.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_IceSpikes[] = INCBIN_U32("graphics/battle_anims/sprites/ice_spikes.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_OldBeatUp[] = INCBIN_U32("graphics/battle_anims/unused/old_beatup.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_OldBeatUp[] = INCBIN_U32("graphics/battle_anims/unused/old_beatup.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Orbs[] = INCBIN_U32("graphics/battle_anims/sprites/orbs.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Orbs[] = INCBIN_U32("graphics/battle_anims/sprites/orbs.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_WaterOrb[] = INCBIN_U32("graphics/battle_anims/sprites/water_orb.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_WaterImpact[] = INCBIN_U32("graphics/battle_anims/sprites/water_impact.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_WaterImpact[] = INCBIN_U32("graphics/battle_anims/sprites/water_impact.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BrownOrb[] = INCBIN_U32("graphics/battle_anims/sprites/brown_orb.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_MudSand[] = INCBIN_U32("graphics/battle_anims/sprites/mud_sand.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_MudSand[] = INCBIN_U32("graphics/battle_anims/sprites/mud_sand.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_PoisonBubble[] = INCBIN_U32("graphics/battle_anims/sprites/poison_bubble.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_PoisonBubble[] = INCBIN_U32("graphics/battle_anims/sprites/poison_bubble.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_ToxicBubble[] = INCBIN_U32("graphics/battle_anims/sprites/toxic_bubble.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_HornHit2[] = INCBIN_U32("graphics/battle_anims/sprites/horn_hit_2.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_HornHit2[] = INCBIN_U32("graphics/battle_anims/sprites/horn_hit_2.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_AirWave2[] = INCBIN_U32("graphics/battle_anims/sprites/air_wave_2.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_AirWave2[] = INCBIN_U32("graphics/battle_anims/sprites/air_wave_2.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_SmallBubbles[] = INCBIN_U32("graphics/battle_anims/sprites/small_bubbles.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_SmallBubbles[] = INCBIN_U32("graphics/battle_anims/sprites/small_bubbles.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_RoundShadow[] = INCBIN_U32("graphics/battle_anims/sprites/round_shadow.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_RoundShadow[] = INCBIN_U32("graphics/battle_anims/sprites/round_shadow.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Sunlight[] = INCBIN_U32("graphics/battle_anims/sprites/sunlight.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Sunlight[] = INCBIN_U32("graphics/battle_anims/sprites/sunlight.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Spore[] = INCBIN_U32("graphics/battle_anims/sprites/spore.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Spore[] = INCBIN_U32("graphics/battle_anims/sprites/spore.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Flower[] = INCBIN_U32("graphics/battle_anims/sprites/flower.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Flower[] = INCBIN_U32("graphics/battle_anims/sprites/flower.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_RazorLeaf[] = INCBIN_U32("graphics/battle_anims/sprites/razor_leaf.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_RazorLeaf[] = INCBIN_U32("graphics/battle_anims/sprites/razor_leaf.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_MistCloud[] = INCBIN_U32("graphics/battle_anims/sprites/mist_cloud.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_MistCloud[] = INCBIN_U32("graphics/battle_anims/sprites/mist_cloud.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimUnusedGfx_Lights[] = INCBIN_U32("graphics/battle_anims/unused/lights.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimUnusedPal_Lights[] = INCBIN_U32("graphics/battle_anims/unused/lights.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimUnusedTilemap_Lights[] = INCBIN_U32("graphics/battle_anims/unused/lights.bin.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_WhirlwindLines[] = INCBIN_U32("graphics/battle_anims/sprites/whirlwind_lines.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_WhirlwindLines[] = INCBIN_U32("graphics/battle_anims/sprites/whirlwind_lines.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_GoldRing[] = INCBIN_U32("graphics/battle_anims/sprites/gold_ring.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_GoldRing[] = INCBIN_U32("graphics/battle_anims/sprites/gold_ring.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BlueRing2[] = INCBIN_U32("graphics/battle_anims/sprites/blue_ring_2.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_PurpleRing[] = INCBIN_U32("graphics/battle_anims/sprites/purple_ring.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BlueRing[] = INCBIN_U32("graphics/battle_anims/sprites/blue_ring.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_GreenLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/green_light_wall.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_GreenLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/green_light_wall.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BlueLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/blue_light_wall.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_RedLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/red_light_wall.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_GrayLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/gray_light_wall.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_OrangeLightWall[] = INCBIN_U32("graphics/battle_anims/sprites/orange_light_wall.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_BlackBall2[] = INCBIN_U32("graphics/battle_anims/sprites/black_ball_2.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BlackBall2[] = INCBIN_U32("graphics/battle_anims/sprites/black_ball_2.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_PurpleGasCloud[] = INCBIN_U32("graphics/battle_anims/sprites/purple_gas_cloud.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gContestJudgeGfx[] = INCBIN_U32("graphics/contest/judge.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gContest2Pal[] = INCBIN_U32("graphics/contest/judge.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Spark[] = INCBIN_U32("graphics/battle_anims/sprites/spark.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Spark[] = INCBIN_U32("graphics/battle_anims/sprites/spark.pal.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_SparkH[] = INCBIN_U32("graphics/battle_anims/sprites/spark_h.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimBgImage_Dark[] = INCBIN_U32("graphics/battle_anims/backgrounds/dark.png.4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimBgPalette_Dark[] = INCBIN_U32("graphics/battle_anims/backgrounds/dark.png.gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimBgTilemap_Dark[] = INCBIN_U32("graphics/battle_anims/backgrounds/dark.bin.lz");

#undef BATTLE_ANIM_POST_CONTEST_GFX

#define BATTLE_INTERFACE_GFX __attribute__((section(".rodata.battle_interface_graphics")))

BATTLE_INTERFACE_GFX const u16 gBattleInterface_BallStatusBarPal[] = INCBIN_U16("graphics/battle_interface/ball_status_bar.gbapal");
BATTLE_INTERFACE_GFX const u16 gBattleInterface_BallDisplayPal[] = INCBIN_U16("graphics/battle_interface/ball_display.gbapal");
BATTLE_INTERFACE_GFX const u8 gHealthboxElementsGfxTable[][32] = INCBIN_U8(
    "graphics/battle_interface/hpbar.4bpp",
    "graphics/battle_interface/expbar.4bpp",
    "graphics/battle_interface/status.4bpp",
    "graphics/battle_interface/misc.4bpp",
    "graphics/battle_interface/hpbar_anim.4bpp",
    "graphics/battle_interface/misc_frameend.4bpp",
    "graphics/battle_interface/ball_display.4bpp",
    "graphics/battle_interface/ball_caught_indicator.4bpp",
    "graphics/battle_interface/status2.4bpp",
    "graphics/battle_interface/status3.4bpp",
    "graphics/battle_interface/status4.4bpp",
    "graphics/battle_interface/healthbox_doubles_frameend.4bpp",
    "graphics/battle_interface/healthbox_doubles_frameend_bar.4bpp");

#undef BATTLE_INTERFACE_GFX

#define BATTLE_ANIM_MASK_AND_BG_GFX __attribute__((section(".rodata.battle_anim_mask_and_bg_graphics")))

BATTLE_ANIM_MASK_AND_BG_GFX const u32 gMetalShineGfx[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gMetalShinePalette[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gMetalShineTilemap[] = INCBIN_U32("graphics/battle_anims/masks/metal_shine.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedGfx_Goosuto[] = INCBIN_U32("graphics/battle_anims/unused/goosuto.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedPal_Goosuto[] = INCBIN_U32("graphics/battle_anims/unused/goosuto.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedTilemap_Goosuto[] = INCBIN_U32("graphics/battle_anims/unused/goosuto.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_YellowStar[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_star.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_YellowStar[] = INCBIN_U32("graphics/battle_anims/sprites/yellow_star.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_LargeFreshEgg[] = INCBIN_U32("graphics/battle_anims/sprites/large_fresh_egg.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_LargeFreshEgg[] = INCBIN_U32("graphics/battle_anims/sprites/large_fresh_egg.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ShadowBall[] = INCBIN_U32("graphics/battle_anims/sprites/shadow_ball.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ShadowBall[] = INCBIN_U32("graphics/battle_anims/sprites/shadow_ball.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Lick[] = INCBIN_U32("graphics/battle_anims/sprites/lick.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Lick[] = INCBIN_U32("graphics/battle_anims/sprites/lick.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_VoidLines[] = INCBIN_U32("graphics/battle_anims/sprites/void_lines.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_VoidLines[] = INCBIN_U32("graphics/battle_anims/sprites/void_lines.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_String[] = INCBIN_U32("graphics/battle_anims/sprites/string.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_String[] = INCBIN_U32("graphics/battle_anims/sprites/string.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_WebThread[] = INCBIN_U32("graphics/battle_anims/sprites/web_thread.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SpiderWeb[] = INCBIN_U32("graphics/battle_anims/sprites/spider_web.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Lightbulb[] = INCBIN_U32("graphics/battle_anims/sprites/lightbulb.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Lightbulb[] = INCBIN_U32("graphics/battle_anims/sprites/lightbulb.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Slash[] = INCBIN_U32("graphics/battle_anims/sprites/slash.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Slash[] = INCBIN_U32("graphics/battle_anims/sprites/slash.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_FocusEnergy[] = INCBIN_U32("graphics/battle_anims/sprites/focus_energy.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_FocusEnergy[] = INCBIN_U32("graphics/battle_anims/sprites/focus_energy.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SphereToCube[] = INCBIN_U32("graphics/battle_anims/sprites/sphere_to_cube.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_SphereToCube[] = INCBIN_U32("graphics/battle_anims/sprites/sphere_to_cube.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Psychic[] = INCBIN_U32("graphics/battle_anims/backgrounds/psychic.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Psychic[] = INCBIN_U32("graphics/battle_anims/backgrounds/psychic.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Psychic[] = INCBIN_U32("graphics/battle_anims/backgrounds/psychic.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Eye[] = INCBIN_U32("graphics/battle_anims/sprites/eye.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Eye[] = INCBIN_U32("graphics/battle_anims/sprites/eye.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Tendrils[] = INCBIN_U32("graphics/battle_anims/sprites/tendrils.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Tendrils[] = INCBIN_U32("graphics/battle_anims/sprites/tendrils.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxSinglesPlayerGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_singles_player.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxSinglesOpponentGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_singles_opponent.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxDoublesPlayerGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_doubles_player.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxDoublesOpponentGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_doubles_opponent.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxSafariGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_safari.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedGfx_Shadow[] = INCBIN_U32("graphics/unused/shadow.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedPal_Shadow[] = INCBIN_U32("graphics/unused/shadow.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_LockOn[] = INCBIN_U32("graphics/battle_anims/sprites/lock_on.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_LockOn[] = INCBIN_U32("graphics/battle_anims/sprites/lock_on.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_OpeningEye[] = INCBIN_U32("graphics/battle_anims/sprites/opening_eye.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_OpeningEye[] = INCBIN_U32("graphics/battle_anims/sprites/opening_eye.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_RoundWhiteHalo[] = INCBIN_U32("graphics/battle_anims/sprites/round_white_halo.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RoundWhiteHalo[] = INCBIN_U32("graphics/battle_anims/sprites/round_white_halo.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_TealAlert[] = INCBIN_U32("graphics/battle_anims/sprites/teal_alert.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_TealAlert[] = INCBIN_U32("graphics/battle_anims/sprites/teal_alert.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_FangAttack[] = INCBIN_U32("graphics/battle_anims/sprites/fang_attack.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_FangAttack[] = INCBIN_U32("graphics/battle_anims/sprites/fang_attack.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PurpleHandOutline[] = INCBIN_U32("graphics/battle_anims/sprites/purple_hand_outline.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PurpleHandOutline[] = INCBIN_U32("graphics/battle_anims/sprites/purple_hand_outline.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskImage_Curse[] = INCBIN_U32("graphics/battle_anims/masks/curse.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskTilemap_Curse[] = INCBIN_U32("graphics/battle_anims/masks/curse.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Pencil[] = INCBIN_U32("graphics/battle_anims/sprites/pencil.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Pencil[] = INCBIN_U32("graphics/battle_anims/sprites/pencil.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Spiral[] = INCBIN_U32("graphics/battle_anims/sprites/spiral.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Spiral[] = INCBIN_U32("graphics/battle_anims/sprites/spiral.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Moon[] = INCBIN_U32("graphics/battle_anims/sprites/moon.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Moon[] = INCBIN_U32("graphics/battle_anims/sprites/moon.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GreenSparkle[] = INCBIN_U32("graphics/battle_anims/sprites/green_sparkle.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GreenSparkle[] = INCBIN_U32("graphics/battle_anims/sprites/green_sparkle.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SnoreZ[] = INCBIN_U32("graphics/battle_anims/sprites/snore_z.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_SnoreZ[] = INCBIN_U32("graphics/battle_anims/sprites/snore_z.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Explosion[] = INCBIN_U32("graphics/battle_anims/sprites/explosion.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Explosion[] = INCBIN_U32("graphics/battle_anims/sprites/explosion.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Nail[] = INCBIN_U32("graphics/battle_anims/sprites/nail.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Nail[] = INCBIN_U32("graphics/battle_anims/sprites/nail.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GhostlySpirit[] = INCBIN_U32("graphics/battle_anims/sprites/ghostly_spirit.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GhostlySpirit[] = INCBIN_U32("graphics/battle_anims/sprites/ghostly_spirit.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_WarmRock[] = INCBIN_U32("graphics/battle_anims/sprites/warm_rock.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_WarmRock[] = INCBIN_U32("graphics/battle_anims/sprites/warm_rock.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PunchImpact[] = INCBIN_U32("graphics/battle_anims/sprites/punch_impact.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PunchImpact[] = INCBIN_U32("graphics/battle_anims/sprites/punch_impact.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_BreakingEgg[] = INCBIN_U32("graphics/battle_anims/sprites/breaking_egg.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_BreakingEgg[] = INCBIN_U32("graphics/battle_anims/sprites/breaking_egg.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ThinRing[] = INCBIN_U32("graphics/battle_anims/sprites/thin_ring.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ThinRing[] = INCBIN_U32("graphics/battle_anims/sprites/thin_ring.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_MusicNotes2[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes_2.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MusicNotes2[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes_2.pal.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Bell[] = INCBIN_U32("graphics/battle_anims/sprites/bell.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Bell[] = INCBIN_U32("graphics/battle_anims/sprites/bell.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SpeedDust[] = INCBIN_U32("graphics/battle_anims/sprites/speed_dust.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_SpeedDust[] = INCBIN_U32("graphics/battle_anims/sprites/speed_dust.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_TornMetal[] = INCBIN_U32("graphics/battle_anims/sprites/torn_metal.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ThoughtBubble[] = INCBIN_U32("graphics/battle_anims/sprites/thought_bubble.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ThoughtBubble[] = INCBIN_U32("graphics/battle_anims/sprites/thought_bubble.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Finger[] = INCBIN_U32("graphics/battle_anims/sprites/finger.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Finger[] = INCBIN_U32("graphics/battle_anims/sprites/finger.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_MagentaHeart[] = INCBIN_U32("graphics/battle_anims/sprites/magenta_heart.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PinkHeart[] = INCBIN_U32("graphics/battle_anims/sprites/pink_heart.pal.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MagentaHeart[] = INCBIN_U32("graphics/battle_anims/sprites/magenta_heart.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RedHeart[] = INCBIN_U32("graphics/battle_anims/sprites/red_heart.pal.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Attract[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Attract[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Attract[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_RedOrb[] = INCBIN_U32("graphics/battle_anims/sprites/red_orb.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RedOrb[] = INCBIN_U32("graphics/battle_anims/sprites/red_orb.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_CircleOfLight[] = INCBIN_U32("graphics/battle_anims/sprites/circle_of_light.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ElectricOrbs[] = INCBIN_U32("graphics/battle_anims/sprites/electric_orbs.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Electricity[] = INCBIN_U32("graphics/battle_anims/sprites/electricity.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ElectricOrbs[] = INCBIN_U32("graphics/battle_anims/sprites/electric_orbs.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Finger2[] = INCBIN_U32("graphics/battle_anims/sprites/finger_2.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_MovementWaves[] = INCBIN_U32("graphics/battle_anims/sprites/movement_waves.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MovementWaves[] = INCBIN_U32("graphics/battle_anims/sprites/movement_waves.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_ScaryFace[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_ScaryFace[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_EyeSparkle[] = INCBIN_U32("graphics/battle_anims/sprites/eye_sparkle.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_EyeSparkle[] = INCBIN_U32("graphics/battle_anims/sprites/eye_sparkle.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Anger[] = INCBIN_U32("graphics/battle_anims/sprites/anger.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Anger[] = INCBIN_U32("graphics/battle_anims/sprites/anger.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Conversion[] = INCBIN_U32("graphics/battle_anims/sprites/conversion.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Conversion[] = INCBIN_U32("graphics/battle_anims/sprites/conversion.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Angel[] = INCBIN_U32("graphics/battle_anims/sprites/angel.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Angel[] = INCBIN_U32("graphics/battle_anims/sprites/angel.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Devil[] = INCBIN_U32("graphics/battle_anims/sprites/devil.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Devil[] = INCBIN_U32("graphics/battle_anims/sprites/devil.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Swipe[] = INCBIN_U32("graphics/battle_anims/sprites/swipe.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Swipe[] = INCBIN_U32("graphics/battle_anims/sprites/swipe.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Roots[] = INCBIN_U32("graphics/battle_anims/sprites/roots.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Roots[] = INCBIN_U32("graphics/battle_anims/sprites/roots.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ItemBag[] = INCBIN_U32("graphics/battle_anims/sprites/item_bag.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ItemBag[] = INCBIN_U32("graphics/battle_anims/sprites/item_bag.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_TriAttackTriangle[] = INCBIN_U32("graphics/battle_anims/sprites/tri_attack_triangle.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_TriAttackTriangle[] = INCBIN_U32("graphics/battle_anims/sprites/tri_attack_triangle.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_LetterZ[] = INCBIN_U32("graphics/battle_anims/sprites/letter_z.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_LetterZ[] = INCBIN_U32("graphics/battle_anims/sprites/letter_z.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Impact[] = INCBIN_U32("graphics/battle_anims/backgrounds/impact.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Impact[] = INCBIN_U32("graphics/battle_anims/backgrounds/impact.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_ImpactOpponent[] = INCBIN_U32("graphics/battle_anims/backgrounds/impact_opponent.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_ImpactPlayer[] = INCBIN_U32("graphics/battle_anims/backgrounds/impact_player.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_ImpactContests[] = INCBIN_U32("graphics/battle_anims/backgrounds/impact_contests.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_JaggedMusicNote[] = INCBIN_U32("graphics/battle_anims/sprites/jagged_music_note.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_JaggedMusicNote[] = INCBIN_U32("graphics/battle_anims/sprites/jagged_music_note.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Spotlight[] = INCBIN_U32("graphics/battle_anims/sprites/spotlight.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Pokeball[] = INCBIN_U32("graphics/battle_anims/sprites/pokeball.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Pokeball[] = INCBIN_U32("graphics/battle_anims/sprites/pokeball.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_RapidSpin[] = INCBIN_U32("graphics/battle_anims/sprites/rapid_spin.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RapidSpin[] = INCBIN_U32("graphics/battle_anims/sprites/rapid_spin.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_MilkBottle[] = INCBIN_U32("graphics/battle_anims/sprites/milk_bottle.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MilkBottle[] = INCBIN_U32("graphics/battle_anims/sprites/milk_bottle.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_WispFire[] = INCBIN_U32("graphics/battle_anims/sprites/wisp_fire.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_WispOrb[] = INCBIN_U32("graphics/battle_anims/sprites/wisp_orb.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_WispOrb[] = INCBIN_U32("graphics/battle_anims/sprites/wisp_orb.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GoldStars[] = INCBIN_U32("graphics/battle_anims/sprites/gold_stars.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GoldStars[] = INCBIN_U32("graphics/battle_anims/sprites/gold_stars.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_EclipsingOrb[] = INCBIN_U32("graphics/battle_anims/sprites/eclipsing_orb.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_EclipsingOrb[] = INCBIN_U32("graphics/battle_anims/sprites/eclipsing_orb.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PinkPetal[] = INCBIN_U32("graphics/battle_anims/sprites/pink_petal.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PinkPetal[] = INCBIN_U32("graphics/battle_anims/sprites/pink_petal.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GrayOrb[] = INCBIN_U32("graphics/battle_anims/sprites/gray_orb.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GrayOrb[] = INCBIN_U32("graphics/battle_anims/sprites/gray_orb.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_BlueOrb[] = INCBIN_U32("graphics/battle_anims/sprites/blue_orb.pal.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RedOrb2[] = INCBIN_U32("graphics/battle_anims/sprites/red_orb_2.pal.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Drill[] = INCBIN_U32("graphics/battle_anims/backgrounds/drill.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Drill[] = INCBIN_U32("graphics/battle_anims/backgrounds/drill.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Sky[] = INCBIN_U32("graphics/battle_anims/backgrounds/sky.pal.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Drill[] = INCBIN_U32("graphics/battle_anims/backgrounds/drill.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_DrillContests[] = INCBIN_U32("graphics/battle_anims/backgrounds/drill_contests.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Aurora[] = INCBIN_U32("graphics/battle_anims/backgrounds/aurora.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Aurora[] = INCBIN_U32("graphics/battle_anims/backgrounds/aurora.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Aurora[] = INCBIN_U32("graphics/battle_anims/backgrounds/aurora.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_HighspeedOpponent[] = INCBIN_U32("graphics/battle_anims/backgrounds/highspeed_opponent.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Highspeed[] = INCBIN_U32("graphics/battle_anims/backgrounds/highspeed.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Bug[] = INCBIN_U32("graphics/battle_anims/backgrounds/bug.pal.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Highspeed[] = INCBIN_U32("graphics/battle_anims/backgrounds/highspeed.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_HighspeedPlayer[] = INCBIN_U32("graphics/battle_anims/backgrounds/highspeed_player.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskImage_LightBeam[] = INCBIN_U32("graphics/battle_anims/masks/light_beam.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskPalette_LightBeam[] = INCBIN_U32("graphics/battle_anims/masks/light_beam.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskTilemap_LightBeam[] = INCBIN_U32("graphics/battle_anims/masks/light_beam.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_GuillotineOpponent[] = INCBIN_U32("graphics/battle_anims/backgrounds/guillotine_opponent.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_GuillotinePlayer[] = INCBIN_U32("graphics/battle_anims/backgrounds/guillotine_player.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_GuillotineContests[] = INCBIN_U32("graphics/battle_anims/backgrounds/guillotine_contests.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Guillotine[] = INCBIN_U32("graphics/battle_anims/backgrounds/guillotine.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Guillotine[] = INCBIN_U32("graphics/battle_anims/backgrounds/guillotine.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Thunder[] = INCBIN_U32("graphics/battle_anims/backgrounds/thunder.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Thunder[] = INCBIN_U32("graphics/battle_anims/backgrounds/thunder.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Thunder[] = INCBIN_U32("graphics/battle_anims/backgrounds/thunder.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PainSplit[] = INCBIN_U32("graphics/battle_anims/sprites/pain_split.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PainSplit[] = INCBIN_U32("graphics/battle_anims/sprites/pain_split.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_HandsAndFeet[] = INCBIN_U32("graphics/battle_anims/sprites/hands_and_feet.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_HandsAndFeet[] = INCBIN_U32("graphics/battle_anims/sprites/hands_and_feet.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Confetti[] = INCBIN_U32("graphics/battle_anims/sprites/confetti.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Confetti[] = INCBIN_U32("graphics/battle_anims/sprites/confetti.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gSubstituteDollPal[] = INCBIN_U32("graphics/battle_anims/sprites/substitute.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gSubstituteDollFrontGfx[] = INCBIN_U32("graphics/battle_anims/sprites/substitute.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gSubstituteDollBackGfx[] = INCBIN_U32("graphics/battle_anims/sprites/substitute_back.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GreenStar[] = INCBIN_U32("graphics/battle_anims/sprites/green_star.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GreenStar[] = INCBIN_U32("graphics/battle_anims/sprites/green_star.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gConfetti_Gfx[] = INCBIN_U32("graphics/misc/confetti.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gConfetti_Pal[] = INCBIN_U32("graphics/misc/confetti.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PinkCloud[] = INCBIN_U32("graphics/battle_anims/sprites/pink_cloud.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PinkCloud[] = INCBIN_U32("graphics/battle_anims/sprites/pink_cloud.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SweatDrop[] = INCBIN_U32("graphics/battle_anims/sprites/sweat_drop.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_SweatDrop[] = INCBIN_U32("graphics/battle_anims/sprites/sweat_drop.png.gbapal.lz");

#undef BATTLE_ANIM_MASK_AND_BG_GFX

#define BATTLE_ANIM_STAT_CHANGE_GFX __attribute__((section(".rodata.battle_anim_stat_change_graphics")))

BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Gfx[] = INCBIN_U32("graphics/battle_anims/stat_change/tiles.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Increase_Tilemap[] = INCBIN_U32("graphics/battle_anims/stat_change/increase.bin.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Decrease_Tilemap[] = INCBIN_U32("graphics/battle_anims/stat_change/decrease.bin.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Defense_Pal[] = INCBIN_U32("graphics/battle_anims/stat_change/defense.pal.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Attack_Pal[] = INCBIN_U32("graphics/battle_anims/stat_change/attack.pal.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Accuracy_Pal[] = INCBIN_U32("graphics/battle_anims/stat_change/accuracy.pal.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Speed_Pal[] = INCBIN_U32("graphics/battle_anims/stat_change/speed.pal.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Multiple_Pal[] = INCBIN_U32("graphics/battle_anims/stat_change/multiple.pal.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Evasion_Pal[] = INCBIN_U32("graphics/battle_anims/stat_change/evasion.pal.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_SpAttack_Pal[] = INCBIN_U32("graphics/battle_anims/stat_change/sp_attack.pal.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_SpDefense_Pal[] = INCBIN_U32("graphics/battle_anims/stat_change/sp_defense.pal.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesGfx[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesPal[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesTilemap[] = INCBIN_U32("graphics/battle_anims/masks/cure_bubbles.bin.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_PurpleScratch[] = INCBIN_U32("graphics/battle_anims/sprites/purple_scratch.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_PurpleScratch[] = INCBIN_U32("graphics/battle_anims/sprites/purple_scratch.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_PurpleSwipe[] = INCBIN_U32("graphics/battle_anims/sprites/purple_swipe.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_GuardRing[] = INCBIN_U32("graphics/battle_anims/sprites/guard_ring.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_GuardRing[] = INCBIN_U32("graphics/battle_anims/sprites/guard_ring.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_TagHand[] = INCBIN_U32("graphics/battle_anims/sprites/tag_hand.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_NoiseLine[] = INCBIN_U32("graphics/battle_anims/sprites/noise_line.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 UnusedLevelupAnimationGfx[] = INCBIN_U32("graphics/battle_anims/masks/unused_level_up.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 UnusedLevelupAnimationTilemap[] = INCBIN_U32("graphics/battle_anims/masks/unused_level_up.bin.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_SmallRedEye[] = INCBIN_U32("graphics/battle_anims/sprites/small_red_eye.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_SmallRedEye[] = INCBIN_U32("graphics/battle_anims/sprites/small_red_eye.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_HollowOrb[] = INCBIN_U32("graphics/battle_anims/sprites/hollow_orb.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_HollowOrb[] = INCBIN_U32("graphics/battle_anims/sprites/hollow_orb.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_XSign[] = INCBIN_U32("graphics/battle_anims/sprites/x_sign.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_BluegreenOrb[] = INCBIN_U32("graphics/battle_anims/sprites/bluegreen_orb.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_BluegreenOrb[] = INCBIN_U32("graphics/battle_anims/sprites/bluegreen_orb.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_PawPrint[] = INCBIN_U32("graphics/battle_anims/sprites/paw_print.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_PawPrint[] = INCBIN_U32("graphics/battle_anims/sprites/paw_print.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_PurpleFlame[] = INCBIN_U32("graphics/battle_anims/sprites/purple_flame.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_PurpleFlame[] = INCBIN_U32("graphics/battle_anims/sprites/purple_flame.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_RedBall[] = INCBIN_U32("graphics/battle_anims/sprites/red_ball.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_RedBall[] = INCBIN_U32("graphics/battle_anims/sprites/red_ball.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_SmellingsaltEffect[] = INCBIN_U32("graphics/battle_anims/sprites/smellingsalt_effect.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_SmellingsaltEffect[] = INCBIN_U32("graphics/battle_anims/sprites/smellingsalt_effect.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_MagnifyingGlass[] = INCBIN_U32("graphics/battle_anims/sprites/magnifying_glass.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_MagnifyingGlass[] = INCBIN_U32("graphics/battle_anims/sprites/magnifying_glass.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_Meteor[] = INCBIN_U32("graphics/battle_anims/sprites/meteor.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_Meteor[] = INCBIN_U32("graphics/battle_anims/sprites/meteor.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_FlatRock[] = INCBIN_U32("graphics/battle_anims/sprites/flat_rock.png.4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_FlatRock[] = INCBIN_U32("graphics/battle_anims/sprites/flat_rock.png.gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimUnusedPal_Unknown2[] = INCBIN_U32("graphics/battle_anims/unused/unknown_2.pal.gbapal.lz");

#undef BATTLE_ANIM_STAT_CHANGE_GFX

#define POKEMON_GRAPHICS_PREFIX __attribute__((section(".rodata.pokemon_graphics_prefix")))

#include "data/graphics/pokemon.h"

#undef POKEMON_GRAPHICS_PREFIX

#define SUMMARY_EFFECT_DATA __attribute__((section(".rodata.summary_screen_effect_data")))

SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Battle_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_battle.bin");
SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Contest_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_contest.bin");
SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Cancel_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_cancel.bin");

#define POKENAV_MAIN_GFX __attribute__((section(".rodata.pokenav_main_graphics")))

POKENAV_MAIN_GFX const u16 gPokenavHeader_Pal[] = INCBIN_U16("graphics/pokenav/header.gbapal");
POKENAV_MAIN_GFX const u32 gPokenavHeader_Gfx[] = INCBIN_U32("graphics/pokenav/header.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavHeader_Tilemap[] = INCBIN_U32("graphics/pokenav/header.bin.lz");
POKENAV_MAIN_GFX const u16 sSpinningPokenav_Pal[] = INCBIN_U16("graphics/pokenav/nav_icon.gbapal");
POKENAV_MAIN_GFX const u32 sSpinningPokenav_Gfx[] = INCBIN_U32("graphics/pokenav/nav_icon.4bpp.lz");
POKENAV_MAIN_GFX const u16 gPokenavLeftHeader_Pal[] = INCBIN_U16("graphics/pokenav/left_headers/palette.gbapal");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderMainMenu_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/main_menu.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderMatchCall_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/match_call.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderRibbons_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/ribbons.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderCondition_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/condition.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderHoennMap_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/hoenn_map.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderParty_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/party.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderSearch_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/search.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderCool_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/cool.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderBeauty_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/beauty.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderCute_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/cute.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderSmart_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/smart.4bpp.lz");
POKENAV_MAIN_GFX const u32 gPokenavLeftHeaderTough_Gfx[] = INCBIN_U32("graphics/pokenav/left_headers/tough.4bpp.lz");

// JP-only unused graphics retained in the original ROM. No pointers to these
// resources exist anywhere in the ROM, so their original purpose is unknown.
#define UNUSED_JP_MENU_SPECIALIZED_PREFIX __attribute__((section(".rodata.unused_jp_menu_specialized_prefix")))
#define UNUSED_JP_MENU_SPECIALIZED_MIDDLE __attribute__((section(".rodata.unused_jp_menu_specialized_middle")))

UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal01[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_01.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles01[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_01.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal02[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_02.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles02[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_02.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal03[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_03.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles03[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_03.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal04[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_04.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles04[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_04.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u16 sUnusedJpMenuSpecializedPal05[] = INCBIN_U16("graphics/unused/jp/menu_specialized/palette_05.gbapal");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles05[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_05.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles06[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_06.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles07[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_07.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles08[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_08.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles09[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_09.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles10[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_10.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_PREFIX static const u32 sUnusedJpMenuSpecializedTiles11[] = INCBIN_U32("graphics/unused/jp/menu_specialized/tiles_11.4bpp.lz");
UNUSED_JP_MENU_SPECIALIZED_MIDDLE static const u8 sUnusedJpMenuSpecializedSpriteData[] = INCBIN_U8("graphics/unused/jp/menu_specialized/sprite_data.bin");


// Rayquaza scene 1 (RAY_ANIM_DUO_FIGHT / RAY_ANIM_DUO_FIGHT_PRE)
#define RAYQUAZA_SCENE_1_GFX __attribute__((section(".rodata.rayquaza_scene_1_graphics")))

RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Groudon_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon.4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_GroudonShoulder_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon_shoulder.4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_GroudonClaw_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon_claw.4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Kyogre_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre.4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_KyogrePectoralFin_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre_pectoral_fin.4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_KyogreDorsalFin_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre_dorsal_fin.4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Groudon_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/groudon.gbapal.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Kyogre_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/kyogre.gbapal.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds.4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds.gbapal.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds1_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds1.bin.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds2_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_1/clouds2.bin.lz");
RAYQUAZA_SCENE_1_GFX const u8 gRaySceneDuoFight_Clouds3_Tilemap[] = INCBIN_U8("graphics/rayquaza_scene/scene_1/clouds3.bin.lz");
static const u8 sRaySceneDuoFightCloudsPadding[3] RAYQUAZA_SCENE_1_GFX __attribute__((used)) = {0, 0, 0};

#undef RAYQUAZA_SCENE_1_GFX


// Rayquaza scene 2 smoke (RAY_ANIM_TAKES_FLIGHT)
#define RAYQUAZA_SCENE_2_SMOKE_GFX __attribute__((section(".rodata.rayquaza_scene_2_smoke_graphics")))

RAYQUAZA_SCENE_2_SMOKE_GFX const u32 gRaySceneTakesFlight_Smoke_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/smoke.4bpp.lz");
RAYQUAZA_SCENE_2_SMOKE_GFX const u32 gRaySceneTakesFlight_Smoke_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/smoke.gbapal.lz");

#undef RAYQUAZA_SCENE_2_SMOKE_GFX

#define RAYQUAZA_SCENE_2_BG_GFX __attribute__((section(".rodata.rayquaza_scene_2_bg_graphics")))

RAYQUAZA_SCENE_2_BG_GFX const u32 gRaySceneTakesFlight_Bg_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/bg.4bpp.lz");

#undef RAYQUAZA_SCENE_2_BG_GFX

// Rayquaza scene 2 shared palette and scene 3 sprites (RAY_ANIM_DESCENDS)
#define RAYQUAZA_SCENE_DESCENDS_SHARED_PAL __attribute__((section(".rodata.rayquaza_scene_descends_shared_pal")))
#define RAYQUAZA_SCENE_2_REMAINING_GFX __attribute__((section(".rodata.rayquaza_scene_2_remaining_graphics")))
#define RAYQUAZA_SCENE_3_SPRITE_GFX __attribute__((section(".rodata.rayquaza_scene_3_sprite_graphics")))
#define RAYQUAZA_SCENE_3_BG_GFX __attribute__((section(".rodata.rayquaza_scene_3_bg_graphics")))

RAYQUAZA_SCENE_DESCENDS_SHARED_PAL const u32 gRaySceneTakesFlight_Rayquaza_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.gbapal.lz");
RAYQUAZA_SCENE_2_REMAINING_GFX const u32 gRaySceneTakesFlight_Bg_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/bg.bin.lz");
RAYQUAZA_SCENE_2_REMAINING_GFX const u32 gRaySceneTakesFlight_Rayquaza_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.8bpp.lz");
RAYQUAZA_SCENE_2_REMAINING_GFX const u32 gRaySceneTakesFlight_Rayquaza_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.bin.lz");
RAYQUAZA_SCENE_3_SPRITE_GFX const u32 gRaySceneDescends_Rayquaza_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/rayquaza.4bpp.lz");
RAYQUAZA_SCENE_3_SPRITE_GFX const u32 gRaySceneDescends_RayquazaTail_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/rayquaza_tail.4bpp.lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Bg_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.4bpp.lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Light_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/light.4bpp.lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Bg_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.gbapal.lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Bg_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/bg.bin.lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Light_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/light.bin.lz");

#undef RAYQUAZA_SCENE_DESCENDS_SHARED_PAL
#undef RAYQUAZA_SCENE_2_REMAINING_GFX
#undef RAYQUAZA_SCENE_3_SPRITE_GFX
#undef RAYQUAZA_SCENE_3_BG_GFX


// Rayquaza scene 4 (RAY_ANIM_CHARGES) and scene 5 (RAY_ANIM_CHASES_AWAY).
// Scene 4's compressed palette is 81 bytes followed by three ROM padding
// bytes. Scene 5 ends on an unaligned 105-byte compressed palette, so both
// use byte arrays where preserving the exact boundary matters.
#define RAYQUAZA_SCENE_4_GFX __attribute__((section(".rodata.rayquaza_scene_4_graphics")))
#define RAYQUAZA_SCENE_5_GFX __attribute__((section(".rodata.rayquaza_scene_5_graphics"), aligned(1)))

RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Bg_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/bg.4bpp.lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Bg_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/bg.bin.lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Streaks_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/streaks.4bpp.lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Streaks_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/streaks.bin.lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Rayquaza_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/rayquaza.4bpp.lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Rayquaza_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/rayquaza.bin.lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Orbs_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_4/orbs.bin.lz");
RAYQUAZA_SCENE_4_GFX const u8 gRaySceneCharges_Bg_Pal[] = INCBIN_U8("graphics/rayquaza_scene/scene_4/bg.gbapal.lz");
static const u8 sRaySceneChargesBgPalPadding[3] RAYQUAZA_SCENE_4_GFX __attribute__((used)) = {0, 0, 0};

RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Groudon_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon.4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_GroudonTail_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon_tail.4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Kyogre_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre.4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Rayquaza_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza.4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_RayquazaTail_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza_tail.4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_KyogreSplash_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Groudon_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/groudon.gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Kyogre_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre.gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Rayquaza_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/rayquaza.gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_KyogreSplash_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Light_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/light.4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Ring_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/ring.8bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Light_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/light.bin.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Bg_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/bg.bin.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Ring_Tilemap[] = INCBIN_U32("graphics/rayquaza_scene/scene_5/ring.bin.lz");
RAYQUAZA_SCENE_5_GFX const u8 gRaySceneChasesAway_Bg_Pal[] = INCBIN_U8("graphics/rayquaza_scene/scene_5/bg.gbapal.lz");

#undef RAYQUAZA_SCENE_4_GFX
#undef RAYQUAZA_SCENE_5_GFX

#define CABLE_CAR_BG_PALETTE __attribute__((section(".rodata.cable_car_bg_palette")))

CABLE_CAR_BG_PALETTE const u16 gCableCarBg_Pal[] =
{
    0x0000, 0x5DBC, 0x5DBC, 0x5DBC, 0x5DBC, 0x5DBC, 0x5DBC, 0x479F,
    0x3F3D, 0x3AFB, 0x36B9, 0x3277, 0x2E36, 0x5DBC, 0x5DBC, 0x5DBC,
    0x0000, 0x4BF7, 0x3373, 0x2710, 0x1A8D, 0x0DCA, 0x0147, 0x5DBC,
    0x5DBC, 0x5DBC, 0x5DBC, 0x5DBC, 0x5DBC, 0x5DBC, 0x5DBC, 0x5DBC,
    0x0000, 0x7FBA, 0x7F97, 0x7F74, 0x7F51, 0x7F2E, 0x7F2C, 0x6F38,
    0x62F7, 0x5296, 0x4213, 0x2D70, 0x210F, 0x5DBC, 0x5DBC, 0x5DBC,
    0x0000, 0x7B38, 0x76F5, 0x76B3, 0x7270, 0x722E, 0x71EC, 0x3528,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

#undef CABLE_CAR_BG_PALETTE

#define CABLE_CAR_BG_GFX __attribute__((section(".rodata.cable_car_bg_gfx"), aligned(1)))

CABLE_CAR_BG_GFX const u8 gCableCarBg_Gfx[] = INCBIN_U8("graphics/cable_car/bg.4bpp.lz");

#undef CABLE_CAR_BG_GFX

#define CABLE_CAR_SPRITE_PALETTE __attribute__((section(".rodata.cable_car_sprite_palette")))

CABLE_CAR_SPRITE_PALETTE const u16 gCableCar_Pal[] =
{
    0x0000, 0x7FFF, 0x6F74, 0x462C, 0x5AD1, 0x4610, 0x3D8C, 0x3528,
    0x2CC5, 0x7B31, 0x76AC, 0x4BFF, 0x2B5D, 0x0ABA, 0x01B6, 0x0111,
};

#undef CABLE_CAR_SPRITE_PALETTE

#define CABLE_CAR_SPRITE_GFX __attribute__((section(".rodata.cable_car_sprite_gfx"), aligned(1)))

CABLE_CAR_SPRITE_GFX const u8 gCableCar_Gfx[] = INCBIN_U8("graphics/cable_car/cable_car.4bpp.lz");

#undef CABLE_CAR_SPRITE_GFX

#define CABLE_CAR_DOOR_GFX __attribute__((section(".rodata.cable_car_door_gfx")))

CABLE_CAR_DOOR_GFX const u32 gCableCarDoor_Gfx[] = INCBIN_U32("graphics/cable_car/door.4bpp.lz");

#undef CABLE_CAR_DOOR_GFX

#define CABLE_CAR_CABLE_GFX __attribute__((section(".rodata.cable_car_cable_gfx")))

CABLE_CAR_CABLE_GFX const u32 gCableCarCable_Gfx[] = INCBIN_U32("graphics/cable_car/cable.4bpp.lz");

#undef CABLE_CAR_CABLE_GFX

// Naming Screen assets retain the JP ROM's physical order, which differs from
// the semantic declaration order in the US source.
#define NAMING_SCREEN_JP_SPRITE_RESOURCES __attribute__((section(".rodata.graphics_naming_screen_jp_sprite_resources"), aligned(1)))

NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenBackButton_Gfx[] = INCBIN_U32("graphics/naming_screen/back_button.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenInputArrow_Gfx[] = INCBIN_U32("graphics/naming_screen/input_arrow.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenOKButton_Gfx[] = INCBIN_U32("graphics/naming_screen/ok_button.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenUnderscore_Gfx[] = INCBIN_U32("graphics/naming_screen/underscore.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenPageSwapFrame_Gfx[] = INCBIN_U32("graphics/naming_screen/page_swap_frame.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenPageSwapButton_Gfx[] = INCBIN_U32("graphics/naming_screen/page_swap_button.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenPageSwapUpper_Gfx[] = INCBIN_U32("graphics/naming_screen/page_swap_upper.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenPageSwapLower_Gfx[] = INCBIN_U32("graphics/naming_screen/page_swap_lower.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenPageSwapOthers_Gfx[] = INCBIN_U32("graphics/naming_screen/page_swap_others.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenCursor_Gfx[] = INCBIN_U32("graphics/naming_screen/cursor.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenCursorSquished_Gfx[] = INCBIN_U32("graphics/naming_screen/cursor_squished.4bpp");
NAMING_SCREEN_JP_SPRITE_RESOURCES const u32 gNamingScreenCursorFilled_Gfx[] = INCBIN_U32("graphics/naming_screen/cursor_filled.4bpp");

#undef NAMING_SCREEN_JP_SPRITE_RESOURCES

// JP ROM has unreferenced zero padding between the cursor tiles and PC icons.
#define NAMING_SCREEN_JP_SPRITE_PADDING __attribute__((section(".rodata.graphics_naming_screen_jp_sprite_padding"), aligned(1), used))

NAMING_SCREEN_JP_SPRITE_PADDING static const u8 sNamingScreenSpritePadding[0x20] = {0};

#undef NAMING_SCREEN_JP_SPRITE_PADDING

#define NAMING_SCREEN_JP_PC_ICONS __attribute__((section(".rodata.graphics_naming_screen_jp_pc_icons"), aligned(1)))

NAMING_SCREEN_JP_PC_ICONS const u8 gNamingScreenPCIconOff_Gfx[] = INCBIN_U8("graphics/naming_screen/pc_icon_off.4bpp");
NAMING_SCREEN_JP_PC_ICONS const u8 gNamingScreenPCIconOn_Gfx[] = INCBIN_U8("graphics/naming_screen/pc_icon_on.4bpp");

#undef NAMING_SCREEN_JP_PC_ICONS

#define NAMING_SCREEN_JP_PALETTES __attribute__((section(".rodata.graphics_naming_screen_jp_palettes"), aligned(1)))

NAMING_SCREEN_JP_PALETTES const u16 gNamingScreenKeyboard_Pal[] = INCBIN_U16("graphics/naming_screen/keyboard.gbapal");
NAMING_SCREEN_JP_PALETTES const u16 gNamingScreenRival_Pal[] = INCBIN_U16("graphics/naming_screen/rival.gbapal");

#undef NAMING_SCREEN_JP_PALETTES

#define NAMING_SCREEN_JP_RESOURCES __attribute__((section(".rodata.graphics_naming_screen_jp_resources"), aligned(1)))

NAMING_SCREEN_JP_RESOURCES const u16 gNamingScreenMenu_Pal[6][16] = INCBIN_U16("graphics/naming_screen/menu.gbapal");
NAMING_SCREEN_JP_RESOURCES const u32 gNamingScreenMenu_Gfx[] = INCBIN_U32("graphics/naming_screen/menu.4bpp.lz");
NAMING_SCREEN_JP_RESOURCES const u32 gNamingScreenBackground_Tilemap[] = INCBIN_U32("graphics/naming_screen/background.bin.lz");
NAMING_SCREEN_JP_RESOURCES const u32 gNamingScreenKeyboardUpper_Tilemap[] = INCBIN_U32("graphics/naming_screen/keyboard_upper.bin.lz");
NAMING_SCREEN_JP_RESOURCES const u32 gNamingScreenKeyboardLower_Tilemap[] = INCBIN_U32("graphics/naming_screen/keyboard_lower.bin.lz");
NAMING_SCREEN_JP_RESOURCES const u32 gNamingScreenKeyboardSymbols_Tilemap[] = INCBIN_U32("graphics/naming_screen/keyboard_symbols.bin.lz");

#undef NAMING_SCREEN_JP_RESOURCES

// These resources are logically owned by text_window.c. They are emitted
// here only because adding data definitions to that matched code unit changes
// agbcc output; dedicated linker sections preserve their original JP order.
#define MESSAGE_BOX_GFX __attribute__((section(".rodata.message_box_gfx"), aligned(1)))

MESSAGE_BOX_GFX const u8 gMessageBox_Gfx[] = INCBIN_U8("graphics/text_window/message_box_jp.4bpp");

#undef MESSAGE_BOX_GFX

#define TEXT_WINDOW_PALETTES __attribute__((section(".rodata.text_window_palettes"), aligned(1)))
#define TEXT_WINDOW_FRAME_TABLE __attribute__((section(".rodata.text_window_frame_table"), aligned(1)))
#include "data/text_window.h"
#undef TEXT_WINDOW_FRAME_TABLE
#undef TEXT_WINDOW_PALETTES

#define MESSAGE_BOX_PAL __attribute__((section(".rodata.message_box_pal"), aligned(1)))

MESSAGE_BOX_PAL const u16 gMessageBox_Pal[] =
{
    0x532E, 0x7FFF, 0x318C, 0x675A, 0x043C, 0x3AFF, 0x0664, 0x4BD2,
    0x6546, 0x7B14, 0x7FFF, 0x73BC, 0x7FFF, 0x4FE0, 0x5F20, 0x51C9,
};

#undef MESSAGE_BOX_PAL

// These script-command tables remain externally referenced by matched code in
// scrcmd.c/script.c. Emit their typed data here to keep that codegen stable.
#define SCRIPT_COMMAND_NULL_PTR __attribute__((section(".rodata.script_command_null_ptr"), aligned(4)))
#define SCRIPT_COMMAND_CONDITION_TABLE __attribute__((section(".rodata.script_command_condition_table"), aligned(1)))
#define SCRIPT_COMMAND_STRING_VARS __attribute__((section(".rodata.script_command_string_vars"), aligned(4)))
#include "data/scrcmd_data.h"
#undef SCRIPT_COMMAND_STRING_VARS
#undef SCRIPT_COMMAND_CONDITION_TABLE
#undef SCRIPT_COMMAND_NULL_PTR

// JP ROM stores the General tiles before its palettes; retain that physical
// order while keeping the US graphics.c ownership and symbol names.
#define TILESET_GENERAL_DATA __attribute__((section(".rodata.tileset_general_data"), aligned(1)))

TILESET_GENERAL_DATA const u32 gTilesetTiles_General[] = INCBIN_U32("data/tilesets/primary/general/tiles.4bpp.lz");

TILESET_GENERAL_DATA const u16 gTilesetPalettes_General[][16] =
{
    INCBIN_U16("data/tilesets/primary/general/palettes/00.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/01.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/02.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/03.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/04.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/05.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/06.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/07.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/08.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/09.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/10.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/11.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/12.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/13.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/14.gbapal"),
    INCBIN_U16("data/tilesets/primary/general/palettes/15.gbapal"),
};

#undef TILESET_GENERAL_DATA
