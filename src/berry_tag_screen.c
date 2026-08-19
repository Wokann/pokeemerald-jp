#include "global.h"
#include "berry_tag_screen.h"
#include "berry.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "main.h"
#include "malloc.h"
#include "menu_helpers.h"
#include "menu.h"
#include "palette.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "decompress.h"
#include "bg.h"
#include "palette.h"
#include "graphics.h"
#include "save.h"

// JP ROM layout matches pokeemerald's struct plus a trailing 2-byte
// padding, giving sizeof(*sBerryTag) == 0x180C (matches AllocZeroed size).
struct BerryTagScreenStruct
{
    u16 tilemapBuffers[3][0x400];
    u16 berryId;
    u8 berrySpriteId;
    u8 flavorCircleIds[FLAVOR_COUNT];
    u16 gfxState;
    u16 unused;
};

// Address defined in ld_script_jp.txt (ABSOLUTE 0x0203B9C0).
extern struct BerryTagScreenStruct *sBerryTag;
#define BG_TILE 0x42
#define tBerryY data[0]
#define tBgOp data[1]
void bag_menu_mail_related(void);
void PrintTextInBerryTagScreen(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed, u8 colorStructId);
void CB2_InitBerryTagScreen(void);
void Task_CloseBerryTagScreen(u8 taskId);
void Task_DisplayAnotherBerry(u8 taskId);
void HandleBagCursorPositionChange(s8 toMove);
void TryChangeDisplayedBerry(u8 taskId, s8 toMove);
extern const u8 gUnknown_85C97BD[];

void DoBerryTagScreen(void)
{
    sBerryTag = AllocZeroed(sizeof(*sBerryTag));
    sBerryTag->berryId = ItemIdToBerryType(gSpecialVar_ItemId);
    SetMainCallback2(CB2_InitBerryTagScreen);
}

void CB2_BerryTagScreen(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

void VblankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

__attribute__((naked)) void CB2_InitBerryTagScreen(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "_08177B6E:\n\t"
        "	bl MenuHelpers_ShouldWaitForLinkRecv\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08177B92\n\t"
        "	bl InitBerryTagScreen\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _08177B92\n\t"
        "	bl MenuHelpers_IsLinkActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08177B6E\n\t"
        "_08177B92:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InitBerryTagScreen(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r0, _08177BB8\n\t"
        "	movs r1, #0x87\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xf\n\t"
        "	bls _08177BAC\n\t"
        "	b _08177CDC\n\t"
        "_08177BAC:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _08177BBC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_08177BB8: .4byte gMain\n\t"
        "_08177BBC: .4byte _08177BC0\n\t"
        "_08177BC0:\n\t"
        "	.4byte _08177C00\n\t"
        "	.4byte _08177C0E\n\t"
        "	.4byte _08177C14\n\t"
        "	.4byte _08177C28\n\t"
        "	.4byte _08177C2E\n\t"
        "	.4byte _08177C34\n\t"
        "	.4byte _08177C44\n\t"
        "	.4byte _08177C60\n\t"
        "	.4byte _08177C6C\n\t"
        "	.4byte _08177C72\n\t"
        "	.4byte _08177C78\n\t"
        "	.4byte _08177C7E\n\t"
        "	.4byte _08177C84\n\t"
        "	.4byte _08177C8E\n\t"
        "	.4byte _08177C9C\n\t"
        "	.4byte _08177CAA\n\t"
        "_08177C00:\n\t"
        "	bl SetVBlankHBlankCallbacksToNull\n\t"
        "	bl ResetVramOamAndBgCntRegs\n\t"
        "	bl ClearScheduledBgCopiesToVram\n\t"
        "	b _08177CC4\n\t"
        "_08177C0E:\n\t"
        "	bl ScanlineEffect_Stop\n\t"
        "	b _08177CC4\n\t"
        "_08177C14:\n\t"
        "	bl ResetPaletteFade\n\t"
        "	ldr r2, _08177C24\n\t"
        "	ldrb r0, [r2, #8]\n\t"
        "	movs r1, #0x80\n\t"
        "	orrs r0, r1\n\t"
        "	b _08177CC2\n\t"
        "	.align 2, 0\n\t"
        "_08177C24: .4byte gPaletteFade\n\t"
        "_08177C28:\n\t"
        "	bl ResetSpriteData\n\t"
        "	b _08177CC4\n\t"
        "_08177C2E:\n\t"
        "	bl FreeAllSpritePalettes\n\t"
        "	b _08177CC4\n\t"
        "_08177C34:\n\t"
        "	bl sub_081221B8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08177CC4\n\t"
        "	bl ResetTasks\n\t"
        "	b _08177CC4\n\t"
        "_08177C44:\n\t"
        "	bl AddBerryTagTextToBg0\n\t"
        "	ldr r0, _08177C58\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _08177C5C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0]\n\t"
        "	b _08177CC4\n\t"
        "	.align 2, 0\n\t"
        "_08177C58: .4byte sBerryTag\n\t"
        "_08177C5C: .4byte 0x00001808\n\t"
        "_08177C60:\n\t"
        "	bl LoadBerryTagGfx\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08177CF4\n\t"
        "	b _08177CC4\n\t"
        "_08177C6C:\n\t"
        "	bl PrintMysteryMenuText\n\t"
        "	b _08177CC4\n\t"
        "_08177C72:\n\t"
        "	bl PrintBerrySize\n\t"
        "	b _08177CC4\n\t"
        "_08177C78:\n\t"
        "	bl PrintAllBerryData\n\t"
        "	b _08177CC4\n\t"
        "_08177C7E:\n\t"
        "	bl CreateBerrySprite\n\t"
        "	b _08177CC4\n\t"
        "_08177C84:\n\t"
        "	bl CreateFlavorCircleSprites\n\t"
        "	bl SetFlavorCirclesVisiblity\n\t"
        "	b _08177CC4\n\t"
        "_08177C8E:\n\t"
        "	ldr r0, _08177C98\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateTask\n\t"
        "	b _08177CC4\n\t"
        "	.align 2, 0\n\t"
        "_08177C98: .4byte Task_HandleInput + 1\n\t"
        "_08177C9C:\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	movs r1, #0x10\n\t"
        "	movs r2, #0\n\t"
        "	bl BlendPalettes\n\t"
        "	b _08177CC4\n\t"
        "_08177CAA:\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp]\n\t"
        "	movs r2, #0x10\n\t"
        "	movs r3, #0\n\t"
        "	bl BeginNormalPaletteFade\n\t"
        "	ldr r2, _08177CD4\n\t"
        "	ldrb r1, [r2, #8]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "_08177CC2:\n\t"
        "	strb r0, [r2, #8]\n\t"
        "_08177CC4:\n\t"
        "	ldr r1, _08177CD8\n\t"
        "	movs r0, #0x87\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	b _08177CF4\n\t"
        "	.align 2, 0\n\t"
        "_08177CD4: .4byte gPaletteFade\n\t"
        "_08177CD8: .4byte gMain\n\t"
        "_08177CDC:\n\t"
        "	ldr r0, _08177CEC\n\t"
        "	bl SetVBlankCallback\n\t"
        "	ldr r0, _08177CF0\n\t"
        "	bl SetMainCallback2\n\t"
        "	movs r0, #1\n\t"
        "	b _08177CF6\n\t"
        "	.align 2, 0\n\t"
        "_08177CEC: .4byte VblankCB + 1\n\t"
        "_08177CF0: .4byte CB2_BerryTagScreen + 1\n\t"
        "_08177CF4:\n\t"
        "	movs r0, #0\n\t"
        "_08177CF6:\n\t"
        "	add sp, #4\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void AddBerryTagTextToBg0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	movs r0, #0\n\t"
        "	bl ResetBgsAndClearDma3BusyFlags\n\t"
        "	ldr r1, _08177D68\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #4\n\t"
        "	bl InitBgsFromTemplates\n\t"
        "	ldr r4, _08177D6C\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #2\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	ldr r1, [r4]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #3\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	bl ResetAllBgsCoordinates\n\t"
        "	movs r0, #2\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	movs r0, #3\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	movs r1, #0x82\n\t"
        "	lsls r1, r1, #5\n\t"
        "	movs r0, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x50\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #1\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #2\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #3\n\t"
        "	bl ShowBg\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08177D68: .4byte gUnknown_85CD068\n\t"
        "_08177D6C: .4byte sBerryTag\n\t"
        ".syntax divided\n\t"
    );
}

bool8 LoadBerryTagGfx(void)
{
    u16 i;

    switch (sBerryTag->gfxState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(2, gBerryCheck_Gfx, 0, 0, 0);
        sBerryTag->gfxState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressVram(gBerryTag_Gfx, sBerryTag->tilemapBuffers[0]);
            sBerryTag->gfxState++;
        }
        break;
    case 2:
        LZDecompressVram(gBerryTag_Tilemap, sBerryTag->tilemapBuffers[2]);
        sBerryTag->gfxState++;
        break;
    case 3:
        if (gSaveBlock2Ptr->playerGender == MALE)
        {
            for (i = 0; i < ARRAY_COUNT(sBerryTag->tilemapBuffers[1]); i++)
                sBerryTag->tilemapBuffers[1][i] = (4 << 12) | BG_TILE;
        }
        else
        {
            for (i = 0; i < ARRAY_COUNT(sBerryTag->tilemapBuffers[1]); i++)
                sBerryTag->tilemapBuffers[1][i] = (5 << 12) | BG_TILE;
        }
        sBerryTag->gfxState++;
        break;
    case 4:
        LoadCompressedPalette(gBerryCheck_Pal, BG_PLTT_ID(0), 6 * PLTT_SIZE_4BPP);
        sBerryTag->gfxState++;
        break;
    case 5:
        LoadCompressedSpriteSheet(&gBerryCheckCircleSpriteSheet);
        sBerryTag->gfxState++;
        break;
    default:
        LoadCompressedSpritePalette(&gBerryCheckCirclePaletteTable);
        return TRUE;
    }

    return FALSE;
}

__attribute__((naked)) void PrintMysteryMenuText(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _08177F2C\n\t"
        "	bl InitWindows\n\t"
        "	bl DeactivateAllTextPrinters\n\t"
        "	ldr r0, _08177F30\n\t"
        "	movs r1, #0xf0\n\t"
        "	movs r2, #0x20\n\t"
        "	bl LoadPalette\n\t"
        "	movs r4, #0\n\t"
        "_08177F08:\n\t"
        "	lsls r0, r4, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl PutWindowTilemap\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	cmp r4, #3\n\t"
        "	bls _08177F08\n\t"
        "	movs r0, #0\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	movs r0, #1\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08177F2C: .4byte gUnknown_85CD0A0\n\t"
        "_08177F30: .4byte gUnknown_85CD078\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PrintTextInBerryTagScreen(u8 windowId, const u8 *text, u8 x, u8 y, s32 speed, u8 colorStructId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #0x14\n\t"
        "	ldr r6, [sp, #0x24]\n\t"
        "	ldr r5, [sp, #0x28]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	lsls r4, r5, #1\n\t"
        "	adds r4, r4, r5\n\t"
        "	ldr r5, _08177F74\n\t"
        "	adds r4, r4, r5\n\t"
        "	str r4, [sp, #8]\n\t"
        "	lsls r6, r6, #0x18\n\t"
        "	asrs r6, r6, #0x18\n\t"
        "	str r6, [sp, #0xc]\n\t"
        "	str r1, [sp, #0x10]\n\t"
        "	movs r1, #1\n\t"
        "	bl AddTextPrinterParameterized4\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08177F74: .4byte gUnknown_85CD098\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PrintBerrySize(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #8\n\t"
        "	movs r0, #0\n\t"
        "	bl GetBgTilemapBuffer\n\t"
        "	ldr r1, _08177FC4\n\t"
        "	ldr r1, [r1]\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #4\n\t"
        "	bl memcpy\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0xff\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r1, _08177FC8\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #3\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl PrintTextInBerryTagScreen\n\t"
        "	movs r0, #3\n\t"
        "	bl PutWindowTilemap\n\t"
        "	movs r0, #0\n\t"
        "	bl ScheduleBgCopyTilemapToVram\n\t"
        "	add sp, #8\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08177FC4: .4byte sBerryTag\n\t"
        "_08177FC8: .4byte gUnknown_85C97BD\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void PrintAllBerryData(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl PrintBerryNumberAndName\n\t"
        "	bl sub_0817804C\n\t"
        "	bl PrintBerryFirmness\n\t"
        "	bl PrintBerryDescription1\n\t"
        "	bl PrintBerryDescription2\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PrintBerryNumberAndName(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r5, _08178038\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r4, #0xc0\n\t"
        "	lsls r4, r4, #5\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBerryInfo\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldr r0, _0817803C\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrh r1, [r1]\n\t"
        "	movs r2, #2\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r0, _08178040\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl StringCopy\n\t"
        "	ldr r4, _08178044\n\t"
        "	ldr r1, _08178048\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	str r0, [sp, #4]\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl PrintTextInBerryTagScreen\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08178038: .4byte sBerryTag\n\t"
        "_0817803C: .4byte gStringVar1\n\t"
        "_08178040: .4byte gStringVar2\n\t"
        "_08178044: .4byte gStringVar4\n\t"
        "_08178048: .4byte gUnknown_85C97B5\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0817804C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r0, _081780D0\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBerryInfo\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r2, _081780D4\n\t"
        "	movs r7, #2\n\t"
        "	str r7, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r6, #0\n\t"
        "	str r6, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrh r0, [r5, #8]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _081780E8\n\t"
        "	ldr r4, _081780D8\n\t"
        "	movs r1, #0xa\n\t"
        "	bl __udivsi3\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r4, _081780DC\n\t"
        "	ldrh r0, [r5, #8]\n\t"
        "	movs r1, #0xa\n\t"
        "	bl __umodsi3\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl ConvertIntToDecimalStringN\n\t"
        "	ldr r4, _081780E0\n\t"
        "	ldr r1, _081780E4\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	str r7, [sp]\n\t"
        "	str r6, [sp, #4]\n\t"
        "	str r6, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	movs r3, #0x28\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	b _081780FA\n\t"
        "	.align 2, 0\n\t"
        "_081780D0: .4byte sBerryTag\n\t"
        "_081780D4: .4byte gUnknown_85C977D\n\t"
        "_081780D8: .4byte gStringVar1\n\t"
        "_081780DC: .4byte gStringVar2\n\t"
        "_081780E0: .4byte gStringVar4\n\t"
        "_081780E4: .4byte gUnknown_85C9786\n\t"
        "_081780E8:\n\t"
        "	ldr r2, _08178104\n\t"
        "	str r7, [sp]\n\t"
        "	str r0, [sp, #4]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0x28\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "_081780FA:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08178104: .4byte gUnknown_85C93F5\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PrintBerryFirmness(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r0, _0817815C\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBerryInfo\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldr r2, _08178160\n\t"
        "	movs r5, #0x12\n\t"
        "	str r5, [sp]\n\t"
        "	movs r0, #0xff\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrb r0, [r6, #7]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08178168\n\t"
        "	ldr r0, _08178164\n\t"
        "	ldrb r1, [r6, #7]\n\t"
        "	subs r1, #1\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, [r1]\n\t"
        "	str r5, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0x28\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	b _0817817A\n\t"
        "	.align 2, 0\n\t"
        "_0817815C: .4byte sBerryTag\n\t"
        "_08178160: .4byte gUnknown_85C9782\n\t"
        "_08178164: .4byte gUnknown_85CD0C8\n\t"
        "_08178168:\n\t"
        "	ldr r2, _08178184\n\t"
        "	str r5, [sp]\n\t"
        "	str r0, [sp, #4]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0x28\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "_0817817A:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08178184: .4byte gUnknown_85C93F5\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PrintBerryDescription1(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r0, _081781B8\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBerryInfo\n\t"
        "	ldr r2, [r0, #0xc]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #4]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081781B8: .4byte sBerryTag\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PrintBerryDescription2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r0, _081781EC\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetBerryInfo\n\t"
        "	ldr r2, [r0, #0x10]\n\t"
        "	movs r0, #0x12\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #4]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081781EC: .4byte sBerryTag\n\t"
        ".syntax divided\n\t"
    );
}

void CreateBerrySprite(void)
{
    sBerryTag->berrySpriteId = CreateBerryTagSprite(sBerryTag->berryId - 1, 56, 64);
}

void DestroyBerrySprite(void)
{
    DestroySprite(&gSprites[sBerryTag->berrySpriteId]);
    FreeBerryTagSpritePalette();
}

void CreateFlavorCircleSprites(void)
{
    sBerryTag->flavorCircleIds[FLAVOR_SPICY] = CreateBerryFlavorCircleSprite(60);
    sBerryTag->flavorCircleIds[FLAVOR_DRY] = CreateBerryFlavorCircleSprite(92);
    sBerryTag->flavorCircleIds[FLAVOR_SWEET] = CreateBerryFlavorCircleSprite(124);
    sBerryTag->flavorCircleIds[FLAVOR_BITTER] = CreateBerryFlavorCircleSprite(156);
    sBerryTag->flavorCircleIds[FLAVOR_SOUR] = CreateBerryFlavorCircleSprite(188);
}

void SetFlavorCirclesVisiblity(void)
{
    const struct Berry *berry = GetBerryInfo(sBerryTag->berryId);

    if (berry->spicy)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SPICY]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SPICY]].invisible = TRUE;

    if (berry->dry)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_DRY]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_DRY]].invisible = TRUE;

    if (berry->sweet)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SWEET]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SWEET]].invisible = TRUE;

    if (berry->bitter)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_BITTER]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_BITTER]].invisible = TRUE;

    if (berry->sour)
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SOUR]].invisible = FALSE;
    else
        gSprites[sBerryTag->flavorCircleIds[FLAVOR_SOUR]].invisible = TRUE;
}

void DestroyFlavorCircleSprites(void)
{
    u16 i;

    for (i = 0; i < FLAVOR_COUNT; i++)
        DestroySprite(&gSprites[sBerryTag->flavorCircleIds[i]]);
}

void PrepareToCloseBerryTagScreen(u8 taskId)
{
    PlaySE(SE_SELECT);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
    gTasks[taskId].func = Task_CloseBerryTagScreen;
}

void Task_CloseBerryTagScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyBerrySprite();
        DestroyFlavorCircleSprites();
        Free(sBerryTag);
        FreeAllWindowBuffers();
        SetMainCallback2(bag_menu_mail_related);
        DestroyTask(taskId);
    }
}

void Task_HandleInput(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        u16 arrowKeys = JOY_REPEAT(DPAD_ANY);
        if (arrowKeys == DPAD_UP)
            TryChangeDisplayedBerry(taskId, -1);
        else if (arrowKeys == DPAD_DOWN)
            TryChangeDisplayedBerry(taskId, 1);
        else if (JOY_NEW(A_BUTTON | B_BUTTON))
            PrepareToCloseBerryTagScreen(taskId);
    }
}

void TryChangeDisplayedBerry(u8 taskId, s8 toMove)
{
    s16 *data = gTasks[taskId].data;
    s16 currPocketPosition = gBagPosition.scrollPosition[BERRIES_POCKET] + gBagPosition.cursorPosition[BERRIES_POCKET];
    u32 newPocketPosition = currPocketPosition + toMove;
    if (newPocketPosition < ITEM_TO_BERRY(MAX_BERRY_INDEX) && BagGetItemIdByPocketPosition(POCKET_BERRIES, newPocketPosition) != ITEM_NONE)
    {
        if (toMove < 0)
            tBgOp = BG_COORD_SUB;
        else
            tBgOp = BG_COORD_ADD;

        tBerryY = 0;
        PlaySE(SE_SELECT);
        HandleBagCursorPositionChange(toMove);
        gTasks[taskId].func = Task_DisplayAnotherBerry;
    }
}

void HandleBagCursorPositionChange(s8 toMove)
{
    u16 *scrollPos = &gBagPosition.scrollPosition[BERRIES_POCKET];
    u16 *cursorPos = &gBagPosition.cursorPosition[BERRIES_POCKET];
    if (toMove > 0)
    {
        if (*cursorPos < 4 || BagGetItemIdByPocketPosition(POCKET_BERRIES, *scrollPos + 8) == 0)
            *cursorPos += toMove;
        else
            *scrollPos += toMove;
    }
    else
    {
        if (*cursorPos > 3 || *scrollPos == 0)
            *cursorPos += toMove;
        else
            *scrollPos += toMove;
    }

    sBerryTag->berryId = ItemIdToBerryType(BagGetItemIdByPocketPosition(POCKET_BERRIES, *scrollPos + *cursorPos));
}

__attribute__((naked)) void Task_DisplayAnotherBerry(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _081786A8\n\t"
        "	adds r6, r0, r1\n\t"
        "	ldrh r0, [r6]\n\t"
        "	adds r0, #0x10\n\t"
        "	movs r1, #0xff\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r6]\n\t"
        "	movs r1, #2\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _081786E0\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r6, r2]\n\t"
        "	cmp r0, #0x70\n\t"
        "	beq _08178740\n\t"
        "	cmp r0, #0x70\n\t"
        "	bgt _081786B6\n\t"
        "	cmp r0, #0x40\n\t"
        "	beq _081786D2\n\t"
        "	cmp r0, #0x40\n\t"
        "	bgt _081786AC\n\t"
        "	cmp r0, #0x30\n\t"
        "	beq _08178750\n\t"
        "	b _0817875E\n\t"
        "	.align 2, 0\n\t"
        "_081786A8: .4byte gUnknown_3005B68\n\t"
        "_081786AC:\n\t"
        "	cmp r0, #0x50\n\t"
        "	beq _08178746\n\t"
        "	cmp r0, #0x60\n\t"
        "	beq _081786D8\n\t"
        "	b _0817875E\n\t"
        "_081786B6:\n\t"
        "	cmp r0, #0xa0\n\t"
        "	beq _081786DC\n\t"
        "	cmp r0, #0xa0\n\t"
        "	bgt _081786C8\n\t"
        "	cmp r0, #0x80\n\t"
        "	beq _0817873A\n\t"
        "	cmp r0, #0x90\n\t"
        "	beq _08178730\n\t"
        "	b _0817875E\n\t"
        "_081786C8:\n\t"
        "	cmp r0, #0xb0\n\t"
        "	beq _0817872A\n\t"
        "	cmp r0, #0xc0\n\t"
        "	beq _08178724\n\t"
        "	b _0817875E\n\t"
        "_081786D2:\n\t"
        "	bl PrintBerryNumberAndName\n\t"
        "	b _0817875E\n\t"
        "_081786D8:\n\t"
        "	movs r0, #1\n\t"
        "	b _08178752\n\t"
        "_081786DC:\n\t"
        "	movs r0, #2\n\t"
        "	b _08178752\n\t"
        "_081786E0:\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	cmp r0, #0x70\n\t"
        "	beq _08178736\n\t"
        "	cmp r0, #0x70\n\t"
        "	bgt _08178704\n\t"
        "	cmp r0, #0x40\n\t"
        "	beq _08178724\n\t"
        "	cmp r0, #0x40\n\t"
        "	bgt _081786FA\n\t"
        "	cmp r0, #0x30\n\t"
        "	beq _08178720\n\t"
        "	b _0817875E\n\t"
        "_081786FA:\n\t"
        "	cmp r0, #0x50\n\t"
        "	beq _0817872A\n\t"
        "	cmp r0, #0x60\n\t"
        "	beq _08178730\n\t"
        "	b _0817875E\n\t"
        "_08178704:\n\t"
        "	cmp r0, #0xa0\n\t"
        "	beq _08178746\n\t"
        "	cmp r0, #0xa0\n\t"
        "	bgt _08178716\n\t"
        "	cmp r0, #0x80\n\t"
        "	beq _0817873A\n\t"
        "	cmp r0, #0x90\n\t"
        "	beq _08178740\n\t"
        "	b _0817875E\n\t"
        "_08178716:\n\t"
        "	cmp r0, #0xb0\n\t"
        "	beq _08178750\n\t"
        "	cmp r0, #0xc0\n\t"
        "	beq _0817875A\n\t"
        "	b _0817875E\n\t"
        "_08178720:\n\t"
        "	movs r0, #2\n\t"
        "	b _08178752\n\t"
        "_08178724:\n\t"
        "	bl PrintBerryDescription2\n\t"
        "	b _0817875E\n\t"
        "_0817872A:\n\t"
        "	bl PrintBerryDescription1\n\t"
        "	b _0817875E\n\t"
        "_08178730:\n\t"
        "	bl SetFlavorCirclesVisiblity\n\t"
        "	b _0817875E\n\t"
        "_08178736:\n\t"
        "	movs r0, #1\n\t"
        "	b _08178752\n\t"
        "_0817873A:\n\t"
        "	bl PrintBerryFirmness\n\t"
        "	b _0817875E\n\t"
        "_08178740:\n\t"
        "	bl sub_0817804C\n\t"
        "	b _0817875E\n\t"
        "_08178746:\n\t"
        "	bl DestroyBerrySprite\n\t"
        "	bl CreateBerrySprite\n\t"
        "	b _0817875E\n\t"
        "_08178750:\n\t"
        "	movs r0, #0\n\t"
        "_08178752:\n\t"
        "	movs r1, #0\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	b _0817875E\n\t"
        "_0817875A:\n\t"
        "	bl PrintBerryNumberAndName\n\t"
        "_0817875E:\n\t"
        "	movs r2, #2\n\t"
        "	ldrsh r0, [r6, r2]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08178770\n\t"
        "	ldrh r0, [r6]\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	b _08178772\n\t"
        "_08178770:\n\t"
        "	ldrh r5, [r6]\n\t"
        "_08178772:\n\t"
        "	ldr r2, _081787E4\n\t"
        "	ldr r3, _081787E8\n\t"
        "	ldr r0, [r3]\n\t"
        "	ldr r1, _081787EC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r5, [r0, #0x26]\n\t"
        "	movs r4, #0\n\t"
        "	adds r7, r2, #0\n\t"
        "	ldr r2, _081787F0\n\t"
        "_0817878E:\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	strh r5, [r0, #0x26]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	cmp r4, #4\n\t"
        "	bls _0817878E\n\t"
        "	movs r4, #0x80\n\t"
        "	lsls r4, r4, #5\n\t"
        "	ldrb r2, [r6, #2]\n\t"
        "	movs r0, #1\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	ldrb r2, [r6, #2]\n\t"
        "	movs r0, #2\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r6, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _081787DA\n\t"
        "	ldr r0, _081787F4\n\t"
        "	mov r2, r8\n\t"
        "	lsls r1, r2, #2\n\t"
        "	add r1, r8\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _081787F8\n\t"
        "	str r0, [r1]\n\t"
        "_081787DA:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_081787E4: .4byte gSprites\n\t"
        "_081787E8: .4byte sBerryTag\n\t"
        "_081787EC: .4byte 0x00001802\n\t"
        "_081787F0: .4byte 0x00001803\n\t"
        "_081787F4: .4byte gTasks\n\t"
        "_081787F8: .4byte Task_HandleInput + 1\n\t"
        ".syntax divided\n\t"
    );
}
