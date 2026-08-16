#ifndef GUARD_EREADER_HELPERS_H
#define GUARD_EREADER_HELPERS_H

#include "trainer_hill.h"

enum {
    EREADER_XFR_STATE_INIT = 0,
    EREADER_XFR_STATE_HANDSHAKE,
    EREADER_XFR_STATE_START,
    EREADER_XFR_STATE_TRANSFER,
    EREADER_XFR_STATE_TRANSFER_DONE,
    EREADER_XFR_STATE_CHECKSUM,
    EREADER_XFR_STATE_DONE
};

#define EREADER_XFER_EXE 1
#define EREADER_XFER_CHK 2
#define EREADER_XFER_SHIFT 0
#define EREADER_XFER_MASK  ((EREADER_XFER_EXE | EREADER_XFER_CHK) << EREADER_XFER_SHIFT)

#define EREADER_CANCEL_TIMEOUT 1
#define EREADER_CANCEL_KEY     2
#define EREADER_CANCEL_SHIFT 2
#define EREADER_CANCEL_TIMEOUT_MASK (EREADER_CANCEL_TIMEOUT << EREADER_CANCEL_SHIFT)
#define EREADER_CANCEL_KEY_MASK     (EREADER_CANCEL_KEY << EREADER_CANCEL_SHIFT)
#define EREADER_CANCEL_MASK         ((EREADER_CANCEL_TIMEOUT | EREADER_CANCEL_KEY) << EREADER_CANCEL_SHIFT)

#define EREADER_CHECKSUM_OK  1
#define EREADER_CHECKSUM_ERR 2
#define EREADER_CHECKSUM_SHIFT 4
#define EREADER_CHECKSUM_OK_MASK (EREADER_CHECKSUM_OK << EREADER_CHECKSUM_SHIFT)
#define EREADER_CHECKSUM_MASK    ((EREADER_CHECKSUM_OK | EREADER_CHECKSUM_ERR) << EREADER_CHECKSUM_SHIFT)

struct EReaderTrainerHillTrainer
{
    u8 trainerNum;
    u8 pad[3];
    struct TrainerHillTrainer trainer;
    u8 mapMetatileData[HILL_FLOOR_WIDTH * HILL_FLOOR_HEIGHT_MAIN];
    u16 mapCollisionData[HILL_FLOOR_WIDTH];
    u8 mapTrainerCoords[HILL_TRAINERS_PER_FLOOR];
    u8 mapTrainerDirections;
    u8 mapTrainerRanges;
    u32 checksum;
}; // size = 0x270 (JP e-reader layout: checksum at 0x26C, no trainerCoords)

struct EReaderTrainerHillSet
{
    u8 numTrainers;
    u8 id;
    u16 dummy; // Only read in an assert.
    u32 checksum;
    struct EReaderTrainerHillTrainer trainers[6];
    u8 unk[0x20];
}; // size = 0xEC8 (JP layout: 6 trainers * 0x270 + 0x20 trailer)

bool8 ValidateTrainerHillData(struct EReaderTrainerHillSet *hillSet);
bool32 TryWriteTrainerHill(struct EReaderTrainerHillSet *hillSet);
bool32 ReadTrainerHillAndValidate(void);
int EReaderHandleTransfer(u8 mode, size_t size, const void *data, void *recvBuffer);
void EReaderHelper_Timer3Callback(void);
void EReaderHelper_SerialCallback(void);
void EReaderHelper_SaveRegsState(void);
void EReaderHelper_RestoreRegsState(void);
void EReaderHelper_ClearSendRecvMgr(void);

#endif // GUARD_EREADER_HELPERS_H
