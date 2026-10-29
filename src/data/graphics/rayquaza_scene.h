// JP scene resources occupy nine original linker input sections.

#define RAYQUAZA_SCENE_1_GFX __attribute__((section(".rodata.rayquaza_scene_1_graphics")))
#define RAYQUAZA_SCENE_2_SMOKE_GFX __attribute__((section(".rodata.rayquaza_scene_2_smoke_graphics")))
#define RAYQUAZA_SCENE_2_RAYQUAZA_GFX __attribute__((section(".rodata.rayquaza_scene_2_rayquaza_graphics")))
#define RAYQUAZA_SCENE_DESCENDS_SHARED_PAL __attribute__((section(".rodata.rayquaza_scene_descends_shared_pal")))
#define RAYQUAZA_SCENE_2_REMAINING_GFX __attribute__((section(".rodata.rayquaza_scene_2_remaining_graphics")))
#define RAYQUAZA_SCENE_3_SPRITE_GFX __attribute__((section(".rodata.rayquaza_scene_3_sprite_graphics")))
#define RAYQUAZA_SCENE_3_BG_GFX __attribute__((section(".rodata.rayquaza_scene_3_bg_graphics")))
#define RAYQUAZA_SCENE_4_GFX __attribute__((section(".rodata.rayquaza_scene_4_graphics")))
#define RAYQUAZA_SCENE_5_GFX __attribute__((section(".rodata.rayquaza_scene_5_graphics"), aligned(1)))

RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Groudon_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/groudon.png", ".4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_GroudonShoulder_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/groudon_shoulder.png", ".4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_GroudonClaw_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/groudon_claw.png", ".4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Kyogre_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/kyogre.png", ".4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_KyogrePectoralFin_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/kyogre_pectoral_fin.png", ".4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_KyogreDorsalFin_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/kyogre_dorsal_fin.png", ".4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Groudon_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/groudon.png", ".gbapal.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Kyogre_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/kyogre.png", ".gbapal.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds.png", ".4bpp.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds.png", ".gbapal.lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds1_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds1.bin", ".lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds2_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds2.bin", ".lz");
RAYQUAZA_SCENE_1_GFX const u32 gRaySceneDuoFight_Clouds3_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_1/clouds3.bin", ".lz");
RAYQUAZA_SCENE_2_SMOKE_GFX const u32 gRaySceneTakesFlight_Smoke_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_2/smoke.png", ".4bpp.lz");
RAYQUAZA_SCENE_2_SMOKE_GFX const u32 gRaySceneTakesFlight_Smoke_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_2/smoke.png", ".gbapal.lz");
RAYQUAZA_SCENE_2_RAYQUAZA_GFX const u32 gRaySceneTakesFlight_Rayquaza_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_2/rayquaza.png", ".8bpp.lz", "-num_tiles 227 -Wnum_tiles");
RAYQUAZA_SCENE_DESCENDS_SHARED_PAL const u32 gRaySceneTakesFlight_Rayquaza_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_2/rayquaza.png", ".gbapal.lz");
RAYQUAZA_SCENE_2_REMAINING_GFX const u32 gRaySceneTakesFlight_Rayquaza_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_2/rayquaza.bin", ".lz");
RAYQUAZA_SCENE_2_REMAINING_GFX const u32 gRaySceneTakesFlight_Bg_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_2/bg.png", ".4bpp.lz", "-num_tiles 313 -Wnum_tiles");
RAYQUAZA_SCENE_2_REMAINING_GFX const u32 gRaySceneTakesFlight_Bg_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_2/bg.bin", ".lz");
RAYQUAZA_SCENE_3_SPRITE_GFX const u32 gRaySceneDescends_Rayquaza_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_3/rayquaza.png", ".4bpp.lz", "-num_tiles 124 -Wnum_tiles");
RAYQUAZA_SCENE_3_SPRITE_GFX const u32 gRaySceneDescends_RayquazaTail_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_3/rayquaza_tail_fix.4bpp", ".lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Bg_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_3/bg.png", ".4bpp.lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Light_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_3/light.png", ".4bpp.lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Bg_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_3/bg.pal", ".gbapal.lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Bg_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_3/bg.bin", ".lz");
RAYQUAZA_SCENE_3_BG_GFX const u32 gRaySceneDescends_Light_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_3/light.bin", ".lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Bg_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/bg.png", ".4bpp.lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Bg_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/bg.bin", ".lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Streaks_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/streaks.png", ".4bpp.lz", "-num_tiles 19 -Wnum_tiles");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Streaks_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/streaks.bin", ".lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Rayquaza_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/rayquaza.png", ".4bpp.lz", "-num_tiles 155 -Wnum_tiles");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Rayquaza_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/rayquaza.bin", ".lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Orbs_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/orbs.bin", ".lz");
RAYQUAZA_SCENE_4_GFX const u32 gRaySceneCharges_Bg_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_4/bg.pal", ".gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Groudon_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/groudon.png", ".4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_GroudonTail_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/groudon_tail.png", ".4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Kyogre_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/kyogre.png", ".4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Rayquaza_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/rayquaza.png", ".4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_RayquazaTail_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/rayquaza_tail.png", ".4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_KyogreSplash_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.png", ".4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Groudon_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/groudon.png", ".gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Kyogre_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/kyogre.png", ".gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Rayquaza_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/rayquaza.png", ".gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_KyogreSplash_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/kyogre_splash.png", ".gbapal.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Light_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/light.png", ".4bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Ring_Gfx[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/ring.png", ".8bpp.lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Light_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/light.bin", ".lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Bg_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/bg.bin", ".lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Ring_Tilemap[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/ring.bin", ".lz");
RAYQUAZA_SCENE_5_GFX const u32 gRaySceneChasesAway_Bg_Pal[] = INCGFX_U32("graphics/rayquaza_scene/scene_5/bg.pal", ".gbapal.lz");

#undef RAYQUAZA_SCENE_1_GFX
#undef RAYQUAZA_SCENE_2_SMOKE_GFX
#undef RAYQUAZA_SCENE_2_RAYQUAZA_GFX
#undef RAYQUAZA_SCENE_DESCENDS_SHARED_PAL
#undef RAYQUAZA_SCENE_2_REMAINING_GFX
#undef RAYQUAZA_SCENE_3_SPRITE_GFX
#undef RAYQUAZA_SCENE_3_BG_GFX
#undef RAYQUAZA_SCENE_4_GFX
#undef RAYQUAZA_SCENE_5_GFX
