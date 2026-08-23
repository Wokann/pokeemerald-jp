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

// This JP-owned generic NPC graphics family follows the May action graphics.
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u16 gObjectEventPal_Npc1[] = INCBIN_U16("graphics/object_events/palettes/npc_1.gbapal");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u16 gObjectEventPal_Npc2[] = INCBIN_U16("graphics/object_events/palettes/npc_2.gbapal");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u16 gObjectEventPal_Npc3[] = INCBIN_U16("graphics/object_events/palettes/npc_3.gbapal");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u16 gObjectEventPal_Npc4[] = INCBIN_U16("graphics/object_events/palettes/npc_4.gbapal");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u16 gObjectEventPal_Npc1Reflection[] = INCBIN_U16("graphics/object_events/palettes/npc_1_reflection.gbapal");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u16 gObjectEventPal_Npc2Reflection[] = INCBIN_U16("graphics/object_events/palettes/npc_2_reflection.gbapal");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u16 gObjectEventPal_Npc3Reflection[] = INCBIN_U16("graphics/object_events/palettes/npc_3_reflection.gbapal");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u16 gObjectEventPal_Npc4Reflection[] = INCBIN_U16("graphics/object_events/palettes/npc_4_reflection.gbapal");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_NinjaBoy[] = INCBIN_U32("graphics/object_events/pics/people/ninja_boy.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Twin[] = INCBIN_U32("graphics/object_events/pics/people/twin.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Boy1[] = INCBIN_U32("graphics/object_events/pics/people/boy_1.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Girl1[] = INCBIN_U32("graphics/object_events/pics/people/girl_1.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Boy2[] = INCBIN_U32("graphics/object_events/pics/people/boy_2.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Girl2[] = INCBIN_U32("graphics/object_events/pics/people/girl_2.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_LittleBoy[] = INCBIN_U32("graphics/object_events/pics/people/little_boy.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_LittleGirl[] = INCBIN_U32("graphics/object_events/pics/people/little_girl.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Boy3[] = INCBIN_U32("graphics/object_events/pics/people/boy_3.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Girl3[] = INCBIN_U32("graphics/object_events/pics/people/girl_3.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_RichBoy[] = INCBIN_U32("graphics/object_events/pics/people/rich_boy.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Woman1[] = INCBIN_U32("graphics/object_events/pics/people/woman_1.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_FatMan[] = INCBIN_U32("graphics/object_events/pics/people/fat_man.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_PokefanF[] = INCBIN_U32("graphics/object_events/pics/people/pokefan_f.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Man1[] = INCBIN_U32("graphics/object_events/pics/people/man_1.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Woman2[] = INCBIN_U32("graphics/object_events/pics/people/woman_2.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_ExpertM[] = INCBIN_U32("graphics/object_events/pics/people/expert_m.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_ExpertF[] = INCBIN_U32("graphics/object_events/pics/people/expert_f.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Man2[] = INCBIN_U32("graphics/object_events/pics/people/man_2.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Woman3[] = INCBIN_U32("graphics/object_events/pics/people/woman_3.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_PokefanM[] = INCBIN_U32("graphics/object_events/pics/people/pokefan_m.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Woman4[] = INCBIN_U32("graphics/object_events/pics/people/woman_4.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Cook[] = INCBIN_U32("graphics/object_events/pics/people/cook.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_LinkReceptionist[] = INCBIN_U32("graphics/object_events/pics/people/link_receptionist.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_OldMan[] = INCBIN_U32("graphics/object_events/pics/people/old_man.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_OldWoman[] = INCBIN_U32("graphics/object_events/pics/people/old_woman.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Camper[] = INCBIN_U32("graphics/object_events/pics/people/camper.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Picnicker[] = INCBIN_U32("graphics/object_events/pics/people/picnicker.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Man3[] = INCBIN_U32("graphics/object_events/pics/people/man_3.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Woman5[] = INCBIN_U32("graphics/object_events/pics/people/woman_5.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Youngster[] = INCBIN_U32("graphics/object_events/pics/people/youngster.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_BugCatcher[] = INCBIN_U32("graphics/object_events/pics/people/bug_catcher.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_PsychicM[] = INCBIN_U32("graphics/object_events/pics/people/psychic_m.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_SchoolKidM[] = INCBIN_U32("graphics/object_events/pics/people/school_kid_m.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_Maniac[] = INCBIN_U32("graphics/object_events/pics/people/maniac.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA const u32 gObjectEventPic_HexManiac[] = INCBIN_U32("graphics/object_events/pics/people/hex_maniac.4bpp");

// This JP-owned continuation keeps the remaining generic people graphics in ROM order.
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_UnusedWoman[] = INCBIN_U32("graphics/object_events/pics/people/unused_woman.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_SwimmerM[] = INCBIN_U32("graphics/object_events/pics/people/swimmer_m.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_SwimmerF[] = INCBIN_U32("graphics/object_events/pics/people/swimmer_f.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_BlackBelt[] = INCBIN_U32("graphics/object_events/pics/people/black_belt.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Beauty[] = INCBIN_U32("graphics/object_events/pics/people/beauty.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Scientist1[] = INCBIN_U32("graphics/object_events/pics/people/scientist_1.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Lass[] = INCBIN_U32("graphics/object_events/pics/people/lass.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Gentleman[] = INCBIN_U32("graphics/object_events/pics/people/gentleman.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Sailor[] = INCBIN_U32("graphics/object_events/pics/people/sailor.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Fisherman[] = INCBIN_U32("graphics/object_events/pics/people/fisherman.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_RunningTriathleteM[] = INCBIN_U32("graphics/object_events/pics/people/running_triathlete_m.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_RunningTriathleteF[] = INCBIN_U32("graphics/object_events/pics/people/running_triathlete_f.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_TuberF[] = INCBIN_U32("graphics/object_events/pics/people/tuber_f.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_TuberM[] = INCBIN_U32("graphics/object_events/pics/people/tuber_m.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Hiker[] = INCBIN_U32("graphics/object_events/pics/people/hiker.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_CyclingTriathleteM[] = INCBIN_U32("graphics/object_events/pics/people/cycling_triathlete_m.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_CyclingTriathleteF[] = INCBIN_U32("graphics/object_events/pics/people/cycling_triathlete_f.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Man4[] = INCBIN_U32("graphics/object_events/pics/people/man_4.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Man5[] = INCBIN_U32("graphics/object_events/pics/people/man_5.4bpp");
OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA const u32 gObjectEventPic_Nurse[] = INCBIN_U32("graphics/object_events/pics/people/nurse.4bpp");

OBJECT_EVENT_GRAPHICS_CUT_GRASS const u8 gFieldEffectPic_CutGrass[] = INCBIN_U8("graphics/field_effects/pics/cut_grass.4bpp");
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u32 gFieldEffectPic_CutGrass_Copy[] = INCBIN_U32("graphics/field_effects/pics/cut_grass.4bpp");
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u16 gFieldEffectPal_CutGrass[] = INCBIN_U16("graphics/field_effects/palettes/cut_grass.gbapal");

// These two palettes are physically later in the JP ROM than the Cut Grass data.
OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES const u16 gFieldEffectObjectPalette0[] = INCBIN_U16("graphics/field_effects/palettes/general_0.gbapal");
OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES const u16 gFieldEffectObjectPalette1[] = INCBIN_U16("graphics/field_effects/palettes/general_1.gbapal");

#endif // GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H
