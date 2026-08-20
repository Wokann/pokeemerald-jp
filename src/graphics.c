#include "global.h"

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
