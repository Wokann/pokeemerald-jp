#include "global.h"
#include "contest.h"
#include "contest_link.h"
#include "event_data.h"
#include "task.h"

static void Task_LinkContest_CommunicateMonsEm(u8 taskId);
static void Task_LinkContest_StartCommunicateRngEm(u8 taskId);
static void Task_LinkContest_CommunicateRngEm(u8 taskId);
static void Task_LinkContest_StartCommunicateLeaderIdsEm(u8 taskId);

#define tCategory data[9]

void Task_LinkContest_StartCommunicationEm(u8 taskId)
{
    int gameCleared;
    u8 *data;

    switch (gTasks[taskId].tCategory)
    {
    case CONTEST_CATEGORY_COOL:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_COOL_RIBBON, data);
        break;
    case CONTEST_CATEGORY_BEAUTY:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_BEAUTY_RIBBON, data);
        break;
    case CONTEST_CATEGORY_CUTE:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_CUTE_RIBBON, data);
        break;
    case CONTEST_CATEGORY_SMART:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_SMART_RIBBON, data);
        break;
    case CONTEST_CATEGORY_TOUGH:
    default:
        gHighestRibbonRank = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_TOUGH_RIBBON, data);
        break;
    }

    gContestMons[gContestPlayerMonIndex].highestRank = gHighestRibbonRank;
    gameCleared = FlagGet(FLAG_SYS_GAME_CLEAR) > 0;
    gContestMons[gContestPlayerMonIndex].gameCleared = gameCleared;
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateMonsEm, Task_LinkContest_StartCommunicateRngEm);
}

static void Task_LinkContest_StartCommunicateRngEm(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateRngEm, Task_LinkContest_StartCommunicateLeaderIdsEm);
}
