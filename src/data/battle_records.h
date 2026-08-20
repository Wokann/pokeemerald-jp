// JP Trainer Hill / link battle record resources in original ROM order.

#define BATTLE_RECORDS_DATA __attribute__((section(".rodata.battle_records_data"), aligned(1)))

const u8 sTrainerHillWindowTileset[0xC0] BATTLE_RECORDS_DATA = INCBIN_U8("graphics/trainer_hill/records_window_tiles.4bpp");
const u8 sTrainerHillWindowPalette[0x20] BATTLE_RECORDS_DATA = INCBIN_U8("graphics/trainer_hill/records_window_palette.gbapal");
const u8 sTrainerHillWindowTilemap[0x800] BATTLE_RECORDS_DATA = INCBIN_U8("graphics/trainer_hill/records_window_tilemap.tilemap");
const u8 sTrainerHillRecordsBgTemplates[0x8] BATTLE_RECORDS_DATA = INCBIN_U8("data/battle_records/jp/trainer_hill_records_bg_templates.bin");
const u8 sTrainerHillRecordsWindowTemplates[0x10] BATTLE_RECORDS_DATA = INCBIN_U8("data/battle_records/jp/trainer_hill_records_window_templates.bin");
const u8 sLinkBattleRecordsWindow[0x8] BATTLE_RECORDS_DATA = INCBIN_U8("data/battle_records/jp/link_battle_records_window_template.bin");

#undef BATTLE_RECORDS_DATA
