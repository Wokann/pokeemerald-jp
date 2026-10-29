// Keep the unclassified suffix separate so it cannot be accidentally assigned
// the same semantics as the verified Berry Blender background resources.
#define BERRY_BLENDER_RESOURCES_AFTER_BACKGROUND_DATA __attribute__((section(".rodata.berry_blender_resources_after_background_data"), aligned(1)))

const u8 gUnknown_830D794[0x1F1A] BERRY_BLENDER_RESOURCES_AFTER_BACKGROUND_DATA = INCBIN_U8("graphics/berry_blender/jp/830d794.bin");

#undef BERRY_BLENDER_RESOURCES_AFTER_BACKGROUND_DATA
