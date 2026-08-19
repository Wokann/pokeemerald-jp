#include "global.h"
#include "link.h"
#include "link_rfu.h"
#include "malloc.h"
#include "mystery_gift.h"
#include "script.h"
#include "util.h"

// JP-only mevent server. The original source was mevent_server.c; the
// assert strings embedded in the ROM preserve its variable names
// (svr->mainseqno, cmd->parameter/cmd->flag, ME_SEND_BUF_SIZE,
// func_tbl).

extern const char gMeventServerAssertFile[];
extern const char gMeventServerAssertExpr0[];
extern const char gMeventServerAssertExpr1[];
extern const char gMeventServerAssertExpr2[];
extern const char gMeventServerAssertExpr3[];
extern const char gMeventServerAssertExpr4[];
extern const u8 gMeventServerCmdTable1[];
extern const u8 gMeventServerCmdTable2[];
extern u32 (*const gMeventServerFuncs[])(void *);
extern u16 gBlockRecvBuffer[MAX_RFU_PLAYERS][BLOCK_BUFFER_SIZE / 2];
extern u32 (*const gMeventServerClientFuncs[])(void *);
extern const u8 gMeventServerClientInitData[];

#define ME_SEND_BUF_SIZE 0x400

struct MeventServerSub
{
    s32 unk0;                       // 0x00
    u8 unk4;                        // 0x04
    u8 unk5;                        // 0x05
    u16 unk6;                       // 0x06
    u16 unk8;                       // 0x08
    u16 unkA;                       // 0x0A
    u16 unkC;                       // 0x0C
    u16 unkE;                       // 0x0E
    u16 unk10;                      // 0x10
    u16 unk12;                      // 0x12
    u16 unk14;                      // 0x14
    u16 unk16;                      // 0x16
    void *unk18;                    // 0x18
    void *unk1C;                    // 0x1C
    u32 (*recvFunc)(void *sub);     // 0x20
    u32 (*sendFunc)(void *sub);     // 0x24
};
bool32 mevent_receive_func(void *data);
bool32 mevent_send_func(void *data);

u32 mevent_srv_sub_recv(struct MeventServerSub *sub)
{
    return sub->recvFunc(sub);
}

u32 mevent_srv_sub_send(struct MeventServerSub *sub)
{
    return sub->sendFunc(sub);
}

void mevent_srv_sub_init(struct MeventServerSub *sub, s32 a, s32 b)
{
    sub->unk4 = a;
    sub->unk5 = b;
    sub->unk0 = 0;
    sub->unk12 = 0;
    sub->unk14 = 0;
    sub->unk10 = 0;
    sub->unkA = 0;
    sub->unkC = 0;
    sub->unk8 = 0;
    sub->unk1C = 0;
    sub->unk18 = 0;
    sub->sendFunc = mevent_send_func;
    sub->recvFunc = mevent_receive_func;
}

void MysteryGiftLink_InitSend(struct MeventServerSub *sub, u32 size, void *buffer, u32 size2)
{
    sub->unk0 = 0;
    sub->unkE = size;
    sub->unk10 = 0;
    sub->unk12 = 0;
    if (size2 != 0)
        sub->unk14 = size2;
    else
        sub->unk14 = 0x400;
    sub->unk1C = buffer;
}

void MysteryGiftLink_InitRecv(struct MeventServerSub *sub, u32 a, void *buffer)
{
    sub->unk0 = 0;
    sub->unk6 = a;
    sub->unk8 = 0;
    sub->unkA = 0;
    sub->unkC = 0;
    sub->unk18 = buffer;
}

void mevent_recv_block(u32 block, void *dst, u32 size)
{
    memcpy(dst, (u8 *)gBlockRecvBuffer + (block << 8), size);
}

bool32 mevent_has_received(u32 block)
{
    if ((GetBlockReceivedStatus() >> block) & 1)
        return TRUE;
    return FALSE;
}

void mevent_reset_recv(u8 block)
{
    ResetBlockReceivedFlag(block);
}


__attribute__((naked)) bool32 mevent_receive_func(void *data)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, lr}\n\t"
        "sub sp, #8\n\t"
        "adds r5, r0, #0\n\t"
        "ldr r6, [r5]\n\t"
        "cmp r6, #1\n\t"
        "beq _0801D7FC\n\t"
        "cmp r6, #1\n\t"
        "bgt _0801D7AE\n\t"
        "cmp r6, #0\n\t"
        "beq _0801D7B4\n\t"
        "b _0801D862\n\t"
        "_0801D7AE:\n\t"
        "cmp r6, #2\n\t"
        "beq _0801D848\n\t"
        "b _0801D862\n\t"
        "_0801D7B4:\n\t"
        "ldrb r0, [r5, #5]\n\t"
        "bl mevent_has_received\n\t"
        "cmp r0, #0\n\t"
        "beq _0801D862\n\t"
        "ldrb r0, [r5, #5]\n\t"
        "mov r4, sp\n\t"
        "mov r1, sp\n\t"
        "movs r2, #8\n\t"
        "bl mevent_recv_block\n\t"
        "ldrh r1, [r4, #4]\n\t"
        "strh r1, [r5, #0xc]\n\t"
        "ldrh r0, [r4, #2]\n\t"
        "strh r0, [r5, #0xa]\n\t"
        "lsls r1, r1, #0x10\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x13\n\t"
        "cmp r1, r0\n\t"
        "bls _0801D7E2\n\t"
        "_0801D7DC:\n\t"
        "bl LinkRfu_FatalError\n\t"
        "b _0801D862\n\t"
        "_0801D7E2:\n\t"
        "mov r1, sp\n\t"
        "ldrh r0, [r5, #6]\n\t"
        "ldrh r1, [r1]\n\t"
        "cmp r0, r1\n\t"
        "bne _0801D7DC\n\t"
        "strh r6, [r5, #8]\n\t"
        "ldrb r0, [r5, #5]\n\t"
        "bl mevent_reset_recv\n\t"
        "ldr r0, [r5]\n\t"
        "adds r0, #1\n\t"
        "str r0, [r5]\n\t"
        "b _0801D862\n\t"
        "_0801D7FC:\n\t"
        "ldrb r0, [r5, #5]\n\t"
        "bl mevent_has_received\n\t"
        "cmp r0, #0\n\t"
        "beq _0801D862\n\t"
        "ldrh r0, [r5, #8]\n\t"
        "lsls r1, r0, #6\n\t"
        "subs r1, r1, r0\n\t"
        "lsls r3, r1, #2\n\t"
        "ldrh r0, [r5, #0xc]\n\t"
        "subs r2, r0, r3\n\t"
        "cmp r2, #0xfc\n\t"
        "bhi _0801D82E\n\t"
        "ldrb r0, [r5, #5]\n\t"
        "ldr r1, [r5, #0x18]\n\t"
        "adds r1, r1, r3\n\t"
        "bl mevent_recv_block\n\t"
        "ldrh r0, [r5, #8]\n\t"
        "adds r0, #1\n\t"
        "strh r0, [r5, #8]\n\t"
        "ldr r0, [r5]\n\t"
        "adds r0, #1\n\t"
        "str r0, [r5]\n\t"
        "b _0801D840\n\t"
        "_0801D82E:\n\t"
        "ldrb r0, [r5, #5]\n\t"
        "ldr r1, [r5, #0x18]\n\t"
        "adds r1, r1, r3\n\t"
        "movs r2, #0xfc\n\t"
        "bl mevent_recv_block\n\t"
        "ldrh r0, [r5, #8]\n\t"
        "adds r0, #1\n\t"
        "strh r0, [r5, #8]\n\t"
        "_0801D840:\n\t"
        "ldrb r0, [r5, #5]\n\t"
        "bl mevent_reset_recv\n\t"
        "b _0801D862\n\t"
        "_0801D848:\n\t"
        "ldr r0, [r5, #0x18]\n\t"
        "ldrh r1, [r5, #0xc]\n\t"
        "bl CalcCRC16WithTable\n\t"
        "lsls r0, r0, #0x10\n\t"
        "lsrs r0, r0, #0x10\n\t"
        "ldrh r1, [r5, #0xa]\n\t"
        "cmp r0, r1\n\t"
        "bne _0801D7DC\n\t"
        "movs r0, #0\n\t"
        "str r0, [r5]\n\t"
        "movs r0, #1\n\t"
        "b _0801D864\n\t"
        "_0801D862:\n\t"
        "movs r0, #0\n\t"
        "_0801D864:\n\t"
        "add sp, #8\n\t"
        "pop {r4, r5, r6}\n\t"
        "pop {r1}\n\t"
        "bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool32 mevent_send_func(void *data)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, lr}\n\t"
        "sub sp, #8\n\t"
        "adds r4, r0, #0\n\t"
        "ldr r5, [r4]\n\t"
        "cmp r5, #1\n\t"
        "beq _0801D8D8\n\t"
        "cmp r5, #1\n\t"
        "bgt _0801D882\n\t"
        "cmp r5, #0\n\t"
        "beq _0801D88C\n\t"
        "b _0801D96E\n\t"
        "_0801D882:\n\t"
        "cmp r5, #2\n\t"
        "beq _0801D92C\n\t"
        "cmp r5, #3\n\t"
        "beq _0801D956\n\t"
        "b _0801D96E\n\t"
        "_0801D88C:\n\t"
        "bl IsLinkTaskFinished\n\t"
        "lsls r0, r0, #0x18\n\t"
        "cmp r0, #0\n\t"
        "beq _0801D96E\n\t"
        "ldrh r1, [r4, #0xe]\n\t"
        "ldr r2, _0801D8D0\n\t"
        "ldr r0, [sp]\n\t"
        "ands r0, r2\n\t"
        "orrs r0, r1\n\t"
        "str r0, [sp]\n\t"
        "ldrh r1, [r4, #0x14]\n\t"
        "ldr r0, [sp, #4]\n\t"
        "ands r0, r2\n\t"
        "orrs r0, r1\n\t"
        "str r0, [sp, #4]\n\t"
        "ldr r0, [r4, #0x1c]\n\t"
        "bl CalcCRC16WithTable\n\t"
        "lsls r0, r0, #0x10\n\t"
        "ldr r2, _0801D8D4\n\t"
        "ldr r1, [sp]\n\t"
        "ands r1, r2\n\t"
        "orrs r1, r0\n\t"
        "str r1, [sp]\n\t"
        "lsrs r1, r1, #0x10\n\t"
        "strh r1, [r4, #0x12]\n\t"
        "strh r5, [r4, #0x10]\n\t"
        "movs r0, #0\n\t"
        "mov r1, sp\n\t"
        "movs r2, #8\n\t"
        "bl SendBlock\n\t"
        "b _0801D94E\n\t"
        ".align 2, 0\n\t"
        "_0801D8D0: .4byte 0xFFFF0000\n\t"
        "_0801D8D4: .4byte 0x0000FFFF\n\t"
        "_0801D8D8:\n\t"
        "bl IsLinkTaskFinished\n\t"
        "lsls r0, r0, #0x18\n\t"
        "cmp r0, #0\n\t"
        "beq _0801D96E\n\t"
        "ldrb r0, [r4, #4]\n\t"
        "bl mevent_has_received\n\t"
        "cmp r0, #0\n\t"
        "beq _0801D96E\n\t"
        "ldrb r0, [r4, #4]\n\t"
        "bl mevent_reset_recv\n\t"
        "ldrh r1, [r4, #0x10]\n\t"
        "lsls r0, r1, #6\n\t"
        "subs r0, r0, r1\n\t"
        "lsls r3, r0, #2\n\t"
        "ldrh r0, [r4, #0x14]\n\t"
        "subs r0, r0, r3\n\t"
        "cmp r0, #0xfc\n\t"
        "bhi _0801D918\n\t"
        "ldr r1, [r4, #0x1c]\n\t"
        "adds r1, r1, r3\n\t"
        "lsls r2, r0, #0x10\n\t"
        "lsrs r2, r2, #0x10\n\t"
        "movs r0, #0\n\t"
        "bl SendBlock\n\t"
        "ldrh r0, [r4, #0x10]\n\t"
        "adds r0, #1\n\t"
        "strh r0, [r4, #0x10]\n\t"
        "b _0801D94E\n\t"
        "_0801D918:\n\t"
        "ldr r1, [r4, #0x1c]\n\t"
        "adds r1, r1, r3\n\t"
        "movs r0, #0\n\t"
        "movs r2, #0xfc\n\t"
        "bl SendBlock\n\t"
        "ldrh r0, [r4, #0x10]\n\t"
        "adds r0, #1\n\t"
        "strh r0, [r4, #0x10]\n\t"
        "b _0801D96E\n\t"
        "_0801D92C:\n\t"
        "bl IsLinkTaskFinished\n\t"
        "lsls r0, r0, #0x18\n\t"
        "cmp r0, #0\n\t"
        "beq _0801D96E\n\t"
        "ldr r0, [r4, #0x1c]\n\t"
        "ldrh r1, [r4, #0x14]\n\t"
        "bl CalcCRC16WithTable\n\t"
        "lsls r0, r0, #0x10\n\t"
        "lsrs r0, r0, #0x10\n\t"
        "ldrh r1, [r4, #0x12]\n\t"
        "cmp r0, r1\n\t"
        "beq _0801D94E\n\t"
        "bl LinkRfu_FatalError\n\t"
        "b _0801D96E\n\t"
        "_0801D94E:\n\t"
        "ldr r0, [r4]\n\t"
        "adds r0, #1\n\t"
        "str r0, [r4]\n\t"
        "b _0801D96E\n\t"
        "_0801D956:\n\t"
        "ldrb r0, [r4, #4]\n\t"
        "bl mevent_has_received\n\t"
        "cmp r0, #0\n\t"
        "beq _0801D96E\n\t"
        "ldrb r0, [r4, #4]\n\t"
        "bl mevent_reset_recv\n\t"
        "movs r0, #0\n\t"
        "str r0, [r4]\n\t"
        "movs r0, #1\n\t"
        "b _0801D970\n\t"
        "_0801D96E:\n\t"
        "movs r0, #0\n\t"
        "_0801D970:\n\t"
        "add sp, #8\n\t"
        "pop {r4, r5}\n\t"
        "pop {r1}\n\t"
        "bx r1\n\t"
        ".syntax divided\n\t"
    );
}
