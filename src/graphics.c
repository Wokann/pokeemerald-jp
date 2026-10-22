#include "global.h"
#include "text_window.h"
#include "string_util.h"
#include "constants/comparison_operators.h"

#define DECORATION_ICONS_GRAPHICS __attribute__((section(".rodata.decoration_icons"), aligned(4)))
#include "data/graphics/decorations.h"
#undef DECORATION_ICONS_GRAPHICS

#define BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES __attribute__((section(".rodata.battle_anim_shock_and_feather_resources")))

BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES const u32 gBattleAnimSpritePal_Shock3[] = INCGFX_U32("graphics/battle_anims/sprites/shock_3.png", ".gbapal.lz");
BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES const u32 gBattleAnimSpriteGfx_Shock3[] = INCGFX_U32("graphics/battle_anims/sprites/shock_3.png", ".4bpp.lz");
BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES const u32 gBattleAnimSpritePal_WhiteFeather[] = INCGFX_U32("graphics/battle_anims/sprites/white_feather.png", ".gbapal.lz");
BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES const u32 gBattleAnimSpriteGfx_WhiteFeather[] = INCGFX_U32("graphics/battle_anims/sprites/white_feather.png", ".4bpp.lz");
BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES const u32 gBattleAnimSpritePal_Sparkle6[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_6.png", ".gbapal.lz");
BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES const u32 gBattleAnimSpriteGfx_Sparkle6[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_6.png", ".4bpp.lz");

#undef BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES

#define TITLE_SCREEN_PRESS_START_GRAPHICS __attribute__((section(".rodata.title_screen_press_start_graphics"), aligned(1)))

// The localized JP Press Start tile stream is byte-exact source data.
TITLE_SCREEN_PRESS_START_GRAPHICS const u16 gTitleScreenPressStartPal[] = INCBIN_U16("graphics/title_screen/press_start.gbapal");
TITLE_SCREEN_PRESS_START_GRAPHICS const u32 gTitleScreenPressStartGfx[] = INCBIN_U32("graphics/title_screen/press_start.4bpp.lz");

#undef TITLE_SCREEN_PRESS_START_GRAPHICS

#define TITLE_SCREEN_GRAPHICS_BEFORE_TITLE_SCREEN_STATIC_GRAPHICS __attribute__((section(".rodata.title_screen_graphics_before_title_screen_static_graphics"), aligned(1)))

TITLE_SCREEN_GRAPHICS_BEFORE_TITLE_SCREEN_STATIC_GRAPHICS const u32 gTitleScreenPokemonLogoTilemap[] = INCBIN_U32("graphics/title_screen/pokemon_logo.bin.lz");
TITLE_SCREEN_GRAPHICS_BEFORE_TITLE_SCREEN_STATIC_GRAPHICS const u16 gTitleScreenBgPalettes[] = INCBIN_U16("graphics/title_screen/pokemon_logo.gbapal");
TITLE_SCREEN_GRAPHICS_BEFORE_TITLE_SCREEN_STATIC_GRAPHICS const u32 gTitleScreenPokemonLogoGfx[] = INCBIN_U32("graphics/title_screen/pokemon_logo.8bpp.lz");
TITLE_SCREEN_GRAPHICS_BEFORE_TITLE_SCREEN_STATIC_GRAPHICS const u32 gTitleScreenEmeraldVersionGfx[] = INCBIN_U32("graphics/title_screen/emerald_version.8bpp.lz");

#undef TITLE_SCREEN_GRAPHICS_BEFORE_TITLE_SCREEN_STATIC_GRAPHICS

#define TITLE_SCREEN_GRAPHICS_AFTER_TITLE_SCREEN_STATIC_GRAPHICS __attribute__((section(".rodata.title_screen_graphics_after_title_screen_static_graphics"), aligned(1)))

TITLE_SCREEN_GRAPHICS_AFTER_TITLE_SCREEN_STATIC_GRAPHICS const u32 gTitleScreenCloudsTilemap[] = INCBIN_U32("graphics/title_screen/clouds.bin.lz");

#undef TITLE_SCREEN_GRAPHICS_AFTER_TITLE_SCREEN_STATIC_GRAPHICS

#define POKEBALL_GRAPHICS __attribute__((section(".rodata.pokeball_graphics"), aligned(1)))
#define POKEBALL_OPEN_GRAPHICS __attribute__((section(".rodata.pokeball_open_graphics"), aligned(1)))
#include "data/graphics/pokeballs.h"
#undef POKEBALL_OPEN_GRAPHICS
#undef POKEBALL_GRAPHICS

#define BATTLE_VS_GRAPHICS __attribute__((section(".rodata.battle_vs_graphics")))

BATTLE_VS_GRAPHICS const u32 gBattleVSFrame_Gfx[] = INCGFX_U32("graphics/battle_transitions/vs_frame.png", ".4bpp.lz", "-num_tiles 16 -Wnum_tiles");
BATTLE_VS_GRAPHICS const u32 gBattleVSFrame_Tilemap[] = INCGFX_U32("graphics/battle_transitions/vs_frame.bin", ".lz");
BATTLE_VS_GRAPHICS const u32 gBattleVSFrame_Pal[] = INCGFX_U32("graphics/battle_transitions/vs_frame.png", ".gbapal.lz");
BATTLE_VS_GRAPHICS const u32 gVsLettersGfx[] = INCGFX_U32("graphics/battle_transitions/vs.png", ".4bpp.lz");

#undef BATTLE_VS_GRAPHICS

#define BATTLE_ENVIRONMENT_GRAPHICS __attribute__((section(".rodata.battle_environment_graphics"), aligned(1)))
#include "data/graphics/battle_environment.h"
#undef BATTLE_ENVIRONMENT_GRAPHICS

#define BATTLE_ANIM_GRAPHICS __attribute__((section(".rodata.battle_anim_graphics"), aligned(1)))

BATTLE_ANIM_GRAPHICS const u32 gBlankGfxCompressed[] = INCGFX_U32("graphics/interface/blank.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Bubble[] = INCGFX_U32("graphics/battle_anims/sprites/bubble.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Bone[] = INCGFX_U32("graphics/battle_anims/sprites/bone.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_AirWave[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Orb[] = INCGFX_U32("graphics/battle_anims/sprites/orb.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Sword[] = INCGFX_U32("graphics/battle_anims/sprites/sword.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Seed[] = INCGFX_U32("graphics/battle_anims/sprites/seed.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_RainDrops[] = INCGFX_U32("graphics/battle_anims/sprites/rain_drops.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Bone[] = INCGFX_U32("graphics/battle_anims/sprites/bone.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_AirWave[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Orb[] = INCGFX_U32("graphics/battle_anims/sprites/orb.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Sword[] = INCGFX_U32("graphics/battle_anims/sprites/sword.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Seed[] = INCGFX_U32("graphics/battle_anims/sprites/seed.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Needle[] = INCGFX_U32("graphics/battle_anims/sprites/needle.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Needle[] = INCGFX_U32("graphics/battle_anims/sprites/needle.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Explosion6[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_6.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Explosion6[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_6.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_PinkOrb[] = INCGFX_U32("graphics/battle_anims/sprites/pink_orb.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_PinkOrb[] = INCGFX_U32("graphics/battle_anims/sprites/pink_orb.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_IceCube[] = INCGFX_U32("graphics/battle_anims/sprites/ice_cube.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_IceCube[] = INCGFX_U32("graphics/battle_anims/sprites/ice_cube.4bpp", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Gust[] = INCGFX_U32("graphics/battle_anims/sprites/gust.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Gust[] = INCGFX_U32("graphics/battle_anims/sprites/gust.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Spark2[] = INCGFX_U32("graphics/battle_anims/sprites/spark_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Spark2[] = INCGFX_U32("graphics/battle_anims/sprites/spark_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Orange[] = INCGFX_U32("graphics/battle_anims/sprites/orange.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Orange[] = INCGFX_U32("graphics/battle_anims/sprites/orange.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Spikes[] = INCGFX_U32("graphics/battle_anims/sprites/spikes.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Spikes[] = INCGFX_U32("graphics/battle_anims/sprites/spikes.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_YellowBall[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_ball.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_YellowBall[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_ball.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_TiedBag[] = INCGFX_U32("graphics/battle_anims/sprites/tied_bag.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_TiedBag[] = INCGFX_U32("graphics/battle_anims/sprites/tied_bag.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BlackSmoke[] = INCGFX_U32("graphics/battle_anims/sprites/black_smoke.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BlackSmoke[] = INCGFX_U32("graphics/battle_anims/sprites/black_smoke.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BlackBall[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BlackBall[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Glass[] = INCGFX_U32("graphics/battle_anims/sprites/glass.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Glass[] = INCGFX_U32("graphics/battle_anims/sprites/glass.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_HornHit[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_HornHit[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BlueShards[] = INCGFX_U32("graphics/battle_anims/sprites/blue_shards.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueShards[] = INCGFX_U32("graphics/battle_anims/sprites/blue_shards.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnusedPal_MusicNotes[] = INCGFX_U32("graphics/battle_anims/unused/music_notes.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnusedGfx_MusicNotes[] = INCGFX_U32("graphics/battle_anims/unused/music_notes.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Hit[] = INCGFX_U32("graphics/battle_anims/sprites/hit.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Hit[] = INCGFX_U32("graphics/battle_anims/sprites/hit.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Hit2[] = INCGFX_U32("graphics/battle_anims/sprites/hit_2.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_WavingHand[] = INCGFX_U32("graphics/battle_anims/sprites/waving_hand.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_WavingHand[] = INCGFX_U32("graphics/battle_anims/sprites/waving_hand.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_ClosingEye[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_ClosingEye[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueStar[] = INCGFX_U32("graphics/battle_anims/sprites/blue_star.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BlueStar[] = INCGFX_U32("graphics/battle_anims/sprites/blue_star.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BubbleBurst[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BubbleBurst[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_HitDuplicate[] = INCGFX_U32("graphics/battle_anims/sprites/hit_duplicate.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_HitDuplicate[] = INCGFX_U32("graphics/battle_anims/sprites/hit_duplicate.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Leer[] = INCGFX_U32("graphics/battle_anims/sprites/leer.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Leer[] = INCGFX_U32("graphics/battle_anims/sprites/leer.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BlueBurst[] = INCGFX_U32("graphics/battle_anims/sprites/blue_burst.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueBurst[] = INCGFX_U32("graphics/battle_anims/sprites/blue_burst.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_SmallEmber[] = INCGFX_U32("graphics/battle_anims/sprites/small_ember.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_SmallEmber[] = INCGFX_U32("graphics/battle_anims/sprites/small_ember.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_GraySmoke[] = INCGFX_U32("graphics/battle_anims/sprites/gray_smoke.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_GraySmoke[] = INCGFX_U32("graphics/battle_anims/sprites/gray_smoke.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Fire[] = INCGFX_U32("graphics/battle_anims/sprites/fire.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Fire[] = INCGFX_U32("graphics/battle_anims/sprites/fire.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_SpinningFire[] = INCGFX_U32("graphics/battle_anims/sprites/spinning_fire.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_FirePlume[] = INCGFX_U32("graphics/battle_anims/sprites/fire_plume.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Lightning2[] = INCGFX_U32("graphics/battle_anims/sprites/lightning_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Lightning2[] = INCGFX_U32("graphics/battle_anims/sprites/lightning_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Lightning[] = INCGFX_U32("graphics/battle_anims/sprites/lightning.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_SpinningBall[] = INCGFX_U32("graphics/battle_anims/unused/spinning_ball.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_SpinningBall[] = INCGFX_U32("graphics/battle_anims/unused/spinning_ball.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_SpinningBall2[] = INCGFX_U32("graphics/battle_anims/unused/spinning_ball_2.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gOldBattleInterfaceGfx[] = INCGFX_U32("graphics/unused/obi1.4bpp", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gOldBattleInterfacePal_1_2_3[] = INCGFX_U32("graphics/unused/obi_palpak1.gbapal", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gOldBattleInterfacePal4[] = INCGFX_U32("graphics/unused/old_pal4.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gOldBattleInterfacePal_5_6_7[] = INCGFX_U32("graphics/unused/obi_palpak3.gbapal", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gOldBattleInterfaceGfx2[] = INCGFX_U32("graphics/unused/obi2.4bpp", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gOldBattleInterfaceTilemap[] = INCGFX_U32("graphics/unused/old_battle_interface_tilemap.bin", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_ClawSlash2[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_ClawSlash[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_ClawSlash2[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_ClawSlash[] = INCGFX_U32("graphics/battle_anims/sprites/claw_slash.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Scratch3[] = INCGFX_U32("graphics/battle_anims/sprites/scratch_3.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Scratch2[] = INCGFX_U32("graphics/battle_anims/sprites/scratch_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gUnusedHpBar_Gfx[] = INCGFX_U32("graphics/battle_interface/hpbar_unused.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BubbleBurst2[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BubbleBurst2[] = INCGFX_U32("graphics/battle_anims/sprites/bubble_burst_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_IceChunk[] = INCGFX_U32("graphics/battle_anims/sprites/ice_chunk.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_IceChunk[] = INCGFX_U32("graphics/battle_anims/sprites/ice_chunk.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Glass2[] = INCGFX_U32("graphics/battle_anims/sprites/glass_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Glass2[] = INCGFX_U32("graphics/battle_anims/sprites/glass_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_PinkHeart2[] = INCGFX_U32("graphics/battle_anims/sprites/pink_heart_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_PinkHeart2[] = INCGFX_U32("graphics/battle_anims/sprites/pink_heart_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleInterfaceGfx_UnusedWindow1[] = INCGFX_U32("graphics/battle_interface/unused_window.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleInterfacePal_UnusedWindow1[] = INCGFX_U32("graphics/battle_interface/unused_window.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleInterfaceGfx_BattleBar[] = INCGFX_U32("graphics/battle_interface/battle_bar.4bpp", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_SapDrip[] = INCGFX_U32("graphics/battle_anims/sprites/sap_drip.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_SapDrip[] = INCGFX_U32("graphics/battle_anims/sprites/sap_drip.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_SapDrip2[] = INCGFX_U32("graphics/battle_anims/sprites/sap_drip_2.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleInterfaceGfx_UnusedWindow2[] = INCGFX_U32("graphics/battle_interface/unused_window2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleInterfaceGfx_UnusedWindow2Bar[] = INCGFX_U32("graphics/battle_interface/unused_window2bar.png", ".4bpp.lz", "-num_tiles 5 -Wnum_tiles");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Sparkle1[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_1.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Sparkle1[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_1.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Sparkle2[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_2.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_HumanoidFoot[] = INCGFX_U32("graphics/battle_anims/sprites/humanoid_foot.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_HumanoidFoot[] = INCGFX_U32("graphics/battle_anims/sprites/humanoid_foot.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_MonsterFoot[] = INCGFX_U32("graphics/battle_anims/sprites/monster_foot.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_HumanoidHand[] = INCGFX_U32("graphics/battle_anims/sprites/humanoid_hand.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_LineSketch[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_LineSketch[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_YellowUnk[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_YellowUnk[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_SlamHit[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_SlamHit[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_RedFist[] = INCGFX_U32("graphics/battle_anims/sprites/red_fist.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Ring[] = INCGFX_U32("graphics/battle_anims/sprites/ring.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Ring[] = INCGFX_U32("graphics/battle_anims/sprites/ring.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Rocks[] = INCGFX_U32("graphics/battle_anims/sprites/rocks.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Rocks[] = INCGFX_U32("graphics/battle_anims/sprites/rocks.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Z[] = INCGFX_U32("graphics/battle_anims/sprites/z.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Z[] = INCGFX_U32("graphics/battle_anims/sprites/z.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_YellowUnk2[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_YellowUnk2[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_unk_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_AirSlash[] = INCGFX_U32("graphics/battle_anims/sprites/air_slash.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_AirSlash[] = INCGFX_U32("graphics/battle_anims/sprites/air_slash.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_SpinningGreenOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/spinning_green_orbs.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_SpinningGreenOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/spinning_green_orbs.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Leaf[] = INCGFX_U32("graphics/battle_anims/sprites/leaf.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Leaf[] = INCGFX_U32("graphics/battle_anims/sprites/leaf.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_MetronomeSmallHand[] = INCGFX_U32("graphics/battle_anims/unused/metronome_hand_small.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Clapping[] = INCGFX_U32("graphics/battle_anims/sprites/clapping.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_PoisonPowder[] = INCGFX_U32("graphics/battle_anims/sprites/poison_powder.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_PoisonPowder[] = INCGFX_U32("graphics/battle_anims/sprites/poison_powder.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BrownTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/brown_triangle.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BrownTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/brown_triangle.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Sparkle3[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_3.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Sparkle3[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_3.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Sparkle4[] = INCGFX_U32("graphics/battle_anims/sprites/sparkle_4.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_MusicNotes[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_MusicNotes[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Duck[] = INCGFX_U32("graphics/battle_anims/sprites/duck.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Duck[] = INCGFX_U32("graphics/battle_anims/sprites/duck.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Alert[] = INCGFX_U32("graphics/battle_anims/sprites/alert.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Alert[] = INCGFX_U32("graphics/battle_anims/sprites/alert.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Shock4[] = INCGFX_U32("graphics/battle_anims/sprites/shock_4.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Shock4[] = INCGFX_U32("graphics/battle_anims/sprites/shock_4.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Shock[] = INCGFX_U32("graphics/battle_anims/sprites/shock.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Bell2[] = INCGFX_U32("graphics/battle_anims/sprites/bell_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Bell2[] = INCGFX_U32("graphics/battle_anims/sprites/bell_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_PinkGlove[] = INCGFX_U32("graphics/battle_anims/sprites/pink_glove.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_PinkGlove[] = INCGFX_U32("graphics/battle_anims/sprites/pink_glove.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u16 gBattleAnimUnused_Unknown1[] = INCBIN_U16("graphics/battle_anims/unused/unknown_1.bin");

BATTLE_ANIM_GRAPHICS const u16 gBattleAnimUnused_Unknown2[] = INCBIN_U16("graphics/battle_anims/unused/unknown_2.bin");

BATTLE_ANIM_GRAPHICS const u16 gBattleAnimUnused_Unknown3[] = INCBIN_U16("graphics/battle_anims/unused/unknown_3.bin");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnusedGfx_LineSketch2[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch_2.png", ".8bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnusedPal_LineSketch2[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch_2.pal", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnusedTilemap_LineSketch2[] = INCGFX_U32("graphics/battle_anims/unused/line_sketch_2.bin", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueLines[] = INCGFX_U32("graphics/battle_anims/sprites/blue_lines.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BlueLines[] = INCGFX_U32("graphics/battle_anims/sprites/blue_lines.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Impact3[] = INCGFX_U32("graphics/battle_anims/sprites/impact_3.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Impact2[] = INCGFX_U32("graphics/battle_anims/sprites/impact_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Reticle[] = INCGFX_U32("graphics/battle_anims/sprites/reticle.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Breath[] = INCGFX_U32("graphics/battle_anims/sprites/breath.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Snowball[] = INCGFX_U32("graphics/battle_anims/sprites/snowball.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Vine[] = INCGFX_U32("graphics/battle_anims/sprites/vine.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Sword2[] = INCGFX_U32("graphics/battle_anims/sprites/sword_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_RedTube[] = INCGFX_U32("graphics/battle_anims/sprites/red_tube.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Amnesia[] = INCGFX_U32("graphics/battle_anims/sprites/amnesia.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_String2[] = INCGFX_U32("graphics/battle_anims/sprites/string_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnused_Unknown4[] = INCGFX_U32("graphics/battle_anims/unused/unknown_4.bin", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Pencil2[] = INCGFX_U32("graphics/battle_anims/sprites/pencil_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Petal[] = INCGFX_U32("graphics/battle_anims/sprites/petal.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BentSpoon[] = INCGFX_U32("graphics/battle_anims/sprites/bent_spoon.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Coin[] = INCGFX_U32("graphics/battle_anims/sprites/coin.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_CrackedEgg[] = INCGFX_U32("graphics/battle_anims/sprites/cracked_egg.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_FreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/fresh_egg.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Impact3[] = INCGFX_U32("graphics/battle_anims/sprites/impact_3.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Impact2[] = INCGFX_U32("graphics/battle_anims/sprites/impact_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Reticle[] = INCGFX_U32("graphics/battle_anims/sprites/reticle.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Breath[] = INCGFX_U32("graphics/battle_anims/sprites/breath.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Snowball[] = INCGFX_U32("graphics/battle_anims/sprites/snowball.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Vine[] = INCGFX_U32("graphics/battle_anims/sprites/vine.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Sword2[] = INCGFX_U32("graphics/battle_anims/sprites/sword_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Clapping[] = INCGFX_U32("graphics/battle_anims/sprites/clapping.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_RedTube[] = INCGFX_U32("graphics/battle_anims/sprites/red_tube.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Amnesia[] = INCGFX_U32("graphics/battle_anims/sprites/amnesia.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_String2[] = INCGFX_U32("graphics/battle_anims/sprites/string_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Pencil2[] = INCGFX_U32("graphics/battle_anims/sprites/pencil_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Petal[] = INCGFX_U32("graphics/battle_anims/sprites/petal.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BentSpoon[] = INCGFX_U32("graphics/battle_anims/sprites/bent_spoon.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Web[] = INCGFX_U32("graphics/battle_anims/sprites/web.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Coin[] = INCGFX_U32("graphics/battle_anims/sprites/coin.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_CrackedEgg[] = INCGFX_U32("graphics/battle_anims/sprites/cracked_egg.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_HatchedEgg[] = INCGFX_U32("graphics/battle_anims/sprites/hatched_egg.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_FreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/fresh_egg.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Fangs[] = INCGFX_U32("graphics/battle_anims/sprites/fangs.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Fangs[] = INCGFX_U32("graphics/battle_anims/sprites/fangs.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Explosion2[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Explosion2[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Explosion3[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_3.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_WaterDroplet[] = INCGFX_U32("graphics/battle_anims/sprites/water_droplet.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_WaterDroplet[] = INCGFX_U32("graphics/battle_anims/sprites/water_droplet.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_WaterDroplet2[] = INCGFX_U32("graphics/battle_anims/sprites/water_droplet_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Seed2[] = INCGFX_U32("graphics/battle_anims/sprites/seed_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Seed2[] = INCGFX_U32("graphics/battle_anims/sprites/seed_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Sprout[] = INCGFX_U32("graphics/battle_anims/sprites/sprout.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_RedWand[] = INCGFX_U32("graphics/battle_anims/sprites/red_wand.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_RedWand[] = INCGFX_U32("graphics/battle_anims/sprites/red_wand.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_PurpleGreenUnk[] = INCGFX_U32("graphics/battle_anims/sprites/purple_green_unk.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_PurpleGreenUnk[] = INCGFX_U32("graphics/battle_anims/sprites/purple_green_unk.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_WaterColumn[] = INCGFX_U32("graphics/battle_anims/sprites/water_column.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_WaterColumn[] = INCGFX_U32("graphics/battle_anims/sprites/water_column.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_MudUnk[] = INCGFX_U32("graphics/battle_anims/sprites/mud_unk.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_MudUnk[] = INCGFX_U32("graphics/battle_anims/sprites/mud_unk.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gUnusedTilemap_BlueFrame[] = INCGFX_U32("graphics/unused/blue_frame.bin", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gUnusedTilemap_RedYellowGreenFrame[] = INCGFX_U32("graphics/unused/redyellowgreen_frame.bin", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gUnusedGfx_ColorFrames[] = INCGFX_U32("graphics/unused/color_frames.png", ".4bpp.lz", "-num_tiles 353 -Wnum_tiles");

BATTLE_ANIM_GRAPHICS const u32 gUnusedPal_ColorFrames[] = INCGFX_U32("graphics/unused/color_frames.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_RainDrops[] = INCGFX_U32("graphics/battle_anims/sprites/rain_drops.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnusedGfx_WaterSplash[] = INCGFX_U32("graphics/battle_anims/unused/water_splash.png", ".8bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnusedTilemap_WaterSplash[] = INCGFX_U32("graphics/battle_anims/unused/water_splash.bin", ".lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimUnusedPal_WaterSplash[] = INCGFX_U32("graphics/battle_anims/unused/water_splash.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gUnusedGfx_BasicFrame[] = INCGFX_U32("graphics/unused/basic_frame.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gUnusedPal_BasicFrame[] = INCGFX_U32("graphics/unused/basic_frame.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gUnusedTilemap_BasicFrame[] = INCGFX_U32("graphics/unused/basic_frame.bin", ".lz");

BATTLE_ANIM_GRAPHICS const u16 gBattleInterface_BallStatusBarPal[] = INCBIN_U16("graphics/battle_interface/ball_status_bar.gbapal");

BATTLE_ANIM_GRAPHICS const u16 gBattleInterface_BallDisplayPal[] = INCBIN_U16("graphics/battle_interface/ball_display.gbapal");

BATTLE_ANIM_GRAPHICS const u8 gHealthboxElementsGfxTable[][32] = INCBIN_U8(
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

BATTLE_ANIM_GRAPHICS const u32 gBattleInterfaceGfx_UnusedWindow3[] = INCGFX_U32("graphics/battle_interface/unused_window3.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleInterfaceGfx_UnusedWindow4[] = INCGFX_U32("graphics/battle_interface/unused_window4.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_FurySwipes[] = INCGFX_U32("graphics/battle_anims/sprites/fury_swipes.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_FurySwipes[] = INCGFX_U32("graphics/battle_anims/sprites/fury_swipes.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Vine2[] = INCGFX_U32("graphics/battle_anims/sprites/vine_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Vine2[] = INCGFX_U32("graphics/battle_anims/sprites/vine_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Teeth[] = INCGFX_U32("graphics/battle_anims/sprites/teeth.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Teeth[] = INCGFX_U32("graphics/battle_anims/sprites/teeth.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Bone2[] = INCGFX_U32("graphics/battle_anims/sprites/bone_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Bone2[] = INCGFX_U32("graphics/battle_anims/sprites/bone_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_WhiteBag[] = INCGFX_U32("graphics/battle_anims/sprites/white_bag.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_WhiteBag[] = INCGFX_U32("graphics/battle_anims/sprites/white_bag.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Unknown[] = INCGFX_U32("graphics/battle_anims/sprites/unknown.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Unknown[] = INCGFX_U32("graphics/battle_anims/sprites/unknown.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_PurpleCoral[] = INCGFX_U32("graphics/battle_anims/sprites/purple_coral.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_PurpleCoral[] = INCGFX_U32("graphics/battle_anims/sprites/purple_coral.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_PurpleDroplet[] = INCGFX_U32("graphics/battle_anims/sprites/purple_droplet.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Shock2[] = INCGFX_U32("graphics/battle_anims/sprites/shock_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Shock2[] = INCGFX_U32("graphics/battle_anims/sprites/shock_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_ClosingEye2[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_ClosingEye2[] = INCGFX_U32("graphics/battle_anims/sprites/closing_eye_2.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_MetalBall[] = INCGFX_U32("graphics/battle_anims/sprites/metal_ball.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_MetalBall[] = INCGFX_U32("graphics/battle_anims/sprites/metal_ball.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_MonsterDoll[] = INCGFX_U32("graphics/battle_anims/sprites/monster_doll.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_MonsterDoll[] = INCGFX_U32("graphics/battle_anims/sprites/monster_doll.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Whirlwind[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Whirlwind[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Whirlwind2[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Explosion4[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_4.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Explosion4[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_4.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Explosion5[] = INCGFX_U32("graphics/battle_anims/sprites/explosion_5.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Tongue[] = INCGFX_U32("graphics/battle_anims/sprites/tongue.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Tongue[] = INCGFX_U32("graphics/battle_anims/sprites/tongue.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Smoke[] = INCGFX_U32("graphics/battle_anims/sprites/smoke.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_Smoke[] = INCGFX_U32("graphics/battle_anims/sprites/smoke.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_Smoke2[] = INCGFX_U32("graphics/battle_anims/sprites/smoke_2.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueFlames[] = INCGFX_U32("graphics/battle_anims/sprites/blue_flames.png", ".4bpp.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpritePal_BlueFlames[] = INCGFX_U32("graphics/battle_anims/sprites/blue_flames.png", ".gbapal.lz");

BATTLE_ANIM_GRAPHICS const u32 gBattleAnimSpriteGfx_BlueFlames2[] = INCGFX_U32("graphics/battle_anims/sprites/blue_flames_2.png", ".4bpp.lz");

#undef BATTLE_ANIM_GRAPHICS


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

#define POKEDEX_GRAPHICS_UNUSED_NOBALL __attribute__((section(".rodata.pokedex_graphics_unused_noball"), aligned(1)))

POKEDEX_GRAPHICS_UNUSED_NOBALL const u32 gUnused_PokedexNoBall[] = INCBIN_U32("graphics/pokedex/noball_unused.png.4bpp.lz");

#undef POKEDEX_GRAPHICS_UNUSED_NOBALL

#define POKEDEX_GRAPHICS_MENU_INTERFACE __attribute__((section(".rodata.pokedex_graphics_menu_interface"), aligned(1)))

POKEDEX_GRAPHICS_MENU_INTERFACE const u32 gPokedexMenu_Gfx[] = INCBIN_U32("graphics/pokedex/menu.4bpp.lz");
POKEDEX_GRAPHICS_MENU_INTERFACE const u32 gPokedexInterface_Gfx[] = INCBIN_U32("graphics/pokedex/interface.4bpp.lz");

#undef POKEDEX_GRAPHICS_MENU_INTERFACE

#define POKEDEX_SEARCH_MENU_GRAPHICS __attribute__((section(".rodata.pokedex_search_menu_graphics"), aligned(1)))

// JP search-menu tiles differ from the English source image; retain the
// byte-exact JP stream while sharing pokeemerald's final resource names.
POKEDEX_SEARCH_MENU_GRAPHICS const u16 gPokedexSearchMenu_Pal[] = INCBIN_U16("graphics/pokedex/search_menu.gbapal");
POKEDEX_SEARCH_MENU_GRAPHICS const u32 gPokedexSearchMenu_Gfx[] = INCBIN_U32("graphics/pokedex/search_menu.4bpp.lz");
POKEDEX_SEARCH_MENU_GRAPHICS const u32 gPokedexSearchMenuNational_Tilemap[] = INCBIN_U32("graphics/pokedex/search_menu_national.bin.lz");
POKEDEX_SEARCH_MENU_GRAPHICS const u32 gPokedexSearchMenuHoenn_Tilemap[] = INCBIN_U32("graphics/pokedex/search_menu_hoenn.bin.lz");

#undef POKEDEX_SEARCH_MENU_GRAPHICS

#define MENU_INFO_GRAPHICS __attribute__((section(".rodata.graphics_menu_info_resources"), aligned(1)))

// JP menu-info graphics retain their localized icon widths and palette data.
MENU_INFO_GRAPHICS const u16 gMenuInfoElements1_Pal[] = INCBIN_U16("graphics/interface/menu_info1.gbapal");
MENU_INFO_GRAPHICS const u16 gMenuInfoElements2_Pal[] = INCBIN_U16("graphics/interface/menu_info2.gbapal");
MENU_INFO_GRAPHICS const u16 gMenuInfoElements3_Pal[] = INCBIN_U16("graphics/interface/menu_info3.gbapal");
MENU_INFO_GRAPHICS const u8 gMenuInfoElements_Gfx[] = INCBIN_U8("graphics/interface/menu_info.4bpp");

#undef MENU_INFO_GRAPHICS

#define BATTLE_FACTORY_MENU_TILES __attribute__((section(".rodata.graphics_battle_factory_menu_tiles"), aligned(1)))

// The JP menu uses two 4bpp palette banks; retain the physical palette stream
// separately while keeping pokeemerald's final resource names and hierarchy.
BATTLE_FACTORY_MENU_TILES const u16 gFrontierFactoryMenu_Gfx[] = INCBIN_U16("graphics/battle_frontier/factory_screen/menu.png.4bpp");
BATTLE_FACTORY_MENU_TILES const u16 gFrontierFactoryMenu_Tilemap[] = INCBIN_U16("graphics/battle_frontier/factory_screen/menu.bin");

#undef BATTLE_FACTORY_MENU_TILES

#define BATTLE_FACTORY_MENU_PAL __attribute__((section(".rodata.graphics_battle_factory_menu_pal"), aligned(1)))

BATTLE_FACTORY_MENU_PAL const u16 gFrontierFactoryMenu_Pal[] = INCBIN_U16("graphics/battle_frontier/factory_screen/menu.pal.gbapal");

#undef BATTLE_FACTORY_MENU_PAL

#define INTRO_COPYRIGHT_GRAPHICS __attribute__((section(".rodata.intro_copyright_graphics")))

INTRO_COPYRIGHT_GRAPHICS const u16 gIntroCopyright_Pal[16] = INCBIN_U16("graphics/intro/copyright.gbapal");
INTRO_COPYRIGHT_GRAPHICS const u32 gIntroCopyright_Gfx[] = INCBIN_U32("graphics/intro/copyright.4bpp.lz");
INTRO_COPYRIGHT_GRAPHICS const u32 gIntroCopyright_Tilemap[] = INCBIN_U32("graphics/intro/copyright.bin.lz");

#undef INTRO_COPYRIGHT_GRAPHICS

#define BATTLE_FRONTIER_GRAPHICS __attribute__((section(".rodata.battle_frontier_graphics")))

BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyTree_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_tree.png", ".4bpp.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyLine_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_line.png", ".4bpp.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyTree_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_tree.bin", ".lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyLineDown_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_line_down_map.bin", ".lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyLineUp_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_line_up_map.bin", ".lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyInfoCard_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card.png", ".4bpp.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyInfoCard_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card_tilemap.bin", ".lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyInfoCardBg_Tilemap[] = INCGFX_U32("graphics/battle_frontier/tourney_info_card_bg.bin", ".lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyTreeButtons_Gfx[] = INCGFX_U32("graphics/battle_frontier/tourney_buttons.png", ".4bpp.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyTree_Pal[] = INCGFX_U32("graphics/battle_frontier/tourney_tree.png", ".gbapal.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyTreeButtons_Pal[] = INCGFX_U32("graphics/battle_frontier/tourney_buttons.pal", ".gbapal.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gDomeTourneyMatchCardBg_Pal[] = INCGFX_U32("graphics/battle_frontier/tourney_match_card_bg.pal", ".gbapal.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gBattleArenaJudgmentSymbolsGfx[] = INCGFX_U32("graphics/battle_frontier/arena_judgment_symbols.png", ".4bpp.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gBattleArenaJudgmentSymbolsPalette[] = INCGFX_U32("graphics/battle_frontier/arena_judgment_symbols.png", ".gbapal.lz");
BATTLE_FRONTIER_GRAPHICS const u32 gBattleWindowTextPalette[] = INCGFX_U32("graphics/battle_interface/text.pal", ".gbapal.lz");
BATTLE_FRONTIER_GRAPHICS const u16 gPPTextPalette[] = INCGFX_U16("graphics/battle_interface/text_pp.pal", ".gbapal");
BATTLE_FRONTIER_GRAPHICS const u16 gTilesetAnims_BattleDomePals0_0[] = INCGFX_U16("graphics/battle_frontier/dome_anim1.pal", ".gbapal");
BATTLE_FRONTIER_GRAPHICS const u16 gTilesetAnims_BattleDomePals0_1[] = INCGFX_U16("graphics/battle_frontier/dome_anim2.pal", ".gbapal");
BATTLE_FRONTIER_GRAPHICS const u16 gTilesetAnims_BattleDomePals0_2[] = INCGFX_U16("graphics/battle_frontier/dome_anim3.pal", ".gbapal");
BATTLE_FRONTIER_GRAPHICS const u16 gTilesetAnims_BattleDomePals0_3[] = INCGFX_U16("graphics/battle_frontier/dome_anim4.pal", ".gbapal");
static BATTLE_FRONTIER_GRAPHICS const u16 sUnused0[] = {0x13F, 0x119, 0x113, 0x10E};
BATTLE_FRONTIER_GRAPHICS const u16 gBattlePyramidFloor_Pal[][16] = INCGFX_U16("graphics/battle_frontier/pyramid_floor.pal", ".gbapal");
BATTLE_FRONTIER_GRAPHICS const u32 gMultiBattleIntroBg_Opponent_Tilemap[] = INCGFX_U32("graphics/battle_frontier/multi_battle_intro_bg_opponent.bin", ".lz");
BATTLE_FRONTIER_GRAPHICS const u32 gMultiBattleIntroBg_Player_Tilemap[] = INCGFX_U32("graphics/battle_frontier/multi_battle_intro_bg_player.bin", ".lz");

#undef BATTLE_FRONTIER_GRAPHICS

#define INTRO_SCENE_GRAPHICS __attribute__((section(".rodata.intro_scene_graphics")))
#include "data/graphics/intro_scene.h"
#undef INTRO_SCENE_GRAPHICS

#define BATTLE_ANIM_SANDSTORM_RESOURCES __attribute__((section(".rodata.battle_anim_sandstorm_resources")))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_SANDSTORM_RESOURCES const u32 gBattleAnimSpriteGfx_FlyingDirt[] = INCGFX_U32("graphics/battle_anims/sprites/flying_dirt.png", ".4bpp.lz");
BATTLE_ANIM_SANDSTORM_RESOURCES const u32 gBattleAnimBgTilemap_Sandstorm[] = INCGFX_U32("graphics/battle_anims/backgrounds/sandstorm_brew.bin", ".lz");
BATTLE_ANIM_SANDSTORM_RESOURCES const u32 gBattleAnimBgImage_Sandstorm[] = INCGFX_U32("graphics/battle_anims/backgrounds/sandstorm_brew.png", ".4bpp.lz");
BATTLE_ANIM_SANDSTORM_RESOURCES const u32 gBattleAnimSpritePal_FlyingDirt[] = INCGFX_U32("graphics/battle_anims/sprites/flying_dirt.png", ".gbapal.lz");

#undef BATTLE_ANIM_SANDSTORM_RESOURCES

#define BATTLE_ANIM_METAL_SOUND_RESOURCES __attribute__((section(".rodata.battle_anim_metal_sound_resources")))

// The JP LZ77 palette stream retains its original two-byte alignment padding.
BATTLE_ANIM_METAL_SOUND_RESOURCES const u32 gBattleAnimSpriteGfx_MetalSoundWaves[] = INCGFX_U32("graphics/battle_anims/sprites/metal_sound_waves.png", ".4bpp.lz");
BATTLE_ANIM_METAL_SOUND_RESOURCES const u32 gBattleAnimSpritePal_MetalSoundWaves[] = INCGFX_U32("graphics/battle_anims/sprites/metal_sound_waves.png", ".gbapal.lz");

#undef BATTLE_ANIM_METAL_SOUND_RESOURCES

#define BATTLE_ANIM_ICE_RESOURCES __attribute__((section(".rodata.battle_anim_ice_resources")))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimBgImage_Ice[] = INCGFX_U32("graphics/battle_anims/backgrounds/ice.png", ".4bpp.lz");
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimBgPalette_Ice[] = INCGFX_U32("graphics/battle_anims/backgrounds/ice.png", ".gbapal.lz");
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimBgTilemap_Ice[] = INCGFX_U32("graphics/battle_anims/backgrounds/ice.bin", ".lz");
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimSpriteGfx_IcicleSpear[] = INCGFX_U32("graphics/battle_anims/sprites/icicle_spear.png", ".4bpp.lz");
BATTLE_ANIM_ICE_RESOURCES const u32 gBattleAnimSpritePal_IcicleSpear[] = INCGFX_U32("graphics/battle_anims/sprites/icicle_spear.png", ".gbapal.lz");

#undef BATTLE_ANIM_ICE_RESOURCES

#define CONTEST_NEXT_TURN_RESOURCES __attribute__((section(".rodata.contest_next_turn_resources")))

// The JP Next Turn banner is 32 pixels wide, unlike the 64-pixel US source asset.
CONTEST_NEXT_TURN_RESOURCES const u32 gContestNextTurnGfx[] = INCGFX_U32("graphics/contest/nextturn.png", ".4bpp.lz");
CONTEST_NEXT_TURN_RESOURCES const u8 gContestNextTurnNumbersGfx[] = INCGFX_U8("graphics/contest/nextturn_numbers.png", ".4bpp");
CONTEST_NEXT_TURN_RESOURCES const u8 gContestNextTurnRandomGfx[] = INCGFX_U8("graphics/contest/nextturn_random.png", ".4bpp");

#undef CONTEST_NEXT_TURN_RESOURCES

#define BATTLE_ANIM_ORB_AND_POWDER_RESOURCES __attribute__((section(".rodata.battle_anim_orb_and_powder_resources")))

BATTLE_ANIM_ORB_AND_POWDER_RESOURCES const u32 gBattleAnimSpriteGfx_GlowyRedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_red_orb.png", ".4bpp.lz");
BATTLE_ANIM_ORB_AND_POWDER_RESOURCES const u32 gBattleAnimSpritePal_GlowyRedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_red_orb.png", ".gbapal.lz");
BATTLE_ANIM_ORB_AND_POWDER_RESOURCES const u32 gBattleAnimSpritePal_GlowyGreenOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_green_orb.pal", ".gbapal.lz");
BATTLE_ANIM_ORB_AND_POWDER_RESOURCES const u32 gBattleAnimSpritePal_SleepPowder[] = INCGFX_U32("graphics/battle_anims/sprites/sleep_powder.pal", ".gbapal.lz");
BATTLE_ANIM_ORB_AND_POWDER_RESOURCES const u32 gBattleAnimSpritePal_StunSpore[] = INCGFX_U32("graphics/battle_anims/sprites/stun_spore.pal", ".gbapal.lz");

#undef BATTLE_ANIM_ORB_AND_POWDER_RESOURCES

#define CONTEST_APPLAUSE_RESOURCES __attribute__((section(".rodata.contest_applause_resources")))

// The JP applause artwork retains its original compressed stream.
CONTEST_APPLAUSE_RESOURCES const u32 gContestApplauseGfx[] = INCGFX_U32("graphics/contest/applause.png", ".4bpp.lz");
CONTEST_APPLAUSE_RESOURCES const u8 gContestApplauseMeterGfx[] = INCGFX_U8("graphics/contest/applause_meter.png", ".4bpp");
CONTEST_APPLAUSE_RESOURCES const u16 gContestPal[] = INCGFX_U16("graphics/contest/nextturn.png", ".gbapal");

#undef CONTEST_APPLAUSE_RESOURCES

#define BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES __attribute__((section(".rodata.battle_anim_splash_through_protect_resources")))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Splash[] = INCGFX_U32("graphics/battle_anims/sprites/splash.png", ".4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpritePal_Splash[] = INCGFX_U32("graphics/battle_anims/sprites/splash.png", ".gbapal.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_SweatBead[] = INCGFX_U32("graphics/battle_anims/sprites/sweat_bead.png", ".4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Pokeblock[] = INCGFX_U32("graphics/battle_anims/sprites/pokeblock.png", ".4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpritePal_Pokeblock[] = INCGFX_U32("graphics/battle_anims/sprites/pokeblock.png", ".gbapal.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Gem1[] = INCGFX_U32("graphics/battle_anims/sprites/gem_1.png", ".4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Gem2[] = INCGFX_U32("graphics/battle_anims/sprites/gem_2.png", ".4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Gem3[] = INCGFX_U32("graphics/battle_anims/sprites/gem_3.png", ".4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpritePal_Gem1[] = INCGFX_U32("graphics/battle_anims/sprites/gem_1.png", ".gbapal.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimBgImage_InAir[] = INCGFX_U32("graphics/battle_anims/backgrounds/in_air.png", ".4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimBgPalette_InAir[] = INCGFX_U32("graphics/battle_anims/backgrounds/in_air.png", ".gbapal.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimBgTilemap_InAir[] = INCGFX_U32("graphics/battle_anims/backgrounds/in_air.bin", ".lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpriteGfx_Protect[] = INCGFX_U32("graphics/battle_anims/sprites/protect.png", ".4bpp.lz");
BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES const u32 gBattleAnimSpritePal_Protect[] = INCGFX_U32("graphics/battle_anims/sprites/protect.png", ".gbapal.lz");

#undef BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES

#define BATTLE_ANIM_MUDDY_WATER_RESOURCES __attribute__((section(".rodata.battle_anim_muddy_water_resources"), aligned(1)))

// The JP LZ77 stream retains its original stream-alignment padding.
BATTLE_ANIM_MUDDY_WATER_RESOURCES const u32 gBattleAnimBackgroundImageMuddyWater_Pal[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_muddy.pal", ".gbapal.lz");

#undef BATTLE_ANIM_MUDDY_WATER_RESOURCES

#define BATTLE_INTERFACE_BALL_STATUS_BAR_GRAPHICS __attribute__((section(".rodata.battle_interface_ball_status_bar_graphics"), aligned(1)))

// The JP LZ77 stream retains its original stream-alignment padding.
BATTLE_INTERFACE_BALL_STATUS_BAR_GRAPHICS const u32 gBattleInterface_BallStatusBarGfx[] = INCBIN_U32("graphics/battle_interface/ball_status_bar.4bpp.lz");

#undef BATTLE_INTERFACE_BALL_STATUS_BAR_GRAPHICS

#define EGG_ICON_GRAPHICS __attribute__((section(".rodata.egg_icon_graphics"), aligned(1)))

EGG_ICON_GRAPHICS const u8 gMonIcon_Egg[] = INCGFX_U8("graphics/pokemon/egg/icon.png", ".4bpp");

#undef EGG_ICON_GRAPHICS

#define BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES __attribute__((section(".rodata.battle_anim_ghost_and_solarbeam_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgImage_Ghost[] = INCGFX_U32("graphics/battle_anims/backgrounds/ghost.png", ".4bpp.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgPalette_Ghost[] = INCGFX_U32("graphics/battle_anims/backgrounds/ghost.png", ".gbapal.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgTilemap_Ghost[] = INCGFX_U32("graphics/battle_anims/backgrounds/ghost.bin", ".lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimSpritePal_WhipHit[] = INCGFX_U32("graphics/battle_anims/sprites/whip_hit.pal", ".gbapal.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgPalette_SolarBeam[] = INCGFX_U32("graphics/battle_anims/backgrounds/solarbeam.pal", ".gbapal.lz");
BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES const u32 gBattleAnimBgTilemap_SolarBeam[] = INCGFX_U32("graphics/battle_anims/backgrounds/solarbeam.bin", ".lz");

#undef BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES

#define BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES __attribute__((section(".rodata.battle_anim_cosmic_and_slam_hit_2_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimBgPalette_Cosmic[] = INCGFX_U32("graphics/battle_anims/backgrounds/cosmic.png", ".gbapal.lz");
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimBgImage_Cosmic[] = INCGFX_U32("graphics/battle_anims/backgrounds/cosmic.png", ".4bpp.lz");
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimBgTilemap_Cosmic[] = INCGFX_U32("graphics/battle_anims/backgrounds/cosmic.bin", ".lz");
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimSpritePal_SlamHit2[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit_2.png", ".gbapal.lz");
BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES const u32 gBattleAnimSpriteGfx_SlamHit2[] = INCGFX_U32("graphics/battle_anims/sprites/slam_hit_2.png", ".4bpp.lz");

#undef BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES

#define BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES __attribute__((section(".rodata.battle_anim_fog_through_cross_impact_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimFogTilemap[] = INCGFX_U32("graphics/battle_anims/backgrounds/fog.bin", ".lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_WeatherBall[] = INCGFX_U32("graphics/battle_anims/sprites/weather_ball.png", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_WeatherBall[] = INCGFX_U32("graphics/battle_anims/sprites/weather_ball.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgTilemap_ScaryFacePlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_player.bin", ".lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgTilemap_ScaryFaceOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_opponent.bin", ".lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgTilemap_ScaryFaceContest[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face_contest.bin", ".lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_Hail[] = INCGFX_U32("graphics/battle_anims/sprites/hail.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_Hail[] = INCGFX_U32("graphics/battle_anims/sprites/hail.png", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_GreenSpike[] = INCGFX_U32("graphics/battle_anims/sprites/green_spike.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_GreenSpike[] = INCGFX_U32("graphics/battle_anims/sprites/green_spike.png", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_WhiteCircleOfLight[] = INCGFX_U32("graphics/battle_anims/sprites/white_circle_of_light.pal", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_GlowyBlueOrb[] = INCGFX_U32("graphics/battle_anims/sprites/glowy_blue_orb.pal", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_Recycle[] = INCGFX_U32("graphics/battle_anims/sprites/recycle.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_Recycle[] = INCGFX_U32("graphics/battle_anims/sprites/recycle.png", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_RedParticles[] = INCGFX_U32("graphics/battle_anims/sprites/red_particles.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_RedParticles[] = INCGFX_U32("graphics/battle_anims/sprites/red_particles.png", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_DirtMound[] = INCGFX_U32("graphics/battle_anims/sprites/dirt_mound.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_DirtMound[] = INCGFX_U32("graphics/battle_anims/sprites/dirt_mound.png", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgImage_Fissure[] = INCGFX_U32("graphics/battle_anims/backgrounds/fissure.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgPalette_Fissure[] = INCGFX_U32("graphics/battle_anims/backgrounds/fissure.png", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimBgTilemap_Fissure[] = INCGFX_U32("graphics/battle_anims/backgrounds/fissure.bin", ".lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_Bird[] = INCGFX_U32("graphics/battle_anims/sprites/bird.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_Bird[] = INCGFX_U32("graphics/battle_anims/sprites/bird.png", ".gbapal.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpriteGfx_CrossImpact[] = INCGFX_U32("graphics/battle_anims/sprites/cross_impact.png", ".4bpp.lz");
BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES const u32 gBattleAnimSpritePal_CrossImpact[] = INCGFX_U32("graphics/battle_anims/sprites/cross_impact.png", ".gbapal.lz");

#undef BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES

#define BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES __attribute__((section(".rodata.battle_anim_surf_and_white_shadow_resources"), aligned(1)))

// The JP LZ77 streams retain their original stream-alignment padding.
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgImage_Surf[] = INCGFX_U32("graphics/battle_anims/backgrounds/water.png", ".4bpp.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgPalette_Surf[] = INCGFX_U32("graphics/battle_anims/backgrounds/water.png", ".gbapal.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgTilemap_SurfOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_opponent.bin", ".lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgTilemap_SurfPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_player.bin", ".lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimBgTilemap_SurfContest[] = INCGFX_U32("graphics/battle_anims/backgrounds/water_contest.bin", ".lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimSpritePal_Slash2[] = INCGFX_U32("graphics/battle_anims/sprites/slash_2.pal", ".gbapal.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimSpriteGfx_WhiteShadow[] = INCGFX_U32("graphics/battle_anims/sprites/white_shadow.png", ".4bpp.lz");
BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES const u32 gBattleAnimSpritePal_WhiteShadow[] = INCGFX_U32("graphics/battle_anims/sprites/white_shadow.png", ".gbapal.lz");

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

MON_ICON_PALETTES_DATA const u16 gMonIconPalettes[][16] =
{
    INCGFX_U16("graphics/pokemon/icon_palettes/icon_palette_0.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/icon_palette_1.pal", ".gbapal"),
    INCGFX_U16("graphics/pokemon/icon_palettes/icon_palette_2.pal", ".gbapal"),
};
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

SMOKESCREEN_IMPACT_GRAPHICS const u32 gSmokescreenImpactTiles[] = INCGFX_U32("graphics/battle_anims/sprites/smokescreen_impact.png", ".4bpp.lz");
SMOKESCREEN_IMPACT_GRAPHICS const u32 gSmokescreenImpactPalette[] = INCGFX_U32("graphics/battle_anims/sprites/smokescreen_impact.png", ".gbapal.lz");

#undef SMOKESCREEN_IMPACT_GRAPHICS

#define ENEMY_SHADOW_GRAPHICS __attribute__((section(".rodata.enemy_shadow_graphics"), aligned(1)))

ENEMY_SHADOW_GRAPHICS const u32 gEnemyMonShadow_Gfx[] = INCBIN_U32("graphics/battle_interface/enemy_mon_shadow.4bpp.lz");

#undef ENEMY_SHADOW_GRAPHICS

#define BERRY_BLENDER_BACKGROUND_GRAPHICS __attribute__((section(".rodata.berry_blender_background_graphics"), aligned(1)))

BERRY_BLENDER_BACKGROUND_GRAPHICS const u32 gBerryBlenderCenter_Gfx[] = INCBIN_U32("graphics/berry_blender/center.8bpp.lz");
BERRY_BLENDER_BACKGROUND_GRAPHICS const u32 gBerryBlenderOuter_Gfx[] = INCBIN_U32("graphics/berry_blender/outer.4bpp.lz");
BERRY_BLENDER_BACKGROUND_GRAPHICS const u8 gBerryBlenderOuter_Tilemap[] = INCBIN_U8("graphics/berry_blender/outer_map.bin.lz");

#undef BERRY_BLENDER_BACKGROUND_GRAPHICS

// The JP ROM interleaves these Easy Chat cursor assets with data that remains
// unclassified. Dedicated linker sections retain that physical order.
#define EASY_CHAT_RECTANGLE_CURSOR_PAL __attribute__((section(".rodata.easy_chat_rectangle_cursor_pal_data"), aligned(1)))

EASY_CHAT_RECTANGLE_CURSOR_PAL const u16 gEasyChatRectangleCursor_Pal[] = INCBIN_U16("graphics/easy_chat/rectangle_cursor.png.gbapal");

#undef EASY_CHAT_RECTANGLE_CURSOR_PAL

#define EASY_CHAT_RECTANGLE_CURSOR_GFX __attribute__((section(".rodata.easy_chat_rectangle_cursor_gfx_data"), aligned(1)))

EASY_CHAT_RECTANGLE_CURSOR_GFX const u32 gEasyChatRectangleCursor_Gfx[] = INCBIN_U32("graphics/easy_chat/rectangle_cursor.png.4bpp.lz");

#undef EASY_CHAT_RECTANGLE_CURSOR_GFX

#define EASY_CHAT_BUTTON_WINDOW_PAL __attribute__((section(".rodata.easy_chat_button_window_pal_data"), aligned(1)))

EASY_CHAT_BUTTON_WINDOW_PAL const u16 gEasyChatButtonWindow_Pal[] = INCBIN_U16("graphics/easy_chat/button_window.png.gbapal");

#undef EASY_CHAT_BUTTON_WINDOW_PAL

#define EASY_CHAT_MODE_GFX __attribute__((section(".rodata.easy_chat_mode_gfx_data"), aligned(1)))

EASY_CHAT_MODE_GFX const u32 gEasyChatMode_Gfx[] = INCBIN_U32("graphics/easy_chat/mode.png.4bpp.lz");

#undef EASY_CHAT_MODE_GFX

#define EASY_CHAT_MODE_PAL __attribute__((section(".rodata.easy_chat_mode_pal_data"), aligned(1)))

EASY_CHAT_MODE_PAL const u16 gEasyChatMode_Pal[] = INCBIN_U16("graphics/easy_chat/mode.png.gbapal");

#undef EASY_CHAT_MODE_PAL

#define EASY_CHAT_WINDOW_GFX __attribute__((section(".rodata.easy_chat_window_gfx_data"), aligned(1)))

EASY_CHAT_WINDOW_GFX const u32 gEasyChatWindow_Gfx[] = INCBIN_U32("graphics/easy_chat/window.png.4bpp.lz");

#undef EASY_CHAT_WINDOW_GFX

#define EASY_CHAT_WINDOW_TILEMAP __attribute__((section(".rodata.easy_chat_window_tilemap_data"), aligned(1)))

EASY_CHAT_WINDOW_TILEMAP const u32 gEasyChatWindow_Tilemap[] = INCBIN_U32("graphics/easy_chat/window.bin.lz");

#undef EASY_CHAT_WINDOW_TILEMAP

#define EASY_CHAT_BUTTON_WINDOW_GFX __attribute__((section(".rodata.easy_chat_button_window_gfx_data"), aligned(1)))

EASY_CHAT_BUTTON_WINDOW_GFX const u32 gEasyChatButtonWindow_Gfx[] = INCBIN_U32("graphics/easy_chat/button_window.png.4bpp.lz");

#undef EASY_CHAT_BUTTON_WINDOW_GFX

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

JP_CONTEST_GFX const u32 gJPContestGfx1[] = INCGFX_U32("graphics/contest/japanese/composite_1.4bpp", ".lz");
JP_CONTEST_GFX const u32 gJPContestPal[] = INCGFX_U32("graphics/contest/japanese/palette.pal", ".gbapal.lz");
JP_CONTEST_GFX const u32 gJPContestBgTilemap[] = INCGFX_U32("graphics/contest/japanese/bg.bin", ".lz");
JP_CONTEST_GFX const u32 gJPContestWindowsTilemap[] = INCGFX_U32("graphics/contest/japanese/windows.bin", ".lz");
JP_CONTEST_GFX const u32 gJPContestGfx2[] = INCGFX_U32("graphics/contest/japanese/composite_2.4bpp", ".lz");
JP_CONTEST_GFX const u32 gContestInterfaceAudiencePalette[] = INCGFX_U32("graphics/contest/interface.png", ".gbapal.lz");
JP_CONTEST_GFX const u32 gContestAudienceTilemap[] = INCGFX_U32("graphics/contest/audience.bin", ".lz");
JP_CONTEST_GFX const u32 gContestInterfaceTilemap[] = INCGFX_U32("graphics/contest/interface.bin", ".lz");
JP_CONTEST_GFX const u32 gJPContestInterfaceTilemap[] = INCGFX_U32("graphics/contest/japanese/interface.bin", ".lz");
JP_CONTEST_GFX const u32 gJPContestAudienceTilemap[] = INCGFX_U32("graphics/contest/japanese/audience.bin", ".lz");
JP_CONTEST_GFX const u32 gContestCurtainTilemap[] = INCGFX_U32("graphics/contest/curtain.bin", ".lz");
JP_CONTEST_GFX const u32 gContestInterfaceGfx[] = INCGFX_U32("graphics/contest/interface.png", ".4bpp.lz");
JP_CONTEST_GFX const u32 gContestAudienceGfx[] = INCGFX_U32("graphics/contest/audience.png", ".4bpp.lz");
JP_CONTEST_GFX const u32 gContestFaces_Gfx[] = INCGFX_U32("graphics/contest/faces.png", ".4bpp.lz");
JP_CONTEST_GFX const u32 gContestJudgeSymbolsGfx[] = INCGFX_U32("graphics/contest/judge_symbols.png", ".4bpp.lz");
JP_CONTEST_GFX const u32 gContestJudgeSymbolsPal[] = INCGFX_U32("graphics/contest/judge_symbols.png", ".gbapal.lz");
JP_CONTEST_GFX const u8 gContestSliderHeart_Gfx[] = INCGFX_U8("graphics/contest/slider_heart.png", ".4bpp");
JP_CONTEST_GFX const u32 gJPContestVoltageGfx[] = INCGFX_U32("graphics/contest/japanese/voltage.png", ".4bpp.lz", "-num_tiles 36 -Wnum_tiles");
JP_CONTEST_GFX const u32 gJPContestVoltagePal[] = INCGFX_U32("graphics/contest/japanese/voltage.png", ".gbapal.lz");
JP_CONTEST_GFX const u32 gContestResults_Gfx[] = INCGFX_U32("graphics/contest/results_screen/tiles.png", ".4bpp.lz");
JP_CONTEST_GFX const u32 gContestResults_WinnerBanner_Tilemap[] = INCGFX_U32("graphics/contest/results_screen/winner_banner.bin", ".lz");
JP_CONTEST_GFX const u32 gContestResults_Interface_Tilemap[] = INCGFX_U32("graphics/contest/results_screen/interface.bin", ".lz");
JP_CONTEST_GFX const u32 gContestResults_Bg_Tilemap[] = INCGFX_U32("graphics/contest/results_screen/bg.bin", ".lz");
JP_CONTEST_GFX const u32 gContestResults_Pal[] = INCGFX_U32("graphics/contest/results_screen/tiles.png", ".gbapal.lz");

#undef JP_CONTEST_GFX

#define BATTLE_ANIM_POST_CONTEST_GFX __attribute__((section(".rodata.battle_anim_post_contest_graphics")))

BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Impact[] = INCGFX_U32("graphics/battle_anims/sprites/impact.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Impact[] = INCGFX_U32("graphics/battle_anims/sprites/impact.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Particles[] = INCGFX_U32("graphics/battle_anims/sprites/particles.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_CircleImpact[] = INCGFX_U32("graphics/battle_anims/sprites/circle_impact.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_CircleImpact[] = INCGFX_U32("graphics/battle_anims/sprites/circle_impact.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Scratch[] = INCGFX_U32("graphics/battle_anims/sprites/scratch.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_SharpTeeth[] = INCGFX_U32("graphics/battle_anims/sprites/sharp_teeth.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_SharpTeeth[] = INCGFX_U32("graphics/battle_anims/sprites/sharp_teeth.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Clamp[] = INCGFX_U32("graphics/battle_anims/sprites/clamp.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Cut[] = INCGFX_U32("graphics/battle_anims/sprites/cut.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_RainbowRings[] = INCGFX_U32("graphics/battle_anims/sprites/rainbow_rings.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_RainbowRings[] = INCGFX_U32("graphics/battle_anims/sprites/rainbow_rings.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_IceCrystals[] = INCGFX_U32("graphics/battle_anims/sprites/ice_crystals.4bpp", ".lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_IceCrystals[] = INCGFX_U32("graphics/battle_anims/sprites/ice_crystals.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_IceSpikes[] = INCGFX_U32("graphics/battle_anims/sprites/ice_spikes.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_OldBeatUp[] = INCGFX_U32("graphics/battle_anims/unused/old_beatup.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_OldBeatUp[] = INCGFX_U32("graphics/battle_anims/unused/old_beatup.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Orbs[] = INCGFX_U32("graphics/battle_anims/sprites/orbs.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Orbs[] = INCGFX_U32("graphics/battle_anims/sprites/orbs.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_WaterOrb[] = INCGFX_U32("graphics/battle_anims/sprites/water_orb.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_WaterImpact[] = INCGFX_U32("graphics/battle_anims/sprites/water_impact.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_WaterImpact[] = INCGFX_U32("graphics/battle_anims/sprites/water_impact.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BrownOrb[] = INCGFX_U32("graphics/battle_anims/sprites/brown_orb.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_MudSand[] = INCGFX_U32("graphics/battle_anims/sprites/mud_sand.4bpp", ".lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_MudSand[] = INCGFX_U32("graphics/battle_anims/sprites/mud_sand.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_PoisonBubble[] = INCGFX_U32("graphics/battle_anims/sprites/poison_bubble.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_PoisonBubble[] = INCGFX_U32("graphics/battle_anims/sprites/poison_bubble.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_ToxicBubble[] = INCGFX_U32("graphics/battle_anims/sprites/toxic_bubble.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_HornHit2[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit_2.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_HornHit2[] = INCGFX_U32("graphics/battle_anims/sprites/horn_hit_2.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_AirWave2[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave_2.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_AirWave2[] = INCGFX_U32("graphics/battle_anims/sprites/air_wave_2.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_SmallBubbles[] = INCGFX_U32("graphics/battle_anims/sprites/small_bubbles.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_SmallBubbles[] = INCGFX_U32("graphics/battle_anims/sprites/small_bubbles.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_RoundShadow[] = INCGFX_U32("graphics/battle_anims/sprites/round_shadow.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_RoundShadow[] = INCGFX_U32("graphics/battle_anims/sprites/round_shadow.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Sunlight[] = INCGFX_U32("graphics/battle_anims/sprites/sunlight.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Sunlight[] = INCGFX_U32("graphics/battle_anims/sprites/sunlight.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Spore[] = INCGFX_U32("graphics/battle_anims/sprites/spore.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Spore[] = INCGFX_U32("graphics/battle_anims/sprites/spore.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Flower[] = INCGFX_U32("graphics/battle_anims/sprites/flower.4bpp", ".lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Flower[] = INCGFX_U32("graphics/battle_anims/sprites/flower.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_RazorLeaf[] = INCGFX_U32("graphics/battle_anims/sprites/razor_leaf.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_RazorLeaf[] = INCGFX_U32("graphics/battle_anims/sprites/razor_leaf.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_MistCloud[] = INCGFX_U32("graphics/battle_anims/sprites/mist_cloud.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_MistCloud[] = INCGFX_U32("graphics/battle_anims/sprites/mist_cloud.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimUnusedGfx_Lights[] = INCGFX_U32("graphics/battle_anims/unused/lights.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimUnusedPal_Lights[] = INCGFX_U32("graphics/battle_anims/unused/lights.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimUnusedTilemap_Lights[] = INCGFX_U32("graphics/battle_anims/unused/lights.bin", ".lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_WhirlwindLines[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind_lines.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_WhirlwindLines[] = INCGFX_U32("graphics/battle_anims/sprites/whirlwind_lines.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_GoldRing[] = INCGFX_U32("graphics/battle_anims/sprites/gold_ring.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_GoldRing[] = INCGFX_U32("graphics/battle_anims/sprites/gold_ring.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BlueRing2[] = INCGFX_U32("graphics/battle_anims/sprites/blue_ring_2.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_PurpleRing[] = INCGFX_U32("graphics/battle_anims/sprites/purple_ring.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BlueRing[] = INCGFX_U32("graphics/battle_anims/sprites/blue_ring.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_GreenLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/green_light_wall.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_GreenLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/green_light_wall.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BlueLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/blue_light_wall.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_RedLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/red_light_wall.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_GrayLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/gray_light_wall.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_OrangeLightWall[] = INCGFX_U32("graphics/battle_anims/sprites/orange_light_wall.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_BlackBall2[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball_2.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_BlackBall2[] = INCGFX_U32("graphics/battle_anims/sprites/black_ball_2.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_PurpleGasCloud[] = INCGFX_U32("graphics/battle_anims/sprites/purple_gas_cloud.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gContestJudgeGfx[] = INCGFX_U32("graphics/contest/judge.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gContest2Pal[] = INCGFX_U32("graphics/contest/judge.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_Spark[] = INCGFX_U32("graphics/battle_anims/sprites/spark.4bpp", ".lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpritePal_Spark[] = INCGFX_U32("graphics/battle_anims/sprites/spark.pal", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimSpriteGfx_SparkH[] = INCGFX_U32("graphics/battle_anims/sprites/spark_h.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimBgImage_Dark[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark.png", ".4bpp.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimBgPalette_Dark[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark.png", ".gbapal.lz");
BATTLE_ANIM_POST_CONTEST_GFX const u32 gBattleAnimBgTilemap_Dark[] = INCGFX_U32("graphics/battle_anims/backgrounds/dark.bin", ".lz");

#undef BATTLE_ANIM_POST_CONTEST_GFX



#define BATTLE_ANIM_MASK_AND_BG_GFX __attribute__((section(".rodata.battle_anim_mask_and_bg_graphics")))

BATTLE_ANIM_MASK_AND_BG_GFX const u32 gMetalShineGfx[] = INCGFX_U32("graphics/battle_anims/masks/metal_shine.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gMetalShinePalette[] = INCGFX_U32("graphics/battle_anims/masks/metal_shine.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gMetalShineTilemap[] = INCGFX_U32("graphics/battle_anims/masks/metal_shine.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedGfx_Goosuto[] = INCGFX_U32("graphics/battle_anims/unused/goosuto.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedPal_Goosuto[] = INCGFX_U32("graphics/battle_anims/unused/goosuto.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedTilemap_Goosuto[] = INCGFX_U32("graphics/battle_anims/unused/goosuto.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_YellowStar[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_star.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_YellowStar[] = INCGFX_U32("graphics/battle_anims/sprites/yellow_star.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_LargeFreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/large_fresh_egg.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_LargeFreshEgg[] = INCGFX_U32("graphics/battle_anims/sprites/large_fresh_egg.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ShadowBall[] = INCGFX_U32("graphics/battle_anims/sprites/shadow_ball.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ShadowBall[] = INCGFX_U32("graphics/battle_anims/sprites/shadow_ball.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Lick[] = INCGFX_U32("graphics/battle_anims/sprites/lick.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Lick[] = INCGFX_U32("graphics/battle_anims/sprites/lick.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_VoidLines[] = INCGFX_U32("graphics/battle_anims/sprites/void_lines.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_VoidLines[] = INCGFX_U32("graphics/battle_anims/sprites/void_lines.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_String[] = INCGFX_U32("graphics/battle_anims/sprites/string.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_String[] = INCGFX_U32("graphics/battle_anims/sprites/string.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_WebThread[] = INCGFX_U32("graphics/battle_anims/sprites/web_thread.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SpiderWeb[] = INCGFX_U32("graphics/battle_anims/sprites/spider_web.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Lightbulb[] = INCGFX_U32("graphics/battle_anims/sprites/lightbulb.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Lightbulb[] = INCGFX_U32("graphics/battle_anims/sprites/lightbulb.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Slash[] = INCGFX_U32("graphics/battle_anims/sprites/slash.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Slash[] = INCGFX_U32("graphics/battle_anims/sprites/slash.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_FocusEnergy[] = INCGFX_U32("graphics/battle_anims/sprites/focus_energy.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_FocusEnergy[] = INCGFX_U32("graphics/battle_anims/sprites/focus_energy.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SphereToCube[] = INCGFX_U32("graphics/battle_anims/sprites/sphere_to_cube.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_SphereToCube[] = INCGFX_U32("graphics/battle_anims/sprites/sphere_to_cube.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Psychic[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Psychic[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Psychic[] = INCGFX_U32("graphics/battle_anims/backgrounds/psychic.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Eye[] = INCGFX_U32("graphics/battle_anims/sprites/eye.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Eye[] = INCGFX_U32("graphics/battle_anims/sprites/eye.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Tendrils[] = INCGFX_U32("graphics/battle_anims/sprites/tendrils.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Tendrils[] = INCGFX_U32("graphics/battle_anims/sprites/tendrils.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxSinglesPlayerGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_singles_player.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxSinglesOpponentGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_singles_opponent.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxDoublesPlayerGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_doubles_player.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxDoublesOpponentGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_doubles_opponent.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gHealthboxSafariGfx[] = INCBIN_U32("graphics/battle_interface/healthbox_safari.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedGfx_Shadow[] = INCBIN_U32("graphics/unused/shadow.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gUnusedPal_Shadow[] = INCBIN_U32("graphics/unused/shadow.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_LockOn[] = INCGFX_U32("graphics/battle_anims/sprites/lock_on.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_LockOn[] = INCGFX_U32("graphics/battle_anims/sprites/lock_on.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_OpeningEye[] = INCGFX_U32("graphics/battle_anims/sprites/opening_eye.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_OpeningEye[] = INCGFX_U32("graphics/battle_anims/sprites/opening_eye.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_RoundWhiteHalo[] = INCGFX_U32("graphics/battle_anims/sprites/round_white_halo.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RoundWhiteHalo[] = INCGFX_U32("graphics/battle_anims/sprites/round_white_halo.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_TealAlert[] = INCGFX_U32("graphics/battle_anims/sprites/teal_alert.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_TealAlert[] = INCGFX_U32("graphics/battle_anims/sprites/teal_alert.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_FangAttack[] = INCGFX_U32("graphics/battle_anims/sprites/fang_attack.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_FangAttack[] = INCGFX_U32("graphics/battle_anims/sprites/fang_attack.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PurpleHandOutline[] = INCGFX_U32("graphics/battle_anims/sprites/purple_hand_outline.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PurpleHandOutline[] = INCGFX_U32("graphics/battle_anims/sprites/purple_hand_outline.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskImage_Curse[] = INCGFX_U32("graphics/battle_anims/masks/curse.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskTilemap_Curse[] = INCGFX_U32("graphics/battle_anims/masks/curse.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Pencil[] = INCGFX_U32("graphics/battle_anims/sprites/pencil.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Pencil[] = INCGFX_U32("graphics/battle_anims/sprites/pencil.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Spiral[] = INCGFX_U32("graphics/battle_anims/sprites/spiral.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Spiral[] = INCGFX_U32("graphics/battle_anims/sprites/spiral.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Moon[] = INCGFX_U32("graphics/battle_anims/sprites/moon.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Moon[] = INCGFX_U32("graphics/battle_anims/sprites/moon.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GreenSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/green_sparkle.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GreenSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/green_sparkle.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SnoreZ[] = INCGFX_U32("graphics/battle_anims/sprites/snore_z.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_SnoreZ[] = INCGFX_U32("graphics/battle_anims/sprites/snore_z.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Explosion[] = INCGFX_U32("graphics/battle_anims/sprites/explosion.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Explosion[] = INCGFX_U32("graphics/battle_anims/sprites/explosion.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Nail[] = INCGFX_U32("graphics/battle_anims/sprites/nail.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Nail[] = INCGFX_U32("graphics/battle_anims/sprites/nail.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GhostlySpirit[] = INCGFX_U32("graphics/battle_anims/sprites/ghostly_spirit.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GhostlySpirit[] = INCGFX_U32("graphics/battle_anims/sprites/ghostly_spirit.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_WarmRock[] = INCGFX_U32("graphics/battle_anims/sprites/warm_rock.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_WarmRock[] = INCGFX_U32("graphics/battle_anims/sprites/warm_rock.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PunchImpact[] = INCGFX_U32("graphics/battle_anims/sprites/punch_impact.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PunchImpact[] = INCGFX_U32("graphics/battle_anims/sprites/punch_impact.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_BreakingEgg[] = INCGFX_U32("graphics/battle_anims/sprites/breaking_egg.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_BreakingEgg[] = INCGFX_U32("graphics/battle_anims/sprites/breaking_egg.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ThinRing[] = INCGFX_U32("graphics/battle_anims/sprites/thin_ring.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ThinRing[] = INCGFX_U32("graphics/battle_anims/sprites/thin_ring.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_MusicNotes2[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes_2.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MusicNotes2[] = INCGFX_U32("graphics/battle_anims/sprites/music_notes_2.pal", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Bell[] = INCGFX_U32("graphics/battle_anims/sprites/bell.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Bell[] = INCGFX_U32("graphics/battle_anims/sprites/bell.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SpeedDust[] = INCGFX_U32("graphics/battle_anims/sprites/speed_dust.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_SpeedDust[] = INCGFX_U32("graphics/battle_anims/sprites/speed_dust.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_TornMetal[] = INCGFX_U32("graphics/battle_anims/sprites/torn_metal.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ThoughtBubble[] = INCGFX_U32("graphics/battle_anims/sprites/thought_bubble.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ThoughtBubble[] = INCGFX_U32("graphics/battle_anims/sprites/thought_bubble.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Finger[] = INCGFX_U32("graphics/battle_anims/sprites/finger.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Finger[] = INCGFX_U32("graphics/battle_anims/sprites/finger.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_MagentaHeart[] = INCGFX_U32("graphics/battle_anims/sprites/magenta_heart.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PinkHeart[] = INCGFX_U32("graphics/battle_anims/sprites/pink_heart.pal", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MagentaHeart[] = INCGFX_U32("graphics/battle_anims/sprites/magenta_heart.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RedHeart[] = INCGFX_U32("graphics/battle_anims/sprites/red_heart.pal", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Attract[] = INCGFX_U32("graphics/battle_anims/backgrounds/attract.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Attract[] = INCGFX_U32("graphics/battle_anims/backgrounds/attract.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Attract[] = INCGFX_U32("graphics/battle_anims/backgrounds/attract.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_RedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/red_orb.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RedOrb[] = INCGFX_U32("graphics/battle_anims/sprites/red_orb.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_CircleOfLight[] = INCGFX_U32("graphics/battle_anims/sprites/circle_of_light.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ElectricOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/electric_orbs.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Electricity[] = INCGFX_U32("graphics/battle_anims/sprites/electricity.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ElectricOrbs[] = INCGFX_U32("graphics/battle_anims/sprites/electric_orbs.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Finger2[] = INCGFX_U32("graphics/battle_anims/sprites/finger_2.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_MovementWaves[] = INCGFX_U32("graphics/battle_anims/sprites/movement_waves.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MovementWaves[] = INCGFX_U32("graphics/battle_anims/sprites/movement_waves.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_ScaryFace[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_ScaryFace[] = INCGFX_U32("graphics/battle_anims/backgrounds/scary_face.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_EyeSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/eye_sparkle.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_EyeSparkle[] = INCGFX_U32("graphics/battle_anims/sprites/eye_sparkle.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Anger[] = INCGFX_U32("graphics/battle_anims/sprites/anger.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Anger[] = INCGFX_U32("graphics/battle_anims/sprites/anger.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Conversion[] = INCGFX_U32("graphics/battle_anims/sprites/conversion.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Conversion[] = INCGFX_U32("graphics/battle_anims/sprites/conversion.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Angel[] = INCGFX_U32("graphics/battle_anims/sprites/angel.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Angel[] = INCGFX_U32("graphics/battle_anims/sprites/angel.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Devil[] = INCGFX_U32("graphics/battle_anims/sprites/devil.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Devil[] = INCGFX_U32("graphics/battle_anims/sprites/devil.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Swipe[] = INCGFX_U32("graphics/battle_anims/sprites/swipe.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Swipe[] = INCGFX_U32("graphics/battle_anims/sprites/swipe.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Roots[] = INCGFX_U32("graphics/battle_anims/sprites/roots.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Roots[] = INCGFX_U32("graphics/battle_anims/sprites/roots.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_ItemBag[] = INCGFX_U32("graphics/battle_anims/sprites/item_bag.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_ItemBag[] = INCGFX_U32("graphics/battle_anims/sprites/item_bag.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_TriAttackTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/tri_attack_triangle.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_TriAttackTriangle[] = INCGFX_U32("graphics/battle_anims/sprites/tri_attack_triangle.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_LetterZ[] = INCGFX_U32("graphics/battle_anims/sprites/letter_z.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_LetterZ[] = INCGFX_U32("graphics/battle_anims/sprites/letter_z.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Impact[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Impact[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_ImpactOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_opponent.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_ImpactPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_player.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_ImpactContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/impact_contests.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_JaggedMusicNote[] = INCGFX_U32("graphics/battle_anims/sprites/jagged_music_note.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_JaggedMusicNote[] = INCGFX_U32("graphics/battle_anims/sprites/jagged_music_note.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Spotlight[] = INCGFX_U32("graphics/battle_anims/sprites/spotlight.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Pokeball[] = INCGFX_U32("graphics/battle_anims/sprites/pokeball.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Pokeball[] = INCGFX_U32("graphics/battle_anims/sprites/pokeball.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_RapidSpin[] = INCGFX_U32("graphics/battle_anims/sprites/rapid_spin.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RapidSpin[] = INCGFX_U32("graphics/battle_anims/sprites/rapid_spin.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_MilkBottle[] = INCGFX_U32("graphics/battle_anims/sprites/milk_bottle.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MilkBottle[] = INCGFX_U32("graphics/battle_anims/sprites/milk_bottle.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_WispFire[] = INCGFX_U32("graphics/battle_anims/sprites/wisp_fire.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_WispOrb[] = INCGFX_U32("graphics/battle_anims/sprites/wisp_orb.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_WispOrb[] = INCGFX_U32("graphics/battle_anims/sprites/wisp_orb.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GoldStars[] = INCGFX_U32("graphics/battle_anims/sprites/gold_stars.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GoldStars[] = INCGFX_U32("graphics/battle_anims/sprites/gold_stars.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_EclipsingOrb[] = INCGFX_U32("graphics/battle_anims/sprites/eclipsing_orb.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_EclipsingOrb[] = INCGFX_U32("graphics/battle_anims/sprites/eclipsing_orb.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PinkPetal[] = INCGFX_U32("graphics/battle_anims/sprites/pink_petal.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PinkPetal[] = INCGFX_U32("graphics/battle_anims/sprites/pink_petal.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GrayOrb[] = INCGFX_U32("graphics/battle_anims/sprites/gray_orb.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GrayOrb[] = INCGFX_U32("graphics/battle_anims/sprites/gray_orb.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_BlueOrb[] = INCGFX_U32("graphics/battle_anims/sprites/blue_orb.pal", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_RedOrb2[] = INCGFX_U32("graphics/battle_anims/sprites/red_orb_2.pal", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Drill[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Drill[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Sky[] = INCGFX_U32("graphics/battle_anims/backgrounds/sky.pal", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Drill[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_DrillContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/drill_contests.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Aurora[] = INCGFX_U32("graphics/battle_anims/backgrounds/aurora.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Aurora[] = INCGFX_U32("graphics/battle_anims/backgrounds/aurora.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Aurora[] = INCGFX_U32("graphics/battle_anims/backgrounds/aurora.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_HighspeedOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed_opponent.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Highspeed[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Bug[] = INCGFX_U32("graphics/battle_anims/backgrounds/bug.pal", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Highspeed[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_HighspeedPlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/highspeed_player.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskImage_LightBeam[] = INCGFX_U32("graphics/battle_anims/masks/light_beam.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskPalette_LightBeam[] = INCGFX_U32("graphics/battle_anims/masks/light_beam.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskTilemap_LightBeam[] = INCGFX_U32("graphics/battle_anims/masks/light_beam.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_GuillotineOpponent[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_opponent.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_GuillotinePlayer[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_player.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_GuillotineContests[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine_contests.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Guillotine[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Guillotine[] = INCGFX_U32("graphics/battle_anims/backgrounds/guillotine.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Thunder[] = INCGFX_U32("graphics/battle_anims/backgrounds/thunder.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Thunder[] = INCGFX_U32("graphics/battle_anims/backgrounds/thunder.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Thunder[] = INCGFX_U32("graphics/battle_anims/backgrounds/thunder.bin", ".lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PainSplit[] = INCGFX_U32("graphics/battle_anims/sprites/pain_split.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PainSplit[] = INCGFX_U32("graphics/battle_anims/sprites/pain_split.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_HandsAndFeet[] = INCGFX_U32("graphics/battle_anims/sprites/hands_and_feet.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_HandsAndFeet[] = INCGFX_U32("graphics/battle_anims/sprites/hands_and_feet.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_Confetti[] = INCGFX_U32("graphics/battle_anims/sprites/confetti.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_Confetti[] = INCGFX_U32("graphics/battle_anims/sprites/confetti.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gSubstituteDollPal[] = INCGFX_U32("graphics/battle_anims/sprites/substitute.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gSubstituteDollFrontGfx[] = INCGFX_U32("graphics/battle_anims/sprites/substitute.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gSubstituteDollBackGfx[] = INCGFX_U32("graphics/battle_anims/sprites/substitute_back.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_GreenStar[] = INCGFX_U32("graphics/battle_anims/sprites/green_star.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_GreenStar[] = INCGFX_U32("graphics/battle_anims/sprites/green_star.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gConfetti_Gfx[] = INCBIN_U32("graphics/misc/confetti.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gConfetti_Pal[] = INCBIN_U32("graphics/misc/confetti.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_PinkCloud[] = INCGFX_U32("graphics/battle_anims/sprites/pink_cloud.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_PinkCloud[] = INCGFX_U32("graphics/battle_anims/sprites/pink_cloud.png", ".gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpriteGfx_SweatDrop[] = INCGFX_U32("graphics/battle_anims/sprites/sweat_drop.png", ".4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_SweatDrop[] = INCGFX_U32("graphics/battle_anims/sprites/sweat_drop.png", ".gbapal.lz");

#undef BATTLE_ANIM_MASK_AND_BG_GFX

#define BATTLE_ANIM_STAT_CHANGE_GFX __attribute__((section(".rodata.battle_anim_stat_change_graphics")))

BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Gfx[] = INCGFX_U32("graphics/battle_anims/stat_change/tiles.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Increase_Tilemap[] = INCGFX_U32("graphics/battle_anims/stat_change/increase.bin", ".lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Decrease_Tilemap[] = INCGFX_U32("graphics/battle_anims/stat_change/decrease.bin", ".lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Defense_Pal[] = INCGFX_U32("graphics/battle_anims/stat_change/defense.pal", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Attack_Pal[] = INCGFX_U32("graphics/battle_anims/stat_change/attack.pal", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Accuracy_Pal[] = INCGFX_U32("graphics/battle_anims/stat_change/accuracy.pal", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Speed_Pal[] = INCGFX_U32("graphics/battle_anims/stat_change/speed.pal", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Multiple_Pal[] = INCGFX_U32("graphics/battle_anims/stat_change/multiple.pal", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Evasion_Pal[] = INCGFX_U32("graphics/battle_anims/stat_change/evasion.pal", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_SpAttack_Pal[] = INCGFX_U32("graphics/battle_anims/stat_change/sp_attack.pal", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_SpDefense_Pal[] = INCGFX_U32("graphics/battle_anims/stat_change/sp_defense.pal", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesGfx[] = INCGFX_U32("graphics/battle_anims/masks/cure_bubbles.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesPal[] = INCGFX_U32("graphics/battle_anims/masks/cure_bubbles.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesTilemap[] = INCGFX_U32("graphics/battle_anims/masks/cure_bubbles.bin", ".lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_PurpleScratch[] = INCGFX_U32("graphics/battle_anims/sprites/purple_scratch.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_PurpleScratch[] = INCGFX_U32("graphics/battle_anims/sprites/purple_scratch.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_PurpleSwipe[] = INCGFX_U32("graphics/battle_anims/sprites/purple_swipe.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_GuardRing[] = INCGFX_U32("graphics/battle_anims/sprites/guard_ring.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_GuardRing[] = INCGFX_U32("graphics/battle_anims/sprites/guard_ring.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_TagHand[] = INCGFX_U32("graphics/battle_anims/sprites/tag_hand.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_NoiseLine[] = INCGFX_U32("graphics/battle_anims/sprites/noise_line.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 UnusedLevelupAnimationGfx[] = INCGFX_U32("graphics/battle_anims/masks/unused_level_up.png", ".4bpp.lz", "-num_tiles 14 -Wnum_tiles");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 UnusedLevelupAnimationTilemap[] = INCGFX_U32("graphics/battle_anims/masks/unused_level_up.bin", ".lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_SmallRedEye[] = INCGFX_U32("graphics/battle_anims/sprites/small_red_eye.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_SmallRedEye[] = INCGFX_U32("graphics/battle_anims/sprites/small_red_eye.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_HollowOrb[] = INCGFX_U32("graphics/battle_anims/sprites/hollow_orb.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_HollowOrb[] = INCGFX_U32("graphics/battle_anims/sprites/hollow_orb.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_XSign[] = INCGFX_U32("graphics/battle_anims/sprites/x_sign.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_BluegreenOrb[] = INCGFX_U32("graphics/battle_anims/sprites/bluegreen_orb.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_BluegreenOrb[] = INCGFX_U32("graphics/battle_anims/sprites/bluegreen_orb.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_PawPrint[] = INCGFX_U32("graphics/battle_anims/sprites/paw_print.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_PawPrint[] = INCGFX_U32("graphics/battle_anims/sprites/paw_print.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_PurpleFlame[] = INCGFX_U32("graphics/battle_anims/sprites/purple_flame.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_PurpleFlame[] = INCGFX_U32("graphics/battle_anims/sprites/purple_flame.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_RedBall[] = INCGFX_U32("graphics/battle_anims/sprites/red_ball.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_RedBall[] = INCGFX_U32("graphics/battle_anims/sprites/red_ball.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_SmellingsaltEffect[] = INCGFX_U32("graphics/battle_anims/sprites/smellingsalt_effect.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_SmellingsaltEffect[] = INCGFX_U32("graphics/battle_anims/sprites/smellingsalt_effect.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_MagnifyingGlass[] = INCGFX_U32("graphics/battle_anims/sprites/magnifying_glass.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_MagnifyingGlass[] = INCGFX_U32("graphics/battle_anims/sprites/magnifying_glass.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_Meteor[] = INCGFX_U32("graphics/battle_anims/sprites/meteor.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_Meteor[] = INCGFX_U32("graphics/battle_anims/sprites/meteor.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpriteGfx_FlatRock[] = INCGFX_U32("graphics/battle_anims/sprites/flat_rock.png", ".4bpp.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimSpritePal_FlatRock[] = INCGFX_U32("graphics/battle_anims/sprites/flat_rock.png", ".gbapal.lz");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gBattleAnimUnusedPal_Unknown2[] = INCGFX_U32("graphics/battle_anims/unused/unknown_2.pal", ".gbapal.lz");

#undef BATTLE_ANIM_STAT_CHANGE_GFX

#define POKEMON_GRAPHICS_PREFIX __attribute__((section(".rodata.pokemon_graphics_prefix")))

#include "data/graphics/pokemon.h"

#undef POKEMON_GRAPHICS_PREFIX

#define QUESTION_MARK_GRAPHICS __attribute__((section(".rodata.pokemon_question_mark_graphics"), aligned(1)))

QUESTION_MARK_GRAPHICS const u8 gMonIcon_QuestionMark[] = INCGFX_U8("graphics/pokemon/question_mark/icon.png", ".4bpp");
QUESTION_MARK_GRAPHICS const u8 gMonFootprint_QuestionMark[] = INCGFX_U8("graphics/pokemon/question_mark/footprint.png", ".1bpp");

#undef QUESTION_MARK_GRAPHICS

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

TILESET_GENERAL_DATA const u32 gTilesetTiles_General[] = INCGFX_U32("data/tilesets/primary/general/tiles.png", ".4bpp.lz");

TILESET_GENERAL_DATA const u16 gTilesetPalettes_General[][16] =
{
    INCGFX_U16("data/tilesets/primary/general/palettes/00.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/01.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/02.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/03.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/04.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/05.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/06.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/07.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/08.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/09.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/10.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/11.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/12.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/13.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/14.pal", ".gbapal"),
    INCGFX_U16("data/tilesets/primary/general/palettes/15.pal", ".gbapal"),
};

#undef TILESET_GENERAL_DATA

#include "data/graphics/slot_machine.h"

#define MON_MARKINGS_MENU_GRAPHICS __attribute__((section(".rodata.mon_markings_menu_graphics"), aligned(1)))

MON_MARKINGS_MENU_GRAPHICS const u16 gMonMarkingsMenu_Pal[] = INCGFX_U16("graphics/interface/mon_markings_menu.png", ".gbapal");
MON_MARKINGS_MENU_GRAPHICS const u8 gMonMarkingsMenu_Gfx[] = INCGFX_U8("graphics/interface/mon_markings_menu.png", ".4bpp");

#undef MON_MARKINGS_MENU_GRAPHICS

#define USE_POKEBLOCK_UPDOWN_GRAPHICS __attribute__((section(".rodata.use_pokeblock_updown_graphics"), aligned(1)))
#define USE_POKEBLOCK_CONDITION_GRAPHICS __attribute__((section(".rodata.use_pokeblock_condition_graphics"), aligned(1)))
#define USE_POKEBLOCK_GRAPH_PALETTE __attribute__((section(".rodata.use_pokeblock_graph_palette"), aligned(1)))
#define USE_POKEBLOCK_GRAPH_GRAPHICS __attribute__((section(".rodata.use_pokeblock_graph_graphics"), aligned(1)))
#define USE_POKEBLOCK_NATURE_WINDOW __attribute__((section(".rodata.use_pokeblock_nature_window"), aligned(1)))

USE_POKEBLOCK_CONDITION_GRAPHICS const u32 gUsePokeblockCondition_Gfx[] = INCGFX_U32("graphics/pokeblock/use_screen/condition.png", ".4bpp.lz");
USE_POKEBLOCK_CONDITION_GRAPHICS const u16 gUsePokeblockCondition_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/condition.png", ".gbapal");

USE_POKEBLOCK_UPDOWN_GRAPHICS const u16 gUsePokeblockUpDown_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/updown.png", ".gbapal");
USE_POKEBLOCK_UPDOWN_GRAPHICS const u8 gUsePokeblockUpDown_Gfx[] = INCGFX_U8("graphics/pokeblock/use_screen/updown.png", ".4bpp");

USE_POKEBLOCK_GRAPH_PALETTE const u16 gUsePokeblockGraph_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/graph.png", ".gbapal");
USE_POKEBLOCK_GRAPH_GRAPHICS const u32 gUsePokeblockGraph_Gfx[] = INCGFX_U32("graphics/pokeblock/use_screen/graph.png", ".4bpp.lz", "-num_tiles 125");
USE_POKEBLOCK_GRAPH_GRAPHICS const u32 gUsePokeblockGraph_Tilemap[] = INCGFX_U32("graphics/pokeblock/use_screen/graph.bin", ".lz");
// JP uses an 11-column tilemap patch; the US owner retains this palette name.
USE_POKEBLOCK_NATURE_WINDOW const u16 gUsePokeblockNatureWin_Pal[] = INCGFX_U16("graphics/pokeblock/use_screen/nature.pal", ".gbapal");

#undef USE_POKEBLOCK_UPDOWN_GRAPHICS
#undef USE_POKEBLOCK_CONDITION_GRAPHICS
#undef USE_POKEBLOCK_GRAPH_PALETTE
#undef USE_POKEBLOCK_GRAPH_GRAPHICS
#undef USE_POKEBLOCK_NATURE_WINDOW

#define GRAPHICS_TRAINER_CARD_TILES __attribute__((section(".rodata.graphics_trainer_card_tiles"), aligned(1)))

#define GRAPHICS_TRAINER_CARD_TILEMAPS __attribute__((section(".rodata.graphics_trainer_card_tilemaps"), aligned(1)))

#define GRAPHICS_TRAINER_CARD_PALETTES __attribute__((section(".rodata.graphics_trainer_card_palettes"), aligned(1)))

const u32 gHoennTrainerCard_Gfx[] GRAPHICS_TRAINER_CARD_TILES = INCBIN_U32("graphics/trainer_card/tiles.4bpp.lz");

const u32 gKantoTrainerCard_Gfx[] GRAPHICS_TRAINER_CARD_TILES = INCBIN_U32("graphics/trainer_card/frlg/tiles.4bpp.lz");

const u32 gHoennTrainerCardFront_Tilemap[] GRAPHICS_TRAINER_CARD_TILEMAPS = INCBIN_U32("graphics/trainer_card/front.bin.lz");

const u32 gKantoTrainerCardFront_Tilemap[] GRAPHICS_TRAINER_CARD_TILEMAPS = INCBIN_U32("graphics/trainer_card/frlg/front.bin.lz");

const u32 gHoennTrainerCardBack_Tilemap[] GRAPHICS_TRAINER_CARD_TILEMAPS = INCBIN_U32("graphics/trainer_card/back.bin.lz");

const u32 gKantoTrainerCardBack_Tilemap[] GRAPHICS_TRAINER_CARD_TILEMAPS = INCBIN_U32("graphics/trainer_card/frlg/back.bin.lz");

const u32 gHoennTrainerCardFrontLink_Tilemap[] GRAPHICS_TRAINER_CARD_TILEMAPS = INCBIN_U32("graphics/trainer_card/front_link.bin.lz");

const u32 gKantoTrainerCardFrontLink_Tilemap[] GRAPHICS_TRAINER_CARD_TILEMAPS = INCBIN_U32("graphics/trainer_card/frlg/front_link.bin.lz");

const u32 gHoennTrainerCardBg_Tilemap[] GRAPHICS_TRAINER_CARD_TILEMAPS = INCBIN_U32("graphics/trainer_card/bg.bin.lz");

const u32 gKantoTrainerCardBg_Tilemap[] GRAPHICS_TRAINER_CARD_TILEMAPS = INCBIN_U32("graphics/trainer_card/frlg/bg.bin.lz");

const u16 gHoennTrainerCardGreen_Pal[] GRAPHICS_TRAINER_CARD_PALETTES = INCBIN_U16("graphics/trainer_card/green.pal.gbapal");

const u16 gKantoTrainerCardBlue_Pal[] GRAPHICS_TRAINER_CARD_PALETTES = INCBIN_U16("graphics/trainer_card/frlg/blue.pal.gbapal");

#undef GRAPHICS_TRAINER_CARD_TILES

#undef GRAPHICS_TRAINER_CARD_TILEMAPS

#undef GRAPHICS_TRAINER_CARD_PALETTES

const u16 gFrontierPassBg_Pal[8][16] __attribute__((section(".rodata.graphics_frontier_pass_palettes"), aligned(4))) = INCBIN_U16("graphics/frontier_pass/bg.gbapal");
const u16 gFrontierPassCursor_Pal[] __attribute__((section(".rodata.graphics_frontier_pass_palettes"), aligned(4))) = INCBIN_U16("graphics/frontier_pass/cursor.gbapal");
const u16 gFrontierPassMapCursor_Pal[] __attribute__((section(".rodata.graphics_frontier_pass_palettes"), aligned(4))) = INCBIN_U16("graphics/frontier_pass/map_cursor.gbapal");
const u16 gFrontierPassMedalsSilver_Pal[] __attribute__((section(".rodata.graphics_frontier_pass_palettes"), aligned(4))) = INCBIN_U16("graphics/frontier_pass/silver.gbapal");
const u16 gFrontierPassMedalsGold_Pal[] __attribute__((section(".rodata.graphics_frontier_pass_palettes"), aligned(4))) = INCBIN_U16("graphics/frontier_pass/gold.gbapal");
const u32 gFrontierPassBg_Gfx[] __attribute__((section(".rodata.graphics_frontier_pass_background"), aligned(4))) = INCBIN_U32("graphics/frontier_pass/bg.4bpp.lz");
const u32 gFrontierPassMedals_Gfx[] __attribute__((section(".rodata.graphics_frontier_pass_medals"), aligned(4))) = INCBIN_U32("graphics/frontier_pass/medals.4bpp.lz");
const u32 gFrontierPassBg_Tilemap[] __attribute__((section(".rodata.graphics_frontier_pass_bg_tilemap"), aligned(4))) = INCBIN_U32("graphics/frontier_pass/bg.bin.lz");
const u32 gFrontierPassCancelButton_Tilemap[] __attribute__((section(".rodata.graphics_frontier_pass_cancel_tilemaps"), aligned(4))) = INCBIN_U32("graphics/frontier_pass/cancel.bin");
const u32 gFrontierPassCancelButtonHighlighted_Tilemap[] __attribute__((section(".rodata.graphics_frontier_pass_cancel_tilemaps"), aligned(4))) = INCBIN_U32("graphics/frontier_pass/cancel_highlighted.bin");
const u32 gFrontierPassMapAndCard_Gfx[] __attribute__((section(".rodata.graphics_frontier_pass_zoom_graphics"), aligned(4))) = INCBIN_U32("graphics/frontier_pass/map_and_card.8bpp.lz");

#define STORAGE_PARTY_PALETTE __attribute__((section(".rodata.graphics_storage_party_palette"), aligned(4)))

const u16 gStorageSystemPartyMenu_Pal[] STORAGE_PARTY_PALETTE = INCBIN_U16("graphics/pokemon_storage/party_menu.pal.gbapal");

#undef STORAGE_PARTY_PALETTE

#define STORAGE_MENU_GRAPHICS __attribute__((section(".rodata.graphics_storage_menu"), aligned(4)))

const u32 gStorageSystemMenu_Gfx[] STORAGE_MENU_GRAPHICS = INCBIN_U32("graphics/pokemon_storage/menu.png.4bpp.lz");
const u32 gStorageSystemPartyMenu_Tilemap[] STORAGE_MENU_GRAPHICS = INCBIN_U32("graphics/pokemon_storage/party_menu.bin.lz");

#undef STORAGE_MENU_GRAPHICS

#define HORIZONTAL_WALLPAPER_DATA __attribute__((section(".rodata.graphics_wallpaper_horizontal"), aligned(4)))
#define RIBBON_WALLPAPER_DATA __attribute__((section(".rodata.graphics_wallpaper_ribbon"), aligned(4)))
#define CROSS_WALLPAPER_ICON_DATA __attribute__((section(".rodata.graphics_wallpaper_icon_cross"), aligned(4)))
#define BOLT_WALLPAPER_ICON_DATA __attribute__((section(".rodata.graphics_wallpaper_icon_bolt"), aligned(4)))
#define PLUSLE_WALLPAPER_ICON_DATA __attribute__((section(".rodata.graphics_wallpaper_icon_plusle"), aligned(4)))

const u32 gWallpaperIcon_Cross[] CROSS_WALLPAPER_ICON_DATA = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/cross.png.4bpp.lz");
const u32 gWallpaperIcon_Bolt[] BOLT_WALLPAPER_ICON_DATA = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/bolt.png.4bpp.lz");
const u32 gWallpaperIcon_Plusle[] PLUSLE_WALLPAPER_ICON_DATA = INCBIN_U32("graphics/pokemon_storage/wallpapers/icons/plusle.png.4bpp.lz");

const u16 gWallpaperPalettes_Horizontal[][16] HORIZONTAL_WALLPAPER_DATA =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/horizontal/bg.png.gbapal"),
};

const u32 gWallpaperTiles_Horizontal[] HORIZONTAL_WALLPAPER_DATA = INCBIN_U32("graphics/pokemon_storage/wallpapers/horizontal/tiles.4bpp.lz");
const u32 gWallpaperTilemap_Horizontal[] HORIZONTAL_WALLPAPER_DATA = INCBIN_U32("graphics/pokemon_storage/wallpapers/horizontal/tilemap.bin.lz");

const u16 gWallpaperPalettes_Ribbon[][16] RIBBON_WALLPAPER_DATA =
{
    INCBIN_U16("graphics/pokemon_storage/wallpapers/ribbon/frame.pal.gbapal"),
    INCBIN_U16("graphics/pokemon_storage/wallpapers/ribbon/bg.png.gbapal"),
};

const u32 gWallpaperTiles_Ribbon[] RIBBON_WALLPAPER_DATA = INCBIN_U32("graphics/pokemon_storage/wallpapers/ribbon/tiles.4bpp.lz");
const u32 gWallpaperTilemap_Ribbon[] RIBBON_WALLPAPER_DATA = INCBIN_U32("graphics/pokemon_storage/wallpapers/ribbon/tilemap.bin.lz");


#undef HORIZONTAL_WALLPAPER_DATA
#undef RIBBON_WALLPAPER_DATA
#undef CROSS_WALLPAPER_ICON_DATA
#undef BOLT_WALLPAPER_ICON_DATA
#undef PLUSLE_WALLPAPER_ICON_DATA

#include "data/graphics/unused_pokenav.h"

#define CONTEST_RESULTS_TITLE_TILEMAPS __attribute__((section(".rodata.contest_results_title_tilemaps")))

// JP title tilemaps are shorter than their localized US counterparts.
CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Normal_Tilemap[] =
{
    0x0020, 0x0021, 0x0022, 0x0023, 0x0008, 0x0009, 0x000A, 0x0010,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0018, 0x0019, 0x001A, 0x0010,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Super_Tilemap[] =
{
    0x0024, 0x0021, 0x0025, 0x0021, 0x0008, 0x0009, 0x000A, 0x0010,
    0x0034, 0x0031, 0x0035, 0x0031, 0x0018, 0x0019, 0x001A, 0x0010,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Hyper_Tilemap[] =
{
    0x0026, 0x0027, 0x0025, 0x0021, 0x0008, 0x0009, 0x000A, 0x0010,
    0x0036, 0x0037, 0x0035, 0x0031, 0x0018, 0x0019, 0x001A, 0x0010,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Master_Tilemap[] =
{
    0x0022, 0x0024, 0x0028, 0x0021, 0x0008, 0x0009, 0x000A, 0x0010,
    0x0032, 0x0034, 0x0038, 0x0031, 0x0018, 0x0019, 0x001A, 0x0010,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Link_Tilemap[] =
{
    0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0004,
    0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0014,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Cool_Tilemap[] =
{
    0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x0039, 0x003A, 0x003B,
    0x003C, 0x003D,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Beauty_Tilemap[] =
{
    0x1002, 0x1001, 0x102E, 0x1003, 0x102D, 0x1012, 0x1011, 0x103E,
    0x1013, 0x103D,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Cute_Tilemap[] =
{
    0x2029, 0x202F, 0x2006, 0x202D, 0x2010, 0x2039, 0x203F, 0x2016,
    0x203D, 0x2010,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Smart_Tilemap[] =
{
    0x3029, 0x3003, 0x302B, 0x302D, 0x3010, 0x3039, 0x3013, 0x303B,
    0x303D, 0x3010,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Tough_Tilemap[] =
{
    0x4005, 0x402E, 0x4040, 0x4003, 0x402D, 0x4015, 0x403E, 0x4050,
    0x4013, 0x403D,
};

CONTEST_RESULTS_TITLE_TILEMAPS const u16 gContestResultsTitle_Tilemap[] =
{
    0x000B, 0x000C, 0x000D, 0x000E, 0x000F, 0x001B, 0x001C, 0x001D,
    0x001E, 0x001F,
};

#undef CONTEST_RESULTS_TITLE_TILEMAPS

#define ITEM_ICONS_GRAPHICS __attribute__((section(".rodata.item_icon_graphics"), aligned(4)))
#include "data/graphics/items.h"
#undef ITEM_ICONS_GRAPHICS

#define ROULETTE_GRAPHICS __attribute__((section(".rodata.roulette_graphics"), aligned(4)))

ROULETTE_GRAPHICS const u32 gRouletteMenu_Gfx[] = INCGFX_U32("graphics/roulette/window.png", ".4bpp.lz");
ROULETTE_GRAPHICS const u32 gRouletteWheel_Gfx[] = INCGFX_U32("graphics/roulette/wheel.png", ".8bpp.lz");
ROULETTE_GRAPHICS const u32 gRouletteCenter_Gfx[] = INCGFX_U32("graphics/roulette/center.png", ".4bpp.lz");
ROULETTE_GRAPHICS const u32 gRouletteHeaders_Gfx[] = INCGFX_U32("graphics/roulette/headers.png", ".4bpp.lz");
ROULETTE_GRAPHICS const u32 gRouletteCredit_Gfx[] = INCGFX_U32("graphics/roulette/credit.png", ".4bpp.lz");
ROULETTE_GRAPHICS const u32 gRouletteNumbers_Gfx[] = INCGFX_U32("graphics/roulette/numbers.png", ".4bpp.lz");
ROULETTE_GRAPHICS const u32 gRouletteMultiplier_Gfx[] = INCGFX_U32("graphics/roulette/multiplier.png", ".4bpp.lz");

#undef ROULETTE_GRAPHICS

#define MAIL_GRAPHICS __attribute__((section(".rodata.mail_graphics"), aligned(4)))
#include "data/graphics/mail.h"
#undef MAIL_GRAPHICS
