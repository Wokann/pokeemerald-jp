#include "global.h"

extern void LaunchBattleTransitionTask(u8 transitionId);

void BattleTransition_Start(u8 transitionId)
{
    LaunchBattleTransitionTask(transitionId);
}
