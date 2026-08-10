#include "global.h"
#include "reshow_battle_screen.h"
#include "battle.h"
#include "palette.h"
#include "pokemon.h"
#include "main.h"
#include "scanline_effect.h"
#include "text.h"
#include "gpu_regs.h"
#include "bg.h"
#include "battle_controllers.h"
#include "link.h"
#include "sprite.h"
#include "constants/trainers.h"
#include "battle_interface.h"
#include "battle_anim.h"
#include "data.h"

// this file's functions
static void CB2_ReshowBattleScreenAfterMenu(void);
static bool8 LoadBattlerSpriteGfx(u8 battler);
static void CreateBattlerSprite(u8 battler);
static void CreateHealthboxSprite(u8 battler);
static void ClearBattleBgCntBaseBlocks(void);

void ReshowBattleScreenDummy(void)
{

}

void ReshowBattleScreenAfterMenu(void)
{
    gPaletteFade.bufferTransferDisabled = 1;
    SetHBlankCallback(NULL);
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    gBattleScripting.reshowMainState = 0;
    gBattleScripting.reshowHelperState = 0;
    SetMainCallback2(CB2_ReshowBattleScreenAfterMenu);
}

__attribute__((naked)) static void CB2_ReshowBattleScreenAfterMenu(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "	push {r4, r5, r6, r7, lr}\n\t	sub sp, #8\n\t	ldr r0, _080A8C20\n\t	adds r0, #0x21\n\t	ldrb r0, [r0]\n\t	cmp r0, #0x13\n\t	bls _080A8C14\n\t	b _080A8E6C\n\t_080A8C14:\n\t	lsls r0, r0, #2\n\t	ldr r1, _080A8C24\n\t	adds r0, r0, r1\n\t	ldr r0, [r0]\n\t	mov pc, r0\n\t	.align 2, 0\n\t_080A8C20: .4byte 0x02024118\n\t_080A8C24: .4byte 0x080A8C28\n\t_080A8C28: @ jump table\n\t	.4byte _080A8C78 @ case 0\n\t	.4byte _080A8CF4 @ case 1\n\t	.4byte _080A8D0C @ case 2\n\t	.4byte _080A8D12 @ case 3\n\t	.4byte _080A8D18 @ case 4\n\t	.4byte _080A8D28 @ case 5\n\t	.4byte _080A8D2E @ case 6\n\t	.4byte _080A8D56 @ case 7\n\t	.4byte _080A8D5A @ case 8\n\t	.4byte _080A8D5E @ case 9\n\t	.4byte _080A8D62 @ case 10\n\t	.4byte _080A8D80 @ case 11\n\t	.4byte _080A8D88 @ case 12\n\t	.4byte _080A8D90 @ case 13\n\t	.4byte _080A8D98 @ case 14\n\t	.4byte _080A8DA0 @ case 15\n\t	.4byte _080A8DA8 @ case 16\n\t	.4byte _080A8DB0 @ case 17\n\t	.4byte _080A8DB8 @ case 18\n\t	.4byte _080A8DC0 @ case 19\n\t_080A8C78:\n\t	bl ScanlineEffect_Clear\n\t	bl BattleInitBgsAndWindows\n\t	movs r0, #1\n\t	movs r1, #1\n\t	movs r2, #0\n\t	bl SetBgAttribute\n\t	movs r0, #2\n\t	movs r1, #1\n\t	movs r2, #0\n\t	bl SetBgAttribute\n\t	movs r0, #0\n\t	bl ShowBg\n\t	movs r0, #1\n\t	bl ShowBg\n\t	movs r0, #2\n\t	bl ShowBg\n\t	movs r0, #3\n\t	bl ShowBg\n\t	bl ResetPaletteFade\n\t	ldr r0, _080A8CD4\n\t	movs r1, #0\n\t	strh r1, [r0]\n\t	ldr r0, _080A8CD8\n\t	strh r1, [r0]\n\t	ldr r0, _080A8CDC\n\t	strh r1, [r0]\n\t	ldr r0, _080A8CE0\n\t	strh r1, [r0]\n\t	ldr r0, _080A8CE4\n\t	strh r1, [r0]\n\t	ldr r0, _080A8CE8\n\t	strh r1, [r0]\n\t	ldr r0, _080A8CEC\n\t	strh r1, [r0]\n\t	ldr r0, _080A8CF0\n\t	strh r1, [r0]\n\t	b _080A8E9A\n\t	.align 2, 0\n\t_080A8CD4: .4byte 0x02022AC8\n\t_080A8CD8: .4byte 0x02022ACA\n\t_080A8CDC: .4byte 0x02022ACC\n\t_080A8CE0: .4byte 0x02022ACE\n\t_080A8CE4: .4byte 0x02022AD0\n\t_080A8CE8: .4byte 0x02022AD2\n\t_080A8CEC: .4byte 0x02022AD4\n\t_080A8CF0: .4byte 0x02022AD6\n\t_080A8CF4:\n\t	movs r0, #0\n\t	str r0, [sp, #4]\n\t	movs r1, #0xc0\n\t	lsls r1, r1, #0x13\n\t	ldr r2, _080A8D08\n\t	add r0, sp, #4\n\t	bl CpuFastSet\n\t	b _080A8E9A\n\t	.align 2, 0\n\t_080A8D08: .4byte 0x01006000\n\t_080A8D0C:\n\t	bl LoadBattleTextboxAndBackground\n\t	b _080A8E9A\n\t_080A8D12:\n\t	bl ResetSpriteData\n\t	b _080A8E9A\n\t_080A8D18:\n\t	bl FreeAllSpritePalettes\n\t	ldr r1, _080A8D24\n\t	movs r0, #4\n\t	strb r0, [r1]\n\t	b _080A8E9A\n\t	.align 2, 0\n\t_080A8D24: .4byte 0x030030BC\n\t_080A8D28:\n\t	bl ClearSpritesHealthboxAnimData\n\t	b _080A8E9A\n\t_080A8D2E:\n\t	ldr r5, _080A8D48\n\t	adds r4, r5, #0\n\t	adds r4, #0x22\n\t	ldrb r0, [r4]\n\t	bl BattleLoadAllHealthBoxesGfx\n\t	lsls r0, r0, #0x18\n\t	cmp r0, #0\n\t	beq _080A8D4C\n\t	movs r0, #0\n\t	strb r0, [r4]\n\t	b _080A8E9A\n\t	.align 2, 0\n\t_080A8D48: .4byte 0x02024118\n\t_080A8D4C:\n\t	ldrb r0, [r4]\n\t	adds r0, #1\n\t	strb r0, [r4]\n\t	adds r1, r5, #0\n\t	b _080A8D72\n\t_080A8D56:\n\t	movs r0, #0\n\t	b _080A8D64\n\t_080A8D5A:\n\t	movs r0, #1\n\t	b _080A8D64\n\t_080A8D5E:\n\t	movs r0, #2\n\t	b _080A8D64\n\t_080A8D62:\n\t	movs r0, #3\n\t_080A8D64:\n\t	bl LoadBattlerSpriteGfx\n\t	lsls r0, r0, #0x18\n\t	cmp r0, #0\n\t	beq _080A8D70\n\t	b _080A8E9A\n\t_080A8D70:\n\t	ldr r1, _080A8D7C\n\t_080A8D72:\n\t	adds r1, #0x21\n\t	ldrb r0, [r1]\n\t	subs r0, #1\n\t	strb r0, [r1]\n\t	b _080A8E9A\n\t	.align 2, 0\n\t_080A8D7C: .4byte 0x02024118\n\t_080A8D80:\n\t	movs r0, #0\n\t	bl CreateBattlerSprite\n\t	b _080A8E9A\n\t_080A8D88:\n\t	movs r0, #1\n\t	bl CreateBattlerSprite\n\t	b _080A8E9A\n\t_080A8D90:\n\t	movs r0, #2\n\t	bl CreateBattlerSprite\n\t	b _080A8E9A\n\t_080A8D98:\n\t	movs r0, #3\n\t	bl CreateBattlerSprite\n\t	b _080A8E9A\n\t_080A8DA0:\n\t	movs r0, #0\n\t	bl CreateHealthboxSprite\n\t	b _080A8E9A\n\t_080A8DA8:\n\t	movs r0, #1\n\t	bl CreateHealthboxSprite\n\t	b _080A8E9A\n\t_080A8DB0:\n\t	movs r0, #2\n\t	bl CreateHealthboxSprite\n\t	b _080A8E9A\n\t_080A8DB8:\n\t	movs r0, #3\n\t	bl CreateHealthboxSprite\n\t	b _080A8E9A\n\t_080A8DC0:\n\t	bl LoadAndCreateEnemyShadowSprites\n\t	movs r0, #1\n\t	bl GetBattlerAtPosition\n\t	adds r4, r0, #0\n\t	lsls r4, r4, #0x18\n\t	lsrs r4, r4, #0x18\n\t	ldr r7, _080A8E54\n\t	lsls r0, r4, #1\n\t	adds r0, r0, r7\n\t	ldrh r0, [r0]\n\t	movs r6, #0x64\n\t	muls r0, r6, r0\n\t	ldr r5, _080A8E58\n\t	adds r0, r0, r5\n\t	movs r1, #0xb\n\t	bl GetMonData3\n\t	adds r1, r0, #0\n\t	lsls r1, r1, #0x10\n\t	lsrs r1, r1, #0x10\n\t	adds r0, r4, #0\n\t	bl SetBattlerShadowSpriteCallback\n\t	bl IsDoubleBattle\n\t	lsls r0, r0, #0x18\n\t	cmp r0, #0\n\t	beq _080A8E24\n\t	movs r0, #3\n\t	bl GetBattlerAtPosition\n\t	adds r4, r0, #0\n\t	lsls r4, r4, #0x18\n\t	lsrs r4, r4, #0x18\n\t	lsls r0, r4, #1\n\t	adds r0, r0, r7\n\t	ldrh r0, [r0]\n\t	muls r0, r6, r0\n\t	adds r0, r0, r5\n\t	movs r1, #0xb\n\t	bl GetMonData3\n\t	adds r1, r0, #0\n\t	lsls r1, r1, #0x10\n\t	lsrs r1, r1, #0x10\n\t	adds r0, r4, #0\n\t	bl SetBattlerShadowSpriteCallback\n\t_080A8E24:\n\t	ldr r1, _080A8E5C\n\t	ldr r0, _080A8E60\n\t	ldrb r0, [r0]\n\t	adds r0, r0, r1\n\t	ldrb r0, [r0]\n\t	movs r1, #0\n\t	bl SetCB2ToReshowScreenAfterMenu\n\t	ldr r0, _080A8E64\n\t	ldrb r0, [r0]\n\t	cmp r0, #0\n\t	beq _080A8E9A\n\t	ldr r0, _080A8E68\n\t	ldrb r0, [r0]\n\t	cmp r0, #0\n\t	beq _080A8E9A\n\t	bl LoadWirelessStatusIndicatorSpriteGfx\n\t	movs r0, #0\n\t	movs r1, #0\n\t	bl CreateWirelessStatusIndicatorSprite\n\t	b _080A8E9A\n\t	.align 2, 0\n\t_080A8E54: .4byte 0x02023D12\n\t_080A8E58: .4byte 0x020243E8\n\t_080A8E5C: .4byte 0x02024150\n\t_080A8E60: .4byte 0x0202415C\n\t_080A8E64: .4byte 0x0300319C\n\t_080A8E68: .4byte 0x030031C4\n\t_080A8E6C:\n\t	ldr r0, _080A8EAC\n\t	bl SetVBlankCallback\n\t	bl ClearBattleBgCntBaseBlocks\n\t	movs r0, #1\n\t	str r0, [sp]\n\t	movs r0, #0xff\n\t	movs r1, #0\n\t	movs r2, #0x10\n\t	movs r3, #0\n\t	bl BeginHardwarePaletteFade\n\t	ldr r2, _080A8EB0\n\t	ldrb r1, [r2, #8]\n\t	movs r0, #0x7f\n\t	ands r0, r1\n\t	strb r0, [r2, #8]\n\t	ldr r0, _080A8EB4\n\t	bl SetMainCallback2\n\t	bl sub_0805EB30\n\t_080A8E9A:\n\t	ldr r1, _080A8EB8\n\t	adds r1, #0x21\n\t	ldrb r0, [r1]\n\t	adds r0, #1\n\t	strb r0, [r1]\n\t	add sp, #8\n\t	pop {r4, r5, r6, r7}\n\t	pop {r0}\n\t	bx r0\n\t	.align 2, 0\n\t_080A8EAC: .4byte 0x080386DD\n\t_080A8EB0: .4byte 0x02037C74\n\t_080A8EB4: .4byte 0x080380FD\n\t_080A8EB8: .4byte 0x02024118\n\t\n\t"
            ".syntax divided\n");
}

static void ClearBattleBgCntBaseBlocks(void)
{
    vBgCnt *regBgcnt1, *regBgcnt2;

    regBgcnt1 = (vBgCnt *)(&REG_BG1CNT);
    regBgcnt1->charBaseBlock = 0;

    regBgcnt2 = (vBgCnt *)(&REG_BG2CNT);
    regBgcnt2->charBaseBlock = 0;
}

static bool8 LoadBattlerSpriteGfx(u8 battler)
{
    if (battler < gBattlersCount)
    {
        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (!gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
                BattleLoadOpponentMonSpriteGfx(&gEnemyParty[gBattlerPartyIndexes[battler]], battler);
            else
                BattleLoadSubstituteOrMonSpriteGfx(battler, FALSE);
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == B_POSITION_PLAYER_LEFT) // Should be checking position, not battler.
            DecompressTrainerBackPic(gSaveBlock2Ptr->playerGender, battler);
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == B_POSITION_PLAYER_LEFT) // Should be checking position, not battler.
            DecompressTrainerBackPic(TRAINER_BACK_PIC_WALLY, battler);
        else if (!gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            BattleLoadPlayerMonSpriteGfx(&gPlayerParty[gBattlerPartyIndexes[battler]], battler);
        else
            BattleLoadSubstituteOrMonSpriteGfx(battler, FALSE);

        gBattleScripting.reshowHelperState = 0;
    }
    return TRUE;
}

static void CreateBattlerSprite(u8 battler)
{
    if (battler < gBattlersCount)
    {
        u8 posY;

        if (gBattleSpritesDataPtr->battlerData[battler].behindSubstitute)
            posY = GetSubstituteSpriteDefault_Y(battler);
        else
            posY = GetBattlerSpriteDefault_Y(battler);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                return;

            SetMultiuseSpriteTemplateToPokemon(GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), GetBattlerPosition(battler));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2), posY, GetBattlerSpriteSubpriority(battler));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
            gSprites[gBattlerSpriteIds[battler]].data[2] = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], gBattleMonForms[battler]);
            if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_CASTFORM)
                gSprites[gBattlerSpriteIds[battler]].anims = gMonFrontAnimsPtrTable[SPECIES_CASTFORM];
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == B_POSITION_PLAYER_LEFT)
        {
            SetMultiuseSpriteTemplateToTrainerBack(gSaveBlock2Ptr->playerGender, GetBattlerPosition(B_POSITION_PLAYER_LEFT));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, 0x50,
                                                (8 - gTrainerBackPicCoords[gSaveBlock2Ptr->playerGender].size) * 4 + 80,
                                                 GetBattlerSpriteSubpriority(0));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == B_POSITION_PLAYER_LEFT)
        {
            SetMultiuseSpriteTemplateToTrainerBack(TRAINER_BACK_PIC_WALLY, GetBattlerPosition(0));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, 0x50,
                                                (8 - gTrainerBackPicCoords[TRAINER_BACK_PIC_WALLY].size) * 4 + 80,
                                                 GetBattlerSpriteSubpriority(0));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
        }
        else
        {
            if (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                return;

            SetMultiuseSpriteTemplateToPokemon(GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES), GetBattlerPosition(battler));
            gBattlerSpriteIds[battler] = CreateSprite(&gMultiuseSpriteTemplate, GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2), posY, GetBattlerSpriteSubpriority(battler));
            gSprites[gBattlerSpriteIds[battler]].oam.paletteNum = battler;
            gSprites[gBattlerSpriteIds[battler]].callback = SpriteCallbackDummy;
            gSprites[gBattlerSpriteIds[battler]].data[0] = battler;
            gSprites[gBattlerSpriteIds[battler]].data[2] = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_SPECIES);

            StartSpriteAnim(&gSprites[gBattlerSpriteIds[battler]], gBattleMonForms[battler]);
            if (gBattleSpritesDataPtr->battlerData[battler].transformSpecies == SPECIES_CASTFORM)
                gSprites[gBattlerSpriteIds[battler]].anims = gMonFrontAnimsPtrTable[SPECIES_CASTFORM];
        }

        gSprites[gBattlerSpriteIds[battler]].invisible = gBattleSpritesDataPtr->battlerData[battler].invisible;
    }
}

static void CreateHealthboxSprite(u8 battler)
{
    if (battler < gBattlersCount)
    {
        u8 healthboxSpriteId;

        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI && battler == B_POSITION_PLAYER_LEFT)
            healthboxSpriteId = CreateSafariPlayerHealthboxSprites();
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL && battler == B_POSITION_PLAYER_LEFT)
            return;
        else
            healthboxSpriteId = CreateBattlerHealthboxSprites(battler);

        gHealthboxSpriteIds[battler] = healthboxSpriteId;
        InitBattlerHealthboxCoords(battler);
        SetHealthboxSpriteVisible(healthboxSpriteId);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gEnemyParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);
        else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_SAFARI_ALL_TEXT);
        else
            UpdateHealthboxAttribute(gHealthboxSpriteIds[battler], &gPlayerParty[gBattlerPartyIndexes[battler]], HEALTHBOX_ALL);

        if (GetBattlerPosition(battler) == B_POSITION_OPPONENT_RIGHT || GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT)
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[battler], TRUE);
        else
            DummyBattleInterfaceFunc(gHealthboxSpriteIds[battler], FALSE);

        if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        {
            if (GetMonData(&gEnemyParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
        else if (!(gBattleTypeFlags & BATTLE_TYPE_SAFARI))
        {
            if (GetMonData(&gPlayerParty[gBattlerPartyIndexes[battler]], MON_DATA_HP) == 0)
                SetHealthboxSpriteInvisible(healthboxSpriteId);
        }
    }
}
