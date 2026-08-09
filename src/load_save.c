#include "global.h"
#include "global.fieldmap.h"
#include "load_save.h"
#include "overworld.h"
#include "save_location.h"

void ClearContinueGameWarpStatus(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags &= ~CONTINUE_GAME_WARP;
}

void SetContinueGameWarpStatus(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags |= CONTINUE_GAME_WARP;
}

void SetContinueGameWarpStatusToDynamicWarp(void)
{
    SetContinueGameWarpToDynamicWarp(0);
    gSaveBlock2Ptr->specialSaveWarpFlags |= CONTINUE_GAME_WARP;
}

void ClearContinueGameWarpStatus2(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags &= ~CONTINUE_GAME_WARP;
}
