#include "global.h"
#include "battle.h"
#include "battle_ai_script_commands.h"
#include "battle_anim.h"
#include "battle_bg.h"
#include "battle_controllers.h"
#include "battle_main.h"
#include "battle_message.h"
#include "battle_scripts.h"
#include "battle_setup.h"
#include "bg.h"
#include "cable_club.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "gba/m4a_internal.h"
#include "link.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "recorded_battle.h"
#include "safari_zone.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle.h"
#include "constants/battle_anim.h"
#include "constants/abilities.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_string_ids.h"
#include "constants/berry.h"
#include "constants/battle_move_effects.h"
#include "constants/flags.h"
#include "constants/global.h"
#include "constants/hold_effects.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"

// JP: battle globals live at fixed EWRAM/IWRAM addresses (sym files).
extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;
extern u16 gBattle_WIN1H;
extern u16 gBattle_WIN1V;
extern u16 gBattle_BG0_X, gBattle_BG0_Y;
extern u16 gBattle_BG1_X, gBattle_BG1_Y;
extern u16 gBattle_BG2_X, gBattle_BG2_Y;
extern u16 gBattle_BG3_X, gBattle_BG3_Y;
extern u8 gBattleTerrain;
extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;
extern struct MultiPartnerMenuPokemon *sMultiPartnerPartyBuffer;
extern struct ScanlineEffectParams sIntroScanlineParams16Bit;
extern void sub_08185CDC(void); // JP recorded-battle helper (US: RecordedBattle_ClearFrontierPassFlag)
extern void sub_08184D04(void); // JP recorded-battle helper (US: RecordedBattle_SetTrainerInfo)
extern void sub_0814FA04(const u8 *text, u8 windowId); // JP BattlePutTextOnWindow equivalent
extern void TryGetStatusString(const u8 *text); // JP text-expand helper (US: BattleStringExpandPlaceholdersToDisplayedString)
extern const struct BgTemplate gBattleBgTemplates[];
extern const struct MonCoords gCastformFrontSpriteCoords[];
extern const s8 sCenterToCornerVecXs[];
extern u32 sFlickerArray[];
extern u8 sUnusedBattlersArray[];
void TurnValuesCleanUp(bool8 var0);
extern void RunTurnActionsFunctions(void); // JP asm 0x0803D488 (US: same name)
extern void RunBattleScriptCommands(void); // JP asm 0x0803D45C (register-sensitive, kept in asm)
extern void (*const sTurnActionsFuncsTable[])(void); // JP data 0x082EC600 (14 B_ACTION_* entries)
extern void (*const gBattleScriptingCommandsTable[])(void); // JP data 0x082EC694 (249 B_SCR_OP_* entries)
extern void (*gCB2_AfterEvolution)(void); // JP IWRAM 0x03005F28
static void SpriteCB_UnusedBattleInit_Main(struct Sprite *sprite);

static void CB2_InitBattleInternal(void);
static void CB2_PreInitIngamePlayerPartnerBattle(void);
static void CB2_HandleStartMultiPartnerBattle(void);
static void CB2_HandleStartMultiBattle(void);
static void CB2_HandleStartBattle(void);
void BattleIntroOpponent1SendsOutMonAnimation(void);
void BattleIntroPlayer1SendsOutMonAnimation(void);
void BattleTurnPassed(void);
u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer);
void SetAllPlayersBerryData(void);
extern void CB2_PreInitMultiBattle(void);
void BattleIntroPrepareBackgroundSlide(void);
void BattleStartClearSetData(void);
u8 IsRunningFromBattleImpossible(void);
void TryEvolvePokemon(void);
bool8 TryRunFromBattle(u8 battler);
u8 GetWhoStrikesFirst(u8 battler1, u8 battler2, bool8 ignoreChosenMoves);
void HandleEndTurn_FinishBattle(void);
void SetPlayerBerryDataInBattleStruct(void);
static void CB2_EndLinkBattle(void);
static void EndLinkBattleInSteps(void);
static void CB2_InitAskRecordBattle(void);
static void CB2_AskRecordBattle(void);
static void AskRecordBattle(void);
static void SpriteCB_MoveWildMonToRight(struct Sprite *sprite);
static void SpriteCB_WildMonShowHealthbox(struct Sprite *sprite);
static void SpriteCB_WildMonAnimate(struct Sprite *sprite);
static void SpriteCB_Flicker(struct Sprite *sprite);
void SpriteCB_AnimFaintOpponent(struct Sprite *sprite);
static void SpriteCB_BlinkVisible(struct Sprite *sprite);
static void SpriteCB_Idle(struct Sprite *sprite);
static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite);
void SpriteCB_BounceEffect(struct Sprite *sprite);
static void SpriteCB_TrainerThrowObject_Main(struct Sprite *sprite);
static void BattleMainCB1(void);
static void BattleIntroGetMonsData(void);
static void BattleIntroPrintPlayerSendsOut(void);
static void BattleIntroPrintWildMonAttacked(void);
static void BattleIntroPrintOpponentSendsOut(void);
static void CheckFocusPunch_ClearVarsBeforeTurnStarts(void);
static void FreeResetData_ReturnToOvOrDoEvolutions(void);
static void WaitForEvoSceneToFinish(void);
static void ReturnFromBattleToOverworld(void);
extern void SetMultiPartnerMenuParty(u8 offset);
static void BufferPartyVsScreenHealth_AtStart(void);
static void FindLinkBattleMaster(u8 numPlayers, u8 multiPlayerId);

void CB2_InitBattle(void)
{
    MoveSaveBlocks_ResetHeap();
    AllocateBattleResources();
    AllocateBattleSpritesData();
    AllocateMonSpritesGfx();
    sub_08185CDC();

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            CB2_InitBattleInternal();
        }
        else if (!(gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER))
        {
            HandleLinkBattleSetup();
            SetMainCallback2(CB2_PreInitMultiBattle);
        }
        else
        {
            SetMainCallback2(CB2_PreInitIngamePlayerPartnerBattle);
        }
        gBattleCommunication[MULTIUSE_STATE] = 0;
    }
    else
    {
        CB2_InitBattleInternal();
    }
}

static void CB2_InitBattleInternal(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);

    CpuFill32(0, (void *)(VRAM), VRAM_SIZE);

    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1));
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);

    gBattle_WIN0H = DISPLAY_WIDTH;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && gPartnerTrainerId != TRAINER_STEVEN_PARTNER)
    {
        gBattle_WIN0V = DISPLAY_HEIGHT - 1;
        gBattle_WIN1H = DISPLAY_WIDTH;
        gBattle_WIN1V = 32;
    }
    else
    {
        gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1);
        ScanlineEffect_Clear();

        for (i = 0; i < DISPLAY_HEIGHT / 2; i++)
        {
            gScanlineEffectRegBuffers[0][i] = 0xF0;
            gScanlineEffectRegBuffers[1][i] = 0xF0;
        }

        for (; i < DISPLAY_HEIGHT; i++)
        {
            gScanlineEffectRegBuffers[0][i] = 0xFF10;
            gScanlineEffectRegBuffers[1][i] = 0xFF10;
        }

        ScanlineEffect_SetParams(sIntroScanlineParams16Bit);
    }

    ResetPaletteFade();
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;

    // JP: BattleSetup_GetEnvironmentId result is stored into the byte at
    // 0x02022C94 (gBattleTerrain), which the JP ROM uses for both the battle
    // terrain and the battle environment.
    gBattleTerrain = BattleSetup_GetEnvironmentId();
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        gBattleTerrain = BATTLE_ENVIRONMENT_BUILDING;

    InitBattleBgsVideo();
    LoadBattleTextboxAndBackground();
    ResetSpriteData();
    ResetTasks();
    DrawBattleEntryBackground();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
    SetVBlankCallback(VBlankCB_Battle);
    SetUpBattleVarsAndBirchZigzagoon();

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
        SetMainCallback2(CB2_HandleStartMultiPartnerBattle);
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        SetMainCallback2(CB2_HandleStartMultiPartnerBattle);
    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
        SetMainCallback2(CB2_HandleStartMultiBattle);
    else
        SetMainCallback2(CB2_HandleStartBattle);

    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)))
    {
        CreateNPCTrainerParty(&gEnemyParty[0], gTrainerBattleOpponent_A, TRUE);
        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            CreateNPCTrainerParty(&gEnemyParty[PARTY_SIZE / 2], gTrainerBattleOpponent_B, FALSE);
        SetWildMonHeldItem();
    }

    gMain.inBattle = TRUE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
        AdjustFriendship(&gPlayerParty[i], FRIENDSHIP_EVENT_LEAGUE_BATTLE);

    gBattleCommunication[MULTIUSE_STATE] = 0;
}

#define BUFFER_PARTY_VS_SCREEN_STATUS(party, flags, i)                      \
    for ((i) = 0; (i) < PARTY_SIZE; (i)++)                                  \
    {                                                                       \
        u16 species = GetMonData(&(party)[(i)], MON_DATA_SPECIES_OR_EGG);   \
        u16 hp = GetMonData(&(party)[(i)], MON_DATA_HP);                    \
        u32 status = GetMonData(&(party)[(i)], MON_DATA_STATUS);            \
                                                                            \
        if (species == SPECIES_NONE)                                        \
            continue;                                                       \
                                                                            \
        /* Is healthy mon? */                                               \
        if (species != SPECIES_EGG && hp != 0 && status == 0)               \
            (flags) |= 1 << (i) * 2;                                        \
                                                                            \
        if (species == SPECIES_NONE) /* Redundant */                        \
            continue;                                                       \
                                                                            \
        /* Is Egg or statused? */                                           \
        if (hp != 0 && (species == SPECIES_EGG || status != 0))             \
            (flags) |= 2 << (i) * 2;                                        \
                                                                            \
        if (species == SPECIES_NONE) /* Redundant */                        \
            continue;                                                       \
                                                                            \
        /* Is fainted? */                                                   \
        if (species != SPECIES_EGG && hp == 0)                              \
            (flags) |= 3 << (i) * 2;                                        \
    }

// For Vs Screen at link battle start
static void BufferPartyVsScreenHealth_AtStart(void)
{
    u16 flags = 0;
    s32 i;

    BUFFER_PARTY_VS_SCREEN_STATUS(gPlayerParty, flags, i);
    gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsLo = flags;
    *(&gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi) = flags >> 8;
    gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi |= FlagGet(FLAG_SYS_FRONTIER_PASS) << 7;
}

static void FindLinkBattleMaster(u8 numPlayers, u8 multiPlayerId)
{
    u8 found = 0;

    // If player 1 is playing the minimum version, player 1 is master.
    if (gBlockRecvBuffer[0][0] == 0x100)
    {
        if (multiPlayerId == 0)
            gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
        else
            gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
        found++;
    }

    if (found == 0)
    {
        // If multiple different versions are being used, player 1 is master.
        s32 i;

        for (i = 0; i < numPlayers; i++)
        {
            if (gBlockRecvBuffer[0][0] != gBlockRecvBuffer[i][0])
                break;
        }

        if (i == numPlayers)
        {
            if (multiPlayerId == 0)
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
            else
                gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
            found++;
        }

        if (found == 0)
        {
            // Lowest index player with the highest game version is master.
            for (i = 0; i < numPlayers; i++)
            {
                if (gBlockRecvBuffer[i][0] == 0x300 && i != multiPlayerId)
                {
                    if (i < multiPlayerId)
                        break;
                }
                if (gBlockRecvBuffer[i][0] > 0x300 && i != multiPlayerId)
                    break;
            }

            if (i == numPlayers)
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER | BATTLE_TYPE_TRAINER;
            else
                gBattleTypeFlags |= BATTLE_TYPE_TRAINER;
        }
    }
}

static void CB2_HandleStartBattle(void)
{
    u8 playerMultiplayerId;
    u8 enemyMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;
    enemyMultiplayerId = playerMultiplayerId ^ BIT_SIDE;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            FillAroundBattleWindows();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();

                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    {
                        gLinkPlayers[0].id = 0;
                        gLinkPlayers[1].id = 1;
                    }

                    SendBlock(BitmaskAllOtherLinkPlayers(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
                    gBattleCommunication[MULTIUSE_STATE] = 2;
                }
                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
            gBattleCommunication[MULTIUSE_STATE] = 15;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            u8 taskId;

            ResetBlockReceivedFlags();
            FindLinkBattleMaster(2, playerMultiplayerId);
            SetAllPlayersBerryData();
            taskId = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsLo | (gBattleStruct->multiBuffer.linkBattlerHeader.vsScreenHealthFlagsHi << 8);
            gTasks[taskId].data[4] = gBlockRecvBuffer[enemyMultiplayerId][1];
            RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[playerMultiplayerId][1]);
            RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[enemyMultiplayerId][1]);
            SetDeoxysStats();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        // Link battle, send/receive party PokÃ©mon 2 at a time
        if (IsLinkTaskFinished())
        {
            // Send PokÃ©mon 1-2
            SendBlock(BitmaskAllOtherLinkPlayers(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv PokÃ©mon 1-2
            ResetBlockReceivedFlags();
            memcpy(gEnemyParty, gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (IsLinkTaskFinished())
        {
            // Send PokÃ©mon 3-4
            SendBlock(BitmaskAllOtherLinkPlayers(), &gPlayerParty[2], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv PokÃ©mon 3-4
            ResetBlockReceivedFlags();
            memcpy(&gEnemyParty[2], gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (IsLinkTaskFinished())
        {
            // Send PokÃ©mon 5-6
            SendBlock(BitmaskAllOtherLinkPlayers(), &gPlayerParty[4], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv PokÃ©mon 5-6
            ResetBlockReceivedFlags();
            memcpy(&gEnemyParty[4], gBlockRecvBuffer[enemyMultiplayerId], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        InitBattleControllers();
        sub_08184D04();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            // Check if both players are using Emerald
            // to determine if the recorded battle rng
            // seed needs to be sent
            s32 i;
            for (i = 0; i < 2 && (gLinkPlayers[i].version & 0xFF) == VERSION_EMERALD; i++);

            if (i == 2)
                gBattleCommunication[MULTIUSE_STATE] = 16;
            else
                gBattleCommunication[MULTIUSE_STATE] = 18;
        }
        else
        {
            gBattleCommunication[MULTIUSE_STATE] = 18;
        }
        break;
    case 16:
        // Both players are using Emerald, send rng seed for recorded battle
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 17:
        // Receive rng seed for recorded battle (only read it if partner is the link master)
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
                memcpy(&gRecordedBattleRngSeed, gBlockRecvBuffer[enemyMultiplayerId], sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 18:
        // Finish, start battle
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
        }
        break;
    // Introduce short delays between sending party PokÃ©mon for link
    case 5:
    case 9:
    case 13:
        gBattleCommunication[MULTIUSE_STATE]++;
        gBattleCommunication[1] = 1;
    case 6:
    case 10:
    case 14:
        if (--gBattleCommunication[1] == 0)
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    }
}

static void CB2_HandleStartMultiPartnerBattle(void)
{
    u8 playerMultiplayerId;
    u8 partnerMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;
    partnerMultiplayerId = playerMultiplayerId ^ BIT_SIDE;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            FillAroundBattleWindows();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        // fall through
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers)
            {
                gLinkPlayers[0].id = 0;
                gLinkPlayers[1].id = 2;
                gLinkPlayers[2].id = 1;
                gLinkPlayers[3].id = 3;
                GetFrontierTrainerName(gLinkPlayers[2].name, gTrainerBattleOpponent_A);
                GetFrontierTrainerName(gLinkPlayers[3].name, gTrainerBattleOpponent_B);

                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();
                    SendBlock(BitmaskAllOtherLinkPlayers(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
                    gBattleCommunication[MULTIUSE_STATE] = 2;
                }

                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
            gBattleCommunication[MULTIUSE_STATE] = 13;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            u8 taskId;

            ResetBlockReceivedFlags();
            FindLinkBattleMaster(2, playerMultiplayerId);
            SetAllPlayersBerryData();
            taskId = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[taskId].data[1] = 0x10E;
            gTasks[taskId].data[2] = 0x5A;
            gTasks[taskId].data[5] = 0;
            gTasks[taskId].data[3] = 0x145;
            gTasks[taskId].data[4] = 0x145;
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 3:
        // Link battle, send/receive party PokÃ©mon in groups
        if (IsLinkTaskFinished())
        {
            // Send PokÃ©mon 1-2
            SendBlock(BitmaskAllOtherLinkPlayers(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv partner's PokÃ©mon 1-2, and copy partner's and own PokÃ©mon into party positions
            ResetBlockReceivedFlags();
            if (gLinkPlayers[playerMultiplayerId].id != 0)
            {
                memcpy(gPlayerParty, gBlockRecvBuffer[partnerMultiplayerId], sizeof(struct Pokemon) * 2);
                memcpy(&gPlayerParty[MULTI_PARTY_SIZE], gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
            }
            else
            {
                memcpy(gPlayerParty, gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon) * 2);
                memcpy(&gPlayerParty[MULTI_PARTY_SIZE], gBlockRecvBuffer[partnerMultiplayerId], sizeof(struct Pokemon) * 2);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
        {
            // Send PokÃ©mon 3
            SendBlock(BitmaskAllOtherLinkPlayers(), &gPlayerParty[2], sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv partner's PokÃ©mon 3, and copy partner's and own PokÃ©mon into party positions
            ResetBlockReceivedFlags();
            if (gLinkPlayers[playerMultiplayerId].id != 0)
            {
                memcpy(&gPlayerParty[2], gBlockRecvBuffer[partnerMultiplayerId], sizeof(struct Pokemon));
                memcpy(&gPlayerParty[2 + MULTI_PARTY_SIZE], gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon));
            }
            else
            {
                memcpy(&gPlayerParty[2], gBlockRecvBuffer[playerMultiplayerId], sizeof(struct Pokemon));
                memcpy(&gPlayerParty[2 + MULTI_PARTY_SIZE], gBlockRecvBuffer[partnerMultiplayerId], sizeof(struct Pokemon));
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (IsLinkTaskFinished())
        {
            // Send enemy PokÃ©mon 1-2 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), gEnemyParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv enemy PokÃ©mon 1-2 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(gEnemyParty, gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if (IsLinkTaskFinished())
        {
            // Send enemy PokÃ©mon 3-4 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), &gEnemyParty[2], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 10:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv enemy PokÃ©mon 3-4 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(&gEnemyParty[2], gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 11:
        if (IsLinkTaskFinished())
        {
            // Send enemy PokÃ©mon 5-6 to partner
            SendBlock(BitmaskAllOtherLinkPlayers(), &gEnemyParty[4], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 12:
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            // Recv enemy PokÃ©mon 5-6 (if not master)
            ResetBlockReceivedFlags();
            if (GetMultiplayerId() != 0)
                memcpy(&gEnemyParty[4], gBlockRecvBuffer[0], sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 13:
        InitBattleControllers();
        sub_08184D04();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            gBattleCommunication[MULTIUSE_STATE] = 14;
        else
            gBattleCommunication[MULTIUSE_STATE] = 16;
        break;
    case 14:
        // Send rng seed for recorded battle
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), &gRecordedBattleRngSeed, sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 15:
        // Receive rng seed for recorded battle (only read it if partner is the link master)
        if ((GetBlockReceivedStatus() & 3) == 3)
        {
            ResetBlockReceivedFlags();
            if (!(gBattleTypeFlags & BATTLE_TYPE_IS_MASTER))
                memcpy(&gRecordedBattleRngSeed, gBlockRecvBuffer[partnerMultiplayerId], sizeof(gRecordedBattleRngSeed));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 16:
        // Finish, start battle
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            TrySetLinkBattleTowerEnemyPartyLevel();
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
        }
        break;
    }
}
static void CB2_PreInitIngamePlayerPartnerBattle(void)
{
    u32 *savedBattleTypeFlags;
    void (**savedCallback)(void);

    savedCallback = &gBattleStruct->savedCallback;
    savedBattleTypeFlags = &gBattleStruct->savedBattleTypeFlags;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        sMultiPartnerPartyBuffer = Alloc(sizeof(gMultiPartnerParty));
        SetMultiPartnerMenuParty(MULTI_PARTY_SIZE);
        gBattleCommunication[MULTIUSE_STATE]++;
        *savedCallback = gMain.savedCallback;
        *savedBattleTypeFlags = gBattleTypeFlags;
        gMain.savedCallback = CB2_PreInitIngamePlayerPartnerBattle;
        ShowPartyMenuToShowcaseMultiBattleParty();
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            gBattleCommunication[MULTIUSE_STATE] = 2;
            gBattleTypeFlags = *savedBattleTypeFlags;
            gMain.savedCallback = *savedCallback;
            SetMainCallback2(CB2_InitBattleInternal);
            FREE_AND_SET_NULL(sMultiPartnerPartyBuffer);
        }
        break;
    }
}

static void CB2_HandleStartMultiBattle(void)
{
    u8 playerMultiplayerId;
    s32 id;
    u8 var;

    playerMultiplayerId = GetMultiplayerId();
    gBattleScripting.multiplayerId = playerMultiplayerId;

    RunTasks();
    AnimateSprites();
    BuildOamBuffer();

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            ShowBg(0);
            ShowBg(1);
            ShowBg(2);
            ShowBg(3);
            FillAroundBattleWindows();
            gBattleCommunication[MULTIUSE_STATE] = 1;
        }
        if (gWirelessCommType)
            LoadWirelessStatusIndicatorSpriteGfx();
        break;
    case 1:
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (gReceivedRemoteLinkPlayers)
            {
                if (IsLinkTaskFinished())
                {
                    // 0x300
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureLo) = 0;
                    *(&gBattleStruct->multiBuffer.linkBattlerHeader.versionSignatureHi) = 3;
                    BufferPartyVsScreenHealth_AtStart();
                    SetPlayerBerryDataInBattleStruct();

                    SendBlock(BitmaskAllOtherLinkPlayers(), &gBattleStruct->multiBuffer.linkBattlerHeader, sizeof(gBattleStruct->multiBuffer.linkBattlerHeader));
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
                if (gWirelessCommType)
                    CreateWirelessStatusIndicatorSprite(0, 0);
            }
        }
        else
        {
            if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
                gBattleTypeFlags |= BATTLE_TYPE_IS_MASTER;
            gBattleCommunication[MULTIUSE_STATE] = 7;
            SetAllPlayersBerryData();
        }
        break;
    case 2:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            FindLinkBattleMaster(4, playerMultiplayerId);
            SetAllPlayersBerryData();
            SetDeoxysStats();
            var = CreateTask(InitLinkBattleVsScreen, 0);
            gTasks[var].data[1] = 0x10E;
            gTasks[var].data[2] = 0x5A;
            gTasks[var].data[5] = 0;
            gTasks[var].data[3] = 0;
            gTasks[var].data[4] = 0;

            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                RecordedBattle_SetFrontierPassFlagFromHword(gBlockRecvBuffer[id][1]);
                switch (gLinkPlayers[id].id)
                {
                case 0:
                    gTasks[var].data[3] |= gBlockRecvBuffer[id][1] & 0x3F;
                    break;
                case 1:
                    gTasks[var].data[4] |= gBlockRecvBuffer[id][1] & 0x3F;
                    break;
                case 2:
                    gTasks[var].data[3] |= (gBlockRecvBuffer[id][1] & 0x3F) << 6;
                    break;
                case 3:
                    gTasks[var].data[4] |= (gBlockRecvBuffer[id][1] & 0x3F) << 6;
                    break;
                }
            }
            ZeroEnemyPartyMons();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        else
        {
            break;
        }
        // fall through
    case 3:
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), gPlayerParty, sizeof(struct Pokemon) * 2);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                if (id == playerMultiplayerId)
                {
                    switch (gLinkPlayers[id].id)
                    {
                    case 0:
                    case 3:
                        memcpy(gPlayerParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                        break;
                    case 1:
                    case 2:
                        memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                        break;
                    }
                }
                else
                {
                    if ((!(gLinkPlayers[id].id & 1) && !(gLinkPlayers[playerMultiplayerId].id & 1))
                     || ((gLinkPlayers[id].id & 1) && (gLinkPlayers[playerMultiplayerId].id & 1)))
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(gPlayerParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        case 1:
                        case 2:
                            memcpy(gPlayerParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        }
                    }
                    else
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(gEnemyParty, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        case 1:
                        case 2:
                            memcpy(gEnemyParty + MULTI_PARTY_SIZE, gBlockRecvBuffer[id], sizeof(struct Pokemon) * 2);
                            break;
                        }
                    }
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 5:
        if (IsLinkTaskFinished())
        {
            SendBlock(BitmaskAllOtherLinkPlayers(), &gPlayerParty[2], sizeof(struct Pokemon));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 6:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (id = 0; id < MAX_LINK_PLAYERS; id++)
            {
                if (id == playerMultiplayerId)
                {
                    switch (gLinkPlayers[id].id)
                    {
                    case 0:
                    case 3:
                        memcpy(&gPlayerParty[2], gBlockRecvBuffer[id], sizeof(struct Pokemon));
                        break;
                    case 1:
                    case 2:
                        memcpy(&gPlayerParty[2 + MULTI_PARTY_SIZE], gBlockRecvBuffer[id], sizeof(struct Pokemon));
                        break;
                    }
                }
                else
                {
                    if ((!(gLinkPlayers[id].id & 1) && !(gLinkPlayers[playerMultiplayerId].id & 1))
                     || ((gLinkPlayers[id].id & 1) && (gLinkPlayers[playerMultiplayerId].id & 1)))
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(&gPlayerParty[2], gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        case 1:
                        case 2:
                            memcpy(&gPlayerParty[2 + MULTI_PARTY_SIZE], gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        }
                    }
                    else
                    {
                        switch (gLinkPlayers[id].id)
                        {
                        case 0:
                        case 3:
                            memcpy(&gEnemyParty[2], gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        case 1:
                        case 2:
                            memcpy(&gEnemyParty[2 + MULTI_PARTY_SIZE], gBlockRecvBuffer[id], sizeof(struct Pokemon));
                            break;
                        }
                    }
                }
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        InitBattleControllers();
        sub_08184D04();
        gBattleCommunication[SPRITES_INIT_STATE1] = 0;
        gBattleCommunication[SPRITES_INIT_STATE2] = 0;
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            for (id = 0; id < MAX_LINK_PLAYERS && (gLinkPlayers[id].version & 0xFF) == VERSION_EMERALD; id++);

            if (id == MAX_LINK_PLAYERS)
                gBattleCommunication[MULTIUSE_STATE] = 8;
            else
                gBattleCommunication[MULTIUSE_STATE] = 10;
        }
        else
        {
            gBattleCommunication[MULTIUSE_STATE] = 10;
        }
        break;
    case 8:
        if (IsLinkTaskFinished())
        {
            u32 *ptr = gBattleStruct->multiBuffer.battleVideo;
            ptr[0] = gBattleTypeFlags;
            ptr[1] = gRecordedBattleRngSeed; // UB: overwrites berry data
            SendBlock(BitmaskAllOtherLinkPlayers(), ptr, sizeof(gBattleStruct->multiBuffer.battleVideo));
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 9:
        if ((GetBlockReceivedStatus() & 0xF) == 0xF)
        {
            ResetBlockReceivedFlags();
            for (var = 0; var < 4; var++)
            {
                u32 blockValue = gBlockRecvBuffer[var][0];
                if (blockValue & 4)
                {
                    memcpy(&gRecordedBattleRngSeed, &gBlockRecvBuffer[var][2], sizeof(gRecordedBattleRngSeed));
                    break;
                }
            }

            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 10:
        if (BattleInitAllSprites(&gBattleCommunication[SPRITES_INIT_STATE1], &gBattleCommunication[SPRITES_INIT_STATE2]))
        {
            gPreBattleCallback1 = gMain.callback1;
            gMain.callback1 = BattleMainCB1;
            SetMainCallback2(BattleMainCB2);
            if (gBattleTypeFlags & BATTLE_TYPE_LINK)
            {
                gTrainerBattleOpponent_A = TRAINER_LINK_OPPONENT;
                gBattleTypeFlags |= BATTLE_TYPE_LINK_IN_BATTLE;
            }
        }
        break;
    }
}

void BattleMainCB2(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();

    if (JOY_HELD(B_BUTTON) && gBattleTypeFlags & BATTLE_TYPE_RECORDED && RecordedBattle_CanStopPlayback())
    {
        // Player pressed B during recorded battle playback, end battle
        gSpecialVar_Result = gBattleOutcome = B_OUTCOME_PLAYER_TELEPORTED;
        ResetPaletteFadeControl();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_QuitRecordedBattle);
    }
}

static void FreeRestoreBattleData(void)
{
    gMain.callback1 = gPreBattleCallback1;
    gScanlineEffect.state = 3;
    gMain.inBattle = FALSE;
    ZeroEnemyPartyMons();
    m4aSongNumStop(SE_LOW_HEALTH);
    FreeMonSpritesGfx();
    FreeBattleSpritesData();
    FreeBattleResources();
}

void CB2_QuitRecordedBattle(void)
{
    UpdatePaletteFade();
    if (!gPaletteFade.active)
    {
        m4aMPlayStop(&gMPlayInfo_SE1);
        m4aMPlayStop(&gMPlayInfo_SE2);
        FreeRestoreBattleData();
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

#define sState data[0]
#define sDelay data[4]

static void SpriteCB_UnusedBattleInit(struct Sprite *sprite)
{
    sprite->sState = 0;
    sprite->callback = SpriteCB_UnusedBattleInit_Main;
}

static void SpriteCB_UnusedBattleInit_Main(struct Sprite *sprite)
{
    u16 *arr = (u16 *)gDecompressionBuffer;

    switch (sprite->sState)
    {
    case 0:
        sprite->sState++;
        sprite->data[1] = 0;
        sprite->data[2] = 0x281;
        sprite->data[3] = 0;
        sprite->sDelay = 1;
        // fall through
    case 1:
        sprite->sDelay--;
        if (sprite->sDelay == 0)
        {
            s32 i;
            s32 r2;
            s32 r0;

            sprite->sDelay = 2;
            r2 = sprite->data[1] + sprite->data[3] * 32;
            r0 = sprite->data[2] - sprite->data[3] * 32;
            for (i = 0; i < 29; i += 2)
            {
                arr[r2 + i] = 0x3D;
                arr[r0 + i] = 0x3D;
            }
            sprite->data[3]++;
            if (sprite->data[3] == 21)
            {
                sprite->sState++;
                sprite->data[1] = 32;
            }
        }
        break;
    case 2:
        sprite->data[1]--;
        if (sprite->data[1] == 20)
            SetMainCallback2(CB2_InitBattle);
        break;
    }
}


static void UNUSED HBlankCB_Battle(void)
{
    if (REG_VCOUNT < DISPLAY_HEIGHT && REG_VCOUNT >= 111)
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_SCREENBASE(24) | BGCNT_TXT256x512);
}

void VBlankCB_Battle(void)
{
    // Change gRngSeed every vblank unless the battle could be recorded.
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_FRONTIER | BATTLE_TYPE_RECORDED)))
        Random();

    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
    SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

void SpriteCallbackDummy_3(struct Sprite *sprite)
{
}

static void SpriteCB_VsLetter(struct Sprite *sprite)
{
    if (sprite->data[0] != 0)
        sprite->x = sprite->data[1] + ((sprite->data[2] & 0xFF00) >> 8);
    else
        sprite->x = sprite->data[1] - ((sprite->data[2] & 0xFF00) >> 8);

    sprite->data[2] += 0x180;

    if (sprite->affineAnimEnded)
    {
        FreeSpriteTilesByTag(ANIM_SPRITES_START);
        FreeSpritePaletteByTag(ANIM_SPRITES_START);
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

void SpriteCB_VsLetterInit(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 1);
    sprite->callback = SpriteCB_VsLetter;
    PlaySE(SE_MUGSHOT);
}

static void BufferPartyVsScreenHealth_AtEnd(u8 taskId)
{
    struct Pokemon *party1 = NULL;
    struct Pokemon *party2 = NULL;
    u8 multiplayerId = gBattleScripting.multiplayerId;
    u32 flags;
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        switch (gLinkPlayers[multiplayerId].id)
        {
        case 0:
        case 2:
            party1 = gPlayerParty;
            party2 = gEnemyParty;
            break;
        case 1:
        case 3:
            party1 = gEnemyParty;
            party2 = gPlayerParty;
            break;
        }
    }
    else
    {
        party1 = gPlayerParty;
        party2 = gEnemyParty;
    }

    flags = 0;
    BUFFER_PARTY_VS_SCREEN_STATUS(party1, flags, i);
    gTasks[taskId].data[3] = flags;

    flags = 0;
    BUFFER_PARTY_VS_SCREEN_STATUS(party2, flags, i);
    gTasks[taskId].data[4] = flags;
}

void CB2_InitEndLinkBattle(void)
{
    s32 i;
    u8 taskId;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    gBattleTypeFlags &= ~BATTLE_TYPE_LINK_IN_BATTLE;

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        SetMainCallback2(gMain.savedCallback);
        FreeBattleResources();
        FreeBattleSpritesData();
        FreeMonSpritesGfx();
    }
    else
    {
        CpuFill32(0, (void *)(VRAM), VRAM_SIZE);
        SetGpuReg(REG_OFFSET_MOSAIC, 0);
        SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1));
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        gBattle_WIN0H = DISPLAY_WIDTH;
        gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2 + 1);
        ScanlineEffect_Clear();

        i = 0;
        while (i < 80)
        {
            gScanlineEffectRegBuffers[0][i] = 0xF0;
            gScanlineEffectRegBuffers[1][i] = 0xF0;
            i++;
        }

        while (i < 160)
        {
            gScanlineEffectRegBuffers[0][i] = 0xFF10;
            gScanlineEffectRegBuffers[1][i] = 0xFF10;
            i++;
        }

        ResetPaletteFade();

        gBattle_BG0_X = 0;
        gBattle_BG0_Y = 0;
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 0;
        gBattle_BG2_X = 0;
        gBattle_BG2_Y = 0;
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;

        InitBattleBgsVideo();
        LoadCompressedPalette(gBattleTextboxPalette, BG_PLTT_ID(0), 2 * PLTT_SIZE_4BPP);
        LoadBattleMenuWindowGfx();
        ResetSpriteData();
        ResetTasks();
        DrawBattleEntryBackground();
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
        SetVBlankCallback(VBlankCB_Battle);

        // Show end Vs screen with battle results
        taskId = CreateTask(InitLinkBattleVsScreen, 0);
        gTasks[taskId].data[1] = 0x10E;
        gTasks[taskId].data[2] = 0x5A;
        gTasks[taskId].data[5] = 1;
        BufferPartyVsScreenHealth_AtEnd(taskId);

        SetMainCallback2(CB2_EndLinkBattle);
        gBattleCommunication[MULTIUSE_STATE] = 0;
    }
}

static void CB2_EndLinkBattle(void)
{
    EndLinkBattleInSteps();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

static void EndLinkBattleInSteps(void)
{
    s32 i;

    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        gBattleCommunication[1] = 0xFF;
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (--gBattleCommunication[1] == 0)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 2:
        if (!gPaletteFade.active)
        {
            u8 battlerCount;

            gMain.anyLinkBattlerHasFrontierPass = GetRecordedBattleFrontierFacility();

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                battlerCount = 4;
            else
                battlerCount = 2;

            for (i = 0; i < battlerCount && (gLinkPlayers[i].version & 0xFF) == VERSION_EMERALD; i++);

            if (!gSaveBlock2Ptr->frontier.disableRecordBattle && i == battlerCount)
            {
                if (FlagGet(FLAG_SYS_FRONTIER_PASS))
                {
                    // Ask player if they want to record the battle
                    FreeAllWindowBuffers();
                    SetMainCallback2(CB2_InitAskRecordBattle);
                }
                else if (!gMain.anyLinkBattlerHasFrontierPass)
                {
                    // No players can record this battle, end
                    SetMainCallback2(gMain.savedCallback);
                    FreeBattleResources();
                    FreeBattleSpritesData();
                    FreeMonSpritesGfx();
                }
                else if (gReceivedRemoteLinkPlayers == 0)
                {
                    // Player can't record battle but
                    // another player can, reconnect with them
                    CreateTask(Task_ReconnectWithLinkPlayers, 5);
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
                else
                {
                    gBattleCommunication[MULTIUSE_STATE]++;
                }
            }
            else
            {
                SetMainCallback2(gMain.savedCallback);
                FreeBattleResources();
                FreeBattleSpritesData();
                FreeMonSpritesGfx();
            }
        }
        break;
    case 3:
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);

        for (i = 0; i < 2; i++)
            LoadChosenBattleElement(i);

        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 4:
        if (!gPaletteFade.active)
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 5:
        if (!FuncIsActiveTask(Task_ReconnectWithLinkPlayers))
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 6:
        if (IsLinkTaskFinished() == TRUE)
        {
            SetLinkStandbyCallback();
            sub_0814FA04(gText_LinkStandby3, B_WIN_MSG);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 7:
        if (!IsTextPrinterActive(B_WIN_MSG))
        {
            if (IsLinkTaskFinished() == TRUE)
                gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case 8:
        if (!gWirelessCommType)
            SetCloseLinkCallback();
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 9:
        if (!gMain.anyLinkBattlerHasFrontierPass || gWirelessCommType || gReceivedRemoteLinkPlayers != 1)
        {
            gMain.anyLinkBattlerHasFrontierPass = FALSE;
            SetMainCallback2(gMain.savedCallback);
            FreeBattleResources();
            FreeBattleSpritesData();
            FreeMonSpritesGfx();
        }
        break;
    }
}

u32 GetBattleBgTemplateData(u8 arrayId, u8 caseId)
{
    u32 ret = 0;

    switch (caseId)
    {
    case 0:
        ret = gBattleBgTemplates[arrayId].bg;
        break;
    case 1:
        ret = gBattleBgTemplates[arrayId].charBaseIndex;
        break;
    case 2:
        ret = gBattleBgTemplates[arrayId].mapBaseIndex;
        break;
    case 3:
        ret = gBattleBgTemplates[arrayId].screenSize;
        break;
    case 4:
        ret = gBattleBgTemplates[arrayId].paletteMode;
        break;
    case 5: // Only this case is used
        ret = gBattleBgTemplates[arrayId].priority;
        break;
    case 6:
        ret = gBattleBgTemplates[arrayId].baseTile;
        break;
    }

    return ret;
}

static void CB2_InitAskRecordBattle(void)
{
    s32 i;

    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    CpuFill32(0, (void *)(VRAM), VRAM_SIZE);
    ResetPaletteFade();
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;
    InitBattleBgsVideo();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    LoadBattleMenuWindowGfx();

    for (i = 0; i < 2; i++)
        LoadChosenBattleElement(i);

    ResetSpriteData();
    ResetTasks();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = MAX_BATTLERS_COUNT;
    SetVBlankCallback(VBlankCB_Battle);
    SetMainCallback2(CB2_AskRecordBattle);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0x10, 0, RGB_BLACK);
    gBattleCommunication[MULTIUSE_STATE] = 0;
}

static void CB2_AskRecordBattle(void)
{
    AskRecordBattle();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    RunTasks();
}

// States for AskRecordBattle
#define STATE_INIT             0
#define STATE_LINK             1
#define STATE_WAIT_LINK        2
#define STATE_ASK_RECORD       3
#define STATE_PRINT_YES_NO     4
#define STATE_HANDLE_YES_NO    5
#define STATE_RECORD_NO        6
#define STATE_END_RECORD_NO    7
#define STATE_WAIT_END         8
#define STATE_END              9
#define STATE_RECORD_YES      10
#define STATE_RECORD_WAIT     11
#define STATE_END_RECORD_YES  12

static void AskRecordBattle(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case STATE_INIT:
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case STATE_LINK:
        if (gMain.anyLinkBattlerHasFrontierPass && gReceivedRemoteLinkPlayers == 0)
            CreateTask(Task_ReconnectWithLinkPlayers, 5);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case STATE_WAIT_LINK:
        if (!FuncIsActiveTask(Task_ReconnectWithLinkPlayers))
            gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case STATE_ASK_RECORD:
        if (!gPaletteFade.active)
        {
            // "Would you like to record your battle on your FRONTIER PASS?"
            sub_0814FA04(gText_RecordBattleToPass, B_WIN_MSG);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_PRINT_YES_NO:
        if (!IsTextPrinterActive(B_WIN_MSG))
        {
            HandleBattleWindow(YESNOBOX_X_Y, 0);
            sub_0814FA04(gText_BattleYesNoChoice, B_WIN_YESNO);
            gBattleCommunication[CURSOR_POSITION] = 1;
            BattleCreateYesNoCursorAt(1);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_HANDLE_YES_NO:
        if (JOY_NEW(DPAD_UP))
        {
            if (gBattleCommunication[CURSOR_POSITION] != 0)
            {
                // Moved cursor onto Yes
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 0;
                BattleCreateYesNoCursorAt(0);
            }
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                // Moved cursor onto No
                PlaySE(SE_SELECT);
                BattleDestroyYesNoCursorAt(gBattleCommunication[CURSOR_POSITION]);
                gBattleCommunication[CURSOR_POSITION] = 1;
                BattleCreateYesNoCursorAt(1);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (gBattleCommunication[CURSOR_POSITION] == 0)
            {
                // Selected Yes
                HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
                gBattleCommunication[1] = MoveRecordedBattleToSaveData();
                gBattleCommunication[MULTIUSE_STATE] = STATE_RECORD_YES;
            }
            else
            {
                // Selected No
                gBattleCommunication[MULTIUSE_STATE]++;
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_RECORD_NO:
        if (IsLinkTaskFinished() == TRUE)
        {
            HandleBattleWindow(YESNOBOX_X_Y, WINDOW_CLEAR);
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                // Other battlers may be recording, wait for them
                SetLinkStandbyCallback();
                sub_0814FA04(gText_LinkStandby3, B_WIN_MSG);
            }
            gBattleCommunication[MULTIUSE_STATE]++; // STATE_END_RECORD_NO
        }
        break;
    case STATE_WAIT_END:
        if (--gBattleCommunication[1] == 0)
        {
            if (gMain.anyLinkBattlerHasFrontierPass && !gWirelessCommType)
                SetCloseLinkCallback();
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_END:
        if (!gMain.anyLinkBattlerHasFrontierPass || gWirelessCommType || gReceivedRemoteLinkPlayers != 1)
        {
            gMain.anyLinkBattlerHasFrontierPass = FALSE;
            if (!gPaletteFade.active)
            {
                SetMainCallback2(gMain.savedCallback);
                FreeBattleResources();
                FreeBattleSpritesData();
                FreeMonSpritesGfx();
            }
        }
        break;
    case STATE_RECORD_YES:
        if (gBattleCommunication[1] == 1)
        {
            PlaySE(SE_SAVE);
            TryGetStatusString(gText_BattleRecordedOnPass);
            sub_0814FA04(gDisplayedStringBattle, B_WIN_MSG);
            gBattleCommunication[1] = 128; // Delay
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        else
        {
            TryGetStatusString(BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved);
            sub_0814FA04(gDisplayedStringBattle, B_WIN_MSG);
            gBattleCommunication[1] = 128; // Delay
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_RECORD_WAIT:
        if (IsLinkTaskFinished() == TRUE && !IsTextPrinterActive(B_WIN_MSG) && --gBattleCommunication[1] == 0)
        {
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                SetLinkStandbyCallback();
                sub_0814FA04(gText_LinkStandby3, B_WIN_MSG);
            }
            gBattleCommunication[MULTIUSE_STATE]++;
        }
        break;
    case STATE_END_RECORD_YES:
    case STATE_END_RECORD_NO:
        if (!IsTextPrinterActive(B_WIN_MSG))
        {
            if (gMain.anyLinkBattlerHasFrontierPass)
            {
                if (IsLinkTaskFinished() == TRUE)
                {
                    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                    gBattleCommunication[1] = 32; // Delay
                    gBattleCommunication[MULTIUSE_STATE] = STATE_WAIT_END;
                }

            }
            else
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gBattleCommunication[1] = 32; // Delay
                gBattleCommunication[MULTIUSE_STATE] = STATE_WAIT_END;
            }
        }
        break;
    }
}

#define sBattler            data[0]
#define sSpeciesId          data[2]

void SpriteCB_WildMon(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_MoveWildMonToRight;
    StartSpriteAnimIfDifferent(sprite, 0);
    BeginNormalPaletteFade(0x20000, 0, 10, 10, RGB(8, 8, 8));
}

static void SpriteCB_MoveWildMonToRight(struct Sprite *sprite)
{
    if ((gIntroSlideFlags & 1) == 0)
    {
        sprite->x2 += 2;
        if (sprite->x2 == 0)
        {
            sprite->callback = SpriteCB_WildMonShowHealthbox;
        }
    }
}

static void SpriteCB_WildMonShowHealthbox(struct Sprite *sprite)
{
    if (sprite->animEnded)
    {
        StartHealthboxSlideIn(sprite->sBattler);
        SetHealthboxSpriteVisible(gHealthboxSpriteIds[sprite->sBattler]);
        sprite->callback = SpriteCB_WildMonAnimate;
        StartSpriteAnimIfDifferent(sprite, 0);
        BeginNormalPaletteFade(0x20000, 0, 10, 0, RGB(8, 8, 8));
    }
}

static void SpriteCB_WildMonAnimate(struct Sprite *sprite)
{
    if (!gPaletteFade.active)
    {
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, FALSE, 1);
    }
}

void SpriteCallbackDummy_2(struct Sprite *sprite)
{
}

#define sNumFlickers data[3]
#define sDelay       data[4]

static void UNUSED SpriteCB_InitFlicker(struct Sprite *sprite)
{
    sprite->sNumFlickers = 6;
    sprite->sDelay = 1;
    sprite->callback = SpriteCB_Flicker;
}

static void SpriteCB_Flicker(struct Sprite *sprite)
{
    sprite->sDelay--;
    if (sprite->sDelay == 0)
    {
        sprite->sDelay = 8;
        sprite->invisible ^= 1;
        sprite->sNumFlickers--;
        if (sprite->sNumFlickers == 0)
        {
            sprite->invisible = FALSE;
            sprite->callback = SpriteCallbackDummy_2;
            sFlickerArray[0] = 0;
        }
    }
}

#undef sNumFlickers
#undef sDelay

void SpriteCB_FaintOpponentMon(struct Sprite *sprite)
{
    u8 battler = sprite->sBattler;
    u16 species;
    u8 yOffset;

    if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies != 0)
        species = gBattleSpritesDataPtr->battlerData[battler].transformSpecies;
    else
        species = sprite->sSpeciesId;

    GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);  // Unused return value.

    if (species == SPECIES_UNOWN)
    {
        u32 personalityValue = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_PERSONALITY);
        u16 unownForm = GET_UNOWN_LETTER(personalityValue);
        u16 unownSpecies;

        if (unownForm == 0)
            unownSpecies = SPECIES_UNOWN;  // Use the A Unown form.
        else
            unownSpecies = NUM_SPECIES + unownForm;  // Use one of the other Unown letters.

        yOffset = gMonFrontPicCoords[unownSpecies].y_offset;
    }
    else if (species == SPECIES_CASTFORM)
    {
        yOffset = gCastformFrontSpriteCoords[gBattleMonForms[battler]].y_offset;
    }
    else if (species > NUM_SPECIES)
    {
        yOffset = gMonFrontPicCoords[SPECIES_NONE].y_offset;
    }
    else
    {
        yOffset = gMonFrontPicCoords[species].y_offset;
    }

    sprite->data[3] = 8 - yOffset / 8;
    sprite->data[4] = 1;
    sprite->callback = SpriteCB_AnimFaintOpponent;
}

// Used when selecting a move, which can hit multiple targets, in double battles.
void SpriteCB_ShowAsMoveTarget(struct Sprite *sprite)
{
    sprite->data[3] = 8;
    sprite->data[4] = sprite->invisible;
    sprite->callback = SpriteCB_BlinkVisible;
}

static void SpriteCB_BlinkVisible(struct Sprite *sprite)
{
    if (--sprite->data[3] == 0)
    {
        sprite->invisible ^= 1;
        sprite->data[3] = 8;
    }
}

void SpriteCB_HideAsMoveTarget(struct Sprite *sprite)
{
    sprite->invisible = sprite->data[4];
    sprite->data[4] = FALSE;
    sprite->callback = SpriteCallbackDummy_2;
}

void SpriteCB_OpponentMonFromBall(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        if (!(gHitMarker & HITMARKER_NO_ANIMATIONS) || gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
        {
            if (HasTwoFramesAnimation(sprite->sSpeciesId))
                StartSpriteAnim(sprite, 1);
        }
        BattleAnimateFrontSprite(sprite, sprite->sSpeciesId, TRUE, 1);
    }
}

// This callback is frequently overwritten by SpriteCB_TrainerSlideIn
void SpriteCB_BattleSpriteStartSlideLeft(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_BattleSpriteSlideLeft;
}

static void SpriteCB_BattleSpriteSlideLeft(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 -= 2;
        if (sprite->x2 == 0)
        {
            sprite->callback = SpriteCB_Idle;
            sprite->data[1] = 0;
        }
    }
}

static void UNUSED SetIdleSpriteCallback(struct Sprite *sprite)
{
    sprite->callback = SpriteCB_Idle;
}

static void SpriteCB_Idle(struct Sprite *sprite)
{
}

#define sSpeedX data[1]
#define sSpeedY data[2]

void SpriteCB_FaintSlideAnim(struct Sprite *sprite)
{
    if (!(gIntroSlideFlags & 1))
    {
        sprite->x2 += sprite->sSpeedX;
        sprite->y2 += sprite->sSpeedY;
    }
}

#undef sSpeedX
#undef sSpeedY

void BeginBattleIntroDummy(void)
{
}

static void BattleIntroGetMonsData(void)
{
    switch (gBattleCommunication[MULTIUSE_STATE])
    {
    case 0:
        gActiveBattler = gBattleCommunication[1];
        BtlController_EmitGetMonData(B_COMM_TO_CONTROLLER, REQUEST_ALL_BATTLE, 0);
        MarkBattlerForControllerExec(gActiveBattler);
        gBattleCommunication[MULTIUSE_STATE]++;
        break;
    case 1:
        if (gBattleControllerExecFlags == 0)
        {
            gBattleCommunication[1]++;
            if (gBattleCommunication[1] == gBattlersCount)
                gBattleMainFunc = BattleIntroPrepareBackgroundSlide;
            else
                gBattleCommunication[MULTIUSE_STATE] = 0;
        }
        break;
    }
}

static void BattleIntroPrintWildMonAttacked(void)
{
    if (gBattleControllerExecFlags == 0)
    {
        gBattleMainFunc = BattleIntroPrintPlayerSendsOut;
        PrepareStringBattle(STRINGID_INTROMSG, 0);
    }
}

static void UNUSED BattleIntroSkipRecordMonsToDex(void)
{
    if (gBattleControllerExecFlags == 0)
        gBattleMainFunc = BattleIntroPrintPlayerSendsOut;
}

static void BattleIntroPrintPlayerSendsOut(void)
{
    u32 position;

    if (gBattleControllerExecFlags)
        return;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
    {
        position = B_POSITION_PLAYER_LEFT;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER)
            position = B_POSITION_PLAYER_LEFT;
        else
            position = B_POSITION_OPPONENT_LEFT;
    }
    else
    {
        position = B_POSITION_PLAYER_LEFT;
    }

    // JP: checks BATTLE_TYPE_SAFARI (US: BATTLE_TYPE_TRAINER)
    if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
        PrepareStringBattle(STRINGID_INTROSENDOUT, GetBattlerAtPosition(position));

    gBattleMainFunc = BattleIntroPlayer1SendsOutMonAnimation;
}


static void BattleIntroPrintOpponentSendsOut(void)
{
    u32 position;

    if (gBattleControllerExecFlags)
        return;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
    {
        position = B_POSITION_OPPONENT_LEFT;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_IS_MASTER)
            position = B_POSITION_OPPONENT_LEFT;
        else
            position = B_POSITION_PLAYER_LEFT;
    }
    else
    {
        position = B_POSITION_OPPONENT_LEFT;
    }

    PrepareStringBattle(STRINGID_INTROSENDOUT, GetBattlerAtPosition(position));
    gBattleMainFunc = BattleIntroOpponent1SendsOutMonAnimation;
}

void HandleEndTurn_ContinueBattle(void)
{
    s32 i;

    if (gBattleControllerExecFlags == 0)
    {
        gBattleMainFunc = BattleTurnPassed;
        for (i = 0; i < BATTLE_COMMUNICATION_ENTRIES_COUNT; i++)
            gBattleCommunication[i] = 0;
        for (i = 0; i < gBattlersCount; i++)
        {
            gBattleMons[i].status2 &= ~STATUS2_FLINCHED;
            if ((gBattleMons[i].status1 & STATUS1_SLEEP) && (gBattleMons[i].status2 & STATUS2_MULTIPLETURNS))
                CancelMultiTurnMoves(i);
        }
        gBattleStruct->turnEffectsTracker = 0;
        gBattleStruct->turnEffectsBattlerId = 0;
        gBattleStruct->wishPerishSongState = 0;
        gBattleStruct->wishPerishSongBattlerId = 0;
        gBattleStruct->turnCountersTracker = 0;
        gMoveResultFlags = 0;
    }
}

void SwitchPartyOrder(u8 battler)
{
    s32 i;
    u8 partyId1;
    u8 partyId2;

    for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        gBattlePartyCurrentOrder[i] = *(battler * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders));

    partyId1 = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[battler]);
    partyId2 = GetPartyIdFromBattlePartyId(*(gBattleStruct->monToSwitchIntoId + battler));
    SwitchPartyMonSlots(partyId1, partyId2);

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
            *(BATTLE_PARTNER(battler) * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        }
    }
    else
    {
        for (i = 0; i < (int)ARRAY_COUNT(gBattlePartyCurrentOrder); i++)
        {
            *(battler * 3 + i + (u8 *)(gBattleStruct->battlerPartyOrders)) = gBattlePartyCurrentOrder[i];
        }
    }
}

enum
{
    STATE_TURN_START_RECORD,
    STATE_BEFORE_ACTION_CHOSEN,
    STATE_WAIT_ACTION_CHOSEN,
    STATE_WAIT_ACTION_CASE_CHOSEN,
    STATE_WAIT_ACTION_CONFIRMED_STANDBY,
    STATE_WAIT_ACTION_CONFIRMED,
    STATE_SELECTION_SCRIPT,
    STATE_WAIT_SET_BEFORE_ACTION,
    STATE_SELECTION_SCRIPT_MAY_RUN
};

bool8 AllAtActionConfirmed(void)
{
    s32 i, count;

    for (count = 0, i = 0; i < gBattlersCount; i++)
    {
        if (gBattleCommunication[i] == STATE_WAIT_ACTION_CONFIRMED)
            count++;
    }

    if (count + 1 == gBattlersCount)
        return TRUE;
    else
        return FALSE;
}

void UpdateBattlerPartyOrdersOnSwitch(void)
{
    *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = gBattleBufferB[gActiveBattler][1];
    RecordedBattle_SetBattlerAction(gActiveBattler, gBattleBufferB[gActiveBattler][1]);

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gBattleTypeFlags & BATTLE_TYPE_MULTI)
    {
        *(gActiveBattler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) &= 0xF;
        *(gActiveBattler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleBufferB[gActiveBattler][2] & 0xF0);
        *(gActiveBattler * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 1) = gBattleBufferB[gActiveBattler][3];

        *((BATTLE_PARTNER(gActiveBattler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) &= (0xF0);
        *((BATTLE_PARTNER(gActiveBattler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 0) |= (gBattleBufferB[gActiveBattler][2] & 0xF0) >> 4;
        *((BATTLE_PARTNER(gActiveBattler)) * 3 + (u8 *)(gBattleStruct->battlerPartyOrders) + 2) = gBattleBufferB[gActiveBattler][3];
    }
}

void SwapTurnOrder(u8 id1, u8 id2)
{
    u32 temp;

    SWAP(gActionsByTurnOrder[id1], gActionsByTurnOrder[id2], temp);
    SWAP(gBattlerByTurnOrder[id1], gBattlerByTurnOrder[id2], temp);
}

static void SetActionsAndBattlersTurnOrder(void)
{
    s32 turnOrderId = 0;
    s32 i, j;

    if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
    {
        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
            gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
            turnOrderId++;
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_RUN)
                {
                    turnOrderId = 5;
                    break;
                }
            }
        }
        else
        {
            if (gChosenActionByBattler[0] == B_ACTION_RUN)
            {
                gActiveBattler = 0;
                turnOrderId = 5;
            }
            if (gChosenActionByBattler[2] == B_ACTION_RUN)
            {
                gActiveBattler = 2;
                turnOrderId = 5;
            }
        }

        if (turnOrderId == 5) // One of battlers wants to run.
        {
            gActionsByTurnOrder[0] = gChosenActionByBattler[gActiveBattler];
            gBattlerByTurnOrder[0] = gActiveBattler;
            turnOrderId = 1;
            for (i = 0; i < gBattlersCount; i++)
            {
                if (i != gActiveBattler)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[i];
                    gBattlerByTurnOrder[turnOrderId] = i;
                    turnOrderId++;
                }
            }
            gBattleMainFunc = CheckFocusPunch_ClearVarsBeforeTurnStarts;
            gBattleStruct->focusPunchBattlerId = 0;
            return;
        }
        else
        {
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] == B_ACTION_USE_ITEM || gChosenActionByBattler[gActiveBattler] == B_ACTION_SWITCH)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
                    gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
                    turnOrderId++;
                }
            }
            for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
            {
                if (gChosenActionByBattler[gActiveBattler] != B_ACTION_USE_ITEM && gChosenActionByBattler[gActiveBattler] != B_ACTION_SWITCH)
                {
                    gActionsByTurnOrder[turnOrderId] = gChosenActionByBattler[gActiveBattler];
                    gBattlerByTurnOrder[turnOrderId] = gActiveBattler;
                    turnOrderId++;
                }
            }
            for (i = 0; i < gBattlersCount - 1; i++)
            {
                for (j = i + 1; j < gBattlersCount; j++)
                {
                    u8 battler1 = gBattlerByTurnOrder[i];
                    u8 battler2 = gBattlerByTurnOrder[j];
                    if (gActionsByTurnOrder[i] != B_ACTION_USE_ITEM
                        && gActionsByTurnOrder[j] != B_ACTION_USE_ITEM
                        && gActionsByTurnOrder[i] != B_ACTION_SWITCH
                        && gActionsByTurnOrder[j] != B_ACTION_SWITCH)
                    {
                        if (GetWhoStrikesFirst(battler1, battler2, FALSE))
                            SwapTurnOrder(i, j);
                    }
                }
            }
        }
    }
    gBattleMainFunc = CheckFocusPunch_ClearVarsBeforeTurnStarts;
    gBattleStruct->focusPunchBattlerId = 0;
}

void TurnValuesCleanUp(bool8 var0)
{
    s32 i;
    u8 *dataPtr;

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        if (var0)
        {
            gProtectStructs[gActiveBattler].protected = 0;
            gProtectStructs[gActiveBattler].endured = 0;
        }
        else
        {
            dataPtr = (u8 *)(&gProtectStructs[gActiveBattler]);
            for (i = 0; i < sizeof(struct ProtectStruct); i++)
                dataPtr[i] = 0;

            if (gDisableStructs[gActiveBattler].isFirstTurn)
                gDisableStructs[gActiveBattler].isFirstTurn--;

            if (gDisableStructs[gActiveBattler].rechargeTimer)
            {
                gDisableStructs[gActiveBattler].rechargeTimer--;
                if (gDisableStructs[gActiveBattler].rechargeTimer == 0)
                    gBattleMons[gActiveBattler].status2 &= ~STATUS2_RECHARGE;
            }
        }

        if (gDisableStructs[gActiveBattler].substituteHP == 0)
            gBattleMons[gActiveBattler].status2 &= ~STATUS2_SUBSTITUTE;
    }

    gSideTimers[0].followmeTimer = 0;
    gSideTimers[1].followmeTimer = 0;
}

void SpecialStatusesClear(void)
{
    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
    {
        s32 i;
        u8 *dataPtr = (u8 *)(&gSpecialStatuses[gActiveBattler]);

        for (i = 0; i < sizeof(struct SpecialStatus); i++)
            dataPtr[i] = 0;
    }
}

void HandleEndTurn_RanFromBattle(void)
{
    gCurrentActionFuncId = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER && gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeited;
        gBattleOutcome = B_OUTCOME_FORFEITED;
        gSaveBlock2Ptr->frontier.disableRecordBattle = TRUE;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        gBattlescriptCurrInstr = BattleScript_PrintPlayerForfeited;
        gBattleOutcome = B_OUTCOME_FORFEITED;
    }
    else
    {
        switch (gProtectStructs[gBattlerAttacker].fleeType)
        {
        default:
            gBattlescriptCurrInstr = BattleScript_GotAwaySafely;
            break;
        case FLEE_ITEM:
            gBattlescriptCurrInstr = BattleScript_SmokeBallEscape;
            break;
        case FLEE_ABILITY:
            gBattlescriptCurrInstr = BattleScript_RanAwayUsingMonAbility;
            break;
        }
    }

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

void HandleEndTurn_MonFled(void)
{
    gCurrentActionFuncId = 0;

    PREPARE_MON_NICK_BUFFER(gBattleTextBuff1, gBattlerAttacker, gBattlerPartyIndexes[gBattlerAttacker]);
    gBattlescriptCurrInstr = BattleScript_WildMonFled;

    gBattleMainFunc = HandleEndTurn_FinishBattle;
}

static void FreeResetData_ReturnToOvOrDoEvolutions(void)
{
    if (!gPaletteFade.active)
    {
        ResetSpriteData();
        if (gLeveledUpInBattle == 0 || gBattleOutcome != B_OUTCOME_WON)
        {
            gBattleMainFunc = ReturnFromBattleToOverworld;
            return;
        }
        else
        {
            gBattleMainFunc = TryEvolvePokemon;
        }
    }

    FreeAllWindowBuffers();
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        FreeMonSpritesGfx();
        FreeBattleResources();
        FreeBattleSpritesData();
    }
}

static void WaitForEvoSceneToFinish(void)
{
    if (gMain.callback2 == BattleMainCB2)
        gBattleMainFunc = TryEvolvePokemon;
}

static void ReturnFromBattleToOverworld(void)
{
    if (!(gBattleTypeFlags & BATTLE_TYPE_LINK))
    {
        RandomlyGivePartyPokerus(gPlayerParty);
        PartySpreadPokerus(gPlayerParty);
    }

    if (gBattleTypeFlags & BATTLE_TYPE_LINK && gReceivedRemoteLinkPlayers)
        return;

    gSpecialVar_Result = gBattleOutcome;
    gMain.inBattle = FALSE;
    gMain.callback1 = gPreBattleCallback1;

    if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
    {
        UpdateRoamerHPStatus(&gEnemyParty[0]);
        if ((gBattleOutcome & B_OUTCOME_WON) || gBattleOutcome == B_OUTCOME_CAUGHT)
            SetRoamerInactive();
    }

    m4aSongNumStop(SE_LOW_HEALTH);
    SetMainCallback2(gMain.savedCallback);
}

void RunBattleScriptCommands_PopCallbacksStack(void)
{
    if (gCurrentActionFuncId == B_ACTION_TRY_FINISH || gCurrentActionFuncId == B_ACTION_FINISHED)
    {
        if (gBattleResources->battleCallbackStack->size != 0)
            gBattleResources->battleCallbackStack->size--;
        gBattleMainFunc = gBattleResources->battleCallbackStack->function[gBattleResources->battleCallbackStack->size];
    }
    else
    {
        if (gBattleControllerExecFlags == 0)
            gBattleScriptingCommandsTable[gBattlescriptCurrInstr[0]]();
    }
}

static void CheckFocusPunch_ClearVarsBeforeTurnStarts(void)
{
    if (!(gHitMarker & HITMARKER_RUN))
    {
        while (gBattleStruct->focusPunchBattlerId < gBattlersCount)
        {
            gActiveBattler = gBattlerAttacker = gBattleStruct->focusPunchBattlerId;
            gBattleStruct->focusPunchBattlerId++;
            if (gChosenMoveByBattler[gActiveBattler] == MOVE_FOCUS_PUNCH
                && !(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
                && !(gDisableStructs[gBattlerAttacker].truantCounter)
                && !(gProtectStructs[gActiveBattler].noValidMoves))
            {
                BattleScriptExecute(BattleScript_FocusPunchSetUp);
                return;
            }
        }
    }

    TryClearRageStatuses();
    gCurrentTurnActionNumber = 0;
    gCurrentActionFuncId = gActionsByTurnOrder[gCurrentTurnActionNumber];
    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleMainFunc = RunBattleScriptCommands; // JP: uses RunBattleScriptCommands @ 0x0803D45C (US: RunTurnActionsFunctions)
    gBattleCommunication[3] = 0;
    gBattleCommunication[4] = 0;
    gBattleScripting.multihitMoveEffect = 0;
    gBattleResources->battleScriptsStack->size = 0;
}













#define sSinIndex           data[0]
#define sDelta              data[1]
#define sAmplitude          data[2]
#define sBouncerSpriteId    data[3]
#define sWhich              data[4]

void DoBounceEffect(u8 battler, u8 which, s8 delta, s8 amplitude)
{
    u8 invisibleSpriteId;
    u8 bouncerSpriteId;

    switch (which)
    {
    case BOUNCE_HEALTHBOX:
    default:
        if (gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
            return;
        break;
    case BOUNCE_MON:
        if (gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing)
            return;
        break;
    }

    invisibleSpriteId = CreateInvisibleSpriteWithCallback(SpriteCB_BounceEffect);
    if (which == BOUNCE_HEALTHBOX)
    {
        bouncerSpriteId = gHealthboxSpriteIds[battler];
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId = invisibleSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing = 1;
        gSprites[invisibleSpriteId].sSinIndex = 128; // 0
    }
    else
    {
        bouncerSpriteId = gBattlerSpriteIds[battler];
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId = invisibleSpriteId;
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing = 1;
        gSprites[invisibleSpriteId].sSinIndex = 192; // -1
    }
    gSprites[invisibleSpriteId].sDelta = delta;
    gSprites[invisibleSpriteId].sAmplitude = amplitude;
    gSprites[invisibleSpriteId].sBouncerSpriteId = bouncerSpriteId;
    gSprites[invisibleSpriteId].sWhich = which;
    gSprites[bouncerSpriteId].x2 = 0;
    gSprites[bouncerSpriteId].y2 = 0;
}

void EndBounceEffect(u8 battler, u8 which)
{
    u8 bouncerSpriteId;

    if (which == BOUNCE_HEALTHBOX)
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing)
            return;

        bouncerSpriteId = gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId].sBouncerSpriteId;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].healthboxBounceSpriteId]);
        gBattleSpritesDataPtr->healthBoxesData[battler].healthboxIsBouncing = 0;
    }
    else
    {
        if (!gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing)
            return;

        bouncerSpriteId = gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId].sBouncerSpriteId;
        DestroySprite(&gSprites[gBattleSpritesDataPtr->healthBoxesData[battler].battlerBounceSpriteId]);
        gBattleSpritesDataPtr->healthBoxesData[battler].battlerIsBouncing = 0;
    }

    gSprites[bouncerSpriteId].x2 = 0;
    gSprites[bouncerSpriteId].y2 = 0;
}

void SpriteCB_PlayerMonFromBall(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        BattleAnimateBackSprite(sprite, sprite->sSpeciesId);
}

static void SpriteCB_TrainerThrowObject_Main(struct Sprite *sprite)
{
    AnimSetCenterToCornerVecX(sprite);
    if (sprite->animEnded)
        sprite->callback = SpriteCB_Idle;
}

// Sprite callback for a trainer back pic to throw an object
// (Wally throwing a ball, throwing PokÃ©blocks/balls in the Safari Zone)
void SpriteCB_TrainerThrowObject(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, 1);
    sprite->callback = SpriteCB_TrainerThrowObject_Main;
}

void AnimSetCenterToCornerVecX(struct Sprite *sprite)
{
    if (sprite->animDelayCounter == 0)
        sprite->centerToCornerVecX = sCenterToCornerVecXs[sprite->animCmdIndex];
}

void BeginBattleIntro(void)
{
    BattleStartClearSetData();
    gBattleCommunication[1] = 0;
    gBattleMainFunc = BattleIntroGetMonsData;
}

static void BattleMainCB1(void)
{
    gBattleMainFunc();

    for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        gBattlerControllerFuncs[gActiveBattler]();
}

// JP byte-exact: JP checks both recorded flags before choosing the
// opponent-right position and only supports B_POSITION_OPPONENT_RIGHT
// (2) / B_POSITION_PLAYER_RIGHT (3), unlike US pokeemerald.
__attribute__((naked)) void BattleIntroOpponent2SendsOutMonAnimation(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, lr}\n\t"
        "ldr r0, _0803AE8C\n\t"
        "ldr r1, [r0]\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x11\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "beq _0803AE40\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x12\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "beq _0803AE40\n\t"
        "movs r5, #2\n\t"
        "cmp r1, #0\n\t"
        "bge _0803AE42\n\t"
        "_0803AE40:\n\t"
        "movs r5, #3\n\t"
        "_0803AE42:\n\t"
        "ldr r1, _0803AE90\n\t"
        "movs r0, #0\n\t"
        "strb r0, [r1]\n\t"
        "ldr r0, _0803AE94\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r0, #0\n\t"
        "beq _0803AE7E\n\t"
        "adds r4, r1, #0\n\t"
        "_0803AE52:\n\t"
        "ldrb r0, [r4]\n\t"
        "bl GetBattlerPosition\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "cmp r0, r5\n\t"
        "bne _0803AE6C\n\t"
        "movs r0, #0\n\t"
        "bl BtlController_EmitIntroTrainerBallThrow\n\t"
        "ldrb r0, [r4]\n\t"
        "bl MarkBattlerForControllerExec\n\t"
        "_0803AE6C:\n\t"
        "ldrb r0, [r4]\n\t"
        "adds r0, #1\n\t"
        "strb r0, [r4]\n\t"
        "ldr r1, _0803AE94\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "ldrb r1, [r1]\n\t"
        "cmp r0, r1\n\t"
        "blo _0803AE52\n\t"
        "_0803AE7E:\n\t"
        "ldr r1, _0803AE98\n\t"
        "ldr r0, _0803AE9C\n\t"
        "str r0, [r1]\n\t"
        "pop {r4, r5}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_0803AE8C: .4byte gBattleTypeFlags\n\t"
        "_0803AE90: .4byte gActiveBattler\n\t"
        "_0803AE94: .4byte gBattlersCount\n\t"
        "_0803AE98: .4byte gBattleMainFunc\n\t"
        "_0803AE9C: .4byte BattleIntroRecordMonsToDex + 1\n\t"
        ".syntax divided\n\t"
    );
}

// JP byte-exact: JP selects position 0 (B_POSITION_OPPONENT_LEFT) for
// normal battles and computes the recorded-link position differently
// from US pokeemerald.
__attribute__((naked)) void BattleIntroOpponent1SendsOutMonAnimation(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, lr}\n\t"
        "ldr r0, _0803AEC8\n\t"
        "ldr r2, [r0]\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x11\n\t"
        "ands r0, r2\n\t"
        "cmp r0, #0\n\t"
        "beq _0803AEDC\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x12\n\t"
        "ands r0, r2\n\t"
        "cmp r0, #0\n\t"
        "beq _0803AEDC\n\t"
        "movs r1, #0x80\n\t"
        "lsls r1, r1, #0x18\n\t"
        "ands r1, r2\n\t"
        "rsbs r0, r1, #0\n\t"
        "orrs r0, r1\n\t"
        "lsrs r5, r0, #0x1f\n\t"
        "b _0803AEDE\n\t"
        ".align 2, 0\n\t"
        "_0803AEC8: .4byte gBattleTypeFlags\n\t"
        "_0803AECC:\n\t"
        "ldr r1, _0803AED4\n\t"
        "ldr r0, _0803AED8\n\t"
        "b _0803AF34\n\t"
        ".align 2, 0\n\t"
        "_0803AED4: .4byte gBattleMainFunc\n\t"
        "_0803AED8: .4byte BattleIntroOpponent2SendsOutMonAnimation + 1\n\t"
        "_0803AEDC:\n\t"
        "movs r5, #1\n\t"
        "_0803AEDE:\n\t"
        "ldr r0, _0803AF3C\n\t"
        "ldr r2, [r0]\n\t"
        "cmp r2, #0\n\t"
        "bne _0803AF36\n\t"
        "ldr r0, _0803AF40\n\t"
        "strb r2, [r0]\n\t"
        "ldr r1, _0803AF44\n\t"
        "adds r4, r0, #0\n\t"
        "ldrb r1, [r1]\n\t"
        "cmp r2, r1\n\t"
        "bhs _0803AF30\n\t"
        "adds r6, r4, #0\n\t"
        "_0803AEF6:\n\t"
        "ldrb r0, [r4]\n\t"
        "bl GetBattlerPosition\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "cmp r0, r5\n\t"
        "bne _0803AF1C\n\t"
        "movs r0, #0\n\t"
        "bl BtlController_EmitIntroTrainerBallThrow\n\t"
        "ldrb r0, [r4]\n\t"
        "bl MarkBattlerForControllerExec\n\t"
        "ldr r0, _0803AF48\n\t"
        "ldr r0, [r0]\n\t"
        "ldr r1, _0803AF4C\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "bne _0803AECC\n\t"
        "_0803AF1C:\n\t"
        "ldrb r0, [r6]\n\t"
        "adds r0, #1\n\t"
        "strb r0, [r6]\n\t"
        "ldr r1, _0803AF44\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "ldr r4, _0803AF40\n\t"
        "ldrb r1, [r1]\n\t"
        "cmp r0, r1\n\t"
        "blo _0803AEF6\n\t"
        "_0803AF30:\n\t"
        "ldr r1, _0803AF50\n\t"
        "ldr r0, _0803AF54\n\t"
        "_0803AF34:\n\t"
        "str r0, [r1]\n\t"
        "_0803AF36:\n\t"
        "pop {r4, r5, r6}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_0803AF3C: .4byte gBattleControllerExecFlags\n\t"
        "_0803AF40: .4byte gActiveBattler\n\t"
        "_0803AF44: .4byte gBattlersCount\n\t"
        "_0803AF48: .4byte gBattleTypeFlags\n\t"
        "_0803AF4C: .4byte 0x00008040\n\t"
        "_0803AF50: .4byte gBattleMainFunc\n\t"
        "_0803AF54: .4byte BattleIntroRecordMonsToDex + 1\n\t"
        ".syntax divided\n\t"
    );
}

// JP byte-exact: JP records opponent mons into the dex during the intro
// (skipping recorded-link battles), unlike US pokeemerald which does this
// in a later battle state.
__attribute__((naked)) void BattleIntroRecordMonsToDex(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, r7, lr}\n\t"
        "ldr r0, _0803AFD0\n\t"
        "ldr r1, [r0]\n\t"
        "cmp r1, #0\n\t"
        "bne _0803AFC8\n\t"
        "ldr r2, _0803AFD4\n\t"
        "strb r1, [r2]\n\t"
        "ldr r0, _0803AFD8\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r1, r0\n\t"
        "bhs _0803AFC2\n\t"
        "adds r4, r2, #0\n\t"
        "ldr r6, _0803AFDC\n\t"
        "movs r5, #0x58\n\t"
        "adds r7, r6, #0\n\t"
        "adds r7, #0x48\n\t"
        "_0803AF78:\n\t"
        "ldrb r0, [r4]\n\t"
        "bl GetBattlerSide\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "cmp r0, #1\n\t"
        "bne _0803AFB0\n\t"
        "ldr r0, _0803AFE0\n\t"
        "ldr r0, [r0]\n\t"
        "ldr r1, _0803AFE4\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "bne _0803AFB0\n\t"
        "ldrb r0, [r4]\n\t"
        "muls r0, r5, r0\n\t"
        "adds r0, r0, r6\n\t"
        "ldrh r0, [r0]\n\t"
        "bl HoennToNationalOrder\n\t"
        "lsls r0, r0, #0x10\n\t"
        "lsrs r0, r0, #0x10\n\t"
        "ldrb r1, [r4]\n\t"
        "muls r1, r5, r1\n\t"
        "adds r1, r1, r7\n\t"
        "ldr r2, [r1]\n\t"
        "movs r1, #2\n\t"
        "bl HandleSetPokedexFlag\n\t"
        "_0803AFB0:\n\t"
        "ldrb r0, [r4]\n\t"
        "adds r0, #1\n\t"
        "strb r0, [r4]\n\t"
        "ldr r1, _0803AFD8\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "ldrb r1, [r1]\n\t"
        "cmp r0, r1\n\t"
        "blo _0803AF78\n\t"
        "_0803AFC2:\n\t"
        "ldr r1, _0803AFE8\n\t"
        "ldr r0, _0803AFEC\n\t"
        "str r0, [r1]\n\t"
        "_0803AFC8:\n\t"
        "pop {r4, r5, r6, r7}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_0803AFD0: .4byte gBattleControllerExecFlags\n\t"
        "_0803AFD4: .4byte gActiveBattler\n\t"
        "_0803AFD8: .4byte gBattlersCount\n\t"
        "_0803AFDC: .4byte gBattleMons\n\t"
        "_0803AFE0: .4byte gBattleTypeFlags\n\t"
        "_0803AFE4: .4byte 0x063F0902\n\t"
        "_0803AFE8: .4byte gBattleMainFunc\n\t"
        "_0803AFEC: .4byte 0x0803B011\n\t"
        ".syntax divided\n\t"
    );
}

// JP byte-exact: JP selects position 3 (B_POSITION_PLAYER_RIGHT) for
// normal battles and 2 for recorded-link, opposite of the opponent
// variant; also clears the player mon summary fields.
__attribute__((naked)) void BattleIntroPlayer2SendsOutMonAnimation(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, lr}\n\t"
        "ldr r0, _0803B0F4\n\t"
        "ldr r1, [r0]\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x11\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B090\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x12\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B090\n\t"
        "movs r5, #3\n\t"
        "cmp r1, #0\n\t"
        "bge _0803B092\n\t"
        "_0803B090:\n\t"
        "movs r5, #2\n\t"
        "_0803B092:\n\t"
        "ldr r1, _0803B0F8\n\t"
        "movs r0, #0\n\t"
        "strb r0, [r1]\n\t"
        "ldr r0, _0803B0FC\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B0CE\n\t"
        "adds r4, r1, #0\n\t"
        "_0803B0A2:\n\t"
        "ldrb r0, [r4]\n\t"
        "bl GetBattlerPosition\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "cmp r0, r5\n\t"
        "bne _0803B0BC\n\t"
        "movs r0, #0\n\t"
        "bl BtlController_EmitIntroTrainerBallThrow\n\t"
        "ldrb r0, [r4]\n\t"
        "bl MarkBattlerForControllerExec\n\t"
        "_0803B0BC:\n\t"
        "ldrb r0, [r4]\n\t"
        "adds r0, #1\n\t"
        "strb r0, [r4]\n\t"
        "ldr r1, _0803B0FC\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "ldrb r1, [r1]\n\t"
        "cmp r0, r1\n\t"
        "blo _0803B0A2\n\t"
        "_0803B0CE:\n\t"
        "ldr r2, _0803B100\n\t"
        "ldr r0, [r2]\n\t"
        "adds r0, #0x4c\n\t"
        "movs r1, #0\n\t"
        "strb r1, [r0]\n\t"
        "ldr r0, [r2]\n\t"
        "adds r0, #0xd9\n\t"
        "strb r1, [r0]\n\t"
        "ldr r0, [r2]\n\t"
        "movs r2, #0xd1\n\t"
        "lsls r2, r2, #1\n\t"
        "adds r0, r0, r2\n\t"
        "strb r1, [r0]\n\t"
        "ldr r1, _0803B104\n\t"
        "ldr r0, _0803B108\n\t"
        "str r0, [r1]\n\t"
        "pop {r4, r5}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_0803B0F4: .4byte gBattleTypeFlags\n\t"
        "_0803B0F8: .4byte gActiveBattler\n\t"
        "_0803B0FC: .4byte gBattlersCount\n\t"
        "_0803B100: .4byte gBattleStruct\n\t"
        "_0803B104: .4byte gBattleMainFunc\n\t"
        "_0803B108: .4byte TryDoEventsBeforeFirstTurn + 1\n\t"
        ".syntax divided\n\t"
    );
}

// JP byte-exact: JP selects position 0 for normal battles and 1 for
// recorded-link; also checks the 0x40 link flag and clears player mon
// summary fields, unlike US pokeemerald.
__attribute__((naked)) void BattleIntroPlayer1SendsOutMonAnimation(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, lr}\n\t"
        "ldr r0, _0803B130\n\t"
        "ldr r1, [r0]\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x11\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B144\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0x12\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B144\n\t"
        "movs r6, #1\n\t"
        "cmp r1, #0\n\t"
        "bge _0803B146\n\t"
        "b _0803B144\n\t"
        ".align 2, 0\n\t"
        "_0803B130: .4byte gBattleTypeFlags\n\t"
        "_0803B134:\n\t"
        "ldr r1, _0803B13C\n\t"
        "ldr r0, _0803B140\n\t"
        "b _0803B1B6\n\t"
        ".align 2, 0\n\t"
        "_0803B13C: .4byte gBattleMainFunc\n\t"
        "_0803B140: .4byte BattleIntroPlayer2SendsOutMonAnimation + 1\n\t"
        "_0803B144:\n\t"
        "movs r6, #0\n\t"
        "_0803B146:\n\t"
        "ldr r0, _0803B1C0\n\t"
        "ldr r2, [r0]\n\t"
        "cmp r2, #0\n\t"
        "bne _0803B1B8\n\t"
        "ldr r0, _0803B1C4\n\t"
        "strb r2, [r0]\n\t"
        "ldr r1, _0803B1C8\n\t"
        "adds r4, r0, #0\n\t"
        "ldrb r1, [r1]\n\t"
        "cmp r2, r1\n\t"
        "bhs _0803B198\n\t"
        "adds r5, r4, #0\n\t"
        "_0803B15E:\n\t"
        "ldrb r0, [r4]\n\t"
        "bl GetBattlerPosition\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "cmp r0, r6\n\t"
        "bne _0803B184\n\t"
        "movs r0, #0\n\t"
        "bl BtlController_EmitIntroTrainerBallThrow\n\t"
        "ldrb r0, [r4]\n\t"
        "bl MarkBattlerForControllerExec\n\t"
        "ldr r0, _0803B1CC\n\t"
        "ldr r0, [r0]\n\t"
        "movs r1, #0x40\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "bne _0803B134\n\t"
        "_0803B184:\n\t"
        "ldrb r0, [r5]\n\t"
        "adds r0, #1\n\t"
        "strb r0, [r5]\n\t"
        "ldr r1, _0803B1C8\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "ldr r4, _0803B1C4\n\t"
        "ldrb r1, [r1]\n\t"
        "cmp r0, r1\n\t"
        "blo _0803B15E\n\t"
        "_0803B198:\n\t"
        "ldr r2, _0803B1D0\n\t"
        "ldr r0, [r2]\n\t"
        "adds r0, #0x4c\n\t"
        "movs r1, #0\n\t"
        "strb r1, [r0]\n\t"
        "ldr r0, [r2]\n\t"
        "adds r0, #0xd9\n\t"
        "strb r1, [r0]\n\t"
        "ldr r0, [r2]\n\t"
        "movs r2, #0xd1\n\t"
        "lsls r2, r2, #1\n\t"
        "adds r0, r0, r2\n\t"
        "strb r1, [r0]\n\t"
        "ldr r1, _0803B1D4\n\t"
        "ldr r0, _0803B1D8\n\t"
        "_0803B1B6:\n\t"
        "str r0, [r1]\n\t"
        "_0803B1B8:\n\t"
        "pop {r4, r5, r6}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_0803B1C0: .4byte gBattleControllerExecFlags\n\t"
        "_0803B1C4: .4byte gActiveBattler\n\t"
        "_0803B1C8: .4byte gBattlersCount\n\t"
        "_0803B1CC: .4byte gBattleTypeFlags\n\t"
        "_0803B1D0: .4byte gBattleStruct\n\t"
        "_0803B1D4: .4byte gBattleMainFunc\n\t"
        "_0803B1D8: .4byte TryDoEventsBeforeFirstTurn + 1\n\t"
        ".syntax divided\n\t"
    );
}

// JP byte-exact: JP-only intro helper that emits switch-in animations
// for all player-side battlers (US pokeemerald does not have this
// function; JP funcmap names it BattleIntroSwitchInPlayerMons).
__attribute__((naked)) void BattleIntroSwitchInPlayerMons(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, lr}\n\t"
        "ldr r0, _0803B250\n\t"
        "ldr r1, [r0]\n\t"
        "cmp r1, #0\n\t"
        "bne _0803B24A\n\t"
        "ldr r2, _0803B254\n\t"
        "strb r1, [r2]\n\t"
        "ldr r0, _0803B258\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r1, r0\n\t"
        "bhs _0803B22A\n\t"
        "adds r4, r2, #0\n\t"
        "ldr r5, _0803B25C\n\t"
        "_0803B1F6:\n\t"
        "ldrb r0, [r4]\n\t"
        "bl GetBattlerSide\n\t"
        "lsls r0, r0, #0x18\n\t"
        "cmp r0, #0\n\t"
        "bne _0803B218\n\t"
        "ldrb r0, [r4]\n\t"
        "lsls r0, r0, #1\n\t"
        "adds r0, r0, r5\n\t"
        "ldrb r1, [r0]\n\t"
        "movs r0, #0\n\t"
        "movs r2, #0\n\t"
        "bl BtlController_EmitSwitchInAnim\n\t"
        "ldrb r0, [r4]\n\t"
        "bl MarkBattlerForControllerExec\n\t"
        "_0803B218:\n\t"
        "ldrb r0, [r4]\n\t"
        "adds r0, #1\n\t"
        "strb r0, [r4]\n\t"
        "ldr r1, _0803B258\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r0, r0, #0x18\n\t"
        "ldrb r1, [r1]\n\t"
        "cmp r0, r1\n\t"
        "blo _0803B1F6\n\t"
        "_0803B22A:\n\t"
        "ldr r2, _0803B260\n\t"
        "ldr r0, [r2]\n\t"
        "adds r0, #0x4c\n\t"
        "movs r1, #0\n\t"
        "strb r1, [r0]\n\t"
        "ldr r0, [r2]\n\t"
        "adds r0, #0xd9\n\t"
        "strb r1, [r0]\n\t"
        "ldr r0, [r2]\n\t"
        "movs r2, #0xd1\n\t"
        "lsls r2, r2, #1\n\t"
        "adds r0, r0, r2\n\t"
        "strb r1, [r0]\n\t"
        "ldr r1, _0803B264\n\t"
        "ldr r0, _0803B268\n\t"
        "str r0, [r1]\n\t"
        "_0803B24A:\n\t"
        "pop {r4, r5}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_0803B250: .4byte gBattleControllerExecFlags\n\t"
        "_0803B254: .4byte gActiveBattler\n\t"
        "_0803B258: .4byte gBattlersCount\n\t"
        "_0803B25C: .4byte gBattlerPartyIndexes\n\t"
        "_0803B260: .4byte gBattleStruct\n\t"
        "_0803B264: .4byte gBattleMainFunc\n\t"
        "_0803B268: .4byte TryDoEventsBeforeFirstTurn + 1\n\t"
        ".syntax divided\n\t"
    );
}

// JP byte-exact: turn-end cleanup differs from US pokeemerald (JP clears
// more state bits and runs the switch-in animation helper); kept as naked
// asm because the state layout and mask sequence are register-sensitive.
__attribute__((naked)) void BattleTurnPassed(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, r7, lr}\n\t"
        "mov r7, sb\n\t"
        "mov r6, r8\n\t"
        "push {r6, r7}\n\t"
        "movs r0, #1\n\t"
        "bl TurnValuesCleanUp\n\t"
        "ldr r0, _0803B6A4\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r0, #0\n\t"
        "bne _0803B62E\n\t"
        "bl DoFieldEndTurnEffects\n\t"
        "lsls r0, r0, #0x18\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B622\n\t"
        "b _0803B7BC\n\t"
        "_0803B622:\n\t"
        "bl BattleScriptPop\n\t"
        "lsls r0, r0, #0x18\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B62E\n\t"
        "b _0803B7BC\n\t"
        "_0803B62E:\n\t"
        "bl HandleFaintedMonActions\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r1, r0, #0x18\n\t"
        "cmp r1, #0\n\t"
        "beq _0803B63C\n\t"
        "b _0803B7BC\n\t"
        "_0803B63C:\n\t"
        "ldr r0, _0803B6A8\n\t"
        "ldr r0, [r0]\n\t"
        "adds r0, #0x4d\n\t"
        "strb r1, [r0]\n\t"
        "bl HandleWishPerishSongOnTurnEnd\n\t"
        "lsls r0, r0, #0x18\n\t"
        "lsrs r4, r0, #0x18\n\t"
        "cmp r4, #0\n\t"
        "beq _0803B652\n\t"
        "b _0803B7BC\n\t"
        "_0803B652:\n\t"
        "movs r0, #0\n\t"
        "bl TurnValuesCleanUp\n\t"
        "ldr r2, _0803B6AC\n\t"
        "ldr r0, [r2]\n\t"
        "ldr r1, _0803B6B0\n\t"
        "ands r0, r1\n\t"
        "ldr r1, _0803B6B4\n\t"
        "ands r0, r1\n\t"
        "ldr r1, _0803B6B8\n\t"
        "ands r0, r1\n\t"
        "ldr r1, _0803B6BC\n\t"
        "ands r0, r1\n\t"
        "str r0, [r2]\n\t"
        "ldr r0, _0803B6C0\n\t"
        "strb r4, [r0, #0x18]\n\t"
        "strb r4, [r0, #0x19]\n\t"
        "strb r4, [r0, #0x14]\n\t"
        "ldr r0, _0803B6C4\n\t"
        "str r4, [r0]\n\t"
        "ldr r0, _0803B6C8\n\t"
        "strb r4, [r0]\n\t"
        "ldr r1, _0803B6CC\n\t"
        "movs r2, #0\n\t"
        "adds r0, r1, #4\n\t"
        "_0803B684:\n\t"
        "strb r2, [r0]\n\t"
        "subs r0, #1\n\t"
        "cmp r0, r1\n\t"
        "bge _0803B684\n\t"
        "ldr r0, _0803B6A4\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B6DC\n\t"
        "ldr r1, _0803B6D0\n\t"
        "movs r0, #0xc\n\t"
        "strb r0, [r1]\n\t"
        "ldr r1, _0803B6D4\n\t"
        "ldr r0, _0803B6D8\n\t"
        "str r0, [r1]\n\t"
        "b _0803B7BC\n\t"
        ".align 2, 0\n\t"
        "_0803B6A4: .4byte gBattleOutcome\n\t"
        "_0803B6A8: .4byte gBattleStruct\n\t"
        "_0803B6AC: .4byte gHitMarker\n\t"
        "_0803B6B0: .4byte 0xFFFFFDFF\n\t"
        "_0803B6B4: .4byte 0xFFF7FFFF\n\t"
        "_0803B6B8: .4byte 0xFFBFFFFF\n\t"
        "_0803B6BC: .4byte 0xFFEFFFFF\n\t"
        "_0803B6C0: .4byte gBattleScripting\n\t"
        "_0803B6C4: .4byte gBattleMoveDamage\n\t"
        "_0803B6C8: .4byte gMoveResultFlags\n\t"
        "_0803B6CC: .4byte gBattleCommunication\n\t"
        "_0803B6D0: .4byte gCurrentActionFuncId\n\t"
        "_0803B6D4: .4byte gBattleMainFunc\n\t"
        "_0803B6D8: .4byte RunBattleScriptCommands + 1\n\t"
        "_0803B6DC:\n\t"
        "ldr r1, _0803B770\n\t"
        "ldrb r0, [r1, #0x13]\n\t"
        "ldr r2, _0803B774\n\t"
        "mov r8, r2\n\t"
        "cmp r0, #0xfe\n\t"
        "bhi _0803B6F6\n\t"
        "adds r0, #1\n\t"
        "strb r0, [r1, #0x13]\n\t"
        "ldr r1, [r2]\n\t"
        "adds r1, #0xda\n\t"
        "ldrb r0, [r1]\n\t"
        "adds r0, #1\n\t"
        "strb r0, [r1]\n\t"
        "_0803B6F6:\n\t"
        "movs r2, #0\n\t"
        "ldr r4, _0803B778\n\t"
        "ldr r0, _0803B77C\n\t"
        "mov ip, r0\n\t"
        "ldr r1, _0803B780\n\t"
        "mov sb, r1\n\t"
        "ldrb r0, [r4]\n\t"
        "cmp r2, r0\n\t"
        "bge _0803B724\n\t"
        "ldr r7, _0803B784\n\t"
        "movs r6, #0xff\n\t"
        "movs r5, #0\n\t"
        "ldr r3, _0803B788\n\t"
        "_0803B710:\n\t"
        "adds r1, r2, r7\n\t"
        "ldrb r0, [r1]\n\t"
        "orrs r0, r6\n\t"
        "strb r0, [r1]\n\t"
        "strh r5, [r3]\n\t"
        "adds r3, #2\n\t"
        "adds r2, #1\n\t"
        "ldrb r1, [r4]\n\t"
        "cmp r2, r1\n\t"
        "blt _0803B710\n\t"
        "_0803B724:\n\t"
        "movs r2, #0\n\t"
        "ldr r3, _0803B774\n\t"
        "movs r1, #6\n\t"
        "_0803B72A:\n\t"
        "ldr r0, [r3]\n\t"
        "adds r0, r2, r0\n\t"
        "adds r0, #0x5c\n\t"
        "strb r1, [r0]\n\t"
        "adds r2, #1\n\t"
        "cmp r2, #3\n\t"
        "ble _0803B72A\n\t"
        "mov r2, r8\n\t"
        "ldr r0, [r2]\n\t"
        "adds r0, #0x91\n\t"
        "mov r2, ip\n\t"
        "ldrb r1, [r2]\n\t"
        "strb r1, [r0]\n\t"
        "mov r0, sb\n\t"
        "movs r1, #0\n\t"
        "bl sub_0814FA04\n\t"
        "ldr r1, _0803B78C\n\t"
        "ldr r0, _0803B790\n\t"
        "str r0, [r1]\n\t"
        "bl Random\n\t"
        "ldr r1, _0803B794\n\t"
        "strh r0, [r1]\n\t"
        "ldr r0, _0803B798\n\t"
        "ldr r1, [r0]\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0xa\n\t"
        "ands r0, r1\n\t"
        "cmp r0, #0\n\t"
        "beq _0803B7A0\n\t"
        "ldr r0, _0803B79C\n\t"
        "bl BattleScriptExecute\n\t"
        "b _0803B7BC\n\t"
        ".align 2, 0\n\t"
        "_0803B770: .4byte gBattleResults\n\t"
        "_0803B774: .4byte gBattleStruct\n\t"
        "_0803B778: .4byte gBattlersCount\n\t"
        "_0803B77C: .4byte gAbsentBattlerFlags\n\t"
        "_0803B780: .4byte gText_EmptyString3\n\t"
        "_0803B784: .4byte gChosenActionByBattler\n\t"
        "_0803B788: .4byte gChosenMoveByBattler\n\t"
        "_0803B78C: .4byte gBattleMainFunc\n\t"
        "_0803B790: .4byte HandleAction_TryFinish + 1\n\t"
        "_0803B794: .4byte gRandomTurnNumber\n\t"
        "_0803B798: .4byte gBattleTypeFlags\n\t"
        "_0803B79C: .4byte BattleScript_PalacePrintFlavorText\n\t"
        "_0803B7A0:\n\t"
        "movs r0, #0x80\n\t"
        "lsls r0, r0, #0xb\n\t"
        "ands r1, r0\n\t"
        "cmp r1, #0\n\t"
        "beq _0803B7BC\n\t"
        "mov r1, r8\n\t"
        "ldr r0, [r1]\n\t"
        "adds r0, #0xda\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r0, #0\n\t"
        "bne _0803B7BC\n\t"
        "ldr r0, _0803B7C8\n\t"
        "bl BattleScriptExecute\n\t"
        "_0803B7BC:\n\t"
        "pop {r3, r4}\n\t"
        "mov r8, r3\n\t"
        "mov sb, r4\n\t"
        "pop {r4, r5, r6, r7}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_0803B7C8: .4byte BattleScript_ArenaTurnBeginning\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BattleIntroDrawPartySummaryScreens(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0x30\n\t"
        "	ldr r0, _0803AC1C\n\t"
        "	ldr r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803ABD6\n\t"
        "	b _0803AD50\n\t"
        "_0803ABD6:\n\t"
        "	ldr r0, _0803AC20\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803ABE4\n\t"
        "	b _0803ACF0\n\t"
        "_0803ABE4:\n\t"
        "	movs r7, #0\n\t"
        "	add r0, sp, #4\n\t"
        "	mov r8, r0\n\t"
        "	mov r6, r8\n\t"
        "	mov r5, sp\n\t"
        "_0803ABEE:\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r1, r7, #0\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _0803AC24\n\t"
        "	adds r4, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803AC14\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	movs r1, #0xce\n\t"
        "	lsls r1, r1, #1\n\t"
        "	cmp r0, r1\n\t"
        "	bne _0803AC2C\n\t"
        "_0803AC14:\n\t"
        "	ldr r0, _0803AC28\n\t"
        "	strh r0, [r5]\n\t"
        "	movs r0, #0\n\t"
        "	b _0803AC3E\n\t"
        "	.align 2, 0\n\t"
        "_0803AC1C: .4byte gBattleControllerExecFlags\n\t"
        "_0803AC20: .4byte gBattleTypeFlags\n\t"
        "_0803AC24: .4byte gEnemyParty\n\t"
        "_0803AC28: .4byte 0x0000FFFF\n\t"
        "_0803AC2C:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x37\n\t"
        "	bl GetMonData3\n\t"
        "_0803AC3E:\n\t"
        "	str r0, [r6]\n\t"
        "	adds r6, #8\n\t"
        "	adds r5, #8\n\t"
        "	adds r7, #1\n\t"
        "	cmp r7, #5\n\t"
        "	ble _0803ABEE\n\t"
        "	movs r0, #1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r4, _0803AC98\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	mov r1, sp\n\t"
        "	movs r2, #0x80\n\t"
        "	bl BtlController_EmitDrawPartyStatusSummary\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "	movs r7, #0\n\t"
        "	mov r6, r8\n\t"
        "	mov r5, sp\n\t"
        "_0803AC6A:\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r1, r7, #0\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _0803AC9C\n\t"
        "	adds r4, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803AC90\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	movs r1, #0xce\n\t"
        "	lsls r1, r1, #1\n\t"
        "	cmp r0, r1\n\t"
        "	bne _0803ACA4\n\t"
        "_0803AC90:\n\t"
        "	ldr r0, _0803ACA0\n\t"
        "	strh r0, [r5]\n\t"
        "	movs r0, #0\n\t"
        "	b _0803ACB6\n\t"
        "	.align 2, 0\n\t"
        "_0803AC98: .4byte gActiveBattler\n\t"
        "_0803AC9C: .4byte gPlayerParty\n\t"
        "_0803ACA0: .4byte 0x0000FFFF\n\t"
        "_0803ACA4:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x37\n\t"
        "	bl GetMonData3\n\t"
        "_0803ACB6:\n\t"
        "	str r0, [r6]\n\t"
        "	adds r6, #8\n\t"
        "	adds r5, #8\n\t"
        "	adds r7, #1\n\t"
        "	cmp r7, #5\n\t"
        "	ble _0803AC6A\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r4, _0803ACE4\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	mov r1, sp\n\t"
        "	movs r2, #0x80\n\t"
        "	bl BtlController_EmitDrawPartyStatusSummary\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "	ldr r1, _0803ACE8\n\t"
        "	ldr r0, _0803ACEC\n\t"
        "	b _0803AD4E\n\t"
        "	.align 2, 0\n\t"
        "_0803ACE4: .4byte gActiveBattler\n\t"
        "_0803ACE8: .4byte gBattleMainFunc\n\t"
        "_0803ACEC: .4byte BattleIntroPrintTrainerWantsToBattle + 1\n\t"
        "_0803ACF0:\n\t"
        "	movs r7, #0\n\t"
        "	add r6, sp, #4\n\t"
        "	mov r5, sp\n\t"
        "_0803ACF6:\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r1, r7, #0\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _0803AD24\n\t"
        "	adds r4, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803AD1C\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x41\n\t"
        "	bl GetMonData3\n\t"
        "	movs r1, #0xce\n\t"
        "	lsls r1, r1, #1\n\t"
        "	cmp r0, r1\n\t"
        "	bne _0803AD2C\n\t"
        "_0803AD1C:\n\t"
        "	ldr r0, _0803AD28\n\t"
        "	strh r0, [r5]\n\t"
        "	movs r0, #0\n\t"
        "	b _0803AD3E\n\t"
        "	.align 2, 0\n\t"
        "_0803AD24: .4byte gPlayerParty\n\t"
        "_0803AD28: .4byte 0x0000FFFF\n\t"
        "_0803AD2C:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r5]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x37\n\t"
        "	bl GetMonData3\n\t"
        "_0803AD3E:\n\t"
        "	str r0, [r6]\n\t"
        "	adds r6, #8\n\t"
        "	adds r5, #8\n\t"
        "	adds r7, #1\n\t"
        "	cmp r7, #5\n\t"
        "	ble _0803ACF6\n\t"
        "	ldr r1, _0803AD5C\n\t"
        "	ldr r0, _0803AD60\n\t"
        "_0803AD4E:\n\t"
        "	str r0, [r1]\n\t"
        "_0803AD50:\n\t"
        "	add sp, #0x30\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803AD5C: .4byte gBattleMainFunc\n\t"
        "_0803AD60: .4byte 0x0803AD9D\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void SpriteCB_AnimFaintOpponent(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r0, [r4, #0x36]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r4, #0x36]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803970C\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r4, #0x36]\n\t"
        "	ldrh r0, [r4, #0x26]\n\t"
        "	adds r0, #8\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r4, #0x34]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bge _080396C0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FreeSpriteOamMatrix\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroySprite\n\t"
        "	b _0803970C\n\t"
        "_080396C0:\n\t"
        "	ldrh r0, [r4, #0x2e]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerPosition\n\t"
        "	ldr r1, _08039714\n\t"
        "	ldr r1, [r1]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r1, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, _08039718\n\t"
        "	movs r3, #0x2e\n\t"
        "	ldrsh r0, [r4, r3]\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0xb\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r2, #0x34\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r2, #0\n\t"
        "	movs r0, #0xff\n\t"
        "_080396F2:\n\t"
        "	strb r2, [r1]\n\t"
        "	adds r1, #1\n\t"
        "	subs r0, #1\n\t"
        "	cmp r0, #0\n\t"
        "	bge _080396F2\n\t"
        "	ldr r0, _08039718\n\t"
        "	movs r3, #0x2e\n\t"
        "	ldrsh r1, [r4, r3]\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "_0803970C:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08039714: .4byte gMonSpritesGfxPtr\n\t"
        "_08039718: .4byte gBattleMonForms\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void SpriteCB_BounceEffect(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r0, [r4, #0x34]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	movs r1, #0x36\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08039A54\n\t"
        "	movs r2, #0x2e\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	b _08039A58\n\t"
        "_08039A54:\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "_08039A58:\n\t"
        "	movs r2, #0x32\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl Sin\n\t"
        "	ldr r2, _08039A84\n\t"
        "	lsls r1, r5, #4\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrh r2, [r4, #0x32]\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r0, [r1, #0x26]\n\t"
        "	ldrh r0, [r4, #0x30]\n\t"
        "	ldrh r1, [r4, #0x2e]\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0xff\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08039A84: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void HandleEndTurn_FinishBattle(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	ldr r0, _0803D994\n\t"
        "	ldrb r0, [r0]\n\t"
        "	subs r0, #0xb\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bls _0803D92E\n\t"
        "	b _0803DA50\n\t"
        "_0803D92E:\n\t"
        "	ldr r0, _0803D998\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0803D99C\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0803D9F6\n\t"
        "	ldr r2, _0803D9A0\n\t"
        "	strb r1, [r2]\n\t"
        "	ldr r0, _0803D9A4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r1, r0\n\t"
        "	bhs _0803D9F2\n\t"
        "	adds r5, r2, #0\n\t"
        "	ldr r0, _0803D9A8\n\t"
        "	mov r8, r0\n\t"
        "	movs r7, #0x64\n\t"
        "	ldr r6, _0803D9AC\n\t"
        "_0803D950:\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803D9E0\n\t"
        "	ldr r4, _0803D9B0\n\t"
        "	ldrh r0, [r4, #6]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803D9B4\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	muls r0, r7, r0\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #0xb\n\t"
        "	movs r2, #0\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r4, #6]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	muls r0, r7, r0\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #2\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #8\n\t"
        "	bl GetMonData3\n\t"
        "	b _0803D9E0\n\t"
        "	.align 2, 0\n\t"
        "_0803D994: .4byte gCurrentActionFuncId\n\t"
        "_0803D998: .4byte gBattleTypeFlags\n\t"
        "_0803D99C: .4byte 0x023F0B92\n\t"
        "_0803D9A0: .4byte gActiveBattler\n\t"
        "_0803D9A4: .4byte gBattlersCount\n\t"
        "_0803D9A8: .4byte gBattlerPartyIndexes\n\t"
        "_0803D9AC: .4byte gPlayerParty\n\t"
        "_0803D9B0: .4byte gBattleResults\n\t"
        "_0803D9B4:\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	muls r0, r7, r0\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #0xb\n\t"
        "	movs r2, #0\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	muls r0, r7, r0\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #2\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x14\n\t"
        "	bl GetMonData3\n\t"
        "_0803D9E0:\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r5]\n\t"
        "	ldr r1, _0803DA30\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	blo _0803D950\n\t"
        "_0803D9F2:\n\t"
        "	bl PutPokemonTodayCaughtOnAir\n\t"
        "_0803D9F6:\n\t"
        "	ldr r0, _0803DA34\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0803DA38\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803DA12\n\t"
        "	ldr r0, _0803DA3C\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803DA12\n\t"
        "	bl sub_080EECA4\n\t"
        "_0803DA12:\n\t"
        "	bl sub_0818619C\n\t"
        "	movs r0, #3\n\t"
        "	bl BeginFastPaletteFade\n\t"
        "	movs r0, #5\n\t"
        "	bl FadeOutMapMusic\n\t"
        "	ldr r1, _0803DA40\n\t"
        "	ldr r0, _0803DA44\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r1, _0803DA48\n\t"
        "	ldr r0, _0803DA4C\n\t"
        "	str r0, [r1]\n\t"
        "	b _0803DA6A\n\t"
        "	.align 2, 0\n\t"
        "_0803DA30: .4byte gBattlersCount\n\t"
        "_0803DA34: .4byte gBattleTypeFlags\n\t"
        "_0803DA38: .4byte 0x023F0B9A\n\t"
        "_0803DA3C: .4byte gBattleResults\n\t"
        "_0803DA40: .4byte gBattleMainFunc\n\t"
        "_0803DA44: .4byte 0x0803DA81\n\t"
        "_0803DA48: .4byte gCB2_AfterEvolution\n\t"
        "_0803DA4C: .4byte BattleMainCB2 + 1\n\t"
        "_0803DA50:\n\t"
        "	ldr r0, _0803DA74\n\t"
        "	ldr r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803DA6A\n\t"
        "	ldr r1, _0803DA78\n\t"
        "	ldr r0, _0803DA7C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl _call_via_r0\n\t"
        "_0803DA6A:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803DA74: .4byte gBattleControllerExecFlags\n\t"
        "_0803DA78: .4byte gBattleScriptingCommandsTable\n\t"
        "_0803DA7C: .4byte gBattlescriptCurrInstr\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void HandleEndTurn_BattleWon(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r1, _0803D540\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803D544\n\t"
        "	ldr r2, [r1]\n\t"
        "	ldr r0, _0803D548\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803D564\n\t"
        "	ldr r1, _0803D54C\n\t"
        "	ldr r4, _0803D550\n\t"
        "	ldrb r0, [r4]\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _0803D554\n\t"
        "	ldrb r0, [r4]\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0803D558\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803D55C\n\t"
        "	ldr r0, _0803D560\n\t"
        "	str r0, [r1]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	b _0803D6E4\n\t"
        "	.align 2, 0\n\t"
        "_0803D540: .4byte gCurrentActionFuncId\n\t"
        "_0803D544: .4byte gBattleTypeFlags\n\t"
        "_0803D548: .4byte gUnknown_2000002\n\t"
        "_0803D54C: .4byte gSpecialVar_Result\n\t"
        "_0803D550: .4byte gBattleOutcome\n\t"
        "_0803D554: .4byte gBattleTextBuff1\n\t"
        "_0803D558: .4byte gBattlerAttacker\n\t"
        "_0803D55C: .4byte gBattlescriptCurrInstr\n\t"
        "_0803D560: .4byte BattleScript_LinkBattleWonOrLost\n\t"
        "_0803D564:\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803D5A0\n\t"
        "	ldr r0, _0803D58C\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0803D5A0\n\t"
        "	bl BattleStopLowHpSound\n\t"
        "	ldr r1, _0803D590\n\t"
        "	ldr r0, _0803D594\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _0803D598\n\t"
        "	ldrh r1, [r0]\n\t"
        "	ldr r0, _0803D59C\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0803D58A\n\t"
        "	b _0803D6CA\n\t"
        "_0803D58A:\n\t"
        "	b _0803D6D4\n\t"
        "	.align 2, 0\n\t"
        "_0803D58C: .4byte 0x043F0900\n\t"
        "_0803D590: .4byte gBattlescriptCurrInstr\n\t"
        "_0803D594: .4byte BattleScript_FrontierTrainerBattleWon\n\t"
        "_0803D598: .4byte gTrainerBattleOpponent_A\n\t"
        "_0803D59C: .4byte 0x000003FE\n\t"
        "_0803D5A0:\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r1, #0xa\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #8\n\t"
        "	beq _0803D5AC\n\t"
        "	b _0803D6DE\n\t"
        "_0803D5AC:\n\t"
        "	bl BattleStopLowHpSound\n\t"
        "	ldr r1, _0803D5D4\n\t"
        "	ldr r0, _0803D5D8\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r1, _0803D5DC\n\t"
        "	ldr r0, _0803D5E0\n\t"
        "	ldrh r0, [r0]\n\t"
        "	lsls r0, r0, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	subs r0, #3\n\t"
        "	cmp r0, #0x32\n\t"
        "	bls _0803D5CA\n\t"
        "	b _0803D6D4\n\t"
        "_0803D5CA:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0803D5E4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0803D5D4: .4byte gBattlescriptCurrInstr\n\t"
        "_0803D5D8: .4byte BattleScript_LocalTrainerBattleWon\n\t"
        "_0803D5DC: .4byte gTrainers\n\t"
        "_0803D5E0: .4byte gTrainerBattleOpponent_A\n\t"
        "_0803D5E4: .4byte 0x0803D5E8\n\t"
        "_0803D5E8: @ jump table\n\t"
        "	.4byte _0803D6C0 @ case 0\n\t"
        "	.4byte _0803D6D4 @ case 1\n\t"
        "	.4byte _0803D6D4 @ case 2\n\t"
        "	.4byte _0803D6D4 @ case 3\n\t"
        "	.4byte _0803D6D4 @ case 4\n\t"
        "	.4byte _0803D6D4 @ case 5\n\t"
        "	.4byte _0803D6C0 @ case 6\n\t"
        "	.4byte _0803D6D4 @ case 7\n\t"
        "	.4byte _0803D6C0 @ case 8\n\t"
        "	.4byte _0803D6D4 @ case 9\n\t"
        "	.4byte _0803D6C0 @ case 10\n\t"
        "	.4byte _0803D6D4 @ case 11\n\t"
        "	.4byte _0803D6D4 @ case 12\n\t"
        "	.4byte _0803D6D4 @ case 13\n\t"
        "	.4byte _0803D6D4 @ case 14\n\t"
        "	.4byte _0803D6D4 @ case 15\n\t"
        "	.4byte _0803D6D4 @ case 16\n\t"
        "	.4byte _0803D6D4 @ case 17\n\t"
        "	.4byte _0803D6D4 @ case 18\n\t"
        "	.4byte _0803D6D4 @ case 19\n\t"
        "	.4byte _0803D6D4 @ case 20\n\t"
        "	.4byte _0803D6D4 @ case 21\n\t"
        "	.4byte _0803D6D4 @ case 22\n\t"
        "	.4byte _0803D6D4 @ case 23\n\t"
        "	.4byte _0803D6D4 @ case 24\n\t"
        "	.4byte _0803D6D4 @ case 25\n\t"
        "	.4byte _0803D6D4 @ case 26\n\t"
        "	.4byte _0803D6D4 @ case 27\n\t"
        "	.4byte _0803D6B4 @ case 28\n\t"
        "	.4byte _0803D6CA @ case 29\n\t"
        "	.4byte _0803D6D4 @ case 30\n\t"
        "	.4byte _0803D6D4 @ case 31\n\t"
        "	.4byte _0803D6D4 @ case 32\n\t"
        "	.4byte _0803D6D4 @ case 33\n\t"
        "	.4byte _0803D6D4 @ case 34\n\t"
        "	.4byte _0803D6B4 @ case 35\n\t"
        "	.4byte _0803D6D4 @ case 36\n\t"
        "	.4byte _0803D6D4 @ case 37\n\t"
        "	.4byte _0803D6D4 @ case 38\n\t"
        "	.4byte _0803D6D4 @ case 39\n\t"
        "	.4byte _0803D6D4 @ case 40\n\t"
        "	.4byte _0803D6D4 @ case 41\n\t"
        "	.4byte _0803D6D4 @ case 42\n\t"
        "	.4byte _0803D6D4 @ case 43\n\t"
        "	.4byte _0803D6D4 @ case 44\n\t"
        "	.4byte _0803D6D4 @ case 45\n\t"
        "	.4byte _0803D6C0 @ case 46\n\t"
        "	.4byte _0803D6D4 @ case 47\n\t"
        "	.4byte _0803D6D4 @ case 48\n\t"
        "	.4byte _0803D6D4 @ case 49\n\t"
        "	.4byte _0803D6C0 @ case 50\n\t"
        "_0803D6B4:\n\t"
        "	ldr r0, _0803D6BC\n\t"
        "	bl PlayBGM\n\t"
        "	b _0803D6E4\n\t"
        "	.align 2, 0\n\t"
        "_0803D6BC: .4byte SPECIAL_sub_080EBE30\n\t"
        "_0803D6C0:\n\t"
        "	movs r0, #0xd4\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl PlayBGM\n\t"
        "	b _0803D6E4\n\t"
        "_0803D6CA:\n\t"
        "	movs r0, #0xb1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl PlayBGM\n\t"
        "	b _0803D6E4\n\t"
        "_0803D6D4:\n\t"
        "	movs r0, #0xce\n\t"
        "	lsls r0, r0, #1\n\t"
        "	bl PlayBGM\n\t"
        "	b _0803D6E4\n\t"
        "_0803D6DE:\n\t"
        "	ldr r1, _0803D6F0\n\t"
        "	ldr r0, _0803D6F4\n\t"
        "	str r0, [r1]\n\t"
        "_0803D6E4:\n\t"
        "	ldr r1, _0803D6F8\n\t"
        "	ldr r0, _0803D6FC\n\t"
        "	str r0, [r1]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803D6F0: .4byte gBattlescriptCurrInstr\n\t"
        "_0803D6F4: .4byte BattleScript_PayDayMoneyAndPickUpItems\n\t"
        "_0803D6F8: .4byte gBattleMainFunc\n\t"
        "_0803D6FC: .4byte HandleEndTurn_FinishBattle + 1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void HandleEndTurn_BattleLost(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r1, _0803D748\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _0803D74C\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0803D750\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803D7BC\n\t"
        "	ldr r0, _0803D754\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803D784\n\t"
        "	ldr r3, _0803D758\n\t"
        "	ldrb r2, [r3]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803D76C\n\t"
        "	ldr r1, _0803D75C\n\t"
        "	ldr r0, _0803D760\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r3]\n\t"
        "	ldr r0, _0803D764\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0803D768\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r2, #8\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0803D7C2\n\t"
        "	.align 2, 0\n\t"
        "_0803D748: .4byte gCurrentActionFuncId\n\t"
        "_0803D74C: .4byte gBattleTypeFlags\n\t"
        "_0803D750: .4byte gUnknown_2000002\n\t"
        "_0803D754: .4byte 0x003F0100\n\t"
        "_0803D758: .4byte gBattleOutcome\n\t"
        "_0803D75C: .4byte gBattlescriptCurrInstr\n\t"
        "_0803D760: .4byte BattleScript_PrintPlayerForfeitedLinkBattle\n\t"
        "_0803D764: .4byte gSaveBlock2Ptr\n\t"
        "_0803D768: .4byte 0x00000CA9\n\t"
        "_0803D76C:\n\t"
        "	ldr r1, _0803D77C\n\t"
        "	ldr r0, _0803D780\n\t"
        "	str r0, [r1]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r3]\n\t"
        "	b _0803D7C2\n\t"
        "	.align 2, 0\n\t"
        "_0803D77C: .4byte gBattlescriptCurrInstr\n\t"
        "_0803D780: .4byte BattleScript_FrontierLinkBattleLost\n\t"
        "_0803D784:\n\t"
        "	ldr r1, _0803D7A8\n\t"
        "	ldr r4, _0803D7AC\n\t"
        "	ldrb r0, [r4]\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0803D7B0\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803D7B4\n\t"
        "	ldr r0, _0803D7B8\n\t"
        "	str r0, [r1]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	b _0803D7C2\n\t"
        "	.align 2, 0\n\t"
        "_0803D7A8: .4byte gBattleTextBuff1\n\t"
        "_0803D7AC: .4byte gBattleOutcome\n\t"
        "_0803D7B0: .4byte gBattlerAttacker\n\t"
        "_0803D7B4: .4byte gBattlescriptCurrInstr\n\t"
        "_0803D7B8: .4byte BattleScript_LinkBattleWonOrLost\n\t"
        "_0803D7BC:\n\t"
        "	ldr r1, _0803D7D0\n\t"
        "	ldr r0, _0803D7D4\n\t"
        "	str r0, [r1]\n\t"
        "_0803D7C2:\n\t"
        "	ldr r1, _0803D7D8\n\t"
        "	ldr r0, _0803D7DC\n\t"
        "	str r0, [r1]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803D7D0: .4byte gBattlescriptCurrInstr\n\t"
        "_0803D7D4: .4byte BattleScript_LocalBattleLost\n\t"
        "_0803D7D8: .4byte gBattleMainFunc\n\t"
        "_0803D7DC: .4byte HandleEndTurn_FinishBattle + 1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void SetPlayerBerryDataInBattleStruct(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	ldr r0, _08036A00\n\t"
        "	ldr r5, [r0]\n\t"
        "	movs r0, #0xc2\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r4, r5, r0\n\t"
        "	bl IsEnigmaBerryValid\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08036A14\n\t"
        "	movs r2, #0\n\t"
        "	ldr r7, _08036A04\n\t"
        "	movs r1, #0xc6\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r5, r5, r1\n\t"
        "	adds r6, r7, #0\n\t"
        "	ldr r3, _08036A08\n\t"
        "_080369BA:\n\t"
        "	adds r0, r4, r2\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r3\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #5\n\t"
        "	ble _080369BA\n\t"
        "	adds r1, r4, r2\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r2, #0\n\t"
        "	adds r3, r5, #0\n\t"
        "	ldr r6, _08036A04\n\t"
        "	ldr r5, _08036A0C\n\t"
        "_080369DA:\n\t"
        "	adds r0, r3, r2\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r5\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #0x11\n\t"
        "	ble _080369DA\n\t"
        "	ldr r0, [r7]\n\t"
        "	ldr r1, _08036A10\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r4, #7]\n\t"
        "	ldr r0, [r7]\n\t"
        "	adds r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	b _08036A54\n\t"
        "	.align 2, 0\n\t"
        "_08036A00: .4byte gBattleStruct\n\t"
        "_08036A04: .4byte gSaveBlock1Ptr\n\t"
        "_08036A08: .4byte 0x000031F8\n\t"
        "_08036A0C: .4byte 0x00003214\n\t"
        "_08036A10: .4byte 0x00003226\n\t"
        "_08036A14:\n\t"
        "	movs r0, #0xaf\n\t"
        "	bl ItemIdToBerryType\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBerryInfo\n\t"
        "	adds r3, r0, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r0, #0xc6\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r5, r5, r0\n\t"
        "_08036A2C:\n\t"
        "	adds r0, r4, r2\n\t"
        "	adds r1, r3, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #5\n\t"
        "	ble _08036A2C\n\t"
        "	adds r1, r4, r2\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r2, #0\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r1, #0x11\n\t"
        "_08036A48:\n\t"
        "	strb r2, [r1]\n\t"
        "	subs r1, #1\n\t"
        "	cmp r1, r0\n\t"
        "	bge _08036A48\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r4, #7]\n\t"
        "_08036A54:\n\t"
        "	strb r0, [r4, #0x1a]\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_08037770(u8 a)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sl, r0\n\t"
        "	movs r7, #0\n\t"
        "	ldr r6, _08037820\n\t"
        "	mov sb, r6\n\t"
        "_08037786:\n\t"
        "	mov r0, sl\n\t"
        "	adds r1, r7, r0\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r4, r1, #0\n\t"
        "	muls r4, r0, r4\n\t"
        "	ldr r0, _08037824\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	lsls r5, r7, #5\n\t"
        "	strh r0, [r6]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xc\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r6, #2]\n\t"
        "	movs r0, #4\n\t"
        "	add r0, sb\n\t"
        "	mov r8, r0\n\t"
        "	adds r2, r5, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #2\n\t"
        "	bl GetMonData3\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x38\n\t"
        "	bl GetMonData3\n\t"
        "	strb r0, [r6, #0xf]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r6, #0x10]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x3a\n\t"
        "	bl GetMonData3\n\t"
        "	strh r0, [r6, #0x12]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x37\n\t"
        "	bl GetMonData3\n\t"
        "	mov r1, sb\n\t"
        "	adds r1, #0x14\n\t"
        "	adds r5, r5, r1\n\t"
        "	str r0, [r5]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl GetMonData3\n\t"
        "	str r0, [r6, #0x18]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetMonGender\n\t"
        "	strb r0, [r6, #0x1c]\n\t"
        "	adds r6, #0x20\n\t"
        "	adds r7, #1\n\t"
        "	cmp r7, #2\n\t"
        "	ble _08037786\n\t"
        "	ldr r0, _08037828\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov r1, r8\n\t"
        "	subs r1, #4\n\t"
        "	movs r2, #0x60\n\t"
        "	bl memcpy\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08037820: .4byte gMultiPartnerParty\n\t"
        "_08037824: .4byte gPlayerParty\n\t"
        "_08037828: .4byte sMultiPartnerPartyBuffer\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void TryDoEventsBeforeFirstTurn(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	ldr r0, _0803B2B0\n\t"
        "	ldr r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B286\n\t"
        "	b _0803B4F6\n\t"
        "_0803B286:\n\t"
        "	ldr r0, _0803B2B4\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x4c\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803B306\n\t"
        "	movs r5, #0\n\t"
        "	ldr r1, _0803B2B8\n\t"
        "	mov sl, r1\n\t"
        "	ldrb r3, [r1]\n\t"
        "	cmp r5, r3\n\t"
        "	bge _0803B2AC\n\t"
        "	ldr r2, _0803B2BC\n\t"
        "_0803B2A0:\n\t"
        "	adds r0, r5, r2\n\t"
        "	strb r5, [r0]\n\t"
        "	adds r5, #1\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _0803B2A0\n\t"
        "_0803B2AC:\n\t"
        "	movs r5, #0\n\t"
        "	b _0803B2FC\n\t"
        "	.align 2, 0\n\t"
        "_0803B2B0: .4byte gBattleControllerExecFlags\n\t"
        "_0803B2B4: .4byte gBattleStruct\n\t"
        "_0803B2B8: .4byte gBattlersCount\n\t"
        "_0803B2BC: .4byte gBattlerByTurnOrder\n\t"
        "_0803B2C0:\n\t"
        "	adds r4, r5, #1\n\t"
        "	mov r8, r4\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r8, r1\n\t"
        "	bge _0803B2FA\n\t"
        "	ldr r6, _0803B334\n\t"
        "	ldr r1, _0803B338\n\t"
        "	mov sl, r1\n\t"
        "	lsls r7, r5, #0x18\n\t"
        "_0803B2D2:\n\t"
        "	adds r0, r5, r6\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, r6\n\t"
        "	ldrb r1, [r1]\n\t"
        "	movs r2, #1\n\t"
        "	bl GetWhoStrikesFirst\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B2F0\n\t"
        "	lsls r1, r4, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsrs r0, r7, #0x18\n\t"
        "	bl SwapTurnOrder\n\t"
        "_0803B2F0:\n\t"
        "	adds r4, #1\n\t"
        "	ldr r0, _0803B338\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r4, r0\n\t"
        "	blt _0803B2D2\n\t"
        "_0803B2FA:\n\t"
        "	mov r5, r8\n\t"
        "_0803B2FC:\n\t"
        "	mov r1, sl\n\t"
        "	ldrb r0, [r1]\n\t"
        "	subs r0, #1\n\t"
        "	cmp r5, r0\n\t"
        "	blt _0803B2C0\n\t"
        "_0803B306:\n\t"
        "	ldr r5, _0803B33C\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r4, #0xd1\n\t"
        "	lsls r4, r4, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803B340\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0xff\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B340\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	b _0803B4F6\n\t"
        "	.align 2, 0\n\t"
        "_0803B334: .4byte gBattlerByTurnOrder\n\t"
        "_0803B338: .4byte gBattlersCount\n\t"
        "_0803B33C: .4byte gBattleStruct\n\t"
        "_0803B340:\n\t"
        "	ldr r2, _0803B508\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x4c\n\t"
        "	ldr r1, _0803B50C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bhs _0803B39A\n\t"
        "	ldr r5, _0803B510\n\t"
        "	adds r4, r2, #0\n\t"
        "_0803B354:\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x4c\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B37A\n\t"
        "	mov r0, sb\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "_0803B37A:\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, #0x4c\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r3, sb\n\t"
        "	cmp r3, #0\n\t"
        "	beq _0803B38C\n\t"
        "	b _0803B4F6\n\t"
        "_0803B38C:\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x4c\n\t"
        "	ldr r1, _0803B50C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	blo _0803B354\n\t"
        "_0803B39A:\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #9\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B3B4\n\t"
        "	b _0803B4F6\n\t"
        "_0803B3B4:\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xb\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B3CA\n\t"
        "	b _0803B4F6\n\t"
        "_0803B3CA:\n\t"
        "	ldr r2, _0803B508\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0xd9\n\t"
        "	ldr r1, _0803B50C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bhs _0803B41E\n\t"
        "	ldr r5, _0803B510\n\t"
        "	adds r4, r2, #0\n\t"
        "_0803B3DE:\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0xd9\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ItemBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B400\n\t"
        "	mov r0, sb\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "_0803B400:\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, #0xd9\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r0, sb\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803B4F6\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0xd9\n\t"
        "	ldr r1, _0803B50C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	blo _0803B3DE\n\t"
        "_0803B41E:\n\t"
        "	movs r5, #0\n\t"
        "	ldr r1, _0803B508\n\t"
        "	mov r8, r1\n\t"
        "	movs r7, #6\n\t"
        "	ldr r6, _0803B514\n\t"
        "	ldr r2, _0803B518\n\t"
        "	movs r4, #0xff\n\t"
        "	movs r3, #0\n\t"
        "_0803B42E:\n\t"
        "	mov r1, r8\n\t"
        "	ldr r0, [r1]\n\t"
        "	adds r0, r5, r0\n\t"
        "	adds r0, #0x5c\n\t"
        "	strb r7, [r0]\n\t"
        "	adds r1, r5, r6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	orrs r0, r4\n\t"
        "	strb r0, [r1]\n\t"
        "	strh r3, [r2]\n\t"
        "	adds r2, #2\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #3\n\t"
        "	ble _0803B42E\n\t"
        "	movs r0, #0\n\t"
        "	bl TurnValuesCleanUp\n\t"
        "	bl SpecialStatusesClear\n\t"
        "	ldr r0, _0803B508\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x91\n\t"
        "	ldr r1, _0803B51C\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _0803B520\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_0814FA04\n\t"
        "	ldr r1, _0803B524\n\t"
        "	ldr r0, _0803B528\n\t"
        "	str r0, [r1]\n\t"
        "	bl ResetSentPokesToOpponentValue\n\t"
        "	ldr r1, _0803B52C\n\t"
        "	movs r2, #0\n\t"
        "	adds r0, r1, #7\n\t"
        "_0803B478:\n\t"
        "	strb r2, [r0]\n\t"
        "	subs r0, #1\n\t"
        "	cmp r0, r1\n\t"
        "	bge _0803B478\n\t"
        "	movs r5, #0\n\t"
        "	ldr r3, _0803B50C\n\t"
        "	ldr r2, _0803B508\n\t"
        "	ldr r6, _0803B530\n\t"
        "	ldr r7, _0803B534\n\t"
        "	ldrb r0, [r3]\n\t"
        "	cmp r5, r0\n\t"
        "	bge _0803B4AA\n\t"
        "	ldr r0, _0803B538\n\t"
        "	movs r4, #9\n\t"
        "	rsbs r4, r4, #0\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r1, #0x50\n\t"
        "_0803B49A:\n\t"
        "	ldr r0, [r1]\n\t"
        "	ands r0, r4\n\t"
        "	str r0, [r1]\n\t"
        "	adds r1, #0x58\n\t"
        "	adds r5, #1\n\t"
        "	ldrb r0, [r3]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _0803B49A\n\t"
        "_0803B4AA:\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r2]\n\t"
        "	strb r1, [r0, #1]\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r3, #0xd0\n\t"
        "	lsls r3, r3, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r3, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r6, #0x14]\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, #0x4d\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r2]\n\t"
        "	strb r1, [r0, #3]\n\t"
        "	strb r1, [r7]\n\t"
        "	bl Random\n\t"
        "	ldr r1, _0803B53C\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _0803B540\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xb\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B4F6\n\t"
        "	bl StopCryAndClearCrySongs\n\t"
        "	ldr r0, _0803B544\n\t"
        "	bl BattleScriptExecute\n\t"
        "_0803B4F6:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803B508: .4byte gBattleStruct\n\t"
        "_0803B50C: .4byte gBattlersCount\n\t"
        "_0803B510: .4byte gBattlerByTurnOrder\n\t"
        "_0803B514: .4byte gChosenActionByBattler\n\t"
        "_0803B518: .4byte gChosenMoveByBattler\n\t"
        "_0803B51C: .4byte gAbsentBattlerFlags\n\t"
        "_0803B520: .4byte gText_EmptyString3\n\t"
        "_0803B524: .4byte gBattleMainFunc\n\t"
        "_0803B528: .4byte HandleAction_TryFinish + 1\n\t"
        "_0803B52C: .4byte gBattleCommunication\n\t"
        "_0803B530: .4byte gBattleScripting\n\t"
        "_0803B534: .4byte gMoveResultFlags\n\t"
        "_0803B538: .4byte gBattleMons\n\t"
        "_0803B53C: .4byte gRandomTurnNumber\n\t"
        "_0803B540: .4byte gBattleTypeFlags\n\t"
        "_0803B544: .4byte BattleScript_ArenaTurnBeginning\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void BattleIntroDrawTrainersOrMonsSprites(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	ldr r0, _0803A92C\n\t"
        "	ldr r1, [r0]\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803A8DC\n\t"
        "	b _0803AB92\n\t"
        "_0803A8DC:\n\t"
        "	ldr r2, _0803A930\n\t"
        "	strb r1, [r2]\n\t"
        "	ldr r0, _0803A934\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r1, r0\n\t"
        "	blo _0803A8EA\n\t"
        "	b _0803AB8C\n\t"
        "_0803A8EA:\n\t"
        "	movs r7, #0x58\n\t"
        "	ldr r0, _0803A938\n\t"
        "	mov r8, r0\n\t"
        "	mov sb, r2\n\t"
        "	movs r1, #0x48\n\t"
        "	add r1, r8\n\t"
        "	mov sl, r1\n\t"
        "_0803A8F8:\n\t"
        "	ldr r0, _0803A93C\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803A940\n\t"
        "	ldr r4, _0803A930\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803A940\n\t"
        "	ldrb r0, [r4]\n\t"
        "	muls r0, r7, r0\n\t"
        "	mov r2, r8\n\t"
        "	adds r3, r0, r2\n\t"
        "	movs r2, #0\n\t"
        "	movs r1, #0\n\t"
        "_0803A91E:\n\t"
        "	adds r0, r3, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #0x57\n\t"
        "	bls _0803A91E\n\t"
        "	b _0803AA0E\n\t"
        "	.align 2, 0\n\t"
        "_0803A92C: .4byte gBattleControllerExecFlags\n\t"
        "_0803A930: .4byte gActiveBattler\n\t"
        "_0803A934: .4byte gBattlersCount\n\t"
        "_0803A938: .4byte gBattleMons\n\t"
        "_0803A93C: .4byte gBattleTypeFlags\n\t"
        "_0803A940:\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	muls r0, r7, r0\n\t"
        "	mov r2, r8\n\t"
        "	adds r3, r0, r2\n\t"
        "	movs r2, #0\n\t"
        "	ldr r6, _0803AA88\n\t"
        "	ldr r5, _0803AA8C\n\t"
        "	ldr r4, _0803AA90\n\t"
        "_0803A952:\n\t"
        "	adds r0, r3, r2\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r1, r1, #9\n\t"
        "	adds r1, #4\n\t"
        "	adds r1, r2, r1\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #0x57\n\t"
        "	bls _0803A952\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r2, r0, #0\n\t"
        "	muls r2, r7, r2\n\t"
        "	add r2, r8\n\t"
        "	ldrh r1, [r2]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0, #6]\n\t"
        "	adds r2, #0x21\n\t"
        "	strb r0, [r2]\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	adds r2, r0, #0\n\t"
        "	muls r2, r7, r2\n\t"
        "	add r2, r8\n\t"
        "	ldrh r1, [r2]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0, #7]\n\t"
        "	adds r2, #0x22\n\t"
        "	strb r0, [r2]\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r1, r0, #0\n\t"
        "	muls r1, r7, r1\n\t"
        "	add r1, r8\n\t"
        "	ldrh r0, [r1]\n\t"
        "	ldrb r1, [r1, #0x17]\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	bl GetAbilityBySpecies\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r1, [r2]\n\t"
        "	muls r1, r7, r1\n\t"
        "	add r1, r8\n\t"
        "	adds r1, #0x20\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	bl GetBattlerSide\n\t"
        "	ldr r1, _0803AA94\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r0, #0xa8\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r1, r0\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	muls r0, r7, r0\n\t"
        "	add r0, r8\n\t"
        "	ldrh r0, [r0, #0x28]\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r2, #0\n\t"
        "	ldr r4, _0803AA90\n\t"
        "	movs r5, #0x58\n\t"
        "	ldr r1, _0803AA98\n\t"
        "	adds r6, r4, #0\n\t"
        "	movs r0, #0x18\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r0, r0, r1\n\t"
        "	mov ip, r0\n\t"
        "	movs r3, #6\n\t"
        "_0803A9EE:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r3, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #7\n\t"
        "	ble _0803A9EE\n\t"
        "	ldrb r0, [r6]\n\t"
        "	adds r1, r0, #0\n\t"
        "	muls r1, r7, r1\n\t"
        "	mov r0, ip\n\t"
        "	adds r0, #0x50\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "_0803AA0E:\n\t"
        "	ldr r4, _0803AA90\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803AA28\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitDrawTrainerPic\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "_0803AA28:\n\t"
        "	ldr r5, _0803AA9C\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803AAA4\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0803AA4E\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitDrawTrainerPic\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "_0803AA4E:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0803AB04\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _0803AAA0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803AB04\n\t"
        "	ldrb r0, [r4]\n\t"
        "	muls r0, r7, r0\n\t"
        "	add r0, r8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl HoennToNationalOrder\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldrb r1, [r4]\n\t"
        "	muls r1, r7, r1\n\t"
        "	add r1, sl\n\t"
        "	ldr r2, [r1]\n\t"
        "	movs r1, #2\n\t"
        "	bl HandleSetPokedexFlag\n\t"
        "	b _0803AB04\n\t"
        "	.align 2, 0\n\t"
        "_0803AA88: .4byte gSpeciesInfo\n\t"
        "_0803AA8C: .4byte gBattleBufferB\n\t"
        "_0803AA90: .4byte gActiveBattler\n\t"
        "_0803AA94: .4byte gBattleStruct\n\t"
        "_0803AA98: .4byte gUnknown_2023D40\n\t"
        "_0803AA9C: .4byte gBattleTypeFlags\n\t"
        "_0803AAA0: .4byte 0x063F0902\n\t"
        "_0803AAA4:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0803AB04\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _0803ABA0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803AADA\n\t"
        "	ldrb r0, [r4]\n\t"
        "	muls r0, r7, r0\n\t"
        "	add r0, r8\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl HoennToNationalOrder\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldrb r1, [r4]\n\t"
        "	muls r1, r7, r1\n\t"
        "	add r1, sl\n\t"
        "	ldr r2, [r1]\n\t"
        "	movs r1, #2\n\t"
        "	bl HandleSetPokedexFlag\n\t"
        "_0803AADA:\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitLoadMonSprite\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "	ldr r1, _0803ABA4\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0803ABA8\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0xb\n\t"
        "	movs r2, #0\n\t"
        "	bl GetMonData3\n\t"
        "	ldr r1, _0803ABAC\n\t"
        "	strh r0, [r1, #0x20]\n\t"
        "_0803AB04:\n\t"
        "	ldr r0, _0803ABB0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803AB3A\n\t"
        "	ldr r4, _0803ABB4\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0803AB2E\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0803AB3A\n\t"
        "_0803AB2E:\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitDrawTrainerPic\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "_0803AB3A:\n\t"
        "	ldr r0, _0803ABB0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803AB64\n\t"
        "	ldr r4, _0803ABB4\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0803AB64\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitDrawTrainerPic\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "_0803AB64:\n\t"
        "	ldr r0, _0803ABB0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xb\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803AB76\n\t"
        "	bl BattleArena_InitPoints\n\t"
        "_0803AB76:\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803ABB8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrb r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bhs _0803AB8C\n\t"
        "	b _0803A8F8\n\t"
        "_0803AB8C:\n\t"
        "	ldr r1, _0803ABBC\n\t"
        "	ldr r0, _0803ABC0\n\t"
        "	str r0, [r1]\n\t"
        "_0803AB92:\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803ABA0: .4byte 0x063F0902\n\t"
        "_0803ABA4: .4byte gBattlerPartyIndexes\n\t"
        "_0803ABA8: .4byte gEnemyParty\n\t"
        "_0803ABAC: .4byte gBattleResults\n\t"
        "_0803ABB0: .4byte gBattleTypeFlags\n\t"
        "_0803ABB4: .4byte gActiveBattler\n\t"
        "_0803ABB8: .4byte gBattlersCount\n\t"
        "_0803ABBC: .4byte gBattleMainFunc\n\t"
        "_0803ABC0: .4byte BattleIntroDrawPartySummaryScreens + 1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void BattleStartClearSetData(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	movs r0, #0\n\t"
        "	bl TurnValuesCleanUp\n\t"
        "	bl SpecialStatusesClear\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	ldr r0, _08039C80\n\t"
        "	mov sl, r0\n\t"
        "	ldr r1, _08039C84\n\t"
        "	mov sb, r1\n\t"
        "	ldr r0, _08039C88\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _08039C8C\n\t"
        "	mov ip, r1\n\t"
        "	ldr r5, _08039C90\n\t"
        "	movs r4, #0\n\t"
        "	ldr r7, _08039C94\n\t"
        "	ldr r6, _08039C98\n\t"
        "_08039BB4:\n\t"
        "	ldr r0, _08039C9C\n\t"
        "	adds r0, r4, r0\n\t"
        "	str r3, [r0]\n\t"
        "	movs r1, #0\n\t"
        "_08039BBC:\n\t"
        "	adds r0, r5, r1\n\t"
        "	strb r3, [r0]\n\t"
        "	adds r1, #1\n\t"
        "	cmp r1, #0x1b\n\t"
        "	bls _08039BBC\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r5, #0x16]\n\t"
        "	ldr r1, _08039CA0\n\t"
        "	adds r0, r2, r1\n\t"
        "	strb r3, [r0]\n\t"
        "	mov r0, ip\n\t"
        "	strh r3, [r0]\n\t"
        "	mov r1, r8\n\t"
        "	strh r3, [r1]\n\t"
        "	mov r0, sb\n\t"
        "	strh r3, [r0]\n\t"
        "	mov r1, sl\n\t"
        "	strh r3, [r1]\n\t"
        "	ldr r0, _08039CA4\n\t"
        "	adds r1, r2, r0\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	strh r3, [r6]\n\t"
        "	strh r3, [r7]\n\t"
        "	ldr r1, _08039CA8\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r0, [r0, #4]\n\t"
        "	adds r0, r0, r4\n\t"
        "	str r3, [r0]\n\t"
        "	ldr r1, _08039CAC\n\t"
        "	adds r0, r4, r1\n\t"
        "	str r3, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	add sl, r0\n\t"
        "	add sb, r0\n\t"
        "	add r8, r0\n\t"
        "	add ip, r0\n\t"
        "	adds r5, #0x1c\n\t"
        "	adds r4, #4\n\t"
        "	adds r7, #2\n\t"
        "	adds r6, #2\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #3\n\t"
        "	ble _08039BB4\n\t"
        "	movs r5, #0\n\t"
        "	ldr r3, _08039CB0\n\t"
        "	ldr r4, _08039CB4\n\t"
        "	movs r2, #1\n\t"
        "_08039C1C:\n\t"
        "	strh r5, [r4]\n\t"
        "	movs r1, #0\n\t"
        "_08039C20:\n\t"
        "	adds r0, r3, r1\n\t"
        "	strb r5, [r0]\n\t"
        "	adds r1, #1\n\t"
        "	cmp r1, #0xb\n\t"
        "	bls _08039C20\n\t"
        "	adds r3, #0xc\n\t"
        "	adds r4, #2\n\t"
        "	subs r2, #1\n\t"
        "	cmp r2, #0\n\t"
        "	bge _08039C1C\n\t"
        "	movs r1, #0\n\t"
        "	ldr r2, _08039CB8\n\t"
        "	strb r1, [r2]\n\t"
        "	ldr r0, _08039CBC\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r2, _08039CC0\n\t"
        "	strh r1, [r2]\n\t"
        "	ldr r1, _08039CC4\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "_08039C48:\n\t"
        "	adds r0, r1, r2\n\t"
        "	strb r3, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #0x2b\n\t"
        "	bls _08039C48\n\t"
        "	ldr r2, _08039CC8\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r2]\n\t"
        "	ldr r0, _08039CCC\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x11\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08039CD4\n\t"
        "	movs r0, #2\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08039CF2\n\t"
        "	ldr r0, _08039CD0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r1, [r0, #0x15]\n\t"
        "	movs r0, #4\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08039CF2\n\t"
        "	movs r0, #0x80\n\t"
        "	b _08039CF0\n\t"
        "	.align 2, 0\n\t"
        "_08039C80: .4byte gLastHitByType\n\t"
        "_08039C84: .4byte gLastResultingMoves\n\t"
        "_08039C88: .4byte gLastLandedMoves\n\t"
        "_08039C8C: .4byte gLastMoves\n\t"
        "_08039C90: .4byte gDisableStructs\n\t"
        "_08039C94: .4byte gLockedMoves\n\t"
        "_08039C98: .4byte gLastPrintedMoves\n\t"
        "_08039C9C: .4byte gStatuses3\n\t"
        "_08039CA0: .4byte sUnusedBattlersArray\n\t"
        "_08039CA4: .4byte gLastHitBy\n\t"
        "_08039CA8: .4byte gBattleResources\n\t"
        "_08039CAC: .4byte gPalaceSelectionBattleScripts\n\t"
        "_08039CB0: .4byte gSideTimers\n\t"
        "_08039CB4: .4byte gSideStatuses\n\t"
        "_08039CB8: .4byte gBattlerAttacker\n\t"
        "_08039CBC: .4byte gBattlerTarget\n\t"
        "_08039CC0: .4byte gBattleWeather\n\t"
        "_08039CC4: .4byte gWishFutureKnock\n\t"
        "_08039CC8: .4byte gHitMarker\n\t"
        "_08039CCC: .4byte gBattleTypeFlags\n\t"
        "_08039CD0: .4byte gSaveBlock2Ptr\n\t"
        "_08039CD4:\n\t"
        "	ldr r0, _08039E70\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08039CF2\n\t"
        "	bl GetRecordedBattleRecordMixFriendClass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08039CF2\n\t"
        "	ldr r1, _08039E74\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r1, #0x80\n\t"
        "	orrs r0, r1\n\t"
        "	ldr r2, _08039E74\n\t"
        "_08039CF0:\n\t"
        "	str r0, [r2]\n\t"
        "_08039CF2:\n\t"
        "	ldr r3, _08039E78\n\t"
        "	ldr r0, _08039E7C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #0x15]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r0, r0, #0x1f\n\t"
        "	movs r1, #0\n\t"
        "	strb r0, [r3, #0x1d]\n\t"
        "	ldr r0, _08039E80\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _08039E84\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _08039E88\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r0, _08039E8C\n\t"
        "	movs r2, #0\n\t"
        "	strh r1, [r0]\n\t"
        "	ldr r1, _08039E90\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r0, [r0, #8]\n\t"
        "	adds r0, #0x20\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r0, [r0, #0xc]\n\t"
        "	adds r0, #0x20\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r5, _08039E94\n\t"
        "	ldr r6, _08039E98\n\t"
        "	ldr r7, _08039E9C\n\t"
        "	ldr r0, _08039EA0\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _08039EA4\n\t"
        "	mov sb, r1\n\t"
        "	ldr r2, _08039EA8\n\t"
        "	mov sl, r2\n\t"
        "	ldr r1, _08039EAC\n\t"
        "	movs r2, #0\n\t"
        "	adds r0, r1, #7\n\t"
        "_08039D3E:\n\t"
        "	strb r2, [r0]\n\t"
        "	subs r0, #1\n\t"
        "	cmp r0, r1\n\t"
        "	bge _08039D3E\n\t"
        "	movs r4, #0\n\t"
        "	strh r4, [r5]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r6]\n\t"
        "	strh r0, [r7]\n\t"
        "	strb r4, [r3, #0x18]\n\t"
        "	strb r4, [r3, #0x19]\n\t"
        "	mov r0, r8\n\t"
        "	strb r4, [r0]\n\t"
        "	mov r1, sb\n\t"
        "	strb r4, [r1]\n\t"
        "	ldr r5, _08039EB0\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x6c\n\t"
        "	strb r4, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x79\n\t"
        "	strb r4, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x7a\n\t"
        "	strb r4, [r0]\n\t"
        "	mov r0, sl\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	ldr r6, [r5]\n\t"
        "	adds r6, #0x7c\n\t"
        "	ldr r2, _08039EB4\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1, #8]\n\t"
        "	movs r0, #0x64\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _08039EB8\n\t"
        "	bl __divsi3\n\t"
        "	strb r0, [r6]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x7b\n\t"
        "	movs r1, #3\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	strb r4, [r0, #0x12]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #0x4a\n\t"
        "	movs r1, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r2, #0\n\t"
        "	movs r1, #0\n\t"
        "	adds r6, r5, #0\n\t"
        "_08039DAE:\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0x98\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0xb8\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0xc8\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0xd0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0xe0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0xe8\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0xf0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0xf8\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #7\n\t"
        "	ble _08039DAE\n\t"
        "	movs r2, #0\n\t"
        "	ldr r4, _08039EB0\n\t"
        "	movs r3, #0xa5\n\t"
        "	lsls r3, r3, #2\n\t"
        "	movs r1, #6\n\t"
        "_08039DFE:\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, r0, r3\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #3\n\t"
        "	ble _08039DFE\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, #0xdf\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, #0x92\n\t"
        "	strb r1, [r0]\n\t"
        "	bl Random\n\t"
        "	ldr r1, _08039EBC\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, _08039EC0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "_08039E28:\n\t"
        "	adds r0, r1, r2\n\t"
        "	strb r3, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #0x43\n\t"
        "	bls _08039E28\n\t"
        "	ldr r0, _08039EA8\n\t"
        "	bl IsMonShiny\n\t"
        "	ldr r3, _08039EC0\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #6\n\t"
        "	ldrb r2, [r3, #5]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3, #5]\n\t"
        "	ldr r2, _08039EB0\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0xa8\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r2, _08039EC4\n\t"
        "	adds r0, r0, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08039E70: .4byte gUnknown_2000002\n\t"
        "_08039E74: .4byte gHitMarker\n\t"
        "_08039E78: .4byte gBattleScripting\n\t"
        "_08039E7C: .4byte gSaveBlock2Ptr\n\t"
        "_08039E80: .4byte gMultiHitCounter\n\t"
        "_08039E84: .4byte gBattleOutcome\n\t"
        "_08039E88: .4byte gBattleControllerExecFlags\n\t"
        "_08039E8C: .4byte gPaydayMoney\n\t"
        "_08039E90: .4byte gBattleResources\n\t"
        "_08039E94: .4byte gPauseCounterBattle\n\t"
        "_08039E98: .4byte gBattleMoveDamage\n\t"
        "_08039E9C: .4byte gIntroSlideFlags\n\t"
        "_08039EA0: .4byte gLeveledUpInBattle\n\t"
        "_08039EA4: .4byte gAbsentBattlerFlags\n\t"
        "_08039EA8: .4byte gEnemyParty\n\t"
        "_08039EAC: .4byte gBattleCommunication\n\t"
        "_08039EB0: .4byte gBattleStruct\n\t"
        "_08039EB4: .4byte gSpeciesInfo\n\t"
        "_08039EB8: .4byte 0x000004FB\n\t"
        "_08039EBC: .4byte gRandomTurnNumber\n\t"
        "_08039EC0: .4byte gBattleResults\n\t"
        "_08039EC4: .4byte 0x000002A1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) u8 GetWhoStrikesFirst(u8 battler1, u8 battler2, bool8 ignoreChosenMoves)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov sl, r1\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	str r2, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #8]\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0x13\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xd\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CC1C\n\t"
        "	ldr r1, [sp, #8]\n\t"
        "	str r1, [sp]\n\t"
        "	movs r0, #0x13\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0x4d\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CC1C\n\t"
        "	ldr r1, _0803CBD4\n\t"
        "	movs r0, #0x58\n\t"
        "	mov r2, sb\n\t"
        "	muls r2, r0, r2\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r3, [r0]\n\t"
        "	cmp r3, #0x21\n\t"
        "	bne _0803CBC0\n\t"
        "	ldr r0, _0803CBD8\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #7\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CBD0\n\t"
        "_0803CBC0:\n\t"
        "	cmp r3, #0x22\n\t"
        "	bne _0803CBDC\n\t"
        "	ldr r0, _0803CBD8\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x60\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803CBDC\n\t"
        "_0803CBD0:\n\t"
        "	movs r3, #2\n\t"
        "	b _0803CBDE\n\t"
        "	.align 2, 0\n\t"
        "_0803CBD4: .4byte gBattleMons\n\t"
        "_0803CBD8: .4byte gBattleWeather\n\t"
        "_0803CBDC:\n\t"
        "	movs r3, #1\n\t"
        "_0803CBDE:\n\t"
        "	movs r0, #0x58\n\t"
        "	mov r1, sl\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r0, r1, #0\n\t"
        "	ldr r2, _0803CC14\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r2, [r0]\n\t"
        "	cmp r2, #0x21\n\t"
        "	bne _0803CBFE\n\t"
        "	ldr r0, _0803CC18\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #7\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CC0E\n\t"
        "_0803CBFE:\n\t"
        "	cmp r2, #0x22\n\t"
        "	bne _0803CC1E\n\t"
        "	ldr r0, _0803CC18\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x60\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803CC1E\n\t"
        "_0803CC0E:\n\t"
        "	movs r7, #2\n\t"
        "	b _0803CC20\n\t"
        "	.align 2, 0\n\t"
        "_0803CC14: .4byte gBattleMons\n\t"
        "_0803CC18: .4byte gBattleWeather\n\t"
        "_0803CC1C:\n\t"
        "	movs r3, #1\n\t"
        "_0803CC1E:\n\t"
        "	movs r7, #1\n\t"
        "_0803CC20:\n\t"
        "	ldr r1, _0803CC64\n\t"
        "	movs r0, #0x58\n\t"
        "	mov r2, sb\n\t"
        "	muls r2, r0, r2\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrh r0, [r4, #6]\n\t"
        "	muls r3, r0, r3\n\t"
        "	ldr r2, _0803CC68\n\t"
        "	movs r1, #0x1b\n\t"
        "	ldrsb r1, [r4, r1]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	muls r0, r3, r0\n\t"
        "	adds r2, #1\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	bl __divsi3\n\t"
        "	mov r8, r0\n\t"
        "	ldrh r0, [r4, #0x2e]\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bne _0803CC70\n\t"
        "	ldr r1, _0803CC6C\n\t"
        "	mov r3, sb\n\t"
        "	lsls r0, r3, #3\n\t"
        "	subs r0, r0, r3\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r6, [r0, #7]\n\t"
        "	ldrb r5, [r0, #0x1a]\n\t"
        "	b _0803CC84\n\t"
        "	.align 2, 0\n\t"
        "_0803CC64: .4byte gBattleMons\n\t"
        "_0803CC68: .4byte gUnknown_82FA6B6\n\t"
        "_0803CC6C: .4byte gEnigmaBerries\n\t"
        "_0803CC70:\n\t"
        "	ldrh r0, [r4, #0x2e]\n\t"
        "	bl sub_080D6CF8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldrh r0, [r4, #0x2e]\n\t"
        "	bl sub_080D6D1C\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "_0803CC84:\n\t"
        "	ldr r0, _0803CD40\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0803CD44\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CCB8\n\t"
        "	ldr r0, _0803CD48\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803CCB8\n\t"
        "	mov r0, sb\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CCB8\n\t"
        "	movs r0, #0x6e\n\t"
        "	mov r1, r8\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r0, r1, #0\n\t"
        "	movs r1, #0x64\n\t"
        "	bl __udivsi3\n\t"
        "	mov r8, r0\n\t"
        "_0803CCB8:\n\t"
        "	cmp r6, #0x18\n\t"
        "	bne _0803CCC2\n\t"
        "	mov r2, r8\n\t"
        "	lsrs r2, r2, #1\n\t"
        "	mov r8, r2\n\t"
        "_0803CCC2:\n\t"
        "	ldr r1, _0803CD4C\n\t"
        "	movs r0, #0x58\n\t"
        "	mov r3, sb\n\t"
        "	muls r3, r0, r3\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r1, #0x4c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803CCE0\n\t"
        "	mov r0, r8\n\t"
        "	lsrs r0, r0, #2\n\t"
        "	mov r8, r0\n\t"
        "_0803CCE0:\n\t"
        "	cmp r6, #0x1a\n\t"
        "	bne _0803CCFC\n\t"
        "	ldr r0, _0803CD50\n\t"
        "	ldrh r4, [r0]\n\t"
        "	lsls r0, r5, #0x10\n\t"
        "	subs r0, r0, r5\n\t"
        "	movs r1, #0x64\n\t"
        "	bl __divsi3\n\t"
        "	cmp r4, r0\n\t"
        "	bge _0803CCFC\n\t"
        "	movs r1, #1\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	mov r8, r1\n\t"
        "_0803CCFC:\n\t"
        "	ldr r1, _0803CD4C\n\t"
        "	movs r0, #0x58\n\t"
        "	mov r2, sl\n\t"
        "	muls r2, r0, r2\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrh r0, [r4, #6]\n\t"
        "	adds r3, r0, #0\n\t"
        "	muls r3, r7, r3\n\t"
        "	ldr r2, _0803CD54\n\t"
        "	movs r1, #0x1b\n\t"
        "	ldrsb r1, [r4, r1]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	muls r0, r3, r0\n\t"
        "	adds r2, #1\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	bl __divsi3\n\t"
        "	adds r7, r0, #0\n\t"
        "	ldrh r0, [r4, #0x2e]\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bne _0803CD5C\n\t"
        "	ldr r1, _0803CD58\n\t"
        "	mov r3, sl\n\t"
        "	lsls r0, r3, #3\n\t"
        "	subs r0, r0, r3\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r6, [r0, #7]\n\t"
        "	ldrb r5, [r0, #0x1a]\n\t"
        "	b _0803CD70\n\t"
        "	.align 2, 0\n\t"
        "_0803CD40: .4byte gBattleTypeFlags\n\t"
        "_0803CD44: .4byte 0x023F0102\n\t"
        "_0803CD48: .4byte 0x00000869\n\t"
        "_0803CD4C: .4byte gBattleMons\n\t"
        "_0803CD50: .4byte gRandomTurnNumber\n\t"
        "_0803CD54: .4byte gUnknown_82FA6B6\n\t"
        "_0803CD58: .4byte gEnigmaBerries\n\t"
        "_0803CD5C:\n\t"
        "	ldrh r0, [r4, #0x2e]\n\t"
        "	bl sub_080D6CF8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldrh r0, [r4, #0x2e]\n\t"
        "	bl sub_080D6D1C\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "_0803CD70:\n\t"
        "	ldr r0, _0803CDE8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0803CDEC\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CDA0\n\t"
        "	ldr r0, _0803CDF0\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803CDA0\n\t"
        "	mov r0, sl\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CDA0\n\t"
        "	movs r0, #0x6e\n\t"
        "	muls r0, r7, r0\n\t"
        "	movs r1, #0x64\n\t"
        "	bl __udivsi3\n\t"
        "	adds r7, r0, #0\n\t"
        "_0803CDA0:\n\t"
        "	cmp r6, #0x18\n\t"
        "	bne _0803CDA6\n\t"
        "	lsrs r7, r7, #1\n\t"
        "_0803CDA6:\n\t"
        "	ldr r2, _0803CDF4\n\t"
        "	movs r0, #0x58\n\t"
        "	mov r1, sl\n\t"
        "	muls r1, r0, r1\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r1, #0x4c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803CDC2\n\t"
        "	lsrs r7, r7, #2\n\t"
        "_0803CDC2:\n\t"
        "	cmp r6, #0x1a\n\t"
        "	bne _0803CDDC\n\t"
        "	ldr r0, _0803CDF8\n\t"
        "	ldrh r4, [r0]\n\t"
        "	lsls r0, r5, #0x10\n\t"
        "	subs r0, r0, r5\n\t"
        "	movs r1, #0x64\n\t"
        "	bl __divsi3\n\t"
        "	cmp r4, r0\n\t"
        "	bge _0803CDDC\n\t"
        "	movs r7, #1\n\t"
        "	rsbs r7, r7, #0\n\t"
        "_0803CDDC:\n\t"
        "	ldr r2, [sp, #4]\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0803CDFC\n\t"
        "	movs r3, #0\n\t"
        "	b _0803CE98\n\t"
        "	.align 2, 0\n\t"
        "_0803CDE8: .4byte gBattleTypeFlags\n\t"
        "_0803CDEC: .4byte 0x023F0102\n\t"
        "_0803CDF0: .4byte 0x00000869\n\t"
        "_0803CDF4: .4byte gBattleMons\n\t"
        "_0803CDF8: .4byte gRandomTurnNumber\n\t"
        "_0803CDFC:\n\t"
        "	ldr r0, _0803CE1C\n\t"
        "	mov r3, sb\n\t"
        "	adds r1, r3, r0\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0803CE4C\n\t"
        "	ldr r0, _0803CE20\n\t"
        "	lsls r1, r3, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _0803CE24\n\t"
        "	movs r3, #0xa5\n\t"
        "	b _0803CE4E\n\t"
        "	.align 2, 0\n\t"
        "_0803CE1C: .4byte gChosenActionByBattler\n\t"
        "_0803CE20: .4byte gProtectStructs\n\t"
        "_0803CE24:\n\t"
        "	ldr r0, _0803CE44\n\t"
        "	ldr r0, [r0]\n\t"
        "	add r0, sb\n\t"
        "	adds r0, #0x80\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	movs r1, #0x58\n\t"
        "	mov r3, sb\n\t"
        "	muls r3, r1, r3\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0803CE48\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r3, [r0]\n\t"
        "	b _0803CE4E\n\t"
        "	.align 2, 0\n\t"
        "_0803CE44: .4byte gBattleStruct\n\t"
        "_0803CE48: .4byte gBattleMons\n\t"
        "_0803CE4C:\n\t"
        "	movs r3, #0\n\t"
        "_0803CE4E:\n\t"
        "	mov r1, sl\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803CE98\n\t"
        "	ldr r0, _0803CE6C\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _0803CE70\n\t"
        "	movs r2, #0xa5\n\t"
        "	b _0803CE9A\n\t"
        "	.align 2, 0\n\t"
        "_0803CE6C: .4byte gProtectStructs\n\t"
        "_0803CE70:\n\t"
        "	ldr r0, _0803CE90\n\t"
        "	ldr r0, [r0]\n\t"
        "	add r0, sl\n\t"
        "	adds r0, #0x80\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	movs r1, #0x58\n\t"
        "	mov r2, sl\n\t"
        "	muls r2, r1, r2\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0803CE94\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r2, [r0]\n\t"
        "	b _0803CE9A\n\t"
        "	.align 2, 0\n\t"
        "_0803CE90: .4byte gBattleStruct\n\t"
        "_0803CE94: .4byte gBattleMons\n\t"
        "_0803CE98:\n\t"
        "	movs r2, #0\n\t"
        "_0803CE9A:\n\t"
        "	ldr r4, _0803CEE4\n\t"
        "	lsls r0, r3, #1\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #7\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	lsls r3, r2, #1\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0803CEBE\n\t"
        "	adds r0, r3, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0, #7]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803CEFC\n\t"
        "_0803CEBE:\n\t"
        "	adds r0, r3, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0, #7]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0803CEF2\n\t"
        "	cmp r8, r7\n\t"
        "	bne _0803CEE8\n\t"
        "	bl Random\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803CEE8\n\t"
        "	movs r3, #2\n\t"
        "	b _0803CF18\n\t"
        "	.align 2, 0\n\t"
        "_0803CEE4: .4byte gBattleMoves\n\t"
        "_0803CEE8:\n\t"
        "	cmp r8, r7\n\t"
        "	bhs _0803CF1A\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	b _0803CF1A\n\t"
        "_0803CEF2:\n\t"
        "	cmp r1, r0\n\t"
        "	bge _0803CF1A\n\t"
        "	movs r1, #1\n\t"
        "	str r1, [sp, #8]\n\t"
        "	b _0803CF1A\n\t"
        "_0803CEFC:\n\t"
        "	cmp r8, r7\n\t"
        "	bne _0803CF12\n\t"
        "	bl Random\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803CF12\n\t"
        "	movs r2, #2\n\t"
        "	str r2, [sp, #8]\n\t"
        "	b _0803CF1A\n\t"
        "_0803CF12:\n\t"
        "	cmp r8, r7\n\t"
        "	bhs _0803CF1A\n\t"
        "	movs r3, #1\n\t"
        "_0803CF18:\n\t"
        "	str r3, [sp, #8]\n\t"
        "_0803CF1A:\n\t"
        "	ldr r0, [sp, #8]\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void FaintClearSetData(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	movs r5, #0\n\t"
        "	ldr r6, _0803A764\n\t"
        "	ldr r0, _0803A768\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _0803A76C\n\t"
        "	mov ip, r1\n\t"
        "	ldr r2, _0803A770\n\t"
        "	mov sb, r2\n\t"
        "	ldr r3, _0803A774\n\t"
        "	mov sl, r3\n\t"
        "	ldr r7, _0803A778\n\t"
        "	ldr r4, _0803A77C\n\t"
        "	movs r3, #0x58\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r2, #0x18\n\t"
        "	movs r1, #6\n\t"
        "_0803A3CC:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	muls r0, r3, r0\n\t"
        "	adds r0, r5, r0\n\t"
        "	adds r0, r0, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #7\n\t"
        "	ble _0803A3CC\n\t"
        "	ldr r0, _0803A77C\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r2, #0x50\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r3, _0803A77C\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	str r1, [r0]\n\t"
        "	movs r5, #0\n\t"
        "	ldr r6, _0803A780\n\t"
        "	ldrb r6, [r6]\n\t"
        "	cmp r5, r6\n\t"
        "	bge _0803A474\n\t"
        "	adds r3, r2, #0\n\t"
        "	movs r4, #0\n\t"
        "	ldr r0, _0803A784\n\t"
        "	mov r8, r0\n\t"
        "_0803A40A:\n\t"
        "	ldr r1, [r3]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803A42A\n\t"
        "	ldr r2, _0803A788\n\t"
        "	adds r0, r4, r2\n\t"
        "	ldrb r0, [r0, #0x14]\n\t"
        "	ldr r6, _0803A77C\n\t"
        "	ldrb r6, [r6]\n\t"
        "	cmp r0, r6\n\t"
        "	bne _0803A42A\n\t"
        "	ldr r0, _0803A78C\n\t"
        "	ands r1, r0\n\t"
        "	str r1, [r3]\n\t"
        "_0803A42A:\n\t"
        "	ldr r1, _0803A77C\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r2, r0, #0x10\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803A444\n\t"
        "	bics r1, r2\n\t"
        "	str r1, [r3]\n\t"
        "_0803A444:\n\t"
        "	ldr r1, [r3]\n\t"
        "	movs r0, #0xe0\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803A466\n\t"
        "	mov r2, ip\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldrb r0, [r0, #0x14]\n\t"
        "	ldr r6, _0803A77C\n\t"
        "	ldrb r6, [r6]\n\t"
        "	cmp r0, r6\n\t"
        "	bne _0803A466\n\t"
        "	ldr r0, _0803A790\n\t"
        "	ands r1, r0\n\t"
        "	str r1, [r3]\n\t"
        "_0803A466:\n\t"
        "	adds r3, #0x58\n\t"
        "	adds r4, #0x1c\n\t"
        "	adds r5, #1\n\t"
        "	ldr r0, _0803A780\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _0803A40A\n\t"
        "_0803A474:\n\t"
        "	ldr r1, _0803A77C\n\t"
        "	ldrb r0, [r1]\n\t"
        "	add r0, sb\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r2, _0803A77C\n\t"
        "	ldrb r0, [r2]\n\t"
        "	add r0, sl\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r3, _0803A788\n\t"
        "	adds r1, r0, r3\n\t"
        "	movs r5, #0\n\t"
        "	movs r2, #0\n\t"
        "_0803A496:\n\t"
        "	adds r0, r1, r5\n\t"
        "	strb r2, [r0]\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #0x1b\n\t"
        "	bls _0803A496\n\t"
        "	ldr r6, _0803A77C\n\t"
        "	ldrb r1, [r6]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r0, #2\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r1, [r6]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r3, #3\n\t"
        "	rsbs r3, r3, #0\n\t"
        "	mov r8, r3\n\t"
        "	mov r0, r8\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r1, [r6]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r6, #5\n\t"
        "	rsbs r6, r6, #0\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _0803A77C\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1]\n\t"
        "	subs r3, #6\n\t"
        "	mov sl, r3\n\t"
        "	mov r0, sl\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _0803A77C\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r2, _0803A77C\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r5, #0x21\n\t"
        "	rsbs r5, r5, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r3, _0803A77C\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r4, #0x41\n\t"
        "	rsbs r4, r4, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r3, #0x7f\n\t"
        "	adds r0, r3, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _0803A77C\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1, #1]\n\t"
        "	mov r0, sb\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	ldr r2, _0803A77C\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1, #1]\n\t"
        "	mov r0, r8\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	ldr r0, _0803A77C\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1, #1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	ldr r2, _0803A77C\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r2, [r1, #1]\n\t"
        "	movs r0, #0x19\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	ldr r1, _0803A77C\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	ands r5, r1\n\t"
        "	strb r5, [r0, #1]\n\t"
        "	ldr r2, _0803A77C\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	ands r4, r1\n\t"
        "	strb r4, [r0, #1]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	ands r3, r1\n\t"
        "	strb r3, [r0, #1]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r1, [r0, #2]\n\t"
        "	mov r3, sb\n\t"
        "	ands r3, r1\n\t"
        "	strb r3, [r0, #2]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r1, [r0, #2]\n\t"
        "	mov r2, r8\n\t"
        "	ands r2, r1\n\t"
        "	strb r2, [r0, #2]\n\t"
        "	ldr r3, _0803A77C\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r1, [r0, #2]\n\t"
        "	ands r6, r1\n\t"
        "	strb r6, [r0, #2]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r1, [r0, #2]\n\t"
        "	mov r6, sl\n\t"
        "	ands r6, r1\n\t"
        "	strb r6, [r0, #2]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0803A788\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "	movs r1, #2\n\t"
        "	strb r1, [r0, #0x16]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r3, _0803A794\n\t"
        "	adds r0, r0, r3\n\t"
        "	movs r3, #0\n\t"
        "	strh r2, [r0]\n\t"
        "	ldr r6, _0803A77C\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r1, _0803A798\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r2, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r6, _0803A79C\n\t"
        "	adds r0, r0, r6\n\t"
        "	strh r2, [r0]\n\t"
        "	ldr r1, _0803A77C\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r6, _0803A7A0\n\t"
        "	adds r0, r0, r6\n\t"
        "	strh r2, [r0]\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r1, _0803A7A4\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r2, [r0]\n\t"
        "	ldr r2, _0803A77C\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ldr r6, _0803A7A8\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #0xff\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	mov r2, ip\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc8\n\t"
        "	strb r3, [r0]\n\t"
        "	ldr r6, _0803A77C\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc9\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x98\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x99\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe0\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe1\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe2\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe3\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe4\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe5\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe6\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe7\n\t"
        "	strb r3, [r0]\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r1, #0x92\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r2, _0803A784\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bics r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r5, #0\n\t"
        "	ldr r3, _0803A780\n\t"
        "	ldrb r3, [r3]\n\t"
        "	cmp r5, r3\n\t"
        "	bge _0803A746\n\t"
        "	adds r3, r6, #0\n\t"
        "	mov r7, ip\n\t"
        "	movs r6, #0\n\t"
        "_0803A6E8:\n\t"
        "	ldrb r0, [r3]\n\t"
        "	cmp r5, r0\n\t"
        "	beq _0803A71E\n\t"
        "	lsls r0, r5, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r3, [sp]\n\t"
        "	bl GetBattlerSide\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r3, [sp]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r3, [sp]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0803A71E\n\t"
        "	ldr r0, [r7]\n\t"
        "	lsls r1, r5, #1\n\t"
        "	adds r0, r1, r0\n\t"
        "	adds r0, #0x98\n\t"
        "	strb r6, [r0]\n\t"
        "	ldr r0, [r7]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x99\n\t"
        "	strb r6, [r1]\n\t"
        "_0803A71E:\n\t"
        "	ldrb r0, [r3]\n\t"
        "	ldr r1, [r7]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	lsls r2, r5, #3\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe0\n\t"
        "	strb r6, [r0]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	ldr r1, [r7]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe1\n\t"
        "	strb r6, [r0]\n\t"
        "	adds r5, #1\n\t"
        "	ldr r0, _0803A780\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _0803A6E8\n\t"
        "_0803A746:\n\t"
        "	ldr r0, _0803A7AC\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "	ldr r2, _0803A77C\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r4, _0803A764\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r3, #0x58\n\t"
        "	adds r2, r0, #0\n\t"
        "	muls r2, r3, r2\n\t"
        "	b _0803A7B0\n\t"
        "	.align 2, 0\n\t"
        "_0803A764: .4byte gBattleMons\n\t"
        "_0803A768: .4byte gStatuses3\n\t"
        "_0803A76C: .4byte gBattleStruct\n\t"
        "_0803A770: .4byte gActionSelectionCursor\n\t"
        "_0803A774: .4byte gMoveSelectionCursor\n\t"
        "_0803A778: .4byte gProtectStructs\n\t"
        "_0803A77C: .4byte gActiveBattler\n\t"
        "_0803A780: .4byte gBattlersCount\n\t"
        "_0803A784: .4byte gBitTable\n\t"
        "_0803A788: .4byte gDisableStructs\n\t"
        "_0803A78C: .4byte 0xFBFFFFFF\n\t"
        "_0803A790: .4byte 0xFFFF1FFF\n\t"
        "_0803A794: .4byte gLastMoves\n\t"
        "_0803A798: .4byte gLastLandedMoves\n\t"
        "_0803A79C: .4byte gLastResultingMoves\n\t"
        "_0803A7A0: .4byte gLastHitByType\n\t"
        "_0803A7A4: .4byte gLockedMoves\n\t"
        "_0803A7A8: .4byte gLastHitBy\n\t"
        "_0803A7AC: .4byte gBattleResources\n\t"
        "_0803A7B0:\n\t"
        "	adds r2, r2, r4\n\t"
        "	ldr r5, _0803A7FC\n\t"
        "	ldrh r1, [r2]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0, #6]\n\t"
        "	adds r2, #0x21\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r6, _0803A800\n\t"
        "	ldrb r0, [r6]\n\t"
        "	adds r1, r0, #0\n\t"
        "	muls r1, r3, r1\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrh r2, [r1]\n\t"
        "	lsls r0, r2, #3\n\t"
        "	subs r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0, #7]\n\t"
        "	adds r1, #0x22\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	bl ClearBattlerMoveHistory\n\t"
        "	ldrb r0, [r6]\n\t"
        "	bl ClearBattlerAbilityHistory\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803A7FC: .4byte gSpeciesInfo\n\t"
        "_0803A800: .4byte gActiveBattler\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void SwitchInClearSetData(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x20\n\t"
        "	ldr r4, _0803A02C\n\t"
        "	ldr r5, _0803A030\n\t"
        "	ldrb r1, [r5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldm r0!, {r2, r3, r6}\n\t"
        "	stm r1!, {r2, r3, r6}\n\t"
        "	ldm r0!, {r2, r3, r7}\n\t"
        "	stm r1!, {r2, r3, r7}\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r2, _0803A034\n\t"
        "	ldr r3, _0803A038\n\t"
        "	ldrh r1, [r3]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov ip, r4\n\t"
        "	mov sb, r5\n\t"
        "	ldr r6, _0803A03C\n\t"
        "	mov sl, r6\n\t"
        "	cmp r0, #0x7f\n\t"
        "	beq _08039FA0\n\t"
        "	movs r5, #0\n\t"
        "	mov r6, sb\n\t"
        "	movs r4, #0x58\n\t"
        "	ldr r2, _0803A040\n\t"
        "	adds r2, #0x18\n\t"
        "	movs r1, #6\n\t"
        "_08039F18:\n\t"
        "	ldrb r0, [r6]\n\t"
        "	muls r0, r4, r0\n\t"
        "	adds r0, r5, r0\n\t"
        "	adds r0, r0, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #7\n\t"
        "	ble _08039F18\n\t"
        "	movs r5, #0\n\t"
        "	ldr r7, _0803A044\n\t"
        "	ldrb r7, [r7]\n\t"
        "	cmp r5, r7\n\t"
        "	bge _08039F8C\n\t"
        "	ldr r0, _0803A048\n\t"
        "	mov r8, r0\n\t"
        "	ldr r4, _0803A02C\n\t"
        "	ldr r3, _0803A03C\n\t"
        "_08039F3A:\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r5, r0\n\t"
        "	mov r1, r8\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldr r1, [r2]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08039F5E\n\t"
        "	ldrb r0, [r4, #0x14]\n\t"
        "	ldr r6, _0803A030\n\t"
        "	ldrb r6, [r6]\n\t"
        "	cmp r0, r6\n\t"
        "	bne _08039F5E\n\t"
        "	ldr r0, _0803A04C\n\t"
        "	ands r1, r0\n\t"
        "	str r1, [r2]\n\t"
        "_08039F5E:\n\t"
        "	ldr r1, [r3]\n\t"
        "	movs r0, #0x18\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08039F7E\n\t"
        "	ldrb r0, [r4, #0x15]\n\t"
        "	ldr r7, _0803A030\n\t"
        "	ldrb r7, [r7]\n\t"
        "	cmp r0, r7\n\t"
        "	bne _08039F7E\n\t"
        "	movs r0, #0x19\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r1, r0\n\t"
        "	str r1, [r3]\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r4, #0x15]\n\t"
        "_08039F7E:\n\t"
        "	adds r4, #0x1c\n\t"
        "	adds r3, #4\n\t"
        "	adds r5, #1\n\t"
        "	ldr r0, _0803A044\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _08039F3A\n\t"
        "_08039F8C:\n\t"
        "	ldr r1, _0803A038\n\t"
        "	ldrh r0, [r1]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r2, _0803A034\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0x7f\n\t"
        "	bne _0803A058\n\t"
        "_08039FA0:\n\t"
        "	mov r3, sb\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r0, #0x58\n\t"
        "	adds r2, r1, #0\n\t"
        "	muls r2, r0, r2\n\t"
        "	ldr r0, _0803A040\n\t"
        "	adds r0, #0x50\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r1, _0803A050\n\t"
        "	ands r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, sl\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r2, _0803A054\n\t"
        "	ands r0, r2\n\t"
        "	str r0, [r1]\n\t"
        "	movs r5, #0\n\t"
        "	ldr r6, _0803A044\n\t"
        "	ldrb r6, [r6]\n\t"
        "	cmp r5, r6\n\t"
        "	bge _0803A074\n\t"
        "	mov r7, sb\n\t"
        "	movs r6, #0\n\t"
        "_08039FD4:\n\t"
        "	ldrb r0, [r7]\n\t"
        "	bl GetBattlerSide\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r0, r5, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0803A014\n\t"
        "	ldr r1, _0803A03C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldr r1, [r2]\n\t"
        "	movs r0, #0x18\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803A014\n\t"
        "	ldr r0, _0803A02C\n\t"
        "	adds r0, r6, r0\n\t"
        "	ldrb r0, [r0, #0x15]\n\t"
        "	ldrb r3, [r7]\n\t"
        "	cmp r0, r3\n\t"
        "	bne _0803A014\n\t"
        "	movs r0, #0x19\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0x10\n\t"
        "	orrs r1, r0\n\t"
        "	str r1, [r2]\n\t"
        "_0803A014:\n\t"
        "	adds r6, #0x1c\n\t"
        "	adds r5, #1\n\t"
        "	ldr r0, _0803A044\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _08039FD4\n\t"
        "	ldr r6, _0803A02C\n\t"
        "	mov ip, r6\n\t"
        "	ldr r7, _0803A030\n\t"
        "	mov sb, r7\n\t"
        "	b _0803A074\n\t"
        "	.align 2, 0\n\t"
        "_0803A02C: .4byte gDisableStructs\n\t"
        "_0803A030: .4byte gActiveBattler\n\t"
        "_0803A034: .4byte gBattleMoves\n\t"
        "_0803A038: .4byte gCurrentMove\n\t"
        "_0803A03C: .4byte gStatuses3\n\t"
        "_0803A040: .4byte gBattleMons\n\t"
        "_0803A044: .4byte gBattlersCount\n\t"
        "_0803A048: .4byte gUnknown_2023D78\n\t"
        "_0803A04C: .4byte 0xFBFFFFFF\n\t"
        "_0803A050: .4byte 0x15100007\n\t"
        "_0803A054: .4byte 0x0003043F\n\t"
        "_0803A058:\n\t"
        "	mov r0, sb\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r1, _0803A354\n\t"
        "	adds r1, #0x50\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [r0]\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sl\n\t"
        "	str r1, [r0]\n\t"
        "_0803A074:\n\t"
        "	movs r5, #0\n\t"
        "	ldr r3, _0803A358\n\t"
        "	mov r8, r3\n\t"
        "	ldr r6, _0803A35C\n\t"
        "	mov sl, r6\n\t"
        "	ldr r7, _0803A360\n\t"
        "	ldrb r7, [r7]\n\t"
        "	cmp r5, r7\n\t"
        "	bge _0803A0D4\n\t"
        "	ldr r3, _0803A364\n\t"
        "	ldr r7, _0803A368\n\t"
        "	ldr r6, _0803A36C\n\t"
        "_0803A08C:\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r4, r0, r3\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r2, r0, #0x10\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803A0AA\n\t"
        "	bics r1, r2\n\t"
        "	str r1, [r4]\n\t"
        "_0803A0AA:\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #0xe0\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803A0CA\n\t"
        "	mov r2, r8\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldrb r0, [r0, #0x14]\n\t"
        "	ldrb r2, [r6]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _0803A0CA\n\t"
        "	ldr r0, _0803A370\n\t"
        "	ands r1, r0\n\t"
        "	str r1, [r4]\n\t"
        "_0803A0CA:\n\t"
        "	adds r5, #1\n\t"
        "	ldr r0, _0803A360\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _0803A08C\n\t"
        "_0803A0D4:\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	add r0, sl\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ldr r3, _0803A374\n\t"
        "	adds r0, r0, r3\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r6, ip\n\t"
        "	adds r1, r0, r6\n\t"
        "	movs r5, #0\n\t"
        "	movs r2, #0\n\t"
        "_0803A0F8:\n\t"
        "	adds r0, r1, r5\n\t"
        "	strb r2, [r0]\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #0x1b\n\t"
        "	bls _0803A0F8\n\t"
        "	ldr r7, _0803A378\n\t"
        "	ldrh r0, [r7]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _0803A37C\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0x7f\n\t"
        "	bne _0803A184\n\t"
        "	mov r2, sb\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	mov r1, sp\n\t"
        "	ldrb r1, [r1, #0xa]\n\t"
        "	strb r1, [r0, #0xa]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	mov r1, sp\n\t"
        "	ldrb r1, [r1, #0x15]\n\t"
        "	strb r1, [r0, #0x15]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, ip\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r2, [r0, #0xf]\n\t"
        "	lsls r2, r2, #0x1c\n\t"
        "	movs r4, #0xf\n\t"
        "	lsrs r2, r2, #0x1c\n\t"
        "	ldrb r3, [r1, #0xf]\n\t"
        "	movs r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1, #0xf]\n\t"
        "	mov r3, sb\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	mov r1, sp\n\t"
        "	ldrb r1, [r1, #0xf]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	lsls r1, r1, #4\n\t"
        "	ldrb r2, [r0, #0xf]\n\t"
        "	ands r4, r2\n\t"
        "	orrs r4, r1\n\t"
        "	strb r4, [r0, #0xf]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	mov r1, sp\n\t"
        "	ldrb r1, [r1, #0x14]\n\t"
        "	strb r1, [r0, #0x14]\n\t"
        "_0803A184:\n\t"
        "	movs r0, #0\n\t"
        "	ldr r6, _0803A380\n\t"
        "	strb r0, [r6]\n\t"
        "	mov r7, sb\n\t"
        "	ldrb r1, [r7]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	movs r4, #0\n\t"
        "	movs r1, #2\n\t"
        "	strb r1, [r0, #0x16]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, ip\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0, #0x18]\n\t"
        "	movs r2, #2\n\t"
        "	ands r2, r0\n\t"
        "	ldrb r3, [r1, #0x18]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1, #0x18]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r1, _0803A384\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "	strh r4, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r3, _0803A388\n\t"
        "	adds r0, r0, r3\n\t"
        "	strh r4, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r6, _0803A38C\n\t"
        "	adds r0, r0, r6\n\t"
        "	strh r4, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r7, _0803A390\n\t"
        "	adds r0, r0, r7\n\t"
        "	strh r4, [r0]\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r3, _0803A394\n\t"
        "	adds r0, r0, r3\n\t"
        "	strh r4, [r0]\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldr r6, _0803A398\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #0xff\n\t"
        "	strb r1, [r0]\n\t"
        "	mov r7, sb\n\t"
        "	ldrb r0, [r7]\n\t"
        "	mov r3, r8\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x98\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x99\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe0\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe1\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe2\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe3\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe4\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe5\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe6\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	ldr r1, [r3]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe7\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r1, #0x92\n\t"
        "	ldrb r0, [r7]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r6, _0803A368\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bics r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r5, #0\n\t"
        "	ldr r7, _0803A360\n\t"
        "	ldrb r7, [r7]\n\t"
        "	cmp r5, r7\n\t"
        "	bge _0803A2F8\n\t"
        "	mov r3, sb\n\t"
        "	mov r7, r8\n\t"
        "	movs r6, #0\n\t"
        "_0803A29A:\n\t"
        "	ldrb r0, [r3]\n\t"
        "	cmp r5, r0\n\t"
        "	beq _0803A2D0\n\t"
        "	lsls r0, r5, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r3, [sp, #0x1c]\n\t"
        "	bl GetBattlerSide\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r3, [sp, #0x1c]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r3, [sp, #0x1c]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _0803A2D0\n\t"
        "	ldr r0, [r7]\n\t"
        "	lsls r1, r5, #1\n\t"
        "	adds r0, r1, r0\n\t"
        "	adds r0, #0x98\n\t"
        "	strb r6, [r0]\n\t"
        "	ldr r0, [r7]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x99\n\t"
        "	strb r6, [r1]\n\t"
        "_0803A2D0:\n\t"
        "	ldrb r0, [r3]\n\t"
        "	ldr r1, [r7]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	lsls r2, r5, #3\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe0\n\t"
        "	strb r6, [r0]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	ldr r1, [r7]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xe1\n\t"
        "	strb r6, [r0]\n\t"
        "	adds r5, #1\n\t"
        "	ldr r0, _0803A360\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _0803A29A\n\t"
        "_0803A2F8:\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	mov r2, r8\n\t"
        "	ldr r1, [r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc8\n\t"
        "	movs r2, #0\n\t"
        "	strb r2, [r0]\n\t"
        "	mov r3, sb\n\t"
        "	ldrb r0, [r3]\n\t"
        "	mov r6, r8\n\t"
        "	ldr r1, [r6]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0xc9\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, _0803A39C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r2, #0\n\t"
        "	str r2, [r1]\n\t"
        "	ldr r0, _0803A378\n\t"
        "	strh r2, [r0]\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, #0xda\n\t"
        "	movs r1, #0xff\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r0, [r3]\n\t"
        "	bl ClearBattlerMoveHistory\n\t"
        "	mov r7, sb\n\t"
        "	ldrb r0, [r7]\n\t"
        "	bl ClearBattlerAbilityHistory\n\t"
        "	add sp, #0x20\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803A354: .4byte gBattleMons\n\t"
        "_0803A358: .4byte gBattleStruct\n\t"
        "_0803A35C: .4byte gActionSelectionCursor\n\t"
        "_0803A360: .4byte gBattlersCount\n\t"
        "_0803A364: .4byte gUnknown_2023D78\n\t"
        "_0803A368: .4byte gBitTable\n\t"
        "_0803A36C: .4byte gActiveBattler\n\t"
        "_0803A370: .4byte 0xFFFF1FFF\n\t"
        "_0803A374: .4byte gMoveSelectionCursor\n\t"
        "_0803A378: .4byte gCurrentMove\n\t"
        "_0803A37C: .4byte gBattleMoves\n\t"
        "_0803A380: .4byte gMoveResultFlags\n\t"
        "_0803A384: .4byte gLastMoves\n\t"
        "_0803A388: .4byte gLastLandedMoves\n\t"
        "_0803A38C: .4byte gLastResultingMoves\n\t"
        "_0803A390: .4byte gLastHitByType\n\t"
        "_0803A394: .4byte gLockedMoves\n\t"
        "_0803A398: .4byte gLastHitBy\n\t"
        "_0803A39C: .4byte gBattleResources\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) u8 CreateNPCTrainerParty(struct Pokemon *party, u16 trainerNum, bool8 firstTrainer)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x24\n\t"
        "	str r0, [sp, #0x10]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r3, r1, #0x10\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #3\n\t"
        "	cmp r3, r0\n\t"
        "	bne _080382EA\n\t"
        "	movs r0, #0\n\t"
        "	b _08038696\n\t"
        "_080382EA:\n\t"
        "	ldr r4, _08038328\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _0803832C\n\t"
        "	ands r0, r1\n\t"
        "	lsls r3, r3, #5\n\t"
        "	str r3, [sp, #0x20]\n\t"
        "	cmp r0, #8\n\t"
        "	beq _080382FC\n\t"
        "	b _0803868E\n\t"
        "_080382FC:\n\t"
        "	cmp r2, #1\n\t"
        "	bne _08038304\n\t"
        "	bl ZeroEnemyPartyMons\n\t"
        "_08038304:\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08038334\n\t"
        "	ldr r0, _08038330\n\t"
        "	ldr r1, [sp, #0x20]\n\t"
        "	adds r2, r1, r0\n\t"
        "	ldrb r1, [r2, #0x18]\n\t"
        "	movs r3, #3\n\t"
        "	str r3, [sp, #0x18]\n\t"
        "	adds r4, r0, #0\n\t"
        "	cmp r1, #3\n\t"
        "	bhi _08038340\n\t"
        "	adds r2, r1, #0\n\t"
        "	str r2, [sp, #0x18]\n\t"
        "	b _08038340\n\t"
        "	.align 2, 0\n\t"
        "_08038328: .4byte gBattleTypeFlags\n\t"
        "_0803832C: .4byte 0x043F0908\n\t"
        "_08038330: .4byte gTrainers\n\t"
        "_08038334:\n\t"
        "	ldr r1, _0803835C\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrb r0, [r0, #0x18]\n\t"
        "	str r0, [sp, #0x18]\n\t"
        "	adds r4, r1, #0\n\t"
        "_08038340:\n\t"
        "	movs r3, #0\n\t"
        "	str r3, [sp, #0x14]\n\t"
        "	ldr r0, [sp, #0x18]\n\t"
        "	cmp r3, r0\n\t"
        "	blt _0803834C\n\t"
        "	b _0803867E\n\t"
        "_0803834C:\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	adds r1, r2, r4\n\t"
        "	ldrb r0, [r1, #0x12]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08038360\n\t"
        "	movs r3, #0x80\n\t"
        "	mov sl, r3\n\t"
        "	b _08038372\n\t"
        "	.align 2, 0\n\t"
        "_0803835C: .4byte gTrainers\n\t"
        "_08038360:\n\t"
        "	ldrb r1, [r1, #2]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x88\n\t"
        "	mov sl, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08038372\n\t"
        "	movs r2, #0x78\n\t"
        "	mov sl, r2\n\t"
        "_08038372:\n\t"
        "	movs r6, #0\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	adds r1, r4, #4\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r3, [sp, #0x14]\n\t"
        "	adds r3, #1\n\t"
        "	str r3, [sp, #0x1c]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _0803839E\n\t"
        "	adds r3, r1, #0\n\t"
        "_08038388:\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r0, r6, r2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sb, r0\n\t"
        "	adds r6, #1\n\t"
        "	adds r1, r6, r1\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _08038388\n\t"
        "_0803839E:\n\t"
        "	ldr r1, [sp, #0x20]\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0803844C\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080383B2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080383C0\n\t"
        "	b _08038670\n\t"
        "_080383B2:\n\t"
        "	cmp r0, #2\n\t"
        "	bne _080383B8\n\t"
        "	b _08038510\n\t"
        "_080383B8:\n\t"
        "	cmp r0, #3\n\t"
        "	bne _080383BE\n\t"
        "	b _080385A8\n\t"
        "_080383BE:\n\t"
        "	b _08038670\n\t"
        "_080383C0:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x1c\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldr r4, [r0]\n\t"
        "	movs r6, #0\n\t"
        "	ldr r3, [sp, #0x14]\n\t"
        "	lsls r2, r3, #3\n\t"
        "	adds r0, r2, r4\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r1, _08038448\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r5, r2, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _08038406\n\t"
        "	adds r3, r1, #0\n\t"
        "_080383E8:\n\t"
        "	adds r0, r2, r4\n\t"
        "	ldrh r0, [r0, #4]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r6, r1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sb, r0\n\t"
        "	adds r6, #1\n\t"
        "	adds r1, r6, r1\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _080383E8\n\t"
        "_08038406:\n\t"
        "	mov r2, sb\n\t"
        "	lsls r0, r2, #8\n\t"
        "	add sl, r0\n\t"
        "	adds r4, r5, r4\n\t"
        "	ldrh r1, [r4]\n\t"
        "	lsls r0, r1, #5\n\t"
        "	subs r0, r0, r1\n\t"
        "	movs r1, #0xff\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r3, [sp, #0x14]\n\t"
        "	movs r1, #0x64\n\t"
        "	adds r0, r3, #0\n\t"
        "	muls r0, r1, r0\n\t"
        "	ldr r2, [sp, #0x10]\n\t"
        "	adds r0, r2, r0\n\t"
        "	ldrh r1, [r4, #4]\n\t"
        "	ldrb r2, [r4, #2]\n\t"
        "	movs r3, #1\n\t"
        "	str r3, [sp]\n\t"
        "	mov r3, sl\n\t"
        "	str r3, [sp, #4]\n\t"
        "	movs r3, #2\n\t"
        "	str r3, [sp, #8]\n\t"
        "	movs r3, #0\n\t"
        "	str r3, [sp, #0xc]\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl CreateMon\n\t"
        "	b _08038670\n\t"
        "	.align 2, 0\n\t"
        "_08038448: .4byte gSpeciesNames\n\t"
        "_0803844C:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x1c\n\t"
        "	ldr r1, [sp, #0x20]\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldr r7, [r0]\n\t"
        "	movs r6, #0\n\t"
        "	ldr r3, [sp, #0x14]\n\t"
        "	lsls r2, r3, #4\n\t"
        "	adds r0, r2, r7\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r1, _08038508\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov r8, r2\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _08038492\n\t"
        "	adds r3, r1, #0\n\t"
        "_08038474:\n\t"
        "	adds r0, r2, r7\n\t"
        "	ldrh r0, [r0, #4]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r6, r1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sb, r0\n\t"
        "	adds r6, #1\n\t"
        "	adds r1, r6, r1\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _08038474\n\t"
        "_08038492:\n\t"
        "	mov r2, sb\n\t"
        "	lsls r0, r2, #8\n\t"
        "	add sl, r0\n\t"
        "	mov r3, r8\n\t"
        "	adds r4, r3, r7\n\t"
        "	ldrh r1, [r4]\n\t"
        "	lsls r0, r1, #5\n\t"
        "	subs r0, r0, r1\n\t"
        "	movs r1, #0xff\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r0, [sp, #0x14]\n\t"
        "	movs r1, #0x64\n\t"
        "	adds r5, r0, #0\n\t"
        "	muls r5, r1, r5\n\t"
        "	ldr r2, [sp, #0x10]\n\t"
        "	adds r5, r2, r5\n\t"
        "	ldrh r1, [r4, #4]\n\t"
        "	ldrb r2, [r4, #2]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp]\n\t"
        "	mov r3, sl\n\t"
        "	str r3, [sp, #4]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl CreateMon\n\t"
        "	movs r6, #0\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #6\n\t"
        "	adds r4, r7, r0\n\t"
        "_080384DC:\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl SetMonData\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x11\n\t"
        "	ldrh r0, [r4]\n\t"
        "	lsls r2, r0, #1\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldr r0, _0803850C\n\t"
        "	adds r2, r2, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl SetMonData\n\t"
        "	adds r4, #2\n\t"
        "	adds r6, #1\n\t"
        "	cmp r6, #3\n\t"
        "	ble _080384DC\n\t"
        "	b _08038670\n\t"
        "	.align 2, 0\n\t"
        "_08038508: .4byte gSpeciesNames\n\t"
        "_0803850C: .4byte gUnknown_82ED224\n\t"
        "_08038510:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x1c\n\t"
        "	ldr r1, [sp, #0x20]\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldr r4, [r0]\n\t"
        "	movs r6, #0\n\t"
        "	ldr r3, [sp, #0x14]\n\t"
        "	lsls r2, r3, #3\n\t"
        "	adds r0, r2, r4\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r1, _080385A4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r5, r2, #0\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _08038556\n\t"
        "	adds r3, r1, #0\n\t"
        "_08038538:\n\t"
        "	adds r0, r2, r4\n\t"
        "	ldrh r0, [r0, #4]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r6, r1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sb, r0\n\t"
        "	adds r6, #1\n\t"
        "	adds r1, r6, r1\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _08038538\n\t"
        "_08038556:\n\t"
        "	mov r2, sb\n\t"
        "	lsls r0, r2, #8\n\t"
        "	add sl, r0\n\t"
        "	adds r5, r5, r4\n\t"
        "	ldrh r1, [r5]\n\t"
        "	lsls r0, r1, #5\n\t"
        "	subs r0, r0, r1\n\t"
        "	movs r1, #0xff\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r3, [sp, #0x14]\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r4, r3, #0\n\t"
        "	muls r4, r0, r4\n\t"
        "	ldr r1, [sp, #0x10]\n\t"
        "	adds r4, r1, r4\n\t"
        "	ldrh r1, [r5, #4]\n\t"
        "	ldrb r2, [r5, #2]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp]\n\t"
        "	mov r3, sl\n\t"
        "	str r3, [sp, #4]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl CreateMon\n\t"
        "	adds r5, #6\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xc\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl SetMonData\n\t"
        "	b _08038670\n\t"
        "	.align 2, 0\n\t"
        "_080385A4: .4byte gSpeciesNames\n\t"
        "_080385A8:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x1c\n\t"
        "	ldr r1, [sp, #0x20]\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldr r7, [r0]\n\t"
        "	movs r6, #0\n\t"
        "	ldr r3, [sp, #0x14]\n\t"
        "	lsls r2, r3, #4\n\t"
        "	adds r0, r2, r7\n\t"
        "	ldrh r1, [r0, #4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ldr r1, _080386A8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov r8, r2\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _080385EE\n\t"
        "	adds r3, r1, #0\n\t"
        "_080385D0:\n\t"
        "	adds r0, r2, r7\n\t"
        "	ldrh r0, [r0, #4]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r0, r6, r1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sb, r0\n\t"
        "	adds r6, #1\n\t"
        "	adds r1, r6, r1\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _080385D0\n\t"
        "_080385EE:\n\t"
        "	mov r2, sb\n\t"
        "	lsls r0, r2, #8\n\t"
        "	add sl, r0\n\t"
        "	mov r3, r8\n\t"
        "	adds r5, r3, r7\n\t"
        "	ldrh r1, [r5]\n\t"
        "	lsls r0, r1, #5\n\t"
        "	subs r0, r0, r1\n\t"
        "	movs r1, #0xff\n\t"
        "	bl __divsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r0, [sp, #0x14]\n\t"
        "	movs r1, #0x64\n\t"
        "	adds r4, r0, #0\n\t"
        "	muls r4, r1, r4\n\t"
        "	ldr r2, [sp, #0x10]\n\t"
        "	adds r4, r2, r4\n\t"
        "	ldrh r1, [r5, #4]\n\t"
        "	ldrb r2, [r5, #2]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp]\n\t"
        "	mov r3, sl\n\t"
        "	str r3, [sp, #4]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl CreateMon\n\t"
        "	adds r5, #6\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xc\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl SetMonData\n\t"
        "	movs r6, #0\n\t"
        "	adds r5, r4, #0\n\t"
        "	mov r0, r8\n\t"
        "	adds r0, #8\n\t"
        "	adds r4, r7, r0\n\t"
        "_08038646:\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0xd\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl SetMonData\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x11\n\t"
        "	ldrh r0, [r4]\n\t"
        "	lsls r2, r0, #1\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldr r0, _080386AC\n\t"
        "	adds r2, r2, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl SetMonData\n\t"
        "	adds r4, #2\n\t"
        "	adds r6, #1\n\t"
        "	cmp r6, #3\n\t"
        "	ble _08038646\n\t"
        "_08038670:\n\t"
        "	ldr r0, [sp, #0x1c]\n\t"
        "	str r0, [sp, #0x14]\n\t"
        "	ldr r4, _080386B0\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	cmp r0, r1\n\t"
        "	bge _0803867E\n\t"
        "	b _0803834C\n\t"
        "_0803867E:\n\t"
        "	ldr r2, _080386B4\n\t"
        "	ldr r0, _080386B0\n\t"
        "	ldr r3, [sp, #0x20]\n\t"
        "	adds r0, r3, r0\n\t"
        "	ldrb r1, [r0, #0x12]\n\t"
        "	ldr r0, [r2]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "_0803868E:\n\t"
        "	ldr r0, _080386B0\n\t"
        "	ldr r1, [sp, #0x20]\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldrb r0, [r0, #0x18]\n\t"
        "_08038696:\n\t"
        "	add sp, #0x24\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080386A8: .4byte gSpeciesNames\n\t"
        "_080386AC: .4byte gUnknown_82ED224\n\t"
        "_080386B0: .4byte gTrainers\n\t"
        "_080386B4: .4byte gBattleTypeFlags\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void SetAllPlayersBerryData(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	ldr r0, _08036B14\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08036A74\n\t"
        "	b _08036BA0\n\t"
        "_08036A74:\n\t"
        "	bl IsEnigmaBerryValid\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08036B30\n\t"
        "	movs r5, #0\n\t"
        "	ldr r3, _08036B18\n\t"
        "	ldr r0, _08036B1C\n\t"
        "	mov r8, r0\n\t"
        "	adds r6, r3, #0\n\t"
        "	mov r4, r8\n\t"
        "	ldr r2, _08036B20\n\t"
        "	adds r7, r3, #0\n\t"
        "	adds r7, #0x38\n\t"
        "_08036A8E:\n\t"
        "	adds r1, r5, r6\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r1, r5, r7\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #5\n\t"
        "	ble _08036A8E\n\t"
        "	adds r1, r5, r3\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x38\n\t"
        "	adds r0, r5, r0\n\t"
        "	movs r1, #1\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r5, #0\n\t"
        "	adds r7, r3, #0\n\t"
        "	adds r7, #8\n\t"
        "	ldr r4, _08036B1C\n\t"
        "	ldr r2, _08036B24\n\t"
        "	adds r6, r3, #0\n\t"
        "	adds r6, #0x40\n\t"
        "_08036ACC:\n\t"
        "	adds r1, r5, r7\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r1, r5, r6\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #0x11\n\t"
        "	ble _08036ACC\n\t"
        "	mov r1, r8\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r2, _08036B28\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0]\n\t"
        "	strb r1, [r3, #7]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r1, #0x3f\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r4, r8\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _08036B2C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	strb r1, [r3, #0x1a]\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x52\n\t"
        "	strb r1, [r0]\n\t"
        "	b _08036CF4\n\t"
        "	.align 2, 0\n\t"
        "_08036B14: .4byte gBattleTypeFlags\n\t"
        "_08036B18: .4byte gEnigmaBerries\n\t"
        "_08036B1C: .4byte gSaveBlock1Ptr\n\t"
        "_08036B20: .4byte 0x000031F8\n\t"
        "_08036B24: .4byte 0x00003214\n\t"
        "_08036B28: .4byte 0x00003226\n\t"
        "_08036B2C: .4byte 0x00003227\n\t"
        "_08036B30:\n\t"
        "	movs r0, #0xaf\n\t"
        "	bl ItemIdToBerryType\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBerryInfo\n\t"
        "	adds r6, r0, #0\n\t"
        "	movs r5, #0\n\t"
        "	ldr r4, _08036B9C\n\t"
        "	adds r7, r4, #0\n\t"
        "	adds r7, #0x38\n\t"
        "	adds r3, r4, #0\n\t"
        "_08036B4A:\n\t"
        "	adds r1, r5, r4\n\t"
        "	adds r2, r6, r5\n\t"
        "	ldrb r0, [r2]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r1, r5, r7\n\t"
        "	ldrb r0, [r2]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #5\n\t"
        "	ble _08036B4A\n\t"
        "	adds r1, r5, r3\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x38\n\t"
        "	adds r0, r5, r0\n\t"
        "	movs r1, #1\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r5, #0\n\t"
        "	adds r4, r3, #0\n\t"
        "	adds r4, #8\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x40\n\t"
        "_08036B7C:\n\t"
        "	adds r0, r5, r4\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r5, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, #0x11\n\t"
        "	ble _08036B7C\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r3, #7]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x3f\n\t"
        "	strb r1, [r0]\n\t"
        "	strb r1, [r3, #0x1a]\n\t"
        "	adds r0, #0x13\n\t"
        "	strb r1, [r0]\n\t"
        "	b _08036CF4\n\t"
        "	.align 2, 0\n\t"
        "_08036B9C: .4byte gEnigmaBerries\n\t"
        "_08036BA0:\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08036C44\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ands r1, r0\n\t"
        "	movs r2, #4\n\t"
        "	mov r8, r2\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08036BBA\n\t"
        "	movs r4, #2\n\t"
        "	mov r8, r4\n\t"
        "_08036BBA:\n\t"
        "	movs r5, #0\n\t"
        "	cmp r5, r8\n\t"
        "	blt _08036BC2\n\t"
        "	b _08036CF4\n\t"
        "_08036BC2:\n\t"
        "	ldr r0, _08036C38\n\t"
        "	mov ip, r0\n\t"
        "	ldr r3, _08036C3C\n\t"
        "	adds r6, r3, #0\n\t"
        "	movs r1, #8\n\t"
        "	adds r1, r1, r6\n\t"
        "	mov sb, r1\n\t"
        "_08036BD0:\n\t"
        "	lsls r1, r5, #8\n\t"
        "	ldr r0, _08036C40\n\t"
        "	adds r7, r1, r0\n\t"
        "	lsls r0, r5, #3\n\t"
        "	subs r0, r0, r5\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, ip\n\t"
        "	ldrb r3, [r0, #0x18]\n\t"
        "	movs r4, #0\n\t"
        "	adds r5, #1\n\t"
        "	mov sl, r5\n\t"
        "	lsls r1, r3, #3\n\t"
        "	subs r0, r1, r3\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r0, r6\n\t"
        "_08036BF0:\n\t"
        "	adds r0, r7, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r1, #1\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #5\n\t"
        "	ble _08036BF0\n\t"
        "	subs r0, r5, r3\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r4, r0\n\t"
        "	adds r1, r1, r6\n\t"
        "	movs r2, #0xff\n\t"
        "	strb r2, [r1]\n\t"
        "	movs r4, #0\n\t"
        "	mov r2, sb\n\t"
        "	adds r1, r0, r2\n\t"
        "	adds r2, r7, #0\n\t"
        "	adds r2, #8\n\t"
        "_08036C14:\n\t"
        "	adds r0, r2, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r1, #1\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #0x11\n\t"
        "	ble _08036C14\n\t"
        "	subs r0, r5, r3\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r1, [r7, #7]\n\t"
        "	strb r1, [r0, #7]\n\t"
        "	ldrb r1, [r7, #0x1a]\n\t"
        "	strb r1, [r0, #0x1a]\n\t"
        "	mov r5, sl\n\t"
        "	cmp r5, r8\n\t"
        "	blt _08036BD0\n\t"
        "	b _08036CF4\n\t"
        "	.align 2, 0\n\t"
        "_08036C38: .4byte gLinkPlayers\n\t"
        "_08036C3C: .4byte gEnigmaBerries\n\t"
        "_08036C40: .4byte gUnknown_2022080\n\t"
        "_08036C44:\n\t"
        "	movs r5, #0\n\t"
        "	ldr r4, _08036D04\n\t"
        "	mov sb, r4\n\t"
        "_08036C4A:\n\t"
        "	lsls r0, r5, #8\n\t"
        "	ldr r1, _08036D08\n\t"
        "	adds r7, r0, r1\n\t"
        "	movs r4, #0\n\t"
        "	adds r2, r5, #1\n\t"
        "	mov sl, r2\n\t"
        "	lsls r0, r5, #3\n\t"
        "	mov r8, r0\n\t"
        "	adds r1, r5, #2\n\t"
        "	mov ip, r1\n\t"
        "	subs r1, r0, r5\n\t"
        "	mov r2, ip\n\t"
        "	lsls r0, r2, #3\n\t"
        "	subs r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	mov r2, sb\n\t"
        "	adds r3, r0, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r2, r1, r2\n\t"
        "_08036C70:\n\t"
        "	adds r0, r7, r4\n\t"
        "	ldrb r1, [r0]\n\t"
        "	strb r1, [r2]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r3]\n\t"
        "	adds r3, #1\n\t"
        "	adds r2, #1\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #5\n\t"
        "	ble _08036C70\n\t"
        "	mov r0, r8\n\t"
        "	subs r3, r0, r5\n\t"
        "	lsls r3, r3, #2\n\t"
        "	adds r1, r4, r3\n\t"
        "	add r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r2, #0xff\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r0, ip\n\t"
        "	lsls r2, r0, #3\n\t"
        "	subs r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r1, r4, r2\n\t"
        "	add r1, sb\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r4, #0xff\n\t"
        "	orrs r0, r4\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r4, #0\n\t"
        "	ldr r0, _08036D04\n\t"
        "	adds r0, #8\n\t"
        "	adds r2, r2, r0\n\t"
        "	adds r3, r3, r0\n\t"
        "	adds r6, r7, #0\n\t"
        "	adds r6, #8\n\t"
        "_08036CB8:\n\t"
        "	adds r0, r6, r4\n\t"
        "	ldrb r1, [r0]\n\t"
        "	strb r1, [r3]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r2]\n\t"
        "	adds r2, #1\n\t"
        "	adds r3, #1\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #0x11\n\t"
        "	ble _08036CB8\n\t"
        "	mov r0, r8\n\t"
        "	subs r2, r0, r5\n\t"
        "	lsls r2, r2, #2\n\t"
        "	add r2, sb\n\t"
        "	ldrb r0, [r7, #7]\n\t"
        "	strb r0, [r2, #7]\n\t"
        "	mov r1, ip\n\t"
        "	lsls r0, r1, #3\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sb\n\t"
        "	ldrb r1, [r7, #7]\n\t"
        "	strb r1, [r0, #7]\n\t"
        "	ldrb r1, [r7, #0x1a]\n\t"
        "	strb r1, [r2, #0x1a]\n\t"
        "	ldrb r1, [r7, #0x1a]\n\t"
        "	strb r1, [r0, #0x1a]\n\t"
        "	mov r5, sl\n\t"
        "	cmp r5, #1\n\t"
        "	ble _08036C4A\n\t"
        "_08036CF4:\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08036D04: .4byte gEnigmaBerries\n\t"
        "_08036D08: .4byte gUnknown_2022080\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void CB2_PreInitMultiBattle(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	movs r0, #4\n\t"
        "	mov sb, r0\n\t"
        "	movs r4, #0xf\n\t"
        "	ldr r6, _08037890\n\t"
        "	ldr r0, [r6]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08037852\n\t"
        "	movs r1, #2\n\t"
        "	mov sb, r1\n\t"
        "	movs r4, #3\n\t"
        "_08037852:\n\t"
        "	bl GetMultiplayerId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	ldr r0, _08037894\n\t"
        "	adds r0, #0x25\n\t"
        "	movs r2, #0\n\t"
        "	mov r8, r2\n\t"
        "	strb r7, [r0]\n\t"
        "	ldr r0, _08037898\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r1, #0xb4\n\t"
        "	str r1, [sp]\n\t"
        "	adds r0, #0xac\n\t"
        "	mov sl, r0\n\t"
        "	bl RunTasks\n\t"
        "	bl AnimateSprites\n\t"
        "	bl BuildOamBuffer\n\t"
        "	ldr r5, _0803789C\n\t"
        "	ldrb r0, [r5]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080378F4\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080378A0\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080378AE\n\t"
        "	b _08037A5A\n\t"
        "	.align 2, 0\n\t"
        "_08037890: .4byte gBattleTypeFlags\n\t"
        "_08037894: .4byte gBattleScripting\n\t"
        "_08037898: .4byte gBattleStruct\n\t"
        "_0803789C: .4byte gBattleCommunication\n\t"
        "_080378A0:\n\t"
        "	cmp r0, #2\n\t"
        "	bne _080378A6\n\t"
        "	b _080379B4\n\t"
        "_080378A6:\n\t"
        "	cmp r0, #3\n\t"
        "	bne _080378AC\n\t"
        "	b _080379EE\n\t"
        "_080378AC:\n\t"
        "	b _08037A5A\n\t"
        "_080378AE:\n\t"
        "	ldr r0, _080378EC\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080378B8\n\t"
        "	b _08037A5A\n\t"
        "_080378B8:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080378C4\n\t"
        "	b _08037A5A\n\t"
        "_080378C4:\n\t"
        "	ldr r4, _080378F0\n\t"
        "	movs r0, #0x60\n\t"
        "	bl Alloc\n\t"
        "	str r0, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_08037770\n\t"
        "	bl BitmaskAllOtherLinkPlayers\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r2, #0x60\n\t"
        "	bl SendBlock\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r5]\n\t"
        "	b _08037A5A\n\t"
        "	.align 2, 0\n\t"
        "_080378EC: .4byte gReceivedRemoteLinkPlayers\n\t"
        "_080378F0: .4byte sMultiPartnerPartyBuffer\n\t"
        "_080378F4:\n\t"
        "	bl GetBlockReceivedStatus\n\t"
        "	adds r1, r4, #0\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, r4\n\t"
        "	beq _08037902\n\t"
        "	b _08037A5A\n\t"
        "_08037902:\n\t"
        "	bl ResetBlockReceivedFlags\n\t"
        "	movs r5, #0\n\t"
        "	cmp r8, sb\n\t"
        "	bge _0803797E\n\t"
        "	lsls r0, r7, #3\n\t"
        "	subs r0, r0, r7\n\t"
        "	lsls r6, r0, #2\n\t"
        "	mov r8, r5\n\t"
        "	ldr r4, _08037940\n\t"
        "_08037916:\n\t"
        "	cmp r5, r7\n\t"
        "	beq _0803796E\n\t"
        "	mov r2, sb\n\t"
        "	cmp r2, #4\n\t"
        "	bne _08037964\n\t"
        "	ldr r2, _08037944\n\t"
        "	mov r1, r8\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	movs r3, #1\n\t"
        "	adds r0, r3, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08037948\n\t"
        "	adds r0, r6, r2\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	adds r0, r3, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08037954\n\t"
        "	b _0803796E\n\t"
        "	.align 2, 0\n\t"
        "_08037940: .4byte gBlockRecvBuffer\n\t"
        "_08037944: .4byte gLinkPlayers\n\t"
        "_08037948:\n\t"
        "	adds r0, r6, r2\n\t"
        "	ldrh r1, [r0, #0x18]\n\t"
        "	adds r0, r3, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803796E\n\t"
        "_08037954:\n\t"
        "	ldr r0, _08037960\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #0x60\n\t"
        "	bl memcpy\n\t"
        "	b _0803796E\n\t"
        "	.align 2, 0\n\t"
        "_08037960: .4byte gMultiPartnerParty\n\t"
        "_08037964:\n\t"
        "	ldr r0, _080379A0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #0x60\n\t"
        "	bl memcpy\n\t"
        "_0803796E:\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r4, r4, r2\n\t"
        "	movs r0, #0x1c\n\t"
        "	add r8, r0\n\t"
        "	adds r5, #1\n\t"
        "	cmp r5, sb\n\t"
        "	blt _08037916\n\t"
        "_0803797E:\n\t"
        "	ldr r1, _080379A4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _080379A8\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	ldr r2, [sp]\n\t"
        "	str r0, [r2]\n\t"
        "	ldr r0, _080379AC\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov r2, sl\n\t"
        "	str r0, [r2]\n\t"
        "	ldr r0, _080379B0\n\t"
        "	str r0, [r1, #8]\n\t"
        "	bl ShowPartyMenuToShowcaseMultiBattleParty\n\t"
        "	b _08037A5A\n\t"
        "	.align 2, 0\n\t"
        "_080379A0: .4byte gMultiPartnerParty\n\t"
        "_080379A4: .4byte gBattleCommunication\n\t"
        "_080379A8: .4byte gMain\n\t"
        "_080379AC: .4byte gBattleTypeFlags\n\t"
        "_080379B0: .4byte CB2_PreInitMultiBattle + 1\n\t"
        "_080379B4:\n\t"
        "	bl IsLinkTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08037A5A\n\t"
        "	ldr r0, _080379E0\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08037A5A\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r5]\n\t"
        "	ldr r0, _080379E4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080379E8\n\t"
        "	bl SetLinkStandbyCallback\n\t"
        "	b _08037A5A\n\t"
        "	.align 2, 0\n\t"
        "_080379E0: .4byte gPaletteFade\n\t"
        "_080379E4: .4byte gWirelessCommType\n\t"
        "_080379E8:\n\t"
        "	bl SetCloseLinkCallback\n\t"
        "	b _08037A5A\n\t"
        "_080379EE:\n\t"
        "	ldr r0, _08037A24\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08037A34\n\t"
        "	bl IsLinkRfuTaskFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08037A5A\n\t"
        "	mov r1, sl\n\t"
        "	ldr r0, [r1]\n\t"
        "	str r0, [r6]\n\t"
        "	ldr r1, _08037A28\n\t"
        "	ldr r2, [sp]\n\t"
        "	ldr r0, [r2]\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, _08037A2C\n\t"
        "	bl SetMainCallback2\n\t"
        "	ldr r4, _08037A30\n\t"
        "	ldr r0, [r4]\n\t"
        "	bl Free\n\t"
        "	mov r0, r8\n\t"
        "	str r0, [r4]\n\t"
        "	b _08037A5A\n\t"
        "	.align 2, 0\n\t"
        "_08037A24: .4byte gWirelessCommType\n\t"
        "_08037A28: .4byte gMain\n\t"
        "_08037A2C: .4byte 0x08036629\n\t"
        "_08037A30: .4byte sMultiPartnerPartyBuffer\n\t"
        "_08037A34:\n\t"
        "	ldr r0, _08037A6C\n\t"
        "	ldrb r5, [r0]\n\t"
        "	cmp r5, #0\n\t"
        "	bne _08037A5A\n\t"
        "	mov r1, sl\n\t"
        "	ldr r0, [r1]\n\t"
        "	str r0, [r6]\n\t"
        "	ldr r1, _08037A70\n\t"
        "	ldr r2, [sp]\n\t"
        "	ldr r0, [r2]\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, _08037A74\n\t"
        "	bl SetMainCallback2\n\t"
        "	ldr r4, _08037A78\n\t"
        "	ldr r0, [r4]\n\t"
        "	bl Free\n\t"
        "	str r5, [r4]\n\t"
        "_08037A5A:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08037A6C: .4byte gReceivedRemoteLinkPlayers\n\t"
        "_08037A70: .4byte gMain\n\t"
        "_08037A74: .4byte 0x08036629\n\t"
        "_08037A78: .4byte sMultiPartnerPartyBuffer\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) u8 IsRunningFromBattleImpossible(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r1, _0803B7F0\n\t"
        "	ldr r0, _0803B7F4\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r1, r0, r1\n\t"
        "	ldrh r0, [r1, #0x2e]\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bne _0803B7FC\n\t"
        "	ldr r1, _0803B7F8\n\t"
        "	lsls r0, r2, #3\n\t"
        "	subs r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r2, [r0, #7]\n\t"
        "	b _0803B806\n\t"
        "	.align 2, 0\n\t"
        "_0803B7F0: .4byte gBattleMons\n\t"
        "_0803B7F4: .4byte gActiveBattler\n\t"
        "_0803B7F8: .4byte gEnigmaBerries\n\t"
        "_0803B7FC:\n\t"
        "	ldrh r0, [r1, #0x2e]\n\t"
        "	bl sub_080D6CF8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "_0803B806:\n\t"
        "	ldr r1, _0803B91C\n\t"
        "	ldr r3, _0803B920\n\t"
        "	ldrb r0, [r3]\n\t"
        "	strb r0, [r1]\n\t"
        "	cmp r2, #0x25\n\t"
        "	bne _0803B814\n\t"
        "	b _0803B990\n\t"
        "_0803B814:\n\t"
        "	ldr r0, _0803B924\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B822\n\t"
        "	b _0803B990\n\t"
        "_0803B822:\n\t"
        "	ldr r1, _0803B928\n\t"
        "	ldrb r2, [r3]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0x32\n\t"
        "	bne _0803B836\n\t"
        "	b _0803B990\n\t"
        "_0803B836:\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	movs r5, #0\n\t"
        "	ldr r0, _0803B92C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	bge _0803B8CA\n\t"
        "	movs r7, #0\n\t"
        "_0803B84C:\n\t"
        "	lsrs r4, r7, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r6, r0\n\t"
        "	beq _0803B870\n\t"
        "	ldr r1, _0803B928\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r5, r0\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r2, r0, #0\n\t"
        "	adds r2, #0x20\n\t"
        "	ldrb r0, [r2]\n\t"
        "	cmp r0, #0x17\n\t"
        "	bne _0803B870\n\t"
        "	b _0803B998\n\t"
        "_0803B870:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetBattlerSide\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r6, r0\n\t"
        "	beq _0803B8BA\n\t"
        "	ldr r3, _0803B928\n\t"
        "	ldr r0, _0803B920\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r2, #0x58\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r1, r0, r3\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0x1a\n\t"
        "	beq _0803B8BA\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x21\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0803B8BA\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x22\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0803B8BA\n\t"
        "	adds r0, r5, #0\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r2, r0, #0\n\t"
        "	adds r2, #0x20\n\t"
        "	ldrb r0, [r2]\n\t"
        "	cmp r0, #0x47\n\t"
        "	bne _0803B8BA\n\t"
        "	b _0803B9B4\n\t"
        "_0803B8BA:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0x11\n\t"
        "	adds r7, r7, r0\n\t"
        "	adds r5, #1\n\t"
        "	ldr r0, _0803B92C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r5, r0\n\t"
        "	blt _0803B84C\n\t"
        "_0803B8CA:\n\t"
        "	ldr r4, _0803B920\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xf\n\t"
        "	movs r2, #0x2a\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #0\n\t"
        "	beq _0803B93C\n\t"
        "	ldr r6, _0803B928\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r3, #0x58\n\t"
        "	muls r0, r3, r0\n\t"
        "	adds r1, r0, r6\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x21\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #8\n\t"
        "	beq _0803B902\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x22\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #8\n\t"
        "	bne _0803B93C\n\t"
        "_0803B902:\n\t"
        "	ldr r0, _0803B930\n\t"
        "	subs r1, r5, #1\n\t"
        "	strb r1, [r0, #0x17]\n\t"
        "	ldr r2, _0803B934\n\t"
        "	adds r0, r1, #0\n\t"
        "	muls r0, r3, r0\n\t"
        "	adds r0, r0, r6\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r2]\n\t"
        "	ldr r1, _0803B938\n\t"
        "	movs r0, #2\n\t"
        "	b _0803B9D4\n\t"
        "	.align 2, 0\n\t"
        "_0803B91C: .4byte gPotentialItemEffectBattler\n\t"
        "_0803B920: .4byte gActiveBattler\n\t"
        "_0803B924: .4byte gBattleTypeFlags\n\t"
        "_0803B928: .4byte gBattleMons\n\t"
        "_0803B92C: .4byte gBattlersCount\n\t"
        "_0803B930: .4byte gBattleScripting\n\t"
        "_0803B934: .4byte gLastUsedAbility\n\t"
        "_0803B938: .4byte gBattleCommunication\n\t"
        "_0803B93C:\n\t"
        "	ldr r1, _0803B970\n\t"
        "	ldr r0, _0803B974\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r1, #0x50\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0803B978\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803B966\n\t"
        "	ldr r1, _0803B97C\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803B984\n\t"
        "_0803B966:\n\t"
        "	ldr r1, _0803B980\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	movs r0, #1\n\t"
        "	b _0803B9D6\n\t"
        "	.align 2, 0\n\t"
        "_0803B970: .4byte gBattleMons\n\t"
        "_0803B974: .4byte gActiveBattler\n\t"
        "_0803B978: .4byte 0x0400E000\n\t"
        "_0803B97C: .4byte gStatuses3\n\t"
        "_0803B980: .4byte gBattleCommunication\n\t"
        "_0803B984:\n\t"
        "	ldr r0, _0803B994\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803B9D0\n\t"
        "_0803B990:\n\t"
        "	movs r0, #0\n\t"
        "	b _0803B9D6\n\t"
        "	.align 2, 0\n\t"
        "_0803B994: .4byte gBattleTypeFlags\n\t"
        "_0803B998:\n\t"
        "	ldr r0, _0803B9A8\n\t"
        "	strb r5, [r0, #0x17]\n\t"
        "	ldr r1, _0803B9AC\n\t"
        "	ldrb r0, [r2]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803B9B0\n\t"
        "	movs r0, #2\n\t"
        "	b _0803B9D4\n\t"
        "	.align 2, 0\n\t"
        "_0803B9A8: .4byte gBattleScripting\n\t"
        "_0803B9AC: .4byte gLastUsedAbility\n\t"
        "_0803B9B0: .4byte gBattleCommunication\n\t"
        "_0803B9B4:\n\t"
        "	ldr r0, _0803B9C4\n\t"
        "	strb r5, [r0, #0x17]\n\t"
        "	ldr r1, _0803B9C8\n\t"
        "	ldrb r0, [r2]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803B9CC\n\t"
        "	movs r0, #2\n\t"
        "	b _0803B9D4\n\t"
        "	.align 2, 0\n\t"
        "_0803B9C4: .4byte gBattleScripting\n\t"
        "_0803B9C8: .4byte gLastUsedAbility\n\t"
        "_0803B9CC: .4byte gBattleCommunication\n\t"
        "_0803B9D0:\n\t"
        "	ldr r1, _0803B9E0\n\t"
        "	movs r0, #1\n\t"
        "_0803B9D4:\n\t"
        "	strb r0, [r1, #5]\n\t"
        "_0803B9D6:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0803B9E0: .4byte gBattleCommunication\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void TryEvolvePokemon(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r0, _0803DB4C\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r3, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803DB6E\n\t"
        "_0803DB00:\n\t"
        "	movs r6, #0\n\t"
        "_0803DB02:\n\t"
        "	ldrb r2, [r3]\n\t"
        "	ldr r0, _0803DB50\n\t"
        "	lsls r1, r6, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803DB60\n\t"
        "	bics r2, r1\n\t"
        "	strb r2, [r3]\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r1, r6, #0\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _0803DB54\n\t"
        "	adds r5, r1, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl GetEvolutionTargetSpecies\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	cmp r4, #0\n\t"
        "	beq _0803DB60\n\t"
        "	bl FreeAllWindowBuffers\n\t"
        "	ldr r0, _0803DB58\n\t"
        "	ldr r1, _0803DB5C\n\t"
        "	str r1, [r0]\n\t"
        "	lsls r3, r6, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl EvolutionScene\n\t"
        "	b _0803DB74\n\t"
        "	.align 2, 0\n\t"
        "_0803DB4C: .4byte gLeveledUpInBattle\n\t"
        "_0803DB50: .4byte gBitTable\n\t"
        "_0803DB54: .4byte gPlayerParty\n\t"
        "_0803DB58: .4byte gBattleMainFunc\n\t"
        "_0803DB5C: .4byte 0x0803DB89\n\t"
        "_0803DB60:\n\t"
        "	adds r6, #1\n\t"
        "	ldr r3, _0803DB7C\n\t"
        "	cmp r6, #5\n\t"
        "	ble _0803DB02\n\t"
        "	ldrb r0, [r3]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803DB00\n\t"
        "_0803DB6E:\n\t"
        "	ldr r1, _0803DB80\n\t"
        "	ldr r0, _0803DB84\n\t"
        "	str r0, [r1]\n\t"
        "_0803DB74:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803DB7C: .4byte gLeveledUpInBattle\n\t"
        "_0803DB80: .4byte gBattleMainFunc\n\t"
        "_0803DB84: .4byte 0x0803DBB1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void BattleIntroPrintTrainerWantsToBattle(void)
{
    __asm__(".syntax unified\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0803AD8C\n\t"
        "	ldr r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803AD86\n\t"
        "	movs r0, #1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0803AD90\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r1, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	bl PrepareStringBattle\n\t"
        "	ldr r1, _0803AD94\n\t"
        "	ldr r0, _0803AD98\n\t"
        "	str r0, [r1]\n\t"
        "_0803AD86:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803AD8C: .4byte gBattleControllerExecFlags\n\t"
        "_0803AD90: .4byte gActiveBattler\n\t"
        "_0803AD94: .4byte gBattleMainFunc\n\t"
        "_0803AD98: .4byte 0x0803ADC5\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void sub_0803EEE4(void)
{
    __asm__(".syntax unified\n\t"
        "	push {lr}\n\t"
        "	bl HandleFaintedMonActions\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0803EF00\n\t"
        "	ldr r0, _0803EF04\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x4d\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, _0803EF08\n\t"
        "	movs r0, #0xc\n\t"
        "	strb r0, [r1]\n\t"
        "_0803EF00:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803EF04: .4byte gBattleStruct\n\t"
        "_0803EF08: .4byte gCurrentActionFuncId\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void BattleIntroPrepareBackgroundSlide(void)
{
    __asm__(".syntax unified\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r0, _0803A8B0\n\t"
        "	ldr r5, [r0]\n\t"
        "	cmp r5, #0\n\t"
        "	bne _0803A8A8\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r4, _0803A8B4\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r0, _0803A8B8\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitIntroSlide\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "	ldr r1, _0803A8BC\n\t"
        "	ldr r0, _0803A8C0\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _0803A8C4\n\t"
        "	strb r5, [r0]\n\t"
        "	strb r5, [r0, #1]\n\t"
        "_0803A8A8:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803A8B0: .4byte gBattleControllerExecFlags\n\t"
        "_0803A8B4: .4byte gActiveBattler\n\t"
        "_0803A8B8: .4byte gBattleEnvironment\n\t"
        "_0803A8BC: .4byte gBattleMainFunc\n\t"
        "_0803A8C0: .4byte BattleIntroDrawTrainersOrMonsSprites + 1\n\t"
        "_0803A8C4: .4byte gBattleCommunication\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void HandleTurnActionSelectionState(void)
{
    __asm__(".syntax unified\n\t"
        "	ldr r4, _0803BB08\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r1, _0803BB0C\n\t"
        "	ldrb r0, [r4]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #8\n\t"
        "	bls _0803BAFC\n\t"
        "	bl _0803C948\n\t"
        "_0803BAFC:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0803BB10\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0803BB08: .4byte gActiveBattler\n\t"
        "_0803BB0C: .4byte gBattleCommunication\n\t"
        "_0803BB10: .4byte 0x0803BB14\n\t"
        "_0803BB14: @ jump table\n\t"
        "	.4byte _0803BB38 @ case 0\n\t"
        "	.4byte _0803BB50 @ case 1\n\t"
        "	.4byte _0803BC70 @ case 2\n\t"
        "	.4byte _0803C41C @ case 3\n\t"
        "	.4byte _0803C714 @ case 4\n\t"
        "	.4byte _0803C7C8 @ case 5\n\t"
        "	.4byte _0803C80C @ case 6\n\t"
        "	.4byte _0803C838 @ case 7\n\t"
        "	.4byte _0803C87C @ case 8\n\t"
        "_0803BB38:\n\t"
        "	bl RecordedBattle_CopyBattlerMoves\n\t"
        "	ldr r1, _0803BB48\n\t"
        "	ldr r0, _0803BB4C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl _0803C864\n\t"
        "	.align 2, 0\n\t"
        "_0803BB48: .4byte gBattleCommunication\n\t"
        "_0803BB4C: .4byte gActiveBattler\n\t"
        "_0803BB50:\n\t"
        "	ldr r0, _0803BBE8\n\t"
        "	ldrb r1, [r0]\n\t"
        "	ldr r4, _0803BBEC\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x5c\n\t"
        "	movs r0, #6\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _0803BBF0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803BBAC\n\t"
        "	movs r1, #2\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r5\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803BBAC\n\t"
        "	eors r5, r1\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, #0x91\n\t"
        "	ldrb r1, [r1]\n\t"
        "	ldr r2, _0803BBF4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0803BBAC\n\t"
        "	ldr r4, _0803BBF8\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #5\n\t"
        "	beq _0803BBAC\n\t"
        "	bl _0803C948\n\t"
        "_0803BBAC:\n\t"
        "	ldr r0, _0803BBEC\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, #0x91\n\t"
        "	ldrb r3, [r0]\n\t"
        "	ldr r1, _0803BBF4\n\t"
        "	ldr r4, _0803BBE8\n\t"
        "	ldrb r2, [r4]\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r3, r0\n\t"
        "	cmp r3, #0\n\t"
        "	beq _0803BC14\n\t"
        "	ldr r0, _0803BBFC\n\t"
        "	adds r0, r2, r0\n\t"
        "	movs r1, #0xd\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _0803BBF0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x40\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803BC00\n\t"
        "	ldr r0, _0803BBF8\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #5\n\t"
        "	strb r0, [r1]\n\t"
        "	bl _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803BBE8: .4byte gActiveBattler\n\t"
        "_0803BBEC: .4byte gBattleStruct\n\t"
        "_0803BBF0: .4byte gBattleTypeFlags\n\t"
        "_0803BBF4: .4byte gBitTable\n\t"
        "_0803BBF8: .4byte gBattleCommunication\n\t"
        "_0803BBFC: .4byte gChosenActionByBattler\n\t"
        "_0803BC00:\n\t"
        "	ldr r0, _0803BC10\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #4\n\t"
        "	strb r0, [r1]\n\t"
        "	bl _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803BC10: .4byte gBattleCommunication\n\t"
        "_0803BC14:\n\t"
        "	ldr r1, _0803BC44\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r2, r0\n\t"
        "	adds r1, #0x50\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #5\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803BC34\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #0xf\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803BC50\n\t"
        "_0803BC34:\n\t"
        "	ldr r0, _0803BC48\n\t"
        "	adds r0, r2, r0\n\t"
        "	strb r3, [r0]\n\t"
        "	ldr r1, _0803BC4C\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl _0803C8B6\n\t"
        "	.align 2, 0\n\t"
        "_0803BC44: .4byte gBattleMons\n\t"
        "_0803BC48: .4byte gChosenActionByBattler\n\t"
        "_0803BC4C: .4byte gBattleCommunication\n\t"
        "_0803BC50:\n\t"
        "	ldr r0, _0803BC68\n\t"
        "	ldrb r1, [r0]\n\t"
        "	ldr r0, _0803BC6C\n\t"
        "	ldrb r2, [r0, #1]\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r2, r0\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitChooseAction\n\t"
        "	bl _0803C7AC\n\t"
        "	.align 2, 0\n\t"
        "_0803BC68: .4byte gChosenActionByBattler\n\t"
        "_0803BC6C: .4byte gBattleBufferB\n\t"
        "_0803BC70:\n\t"
        "	ldr r3, _0803BCD4\n\t"
        "	ldr r1, _0803BCD8\n\t"
        "	ldr r6, _0803BCDC\n\t"
        "	ldrb r5, [r6]\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	movs r0, #0xf0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r1, r0\n\t"
        "	orrs r1, r2\n\t"
        "	lsls r0, r2, #8\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r2, r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	ldr r0, [r3]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803BC9C\n\t"
        "	bl _0803C948\n\t"
        "_0803BC9C:\n\t"
        "	ldr r4, _0803BCE0\n\t"
        "	lsls r0, r5, #9\n\t"
        "	adds r4, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl RecordedBattle_SetBattlerAction\n\t"
        "	ldr r1, _0803BCE4\n\t"
        "	ldrb r0, [r6]\n\t"
        "	adds r1, r0, r1\n\t"
        "	lsls r0, r0, #9\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r0, r0, #9\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xc\n\t"
        "	bls _0803BCC8\n\t"
        "	b _0803C308\n\t"
        "_0803BCC8:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0803BCE8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0803BCD4: .4byte gBattleControllerExecFlags\n\t"
        "_0803BCD8: .4byte gBitTable\n\t"
        "_0803BCDC: .4byte gActiveBattler\n\t"
        "_0803BCE0: .4byte gBattleBufferB\n\t"
        "_0803BCE4: .4byte gChosenActionByBattler\n\t"
        "_0803BCE8: .4byte 0x0803BCEC\n\t"
        "_0803BCEC: @ jump table\n\t"
        "	.4byte _0803BD20 @ case 0\n\t"
        "	.4byte _0803BE74 @ case 1\n\t"
        "	.4byte _0803BEAC @ case 2\n\t"
        "	.4byte _0803C308 @ case 3\n\t"
        "	.4byte _0803C308 @ case 4\n\t"
        "	.4byte _0803C084 @ case 5\n\t"
        "	.4byte _0803C0D0 @ case 6\n\t"
        "	.4byte _0803C308 @ case 7\n\t"
        "	.4byte _0803C308 @ case 8\n\t"
        "	.4byte _0803C308 @ case 9\n\t"
        "	.4byte _0803C308 @ case 10\n\t"
        "	.4byte _0803C308 @ case 11\n\t"
        "	.4byte _0803C0F8 @ case 12\n\t"
        "_0803BD20:\n\t"
        "	bl AreAllMovesUnusable\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803BD78\n\t"
        "	ldr r0, _0803BD68\n\t"
        "	ldr r3, _0803BD6C\n\t"
        "	ldrb r1, [r3]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r4, #0\n\t"
        "	movs r0, #6\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	ldr r2, _0803BD70\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x54\n\t"
        "	strb r4, [r1]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x84\n\t"
        "	movs r0, #4\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	ldr r2, [r2]\n\t"
        "	adds r2, r1, r2\n\t"
        "	ldr r0, _0803BD74\n\t"
        "	lsls r1, r1, #9\n\t"
        "	adds r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	strb r0, [r2, #0xc]\n\t"
        "	bl _0803C9B4\n\t"
        "	.align 2, 0\n\t"
        "_0803BD68: .4byte gBattleCommunication\n\t"
        "_0803BD6C: .4byte gActiveBattler\n\t"
        "_0803BD70: .4byte gBattleStruct\n\t"
        "_0803BD74: .4byte gBattleBufferB\n\t"
        "_0803BD78:\n\t"
        "	ldr r3, _0803BDB8\n\t"
        "	ldr r5, _0803BDBC\n\t"
        "	ldrb r4, [r5]\n\t"
        "	lsls r0, r4, #3\n\t"
        "	subs r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r2, [r0, #6]\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0803BDCC\n\t"
        "	ldr r1, _0803BDC0\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r2, [r0]\n\t"
        "	ldrb r2, [r5]\n\t"
        "	ldr r0, _0803BDC4\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r1, r2, r1\n\t"
        "	adds r1, #0x80\n\t"
        "	lsls r0, r2, #3\n\t"
        "	subs r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0, #0xc]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, _0803BDC8\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #4\n\t"
        "	strb r1, [r0]\n\t"
        "	bl _0803C9B4\n\t"
        "	.align 2, 0\n\t"
        "_0803BDB8: .4byte gDisableStructs\n\t"
        "_0803BDBC: .4byte gActiveBattler\n\t"
        "_0803BDC0: .4byte gChosenMoveByBattler\n\t"
        "_0803BDC4: .4byte gBattleStruct\n\t"
        "_0803BDC8: .4byte gBattleCommunication\n\t"
        "_0803BDCC:\n\t"
        "	add r2, sp, #4\n\t"
        "	ldr r3, _0803BE6C\n\t"
        "	movs r1, #0x58\n\t"
        "	adds r0, r4, #0\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r2, #0x10]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x21\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r2, #0x12]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x22\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r2, #0x13]\n\t"
        "	movs r4, #0\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, #0xc\n\t"
        "	str r1, [sp, #0x18]\n\t"
        "	add r2, sp, #0x10\n\t"
        "	mov sl, r2\n\t"
        "	mov r8, r3\n\t"
        "	adds r7, r5, #0\n\t"
        "	movs r6, #0x58\n\t"
        "	movs r0, #0xc\n\t"
        "	add r0, r8\n\t"
        "	mov sb, r0\n\t"
        "	add r5, sp, #4\n\t"
        "_0803BE0E:\n\t"
        "	lsls r2, r4, #1\n\t"
        "	ldrb r0, [r7]\n\t"
        "	muls r0, r6, r0\n\t"
        "	adds r0, r2, r0\n\t"
        "	add r0, sb\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r5]\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	adds r3, r1, r4\n\t"
        "	ldrb r0, [r7]\n\t"
        "	muls r0, r6, r0\n\t"
        "	adds r0, r4, r0\n\t"
        "	mov r1, r8\n\t"
        "	adds r1, #0x24\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r3]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	adds r1, r0, #0\n\t"
        "	muls r1, r6, r1\n\t"
        "	adds r2, r2, r1\n\t"
        "	add r2, sb\n\t"
        "	ldrh r0, [r2]\n\t"
        "	add r1, r8\n\t"
        "	adds r1, #0x3b\n\t"
        "	ldrb r1, [r1]\n\t"
        "	lsls r2, r4, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	bl CalculatePPWithBonus\n\t"
        "	mov r2, sl\n\t"
        "	adds r1, r2, r4\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r5, #2\n\t"
        "	adds r4, #1\n\t"
        "	cmp r4, #3\n\t"
        "	ble _0803BE0E\n\t"
        "	ldr r0, _0803BE70\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #0\n\t"
        "	add r3, sp, #4\n\t"
        "	bl BtlController_EmitChooseMove\n\t"
        "	b _0803C072\n\t"
        "	.align 2, 0\n\t"
        "_0803BE6C: .4byte gBattleMons\n\t"
        "_0803BE70: .4byte gBattleTypeFlags\n\t"
        "_0803BE74:\n\t"
        "	ldr r0, _0803BE98\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _0803BE9C\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803BE82\n\t"
        "	b _0803C0D0\n\t"
        "_0803BE82:\n\t"
        "	ldr r4, _0803BEA0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #1\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "	ldr r1, _0803BEA4\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0803BEA8\n\t"
        "	b _0803C3C8\n\t"
        "	.align 2, 0\n\t"
        "_0803BE98: .4byte gBattleTypeFlags\n\t"
        "_0803BE9C: .4byte 0x021F0902\n\t"
        "_0803BEA0: .4byte gActiveBattler\n\t"
        "_0803BEA4: .4byte gSelectionBattleScripts\n\t"
        "_0803BEA8: .4byte gUnknown_8289E01\n\t"
        "_0803BEAC:\n\t"
        "	ldr r5, _0803BF14\n\t"
        "	ldrb r0, [r5]\n\t"
        "	ldr r3, _0803BF18\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r1, r0, r1\n\t"
        "	adds r1, #0x58\n\t"
        "	ldr r2, _0803BF1C\n\t"
        "	lsls r0, r0, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r7, _0803BF20\n\t"
        "	ldrb r2, [r5]\n\t"
        "	movs r6, #0x58\n\t"
        "	adds r0, r2, #0\n\t"
        "	muls r0, r6, r0\n\t"
        "	adds r1, r7, #0\n\t"
        "	adds r1, #0x50\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0803BF24\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0803BEFC\n\t"
        "	ldr r0, _0803BF28\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xb\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803BEFC\n\t"
        "	ldr r0, _0803BF2C\n\t"
        "	lsls r1, r2, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r1, [r1]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803BF30\n\t"
        "_0803BEFC:\n\t"
        "	ldr r0, _0803BF14\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x60\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #2\n\t"
        "	movs r2, #6\n\t"
        "	b _0803C044\n\t"
        "	.align 2, 0\n\t"
        "_0803BF14: .4byte gActiveBattler\n\t"
        "_0803BF18: .4byte gBattleStruct\n\t"
        "_0803BF1C: .4byte gBattlerPartyIndexes\n\t"
        "_0803BF20: .4byte gBattleMons\n\t"
        "_0803BF24: .4byte 0x0400E000\n\t"
        "_0803BF28: .4byte gBattleTypeFlags\n\t"
        "_0803BF2C: .4byte gStatuses3\n\t"
        "_0803BF30:\n\t"
        "	str r1, [sp]\n\t"
        "	movs r0, #0xc\n\t"
        "	adds r1, r2, #0\n\t"
        "	movs r2, #0x17\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	bne _0803BFB8\n\t"
        "	ldrb r1, [r5]\n\t"
        "	str r4, [sp]\n\t"
        "	movs r0, #0xc\n\t"
        "	movs r2, #0x47\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	beq _0803BF80\n\t"
        "	ldrb r0, [r5]\n\t"
        "	muls r0, r6, r0\n\t"
        "	adds r1, r0, r7\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x21\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0803BF80\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x22\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _0803BF80\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0x1a\n\t"
        "	bne _0803BFB8\n\t"
        "_0803BF80:\n\t"
        "	ldr r5, _0803BFE4\n\t"
        "	ldrb r1, [r5]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0xf\n\t"
        "	movs r2, #0x2a\n\t"
        "	movs r3, #0\n\t"
        "	bl AbilityBattleEffects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	beq _0803BFF4\n\t"
        "	ldr r2, _0803BFE8\n\t"
        "	ldrb r1, [r5]\n\t"
        "	movs r0, #0x58\n\t"
        "	muls r0, r1, r0\n\t"
        "	adds r1, r0, r2\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x21\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #8\n\t"
        "	beq _0803BFB8\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x22\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #8\n\t"
        "	bne _0803BFF4\n\t"
        "_0803BFB8:\n\t"
        "	subs r1, r4, #1\n\t"
        "	lsls r1, r1, #4\n\t"
        "	movs r0, #4\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r0, _0803BFEC\n\t"
        "	ldrb r3, [r0]\n\t"
        "	ldr r4, _0803BFF0\n\t"
        "	ldr r0, _0803BFE4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r2, r0, #1\n\t"
        "	adds r2, r2, r0\n\t"
        "	adds r2, #0x60\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r2\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #6\n\t"
        "	bl BtlController_EmitChoosePokemon\n\t"
        "	b _0803C072\n\t"
        "	.align 2, 0\n\t"
        "_0803BFE4: .4byte gActiveBattler\n\t"
        "_0803BFE8: .4byte gBattleMons\n\t"
        "_0803BFEC: .4byte gLastUsedAbility\n\t"
        "_0803BFF0: .4byte gBattleStruct\n\t"
        "_0803BFF4:\n\t"
        "	ldr r0, _0803C010\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r4, r0, #0\n\t"
        "	cmp r1, #2\n\t"
        "	bne _0803C01C\n\t"
        "	ldr r0, _0803C014\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0803C01C\n\t"
        "	ldr r0, _0803C018\n\t"
        "	ldr r3, [r0]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x5c\n\t"
        "	b _0803C032\n\t"
        "	.align 2, 0\n\t"
        "_0803C010: .4byte gActiveBattler\n\t"
        "_0803C014: .4byte gChosenActionByBattler\n\t"
        "_0803C018: .4byte gBattleStruct\n\t"
        "_0803C01C:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0803C054\n\t"
        "	ldr r0, _0803C04C\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0803C054\n\t"
        "	ldr r0, _0803C050\n\t"
        "	ldr r3, [r0]\n\t"
        "	adds r0, r3, #0\n\t"
        "	adds r0, #0x5d\n\t"
        "_0803C032:\n\t"
        "	ldrb r2, [r0]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x60\n\t"
        "	adds r3, r3, r0\n\t"
        "	str r3, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "_0803C044:\n\t"
        "	movs r3, #0\n\t"
        "	bl BtlController_EmitChoosePokemon\n\t"
        "	b _0803C072\n\t"
        "	.align 2, 0\n\t"
        "_0803C04C: .4byte gChosenActionByBattler\n\t"
        "_0803C050: .4byte gBattleStruct\n\t"
        "_0803C054:\n\t"
        "	ldr r2, _0803C07C\n\t"
        "	ldr r0, _0803C080\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x60\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r0, r0, r1\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #6\n\t"
        "	movs r3, #0\n\t"
        "	bl BtlController_EmitChoosePokemon\n\t"
        "_0803C072:\n\t"
        "	ldr r0, _0803C080\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "	b _0803C308\n\t"
        "	.align 2, 0\n\t"
        "_0803C07C: .4byte gBattleStruct\n\t"
        "_0803C080: .4byte gActiveBattler\n\t"
        "_0803C084:\n\t"
        "	bl IsPlayerPartyAndPokemonStorageFull\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803C090\n\t"
        "	b _0803C308\n\t"
        "_0803C090:\n\t"
        "	ldr r1, _0803C0BC\n\t"
        "	ldr r3, _0803C0C0\n\t"
        "	ldrb r0, [r3]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0803C0C4\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r0, _0803C0C8\n\t"
        "	ldrb r1, [r3]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r4, #0\n\t"
        "	movs r0, #6\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	ldr r2, _0803C0CC\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x54\n\t"
        "	strb r4, [r1]\n\t"
        "	ldrb r1, [r3]\n\t"
        "	b _0803C3E4\n\t"
        "	.align 2, 0\n\t"
        "_0803C0BC: .4byte gSelectionBattleScripts\n\t"
        "_0803C0C0: .4byte gActiveBattler\n\t"
        "_0803C0C4: .4byte gUnknown_8289099\n\t"
        "_0803C0C8: .4byte gBattleCommunication\n\t"
        "_0803C0CC: .4byte gBattleStruct\n\t"
        "_0803C0D0:\n\t"
        "	ldr r2, _0803C0F0\n\t"
        "	ldr r4, _0803C0F4\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x60\n\t"
        "	ldr r1, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitChooseItem\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "	b _0803C308\n\t"
        "	.align 2, 0\n\t"
        "_0803C0F0: .4byte gBattleStruct\n\t"
        "_0803C0F4: .4byte gActiveBattler\n\t"
        "_0803C0F8:\n\t"
        "	ldr r4, _0803C188\n\t"
        "	ldr r5, _0803C18C\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #7\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	movs r6, #2\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0803C190\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r7, #0x58\n\t"
        "	muls r0, r7, r0\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r4, #0x50\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #5\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803C176\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	muls r0, r7, r0\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C194\n\t"
        "_0803C176:\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitEndBounceEffect\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "	bl _0803C9B4\n\t"
        "	.align 2, 0\n\t"
        "_0803C188: .4byte gBattleCommunication\n\t"
        "_0803C18C: .4byte gActiveBattler\n\t"
        "_0803C190: .4byte gBattleMons\n\t"
        "_0803C194:\n\t"
        "	ldr r4, _0803C1D0\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0803C1D4\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #2\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "	b _0803C2F2\n\t"
        "	.align 2, 0\n\t"
        "_0803C1D0: .4byte gChosenActionByBattler\n\t"
        "_0803C1D4:\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0803C1FA\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	b _0803C2AC\n\t"
        "_0803C1FA:\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803C26C\n\t"
        "	ldr r4, _0803C264\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x14\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0803C25A\n\t"
        "	ldr r4, _0803C268\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrh r0, [r1, #6]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C26C\n\t"
        "_0803C25A:\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r6\n\t"
        "	b _0803C2AC\n\t"
        "	.align 2, 0\n\t"
        "_0803C264: .4byte gProtectStructs\n\t"
        "_0803C268: .4byte gDisableStructs\n\t"
        "_0803C26C:\n\t"
        "	ldr r0, _0803C2C0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xa\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C2D4\n\t"
        "	ldr r4, _0803C2C4\n\t"
        "	ldr r6, _0803C2C8\n\t"
        "	ldrb r0, [r6]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	movs r5, #2\n\t"
        "	eors r0, r5\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803C2D4\n\t"
        "	ldr r1, _0803C2CC\n\t"
        "	ldr r0, _0803C2D0\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r1]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	eors r0, r5\n\t"
        "_0803C2AC:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #1\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "	b _0803C2F2\n\t"
        "	.align 2, 0\n\t"
        "_0803C2C0: .4byte gBattleTypeFlags\n\t"
        "_0803C2C4: .4byte gChosenActionByBattler\n\t"
        "_0803C2C8: .4byte gActiveBattler\n\t"
        "_0803C2CC: .4byte gRngValue\n\t"
        "_0803C2D0: .4byte gUnknown_203B9FC\n\t"
        "_0803C2D4:\n\t"
        "	ldr r0, _0803C304\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBattlerPosition\n\t"
        "	movs r1, #2\n\t"
        "	eors r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #3\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "_0803C2F2:\n\t"
        "	movs r0, #0\n\t"
        "	bl BtlController_EmitEndBounceEffect\n\t"
        "	ldr r0, _0803C304\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "	b _0803C9B4\n\t"
        "	.align 2, 0\n\t"
        "_0803C304: .4byte gActiveBattler\n\t"
        "_0803C308:\n\t"
        "	ldr r1, _0803C348\n\t"
        "	ldr r2, [r1]\n\t"
        "	movs r5, #8\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r0, r5\n\t"
        "	adds r3, r1, #0\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C364\n\t"
        "	ldr r0, _0803C34C\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0803C364\n\t"
        "	ldr r0, _0803C350\n\t"
        "	ldr r4, _0803C354\n\t"
        "	ldrb r2, [r4]\n\t"
        "	lsls r1, r2, #9\n\t"
        "	adds r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0803C364\n\t"
        "	ldr r1, _0803C358\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0803C35C\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r1, _0803C360\n\t"
        "	ldrb r0, [r4]\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r3, #0\n\t"
        "	strb r5, [r0]\n\t"
        "	b _0803C3D6\n\t"
        "	.align 2, 0\n\t"
        "_0803C348: .4byte gBattleTypeFlags\n\t"
        "_0803C34C: .4byte 0x043F0100\n\t"
        "_0803C350: .4byte gBattleBufferB\n\t"
        "_0803C354: .4byte gActiveBattler\n\t"
        "_0803C358: .4byte gSelectionBattleScripts\n\t"
        "_0803C35C: .4byte gUnknown_8289F42\n\t"
        "_0803C360: .4byte gBattleCommunication\n\t"
        "_0803C364:\n\t"
        "	ldr r0, [r3]\n\t"
        "	ldr r1, _0803C390\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #8\n\t"
        "	bne _0803C3A4\n\t"
        "	ldr r0, _0803C394\n\t"
        "	ldr r4, _0803C398\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r1, r1, #9\n\t"
        "	adds r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0803C3A4\n\t"
        "	ldr r0, _0803C39C\n\t"
        "	bl BattleScriptExecute\n\t"
        "	ldr r1, _0803C3A0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	adds r0, r0, r1\n\t"
        "	b _0803C864\n\t"
        "	.align 2, 0\n\t"
        "_0803C390: .4byte gUnknown_200000A\n\t"
        "_0803C394: .4byte gBattleBufferB\n\t"
        "_0803C398: .4byte gActiveBattler\n\t"
        "_0803C39C: .4byte gUnknown_8289086\n\t"
        "_0803C3A0: .4byte gBattleCommunication\n\t"
        "_0803C3A4:\n\t"
        "	bl IsRunningFromBattleImpossible\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C408\n\t"
        "	ldr r0, _0803C3F0\n\t"
        "	ldr r4, _0803C3F4\n\t"
        "	ldrb r2, [r4]\n\t"
        "	lsls r1, r2, #9\n\t"
        "	adds r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0803C408\n\t"
        "	ldr r1, _0803C3F8\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0803C3FC\n\t"
        "_0803C3C8:\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r0, _0803C400\n\t"
        "	ldrb r1, [r4]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r3, #0\n\t"
        "	movs r0, #6\n\t"
        "	strb r0, [r1]\n\t"
        "_0803C3D6:\n\t"
        "	ldrb r1, [r4]\n\t"
        "	ldr r2, _0803C404\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x54\n\t"
        "	strb r3, [r1]\n\t"
        "	ldrb r1, [r4]\n\t"
        "_0803C3E4:\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x84\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0803C9B4\n\t"
        "	.align 2, 0\n\t"
        "_0803C3F0: .4byte gBattleBufferB\n\t"
        "_0803C3F4: .4byte gActiveBattler\n\t"
        "_0803C3F8: .4byte gSelectionBattleScripts\n\t"
        "_0803C3FC: .4byte gUnknown_8289093\n\t"
        "_0803C400: .4byte gBattleCommunication\n\t"
        "_0803C404: .4byte gBattleStruct\n\t"
        "_0803C408:\n\t"
        "	ldr r2, _0803C414\n\t"
        "	ldr r0, _0803C418\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, r1, r2\n\t"
        "	b _0803C7B8\n\t"
        "	.align 2, 0\n\t"
        "_0803C414: .4byte gBattleCommunication\n\t"
        "_0803C418: .4byte gActiveBattler\n\t"
        "_0803C41C:\n\t"
        "	ldr r4, _0803C460\n\t"
        "	ldr r1, _0803C464\n\t"
        "	ldr r3, _0803C468\n\t"
        "	ldrb r5, [r3]\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	lsls r0, r2, #4\n\t"
        "	movs r1, #0xf0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	orrs r0, r1\n\t"
        "	orrs r0, r2\n\t"
        "	lsls r1, r2, #8\n\t"
        "	orrs r0, r1\n\t"
        "	lsls r2, r2, #0xc\n\t"
        "	orrs r0, r2\n\t"
        "	ldr r1, [r4]\n\t"
        "	ands r1, r0\n\t"
        "	adds r4, r3, #0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803C448\n\t"
        "	b _0803C948\n\t"
        "_0803C448:\n\t"
        "	ldr r1, _0803C46C\n\t"
        "	adds r0, r5, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r2, r1, #0\n\t"
        "	cmp r0, #9\n\t"
        "	bls _0803C456\n\t"
        "	b _0803C948\n\t"
        "_0803C456:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0803C470\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0803C460: .4byte gBattleControllerExecFlags\n\t"
        "_0803C464: .4byte gBitTable\n\t"
        "_0803C468: .4byte gActiveBattler\n\t"
        "_0803C46C: .4byte gChosenActionByBattler\n\t"
        "_0803C470: .4byte 0x0803C474\n\t"
        "_0803C474: @ jump table\n\t"
        "	.4byte _0803C49C @ case 0\n\t"
        "	.4byte _0803C5E0 @ case 1\n\t"
        "	.4byte _0803C618 @ case 2\n\t"
        "	.4byte _0803C64E @ case 3\n\t"
        "	.4byte _0803C670 @ case 4\n\t"
        "	.4byte _0803C684 @ case 5\n\t"
        "	.4byte _0803C698 @ case 6\n\t"
        "	.4byte _0803C6C8 @ case 7\n\t"
        "	.4byte _0803C6DC @ case 8\n\t"
        "	.4byte _0803C700 @ case 9\n\t"
        "_0803C49C:\n\t"
        "	ldr r1, _0803C4B8\n\t"
        "	ldrb r3, [r4]\n\t"
        "	lsls r0, r3, #9\n\t"
        "	adds r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	cmp r1, #3\n\t"
        "	blt _0803C4CE\n\t"
        "	cmp r1, #9\n\t"
        "	ble _0803C4BC\n\t"
        "	cmp r1, #0xf\n\t"
        "	beq _0803C4C2\n\t"
        "	b _0803C4CE\n\t"
        "	.align 2, 0\n\t"
        "_0803C4B8: .4byte gBattleBufferB\n\t"
        "_0803C4BC:\n\t"
        "	adds r0, r3, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	b _0803C9B4\n\t"
        "_0803C4C2:\n\t"
        "	adds r1, r3, r2\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r1]\n\t"
        "	bl UpdateBattlerPartyOrdersOnSwitch\n\t"
        "	b _0803C9B4\n\t"
        "_0803C4CE:\n\t"
        "	movs r0, #2\n\t"
        "	bl sub_08185D94\n\t"
        "	ldr r4, _0803C504\n\t"
        "	ldr r6, _0803C508\n\t"
        "	ldrb r3, [r6]\n\t"
        "	lsls r1, r3, #9\n\t"
        "	adds r5, r4, #2\n\t"
        "	adds r0, r1, r5\n\t"
        "	ldrb r2, [r0]\n\t"
        "	adds r7, r4, #3\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r2, r0\n\t"
        "	ldr r0, _0803C50C\n\t"
        "	cmp r2, r0\n\t"
        "	bne _0803C514\n\t"
        "	ldr r0, _0803C510\n\t"
        "	adds r0, r3, r0\n\t"
        "	movs r1, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "	b _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803C504: .4byte gBattleBufferB\n\t"
        "_0803C508: .4byte gActiveBattler\n\t"
        "_0803C50C: .4byte 0x0000FFFF\n\t"
        "_0803C510: .4byte gBattleCommunication\n\t"
        "_0803C514:\n\t"
        "	bl TrySetCantSelectMoveBattleScript\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C560\n\t"
        "	ldrb r0, [r6]\n\t"
        "	movs r1, #1\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "	ldr r0, _0803C558\n\t"
        "	ldrb r1, [r6]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r3, #0\n\t"
        "	movs r0, #6\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r1, [r6]\n\t"
        "	ldr r2, _0803C55C\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x54\n\t"
        "	strb r3, [r1]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r0, r0, #9\n\t"
        "	adds r1, r4, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r3, [r0]\n\t"
        "	ldrb r1, [r6]\n\t"
        "	ldr r0, [r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, #0x84\n\t"
        "	movs r0, #2\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0803C9B4\n\t"
        "	.align 2, 0\n\t"
        "_0803C558: .4byte gBattleCommunication\n\t"
        "_0803C55C: .4byte gBattleStruct\n\t"
        "_0803C560:\n\t"
        "	ldr r0, _0803C5CC\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xa\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803C586\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r1, r0, #9\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrb r1, [r1]\n\t"
        "	bl RecordedBattle_SetBattlerAction\n\t"
        "	ldrb r0, [r6]\n\t"
        "	lsls r1, r0, #9\n\t"
        "	adds r1, r1, r7\n\t"
        "	ldrb r1, [r1]\n\t"
        "	bl RecordedBattle_SetBattlerAction\n\t"
        "_0803C586:\n\t"
        "	ldrb r0, [r6]\n\t"
        "	ldr r4, _0803C5D0\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r1, r0, r1\n\t"
        "	adds r1, #0x80\n\t"
        "	lsls r0, r0, #9\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _0803C5D4\n\t"
        "	ldrb r2, [r6]\n\t"
        "	lsls r5, r2, #1\n\t"
        "	adds r5, r5, r0\n\t"
        "	ldr r3, _0803C5D8\n\t"
        "	ldr r4, [r4]\n\t"
        "	adds r0, r2, r4\n\t"
        "	adds r0, #0x80\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	movs r1, #0x58\n\t"
        "	muls r1, r2, r1\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r3, #0xc\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r5]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	adds r4, r0, r4\n\t"
        "	lsls r0, r0, #9\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r4, #0xc]\n\t"
        "	ldr r0, _0803C5DC\n\t"
        "	ldrb r1, [r6]\n\t"
        "	b _0803C7B6\n\t"
        "	.align 2, 0\n\t"
        "_0803C5CC: .4byte gBattleTypeFlags\n\t"
        "_0803C5D0: .4byte gBattleStruct\n\t"
        "_0803C5D4: .4byte gChosenMoveByBattler\n\t"
        "_0803C5D8: .4byte gBattleMons\n\t"
        "_0803C5DC: .4byte gBattleCommunication\n\t"
        "_0803C5E0:\n\t"
        "	ldr r2, _0803C608\n\t"
        "	ldr r5, _0803C60C\n\t"
        "	ldrb r4, [r5]\n\t"
        "	lsls r1, r4, #9\n\t"
        "	adds r0, r2, #1\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldrb r3, [r0]\n\t"
        "	adds r2, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r3, r0\n\t"
        "	cmp r3, #0\n\t"
        "	bne _0803C5FE\n\t"
        "	b _0803C860\n\t"
        "_0803C5FE:\n\t"
        "	ldr r0, _0803C610\n\t"
        "	strh r3, [r0]\n\t"
        "	ldr r0, _0803C614\n\t"
        "	ldrb r1, [r5]\n\t"
        "	b _0803C7B6\n\t"
        "	.align 2, 0\n\t"
        "_0803C608: .4byte gBattleBufferB\n\t"
        "_0803C60C: .4byte gActiveBattler\n\t"
        "_0803C610: .4byte gLastUsedItem\n\t"
        "_0803C614: .4byte gBattleCommunication\n\t"
        "_0803C618:\n\t"
        "	ldr r0, _0803C63C\n\t"
        "	ldr r4, _0803C640\n\t"
        "	ldrb r2, [r4]\n\t"
        "	lsls r1, r2, #9\n\t"
        "	adds r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #6\n\t"
        "	bne _0803C648\n\t"
        "	ldr r0, _0803C644\n\t"
        "	adds r0, r2, r0\n\t"
        "	movs r1, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "	b _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803C63C: .4byte gBattleBufferB\n\t"
        "_0803C640: .4byte gActiveBattler\n\t"
        "_0803C644: .4byte gBattleCommunication\n\t"
        "_0803C648:\n\t"
        "	bl UpdateBattlerPartyOrdersOnSwitch\n\t"
        "	b _0803C7B2\n\t"
        "_0803C64E:\n\t"
        "	ldr r2, _0803C664\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "	ldr r2, _0803C668\n\t"
        "	ldr r0, _0803C66C\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, r1, r2\n\t"
        "	b _0803C7B8\n\t"
        "	.align 2, 0\n\t"
        "_0803C664: .4byte gHitMarker\n\t"
        "_0803C668: .4byte gBattleCommunication\n\t"
        "_0803C66C: .4byte gActiveBattler\n\t"
        "_0803C670:\n\t"
        "	ldr r2, _0803C67C\n\t"
        "	ldr r0, _0803C680\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, r1, r2\n\t"
        "	b _0803C7B8\n\t"
        "	.align 2, 0\n\t"
        "_0803C67C: .4byte gBattleCommunication\n\t"
        "_0803C680: .4byte gActiveBattler\n\t"
        "_0803C684:\n\t"
        "	ldr r2, _0803C690\n\t"
        "	ldr r0, _0803C694\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, r1, r2\n\t"
        "	b _0803C7B8\n\t"
        "	.align 2, 0\n\t"
        "_0803C690: .4byte gBattleCommunication\n\t"
        "_0803C694: .4byte gActiveBattler\n\t"
        "_0803C698:\n\t"
        "	ldr r3, _0803C6BC\n\t"
        "	ldr r0, _0803C6C0\n\t"
        "	ldrb r4, [r0]\n\t"
        "	lsls r1, r4, #9\n\t"
        "	adds r0, r3, #1\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldrb r2, [r0]\n\t"
        "	adds r3, #2\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	orrs r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	bne _0803C6B6\n\t"
        "	b _0803C860\n\t"
        "_0803C6B6:\n\t"
        "	ldr r1, _0803C6C4\n\t"
        "	adds r1, r4, r1\n\t"
        "	b _0803C7B8\n\t"
        "	.align 2, 0\n\t"
        "_0803C6BC: .4byte gBattleBufferB\n\t"
        "_0803C6C0: .4byte gActiveBattler\n\t"
        "_0803C6C4: .4byte gBattleCommunication\n\t"
        "_0803C6C8:\n\t"
        "	ldr r2, _0803C6D4\n\t"
        "	ldr r0, _0803C6D8\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, r1, r2\n\t"
        "	b _0803C7B8\n\t"
        "	.align 2, 0\n\t"
        "_0803C6D4: .4byte gBattleCommunication\n\t"
        "_0803C6D8: .4byte gActiveBattler\n\t"
        "_0803C6DC:\n\t"
        "	ldr r2, _0803C6F4\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "	ldr r2, _0803C6F8\n\t"
        "	ldr r0, _0803C6FC\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, r1, r2\n\t"
        "	b _0803C7B8\n\t"
        "	.align 2, 0\n\t"
        "_0803C6F4: .4byte gHitMarker\n\t"
        "_0803C6F8: .4byte gBattleCommunication\n\t"
        "_0803C6FC: .4byte gActiveBattler\n\t"
        "_0803C700:\n\t"
        "	ldr r2, _0803C70C\n\t"
        "	ldr r0, _0803C710\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, r1, r2\n\t"
        "	b _0803C7B8\n\t"
        "	.align 2, 0\n\t"
        "_0803C70C: .4byte gBattleCommunication\n\t"
        "_0803C710: .4byte gActiveBattler\n\t"
        "_0803C714:\n\t"
        "	ldr r3, _0803C78C\n\t"
        "	ldr r6, _0803C790\n\t"
        "	ldr r0, _0803C794\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldr r2, [r0]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	movs r0, #0xf0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r1, r0\n\t"
        "	orrs r1, r2\n\t"
        "	lsls r0, r2, #8\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r2, r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	ldr r0, [r3]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C73E\n\t"
        "	b _0803C948\n\t"
        "_0803C73E:\n\t"
        "	bl AllAtActionConfirmed\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	rsbs r1, r0, #0\n\t"
        "	orrs r1, r0\n\t"
        "	lsrs r4, r1, #0x1f\n\t"
        "	ldr r0, _0803C798\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x41\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0803C780\n\t"
        "	movs r1, #2\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r5\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803C780\n\t"
        "	adds r0, r5, #0\n\t"
        "	eors r0, r1\n\t"
        "	bl GetBattlerAtPosition\n\t"
        "	ldr r1, _0803C79C\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, #0x91\n\t"
        "	ldrb r1, [r1]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0803C7A0\n\t"
        "_0803C780:\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl BtlController_EmitLinkStandbyMsg\n\t"
        "	b _0803C7AA\n\t"
        "	.align 2, 0\n\t"
        "_0803C78C: .4byte gBattleControllerExecFlags\n\t"
        "_0803C790: .4byte gBitTable\n\t"
        "_0803C794: .4byte gActiveBattler\n\t"
        "_0803C798: .4byte gBattleTypeFlags\n\t"
        "_0803C79C: .4byte gBattleStruct\n\t"
        "_0803C7A0:\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl BtlController_EmitLinkStandbyMsg\n\t"
        "_0803C7AA:\n\t"
        "	ldr r4, _0803C7C0\n\t"
        "_0803C7AC:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl MarkBattlerForControllerExec\n\t"
        "_0803C7B2:\n\t"
        "	ldr r0, _0803C7C4\n\t"
        "	ldrb r1, [r4]\n\t"
        "_0803C7B6:\n\t"
        "	adds r1, r1, r0\n\t"
        "_0803C7B8:\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803C7C0: .4byte gActiveBattler\n\t"
        "_0803C7C4: .4byte gBattleCommunication\n\t"
        "_0803C7C8:\n\t"
        "	ldr r3, _0803C7FC\n\t"
        "	ldr r1, _0803C800\n\t"
        "	ldr r0, _0803C804\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	movs r0, #0xf0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r1, r0\n\t"
        "	orrs r1, r2\n\t"
        "	lsls r0, r2, #8\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r2, r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	ldr r0, [r3]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C7F2\n\t"
        "	b _0803C948\n\t"
        "_0803C7F2:\n\t"
        "	ldr r1, _0803C808\n\t"
        "	ldrb r0, [r1, #4]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1, #4]\n\t"
        "	b _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803C7FC: .4byte gBattleControllerExecFlags\n\t"
        "_0803C800: .4byte gBitTable\n\t"
        "_0803C804: .4byte gActiveBattler\n\t"
        "_0803C808: .4byte gBattleCommunication\n\t"
        "_0803C80C:\n\t"
        "	ldr r5, _0803C82C\n\t"
        "	ldrb r2, [r5]\n\t"
        "	ldr r0, _0803C830\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r1, r2, r0\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x54\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C8F8\n\t"
        "	ldr r0, _0803C834\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r1, #0x84\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	b _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803C82C: .4byte gActiveBattler\n\t"
        "_0803C830: .4byte gBattleStruct\n\t"
        "_0803C834: .4byte gBattleCommunication\n\t"
        "_0803C838:\n\t"
        "	ldr r3, _0803C86C\n\t"
        "	ldr r1, _0803C870\n\t"
        "	ldr r0, _0803C874\n\t"
        "	ldrb r4, [r0]\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	movs r0, #0xf0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r1, r0\n\t"
        "	orrs r1, r2\n\t"
        "	lsls r0, r2, #8\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r2, r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	ldr r0, [r3]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803C948\n\t"
        "_0803C860:\n\t"
        "	ldr r0, _0803C878\n\t"
        "	adds r0, r4, r0\n\t"
        "_0803C864:\n\t"
        "	movs r1, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	b _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803C86C: .4byte gBattleControllerExecFlags\n\t"
        "_0803C870: .4byte gBitTable\n\t"
        "_0803C874: .4byte gActiveBattler\n\t"
        "_0803C878: .4byte gBattleCommunication\n\t"
        "_0803C87C:\n\t"
        "	ldr r5, _0803C8C0\n\t"
        "	ldrb r2, [r5]\n\t"
        "	ldr r4, _0803C8C4\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r2, r0\n\t"
        "	adds r0, #0x54\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C8F8\n\t"
        "	ldr r0, _0803C8C8\n\t"
        "	lsls r1, r2, #9\n\t"
        "	adds r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0xd\n\t"
        "	bne _0803C8D8\n\t"
        "	ldr r2, _0803C8CC\n\t"
        "	ldr r0, [r2]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "	ldr r1, _0803C8D0\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #3\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, _0803C8D4\n\t"
        "	ldrb r0, [r5]\n\t"
        "_0803C8B6:\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #4\n\t"
        "	strb r1, [r0]\n\t"
        "	b _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803C8C0: .4byte gActiveBattler\n\t"
        "_0803C8C4: .4byte gBattleStruct\n\t"
        "_0803C8C8: .4byte gBattleBufferB\n\t"
        "_0803C8CC: .4byte gHitMarker\n\t"
        "_0803C8D0: .4byte gChosenActionByBattler\n\t"
        "_0803C8D4: .4byte gBattleCommunication\n\t"
        "_0803C8D8:\n\t"
        "	adds r0, r2, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl RecordedBattle_ClearBattlerAction\n\t"
        "	ldr r2, _0803C8F4\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r2, r0, r2\n\t"
        "	ldr r1, [r4]\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #0x84\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r2]\n\t"
        "	b _0803C948\n\t"
        "	.align 2, 0\n\t"
        "_0803C8F4: .4byte gBattleCommunication\n\t"
        "_0803C8F8:\n\t"
        "	ldr r0, _0803C9C4\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r7, _0803C9C8\n\t"
        "	ldr r6, _0803C9CC\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldr r4, [r0]\n\t"
        "	str r4, [r7]\n\t"
        "	ldr r3, _0803C9D0\n\t"
        "	ldr r1, _0803C9D4\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [r0]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	movs r0, #0xf0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r1, r0\n\t"
        "	orrs r1, r2\n\t"
        "	lsls r0, r2, #8\n\t"
        "	orrs r1, r0\n\t"
        "	lsls r2, r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	ldr r0, [r3]\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0803C93E\n\t"
        "	ldr r0, _0803C9D8\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, [r1]\n\t"
        "	bl _call_via_r0\n\t"
        "_0803C93E:\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldr r1, [r7]\n\t"
        "	str r1, [r0]\n\t"
        "_0803C948:\n\t"
        "	ldr r0, _0803C9DC\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r1, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, _0803C9E0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        ".global _0803C956\n\t"
        "_0803C956:\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrb r0, [r5]\n\t"
        "	cmp r1, r0\n\t"
        "	bhs _0803C962\n\t"
        "	bl HandleTurnActionSelectionState\n\t"
        "_0803C962:\n\t"
        "	ldr r0, _0803C9E4\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	ldrb r1, [r5]\n\t"
        "	cmp r0, r1\n\t"
        "	bne _0803C9B4\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_08185D94\n\t"
        "	ldr r1, _0803C9E8\n\t"
        "	ldr r0, _0803C9EC\n\t"
        "	str r0, [r1]\n\t"
        "	ldr r0, _0803C9F0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0803C9B4\n\t"
        "	movs r4, #0\n\t"
        "	ldrb r5, [r5]\n\t"
        "	cmp r4, r5\n\t"
        "	bge _0803C9B4\n\t"
        "_0803C98E:\n\t"
        "	ldr r0, _0803C9F4\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0803C9AA\n\t"
        "	lsls r0, r4, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0803C9F8\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r4, r1\n\t"
        "	adds r1, #0x5c\n\t"
        "	ldrb r1, [r1]\n\t"
        "	bl SwitchPartyOrderInGameMulti\n\t"
        "_0803C9AA:\n\t"
        "	adds r4, #1\n\t"
        "	ldr r0, _0803C9E0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r4, r0\n\t"
        "	blt _0803C98E\n\t"
        "_0803C9B4:\n\t"
        "	add sp, #0x1c\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0803C9C4: .4byte gBattlerAttacker\n\t"
        "_0803C9C8: .4byte gBattlescriptCurrInstr\n\t"
        "_0803C9CC: .4byte gSelectionBattleScripts\n\t"
        "_0803C9D0: .4byte gBattleControllerExecFlags\n\t"
        "_0803C9D4: .4byte gBitTable\n\t"
        "_0803C9D8: .4byte gBattleScriptingCommandsTable\n\t"
        "_0803C9DC: .4byte gActiveBattler\n\t"
        "_0803C9E0: .4byte gBattlersCount\n\t"
        "_0803C9E4: .4byte gBattleCommunication\n\t"
        "_0803C9E8: .4byte gBattleMainFunc\n\t"
        "_0803C9EC: .4byte 0x0803CF2D\n\t"
        "_0803C9F0: .4byte gBattleTypeFlags\n\t"
        "_0803C9F4: .4byte gChosenActionByBattler\n\t"
        "_0803C9F8: .4byte gBattleStruct\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void RunBattleScriptCommands(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, lr}\n\t"
        "ldr r6, _0803D4B0\n\t"
        "ldrb r0, [r6]\n\t"
        "ldr r2, _0803D4B4\n\t"
        "cmp r0, #0\n\t"
        "beq _0803D46C\n\t"
        "movs r0, #0xc\n\t"
        "strb r0, [r2]\n\t"
        "_0803D46C:\n\t"
        "ldr r5, _0803D4B8\n\t"
        "ldr r0, [r5]\n\t"
        "adds r0, #0x4b\n\t"
        "ldr r4, _0803D4BC\n\t"
        "ldrb r1, [r4]\n\t"
        "strb r1, [r0]\n\t"
        "ldr r1, _0803D4C0\n\t"
        "ldrb r0, [r2]\n\t"
        "lsls r0, r0, #2\n\t"
        "adds r0, r0, r1\n\t"
        "ldr r0, [r0]\n\t"
        "bl _call_via_r0\n\t"
        "ldr r0, _0803D4C4\n\t"
        "_0803D488:\n\t"
        "ldrb r1, [r4]\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r1, r0\n\t"
        "blo _0803D4D8\n\t"
        "ldr r2, _0803D4C8\n\t"
        "ldr r0, [r2]\n\t"
        "ldr r1, _0803D4CC\n\t"
        "ands r0, r1\n\t"
        "str r0, [r2]\n\t"
        "ldr r3, _0803D4D0\n\t"
        "ldr r2, _0803D4D4\n\t"
        "ldrb r1, [r6]\n\t"
        "movs r0, #0x7f\n\t"
        "ands r0, r1\n\t"
        "lsls r0, r0, #2\n\t"
        "adds r0, r0, r2\n\t"
        "ldr r0, [r0]\n\t"
        "str r0, [r3]\n\t"
        "b _0803D4F0\n\t"
        ".align 2, 0\n\t"
        "_0803D4B0: .4byte gBattleOutcome\n\t"
        "_0803D4B4: .4byte gCurrentActionFuncId\n\t"
        "_0803D4B8: .4byte gBattleStruct\n\t"
        "_0803D4BC: .4byte gCurrentTurnActionNumber\n\t"
        "_0803D4C0: .4byte sTurnActionsFuncsTable\n\t"
        "_0803D4C4: .4byte gBattlersCount\n\t"
        "_0803D4C8: .4byte gHitMarker\n\t"
        "_0803D4CC: .4byte 0xFFEFFFFF\n\t"
        "_0803D4D0: .4byte gBattleMainFunc\n\t"
        "_0803D4D4: .4byte sEndTurnFuncsTable\n\t"
        "_0803D4D8:\n\t"
        "ldr r0, [r5]\n\t"
        "adds r0, #0x4b\n\t"
        "ldrb r0, [r0]\n\t"
        "cmp r0, r1\n\t"
        "beq _0803D4F0\n\t"
        "ldr r2, _0803D4F8\n\t"
        "ldr r0, [r2]\n\t"
        "ldr r1, _0803D4FC\n\t"
        "ands r0, r1\n\t"
        "ldr r1, _0803D500\n\t"
        "ands r0, r1\n\t"
        "str r0, [r2]\n\t"
        "_0803D4F0:\n\t"
        "pop {r4, r5, r6}\n\t"
        "pop {r0}\n\t"
        "bx r0\n\t"
        ".align 2, 0\n\t"
        "_0803D4F8: .4byte gHitMarker\n\t"
        "_0803D4FC: .4byte 0xFFFFFDFF\n\t"
        "_0803D500: .4byte 0xFFF7FFFF\n\t"
        ".syntax divided\n\t"
    );
}
