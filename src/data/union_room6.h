#include "global.h"

// Hi/do-something and contacted/awaiting texts
ALIGNED(4) const u8 sText_HiDoSomethingMale[] = _(
    "やあ！\n"
    "なにか　するかい？");

ALIGNED(4) const u8 sText_HiDoSomethingFemale[] = _(
    "こんにちは！\n"
    "なにか　する？");

ALIGNED(4) const u8 sText_HiDoSomethingAgainMale[] = _(
    "{B_COPY_VAR_1}‘やあ　また　あったね！\n"
    "こんどは　なにをする？");

ALIGNED(4) const u8 sText_HiDoSomethingAgainFemale[] = _(
    "{B_COPY_VAR_1}‘あ！　{MUS_RG_VS_TRAINER}\n"
    "こんにちは！　また　なにかする？");

const u8 *const sHiDoSomethingTexts[] = {
    sText_HiDoSomethingMale,
    sText_HiDoSomethingFemale,
    sText_HiDoSomethingAgainMale,
    sText_HiDoSomethingAgainFemale,
};

ALIGNED(4) const u8 sText_DoSomethingMale[] = _("なにか　するかい？");

ALIGNED(4) const u8 sText_DoSomethingFemale[] = _("なにか　する？");

ALIGNED(4) const u8 sText_DoSomethingAgainMale[] = _("{B_COPY_VAR_1}‘こんどは　なにをする？");

ALIGNED(4) const u8 sText_DoSomethingAgainFemale[] = _("{B_COPY_VAR_1}‘また　なにかする？");

const u8 *const sDoSomethingTexts[] = {
    sText_DoSomethingMale,
    sText_DoSomethingFemale,
    sText_DoSomethingAgainMale,
    sText_DoSomethingAgainMale,
};

ALIGNED(4) const u8 sText_SomebodyHasContactedYou[] = _(
    "だれかが\n"
    "はなしかけて　きました{PAUSE 60}");

ALIGNED(4) const u8 sText_PlayerHasContactedYou[] = _(
    "{B_COPY_VAR_1}が\n"
    "はなしかけて　きました{PAUSE 60}");

const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou,
};

ALIGNED(4) const u8 sText_AwaitingResponseFromTrainer[] = _(
    "あいての　へんじを\n"
    "まっています");

ALIGNED(4) const u8 sText_AwaitingResponseFromPlayer[] = _(
    "{B_COPY_VAR_1}の　へんじを\n"
    "まっています");

const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer,
};

