#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/event_objects.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"

// JP swap: Pike/Factory facility IDs are swapped in this file, same as US.
#define MATCH_CALL_FACTORY  FRONTIER_FACILITY_PIKE
#define MATCH_CALL_PIKE     FRONTIER_FACILITY_FACTORY

struct MatchCallState
{
    u32 minutes;
    u16 trainerId;
    u8 stepCounter;
    bool8 triggeredFromScript;
};

struct BattleFrontierStreakInfo
{
    u16 facilityId;
    u16 streak;
};

// JP state/data live at fixed addresses supplied by ld_script_jp.txt.
extern struct MatchCallState sMatchCallState;           // 0x0203CA4C
extern struct BattleFrontierStreakInfo sBattleFrontierStreakInfo; // 0x0203CA54
extern bool32 (*const sMatchCallTaskFuncs[])(u8);       // 0x085D79F4
extern const struct WindowTemplate sMatchCallTextWindow; // 0x085D7A14
extern const u16 sMatchCallWindow_Pal[];                // 0x085D74C8
extern const u8 sMatchCallWindow_Gfx[];                 // 0x085D74E8
extern const u16 sPokenavIcon_Pal[];                    // 0x085D75E8
extern const u32 sPokenavIcon_Gfx[];                    // 0x085D7608
extern const u8 sText_PokenavCallEllipsis[];            // 0x085D79EC

// JP window/palette sizes (extern tables can't use sizeof).
#define MATCH_CALL_WINDOW_GFX_LENGTH 0x100
#define MATCH_CALL_WINDOW_PAL_LENGTH 0x20
#define POKENAV_ICON_PAL_LENGTH      0x20

static u32 GetCurrentTotalMinutes(struct Time *);
static u32 GetNumRegisteredNPCs(void);
static u32 GetActiveMatchCallTrainerId(u32);
static void StartMatchCall(void);
static void ExecuteMatchCall(u8);
void DrawMatchCallTextBoxBorder_Internal(u32, u32, u32);
static void InitMatchCallTextPrinter(int, const u8 *);
static bool32 RunMatchCallTextPrinter(int);
static bool32 MatchCall_LoadGfx(u8);
static bool32 MatchCall_DrawWindow(u8);
static bool32 MatchCall_ReadyIntro(u8);
static bool32 MatchCall_SlideWindowIn(u8);
static bool32 MatchCall_PrintIntro(u8);
static bool32 MatchCall_PrintMessage(u8);
static bool32 MatchCall_SlideWindowOut(u8);
static bool32 MatchCall_EndCall(u8);

// Still in asm (asm/match_call.s remainder, 0x08196294+).
int GetTrainerMatchCallId(int trainerId);
mapsec_u16_t GetRematchTrainerLocation(int matchCallId);
bool32 TrainerIsEligibleForRematch(int matchCallId);
bool32 SelectMatchCallMessage(int trainerId, u8 *str);
void Task_SpinPokenavIcon(u8 taskId);

void InitMatchCallCounters(void)
{
    RtcCalcLocalTime();
    sMatchCallState.minutes = GetCurrentTotalMinutes(&gLocalTime) + 10;
    sMatchCallState.stepCounter = 0;
}

static u32 GetCurrentTotalMinutes(struct Time *time)
{
    return time->days * 24 * 60 + time->hours * 60 + time->minutes;
}

static bool32 UpdateMatchCallMinutesCounter(void)
{
    int curMinutes;
    RtcCalcLocalTime();
    curMinutes = GetCurrentTotalMinutes(&gLocalTime);
    if (sMatchCallState.minutes > curMinutes || curMinutes - sMatchCallState.minutes > 9)
    {
        sMatchCallState.minutes = curMinutes;
        return TRUE;
    }

    return FALSE;
}

static bool32 CheckMatchCallChance(void)
{
    int callChance = 1;
    if (!GetMonData2(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG) && GetMonAbility(&gPlayerParty[0]) == ABILITY_LIGHTNING_ROD)
        callChance = 2;

    if (Random() % 10 < callChance * 3)
        return TRUE;
    else
        return FALSE;
}

static bool32 MapAllowsMatchCall(void)
{
    if (!Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) || gMapHeader.regionMapSectionId == MAPSEC_SAFARI_ZONE)
        return FALSE;

    if (gMapHeader.regionMapSectionId == MAPSEC_SOOTOPOLIS_CITY
     && FlagGet(FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA) == TRUE
     && FlagGet(FLAG_NEVER_SET_0x0DC) == FALSE)
        return FALSE;

    if (gMapHeader.regionMapSectionId == MAPSEC_MT_CHIMNEY
     && FlagGet(FLAG_MET_ARCHIE_METEOR_FALLS) == TRUE
     && FlagGet(FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY) == FALSE)
        return FALSE;

    return TRUE;
}

static bool32 UpdateMatchCallStepCounter(void)
{
    if (++sMatchCallState.stepCounter >= 10)
    {
        sMatchCallState.stepCounter = 0;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool32 SelectMatchCallTrainer(void)
{
    u32 matchCallId;
    u32 numRegistered = GetNumRegisteredNPCs();
    if (numRegistered == 0)
        return FALSE;

    sMatchCallState.trainerId = GetActiveMatchCallTrainerId(Random() % numRegistered);
    sMatchCallState.triggeredFromScript = FALSE;
    if (sMatchCallState.trainerId == REMATCH_TABLE_ENTRIES)
        return FALSE;

    matchCallId = GetTrainerMatchCallId(sMatchCallState.trainerId);
    if (GetRematchTrainerLocation(matchCallId) == gMapHeader.regionMapSectionId && !TrainerIsEligibleForRematch(matchCallId))
        return FALSE;

    return TRUE;
}

// Ignores registrable non-trainer NPCs, and special trainers like Wally and the gym leaders.
static u32 GetNumRegisteredNPCs(void)
{
    u32 i, count;
    for (i = 0, count = 0; i < REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (FlagGet(TRAINER_REGISTERED_FLAGS_START + i))
            count++;
    }

    return count;
}

static u32 GetActiveMatchCallTrainerId(u32 activeMatchCallId)
{
    u32 i;
    for (i = 0; i < REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (FlagGet(TRAINER_REGISTERED_FLAGS_START + i))
        {
            if (!activeMatchCallId)
                return gRematchTable[i].trainerIds[0];

            activeMatchCallId--;
        }
    }

    return REMATCH_TABLE_ENTRIES;
}

bool32 TryStartMatchCall(void)
{
    if (FlagGet(FLAG_HAS_MATCH_CALL)
        && UpdateMatchCallStepCounter()
        && UpdateMatchCallMinutesCounter()
        && CheckMatchCallChance()
        && MapAllowsMatchCall()
        && SelectMatchCallTrainer())
    {
        StartMatchCall();
        return TRUE;
    }

    return FALSE;
}

void StartMatchCallFromScript(const u8 *message)
{
    sMatchCallState.triggeredFromScript = TRUE;
    StartMatchCall();
}

bool32 IsMatchCallTaskActive(void)
{
    return FuncIsActiveTask(ExecuteMatchCall);
}

static void StartMatchCall(void)
{
    if (!sMatchCallState.triggeredFromScript)
    {
        LockPlayerFieldControls();
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }

    PlaySE(SE_POKENAV_CALL);
    CreateTask(ExecuteMatchCall, 1);
}

#define tState      data[0]
#define tWindowId   data[2]
#define tIconTaskId data[5]

static void ExecuteMatchCall(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (sMatchCallTaskFuncs[tState](taskId))
    {
        tState++;
        data[1] = 0; // Never read
        if ((u16)tState > 7)
            DestroyTask(taskId);
    }
}

#define TILE_MC_WINDOW    0x270
#define TILE_POKENAV_ICON 0x279

static bool32 MatchCall_LoadGfx(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tWindowId = AddWindow(&sMatchCallTextWindow);
    if (tWindowId == WINDOW_NONE)
    {
        DestroyTask(taskId);
        return FALSE;
    }

    if (LoadBgTiles(0, sMatchCallWindow_Gfx, MATCH_CALL_WINDOW_GFX_LENGTH, TILE_MC_WINDOW) == 0xFFFF)
    {
        RemoveWindow(tWindowId);
        DestroyTask(taskId);
        return FALSE;
    }

    if (!DecompressAndCopyTileDataToVram(0, sPokenavIcon_Gfx, 0, TILE_POKENAV_ICON, 0))
    {
        RemoveWindow(tWindowId);
        DestroyTask(taskId);
        return FALSE;
    }

    FillWindowPixelBuffer(tWindowId, PIXEL_FILL(8));
    LoadPalette(sMatchCallWindow_Pal, BG_PLTT_ID(14), MATCH_CALL_WINDOW_PAL_LENGTH);
    LoadPalette(sPokenavIcon_Pal, BG_PLTT_ID(15), POKENAV_ICON_PAL_LENGTH);
    ChangeBgY(0, -0x2000, BG_COORD_SET);
    return TRUE;
}

static bool32 MatchCall_DrawWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (FreeTempTileDataBuffersIfPossible())
        return FALSE;

    PutWindowTilemap(tWindowId);
    DrawMatchCallTextBoxBorder_Internal(tWindowId, TILE_MC_WINDOW, 14);
    WriteSequenceToBgTilemapBuffer(0, (0xF << 12) | TILE_POKENAV_ICON, 1, 15, 4, 4, 17, 1);
    tIconTaskId = CreateTask(Task_SpinPokenavIcon, 10);
    CopyWindowToVram(tWindowId, COPYWIN_GFX);
    CopyBgTilemapBufferToVram(0);
    return TRUE;
}

static bool32 MatchCall_ReadyIntro(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        // Note that "..." is not printed yet, just readied
        InitMatchCallTextPrinter(tWindowId, sText_PokenavCallEllipsis);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_SlideWindowIn(u8 taskId)
{
    if (ChangeBgY(0, 0x600, BG_COORD_ADD) >= 0)
    {
        ChangeBgY(0, 0, BG_COORD_SET);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_PrintIntro(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!RunMatchCallTextPrinter(tWindowId))
    {
        FillWindowPixelBuffer(tWindowId, PIXEL_FILL(8));

        // Ready the message
        if (!sMatchCallState.triggeredFromScript)
            SelectMatchCallMessage(sMatchCallState.trainerId, gStringVar4);
        InitMatchCallTextPrinter(tWindowId, gStringVar4);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_PrintMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!RunMatchCallTextPrinter(tWindowId) && !IsSEPlaying() && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        FillWindowPixelBuffer(tWindowId, PIXEL_FILL(8));
        CopyWindowToVram(tWindowId, COPYWIN_GFX);
        PlaySE(SE_POKENAV_HANG_UP);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_SlideWindowOut(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (ChangeBgY(0, 0x600, BG_COORD_SUB) <= -0x2000)
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 14, 30, 6);
        DestroyTask(tIconTaskId);
        RemoveWindow(tWindowId);
        CopyBgTilemapBufferToVram(0);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_EndCall(u8 taskId)
{
    u8 playerObjectId;
    if (!IsDma3ManagerBusyWithBgCopy() && !IsSEPlaying())
    {
        ChangeBgY(0, 0, BG_COORD_SET);
        if (!sMatchCallState.triggeredFromScript)
        {
            LoadMessageBoxAndBorderGfx();
            playerObjectId = GetObjectEventIdByLocalIdAndMap(LOCALID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
            ScriptMovement_UnfreezeObjectEvents();
            UnfreezeObjectEvents();
            UnlockPlayerFieldControls();
        }

        return TRUE;
    }

    return FALSE;
}

void DrawMatchCallTextBoxBorder_Internal(u32 windowId, u32 tileOffset, u32 paletteId)
{
    int bg, x, y, width, height;
    int tileNum;

    bg = GetWindowAttribute(windowId, WINDOW_BG);
    x = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    y = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    height = GetWindowAttribute(windowId, WINDOW_HEIGHT);
    tileNum = tileOffset + GetBgAttribute(bg, BG_ATTR_BASETILE);

    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 0), x - 1, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 1), x, y - 1, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 2), x + width, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 3), x - 1, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 4), x + width, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 5), x - 1, y + height, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 6), x, y + height, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 7), x + width, y + height, 1, 1);
}

static void InitMatchCallTextPrinter(int windowId, const u8 *str)
{
    struct TextPrinterTemplate printerTemplate;
    printerTemplate.currentChar = str;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = FONT_NORMAL;
    printerTemplate.x = 32;
    printerTemplate.y = 2;
    printerTemplate.currentX = 32;
    printerTemplate.currentY = 2;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = TEXT_DYNAMIC_COLOR_1;
    printerTemplate.bgColor = TEXT_COLOR_BLUE;
    printerTemplate.shadowColor = TEXT_DYNAMIC_COLOR_5;
    gTextFlags.useAlternateDownArrow = FALSE;

    AddTextPrinter(&printerTemplate, GetPlayerTextSpeedDelay(), NULL);
}

static bool32 RunMatchCallTextPrinter(int windowId)
{
    if (JOY_HELD(A_BUTTON))
        gTextFlags.canABSpeedUpPrint = TRUE;
    else
        gTextFlags.canABSpeedUpPrint = FALSE;

    RunTextPrinters();
    return IsTextPrinterActive(windowId);
}
