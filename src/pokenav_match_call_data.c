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

// JP ROM data tables (defined at fixed addresses in ld_script_jp.txt).
extern const match_call_t sMatchCallHeaders[MC_HEADER_COUNT];
extern bool32 (*const sMatchCallGetEnabledFuncs[])(match_call_t);
extern mapsec_u8_t (*const sMatchCallGetMapSecFuncs[])(match_call_t);
extern bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t);
extern bool32 (*const sMatchCall_HasCheckPageFunctions[])(match_call_t);
extern u32 (*const sMatchCall_GetRematchTableIdxFunctions[])(match_call_t);
extern void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *);
extern void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **);
extern const struct MatchCallCheckPageOverride sCheckPageOverrides[4];
extern void sub_08196C74(u8 *dest);


// JP builds this as a jump table with a trailing 2-byte .align that the
// Makefile pipeline does not emit between functions; kept as naked asm.
__attribute__((naked)) static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {lr}\n\t"
            "ldrb r0, [r0]\n\t"
            "cmp r0, #5\n\t"
            "bhi _mcfi_C0\n\t"
            "lsls r0, r0, #2\n\t"
            "ldr r1, _mcfi_A4\n\t"
            "adds r0, r0, r1\n\t"
            "ldr r0, [r0]\n\t"
            "mov pc, r0\n\t"
            ".align 2, 0\n\t"
            "_mcfi_A4: .4byte _mcfi_A8\n\t"
            "_mcfi_A8: .4byte _mcfi_C0\n\t"
            ".4byte _mcfi_C4\n\t"
            ".4byte _mcfi_C8\n\t"
            ".4byte _mcfi_D0\n\t"
            ".4byte _mcfi_CC\n\t"
            ".4byte _mcfi_C4\n\t"
            "_mcfi_C0:\n\t"
            "movs r0, #0\n\t"
            "b _mcfi_D2\n\t"
            "_mcfi_C4:\n\t"
            "movs r0, #1\n\t"
            "b _mcfi_D2\n\t"
            "_mcfi_C8:\n\t"
            "movs r0, #2\n\t"
            "b _mcfi_D2\n\t"
            "_mcfi_CC:\n\t"
            "movs r0, #3\n\t"
            "b _mcfi_D2\n\t"
            "_mcfi_D0:\n\t"
            "movs r0, #4\n\t"
            "_mcfi_D2:\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            ".syntax divided");
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
__attribute__((naked)) static void sub_081D103C(const match_call_text_data_t *textData, u8 *dest)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, r8\n\t"
            "push {r7}\n\t"
            "adds r6, r0, #0\n\t"
            "mov r8, r1\n\t"
            "movs r5, #0\n\t"
            "ldr r7, _t_1050\n\t"
            "adds r4, r6, #0\n\t"
            "b _t_1058\n\t"
            ".align 2, 0\n\t"
            "_t_1050: .4byte 0x0000FFFF\n\t"
            "_t_1054:\n\t"
            "adds r4, #8\n\t"
            "adds r5, #1\n\t"
            "_t_1058:\n\t"
            "ldr r0, [r4]\n\t"
            "cmp r0, #0\n\t"
            "beq _t_106E\n\t"
            "ldrh r0, [r4, #4]\n\t"
            "cmp r0, r7\n\t"
            "beq _t_1054\n\t"
            "bl FlagGet\n\t"
            "lsls r0, r0, #0x18\n\t"
            "cmp r0, #0\n\t"
            "bne _t_1054\n\t"
            "_t_106E:\n\t"
            "cmp r5, #0\n\t"
            "beq _t_1074\n\t"
            "subs r5, #1\n\t"
            "_t_1074:\n\t"
            "lsls r0, r5, #3\n\t"
            "adds r4, r0, r6\n\t"
            "ldrh r1, [r4, #6]\n\t"
            "ldr r0, _t_1098\n\t"
            "cmp r1, r0\n\t"
            "beq _t_1086\n\t"
            "adds r0, r1, #0\n\t"
            "bl FlagSet\n\t"
            "_t_1086:\n\t"
            "ldr r1, [r4]\n\t"
            "mov r0, r8\n\t"
            "bl StringExpandPlaceholders\n\t"
            "pop {r3}\n\t"
            "mov r8, r3\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_t_1098: .4byte 0x0000FFFF\n\t"
            ".syntax divided");
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
