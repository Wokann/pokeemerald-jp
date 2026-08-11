#include "global.h"
#include "link_rfu.h"
#include "random.h"
#include "event_data.h"
#include "text.h"

// JP ROM/RAM data (bound in sym_iwram_jp.txt; JP uses a fixed IWRAM address
// instead of US's file-static variable).
extern IWRAM_DATA u8 sSequenceArrayValOffset;

// JP: the two conversion tables live at fixed JP ROM addresses (data.s), so
// they are bound in ld_script_jp.txt instead of being defined in C.
extern const u8 sWireless_ASCIItoRSETable[256];
extern const u8 sWireless_RSEtoASCIITable[256];

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
