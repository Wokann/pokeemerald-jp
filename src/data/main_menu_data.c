#include "global.h"
#include "main_menu_data.h"

// 0x82D2588 - birch-speech background palettes.
const u16 sBirchSpeechBgPals[][16] =
{
    {0x0000, 0x53FF, 0x37FF, 0x2F7B, 0x26F7, 0x1E73, 0x19EF, 0x116B, 0x08E7, 0x67F8, 0x43EF, 0x376E, 0x2EED, 0x226C, 0x19EB, 0x0000},
    {0x0000, 0x53FF, 0x37FF, 0x2F7B, 0x26F7, 0x1E73, 0x19EF, 0x116B, 0x08E7, 0x67F8, 0x43EF, 0x376E, 0x2EED, 0x226C, 0x19EB, 0x0000},
};
// 0x82D25C8 - birch-speech shadow gfx (LZ, decompresses to 0x600).
const u32 sBirchSpeechShadowGfx[] =
{
    0x00060010, 0xF0000032, 0x99019001, 0xAA01B099,
    0x01B0AA49, 0x01B0BBBB, 0x01B0CCCC, 0xB0DDDD24,
    0xB0EEEE01, 0x93777701, 0x888801B0, 0xFFFF01B0,
    0x019001F0, 0xF0B1F0FF, 0xF001F001, 0xF001F001,
    0xF001F001, 0x01F0FF01, 0x01F001F0, 0x01F001F0,
    0x01F001F0, 0xF0FC01F0, 0xF101B001, 0xF001F051,
    0x8F011001, 0x88FF0878, 0x17F04457, 0x00887888,
    0x45444578, 0x13111234, 0x11111110, 0x888F1890,
    0x57075778, 0x23223445, 0x01501700, 0x88001B50,
    0x45777888, 0xE0222334, 0x1F601A80, 0x44550712,
    0xD8123334, 0x01001CD0, 0x021B008F, 0x22226736,
    0x3BE02270, 0x3B100110, 0x66666666, 0x301FF0C0,
    0x23457801, 0x00557811, 0x578F1234, 0x78FF2445,
    0xFF455502, 0x0055778F, 0x00BA6771, 0x7B107876,
    0x7B102750, 0x45040023, 0x55040080, 0x67223455,
    0x45065555, 0x55567778, 0x2B4051F0, 0x27009F22,
    0x73F03344, 0x1CF00180, 0x01F001F0, 0xF001F0FC,
    0xF001F001, 0x007FA101, 0x003558EB, 0x12358FFF,
    0x112458FF, 0x13458F14, 0x40121701, 0xFF111303,
    0xD320CA01, 0x01F001F0, 0x01F001F0, 0x01F001F0,
    0xF001F0FF, 0xF001F001, 0xF001F001, 0xA201F0FF,
    0x0B02B5CE, 0x4087F48F, 0x07025501, 0xF40C0277,
    0x2700BE02, 0xD202AFF4, 0x34220022, 0x2800D756,
    0x0366A602, 0x55107703, 0x83101F50, 0x002200CC,
    0x00344423, 0x66230022, 0x0B13E966, 0x4F522350,
    0x55232033, 0xE1473055, 0x9F922735, 0x4444DF12,
    0x23104444, 0x78EF12BE, 0x38132300, 0x1F301FF0,
    0x00004350,
};

// 0x82D277C - birch-speech bg tilemap (LZ, decompresses to 0x500).
const u8 sBirchSpeechBgMap[] =
{
    0x10, 0x00, 0x05, 0x00, 0x3D, 0x01, 0x10, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0x50, 0x01, 0x02,
    0xF0, 0x01, 0xEF, 0xF0, 0x01, 0xF0, 0x01, 0x60, 0x01, 0x03, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01,
    0x60, 0x01, 0x79, 0x04, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0x60, 0x01, 0x05, 0x00, 0xF0, 0x01,
    0xFF, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0,
    0x01, 0xFF, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01,
    0xF0, 0x01, 0xC0, 0xF0, 0x01, 0x50, 0x01, 0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x00, 0x13, 0x00,
    0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x00, 0x17, 0x00, 0x17, 0x04, 0x16, 0x04, 0x15, 0x04, 0x01,
    0x14, 0x04, 0x13, 0x04, 0x12, 0x04, 0x11, 0x01, 0x6E, 0xC0, 0xF0, 0x31, 0xB0, 0x01, 0x20, 0x00,
    0x21, 0x00, 0x22, 0x00, 0x00, 0x23, 0x00, 0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x00, 0x27, 0x00,
    0x27, 0x04, 0x26, 0x04, 0x25, 0x04, 0x00, 0x24, 0x04, 0x23, 0x04, 0x22, 0x04, 0x21, 0x04, 0x60,
    0x20, 0xF0, 0x3F, 0xC0, 0x01, 0x18, 0x00, 0x19, 0x00, 0x1A, 0x00, 0x00, 0x1B, 0x00, 0x1C, 0x00,
    0x1D, 0x00, 0x1E, 0x00, 0x00, 0x1F, 0x00, 0x1F, 0x04, 0x1E, 0x04, 0x1D, 0x00, 0x04, 0x1C, 0x04,
    0x1B, 0x04, 0x1A, 0x04, 0x19, 0x30, 0x04, 0x18, 0xF0, 0x3F, 0xC0, 0x01, 0x28, 0x00, 0x29, 0x00,
    0x00, 0x2A, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x2F, 0x04,
    0x2E, 0x04, 0x00, 0x2D, 0x04, 0x2C, 0x04, 0x2B, 0x04, 0x2A, 0x04, 0x1F, 0x29, 0x04, 0x28, 0xF0,
    0x3F, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xFF, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01,
    0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xFF, 0xF0, 0x01, 0xF0, 0x01, 0xF0,
    0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF0, 0x01, 0xF8, 0xF0, 0x01, 0xF0, 0x01,
    0xF0, 0x01, 0xF0, 0x01, 0xE0, 0x01, 0x00, 0x00, 0x0A, 0xFF,
};

// 0x82D28A6 - birch-speech bg gradient palette (16 colors).
const u16 sBirchSpeechBgGradientPal[] =
{
    0x53FF, 0x37FF, 0x2F7B, 0x26F7, 0x1E73, 0x19EF, 0x116B, 0x08E7,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// 0x82D28C6 - pad bytes between the gradient palette and the window templates.
const u16 gUnknown_82D28C6 = 0;

#define MENU_LEFT 2
#define MENU_TOP_WIN0 1
#define MENU_TOP_WIN1 5
#define MENU_TOP_WIN2 1
#define MENU_TOP_WIN3 9
#define MENU_TOP_WIN4 13
#define MENU_TOP_WIN5 17
#define MENU_TOP_WIN6 21
#define MENU_WIDTH 26
#define MENU_HEIGHT_WIN0 2
#define MENU_HEIGHT_WIN1 2
#define MENU_HEIGHT_WIN2 6
#define MENU_HEIGHT_WIN3 2
#define MENU_HEIGHT_WIN4 2
#define MENU_HEIGHT_WIN5 2
#define MENU_HEIGHT_WIN6 2

#define MENU_LEFT_ERROR 2
#define MENU_TOP_ERROR 15
#define MENU_WIDTH_ERROR 26
#define MENU_HEIGHT_ERROR 4

// 0x82D28C8 - main menu window templates (values match pokeemerald).
const struct WindowTemplate sWindowTemplates_MainMenu[] =
{
    // No saved game
    // NEW GAME
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN0,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN0,
        .paletteNum = 15,
        .baseBlock = 1
    },
    // OPTIONS
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN1,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN1,
        .paletteNum = 15,
        .baseBlock = 0x35
    },
    // Has saved game
    // CONTINUE
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN2,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    // NEW GAME
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN3,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN3,
        .paletteNum = 15,
        .baseBlock = 0x9D
    },
    // OPTION / MYSTERY GIFT
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN4,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN4,
        .paletteNum = 15,
        .baseBlock = 0xD1
    },
    // OPTION / MYSTERY EVENTS
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN5,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN5,
        .paletteNum = 15,
        .baseBlock = 0x105
    },
    // OPTION
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT,
        .tilemapTop = MENU_TOP_WIN6,
        .width = MENU_WIDTH,
        .height = MENU_HEIGHT_WIN6,
        .paletteNum = 15,
        .baseBlock = 0x139
    },
    // Error message window
    {
        .bg = 0,
        .tilemapLeft = MENU_LEFT_ERROR,
        .tilemapTop = MENU_TOP_ERROR,
        .width = MENU_WIDTH_ERROR,
        .height = MENU_HEIGHT_ERROR,
        .paletteNum = 15,
        .baseBlock = 0x16D
    },
    DUMMY_WIN_TEMPLATE
};
// 0x82D2910 - new-game birch speech text windows (JP values).
const struct WindowTemplate sNewGameBirchSpeechTextWindows[] =
{
    {
        .bg = 0,
        .tilemapLeft = 4,
        .tilemapTop = 15,
        .width = 22,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 5,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x59
    },
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 2,
        .width = 9,
        .height = 10,
        .paletteNum = 15,
        .baseBlock = 0x6D
    },
    DUMMY_WIN_TEMPLATE
};

// 0x82D2930
const u16 sMainMenuBgPal[] =
{
    0x7E51, 0x7FFF, 0x28E6, 0x398B, 0x0821, 0x5672, 0x7779, 0x5ED6, 0x6F37, 0x1884, 0x460F, 0x3D46, 0x61E5, 0x6A27, 0x728B, 0x7B11,
};

// 0x82D2950
const u16 sMainMenuTextPal[] =
{
    0x7FFF, 0x7FFF, 0x318C, 0x675A, 0x043C, 0x3AFF, 0x0664, 0x4BD2, 0x6546, 0x7B14, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

// 0x82D2970 - declared as struct TextColor by src/main_menu.c.
const u8 sTextColor_Headers[3] =
{
    TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2, TEXT_DYNAMIC_COLOR_3,
};

// 0x82D2973 - JP variant of US sTextColor_MenuInfo with 2 trailing pad bytes.
const u8 sTextColor_Savegame[5] =
{
    TEXT_DYNAMIC_COLOR_1, TEXT_COLOR_WHITE, TEXT_DYNAMIC_COLOR_3, 0, 0,
};

// 0x82D2978
const struct BgTemplate sMainMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

// 0x82D2980
const struct BgTemplate sBirchBgTemplate =
{
    .bg = 0,
    .charBaseIndex = 3,
    .mapBaseIndex = 30,
    .screenSize = 0,
    .paletteMode = 0,
    .priority = 0,
    .baseTile = 0
};

// 0x82D2984
const struct ScrollArrowsTemplate sScrollArrowsTemplate_MainMenu =
{
    2, 0x78, 8, 3, 0x78, 0x98, 3, 4, 1, 1, 0,
};
// JP preset-name texts are defined in data/data_b2d_mid72.s.
extern const u8 gText_DefaultName_Itsuo[];
extern const u8 gText_DefaultName_Gyoku[];
extern const u8 gText_DefaultName_Kei[];
extern const u8 gText_DefaultName_Shuusaku[];
extern const u8 gText_DefaultName_Seigo[];
extern const u8 gText_DefaultName_Daisaku[];
extern const u8 gText_DefaultName_Takahito[];
extern const u8 gText_DefaultName_Tatsuya[];
extern const u8 gText_DefaultName_Daniel[];
extern const u8 gText_DefaultName_Teruki[];
extern const u8 gText_DefaultName_Tom[];
extern const u8 gText_DefaultName_Tomoya[];
extern const u8 gText_DefaultName_Hitoshi[];
extern const u8 gText_DefaultName_Hiroaki[];
extern const u8 gText_DefaultName_Yukihiko[];
extern const u8 gText_DefaultName_Raldo[];
extern const u8 gText_DefaultName_Rikuya[];
extern const u8 gText_DefaultName_Richard[];
extern const u8 gText_DefaultName_Ryuu[];
extern const u8 gText_DefaultName_Ryouta[];
extern const u8 gText_DefaultName_Aiko[];
extern const u8 gText_DefaultName_Ayana[];
extern const u8 gText_DefaultName_Ann[];
extern const u8 gText_DefaultName_Emii[];
extern const u8 gText_DefaultName_Kaori[];
extern const u8 gText_DefaultName_Karen[];
extern const u8 gText_DefaultName_Kyouko[];
extern const u8 gText_DefaultName_Sae[];
extern const u8 gText_DefaultName_Sui[];
extern const u8 gText_DefaultName_Juri[];
extern const u8 gText_DefaultName_Chiemi[];
extern const u8 gText_DefaultName_Chiyoko[];
extern const u8 gText_DefaultName_Teruko[];
extern const u8 gText_DefaultName_Nanae[];
extern const u8 gText_DefaultName_Hina[];
extern const u8 gText_DefaultName_Makiko[];
extern const u8 gText_DefaultName_Misako[];
extern const u8 gText_DefaultName_Mutsumi[];
extern const u8 gText_DefaultName_Monica[];
extern const u8 gText_DefaultName_Yuume[];

// 0x82D2994
const union AffineAnimCmd sSpriteAffineAnim_PlayerShrink[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 0x30),
    AFFINEANIMCMD_END
};

// 0x82D29A4
const union AffineAnimCmd *const sSpriteAffineAnimTable_PlayerShrink[] =
{
    sSpriteAffineAnim_PlayerShrink,
};

// 0x82D29A8
const struct MenuAction sMenuActions_Gender[] =
{
    {gText_BirchBoy, {NULL}},
    {gText_BirchGirl, {NULL}}
};

// 0x82D29B8
const u8 *const sMalePresetNames[] =
{
    gText_DefaultName_Itsuo,
    gText_DefaultName_Gyoku,
    gText_DefaultName_Kei,
    gText_DefaultName_Shuusaku,
    gText_DefaultName_Seigo,
    gText_DefaultName_Daisaku,
    gText_DefaultName_Takahito,
    gText_DefaultName_Tatsuya,
    gText_DefaultName_Daniel,
    gText_DefaultName_Teruki,
    gText_DefaultName_Tom,
    gText_DefaultName_Tomoya,
    gText_DefaultName_Hitoshi,
    gText_DefaultName_Hiroaki,
    gText_DefaultName_Yukihiko,
    gText_DefaultName_Raldo,
    gText_DefaultName_Rikuya,
    gText_DefaultName_Richard,
    gText_DefaultName_Ryuu,
    gText_DefaultName_Ryouta,
};

// 0x82D2A08
const u8 *const sFemalePresetNames[] =
{
    gText_DefaultName_Aiko,
    gText_DefaultName_Ayana,
    gText_DefaultName_Ann,
    gText_DefaultName_Emii,
    gText_DefaultName_Kaori,
    gText_DefaultName_Karen,
    gText_DefaultName_Kyouko,
    gText_DefaultName_Sae,
    gText_DefaultName_Sui,
    gText_DefaultName_Juri,
    gText_DefaultName_Chiemi,
    gText_DefaultName_Chiyoko,
    gText_DefaultName_Teruko,
    gText_DefaultName_Nanae,
    gText_DefaultName_Hina,
    gText_DefaultName_Makiko,
    gText_DefaultName_Misako,
    gText_DefaultName_Mutsumi,
    gText_DefaultName_Monica,
    gText_DefaultName_Yuume,
};

// 0x82D2A58 - used by src/digit_obj_util.c (values match pokeemerald).
const u8 sTilesPerImage[4][4] =
{
    [ST_OAM_SQUARE]      = {
        [ST_OAM_SIZE_0] = 0x01,
        [ST_OAM_SIZE_1] = 0x04,
        [ST_OAM_SIZE_2] = 0x10,
        [ST_OAM_SIZE_3] = 0x40
    },
    [ST_OAM_H_RECTANGLE] = {
        [ST_OAM_SIZE_0] = 0x02,
        [ST_OAM_SIZE_1] = 0x04,
        [ST_OAM_SIZE_2] = 0x08,
        [ST_OAM_SIZE_3] = 0x20
    },
    [ST_OAM_V_RECTANGLE] = {
        [ST_OAM_SIZE_0] = 0x02,
        [ST_OAM_SIZE_1] = 0x04,
        [ST_OAM_SIZE_2] = 0x08,
        [ST_OAM_SIZE_3] = 0x20
    },
};
