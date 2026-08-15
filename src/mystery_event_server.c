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

extern const char gUnknown_82C4A74[]; // "mevent_server.c"
extern const char gUnknown_82C4A84[]; // "size <= ME_SEND_BUF_SIZE"
extern const char gUnknown_82C4AA0[]; // "cmd->parameter == NULL"
extern const char gUnknown_82C4AB8[]; // "cmd->flag == FALSE"
extern const char gUnknown_82C4ACC[]; // "cmd->flag == FALSE && cmd->parameter == NULL"
extern const char gUnknown_82C4B10[]; // "svr->mainseqno < NELEMS(func_tbl)"
extern const u8 gUnknown_82C4F60[];
extern const u8 gUnknown_82C4FC0[];
extern u32 (*const gUnknown_82C4AFC[])(void *);
extern u16 gBlockRecvBuffer[MAX_RFU_PLAYERS][BLOCK_BUFFER_SIZE / 2];
extern u32 (*const gUnknown_82C4B34[])(void *);
extern const u8 gUnknown_82C4B6C[];

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

struct MeventClientData
{
    u32 unk0;                       // 0x00
    u32 result;                     // 0x04
    u32 unk8;                       // 0x08
    u32 unkC;                       // 0x0C
    u32 unk10;                      // 0x10
    void *unk14;                    // 0x14
    void *unk18;                    // 0x18
    void *unk1C;                    // 0x1C
    void *unk20;                    // 0x20
    struct MeventServerSub sub;     // 0x24
    u32 unk4C;                      // 0x4C
};

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
    u32 unk24;        // 0x24
    u32 unk28;        // 0x28
    u32 unk2C;        // 0x2C
    u32 unk30;        // 0x30
    u32 unk34;        // 0x34
    struct MeventServerSub sub; // 0x38
};

struct MeventCmd
{
    u32 id;
    u32 flag;
    u32 parameter;
};

extern EWRAM_DATA struct MeventServerData *gUnknown_2022930;
extern EWRAM_DATA struct MeventClientData *gUnknown_2022934;

void mevent_srv_init_common(void *data, const u8 *script, s32 a, s32 b);
u32 mevent_srv_exec_common(void *data);
u32 common_mainseq_4(void *data);
u32 mevent_receive_func(struct MeventServerSub *sub);
u32 mevent_send_func(struct MeventServerSub *sub);
u32 mevent_srv_sub_recv(struct MeventServerSub *sub);
u32 mevent_srv_sub_send(struct MeventServerSub *sub);
void mevent_srv_sub_init(struct MeventServerSub *sub, s32 a, s32 b);
void mevent_srv_sub_init_send(struct MeventServerSub *sub, u32 size, void *buffer, u32 size2);
void mevent_srv_sub_init_recv(struct MeventServerSub *sub, u32 a, void *buffer);
void mevent_client_init(void *data, s32 a, s32 b);
u32 mevent_client_exec(void *data);
void mevent_client_free_resources(void *data);

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
    mevent_srv_sub_init(&svr->sub, a, b);
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
    mevent_srv_sub_init_send(&((struct MeventServerData *)data)->sub, size, buffer, size2);
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

    if (mevent_srv_sub_recv(&svr->sub))
        svr->mainseqno = 4;
    return 1;
}

u32 common_mainseq_3(void *data)
{
    struct MeventServerData *svr = data;

    if (mevent_srv_sub_send(&svr->sub))
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

u32 common_mainseq_4(void *data)
{
    struct MeventServerData *svr = data;
    struct MeventCmd *cmd = (struct MeventCmd *)&svr->script[svr->cmdIndex * 12];
    void *buf;

    svr->cmdIndex++;
    switch (cmd->id)
    {
    case 0:
        if (cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x162, gUnknown_82C4AA0, TRUE);
        svr->mainseqno = 1;
        svr->result = cmd->flag;
        break;
    case 1:
        svr->mainseqno = 3;
        break;
    case 2:
        if (cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x16C, gUnknown_82C4AA0, TRUE);
        mevent_srv_sub_init_recv(&svr->sub, cmd->flag, svr->unk14);
        svr->mainseqno = 2;
        break;
    case 3:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x172, gUnknown_82C4AB8, TRUE);
        svr->cmdIndex = 0;
        svr->script = cmd->parameter;
        break;
    case 5:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x178, gUnknown_82C4AB8, TRUE);
        if (cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x179, gUnknown_82C4AA0, TRUE);
        memcpy(svr->unk20, svr->unk14, 0x64);
        break;
    case 6:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x17E, gUnknown_82C4AB8, TRUE);
        if (cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x17F, gUnknown_82C4AA0, TRUE);
        svr->result = MysteryGift_ValidateLinkGameData(svr->unk20, FALSE);
        break;
    case 30:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x184, gUnknown_82C4AB8, TRUE);
        if (cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x185, gUnknown_82C4AA0, TRUE);
        svr->result = MysteryGift_ValidateLinkGameData(svr->unk20, TRUE);
        break;
    case 4:
        if (svr->result == cmd->flag)
        {
            svr->cmdIndex = 0;
            svr->script = cmd->parameter;
        }
        break;
    case 7:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x192, gUnknown_82C4AB8, TRUE);
        buf = mevent_first_if_not_null_else_second(cmd->parameter, svr->unk18);
        svr->result = MysteryGift_CompareCardFlags(buf, svr->unk20, buf);
        break;
    case 8:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x198, gUnknown_82C4AB8, TRUE);
        if (cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x199, gUnknown_82C4AA0, TRUE);
        svr->result = *(u32 *)svr->unk14;
        break;
    case 9:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x19E, gUnknown_82C4AB8, TRUE);
        buf = mevent_first_if_not_null_else_second(cmd->parameter, &svr->unk34);
        svr->result = MysteryGift_CheckStamps(buf, svr->unk20, buf);
        break;
    case 10:
        if (cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x1A5, gUnknown_82C4AA0, TRUE);
        svr->result = MysteryGift_GetCardStatFromLinkData(svr->unk20, cmd->flag);
        break;
    case 11:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1AA, gUnknown_82C4AB8, TRUE);
        svr->result = MysteryGift_DoesQuestionnaireMatch(svr->unk20, cmd->parameter);
        break;
    case 12:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1B0, gUnknown_82C4AB8, TRUE);
        svr->result = mevent_compare_pointers(cmd->parameter, *(u32 *)svr->unk14);
        break;
    case 14:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1B6, gUnknown_82C4AB8, TRUE);
        buf = mevent_first_if_not_null_else_second(cmd->parameter, svr->unk1C);
        mevent_srv_common_init_send(svr, 0x17, buf, 0xE0);
        break;
    case 13:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1BC, gUnknown_82C4AB8, TRUE);
        buf = mevent_first_if_not_null_else_second(cmd->parameter, svr->unk18);
        mevent_srv_common_init_send(svr, 0x16, buf, 0xA4);
        break;
    case 16:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1C2, gUnknown_82C4AB8, TRUE);
        buf = mevent_first_if_not_null_else_second(cmd->parameter, &svr->unk34);
        mevent_srv_common_init_send(svr, 0x18, buf, 4);
        break;
    case 15:
        buf = cmd->parameter;
        if (buf == NULL)
            mevent_srv_common_init_send(svr, 0x19, svr->unk24, svr->unk28);
        else
            mevent_srv_common_init_send(svr, 0x19, cmd->parameter, cmd->flag);
        break;
    case 18:
        buf = cmd->parameter;
        if (buf == NULL)
            mevent_srv_common_init_send(svr, 0x10, svr->unk2C, svr->unk30);
        else
            mevent_srv_common_init_send(svr, 0x10, cmd->parameter, cmd->flag);
        break;
    case 19:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1D8, gUnknown_82C4AB8, TRUE);
        mevent_srv_common_init_send(svr, 0x1A, cmd->parameter, 0xBC);
        break;
    case 20:
        mevent_srv_common_init_send(svr, 0x15, cmd->parameter, cmd->flag);
        break;
    case 17:
        mevent_srv_common_init_send(svr, 0x1C, cmd->parameter, cmd->flag);
        break;
    case 22:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1E7, gUnknown_82C4AB8, TRUE);
        memcpy(svr->unk18, cmd->parameter, 0xA4);
        break;
    case 23:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1EC, gUnknown_82C4AB8, TRUE);
        memcpy(svr->unk1C, cmd->parameter, 0xE0);
        break;
    case 21:
        if (cmd->flag != FALSE)
            AGBAssert(gUnknown_82C4A74, 0x1F1, gUnknown_82C4AB8, TRUE);
        svr->unk34 = *(u32 *)cmd->parameter;
        break;
    case 24:
        svr->unk24 = cmd->parameter;
        svr->unk28 = cmd->flag;
        break;
    case 25:
        svr->unk2C = cmd->parameter;
        svr->unk30 = cmd->flag;
        break;
    case 26:
        if (cmd->flag != FALSE || cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x200, gUnknown_82C4ACC, TRUE);
        memcpy(svr->unk18, GetSavedWonderCard(), 0xA4);
        DisableWonderCardSending(svr->unk18);
        break;
    case 27:
        if (cmd->flag != FALSE || cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x206, gUnknown_82C4ACC, TRUE);
        memcpy(svr->unk1C, GetSavedWonderNews(), 0xE0);
        break;
    case 28:
        if (cmd->flag != FALSE || cmd->parameter != NULL)
            AGBAssert(gUnknown_82C4A74, 0x20B, gUnknown_82C4ACC, TRUE);
        svr->unk24 = (u32)GetSavedRamScriptIfValid();
        break;
    case 29:
        mevent_srv_common_init_send(svr, 0x1B, cmd->parameter, cmd->flag);
        break;
    default:
        break;
    }
    return 1;
}

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

void mevent_srv_sub_init_send(struct MeventServerSub *sub, u32 size, void *buffer, u32 size2)
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

void mevent_srv_sub_init_recv(struct MeventServerSub *sub, u32 a, void *buffer)
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

void mevent_client_do_init(void *arg)
{
    gUnknown_2022934 = AllocZeroed(0x50);
    mevent_client_init(gUnknown_2022934, 1, 0);
    gUnknown_2022934->unk4C = arg;
}

u32 mevent_client_do_exec(u16 *result)
{
    u32 status;

    if (gUnknown_2022934 == NULL)
        return 6;
    status = mevent_client_exec(gUnknown_2022934);
    if (status == 6)
    {
        *result = gUnknown_2022934->result;
        mevent_client_free_resources(gUnknown_2022934);
        Free(gUnknown_2022934);
        gUnknown_2022934 = NULL;
    }
    return status;
}

void mevent_client_inc_flag(void)
{
    gUnknown_2022934->unkC++;
}

void *mevent_client_get_buffer(void)
{
    return gUnknown_2022934->unk20;
}

void mevent_client_set_param(u32 param)
{
    gUnknown_2022934->result = param;
}

void mevent_client_init(void *data, s32 a, s32 b)
{
    struct MeventClientData *cli = data;

    cli->unk0 = 0;
    cli->unk8 = 0;
    cli->unkC = 0;
    cli->unk14 = AllocZeroed(0x400);
    cli->unk18 = AllocZeroed(0x400);
    cli->unk1C = AllocZeroed(0x400);
    cli->unk20 = AllocZeroed(0x40);
    mevent_srv_sub_init(&cli->sub, a, b);
}

void mevent_client_free_resources(void *data)
{
    struct MeventClientData *cli = data;

    Free(cli->unk14);
    Free(cli->unk18);
    Free(cli->unk1C);
    Free(cli->unk20);
}

void mevent_client_jmp_buffer(void *data)
{
    struct MeventClientData *cli = data;

    memcpy(cli->unk1C, cli->unk18, 0x400);
    cli->unk10 = 0;
}

void mevent_client_send_word(void *data, u32 a, u32 word)
{
    struct MeventClientData *cli = data;
    u32 zero = 0;

    CpuSet(&zero, cli->unk14, 0x05000100);
    *(u32 *)cli->unk14 = word;
    mevent_srv_sub_init_send(&cli->sub, a, cli->unk14, 4);
}

u32 mainseq_0(void *data)
{
    struct MeventClientData *cli = data;

    memcpy(cli->unk1C, gUnknown_82C4B6C, 0x400);
    cli->unk10 = 0;
    cli->unk8 = 4;
    cli->unkC = 0;
    return 0;
}

u32 mainseq_1(void *data)
{
    return 6;
}

u32 mainseq_2(void *data)
{
    struct MeventClientData *cli = data;

    if (mevent_srv_sub_recv(&cli->sub))
    {
        cli->unk8 = 4;
        cli->unkC = 0;
    }
    return 1;
}

u32 mainseq_3(void *data)
{
    struct MeventClientData *cli = data;

    if (mevent_srv_sub_send(&cli->sub))
    {
        cli->unk8 = 4;
        cli->unkC = 0;
    }
    return 1;
}

u32 mevent_client_exec(void *data)
{
    struct MeventClientData *cli = data;
    u32 (*funcs[8])(void *);

    memcpy(funcs, gUnknown_82C4B34, sizeof(funcs));
    return funcs[cli->unk8](data);
}
