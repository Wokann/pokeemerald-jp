#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "dodrio_berry_picking.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "m4a.h"
#include "palette.h"
#include "random.h"
#include "save.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "window.h"
#include "constants/items.h"
#include "constants/songs.h"

// Note that in this file 'Dodrio Berry Picking' is often
// shortened to DodrioGame or just Game for convenience

#define MAX_SCORE 999990
#define MAX_BERRIES 9999

// The minimum score needed to receive a prize
#define PRIZE_SCORE 3000

// Difficulty increases as berries are eaten. The rate of new berries increases and the types of berries changes
// When the max difficulty is reached it starts again from the beginning
#define NUM_DIFFICULTIES 7

#define MAX_FALL_DIST 10 // The number of times a berry needs to fall before hitting the ground
#define EAT_FALL_DIST 7 // The number of times a berry needs to fall to be available to eat

#define NUM_BERRY_TYPES  4 // Blue, Green, Gold, and 'missed'
#define NUM_BERRY_COLUMNS 11
#define NUM_STATUS_SQUARES 10
#define NUM_CLOUDS 2

enum {
    BERRY_BLUE,
    BERRY_GREEN,
    BERRY_GOLD,
    BERRY_MISSED,
    BERRY_PRIZE,
    BERRY_IN_ROW,
    NUM_BERRY_IDS
};

enum {
    FUNC_INTRO,
    FUNC_INIT_COUNTDOWN,
    FUNC_COUNTDOWN,
    FUNC_WAIT_START,
    FUNC_PLAY_GAME,
    FUNC_INIT_RESULTS,
    FUNC_RESULTS,
    FUNC_ASK_PLAY_AGAIN,
    FUNC_END_LINK,
    FUNC_EXIT,
    FUNC_RESET_GAME,
    FUNC_WAIT_END_GAME,
};

enum {
    GFXFUNC_LOAD,
    GFXFUNC_SHOW_NAMES,
    GFXFUNC_SHOW_RESULTS,
    GFXFUNC_MSG_PLAY_AGAIN,
    GFXFUNC_MSG_SAVING,
    GFXFUNC_MSG_COMM_STANDBY,
    GFXFUNC_ERASE_MSG,
    GFXFUNC_MSG_PLAYER_DROPPED,
    GFXFUNC_STOP,
    GFXFUNC_IDLE,
};

enum {
    PLAY_AGAIN_NONE,
    PLAY_AGAIN_YES,
    PLAY_AGAIN_NO,
    PLAY_AGAIN_DROPPED = 5,
};

enum {
    PICK_NONE,     // Dodrio standing still
    PICK_RIGHT,    // Dodrio reaching right
    PICK_MIDDLE,   // Dodrio reaching up
    PICK_LEFT,     // Dodrio reaching left
    PICK_DISABLED, // Dodrio down after game over
};

enum {
    BERRYSTATE_NONE,
    BERRYSTATE_PICKED,   // Berry has been picked by a Dodrio, replaced with blue hit sprite (still falling)
    BERRYSTATE_EATEN,    // Berry has been eaten (after being picked), berry is gone now
    BERRYSTATE_SQUISHED, // Berry has hit the ground
};

enum {
    INPUTSTATE_NONE,
    INPUTSTATE_TRY_PICK,
    INPUTSTATE_PICKED,
    INPUTSTATE_ATE_BERRY,
    INPUTSTATE_BAD_MISS,
};

#define GFXTAG_DODRIO    0
#define GFXTAG_STATUS    1
#define GFXTAG_BERRIES   2
#define GFXTAG_CLOUD     5
#define GFXTAG_COUNTDOWN 7

#define PALTAG_DODRIO_NORMAL 0
#define PALTAG_DODRIO_SHINY  1
#define PALTAG_STATUS        2
#define PALTAG_BERRIES       3
#define PALTAG_CLOUD         6
#define PALTAG_COUNTDOWN     8

#define PLAYER_NONE 0xFF

struct DodrioGame_Gfx
{
    u16 ALIGNED(4) tilemapBuffers[3][BG_SCREEN_SIZE];
    bool32 finished;
    u8 ALIGNED(4) taskId;
    u8 ALIGNED(4) windowIds[MAX_RFU_PLAYERS + 5]; // The latter 5 are never used
    u8 ALIGNED(4) state;
    u8 ALIGNED(4) loadState;
    u16 ALIGNED(4) timer;
    u8 ALIGNED(4) cursorSelection;
    u8 ALIGNED(4) playAgainState;
    void (*func)(void);
}; // size = 0x302C

struct StatusBar
{
    u8 unused[12];
    bool8 entered[NUM_STATUS_SQUARES];
    s16 yChange[NUM_STATUS_SQUARES];
    u16 spriteIds[NUM_STATUS_SQUARES];
    u16 flashTimer;
}; // size = 0x40

struct DodrioGame_Berries
{
    u8 ids[NUM_BERRY_COLUMNS];
    u8 fallDist[NUM_BERRY_COLUMNS];
};

struct DodrioGame_PlayerCommData
{
    u8 pickState;
    bool8 ALIGNED(4) ateBerry;
    bool8 ALIGNED(4) missedBerry;
};

struct DodrioGame_Player
{
    u8 name[16];
    bool32 receivedGameStatePacket; // Never read
    struct DodrioGame_Berries berries;
    struct DodrioGame_PlayerCommData comm;
    u32 unused;
}; // size = 0x3C

// Because Dodrio is required for this minigame,
// the only relevant information about the selected
// Pokemon is whether or not it's shiny
struct DodrioGame_MonInfo
{
    u8 isShiny;
    u8 filler[3];
}; // size = 0x4 (JP layout)

struct DodrioGame_ScoreResults
{
    u8 ranking;
    u32 score;
};

struct DodrioGame
{
    /*0x0000*/ MainCallback exitCallback;
    /*0x0004*/ u8 ALIGNED(4) taskId;
    /*0x0008*/ u8 ALIGNED(4) playersReceived;
    /*0x000C*/ u8 ALIGNED(4) startState;
    /*0x0010*/ u8 ALIGNED(4) state;
    /*0x0014*/ u8 ALIGNED(4) timer;
    /*0x0018*/ u8 ALIGNED(4) funcId;
    /*0x001C*/ u8 ALIGNED(4) prevFuncId; // Set, never read
    /*0x0020*/ bool8 ALIGNED(4) isLeader;
    /*0x0024*/ u8 ALIGNED(4) numPlayers;
    /*0x0028*/ u8 ALIGNED(4) multiplayerId;
    /*0x0029*/ u8 unused1[7];
    /*0x0030*/ u8 ALIGNED(4) countdownEndDelay;
    /*0x0034*/ u8 ALIGNED(4) posToPlayerId[MAX_RFU_PLAYERS];
    /*0x003C*/ u8 ALIGNED(4) unused2; // Set to 0, never read
    /*0x0040*/ u8 ALIGNED(4) numGraySquares;
    /*0x0044*/ u8 ALIGNED(4) berryColStart;
    /*0x0048*/ u8 ALIGNED(4) berryColEnd;
    /*0x004A*/ u16 berryResults[MAX_RFU_PLAYERS][NUM_BERRY_IDS];
    /*0x0086*/ u16 berriesEaten[MAX_RFU_PLAYERS];
    /*0x0090*/ u8 ALIGNED(4) difficulty[MAX_RFU_PLAYERS];
    /*0x0098*/ u8 ALIGNED(4) pickStateQueue[4];
    /*0x009C*/ u8 ALIGNED(4) eatTimer[NUM_BERRY_COLUMNS];
    /*0x00A8*/ u8 ALIGNED(4) inputState[MAX_RFU_PLAYERS];
    /*0x00B0*/ u8 ALIGNED(4) inputDelay[MAX_RFU_PLAYERS];
    /*0x00B8*/ u8 ALIGNED(4) berryEatenBy[NUM_BERRY_COLUMNS];
    /*0x00C4*/ u8 ALIGNED(4) berryState[NUM_BERRY_COLUMNS];
    /*0x00D0*/ u8 ALIGNED(4) fallTimer[NUM_BERRY_COLUMNS];
    /*0x00DC*/ u8 ALIGNED(4) newBerryTimer[NUM_BERRY_COLUMNS];
    /*0x00E8*/ u8 ALIGNED(4) prevBerryIds[NUM_BERRY_COLUMNS];
    /*0x00F4*/ u8 ALIGNED(4) playersAttemptingPick[NUM_BERRY_COLUMNS][2];
    /*0x010C*/ u8 ALIGNED(4) playAgainStates[MAX_RFU_PLAYERS];
    /*0x0112*/ u16 berriesPickedInRow;
    /*0x0114*/ u16 maxBerriesPickedInRow;
    /*0x0118*/ bool32 startCountdown; // Never read
    /*0x011C*/ bool32 startGame;
    /*0x0120*/ bool32 berriesFalling;
    /*0x0124*/ u8 ALIGNED(4) clearRecvCmdTimer;
    /*0x0128*/ bool8 ALIGNED(4) clearRecvCmds;
    /*0x012C*/ bool32 allReadyToEnd;
    /*0x0130*/ bool32 readyToEnd[MAX_RFU_PLAYERS];
    /*0x0144*/ bool8 ALIGNED(4) playingPickSound;
    /*0x0148*/ bool8 ALIGNED(4) playingSquishSound[NUM_BERRY_COLUMNS];
    /*0x0154*/ u8 ALIGNED(4) endSoundState;
    /*0x0158*/ bool8 ALIGNED(4) readyToStart[MAX_RFU_PLAYERS];
    /*0x0160*/ struct DodrioGame_Gfx gfx;
    /*0x318C*/ struct DodrioGame_MonInfo monInfo[MAX_RFU_PLAYERS];
    /*0x31A0*/ struct DodrioGame_Player players[MAX_RFU_PLAYERS];
    /*0x32CC*/ struct DodrioGame_Player player;
    /*0x3308*/ struct DodrioGame_ScoreResults scoreResults[MAX_RFU_PLAYERS];
}; // size = 0x3330

// JP links these to fixed EWRAM/IWRAM addresses (see sym_ewram_jp.txt /
// sym_iwram_jp.txt); the names avoid clashing with berry_crush's sGame.
extern EWRAM_DATA struct DodrioGame *sDodrioGame;
extern bool32 sDodrioExitingGame;
#define sGame sDodrioGame
#define sExitingGame sDodrioExitingGame

extern void InitDodrioGame(struct DodrioGame *);
extern void Task_StartDodrioGame(u8 taskId);
extern void CB2_DodrioGame(void);
extern void SetRandomPrize(void);
extern void GetActiveBerryColumns(u8, u8 *, u8 *);
extern void InitMonInfo(struct DodrioGame_MonInfo *, struct Pokemon *);
extern void Task_CommunicateMonInfo(u8 taskId);
extern void Task_NewGameIntro(u8 taskId);
extern void VBlankCB_DodrioGame(void);
extern void CreateTask_(TaskFunc func, u8 priority);
extern void InitGameGfx(struct DodrioGame_Gfx *);
extern bool32 IsGfxFuncActive(void);
extern void LoadDodrioGfx(void);
extern void CreateDodrioSprite(struct DodrioGame_MonInfo *, u8, u8, u8);
extern void SetAllDodrioInvisibility(bool8, u8);
extern void LoadBerryGfx_Dodrio(void);
#define LoadBerryGfx LoadBerryGfx_Dodrio
extern void CreateBerrySprites_Dodrio(void);
#define CreateBerrySprites CreateBerrySprites_Dodrio
extern void CreateCloudSprites_Dodrio(void);
#define CreateCloudSprites CreateCloudSprites_Dodrio
extern void CreateStatusBarSprites(void);
extern void CreateDodrioGameTask(TaskFunc func);
extern void (*const sLeaderFuncs[])(void);
extern void (*const sMemberFuncs[])(void);
extern void RecvLinkData_Leader(void);
extern void RecvLinkData_Member(void);
extern void UpdateGame_Leader(void);
extern void UpdateGame_Member(void);
extern void SendLinkData_Leader(void);
extern void SendLinkData_Member(void);
extern void StartDodrioIntroAnim(u8);
extern void SetGfxFuncById(u8);
extern void SetGameFunc(u8);
extern void InitFirstWaveOfBerries(void);
extern u8 UpdatePickStateQueue(u8);
extern void UpdateFallingBerries(void);
extern void HandleSound_Leader(void);
extern void HandleSound_Member(void);
extern bool32 ReadyToEndGame_Leader(void);
extern bool32 ReadyToEndGame_Member(void);
extern void SetMaxBerriesPickedInRow(void);
extern void TryUpdateRecords(void);
extern void SetStatusBarInvisibility(bool8);
extern void ResetCloudPos(void);
extern void SetCloudInvisibility(bool8);
extern u8 GetPlayAgainState(void);

static void ResetTasksAndSprites(void)
{
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
}

void InitDodrioGame(struct DodrioGame *game)
{
    u8 i;

    game->startState = 0;
    game->state = 0;
    game->timer = 0;
    game->funcId = FUNC_INTRO;
    game->prevFuncId = FUNC_INTRO;
    game->startGame = FALSE;
    game->berriesFalling = FALSE;
    game->countdownEndDelay = 0;
    game->numGraySquares = 0;
    game->unused2 = 0;
    game->allReadyToEnd = FALSE;

    for (i = 0; i < ARRAY_COUNT(game->pickStateQueue); i++)
        game->pickStateQueue[i] = PICK_NONE;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        game->inputState[i] = INPUTSTATE_NONE;
        game->inputDelay[i] = 0;
        game->berryResults[i][BERRY_BLUE] = 0;
        game->berryResults[i][BERRY_GREEN] = 0;
        game->berryResults[i][BERRY_GOLD] = 0;
        game->berryResults[i][BERRY_MISSED] = 0;
        game->berryResults[i][BERRY_IN_ROW] = 0;
        game->playAgainStates[i] = PLAY_AGAIN_NONE;
        game->readyToEnd[i] = FALSE;
    }

    for (i = 0; i < NUM_BERRY_COLUMNS; i++)
    {
        game->fallTimer[i] = 0;
        game->newBerryTimer[i] = 0;
        game->berryState[i] = BERRYSTATE_NONE;
        game->playersAttemptingPick[i][0] = PLAYER_NONE;
        game->playersAttemptingPick[i][1] = PLAYER_NONE;
    }

    game->isLeader = GetMultiplayerId() == 0 ? TRUE : FALSE;
    game->numPlayers = GetLinkPlayerCount();
    game->posToPlayerId[0] = GetMultiplayerId();
    for (i = 1; i < game->numPlayers; i++)
    {
        game->posToPlayerId[i] = game->posToPlayerId[i - 1] + 1;
        if (game->posToPlayerId[i] > game->numPlayers - 1)
            game->posToPlayerId[i] %= game->numPlayers;
    }
}

void Task_StartDodrioGame(u8 taskId)
{
    u8 i, numPlayers;

    switch (sGame->startState)
    {
    case 0:
        SetVBlankCallback(NULL);
        CreateTask_(Task_CommunicateMonInfo, 4);
        sGame->startState++;
        break;
    case 1:
        if (!FuncIsActiveTask(Task_CommunicateMonInfo))
        {
            InitGameGfx(&sGame->gfx);
            sGame->startState++;
        }
        break;
    case 2:
        if (!IsGfxFuncActive())
        {
            Rfu_SetLinkStandbyCallback();
            sGame->startState++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            if (gReceivedRemoteLinkPlayers)
            {
                LoadWirelessStatusIndicatorSpriteGfx();
                CreateWirelessStatusIndicatorSprite(0, 0);
            }
            sGame->startState++;
        }
        break;
    case 4:
        numPlayers = sGame->numPlayers;
        LoadDodrioGfx();
        for (i = 0; i < numPlayers; i++)
            CreateDodrioSprite(&sGame->monInfo[sGame->posToPlayerId[i]], i, sGame->posToPlayerId[i], sGame->numPlayers);

        SetAllDodrioInvisibility(FALSE, sGame->numPlayers);
        sGame->startState++;
        break;
    case 5:
        LoadBerryGfx();
        CreateBerrySprites();
        CreateCloudSprites();
        CreateStatusBarSprites();
        sGame->startState++;
        break;
    case 6:
        BlendPalettes(PALETTES_ALL, 0x10, 0x00);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, 0);
        SetVBlankCallback(VBlankCB_DodrioGame);
        sGame->startState++;
        break;
    case 7:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
            sGame->startState++;
        break;
    default:
        DestroyTask(taskId);
        CreateDodrioGameTask(Task_NewGameIntro);
        break;
    }
}

void Task_DodrioGame_Leader(u8 taskId)
{
    RecvLinkData_Leader();
    sLeaderFuncs[sGame->funcId]();
    if (!sExitingGame)
        UpdateGame_Leader();

    SendLinkData_Leader();
}

void Task_DodrioGame_Member(u8 taskId)
{
    RecvLinkData_Member();
    sMemberFuncs[sGame->funcId]();
    if (!sExitingGame)
        UpdateGame_Member();

    SendLinkData_Member();
}

void DoGameIntro(void)
{
    switch (sGame->state)
    {
    case 0:
        StartDodrioIntroAnim(1);
        SetGfxFuncById(GFXFUNC_SHOW_NAMES);
        sGame->state++;
        break;
    case 1:
        if (!IsGfxFuncActive())
            SetGameFunc(FUNC_INIT_COUNTDOWN);
        break;
    }
}

void InitCountdown(void)
{
    switch (sGame->state)
    {
    case 0:
        InitFirstWaveOfBerries();
        sGame->state++;
        break;
    default:
        sGame->startCountdown = TRUE;
        SetGameFunc(FUNC_COUNTDOWN);
        break;
    }
}

void DoCountdown(void)
{
    switch (sGame->state)
    {
    case 0:
        StartMinigameCountdown(GFXTAG_COUNTDOWN, PALTAG_COUNTDOWN, 120, 80, 0);
        sGame->state++;
        break;
    case 1:
        Rfu_SetLinkStandbyCallback();
        sGame->state++;
        break;
    case 2:
        if (IsLinkTaskFinished())
        {
            sGame->state++;
            sGame->countdownEndDelay = 0;
        }
        break;
    case 3:
        if (!IsMinigameCountdownRunning())
            sGame->state++;
        break;
    case 4:
        if (++sGame->countdownEndDelay > 5)
        {
            Rfu_SetLinkStandbyCallback();
            sGame->state++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
            SetGameFunc(FUNC_WAIT_START);
        break;
    }
}

void WaitGameStart(void)
{
    switch (sGame->state)
    {
    case 0:
        if (sGame->startGame)
            SetGameFunc(FUNC_PLAY_GAME);
        break;
    }
}

void PlayGame_Leader(void)
{
    switch (sGame->state)
    {
    case 0:
        if (sGame->numGraySquares < NUM_STATUS_SQUARES)
        {
            if (sGame->inputState[0] == INPUTSTATE_NONE)
            {
                if (JOY_NEW(DPAD_UP))
                {
                    if (sGame->players[0].comm.pickState == PICK_NONE)
                    {
                        sGame->players[0].comm.ateBerry = FALSE;
                        sGame->players[0].comm.pickState = UpdatePickStateQueue(PICK_MIDDLE);
                    }
                }
                else if (JOY_NEW(DPAD_RIGHT))
                {
                    if (sGame->players[0].comm.pickState == PICK_NONE)
                    {
                        sGame->players[0].comm.ateBerry = FALSE;
                        sGame->players[0].comm.pickState = UpdatePickStateQueue(PICK_RIGHT);
                    }
                }
                else if (JOY_NEW(DPAD_LEFT))
                {
                    if (sGame->players[0].comm.pickState == PICK_NONE)
                    {
                        sGame->players[0].comm.ateBerry = FALSE;
                        sGame->players[0].comm.pickState = UpdatePickStateQueue(PICK_LEFT);
                    }
                }
                else
                {
                    sGame->players[0].comm.pickState = UpdatePickStateQueue(PICK_NONE);
                }
            }
        }
        else
        {
            SetGameFunc(FUNC_WAIT_END_GAME);
        }
        UpdateFallingBerries();
        HandleSound_Leader();
        break;
    }
}

void PlayGame_Member(void)
{
    if (sGame->numGraySquares < NUM_STATUS_SQUARES)
    {
        if (JOY_NEW(DPAD_UP))
        {
            if (sGame->players[sGame->multiplayerId].comm.pickState == PICK_NONE)
            {
                sGame->player.comm.pickState = PICK_MIDDLE;
            }
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            if (sGame->players[sGame->multiplayerId].comm.pickState == PICK_NONE)
            {
                sGame->player.comm.pickState = PICK_RIGHT;
            }
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            if (sGame->players[sGame->multiplayerId].comm.pickState == PICK_NONE)
            {
                sGame->player.comm.pickState = PICK_LEFT;
            }
        }
        else
        {
            sGame->player.comm.pickState = PICK_NONE;
        }
    }
    else
    {
        SetGameFunc(FUNC_WAIT_END_GAME);
    }
    HandleSound_Member();
}

void WaitEndGame_Leader(void)
{
    u8 i;

    UpdateFallingBerries();
    HandleSound_Leader();
    if (ReadyToEndGame_Leader() == TRUE)
    {
        SetMaxBerriesPickedInRow();
        SetGameFunc(FUNC_INIT_RESULTS);
    }
    else
    {
        sGame->allReadyToEnd = TRUE;
        for (i = 1; i < sGame->numPlayers; i++)
        {
            if (sGame->readyToEnd[i] != TRUE)
            {
                sGame->allReadyToEnd = FALSE;
                break;
            }
        }
    }
}

void WaitEndGame_Member(void)
{
    HandleSound_Member();
    if (ReadyToEndGame_Member() == TRUE)
        SetGameFunc(FUNC_INIT_RESULTS);
}

bool32 AllPlayersReadyToStart(void)
{
    u8 status = GetBlockReceivedStatus();
    u8 mask = GetLinkPlayerCountAsBitFlags();

    if (status == mask)
    {
        ResetBlockReceivedFlags();
        return TRUE;
    }
    return FALSE;
}

void InitResults_Leader(void)
{
    switch (sGame->state)
    {
    case 0:
        if (SendBlock(0, sGame->berryResults, sizeof(sGame->berryResults)))
        {
            sGame->playersReceived = 0;
            sGame->state++;
        }
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            sGame->state++;
        }
        break;
    case 2:
        if (AllPlayersReadyToStart())
        {
            sGame->playersReceived = sGame->numPlayers;
        }
        if (sGame->playersReceived >= sGame->numPlayers)
        {
            sGame->timer++;
            sGame->state++;
        }
        break;
    default:
        if (WaitFanfare(TRUE))
        {
            SetGameFunc(FUNC_RESULTS);
            FadeOutAndPlayNewMapMusic(MUS_RG_VICTORY_WILD, 4);
        }
        break;
    }
}

void InitResults_Member(void)
{
    u8 i;

    switch (sGame->state)
    {
    case 0:
        if (SendBlock(0, sGame->berryResults[sGame->timer], sizeof(sGame->berryResults)))
        {
            sGame->playersReceived = 0;
            sGame->state++;
        }
        break;
    case 1:
        if (IsLinkTaskFinished())
        {
            sGame->state++;
        }
        break;
    case 2:
        if (AllPlayersReadyToStart())
        {
            for (i = 0; i < sGame->numPlayers; i++)
            {
                memcpy(sGame->berryResults, gBlockRecvBuffer, sizeof(sGame->berryResults));
                sGame->playersReceived = sGame->numPlayers;
            }
        }
        if (sGame->playersReceived >= sGame->numPlayers)
        {
            sGame->timer++;
            sGame->state++;
        }
        break;
    default:
        if (WaitFanfare(TRUE))
        {
            sGame->maxBerriesPickedInRow = sGame->berryResults[sGame->multiplayerId][BERRY_IN_ROW];
            SetGameFunc(FUNC_RESULTS);
            FadeOutAndPlayNewMapMusic(MUS_RG_VICTORY_WILD, 4);
        }
        break;
    }
}

void DoResults(void)
{
    u8 playAgainState = PLAY_AGAIN_YES;
    u8 i;

    switch (sGame->state)
    {
    case 0:
        TryUpdateRecords();
        SetStatusBarInvisibility(TRUE);
        ResetCloudPos();
        SetCloudInvisibility(TRUE);
        SetGfxFuncById(GFXFUNC_SHOW_RESULTS);
        sGame->state++;
        break;
    case 1:
        if (!IsGfxFuncActive())
        {
            SetGfxFuncById(GFXFUNC_MSG_COMM_STANDBY);
            sGame->state++;
        }
        break;
    case 2:
        playAgainState = GetPlayAgainState();
        if (SendBlock(0, &playAgainState, sizeof(playAgainState)))
            sGame->state++;
        break;
    case 3:
        if (IsLinkTaskFinished())
        {
            sGame->state++;
            sGame->playersReceived = 0;
        }
        break;
    case 4:
        if (AllPlayersReadyToStart())
        {
            for (i = 0; i < sGame->numPlayers; i++)
            {
                *(&sGame->playAgainStates[i]) = *(u8 *)gBlockRecvBuffer[i];
                sGame->playersReceived = sGame->numPlayers;
            }
        }
        if (sGame->playersReceived >= sGame->numPlayers)
        {
            if (++sGame->timer >= 120)
            {
                SetGfxFuncById(GFXFUNC_ERASE_MSG);
                sGame->state++;
            }
        }
        break;
    default:
        if (!IsGfxFuncActive())
            SetGameFunc(FUNC_ASK_PLAY_AGAIN);
        break;
    }
}

void StartDodrioBerryPicking(u16 partyId, MainCallback exitCallback)
{
    sExitingGame = FALSE;

    if (gReceivedRemoteLinkPlayers && (sGame = AllocZeroed(sizeof(*sGame))))
    {
        ResetTasksAndSprites();
        InitDodrioGame(sGame);
        sGame->exitCallback = exitCallback;
        sGame->multiplayerId = GetMultiplayerId();
        sGame->player = sGame->players[sGame->multiplayerId];
        InitMonInfo(&sGame->monInfo[sGame->multiplayerId], &gPlayerParty[partyId]);
        CreateTask(Task_StartDodrioGame, 1);
        SetMainCallback2(CB2_DodrioGame);
        SetRandomPrize();
        GetActiveBerryColumns(sGame->numPlayers, &sGame->berryColStart, &sGame->berryColEnd);
        StopMapMusic();
        PlayNewMapMusic(MUS_RG_BERRY_PICK);
    }
    else
    {
        // Exit - Alloc failed, or players not connected
        SetMainCallback2(exitCallback);
        return;
    }
}
