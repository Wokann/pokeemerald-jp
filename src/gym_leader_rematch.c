#include "global.h"
#include "random.h"
#include "event_data.h"
#include "battle_setup.h"
#include "gym_leader_rematch.h"

static void UpdateGymLeaderRematchFromArray(const u16 *data, size_t size, u32 maxRematch);
static s32 GetRematchIndex(u32 trainerIdx);

extern const u16 GymLeaderRematches_AfterNewMauville[];   // ROM @ 0x085FC01C
extern const u16 GymLeaderRematches_BeforeNewMauville[];  // ROM @ 0x085FC02C

void UpdateGymLeaderRematch(void)
{
    if (FlagGet(FLAG_SYS_GAME_CLEAR) && (Random() % 100) <= 30)
    {
        if (FlagGet(FLAG_WATTSON_REMATCH_AVAILABLE))
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_AfterNewMauville, 8, 5);
        else
            UpdateGymLeaderRematchFromArray(GymLeaderRematches_BeforeNewMauville, 7, 1);
    }
}

static void UpdateGymLeaderRematchFromArray(const u16 *data, size_t size, u32 maxRematch)
{
    s32 whichLeader = 0;
    s32 lowestRematchIndex = 5;
    u32 i;
    s32 rematchIndex;
    for (i = 0; i < size; i++)
    {
        if (!gSaveBlock1Ptr->trainerRematches[data[i]])
        {
            rematchIndex = GetRematchIndex(data[i]);
            if (lowestRematchIndex > rematchIndex)
                lowestRematchIndex = rematchIndex;
            whichLeader++;
        }
    }
    if (whichLeader != 0 && lowestRematchIndex <= maxRematch)
    {
        whichLeader = 0;
        for (i = 0; i < size; i++)
        {
            if (!gSaveBlock1Ptr->trainerRematches[data[i]])
            {
                rematchIndex = GetRematchIndex(data[i]);
                if (rematchIndex == lowestRematchIndex)
                    whichLeader++;
            }
        }
        if (whichLeader != 0)
        {
            whichLeader = Random() % whichLeader;
            for (i = 0; i < size; i++)
            {
                if (!gSaveBlock1Ptr->trainerRematches[data[i]])
                {
                    rematchIndex = GetRematchIndex(data[i]);
                    if (rematchIndex == lowestRematchIndex)
                    {
                        if (whichLeader == 0)
                        {
                            gSaveBlock1Ptr->trainerRematches[data[i]] = lowestRematchIndex;
                            break;
                        }
                        whichLeader--;
                    }
                }
            }
        }
    }
}

static s32 GetRematchIndex(u32 trainerIdx)
{
    s32 i;
    for (i = 0; i < 5; i++)
    {
        if (!HasTrainerBeenFought(gRematchTable[trainerIdx].trainerIds[i]))
        {
            return i;
        }
    }
    return 5;
}
