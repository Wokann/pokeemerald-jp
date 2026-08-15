#include "global.h"
#include "link_rfu.h"

// Union-room member-status texts and pointer tables
ALIGNED(4) const u8 sText_AnOKWasSentToPlayer[] = _(
    "{B_COPY_VAR_1}に　OKの\n"
    "へんじを　だしました");

ALIGNED(4) const u8 sText_OtherTrainerUnavailableNow[] = _(
    "あいての\n"
    "つごうが　わるいみたい⋯\p");

ALIGNED(4) const u8 sText_CantTransmitTrainerTooFar[] = _(
    "まだ　とおくの　かたとは\n"
    "つうしんは　できません\p");

ALIGNED(4) const u8 sText_TrainersNotReadyYet[] = _(
    "あいての　じゅんびが\n"
    "できていません\p");

const u8 *const sCantTransmitToTrainerTexts[] = {
    sText_CantTransmitTrainerTooFar,
    sText_TrainersNotReadyYet,
};

ALIGNED(4) const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _(
    "この　メンバーで　{B_COPY_VAR_1}を\n"
    "するのは　やめます{PAUSE 60}");

ALIGNED(4) const u8 sText_MemberNoLongerAvailable[] = _(
    "つごうが　わるくなってしまった\n"
    "メンバーが　います\p");

const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable,
};

ALIGNED(4) const u8 sText_TrainerAppearsUnavailable[] = _("つごうが　わるいみたい⋯\p");

ALIGNED(4) const u8 sText_PlayerSentBackOK[] = _(
    "{B_COPY_VAR_1}から　OKとの\n"
    "へんじが　ありました！");

ALIGNED(4) const u8 sText_PlayerOKdRegistration[] = _(
    "{B_COPY_VAR_1}から　メンバー　とうろく\n"
    "OKとの　れんらくが　きました！");

ALIGNED(4) const u8 sText_PlayerRepliedNo[] = _(
    "{B_COPY_VAR_1}から　NGとの\n"
    "へんじが　きてしまいました⋯\p");

ALIGNED(4) const u8 sText_AwaitingOtherMembers[] = _(
    "{B_COPY_VAR_1}！\n"
    "ほかの　メンバーを　まっています！");

ALIGNED(4) const u8 sText_QuitBeingMember[] = _("メンバーから　ぬけますか？");

ALIGNED(4) const u8 sText_StoppedBeingMember[] = _("メンバーから　ぬけました\p");

const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK] = NULL,
    [RFU_STATUS_FATAL_ERROR] = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR] = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED] = NULL,
    [RFU_STATUS_JOIN_GROUP_OK] = NULL,
    [RFU_STATUS_JOIN_GROUP_NO] = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE] = NULL,
    [RFU_STATUS_LEAVE_GROUP] = sText_StoppedBeingMember,
};

