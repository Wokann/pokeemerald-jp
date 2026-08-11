#include "global.h"
#include "battle_tent.h"
#include "overworld.h"
#include "event_data.h"
#include "region_map.h"
#include "battle.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "random.h"
#include "item.h"
#include "battle_factory_screen.h"
#include "frontier_util.h"
#include "string_util.h"
#include "constants/battle_tent.h"
#include "constants/battle_tent_trainers.h"
#include "constants/battle_tent_mons.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"

// This file's functions.
static void InitVerdanturfTentChallenge(void);
static void GetVerdanturfTentPrize(void);
static void SetVerdanturfTentPrize(void);
static void SetVerdanturfTentTrainerGfx(void);
static void BufferVerdanturfTentTrainerIntro(void);
static void SaveVerdanturfTentChallenge(void);
static void SetRandomVerdanturfTentPrize(void);
static void GiveVerdanturfTentPrize(void);
static void InitFallarborTentChallenge(void);
static void GetFallarborTentPrize(void);
static void SetFallarborTentPrize(void);
static void SaveFallarborTentChallenge(void);
static void SetRandomFallarborTentPrize(void);
static void GiveFallarborTentPrize(void);
static void BufferFallarborTentTrainerName(void);
static void InitSlateportTentChallenge(void);
static void GetSlateportTentPrize(void);
static void SetSlateportTentPrize(void);
static void SaveSlateportTentChallenge(void);
static void SetRandomSlateportTentPrize(void);
static void GiveSlateportTentPrize(void);
static void SelectInitialRentalMons(void);
static void SwapRentalMons(void);
static void GenerateOpponentMons(void);
// Kept as naked asm: agbcc cannot reproduce the JP register allocation
// for the rental-mon generation loop (sb/r8 stack pointers).

/*
 * Battle Tents are mini versions of particular Battle Frontier facilities
 * As such they each share some scripts and functions with their counterpart
 *
 * Verdanturf Battle Tent: Battle Palace
 * Fallarbor Battle Tent:  Battle Arena
 * Slateport Battle Tent:  Battle Factory
 *
 */

extern u16 sRandMonId;

// JP asm name for the still-asm frontier save helper; US: SaveGameFrontier.
void sub_081A482C(void);

// JP keeps the tent dispatch/reward tables in ROM.
extern void (*const sVerdanturfTentFuncs[])(void);
extern const u16 sVerdanturfTentRewards[1];
extern void (*const sFallarborTentFuncs[])(void);
extern const u16 sFallarborTentRewards[1];
extern void (*const sSlateportTentFuncs[])(void);
extern const u16 sSlateportTentRewards[1];

// code
// Kept as naked asm with the 2-byte placeholder: agbcc would place the
// literal pool inside the function and shift the module layout.
void CallVerdanturfTentFunction(void)
{
    sVerdanturfTentFuncs[gSpecialVar_0x8004]();
}

// JP-only alias: the shared bx r0 tail (and literal pool) is labeled sub_081B9668.
__asm__(".set sub_081B9668, CallVerdanturfTentFunction + 0x14");

static void InitVerdanturfTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetVerdanturfTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.verdanturfTentPrize;
}

static void SetVerdanturfTentPrize(void)
{
    gSaveBlock2Ptr->frontier.verdanturfTentPrize = gSpecialVar_0x8006;
}

static void SetVerdanturfTentTrainerGfx(void)
{
    gTrainerBattleOpponent_A = (u32)((Random() % 255) * 5) / 64;
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

static void BufferVerdanturfTentTrainerIntro(void)
{
    if (gTrainerBattleOpponent_A < FRONTIER_TRAINERS_COUNT)
        FrontierSpeechToString(gFacilityTrainers[gTrainerBattleOpponent_A].speechBefore);
}

static void SaveVerdanturfTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    sub_081A482C();
}

static void SetRandomVerdanturfTentPrize(void)
{
    gSaveBlock2Ptr->frontier.verdanturfTentPrize = sVerdanturfTentRewards[Random() % ARRAY_COUNT(sVerdanturfTentRewards)];
}

static void GiveVerdanturfTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.verdanturfTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.verdanturfTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.verdanturfTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void CallFallarborTentFunction(void)
{
    sFallarborTentFuncs[gSpecialVar_0x8004]();
}

// JP-only alias: the shared bx r0 tail (and literal pool) is labeled sub_081B9834.
__asm__(".set sub_081B9834, CallFallarborTentFunction + 0x14");

static void InitFallarborTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetFallarborTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.fallarborTentPrize;
}

static void SetFallarborTentPrize(void)
{
    gSaveBlock2Ptr->frontier.fallarborTentPrize = gSpecialVar_0x8006;
}

static void SaveFallarborTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    sub_081A482C();
}

static void SetRandomFallarborTentPrize(void)
{
    gSaveBlock2Ptr->frontier.fallarborTentPrize = sFallarborTentRewards[Random() % ARRAY_COUNT(sFallarborTentRewards)];
}

static void GiveFallarborTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.fallarborTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.fallarborTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.fallarborTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void BufferFallarborTentTrainerName(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void CallSlateportTentFunction(void)
{
    sSlateportTentFuncs[gSpecialVar_0x8004]();
}

// JP-only alias: the shared bx r0 tail (and literal pool) is labeled sub_081B99BC.
__asm__(".set sub_081B99BC, CallSlateportTentFunction + 0x14");

static void InitSlateportTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
}

static void GetSlateportTentPrize(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.slateportTentPrize;
}

static void SetSlateportTentPrize(void)
{
    gSaveBlock2Ptr->frontier.slateportTentPrize = gSpecialVar_0x8006;
}

static void SaveSlateportTentChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    sub_081A482C();
}

static void SetRandomSlateportTentPrize(void)
{
    gSaveBlock2Ptr->frontier.slateportTentPrize = sSlateportTentRewards[Random() % ARRAY_COUNT(sSlateportTentRewards)];
}

static void GiveSlateportTentPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.slateportTentPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.slateportTentPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.slateportTentPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void SelectInitialRentalMons(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void SwapRentalMons(void)
{
    DoBattleFactorySwapScreen();
}

bool8 InSlateportBattleTent(void)
{
    return gMapHeader.regionMapSectionId == MAPSEC_SLATEPORT_CITY
           && (gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_CORRIDOR || gMapHeader.mapLayoutId == LAYOUT_BATTLE_TENT_BATTLE_ROOM);
}

#ifndef NONMATCHING
// Verified: agbcc -O2 cannot reproduce the JP register allocation for this
// rental-mon selection loop, so the byte-exact naked asm stays the default.
__attribute__((naked)) void GenerateInitialRentalMons(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #0x3c\n\t"
            "ldr r1, _081B9C58\n\t"
            "ldr r0, _081B9C5C\n\t"
            "str r0, [r1]\n\t"
            "add r0, sp, #0xc\n\t"
            "mov sb, r0\n\t"
            "mov r1, sp\n\t"
            "adds r1, #0x18\n\t"
            "str r1, [sp, #0x2c]\n\t"
            "ldr r5, _081B9C60\n\t"
            "ldr r4, _081B9C64\n\t"
            "movs r2, #0\n\t"
            "adds r3, r1, #0\n\t"
            "mov r1, sb\n\t"
            "mov r0, sp\n\t"
            "movs r6, #5\n\t"
            "mov r8, r6\n\t"
            "_081B9B8C:\n\t"
            "strh r2, [r0]\n\t"
            "strh r2, [r1]\n\t"
            "strh r2, [r3]\n\t"
            "adds r3, #2\n\t"
            "adds r1, #2\n\t"
            "adds r0, #2\n\t"
            "movs r7, #1\n\t"
            "rsbs r7, r7, #0\n\t"
            "add r8, r7\n\t"
            "mov r6, r8\n\t"
            "cmp r6, #0\n\t"
            "bge _081B9B8C\n\t"
            "str r4, [r5]\n\t"
            "movs r7, #0\n\t"
            "mov sl, r7\n\t"
            "movs r0, #0\n\t"
            "mov r8, r0\n\t"
            "ldr r1, [sp, #0x2c]\n\t"
            "str r1, [sp, #0x30]\n\t"
            "mov r2, sp\n\t"
            "str r2, [sp, #0x34]\n\t"
            "lsls r6, r0, #1\n\t"
            "str r6, [sp, #0x24]\n\t"
            "add r6, sb\n\t"
            "str r6, [sp, #0x28]\n\t"
            "_081B9BBE:\n\t"
            "bl Random\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r0, r0, #0x10\n\t"
            "movs r1, #0x46\n\t"
            "bl __umodsi3\n\t"
            "lsls r0, r0, #0x10\n\t"
            "lsrs r5, r0, #0x10\n\t"
            "movs r2, #0\n\t"
            "mov r7, r8\n\t"
            "adds r6, r2, r7\n\t"
            "cmp r2, r6\n\t"
            "bge _081B9C1C\n\t"
            "ldr r1, [sp, #0x28]\n\t"
            "ldrh r0, [r1]\n\t"
            "cmp r0, r5\n\t"
            "beq _081B9C1C\n\t"
            "ldr r0, _081B9C60\n\t"
            "ldr r1, [r0]\n\t"
            "lsls r0, r5, #4\n\t"
            "adds r4, r0, r1\n\t"
            "ldrh r7, [r4]\n\t"
            "mov ip, r7\n\t"
            "lsls r3, r2, #1\n\t"
            "ldr r1, [sp, #0x24]\n\t"
            "add r1, sp\n\t"
            "str r6, [sp, #0x38]\n\t"
            "_081B9BF6:\n\t"
            "ldrh r0, [r1]\n\t"
            "cmp r0, ip\n\t"
            "bne _081B9C06\n\t"
            "mov r0, sl\n\t"
            "cmp r0, #0\n\t"
            "bne _081B9C1C\n\t"
            "ldrh r7, [r4]\n\t"
            "mov sl, r7\n\t"
            "_081B9C06:\n\t"
            "adds r3, #2\n\t"
            "adds r1, #2\n\t"
            "adds r2, #1\n\t"
            "ldr r0, [sp, #0x38]\n\t"
            "cmp r2, r0\n\t"
            "bge _081B9C1C\n\t"
            "mov r7, sb\n\t"
            "adds r0, r7, r3\n\t"
            "ldrh r0, [r0]\n\t"
            "cmp r0, r5\n\t"
            "bne _081B9BF6\n\t"
            "_081B9C1C:\n\t"
            "cmp r2, r6\n\t"
            "bne _081B9CBC\n\t"
            "movs r2, #0\n\t"
            "cmp r2, r6\n\t"
            "bge _081B9C74\n\t"
            "ldr r0, _081B9C68\n\t"
            "mov ip, r0\n\t"
            "ldr r7, _081B9C60\n\t"
            "ldr r1, [sp, #0x24]\n\t"
            "ldr r0, [sp, #0x2c]\n\t"
            "adds r4, r1, r0\n\t"
            "_081B9C32:\n\t"
            "ldrh r3, [r4]\n\t"
            "cmp r3, #0\n\t"
            "beq _081B9C6C\n\t"
            "ldr r1, [r7]\n\t"
            "lsls r0, r5, #4\n\t"
            "adds r1, r0, r1\n\t"
            "ldrb r0, [r1, #0xa]\n\t"
            "lsls r0, r0, #1\n\t"
            "add r0, ip\n\t"
            "ldrh r0, [r0]\n\t"
            "cmp r3, r0\n\t"
            "bne _081B9C6C\n\t"
            "ldrh r0, [r1]\n\t"
            "cmp r0, sl\n\t"
            "bne _081B9C74\n\t"
            "movs r1, #0\n\t"
            "mov sl, r1\n\t"
            "b _081B9C74\n\t"
            ".align 2, 0\n\t"
            "_081B9C58: .4byte gFacilityTrainers\n\t"
            "_081B9C5C: .4byte gSlateportBattleTentTrainers\n\t"
            "_081B9C60: .4byte gFacilityTrainerMons\n\t"
            "_081B9C64: .4byte gSlateportBattleTentMons\n\t"
            "_081B9C68: .4byte gBattleFrontierHeldItems\n\t"
            "_081B9C6C:\n\t"
            "adds r4, #2\n\t"
            "adds r2, #1\n\t"
            "cmp r2, r6\n\t"
            "blt _081B9C32\n\t"
            "_081B9C74:\n\t"
            "cmp r2, r6\n\t"
            "bne _081B9CBC\n\t"
            "ldr r0, _081B9CD4\n\t"
            "ldr r1, [r0]\n\t"
            "mov r2, r8\n\t"
            "lsls r3, r2, #1\n\t"
            "adds r0, r3, r2\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r1, r1, r0\n\t"
            "movs r6, #0xe7\n\t"
            "lsls r6, r6, #4\n\t"
            "adds r1, r1, r6\n\t"
            "strh r5, [r1]\n\t"
            "ldr r0, _081B9CD8\n\t"
            "ldr r0, [r0]\n\t"
            "lsls r1, r5, #4\n\t"
            "adds r1, r1, r0\n\t"
            "ldrh r0, [r1]\n\t"
            "ldr r7, [sp, #0x34]\n\t"
            "strh r0, [r7]\n\t"
            "ldr r2, _081B9CDC\n\t"
            "ldrb r0, [r1, #0xa]\n\t"
            "lsls r0, r0, #1\n\t"
            "adds r0, r0, r2\n\t"
            "ldrh r0, [r0]\n\t"
            "ldr r1, [sp, #0x30]\n\t"
            "strh r0, [r1]\n\t"
            "add r3, sb\n\t"
            "strh r5, [r3]\n\t"
            "adds r1, #2\n\t"
            "str r1, [sp, #0x30]\n\t"
            "adds r2, r7, #0\n\t"
            "adds r2, #2\n\t"
            "str r2, [sp, #0x34]\n\t"
            "movs r6, #1\n\t"
            "add r8, r6\n\t"
            "_081B9CBC:\n\t"
            "mov r7, r8\n\t"
            "cmp r7, #6\n\t"
            "beq _081B9CC4\n\t"
            "b _081B9BBE\n\t"
            "_081B9CC4:\n\t"
            "add sp, #0x3c\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_081B9CD4: .4byte gSaveBlock2Ptr\n\t"
            "_081B9CD8: .4byte gFacilityTrainerMons\n\t"
            "_081B9CDC: .4byte gBattleFrontierHeldItems\n\t"
            ".syntax divided");
}
#else
void GenerateInitialRentalMons(void)
{
    s32 i, j;
    u8 firstMonId;
    u16 monSetId;
    u16 currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    firstMonId = 0;
    gFacilityTrainers = gSlateportBattleTentTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    gFacilityTrainerMons = gSlateportBattleTentMons;
    currSpecies = SPECIES_NONE;
    i = 0;
    while (i != PARTY_SIZE)
    {
        // Cannot have two Pokemon of the same species.
        monSetId = Random() % NUM_SLATEPORT_TENT_MONS;
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            if (monIds[j] == monSetId)
                break;
            if (species[j] == gFacilityTrainerMons[monSetId].species)
            {
                if (currSpecies == SPECIES_NONE)
                    currSpecies = gFacilityTrainerMons[monSetId].species;
                else
                    break;
            }
        }
        if (j != i + firstMonId)
            continue;

        // Cannot have two same held items.
        for (j = firstMonId; j < i + firstMonId; j++)
        {
            if (heldItems[j] != 0 && heldItems[j] == gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId])
            {
                if (gFacilityTrainerMons[monSetId].species == currSpecies)
                    currSpecies = SPECIES_NONE;
                break;
            }
        }
        if (j != i + firstMonId)
            continue;

        gSaveBlock2Ptr->frontier.rentalMons[i].monId = monSetId;
        species[i] = gFacilityTrainerMons[monSetId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId];
        monIds[i] = monSetId;
        i++;
    }
}
#endif


static void GenerateOpponentMons(void)
{
    u16 trainerId;
    s32 i, j, k;
    const u16 *monSet;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    s32 numMons = 0;

    gFacilityTrainers = gSlateportBattleTentTrainers;
    gFacilityTrainerMons = gSlateportBattleTentMons;

    while (1)
    {
        do
        {
            // Choose a random trainer, ensuring no repeats in this challenge
            trainerId = Random() % NUM_BATTLE_TENT_TRAINERS;
            for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
            {
                if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                    break;
            }
        } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

        gTrainerBattleOpponent_A = trainerId;
        monSet = gFacilityTrainers[gTrainerBattleOpponent_A].monSet;
        while (monSet[numMons] != 0xFFFF)
            numMons++;
        if (numMons > 8)
            break;
        numMons = 0;
    }

    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < TENT_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = gTrainerBattleOpponent_A;

    monSet = gFacilityTrainers[gTrainerBattleOpponent_A].monSet;
    i = 0;
    while (i != FRONTIER_PARTY_SIZE)
    {
        sRandMonId = monSet[Random() % numMons];

        // Ensure none of the opponent's Pokémon are the same as the potential rental Pokémon for the player
        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (gFacilityTrainerMons[sRandMonId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
                break;
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        // Ensure this species hasn't already been chosen for the opponent
        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[sRandMonId].species)
                break;
        }
        if (k != i)
            continue;

        // Ensure held items don't repeat on the opponent's team
        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != ITEM_NONE && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[sRandMonId].itemTableId])
                break;
        }
        if (k != i)
            continue;

        // Successful selection
        species[i] = gFacilityTrainerMons[sRandMonId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[sRandMonId].itemTableId];
        gFrontierTempParty[i] = sRandMonId;
        i++;
    }
}
