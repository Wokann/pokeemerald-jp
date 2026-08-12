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
#include "pokemon.h"
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
    PACKET_READY_START = 1,
    PACKET_GAME_STATE,
    PACKET_PICK_STATE,
    PACKET_READY_END,
};

struct ReadyToStartPacket
{
    u8 id;
    u8 filler[3];
    u8 ready;
};

struct StatusBar
{
    u8 unused[12];
    bool8 entered[NUM_STATUS_SQUARES];
    s16 yChange[NUM_STATUS_SQUARES];
    u16 spriteIds[NUM_STATUS_SQUARES];
    u16 flashTimer;
}; // size = 0x40

struct PickStatePacket
{
    u8 id;
    u8 ALIGNED(4) pickState;
};

struct ReadyToEndPacket
{
    u8 id;
    bool32 ready;
};

struct GameStatePacket
{
    u8 id;
    u8 fallDist_Col0:4;
    u8 fallDist_Col1:4;
    u16 fallDist_Col2:4;
    u16 fallDist_Col3:4;
    u16 fallDist_Col4:4;
    u16 fallDist_Col5:4;
    u16 fallDist_Col6:4;
    u16 fallDist_Col7:4;
    u16 fallDist_Col8:4;
    u16 fallDist_Col9:4;
    u16 berryId_Col0:2;
    u16 berryId_Col1:2;
    u16 berryId_Col2:2;
    u16 berryId_Col3:2;
    u16 berryId_Col4:2;
    u16 berryId_Col5:2;
    u16 berryId_Col6:2;
    u16 berryId_Col7:2;
    u8 berryId_Col8:2;
    u8 berryId_Col9:2;
    u8 pickState_Player1:2;
    u8 pickState_Player2:2;
    u8 pickState_Player3:2;
    u8 pickState_Player4:2;
    u8 pickState_Player5:2;
    bool8 ateBerry_Player1:1;
    bool8 ateBerry_Player2:1;
    bool8 ateBerry_Player3:1;
    bool8 ateBerry_Player4:1;
    bool8 ateBerry_Player5:1;
    u8 numGraySquares:5;
    bool8 allReadyToEnd:1;
    bool8 berriesFalling:1;
    bool8 missedBerry_Player1:1;
    bool8 missedBerry_Player2:1;
    bool8 missedBerry_Player3:1;
    bool8 missedBerry_Player4:1;
    bool8 missedBerry_Player5:1;
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

enum {
    PRIZE_RECEIVED,
    PRIZE_FILLED_BAG,
    PRIZE_NO_ROOM,
    NO_PRIZE,
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

#define tState data[0]

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
extern void GetActiveBerryColumns(u8, u8 *, u8 *);
extern void InitMonInfo(struct DodrioGame_MonInfo *, struct Pokemon *);
extern void Task_CommunicateMonInfo(u8 taskId);
extern void Task_NewGameIntro(u8 taskId);
extern void VBlankCB_DodrioGame(void);
extern void CreateTask_(TaskFunc func, u8 priority);
extern void InitGameGfx(struct DodrioGame_Gfx *);
extern bool32 IsGfxFuncActive(void);
extern void CreateDodrioSprite(struct DodrioGame_MonInfo *, u8, u8, u8);
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
extern void SetGfxFuncById(u8);
extern void SetGameFunc(u8);
extern void InitFirstWaveOfBerries(void);
extern void UpdateFallingBerries(void);
extern void HandleSound_Leader(void);
extern void HandleSound_Member(void);
extern bool32 ReadyToEndGame_Leader(void);
extern bool32 ReadyToEndGame_Member(void);
extern u32 sub_08027480(u8 playerId); // GetScore
extern void SetStatusBarInvisibility(bool8);
extern void ResetCloudPos(void);
extern void SetCloudInvisibility(bool8);
extern u8 GetPlayAgainState(void);
extern void ResetBerryAndStatusBarSprites(void);
extern void sub_08026748(void); // UpdateBerrySprites
extern void sub_08026848(void); // UpdateAllDodrioAnims
extern void FreeBerrySprites(void);
extern void FreeStatusBar(void);
extern void FreeCloudSprites(void);
extern void StartCloudMovement(void);
extern void ResetGfxState(void);
extern bool32 SlideTreeBordersOut(void);
extern void InitStatusBarPos(void);
extern bool32 DoStatusBarIntro(void);
extern const u8 sActiveColumnMap[MAX_RFU_PLAYERS][MAX_RFU_PLAYERS][NUM_BERRY_COLUMNS];
extern const u8 sDifficultyThresholds[NUM_DIFFICULTIES];
extern const u8 sPrizeBerryIds[3][10];
extern const s16 sBerryScoreMultipliers[NUM_BERRY_IDS];
extern const u8 sPlayerIdAtColumn[MAX_RFU_PLAYERS][NUM_BERRY_COLUMNS];
extern const u8 sDodrioNeighborMap[MAX_RFU_PLAYERS][MAX_RFU_PLAYERS][3];
extern const u8 sUnsharedColumns[MAX_RFU_PLAYERS][MAX_RFU_PLAYERS];
extern const u32 sDodrio_Gfx[];
extern const struct SpritePalette sDodrioNormalSpritePalette;
extern const struct SpritePalette sDodrioShinySpritePalette;
extern const struct OamData sOamData_Dodrio;
extern const union AnimCmd *const sAnims_Dodrio[];
extern const union AffineAnimCmd *const gDummySpriteAffineAnimTable[];
extern EWRAM_DATA u16 *sDodrioSpriteIds[MAX_RFU_PLAYERS];
extern EWRAM_DATA struct StatusBar *sStatusBar;
extern void sub_08028268(struct Sprite *sprite); // DoDodrioMissedAnim
extern void sub_080282D8(struct Sprite *sprite); // DoDodrioIntroAnim
extern s16 sub_08028C40(u8 playerId, u8 numPlayers); // GetDodrioXPos
extern const struct WindowTemplate sRecordsWindowTemplate;
extern void sub_0802792C(u8 windowId); // JP records window drawing
void LoadDodrioGfx(void);
void SetDodrioInvisibility(bool8 invisible, u8 id);
void SetAllDodrioInvisibility(bool8 invisible, u8 count);
void StartDodrioIntroAnim(u8 unused);
u32 IncrementWithLimit(u32 num, u32 max);
u32 Min(u32 a, u32 b);
u32 RecvPacket_ReadyToStart(u32 playerId);
void SpriteCB_Dodrio(struct Sprite *sprite);
void Task_ShowDodrioRecords(u8 taskId);

// Prototypes for functions converted from asm (definitions later in this file)
void InitDodrioGame(struct DodrioGame *game);
void Task_StartDodrioGame(u8 taskId);
void Task_DodrioGame_Leader(u8 taskId);
void Task_DodrioGame_Member(u8 taskId);
void DoGameIntro(void);
void InitCountdown(void);
void DoCountdown(void);
void WaitGameStart(void);
void PlayGame_Leader(void);
void PlayGame_Member(void);
void WaitEndGame_Leader(void);
void WaitEndGame_Member(void);
bool32 AllLinkBlocksReceived(void);
bool32 AllPlayersReadyToStart(void);
void ResetReadyToStart(void);
bool32 ReadyToEndGame_Leader(void);
bool32 ReadyToEndGame_Member(void);
void TryIncrementDifficulty(u8 playerId);
u8 GetNewBerryIdByDifficulty(u8 difficulty, u8 column);
u8 GetPlayerIdAtColumn(u8 column);
u8 GetNewBerryId(u8 playerId, u8 column);
bool32 IsTotalBerriesMissedOver10(u16 berryResults[MAX_RFU_PLAYERS][NUM_BERRY_IDS]);
void IncrementBerryResult(u8 berryIdArg, u8 column, u8 playerId);
void UpdateBerriesPickedInRow(bool32 picked);
void SetMaxBerriesPickedInRow(void);
void ResetForPlayAgainPrompt(void);
void SetRandomPrize(void);
u32 GetBerriesPicked(u8 playerId);
void TryUpdateRecords(void);
u8 UpdatePickStateQueue(u8 pickState);
void HandleWaitPlayAgainInput(void);
void ResetPickState(void);
u16 GetPrizeItemId(void);
u8 GetNumPlayers(void);
u16 GetBerryResult(u8 playerId, u8 berryId);
u32 GetScore(u8 playerId);
u32 GetHighestScore(void);
u16 GetHighestBerryResult(u8 berryId);
u32 GetScoreByRanking(u8 ranking);
u32 SetScoreResults(void);
void GetScoreResults(struct DodrioGame_ScoreResults *dst, u8 playerId);
u8 GetScoreRanking(u8 playerId);
u8 TryGivePrize(void);
u32 IncrementWithLimit(u32 num, u32 max);
u32 Min(u32 a, u32 b);
u8 GetPlayerIdByPos(u8 pos);
void SetNumPlayers(void);
void SendRfuPacket(u32 cmd);
u32 RecvPacket_ReadyToStart(u32 playerId);
void SendPacket_PickState(u8 pickState);
bool32 RecvPacket_PickState(u32 playerId, u8 *pickState);
void SendPacket_ReadyToEnd(bool32 ready);
bool32 RecvPacket_ReadyToEnd(u32 playerId);
void LoadDodrioGfx(void);
void CreateDodrioSprite(struct DodrioGame_MonInfo *monInfo, u8 playerId, u8 id, u8 numPlayers);
void SpriteCB_Dodrio(struct Sprite *sprite);
void StartDodrioMissedAnim(u8 unused);
void StartDodrioIntroAnim(u8 unused);
void FreeDodrioSprites(u8 numPlayers);
void SetDodrioInvisibility(bool8 invisible, u8 id);
void SetAllDodrioInvisibility(bool8 invisible, u8 count);
void SetDodrioAnim(u8 playerId, u8 animNum);
void InitStatusBarPos(void);
void nullsub_15(void);
u32 DoDodrioMissedAnim(struct Sprite *sprite);
u32 DoDodrioIntroAnim(struct Sprite *sprite);
void SendPacket_GameState(struct DodrioGame_Player *player, struct DodrioGame_PlayerCommData *player1, struct DodrioGame_PlayerCommData *player2, struct DodrioGame_PlayerCommData *player3, struct DodrioGame_PlayerCommData *player4, struct DodrioGame_PlayerCommData *player5, u8 numGraySquares, bool32 berriesFalling, bool32 allReadyToEnd);
bool32 RecvPacket_GameState(u32 playerId, struct DodrioGame_Player *player, struct DodrioGame_PlayerCommData *player1, struct DodrioGame_PlayerCommData *player2, struct DodrioGame_PlayerCommData *player3, struct DodrioGame_PlayerCommData *player4, struct DodrioGame_PlayerCommData *player5, u8 *numGraySquares, bool32 *berriesFalling, bool32 *allReadyToEnd);
void CheckDodrioInParty(void);
void ShowDodrioRecords(void);
void Task_ShowDodrioRecords(u8 taskId);
void InitResults_Leader(void);
void InitResults_Member(void);
void DoResults(void);
void AskPlayAgain(void);
void EndLink(void);
void ExitGame(void);
void ResetGame_Dodrio(void);
void Task_NewGameIntro(u8 taskId);
void Task_CommunicateMonInfo(u8 taskId);
void RecvLinkData_Gameplay(void);
void RecvLinkData_ReadyToEnd(void);
void StartDodrioBerryPicking(u16 partyId, MainCallback exitCallback);

void ResetGame_Dodrio(void);
#define ResetGame ResetGame_Dodrio

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

bool32 AllLinkBlocksReceived(void)
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

bool32 AllPlayersReadyToStart(void)
{
    u8 i, numPlayers;

    numPlayers = sGame->numPlayers;
    for (i = 1; i < numPlayers; i++)
    {
        if (sGame->readyToStart[i] == FALSE)
            sGame->readyToStart[i] = RecvPacket_ReadyToStart(i);
    }

    numPlayers = numPlayers; // Needed to force compiler to keep loop below

    for (; i < numPlayers; i++)
    {
        if (sGame->readyToStart[i] == FALSE)
            return FALSE;
    }
    return TRUE;
}

void ResetReadyToStart(void)
{
    u8 i;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        sGame->readyToStart[i] = FALSE;
}

bool32 ReadyToEndGame_Leader(void)
{
    if (sGame->numGraySquares >= NUM_STATUS_SQUARES && !sGame->berriesFalling)
    {
        sGame->numGraySquares = NUM_STATUS_SQUARES;
        if (sGame->allReadyToEnd)
            return TRUE;
    }

    return FALSE;
}

bool32 ReadyToEndGame_Member(void)
{
    u8 i, berryStart, berryEnd;

    if (sGame->numGraySquares >= NUM_STATUS_SQUARES)
    {
        berryStart = sGame->berryColStart;
        berryEnd = sGame->berryColEnd;
        sGame->numGraySquares = NUM_STATUS_SQUARES;
        if (sGame->allReadyToEnd)
        {
            for (i = berryStart; i < berryEnd; i++)
            {
                struct DodrioGame_Player *player = &sGame->players[sGame->multiplayerId];
                u8 column = sActiveColumnMap[sGame->numPlayers - 1][sGame->multiplayerId][i];

                if (player->berries.fallDist[column] != MAX_FALL_DIST)
                    return FALSE;
            }
            return TRUE;
        }
    }

    return FALSE;
}

void TryIncrementDifficulty(u8 playerId)
{
    u8 threshold = sDifficultyThresholds[sGame->difficulty[playerId] % NUM_DIFFICULTIES] + (sGame->difficulty[playerId] / NUM_DIFFICULTIES) * 100;
    if (sGame->berriesEaten[playerId] >= threshold)
        sGame->difficulty[playerId]++;
}

u8 GetNewBerryIdByDifficulty(u8 difficulty, u8 column)
{
    u8 prevBerryId = sGame->prevBerryIds[column];
    switch (difficulty % NUM_DIFFICULTIES)
    {
    default: return BERRY_BLUE;
    case 0:  return BERRY_BLUE;
    case 1:  return BERRY_GREEN;
    case 2:  return BERRY_GOLD;
    case 3:
        if (prevBerryId == BERRY_BLUE)
            return BERRY_GREEN;
        else
            return BERRY_BLUE;
    case 4:
        if (prevBerryId == BERRY_BLUE)
            return BERRY_GOLD;
        else
            return BERRY_BLUE;
    case 5:
        if (prevBerryId == BERRY_GOLD)
            return BERRY_GREEN;
        else
            return BERRY_GOLD;
    case 6:
        if (prevBerryId == BERRY_BLUE)
            return BERRY_GREEN;
        else if (prevBerryId == BERRY_GREEN)
            return BERRY_GOLD;
        else
            return BERRY_BLUE;
    }
}

u8 GetPlayerIdAtColumn(u8 column)
{
    return sPlayerIdAtColumn[sGame->numPlayers - 1][column];
}

u8 GetNewBerryId(u8 playerId, u8 column)
{
    u8 i, highestDifficulty;
    u8 numPlayersIdx = sGame->numPlayers - 1;
    u8 leftPlayer = sDodrioNeighborMap[numPlayersIdx][playerId][0];
    u8 middlePlayer = sDodrioNeighborMap[numPlayersIdx][playerId][1];
    u8 rightPlayer = sDodrioNeighborMap[numPlayersIdx][playerId][2];

    for (i = 0; sUnsharedColumns[numPlayersIdx][i] != 0; i++)
    {
        // If only one player can use this column, just use their difficulty
        if (column == sUnsharedColumns[numPlayersIdx][i])
            return GetNewBerryIdByDifficulty(sGame->difficulty[middlePlayer], column);
    }

    // This column is shared, get the highest difficulty of adjacent players
    if (sGame->difficulty[leftPlayer] > sGame->difficulty[middlePlayer])
        highestDifficulty = sGame->difficulty[leftPlayer];
    else
        highestDifficulty = sGame->difficulty[middlePlayer];

    if (sGame->difficulty[rightPlayer] > highestDifficulty)
        highestDifficulty = sGame->difficulty[rightPlayer];

    return GetNewBerryIdByDifficulty(highestDifficulty, column);
}

bool32 IsTotalBerriesMissedOver10(u16 berryResults[MAX_RFU_PLAYERS][NUM_BERRY_IDS])
{
    int missed = 0, i = 0;
    for (; i < GetLinkPlayerCount(); missed += berryResults[i][BERRY_MISSED], i++)
        ;

    if (missed > 10)
        return TRUE;
    else
        return FALSE;
}

void IncrementBerryResult(u8 berryIdArg, u8 column, u8 playerId)
{
    u8 berryId;
    u8 numPlayers = sGame->numPlayers;
    switch (berryIdArg)
    {
    case BERRY_BLUE:
    case BERRY_GREEN:
    case BERRY_GOLD:
        berryId = sGame->players[0].berries.ids[column];
        sGame->berryResults[playerId][berryId] = IncrementWithLimit(sGame->berryResults[playerId][berryId], 20000);
        break;
    case BERRY_MISSED:
        if (IsTotalBerriesMissedOver10(sGame->berryResults))
            break;
        switch (numPlayers)
        {
        case 5:
            switch (column)
            {
            case 0:
                sGame->berryResults[2][BERRY_MISSED]++;
                sGame->berryResults[3][BERRY_MISSED]++;
                break;
            case 1:
                sGame->berryResults[3][BERRY_MISSED]++;
                break;
            case 2:
                sGame->berryResults[3][BERRY_MISSED]++;
                sGame->berryResults[4][BERRY_MISSED]++;
                break;
            case 3:
                sGame->berryResults[4][BERRY_MISSED]++;
                break;
            case 4:
                sGame->berryResults[4][BERRY_MISSED]++;
                sGame->berryResults[0][BERRY_MISSED]++;
                break;
            case 5:
                sGame->berryResults[0][BERRY_MISSED]++;
                break;
            case 6:
                sGame->berryResults[0][BERRY_MISSED]++;
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            case 7:
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            case 8:
                sGame->berryResults[1][BERRY_MISSED]++;
                sGame->berryResults[2][BERRY_MISSED]++;
                break;
            case 9:
                sGame->berryResults[2][BERRY_MISSED]++;
                break;
            }
            break;
        case 4:
            switch (column)
            {
            case 1:
                sGame->berryResults[2][BERRY_MISSED]++;
                sGame->berryResults[3][BERRY_MISSED]++;
                break;
            case 2:
                sGame->berryResults[3][BERRY_MISSED]++;
                break;
            case 3:
                sGame->berryResults[3][BERRY_MISSED]++;
                sGame->berryResults[0][BERRY_MISSED]++;
                break;
            case 4:
                sGame->berryResults[0][BERRY_MISSED]++;
                break;
            case 5:
                sGame->berryResults[0][BERRY_MISSED]++;
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            case 6:
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            case 7:
                sGame->berryResults[1][BERRY_MISSED]++;
                sGame->berryResults[2][BERRY_MISSED]++;
                break;
            case 8:
                sGame->berryResults[2][BERRY_MISSED]++;
                break;
            }
            break;
        case 3:
            switch (column)
            {
            case 2:
                sGame->berryResults[1][BERRY_MISSED]++;
                sGame->berryResults[2][BERRY_MISSED]++;
                break;
            case 3:
                sGame->berryResults[2][BERRY_MISSED]++;
                break;
            case 4:
                sGame->berryResults[2][BERRY_MISSED]++;
                sGame->berryResults[0][BERRY_MISSED]++;
                break;
            case 5:
                sGame->berryResults[0][BERRY_MISSED]++;
                break;
            case 6:
                sGame->berryResults[0][BERRY_MISSED]++;
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            case 7:
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            }
            break;
        case 2:
            switch (column)
            {
            case 3:
                sGame->berryResults[0][BERRY_MISSED]++;
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            case 4:
                sGame->berryResults[0][BERRY_MISSED]++;
                break;
            case 5:
                sGame->berryResults[0][BERRY_MISSED]++;
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            case 6:
                sGame->berryResults[1][BERRY_MISSED]++;
                break;
            }
            break;
        }
        break;
    }
}

void UpdateBerriesPickedInRow(bool32 picked)
{
    // The 'berries picked in row' stat is only
    // counted for games with all 5 players
    if (sGame->numPlayers != MAX_RFU_PLAYERS)
        return;

    if (picked == TRUE)
    {
        if (++sGame->berriesPickedInRow > sGame->maxBerriesPickedInRow)
            sGame->maxBerriesPickedInRow = sGame->berriesPickedInRow;
        if (sGame->berriesPickedInRow > MAX_BERRIES)
            sGame->berriesPickedInRow = MAX_BERRIES;
    }
    else // missed
    {
        if (sGame->berriesPickedInRow > sGame->maxBerriesPickedInRow)
            sGame->maxBerriesPickedInRow = sGame->berriesPickedInRow;
        sGame->berriesPickedInRow = 0;
    }
}

void SetMaxBerriesPickedInRow(void)
{
    u8 i;
    for (i = 0; i < sGame->numPlayers; i++)
        sGame->berryResults[i][BERRY_IN_ROW] = sGame->maxBerriesPickedInRow;
}

void ResetForPlayAgainPrompt(void)
{
    u8 i, j;

    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        for (j = 0; j < NUM_BERRY_COLUMNS; j++)
            sGame->players[i].berries.fallDist[j] = 0;
        sGame->players[i].comm.pickState = PICK_NONE;
        sGame->players[i].comm.ateBerry = FALSE;
        sGame->difficulty[i] = 0;
        sGame->berriesEaten[i] = 0;
        sGame->scoreResults[i].ranking = 0;
        sGame->scoreResults[i].score = 0;
        sGame->berryResults[i][BERRY_BLUE] = 0;
        sGame->berryResults[i][BERRY_GREEN] = 0;
        sGame->berryResults[i][BERRY_GOLD] = 0;
        sGame->berryResults[i][BERRY_MISSED] = 0;
        sGame->berryResults[i][BERRY_PRIZE] = 0;
        sGame->berryResults[i][BERRY_IN_ROW] = 0;
    }
    sGame->endSoundState = 0;
    sGame->berriesPickedInRow = 0;
    sGame->numGraySquares = 0;
    sub_08026848(); // UpdateAllDodrioAnims
    sub_08026748(); // UpdateBerrySprites
}

void SetRandomPrize(void)
{
    u8 i, prizeSet = 0, prizeIdx = 0;

    switch (sGame->numPlayers)
    {
    case 4:  prizeSet = 1; break;
    case 5:  prizeSet = 2; break;
    }

    prizeIdx = Random() % ARRAY_COUNT(sPrizeBerryIds[0]);
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        sGame->berryResults[i][BERRY_PRIZE] = sPrizeBerryIds[prizeSet][prizeIdx];
}

u32 GetBerriesPicked(u8 playerId)
{
    u32 sum = sGame->berryResults[playerId][BERRY_BLUE]
            + sGame->berryResults[playerId][BERRY_GREEN]
            + sGame->berryResults[playerId][BERRY_GOLD];
    return min(sum, MAX_BERRIES);
}

void TryUpdateRecords(void)
{
    u32 berriesPicked = Min(GetBerriesPicked(sGame->multiplayerId), MAX_BERRIES); // Min here is redundant
    u32 score = Min(sub_08027480(sGame->multiplayerId), MAX_SCORE);

    if (gSaveBlock2Ptr->berryPick.bestScore < score)
        gSaveBlock2Ptr->berryPick.bestScore = score;
    if (gSaveBlock2Ptr->berryPick.berriesPicked < berriesPicked)
        gSaveBlock2Ptr->berryPick.berriesPicked = berriesPicked;
    if (gSaveBlock2Ptr->berryPick.berriesPickedInRow < sGame->maxBerriesPickedInRow)
        gSaveBlock2Ptr->berryPick.berriesPickedInRow = sGame->maxBerriesPickedInRow;
}

u8 UpdatePickStateQueue(u8 pickState)
{
    u8 i, nextState;

    nextState = sGame->pickStateQueue[ARRAY_COUNT(sGame->pickStateQueue) - 1];
    for (i = ARRAY_COUNT(sGame->pickStateQueue) - 1; i != 0; i--)
        sGame->pickStateQueue[i] = sGame->pickStateQueue[i - 1];
    sGame->pickStateQueue[0] = pickState;
    return nextState;
}

void HandleWaitPlayAgainInput(void)
{
    if (sGame->inputDelay[sGame->multiplayerId] == 0)
    {
        if (JOY_NEW(DPAD_UP))
        {
            sGame->players[sGame->multiplayerId].comm.pickState = PICK_MIDDLE;
            sGame->inputDelay[sGame->multiplayerId] = 6;
            PlaySE(SE_M_CHARM);
        }
        else if (JOY_NEW(DPAD_LEFT))
        {
            sGame->players[sGame->multiplayerId].comm.pickState = PICK_LEFT;
            sGame->inputDelay[sGame->multiplayerId] = 6;
            PlaySE(SE_M_CHARM);
        }
        else if (JOY_NEW(DPAD_RIGHT))
        {
            sGame->players[sGame->multiplayerId].comm.pickState = PICK_RIGHT;
            sGame->inputDelay[sGame->multiplayerId] = 6;
            PlaySE(SE_M_CHARM);
        }
        else
        {
            sGame->players[sGame->multiplayerId].comm.pickState = PICK_NONE;
        }
    }
    else
    {
        sGame->inputDelay[sGame->multiplayerId]--;
    }
}

void ResetPickState(void)
{
    sGame->players[sGame->multiplayerId].comm.pickState = PICK_NONE;
}

u16 GetPrizeItemId(void)
{
    return sGame->berryResults[sGame->multiplayerId][BERRY_PRIZE] + FIRST_BERRY_INDEX;
}

u8 GetNumPlayers(void)
{
    return sGame->numPlayers;
}

u8 *GetPlayerName(u8 playerId)
{
    if (gReceivedRemoteLinkPlayers)
        return gLinkPlayers[playerId].name;
    return sGame->players[playerId].name;
}

u16 GetBerryResult(u8 playerId, u8 berryId)
{
    return sGame->berryResults[playerId][berryId];
}

u32 GetScore(u8 playerId)
{
    u8 i;
    u32 scoreLost, score = 0;

    // Sum up points for berries picked
    for (i = 0; i < BERRY_MISSED; i++)
        score += sGame->berryResults[playerId][i] * sBerryScoreMultipliers[i];

    // Get points lost for berries missed
    scoreLost = sGame->berryResults[playerId][BERRY_MISSED] * sBerryScoreMultipliers[BERRY_MISSED];

    if (score <= scoreLost)
        return 0;
    else
        return score - scoreLost;
}

u32 GetHighestScore(void)
{
    u8 i, numPlayers = sGame->numPlayers;
    u32 maxScore = GetScore(0);

    for (i = 1; i < numPlayers; i++)
    {
        u32 score = GetScore(i);
        if (score > maxScore)
            maxScore = score;
    }
    return Min(maxScore, MAX_SCORE);
}

u16 GetHighestBerryResult(u8 berryId)
{
    u8 i, numPlayers = sGame->numPlayers;
    u16 highest = sGame->berryResults[0][berryId];
    for (i = 0; i < numPlayers; i++)
    {
        u16 result = sGame->berryResults[i][berryId];
        if (result > highest)
            highest = result;
    }
    return highest;
}

u32 GetScoreByRanking(u8 ranking)
{
    u32 scores[MAX_RFU_PLAYERS], temp;
    s16 unsorted = TRUE;
    u8 i;
    u8 numPlayers = sGame->numPlayers;

    for (i = 0; i < numPlayers; i++)
        scores[i] = temp = GetScore(i);

    // Sort the scores in the array highest to lowest
    while (unsorted)
    {
        unsorted = FALSE;
        for (i = 0; i < numPlayers - 1; i++)
        {
            if (scores[i] < scores[i + 1])
            {
                SWAP(scores[i], scores[i + 1], temp);
                unsorted = TRUE;
            }
        }
    }

    return scores[ranking];
}

u32 SetScoreResults(void)
{
    u8 i, ranking = 0, nextRanking = 0, playersRanked = 0;
    u8 numPlayers = sGame->numPlayers;

    GetHighestScore(); // Useless call

    if (GetHighestScore() == 0)
    {
        // No one scored any points, put everyone in last place with a score of 0.
        // Presumably this was supposed to then return, as the assignments in this
        // loop are then overwritten by the rest of the function
        for (i = 0; i < numPlayers; i++)
        {
            sGame->scoreResults[i].ranking = MAX_RFU_PLAYERS - 1;
            sGame->scoreResults[i].score = 0;
        }
    }

    // Set scores
    for (i = 0; i < numPlayers; i++)
        sGame->scoreResults[i].score = Min(GetScore(i), MAX_SCORE);

    // Set rankings
    do
    {
        u32 score = GetScoreByRanking(ranking);
        u8 curRanking = nextRanking;

        // Find all players with the score for this ranking.
        // Increment nextRanking but not curRanking to allow
        // for ties
        for (i = 0; i < numPlayers; i++)
        {
            if (score == sGame->scoreResults[i].score)
            {
                sGame->scoreResults[i].ranking = curRanking;
                nextRanking++;
                playersRanked++;
            }
        }
        ranking = nextRanking;
    } while (playersRanked < numPlayers);

    return 0;
}

void GetScoreResults(struct DodrioGame_ScoreResults *dst, u8 playerId)
{
    *dst = sGame->scoreResults[playerId];
}

u8 GetScoreRanking(u8 playerId)
{
    u8 i, ranking = 0;
    u8 numPlayers = sGame->numPlayers;
    u32 playersScore;
    u32 scores[MAX_RFU_PLAYERS] = {0};

    for (i = 0; i < numPlayers; i++)
        scores[i] = GetScore(i);

    playersScore = scores[playerId];
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
    {
        if (i != playerId && playersScore < scores[i])
            ranking++;
    }

    return ranking;
}

u8 TryGivePrize(void)
{
    u8 multiplayerId = sGame->multiplayerId;
    u16 itemId = GetPrizeItemId();

    if (GetScore(multiplayerId) != GetHighestScore())
        return NO_PRIZE;
    if (!CheckBagHasSpace(itemId, 1))
        return PRIZE_NO_ROOM;

    AddBagItem(itemId, 1);
    if (!CheckBagHasSpace(itemId, 1))
        return PRIZE_FILLED_BAG;
    return PRIZE_RECEIVED;
}

u32 IncrementWithLimit(u32 num, u32 max)
{
    if (num < max)
        return num + 1;
    else
        return max;
}

u32 Min(u32 a, u32 b)
{
    if (a < b)
        return a;
    else
        return b;
}

u8 GetPlayerIdByPos(u8 pos)
{
    return sGame->posToPlayerId[pos];
}

void SetNumPlayers(void)
{
    sGame->numPlayers = GetLinkPlayerCount();
}

void SendRfuPacket(u32 cmd)
{
    struct { u32 a, b; } pkt;
    u8 c;
    pkt.a = (pkt.a & 0xFFFFFF00) | 1;
    c = cmd;
    pkt.b = (pkt.b & 0xFFFFFF00) | c;
    Rfu_SendPacket(&pkt);
}

u32 RecvPacket_ReadyToStart(u32 playerId)
{
    struct ReadyToStartPacket *packet;

    if ((gRecvCmds[0][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    packet = (void *)&gRecvCmds[playerId][1];
    if (packet->id == PACKET_READY_START)
        return packet->ready;
    return FALSE;
}

void SendPacket_PickState(u8 pickState)
{
    struct PickStatePacket packet;
    packet.id = PACKET_PICK_STATE;
    packet.pickState = pickState;
    Rfu_SendPacket(&packet);
}

bool32 RecvPacket_PickState(u32 playerId, u8 *pickState)
{
    struct PickStatePacket *packet;

    if ((gRecvCmds[0][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    packet = (void *)&gRecvCmds[playerId][1];
    if (packet->id == PACKET_PICK_STATE)
    {
        *pickState = packet->pickState;
        return TRUE;
    }
    else
        return FALSE;
}

void SendPacket_ReadyToEnd(bool32 ready)
{
    struct ReadyToEndPacket packet;
    packet.id = PACKET_READY_END;
    packet.ready = ready;
    Rfu_SendPacket(&packet);
}

bool32 RecvPacket_ReadyToEnd(u32 playerId)
{
    struct ReadyToEndPacket *packet;

    if ((gRecvCmds[0][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    packet = (void *)&gRecvCmds[playerId][1];
    if (packet->id == PACKET_READY_END)
        return packet->ready;
    else
        return FALSE;
}

void LoadDodrioGfx(void)
{
    void *ptr = AllocZeroed(0x3000);
    struct SpritePalette normal = sDodrioNormalSpritePalette;
    struct SpritePalette shiny = sDodrioShinySpritePalette;

    LZ77UnCompWram(sDodrio_Gfx, ptr);
    if (ptr)
    {
        struct SpriteSheet sheet = {ptr, 0x3000, GFXTAG_DODRIO};
        LoadSpriteSheet(&sheet);
        Free(ptr);
    }
    LoadSpritePalette(&normal);
    LoadSpritePalette(&shiny);
}

void CreateDodrioSprite(struct DodrioGame_MonInfo *monInfo, u8 playerId, u8 id, u8 numPlayers)
{
    struct SpriteTemplate template =
    {
        .tileTag = GFXTAG_DODRIO,
        .paletteTag = monInfo->isShiny, // PALTAG_DODRIO_NORMAL / PALTAG_DODRIO_SHINY
        .oam = &sOamData_Dodrio,
        .anims = sAnims_Dodrio,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCB_Dodrio,
    };

    sDodrioSpriteIds[id] = AllocZeroed(4);
    *sDodrioSpriteIds[id] = CreateSprite(&template, sub_08028C40(playerId, numPlayers), 136, 3);
    SetDodrioInvisibility(TRUE, id);
}

void SpriteCB_Dodrio(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        break;
    case 1:
        sub_08028268(sprite); // DoDodrioMissedAnim
        break;
    case 2:
        sub_080282D8(sprite); // DoDodrioIntroAnim
        break;
    }
}

void StartDodrioMissedAnim(u8 unused)
{
    struct Sprite *sprite = &gSprites[*sDodrioSpriteIds[GetMultiplayerId()]];
    sprite->data[0] = 1;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
}

void StartDodrioIntroAnim(u8 unused)
{
    struct Sprite *sprite = &gSprites[*sDodrioSpriteIds[GetMultiplayerId()]];
    sprite->data[0] = 2;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
}

void FreeDodrioSprites(u8 numPlayers)
{
    u8 i;
    for (i = 0; i < numPlayers; i++)
    {
        struct Sprite *sprite = &gSprites[*sDodrioSpriteIds[i]];
        if (sprite)
            DestroySpriteAndFreeResources(sprite);
    }
}

void SetDodrioInvisibility(bool8 invisible, u8 id)
{
    gSprites[*sDodrioSpriteIds[id]].invisible = invisible;
}

void SetAllDodrioInvisibility(bool8 invisible, u8 count)
{
    u8 i;
    for (i = 0; i < count; i++)
        SetDodrioInvisibility(invisible, i);
}

void SetDodrioAnim(u8 playerId, u8 animNum)
{
    StartSpriteAnim(&gSprites[*sDodrioSpriteIds[playerId]], animNum);
}

void InitStatusBarPos(void)
{
    u8 i;
    for (i = 0; i < NUM_STATUS_SQUARES; i++)
    {
        struct Sprite *sprite = &gSprites[sStatusBar->spriteIds[i]];
        sprite->x = (i * 16) + 48;
        sprite->y = -8 - (i * 8);
        sStatusBar->entered[i] = FALSE;
    }
}

void nullsub_15(void)
{
}

u32 DoDodrioMissedAnim(struct Sprite *sprite)
{
    s8 x;
    u8 state = (++sprite->data[1] / 2) % 4;

    if (sprite->data[1] >= 3)
    {
        switch (state)
        {
        default:
            x = 1;
            break;
        case 1:
        case 2:
            x = -1;
            break;
        }

        sprite->x += x;
        if (++sprite->data[1] >= 40)
        {
            sprite->data[0] = 0;
            sprite->x = sub_08028C40(0, GetNumPlayers());
        }
    }

    return 0;
}

#define FRAMES_PER_STATE 13
#define NUM_INTRO_PICK_STATES PICK_DISABLED // Cycle through 'Normal' and each head, but exclude the Disabled state

u32 DoDodrioIntroAnim(struct Sprite *sprite)
{
    u8 pickState = (++sprite->data[1] / FRAMES_PER_STATE) % NUM_INTRO_PICK_STATES;

    // Play a sound effect at the start of each head extension
    if (sprite->data[1] % FRAMES_PER_STATE == 0 && pickState != PICK_NONE)
        PlaySE(SE_M_CHARM);

    if (sprite->data[1] >= FRAMES_PER_STATE * NUM_INTRO_PICK_STATES * 2)
    {
        // End animation
        sprite->data[0] = 0;
        pickState = PICK_NONE;
    }
    SetDodrioAnim(GetMultiplayerId(), pickState);
    return 0;
}

#undef FRAMES_PER_STATE
#undef NUM_INTRO_PICK_STATES

void SendPacket_GameState(struct DodrioGame_Player *player,
                          struct DodrioGame_PlayerCommData *player1,
                          struct DodrioGame_PlayerCommData *player2,
                          struct DodrioGame_PlayerCommData *player3,
                          struct DodrioGame_PlayerCommData *player4,
                          struct DodrioGame_PlayerCommData *player5,
                          u8 numGraySquares,
                          bool32 berriesFalling,
                          bool32 allReadyToEnd)
{
    struct GameStatePacket packet;
    struct DodrioGame_Berries *berries = &player->berries;

    packet.id = PACKET_GAME_STATE;
    packet.fallDist_Col0 = berries->fallDist[0];
    packet.fallDist_Col1 = berries->fallDist[1];
    packet.fallDist_Col2 = berries->fallDist[2];
    packet.fallDist_Col3 = berries->fallDist[3];
    packet.fallDist_Col4 = berries->fallDist[4];
    packet.fallDist_Col5 = berries->fallDist[5];
    packet.fallDist_Col6 = berries->fallDist[6];
    packet.fallDist_Col7 = berries->fallDist[7];
    packet.fallDist_Col8 = berries->fallDist[8];
    packet.fallDist_Col9 = berries->fallDist[9];

    packet.berryId_Col0 = berries->ids[0];
    packet.berryId_Col1 = berries->ids[1];
    packet.berryId_Col2 = berries->ids[2];
    packet.berryId_Col3 = berries->ids[3];
    packet.berryId_Col4 = berries->ids[4];
    packet.berryId_Col5 = berries->ids[5];
    packet.berryId_Col6 = berries->ids[6];
    packet.berryId_Col7 = berries->ids[7];
    packet.berryId_Col8 = berries->ids[8];
    packet.berryId_Col9 = berries->ids[9];

    packet.pickState_Player1 = player1->pickState;
    packet.pickState_Player2 = player2->pickState;
    packet.pickState_Player3 = player3->pickState;
    packet.pickState_Player4 = player4->pickState;
    packet.pickState_Player5 = player5->pickState;

    packet.ateBerry_Player1 = player1->ateBerry;
    packet.ateBerry_Player2 = player2->ateBerry;
    packet.ateBerry_Player3 = player3->ateBerry;
    packet.ateBerry_Player4 = player4->ateBerry;
    packet.ateBerry_Player5 = player5->ateBerry;

    packet.missedBerry_Player1 = player1->missedBerry;
    packet.missedBerry_Player2 = player2->missedBerry;
    packet.missedBerry_Player3 = player3->missedBerry;
    packet.missedBerry_Player4 = player4->missedBerry;
    packet.missedBerry_Player5 = player5->missedBerry;

    packet.numGraySquares = numGraySquares;
    packet.berriesFalling = berriesFalling;
    packet.allReadyToEnd = allReadyToEnd;
    Rfu_SendPacket(&packet);
}

bool32 RecvPacket_GameState(u32 playerId,
                            struct DodrioGame_Player *player,
                            struct DodrioGame_PlayerCommData *player1,
                            struct DodrioGame_PlayerCommData *player2,
                            struct DodrioGame_PlayerCommData *player3,
                            struct DodrioGame_PlayerCommData *player4,
                            struct DodrioGame_PlayerCommData *player5,
                            u8 *numGraySquares,
                            bool32 *berriesFalling,
                            bool32 *allReadyToEnd)
{
    struct GameStatePacket *packet;
    struct DodrioGame_Berries *berries = &player->berries;

    if ((gRecvCmds[0][0] & RFUCMD_MASK) != RFUCMD_SEND_PACKET)
        return FALSE;

    packet = (void *)&gRecvCmds[0][1];
    if (packet->id == PACKET_GAME_STATE)
    {
        berries->fallDist[0] = packet->fallDist_Col0;
        berries->fallDist[1] = packet->fallDist_Col1;
        berries->fallDist[2] = packet->fallDist_Col2;
        berries->fallDist[3] = packet->fallDist_Col3;
        berries->fallDist[4] = packet->fallDist_Col4;
        berries->fallDist[5] = packet->fallDist_Col5;
        berries->fallDist[6] = packet->fallDist_Col6;
        berries->fallDist[7] = packet->fallDist_Col7;
        berries->fallDist[8] = packet->fallDist_Col8;
        berries->fallDist[9] = packet->fallDist_Col9;
        berries->fallDist[10] = packet->fallDist_Col0;

        berries->ids[0] = packet->berryId_Col0;
        berries->ids[1] = packet->berryId_Col1;
        berries->ids[2] = packet->berryId_Col2;
        berries->ids[3] = packet->berryId_Col3;
        berries->ids[4] = packet->berryId_Col4;
        berries->ids[5] = packet->berryId_Col5;
        berries->ids[6] = packet->berryId_Col6;
        berries->ids[7] = packet->berryId_Col7;
        berries->ids[8] = packet->berryId_Col8;
        berries->ids[9] = packet->berryId_Col9;
        berries->ids[10] = packet->berryId_Col0;

        player1->pickState = packet->pickState_Player1;
        player1->ateBerry = packet->ateBerry_Player1;
        player1->missedBerry = packet->missedBerry_Player1;

        player2->pickState = packet->pickState_Player2;
        player2->ateBerry = packet->ateBerry_Player2;
        player2->missedBerry = packet->missedBerry_Player2;

        player3->pickState = packet->pickState_Player3;
        player3->ateBerry = packet->ateBerry_Player3;
        player3->missedBerry = packet->missedBerry_Player3;

        player4->pickState = packet->pickState_Player4;
        player4->ateBerry = packet->ateBerry_Player4;
        player4->missedBerry = packet->missedBerry_Player4;

        player5->pickState = packet->pickState_Player5;
        player5->ateBerry = packet->ateBerry_Player5;
        player5->missedBerry = packet->missedBerry_Player5;

        *numGraySquares = packet->numGraySquares;
        *berriesFalling = packet->berriesFalling;
        *allReadyToEnd = packet->allReadyToEnd;
        return TRUE;
    }

    return FALSE;
}

void CheckDodrioInParty(void)
{
    int i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData2(&gPlayerParty[i], MON_DATA_SANITY_HAS_SPECIES) != 0
            && GetMonData2(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_DODRIO)
        {
            gSpecialVar_Result = 1;
            return;
        }
    }
    gSpecialVar_Result = 0;
}

void ShowDodrioRecords(void)
{
    u8 taskId = CreateTask(Task_ShowDodrioRecords, 0);
    Task_ShowDodrioRecords(taskId);
}

void Task_ShowDodrioRecords(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (data[0])
    {
    case 0:
        data[1] = AddWindow(&sRecordsWindowTemplate);
        sub_0802792C(data[1]);
        CopyWindowToVram(data[1], 3);
        data[0]++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
            data[0]++;
        break;
    case 2:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            rbox_fill_rectangle(data[1]);
            CopyWindowToVram(data[1], 1);
            data[0]++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            RemoveWindow(data[1]);
            DestroyTask(taskId);
            ScriptContext_Enable();
        }
        break;
    }
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
        if (AllLinkBlocksReceived())
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
        if (AllLinkBlocksReceived())
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
        if (AllLinkBlocksReceived())
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

void AskPlayAgain(void)
{
    u8 playAgainState;
    u8 i;

    switch (sGame->state)
    {
    case 0:
        if (GetHighestScore() >= PRIZE_SCORE)
        {
            SetGfxFuncById(GFXFUNC_MSG_SAVING);
        }
        sGame->state++;
        break;
    case 1:
        if (!IsGfxFuncActive())
        {
            SetGfxFuncById(GFXFUNC_MSG_PLAY_AGAIN);
            sGame->state++;
        }
        break;
    case 2:
        ResetBerryAndStatusBarSprites();
        ResetForPlayAgainPrompt();
        sGame->state++;
        break;
    case 3:
        if ((playAgainState = GetPlayAgainState()) != PLAY_AGAIN_NONE)
        {
            sGame->state++;
        }
        break;
    case 4:
        if (!IsGfxFuncActive())
        {
            SetGfxFuncById(GFXFUNC_MSG_COMM_STANDBY);
            sGame->state++;
        }
        break;
    case 5:
        playAgainState = GetPlayAgainState();
        if (SendBlock(0, &playAgainState, sizeof(playAgainState)))
        {
            sGame->playersReceived = 0;
            sGame->state++;
        }
        break;
    case 6:
        if (IsLinkTaskFinished())
            sGame->state++;
        break;
    case 7:
        if (AllLinkBlocksReceived())
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
                ResetPickState();
                SetGfxFuncById(GFXFUNC_ERASE_MSG);
                sGame->state++;
            }
        }
        else
        {
            HandleWaitPlayAgainInput();
        }
        break;
    default:
        if (!IsGfxFuncActive())
        {
            for (i = 0; i < sGame->numPlayers; i++)
            {
                if (sGame->playAgainStates[i] == PLAY_AGAIN_NO)
                {
                    SetGameFunc(FUNC_END_LINK);
                    return;
                }
            }
            SetGameFunc(FUNC_RESET_GAME);
        }
        break;
    }
}

void EndLink(void)
{
    switch (sGame->state)
    {
    case 0:
        SetCloseLinkCallback();
        SetGfxFuncById(GFXFUNC_MSG_PLAYER_DROPPED);
        sGame->state++;
        break;
    case 1:
        if (!IsGfxFuncActive())
            sGame->state++;
        break;
    case 2:
        if (GetPlayAgainState() == PLAY_AGAIN_DROPPED)
            sGame->state++;
        break;
    default:
        if (gReceivedRemoteLinkPlayers == 0)
        {
            SetGameFunc(FUNC_EXIT);
        }
        break;
    }
}

void ExitGame(void)
{
    switch (sGame->state)
    {
    case 0:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, 0);
        sGame->state++;
        break;
    case 1:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
            sGame->state++;
        break;
    case 2:
        FreeBerrySprites();
        FreeStatusBar();
        FreeDodrioSprites(sGame->numPlayers);
        FreeCloudSprites();
        sExitingGame = TRUE;
        SetGfxFuncById(GFXFUNC_STOP);
        sGame->state++;
        break;
    default:
        if (!IsGfxFuncActive())
        {
            SetMainCallback2(sGame->exitCallback);
            DestroyTask(sGame->taskId);
            Free(sGame);
            FreeAllWindowBuffers();
        }
        break;
    }
}

void ResetGame_Dodrio(void)
{
    switch (sGame->state)
    {
    case 0:
        SetGfxFuncById(GFXFUNC_IDLE);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, 0);
        sGame->state++;
        break;
    case 1:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            sGame->state++;
        }
        break;
    case 2:
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        sGame->state++;
        break;
    case 3:
        StopMapMusic();
        sGame->state++;
        break;
    case 4:
        PlayNewMapMusic(MUS_RG_BERRY_PICK);
        StartCloudMovement();
        sGame->state++;
        break;
    case 5:
        BlendPalettes(PALETTES_ALL, 16, 0);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, 0);
        sGame->state++;
        break;
    case 6:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
            sGame->state++;
        break;
    default:
        DestroyTask(sGame->taskId);
        CreateDodrioGameTask(Task_NewGameIntro);
        ResetGfxState();
        InitDodrioGame(sGame);
        if (gReceivedRemoteLinkPlayers == 0)
            sGame->numPlayers = 1;

        SetRandomPrize();
        SetCloudInvisibility(FALSE);
        break;
    }
}

void Task_NewGameIntro(u8 taskId)
{
    switch (sGame->state)
    {
    case 0:
        if (SlideTreeBordersOut() == TRUE)
            sGame->state++;
        break;
    case 1:
        InitStatusBarPos();
        sGame->state++;
        break;
    case 2:
        if (DoStatusBarIntro() == TRUE)
            sGame->state++;
        break;
    default:
        if (sGame->isLeader)
            CreateDodrioGameTask(Task_DodrioGame_Leader);
        else
            CreateDodrioGameTask(Task_DodrioGame_Member);

        DestroyTask(taskId);
        break;
    }
}

void Task_CommunicateMonInfo(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 i;

    switch (tState)
    {
    case 0:
        if (SendBlock(0, &sGame->monInfo[sGame->multiplayerId].isShiny, sizeof(sGame->monInfo[sGame->multiplayerId].isShiny)))
        {
            sGame->playersReceived = 0;
            tState++;
        }
        break;
    case 1:
        if (IsLinkTaskFinished())
            tState++;
        break;
    case 2:
        if (AllLinkBlocksReceived())
        {
            for (i = 0; i < sGame->numPlayers; i++)
            {
                *(u8 *)&sGame->monInfo[i] = *(u8 *)gBlockRecvBuffer[i];
                sGame->playersReceived = sGame->numPlayers;
            }
        }
        if (sGame->playersReceived >= sGame->numPlayers)
        {
            DestroyTask(taskId);
            SetGfxFuncById(GFXFUNC_ERASE_MSG);
            sGame->state++;
        }
        break;
    }
}

void RecvLinkData_Gameplay(void)
{
    u8 i;
    u8 numPlayers = sGame->numPlayers;

    sGame->players[0].receivedGameStatePacket = RecvPacket_GameState(0,
                                                  &sGame->players[0],
                                                  &sGame->players[0].comm,
                                                  &sGame->players[1].comm,
                                                  &sGame->players[2].comm,
                                                  &sGame->players[3].comm,
                                                  &sGame->players[4].comm,
                                                  &sGame->numGraySquares,
                                                  &sGame->berriesFalling,
                                                  &sGame->allReadyToEnd);
    sGame->clearRecvCmds = TRUE;

    for (i = 1; i < numPlayers; i++)
    {
        if (sGame->inputState[i] == INPUTSTATE_NONE && !RecvPacket_PickState(i, &sGame->players[i].comm.pickState))
        {
            sGame->players[i].comm.pickState = PICK_NONE;
            sGame->clearRecvCmds = FALSE;
        }
    }
    if (++sGame->clearRecvCmdTimer >= 60)
    {
        if (sGame->clearRecvCmds)
        {
            ClearRecvCommands();
            sGame->clearRecvCmdTimer = 0;
        }
        else if (sGame->clearRecvCmdTimer > 70)
        {
            ClearRecvCommands();
            sGame->clearRecvCmdTimer = 0;
        }
    }

    for (i = 0; i < numPlayers; i++)
    {
        if (sGame->players[i].comm.pickState != PICK_NONE && sGame->inputState[i] == INPUTSTATE_NONE)
        {
            sGame->inputState[i] = INPUTSTATE_TRY_PICK;
        }
        switch (sGame->inputState[i])
        {
        case INPUTSTATE_NONE:
        default:
            break;
        case INPUTSTATE_TRY_PICK:
        case INPUTSTATE_PICKED:
        case INPUTSTATE_ATE_BERRY:
            if (++sGame->inputDelay[i] >= 6)
            {
                sGame->inputDelay[i] = 0;
                sGame->inputState[i] = INPUTSTATE_NONE;
                sGame->players[i].comm.pickState = PICK_NONE;
                sGame->players[i].comm.ateBerry = FALSE;
                sGame->players[i].comm.missedBerry = FALSE;
            }
            break;
        case INPUTSTATE_BAD_MISS:
            // Tried to pick with no berry in range, long delay until next input
            if (++sGame->inputDelay[i] >= 40)
            {
                sGame->inputDelay[i] = 0;
                sGame->inputState[i] = INPUTSTATE_NONE;
                sGame->players[i].comm.pickState = PICK_NONE;
                sGame->players[i].comm.ateBerry = FALSE;
                sGame->players[i].comm.missedBerry = FALSE;
            }
            break;
        }
    }
}

void RecvLinkData_ReadyToEnd(void)
{
    u8 i;
    u8 numPlayers = sGame->numPlayers;

    sGame->players[0].receivedGameStatePacket = RecvPacket_GameState(0,
                                                  &sGame->players[0],
                                                  &sGame->players[0].comm,
                                                  &sGame->players[1].comm,
                                                  &sGame->players[2].comm,
                                                  &sGame->players[3].comm,
                                                  &sGame->players[4].comm,
                                                  &sGame->numGraySquares,
                                                  &sGame->berriesFalling,
                                                  &sGame->allReadyToEnd);
    sGame->clearRecvCmds = TRUE;

    for (i = 1; i < numPlayers; i++)
    {
        if (RecvPacket_ReadyToEnd(i))
        {
            sGame->readyToEnd[i] = TRUE;
            sGame->clearRecvCmds = FALSE;
        }
    }
    if (++sGame->clearRecvCmdTimer >= 60)
    {
        if (sGame->clearRecvCmds)
        {
            ClearRecvCommands();
            sGame->clearRecvCmdTimer = 0;
        }
        else if (sGame->clearRecvCmdTimer > 70)
        {
            ClearRecvCommands();
            sGame->clearRecvCmdTimer = 0;
        }
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
