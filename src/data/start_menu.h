// JP Start Menu data kept in its original ROM order.  The names follow the
// corresponding US tables; the byte content remains JP-specific.

#define START_MENU_RESOURCES __attribute__((section(".rodata.start_menu_resources"), aligned(1)))

const u8 sWindowTemplate_SafariBalls[0x8] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/window_template_safari_balls.bin");
const u8 sPyramidFloorNameTexts[0x60] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/pyramid_floor_name_texts.bin");
const u8 sPyramidFloorNames[0x20] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/pyramid_floor_names.bin");
const u8 sWindowTemplate_PyramidFloor[0x8] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/window_template_pyramid_floor.bin");
const u8 sWindowTemplate_PyramidPeak[0x8] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/window_template_pyramid_peak.bin");
const u8 sStartMenuItems[0x68] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/start_menu_items.bin");
const u8 sBgTemplates_LinkBattleSave[0x4] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/bg_templates_link_battle_save.bin");
const u8 sWindowTemplates_LinkBattleSave[0x10] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/window_templates_link_battle_save.bin");
const u8 sSaveInfoWindowTemplate[0x8] START_MENU_RESOURCES = INCBIN_U8("data/start_menu/jp/save_info_window_template.bin");

#undef START_MENU_RESOURCES

// Existing JP implementation code still refers to the original assembler
// labels.  Preserve them while exposing the source-aligned names above.
__asm__(
    ".global gUnknown_84E8B94\n"
    ".set gUnknown_84E8B94, sWindowTemplate_SafariBalls\n"
    ".global gUnknown_84E8B9C\n"
    ".set gUnknown_84E8B9C, sPyramidFloorNameTexts\n"
    ".global gUnknown_84E8BFC\n"
    ".set gUnknown_84E8BFC, sPyramidFloorNames\n"
    ".global gUnknown_84E8C1C\n"
    ".set gUnknown_84E8C1C, sWindowTemplate_PyramidFloor\n"
    ".global gUnknown_84E8C24\n"
    ".set gUnknown_84E8C24, sWindowTemplate_PyramidPeak\n"
    ".global gUnknown_84E8C2C\n"
    ".set gUnknown_84E8C2C, sStartMenuItems\n"
    ".global gUnknown_84E8C94\n"
    ".set gUnknown_84E8C94, sBgTemplates_LinkBattleSave\n"
    ".global gUnknown_84E8C98\n"
    ".set gUnknown_84E8C98, sWindowTemplates_LinkBattleSave\n"
    ".global gUnknown_84E8CA8\n"
    ".set gUnknown_84E8CA8, sSaveInfoWindowTemplate\n"
);
