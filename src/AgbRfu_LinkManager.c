#include "global.h"
#include "librfu.h"
#include "link_rfu.h"

#define RN_ACCEPT           0x01
#define RN_NAME_TIMER_CLEAR 0x02
#define RN_DISCONNECT       0x04

#define LINK_RECOVERY_OFF        0x00
#define LINK_RECOVERY_START      0x01
#define LINK_RECOVERY_EXE        0x02
#define LINK_RECOVERY_IMPOSSIBLE 0x04

#define FSP_ON    0x01
#define FSP_START 0x02

// JP: these Link Manager functions are still in asm/link_rfu.s; they are
// referenced here until they are converted to C in later batches.
extern void sub_0800C96C(u16 REQ_commandID);
extern void sub_0800C270(u16 reqCommandId, u16 reqResult);
extern void sub_0800CDC8(u8 msg, u8 param_count);
extern void sub_0800CDF0(u8 bmDisconnectedSlot);
extern void sub_0800D0CC(void);

// JP: these are called from still-asm Link Manager functions, so unlike the
// US port they must remain externally visible.
void rfu_LMAN_clearVariables(void);
void rfu_LMAN_endManager(void);

u32 rfu_LMAN_REQBN_softReset_and_checkID(void)
{
    u32 id = rfu_REQBN_softReset_and_checkID();
    if (id == RFU_ID)
        lman.RFU_powerOn_flag = 1;
    if (lman.state != LMAN_FORCED_STOP_AND_RFU_RESET && lman.state != LMAN_STATE_SOFT_RESET_AND_CHECK_ID)
    {
        lman.state = lman.next_state = LMAN_STATE_READY;
    }
    lman.pcswitch_flag = 0;
    lman.reserveDisconnectSlot_flag = 0;
    lman.acceptCount = 0;
    lman.acceptSlot_flag = 0;
    lman.parent_child = MODE_NEUTRAL;
    sub_0800D0CC();
    return id;
}

void rfu_LMAN_REQ_sendData(bool8 clockChangeFlag)
{
    if (gRfuLinkStatus->parentChild == MODE_CHILD)
    {
        if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_ON)
            clockChangeFlag = TRUE;
        else
            clockChangeFlag = FALSE;
    }
    else
    {
        lman.parentAck_flag = 0;
    }
    rfu_REQ_sendData(clockChangeFlag);
}

u8 rfu_LMAN_initializeManager(void (*LMAN_callback_p)(u8, u8), void (*MSC_callback_p)(u16))
{
    if (LMAN_callback_p == NULL)
    {
        return LMAN_ERROR_ILLEGAL_PARAMETER;
    }
    CpuFill16(0, &lman, sizeof(struct linkManagerTag));
    lman.parent_child = MODE_NEUTRAL;
    lman.LMAN_callback = LMAN_callback_p;
    lman.MSC_callback = MSC_callback_p;
    rfu_setMSCCallback(sub_0800C96C);
    rfu_setREQCallback(sub_0800C270);
    return 0;
}

void rfu_LMAN_endManager(void)
{
    CpuFill16(0, &lman, sizeof(struct linkManagerTag) - 8);
    lman.parent_child = MODE_NEUTRAL;
}

void rfu_LMAN_initializeRFU(INIT_PARAM *init_parameters)
{
    rfu_LMAN_clearVariables();
    lman.state = LMAN_STATE_SOFT_RESET_AND_CHECK_ID;
    lman.next_state = LMAN_STATE_RESET;
    lman.init_param = init_parameters;
    lman.linkRecovery_enable = init_parameters->linkRecovery_enable;
    lman.linkRecoveryTimer.count_max = init_parameters->linkRecovery_period;
    lman.NI_failCounter_limit = init_parameters->NI_failCounter_limit;
    if (init_parameters->fastSearchParent_flag)
    {
        lman.fastSearchParent_flag = FSP_ON;
    }
}

void rfu_LMAN_clearVariables(void)
{
    u8 i;

    lman.state = lman.next_state = LMAN_STATE_READY;
    lman.parent_child = MODE_NEUTRAL;
    lman.pcswitch_flag = 0;
    lman.child_slot = 0;
    lman.connectSlot_flag_old = 0;
    lman.nameAcceptTimer.active = 0;
    lman.linkRecoveryTimer.active = 0;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        lman.nameAcceptTimer.count[i] = 0;
        lman.linkRecoveryTimer.count[i] = 0;
    }
}

void rfu_LMAN_powerDownRFU(void)
{
    lman.state = LMAN_STATE_STOP_MODE;
}

u8 rfu_LMAN_establishConnection(u8 parent_child, u16 connect_period, u16 name_accept_period, u16 *acceptable_serialNo_list)
{
    u8 i;
    u16 *serial_list;

    if (lman.state != LMAN_STATE_READY && (lman.state != LMAN_STATE_WAIT_RECV_CHILD_NAME || parent_child != MODE_PARENT))
    {
        lman.param[0] = 1;
        sub_0800CDC8(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_MANAGER_BUSY;
    }
    if (rfu_getMasterSlave() == AGB_CLK_SLAVE)
    {
        lman.param[0] = 2;
        sub_0800CDC8(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_AGB_CLK_SLAVE;
    }
    for (i = 0, serial_list = acceptable_serialNo_list; i < 16; i++)
    {
        if (*serial_list++ == 0xFFFF)
        {
            break;
        }
    }
    if (i == 16)
    {
        lman.param[0] = 4;
        sub_0800CDC8(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_ILLEGAL_PARAMETER;
    }
    if (parent_child > MODE_PARENT)
    {
        lman.pcswitch_flag = PCSWITCH_1ST_SC_START;
        parent_child = MODE_PARENT;
        connect_period = 0;
    }
    else
    {
        lman.pcswitch_flag = 0;
    }
    if (parent_child != MODE_CHILD)
    {
        lman.state = LMAN_STATE_START_SEARCH_CHILD;
    }
    else
    {
        lman.state = LMAN_STATE_START_SEARCH_PARENT;
        if (lman.fastSearchParent_flag)
        {
            lman.fastSearchParent_flag = FSP_START;
        }
    }
    lman.parent_child = parent_child;
    lman.connect_period = connect_period;
    lman.nameAcceptTimer.count_max = name_accept_period;
    lman.acceptable_serialNo_list = acceptable_serialNo_list;
    return 0;
}

u8 rfu_LMAN_CHILD_connectParent(u16 parentId, u16 connect_period)
{
    u8 i;

    if (lman.state != LMAN_STATE_READY && (lman.state < 9 || lman.state > 11))
    {
        lman.param[0] = 1;
        sub_0800CDC8(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_MANAGER_BUSY;
    }
    if (rfu_getMasterSlave() == AGB_CLK_SLAVE)
    {
        lman.param[0] = 2;
        sub_0800CDC8(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_AGB_CLK_SLAVE;
    }
    for (i = 0; i < gRfuLinkStatus->findParentCount; i++)
    {
        if (gRfuLinkStatus->partner[i].id == parentId)
        {
            break;
        }
    }
    if (gRfuLinkStatus->findParentCount == 0 || i == gRfuLinkStatus->findParentCount)
    {
        lman.param[0] = 3;
        sub_0800CDC8(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
        return LMAN_ERROR_PID_NOT_FOUND;
    }
    if (lman.state == LMAN_STATE_READY || lman.state == LMAN_STATE_START_SEARCH_PARENT)
    {
        lman.state = LMAN_STATE_START_CONNECT_PARENT;
        lman.next_state = LMAN_STATE_POLL_CONNECT_PARENT;
    }
    else
    {
        lman.state = LMAN_STATE_END_SEARCH_PARENT;
        lman.next_state = LMAN_STATE_START_CONNECT_PARENT;
    }
    lman.work = parentId;
    lman.connect_period = connect_period;
    if (lman.pcswitch_flag != 0)
    {
        lman.pcswitch_flag = PCSWITCH_CP;
    }
    return 0;
}

static void rfu_LMAN_PARENT_stopWaitLinkRecoveryAndDisconnect(u8 bm_targetSlot)
{
    u8 i;

    if ((bm_targetSlot & lman.linkRecoveryTimer.active) == 0)
        return;
    lman.linkRecoveryTimer.active &= ~bm_targetSlot;
    for (i = 0; i < RFU_CHILD_MAX; i++)
    {
        if ((bm_targetSlot >> i) & 1)
        {
            lman.linkRecoveryTimer.count[i] = 0;
        }
    }
    i = gRfuLinkStatus->linkLossSlotFlag & bm_targetSlot;
    if (i)
    {
        sub_0800CDF0(i);
    }
    lman.param[0] = i;
    sub_0800CDC8(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, i);
}

void rfu_LMAN_stopManager(u8 forced_stop_and_RFU_reset_flag)
{
    u8 msg = 0;

    lman.pcswitch_flag = 0;
    if (forced_stop_and_RFU_reset_flag)
    {
        rfu_LMAN_clearVariables();
        lman.state = LMAN_FORCED_STOP_AND_RFU_RESET;
        return;
    }
    switch (lman.state)
    {
    case LMAN_STATE_START_SEARCH_CHILD:
        lman.state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
        lman.next_state = LMAN_STATE_READY;
        msg = LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED;
        break;
    case LMAN_STATE_POLL_SEARCH_CHILD:
        lman.state = LMAN_STATE_END_SEARCH_CHILD;
        lman.next_state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
        break;
    case LMAN_STATE_END_SEARCH_CHILD:
        lman.state = LMAN_STATE_END_SEARCH_CHILD;
        lman.next_state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
        break;
    case LMAN_STATE_WAIT_RECV_CHILD_NAME:
        break;
    case LMAN_STATE_START_SEARCH_PARENT:
        lman.state = lman.next_state = LMAN_STATE_READY;
        msg = LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED;
        break;
    case LMAN_STATE_POLL_SEARCH_PARENT:
        lman.state = LMAN_STATE_END_SEARCH_PARENT;
        lman.next_state = LMAN_STATE_READY;
        break;
    case LMAN_STATE_END_SEARCH_PARENT:
        lman.state = LMAN_STATE_END_SEARCH_PARENT;
        lman.next_state = LMAN_STATE_READY;
        break;
    case LMAN_STATE_START_CONNECT_PARENT:
        lman.state = lman.next_state = LMAN_STATE_READY;
        msg = LMAN_MSG_CONNECT_PARENT_FAILED;
        break;
    case LMAN_STATE_POLL_CONNECT_PARENT:
        lman.state = LMAN_STATE_END_CONNECT_PARENT;
        break;
    case LMAN_STATE_END_CONNECT_PARENT:
        lman.state = LMAN_STATE_END_CONNECT_PARENT;
        break;
    case LMAN_STATE_SEND_CHILD_NAME:
        break;
    case LMAN_STATE_START_LINK_RECOVERY:
        lman.state = lman.state_bak[0];
        lman.next_state = lman.state_bak[1];
        sub_0800CDF0(gRfuLinkStatus->linkLossSlotFlag);
        lman.param[0] = gRfuLinkStatus->linkLossSlotFlag;
        sub_0800CDC8(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, 1);
        return;
    case LMAN_STATE_POLL_LINK_RECOVERY:
        lman.state = LMAN_STATE_END_LINK_RECOVERY;
        break;
    case LMAN_STATE_END_LINK_RECOVERY:
        lman.state = LMAN_STATE_END_LINK_RECOVERY;
        break;
    default:
        lman.state = lman.next_state = LMAN_STATE_READY;
        msg = LMAN_MSG_MANAGER_STOPPED;
        break;
    }
    if (lman.state == LMAN_STATE_READY)
    {
        sub_0800CDC8(msg, 0);
    }
}

// JP: still called from asm rfu_LMAN_manager_entity / rfu_LMAN_REQ_callback,
// so unlike US it stays non-static.
bool8 rfu_LMAN_linkWatcher(u16 REQ_commandID)
{
    u8 i;
    u8 bm_linkLossSlot;
    u8 reason;
    u8 bm_linkRecoverySlot;
    u8 bm_disconnectSlot;

    bool8 disconnect_occure_flag = FALSE;
    rfu_REQBN_watchLink(REQ_commandID, &bm_linkLossSlot, &reason, &bm_linkRecoverySlot);
    if (bm_linkLossSlot)
    {
        lman.param[0] = bm_linkLossSlot;
        lman.param[1] = reason;
        if (lman.linkRecovery_enable)
        {
            lman.linkRecovery_start_flag = LINK_RECOVERY_START;
            if (lman.parent_child == MODE_CHILD && reason == REASON_DISCONNECTED)
            {
                lman.linkRecovery_start_flag = LINK_RECOVERY_IMPOSSIBLE;
            }
            if (lman.linkRecovery_start_flag == LINK_RECOVERY_START)
            {
                for (i = 0; i < RFU_CHILD_MAX; i++)
                {
                    if ((bm_linkLossSlot >> i) & 1)
                    {
                        lman.linkRecoveryTimer.active |= (1 << i);
                        lman.linkRecoveryTimer.count[i] = lman.linkRecoveryTimer.count_max;
                    }
                }
                sub_0800CDC8(LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY, 1);
            }
            else
            {
                lman.linkRecovery_start_flag = 0;
                sub_0800CDF0(bm_linkLossSlot);
                disconnect_occure_flag = TRUE;
                sub_0800CDC8(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, 1);
            }
        }
        else
        {
            sub_0800CDF0(bm_linkLossSlot);
            disconnect_occure_flag = TRUE;
            sub_0800CDC8(LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED, 2);
        }
        sub_0800D0CC();
    }
    if (gRfuLinkStatus->parentChild == MODE_PARENT)
    {
        if (bm_linkRecoverySlot)
        {
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if ((lman.linkRecoveryTimer.active >> i) & 1 && (bm_linkRecoverySlot >> i) & 1)
                {
                    lman.linkRecoveryTimer.count[i] = 0;
                }
            }
            lman.linkRecoveryTimer.active &= ~bm_linkRecoverySlot;
            lman.param[0] = bm_linkRecoverySlot;
            sub_0800CDC8(LMAN_MSG_LINK_RECOVERY_SUCCESSED, 1);
        }
        if (lman.linkRecoveryTimer.active)
        {
            bm_disconnectSlot = 0;
            for (i = 0; i < RFU_CHILD_MAX; i++)
            {
                if ((lman.linkRecoveryTimer.active >> i) & 1 && lman.linkRecoveryTimer.count[i] && --lman.linkRecoveryTimer.count[i] == 0)
                {
                    lman.linkRecoveryTimer.active &= ~(1 << i);
                    bm_disconnectSlot |= (1 << i);
                }
            }
            if (bm_disconnectSlot)
            {
                sub_0800CDF0(bm_disconnectSlot);
                disconnect_occure_flag = TRUE;
                lman.param[0] = bm_disconnectSlot;
                sub_0800CDC8(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, 1);
            }
        }
        if (!lman.linkRecoveryTimer.active)
        {
            lman.linkRecovery_start_flag = 0;
        }
    }
    return disconnect_occure_flag;
}

void rfu_LMAN_syncVBlank(void)
{
    if (rfu_syncVBlank())
    {
        sub_0800CDC8(LMAN_MSG_WATCH_DOG_TIMER_ERROR, 0);
        sub_0800D0CC();
    }
}
