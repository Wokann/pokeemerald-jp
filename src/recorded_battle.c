#include "global.h"

extern u32 sAI_Scripts;
extern u8 sBattleScene;
extern u8 sApprenticeId;
extern u8 sFrontierFacility;
extern u8 sTextSpeed;
extern u8 sApprenticeLanguage;
extern u8 sFrontierBrainSymbol;
extern u8 sRecordMixFriendClass;
extern u8 sRecordMixFriendLanguage;

u32 GetAiScriptsInRecordedBattle(void)
{
    return sAI_Scripts;
}

u8 GetBattleSceneInRecordedBattle(void)
{
    return sBattleScene;
}

u8 GetRecordedBattleApprenticeId(void)
{
    return sApprenticeId;
}

u8 GetRecordedBattleFrontierFacility(void)
{
    return sFrontierFacility;
}

u8 GetTextSpeedInRecordedBattle(void)
{
    return sTextSpeed;
}

u8 GetRecordedBattleApprenticeLanguage(void)
{
    return sApprenticeLanguage;
}

u8 GetRecordedBattleFronterBrainSymbol(void)
{
    return sFrontierBrainSymbol;
}

u8 GetRecordedBattleRecordMixFriendClass(void)
{
    return sRecordMixFriendClass;
}

u8 GetRecordedBattleRecordMixFriendLanguage(void)
{
    return sRecordMixFriendLanguage;
}
