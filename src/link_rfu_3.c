#include "global.h"
#include "link_rfu.h"
#include "random.h"
#include "event_data.h"
#include "text.h"
#include "sprite.h"
#include "malloc.h"
#include "string_util.h"

// JP ROM/RAM data (bound in sym_iwram_jp.txt; JP uses a fixed IWRAM address
// instead of US's file-static variable).
extern IWRAM_DATA u8 sSequenceArrayValOffset;

#define LINK_RFU_3_WIRELESS_STATUS_INDICATOR_PALETTE_DATA __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_palette_data")))
#define LINK_RFU_3_WIRELESS_STATUS_INDICATOR_GRAPHICS_DATA __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_graphics_data")))
#define LINK_RFU_3_WIRELESS_STATUS_INDICATOR_SHEET_DATA __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_sheet")))
#define LINK_RFU_3_WIRELESS_STATUS_INDICATOR_PALETTE_DESCRIPTOR_DATA __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_palette")))
#define LINK_RFU_3_WIRELESS_STATUS_INDICATOR_TEMPLATE_DATA __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_template")))

#define TAG_GFX_STATUS_INDICATOR 0xD431
#define TAG_PAL_STATUS_INDICATOR 0xD432

// JP uses a distinct icon encoding from the US PNG-derived assets.
LINK_RFU_3_WIRELESS_STATUS_INDICATOR_PALETTE_DATA static const u16 sWirelessLinkIconPalette[] = INCBIN_U16("graphics/link/jp/wireless_icon.gbapal");
LINK_RFU_3_WIRELESS_STATUS_INDICATOR_GRAPHICS_DATA static const u32 sWirelessLinkIconPic[] = INCBIN_U32("graphics/link/jp/wireless_icon.4bpp.lz");

const u8 sWireless_ASCIItoRSETable[256]
    __attribute__((section(".rodata.link_rfu_3_ascii_to_rse"))) =
{
    0xFF, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x00, 0xAB, 0xB5, 0xB6, 0xB1, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB2, 0xF1, 0x00, 0xAE, 0xAD, 0xBA,
    0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0x00, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
    0x00, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9,
    0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6,
    0x00, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3,
    0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0x2D, 0x2F, 0x30, 0x31, 0x32,
    0x33, 0x34, 0x35, 0x36, 0x50, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
    0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A,
    0x1B, 0xAD, 0xB3, 0xB4, 0x00, 0xAF, 0x7D, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0xA0,
    0xAE, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7E, 0xB0, 0xAC,
    0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B,
    0x2C, 0x2E, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
};

const u8 sWireless_RSEtoASCIITable[256]
    __attribute__((section(".rodata.link_rfu_3_rse_to_ascii"))) =
{
    0x20, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
    0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xE0, 0xE1, 0xE2, 0xE3,
    0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0, 0x7B, 0xF1, 0x7C,
    0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
    0x84, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xA6, 0xDD, 0xA7,
    0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA,
    0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
    0xAF, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x21, 0xDF, 0xA1, 0xB0, 0xA5,
    0xDE, 0x24, 0x2A, 0xA2, 0xA3, 0x22, 0x23, 0x20, 0xA4, 0x20, 0x2F, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55,
    0x56, 0x57, 0x58, 0x59, 0x5A, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B,
    0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x20,
    0x20, 0x2B, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00,
};

enum {
    WIRELESS_STATUS_ANIM_3_BARS,
    WIRELESS_STATUS_ANIM_2_BARS,
    WIRELESS_STATUS_ANIM_1_BAR,
    WIRELESS_STATUS_ANIM_SEARCHING,
    WIRELESS_STATUS_ANIM_ERROR,
};

const struct OamData sWirelessStatusIndicatorOamData
    __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_oam"))) =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

static const union AnimCmd sWirelessStatusIndicator_3Bars[]
    __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_3_bars"))) =
{
    ANIMCMD_FRAME( 4,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_FRAME(12,  5),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_FRAME(12,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sWirelessStatusIndicator_2Bars[]
    __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_2_bars"))) =
{
    ANIMCMD_FRAME( 4,  5),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_FRAME(12, 10),
    ANIMCMD_FRAME( 8,  5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sWirelessStatusIndicator_1Bar[]
    __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_1_bar"))) =
{
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sWirelessStatusIndicator_Searching[]
    __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_searching"))) =
{
    ANIMCMD_FRAME( 4, 10),
    ANIMCMD_FRAME(20, 10),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sWirelessStatusIndicator_Error[]
    __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_error"))) =
{
    ANIMCMD_FRAME(24, 10),
    ANIMCMD_FRAME( 4, 10),
    ANIMCMD_JUMP(0),
};

const union AnimCmd *const sWirelessStatusIndicatorAnims[]
    __attribute__((section(".rodata.link_rfu_3_wireless_status_indicator_anims"))) =
{
    [WIRELESS_STATUS_ANIM_3_BARS]    = sWirelessStatusIndicator_3Bars,
    [WIRELESS_STATUS_ANIM_2_BARS]    = sWirelessStatusIndicator_2Bars,
    [WIRELESS_STATUS_ANIM_1_BAR]     = sWirelessStatusIndicator_1Bar,
    [WIRELESS_STATUS_ANIM_SEARCHING] = sWirelessStatusIndicator_Searching,
    [WIRELESS_STATUS_ANIM_ERROR]     = sWirelessStatusIndicator_Error,
};

LINK_RFU_3_WIRELESS_STATUS_INDICATOR_SHEET_DATA const struct CompressedSpriteSheet sWirelessStatusIndicatorSpriteSheet =
{
    sWirelessLinkIconPic, 0x0380, TAG_GFX_STATUS_INDICATOR,
};

LINK_RFU_3_WIRELESS_STATUS_INDICATOR_PALETTE_DESCRIPTOR_DATA const struct SpritePalette sWirelessStatusIndicatorSpritePalette =
{
    sWirelessLinkIconPalette, TAG_PAL_STATUS_INDICATOR,
};

LINK_RFU_3_WIRELESS_STATUS_INDICATOR_TEMPLATE_DATA const struct SpriteTemplate sWirelessStatusIndicatorSpriteTemplate =
{
    .tileTag = TAG_GFX_STATUS_INDICATOR,
    .paletteTag = TAG_PAL_STATUS_INDICATOR,
    .oam = &sWirelessStatusIndicatorOamData,
    .anims = sWirelessStatusIndicatorAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

#define STATUS_INDICATOR_ACTIVE 0x1234 // Used to validate active indicator

#define sNextAnimNum  data[0]
#define sSavedAnimNum data[1]
#define sCurrAnimNum  data[2]
#define sFrameDelay   data[3]
#define sFrameIdx     data[4]
#define sTileStart    data[6]
#define sValidator    data[7]

// JP-specific: US uses RECV_QUEUE_NUM_SLOTS == 32, JP == 20 (see link_rfu.h).
// These queue constants are only used by the functions in this file.
#define UNUSED_QUEUE_NUM_SLOTS 2
#define UNUSED_QUEUE_SLOT_LENGTH 256

struct RfuUnusedQueue
{
    u8 slots[UNUSED_QUEUE_NUM_SLOTS][UNUSED_QUEUE_SLOT_LENGTH];
    vu8 recvSlot;
    vu8 sendSlot;
    vu8 count;
    vu8 full;
};

void RfuRecvQueue_Reset(struct RfuRecvQueue *queue)
{
    s32 i;
    s32 j;

    for (i = 0; i < RECV_QUEUE_NUM_SLOTS; i++)
    {
        for (j = 0; j < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; j++)
            queue->slots[i][j] = 0;
    }
    queue->sendSlot = 0;
    queue->recvSlot = 0;
    queue->count = 0;
    queue->full = FALSE;
}

void RfuSendQueue_Reset(struct RfuSendQueue *queue)
{
    s32 i;
    s32 j;

    for (i = 0; i < SEND_QUEUE_NUM_SLOTS; i++)
    {
        for (j = 0; j < COMM_SLOT_LENGTH; j++)
            queue->slots[i][j] = 0;
    }
    queue->sendSlot = 0;
    queue->recvSlot = 0;
    queue->count = 0;
    queue->full = FALSE;
}

static void UNUSED RfuUnusedQueue_Reset(struct RfuUnusedQueue *queue)
{
    s32 i;
    s32 j;

    for (i = 0; i < UNUSED_QUEUE_NUM_SLOTS; i++)
    {
        for (j = 0; j < UNUSED_QUEUE_SLOT_LENGTH; j++)
            queue->slots[i][j] = 0;
    }
    queue->sendSlot = 0;
    queue->recvSlot = 0;
    queue->count = 0;
    queue->full = FALSE;
}

void RfuRecvQueue_Enqueue(struct RfuRecvQueue *queue, u8 *data)
{
    s32 i;
    u16 imeBak;
    u8 count;

    if (queue->count < RECV_QUEUE_NUM_SLOTS)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        count = 0;
        for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i += COMM_SLOT_LENGTH)
        {
            if (data[i] == 0 && data[i + 1] == 0)
                count++;
        }
        if (count != MAX_RFU_PLAYERS)
        {
            for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i++)
                queue->slots[queue->recvSlot][i] = data[i];

            queue->recvSlot++;
            queue->recvSlot %= RECV_QUEUE_NUM_SLOTS;
            queue->count++;

            for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i++)
                data[i] = 0;
        }
        REG_IME = imeBak;
    }
    else
    {
        queue->full = TRUE;
    }
}

void RfuSendQueue_Enqueue(struct RfuSendQueue *queue, u8 *data)
{
    s32 i;
    u16 imeBak;

    if (queue->count < SEND_QUEUE_NUM_SLOTS)
    {
        imeBak = REG_IME;
        REG_IME = 0;
        for (i = 0; i < COMM_SLOT_LENGTH; i++)
        {
            if (data[i] != 0)
                break;
        }
        if (i != COMM_SLOT_LENGTH)
        {
            for (i = 0; i < COMM_SLOT_LENGTH; i++)
                queue->slots[queue->recvSlot][i] = data[i];
            queue->recvSlot++;
            queue->recvSlot %= SEND_QUEUE_NUM_SLOTS;
            queue->count++;

            for (i = 0; i < COMM_SLOT_LENGTH; i++)
                data[i] = 0;
        }
        REG_IME = imeBak;
    }
    else
    {
        queue->full = TRUE;
    }
}

bool8 RfuRecvQueue_Dequeue(struct RfuRecvQueue *queue, u8 *src)
{
    u16 imeBak;
    s32 i;

    imeBak = REG_IME;
    REG_IME = 0;
    if (queue->recvSlot == queue->sendSlot || queue->full)
    {
        for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i++)
            src[i] = 0;

        REG_IME = imeBak;
        return FALSE;
    }
    for (i = 0; i < COMM_SLOT_LENGTH * MAX_RFU_PLAYERS; i++)
    {
        src[i] = queue->slots[queue->sendSlot][i];
    }
    queue->sendSlot++;
    queue->sendSlot %= RECV_QUEUE_NUM_SLOTS;
    queue->count--;
    REG_IME = imeBak;
    return TRUE;
}

bool8 RfuSendQueue_Dequeue(struct RfuSendQueue *queue, u8 *src)
{
    s32 i;
    u16 imeBak;

    if (queue->recvSlot == queue->sendSlot || queue->full)
        return FALSE;

    imeBak = REG_IME;
    REG_IME = 0;
    for (i = 0; i < COMM_SLOT_LENGTH; i++)
        src[i] = queue->slots[queue->sendSlot][i];

    queue->sendSlot++;
    queue->sendSlot %= SEND_QUEUE_NUM_SLOTS;
    queue->count--;
    REG_IME = imeBak;
    return TRUE;
}

void RfuBackupQueue_Enqueue(struct RfuBackupQueue *queue, const u8 *data)
{
    s32 i;

    if (data[1] == 0)
    {
        RfuBackupQueue_Dequeue(queue, NULL);
    }
    else
    {
        for (i = 0; i < COMM_SLOT_LENGTH; i++)
            queue->slots[queue->recvSlot][i] = data[i];

        queue->recvSlot++;
        queue->recvSlot %= BACKUP_QUEUE_NUM_SLOTS;

        if (queue->count < BACKUP_QUEUE_NUM_SLOTS)
            queue->count++;
        else
            queue->sendSlot = queue->recvSlot;
    }
}

bool8 RfuBackupQueue_Dequeue(struct RfuBackupQueue *queue, u8 *src)
{
    s32 i;

    if (queue->count == 0)
        return FALSE;

    if (src != NULL)
    {
        for (i = 0; i < COMM_SLOT_LENGTH; i++)
            src[i] = queue->slots[queue->sendSlot][i];
    }
    queue->sendSlot++;
    queue->sendSlot %= BACKUP_QUEUE_NUM_SLOTS;
    queue->count--;
    return TRUE;
}

static void UNUSED RfuUnusedQueue_Enqueue(struct RfuUnusedQueue *queue, u8 *data)
{
    s32 i;

    if (queue->count < UNUSED_QUEUE_NUM_SLOTS)
    {
        for (i = 0; i < UNUSED_QUEUE_SLOT_LENGTH; i++)
            queue->slots[queue->recvSlot][i] = data[i];

        queue->recvSlot++;
        queue->recvSlot %= UNUSED_QUEUE_NUM_SLOTS;
        queue->count++;
    }
    else
    {
        queue->full = TRUE;
    }
}

static bool8 UNUSED RfuUnusedQueue_Dequeue(struct RfuUnusedQueue *queue, u8 *dest)
{
    s32 i;

    if (queue->recvSlot == queue->sendSlot || queue->full)
        return FALSE;

    for (i = 0; i < UNUSED_QUEUE_SLOT_LENGTH; i++)
        dest[i] = queue->slots[queue->sendSlot][i];

    queue->sendSlot++;
    queue->sendSlot %= UNUSED_QUEUE_NUM_SLOTS;
    queue->count--;
    return TRUE;
}

// Populates an array with a sequence of numbers (which numbers depends on the mode)
// and sets the final element to the total of the other elements
#define SEQ_ARRAY_MAX_SIZE 200
static void UNUSED PopulateArrayWithSequence(u8 *arr, u8 mode)
{
    s32 i;
    u8 rval;
    u16 total = 0;
    switch (mode)
    {
    case 0:
        // Populate with numbers 1-200
        // Total will be 20100
        for (i = 0; i < SEQ_ARRAY_MAX_SIZE; i++)
        {
            arr[i] = i + 1;
            total += i + 1;
        }
        *((u16 *)(arr + i)) = total;
        break;
    case 1:
        // Populate with numbers 1-100
        // Total will be 5050
        for (i = 0; i < 100; i++)
        {
            arr[i] = i + 1;
            total += i + 1;
        }
        *((u16 *)(arr + SEQ_ARRAY_MAX_SIZE)) = total;
        break;
    case 2:
        // Populate with random numbers 0-255
        // Total will be a number 0-51000
        for (i = 0; i < SEQ_ARRAY_MAX_SIZE; i++)
        {
            rval = Random();
            arr[i] = rval;
            total += rval;
        }
        *((u16 *)(arr + i)) = total;
        break;
    case 3:
        // Populate with numbers 1-200 + sSequenceArrayValOffset
        // Total will be a number 20100-51000
        for (i = 0; i < SEQ_ARRAY_MAX_SIZE; i++)
        {
            arr[i] = i + 1 + sSequenceArrayValOffset;
            total += (i + 1 + sSequenceArrayValOffset) & 0xFF;
        }
        *((u16 *)(arr + i)) = total;
        sSequenceArrayValOffset++;
        break;
    }
}

static void UNUSED PkmnStrToASCII(u8 *asciiStr, const u8 *pkmnStr)
{
    s32 i;

    for (i = 0; pkmnStr[i] != EOS; i++)
        asciiStr[i] = sWireless_RSEtoASCIITable[pkmnStr[i]];
    asciiStr[i] = 0;
}

static void UNUSED ASCIIToPkmnStr(u8 *pkmnStr, const u8 *asciiStr)
{
    s32 i;

    for (i = 0; asciiStr[i] != 0; i++)
        pkmnStr[i] = sWireless_ASCIItoRSETable[asciiStr[i]];
    pkmnStr[i] = EOS;
}

// JP: still called from asm (UpdateWirelessStatusIndicatorSprite area), so it
// stays externally visible unlike the US static.
u8 GetConnectedChildStrength(u8 maxFlags)
{
    u8 flagCount = 0;
    u32 flags = gRfuLinkStatus->connSlotFlag;
    u8 i;

    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        for (i = 0; i < 4; flags >>= 1, i++)
        {
            if (flags & 1)
            {
                if (maxFlags == flagCount + 1)
                {
                    return gRfuLinkStatus->strength[i];
                    break;
                }
                flagCount++;
            }
        }
    }
    else
    {
        for (i = 0; i < 4; flags >>= 1, i++)
        {
            if (flags & 1)
                return gRfuLinkStatus->strength[i];
        }
    }
    return 0;
}

void InitHostRfuGameData(struct RfuGameData *data, u8 activity, bool32 startedActivity, s32 partnerInfo)
{
    s32 i;

    for (i = 0; i < (s32)ARRAY_COUNT(data->compatibility.playerTrainerId); i++)
        data->compatibility.playerTrainerId[i] = gSaveBlock2Ptr->playerTrainerId[i];

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        data->partnerInfo[i] = partnerInfo;
        partnerInfo >>= 8; // Each element is 1 byte
    }
    data->playerGender = gSaveBlock2Ptr->playerGender;
    data->activity = activity;
    data->startedActivity = startedActivity;
    data->compatibility.language = GAME_LANGUAGE;
    data->compatibility.version = GAME_VERSION;
    data->compatibility.hasNews = FALSE;
    data->compatibility.hasCard = FALSE;
    data->compatibility.unknown = FALSE;
    data->compatibility.canLinkNationally = FlagGet(FLAG_IS_CHAMPION);
    data->compatibility.hasNationalDex = IsNationalPokedexEnabled();
    data->compatibility.gameClear = FlagGet(FLAG_SYS_GAME_CLEAR);
}

bool8 Rfu_GetCompatiblePlayerData(struct RfuGameData *gameData, u8 *username, u8 idx)
{
    bool8 retVal;

    if (lman.parent_child == MODE_PARENT)
    {
        retVal = TRUE;
        if (IsRfuSerialNumberValid(gRfuLinkStatus->partner[idx].serialNo) && ((gRfuLinkStatus->getNameFlag >> idx) & 1))
        {
            memcpy(gameData, gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
            memcpy(username, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        }
        else
        {
            memset(gameData, 0, RFU_GAME_NAME_LENGTH);
            memset(username, 0, RFU_USER_NAME_LENGTH);
        }
    }
    else
    {
        retVal = FALSE;
        if (IsRfuSerialNumberValid(gRfuLinkStatus->partner[idx].serialNo))
        {
            memcpy(gameData, gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
            memcpy(username, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        }
        else
        {
            memset(gameData, 0, RFU_GAME_NAME_LENGTH);
            memset(username, 0, RFU_USER_NAME_LENGTH);
        }
    }
    return retVal;
}

bool8 Rfu_GetWonderDistributorPlayerData(struct RfuGameData *gameData, u8 *username, u8 idx)
{
    bool8 retVal = FALSE;
    if (gRfuLinkStatus->partner[idx].serialNo == RFU_SERIAL_WONDER_DISTRIBUTOR)
    {
        memcpy(gameData, gRfuLinkStatus->partner[idx].gname, RFU_GAME_NAME_LENGTH);
        memcpy(username, gRfuLinkStatus->partner[idx].uname, RFU_USER_NAME_LENGTH);
        retVal = TRUE;
    }
    else
    {
        memset(gameData, 0, RFU_GAME_NAME_LENGTH);
        memset(username, 0, RFU_USER_NAME_LENGTH);
    }
    return retVal;
}

void CopyHostRfuGameDataAndUsername(struct RfuGameData *gameData, u8 *username)
{
    memcpy(gameData, &gHostRfuGameData, RFU_GAME_NAME_LENGTH);
    memcpy(username, gHostRfuUsername, RFU_USER_NAME_LENGTH);
}

void CreateWirelessStatusIndicatorSprite(u8 x, u8 y)
{
    u8 sprId;

    if (x == 0 && y == 0)
    {
        x = 231;
        y = 8;
    }
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        sprId = CreateSprite(&sWirelessStatusIndicatorSpriteTemplate, x, y, 0);
        gSprites[sprId].sValidator = STATUS_INDICATOR_ACTIVE;
        gSprites[sprId].sTileStart = GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag);
        gSprites[sprId].invisible = TRUE;
        gWirelessStatusIndicatorSpriteId = sprId;
    }
    else
    {
        gWirelessStatusIndicatorSpriteId = CreateSprite(&sWirelessStatusIndicatorSpriteTemplate, x, y, 0);
        gSprites[gWirelessStatusIndicatorSpriteId].sValidator = STATUS_INDICATOR_ACTIVE;
        gSprites[gWirelessStatusIndicatorSpriteId].sTileStart = GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag);
        gSprites[gWirelessStatusIndicatorSpriteId].invisible = TRUE;
    }
}

void DestroyWirelessStatusIndicatorSprite(void)
{
    if (gSprites[gWirelessStatusIndicatorSpriteId].sValidator == STATUS_INDICATOR_ACTIVE)
    {
        gSprites[gWirelessStatusIndicatorSpriteId].sValidator = 0;
        DestroySprite(&gSprites[gWirelessStatusIndicatorSpriteId]);
        gMain.oamBuffer[125] = gDummyOamData;
        CpuCopy16(&gDummyOamData, (struct OamData *)OAM + 125, sizeof(struct OamData));
    }
}

void LoadWirelessStatusIndicatorSpriteGfx(void)
{
    if (GetSpriteTileStartByTag(sWirelessStatusIndicatorSpriteSheet.tag) == 0xFFFF)
        LoadCompressedSpriteSheet(&sWirelessStatusIndicatorSpriteSheet);
    LoadSpritePalette(&sWirelessStatusIndicatorSpritePalette);
    gWirelessStatusIndicatorSpriteId = SPRITE_NONE;
}

static u8 GetParentSignalStrength(void)
{
    u8 i;
    u8 flags = gRfuLinkStatus->connSlotFlag;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (flags & 1)
            return gRfuLinkStatus->strength[i];
        flags >>= 1;
    }
    return 0;
}

static void SetWirelessStatusIndicatorAnim(struct Sprite *sprite, s32 animNum)
{
    if (sprite->sCurrAnimNum != animNum)
    {
        sprite->sCurrAnimNum = animNum;
        sprite->sFrameDelay = 0;
        sprite->sFrameIdx = 0;
    }
}

void UpdateWirelessStatusIndicatorSprite(void)
{
    if (gWirelessStatusIndicatorSpriteId != SPRITE_NONE && gSprites[gWirelessStatusIndicatorSpriteId].sValidator == STATUS_INDICATOR_ACTIVE)
    {
        struct Sprite *sprite = &gSprites[gWirelessStatusIndicatorSpriteId];
        u8 signalStrength = RFU_LINK_ICON_LEVEL4_MAX;
        u8 i = 0;

        // Get weakest signal strength
        if (gRfuLinkStatus->parentChild == MODE_PARENT)
        {
            for (i = 0; i < GetLinkPlayerCount() - 1; i++)
            {
                if (signalStrength >= GetConnectedChildStrength(i + 1))
                    signalStrength = GetConnectedChildStrength(i + 1);
            }
        }
        else
        {
            signalStrength = GetParentSignalStrength();
        }

        // Set signal strength sprite anim number
        if (IsRfuRecoveringFromLinkLoss() == TRUE)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_ERROR;
        else if (signalStrength <= RFU_LINK_ICON_LEVEL1_MAX)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_SEARCHING;
        else if (signalStrength >= RFU_LINK_ICON_LEVEL2_MIN && signalStrength <= RFU_LINK_ICON_LEVEL2_MAX)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_1_BAR;
        else if (signalStrength >= RFU_LINK_ICON_LEVEL3_MIN && signalStrength <= RFU_LINK_ICON_LEVEL3_MAX)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_2_BARS;
        else if (signalStrength >= RFU_LINK_ICON_LEVEL4_MIN)
            sprite->sNextAnimNum = WIRELESS_STATUS_ANIM_3_BARS;

        if (sprite->sNextAnimNum != sprite->sSavedAnimNum)
        {
            SetWirelessStatusIndicatorAnim(sprite, sprite->sNextAnimNum);
            sprite->sSavedAnimNum = sprite->sNextAnimNum;
        }
        if (sprite->anims[sprite->sCurrAnimNum][sprite->sFrameIdx].frame.duration < sprite->sFrameDelay)
        {
            sprite->sFrameIdx++;
            sprite->sFrameDelay = 0;
            if (sprite->anims[sprite->sCurrAnimNum][sprite->sFrameIdx].type == -2)
                sprite->sFrameIdx = 0;
        }
        else
        {
            sprite->sFrameDelay++;
        }
        gMain.oamBuffer[125] = sWirelessStatusIndicatorOamData;
        gMain.oamBuffer[125].x = sprite->x + sprite->centerToCornerVecX;
        gMain.oamBuffer[125].y = sprite->y + sprite->centerToCornerVecY;
        gMain.oamBuffer[125].paletteNum = sprite->oam.paletteNum;
        gMain.oamBuffer[125].tileNum = sprite->sTileStart + sprite->anims[sprite->sCurrAnimNum][sprite->sFrameIdx].frame.imageValue;
        CpuCopy16(&gMain.oamBuffer[125], (struct OamData *)OAM + 125, sizeof(struct OamData));
        if (RfuGetStatus() == RFU_STATUS_FATAL_ERROR)
            DestroyWirelessStatusIndicatorSprite();
    }
}

#undef sNextAnimNum
#undef sSavedAnimNum
#undef sCurrAnimNum
#undef sFrameDelay
#undef sFrameIdx
#undef sTileStart
#undef sValidator

static void CopyTrainerRecord(struct TrainerNameRecord *dest, u32 trainerId, const u8 *name)
{
    dest->trainerId = trainerId;
    StringCopy(dest->trainerName, name);
}

static bool32 NameIsNotEmpty(const u8 *name)
{
    s32 i;

    for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
    {
        if (name[i] != 0)
            return TRUE;
    }
    return FALSE;
}

// JP: named RecordMixTrainerNames in the JP ROM, but it corresponds to US
// SaveLinkTrainerNames. JP differences: no LANGUAGE_JAPANESE filter (US skips
// non-Japanese players), and wiping an old record only clears trainerName[0].
void SaveLinkTrainerNames(void)
{
    if (gWirelessCommType != 0)
    {
        s32 i;
        s32 j;
        s32 nextSpace;
        s32 connectedTrainerRecordIndices[MAX_RFU_PLAYERS];
        struct TrainerNameRecord *newRecords = AllocZeroed(sizeof(gSaveBlock1Ptr->trainerNameRecords));

        // Check if we already have a record saved for connected trainers.
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            connectedTrainerRecordIndices[i] = -1;
            for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords); j++)
            {
                if ((u16)gLinkPlayers[i].trainerId ==  gSaveBlock1Ptr->trainerNameRecords[j].trainerId && StringCompare(gLinkPlayers[i].name, gSaveBlock1Ptr->trainerNameRecords[j].trainerName) == 0)
                    connectedTrainerRecordIndices[i] = j;
            }
        }

        // Save the connected trainers first, at the top of the list.
        nextSpace = 0;
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            if (i != GetMultiplayerId())
            {
                CopyTrainerRecord(&newRecords[nextSpace], (u16)gLinkPlayers[i].trainerId, gLinkPlayers[i].name);

                // If we already had a record for this trainer, wipe it so that the next step doesn't duplicate it.
                if (connectedTrainerRecordIndices[i] >= 0)
                    gSaveBlock1Ptr->trainerNameRecords[connectedTrainerRecordIndices[i]].trainerName[0] = 0;
                nextSpace++;
            }
        }

        // Copy all non-empty records to the new list, in the order they appear on the old list. If the list is full,
        // the last (oldest) records will be dropped.
        for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords); i++)
        {
            if (NameIsNotEmpty(gSaveBlock1Ptr->trainerNameRecords[i].trainerName))
            {
                CopyTrainerRecord(&newRecords[nextSpace], gSaveBlock1Ptr->trainerNameRecords[i].trainerId, gSaveBlock1Ptr->trainerNameRecords[i].trainerName);
                if (++nextSpace >= (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords))
                    break;
            }
        }

        // Finalize the new list, and clean up.
        memcpy(gSaveBlock1Ptr->trainerNameRecords, newRecords, sizeof(gSaveBlock1Ptr->trainerNameRecords));
        Free(newRecords);
    }
}

bool32 PlayerHasMetTrainerBefore(u16 id, u8 *name)
{
    s32 i;

    for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords); i++)
    {
        if (StringCompare(gSaveBlock1Ptr->trainerNameRecords[i].trainerName, name) == 0 && gSaveBlock1Ptr->trainerNameRecords[i].trainerId == id)
            return TRUE;

        if (!NameIsNotEmpty(gSaveBlock1Ptr->trainerNameRecords[i].trainerName))
            return FALSE;
    }
    return FALSE;
}

void WipeTrainerNameRecords(void)
{
    s32 i;

    for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock1Ptr->trainerNameRecords); i++)
    {
        gSaveBlock1Ptr->trainerNameRecords[i].trainerId = 0;
        CpuFill16(0, gSaveBlock1Ptr->trainerNameRecords[i].trainerName, PLAYER_NAME_LENGTH + 1);
    }
}
