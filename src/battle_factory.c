#include "global.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "event_data.h"
#include "pokemon.h"
#include "constants/battle_ai.h"
#include "constants/battle_frontier.h"
#include "constants/battle_frontier_mons.h"
#include "constants/battle_tent.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include <stddef.h>

#define BATTLE_FACTORY_DATA __attribute__((section(".rodata.battle_factory_data")))

extern const u8 gUnknown_85DD958[];
extern const u8 gUnknown_85DD7F8[];
extern const u8 gUnknown_85DD93C[];
extern const u8 gUnknown_85DD9BC[];
extern u16 gSpecialVar_0x8004;
extern u8 gUnknown_3001284;

// JP asm name for the still-asm frontier save helper; US: SaveGameFrontier.
void sub_081A482C(void);

u8 GetMoveBattleStyle(u16 move);
u16 sub_0816245C(u8 challengeNum, u8 battleNum);
u16 GetMonSetId(u8 lvlMode, u8 challengeNum, bool8 useBetterRange);
u8 GetNumPastRentalsRank(u8 battleMode, u8 lvlMode);
u8 GetFactoryMonFixedIV(u8 challengeNum, bool8 isLastBattle);
void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 moveArg, u8 moveSlot);

void CallBattleFactoryFunction(void)
{
    void (*const *funcs)(void) = (void (*const *)(void))gUnknown_85DD958;

    funcs[gSpecialVar_0x8004]();
}

__asm__(".global nullsub_75\n.set nullsub_75, CallBattleFactoryFunction + 0x14\n"
        ".size CallBattleFactoryFunction, 0x14\n.size nullsub_75, 0xc");

// Kept naked: equivalent C variants consistently reuse the 0xCA9 field offset
// as +0x33, shortening the active-streak branch by four bytes. The JP object
// reloads the save pointer and uses a separate 0xCDC literal-pool path.
__attribute__((naked)) void InitFactoryChallenge(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	ldr r5, _081A5D0C\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r4, _081A5D10\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r7, r0, #0x1e\n\t"
        "	ldr r0, _081A5D14\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _081A5D18\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r3, _081A5D1C\n\t"
        "	adds r0, r1, r3\n\t"
        "	strh r2, [r0]\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r0, #9\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r4, [r5]\n\t"
        "	ldr r0, _081A5D20\n\t"
        "	adds r3, r4, r0\n\t"
        "	ldr r2, _081A5D24\n\t"
        "	lsls r0, r7, #2\n\t"
        "	lsls r1, r6, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r3, [r3]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r3, r0\n\t"
        "	cmp r3, #0\n\t"
        "	bne _081A5CA2\n\t"
        "	lsls r1, r7, #1\n\t"
        "	lsls r0, r6, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, _081A5D28\n\t"
        "	adds r0, r4, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r3, [r0]\n\t"
        "	adds r2, #0x10\n\t"
        "	adds r0, r4, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r3, [r0]\n\t"
        "_081A5CA2:\n\t"
        "	ldr r1, _081A5D2C\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r2, #0\n\t"
        "	ldr r6, _081A5D30\n\t"
        "	movs r4, #0xe7\n\t"
        "	lsls r4, r4, #4\n\t"
        "	ldr r0, _081A5D34\n\t"
        "	adds r3, r0, #0\n\t"
        "_081A5CB4:\n\t"
        "	ldr r1, [r5]\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrh r0, [r1]\n\t"
        "	orrs r0, r3\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #5\n\t"
        "	bls _081A5CB4\n\t"
        "	movs r2, #0\n\t"
        "	ldr r4, _081A5D38\n\t"
        "	ldr r1, _081A5D34\n\t"
        "	adds r3, r1, #0\n\t"
        "_081A5CD8:\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r1, [r0]\n\t"
        "	orrs r1, r3\n\t"
        "	strh r1, [r0]\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #2\n\t"
        "	bls _081A5CD8\n\t"
        "	ldr r0, [r6]\n\t"
        "	movs r1, #4\n\t"
        "	ldrsb r1, [r0, r1]\n\t"
        "	movs r2, #5\n\t"
        "	ldrsb r2, [r0, r2]\n\t"
        "	movs r3, #1\n\t"
        "	rsbs r3, r3, #0\n\t"
        "	movs r0, #0\n\t"
        "	bl SetDynamicWarp\n\t"
        "	ldr r1, _081A5D3C\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081A5D0C: .4byte gSaveBlock2Ptr\n\t"
        "_081A5D10: .4byte 0x00000CA9\n\t"
        "_081A5D14: .4byte 0x000040CE\n\t"
        "_081A5D18: .4byte 0x00000CA8\n\t"
        "_081A5D1C: .4byte 0x00000CB2\n\t"
        "_081A5D20: .4byte 0x00000CDC\n\t"
        "_081A5D24: .4byte gUnknown_85DD99C\n\t"
        "_081A5D28: .4byte 0x00000DE2\n\t"
        "_081A5D2C: .4byte gUnknown_3001284\n\t"
        "_081A5D30: .4byte gSaveBlock1Ptr\n\t"
        "_081A5D34: .4byte 0x0000FFFF\n\t"
        "_081A5D38: .4byte gFrontierTempParty\n\t"
        "_081A5D3C: .4byte gTrainerBattleOpponent_A\n\t"
        ".syntax divided\n\t"
    );
}

// Kept naked: equivalent C preserves the selectors but allocates the live save
// pointer and modes to r6/r5/r4 and merges the flag-result store. The JP object
// requires r7/r6/r5 plus the distinct active-flag write path below.
__attribute__((naked)) void GetBattleFactoryData(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	ldr r7, _081A5D6C\n\t"
        "	ldr r0, [r7]\n\t"
        "	ldr r1, _081A5D70\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r6, r0, #0x1e\n\t"
        "	ldr r0, _081A5D74\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldr r0, _081A5D78\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _081A5D98\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _081A5D7C\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081A5D82\n\t"
        "	b _081A5DDC\n\t"
        "	.align 2, 0\n\t"
        "_081A5D6C: .4byte gSaveBlock2Ptr\n\t"
        "_081A5D70: .4byte 0x00000CA9\n\t"
        "_081A5D74: .4byte 0x000040CE\n\t"
        "_081A5D78: .4byte gSpecialVar_0x8005\n\t"
        "_081A5D7C:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _081A5DC8\n\t"
        "	b _081A5DDC\n\t"
        "_081A5D82:\n\t"
        "	ldr r3, _081A5D90\n\t"
        "	ldr r0, [r7]\n\t"
        "	lsls r1, r6, #1\n\t"
        "	lsls r2, r5, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _081A5D94\n\t"
        "	b _081A5DD4\n\t"
        "	.align 2, 0\n\t"
        "_081A5D90: .4byte gSpecialVar_Result\n\t"
        "_081A5D94: .4byte 0x00000DE2\n\t"
        "_081A5D98:\n\t"
        "	ldr r4, _081A5DBC\n\t"
        "	ldr r2, [r7]\n\t"
        "	ldr r0, _081A5DC0\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r3, _081A5DC4\n\t"
        "	lsls r0, r6, #2\n\t"
        "	lsls r1, r5, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldr r1, [r2]\n\t"
        "	ldr r0, [r0]\n\t"
        "	ands r1, r0\n\t"
        "	rsbs r0, r1, #0\n\t"
        "	orrs r0, r1\n\t"
        "	lsrs r0, r0, #0x1f\n\t"
        "	strh r0, [r4]\n\t"
        "	b _081A5DDC\n\t"
        "	.align 2, 0\n\t"
        "_081A5DBC: .4byte gSpecialVar_Result\n\t"
        "_081A5DC0: .4byte 0x00000CDC\n\t"
        "_081A5DC4: .4byte gUnknown_85DD99C\n\t"
        "_081A5DC8:\n\t"
        "	ldr r3, _081A5DE4\n\t"
        "	ldr r0, [r7]\n\t"
        "	lsls r1, r6, #1\n\t"
        "	lsls r2, r5, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r2, _081A5DE8\n\t"
        "_081A5DD4:\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r3]\n\t"
        "_081A5DDC:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081A5DE4: .4byte gSpecialVar_Result\n\t"
        "_081A5DE8: .4byte 0x00000DF2\n\t"
        ".syntax divided\n\t"
    );
}

// Kept naked: both the US-shaped C version and a u32/local-order variant
// allocate battleMode to r1 and shrink the saved-register set. The JP object
// requires the r6/r5/r4 layout across all three switch paths.
__attribute__((naked)) void SetBattleFactoryData(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r6, _081A5E18\n\t"
        "	ldr r0, [r6]\n\t"
        "	ldr r1, _081A5E1C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1e\n\t"
        "	lsrs r5, r0, #0x1e\n\t"
        "	ldr r0, _081A5E20\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	ldr r0, _081A5E24\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	beq _081A5E4C\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _081A5E28\n\t"
        "	cmp r0, #1\n\t"
        "	beq _081A5E2E\n\t"
        "	b _081A5EC0\n\t"
        "	.align 2, 0\n\t"
        "_081A5E18: .4byte gSaveBlock2Ptr\n\t"
        "_081A5E1C: .4byte 0x00000CA9\n\t"
        "_081A5E20: .4byte 0x000040CE\n\t"
        "_081A5E24: .4byte gSpecialVar_0x8005\n\t"
        "_081A5E28:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _081A5EA0\n\t"
        "	b _081A5EC0\n\t"
        "_081A5E2E:\n\t"
        "	ldr r2, [r6]\n\t"
        "	lsls r0, r5, #1\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081A5E44\n\t"
        "	adds r2, r2, r1\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r0, _081A5E48\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r2]\n\t"
        "	b _081A5EC0\n\t"
        "	.align 2, 0\n\t"
        "_081A5E44: .4byte 0x00000DE2\n\t"
        "_081A5E48: .4byte gSpecialVar_0x8006\n\t"
        "_081A5E4C:\n\t"
        "	ldr r0, _081A5E70\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081A5E7C\n\t"
        "	ldr r2, [r6]\n\t"
        "	ldr r0, _081A5E74\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r3, _081A5E78\n\t"
        "	lsls r1, r5, #2\n\t"
        "	lsls r0, r4, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r1, [r1]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "	b _081A5EC0\n\t"
        "	.align 2, 0\n\t"
        "_081A5E70: .4byte gSpecialVar_0x8006\n\t"
        "_081A5E74: .4byte 0x00000CDC\n\t"
        "_081A5E78: .4byte gUnknown_85DD99C\n\t"
        "_081A5E7C:\n\t"
        "	ldr r2, [r6]\n\t"
        "	ldr r1, _081A5E98\n\t"
        "	adds r2, r2, r1\n\t"
        "	ldr r3, _081A5E9C\n\t"
        "	lsls r1, r5, #2\n\t"
        "	lsls r0, r4, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r1, [r1]\n\t"
        "	ands r0, r1\n\t"
        "	str r0, [r2]\n\t"
        "	b _081A5EC0\n\t"
        "	.align 2, 0\n\t"
        "_081A5E98: .4byte 0x00000CDC\n\t"
        "_081A5E9C: .4byte gUnknown_85DD9AC\n\t"
        "_081A5EA0:\n\t"
        "	ldr r3, _081A5EC8\n\t"
        "	ldrb r0, [r3]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081A5EC0\n\t"
        "	ldr r2, [r6]\n\t"
        "	lsls r0, r5, #1\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _081A5ECC\n\t"
        "	adds r2, r2, r1\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r0, _081A5ED0\n\t"
        "	ldrh r0, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	strh r0, [r2]\n\t"
        "	strb r1, [r3]\n\t"
        "_081A5EC0:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081A5EC8: .4byte gUnknown_3001284\n\t"
        "_081A5ECC: .4byte 0x00000DF2\n\t"
        "_081A5ED0: .4byte gSpecialVar_0x8006\n\t"
        ".syntax divided\n\t"
    );
}

void sub_081A5ED4(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_CHALLENGE_STATUS, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    sub_081A482C();
}

void sub_081A5F18(void) {}
void nullsub_123(void) {}
void SelectInitialRentalMons(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

void sub_081A5F30(void)
{
    DoBattleFactorySwapScreen();
}

void SetPerformedRentalSwap(void)
{
    gUnknown_3001284 = TRUE;
}

void sub_081A5F48(void)
{
    int i;
    int j;
    int k;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    int firstMonId = 0;
    u16 trainerId = 0;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    u32 challengeNum = winStreak / FRONTIER_STAGES_PER_CHALLENGE;

    gFacilityTrainers = gBattleFrontierTrainers;
    do
    {
        trainerId = sub_0816245C(challengeNum, gSaveBlock2Ptr->frontier.curChallengeBattleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    gTrainerBattleOpponent_A = trainerId;
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < FRONTIER_STAGES_PER_CHALLENGE - 1)
        gSaveBlock2Ptr->frontier.trainerIds[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = trainerId;

    i = 0;
    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetMonSetId(lvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (gFacilityTrainerMons[monId].species
                == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[j].monId].species)
            {
                break;
            }
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        if (lvlMode == FRONTIER_LVL_50 && monId > FRONTIER_MONS_HIGH_TIER)
            continue;

        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monId].species)
                break;
        }
        if (k != firstMonId + i)
            continue;

        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (heldItems[k] != ITEM_NONE
                && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId])
            {
                break;
            }
        }
        if (k != firstMonId + i)
            continue;

        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId];
        gFrontierTempParty[i] = monId;
        i++;
    }
}

void SetOpponentGfxVar(void)
{
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

void SetRentalsToOpponentParty(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId = gFrontierTempParty[i];
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ATK_IV, NULL);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].personality = GetMonData3(&gEnemyParty[i], MON_DATA_PERSONALITY, NULL);
        gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].abilityNum = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ABILITY_NUM, NULL);
        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[gFrontierTempParty[i]].itemTableId]);
    }
}

void SetPlayerAndOpponentParties(void)
{
    int i;
    int j;
    int k;
    int count = 0;
    u8 bits = 0;
    u8 monLevel;
    u16 monId;
    u16 evs;
    u8 ivs;
    u8 friendship;

    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        gFacilityTrainerMons = gSlateportBattleTentMons;
        monLevel = TENT_MIN_LEVEL;
    }
    else
    {
        gFacilityTrainerMons = gBattleFrontierMons;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
            monLevel = FRONTIER_MAX_LEVEL_OPEN;
        else
            monLevel = FRONTIER_MAX_LEVEL_50;
    }

    if (gSpecialVar_0x8005 < 2)
    {
        ZeroPlayerPartyMons();
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i].ivs;
            CreateMon(&gPlayerParty[i],
                      gFacilityTrainerMons[monId].species,
                      monLevel,
                      ivs,
                      TRUE,
                      gSaveBlock2Ptr->frontier.rentalMons[i].personality,
                      OT_ID_PLAYER_ID,
                      0);

            count = 0;
            bits = gFacilityTrainerMons[monId].evSpread;
            for (j = 0; j < NUM_STATS; bits >>= 1, j++)
            {
                if (bits & 1)
                    count++;
            }

            evs = MAX_TOTAL_EVS / count;
            bits = 1;
            for (j = 0; j < NUM_STATS; bits <<= 1, j++)
            {
                if (gFacilityTrainerMons[monId].evSpread & bits)
                    SetMonData(&gPlayerParty[i], MON_DATA_HP_EV + j, &evs);
            }

            CalculateMonStats(&gPlayerParty[i]);
            friendship = 0;
            for (k = 0; k < MAX_MON_MOVES; k++)
                SetMonMoveAvoidReturn(&gPlayerParty[i], gFacilityTrainerMons[monId].moves[k], k);
            SetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP, &friendship);
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId]);
            SetMonData(&gPlayerParty[i], MON_DATA_ABILITY_NUM, &gSaveBlock2Ptr->frontier.rentalMons[i].abilityNum);
        }
    }

    switch (gSpecialVar_0x8005)
    {
    case 0:
    case 2:
        for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
        {
            monId = gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].monId;
            ivs = gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].ivs;
            CreateMon(&gEnemyParty[i],
                      gFacilityTrainerMons[monId].species,
                      monLevel,
                      ivs,
                      TRUE,
                      gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].personality,
                      OT_ID_PLAYER_ID,
                      0);

            count = 0;
            bits = gFacilityTrainerMons[monId].evSpread;
            for (j = 0; j < NUM_STATS; bits >>= 1, j++)
            {
                if (bits & 1)
                    count++;
            }

            evs = MAX_TOTAL_EVS / count;
            bits = 1;
            for (j = 0; j < NUM_STATS; bits <<= 1, j++)
            {
                if (gFacilityTrainerMons[monId].evSpread & bits)
                    SetMonData(&gEnemyParty[i], MON_DATA_HP_EV + j, &evs);
            }

            CalculateMonStats(&gEnemyParty[i]);
            for (k = 0; k < MAX_MON_MOVES; k++)
                SetMonMoveAvoidReturn(&gEnemyParty[i], gFacilityTrainerMons[monId].moves[k], k);
            SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId]);
            SetMonData(&gEnemyParty[i], MON_DATA_ABILITY_NUM, &gSaveBlock2Ptr->frontier.rentalMons[i + FRONTIER_PARTY_SIZE].abilityNum);
        }
        break;
    }
}

void sub_081A6584(void)
{
    int i;
    int j;
    u8 firstMonId;
    u8 battleMode;
    u8 lvlMode;
    u8 challengeNum;
    u8 factoryLvlMode;
    u8 factoryBattleMode;
    u8 rentalRank;
    u16 monId;
    u16 currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    gFacilityTrainers = gBattleFrontierTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = SPECIES_NONE;
        monIds[i] = 0;
        heldItems[i] = ITEM_NONE;
    }

    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode]
        / FRONTIER_STAGES_PER_CHALLENGE;
    if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        factoryBattleMode = FRONTIER_MODE_DOUBLES;
    else
        factoryBattleMode = FRONTIER_MODE_SINGLES;

    gFacilityTrainerMons = gBattleFrontierMons;
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
    {
        factoryLvlMode = FRONTIER_LVL_OPEN;
        firstMonId = 0;
    }
    else
    {
        factoryLvlMode = FRONTIER_LVL_50;
        firstMonId = 0;
    }

    rentalRank = GetNumPastRentalsRank(factoryBattleMode, factoryLvlMode);
    currSpecies = SPECIES_NONE;
    i = 0;
    while (i != PARTY_SIZE)
    {
        if (i < rentalRank)
            monId = GetMonSetId(factoryLvlMode, challengeNum, TRUE);
        else
            monId = GetMonSetId(factoryLvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;

        for (j = firstMonId; j < firstMonId + i; j++)
        {
            u16 existingMonId = monIds[j];

            if (existingMonId == monId)
                break;
            if (species[j] == gFacilityTrainerMons[monId].species)
            {
                if (currSpecies == SPECIES_NONE)
                    currSpecies = gFacilityTrainerMons[monId].species;
                else
                    break;
            }
        }
        if (j != firstMonId + i)
            continue;

        for (j = firstMonId; j < firstMonId + i; j++)
        {
            if (heldItems[j] != ITEM_NONE
                && heldItems[j] == gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId])
            {
                if (gFacilityTrainerMons[monId].species == currSpecies)
                    currSpecies = SPECIES_NONE;
                break;
            }
        }
        if (j != firstMonId + i)
            continue;

        gSaveBlock2Ptr->frontier.rentalMons[i].monId = monId;
        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId];
        monIds[i] = monId;
        i++;
    }
}

void GetOpponentMostCommonMonType(void)
{
    u8 i;
    u8 typeCounts[NUMBER_OF_MON_TYPES];
    u8 mostCommonTypes[2];

    gFacilityTrainerMons = gBattleFrontierMons;

    for (i = TYPE_NORMAL; i < NUMBER_OF_MON_TYPES; i++)
        typeCounts[i] = 0;
    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u32 species = gFacilityTrainerMons[gFrontierTempParty[i]].species;

        typeCounts[gSpeciesInfo[species].types[0]]++;
        if (gSpeciesInfo[species].types[0] != gSpeciesInfo[species].types[1])
            typeCounts[gSpeciesInfo[species].types[1]]++;
    }

    mostCommonTypes[0] = 0;
    mostCommonTypes[1] = 0;
    for (i = 1; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (typeCounts[mostCommonTypes[0]] < typeCounts[i])
            mostCommonTypes[0] = i;
        else if (typeCounts[mostCommonTypes[0]] == typeCounts[i])
            mostCommonTypes[1] = i;
    }

    if (typeCounts[mostCommonTypes[0]] != 0)
    {
        if (typeCounts[mostCommonTypes[0]] > typeCounts[mostCommonTypes[1]])
            gSpecialVar_Result = mostCommonTypes[0];
        else if (mostCommonTypes[0] == mostCommonTypes[1])
            gSpecialVar_Result = mostCommonTypes[0];
        else
            gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
    else
    {
        gSpecialVar_Result = NUMBER_OF_MON_TYPES;
    }
}

void GetOpponentBattleStyle(void)
{
    u8 i;
    u8 j;
    u8 count;
    u8 stylePoints[8];

    count = 0;
    gFacilityTrainerMons = gBattleFrontierMons;
    for (i = 0; i < 8; i++)
        stylePoints[i] = 0;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        u16 monId = gFrontierTempParty[i];

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            u8 battleStyle = GetMoveBattleStyle(gFacilityTrainerMons[monId].moves[j]);

            stylePoints[battleStyle]++;
        }
    }

    gSpecialVar_Result = 0;
    for (i = 1; i < 8; i++)
    {
        if (stylePoints[i] >= gUnknown_85DD7F8[i - 1])
        {
            gSpecialVar_Result = i;
            count++;
        }
    }

    if (count > 2)
        gSpecialVar_Result = 8;
}

u8 GetMoveBattleStyle(u16 move)
{
    const u16 *moves;
    u8 i;
    u8 j;

    for (i = 0; i < 7; i++)
    {
        for (j = 0, moves = ((const u16 *const *)gUnknown_85DD93C)[i]; moves[j] != MOVE_NONE; j++)
        {
            if (moves[j] == move)
                return i + 1;
        }
    }

    return 0;
}

bool8 InBattleFactory(void)
{
    return gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM
        || gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_FACTORY_BATTLE_ROOM;
}

void RestorePlayerPartyHeldItems(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < FRONTIER_PARTY_SIZE; i++)
    {
        SetMonData(&gPlayerParty[i],
                   MON_DATA_HELD_ITEM,
                   &gBattleFrontierHeldItems[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.rentalMons[i].monId].itemTableId]);
    }
}

u8 GetFactoryMonFixedIV(u8 challengeNum, bool8 isLastBattle)
{
    u8 ivSet;
    bool8 useHigherIV = isLastBattle ? TRUE : FALSE;

    if (challengeNum > 8)
        ivSet = 7;
    else
        ivSet = challengeNum;

    return gUnknown_85DD9BC[useHigherIV + ivSet * 2];
}

void FillFactoryBrainParty(void)
{
    int i;
    int j;
    int k;
    u16 species[FRONTIER_PARTY_SIZE];
    u16 heldItems[FRONTIER_PARTY_SIZE];
    u8 friendship;
    int monLevel;
    u8 fixedIV;
    u32 otId;

    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode]
        / FRONTIER_STAGES_PER_CHALLENGE;

    fixedIV = GetFactoryMonFixedIV(challengeNum + 2, FALSE);
    monLevel = SetFacilityPtrsGetLevel();
    i = 0;
    otId = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    while (i != FRONTIER_PARTY_SIZE)
    {
        u16 monId = GetMonSetId(lvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monId].species == SPECIES_UNOWN)
            continue;
        if (monLevel == FRONTIER_MAX_LEVEL_50 && monId > FRONTIER_MONS_HIGH_TIER)
            continue;

        for (j = 0; j < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons); j++)
        {
            if (monId == gSaveBlock2Ptr->frontier.rentalMons[j].monId)
                break;
        }
        if (j != (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.rentalMons))
            continue;

        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monId].species)
                break;
        }
        if (k != i)
            continue;

        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != ITEM_NONE
                && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId])
            {
                break;
            }
        }
        if (k != i)
            continue;

        species[i] = gFacilityTrainerMons[monId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId];
        CreateMonWithEVSpreadNatureOTID(&gEnemyParty[i],
                                        gFacilityTrainerMons[monId].species,
                                        monLevel,
                                        gFacilityTrainerMons[monId].nature,
                                        fixedIV,
                                        gFacilityTrainerMons[monId].evSpread,
                                        otId);

        friendship = 0;
        for (k = 0; k < MAX_MON_MOVES; k++)
            SetMonMoveAvoidReturn(&gEnemyParty[i], gFacilityTrainerMons[monId].moves[k], k);
        SetMonData(&gEnemyParty[i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monId].itemTableId]);
        i++;
    }
}

// Kept naked: the JP range selector's three literal-pool paths require its original
// r1/r2/r4 register allocation; equivalent C does not preserve its byte layout.
__attribute__((naked)) u16 GetMonSetId(u8 lvlMode, u8 challengeNum, bool8 useBetterRange)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r3, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	movs r4, #8\n\t"
        "	rsbs r1, r0, #0\n\t"
        "	orrs r1, r0\n\t"
        "	asrs r1, r1, #0x1f\n\t"
        "	ands r1, r4\n\t"
        "	adds r4, r1, #0\n\t"
        "	cmp r3, #6\n\t"
        "	bhi _081A6CC4\n\t"
        "	cmp r2, #0\n\t"
        "	beq _081A6CB8\n\t"
        "	ldr r2, _081A6CB4\n\t"
        "	adds r1, r1, r3\n\t"
        "	adds r1, #1\n\t"
        "	b _081A6CD0\n\t"
        "	.align 2, 0\n\t"
        "_081A6CB4: .4byte gUnknown_85DD9CC\n\t"
        "_081A6CB8:\n\t"
        "	ldr r2, _081A6CC0\n\t"
        "	adds r1, r1, r3\n\t"
        "	b _081A6CD0\n\t"
        "	.align 2, 0\n\t"
        "_081A6CC0: .4byte gUnknown_85DD9CC\n\t"
        "_081A6CC4:\n\t"
        "	adds r1, r3, #0\n\t"
        "	cmp r1, #7\n\t"
        "	beq _081A6CCC\n\t"
        "	movs r1, #7\n\t"
        "_081A6CCC:\n\t"
        "	ldr r2, _081A6D04\n\t"
        "	adds r1, r4, r1\n\t"
        "_081A6CD0:\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r0, r2, #2\n\t"
        "	adds r0, r1, r0\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrh r0, [r0]\n\t"
        "	ldrh r4, [r1]\n\t"
        "	subs r0, r0, r4\n\t"
        "	adds r0, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl __umodsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	adds r4, r0, r4\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r0, r4, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_081A6D04: .4byte gUnknown_85DD9CC\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetNumPastRentalsRank(u8 battleMode, u8 lvlMode)
{
    u8 ret;
    u8 *saveBlock2;
    u16 index;
    u8 rents;

    saveBlock2 = (u8 *)gSaveBlock2Ptr;
    index = lvlMode * 2;
    index += battleMode * 4;
    saveBlock2 += offsetof(struct SaveBlock2, frontier.factoryRentsCount);
    rents = saveBlock2[index];

    if (rents < 15)
        ret = 0;
    else if (rents < 22)
        ret = 1;
    else if (rents < 29)
        ret = 2;
    else if (rents < 36)
        ret = 3;
    else if (rents < 43)
        ret = 4;
    else
        ret = 5;

    return ret;
}

u32 GetAiScriptsInBattleFactory(void)
{
    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (lvlMode == FRONTIER_LVL_TENT)
    {
        return 0;
    }
    else
    {
        u16 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        int challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / FRONTIER_STAGES_PER_CHALLENGE;

        if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
            return AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY;
        else if (challengeNum < 2)
            return 0;
        else if (challengeNum < 4)
            return AI_SCRIPT_CHECK_BAD_MOVE;
        else
            return AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY;
    }
}

void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 moveArg, u8 moveSlot)
{
    u16 move = moveArg;

    if (moveArg == MOVE_RETURN)
        move = MOVE_FRUSTRATION;
    SetMonMoveSlot(mon, move, moveSlot);
}



BATTLE_FACTORY_DATA const u8 gUnknown_85DD7F8[] = {
    0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x00, 0x0E, 0x00, 0x4A, 0x00, 0x60, 0x00, 0x61, 0x00,
    0x68, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x6E, 0x00, 0x6F, 0x00, 0x70, 0x00, 0x74, 0x00, 0x85, 0x00,
    0x97, 0x00, 0x9F, 0x00, 0xA0, 0x00, 0xB0, 0x00, 0xBB, 0x00, 0xF4, 0x00, 0x0C, 0x01, 0x21, 0x01,
    0x26, 0x01, 0x42, 0x01, 0x4E, 0x01, 0x50, 0x01, 0x53, 0x01, 0x5B, 0x01, 0x5D, 0x01, 0x00, 0x00,
    0x66, 0x00, 0x76, 0x00, 0x77, 0x00, 0x90, 0x00, 0xA4, 0x00, 0xA6, 0x00, 0xAE, 0x00, 0xD9, 0x00,
    0x0A, 0x01, 0x0F, 0x01, 0x10, 0x01, 0x12, 0x01, 0x1D, 0x01, 0x25, 0x01, 0x00, 0x00, 0x1C, 0x00,
    0x27, 0x00, 0x2B, 0x00, 0x2D, 0x00, 0x51, 0x00, 0x67, 0x00, 0x6C, 0x00, 0x86, 0x00, 0x94, 0x00,
    0xB2, 0x00, 0xB4, 0x00, 0xB8, 0x00, 0xCC, 0x00, 0x1A, 0x01, 0xE6, 0x00, 0x29, 0x01, 0x39, 0x01,
    0x3F, 0x01, 0x41, 0x01, 0x00, 0x00, 0x0C, 0x00, 0x20, 0x00, 0x26, 0x00, 0x3F, 0x00, 0x44, 0x00,
    0x5A, 0x00, 0x75, 0x00, 0x78, 0x00, 0x8F, 0x00, 0x99, 0x00, 0xAF, 0x00, 0xB3, 0x00, 0xC2, 0x00,
    0xC3, 0x00, 0xDC, 0x00, 0xF3, 0x00, 0x06, 0x01, 0x20, 0x01, 0x07, 0x01, 0x08, 0x01, 0x33, 0x01,
    0x34, 0x01, 0x3B, 0x01, 0x52, 0x01, 0x62, 0x01, 0x58, 0x01, 0x00, 0x00, 0x36, 0x00, 0x69, 0x00,
    0x71, 0x00, 0x72, 0x00, 0x73, 0x00, 0x87, 0x00, 0x9C, 0x00, 0xB6, 0x00, 0xC5, 0x00, 0xCB, 0x00,
    0xD0, 0x00, 0xD7, 0x00, 0xDB, 0x00, 0xE2, 0x00, 0xEA, 0x00, 0xEB, 0x00, 0xEC, 0x00, 0x00, 0x01,
    0x11, 0x01, 0x13, 0x01, 0x15, 0x01, 0x16, 0x01, 0x1F, 0x01, 0x2C, 0x01, 0x2F, 0x01, 0x38, 0x01,
    0x5A, 0x01, 0x00, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x32, 0x00, 0x49, 0x00, 0x4D, 0x00, 0x4E, 0x00,
    0x4F, 0x00, 0x56, 0x00, 0x5C, 0x00, 0x5F, 0x00, 0x6D, 0x00, 0x89, 0x00, 0x8B, 0x00, 0x8E, 0x00,
    0x93, 0x00, 0xA9, 0x00, 0xBA, 0x00, 0xBF, 0x00, 0xCF, 0x00, 0xD4, 0x00, 0xD5, 0x00, 0xE3, 0x00,
    0x03, 0x01, 0x04, 0x01, 0x05, 0x01, 0x0D, 0x01, 0x19, 0x01, 0x1E, 0x01, 0x21, 0x01, 0x2A, 0x01,
    0x40, 0x01, 0x4F, 0x01, 0x00, 0x00, 0xC9, 0x00, 0xF0, 0x00, 0xF1, 0x00, 0x02, 0x01, 0x37, 0x01,
    0x00, 0x00, 0x00, 0x00,
};
BATTLE_FACTORY_DATA const u8 gUnknown_85DD93C[] = {
    0x00, 0xD8, 0x5D, 0x08, 0xEC, 0xD8, 0x5D, 0x08, 0xB4, 0xD8, 0x5D, 0x08, 0x7E, 0xD8, 0x5D, 0x08,
    0x56, 0xD8, 0x5D, 0x08, 0x38, 0xD8, 0x5D, 0x08, 0x2E, 0xD9, 0x5D, 0x08,
};
BATTLE_FACTORY_DATA const u8 gUnknown_85DD958[] = {
    0x2D, 0x5C, 0x1A, 0x08, 0x41, 0x5D, 0x1A, 0x08, 0xED, 0x5D, 0x1A, 0x08, 0xD5, 0x5E, 0x1A, 0x08,
    0x19, 0x5F, 0x1A, 0x08, 0x1D, 0x5F, 0x1A, 0x08, 0x21, 0x5F, 0x1A, 0x08, 0x31, 0x5F, 0x1A, 0x08,
    0x3D, 0x5F, 0x1A, 0x08, 0x65, 0x61, 0x1A, 0x08, 0x5D, 0x62, 0x1A, 0x08, 0x51, 0x61, 0x1A, 0x08,
    0x49, 0x5F, 0x1A, 0x08, 0x85, 0x65, 0x1A, 0x08, 0xA1, 0x67, 0x1A, 0x08, 0x85, 0x68, 0x1A, 0x08,
    0xB5, 0x69, 0x1A, 0x08,
};
BATTLE_FACTORY_DATA const u8 gUnknown_85DD99C[] = {
    0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02,
};
BATTLE_FACTORY_DATA const u8 gUnknown_85DD9AC[] = {
    0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFD,
};
BATTLE_FACTORY_DATA const u8 gUnknown_85DD9BC[] = {
    0x03, 0x06, 0x06, 0x09, 0x09, 0x0C, 0x0C, 0x0F, 0x0F, 0x12, 0x15, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
};
BATTLE_FACTORY_DATA const u8 gUnknown_85DD9CC[] = {
    0x6E, 0x00, 0xC7, 0x00, 0xA2, 0x00, 0x0A, 0x01, 0x0B, 0x01, 0x73, 0x01, 0x74, 0x01, 0xD3, 0x01,
    0xD4, 0x01, 0x33, 0x02, 0x34, 0x02, 0x93, 0x02, 0x94, 0x02, 0xF3, 0x02, 0x74, 0x01, 0x51, 0x03,
    0x74, 0x01, 0xD3, 0x01, 0xD4, 0x01, 0x33, 0x02, 0x34, 0x02, 0x93, 0x02, 0x94, 0x02, 0xF3, 0x02,
    0x74, 0x01, 0x71, 0x03, 0x74, 0x01, 0x71, 0x03, 0x74, 0x01, 0x71, 0x03, 0x74, 0x01, 0x71, 0x03,
    0x7B, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x89, 0x00, 0x22, 0x00, 0xBC, 0x00, 0x49, 0x01, 0x04, 0x00,
    0x5C, 0x00, 0x5F, 0x00, 0x22, 0x00, 0x39, 0x00, 0x6A, 0x01, 0x05, 0x00, 0x05, 0x01, 0xD4, 0x00,
    0x5C, 0x00, 0x45, 0x01, 0x7B, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x89, 0x00, 0x22, 0x00, 0xBC, 0x00,
    0x49, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x5F, 0x00, 0x22, 0x00, 0x39, 0x00, 0x65, 0x00, 0x05, 0x00,
    0x99, 0x00, 0x78, 0x00, 0x57, 0x00, 0x5C, 0x00, 0x7B, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x89, 0x00,
    0x22, 0x00, 0xBC, 0x00, 0x49, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x5F, 0x00, 0x22, 0x00, 0x39, 0x00,
    0x33, 0x01, 0x05, 0x00, 0x93, 0x00, 0x4E, 0x00, 0x4D, 0x00, 0xED, 0x00, 0x7B, 0x01, 0x04, 0x00,
    0x5C, 0x00, 0x89, 0x00, 0x22, 0x00, 0xBC, 0x00, 0x49, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x5F, 0x00,
    0x22, 0x00, 0x39, 0x00, 0xCA, 0x00, 0x05, 0x00, 0x44, 0x00, 0xF3, 0x00, 0xDB, 0x00, 0xC2, 0x00,
    0x0C, 0xDA, 0x5D, 0x08, 0x30, 0xDA, 0x5D, 0x08, 0x54, 0xDA, 0x5D, 0x08, 0x78, 0xDA, 0x5D, 0x08,
    0x7B, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x89, 0x00, 0x31, 0x01, 0xBC, 0x00, 0x49, 0x01, 0x04, 0x00,
    0x5C, 0x00, 0x5F, 0x00, 0x22, 0x00, 0x3A, 0x00, 0x6A, 0x01, 0x05, 0x00, 0x05, 0x01, 0xD4, 0x00,
    0x5C, 0x00, 0x3A, 0x00, 0x7B, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x89, 0x00, 0x31, 0x01, 0xBC, 0x00,
    0x49, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x5F, 0x00, 0x22, 0x00, 0x3A, 0x00, 0x65, 0x00, 0x05, 0x00,
    0x99, 0x00, 0x78, 0x00, 0x57, 0x00, 0x5C, 0x00, 0x7B, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x89, 0x00,
    0x31, 0x01, 0xBC, 0x00, 0x49, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x5F, 0x00, 0x22, 0x00, 0x3A, 0x00,
    0x33, 0x01, 0x05, 0x00, 0x93, 0x00, 0x4E, 0x00, 0x4D, 0x00, 0xED, 0x00, 0x7B, 0x01, 0x04, 0x00,
    0x5C, 0x00, 0x89, 0x00, 0x31, 0x01, 0xBC, 0x00, 0x49, 0x01, 0x04, 0x00, 0x5C, 0x00, 0x5F, 0x00,
    0x22, 0x00, 0x3A, 0x00, 0xCA, 0x00, 0x05, 0x00, 0x44, 0x00, 0xF3, 0x00, 0xDB, 0x00, 0xE3, 0x00,
    0xAC, 0xDA, 0x5D, 0x08, 0xD0, 0xDA, 0x5D, 0x08, 0xF4, 0xDA, 0x5D, 0x08, 0x18, 0xDB, 0x5D, 0x08,
};
