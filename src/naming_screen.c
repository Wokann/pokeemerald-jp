#include "global.h"
#include "bg.h"
#include "constants/characters.h"
#include "graphics.h"
#include "naming_screen.h"
#include "sprite.h"
#include "strings.h"
#include "window.h"

enum
{
    WIN_KB_PAGE_1,
    WIN_KB_PAGE_2,
    WIN_TEXT_ENTRY,
    WIN_TEXT_ENTRY_BOX,
    WIN_BANNER,
    WIN_COUNT,
};

enum
{
    KBPAGE_SYMBOLS,
    KBPAGE_LETTERS_UPPER,
    KBPAGE_LETTERS_LOWER,
    KBPAGE_COUNT,
};

enum
{
    KEYBOARD_LETTERS_LOWER,
    KEYBOARD_LETTERS_UPPER,
    KEYBOARD_SYMBOLS,
};

enum
{
    PAGE_SWAP_UPPER,
    PAGE_SWAP_OTHERS,
    PAGE_SWAP_LOWER,
};

enum
{
    PAGE_MAPPING_BOX_OR_MON,
    PAGE_MAPPING_PLAYER_OR_WALDA,
    PAGE_MAPPING_COUNT,
};

__attribute__((naked)) void DoNamingScreen(u8 templateNum, u8 *destBuffer, u16 monSpecies, u16 monGender, u32 monPersonality, MainCallback returnCallback)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	mov r8, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r5, r2, #0x10\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r6, r3, #0x10\n\t"
        "	ldr r4, _080E2270\n\t"
        "	movs r0, #0xf2\n\t"
        "	lsls r0, r0, #5\n\t"
        "	bl Alloc\n\t"
        "	str r0, [r4]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E2274\n\t"
        "	ldr r0, [sp, #0x1c]\n\t"
        "	bl SetMainCallback2\n\t"
        "	b _080E22AE\n\t"
        "	.align 2, 0\n\t"
        "_080E2270: .4byte gUnknown_2039C34\n\t"
        "_080E2274:\n\t"
        "	ldr r1, _080E22B8\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r7, [r0]\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _080E22BC\n\t"
        "	adds r1, r0, r2\n\t"
        "	strh r5, [r1]\n\t"
        "	adds r2, #2\n\t"
        "	adds r1, r0, r2\n\t"
        "	strh r6, [r1]\n\t"
        "	ldr r1, _080E22C0\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldr r1, [sp, #0x18]\n\t"
        "	str r1, [r2]\n\t"
        "	ldr r2, _080E22C4\n\t"
        "	adds r1, r0, r2\n\t"
        "	mov r2, r8\n\t"
        "	str r2, [r1]\n\t"
        "	ldr r1, _080E22C8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r2, [sp, #0x1c]\n\t"
        "	str r2, [r0]\n\t"
        "	cmp r7, #0\n\t"
        "	bne _080E22A8\n\t"
        "	bl StartTimer1\n\t"
        "_080E22A8:\n\t"
        "	ldr r0, _080E22CC\n\t"
        "	bl SetMainCallback2\n\t"
        "_080E22AE:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E22B8: .4byte 0x00001E2C\n\t"
        "_080E22BC: .4byte 0x00001E34\n\t"
        "_080E22C0: .4byte 0x00001E38\n\t"
        "_080E22C4: .4byte 0x00001E30\n\t"
        "_080E22C8: .4byte 0x00001E3C\n\t"
        "_080E22CC: .4byte C2_NamingScreen + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void C2_NamingScreen(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E22EC\n\t"
        "	movs r1, #0x87\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #7\n\t"
        "	bhi _080E2368\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080E22F0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_080E22EC: .4byte gMain\n\t"
        "_080E22F0: .4byte _080E22F4\n\t"
        "_080E22F4:\n\t"
        "	.4byte _080E2314\n\t"
        "	.4byte _080E231E\n\t"
        "	.4byte _080E2324\n\t"
        "	.4byte _080E232A\n\t"
        "	.4byte _080E2334\n\t"
        "	.4byte _080E233A\n\t"
        "	.4byte _080E2340\n\t"
        "	.4byte _080E2346\n\t"
        "_080E2314:\n\t"
        "	bl NamingScreen_TurnOffScreen\n\t"
        "	bl NamingScreen_Init\n\t"
        "	b _080E2352\n\t"
        "_080E231E:\n\t"
        "	bl NamingScreen_InitBGs\n\t"
        "	b _080E2352\n\t"
        "_080E2324:\n\t"
        "	bl ResetPaletteFade\n\t"
        "	b _080E2352\n\t"
        "_080E232A:\n\t"
        "	bl ResetSpriteData\n\t"
        "	bl FreeAllSpritePalettes\n\t"
        "	b _080E2352\n\t"
        "_080E2334:\n\t"
        "	bl ResetTasks\n\t"
        "	b _080E2352\n\t"
        "_080E233A:\n\t"
        "	bl choose_name_or_words_screen_apply_bg_pals\n\t"
        "	b _080E2352\n\t"
        "_080E2340:\n\t"
        "	bl choose_name_or_words_screen_load_bg_tile_patterns\n\t"
        "	b _080E2352\n\t"
        "_080E2346:\n\t"
        "	bl sub_080E31EC\n\t"
        "	bl UpdatePaletteFade\n\t"
        "	bl SetCursorPos\n\t"
        "_080E2352:\n\t"
        "	ldr r1, _080E2364\n\t"
        "	movs r0, #0x87\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	b _080E2370\n\t"
        "	.align 2, 0\n\t"
        "_080E2364: .4byte gMain\n\t"
        "_080E2368:\n\t"
        "	bl sub_080E4450\n\t"
        "	bl sub_080E265C\n\t"
        "_080E2370:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void NamingScreen_Init(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r5, _080E2434\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E2438\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r3, _080E243C\n\t"
        "	adds r0, r1, r3\n\t"
        "	movs r4, #0\n\t"
        "	strh r2, [r0]\n\t"
        "	adds r3, #2\n\t"
        "	adds r0, r1, r3\n\t"
        "	strh r2, [r0]\n\t"
        "	ldr r0, _080E2440\n\t"
        "	adds r2, r1, r0\n\t"
        "	movs r3, #1\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r2]\n\t"
        "	ldr r0, _080E2444\n\t"
        "	adds r2, r1, r0\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r2]\n\t"
        "	movs r2, #0xf1\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r1, r1, r2\n\t"
        "	strb r4, [r1]\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E2448\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r3, [r0]\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r6, _080E244C\n\t"
        "	adds r3, r1, r6\n\t"
        "	ldr r2, _080E2450\n\t"
        "	ldr r4, _080E2454\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r3]\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	ldr r2, _080E2458\n\t"
        "	adds r1, r1, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r2, [r5]\n\t"
        "	adds r0, r2, r6\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsrs r0, r0, #1\n\t"
        "	movs r1, #0xe\n\t"
        "	subs r1, r1, r0\n\t"
        "	ldr r0, _080E245C\n\t"
        "	adds r3, r2, r0\n\t"
        "	strh r1, [r3]\n\t"
        "	adds r2, r2, r4\n\t"
        "	ldrb r0, [r2]\n\t"
        "	cmp r0, #4\n\t"
        "	bne _080E23F2\n\t"
        "	adds r0, r1, #1\n\t"
        "	strh r0, [r3]\n\t"
        "_080E23F2:\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r4, _080E2460\n\t"
        "	ldrh r1, [r4]\n\t"
        "	ldr r2, _080E2464\n\t"
        "	adds r0, r0, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r3, #0xc0\n\t"
        "	lsls r3, r3, #5\n\t"
        "	adds r0, r0, r3\n\t"
        "	movs r1, #0xff\n\t"
        "	movs r2, #0x10\n\t"
        "	bl memset\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r0, r1, r6\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E242A\n\t"
        "	movs r2, #0xc0\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldr r3, _080E2468\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl StringCopy\n\t"
        "_080E242A:\n\t"
        "	movs r0, #0x10\n\t"
        "	strh r0, [r4]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E2434: .4byte gUnknown_2039C34\n\t"
        "_080E2438: .4byte 0x00001E10\n\t"
        "_080E243C: .4byte 0x00001E18\n\t"
        "_080E2440: .4byte 0x00001E1C\n\t"
        "_080E2444: .4byte 0x00001E1E\n\t"
        "_080E2448: .4byte 0x00001E21\n\t"
        "_080E244C: .4byte 0x00001E28\n\t"
        "_080E2450: .4byte sNamingScreenTemplates\n\t"
        "_080E2454: .4byte 0x00001E2C\n\t"
        "_080E2458: .4byte 0x00001E22\n\t"
        "_080E245C: .4byte 0x00001E16\n\t"
        "_080E2460: .4byte gKeyRepeatStartDelay\n\t"
        "_080E2464: .4byte 0x00001E25\n\t"
        "_080E2468: .4byte 0x00001E30\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E246C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	movs r3, #0\n\t"
        "	ldr r4, _080E24A8\n\t"
        "	movs r5, #5\n\t"
        "	rsbs r5, r5, #0\n\t"
        "_080E2476:\n\t"
        "	lsls r0, r3, #4\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r2, r0, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E2490\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "_080E2490:\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	cmp r3, #0x3f\n\t"
        "	bls _080E2476\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_080E3320\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E24A8: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void NamingScreen_InitBGs(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	movs r3, #0xc0\n\t"
        "	lsls r3, r3, #0x13\n\t"
        "	movs r4, #0xc0\n\t"
        "	lsls r4, r4, #9\n\t"
        "	add r0, sp, #0xc\n\t"
        "	mov r8, r0\n\t"
        "	add r2, sp, #8\n\t"
        "	movs r6, #0\n\t"
        "	ldr r1, _080E2640\n\t"
        "	movs r5, #0x80\n\t"
        "	lsls r5, r5, #5\n\t"
        "	ldr r7, _080E2644\n\t"
        "	movs r0, #0x81\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	mov ip, r0\n\t"
        "_080E24D2:\n\t"
        "	strh r6, [r2]\n\t"
        "	add r0, sp, #8\n\t"
        "	str r0, [r1]\n\t"
        "	str r3, [r1, #4]\n\t"
        "	str r7, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	adds r3, r3, r5\n\t"
        "	subs r4, r4, r5\n\t"
        "	cmp r4, r5\n\t"
        "	bhi _080E24D2\n\t"
        "	strh r6, [r2]\n\t"
        "	add r2, sp, #8\n\t"
        "	str r2, [r1]\n\t"
        "	str r3, [r1, #4]\n\t"
        "	lsrs r0, r4, #1\n\t"
        "	mov r2, ip\n\t"
        "	orrs r0, r2\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	movs r0, #0xe0\n\t"
        "	lsls r0, r0, #0x13\n\t"
        "	movs r3, #0x80\n\t"
        "	lsls r3, r3, #3\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp, #0xc]\n\t"
        "	ldr r2, _080E2640\n\t"
        "	mov r1, r8\n\t"
        "	str r1, [r2]\n\t"
        "	str r0, [r2, #4]\n\t"
        "	lsrs r0, r3, #2\n\t"
        "	movs r1, #0x85\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r2, #8]\n\t"
        "	ldr r0, [r2, #8]\n\t"
        "	movs r1, #0xa0\n\t"
        "	lsls r1, r1, #0x13\n\t"
        "	add r0, sp, #8\n\t"
        "	strh r4, [r0]\n\t"
        "	str r0, [r2]\n\t"
        "	str r1, [r2, #4]\n\t"
        "	lsrs r3, r3, #1\n\t"
        "	movs r0, #0x81\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	orrs r3, r0\n\t"
        "	str r3, [r2, #8]\n\t"
        "	ldr r0, [r2, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0\n\t"
        "	bl ResetBgsAndClearDma3BusyFlags\n\t"
        "	ldr r1, _080E2648\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #4\n\t"
        "	bl InitBgsFromTemplates\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgX\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl ChangeBgY\n\t"
        "	bl InitStandardTextBoxWindows\n\t"
        "	bl sub_08196DF4\n\t"
        "_080E25A0:\n\t"
        "	lsls r0, r4, #3\n\t"
        "	ldr r1, _080E264C\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl AddWindow\n\t"
        "	ldr r5, _080E2650\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r2, _080E2654\n\t"
        "	adds r1, r1, r2\n\t"
        "	adds r1, r1, r4\n\t"
        "	strb r0, [r1]\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #4\n\t"
        "	bls _080E25A0\n\t"
        "	movs r1, #0x82\n\t"
        "	lsls r1, r1, #5\n\t"
        "	movs r0, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r1, #0xc8\n\t"
        "	lsls r1, r1, #3\n\t"
        "	movs r0, #0x50\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r1, _080E2658\n\t"
        "	movs r0, #0x52\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r1, [r5]\n\t"
        "	movs r0, #1\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	ldr r1, [r5]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #2\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	ldr r1, [r5]\n\t"
        "	movs r2, #0x80\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r0, #3\n\t"
        "	bl SetBgTilemapBuffer\n\t"
        "	movs r4, #0x20\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl FillBgTilemapBufferRect_Palette0\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl FillBgTilemapBufferRect_Palette0\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl FillBgTilemapBufferRect_Palette0\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E2640: .4byte 0x040000D4\n\t"
        "_080E2644: .4byte 0x81000800\n\t"
        "_080E2648: .4byte sBgTemplates\n\t"
        "_080E264C: .4byte sWindowTemplates\n\t"
        "_080E2650: .4byte gUnknown_2039C34\n\t"
        "_080E2654: .4byte 0x00001E11\n\t"
        "_080E2658: .4byte 0x0000080C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E265C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E2670\n\t"
        "	movs r1, #2\n\t"
        "	bl CreateTask\n\t"
        "	ldr r0, _080E2674\n\t"
        "	bl SetMainCallback2\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E2670: .4byte sub_080E2678 + 1\n\t"
        "_080E2674: .4byte sub_080E474C + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E2678(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E2694\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E2698\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #9\n\t"
        "	bhi _080E2708\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080E269C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_080E2694: .4byte gUnknown_2039C34\n\t"
        "_080E2698: .4byte 0x00001E10\n\t"
        "_080E269C: .4byte _080E26A0\n\t"
        "_080E26A0:\n\t"
        "	.4byte _080E26C8\n\t"
        "	.4byte _080E26D6\n\t"
        "	.4byte _080E26E0\n\t"
        "	.4byte _080E26DC\n\t"
        "	.4byte _080E26E6\n\t"
        "	.4byte _080E26EC\n\t"
        "	.4byte _080E26F2\n\t"
        "	.4byte _080E26F8\n\t"
        "	.4byte _080E26FE\n\t"
        "	.4byte _080E2704\n\t"
        "_080E26C8:\n\t"
        "	bl MainState_BeginFadeIn\n\t"
        "	bl sub_080E246C\n\t"
        "	bl NamingScreen_InitDisplayMode\n\t"
        "	b _080E2708\n\t"
        "_080E26D6:\n\t"
        "	bl MainState_WaitFadeIn\n\t"
        "	b _080E2708\n\t"
        "_080E26DC:\n\t"
        "	bl MainState_MoveToOKButton\n\t"
        "_080E26E0:\n\t"
        "	bl MainState_HandleInput\n\t"
        "	b _080E2708\n\t"
        "_080E26E6:\n\t"
        "	bl MainState_StartPageSwap\n\t"
        "	b _080E2708\n\t"
        "_080E26EC:\n\t"
        "	bl sub_080E2C14\n\t"
        "	b _080E2708\n\t"
        "_080E26F2:\n\t"
        "	bl MainState_6\n\t"
        "	b _080E2708\n\t"
        "_080E26F8:\n\t"
        "	bl sub_080E2B98\n\t"
        "	b _080E2708\n\t"
        "_080E26FE:\n\t"
        "	bl MainState_BeginFadeInOut\n\t"
        "	b _080E2708\n\t"
        "_080E2704:\n\t"
        "	bl MainState_WaitFadeOutAndExit\n\t"
        "_080E2708:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E270C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E2724\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E2728\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E2720\n\t"
        "	cmp r0, #4\n\t"
        "	bne _080E272C\n\t"
        "_080E2720:\n\t"
        "	movs r0, #1\n\t"
        "	b _080E272E\n\t"
        "	.align 2, 0\n\t"
        "_080E2724: .4byte gUnknown_2039C34\n\t"
        "_080E2728: .4byte 0x00001E2C\n\t"
        "_080E272C:\n\t"
        "	movs r0, #0\n\t"
        "_080E272E:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetCurrentPageColumnCount(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r5, _080E2754\n\t"
        "	bl sub_080E270C\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r4, r4, r1\n\t"
        "	adds r4, r4, r5\n\t"
        "	ldrb r0, [r4]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2754: .4byte sPageToNextGfxId\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E2758(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _080E277C\n\t"
        "	bl sub_080E270C\n\t"
        "	ldr r1, _080E2780\n\t"
        "	ldr r2, [r1]\n\t"
        "	ldr r1, _080E2784\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E277C: .4byte sPageToNextKeyboardId\n\t"
        "_080E2780: .4byte gUnknown_2039C34\n\t"
        "_080E2784: .4byte 0x00001E22\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E2788(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _080E27AC\n\t"
        "	bl sub_080E270C\n\t"
        "	ldr r1, _080E27B0\n\t"
        "	ldr r2, [r1]\n\t"
        "	ldr r1, _080E27B4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrb r0, [r1]\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E27AC: .4byte sPageToKeyboardId\n\t"
        "_080E27B0: .4byte gUnknown_2039C34\n\t"
        "_080E27B4: .4byte 0x00001E22\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_BeginFadeIn(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r1, _080E2818\n\t"
        "	movs r0, #3\n\t"
        "	bl sub_080E4490\n\t"
        "	bl sub_080E270C\n\t"
        "	adds r1, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _080E2834\n\t"
        "	ldr r4, _080E281C\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080E2820\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, _080E2824\n\t"
        "	movs r0, #2\n\t"
        "	bl sub_080E4490\n\t"
        "	ldr r1, _080E2828\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_080E4490\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _080E282C\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_080E45D0\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080E2830\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	bl sub_080E45D0\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_080E44A4\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	bl sub_080E44A4\n\t"
        "	b _080E287A\n\t"
        "	.align 2, 0\n\t"
        "_080E2818: .4byte gNamingScreenBackground_Tilemap\n\t"
        "_080E281C: .4byte gUnknown_2039C34\n\t"
        "_080E2820: .4byte 0x00001E22\n\t"
        "_080E2824: .4byte gNamingScreenKeyboardLower_Tilemap\n\t"
        "_080E2828: .4byte gNamingScreenKeyboardUpper_Tilemap\n\t"
        "_080E282C: .4byte 0x00001E12\n\t"
        "_080E2830: .4byte 0x00001E11\n\t"
        "_080E2834:\n\t"
        "	ldr r4, _080E28D4\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _080E28D8\n\t"
        "	adds r0, r0, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, _080E28DC\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_080E4490\n\t"
        "	ldr r1, _080E28E0\n\t"
        "	movs r0, #2\n\t"
        "	bl sub_080E4490\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080E28E4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_080E45D0\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r2, _080E28E8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	bl sub_080E45D0\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_080E44A4\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #1\n\t"
        "	bl sub_080E44A4\n\t"
        "_080E287A:\n\t"
        "	bl sub_080E4510\n\t"
        "	bl sub_080E3E4C\n\t"
        "	bl sub_080E3E24\n\t"
        "	bl sub_080E46E4\n\t"
        "	movs r0, #1\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r0, #2\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r0, #3\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r4, #1\n\t"
        "	rsbs r4, r4, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x10\n\t"
        "	movs r2, #0\n\t"
        "	bl BlendPalettes\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0x10\n\t"
        "	movs r3, #0\n\t"
        "	bl BeginNormalPaletteFade\n\t"
        "	ldr r0, _080E28D4\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080E28EC\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E28D4: .4byte gUnknown_2039C34\n\t"
        "_080E28D8: .4byte 0x00001E22\n\t"
        "_080E28DC: .4byte gNamingScreenKeyboardLower_Tilemap\n\t"
        "_080E28E0: .4byte gNamingScreenKeyboardUpper_Tilemap\n\t"
        "_080E28E4: .4byte 0x00001E11\n\t"
        "_080E28E8: .4byte 0x00001E12\n\t"
        "_080E28EC: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_WaitFadeIn(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E2920\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E2918\n\t"
        "	movs r0, #1\n\t"
        "	bl SetInputState\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_080E3378\n\t"
        "	ldr r0, _080E2924\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080E2928\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "_080E2918:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2920: .4byte gPaletteFade\n\t"
        "_080E2924: .4byte gUnknown_2039C34\n\t"
        "_080E2928: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_HandleInput(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl HandleKeyboardEvent\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_MoveToOKButton(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl IsCursorAnimFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E295E\n\t"
        "	movs r0, #1\n\t"
        "	bl SetInputState\n\t"
        "	bl sub_080E3310\n\t"
        "	ldr r0, _080E2964\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E2968\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	strb r1, [r0]\n\t"
        "_080E295E:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2964: .4byte gUnknown_2039C34\n\t"
        "_080E2968: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_6(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	bl sub_080E437C\n\t"
        "	movs r0, #0\n\t"
        "	bl SetInputState\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_080E3378\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl sub_080E2E78\n\t"
        "	ldr r4, _080E29B4\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080E29B8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _080E29C0\n\t"
        "	bl CalculatePlayerPartyCount\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #5\n\t"
        "	bls _080E29C0\n\t"
        "	bl DisplaySentToPCMessage\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080E29BC\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #7\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	b _080E29CE\n\t"
        "	.align 2, 0\n\t"
        "_080E29B4: .4byte gUnknown_2039C34\n\t"
        "_080E29B8: .4byte 0x00001E2C\n\t"
        "_080E29BC: .4byte 0x00001E10\n\t"
        "_080E29C0:\n\t"
        "	ldr r0, _080E29D4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E29D8\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "_080E29CE:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E29D4: .4byte gUnknown_2039C34\n\t"
        "_080E29D8: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_BeginFadeInOut(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp]\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x10\n\t"
        "	bl BeginNormalPaletteFade\n\t"
        "	ldr r0, _080E2A08\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080E2A0C\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #4\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2A08: .4byte gUnknown_2039C34\n\t"
        "_080E2A0C: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_WaitFadeOutAndExit(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r0, _080E2A64\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #0\n\t"
        "	bne _080E2A5A\n\t"
        "	ldr r4, _080E2A68\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080E2A6C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E2A34\n\t"
        "	bl SeedRngAndSetTrainerId\n\t"
        "_080E2A34:\n\t"
        "	ldr r0, [r4]\n\t"
        "	ldr r1, _080E2A70\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl SetMainCallback2\n\t"
        "	ldr r0, _080E2A74\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl DestroyTask\n\t"
        "	bl FreeAllWindowBuffers\n\t"
        "	ldr r0, [r4]\n\t"
        "	bl Free\n\t"
        "	str r5, [r4]\n\t"
        "_080E2A5A:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2A64: .4byte gPaletteFade\n\t"
        "_080E2A68: .4byte gUnknown_2039C34\n\t"
        "_080E2A6C: .4byte 0x00001E2C\n\t"
        "_080E2A70: .4byte 0x00001E3C\n\t"
        "_080E2A74: .4byte sub_080E2678 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DisplaySentToPCMessage(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	movs r5, #0\n\t"
        "	bl sub_0813B298\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E2AC8\n\t"
        "	ldr r4, _080E2AB4\n\t"
        "	ldr r0, _080E2AB8\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBoxNamePtr\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringCopy\n\t"
        "	ldr r0, _080E2ABC\n\t"
        "	ldr r1, _080E2AC0\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r2, _080E2AC4\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl StringCopy\n\t"
        "	b _080E2B08\n\t"
        "	.align 2, 0\n\t"
        "_080E2AB4: .4byte gStringVar1\n\t"
        "_080E2AB8: .4byte 0x00004036\n\t"
        "_080E2ABC: .4byte gStringVar2\n\t"
        "_080E2AC0: .4byte gUnknown_2039C34\n\t"
        "_080E2AC4: .4byte 0x00001E30\n\t"
        "_080E2AC8:\n\t"
        "	ldr r4, _080E2B70\n\t"
        "	ldr r0, _080E2B74\n\t"
        "	bl VarGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBoxNamePtr\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringCopy\n\t"
        "	ldr r0, _080E2B78\n\t"
        "	ldr r1, _080E2B7C\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r2, _080E2B80\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl StringCopy\n\t"
        "	ldr r4, _080E2B84\n\t"
        "	bl get_unknown_box_id\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBoxNamePtr\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringCopy\n\t"
        "	movs r5, #2\n\t"
        "_080E2B08:\n\t"
        "	ldr r0, _080E2B88\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E2B1A\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "_080E2B1A:\n\t"
        "	ldr r4, _080E2B8C\n\t"
        "	ldr r1, _080E2B90\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StringExpandPlaceholders\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl DrawDialogueFrame\n\t"
        "	ldr r2, _080E2B94\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #1\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	bl GetPlayerTextSpeedDelay\n\t"
        "	adds r3, r0, #0\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl AddTextPrinterParameterized2\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E2B70: .4byte gStringVar1\n\t"
        "_080E2B74: .4byte 0x00004036\n\t"
        "_080E2B78: .4byte gStringVar2\n\t"
        "_080E2B7C: .4byte gUnknown_2039C34\n\t"
        "_080E2B80: .4byte 0x00001E30\n\t"
        "_080E2B84: .4byte gStringVar3\n\t"
        "_080E2B88: .4byte 0x000008AB\n\t"
        "_080E2B8C: .4byte gStringVar4\n\t"
        "_080E2B90: .4byte gUnknown_8565858\n\t"
        "_080E2B94: .4byte gTextFlags\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E2B98(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl RunTextPrinters\n\t"
        "	movs r0, #0\n\t"
        "	bl IsTextPrinterActive\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E2BC2\n\t"
        "	ldr r0, _080E2BC8\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E2BC2\n\t"
        "	ldr r0, _080E2BCC\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E2BD0\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	strb r1, [r0]\n\t"
        "_080E2BC2:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2BC8: .4byte gMain\n\t"
        "_080E2BCC: .4byte gUnknown_2039C34\n\t"
        "_080E2BD0: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_StartPageSwap(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r0, #0\n\t"
        "	bl SetInputState\n\t"
        "	bl sub_080E3510\n\t"
        "	bl StartPageSwapAnim\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_080E3320\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl sub_080E2E78\n\t"
        "	movs r0, #6\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _080E2C0C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E2C10\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #5\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2C0C: .4byte gUnknown_2039C34\n\t"
        "_080E2C10: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E2C14(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	bl IsPageSwapAnimNotInProgress\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E2C56\n\t"
        "	ldr r2, _080E2C60\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r1, _080E2C64\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, [r2]\n\t"
        "	ldr r3, _080E2C68\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r4, [r2]\n\t"
        "	adds r4, r4, r3\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	bl __umodsi3\n\t"
        "	strb r0, [r4]\n\t"
        "	bl sub_080E4648\n\t"
        "	movs r0, #1\n\t"
        "	bl SetInputState\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_080E3320\n\t"
        "_080E2C56:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2C60: .4byte gUnknown_2039C34\n\t"
        "_080E2C64: .4byte 0x00001E10\n\t"
        "_080E2C68: .4byte 0x00001E22\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void StartPageSwapAnim(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _080E2C88\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E2C88: .4byte Task_HandlePageSwapAnim + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_HandlePageSwapAnim(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r5, _080E2CBC\n\t"
        "	ldr r2, _080E2CC0\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r4, r1, r2\n\t"
        "_080E2C9E:\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl _call_via_r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E2C9E\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E2CBC: .4byte sPageSwapAnimStateFuncs\n\t"
        "_080E2CC0: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void IsPageSwapAnimNotInProgress(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E2CD8\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _080E2CDC\n\t"
        "	movs r0, #0\n\t"
        "	b _080E2CDE\n\t"
        "	.align 2, 0\n\t"
        "_080E2CD8: .4byte Task_HandlePageSwapAnim + 1\n\t"
        "_080E2CDC:\n\t"
        "	movs r0, #1\n\t"
        "_080E2CDE:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PageSwapAnimState_Init(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r1, _080E2D00\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r3, _080E2D04\n\t"
        "	adds r2, r1, r3\n\t"
        "	movs r3, #0\n\t"
        "	strh r3, [r2]\n\t"
        "	ldr r2, _080E2D08\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r3, [r1]\n\t"
        "	ldrh r1, [r0, #8]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r0, #8]\n\t"
        "	movs r0, #0\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E2D00: .4byte gUnknown_2039C34\n\t"
        "_080E2D04: .4byte 0x00001E18\n\t"
        "_080E2D08: .4byte 0x00001E1A\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PageSwapAnimState_1(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r5, _080E2D8C\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r2, _080E2D90\n\t"
        "	adds r1, r0, r2\n\t"
        "	str r1, [sp]\n\t"
        "	ldr r1, _080E2D94\n\t"
        "	adds r0, r0, r1\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r0, #4\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	movs r2, #0xa\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	movs r1, #0x28\n\t"
        "	bl Sin\n\t"
        "	ldr r1, [r5]\n\t"
        "	movs r2, #0xf1\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, sp\n\t"
        "	ldr r1, [r1]\n\t"
        "	strh r0, [r1]\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r0, #0x80\n\t"
        "	movs r1, #0xff\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x28\n\t"
        "	bl Sin\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r2, _080E2D98\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, sp\n\t"
        "	ldr r1, [r1]\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x3f\n\t"
        "	ble _080E2D82\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E2D9C\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldrb r3, [r2]\n\t"
        "	adds r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	strh r1, [r2]\n\t"
        "	strh r3, [r0]\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_080E2D82:\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2D8C: .4byte gUnknown_2039C34\n\t"
        "_080E2D90: .4byte 0x00001E1A\n\t"
        "_080E2D94: .4byte 0x00001E18\n\t"
        "_080E2D98: .4byte 0x00001E21\n\t"
        "_080E2D9C: .4byte 0x00001E1C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PageSwapAnimState_2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r5, _080E2E24\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r2, _080E2E28\n\t"
        "	adds r1, r0, r2\n\t"
        "	str r1, [sp]\n\t"
        "	ldr r3, _080E2E2C\n\t"
        "	adds r0, r0, r3\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r0, #4\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r1, #0x28\n\t"
        "	bl Sin\n\t"
        "	ldr r1, [r5]\n\t"
        "	movs r2, #0xf1\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, sp\n\t"
        "	ldr r1, [r1]\n\t"
        "	strh r0, [r1]\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r0, #0x80\n\t"
        "	movs r1, #0xff\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x28\n\t"
        "	bl Sin\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r3, _080E2E30\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r1, [r1]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, sp\n\t"
        "	ldr r1, [r1]\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x7f\n\t"
        "	ble _080E2E1A\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r2, #0xf1\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r1, r0, r2\n\t"
        "	ldrb r2, [r1]\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r3\n\t"
        "	strb r2, [r0]\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_080E2E1A:\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2E24: .4byte gUnknown_2039C34\n\t"
        "_080E2E28: .4byte 0x00001E1A\n\t"
        "_080E2E2C: .4byte 0x00001E18\n\t"
        "_080E2E30: .4byte 0x00001E21\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PageSwapAnimState_Done(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E2E4C\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl DestroyTask\n\t"
        "	movs r0, #0\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E2E4C: .4byte Task_HandlePageSwapAnim + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MoveCursorToOKButton(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E2E70\n\t"
        "	movs r1, #3\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _080E2E74\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r0, #3\n\t"
        "	strh r0, [r1, #8]\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E2E70: .4byte Task_80E39BC + 1\n\t"
        "_080E2E74: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E2E78(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r7, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	ldr r0, _080E2EB0\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _080E2EB4\n\t"
        "	adds r4, r1, r0\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r5, r0\n\t"
        "	bne _080E2EB8\n\t"
        "	cmp r6, #0\n\t"
        "	bne _080E2EB8\n\t"
        "	strh r7, [r4, #0xa]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r4, #0xc]\n\t"
        "	b _080E2EE4\n\t"
        "	.align 2, 0\n\t"
        "_080E2EB0: .4byte Task_80E39BC + 1\n\t"
        "_080E2EB4: .4byte gTasks\n\t"
        "_080E2EB8:\n\t"
        "	cmp r5, #3\n\t"
        "	bne _080E2EC8\n\t"
        "	movs r2, #0xa\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E2EC8\n\t"
        "	cmp r6, #0\n\t"
        "	beq _080E2EE4\n\t"
        "_080E2EC8:\n\t"
        "	ldrh r1, [r4, #8]\n\t"
        "	movs r2, #8\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080E2EDA\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl sub_080E3018\n\t"
        "_080E2EDA:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r7, #0\n\t"
        "	bl sub_080E3040\n\t"
        "_080E2EE4:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_80E39BC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _080E2F54\n\t"
        "	adds r4, r1, r0\n\t"
        "	ldrh r1, [r4, #8]\n\t"
        "	movs r2, #8\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080E2F9E\n\t"
        "	movs r3, #0xc\n\t"
        "	ldrsh r0, [r4, r3]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E2F9E\n\t"
        "	lsls r0, r1, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl sub_080E2FA4\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldrb r3, [r4, #0xe]\n\t"
        "	adds r1, r3, #0\n\t"
        "	adds r2, r3, #0\n\t"
        "	bl MultiplyInvertedPaletteRGBComponents\n\t"
        "	ldrh r1, [r4, #0x12]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E2F38\n\t"
        "	subs r0, r1, #1\n\t"
        "	strh r0, [r4, #0x12]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E2F9E\n\t"
        "_080E2F38:\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r4, #0x12]\n\t"
        "	ldrh r1, [r4, #0x10]\n\t"
        "	movs r3, #0x10\n\t"
        "	ldrsh r0, [r4, r3]\n\t"
        "	cmp r0, #0\n\t"
        "	blt _080E2F62\n\t"
        "	ldrh r2, [r4, #0xe]\n\t"
        "	movs r3, #0xe\n\t"
        "	ldrsh r0, [r4, r3]\n\t"
        "	cmp r0, #0xd\n\t"
        "	bgt _080E2F58\n\t"
        "	adds r0, r2, r1\n\t"
        "	b _080E2F66\n\t"
        "	.align 2, 0\n\t"
        "_080E2F54: .4byte gTasks\n\t"
        "_080E2F58:\n\t"
        "	movs r0, #0x10\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "	ldrh r0, [r4, #0x14]\n\t"
        "	adds r0, #1\n\t"
        "	b _080E2F6C\n\t"
        "_080E2F62:\n\t"
        "	ldrh r3, [r4, #0xe]\n\t"
        "	adds r0, r1, r3\n\t"
        "_080E2F66:\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "	ldrh r2, [r4, #0x14]\n\t"
        "	adds r0, r1, r2\n\t"
        "_080E2F6C:\n\t"
        "	strh r0, [r4, #0x14]\n\t"
        "	movs r3, #0xe\n\t"
        "	ldrsh r0, [r4, r3]\n\t"
        "	ldrh r1, [r4, #0xe]\n\t"
        "	cmp r0, #0x10\n\t"
        "	bne _080E2F8C\n\t"
        "	movs r2, #0x14\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0x16\n\t"
        "	bne _080E2F8C\n\t"
        "	ldr r0, _080E2F88\n\t"
        "	strh r0, [r4, #0x10]\n\t"
        "	b _080E2F9E\n\t"
        "	.align 2, 0\n\t"
        "_080E2F88: .4byte 0x0000FFFC\n\t"
        "_080E2F8C:\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r1, r0, #0x10\n\t"
        "	cmp r1, #0\n\t"
        "	bne _080E2F9E\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	strh r0, [r4, #0xc]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r4, #0x10]\n\t"
        "	strh r1, [r4, #0x14]\n\t"
        "_080E2F9E:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E2FA4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #4\n\t"
        "	bl IndexOfSpritePaletteTag\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x14\n\t"
        "	movs r1, #0x87\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r0, r0, r5\n\t"
        "	add r6, sp, #8\n\t"
        "	strh r0, [r6]\n\t"
        "	movs r0, #6\n\t"
        "	bl IndexOfSpritePaletteTag\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x14\n\t"
        "	adds r0, r0, r5\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, #0xa\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r0, #7\n\t"
        "	bl IndexOfSpritePaletteTag\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x14\n\t"
        "	adds r0, r0, r5\n\t"
        "	add r1, sp, #0xc\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r0, #7\n\t"
        "	bl IndexOfSpritePaletteTag\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x14\n\t"
        "	ldr r1, _080E3014\n\t"
        "	adds r0, r0, r1\n\t"
        "	mov r1, sp\n\t"
        "	adds r1, #0xe\n\t"
        "	strh r0, [r1]\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r6, #0\n\t"
        "	movs r2, #8\n\t"
        "	bl memcpy\n\t"
        "	lsls r4, r4, #1\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E3014: .4byte SPECIAL_RetrieveLotteryNumber\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3018(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl sub_080E2FA4\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	ldr r2, _080E3038\n\t"
        "	lsrs r0, r0, #0xf\n\t"
        "	adds r2, r0, r2\n\t"
        "	ldr r1, _080E303C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r2]\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3038: .4byte gPlttBufferFaded\n\t"
        "_080E303C: .4byte gPlttBufferUnfaded\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3040(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	movs r3, #0\n\t"
        "	strh r1, [r0, #8]\n\t"
        "	strh r2, [r0, #0xa]\n\t"
        "	movs r1, #1\n\t"
        "	strh r1, [r0, #0xc]\n\t"
        "	movs r2, #4\n\t"
        "	strh r2, [r0, #0xe]\n\t"
        "	movs r1, #2\n\t"
        "	strh r1, [r0, #0x10]\n\t"
        "	strh r3, [r0, #0x12]\n\t"
        "	strh r2, [r0, #0x14]\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3060(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r0, #0x3f\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x10\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3078\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "_080E3078:\n\t"
        "	ldrh r1, [r4, #0x36]\n\t"
        "	movs r0, #0xff\n\t"
        "	ands r0, r1\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x3e\n\t"
        "	movs r1, #1\n\t"
        "	ands r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r2, #5\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	ands r2, r1\n\t"
        "	orrs r2, r0\n\t"
        "	strb r2, [r3]\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x13\n\t"
        "	bne _080E30A2\n\t"
        "	movs r0, #4\n\t"
        "	orrs r2, r0\n\t"
        "	strb r2, [r3]\n\t"
        "_080E30A2:\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r0, #4\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E30D2\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	movs r1, #0xff\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E30D2\n\t"
        "	movs r0, #0x2e\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	movs r2, #0x32\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r1, r0\n\t"
        "	bne _080E30D2\n\t"
        "	movs r0, #0x30\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	movs r2, #0x34\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r1, r0\n\t"
        "	beq _080E30DC\n\t"
        "_080E30D2:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r4, #0x3a]\n\t"
        "	strh r0, [r4, #0x3c]\n\t"
        "_080E30DC:\n\t"
        "	ldrh r0, [r4, #0x3c]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r4, #0x3c]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E3104\n\t"
        "	ldrh r1, [r4, #0x3a]\n\t"
        "	ldrh r2, [r4, #0x38]\n\t"
        "	adds r0, r1, r2\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x10\n\t"
        "	beq _080E30FC\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E3100\n\t"
        "_080E30FC:\n\t"
        "	rsbs r0, r1, #0\n\t"
        "	strh r0, [r4, #0x3a]\n\t"
        "_080E3100:\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r4, #0x3c]\n\t"
        "_080E3104:\n\t"
        "	movs r1, #0x36\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r1, #0xff\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E313A\n\t"
        "	ldrh r4, [r4, #0x38]\n\t"
        "	lsls r5, r4, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0x11\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #5\n\t"
        "	bl IndexOfSpritePaletteTag\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	ldr r2, _080E3140\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r3, r5, #0\n\t"
        "	bl MultiplyInvertedPaletteRGBComponents\n\t"
        "_080E313A:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3140: .4byte 0x01010000\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3144(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _080E318C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #8\n\t"
        "	bl memcpy\n\t"
        "	ldrh r1, [r4, #0x2e]\n\t"
        "	movs r2, #0x2e\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3168\n\t"
        "	subs r0, r1, #1\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E3176\n\t"
        "_080E3168:\n\t"
        "	movs r0, #8\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	ldrh r0, [r4, #0x30]\n\t"
        "	adds r0, #1\n\t"
        "	movs r1, #3\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r4, #0x30]\n\t"
        "_080E3176:\n\t"
        "	movs r1, #0x30\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sp\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r4, #0x24]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E318C: .4byte sInputArrowXOffsets\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3190(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _080E31B8\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #8\n\t"
        "	bl memcpy\n\t"
        "	bl GetTextCaretPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldrh r1, [r4, #0x2e]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	cmp r0, r1\n\t"
        "	beq _080E31BC\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	strh r0, [r4, #0x30]\n\t"
        "	b _080E31E2\n\t"
        "	.align 2, 0\n\t"
        "_080E31B8: .4byte sUnderscoreYOffsets\n\t"
        "_080E31BC:\n\t"
        "	movs r1, #0x30\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sp\n\t"
        "	ldrh r0, [r0]\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	ldrh r0, [r4, #0x32]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x32]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #8\n\t"
        "	ble _080E31E4\n\t"
        "	ldrh r0, [r4, #0x30]\n\t"
        "	adds r0, #1\n\t"
        "	movs r1, #3\n\t"
        "	ands r0, r1\n\t"
        "	strh r0, [r4, #0x30]\n\t"
        "	movs r0, #0\n\t"
        "_080E31E2:\n\t"
        "	strh r0, [r4, #0x32]\n\t"
        "_080E31E4:\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E31EC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl CursorInit\n\t"
        "	bl CreatePageSwitcherSprites\n\t"
        "	bl CreateBackOkSprites\n\t"
        "	bl CreateUnderscoreSprites\n\t"
        "	bl CreateInputTargetIcon\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CursorInit(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r0, _080E328C\n\t"
        "	movs r1, #0x1b\n\t"
        "	movs r2, #0x57\n\t"
        "	movs r3, #1\n\t"
        "	bl CreateSprite\n\t"
        "	ldr r5, _080E3290\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r4, _080E3294\n\t"
        "	adds r1, r1, r4\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_080E3320\n\t"
        "	ldr r6, _080E3298\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	ldrb r3, [r1, #5]\n\t"
        "	movs r2, #0xd\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	adds r0, r2, #0\n\t"
        "	ands r0, r3\n\t"
        "	movs r3, #4\n\t"
        "	orrs r0, r3\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	ands r2, r1\n\t"
        "	orrs r2, r3\n\t"
        "	strb r2, [r0, #1]\n\t"
        "	ldr r2, [r5]\n\t"
        "	adds r2, r2, r4\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #1\n\t"
        "	strh r1, [r0, #0x3a]\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #2\n\t"
        "	strh r1, [r0, #0x3a]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl sub_080E329C\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E328C: .4byte sSpriteTemplate_Cursor\n\t"
        "_080E3290: .4byte gUnknown_2039C34\n\t"
        "_080E3294: .4byte 0x00001E23\n\t"
        "_080E3298: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E329C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	ldr r2, _080E32D8\n\t"
        "	ldr r2, [r2]\n\t"
        "	ldr r3, _080E32DC\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrb r3, [r2]\n\t"
        "	lsls r2, r3, #4\n\t"
        "	adds r2, r2, r3\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldr r3, _080E32E0\n\t"
        "	adds r2, r2, r3\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	asrs r0, r0, #0xd\n\t"
        "	adds r0, #0x1b\n\t"
        "	strh r0, [r2, #0x20]\n\t"
        "	lsrs r3, r1, #0x10\n\t"
        "	asrs r1, r1, #0xc\n\t"
        "	adds r1, #0x57\n\t"
        "	strh r1, [r2, #0x22]\n\t"
        "	ldrh r0, [r2, #0x2e]\n\t"
        "	strh r0, [r2, #0x32]\n\t"
        "	ldrh r0, [r2, #0x30]\n\t"
        "	strh r0, [r2, #0x34]\n\t"
        "	strh r4, [r2, #0x2e]\n\t"
        "	strh r3, [r2, #0x30]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E32D8: .4byte gUnknown_2039C34\n\t"
        "_080E32DC: .4byte 0x00001E23\n\t"
        "_080E32E0: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetCursorPos(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r2, _080E3304\n\t"
        "	ldr r2, [r2]\n\t"
        "	ldr r3, _080E3308\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrb r3, [r2]\n\t"
        "	lsls r2, r3, #4\n\t"
        "	adds r2, r2, r3\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldr r3, _080E330C\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldrh r3, [r2, #0x2e]\n\t"
        "	strh r3, [r0]\n\t"
        "	ldrh r0, [r2, #0x30]\n\t"
        "	strh r0, [r1]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E3304: .4byte gUnknown_2039C34\n\t"
        "_080E3308: .4byte 0x00001E23\n\t"
        "_080E330C: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3310(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r0, #0x13\n\t"
        "	movs r1, #2\n\t"
        "	bl sub_080E329C\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3320(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r5, _080E3368\n\t"
        "	ldr r1, _080E336C\n\t"
        "	ldr r4, [r1]\n\t"
        "	ldr r1, _080E3370\n\t"
        "	adds r4, r4, r1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r5\n\t"
        "	ldrh r3, [r2, #0x36]\n\t"
        "	ldr r1, _080E3374\n\t"
        "	ands r1, r3\n\t"
        "	strh r1, [r2, #0x36]\n\t"
        "	ldrb r2, [r4]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	ldrh r2, [r1, #0x36]\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1, #0x36]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	movs r1, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3368: .4byte gSprites\n\t"
        "_080E336C: .4byte gUnknown_2039C34\n\t"
        "_080E3370: .4byte 0x00001E23\n\t"
        "_080E3374: .4byte 0xFFFFFF00\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3378(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r5, _080E33B0\n\t"
        "	ldr r1, _080E33B4\n\t"
        "	ldr r4, [r1]\n\t"
        "	ldr r1, _080E33B8\n\t"
        "	adds r4, r4, r1\n\t"
        "	ldrb r1, [r4]\n\t"
        "	lsls r2, r1, #4\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r5\n\t"
        "	ldrh r3, [r2, #0x36]\n\t"
        "	movs r1, #0xff\n\t"
        "	ands r1, r3\n\t"
        "	strh r1, [r2, #0x36]\n\t"
        "	ldrb r2, [r4]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	ldrh r2, [r1, #0x36]\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1, #0x36]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E33B0: .4byte gSprites\n\t"
        "_080E33B4: .4byte gUnknown_2039C34\n\t"
        "_080E33B8: .4byte 0x00001E23\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E33BC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E33DC\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E33E0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080E33E4\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	bl StartSpriteAnim\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E33DC: .4byte gUnknown_2039C34\n\t"
        "_080E33E0: .4byte 0x00001E23\n\t"
        "_080E33E4: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void IsCursorAnimFinished(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r2, _080E3408\n\t"
        "	ldr r0, _080E340C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E3410\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, #0x3f\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	lsrs r0, r0, #0x1f\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E3408: .4byte gSprites\n\t"
        "_080E340C: .4byte gUnknown_2039C34\n\t"
        "_080E3410: .4byte 0x00001E23\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetKeyRoleAtCursorPos(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #2\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetCursorPos\n\t"
        "	mov r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	cmp r0, #0x12\n\t"
        "	ble _080E3440\n\t"
        "	ldr r0, _080E343C\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	b _080E3442\n\t"
        "	.align 2, 0\n\t"
        "_080E343C: .4byte sButtonKeyRoles\n\t"
        "_080E3440:\n\t"
        "	movs r0, #0\n\t"
        "_080E3442:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreatePageSwitcherSprites(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	ldr r0, _080E34F0\n\t"
        "	movs r1, #0xcc\n\t"
        "	movs r2, #0x58\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _080E34F4\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r2, _080E34F8\n\t"
        "	adds r1, r1, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	lsls r5, r0, #4\n\t"
        "	adds r5, r5, r0\n\t"
        "	lsls r5, r5, #2\n\t"
        "	ldr r0, _080E34FC\n\t"
        "	mov r8, r0\n\t"
        "	add r5, r8\n\t"
        "	ldr r1, _080E3500\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl SetSubspriteTables\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r1, #0x3e\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r6, #4\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r1]\n\t"
        "	ldr r0, _080E3504\n\t"
        "	movs r1, #0xcc\n\t"
        "	movs r2, #0x54\n\t"
        "	movs r3, #1\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r5, #0x3a]\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	add r4, r8\n\t"
        "	ldr r1, _080E3508\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SetSubspriteTables\n\t"
        "	adds r4, #0x3e\n\t"
        "	ldrb r0, [r4]\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r0, _080E350C\n\t"
        "	movs r1, #0xcc\n\t"
        "	movs r2, #0x53\n\t"
        "	movs r3, #2\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r2, r0, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	add r2, r8\n\t"
        "	ldrb r3, [r2, #5]\n\t"
        "	movs r1, #0xd\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r3\n\t"
        "	orrs r1, r6\n\t"
        "	strb r1, [r2, #5]\n\t"
        "	strh r0, [r5, #0x3c]\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r0, [r2]\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r2]\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E34F0: .4byte sSpriteTemplate_PageSwapFrame\n\t"
        "_080E34F4: .4byte gUnknown_2039C34\n\t"
        "_080E34F8: .4byte 0x00001E24\n\t"
        "_080E34FC: .4byte gSprites\n\t"
        "_080E3500: .4byte sSubspriteTable_PageSwapFrame\n\t"
        "_080E3504: .4byte sSpriteTemplate_PageSwapText\n\t"
        "_080E3508: .4byte sSubspriteTable_PageSwapText\n\t"
        "_080E350C: .4byte sSpriteTemplate_PageSwapButton\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3510(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, _080E3534\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldr r1, _080E3538\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080E353C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	strh r1, [r0, #0x2e]\n\t"
        "	ldr r1, _080E3540\n\t"
        "	adds r2, r2, r1\n\t"
        "	ldrb r1, [r2]\n\t"
        "	strh r1, [r0, #0x30]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E3534: .4byte gUnknown_2039C34\n\t"
        "_080E3538: .4byte 0x00001E24\n\t"
        "_080E353C: .4byte gSprites\n\t"
        "_080E3540: .4byte 0x00001E22\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3544(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r5, _080E3568\n\t"
        "_080E354A:\n\t"
        "	movs r1, #0x2e\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl _call_via_r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E354A\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3568: .4byte sPageSwapSpriteFuncs\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E356C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	movs r1, #0x3a\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	lsls r5, r0, #4\n\t"
        "	adds r5, r5, r0\n\t"
        "	lsls r5, r5, #2\n\t"
        "	ldr r1, _080E35B4\n\t"
        "	adds r5, r5, r1\n\t"
        "	movs r2, #0x3c\n\t"
        "	ldrsh r0, [r6, r2]\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	adds r4, r4, r1\n\t"
        "	ldr r0, _080E35B8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E35BC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetCurrentPageColumnCount\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl sub_080E3678\n\t"
        "	ldrh r0, [r6, #0x2e]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r6, #0x2e]\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E35B4: .4byte gSprites\n\t"
        "_080E35B8: .4byte gUnknown_2039C34\n\t"
        "_080E35BC: .4byte 0x00001E22\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E35C0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	movs r0, #0\n\t"
        "	bx lr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E35C4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r3, r0, #0\n\t"
        "	movs r0, #0x3a\n\t"
        "	ldrsh r1, [r3, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r2, _080E3630\n\t"
        "	adds r4, r0, r2\n\t"
        "	movs r0, #0x3c\n\t"
        "	ldrsh r1, [r3, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r5, r0, r2\n\t"
        "	ldrh r0, [r4, #0x26]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #7\n\t"
        "	ble _080E3628\n\t"
        "	ldrh r0, [r3, #0x2e]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r3, #0x2e]\n\t"
        "	ldr r0, _080E3634\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r3, #0x30]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r0, #1\n\t"
        "	movs r1, #3\n\t"
        "	bl __modsi3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetCurrentPageColumnCount\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl sub_080E3678\n\t"
        "_080E3628:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E3630: .4byte gSprites\n\t"
        "_080E3634: .4byte 0x0000FFFC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3638(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r0, #0x3a\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080E3674\n\t"
        "	adds r2, r0, r1\n\t"
        "	adds r3, r2, #0\n\t"
        "	adds r3, #0x3e\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	ldrh r0, [r2, #0x26]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r2, #0x26]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	blt _080E366C\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2, #0x26]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "_080E366C:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E3674: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3678(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	mov r8, r2\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r0, _080E36D0\n\t"
        "	lsls r4, r5, #1\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl IndexOfSpritePaletteTag\n\t"
        "	lsls r0, r0, #4\n\t"
        "	mov r1, r8\n\t"
        "	ldrb r2, [r1, #5]\n\t"
        "	movs r1, #0xf\n\t"
        "	ands r1, r2\n\t"
        "	orrs r1, r0\n\t"
        "	mov r0, r8\n\t"
        "	strb r1, [r0, #5]\n\t"
        "	ldr r0, _080E36D4\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrh r0, [r4]\n\t"
        "	bl GetSpriteTileStartByTag\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r1, #0x40\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r6, #0x42\n\t"
        "	movs r1, #0x3f\n\t"
        "	ands r1, r5\n\t"
        "	ldrb r2, [r6]\n\t"
        "	movs r0, #0x40\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E36D0: .4byte sPageSwapPalTags\n\t"
        "_080E36D4: .4byte sPageSwapGfxTags\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreateBackOkSprites(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	ldr r0, _080E3740\n\t"
        "	movs r1, #0xcc\n\t"
        "	movs r2, #0x74\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r6, _080E3744\n\t"
        "	adds r4, r4, r6\n\t"
        "	ldr r0, _080E3748\n\t"
        "	mov r8, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl SetSubspriteTables\n\t"
        "	adds r4, #0x3e\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r5, #4\n\t"
        "	orrs r0, r5\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r0, _080E374C\n\t"
        "	movs r1, #0xcc\n\t"
        "	movs r2, #0x8c\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	adds r4, r4, r6\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl SetSubspriteTables\n\t"
        "	adds r4, #0x3e\n\t"
        "	ldrb r0, [r4]\n\t"
        "	orrs r0, r5\n\t"
        "	strb r0, [r4]\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3740: .4byte sSpriteTemplate_BackButton\n\t"
        "_080E3744: .4byte gSprites\n\t"
        "_080E3748: .4byte sSubspriteTable_Button\n\t"
        "_080E374C: .4byte sSpriteTemplate_OkButton\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreateUnderscoreSprites(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r5, _080E3808\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r4, _080E380C\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r1, [r0]\n\t"
        "	subs r1, #1\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, #4\n\t"
        "	ldr r0, _080E3810\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	movs r2, #0x38\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	ldr r3, _080E3814\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	movs r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #5]\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r4, r1, r4\n\t"
        "	ldrh r0, [r4]\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, #4\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	movs r5, #0\n\t"
        "	ldr r0, _080E3818\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	cmp r5, r0\n\t"
        "	bhs _080E3800\n\t"
        "	adds r6, r3, #0\n\t"
        "_080E37AE:\n\t"
        "	lsls r1, r4, #0x10\n\t"
        "	asrs r4, r1, #0x10\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #0xa\n\t"
        "	adds r1, r1, r0\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldr r0, _080E381C\n\t"
        "	movs r2, #0x3c\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	movs r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #5]\n\t"
        "	strh r5, [r0, #0x2e]\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	adds r4, #0xa\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	ldr r0, _080E3808\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E3818\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	cmp r5, r0\n\t"
        "	blo _080E37AE\n\t"
        "_080E3800:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3808: .4byte gUnknown_2039C34\n\t"
        "_080E380C: .4byte 0x00001E16\n\t"
        "_080E3810: .4byte sSpriteTemplate_InputArrow\n\t"
        "_080E3814: .4byte gSprites\n\t"
        "_080E3818: .4byte 0x00001E28\n\t"
        "_080E381C: .4byte sSpriteTemplate_Underscore\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreateInputTargetIcon(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080E3840\n\t"
        "	ldr r0, _080E3844\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r2, _080E3848\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #2]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl _call_via_r0\n\t"
        "	pop {r0}\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void TaskDummy3(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3840: .4byte sIconFunctions\n\t"
        "_080E3844: .4byte gUnknown_2039C34\n\t"
        "_080E3848: .4byte 0x00001E28\n\t"
        ".syntax divided\n\t"
    );
}

void TaskDummy2(void) {}
__attribute__((naked)) void NamingScreen_CreatePlayerIcon(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r0, _080E389C\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E38A0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	bl GetPlayerAvatarGraphicsIdByStateIdAndGender\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _080E38A4\n\t"
        "	movs r2, #0\n\t"
        "	str r2, [sp]\n\t"
        "	movs r2, #0x38\n\t"
        "	movs r3, #0x25\n\t"
        "	bl AddPseudoEventObject\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r2, _080E38A8\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	movs r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #5]\n\t"
        "	movs r1, #4\n\t"
        "	bl StartSpriteAnim\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E389C: .4byte gUnknown_2039C34\n\t"
        "_080E38A0: .4byte 0x00001E34\n\t"
        "_080E38A4: .4byte SpriteCallbackDummy + 1\n\t"
        "_080E38A8: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void NamingScreen_CreatePCIcon(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _080E38E0\n\t"
        "	movs r1, #0x38\n\t"
        "	movs r2, #0x29\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _080E38E4\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldr r1, _080E38E8\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SetSubspriteTables\n\t"
        "	ldrb r0, [r4, #5]\n\t"
        "	movs r1, #0xc\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #5]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E38E0: .4byte sSpriteTemplate_PCIcon\n\t"
        "_080E38E4: .4byte gSprites\n\t"
        "_080E38E8: .4byte sSubspriteTable_PCIcon\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void NamingScreen_CreateMonIcon(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	bl LoadMonIconPalettes\n\t"
        "	ldr r0, _080E3934\n\t"
        "	ldr r3, [r0]\n\t"
        "	ldr r1, _080E3938\n\t"
        "	adds r0, r3, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	ldr r1, _080E393C\n\t"
        "	movs r2, #0\n\t"
        "	str r2, [sp]\n\t"
        "	ldr r2, _080E3940\n\t"
        "	adds r3, r3, r2\n\t"
        "	ldr r2, [r3]\n\t"
        "	str r2, [sp, #4]\n\t"
        "	movs r2, #1\n\t"
        "	str r2, [sp, #8]\n\t"
        "	movs r2, #0x38\n\t"
        "	movs r3, #0x28\n\t"
        "	bl CreateMonIcon\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _080E3944\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	movs r2, #0xc\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1, #5]\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3934: .4byte gUnknown_2039C34\n\t"
        "_080E3938: .4byte 0x00001E34\n\t"
        "_080E393C: .4byte SpriteCallbackDummy + 1\n\t"
        "_080E3940: .4byte 0x00001E38\n\t"
        "_080E3944: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void NamingScreen_CreateWandaDadIcon(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r1, _080E3980\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #0x13\n\t"
        "	movs r2, #0x38\n\t"
        "	movs r3, #0x25\n\t"
        "	bl AddPseudoEventObject\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r2, _080E3984\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	movs r2, #0xc\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #5]\n\t"
        "	movs r1, #4\n\t"
        "	bl StartSpriteAnim\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3980: .4byte SpriteCallbackDummy + 1\n\t"
        "_080E3984: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void HandleKeyboardEvent(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	bl GetInputEvent\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r5, r4, #0\n\t"
        "	bl GetKeyRoleAtCursorPos\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r4, #8\n\t"
        "	bne _080E39A6\n\t"
        "	bl sub_080E3AB8\n\t"
        "	b _080E39CC\n\t"
        "_080E39A6:\n\t"
        "	cmp r4, #6\n\t"
        "	bne _080E39B0\n\t"
        "	bl DeleteTextCharacter\n\t"
        "	b _080E39DC\n\t"
        "_080E39B0:\n\t"
        "	cmp r4, #7\n\t"
        "	bne _080E39BA\n\t"
        "	bl sub_080E40A8\n\t"
        "	b _080E39DC\n\t"
        "_080E39BA:\n\t"
        "	cmp r5, #9\n\t"
        "	beq _080E39D8\n\t"
        "	ldr r1, _080E39D4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl _call_via_r1\n\t"
        "_080E39CC:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _080E39DE\n\t"
        "	.align 2, 0\n\t"
        "_080E39D4: .4byte sKeyboardKeyHandlers\n\t"
        "_080E39D8:\n\t"
        "	bl sub_080E3310\n\t"
        "_080E39DC:\n\t"
        "	movs r0, #0\n\t"
        "_080E39DE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void KeyboardKeyHandler_Character(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #3\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl sub_080E2E78\n\t"
        "	cmp r4, #5\n\t"
        "	bne _080E3A1E\n\t"
        "	bl sub_080E4018\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl sub_080E33BC\n\t"
        "	cmp r4, #0\n\t"
        "	beq _080E3A1E\n\t"
        "	movs r0, #2\n\t"
        "	bl SetInputState\n\t"
        "	ldr r0, _080E3A28\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E3A2C\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #3\n\t"
        "	strb r1, [r0]\n\t"
        "_080E3A1E:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E3A28: .4byte gUnknown_2039C34\n\t"
        "_080E3A2C: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void KeyboardKeyHandler_Page(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	bl sub_080E2E78\n\t"
        "	cmp r4, #5\n\t"
        "	beq _080E3A4A\n\t"
        "	movs r0, #0\n\t"
        "	b _080E3A52\n\t"
        "_080E3A4A:\n\t"
        "	bl sub_080E3AB8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "_080E3A52:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void KeyboardKeyHandler_Backspace(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	bl sub_080E2E78\n\t"
        "	cmp r4, #5\n\t"
        "	bne _080E3A72\n\t"
        "	bl DeleteTextCharacter\n\t"
        "_080E3A72:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void KeyboardKeyHandler_OK(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r0, #2\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	bl sub_080E2E78\n\t"
        "	cmp r4, #5\n\t"
        "	beq _080E3A96\n\t"
        "	movs r0, #0\n\t"
        "	b _080E3AAA\n\t"
        "_080E3A96:\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	ldr r0, _080E3AB0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E3AB4\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #6\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "_080E3AAA:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E3AB0: .4byte gUnknown_2039C34\n\t"
        "_080E3AB4: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3AB8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, _080E3AC8\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E3ACC\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #4\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E3AC8: .4byte gUnknown_2039C34\n\t"
        "_080E3ACC: .4byte 0x00001E10\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InputInit(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E3AE0\n\t"
        "	movs r1, #1\n\t"
        "	bl CreateTask\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3AE0: .4byte sub_080E3B34 + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetInputEvent(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E3B00\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _080E3B04\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1, #0xa]\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E3B00: .4byte sub_080E3B34 + 1\n\t"
        "_080E3B04: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetInputState(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _080E3B2C\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _080E3B30\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r4, [r1, #8]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3B2C: .4byte sub_080E3B34 + 1\n\t"
        "_080E3B30: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3B34(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r3, _080E3B5C\n\t"
        "	ldr r2, _080E3B60\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r2, #8\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl _call_via_r1\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3B5C: .4byte sInputFuncs\n\t"
        "_080E3B60: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InputState_2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0, #0xa]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InputState_Enabled(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	ldr r0, _080E3B88\n\t"
        "	ldrh r2, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3B8C\n\t"
        "	movs r0, #5\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	b _080E3BCC\n\t"
        "	.align 2, 0\n\t"
        "_080E3B88: .4byte gMain\n\t"
        "_080E3B8C:\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3B9A\n\t"
        "	movs r0, #6\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	b _080E3BCC\n\t"
        "_080E3B9A:\n\t"
        "	movs r0, #4\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3BA8\n\t"
        "	movs r0, #8\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	b _080E3BCC\n\t"
        "_080E3BA8:\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3BB6\n\t"
        "	movs r0, #9\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	b _080E3BCC\n\t"
        "_080E3BB6:\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3BC6\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	b _080E3BCC\n\t"
        "_080E3BC6:\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl HandleDpadMovement\n\t"
        "_080E3BCC:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3BD0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r2, r0, #0\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2, #0xa]\n\t"
        "	ldr r0, _080E3BF0\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3BEA\n\t"
        "	movs r0, #7\n\t"
        "	strh r0, [r2, #0xa]\n\t"
        "_080E3BEA:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3BF0: .4byte gMain\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void HandleDpadMovement(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #0x2c\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldr r1, _080E3CB8\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0xa\n\t"
        "	bl memcpy\n\t"
        "	add r7, sp, #0xc\n\t"
        "	ldr r1, _080E3CBC\n\t"
        "	adds r0, r7, #0\n\t"
        "	movs r2, #0xa\n\t"
        "	bl memcpy\n\t"
        "	add r0, sp, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	ldr r1, _080E3CC0\n\t"
        "	movs r2, #8\n\t"
        "	bl memcpy\n\t"
        "	add r1, sp, #0x20\n\t"
        "	mov sb, r1\n\t"
        "	ldr r1, _080E3CC4\n\t"
        "	mov r0, sb\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	add r4, sp, #0x28\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #0x2a\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetCursorPos\n\t"
        "	ldr r0, _080E3CC8\n\t"
        "	ldrh r2, [r0, #0x30]\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	lsrs r1, r0, #0x1f\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3C58\n\t"
        "	movs r1, #2\n\t"
        "_080E3C58:\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3C62\n\t"
        "	movs r1, #3\n\t"
        "_080E3C62:\n\t"
        "	movs r0, #0x10\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3C6C\n\t"
        "	movs r1, #4\n\t"
        "_080E3C6C:\n\t"
        "	ldrh r3, [r4]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	mov r2, sp\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrh r2, [r0]\n\t"
        "	adds r0, r3, r2\n\t"
        "	strh r0, [r4]\n\t"
        "	adds r1, r7, r1\n\t"
        "	ldrh r0, [r1]\n\t"
        "	ldrh r1, [r5]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r5]\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bge _080E3C90\n\t"
        "	movs r0, #0x13\n\t"
        "	strh r0, [r4]\n\t"
        "_080E3C90:\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0x13\n\t"
        "	ble _080E3C9C\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4]\n\t"
        "_080E3C9C:\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3CE8\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0x13\n\t"
        "	bne _080E3CCC\n\t"
        "	ldrh r0, [r5]\n\t"
        "	strh r0, [r6, #0xc]\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, r8\n\t"
        "	b _080E3CE4\n\t"
        "	.align 2, 0\n\t"
        "_080E3CB8: .4byte sDpadDeltaX\n\t"
        "_080E3CBC: .4byte sDpadDeltaY\n\t"
        "_080E3CC0: .4byte sKeyRowToButtonRow\n\t"
        "_080E3CC4: .4byte sButtonRowToKeyRow\n\t"
        "_080E3CC8: .4byte gMain\n\t"
        "_080E3CCC:\n\t"
        "	cmp r3, #0x13\n\t"
        "	bne _080E3CE8\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080E3CDC\n\t"
        "	ldrh r0, [r6, #0xc]\n\t"
        "	b _080E3CE6\n\t"
        "_080E3CDC:\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sb\n\t"
        "_080E3CE4:\n\t"
        "	ldrh r0, [r0]\n\t"
        "_080E3CE6:\n\t"
        "	strh r0, [r5]\n\t"
        "_080E3CE8:\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0x13\n\t"
        "	bne _080E3D1E\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bge _080E3CFC\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5]\n\t"
        "_080E3CFC:\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	cmp r0, #2\n\t"
        "	ble _080E3D08\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5]\n\t"
        "_080E3D08:\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E3D16\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r6, #0xc]\n\t"
        "	b _080E3D36\n\t"
        "_080E3D16:\n\t"
        "	cmp r0, #2\n\t"
        "	bne _080E3D36\n\t"
        "	strh r0, [r6, #0xc]\n\t"
        "	b _080E3D36\n\t"
        "_080E3D1E:\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bge _080E3D2A\n\t"
        "	movs r0, #3\n\t"
        "	strh r0, [r5]\n\t"
        "_080E3D2A:\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #3\n\t"
        "	ble _080E3D36\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5]\n\t"
        "_080E3D36:\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl sub_080E329C\n\t"
        "	add sp, #0x2c\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3D50(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	ldr r5, _080E3D98\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r4, _080E3D9C\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r2, _080E3DA0\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r2, [r1, #8]\n\t"
        "	movs r1, #1\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #5\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3D98: .4byte gUnknown_2039C34\n\t"
        "_080E3D9C: .4byte 0x00001E14\n\t"
        "_080E3DA0: .4byte 0x00001E28\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3DA4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x2c\n\t"
        "	ldr r5, _080E3E10\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E3E14\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	ldr r0, _080E3E18\n\t"
        "	adds r1, r1, r0\n\t"
        "	add r0, sp, #0xc\n\t"
        "	bl StringCopy\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E3E1C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, [r0, #8]\n\t"
        "	add r0, sp, #0xc\n\t"
        "	movs r2, #0xf\n\t"
        "	bl StringAppendN\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r4, _080E3E20\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #1\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	add r2, sp, #0xc\n\t"
        "	movs r3, #9\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	add sp, #0x2c\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3E10: .4byte gUnknown_2039C34\n\t"
        "_080E3E14: .4byte 0x00001E34\n\t"
        "_080E3E18: .4byte gSpeciesNames\n\t"
        "_080E3E1C: .4byte 0x00001E28\n\t"
        "_080E3E20: .4byte 0x00001E14\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3E24(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080E3E40\n\t"
        "	ldr r0, _080E3E44\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r2, _080E3E48\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl _call_via_r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void nullsub_10(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3E40: .4byte sDrawTextEntryBoxFuncs\n\t"
        "_080E3E44: .4byte gUnknown_2039C34\n\t"
        "_080E3E48: .4byte 0x00001E2C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E3E4C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _080E3E6C\n\t"
        "	ldr r0, _080E3E70\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r2, _080E3E74\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #3]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	bl _call_via_r0\n\t"
        "	pop {r0}\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InputState_Disabled(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3E6C: .4byte sDrawGenderIconFuncs\n\t"
        "_080E3E70: .4byte gUnknown_2039C34\n\t"
        "_080E3E74: .4byte 0x00001E28\n\t"
        ".syntax divided\n\t"
    );
}

void sub_080E3E78(void) {}
__attribute__((naked)) void sub_080E3E7C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	movs r4, #0\n\t"
        "	ldr r1, _080E3ED4\n\t"
        "	add r0, sp, #0xc\n\t"
        "	bl StringCopy\n\t"
        "	ldr r5, _080E3ED8\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E3EDC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _080E3ECA\n\t"
        "	cmp r0, #0xfe\n\t"
        "	bne _080E3EA6\n\t"
        "	ldr r1, _080E3EE0\n\t"
        "	add r0, sp, #0xc\n\t"
        "	bl StringCopy\n\t"
        "	movs r4, #1\n\t"
        "_080E3EA6:\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E3EE4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r4, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldr r2, _080E3EE8\n\t"
        "	adds r1, r1, r2\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	add r1, sp, #0xc\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0x5b\n\t"
        "	movs r3, #1\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "_080E3ECA:\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E3ED4: .4byte gText_MaleSymbol\n\t"
        "_080E3ED8: .4byte gUnknown_2039C34\n\t"
        "_080E3EDC: .4byte 0x00001E36\n\t"
        "_080E3EE0: .4byte gText_FemaleSymbol\n\t"
        "_080E3EE4: .4byte 0x00001E13\n\t"
        "_080E3EE8: .4byte sGenderColors\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetCharAtKeyboardPos(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	bl sub_080E2788\n\t"
        "	ldr r1, _080E3F1C\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0xe\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x14\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r4, r4, r1\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	asrs r5, r5, #0x10\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r0, [r0]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E3F1C: .4byte sNamingScreenKeyboardText\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetTextCaretPosition(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	movs r2, #0\n\t"
        "	ldr r0, _080E3F48\n\t"
        "	ldr r4, [r0]\n\t"
        "	ldr r3, _080E3F4C\n\t"
        "	adds r1, r4, r3\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldrb r3, [r1, #1]\n\t"
        "	adds r5, r0, #0\n\t"
        "	cmp r2, r3\n\t"
        "	bhs _080E3F5A\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #5\n\t"
        "	adds r1, r4, r0\n\t"
        "_080E3F3C:\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _080E3F50\n\t"
        "	adds r0, r2, #0\n\t"
        "	b _080E3F6A\n\t"
        "	.align 2, 0\n\t"
        "_080E3F48: .4byte gUnknown_2039C34\n\t"
        "_080E3F4C: .4byte 0x00001E28\n\t"
        "_080E3F50:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, r3\n\t"
        "	blo _080E3F3C\n\t"
        "_080E3F5A:\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E3F70\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "_080E3F6A:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E3F70: .4byte 0x00001E28\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPreviousTextCaretPosition(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E3FA0\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldr r1, _080E3FA4\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	subs r0, #1\n\t"
        "	lsls r1, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	ble _080E3FB0\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #5\n\t"
        "	adds r3, r2, r0\n\t"
        "_080E3F90:\n\t"
        "	asrs r2, r1, #0x18\n\t"
        "	adds r0, r3, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _080E3FA8\n\t"
        "	lsrs r0, r1, #0x18\n\t"
        "	b _080E3FB2\n\t"
        "	.align 2, 0\n\t"
        "_080E3FA0: .4byte gUnknown_2039C34\n\t"
        "_080E3FA4: .4byte 0x00001E28\n\t"
        "_080E3FA8:\n\t"
        "	subs r0, r2, #1\n\t"
        "	lsls r1, r0, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	bgt _080E3F90\n\t"
        "_080E3FB0:\n\t"
        "	movs r0, #0\n\t"
        "_080E3FB2:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DeleteTextCharacter(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	bl GetPreviousTextCaretPosition\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r6, _080E4014\n\t"
        "	ldr r0, [r6]\n\t"
        "	movs r5, #0xc0\n\t"
        "	lsls r5, r5, #5\n\t"
        "	adds r0, r0, r5\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	bl sub_080E4510\n\t"
        "	bl sub_080E3E4C\n\t"
        "	movs r0, #3\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, r0, r5\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r1, #0xff\n\t"
        "	strb r1, [r0]\n\t"
        "	bl GetKeyRoleAtCursorPos\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E3FFC\n\t"
        "	cmp r0, #2\n\t"
        "	bne _080E4006\n\t"
        "_080E3FFC:\n\t"
        "	movs r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl sub_080E2E78\n\t"
        "_080E4006:\n\t"
        "	movs r0, #0x17\n\t"
        "	bl PlaySE\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E4014: .4byte gUnknown_2039C34\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4018(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #2\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetCursorPos\n\t"
        "	mov r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl GetCharAtKeyboardPos\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r4, #1\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _080E4048\n\t"
        "	bl sub_080E4110\n\t"
        "	b _080E4050\n\t"
        "_080E4048:\n\t"
        "	cmp r0, #0xfe\n\t"
        "	bne _080E4056\n\t"
        "	bl sub_080E414C\n\t"
        "_080E4050:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	b _080E405C\n\t"
        "_080E4056:\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl AddTextCharacter\n\t"
        "_080E405C:\n\t"
        "	bl sub_080E4510\n\t"
        "	bl sub_080E3E4C\n\t"
        "	movs r0, #3\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	cmp r4, #0\n\t"
        "	beq _080E409C\n\t"
        "	bl GetPreviousTextCaretPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _080E4094\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldr r2, _080E4098\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldrb r1, [r1, #1]\n\t"
        "	subs r1, #1\n\t"
        "	cmp r0, r1\n\t"
        "	bne _080E409C\n\t"
        "	movs r0, #1\n\t"
        "	b _080E409E\n\t"
        "	.align 2, 0\n\t"
        "_080E4094: .4byte gUnknown_2039C34\n\t"
        "_080E4098: .4byte 0x00001E28\n\t"
        "_080E409C:\n\t"
        "	movs r0, #0\n\t"
        "_080E409E:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E40A8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	movs r4, #0\n\t"
        "	bl GetPreviousTextCaretPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	ldr r6, _080E40E0\n\t"
        "	ldr r0, [r6]\n\t"
        "	movs r5, #0xc0\n\t"
        "	lsls r5, r5, #5\n\t"
        "	adds r0, r0, r5\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r1, [r0]\n\t"
        "	ldr r2, _080E40E4\n\t"
        "	ldrb r0, [r2]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _080E40F6\n\t"
        "	ldr r7, _080E40E8\n\t"
        "_080E40CC:\n\t"
        "	ldrb r0, [r2]\n\t"
        "	cmp r1, r0\n\t"
        "	bne _080E40EC\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, r0, r5\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r1, r4, r7\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	b _080E40F6\n\t"
        "	.align 2, 0\n\t"
        "_080E40E0: .4byte gUnknown_2039C34\n\t"
        "_080E40E4: .4byte sCharacterTransformSourceChars\n\t"
        "_080E40E8: .4byte sCharacterTransformTargetChars\n\t"
        "_080E40EC:\n\t"
        "	adds r2, #1\n\t"
        "	adds r4, #1\n\t"
        "	ldrb r0, [r2]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _080E40CC\n\t"
        "_080E40F6:\n\t"
        "	bl sub_080E4510\n\t"
        "	bl sub_080E3E4C\n\t"
        "	movs r0, #3\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	movs r0, #5\n\t"
        "	bl PlaySE\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4110(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	bl GetPreviousTextCaretPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _080E4138\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r4, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_080E41B0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E413C\n\t"
        "	movs r0, #0\n\t"
        "	b _080E4146\n\t"
        "	.align 2, 0\n\t"
        "_080E4138: .4byte gUnknown_2039C34\n\t"
        "_080E413C:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MainState_WaitPageSwap\n\t"
        "	movs r0, #1\n\t"
        "_080E4146:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E414C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	bl GetPreviousTextCaretPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r0, _080E4174\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrb r4, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_080E4208\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E4178\n\t"
        "	movs r0, #0\n\t"
        "	b _080E4182\n\t"
        "	.align 2, 0\n\t"
        "_080E4174: .4byte gUnknown_2039C34\n\t"
        "_080E4178:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_080E4318\n\t"
        "	movs r0, #1\n\t"
        "_080E4182:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void AddTextCharacter(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl GetTextCaretPosition\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _080E41AC\n\t"
        "	ldr r1, [r1]\n\t"
        "	movs r2, #0xc0\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r1, r1, r2\n\t"
        "	adds r1, r1, r0\n\t"
        "	strb r4, [r1]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E41AC: .4byte gUnknown_2039C34\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E41B0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	movs r2, #0xfa\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0xe\n\t"
        "	bls _080E41FE\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0x1a\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _080E41FE\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0x4b\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _080E41FE\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0x56\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0xe\n\t"
        "	bls _080E41FE\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0x6a\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _080E41FE\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x65\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4202\n\t"
        "_080E41FE:\n\t"
        "	movs r0, #1\n\t"
        "	b _080E4204\n\t"
        "_080E4202:\n\t"
        "	movs r0, #0\n\t"
        "_080E4204:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4208(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	movs r2, #0xe6\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _080E423E\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0x46\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _080E423E\n\t"
        "	adds r0, r1, #0\n\t"
        "	subs r0, #0x6a\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _080E423E\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x6a\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4242\n\t"
        "_080E423E:\n\t"
        "	movs r0, #1\n\t"
        "	b _080E4244\n\t"
        "_080E4242:\n\t"
        "	movs r0, #0\n\t"
        "_080E4244:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MainState_WaitPageSwap(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	movs r3, #0xfa\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4264\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x31\n\t"
        "	b _080E42FE\n\t"
        "_080E4264:\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0xb\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4276\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x31\n\t"
        "	b _080E42FE\n\t"
        "_080E4276:\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x10\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4288\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x31\n\t"
        "	b _080E42FE\n\t"
        "_080E4288:\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x1a\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E429A\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x2c\n\t"
        "	b _080E42FE\n\t"
        "_080E429A:\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x4b\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _080E42FA\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x56\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E42B8\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x31\n\t"
        "	b _080E42FE\n\t"
        "_080E42B8:\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x5b\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E42CA\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x31\n\t"
        "	b _080E42FE\n\t"
        "_080E42CA:\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x60\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E42DC\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x31\n\t"
        "	b _080E42FE\n\t"
        "_080E42DC:\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x6a\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E42EE\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x2c\n\t"
        "	b _080E42FE\n\t"
        "_080E42EE:\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x65\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4302\n\t"
        "_080E42FA:\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0xfb\n\t"
        "_080E42FE:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "_080E4302:\n\t"
        "	ldr r0, _080E4314\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r3, #0xc0\n\t"
        "	lsls r3, r3, #5\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r2, [r0]\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E4314: .4byte gUnknown_2039C34\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4318(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	movs r3, #0xe6\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4334\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x31\n\t"
        "	b _080E4360\n\t"
        "_080E4334:\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x46\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bls _080E435E\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, #0x6a\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4352\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x31\n\t"
        "	b _080E4360\n\t"
        "_080E4352:\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x6a\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #4\n\t"
        "	bhi _080E4364\n\t"
        "_080E435E:\n\t"
        "	adds r0, r2, #5\n\t"
        "_080E4360:\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "_080E4364:\n\t"
        "	ldr r0, _080E4378\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r3, #0xc0\n\t"
        "	lsls r3, r3, #5\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, r0, r1\n\t"
        "	strb r2, [r0]\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E4378: .4byte gUnknown_2039C34\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E437C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	movs r2, #0\n\t"
        "	ldr r1, _080E4390\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r4, _080E4394\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r5, r1, #0\n\t"
        "	b _080E43DC\n\t"
        "	.align 2, 0\n\t"
        "_080E4390: .4byte gUnknown_2039C34\n\t"
        "_080E4394: .4byte 0x00001E28\n\t"
        "_080E4398:\n\t"
        "	ldr r1, [r1]\n\t"
        "	movs r0, #0xc0\n\t"
        "	lsls r0, r0, #5\n\t"
        "	adds r3, r1, r0\n\t"
        "	adds r0, r3, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E43CC\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _080E43CC\n\t"
        "	ldr r2, _080E43C8\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldrb r2, [r1, #1]\n\t"
        "	adds r2, #1\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r1, r3, #0\n\t"
        "	bl StringCopyN\n\t"
        "	b _080E43E2\n\t"
        "	.align 2, 0\n\t"
        "_080E43C8: .4byte 0x00001E30\n\t"
        "_080E43CC:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	adds r1, r5, #0\n\t"
        "	ldr r0, [r1]\n\t"
        "	ldr r4, _080E43E8\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r0, [r0]\n\t"
        "_080E43DC:\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	cmp r2, r0\n\t"
        "	blo _080E4398\n\t"
        "_080E43E2:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E43E8: .4byte 0x00001E28\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void choose_name_or_words_screen_load_bg_tile_patterns(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r0, _080E443C\n\t"
        "	ldr r6, _080E4440\n\t"
        "	ldr r1, [r6]\n\t"
        "	ldr r4, _080E4444\n\t"
        "	adds r1, r1, r4\n\t"
        "	bl LZ77UnCompWram\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r5, #0xc0\n\t"
        "	lsls r5, r5, #3\n\t"
        "	movs r0, #1\n\t"
        "	adds r2, r5, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl LoadBgTiles\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #2\n\t"
        "	adds r2, r5, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl LoadBgTiles\n\t"
        "	ldr r1, [r6]\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #3\n\t"
        "	adds r2, r5, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl LoadBgTiles\n\t"
        "	ldr r0, _080E4448\n\t"
        "	bl LoadSpriteSheets\n\t"
        "	ldr r0, _080E444C\n\t"
        "	bl LoadSpritePalettes\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E443C: .4byte gNamingScreenMenu_Gfx\n\t"
        "_080E4440: .4byte gUnknown_2039C34\n\t"
        "_080E4444: .4byte 0x00001810\n\t"
        "_080E4448: .4byte sSpriteSheets\n\t"
        "_080E444C: .4byte sSpritePalettes\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4450(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl InputInit\n\t"
        "	bl MoveCursorToOKButton\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void choose_name_or_words_screen_apply_bg_pals(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E4488\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xc0\n\t"
        "	bl LoadPalette\n\t"
        "	ldr r0, _080E448C\n\t"
        "	movs r1, #0xa0\n\t"
        "	movs r2, #0x20\n\t"
        "	bl LoadPalette\n\t"
        "	movs r0, #2\n\t"
        "	bl GetTextWindowPalette\n\t"
        "	movs r1, #0xb0\n\t"
        "	movs r2, #0x20\n\t"
        "	bl LoadPalette\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E4488: .4byte gNamingScreenMenu_Pal\n\t"
        "_080E448C: .4byte gNamingScreenKeyboard_Pal\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4490(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl CopyToBgTilemapBuffer\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E44A4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	cmp r1, #2\n\t"
        "	beq _080E4504\n\t"
        "	movs r4, #1\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	ldr r0, _080E450C\n\t"
        "	adds r0, r1, r0\n\t"
        "	ldrb r5, [r0]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0x20\n\t"
        "	movs r2, #0x13\n\t"
        "	movs r3, #0xc\n\t"
        "	bl FillBgTilemapBufferRect\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0x21\n\t"
        "	movs r2, #0x14\n\t"
        "	movs r3, #0xc\n\t"
        "	bl FillBgTilemapBufferRect\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0x1e\n\t"
        "	movs r2, #0x14\n\t"
        "	movs r3, #0xa\n\t"
        "	bl FillBgTilemapBufferRect\n\t"
        "	str r4, [sp]\n\t"
        "	str r4, [sp, #4]\n\t"
        "	str r5, [sp, #8]\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0x1f\n\t"
        "	movs r2, #0x14\n\t"
        "	movs r3, #0xb\n\t"
        "	bl FillBgTilemapBufferRect\n\t"
        "_080E4504:\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E450C: .4byte sKeyboardPagePaletteIds\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4510(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	ldr r7, _080E45C0\n\t"
        "	ldr r1, [r7]\n\t"
        "	ldr r2, _080E45C4\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r6, [r0, #1]\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	mov sl, r0\n\t"
        "	ldr r0, _080E45C8\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	movs r4, #0\n\t"
        "	cmp r4, r6\n\t"
        "	bhs _080E45A0\n\t"
        "	add r5, sp, #0xc\n\t"
        "	mov r8, r7\n\t"
        "	movs r7, #0\n\t"
        "	ldr r0, _080E45CC\n\t"
        "	ldrb r0, [r0]\n\t"
        "	mov sb, r0\n\t"
        "_080E454A:\n\t"
        "	mov r1, r8\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r2, #0xc0\n\t"
        "	lsls r2, r2, #5\n\t"
        "	adds r0, r0, r2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	strb r0, [r5]\n\t"
        "	mov r0, sb\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	bl sub_080E4830\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	cmp r0, #1\n\t"
        "	bne _080E4570\n\t"
        "	movs r1, #2\n\t"
        "_080E4570:\n\t"
        "	mov r2, r8\n\t"
        "	ldr r0, [r2]\n\t"
        "	ldr r2, _080E45C8\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r3, r4, #2\n\t"
        "	adds r3, r3, r4\n\t"
        "	lsls r3, r3, #1\n\t"
        "	add r3, sl\n\t"
        "	adds r3, r3, r1\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	movs r1, #1\n\t"
        "	str r1, [sp]\n\t"
        "	str r7, [sp, #4]\n\t"
        "	str r7, [sp, #8]\n\t"
        "	add r2, sp, #0xc\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, r6\n\t"
        "	blo _080E454A\n\t"
        "_080E45A0:\n\t"
        "	ldr r0, _080E45C0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E45C8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E45C0: .4byte gUnknown_2039C34\n\t"
        "_080E45C4: .4byte 0x00001E28\n\t"
        "_080E45C8: .4byte 0x00001E13\n\t"
        "_080E45CC: .4byte gText_ExpandedPlaceholder_Empty\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E45D0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0xc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r5, r1, #0x18\n\t"
        "	ldr r0, _080E463C\n\t"
        "	adds r0, r5, r0\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	movs r4, #0\n\t"
        "	ldr r1, _080E4640\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r7, [r0]\n\t"
        "	ldr r0, _080E4644\n\t"
        "	mov r8, r0\n\t"
        "_080E45FA:\n\t"
        "	lsls r3, r4, #4\n\t"
        "	adds r3, #1\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	str r7, [sp]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #4]\n\t"
        "	lsls r0, r4, #2\n\t"
        "	lsls r1, r5, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	add r0, r8\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [sp, #8]\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r2, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #3\n\t"
        "	bls _080E45FA\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl PutWindowTilemap\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E463C: .4byte sFillValues\n\t"
        "_080E4640: .4byte sKeyboardTextColors\n\t"
        "_080E4644: .4byte sNamingScreenKeyboardText\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4648(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	movs r0, #0xa\n\t"
        "	bl GetGpuReg\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r5, #3\n\t"
        "	ands r4, r5\n\t"
        "	movs r0, #0xc\n\t"
        "	bl GetGpuReg\n\t"
        "	ands r0, r5\n\t"
        "	cmp r4, r0\n\t"
        "	bls _080E4678\n\t"
        "	movs r6, #1\n\t"
        "	movs r7, #1\n\t"
        "	ldr r0, _080E4670\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E4674\n\t"
        "	b _080E4682\n\t"
        "	.align 2, 0\n\t"
        "_080E4670: .4byte gUnknown_2039C34\n\t"
        "_080E4674: .4byte 0x00001E11\n\t"
        "_080E4678:\n\t"
        "	movs r6, #2\n\t"
        "	movs r7, #2\n\t"
        "	ldr r0, _080E46D4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E46D8\n\t"
        "_080E4682:\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r5, [r0]\n\t"
        "	ldr r4, _080E46DC\n\t"
        "	bl sub_080E270C\n\t"
        "	ldr r1, _080E46D4\n\t"
        "	ldr r2, [r1]\n\t"
        "	ldr r1, _080E46E0\n\t"
        "	adds r2, r2, r1\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r2, [r2]\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_080E4490\n\t"
        "	bl sub_080E2758\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_080E45D0\n\t"
        "	bl sub_080E2758\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_080E44A4\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl CopyBgTilemapBufferToVram\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E46D4: .4byte gUnknown_2039C34\n\t"
        "_080E46D8: .4byte 0x00001E12\n\t"
        "_080E46DC: .4byte sKeyboardPageTilemaps\n\t"
        "_080E46E0: .4byte 0x00001E22\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E46E4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	ldr r1, _080E473C\n\t"
        "	add r0, sp, #0xc\n\t"
        "	movs r2, #3\n\t"
        "	bl memcpy\n\t"
        "	ldr r5, _080E4740\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r4, _080E4744\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #0xff\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add r1, sp, #0xc\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp, #4]\n\t"
        "	ldr r1, _080E4748\n\t"
        "	str r1, [sp, #8]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0x18\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized3\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl PutWindowTilemap\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	movs r1, #3\n\t"
        "	bl CopyWindowToVram\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E473C: .4byte sTextColor_Title\n\t"
        "_080E4740: .4byte gUnknown_2039C34\n\t"
        "_080E4744: .4byte 0x00001E15\n\t"
        "_080E4748: .4byte gText_NamingScreenInstructions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E474C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl RunTasks\n\t"
        "	bl AnimateSprites\n\t"
        "	bl BuildOamBuffer\n\t"
        "	bl UpdatePaletteFade\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void NamingScreen_TurnOffScreen(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r0, #0\n\t"
        "	bl SetVBlankCallback\n\t"
        "	movs r0, #0\n\t"
        "	bl SetHBlankCallback\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void NamingScreen_InitDisplayMode(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E4784\n\t"
        "	bl SetVBlankCallback\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E4784: .4byte VBlankCB_NamingScreen + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void VBlankCB_NamingScreen(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	bl LoadOam\n\t"
        "	bl ProcessSpriteCopyRequests\n\t"
        "	bl TransferPlttBuffer\n\t"
        "	ldr r5, _080E47F8\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E47FC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x16\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E4800\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x1a\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0xa\n\t"
        "	bl GetGpuReg\n\t"
        "	ldr r4, _080E4804\n\t"
        "	adds r1, r4, #0\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0xa\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E4808\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0xa\n\t"
        "	bl SetGpuRegBits\n\t"
        "	movs r0, #0xc\n\t"
        "	bl GetGpuReg\n\t"
        "	ands r4, r0\n\t"
        "	movs r0, #0xc\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldr r1, _080E480C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0xc\n\t"
        "	bl SetGpuRegBits\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E47F8: .4byte gUnknown_2039C34\n\t"
        "_080E47FC: .4byte 0x00001E18\n\t"
        "_080E4800: .4byte 0x00001E1A\n\t"
        "_080E4804: .4byte 0x0000FFFC\n\t"
        "_080E4808: .4byte 0x00001E1C\n\t"
        "_080E480C: .4byte 0x00001E1E\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetCursorPos(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r0, #0\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #1\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #2\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #3\n\t"
        "	bl ShowBg\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4830(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	movs r2, #0\n\t"
        "	ldr r0, _080E4864\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r3, r0, #0\n\t"
        "	cmp r1, #0xff\n\t"
        "	beq _080E485A\n\t"
        "	adds r1, r3, #0\n\t"
        "_080E4844:\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _080E485A\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	adds r0, r2, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _080E4844\n\t"
        "_080E485A:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E4864: .4byte gNamingScreenValidCharacters\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4868(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r0, _080E4888\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r2, [r1, #8]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _080E488C\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl DoNamingScreen\n\t"
        "	add sp, #8\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E4888: .4byte gSaveBlock2Ptr\n\t"
        "_080E488C: .4byte CB2_ReturnToFieldWithOpenMenu + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E4890(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r0, _080E48B0\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r2, [r1, #8]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _080E48B4\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	movs r3, #0\n\t"
        "	bl DoNamingScreen\n\t"
        "	add sp, #8\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E48B0: .4byte gSaveBlock2Ptr\n\t"
        "_080E48B4: .4byte CB2_ReturnToFieldWithOpenMenu + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E48B8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r0, _080E48D8\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r2, [r1, #8]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _080E48DC\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #2\n\t"
        "	movs r3, #0\n\t"
        "	bl DoNamingScreen\n\t"
        "	add sp, #8\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E48D8: .4byte gSaveBlock2Ptr\n\t"
        "_080E48DC: .4byte CB2_ReturnToFieldWithOpenMenu + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080E48E0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #8\n\t"
        "	ldr r0, _080E4900\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r2, [r1, #8]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	ldr r0, _080E4904\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #3\n\t"
        "	movs r3, #0\n\t"
        "	bl DoNamingScreen\n\t"
        "	add sp, #8\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E4900: .4byte gSaveBlock2Ptr\n\t"
        "_080E4904: .4byte CB2_ReturnToFieldWithOpenMenu + 1\n\t"
        ".syntax divided\n\t"
    );
}

// Naming Screen dispatch tables retain the JP ROM's mid59 layout.
#define NAMING_SCREEN_PRE_PAGE_SWAP_ANIM __attribute__((section(".rodata.naming_screen_mid59_pre_page_swap_anim")))
#define NAMING_SCREEN_PAGE_SWAP_ANIM __attribute__((section(".rodata.naming_screen_mid59_page_swap_anim")))
#define NAMING_SCREEN_CURSOR_ANIM_OFFSETS __attribute__((section(".rodata.naming_screen_mid59_cursor_anim_offsets")))
#define NAMING_SCREEN_BUTTON_KEY_ROLES __attribute__((section(".rodata.naming_screen_mid59_button_key_roles")))
#define NAMING_SCREEN_PAGE_SWAP_SPRITE __attribute__((section(".rodata.naming_screen_mid59_page_swap_sprite")))
#define NAMING_SCREEN_PAGE_SWAP_PAL_TAGS __attribute__((section(".rodata.naming_screen_mid59_page_swap_pal_tags")))
#define NAMING_SCREEN_PAGE_SWAP_GFX_TAGS __attribute__((section(".rodata.naming_screen_mid59_page_swap_gfx_tags")))
#define NAMING_SCREEN_UI_LAYOUT __attribute__((section(".rodata.naming_screen_mid59_ui_layout")))
#define NAMING_SCREEN_SPRITE_LAYOUT __attribute__((section(".rodata.naming_screen_mid59_sprite_layout")))
#define NAMING_SCREEN_SPRITE_RESOURCES __attribute__((section(".rodata.naming_screen_mid59_sprite_resources")))
#define NAMING_SCREEN_ICON_FUNCS __attribute__((section(".rodata.naming_screen_mid59_icon_funcs")))
#define NAMING_SCREEN_KEY_HANDLERS __attribute__((section(".rodata.naming_screen_mid59_key_handlers")))
#define NAMING_SCREEN_INPUT_FUNCS __attribute__((section(".rodata.naming_screen_mid59_input_funcs")))
#define NAMING_SCREEN_DPAD_MOVEMENT __attribute__((section(".rodata.naming_screen_mid59_dpad_movement")))
#define NAMING_SCREEN_DRAW_TEXT __attribute__((section(".rodata.naming_screen_mid59_draw_text")))
#define NAMING_SCREEN_DRAW_GENDER __attribute__((section(".rodata.naming_screen_mid59_draw_gender")))
#define NAMING_SCREEN_GENDER_COLORS __attribute__((section(".rodata.naming_screen_mid59_gender_colors")))
#define NAMING_SCREEN_CHARACTER_TRANSFORM __attribute__((section(".rodata.naming_screen_mid59_character_transform")))

NAMING_SCREEN_PRE_PAGE_SWAP_ANIM static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .priority = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .priority = 1,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .priority = 2,
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .priority = 3,
    },
};

NAMING_SCREEN_PRE_PAGE_SWAP_ANIM static const struct WindowTemplate sWindowTemplates[WIN_COUNT + 1] =
{
    [WIN_KB_PAGE_1] = {
        .bg = 1,
        .tilemapLeft = 3,
        .tilemapTop = 10,
        .width = 19,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x030,
    },
    [WIN_KB_PAGE_2] = {
        .bg = 2,
        .tilemapLeft = 3,
        .tilemapTop = 10,
        .width = 19,
        .height = 8,
        .paletteNum = 10,
        .baseBlock = 0x0C8,
    },
    [WIN_TEXT_ENTRY] = {
        .bg = 3,
        .tilemapLeft = 8,
        .tilemapTop = 6,
        .width = 17,
        .height = 2,
        .paletteNum = 10,
        .baseBlock = 0x030,
    },
    [WIN_TEXT_ENTRY_BOX] = {
        .bg = 3,
        .tilemapLeft = 8,
        .tilemapTop = 4,
        .width = 17,
        .height = 2,
        .paletteNum = 10,
        .baseBlock = 0x052,
    },
    [WIN_BANNER] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = DISPLAY_TILE_WIDTH,
        .height = 2,
        .paletteNum = 11,
        .baseBlock = 0x074,
    },
    DUMMY_WIN_TEMPLATE,
};

// Player and Walda phrase screens use the second JP page-mapping row.
NAMING_SCREEN_PRE_PAGE_SWAP_ANIM static const u8 sPageToNextGfxId[PAGE_MAPPING_COUNT][KBPAGE_COUNT] =
{
    [PAGE_MAPPING_BOX_OR_MON] = { PAGE_SWAP_UPPER, PAGE_SWAP_OTHERS, PAGE_SWAP_LOWER },
    [PAGE_MAPPING_PLAYER_OR_WALDA] = { PAGE_SWAP_UPPER, PAGE_SWAP_LOWER, PAGE_SWAP_OTHERS },
};

NAMING_SCREEN_PRE_PAGE_SWAP_ANIM static const u8 sPageToNextKeyboardId[PAGE_MAPPING_COUNT][KBPAGE_COUNT] =
{
    [PAGE_MAPPING_BOX_OR_MON] = { KEYBOARD_LETTERS_UPPER, KEYBOARD_SYMBOLS, KEYBOARD_LETTERS_LOWER },
    [PAGE_MAPPING_PLAYER_OR_WALDA] = { KEYBOARD_LETTERS_UPPER, KEYBOARD_LETTERS_LOWER, KEYBOARD_SYMBOLS },
};

NAMING_SCREEN_PRE_PAGE_SWAP_ANIM static const u8 sPageToKeyboardId[PAGE_MAPPING_COUNT][KBPAGE_COUNT] =
{
    [PAGE_MAPPING_BOX_OR_MON] = { KEYBOARD_LETTERS_LOWER, KEYBOARD_LETTERS_UPPER, KEYBOARD_SYMBOLS },
    [PAGE_MAPPING_PLAYER_OR_WALDA] = { KEYBOARD_SYMBOLS, KEYBOARD_LETTERS_UPPER, KEYBOARD_LETTERS_LOWER },
};

NAMING_SCREEN_PAGE_SWAP_ANIM static void (*const sPageSwapAnimStateFuncs[])(void) =
{
    PageSwapAnimState_Init,
    PageSwapAnimState_1,
    PageSwapAnimState_2,
    PageSwapAnimState_Done,
};

NAMING_SCREEN_CURSOR_ANIM_OFFSETS static const s16 sInputArrowXOffsets[] =
{
    0,
    -4,
    -2,
    -1,
};

NAMING_SCREEN_CURSOR_ANIM_OFFSETS static const s16 sUnderscoreYOffsets[] =
{
    2,
    3,
    2,
    1,
};

NAMING_SCREEN_BUTTON_KEY_ROLES static const u8 sButtonKeyRoles[] =
{
    1,
    2,
    3,
};

NAMING_SCREEN_PAGE_SWAP_SPRITE static void (*const sPageSwapSpriteFuncs[])(void) =
{
    sub_080E356C,
    sub_080E35C0,
    sub_080E35C4,
    sub_080E3638,
};

NAMING_SCREEN_PAGE_SWAP_PAL_TAGS static const u16 sPageSwapPalTags[] =
{
    1,
    3,
    2,
};

NAMING_SCREEN_PAGE_SWAP_GFX_TAGS static const u16 sPageSwapGfxTags[] =
{
    4,
    6,
    5,
};

NAMING_SCREEN_ICON_FUNCS static void (*const sIconFunctions[])(void) =
{
    TaskDummy2,
    NamingScreen_CreatePlayerIcon,
    NamingScreen_CreatePCIcon,
    NamingScreen_CreateMonIcon,
    NamingScreen_CreateWandaDadIcon,
};

NAMING_SCREEN_KEY_HANDLERS static void (*const sKeyboardKeyHandlers[])(void) =
{
    KeyboardKeyHandler_Character,
    KeyboardKeyHandler_Page,
    KeyboardKeyHandler_Backspace,
    KeyboardKeyHandler_OK,
};

NAMING_SCREEN_INPUT_FUNCS static void (*const sInputFuncs[])(void) =
{
    InputState_2,
    InputState_Enabled,
    sub_080E3BD0,
};

// These mirror pret's local HandleDpadMovement tables in a JP ROM-stable slice.
NAMING_SCREEN_DPAD_MOVEMENT static const s16 sDpadDeltaX[] =
{
    0,
    0,
    0,
    -1,
    1,
};

NAMING_SCREEN_DPAD_MOVEMENT static const s16 sDpadDeltaY[] =
{
    0,
    -1,
    1,
    0,
    0,
};

NAMING_SCREEN_DPAD_MOVEMENT static const s16 sKeyRowToButtonRow[] =
{
    0,
    1,
    1,
    2,
};

NAMING_SCREEN_DPAD_MOVEMENT static const s16 sButtonRowToKeyRow[] =
{
    0,
    0,
    3,
};

NAMING_SCREEN_DRAW_TEXT static void (*const sDrawTextEntryBoxFuncs[])(void) =
{
    sub_080E3D50,
    sub_080E3D50,
    sub_080E3DA4,
    sub_080E3DA4,
    sub_080E3D50,
};

NAMING_SCREEN_DRAW_GENDER static void (*const sDrawGenderIconFuncs[])(void) =
{
    sub_080E3E78,
    sub_080E3E7C,
};

NAMING_SCREEN_GENDER_COLORS static const u8 sGenderColors[2][3] =
{
    { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_BLUE, TEXT_COLOR_BLUE },
    { TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_RED },
};

// The JP character-transform button cycles kana variants, letter case, and digits.
NAMING_SCREEN_CHARACTER_TRANSFORM static const u8 sCharacterTransformSourceChars[] =
{
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C,
    0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x1A, 0x1B, 0x1C, 0x1D,
    0x1E, 0x24, 0x25, 0x26, 0x34, 0x35, 0x36, 0x2F, 0x30, 0x31, 0x32, 0x33,
    0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42,
    0x43, 0x44, 0x45, 0x50, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D,
    0x4E, 0x4F, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A,
    0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x6A, 0x6B,
    0x6C, 0x6D, 0x6E, 0x74, 0x75, 0x76, 0x84, 0x85, 0x86, 0x7F, 0x80, 0x81,
    0x82, 0x83, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90,
    0x91, 0x92, 0x93, 0x94, 0x95, 0xA0, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B,
    0x9C, 0x9D, 0x9E, 0x9F, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2,
    0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE,
    0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA,
    0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6,
    0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xA1, 0xA2, 0xA3, 0xA4,
    0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, EOS,
};

NAMING_SCREEN_CHARACTER_TRANSFORM static const u8 sCharacterTransformTargetChars[] =
{
    0x2F, 0x30, 0x31, 0x32, 0x33, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D,
    0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
    0x4A, 0x34, 0x35, 0x36, 0x24, 0x25, 0x26, 0x01, 0x02, 0x03, 0x04, 0x05,
    0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11,
    0x50, 0x13, 0x14, 0x12, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x1A, 0x1B, 0x1C,
    0x1D, 0x1E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x87, 0x88, 0x89, 0x8A, 0x8B,
    0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
    0x98, 0x99, 0x9A, 0x84, 0x85, 0x86, 0x74, 0x75, 0x76, 0x51, 0x52, 0x53,
    0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
    0x60, 0x61, 0xA0, 0x63, 0x64, 0x62, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0x6A,
    0x6B, 0x6C, 0x6D, 0x6E, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC,
    0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8,
    0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0,
    0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC,
    0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xA2, 0xA3, 0xA4, 0xA5,
    0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xA1,
};

NAMING_SCREEN_CHARACTER_TRANSFORM static const u8 sKeyboardPagePaletteIds[] =
{
    2,
    1,
    3,
    0,
    0,
};

// The JP page labels use both 16x8 and 24x8 subsprite layouts.
extern const u8 gUnknown_8565858[];
extern const u8 gUnknown_8565858_sub1[];
extern const u8 gUnknown_8565858_sub2[];
extern const u8 gUnknown_8565858_sub3[];
struct NamingScreenTemplate
{
    u8 copyExistingString;
    u8 maxChars;
    u8 iconFunction;
    u8 addGenderIcon;
    u8 initialPage;
    u8 unused;
    const u8 *title;
};

struct TextColor
{
    u8 colors[3][4];
};

NAMING_SCREEN_UI_LAYOUT static const struct TextColor sTextColorStruct =
{
    {
        { 0x0D, 1, 2, 0 },
        { 0x0E, 1, 2, 0 },
        { 0x0F, 1, 2, 0 },
    },
};

NAMING_SCREEN_UI_LAYOUT static const u8 sFillValues[] =
{
    0xEE,
    0xDD,
    0xFF,
};

NAMING_SCREEN_UI_LAYOUT static const u8 *const sKeyboardTextColors[] =
{
    sTextColorStruct.colors[1],
    sTextColorStruct.colors[0],
    sTextColorStruct.colors[2],
};

NAMING_SCREEN_UI_LAYOUT static const u8 *const sKeyboardPageTilemaps[] =
{
    (const u8 *)gNamingScreenKeyboardUpper_Tilemap,
    (const u8 *)gNamingScreenKeyboardSymbols_Tilemap,
    (const u8 *)gNamingScreenKeyboardLower_Tilemap,
    (const u8 *)gNamingScreenKeyboardUpper_Tilemap,
    (const u8 *)gNamingScreenKeyboardLower_Tilemap,
    (const u8 *)gNamingScreenKeyboardSymbols_Tilemap,
};

NAMING_SCREEN_UI_LAYOUT static const u8 sTextColor_Title[] =
{
    0x0F,
    1,
    2,
};

NAMING_SCREEN_UI_LAYOUT static const struct NamingScreenTemplate sPlayerNamingScreenTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = 5,
    .iconFunction = 1,
    .addGenderIcon = FALSE,
    .initialPage = 1,
    .unused = 0x23,
    .title = gUnknown_8565858 + 0x10,
};

NAMING_SCREEN_UI_LAYOUT static const struct NamingScreenTemplate sPCBoxNamingTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = 8,
    .iconFunction = 2,
    .addGenderIcon = FALSE,
    .initialPage = 0,
    .unused = 0x13,
    .title = gUnknown_8565858_sub1,
};

NAMING_SCREEN_UI_LAYOUT static const struct NamingScreenTemplate sMonNamingScreenTemplate =
{
    .copyExistingString = FALSE,
    .maxChars = 5,
    .iconFunction = 3,
    .addGenderIcon = TRUE,
    .initialPage = 0,
    .unused = 0x23,
    .title = gUnknown_8565858_sub2,
};

NAMING_SCREEN_UI_LAYOUT static const struct NamingScreenTemplate sWaldaWordsScreenTemplate =
{
    .copyExistingString = TRUE,
    .maxChars = 12,
    .iconFunction = 4,
    .addGenderIcon = FALSE,
    .initialPage = 1,
    .unused = 0x0B,
    .title = gUnknown_8565858_sub3,
};

NAMING_SCREEN_UI_LAYOUT static const struct NamingScreenTemplate *const sNamingScreenTemplates[] =
{
    &sPlayerNamingScreenTemplate,
    &sPCBoxNamingTemplate,
    &sMonNamingScreenTemplate,
    &sMonNamingScreenTemplate,
    &sWaldaWordsScreenTemplate,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct OamData sOam_8x8 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct OamData sOam_16x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct OamData sOam_32x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct Subsprite sSubsprites_PageSwapFrame[] =
{
    { .x = -20, .y = -16, .shape = SPRITE_SHAPE(32x8), .size = SPRITE_SIZE(32x8), .tileOffset = 0,  .priority = 1 },
    { .x =  12, .y = -16, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8),  .tileOffset = 4,  .priority = 1 },
    { .x = -20, .y =  -8, .shape = SPRITE_SHAPE(32x8), .size = SPRITE_SIZE(32x8), .tileOffset = 5,  .priority = 1 },
    { .x =  12, .y =  -8, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8),  .tileOffset = 9,  .priority = 1 },
    { .x = -20, .y =   0, .shape = SPRITE_SHAPE(32x8), .size = SPRITE_SIZE(32x8), .tileOffset = 10, .priority = 1 },
    { .x =  12, .y =   0, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8),  .tileOffset = 14, .priority = 1 },
    { .x = -20, .y =   8, .shape = SPRITE_SHAPE(32x8), .size = SPRITE_SIZE(32x8), .tileOffset = 15, .priority = 1 },
    { .x =  12, .y =   8, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8),  .tileOffset = 19, .priority = 1 },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct Subsprite sSubsprites_PageSwapText16x8[] =
{
    { .x = -12, .y = -4, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8), .tileOffset = 0, .priority = 1 },
    { .x =   4, .y = -4, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8), .tileOffset = 1, .priority = 1 },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct Subsprite sSubsprites_PageSwapText24x8[] =
{
    { .x = -12, .y = -4, .shape = SPRITE_SHAPE(16x8), .size = SPRITE_SIZE(16x8), .tileOffset = 0, .priority = 1 },
    { .x =   4, .y = -4, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8),  .tileOffset = 2, .priority = 1 },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct Subsprite sSubsprites_Button[] =
{
    { .x = -20, .y = -12, .shape = SPRITE_SHAPE(32x8), .size = SPRITE_SIZE(32x8), .tileOffset = 0,  .priority = 1 },
    { .x =  12, .y = -12, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8),  .tileOffset = 4,  .priority = 1 },
    { .x = -20, .y =  -4, .shape = SPRITE_SHAPE(32x8), .size = SPRITE_SIZE(32x8), .tileOffset = 5,  .priority = 1 },
    { .x =  12, .y =  -4, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8),  .tileOffset = 9,  .priority = 1 },
    { .x = -20, .y =   4, .shape = SPRITE_SHAPE(32x8), .size = SPRITE_SIZE(32x8), .tileOffset = 10, .priority = 1 },
    { .x =  12, .y =   4, .shape = SPRITE_SHAPE(8x8),  .size = SPRITE_SIZE(8x8),  .tileOffset = 14, .priority = 1 },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct Subsprite sSubsprites_PCIcon[] =
{
    { .x = -8, .y = -12, .shape = SPRITE_SHAPE(16x8), .size = SPRITE_SIZE(16x8), .tileOffset = 0, .priority = 3 },
    { .x = -8, .y =  -4, .shape = SPRITE_SHAPE(16x8), .size = SPRITE_SIZE(16x8), .tileOffset = 2, .priority = 3 },
    { .x = -8, .y =   4, .shape = SPRITE_SHAPE(16x8), .size = SPRITE_SIZE(16x8), .tileOffset = 4, .priority = 3 },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SubspriteTable sSubspriteTable_PageSwapFrame[] =
{
    { ARRAY_COUNT(sSubsprites_PageSwapFrame), sSubsprites_PageSwapFrame },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SubspriteTable sSubspriteTable_PageSwapText[] =
{
    { ARRAY_COUNT(sSubsprites_PageSwapText16x8), sSubsprites_PageSwapText16x8 },
    { ARRAY_COUNT(sSubsprites_PageSwapText24x8), sSubsprites_PageSwapText24x8 },
    { ARRAY_COUNT(sSubsprites_PageSwapText16x8), sSubsprites_PageSwapText16x8 },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SubspriteTable sSubspriteTable_Button[] =
{
    { ARRAY_COUNT(sSubsprites_Button), sSubsprites_Button },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SubspriteTable sSubspriteTable_PCIcon[] =
{
    { ARRAY_COUNT(sSubsprites_PCIcon), sSubsprites_PCIcon },
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteFrameImage sImageTable_PCIcon[] =
{
    { gNamingScreenPCIconOff_Gfx, sizeof(gNamingScreenPCIconOff_Gfx) },
    { gNamingScreenPCIconOn_Gfx, sizeof(gNamingScreenPCIconOn_Gfx) },
};

NAMING_SCREEN_SPRITE_LAYOUT static const union AnimCmd sAnim_Loop[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_JUMP(0),
};

NAMING_SCREEN_SPRITE_LAYOUT static const union AnimCmd sAnim_CursorSquish[] =
{
    ANIMCMD_FRAME(4, 8),
    ANIMCMD_FRAME(8, 8),
    ANIMCMD_END,
};

NAMING_SCREEN_SPRITE_LAYOUT static const union AnimCmd sAnim_PCIcon[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_JUMP(0),
};

NAMING_SCREEN_SPRITE_LAYOUT static const union AnimCmd *const sAnims_Loop[] =
{
    sAnim_Loop,
};

NAMING_SCREEN_SPRITE_LAYOUT static const union AnimCmd *const sAnims_Cursor[] =
{
    sAnim_Loop,
    sAnim_CursorSquish,
};

NAMING_SCREEN_SPRITE_LAYOUT static const union AnimCmd *const sAnims_PCIcon[] =
{
    sAnim_PCIcon,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_PageSwapFrame =
{
    .tileTag = 2,
    .paletteTag = 4,
    .oam = &sOam_8x8,
    .anims = sAnims_Loop,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = (SpriteCallback)sub_080E3544,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_PageSwapButton =
{
    .tileTag = 3,
    .paletteTag = 1,
    .oam = &sOam_32x16,
    .anims = sAnims_Loop,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_PageSwapText =
{
    .tileTag = 4,
    .paletteTag = 4,
    .oam = &sOam_8x8,
    .anims = sAnims_Loop,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_BackButton =
{
    .tileTag = 0,
    .paletteTag = 6,
    .oam = &sOam_8x8,
    .anims = sAnims_Loop,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_OkButton =
{
    .tileTag = 1,
    .paletteTag = 7,
    .oam = &sOam_8x8,
    .anims = sAnims_Loop,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_Cursor =
{
    .tileTag = 7,
    .paletteTag = 5,
    .oam = &sOam_16x16,
    .anims = sAnims_Cursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = (SpriteCallback)sub_080E3060,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_InputArrow =
{
    .tileTag = 10,
    .paletteTag = 3,
    .oam = &sOam_8x8,
    .anims = sAnims_Loop,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = (SpriteCallback)sub_080E3144,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_Underscore =
{
    .tileTag = 11,
    .paletteTag = 3,
    .oam = &sOam_8x8,
    .anims = sAnims_Loop,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = (SpriteCallback)sub_080E3190,
};

NAMING_SCREEN_SPRITE_LAYOUT static const struct SpriteTemplate sSpriteTemplate_PCIcon =
{
    .tileTag = 0xFFFF,
    .paletteTag = 0,
    .oam = &sOam_8x8,
    .anims = sAnims_PCIcon,
    .images = sImageTable_PCIcon,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

NAMING_SCREEN_SPRITE_RESOURCES static const u8 *const sNamingScreenKeyboardText[][4] =
{
    {
        gText_NamingScreenKeyboard_Katakana1,
        gText_NamingScreenKeyboard_Katakana2,
        gText_NamingScreenKeyboard_Katakana3,
        gText_NamingScreenKeyboard_Katakana4,
    },
    {
        gText_NamingScreenKeyboard_Hiragana1,
        gText_NamingScreenKeyboard_Hiragana2,
        gText_NamingScreenKeyboard_Hiragana3,
        gText_NamingScreenKeyboard_Hiragana4,
    },
    {
        gText_NamingScreenKeyboard_LatinUpper1,
        gText_NamingScreenKeyboard_LatinUpper2,
        gText_NamingScreenKeyboard_LatinLower1,
        gText_NamingScreenKeyboard_LatinLower2,
    },
};

NAMING_SCREEN_SPRITE_RESOURCES static const struct SpriteSheet sSpriteSheets[] =
{
    { gNamingScreenBackButton_Gfx, 0x1E0, 0 },
    { gNamingScreenOKButton_Gfx, 0x1E0, 1 },
    { gNamingScreenPageSwapFrame_Gfx, 0x280, 2 },
    { gNamingScreenPageSwapButton_Gfx, 0x100, 3 },
    { gNamingScreenPageSwapUpper_Gfx, 0x040, 4 },
    { gNamingScreenPageSwapLower_Gfx, 0x040, 5 },
    { gNamingScreenPageSwapOthers_Gfx, 0x060, 6 },
    { gNamingScreenCursor_Gfx, 0x080, 7 },
    { gNamingScreenCursorSquished_Gfx, 0x080, 8 },
    { gNamingScreenCursorFilled_Gfx, 0x080, 9 },
    { gNamingScreenInputArrow_Gfx, 0x020, 10 },
    { gNamingScreenUnderscore_Gfx, 0x020, 11 },
    { NULL, 0, 0 },
};

NAMING_SCREEN_SPRITE_RESOURCES static const struct SpritePalette sSpritePalettes[] =
{
    { gNamingScreenMenu_Pal[0], 0 },
    { gNamingScreenMenu_Pal[1], 1 },
    { gNamingScreenMenu_Pal[2], 2 },
    { gNamingScreenMenu_Pal[3], 3 },
    { gNamingScreenMenu_Pal[4], 4 },
    { gNamingScreenMenu_Pal[5], 5 },
    { gNamingScreenMenu_Pal[4], 6 },
    { gNamingScreenMenu_Pal[4], 7 },
    { NULL, 0 },
};

#undef NAMING_SCREEN_PAGE_SWAP_ANIM
#undef NAMING_SCREEN_BUTTON_KEY_ROLES
#undef NAMING_SCREEN_PAGE_SWAP_SPRITE
#undef NAMING_SCREEN_PAGE_SWAP_PAL_TAGS
#undef NAMING_SCREEN_PAGE_SWAP_GFX_TAGS
#undef NAMING_SCREEN_UI_LAYOUT
#undef NAMING_SCREEN_SPRITE_LAYOUT
#undef NAMING_SCREEN_SPRITE_RESOURCES
#undef NAMING_SCREEN_ICON_FUNCS
#undef NAMING_SCREEN_KEY_HANDLERS
#undef NAMING_SCREEN_INPUT_FUNCS
#undef NAMING_SCREEN_DPAD_MOVEMENT
#undef NAMING_SCREEN_DRAW_TEXT
#undef NAMING_SCREEN_DRAW_GENDER
#undef NAMING_SCREEN_GENDER_COLORS
#undef NAMING_SCREEN_CHARACTER_TRANSFORM
