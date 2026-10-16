#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "coins.h"
#include "decompress.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "palette_util.h"
#include "random.h"
#include "roulette.h"
#include "rtc.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trig.h"
#include "tv.h"
#include "window.h"
#include "constants/coins.h"
#include "constants/rgb.h"
#include "constants/roulette.h"
#include "constants/songs.h"

#define BALLS_PER_ROUND 6

// "Board" is used in this file to refer to both the wheel and the bet selection grid
#define NUM_BOARD_COLORS 3 // Rows on grid
#define NUM_BOARD_POKES  4 // Columns on grid
#define NUM_ROULETTE_SLOTS (NUM_BOARD_COLORS * NUM_BOARD_POKES)

// The degree change between each slot on the roulette wheel
#define DEGREES_PER_SLOT (360 / NUM_ROULETTE_SLOTS)

// Where in the slot the ball will drop when landing
#define SLOT_MIDPOINT (DEGREES_PER_SLOT / 2 - 1)

// IDs for grid selections when betting
#define SELECTION_NONE      0
#define COL_WYNAUT          1
#define COL_AZURILL         2
#define COL_SKITTY          3
#define COL_MAKUHITA        4
#define ROW_ORANGE          (COL_MAKUHITA + 1)
#define SQU_ORANGE_WYNAUT   (ROW_ORANGE + COL_WYNAUT)
#define SQU_ORANGE_AZURILL  (ROW_ORANGE + COL_AZURILL)
#define SQU_ORANGE_SKITTY   (ROW_ORANGE + COL_SKITTY)
#define SQU_ORANGE_MAKUHITA (ROW_ORANGE + COL_MAKUHITA)
#define ROW_GREEN           (SQU_ORANGE_MAKUHITA + 1)
#define SQU_GREEN_WYNAUT    (ROW_GREEN + COL_WYNAUT)
#define SQU_GREEN_AZURILL   (ROW_GREEN + COL_AZURILL)
#define SQU_GREEN_SKITTY    (ROW_GREEN + COL_SKITTY)
#define SQU_GREEN_MAKUHITA  (ROW_GREEN + COL_MAKUHITA)
#define ROW_PURPLE          (SQU_GREEN_MAKUHITA + 1)
#define SQU_PURPLE_WYNAUT   (ROW_PURPLE + COL_WYNAUT)
#define SQU_PURPLE_AZURILL  (ROW_PURPLE + COL_AZURILL)
#define SQU_PURPLE_SKITTY   (ROW_PURPLE + COL_SKITTY)
#define SQU_PURPLE_MAKUHITA (ROW_PURPLE + COL_MAKUHITA)
#define NUM_GRID_SELECTIONS SQU_PURPLE_MAKUHITA

// Get the id of the col/row from the selection ID
// e.g. GET_ROW(SQU_PURPLE_SKITTY) is ROW_PURPLE
#define GET_COL(selectionId) ((selectionId) % (NUM_BOARD_POKES + 1))
#define GET_ROW(selectionId) ((selectionId) / (NUM_BOARD_POKES + 1) * (NUM_BOARD_POKES + 1))

// Get the col/row index from the selection ID
// e.g. GET_ROW_IDX(SQU_PURPLE_SKITTY) is 2 (purple being the 3rd row)
#define GET_COL_IDX(selectionId) (selectionId - 1)
#define GET_ROW_IDX(selectionId) (selectionId / 5 - 1)

// Flags for the above selections, used to set which spaces have been hit or bet on
#define F_WYNAUT_COL      (1 << COL_WYNAUT)
#define F_AZURILL_COL     (1 << COL_AZURILL)
#define F_SKITTY_COL      (1 << COL_SKITTY)
#define F_MAKUHITA_COL    (1 << COL_MAKUHITA)
#define F_ORANGE_ROW      (1 << ROW_ORANGE)
#define F_ORANGE_WYNAUT   (1 << SQU_ORANGE_WYNAUT)
#define F_ORANGE_AZURILL  (1 << SQU_ORANGE_AZURILL)
#define F_ORANGE_SKITTY   (1 << SQU_ORANGE_SKITTY)
#define F_ORANGE_MAKUHITA (1 << SQU_ORANGE_MAKUHITA)
#define F_GREEN_ROW       (1 << ROW_GREEN)
#define F_GREEN_WYNAUT    (1 << SQU_GREEN_WYNAUT)
#define F_GREEN_AZURILL   (1 << SQU_GREEN_AZURILL)
#define F_GREEN_SKITTY    (1 << SQU_GREEN_SKITTY)
#define F_GREEN_MAKUHITA  (1 << SQU_GREEN_MAKUHITA)
#define F_PURPLE_ROW      (1 << ROW_PURPLE)
#define F_PURPLE_WYNAUT   (1 << SQU_PURPLE_WYNAUT)
#define F_PURPLE_AZURILL  (1 << SQU_PURPLE_AZURILL)
#define F_PURPLE_SKITTY   (1 << SQU_PURPLE_SKITTY)
#define F_PURPLE_MAKUHITA (1 << SQU_PURPLE_MAKUHITA)

// Flags for flashing selections on the roulette wheel
#define F_FLASH_COLOR_O_WYNAUT   (1 << 0)
#define F_FLASH_COLOR_G_AZURILL  (1 << 1)
#define F_FLASH_COLOR_P_SKITTY   (1 << 2)
#define F_FLASH_COLOR_O_MAKUHITA (1 << 3)
#define F_FLASH_COLOR_G_WYNAUT   (1 << 4)
#define F_FLASH_COLOR_P_AZURILL  (1 << 5)
#define F_FLASH_COLOR_O_SKITTY   (1 << 6)
#define F_FLASH_COLOR_G_MAKUHITA (1 << 7)
#define F_FLASH_COLOR_P_WYNAUT   (1 << 8)
#define F_FLASH_COLOR_O_AZURILL  (1 << 9)
#define F_FLASH_COLOR_G_SKITTY   (1 << 10)
#define F_FLASH_COLOR_P_MAKUHITA (1 << 11)
#define F_FLASH_OUTER_EDGES      (1 << 12) // when the player wins
#define FLASH_ICON               (NUM_ROULETTE_SLOTS + 1)
#define FLASH_ICON_2             (FLASH_ICON + 1)
#define FLASH_ICON_3             (FLASH_ICON + 2)
#define F_FLASH_ICON             (1 << FLASH_ICON)
#define F_FLASH_COLUMN           (1 << FLASH_ICON | 1 << FLASH_ICON_2 | 1 << FLASH_ICON_3)

#define MAX_MULTIPLIER 12

#define PALTAG_SHADOW 1
#define PALTAG_BALL 2
#define PALTAG_BALL_COUNTER 3
#define PALTAG_CURSOR 4
#define PALTAG_INTERFACE 5
#define PALTAG_SHROOMISH 6
#define PALTAG_TAILLOW   7
#define PALTAG_GRID_ICONS 8
#define PALTAG_WYNAUT    9
#define PALTAG_AZURILL   10
#define PALTAG_SKITTY    11
#define PALTAG_MAKUHITA  12

#define GFXTAG_WHEEL_ICONS 0
#define GFXTAG_HEADERS 4
#define GFXTAG_GRID_ICONS 5
#define GFXTAG_WHEEL_CENTER 6
#define GFXTAG_CREDIT 7
#define GFXTAG_CREDIT_DIGIT 8
#define GFXTAG_MULTIPLIER 9
#define GFXTAG_BALL_COUNTER 10
#define GFXTAG_CURSOR 11
#define GFXTAG_BALL 12
#define GFXTAG_SHROOMISH_TAILLOW 13
#define GFXTAG_SHADOW 14

// 2 different Roulette tables with 2 different rates (normal vs service day special)
// & 1 gets which table, >> 7 gets if ROULETTE_SPECIAL_RATE is set
#define GET_MIN_BET_ID(var) (((var) & 1) + (((var) >> 7) * 2))

// Having Shroomish or Taillow in the party can make rolls more consistent in length
// It also increases the likelihood that, if they appear to unstick a ball, they'll move it to a slot the player bet on
#define HAS_SHROOMISH  (1 << 0)
#define HAS_TAILLOW    (1 << 1)

#define NO_DELAY 0xFFFF

enum {
    BALL_STATE_ROLLING,
    BALL_STATE_STUCK,
    BALL_STATE_LANDED = 0xFF,
};

enum {
    SELECT_STATE_WAIT,
    SELECT_STATE_DRAW,
    SELECT_STATE_UPDATE,
    SELECT_STATE_ERASE = 0xFF,
};

// Roulette uses a large amount of sprites, and stores ids for these in a single array
// Many are looped over rather than referenced directly
enum {
    SPR_WHEEL_BALL_1,
    SPR_WHEEL_BALL_2,
    SPR_WHEEL_BALL_3,
    SPR_WHEEL_BALL_4,
    SPR_WHEEL_BALL_5,
    SPR_WHEEL_BALL_6,
    SPR_WHEEL_CENTER,
    SPR_WHEEL_ICON_ORANGE_WYNAUT,
    SPR_WHEEL_ICON_GREEN_AZURILL,
    SPR_WHEEL_ICON_PURPLE_SKITTY,
    SPR_WHEEL_ICON_ORANGE_MAKUHITA,
    SPR_WHEEL_ICON_GREEN_WYNAUT,
    SPR_WHEEL_ICON_PURPLE_AZURILL,
    SPR_WHEEL_ICON_ORANGE_SKITTY,
    SPR_WHEEL_ICON_GREEN_MAKUHITA,
    SPR_WHEEL_ICON_PURPLE_WYNAUT,
    SPR_WHEEL_ICON_ORANGE_AZURILL,
    SPR_WHEEL_ICON_GREEN_SKITTY,
    SPR_WHEEL_ICON_PURPLE_MAKUHITA,
    SPR_19, // Unused
    SPR_CREDIT,
    SPR_CREDIT_DIG_1,
    SPR_CREDIT_DIG_10,
    SPR_CREDIT_DIG_100,
    SPR_CREDIT_DIG_1000,
    SPR_MULTIPLIER,
    SPR_BALL_COUNTER_1,
    SPR_BALL_COUNTER_2,
    SPR_BALL_COUNTER_3,
    SPR_GRID_ICON_ORANGE_WYNAUT,
    SPR_GRID_ICON_GREEN_AZURILL,
    SPR_GRID_ICON_PURPLE_SKITTY,
    SPR_GRID_ICON_ORANGE_MAKUHITA,
    SPR_GRID_ICON_GREEN_WYNAUT,
    SPR_GRID_ICON_PURPLE_AZURILL,
    SPR_GRID_ICON_ORANGE_SKITTY,
    SPR_GRID_ICON_GREEN_MAKUHITA,
    SPR_GRID_ICON_PURPLE_WYNAUT,
    SPR_GRID_ICON_ORANGE_AZURILL,
    SPR_GRID_ICON_GREEN_SKITTY,
    SPR_GRID_ICON_PURPLE_MAKUHITA,
    SPR_POKE_HEADER_1,
    SPR_POKE_HEADER_2,
    SPR_POKE_HEADER_3,
    SPR_POKE_HEADER_4,
    SPR_COLOR_HEADER_1,
    SPR_COLOR_HEADER_2,
    SPR_COLOR_HEADER_3,
    SPR_WIN_SLOT_CURSOR,
    SPR_GRID_BALL_1,
    SPR_GRID_BALL_2,
    SPR_GRID_BALL_3,
    SPR_GRID_BALL_4,
    SPR_GRID_BALL_5,
    SPR_GRID_BALL_6,
    SPR_CLEAR_MON, // Shroomish/Taillow
    SPR_CLEAR_MON_SHADOW_1,
    SPR_CLEAR_MON_SHADOW_2,
    SPR_58, // Here below unused
    SPR_59,
    SPR_60,
    SPR_61,
    SPR_62,
    SPR_63,
};

// Start points for sprite IDs that are looped over
#define SPR_WHEEL_BALLS SPR_WHEEL_BALL_1
#define SPR_WHEEL_ICONS SPR_WHEEL_ICON_ORANGE_WYNAUT
#define SPR_BALL_COUNTER SPR_BALL_COUNTER_1
#define SPR_CREDIT_DIGITS SPR_CREDIT_DIG_1
#define SPR_GRID_ICONS SPR_GRID_ICON_ORANGE_WYNAUT
#define SPR_POKE_HEADERS SPR_POKE_HEADER_1
#define SPR_COLOR_HEADERS SPR_COLOR_HEADER_1
#define SPR_GRID_BALLS SPR_GRID_BALL_1

struct Shroomish
{
    u16 startAngle;
    u16 dropAngle;
    u16 fallSlowdown;
};

struct Taillow
{
    u16 baseDropDelay;
    u16 rightStartAngle;
    u16 leftStartAngle;
};

struct RouletteTable
{
    u8 minBet; // Never read
    u8 randDistanceHigh;
    u8 randDistanceLow;
    u8 wheelSpeed;
    u8 wheelDelay;
    struct Shroomish shroomish;
    struct Taillow taillow;
    u16 ballSpeed;
    u16 baseTravelDist;
    f32 var1C;
};

struct GridSelection
{
    u8 spriteIdOffset;
    u8 baseMultiplier:4;
    u8 column:4; // Never read
    u8 row;      // Never read
    u8 x;
    u8 y;
    u8 var05;    // Never read
    u8 tilemapOffset;
    u32 flag;
    u32 inSelectionFlags;
    u16 flashFlags;
};

struct RouletteSlot
{
    u8 id1; // Never read
    u8 id2; // Never read
    u8 gridSquare;
    u32 flag;
};

void sub_08140A30(void);
void sub_08140A5C(void);
void sub_081429E0(void);
void sub_08142A44(void);
void sub_0814334C(void);
void sub_081439D8(void);
void sub_08143A68(void);
void sub_08144F2C(void);
void sub_08145360(void);

#define ROULETTE_DATA __attribute__((section(".rodata.roulette_data"), aligned(1)))

ROULETTE_DATA static const u16 sWheel_Pal[] = INCGFX_U16("graphics/roulette/wheel.png", ".gbapal");

ROULETTE_DATA static const u32 sGrid_Tilemap[] = INCGFX_U32("graphics/roulette/grid.bin", ".lz");

ROULETTE_DATA static const u32 sWheel_Tilemap[] = INCGFX_U32("graphics/roulette/wheel.bin", ".lz");

ROULETTE_DATA static const struct BgTemplate sBgTemplates[] =
{
    // Text box
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    // Selection grid
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 4,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    // Wheel
    {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 6,
        .screenSize = 1,
        .paletteMode = 1,
        .priority = 2,
        .baseTile = 0
    }
};

// JP keeps one window entry at native tile block 0xD6.
ROULETTE_DATA static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 24,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0xD6
    },
};

ROULETTE_DATA static const struct GridSelection sGridSelections[NUM_GRID_SELECTIONS + 1] =
{
    [SELECTION_NONE] = {
        .spriteIdOffset = 0xFF,
        .baseMultiplier = 0,
        .column = 0,
        .row = 0,
        .x = 7,
        .y = 7,
        .var05 = 0,
        .tilemapOffset = 0,
        .flag = 0,
        .inSelectionFlags = 0,
        .flashFlags = 0,
    },
    [COL_WYNAUT] = {
        .spriteIdOffset = 12,
        .baseMultiplier = NUM_BOARD_POKES,
        .column = 1,
        .row = 0,
        .x = 17,
        .y = 7,
        .var05 = 0,
        .tilemapOffset = 0,
        .flag = F_WYNAUT_COL,
        .inSelectionFlags = F_WYNAUT_COL | F_ORANGE_WYNAUT | F_GREEN_WYNAUT | F_PURPLE_WYNAUT,
        .flashFlags = F_FLASH_COLUMN,
    },
    [COL_AZURILL] = {
        .spriteIdOffset = 13,
        .baseMultiplier = NUM_BOARD_POKES,
        .column = 2,
        .row = 0,
        .x = 20,
        .y = 7,
        .var05 = 0,
        .tilemapOffset = 0,
        .flag = F_AZURILL_COL,
        .inSelectionFlags = F_AZURILL_COL | F_ORANGE_AZURILL | F_GREEN_AZURILL | F_PURPLE_AZURILL,
        .flashFlags = F_FLASH_COLUMN,
    },
    [COL_SKITTY] = {
        .spriteIdOffset = 14,
        .baseMultiplier = NUM_BOARD_POKES,
        .column = 3,
        .row = 0,
        .x = 23,
        .y = 7,
        .var05 = 0,
        .tilemapOffset = 0,
        .flag = F_SKITTY_COL,
        .inSelectionFlags = F_SKITTY_COL | F_ORANGE_SKITTY | F_GREEN_SKITTY | F_PURPLE_SKITTY,
        .flashFlags = F_FLASH_COLUMN,
    },
    [COL_MAKUHITA] = {
        .spriteIdOffset = 15,
        .baseMultiplier = NUM_BOARD_POKES,
        .column = 4,
        .row = 0,
        .x = 26,
        .y = 7,
        .var05 = 0,
        .tilemapOffset = 0,
        .flag = F_MAKUHITA_COL,
        .inSelectionFlags = F_MAKUHITA_COL | F_ORANGE_MAKUHITA | F_GREEN_MAKUHITA | F_PURPLE_MAKUHITA,
        .flashFlags = F_FLASH_COLUMN,
    },
    [ROW_ORANGE] = {
        .spriteIdOffset = 16,
        .baseMultiplier = NUM_BOARD_COLORS,
        .column = 0,
        .row = 1,
        .x = 14,
        .y = 10,
        .var05 = 0,
        .tilemapOffset = 12,
        .flag = F_ORANGE_ROW,
        .inSelectionFlags = F_ORANGE_ROW | F_ORANGE_WYNAUT | F_ORANGE_AZURILL | F_ORANGE_SKITTY | F_ORANGE_MAKUHITA,
        .flashFlags = F_FLASH_COLOR_O_WYNAUT | F_FLASH_COLOR_O_AZURILL | F_FLASH_COLOR_O_SKITTY | F_FLASH_COLOR_O_MAKUHITA,
    },
    [SQU_ORANGE_WYNAUT] = {
        .spriteIdOffset = 0,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 1,
        .row = 1,
        .x = 17,
        .y = 10,
        .var05 = 3,
        .tilemapOffset = 3,
        .flag = F_ORANGE_WYNAUT,
        .inSelectionFlags = F_ORANGE_WYNAUT,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_O_WYNAUT,
    },
    [SQU_ORANGE_AZURILL] = {
        .spriteIdOffset = 9,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 2,
        .row = 1,
        .x = 20,
        .y = 10,
        .var05 = 3,
        .tilemapOffset = 3,
        .flag = F_ORANGE_AZURILL,
        .inSelectionFlags = F_ORANGE_AZURILL,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_O_AZURILL,
    },
    [SQU_ORANGE_SKITTY] = {
        .spriteIdOffset = 6,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 3,
        .row = 1,
        .x = 23,
        .y = 10,
        .var05 = 3,
        .tilemapOffset = 3,
        .flag = F_ORANGE_SKITTY,
        .inSelectionFlags = F_ORANGE_SKITTY,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_O_SKITTY,
    },
    [SQU_ORANGE_MAKUHITA] = {
        .spriteIdOffset = 3,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 4,
        .row = 1,
        .x = 26,
        .y = 10,
        .var05 = 3,
        .tilemapOffset = 3,
        .flag = F_ORANGE_MAKUHITA,
        .inSelectionFlags = F_ORANGE_MAKUHITA,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_O_MAKUHITA,
    },
    [ROW_GREEN] = {
        .spriteIdOffset = 17,
        .baseMultiplier = NUM_BOARD_COLORS,
        .column = 0,
        .row = 2,
        .x = 14,
        .y = 13,
        .var05 = 3,
        .tilemapOffset = 15,
        .flag = F_GREEN_ROW,
        .inSelectionFlags = F_GREEN_ROW | F_GREEN_WYNAUT | F_GREEN_AZURILL | F_GREEN_SKITTY | F_GREEN_MAKUHITA,
        .flashFlags = F_FLASH_COLOR_G_WYNAUT | F_FLASH_COLOR_G_AZURILL | F_FLASH_COLOR_G_SKITTY | F_FLASH_COLOR_G_MAKUHITA,
    },
    [SQU_GREEN_WYNAUT] = {
        .spriteIdOffset = 4,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 1,
        .row = 2,
        .x = 17,
        .y = 13,
        .var05 = 6,
        .tilemapOffset = 6,
        .flag = F_GREEN_WYNAUT,
        .inSelectionFlags = F_GREEN_WYNAUT,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_G_WYNAUT,
    },
    [SQU_GREEN_AZURILL] = {
        .spriteIdOffset = 1,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 2,
        .row = 2,
        .x = 20,
        .y = 13,
        .var05 = 6,
        .tilemapOffset = 6,
        .flag = F_GREEN_AZURILL,
        .inSelectionFlags = F_GREEN_AZURILL,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_G_AZURILL,
    },
    [SQU_GREEN_SKITTY] = {
        .spriteIdOffset = 10,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 3,
        .row = 2,
        .x = 23,
        .y = 13,
        .var05 = 6,
        .tilemapOffset = 6,
        .flag = F_GREEN_SKITTY,
        .inSelectionFlags = F_GREEN_SKITTY,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_G_SKITTY,
    },
    [SQU_GREEN_MAKUHITA] = {
        .spriteIdOffset = 7,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 4,
        .row = 2,
        .x = 26,
        .y = 13,
        .var05 = 6,
        .tilemapOffset = 6,
        .flag = F_GREEN_MAKUHITA,
        .inSelectionFlags = F_GREEN_MAKUHITA,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_G_MAKUHITA,
    },
    [ROW_PURPLE] = {
        .spriteIdOffset = 18,
        .baseMultiplier = NUM_BOARD_COLORS,
        .column = 0,
        .row = 3,
        .x = 14,
        .y = 16,
        .var05 = 6,
        .tilemapOffset = 18,
        .flag = F_PURPLE_ROW,
        .inSelectionFlags = F_PURPLE_ROW | F_PURPLE_WYNAUT | F_PURPLE_AZURILL | F_PURPLE_SKITTY | F_PURPLE_MAKUHITA,
        .flashFlags = F_FLASH_COLOR_P_WYNAUT | F_FLASH_COLOR_P_AZURILL | F_FLASH_COLOR_P_SKITTY | F_FLASH_COLOR_P_MAKUHITA,
    },
    [SQU_PURPLE_WYNAUT] = {
        .spriteIdOffset = 8,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 1,
        .row = 3,
        .x = 17,
        .y = 16,
        .var05 = 9,
        .tilemapOffset = 9,
        .flag = F_PURPLE_WYNAUT,
        .inSelectionFlags = F_PURPLE_WYNAUT,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_P_WYNAUT,
    },
    [SQU_PURPLE_AZURILL] = {
        .spriteIdOffset = 5,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 2,
        .row = 3,
        .x = 20,
        .y = 16,
        .var05 = 9,
        .tilemapOffset = 9,
        .flag = F_PURPLE_AZURILL,
        .inSelectionFlags = F_PURPLE_AZURILL,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_P_AZURILL,
    },
    [SQU_PURPLE_SKITTY] = {
        .spriteIdOffset = 2,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 3,
        .row = 3,
        .x = 23,
        .y = 16,
        .var05 = 9,
        .tilemapOffset = 9,
        .flag = F_PURPLE_SKITTY,
        .inSelectionFlags = F_PURPLE_SKITTY,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_P_SKITTY,
    },
    [SQU_PURPLE_MAKUHITA] = {
        .spriteIdOffset = 11,
        .baseMultiplier = NUM_ROULETTE_SLOTS,
        .column = 4,
        .row = 3,
        .x = 26,
        .y = 16,
        .var05 = 9,
        .tilemapOffset = 9,
        .flag = F_PURPLE_MAKUHITA,
        .inSelectionFlags = F_PURPLE_MAKUHITA,
        .flashFlags = F_FLASH_ICON | F_FLASH_COLOR_P_MAKUHITA,
    },
};

ROULETTE_DATA static const struct RouletteSlot sRouletteSlots[] =
{
    {
        .id1 = 0,
        .id2 = 1,
        .gridSquare = SQU_ORANGE_WYNAUT,
        .flag = F_ORANGE_WYNAUT,
    },
    {
        .id1 = 1,
        .id2 = 3,
        .gridSquare = SQU_GREEN_AZURILL,
        .flag = F_GREEN_AZURILL,
    },
    {
        .id1 = 2,
        .id2 = 5,
        .gridSquare = SQU_PURPLE_SKITTY,
        .flag = F_PURPLE_SKITTY,
    },
    {
        .id1 = 3,
        .id2 = 7,
        .gridSquare = SQU_ORANGE_MAKUHITA,
        .flag = F_ORANGE_MAKUHITA,
    },
    {
        .id1 = 4,
        .id2 = 9,
        .gridSquare = SQU_GREEN_WYNAUT,
        .flag = F_GREEN_WYNAUT,
    },
    {
        .id1 = 5,
        .id2 = 11,
        .gridSquare = SQU_PURPLE_AZURILL,
        .flag = F_PURPLE_AZURILL,
    },
    {
        .id1 = 6,
        .id2 = 13,
        .gridSquare = SQU_ORANGE_SKITTY,
        .flag = F_ORANGE_SKITTY,
    },
    {
        .id1 = 7,
        .id2 = 15,
        .gridSquare = SQU_GREEN_MAKUHITA,
        .flag = F_GREEN_MAKUHITA,
    },
    {
        .id1 = 8,
        .id2 = 17,
        .gridSquare = SQU_PURPLE_WYNAUT,
        .flag = F_PURPLE_WYNAUT,
    },
    {
        .id1 = 9,
        .id2 = 19,
        .gridSquare = SQU_ORANGE_AZURILL,
        .flag = F_ORANGE_AZURILL,
    },
    {
        .id1 = 10,
        .id2 = 21,
        .gridSquare = SQU_GREEN_SKITTY,
        .flag = F_GREEN_SKITTY,
    },
    {
        .id1 = 11,
        .id2 = 23,
        .gridSquare = SQU_PURPLE_MAKUHITA,
        .flag = F_PURPLE_MAKUHITA,
    },
};

ROULETTE_DATA static const u8 sTableMinBets[] = {1, 3, 1, 6};

ROULETTE_DATA static const struct RouletteTable sRouletteTables[] =
{
    // Left table
    {
        .minBet = 1,
        .randDistanceHigh = DEGREES_PER_SLOT * 2,
        .randDistanceLow = DEGREES_PER_SLOT,
        .wheelSpeed = 1,
        .wheelDelay = 1,
        .shroomish = {
            .startAngle = 45,
            .dropAngle = 30,
            .fallSlowdown = 1,
        },
        .taillow = {
            .baseDropDelay = 75,
            .rightStartAngle = 27,
            .leftStartAngle = 24,
        },
        .ballSpeed = 10,
        .baseTravelDist = 360,
        .var1C = -0.5f
    },
    // Right table
    {
        .minBet = 3,
        .randDistanceHigh = DEGREES_PER_SLOT,
        .randDistanceLow = DEGREES_PER_SLOT / 2,
        .wheelSpeed = 1,
        .wheelDelay = 0,
        .shroomish = {
            .startAngle = 75,
            .dropAngle = 60,
            .fallSlowdown = 2,
        },
        .taillow = {
            .baseDropDelay = 0,
            .rightStartAngle = 54,
            .leftStartAngle = 48,
        },
        .ballSpeed = 10,
        .baseTravelDist = 270,
        .var1C = -1.0f
    }
};

ROULETTE_DATA static const struct RouletteFlashSettings sFlashData_Colors[NUM_ROULETTE_SLOTS + 1] =
{
    { // F_FLASH_COLOR_O_WYNAUT
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(0) + 5,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_G_AZURILL
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(0) + 10,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_P_SKITTY
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(1) + 5,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_O_MAKUHITA
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(5) + 5,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_G_WYNAUT
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(5) + 10,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_P_AZURILL
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(6) + 5,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_O_SKITTY
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(7) + 5,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_G_MAKUHITA
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(7) + 10,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_P_WYNAUT
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(8) + 5,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_O_AZURILL
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(9) + 5,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_G_SKITTY
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(9) + 10,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_COLOR_P_MAKUHITA
        .color = FLASHUTIL_USE_EXISTING_COLOR,
        .paletteOffset = BG_PLTT_ID(10) + 5,
        .numColors = 1,
        .delay = 1,
        .unk6 = -1,
        .numFadeCycles = 8,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    { // F_FLASH_OUTER_EDGES
        .color = RGB(22, 30, 29),
        .paletteOffset = BG_PLTT_ID(2) + 8,
        .numColors = 2,
        .delay = 10,
        .unk6 = -1,
        .numFadeCycles = 14,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
};

ROULETTE_DATA static const struct RouletteFlashSettings sFlashData_PokeIcons[NUM_BOARD_COLORS] =
{
    [GET_ROW_IDX(ROW_ORANGE)] = {
        .color = RGB(31, 31, 20),
        .paletteOffset = OBJ_PLTT_ID(0) + 1,
        .numColors = 5,
        .delay = 30,
        .unk6 = -1,
        .numFadeCycles = 14,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    [GET_ROW_IDX(ROW_GREEN)] = {
        .color = RGB(27, 31, 31),
        .paletteOffset = OBJ_PLTT_ID(0) + 6,
        .numColors = 5,
        .delay = 30,
        .unk6 = -1,
        .numFadeCycles = 14,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    },
    [GET_ROW_IDX(ROW_PURPLE)] = {
        .color = RGB(31, 27, 31),
        .paletteOffset = OBJ_PLTT_ID(0) + 11,
        .numColors = 5,
        .delay = 30,
        .unk6 = -1,
        .numFadeCycles = 14,
        .unk7_5 = -2,
        .colorDeltaDir = 0,
    }
};

// Unused JP text retains EOS and three native zero padding bytes.
ROULETTE_DATA static const u8 sUnusedText_NumberOfCoins[8] = _("{STR_VAR_1}まい");

ROULETTE_DATA static const struct YesNoFuncTable sYesNoTable_AcceptMinBet =
{
    (TaskFunc)sub_081429E0,
    (TaskFunc)sub_08142A44
};

ROULETTE_DATA static const struct YesNoFuncTable sYesNoTable_KeepPlaying =
{
    (TaskFunc)sub_08140A30,
    (TaskFunc)sub_08140A5C
};

ROULETTE_DATA static const u16 sInitTableBgColors[3] = {RGB(24, 4, 10), RGB(10, 19, 6), RGB(24, 4, 10)};

ROULETTE_DATA static const s8 sGridMoveOffsets[4] = {-5, 5, -1, 1};

ROULETTE_DATA static const u16 sBallStartAngles[4] = {0, 180, 90, 270};

ROULETTE_DATA static const u32 sBoardColumnFlags[NUM_BOARD_POKES] __attribute__((aligned(4))) =
{
    F_WYNAUT_COL | F_ORANGE_WYNAUT | F_GREEN_WYNAUT | F_PURPLE_WYNAUT,
    F_AZURILL_COL | F_ORANGE_AZURILL | F_GREEN_AZURILL | F_PURPLE_AZURILL,
    F_SKITTY_COL | F_ORANGE_SKITTY | F_GREEN_SKITTY | F_PURPLE_SKITTY,
    F_MAKUHITA_COL | F_ORANGE_MAKUHITA | F_GREEN_MAKUHITA | F_PURPLE_MAKUHITA
};

ROULETTE_DATA static const u32 sBoardRowFlags[NUM_BOARD_COLORS] =
{
    F_ORANGE_ROW | F_ORANGE_WYNAUT | F_ORANGE_AZURILL | F_ORANGE_SKITTY | F_ORANGE_MAKUHITA,
    F_GREEN_ROW | F_GREEN_WYNAUT | F_GREEN_AZURILL | F_GREEN_SKITTY | F_GREEN_MAKUHITA,
    F_PURPLE_ROW | F_PURPLE_WYNAUT | F_PURPLE_AZURILL | F_PURPLE_SKITTY | F_PURPLE_MAKUHITA
};

ROULETTE_DATA static const u8 sSelectionMultipliers[5] = {0, 3, 4, 6, MAX_MULTIPLIER};

ROULETTE_DATA static const u8 sFiller[3] = {};

ROULETTE_DATA static const u16 sShadow_Pal[] = INCGFX_U16("graphics/roulette/shadow.png", ".gbapal");

ROULETTE_DATA static const u16 sBall_Pal[] = INCGFX_U16("graphics/roulette/ball.png", ".gbapal");

ROULETTE_DATA static const u16 sBallCounter_Pal[] = INCGFX_U16("graphics/roulette/ball_counter.png", ".gbapal");

ROULETTE_DATA static const u16 sCursor_Pal[] = INCGFX_U16("graphics/roulette/cursor.png", ".gbapal");

ROULETTE_DATA static const u16 sCredit_Pal[] = INCGFX_U16("graphics/roulette/credit.png", ".gbapal");

ROULETTE_DATA static const u16 sShroomish_Pal[] = INCGFX_U16("graphics/roulette/shroomish.png", ".gbapal");

ROULETTE_DATA static const u16 sTaillow_Pal[] = INCGFX_U16("graphics/roulette/tailow.png", ".gbapal");

ROULETTE_DATA static const u16 sGridIcons_Pal[] = INCGFX_U16("graphics/roulette/grid_icons.png", ".gbapal");

ROULETTE_DATA static const u16 sWynaut_Pal[] = INCGFX_U16("graphics/roulette/wynaut.png", ".gbapal");

ROULETTE_DATA static const u16 sAzurill_Pal[] = INCGFX_U16("graphics/roulette/azurill.png", ".gbapal");

ROULETTE_DATA static const u16 sSkitty_Pal[] = INCGFX_U16("graphics/roulette/skitty.png", ".gbapal");

ROULETTE_DATA static const u16 sMakuhita_Pal[] = INCGFX_U16("graphics/roulette/makuhita.png", ".gbapal");

ROULETTE_DATA static const u16 sUnused1_Pal[] = INCGFX_U16("graphics/roulette/unused_1.pal", ".gbapal");

ROULETTE_DATA static const u16 sUnused2_Pal[] = INCGFX_U16("graphics/roulette/unused_2.pal", ".gbapal");

ROULETTE_DATA static const u16 sUnused3_Pal[] = INCGFX_U16("graphics/roulette/unused_3.pal", ".gbapal");

ROULETTE_DATA static const u16 sUnused4_Pal[] = INCGFX_U16("graphics/roulette/unused_4.pal", ".gbapal");

ROULETTE_DATA static const u32 sBall_Gfx[] = INCGFX_U32("graphics/roulette/ball.png", ".4bpp.lz");

ROULETTE_DATA static const u32 sBallCounter_Gfx[] = INCGFX_U32("graphics/roulette/ball_counter.png", ".4bpp.lz");

ROULETTE_DATA static const u32 sShroomishTaillow_Gfx[] = INCGFX_U32("graphics/roulette/roulette_tilt.4bpp", ".lz");

ROULETTE_DATA static const u32 sGridIcons_Gfx[] = INCGFX_U32("graphics/roulette/grid_icons.png", ".4bpp.lz");

ROULETTE_DATA static const u32 sWheelIcons_Gfx[] = INCGFX_U32("graphics/roulette/wheel_icons.4bpp", ".lz");

ROULETTE_DATA static const u32 sShadow_Gfx[] = INCGFX_U32("graphics/roulette/shadow.png", ".4bpp.lz");

ROULETTE_DATA static const u32 sCursor_Gfx[] = INCGFX_U32("graphics/roulette/cursor.png", ".4bpp.lz");

ROULETTE_DATA static const struct SpritePalette sSpritePalettes[] =
{
    { .data = sShadow_Pal,      .tag = PALTAG_SHADOW },
    { .data = sBall_Pal,        .tag = PALTAG_BALL },
    { .data = sBallCounter_Pal, .tag = PALTAG_BALL_COUNTER },
    { .data = sCursor_Pal,      .tag = PALTAG_CURSOR },
    { .data = sCredit_Pal,      .tag = PALTAG_INTERFACE },
    { .data = sShroomish_Pal,   .tag = PALTAG_SHROOMISH },
    { .data = sTaillow_Pal,     .tag = PALTAG_TAILLOW },
    { .data = sGridIcons_Pal,   .tag = PALTAG_GRID_ICONS },
    { .data = sWynaut_Pal,      .tag = PALTAG_WYNAUT },
    { .data = sAzurill_Pal,     .tag = PALTAG_AZURILL },
    { .data = sSkitty_Pal,      .tag = PALTAG_SKITTY },
    { .data = sMakuhita_Pal,    .tag = PALTAG_MAKUHITA },
    {}
};

ROULETTE_DATA static const struct OamData sOam_GridHeader =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 1,
};

ROULETTE_DATA static const struct OamData sOam_GridIcon =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 1,
};

ROULETTE_DATA static const struct OamData sOam_WheelIcon =
{
    .y = 60,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x32),
    .size = SPRITE_SIZE(16x32),
    .priority = 2,
};

ROULETTE_DATA static const union AnimCmd sAffineAnim_Unused1[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd *const sAffineAnims_Unused1[] =
{
    sAffineAnim_Unused1
};

ROULETTE_DATA static const union AffineAnimCmd sAffineAnim_Unused2[] =
{
    AFFINEANIMCMD_END
};

ROULETTE_DATA static const union AffineAnimCmd *const sAffineAnims_Unused2[] =
{
    sAffineAnim_Unused2
};

ROULETTE_DATA static const struct CompressedSpriteSheet sSpriteSheet_WheelIcons =
{
    .data = sWheelIcons_Gfx,
    .size = 0xC00,
    .tag = GFXTAG_WHEEL_ICONS
};

ROULETTE_DATA static const union AnimCmd sAnim_WheelIcons[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_FRAME(72, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(40, 0),
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_FRAME(56, 0),
    ANIMCMD_FRAME(88, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_OrangeWynaut[] =
{
    &sAnim_WheelIcons[0]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_GreenAzurill[] =
{
    &sAnim_WheelIcons[1]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_PurpleSkitty[] =
{
    &sAnim_WheelIcons[2]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_OrangeMakuhita[] =
{
    &sAnim_WheelIcons[3]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_GreenWynaut[] =
{
    &sAnim_WheelIcons[4]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_PurpleAzurill[] =
{
    &sAnim_WheelIcons[5]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_OrangeSkitty[] =
{
    &sAnim_WheelIcons[6]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_GreenMakuhita[] =
{
    &sAnim_WheelIcons[7]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_PurpleWynaut[] =
{
    &sAnim_WheelIcons[8]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_OrangeAzurill[] =
{
    &sAnim_WheelIcons[9]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_GreenSkitty[] =
{
    &sAnim_WheelIcons[10]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WheelIcon_PurpleMakuhita[] =
{
    &sAnim_WheelIcons[11]
};

ROULETTE_DATA static const struct CompressedSpriteSheet sSpriteSheet_Headers =
{
    .data = gRouletteHeaders_Gfx,
    .size = 0x1600,
    .tag = GFXTAG_HEADERS
};

ROULETTE_DATA static const struct CompressedSpriteSheet sSpriteSheet_GridIcons =
{
    .data = sGridIcons_Gfx,
    .size = 0x400,
    .tag = GFXTAG_GRID_ICONS
};

ROULETTE_DATA static const union AnimCmd sAnim_Headers[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_FRAME(96, 0),
    ANIMCMD_FRAME(112, 0),
    ANIMCMD_FRAME(128, 0),
    ANIMCMD_FRAME(144, 0),
    ANIMCMD_FRAME(160, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd sAnim_GridIcons[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd *const sAnim_WynautHeader[] =
{
    &sAnim_Headers[0]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_AzurillHeader[] =
{
    &sAnim_Headers[2]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_SkittyHeader[] =
{
    &sAnim_Headers[4]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_MakuhitaHeader[] =
{
    &sAnim_Headers[6]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_OrangeHeader[] =
{
    &sAnim_Headers[8]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_GreenHeader[] =
{
    &sAnim_Headers[9]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_PurpleHeader[] =
{
    &sAnim_Headers[10]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_GridIcon_Wynaut[] =
{
    &sAnim_GridIcons[0]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_GridIcon_Azurill[] =
{
    &sAnim_GridIcons[1]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_GridIcon_Skitty[] =
{
    &sAnim_GridIcons[2]
};

ROULETTE_DATA static const union AnimCmd *const sAnim_GridIcon_Makuhita[] =
{
    &sAnim_GridIcons[3]
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplates_PokeHeaders[NUM_BOARD_POKES] =
{
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridHeader,
        .anims = sAnim_WynautHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridHeader,
        .anims = sAnim_AzurillHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridHeader,
        .anims = sAnim_SkittyHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridHeader,
        .anims = sAnim_MakuhitaHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    }
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplates_ColorHeaders[NUM_BOARD_COLORS] =
{
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridHeader,
        .anims = sAnim_OrangeHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridHeader,
        .anims = sAnim_GreenHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    },
    {
        .tileTag = GFXTAG_HEADERS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridHeader,
        .anims = sAnim_PurpleHeader,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    }
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplates_GridIcons[NUM_BOARD_POKES] =
{
    {
        .tileTag = GFXTAG_GRID_ICONS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridIcon,
        .anims = sAnim_GridIcon_Wynaut,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    },
    {
        .tileTag = GFXTAG_GRID_ICONS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridIcon,
        .anims = sAnim_GridIcon_Azurill,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    },
    {
        .tileTag = GFXTAG_GRID_ICONS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridIcon,
        .anims = sAnim_GridIcon_Skitty,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    },
    {
        .tileTag = GFXTAG_GRID_ICONS,
        .paletteTag = PALTAG_GRID_ICONS,
        .oam = &sOam_GridIcon,
        .anims = sAnim_GridIcon_Makuhita,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_081439D8
    }
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplates_WheelIcons[NUM_ROULETTE_SLOTS] =
{
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_WYNAUT,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_OrangeWynaut,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_AZURILL,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_GreenAzurill,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_SKITTY,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_PurpleSkitty,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_MAKUHITA,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_OrangeMakuhita,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_WYNAUT,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_GreenWynaut,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_AZURILL,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_PurpleAzurill,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_SKITTY,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_OrangeSkitty,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_MAKUHITA,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_GreenMakuhita,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_WYNAUT,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_PurpleWynaut,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_AZURILL,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_OrangeAzurill,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_SKITTY,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_GreenSkitty,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    },
    {
        .tileTag = GFXTAG_WHEEL_ICONS,
        .paletteTag = PALTAG_MAKUHITA,
        .oam = &sOam_WheelIcon,
        .anims = sAnim_WheelIcon_PurpleMakuhita,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_0814334C
    }
};

ROULETTE_DATA static const struct OamData sOam_Credit =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1,
};

ROULETTE_DATA static const struct OamData sOam_CreditDigit =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(8x16),
    .size = SPRITE_SIZE(8x16),
    .priority = 1,
};

ROULETTE_DATA static const struct OamData sOam_Multiplier =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 1,
};

ROULETTE_DATA static const struct OamData sOam_BallCounter =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x8),
    .size = SPRITE_SIZE(16x8),
    .priority = 1,
};

ROULETTE_DATA static const struct CompressedSpriteSheet sSpriteSheets_Interface[] =
{
    {
        .data = gRouletteCredit_Gfx,
        .size = 0x400,
        .tag = GFXTAG_CREDIT
    },
    {
        .data = gRouletteNumbers_Gfx,
        .size = 0x280,
        .tag = GFXTAG_CREDIT_DIGIT
    },
    {
        .data = gRouletteMultiplier_Gfx,
        .size = 0x500,
        .tag = GFXTAG_MULTIPLIER
    },
    {
        .data = sBallCounter_Gfx,
        .size = 0x140,
        .tag = GFXTAG_BALL_COUNTER
    },
    {
        .data = sCursor_Gfx,
        .size = 0x200,
        .tag = GFXTAG_CURSOR
    },
    {}
};

ROULETTE_DATA static const union AnimCmd sAnim_CreditDigit[] =
{
    ANIMCMD_FRAME(0, 0),  // 0
    ANIMCMD_FRAME(2, 0),  // 1
    ANIMCMD_FRAME(4, 0),  // 2
    ANIMCMD_FRAME(6, 0),  // 3
    ANIMCMD_FRAME(8, 0),  // 4
    ANIMCMD_FRAME(10, 0), // 5
    ANIMCMD_FRAME(12, 0), // 6
    ANIMCMD_FRAME(14, 0), // 7
    ANIMCMD_FRAME(16, 0), // 8
    ANIMCMD_FRAME(18, 0), // 9
    // BUG: Animation not terminated properly
    // Doesn't matter in practice, the frames are set directly and not looped
#ifdef BUGFIX
    ANIMCMD_END
#endif
};

ROULETTE_DATA static const union AnimCmd *const sAnims_CreditDigit[] =
{
    sAnim_CreditDigit
};

ROULETTE_DATA static const union AnimCmd sAnim_Multiplier[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_FRAME(24, 0),
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd *const sAnims_Multiplier[] =
{
    sAnim_Multiplier
};

ROULETTE_DATA static const union AnimCmd sAnim_BallCounter[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_FRAME(6, 0),
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd *const sAnims_BallCounter[] =
{
    sAnim_BallCounter
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_Credit =
{
    .tileTag = GFXTAG_CREDIT,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_Credit,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_CreditDigit =
{
    .tileTag = GFXTAG_CREDIT_DIGIT,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_CreditDigit,
    .anims = sAnims_CreditDigit,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_Multiplier =
{
    .tileTag = GFXTAG_MULTIPLIER,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_Multiplier,
    .anims = sAnims_Multiplier,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = (SpriteCallback)sub_081439D8
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_BallCounter =
{
    .tileTag = GFXTAG_BALL_COUNTER,
    .paletteTag = PALTAG_BALL_COUNTER,
    .oam = &sOam_BallCounter,
    .anims = sAnims_BallCounter,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_INTERFACE,
    .oam = &sOam_GridHeader,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

ROULETTE_DATA static const struct OamData sOam_Ball =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

ROULETTE_DATA static const struct CompressedSpriteSheet sSpriteSheet_Ball = {
    .data = sBall_Gfx,
    .size = 0x200,
    .tag = GFXTAG_BALL
};

ROULETTE_DATA static const union AnimCmd sAnim_Ball_RollFast[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_JUMP(0)
};

ROULETTE_DATA static const union AnimCmd sAnim_Ball_RollMedium[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_FRAME(8, 10),
    ANIMCMD_FRAME(4, 10),
    ANIMCMD_JUMP(0)
};

ROULETTE_DATA static const union AnimCmd sAnim_Ball_RollSlow[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(4, 15),
    ANIMCMD_FRAME(8, 15),
    ANIMCMD_FRAME(4, 15),
    ANIMCMD_JUMP(0)
};

ROULETTE_DATA static const union AnimCmd sAnim_Ball_StopOnFrame1[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd sAnim_Ball_StopOnFrame3[] =
{
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd sAnim_Ball_StopOnFrame4[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd sAnim_Ball_Still[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd sAnim_Ball_StopOnFrame2[] =
{
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(12, 5),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd *const sAnims_Ball[] =
{
    sAnim_Ball_RollFast,
    sAnim_Ball_RollMedium,
    sAnim_Ball_RollSlow,
    sAnim_Ball_StopOnFrame1,
    sAnim_Ball_StopOnFrame2,
    sAnim_Ball_StopOnFrame3,
    sAnim_Ball_StopOnFrame4,
    sAnim_Ball_StopOnFrame4,
    sAnim_Ball_Still
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_Ball =
{
    .tileTag = GFXTAG_BALL,
    .paletteTag = PALTAG_BALL,
    .oam = &sOam_Ball,
    .anims = sAnims_Ball,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

ROULETTE_DATA static const struct OamData sOam_WheelCenter =
{
    .y = 81,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 2,
};

ROULETTE_DATA static const struct CompressedSpriteSheet sSpriteSheet_WheelCenter =
{
    .data = gRouletteCenter_Gfx,
    .size = 0x800,
    .tag = GFXTAG_WHEEL_CENTER
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_WheelCenter =
{
    .tileTag = GFXTAG_WHEEL_CENTER,
    .paletteTag = PALTAG_BALL,
    .oam = &sOam_WheelCenter,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = (SpriteCallback)sub_08143A68
};

ROULETTE_DATA static const struct OamData sOam_Shroomish =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

ROULETTE_DATA static const struct OamData sOam_Taillow =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x32),
    .size = SPRITE_SIZE(32x32),
    .priority = 2,
};

ROULETTE_DATA static const struct CompressedSpriteSheet sSpriteSheet_ShroomishTaillow =
{
    .data = sShroomishTaillow_Gfx,
    .size = 0xE00,
    .tag = GFXTAG_SHROOMISH_TAILLOW
};

ROULETTE_DATA static const union AnimCmd sAnim_Shroomish[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(16, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(48, 6),
    ANIMCMD_FRAME(32, 6),
    ANIMCMD_FRAME(64, 6),
    ANIMCMD_JUMP(2)
};

ROULETTE_DATA static const union AnimCmd sAnim_Taillow_WingDown_Left[] =
{
    ANIMCMD_FRAME(80, 10),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd sAnim_Taillow_WingDown_Right[] =
{
    ANIMCMD_FRAME(80, 10, .hFlip = TRUE),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd sAnim_Taillow_FlapSlow_Left[] =
{
    ANIMCMD_FRAME(80, 20),
    ANIMCMD_FRAME(96, 20),
    ANIMCMD_JUMP(0)
};

ROULETTE_DATA static const union AnimCmd sAnim_Taillow_FlapSlow_Right[] =
{
    ANIMCMD_FRAME(80, 20, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 20, .hFlip = TRUE),
    ANIMCMD_JUMP(0)
};

ROULETTE_DATA static const union AnimCmd sAnim_Taillow_FlapFast_Left[] =
{
    ANIMCMD_FRAME(80, 10),
    ANIMCMD_FRAME(96, 10),
    ANIMCMD_JUMP(0)
};

ROULETTE_DATA static const union AnimCmd sAnim_Taillow_FlapFast_Right[] =
{
    ANIMCMD_FRAME(80, 10, .hFlip = TRUE),
    ANIMCMD_FRAME(96, 10, .hFlip = TRUE),
    ANIMCMD_JUMP(0)
};

ROULETTE_DATA static const union AnimCmd *const sAnims_Shroomish[] =
{
    sAnim_Shroomish
};

ROULETTE_DATA static const union AnimCmd *const sAnims_Taillow[] =
{
    sAnim_Taillow_WingDown_Left,   // While gliding in
    sAnim_Taillow_WingDown_Right,
    sAnim_Taillow_FlapSlow_Left,   // While carrying ball
    sAnim_Taillow_FlapSlow_Right,
    sAnim_Taillow_FlapFast_Left,   // While flying off
    sAnim_Taillow_FlapFast_Right
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_Shroomish =
{
    .tileTag = GFXTAG_SHROOMISH_TAILLOW,
    .paletteTag = PALTAG_SHROOMISH,
    .oam = &sOam_Shroomish,
    .anims = sAnims_Shroomish,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_Taillow =
{
    .tileTag = GFXTAG_SHROOMISH_TAILLOW,
    .paletteTag = PALTAG_TAILLOW,
    .oam = &sOam_Taillow,
    .anims = sAnims_Taillow,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = (SpriteCallback)sub_08145360
};

ROULETTE_DATA static const struct OamData sOam_ShroomishBallShadow =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2,
};

ROULETTE_DATA static const struct OamData sOam_ShroomishShadow =
{
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2,
};

ROULETTE_DATA static const struct OamData sOam_TaillowShadow =
{
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2,
};

ROULETTE_DATA static const struct CompressedSpriteSheet sSpriteSheet_Shadow =
{
    .data = sShadow_Gfx,
    .size = 0x180,
    .tag = GFXTAG_SHADOW
};

ROULETTE_DATA static const union AffineAnimCmd sAffineAnim_Unused3[] =
{
    AFFINEANIMCMD_FRAME(0x80, 0x80, 0, 0),
    AFFINEANIMCMD_FRAME(2,    2,    0, 60),
    AFFINEANIMCMD_END
};

ROULETTE_DATA static const union AffineAnimCmd sAffineAnim_TaillowShadow[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(-2,    0x0,   0, 15),
    AFFINEANIMCMD_FRAME(-1,    -2,    0, 15),
    AFFINEANIMCMD_FRAME(-1,    -5,    0, 24),
    AFFINEANIMCMD_END
};

ROULETTE_DATA static const union AffineAnimCmd *const sAffineAnims_Unused3[] =
{
    sAffineAnim_Unused3
};

ROULETTE_DATA static const union AffineAnimCmd *const sAffineAnims_TaillowShadow[] =
{
    sAffineAnim_TaillowShadow
};

ROULETTE_DATA static const union AffineAnimCmd sAffineAnim_Unused4[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END
};

ROULETTE_DATA static const union AffineAnimCmd *const sAffineAnims_Unused4[] =
{
    sAffineAnim_Unused4
};

ROULETTE_DATA static const union AnimCmd sAnim_ShroomishBallShadow[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd sAnim_UnstickMonShadow[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

ROULETTE_DATA static const union AnimCmd *const sAnims_ShroomishBallShadow[] =
{
    sAnim_ShroomishBallShadow
};

ROULETTE_DATA static const union AnimCmd *const sAnims_UnstickMonShadow[] =
{
    sAnim_UnstickMonShadow
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_ShroomishShadow[] =
{
    // Ball's shadow as it flies up
    {
        .tileTag = GFXTAG_SHADOW,
        .paletteTag = PALTAG_SHADOW,
        .oam = &sOam_ShroomishBallShadow,
        .anims = sAnims_ShroomishBallShadow,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy
    },
    // Shroomish's Shadow
    {
        .tileTag = GFXTAG_SHADOW,
        .paletteTag = PALTAG_SHADOW,
        .oam = &sOam_ShroomishShadow,
        .anims = sAnims_UnstickMonShadow,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = (SpriteCallback)sub_08144F2C
    }
};

ROULETTE_DATA static const struct SpriteTemplate sSpriteTemplate_TaillowShadow =
{
    .tileTag = GFXTAG_SHADOW,
    .paletteTag = PALTAG_SHADOW,
    .oam = &sOam_TaillowShadow,
    .anims = sAnims_UnstickMonShadow,
    .images = NULL,
    .affineAnims = sAffineAnims_TaillowShadow,
    .callback = (SpriteCallback)sub_08145360
};

ROULETTE_DATA static const u8 sMultiplierAnimIds[5] = {0, 1, 2, 3, 4};

ROULETTE_DATA static const s16 sShroomishShadowCoords[2][2] __attribute__((aligned(2))) = {{116, 44}, {116, 112}};

ROULETTE_DATA static const s16 sTaillowStartCoords[2][2] = {{256, 84}, {-16, 84}};

ROULETTE_DATA static const u16 sShroomishShadowAlphas[] = {
    0x907,
    0x808,
    0x709,
    0x60A,
    0x50B,
    0x40C,
    0x30D,
    0x20E,
    0x10F,
    0x010,
};

ROULETTE_DATA static const u16 sShroomishScreenShakeOffsets[3][4] = {{-1, 0, 1, 0}, {-2, 0, 2, 0}, {-3, 0, 3, 0}};

ROULETTE_DATA static const s8 sTaillowXMoveOffsets[2] = {-1, 1};

ROULETTE_DATA static const s8 sTaillowYMoveOffsets[8][2] = {{2, 0}, {2, 0}, {2, -1}, {2, -1}, {2, -1}, {2, -1}, {2, -2}, {2, -2}};

#undef ROULETTE_DATA

__attribute__((naked)) void sub_08140300(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl RunTasks\n\t"
        "	bl AnimateSprites\n\t"
        "	bl BuildOamBuffer\n\t"
        "	ldr r0, _08140328\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r1, #0xb8\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140322\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl RouletteFlash_Run\n\t"
        "_08140322:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140328: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814032C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	bl LoadOam\n\t"
        "	bl ProcessSpriteCopyRequests\n\t"
        "	bl TransferPlttBuffer\n\t"
        "	bl sub_081428DC\n\t"
        "	ldr r4, _081403A0\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrh r0, [r0, #0x26]\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r1, r2, #0\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x14\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldrb r0, [r1, #1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140368\n\t"
        "	ldrh r1, [r1, #0x34]\n\t"
        "	movs r0, #0x52\n\t"
        "	bl SetGpuReg\n\t"
        "_08140368:\n\t"
        "	ldr r2, [r4]\n\t"
        "	movs r3, #0x2a\n\t"
        "	ldrsh r0, [r2, r3]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140388\n\t"
        "	ldr r1, _081403A4\n\t"
        "	ldr r3, _081403A8\n\t"
        "	adds r0, r2, r3\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _081403AC\n\t"
        "	str r0, [r1, #4]\n\t"
        "	ldr r0, _081403B0\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2, #0x2a]\n\t"
        "_08140388:\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r2, #0x28\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	cmp r1, #1\n\t"
        "	beq _081403B4\n\t"
        "	cmp r1, #1\n\t"
        "	ble _0814043C\n\t"
        "	cmp r1, #2\n\t"
        "	beq _081403EC\n\t"
        "	cmp r1, #0xff\n\t"
        "	beq _08140410\n\t"
        "	b _0814043C\n\t"
        "	.align 2, 0\n\t"
        "_081403A0: .4byte gUnknown_203A854\n\t"
        "_081403A4: .4byte 0x040000D4\n\t"
        "_081403A8: .4byte 0x0000133C\n\t"
        "_081403AC: .4byte 0x060021C0\n\t"
        "_081403B0: .4byte 0x800001A0\n\t"
        "_081403B4:\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	bl SetBgAttribute\n\t"
        "	movs r0, #0\n\t"
        "	bl ShowBg\n\t"
        "	ldr r1, _081403E0\n\t"
        "	ldr r2, [r4]\n\t"
        "	movs r3, #0xcf\n\t"
        "	lsls r3, r3, #2\n\t"
        "	adds r0, r2, r3\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _081403E4\n\t"
        "	str r0, [r1, #4]\n\t"
        "	ldr r0, _081403E8\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r2, #0x28]\n\t"
        "	b _0814043C\n\t"
        "	.align 2, 0\n\t"
        "_081403E0: .4byte 0x040000D4\n\t"
        "_081403E4: .4byte 0x0600F9C0\n\t"
        "_081403E8: .4byte 0x800001A0\n\t"
        "_081403EC:\n\t"
        "	ldr r1, _08140404\n\t"
        "	movs r2, #0xcf\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _08140408\n\t"
        "	str r0, [r1, #4]\n\t"
        "	ldr r0, _0814040C\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	b _0814043C\n\t"
        "	.align 2, 0\n\t"
        "_08140404: .4byte 0x040000D4\n\t"
        "_08140408: .4byte 0x0600F9C0\n\t"
        "_0814040C: .4byte 0x800001A0\n\t"
        "_08140410:\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #2\n\t"
        "	bl SetBgAttribute\n\t"
        "	movs r0, #0\n\t"
        "	bl ShowBg\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _08140444\n\t"
        "	mov r3, sp\n\t"
        "	str r3, [r1]\n\t"
        "	ldr r0, _08140448\n\t"
        "	str r0, [r1, #4]\n\t"
        "	ldr r0, _0814044C\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #0x28]\n\t"
        "_0814043C:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140444: .4byte 0x040000D4\n\t"
        "_08140448: .4byte 0x0600F9C0\n\t"
        "_0814044C: .4byte 0x810001A0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140450(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	movs r5, #0\n\t"
        "	str r5, [sp]\n\t"
        "	ldr r4, _081404C0\n\t"
        "	movs r0, #0xe6\n\t"
        "	lsls r0, r0, #6\n\t"
        "	bl AllocZeroed\n\t"
        "	str r0, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	bl ResetBgsAndClearDma3BusyFlags\n\t"
        "	ldr r1, _081404C4\n\t"
        "	movs r0, #1\n\t"
        "	movs r2, #3\n\t"
        "	bl InitBgsFromTemplates\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #0xbe\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #0\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r2, _081404C8\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r0, #1\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r0, _081404CC\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #2\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	ldr r0, _081404D0\n\t"
        "	bl InitWindows\n\t"
        "	bl sub_08196DF4\n\t"
        "	ldr r0, _081404D4\n\t"
        "	strb r5, [r0]\n\t"
        "	ldr r0, _081404D8\n\t"
        "	mov r1, sp\n\t"
        "	bl malloc_and_decompress\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r2, _081404DC\n\t"
        "	adds r1, r1, r2\n\t"
        "	str r0, [r1]\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081404C0: .4byte gUnknown_203A854\n\t"
        "_081404C4: .4byte sBgTemplates\n\t"
        "_081404C8: .4byte 0x0000117C\n\t"
        "_081404CC: .4byte 0x0000317C\n\t"
        "_081404D0: .4byte sWindowTemplates\n\t"
        "_081404D4: .4byte gUnknown_203A858\n\t"
        "_081404D8: .4byte sGrid_Tilemap\n\t"
        "_081404DC: .4byte 0x0000397C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081404E0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r5, _08140530\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r4, _08140534\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl Free\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [r0]\n\t"
        "	bl FreeAllWindowBuffers\n\t"
        "	movs r0, #0\n\t"
        "	bl UnsetBgTilemapBuffer\n\t"
        "	movs r0, #1\n\t"
        "	bl UnsetBgTilemapBuffer\n\t"
        "	movs r0, #2\n\t"
        "	bl UnsetBgTilemapBuffer\n\t"
        "	movs r0, #0\n\t"
        "	bl ResetBgsAndClearDma3BusyFlags\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r2, #0xe6\n\t"
        "	lsls r2, r2, #6\n\t"
        "	movs r1, #0\n\t"
        "	bl memset\n\t"
        "	ldr r0, [r5]\n\t"
        "	bl Free\n\t"
        "	str r4, [r5]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140530: .4byte gUnknown_203A854\n\t"
        "_08140534: .4byte 0x0000397C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140538(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r1, _081405CC\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	ldr r5, _081405D0\n\t"
        "	ldr r3, [r5]\n\t"
        "	ldr r4, _081405D4\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	ldrb r2, [r3, #4]\n\t"
        "	movs r0, #4\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3, #4]\n\t"
        "	ldrh r1, [r4]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140572\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #4]\n\t"
        "_08140572:\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r2, _081405D8\n\t"
        "	ldrb r0, [r1, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #3]\n\t"
        "	adds r1, #0x22\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldrb r0, [r1, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	adds r1, #0x23\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r2, [r5]\n\t"
        "	ldr r3, _081405DC\n\t"
        "	ldrb r1, [r2, #4]\n\t"
        "	lsls r0, r1, #0x1e\n\t"
        "	lsrs r0, r0, #0x1e\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r2, #0x19]\n\t"
        "	ldr r2, [r5]\n\t"
        "	ldrb r1, [r2, #0x1a]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x10\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #0x1a]\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r0, [r0, #0x19]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081405E8\n\t"
        "	ldr r4, _081405E0\n\t"
        "	ldr r3, _081405E4\n\t"
        "	mov r0, sp\n\t"
        "	ldrh r2, [r0]\n\t"
        "	b _081405F0\n\t"
        "	.align 2, 0\n\t"
        "_081405CC: .4byte sInitTableBgColors\n\t"
        "_081405D0: .4byte gUnknown_203A854\n\t"
        "_081405D4: .4byte gSpecialVar_0x8004\n\t"
        "_081405D8: .4byte sRouletteTables\n\t"
        "_081405DC: .4byte sTableMinBets\n\t"
        "_081405E0: .4byte gPlttBufferUnfaded\n\t"
        "_081405E4: .4byte gPlttBufferFaded\n\t"
        "_081405E8:\n\t"
        "	ldr r4, _0814065C\n\t"
        "	ldr r3, _08140660\n\t"
        "	mov r0, sp\n\t"
        "	ldrh r2, [r0, #2]\n\t"
        "_081405F0:\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xa2\n\t"
        "	strh r2, [r0]\n\t"
        "	ldr r1, _08140664\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	strh r0, [r3]\n\t"
        "	ands r0, r1\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0xa2\n\t"
        "	strh r0, [r2]\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r4]\n\t"
        "	ldr r0, _08140668\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0xb8\n\t"
        "	bl sub_08151654\n\t"
        "	movs r4, #0\n\t"
        "_08140616:\n\t"
        "	ldr r5, _08140668\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0xb8\n\t"
        "	lsls r2, r4, #3\n\t"
        "	ldr r1, _0814066C\n\t"
        "	adds r2, r2, r1\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl sub_08151668\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xc\n\t"
        "	bls _08140616\n\t"
        "	movs r4, #0\n\t"
        "_08140634:\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r4, r0\n\t"
        "	ldr r1, _08140670\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0x98\n\t"
        "	lsls r0, r0, #1\n\t"
        "	cmp r1, r0\n\t"
        "	beq _08140674\n\t"
        "	adds r0, #2\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0814067E\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r1, [r0, #2]\n\t"
        "	movs r2, #1\n\t"
        "	b _0814067A\n\t"
        "	.align 2, 0\n\t"
        "_0814065C: .4byte gPlttBufferUnfaded\n\t"
        "_08140660: .4byte gPlttBufferFaded\n\t"
        "_08140664: .4byte 0x0000FFFF\n\t"
        "_08140668: .4byte gUnknown_203A854\n\t"
        "_0814066C: .4byte sFlashData_Colors\n\t"
        "_08140670: .4byte gPlayerParty\n\t"
        "_08140674:\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r1, [r0, #2]\n\t"
        "	movs r2, #2\n\t"
        "_0814067A:\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #2]\n\t"
        "_0814067E:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #5\n\t"
        "	bls _08140634\n\t"
        "	bl RtcCalcLocalTime\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140694(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r0, _081406B4\n\t"
        "	movs r1, #0x87\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #8\n\t"
        "	bls _081406A8\n\t"
        "	b _081408C0\n\t"
        "_081406A8:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081406B8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081406B4: .4byte gMain\n\t"
        "_081406B8: .4byte _081406BC\n\t"
        "_081406BC:\n\t"
        "	.4byte _081406E0\n\t"
        "	.4byte _081406F8\n\t"
        "	.4byte _08140718\n\t"
        "	.4byte _0814072A\n\t"
        "	.4byte _08140764\n\t"
        "	.4byte _08140788\n\t"
        "	.4byte _081407A8\n\t"
        "	.4byte _08140818\n\t"
        "	.4byte _08140842\n\t"
        "_081406E0:\n\t"
        "	movs r0, #0\n\t"
        "	bl SetVBlankCallback\n\t"
        "	bl ScanlineEffect_Stop\n\t"
        "	bl SetVBlankHBlankCallbacksToNull\n\t"
        "	bl ResetVramOamAndBgCntRegs\n\t"
        "	bl ResetAllBgsCoordinates\n\t"
        "	b _081408C0\n\t"
        "_081406F8:\n\t"
        "	bl sub_08140450\n\t"
        "	bl DeactivateAllTextPrinters\n\t"
        "	movs r1, #0x90\n\t"
        "	lsls r1, r1, #6\n\t"
        "	movs r0, #0x50\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r1, _08140714\n\t"
        "	movs r0, #0x52\n\t"
        "	bl SetGpuReg\n\t"
        "	b _081408C0\n\t"
        "	.align 2, 0\n\t"
        "_08140714: .4byte 0x0000060A\n\t"
        "_08140718:\n\t"
        "	bl ResetPaletteFade\n\t"
        "	bl ResetSpriteData\n\t"
        "	bl ResetTasks\n\t"
        "	bl ResetTempTileDataBuffers\n\t"
        "	b _081408C0\n\t"
        "_0814072A:\n\t"
        "	ldr r0, _08140758\n\t"
        "	movs r2, #0xe0\n\t"
        "	lsls r2, r2, #1\n\t"
        "	movs r1, #0\n\t"
        "	bl LoadPalette\n\t"
        "	ldr r1, _0814075C\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp]\n\t"
        "	movs r0, #1\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl DecompressAndCopyTileDataToVram\n\t"
        "	ldr r1, _08140760\n\t"
        "	str r4, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl DecompressAndCopyTileDataToVram\n\t"
        "	b _081408C0\n\t"
        "	.align 2, 0\n\t"
        "_08140758: .4byte sWheel_Pal\n\t"
        "_0814075C: .4byte gRouletteMenu_Gfx\n\t"
        "_08140760: .4byte gRouletteWheel_Gfx\n\t"
        "_08140764:\n\t"
        "	bl FreeTempTileDataBuffersIfPossible\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140770\n\t"
        "	b _081408CE\n\t"
        "_08140770:\n\t"
        "	bl sub_08140538\n\t"
        "	ldr r1, _08140784\n\t"
        "	movs r0, #2\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl CopyToBgTilemapBuffer\n\t"
        "	b _081408C0\n\t"
        "	.align 2, 0\n\t"
        "_08140784: .4byte sWheel_Tilemap\n\t"
        "_08140788:\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_08142CD8\n\t"
        "	bl sub_08143A94\n\t"
        "	bl sub_081439E8\n\t"
        "	bl sub_081433E0\n\t"
        "	bl sub_08142D9C\n\t"
        "	bl sub_08143048\n\t"
        "	bl sub_081432B0\n\t"
        "	b _081408C0\n\t"
        "_081407A8:\n\t"
        "	bl AnimateSprites\n\t"
        "	bl BuildOamBuffer\n\t"
        "	bl GetCoins\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl sub_081435E0\n\t"
        "	movs r0, #6\n\t"
        "	bl sub_081437F8\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_0814379C\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_081425C4\n\t"
        "	ldr r4, _08140808\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _0814080C\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r5, #0\n\t"
        "	str r5, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, _08140810\n\t"
        "	movs r2, #0x3c\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _08140814\n\t"
        "	strh r5, [r0]\n\t"
        "	b _081408C0\n\t"
        "	.align 2, 0\n\t"
        "_08140808: .4byte gUnknown_203A858\n\t"
        "_0814080C: .4byte Roulette_Text_ControlsInstruction\n\t"
        "_08140810: .4byte gSpriteCoordOffsetX\n\t"
        "_08140814: .4byte gSpriteCoordOffsetY\n\t"
        "_08140818:\n\t"
        "	movs r1, #0x82\n\t"
        "	lsls r1, r1, #5\n\t"
        "	movs r0, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #1\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r0, #2\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r0, #0\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #1\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #2\n\t"
        "	bl ShowBg\n\t"
        "	b _081408C0\n\t"
        "_08140842:\n\t"
        "	movs r0, #1\n\t"
        "	bl EnableInterrupts\n\t"
        "	ldr r0, _081408A8\n\t"
        "	bl SetVBlankCallback\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0x10\n\t"
        "	movs r3, #0\n\t"
        "	bl BeginHardwarePaletteFade\n\t"
        "	ldr r0, _081408AC\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateTask\n\t"
        "	ldr r5, _081408B0\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0xa4\n\t"
        "	strb r0, [r1]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _081408B4\n\t"
        "	lsls r4, r0, #2\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r1\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r4, #0x14]\n\t"
        "	bl GetCoins\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "	bl GetCoins\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl AlertTVThatPlayerPlayedRoulette\n\t"
        "	ldr r0, _081408B8\n\t"
        "	movs r1, #1\n\t"
        "	bl CreateTask\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0xa5\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _081408BC\n\t"
        "	bl SetMainCallback2\n\t"
        "	b _081408CE\n\t"
        "	.align 2, 0\n\t"
        "_081408A8: .4byte sub_0814032C + 1\n\t"
        "_081408AC: .4byte sub_08140970 + 1\n\t"
        "_081408B0: .4byte gUnknown_203A854\n\t"
        "_081408B4: .4byte gTasks\n\t"
        "_081408B8: .4byte sub_081408DC + 1\n\t"
        "_081408BC: .4byte 0x08140301\n\t"
        "_081408C0:\n\t"
        "	ldr r1, _081408D8\n\t"
        "	movs r0, #0x87\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "_081408CE:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081408D8: .4byte gMain\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081408DC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r3, _0814096C\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x21\n\t"
        "	ldrb r2, [r0]\n\t"
        "	adds r1, r2, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x23\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r6, r3, #0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r2, r0\n\t"
        "	bne _08140922\n\t"
        "	adds r1, #0x21\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r2, [r6]\n\t"
        "	adds r3, r2, #0\n\t"
        "	adds r3, #0x22\n\t"
        "	ldrb r1, [r3]\n\t"
        "	ldrh r0, [r2, #0x24]\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r2, #0x24]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08140922\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r3, #0xb4\n\t"
        "	lsls r3, r3, #1\n\t"
        "	adds r0, r3, #0\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r2, #0x24]\n\t"
        "_08140922:\n\t"
        "	adds r4, r6, #0\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrh r0, [r0, #0x24]\n\t"
        "	bl Sin2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrh r0, [r0, #0x24]\n\t"
        "	bl Cos2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	lsls r0, r5, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08140946\n\t"
        "	adds r0, #0xf\n\t"
        "_08140946:\n\t"
        "	lsls r0, r0, #0xc\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldr r3, [r6]\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08140956\n\t"
        "	adds r0, #0xf\n\t"
        "_08140956:\n\t"
        "	asrs r0, r0, #4\n\t"
        "	strh r0, [r3, #0x32]\n\t"
        "	strh r0, [r3, #0x2c]\n\t"
        "	strh r5, [r3, #0x2e]\n\t"
        "	lsls r0, r5, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r3, #0x30]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0814096C: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140970(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl UpdatePaletteFade\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #0\n\t"
        "	bne _081409C6\n\t"
        "	movs r1, #0x90\n\t"
        "	lsls r1, r1, #6\n\t"
        "	movs r0, #0x50\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r1, _081409CC\n\t"
        "	movs r0, #0x52\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r1, _081409D0\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r5, [r0, #0x14]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081420BC\n\t"
        "	bl sub_08142138\n\t"
        "	bl sub_08143B0C\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_081425C4\n\t"
        "	movs r0, #6\n\t"
        "	bl sub_081437F8\n\t"
        "	ldr r1, _081409D4\n\t"
        "	ldr r2, _081409D8\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r3, #3\n\t"
        "	bl sub_08142044\n\t"
        "_081409C6:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081409CC: .4byte 0x00000808\n\t"
        "_081409D0: .4byte gTasks\n\t"
        "_081409D4: .4byte sub_08140A30 + 1\n\t"
        "_081409D8: .4byte 0x0000FFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081409DC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl DisplayYesNoMenuDefaultYes\n\t"
        "	ldr r5, _08140A24\n\t"
        "	ldrb r0, [r5]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r5]\n\t"
        "	ldr r2, _08140A28\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r5]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, _08140A2C\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DoYesNoFuncWithChoice\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140A24: .4byte gUnknown_203A858\n\t"
        "_08140A28: .4byte Roulette_Text_KeepPlaying\n\t"
        "_08140A2C: .4byte sYesNoTable_KeepPlaying\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140A30(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ClearStdWindowAndFrame\n\t"
        "	ldr r1, _08140A54\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08140A58\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140A54: .4byte gTasks\n\t"
        "_08140A58: .4byte sub_08140C98 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140A5C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _08140A7C\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0xa5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl DestroyTask\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_08141EAC\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140A7C: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140A80(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xf\n\t"
        "	bls _08140A92\n\t"
        "	b _08140BB0\n\t"
        "_08140A92:\n\t"
        "	lsls r0, r4, #2\n\t"
        "	ldr r1, _08140A9C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_08140A9C: .4byte _08140AA0\n\t"
        "_08140AA0:\n\t"
        "	.4byte _08140AE0\n\t"
        "	.4byte _08140B04\n\t"
        "	.4byte _08140B04\n\t"
        "	.4byte _08140B04\n\t"
        "	.4byte _08140B04\n\t"
        "	.4byte _08140B58\n\t"
        "	.4byte _08140BB0\n\t"
        "	.4byte _08140BB0\n\t"
        "	.4byte _08140BB0\n\t"
        "	.4byte _08140BB0\n\t"
        "	.4byte _08140B58\n\t"
        "	.4byte _08140BB0\n\t"
        "	.4byte _08140BB0\n\t"
        "	.4byte _08140BB0\n\t"
        "	.4byte _08140BB0\n\t"
        "	.4byte _08140B58\n\t"
        "_08140AE0:\n\t"
        "	ldr r0, _08140B00\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0xbe\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0x10\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xd\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xe\n\t"
        "	movs r3, #7\n\t"
        "	bl sub_08151FE4\n\t"
        "	b _08140C16\n\t"
        "	.align 2, 0\n\t"
        "_08140B00: .4byte gUnknown_203A854\n\t"
        "_08140B04:\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0xe\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	ldr r5, _08140B4C\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r4, #0xbe\n\t"
        "	lsls r4, r4, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x10\n\t"
        "	str r1, [sp]\n\t"
        "	movs r6, #0xd\n\t"
        "	str r6, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xe\n\t"
        "	movs r3, #7\n\t"
        "	bl sub_08151FE4\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r4, r0, r4\n\t"
        "	ldr r1, _08140B50\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _08140B54\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp]\n\t"
        "	str r6, [sp, #4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r2, r8\n\t"
        "	movs r3, #7\n\t"
        "	bl sub_08152034\n\t"
        "	b _08140C16\n\t"
        "	.align 2, 0\n\t"
        "_08140B4C: .4byte gUnknown_203A854\n\t"
        "_08140B50: .4byte 0x0000397C\n\t"
        "_08140B54: .4byte 0x00000232\n\t"
        "_08140B58:\n\t"
        "	subs r0, r4, #1\n\t"
        "	movs r1, #5\n\t"
        "	bl __divsi3\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xa\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r7, r1, #0x18\n\t"
        "	ldr r5, _08140BA8\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r4, #0xbe\n\t"
        "	lsls r4, r4, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r6, #0x10\n\t"
        "	str r6, [sp]\n\t"
        "	movs r1, #0xd\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xe\n\t"
        "	movs r3, #7\n\t"
        "	bl sub_08151FE4\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r4, r0, r4\n\t"
        "	ldr r1, _08140BAC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0xa0\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	str r6, [sp]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #0xe\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl sub_08152034\n\t"
        "	b _08140C16\n\t"
        "	.align 2, 0\n\t"
        "_08140BA8: .4byte gUnknown_203A854\n\t"
        "_08140BAC: .4byte 0x0000397C\n\t"
        "_08140BB0:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #5\n\t"
        "	bl __umodsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0xe\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov r8, r1\n\t"
        "	subs r0, r4, #1\n\t"
        "	movs r1, #5\n\t"
        "	bl __divsi3\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #7\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r7, r1, #0x18\n\t"
        "	ldr r5, _08140C24\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r4, #0xbe\n\t"
        "	lsls r4, r4, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0x10\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xd\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xe\n\t"
        "	movs r3, #7\n\t"
        "	bl sub_08151FE4\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r4, r0, r4\n\t"
        "	ldr r1, _08140C28\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x88\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp]\n\t"
        "	str r0, [sp, #4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r2, r8\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl sub_08152034\n\t"
        "_08140C16:\n\t"
        "	add sp, #8\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140C24: .4byte gUnknown_203A854\n\t"
        "_08140C28: .4byte 0x0000397C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140C2C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _08140C50\n\t"
        "	lsls r4, r0, #2\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r1\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	bl sub_0814379C\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	bl sub_08140A80\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140C50: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140C54(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r5, _08140C8C\n\t"
        "	ldr r2, [r5]\n\t"
        "	movs r6, #0\n\t"
        "	movs r1, #1\n\t"
        "	strh r1, [r2, #0x28]\n\t"
        "	ldr r1, _08140C90\n\t"
        "	lsls r4, r0, #2\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r1\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	bl sub_08140A80\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x23\n\t"
        "	movs r1, #2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x21\n\t"
        "	strb r6, [r0]\n\t"
        "	ldr r0, _08140C94\n\t"
        "	str r0, [r4]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140C8C: .4byte gUnknown_203A854\n\t"
        "_08140C90: .4byte gTasks\n\t"
        "_08140C94: .4byte sub_08141108 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140C98(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r1, _08140CEC\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r2, [r0, #8]\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140CF8\n\t"
        "	movs r3, #0xb\n\t"
        "	ldr r5, _08140CF0\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0xe4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r2, r0\n\t"
        "	ldr r0, _08140CF4\n\t"
        "	mov ip, r0\n\t"
        "	lsls r7, r6, #2\n\t"
        "	cmp r2, #0\n\t"
        "	beq _08140D36\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r5, #8\n\t"
        "_08140CC6:\n\t"
        "	lsls r0, r3, #0x10\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #9\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r3, r0, #0x10\n\t"
        "	asrs r2, r0, #0x10\n\t"
        "	cmp r2, #0xd\n\t"
        "	bgt _08140D36\n\t"
        "	ldr r1, [r4]\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldr r1, [r1, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08140CC6\n\t"
        "	b _08140D36\n\t"
        "	.align 2, 0\n\t"
        "_08140CEC: .4byte gUnknown_203A854\n\t"
        "_08140CF0: .4byte sGridSelections\n\t"
        "_08140CF4: .4byte gTasks\n\t"
        "_08140CF8:\n\t"
        "	movs r3, #6\n\t"
        "	ldr r5, _08140D64\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x80\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r2, r0\n\t"
        "	ldr r0, _08140D68\n\t"
        "	mov ip, r0\n\t"
        "	lsls r7, r6, #2\n\t"
        "	cmp r2, #0\n\t"
        "	beq _08140D36\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r5, #8\n\t"
        "_08140D12:\n\t"
        "	lsls r0, r3, #0x10\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #9\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r3, r0, #0x10\n\t"
        "	asrs r2, r0, #0x10\n\t"
        "	cmp r2, #9\n\t"
        "	bgt _08140D36\n\t"
        "	ldr r1, [r4]\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldr r1, [r1, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08140D12\n\t"
        "_08140D36:\n\t"
        "	adds r4, r7, r6\n\t"
        "	lsls r4, r4, #3\n\t"
        "	add r4, ip\n\t"
        "	movs r5, #0\n\t"
        "	strh r3, [r4, #0x10]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_081420BC\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	bl sub_081425C4\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	bl sub_0814379C\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	bl sub_0814234C\n\t"
        "	strh r5, [r4, #0xa]\n\t"
        "	ldr r0, _08140D6C\n\t"
        "	str r0, [r4]\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08140D64: .4byte sGridSelections\n\t"
        "_08140D68: .4byte gTasks\n\t"
        "_08140D6C: .4byte sub_08140C54 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140D70(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r5, r1, #0x18\n\t"
        "	movs r6, #0\n\t"
        "	movs r7, #0\n\t"
        "	ldr r1, _08140DB8\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #4\n\t"
        "	bl memcpy\n\t"
        "	ldrb r0, [r4]\n\t"
        "	mov r8, r0\n\t"
        "	cmp r5, #0\n\t"
        "	blt _08140DE4\n\t"
        "	cmp r5, #1\n\t"
        "	bgt _08140DBC\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r1, #5\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	movs r2, #0xf0\n\t"
        "	lsls r2, r2, #0x14\n\t"
        "	adds r1, r0, r2\n\t"
        "	lsrs r7, r1, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08140DE4\n\t"
        "	movs r6, #5\n\t"
        "	b _08140DE4\n\t"
        "	.align 2, 0\n\t"
        "_08140DB8: .4byte sGridMoveOffsets\n\t"
        "_08140DBC:\n\t"
        "	cmp r5, #3\n\t"
        "	bgt _08140DE4\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r1, #5\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r6, r1, #0x18\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #0x13\n\t"
        "	adds r0, r1, r2\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08140DE4\n\t"
        "	movs r6, #1\n\t"
        "_08140DE4:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	ldrh r2, [r4]\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r0, [r4]\n\t"
        "	lsls r1, r6, #0x18\n\t"
        "	asrs r3, r1, #0x18\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r2, r7, #0x18\n\t"
        "	cmp r0, r3\n\t"
        "	bge _08140E06\n\t"
        "	asrs r0, r2, #0x18\n\t"
        "	strh r0, [r4]\n\t"
        "_08140E06:\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	asrs r0, r2, #0x18\n\t"
        "	cmp r1, r0\n\t"
        "	ble _08140E12\n\t"
        "	strh r3, [r4]\n\t"
        "_08140E12:\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08140E24\n\t"
        "	movs r0, #0\n\t"
        "	b _08140E26\n\t"
        "_08140E24:\n\t"
        "	movs r0, #1\n\t"
        "_08140E26:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08140E34(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	movs r5, #0\n\t"
        "	ldr r4, _08141010\n\t"
        "	ldrh r1, [r4, #0x2e]\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140E70\n\t"
        "	movs r5, #1\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _08141014\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #8\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_08140D70\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08140E70\n\t"
        "	b _08141002\n\t"
        "_08140E70:\n\t"
        "	ldrh r1, [r4, #0x2e]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140E96\n\t"
        "	movs r5, #1\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _08141014\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #8\n\t"
        "	movs r1, #1\n\t"
        "	bl sub_08140D70\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08140E96\n\t"
        "	b _08141002\n\t"
        "_08140E96:\n\t"
        "	ldrh r1, [r4, #0x2e]\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140EBC\n\t"
        "	movs r5, #1\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _08141014\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #8\n\t"
        "	movs r1, #2\n\t"
        "	bl sub_08140D70\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08140EBC\n\t"
        "	b _08141002\n\t"
        "_08140EBC:\n\t"
        "	ldrh r1, [r4, #0x2e]\n\t"
        "	movs r0, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08140EE2\n\t"
        "	movs r5, #1\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _08141014\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #8\n\t"
        "	movs r1, #3\n\t"
        "	bl sub_08140D70\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08140EE2\n\t"
        "	b _08141002\n\t"
        "_08140EE2:\n\t"
        "	cmp r5, #0\n\t"
        "	bne _08140EE8\n\t"
        "	b _08141002\n\t"
        "_08140EE8:\n\t"
        "	ldr r0, _08141018\n\t"
        "	lsls r6, r7, #2\n\t"
        "	adds r4, r6, r7\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	bl sub_081425C4\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl sub_08140C2C\n\t"
        "	mov r1, sb\n\t"
        "	strh r1, [r4, #0xa]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r5, _0814101C\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0xb8\n\t"
        "	ldr r1, _08141020\n\t"
        "	bl sub_08151A78\n\t"
        "	ldr r5, [r5]\n\t"
        "	movs r2, #0xb8\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r3, r5, r2\n\t"
        "	ldrb r2, [r3]\n\t"
        "	movs r1, #0x7f\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r3]\n\t"
        "	movs r0, #0xb2\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r3, r5, r0\n\t"
        "	ldrb r2, [r3]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r3]\n\t"
        "	movs r0, #0xac\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r2, r5, r0\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r2]\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	bl sub_0814234C\n\t"
        "	movs r4, #0\n\t"
        "	mov sb, r6\n\t"
        "	ldr r1, _08141024\n\t"
        "	mov ip, r1\n\t"
        "	movs r2, #8\n\t"
        "	add r2, ip\n\t"
        "	mov sl, r2\n\t"
        "_08140F54:\n\t"
        "	ldr r0, _0814101C\n\t"
        "	ldr r5, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x29\n\t"
        "	adds r6, r5, #0\n\t"
        "	adds r6, #0x3c\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r1, ip\n\t"
        "	adds r3, r0, r1\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x40\n\t"
        "	add r0, sl\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r1, [r0]\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _08141028\n\t"
        "	mov r8, r2\n\t"
        "	mov r0, r8\n\t"
        "	ands r1, r0\n\t"
        "	ldrh r2, [r3, #4]\n\t"
        "	ldr r0, _0814102C\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r3, #4]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #3\n\t"
        "	bls _08140F54\n\t"
        "	ldr r0, _08141018\n\t"
        "	mov r2, sb\n\t"
        "	adds r1, r2, r7\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r3, [r1, #0x10]\n\t"
        "	subs r0, r3, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #3\n\t"
        "	bhi _08141002\n\t"
        "	ldr r2, _08141030\n\t"
        "	movs r0, #0x10\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r2, #8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, [r5, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08141002\n\t"
        "	subs r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	adds r0, #0x29\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08141024\n\t"
        "	adds r3, r0, r1\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x40\n\t"
        "	adds r1, #8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	mov r2, r8\n\t"
        "	ands r1, r2\n\t"
        "	ldrh r2, [r3, #4]\n\t"
        "	ldr r0, _0814102C\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r3, #4]\n\t"
        "_08141002:\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141010: .4byte gMain\n\t"
        "_08141014: .4byte gUnknown_3005B68\n\t"
        "_08141018: .4byte gTasks\n\t"
        "_0814101C: .4byte gUnknown_203A854\n\t"
        "_08141020: .4byte 0x0000FFFF\n\t"
        "_08141024: .4byte gSprites\n\t"
        "_08141028: .4byte 0x000003FF\n\t"
        "_0814102C: .4byte 0xFFFFFC00\n\t"
        "_08141030: .4byte sGridSelections\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141034(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	bl sub_080EF7A8\n\t"
        "	ldr r0, _08141054\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0xff\n\t"
        "	strh r0, [r1, #0x28]\n\t"
        "	ldrb r2, [r1, #0x19]\n\t"
        "	cmp r2, #1\n\t"
        "	bne _08141058\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x23\n\t"
        "	strb r2, [r0]\n\t"
        "	b _0814105E\n\t"
        "	.align 2, 0\n\t"
        "_08141054: .4byte gUnknown_203A854\n\t"
        "_08141058:\n\t"
        "	adds r1, #0x23\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "_0814105E:\n\t"
        "	ldr r0, _08141080\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x21\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, _08141084\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0x20\n\t"
        "	strh r1, [r0, #0xa]\n\t"
        "	ldr r1, _08141088\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141080: .4byte gUnknown_203A854\n\t"
        "_08141084: .4byte gTasks\n\t"
        "_08141088: .4byte sub_081411C4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814108C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r4, _081410FC\n\t"
        "	ldr r2, [r4]\n\t"
        "	ldrb r1, [r2, #0x1a]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	adds r2, #0x1b\n\t"
        "	adds r2, r2, r1\n\t"
        "	ldr r3, _08141100\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r5, r1, r3\n\t"
        "	ldrh r0, [r5, #0x10]\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldrb r0, [r1, #0x1a]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r1, #0x1b\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl sub_08142820\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r5, #0xc]\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldrb r0, [r1, #0x1a]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r1, #0x1b\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl sub_0814379C\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrb r1, [r0, #0x19]\n\t"
        "	ldrh r0, [r5, #0x22]\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r5, #0x22]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bge _081410EC\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #0x22]\n\t"
        "_081410EC:\n\t"
        "	ldrh r0, [r5, #0x22]\n\t"
        "	bl sub_081435E0\n\t"
        "	ldr r0, _08141104\n\t"
        "	str r0, [r5]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081410FC: .4byte gUnknown_203A854\n\t"
        "_08141100: .4byte gTasks\n\t"
        "_08141104: .4byte sub_08141034 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141108(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08140E34\n\t"
        "	ldr r1, _08141130\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x1e\n\t"
        "	beq _0814113E\n\t"
        "	cmp r0, #0x1e\n\t"
        "	bgt _08141134\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814113A\n\t"
        "	b _08141152\n\t"
        "	.align 2, 0\n\t"
        "_08141130: .4byte gTasks\n\t"
        "_08141134:\n\t"
        "	cmp r0, #0x3b\n\t"
        "	beq _0814114C\n\t"
        "	b _08141152\n\t"
        "_0814113A:\n\t"
        "	ldrb r0, [r4, #0x10]\n\t"
        "	b _08141140\n\t"
        "_0814113E:\n\t"
        "	movs r0, #0\n\t"
        "_08141140:\n\t"
        "	bl sub_08140A80\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	b _08141162\n\t"
        "_0814114C:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	b _08141162\n\t"
        "_08141152:\n\t"
        "	ldr r0, _081411A0\n\t"
        "	lsls r1, r5, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r0, [r1, #0xa]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "_08141162:\n\t"
        "	ldr r0, _081411A4\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081411BA\n\t"
        "	ldr r0, _081411A8\n\t"
        "	ldr r3, [r0]\n\t"
        "	ldr r2, _081411AC\n\t"
        "	ldr r1, _081411A0\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r0, #0x10\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r2, #8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, [r3, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081411B0\n\t"
        "	movs r0, #0x16\n\t"
        "	bl PlaySE\n\t"
        "	b _081411BA\n\t"
        "	.align 2, 0\n\t"
        "_081411A0: .4byte gTasks\n\t"
        "_081411A4: .4byte gMain\n\t"
        "_081411A8: .4byte gUnknown_203A854\n\t"
        "_081411AC: .4byte sGridSelections\n\t"
        "_081411B0:\n\t"
        "	movs r0, #0x5f\n\t"
        "	bl m4aSongNumStart\n\t"
        "	ldr r0, _081411C0\n\t"
        "	str r0, [r4]\n\t"
        "_081411BA:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081411C0: .4byte sub_0814108C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081411C4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _0814121C\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r4, r1, r2\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	subs r1, r0, #1\n\t"
        "	strh r1, [r4, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	ble _08141230\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #2\n\t"
        "	ble _081411F0\n\t"
        "	ldr r1, _08141220\n\t"
        "	ldrh r0, [r1]\n\t"
        "	adds r0, #2\n\t"
        "	strh r0, [r1]\n\t"
        "_081411F0:\n\t"
        "	ldr r0, _08141224\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrh r0, [r1, #0x26]\n\t"
        "	adds r0, #4\n\t"
        "	strh r0, [r1, #0x26]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x68\n\t"
        "	bne _08141248\n\t"
        "	ldr r2, _08141228\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x55\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r2, #0x1c\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, _0814122C\n\t"
        "	str r1, [r0]\n\t"
        "	b _08141248\n\t"
        "	.align 2, 0\n\t"
        "_0814121C: .4byte gTasks\n\t"
        "_08141220: .4byte gSpriteCoordOffsetX\n\t"
        "_08141224: .4byte gUnknown_203A854\n\t"
        "_08141228: .4byte gSprites\n\t"
        "_0814122C: .4byte SpriteCallbackDummy + 1\n\t"
        "_08141230:\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0xff\n\t"
        "	bl sub_08142F3C\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0xff\n\t"
        "	bl sub_08143104\n\t"
        "	ldr r0, _08141250\n\t"
        "	str r0, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "_08141248:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141250: .4byte sub_0814140C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141254(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	ldr r0, _08141270\n\t"
        "	ldr r3, [r0]\n\t"
        "	ldrb r2, [r3, #2]\n\t"
        "	adds r5, r0, #0\n\t"
        "	cmp r2, #2\n\t"
        "	bgt _08141274\n\t"
        "	cmp r2, #1\n\t"
        "	bge _0814127A\n\t"
        "	b _08141348\n\t"
        "	.align 2, 0\n\t"
        "_08141270: .4byte gUnknown_203A854\n\t"
        "_08141274:\n\t"
        "	cmp r2, #3\n\t"
        "	beq _081412DC\n\t"
        "	b _08141348\n\t"
        "_0814127A:\n\t"
        "	ldr r0, _081412A4\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	subs r0, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #5\n\t"
        "	bhi _081412AC\n\t"
        "	cmp r4, #0xb\n\t"
        "	bls _08141294\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814135E\n\t"
        "_08141294:\n\t"
        "	ldr r0, _081412A8\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	lsls r1, r1, #0x1e\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #2]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_081412A4: .4byte gLocalTime\n\t"
        "_081412A8: .4byte sRouletteTables\n\t"
        "_081412AC:\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081412C8\n\t"
        "	ldr r0, _081412C4\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	lsls r1, r1, #0x1e\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #2]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_081412C4: .4byte sRouletteTables\n\t"
        "_081412C8:\n\t"
        "	ldr r0, _081412D8\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	lsls r1, r1, #0x1e\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #2]\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_081412D8: .4byte sRouletteTables\n\t"
        "_081412DC:\n\t"
        "	ldr r0, _08141308\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	subs r0, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #6\n\t"
        "	bhi _08141310\n\t"
        "	cmp r4, #5\n\t"
        "	bls _081412F6\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814135E\n\t"
        "_081412F6:\n\t"
        "	ldr r0, _0814130C\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	lsls r1, r1, #0x1e\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #2]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_08141308: .4byte gLocalTime\n\t"
        "_0814130C: .4byte sRouletteTables\n\t"
        "_08141310:\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08141330\n\t"
        "	cmp r4, #6\n\t"
        "	bls _08141330\n\t"
        "	ldr r0, _0814132C\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	lsls r1, r1, #0x1e\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1, #2]\n\t"
        "	lsrs r0, r0, #2\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_0814132C: .4byte sRouletteTables\n\t"
        "_08141330:\n\t"
        "	ldr r1, _08141344\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_08141344: .4byte sRouletteTables\n\t"
        "_08141348:\n\t"
        "	ldr r0, _08141364\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	subs r0, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #5\n\t"
        "	bhi _08141380\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08141368\n\t"
        "_0814135E:\n\t"
        "	movs r0, #1\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_08141364: .4byte gLocalTime\n\t"
        "_08141368:\n\t"
        "	ldr r1, _0814137C\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_0814137C: .4byte sRouletteTables\n\t"
        "_08141380:\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081413B8\n\t"
        "	cmp r4, #0xc\n\t"
        "	bls _081413A4\n\t"
        "	ldr r1, _081413A0\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_081413A0: .4byte sRouletteTables\n\t"
        "_081413A4:\n\t"
        "	ldr r1, _081413B4\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_081413B4: .4byte sRouletteTables\n\t"
        "_081413B8:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081413F0\n\t"
        "	cmp r4, #0xc\n\t"
        "	bls _081413DC\n\t"
        "	ldr r1, _081413D8\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_081413D8: .4byte sRouletteTables\n\t"
        "_081413DC:\n\t"
        "	ldr r1, _081413EC\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	b _08141402\n\t"
        "	.align 2, 0\n\t"
        "_081413EC: .4byte sRouletteTables\n\t"
        "_081413F0:\n\t"
        "	ldr r1, _08141408\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #0x19\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "_08141402:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08141408: .4byte sRouletteTables\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814140C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "	movs r4, #0\n\t"
        "	ldr r1, _08141498\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #8\n\t"
        "	bl memcpy\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #0x64\n\t"
        "	bl __umodsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	ldr r3, _0814149C\n\t"
        "	ldr r0, [r3]\n\t"
        "	ldr r2, _081414A0\n\t"
        "	mov r5, sl\n\t"
        "	lsls r1, r5, #2\n\t"
        "	add r1, sl\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrh r2, [r1, #0x14]\n\t"
        "	adds r0, #0x7c\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r2, r0, #0\n\t"
        "	adds r2, #0x7f\n\t"
        "	strb r4, [r2]\n\t"
        "	subs r2, #1\n\t"
        "	strb r4, [r2]\n\t"
        "	adds r0, #0x7d\n\t"
        "	strb r4, [r0]\n\t"
        "	ldrh r0, [r1, #0x18]\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl sub_08141254\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r1, r4, #0x18\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl __modsi3\n\t"
        "	lsrs r4, r4, #0x19\n\t"
        "	subs r0, r0, r4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _081414A4\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	movs r5, #1\n\t"
        "	cmp r0, #0xc\n\t"
        "	bgt _08141490\n\t"
        "	movs r5, #0\n\t"
        "_08141490:\n\t"
        "	cmp r6, #0x4f\n\t"
        "	bhi _081414A8\n\t"
        "	lsls r0, r5, #0x19\n\t"
        "	b _081414B2\n\t"
        "	.align 2, 0\n\t"
        "_08141498: .4byte sBallStartAngles\n\t"
        "_0814149C: .4byte gUnknown_203A854\n\t"
        "_081414A0: .4byte gTasks\n\t"
        "_081414A4: .4byte gLocalTime\n\t"
        "_081414A8:\n\t"
        "	lsls r1, r5, #0x18\n\t"
        "	asrs r1, r1, #0x18\n\t"
        "	movs r0, #1\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #0x19\n\t"
        "_081414B2:\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _081415F8\n\t"
        "	ldr r6, [r0]\n\t"
        "	ldrb r0, [r6, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	ldr r1, _081415FC\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	asrs r4, r4, #0x18\n\t"
        "	ldrh r0, [r0, #0x1a]\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r0, #0x80\n\t"
        "	strh r4, [r0]\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	cmp r4, #0\n\t"
        "	bge _081414E4\n\t"
        "	ldr r1, _08141600\n\t"
        "	bl __addsf3\n\t"
        "_081414E4:\n\t"
        "	ldr r1, _08141604\n\t"
        "	bl __divsf3\n\t"
        "	bl __fixunssfsi\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r2, #0x82\n\t"
        "	adds r2, r2, r6\n\t"
        "	mov r8, r2\n\t"
        "	strh r0, [r2]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r0, #0x84\n\t"
        "	strh r4, [r0]\n\t"
        "	adds r0, #2\n\t"
        "	strh r4, [r0]\n\t"
        "	movs r0, #0x88\n\t"
        "	adds r0, r0, r6\n\t"
        "	mov sb, r0\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r7\n\t"
        "	lsls r1, r5, #0x18\n\t"
        "	asrs r1, r1, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r4, [r0, r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	cmp r4, #0\n\t"
        "	bge _08141530\n\t"
        "	ldr r1, _08141600\n\t"
        "	bl __addsf3\n\t"
        "_08141530:\n\t"
        "	mov r2, sb\n\t"
        "	str r0, [r2]\n\t"
        "	adds r7, r6, #0\n\t"
        "	adds r7, #0x8c\n\t"
        "	ldrb r0, [r6, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	ldr r5, _081415FC\n\t"
        "	adds r0, r0, r5\n\t"
        "	movs r1, #0x18\n\t"
        "	ldrsh r4, [r0, r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	adds r5, r0, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bge _0814155A\n\t"
        "	ldr r1, _08141600\n\t"
        "	bl __addsf3\n\t"
        "	adds r5, r0, #0\n\t"
        "_0814155A:\n\t"
        "	str r5, [r7]\n\t"
        "	adds r7, r6, #0\n\t"
        "	adds r7, #0x90\n\t"
        "	ldr r1, _08141608\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl __mulsf3\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl __subsf3\n\t"
        "	adds r5, r0, #0\n\t"
        "	mov r2, r8\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r4, [r2, r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bge _0814158A\n\t"
        "	ldr r1, _08141600\n\t"
        "	bl __addsf3\n\t"
        "	adds r2, r0, #0\n\t"
        "_0814158A:\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl __divsf3\n\t"
        "	str r0, [r7]\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x94\n\t"
        "	ldr r0, _0814160C\n\t"
        "	str r0, [r1]\n\t"
        "	adds r1, #8\n\t"
        "	ldr r0, _08141610\n\t"
        "	str r0, [r1]\n\t"
        "	adds r5, r6, #0\n\t"
        "	adds r5, #0x98\n\t"
        "	mov r1, r8\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r4, [r1, r2]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bge _081415C0\n\t"
        "	ldr r1, _08141600\n\t"
        "	bl __addsf3\n\t"
        "	adds r2, r0, #0\n\t"
        "_081415C0:\n\t"
        "	ldr r0, _08141614\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl __divsf3\n\t"
        "	bl __negsf2\n\t"
        "	str r0, [r5]\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0xa0\n\t"
        "	ldr r0, _08141618\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r1, _0814161C\n\t"
        "	mov r5, sl\n\t"
        "	lsls r0, r5, #2\n\t"
        "	add r0, sl\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08141620\n\t"
        "	str r1, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081415F8: .4byte gUnknown_203A854\n\t"
        "_081415FC: .4byte sRouletteTables\n\t"
        "_08141600: .4byte 0x47800000\n\t"
        "_08141604: .4byte 0x40A00000\n\t"
        "_08141608: .4byte 0x3F000000\n\t"
        "_0814160C: .4byte 0x42880000\n\t"
        "_08141610: .4byte 0x00000000\n\t"
        "_08141614: .4byte 0x41000000\n\t"
        "_08141618: .4byte 0x42100000\n\t"
        "_0814161C: .4byte gTasks\n\t"
        "_08141620: .4byte sub_08141624 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141624(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r4, _08141688\n\t"
        "	ldr r3, [r4]\n\t"
        "	ldrb r1, [r3, #3]\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r3, #3]\n\t"
        "	ldr r3, [r4]\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x7c\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #0x3c\n\t"
        "	ldrb r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r2, [r1]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r2, _0814168C\n\t"
        "	adds r1, r1, r2\n\t"
        "	str r1, [r3, #0x38]\n\t"
        "	ldr r2, _08141690\n\t"
        "	str r2, [r1, #0x1c]\n\t"
        "	ldr r1, _08141694\n\t"
        "	lsls r4, r0, #2\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r1\n\t"
        "	ldrh r1, [r4, #0x14]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r4, #0x14]\n\t"
        "	ldrh r0, [r4, #0x18]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x18]\n\t"
        "	movs r0, #6\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl sub_081437F8\n\t"
        "	movs r0, #0x5c\n\t"
        "	bl m4aSongNumStart\n\t"
        "	ldr r0, _08141698\n\t"
        "	str r0, [r4]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141688: .4byte gUnknown_203A854\n\t"
        "_0814168C: .4byte gSprites\n\t"
        "_08141690: .4byte sub_08144778 + 1\n\t"
        "_08141694: .4byte gTasks\n\t"
        "_08141698: .4byte sub_0814169C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814169C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r6, _081416D8\n\t"
        "	ldr r3, [r6]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x7d\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814178E\n\t"
        "	ldrb r1, [r3, #3]\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081416DC\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814178E\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r3, #3]\n\t"
        "	ldr r2, [r6]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x21\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	b _0814178E\n\t"
        "	.align 2, 0\n\t"
        "_081416D8: .4byte gUnknown_203A854\n\t"
        "_081416DC:\n\t"
        "	ldr r2, _08141750\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r0, r1, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r5, r0, r2\n\t"
        "	movs r2, #0xa\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	adds r7, r1, #0\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08141728\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x7e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_08142198\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, [r6]\n\t"
        "	ldrb r1, [r2, #0x1a]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	adds r2, #0x1b\n\t"
        "	adds r2, r2, r1\n\t"
        "	ldrb r1, [r2]\n\t"
        "	bl sub_081422B0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r5, #0x12]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08141728\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, #0xb8\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #5\n\t"
        "	bl sub_08151A24\n\t"
        "_08141728:\n\t"
        "	ldr r0, _08141750\n\t"
        "	adds r1, r7, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r4, r1, r0\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x3c\n\t"
        "	bgt _08141758\n\t"
        "	ldr r0, _08141754\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08141748\n\t"
        "	movs r0, #0x3c\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "_08141748:\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	b _0814178E\n\t"
        "	.align 2, 0\n\t"
        "_08141750: .4byte gTasks\n\t"
        "_08141754: .4byte gMain\n\t"
        "_08141758:\n\t"
        "	ldr r0, _08141794\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r0, [r1, #0x1a]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r1, #0x1b\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bl sub_081425C4\n\t"
        "	ldrh r1, [r4, #0x20]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_08142F3C\n\t"
        "	ldrb r1, [r4, #0x14]\n\t"
        "	subs r1, #1\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_08143104\n\t"
        "	movs r0, #0x20\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	ldr r0, _08141798\n\t"
        "	str r0, [r4]\n\t"
        "_0814178E:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141794: .4byte gUnknown_203A854\n\t"
        "_08141798: .4byte sub_0814179C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814179C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r1, _081417F4\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	subs r1, r0, #1\n\t"
        "	strh r1, [r4, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	ble _08141808\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #2\n\t"
        "	ble _081417C8\n\t"
        "	ldr r1, _081417F8\n\t"
        "	ldrh r0, [r1]\n\t"
        "	subs r0, #2\n\t"
        "	strh r0, [r1]\n\t"
        "_081417C8:\n\t"
        "	ldr r0, _081417FC\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrh r0, [r1, #0x26]\n\t"
        "	subs r0, #4\n\t"
        "	strh r0, [r1, #0x26]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x68\n\t"
        "	bne _08141830\n\t"
        "	ldr r2, _08141800\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x55\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r2, #0x1c\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, _08141804\n\t"
        "	str r1, [r0]\n\t"
        "	b _08141830\n\t"
        "	.align 2, 0\n\t"
        "_081417F4: .4byte gTasks\n\t"
        "_081417F8: .4byte gSpriteCoordOffsetX\n\t"
        "_081417FC: .4byte gUnknown_203A854\n\t"
        "_08141800: .4byte gSprites\n\t"
        "_08141804: .4byte sub_081439D8 + 1\n\t"
        "_08141808:\n\t"
        "	ldrh r0, [r4, #0x20]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl sub_0814321C\n\t"
        "	movs r1, #0x12\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0814181E\n\t"
        "	movs r0, #0x79\n\t"
        "	b _08141820\n\t"
        "_0814181E:\n\t"
        "	movs r0, #0x3d\n\t"
        "_08141820:\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	ldr r0, _08141838\n\t"
        "	lsls r1, r5, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _0814183C\n\t"
        "	str r0, [r1]\n\t"
        "_08141830:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141838: .4byte gTasks\n\t"
        "_0814183C: .4byte sub_08141840 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141840(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	ldr r1, _08141890\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	subs r1, r0, #1\n\t"
        "	strh r1, [r4, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #1\n\t"
        "	ble _081418B0\n\t"
        "	movs r0, #0xa\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r1, #0\n\t"
        "	bge _0814186A\n\t"
        "	adds r0, #0xf\n\t"
        "_0814186A:\n\t"
        "	asrs r0, r0, #4\n\t"
        "	lsls r0, r0, #4\n\t"
        "	subs r0, r1, r0\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08141894\n\t"
        "	cmp r0, #8\n\t"
        "	bne _081418BC\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0xff\n\t"
        "	bl sub_08142F3C\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0xff\n\t"
        "	bl sub_08143104\n\t"
        "	b _081418BC\n\t"
        "	.align 2, 0\n\t"
        "_08141890: .4byte gTasks\n\t"
        "_08141894:\n\t"
        "	ldrh r1, [r4, #0x20]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_08142F3C\n\t"
        "	ldrb r1, [r4, #0x14]\n\t"
        "	subs r1, #1\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_08143104\n\t"
        "	b _081418BC\n\t"
        "_081418B0:\n\t"
        "	ldr r1, _081418C4\n\t"
        "	adds r0, r2, #0\n\t"
        "	movs r2, #0x1e\n\t"
        "	movs r3, #0\n\t"
        "	bl sub_08142044\n\t"
        "_081418BC:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081418C4: .4byte sub_08141964 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081418C8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r1, _08141920\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r1, #0x12\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814192C\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0814192C\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _0814192C\n\t"
        "	bl IsFanfareTaskInactive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08141950\n\t"
        "	movs r0, #0x1d\n\t"
        "	bl GetGameStat\n\t"
        "	ldrh r1, [r4, #0x1e]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r4, #0x1e]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	cmp r0, r1\n\t"
        "	bhs _08141910\n\t"
        "	movs r0, #0x1e\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	movs r0, #0x1d\n\t"
        "	bl SetGameStat\n\t"
        "_08141910:\n\t"
        "	ldr r1, _08141924\n\t"
        "	ldr r2, _08141928\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r3, #3\n\t"
        "	bl sub_08142044\n\t"
        "	b _08141950\n\t"
        "	.align 2, 0\n\t"
        "_08141920: .4byte gTasks\n\t"
        "_08141924: .4byte sub_08141AE0 + 1\n\t"
        "_08141928: .4byte 0x0000FFFF\n\t"
        "_0814192C:\n\t"
        "	bl IsSEPlaying\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0\n\t"
        "	bne _08141950\n\t"
        "	ldr r1, _08141958\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r2, [r0, #0x1e]\n\t"
        "	ldr r1, _0814195C\n\t"
        "	ldr r2, _08141960\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r3, #3\n\t"
        "	bl sub_08142044\n\t"
        "_08141950:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141958: .4byte gTasks\n\t"
        "_0814195C: .4byte sub_08141B88 + 1\n\t"
        "_08141960: .4byte 0x0000FFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141964(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r1, _081419A4\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	cmp r1, #0\n\t"
        "	beq _081419F0\n\t"
        "	cmp r1, #0\n\t"
        "	blt _081419F0\n\t"
        "	cmp r1, #2\n\t"
        "	bgt _081419F0\n\t"
        "	movs r1, #0xc\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	cmp r0, #0xc\n\t"
        "	bne _081419B4\n\t"
        "	ldr r0, _081419A8\n\t"
        "	bl PlayFanfare\n\t"
        "	ldr r4, _081419AC\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _081419B0\n\t"
        "	b _081419CA\n\t"
        "	.align 2, 0\n\t"
        "_081419A4: .4byte gTasks\n\t"
        "_081419A8: .4byte SPECIAL_GetMysteryGiftCardStat\n\t"
        "_081419AC: .4byte gUnknown_203A858\n\t"
        "_081419B0: .4byte Roulette_Text_Jackpot\n\t"
        "_081419B4:\n\t"
        "	movs r0, #0xc3\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl PlayFanfare\n\t"
        "	ldr r4, _081419E8\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _081419EC\n\t"
        "_081419CA:\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	b _08141A20\n\t"
        "	.align 2, 0\n\t"
        "_081419E8: .4byte gUnknown_203A858\n\t"
        "_081419EC: .4byte Roulette_Text_ItsAHit\n\t"
        "_081419F0:\n\t"
        "	movs r0, #0x20\n\t"
        "	bl m4aSongNumStart\n\t"
        "	ldr r4, _08141A3C\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _08141A40\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "_08141A20:\n\t"
        "	ldr r1, _08141A44\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0, #0xa]\n\t"
        "	ldr r1, _08141A48\n\t"
        "	str r1, [r0]\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141A3C: .4byte gUnknown_203A858\n\t"
        "_08141A40: .4byte Roulette_Text_NothingDoing\n\t"
        "_08141A44: .4byte gTasks\n\t"
        "_08141A48: .4byte sub_081418C8 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141A4C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r1, _08141A70\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r0, #0x16\n\t"
        "	ldrsh r5, [r4, r0]\n\t"
        "	cmp r5, #0\n\t"
        "	beq _08141A74\n\t"
        "	cmp r5, #3\n\t"
        "	beq _08141AA4\n\t"
        "	ldrh r0, [r4, #0x16]\n\t"
        "	adds r0, #1\n\t"
        "	b _08141AAC\n\t"
        "	.align 2, 0\n\t"
        "_08141A70: .4byte gTasks\n\t"
        "_08141A74:\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "	movs r0, #0x15\n\t"
        "	bl m4aSongNumStart\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	bl sub_081435E0\n\t"
        "	movs r2, #0x22\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	ldr r0, _08141A94\n\t"
        "	cmp r1, r0\n\t"
        "	ble _08141A98\n\t"
        "	strh r5, [r4, #0xa]\n\t"
        "	b _08141AAE\n\t"
        "	.align 2, 0\n\t"
        "_08141A94: .4byte 0x0000270E\n\t"
        "_08141A98:\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	ldrh r0, [r4, #0x16]\n\t"
        "	adds r0, #1\n\t"
        "	b _08141AAC\n\t"
        "_08141AA4:\n\t"
        "	movs r0, #0x15\n\t"
        "	bl m4aSongNumStop\n\t"
        "	movs r0, #0\n\t"
        "_08141AAC:\n\t"
        "	strh r0, [r4, #0x16]\n\t"
        "_08141AAE:\n\t"
        "	ldr r0, _08141AD4\n\t"
        "	lsls r1, r6, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r2, #0xa\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08141ACC\n\t"
        "	ldr r1, _08141AD8\n\t"
        "	ldr r2, _08141ADC\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r3, #3\n\t"
        "	bl sub_08142044\n\t"
        "_08141ACC:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141AD4: .4byte gTasks\n\t"
        "_08141AD8: .4byte sub_08141B88 + 1\n\t"
        "_08141ADC: .4byte 0x0000FFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141AE0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r3, _08141B6C\n\t"
        "	ldr r1, _08141B70\n\t"
        "	mov sb, r1\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldrb r2, [r1, #0x19]\n\t"
        "	ldr r1, _08141B74\n\t"
        "	lsls r4, r0, #2\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r1\n\t"
        "	movs r1, #0xc\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	adds r1, r2, #0\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r0, r3, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r2, _08141B78\n\t"
        "	mov r8, r2\n\t"
        "	ldr r1, _08141B7C\n\t"
        "	mov r0, r8\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	ldr r5, _08141B80\n\t"
        "	ldrb r0, [r5]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r5]\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r6, #0\n\t"
        "	str r6, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	mov r2, r8\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r5]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	mov r1, sb\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldrb r1, [r0, #0x19]\n\t"
        "	movs r2, #0xc\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	muls r0, r1, r0\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	strh r6, [r4, #0x16]\n\t"
        "	ldr r0, _08141B84\n\t"
        "	str r0, [r4]\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141B6C: .4byte gStringVar1\n\t"
        "_08141B70: .4byte gUnknown_203A854\n\t"
        "_08141B74: .4byte gTasks\n\t"
        "_08141B78: .4byte gStringVar4\n\t"
        "_08141B7C: .4byte Roulette_Text_YouveWonXCoins\n\t"
        "_08141B80: .4byte gUnknown_203A858\n\t"
        "_08141B84: .4byte sub_08141A4C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141B88(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r5, _08141C08\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0xb8\n\t"
        "	ldr r1, _08141C0C\n\t"
        "	bl sub_08151A78\n\t"
        "	ldr r6, [r5]\n\t"
        "	movs r0, #0xb8\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r3, r6, r0\n\t"
        "	ldrb r2, [r3]\n\t"
        "	movs r1, #0x7f\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r3]\n\t"
        "	movs r0, #0xb2\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r3, r6, r0\n\t"
        "	ldrb r2, [r3]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r3]\n\t"
        "	movs r0, #0xac\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r2, r6, r0\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r2]\n\t"
        "	ldr r6, _08141C10\n\t"
        "	ldr r2, [r5]\n\t"
        "	ldr r5, _08141C14\n\t"
        "	ldr r0, _08141C18\n\t"
        "	lsls r3, r4, #2\n\t"
        "	adds r3, r3, r4\n\t"
        "	lsls r3, r3, #3\n\t"
        "	adds r3, r3, r0\n\t"
        "	movs r0, #0x20\n\t"
        "	ldrsh r1, [r3, r0]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r2, r2, r0\n\t"
        "	adds r2, #0x43\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _08141C1C\n\t"
        "	str r0, [r3]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141C08: .4byte gUnknown_203A854\n\t"
        "_08141C0C: .4byte 0x0000FFFF\n\t"
        "_08141C10: .4byte gSprites\n\t"
        "_08141C14: .4byte sGridSelections\n\t"
        "_08141C18: .4byte gTasks\n\t"
        "_08141C1C: .4byte sub_08141C20 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141C20(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	movs r5, #0\n\t"
        "	ldr r1, _08141D00\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "	strh r5, [r0, #0x10]\n\t"
        "	ldr r4, _08141D04\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldrb r0, [r1, #0x1a]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r1, #0x1b\n\t"
        "	adds r1, r1, r0\n\t"
        "	strb r2, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_081425C4\n\t"
        "	ldr r3, _08141D08\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x6c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r7, r3, #0\n\t"
        "	movs r0, #8\n\t"
        "	adds r0, r0, r7\n\t"
        "	mov ip, r0\n\t"
        "	ldr r1, _08141D0C\n\t"
        "	mov r8, r1\n\t"
        "_08141C78:\n\t"
        "	ldr r0, _08141D04\n\t"
        "	ldr r4, [r0]\n\t"
        "	adds r0, r4, r5\n\t"
        "	adds r0, #0x65\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r3, r0, r7\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x40\n\t"
        "	add r0, ip\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r1, [r0]\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _08141D10\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r1, r0\n\t"
        "	ldrh r2, [r3, #4]\n\t"
        "	mov r0, r8\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r3, #4]\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #3\n\t"
        "	bls _08141C78\n\t"
        "	ldr r0, _08141D00\n\t"
        "	lsls r1, r6, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r2, r1, r0\n\t"
        "	movs r1, #0x22\n\t"
        "	ldrsh r0, [r2, r1]\n\t"
        "	ldrb r4, [r4, #0x19]\n\t"
        "	cmp r0, r4\n\t"
        "	blt _08141D84\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r2, r1]\n\t"
        "	cmp r0, #6\n\t"
        "	bne _08141D20\n\t"
        "	ldr r4, _08141D14\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _08141D18\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, _08141D1C\n\t"
        "	b _08141D56\n\t"
        "	.align 2, 0\n\t"
        "_08141D00: .4byte gTasks\n\t"
        "_08141D04: .4byte gUnknown_203A854\n\t"
        "_08141D08: .4byte gSprites\n\t"
        "_08141D0C: .4byte 0xFFFFFC00\n\t"
        "_08141D10: .4byte 0x000003FF\n\t"
        "_08141D14: .4byte gUnknown_203A858\n\t"
        "_08141D18: .4byte Roulette_Text_BoardWillBeCleared\n\t"
        "_08141D1C: .4byte dp01t_12_3_battle_menu + 1\n\t"
        "_08141D20:\n\t"
        "	movs r0, #0x22\n\t"
        "	ldrsh r1, [r2, r0]\n\t"
        "	ldr r0, _08141D64\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08141D78\n\t"
        "	ldr r4, _08141D68\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _08141D6C\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, _08141D70\n\t"
        "_08141D56:\n\t"
        "	ldr r2, _08141D74\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r3, #3\n\t"
        "	bl sub_08142044\n\t"
        "	b _08141DBA\n\t"
        "	.align 2, 0\n\t"
        "_08141D64: .4byte 0x0000270F\n\t"
        "_08141D68: .4byte gUnknown_203A858\n\t"
        "_08141D6C: .4byte Roulette_Text_CoinCaseIsFull\n\t"
        "_08141D70: .4byte sub_081409DC + 1\n\t"
        "_08141D74: .4byte 0x0000FFFF\n\t"
        "_08141D78:\n\t"
        "	ldr r0, _08141D80\n\t"
        "	str r0, [r2]\n\t"
        "	b _08141DBA\n\t"
        "	.align 2, 0\n\t"
        "_08141D80: .4byte sub_081409DC + 1\n\t"
        "_08141D84:\n\t"
        "	ldr r4, _08141DC8\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _08141DCC\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, _08141DD0\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r2, #0x3c\n\t"
        "	movs r3, #3\n\t"
        "	bl sub_08142044\n\t"
        "_08141DBA:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141DC8: .4byte gUnknown_203A858\n\t"
        "_08141DCC: .4byte Roulette_Text_NoCoinsLeft\n\t"
        "_08141DD0: .4byte sub_08140A5C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void dp01t_12_3_battle_menu(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	movs r4, #0\n\t"
        "	ldr r1, _08141E7C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r4, [r0, #0x14]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_081420BC\n\t"
        "	bl sub_08142138\n\t"
        "	bl sub_08143B0C\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_081425C4\n\t"
        "	movs r0, #6\n\t"
        "	bl sub_081437F8\n\t"
        "	ldr r7, _08141E80\n\t"
        "	ldr r3, _08141E84\n\t"
        "	movs r6, #5\n\t"
        "	rsbs r6, r6, #0\n\t"
        "_08141E0C:\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x43\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, #0x3e\n\t"
        "	ldrb r2, [r1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xb\n\t"
        "	bls _08141E0C\n\t"
        "	ldr r1, _08141E7C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r2, r0, r1\n\t"
        "	movs r0, #0x22\n\t"
        "	ldrsh r1, [r2, r0]\n\t"
        "	ldr r0, _08141E88\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08141E9C\n\t"
        "	ldr r4, _08141E8C\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldrb r0, [r4]\n\t"
        "	ldr r2, _08141E90\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, _08141E94\n\t"
        "	ldr r2, _08141E98\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r3, #3\n\t"
        "	bl sub_08142044\n\t"
        "	b _08141EA0\n\t"
        "	.align 2, 0\n\t"
        "_08141E7C: .4byte gTasks\n\t"
        "_08141E80: .4byte gSprites\n\t"
        "_08141E84: .4byte gUnknown_203A854\n\t"
        "_08141E88: .4byte 0x0000270F\n\t"
        "_08141E8C: .4byte gUnknown_203A858\n\t"
        "_08141E90: .4byte Roulette_Text_CoinCaseIsFull\n\t"
        "_08141E94: .4byte sub_081409DC + 1\n\t"
        "_08141E98: .4byte 0x0000FFFF\n\t"
        "_08141E9C:\n\t"
        "	ldr r0, _08141EA8\n\t"
        "	str r0, [r2]\n\t"
        "_08141EA0:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141EA8: .4byte sub_081409DC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141EAC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r4, _08141EF0\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0xb8\n\t"
        "	ldr r1, _08141EF4\n\t"
        "	bl sub_08151A78\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0xb8\n\t"
        "	bl sub_08151654\n\t"
        "	ldr r1, _08141EF8\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0x22]\n\t"
        "	bl SetCoins\n\t"
        "	bl GetCoins\n\t"
        "	ldr r1, [r4]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldrb r1, [r1, #0x19]\n\t"
        "	cmp r0, r1\n\t"
        "	bhs _08141F00\n\t"
        "	ldr r1, _08141EFC\n\t"
        "	movs r0, #1\n\t"
        "	b _08141F04\n\t"
        "	.align 2, 0\n\t"
        "_08141EF0: .4byte gUnknown_203A854\n\t"
        "_08141EF4: .4byte 0x0000FFFF\n\t"
        "_08141EF8: .4byte gTasks\n\t"
        "_08141EFC: .4byte gSpecialVar_0x8004\n\t"
        "_08141F00:\n\t"
        "	ldr r1, _08141F38\n\t"
        "	movs r0, #0\n\t"
        "_08141F04:\n\t"
        "	strh r0, [r1]\n\t"
        "	bl GetCoins\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl TryPutFindThatGamerOnAir\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x10\n\t"
        "	bl BeginHardwarePaletteFade\n\t"
        "	ldr r1, _08141F3C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08141F40\n\t"
        "	str r1, [r0]\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141F38: .4byte gSpecialVar_0x8004\n\t"
        "_08141F3C: .4byte gTasks\n\t"
        "_08141F40: .4byte sub_08141F44 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141F44(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	bl UpdatePaletteFade\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	bne _08141FA6\n\t"
        "	movs r0, #0\n\t"
        "	bl SetVBlankCallback\n\t"
        "	ldr r1, _08141FAC\n\t"
        "	ldr r0, _08141FB0\n\t"
        "	strh r4, [r0]\n\t"
        "	strh r4, [r1]\n\t"
        "	bl ResetVramOamAndBgCntRegs\n\t"
        "	bl ResetAllBgsCoordinates\n\t"
        "	movs r0, #0x50\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x52\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x54\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	bl FreeAllSpritePalettes\n\t"
        "	bl ResetPaletteFade\n\t"
        "	bl ResetSpriteData\n\t"
        "	bl sub_081404E0\n\t"
        "	ldr r1, _08141FB4\n\t"
        "	ldr r0, _08141FB8\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _08141FBC\n\t"
        "	bl SetMainCallback2\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_08141FA6:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08141FAC: .4byte gSpriteCoordOffsetX\n\t"
        "_08141FB0: .4byte gSpriteCoordOffsetY\n\t"
        "_08141FB4: .4byte gFieldCallback\n\t"
        "_08141FB8: .4byte FieldCB_ContinueScriptHandleMusic + 1\n\t"
        "_08141FBC: .4byte CB2_ReturnToField + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08141FC0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08142034\n\t"
        "	ldr r3, [r1]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xa8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	adds r5, r1, #0\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08141FE6\n\t"
        "	ldr r0, _08142038\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0xaa\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	ldrh r0, [r2]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814201A\n\t"
        "_08141FE6:\n\t"
        "	ldr r1, _0814203C\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #0xac\n\t"
        "	ldr r1, [r1]\n\t"
        "	str r1, [r0]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0xaa\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08142008\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "_08142008:\n\t"
        "	ldr r2, [r5]\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0xac\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [r0]\n\t"
        "	subs r0, #2\n\t"
        "	strh r1, [r0]\n\t"
        "	subs r0, #2\n\t"
        "	strh r1, [r0]\n\t"
        "_0814201A:\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r1, #0xa8\n\t"
        "	ldrh r2, [r1]\n\t"
        "	ldr r0, _08142040\n\t"
        "	cmp r2, r0\n\t"
        "	beq _0814202C\n\t"
        "	subs r0, r2, #1\n\t"
        "	strh r0, [r1]\n\t"
        "_0814202C:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142034: .4byte gUnknown_203A854\n\t"
        "_08142038: .4byte gMain\n\t"
        "_0814203C: .4byte gTasks\n\t"
        "_08142040: .4byte 0x0000FFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142044(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r4, r2, #0x10\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r7, r3, #0x10\n\t"
        "	ldr r2, _08142094\n\t"
        "	ldr r0, [r2]\n\t"
        "	mov ip, r0\n\t"
        "	mov r3, ip\n\t"
        "	adds r3, #0xb4\n\t"
        "	ldr r1, _08142098\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r3]\n\t"
        "	adds r3, r1, #0\n\t"
        "	cmp r5, #0\n\t"
        "	bne _08142074\n\t"
        "	adds r5, r0, #0\n\t"
        "_08142074:\n\t"
        "	mov r0, ip\n\t"
        "	adds r0, #0xac\n\t"
        "	str r5, [r0]\n\t"
        "	subs r0, #4\n\t"
        "	strh r4, [r0]\n\t"
        "	ldr r0, _0814209C\n\t"
        "	cmp r4, r0\n\t"
        "	bne _081420A0\n\t"
        "	cmp r7, #0\n\t"
        "	bne _081420A0\n\t"
        "	mov r1, ip\n\t"
        "	adds r1, #0xaa\n\t"
        "	ldrh r0, [r1]\n\t"
        "	orrs r4, r0\n\t"
        "	strh r4, [r1]\n\t"
        "	b _081420A6\n\t"
        "	.align 2, 0\n\t"
        "_08142094: .4byte gUnknown_203A854\n\t"
        "_08142098: .4byte gTasks\n\t"
        "_0814209C: .4byte 0x0000FFFF\n\t"
        "_081420A0:\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0xaa\n\t"
        "	strh r7, [r0]\n\t"
        "_081420A6:\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldr r1, _081420B8\n\t"
        "	str r1, [r0]\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081420B8: .4byte sub_08141FC0 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081420BC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	movs r4, #0\n\t"
        "	ldr r3, _08142130\n\t"
        "	ldr r0, [r3]\n\t"
        "	strb r4, [r0]\n\t"
        "	ldr r2, [r3]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	ldr r2, [r3]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x21\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	ldr r2, [r3]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	ldr r2, [r3]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x20\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	ldr r6, _08142134\n\t"
        "	adds r2, r3, #0\n\t"
        "	movs r1, #0\n\t"
        "_081420FE:\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x1b\n\t"
        "	adds r0, r0, r4\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #5\n\t"
        "	bls _081420FE\n\t"
        "	ldr r2, [r3]\n\t"
        "	ldrb r1, [r2, #0x1a]\n\t"
        "	movs r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #0x1a]\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0, #0xa]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142130: .4byte gUnknown_203A854\n\t"
        "_08142134: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142138(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r2, _08142194\n\t"
        "	ldr r1, [r2]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1, #8]\n\t"
        "	movs r1, #0\n\t"
        "	movs r3, #0\n\t"
        "_08142146:\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0xc\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r3, [r0]\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #5\n\t"
        "	bls _08142146\n\t"
        "	movs r1, #0\n\t"
        "	ldr r3, _08142194\n\t"
        "	movs r2, #0\n\t"
        "_0814215E:\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x12\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r2, [r0]\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #3\n\t"
        "	bls _0814215E\n\t"
        "	movs r1, #0\n\t"
        "	ldr r3, _08142194\n\t"
        "	movs r2, #0\n\t"
        "_08142176:\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x16\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r2, [r0]\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #2\n\t"
        "	bls _08142176\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0xff\n\t"
        "	bl sub_08143104\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142194: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142198(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #0x1c\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r5, r1, #0x18\n\t"
        "	mov r1, sp\n\t"
        "	ldr r0, _081421CC\n\t"
        "	ldm r0!, {r2, r3, r6}\n\t"
        "	stm r1!, {r2, r3, r6}\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r1]\n\t"
        "	add r2, sp, #0x10\n\t"
        "	adds r1, r2, #0\n\t"
        "	ldr r0, _081421D0\n\t"
        "	ldm r0!, {r3, r6, r7}\n\t"
        "	stm r1!, {r3, r6, r7}\n\t"
        "	mov r8, r2\n\t"
        "	cmp r5, #0xb\n\t"
        "	bls _081421D4\n\t"
        "	movs r0, #0\n\t"
        "	b _08142290\n\t"
        "	.align 2, 0\n\t"
        "_081421CC: .4byte sBoardColumnFlags\n\t"
        "_081421D0: .4byte sBoardRowFlags\n\t"
        "_081421D4:\n\t"
        "	ldr r6, _081422A0\n\t"
        "	ldr r3, [r6]\n\t"
        "	ldr r1, _081422A4\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r7, #0x14\n\t"
        "	ldrsh r1, [r0, r7]\n\t"
        "	adds r3, r3, r1\n\t"
        "	ldr r4, _081422A8\n\t"
        "	lsls r5, r5, #3\n\t"
        "	adds r2, r5, r4\n\t"
        "	ldrb r1, [r2, #2]\n\t"
        "	strb r1, [r3, #0xb]\n\t"
        "	ldrb r1, [r2, #2]\n\t"
        "	strh r1, [r0, #0x20]\n\t"
        "	ldr r2, [r6]\n\t"
        "	adds r0, r4, #4\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldr r1, [r2, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	orrs r1, r0\n\t"
        "	str r1, [r2, #8]\n\t"
        "	movs r3, #0\n\t"
        "	mov sb, r4\n\t"
        "	mov ip, r5\n\t"
        "	adds r5, r0, #0\n\t"
        "_0814220C:\n\t"
        "	lsls r0, r3, #2\n\t"
        "	mov r1, sp\n\t"
        "	adds r4, r1, r0\n\t"
        "	ldr r0, [r4]\n\t"
        "	ands r0, r5\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08142226\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, #0x12\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "_08142226:\n\t"
        "	ldr r2, [r6]\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x12\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	bls _0814223C\n\t"
        "	ldr r0, [r2, #8]\n\t"
        "	ldr r1, [r4]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2, #8]\n\t"
        "_0814223C:\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	cmp r3, #3\n\t"
        "	bls _0814220C\n\t"
        "	movs r6, #0\n\t"
        "	ldr r0, _081422AC\n\t"
        "	add r0, ip\n\t"
        "	ldr r7, [r0]\n\t"
        "	ldr r4, _081422A0\n\t"
        "	mov r5, r8\n\t"
        "_08142252:\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r2, r5, r0\n\t"
        "	ldr r0, [r2]\n\t"
        "	ands r0, r7\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814226A\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, #0x16\n\t"
        "	adds r1, r1, r6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "_0814226A:\n\t"
        "	ldr r3, [r4]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x16\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #3\n\t"
        "	bls _08142280\n\t"
        "	ldr r0, [r3, #8]\n\t"
        "	ldr r1, [r2]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r3, #8]\n\t"
        "_08142280:\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #2\n\t"
        "	bls _08142252\n\t"
        "	mov r0, ip\n\t"
        "	add r0, sb\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "_08142290:\n\t"
        "	add sp, #0x1c\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081422A0: .4byte gUnknown_203A854\n\t"
        "_081422A4: .4byte gTasks\n\t"
        "_081422A8: .4byte sRouletteSlots\n\t"
        "_081422AC: .4byte sRouletteSlots + 4\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081422B0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r2, r1, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	movs r1, #0xff\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x12\n\t"
        "	bhi _08142344\n\t"
        "	cmp r2, #0xf\n\t"
        "	bhi _08142340\n\t"
        "	lsls r0, r2, #2\n\t"
        "	ldr r1, _081422D4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_081422D4: .4byte _081422D8\n\t"
        "_081422D8:\n\t"
        "	.4byte _08142318\n\t"
        "	.4byte _0814231C\n\t"
        "	.4byte _0814231C\n\t"
        "	.4byte _0814231C\n\t"
        "	.4byte _0814231C\n\t"
        "	.4byte _08142330\n\t"
        "	.4byte _08142340\n\t"
        "	.4byte _08142340\n\t"
        "	.4byte _08142340\n\t"
        "	.4byte _08142340\n\t"
        "	.4byte _08142330\n\t"
        "	.4byte _08142340\n\t"
        "	.4byte _08142340\n\t"
        "	.4byte _08142340\n\t"
        "	.4byte _08142340\n\t"
        "	.4byte _08142330\n\t"
        "_08142318:\n\t"
        "	movs r0, #3\n\t"
        "	b _08142346\n\t"
        "_0814231C:\n\t"
        "	adds r0, r2, #5\n\t"
        "	cmp r3, r0\n\t"
        "	beq _0814233C\n\t"
        "	adds r0, #5\n\t"
        "	cmp r3, r0\n\t"
        "	beq _0814233C\n\t"
        "	adds r0, #5\n\t"
        "	cmp r3, r0\n\t"
        "	bne _08142344\n\t"
        "	b _0814233C\n\t"
        "_08142330:\n\t"
        "	adds r0, r2, #1\n\t"
        "	cmp r3, r0\n\t"
        "	blt _08142344\n\t"
        "	adds r0, r2, #4\n\t"
        "	cmp r3, r0\n\t"
        "	bgt _08142344\n\t"
        "_0814233C:\n\t"
        "	movs r0, #1\n\t"
        "	b _08142346\n\t"
        "_08142340:\n\t"
        "	cmp r3, r2\n\t"
        "	beq _0814233C\n\t"
        "_08142344:\n\t"
        "	movs r0, #0\n\t"
        "_08142346:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814234C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x20\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0x18]\n\t"
        "	cmp r7, #0xa\n\t"
        "	beq _08142372\n\t"
        "	cmp r7, #0xa\n\t"
        "	bgt _0814236E\n\t"
        "	cmp r7, #5\n\t"
        "	beq _08142372\n\t"
        "	b _081423D4\n\t"
        "_0814236E:\n\t"
        "	cmp r7, #0xf\n\t"
        "	bne _081423D4\n\t"
        "_08142372:\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r2, r7, #5\n\t"
        "	ldr r1, _081423C8\n\t"
        "	mov ip, r1\n\t"
        "	cmp r4, r2\n\t"
        "	bge _081423B0\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r3, _081423CC\n\t"
        "	ldr r5, [r0, #8]\n\t"
        "	adds r6, r3, #0\n\t"
        "	adds r6, #8\n\t"
        "_0814238C:\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r0, r1, r6\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r0, r5\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081423A6\n\t"
        "	adds r0, r1, r3\n\t"
        "	ldrh r0, [r0, #0x10]\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	orrs r1, r0\n\t"
        "	str r1, [sp, #0x18]\n\t"
        "_081423A6:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, r2\n\t"
        "	blt _0814238C\n\t"
        "_081423B0:\n\t"
        "	mov r2, ip\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0xb8\n\t"
        "	ldr r1, _081423D0\n\t"
        "	ldr r3, [sp, #0x18]\n\t"
        "	ands r3, r1\n\t"
        "	str r3, [sp, #0x18]\n\t"
        "	adds r1, r3, #0\n\t"
        "	bl sub_08151A24\n\t"
        "	b _081425AA\n\t"
        "	.align 2, 0\n\t"
        "_081423C8: .4byte gUnknown_203A854\n\t"
        "_081423CC: .4byte sGridSelections\n\t"
        "_081423D0: .4byte 0x0000DFFF\n\t"
        "_081423D4:\n\t"
        "	mov r0, sp\n\t"
        "	ldr r1, _08142424\n\t"
        "	ldm r1!, {r2, r4, r5}\n\t"
        "	stm r0!, {r2, r4, r5}\n\t"
        "	ldm r1!, {r3, r4, r5}\n\t"
        "	stm r0!, {r3, r4, r5}\n\t"
        "	subs r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #1\n\t"
        "	mov sb, r1\n\t"
        "	cmp r0, #3\n\t"
        "	bhi _081423F2\n\t"
        "	movs r2, #3\n\t"
        "	mov sb, r2\n\t"
        "_081423F2:\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #5\n\t"
        "	bl __udivsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #8\n\t"
        "	ldr r3, _08142428\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #5\n\t"
        "	bl __umodsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #2\n\t"
        "	beq _08142458\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _08142430\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08142444\n\t"
        "	ldr r4, _0814242C\n\t"
        "	mov ip, r4\n\t"
        "	b _0814249C\n\t"
        "	.align 2, 0\n\t"
        "_08142424: .4byte sFlashData_PokeIcons\n\t"
        "_08142428: .4byte 0xFFFF0000\n\t"
        "_0814242C: .4byte gUnknown_203A854\n\t"
        "_08142430:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _0814246C\n\t"
        "	cmp r0, #4\n\t"
        "	beq _08142480\n\t"
        "	ldr r5, _08142440\n\t"
        "	mov ip, r5\n\t"
        "	b _0814249C\n\t"
        "	.align 2, 0\n\t"
        "_08142440: .4byte gUnknown_203A854\n\t"
        "_08142444:\n\t"
        "	ldr r3, _08142450\n\t"
        "	ldr r2, _08142454\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x43\n\t"
        "	b _08142488\n\t"
        "	.align 2, 0\n\t"
        "_08142450: .4byte gSprites\n\t"
        "_08142454: .4byte gUnknown_203A854\n\t"
        "_08142458:\n\t"
        "	ldr r3, _08142464\n\t"
        "	ldr r2, _08142468\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x44\n\t"
        "	b _08142488\n\t"
        "	.align 2, 0\n\t"
        "_08142464: .4byte gSprites\n\t"
        "_08142468: .4byte gUnknown_203A854\n\t"
        "_0814246C:\n\t"
        "	ldr r3, _08142478\n\t"
        "	ldr r2, _0814247C\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x45\n\t"
        "	b _08142488\n\t"
        "	.align 2, 0\n\t"
        "_08142478: .4byte gSprites\n\t"
        "_0814247C: .4byte gUnknown_203A854\n\t"
        "_08142480:\n\t"
        "	ldr r3, _081424EC\n\t"
        "	ldr r2, _081424F0\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x46\n\t"
        "_08142488:\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	lsls r0, r0, #4\n\t"
        "	mov r8, r0\n\t"
        "	mov ip, r2\n\t"
        "_0814249C:\n\t"
        "	mov r0, sb\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081424F8\n\t"
        "	mov r1, ip\n\t"
        "	ldr r4, [r1]\n\t"
        "	ldr r1, _081424F4\n\t"
        "	lsls r2, r7, #2\n\t"
        "	adds r0, r2, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, #8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r4, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	str r2, [sp, #0x1c]\n\t"
        "	cmp r1, #0\n\t"
        "	bne _081425AA\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #5\n\t"
        "	bl __udivsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	subs r1, r0, #1\n\t"
        "	lsls r1, r1, #3\n\t"
        "	mov r3, sp\n\t"
        "	adds r2, r3, r1\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	add r1, r8\n\t"
        "	strh r1, [r2, #2]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0xb8\n\t"
        "	lsls r0, r0, #3\n\t"
        "	subs r0, #8\n\t"
        "	adds r2, r3, r0\n\t"
        "	adds r0, r1, #0\n\t"
        "	movs r1, #0xd\n\t"
        "	bl sub_08151668\n\t"
        "	b _0814258C\n\t"
        "	.align 2, 0\n\t"
        "_081424EC: .4byte gSprites\n\t"
        "_081424F0: .4byte gUnknown_203A854\n\t"
        "_081424F4: .4byte sGridSelections\n\t"
        "_081424F8:\n\t"
        "	movs r4, #0\n\t"
        "	lsls r5, r7, #2\n\t"
        "	str r5, [sp, #0x1c]\n\t"
        "	ldr r0, _081425BC\n\t"
        "	mov sl, r0\n\t"
        "_08142502:\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, r7, r0\n\t"
        "	adds r0, #5\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	mov r1, ip\n\t"
        "	ldr r5, [r1]\n\t"
        "	lsls r0, r3, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsls r6, r0, #2\n\t"
        "	mov r0, sl\n\t"
        "	adds r0, #8\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldr r1, [r5, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08142578\n\t"
        "	adds r0, r3, #0\n\t"
        "	movs r1, #5\n\t"
        "	bl __udivsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	subs r1, r0, #1\n\t"
        "	lsls r1, r1, #3\n\t"
        "	mov r3, sp\n\t"
        "	adds r2, r3, r1\n\t"
        "	ldrh r1, [r2, #2]\n\t"
        "	add r1, r8\n\t"
        "	strh r1, [r2, #2]\n\t"
        "	adds r3, r5, #0\n\t"
        "	adds r3, #0xb8\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r0, r0, #3\n\t"
        "	subs r0, #8\n\t"
        "	mov r5, sp\n\t"
        "	adds r2, r5, r0\n\t"
        "	adds r0, r3, #0\n\t"
        "	bl sub_08151668\n\t"
        "	mov r0, sb\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0814256A\n\t"
        "	mov r1, sl\n\t"
        "	adds r0, r6, r1\n\t"
        "	ldrh r0, [r0, #0x10]\n\t"
        "	str r0, [sp, #0x18]\n\t"
        "_0814256A:\n\t"
        "	mov r0, sb\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	ldr r2, _081425C0\n\t"
        "	mov ip, r2\n\t"
        "_08142578:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #2\n\t"
        "	bls _08142502\n\t"
        "	mov r3, sb\n\t"
        "	cmp r3, #2\n\t"
        "	beq _0814258C\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp, #0x18]\n\t"
        "_0814258C:\n\t"
        "	ldr r0, _081425C0\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0xb8\n\t"
        "	ldr r2, _081425BC\n\t"
        "	ldr r5, [sp, #0x1c]\n\t"
        "	adds r1, r5, r7\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrh r1, [r1, #0x10]\n\t"
        "	ldr r2, [sp, #0x18]\n\t"
        "	orrs r2, r1\n\t"
        "	str r2, [sp, #0x18]\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl sub_08151A24\n\t"
        "_081425AA:\n\t"
        "	add sp, #0x20\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081425BC: .4byte sGridSelections\n\t"
        "_081425C0: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081425C4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x2c\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r4, _08142610\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1, #0x2a]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_08142F3C\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r2, _08142614\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldr r2, _08142618\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r1, [r1]\n\t"
        "	movs r2, #0x10\n\t"
        "	str r2, [sp]\n\t"
        "	movs r2, #0xd\n\t"
        "	str r2, [sp, #4]\n\t"
        "	movs r2, #0xe\n\t"
        "	movs r3, #7\n\t"
        "	bl sub_08152034\n\t"
        "	cmp r5, #0xf\n\t"
        "	bhi _081426C4\n\t"
        "	lsls r0, r5, #2\n\t"
        "	ldr r1, _0814261C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_08142610: .4byte gUnknown_203A854\n\t"
        "_08142614: .4byte 0x0000117C\n\t"
        "_08142618: .4byte 0x0000397C\n\t"
        "_0814261C: .4byte _08142620\n\t"
        "_08142620:\n\t"
        "	.4byte _08142800\n\t"
        "	.4byte _08142660\n\t"
        "	.4byte _08142660\n\t"
        "	.4byte _08142660\n\t"
        "	.4byte _08142660\n\t"
        "	.4byte _08142694\n\t"
        "	.4byte _081426C4\n\t"
        "	.4byte _081426C4\n\t"
        "	.4byte _081426C4\n\t"
        "	.4byte _081426C4\n\t"
        "	.4byte _08142694\n\t"
        "	.4byte _081426C4\n\t"
        "	.4byte _081426C4\n\t"
        "	.4byte _081426C4\n\t"
        "	.4byte _081426C4\n\t"
        "	.4byte _08142694\n\t"
        "_08142660:\n\t"
        "	movs r0, #4\n\t"
        "	str r0, [sp, #0x18]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #3\n\t"
        "	bhi _081426CC\n\t"
        "	add r4, sp, #0x10\n\t"
        "	adds r3, r1, #0\n\t"
        "_08142676:\n\t"
        "	ldrb r2, [r3]\n\t"
        "	adds r2, r2, r4\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r5, r0\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r3]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	cmp r0, r1\n\t"
        "	blo _08142676\n\t"
        "	b _081426CC\n\t"
        "_08142694:\n\t"
        "	movs r2, #5\n\t"
        "	str r2, [sp, #0x18]\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _081426CC\n\t"
        "	add r3, sp, #0x10\n\t"
        "	adds r2, r1, #0\n\t"
        "_081426AA:\n\t"
        "	ldrb r1, [r2]\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r2]\n\t"
        "	adds r0, r5, r0\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	cmp r0, r1\n\t"
        "	blo _081426AA\n\t"
        "	b _081426CC\n\t"
        "_081426C4:\n\t"
        "	movs r2, #1\n\t"
        "	str r2, [sp, #0x18]\n\t"
        "	add r0, sp, #0x10\n\t"
        "	strb r5, [r0]\n\t"
        "_081426CC:\n\t"
        "	add r1, sp, #8\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	cmp r0, r1\n\t"
        "	blo _081426DE\n\t"
        "	b _08142800\n\t"
        "_081426DE:\n\t"
        "	mov r2, sp\n\t"
        "	adds r2, #0xe\n\t"
        "	str r2, [sp, #0x1c]\n\t"
        "	add r0, sp, #0x10\n\t"
        "	mov sl, r0\n\t"
        "	add r1, sp, #8\n\t"
        "	mov sb, r1\n\t"
        "	subs r2, #4\n\t"
        "	str r2, [sp, #0x20]\n\t"
        "_081426F0:\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	add r0, sl\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r2, _08142810\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #6]\n\t"
        "	ldr r1, [sp, #0x1c]\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	add r0, sl\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08142810\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #3]\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	strh r0, [r2]\n\t"
        "	mov r7, sp\n\t"
        "	adds r7, #9\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r7]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	cmp r0, #2\n\t"
        "	bhi _081427EE\n\t"
        "	add r6, sp, #0xc\n\t"
        "	mov r8, r2\n\t"
        "	ldr r0, [sp, #0x1c]\n\t"
        "	mov ip, r0\n\t"
        "	ldr r1, _08142814\n\t"
        "	str r1, [sp, #0x28]\n\t"
        "_0814273A:\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	add r0, sl\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _08142810\n\t"
        "	adds r1, r1, r0\n\t"
        "	str r7, [sp, #0x24]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #5\n\t"
        "	strh r0, [r6]\n\t"
        "	ldr r1, [sp, #0x28]\n\t"
        "	ldr r4, [r1]\n\t"
        "	mov r2, r8\n\t"
        "	ldrh r0, [r2]\n\t"
        "	ldrh r2, [r6]\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #1\n\t"
        "	ldr r0, _08142818\n\t"
        "	adds r5, r4, r0\n\t"
        "	adds r2, r5, r2\n\t"
        "	mov r1, ip\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldrb r1, [r7]\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _0814281C\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldr r3, [r4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	movs r1, #0xd0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r2]\n\t"
        "	mov r2, r8\n\t"
        "	ldrh r0, [r2]\n\t"
        "	ldrh r2, [r6]\n\t"
        "	adds r2, r2, r0\n\t"
        "	adds r2, #1\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r2, r5, r2\n\t"
        "	mov r1, ip\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldrb r1, [r7]\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r3, [r4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	movs r1, #0xd1\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r2]\n\t"
        "	mov r2, r8\n\t"
        "	ldrh r1, [r2]\n\t"
        "	ldrh r0, [r6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #2\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r5, r5, r0\n\t"
        "	mov r1, ip\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldrb r1, [r7]\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, [r4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r2, #0xd2\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r5]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r7]\n\t"
        "	ldr r1, [sp, #0x24]\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #2\n\t"
        "	bls _0814273A\n\t"
        "_081427EE:\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	cmp r0, r1\n\t"
        "	bhs _08142800\n\t"
        "	b _081426F0\n\t"
        "_08142800:\n\t"
        "	add sp, #0x2c\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142810: .4byte sGridSelections\n\t"
        "_08142814: .4byte gUnknown_203A854\n\t"
        "_08142818: .4byte 0x0000117C\n\t"
        "_0814281C: .4byte 0x0000397C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142820(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08142858\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #0x13\n\t"
        "	bls _08142838\n\t"
        "	movs r4, #0\n\t"
        "_08142838:\n\t"
        "	ldr r3, _0814285C\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r2, r0, #2\n\t"
        "	adds r0, r2, r3\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	cmp r0, #4\n\t"
        "	beq _0814288C\n\t"
        "	cmp r0, #4\n\t"
        "	bgt _08142860\n\t"
        "	cmp r0, #3\n\t"
        "	beq _08142866\n\t"
        "	b _081428D0\n\t"
        "	.align 2, 0\n\t"
        "_08142858: .4byte sSelectionMultipliers\n\t"
        "_0814285C: .4byte sGridSelections\n\t"
        "_08142860:\n\t"
        "	cmp r0, #0xc\n\t"
        "	beq _081428B0\n\t"
        "	b _081428D0\n\t"
        "_08142866:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #5\n\t"
        "	bl __udivsi3\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _08142888\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x16\n\t"
        "	adds r1, r0, r4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #3\n\t"
        "	bhi _081428D0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	b _081428A4\n\t"
        "	.align 2, 0\n\t"
        "_08142888: .4byte gUnknown_203A854\n\t"
        "_0814288C:\n\t"
        "	subs r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _081428AC\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x12\n\t"
        "	adds r1, r0, r4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #2\n\t"
        "	bhi _081428D0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #2\n\t"
        "_081428A4:\n\t"
        "	add r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "	b _081428D2\n\t"
        "	.align 2, 0\n\t"
        "_081428AC: .4byte gUnknown_203A854\n\t"
        "_081428B0:\n\t"
        "	ldr r0, _081428CC\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #8\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldr r1, [r1, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _081428D0\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	b _081428D2\n\t"
        "	.align 2, 0\n\t"
        "_081428CC: .4byte gUnknown_203A854\n\t"
        "_081428D0:\n\t"
        "	movs r0, #0\n\t"
        "_081428D2:\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081428DC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r4, _0814297C\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrh r1, [r0, #0x2c]\n\t"
        "	movs r0, #0x20\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #0x22\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrh r1, [r0, #0x30]\n\t"
        "	movs r0, #0x24\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrh r1, [r0, #0x32]\n\t"
        "	movs r0, #0x26\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r3, [r4]\n\t"
        "	movs r0, #0x2e\n\t"
        "	ldrsh r1, [r3, r0]\n\t"
        "	ldr r0, _08142980\n\t"
        "	movs r4, #0\n\t"
        "	ldrsh r2, [r0, r4]\n\t"
        "	adds r2, #0x50\n\t"
        "	adds r0, r1, #0\n\t"
        "	muls r0, r2, r0\n\t"
        "	movs r4, #0xe8\n\t"
        "	lsls r4, r4, #7\n\t"
        "	subs r4, r4, r0\n\t"
        "	movs r6, #0x2c\n\t"
        "	ldrsh r5, [r3, r6]\n\t"
        "	ldr r0, _08142984\n\t"
        "	movs r6, #0\n\t"
        "	ldrsh r1, [r0, r6]\n\t"
        "	adds r1, #0x74\n\t"
        "	adds r0, r5, #0\n\t"
        "	muls r0, r1, r0\n\t"
        "	subs r4, r4, r0\n\t"
        "	movs r5, #0x32\n\t"
        "	ldrsh r0, [r3, r5]\n\t"
        "	muls r0, r2, r0\n\t"
        "	movs r5, #0xa8\n\t"
        "	lsls r5, r5, #7\n\t"
        "	subs r5, r5, r0\n\t"
        "	movs r6, #0x30\n\t"
        "	ldrsh r0, [r3, r6]\n\t"
        "	muls r0, r1, r0\n\t"
        "	subs r5, r5, r0\n\t"
        "	lsls r1, r4, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x28\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r6, _08142988\n\t"
        "	ands r4, r6\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	movs r0, #0x2a\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	lsls r1, r5, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	movs r0, #0x2c\n\t"
        "	bl SetGpuReg\n\t"
        "	ands r5, r6\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	movs r0, #0x2e\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0814297C: .4byte gUnknown_203A854\n\t"
        "_08142980: .4byte gSpriteCoordOffsetY\n\t"
        "_08142984: .4byte gSpriteCoordOffsetX\n\t"
        "_08142988: .4byte 0x0FFF0000\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814298C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl DisplayYesNoMenuDefaultYes\n\t"
        "	ldr r1, _081429A8\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DoYesNoFuncWithChoice\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081429A8: .4byte sYesNoTable_AcceptMinBet\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081429AC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _081429D8\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081429D0\n\t"
        "	movs r0, #0\n\t"
        "	bl SetVBlankCallback\n\t"
        "	ldr r0, _081429DC\n\t"
        "	bl SetMainCallback2\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_081429D0:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081429D8: .4byte gPaletteFade\n\t"
        "_081429DC: .4byte sub_08140694 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081429E0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ClearStdWindowAndFrame\n\t"
        "	bl HideCoinsWindow\n\t"
        "	bl FreeAllWindowBuffers\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp]\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x10\n\t"
        "	bl BeginNormalPaletteFade\n\t"
        "	ldr r2, _08142A38\n\t"
        "	ldrb r1, [r2, #8]\n\t"
        "	lsls r1, r1, #0x1a\n\t"
        "	lsrs r1, r1, #0x1a\n\t"
        "	ldrb r3, [r2, #4]\n\t"
        "	movs r0, #0x40\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #4]\n\t"
        "	bl UpdatePaletteFade\n\t"
        "	ldr r1, _08142A3C\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08142A40\n\t"
        "	str r1, [r0]\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142A38: .4byte gPaletteFade\n\t"
        "_08142A3C: .4byte gTasks\n\t"
        "_08142A40: .4byte sub_081429AC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142A44(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl ClearStdWindowAndFrame\n\t"
        "	bl HideCoinsWindow\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142A68(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08142AAC\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #8]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r0, #8]\n\t"
        "	ldr r0, _08142AB0\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08142AA6\n\t"
        "	ldr r1, _08142AB4\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "	bl HideCoinsWindow\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ClearStdWindowAndFrame\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "_08142AA6:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142AAC: .4byte gTasks\n\t"
        "_08142AB0: .4byte gMain\n\t"
        "_08142AB4: .4byte gSpecialVar_0x8004\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142AB8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _08142B30\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08142B28\n\t"
        "	ldr r2, _08142B34\n\t"
        "	ldr r0, _08142B38\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0]\n\t"
        "	ldr r0, _08142B3C\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #1\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r4, _08142B40\n\t"
        "	ldr r1, _08142B44\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, _08142B48\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08142B4C\n\t"
        "	str r1, [r0]\n\t"
        "_08142B28:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142B30: .4byte gMain\n\t"
        "_08142B34: .4byte sTableMinBets\n\t"
        "_08142B38: .4byte gSpecialVar_0x8004\n\t"
        "_08142B3C: .4byte gStringVar1\n\t"
        "_08142B40: .4byte gStringVar4\n\t"
        "_08142B44: .4byte Roulette_Text_PlayMinimumWagerIsX\n\t"
        "_08142B48: .4byte gTasks\n\t"
        "_08142B4C: .4byte sub_0814298C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_Roulette_0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r1, _08142BD8\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r6, r0, r1\n\t"
        "	movs r1, #0x22\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	bl PrintCoinsString\n\t"
        "	ldr r2, _08142BDC\n\t"
        "	ldr r7, _08142BE0\n\t"
        "	ldrh r1, [r7]\n\t"
        "	movs r0, #1\n\t"
        "	mov r8, r0\n\t"
        "	ands r0, r1\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r4, [r0]\n\t"
        "	ldr r0, _08142BE4\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #1\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	movs r1, #0x22\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	cmp r0, r4\n\t"
        "	blt _08142C40\n\t"
        "	ldrh r1, [r7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08142BF0\n\t"
        "	mov r0, r8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08142BF0\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	ldr r2, _08142BE8\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r0, _08142BEC\n\t"
        "	str r0, [r6]\n\t"
        "	b _08142C7A\n\t"
        "	.align 2, 0\n\t"
        "_08142BD8: .4byte gTasks\n\t"
        "_08142BDC: .4byte sTableMinBets\n\t"
        "_08142BE0: .4byte gSpecialVar_0x8004\n\t"
        "_08142BE4: .4byte gStringVar1\n\t"
        "_08142BE8: .4byte Roulette_Text_SpecialRateTable\n\t"
        "_08142BEC: .4byte sub_08142AB8 + 1\n\t"
        "_08142BF0:\n\t"
        "	ldr r4, _08142C30\n\t"
        "	ldr r1, _08142C34\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, _08142C38\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08142C3C\n\t"
        "	str r1, [r0]\n\t"
        "	b _08142C7A\n\t"
        "	.align 2, 0\n\t"
        "_08142C30: .4byte gStringVar4\n\t"
        "_08142C34: .4byte Roulette_Text_PlayMinimumWagerIsX\n\t"
        "_08142C38: .4byte gTasks\n\t"
        "_08142C3C: .4byte sub_0814298C + 1\n\t"
        "_08142C40:\n\t"
        "	ldr r5, _08142C88\n\t"
        "	ldr r1, _08142C8C\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawStdWindowFrame\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r5, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r0, _08142C90\n\t"
        "	str r0, [r6]\n\t"
        "	strh r4, [r6, #0x22]\n\t"
        "	strh r4, [r6, #8]\n\t"
        "_08142C7A:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142C88: .4byte gStringVar4\n\t"
        "_08142C8C: .4byte Roulette_Text_NotEnoughCoins\n\t"
        "_08142C90: .4byte sub_08142A68 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayRoulette()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	bl GetCoins\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #1\n\t"
        "	bl ShowCoinsWindow\n\t"
        "	ldr r0, _08142CD0\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateTask\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl GetCoins\n\t"
        "	ldr r2, _08142CD4\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r0, [r1, #0x22]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142CD0: .4byte Task_Roulette_0 + 1\n\t"
        "_08142CD4: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142CD8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08142D10\n\t"
        "	bl FreeAllSpritePalettes\n\t"
        "	ldr r0, _08142D00\n\t"
        "	bl LoadSpritePalettes\n\t"
        "	ldr r0, _08142D04\n\t"
        "	bl LoadCompressedSpriteSheet\n\t"
        "	ldr r0, _08142D08\n\t"
        "	bl LoadCompressedSpriteSheet\n\t"
        "	ldr r0, _08142D0C\n\t"
        "	bl LoadCompressedSpriteSheet\n\t"
        "	b _08142D26\n\t"
        "	.align 2, 0\n\t"
        "_08142D00: .4byte sSpritePalettes\n\t"
        "_08142D04: .4byte sSpriteSheet_Ball\n\t"
        "_08142D08: .4byte sSpriteSheet_ShroomishTaillow\n\t"
        "_08142D0C: .4byte sSpriteSheet_Shadow\n\t"
        "_08142D10:\n\t"
        "	movs r0, #0xe\n\t"
        "	bl FreeSpriteTilesByTag\n\t"
        "	movs r0, #0xd\n\t"
        "	bl FreeSpriteTilesByTag\n\t"
        "	movs r0, #0xc\n\t"
        "	bl FreeSpriteTilesByTag\n\t"
        "	bl FreeAllSpritePalettes\n\t"
        "_08142D26:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142D2C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r6, r2, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "	ldrb r3, [r1]\n\t"
        "	movs r1, #0x74\n\t"
        "	movs r2, #0x50\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r0, _08142D90\n\t"
        "	lsls r1, r5, #4\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r0, [r6]\n\t"
        "	strh r0, [r1, #0x2e]\n\t"
        "	strh r4, [r1, #0x30]\n\t"
        "	adds r3, r1, #0\n\t"
        "	adds r3, #0x3e\n\t"
        "	ldrb r0, [r3]\n\t"
        "	movs r2, #2\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r3]\n\t"
        "	adds r1, #0x2c\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r0, r2\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrh r2, [r6]\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x1e\n\t"
        "	strh r0, [r6]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ldr r1, _08142D94\n\t"
        "	cmp r0, r1\n\t"
        "	bls _08142D88\n\t"
        "	ldr r1, _08142D98\n\t"
        "	adds r0, r2, r1\n\t"
        "	strh r0, [r6]\n\t"
        "_08142D88:\n\t"
        "	adds r0, r5, #0\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08142D90: .4byte gSprites\n\t"
        "_08142D94: .4byte 0x01670000\n\t"
        "_08142D98: .4byte 0xFFFFFEB6\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142D9C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r4, _08142EE8\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r5, _08142EEC\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl LZ77UnCompWram\n\t"
        "	str r5, [sp]\n\t"
        "	mov r6, sp\n\t"
        "	ldrh r1, [r4, #6]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [sp, #4]\n\t"
        "	mov r0, sp\n\t"
        "	bl LoadSpriteSheet\n\t"
        "	ldr r4, _08142EF0\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl LZ77UnCompWram\n\t"
        "	str r5, [sp]\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	strh r0, [r6, #4]\n\t"
        "	ldrh r0, [r4, #6]\n\t"
        "	strh r0, [r6, #6]\n\t"
        "	mov r0, sp\n\t"
        "	bl LoadSpriteSheet\n\t"
        "	movs r6, #0\n\t"
        "	ldr r0, _08142EF4\n\t"
        "	mov r8, r0\n\t"
        "_08142DE4:\n\t"
        "	lsls r0, r6, #1\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r5, #0\n\t"
        "	lsls r7, r6, #2\n\t"
        "_08142DF0:\n\t"
        "	lsls r1, r5, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _08142EF8\n\t"
        "	adds r0, r1, r0\n\t"
        "	adds r1, #0x94\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x5c\n\t"
        "	movs r3, #0x1e\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, _08142EFC\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x1d\n\t"
        "	adds r2, r7, r2\n\t"
        "	adds r1, #0x3c\n\t"
        "	adds r1, r1, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0x47\n\t"
        "	bls _08142E3A\n\t"
        "	movs r4, #0\n\t"
        "_08142E3A:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #3\n\t"
        "	bls _08142DF0\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #2\n\t"
        "	bls _08142DE4\n\t"
        "	movs r6, #0\n\t"
        "	ldr r4, _08142EF4\n\t"
        "_08142E52:\n\t"
        "	lsls r1, r6, #1\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _08142F00\n\t"
        "	adds r0, r1, r0\n\t"
        "	adds r1, #0x94\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	movs r2, #0x46\n\t"
        "	movs r3, #0x1e\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, _08142EFC\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r1, r6\n\t"
        "	adds r1, #0x65\n\t"
        "	strb r0, [r1]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #3\n\t"
        "	bls _08142E52\n\t"
        "	movs r6, #0\n\t"
        "	ldr r4, _08142EF4\n\t"
        "_08142E98:\n\t"
        "	lsls r2, r6, #1\n\t"
        "	adds r2, r2, r6\n\t"
        "	lsls r2, r2, #3\n\t"
        "	ldr r0, _08142F04\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r2, #0x5c\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	movs r1, #0x7e\n\t"
        "	movs r3, #0x1e\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, _08142EFC\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r1, r6\n\t"
        "	adds r1, #0x69\n\t"
        "	strb r0, [r1]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #2\n\t"
        "	bls _08142E98\n\t"
        "	add sp, #8\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142EE8: .4byte sSpriteSheet_Headers\n\t"
        "_08142EEC: .4byte gDecompressionBuffer\n\t"
        "_08142EF0: .4byte sSpriteSheet_GridIcons\n\t"
        "_08142EF4: .4byte gSprites\n\t"
        "_08142EF8: .4byte sSpriteTemplates_GridIcons\n\t"
        "_08142EFC: .4byte gUnknown_203A854\n\t"
        "_08142F00: .4byte sSpriteTemplates_PokeHeaders\n\t"
        "_08142F04: .4byte sSpriteTemplates_ColorHeaders\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void unref_sub_8142E3C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	movs r4, #0\n\t"
        "_08142F0C:\n\t"
        "	ldr r0, _08142F34\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x59\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08142F38\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl DestroySprite\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xb\n\t"
        "	bls _08142F0C\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08142F34: .4byte gUnknown_203A854\n\t"
        "_08142F38: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08142F3C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov ip, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08142F8C\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08143032\n\t"
        "	movs r4, #0\n\t"
        "	ldr r5, _08142F84\n\t"
        "	ldr r3, _08142F88\n\t"
        "	movs r2, #4\n\t"
        "_08142F5E:\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x59\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0x12\n\t"
        "	bls _08142F5E\n\t"
        "	b _08143032\n\t"
        "	.align 2, 0\n\t"
        "_08142F84: .4byte gSprites\n\t"
        "_08142F88: .4byte gUnknown_203A854\n\t"
        "_08142F8C:\n\t"
        "	movs r4, #0\n\t"
        "	ldr r0, _08142FD4\n\t"
        "	mov sb, r0\n\t"
        "	ldr r7, _08142FD8\n\t"
        "	adds r1, r7, #4\n\t"
        "	mov r8, r1\n\t"
        "	ldr r5, _08142FDC\n\t"
        "	movs r6, #5\n\t"
        "	rsbs r6, r6, #0\n\t"
        "_08142F9E:\n\t"
        "	mov r0, sb\n\t"
        "	ldr r2, [r0]\n\t"
        "	lsls r3, r4, #3\n\t"
        "	mov r1, r8\n\t"
        "	adds r0, r3, r1\n\t"
        "	ldr r1, [r2, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08142FE0\n\t"
        "	adds r0, r3, r7\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	cmp r0, ip\n\t"
        "	beq _08142FE0\n\t"
        "	adds r0, r2, r4\n\t"
        "	adds r0, #0x59\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	b _08142FF8\n\t"
        "	.align 2, 0\n\t"
        "_08142FD4: .4byte gUnknown_203A854\n\t"
        "_08142FD8: .4byte sRouletteSlots\n\t"
        "_08142FDC: .4byte gSprites\n\t"
        "_08142FE0:\n\t"
        "	adds r0, r2, r4\n\t"
        "	adds r0, #0x59\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	adds r1, #0x3e\n\t"
        "	ldrb r2, [r1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "_08142FF8:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xb\n\t"
        "	bls _08142F9E\n\t"
        "	cmp r4, #0x12\n\t"
        "	bhi _08143032\n\t"
        "	ldr r6, _08143040\n\t"
        "	ldr r3, _08143044\n\t"
        "	movs r5, #5\n\t"
        "	rsbs r5, r5, #0\n\t"
        "_0814300E:\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x59\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	adds r1, #0x3e\n\t"
        "	ldrb r2, [r1]\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0x12\n\t"
        "	bls _0814300E\n\t"
        "_08143032:\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08143040: .4byte gSprites\n\t"
        "_08143044: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143048(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	movs r5, #0\n\t"
        "	ldr r6, _081430F4\n\t"
        "	ldr r4, _081430F8\n\t"
        "	movs r0, #4\n\t"
        "	mov r8, r0\n\t"
        "_08143058:\n\t"
        "	ldr r0, _081430FC\n\t"
        "	movs r1, #0x74\n\t"
        "	movs r2, #0x14\n\t"
        "	movs r3, #0xa\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r3, r5, #0\n\t"
        "	adds r3, #0x31\n\t"
        "	adds r1, #0x3c\n\t"
        "	adds r1, r1, r3\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	mov r2, r8\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r2, [r6]\n\t"
        "	adds r2, #0x3c\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #1\n\t"
        "	strh r1, [r0, #0x2e]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08143100\n\t"
        "	str r1, [r0]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	movs r7, #0xd\n\t"
        "	rsbs r7, r7, #0\n\t"
        "	adds r2, r7, #0\n\t"
        "	ands r1, r2\n\t"
        "	mov r2, r8\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #5]\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #8\n\t"
        "	bl StartSpriteAnim\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #5\n\t"
        "	bls _08143058\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081430F4: .4byte gUnknown_203A854\n\t"
        "_081430F8: .4byte gSprites\n\t"
        "_081430FC: .4byte sSpriteTemplate_Ball\n\t"
        "_08143100: .4byte sub_081439D8 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143104(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov sb, r1\n\t"
        "	movs r6, #0\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08143150\n\t"
        "	ldr r4, _08143148\n\t"
        "	ldr r3, _0814314C\n\t"
        "	movs r2, #4\n\t"
        "_08143122:\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x6d\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #5\n\t"
        "	bls _08143122\n\t"
        "	b _0814320E\n\t"
        "	.align 2, 0\n\t"
        "_08143148: .4byte gSprites\n\t"
        "_0814314C: .4byte gUnknown_203A854\n\t"
        "_08143150:\n\t"
        "	ldr r0, _08143190\n\t"
        "	mov r8, r0\n\t"
        "	ldr r7, _08143194\n\t"
        "	ldr r0, _08143198\n\t"
        "	mov ip, r0\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	mov sl, r0\n\t"
        "_08143160:\n\t"
        "	mov r0, r8\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0xc\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08143174\n\t"
        "	cmp r6, sb\n\t"
        "	bne _0814319C\n\t"
        "_08143174:\n\t"
        "	adds r0, r1, r6\n\t"
        "	adds r0, #0x6d\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	b _08143204\n\t"
        "	.align 2, 0\n\t"
        "_08143190: .4byte gUnknown_203A854\n\t"
        "_08143194: .4byte gSprites\n\t"
        "_08143198: .4byte sGridSelections\n\t"
        "_0814319C:\n\t"
        "	adds r5, r6, #0\n\t"
        "	adds r5, #0x31\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, #0x3e\n\t"
        "	ldrb r2, [r1]\n\t"
        "	mov r0, sl\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r0, r8\n\t"
        "	ldr r3, [r0]\n\t"
        "	adds r4, r3, #0\n\t"
        "	adds r4, #0x3c\n\t"
        "	adds r4, r4, r5\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r2, r0, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r7\n\t"
        "	adds r3, #0xc\n\t"
        "	adds r3, r3, r6\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	ldrb r0, [r0, #3]\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, #4\n\t"
        "	strh r0, [r2, #0x20]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r2, r0, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r7\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, #3\n\t"
        "	strh r0, [r2, #0x22]\n\t"
        "_08143204:\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #5\n\t"
        "	bls _08143160\n\t"
        "_0814320E:\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814321C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #0\n\t"
        "	bne _0814324C\n\t"
        "	ldr r2, _08143244\n\t"
        "	ldr r0, _08143248\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x6c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	b _0814329C\n\t"
        "	.align 2, 0\n\t"
        "_08143244: .4byte gSprites\n\t"
        "_08143248: .4byte gUnknown_203A854\n\t"
        "_0814324C:\n\t"
        "	ldr r4, _081432A4\n\t"
        "	ldr r3, _081432A8\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x6c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #5\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r3, [r3]\n\t"
        "	adds r3, #0x6c\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldr r0, _081432AC\n\t"
        "	lsls r2, r5, #2\n\t"
        "	adds r2, r2, r5\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldrb r0, [r2, #3]\n\t"
        "	adds r0, #2\n\t"
        "	lsls r0, r0, #3\n\t"
        "	strh r0, [r1, #0x20]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrb r0, [r2, #4]\n\t"
        "	adds r0, #2\n\t"
        "	lsls r0, r0, #3\n\t"
        "	strh r0, [r1, #0x22]\n\t"
        "_0814329C:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081432A4: .4byte gSprites\n\t"
        "_081432A8: .4byte gUnknown_203A854\n\t"
        "_081432AC: .4byte sGridSelections\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081432B0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r4, _08143338\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r5, _0814333C\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl LZ77UnCompWram\n\t"
        "	str r5, [sp, #4]\n\t"
        "	add r0, sp, #4\n\t"
        "	ldrh r2, [r4, #6]\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	ldrh r1, [r4, #4]\n\t"
        "	orrs r1, r2\n\t"
        "	str r1, [r0, #4]\n\t"
        "	bl LoadSpriteSheet\n\t"
        "	movs r1, #0xf\n\t"
        "	mov r0, sp\n\t"
        "	strh r1, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	ldr r7, _08143340\n\t"
        "_081432DC:\n\t"
        "	movs r4, #0\n\t"
        "	adds r6, r0, #1\n\t"
        "	lsls r5, r0, #2\n\t"
        "_081432E2:\n\t"
        "	adds r1, r5, r4\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _08143344\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0x28\n\t"
        "	mov r2, sp\n\t"
        "	bl sub_08142D2C\n\t"
        "	ldr r1, _08143348\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r2, r4, #7\n\t"
        "	adds r2, r5, r2\n\t"
        "	adds r1, #0x3c\n\t"
        "	adds r1, r1, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, #0x2c\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r0, r2\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #3\n\t"
        "	bls _081432E2\n\t"
        "	lsls r0, r6, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #2\n\t"
        "	bls _081432DC\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08143338: .4byte sSpriteSheet_WheelIcons\n\t"
        "_0814333C: .4byte gDecompressionBuffer\n\t"
        "_08143340: .4byte gSprites\n\t"
        "_08143344: .4byte sSpriteTemplates_WheelIcons\n\t"
        "_08143348: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814334C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldr r0, _081433D0\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrh r0, [r6, #0x2e]\n\t"
        "	ldrh r1, [r1, #0x24]\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	asrs r1, r0, #0x10\n\t"
        "	ldr r0, _081433D4\n\t"
        "	cmp r1, r0\n\t"
        "	ble _0814336E\n\t"
        "	ldr r2, _081433D8\n\t"
        "	adds r0, r1, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "_0814336E:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Sin2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Cos2\n\t"
        "	lsls r2, r5, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	movs r3, #0x30\n\t"
        "	ldrsh r1, [r6, r3]\n\t"
        "	muls r1, r2, r1\n\t"
        "	asrs r1, r1, #0xc\n\t"
        "	strh r1, [r6, #0x24]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r4, r0, #0x10\n\t"
        "	rsbs r1, r4, #0\n\t"
        "	movs r3, #0x30\n\t"
        "	ldrsh r0, [r6, r3]\n\t"
        "	muls r0, r1, r0\n\t"
        "	asrs r0, r0, #0xc\n\t"
        "	strh r0, [r6, #0x26]\n\t"
        "	ldrb r0, [r6, #3]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r3, r0, #0x1b\n\t"
        "	cmp r2, #0\n\t"
        "	bge _081433A8\n\t"
        "	adds r2, #0xf\n\t"
        "_081433A8:\n\t"
        "	lsls r0, r2, #0xc\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldr r1, _081433DC\n\t"
        "	lsls r0, r3, #3\n\t"
        "	adds r1, r0, r1\n\t"
        "	adds r0, r4, #0\n\t"
        "	cmp r0, #0\n\t"
        "	bge _081433BA\n\t"
        "	adds r0, #0xf\n\t"
        "_081433BA:\n\t"
        "	asrs r0, r0, #4\n\t"
        "	strh r0, [r1, #6]\n\t"
        "	strh r0, [r1]\n\t"
        "	strh r5, [r1, #2]\n\t"
        "	lsls r0, r5, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r1, #4]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081433D0: .4byte gUnknown_203A854\n\t"
        "_081433D4: .4byte SPECIAL_CheckInteractedWithFriendsFurnitureTop\n\t"
        "_081433D8: .4byte 0xFFFFFE98\n\t"
        "_081433DC: .4byte gOamMatrices\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081433E0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #8\n\t"
        "	movs r5, #0\n\t"
        "	ldr r7, _081435B4\n\t"
        "	mov r6, sp\n\t"
        "_081433EE:\n\t"
        "	ldr r0, _081435B8\n\t"
        "	lsls r4, r5, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl LZ77UnCompWram\n\t"
        "	str r7, [sp]\n\t"
        "	ldrh r2, [r4, #4]\n\t"
        "	ldr r0, _081435BC\n\t"
        "	ldr r1, [r6, #4]\n\t"
        "	ands r1, r0\n\t"
        "	orrs r1, r2\n\t"
        "	str r1, [r6, #4]\n\t"
        "	ldrh r2, [r4, #6]\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	ldr r0, _081435C0\n\t"
        "	ands r0, r1\n\t"
        "	orrs r0, r2\n\t"
        "	str r0, [r6, #4]\n\t"
        "	mov r0, sp\n\t"
        "	bl LoadSpriteSheet\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #4\n\t"
        "	bls _081433EE\n\t"
        "	ldr r0, _081435C4\n\t"
        "	movs r1, #0xd0\n\t"
        "	movs r2, #0x10\n\t"
        "	movs r3, #4\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r3, _081435C8\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r1, #0x50\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r4, _081435CC\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x50\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r5, #0\n\t"
        "	adds r7, r3, #0\n\t"
        "_08143458:\n\t"
        "	lsls r1, r5, #0x13\n\t"
        "	movs r0, #0xc4\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	adds r1, r1, r0\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldr r0, _081435D0\n\t"
        "	movs r2, #0x18\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, [r7]\n\t"
        "	adds r3, r5, #0\n\t"
        "	adds r3, #0x15\n\t"
        "	adds r1, #0x3c\n\t"
        "	adds r1, r1, r3\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r7]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r7]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r6, #0x40\n\t"
        "	orrs r1, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #3\n\t"
        "	bls _08143458\n\t"
        "	ldr r0, _081435D4\n\t"
        "	movs r1, #0x78\n\t"
        "	movs r2, #0x44\n\t"
        "	movs r3, #4\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r2, _081435C8\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r1, #0x55\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r3, _081435CC\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x55\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	orrs r1, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r5, #0\n\t"
        "	adds r4, r2, #0\n\t"
        "	adds r7, r3, #0\n\t"
        "_081434E8:\n\t"
        "	lsls r1, r5, #0x14\n\t"
        "	movs r2, #0xc0\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	adds r1, r1, r2\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldr r0, _081435D8\n\t"
        "	movs r2, #0x24\n\t"
        "	movs r3, #4\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x1a\n\t"
        "	adds r1, #0x3c\n\t"
        "	adds r1, r1, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r3, #4\n\t"
        "	mov r8, r3\n\t"
        "	mov r3, r8\n\t"
        "	orrs r1, r3\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r6, #0x40\n\t"
        "	orrs r1, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #2\n\t"
        "	bls _081434E8\n\t"
        "	ldr r0, _081435DC\n\t"
        "	movs r1, #0x98\n\t"
        "	movs r2, #0x60\n\t"
        "	movs r3, #9\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r3, _081435C8\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r1, #0x6c\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r4, _081435CC\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x6c\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrb r2, [r1, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	mov r2, r8\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x6c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	orrs r1, r6\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x6c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081435B4: .4byte gDecompressionBuffer\n\t"
        "_081435B8: .4byte sSpriteSheets_Interface\n\t"
        "_081435BC: .4byte 0xFFFF0000\n\t"
        "_081435C0: .4byte 0x0000FFFF\n\t"
        "_081435C4: .4byte sSpriteTemplate_Credit\n\t"
        "_081435C8: .4byte gUnknown_203A854\n\t"
        "_081435CC: .4byte gSprites\n\t"
        "_081435D0: .4byte sSpriteTemplate_CreditDigit\n\t"
        "_081435D4: .4byte sSpriteTemplate_Multiplier\n\t"
        "_081435D8: .4byte sSpriteTemplate_BallCounter\n\t"
        "_081435DC: .4byte sSpriteTemplate_Cursor\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081435E0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	movs r0, #0xfa\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r8, r0\n\t"
        "	movs r4, #0\n\t"
        "	movs r6, #0\n\t"
        "	ldr r1, _081436CC\n\t"
        "	mov sb, r1\n\t"
        "	ldr r0, _081436D0\n\t"
        "	mov sl, r0\n\t"
        "_08143600:\n\t"
        "	adds r0, r7, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl __udivsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r1, _081436D0\n\t"
        "	ldr r0, [r1]\n\t"
        "	adds r3, r6, #0\n\t"
        "	adds r3, #0x15\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _081436CC\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	cmp r5, #0\n\t"
        "	bne _0814363A\n\t"
        "	cmp r4, #0\n\t"
        "	bne _0814363A\n\t"
        "	cmp r6, #3\n\t"
        "	bne _08143698\n\t"
        "_0814363A:\n\t"
        "	mov r4, sl\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sb\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r4, #5\n\t"
        "	rsbs r4, r4, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	mov r1, sl\n\t"
        "	ldr r0, [r1]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r4, sb\n\t"
        "	adds r3, r0, r4\n\t"
        "	adds r4, r3, #0\n\t"
        "	adds r4, #0x40\n\t"
        "	ldr r1, _081436D4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [r0]\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r2, [r0]\n\t"
        "	ldrh r4, [r4]\n\t"
        "	adds r2, r2, r4\n\t"
        "	ldr r4, _081436D8\n\t"
        "	adds r0, r4, #0\n\t"
        "	ands r2, r0\n\t"
        "	ldrh r0, [r3, #4]\n\t"
        "	ldr r4, _081436DC\n\t"
        "	adds r1, r4, #0\n\t"
        "	ands r0, r1\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r3, #4]\n\t"
        "	movs r4, #1\n\t"
        "_08143698:\n\t"
        "	adds r0, r7, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl __umodsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r7, r0, #0x10\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #0xa\n\t"
        "	bl __udivsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #3\n\t"
        "	bls _08143600\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081436CC: .4byte gSprites\n\t"
        "_081436D0: .4byte gUnknown_203A854\n\t"
        "_081436D4: .4byte gUnknown_20205B4\n\t"
        "_081436D8: .4byte 0x000003FF\n\t"
        "_081436DC: .4byte 0xFFFFFC00\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081436E0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08143718\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #0x13\n\t"
        "	bls _081436F8\n\t"
        "	movs r4, #0\n\t"
        "_081436F8:\n\t"
        "	ldr r3, _0814371C\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r2, r0, #2\n\t"
        "	adds r0, r2, r3\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	cmp r0, #4\n\t"
        "	beq _0814374C\n\t"
        "	cmp r0, #4\n\t"
        "	bgt _08143720\n\t"
        "	cmp r0, #3\n\t"
        "	beq _08143726\n\t"
        "	b _08143790\n\t"
        "	.align 2, 0\n\t"
        "_08143718: .4byte sMultiplierAnimIds\n\t"
        "_0814371C: .4byte sGridSelections\n\t"
        "_08143720:\n\t"
        "	cmp r0, #0xc\n\t"
        "	beq _08143770\n\t"
        "	b _08143790\n\t"
        "_08143726:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #5\n\t"
        "	bl __udivsi3\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _08143748\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x16\n\t"
        "	adds r1, r0, r4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #3\n\t"
        "	bhi _08143790\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	b _08143764\n\t"
        "	.align 2, 0\n\t"
        "_08143748: .4byte gUnknown_203A854\n\t"
        "_0814374C:\n\t"
        "	subs r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r0, _0814376C\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x12\n\t"
        "	adds r1, r0, r4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #2\n\t"
        "	bhi _08143790\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #2\n\t"
        "_08143764:\n\t"
        "	add r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "	b _08143792\n\t"
        "	.align 2, 0\n\t"
        "_0814376C: .4byte gUnknown_203A854\n\t"
        "_08143770:\n\t"
        "	ldr r0, _0814378C\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #8\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldr r1, [r1, #8]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08143790\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	b _08143792\n\t"
        "	.align 2, 0\n\t"
        "_0814378C: .4byte gUnknown_203A854\n\t"
        "_08143790:\n\t"
        "	movs r0, #0\n\t"
        "_08143792:\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814379C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _081437E8\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, #0x55\n\t"
        "	ldrb r2, [r1]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r2, _081437EC\n\t"
        "	adds r4, r1, r2\n\t"
        "	bl sub_081436E0\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x2b\n\t"
        "	strb r0, [r3]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x40\n\t"
        "	ldr r1, [r4, #8]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	ldr r1, [r1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _081437F0\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r1, r0\n\t"
        "	ldrh r2, [r4, #4]\n\t"
        "	ldr r0, _081437F4\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r4, #4]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081437E8: .4byte gUnknown_203A854\n\t"
        "_081437EC: .4byte gSprites\n\t"
        "_081437F0: .4byte 0x000003FF\n\t"
        "_081437F4: .4byte 0xFFFFFC00\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081437F8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	movs r6, #0\n\t"
        "	ldr r1, _08143824\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldrb r0, [r0, #0x19]\n\t"
        "	adds r5, r1, #0\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08143812\n\t"
        "	movs r6, #2\n\t"
        "_08143812:\n\t"
        "	cmp r2, #6\n\t"
        "	bls _08143818\n\t"
        "	b _08143974\n\t"
        "_08143818:\n\t"
        "	lsls r0, r2, #2\n\t"
        "	ldr r1, _08143828\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_08143824: .4byte gUnknown_203A854\n\t"
        "_08143828: .4byte _0814382C\n\t"
        "_0814382C:\n\t"
        "	.4byte _08143974\n\t"
        "	.4byte _08143930\n\t"
        "	.4byte _08143908\n\t"
        "	.4byte _081438FC\n\t"
        "	.4byte _081438D4\n\t"
        "	.4byte _081438C8\n\t"
        "	.4byte _08143848\n\t"
        "_08143848:\n\t"
        "	movs r4, #0\n\t"
        "	ldr r5, _081438B8\n\t"
        "	ldr r6, _081438BC\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	mov ip, r0\n\t"
        "	adds r7, r5, #0\n\t"
        "	adds r7, #8\n\t"
        "	ldr r2, _081438C0\n\t"
        "	mov r8, r2\n\t"
        "_0814385C:\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x1a\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	adds r1, #0x3e\n\t"
        "	ldrb r2, [r1]\n\t"
        "	mov r0, ip\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r3, r0, r5\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x40\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r1, [r0]\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _081438C4\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r1, r0\n\t"
        "	ldrh r2, [r3, #4]\n\t"
        "	mov r0, r8\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r3, #4]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #2\n\t"
        "	bls _0814385C\n\t"
        "	b _081439C0\n\t"
        "	.align 2, 0\n\t"
        "_081438B8: .4byte gSprites\n\t"
        "_081438BC: .4byte gUnknown_203A854\n\t"
        "_081438C0: .4byte 0xFFFFFC00\n\t"
        "_081438C4: .4byte 0x000003FF\n\t"
        "_081438C8:\n\t"
        "	ldr r2, _081438D0\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x58\n\t"
        "	b _08143936\n\t"
        "	.align 2, 0\n\t"
        "_081438D0: .4byte gSprites\n\t"
        "_081438D4:\n\t"
        "	ldr r2, _081438F8\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x58\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r3, r0, r2\n\t"
        "	adds r4, r3, #0\n\t"
        "	adds r4, #0x40\n\t"
        "	adds r2, #8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [r0]\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #8]\n\t"
        "	b _08143952\n\t"
        "	.align 2, 0\n\t"
        "_081438F8: .4byte gSprites\n\t"
        "_081438FC:\n\t"
        "	ldr r2, _08143904\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x57\n\t"
        "	b _08143936\n\t"
        "	.align 2, 0\n\t"
        "_08143904: .4byte gSprites\n\t"
        "_08143908:\n\t"
        "	ldr r2, _0814392C\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x57\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r3, r0, r2\n\t"
        "	adds r4, r3, #0\n\t"
        "	adds r4, #0x40\n\t"
        "	adds r2, #8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [r0]\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #8]\n\t"
        "	b _08143952\n\t"
        "	.align 2, 0\n\t"
        "_0814392C: .4byte gSprites\n\t"
        "_08143930:\n\t"
        "	ldr r2, _08143968\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x56\n\t"
        "_08143936:\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r3, r0, r2\n\t"
        "	adds r4, r3, #0\n\t"
        "	adds r4, #0x40\n\t"
        "	adds r2, #8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [r0]\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "_08143952:\n\t"
        "	ldrh r4, [r4]\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldr r2, _0814396C\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r1, r0\n\t"
        "	ldrh r2, [r3, #4]\n\t"
        "	ldr r0, _08143970\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r3, #4]\n\t"
        "	b _081439C0\n\t"
        "	.align 2, 0\n\t"
        "_08143968: .4byte gSprites\n\t"
        "_0814396C: .4byte 0x000003FF\n\t"
        "_08143970: .4byte 0xFFFFFC00\n\t"
        "_08143974:\n\t"
        "	movs r4, #0\n\t"
        "	lsls r7, r6, #2\n\t"
        "	ldr r6, _081439CC\n\t"
        "	movs r0, #8\n\t"
        "	adds r0, r0, r6\n\t"
        "	mov ip, r0\n\t"
        "	ldr r2, _081439D0\n\t"
        "	mov r8, r2\n\t"
        "_08143984:\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r0, #0x56\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r3, r0, r6\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x40\n\t"
        "	add r0, ip\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, r7, r0\n\t"
        "	ldrh r1, [r0, #8]\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _081439D4\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r1, r0\n\t"
        "	ldrh r2, [r3, #4]\n\t"
        "	mov r0, r8\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r3, #4]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #2\n\t"
        "	bls _08143984\n\t"
        "_081439C0:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081439CC: .4byte gSprites\n\t"
        "_081439D0: .4byte 0xFFFFFC00\n\t"
        "_081439D4: .4byte 0x000003FF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081439D8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r1, _081439E4\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldrh r1, [r1, #0x26]\n\t"
        "	strh r1, [r0, #0x24]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_081439E4: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081439E8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r4, _08143A54\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r5, _08143A58\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl LZ77UnCompWram\n\t"
        "	str r5, [sp]\n\t"
        "	ldrh r1, [r4, #6]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [sp, #4]\n\t"
        "	mov r0, sp\n\t"
        "	bl LoadSpriteSheet\n\t"
        "	ldr r0, _08143A5C\n\t"
        "	movs r1, #0x74\n\t"
        "	movs r2, #0x50\n\t"
        "	movs r3, #0x51\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _08143A60\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r0, _08143A64\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r0, [r0, #0x24]\n\t"
        "	movs r2, #0\n\t"
        "	strh r0, [r1, #0x2e]\n\t"
        "	strh r2, [r1, #0x30]\n\t"
        "	adds r3, r1, #0\n\t"
        "	adds r3, #0x2c\n\t"
        "	ldrb r0, [r3]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r0, r2\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r3]\n\t"
        "	adds r1, #0x3e\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r2, #2\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08143A54: .4byte sSpriteSheet_WheelCenter\n\t"
        "_08143A58: .4byte gDecompressionBuffer\n\t"
        "_08143A5C: .4byte sSpriteTemplate_WheelCenter\n\t"
        "_08143A60: .4byte gSprites\n\t"
        "_08143A64: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143A68(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldrb r0, [r0, #3]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r0, r0, #0x1b\n\t"
        "	ldr r1, _08143A8C\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08143A90\n\t"
        "	ldr r2, [r1]\n\t"
        "	ldrh r1, [r2, #0x2c]\n\t"
        "	strh r1, [r0, #6]\n\t"
        "	ldrh r1, [r2, #0x2c]\n\t"
        "	strh r1, [r0]\n\t"
        "	ldrh r1, [r2, #0x2e]\n\t"
        "	strh r1, [r0, #2]\n\t"
        "	ldrh r1, [r2, #0x30]\n\t"
        "	strh r1, [r0, #4]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_08143A8C: .4byte gOamMatrices\n\t"
        "_08143A90: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143A94(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	movs r4, #0\n\t"
        "	ldr r5, _08143B00\n\t"
        "	ldr r6, _08143B04\n\t"
        "_08143A9C:\n\t"
        "	movs r3, #0x39\n\t"
        "	subs r3, r3, r4\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	ldr r0, _08143B08\n\t"
        "	movs r1, #0x74\n\t"
        "	movs r2, #0x50\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0x3c\n\t"
        "	adds r1, r1, r4\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r1, r0, r4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0x40\n\t"
        "	beq _08143AF0\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #2\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "_08143AF0:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #5\n\t"
        "	bls _08143A9C\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08143B00: .4byte gUnknown_203A854\n\t"
        "_08143B04: .4byte gSprites\n\t"
        "_08143B08: .4byte sSpriteTemplate_Ball\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143B0C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	ldr r0, _08143B88\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x3c\n\t"
        "	ldrb r5, [r0]\n\t"
        "	movs r6, #0\n\t"
        "	ldr r7, _08143B8C\n\t"
        "	movs r0, #0x1c\n\t"
        "	adds r0, r0, r7\n\t"
        "	mov sl, r0\n\t"
        "	movs r1, #0x2e\n\t"
        "	adds r1, r1, r7\n\t"
        "	mov sb, r1\n\t"
        "	mov r8, r6\n\t"
        "_08143B30:\n\t"
        "	lsls r4, r5, #4\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #2\n\t"
        "	adds r0, r4, r7\n\t"
        "	adds r3, r0, #0\n\t"
        "	adds r3, #0x3e\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r3]\n\t"
        "	mov r1, sl\n\t"
        "	adds r2, r4, r1\n\t"
        "	ldr r1, _08143B90\n\t"
        "	str r1, [r2]\n\t"
        "	movs r1, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r5, #1\n\t"
        "	adds r3, r6, #1\n\t"
        "_08143B58:\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	add r0, sb\n\t"
        "	mov r5, r8\n\t"
        "	strh r5, [r0]\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #7\n\t"
        "	bls _08143B58\n\t"
        "	lsls r0, r2, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r0, r3, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #5\n\t"
        "	bls _08143B30\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08143B88: .4byte gUnknown_203A854\n\t"
        "_08143B8C: .4byte gSprites\n\t"
        "_08143B90: .4byte SpriteCallbackDummy + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143B94(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r3, r0, #0\n\t"
        "	ldr r0, _08143BC4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrh r4, [r0, #0x24]\n\t"
        "	movs r2, #0x24\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	ldrh r2, [r3, #0x34]\n\t"
        "	movs r5, #0x34\n\t"
        "	ldrsh r0, [r3, r5]\n\t"
        "	cmp r1, r0\n\t"
        "	ble _08143BD0\n\t"
        "	movs r1, #0xb4\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r2, r1\n\t"
        "	subs r2, r0, r4\n\t"
        "	strh r2, [r3, #0x3a]\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	ldr r0, _08143BC8\n\t"
        "	cmp r1, r0\n\t"
        "	ble _08143BD4\n\t"
        "	ldr r5, _08143BCC\n\t"
        "	adds r0, r2, r5\n\t"
        "	b _08143BD2\n\t"
        "	.align 2, 0\n\t"
        "_08143BC4: .4byte gUnknown_203A854\n\t"
        "_08143BC8: .4byte 0x01670000\n\t"
        "_08143BCC: .4byte 0xFFFFFE98\n\t"
        "_08143BD0:\n\t"
        "	subs r0, r2, r4\n\t"
        "_08143BD2:\n\t"
        "	strh r0, [r3, #0x3a]\n\t"
        "_08143BD4:\n\t"
        "	movs r1, #0x3a\n\t"
        "	ldrsh r0, [r3, r1]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143BE0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	bl sub_08143B94\n\t"
        "	ldr r5, _08143C0C\n\t"
        "	ldr r4, [r5]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	bl __floatsisf\n\t"
        "	ldr r1, _08143C10\n\t"
        "	bl __divsf3\n\t"
        "	bl __fixunssfsi\n\t"
        "	adds r4, #0x7e\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x7e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08143C0C: .4byte gUnknown_203A854\n\t"
        "_08143C10: .4byte 0x41F00000\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143C14(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl sub_08143B94\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r1, #0x1e\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r1, r0, #0x10\n\t"
        "	cmp r1, #0xe\n\t"
        "	bne _08143C34\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x32]\n\t"
        "	b _08143C4A\n\t"
        "_08143C34:\n\t"
        "	cmp r1, #0xd\n\t"
        "	bgt _08143C3C\n\t"
        "	movs r0, #0xe\n\t"
        "	b _08143C3E\n\t"
        "_08143C3C:\n\t"
        "	movs r0, #0x2b\n\t"
        "_08143C3E:\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	strh r0, [r4, #0x32]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "_08143C4A:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143C50(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r7, r0, #0\n\t"
        "	ldr r5, _08143C98\n\t"
        "	ldr r6, [r5]\n\t"
        "	adds r4, r6, #0\n\t"
        "	adds r4, #0x8c\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x90\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl __addsf3\n\t"
        "	adds r1, r0, #0\n\t"
        "	str r1, [r4]\n\t"
        "	subs r4, #4\n\t"
        "	ldr r0, [r4]\n\t"
        "	bl __addsf3\n\t"
        "	adds r6, r0, #0\n\t"
        "	str r6, [r4]\n\t"
        "	ldr r0, _08143C9C\n\t"
        "	mov r8, r0\n\t"
        "	adds r0, r6, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl __gesf2\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08143CA0\n\t"
        "	adds r0, r6, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl __subsf3\n\t"
        "	b _08143CB4\n\t"
        "	.align 2, 0\n\t"
        "_08143C98: .4byte gUnknown_203A854\n\t"
        "_08143C9C: .4byte 0x43B40000\n\t"
        "_08143CA0:\n\t"
        "	ldr r1, _08143D4C\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl __ltsf2\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08143CB6\n\t"
        "	adds r0, r6, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl __addsf3\n\t"
        "_08143CB4:\n\t"
        "	str r0, [r4]\n\t"
        "_08143CB6:\n\t"
        "	ldr r5, [r5]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x88\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl __fixsfsi\n\t"
        "	strh r0, [r7, #0x34]\n\t"
        "	adds r4, r5, #0\n\t"
        "	adds r4, #0x98\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r1, #0x9c\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl __addsf3\n\t"
        "	adds r1, r0, #0\n\t"
        "	str r1, [r4]\n\t"
        "	subs r4, #4\n\t"
        "	ldr r0, [r4]\n\t"
        "	bl __addsf3\n\t"
        "	str r0, [r4]\n\t"
        "	bl __fixsfsi\n\t"
        "	strh r0, [r7, #0x36]\n\t"
        "	ldrh r0, [r7, #0x34]\n\t"
        "	bl Sin2\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldrh r0, [r7, #0x34]\n\t"
        "	bl Cos2\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0x10\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	muls r1, r4, r1\n\t"
        "	asrs r1, r1, #0xc\n\t"
        "	strh r1, [r7, #0x24]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	muls r0, r1, r0\n\t"
        "	asrs r0, r0, #0xc\n\t"
        "	strh r0, [r7, #0x26]\n\t"
        "	bl IsSEPlaying\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08143D40\n\t"
        "	ldr r0, _08143D50\n\t"
        "	ldr r4, _08143D54\n\t"
        "	ldrh r2, [r7, #0x24]\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	asrs r2, r2, #0x18\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl m4aMPlayPanpotControl\n\t"
        "	ldr r0, _08143D58\n\t"
        "	ldrh r2, [r7, #0x24]\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	asrs r2, r2, #0x18\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl m4aMPlayPanpotControl\n\t"
        "_08143D40:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08143D4C: .4byte 0x00000000\n\t"
        "_08143D50: .4byte gMPlayInfo_SE1\n\t"
        "_08143D54: .4byte 0x0000FFFF\n\t"
        "_08143D58: .4byte gMPlayInfo_SE2\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143D5C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r0, _08143DB8\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrh r0, [r5, #0x3a]\n\t"
        "	ldrh r1, [r1, #0x24]\n\t"
        "	adds r2, r0, r1\n\t"
        "	strh r2, [r5, #0x34]\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	ldr r0, _08143DBC\n\t"
        "	cmp r1, r0\n\t"
        "	ble _08143D7A\n\t"
        "	ldr r1, _08143DC0\n\t"
        "	adds r0, r2, r1\n\t"
        "	strh r0, [r5, #0x34]\n\t"
        "_08143D7A:\n\t"
        "	ldrh r0, [r5, #0x34]\n\t"
        "	bl Sin2\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldrh r0, [r5, #0x34]\n\t"
        "	bl Cos2\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0x10\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	muls r1, r4, r1\n\t"
        "	asrs r1, r1, #0xc\n\t"
        "	strh r1, [r5, #0x24]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _08143DC4\n\t"
        "	asrs r0, r0, #0xc\n\t"
        "	ldrh r1, [r1]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r5, #0x26]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08143DB8: .4byte gUnknown_203A854\n\t"
        "_08143DBC: .4byte 0x01670000\n\t"
        "_08143DC0: .4byte 0xFFFFFE98\n\t"
        "_08143DC4: .4byte gSpriteCoordOffsetY\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143DC8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	ldrh r0, [r5, #0x32]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	ldrh r0, [r5, #0x36]\n\t"
        "	adds r0, #0x84\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xd4\n\t"
        "	bls _08143DEE\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	b _08143DFA\n\t"
        "_08143DEE:\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "_08143DFA:\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r1, #0x32\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0x1d\n\t"
        "	ble _08143EC4\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08143E38\n\t"
        "	ldr r7, _08143E30\n\t"
        "	ldr r6, [r7]\n\t"
        "	adds r4, r6, #0\n\t"
        "	adds r4, #0x94\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r0, #0xa0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _08143E34\n\t"
        "	bl __subsf3\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldr r0, [r4]\n\t"
        "	bl __lesf2\n\t"
        "	cmp r0, #0\n\t"
        "	bgt _08143EC4\n\t"
        "	b _08143E58\n\t"
        "	.align 2, 0\n\t"
        "_08143E30: .4byte gUnknown_203A854\n\t"
        "_08143E34: .4byte 0x40000000\n\t"
        "_08143E38:\n\t"
        "	ldr r7, _08143ECC\n\t"
        "	ldr r6, [r7]\n\t"
        "	adds r4, r6, #0\n\t"
        "	adds r4, #0x94\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r0, #0xa0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _08143ED0\n\t"
        "	bl __subsf3\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldr r0, [r4]\n\t"
        "	bl __gesf2\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08143EC4\n\t"
        "_08143E58:\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x7d\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r2, [r7]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, #3\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08143BE0\n\t"
        "	movs r0, #0x1e\n\t"
        "	strh r0, [r5, #0x36]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08143B94\n\t"
        "	movs r1, #0x3a\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	movs r1, #0x1e\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r1, r0, #4\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, #0xf\n\t"
        "	strh r1, [r5, #0x3a]\n\t"
        "	ldr r0, _08143ED4\n\t"
        "	str r0, [r5, #0x1c]\n\t"
        "	movs r0, #0x47\n\t"
        "	bl m4aSongNumStartOrChange\n\t"
        "	ldr r3, [r7]\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x9c\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #0x98\n\t"
        "	ldr r0, _08143ED8\n\t"
        "	str r0, [r1]\n\t"
        "	str r0, [r2]\n\t"
        "	subs r1, #0xc\n\t"
        "	ldr r0, _08143EDC\n\t"
        "	str r0, [r1]\n\t"
        "_08143EC4:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08143ECC: .4byte gUnknown_203A854\n\t"
        "_08143ED0: .4byte 0x40000000\n\t"
        "_08143ED4: .4byte sub_08143D5C + 1\n\t"
        "_08143ED8: .4byte 0x00000000\n\t"
        "_08143EDC: .4byte 0xBF800000\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08143EE0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	adds r7, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	movs r1, #0x34\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08143EFE\n\t"
        "	cmp r0, #0xb4\n\t"
        "	beq _08143F68\n\t"
        "	b _0814404C\n\t"
        "_08143EFE:\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08143F08\n\t"
        "	b _0814404C\n\t"
        "_08143F08:\n\t"
        "	movs r1, #0x3c\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	bl __floatsisf\n\t"
        "	mov sb, r0\n\t"
        "	ldr r0, _08143F60\n\t"
        "	mov sl, r0\n\t"
        "	ldr r1, _08143F64\n\t"
        "	mov r8, r1\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldrb r4, [r0, #4]\n\t"
        "	lsls r4, r4, #0x1e\n\t"
        "	lsrs r0, r4, #0x19\n\t"
        "	add r0, sl\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	bl __floatsisf\n\t"
        "	adds r1, r0, #0\n\t"
        "	mov r0, sb\n\t"
        "	bl __mulsf3\n\t"
        "	adds r6, r0, #0\n\t"
        "	lsrs r0, r4, #0x19\n\t"
        "	add r0, sl\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	subs r0, #1\n\t"
        "	bl __floatsisf\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl __addsf3\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsrs r4, r4, #0x19\n\t"
        "	add r4, sl\n\t"
        "	ldrh r0, [r4, #0xc]\n\t"
        "	bl __floatsisf\n\t"
        "	adds r1, r0, #0\n\t"
        "	mov r0, sb\n\t"
        "	bl __divsf3\n\t"
        "	b _08143FC8\n\t"
        "	.align 2, 0\n\t"
        "_08143F60: .4byte sRouletteTables\n\t"
        "_08143F64: .4byte gUnknown_203A854\n\t"
        "_08143F68:\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814404C\n\t"
        "	movs r1, #0x3c\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	bl __floatsisf\n\t"
        "	mov sb, r0\n\t"
        "	ldr r0, _0814405C\n\t"
        "	mov sl, r0\n\t"
        "	ldr r1, _08144060\n\t"
        "	mov r8, r1\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldrb r4, [r0, #4]\n\t"
        "	lsls r4, r4, #0x1e\n\t"
        "	lsrs r0, r4, #0x19\n\t"
        "	add r0, sl\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	bl __floatsisf\n\t"
        "	adds r1, r0, #0\n\t"
        "	mov r0, sb\n\t"
        "	bl __mulsf3\n\t"
        "	adds r6, r0, #0\n\t"
        "	lsrs r0, r4, #0x19\n\t"
        "	add r0, sl\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	subs r0, #1\n\t"
        "	bl __floatsisf\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl __addsf3\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsrs r4, r4, #0x19\n\t"
        "	add r4, sl\n\t"
        "	ldrh r0, [r4, #0xc]\n\t"
        "	bl __floatsisf\n\t"
        "	adds r1, r0, #0\n\t"
        "	mov r0, sb\n\t"
        "	bl __divsf3\n\t"
        "	bl __negsf2\n\t"
        "_08143FC8:\n\t"
        "	adds r2, r0, #0\n\t"
        "	mov r0, r8\n\t"
        "	ldr r6, [r0]\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0xa0\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r0, #0x94\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r0, #0x98\n\t"
        "	str r2, [r0]\n\t"
        "	movs r0, #0x9c\n\t"
        "	adds r0, r0, r6\n\t"
        "	mov r8, r0\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl __addsf3\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl __divsf3\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl __mulsf3\n\t"
        "	adds r1, r0, #0\n\t"
        "	ldr r0, _08144064\n\t"
        "	bl __divsf3\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __addsf3\n\t"
        "	bl __negsf2\n\t"
        "	mov r1, r8\n\t"
        "	str r0, [r1]\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x8c\n\t"
        "	ldr r0, _08144068\n\t"
        "	str r0, [r1]\n\t"
        "	adds r2, r7, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r0, #0x2a\n\t"
        "	movs r2, #0\n\t"
        "	strb r2, [r0]\n\t"
        "	adds r3, r7, #0\n\t"
        "	adds r3, #0x3f\n\t"
        "	ldrb r0, [r3]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #0x11\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	ldr r0, _0814406C\n\t"
        "	str r0, [r7, #0x1c]\n\t"
        "	strh r2, [r7, #0x32]\n\t"
        "_0814404C:\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0814405C: .4byte sRouletteTables\n\t"
        "_08144060: .4byte gUnknown_203A854\n\t"
        "_08144064: .4byte 0x40000000\n\t"
        "_08144068: .4byte 0x00000000\n\t"
        "_0814406C: .4byte sub_08143DC8 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144070(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	movs r1, #0x32\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	bl __floatsisf\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _08144110\n\t"
        "	bl __mulsf3\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl __mulsf3\n\t"
        "	bl __fixsfsi\n\t"
        "	adds r1, r0, #0\n\t"
        "	subs r1, #0x2d\n\t"
        "	strh r1, [r5, #0x26]\n\t"
        "	ldrh r0, [r5, #0x32]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x1d\n\t"
        "	ble _0814410A\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0814410A\n\t"
        "	ldr r4, _08144114\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x7d\n\t"
        "	movs r1, #0xff\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r2, [r4]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, #3\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08143BE0\n\t"
        "	movs r0, #0x1e\n\t"
        "	strh r0, [r5, #0x36]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08143B94\n\t"
        "	movs r1, #0x3a\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	movs r1, #0x1e\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r1, r0, #4\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, #0xf\n\t"
        "	strh r1, [r5, #0x3a]\n\t"
        "	ldr r0, _08144118\n\t"
        "	str r0, [r5, #0x1c]\n\t"
        "	movs r0, #0x47\n\t"
        "	bl m4aSongNumStartOrChange\n\t"
        "	ldr r2, [r4]\n\t"
        "	ldrb r0, [r2, #3]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "_0814410A:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144110: .4byte 0x3D4CCCCD\n\t"
        "_08144114: .4byte gUnknown_203A854\n\t"
        "_08144118: .4byte sub_08143D5C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814411C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r3, r0, #0\n\t"
        "	ldrh r0, [r3, #0x32]\n\t"
        "	adds r1, r0, #1\n\t"
        "	strh r1, [r3, #0x32]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x2c\n\t"
        "	bgt _08144164\n\t"
        "	ldrh r4, [r3, #0x26]\n\t"
        "	subs r0, r4, #1\n\t"
        "	strh r0, [r3, #0x26]\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x2d\n\t"
        "	bne _081441EA\n\t"
        "	ldr r2, _0814415C\n\t"
        "	ldr r0, _08144160\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x73\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081441EA\n\t"
        "	strh r4, [r3, #0x26]\n\t"
        "	b _081441EA\n\t"
        "	.align 2, 0\n\t"
        "_0814415C: .4byte gSprites\n\t"
        "_08144160: .4byte gUnknown_203A854\n\t"
        "_08144164:\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r2, #0x3c\n\t"
        "	ldrsh r1, [r3, r2]\n\t"
        "	cmp r0, r1\n\t"
        "	bge _081441B0\n\t"
        "	ldr r2, _081441A0\n\t"
        "	ldr r0, _081441A4\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x73\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r0, r2\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081441EA\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081441A8\n\t"
        "	ldrh r0, [r3, #0x26]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r3, #0x26]\n\t"
        "	b _081441EA\n\t"
        "	.align 2, 0\n\t"
        "_081441A0: .4byte gSprites\n\t"
        "_081441A4: .4byte gUnknown_203A854\n\t"
        "_081441A8:\n\t"
        "	ldrh r0, [r3, #0x26]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r3, #0x26]\n\t"
        "	b _081441EA\n\t"
        "_081441B0:\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #0x2a\n\t"
        "	movs r2, #0\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0x3f\n\t"
        "	adds r0, r0, r3\n\t"
        "	mov ip, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #0x11\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	mov r1, ip\n\t"
        "	strb r0, [r1]\n\t"
        "	strh r2, [r3, #0x32]\n\t"
        "	ldr r0, _081441F0\n\t"
        "	str r0, [r3, #0x1c]\n\t"
        "	movs r0, #0x3d\n\t"
        "	bl m4aSongNumStart\n\t"
        "_081441EA:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081441F0: .4byte sub_08144070 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081441F4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	movs r0, #0x34\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	cmp r1, #0x5a\n\t"
        "	beq _0814420E\n\t"
        "	movs r0, #0x87\n\t"
        "	lsls r0, r0, #1\n\t"
        "	cmp r1, r0\n\t"
        "	beq _08144218\n\t"
        "	b _08144228\n\t"
        "_0814420E:\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08144228\n\t"
        "	b _08144220\n\t"
        "_08144218:\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08144228\n\t"
        "_08144220:\n\t"
        "	ldr r0, _08144230\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x32]\n\t"
        "_08144228:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144230: .4byte sub_0814411C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144234(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	ldr r0, _08144258\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #3]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	lsrs r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0814424E\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08144260\n\t"
        "_0814424E:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_081447A8\n\t"
        "	ldr r0, _0814425C\n\t"
        "	b _08144268\n\t"
        "	.align 2, 0\n\t"
        "_08144258: .4byte gUnknown_203A854\n\t"
        "_0814425C: .4byte sub_08143EE0 + 1\n\t"
        "_08144260:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_08144984\n\t"
        "	ldr r0, _08144270\n\t"
        "_08144268:\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144270: .4byte sub_081441F4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void prev_quest_read_x24_hm_usage(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	ldrh r0, [r5, #0x32]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xf\n\t"
        "	bne _0814429A\n\t"
        "	ldr r0, _08144304\n\t"
        "	ldr r4, [r0]\n\t"
        "	adds r4, #0x98\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08144308\n\t"
        "	bl __mulsf3\n\t"
        "	str r0, [r4]\n\t"
        "_0814429A:\n\t"
        "	movs r1, #0x32\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08144328\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08144310\n\t"
        "	ldr r2, _08144304\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x7d\n\t"
        "	movs r1, #0xff\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r2, [r2]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, #3\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08143BE0\n\t"
        "	movs r0, #0x1e\n\t"
        "	strh r0, [r5, #0x36]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08143B94\n\t"
        "	movs r1, #0x3a\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	movs r1, #0x1e\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r1, r0, #4\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, #0xf\n\t"
        "	strh r1, [r5, #0x3a]\n\t"
        "	ldr r0, _0814430C\n\t"
        "	str r0, [r5, #0x1c]\n\t"
        "	movs r0, #0x47\n\t"
        "	bl m4aSongNumStartOrChange\n\t"
        "	b _08144328\n\t"
        "	.align 2, 0\n\t"
        "_08144304: .4byte gUnknown_203A854\n\t"
        "_08144308: .4byte 0xBF800000\n\t"
        "_0814430C: .4byte sub_08143D5C + 1\n\t"
        "_08144310:\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #0x38\n\t"
        "	bl m4aSongNumStart\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08144AF0\n\t"
        "_08144328:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144330(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r6, #0x32]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08143BE0\n\t"
        "	ldr r1, _081443BC\n\t"
        "	ldr r4, _081443C0\n\t"
        "	ldr r2, [r4]\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x7e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [r2, #8]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081443C8\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r1, #0x7d\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r2, [r4]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, #3\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08143BE0\n\t"
        "	movs r0, #0x1e\n\t"
        "	strh r0, [r6, #0x36]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08143B94\n\t"
        "	movs r1, #0x3a\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	movs r1, #0x1e\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r1, r0, #4\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, #0xf\n\t"
        "	strh r1, [r6, #0x3a]\n\t"
        "	ldr r0, _081443C4\n\t"
        "	str r0, [r6, #0x1c]\n\t"
        "	movs r0, #0x47\n\t"
        "	bl m4aSongNumStartOrChange\n\t"
        "	b _081444C4\n\t"
        "	.align 2, 0\n\t"
        "_081443BC: .4byte sRouletteSlots\n\t"
        "_081443C0: .4byte gUnknown_203A854\n\t"
        "_081443C4: .4byte sub_08143D5C + 1\n\t"
        "_081443C8:\n\t"
        "	movs r0, #0x38\n\t"
        "	bl m4aSongNumStart\n\t"
        "	bl Random\n\t"
        "	movs r1, #1\n\t"
        "	mov r8, r1\n\t"
        "	ands r1, r0\n\t"
        "	mov r8, r1\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0814440C\n\t"
        "	ldr r4, [r4]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x8c\n\t"
        "	ldr r0, _08144404\n\t"
        "	str r0, [r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x7e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r0, #1\n\t"
        "	movs r1, #0xc\n\t"
        "	bl __modsi3\n\t"
        "	lsls r1, r0, #0x18\n\t"
        "	lsrs r2, r1, #0x18\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x7f\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r5, _08144408\n\t"
        "	b _08144444\n\t"
        "	.align 2, 0\n\t"
        "_08144404: .4byte 0x00000000\n\t"
        "_08144408: .4byte sRouletteTables\n\t"
        "_0814440C:\n\t"
        "	ldr r7, [r4]\n\t"
        "	adds r4, r7, #0\n\t"
        "	adds r4, #0x8c\n\t"
        "	ldr r5, _0814446C\n\t"
        "	ldrb r0, [r7, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r1, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl __addsf3\n\t"
        "	str r0, [r4]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r0, #0x7e\n\t"
        "	ldrb r4, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0xb\n\t"
        "	movs r1, #0xc\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r0, #0x7f\n\t"
        "	strb r4, [r0]\n\t"
        "_08144444:\n\t"
        "	ldr r0, _08144470\n\t"
        "	lsls r1, r2, #3\n\t"
        "	adds r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, _08144474\n\t"
        "	ldr r3, [r2]\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r0, [r3, #8]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08144478\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r6, #0x2e]\n\t"
        "	ldrb r0, [r3, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	strh r0, [r6, #0x32]\n\t"
        "	b _081444B4\n\t"
        "	.align 2, 0\n\t"
        "_0814446C: .4byte sRouletteTables\n\t"
        "_08144470: .4byte sRouletteSlots\n\t"
        "_08144474: .4byte gUnknown_203A854\n\t"
        "_08144478:\n\t"
        "	strh r1, [r6, #0x2e]\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08144490\n\t"
        "	lsls r0, r1, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	strh r0, [r6, #0x32]\n\t"
        "	b _081444B4\n\t"
        "_08144490:\n\t"
        "	lsls r0, r1, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	strh r0, [r6, #0x32]\n\t"
        "	mov r0, r8\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081444AC\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #0x8c\n\t"
        "	ldr r0, _081444A8\n\t"
        "	b _081444B2\n\t"
        "	.align 2, 0\n\t"
        "_081444A8: .4byte 0x3F000000\n\t"
        "_081444AC:\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #0x8c\n\t"
        "	ldr r0, _081444D0\n\t"
        "_081444B2:\n\t"
        "	str r0, [r1]\n\t"
        "_081444B4:\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x98\n\t"
        "	ldr r1, _081444D4\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r0, _081444D8\n\t"
        "	str r0, [r6, #0x1c]\n\t"
        "	movs r0, #5\n\t"
        "	strh r0, [r6, #0x30]\n\t"
        "_081444C4:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081444D0: .4byte 0xBFC00000\n\t"
        "_081444D4: .4byte 0x3DAE147B\n\t"
        "_081444D8: .4byte prev_quest_read_x24_hm_usage + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081444DC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	ldr r4, _08144570\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x8c\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _08144574\n\t"
        "	bl __gtsf2\n\t"
        "	cmp r0, #0\n\t"
        "	bgt _081445C6\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08143BE0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08143C14\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08144588\n\t"
        "	ldr r2, [r4]\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r1, #0x90\n\t"
        "	ldr r0, _08144578\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #0x8c\n\t"
        "	adds r0, r0, r2\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _0814457C\n\t"
        "	mov sb, r1\n\t"
        "	ldrb r0, [r2, #4]\n\t"
        "	lsls r7, r0, #0x1e\n\t"
        "	lsrs r0, r7, #0x19\n\t"
        "	add r0, sb\n\t"
        "	movs r4, #3\n\t"
        "	ldrsb r4, [r0, r4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	adds r5, r0, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bge _08144542\n\t"
        "	ldr r1, _08144580\n\t"
        "	bl __addsf3\n\t"
        "	adds r5, r0, #0\n\t"
        "_08144542:\n\t"
        "	lsrs r0, r7, #0x19\n\t"
        "	add r0, sb\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	adds r0, #1\n\t"
        "	bl __floatsisf\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl __divsf3\n\t"
        "	adds r1, r0, #0\n\t"
        "	mov r2, r8\n\t"
        "	ldr r0, [r2]\n\t"
        "	bl __subsf3\n\t"
        "	mov r1, r8\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #4\n\t"
        "	strh r0, [r6, #0x30]\n\t"
        "	ldr r0, _08144584\n\t"
        "	str r0, [r6, #0x1c]\n\t"
        "	b _081445C6\n\t"
        "	.align 2, 0\n\t"
        "_08144570: .4byte gUnknown_203A854\n\t"
        "_08144574: .4byte 0x3F000000\n\t"
        "_08144578: .4byte 0x00000000\n\t"
        "_0814457C: .4byte sRouletteTables\n\t"
        "_08144580: .4byte 0x43800000\n\t"
        "_08144584: .4byte sub_08144330 + 1\n\t"
        "_08144588:\n\t"
        "	ldr r4, [r4]\n\t"
        "	adds r7, r4, #0\n\t"
        "	adds r7, #0x90\n\t"
        "	ldr r0, [r7]\n\t"
        "	ldr r6, _081445D4\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl __nesf2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081445C6\n\t"
        "	adds r5, r4, #0\n\t"
        "	adds r5, #0x8c\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl __ltsf2\n\t"
        "	cmp r0, #0\n\t"
        "	bge _081445C6\n\t"
        "	str r6, [r7]\n\t"
        "	str r6, [r5]\n\t"
        "	adds r4, #0x98\n\t"
        "	ldr r0, [r4]\n\t"
        "	bl __extendsfdf2\n\t"
        "	ldr r2, _081445D8\n\t"
        "	ldr r3, _081445DC\n\t"
        "	bl __divdf3\n\t"
        "	bl __truncdfsf2\n\t"
        "	str r0, [r4]\n\t"
        "_081445C6:\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081445D4: .4byte 0x00000000\n\t"
        "_081445D8: .4byte 0x3FF33333\n\t"
        "_081445DC: .4byte 0x33333333\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081445E0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	ldr r0, _08144690\n\t"
        "	ldr r5, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x94\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _08144694\n\t"
        "	bl __gtsf2\n\t"
        "	cmp r0, #0\n\t"
        "	bgt _08144684\n\t"
        "	movs r0, #0x98\n\t"
        "	adds r0, r0, r5\n\t"
        "	mov r8, r0\n\t"
        "	adds r7, r5, #0\n\t"
        "	adds r7, #0x86\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r4, [r7, r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bge _08144622\n\t"
        "	ldr r1, _08144698\n\t"
        "	bl __addsf3\n\t"
        "	adds r2, r0, #0\n\t"
        "_08144622:\n\t"
        "	ldr r0, _0814469C\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl __divsf3\n\t"
        "	bl __negsf2\n\t"
        "	mov r1, r8\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #0x90\n\t"
        "	adds r0, r0, r5\n\t"
        "	mov r8, r0\n\t"
        "	adds r5, #0x8c\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r4, [r7, r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bge _08144652\n\t"
        "	ldr r1, _08144698\n\t"
        "	bl __addsf3\n\t"
        "	adds r2, r0, #0\n\t"
        "_08144652:\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl __divsf3\n\t"
        "	bl __negsf2\n\t"
        "	mov r1, r8\n\t"
        "	str r0, [r1]\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x2a\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r2, #0x3f\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #0x11\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #3\n\t"
        "	strh r0, [r6, #0x30]\n\t"
        "	ldr r0, _081446A0\n\t"
        "	str r0, [r6, #0x1c]\n\t"
        "_08144684:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144690: .4byte gUnknown_203A854\n\t"
        "_08144694: .4byte 0x42200000\n\t"
        "_08144698: .4byte 0x47800000\n\t"
        "_0814469C: .4byte 0x40800000\n\t"
        "_081446A0: .4byte sub_081444DC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081446A4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	ldr r4, _08144760\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x94\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _08144764\n\t"
        "	bl __gtsf2\n\t"
        "	cmp r0, #0\n\t"
        "	bgt _08144756\n\t"
        "	movs r0, #0x5d\n\t"
        "	bl m4aSongNumStartOrChange\n\t"
        "	ldr r5, [r4]\n\t"
        "	movs r0, #0x98\n\t"
        "	adds r0, r0, r5\n\t"
        "	mov r8, r0\n\t"
        "	adds r7, r5, #0\n\t"
        "	adds r7, #0x84\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r4, [r7, r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bge _081446EC\n\t"
        "	ldr r1, _08144768\n\t"
        "	bl __addsf3\n\t"
        "	adds r2, r0, #0\n\t"
        "_081446EC:\n\t"
        "	ldr r0, _0814476C\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl __divsf3\n\t"
        "	bl __negsf2\n\t"
        "	mov r1, r8\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #0x90\n\t"
        "	adds r0, r0, r5\n\t"
        "	mov r8, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x8c\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _08144770\n\t"
        "	bl __subsf3\n\t"
        "	adds r5, r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r4, [r7, r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl __floatsisf\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r4, #0\n\t"
        "	bge _08144728\n\t"
        "	ldr r1, _08144768\n\t"
        "	bl __addsf3\n\t"
        "	adds r2, r0, #0\n\t"
        "_08144728:\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl __divsf3\n\t"
        "	mov r1, r8\n\t"
        "	str r0, [r1]\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x2a\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r2, #0x3f\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #0x11\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r6, #0x30]\n\t"
        "	ldr r0, _08144774\n\t"
        "	str r0, [r6, #0x1c]\n\t"
        "_08144756:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144760: .4byte gUnknown_203A854\n\t"
        "_08144764: .4byte 0x42700000\n\t"
        "_08144768: .4byte 0x47800000\n\t"
        "_0814476C: .4byte 0x41A00000\n\t"
        "_08144770: .4byte 0x3F800000\n\t"
        "_08144774: .4byte sub_081445E0 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144778(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r4, #0x30]\n\t"
        "	strh r1, [r4, #0x32]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_08143C50\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r0, _081447A4\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081447A4: .4byte sub_081446A4 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081447A8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #8\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _08144968\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #8\n\t"
        "	bl memcpy\n\t"
        "	mov r1, r8\n\t"
        "	ldrh r0, [r1, #0x3c]\n\t"
        "	subs r0, #2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	ldr r5, _0814496C\n\t"
        "	ldr r0, _08144970\n\t"
        "	movs r2, #0xc\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	movs r1, #0x24\n\t"
        "	movs r3, #0x32\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0x73\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r4, _08144974\n\t"
        "	mov r3, r8\n\t"
        "	movs r0, #0x2e\n\t"
        "	ldrsh r2, [r3, r0]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r2\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r1, [r0, r3]\n\t"
        "	mov r0, sp\n\t"
        "	adds r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r2, [r0, r3]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r3, #0x3b\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0x74\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r4, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x24\n\t"
        "	movs r2, #0x8c\n\t"
        "	movs r3, #0x33\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0x75\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r3, _08144978\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x75\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r2, [r0, #1]\n\t"
        "	movs r1, #0xd\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #1]\n\t"
        "	movs r7, #0\n\t"
        "	adds r6, r3, #0\n\t"
        "	ldr r0, _0814497C\n\t"
        "	mov ip, r0\n\t"
        "	mov sl, r5\n\t"
        "_08144848:\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r3, r7, #0\n\t"
        "	adds r3, #0x37\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	adds r1, #0x3e\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x3c\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r4, [r5]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x3c\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x73\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strh r1, [r0, #0x36]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x74\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strh r1, [r0, #0x38]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x75\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strh r1, [r0, #0x3a]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	mov r1, sb\n\t"
        "	strh r1, [r0, #0x32]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r2, r0, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r6\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #0x3c\n\t"
        "	ldrsh r3, [r0, r1]\n\t"
        "	ldrb r1, [r4, #4]\n\t"
        "	lsls r1, r1, #0x1e\n\t"
        "	lsrs r0, r1, #0x19\n\t"
        "	add r0, ip\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	muls r3, r0, r3\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	add r1, ip\n\t"
        "	ldrb r0, [r1, #2]\n\t"
        "	ldr r1, _08144980\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r3, r3, r0\n\t"
        "	strh r3, [r2, #0x34]\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r2, _08144978\n\t"
        "	cmp r7, #2\n\t"
        "	bls _08144848\n\t"
        "	mov r3, sl\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x74\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #2\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r3]\n\t"
        "	mov r1, r8\n\t"
        "	str r1, [r0, #0x38]\n\t"
        "	add sp, #8\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144968: .4byte sShroomishShadowCoords\n\t"
        "_0814496C: .4byte gUnknown_203A854\n\t"
        "_08144970: .4byte sSpriteTemplate_Shroomish\n\t"
        "_08144974: .4byte sSpriteTemplate_ShroomishShadow\n\t"
        "_08144978: .4byte gSprites\n\t"
        "_0814497C: .4byte sRouletteTables\n\t"
        "_08144980: .4byte 0x0000FFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144984(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #8\n\t"
        "	adds r7, r0, #0\n\t"
        "	movs r0, #0\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _08144AD8\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #8\n\t"
        "	bl memcpy\n\t"
        "	ldrh r0, [r7, #0x3c]\n\t"
        "	subs r0, #2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	ldr r0, _08144ADC\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r2, [r7, r1]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	mov r3, sp\n\t"
        "	adds r1, r3, r2\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r1, [r1, r3]\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #2\n\t"
        "	adds r2, r4, r2\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r2, [r2, r3]\n\t"
        "	movs r3, #0x32\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r5, _08144AE0\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0x73\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x73\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r6, _08144AE4\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrh r1, [r7, #0x2e]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	bl StartSpriteAnim\n\t"
        "	ldr r0, _08144AE8\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r2, [r7, r1]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	mov r3, sp\n\t"
        "	adds r1, r3, r2\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r1, [r1, r3]\n\t"
        "	adds r4, r4, r2\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r2, [r4, r3]\n\t"
        "	movs r3, #0x33\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0x74\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x74\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x74\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	mov r0, sb\n\t"
        "	lsls r2, r0, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	ldr r3, _08144AEC\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	lsls r1, r1, #0x1e\n\t"
        "	lsrs r0, r1, #0x19\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	muls r2, r0, r2\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrh r0, [r1, #0x10]\n\t"
        "	adds r0, #0x2d\n\t"
        "	adds r2, r2, r0\n\t"
        "	strh r2, [r7, #0x3c]\n\t"
        "_08144A5E:\n\t"
        "	ldr r0, _08144AE0\n\t"
        "	ldr r4, [r0]\n\t"
        "	mov r1, r8\n\t"
        "	adds r2, r4, r1\n\t"
        "	adds r2, #0x73\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x73\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strh r1, [r0, #0x36]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x74\n\t"
        "	ldrb r1, [r3]\n\t"
        "	strh r1, [r0, #0x38]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r1, [r3]\n\t"
        "	strh r1, [r0, #0x3a]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	mov r3, sb\n\t"
        "	strh r3, [r0, #0x32]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	ldrh r0, [r7, #0x3c]\n\t"
        "	subs r0, #0x2d\n\t"
        "	strh r0, [r1, #0x34]\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	cmp r0, #1\n\t"
        "	bls _08144A5E\n\t"
        "	str r7, [r4, #0x38]\n\t"
        "	add sp, #8\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144AD8: .4byte sTaillowStartCoords\n\t"
        "_08144ADC: .4byte sSpriteTemplate_Taillow\n\t"
        "_08144AE0: .4byte gUnknown_203A854\n\t"
        "_08144AE4: .4byte gSprites\n\t"
        "_08144AE8: .4byte sSpriteTemplate_TaillowShadow\n\t"
        "_08144AEC: .4byte sRouletteTables\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144AF0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x14\n\t"
        "	adds r7, r0, #0\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	movs r1, #5\n\t"
        "	mov r8, r1\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	mov r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xa\n\t"
        "	bl memset\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	str r0, [sp, #0x10]\n\t"
        "	ldr r3, _08144BDC\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x7d\n\t"
        "	movs r5, #1\n\t"
        "	strb r5, [r0]\n\t"
        "	ldr r2, [r3]\n\t"
        "	ldrb r0, [r2, #3]\n\t"
        "	movs r1, #0x20\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	ldr r2, [r3]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, #0x7e\n\t"
        "	movs r1, #0xff\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r6, [r3]\n\t"
        "	adds r4, r6, #0\n\t"
        "	adds r4, #0x88\n\t"
        "	movs r1, #0x34\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	bl __floatsisf\n\t"
        "	str r0, [r4]\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x98\n\t"
        "	ldr r0, _08144BE0\n\t"
        "	str r0, [r1]\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r2, #0x8c\n\t"
        "	ldr r1, _08144BE4\n\t"
        "	ldrb r0, [r6, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r1, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r2]\n\t"
        "	ldrb r0, [r6, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x1e\n\t"
        "	lsls r1, r0, #4\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r0, [r6, #3]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	lsrs r0, r0, #0x1b\n\t"
        "	subs r5, r5, r0\n\t"
        "	lsls r0, r5, #4\n\t"
        "	subs r0, r0, r5\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	mov r5, sb\n\t"
        "	movs r0, #0x34\n\t"
        "	ldrsh r2, [r7, r0]\n\t"
        "_08144B96:\n\t"
        "	cmp r1, r2\n\t"
        "	bge _08144BA2\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x5a\n\t"
        "	cmp r2, r0\n\t"
        "	ble _08144C04\n\t"
        "_08144BA2:\n\t"
        "	cmp r5, #3\n\t"
        "	beq _08144BE8\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x5a\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #3\n\t"
        "	bls _08144B96\n\t"
        "_08144BB8:\n\t"
        "	ldr r0, _08144BDC\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r1, [r0, #3]\n\t"
        "	movs r0, #0x1f\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08144C30\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08144C24\n\t"
        "	movs r0, #0x98\n\t"
        "	lsls r0, r0, #1\n\t"
        "	movs r1, #0x3f\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	bl PlayCry1\n\t"
        "	b _08144C3C\n\t"
        "	.align 2, 0\n\t"
        "_08144BDC: .4byte gUnknown_203A854\n\t"
        "_08144BE0: .4byte 0x00000000\n\t"
        "_08144BE4: .4byte sRouletteTables\n\t"
        "_08144BE8:\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r7, #0x2e]\n\t"
        "	ldr r0, _08144C00\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	movs r0, #0x20\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #3]\n\t"
        "	b _08144BB8\n\t"
        "	.align 2, 0\n\t"
        "_08144C00: .4byte gUnknown_203A854\n\t"
        "_08144C04:\n\t"
        "	lsrs r0, r5, #1\n\t"
        "	strh r0, [r7, #0x2e]\n\t"
        "	ldr r0, _08144C20\n\t"
        "	ldr r3, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r5\n\t"
        "	ldrb r2, [r3, #3]\n\t"
        "	movs r0, #0x20\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3, #3]\n\t"
        "	b _08144BB8\n\t"
        "	.align 2, 0\n\t"
        "_08144C20: .4byte gUnknown_203A854\n\t"
        "_08144C24:\n\t"
        "	movs r0, #0x98\n\t"
        "	lsls r0, r0, #1\n\t"
        "	movs r1, #0x3f\n\t"
        "	bl PlayCry1\n\t"
        "	b _08144C3C\n\t"
        "_08144C30:\n\t"
        "	movs r0, #0x99\n\t"
        "	lsls r0, r0, #1\n\t"
        "	movs r1, #0x3f\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	bl PlayCry1\n\t"
        "_08144C3C:\n\t"
        "	movs r0, #2\n\t"
        "	mov sl, r0\n\t"
        "	ldr r4, _08144C70\n\t"
        "	ldr r5, [r4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r0, #0x7f\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r0, #2\n\t"
        "	movs r1, #0xc\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldrb r1, [r5, #3]\n\t"
        "	movs r0, #0x1f\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08144C74\n\t"
        "	ldrb r1, [r5, #4]\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08144C74\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #6\n\t"
        "	b _08144C78\n\t"
        "	.align 2, 0\n\t"
        "_08144C70: .4byte gUnknown_203A854\n\t"
        "_08144C74:\n\t"
        "	mov r0, r8\n\t"
        "	add r0, sl\n\t"
        "_08144C78:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	mov r5, sl\n\t"
        "	cmp r5, r8\n\t"
        "	bhs _08144CE4\n\t"
        "	ldr r1, _08144D0C\n\t"
        "	mov sl, r1\n\t"
        "_08144C88:\n\t"
        "	ldr r3, [r4]\n\t"
        "	lsls r0, r6, #3\n\t"
        "	ldr r1, _08144D10\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r3, #8]\n\t"
        "	ldr r2, [r0]\n\t"
        "	ands r1, r2\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08144CCE\n\t"
        "	mov r0, sb\n\t"
        "	adds r1, r0, #1\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov sb, r1\n\t"
        "	add r0, sp\n\t"
        "	strb r5, [r0]\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08144CCE\n\t"
        "	ldrb r1, [r3, #0x1a]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x1b\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sl\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _08144CCE\n\t"
        "	str r5, [sp, #0xc]\n\t"
        "_08144CCE:\n\t"
        "	adds r0, r6, #1\n\t"
        "	movs r1, #0xc\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, r8\n\t"
        "	blo _08144C88\n\t"
        "_08144CE4:\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldrb r1, [r0, #3]\n\t"
        "	lsls r1, r1, #0x1b\n\t"
        "	lsrs r1, r1, #0x1b\n\t"
        "	adds r1, #1\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08144D14\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08144D14\n\t"
        "	movs r0, #0xff\n\t"
        "	ldr r1, [sp, #0x10]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0xbf\n\t"
        "	bhi _08144D14\n\t"
        "	mov r0, sp\n\t"
        "	ldrh r0, [r0, #0xc]\n\t"
        "	b _08144D20\n\t"
        "	.align 2, 0\n\t"
        "_08144D0C: .4byte sGridSelections + 12\n\t"
        "_08144D10: .4byte sRouletteSlots + 4\n\t"
        "_08144D14:\n\t"
        "	ldr r0, [sp, #0x10]\n\t"
        "	mov r1, sb\n\t"
        "	bl __modsi3\n\t"
        "	add r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "_08144D20:\n\t"
        "	strh r0, [r7, #0x3c]\n\t"
        "	ldr r1, _08144D38\n\t"
        "	str r1, [r7, #0x1c]\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144D38: .4byte sub_08144234 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144D3C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldrh r0, [r2, #0x30]\n\t"
        "	adds r1, r0, #1\n\t"
        "	strh r1, [r2, #0x30]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r3, #0x34\n\t"
        "	ldrsh r1, [r2, r3]\n\t"
        "	cmp r0, r1\n\t"
        "	blt _08144D8C\n\t"
        "	ldrh r0, [r2, #0x20]\n\t"
        "	subs r0, #2\n\t"
        "	strh r0, [r2, #0x20]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r1, #0x10\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	cmp r0, r1\n\t"
        "	bge _08144D8C\n\t"
        "	ldr r4, _08144D94\n\t"
        "	ldr r3, [r4]\n\t"
        "	ldrb r1, [r3, #3]\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08144D78\n\t"
        "	movs r0, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3, #3]\n\t"
        "_08144D78:\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl DestroySprite\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r0, _08144D98\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1, #0x34]\n\t"
        "_08144D8C:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144D94: .4byte gUnknown_203A854\n\t"
        "_08144D98: .4byte sShroomishShadowAlphas\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144D9C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #0x18\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _08144E18\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0x18\n\t"
        "	bl memcpy\n\t"
        "	ldrh r0, [r4, #0x30]\n\t"
        "	adds r2, r0, #1\n\t"
        "	strh r2, [r4, #0x30]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r3, #0x34\n\t"
        "	ldrsh r1, [r4, r3]\n\t"
        "	cmp r0, r1\n\t"
        "	bge _08144E20\n\t"
        "	movs r0, #1\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _08144DFA\n\t"
        "	ldr r3, _08144E1C\n\t"
        "	movs r0, #0x3c\n\t"
        "	ldrsh r2, [r4, r0]\n\t"
        "	lsls r2, r2, #1\n\t"
        "	movs r1, #0x32\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	lsrs r1, r0, #0x1f\n\t"
        "	adds r0, r0, r1\n\t"
        "	asrs r0, r0, #1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r2, r2, r0\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r3]\n\t"
        "	movs r3, #0x3c\n\t"
        "	ldrsh r2, [r4, r3]\n\t"
        "	adds r1, r2, #1\n\t"
        "	adds r0, r1, #0\n\t"
        "	cmp r1, #0\n\t"
        "	bge _08144DF2\n\t"
        "	adds r0, r2, #4\n\t"
        "_08144DF2:\n\t"
        "	asrs r0, r0, #2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	subs r0, r1, r0\n\t"
        "	strh r0, [r4, #0x3c]\n\t"
        "_08144DFA:\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x3e\n\t"
        "	ldrb r2, [r3]\n\t"
        "	lsls r0, r2, #0x1d\n\t"
        "	lsrs r0, r0, #0x1f\n\t"
        "	movs r1, #1\n\t"
        "	eors r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	b _08144E4A\n\t"
        "	.align 2, 0\n\t"
        "_08144E18: .4byte sShroomishScreenShakeOffsets\n\t"
        "_08144E1C: .4byte gSpriteCoordOffsetY\n\t"
        "_08144E20:\n\t"
        "	ldr r1, _08144E54\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r2, _08144E58\n\t"
        "	ldr r0, _08144E5C\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x73\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroySprite\n\t"
        "_08144E4A:\n\t"
        "	add sp, #0x18\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144E54: .4byte gSpriteCoordOffsetY\n\t"
        "_08144E58: .4byte gSprites\n\t"
        "_08144E5C: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144E60(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrh r0, [r5, #0x30]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #0x30]\n\t"
        "	movs r1, #0x30\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	bl __floatsisf\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _08144F10\n\t"
        "	bl __mulsf3\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl __mulsf3\n\t"
        "	bl __fixsfsi\n\t"
        "	strh r0, [r5, #0x26]\n\t"
        "	ldr r0, _08144F14\n\t"
        "	ldr r3, [r0]\n\t"
        "	ldr r2, _08144F18\n\t"
        "	ldrb r0, [r3, #1]\n\t"
        "	subs r0, #1\n\t"
        "	lsrs r1, r0, #0x1f\n\t"
        "	adds r0, r0, r1\n\t"
        "	asrs r0, r0, #1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r3, #0x34]\n\t"
        "	ldrb r0, [r3, #1]\n\t"
        "	cmp r0, #0x12\n\t"
        "	bhi _08144EA8\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r3, #1]\n\t"
        "_08144EA8:\n\t"
        "	movs r1, #0x30\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0x3c\n\t"
        "	ble _08144F0A\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #0x30]\n\t"
        "	ldr r3, _08144F1C\n\t"
        "	str r3, [r5, #0x1c]\n\t"
        "	ldr r2, _08144F20\n\t"
        "	movs r0, #0x3a\n\t"
        "	ldrsh r1, [r5, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r4, r2, #0\n\t"
        "	adds r4, #0x1c\n\t"
        "	adds r0, r0, r4\n\t"
        "	str r3, [r0]\n\t"
        "	movs r0, #0x3a\n\t"
        "	ldrsh r1, [r5, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, _08144F24\n\t"
        "	strh r1, [r0, #0x30]\n\t"
        "	movs r0, #0x38\n\t"
        "	ldrsh r1, [r5, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #5\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #0x38\n\t"
        "	ldrsh r1, [r5, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r1, _08144F28\n\t"
        "	str r1, [r0]\n\t"
        "	movs r0, #0xd6\n\t"
        "	bl m4aSongNumStart\n\t"
        "_08144F0A:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08144F10: .4byte 0x3D1FBE77\n\t"
        "_08144F14: .4byte gUnknown_203A854\n\t"
        "_08144F18: .4byte sShroomishShadowAlphas\n\t"
        "_08144F1C: .4byte sub_08144D3C + 1\n\t"
        "_08144F20: .4byte gSprites\n\t"
        "_08144F24: .4byte 0x0000FFFE\n\t"
        "_08144F28: .4byte sub_08144D9C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08144F2C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r1, #0x3c\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08144FB0\n\t"
        "	ldr r0, _08144F58\n\t"
        "	ldr r3, [r0]\n\t"
        "	ldr r1, [r3, #0x38]\n\t"
        "	movs r2, #0x2e\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08144F60\n\t"
        "	movs r0, #0x34\n\t"
        "	ldrsh r2, [r1, r0]\n\t"
        "	ldr r1, _08144F5C\n\t"
        "	ldrb r0, [r3, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #8]\n\t"
        "	b _08144F72\n\t"
        "	.align 2, 0\n\t"
        "_08144F58: .4byte gUnknown_203A854\n\t"
        "_08144F5C: .4byte sRouletteTables\n\t"
        "_08144F60:\n\t"
        "	movs r0, #0x34\n\t"
        "	ldrsh r2, [r1, r0]\n\t"
        "	ldr r1, _08144FA4\n\t"
        "	ldrb r0, [r3, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #8]\n\t"
        "	adds r0, #0xb4\n\t"
        "_08144F72:\n\t"
        "	cmp r2, r0\n\t"
        "	bne _08145048\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r4, #0x3c]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x3c]\n\t"
        "	movs r0, #0x2b\n\t"
        "	bl m4aSongNumStart\n\t"
        "	ldr r2, _08144FA8\n\t"
        "	ldr r1, [r2]\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	ldr r1, [r2]\n\t"
        "	ldr r0, _08144FAC\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1, #0x34]\n\t"
        "	b _08145048\n\t"
        "	.align 2, 0\n\t"
        "_08144FA4: .4byte sRouletteTables\n\t"
        "_08144FA8: .4byte gUnknown_203A854\n\t"
        "_08144FAC: .4byte sShroomishShadowAlphas\n\t"
        "_08144FB0:\n\t"
        "	ldr r5, _08144FF0\n\t"
        "	ldr r3, [r5]\n\t"
        "	ldr r2, _08144FF4\n\t"
        "	ldrb r0, [r3, #1]\n\t"
        "	subs r0, #1\n\t"
        "	lsrs r1, r0, #0x1f\n\t"
        "	adds r0, r0, r1\n\t"
        "	asrs r0, r0, #1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r3, #0x34]\n\t"
        "	ldrb r0, [r3, #1]\n\t"
        "	cmp r0, #0x12\n\t"
        "	bhi _08144FD2\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r3, #1]\n\t"
        "_08144FD2:\n\t"
        "	ldr r3, [r5]\n\t"
        "	ldr r1, [r3, #0x38]\n\t"
        "	movs r2, #0x2e\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08144FFC\n\t"
        "	movs r0, #0x34\n\t"
        "	ldrsh r2, [r1, r0]\n\t"
        "	ldr r1, _08144FF8\n\t"
        "	ldrb r0, [r3, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0xa]\n\t"
        "	b _0814500E\n\t"
        "	.align 2, 0\n\t"
        "_08144FF0: .4byte gUnknown_203A854\n\t"
        "_08144FF4: .4byte sShroomishShadowAlphas\n\t"
        "_08144FF8: .4byte sRouletteTables\n\t"
        "_08144FFC:\n\t"
        "	movs r0, #0x34\n\t"
        "	ldrsh r2, [r1, r0]\n\t"
        "	ldr r1, _08145050\n\t"
        "	ldrb r0, [r3, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0xa]\n\t"
        "	adds r0, #0xb4\n\t"
        "_0814500E:\n\t"
        "	cmp r2, r0\n\t"
        "	bne _08145048\n\t"
        "	ldr r2, _08145054\n\t"
        "	movs r0, #0x36\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r1, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _08145058\n\t"
        "	str r1, [r0]\n\t"
        "	movs r0, #0x36\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #5\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _0814505C\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x3c]\n\t"
        "_08145048:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08145050: .4byte sRouletteTables\n\t"
        "_08145054: .4byte gSprites\n\t"
        "_08145058: .4byte sub_08144E60 + 1\n\t"
        "_0814505C: .4byte SpriteCallbackDummy + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08145060(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r3, [r0]\n\t"
        "	lsls r1, r3, #0x1d\n\t"
        "	lsrs r1, r1, #0x1f\n\t"
        "	movs r2, #1\n\t"
        "	eors r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	movs r1, #5\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r3\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0814507C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r2, [r4, #0x22]\n\t"
        "	movs r0, #0x22\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	movs r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r1, r0\n\t"
        "	ble _08145094\n\t"
        "	subs r0, r2, #1\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "	b _081450E8\n\t"
        "_08145094:\n\t"
        "	ldr r0, _081450F0\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	subs r2, #0x12\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #0x5e\n\t"
        "	bl m4aSongNumStop\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroySprite\n\t"
        "	ldr r5, _081450F4\n\t"
        "	ldr r4, _081450F8\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x74\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0, #3]\n\t"
        "	lsls r0, r0, #0x1a\n\t"
        "	lsrs r0, r0, #0x1b\n\t"
        "	bl FreeOamMatrix\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x74\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	bl DestroySprite\n\t"
        "_081450E8:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081450F0: .4byte SpriteCallbackDummy + 1\n\t"
        "_081450F4: .4byte gSprites\n\t"
        "_081450F8: .4byte gUnknown_203A854\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081450FC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r1, [r4, #0x30]\n\t"
        "	movs r2, #0x30\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08145126\n\t"
        "	subs r1, #1\n\t"
        "	strh r1, [r4, #0x30]\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08145192\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08145192\n\t"
        "	b _0814514C\n\t"
        "_08145126:\n\t"
        "	ldrh r1, [r4, #0x34]\n\t"
        "	movs r2, #0x34\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0814515C\n\t"
        "	subs r0, r1, #1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x3f\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08145192\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08145154\n\t"
        "_0814514C:\n\t"
        "	ldrh r0, [r4, #0x26]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	b _08145192\n\t"
        "_08145154:\n\t"
        "	ldrh r0, [r4, #0x26]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	b _08145192\n\t"
        "_0814515C:\n\t"
        "	movs r0, #0x2b\n\t"
        "	bl m4aSongNumStart\n\t"
        "	ldr r0, _08145198\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #0x38]\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	adds r1, #4\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	ldr r0, _0814519C\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "	ldr r2, _081451A0\n\t"
        "	movs r0, #0x3a\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #0x7f\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "_08145192:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08145198: .4byte gUnknown_203A854\n\t"
        "_0814519C: .4byte sub_0814507C + 1\n\t"
        "_081451A0: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081451A4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x14\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _08145220\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #2\n\t"
        "	bl memcpy\n\t"
        "	add r5, sp, #4\n\t"
        "	ldr r1, _08145224\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r2, #0x10\n\t"
        "	bl memcpy\n\t"
        "	ldrh r0, [r4, #0x30]\n\t"
        "	subs r1, r0, #1\n\t"
        "	strh r1, [r4, #0x30]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #7\n\t"
        "	ble _08145238\n\t"
        "	ldr r0, _08145228\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #0x38]\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	add r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldrh r2, [r4, #0x20]\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	bl IsSEPlaying\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081452D4\n\t"
        "	movs r1, #0x20\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r4, #0x74\n\t"
        "	subs r4, r4, r0\n\t"
        "	lsrs r0, r4, #0x1f\n\t"
        "	adds r4, r4, r0\n\t"
        "	asrs r4, r4, #1\n\t"
        "	rsbs r4, r4, #0\n\t"
        "	ldr r0, _0814522C\n\t"
        "	ldr r5, _08145230\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	asrs r4, r4, #0x18\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl m4aMPlayPanpotControl\n\t"
        "	ldr r0, _08145234\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl m4aMPlayPanpotControl\n\t"
        "	b _081452D4\n\t"
        "	.align 2, 0\n\t"
        "_08145220: .4byte sTaillowXMoveOffsets\n\t"
        "_08145224: .4byte sTaillowYMoveOffsets\n\t"
        "_08145228: .4byte gUnknown_203A854\n\t"
        "_0814522C: .4byte gMPlayInfo_SE1\n\t"
        "_08145230: .4byte 0x0000FFFF\n\t"
        "_08145234: .4byte gMPlayInfo_SE2\n\t"
        "_08145238:\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08145288\n\t"
        "	ldr r0, _08145284\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #0x38]\n\t"
        "	movs r2, #0x2e\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	add r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsb r2, [r0, r2]\n\t"
        "	movs r1, #0x30\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r1, #7\n\t"
        "	subs r0, r1, r0\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	muls r0, r2, r0\n\t"
        "	ldrh r2, [r4, #0x20]\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	movs r2, #0x30\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	mov r0, sp\n\t"
        "	adds r0, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	ldrh r1, [r4, #0x22]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "	b _081452D4\n\t"
        "	.align 2, 0\n\t"
        "_08145284: .4byte gUnknown_203A854\n\t"
        "_08145288:\n\t"
        "	movs r0, #0x5e\n\t"
        "	bl m4aSongNumStartOrChange\n\t"
        "	ldr r0, _081452A8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #0x38]\n\t"
        "	movs r2, #0x2e\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081452AC\n\t"
        "	movs r0, #0x98\n\t"
        "	lsls r0, r0, #1\n\t"
        "	movs r1, #0x3f\n\t"
        "	bl PlayCry1\n\t"
        "	b _081452B8\n\t"
        "	.align 2, 0\n\t"
        "_081452A8: .4byte gUnknown_203A854\n\t"
        "_081452AC:\n\t"
        "	movs r0, #0x98\n\t"
        "	lsls r0, r0, #1\n\t"
        "	movs r1, #0x3f\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	bl PlayCry1\n\t"
        "_081452B8:\n\t"
        "	ldr r0, _081452DC\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #0x38]\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	adds r1, #2\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	movs r0, #0x2d\n\t"
        "	strh r0, [r4, #0x30]\n\t"
        "	ldr r0, _081452E0\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "_081452D4:\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081452DC: .4byte gUnknown_203A854\n\t"
        "_081452E0: .4byte sub_081450FC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_081452E4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _08145344\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #2\n\t"
        "	bl memcpy\n\t"
        "	ldrh r0, [r4, #0x30]\n\t"
        "	subs r1, r0, #1\n\t"
        "	strh r1, [r4, #0x30]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08145350\n\t"
        "	ldr r0, _08145348\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r0, [r0, #0x38]\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	add r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldrh r2, [r4, #0x20]\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	ldr r1, _0814534C\n\t"
        "	movs r2, #0x3a\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	lsls r2, r0, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r1\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r3, [r2]\n\t"
        "	lsls r0, r3, #0x1d\n\t"
        "	lsrs r0, r0, #0x1f\n\t"
        "	movs r1, #1\n\t"
        "	eors r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	b _08145354\n\t"
        "	.align 2, 0\n\t"
        "_08145344: .4byte sTaillowXMoveOffsets\n\t"
        "_08145348: .4byte gUnknown_203A854\n\t"
        "_0814534C: .4byte gSprites\n\t"
        "_08145350:\n\t"
        "	ldr r0, _0814535C\n\t"
        "	str r0, [r4, #0x1c]\n\t"
        "_08145354:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0814535C: .4byte sub_08145060 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08145360(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r0, _0814539C\n\t"
        "	ldr r3, [r0]\n\t"
        "	ldr r1, [r3, #0x38]\n\t"
        "	movs r2, #0x2e\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081453A8\n\t"
        "	movs r0, #0x34\n\t"
        "	ldrsh r2, [r1, r0]\n\t"
        "	ldr r1, _081453A0\n\t"
        "	ldrb r0, [r3, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0x12]\n\t"
        "	adds r0, #0x5a\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0814540A\n\t"
        "	ldr r2, _081453A4\n\t"
        "	movs r0, #0x3a\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r3, #0x34\n\t"
        "	b _081453D2\n\t"
        "	.align 2, 0\n\t"
        "_0814539C: .4byte gUnknown_203A854\n\t"
        "_081453A0: .4byte sRouletteTables\n\t"
        "_081453A4: .4byte gSprites\n\t"
        "_081453A8:\n\t"
        "	movs r0, #0x34\n\t"
        "	ldrsh r2, [r1, r0]\n\t"
        "	ldr r1, _08145410\n\t"
        "	ldrb r0, [r3, #4]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0, #0x14]\n\t"
        "	movs r1, #0x87\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0814540A\n\t"
        "	ldr r2, _08145414\n\t"
        "	movs r0, #0x3a\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r3, #0x2e\n\t"
        "_081453D2:\n\t"
        "	strh r3, [r0, #0x30]\n\t"
        "	movs r0, #0x36\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r3, [r0, #0x30]\n\t"
        "	movs r0, #0x3a\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r2, #0x1c\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, _08145418\n\t"
        "	str r1, [r0]\n\t"
        "	movs r0, #0x36\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, _0814541C\n\t"
        "	str r1, [r0]\n\t"
        "	movs r0, #0x2b\n\t"
        "	bl m4aSongNumStart\n\t"
        "_0814540A:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08145410: .4byte sRouletteTables\n\t"
        "_08145414: .4byte gSprites\n\t"
        "_08145418: .4byte sub_081452E4 + 1\n\t"
        "_0814541C: .4byte sub_081451A4 + 1\n\t"
        ".syntax divided\n\t"
    );
}
