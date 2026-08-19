#include "global.h"

#define SUMMARY_EFFECT_DATA __attribute__((section(".rodata.summary_screen_effect_data")))

SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Battle_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_battle.bin");
SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Contest_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_contest.bin");
SUMMARY_EFFECT_DATA const u16 gSummaryScreen_MoveEffect_Cancel_Tilemap[] =
    INCBIN_U16("graphics/summary_screen/effect_cancel.bin");
