#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "librfu.h"
#include "link.h"
#include "link_rfu.h"
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
extern struct RfuGameData *sub_0800F29C(void);
extern void sub_08011554(u8 status, u16 errorInfo);
extern void sub_08010B58(bool8 startedActivity);
extern void sub_0800EB08(void);
extern void sub_08010CA0(bool32 enable);
extern void sub_0800F7A8(struct RfuBlockSend *data);

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

static void InitChildRecvBuffers(void);
static void InitParentSendData(void);
static void MSCCallback_Child(u16 REQ_commandID);
static void MSCCallback_Parent(u16 REQ_commandID);
static void Task_ParentSearchForChildren(u8 taskId);
static void Task_ChildSearchForParent(u8 taskId);
static void Task_UnionRoomListen(u8 taskId);

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
        sub_0800F7A8(&gRfu.recvBlock[i]);
    sub_0800F7A8(&gRfu.sendBlock);
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
    if (sub_0800F29C()->activity == (ACTIVITY_PLYRTALK | IN_UNION_ROOM) && RfuGetStatus() == RFU_STATUS_NEW_CHILD_DETECTED)
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
        sub_0800EB08();
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
