#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "pokenav.h"
#include "strings.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"


// NPC below means non-trainer character (no rematch or check page)
// Steven also uses this type but has a check page by using a MatchCallCheckPageOverride
enum
{
    MC_TYPE_NPC,
    MC_TYPE_TRAINER,
    MC_TYPE_WALLY,
    MC_TYPE_BIRCH,
    MC_TYPE_RIVAL,
    MC_TYPE_LEADER
};

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 availabilityFlag;
    u16 flagToSetOnCompletion;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    mapsec_u8_t mapSec;
    u16 flag;
};

struct MatchCallStructNPC {
    u8 type;
    mapsec_u8_t mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

// Shared by MC_TYPE_TRAINER and MC_TYPE_LEADER
struct MatchCallStructTrainer {
    u8 type;
    mapsec_u8_t mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallLocationOverride {
    u16 flag;
    mapsec_u8_t mapSec;
};

struct MatchCallWally {
    u8 type;
    mapsec_u8_t mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallLocationOverride *locationData;
};

struct MatchCallBirch {
    u8 type;
    mapsec_u8_t mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallRival {
    u8 type;
    u8 playerGender;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStructNPC *npc;
    const struct MatchCallStructTrainer *trainer;
    const struct MatchCallWally *wally;
    const struct MatchCallBirch *birch;
    const struct MatchCallRival *rival;
    const struct MatchCallStructTrainer *leader;
} match_call_t;

struct MatchCallCheckPageOverride {
    u16 idx;
    u16 facilityClass;
    u32 flag;
    const u8 *flavorTexts[CHECK_PAGE_ENTRY_COUNT];
};

// Static RAM declarations

// Static ROM declarations

static bool32 MatchCall_GetEnabled_NPC(match_call_t);
static bool32 MatchCall_GetEnabled_Trainer(match_call_t);
static bool32 MatchCall_GetEnabled_Wally(match_call_t);
static bool32 MatchCall_GetEnabled_Birch(match_call_t);
static bool32 MatchCall_GetEnabled_Rival(match_call_t);

static mapsec_u8_t MatchCall_GetMapSec_NPC(match_call_t);
static mapsec_u8_t MatchCall_GetMapSec_Trainer(match_call_t);
static mapsec_u8_t MatchCall_GetMapSec_Wally(match_call_t);
static mapsec_u8_t MatchCall_GetMapSec_Birch(match_call_t);
static mapsec_u8_t MatchCall_GetMapSec_Rival(match_call_t);

static bool32 MatchCall_IsRematchable_NPC(match_call_t);
static bool32 MatchCall_IsRematchable_Trainer(match_call_t);
static bool32 MatchCall_IsRematchable_Wally(match_call_t);
static bool32 MatchCall_IsRematchable_Birch(match_call_t);
static bool32 MatchCall_IsRematchable_Rival(match_call_t);

static bool32 MatchCall_HasCheckPage_NPC(match_call_t);
static bool32 MatchCall_HasCheckPage_Trainer(match_call_t);
static bool32 MatchCall_HasCheckPage_Wally(match_call_t);
static bool32 MatchCall_HasCheckPage_Birch(match_call_t);
static bool32 MatchCall_HasCheckPage_Rival(match_call_t);

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Wally(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Birch(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t);

static void MatchCall_GetMessage_NPC(match_call_t, u8 *);
static void MatchCall_GetMessage_Trainer(match_call_t, u8 *);
static void MatchCall_GetMessage_Wally(match_call_t, u8 *);
static void MatchCall_GetMessage_Birch(match_call_t, u8 *);
static void MatchCall_GetMessage_Rival(match_call_t, u8 *);

static void MatchCall_GetNameAndDesc_NPC(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Trainer(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Wally(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Birch(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Rival(match_call_t, const u8 **, const u8 **);

static void sub_081D103C(const match_call_text_data_t *, u8 *);
static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx(u32, const u8 **, const u8 **);

// Special flag ID that indicates the start of a section of match calls
// related to a gym leader's rematch. It's expected that there will be
// exactly 3 calls after the call associated with this flag, with text
// that follows this format:
// - Call 1: A basic 'preparing for a rematch' call.
//           Remains active until the player beats the game (FLAG_SYS_GAME_CLEAR).
// - Call 2: Congratulating the player on their success, still preparing.
//           Remains active until the gym leader is ready for a rematch.
// - Call 3: Requesting the rematch. Active whenever the gym leader is ready.
// - Call 4: Expressing their admiration of the player. Active after defeating
//           them in a rematch and if they're not ready yet for another battle.
#define REMATCH_CALL_START 0xFFFE

#define ALWAYS_AVAILABLE 0xFFFF
#define NO_FLAG_TO_SET   0xFFFF
#define MATCH_CALL_TEXT_END {NULL, ALWAYS_AVAILABLE, NO_FLAG_TO_SET}

// .rodata

#define MATCH_CALL_STRUCT_DATA __attribute__((section(".rodata.match_call_struct_data")))

static const u8 sText_MrStoneMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("デボンしゃちょう");
static const u8 sText_MrStoneMatchCallName[] MATCH_CALL_STRUCT_DATA = _("ツワブキ");
static const u8 sText_StevenMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("いしがかたいひと");
static const u8 sText_StevenMatchCallName[] MATCH_CALL_STRUCT_DATA = _("ダイゴ");
static const u8 sText_RivalMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("おとなりさん");
static const u8 sText_NormanMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("つよくてたのもしい");
static const u8 sText_MomMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("やさしくてきれい");
static const u8 sText_WallyMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("ポケモンがだいすき");
static const u8 sText_NormanMatchCallName[] MATCH_CALL_STRUCT_DATA = _("パパ");
static const u8 sText_MomMatchCallName[] MATCH_CALL_STRUCT_DATA = _("ママ");
static const u8 sText_ScottMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("しんしゅつきぼつ");
static const u8 sText_ScottMatchCallName[] MATCH_CALL_STRUCT_DATA = _("エニシダ");
static const u8 sText_RoxanneMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("いわのゆうとうせい");
static const u8 sText_BrawlyMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("ビッグなウェーブ");
static const u8 sText_WattsonMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("でんげきおやじ");
static const u8 sText_FlanneryMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("じょうねつのひと");
static const u8 sText_WinonaMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("せかいのとりつかい");
static const u8 sText_TateLizaMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("しんぴてきなコンビ");
static const u8 sText_JuanMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("みわくのダンディ");
static const u8 sText_EliteFourMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("してんのう");
static const u8 sText_ChampionMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("チャンピオン");
static const u8 sText_ProfBirchMatchCallDesc[] MATCH_CALL_STRUCT_DATA = _("ポケモンはかせ");

static const match_call_text_data_t sMrStoneTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826C287, 0xFFFF, 0x0158},
    {(const u8 *)0x0826C35D, 0x0158, 0xFFFF},
    {(const u8 *)0x0826C400, 0x00BD, 0xFFFF},
    {(const u8 *)0x0826C465, 0x0110, 0xFFFF},
    {(const u8 *)0x0826C4FB, 0x006A, 0xFFFF},
    {(const u8 *)0x0826C547, 0x04F4, 0xFFFF},
    {(const u8 *)0x0826C5A4, 0x0097, 0xFFFF},
    {(const u8 *)0x0826C616, 0x006F, 0xFFFF},
    {(const u8 *)0x0826C64D, 0x0070, 0xFFFF},
    {(const u8 *)0x0826C687, 0x04F7, 0xFFFF},
    {(const u8 *)0x0826C707, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructNPC sMrStoneMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 0,
    .mapSec = 10,
    .flag = 0xFFFF,
    .desc = sText_MrStoneMatchCallDesc,
    .name = sText_MrStoneMatchCallName,
    .textData = sMrStoneTextScripts,
};

static const match_call_text_data_t sNormanTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826BCF0, 0x0132, 0xFFFF},
    {(const u8 *)0x0826BD3E, 0x04F1, 0xFFFF},
    {(const u8 *)0x0826BDA8, 0x04F3, 0xFFFF},
    {(const u8 *)0x0826BDEC, 0x04F4, 0xFFFF},
    {(const u8 *)0x0826BE3E, 0x00D4, 0xFFFF},
    {(const u8 *)0x0826BE92, 0xFFFE, 0xFFFF},
    {(const u8 *)0x0826BED3, 0x0864, 0xFFFF},
    {(const u8 *)0x0826BF0E, 0x0864, 0xFFFF},
    {(const u8 *)0x0826BF6C, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sNormanMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 7,
    .flag = 0x0132,
    .rematchTableIdx = 0x0045,
    .desc = sText_NormanMatchCallDesc,
    .name = sText_NormanMatchCallName,
    .textData = sNormanTextScripts,
};

static const struct MatchCallBirch sProfBirchMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 3,
    .mapSec = 0,
    .flag = 0x0119,
    .desc = sText_ProfBirchMatchCallDesc,
    .name = (const u8 *)0x085C8C6B,
};

static const match_call_text_data_t sMomTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x08269D8F, 0xFFFF, 0xFFFF},
    {(const u8 *)0x08269DF1, 0x04F4, 0xFFFF},
    {(const u8 *)0x08269E62, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructNPC sMomMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 0,
    .mapSec = 0,
    .flag = 0x00D8,
    .desc = sText_MomMatchCallDesc,
    .name = sText_MomMatchCallName,
    .textData = sMomTextScripts,
};

static const match_call_text_data_t sStevenTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826BF8E, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826C00A, 0x00C7, 0xFFFF},
    {(const u8 *)0x0826C05E, 0x00D4, 0xFFFF},
    {(const u8 *)0x0826C0D6, 0x0070, 0xFFFF},
    {(const u8 *)0x0826C118, 0x04F6, 0xFFFF},
    {(const u8 *)0x0826C151, 0x0081, 0xFFFF},
    {(const u8 *)0x0826C174, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructNPC sStevenMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 0,
    .mapSec = 213,
    .flag = 0x0131,
    .desc = sText_StevenMatchCallDesc,
    .name = sText_StevenMatchCallName,
    .textData = sStevenTextScripts,
};

static const match_call_text_data_t sMayTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826AC61, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826ACBD, 0x04F1, 0xFFFF},
    {(const u8 *)0x0826AD30, 0x0095, 0xFFFF},
    {(const u8 *)0x0826ADB8, 0x0324, 0xFFFF},
    {(const u8 *)0x0826ADF2, 0x006A, 0xFFFF},
    {(const u8 *)0x0826AE48, 0x04F3, 0xFFFF},
    {(const u8 *)0x0826AEA2, 0x04F4, 0xFFFF},
    {(const u8 *)0x0826AEFF, 0x0097, 0xFFFF},
    {(const u8 *)0x0826AF50, 0x00D4, 0xFFFF},
    {(const u8 *)0x0826AFB3, 0x006F, 0xFFFF},
    {(const u8 *)0x0826AFF8, 0x0061, 0xFFFF},
    {(const u8 *)0x0826B066, 0x0070, 0xFFFF},
    {(const u8 *)0x0826B0CD, 0x0081, 0xFFFF},
    {(const u8 *)0x0826B149, 0x04F7, 0xFFFF},
    {(const u8 *)0x0826B184, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallRival sMayMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 4,
    .playerGender = 0,
    .flag = 0x00FD,
    .desc = sText_RivalMatchCallDesc,
    .name = (const u8 *)0x085C8C5E,
    .textData = sMayTextScripts,
};

static const match_call_text_data_t sBrendanTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826B1D9, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826B236, 0x04F1, 0xFFFF},
    {(const u8 *)0x0826B2A4, 0x0095, 0xFFFF},
    {(const u8 *)0x0826B329, 0x0324, 0xFFFF},
    {(const u8 *)0x0826B36F, 0x006A, 0xFFFF},
    {(const u8 *)0x0826B3DC, 0x04F3, 0xFFFF},
    {(const u8 *)0x0826B433, 0x04F4, 0xFFFF},
    {(const u8 *)0x0826B48A, 0x0097, 0xFFFF},
    {(const u8 *)0x0826B4DC, 0x00D4, 0xFFFF},
    {(const u8 *)0x0826B541, 0x006F, 0xFFFF},
    {(const u8 *)0x0826B585, 0x0061, 0xFFFF},
    {(const u8 *)0x0826B600, 0x0070, 0xFFFF},
    {(const u8 *)0x0826B666, 0x0081, 0xFFFF},
    {(const u8 *)0x0826B6E9, 0x04F7, 0xFFFF},
    {(const u8 *)0x0826B721, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallRival sBrendanMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 4,
    .playerGender = 1,
    .flag = 0x00FD,
    .desc = sText_RivalMatchCallDesc,
    .name = (const u8 *)0x085C8C5A,
    .textData = sBrendanTextScripts,
};

static const match_call_text_data_t sWallyTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826B773, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826B7BF, 0x00C7, 0xFFFF},
    {(const u8 *)0x0826B7FF, 0x04F3, 0xFFFF},
    {(const u8 *)0x0826B85D, 0x0097, 0xFFFF},
    {(const u8 *)0x0826B8D1, 0x006F, 0xFFFF},
    {(const u8 *)0x0826B942, 0x0081, 0xFFFF},
    {(const u8 *)0x0826B978, 0x007E, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallLocationOverride sWallyLocationData[] MATCH_CALL_STRUCT_DATA =
{
    {0x0324, 5},
    {0x006F, 213},
    {0x035A, 70},
    {0xFFFF, 213},
};

static const struct MatchCallWally sWallyMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 2,
    .mapSec = 0,
    .flag = 0x00D6,
    .rematchTableIdx = 0x0040,
    .desc = sText_WallyMatchCallDesc,
    .textData = sWallyTextScripts,
    .locationData = sWallyLocationData,
};

static const match_call_text_data_t sScottTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826B9D0, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826BA50, 0x008B, 0xFFFF},
    {(const u8 *)0x0826BAC4, 0x0097, 0xFFFF},
    {(const u8 *)0x0826BB36, 0x00D4, 0xFFFF},
    {(const u8 *)0x0826BBA2, 0x0070, 0xFFFF},
    {(const u8 *)0x0826BBFE, 0x04F7, 0xFFFF},
    {(const u8 *)0x0826BCB9, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructNPC sScottMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 0,
    .mapSec = 213,
    .flag = 0x00D7,
    .desc = sText_ScottMatchCallDesc,
    .name = sText_ScottMatchCallName,
    .textData = sScottTextScripts,
};

static const match_call_text_data_t sRoxanneTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x08269EA8, 0xFFFE, 0xFFFF},
    {(const u8 *)0x08269F24, 0xFFFF, 0xFFFF},
    {(const u8 *)0x08269F8E, 0xFFFF, 0xFFFF},
    {(const u8 *)0x08269FC2, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sRoxanneMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 10,
    .flag = 0x01D3,
    .rematchTableIdx = 0x0041,
    .desc = sText_RoxanneMatchCallDesc,
    .name = NULL,
    .textData = sRoxanneTextScripts,
};

static const match_call_text_data_t sBrawlyTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x08269FE9, 0xFFFE, 0xFFFF},
    {(const u8 *)0x0826A07E, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A11E, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A156, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sBrawlyMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 2,
    .flag = 0x01D4,
    .rematchTableIdx = 0x0042,
    .desc = sText_BrawlyMatchCallDesc,
    .name = NULL,
    .textData = sBrawlyTextScripts,
};

static const match_call_text_data_t sWattsonTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A176, 0xFFFE, 0xFFFF},
    {(const u8 *)0x0826A1EB, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A280, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A2C0, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sWattsonMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 9,
    .flag = 0x01D5,
    .rematchTableIdx = 0x0043,
    .desc = sText_WattsonMatchCallDesc,
    .name = NULL,
    .textData = sWattsonTextScripts,
};

static const match_call_text_data_t sFlanneryTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A2EF, 0xFFFE, 0xFFFF},
    {(const u8 *)0x0826A377, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A3FC, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A43E, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sFlanneryMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 3,
    .flag = 0x01D6,
    .rematchTableIdx = 0x0044,
    .desc = sText_FlanneryMatchCallDesc,
    .name = NULL,
    .textData = sFlanneryTextScripts,
};

static const match_call_text_data_t sWinonaTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A46B, 0xFFFE, 0xFFFF},
    {(const u8 *)0x0826A4C7, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A527, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A557, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sWinonaMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 11,
    .flag = 0x01D7,
    .rematchTableIdx = 0x0046,
    .desc = sText_WinonaMatchCallDesc,
    .name = NULL,
    .textData = sWinonaTextScripts,
};

static const match_call_text_data_t sTateLizaTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A5A4, 0xFFFE, 0xFFFF},
    {(const u8 *)0x0826A633, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A6BD, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A716, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sTateLizaMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 13,
    .flag = 0x01D8,
    .rematchTableIdx = 0x0047,
    .desc = sText_TateLizaMatchCallDesc,
    .name = NULL,
    .textData = sTateLizaTextScripts,
};

static const match_call_text_data_t sJuanTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A75D, 0xFFFE, 0xFFFF},
    {(const u8 *)0x0826A7CD, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A82E, 0xFFFF, 0xFFFF},
    {(const u8 *)0x0826A87D, 0x0864, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sJuanMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 14,
    .flag = 0x01D9,
    .rematchTableIdx = 0x0048,
    .desc = sText_JuanMatchCallDesc,
    .name = NULL,
    .textData = sJuanTextScripts,
};

static const match_call_text_data_t sSidneyTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A8E9, 0xFFFF, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sSidneyMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 15,
    .flag = 0x01A5,
    .rematchTableIdx = 0x0049,
    .desc = sText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sSidneyTextScripts,
};

static const match_call_text_data_t sPhoebeTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A93A, 0xFFFF, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sPhoebeMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 15,
    .flag = 0x01A6,
    .rematchTableIdx = 0x004A,
    .desc = sText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sPhoebeTextScripts,
};

static const match_call_text_data_t sGlaciaTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A979, 0xFFFF, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sGlaciaMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 15,
    .flag = 0x01A7,
    .rematchTableIdx = 0x004B,
    .desc = sText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sGlaciaTextScripts,
};

static const match_call_text_data_t sDrakeTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826A9D4, 0xFFFF, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sDrakeMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 15,
    .flag = 0x01A8,
    .rematchTableIdx = 0x004C,
    .desc = sText_EliteFourMatchCallDesc,
    .name = NULL,
    .textData = sDrakeTextScripts,
};

static const match_call_text_data_t sWallaceTextScripts[] MATCH_CALL_STRUCT_DATA =
{
    {(const u8 *)0x0826AA64, 0xFFFF, 0xFFFF},
    MATCH_CALL_TEXT_END
};

static const struct MatchCallStructTrainer sWallaceMatchCallHeader MATCH_CALL_STRUCT_DATA =
{
    .type = 5,
    .mapSec = 15,
    .flag = 0x01A9,
    .rematchTableIdx = 0x004D,
    .desc = sText_ChampionMatchCallDesc,
    .name = NULL,
    .textData = sWallaceTextScripts,
};

static const match_call_t sMatchCallHeaders[] MATCH_CALL_STRUCT_DATA =
{
    [0] = {.npc = &sMrStoneMatchCallHeader},
    [1] = {.birch = &sProfBirchMatchCallHeader},
    [2] = {.rival = &sBrendanMatchCallHeader},
    [3] = {.rival = &sMayMatchCallHeader},
    [4] = {.wally = &sWallyMatchCallHeader},
    [5] = {.leader = &sNormanMatchCallHeader},
    [6] = {.npc = &sMomMatchCallHeader},
    [7] = {.npc = &sStevenMatchCallHeader},
    [8] = {.npc = &sScottMatchCallHeader},
    [9] = {.leader = &sRoxanneMatchCallHeader},
    [10] = {.leader = &sBrawlyMatchCallHeader},
    [11] = {.leader = &sWattsonMatchCallHeader},
    [12] = {.leader = &sFlanneryMatchCallHeader},
    [13] = {.leader = &sWinonaMatchCallHeader},
    [14] = {.leader = &sTateLizaMatchCallHeader},
    [15] = {.leader = &sJuanMatchCallHeader},
    [16] = {.leader = &sSidneyMatchCallHeader},
    [17] = {.leader = &sPhoebeMatchCallHeader},
    [18] = {.leader = &sGlaciaMatchCallHeader},
    [19] = {.leader = &sDrakeMatchCallHeader},
    [20] = {.leader = &sWallaceMatchCallHeader},
};

#define MATCH_CALL_CHECK_PAGE_OVERRIDES __attribute__((section(".rodata.match_call_check_page_overrides")))

static const struct MatchCallCheckPageOverride sCheckPageOverrides[] MATCH_CALL_CHECK_PAGE_OVERRIDES =
{
    {
        .idx = 7,
        .facilityClass = 75,
        .flag = 0x0000FFFF,
        .flavorTexts =
        {
            (const u8 *)0x085CC79E,
            (const u8 *)0x085CC7AE,
            (const u8 *)0x085CC7BD,
            (const u8 *)0x085CC7CC,
        },
    },
    {
        .idx = 7,
        .facilityClass = 75,
        .flag = 0x000004F6,
        .flavorTexts =
        {
            (const u8 *)0x085CC79E,
            (const u8 *)0x085CC7AE,
            (const u8 *)0x085CC7DB,
            (const u8 *)0x085CC7EA,
        },
    },
    {
        .idx = 2,
        .facilityClass = 60,
        .flag = 0x0000FFFF,
        .flavorTexts =
        {
            (const u8 *)0x085CC7F7,
            (const u8 *)0x085CC807,
            (const u8 *)0x085CC817,
            (const u8 *)0x085CC827,
        },
    },
    {
        .idx = 3,
        .facilityClass = 63,
        .flag = 0x0000FFFF,
        .flavorTexts =
        {
            (const u8 *)0x085CC836,
            (const u8 *)0x085CC846,
            (const u8 *)0x085CC856,
            (const u8 *)0x085CC866,
        },
    },
};

#define MATCH_CALL_DISPATCH_TABLES __attribute__((section(".rodata.match_call_dispatch_tables")))

static bool32 (*const sMatchCallGetEnabledFuncs[])(match_call_t) MATCH_CALL_DISPATCH_TABLES =
{
    MatchCall_GetEnabled_NPC, MatchCall_GetEnabled_Trainer, MatchCall_GetEnabled_Wally,
    MatchCall_GetEnabled_Rival, MatchCall_GetEnabled_Birch,
};
static mapsec_u8_t (*const sMatchCallGetMapSecFuncs[])(match_call_t) MATCH_CALL_DISPATCH_TABLES =
{
    MatchCall_GetMapSec_NPC, MatchCall_GetMapSec_Trainer, MatchCall_GetMapSec_Wally,
    MatchCall_GetMapSec_Rival, MatchCall_GetMapSec_Birch,
};
static bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t) MATCH_CALL_DISPATCH_TABLES =
{
    MatchCall_IsRematchable_Birch, MatchCall_IsRematchable_Trainer, MatchCall_IsRematchable_Wally,
    MatchCall_IsRematchable_Rival, MatchCall_HasCheckPage_NPC,
};
static bool32 (*const sMatchCall_HasCheckPageFunctions[])(match_call_t) MATCH_CALL_DISPATCH_TABLES =
{
    MatchCall_HasCheckPage_Trainer, MatchCall_HasCheckPage_Wally, MatchCall_HasCheckPage_Rival,
    MatchCall_HasCheckPage_Birch, MatchCall_IsRematchable_NPC,
};
static u32 (*const sMatchCall_GetRematchTableIdxFunctions[])(match_call_t) MATCH_CALL_DISPATCH_TABLES =
{
    MatchCall_GetRematchTableIdx_Birch, MatchCall_GetRematchTableIdx_Trainer,
    MatchCall_GetRematchTableIdx_Wally, MatchCall_GetRematchTableIdx_Rival,
    MatchCall_GetRematchTableIdx_NPC,
};
static void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *) MATCH_CALL_DISPATCH_TABLES =
{
    MatchCall_GetMessage_NPC, MatchCall_GetMessage_Trainer, MatchCall_GetMessage_Wally,
    MatchCall_GetMessage_Rival, MatchCall_GetMessage_Birch,
};
static void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **) MATCH_CALL_DISPATCH_TABLES =
{
    MatchCall_GetNameAndDesc_Birch, MatchCall_GetNameAndDesc_Trainer,
    MatchCall_GetNameAndDesc_Wally, MatchCall_GetNameAndDesc_Rival,
    MatchCall_GetNameAndDesc_NPC,
};
extern void sub_08196C74(u8 *dest);


// JP builds this as a jump table with a trailing 2-byte .align that the
// Makefile pipeline does not emit between functions; kept as naked asm.
static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        default:
        case MC_TYPE_NPC:
            return 0;
        case MC_TYPE_TRAINER:
        case MC_TYPE_LEADER:
            return 1;
        case MC_TYPE_WALLY:
            return 2;
        case MC_TYPE_RIVAL:
            return 3;
        case MC_TYPE_BIRCH:
            return 4;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}
s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}
bool32 MatchCall_GetEnabled(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetEnabledFuncs[i](matchCall);
}
static bool32 MatchCall_GetEnabled_NPC(match_call_t matchCall)
{
    if (matchCall.npc->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.npc->flag);
}
static bool32 MatchCall_GetEnabled_Trainer(match_call_t matchCall)
{
    if (matchCall.trainer->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.trainer->flag);
}
static bool32 MatchCall_GetEnabled_Wally(match_call_t matchCall)
{
    if (matchCall.wally->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.wally->flag);
}
static bool32 MatchCall_GetEnabled_Rival(match_call_t matchCall)
{
    if (matchCall.rival->playerGender != gSaveBlock2Ptr->playerGender)
        return FALSE;
    if (matchCall.rival->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.rival->flag);
}
static bool32 MatchCall_GetEnabled_Birch(match_call_t matchCall)
{
    return FlagGet(matchCall.birch->flag);
}
mapsec_u8_t MatchCall_GetMapSec(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetMapSecFuncs[i](matchCall);
}
static mapsec_u8_t MatchCall_GetMapSec_NPC(match_call_t matchCall)
{
    return matchCall.npc->mapSec;
}
static mapsec_u8_t MatchCall_GetMapSec_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->mapSec;
}
static mapsec_u8_t MatchCall_GetMapSec_Wally(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.wally->locationData[i].flag != 0xFFFF; i++)
    {
        if (!FlagGet(matchCall.wally->locationData[i].flag))
            break;
    }
    return matchCall.wally->locationData[i].mapSec;
}
static mapsec_u8_t MatchCall_GetMapSec_Rival(match_call_t matchCall)
{
    return MAPSEC_NONE;
}
static mapsec_u8_t MatchCall_GetMapSec_Birch(match_call_t matchCall)
{
    return MAPSEC_NONE;
}
bool32 MatchCall_IsRematchable(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_IsRematchableFunctions[i](matchCall);
}
static bool32 MatchCall_IsRematchable_Birch(match_call_t matchCall)
{
    return FALSE;
}
static bool32 MatchCall_IsRematchable_Trainer(match_call_t matchCall)
{
    if (matchCall.trainer->rematchTableIdx >= REMATCH_ELITE_FOUR_ENTRIES)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.trainer->rematchTableIdx] ? TRUE : FALSE;
}
static bool32 MatchCall_IsRematchable_Wally(match_call_t matchCall)
{
    return gSaveBlock1Ptr->trainerRematches[matchCall.wally->rematchTableIdx] ? TRUE : FALSE;
}
static bool32 MatchCall_IsRematchable_Rival(match_call_t matchCall)
{
    return FALSE;
}
static bool32 MatchCall_HasCheckPage_NPC(match_call_t matchCall)
{
    return FALSE;
}
bool32 MatchCall_HasCheckPage(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    if (sMatchCall_HasCheckPageFunctions[i](matchCall))
        return TRUE;
    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}
static bool32 MatchCall_HasCheckPage_Trainer(match_call_t matchCall)
{
    return FALSE;
}
static bool32 MatchCall_HasCheckPage_Wally(match_call_t matchCall)
{
    return TRUE;
}
static bool32 MatchCall_HasCheckPage_Rival(match_call_t matchCall)
{
    return TRUE;
}
static bool32 MatchCall_HasCheckPage_Birch(match_call_t matchCall)
{
    return FALSE;
}
static bool32 MatchCall_IsRematchable_NPC(match_call_t matchCall)
{
    return FALSE;
}
u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return REMATCH_TABLE_ENTRIES;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_GetRematchTableIdxFunctions[i](matchCall);
}
static u32 MatchCall_GetRematchTableIdx_Birch(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}
static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->rematchTableIdx;
}
static u32 MatchCall_GetRematchTableIdx_Wally(match_call_t matchCall)
{
    return matchCall.wally->rematchTableIdx;
}
static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}
static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}
void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetMessageFunctions[i](matchCall, dest);
}
static void MatchCall_GetMessage_NPC(match_call_t matchCall, u8 *dest)
{
    sub_081D103C(matchCall.npc->textData, dest);
}
static void MatchCall_GetMessage_Trainer(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != MC_TYPE_LEADER)
        sub_081D103C(matchCall.trainer->textData, dest);
    else
        MatchCall_BufferCallMessageTextByRematchTeam(matchCall.leader->textData, matchCall.leader->rematchTableIdx, dest);
}
static void MatchCall_GetMessage_Wally(match_call_t matchCall, u8 *dest)
{
    sub_081D103C(matchCall.wally->textData, dest);
}
static void MatchCall_GetMessage_Rival(match_call_t matchCall, u8 *dest)
{
    sub_081D103C(matchCall.rival->textData, dest);
}
static void MatchCall_GetMessage_Birch(match_call_t matchCall, u8 *dest)
{
    sub_08196C74(dest);
}
static void sub_081D103C(const match_call_text_data_t *textData, u8 *dest)
{
    u32 i;

    for (i = 0; textData[i].text != NULL; i++)
    {
        if (textData[i].availabilityFlag != ALWAYS_AVAILABLE && !FlagGet(textData[i].availabilityFlag))
            break;
    }
    if (i)
        i--;
    if (textData[i].flagToSetOnCompletion != NO_FLAG_TO_SET)
        FlagSet(textData[i].flagToSetOnCompletion);
    StringExpandPlaceholders(dest, textData[i].text);
}

static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *textData, u16 idx, u8 *dest)
{
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
    {
        if (textData[i].availabilityFlag == REMATCH_CALL_START)
            break;
        if (textData[i].availabilityFlag != ALWAYS_AVAILABLE && !FlagGet(textData[i].availabilityFlag))
            break;
    }
    if (textData[i].availabilityFlag != REMATCH_CALL_START)
    {
        if (i)
            i--;
        if (textData[i].flagToSetOnCompletion != NO_FLAG_TO_SET)
            FlagSet(textData[i].flagToSetOnCompletion);
        StringExpandPlaceholders(dest, textData[i].text);
    }
    else
    {
        if (FlagGet(FLAG_SYS_GAME_CLEAR))
        {
            do
            {
                // If the rematch is ready, advance to the rematch call.
                if (gSaveBlock1Ptr->trainerRematches[idx]) i += 2;
                // No rematch ready, but if the player has defeated them in
                // a rematch before, advance to the final call.
                // Note: The 2 "rematch" teams battled includes the first non-rematch battle.
                else if (CountBattledRematchTeams(idx) >= 2) i += 3; 
                // No rematch ready and never defeated in a rematch, advance to congratulations call.
                else i++;
            } while (0);
        }
        // If the game hasn't been cleared yet, the index remains on the basic "preparing for rematch" call.
        StringExpandPlaceholders(dest, textData[i].text);
    }
}
void MatchCall_GetNameAndDesc(u32 idx, const u8 **desc, const u8 **name)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetNameAndDescFunctions[i](matchCall, desc, name);
}
static void MatchCall_GetNameAndDesc_Birch(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.birch->desc;
    *name = matchCall.birch->name;
}
static void MatchCall_GetNameAndDesc_Trainer(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.trainer->name == NULL)
        MatchCall_GetNameAndDescByRematchIdx(_matchCall.trainer->rematchTableIdx, desc, name);
    else
        *name = _matchCall.trainer->name;
    *desc = _matchCall.trainer->desc;
}
static void MatchCall_GetNameAndDesc_Wally(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    MatchCall_GetNameAndDescByRematchIdx(matchCall.wally->rematchTableIdx, desc, name);
    *desc = matchCall.wally->desc;
}
static void MatchCall_GetNameAndDesc_Rival(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.rival->desc;
    *name = matchCall.rival->name;
}
static void MatchCall_GetNameAndDesc_NPC(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.npc->desc;
    *name = matchCall.npc->name;
}
static void MatchCall_GetNameAndDescByRematchIdx(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = gTrainers + GetTrainerIdxByRematchIdx(idx);
    *desc = gTrainerClassNames[trainer->trainerClass];
    *name = trainer->trainerName;
}
const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
        {
            for (; i + 1 < ARRAY_COUNT(sCheckPageOverrides) &&
                sCheckPageOverrides[i + 1].idx == idx &&
                FlagGet(sCheckPageOverrides[i + 1].flag); i++);
            return sCheckPageOverrides[i].flavorTexts[offset];
        }
    }
    return NULL;
}
int MatchCall_GetOverrideFacilityClass(u32 idx)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
            return sCheckPageOverrides[i].facilityClass;
    }
    return -1;
}
bool32 MatchCall_HasRematchId(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders); i++)
    {
        u32 id = MatchCall_GetRematchTableIdx(i);
        if (id != REMATCH_TABLE_ENTRIES && id == idx)
            return TRUE;
    }
    return FALSE;
}
void SetMatchCallRegisteredFlag(void)
{
    int index = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (index >= 0)
        FlagSet(TRAINER_REGISTERED_FLAGS_START + index);
}
