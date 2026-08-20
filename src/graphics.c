#include "global.h"

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
BATTLE_ANIM_MASK_AND_BG_GFX static const u32 sBattleAnimDataAfterCurse[] = INCBIN_U32("graphics/battle_anims/unknown/jp/after_curse.bin");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimSpritePal_MusicNotes2[] = INCBIN_U32("graphics/battle_anims/sprites/music_notes_2.pal.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX static const u32 sBattleAnimDataAfterMusicNotes2[] = INCBIN_U32("graphics/battle_anims/unknown/jp/after_music_notes_2.bin");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_Attract[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_Attract[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgTilemap_Attract[] = INCBIN_U32("graphics/battle_anims/backgrounds/attract.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX static const u32 sBattleAnimDataAfterAttract[] = INCBIN_U32("graphics/battle_anims/unknown/jp/after_attract.bin");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgPalette_ScaryFace[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimBgImage_ScaryFace[] = INCBIN_U32("graphics/battle_anims/backgrounds/scary_face.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX static const u32 sBattleAnimDataAfterScaryFace[] = INCBIN_U32("graphics/battle_anims/unknown/jp/after_scary_face.bin");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskImage_LightBeam[] = INCBIN_U32("graphics/battle_anims/masks/light_beam.png.4bpp.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskPalette_LightBeam[] = INCBIN_U32("graphics/battle_anims/masks/light_beam.png.gbapal.lz");
BATTLE_ANIM_MASK_AND_BG_GFX const u32 gBattleAnimMaskTilemap_LightBeam[] = INCBIN_U32("graphics/battle_anims/masks/light_beam.bin.lz");
BATTLE_ANIM_MASK_AND_BG_GFX static const u32 sBattleAnimDataAfterLightBeam[] = INCBIN_U32("graphics/battle_anims/unknown/jp/after_light_beam.bin");

#undef BATTLE_ANIM_MASK_AND_BG_GFX

#define BATTLE_ANIM_STAT_CHANGE_GFX __attribute__((section(".rodata.battle_anim_stat_change_graphics")))

BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Gfx[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Gfx.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Increase_Tilemap[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Increase_Tilemap.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Decrease_Tilemap[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Decrease_Tilemap.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Defense_Pal[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Defense_Pal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Attack_Pal[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Attack_Pal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Accuracy_Pal[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Accuracy_Pal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Speed_Pal[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Speed_Pal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Multiple_Pal[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Multiple_Pal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_Evasion_Pal[] = INCBIN_U32("graphics/battle_anims/gStatAnim_Evasion_Pal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_SpAttack_Pal[] = INCBIN_U32("graphics/battle_anims/gStatAnim_SpAttack_Pal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gStatAnim_SpDefense_Pal[] = INCBIN_U32("graphics/battle_anims/gStatAnim_SpDefense_Pal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesGfx[] = INCBIN_U32("graphics/misc/gCureBubblesGfx.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesPal[] = INCBIN_U32("graphics/misc/gCureBubblesPal.bin");
BATTLE_ANIM_STAT_CHANGE_GFX const u32 gCureBubblesTilemap[] = INCBIN_U32("graphics/misc/gCureBubblesTilemap.bin");

#undef BATTLE_ANIM_STAT_CHANGE_GFX

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

#undef RAYQUAZA_SCENE_1_GFX


// Rayquaza scene 2 smoke (RAY_ANIM_TAKES_FLIGHT)
#define RAYQUAZA_SCENE_2_SMOKE_GFX __attribute__((section(".rodata.rayquaza_scene_2_smoke_graphics")))

RAYQUAZA_SCENE_2_SMOKE_GFX const u32 gRaySceneTakesFlight_Smoke_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/smoke.4bpp.lz");
RAYQUAZA_SCENE_2_SMOKE_GFX const u32 gRaySceneTakesFlight_Smoke_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/smoke.gbapal.lz");

#undef RAYQUAZA_SCENE_2_SMOKE_GFX


// Rayquaza scene 2 shared palette and scene 3 sprites (RAY_ANIM_DESCENDS)
#define RAYQUAZA_SCENE_DESCENDS_SHARED_PAL __attribute__((section(".rodata.rayquaza_scene_descends_shared_pal")))
#define RAYQUAZA_SCENE_3_SPRITE_GFX __attribute__((section(".rodata.rayquaza_scene_3_sprite_graphics")))

RAYQUAZA_SCENE_DESCENDS_SHARED_PAL const u32 gRaySceneTakesFlight_Rayquaza_Pal[] = INCBIN_U32("graphics/rayquaza_scene/scene_2/rayquaza.gbapal.lz");
RAYQUAZA_SCENE_3_SPRITE_GFX const u32 gRaySceneDescends_Rayquaza_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/rayquaza.4bpp.lz");
RAYQUAZA_SCENE_3_SPRITE_GFX const u32 gRaySceneDescends_RayquazaTail_Gfx[] = INCBIN_U32("graphics/rayquaza_scene/scene_3/rayquaza_tail.4bpp.lz");

#undef RAYQUAZA_SCENE_DESCENDS_SHARED_PAL
#undef RAYQUAZA_SCENE_3_SPRITE_GFX
