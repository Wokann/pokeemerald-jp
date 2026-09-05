#include "global.h"
#include "battle.h"
#include "berry.h"
#include "contest.h"
#include "event_data.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "overworld.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "constants/battle_frontier.h"
#include "constants/items.h"
#include "script_pokemon_util.h"

void sub_080F9918(u8 taskId);
void CB2_ReturnFromChooseHalfParty(void);
void sub_080F9D48(void);

void GetContestMultiplayerId(void)
{
    if ((gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        && gNumLinkContestPlayers == CONTESTANT_COUNT
        && !(gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS))
        gSpecialVar_Result = GetMultiplayerId();
    else
        gSpecialVar_Result = MAX_LINK_PLAYERS;
}

void GenerateContestRand(void)
{
    u16 random;
    u16 *result;

    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        gContestRngValue = ISO_RANDOMIZE1(gContestRngValue);
        random = gContestRngValue >> 16;
        result = &gSpecialVar_Result;
    }
    else
    {
        result = &gSpecialVar_Result;
        random = Random();
    }
    *result = random % *result;
}

// JP symbol; equivalent to GetContestRand.
u16 sub_080F98CC(void)
{
    gContestRngValue = ISO_RANDOMIZE1(gContestRngValue);
    return gContestRngValue >> 16;
}

bool8 LinkContestWaitForConnection(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        CreateTask(sub_080F9918, 5);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// JP symbol; equivalent to Task_LinkContestWaitForConnection.
void sub_080F9918(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            SetLinkStandbyCallback();
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        gTasks[taskId].data[0]++;
        break;
    default:
        if (IsLinkTaskFinished() == 1)
        {
            ScriptContext_Enable();
            DestroyTask(taskId);
        }
        break;
    }
}

void LinkContestTryShowWirelessIndicator(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        if (gReceivedRemoteLinkPlayers)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(8, 8);
        }
    }
}

void LinkContestTryHideWirelessIndicator(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        if (gReceivedRemoteLinkPlayers)
            DestroyWirelessStatusIndicatorSprite();
    }
}

bool8 IsContestWithRSPlayer(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER)
        return TRUE;
    else
        return FALSE;
}

void ClearLinkContestFlags(void)
{
    gLinkContestFlags = 0;
}

bool8 IsWirelessContest(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
        return TRUE;
    else
        return FALSE;
}

void HealPlayerParty(void)
{
    u8 i;
    u8 j;
    u8 ppBonuses;
    u8 arg[4];

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        u16 maxHP = GetMonData3(&gPlayerParty[i], MON_DATA_MAX_HP);
        arg[0] = maxHP;
        arg[1] = maxHP >> 8;
        SetMonData(&gPlayerParty[i], MON_DATA_HP, arg);
        ppBonuses = GetMonData3(&gPlayerParty[i], MON_DATA_PP_BONUSES);

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            arg[0] = CalculatePPWithBonus(GetMonData3(&gPlayerParty[i], MON_DATA_MOVE1 + j), ppBonuses, j);
            SetMonData(&gPlayerParty[i], MON_DATA_PP1 + j, arg);
        }

        arg[0] = 0;
        arg[1] = 0;
        arg[2] = 0;
        arg[3] = 0;
        SetMonData(&gPlayerParty[i], MON_DATA_STATUS, arg);
    }
}

u8 ScriptGiveMon(u16 species, u8 level, u16 item, u32 unused1, u32 unused2, u8 unused3)
{
    u16 nationalDexNum;
    int sentToPc;
    u8 heldItem[2];
    struct Pokemon mon;

    CreateMon(&mon, species, level, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    heldItem[0] = item;
    heldItem[1] = item >> 8;
    SetMonData(&mon, MON_DATA_HELD_ITEM, heldItem);
    sentToPc = GiveMonToPlayer(&mon);
    nationalDexNum = HoennToNationalOrder(species);

    switch (sentToPc)
    {
    case MON_GIVEN_TO_PARTY:
    case MON_GIVEN_TO_PC:
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
        GetSetPokedexFlag(nationalDexNum, FLAG_SET_CAUGHT);
        break;
    }
    return sentToPc;
}

u8 ScriptGiveEgg(u16 species)
{
    struct Pokemon mon;
    u8 isEgg;

    CreateEgg(&mon, species, TRUE);
    isEgg = TRUE;
    SetMonData(&mon, MON_DATA_IS_EGG, &isEgg);

    return GiveMonToPlayer(&mon);
}

void HasEnoughMonsForDoubleBattle(void)
{
    switch (GetMonsStateToDoubles())
    {
    case PLAYER_HAS_TWO_USABLE_MONS:
        gSpecialVar_Result = PLAYER_HAS_TWO_USABLE_MONS;
        break;
    case PLAYER_HAS_ONE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_MON;
        break;
    case PLAYER_HAS_ONE_USABLE_MON:
        gSpecialVar_Result = PLAYER_HAS_ONE_USABLE_MON;
        break;
    }
}

bool8 CheckPartyMonHasHeldItem(u16 item)
{
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData3(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if (species != SPECIES_NONE && species != SPECIES_EGG && GetMonData3(&gPlayerParty[i], MON_DATA_HELD_ITEM) == item)
            return TRUE;
    }
    return FALSE;
}

bool8 DoesPartyHaveEnigmaBerry(void)
{
    bool8 hasItem = CheckPartyMonHasHeldItem(ITEM_ENIGMA_BERRY);

    if (hasItem == TRUE)
        GetBerryNameByBerryType(ItemIdToBerryType(ITEM_ENIGMA_BERRY), gStringVar1);

    return hasItem;
}

void CreateScriptedWildMon(u16 species, u8 level, u16 item)
{
    u8 heldItem[2];

    ZeroEnemyPartyMons();
    CreateMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, 0, 0, OT_ID_PLAYER_ID, 0);
    if (item)
    {
        heldItem[0] = item;
        heldItem[1] = item >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

void ScriptSetMonMoveSlot(u8 monIndex, u16 move, u8 slot)
{
    if (monIndex > PARTY_SIZE)
        monIndex = gPlayerPartyCount - 1;

    SetMonMoveSlot(&gPlayerParty[monIndex], move, slot);
}

void ChooseHalfPartyForBattle(void)
{
    gMain.savedCallback = CB2_ReturnFromChooseHalfParty;
    VarSet(VAR_FRONTIER_FACILITY, FACILITY_MULTI_OR_EREADER);
    InitChooseHalfPartyForBattle(0);
}

void CB2_ReturnFromChooseHalfParty(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ChoosePartyForBattleFrontier(void)
{
    gMain.savedCallback = sub_080F9D48;
    InitChooseHalfPartyForBattle(gSpecialVar_0x8004 + 1);
}

// JP symbol; equivalent to CB2_ReturnFromChooseBattleFrontierParty.
void sub_080F9D48(void)
{
    switch (gSelectedOrderFromParty[0])
    {
    case 0:
        gSpecialVar_Result = FALSE;
        break;
    default:
        gSpecialVar_Result = TRUE;
        break;
    }

    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ReducePlayerPartyToSelectedMons(void)
{
    struct Pokemon party[MAX_FRONTIER_PARTY_SIZE];
    int i;

    CpuFill32(0, party, sizeof party);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        if (gSelectedOrderFromParty[i])
            party[i] = gPlayerParty[gSelectedOrderFromParty[i] - 1];

    CpuFill32(0, gPlayerParty, sizeof gPlayerParty);

    for (i = 0; i < MAX_FRONTIER_PARTY_SIZE; i++)
        gPlayerParty[i] = party[i];

    CalculatePlayerPartyCount();
}
