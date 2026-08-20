#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "ereader_helpers.h"
#include "link.h"
#include "main.h"
#include "union_room.h"
#include "save.h"
#include "sprite.h"
#include "task.h"
#include "util.h"
#include "trainer_hill.h"

#include "constants/trainers.h"


#define EREADER_ASSERT_STRINGS __attribute__((section(".rodata.ereader_assert_strings")))

static const u8 sEReaderToolFileName[] EREADER_ASSERT_STRINGS = "cereader_tool.c";
static const u8 sEReaderTrainerHillDummyAssert[] EREADER_ASSERT_STRINGS = "ttdata->dummy == 0\0";
static const u8 sEReaderTrainerHillIdAssert[] EREADER_ASSERT_STRINGS = "ttdata->id == 0";
#include "constants/moves.h"
#include "constants/items.h"
#include "constants/trainer_hill.h"

// Save data using TryWriteSpecialSaveSector is allowed to exceed SECTOR_DATA_SIZE (up to the counter field)
STATIC_ASSERT(sizeof(struct TrainerHillChallenge) <= SECTOR_COUNTER_OFFSET, TrainerHillChallengeFreeSpace);

struct SendRecvMgr
{
    bool8 isParent;
    u8 state;              // EREADER_XFR_STATE_*
    u8 xferState;          // EREADER_XFER_*
    u8 checksumResult;     // EREADER_CHECKSUM_*
    u8 cancellationReason; // EREADER_CANCEL_*
    u32 *data;             // Payload source or destination
    int cursor;            // Index of the next word
    int size;              // Last word index
    int checksum;
};

static void GetKeyInput(void);
static u16 DetermineSendRecvState(u8);
static void EnableSio(void);
static void DisableTm3(void);
static void SetUpTransferManager(size_t, const void *, void *);
static void StartTm3(void);

extern struct SendRecvMgr sSendRecvMgr;
extern u16 sJoyNewOrRepeated;
extern u16 sJoyNew;
extern u16 sSendRecvStatus;
extern u16 sCounter1;
extern u32 sCounter2;
extern u16 sSavedIme;
extern u16 sSavedIe;
extern u16 sSavedTm3Cnt;
extern u16 sSavedSioCnt;
extern u16 sSavedRCnt;
// JP-only trainer hill templates at 0x085FA9E4 (bound in ld_script_jp.txt).
// Decoded with tools/decode_jp_text.py: first trainer's name is "マキエ",
// its mons are "マルノーム"/"ドクケイル"/"ジーランス".
extern const struct TrainerHillTrainer sTrainerHillTrainerTemplates_JP[];

static u8 GetTrainerHillUnkVal(void)
{
    return (gSaveBlock1Ptr->trainerHill.unused + 1) % 256;
}

// JP 0x081D2F28: JP checksum is at offset 0x26C of the trainer record.
static bool32 ValidateTrainerChecksum(struct EReaderTrainerHillTrainer *hillTrainer)
{
    int checksum = CalcByteArraySum((u8 *)hillTrainer, offsetof(typeof(*hillTrainer), checksum));
    if (checksum != hillTrainer->checksum)
        return FALSE;

    return TRUE;
}

// JP 0x081D2F4C
bool8 ValidateTrainerHillData(struct EReaderTrainerHillSet *hillSet)
{
    u32 i;
    u32 checksum;
    int numTrainers = hillSet->numTrainers;

    // Validate number of trainers
    if (numTrainers < 1 || numTrainers > NUM_TRAINER_HILL_TRAINERS)
        return FALSE;

    // Validate trainers
    for (i = 0; i < numTrainers; i++)
    {
        if (!ValidateTrainerChecksum(&hillSet->trainers[i]))
            return FALSE;
    }

    // Validate checksum
    checksum = CalcByteArraySum((u8 *)hillSet->trainers, numTrainers * sizeof(struct EReaderTrainerHillTrainer));
    if (checksum != hillSet->checksum)
        return FALSE;

    return TRUE;
}

// JP 0x081D2F9C
static bool32 ValidateTrainerHillChecksum(struct EReaderTrainerHillSet *hillSet)
{
    u32 checksum;
    int numTrainers = hillSet->numTrainers;
    if (numTrainers < 1 || numTrainers > NUM_TRAINER_HILL_TRAINERS)
        return FALSE;

    checksum = CalcByteArraySum((u8 *)hillSet->trainers, sizeof(struct EReaderTrainerHillSet) - offsetof(struct EReaderTrainerHillSet, trainers));
    if (checksum != hillSet->checksum)
        return FALSE;

    return TRUE;
}

// JP 0x081D2FC8: kept as asm (compiler register allocation differs from US).
__attribute__((naked)) static bool32 TryWriteTrainerHill_Internal(struct EReaderTrainerHillSet *hillSet, struct TrainerHillChallenge *challenge)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #4\n\t"
            "mov r8, r0\n\t"
            "mov sb, r1\n\t"
            "ldrh r0, [r0, #2]\n\t"
            "cmp r0, #0\n\t"
            "beq _081D2FEA\n\t"
            "ldr r0, _081D3080\n\t"
            "ldr r2, _081D3084\n\t"
            "movs r1, #0xe1\n\t"
            "movs r3, #1\n\t"
            "bl AGBAssert\n\t"
            "_081D2FEA:\n\t"
            "mov r1, r8\n\t"
            "ldrb r0, [r1, #1]\n\t"
            "cmp r0, #0\n\t"
            "beq _081D2FFE\n\t"
            "ldr r0, _081D3080\n\t"
            "ldr r2, _081D3088\n\t"
            "movs r1, #0xe2\n\t"
            "movs r3, #1\n\t"
            "bl AGBAssert\n\t"
            "_081D2FFE:\n\t"
            "movs r2, #0x80\n\t"
            "lsls r2, r2, #5\n\t"
            "mov r0, sb\n\t"
            "movs r1, #0\n\t"
            "bl memset\n\t"
            "mov r1, r8\n\t"
            "ldrb r0, [r1]\n\t"
            "mov r1, sb\n\t"
            "strb r0, [r1]\n\t"
            "bl GetTrainerHillUnkVal\n\t"
            "mov r1, sb\n\t"
            "strb r0, [r1, #1]\n\t"
            "mov r1, r8\n\t"
            "ldrb r0, [r1]\n\t"
            "adds r0, #1\n\t"
            "asrs r0, r0, #1\n\t"
            "mov r1, sb\n\t"
            "strb r0, [r1, #2]\n\t"
            "movs r5, #0\n\t"
            "adds r1, #8\n\t"
            "str r1, [sp]\n\t"
            "mov r0, r8\n\t"
            "ldrb r0, [r0]\n\t"
            "cmp r5, r0\n\t"
            "bge _081D30C6\n\t"
            "mov r7, r8\n\t"
            "adds r7, #0xc\n\t"
            "mov r6, r8\n\t"
            "movs r1, #0xa8\n\t"
            "lsls r1, r1, #1\n\t"
            "add r1, r8\n\t"
            "mov sl, r1\n\t"
            "_081D3042:\n\t"
            "movs r0, #1\n\t"
            "ands r0, r5\n\t"
            "cmp r0, #0\n\t"
            "bne _081D308C\n\t"
            "lsrs r0, r5, #0x1f\n\t"
            "adds r0, r5, r0\n\t"
            "asrs r0, r0, #1\n\t"
            "lsls r4, r0, #4\n\t"
            "subs r4, r4, r0\n\t"
            "lsls r4, r4, #2\n\t"
            "subs r4, r4, r0\n\t"
            "lsls r4, r4, #4\n\t"
            "add r4, sb\n\t"
            "ldrb r0, [r6, #8]\n\t"
            "strb r0, [r4, #8]\n\t"
            "movs r1, #0xa5\n\t"
            "lsls r1, r1, #2\n\t"
            "adds r0, r4, r1\n\t"
            "mov r1, sl\n\t"
            "movs r2, #0x92\n\t"
            "lsls r2, r2, #1\n\t"
            "bl memcpy\n\t"
            "adds r4, #0xc\n\t"
            "adds r0, r4, #0\n\t"
            "adds r1, r7, #0\n\t"
            "movs r2, #0xa2\n\t"
            "lsls r2, r2, #1\n\t"
            "bl memcpy\n\t"
            "b _081D30B2\n\t"
            ".align 2, 0\n\t"
            "_081D3080: .4byte sEReaderToolFileName\n\t"
            "_081D3084: .4byte sEReaderTrainerHillDummyAssert\n\t"
            "_081D3088: .4byte sEReaderTrainerHillIdAssert\n\t"
            "_081D308C:\n\t"
            "lsrs r1, r5, #0x1f\n\t"
            "adds r1, r5, r1\n\t"
            "asrs r1, r1, #1\n\t"
            "lsls r0, r1, #4\n\t"
            "subs r0, r0, r1\n\t"
            "lsls r0, r0, #2\n\t"
            "subs r0, r0, r1\n\t"
            "lsls r0, r0, #4\n\t"
            "add r0, sb\n\t"
            "ldrb r1, [r6, #8]\n\t"
            "strb r1, [r0, #9]\n\t"
            "movs r1, #0xa8\n\t"
            "lsls r1, r1, #1\n\t"
            "adds r0, r0, r1\n\t"
            "adds r1, r7, #0\n\t"
            "movs r2, #0xa2\n\t"
            "lsls r2, r2, #1\n\t"
            "bl memcpy\n\t"
            "_081D30B2:\n\t"
            "movs r0, #0x9c\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r7, r7, r0\n\t"
            "adds r6, r6, r0\n\t"
            "add sl, r0\n\t"
            "adds r5, #1\n\t"
            "mov r1, r8\n\t"
            "ldrb r1, [r1]\n\t"
            "cmp r5, r1\n\t"
            "blt _081D3042\n\t"
            "_081D30C6:\n\t"
            "movs r0, #1\n\t"
            "ands r0, r5\n\t"
            "cmp r0, #0\n\t"
            "beq _081D30FC\n\t"
            "lsrs r2, r5, #0x1f\n\t"
            "adds r2, r5, r2\n\t"
            "asrs r2, r2, #1\n\t"
            "lsls r0, r2, #4\n\t"
            "subs r0, r0, r2\n\t"
            "lsls r0, r0, #2\n\t"
            "subs r0, r0, r2\n\t"
            "lsls r0, r0, #4\n\t"
            "add r0, sb\n\t"
            "movs r1, #0xa8\n\t"
            "lsls r1, r1, #1\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r3, _081D3118\n\t"
            "lsls r1, r2, #2\n\t"
            "adds r1, r1, r2\n\t"
            "lsls r1, r1, #4\n\t"
            "adds r1, r1, r2\n\t"
            "lsls r1, r1, #2\n\t"
            "adds r1, r1, r3\n\t"
            "movs r2, #0xa2\n\t"
            "lsls r2, r2, #1\n\t"
            "bl memcpy\n\t"
            "_081D30FC:\n\t"
            "movs r1, #0xec\n\t"
            "lsls r1, r1, #4\n\t"
            "ldr r0, [sp]\n\t"
            "bl CalcByteArraySum\n\t"
            "mov r1, sb\n\t"
            "str r0, [r1, #4]\n\t"
            "movs r0, #0x1e\n\t"
            "bl TryWriteSpecialSaveSection\n\t"
            "cmp r0, #1\n\t"
            "bne _081D311C\n\t"
            "movs r0, #1\n\t"
            "b _081D311E\n\t"
            ".align 2, 0\n\t"
            "_081D3118: .4byte sTrainerHillTrainerTemplates_JP\n\t"
            "_081D311C:\n\t"
            "movs r0, #0\n\t"
            "_081D311E:\n\t"
            "add sp, #4\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            ".syntax divided\n");
}

bool32 TryWriteTrainerHill(struct EReaderTrainerHillSet *hillSet)
{
    void *buffer = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryWriteTrainerHill_Internal(hillSet, buffer);
    Free(buffer);
    return result;
}

// JP 0x081D3158
static bool32 TryReadTrainerHill_Internal(struct EReaderTrainerHillSet *dest, u8 *buffer)
{
    if (TryReadSpecialSaveSector(SECTOR_ID_TRAINER_HILL, buffer) != SAVE_STATUS_OK)
        return FALSE;

    memcpy(dest, buffer, sizeof(struct EReaderTrainerHillSet));
    if (!ValidateTrainerHillChecksum(dest))
        return FALSE;

    return TRUE;
}

bool32 TryReadTrainerHill(struct EReaderTrainerHillSet *hillSet)
{
    u8 *buffer = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryReadTrainerHill_Internal(hillSet, buffer);
    Free(buffer);
    return result;
}

bool32 ReadTrainerHillAndValidate(void)
{
    struct EReaderTrainerHillSet *hillSet = AllocZeroed(SECTOR_SIZE);
    bool32 result = TryReadTrainerHill(hillSet);
    Free(hillSet);
    return result;
}

int EReader_Send(int size, const void *src)
{
    int result;
    int sendStatus;

    EReaderHelper_SaveRegsState();
    while (1)
    {
        GetKeyInput();
        if (sJoyNew & B_BUTTON)
            gShouldAdvanceLinkState = 2;

        sendStatus = EReaderHandleTransfer(1, size, src, NULL);
        sSendRecvStatus = sendStatus;
        if ((sSendRecvStatus & EREADER_XFER_MASK) == 0 && sSendRecvStatus & EREADER_CHECKSUM_OK_MASK)
        {
            result = 0;
            break;
        }
        else if (sSendRecvStatus & EREADER_CANCEL_KEY_MASK)
        {
            result = 1;
            break;
        }
        else if (sSendRecvStatus & EREADER_CANCEL_TIMEOUT_MASK)
        {
            result = 2;
            break;
        }
        else
        {
            gShouldAdvanceLinkState = 0;
            VBlankIntrWait();
        }
    }

    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
    EReaderHelper_RestoreRegsState();
    return result;
}

int EReader_Recv(void *dest)
{
    int result;
    int recvStatus;

    EReaderHelper_SaveRegsState();
    while (1)
    {
        GetKeyInput();
        if (sJoyNew & B_BUTTON)
            gShouldAdvanceLinkState = 2;

        recvStatus = EReaderHandleTransfer(0, 0, NULL, dest);
        sSendRecvStatus = recvStatus;
        if ((sSendRecvStatus & EREADER_XFER_MASK) == 0 && sSendRecvStatus & EREADER_CHECKSUM_OK_MASK)
        {
            result = 0;
            break;
        }
        else if (sSendRecvStatus & EREADER_CANCEL_KEY_MASK)
        {
            result = 1;
            break;
        }
        else if (sSendRecvStatus & EREADER_CANCEL_TIMEOUT_MASK)
        {
            result = 2;
            break;
        }
        else
        {
            gShouldAdvanceLinkState = 0;
            VBlankIntrWait();
        }
    }

    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
    EReaderHelper_RestoreRegsState();
    return result;
}

static void CloseSerial(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_SIOCNT = 0;
    REG_TM3CNT_H = 0;
    REG_IF = INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL;
}

static void OpenSerialMulti(void)
{
    REG_IME = 0;
    REG_IE &= ~(INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = SIO_MULTI_MODE;
    REG_SIOCNT |= SIO_INTR_ENABLE | SIO_115200_BPS;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_SERIAL;
    REG_IME = 1;

    if (sSendRecvMgr.state == 0)
        CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
}

static void OpenSerial32(void)
{
    REG_RCNT = 0;
    REG_SIOCNT = SIO_32BIT_MODE | SIO_INTR_ENABLE;
    REG_SIOCNT |= SIO_MULTI_SD;
    gShouldAdvanceLinkState = 0;
    sCounter1 = 0;
    sCounter2 = 0;
}

int EReaderHandleTransfer(u8 mode, size_t size, const void *data, void *recvBuffer)
{
    switch (sSendRecvMgr.state)
    {
    case EREADER_XFR_STATE_INIT:
        OpenSerialMulti();
        sSendRecvMgr.xferState = EREADER_XFER_EXE;
        sSendRecvMgr.state = EREADER_XFR_STATE_HANDSHAKE;
        break;
    case EREADER_XFR_STATE_HANDSHAKE:
        if (DetermineSendRecvState(mode))
            EnableSio();

        if (gShouldAdvanceLinkState == 2)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_KEY;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    case EREADER_XFR_STATE_START:
        OpenSerial32();
        SetUpTransferManager(size, data, recvBuffer);
        sSendRecvMgr.state = EREADER_XFR_STATE_TRANSFER;
        // fall through
    case EREADER_XFR_STATE_TRANSFER:
        if (gShouldAdvanceLinkState == 2)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_KEY;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        else
        {
            sCounter1++;
            sCounter2++;
            if (!sSendRecvMgr.isParent && sCounter2 > 60)
            {
                sSendRecvMgr.cancellationReason = EREADER_CANCEL_TIMEOUT;
                sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
            }

            if (sSendRecvMgr.xferState != EREADER_XFER_CHK)
            {
                if (sSendRecvMgr.isParent && sCounter1 > 2)
                {
                    EnableSio();
                    sSendRecvMgr.xferState = EREADER_XFER_CHK;
                }
                else
                {
                    EnableSio();
                    sSendRecvMgr.xferState = EREADER_XFER_CHK;
                }
            }
        }
        break;
    case EREADER_XFR_STATE_TRANSFER_DONE:
        OpenSerialMulti();
        sSendRecvMgr.state = EREADER_XFR_STATE_CHECKSUM;
        break;
    case EREADER_XFR_STATE_CHECKSUM:
        if (sSendRecvMgr.isParent == TRUE && sCounter1 > 2)
            EnableSio();

        if (++sCounter1 > 60)
        {
            sSendRecvMgr.cancellationReason = EREADER_CANCEL_TIMEOUT;
            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    case EREADER_XFR_STATE_DONE:
        if (sSendRecvMgr.xferState)
        {
            CloseSerial();
            sSendRecvMgr.xferState = 0;
        }
        break;
    }

    return (sSendRecvMgr.xferState << EREADER_XFER_SHIFT)
         | (sSendRecvMgr.cancellationReason << EREADER_CANCEL_SHIFT)
         | (sSendRecvMgr.checksumResult << EREADER_CHECKSUM_SHIFT);
}

static u16 DetermineSendRecvState(u8 mode)
{
    bool16 resp;
    if ((*(vu32 *)REG_ADDR_SIOCNT & (SIO_MULTI_SI | SIO_MULTI_SD)) == SIO_MULTI_SD && mode)
        resp = sSendRecvMgr.isParent = TRUE;
    else
        resp = sSendRecvMgr.isParent = FALSE;
    return resp;
}

static void SetUpTransferManager(size_t size, const void *data, void *recvBuffer)
{
    if (sSendRecvMgr.isParent)
    {
        REG_SIOCNT |= SIO_38400_BPS;
        sSendRecvMgr.data = (void *)data;
        REG_SIODATA32 = size;
        sSendRecvMgr.size = size / 4 + 1;
        StartTm3();
    }
    else
    {
        REG_SIOCNT = REG_SIOCNT;
        sSendRecvMgr.data = recvBuffer;
    }
}

static void StartTm3(void)
{
    REG_TM3CNT_L = -601;
    REG_TM3CNT_H = TIMER_INTR_ENABLE;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_TIMER3;
    REG_IME = 1;
}

void EReaderHelper_Timer3Callback(void)
{
    DisableTm3();
    EnableSio();
}

void EReaderHelper_SerialCallback(void)
{
    u16 i, cnt1, cnt2;
    u32 recv32;
    u16 recv[4];

    switch (sSendRecvMgr.state)
    {
    case EREADER_XFR_STATE_HANDSHAKE:
        REG_SIOMLT_SEND = EREADER_HANDSHAKE;
        *(u64 *)recv = REG_SIOMLT_RECV;
        for (i = 0, cnt1 = 0, cnt2 = 0; i < 4; i++)
        {
            if (recv[i] == EREADER_HANDSHAKE)
                cnt1++;
            else if (recv[i] != 0xFFFF)
                cnt2++;
        }

        if (cnt1 == 2 && cnt2 == 0)
            sSendRecvMgr.state = 2;
        break;
    case EREADER_XFR_STATE_TRANSFER:
        recv32 = REG_SIODATA32;
        // The first value sent by the EReader is the payload size
        if (!sSendRecvMgr.cursor && !sSendRecvMgr.isParent)
            sSendRecvMgr.size = recv32 / 4 + 1;

        if (sSendRecvMgr.isParent == TRUE)
        {
            // Send mode
            if (sSendRecvMgr.cursor < sSendRecvMgr.size)
            {
                REG_SIODATA32 = sSendRecvMgr.data[sSendRecvMgr.cursor];
                sSendRecvMgr.checksum += sSendRecvMgr.data[sSendRecvMgr.cursor];
            }
            else
            {
                REG_SIODATA32 = sSendRecvMgr.checksum;
            }
        }
        else
        {
            // Receive mode
            if (sSendRecvMgr.cursor > 0 && sSendRecvMgr.cursor < sSendRecvMgr.size + 1)
            {
                sSendRecvMgr.data[sSendRecvMgr.cursor - 1] = recv32;
                sSendRecvMgr.checksum += recv32;
            }
            else if (sSendRecvMgr.cursor)
            {
                if (sSendRecvMgr.checksum == recv32)
                    sSendRecvMgr.checksumResult = EREADER_CHECKSUM_OK;
                else
                    sSendRecvMgr.checksumResult = EREADER_CHECKSUM_ERR;
            }

            sCounter2 = 0;
        }

        if (++sSendRecvMgr.cursor < sSendRecvMgr.size + 2)
        {
            if (sSendRecvMgr.isParent)
                REG_TM3CNT_H |= TIMER_ENABLE;
            else
                EnableSio();
        }
        else
        {
            sSendRecvMgr.state = EREADER_XFR_STATE_TRANSFER_DONE;
            sCounter1 = 0;
        }
        break;
    case EREADER_XFR_STATE_CHECKSUM:
        if (!sSendRecvMgr.isParent)
            REG_SIOMLT_SEND = sSendRecvMgr.checksumResult;

        *(vu64 *)recv = REG_SIOMLT_RECV;
        if (recv[1] == EREADER_CHECKSUM_OK || recv[1] == EREADER_CHECKSUM_ERR)
        {
            if (sSendRecvMgr.isParent == TRUE)
                sSendRecvMgr.checksumResult = recv[1]; // EReader has (in)validated the payload

            sSendRecvMgr.state = EREADER_XFR_STATE_DONE;
        }
        break;
    }
}

// JP 0x081D37BC: JP enables the SIOCNT SI bit directly.
static void EnableSio(void)
{
    REG_SIOCNT |= 0x80;
}

static void DisableTm3(void)
{
    REG_TM3CNT_H &= ~TIMER_ENABLE;
    REG_TM3CNT_L = 0xFDA7;
}

static void GetKeyInput(void)
{
    int rawKeys = REG_KEYINPUT ^ KEYS_MASK;
    sJoyNew = rawKeys & ~sJoyNewOrRepeated;
    sJoyNewOrRepeated = rawKeys;
}

void EReaderHelper_SaveRegsState(void)
{
    sSavedIme = REG_IME;
    sSavedIe = REG_IE;
    sSavedTm3Cnt = REG_TM3CNT_H;
    sSavedSioCnt = REG_SIOCNT;
    sSavedRCnt = REG_RCNT;
}

void EReaderHelper_RestoreRegsState(void)
{
    REG_IME = sSavedIme;
    REG_IE = sSavedIe;
    REG_TM3CNT_H = sSavedTm3Cnt;
    REG_SIOCNT = sSavedSioCnt;
    REG_RCNT = sSavedRCnt;
}

void EReaderHelper_ClearSendRecvMgr(void)
{
    CpuFill32(0, &sSendRecvMgr, sizeof(sSendRecvMgr));
}
