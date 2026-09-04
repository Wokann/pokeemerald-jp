#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_interface.h"
#include "battle_message.h"
#include "bg.h"
#include "data.h"
#include "item_menu.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "pokeball.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "reshow_battle_screen.h"
#include "sound.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define SAFARI_DISPATCH_DATA __attribute__((section(".rodata.safari_dispatch_data")))

typedef void (*SafariBufferCommandFunc)(void);

void SafariBufferRunCommand(void);
void SafariBufferExecCompleted(void);
void sub_081595D4(void);

extern void SetCB2ToReshowScreenAfterMenu(u8 cursorPosition, u8 baseTileNum);
extern void sub_08135944(void);
extern void sub_0805D3C8(struct Sprite *sprite);
extern void sub_08076320(u8 battler);
extern void sub_0814FA04(const u8 *text, u8 windowId);
extern void TryGetStatusString(const u8 *text);
extern void PlayCry1(u16 species, s8 pan);
extern bool8 gUnknown_202415D;
extern u16 gUnknown_2022D0A[][0x100];
extern const u8 gUnknown_85ABAEE[];
extern const SafariBufferCommandFunc sSafariBufferCommands[CONTROLLER_TERMINATOR_NOP + 1];

void SpriteCB_Null4(void) {}
void SetControllerToSafari(void)
{
    gBattlerControllerFuncs[gActiveBattler] = SafariBufferRunCommand;
}

void SafariBufferRunCommand(void)
{
    if (gBattleControllerExecFlags & gBitTable[gActiveBattler])
    {
        if (gBattleBufferA[gActiveBattler][0] < ARRAY_COUNT(sSafariBufferCommands))
            sSafariBufferCommands[gBattleBufferA[gActiveBattler][0]]();
        else
            SafariBufferExecCompleted();
    }
}

void HandleInputChooseAction(void)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);

        switch (gActionSelectionCursor[gActiveBattler])
        {
        case 0:
            BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SAFARI_BALL, 0);
            break;
        case 1:
            BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SAFARI_POKEBLOCK, 0);
            break;
        case 2:
            BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SAFARI_GO_NEAR, 0);
            break;
        case 3:
            BtlController_EmitTwoReturnValues(B_COMM_TO_ENGINE, B_ACTION_SAFARI_RUN, 0);
            break;
        }
        SafariBufferExecCompleted();
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (gActionSelectionCursor[gActiveBattler] & 1)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 1;
            SetCB2ToReshowScreenAfterMenu(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (!(gActionSelectionCursor[gActiveBattler] & 1))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 1;
            SetCB2ToReshowScreenAfterMenu(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (gActionSelectionCursor[gActiveBattler] & 2)
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 2;
            SetCB2ToReshowScreenAfterMenu(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (!(gActionSelectionCursor[gActiveBattler] & 2))
        {
            PlaySE(SE_SELECT);
            ActionSelectionDestroyCursorAt(gActionSelectionCursor[gActiveBattler]);
            gActionSelectionCursor[gActiveBattler] ^= 2;
            SetCB2ToReshowScreenAfterMenu(gActionSelectionCursor[gActiveBattler], 0);
        }
    }
}

void CompleteOnHealthboxSpriteCallbackDummy(void)
{
    if (gSprites[gBattlerSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        SafariBufferExecCompleted();
}

void SafariHandlePrintSelectionString(void)
{
    if (!IsTextPrinterActive(0))
        SafariBufferExecCompleted();
}

void CompleteWhenChosePokeblock(void)
{
    if (gSprites[gHealthboxSpriteIds[gActiveBattler]].callback == SpriteCallbackDummy)
        SafariBufferExecCompleted();
}

void sub_08159520(void)
{
    if (!gPaletteFade.active)
    {
        gMain.inBattle = FALSE;
        gMain.callback1 = gPreBattleCallback1;
        SetMainCallback2(gMain.savedCallback);
    }
}

void CompleteOnSpecialAnimDone(void)
{
    if (!gUnknown_202415D || !gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].specialAnimActive)
        SafariBufferExecCompleted();
}

void SafariOpenPokeblockCase(void)
{
    if (!gPaletteFade.active)
    {
        gBattlerControllerFuncs[gActiveBattler] = sub_081595D4;
        FreeAllWindowBuffers();
        sub_08135944();
    }
}

void sub_081595D4(void)
{
    if (gMain.callback2 == BattleMainCB2 && !gPaletteFade.active)
    {
        BtlController_EmitOneReturnValue(B_COMM_TO_ENGINE, gSpecialVar_ItemId);
        SafariBufferExecCompleted();
    }
}

void SafariHandleSuccessBallThrowAnim(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].animFromTableActive)
        SafariBufferExecCompleted();
}

void SafariBufferExecCompleted(void)
{
    gBattlerControllerFuncs[gActiveBattler] = SafariBufferRunCommand;
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        u8 playerId = GetMultiplayerId();

        PrepareBufferDataTransferLink(B_COMM_CONTROLLER_IS_DONE, 4, &playerId);
        gBattleBufferA[gActiveBattler][0] = CONTROLLER_TERMINATOR_NOP;
    }
    else
    {
        gBattleControllerExecFlags &= ~gBitTable[gActiveBattler];
    }
}

void SafariHandleBallThrowAnim(void)
{
    if (!gBattleSpritesDataPtr->healthBoxesData[gActiveBattler].statusAnimActive)
        SafariBufferExecCompleted();
}

void SafariHandleGetMonData(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleGetRawMonData(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleSetMonData(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleSetRawMonData(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleLoadMonSprite(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleSwitchInAnim(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleReturnMonToBall(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleDrawTrainerPic(void)
{
    DecompressTrainerBackPic(gSaveBlock2Ptr->playerGender, gActiveBattler);
    SetMultiuseSpriteTemplateToTrainerBack(gSaveBlock2Ptr->playerGender, GetBattlerPosition(gActiveBattler));
    gBattlerSpriteIds[gActiveBattler] = CreateSprite(
        &gMultiuseSpriteTemplate,
        80,
        (8 - gTrainerBackPicCoords[gSaveBlock2Ptr->playerGender].size) * 4 + 80,
        30);
    gSprites[gBattlerSpriteIds[gActiveBattler]].oam.paletteNum = gActiveBattler;
    gSprites[gBattlerSpriteIds[gActiveBattler]].x2 = DISPLAY_WIDTH;
    gSprites[gBattlerSpriteIds[gActiveBattler]].data[0] = -2;
    gSprites[gBattlerSpriteIds[gActiveBattler]].callback = sub_0805D3C8;
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnHealthboxSpriteCallbackDummy;
}

void SafariHandleTrainerSlide(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleTrainerSlideBack(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleFaintAnimation(void)
{
    SafariBufferExecCompleted();
}


void SafariHandlePaletteFade(void)
{
    SafariBufferExecCompleted();
}


void sub_0815984C(void)
{
    gBattleSpritesDataPtr->animationData->ballThrowCaseId = BALL_3_SHAKES_SUCCESS;
    gUnknown_202415D = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_BALL_THROW_WITH_TRAINER);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnSpecialAnimDone;
}

void sub_081598A0(void)
{
    u8 ballThrowCaseId = gBattleBufferA[gActiveBattler][1];

    gBattleSpritesDataPtr->animationData->ballThrowCaseId = ballThrowCaseId;
    gUnknown_202415D = TRUE;
    InitAndLaunchSpecialAnimation(gActiveBattler, gActiveBattler, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), B_ANIM_BALL_THROW_WITH_TRAINER);
    gBattlerControllerFuncs[gActiveBattler] = CompleteOnSpecialAnimDone;
}

void SafariHandlePause(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleMoveAnimation(void)
{
    SafariBufferExecCompleted();
}


void SafariHandlePrintString(void)
{
    u16 *stringId;

    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    stringId = gUnknown_2022D0A[gActiveBattler];
    BufferStringBattle(*stringId);
    sub_0814FA04(gDisplayedStringBattle, 0);
    gBattlerControllerFuncs[gActiveBattler] = SafariHandlePrintSelectionString;
}

void sub_0815996C(void)
{
    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        SafariHandlePrintString();
    else
        SafariBufferExecCompleted();
}

void sub_08159990(void)
{
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        gBattle_BG0_X = 0;
        gBattle_BG0_Y = DISPLAY_HEIGHT;
        gBattlerControllerFuncs[gActiveBattler] = HandleInputChooseAction;
    }
}

void SafariHandleChooseAction(void)
{
    s32 i;

    gBattlerControllerFuncs[gActiveBattler] = sub_08159990;
    sub_0814FA04(gUnknown_85ABAEE + 0x98, 2);

    for (i = 0; i < 4; i++)
        ActionSelectionDestroyCursorAt(i);

    SetCB2ToReshowScreenAfterMenu(gActionSelectionCursor[gActiveBattler], 0);
    TryGetStatusString(gUnknown_85ABAEE + 0x5F);
    sub_0814FA04(gDisplayedStringBattle, 1);
}

void SafariHandleUnknownYesNoBox(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleChooseMove(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleChooseItem(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gBattlerControllerFuncs[gActiveBattler] = SafariOpenPokeblockCase;
    gBattlerInMenuId = gActiveBattler;
}

void SafariHandleChoosePokemon(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleCmd23(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleHealthBarUpdate(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleExpUpdate(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleStatusIconUpdate(void)
{
    UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_SAFARI_BALLS_TEXT);
    SafariBufferExecCompleted();
}

void SafariHandleStatusAnimation(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleStatusXor(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleDataTransfer(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleDMA3Transfer(void)
{
    SafariBufferExecCompleted();
}


void SafariHandlePlayBGM(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleCmd32(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleTwoReturnValues(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleChosenMonReturnValue(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleOneReturnValue(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleOneReturnValue_Duplicate(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleCmd37(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleCmd38(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleCmd39(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleCmd40(void)
{
    SafariBufferExecCompleted();
}

void SafariHandleHitAnimation(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleCmd42(void)
{
    SafariBufferExecCompleted();
}

void SafariHandlePlaySE(void)
{
    s8 pan;

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        pan = SOUND_PAN_ATTACKER;
    else
        pan = SOUND_PAN_TARGET;

    PlaySE12WithPanning(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8), pan);
    SafariBufferExecCompleted();
}

void SafariHandlePlayFanfareOrBGM(void)
{
    if (gBattleBufferA[gActiveBattler][3])
    {
        BattleStopLowHpSound();
        PlayBGM(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8));
    }
    else
    {
        PlayFanfare(gBattleBufferA[gActiveBattler][1] | (gBattleBufferA[gActiveBattler][2] << 8));
    }

    SafariBufferExecCompleted();
}

void SafariHandleFaintingCry(void)
{
    u16 species = GetMonData3(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_SPECIES);

    PlayCry1(species, 25);
    SafariBufferExecCompleted();
}

void SafariHandleIntroSlide(void)
{
    HandleIntroSlide(gBattleBufferA[gActiveBattler][1]);
    gIntroSlideFlags |= 1;
    SafariBufferExecCompleted();
}

void SafariHandleIntroTrainerBallThrow(void)
{
    UpdateHealthboxAttribute(gHealthboxSpriteIds[gActiveBattler], &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], HEALTHBOX_SAFARI_ALL_TEXT);
    sub_08076320(gActiveBattler);
    SetHealthboxSpriteVisible(gHealthboxSpriteIds[gActiveBattler]);
    gBattlerControllerFuncs[gActiveBattler] = CompleteWhenChosePokeblock;
}

void SafariHandleDrawPartyStatusSummary(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleHidePartyStatusSummary(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleEndBounceEffect(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleSpriteInvisibility(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleBattleAnimation(void)
{
    u8 animationId = gBattleBufferA[gActiveBattler][1];
    u16 argument = gBattleBufferA[gActiveBattler][2] | (gBattleBufferA[gActiveBattler][3] << 8);

    if (TryHandleLaunchBattleTableAnimation(gActiveBattler, gActiveBattler, gActiveBattler, animationId, argument))
        SafariBufferExecCompleted();
    else
        gBattlerControllerFuncs[gActiveBattler] = SafariHandleSuccessBallThrowAnim;
}

void SafariHandleLinkStandbyMsg(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleResetActionMoveSelection(void)
{
    SafariBufferExecCompleted();
}


void SafariHandleCmd55(void)
{
    gBattleOutcome = gBattleBufferA[gActiveBattler][1];
    FadeOutMapMusic(5);
    BeginFastPaletteFade(3);
    SafariBufferExecCompleted();
    if ((gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_IS_MASTER)) == BATTLE_TYPE_LINK)
        gBattlerControllerFuncs[gActiveBattler] = sub_08159520;
}

void SafariCmdEnd(void) {}

// SafariBufferRunCommand accepts command IDs 0x00 through 0x38.
SAFARI_DISPATCH_DATA const SafariBufferCommandFunc sSafariBufferCommands[CONTROLLER_TERMINATOR_NOP + 1] =
{
    [CONTROLLER_GETMONDATA]               = SafariHandleGetMonData,
    [CONTROLLER_GETRAWMONDATA]            = SafariHandleGetRawMonData,
    [CONTROLLER_SETMONDATA]               = SafariHandleSetMonData,
    [CONTROLLER_SETRAWMONDATA]            = SafariHandleSetRawMonData,
    [CONTROLLER_LOADMONSPRITE]            = SafariHandleLoadMonSprite,
    [CONTROLLER_SWITCHINANIM]             = SafariHandleSwitchInAnim,
    [CONTROLLER_RETURNMONTOBALL]          = SafariHandleReturnMonToBall,
    [CONTROLLER_DRAWTRAINERPIC]           = SafariHandleDrawTrainerPic,
    [CONTROLLER_TRAINERSLIDE]             = SafariHandleTrainerSlide,
    [CONTROLLER_TRAINERSLIDEBACK]         = SafariHandleTrainerSlideBack,
    [CONTROLLER_FAINTANIMATION]           = SafariHandleFaintAnimation,
    [CONTROLLER_PALETTEFADE]              = SafariHandlePaletteFade,
    [CONTROLLER_SUCCESSBALLTHROWANIM]     = sub_0815984C,
    [CONTROLLER_BALLTHROWANIM]            = sub_081598A0,
    [CONTROLLER_PAUSE]                    = SafariHandlePause,
    [CONTROLLER_MOVEANIMATION]            = SafariHandleMoveAnimation,
    [CONTROLLER_PRINTSTRING]              = SafariHandlePrintString,
    [CONTROLLER_PRINTSTRINGPLAYERONLY]    = sub_0815996C,
    [CONTROLLER_CHOOSEACTION]             = SafariHandleChooseAction,
    [CONTROLLER_YESNOBOX]                 = SafariHandleUnknownYesNoBox,
    [CONTROLLER_CHOOSEMOVE]               = SafariHandleChooseMove,
    [CONTROLLER_OPENBAG]                  = SafariHandleChooseItem,
    [CONTROLLER_CHOOSEPOKEMON]            = SafariHandleChoosePokemon,
    [CONTROLLER_23]                       = SafariHandleCmd23,
    [CONTROLLER_HEALTHBARUPDATE]          = SafariHandleHealthBarUpdate,
    [CONTROLLER_EXPUPDATE]                = SafariHandleExpUpdate,
    [CONTROLLER_STATUSICONUPDATE]         = SafariHandleStatusIconUpdate,
    [CONTROLLER_STATUSANIMATION]          = SafariHandleStatusAnimation,
    [CONTROLLER_STATUSXOR]                = SafariHandleStatusXor,
    [CONTROLLER_DATATRANSFER]             = SafariHandleDataTransfer,
    [CONTROLLER_DMA3TRANSFER]             = SafariHandleDMA3Transfer,
    [CONTROLLER_PLAYBGM]                  = SafariHandlePlayBGM,
    [CONTROLLER_32]                       = SafariHandleCmd32,
    [CONTROLLER_TWORETURNVALUES]          = SafariHandleTwoReturnValues,
    [CONTROLLER_CHOSENMONRETURNVALUE]     = SafariHandleChosenMonReturnValue,
    [CONTROLLER_ONERETURNVALUE]           = SafariHandleOneReturnValue,
    [CONTROLLER_ONERETURNVALUE_DUPLICATE] = SafariHandleOneReturnValue_Duplicate,
    [CONTROLLER_CLEARUNKVAR]              = SafariHandleCmd37,
    [CONTROLLER_SETUNKVAR]                = SafariHandleCmd38,
    [CONTROLLER_CLEARUNKFLAG]             = SafariHandleCmd39,
    [CONTROLLER_TOGGLEUNKFLAG]            = SafariHandleCmd40,
    [CONTROLLER_HITANIMATION]             = SafariHandleHitAnimation,
    [CONTROLLER_CANTSWITCH]               = SafariHandleCmd42,
    [CONTROLLER_PLAYSE]                   = SafariHandlePlaySE,
    [CONTROLLER_PLAYFANFAREORBGM]         = SafariHandlePlayFanfareOrBGM,
    [CONTROLLER_FAINTINGCRY]              = SafariHandleFaintingCry,
    [CONTROLLER_INTROSLIDE]               = SafariHandleIntroSlide,
    [CONTROLLER_INTROTRAINERBALLTHROW]    = SafariHandleIntroTrainerBallThrow,
    [CONTROLLER_DRAWPARTYSTATUSSUMMARY]   = SafariHandleDrawPartyStatusSummary,
    [CONTROLLER_HIDEPARTYSTATUSSUMMARY]   = SafariHandleHidePartyStatusSummary,
    [CONTROLLER_ENDBOUNCE]                = SafariHandleEndBounceEffect,
    [CONTROLLER_SPRITEINVISIBILITY]       = SafariHandleSpriteInvisibility,
    [CONTROLLER_BATTLEANIMATION]          = SafariHandleBattleAnimation,
    [CONTROLLER_LINKSTANDBYMSG]           = SafariHandleLinkStandbyMsg,
    [CONTROLLER_RESETACTIONMOVESELECTION] = SafariHandleResetActionMoveSelection,
    [CONTROLLER_ENDLINKBATTLE]            = SafariHandleCmd55,
    [CONTROLLER_TERMINATOR_NOP]           = SafariCmdEnd,
};
