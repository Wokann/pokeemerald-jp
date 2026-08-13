#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "data.h"
#include "string_util.h"
#include "strings.h"
#include "constants/battle_string_ids.h"
#include "constants/characters.h"
#include "constants/moves.h"
#include "constants/trainers.h"

// JP text-expand helper (US: BattleStringExpandPlaceholdersToDisplayedString)
extern void TryGetStatusString(const u8 *text);
extern void ChooseMoveUsedParticle(u8 *dest);
extern void ChooseTypeOfMoveUsedString(u8 *dest);
extern const u8 sATypeMove_Table[][12];
extern u8 sBattlerAbilities[MAX_BATTLERS_COUNT];

extern const u8 sText_GotAwaySafely[];
extern const u8 sText_PlayerDefeatedLinkTrainer[];
extern const u8 sText_TwoLinkTrainersDefeated[];
extern const u8 sText_PlayerLostAgainstLinkTrainer[];
extern const u8 sText_PlayerLostToTwo[];
extern const u8 sText_PlayerBattledToDrawLinkTrainer[];
extern const u8 sText_PlayerBattledToDrawVsTwo[];
extern const u8 sText_WildFled[];
extern const u8 sText_TwoWildFled[];
extern const u8 sText_PlayerDefeatedLinkTrainerTrainer1[];
extern const u8 sText_WildPkmnAppearedPause[];
extern const u8 sText_LegendaryPkmnAppeared[];
extern const u8 sText_WildPkmnAppeared[];
extern const u8 sText_TwoWildPkmnAppeared[];
extern const u8 sText_Trainer1WantsToBattle[];
extern const u8 sText_LinkTrainerWantsToBattlePause[];
extern const u8 sText_TwoLinkTrainersWantToBattlePause[];
extern const u8 sText_Trainer1SentOutPkmn[];
extern const u8 sText_Trainer1SentOutTwoPkmn[];
extern const u8 sText_Trainer1SentOutPkmn2[];
extern const u8 sText_LinkTrainerSentOutPkmn[];
extern const u8 sText_LinkTrainerSentOutTwoPkmn[];
extern const u8 sText_TwoLinkTrainersSentOutPkmn[];
extern const u8 sText_LinkTrainerSentOutPkmn2[];
extern const u8 sText_LinkTrainerMultiSentOutPkmn[];
extern const u8 sText_GoPkmn[];
extern const u8 sText_GoTwoPkmn[];
extern const u8 sText_GoPkmn2[];
extern const u8 sText_DoItPkmn[];
extern const u8 sText_YourFoesWeakGetEmPkmn[];
extern const u8 sText_GoForItPkmn[];
extern const u8 sText_LinkPartnerSentOutPkmnGoPkmn[];
extern const u8 sText_PkmnThatsEnough[];
extern const u8 sText_PkmnComeBack[];
extern const u8 sText_PkmnGoodComeBack[];
extern const u8 sText_PkmnOkComeBack[];
extern const u8 sText_Trainer1WithdrewPkmn[];
extern const u8 sText_LinkTrainer1WithdrewPkmn[];
extern const u8 sText_LinkTrainer2WithdrewPkmn[];
extern const u8 sText_AttackerUsedX[];
extern const u8 sText_TwoTrainersSentPkmn[];
extern const u8 sText_Trainer2SentOutPkmn[];
extern const u8 sText_TwoTrainersWantToBattle[];
extern const u8 sText_InGamePartnerSentOutZGoN[];
extern const u8 sText_TwoInGameTrainersDefeated[];
extern const u8 sText_PlayerLostAgainstTrainer1[];
extern const u8 sText_PlayerBattledToDrawTrainer1[];
extern const u8 sText_LinkTrainerWantsToBattle[];
extern const u8 sText_TwoLinkTrainersWantToBattle[];


extern const u16 sGrammarMoveUsedTable[];
extern const u8 sText_SpaceIs[];
extern const u8 sText_ApostropheS[];
extern const u8 sText_ExclamationMark[];
extern const u8 sText_ExclamationMark2[];
extern const u8 sText_ExclamationMark3[];
extern const u8 sText_ExclamationMark4[];
extern const u8 sText_ExclamationMark5[];

void ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

void ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}
