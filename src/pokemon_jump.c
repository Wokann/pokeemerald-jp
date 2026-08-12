#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "digit_obj_util.h"
#include "link.h"
#include "main.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_jump.h"
#include "random.h"
#include "sound.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"

#define VINE_SPRITES_PER_SIDE 4 // Vine rope is divided into 8 sprites, 4 per side copied and flipped horizontally
#define JUMP_PEAK (-30)

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
    MONSTATE_NORMAL, // Pokémon is either on the ground or in the middle of a jump
    MONSTATE_JUMP,   // Pokémon has begun a jump
    MONSTATE_HIT,    // Pokémon got hit by the vine
};

enum {
    JUMPSTATE_NONE,
    JUMPSTATE_SUCCESS, // Cleared vine
    JUMPSTATE_FAILURE, // Hit vine
};

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
