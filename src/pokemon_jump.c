#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "digit_obj_util.h"
#include "item.h"
#include "link.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_jump.h"
#include "random.h"
#include "save.h"
#include "sound.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"

#define VINE_SPRITES_PER_SIDE 4 // Vine rope is divided into 8 sprites, 4 per side copied and flipped horizontally
#define JUMP_PEAK (-30)

// Used by SetLinkTimeInterval to get a bit mask for capping
// a timer that controls how frequently link data is sent.
#define LINK_INTERVAL_NONE   0
#define LINK_INTERVAL_SHORT  3 // 3 frame interval
#define LINK_INTERVAL_MEDIUM 4 // 7 frame interval
#define LINK_INTERVAL_LONG   5 // 15 frame interval

#define LINK_TIMER_STOPPED 0x1111

// JP: enum order matches the JP ROM data (sPokeJumpMons jumpType bytes).
// US order is NORMAL, FAST, SLOW; JP data stores NORMAL=0, FAST=1, SLOW=2.
enum {
    JUMP_TYPE_NORMAL,
    JUMP_TYPE_FAST,
    JUMP_TYPE_SLOW,
};

enum {
    FUNC_GAME_INTRO,
    FUNC_WAIT_ROUND,
    FUNC_GAME_ROUND,
    FUNC_GAME_OVER,
    FUNC_ASK_PLAY_AGAIN,
    FUNC_RESET_GAME,
    FUNC_EXIT,
    FUNC_GIVE_PRIZE,
    FUNC_SAVE,
    FUNC_NONE
};

enum {
    GFXFUNC_LOAD,
    GFXFUNC_SHOW_NAMES,
    GFXFUNC_SHOW_NAMES_HIGHLIGHT,
    GFXFUNC_ERASE_NAMES,
    GFXFUNC_MSG_PLAY_AGAIN,
    GFXFUNC_MSG_SAVING,
    GFXFUNC_ERASE_MSG,
    GFXFUNC_MSG_PLAYER_DROPPED,
    GFXFUNC_MSG_COMM_STANDBY,
    GFXFUNC_COUNTDOWN,
};

enum {
    MONSTATE_NORMAL, // Pokémon is either on the ground or in the middle of a jump
    MONSTATE_JUMP,   // Pokémon has begun a jump
    MONSTATE_HIT,    // Pokémon got hit by the vine
};

enum {
    JUMPSTATE_NONE,
    JUMPSTATE_SUCCESS, // Cleared vine
    JUMPSTATE_FAILURE, // Hit vine
};

#define PLAY_AGAIN_NO  1
#define PLAY_AGAIN_YES 2

#define VINE_STATE_TIMER(vineState) (((vineState) << 8) | 0xFF)

enum {
    VINE_HIGHEST,
    VINE_DOWNSWING_HIGHER,
    VINE_DOWNSWING_HIGH,
    VINE_DOWNSWING_LOW,
    VINE_DOWNSWING_LOWER,
    VINE_LOWEST,
    VINE_UPSWING_LOWER,
    VINE_UPSWING_LOW,
    VINE_UPSWING_HIGH,
    VINE_UPSWING_HIGHER,
    NUM_VINESTATES
};

struct PokemonJump_MonInfo
{
    u16 species;
    u32 otId;
    u32 personality;
};

struct PokemonJump_Player
{
    int jumpOffset;
    int jumpOffsetIdx;
    u32 unused;
    u16 monJumpType;
    u16 jumpTimeStart;
    u16 monState;
    u16 prevMonState;
    int jumpState;
    bool32 funcFinished;
    u8 name[8]; // JP: player names are 8 bytes (JP charmap, US is name[11])
};

struct PokemonJumpMons
{
    u16 species;
    u16 jumpType;
};

struct PokemonJumpGfx
{
    bool32 funcFinished;
    u16 mainState;
    u8 taskId;
    u8 unused1[3];
    u8 resetVineState;
    u8 resetVineTimer;
    u8 vineState;
    u8 msgWindowState;
    u8 vinePalNumDownswing;
    u8 vinePalNumUpswing;
    u16 unused2;
    u16 msgWindowId;
    u16 fanfare;
    u32 bonusTimer;
    u16 nameWindowIds[MAX_RFU_PLAYERS];
    u8 itemName[64];
    u8 itemQuantityStr[64];
    u8 prizeMsg[256];
    u16 tilemapBuffer[0x4000];
    struct Sprite *monSprites[MAX_RFU_PLAYERS];
    struct Sprite *starSprites[MAX_RFU_PLAYERS];
    struct Sprite *vineSprites[VINE_SPRITES_PER_SIDE * 2];
    u8 unused3[12];
    u8 monSpriteSubpriorities[MAX_RFU_PLAYERS];
};

struct PokemonJump_CommData
{
    u8 funcId;
    u8 receivedBonusFlags;
    u16 data; // Multi-use
    u16 jumpsInRow;
    u32 jumpScore;
};

struct PokemonJump
{
    MainCallback exitCallback;
    u8 taskId;
    u8 numPlayers;
    u8 multiplayerId;
    u8 startDelayTimer;
    u16 mainState;
    u16 helperState;
    u16 excellentsInRow;
    u16 excellentsInRowRecord;
    bool32 gameOver;
    u32 vineState;
    u32 prevVineState;
    int vineSpeed;
    u32 vineSpeedAccel;
    u32 rngSeed;
    u32 nextVineSpeed;
    int linkTimer;
    u32 linkTimerLimit;
    u16 vineStateTimer;
    bool16 ignoreJumpInput;
    u16 unused1;
    u16 unused2; // Set to 0, never read
    u16 timer;
    u16 prizeItemId;
    u16 prizeItemQuantity;
    u16 playAgainComm;
    u8 unused3; // Set to 0, never read
    u8 playAgainState;
    bool8 allowVineUpdates;
    bool8 isLeader;
    bool8 funcActive;
    bool8 allPlayersReady;
    u16 vineTimer;
    u8 nextFuncId;
    bool8 showBonus;
    u16 vineSpeedDelay;
    u8 vineBaseSpeedIdx;
    u8 vineSpeedStage;
    int numPlayersAtPeak;
    bool32 initScoreUpdate;
    bool32 updateScore;
    bool32 unused4; // Set to TRUE, never read
    bool32 giveBonus;
    bool32 skipJumpUpdate;
    bool32 atMaxSpeedStage;
    struct PokemonJump_CommData comm;
    bool8 atJumpPeak[MAX_RFU_PLAYERS];
    bool8 atJumpPeak2[MAX_RFU_PLAYERS];
    bool8 atJumpPeak3[MAX_RFU_PLAYERS];
    u8 memberFuncIds[MAX_RFU_PLAYERS];
    u16 playAgainStates[MAX_RFU_PLAYERS];
    u16 jumpTimeStarts[MAX_RFU_PLAYERS];
    struct PokemonJumpGfx jumpGfx;
    struct PokemonJump_MonInfo monInfo[MAX_RFU_PLAYERS];
    struct PokemonJump_Player players[MAX_RFU_PLAYERS];
struct PokemonJump_Player *player;
};

// JP: the species->jump type table is ROM data at 0x082CECF0 (data/data_b.s,
// gUnknown_82CECF0).  US defines it as sPokeJumpMons in C; JP data has the
// same layout ({u16 species, u16 jumpType}) but jumpType byte values differ
// from US (JP enum order NORMAL=0, FAST=1, SLOW=2).
extern const struct PokemonJumpMons sPokeJumpMons[];
// JP: jump Y-offset table is ROM data at 0x082CEEE8 (data/data_b.s,
// gUnknown_82CEEE8).  3 rows of 48 s8 (row order NORMAL, FAST, SLOW).
extern const s8 sJumpOffsets[][48];

EWRAM_DATA struct PokemonJump *sPokemonJump = NULL;

void InitJumpMonInfo(struct PokemonJump_MonInfo *monInfo, struct Pokemon *mon);
void InitGame(struct PokemonJump *jump);
void CB2_PokemonJump(void);
void Task_StartPokemonJump(u8 taskId);

void FreeWindowsAndDigitObj(void);
void FreePokemonJump(void);
void InitJumpMonInfo(struct PokemonJump_MonInfo *monInfo, struct Pokemon *mon);
void InitPlayerAndJumpTypes(void);
void ResetForNewGame(struct PokemonJump *jump);
void ResetPlayersForNewGame(void);
void ResetPlayersJumpStates(void);
s16 GetPokemonJumpSpeciesIdx(u16 species);
struct PokemonJumpRecords *GetPokeJumpRecords(void);
void IncrementGamesWithMaxPlayers(void);

void FreeWindowsAndDigitObj(void)
{
    FreeAllWindowBuffers();
    DigitObjUtil_Free();
}

void FreePokemonJump(void)
{
    FreeWindowsAndDigitObj();
    Free(sPokemonJump);
}

void StartPokemonJump(u16 partyId, MainCallback exitCallback)
{
    u8 taskId;

    if (gReceivedRemoteLinkPlayers)
    {
        sPokemonJump = Alloc(sizeof(*sPokemonJump));
        if (sPokemonJump)
        {
            ResetTasks();
            taskId = CreateTask(Task_StartPokemonJump, 1);
            sPokemonJump->mainState = 0;
            sPokemonJump->exitCallback = exitCallback;
            sPokemonJump->taskId = taskId;
            sPokemonJump->multiplayerId = GetMultiplayerId();
            InitJumpMonInfo(&sPokemonJump->monInfo[sPokemonJump->multiplayerId], &gPlayerParty[partyId]);
            InitGame(sPokemonJump);
            SetWordTaskArg(taskId, 2, (u32)sPokemonJump);
            SetMainCallback2(CB2_PokemonJump);
            return;
        }
    }

    SetMainCallback2(exitCallback);
}

void InitJumpMonInfo(struct PokemonJump_MonInfo *monInfo, struct Pokemon *mon)
{
    // JP: the ROM calls GetMonData2 (2-arg alias of GetMonData3); passing a
    // third argument would emit an extra r2 setup instruction.
    monInfo->species = GetMonData2(mon, MON_DATA_SPECIES);
    monInfo->otId = GetMonData2(mon, MON_DATA_OT_ID);
    monInfo->personality = GetMonData2(mon, MON_DATA_PERSONALITY);
}

void VBlankCB_PokemonJump(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

void CB2_PokemonJump(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void SetPokeJumpTask(TaskFunc func)
{
    sPokemonJump->taskId = CreateTask(func, 1);
    sPokemonJump->mainState = 0;
}

// JP: these helpers are still in asm (sub_ names); rename to US names when
// each one is converted to C.
extern void sub_0802BB54(TaskFunc func, u8 taskPriority); // SetTaskWithPokeJumpStruct
extern void sub_0802BA78(u8 taskId); // Task_CommunicateMonInfo (JP pokemon_jump; dodrio has its own)
extern void sub_0802CD68(struct PokemonJumpGfx *gfx); // StartPokeJumpGfx
extern bool32 sub_0802CDE4(void); // IsPokeJumpGfxFuncFinished
extern void sub_0802AC74(u8 taskId); // Task_PokemonJump_Leader
extern void sub_0802AE88(u8 taskId); // Task_PokemonJump_Member
extern void sub_0802BB74(void); // InitVineState
extern bool32 sub_0802DF5C(struct PokemonJump_Player *player, int multiplayerId, u8 *funcId, u16 *playAgainState);
extern void sub_0802BED0(void); // UpdateGame
extern void sub_0802C130(void); // TryUpdateScore
extern void sub_0802DE30(struct PokemonJump_Player *players, struct PokemonJump_CommData *comm); // SendPacket_LeaderState
extern bool32 sub_0802DEB4(struct PokemonJump_Player *players, struct PokemonJump_CommData *leaderData); // RecvPacket_LeaderState
extern bool32 sub_0802DFC8(struct PokemonJump_Player *player, int multiplayerId); // RecvPacket_MemberStateToMember
extern void sub_0802AEF0(void); // SendLinkData_Member
extern void sub_0802DF2C(struct PokemonJump_Player *player, u8 funcId, u16 playAgainComm); // SendPacket_MemberState
extern bool32 sub_0802B4D4(void); // DoGameIntro
extern bool32 sub_0802C400(void); // AreLinkQueuesEmpty
extern bool32 sub_0802B5C0(void); // HandleSwingRound
extern bool32 sub_0802C22C(void); // UpdateVineHitStates
extern void sub_0802BDAC(void); // ResetVineAfterHit
extern bool32 sub_0802C2D0(void); // AllPlayersJumpedOrHit
extern bool32 sub_0802B658(void); // DoVineHitEffect
extern bool32 sub_0802C4B0(void); // HasEnoughScoreForPrize
extern u16 sub_0802C4D4(void); // GetPrizeData
extern bool32 sub_0802B878(void); // DoPlayAgainPrompt
extern bool32 sub_0802C344(void); // ShouldPlayAgain
extern void sub_0802E04C(u32 jumpScore, u16 jumpsInRow, u16 data); // TryUpdateRecords
extern bool32 sub_0802BA24(void); // CloseMessageAndResetScore
extern bool32 sub_0802B954(void); // ClosePokeJumpLink
extern bool32 sub_0802B74C(void); // TryGivePrize
extern void sub_0802CDBC(int funcId); // SetUpPokeJumpGfxFuncById
extern void sub_0802D704(void); // ClearMessageWindow
extern bool32 sub_0802D734(void); // RemoveMessageWindow
extern void sub_0802DAD8(void); // ResetMonSpriteSubpriorities
extern void sub_0802DAEC(int multiplayerId); // StartMonIntroBounce
extern bool32 sub_0802DB00(void); // IsMonIntroBounceActive
extern void sub_0802BF54(void); // DisallowVineUpdates
extern void sub_0802D458(void); // SetUpResetVineGfx
extern bool32 sub_0802D47C(void); // ResetVineGfx
extern void sub_0802BF64(void); // AllowVineUpdates
extern void sub_0802BB94(void); // ResetVineState
extern bool32 sub_0802BE24(u16 monState); // IsPlayersMonState
extern void sub_0802BE58(void); // SetMonStateJump
extern void sub_0802BBD8(void); // UpdateVineState
extern bool32 sub_0802DAB0(int multiplayerId); // IsMonHitShakeActive
extern void sub_0802DA98(u8 multiplayerId); // StartMonHitFlash
extern void sub_0802DAC4(void); // StopMonHitFlash
extern void sub_0802BE08(void); // ResetPlayersMonState
extern void sub_0802C4FC(u16 prizeData, u16 *prizeItemId, u16 *prizeItemQuantity); // UnpackPrizeData
extern void sub_0802D4DC(u16 prizeItemId, u16 prizeItemQuantity); // PrintPrizeMessage
extern bool32 sub_0802D664(void); // DoPrizeMessageAndFanfare
extern u16 sub_0802C574(u16 prizeItemId, u16 prizeItemQuantity); // GetQuantityLimitedByBag
extern void sub_0802D574(u16 prizeItemId); // PrintPrizeFilledBagMessage
extern void sub_0802D5EC(u16 prizeItemId); // PrintNoRoomForPrizeMessage
extern s8 sub_0802D77C(void); // HandlePlayAgainInput
extern void sub_0802DA5C(int score); // PrintScore
extern void sub_0802DDA4(struct PokemonJump_MonInfo *monInfo); // SendPacket_MonInfo
extern bool32 sub_0802DDC8(int multiplayerId, struct PokemonJump_MonInfo *monInfo); // RecvPacket_MonInfo
extern void sub_0802BC70(void); // UpdateVineSpeed
extern int sub_0802BC3C(void); // GetVineSpeed
extern int sub_0802BD8C(void); // PokeJumpRandom

// JP: vine speed tables are ROM data (data/data_b.s gUnknown_82CEEC8 /
// gUnknown_82CEED8); same layouts as US sVineBaseSpeeds / sVineSpeedDelays.
extern const u16 sVineBaseSpeeds[];
extern const u16 sVineSpeedDelays[];

// JP: member function table is ROM data at 0x082CEEA4 (data/data_b.s,
// gUnknown_82CEEA4); same 9-entry layout as US sPokeJumpMemberFuncs.
extern bool32 (*const sPokeJumpMemberFuncs[])(void);

// JP: leader function table is ROM data at 0x082CEE80 (data/data_b.s,
// gUnknown_82CEE80); same 9-entry layout as US sPokeJumpLeaderFuncs.
extern bool32 (*const sPokeJumpLeaderFuncs[])(void);

void Task_StartPokemonJump(u8 taskId)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetVBlankCallback(NULL);
        ResetSpriteData();
        FreeAllSpritePalettes();
        sub_0802BB54(sub_0802BA78, 5); // SetTaskWithPokeJumpStruct(Task_CommunicateMonInfo, 5)
        FadeOutMapMusic(4);
        sPokemonJump->mainState++;
        break;
    case 1:
        if (!FuncIsActiveTask(sub_0802BA78))
        {
            sub_0802CD68(&sPokemonJump->jumpGfx); // StartPokeJumpGfx
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
            sPokemonJump->mainState++;
        }
        break;
    case 2:
        if (!sub_0802CDE4() && IsNotWaitingForBGMStop() == TRUE) // IsPokeJumpGfxFuncFinished
        {
            FadeOutAndPlayNewMapMusic(MUS_RG_POKE_JUMP, 8);
            sPokemonJump->mainState++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
            SetVBlankCallback(VBlankCB_PokemonJump);
            sPokemonJump->mainState++;
        }
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            sPokemonJump->startDelayTimer = 0;
            sPokemonJump->mainState++;
        }
        break;
    case 5:
        sPokemonJump->startDelayTimer++;
        if (sPokemonJump->startDelayTimer >= 20)
        {
            if (sPokemonJump->isLeader)
                SetPokeJumpTask(sub_0802AC74); // Task_PokemonJump_Leader
            else
                SetPokeJumpTask(sub_0802AE88); // Task_PokemonJump_Member
            sub_0802BB74(); // InitVineState
            DestroyTask(taskId);
        }
        break;
    }
}

void SetLinkTimeInterval(int intervalId)
{
    if (intervalId == LINK_INTERVAL_NONE)
    {
        // Link data is sent when timer reaches 0.
        // Set timer to 1 and set limit to special
        // 'stopped' value so timer won't change
        sPokemonJump->linkTimerLimit = LINK_TIMER_STOPPED;
        sPokemonJump->linkTimer = 1;
    }
    else
    {
        sPokemonJump->linkTimerLimit = (1 << (intervalId - 1)) - 1;
        sPokemonJump->linkTimer = 0;
    }
}

void SetFunc_Leader(u8 funcId)
{
    int i;

    sPokemonJump->comm.funcId = funcId;
    sPokemonJump->mainState = 0;
    sPokemonJump->helperState = 0;
    sPokemonJump->funcActive = TRUE;
    sPokemonJump->allPlayersReady = FALSE;
    for (i = 1; i < sPokemonJump->numPlayers; i++)
        sPokemonJump->players[i].funcFinished = FALSE;
}

// JP: this is the member-state receive loop that US keeps inside
// RecvLinkData_Leader; JP has it as a standalone function.
void RecvLinkData_Leader(void)
{
    int i;
    int numReady;
    u16 monState;
    u8 funcId;
    u16 playAgainState;

    for (i = 1, numReady = 0; i < sPokemonJump->numPlayers; i++)
    {
        monState = sPokemonJump->players[i].monState;
        if (sub_0802DF5C(&sPokemonJump->players[i], i, &funcId, &playAgainState))
        {
            sPokemonJump->playAgainStates[i] = playAgainState;
            sPokemonJump->memberFuncIds[i] = funcId;
            sPokemonJump->players[i].prevMonState = monState;
        }

        // Group member has finished currently assigned function
        if (sPokemonJump->players[i].funcFinished && sPokemonJump->memberFuncIds[i] == sPokemonJump->comm.funcId)
            numReady++;
    }

    if (numReady == sPokemonJump->numPlayers - 1)
        sPokemonJump->allPlayersReady = TRUE;
}

void Task_PokemonJump_Leader(u8 taskId)
{
    RecvLinkData_Leader();
    sub_0802C130(); // TryUpdateScore
    if (!sPokemonJump->funcActive && sPokemonJump->allPlayersReady)
    {
        SetFunc_Leader(sPokemonJump->nextFuncId);
        SetLinkTimeInterval(LINK_INTERVAL_SHORT);
    }

    if (sPokemonJump->funcActive == TRUE)
    {
        if (!sPokeJumpLeaderFuncs[sPokemonJump->comm.funcId]())
        {
            sPokemonJump->funcActive = FALSE;
            sPokemonJump->players[sPokemonJump->multiplayerId].funcFinished = TRUE;
        }
    }

    sub_0802BED0(); // UpdateGame
    SendLinkData_Leader();
}

void SendLinkData_Leader(void)
{
    if (!sPokemonJump->linkTimer)
        sub_0802DE30(sPokemonJump->players, &sPokemonJump->comm); // SendPacket_LeaderState

    if (sPokemonJump->linkTimerLimit != LINK_TIMER_STOPPED)
    {
        sPokemonJump->linkTimer++;
        sPokemonJump->linkTimer &= sPokemonJump->linkTimerLimit;
    }
}

void SetFunc_Member(u8 funcId)
{
    sPokemonJump->comm.funcId = funcId;
    sPokemonJump->mainState = 0;
    sPokemonJump->helperState = 0;
    sPokemonJump->funcActive = TRUE;
    sPokemonJump->players[sPokemonJump->multiplayerId].funcFinished = FALSE;
}

void RecvLinkData_Member(void)
{
    int i;
    u16 monState;
    struct PokemonJump_CommData leaderData;

    monState = sPokemonJump->players[0].monState;
    if (sub_0802DEB4(sPokemonJump->players, &leaderData)) // RecvPacket_LeaderState
    {
        if (sPokemonJump->players[sPokemonJump->multiplayerId].funcFinished == TRUE
         && leaderData.funcId != sPokemonJump->comm.funcId)
        {
            SetFunc_Member(leaderData.funcId);
        }

        if (sPokemonJump->comm.jumpScore != leaderData.jumpScore)
        {
            sPokemonJump->comm.jumpScore = leaderData.jumpScore;
            sPokemonJump->updateScore = TRUE;
            sPokemonJump->comm.receivedBonusFlags = leaderData.receivedBonusFlags;
            if (sPokemonJump->comm.receivedBonusFlags)
                sPokemonJump->showBonus = TRUE;
            else
                sPokemonJump->showBonus = FALSE;
        }

        sPokemonJump->comm.data = leaderData.data;
        sPokemonJump->comm.jumpsInRow = leaderData.jumpsInRow;
        sPokemonJump->players[0].prevMonState = monState;
    }

    for (i = 1; i < sPokemonJump->numPlayers; i++)
    {
        if (i != sPokemonJump->multiplayerId)
        {
            monState = sPokemonJump->players[i].monState;
            if (sub_0802DFC8(&sPokemonJump->players[i], i)) // RecvPacket_MemberStateToMember
                sPokemonJump->players[i].prevMonState = monState;
        }
    }
}

void Task_PokemonJump_Member(u8 taskId)
{
    RecvLinkData_Member();
    if (sPokemonJump->funcActive)
    {
        if (!sPokeJumpMemberFuncs[sPokemonJump->comm.funcId]())
        {
            sPokemonJump->funcActive = FALSE;
            sPokemonJump->players[sPokemonJump->multiplayerId].funcFinished = TRUE;
            SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        }
    }

    sub_0802BED0(); // UpdateGame
    SendLinkData_Member();
}

void SendLinkData_Member(void)
{
    if (!sPokemonJump->linkTimer)
        sub_0802DF2C(&sPokemonJump->players[sPokemonJump->multiplayerId], sPokemonJump->comm.funcId, sPokemonJump->playAgainComm); // SendPacket_MemberState

    if (sPokemonJump->linkTimerLimit != LINK_TIMER_STOPPED)
    {
        sPokemonJump->linkTimer++;
        sPokemonJump->linkTimer &= sPokemonJump->linkTimerLimit;
    }
}

bool32 GameIntro_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        sPokemonJump->mainState++;
        // fall through
    case 1:
        if (!sub_0802B4D4()) // DoGameIntro
        {
            sPokemonJump->comm.data = sPokemonJump->vineTimer;
            sPokemonJump->nextFuncId = FUNC_WAIT_ROUND;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool32 GameIntro_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_NONE);
        sPokemonJump->rngSeed = sPokemonJump->comm.data;
        sPokemonJump->mainState++;
        // fall through
    case 1:
        return sub_0802B4D4(); // DoGameIntro
    }

    return TRUE;
}

bool32 WaitRound_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        ResetPlayersJumpStates();
        SetLinkTimeInterval(LINK_INTERVAL_LONG);
        sPokemonJump->mainState++;
        break;
    case 1:
        if (sPokemonJump->allPlayersReady)
        {
            sPokemonJump->nextFuncId = FUNC_GAME_ROUND;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool32 WaitRound_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        ResetPlayersJumpStates();
        SetLinkTimeInterval(LINK_INTERVAL_NONE);
        sPokemonJump->vineTimer = sPokemonJump->comm.data;
        sPokemonJump->mainState++;
        // fall through
    case 1:
        if (sub_0802C400()) // AreLinkQueuesEmpty
            return FALSE;
        break;
    }

    return TRUE;
}

bool32 GameRound_Leader(void)
{
    if (!sub_0802B5C0()) // HandleSwingRound
    {
        sPokemonJump->comm.data = sPokemonJump->vineTimer;
        sPokemonJump->nextFuncId = FUNC_WAIT_ROUND;
    }
    else if (sub_0802C22C()) // UpdateVineHitStates
    {
        return TRUE;
    }
    else
    {
        // Someone hit the vine
        sub_0802BDAC(); // ResetVineAfterHit
        sPokemonJump->nextFuncId = FUNC_GAME_OVER;
    }

    return FALSE;
}

bool32 GameRound_Member(void)
{
    if (!sub_0802B5C0()) // HandleSwingRound
        ;
    else if (sub_0802C22C()) // UpdateVineHitStates
        return TRUE;
    else // Someone hit the vine
        sub_0802BDAC(); // ResetVineAfterHit

    return FALSE;
}

bool32 GameOver_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        sub_0802C22C(); // UpdateVineHitStates
        if (sub_0802C2D0()) // AllPlayersJumpedOrHit
            sPokemonJump->mainState++;
        break;
    case 1:
        if (!sub_0802B658()) // DoVineHitEffect
        {
            if (sub_0802C4B0()) // HasEnoughScoreForPrize
            {
                sPokemonJump->comm.data = sub_0802C4D4(); // GetPrizeData
                sPokemonJump->nextFuncId = FUNC_GIVE_PRIZE;
            }
            else if (sPokemonJump->comm.jumpsInRow >= 200)
            {
                sPokemonJump->comm.data = sPokemonJump->excellentsInRowRecord;
                sPokemonJump->nextFuncId = FUNC_SAVE;
            }
            else
            {
                sPokemonJump->comm.data = sPokemonJump->excellentsInRowRecord;
                sPokemonJump->nextFuncId = FUNC_ASK_PLAY_AGAIN;
            }

            sPokemonJump->mainState++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

bool32 GameOver_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        if (!sub_0802C22C()) // UpdateVineHitStates
            sub_0802BDAC(); // ResetVineAfterHit
        if (sub_0802C2D0()) // AllPlayersJumpedOrHit
            sPokemonJump->mainState++;
        break;
    case 1:
        if (!sub_0802B658()) // DoVineHitEffect
        {
            sPokemonJump->mainState++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

bool32 AskPlayAgain_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_MEDIUM);
        sPokemonJump->mainState++;
        // fall through
    case 1:
        if (!sub_0802B878()) // DoPlayAgainPrompt
        {
            sub_0802E04C(sPokemonJump->comm.jumpScore, sPokemonJump->comm.jumpsInRow, sPokemonJump->comm.data); // TryUpdateRecords
            sPokemonJump->mainState++;
        }
        break;
    case 2:
        if (sPokemonJump->allPlayersReady)
        {
            if (sub_0802C344()) // ShouldPlayAgain
                sPokemonJump->nextFuncId = FUNC_RESET_GAME;
            else
                sPokemonJump->nextFuncId = FUNC_EXIT;

            sPokemonJump->mainState++;
            return FALSE;
        }
        break;
    case 3:
        return FALSE;
    }

    return TRUE;
}

bool32 AskPlayAgain_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_NONE);
        sPokemonJump->mainState++;
        // fall through
    case 1:
        if (!sub_0802B878()) // DoPlayAgainPrompt
        {
            sub_0802E04C(sPokemonJump->comm.jumpScore, sPokemonJump->comm.jumpsInRow, sPokemonJump->comm.data); // TryUpdateRecords
            sPokemonJump->playAgainComm = sPokemonJump->playAgainState;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool32 ResetGame_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        if (!sub_0802BA24()) // CloseMessageAndResetScore
            sPokemonJump->mainState++;
        break;
    case 1:
        if (sPokemonJump->allPlayersReady)
        {
            ResetForNewGame(sPokemonJump);
            sPokemonJump->rngSeed = Random();
            sPokemonJump->comm.data = sPokemonJump->rngSeed;
            sPokemonJump->nextFuncId = FUNC_GAME_INTRO;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool32 ResetGame_Member(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        if (!sub_0802BA24()) // CloseMessageAndResetScore
        {
            ResetForNewGame(sPokemonJump);
            sPokemonJump->mainState++;
            return FALSE;
        }
        break;
    case 1:
        return FALSE;
    }

    return TRUE;
}

bool32 ExitGame(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        sPokemonJump->mainState = 1;
        break;
    case 1:
        SetLinkTimeInterval(LINK_INTERVAL_NONE);
        sPokemonJump->mainState++;
        break;
    case 2:
        if (!sub_0802B954()) // ClosePokeJumpLink
        {
            SetMainCallback2(sPokemonJump->exitCallback);
            FreePokemonJump();
        }
        break;
    }

    return TRUE;
}

bool32 GivePrize_Leader(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        SetLinkTimeInterval(LINK_INTERVAL_MEDIUM);
        sPokemonJump->mainState++;
        break;
    case 1:
        if (!sub_0802B74C()) // TryGivePrize
        {
            sPokemonJump->comm.data = sPokemonJump->excellentsInRowRecord;
            sPokemonJump->nextFuncId = FUNC_SAVE;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool32 GivePrize_Member(void)
{
    SetLinkTimeInterval(LINK_INTERVAL_NONE);
    if (!sub_0802B74C()) // TryGivePrize
        return FALSE;
    else
        return TRUE;
}

bool32 SavePokeJump(void)
{
    switch (sPokemonJump->mainState)
    {
    case 0:
        sub_0802E04C(sPokemonJump->comm.jumpScore, sPokemonJump->comm.jumpsInRow, sPokemonJump->comm.data); // TryUpdateRecords
        sub_0802CDBC(GFXFUNC_MSG_SAVING); // SetUpPokeJumpGfxFuncById
        sPokemonJump->mainState++;
        break;
    case 1:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
        {
            SetLinkTimeInterval(LINK_INTERVAL_NONE);
            sPokemonJump->mainState++;
        }
        break;
    case 2:
        if (sub_0802C400()) // AreLinkQueuesEmpty
        {
            CreateTask(Task_LinkFullSave, 6);
            sPokemonJump->mainState++;
        }
        break;
    case 3:
        if (!FuncIsActiveTask(Task_LinkFullSave))
        {
            sub_0802D704(); // ClearMessageWindow
            sPokemonJump->mainState++;
        }
        break;
    case 4:
        if (!sub_0802D734()) // RemoveMessageWindow
        {
            sPokemonJump->nextFuncId = FUNC_ASK_PLAY_AGAIN;
            return FALSE;
        }
        break;
    }

    return TRUE;
}

bool32 DoGameIntro(void)
{
    switch (sPokemonJump->helperState)
    {
    case 0:
        sub_0802CDBC(GFXFUNC_SHOW_NAMES_HIGHLIGHT); // SetUpPokeJumpGfxFuncById
        sub_0802DAD8(); // ResetMonSpriteSubpriorities
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
        {
            sub_0802DAEC(sPokemonJump->multiplayerId); // StartMonIntroBounce
            sPokemonJump->timer = 0;
            sPokemonJump->helperState++;
        }
        break;
    case 2:
        if (++sPokemonJump->timer > 120)
        {
            sub_0802CDBC(GFXFUNC_ERASE_NAMES); // SetUpPokeJumpGfxFuncById
            sPokemonJump->helperState++;
        }
        break;
    case 3:
        if (sub_0802CDE4() != TRUE && sub_0802DB00() != TRUE) // IsPokeJumpGfxFuncFinished, IsMonIntroBounceActive
            sPokemonJump->helperState++;
        break;
    case 4:
        sub_0802CDBC(GFXFUNC_COUNTDOWN); // SetUpPokeJumpGfxFuncById
        sPokemonJump->helperState++;
        break;
    case 5:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
        {
            sub_0802BF54(); // DisallowVineUpdates
            sub_0802D458(); // SetUpResetVineGfx
            sPokemonJump->helperState++;
        }
        break;
    case 6:
        if (!sub_0802D47C()) // ResetVineGfx
        {
            sub_0802BF64(); // AllowVineUpdates
            sub_0802BB94(); // ResetVineState
            sPokemonJump->helperState++;
            return FALSE;
        }
        break;
    case 7:
        return FALSE;
    }

    return TRUE;
}

bool32 HandleSwingRound(void)
{
    sub_0802BBD8(); // UpdateVineState
    if (sPokemonJump->ignoreJumpInput)
    {
        sPokemonJump->ignoreJumpInput = FALSE;
        return FALSE;
    }

    switch (sPokemonJump->helperState)
    {
    case 0:
        if (IsPlayersMonState(MONSTATE_NORMAL))
            sPokemonJump->helperState++;
        else
            break;
        // fall through
    case 1:
        if (JOY_NEW(A_BUTTON))
        {
            SetMonStateJump();
            SetLinkTimeInterval(LINK_INTERVAL_SHORT);
            sPokemonJump->helperState++;
        }
        break;
    case 2:
        if (IsPlayersMonState(MONSTATE_JUMP) == TRUE)
            sPokemonJump->helperState++;
        break;
    case 3:
        if (IsPlayersMonState(MONSTATE_NORMAL) == TRUE)
            sPokemonJump->helperState = 0;
        break;
    }

    return TRUE;
}

bool32 DoVineHitEffect(void)
{
    int i;

    switch (sPokemonJump->helperState)
    {
    case 0:
        for (i = 0; i < sPokemonJump->numPlayers; i++)
        {
            if (sub_0802DAB0(i) == TRUE) // IsMonHitShakeActive
                return TRUE;
        }

        sPokemonJump->helperState++;
        break;
    case 1:
        for (i = 0; i < sPokemonJump->numPlayers; i++)
        {
            if (sPokemonJump->players[i].monState == MONSTATE_HIT)
                sub_0802DA98(i); // StartMonHitFlash
        }

        sub_0802CDBC(GFXFUNC_SHOW_NAMES); // SetUpPokeJumpGfxFuncById
        sPokemonJump->timer = 0;
        sPokemonJump->helperState++;
        break;
    case 2:
        if (++sPokemonJump->timer > 100)
        {
            sub_0802CDBC(GFXFUNC_ERASE_NAMES); // SetUpPokeJumpGfxFuncById
            sPokemonJump->timer = 0;
            sPokemonJump->helperState++;
        }
        break;
    case 3:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
        {
            sub_0802DAC4(); // StopMonHitFlash
            sPokemonJump->comm.receivedBonusFlags = 0;
            sub_0802BE08(); // ResetPlayersMonState
            sPokemonJump->helperState++;
            return FALSE;
        }
        break;
    case 4:
        return FALSE;
    }

    return TRUE;
}

// JP: dodrio_berry_picking.c already has a global TryGivePrize (0x08027788,
// referenced from its asm), so the pokemon_jump one gets a JP-specific name.
bool32 TryGivePrize_PokeJump(void)
{
    switch (sPokemonJump->helperState)
    {
    case 0:
        sub_0802C4FC(sPokemonJump->comm.data, &sPokemonJump->prizeItemId, &sPokemonJump->prizeItemQuantity); // UnpackPrizeData
        sub_0802D4DC(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity); // PrintPrizeMessage
        sPokemonJump->helperState++;
        break;
    case 1:
    case 4:
        if (!sub_0802D664()) // DoPrizeMessageAndFanfare
        {
            sPokemonJump->timer = 0;
            sPokemonJump->helperState++;
        }
        break;
    case 2:
    case 5:
        // Wait to continue after message
        sPokemonJump->timer++;
        if (JOY_NEW(A_BUTTON | B_BUTTON) || sPokemonJump->timer > 180)
        {
            sub_0802D704(); // ClearMessageWindow
            sPokemonJump->helperState++;
        }
        break;
    case 3:
        if (!sub_0802D734()) // RemoveMessageWindow
        {
            sPokemonJump->prizeItemQuantity = sub_0802C574(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity); // GetQuantityLimitedByBag
            if (sPokemonJump->prizeItemQuantity && AddBagItem(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity))
            {
                if (!CheckBagHasSpace(sPokemonJump->prizeItemId, 1))
                {
                    // An item was given successfully, but no room for any more.
                    // It's possible the full prize quantity had to be limited
                    sub_0802D574(sPokemonJump->prizeItemId); // PrintPrizeFilledBagMessage
                    sPokemonJump->helperState = 4; // Do message
                }
                else
                {
                    sPokemonJump->helperState = 6; // Exit
                    break;
                }
            }
            else
            {
                sub_0802D5EC(sPokemonJump->prizeItemId); // PrintNoRoomForPrizeMessage
                sPokemonJump->helperState = 4; // Do message
            }
        }
        break;
    case 6:
        if (!sub_0802D734()) // RemoveMessageWindow
            return FALSE;
        break;
    }

    return TRUE;
}

bool32 DoPlayAgainPrompt(void)
{
    s8 input;

    switch (sPokemonJump->helperState)
    {
    case 0:
        sub_0802CDBC(GFXFUNC_MSG_PLAY_AGAIN); // SetUpPokeJumpGfxFuncById
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
            sPokemonJump->helperState++;
        break;
    case 2:
        input = sub_0802D77C(); // HandlePlayAgainInput
        switch (input)
        {
        case MENU_B_PRESSED:
        case 1: // No
            sPokemonJump->playAgainState = PLAY_AGAIN_NO;
            sub_0802CDBC(GFXFUNC_ERASE_MSG); // SetUpPokeJumpGfxFuncById
            sPokemonJump->helperState++;
            break;
        case 0: // Yes
            sPokemonJump->playAgainState = PLAY_AGAIN_YES;
            sub_0802CDBC(GFXFUNC_ERASE_MSG); // SetUpPokeJumpGfxFuncById
            sPokemonJump->helperState++;
            break;
        }
        break;
    case 3:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
            sPokemonJump->helperState++;
        break;
    case 4:
        sub_0802CDBC(GFXFUNC_MSG_COMM_STANDBY); // SetUpPokeJumpGfxFuncById
        sPokemonJump->helperState++;
        break;
    case 5:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
        {
            sPokemonJump->helperState++;
            return FALSE;
        }
        break;
    case 6:
        return FALSE;
    }

    return TRUE;
}

bool32 ClosePokeJumpLink(void)
{
    switch (sPokemonJump->helperState)
    {
    case 0:
        sub_0802D704(); // ClearMessageWindow
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!sub_0802D734()) // RemoveMessageWindow
        {
            sub_0802CDBC(GFXFUNC_MSG_PLAYER_DROPPED); // SetUpPokeJumpGfxFuncById
            sPokemonJump->helperState++;
        }
        break;
    case 2:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
        {
            sPokemonJump->timer = 0;
            sPokemonJump->helperState++;
        }
        break;
    case 3:
        if (++sPokemonJump->timer > 120)
        {
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
            sPokemonJump->helperState++;
        }
        break;
    case 4:
        if (!gPaletteFade.active)
        {
            SetCloseLinkCallback();
            sPokemonJump->helperState++;
        }
        break;
    case 5:
        if (!gReceivedRemoteLinkPlayers)
            return FALSE;
        break;
    }

    return TRUE;
}

bool32 CloseMessageAndResetScore(void)
{
    switch (sPokemonJump->helperState)
    {
    case 0:
        sub_0802D704(); // ClearMessageWindow
        sub_0802DA5C(0); // PrintScore
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!sub_0802D734()) // RemoveMessageWindow
        {
            sPokemonJump->helperState++;
            return FALSE;
        }
        break;
    case 2:
        return FALSE;
    }

    return TRUE;
}

// JP: same task-data layout as US here.
#define tState data[0]
#define tNumReceived data[1]
#define tReceivedPacket(playerId) data[(playerId) + 2]
#define DATAIDX_GAME_STRUCT 14

void Task_CommunicateMonInfo_PokeJump(u8 taskId)
{
    int i;
    s16 *data = gTasks[taskId].data;
    struct PokemonJump *jump = (struct PokemonJump *)GetWordTaskArg(taskId, DATAIDX_GAME_STRUCT);

    switch (tState)
    {
    case 0:
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            tReceivedPacket(i) = FALSE;

        tState++;
        // fall through
    case 1:
        sub_0802DDA4(&jump->monInfo[jump->multiplayerId]); // SendPacket_MonInfo
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
        {
            if (!tReceivedPacket(i) && sub_0802DDC8(i, &jump->monInfo[i])) // RecvPacket_MonInfo
            {
                StringCopy(jump->players[i].name, gLinkPlayers[i].name);
                tReceivedPacket(i) = TRUE;
                tNumReceived++;
                if (tNumReceived == jump->numPlayers)
                {
                    InitPlayerAndJumpTypes();
                    DestroyTask(taskId);
                    break;
                }
            }
        }
        break;
    }
}

#undef tState
#undef tNumReceived
#undef tReceivedPacket

void SetTaskWithPokeJumpStruct(TaskFunc func, u8 taskPriority)
{
    u8 taskId = CreateTask(func, taskPriority);
    SetWordTaskArg(taskId, DATAIDX_GAME_STRUCT, (u32)sPokemonJump);
}

#undef DATAIDX_GAME_STRUCT

void InitVineState(void)
{
    sPokemonJump->vineTimer = 0;
    sPokemonJump->vineState = VINE_UPSWING_LOWER;
    sPokemonJump->vineStateTimer = 0;
    sPokemonJump->vineSpeed = 0;
    sPokemonJump->ignoreJumpInput = FALSE;
    sPokemonJump->gameOver = FALSE;
}

void ResetVineState(void)
{
    sPokemonJump->vineTimer = 0;
    sPokemonJump->vineStateTimer = VINE_STATE_TIMER(VINE_UPSWING_LOWER);
    sPokemonJump->vineState = VINE_UPSWING_LOW;
    sPokemonJump->ignoreJumpInput = FALSE;
    sPokemonJump->gameOver = FALSE;
    sPokemonJump->vineSpeedStage = 0;
    sPokemonJump->vineBaseSpeedIdx = 0;
    sPokemonJump->vineSpeedAccel = 0;
    sPokemonJump->vineSpeedDelay = 0;
    sPokemonJump->atMaxSpeedStage = FALSE;
    sub_0802BC70(); // UpdateVineSpeed
}

void UpdateVineState(void)
{
    if (sPokemonJump->allowVineUpdates)
    {
        sPokemonJump->vineTimer++;
        sPokemonJump->vineStateTimer += sub_0802BC3C(); // GetVineSpeed
        if (sPokemonJump->vineStateTimer >= VINE_STATE_TIMER(NUM_VINESTATES - 1))
            sPokemonJump->vineStateTimer -= VINE_STATE_TIMER(NUM_VINESTATES - 1);

        sPokemonJump->prevVineState = sPokemonJump->vineState;
        sPokemonJump->vineState = sPokemonJump->vineStateTimer >> 8;

        // If beginning upswing
        if (sPokemonJump->vineState > VINE_UPSWING_LOWER && sPokemonJump->prevVineState < VINE_UPSWING_LOW)
        {
            sPokemonJump->ignoreJumpInput++;
            sub_0802BC70(); // UpdateVineSpeed
        }
    }
}

int GetVineSpeed(void)
{
    int speed;

    if (sPokemonJump->gameOver)
        return 0;

    speed = sPokemonJump->vineSpeed;
    if (sPokemonJump->vineStateTimer <= VINE_STATE_TIMER(VINE_LOWEST))
    {
        // If at or below lowest, then vine is in downswing
        // Increase speed in downswing
        sPokemonJump->vineSpeedAccel += 80;
        speed += sPokemonJump->vineSpeedAccel / 256;
    }

    return speed;
}

void UpdateVineSpeed(void)
{
    int baseSpeed;

    sPokemonJump->vineSpeedAccel = 0;
    if (sPokemonJump->vineSpeedDelay)
    {
        sPokemonJump->vineSpeedDelay--;
        if (sPokemonJump->atMaxSpeedStage)
        {
            if (sub_0802BD8C() & 3) // PokeJumpRandom % 4
            {
                sPokemonJump->vineSpeed = sPokemonJump->nextVineSpeed;
            }
            else
            {
                if (sPokemonJump->nextVineSpeed > 54)
                    sPokemonJump->vineSpeed = 30;
                else
                    sPokemonJump->vineSpeed = 82;
            }
        }
    }
    else
    {
        if (!(sPokemonJump->vineBaseSpeedIdx & 8)) // ARRAY_COUNT(sVineBaseSpeeds)
        {
            sPokemonJump->nextVineSpeed = sVineBaseSpeeds[sPokemonJump->vineBaseSpeedIdx] + (sPokemonJump->vineSpeedStage * 7);
            sPokemonJump->vineSpeedDelay = sVineSpeedDelays[sub_0802BD8C() & 3] + 2; // PokeJumpRandom, ARRAY_COUNT(sVineSpeedDelays)
            sPokemonJump->vineBaseSpeedIdx++;
        }
        else
        {
            if (sPokemonJump->vineBaseSpeedIdx == 8) // ARRAY_COUNT(sVineBaseSpeeds)
            {
                if (sPokemonJump->vineSpeedStage < 3)
                    sPokemonJump->vineSpeedStage++;
                else
                    sPokemonJump->atMaxSpeedStage = TRUE;
            }

            baseSpeed = sVineBaseSpeeds[15 - sPokemonJump->vineBaseSpeedIdx];
            sPokemonJump->nextVineSpeed = baseSpeed + (sPokemonJump->vineSpeedStage * 7);
            if (++sPokemonJump->vineBaseSpeedIdx > 15)
            {
                if ((sub_0802BD8C() & 3) == 0) // PokeJumpRandom % 4
                    sPokemonJump->nextVineSpeed -= 5;

                sPokemonJump->vineBaseSpeedIdx = 0;
            }
        }

        sPokemonJump->vineSpeed = sPokemonJump->nextVineSpeed;
    }
}

int PokeJumpRandom(void)
{
    sPokemonJump->rngSeed = ISO_RANDOMIZE1(sPokemonJump->rngSeed);
    return sPokemonJump->rngSeed >> 16;
}

void ResetVineAfterHit(void)
{
    sPokemonJump->gameOver = TRUE;
    sPokemonJump->vineState = VINE_UPSWING_LOWER;
    sPokemonJump->vineStateTimer = VINE_STATE_TIMER(VINE_LOWEST);
    sub_0802BF64(); // AllowVineUpdates
}

bool32 IsGameOver(void)
{
    return sPokemonJump->gameOver;
}

void ResetPlayersMonState(void)
{
    sPokemonJump->player->monState = MONSTATE_NORMAL;
    sPokemonJump->player->prevMonState = MONSTATE_NORMAL;
}

bool32 IsPlayersMonState(u16 monState)
{
    if (sPokemonJump->players[sPokemonJump->multiplayerId].monState == monState)
        return TRUE;
    else
        return FALSE;
}

void SetMonStateJump(void)
{
    sPokemonJump->player->jumpTimeStart = sPokemonJump->vineTimer;
    sPokemonJump->player->prevMonState = sPokemonJump->player->monState;
    sPokemonJump->player->monState = MONSTATE_JUMP;
}

void SetMonStateHit(void)
{
    sPokemonJump->player->prevMonState = sPokemonJump->player->monState;
    sPokemonJump->player->monState = MONSTATE_HIT;
    sPokemonJump->player->jumpTimeStart = sPokemonJump->vineTimer;
    sPokemonJump->player->jumpState = JUMPSTATE_FAILURE;
}

void SetMonStateNormal(void)
{
    sPokemonJump->player->prevMonState = sPokemonJump->player->monState;
    sPokemonJump->player->monState = MONSTATE_NORMAL;
}

void InitGame(struct PokemonJump *jump)
{
    jump->numPlayers = GetLinkPlayerCount();
    jump->comm.funcId = FUNC_RESET_GAME;
    jump->comm.data = 0;
    InitPlayerAndJumpTypes();
    ResetForNewGame(jump);
    if (jump->numPlayers == MAX_RFU_PLAYERS)
        IncrementGamesWithMaxPlayers();
}

void ResetForNewGame(struct PokemonJump *jump)
{
    int i;

    jump->vineState = VINE_UPSWING_LOWER;
    jump->prevVineState = VINE_UPSWING_LOWER;
    jump->vineTimer = 0;
    jump->vineSpeed = 0;
    jump->updateScore = FALSE;
    jump->isLeader = GetMultiplayerId() == 0;
    jump->mainState = 0;
    jump->helperState = 0;
    jump->excellentsInRow = 0;
    jump->excellentsInRowRecord = 0;
    jump->initScoreUpdate = FALSE;
    jump->unused2 = 0;
    jump->unused3 = 0;
    jump->numPlayersAtPeak = 0;
    jump->allowVineUpdates = FALSE;
    jump->allPlayersReady = FALSE;
    jump->funcActive = TRUE;
    jump->comm.jumpScore = 0;
    jump->comm.receivedBonusFlags = 0;
    jump->comm.jumpsInRow = 0;
    jump->unused4 = TRUE;
    jump->showBonus = FALSE;
    jump->skipJumpUpdate = FALSE;
    jump->giveBonus = FALSE;
    jump->linkTimer = 0;
    jump->linkTimerLimit = 0;
    ResetPlayersForNewGame();
    ResetPlayersJumpStates();

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        jump->atJumpPeak[i] = FALSE;
        jump->jumpTimeStarts[i] = 0;
    }
}

void InitPlayerAndJumpTypes(void)
{
    int i, index;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        index = GetPokemonJumpSpeciesIdx(sPokemonJump->monInfo[i].species);
        sPokemonJump->players[i].monJumpType = sPokeJumpMons[index].jumpType;
    }

    sPokemonJump->player = &sPokemonJump->players[sPokemonJump->multiplayerId];
}

void ResetPlayersForNewGame(void)
{
    int i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        sPokemonJump->players[i].jumpTimeStart = 0;
        sPokemonJump->players[i].monState = MONSTATE_NORMAL;
        sPokemonJump->players[i].prevMonState = MONSTATE_NORMAL;
        sPokemonJump->players[i].jumpOffset = 0;
        sPokemonJump->players[i].jumpOffsetIdx = INT_MAX;
        sPokemonJump->players[i].jumpState = JUMPSTATE_NONE;
        sPokemonJump->memberFuncIds[i] = FUNC_NONE;
    }
}

__attribute__((noinline)) void ResetPlayersJumpStates(void)
{
    int i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        sPokemonJump->players[i].jumpState = JUMPSTATE_NONE;
}

s16 GetPokemonJumpSpeciesIdx(u16 species)
{
    u32 i;

    // JP: sPokeJumpMons is ROM data (data/data_b.s), fixed 100 entries.
    for (i = 0; i < 100; i++)
    {
        if (sPokeJumpMons[i].species == species)
            return i;
    }

    return -1; // species isnt allowed
}

struct PokemonJumpRecords *GetPokeJumpRecords(void)
{
    return &gSaveBlock2Ptr->pokeJump;
}

void IncrementGamesWithMaxPlayers(void)
{
    struct PokemonJumpRecords *records = GetPokeJumpRecords();

    if (records->gamesWithMaxPlayers < 9999)
        records->gamesWithMaxPlayers++;
}
