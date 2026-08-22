// These have Berry Blender semantics, but this dedicated data object supplies
// the binary initializer because the implementation's generic agbcc rule does
// not run the INCBIN preprocessor. External linkage preserves old ROM aliases.
#define BERRY_BLENDER_BACKGROUND_DATA __attribute__((section(".rodata.berry_blender_background_data"), aligned(1)))

const u16 sBlenderCenter_Pal[] BERRY_BLENDER_BACKGROUND_DATA = INCBIN_U16("graphics/berry_blender/center.gbapal");
const u16 sBlenderCenter_Tilemap[] BERRY_BLENDER_BACKGROUND_DATA = INCBIN_U16("graphics/berry_blender/center_map.bin");
const u16 sBlenderOuter_Pal[] BERRY_BLENDER_BACKGROUND_DATA = INCBIN_U16("graphics/berry_blender/outer.gbapal");

#undef BERRY_BLENDER_BACKGROUND_DATA

// Keep the unclassified suffix separate so it cannot be accidentally assigned
// the same semantics as the verified Berry Blender background resources.
#define BERRY_BLENDER_RESOURCES_AFTER_BACKGROUND_DATA __attribute__((section(".rodata.berry_blender_resources_after_background_data"), aligned(1)))

const u8 gUnknown_830D794[0x1F1A] BERRY_BLENDER_RESOURCES_AFTER_BACKGROUND_DATA = INCBIN_U8("graphics/berry_blender/jp/830d794.bin");

#undef BERRY_BLENDER_RESOURCES_AFTER_BACKGROUND_DATA
