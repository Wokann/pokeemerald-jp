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

struct MeventBlockHeader
{
    u16 ident;
    u16 crc;
    u16 size;
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

bool32 mevent_receive_func(void *data)
{
    struct MeventServerSub *sub = data;
    struct MeventBlockHeader header;

    switch (sub->unk0)
    {
    case 0:
        if (mevent_has_received(sub->unk5))
        {
            mevent_recv_block(sub->unk5, &header, sizeof(header));
            sub->unkC = header.size;
            sub->unkA = header.crc;
            if (sub->unkC > ME_SEND_BUF_SIZE)
            {
                LinkRfu_FatalError();
                return FALSE;
            }
            else if (sub->unk6 != header.ident)
            {
                LinkRfu_FatalError();
                return FALSE;
            }
            else
            {
                sub->unk8 = 0;
                mevent_reset_recv(sub->unk5);
                sub->unk0++;
            }
        }
        break;
    case 1:
        if (mevent_has_received(sub->unk5))
        {
            u32 blockSize = sub->unk8 * 252;

            if (sub->unkC - blockSize <= 252)
            {
                mevent_recv_block(sub->unk5, sub->unk18 + blockSize, sub->unkC - blockSize);
                sub->unk8++;
                sub->unk0++;
            }
            else
            {
                mevent_recv_block(sub->unk5, sub->unk18 + blockSize, 252);
                sub->unk8++;
            }
            mevent_reset_recv(sub->unk5);
        }
        break;
    case 2:
        if (CalcCRC16WithTable(sub->unk18, sub->unkC) != sub->unkA)
        {
            LinkRfu_FatalError();
            return FALSE;
        }
        else
        {
            sub->unk0 = 0;
            return TRUE;
        }
    }

    return FALSE;
}

bool32 mevent_send_func(void *data)
{
    struct MeventServerSub *sub = data;
    struct MeventBlockHeader header;

    switch (sub->unk0)
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            header.ident = sub->unkE;
            header.size = sub->unk14;
            header.crc = CalcCRC16WithTable(sub->unk1C, sub->unk14);
            sub->unk12 = header.crc;
            sub->unk10 = 0;
            SendBlock(0, &header, sizeof(header));
            sub->unk0++;
        }
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            if (mevent_has_received(sub->unk4))
            {
                u32 blockSize;

                mevent_reset_recv(sub->unk4);
                blockSize = sub->unk10 * 252;
                if (sub->unk14 - blockSize <= 252)
                {
                    SendBlock(0, sub->unk1C + blockSize, sub->unk14 - blockSize);
                    sub->unk10++;
                    sub->unk0++;
                }
                else
                {
                    SendBlock(0, sub->unk1C + blockSize, 252);
                    sub->unk10++;
                }
            }
        }
        break;
    case 2:
        if (IsLinkTaskFinished())
        {
            if (CalcCRC16WithTable(sub->unk1C, sub->unk14) != sub->unk12)
                LinkRfu_FatalError();
            else
                sub->unk0++;
        }
        break;
    case 3:
        if (mevent_has_received(sub->unk4))
        {
            mevent_reset_recv(sub->unk4);
            sub->unk0 = 0;
            return TRUE;
        }
        break;
    }

    return FALSE;
}
