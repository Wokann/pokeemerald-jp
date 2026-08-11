#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "main.h"
#include "berry_blender.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
#include "overworld.h"
#include "random.h"
#include "palette.h"
#include "union_room.h"
#include "string_util.h"
#include "task.h"
#include "save.h"

enum {
    RFUSTATE_INIT,
    RFUSTATE_INIT_END,
    RFUSTATE_PARENT_CONNECT,
    RFUSTATE_PARENT_CONNECT_END,
    RFUSTATE_STOP_MANAGER,
    RFUSTATE_STOP_MANAGER_END,
    RFUSTATE_CHILD_CONNECT,
    RFUSTATE_CHILD_CONNECT_END,
    RFUSTATE_UNUSED,
    RFUSTATE_RECONNECTED,
    RFUSTATE_CONNECTED,
    RFUSTATE_CHILD_TRY_JOIN,
    RFUSTATE_CHILD_JOINED,
    RFUSTATE_UR_PLAYER_EXCHANGE,
    RFUSTATE_UR_STOP_MANAGER,
    RFUSTATE_UR_STOP_MANAGER_END,
    RFUSTATE_UR_FINALIZE,
};
// These states are used for different purposes
// depending on the link mode (parent, child, union room)
#define RFUSTATE_PARENT_FINALIZE_START 17
#define RFUSTATE_PARENT_FINALIZE       18
#define RFUSTATE_UR_CONNECT     17
#define RFUSTATE_UR_CONNECT_END 18
#define RFUSTATE_FINALIZED 20

// JP: RAM data bound via sym_*_jp.txt (JP uses fixed IWRAM/EWRAM addresses
// instead of US COMMON_DATA / EWRAM_DATA definitions).
extern COMMON_DATA u32 gRfuAPIBuffer[RFU_API_BUFF_SIZE_RAM / 4];
extern COMMON_DATA struct RfuManager gRfu;
extern EWRAM_DATA INIT_PARAM sRfuReqConfig;
extern EWRAM_DATA struct RfuDebug sRfuDebug;

// JP: ROM data bound via ld_script_jp.txt.
extern const INIT_PARAM sRfuReqConfigTemplate;
extern const u8 sPlayerBitsToNewChildIdx[];
extern const u16 sAcceptedSerialNos[];
extern const TaskFunc sShutdownTasks[3];

// JP: these helpers are still in asm/link_rfu.s; referenced by their sub_
// names until converted.
extern void sub_08010250(void);
extern s32 sub_080102A0(void);
extern void sub_08011D68(void);
extern void sub_0801034C(u8);
extern void sub_080107FC(u8);
extern void sub_08011554(u8 status, u16 errorInfo);
extern void sub_08010B58(bool8 startedActivity);
extern void sub_08010CA0(bool32 enable);
extern void sub_08011858(u32 slots);
extern void sub_08010028(void);
extern void sub_080105A4(u8 taskId);
extern bool32 sub_08011570(void);
extern void sub_080104E8(u16 selected);
extern void sub_08010568(void *recvBuffer);

// JP: IWRAM buffers bound via sym_iwram_jp.txt (US file-statics).
extern IWRAM_DATA u8 sResendBlock8[];
extern IWRAM_DATA u16 sResendBlock16[];
extern IWRAM_DATA u8 sHeldKeyCount;

// JP: assert strings bound via ld_script_jp.txt.
extern const char sAssertFile_rfu[];
extern const char sAssertExpr_RfuFuncNull[];
extern const char sAssertExpr_SizeLe252[];

// JP: ROM data bound via ld_script_jp.txt.
extern const u32 sAllBlocksReceived[];
extern const u8 sPlayerBitsToCount[];
extern const struct BlockRequest sBlockRequests[];

// Struct is mostly empty, presumably because usage of
// its fields was largely removed before release
struct RfuDebug
{
    u8 unused0[6];
    u16 recvCount;
    u8 unused1[6];
    vu8 unkFlag;
    u8 childJoinCount;
    u8 unused2[84];
    u16 blockSendFailures;
    u8 unused3[29];
    u8 blockSendTime;
    u8 unused4[88];
};

// States for the 'receiving' field of RfuBlockSend
enum {
    RECV_STATE_READY,
    RECV_STATE_RECEIVING,
    RECV_STATE_FINISHED,
};

static void InitChildRecvBuffers(void);
static void InitParentSendData(void);
static void MSCCallback_Child(u16 REQ_commandID);
static void MSCCallback_Parent(u16 REQ_commandID);
static void Task_ParentSearchForChildren(u8 taskId);
static void Task_ChildSearchForParent(u8 taskId);
static void Task_UnionRoomListen(u8 taskId);
static void ReadAllPlayerRecvCmds(void);
static void MoveSendCmdToRecv(void);
static void UpdateBackupQueue(void);
static void ChildBuildSendCmd(u16 *sendCmd, u8 *dst);
void HandleSendFailure(u8 unused, u32 flags);
bool32 RfuMain1_Parent(void);
bool32 RfuMain2_Parent(void);
bool32 RfuMain1_Child(void);
static void RfuHandleReceiveCommand(u8 unused);
static void ResetSendDataManager(struct RfuBlockSend *data);
bool8 AreAllPlayersReadyToReceive(void);
bool8 AreAllPlayersFinishedReceiving(void);
void RfuPrepareSendBuffer(u16 command);
static void HandleBlockSend(void);
static void SendNextBlock(void);
static void SendLastBlock(void);
static void RfuShutdownAfterDisconnect(void);
static void DisconnectRfu(void);
void TryDisconnectRfu(void);
void CreateTask_ParentSearchForChildren(void);
void CreateTask_ChildSearchForParent(void);
bool8 CanTryReconnectParent(void);
bool32 TryReconnectParent(void);

void nullsub_13(void)
{
}

void nullsub_5(void)
{
}

void ResetLinkRfuGFLayer(void)
{
    s32 i;
    u8 errorState = gRfu.errorState;
    CpuFill16(0, &gRfu, sizeof(gRfu));
    gRfu.errorState = errorState;
    gRfu.parentChild = 0xFF;
    if (gRfu.errorState != RFU_ERROR_STATE_IGNORE)
        gRfu.errorState = RFU_ERROR_STATE_NONE;
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        ResetSendDataManager(&gRfu.recvBlock[i]);
    ResetSendDataManager(&gRfu.sendBlock);
    RfuRecvQueue_Reset(&gRfu.recvQueue);
    RfuSendQueue_Reset(&gRfu.sendQueue);
    CpuFill16(0, gSendCmd, sizeof gSendCmd);
    CpuFill16(0, gRecvCmds, sizeof gRecvCmds);
    CpuFill16(0, gLinkPlayers, sizeof gLinkPlayers);
}

void InitRFU(void)
{
    IntrFunc serialIntr = gIntrTable[1];
    IntrFunc timerIntr = gIntrTable[2];
    InitRFUAPI();
    rfu_REQ_stopMode();
    rfu_waitREQComplete();
    REG_IME = 0;
    gIntrTable[1] = serialIntr;
    gIntrTable[2] = timerIntr;
    REG_IME = INTR_FLAG_VBLANK;
}

void InitRFUAPI(void)
{
    if (!rfu_initializeAPI((void *)gRfuAPIBuffer, sizeof(gRfuAPIBuffer), &gIntrTable[1], TRUE))
    {
        gLinkType = 0;
        ClearSavedLinkPlayers();
        sub_08010CA0(FALSE);
        ResetLinkRfuGFLayer();
        rfu_setTimerInterrupt(3, &gIntrTable[2]);
    }
}

static void Task_ParentSearchForChildren(u8 taskId)
{
    sub_08010250();
    switch (gRfu.state)
    {
    case RFUSTATE_INIT:
        rfu_LMAN_initializeRFU(&sRfuReqConfig);
        gRfu.state = RFUSTATE_INIT_END;
        gTasks[taskId].data[1] = 1;
        break;
    case RFUSTATE_INIT_END:
        break;
    case RFUSTATE_PARENT_CONNECT:
        rfu_LMAN_establishConnection(gRfu.parentChild, 0, 240, (u16 *)sAcceptedSerialNos);
        gRfu.state = RFUSTATE_PARENT_CONNECT_END;
        gTasks[taskId].data[1] = 6;
        break;
    case RFUSTATE_PARENT_CONNECT_END:
        break;
    case RFUSTATE_STOP_MANAGER:
        rfu_LMAN_stopManager(FALSE);
        gRfu.state = RFUSTATE_STOP_MANAGER_END;
        break;
    case RFUSTATE_STOP_MANAGER_END:
        break;
    case RFUSTATE_PARENT_FINALIZE:
        gRfu.parentFinished = FALSE;
        rfu_LMAN_setMSCCallback(MSCCallback_Parent);
        InitChildRecvBuffers();
        InitParentSendData();
        gRfu.state = RFUSTATE_FINALIZED;
        gTasks[taskId].data[1] = 8;
        CreateTask(sub_0801034C, 5);
        DestroyTask(taskId);
        break;
    }
}

s32 Rfu_GetIndexOfNewestChild(u8 bits)
{
    return sPlayerBitsToNewChildIdx[bits];
}

// JP: still called from asm/link_rfu.s, so it stays externally visible.
void SetLinkPlayerIdsFromSlots(s32 baseSlots, s32 addSlots)
{
    u8 i;
    u8 baseId = 1;
    s32 baseSlotsCopy = baseSlots;
    s32 newId = 0;
    if (addSlots == -1)
    {
        // Initialize
        for (i = 0; i < RFU_CHILD_MAX; baseSlots >>= 1, i++)
        {
            if (baseSlots & 1)
            {
                gRfu.linkPlayerIdx[i] = baseId;
                baseId++;
            }
        }
    }
    else
    {
        // Clear id for any empty slot
        for (i = 0; i < RFU_CHILD_MAX; baseSlotsCopy >>= 1, i++)
        {
            if (!(baseSlotsCopy & 1))
                gRfu.linkPlayerIdx[i] = 0;
        }

        // Get starting id by checking existing slots
        for (baseId = RFU_CHILD_MAX; baseId != 0; baseId--)
        {
            for (i = 0; i < RFU_CHILD_MAX && gRfu.linkPlayerIdx[i] != baseId; i++)
                ;
            if (i == RFU_CHILD_MAX)
                newId = baseId;
        }

        // Set id for new slots
        for (addSlots &= ~baseSlots, i = 0; i < RFU_CHILD_MAX; addSlots >>= 1, i++)
        {
            if (addSlots & 1)
                gRfu.linkPlayerIdx[i] = newId++;
        }
    }
}

static void Task_ChildSearchForParent(u8 taskId)
{
    switch (gRfu.state)
    {
    case RFUSTATE_INIT:
        rfu_LMAN_initializeRFU((INIT_PARAM *)&sRfuReqConfigTemplate);
        gRfu.state = RFUSTATE_INIT_END;
        gTasks[taskId].data[1] = 1;
        break;
    case RFUSTATE_INIT_END:
        break;
    case RFUSTATE_CHILD_CONNECT:
        rfu_LMAN_establishConnection(gRfu.parentChild, 0, 240, (u16 *)sAcceptedSerialNos);
        gRfu.state = RFUSTATE_CHILD_CONNECT_END;
        gTasks[taskId].data[1] = 7;
        break;
    case RFUSTATE_CHILD_CONNECT_END:
        break;
    case RFUSTATE_RECONNECTED:
        gTasks[taskId].data[1] = 10;
        break;
    case RFUSTATE_CHILD_TRY_JOIN:
        switch (sub_080102A0())
        {
        case RFU_STATUS_JOIN_GROUP_OK:
            gRfu.state = RFUSTATE_CHILD_JOINED;
            break;
        case RFU_STATUS_JOIN_GROUP_NO:
        case RFU_STATUS_LEAVE_GROUP:
            rfu_LMAN_requestChangeAgbClockMaster();
            gRfu.disconnectMode = RFU_DISCONNECT_NORMAL;
            DestroyTask(taskId);
            break;
        }
        break;
    case RFUSTATE_CHILD_JOINED:
    {
        u8 bmChildSlot = 1 << gRfu.childSlot;
        rfu_clearSlot(TYPE_NI_SEND | TYPE_NI_RECV, gRfu.childSlot);
        rfu_setRecvBuffer(TYPE_UNI, gRfu.childSlot, gRfu.childRecvQueue, sizeof(gRfu.childRecvQueue));
        rfu_UNI_setSendData(bmChildSlot, gRfu.childSendBuffer,  sizeof(gRfu.childSendBuffer));
        gTasks[taskId].data[1] = 8;
        DestroyTask(taskId);
        if (sRfuDebug.childJoinCount == 0)
        {
            sub_08011D68();
            sRfuDebug.childJoinCount++;
        }
        CreateTask(sub_0801034C, 5);
        break;
    }
    }
}

static void InitChildRecvBuffers(void)
{
    u8 i;
    u8 acceptSlot = lman.acceptSlot_flag;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (acceptSlot & 1)
        {
            rfu_setRecvBuffer(TYPE_UNI, i, gRfu.childRecvBuffer[i], sizeof(gRfu.childRecvBuffer[0]));
            rfu_clearSlot(TYPE_UNI_SEND | TYPE_UNI_RECV, i);
        }
        acceptSlot >>= 1;
    }
}

static void InitParentSendData(void)
{
    u8 acceptSlot = lman.acceptSlot_flag;
    rfu_UNI_setSendData(acceptSlot, gRfu.recvCmds, sizeof(gRfu.recvCmds));
    gRfu.parentSendSlot = Rfu_GetIndexOfNewestChild(acceptSlot);
    gRfu.parentSlots = acceptSlot;
    SetLinkPlayerIdsFromSlots(acceptSlot, -1);
    gRfu.parentChild = MODE_PARENT;
}

#define tConnectingForChat data[7]

static void Task_UnionRoomListen(u8 taskId)
{
    if (GetHostRfuGameData()->activity == (ACTIVITY_PLYRTALK | IN_UNION_ROOM) && RfuGetStatus() == RFU_STATUS_NEW_CHILD_DETECTED)
    {
        rfu_REQ_disconnect(lman.acceptSlot_flag);
        rfu_waitREQComplete();
        sub_08011554(RFU_STATUS_OK, 0);
    }
    switch (gRfu.state)
    {
    case RFUSTATE_INIT:
        rfu_LMAN_initializeRFU(&sRfuReqConfig);
        gRfu.state = RFUSTATE_INIT_END;
        gTasks[taskId].data[1] = 1;
        break;
    case RFUSTATE_INIT_END:
        break;
    case RFUSTATE_UR_CONNECT:
        rfu_LMAN_establishConnection(MODE_P_C_SWITCH, 0, 240, (u16 *)sAcceptedSerialNos);
        rfu_LMAN_setMSCCallback(MSCCallback_Child);
        gRfu.state = RFUSTATE_UR_CONNECT_END;
        break;
    case RFUSTATE_UR_CONNECT_END:
        break;
    case RFUSTATE_UR_PLAYER_EXCHANGE:
        if (rfu_UNI_setSendData(1 << gRfu.childSlot, gRfu.childSendBuffer, sizeof(gRfu.childSendBuffer)) == 0)
        {
            gRfu.parentChild = MODE_CHILD;
            DestroyTask(taskId);
            if (gTasks[taskId].tConnectingForChat)
                CreateTask(sub_080107FC, 1);
            else
                CreateTask(sub_0801034C, 5);
        }
        break;
    case RFUSTATE_UR_STOP_MANAGER:
        rfu_LMAN_stopManager(FALSE);
        gRfu.state = RFUSTATE_UR_STOP_MANAGER_END;
        break;
    case RFUSTATE_UR_STOP_MANAGER_END:
        break;
    case RFUSTATE_UR_FINALIZE:
        gRfu.parentFinished = FALSE;
        rfu_LMAN_setMSCCallback(MSCCallback_Parent);
        sub_08010B58(TRUE);
        InitChildRecvBuffers();
        InitParentSendData();
        gRfu.state = RFUSTATE_FINALIZED;
        gTasks[taskId].data[1] = 8;
        gRfu.parentChild = MODE_PARENT;
        CreateTask(sub_0801034C, 5);
        gRfu.playerExchangeActive = TRUE;
        DestroyTask(taskId);
        break;
    }
}

#undef tConnectingForChat

void LinkRfu_CreateConnectionAsParent(void)
{
    rfu_LMAN_establishConnection(MODE_PARENT, 0, 240, (u16 *)sAcceptedSerialNos);
}

void LinkRfu_StopManagerBeforeEnteringChat(void)
{
    rfu_LMAN_stopManager(FALSE);
}

// Argument is provided by the RFU and is unused.
static void MSCCallback_Child(u16 REQ_commandID)
{
    s32 i;

    for (i = 0; i < COMM_SLOT_LENGTH; i++)
        gRfu.childSendBuffer[i] = 0;

    rfu_REQ_recvData();
    rfu_waitREQComplete();
    if (gRfuSlotStatusUNI[gRfu.childSlot]->recv.newDataFlag)
    {
        gRfu.childSendCount++;
        RfuRecvQueue_Enqueue(&gRfu.recvQueue, gRfu.childRecvQueue);
        sRfuDebug.recvCount++;
        UpdateBackupQueue();
        rfu_UNI_readySendData(gRfu.childSlot);
        rfu_UNI_clearRecvNewDataFlag(gRfu.childSlot);
    }
    rfu_LMAN_REQ_sendData(TRUE);
}

// Argument is provided by the RFU and is unused.
static void MSCCallback_Parent(u16 REQ_commandID)
{
    gRfu.parentFinished = TRUE;
}

void LinkRfu_Shutdown(void)
{
    u8 i;

    rfu_LMAN_powerDownRFU();
    if (gRfu.parentChild == MODE_PARENT)
    {
        // Stop parent searching for children
        if (FuncIsActiveTask(Task_ParentSearchForChildren) == TRUE)
        {
            DestroyTask(gRfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }
    else if (gRfu.parentChild == MODE_CHILD)
    {
        // Stop child searching for parent
        if (FuncIsActiveTask(Task_ChildSearchForParent) == TRUE)
        {
            DestroyTask(gRfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }
    else if (gRfu.parentChild == MODE_P_C_SWITCH)
    {
        // Stop parent-child switching mode (union room)
        if (FuncIsActiveTask(Task_UnionRoomListen) == TRUE)
        {
            DestroyTask(gRfu.searchTaskId);
            ResetLinkRfuGFLayer();
        }
    }

    // Destroy additional tasks
    for (i = 0; i < ARRAY_COUNT(sShutdownTasks); i++)
    {
        if (FuncIsActiveTask(sShutdownTasks[i]) == TRUE)
            DestroyTask(FindTaskIdByFunc(sShutdownTasks[i]));
    }
}

// JP: still called from asm, so these stay externally visible.
void CreateTask_ParentSearchForChildren(void)
{
    gRfu.searchTaskId = CreateTask(Task_ParentSearchForChildren, 1);
}

// If no parent ID (or if child connection not ready) can't reconnect with parent yet
bool8 CanTryReconnectParent(void)
{
    if (gRfu.state == RFUSTATE_CHILD_CONNECT_END && gRfu.parentId)
        return TRUE;
    return FALSE;
}

bool32 TryReconnectParent(void)
{
    if (gRfu.state == RFUSTATE_CHILD_CONNECT_END && !rfu_LMAN_CHILD_connectParent(gRfuLinkStatus->partner[gRfu.reconnectParentId].id, 240))
    {
        gRfu.state = RFUSTATE_RECONNECTED;
        return TRUE;
    }
    return FALSE;
}

void CreateTask_ChildSearchForParent(void)
{
    gRfu.searchTaskId = CreateTask(Task_ChildSearchForParent, 1);
}

bool8 LmanAcceptSlotFlagIsNotZero(void)
{
    if (lman.acceptSlot_flag)
        return TRUE;
    return FALSE;
}

void LinkRfu_StopManagerAndFinalizeSlots(void)
{
    gRfu.state = RFUSTATE_STOP_MANAGER;
    // JP: stores into gRfu.acceptSlot_flag (US stores into linkLossRecoveryState).
    gRfu.acceptSlot_flag = lman.acceptSlot_flag;
}

bool32 WaitRfuState(bool32 force)
{
    // JP: checks RFUSTATE_UR_CONNECT and advances to RFUSTATE_UR_CONNECT_END
    // (US checks UR_CONNECT_END and advances to RFUSTATE_FINALIZED).
    if (gRfu.state == RFUSTATE_UR_CONNECT || force)
    {
        gRfu.state = RFUSTATE_UR_CONNECT_END;
        return TRUE;
    }
    return FALSE;
}

void StopUnionRoomLinkManager(void)
{
    gRfu.state = RFUSTATE_UR_STOP_MANAGER;
}

static void UNUSED ReadySendDataForSlots(u8 slots)
{
    u8 i;

    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if (slots & 1)
        {
            rfu_UNI_readySendData(i);
            break;
        }
        slots >>= 1;
    }
}

static void ReadAllPlayerRecvCmds(void)
{
    s32 i, j;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        struct RfuManager *rfu = &gRfu;
        for (j = 0; j < CMD_LENGTH - 1; j++)
        {
            rfu->recvCmds[i][j][1] = gRecvCmds[i][j] >> 8;
            rfu->recvCmds[i][j][0] = gRecvCmds[i][j];
        }
    }
    CpuFill16(0, gRecvCmds, sizeof gRecvCmds);
}

static void MoveSendCmdToRecv(void)
{
    s32 i;
    for (i = 0; i < CMD_LENGTH - 1; i++)
        gRecvCmds[0][i] = gSendCmd[i];

    for (i = 0; i < CMD_LENGTH - 1; i++)
        gSendCmd[i] = 0;
}

static void UpdateBackupQueue(void)
{
    if (gRfu.linkRecovered)
    {
        bool8 backupEmpty = RfuBackupQueue_Dequeue(&gRfu.backupQueue, gRfu.childSendBuffer);

        if (gRfu.backupQueue.count == 0)
            gRfu.linkRecovered = FALSE;

        if (backupEmpty)
            return;
    }
    if (!gRfu.linkRecovered)
    {
        RfuSendQueue_Dequeue(&gRfu.sendQueue, gRfu.childSendBuffer);
        RfuBackupQueue_Enqueue(&gRfu.backupQueue, gRfu.childSendBuffer);
    }
}

bool32 IsRfuRecvQueueEmpty(void)
{
    s32 i;
    s32 j;

    if (!gRfuLinkStatus->sendSlotUNIFlag)
        return FALSE;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        for (j = 0; j < CMD_LENGTH - 1; j++)
            if (gRecvCmds[i][j] != 0)
                return FALSE;

    return TRUE;
}

bool32 RfuMain1_Parent(void)
{
    if (gRfu.state < RFUSTATE_FINALIZED)
    {
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        rfu_LMAN_REQ_sendData(FALSE);
    }
    else
    {
        gRfu.parentFinished = FALSE;
        if ((gRfu.parentSlots & gRfuLinkStatus->connSlotFlag) == gRfu.parentSlots && (gRfu.parentSlots & gRfuLinkStatus->connSlotFlag))
        {
            if (!gRfu.parentMain2Failed)
            {
                if (gRfu.disconnectSlots)
                {
                    sub_08011858(gRfu.disconnectSlots);
                    gRfu.disconnectSlots = 0;
                    if (gRfu.disconnectMode == RFU_DISCONNECT_ERROR)
                    {
                        sub_08011554(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_8);
                        RfuSetErrorParams(F_RFU_ERROR_8);
                        return FALSE;
                    }
                    if (!lman.acceptSlot_flag)
                    {
                        LinkRfu_Shutdown();
                        gReceivedRemoteLinkPlayers = 0;
                        return FALSE;
                    }
                }
                ReadAllPlayerRecvCmds();
                rfu_UNI_readySendData(gRfu.parentSendSlot);
                rfu_LMAN_REQ_sendData(TRUE);
            }
            else
            {
                rfu_REQ_PARENT_resumeRetransmitAndChange();
            }
            gRfu.runParentMain2 = TRUE;
        }
    }
    return FALSE;
}

bool32 RfuMain2_Parent(void)
{
    u16 i;
    u16 flags;
    u8 r0;
    u16 j;
    bool8 failed;

    if (gRfu.state >= RFUSTATE_FINALIZED && gRfu.runParentMain2 == TRUE)
    {
        rfu_waitREQComplete();
        while (gRfu.parentFinished == FALSE)
        {
            if (gRfu.errorState != RFU_ERROR_STATE_NONE)
                return FALSE;
        }
        rfu_REQ_recvData();
        rfu_waitREQComplete();
        if ((lman.parentAck_flag & gRfu.parentSlots) == gRfu.parentSlots)
        {
            gRfu.parentMain2Failed = FALSE;
            sRfuDebug.recvCount++;
            flags = lman.acceptSlot_flag;
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if (flags & 1)
                {
                    if (gRfu.childRecvBuffer[i][1])
                    {
                        if (gRfu.childRecvIds[i] != 0xFF && (gRfu.childRecvBuffer[i][0] >> 5) != ((gRfu.childRecvIds[i] + 1) & 7))
                        {
                            if (++gRfu.numChildRecvErrors[i] > 4)
                                RfuSetErrorParams(F_RFU_ERROR_8 | F_RFU_ERROR_1);
                        }
                        else
                        {
                            gRfu.childRecvIds[i] = gRfu.childRecvBuffer[i][0] / 32;
                            gRfu.numChildRecvErrors[i] = 0;
                            gRfu.childRecvBuffer[i][0] &= 0x1f;
                            r0 = gRfu.linkPlayerIdx[i];
                            for (j = 0; j < CMD_LENGTH - 1; j++)
                            {
                                gRecvCmds[r0][j] = (gRfu.childRecvBuffer[i][(j << 1) + 1] << 8) | gRfu.childRecvBuffer[i][(j << 1) + 0];
                                gRfu.childRecvBuffer[i][(j << 1) + 1] = 0;
                                gRfu.childRecvBuffer[i][(j << 1) + 0] = 0;
                            }
                        }
                    }
                    rfu_UNI_clearRecvNewDataFlag(i);
                }
                flags >>= 1;
            }
            MoveSendCmdToRecv();
            RfuHandleReceiveCommand(0);
            sub_08010028();
            if (gRfu.nextChildBits && !gRfu.stopNewConnections)
            {
                sRfuDebug.unkFlag = FALSE;
                rfu_clearSlot(TYPE_UNI_SEND | TYPE_UNI_RECV, gRfu.parentSendSlot);
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((gRfu.nextChildBits >> i) & 1)
                        rfu_setRecvBuffer(TYPE_UNI, i, gRfu.childRecvBuffer[i], sizeof(gRfu.childRecvBuffer[0]));
                }
                SetLinkPlayerIdsFromSlots(gRfu.parentSlots, gRfu.parentSlots | gRfu.nextChildBits);
                gRfu.incomingChild = gRfu.nextChildBits;
                gRfu.parentSlots |= gRfu.nextChildBits;
                gRfu.nextChildBits = 0;
                rfu_UNI_setSendData(gRfu.parentSlots, gRfu.recvCmds, sizeof(gRfu.recvCmds));
                gRfu.parentSendSlot = Rfu_GetIndexOfNewestChild(gRfu.parentSlots);
                CreateTask(sub_080105A4, 0);
            }
        }
        else
        {
            gRfu.parentMain2Failed = TRUE;
            gRfu.runParentMain2 = FALSE;
        }
        gRfu.runParentMain2 = FALSE;
    }
    failed = gRfu.parentMain2Failed;
    return gRfuLinkStatus->sendSlotUNIFlag ? failed & 1 : FALSE;
}

static void ChildBuildSendCmd(u16 *sendCmd, u8 *dst)
{
    s32 i;

    if (sendCmd[0])
    {
        sendCmd[0] |= (gRfu.childSendCmdId << 5);
        gRfu.childSendCmdId = (gRfu.childSendCmdId + 1) & 7;
        for (i = 0; i < CMD_LENGTH - 1; i++)
        {
            dst[2 * i + 1] = sendCmd[i] >> 8;
            dst[2 * i + 0] = sendCmd[i];
        }
    }
    else
    {
        for (i = 0; i < COMM_SLOT_LENGTH; i++)
            dst[i] = 0;
    }
}

bool32 RfuMain1_Child(void)
{
    u8 i;
    u8 j;
    u8 recv[MAX_RFU_PLAYERS * (2 * (CMD_LENGTH - 1))];
    u8 send[2 * (CMD_LENGTH - 1)];
    u8 status;

    RfuRecvQueue_Dequeue(&gRfu.recvQueue, recv);
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        for (j = 0; j < CMD_LENGTH - 1; j++)
            gRecvCmds[i][j] = (recv[i * COMM_SLOT_LENGTH + (j * 2) + 1] << 8)
                             | recv[i * COMM_SLOT_LENGTH + (j * 2) + 0];
    }
    RfuHandleReceiveCommand(0);
    if (lman.childClockSlave_flag == 0 && gRfu.disconnectMode != RFU_DISCONNECT_NONE)
    {
        rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
        rfu_waitREQComplete();
        status = RfuGetStatus();
        if (status != RFU_STATUS_FATAL_ERROR && status != RFU_STATUS_JOIN_GROUP_NO && status != RFU_STATUS_LEAVE_GROUP)
            sub_08011554(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_8);
        rfu_clearAllSlot();
        gReceivedRemoteLinkPlayers = FALSE;
        gRfu.callback = NULL;
        if (gRfu.disconnectMode == RFU_DISCONNECT_ERROR)
        {
            sub_08011554(RFU_STATUS_CONNECTION_ERROR, F_RFU_ERROR_5 | F_RFU_ERROR_8);
            RfuSetErrorParams(F_RFU_ERROR_5 | F_RFU_ERROR_8);
        }
        lman.state = lman.next_state = 0;
        gRfu.disconnectMode = RFU_DISCONNECT_NONE;
    }
    if (gRfu.childSendCount)
    {
        gRfu.childSendCount--;
        sub_08010028();
        ChildBuildSendCmd(gSendCmd, send);
        RfuSendQueue_Enqueue(&gRfu.sendQueue, send);
        for (i = 0; i < CMD_LENGTH - 1; i++)
            gSendCmd[i] = 0;
    }
    return IsRfuRecvQueueEmpty();
}

void HandleSendFailure(u8 unused, u32 flags)
{
    s32 i, j, temp;

    const u8 *payload = gRfu.sendBlock.payload;
    for (i = 0; i < gRfu.sendBlock.count; i++)
    {
        if (!(flags & 1))
        {
            sResendBlock16[0] = RFUCMD_SEND_BLOCK | i;
            for (j = 0; j < CMD_LENGTH - 1; j++)
            {
                temp = j * 2;
                sResendBlock16[j + 1] = (payload[(COMM_SLOT_LENGTH - 2) * i + temp + 1] << 8)
                                       | payload[(COMM_SLOT_LENGTH - 2) * i + temp + 0];
            }
            for (j = 0; j < CMD_LENGTH - 1; j++)
            {
                temp = j * 2;
                sResendBlock8[temp + 1] = sResendBlock16[j] >> 8;
                sResendBlock8[temp + 0] = sResendBlock16[j];
            }
            RfuSendQueue_Enqueue(&gRfu.sendQueue, sResendBlock8);
            gRfu.sendBlock.failedFlags |= (1 << i);
        }
        flags >>= 1;
    }
}

// JP: unlike US, also sets numBlocksReceived when parent and id nonzero.
void Rfu_SetBlockReceivedFlag(u8 linkPlayerId)
{
    if (gRfu.parentChild == MODE_PARENT && linkPlayerId)
        gRfu.numBlocksReceived[linkPlayerId] = TRUE;
    else
        gRfu.blockReceived[linkPlayerId] = TRUE;
}

// JP: unlike US, also clears recvBlock[linkPlayerId].receiving.
void Rfu_ResetBlockReceivedFlag(u8 linkPlayerId)
{
    gRfu.blockReceived[linkPlayerId] = FALSE;
    gRfu.recvBlock[linkPlayerId].receiving = FALSE;
}

// JP: still called from asm, so it stays externally visible.
u8 LoadLinkPlayerIds(const u8 *ids)
{
    u8 i;
    if (gRfu.parentChild == MODE_PARENT)
        return FALSE;
    for (i = 0; i < RFU_CHILD_MAX; i++)
        gRfu.linkPlayerIdx[i] = ids[i];

    return ids[gRfu.childSlot];
}

static void SendKeysToRfu(void)
{
    if (gReceivedRemoteLinkPlayers
        && gHeldKeyCodeToSend != LINK_KEY_CODE_NULL
        && gLinkTransferringData != TRUE)
    {
        sHeldKeyCount++;
        gHeldKeyCodeToSend |= (sHeldKeyCount << 8);
        RfuPrepareSendBuffer(RFUCMD_SEND_HELD_KEYS);
    }
}

struct RfuGameData *GetHostRfuGameData(void)
{
    return &gHostRfuGameData;
}

bool32 IsSendingKeysToRfu(void)
{
    return gRfu.callback == SendKeysToRfu;
}

// JP: has an assert (US does not).
void StartSendingKeysToRfu(void)
{
    if (gRfu.callback != NULL)
    {
        AGBAssert(sAssertFile_rfu, 0x5E6, sAssertExpr_RfuFuncNull, 1);
    }
    gRfu.callback = SendKeysToRfu;
}

void ClearLinkRfuCallback(void)
{
    gRfu.callback = NULL;
}

static void Rfu_BerryBlenderSendHeldKeys(void)
{
    RfuPrepareSendBuffer(RFUCMD_BLENDER_SEND_KEYS);
    if (GetMultiplayerId() == 0)
        gSendCmd[BLENDER_COMM_ARROW_POS] = GetBlenderArrowPosition();
    gBerryBlenderKeySendAttempts++;
}

void Rfu_SetBerryBlenderLinkCallback(void)
{
    if (gRfu.callback == NULL)
        gRfu.callback = Rfu_BerryBlenderSendHeldKeys;
}

static void RfuHandleReceiveCommand(u8 unused)
{
    u16 i;
    u16 j;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        switch (gRecvCmds[i][0] & RFUCMD_MASK)
        {
        case RFUCMD_SEND_PLAYER_IDS_NEW:
            if (gRfu.parentChild == MODE_CHILD && gReceivedRemoteLinkPlayers)
                return;
            // fallthrough
        case RFUCMD_SEND_PLAYER_IDS:
            if (gRfuLinkStatus->parentChild == MODE_CHILD)
            {
                gRfu.playerCount = gRecvCmds[i][1];
                gRfu.multiplayerId = LoadLinkPlayerIds((u8 *)(gRecvCmds[i] + 2));
            }
            break;
        case RFUCMD_SEND_BLOCK_INIT:
            if (gRfu.recvBlock[i].receiving == RECV_STATE_READY)
            {
                gRfu.recvBlock[i].next = 0;
                gRfu.recvBlock[i].count = gRecvCmds[i][1];
                gRfu.recvBlock[i].owner = gRecvCmds[i][2];
                gRfu.recvBlock[i].receivedFlags = 0;
                gRfu.recvBlock[i].receiving = RECV_STATE_RECEIVING;
                gRfu.blockReceived[i] = FALSE;
            }
            break;
        case RFUCMD_SEND_BLOCK:
            if (gRfu.recvBlock[i].receiving == RECV_STATE_RECEIVING)
            {
                gRfu.recvBlock[i].next = gRecvCmds[i][0] & 0xff;
                gRfu.recvBlock[i].receivedFlags |= (1 << gRfu.recvBlock[i].next);
                for (j = 0; j < 6; j++)
                    gBlockRecvBuffer[i][gRfu.recvBlock[i].next * 6 + j] = gRecvCmds[i][j + 1];
                if (gRfu.recvBlock[i].receivedFlags == sAllBlocksReceived[gRfu.recvBlock[i].count])
                {
                    gRfu.recvBlock[i].receiving = RECV_STATE_FINISHED;
                    Rfu_SetBlockReceivedFlag(i);
                    if (GetHostRfuGameData()->activity == (ACTIVITY_CHAT | IN_UNION_ROOM) && gReceivedRemoteLinkPlayers && gRfu.parentChild == MODE_CHILD)
                        sub_08010568(gBlockRecvBuffer);
                }
            }
            break;
        case RFUCMD_SEND_BLOCK_REQ:
            Rfu_InitBlockSend(sBlockRequests[gRecvCmds[i][1]].address, (u16)sBlockRequests[gRecvCmds[i][1]].size);
            break;
        case RFUCMD_READY_CLOSE_LINK:
            gRfu.readyCloseLink[i] = TRUE;
            break;
        case RFUCMD_READY_EXIT_STANDBY:
            if (gRfu.allReadyNum == gRecvCmds[i][1])
                gRfu.readyExitStandby[i] = TRUE;
            break;
        case RFUCMD_DISCONNECT:
            if (gRfu.parentChild == MODE_CHILD)
            {
                // Disconnect child
                if (gReceivedRemoteLinkPlayers)
                {
                    if (gRecvCmds[i][1] & gRfuLinkStatus->connSlotFlag)
                    {
                        gReceivedRemoteLinkPlayers = 0;
                        rfu_LMAN_requestChangeAgbClockMaster();
                        gRfu.disconnectMode = gRecvCmds[i][2];
                    }
                    gRfu.playerCount = gRecvCmds[i][3];
                    sub_080104E8(gRecvCmds[i][1]);
                }
            }
            else
            {
                // Disconnect parent
                RfuPrepareSendBuffer(RFUCMD_DISCONNECT_PARENT);
                gSendCmd[1] = gRecvCmds[i][1];
                gSendCmd[2] = gRecvCmds[i][2];
                gSendCmd[3] = gRecvCmds[i][3];
            }
            break;
        case RFUCMD_DISCONNECT_PARENT:
            if (gRfu.parentChild == MODE_PARENT)
            {
                gRfu.disconnectSlots |= gRecvCmds[i][1];
                gRfu.disconnectMode = gRecvCmds[i][2];
                sub_080104E8(gRecvCmds[i][1]);
            }
            break;
        case RFUCMD_BLENDER_SEND_KEYS:
        case RFUCMD_SEND_HELD_KEYS:
            gLinkPartnersHeldKeys[i] = gRecvCmds[i][1];
            break;
        }
        if (gRfu.parentChild == MODE_PARENT && gRfu.numBlocksReceived[i])
        {
            if (gRfu.numBlocksReceived[i] == 4)
            {
                gRfu.blockReceived[i] = TRUE;
                gRfu.numBlocksReceived[i] = 0;
            }
            else
            {
                gRfu.numBlocksReceived[i]++;
            }
        }
    }
}

// JP: still called from asm, so these stay externally visible.
bool8 AreAllPlayersReadyToReceive(void)
{
    s32 i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (gRfu.recvBlock[i].receiving != RECV_STATE_READY)
            return FALSE;
    }
    return TRUE;
}

bool8 AreAllPlayersFinishedReceiving(void)
{
    s32 i;

    for (i = 0; i < gRfu.playerCount; i++)
    {
        if (gRfu.recvBlock[i].receiving != RECV_STATE_FINISHED || gRfu.blockReceived[i] != TRUE)
            return FALSE;
    }
    return TRUE;
}

static void ResetSendDataManager(struct RfuBlockSend *data)
{
    data->next = 0;
    data->count = 0;
    data->payload = NULL;
    data->receivedFlags = 0;
    data->sending = FALSE;
    data->owner = 0;
    data->receiving = RECV_STATE_READY;
}

u8 Rfu_GetBlockReceivedStatus(void)
{
    u8 flags = 0;
    s32 i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (gRfu.recvBlock[i].receiving == RECV_STATE_FINISHED && gRfu.blockReceived[i] == TRUE)
            flags |= (1 << i);
    }
    return flags;
}

void RfuPrepareSendBuffer(u16 command)
{
    u8 i;
    u8 *buff;
    u8 tmp;

    gSendCmd[0] = command;
    switch (command)
    {
    case RFUCMD_SEND_BLOCK_INIT:
        gSendCmd[1] = gRfu.sendBlock.count;
        gSendCmd[2] = gRfu.sendBlock.owner + 0x80;
        break;
    case RFUCMD_SEND_BLOCK_REQ:
        if (AreAllPlayersReadyToReceive())
            gSendCmd[1] = gRfu.blockRequestType;
        break;
    case RFUCMD_SEND_PLAYER_IDS:
    case RFUCMD_SEND_PLAYER_IDS_NEW:
        tmp = gRfu.parentSlots ^ gRfu.disconnectSlots;
        gRfu.playerCount = sPlayerBitsToCount[tmp] + 1;
        gSendCmd[1] = gRfu.playerCount;
        buff = (u8 *)&gSendCmd[2];
        for (i = 0; i < RFU_CHILD_MAX; i++)
            buff[i] = gRfu.linkPlayerIdx[i];
        break;
    case RFUCMD_READY_EXIT_STANDBY:
    case RFUCMD_READY_CLOSE_LINK:
        gSendCmd[1] = gRfu.allReadyNum;
        break;
    case RFUCMD_BLENDER_SEND_KEYS:
        gSendCmd[0] = command;
        gSendCmd[1] = gMain.heldKeys;
        break;
    case RFUCMD_SEND_PACKET:
        for (i = 0; i < RFU_PACKET_SIZE; i++)
            gSendCmd[1 + i] = gRfu.packet[i];
        break;
    case RFUCMD_SEND_HELD_KEYS:
        gSendCmd[1] = gHeldKeyCodeToSend;
        break;
    case RFUCMD_DISCONNECT_PARENT:
    case RFUCMD_DISCONNECT:
        break;
    }
}

void Rfu_SendPacket(void *data)
{
    if (gSendCmd[0] == 0 && !sub_08011570())
    {
        memcpy(gRfu.packet, data, sizeof(gRfu.packet));
        RfuPrepareSendBuffer(RFUCMD_SEND_PACKET);
    }
}

bool32 Rfu_InitBlockSend(const u8 *src, size_t size)
{
    bool8 r4;
    // JP: has an assert (US does not).
    if (size > 252)
        AGBAssert(sAssertFile_rfu, 0x755, sAssertExpr_SizeLe252, 1);
    if (gRfu.callback != NULL)
        return FALSE;
    if (gSendCmd[0] != 0)
        return FALSE;
    if (gRfu.sendBlock.sending)
    {
        sRfuDebug.blockSendTime++;
        return FALSE;
    }
    r4 = (size % 12) != 0;
    gRfu.sendBlock.owner = GetMultiplayerId();
    gRfu.sendBlock.sending = TRUE;
    gRfu.sendBlock.count = (size / 12) + r4;
    gRfu.sendBlock.next = 0;
    if (size > BLOCK_BUFFER_SIZE)
    {
        gRfu.sendBlock.payload = src;
    }
    else
    {
        if (src != gBlockSendBuffer)
            memcpy(gBlockSendBuffer, src, size);
        gRfu.sendBlock.payload = gBlockSendBuffer;
    }
    RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_INIT);
    gRfu.callback = HandleBlockSend;
    gRfu.blockSendAttempts = 0;
    return TRUE;
}

static void HandleBlockSend(void)
{
    if (gSendCmd[0] == 0)
    {
        RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_INIT);
        if (gRfu.parentChild == MODE_PARENT)
        {
            if (++gRfu.blockSendAttempts > 2)
                gRfu.callback = SendNextBlock;
        }
        else
        {
            if ((gRecvCmds[GetMultiplayerId()][0] & RFUCMD_MASK) == RFUCMD_SEND_BLOCK_INIT)
                gRfu.callback = SendNextBlock;
        }
    }
}

static void SendNextBlock(void)
{
    s32 i;
    const u8 *src = gRfu.sendBlock.payload;
    gSendCmd[0] = RFUCMD_SEND_BLOCK | gRfu.sendBlock.next;
    for (i = 0; i < CMD_LENGTH - 1; i++)
        gSendCmd[i + 1] = (src[(i << 1) + gRfu.sendBlock.next * 12 + 1] << 8) | src[(i << 1) + gRfu.sendBlock.next * 12 + 0];
    gRfu.sendBlock.next++;
    if (gRfu.sendBlock.count <= gRfu.sendBlock.next)
    {
        gRfu.sendBlock.sending = FALSE;
        gRfu.callback = SendLastBlock;
    }
}

static void SendLastBlock(void)
{
    const u8 *src = gRfu.sendBlock.payload;
    u8 mpId = GetMultiplayerId();
    s32 i;
    if (gRfu.parentChild == MODE_CHILD)
    {
        gSendCmd[0] = RFUCMD_SEND_BLOCK | (gRfu.sendBlock.count - 1);
        for (i = 0; i < CMD_LENGTH - 1; i++)
            gSendCmd[i + 1] = (src[(i << 1) + (gRfu.sendBlock.count - 1) * 12 + 1] << 8) | src[(i << 1) + (gRfu.sendBlock.count - 1) * 12 + 0];
        if ((u8)gRecvCmds[mpId][0] == gRfu.sendBlock.count - 1)
        {
            if (gRfu.recvBlock[mpId].receivedFlags != sAllBlocksReceived[gRfu.recvBlock[mpId].count])
            {
                HandleSendFailure(mpId, gRfu.recvBlock[mpId].receivedFlags);
                sRfuDebug.blockSendFailures++;
            }
            else
            {
                gRfu.callback = NULL;
            }
        }
    }
    else
    {
        gRfu.callback = NULL;
    }
}

bool8 Rfu_SendBlockRequest(u8 type)
{
    gRfu.blockRequestType = type;
    RfuPrepareSendBuffer(RFUCMD_SEND_BLOCK_REQ);
    return TRUE;
}

static void RfuShutdownAfterDisconnect(void)
{
    rfu_clearAllSlot();
    rfu_LMAN_powerDownRFU();
    gReceivedRemoteLinkPlayers = 0;
    gRfu.isShuttingDown = TRUE;
    gRfu.callback = NULL;
}

static void DisconnectRfu(void)
{
    rfu_REQ_disconnect(gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag);
    rfu_waitREQComplete();
    RfuShutdownAfterDisconnect();
}

void TryDisconnectRfu(void)
{
    if (gRfu.parentChild == MODE_CHILD)
    {
        rfu_LMAN_requestChangeAgbClockMaster();
        gRfu.disconnectMode = RFU_DISCONNECT_NORMAL;
    }
    else
    {
        gRfu.callback = DisconnectRfu;
    }
}

void LinkRfu_FatalError(void)
{
    rfu_LMAN_requestChangeAgbClockMaster();
    gRfu.disconnectMode = RFU_DISCONNECT_ERROR;
    gRfu.disconnectSlots = gRfuLinkStatus->connSlotFlag | gRfuLinkStatus->linkLossSlotFlag;
}
