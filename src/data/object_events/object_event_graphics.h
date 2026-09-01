#ifndef GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H
#define GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H

// These JP-specific graphics are addressed by the recovered picture tables.
// Their binary owners remain in the original ROM layout pending source recovery.
extern const u32 gObjectEventPic_Vigoroth[];
extern const u32 gObjectEventPic_BirchsBag[0x20];
extern const u32 gObjectEventPic_EnemyZigzagoon[];
extern const u32 gObjectEventPic_Poochyena[];
extern const u32 gObjectEventPic_CableCar[0x200];
extern const u32 gObjectEventPic_SSTidal[0x1E0];
extern const u32 gObjectEventPic_QuintyPlump[];
extern const u32 gObjectEventPic_Juan[];
extern const u32 gObjectEventPic_Scott[];
extern const u32 gObjectEventPic_Statue[0x40];
extern const u32 gObjectEventPic_Kirlia[];
extern const u32 gObjectEventPic_Dusclops[];
extern const u32 gObjectEventPic_MysteryEventDeliveryman[];
extern const u32 gObjectEventPic_UnionRoomAttendant[];
extern const u32 gObjectEventPic_MovingBox[0x20];
extern const u32 gObjectEventPic_Sudowoodo[];
extern const u32 gObjectEventPic_Mew[];
extern const u32 gObjectEventPic_Red[];
extern const u32 gObjectEventPic_Leaf[];
extern const u32 gObjectEventPic_BirthIslandStone[0x80];
extern const u32 gObjectEventPic_Deoxys[];
extern const u32 gObjectEventPic_Anabel[];
extern const u32 gObjectEventPic_Tucker[];
extern const u32 gObjectEventPic_Spenser[];
extern const u32 gObjectEventPic_Greta[];
extern const u32 gObjectEventPic_Noland[];
extern const u32 gObjectEventPic_Lucy[];
extern const u32 gObjectEventPic_Brandon[];
extern const u32 gObjectEventPic_Lugia[];
extern const u32 gObjectEventPic_HoOh[];

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

// This JP-owned special object family follows the generic NPC people graphics.
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_ItemBall[] = INCBIN_U32("graphics/object_events/pics/misc/item_ball.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_ProfBirch[] = INCBIN_U32("graphics/object_events/pics/people/prof_birch.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_ReporterM[] = INCBIN_U32("graphics/object_events/pics/people/reporter_m.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_ReporterF[] = INCBIN_U32("graphics/object_events/pics/people/reporter_f.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_MauvilleOldMan1[] = INCBIN_U32("graphics/object_events/pics/people/mauville_old_man_1.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_MauvilleOldMan2[] = INCBIN_U32("graphics/object_events/pics/people/mauville_old_man_2.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_MartEmployee[] = INCBIN_U32("graphics/object_events/pics/people/mart_employee.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_RooftopSaleWoman[] = INCBIN_U32("graphics/object_events/pics/people/rooftop_sale_woman.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Teala[] = INCBIN_U32("graphics/object_events/pics/people/teala.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Artist[] = INCBIN_U32("graphics/object_events/pics/people/artist.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Cameraman[] = INCBIN_U32("graphics/object_events/pics/people/cameraman.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Scientist2[] = INCBIN_U32("graphics/object_events/pics/people/scientist_2.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_DevonEmployee[] = INCBIN_U32("graphics/object_events/pics/people/devon_employee.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_AquaMemberM[] = INCBIN_U32("graphics/object_events/pics/people/team_aqua/aqua_member_m.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_AquaMemberF[] = INCBIN_U32("graphics/object_events/pics/people/team_aqua/aqua_member_f.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_MagmaMemberM[] = INCBIN_U32("graphics/object_events/pics/people/team_magma/magma_member_m.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_MagmaMemberF[] = INCBIN_U32("graphics/object_events/pics/people/team_magma/magma_member_f.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Sidney[] = INCBIN_U32("graphics/object_events/pics/people/elite_four/sidney.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Phoebe[] = INCBIN_U32("graphics/object_events/pics/people/elite_four/phoebe.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Glacia[] = INCBIN_U32("graphics/object_events/pics/people/elite_four/glacia.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Drake[] = INCBIN_U32("graphics/object_events/pics/people/elite_four/drake.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Roxanne[] = INCBIN_U32("graphics/object_events/pics/people/gym_leaders/roxanne.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Brawly[] = INCBIN_U32("graphics/object_events/pics/people/gym_leaders/brawly.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Wattson[] = INCBIN_U32("graphics/object_events/pics/people/gym_leaders/wattson.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Flannery[] = INCBIN_U32("graphics/object_events/pics/people/gym_leaders/flannery.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Norman[] = INCBIN_U32("graphics/object_events/pics/people/gym_leaders/norman.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Winona[] = INCBIN_U32("graphics/object_events/pics/people/gym_leaders/winona.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Liza[] = INCBIN_U32("graphics/object_events/pics/people/gym_leaders/liza.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Tate[] = INCBIN_U32("graphics/object_events/pics/people/gym_leaders/tate.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Wallace[] = INCBIN_U32("graphics/object_events/pics/people/wallace.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Steven[] = INCBIN_U32("graphics/object_events/pics/people/steven.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Wally[] = INCBIN_U32("graphics/object_events/pics/people/wally.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_RubySapphireLittleBoy[] = INCBIN_U32("graphics/object_events/pics/people/rs_little_boy.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_HotSpringsOldWoman[] = INCBIN_U32("graphics/object_events/pics/people/hot_springs_old_woman.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_LatiasLatios[] = INCBIN_U32("graphics/object_events/pics/pokemon/latias_latios.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_GameboyKid[] = INCBIN_U32("graphics/object_events/pics/people/gameboy_kid.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_ContestJudge[] = INCBIN_U32("graphics/object_events/pics/people/contest_judge.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Archie[] = INCBIN_U32("graphics/object_events/pics/people/team_aqua/archie.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Maxie[] = INCBIN_U32("graphics/object_events/pics/people/team_magma/maxie.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Kyogre[] = INCBIN_U32("graphics/object_events/pics/pokemon/kyogre.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Groudon[] = INCBIN_U32("graphics/object_events/pics/pokemon/groudon.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Regi[] = INCBIN_U32("graphics/object_events/pics/pokemon/regi.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Skitty[] = INCBIN_U32("graphics/object_events/pics/pokemon/skitty.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Kecleon[] = INCBIN_U32("graphics/object_events/pics/pokemon/kecleon.4bpp");
// This symbol is also consumed by the pre-existing Rayquaza spotlight field effect.
// Keep its historical byte-pointer type so that consumer's declaration remains valid.
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u8 gObjectEventPic_Rayquaza[] = INCBIN_U8("graphics/object_events/pics/pokemon/rayquaza.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_RayquazaStill[] = INCBIN_U32("graphics/object_events/pics/pokemon/rayquaza_still.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Zigzagoon[] = INCBIN_U32("graphics/object_events/pics/pokemon/zigzagoon.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Pikachu[] = INCBIN_U32("graphics/object_events/pics/pokemon/pikachu.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Azumarill[] = INCBIN_U32("graphics/object_events/pics/pokemon/azumarill.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Wingull[] = INCBIN_U32("graphics/object_events/pics/pokemon/wingull.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_TuberMSwimming[] = INCBIN_U32("graphics/object_events/pics/people/tuber_m_swimming.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Azurill[] = INCBIN_U32("graphics/object_events/pics/pokemon/azurill.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u32 gObjectEventPic_Mom[] = INCBIN_U32("graphics/object_events/pics/people/mom.4bpp");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u16 gObjectEventPal_Kyogre[] = INCBIN_U16("graphics/object_events/palettes/kyogre.gbapal");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u16 gObjectEventPal_KyogreReflection[] = INCBIN_U16("graphics/object_events/palettes/kyogre_reflection.gbapal");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u16 gObjectEventPal_Groudon[] = INCBIN_U16("graphics/object_events/palettes/groudon.gbapal");
OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA const u16 gObjectEventPal_GroudonReflection[] = INCBIN_U16("graphics/object_events/palettes/groudon_reflection.gbapal");

// Dolls and cushions are a contiguous object-event graphics family in the JP ROM.
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_UnusedNatuDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/unused_natu_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_UnusedMagnemiteDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/unused_magnemite_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_UnusedSquirtleDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/unused_squirtle_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_UnusedWooperDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/unused_wooper_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_UnusedPikachuDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/unused_pikachu_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_UnusedPorygon2Doll[] = INCBIN_U32("graphics/object_events/pics/dolls/unused_porygon2_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_PichuDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/pichu_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_PikachuDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/pikachu_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_MarillDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/marill_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_TogepiDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/togepi_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_CyndaquilDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/cyndaquil_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_ChikoritaDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/chikorita_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_TotodileDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/totodile_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_JigglypuffDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/jigglypuff_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_MeowthDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/meowth_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_ClefairyDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/clefairy_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_DittoDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/ditto_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_SmoochumDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/smoochum_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_TreeckoDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/treecko_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_TorchicDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/torchic_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_MudkipDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/mudkip_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_DuskullDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/duskull_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_WynautDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/wynaut_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BaltoyDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/baltoy_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_KecleonDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/kecleon_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_AzurillDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/azurill_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_SkittyDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/skitty_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_SwabluDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/swablu_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_GulpinDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/gulpin_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_LotadDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/lotad_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_SeedotDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/seedot_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_PikaCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/pika_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_RoundCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/round_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_KissCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/kiss_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_ZigzagCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/zigzag_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_SpinCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/spin_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_DiamondCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/diamond_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BallCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/ball_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_GrassCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/grass_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_FireCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/fire_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_WaterCushion[] = INCBIN_U32("graphics/object_events/pics/cushions/water_cushion.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigSnorlaxDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_snorlax_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigRhydonDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_rhydon_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigLaprasDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_lapras_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigVenusaurDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_venusaur_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigCharizardDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_charizard_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigBlastoiseDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_blastoise_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigWailmerDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_wailmer_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigRegirockDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_regirock_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigRegiceDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_regice_doll.4bpp");
OBJECT_EVENT_GRAPHICS_DOLLS_DATA const u32 gObjectEventPic_BigRegisteelDoll[] = INCBIN_U32("graphics/object_events/pics/dolls/big_registeel_doll.4bpp");

// This JP-owned static misc-object graphics family follows the dolls and cushions.
OBJECT_EVENT_GRAPHICS_MISC_DATA const u32 gObjectEventPic_CuttableTree[] = INCBIN_U32("graphics/object_events/pics/misc/cuttable_tree.4bpp");
OBJECT_EVENT_GRAPHICS_MISC_DATA const u32 gObjectEventPic_BreakableRock[] = INCBIN_U32("graphics/object_events/pics/misc/breakable_rock.4bpp");
OBJECT_EVENT_GRAPHICS_MISC_DATA const u32 gObjectEventPic_PushableBoulder[] = INCBIN_U32("graphics/object_events/pics/misc/pushable_boulder.4bpp");
OBJECT_EVENT_GRAPHICS_MISC_DATA const u32 gObjectEventPic_MrBrineysBoat[] = INCBIN_U32("graphics/object_events/pics/misc/mr_brineys_boat.4bpp");
OBJECT_EVENT_GRAPHICS_MISC_DATA const u32 gObjectEventPic_Fossil[] = INCBIN_U32("graphics/object_events/pics/misc/fossil.4bpp");
OBJECT_EVENT_GRAPHICS_MISC_DATA const u32 gObjectEventPic_SubmarineShadow[] = INCBIN_U32("graphics/object_events/pics/misc/submarine_shadow.4bpp");
OBJECT_EVENT_GRAPHICS_MISC_DATA const u16 gObjectEventPal_SubmarineShadow[] = INCBIN_U16("graphics/object_events/palettes/submarine_shadow.gbapal");
OBJECT_EVENT_GRAPHICS_MISC_DATA const u32 gObjectEventPic_Truck[] = INCBIN_U32("graphics/object_events/pics/misc/truck.4bpp");
OBJECT_EVENT_GRAPHICS_MISC_DATA const u16 gObjectEventPal_Truck[] = INCBIN_U16("graphics/object_events/palettes/truck.gbapal");

OBJECT_EVENT_GRAPHICS_CUT_GRASS const u8 gFieldEffectPic_CutGrass[] = INCBIN_U8("graphics/field_effects/pics/cut_grass.4bpp");
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u32 gFieldEffectPic_CutGrass_Copy[] = INCBIN_U32("graphics/field_effects/pics/cut_grass.4bpp");
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u16 gFieldEffectPal_CutGrass[] = INCBIN_U16("graphics/field_effects/palettes/cut_grass.gbapal");

// These two palettes are physically later in the JP ROM than the Cut Grass data.
OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES const u16 gFieldEffectObjectPalette0[] = INCBIN_U16("graphics/field_effects/palettes/general_0.gbapal");
OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES const u16 gFieldEffectObjectPalette1[] = INCBIN_U16("graphics/field_effects/palettes/general_1.gbapal");

#endif // GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H
