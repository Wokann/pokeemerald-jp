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
#include "text.h"
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

enum {
    STATUS_YELLOW,
    STATUS_GRAY,
    STATUS_RED,
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

struct GfxFunc
{
    u8 id;
    void (*func)(void);
};

#define NUM_GFX_FUNCS 10

struct WinCoords
{
    u8 left;
    u8 top;
};

enum
{
    COLORID_GRAY,
    COLORID_RED,
    COLORID_BLUE,
    COLORID_GREEN,
};

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
extern void Task_TryRunGfxFunc(u8 taskId);
extern void LoadGfx(void);
extern void SetGfxFunc(void (*func)(void));
extern void (*GetGfxFunc(void))(void);
extern void InitBgs(void);
extern bool32 LoadBgGfx(void);
extern void FreeAllWindowBuffers_(void);
extern const struct GfxFunc sGfxFuncs[];
extern const u16 sDodrioBg_Tilemap[];
extern const u16 sTreeBorderLeft_Tilemap[];
extern const u16 sTreeBorderRight_Tilemap[];
extern const u8 sDodrioTextColorTable[][3];
extern const struct WinCoords *const sNameWindowCoords[];
extern const u8 *const sRankingTexts[];
extern const u16 sRankingYCoords[];
extern const u8 sRankingOrder[];
extern const struct WindowTemplate sWindowTemplates_PlayAgain[];
extern const struct WindowTemplate sWindowTemplate_CommStandby;
extern const struct WindowTemplate sWindowTemplate_DroppedOut;
extern const u8 sBg_Pal[];
extern const u8 sBg_Gfx[];
extern const u8 sTreeBorder_Gfx[];
extern const u8 sTreeBorderXPos[];
extern const u8 sDodrioHeadToColumnMap[MAX_RFU_PLAYERS][MAX_RFU_PLAYERS][3];
extern const u8 sBerryFallDelays[][3];
extern bool32 IsGfxFuncActive(void);
extern void CreateDodrioSprite(struct DodrioGame_MonInfo *, u8, u8, u8);
extern void LoadBerryGfx_Dodrio(void);
#define LoadBerryGfx LoadBerryGfx_Dodrio
extern void CreateBerrySprites_Dodrio(void);
#define CreateBerrySprites CreateBerrySprites_Dodrio
extern void CreateCloudSprites_Dodrio(void);
#define CreateCloudSprites CreateCloudSprites_Dodrio
extern void CreateDodrioGameTask(TaskFunc func);
extern void (*const sLeaderFuncs[])(void);
extern void (*const sMemberFuncs[])(void);
static void RecvLinkData_Leader(void);
void sub_0802792C(u8 windowId);
static void RecvLinkData_Member(void);
extern void UpdateGame_Leader(void);
extern void UpdateGame_Member(void);
static void SendLinkData_Leader(void);
static void SendLinkData_Member(void);
extern void SetGfxFuncById(u8);
extern void SetGameFunc(u8);
extern void InitFirstWaveOfBerries(void);
extern void UpdateFallingBerries(void);
extern void HandleSound_Leader(void);
extern void HandleSound_Member(void);
extern bool32 ReadyToEndGame_Leader(void);
extern bool32 ReadyToEndGame_Member(void);
extern u32 sub_08027480(u8 playerId); // GetScore
extern u8 GetPlayAgainState(void);
extern void UpdateBerrySprites(void);
extern void sub_08026848(void); // UpdateAllDodrioAnims
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
extern const u32 sStatus_Gfx[];
extern const struct SpritePalette sStatusPalette;
extern const struct SpriteTemplate sStatusSpriteTemplate;
extern const u32 sBerry_Gfx[];
extern const struct SpritePalette sBerryPalette;
extern const s16 sBerryIconXCoords[NUM_BERRY_TYPES];
extern const struct SpriteTemplate sBerrySpriteTemplate;
extern const struct SpriteTemplate sBerryIconSpriteTemplate;
extern const u32 sCloud_Gfx[];
extern const struct SpritePalette sCloudPalette;
extern const struct SpriteTemplate sCloudSpriteTemplate;
extern const s16 sCloudPositions[NUM_CLOUDS][2];
extern EWRAM_DATA u16 *sBerrySpriteIds[NUM_BERRY_COLUMNS];
extern EWRAM_DATA u16 *sBerryIconSpriteIds[NUM_BERRY_TYPES];
extern EWRAM_DATA u16 *sCloudSpriteIds[NUM_CLOUDS];
extern EWRAM_DATA struct DodrioGame_Gfx *sGfx;
extern const struct OamData sOamData_Dodrio;
extern const union AnimCmd *const sAnims_Dodrio[];
extern const union AffineAnimCmd *const gDummySpriteAffineAnimTable[];
extern EWRAM_DATA u16 *sDodrioSpriteIds[MAX_RFU_PLAYERS];
extern EWRAM_DATA struct StatusBar *sStatusBar;
extern void sub_08028268(struct Sprite *sprite); // DoDodrioMissedAnim
extern void sub_080282D8(struct Sprite *sprite); // DoDodrioIntroAnim
extern const struct WindowTemplate sRecordsWindowTemplate;
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
static void DoGameIntro(void);
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
void DrawMessageWindow(const struct WindowTemplate *template);
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
static void ExitGame(void);
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

static void DoGameIntro(void)
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
    UpdateBerrySprites();
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
    *sDodrioSpriteIds[id] = CreateSprite(&template, GetDodrioXPos(playerId, numPlayers), 136, 3);
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

void CreateStatusBarSprites(void)
{
    u8 i;
    void *ptr = AllocZeroed(0x180);
    struct SpritePalette pal = sStatusPalette;

    LZ77UnCompWram(sStatus_Gfx, ptr);
    if (ptr)
    {
        struct SpriteSheet sheet = {ptr, 0x180, GFXTAG_STATUS};
        struct SpriteTemplate template = sStatusSpriteTemplate;

        sStatusBar = AllocZeroed(sizeof(*sStatusBar));
        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&pal);
        for (i = 0; i < NUM_STATUS_SQUARES; i++)
            sStatusBar->spriteIds[i] = CreateSprite(&template, (i * 16) + 48, -8 - (i * 8), 0);
    }
    Free(ptr);
}

void FreeStatusBar(void)
{
    u8 i;
    for (i = 0; i < NUM_STATUS_SQUARES; i++)
    {
        struct Sprite *sprite = &gSprites[sStatusBar->spriteIds[i]];
        if (sprite)
            DestroySpriteAndFreeResources(sprite);
    }
    Free(sStatusBar);
    sStatusBar = NULL;
}

bool32 DoStatusBarIntro(void)
{
    u8 i;
    bool32 animActive = FALSE;
    for (i = 0; i < NUM_STATUS_SQUARES; i++)
    {
        struct Sprite *sprite = &gSprites[sStatusBar->spriteIds[i]];
        sStatusBar->yChange[i] = 2;
        if (sStatusBar->entered[i] && sprite->y == 8)
            continue;

        animActive = TRUE;
        if (sprite->y == 8)
        {
            if (sStatusBar->entered[i])
                continue;

            // Square has entered screen, play click
            // sound and reverse direction
            sStatusBar->entered[i] = TRUE;
            sStatusBar->yChange[i] = -16;
            PlaySE(SE_CLICK);
        }
        sprite->y += sStatusBar->yChange[i];
    }

    if (animActive)
        return FALSE;
    else
        return TRUE;
}

void UpdateStatusBarAnim(u8 numEmpty)
{
    u8 i;

    if (numEmpty > NUM_STATUS_SQUARES)
    {
        // All squares gray
        for (i = 0; i < NUM_STATUS_SQUARES; i++)
            StartSpriteAnim(&gSprites[sStatusBar->spriteIds[i]], STATUS_GRAY);
    }
    else
    {
        // At least 1 square is yellow
        for (i = 0; i < NUM_STATUS_SQUARES - numEmpty; i++)
        {
            if (numEmpty > 6)
            {
                // Flash the yellow squares red
                // The flash cycles faster the fewer yellow squares remain
                sStatusBar->flashTimer += numEmpty - 6;
                if (sStatusBar->flashTimer > 30)
                    sStatusBar->flashTimer = 0;
                else if (sStatusBar->flashTimer > 10)
                    StartSpriteAnim(&gSprites[sStatusBar->spriteIds[i]], STATUS_RED);
                else
                    StartSpriteAnim(&gSprites[sStatusBar->spriteIds[i]], STATUS_YELLOW);
            }
            else
            {
                // Set yellow squares, no flash
                StartSpriteAnim(&gSprites[sStatusBar->spriteIds[i]], STATUS_YELLOW);
            }
        }

        // Set remaining squares gray
        for (; i < NUM_STATUS_SQUARES; i++)
            StartSpriteAnim(&gSprites[sStatusBar->spriteIds[i]], STATUS_GRAY);
    }
}

void SetStatusBarInvisibility(bool8 invisible)
{
    u8 i;
    for (i = 0; i < NUM_STATUS_SQUARES; i++)
        gSprites[sStatusBar->spriteIds[i]].invisible = invisible;
}

void LoadBerryGfx_Dodrio(void)
{
    void *ptr = AllocZeroed(0x480);
    struct SpritePalette pal = sBerryPalette;

    LZ77UnCompWram(sBerry_Gfx, ptr);
    if (ptr)
    {
        struct SpriteSheet sheet = {ptr, 0x480, GFXTAG_BERRIES};
        LoadSpriteSheet(&sheet);
    }
    LoadSpritePalette(&pal);
    Free(ptr);
}

void CreateBerrySprites_Dodrio(void)
{
    u8 i;
    s16 x;

    struct SpriteTemplate berry = sBerrySpriteTemplate;
    struct SpriteTemplate berryIcon = sBerryIconSpriteTemplate;

    // Create berry sprites that fall during gameplay
    for (i = 0; i < NUM_BERRY_COLUMNS; i++)
    {
        sBerrySpriteIds[i] = AllocZeroed(4);
        x = i * 16;
        *sBerrySpriteIds[i] = CreateSprite(&berry, x + (i * 8), 8, 1);
        SetBerryInvisibility(i, TRUE);
    }

    // Create berry icon sprites for results screen
    for (i = 0; i < NUM_BERRY_TYPES; i++)
    {
        sBerryIconSpriteIds[i] = AllocZeroed(4);
        if (i == BERRY_MISSED)
            *sBerryIconSpriteIds[i] = CreateSprite(&berryIcon, sBerryIconXCoords[i], 57, 0);
        else
            *sBerryIconSpriteIds[i] = CreateSprite(&berryIcon, sBerryIconXCoords[i], 60, 0);
        StartSpriteAnim(&gSprites[*sBerryIconSpriteIds[i]], i);
    }
    SetBerryIconsInvisibility(TRUE);
}

void FreeBerrySprites(void)
{
    struct Sprite *sprite;
    u8 i;

    for (i = 0; i < NUM_BERRY_COLUMNS; i++)
    {
        sprite = &gSprites[*sBerrySpriteIds[i]];
        if (sprite)
            DestroySprite(sprite);
        FREE_AND_SET_NULL(sBerrySpriteIds[i]);
    }
    for (i = 0; i < NUM_BERRY_TYPES; i++)
    {
        sprite = &gSprites[*sBerryIconSpriteIds[i]];
        if (sprite)
            DestroySprite(sprite);
        FREE_AND_SET_NULL(sBerryIconSpriteIds[i]);
    }
}

void SetBerryInvisibility(u8 id, bool8 invisible)
{
    gSprites[*sBerrySpriteIds[id]].invisible = invisible;
}

void SetBerryIconsInvisibility(bool8 invisible)
{
    u8 i;
    for (i = 0; i < NUM_BERRY_TYPES; i++)
        gSprites[*sBerryIconSpriteIds[i]].invisible = invisible;
}

void SetBerryYPos(u8 id, u8 y)
{
    gSprites[*sBerrySpriteIds[id]].y = y * 8;
}

void SetBerryAnim(u16 id, u8 animNum)
{
    StartSpriteAnim(&gSprites[*sBerrySpriteIds[id]], animNum);
}

void SetSpritePos(u8 spriteId)
{
    gSprites[spriteId].x = spriteId * 20 + 50;
    gSprites[spriteId].y = 50;
}

void CreateCloudSprites_Dodrio(void)
{
    u8 i;
    void *ptr = AllocZeroed(0x400);
    struct SpritePalette pal = sCloudPalette;

    LZ77UnCompWram(sCloud_Gfx, ptr);
    if (ptr)
    {
        struct SpriteSheet sheet = {ptr, 0x400, GFXTAG_CLOUD};
        struct SpriteTemplate template = sCloudSpriteTemplate;

        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&pal);
        for (i = 0; i < NUM_CLOUDS; i++)
        {
            sCloudSpriteIds[i] = AllocZeroed(4);
            *sCloudSpriteIds[i] = CreateSprite(&template, sCloudPositions[i][0], sCloudPositions[i][1], 4);
        }
    }
    Free(ptr);
}

void ResetCloudPos(void)
{
    u8 i;
    for (i = 0; i < NUM_CLOUDS; i++)
    {
        struct Sprite *sprite = &gSprites[*sCloudSpriteIds[i]];
        sprite->data[10] = 1;
        sprite->x = sCloudPositions[i][0];
        sprite->y = sCloudPositions[i][1];
    }
}

void StartCloudMovement(void)
{
    u8 i;
    for (i = 0; i < NUM_CLOUDS; i++)
    {
        u16 spriteId = *sCloudSpriteIds[i];
        gSprites[spriteId].data[10] = 0;
    }
}

void FreeCloudSprites(void)
{
    u8 i;
    for (i = 0; i < NUM_CLOUDS; i++)
    {
        struct Sprite *sprite = &gSprites[*sCloudSpriteIds[i]];
        if (sprite)
            DestroySprite(sprite);
        FREE_AND_SET_NULL(sCloudSpriteIds[i]);
    }
}

void SetCloudInvisibility(bool8 invisible)
{
    u8 i;
    for (i = 0; i < NUM_CLOUDS; i++)
        gSprites[*sCloudSpriteIds[i]].invisible = invisible;
}

s16 GetDodrioXPos(u8 playerId, u8 numPlayers)
{
    s16 x = 0;
    switch (numPlayers)
    {
    case 1:
        x = 15;
        break;
    case 2:
        switch (playerId)
        {
            case 0: x = 12; break;
            case 1: x = 18; break;
        }
        break;
    case 3:
        switch (playerId)
        {
            case 0: x = 15; break;
            case 1: x = 21; break;
            case 2: x =  9; break;
        }
        break;
    case 4:
        switch (playerId)
        {
            case 0: x = 12; break;
            case 1: x = 18; break;
            case 2: x = 24; break;
            case 3: x =  6; break;
        }
        break;
    case 5:
        switch (playerId)
        {
            case 0: x = 15; break;
            case 1: x = 21; break;
            case 2: x = 27; break;
            case 3: x =  3; break;
            case 4: x =  9; break;
        }
        break;
    }

    return x * 8;
}

void ResetBerryAndStatusBarSprites(void)
{
    u8 i;
    for (i = 0; i < NUM_BERRY_COLUMNS; i++)
    {
        SetBerryInvisibility(i, TRUE);
        SetBerryYPos(i, 1);
    }
    SetStatusBarInvisibility(FALSE);
}

void LoadWindowFrameGfx(u8 windowId)
{
    LoadBgTiles(0, GetWindowFrameTilesPal(windowId)->tiles, 0x120, 1);
    LoadPalette(GetWindowFrameTilesPal(windowId)->pal, 0xa0, 0x20);
}

void nullsub_16(void)
{
    LoadUserWindowBorderGfx_(0, 10, 0xB0);
}

void ResetGfxState(void)
{
    sGfx->finished = FALSE;
    sGfx->state = 0;
    sGfx->loadState = 0;
    sGfx->cursorSelection = 0;
    sGfx->playAgainState = PLAY_AGAIN_NONE;
}

void DrawYesNoMessageWindow(const struct WindowTemplate *template)
{
    u8 pal = 10;

    FillBgTilemapBufferRect(0, 1, template->tilemapLeft - 1,                template->tilemapTop - 1,                   1, 1, pal);
    FillBgTilemapBufferRect(0, 2, template->tilemapLeft,                    template->tilemapTop - 1,                   template->width, 1, pal);
    FillBgTilemapBufferRect(0, 3, template->tilemapLeft + template->width,  template->tilemapTop - 1,                   1, 1, pal);
    FillBgTilemapBufferRect(0, 4, template->tilemapLeft - 1,                template->tilemapTop, 1,                    template->height, pal);
    FillBgTilemapBufferRect(0, 6, template->tilemapLeft + template->width,  template->tilemapTop, 1,                    template->height, pal);
    FillBgTilemapBufferRect(0, 7, template->tilemapLeft - 1,                template->tilemapTop + template->height,    1, 1, pal);
    FillBgTilemapBufferRect(0, 8, template->tilemapLeft,                    template->tilemapTop + template->height,    template->width, 1, pal);
    FillBgTilemapBufferRect(0, 9, template->tilemapLeft + template->width,  template->tilemapTop + template->height,    1, 1, pal);
}

void DrawMessageWindow(const struct WindowTemplate *template)
{
    u8 pal = 11;

    FillBgTilemapBufferRect(0, 10, template->tilemapLeft - 1,                template->tilemapTop - 1,                   1, 1, pal);
    FillBgTilemapBufferRect(0, 11, template->tilemapLeft,                    template->tilemapTop - 1,                   template->width, 1, pal);
    FillBgTilemapBufferRect(0, 12, template->tilemapLeft + template->width,  template->tilemapTop - 1,                   1, 1, pal);
    FillBgTilemapBufferRect(0, 13, template->tilemapLeft - 1,                template->tilemapTop, 1,                    template->height, pal);
    FillBgTilemapBufferRect(0, 15, template->tilemapLeft + template->width,  template->tilemapTop, 1,                    template->height, pal);
    FillBgTilemapBufferRect(0, 16, template->tilemapLeft - 1,                template->tilemapTop + template->height,    1, 1, pal);
    FillBgTilemapBufferRect(0, 17, template->tilemapLeft,                    template->tilemapTop + template->height,    template->width, 1, pal);
    FillBgTilemapBufferRect(0, 18, template->tilemapLeft + template->width,  template->tilemapTop + template->height,    1, 1, pal);
}

void InitGameGfx(struct DodrioGame_Gfx *ptr)
{
    sGfx = ptr;
    sGfx->finished = FALSE;
    sGfx->state = 0;
    sGfx->loadState = 0;
    sGfx->cursorSelection = 0;
    sGfx->playAgainState = PLAY_AGAIN_NONE;
    sGfx->taskId = CreateTask(Task_TryRunGfxFunc, 3);
    SetGfxFunc(LoadGfx);
}

void FreeAllWindowBuffers_(void)
{
    FreeAllWindowBuffers();
}

void SetGfxFuncById(u8 funcId)
{
    u8 i;

    for (i = 0; i < NUM_GFX_FUNCS; i++)
    {
        if (sGfxFuncs[i].id == funcId)
            SetGfxFunc(sGfxFuncs[i].func);
    }
}

void Task_TryRunGfxFunc(u8 taskId)
{
    if (!sGfx->finished)
        GetGfxFunc()();
}

void LoadGfx(void)
{
    switch (sGfx->state)
    {
    case 0:
        InitBgs();
        sGfx->state++;
        break;
    case 1:
        if (LoadBgGfx() == TRUE)
            sGfx->state++;
        break;
    case 2:
        CopyToBgTilemapBuffer(3, sDodrioBg_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(1, sTreeBorderLeft_Tilemap, 0, 0);
        CopyToBgTilemapBuffer(2, sTreeBorderRight_Tilemap, 0, 0);
        CopyBgTilemapBufferToVram(3);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        sGfx->state++;
        break;
    case 3:
        ShowBg(0);
        ShowBg(3);
        ShowBg(1);
        ShowBg(2);
        sGfx->state++;
        break;
    case 4:
        LoadWindowFrameGfx(gSaveBlock2Ptr->optionsWindowFrameType);
        nullsub_16();
        sGfx->state++;
        break;
    default:
        sGfx->finished = TRUE;
        break;
    }
}

void ShowNames(void)
{
    u8 i, numPlayers, playerId, colorsId, *name;
    u32 left;
    struct WindowTemplate window;
    const struct WinCoords *coords;

    switch (sGfx->state)
    {
    case 0:
        numPlayers = GetNumPlayers();
        coords = sNameWindowCoords[numPlayers - 1];
        window.bg = 0;
        window.width = 7;
        window.height = 2;
        window.paletteNum = 13;
        window.baseBlock = 0x13;
        for (i = 0; i < numPlayers; coords++, i++)
        {
            colorsId = COLORID_GRAY;
            playerId = GetPlayerIdByPos(i);
            left = (56 - GetStringWidth(0, GetPlayerName(playerId), -1)) / 2u; // JP uses font id 0 here
            window.tilemapLeft = coords->left;
            window.tilemapTop = coords->top;
            sGfx->windowIds[i] = AddWindow(&window);
            ClearWindowTilemap(sGfx->windowIds[i]);
            FillWindowPixelBuffer(sGfx->windowIds[i], PIXEL_FILL(1));
            if (playerId == GetMultiplayerId())
                colorsId = COLORID_BLUE;
            name = GetPlayerName(playerId);
            AddTextPrinterParameterized3(sGfx->windowIds[i], 0, (u8)left, 1, sDodrioTextColorTable[colorsId], -1, name); // JP uses font id 0 here
            CopyWindowToVram(sGfx->windowIds[i], COPYWIN_GFX);
            window.baseBlock += 0xE;
            DrawMessageWindow(&window);
        }
        sGfx->state++;
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            numPlayers = GetNumPlayers();
            for (i = 0; i < numPlayers; i++)
                PutWindowTilemap(sGfx->windowIds[i]);
            CopyBgTilemapBufferToVram(0);
            sGfx->state++;
        }
        break;
    default:
        if (++sGfx->state > 180)
        {
            numPlayers = GetNumPlayers();
            for (i = 0; i < numPlayers; i++)
            {
                ClearWindowTilemap(sGfx->windowIds[i]);
                RemoveWindow(sGfx->windowIds[i]);
            }
            FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x1E, 0x14);
            CopyBgTilemapBufferToVram(0);
            sGfx->finished = TRUE;
        }
        break;
    }
}

void PrintRankedScores(u8 numPlayers_)
{
    u8 i, ranking = 0, rankedPlayers = 0;
    u8 numPlayers = numPlayers_; // Needed to match
    u8 *name;
    u32 numWidth;
    u8 numString[32];
    u8 playersByRanking[MAX_RFU_PLAYERS];
    struct DodrioGame_ScoreResults temp, scoreResults[MAX_RFU_PLAYERS];

    memcpy(playersByRanking, sRankingOrder, MAX_RFU_PLAYERS); // JP copies the initial order from ROM

    // Get all players scores and rankings
    for (i = 0; i < numPlayers; i++)
    {
        playersByRanking[i] = i;
        GetScoreResults(&temp, i);
        scoreResults[i] = temp;
    }

    // Sort player ids by ranking
    if (GetHighestScore() != 0)
    {
        do
        {
            for (i = 0; i < numPlayers; i++)
            {
                if (scoreResults[i].ranking == ranking)
                {
                    playersByRanking[rankedPlayers] = i;
                    rankedPlayers++;
                }
            }
            ranking = rankedPlayers;
        } while (rankedPlayers < numPlayers);
    }

    // Put any player with a score of 0 at lowest ranking
    for (i = 0; i < numPlayers; i++)
    {
        if (scoreResults[i].score == 0)
            scoreResults[i].ranking = numPlayers - 1;
    }

    // Print text
    for (i = 0; i < numPlayers; i++)
    {
        u8 colorsId = COLORID_GRAY;
        u8 playerId = playersByRanking[i];
        u32 points = scoreResults[playerId].score;
        u8 y;
        const u16 *yp;

        AddTextPrinterParameterized(sGfx->windowIds[1], 0, sRankingTexts[scoreResults[playerId].ranking], 8, (y = *(const u8 *)(yp = &sRankingYCoords[0], yp + i)), TEXT_SKIP_DRAW, NULL); // JP reads the low byte of the u16 table
        if (playerId == GetMultiplayerId())
            colorsId = COLORID_BLUE;
        name = GetPlayerName(playerId);
        AddTextPrinterParameterized3(sGfx->windowIds[1], 0, 28, y, sDodrioTextColorTable[colorsId], -1, name); // JP uses font id 0
        ConvertIntToDecimalStringN(numString, points, STR_CONV_MODE_LEFT_ALIGN, 7);
        numWidth = GetStringWidth(0, numString, -1); // JP uses font id 0
        AddTextPrinterParameterized(sGfx->windowIds[1], 0, numString, (u8)(145 - numWidth), y, TEXT_SKIP_DRAW, NULL); // JP fixed x
        AddTextPrinterParameterized(sGfx->windowIds[1], 0, gText_SpacePoints, 155, y, TEXT_SKIP_DRAW, NULL); // JP fixed x
    }
}

void Msg_WantToPlayAgain(void)
{
    u8 y;

    switch (sGfx->state)
    {
    case 0:
        sGfx->windowIds[0] = AddWindow(&sWindowTemplates_PlayAgain[0]);
        sGfx->windowIds[1] = AddWindow(&sWindowTemplates_PlayAgain[1]);
        ClearWindowTilemap(sGfx->windowIds[0]);
        ClearWindowTilemap(sGfx->windowIds[1]);
        DrawMessageWindow(&sWindowTemplates_PlayAgain[0]);
        DrawYesNoMessageWindow(&sWindowTemplates_PlayAgain[1]);
        sGfx->state++;
        sGfx->cursorSelection = PLAY_AGAIN_NONE;
        sGfx->playAgainState = PLAY_AGAIN_NONE;
        break;
    case 1:
        FillWindowPixelBuffer(sGfx->windowIds[0], PIXEL_FILL(1));
        FillWindowPixelBuffer(sGfx->windowIds[1], PIXEL_FILL(1));
        AddTextPrinterParameterized(sGfx->windowIds[0], FONT_NORMAL, gText_WantToPlayAgain, 8, 6, TEXT_SKIP_DRAW, NULL); // JP x=8 y=6
        AddTextPrinterParameterized(sGfx->windowIds[1], FONT_NORMAL, gText_Yes, 12, 2, TEXT_SKIP_DRAW, NULL); // JP x=12 y=2
        AddTextPrinterParameterized(sGfx->windowIds[1], FONT_NORMAL, gText_No, 12, 18, TEXT_SKIP_DRAW, NULL); // JP x=12 y=18
        AddTextPrinterParameterized(sGfx->windowIds[1], FONT_NORMAL, gText_SelectorArrow2, 2, 2, TEXT_SKIP_DRAW, NULL); // JP x=2 y=2
        CopyWindowToVram(sGfx->windowIds[0], COPYWIN_GFX);
        CopyWindowToVram(sGfx->windowIds[1], COPYWIN_GFX);
        sGfx->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            PutWindowTilemap(sGfx->windowIds[0]);
            PutWindowTilemap(sGfx->windowIds[1]);
        }
        CopyBgTilemapBufferToVram(0);
        sGfx->state++;
        break;
    case 3:
        y = sGfx->cursorSelection;
        if (y == PLAY_AGAIN_NONE)
            y = PLAY_AGAIN_YES;
        FillWindowPixelBuffer(sGfx->windowIds[1], PIXEL_FILL(1));
        AddTextPrinterParameterized(sGfx->windowIds[1], FONT_NORMAL, gText_Yes, 12, 2, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(sGfx->windowIds[1], FONT_NORMAL, gText_No, 12, 18, TEXT_SKIP_DRAW, NULL);
        AddTextPrinterParameterized(sGfx->windowIds[1], FONT_NORMAL, gText_SelectorArrow2, 2, ((y - 1) * 16) + 2, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(sGfx->windowIds[1], COPYWIN_FULL);

        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (sGfx->cursorSelection == PLAY_AGAIN_NONE)
                sGfx->cursorSelection = PLAY_AGAIN_YES;
            sGfx->state++;
        }
        else if (JOY_NEW(DPAD_UP | DPAD_DOWN))
        {
            PlaySE(SE_SELECT);
            switch (sGfx->cursorSelection)
            {
            case PLAY_AGAIN_NONE:
                sGfx->cursorSelection = PLAY_AGAIN_NO;
                break;
            case PLAY_AGAIN_YES:
                sGfx->cursorSelection = PLAY_AGAIN_NO;
                break;
            case PLAY_AGAIN_NO:
                sGfx->cursorSelection = PLAY_AGAIN_YES;
                break;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            sGfx->cursorSelection = PLAY_AGAIN_NO;
            sGfx->state++;
        }
        break;
    default:
        sGfx->playAgainState = sGfx->cursorSelection;
        ClearWindowTilemap(sGfx->windowIds[0]);
        ClearWindowTilemap(sGfx->windowIds[1]);
        RemoveWindow(sGfx->windowIds[0]);
        RemoveWindow(sGfx->windowIds[1]);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        sGfx->finished = TRUE;
        break;
    }
}

void Msg_SavingDontTurnOff(void)
{
    switch (sGfx->state)
    {
    case 0:
        DrawDialogueFrame(0, FALSE);
        AddTextPrinterParameterized2(0, FONT_NORMAL, gText_SavingDontTurnOffPower, 0, NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
        sGfx->state++;
        break;
    case 1:
        CopyWindowToVram(0, COPYWIN_FULL);
        sGfx->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CreateTask(Task_LinkFullSave, 0);
            sGfx->state++;
        }
        break;
    case 3:
        if (!FuncIsActiveTask(Task_LinkFullSave))
            sGfx->state++;
        break;
    default:
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        sGfx->finished = TRUE;
        break;
    }
}

void Msg_CommunicationStandby(void)
{
    switch (sGfx->state)
    {
    case 0:
        sGfx->windowIds[0] = AddWindow(&sWindowTemplate_CommStandby);
        ClearWindowTilemap(sGfx->windowIds[0]);
        DrawMessageWindow(&sWindowTemplate_CommStandby);
        sGfx->state++;
        break;
    case 1:
        FillWindowPixelBuffer(sGfx->windowIds[0], PIXEL_FILL(1));
        AddTextPrinterParameterized(sGfx->windowIds[0], FONT_NORMAL, gText_CommunicationStandby3, 4, 6, TEXT_SKIP_DRAW, NULL); // JP x=4 y=6
        CopyWindowToVram(sGfx->windowIds[0], COPYWIN_GFX);
        sGfx->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            PutWindowTilemap(sGfx->windowIds[0]);
        CopyBgTilemapBufferToVram(0);
        sGfx->state++;
        break;
    default:
        sGfx->finished = TRUE;
        break;
    }
}

void EraseMessage(void)
{
    ClearWindowTilemap(sGfx->windowIds[0]);
    RemoveWindow(sGfx->windowIds[0]);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
    CopyBgTilemapBufferToVram(0);
    sGfx->finished = TRUE;
}

void Msg_SomeoneDroppedOut(void)
{
    switch (sGfx->state)
    {
    case 0:
        sGfx->windowIds[0] = AddWindow(&sWindowTemplate_DroppedOut);
        ClearWindowTilemap(sGfx->windowIds[0]);
        DrawMessageWindow(&sWindowTemplate_DroppedOut);
        sGfx->state++;
        sGfx->timer = 0;
        sGfx->cursorSelection = 0;
        sGfx->playAgainState = PLAY_AGAIN_NONE;
        break;
    case 1:
        FillWindowPixelBuffer(sGfx->windowIds[0], PIXEL_FILL(1));
        AddTextPrinterParameterized(sGfx->windowIds[0], FONT_NORMAL, gText_SomeoneDroppedOut, 2, 6, TEXT_SKIP_DRAW, NULL); // JP x=2 y=6
        CopyWindowToVram(sGfx->windowIds[0], COPYWIN_GFX);
        sGfx->state++;
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            PutWindowTilemap(sGfx->windowIds[0]);
        CopyBgTilemapBufferToVram(0);
        sGfx->state++;
        break;
    case 3:
        if (++sGfx->timer >= 120)
            sGfx->state++;
        break;
    default:
        sGfx->playAgainState = PLAY_AGAIN_DROPPED;
        ClearWindowTilemap(sGfx->windowIds[0]);
        RemoveWindow(sGfx->windowIds[0]);
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 30, 20);
        CopyBgTilemapBufferToVram(0);
        sGfx->finished = TRUE;
        break;
    }
}

void StopGfxFuncs(void)
{
    DestroyTask(sGfx->taskId);
    sGfx->finished = TRUE;
}

void GfxIdle(void)
{
}

void SetGfxFunc(void (*func)(void))
{
    sGfx->state = 0;
    sGfx->finished = FALSE;
    sGfx->func = func;
}

void (*GetGfxFunc(void))(void)
{
    return sGfx->func;
}

bool32 IsGfxFuncActive(void)
{
    if (sGfx->finished == TRUE)
        return FALSE;
    else
        return TRUE;
}

u8 GetPlayAgainState(void)
{
    return sGfx->playAgainState;
}

bool32 LoadBgGfx(void)
{
    switch (sGfx->loadState)
    {
    case 0:
        LoadPalette(sBg_Pal, 0, 0x40);
        break;
    case 1:
        ResetTempTileDataBuffers();
        break;
    case 2:
        DecompressAndCopyTileDataToVram(3, sBg_Gfx, 0, 0, 0);
        break;
    case 3:
        DecompressAndCopyTileDataToVram(1, sTreeBorder_Gfx, 0, 0, 0);
        break;
    case 4:
        if ((u8)FreeTempTileDataBuffersIfPossible() == TRUE)
            return FALSE;
        break;
    case 5:
        LoadPalette(GetTextWindowPalette(3), 0xD0, 0x20);
        break;
    default:
        sGfx->loadState = 0;
        return TRUE;
    }
    sGfx->loadState++;
    return FALSE;
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
            sprite->x = GetDodrioXPos(0, GetNumPlayers());
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

static void ExitGame(void)
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

static void RecvLinkData_Leader(void)
{
    switch (sGame->funcId)
    {
    case FUNC_WAIT_START:
        if (AllPlayersReadyToStart() == TRUE)
        {
            ResetReadyToStart();
            sGame->startGame = TRUE;
        }
        break;
    case FUNC_PLAY_GAME:
        RecvLinkData_Gameplay();
        break;
    case FUNC_WAIT_END_GAME:
        RecvLinkData_ReadyToEnd();
        break;
    }
}

static void SendLinkData_Leader(void)
{
    switch (sGame->funcId)
    {
    case FUNC_PLAY_GAME:
        SendPacket_GameState(&sGame->player,
                             &sGame->players[0].comm,
                             &sGame->players[1].comm,
                             &sGame->players[2].comm,
                             &sGame->players[3].comm,
                             &sGame->players[4].comm,
                             sGame->numGraySquares,
                             sGame->berriesFalling,
                             sGame->allReadyToEnd);
        break;
    case FUNC_WAIT_END_GAME:
        SendPacket_GameState(&sGame->player,
                             &sGame->players[0].comm,
                             &sGame->players[1].comm,
                             &sGame->players[2].comm,
                             &sGame->players[3].comm,
                             &sGame->players[4].comm,
                             sGame->numGraySquares,
                             sGame->berriesFalling,
                             sGame->allReadyToEnd);
        break;
    }
}

static void RecvLinkData_Member(void)
{
    switch (sGame->funcId)
    {
    case FUNC_PLAY_GAME:
        RecvPacket_GameState(sGame->multiplayerId,
                             &sGame->players[sGame->multiplayerId],
                             &sGame->players[0].comm,
                             &sGame->players[1].comm,
                             &sGame->players[2].comm,
                             &sGame->players[3].comm,
                             &sGame->players[4].comm,
                             &sGame->numGraySquares,
                             &sGame->berriesFalling,
                             &sGame->allReadyToEnd);
        break;
    case FUNC_WAIT_END_GAME:
        RecvPacket_GameState(sGame->multiplayerId,
                             &sGame->players[sGame->multiplayerId],
                             &sGame->players[0].comm,
                             &sGame->players[1].comm,
                             &sGame->players[2].comm,
                             &sGame->players[3].comm,
                             &sGame->players[4].comm,
                             &sGame->numGraySquares,
                             &sGame->berriesFalling,
                             &sGame->allReadyToEnd);
        break;
    }
}

static void SendLinkData_Member(void)
{
    switch (sGame->funcId)
    {
    case FUNC_WAIT_START:
        SendRfuPacket(1); // JP sends the ready-to-start packet directly
        sGame->startGame = TRUE;
        break;
    case FUNC_PLAY_GAME:
        if (sGame->player.comm.pickState != PICK_NONE)
            SendPacket_PickState(sGame->player.comm.pickState);
        break;
    case FUNC_WAIT_END_GAME:
        if (!sGame->berriesFalling && !sGame->allReadyToEnd)
            SendPacket_ReadyToEnd(TRUE);
        break;
    }
}

void HandleSound_Leader(void)
{
    if (sGame->players[sGame->multiplayerId].comm.pickState == PICK_NONE)
    {
        if (!IsSEPlaying())
            sGame->playingPickSound = FALSE;
    }
    else if (sGame->players[sGame->multiplayerId].comm.ateBerry == TRUE)
    {
        if (!sGame->playingPickSound)
        {
            m4aSongNumStop(SE_SUCCESS);
            PlaySE(SE_SUCCESS);
            sGame->playingPickSound = TRUE;
        }
    }
    else if (sGame->players[sGame->multiplayerId].comm.missedBerry == TRUE)
    {
        if (!sGame->playingPickSound && !IsSEPlaying())
        {
            PlaySE(SE_BOO);
            StartDodrioMissedAnim(1);
            sGame->playingPickSound = TRUE;
        }
    }

    if (sGame->endSoundState == 0 && sGame->numGraySquares >= NUM_STATUS_SQUARES)
    {
        StopMapMusic();
        sGame->endSoundState = 1;
    }
    else if (sGame->endSoundState == 1)
    {
        PlayFanfareByFanfareNum(FANFARE_TOO_BAD);
        sGame->endSoundState = 2;
    }
}

void HandleSound_Member(void)
{
    u8 berryStart = sGame->berryColStart;
    u8 berryEnd = sGame->berryColEnd;
    u8 i;
    if (sGame->players[sGame->multiplayerId].comm.pickState == PICK_NONE)
    {
        if (sGame->players[sGame->multiplayerId].comm.ateBerry != TRUE
         && sGame->players[sGame->multiplayerId].comm.missedBerry != TRUE)
            sGame->playingPickSound = 0;
    }
    else if (sGame->players[sGame->multiplayerId].comm.ateBerry == TRUE)
    {
        if (!sGame->playingPickSound)
        {
            m4aSongNumStop(SE_SUCCESS);
            PlaySE(SE_SUCCESS);
            sGame->playingPickSound = TRUE;
        }
    }
    else if (sGame->players[sGame->multiplayerId].comm.missedBerry == TRUE)
    {
        if (!sGame->playingPickSound && !IsSEPlaying())
        {
            PlaySE(SE_BOO);
            StartDodrioMissedAnim(1);
            sGame->playingPickSound = TRUE;
        }
    }
    for (i = berryStart; i < berryEnd; i++)
    {
        struct DodrioGame_Berries *berries = &sGame->players[sGame->multiplayerId].berries;
        if (berries->fallDist[i] >= MAX_FALL_DIST)
        {
            if (!sGame->playingSquishSound[i])
            {
                PlaySE(SE_BALLOON_RED + berries->ids[i]);
                sGame->playingSquishSound[i] = TRUE;
            }
        }
        else
        {
            sGame->playingSquishSound[i] = FALSE;
        }
    }
    if (sGame->endSoundState == 0 && sGame->numGraySquares >= NUM_STATUS_SQUARES)
    {
        StopMapMusic();
        sGame->endSoundState = 1;
    }
    else if (sGame->endSoundState == 1)
    {
        PlayFanfareByFanfareNum(FANFARE_TOO_BAD);
        sGame->endSoundState = 2;
    }
}

void CB2_DodrioGame(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void VBlankCB_DodrioGame(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
}

void InitMonInfo(struct DodrioGame_MonInfo *monInfo, struct Pokemon *mon)
{
    monInfo->isShiny = IsMonShiny(mon);
}

void CreateTask_(TaskFunc func, u8 priority)
{
    CreateTask(func, priority);
}

void CreateDodrioGameTask(TaskFunc func)
{
    sGame->taskId = CreateTask(func, 1);
    sGame->state = 0;
    sGame->startState = 0;
    sGame->timer = 0;
}

void SetGameFunc(u8 funcId)
{
    sGame->prevFuncId = sGame->funcId;
    sGame->funcId = funcId;
    sGame->state = 0;
    sGame->timer = 0;
}

bool32 SlideTreeBordersOut(void)
{
    u8 x = sGame->timer / 4;
    sGame->timer++;
    if (x != 0 && sGame->timer % 4 == 0)
    {
        if (x < sTreeBorderXPos[sGame->numPlayers - 1])
        {
            SetGpuReg(REG_OFFSET_BG1HOFS, x * 8);
            SetGpuReg(REG_OFFSET_BG2HOFS, (u16)-(x * 8));
            return FALSE;
        }
        else
            return TRUE;
    }
    else
        return FALSE;
}

void InitFirstWaveOfBerries(void)
{
    u8 i;
    u8 berryStart = sGame->berryColStart;
    u8 berryEnd = sGame->berryColEnd;

    for (i = berryStart; i < berryEnd; i++)
    {
        struct DodrioGame_Berries *berries = &sGame->player.berries;
        berries->fallDist[i] = (i % 2 == 0) ? 1 : 0;
        berries->ids[i] = BERRY_BLUE;
    }
}

bool32 TryPickBerry(u8 playerId, u8 pickState, u8 column)
{
    s32 pick = 0;
    u8 numPlayersIdx = sGame->numPlayers - 1;
    struct DodrioGame_Berries *berries = &sGame->player.berries;

    switch (pickState)
    {
    case PICK_LEFT:
    default:
        pick = 0;
        break;
    case PICK_MIDDLE:
        pick = 1;
        break;
    case PICK_RIGHT:
        pick = 2;
        break;
    }

    if (berries->fallDist[column] == EAT_FALL_DIST - 1 || berries->fallDist[column] == EAT_FALL_DIST)
    {
        if (column == sDodrioHeadToColumnMap[numPlayersIdx][playerId][pick])
        {
            if (sGame->berryState[column] == BERRYSTATE_PICKED || sGame->berryState[column] == BERRYSTATE_EATEN)
            {
                sGame->players[playerId].comm.missedBerry = TRUE;
                return FALSE;
            }
            else
                return TRUE;
        }
    }
    else
    {
        if (column == sDodrioHeadToColumnMap[numPlayersIdx][playerId][pick])
        {
            sGame->inputState[playerId] = INPUTSTATE_BAD_MISS;
            sGame->players[playerId].comm.missedBerry = TRUE;
        }
    }
    return FALSE;
}

void HandlePickBerries(void)
{
    u8 berryStart = sGame->berryColStart;
    u8 berryEnd = sGame->berryColEnd;
    u8 numPlayers = sGame->numPlayers;
    u8 i, j, k, column;

    if (sGame->numGraySquares >= NUM_STATUS_SQUARES)
        return;

    for (i = 0; i < numPlayers; i++)
    {
        u8 *pickState = &sGame->players[i].comm.pickState;
        if (*pickState != PICK_NONE && sGame->inputState[i] == INPUTSTATE_TRY_PICK)
        {
            for (j = berryStart; j < berryEnd; j++)
            {
                column = sActiveColumnMap[0][0][j];
                if (sGame->playersAttemptingPick[column][0] == i
                 || sGame->playersAttemptingPick[column][1] == i)
                    break;
                if (TryPickBerry(i, *pickState, column) == TRUE)
                {
                    for (k = 0; k < ARRAY_COUNT(sGame->playersAttemptingPick[0]); k++)
                    {
                        if (sGame->playersAttemptingPick[column][k] == PLAYER_NONE)
                        {
                            sGame->playersAttemptingPick[column][k] = i;
                            sGame->inputState[i] = INPUTSTATE_PICKED;
                            sGame->berryState[column] = BERRYSTATE_PICKED;
                            break;
                        }
                    }
                    break;
                }
                if (sGame->players[i].comm.missedBerry == TRUE)
                    break;
            }
        }
    }

    for (j = berryStart; j < berryEnd; j++)
    {
        u8 playerIdMissed = PLAYER_NONE;
        column = sActiveColumnMap[0][0][j];
        if (sGame->berryState[column] == BERRYSTATE_PICKED)
        {
            s32 delayRemaining;
            u8 playerIdPicked, delayStage = sGame->difficulty[GetPlayerIdAtColumn(column)] / NUM_DIFFICULTIES;
            if (delayStage > 1)
                delayStage = 2;
            delayRemaining = sBerryFallDelays[delayStage][sGame->players[0].berries.ids[column]] - sGame->fallTimer[column];
            if (delayRemaining < 6)
                sGame->eatTimer[column] += delayRemaining;
            if (++sGame->eatTimer[column] >= 6)
            {
                sGame->eatTimer[column] = 0;
                if (sGame->playersAttemptingPick[column][0] == PLAYER_NONE
                 && sGame->playersAttemptingPick[column][1] == PLAYER_NONE)
                {
                    continue;
                }
                else if (sGame->playersAttemptingPick[column][0] != PLAYER_NONE
                      && sGame->playersAttemptingPick[column][1] == PLAYER_NONE)
                {
                    playerIdPicked = sGame->playersAttemptingPick[column][0];
                }
                else
                {
                    u8 playerId1 = sGame->playersAttemptingPick[column][0];
                    i = sGame->playersAttemptingPick[column][1];
                    if (!(Random() & 1))
                    {
                        playerIdPicked = playerId1;
                        playerIdMissed = i;
                    }
                    else
                    {
                        playerIdPicked = i;
                        playerIdMissed = playerId1;
                    }
                }
                sGame->player.berries.fallDist[column] = EAT_FALL_DIST;
                sGame->berryState[column] = BERRYSTATE_EATEN;
                sGame->inputState[playerIdPicked] = INPUTSTATE_ATE_BERRY;
                sGame->berryEatenBy[column] = playerIdPicked;
                sGame->players[playerIdPicked].comm.ateBerry = TRUE;
                sGame->players[playerIdMissed].comm.missedBerry = TRUE;
                sGame->berriesEaten[playerIdPicked]++;
                IncrementBerryResult(0, column, playerIdPicked);
                UpdateBerriesPickedInRow(TRUE);
                TryIncrementDifficulty(playerIdPicked);
                sGame->prevBerryIds[column] = sGame->player.berries.ids[column];
                sGame->player.berries.ids[column] = BERRY_MISSED;
                sGame->playersAttemptingPick[column][0] = PLAYER_NONE;
                sGame->playersAttemptingPick[column][1] = PLAYER_NONE;
            }
        }
    }
}

void UpdateFallingBerries(void)
{
    u8 berryStart = sGame->berryColStart;
    u8 berryEnd = sGame->berryColEnd;
    u8 delayStage = 0;
    u8 otherBerryMissed = 0;
    u8 i;

    sGame->berriesFalling = FALSE;

    for (i = berryStart; i < berryEnd - 1; i++)
    {
        struct DodrioGame *game = sGame;

        if (sGame->berryState[i] == BERRYSTATE_NONE || sGame->berryState[i] == BERRYSTATE_PICKED)
        {
            sGame->berriesFalling = TRUE;
            if (game->player.berries.fallDist[i] >= MAX_FALL_DIST)
            {
                game->player.berries.fallDist[i] = MAX_FALL_DIST;
                sGame->berryState[i] = BERRYSTATE_SQUISHED;
                if (!sGame->playingSquishSound[i])
                {
                    sGame->playingSquishSound[i] = TRUE;
                    PlaySE(SE_BALLOON_RED + game->player.berries.ids[i]);
                }
                if (sGame->numGraySquares < NUM_STATUS_SQUARES || otherBerryMissed == TRUE)
                {
                    otherBerryMissed = TRUE;
                    sGame->playingSquishSound[i] = FALSE;
                    if (sGame->numGraySquares < NUM_STATUS_SQUARES)
                        sGame->numGraySquares++;
                    IncrementBerryResult(BERRY_MISSED, i, 0);
                    UpdateBerriesPickedInRow(FALSE);
                }
            }
            else
            {
                u8 delay;
                delayStage = sGame->difficulty[GetPlayerIdAtColumn(i)] / NUM_DIFFICULTIES;
                if (delayStage > 1)
                    delayStage = 2;
                delay = sBerryFallDelays[delayStage][game->player.berries.ids[i]];
                if (++sGame->fallTimer[i] >= delay)
                {
                    game->player.berries.fallDist[i]++;
                    sGame->fallTimer[i] = 0;
                }
                HandlePickBerries();
            }
        }
        else if (sGame->berryState[i] == BERRYSTATE_EATEN)
        {
            if (++sGame->newBerryTimer[i] >= 20)
            {
                sGame->players[sGame->berryEatenBy[i]].comm.ateBerry = FALSE;
                sGame->newBerryTimer[i] = 0;
                sGame->fallTimer[i] = 0;
                sGame->berryState[i] = BERRYSTATE_NONE;
                game->player.berries.fallDist[i] = 1;
                game->player.berries.ids[i] = GetNewBerryId(GetPlayerIdAtColumn(i), i);
            }
        }
        else if (sGame->berryState[i] == BERRYSTATE_SQUISHED)
        {
            if (++sGame->newBerryTimer[i] >= 20)
            {
                if (sGame->numGraySquares < NUM_STATUS_SQUARES)
                {
                    sGame->newBerryTimer[i] = 0;
                    sGame->fallTimer[i] = 0;
                    sGame->berryState[i] = BERRYSTATE_NONE;
                    game->player.berries.fallDist[i] = 1;
                    sGame->prevBerryIds[i] = game->player.berries.ids[i];
                    game->player.berries.ids[i] = GetNewBerryId(GetPlayerIdAtColumn(i), i);
                }
            }
        }
    }
}

void UpdateBerrySprites(void)
{
    u8 i;
    u8 berryStart = sGame->berryColStart;
    u8 berryEnd = sGame->berryColEnd;

    for (i = berryStart; i < berryEnd; i++)
    {
        struct DodrioGame_Player *player = &sGame->players[sGame->multiplayerId];
        u8 column = sActiveColumnMap[sGame->numPlayers - 1][sGame->multiplayerId][i];

        if (player->berries.fallDist[column] != 0)
            SetBerryInvisibility(i, FALSE);
        else
            SetBerryInvisibility(i, TRUE);

        if (player->berries.fallDist[column] >= MAX_FALL_DIST)
        {
            SetBerryAnim(i, player->berries.ids[column] + BERRY_MISSED);
            SetBerryYPos(i, player->berries.fallDist[column] * 2 - 1);
        }
        else if (player->berries.ids[column] == 3)
        {
            player->berries.fallDist[column] = EAT_FALL_DIST;
            SetBerryAnim(i, 6); // JP eaten anim
            SetBerryYPos(i, player->berries.fallDist[column] * 2 - 1);
        }
        else
        {
            SetBerryAnim(i, player->berries.ids[column]);
            SetBerryYPos(i, player->berries.fallDist[column] * 2);
        }
    }
}

void UpdateAllDodrioAnims(void)
{
    u8 i, numPlayers;

    numPlayers = sGame->numPlayers;
    for (i = 0; i < numPlayers; i++)
    {
        struct DodrioGame_Player *player = &sGame->players[i];
        SetDodrioAnim(i, player->comm.pickState);
    }
}

void SetAllDodrioDisabled(void)
{
    u8 i, numPlayers;

    numPlayers = sGame->numPlayers;
    for (i = 0; i < numPlayers; i++)
        SetDodrioAnim(i, PICK_DISABLED);
}

void UpdateGame_Leader(void)
{
    UpdateBerrySprites();
    if (sGame->numGraySquares >= NUM_STATUS_SQUARES)
        SetAllDodrioDisabled();
    else
        UpdateAllDodrioAnims();
    UpdateStatusBarAnim(sGame->numGraySquares);
}

void UpdateGame_Member(void)
{
    UpdateBerrySprites();
    if (sGame->numGraySquares >= NUM_STATUS_SQUARES)
        SetAllDodrioDisabled();
    else
        UpdateAllDodrioAnims();
    UpdateStatusBarAnim(sGame->numGraySquares);
}

void GetActiveBerryColumns(u8 numPlayers, u8 *berryStart, u8 *berryEnd)
{
    switch (numPlayers - 1)
    {
    case 0:
        *berryStart = 4;
        *berryEnd = 7;
        break;
    case 1:
        *berryStart = 3;
        *berryEnd = 8;
        break;
    case 2:
        *berryStart = 2;
        *berryEnd = 9;
        break;
    case 3:
        *berryStart = 1;
        *berryEnd = 10;
        break;
    case 4:
        *berryStart = 0;
        *berryEnd = 11;
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

__attribute__((naked)) void sub_0802792C(u8 windowId)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x1c\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r0, _08027A28\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r2, #0x84\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	subs r2, #4\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [sp, #0x10]\n\t"
        "	ldr r0, _08027A2C\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrh r0, [r1]\n\t"
        "	str r0, [sp, #0x14]\n\t"
        "	ldr r4, _08027A30\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #0xd0\n\t"
        "	bl LoadUserWindowBorderGfx_\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #0xd\n\t"
        "	bl DrawTextBorderOuter\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r2, _08027A34\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #8]\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	movs r6, #0\n\t"
        "	ldr r2, _08027A38\n\t"
        "	mov r8, r2\n\t"
        "	movs r0, #0xff\n\t"
        "	mov sl, r0\n\t"
        "	mov sb, r6\n\t"
        "	mov r2, sp\n\t"
        "	adds r2, #0xc\n\t"
        "	str r2, [sp, #0x18]\n\t"
        "_080279A2:\n\t"
        "	lsls r4, r6, #2\n\t"
        "	ldr r0, [sp, #0x18]\n\t"
        "	ldm r0!, {r1}\n\t"
        "	str r0, [sp, #0x18]\n\t"
        "	ldr r0, _08027A3C\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldrb r3, [r0]\n\t"
        "	mov r0, r8\n\t"
        "	movs r2, #0\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	movs r0, #1\n\t"
        "	mov r1, r8\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r0, _08027A40\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldr r2, [r4]\n\t"
        "	ldr r0, _08027A44\n\t"
        "	lsls r4, r6, #1\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	str r0, [sp]\n\t"
        "	mov r0, sl\n\t"
        "	str r0, [sp, #4]\n\t"
        "	mov r0, sb\n\t"
        "	str r0, [sp, #8]\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	movs r3, #0xa0\n\t"
        "	subs r3, r3, r5\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	ldr r0, _08027A48\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	str r0, [sp]\n\t"
        "	mov r2, sl\n\t"
        "	str r2, [sp, #4]\n\t"
        "	mov r0, sb\n\t"
        "	str r0, [sp, #8]\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r1, #1\n\t"
        "	mov r2, r8\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	adds r6, #1\n\t"
        "	cmp r6, #2\n\t"
        "	ble _080279A2\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl PutWindowTilemap\n\t"
        "	add sp, #0x1c\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08027A28: .4byte gSaveBlock2Ptr\n\t"
        "_08027A2C: .4byte 0x00000212\n\t"
        "_08027A30: .4byte 0x0000021D\n\t"
        "_08027A34: .4byte 0x085CCCF5\n\t"
        "_08027A38: .4byte gStringVar1\n\t"
        "_08027A3C: .4byte sRecordDigitCounts\n\t"
        "_08027A40: .4byte sRecordsLabels\n\t"
        "_08027A44: .4byte sRecordLabelYs\n\t"
        "_08027A48: .4byte sRecordValueYs\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void Debug_SetPlayerNamesAndResults(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	ldr r0, _08027AEC\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x24\n\t"
        "	ldrb r4, [r0]\n\t"
        "	cmp r4, #4\n\t"
        "	bhi _08027A92\n\t"
        "	ldr r5, _08027AF0\n\t"
        "_08027A74:\n\t"
        "	lsls r0, r4, #3\n\t"
        "	subs r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08027AF4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl StringCopy\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08027A74\n\t"
        "_08027A92:\n\t"
        "	ldr r0, _08027AEC\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r1, #0x24\n\t"
        "	movs r2, #5\n\t"
        "	strb r2, [r1]\n\t"
        "	movs r1, #0\n\t"
        "	mov ip, r0\n\t"
        "_08027AA0:\n\t"
        "	movs r4, #0\n\t"
        "	mov r2, ip\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x24\n\t"
        "	adds r5, r1, #1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r4, r0\n\t"
        "	bhs _08027ADE\n\t"
        "	ldr r7, _08027AEC\n\t"
        "	lsls r3, r1, #1\n\t"
        "	ldr r6, _08027AF8\n\t"
        "_08027AB6:\n\t"
        "	ldr r2, [r7]\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r3, r0\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r1, #0x4a\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r0, r4, #3\n\t"
        "	adds r0, r3, r0\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r2, #0x24\n\t"
        "	ldrb r2, [r2]\n\t"
        "	cmp r4, r2\n\t"
        "	blo _08027AB6\n\t"
        "_08027ADE:\n\t"
        "	lsls r0, r5, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #3\n\t"
        "	bls _08027AA0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08027AEC: .4byte sDodrioGame\n\t"
        "_08027AF0: .4byte sPlayerNames\n\t"
        "_08027AF4: .4byte gUnknown_20226A8\n\t"
        "_08027AF8: .4byte sBerryResultsInit\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void SpriteCB_Cloud(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r0, #0x42\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08028A62\n\t"
        "	movs r3, #0\n\t"
        "	ldr r7, _08028A68\n\t"
        "	ldr r6, _08028A6C\n\t"
        "	movs r5, #0\n\t"
        "_08028A36:\n\t"
        "	lsls r0, r3, #2\n\t"
        "	adds r2, r0, r6\n\t"
        "	ldr r1, [r2]\n\t"
        "	ldrh r0, [r1, #2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	adds r1, r3, r7\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bls _08028A58\n\t"
        "	ldrh r0, [r4, #0x20]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	ldr r0, [r2]\n\t"
        "	strh r5, [r0, #2]\n\t"
        "_08028A58:\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	cmp r3, #1\n\t"
        "	bls _08028A36\n\t"
        "_08028A62:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08028A68: .4byte sCloudDurations\n\t"
        "_08028A6C: .4byte gUnknown_2022964\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void InitBgs(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #8\n\t"
        "	movs r3, #0xc0\n\t"
        "	lsls r3, r3, #0x13\n\t"
        "	movs r4, #0xc0\n\t"
        "	lsls r4, r4, #9\n\t"
        "	add r0, sp, #4\n\t"
        "	mov r8, r0\n\t"
        "	mov r2, sp\n\t"
        "	movs r6, #0\n\t"
        "	ldr r1, _0802A5CC\n\t"
        "	movs r5, #0x80\n\t"
        "	lsls r5, r5, #5\n\t"
        "	ldr r7, _0802A5D0\n\t"
        "	movs r0, #0x81\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	mov ip, r0\n\t"
        "_0802A4C2:\n\t"
        "	strh r6, [r2]\n\t"
        "	mov r0, sp\n\t"
        "	str r0, [r1]\n\t"
        "	str r3, [r1, #4]\n\t"
        "	str r7, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	adds r3, r3, r5\n\t"
        "	subs r4, r4, r5\n\t"
        "	cmp r4, r5\n\t"
        "	bhi _0802A4C2\n\t"
        "	strh r6, [r2]\n\t"
        "	mov r2, sp\n\t"
        "	str r2, [r1]\n\t"
        "	str r3, [r1, #4]\n\t"
        "	lsrs r0, r4, #1\n\t"
        "	mov r2, ip\n\t"
        "	orrs r0, r2\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	movs r0, #0xe0\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	movs r3, #0x80\n\t"
        "	lsls r3, r3, #3\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp, #4]\n\t"
        "	ldr r2, _0802A5CC\n\t"
        "	mov r1, r8\n\t"
        "	str r1, [r2]\n\t"
        "	str r0, [r2, #4]\n\t"
        "	lsrs r0, r3, #2\n\t"
        "	movs r1, #0x85\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2, #8]\n\t"
        "	ldr r0, [r2, #8]\n\t"
        "	movs r1, #0xa0\n\t"
        "	lsls r1, r1, #0x13\n\t"
        "	mov r0, sp\n\t"
        "	strh r4, [r0]\n\t"
        "	str r0, [r2]\n\t"
        "	str r1, [r2, #4]\n\t"
        "	lsrs r3, r3, #1\n\t"
        "	movs r0, #0x81\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r3, r0\n\t"
        "	str r3, [r2, #8]\n\t"
        "	ldr r0, [r2, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0\n\t"
        "	bl ResetBgsAndClearDma3BusyFlags\n\t"
        "	ldr r1, _0802A5D4\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #4\n\t"
        "	bl InitBgsFromTemplates\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	bl InitStandardTextBoxWindows\n\t"
        "	bl sub_08196DF4\n\t"
        "	movs r1, #0x82\n\t"
        "	lsls r1, r1, #5\n\t"
        "	movs r0, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r4, _0802A5D8\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #3\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r0, #1\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #6\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #2\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	add sp, #8\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0802A5CC: .4byte 0x040000D4\n\t"
        "_0802A5D0: .4byte 0x81000800\n\t"
        "_0802A5D4: .4byte sDodrioBgTemplates\n\t"
        "_0802A5D8: .4byte gUnknown_20229AC\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_080295A4(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x14\n\t"
        "	bl sub_08027410\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	ldr r6, _080295D4\n\t"
        "	ldr r1, [r6]\n\t"
        "	ldr r2, _080295D8\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xb\n\t"
        "	bls _080295CA\n\t"
        "	b _08029CC0\n\t"
        "_080295CA:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080295DC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_080295D4: .4byte gUnknown_20229AC\n\t"
        "_080295D8: .4byte 0x00003014\n\t"
        "_080295DC: .4byte 0x080295E0\n\t"
        "_080295E0: @ jump table\n\t"
        "	.4byte _08029610 @ case 0\n\t"
        "	.4byte _0802962C @ case 1\n\t"
        "	.4byte _08029684 @ case 2\n\t"
        "	.4byte _08029888 @ case 3\n\t"
        "	.4byte _080298D4 @ case 4\n\t"
        "	.4byte _08029918 @ case 5\n\t"
        "	.4byte _0802997C @ case 6\n\t"
        "	.4byte _080299B8 @ case 7\n\t"
        "	.4byte _080299FC @ case 8\n\t"
        "	.4byte _08029ABC @ case 9\n\t"
        "	.4byte _08029C20 @ case 10\n\t"
        "	.4byte _08029C74 @ case 11\n\t"
        "_08029610:\n\t"
        "	bl sub_0802760C\n\t"
        "	ldr r0, _08029624\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _08029628\n\t"
        "	adds r2, r1, r0\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2]\n\t"
        "	b _08029CA2\n\t"
        "	.align 2, 0\n\t"
        "_08029624: .4byte gUnknown_20229AC\n\t"
        "_08029628: .4byte 0x0000301C\n\t"
        "_0802962C:\n\t"
        "	ldr r6, _08029674\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl AddWindow\n\t"
        "	ldr r4, _08029678\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r2, _0802967C\n\t"
        "	mov r8, r2\n\t"
        "	add r1, r8\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #8\n\t"
        "	adds r0, r0, r6\n\t"
        "	mov sb, r0\n\t"
        "	bl AddWindow\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r5, _08029680\n\t"
        "	adds r1, r1, r5\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r4]\n\t"
        "	add r0, r8\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08028EA0\n\t"
        "	mov r0, sb\n\t"
        "	bl sub_08028EA0\n\t"
        "	b _08029CA0\n\t"
        "	.align 2, 0\n\t"
        "_08029674: .4byte sDodrioWindowTemplates_Results\n\t"
        "_08029678: .4byte gUnknown_20229AC\n\t"
        "_0802967C: .4byte 0x00003008\n\t"
        "_08029680: .4byte 0x00003009\n\t"
        "_08029684:\n\t"
        "	ldr r4, _080297D0\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r5, _080297D4\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080297D8\n\t"
        "	mov sb, r1\n\t"
        "	add r0, sb\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r2, _080297DC\n\t"
        "	mov r8, r2\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	movs r0, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl GetStringWidth\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0xe0\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsrs r3, r0, #1\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r6, #0xff\n\t"
        "	str r6, [sp, #4]\n\t"
        "	movs r5, #0\n\t"
        "	str r5, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	mov r2, r8\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldr r0, [r4]\n\t"
        "	add r0, sb\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r2, _080297E0\n\t"
        "	movs r1, #0x10\n\t"
        "	str r1, [sp]\n\t"
        "	str r6, [sp, #4]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	movs r3, #0x44\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	ldr r1, [sp, #0xc]\n\t"
        "	cmp sb, r1\n\t"
        "	blo _080296FE\n\t"
        "	b _08029844\n\t"
        "_080296FE:\n\t"
        "	movs r4, #0\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp sb, r0\n\t"
        "	bne _0802970E\n\t"
        "	movs r4, #2\n\t"
        "_0802970E:\n\t"
        "	mov r0, sb\n\t"
        "	bl sub_08027420\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldr r0, _080297D0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r2, _080297D8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov r1, sb\n\t"
        "	lsls r5, r1, #1\n\t"
        "	ldr r2, _080297E4\n\t"
        "	adds r1, r5, r2\n\t"
        "	ldrb r3, [r1]\n\t"
        "	lsls r1, r4, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldr r2, _080297E8\n\t"
        "	adds r1, r1, r2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r4, #1\n\t"
        "	rsbs r4, r4, #0\n\t"
        "	str r4, [sp, #4]\n\t"
        "	str r6, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #2\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	movs r7, #0\n\t"
        "	mov r8, r5\n\t"
        "	mov r0, sb\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [sp, #0x10]\n\t"
        "	ldr r1, _080297EC\n\t"
        "	mov sl, r1\n\t"
        "_08029752:\n\t"
        "	mov r0, sb\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl sub_08027460\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldr r1, _080297F0\n\t"
        "	bl Min\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl sub_0802754C\n\t"
        "	ldr r1, _080297F0\n\t"
        "	bl Min\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	mov r0, sl\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #4\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	movs r0, #0\n\t"
        "	mov r1, sl\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	adds r5, r0, #0\n\t"
        "	cmp r6, r4\n\t"
        "	bne _080297FC\n\t"
        "	cmp r6, #0\n\t"
        "	beq _080297FC\n\t"
        "	ldr r0, _080297D0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r2, _080297D8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r7, #1\n\t"
        "	ldr r2, _080297F4\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r2, [r1]\n\t"
        "	subs r2, r2, r5\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r1, _080297E4\n\t"
        "	add r1, r8\n\t"
        "	ldrb r3, [r1]\n\t"
        "	ldr r1, _080297F8\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #1\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	mov r1, sl\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	b _0802982A\n\t"
        "	.align 2, 0\n\t"
        "_080297D0: .4byte gUnknown_20229AC\n\t"
        "_080297D4: .4byte 0x00003008\n\t"
        "_080297D8: .4byte 0x00003009\n\t"
        "_080297DC: .4byte gText_BerryPickingResults\n\t"
        "_080297E0: .4byte gText_10P30P50P50P\n\t"
        "_080297E4: .4byte sResultsYCoords\n\t"
        "_080297E8: .4byte sDodrioTextColorTable\n\t"
        "_080297EC: .4byte gStringVar4\n\t"
        "_080297F0: .4byte 0x0000270F\n\t"
        "_080297F4: .4byte sResultsXCoords\n\t"
        "_080297F8: .4byte 0x082CEC0F\n\t"
        "_080297FC:\n\t"
        "	ldr r0, _0802986C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r2, _08029870\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r7, #1\n\t"
        "	ldr r2, _08029874\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r3, [r1]\n\t"
        "	subs r3, r3, r5\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	ldr r1, _08029878\n\t"
        "	add r1, r8\n\t"
        "	ldrb r1, [r1]\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	ldr r2, _0802987C\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "_0802982A:\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	cmp r7, #3\n\t"
        "	bls _08029752\n\t"
        "	ldr r1, [sp, #0x10]\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	ldr r2, [sp, #0xc]\n\t"
        "	cmp sb, r2\n\t"
        "	bhs _08029844\n\t"
        "	b _080296FE\n\t"
        "_08029844:\n\t"
        "	ldr r4, _0802986C\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08029880\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _08029870\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r0, _08029884\n\t"
        "	adds r1, r1, r0\n\t"
        "	b _08029CA6\n\t"
        "	.align 2, 0\n\t"
        "_0802986C: .4byte gUnknown_20229AC\n\t"
        "_08029870: .4byte 0x00003009\n\t"
        "_08029874: .4byte sResultsXCoords\n\t"
        "_08029878: .4byte sResultsYCoords\n\t"
        "_0802987C: .4byte gStringVar4\n\t"
        "_08029880: .4byte 0x00003008\n\t"
        "_08029884: .4byte 0x00003014\n\t"
        "_08029888:\n\t"
        "	bl IsDma3ManagerBusyWithBgCopy\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080298AC\n\t"
        "	ldr r4, _080298C4\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080298C8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _080298CC\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "_080298AC:\n\t"
        "	movs r0, #0\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_0802895C\n\t"
        "	ldr r0, _080298C4\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080298D0\n\t"
        "	adds r1, r1, r0\n\t"
        "	b _08029CA6\n\t"
        "	.align 2, 0\n\t"
        "_080298C4: .4byte gUnknown_20229AC\n\t"
        "_080298C8: .4byte 0x00003008\n\t"
        "_080298CC: .4byte 0x00003009\n\t"
        "_080298D0: .4byte 0x00003014\n\t"
        "_080298D4:\n\t"
        "	ldr r4, _0802990C\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08029910\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldrh r0, [r2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r2]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x1d\n\t"
        "	bhi _080298EC\n\t"
        "	b _08029D10\n\t"
        "_080298EC:\n\t"
        "	ldr r0, _08029914\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080298FA\n\t"
        "	b _08029D10\n\t"
        "_080298FA:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_0802895C\n\t"
        "	b _08029CA0\n\t"
        "	.align 2, 0\n\t"
        "_0802990C: .4byte gUnknown_20229AC\n\t"
        "_08029910: .4byte 0x0000301C\n\t"
        "_08029914: .4byte gMain\n\t"
        "_08029918:\n\t"
        "	ldr r4, _0802996C\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r5, _08029970\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08029974\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r6, _08029978\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	movs r0, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0xe0\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsrs r3, r0, #1\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	b _08029CA0\n\t"
        "	.align 2, 0\n\t"
        "_0802996C: .4byte gUnknown_20229AC\n\t"
        "_08029970: .4byte 0x00003008\n\t"
        "_08029974: .4byte 0x00003009\n\t"
        "_08029978: .4byte gText_AnnouncingRankings\n\t"
        "_0802997C:\n\t"
        "	ldr r0, [sp, #0xc]\n\t"
        "	bl sub_080293D4\n\t"
        "	ldr r4, _080299A8\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080299AC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _080299B0\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r0, _080299B4\n\t"
        "	adds r1, r1, r0\n\t"
        "	b _08029CA6\n\t"
        "	.align 2, 0\n\t"
        "_080299A8: .4byte gUnknown_20229AC\n\t"
        "_080299AC: .4byte 0x00003008\n\t"
        "_080299B0: .4byte 0x00003009\n\t"
        "_080299B4: .4byte 0x00003014\n\t"
        "_080299B8:\n\t"
        "	bl IsDma3ManagerBusyWithBgCopy\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080299DC\n\t"
        "	ldr r4, _080299EC\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080299F0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _080299F4\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "_080299DC:\n\t"
        "	movs r0, #0\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	ldr r0, _080299EC\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080299F8\n\t"
        "	adds r1, r1, r0\n\t"
        "	b _08029CA6\n\t"
        "	.align 2, 0\n\t"
        "_080299EC: .4byte gUnknown_20229AC\n\t"
        "_080299F0: .4byte 0x00003008\n\t"
        "_080299F4: .4byte 0x00003009\n\t"
        "_080299F8: .4byte 0x00003014\n\t"
        "_080299FC:\n\t"
        "	ldr r4, _08029A44\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08029A48\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldrh r0, [r2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r2]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x1d\n\t"
        "	bhi _08029A14\n\t"
        "	b _08029D10\n\t"
        "_08029A14:\n\t"
        "	ldr r0, _08029A4C\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08029A22\n\t"
        "	b _08029D10\n\t"
        "_08029A22:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	bl sub_08027508\n\t"
        "	ldr r1, _08029A50\n\t"
        "	cmp r0, r1\n\t"
        "	bhi _08029A58\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _08029A54\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r1, #0x7f\n\t"
        "	strb r1, [r0]\n\t"
        "	b _08029A68\n\t"
        "	.align 2, 0\n\t"
        "_08029A44: .4byte gUnknown_20229AC\n\t"
        "_08029A48: .4byte 0x0000301C\n\t"
        "_08029A4C: .4byte gMain\n\t"
        "_08029A50: .4byte 0x00000BB7\n\t"
        "_08029A54: .4byte 0x00003014\n\t"
        "_08029A58:\n\t"
        "	bl StopMapMusic\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r0, _08029AAC\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "_08029A68:\n\t"
        "	movs r0, #0x1e\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xf\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #5\n\t"
        "	bl FillBgTilemapBufferRect_Palette0\n\t"
        "	ldr r5, _08029AB0\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r4, _08029AB4\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl RemoveWindow\n\t"
        "	ldr r6, _08029AB8\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl AddWindow\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, r1, r4\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08028EA0\n\t"
        "	b _08029D10\n\t"
        "	.align 2, 0\n\t"
        "_08029AAC: .4byte 0x00003014\n\t"
        "_08029AB0: .4byte gUnknown_20229AC\n\t"
        "_08029AB4: .4byte 0x00003009\n\t"
        "_08029AB8: .4byte sWindowTemplate_Prize\n\t"
        "_08029ABC:\n\t"
        "	ldr r0, _08029B94\n\t"
        "	bl PlayNewMapMusic\n\t"
        "	ldr r4, _08029B98\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r6, _08029B9C\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08029BA0\n\t"
        "	mov sl, r1\n\t"
        "	add r0, sl\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r5, _08029BA4\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	movs r0, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetStringWidth\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0xe0\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsrs r3, r0, #1\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	movs r2, #2\n\t"
        "	mov sb, r2\n\t"
        "	str r2, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	mov r8, r1\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r6, #0\n\t"
        "	str r6, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	bl DynamicPlaceholderTextUtil_Reset\n\t"
        "	bl sub_080273EC\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldr r5, _08029BA8\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl CopyItemName\n\t"
        "	movs r0, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
        "	ldr r7, _08029BAC\n\t"
        "	ldr r1, _08029BB0\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
        "	ldr r0, [r4]\n\t"
        "	add r0, sl\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov r2, sb\n\t"
        "	str r2, [sp]\n\t"
        "	mov r1, r8\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r6, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r7, #0\n\t"
        "	movs r3, #8\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	bl sub_08027788\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r6, r4, #0\n\t"
        "	cmp r4, #0\n\t"
        "	beq _08029BE2\n\t"
        "	cmp r4, #3\n\t"
        "	beq _08029BE2\n\t"
        "	bl DynamicPlaceholderTextUtil_Reset\n\t"
        "	bl sub_080273EC\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl CopyItemName\n\t"
        "	movs r0, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr\n\t"
        "	cmp r4, #2\n\t"
        "	bne _08029BB8\n\t"
        "	ldr r1, _08029BB4\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
        "	b _08029BC4\n\t"
        "	.align 2, 0\n\t"
        "_08029B94: .4byte SPECIAL_sub_0818DA30\n\t"
        "_08029B98: .4byte gUnknown_20229AC\n\t"
        "_08029B9C: .4byte 0x00003008\n\t"
        "_08029BA0: .4byte 0x00003009\n\t"
        "_08029BA4: .4byte gText_AnnouncingPrizes\n\t"
        "_08029BA8: .4byte gStringVar1\n\t"
        "_08029BAC: .4byte gStringVar4\n\t"
        "_08029BB0: .4byte gText_FirstPlacePrize\n\t"
        "_08029BB4: .4byte gText_CantHoldAnyMore\n\t"
        "_08029BB8:\n\t"
        "	cmp r6, #1\n\t"
        "	bne _08029BC4\n\t"
        "	ldr r1, _08029C08\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl DynamicPlaceholderTextUtil_ExpandPlaceholders\n\t"
        "_08029BC4:\n\t"
        "	ldr r0, _08029C0C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r2, _08029C10\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r2, _08029C14\n\t"
        "	movs r1, #0x28\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xff\n\t"
        "	str r1, [sp, #4]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r3, #8\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "_08029BE2:\n\t"
        "	ldr r4, _08029C0C\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08029C18\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _08029C10\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #2\n\t"
        "	bl CopyWindowToVram\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r0, _08029C1C\n\t"
        "	adds r1, r1, r0\n\t"
        "	b _08029CA6\n\t"
        "	.align 2, 0\n\t"
        "_08029C08: .4byte gText_FilledStorageSpace\n\t"
        "_08029C0C: .4byte gUnknown_20229AC\n\t"
        "_08029C10: .4byte 0x00003009\n\t"
        "_08029C14: .4byte gStringVar4\n\t"
        "_08029C18: .4byte 0x00003008\n\t"
        "_08029C1C: .4byte 0x00003014\n\t"
        "_08029C20:\n\t"
        "	bl IsDma3ManagerBusyWithBgCopy\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08029C44\n\t"
        "	ldr r4, _08029C60\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08029C64\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _08029C68\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "_08029C44:\n\t"
        "	movs r0, #0\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	ldr r0, _08029C6C\n\t"
        "	movs r1, #0x14\n\t"
        "	movs r2, #0xa\n\t"
        "	bl FadeOutAndFadeInNewMapMusic\n\t"
        "	ldr r0, _08029C60\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _08029C70\n\t"
        "	adds r1, r1, r0\n\t"
        "	b _08029CA6\n\t"
        "	.align 2, 0\n\t"
        "_08029C60: .4byte gUnknown_20229AC\n\t"
        "_08029C64: .4byte 0x00003008\n\t"
        "_08029C68: .4byte 0x00003009\n\t"
        "_08029C6C: .4byte SPECIAL_sub_080B331C\n\t"
        "_08029C70: .4byte 0x00003014\n\t"
        "_08029C74:\n\t"
        "	ldr r4, _08029CB0\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08029CB4\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldrh r0, [r2]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r2]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x1d\n\t"
        "	bls _08029D10\n\t"
        "	ldr r0, _08029CB8\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08029D10\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2]\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "_08029CA0:\n\t"
        "	ldr r1, [r4]\n\t"
        "_08029CA2:\n\t"
        "	ldr r2, _08029CBC\n\t"
        "	adds r1, r1, r2\n\t"
        "_08029CA6:\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	b _08029D10\n\t"
        "	.align 2, 0\n\t"
        "_08029CB0: .4byte gUnknown_20229AC\n\t"
        "_08029CB4: .4byte 0x0000301C\n\t"
        "_08029CB8: .4byte gMain\n\t"
        "_08029CBC: .4byte 0x00003014\n\t"
        "_08029CC0:\n\t"
        "	ldr r5, _08029D20\n\t"
        "	adds r0, r1, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	ldr r0, [r6]\n\t"
        "	ldr r4, _08029D24\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl ClearWindowTilemap\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl RemoveWindow\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl RemoveWindow\n\t"
        "	movs r0, #0x1e\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0x14\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl FillBgTilemapBufferRect_Palette0\n\t"
        "	movs r0, #0\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	ldr r0, [r6]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #6\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	str r1, [r0]\n\t"
        "_08029D10:\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08029D20: .4byte 0x00003008\n\t"
        "_08029D24: .4byte 0x00003009\n\t"
        ".syntax divided\n\t"
    );
}

