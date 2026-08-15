#include "global.h"
#include "link.h"
#include "constants/characters.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/global.h"
#include "constants/map_event_ids.h"
#include "constants/union_room.h"

// Union-room helper data (0x82C2B64..0x82C2C10)

// 0x82C2B64
const u8 sTextColors_Header[8] = {
    TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, 0,
    TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, 0,
};

// 0x82C2B6C: JP packs the test texts "あいうテスト" / "むげんのチケット"
// here; the first three bytes double as the e-Reader text colors
// (WHITE, DARK_GRAY, LIGHT_GRAY) used by mystery_gift_menu.c.
const u8 sMG_Ereader_TextColor_2[] = _("あいうテスト$むげんのチケット");

// 0x82C2B7C
const u8 sUnionRoomObjGfxIds[GENDER_COUNT][NUM_UNION_ROOM_CLASSES + 2] = {
    [MALE] = {
        OBJ_EVENT_GFX_MAN_3,
        OBJ_EVENT_GFX_BLACK_BELT,
        OBJ_EVENT_GFX_CAMPER,
        OBJ_EVENT_GFX_YOUNGSTER,
        OBJ_EVENT_GFX_PSYCHIC_M,
        OBJ_EVENT_GFX_BUG_CATCHER,
        OBJ_EVENT_GFX_MAN_4,
        OBJ_EVENT_GFX_MAN_5,
        0, 0,
    },
    [FEMALE] = {
        OBJ_EVENT_GFX_WOMAN_5,
        OBJ_EVENT_GFX_HEX_MANIAC,
        OBJ_EVENT_GFX_PICNICKER,
        OBJ_EVENT_GFX_LASS,
        OBJ_EVENT_GFX_LASS,
        OBJ_EVENT_GFX_GIRL_3,
        OBJ_EVENT_GFX_WOMAN_2,
        OBJ_EVENT_GFX_BEAUTY,
        0, 0,
    },
};

// 0x82C2B90
const s16 sUnionRoomPlayerCoords[MAX_UNION_ROOM_LEADERS][2] = {
    { 4,  6 },
    {13,  8 },
    {10,  6 },
    { 1,  8 },
    {13,  4 },
    { 7,  4 },
    { 1,  4 },
    { 7,  8 },
};

// 0x82C2BB0
const s8 sUnionRoomGroupOffsets[MAX_RFU_PLAYERS][2] = {
    { 0,  0 },
    { 1,  0 },
    { 0, -1 },
    {-1,  0 },
    { 0,  1 },
};

// 0x82C2BBA
const u8 sOppositeFacingDirection[] = {
    [DIR_NONE]  = DIR_NONE,
    [DIR_SOUTH] = DIR_NORTH,
    [DIR_NORTH] = DIR_SOUTH,
    [DIR_WEST]  = DIR_EAST,
    [DIR_EAST]  = DIR_WEST,
};

// 0x82C2BBF
const u8 sMemberFacingDirections[MAX_RFU_PLAYERS] = {
    DIR_SOUTH,
    DIR_WEST,
    DIR_SOUTH,
    DIR_EAST,
    DIR_NORTH,
};

// 0x82C2BC4 (8 local ids) + 0x82C2BCC (unused hide-player flags)
const u8 sUnionRoomLocalIds[] = {
    LOCALID_UNION_ROOM_PLAYER_1,
    LOCALID_UNION_ROOM_PLAYER_2,
    LOCALID_UNION_ROOM_PLAYER_3,
    LOCALID_UNION_ROOM_PLAYER_4,
    LOCALID_UNION_ROOM_PLAYER_5,
    LOCALID_UNION_ROOM_PLAYER_6,
    LOCALID_UNION_ROOM_PLAYER_7,
    LOCALID_UNION_ROOM_PLAYER_8,
};

// Unused (JP keeps them right after sUnionRoomLocalIds)
const u16 sHidePlayerFlags[] = {
    FLAG_HIDE_UNION_ROOM_PLAYER_1,
    FLAG_HIDE_UNION_ROOM_PLAYER_2,
    FLAG_HIDE_UNION_ROOM_PLAYER_3,
    FLAG_HIDE_UNION_ROOM_PLAYER_4,
    FLAG_HIDE_UNION_ROOM_PLAYER_5,
    FLAG_HIDE_UNION_ROOM_PLAYER_6,
    FLAG_HIDE_UNION_ROOM_PLAYER_7,
    FLAG_HIDE_UNION_ROOM_PLAYER_8,
};

// 0x82C2BDC
const char gAssertFile_rfu_union_tool[20] = {"rfu_union_tool.c"};

// 0x82C2BF0
const u8 gAssertCond_UnionObjWork[] = {0x30, 0x00, 0x00, 0x00};

// 0x82C2BF4
const char gAssertCond_UnionObjWork2[21] = {"UnionObjWork != NULL"};

// 0x82C2C09
const u8 sMovement_UnionPlayerExit[] = {
    MOVEMENT_ACTION_FLY_UP,
    MOVEMENT_ACTION_STEP_END,
};

// 0x82C2C0B (JP keeps three trailing zero bytes)
const u8 sMovement_UnionPlayerEnter[5] = {
    MOVEMENT_ACTION_FLY_DOWN,
    MOVEMENT_ACTION_STEP_END,
    0x00, 0x00, 0x00,
};
