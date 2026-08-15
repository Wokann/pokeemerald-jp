#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate src/data/union_room.c/h for the union-room text region.

The region in data/data_b.s at 0x82C053C..0x82C06B8 contains the RFU
assert/debug ASCII strings and the first union-room texts.  Every symbol
is decoded from baserom_jp.gba with the EXT_CTRL_CODE rules from
src/text.c (tools/decode_jp_text.py), then emitted as a C array.  The
generated file is round-trip checked by re-encoding through preproc and
comparing byte-for-byte with the ROM.
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import decode_jp_text as d  # noqa: E402


ROM = (ROOT / "baserom_jp.gba").read_bytes()

# (name, addr, kind) for the clean sub-region.  kind is 'ascii', 'text' or
# 'gap'.  ASCII strings are emitted as char arrays; text as _() strings.
SYMBOLS = [
    ("sAssertFile_rfu", 0x082C053C, "ascii_fixed", "rfu.c", 8),
    ("sAssertExpr_RfuFuncNull", 0x082C0544, "ascii_fixed", "Rfu.RfuFunc == NULL", 20),
    ("sAssertExpr_SizeLe252", 0x082C0558, "ascii_fixed", "size<=252", 12),
    ("sASCII_PokemonSioInfo", 0x082C0564, "ascii_fixed", "PokemonSioInfo", 15),
    ("sJPText_Akito", 0x082C0574, "text", None),
    ("sASCII_LinkLossDisconnect", 0x082C0578, "ascii", "LINK LOSS DISCONNECT!"),
    ("sASCII_LinkLossRecoveryNow", 0x082C0590, "ascii_aligned", "LINK LOSS RECOVERY NOW"),
    ("sASCII_30Spaces", 0x082C05A8, "ascii_aligned", " " * 30),
    ("sASCII_15Spaces", 0x082C05C7, "ascii", " " * 15),
    ("sASCII_8Spaces", 0x082C05D7, "ascii", " " * 8),
    ("sASCII_Space", 0x082C05E0, "ascii", " "),
    ("sASCII_Asterisk", 0x082C05E2, "ascii", "*"),
    ("sASCII_NowSlot", 0x082C05E4, "ascii", "NOWSLOT"),
    ("sASCII_ClockCmds", 0x082C05EC, "clock_cmds", None),
    ("sASCII_ChildParentSearch", 0x082C0628, "child_search", None),
    ("sUnknown_82C0640", 0x082C0640, "gap", bytes([0xFF, 0x00, 0x00, 0x00])),
    ("sText_Colon", 0x082C0644, "text", None),
    ("sText_ID", 0x082C0648, "text", None),
    ("sText_PleaseStartOver", 0x082C064C, "text", None),
    ("sText_WirelessSearchCanceled", 0x082C066C, "text", None),
    ("sText_AwaitingCommunication", 0x082C069C, "text_fixed", None),
]

END_ADDR = 0x082C06B8  # sText_AwaitingLinkPressStart (next region)

# Second batch: six simple union-room texts (no embedded tables).
SYMBOLS2 = [
    ("sText_BButtonCancel", 0x082C08A4, "text", None),
    ("sText_PlayerContactedYouForXAccept", 0x082C08C4, "text", None),
    ("sText_PlayerContactedYouShareX", 0x082C08DC, "text", None),
    ("sText_PlayerContactedYouAddToMembers", 0x082C08F8, "text", None),
    ("sText_AreTheseMembersOK", 0x082C0914, "text", None),
    ("sText_CancelModeWithTheseMembers", 0x082C092C, "text_fixed", None),
]

END_ADDR2 = 0x082C0948  # sText_AnOKWasSentToPlayer (next region)

# Third batch: AnOK/member-status texts and their pointer tables.
# Sub-text boundaries come from the pointer-table targets in the ROM.
SYMBOLS3 = [
    ("sText_AnOKWasSentToPlayer", 0x082C0948, "text", None),
    ("sText_OtherTrainerUnavailableNow", 0x082C095C, "text", None),
    ("sText_CantTransmitTrainerTooFar", 0x082C0970, "text", None),
    ("sText_TrainersNotReadyYet", 0x082C098C, "text", None),
    ("sCantTransmitToTrainerTexts", 0x082C09A0, "table", ["sText_CantTransmitTrainerTooFar", "sText_TrainersNotReadyYet"]),
    ("sText_ModeWithTheseMembersWillBeCanceled", 0x082C09A8, "text", None),
    ("sText_MemberNoLongerAvailable", 0x082C09C4, "text", None),
    ("sPlayerUnavailableTexts", 0x082C09E0, "table", ["sText_OtherTrainerUnavailableNow", "sText_MemberNoLongerAvailable"]),
    ("sText_TrainerAppearsUnavailable", 0x082C09E8, "text", None),
    ("sText_PlayerSentBackOK", 0x082C09F8, "text", None),
    ("sText_PlayerOKdRegistration", 0x082C0A10, "text", None),
    ("sText_PlayerRepliedNo", 0x082C0A30, "text", None),
    ("sText_AwaitingOtherMembers", 0x082C0A4C, "text", None),
    ("sText_QuitBeingMember", 0x082C0A64, "text", None),
    ("sText_StoppedBeingMember", 0x082C0A74, "text", None),
    ("sPlayerDisconnectedTexts", 0x082C0A84, "table_rfu", None),
]

END_ADDR3 = 0x082C0AAC  # sText_WirelessLinkEstablished (next region)

# Fourth batch: wireless link texts and the link-dropped table.
SYMBOLS4 = [
    ("sText_WirelessLinkEstablished", 0x082C0AAC, "text", None),
    ("sText_WirelessLinkDropped", 0x082C0AC8, "text", None),
    ("sText_LinkWithFriendDropped", 0x082C0AE4, "text", None),
    ("sText_PlayerRepliedNo2", 0x082C0B00, "text", None),
    ("sLinkDroppedTexts", 0x082C0B1C, "table_link", None),
]

END_ADDR4 = 0x082C0B44  # unlabeled trade-request texts (next region)

# Fifth batch: trade-request/communicating texts and their tables.
SYMBOLS5 = [
    ("sText_DoYouWantXMode", 0x082C0B44, "text", None),
    ("sText_DoYouWantXMode2", 0x082C0B50, "text", None),
    ("sDoYouWantModeTexts", 0x082C0B5C, "table", ["sText_DoYouWantXMode", "sText_DoYouWantXMode2"]),
    ("sText_CommunicatingPleaseWait", 0x082C0B64, "text", None),
    ("sText_AwaitingPlayersResponseAboutTrade", 0x082C0B80, "text", None),
    ("sText_Communicating", 0x082C0B9C, "text", None),
    ("sText_CommunicatingWithPlayer", 0x082C0C04, "text", None),
    ("sText_PleaseWaitAWhile", 0x082C0C68, "text", None),
    ("sCommunicatingWaitTexts", 0x082C0CD8, "table",
        ["sText_Communicating", "sText_CommunicatingWithPlayer", "sText_PleaseWaitAWhile"]),
]

END_ADDR5 = 0x082C0CE4  # sHiDoSomethingTexts area (next region)

# Sixth batch: hi/do-something/contacted/awaiting texts and tables.
SYMBOLS6 = [
    ("sText_HiDoSomethingMale", 0x082C0CE4, "text", None),
    ("sText_HiDoSomethingFemale", 0x082C0CF4, "text", None),
    ("sText_HiDoSomethingAgainMale", 0x082C0D04, "text", None),
    ("sText_HiDoSomethingAgainFemale", 0x082C0D20, "text", None),
    ("sHiDoSomethingTexts", 0x082C0D3C, "table",
        ["sText_HiDoSomethingMale", "sText_HiDoSomethingFemale",
         "sText_HiDoSomethingAgainMale", "sText_HiDoSomethingAgainFemale"]),
    ("sText_DoSomethingMale", 0x082C0D4C, "text", None),
    ("sText_DoSomethingFemale", 0x082C0D58, "text", None),
    ("sText_DoSomethingAgainMale", 0x082C0D60, "text", None),
    ("sText_DoSomethingAgainFemale", 0x082C0D70, "text", None),
    ("sDoSomethingTexts", 0x082C0D80, "table",
        ["sText_DoSomethingMale", "sText_DoSomethingFemale",
         "sText_DoSomethingAgainMale", "sText_DoSomethingAgainMale"]),
    ("sText_SomebodyHasContactedYou", 0x082C0D90, "text", None),
    ("sText_PlayerHasContactedYou", 0x082C0DA4, "text", None),
    ("sPlayerContactedYouTexts", 0x082C0DB8, "table",
        ["sText_SomebodyHasContactedYou", "sText_PlayerHasContactedYou"]),
    ("sText_AwaitingResponseFromTrainer", 0x082C0DC0, "text", None),
    ("sText_AwaitingResponseFromPlayer", 0x082C0DD4, "text", None),
    ("sAwaitingResponseTexts", 0x082C0DE4, "table",
        ["sText_AwaitingResponseFromTrainer", "sText_AwaitingResponseFromPlayer"]),
]

END_ADDR6 = 0x082C0DEC  # sText_ShowTrainerCard (next region)

# Seventh batch: invitation/chat texts and their tables.
SYMBOLS7 = [
    ("sText_ShowTrainerCard", 0x082C0DEC, "text", None),
    ("sText_BattleChallenge", 0x082C0E1C, "text", None),
    ("sText_ChatInvitation", 0x082C0E40, "text", None),
    ("sText_OfferToTradeMon", 0x082C0E68, "text", None),
    ("sText_OfferToTradeEgg", 0x082C0EA8, "text", None),
    ("sText_ChatDropped", 0x082C0ED4, "text", None),
    ("sText_OfferDeclined1", 0x082C0EE0, "text", None),
    ("sText_OfferDeclined2", 0x082C0EF4, "text", None),
    ("sText_ChatEnded", 0x082C0F04, "text", None),
    ("sInvitationTexts", 0x082C0F10, "table",
        ["sText_ShowTrainerCard", "sText_BattleChallenge",
         "sText_ChatInvitation", "sText_OfferToTradeMon"]),
    ("sText_JoinChatMale", 0x082C0F20, "text", None),
    ("sText_JoinChatFemale", 0x082C0F4C, "text", None),
    ("sText_PlayerJoinChatMale", 0x082C0F78, "text", None),
    ("sText_PlayerJoinChatFemale", 0x082C0FA4, "text", None),
    ("sJoinChatTexts", 0x082C0FD0, "table",
        ["sText_JoinChatMale", "sText_PlayerJoinChatMale",
         "sText_JoinChatFemale", "sText_PlayerJoinChatFemale"]),
    ("sText_TrainerAppearsBusy", 0x082C0FE0, "text_fixed", None),
]

END_ADDR7 = 0x082C0FF8  # gUnknown_82C0FF8 (next region)

# Eighth batch: wait-for-battle/chat and show-card texts.
SYMBOLS8 = [
    ("sText_WaitForBattleMale", 0x082C0FF8, "text", None),
    ("sText_WaitForChatMale", 0x082C1010, "text", None),
    ("sText_ShowTrainerCardMale", 0x082C1028, "text", None),
    ("sText_WaitForBattleFemale", 0x082C1050, "text", None),
    ("sText_WaitForChatFemale", 0x082C1068, "text", None),
    ("sText_ShowTrainerCardFemale", 0x082C1080, "text", None),
    ("sText_WaitOrShowCardTexts", 0x082C10A4, "table_2x4", None),
]

END_ADDR8 = 0x082C10C4  # gUnknown_82C10C4 (next region)

# Eighth batch part 2: start-activity and battle-declined texts.
SYMBOLS8B = [
    ("sText_WaitForChatMale2", 0x082C10C4, "text", None),
    ("sText_DoneWaitingBattleMale", 0x082C10DC, "text", None),
    ("sText_DoneWaitingChatMale", 0x082C10F8, "text", None),
    ("sText_DoneWaitingBattleFemale", 0x082C1114, "text", None),
    ("sText_DoneWaitingChatFemale", 0x082C112C, "text", None),
    ("sText_TradeWillBeStarted", 0x082C114C, "text", None),
    ("sText_BattleWillBeStarted", 0x082C1160, "text", None),
    ("sText_EnteringChat", 0x082C1174, "text", None),
    ("sStartActivityTexts", 0x082C1188, "table_start_activity", None),
    ("sText_BattleDeclinedMale", 0x082C11B8, "text", None),
    ("sText_BattleDeclinedFemale", 0x082C11EC, "text", None),
    ("sBattleDeclinedTexts", 0x082C1224, "table",
        ["sText_BattleDeclinedMale", "sText_BattleDeclinedFemale"]),
    ("sText_ShowTrainerCardDeclinedMale", 0x082C122C, "text", None),
    ("sText_ShowTrainerCardDeclinedFemale", 0x082C1254, "text", None),
    ("sShowTrainerCardDeclinedTexts", 0x082C127C, "table",
        ["sText_ShowTrainerCardDeclinedMale", "sText_ShowTrainerCardDeclinedFemale"]),
    ("sText_IfYouWantToDoSomethingMale", 0x082C1284, "text", None),
    ("sText_IfYouWantToDoSomethingFemale", 0x082C12A0, "text", None),
    ("sIfYouWantToDoSomethingTexts", 0x082C12BC, "table",
        ["sText_IfYouWantToDoSomethingMale", "sText_IfYouWantToDoSomethingFemale"]),
]

END_ADDR8B = 0x082C12C4  # sText_TrainerBattleBusy (next region)

# Eighth batch part 3: battle-busy, level-requirement and reaction texts.
SYMBOLS8C = [
    ("sText_TrainerBattleBusy", 0x082C12C4, "text", None),
    ("sText_NeedTwoMonsOfLevel30OrLower1", 0x082C12E4, "text", None),
    ("sText_NeedTwoMonsOfLevel30OrLower2", 0x082C1310, "text", None),
    ("sText_DeclineChatMale", 0x082C133C, "text", None),
    ("stext_DeclineChatFemale", 0x082C1350, "text", None),
    ("sDeclineChatTexts", 0x082C1364, "table",
        ["sText_DeclineChatMale", "stext_DeclineChatFemale"]),
    ("sText_ChatDeclinedMale", 0x082C136C, "text", None),
    ("sText_ChatDeclinedFemale", 0x082C1398, "text", None),
    ("sChatDeclinedTexts", 0x082C13C4, "table",
        ["sText_ChatDeclinedMale", "sText_ChatDeclinedFemale"]),
    ("sText_YoureToughMale", 0x082C13CC, "text", None),
    ("sText_UsedGoodMoveMale", 0x082C13E0, "text", None),
    ("sText_BattleSurpriseMale", 0x082C13FC, "text", None),
    ("sText_SwitchedMonsMale", 0x082C1418, "text", None),
    ("sText_YoureToughFemale", 0x082C1434, "text", None),
    ("sText_UsedGoodMoveFemale", 0x082C1450, "text", None),
    ("sText_BattleSurpriseFemale", 0x082C1464, "text", None),
    ("sText_SwitchedMonsFemale", 0x082C147C, "text", None),
    ("sBattleReactionTexts", 0x082C1498, "table_2x4_battle", None),
]

END_ADDR8C = 0x082C14B8  # chat reaction texts (next region)

# Eighth batch part 4: chat/trainer-card/trade reaction texts.
SYMBOLS8D = [
    ("sText_LearnedSomethingMale", 0x082C14B8, "text", None),
    ("sText_ThatsFunnyMale", 0x082C14C8, "text", None),
    ("sText_RandomChatMale1", 0x082C14E4, "text", None),
    ("sText_RandomChatMale2", 0x082C14F8, "text", None),
    ("sText_LearnedSomethingFemale", 0x082C1518, "text", None),
    ("sText_ThatsFunnyFemale", 0x082C1530, "text", None),
    ("sText_RandomChatFemale1", 0x082C153C, "text", None),
    ("sText_RandomChatFemale2", 0x082C1550, "text", None),
    ("sChatReactionTexts", 0x082C1564, "table_chat", None),
    ("sText_ShowedTrainerCardMale1", 0x082C1584, "text", None),
    ("sText_ShowedTrainerCardMale2", 0x082C15A4, "text", None),
    ("sText_ShowedTrainerCardFemale1", 0x082C15B4, "text", None),
    ("sText_ShowedTrainerCardFemale2", 0x082C15D8, "text", None),
    ("sTrainerCardReactionTexts", 0x082C15E8, "table_2x2", None),
    ("sText_MaleTraded1", 0x082C15F8, "text", None),
    ("sText_MaleTraded2", 0x082C1610, "text", None),
    ("sText_FemaleTraded1", 0x082C1630, "text", None),
    ("sText_FemaleTraded2", 0x082C1648, "text", None),
    ("sTradeReactionTexts", 0x082C1668, "table_trade", None),
]

END_ADDR8D = 0x082C1688  # sText_XCheckedTradingBoard (next region)


def next_addr(addr, symbols, end_addr):
    for sym in symbols:
        if sym[1] > addr:
            return sym[1]
    return end_addr


def region_bytes(addr, end):
    off = addr & 0xFFFFFF
    return ROM[off : off + (end - addr)]


def emit_ascii(name, content, aligned=False, size=None):
    a = "ALIGNED(4) " if aligned else ""
    s = f"[{size}]" if size else "[]"
    # Brace initializers keep agbcc from emitting .align 2 before every
    # array (packed layout like the ROM); plain strings would be aligned.
    return f'{a}const char {name}{s} = {{"{content}"}};'


def emit_text(name, addr, end, size=None):
    data = region_bytes(addr, end)
    # Decode the raw ROM bytes, then truncate at the last $ terminator.
    # Everything after it is alignment padding; the trailing $ itself is
    # reproduced by preproc's automatic terminator (which appends 0xFF).
    text = decode_preproc(data)
    last = text.rfind("$")
    if last >= 0:
        text = text[:last]
    lines = text.split("\\n")
    s = f"[{size}]" if size else "[]"
    if len(lines) == 1:
        return f'ALIGNED(4) const u8 {name}{s} = _("{text}");'
    body = "\n".join('    "%s\\n"' % ln for ln in lines[:-1]) + "\n" + '    "%s"' % lines[-1]
    return f"ALIGNED(4) const u8 {name}{s} = _(\n{body});"


def decode_preproc(data):
    """Decode JP text bytes into preproc-compatible _() content.

    EXT_CTRL_CODE arguments are rendered as decimal numbers ("{COLOR 1}",
    "{PAUSE 60}", "{PLAY_BGM 240 0}") which preproc re-encodes to the same
    bytes; multi-byte macros keep their {NAME} form.
    """
    single, multi = d.build_maps()
    max_len = max((len(k) for k in multi), default=1)
    out = []
    i = 0
    while i < len(data):
        b = data[i]
        if b == 0xFC:
            if i + 1 < len(data):
                code = data[i + 1]
                name = d.CTRL_NAMES.get(code, "CTRL_%02X" % code)
                nargs = d.CTRL_ARGS.get(code, 0)
                args = data[i + 2 : i + 2 + nargs]
                if code in (0x0B, 0x10):  # PLAY_BGM / PLAY_SE: u16 lo, hi
                    argtext = " %d %d" % (args[0], args[1]) if len(args) >= 2 else ""
                elif args:
                    argtext = " " + " ".join(str(a) for a in args)
                else:
                    argtext = ""
                out.append("{%s%s}" % (name, argtext))
                i += 2 + nargs
            else:
                out.append("[FC]")
                i += 1
            continue
        if b == 0xFF:
            out.append("$")
            i += 1
            continue
        if b == 0xFE:
            out.append("\\n")
            i += 1
            continue
        if b == 0xF7:  # DYNAMIC placeholder, one argument byte
            if i + 1 < len(data):
                out.append("{DYNAMIC %d}" % data[i + 1])
                i += 2
            else:
                out.append("[F7]")
                i += 1
            continue
        if b not in single:
            matched = False
            for ln in range(max_len, 0, -1):
                seq = bytes(data[i : i + ln])
                if seq in multi:
                    out.append("{%s}" % multi[seq])
                    i += ln
                    matched = True
                    break
            if matched:
                continue
        out.append(single.get(b, "?%02X" % b))
        i += 1
    return "".join(out)


def emit_table(name, entries):
    out = [f"const u8 *const {name}[] = {{"]
    for e in entries:
        out.append(f"    {e},")
    out.append("};")
    return "\n".join(out)


def emit_table_rfu(name):
    # sPlayerDisconnectedTexts: RFU status -> text, from US union_room.h.
    entries = [
        "[RFU_STATUS_OK] = NULL",
        "[RFU_STATUS_FATAL_ERROR] = sText_MemberNoLongerAvailable",
        "[RFU_STATUS_CONNECTION_ERROR] = sText_TrainerAppearsUnavailable",
        "[RFU_STATUS_CHILD_SEND_COMPLETE] = NULL",
        "[RFU_STATUS_NEW_CHILD_DETECTED] = NULL",
        "[RFU_STATUS_JOIN_GROUP_OK] = NULL",
        "[RFU_STATUS_JOIN_GROUP_NO] = sText_PlayerRepliedNo",
        "[RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL",
        "[RFU_STATUS_LEAVE_GROUP_NOTICE] = NULL",
        "[RFU_STATUS_LEAVE_GROUP] = sText_StoppedBeingMember",
    ]
    out = [f"const u8 *const {name}[] = {{"]
    for e in entries:
        out.append(f"    {e},")
    out.append("};")
    return "\n".join(out)


def emit_table_link(name):
    entries = [
        "[RFU_STATUS_OK] = NULL",
        "[RFU_STATUS_FATAL_ERROR] = sText_LinkWithFriendDropped",
        "[RFU_STATUS_CONNECTION_ERROR] = sText_LinkWithFriendDropped",
        "[RFU_STATUS_CHILD_SEND_COMPLETE] = NULL",
        "[RFU_STATUS_NEW_CHILD_DETECTED] = NULL",
        "[RFU_STATUS_JOIN_GROUP_OK] = NULL",
        "[RFU_STATUS_JOIN_GROUP_NO] = sText_PlayerRepliedNo2",
        "[RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL",
        "[RFU_STATUS_LEAVE_GROUP_NOTICE] = NULL",
        "[RFU_STATUS_LEAVE_GROUP] = NULL",
    ]
    out = [f"const u8 *const {name}[] = {{"]
    for e in entries:
        out.append(f"    {e},")
    out.append("};")
    return "\n".join(out)


def emit_table_2x4(name):
    rows = [
        ["sText_WaitForBattleMale", "sText_WaitForChatMale", "NULL", "sText_ShowTrainerCardMale"],
        ["sText_WaitForBattleFemale", "sText_WaitForChatFemale", "NULL", "sText_ShowTrainerCardFemale"],
    ]
    out = [f"const u8 *const {name}[][4] = {{"]
    for row in rows:
        out.append("    { %s }," % ", ".join(row))
    out.append("};")
    return "\n".join(out)


def emit_table_start_activity(name):
    out = [f"const u8 *const {name}[][2][3] = {{"]
    out.append("    {")
    out.append("        { sText_BattleWillBeStarted, sText_EnteringChat, sText_TradeWillBeStarted },")
    out.append("        { sText_BattleWillBeStarted, sText_EnteringChat, sText_TradeWillBeStarted },")
    out.append("    }, {")
    out.append("        { sText_DoneWaitingBattleMale, sText_DoneWaitingChatMale, sText_TradeWillBeStarted },")
    out.append("        { sText_DoneWaitingBattleFemale, sText_DoneWaitingChatFemale, sText_TradeWillBeStarted },")
    out.append("    }")
    out.append("};")
    return "\n".join(out)


def emit_table_2x4_battle(name):
    rows = [
        ["sText_YoureToughMale", "sText_UsedGoodMoveMale", "sText_BattleSurpriseMale", "sText_SwitchedMonsMale"],
        ["sText_YoureToughFemale", "sText_UsedGoodMoveFemale", "sText_BattleSurpriseFemale", "sText_SwitchedMonsFemale"],
    ]
    out = [f"const u8 *const {name}[][4] = {{"]
    for row in rows:
        out.append("    { %s }," % ", ".join(row))
    out.append("};")
    return "\n".join(out)


def emit_table_chat(name):
    rows = [
        ["sText_LearnedSomethingMale", "sText_ThatsFunnyMale", "sText_RandomChatMale1", "sText_RandomChatMale2"],
        ["sText_LearnedSomethingFemale", "sText_ThatsFunnyFemale", "sText_RandomChatFemale1", "sText_RandomChatFemale2"],
    ]
    out = [f"const u8 *const {name}[][4] = {{"]
    for row in rows:
        out.append("    { %s }," % ", ".join(row))
    out.append("};")
    return "\n".join(out)


def emit_table_2x2(name):
    rows = [
        ["sText_ShowedTrainerCardMale1", "sText_ShowedTrainerCardMale2"],
        ["sText_ShowedTrainerCardFemale1", "sText_ShowedTrainerCardFemale2"],
    ]
    out = [f"const u8 *const {name}[][2] = {{"]
    for row in rows:
        out.append("    { %s }," % ", ".join(row))
    out.append("};")
    return "\n".join(out)


def emit_table_trade(name):
    out = [f"const u8 *const {name}[][4] = {{"]
    out.append("    { sText_MaleTraded1, sText_MaleTraded2, NULL, NULL },")
    out.append("    { sText_FemaleTraded1, sText_FemaleTraded2, NULL, NULL },")
    out.append("};")
    return "\n".join(out)


def build(symbols, end_addr, out_h, out_c, comment):
    single, multi = d.build_maps()
    sounds = d.build_sound_map()
    out = []
    out.append('#include "global.h"')
    if any(sym[2] in ("table_rfu", "table_link") for sym in symbols):
        out.append('#include "link_rfu.h"')
    out.append("")
    out.append(comment)
    for i, sym in enumerate(symbols):
        name, addr, kind, payload = sym[0], sym[1], sym[2], sym[3]
        end = next_addr(addr, symbols, end_addr)
        if kind == "ascii_fixed":
            out.append(emit_ascii(name, payload, size=symbols[i][4]))
        elif kind in ("ascii", "ascii_aligned"):
            out.append(emit_ascii(name, payload, aligned=(kind == "ascii_aligned")))
        elif kind == "gap":
            b = ", ".join("0x%02X" % x for x in payload)
            out.append(f"const u8 {name}[] = {{{b}}};")
        elif kind in ("text", "text_fixed"):
            size = None
            if kind == "text_fixed":
                size = end_addr - addr
            out.append(emit_text(name, addr, end, size=size))
        elif kind == "table":
            out.append(emit_table(name, payload))
        elif kind == "table_rfu":
            out.append(emit_table_rfu(name))
        elif kind == "table_link":
            out.append(emit_table_link(name))
        elif kind == "table_2x4":
            out.append(emit_table_2x4(name))
        elif kind == "table_start_activity":
            out.append(emit_table_start_activity(name))
        elif kind == "table_2x4_battle":
            out.append(emit_table_2x4_battle(name))
        elif kind == "table_chat":
            out.append(emit_table_chat(name))
        elif kind == "table_2x2":
            out.append(emit_table_2x2(name))
        elif kind == "table_trade":
            out.append(emit_table_trade(name))
        elif kind == "clock_cmds":
            out.append('const char sASCII_ClockCmds[][12] = {')
            for row in ["           ", "CLOCK DRIFT", "BUSY SEND  ", "CMD REJECT ", "CLOCK SLAVE"]:
                out.append(f'    "{row}",')
            out.append("};")
        elif kind == "child_search":
            out.append('const char sASCII_ChildParentSearch[][8] = {')
            for row in ["CHILD ", "PARENT", "SEARCH"]:
                out.append(f'    "{row}",')
            out.append("};")
        out.append("")
    (ROOT / out_h).write_text("\n".join(out) + "\n", encoding="utf-8")
    (ROOT / out_c).write_text(f'#include "{Path(out_h).name}"\n', encoding="utf-8")
    print(f"wrote {out_h} and {out_c}")


def main():
    build(SYMBOLS, END_ADDR, "src/data/union_room.h", "src/data/union_room.c",
          "// RFU assert and debug strings (JP-specific section at 0x82C053C)")
    build(SYMBOLS2, END_ADDR2, "src/data/union_room2.h", "src/data/union_room2.c",
          "// Union-room texts (second batch)")
    build(SYMBOLS3, END_ADDR3, "src/data/union_room3.h", "src/data/union_room3.c",
          "// Union-room member-status texts and pointer tables")
    build(SYMBOLS4, END_ADDR4, "src/data/union_room4.h", "src/data/union_room4.c",
          "// Wireless link texts and the link-dropped table")
    build(SYMBOLS5, END_ADDR5, "src/data/union_room5.h", "src/data/union_room5.c",
          "// Trade-request and communicating texts")
    build(SYMBOLS6, END_ADDR6, "src/data/union_room6.h", "src/data/union_room6.c",
          "// Hi/do-something and contacted/awaiting texts")
    build(SYMBOLS7, END_ADDR7, "src/data/union_room7.h", "src/data/union_room7.c",
          "// Invitation and chat texts")
    build(SYMBOLS8, END_ADDR8, "src/data/union_room8.h", "src/data/union_room8.c",
          "// Wait-for-activity and show-card texts")
    build(SYMBOLS8B, END_ADDR8B, "src/data/union_room8b.h", "src/data/union_room8b.c",
          "// Start-activity and battle-declined texts")
    build(SYMBOLS8C, END_ADDR8C, "src/data/union_room8c.h", "src/data/union_room8c.c",
          "// Battle-busy, level-requirement and reaction texts")
    build(SYMBOLS8D, END_ADDR8D, "src/data/union_room8d.h", "src/data/union_room8d.c",
          "// Chat/trainer-card/trade reaction texts")


if __name__ == "__main__":
    main()
