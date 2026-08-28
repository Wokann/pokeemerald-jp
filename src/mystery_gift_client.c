#include "global.h"
#include "malloc.h"
#include "decompress.h"
#include "overworld.h"
#include "script.h"
#include "battle_tower.h"
#include "mystery_gift.h"
#include "mystery_event_script.h"
#include "mystery_gift_client.h"

enum
{
    FUNC_INIT,
    FUNC_DONE,
    FUNC_RECV,
    FUNC_SEND,
    FUNC_RUN,
    FUNC_WAIT,
    FUNC_RUN_MEVENT,
    FUNC_RUN_BUFFER,
};

struct MeventClientData
{
    u32 unk0;
    u32 result;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    struct MysteryGiftLink sub;
    u32 unk4C;
};

extern EWRAM_DATA struct MeventClientData *gUnknown_2022934;
extern u32 (*const gMeventServerClientFuncs[])(void *);
extern const u8 gMeventServerClientInitData[];

void mevent_srv_sub_init(struct MysteryGiftLink *sub, s32 a, s32 b);
u32 mevent_srv_sub_recv(struct MysteryGiftLink *sub);
u32 mevent_srv_sub_send(struct MysteryGiftLink *sub);
void mevent_client_init(void *data, s32 a, s32 b);
u32 mevent_client_exec(void *data);
void mevent_client_free_resources(void *data);

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
    MysteryGiftLink_InitSend(&cli->sub, a, cli->unk14, 4);
}

u32 mainseq_0(void *data)
{
    struct MeventClientData *cli = data;

    memcpy(cli->unk1C, gMeventServerClientInitData, 0x400);
    cli->unk10 = 0;
    cli->unk8 = 4;
    cli->unkC = 0;
    return 0;
}

u32 Client_Done(void *data)
{
    return 6;
}

u32 Client_Recv(void *data)
{
    struct MeventClientData *cli = data;

    if (mevent_srv_sub_recv(&cli->sub))
    {
        cli->unk8 = 4;
        cli->unkC = 0;
    }
    return 1;
}

u32 Client_Send(void *data)
{
    struct MeventClientData *cli = data;

    if (mevent_srv_sub_send(&cli->sub))
    {
        cli->unk8 = 4;
        cli->unkC = 0;
    }
    return 1;
}

u32 mainseq_4(void *data)
{
    struct MeventClientData *cli = data;
    struct MysteryGiftClientCmd *cmd = &((struct MysteryGiftClientCmd *)cli->unk1C)[cli->unk10];

    cli->unk10++;
    switch (cmd->instr)
    {
    case CLI_NONE:
        break;
    case CLI_RETURN:
        cli->result = cmd->parameter;
        cli->unk8 = FUNC_DONE;
        cli->unkC = 0;
        break;
    case CLI_RECV:
        MysteryGiftLink_InitRecv(&cli->sub, cmd->parameter, cli->unk18);
        cli->unk8 = FUNC_RECV;
        cli->unkC = 0;
        break;
    case CLI_SEND_LOADED:
        cli->unk8 = FUNC_SEND;
        cli->unkC = 0;
        break;
    case CLI_SEND_READY_END:
        MysteryGiftLink_InitSend(&cli->sub, 0x14, cli->unk14, 0);
        cli->unk8 = FUNC_SEND;
        cli->unkC = 0;
        break;
    case CLI_SEND_STAT:
        mevent_client_send_word(cli, 0x12, GetGameStat(cmd->parameter));
        cli->unk8 = FUNC_SEND;
        cli->unkC = 0;
        break;
    case CLI_COPY_RECV_IF_N:
        if (cli->result == FALSE)
            mevent_client_jmp_buffer(cli);
        break;
    case CLI_COPY_RECV_IF:
        if (cli->result == TRUE)
            mevent_client_jmp_buffer(cli);
        break;
    case CLI_COPY_RECV:
        mevent_client_jmp_buffer(cli);
        break;
    case CLI_YES_NO:
        memcpy(cli->unk20, cli->unk18, 0x40);
        cli->unk8 = FUNC_WAIT;
        cli->unkC = 0;
        return CLI_RET_YES_NO;
    case CLI_PRINT_MSG:
        memcpy(cli->unk20, cli->unk18, 0x40);
        cli->unk8 = FUNC_WAIT;
        cli->unkC = 0;
        return CLI_RET_PRINT_MSG;
    case CLI_COPY_MSG:
        memcpy(cli->unk20, cli->unk18, 0x40);
        cli->unk8 = FUNC_WAIT;
        cli->unkC = 0;
        return CLI_RET_COPY_MSG;
    case CLI_ASK_TOSS:
        cli->unk8 = FUNC_WAIT;
        cli->unkC = 0;
        return CLI_RET_ASK_TOSS;
    case CLI_LOAD_GAME_DATA:
        MysteryGift_LoadLinkGameData(cli->unk14, cli->unk4C);
        MysteryGiftLink_InitSend(&cli->sub, 0x11, cli->unk14, 0x64);
        break;
    case CLI_LOAD_TOSS_RESPONSE:
        mevent_client_send_word(cli, 0x13, cli->result);
        break;
    case CLI_SAVE_CARD:
        SaveWonderCard(cli->unk18);
        break;
    case CLI_SAVE_NEWS:
        if (!IsWonderNewsSameAsSaved(cli->unk18))
        {
            SaveWonderNews(cli->unk18);
            mevent_client_send_word(cli, 0x13, FALSE);
        }
        else
        {
            mevent_client_send_word(cli, 0x13, TRUE);
        }
        break;
    case CLI_RUN_MEVENT_SCRIPT:
        cli->unk8 = FUNC_RUN_MEVENT;
        cli->unkC = 0;
        break;
    case CLI_SAVE_STAMP:
        MysteryGift_TrySaveStamp(cli->unk18);
        break;
    case CLI_SAVE_RAM_SCRIPT:
        InitRamScript_NoObjectEvent(cli->unk18, sizeof(struct RamScriptData));
        break;
    case CLI_RECV_EREADER_TRAINER:
        memcpy(&gSaveBlock2Ptr->frontier.ereaderTrainer, cli->unk18, sizeof(gSaveBlock2Ptr->frontier.ereaderTrainer));
        ValidateEReaderTrainer();
        break;
    case CLI_RUN_BUFFER_SCRIPT:
        memcpy(gDecompressionBuffer, cli->unk18, 0x400);
        cli->unk8 = FUNC_RUN_BUFFER;
        cli->unkC = 0;
        break;
    }

    return CLI_RET_ACTIVE;
}

u32 Client_Wait(struct MysteryGiftClient *client)
{
    if (client->funcState)
    {
        client->funcId = FUNC_RUN;
        client->funcState = 0;
    }
    return CLI_RET_ACTIVE;
}

u32 mainseq_6(void *data)
{
    struct MeventClientData *cli = data;

    switch (cli->unkC)
    {
    case 0:
        InitMysteryEventScriptContext(cli->unk18);
        cli->unkC++;
        break;
    case 1:
        if (!RunMysteryEventScriptContextCommand(&cli->result))
        {
            cli->unk8 = FUNC_RUN;
            cli->unkC = 0;
        }
        break;
    }
    return CLI_RET_ACTIVE;
}

u32 mainseq_7(void *data)
{
    struct MeventClientData *cli = data;
    u32 (*func)(u32 *, struct SaveBlock2 *, struct SaveBlock1 *) = (void *)gDecompressionBuffer;

    if (func(&cli->result, gSaveBlock2Ptr, gSaveBlock1Ptr) == 1)
    {
        cli->unk8 = FUNC_RUN;
        cli->unkC = 0;
    }
    return CLI_RET_ACTIVE;
}

u32 mevent_client_exec(void *data)
{
    struct MeventClientData *cli = data;
    u32 (*funcs[8])(void *);

    memcpy(funcs, gMeventServerClientFuncs, sizeof(funcs));
    return funcs[cli->unk8](data);
}
