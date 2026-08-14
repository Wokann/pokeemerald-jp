#include "global.h"
#include "field_effect.h"
#include "sprite.h"
#include "main.h"
#include "task.h"

__attribute__((naked)) u32 FieldEffectStart(u8 id)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FieldEffectActiveListAdd\n\t"
        "	ldr r0, _080B52B0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldr r0, [r4]\n\t"
        "	str r0, [sp]\n\t"
        "	add r4, sp, #4\n\t"
        "	ldr r5, _080B52B4\n\t"
        "_080B528E:\n\t"
        "	ldr r0, [sp]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldr r2, [r0]\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl _call_via_r2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080B528E\n\t"
        "	ldr r0, [sp, #4]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080B52B0: .4byte 0x08289F5C\n\t"
        "_080B52B4: .4byte 0x08536E9C\n\t"

        ".syntax divided\n\t"

    );
}


__attribute__((naked)) bool8 FieldEffectCmd_loadtiles(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r1, #1\n\t"
        "	str r1, [r0]\n\t"
        "	bl FieldEffectScript_LoadTiles\n\t"
        "	movs r0, #1\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 FieldEffectCmd_loadfadedpal(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r1, #1\n\t"
        "	str r1, [r0]\n\t"
        "	bl FieldEffectScript_LoadFadedPalette\n\t"
        "	movs r0, #1\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 FieldEffectCmd_loadpal(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r1, #1\n\t"
        "	str r1, [r0]\n\t"
        "	bl FieldEffectScript_LoadPalette\n\t"
        "	movs r0, #1\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 FieldEffectCmd_callnative(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r2, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	str r2, [r0]\n\t"
        "	bl FieldEffectScript_CallNative\n\t"
        "	movs r0, #1\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 FieldEffectCmd_end(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	movs r0, #0\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 FieldEffectCmd_loadgfx_callnative(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FieldEffectScript_LoadTiles\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FieldEffectScript_LoadFadedPalette\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl FieldEffectScript_CallNative\n\t"
        "	movs r0, #1\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 FieldEffectCmd_loadtiles_callnative(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FieldEffectScript_LoadTiles\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl FieldEffectScript_CallNative\n\t"
        "	movs r0, #1\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 FieldEffectCmd_loadfadedpal_callnative(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "	str r0, [r4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FieldEffectScript_LoadFadedPalette\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl FieldEffectScript_CallNative\n\t"
        "	movs r0, #1\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u32 FieldEffectScript_ReadWord(u8 **script)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldrb r0, [r2]\n\t"
        "	ldrb r1, [r2, #1]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r2, #2]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r2, #3]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FieldEffectScript_LoadTiles(u8 **script)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl FieldEffectScript_ReadWord\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrh r0, [r5, #6]\n\t"
        "	bl GetSpriteTileStartByTag\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ldr r1, _080B53C0\n\t"
        "	cmp r0, r1\n\t"
        "	bne _080B53B2\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl LoadSpriteSheet\n\t"
        "_080B53B2:\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #4\n\t"
        "	str r0, [r4]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B53C0: .4byte 0xFFFF0000\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FieldEffectScript_LoadFadedPalette(u8 **script)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	bl FieldEffectScript_ReadWord\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl LoadSpritePalette\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	bl IndexOfSpritePaletteTag\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl UpdateSpritePaletteWithWeather\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, #4\n\t"
        "	str r0, [r5]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FieldEffectScript_LoadPalette(u8 **script)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl FieldEffectScript_ReadWord\n\t"
        "	bl LoadSpritePalette\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #4\n\t"
        "	str r0, [r4]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FieldEffectScript_CallNative(u8 **script, u32 *val)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl FieldEffectScript_ReadWord\n\t"
        "	bl _call_via_r0\n\t"
        "	str r0, [r5]\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #4\n\t"
        "	str r0, [r4]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"

        ".syntax divided\n\t"

    );
}


__attribute__((naked)) void FieldEffectFreeGraphicsResources(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r1, #0x40\n\t"
        "	ldrh r5, [r1]\n\t"
        "	ldrb r4, [r0, #5]\n\t"
        "	lsrs r4, r4, #4\n\t"
        "	bl DestroySprite\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl FieldEffectFreeTilesIfUnused\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FieldEffectFreePaletteIfUnused\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FieldEffectStop(struct Sprite *sprite, u8 id)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r4, r1, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl FieldEffectFreeGraphicsResources\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FieldEffectActiveListRemove\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FieldEffectFreeTilesIfUnused(u16 tileStart)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetSpriteTileTagByTileStart\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r3, r0, #0x10\n\t"
        "	ldr r0, _080B54B8\n\t"
        "	cmp r3, r0\n\t"
        "	beq _080B54B0\n\t"
        "	movs r2, #0\n\t"
        "	ldr r5, _080B54BC\n\t"
        "_080B5476:\n\t"
        "	lsls r0, r2, #4\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r0, r5\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B54A0\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x3f\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x19\n\t"
        "	cmp r0, #0\n\t"
        "	bge _080B54A0\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x40\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _080B54B0\n\t"
        "_080B54A0:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0x3f\n\t"
        "	bls _080B5476\n\t"
        "	adds r0, r3, #0\n\t"
        "	bl FreeSpriteTilesByTag\n\t"
        "_080B54B0:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B54B8: .4byte 0x0000FFFF\n\t"
        "_080B54BC: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FieldEffectFreePaletteIfUnused(u8 paletteNum)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetSpritePaletteTagByPaletteNum\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	ldr r0, _080B5510\n\t"
        "	cmp r5, r0\n\t"
        "	beq _080B5508\n\t"
        "	movs r2, #0\n\t"
        "	ldr r6, _080B5514\n\t"
        "	adds r3, r4, #0\n\t"
        "_080B54DC:\n\t"
        "	lsls r0, r2, #4\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r0, r6\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080B54F8\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	cmp r0, r3\n\t"
        "	beq _080B5508\n\t"
        "_080B54F8:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0x3f\n\t"
        "	bls _080B54DC\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl FreeSpritePaletteByTag\n\t"
        "_080B5508:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080B5510: .4byte 0x0000FFFF\n\t"
        "_080B5514: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

