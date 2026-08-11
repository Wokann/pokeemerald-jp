#include "global.h"
#include "battle_records.h"
#include "bg.h"
#include "window.h"
#include "link.h"
#include "battle.h"
#include "overworld.h"
#include "text.h"
#include "text_window.h"
#include "strings.h"
#include "string_util.h"
#include "trainer_card.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "main.h"
#include "scanline_effect.h"
#include "international_string_util.h"
#include "sound.h"
#include "constants/songs.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "constants/game_stat.h"
#include "trainer_hill.h"
#include "constants/rgb.h"

static void Task_CloseTrainerHillRecordsOnButton(u8 taskId);
static void Task_BeginPaletteFade(u8 taskId);
static void Task_ExitTrainerHillRecords(u8 taskId);
static void RemoveTrainerHillRecordsWindow(u8 windowId);
static void CB2_ShowTrainerHillRecords(void);

extern u8 gRecordsWindowId;
extern u8 *sTilemapBuffer;

// JP keeps the trainer-hill window graphics and window templates in ROM.
extern const u32 sTrainerHillWindowTileset[48];
extern const u16 sTrainerHillWindowPalette[16];
extern const u32 sTrainerHillWindowTilemap[];
extern const struct BgTemplate sTrainerHillRecordsBgTemplates[2];
extern const struct WindowTemplate sTrainerHillRecordsWindowTemplates[];
extern const struct WindowTemplate sLinkBattleRecordsWindow;
extern const u8 sText_DashesNoPlayer[];
extern const u8 sText_DashesNoScore[];

// code
static void ClearLinkBattleRecord(struct LinkBattleRecord *record)
{
    CpuFill16(0, record, sizeof(struct LinkBattleRecord));
    record->name[0] = EOS;
    record->trainerId = 0;
    record->wins = 0;
    record->losses = 0;
    record->draws = 0;
}

static void ClearLinkBattleRecords(struct LinkBattleRecord *records)
{
    s32 i;
    for (i = 0; i < LINK_B_RECORDS_COUNT; i++)
    {
        ClearLinkBattleRecord(records + i);
    }
    SetGameStat(GAME_STAT_LINK_BATTLE_WINS, 0);
    SetGameStat(GAME_STAT_LINK_BATTLE_LOSSES, 0);
    SetGameStat(GAME_STAT_LINK_BATTLE_DRAWS, 0);
}

static s32 GetLinkBattleRecordTotalBattles(struct LinkBattleRecord *record)
{
    return record->wins + record->losses + record->draws;
}

static s32 FindLinkBattleRecord(struct LinkBattleRecord *records, const u8 *name, u16 trainerId)
{
    s32 i;

    for (i = 0; i < LINK_B_RECORDS_COUNT; i++)
    {
        if (!StringCompareN(records[i].name, name, PLAYER_NAME_LENGTH) && records[i].trainerId == trainerId)
            return i;
    }

    return LINK_B_RECORDS_COUNT;
}

static void SortLinkBattleRecords(struct LinkBattleRecords *records)
{
    s32 i, j;

    for (i = LINK_B_RECORDS_COUNT - 1; i > 0; i--)
    {
        for (j = i - 1; j >= 0; j--)
        {
            s32 totalBattlesI = GetLinkBattleRecordTotalBattles(&records->entries[i]);
            s32 totalBattlesJ = GetLinkBattleRecordTotalBattles(&records->entries[j]);

            if (totalBattlesI > totalBattlesJ)
            {
                struct LinkBattleRecord temp1;

                temp1 = records->entries[i];
                records->entries[i] = records->entries[j];
                records->entries[j] = temp1;
            }
        }
    }
}

static void UpdateLinkBattleRecord(struct LinkBattleRecord *record, s32 battleOutcome)
{
    switch (battleOutcome)
    {
    case B_OUTCOME_WON:
        record->wins++;
        if (record->wins > 9999)
            record->wins = 9999;
        break;
    case B_OUTCOME_LOST:
        record->losses++;
        if (record->losses > 9999)
            record->losses = 9999;
        break;
    case B_OUTCOME_DREW:
        record->draws++;
        if (record->draws > 9999)
            record->draws = 9999;
        break;
    }
}

static void UpdateLinkBattleGameStats(s32 battleOutcome)
{
    u8 stat;

    switch (battleOutcome)
    {
    case B_OUTCOME_WON:
        stat = GAME_STAT_LINK_BATTLE_WINS;
        break;
    case B_OUTCOME_LOST:
        stat = GAME_STAT_LINK_BATTLE_LOSSES;
        break;
    case B_OUTCOME_DREW:
        stat = GAME_STAT_LINK_BATTLE_DRAWS;
        break;
    default:
        return;
    }

    if (GetGameStat(stat) < 9999)
        IncrementGameStat(stat);
}

static void UpdateLinkBattleRecords(struct LinkBattleRecords *records, const u8 *name, u16 trainerId, s32 battleOutcome, u8 battler)
{
    s32 index;

    UpdateLinkBattleGameStats(battleOutcome);
    SortLinkBattleRecords(records);
    index = FindLinkBattleRecord(records->entries, name, trainerId);
    if (index == LINK_B_RECORDS_COUNT)
    {
        index = LINK_B_RECORDS_COUNT - 1;
        ClearLinkBattleRecord(&records->entries[index]);
        StringCopyN(records->entries[index].name, name, PLAYER_NAME_LENGTH);
        records->entries[index].trainerId = trainerId;
        records->languages[index] = gLinkPlayers[battler].language;
    }
    UpdateLinkBattleRecord(&records->entries[index], battleOutcome);
    SortLinkBattleRecords(records);
}

void ClearPlayerLinkBattleRecords(void)
{
    ClearLinkBattleRecords(gSaveBlock1Ptr->linkBattleRecords.entries);
}

static void IncTrainerCardWins(s32 battler)
{
    u16 *wins = &gTrainerCards[battler].linkBattleWins;
    (*wins)++;
    if (*wins > 9999)
        *wins = 9999;
}

static void IncTrainerCardLosses(s32 battler)
{
    u16 *losses = &gTrainerCards[battler].linkBattleLosses;
    (*losses)++;
    if (*losses > 9999)
        *losses = 9999;
}

static void UpdateTrainerCardWinsLosses(s32 battler)
{
    switch (gBattleOutcome)
    {
    case B_OUTCOME_WON:
        IncTrainerCardWins(BATTLE_OPPOSITE(battler));
        IncTrainerCardLosses(battler);
        break;
    case B_OUTCOME_LOST:
        IncTrainerCardLosses(BATTLE_OPPOSITE(battler));
        IncTrainerCardWins(battler);
        break;
    }
}

void UpdatePlayerLinkBattleRecords(s32 battler)
{
    if (InUnionRoom() != TRUE)
    {
        UpdateTrainerCardWinsLosses(battler);
        UpdateLinkBattleRecords(
            &gSaveBlock1Ptr->linkBattleRecords,
            gTrainerCards[battler].playerName,
            gTrainerCards[battler].trainerId,
            gBattleOutcome,
            battler);
    }
}

static void PrintLinkBattleWinsLossesDraws(struct LinkBattleRecord *records)
{
    ConvertIntToDecimalStringN(gStringVar1, GetGameStat(GAME_STAT_LINK_BATTLE_WINS), STR_CONV_MODE_RIGHT_ALIGN, 4);
    ConvertIntToDecimalStringN(gStringVar2, GetGameStat(GAME_STAT_LINK_BATTLE_LOSSES), STR_CONV_MODE_RIGHT_ALIGN, 4);
    ConvertIntToDecimalStringN(gStringVar3, GetGameStat(GAME_STAT_LINK_BATTLE_DRAWS), STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_TotalRecordWLD);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, 0, 0x12, 0, NULL);
}

static void PrintLinkBattleRecord(struct LinkBattleRecord *record, u8 y)
{
    // JP reads losses and draws as one 32-bit word.
    if (record->wins == 0 && *(u32 *)&record->losses == 0)
    {
        // empty slot
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, sText_DashesNoPlayer,   8, (y * 8) + 2, 0, NULL);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, sText_DashesNoScore,  80, (y * 8) + 2, 0, NULL);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, sText_DashesNoScore, 120, (y * 8) + 2, 0, NULL);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, sText_DashesNoScore, 168, (y * 8) + 2, 0, NULL);
    }
    else
    {
        StringFillWithTerminator(gStringVar1, 8);
        StringCopyN(gStringVar1, record->name, 7);

        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar1, 8, (y * 8) + 2, 0, NULL);

        ConvertIntToDecimalStringN(gStringVar1, record->wins, STR_CONV_MODE_RIGHT_ALIGN, 4);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar1,  80, (y * 8) + 2, 0, NULL);

        ConvertIntToDecimalStringN(gStringVar1, record->losses, STR_CONV_MODE_RIGHT_ALIGN, 4);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar1, 120, (y * 8) + 2, 0, NULL);

        ConvertIntToDecimalStringN(gStringVar1, record->draws, STR_CONV_MODE_RIGHT_ALIGN, 4);
        AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar1, 168, (y * 8) + 2, 0, NULL);
    }
}

// Kept as naked asm: agbcc cannot reproduce the JP register allocation
// for the record loop (r4 counter, r5 entry offset, r6 y in the high
// byte, r7 save-block pointer).
#ifndef NONMATCHING
__attribute__((naked)) void ShowLinkBattleRecords(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sb\n\t"
            "mov r6, r8\n\t"
            "push {r6, r7}\n\t"
            "sub sp, #0xc\n\t"
            "ldr r6, _0813C560\n\t"
            "ldr r0, _0813C564\n\t"
            "bl AddWindow\n\t"
            "strb r0, [r6]\n\t"
            "ldrb r0, [r6]\n\t"
            "movs r1, #0\n\t"
            "bl DrawStdWindowFrame\n\t"
            "ldrb r0, [r6]\n\t"
            "movs r1, #0x11\n\t"
            "bl FillWindowPixelBuffer\n\t"
            "ldr r5, _0813C568\n\t"
            "ldr r1, _0813C56C\n\t"
            "adds r0, r5, #0\n\t"
            "bl StringExpandPlaceholders\n\t"
            "ldrb r0, [r6]\n\t"
            "movs r1, #2\n\t"
            "str r1, [sp]\n\t"
            "movs r4, #0\n\t"
            "str r4, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "adds r2, r5, #0\n\t"
            "movs r3, #0x30\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "ldr r0, _0813C570\n\t"
            "mov r8, r0\n\t"
            "ldr r0, [r0]\n\t"
            "ldr r1, _0813C574\n\t"
            "mov sb, r1\n\t"
            "add r0, sb\n\t"
            "bl PrintLinkBattleWinsLossesDraws\n\t"
            "ldr r1, _0813C578\n\t"
            "adds r0, r5, #0\n\t"
            "bl StringExpandPlaceholders\n\t"
            "ldrb r0, [r6]\n\t"
            "movs r1, #0x2a\n\t"
            "str r1, [sp]\n\t"
            "str r4, [sp, #4]\n\t"
            "str r4, [sp, #8]\n\t"
            "movs r1, #1\n\t"
            "adds r2, r5, #0\n\t"
            "movs r3, #0x50\n\t"
            "bl AddTextPrinterParameterized\n\t"
            "mov r7, r8\n\t"
            "movs r6, #0xe0\n\t"
            "lsls r6, r6, #0x13\n\t"
            "mov r5, sb\n\t"
            "movs r4, #4\n\t"
            "_0813C52A:\n\t"
            "ldr r0, [r7]\n\t"
            "adds r0, r0, r5\n\t"
            "lsrs r1, r6, #0x18\n\t"
            "bl PrintLinkBattleRecord\n\t"
            "movs r0, #0x80\n\t"
            "lsls r0, r0, #0x12\n\t"
            "adds r6, r6, r0\n\t"
            "adds r5, #0x10\n\t"
            "subs r4, #1\n\t"
            "cmp r4, #0\n\t"
            "bge _0813C52A\n\t"
            "ldr r4, _0813C560\n\t"
            "ldrb r0, [r4]\n\t"
            "bl PutWindowTilemap\n\t"
            "ldrb r0, [r4]\n\t"
            "movs r1, #3\n\t"
            "bl CopyWindowToVram\n\t"
            "add sp, #0xc\n\t"
            "pop {r3, r4}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_0813C560: .4byte gRecordsWindowId\n\t"
            "_0813C564: .4byte sLinkBattleRecordsWindow\n\t"
            "_0813C568: .4byte gStringVar4\n\t"
            "_0813C56C: .4byte gText_PlayersBattleResults\n\t"
            "_0813C570: .4byte gSaveBlock1Ptr\n\t"
            "_0813C574: .4byte 0x00003150\n\t"
            "_0813C578: .4byte gText_WinLoseDraw\n\t"
            ".syntax divided");
}

#else
// 可读的 C 版本（NONMATCHING）：与汇编版语义相同（JP 用固定标题 x、2 参数
// PrintLinkBattleRecord），但不保证逐字节一致。启用方式见 include/config.h。
void ShowLinkBattleRecords(void)
{
    s32 i;

    gRecordsWindowId = AddWindow(&sLinkBattleRecordsWindow);
    DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, PIXEL_FILL(1));
    StringExpandPlaceholders(gStringVar4, gText_PlayersBattleResults);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, 0x30, 1, 0, NULL);
    PrintLinkBattleWinsLossesDraws(gSaveBlock1Ptr->linkBattleRecords.entries);
    StringExpandPlaceholders(gStringVar4, gText_WinLoseDraw);
    AddTextPrinterParameterized(gRecordsWindowId, FONT_NORMAL, gStringVar4, 0x50, 0x2A, 0, NULL);

    for (i = 0; i < LINK_B_RECORDS_COUNT; i++)
        PrintLinkBattleRecord(&gSaveBlock1Ptr->linkBattleRecords.entries[i], 7 + (i * 2));

    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, COPYWIN_FULL);
}
#endif

void RemoveRecordsWindow(void)
{
    ClearStdWindowAndFrame(gRecordsWindowId, FALSE);
    RemoveWindow(gRecordsWindowId);
}

static void Task_TrainerHillWaitForPaletteFade(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_CloseTrainerHillRecordsOnButton;
}

static void Task_CloseTrainerHillRecordsOnButton(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        task->func = Task_BeginPaletteFade;
    }
}

static void Task_BeginPaletteFade(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_ExitTrainerHillRecords;
}

static void Task_ExitTrainerHillRecords(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
        Free(sTilemapBuffer);
        RemoveTrainerHillRecordsWindow(0);
        FreeAllWindowBuffers();
        DestroyTask(taskId);
    }
}

static void RemoveTrainerHillRecordsWindow(u8 windowId)
{
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
    ClearWindowTilemap(windowId);
    CopyWindowToVram(windowId, COPYWIN_GFX);
    RemoveWindow(windowId);
}

static void ClearVramOamPlttRegs(void)
{
    DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
    DmaClear32(3, OAM, OAM_SIZE);
    DmaClear16(3, PLTT, PLTT_SIZE);

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void ClearTasksAndGraphicalStructs(void)
{
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    FreeAllSpritePalettes();
}

static void ResetBgCoordinates(void)
{
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
}

static void SetDispcntReg(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_1D_MAP);
}

static void LoadTrainerHillRecordsWindowGfx(u8 bgId)
{
    LoadBgTiles(bgId, sTrainerHillWindowTileset, sizeof(sTrainerHillWindowTileset), 0);
    CopyToBgTilemapBufferRect(bgId, sTrainerHillWindowTilemap, 0, 0, 0x20, 0x20);
    LoadPalette(sTrainerHillWindowPalette, BG_PLTT_ID(0), sizeof(sTrainerHillWindowPalette));
}

static void VblankCB_TrainerHillRecords(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MainCB2_TrainerHillRecords(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void ShowTrainerHillRecords(void)
{
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_ShowTrainerHillRecords);
}

static void CB2_ShowTrainerHillRecords(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ClearVramOamPlttRegs();
        gMain.state++;
        break;
    case 1:
        ClearTasksAndGraphicalStructs();
        gMain.state++;
        break;
    case 2:
        sTilemapBuffer = AllocZeroed(BG_SCREEN_SIZE);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sTrainerHillRecordsBgTemplates, ARRAY_COUNT(sTrainerHillRecordsBgTemplates));
        SetBgTilemapBuffer(3, sTilemapBuffer);
        ResetBgCoordinates();
        gMain.state++;
        break;
    case 3:
        LoadTrainerHillRecordsWindowGfx(3);
        LoadPalette(GetTextWindowPalette(0), BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 4:
        if (IsDma3ManagerBusyWithBgCopy() != TRUE)
        {
            ShowBg(0);
            ShowBg(3);
            CopyBgTilemapBufferToVram(3);
            gMain.state++;
        }
        break;
    case 5:
        InitWindows(sTrainerHillRecordsWindowTemplates);
        DeactivateAllTextPrinters();
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        SetDispcntReg();
        SetVBlankCallback(VblankCB_TrainerHillRecords);
        PrintOnTrainerHillRecordsWindow();
        CreateTask(Task_TrainerHillWaitForPaletteFade, 8);
        SetMainCallback2(MainCB2_TrainerHillRecords);
        gMain.state = 0;
        break;
    }
}
