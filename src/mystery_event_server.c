#include "global.h"
#include "malloc.h"

// JP-only mevent server. The original source was mevent_server.c; the
// assert strings embedded in the ROM preserve its variable names
// (svr->mainseqno, cmd->parameter/cmd->flag, ME_SEND_BUF_SIZE,
// func_tbl).

extern const char gUnknown_82C4A74[]; // "mevent_server.c"
extern const char gUnknown_82C4A84[]; // "size <= ME_SEND_BUF_SIZE"
extern const char gUnknown_82C4B10[]; // "svr->mainseqno < NELEMS(func_tbl)"
extern const u8 gUnknown_82C4F60[];
extern const u8 gUnknown_82C4FC0[];
extern u32 (*const gUnknown_82C4AFC[])(void *);

extern void mevent_srv_sub_init(void *sub, s32 a, s32 b);
extern void mevent_srv_sub_init_send(void *sub, u32 size, void *buffer, u32 size2);
extern u32 mevent_srv_sub_recv(void *sub);
extern u32 mevent_srv_sub_send(void *sub);

#define ME_SEND_BUF_SIZE 0x400

struct MeventServerData
{
    u32 unk0;         // 0x00
    u32 result;       // 0x04
    u32 mainseqno;    // 0x08
    u32 cmdIndex;     // 0x0C
    const u8 *script; // 0x10
    void *unk14;      // 0x14
    void *unk18;      // 0x18
    void *unk1C;      // 0x1C
    void *unk20;      // 0x20
    u8 unk24[0x14];   // 0x24
    u8 sub[0x28];     // 0x38
};

extern EWRAM_DATA struct MeventServerData *gUnknown_2022930;

void mevent_srv_init_common(void *data, const u8 *script, s32 a, s32 b);
u32 mevent_srv_exec_common(void *data);

void mevent_srv_init_wnews(void)
{
    gUnknown_2022930 = AllocZeroed(0x60);
    mevent_srv_init_common(gUnknown_2022930, gUnknown_82C4F60, 0, 1);
}

void mevent_srv_new_wcard(void)
{
    gUnknown_2022930 = AllocZeroed(0x60);
    mevent_srv_init_common(gUnknown_2022930, gUnknown_82C4FC0, 0, 1);
}

u32 mevent_srv_common_do_exec(u16 *result)
{
    u32 status;

    if (gUnknown_2022930 == NULL)
        return 3;
    status = mevent_srv_exec_common(gUnknown_2022930);
    if (status == 3)
    {
        *result = gUnknown_2022930->result;
        mevent_srv_free_resources(gUnknown_2022930);
        Free(gUnknown_2022930);
        gUnknown_2022930 = NULL;
    }
    return status;
}

void mevent_srv_init_common(void *data, const u8 *script, s32 a, s32 b)
{
    struct MeventServerData *svr = data;

    svr->unk0 = 0;
    svr->mainseqno = 0;
    svr->unk18 = AllocZeroed(0xA4);
    svr->unk1C = AllocZeroed(0xE0);
    svr->unk14 = AllocZeroed(0x400);
    svr->unk20 = AllocZeroed(0x64);
    svr->script = script;
    svr->cmdIndex = 0;
    mevent_srv_sub_init(svr->sub, a, b);
}

void mevent_srv_free_resources(void *data)
{
    struct MeventServerData *svr = data;

    Free(svr->unk18);
    Free(svr->unk1C);
    Free(svr->unk14);
    Free(svr->unk20);
}

void mevent_srv_common_init_send(void *data, u32 size, void *buffer, u32 size2)
{
    if (size2 > ME_SEND_BUF_SIZE)
        AGBAssert(gUnknown_82C4A74, 0x101, gUnknown_82C4A84, TRUE);
    mevent_srv_sub_init_send(((struct MeventServerData *)data)->sub, size, buffer, size2);
}

void *mevent_first_if_not_null_else_second(void *a, void *b)
{
    if (a == NULL)
        return b;
    return a;
}

u32 mevent_compare_pointers(u32 a, u32 b)
{
    if (b < a)
        return 0;
    if (b == a)
        return 1;
    return 2;
}

u32 common_mainseq_0(void *data)
{
    ((struct MeventServerData *)data)->mainseqno = 4;
    return 0;
}

u32 common_mainseq_1(void *data)
{
    return 3;
}

u32 common_mainseq_2(void *data)
{
    struct MeventServerData *svr = data;

    if (mevent_srv_sub_recv(svr->sub))
        svr->mainseqno = 4;
    return 1;
}

u32 common_mainseq_3(void *data)
{
    struct MeventServerData *svr = data;

    if (mevent_srv_sub_send(svr->sub))
        svr->mainseqno = 4;
    return 1;
}

u32 mevent_srv_exec_common(void *data)
{
    struct MeventServerData *svr = data;
    u32 status;

    if (svr->mainseqno > 4)
        AGBAssert(gUnknown_82C4A74, 0x228, gUnknown_82C4B10, TRUE);
    status = gUnknown_82C4AFC[svr->mainseqno](svr);
    if (svr->mainseqno > 4)
        AGBAssert(gUnknown_82C4A74, 0x22A, gUnknown_82C4B10, TRUE);
    return status;
}
