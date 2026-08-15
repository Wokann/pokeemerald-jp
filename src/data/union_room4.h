#include "global.h"
#include "link_rfu.h"

// Wireless link texts and the link-dropped table
ALIGNED(4) const u8 sText_WirelessLinkEstablished[] = _(
    "ジョイスポットとの　せつぞくに\n"
    "せいこう　しました！");

ALIGNED(4) const u8 sText_WirelessLinkDropped[] = _(
    "ジョイスポットから　せつぞくを\n"
    "せつだん　されました⋯");

ALIGNED(4) const u8 sText_LinkWithFriendDropped[] = _(
    "おともだちとの　つうしんが\n"
    "せつだん　されました⋯");

ALIGNED(4) const u8 sText_PlayerRepliedNo2[] = _(
    "{B_COPY_VAR_1}から　NGとの\n"
    "へんじが　きてしまいました⋯");

const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK] = NULL,
    [RFU_STATUS_FATAL_ERROR] = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR] = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED] = NULL,
    [RFU_STATUS_JOIN_GROUP_OK] = NULL,
    [RFU_STATUS_JOIN_GROUP_NO] = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE] = NULL,
    [RFU_STATUS_LEAVE_GROUP] = NULL,
};

