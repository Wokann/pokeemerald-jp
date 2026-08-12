#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "data.h"
#include "digit_obj_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "minigame_countdown.h"
#include "event_data.h"
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
#include "trig.h"

#define PALTAG_1 5
#define PALTAG_2 6
#define GFXTAG_COUNTDOWN 9
#define PALTAG_COUNTDOWN 7

enum {
    BG_INTERFACE,
    BG_BONUSES,
    BG_VENUSAUR,
    BG_SCENERY,
};

// IDs for persistent windows
enum {
    WIN_POINTS,
    WIN_TIMES,
    NUM_WINDOWS
};

enum {
    PACKET_MON_INFO = 1,
    PACKET_UNUSED,
    PACKET_LEADER_STATE,
    PACKET_MEMBER_STATE,
};

// JP: the front-pic coordinate table uses 4-byte entries (size, y_offset,
// 2 padding bytes).  US pokeemerald uses the 2-byte struct MonCoords, so the
// JP layout is kept under the raw data symbol gUnknown_82D45C8.
struct JP_MonFrontPicCoords
{
    u8 size;
    u8 y_offset;
    u16 unused;
};

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

// Which of the three Venusaur pairs is shown for each vine state.
enum {
    VENUSAUR_NEUTRAL,
    VENUSAUR_DOWN,
    VENUSAUR_UP,
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

struct PokeJumpGfxFunc
{
    int id;
    void (*func)(void);
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

// Layout checks against baserom_jp.gba addresses used by the remaining asm.
STATIC_ASSERT(sizeof(struct PokemonJump_MonInfo) == 0xC, MonInfo_size_0xC);
STATIC_ASSERT(sizeof(struct PokemonJump_Player) == 0x24, Player_size_0x24);
STATIC_ASSERT(offsetof(struct PokemonJump, monInfo) == 0x82A8, monInfo_off_82A8);
STATIC_ASSERT(offsetof(struct PokemonJump, players) == 0x82E4, players_off_82E4);
STATIC_ASSERT(offsetof(struct PokemonJump, comm) == 0x70, comm_off_70);
STATIC_ASSERT(offsetof(struct Sprite, data) == 0x2E, sprite_data_off_2E);
STATIC_ASSERT(offsetof(struct PokemonJump_MonInfo, species) == 0, mon_species_off_0);

// JP: the species->jump type table is ROM data at 0x082CECF0 (data/data_b.s,
// gUnknown_82CECF0).  US defines it as sPokeJumpMons in C; JP data has the
// same layout ({u16 species, u16 jumpType}) but jumpType byte values differ
// from US (JP enum order NORMAL=0, FAST=1, SLOW=2).
extern const struct PokemonJumpMons sPokeJumpMons[];
// JP: jump Y-offset table is ROM data at 0x082CEEE8 (data/data_b.s,
// gUnknown_82CEEE8).  3 rows of 48 s8 (row order NORMAL, FAST, SLOW).
extern const s8 sJumpOffsets[][48];

EWRAM_DATA struct PokemonJump *sPokemonJump = NULL;
extern EWRAM_DATA struct PokemonJumpGfx *sPokemonJumpGfx;

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
void SpriteCB_Star(struct Sprite *sprite);
void SpriteCB_MonHitShake(struct Sprite *sprite);
void SpriteCB_MonHitFlash(struct Sprite *sprite);
void SpriteCB_MonIntroBounce(struct Sprite *sprite);
void InitPokeJumpGfx(struct PokemonJumpGfx *jumpGfx);
void SetUpPokeJumpGfxFuncById(int id);
bool32 IsPokeJumpGfxFuncFinished(void);
void SetUpPokeJumpGfxFunc(void (*func)(void));
void Task_RunPokeJumpGfxFunc(u8 taskId);

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
bool32 RecvPacket_MemberStateToLeader(struct PokemonJump_Player *player, int multiplayerId, u8 *funcId, u16 *playAgainState);
extern void sub_0802BED0(void); // UpdateGame
extern void sub_0802C130(void); // TryUpdateScore
void SendPacket_LeaderState(struct PokemonJump_Player *players, struct PokemonJump_CommData *comm);
bool32 RecvPacket_LeaderState(struct PokemonJump_Player *players, struct PokemonJump_CommData *leaderData);
void PrintPokeJumpPlayerName(int multiplayerId, u8 bgColor, u8 fgColor, u8 shadow);
bool32 UpdateBonus(void);
void Task_UpdateBonus(u8 taskId);
bool32 RecvPacket_MemberStateToMember(struct PokemonJump_Player *player, int multiplayerId);
extern void sub_0802AEF0(void); // SendLinkData_Member
void SendPacket_MemberState(struct PokemonJump_Player *player, u8 funcId, u16 playAgainComm);
extern bool32 sub_0802B4D4(void); // DoGameIntro
extern bool32 sub_0802B5C0(void); // HandleSwingRound
extern bool32 sub_0802C22C(void); // UpdateVineHitStates
extern void sub_0802BDAC(void); // ResetVineAfterHit
extern bool32 sub_0802C2D0(void); // AllPlayersJumpedOrHit
extern bool32 sub_0802B658(void); // DoVineHitEffect
extern bool32 sub_0802B878(void); // DoPlayAgainPrompt
extern void sub_0802E04C(u32 jumpScore, u16 jumpsInRow, u16 data); // TryUpdateRecords
extern bool32 sub_0802BA24(void); // CloseMessageAndResetScore
extern bool32 sub_0802B954(void); // ClosePokeJumpLink
extern bool32 sub_0802B74C(void); // TryGivePrize
extern void sub_0802CDBC(int funcId); // SetUpPokeJumpGfxFuncById
extern void sub_0802D704(void); // ClearMessageWindow
extern bool32 sub_0802D734(void); // RemoveMessageWindow
void ResetMonSpriteSubpriorities(void);
void StartMonIntroBounce(int multiplayerId);
bool32 IsMonIntroBounceActive(void);
extern void sub_0802D458(void); // SetUpResetVineGfx
extern bool32 sub_0802D47C(void); // ResetVineGfx
extern void sub_0802BB94(void); // ResetVineState
extern bool32 sub_0802BE24(u16 monState); // IsPlayersMonState
extern void sub_0802BE58(void); // SetMonStateJump
extern void sub_0802BBD8(void); // UpdateVineState
bool32 IsMonHitShakeActive(int multiplayerId);
void StartMonHitFlash(u8 multiplayerId);
void StopMonHitFlash(void);
extern void LoadPokeJumpGfx(void); // sub_0802CE44, still asm
extern const struct PokeJumpGfxFunc sPokeJumpGfxFuncs[10];
void AddPlayerNameWindows(void);
extern const u16 *const sPlayerNameWindowCoords[MAX_RFU_PLAYERS - 1];
void PrintPokeJumpPlayerNames(bool32 highlightSelf);
void DrawPlayerNameWindows_PokeJump(void);
extern const struct BgTemplate sPokeJumpBgTemplates[];
extern const struct WindowTemplate sPokeJumpWindowTemplates[];
extern const u16 sPokeJumpBg_Pal[];
extern const u32 sPokeJumpBg_Gfx[];
extern const u32 sPokeJumpBg_Tilemap[];
extern const u16 sPokeJumpVenusaur_Pal[];
extern const u32 sPokeJumpVenusaur_Gfx[];
extern const u32 sPokeJumpVenusaur_Tilemap[];
extern const u16 sPokeJumpBonuses_Pal[];
extern const u32 sPokeJumpBonuses_Gfx[];
extern const u32 sPokeJumpBonuses_Tilemap[];
extern const u16 sPokeJumpInterface_Pal[];
void InitDigitPrinters(void);
extern const struct SpriteSheet sSpriteSheet_Digits;
extern const struct SpritePalette sSpritePalette_Digits;
void PrintScoreSuffixes(void);
extern const u8 gUnknown_82D1A68[];
void PrintScore(int num);
void CreateJumpMonSprites(void);
extern const s16 *const sMonXCoords[MAX_RFU_PLAYERS - 1];
extern const struct JP_MonFrontPicCoords gUnknown_82D45C8[];
void CreatePokeJumpYesNoMenu(u16 left, u16 top, u8 cursorPos);
extern void CreateYesNoMenuAtPos(const struct WindowTemplate *window, u8 fontId, u8 left, u8 top, u16 baseTileNum, u8 paletteNum, u8 initialCursorPos);
extern const u8 gText_WantToPlayAgain2[];
extern const u8 gText_SavingDontTurnOffPower[];
extern const u8 gText_SomeoneDroppedOut2[];
extern const u8 gText_CommunicationStandby4[];
extern void sub_08198D88(void); // EraseYesNoWindow
extern void sub_0802BE08(void); // ResetPlayersMonState
void SendPacket_MonInfo(struct PokemonJump_MonInfo *monInfo);
bool32 RecvPacket_MonInfo(int multiplayerId, struct PokemonJump_MonInfo *monInfo);
extern void sub_0802BC70(void); // UpdateVineSpeed
extern int sub_0802BC3C(void); // GetVineSpeed
extern int sub_0802BD8C(void); // PokeJumpRandom

// JP: vine speed tables are ROM data (data/data_b.s gUnknown_82CEEC8 /
// gUnknown_82CEED8); same layouts as US sVineBaseSpeeds / sVineSpeedDelays.
// US keeps an anonymous struct for sPrizeQuantityData; JP names it so the
// ROM table (gUnknown_82CEFA0) can be aliased as an extern array.
struct PrizeQuantityData
{
    u32 score;
    u32 quantity;
};

extern const u16 sVineBaseSpeeds[];
extern const u16 sVineSpeedDelays[];
extern const u16 sSoundEffects[];
extern const int sScoreBonuses[];
extern const u16 sPrizeItems[];
extern const struct PrizeQuantityData sPrizeQuantityData[];
extern const struct CompressedSpriteSheet sCompressedSpriteSheets[5];
extern const struct SpritePalette sSpritePalettes[2];
extern const struct SpriteTemplate sSpriteTemplate_JumpMon;
extern const struct SpriteTemplate sSpriteTemplate_Star;
extern const struct SpriteTemplate *const sSpriteTemplates_Vine[4];
extern const s16 sVineXCoords[8];
extern const s16 sVineYCoords[4][10];
int DoSameJumpTimeBonus(u8 flags);
void PrintJumpsInRow(u16 num);
extern void sub_0802BF74(void); // HandleMonState
extern void sub_0802BF34(void); // TryUpdateVineSwing
void UpdateVineSwing(int vineState);
void SetMonSpriteY(u32 id, s16 y);
extern void sub_0802C08C(int playerId); // UpdateJump
void StartMonHitShake(u8 multiplayerId);
extern const u8 sVenusaurStates[];
void ShowBonus(u8 numPlayers);

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
        if (RecvPacket_MemberStateToLeader(&sPokemonJump->players[i], i, &funcId, &playAgainState))
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
        SendPacket_LeaderState(sPokemonJump->players, &sPokemonJump->comm);

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
    if (RecvPacket_LeaderState(sPokemonJump->players, &leaderData))
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
            if (RecvPacket_MemberStateToMember(&sPokemonJump->players[i], i))
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
        SendPacket_MemberState(&sPokemonJump->players[sPokemonJump->multiplayerId], sPokemonJump->comm.funcId, sPokemonJump->playAgainComm);

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
        if (AreLinkQueuesEmpty())
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
            if (HasEnoughScoreForPrize())
            {
                sPokemonJump->comm.data = GetPrizeData();
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
            if (ShouldPlayAgain())
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
        if (AreLinkQueuesEmpty())
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
        ResetMonSpriteSubpriorities();
        sPokemonJump->helperState++;
        break;
    case 1:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
        {
            StartMonIntroBounce(sPokemonJump->multiplayerId);
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
        if (sub_0802CDE4() != TRUE && IsMonIntroBounceActive() != TRUE) // IsPokeJumpGfxFuncFinished, IsMonIntroBounceActive
            sPokemonJump->helperState++;
        break;
    case 4:
        sub_0802CDBC(GFXFUNC_COUNTDOWN); // SetUpPokeJumpGfxFuncById
        sPokemonJump->helperState++;
        break;
    case 5:
        if (!sub_0802CDE4()) // IsPokeJumpGfxFuncFinished
        {
            DisallowVineUpdates();
            sub_0802D458(); // SetUpResetVineGfx
            sPokemonJump->helperState++;
        }
        break;
    case 6:
        if (!sub_0802D47C()) // ResetVineGfx
        {
            AllowVineUpdates();
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
            if (IsMonHitShakeActive(i) == TRUE)
                return TRUE;
        }

        sPokemonJump->helperState++;
        break;
    case 1:
        for (i = 0; i < sPokemonJump->numPlayers; i++)
        {
            if (sPokemonJump->players[i].monState == MONSTATE_HIT)
                StartMonHitFlash(i);
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
            StopMonHitFlash();
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
        UnpackPrizeData(sPokemonJump->comm.data, &sPokemonJump->prizeItemId, &sPokemonJump->prizeItemQuantity);
        PrintPrizeMessage(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity);
        sPokemonJump->helperState++;
        break;
    case 1:
    case 4:
        if (!DoPrizeMessageAndFanfare())
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
            sPokemonJump->prizeItemQuantity = GetQuantityLimitedByBag(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity);
            if (sPokemonJump->prizeItemQuantity && AddBagItem(sPokemonJump->prizeItemId, sPokemonJump->prizeItemQuantity))
            {
                if (!CheckBagHasSpace(sPokemonJump->prizeItemId, 1))
                {
                    // An item was given successfully, but no room for any more.
                    // It's possible the full prize quantity had to be limited
            PrintPrizeFilledBagMessage(sPokemonJump->prizeItemId);
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
                PrintNoRoomForPrizeMessage(sPokemonJump->prizeItemId);
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
        input = HandlePlayAgainInput();
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
        ClearMessageWindow();
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
        PrintScore(0);
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
        SendPacket_MonInfo(&jump->monInfo[jump->multiplayerId]);
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
        {
            if (!tReceivedPacket(i) && RecvPacket_MonInfo(i, &jump->monInfo[i]))
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
    AllowVineUpdates();
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

void UpdateGame(void)
{
    if (sPokemonJump->updateScore)
    {
        PrintScore(sPokemonJump->comm.jumpScore);
        sPokemonJump->updateScore = FALSE;
        if (sPokemonJump->showBonus)
        {
            int numPlayers = DoSameJumpTimeBonus(sPokemonJump->comm.receivedBonusFlags);
            PlaySE(sSoundEffects[numPlayers - 2]);
            sPokemonJump->showBonus = FALSE;
        }
    }

    PrintJumpsInRow(sPokemonJump->comm.jumpsInRow);
    sub_0802BF74(); // HandleMonState
    sub_0802BF34(); // TryUpdateVineSwing
}

void TryUpdateVineSwing(void)
{
    if (sPokemonJump->allowVineUpdates)
        UpdateVineSwing(sPokemonJump->vineState);
}

void DisallowVineUpdates(void)
{
    sPokemonJump->allowVineUpdates = FALSE;
}

void AllowVineUpdates(void)
{
    sPokemonJump->allowVineUpdates = TRUE;
}

#define F_SE_JUMP (1 << 0)
#define F_SE_FAIL (1 << 1)

void HandleMonState(void)
{
    int i;
    int soundFlags = 0;
    int numPlayers = sPokemonJump->numPlayers;

    for (i = 0; i < numPlayers; i++)
    {
        switch (sPokemonJump->players[i].monState)
        {
        case MONSTATE_NORMAL:
            SetMonSpriteY(i, 0);
            break;
        case MONSTATE_JUMP:
            if (sPokemonJump->players[i].prevMonState != MONSTATE_JUMP || sPokemonJump->players[i].jumpTimeStart != sPokemonJump->jumpTimeStarts[i])
            {
                // This is a new jump, play SE and init fields for jump handling
                if (i == sPokemonJump->multiplayerId)
                    sPokemonJump->players[i].prevMonState = MONSTATE_JUMP;

                soundFlags |= F_SE_JUMP;
                sPokemonJump->players[i].jumpOffsetIdx = INT_MAX;
                sPokemonJump->jumpTimeStarts[i] = sPokemonJump->players[i].jumpTimeStart;
            }

            sub_0802C08C(i); // UpdateJump
            break;
        case MONSTATE_HIT:
            if (sPokemonJump->players[i].prevMonState != MONSTATE_HIT)
            {
                if (i == sPokemonJump->multiplayerId)
                    sPokemonJump->players[i].prevMonState = MONSTATE_HIT;

                soundFlags |= F_SE_FAIL;
                StartMonHitShake(i);
            }
            break;
        }
    }

    if (soundFlags & F_SE_FAIL)
        PlaySE(SE_RG_POKE_JUMP_FAILURE);
    else if (soundFlags & F_SE_JUMP)
        PlaySE(SE_LEDGE);
}

void UpdateJump(int multiplayerId)
{
    int jumpOffsetIdx;
    int jumpOffset;
    struct PokemonJump_Player *player;

    if (sPokemonJump->skipJumpUpdate) // Always false
        return;

    player = &sPokemonJump->players[multiplayerId];
    if (player->jumpOffsetIdx != INT_MAX)
    {
        player->jumpOffsetIdx++;
        jumpOffsetIdx = player->jumpOffsetIdx;
    }
    else
    {
        jumpOffsetIdx = sPokemonJump->vineTimer - player->jumpTimeStart;
        if (jumpOffsetIdx >= 65000)
        {
            jumpOffsetIdx -= 65000;
            jumpOffsetIdx += sPokemonJump->vineTimer;
        }

        player->jumpOffsetIdx = jumpOffsetIdx;
    }

    if (jumpOffsetIdx < 4)
        return;

    jumpOffsetIdx -= 4;
    if (jumpOffsetIdx < 48) // ARRAY_COUNT(sJumpOffsets[0])
        jumpOffset = sJumpOffsets[player->monJumpType][jumpOffsetIdx];
    else
        jumpOffset = 0;

    SetMonSpriteY(multiplayerId, jumpOffset);
    if (jumpOffset == 0 && multiplayerId == sPokemonJump->multiplayerId)
        SetMonStateNormal();

    player->jumpOffset = jumpOffset;
}

void TryUpdateScore(void)
{
    if (sPokemonJump->vineState == VINE_UPSWING_HIGH && sPokemonJump->prevVineState == VINE_UPSWING_LOW)
    {
        // Vine has passed through the point where it
        // would hit the players, allow score to update

        if (!sPokemonJump->initScoreUpdate)
        {
            ClearUnreadField();
            sPokemonJump->numPlayersAtPeak = 0;
            sPokemonJump->initScoreUpdate = TRUE;
            sPokemonJump->comm.receivedBonusFlags = 0;
        }
        else
        {
            if (sPokemonJump->numPlayersAtPeak == MAX_RFU_PLAYERS)
            {
                // An 'excellent' is the max 5 players all jumping synchronously
                sPokemonJump->excellentsInRow++;
                TryUpdateExcellentsRecord(sPokemonJump->excellentsInRow);
            }
            else
            {
                sPokemonJump->excellentsInRow = 0;
            }

            if (sPokemonJump->numPlayersAtPeak > 1)
            {
                sPokemonJump->giveBonus = TRUE;
                // Unclear why atJumpPeak needed to be copied over twice
                memcpy(sPokemonJump->atJumpPeak3, sPokemonJump->atJumpPeak2, sizeof(u8) * MAX_RFU_PLAYERS);
            }

            ClearUnreadField();
            sPokemonJump->numPlayersAtPeak = 0;
            sPokemonJump->initScoreUpdate = TRUE;
            sPokemonJump->comm.receivedBonusFlags = 0;
            if (sPokemonJump->comm.jumpsInRow <= 9998) // MAX_JUMPS
                sPokemonJump->comm.jumpsInRow++;

            AddJumpScore(10);
            SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        }
    }

    if (sPokemonJump->giveBonus && (DidAllPlayersClearVine() == TRUE || sPokemonJump->vineState == VINE_HIGHEST))
    {
        int numPlayers = GetNumPlayersForBonus(sPokemonJump->atJumpPeak3);
        AddJumpScore(GetScoreBonus(numPlayers));
        SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        sPokemonJump->giveBonus = FALSE;
    }

    if (sPokemonJump->initScoreUpdate)
    {
        int numAtPeak = GetPlayersAtJumpPeak();
        if (numAtPeak > sPokemonJump->numPlayersAtPeak)
        {
            sPokemonJump->numPlayersAtPeak = numAtPeak;
            memcpy(sPokemonJump->atJumpPeak2, sPokemonJump->atJumpPeak, sizeof(u8) * MAX_RFU_PLAYERS);
        }
    }
}

bool32 UpdateVineHitStates(void)
{
    int i;

    if (sPokemonJump->vineState == VINE_UPSWING_LOWER && sPokemonJump->player->jumpOffset == 0)
    {
        // Vine is in position to hit the player and jump offset is 0.
        // Unless the player had just jumped and has been forced to the ground
        // by someone else getting hit, the player has been hit
        if (sPokemonJump->player->prevMonState == MONSTATE_JUMP && IsGameOver() == TRUE)
        {
            sPokemonJump->player->jumpState = JUMPSTATE_SUCCESS;
        }
        else
        {
            // Hit vine
            SetMonStateHit();
            SetLinkTimeInterval(LINK_INTERVAL_SHORT);
        }
    }

    if (sPokemonJump->vineState == VINE_UPSWING_LOW
     && sPokemonJump->prevVineState == VINE_UPSWING_LOWER
     && sPokemonJump->player->monState != MONSTATE_HIT)
    {
        sPokemonJump->player->jumpState = JUMPSTATE_SUCCESS;
        SetLinkTimeInterval(LINK_INTERVAL_SHORT);
    }

    for (i = 0; i < sPokemonJump->numPlayers; i++)
    {
        if (sPokemonJump->players[i].monState == MONSTATE_HIT)
            return FALSE;
    }

    return TRUE;
}

bool32 AllPlayersJumpedOrHit(void)
{
    int i;
    int numPlayers = sPokemonJump->numPlayers;
    int numJumpedOrHit = 0;
    for (i = 0; i < numPlayers; i++)
    {
        if (sPokemonJump->players[i].jumpState != JUMPSTATE_NONE)
            numJumpedOrHit++;
    }

    return numJumpedOrHit == numPlayers;
}

bool32 DidAllPlayersClearVine(void)
{
    int i;
    for (i = 0; i < sPokemonJump->numPlayers; i++)
    {
        if (sPokemonJump->players[i].jumpState != JUMPSTATE_SUCCESS)
            return FALSE;
    }

    return TRUE;
}

bool32 ShouldPlayAgain(void)
{
    int i;

    if (sPokemonJump->playAgainState == PLAY_AGAIN_NO)
        return FALSE;

    for (i = 1; i < sPokemonJump->numPlayers; i++)
    {
        if (sPokemonJump->playAgainStates[i] == PLAY_AGAIN_NO)
            return FALSE;
    }

    return TRUE;
}

void AddJumpScore(int score)
{
    sPokemonJump->comm.jumpScore += score;
    sPokemonJump->updateScore = TRUE;
    if (sPokemonJump->comm.jumpScore >= 99990) // MAX_JUMP_SCORE
        sPokemonJump->comm.jumpScore = 99990;
}

int GetPlayersAtJumpPeak(void)
{
    int i;
    int numAtPeak = 0;
    int numPlayers = sPokemonJump->numPlayers;

    for (i = 0; i < numPlayers; i++)
    {
        if (sPokemonJump->players[i].jumpOffset == JUMP_PEAK)
        {
            sPokemonJump->atJumpPeak[i] = TRUE;
            numAtPeak++;
        }
        else
        {
            sPokemonJump->atJumpPeak[i] = FALSE;
        }
    }

    return numAtPeak;
}

bool32 AreLinkQueuesEmpty(void)
{
    return !gRfu.recvQueue.count && !gRfu.sendQueue.count;
}

int GetNumPlayersForBonus(u8 *atJumpPeak)
{
    int i = 0;
    int flags = 0;
    int count = 0;

    for (; i < MAX_RFU_PLAYERS; i++)
    {
        if (atJumpPeak[i])
        {
            flags |= 1 << i;
            count++;
        }
    }

    sPokemonJump->comm.receivedBonusFlags = flags;
    if (flags)
        sPokemonJump->showBonus = TRUE;

    return count;
}

void ClearUnreadField(void)
{
    sPokemonJump->unused3 = 0;
}

int GetScoreBonus(int numPlayers)
{
    return sScoreBonuses[numPlayers];
}

void TryUpdateExcellentsRecord(u16 excellentsInRow)
{
    if (excellentsInRow > sPokemonJump->excellentsInRowRecord)
        sPokemonJump->excellentsInRowRecord = excellentsInRow;
}

bool32 HasEnoughScoreForPrize(void)
{
    if (sPokemonJump->comm.jumpScore >= sPrizeQuantityData[0].score)
        return TRUE;
    else
        return FALSE;
}

u16 GetPrizeData(void)
{
    u16 itemId = GetPrizeItemId_PokeJump();
    u16 quantity = GetPrizeQuantity();
    return (quantity << 12) | (itemId & 0xFFF);
}

void UnpackPrizeData(u16 data, u16 *itemId, u16 *quantity)
{
    *quantity = data >> 12;
    *itemId = data & 0xFFF;
}

u16 GetPrizeItemId_PokeJump(void)
{
    u16 index = Random() % 8; // ARRAY_COUNT(sPrizeItems)
    return sPrizeItems[index];
}

u16 GetPrizeQuantity(void)
{
    u32 quantity, i;

    quantity = 0;
    for (i = 0; i < 5; i++) // ARRAY_COUNT(sPrizeQuantityData)
    {
        if (sPokemonJump->comm.jumpScore >= sPrizeQuantityData[i].score)
            quantity = sPrizeQuantityData[i].quantity;
        else
            break;
    }

    return quantity;
}

u16 GetQuantityLimitedByBag(u16 item, u16 quantity)
{
    while (quantity && !CheckBagHasSpace(item, quantity))
        quantity--;

    return quantity;
}

u16 GetNumPokeJumpPlayers(void)
{
    return GetLinkPlayerCount();
}

u16 GetPokeJumpMultiplayerId(void)
{
    return sPokemonJump->multiplayerId;
}

struct PokemonJump_MonInfo *GetMonInfoByMultiplayerId(u8 multiplayerId)
{
    return &sPokemonJump->monInfo[multiplayerId];
}

u8 *GetPokeJumpPlayerName(u8 multiplayerId)
{
    return sPokemonJump->players[multiplayerId].name;
}

bool32 IsSpeciesAllowedInPokemonJump(u16 species)
{
    return GetPokemonJumpSpeciesIdx(species) > -1;
}

void IsPokemonJumpSpeciesInParty(void)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData2(&gPlayerParty[i], MON_DATA_SANITY_HAS_SPECIES))
        {
            u16 species = GetMonData2(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
            if (IsSpeciesAllowedInPokemonJump(species))
            {
                gSpecialVar_Result = TRUE;
                return;
            }
        }
    }

    gSpecialVar_Result = FALSE;
}

void LoadSpriteSheetsAndPalettes(struct PokemonJumpGfx *jumpGfx)
{
    int i;

    for (i = 0; i < ARRAY_COUNT(sCompressedSpriteSheets); i++)
        LoadCompressedSpriteSheet(&sCompressedSpriteSheets[i]);

    for (i = 0; i < ARRAY_COUNT(sSpritePalettes); i++)
        LoadSpritePalette(&sSpritePalettes[i]);

    jumpGfx->vinePalNumDownswing = IndexOfSpritePaletteTag(PALTAG_1);
    jumpGfx->vinePalNumUpswing = IndexOfSpritePaletteTag(PALTAG_2);
}

void ResetPokeJumpSpriteData(struct Sprite *sprite)
{
    int i;
    for (i = 0; i < (int)ARRAY_COUNT(sprite->data); i++)
        sprite->data[i] = 0;
}

void CreateJumpMonSprite(struct PokemonJumpGfx *jumpGfx, struct PokemonJump_MonInfo *monInfo, s16 x, s16 y, u8 multiplayerId)
{
    struct SpriteTemplate spriteTemplate;
    struct SpriteSheet spriteSheet;
    struct CompressedSpritePalette spritePalette;
    u8 *buffer;
    u8 *unusedBuffer;
    u8 subpriority;
    u8 spriteId;

    spriteTemplate = sSpriteTemplate_JumpMon;
    buffer = Alloc(MON_PIC_SIZE * MAX_MON_PIC_FRAMES);
    unusedBuffer = Alloc(MON_PIC_SIZE);
    if (multiplayerId == GetPokeJumpMultiplayerId())
        subpriority = 3;
    else
        subpriority = multiplayerId + 4;

    if (buffer && unusedBuffer)
    {
        HandleLoadSpecialPokePic(
            &gMonStillFrontPicTable[monInfo->species],
            buffer,
            monInfo->species,
            monInfo->personality);

        spriteSheet.data = buffer;
        spriteSheet.tag = multiplayerId;
        spriteSheet.size = MON_PIC_SIZE;
        LoadSpriteSheet(&spriteSheet);

        spritePalette.data = GetMonSpritePalFromSpeciesAndPersonality(monInfo->species, monInfo->otId, monInfo->personality);
        spritePalette.tag = multiplayerId;
        LoadCompressedSpritePalette(&spritePalette);

        Free(buffer);
        Free(unusedBuffer);

        spriteTemplate.tileTag += multiplayerId;
        spriteTemplate.paletteTag += multiplayerId;
        spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
        if (spriteId != MAX_SPRITES)
        {
            jumpGfx->monSprites[multiplayerId] = &gSprites[spriteId];
            jumpGfx->monSpriteSubpriorities[multiplayerId] = subpriority;
            return;
        }
    }

    jumpGfx->monSprites[multiplayerId] = NULL;
}

#define sState data[0]
#define sTimer data[1]
#define sOffset data[7] // Never read

void DoStarAnim(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    ResetPokeJumpSpriteData(jumpGfx->starSprites[multiplayerId]);
    jumpGfx->starSprites[multiplayerId]->sOffset = jumpGfx->monSprites[multiplayerId] - gSprites;
    jumpGfx->starSprites[multiplayerId]->invisible = FALSE;
    jumpGfx->starSprites[multiplayerId]->y = 96;
    jumpGfx->starSprites[multiplayerId]->callback = SpriteCB_Star;
    StartSpriteAnim(jumpGfx->starSprites[multiplayerId], 1);
}

void SpriteCB_Star(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (sprite->animEnded)
        {
            sprite->invisible = TRUE;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    case 1:
        sprite->y--;
        sprite->sTimer++;
        if (sprite->y <= 72)
        {
            sprite->y = 72;
            sprite->sState++;
        }
        break;
    case 2:
        if (++sprite->sTimer >= 48)
        {
            sprite->invisible = TRUE;
            sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

#undef sState
#undef sTimer
#undef sOffset

void Gfx_StartMonHitShake(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    jumpGfx->monSprites[multiplayerId]->callback = SpriteCB_MonHitShake;
    jumpGfx->monSprites[multiplayerId]->y2 = 0;
    ResetPokeJumpSpriteData(jumpGfx->monSprites[multiplayerId]);
}

bool32 Gfx_IsMonHitShakeActive(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    return jumpGfx->monSprites[multiplayerId]->callback == SpriteCB_MonHitShake;
}

void Gfx_StartMonHitFlash(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    ResetPokeJumpSpriteData(jumpGfx->monSprites[multiplayerId]);
    jumpGfx->monSprites[multiplayerId]->callback = SpriteCB_MonHitFlash;
}

void Gfx_ResetMonSpriteSubpriorities(struct PokemonJumpGfx *jumpGfx)
{
    int i;
    u16 numPlayers = GetNumPokeJumpPlayers();
    for (i = 0; i < numPlayers; i++)
        jumpGfx->monSprites[i]->subpriority = jumpGfx->monSpriteSubpriorities[i];
}

void Gfx_StartMonIntroBounce(struct PokemonJumpGfx *jumpGfx, int multiplayerId)
{
    ResetPokeJumpSpriteData(jumpGfx->monSprites[multiplayerId]);
    jumpGfx->monSprites[multiplayerId]->callback = SpriteCB_MonIntroBounce;
}

bool32 Gfx_IsMonIntroBounceActive(struct PokemonJumpGfx *jumpGfx)
{
    int i;
    u16 numPlayers = GetNumPokeJumpPlayers();
    for (i = 0; i < numPlayers; i++)
    {
        if (jumpGfx->monSprites[i]->callback == SpriteCB_MonIntroBounce)
            return TRUE;
    }

    return FALSE;
}

#define sState   data[0]
#define sHopPos  data[1]
#define sNumHops data[2]

void SpriteCB_MonIntroBounce(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        PlaySE(SE_BIKE_HOP);
        sprite->sHopPos = 0;
        sprite->sState++;
        // fall through
    case 1:
        sprite->sHopPos += 4;
        if (sprite->sHopPos > 127)
            sprite->sHopPos = 0;

        sprite->y2 = -(gSineTable[sprite->sHopPos] >> 3);
        if (sprite->sHopPos == 0)
        {
            if (++sprite->sNumHops < 2)
                sprite->sState = 0;
            else
                sprite->callback = SpriteCallbackDummy;
        }
        break;
    }
}

#undef sState
#undef sHopPos
#undef sNumHops

void CreateStarSprite(struct PokemonJumpGfx *jumpGfx, s16 x, s16 y, u8 multiplayerId)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_Star, x, y, 1);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].invisible = TRUE;
        jumpGfx->starSprites[multiplayerId] = &gSprites[spriteId];
    }
}

void CreateVineSprites(struct PokemonJumpGfx *jumpGfx)
{
    int i;
    int count;
    u8 spriteId;

    count = 0;
    for (i = 0; i < VINE_SPRITES_PER_SIDE; i++)
    {
        spriteId = CreateSprite(sSpriteTemplates_Vine[i], sVineXCoords[count], sVineYCoords[i][0], 2);
        jumpGfx->vineSprites[count] = &gSprites[spriteId];
        count++;
    }

    for (i = VINE_SPRITES_PER_SIDE - 1; i >= 0; i--)
    {
        spriteId = CreateSprite(sSpriteTemplates_Vine[i], sVineXCoords[count], sVineYCoords[i][0], 2);
        jumpGfx->vineSprites[count] = &gSprites[spriteId];
        jumpGfx->vineSprites[count]->hFlip = TRUE;
        count++;
    }
}

void UpdateVineAnim(struct PokemonJumpGfx *jumpGfx, int vineState)
{
    int i, count, palNum;
    int priority;

    if (vineState > VINE_LOWEST)
    {
        // animNums for vine on upswing are same as
        // on downswing but in reverse
        vineState = NUM_VINESTATES - vineState;
        priority = 3; // Set vine behind Pokemon
        palNum = jumpGfx->vinePalNumUpswing;
    }
    else
    {
        priority = 2; // Set vine in front of Pokemon
        palNum = jumpGfx->vinePalNumDownswing;
    }

    count = 0;
    for (i = 0; i < VINE_SPRITES_PER_SIDE; i++)
    {
        jumpGfx->vineSprites[count]->y = sVineYCoords[i][vineState];
        jumpGfx->vineSprites[count]->oam.priority = priority;
        jumpGfx->vineSprites[count]->oam.paletteNum = palNum;
        StartSpriteAnim(jumpGfx->vineSprites[count], vineState);
        count++;
    }

    for (i = VINE_SPRITES_PER_SIDE - 1; i >= 0; i--)
    {
        jumpGfx->vineSprites[count]->y = sVineYCoords[i][vineState];
        jumpGfx->vineSprites[count]->oam.priority = priority;
        jumpGfx->vineSprites[count]->oam.paletteNum = palNum;
        StartSpriteAnim(jumpGfx->vineSprites[count], vineState);
        count++;
    }
}

void StartPokeJumpCountdown(struct PokemonJumpGfx *jumpGfx)
{
    StartMinigameCountdown(GFXTAG_COUNTDOWN, PALTAG_COUNTDOWN, 120, 80, 0);
    Gfx_ResetMonSpriteSubpriorities(jumpGfx);
}

bool32 IsPokeJumpCountdownRunning(void)
{
    return IsMinigameCountdownRunning();
}

void StartPokeJumpGfx(struct PokemonJumpGfx *jumpGfx)
{
    u8 taskId;

    sPokemonJumpGfx = jumpGfx;
    InitPokeJumpGfx(sPokemonJumpGfx);
    taskId = CreateTask(Task_RunPokeJumpGfxFunc, 3);
    sPokemonJumpGfx->taskId = taskId;
    SetWordTaskArg(sPokemonJumpGfx->taskId, 2, (u32)sPokemonJumpGfx);
    SetUpPokeJumpGfxFunc(LoadPokeJumpGfx);
}

void InitPokeJumpGfx(struct PokemonJumpGfx *jumpGfx)
{
    jumpGfx->mainState = 0;
    jumpGfx->funcFinished = FALSE;
    jumpGfx->msgWindowId = WINDOW_NONE;
}

void SetUpPokeJumpGfxFuncById(int id)
{
    int i;

    for (i = 0; i < ARRAY_COUNT(sPokeJumpGfxFuncs); i++)
    {
        if (sPokeJumpGfxFuncs[i].id == id)
            SetUpPokeJumpGfxFunc(sPokeJumpGfxFuncs[i].func);
    }
}

bool32 IsPokeJumpGfxFuncFinished(void)
{
    return (sPokemonJumpGfx->funcFinished != TRUE);
}

void SetUpPokeJumpGfxFunc(void (*func)(void))
{
    SetWordTaskArg(sPokemonJumpGfx->taskId, 0, (u32)func);
    sPokemonJumpGfx->mainState = 0;
    sPokemonJumpGfx->funcFinished = FALSE;
}

void Task_RunPokeJumpGfxFunc(u8 taskId)
{
    if (!sPokemonJumpGfx->funcFinished)
    {
        // Read the function set in the data by SetUpPokeJumpGfxFunc
        void (*func)(void) = (void *)(GetWordTaskArg(taskId, 0));

        func();
    }
}

void LoadPokeJumpGfx(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sPokeJumpBgTemplates, 4); // ARRAY_COUNT(sPokeJumpBgTemplates)
        InitWindows(sPokeJumpWindowTemplates);
        ResetTempTileDataBuffers();
        LoadSpriteSheetsAndPalettes(sPokemonJumpGfx);
        sub_0802DA00(); // InitDigitPrinters
        LoadPalette(sPokeJumpBg_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        DecompressAndCopyTileDataToVram(BG_SCENERY, sPokeJumpBg_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_SCENERY, sPokeJumpBg_Tilemap, 0, 0, 1);
        LoadPalette(sPokeJumpVenusaur_Pal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
        DecompressAndCopyTileDataToVram(BG_VENUSAUR, sPokeJumpVenusaur_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_VENUSAUR, sPokeJumpVenusaur_Tilemap, 0, 0, 1);
        LoadPalette(sPokeJumpBonuses_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        DecompressAndCopyTileDataToVram(BG_BONUSES, sPokeJumpBonuses_Gfx, 0, 0, 0);
        DecompressAndCopyTileDataToVram(BG_BONUSES, sPokeJumpBonuses_Tilemap, 0, 0, 1);
        LoadPalette(sPokeJumpInterface_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        SetBgTilemapBuffer(BG_INTERFACE, sPokemonJumpGfx->tilemapBuffer);
        FillBgTilemapBufferRect_Palette0(BG_INTERFACE, 0, 0, 0, 0x20, 0x20);
        PrintScoreSuffixes();
        PrintScore(0);
        LoadUserWindowBorderGfxOnBg(0, 1, BG_PLTT_ID(14));
        CopyBgTilemapBufferToVram(BG_INTERFACE);
        CopyBgTilemapBufferToVram(BG_VENUSAUR);
        CopyBgTilemapBufferToVram(BG_BONUSES);
        ResetBgPositions();
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            CreateJumpMonSprites();
            CreateVineSprites(sPokemonJumpGfx);
            UpdateVineAnim(sPokemonJumpGfx, VINE_UPSWING_LOWER);
            ShowBg(BG_SCENERY);
            ShowBg(BG_INTERFACE);
            ShowBg(BG_VENUSAUR);
            HideBg(BG_BONUSES);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void PrintPlayerNamesNoHighlight(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        AddPlayerNameWindows();
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PrintPokeJumpPlayerNames(FALSE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            DrawPlayerNameWindows_PokeJump();
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void PrintPlayerNamesWithHighlight(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        AddPlayerNameWindows();
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PrintPokeJumpPlayerNames(TRUE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            DrawPlayerNameWindows_PokeJump();
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void ErasePlayerNames(void)
{
    int i, numPlayers;

    numPlayers = GetNumPokeJumpPlayers();
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        for (i = 0; i < numPlayers; i++)
            ClearWindowTilemap(sPokemonJumpGfx->nameWindowIds[i]);

        CopyBgTilemapBufferToVram(BG_INTERFACE);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            for (i = 0; i < numPlayers; i++)
                RemoveWindow(sPokemonJumpGfx->nameWindowIds[i]);

            sPokemonJumpGfx->funcFinished = TRUE;
        }
        break;
    }
}

void Msg_WantToPlayAgain_PokeJump(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sPokemonJumpGfx->msgWindowId = AddMessageWindow(1, 8, 20, 2);
        AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, gText_WantToPlayAgain2, 0, 2, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter((u8)sPokemonJumpGfx->msgWindowId, 1, 14);
            CreatePokeJumpYesNoMenu(23, 7, 0);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void Msg_SavingDontTurnOff_PokeJump(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sPokemonJumpGfx->msgWindowId = AddMessageWindow(2, 7, 26, 4);
        AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, gText_SavingDontTurnOffPower, 0, 2, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter((u8)sPokemonJumpGfx->msgWindowId, 1, 14);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void EraseMessage_PokeJump(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sub_0802D704(); // ClearMessageWindow
        sub_08198D88(); // EraseYesNoWindow
        CopyBgTilemapBufferToVram(BG_INTERFACE);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!RemoveMessageWindow_PokeJump() && !IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void Msg_SomeoneDroppedOut_PokeJump(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sPokemonJumpGfx->msgWindowId = AddMessageWindow(2, 8, 22, 4);
        AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, gText_SomeoneDroppedOut2, 0, 2, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter((u8)sPokemonJumpGfx->msgWindowId, 1, 14);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void Msg_CommunicationStandby_PokeJump(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        sPokemonJumpGfx->msgWindowId = AddMessageWindow(7, 10, 16, 2);
        AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, gText_CommunicationStandby4, 0, 2, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter((u8)sPokemonJumpGfx->msgWindowId, 1, 14);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->mainState++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void DoPokeJumpCountdown(void)
{
    switch (sPokemonJumpGfx->mainState)
    {
    case 0:
        StartPokeJumpCountdown(sPokemonJumpGfx);
        sPokemonJumpGfx->mainState++;
        break;
    case 1:
        if (!IsPokeJumpCountdownRunning())
            sPokemonJumpGfx->funcFinished = TRUE;
        break;
    }
}

void SetUpResetVineGfx(void)
{
    sPokemonJumpGfx->resetVineState = 0;
    sPokemonJumpGfx->resetVineTimer = 0;
    sPokemonJumpGfx->vineState = VINE_UPSWING_LOWER;
    UpdateVineSwing(sPokemonJumpGfx->vineState);
}

bool32 ResetVineGfx(void)
{
    switch (sPokemonJumpGfx->resetVineState)
    {
    case 0:
        sPokemonJumpGfx->resetVineTimer++;
        if (sPokemonJumpGfx->resetVineTimer > 10)
        {
            sPokemonJumpGfx->resetVineTimer = 0;
            sPokemonJumpGfx->vineState++;
            if (sPokemonJumpGfx->vineState >= NUM_VINESTATES)
            {
                sPokemonJumpGfx->vineState = VINE_HIGHEST;
                sPokemonJumpGfx->resetVineState++;
            }
        }
        UpdateVineSwing(sPokemonJumpGfx->vineState);
        if (sPokemonJumpGfx->vineState != VINE_UPSWING_LOW)
            break;
    case 1:
        return FALSE;
    }

    return TRUE;
}

void PrintPrizeMessage(u16 itemId, u16 quantity)
{
    CopyItemName(itemId, sPokemonJumpGfx->itemName);
    ConvertIntToDecimalStringN(sPokemonJumpGfx->itemQuantityStr, quantity, STR_CONV_MODE_LEFT_ALIGN, 1);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, sPokemonJumpGfx->itemQuantityStr);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(sPokemonJumpGfx->prizeMsg, gText_AwesomeWonF701F700);
    sPokemonJumpGfx->msgWindowId = AddMessageWindow(4, 8, 22, 4);
    AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, sPokemonJumpGfx->prizeMsg, 0, 2, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
    sPokemonJumpGfx->fanfare = MUS_LEVEL_UP;
    sPokemonJumpGfx->msgWindowState = 0;
}

void PrintPrizeFilledBagMessage(u16 itemId)
{
    CopyItemName(itemId, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(sPokemonJumpGfx->prizeMsg, gText_FilledStorageSpace2);
    sPokemonJumpGfx->msgWindowId = AddMessageWindow(4, 8, 22, 4);
    AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, sPokemonJumpGfx->prizeMsg, 0, 2, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
    sPokemonJumpGfx->fanfare = MUS_DUMMY;
    sPokemonJumpGfx->msgWindowState = 0;
}

void PrintNoRoomForPrizeMessage(u16 itemId)
{
    CopyItemName(itemId, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sPokemonJumpGfx->itemName);
    DynamicPlaceholderTextUtil_ExpandPlaceholders(sPokemonJumpGfx->prizeMsg, gText_CantHoldMore);
    sPokemonJumpGfx->msgWindowId = AddMessageWindow(4, 9, 22, 2);
    AddTextPrinterParameterized(sPokemonJumpGfx->msgWindowId, FONT_NORMAL, sPokemonJumpGfx->prizeMsg, 0, 2, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_GFX);
    sPokemonJumpGfx->fanfare = MUS_DUMMY;
    sPokemonJumpGfx->msgWindowState = 0;
}

bool32 DoPrizeMessageAndFanfare(void)
{
    switch (sPokemonJumpGfx->msgWindowState)
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sPokemonJumpGfx->msgWindowId);
            DrawTextBorderOuter((u8)sPokemonJumpGfx->msgWindowId, 1, 14);
            CopyBgTilemapBufferToVram(BG_INTERFACE);
            sPokemonJumpGfx->msgWindowState++;
        }
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            break;
        if (sPokemonJumpGfx->fanfare == MUS_DUMMY)
        {
            sPokemonJumpGfx->msgWindowState += 2;
            return FALSE;
        }
        PlayFanfare(sPokemonJumpGfx->fanfare);
        sPokemonJumpGfx->msgWindowState++;
    case 2:
        if (!IsFanfareTaskInactive())
            break;
        sPokemonJumpGfx->msgWindowState++;
    case 3:
        return FALSE;
    }

    return TRUE;
}

void ClearMessageWindow(void)
{
    if (sPokemonJumpGfx->msgWindowId != WINDOW_NONE)
    {
        rbox_fill_rectangle((u8)sPokemonJumpGfx->msgWindowId);
        CopyWindowToVram(sPokemonJumpGfx->msgWindowId, COPYWIN_MAP);
        sPokemonJumpGfx->msgWindowState = 0;
    }
}

bool32 RemoveMessageWindow_PokeJump(void)
{
    if (sPokemonJumpGfx->msgWindowId == WINDOW_NONE)
        return FALSE;

    switch (sPokemonJumpGfx->msgWindowState)
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            RemoveWindow(sPokemonJumpGfx->msgWindowId);
            sPokemonJumpGfx->msgWindowId = WINDOW_NONE;
            sPokemonJumpGfx->msgWindowState++;
        }
        else
            break;
    case 1:
        return FALSE;
    }

    return TRUE;
}

s8 HandlePlayAgainInput(void)
{
    return Menu_ProcessInputNoWrapClearOnChoose();
}

u32 AddMessageWindow(u32 left, u32 top, u32 width, u32 height)
{
    u32 windowId;
    struct PokeJumpWindowTemplate
    {
        u8 bg;
        u8 tilemapLeft;
        u8 tilemapTop;
        u8 width;
        u8 height;
        u8 paletteNum : 8;
        u16 baseBlock : 16;
    } window;

    window.bg = BG_INTERFACE;
    window.tilemapLeft = left;
    window.tilemapTop = top;
    window.width = width;
    window.height = height;
    window.paletteNum = 15;
    window.baseBlock = 0x33;

    windowId = AddWindow((struct WindowTemplate *)&window);
    FillWindowPixelBuffer(windowId, 0x11);
    return windowId;
}

void CreatePokeJumpYesNoMenu(u16 left, u16 top, u8 cursorPos)
{
    struct PokeJumpWindowTemplate
    {
        u8 bg;
        u8 tilemapLeft;
        u8 tilemapTop;
        u8 width;
        u8 height;
        u8 paletteNum : 8;
        u16 baseBlock : 16;
    } window;

    window.bg = BG_INTERFACE;
    window.tilemapLeft = left;
    window.tilemapTop = top;
    window.width = 6;
    window.height = 4;
    window.paletteNum = 2;
    window.baseBlock = 0x1B;

    CreateYesNoMenuAtPos((struct WindowTemplate *)&window, 1, 2, 2, 1, 0xD, cursorPos);
}

void PrintScoreSuffixes(void)
{
    u8 color[3];

    memcpy(color, gUnknown_82D1A68, 3);
    PutWindowTilemap(WIN_POINTS);
    PutWindowTilemap(WIN_TIMES);
    FillWindowPixelBuffer(WIN_POINTS, 0);
    FillWindowPixelBuffer(WIN_TIMES, 0);
    AddTextPrinterParameterized3(WIN_POINTS, FONT_SMALL, 0, 2, color, 0, gText_SpacePoints2);
    AddTextPrinterParameterized3(WIN_TIMES, FONT_SMALL, 0, 2, color, 0, gText_SpaceTimes3);
}

void CreateJumpMonSprites(void)
{
    int i, y, playersCount = GetNumPokeJumpPlayers();
    const s16 *xCoords = sMonXCoords[playersCount - 2];

    for (i = 0; i < playersCount; i++)
    {
        struct PokemonJump_MonInfo *monInfo = GetMonInfoByMultiplayerId(i);

        y = gUnknown_82D45C8[monInfo->species].y_offset;
        CreateJumpMonSprite(sPokemonJumpGfx, monInfo, *xCoords, y + 112, i);
        CreateStarSprite(sPokemonJumpGfx, *xCoords, 112, i);
        xCoords++;
    }
}

void SetMonSpriteY(u32 id, s16 y)
{
    sPokemonJumpGfx->monSprites[id]->y2 = y;
}

void UpdateVineSwing(int vineState)
{
    UpdateVineAnim(sPokemonJumpGfx, vineState);
    ChangeBgY(BG_VENUSAUR, (sVenusaurStates[vineState] * 5) << 13, BG_COORD_SET);
}

int DoSameJumpTimeBonus(u8 flags)
{
    int i, numPlayers;

    for (i = 0, numPlayers = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (flags & 1)
        {
            // Player was part of a synchronous jump
            // Give a bonus to them
            DoStarAnim(sPokemonJumpGfx, i);
            numPlayers++;
        }
        flags >>= 1;
    }

    ShowBonus(numPlayers - 2);
    return numPlayers;
}

void InitDigitPrinters(void)
{
    struct DigitObjUtilTemplate template;
    // The first printer keeps the template base in a register (r1) across all
    // its field stores; the second printer re-derives sp for y.  Keeping the
    // pointer for the first block and direct access for the second reproduces
    // the JP compiler's exact allocation.
    struct DigitObjUtilTemplate *t = &template;

    // JP compiles the bitfield byte (strConvMode=0, shape=0, size=0,
    // priority=1) as a single 0x40 store; assign it wholesale to match.
    *(u8 *)t = 0x40;
    t->oamCount = 5;
    t->xDelta = 8;
    t->x = 108;
    t->y = 6;
    t->spriteSheet = &sSpriteSheet_Digits;
    t->spritePal = &sSpritePalette_Digits;

    DigitObjUtil_Init(NUM_WINDOWS);
    DigitObjUtil_CreatePrinter(WIN_POINTS, 0, t);

    template.oamCount = 4;
    template.x = 30;
    template.y = 6;
    DigitObjUtil_CreatePrinter(WIN_TIMES, 0, &template);
}

void PrintScore(int num)
{
    DigitObjUtil_PrintNumOn(WIN_POINTS, num);
}

void PrintJumpsInRow(u16 num)
{
    DigitObjUtil_PrintNumOn(WIN_TIMES, num);
}

void StartMonHitShake(u8 multiplayerId)
{
    Gfx_StartMonHitShake(sPokemonJumpGfx, multiplayerId);
}

void StartMonHitFlash(u8 multiplayerId)
{
    Gfx_StartMonHitFlash(sPokemonJumpGfx, multiplayerId);
}

bool32 IsMonHitShakeActive(int multiplayerId)
{
    return Gfx_IsMonHitShakeActive(sPokemonJumpGfx, multiplayerId);
}

void StopMonHitFlash(void)
{
    Gfx_StopMonHitFlash(sPokemonJumpGfx);
}

void ResetMonSpriteSubpriorities(void)
{
    Gfx_ResetMonSpriteSubpriorities(sPokemonJumpGfx);
}

void StartMonIntroBounce(int multiplayerId)
{
    Gfx_StartMonIntroBounce(sPokemonJumpGfx, multiplayerId);
}

bool32 IsMonIntroBounceActive(void)
{
    return Gfx_IsMonIntroBounceActive(sPokemonJumpGfx);
}

void AddPlayerNameWindows(void)
{
    struct PokeJumpWindowTemplate
    {
        u8 bg;
        u8 tilemapLeft;
        u8 tilemapTop;
        u8 width;
        u8 height;
        u8 paletteNum : 8;
        u16 baseBlock : 16;
    } window;
    int i, playersCount = GetNumPokeJumpPlayers();
    const u16 *winCoords = sPlayerNameWindowCoords[playersCount - 2];

    window.bg = BG_INTERFACE;
    window.width = 8;
    window.height = 2;
    window.paletteNum = 2;
    window.baseBlock = 0x1B;

    for (i = 0; i < playersCount; i++)
    {
        window.tilemapLeft = winCoords[0];
        window.tilemapTop = winCoords[1];
        sPokemonJumpGfx->nameWindowIds[i] = AddWindow((struct WindowTemplate *)&window);
        ClearWindowTilemap(sPokemonJumpGfx->nameWindowIds[i]);
        window.baseBlock += 0x10;
        winCoords += 2;
    }

    CopyBgTilemapBufferToVram(BG_INTERFACE);
}

void PrintPokeJumpPlayerName(int multiplayerId, u8 bgColor, u8 fgColor, u8 shadow)
{
    u32 x;
    u8 colors[3] = {bgColor, fgColor, shadow};

    FillWindowPixelBuffer(sPokemonJumpGfx->nameWindowIds[multiplayerId], 0);
    // JP uses the small font (index 0) for the name labels; US FONT_NORMAL is
    // index 0 there, so the constant is FONT_SMALL in JP's font enum.
    x = 64 - GetStringWidth(FONT_SMALL, GetPokeJumpPlayerName(multiplayerId), -1);
    x /= 2;
    AddTextPrinterParameterized3(sPokemonJumpGfx->nameWindowIds[multiplayerId], FONT_SMALL, x, 2, colors, TEXT_SKIP_DRAW, GetPokeJumpPlayerName(multiplayerId));
    CopyWindowToVram(sPokemonJumpGfx->nameWindowIds[multiplayerId], COPYWIN_GFX);
}

void PrintPokeJumpPlayerNames(bool32 highlightSelf)
{
    int i, multiplayerId, playersCount = GetNumPokeJumpPlayers();

    if (!highlightSelf)
    {
        for (i = 0; i < playersCount; i++)
            PrintPokeJumpPlayerName(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY);
    }
    else
    {
        // Highlight own name
        multiplayerId = GetPokeJumpMultiplayerId();
        for (i = 0; i < playersCount; i++)
        {
            if (multiplayerId != i)
                PrintPokeJumpPlayerName(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY);
            else
                PrintPokeJumpPlayerName(i, TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_RED);
        }
    }
}

void DrawPlayerNameWindows_PokeJump(void)
{
    int i, playersCount = GetNumPokeJumpPlayers();

    for (i = 0; i < playersCount; i++)
        PutWindowTilemap(sPokemonJumpGfx->nameWindowIds[i]);
    CopyBgTilemapBufferToVram(BG_INTERFACE);
}

void ShowBonus(u8 bonusId)
{
    sPokemonJumpGfx->bonusTimer = 0;
    ChangeBgX(BG_BONUSES, (bonusId / 2) * 256 * 256, BG_COORD_SET);
    ChangeBgY(BG_BONUSES, (((bonusId % 2) * 256) - 40) * 256, BG_COORD_SET);
    ShowBg(BG_BONUSES);
    CreateTask(Task_UpdateBonus, 4);
}

bool32 UpdateBonus(void)
{
    if (sPokemonJumpGfx->bonusTimer >= 32)
    {
        return FALSE;
    }
    else
    {
        ChangeBgY(BG_BONUSES, 128, BG_COORD_ADD);
        if (++sPokemonJumpGfx->bonusTimer >= 32)
            HideBg(BG_BONUSES);
        return TRUE;
    }
}

void Task_UpdateBonus(u8 taskId)
{
    if (!UpdateBonus())
        DestroyTask(taskId);
}

struct MonInfoPacket
{
    u8 id;
    u16 species;
    u32 personality;
    u32 otId;
};

void SendPacket_MonInfo(struct PokemonJump_MonInfo *monInfo)
{
    struct MonInfoPacket packet;
    packet.id = PACKET_MON_INFO,
    packet.species = monInfo->species,
    packet.otId = monInfo->otId,
    packet.personality = monInfo->personality,
    Rfu_SendPacket(&packet);
}

bool32 RecvPacket_MonInfo(int multiplayerId, struct PokemonJump_MonInfo *monInfo)
{
    struct MonInfoPacket packet;

    if ((gRecvCmds[multiplayerId][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id == PACKET_MON_INFO)
    {
        monInfo->species = packet.species;
        monInfo->otId = packet.otId;
        monInfo->personality = packet.personality;
        return TRUE;
    }

    return FALSE;
}

struct UnusedPacket
{
    u8 id;
    u32 data;
    u32 filler;
};

// Data packet that's never sent; no function reads it either.
void UNUSED SendPacket_Unused(u32 data)
{
    struct UnusedPacket packet;
    packet.id = PACKET_UNUSED;
    packet.data = data;
    Rfu_SendPacket(&packet);
}

struct LeaderStatePacket
{
    u8 id;
    u8 funcId;
    u8 monState;
    u8 receivedBonusFlags:5; // 1 bit for each player (MAX_RFU_PLAYERS)
    u8 jumpState:3;
    u16 jumpTimeStart;
    u16 vineTimer;
    u32 jumpsInRow:15;
    u32 jumpScore:17;
};

void SendPacket_LeaderState(struct PokemonJump_Player *player, struct PokemonJump_CommData *comm)
{
    struct LeaderStatePacket packet;
    packet.id = PACKET_LEADER_STATE;
    packet.jumpScore = comm->jumpScore;
    packet.receivedBonusFlags = comm->receivedBonusFlags;
    packet.funcId = comm->funcId;
    packet.vineTimer = comm->data;
    packet.jumpsInRow = comm->jumpsInRow;
    packet.monState = player->monState;
    packet.jumpState = player->jumpState;
    packet.jumpTimeStart = player->jumpTimeStart;
    Rfu_SendPacket(&packet);
}

// Used by group members to read the state of the group leader
bool32 RecvPacket_LeaderState(struct PokemonJump_Player *player, struct PokemonJump_CommData *comm)
{
    struct LeaderStatePacket packet;

    if ((gRecvCmds[0][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[0][1], sizeof(packet));
    if (packet.id != PACKET_LEADER_STATE)
        return FALSE;

    comm->jumpScore = packet.jumpScore;
    comm->receivedBonusFlags = packet.receivedBonusFlags;
    comm->funcId = packet.funcId;
    comm->data = packet.vineTimer;
    comm->jumpsInRow = packet.jumpsInRow;
    player->monState = packet.monState;
    player->jumpState = packet.jumpState;
    player->jumpTimeStart = packet.jumpTimeStart;
    return TRUE;
}

struct MemberStatePacket
{
    u8 id;
    u8 monState;
    u8 jumpState;
    bool8 funcFinished;
    u16 jumpTimeStart;
    u8 funcId;
    u16 playAgainState;
};

void SendPacket_MemberState(struct PokemonJump_Player *player, u8 funcId, u16 playAgainState)
{
    struct MemberStatePacket packet;
    packet.id = PACKET_MEMBER_STATE;
    packet.monState = player->monState;
    packet.jumpState = player->jumpState;
    packet.funcFinished = player->funcFinished;
    packet.jumpTimeStart = player->jumpTimeStart;
    packet.funcId = funcId;
    packet.playAgainState = playAgainState;
    Rfu_SendPacket(&packet);
}

bool32 RecvPacket_MemberStateToLeader(struct PokemonJump_Player *player, int multiplayerId, u8 *funcId, u16 *playAgainState)
{
    struct MemberStatePacket packet;

    if ((gRecvCmds[multiplayerId][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id != PACKET_MEMBER_STATE)
        return FALSE;

    player->monState = packet.monState;
    player->jumpState = packet.jumpState;
    player->funcFinished = packet.funcFinished;
    player->jumpTimeStart = packet.jumpTimeStart;
    *funcId = packet.funcId;
    *playAgainState = packet.playAgainState;
    return TRUE;
}

bool32 RecvPacket_MemberStateToMember(struct PokemonJump_Player *player, int multiplayerId)
{
    struct MemberStatePacket packet;

    if ((gRecvCmds[multiplayerId][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    memcpy(&packet, &gRecvCmds[multiplayerId][1], sizeof(packet));
    if (packet.id != PACKET_MEMBER_STATE)
        return FALSE;

    player->monState = packet.monState;
    player->jumpState = packet.jumpState;
    player->funcFinished = packet.funcFinished;
    player->jumpTimeStart = packet.jumpTimeStart;
    return TRUE;
}

void Gfx_StopMonHitFlash(struct PokemonJumpGfx *jumpGfx)
{
    int i;
    u16 numPlayers = GetNumPokeJumpPlayers();
    for (i = 0; i < numPlayers; i++)
    {
        if (jumpGfx->monSprites[i]->callback == SpriteCB_MonHitFlash)
        {
            jumpGfx->monSprites[i]->invisible = FALSE;
            jumpGfx->monSprites[i]->callback = SpriteCallbackDummy;
            jumpGfx->monSprites[i]->subpriority = 10;
        }
    }
}

#define sTimer     data[1]
#define sNumShakes data[2]

void SpriteCB_MonHitShake(struct Sprite *sprite)
{
    if (++sprite->sTimer > 1)
    {
        if (++sprite->sNumShakes & 1)
            sprite->y2 = 2;
        else
            sprite->y2 = -2;

        sprite->sTimer = 0;
    }

    if (sprite->sNumShakes > 12)
    {
        sprite->y2 = 0;
        sprite->callback = SpriteCallbackDummy;
    }
}

#undef sTimer
#undef sNumShakes

#define sTimer data[0]

void SpriteCB_MonHitFlash(struct Sprite *sprite)
{
    if (++sprite->sTimer > 3)
    {
        sprite->sTimer = 0;
        sprite->invisible ^= 1;
    }
}

#undef sTimer

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
