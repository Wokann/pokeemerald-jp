#ifndef GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H
#define GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H

// This JP-owned subset is emitted by event_object_movement.c at its original ROM range.
OBJECT_EVENT_GRAPHICS_PLAYER_DATA const u32 gObjectEventPic_BrendanNormal[] = INCBIN_U32("graphics/object_events/pics/people/brendan/walking.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_DATA const u32 gObjectEventPic_BrendanRunning[] = INCBIN_U32("graphics/object_events/pics/people/brendan/running.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_DATA const u16 gObjectEventPal_Brendan[] = INCBIN_U16("graphics/object_events/palettes/brendan.gbapal");
OBJECT_EVENT_GRAPHICS_PLAYER_DATA const u32 gObjectEventPic_RubySapphireBrendanNormal[] = INCBIN_U32("graphics/object_events/pics/people/ruby_sapphire_brendan/walking.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_DATA const u32 gObjectEventPic_RubySapphireBrendanRunning[] = INCBIN_U32("graphics/object_events/pics/people/ruby_sapphire_brendan/running.4bpp");

// This JP-owned player graphics family follows the Brendan base data in ROM.
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_RubySapphireBrendan[] = INCBIN_U16("graphics/object_events/palettes/ruby_sapphire_brendan.gbapal");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null1[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null2[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null3[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null4[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null5[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null6[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null7[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null8[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null9[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null10[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null11[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null12[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null13[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null14[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_Null15[16] = {};
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_BrendanReflection[] = INCBIN_U16("graphics/object_events/palettes/brendan_reflection.gbapal");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_BridgeReflection[] = INCBIN_U16("graphics/object_events/palettes/bridge_reflection.gbapal");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_BrendanFieldMove[] = INCBIN_U32("graphics/object_events/pics/people/brendan/field_move.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_BrendanSurfing[] = INCBIN_U32("graphics/object_events/pics/people/brendan/surfing.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_BrendanMachBike[] = INCBIN_U32("graphics/object_events/pics/people/brendan/mach_bike.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_BrendanAcroBike[] = INCBIN_U32("graphics/object_events/pics/people/brendan/acro_bike.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_BrendanFishing[] = INCBIN_U32("graphics/object_events/pics/people/brendan/fishing.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_BrendanWatering[] = INCBIN_U32("graphics/object_events/pics/people/brendan/watering.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_BrendanDecorating[] = INCBIN_U32("graphics/object_events/pics/people/brendan/decorating.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_MayDecorating[] = INCBIN_U32("graphics/object_events/pics/people/may/decorating.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_BrendanUnderwater[] = INCBIN_U32("graphics/object_events/pics/people/brendan/underwater.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_MayUnderwater[] = INCBIN_U32("graphics/object_events/pics/people/may/underwater.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u16 gObjectEventPal_PlayerUnderwater[] = INCBIN_U16("graphics/object_events/palettes/player_underwater.gbapal");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_MayNormal[] = INCBIN_U32("graphics/object_events/pics/people/may/walking.4bpp");
OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA const u32 gObjectEventPic_MayRunning[] = INCBIN_U32("graphics/object_events/pics/people/may/running.4bpp");

// This JP-owned May base graphics family follows the extended player graphics.
OBJECT_EVENT_GRAPHICS_MAY_BASE_DATA const u16 gObjectEventPal_May[] = INCBIN_U16("graphics/object_events/palettes/may.gbapal");
OBJECT_EVENT_GRAPHICS_MAY_BASE_DATA const u16 gObjectEventPal_MayReflection[] = INCBIN_U16("graphics/object_events/palettes/may_reflection.gbapal");
OBJECT_EVENT_GRAPHICS_MAY_BASE_DATA const u32 gObjectEventPic_RubySapphireMayNormal[] = INCBIN_U32("graphics/object_events/pics/people/ruby_sapphire_may/walking.4bpp");
OBJECT_EVENT_GRAPHICS_MAY_BASE_DATA const u32 gObjectEventPic_RubySapphireMayRunning[] = INCBIN_U32("graphics/object_events/pics/people/ruby_sapphire_may/running.4bpp");

// This JP-owned May action graphics family follows the Ruby/Sapphire May base graphics.
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_RubySapphireMay[] = INCBIN_U16("graphics/object_events/palettes/ruby_sapphire_may.gbapal");
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gUnusedObjectEventPalette[] = INCBIN_U16("graphics/object_events/palettes/unused_palette.gbapal");
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null16[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null17[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null18[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null19[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null20[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null21[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null22[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null23[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null24[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null25[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null26[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null27[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null28[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u16 gObjectEventPal_Null29[16] = {};
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u32 gObjectEventPic_MayMachBike[] = INCBIN_U32("graphics/object_events/pics/people/may/mach_bike.4bpp");
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u32 gObjectEventPic_MayAcroBike[] = INCBIN_U32("graphics/object_events/pics/people/may/acro_bike.4bpp");
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u32 gObjectEventPic_MaySurfing[] = INCBIN_U32("graphics/object_events/pics/people/may/surfing.4bpp");
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u32 gObjectEventPic_MayFieldMove[] = INCBIN_U32("graphics/object_events/pics/people/may/field_move.4bpp");
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u32 gObjectEventPic_MayFishing[] = INCBIN_U32("graphics/object_events/pics/people/may/fishing.4bpp");
OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA const u32 gObjectEventPic_MayWatering[] = INCBIN_U32("graphics/object_events/pics/people/may/watering.4bpp");

OBJECT_EVENT_GRAPHICS_CUT_GRASS const u8 gFieldEffectPic_CutGrass[] = INCBIN_U8("graphics/field_effects/pics/cut_grass.4bpp");
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u32 gFieldEffectPic_CutGrass_Copy[] = INCBIN_U32("graphics/field_effects/pics/cut_grass.4bpp");
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u16 gFieldEffectPal_CutGrass[] = INCBIN_U16("graphics/field_effects/palettes/cut_grass.gbapal");

// These two palettes are physically later in the JP ROM than the Cut Grass data.
OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES const u16 gFieldEffectObjectPalette0[] = INCBIN_U16("graphics/field_effects/palettes/general_0.gbapal");
OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES const u16 gFieldEffectObjectPalette1[] = INCBIN_U16("graphics/field_effects/palettes/general_1.gbapal");

#endif // GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H
