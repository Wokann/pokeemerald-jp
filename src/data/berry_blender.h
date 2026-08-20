// JP Berry Blender resources retained in original ROM order.  Filenames use
// their original addresses until each resource's semantic name is verified.

#define BERRY_BLENDER_RESOURCES __attribute__((section(".rodata.berry_blender_resources"), aligned(1)))

const u8 gUnknown_830D354[0x20] BERRY_BLENDER_RESOURCES = INCBIN_U8("graphics/berry_blender/jp/830d354.bin");
const u8 gUnknown_830D374[0x400] BERRY_BLENDER_RESOURCES = INCBIN_U8("graphics/berry_blender/jp/830d374.bin");
const u8 gUnknown_830D774[0x1F3A] BERRY_BLENDER_RESOURCES = INCBIN_U8("graphics/berry_blender/jp/830d774.bin");

#undef BERRY_BLENDER_RESOURCES
