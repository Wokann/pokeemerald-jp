#include "global.h"
#include "list_menu.h"

// Mystery-news graphics table and mevent-server data
// (0x82C49F4..0x82C4B6C)

extern const u32 sWonderNewsGfx1[], sWonderNewsGfx2[], sWonderNewsGfx3[], sWonderNewsGfx7[], sWonderNewsGfx8[];
extern const u32 sWonderNewsTilemap1[], sWonderNewsTilemap2[], sWonderNewsTilemap3[], sWonderNewsTilemap7[], sWonderNewsTilemap8[];
extern const u16 sWonderCardBgPal2[], sWonderCardBgPal3[], sWonderCardBgPal4[], sWonderCardBgPal5[], sWonderCardBgPal6[];
extern const u16 sWonderNewsPal1[], sWonderNewsPal7[], sWonderNewsPal8[];
extern u32 Server_Init(void *), Server_Done(void *), common_mainseq_2(void *), common_mainseq_3(void *), common_mainseq_4(void *);
extern u32 mainseq_0(void *), Client_Done(void *), Client_Recv(void *), Client_Send(void *), mainseq_4(void *), Client_Wait(void *), mainseq_6(void *), mainseq_7(void *);

struct WonderGfx
{
    u8 titleTextPal:4;
    u8 bodyTextPal:4;
    u8 footerTextPal:4;
    u8 stampShadowPal:4;
    const u32 *tiles;
    const u32 *map;
    const u16 *pal;
};

// 0x82C49F4
const struct WonderGfx sNewsGraphics[] = {
    { .titleTextPal = 1, .bodyTextPal = 0, .tiles = sWonderNewsGfx1, .map = sWonderNewsTilemap1, .pal = sWonderNewsPal1 },
    { .titleTextPal = 1, .bodyTextPal = 0, .tiles = sWonderNewsGfx2, .map = sWonderNewsTilemap2, .pal = sWonderCardBgPal2 },
    { .titleTextPal = 1, .bodyTextPal = 0, .tiles = sWonderNewsGfx3, .map = sWonderNewsTilemap3, .pal = sWonderCardBgPal3 },
    { .titleTextPal = 1, .bodyTextPal = 0, .tiles = sWonderNewsGfx3, .map = sWonderNewsTilemap3, .pal = sWonderCardBgPal4 },
    { .titleTextPal = 1, .bodyTextPal = 0, .tiles = sWonderNewsGfx3, .map = sWonderNewsTilemap3, .pal = sWonderCardBgPal5 },
    { .titleTextPal = 1, .bodyTextPal = 0, .tiles = sWonderNewsGfx3, .map = sWonderNewsTilemap3, .pal = sWonderCardBgPal6 },
    { .titleTextPal = 1, .bodyTextPal = 0, .tiles = sWonderNewsGfx7, .map = sWonderNewsTilemap7, .pal = sWonderNewsPal7 },
    { .titleTextPal = 1, .bodyTextPal = 0, .tiles = sWonderNewsGfx8, .map = sWonderNewsTilemap8, .pal = sWonderNewsPal8 },
};

// 0x82C4A74
const char gMeventServerAssertFile[16] = {"mevent_server.c"};

// 0x82C4A84
const char gMeventServerAssertExpr0[28] = {"size <= ME_SEND_BUF_SIZE"};

// 0x82C4AA0
const char gMeventServerAssertExpr1[24] = {"cmd->parameter == NULL"};

// 0x82C4AB8
const char gMeventServerAssertExpr2[20] = {"cmd->flag == FALSE"};

// 0x82C4ACC
const char gMeventServerAssertExpr3[48] = {"cmd->flag == FALSE && cmd->parameter == NULL"};

// 0x82C4AFC
u32 (*const gMeventServerFuncs[])(void *) = {
    Server_Init,
    Server_Done,
    common_mainseq_2,
    common_mainseq_3,
    common_mainseq_4,
};

// 0x82C4B10
const char gMeventServerAssertExpr4[36] = {"svr->mainseqno < NELEMS(func_tbl)"};

// 0x82C4B34
u32 (*const gMeventServerClientFuncs[])(void *) = {
    mainseq_0,
    Client_Done,
    Client_Recv,
    Client_Send,
    mainseq_4,
    Client_Wait,
    mainseq_6,
    mainseq_7,
};

// 0x82C4B54: "カードの　よみこみを\nキャンセル　しました$　　"
const u8 sMeventServerCancelReadText[24] = { 0x56, 0xAE, 0x95, 0x19, 0x00, 0x26, 0x20, 0x0A, 0x20, 0x2D, 0xFE, 0x57, 0x84, 0x7E, 0x5E, 0x79, 0x00, 0x0C, 0x1F, 0x0C, 0x10, 0xFF, 0x00, 0x00 };
