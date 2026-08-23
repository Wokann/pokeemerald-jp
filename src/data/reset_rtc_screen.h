// JP Reset RTC screen resources retained in original ROM order.

#define RESET_RTC_SCREEN_DATA __attribute__((section(".rodata.reset_rtc_screen_data"), aligned(1)))
#define RESET_RTC_SCREEN_TEMPLATES __attribute__((section(".rodata.reset_rtc_screen_templates"), aligned(4)))

const struct BgTemplate gResetRtcBgTemplates[] RESET_RTC_SCREEN_TEMPLATES =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

const struct WindowTemplate gResetRtcWindowTemplates[] RESET_RTC_SCREEN_TEMPLATES =
{
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 1,
        .width = 19,
        .height = 9,
        .paletteNum = 15,
        .baseBlock = 0x155,
    },
    {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 15,
        .width = 22,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xFD,
    },
    DUMMY_WIN_TEMPLATE,
};

const struct WindowTemplate gResetRtcInputTimeWindow RESET_RTC_SCREEN_TEMPLATES =
{
    .bg = 0,
    .tilemapLeft = 4,
    .tilemapTop = 9,
    .width = 21,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0xD3,
};

const u8 sText_ResetRtcConfirm[0x43] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/confirm_label.bin");
const u8 sOamData_Arrow[0x8] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_oam.bin");
const u8 sArrowGfx[0x48] RESET_RTC_SCREEN_DATA = INCBIN_U8("graphics/reset_rtc_screen/arrow.4bpp");
const u8 sArrowImages[0x10] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_images.bin");
const u8 gResetRtcArrowPalette[0x8] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_palette.bin");
const u8 sAnim_Arrow_Down[0x8] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_anim_down.bin");
const u8 sAnim_Arrow_Up[0x8] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_anim_up.bin");
const u8 sAnim_Arrow_Right[0x8] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_anim_right.bin");
const u8 sAnims_Arrow[0xC] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_anims.bin");
const u8 gResetRtcArrowSpriteTemplate[0x18] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_sprite_template.bin");
const u8 sResetRtcArrowPostTemplateData[0x4] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/arrow_post_template_data.bin");
const u8 sResetRtcScreenTrailingData[0x28] RESET_RTC_SCREEN_DATA = INCBIN_U8("data/reset_rtc_screen/jp/trailing_data.bin");

#undef RESET_RTC_SCREEN_DATA
#undef RESET_RTC_SCREEN_TEMPLATES

// Retain the JP labels used by reset_rtc_screen.c and start_menu.c.
__asm__(
    ".global gUnknown_84E8A71\n"
    ".set gUnknown_84E8A71, sText_ResetRtcConfirm\n"
    ".global gUnknown_84E8B58\n"
    ".set gUnknown_84E8B58, sResetRtcArrowPostTemplateData\n"
    ".global gUnknown_84E8B5C\n"
    ".set gUnknown_84E8B5C, sResetRtcScreenTrailingData\n"
);
