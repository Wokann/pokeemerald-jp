#include "global.h"
#include "bg.h"
#include "window.h"
#include "link_rfu.h"
#include "constants/union_room.h"

// Union-room activity data and mystery-gift graphics (0x82C2364..0x82C24D4)

// Same layout as include/union_room.h; included here directly because
// "union_room.h" would resolve to this directory's data header instead.
struct RfuPlayerData
{
    struct RfuGameData data;
    u8 ALIGNED(4) name[RFU_USER_NAME_LENGTH];
};

// 0x82C2364
const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

// 0x82C237C..0x82C23DC: per-link-group accepted-activity ID arrays
ALIGNED(4) const u8 sAcceptedActivityIds_SingleBattle[] = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_DoubleBattle[] = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_MultiBattle[] = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_Trade[] = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_PokemonJump[] = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BerryCrush[] = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BerryPicking[] = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_WonderCard[] = {ACTIVITY_WONDER_CARD_DUP, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_WonderNews[] = {ACTIVITY_WONDER_NEWS_DUP, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_Resume[] = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) const u8 sAcceptedActivityIds_Init[] = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_Unk11[] = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD_DUP,
    ACTIVITY_WONDER_NEWS_DUP,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) const u8 sAcceptedActivityIds_RecordCorner[] = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BerryBlender[] = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_CoolContest[] = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BeautyContest[] = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_CuteContest[] = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_SmartContest[] = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_ToughContest[] = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BattleTower[] = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

// 0x82C23E0
const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen,
};

// 0x82C2438: JP keeps the 22-entry activity array (US has 24); the
// 6-byte "{DYNAMIC 0}・{DYNAMIC 1}$" string follows it at 0x82C244E.
const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD_DUP,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS_DUP,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN,
};

// JP-only trailing text after sLinkGroupToURoomActivity (0x82C244E)
const u8 sText_Unused[] = _("{DYNAMIC 0}·{DYNAMIC 1}");

// 0x82C2454
const u16 sTextboxBorder_Pal[] = {
    0x4A52, 0x7EF2, 0x7F93, 0x7FF9, 0x79AC, 0x56D4, 0x6338, 0x6F9B,
    0x7FFF, 0x0000, 0x0000, 0x0000, 0x318C, 0x4A52, 0x6318, 0x0000,
};

// 0x82C2474 (LZ-compressed 4bpp)
const u32 sTextboxBorder_Gfx[] = {
    0x00010010, 0xF0000033, 0x22019001, 0x9001F022, 0x11113301, 0x019001F0,
    0x01F04444, 0xF0FE0190, 0xF001F071, 0xF001F001, 0xF001F001, 0x00000001,
};

// 0x82C24A4: JP ships only the first two of the US four BgTemplates
const struct BgTemplate sBGTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0x000,
    }, {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 14,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0x000,
    }, {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 13,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0x000,
    }, {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 12,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0x000,
    },
};

// 0x82C24B4
const struct WindowTemplate sMainWindows[] = {
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 30,
        .height = 2,
        .paletteNum = 12,
        .baseBlock = 0x0013,
    }, {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 28,
        .height = 4,
        .paletteNum = 12,
        .baseBlock = 0x004F,
    }, {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 15,
        .width = 30,
        .height = 5,
        .paletteNum = 13,
        .baseBlock = 0x004F,
    },
    DUMMY_WIN_TEMPLATE,
};
