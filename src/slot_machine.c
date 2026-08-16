#include "global.h"
#include "overworld.h"
#include "field_effect.h"
#include "random.h"
#include "gpu_regs.h"
#include "bg.h"
#include "sound.h"
#include "main.h"
#include "task.h"
#include "slot_machine.h"
#include "constants/rgb.h"
#include "constants/coins.h"
#include "constants/songs.h"
#include "coins.h"
#include "constants/game_stat.h"
#include "menu.h"
#include "main_menu.h"
#include "malloc.h"
#include "string_util.h"
#include "decompress.h"
#include "trig.h"
#include "graphics.h"
#include "palette.h"
#include "window.h"
#include "text.h"
#include "util.h"
#include "text.h"
#include "menu.h"

enum
{
    SYMBOL_7_RED,
    SYMBOL_7_BLUE,
    SYMBOL_AZURILL,
    SYMBOL_LOTAD,
    SYMBOL_CHERRY,
    SYMBOL_POWER,
    SYMBOL_REPLAY,
};

__attribute__((naked)) void Task_FadeToSlotMachine(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r1, _0812A50C\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r4, r0, r1\n\t"
        "	movs r0, #8\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0812A510\n\t"
        "	cmp r1, #1\n\t"
        "	beq _0812A528\n\t"
        "	b _0812A540\n\t"
        "	.align 2, 0\n\t"
        "_0812A50C: .4byte gTasks\n\t"
        "_0812A510:\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x10\n\t"
        "	bl BeginNormalPaletteFade\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	b _0812A540\n\t"
        "_0812A528:\n\t"
        "	ldr r0, _0812A548\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0812A540\n\t"
        "	ldr r0, _0812A54C\n\t"
        "	bl SetMainCallback2\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0812A540:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A548: .4byte gPaletteFade\n\t"
        "_0812A54C: .4byte CB2_SlotMachineSetup + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlaySlotMachine(u8 machineId, MainCallback exitCallback)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r5, _0812A58C\n\t"
        "	movs r0, #0x68\n\t"
        "	bl AllocZeroed\n\t"
        "	str r0, [r5]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl PlaySlotMachine_Internal\n\t"
        "	ldr r0, _0812A590\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _0812A594\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #8]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A58C: .4byte sSlotMachine\n\t"
        "_0812A590: .4byte Task_FadeToSlotMachine + 1\n\t"
        "_0812A594: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CB2_SlotMachineSetup(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r0, _0812A5B4\n\t"
        "	movs r1, #0x87\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0xb\n\t"
        "	bhi _0812A676\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0812A5B8\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A5B4: .4byte gMain\n\t"
        "_0812A5B8: .4byte 0x0812A5BC\n\t"
        "_0812A5BC: @ jump table\n\t"
        "	.4byte _0812A5EC @ case 0\n\t"
        "	.4byte _0812A5F6 @ case 1\n\t"
        "	.4byte _0812A5FC @ case 2\n\t"
        "	.4byte _0812A606 @ case 3\n\t"
        "	.4byte _0812A60C @ case 4\n\t"
        "	.4byte _0812A612 @ case 5\n\t"
        "	.4byte _0812A618 @ case 6\n\t"
        "	.4byte _0812A61E @ case 7\n\t"
        "	.4byte _0812A648 @ case 8\n\t"
        "	.4byte _0812A64E @ case 9\n\t"
        "	.4byte _0812A654 @ case 10\n\t"
        "	.4byte _0812A670 @ case 11\n\t"
        "_0812A5EC:\n\t"
        "	bl SlotMachineSetup_0_0\n\t"
        "	bl SlotMachineSetup_0_1\n\t"
        "	b _0812A65C\n\t"
        "_0812A5F6:\n\t"
        "	bl SlotMachineSetup_InitVRAM\n\t"
        "	b _0812A65C\n\t"
        "_0812A5FC:\n\t"
        "	bl SlotMachineSetup_InitOAM\n\t"
        "	bl SlotMachineSetup_2_1\n\t"
        "	b _0812A65C\n\t"
        "_0812A606:\n\t"
        "	bl SlotMachineSetup_3_0\n\t"
        "	b _0812A65C\n\t"
        "_0812A60C:\n\t"
        "	bl SlotMachineSetup_4_0\n\t"
        "	b _0812A65C\n\t"
        "_0812A612:\n\t"
        "	bl SlotMachineSetup_5_0\n\t"
        "	b _0812A65C\n\t"
        "_0812A618:\n\t"
        "	bl SlotMachineSetup_6_0\n\t"
        "	b _0812A65C\n\t"
        "_0812A61E:\n\t"
        "	movs r0, #1\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp]\n\t"
        "	movs r2, #0x10\n\t"
        "	movs r3, #0\n\t"
        "	bl BeginNormalPaletteFade\n\t"
        "	movs r0, #0\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #1\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #2\n\t"
        "	bl ShowBg\n\t"
        "	movs r0, #3\n\t"
        "	bl ShowBg\n\t"
        "	b _0812A65C\n\t"
        "_0812A648:\n\t"
        "	bl SlotMachineSetup_8_0\n\t"
        "	b _0812A65C\n\t"
        "_0812A64E:\n\t"
        "	bl SlotMachineSetup_9_0\n\t"
        "	b _0812A65C\n\t"
        "_0812A654:\n\t"
        "	bl CreateSlotMachineSprites\n\t"
        "	bl CreateGameplayTasks\n\t"
        "_0812A65C:\n\t"
        "	ldr r1, _0812A66C\n\t"
        "	movs r0, #0x87\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0812A676\n\t"
        "	.align 2, 0\n\t"
        "_0812A66C: .4byte gMain\n\t"
        "_0812A670:\n\t"
        "	ldr r0, _0812A67C\n\t"
        "	bl SetMainCallback2\n\t"
        "_0812A676:\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A67C: .4byte CB2_SlotMachineLoop + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CB2_SlotMachineLoop(void)
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

__attribute__((naked)) void SlotMachine_VBlankCallback(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	bl LoadOam\n\t"
        "	bl ProcessSpriteCopyRequests\n\t"
        "	bl TransferPlttBuffer\n\t"
        "	ldr r4, _0812A6E0\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x58\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x40\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x5a\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x44\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x5c\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x48\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, #0x5e\n\t"
        "	ldrh r1, [r0]\n\t"
        "	movs r0, #0x4a\n\t"
        "	bl SetGpuReg\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A6E0: .4byte sSlotMachine\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlaySlotMachine_Internal(u8 machineId, MainCallback exitCallback)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _0812A718\n\t"
        "	movs r1, #0xff\n\t"
        "	bl CreateTask\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0812A71C\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r4, [r0, #8]\n\t"
        "	adds r0, #0xa\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl StoreWordInTwoHalfwords\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A718: .4byte SlotMachineDummyTask + 1\n\t"
        "_0812A71C: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0812A720(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0812A750\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r2, r0, #2\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #3\n\t"
        "	ldr r0, _0812A754\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r3, _0812A758\n\t"
        "	ldr r1, [r3]\n\t"
        "	ldrh r0, [r2, #8]\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	adds r2, #0xa\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r1, #0x64\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl LoadWordFromTwoHalfwords\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A750: .4byte SlotMachineDummyTask + 1\n\t"
        "_0812A754: .4byte gTasks\n\t"
        "_0812A758: .4byte sSlotMachine\n\t"
        ".syntax divided\n\t"
    );
}

void SlotMachineDummyTask(u8 taskId) {}
__attribute__((naked)) void SlotMachineSetup_0_0(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	movs r0, #0\n\t"
        "	bl SetVBlankCallback\n\t"
        "	movs r0, #0\n\t"
        "	bl SetHBlankCallback\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r1, #0xc0\n\t"
        "	lsls r1, r1, #0x13\n\t"
        "	ldr r2, _0812A7A0\n\t"
        "	mov r0, sp\n\t"
        "	bl CpuSet\n\t"
        "	movs r0, #0\n\t"
        "	bl ResetBgsAndClearDma3BusyFlags\n\t"
        "	ldr r1, _0812A7A4\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #4\n\t"
        "	bl InitBgsFromTemplates\n\t"
        "	ldr r0, _0812A7A8\n\t"
        "	bl InitWindows\n\t"
        "	bl DeactivateAllTextPrinters\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A7A0: .4byte 0x05006000\n\t"
        "_0812A7A4: .4byte gUnknown_85843A8\n\t"
        "_0812A7A8: .4byte gUnknown_85843B8\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SlotMachineSetup_6_0(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0812A7C8\n\t"
        "	bl SetVBlankCallback\n\t"
        "	movs r0, #1\n\t"
        "	bl EnableInterrupts\n\t"
        "	movs r1, #0xc1\n\t"
        "	lsls r1, r1, #6\n\t"
        "	movs r0, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A7C8: .4byte SlotMachine_VBlankCallback + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SlotMachineSetup_InitVRAM(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	movs r2, #0xc0\n\t"
        "	lsls r2, r2, #0x13\n\t"
        "	movs r3, #0x80\n\t"
        "	lsls r3, r3, #9\n\t"
        "	mov r4, sp\n\t"
        "	movs r6, #0\n\t"
        "	ldr r1, _0812A818\n\t"
        "	movs r5, #0x80\n\t"
        "	lsls r5, r5, #5\n\t"
        "	ldr r7, _0812A81C\n\t"
        "	movs r0, #0x81\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	mov ip, r0\n\t"
        "_0812A7EA:\n\t"
        "	strh r6, [r4]\n\t"
        "	mov r0, sp\n\t"
        "	str r0, [r1]\n\t"
        "	str r2, [r1, #4]\n\t"
        "	str r7, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	adds r2, r2, r5\n\t"
        "	subs r3, r3, r5\n\t"
        "	cmp r3, r5\n\t"
        "	bhi _0812A7EA\n\t"
        "	strh r6, [r4]\n\t"
        "	mov r0, sp\n\t"
        "	str r0, [r1]\n\t"
        "	str r2, [r1, #4]\n\t"
        "	lsrs r0, r3, #1\n\t"
        "	mov r2, ip\n\t"
        "	orrs r0, r2\n\t"
        "	str r0, [r1, #8]\n\t"
        "	ldr r0, [r1, #8]\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A818: .4byte 0x040000D4\n\t"
        "_0812A81C: .4byte 0x81000800\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SlotMachineSetup_InitOAM(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	sub sp, #4\n\t"
        "	movs r2, #0xe0\n\t"
        "	lsls r2, r2, #0x13\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _0812A83C\n\t"
        "	str r1, [r0]\n\t"
        "	str r2, [r0, #4]\n\t"
        "	ldr r1, _0812A840\n\t"
        "	str r1, [r0, #8]\n\t"
        "	ldr r0, [r0, #8]\n\t"
        "	add sp, #4\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0812A83C: .4byte 0x040000D4\n\t"
        "_0812A840: .4byte 0x81000200\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SlotMachineSetup_2_1(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r0, #8\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0xa\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0xc\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0xe\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x10\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x12\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x14\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x16\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x1a\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x1c\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x1e\n\t"
        "	movs r1, #0\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x48\n\t"
        "	movs r1, #0x3f\n\t"
        "	bl SetGpuReg\n\t"
        "	movs r0, #0x4a\n\t"
        "	movs r1, #0x3f\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r1, _0812A8CC\n\t"
        "	movs r0, #0x50\n\t"
        "	bl SetGpuReg\n\t"
        "	ldr r1, _0812A8D0\n\t"
        "	movs r0, #0x52\n\t"
        "	bl SetGpuReg\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A8CC: .4byte 0x00001048\n\t"
        "_0812A8D0: .4byte 0x00000809\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SlotMachineSetup_0_1(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	bl sub_0812A720\n\t"
        "	ldr r5, _0812A9B4\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r4, #0\n\t"
        "	strb r4, [r0]\n\t"
        "	ldr r0, [r5]\n\t"
        "	strb r4, [r0, #2]\n\t"
        "	bl Random\n\t"
        "	ldr r2, [r5]\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r2, #3]\n\t"
        "	ldr r0, [r5]\n\t"
        "	strb r4, [r0, #4]\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0\n\t"
        "	strh r4, [r0, #8]\n\t"
        "	strb r1, [r0, #0xa]\n\t"
        "	ldr r0, [r5]\n\t"
        "	strb r1, [r0, #0xb]\n\t"
        "	bl GetCoins\n\t"
        "	ldr r2, [r5]\n\t"
        "	strh r0, [r2, #0xc]\n\t"
        "	strh r4, [r2, #0xe]\n\t"
        "	strh r4, [r2, #0x10]\n\t"
        "	strh r4, [r2, #0x12]\n\t"
        "	strh r4, [r2, #0x18]\n\t"
        "	movs r0, #8\n\t"
        "	strh r0, [r2, #0x1a]\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r1, #0x58\n\t"
        "	movs r0, #0xf0\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r1, #2\n\t"
        "	movs r0, #0xa0\n\t"
        "	strh r0, [r1]\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x5c\n\t"
        "	movs r1, #0x3f\n\t"
        "	strh r1, [r0]\n\t"
        "	adds r0, #2\n\t"
        "	strh r1, [r0]\n\t"
        "	bl GetCurrentMapMusic\n\t"
        "	ldr r1, [r5]\n\t"
        "	adds r1, #0x60\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r7, #0\n\t"
        "	ldr r0, _0812A9B8\n\t"
        "	mov r8, r0\n\t"
        "_0812A944:\n\t"
        "	ldr r0, _0812A9B4\n\t"
        "	ldr r4, [r0]\n\t"
        "	lsls r6, r7, #1\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x22\n\t"
        "	adds r0, r0, r6\n\t"
        "	movs r1, #0\n\t"
        "	strh r1, [r0]\n\t"
        "	adds r5, r4, #0\n\t"
        "	adds r5, #0x28\n\t"
        "	adds r5, r5, r6\n\t"
        "	ldrb r0, [r4, #3]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	lsls r1, r7, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	add r0, r8\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	movs r1, #0x15\n\t"
        "	bl __modsi3\n\t"
        "	strh r0, [r5]\n\t"
        "	adds r4, #0x1c\n\t"
        "	adds r4, r4, r6\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	lsls r1, r0, #1\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	movs r2, #0xfc\n\t"
        "	lsls r2, r2, #1\n\t"
        "	adds r0, r2, #0\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r4]\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl __modsi3\n\t"
        "	strh r0, [r4]\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	cmp r7, #2\n\t"
        "	bls _0812A944\n\t"
        "	bl GetCoins\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl AlertTVThatPlayerPlayedSlotMachine\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A9B4: .4byte sSlotMachine\n\t"
        "_0812A9B8: .4byte gUnknown_8584638\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SlotMachineSetup_3_0(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl ResetPaletteFade\n\t"
        "	bl ResetSpriteData\n\t"
        "	ldr r1, _0812A9D8\n\t"
        "	movs r0, #0x80\n\t"
        "	strb r0, [r1]\n\t"
        "	bl FreeAllSpritePalettes\n\t"
        "	bl ResetTasks\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812A9D8: .4byte gOamLimit\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SlotMachineSetup_4_0(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r4, _0812AA30\n\t"
        "	movs r0, #8\n\t"
        "	bl Alloc\n\t"
        "	str r0, [r4]\n\t"
        "	ldr r4, _0812AA34\n\t"
        "	movs r0, #0xe\n\t"
        "	bl AllocZeroed\n\t"
        "	str r0, [r4]\n\t"
        "	ldr r5, _0812AA38\n\t"
        "	movs r0, #8\n\t"
        "	bl AllocZeroed\n\t"
        "	str r0, [r5]\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r2, _0812AA3C\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r2, _0812AA40\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	ldr r2, _0812AA44\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #4]\n\t"
        "	ldr r2, _0812AA48\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #6]\n\t"
        "	ldr r2, _0812AA4C\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #8]\n\t"
        "	ldr r2, _0812AA50\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #0xa]\n\t"
        "	ldr r2, _0812AA54\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #0xc]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0812AA30: .4byte sSelectedPikaPowerTile\n\t"
        "_0812AA34: .4byte sReelOverlay_Tilemap\n\t"
        "_0812AA38: .4byte sReelButtonPress_Tilemap\n\t"
        "_0812AA3C: .4byte 0x00002051\n\t"
        "_0812AA40: .4byte 0x00002851\n\t"
        "_0812AA44: .4byte 0x00002061\n\t"
        "_0812AA48: .4byte 0x00002861\n\t"
        "_0812AA4C: .4byte 0x000020BE\n\t"
        "_0812AA50: .4byte 0x000028BE\n\t"
        "_0812AA54: .4byte 0x000020BF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SlotMachineSetup_5_0(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl sub_0812F918\n\t"
        "	bl sub_0812F968\n\t"
        "	bl sub_0812F7F4\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #2\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #0xf0\n\t"
        "	bl LoadMessageBoxGfx\n\t"
        "	movs r1, #0x85\n\t"
        "	lsls r1, r1, #2\n\t"
        "	movs r0, #0\n\t"
        "	movs r2, #0xe0\n\t"
        "	bl LoadUserWindowBorderGfx\n\t"
        "	movs r0, #0\n\t"
        "	bl PutWindowTilemap\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

void CreateSlotMachineSprites(void)
{
    CreateReelSymbolSprites();
    CreateCreditPayoutNumberSprites();
    CreateInvisibleFlashMatchLineSprites();
    CreateReelBackgroundSprite();
}
__attribute__((naked)) void CreateGameplayTasks(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl CreatePikaPowerBoltTask\n\t"
        "	bl CreateReelTasks\n\t"
        "	bl sub_0812DEA4\n\t"
        "	bl CreateSlotMachineTasks\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

enum {
    MATCH_MIDDLE_ROW,
    MATCH_TOP_ROW,
    MATCH_BOTTOM_ROW,
    MATCH_NWSE_DIAG,
    MATCH_NESW_DIAG,
    NUM_MATCH_LINES,
};

enum {
    PIKABOLT_TASK_IDLE,
    PIKABOLT_TASK_ADD_BOLT,
    PIKABOLT_TASK_WAIT_ANIM,
    PIKABOLT_TASK_CLEAR_ALL,
};

enum {
    RT_TASK_INIT,
    RT_TASK_WINDOW_ENTER,
    RT_TASK_WAIT_START_PIKA,
    RT_TASK_PIKA_SPEEDUP1,
    RT_TASK_PIKA_SPEEDUP2,
    RT_TASK_WAIT_REEL,
    RT_TASK_CHECK_EXPLODE,
    RT_TASK_LAND,
    RT_TASK_PIKA_REACT,
    RT_TASK_WAIT_CLEAR_POWER,
    RT_TASK_CLOSE_WINDOW_SUCCESS,
    RT_TASK_DESTROY_SPRITES,
    RT_TASK_SET_REEL_SPEED,
    RT_TASK_END_SUCCESS,
    RT_TASK_EXPLODE,
    RT_TASK_WAIT_EXPLODE,
    RT_TASK_WAIT_SMOKE,
    RT_TASK_CLOSE_WINDOW_FAILURE,
    RT_TASK_END_FAILURE,
};

enum {
    MATCH_CHERRY,        // Cherry in center of first reel
    MATCH_TOPBOT_CHERRY, // Cherry in top/bottom of first reel
    MATCH_REPLAY,
    MATCH_LOTAD,
    MATCH_AZURILL,
    MATCH_POWER,
    MATCH_MIXED_7,       // First two 7's are same color; last is other color
    MATCH_RED_7,
    MATCH_BLUE_7,
    MATCH_NONE,
};

enum {
    SLOTTASK_UNFADE,
    SLOTTASK_WAIT_FADE,
    SLOTTASK_READY_NEW_SPIN,
    SLOTTASK_READY_NEW_RT_SPIN,
    SLOTTASK_ASK_INSERT_BET,
    SLOTTASK_BET_INPUT,
    SLOTTASK_MSG_NEED_3_COINS,
    SLOTTASK_WAIT_MSG_NEED_3_COINS,
    SLOTTASK_WAIT_INFO_BOX,
    SLOTTASK_START_SPIN,
    SLOTTASK_START_RT_SPIN,
    SLOTTASK_RESET_BIAS_FAILURE,
    SLOTTASK_WAIT_REEL_STOP,
    SLOTTASK_WAIT_ALL_REELS_STOP,
    SLOTTASK_CHECK_MATCHES,
    SLOTTASK_WAIT_PAYOUT,
    SLOTTASK_END_PAYOUT,
    SLOTTASK_MATCHED_POWER,
    SLOTTASK_WAIT_RT_ANIM,
    SLOTTASK_RESET_BET_TILES,
    SLOTTASK_NO_MATCHES,
    SLOTTASK_ASK_QUIT,
    SLOTTASK_HANDLE_QUIT_INPUT,
    SLOTTASK_MSG_MAX_COINS,
    SLOTTASK_WAIT_MSG_MAX_COINS,
    SLOTTASK_MSG_NO_MORE_COINS,
    SLOTTASK_WAIT_MSG_NO_MORE_COINS,
    SLOTTASK_END,
    SLOTTASK_FREE,
};

enum {
    PAYOUT_TASK_INIT,
    PAYOUT_TASK_GIVE_PAYOUT,
    PAYOUT_TASK_FREE,
};

// IDs for digital display "scenes", i.e. each of the screens it can show made up of sprites
enum {
    DIG_DISPLAY_INSERT_BET,
    DIG_DISPLAY_STOP_REEL,
    DIG_DISPLAY_WIN,
    DIG_DISPLAY_LOSE,
    DIG_DISPLAY_REEL_TIME,
    DIG_DISPLAY_BONUS_REG,
    DIG_DISPLAY_BONUS_BIG,
};

struct DigitalDisplaySprite
{
    /*0x00*/ u8 spriteTemplateId;
    /*0x01*/ u8 dispInfoId;
    /*0x02*/ s16 spriteId;
};

// Sprite template IDs for the digital display in the right panel
enum {
    DIG_SPRITE_REEL,
    DIG_SPRITE_TIME,
    DIG_SPRITE_INSERT,
    DIG_SPRITE_WIN,
    DIG_SPRITE_LOSE,
    DIG_SPRITE_A_BUTTON,
    DIG_SPRITE_SMOKE,
    DIG_SPRITE_NUMBER,
    DIG_SPRITE_POKE_BALL,
    DIG_SPRITE_D_PAD,
    DIG_SPRITE_STOP_S,
    DIG_SPRITE_STOP_T,
    DIG_SPRITE_STOP_O,
    DIG_SPRITE_STOP_P,
    DIG_SPRITE_BONUS_B,
    DIG_SPRITE_BONUS_O,
    DIG_SPRITE_BONUS_N,
    DIG_SPRITE_BONUS_U,
    DIG_SPRITE_BONUS_S,
    DIG_SPRITE_BIG_B,
    DIG_SPRITE_BIG_I,
    DIG_SPRITE_BIG_G,
    DIG_SPRITE_REG_R,
    DIG_SPRITE_REG_E,
    DIG_SPRITE_REG_G,
    DIG_SPRITE_EMPTY,
    NUM_DIG_DISPLAY_SPRITES
};

// IDs used by the digital display to set coords and callbacks for its sprites
enum {
    DIG_DISPINFO_INSERT,
    DIG_DISPINFO_STOP_S,
    DIG_DISPINFO_STOP_T,
    DIG_DISPINFO_STOP_O,
    DIG_DISPINFO_STOP_P,
    DIG_DISPINFO_A_BUTTON_STOP,
    DIG_DISPINFO_POKE_BALL_ROCKING,
    DIG_DISPINFO_WIN,
    DIG_DISPINFO_LOSE,
    DIG_DISPINFO_SMOKE_NW,
    DIG_DISPINFO_SMOKE_NE,
    DIG_DISPINFO_SMOKE_SW,
    DIG_DISPINFO_SMOKE_SE,
    DIG_DISPINFO_REEL,
    DIG_DISPINFO_TIME,
    DIG_DISPINFO_NUMBER,
    DIG_DISPINFO_DPAD,
    DIG_DISPINFO_POKE_BALL_SHINING,
    DIG_DISPINFO_REG_R,
    DIG_DISPINFO_REG_E,
    DIG_DISPINFO_REG_G,
    DIG_DISPINFO_REG_BONUS_B,
    DIG_DISPINFO_REG_BONUS_O,
    DIG_DISPINFO_REG_BONUS_N,
    DIG_DISPINFO_REG_BONUS_U,
    DIG_DISPINFO_REG_BONUS_S,
    DIG_DISPINFO_BIG_B,
    DIG_DISPINFO_BIG_I,
    DIG_DISPINFO_BIG_G,
    DIG_DISPINFO_BIG_BONUS_B,
    DIG_DISPINFO_BIG_BONUS_O,
    DIG_DISPINFO_BIG_BONUS_N,
    DIG_DISPINFO_BIG_BONUS_U,
    DIG_DISPINFO_BIG_BONUS_S,
    DIG_DISPINFO_A_BUTTON_START
};

#define DIG_SPRITE_DUMMY {255, 0, 0}

// IDs for the text windows
enum {
    WIN_MSG,
    WIN_INFO,
};

// JP tag scheme for the coin number sprites (differs from the US GFXTAG enum).
#define GFXTAG_NUM_0 0x70000
// JP tag scheme for the machine/reel sprites (values match the US GFXTAG enum).
#define GFXTAG_REEL_BG 17
#define GFXTAG_STOP 18
#define GFXTAG_BONUS 19
#define GFXTAG_BIG 20
#define GFXTAG_REG 21

// Palette tags match the US pokeemerald enum order (JP ROM uses the same tag ids).
enum {
    PALTAG_REEL,
    PALTAG_REEL_TIME_PIKACHU,
    PALTAG_REEL_TIME_MISC,
    PALTAG_REEL_TIME_MACHINE,
    PALTAG_MISC,
    PALTAG_EXPLOSION,
    PALTAG_DIG_DISPLAY,
    PALTAG_PIKA_AURA,
};

#define MAX_BET 3
#define REEL_NORMAL_SPEED 8
#define REEL_HALF_SPEED 4
#define REEL_QUARTER_SPEED 2
#define MAX_EXTRA_TURNS 4

#define BIAS_REPLAY     (1 << 0)
#define BIAS_CHERRY     (1 << 1)
#define BIAS_LOTAD      (1 << 2)
#define BIAS_AZURILL    (1 << 3)
#define BIAS_POWER      (1 << 4)
#define BIAS_REELTIME   (1 << 5)
#define BIAS_MIXED_7    (1 << 6)
#define BIAS_STRAIGHT_7 (1 << 7)
#define BIAS_7          (BIAS_STRAIGHT_7 | BIAS_MIXED_7)

enum {
    LEFT_REEL,
    MIDDLE_REEL,
    RIGHT_REEL,
    NUM_REELS,
};

struct SlotMachine
{
    /*0x00*/ u8 state;
    /*0x01*/ u8 machineId;
    /*0x02*/ u8 pikaPowerBolts;
    /*0x03*/ bool8 luckyGame;
    /*0x04*/ u8 machineBias;
    /*0x05*/ u8 reelTimeDraw;
    /*0x06*/ bool8 didNotFailBias;
    /*0x07*/ u8 biasSymbol;
    /*0x08*/ u16 matches;
    /*0x0A*/ u8 reelTimeSpinsLeft;
    /*0x0B*/ u8 reelTimeSpinsUsed;
    /*0x0C*/ s16 coins;
    /*0x0E*/ s16 payout;
    /*0x10*/ s16 netCoinLoss; // never negative
    /*0x12*/ s16 bet;
    /*0x14*/ s16 reeltimePixelOffset;
    /*0x16*/ s16 reeltimePosition;
    /*0x18*/ s16 currentReel;
    /*0x1A*/ s16 reelSpeed;
    /*0x1C*/ s16 reelPixelOffsets[NUM_REELS];
    /*0x22*/ u16 reelShockOffsets[NUM_REELS];
    /*0x28*/ s16 reelPositions[NUM_REELS];
    /*0x2E*/ s16 reelExtraTurns[NUM_REELS];
    /*0x34*/ s16 winnerRows[NUM_REELS];
    /*0x3A*/ u8 slotReelTasks[NUM_REELS];
    /*0x3D*/ u8 digDisplayTaskId;
    /*0x3E*/ u8 pikaPowerBoltTaskId;
    /*0x3F*/ u8 reelTimePikachuSpriteId;
    /*0x40*/ u8 reelTimeNumberGapSpriteId;
    /*0x41*/ u8 reelTimeExplosionSpriteId;
    /*0x42*/ u8 reelTimeBrokenMachineSpriteId;
    /*0x43*/ u8 reelTimeSmokeSpriteId;
    /*0x44*/ u8 flashMatchLineSpriteIds[NUM_MATCH_LINES];
    /*0x49*/ u8 reelTimeMachineSpriteIds[2];
    /*0x49*/ u8 reelTimeNumberSpriteIds[3];
    /*0x4E*/ u8 reelTimeShadowSpriteIds[2];
    /*0x50*/ u8 reelTimeBoltSpriteIds[2];
    /*0x52*/ u8 reelTimePikachuAuraSpriteIds[2];
    /*0x54*/ u8 reelTimeDuckSpriteIds[4];
    /*0x58*/ u16 win0h;
    /*0x5A*/ u16 win0v;
    /*0x5C*/ u16 winIn;
    /*0x5E*/ u16 winOut;
    /*0x60*/ u16 backupMapMusic;
    /*0x64*/ MainCallback prevMainCb;
};

extern u16 *sMenuGfx;
extern u16 *sSelectedPikaPowerTile;
extern u16 *sReelOverlay_Tilemap;
extern u8 *sDigitalDisplayGfxPtr;
extern u8 *sReelTimeGfxPtr;
extern u16 *sReelButtonPress_Tilemap;
extern u8 *sReelBackground_Gfx;
extern struct SpriteFrameImage *sImageTable_ReelTimePikachu;
extern struct SpriteFrameImage *sImageTable_ReelTimeMachineAntennae;
extern struct SpriteFrameImage *sImageTable_ReelTimeMachine;
extern struct SpriteFrameImage *sImageTable_BrokenReelTimeMachine;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Reel;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Time;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Insert;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Stop;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Win;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Lose;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Bonus;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Big;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Reg;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_AButton;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Smoke;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Number;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_Pokeball;
extern struct SpriteFrameImage *sImageTable_DigitalDisplay_DPad;
extern struct SpriteSheet *sReelBackgroundSpriteSheet;
extern struct SpriteSheet *sSlotMachineSpritesheetsPtr;
extern struct SlotMachine *sSlotMachine;

static const bool8 (*const sSlotTasks[])(struct Task *);
static const bool8 (*const sPayoutTasks[])(struct Task *);

static void Task_SlotMachine(u8 taskId);
static void Task_Reel(u8 taskId);
static void SpinSlotReel(u8 reelIndex);
static void StopSlotReel(u8 reelIndex);
static bool8 IsSlotReelMoving(u8 reelIndex);
static bool8 ReelTask_StayStill(struct Task *task);
static bool8 ReelTask_Spin(struct Task *task);
static bool8 ReelTask_DecideStop(struct Task *task);
static bool8 ReelTask_MoveToStop(struct Task *task);
static bool8 ReelTask_ShakingStop(struct Task *task);

enum {
    REEL_TASK_STILL,
    REEL_TASK_SPIN,
    REEL_TASK_DECIDE_STOP,
    REEL_TASK_STOP_MOVE,
    REEL_TASK_STOP_SHAKE,
};

#define SYMBOLS_PER_REEL   21
#define REEL_SYMBOL_HEIGHT 24
#define REEL_HEIGHT        (SYMBOLS_PER_REEL * REEL_SYMBOL_HEIGHT)
#define REELTIME_SYMBOLS       6
#define REELTIME_SYMBOL_HEIGHT 20
#define REELTIME_REEL_HEIGHT   (REELTIME_SYMBOLS * REELTIME_SYMBOL_HEIGHT)

#define tState data[0]
#define tMoving data[14]
#define tExtraTurns    data[1]
#define tShockMagnitude data[1]

__attribute__((section(".rodata.sReelTasks")))
static const bool8 (*const sReelTasks[])(struct Task *task) =
{
    [REEL_TASK_STILL]       = ReelTask_StayStill,
    [REEL_TASK_SPIN]        = ReelTask_Spin,
    [REEL_TASK_DECIDE_STOP] = ReelTask_DecideStop,
    [REEL_TASK_STOP_MOVE]   = ReelTask_MoveToStop,
    [REEL_TASK_STOP_SHAKE]  = ReelTask_ShakingStop,
};

bool8 DecideStop_Bias_Reel1(void);
bool8 DecideStop_Bias_Reel2(void);
bool8 DecideStop_Bias_Reel3(void);
void DecideStop_NoBias_Reel1(void);
void DecideStop_NoBias_Reel2(void);
void DecideStop_NoBias_Reel3(void);

__attribute__((section(".rodata.sDecideStop_Bias")))
static bool8 (*const sDecideStop_Bias[NUM_REELS])(void) =
{
    DecideStop_Bias_Reel1,
    DecideStop_Bias_Reel2,
    DecideStop_Bias_Reel3,
};

__attribute__((section(".rodata.sDecideStop_NoBias")))
static void (*const sDecideStop_NoBias[NUM_REELS])(void) =
{
    DecideStop_NoBias_Reel1,
    DecideStop_NoBias_Reel2,
    DecideStop_NoBias_Reel3,
};

// JP ROM table has a trailing padding u16 (6th entry is never copied/used).
__attribute__((section(".rodata.sReelStopShocks")))
static const u16 sReelStopShocks[] = {2, 4, 4, 4, 8, 0};

static void CreateSlotMachineTasks(void)
{
    Task_SlotMachine(CreateTask(Task_SlotMachine, 0));
}


static void Task_SlotMachine(u8 taskId)
{
    while (sSlotTasks[sSlotMachine->state](&gTasks[taskId]))
        ;
}


void LoadPikaPowerMeter(u8 bolts);
void CreateDigitalDisplayScene(u8 id);
bool8 IsDigitalDisplayAnimFinished(void);
static bool8 IsInfoBoxClosed(void);
static void OpenInfoBox(u8 digDisplayId);
static void Task_InfoBox(u8 taskId);
static void InfoBox_FadeIn(struct Task *task);
static void InfoBox_WaitFade(struct Task *task);
static void InfoBox_DrawWindow(struct Task *task);
static void InfoBox_AddText(struct Task *task);
static void InfoBox_WaitInput(struct Task *task);
static void InfoBox_LoadSlotMachineTilemap(struct Task *task);
static void InfoBox_CreateDigitalDisplay(struct Task *task);
static void InfoBox_LoadPikaPowerMeter(struct Task *task);
static void InfoBox_FreeTask(struct Task *task);
extern const u8 gText_YouDontHaveThreeCoins[];
extern const u8 gText_ReelTimeHelp[];
extern const u8 gText_YouveGot9999Coins[];
extern const u8 gText_YouveRunOutOfCoins[];
extern const u8 gText_QuitTheGame[];
static void DrawMachineBias(void);
static void ResetBiasFailure(void);
static bool8 ShouldTrySpecialBias(void);
static u8 TrySelectBias_Special(void);
static u8 TrySelectBias_Regular(void);
static u8 GetReelTimeSpinProbability(u8 spins);
static void GetReelTimeDraw(void);
void DestroyDigitalDisplayScene(void);
void CreateCoinNumberSprite(s16 x, s16 y, bool8 isPayout, s16 digitMult);
extern const struct SpriteTemplate sSpriteTemplate_ReelSymbol;
extern const struct SpriteTemplate sSpriteTemplate_CoinNumber;
extern const struct SpriteTemplate sSpriteTemplate_ReelBackground;
extern const struct SubspriteTable sSubspriteTable_ReelBackground[];
extern const struct SpriteTemplate sSpriteTemplate_ReelTimePikachu;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeMachineAntennae;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeMachine;
extern const struct SpriteTemplate sSpriteTemplate_BrokenReelTimeMachine;
extern const struct SubspriteTable sSubspriteTable_ReelTimeMachineAntennae[];
extern const struct SubspriteTable sSubspriteTable_ReelTimeMachine[];
extern const struct SubspriteTable sSubspriteTable_BrokenReelTimeMachine[];
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeNumbers;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeShadow;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeNumberGap;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeBolt;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimePikachuAura;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeExplosion;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeDuck;
extern const struct SpriteTemplate sSpriteTemplate_ReelTimeSmoke;
extern const struct SpriteTemplate sSpriteTemplate_PikaPowerBolt;
extern const s16 sDigitalDisplay_SpriteCoords[][2];
extern const SpriteCallback sDigitalDisplay_SpriteCallbacks[];
extern const struct SpriteTemplate *const sSpriteTemplates_DigitalDisplay[];
extern struct SpriteFrameImage *sImageTables_DigitalDisplay[];
extern const struct SubspriteTable *const sSubspriteTables_DigitalDisplay[];
// JP ROM keeps the smoke offset tables as data symbols (US has them inline).
extern const s16 sDigitalDisplaySmokeXOffsets[];
extern const s16 sDigitalDisplaySmokeYOffsets[];
extern const u16 *const sPokeballShiningPalTable[];
extern const s16 sDigitalDisplayRegBonusXOffsets[];
extern const s16 sDigitalDisplayRegBonusYOffsets[];
extern const s16 sDigitalDisplayRegBonusDelays[];
extern const s16 sDigitalDisplayBigBonusOffsets[];
extern const u16 *const sDigitalDisplay_Pal;
extern const u32 gSlotMachineDigitalDisplay_Gfx[];
extern const u32 sReelTimeGfx[];
extern const struct SpriteSheet sSlotMachineSpriteSheets[22];
extern const struct SpritePalette sSlotMachineSpritePalettes[];
extern const u8 *const sReelBackground_Tilemap;
extern const u32 gSlotMachineMenu_Gfx[];
extern const u16 sUnkPalette[];
extern const u16 gSlotMachineMenu_Tilemap[];
extern const u16 gSlotMachineInfoBox_Tilemap[];
extern const u8 sSpecialDrawOdds[][MAX_BET];
extern const u8 sBiasProbabilities_Special[][6];
extern const u8 sBiasProbabilities_Regular[][6];
extern const u8 sReelTimeProbabilities_NormalGame[][17];
extern const u8 sReelTimeProbabilities_LuckyGame[][17];
extern const u16 sReelTimeSpeed_Probabilities[][2];
extern const u16 sQuarterSpeed_ProbabilityBoost[];
extern const u16 sBiasesSpecial[3];
extern const u16 sBiasesRegular[5];
extern const struct SubspriteTable sSubspriteTable_ReelTimeShadow[];
extern const struct SubspriteTable sSubspriteTable_ReelTimeNumberGap[];
// JP ROM keeps the aura flash colors / duck offsets as data symbols (US has them inline).
extern const u8 sReelTimeAuraColors[];
extern const u16 sReelTimeDuckOffsets[];
static void EndDigitalDisplayScene_StopReel(void);
static void EndDigitalDisplayScene_Win(void);
static void EndDigitalDisplayScene_InsertBet(void);
static void EndDigitalDisplayScene_Dummy(void);
u8 CreateStdDigitalDisplaySprite(u8 templateIdx, u8 dispInfoId, s16 spriteId);
void IncrementDailySlotsUses(void);
void BeginReelTime(void);
static u16 ReelTimeSpeed(void);
bool8 IsReelTimeTaskDone(void);
static void PressStopReelButton(u8 reelIndex);
void Task_PressStopReelButton(u8 taskId);
static void StopReelButton_Press(struct Task *task, u8 taskId);
static void StopReelButton_Wait(struct Task *task, u8 taskId);
static void StopReelButton_Unpress(struct Task *task, u8 taskId);
void TryPutFindThatGamerOnAir(u16 nCoinsPaidOut);
bool8 IsFinalTask_Task_Payout(void);
bool8 TryStopSlotMachineLights(void);
bool8 IsPikaPowerBoltAnimating(void);
void DarkenBetTiles(u8 betLevel);
void LightenBetTiles(u8 betLevel);
void CheckMatch(void);
void AwardPayout(void);
void FlashSlotMachineLights(void);
static void Task_FlashSlotMachineLights(u8 taskId);
void AddPikaPowerBolt(u8 bolts);
static void CreatePikaPowerBoltTask(void);
void ResetPikaPowerBolts(void);
static void Task_CreatePikaPowerBolt(u8 taskId);
static void PikaPowerBolt_Idle(struct Task *task);
static void PikaPowerBolt_AddBolt(struct Task *task);
static void PikaPowerBolt_WaitAnim(struct Task *task);
static void PikaPowerBolt_ClearAll(struct Task *task);
static void ResetPikaPowerBoltTask(struct Task *task);
u8 CreatePikaPowerBoltSprite(s16 x, s16 y);
void DestroyPikaPowerBoltSprite(u8 spriteId);
static void Task_ReelTime(u8 taskId);
static void ReelTime_Init(struct Task *task);
static void ReelTime_WindowEnter(struct Task *task);
static void ReelTime_WaitStartPikachu(struct Task *task);
static void ReelTime_PikachuSpeedUp1(struct Task *task);
static void ReelTime_PikachuSpeedUp2(struct Task *task);
static void ReelTime_WaitReel(struct Task *task);
static void ReelTime_CheckExplode(struct Task *task);
static void ReelTime_LandOnOutcome(struct Task *task);
static void ReelTime_PikachuReact(struct Task *task);
static void ReelTime_WaitClearPikaPower(struct Task *task);
static void ReelTime_CloseWindow(struct Task *task);
static void ReelTime_DestroySprites(struct Task *task);
static void ReelTime_SetReelSpeed(struct Task *task);
static void ReelTime_EndSuccess(struct Task *task);
static void ReelTime_ExplodeMachine(struct Task *task);
static void ReelTime_WaitExplode(struct Task *task);
static void ReelTime_WaitSmoke(struct Task *task);
static void ReelTime_EndFailure(struct Task *task);
void LoadReelTimeWindowTilemap(s16 a0, s16 a1);
void CreateReelTimeMachineSprites(void);
void CreateReelTimePikachuSprite(void);
void CreateReelTimeNumberSprites(void);
void CreateReelTimeShadowSprites(void);
void CreateReelTimeNumberGapSprite(void);
static void GetReelTimeDraw(void);
static void Task_DigitalDisplay(u8 taskId);
static void DigitalDisplay_Idle(struct Task *task);
u8 CreateDigitalDisplaySprite(u8 templateIdx, SpriteCallback callback, s16 x, s16 y, s16 spriteId);
void LoadSlotMachineGfx(void);
void LoadReelBackground(void);
void LoadMenuGfx(void);
void LoadMenuAndReelOverlayTilemaps(void);
static void LoadSlotMachineMenuTilemap(void);
void LoadSlotMachineReelOverlay(void);
static void LoadInfoBoxTilemap(void);
void SetDigitalDisplayImagePtrs(void);
void AllocDigitalDisplayGfx(void);
void LoadSlotMachineMenuTilemap(void);
static bool8 ShouldReelTimeMachineExplode(u16 check);
void ClearReelTimeWindowTilemap(s16 a0);
void DestroyReelTimePikachuSprite(void);
void DestroyReelTimeMachineSprites(void);
void DestroyReelTimeShadowSprites(void);
void DestroyReelTimeBoltSprites(void);
void DestroyReelTimePikachuAuraSprites(void);
void DestroyReelTimeExplosionSprite(void);
void CreateReelTimeDuckSprites(void);
void CreateBrokenReelTimeMachineSprite(void);
void CreateReelTimeSmokeSprite(void);
bool8 IsReelTimeSmokeAnimFinished(void);
void DestroyReelTimeSmokeSprite(void);
void DestroyBrokenReelTimeMachineSprite(void);
void DestroyReelTimeDuckSprites(void);
void CreateReelTimeExplosionSprite(void);
void CreateReelTimeBoltSprites(void);
void CreateReelTimePikachuAuraSprites(void);
void SetReelTimeBoltDelay(s16 delay);
void SetReelTimePikachuAuraFlashDelay(s16 delay);
void FlashMatchLine(u8 spriteId);
void CreateInvisibleFlashMatchLineSprites(void);
static bool8 TryStopMatchLineFlashing(u8 spriteId);
static void SpriteCB_FlashMatchingLines(struct Sprite *sprite);
void SetReelButtonTilemap(s16 a0, u16 a1, u16 a2, u16 a3, u16 a4);
static u8 GetSymbolAtRest(u8 reelIndex, s16 row);
u8 GetMatchFromSymbols(u8 sym1, u8 sym2, u8 sym3);
void Task_Payout(u8 taskId);
static bool8 IsMatchLineDoneFlashingBeforePayout(void);
static bool8 TryStopMatchLinesFlashing(void);
static bool8 DecideStop_Bias_Reel1_Bet1(u8 sym1, u8 sym2);
static bool8 DecideStop_Bias_Reel1_Bet2or3(u8 sym1, u8 sym2);
static bool8 EitherSymbolAtPos_Reel1(s16 pos, u8 sym1, u8 sym2);
static bool8 BiasedTowardCherryOr7s(void);
static bool8 DecideStop_Bias_Reel2_Bet1or2(void);
static bool8 DecideStop_Bias_Reel2_Bet3(void);
static bool8 DecideStop_Bias_Reel3_Bet1or2(u8 biasSymbol);
static bool8 DecideStop_Bias_Reel3_Bet3(u8 biasSymbol);
static void DecideStop_NoBias_Reel2_Bet1(void);
static void DecideStop_NoBias_Reel2_Bet2(void);
static void DecideStop_NoBias_Reel2_Bet3(void);
static void DecideStop_NoBias_Reel3_Bet1(void);
static void DecideStop_NoBias_Reel3_Bet2(void);
static void DecideStop_NoBias_Reel3_Bet3(void);
bool8 IfSymbol7_SwitchColor(u8 *symbol);
static bool8 MismatchedSyms_77(u8 sym1, u8 sym2);
static bool8 MismatchedSyms_777(u8 sym1, u8 sym2, u8 sym3);
static bool8 NeitherMatchNor7Mismatch(u8 sym1, u8 sym2, u8 sym3);

#define tTimer data[0]
#define tTimer2 data[1]

static bool8 SlotTask_UnfadeScreen(struct Task *task)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    LoadPikaPowerMeter(sSlotMachine->pikaPowerBolts);
    sSlotMachine->state++; // SLOTTASK_WAIT_FADE
    return FALSE;
}

static bool8 SlotTask_WaitUnfade(struct Task *task)
{
    if (!gPaletteFade.active)
        sSlotMachine->state++;
    return FALSE;
}

static bool8 SlotTask_ReadyNewSpin(struct Task *task)
{
    sSlotMachine->payout = 0;
    sSlotMachine->bet = 0;
    sSlotMachine->currentReel = LEFT_REEL;
    sSlotMachine->machineBias &= (BIAS_STRAIGHT_7 | BIAS_MIXED_7);
    sSlotMachine->state = SLOTTASK_ASK_INSERT_BET;
    if (sSlotMachine->coins <= 0)
    {
        sSlotMachine->state = SLOTTASK_MSG_NO_MORE_COINS;
    }
    else if (sSlotMachine->reelTimeSpinsLeft)
    {
        sSlotMachine->state = SLOTTASK_READY_NEW_RT_SPIN;
        CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
    }
    return TRUE;
}

static bool8 SlotTask_ReadyNewReelTimeSpin(struct Task *task)
{
    if (IsDigitalDisplayAnimFinished())
        sSlotMachine->state = SLOTTASK_ASK_INSERT_BET;
    return FALSE;
}

static bool8 SlotTask_AskInsertBet(struct Task *task)
{
    CreateDigitalDisplayScene(DIG_DISPLAY_INSERT_BET);
    sSlotMachine->state = SLOTTASK_BET_INPUT;
    if (sSlotMachine->coins >= MAX_COINS)
        sSlotMachine->state = SLOTTASK_MSG_MAX_COINS;
    return TRUE;
}

static bool8 SlotTask_HandleBetInput(struct Task *task)
{
    s16 i;

    if (JOY_NEW(SELECT_BUTTON))
    {
        OpenInfoBox(DIG_DISPLAY_INSERT_BET);
        sSlotMachine->state = SLOTTASK_WAIT_INFO_BOX;
    }
    // Try to bet the max amount
    else if (JOY_NEW(R_BUTTON))
    {
        if (sSlotMachine->coins - (MAX_BET - sSlotMachine->bet) >= 0)
        {
            for (i = sSlotMachine->bet; i < MAX_BET; i++)
                LightenBetTiles(i);
            sSlotMachine->coins -= (MAX_BET - sSlotMachine->bet);
            sSlotMachine->bet = MAX_BET;
            sSlotMachine->state = SLOTTASK_START_SPIN;
            PlaySE(SE_SHOP);
        }
        // Not enough coins
        else
        {
            sSlotMachine->state = SLOTTASK_MSG_NEED_3_COINS;
        }
    }
    else
    {
        // Increase bet
        if (JOY_NEW(DPAD_DOWN) && sSlotMachine->coins != 0)
        {
            PlaySE(SE_SHOP);
            LightenBetTiles(sSlotMachine->bet);
            sSlotMachine->coins--;
            sSlotMachine->bet++;
        }

        // Maxed bet or finished betting
        if (sSlotMachine->bet >= MAX_BET || (sSlotMachine->bet != 0 && JOY_NEW(A_BUTTON)))
            sSlotMachine->state = SLOTTASK_START_SPIN;

        // Quit prompt
        if (JOY_NEW(B_BUTTON))
            sSlotMachine->state = SLOTTASK_ASK_QUIT;
    }
    return FALSE;
}


static bool8 SlotTask_PrintMsg_Need3Coins(struct Task *task)
{
    DrawDialogueFrame(WIN_MSG, FALSE);
    AddTextPrinterParameterized(WIN_MSG, FONT_NORMAL, gText_YouDontHaveThreeCoins, 0, 2, 0, 0); // JP text x offset = 2
    CopyWindowToVram(WIN_MSG, COPYWIN_FULL);
    sSlotMachine->state = SLOTTASK_WAIT_MSG_NEED_3_COINS;
    return FALSE;
}

static bool8 SlotTask_WaitMsg_Need3Coins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(WIN_MSG, TRUE);
        sSlotMachine->state = SLOTTASK_BET_INPUT;
    }
    return FALSE;
}

static bool8 SlotTask_WaitInfoBox(struct Task *task)
{
    if (IsInfoBoxClosed())
        sSlotMachine->state = SLOTTASK_BET_INPUT;
    return FALSE;
}

static bool8 SlotTask_StartSpin(struct Task *task)
{
    DrawMachineBias();
    DestroyDigitalDisplayScene();

    SpinSlotReel(LEFT_REEL);
    SpinSlotReel(MIDDLE_REEL);
    SpinSlotReel(RIGHT_REEL);

    IncrementDailySlotsUses();

    task->tTimer = 0;
    if (sSlotMachine->machineBias & BIAS_REELTIME)
    {
        BeginReelTime();
        sSlotMachine->state = SLOTTASK_START_RT_SPIN;
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_STOP_REEL);
        sSlotMachine->state = SLOTTASK_RESET_BIAS_FAILURE;
    }
    sSlotMachine->reelSpeed = REEL_NORMAL_SPEED;
    if (sSlotMachine->reelTimeSpinsLeft)
        sSlotMachine->reelSpeed = ReelTimeSpeed();
    return FALSE;
}

static bool8 SlotTask_StartReelTimeSpin(struct Task *task)
{
    if (IsReelTimeTaskDone())
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_STOP_REEL);
        sSlotMachine->machineBias &= ~BIAS_REELTIME;
        sSlotMachine->state = SLOTTASK_RESET_BIAS_FAILURE;
    }
    return FALSE;
}

static bool8 SlotTask_ResetBiasFailure(struct Task *task)
{
    if (++task->tTimer >= 30)
    {
        ResetBiasFailure();
        sSlotMachine->state = SLOTTASK_WAIT_REEL_STOP;
    }
    return FALSE;
}

static bool8 SlotTask_WaitReelStop(struct Task *task)
{
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_CONTEST_PLACE);
        StopSlotReel(sSlotMachine->currentReel);
        PressStopReelButton(sSlotMachine->currentReel);
        sSlotMachine->state = SLOTTASK_WAIT_ALL_REELS_STOP;
    }
    return FALSE;
}

static bool8 SlotTask_WaitAllReelsStop(struct Task *task)
{
    if (!IsSlotReelMoving(sSlotMachine->currentReel))
    {
        sSlotMachine->currentReel++;
        sSlotMachine->state = SLOTTASK_WAIT_REEL_STOP;
        if (sSlotMachine->currentReel >= NUM_REELS)
        {
            sSlotMachine->state = SLOTTASK_CHECK_MATCHES;
        }
        return TRUE;
    }
    return FALSE;
}

static bool8 SlotTask_CheckMatches(struct Task *task)
{
    sSlotMachine->machineBias &= (BIAS_STRAIGHT_7 | BIAS_MIXED_7);
    CheckMatch();
    if (sSlotMachine->reelTimeSpinsLeft)
    {
        sSlotMachine->reelTimeSpinsLeft--;
        sSlotMachine->reelTimeSpinsUsed++;
    }

    if (sSlotMachine->matches)
    {
        sSlotMachine->state = SLOTTASK_WAIT_PAYOUT;
        AwardPayout();
        FlashSlotMachineLights();
        if ((sSlotMachine->netCoinLoss -= sSlotMachine->payout) < 0)
        {
            sSlotMachine->netCoinLoss = 0;
        }
        if (sSlotMachine->matches & ((1 << MATCH_BLUE_7) | (1 << MATCH_RED_7)))
        {
            PlayFanfare(MUS_SLOTS_JACKPOT);
            CreateDigitalDisplayScene(DIG_DISPLAY_BONUS_BIG);
        }
        else if (sSlotMachine->matches & (1 << MATCH_MIXED_7))
        {
            PlayFanfare(MUS_SLOTS_JACKPOT);
            CreateDigitalDisplayScene(DIG_DISPLAY_BONUS_REG);
        }
        else
        {
            PlayFanfare(MUS_SLOTS_WIN);
            CreateDigitalDisplayScene(DIG_DISPLAY_WIN);
        }

        if (sSlotMachine->matches & ((1 << MATCH_MIXED_7) | (1 << MATCH_BLUE_7) | (1 << MATCH_RED_7)))
        {
            sSlotMachine->machineBias &= ~(BIAS_STRAIGHT_7 | BIAS_MIXED_7);
            if (sSlotMachine->matches & ((1 << MATCH_BLUE_7) | (1 << MATCH_RED_7)))
            {
                // ReelTime ends if it was ongoing
                sSlotMachine->reelTimeSpinsLeft = 0;
                sSlotMachine->reelTimeSpinsUsed = 0;
                sSlotMachine->luckyGame = FALSE;
                if (sSlotMachine->matches & (1 << MATCH_BLUE_7))
                    sSlotMachine->luckyGame = TRUE;
            }
        }
        if (sSlotMachine->matches & (1 << MATCH_POWER) && sSlotMachine->pikaPowerBolts < 16)
        {
            sSlotMachine->pikaPowerBolts++;
            AddPikaPowerBolt(sSlotMachine->pikaPowerBolts);
        }
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_LOSE);
        sSlotMachine->state = SLOTTASK_NO_MATCHES;
        if ((sSlotMachine->netCoinLoss += sSlotMachine->bet) > MAX_COINS)
            sSlotMachine->netCoinLoss = MAX_COINS;
    }
    return FALSE;
}


static bool8 SlotTask_WaitPayout(struct Task *task)
{
    if (IsFinalTask_Task_Payout())
        sSlotMachine->state = SLOTTASK_END_PAYOUT;
    return FALSE;
}

static bool8 SlotTask_EndPayout(struct Task *task)
{
    if (TryStopSlotMachineLights())
    {
        sSlotMachine->state = SLOTTASK_RESET_BET_TILES;

        if (sSlotMachine->matches & ((1 << MATCH_RED_7) | (1 << MATCH_BLUE_7)))
            IncrementGameStat(GAME_STAT_SLOT_JACKPOTS);

        if (sSlotMachine->matches & (1 << MATCH_REPLAY))
        {
            sSlotMachine->currentReel = LEFT_REEL;
            sSlotMachine->state = SLOTTASK_START_SPIN;
        }

        if (sSlotMachine->matches & (1 << MATCH_POWER))
            sSlotMachine->state = SLOTTASK_MATCHED_POWER;

        if (sSlotMachine->reelTimeSpinsLeft && sSlotMachine->matches & (1 << MATCH_REPLAY))
        {
            CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
            sSlotMachine->state = SLOTTASK_WAIT_RT_ANIM;
        }
    }
    return FALSE;
}

static bool8 SlotTask_MatchedPower(struct Task *task)
{
    if (!IsPikaPowerBoltAnimating())
    {
        sSlotMachine->state = SLOTTASK_RESET_BET_TILES;
        if (sSlotMachine->matches & (1 << MATCH_REPLAY))
        {
            sSlotMachine->state = SLOTTASK_START_SPIN;
            if (sSlotMachine->reelTimeSpinsLeft)
            {
                CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
                sSlotMachine->state = SLOTTASK_WAIT_RT_ANIM;
            }
        }
    }
    return FALSE;
}

static bool8 SlotTask_WaitReelTimeAnim(struct Task *task)
{
    if (IsDigitalDisplayAnimFinished())
    {
        sSlotMachine->state = SLOTTASK_RESET_BET_TILES;
        if (sSlotMachine->matches & (1 << MATCH_REPLAY))
        {
            sSlotMachine->state = SLOTTASK_START_SPIN;
        }
    }
    return FALSE;
}

static bool8 SlotTask_ResetBetTiles(struct Task *task)
{
    DarkenBetTiles(0);
    DarkenBetTiles(1);
    DarkenBetTiles(2);
    sSlotMachine->state = SLOTTASK_READY_NEW_SPIN;
    return FALSE;
}

static bool8 SlotTask_NoMatches(struct Task *task)
{
    if (++task->tTimer2 > 64)
    {
        task->tTimer2 = 0;
        sSlotMachine->state = SLOTTASK_RESET_BET_TILES;
    }
    return FALSE;
}

static bool8 SlotTask_AskQuit(struct Task *task)
{
    DrawDialogueFrame(WIN_MSG, FALSE);
    AddTextPrinterParameterized(WIN_MSG, FONT_NORMAL, gText_QuitTheGame, 0, 2, 0, 0); // JP text x offset = 2
    CopyWindowToVram(WIN_MSG, COPYWIN_FULL);
    CreateYesNoMenuParameterized(0x15, 7, 0x214, 0x194, 0xE, 0xF); // JP baseBlock = 0x194 (US uses 0x180)
    sSlotMachine->state = SLOTTASK_HANDLE_QUIT_INPUT;
    return FALSE;
}

static bool8 SlotTask_HandleQuitInput(struct Task *task)
{
    s8 input = Menu_ProcessInputNoWrapClearOnChoose();
    if (input == 0) // Chose to quit
    {
        ClearDialogWindowAndFrame(WIN_MSG, TRUE);
        DarkenBetTiles(0);
        DarkenBetTiles(1);
        DarkenBetTiles(2);
        sSlotMachine->coins += sSlotMachine->bet;
        sSlotMachine->state = SLOTTASK_END;
    }
    else if (input == 1 || input == MENU_B_PRESSED) // Chose not to quit
    {
        ClearDialogWindowAndFrame(WIN_MSG, TRUE);
        sSlotMachine->state = SLOTTASK_BET_INPUT;
    }
    return FALSE;
}

static bool8 SlotTask_PrintMsg_MaxCoins(struct Task *task)
{
    DrawDialogueFrame(WIN_MSG, FALSE);
    AddTextPrinterParameterized(WIN_MSG, FONT_NORMAL, gText_YouveGot9999Coins, 0, 2, 0, 0); // JP text x offset = 2
    CopyWindowToVram(WIN_MSG, COPYWIN_FULL);
    sSlotMachine->state = SLOTTASK_WAIT_MSG_MAX_COINS;
    return FALSE;
}

static bool8 SlotTask_WaitMsg_MaxCoins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(WIN_MSG, TRUE);
        sSlotMachine->state = SLOTTASK_BET_INPUT;
    }
    return FALSE;
}

static bool8 SlotTask_PrintMsg_NoMoreCoins(struct Task *task)
{
    DrawDialogueFrame(WIN_MSG, FALSE);
    AddTextPrinterParameterized(WIN_MSG, FONT_NORMAL, gText_YouveRunOutOfCoins, 0, 2, 0, 0); // JP text x offset = 2
    CopyWindowToVram(WIN_MSG, COPYWIN_FULL);
    sSlotMachine->state = SLOTTASK_WAIT_MSG_NO_MORE_COINS;
    return FALSE;
}

static bool8 SlotTask_WaitMsg_NoMoreCoins(struct Task *task)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        ClearDialogWindowAndFrame(WIN_MSG, TRUE);
        sSlotMachine->state = SLOTTASK_END;
    }
    return FALSE;
}

static bool8 SlotTask_EndGame(struct Task *task)
{
    SetCoins(sSlotMachine->coins);
    TryPutFindThatGamerOnAir(GetCoins());
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    sSlotMachine->state++; // SLOTTASK_FREE
    return FALSE;
}

static bool8 SlotTask_FreeDataStructures(struct Task *task)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSlotMachine->prevMainCb);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Reel);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Time);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Insert);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Stop);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Win);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Lose);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Bonus);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Big);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Reg);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_AButton);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Smoke);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Number);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_Pokeball);
        FREE_AND_SET_NULL(sImageTable_DigitalDisplay_DPad);
        TRY_FREE_AND_SET_NULL(sImageTable_ReelTimePikachu);
        TRY_FREE_AND_SET_NULL(sImageTable_ReelTimeMachineAntennae);
        TRY_FREE_AND_SET_NULL(sImageTable_ReelTimeMachine);
        TRY_FREE_AND_SET_NULL(sImageTable_BrokenReelTimeMachine);
        FREE_AND_SET_NULL(sMenuGfx);
        FREE_AND_SET_NULL(sSelectedPikaPowerTile);
        FREE_AND_SET_NULL(sReelOverlay_Tilemap);
        FREE_AND_SET_NULL(sDigitalDisplayGfxPtr);
        FREE_AND_SET_NULL(sReelTimeGfxPtr);
        FREE_AND_SET_NULL(sReelButtonPress_Tilemap);
        FREE_AND_SET_NULL(sReelBackground_Gfx);
        FREE_AND_SET_NULL(sReelBackgroundSpriteSheet);
        FREE_AND_SET_NULL(sSlotMachineSpritesheetsPtr);
        FREE_AND_SET_NULL(sSlotMachine);
    }
    return FALSE;
}


__attribute__((section(".rodata.sReelTimeExplodeProbability")))
static const u16 sReelTimeExplodeProbability[] = {
    128, 175, 200, 225, 256
};

// Returns true if the ReelTime machine should explode. Each time we check,
// the odds of explosion increase.
static bool8 ShouldReelTimeMachineExplode(u16 check)
{
    u16 rval = Random() & 0xff;
    if (rval < sReelTimeExplodeProbability[check])
        return TRUE;
    else
        return FALSE;
}

__attribute__((section(".rodata.sSlotMatchFlags")))
static const u16 sSlotMatchFlags[] = {
    [MATCH_CHERRY]        = 1 << MATCH_CHERRY,
    [MATCH_TOPBOT_CHERRY] = 1 << MATCH_TOPBOT_CHERRY,
    [MATCH_REPLAY]        = 1 << MATCH_REPLAY,
    [MATCH_LOTAD]         = 1 << MATCH_LOTAD,
    [MATCH_AZURILL]       = 1 << MATCH_AZURILL,
    [MATCH_POWER]         = 1 << MATCH_POWER,
    [MATCH_MIXED_7]       = 1 << MATCH_MIXED_7,
    [MATCH_RED_7]         = 1 << MATCH_RED_7,
    [MATCH_BLUE_7]        = 1 << MATCH_BLUE_7,
};

__attribute__((section(".rodata.sSlotPayouts")))
static const u16 sSlotPayouts[] = {
    [MATCH_CHERRY]        = 2,
    [MATCH_TOPBOT_CHERRY] = 4,
    [MATCH_REPLAY]        = 0,
    [MATCH_LOTAD]         = 6,
    [MATCH_AZURILL]       = 12,
    [MATCH_POWER]         = 3,
    [MATCH_MIXED_7]       = 90,
    [MATCH_RED_7]         = 300,
    [MATCH_BLUE_7]        = 300,
};

static void CheckMatch(void)
{
    sSlotMachine->matches = 0;
    CheckMatch_CenterRow();
    if (sSlotMachine->bet > 1)
        CheckMatch_TopAndBottom();
    if (sSlotMachine->bet > 2)
        CheckMatch_Diagonals();
}

static void CheckMatch_CenterRow(void)
{
    u8 sym1, sym2, sym3, match;

    sym1 = GetSymbolAtRest(LEFT_REEL, 2);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 2);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 2);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matches |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_MIDDLE_ROW);
    }
}

static void CheckMatch_TopAndBottom(void)
{
    u8 sym1, sym2, sym3, match;

    sym1 = GetSymbolAtRest(LEFT_REEL, 1);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 1);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 1);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        if (match == MATCH_CHERRY)
            match = MATCH_TOPBOT_CHERRY;
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matches |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_TOP_ROW);
    }
    sym1 = GetSymbolAtRest(LEFT_REEL, 3);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 3);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 3);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        if (match == MATCH_CHERRY)
            match = MATCH_TOPBOT_CHERRY;
        sSlotMachine->payout += sSlotPayouts[match];
        sSlotMachine->matches |= sSlotMatchFlags[match];
        FlashMatchLine(MATCH_BOTTOM_ROW);
    }
}








__attribute__((section(".rodata.sSymbolToMatch")))
static const u8 sSymbolToMatch[] = {
    [SYMBOL_7_RED]   = MATCH_RED_7,
    [SYMBOL_7_BLUE]  = MATCH_BLUE_7,
    [SYMBOL_AZURILL] = MATCH_AZURILL,
    [SYMBOL_LOTAD]   = MATCH_LOTAD,
    [SYMBOL_CHERRY]  = MATCH_CHERRY,
    [SYMBOL_POWER]   = MATCH_POWER,
    [SYMBOL_REPLAY]  = MATCH_REPLAY,
    [SYMBOL_REPLAY + 1] = 0, // JP ROM trailing padding byte
};

static void CheckMatch_Diagonals(void)
{
    u8 sym1, sym2, sym3, match;

    sym1 = GetSymbolAtRest(LEFT_REEL, 1);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 2);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 3);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        // Don't add payout for cherry, since it's already counted in
        // CheckMatch_TopAndBottom().
        if (match != MATCH_CHERRY)
        {
            sSlotMachine->payout += sSlotPayouts[match];
            sSlotMachine->matches |= sSlotMatchFlags[match];
        }
        FlashMatchLine(MATCH_NWSE_DIAG);
    }
    sym1 = GetSymbolAtRest(LEFT_REEL, 3);
    sym2 = GetSymbolAtRest(MIDDLE_REEL, 2);
    sym3 = GetSymbolAtRest(RIGHT_REEL, 1);
    match = GetMatchFromSymbols(sym1, sym2, sym3);
    if (match != MATCH_NONE)
    {
        // Don't add payout for cherry, since it's already counted in
        // CheckMatch_TopAndBottom().
        if (match != MATCH_CHERRY)
        {
            sSlotMachine->payout += sSlotPayouts[match];
            sSlotMachine->matches |= sSlotMatchFlags[match];
        }
        FlashMatchLine(MATCH_NESW_DIAG);
    }
}

static u8 GetMatchFromSymbols(u8 sym1, u8 sym2, u8 sym3)
{
    if (sym1 == sym2 && sym1 == sym3)
        return sSymbolToMatch[sym1];
    if (sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE)
        return MATCH_MIXED_7;
    if (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED)
        return MATCH_MIXED_7;
    if (sym1 == SYMBOL_CHERRY)
        return MATCH_CHERRY;
    return MATCH_NONE;
}






#undef tTimer
#define tTimer data[1]

static void AwardPayout(void)
{
    Task_Payout(CreateTask(Task_Payout, 4));
}

static bool8 IsFinalTask_Task_Payout(void)
{
    if (FindTaskIdByFunc(Task_Payout) == TAIL_SENTINEL)
        return TRUE;
    else
        return FALSE;
}

static void Task_Payout(u8 taskId)
{
    while (sPayoutTasks[gTasks[taskId].data[0]](&gTasks[taskId]))
        ;
}

static bool8 PayoutTask_Init(struct Task *task)
{
    if (IsMatchLineDoneFlashingBeforePayout())
    {
        task->tState++; // PAYOUT_TASK_GIVE_PAYOUT
        if (sSlotMachine->payout == 0)
        {
            task->tState = PAYOUT_TASK_FREE;
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 PayoutTask_GivePayout(struct Task *task)
{
    if (!task->tTimer--)
    {
        if (IsFanfareTaskInactive())
            PlaySE(SE_PIN);
        sSlotMachine->payout--;
        if (sSlotMachine->coins < MAX_COINS)
            sSlotMachine->coins++;
        task->tTimer = 8;
        if (JOY_HELD(A_BUTTON))
            task->tTimer = 4;
    }
    if (IsFanfareTaskInactive() && JOY_NEW(START_BUTTON))
    {
        PlaySE(SE_PIN);
        sSlotMachine->coins += sSlotMachine->payout;
        if (sSlotMachine->coins > MAX_COINS)
            sSlotMachine->coins = MAX_COINS;
        sSlotMachine->payout = 0;
    }
    if (sSlotMachine->payout == 0)
        task->tState++; // PAYOUT_TASK_FREE
    return FALSE;
}

static bool8 PayoutTask_Free(struct Task *task)
{
    if (TryStopMatchLinesFlashing())
        DestroyTask(FindTaskIdByFunc(Task_Payout));
    return FALSE;
}













__attribute__((section(".rodata.sSlotTasks")))
static const bool8 (*const sSlotTasks[])(struct Task *task) =
{
    [SLOTTASK_UNFADE]                 = SlotTask_UnfadeScreen,
    [SLOTTASK_WAIT_FADE]              = SlotTask_WaitUnfade,
    [SLOTTASK_READY_NEW_SPIN]         = SlotTask_ReadyNewSpin,
    [SLOTTASK_READY_NEW_RT_SPIN]      = SlotTask_ReadyNewReelTimeSpin,
    [SLOTTASK_ASK_INSERT_BET]         = SlotTask_AskInsertBet,
    [SLOTTASK_BET_INPUT]              = SlotTask_HandleBetInput,
    [SLOTTASK_MSG_NEED_3_COINS]       = SlotTask_PrintMsg_Need3Coins,
    [SLOTTASK_WAIT_MSG_NEED_3_COINS]  = SlotTask_WaitMsg_Need3Coins,
    [SLOTTASK_WAIT_INFO_BOX]          = SlotTask_WaitInfoBox,
    [SLOTTASK_START_SPIN]             = SlotTask_StartSpin,
    [SLOTTASK_START_RT_SPIN]          = SlotTask_StartReelTimeSpin,
    [SLOTTASK_RESET_BIAS_FAILURE]     = SlotTask_ResetBiasFailure,
    [SLOTTASK_WAIT_REEL_STOP]         = SlotTask_WaitReelStop,
    [SLOTTASK_WAIT_ALL_REELS_STOP]    = SlotTask_WaitAllReelsStop,
    [SLOTTASK_CHECK_MATCHES]          = SlotTask_CheckMatches,
    [SLOTTASK_WAIT_PAYOUT]            = SlotTask_WaitPayout,
    [SLOTTASK_END_PAYOUT]             = SlotTask_EndPayout,
    [SLOTTASK_MATCHED_POWER]          = SlotTask_MatchedPower,
    [SLOTTASK_WAIT_RT_ANIM]           = SlotTask_WaitReelTimeAnim,
    [SLOTTASK_RESET_BET_TILES]        = SlotTask_ResetBetTiles,
    [SLOTTASK_NO_MATCHES]             = SlotTask_NoMatches,
    [SLOTTASK_ASK_QUIT]               = SlotTask_AskQuit,
    [SLOTTASK_HANDLE_QUIT_INPUT]      = SlotTask_HandleQuitInput,
    [SLOTTASK_MSG_MAX_COINS]          = SlotTask_PrintMsg_MaxCoins,
    [SLOTTASK_WAIT_MSG_MAX_COINS]     = SlotTask_WaitMsg_MaxCoins,
    [SLOTTASK_MSG_NO_MORE_COINS]      = SlotTask_PrintMsg_NoMoreCoins,
    [SLOTTASK_WAIT_MSG_NO_MORE_COINS] = SlotTask_WaitMsg_NoMoreCoins,
    [SLOTTASK_END]                    = SlotTask_EndGame,
    [SLOTTASK_FREE]                   = SlotTask_FreeDataStructures,
};

__attribute__((section(".rodata.sPayoutTasks")))
static const bool8 (*const sPayoutTasks[])(struct Task *task) =
{
    [PAYOUT_TASK_INIT]        = PayoutTask_Init,
    [PAYOUT_TASK_GIVE_PAYOUT] = PayoutTask_GivePayout,
    [PAYOUT_TASK_FREE]        = PayoutTask_Free,
};


__attribute__((section(".rodata.sReelSymbols")))
static const u8 sReelSymbols[NUM_REELS][SYMBOLS_PER_REEL] =
{
    [LEFT_REEL] = {
        SYMBOL_7_RED,   SYMBOL_CHERRY, SYMBOL_AZURILL, SYMBOL_REPLAY, SYMBOL_POWER, SYMBOL_LOTAD, SYMBOL_7_BLUE,
        SYMBOL_LOTAD,   SYMBOL_CHERRY, SYMBOL_POWER,   SYMBOL_REPLAY, SYMBOL_AZURILL, SYMBOL_7_RED, SYMBOL_POWER,
        SYMBOL_LOTAD,   SYMBOL_REPLAY, SYMBOL_AZURILL, SYMBOL_7_BLUE, SYMBOL_POWER, SYMBOL_LOTAD, SYMBOL_REPLAY
    },
    [MIDDLE_REEL] = {
        SYMBOL_7_RED,   SYMBOL_CHERRY, SYMBOL_REPLAY, SYMBOL_LOTAD, SYMBOL_AZURILL, SYMBOL_CHERRY, SYMBOL_REPLAY,
        SYMBOL_POWER,   SYMBOL_POWER,  SYMBOL_LOTAD,  SYMBOL_7_BLUE, SYMBOL_LOTAD, SYMBOL_REPLAY, SYMBOL_CHERRY,
        SYMBOL_AZURILL, SYMBOL_LOTAD, SYMBOL_REPLAY, SYMBOL_CHERRY, SYMBOL_LOTAD, SYMBOL_REPLAY, SYMBOL_CHERRY
    },
    [RIGHT_REEL] = {
        SYMBOL_7_RED,   SYMBOL_POWER, SYMBOL_7_BLUE, SYMBOL_REPLAY, SYMBOL_LOTAD, SYMBOL_AZURILL, SYMBOL_REPLAY,
        SYMBOL_LOTAD,   SYMBOL_POWER, SYMBOL_AZURILL, SYMBOL_REPLAY, SYMBOL_LOTAD, SYMBOL_AZURILL, SYMBOL_POWER,
        SYMBOL_REPLAY,  SYMBOL_LOTAD, SYMBOL_AZURILL, SYMBOL_POWER,  SYMBOL_REPLAY, SYMBOL_LOTAD, SYMBOL_CHERRY
    },
};

// JP ROM has a trailing padding byte after the 6 reel-time symbols.
__attribute__((section(".rodata.sReelTimeSymbols")))
static const u8 sReelTimeSymbols[] = {
    1, 0, 5, 4, 3, 2, 0
};

static u8 GetSymbolAtRest(u8 reel, s16 offset)
{
    s16 pos = (sSlotMachine->reelPositions[reel] + offset) % SYMBOLS_PER_REEL;
    if (pos < 0)
        pos += SYMBOLS_PER_REEL;
    return sReelSymbols[reel][pos];
}

// Calculates GetSymbolAtRest as if the reel were snapped downwards into place.
static u8 GetSymbol(u8 reel, s16 offset)
{
    s16 inc = 0;
    s16 pixelOffset = sSlotMachine->reelPixelOffsets[reel] % REEL_SYMBOL_HEIGHT;
    if (pixelOffset != 0)
        inc = -1;
    return GetSymbolAtRest(reel, offset + inc);
}

static u8 GetReelTimeSymbol(s16 offset)
{
    s16 newPosition = (sSlotMachine->reeltimePosition + offset) % REELTIME_SYMBOLS;
    if (newPosition < 0)
        newPosition += REELTIME_SYMBOLS;
    return sReelTimeSymbols[newPosition];
}








static void AdvanceSlotReel(u8 reelIndex, s16 value)
{
    sSlotMachine->reelPixelOffsets[reelIndex] += value;
    sSlotMachine->reelPixelOffsets[reelIndex] %= REEL_HEIGHT;
    sSlotMachine->reelPositions[reelIndex] = SYMBOLS_PER_REEL - sSlotMachine->reelPixelOffsets[reelIndex] / REEL_SYMBOL_HEIGHT;
}

// Advances the reel no further than the next symbol. Returns the remaining
// pixels until the next symbol.
s16 AdvanceSlotReelToNextSymbol(u8 reelIndex, s16 value)
{
    s16 offset = sSlotMachine->reelPixelOffsets[reelIndex] % REEL_SYMBOL_HEIGHT;
    if (offset != 0)
    {
        if (offset < value)
            value = offset;
        AdvanceSlotReel(reelIndex, value);
        offset = sSlotMachine->reelPixelOffsets[reelIndex] % REEL_SYMBOL_HEIGHT;
    }
    return offset;
}

static void AdvanceReeltimeReel(s16 value)
{
    sSlotMachine->reeltimePixelOffset += value;
    sSlotMachine->reeltimePixelOffset %= REELTIME_REEL_HEIGHT;
    sSlotMachine->reeltimePosition = REELTIME_SYMBOLS - sSlotMachine->reeltimePixelOffset / REELTIME_SYMBOL_HEIGHT;
}

// Advances the reel no further than the next symbol. Returns the remaining
// pixels until the next symbol.
s16 AdvanceReeltimeReelToNextSymbol(s16 value)
{
    s16 offset = sSlotMachine->reeltimePixelOffset % REELTIME_SYMBOL_HEIGHT;
    if (offset != 0)
    {
        if (offset < value)
            value = offset;
        AdvanceReeltimeReel(value);
        offset = sSlotMachine->reeltimePixelOffset % REELTIME_SYMBOL_HEIGHT;
    }
    return offset;
}









#define tReelId data[15]

static void CreateReelTasks(void)
{
    u8 i;
    for (i = 0; i < NUM_REELS; i++)
    {
        u8 taskId = CreateTask(Task_Reel, 2);
        gTasks[taskId].tReelId = i;
        sSlotMachine->slotReelTasks[i] = taskId;
        Task_Reel(taskId);
    }
}

static void SpinSlotReel(u8 reelIndex)
{
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tState = REEL_TASK_SPIN;
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tMoving = TRUE;
}

static void StopSlotReel(u8 reelIndex)
{
    gTasks[sSlotMachine->slotReelTasks[reelIndex]].tState = REEL_TASK_DECIDE_STOP;
}

static bool8 IsSlotReelMoving(u8 reelIndex)
{
    return gTasks[sSlotMachine->slotReelTasks[reelIndex]].tMoving;
}

static void Task_Reel(u8 taskId)
{
    while (sReelTasks[gTasks[taskId].tState](&gTasks[taskId]))
        ;
}

static bool8 ReelTask_StayStill(struct Task *task)
{
    return FALSE;
}

static bool8 ReelTask_Spin(struct Task *task)
{
    AdvanceSlotReel(task->tReelId, sSlotMachine->reelSpeed);
    return FALSE;
}

static bool8 ReelTask_DecideStop(struct Task *task)
{
    task->tState++; // REEL_TASK_STOP_MOVE
    sSlotMachine->winnerRows[task->tReelId] = 0;
    sSlotMachine->reelExtraTurns[task->tReelId] = 0;

    if (sSlotMachine->reelTimeSpinsLeft == 0)
    {
        if (sSlotMachine->machineBias == 0 || !sSlotMachine->didNotFailBias || !sDecideStop_Bias[task->tReelId]())
        {
            sSlotMachine->didNotFailBias = FALSE;
            sDecideStop_NoBias[task->tReelId]();
        }
    }
    task->tExtraTurns = sSlotMachine->reelExtraTurns[task->tReelId];
    return TRUE;
}

#undef tTimer
#define tTimer data[2]

static bool8 ReelTask_MoveToStop(struct Task *task)
{
    u16 reelStopShocks[5]; // JP copies 10 bytes; sReelStopShocks has a trailing padding entry
    s16 reelPixelPos;

    memcpy(reelStopShocks, sReelStopShocks, sizeof(reelStopShocks));
    reelPixelPos = sSlotMachine->reelPixelOffsets[task->tReelId] % REEL_SYMBOL_HEIGHT;
    if (reelPixelPos != 0)
    {
        reelPixelPos = AdvanceSlotReelToNextSymbol(task->tReelId, sSlotMachine->reelSpeed);
    }
    else if (sSlotMachine->reelExtraTurns[task->tReelId])
    {
        sSlotMachine->reelExtraTurns[task->tReelId]--;
        AdvanceSlotReel(task->tReelId, sSlotMachine->reelSpeed);
        reelPixelPos = sSlotMachine->reelPixelOffsets[task->tReelId] % REEL_SYMBOL_HEIGHT;
    }

    if (reelPixelPos == 0 && sSlotMachine->reelExtraTurns[task->tReelId] == 0)
    {
        task->tState++; // REEL_TASK_STOP_SHAKE
        task->tShockMagnitude = reelStopShocks[task->tExtraTurns];
        task->tTimer = 0;
    }
    return FALSE;
}

static bool8 ReelTask_ShakingStop(struct Task *task)
{
    sSlotMachine->reelShockOffsets[task->tReelId] = task->tShockMagnitude;
    task->tShockMagnitude = -task->tShockMagnitude;
    task->tTimer++;
    if ((task->tTimer & 0x3) == 0)
        task->tShockMagnitude >>= 1;
    if (task->tShockMagnitude == 0)
    {
        task->tState = 0;
        task->tMoving = FALSE;
        sSlotMachine->reelShockOffsets[task->tReelId] = 0;
    }
    return FALSE;
}


__attribute__((section(".rodata.sBiasSymbols")))
static const u8 sBiasSymbols[] = {
    SYMBOL_REPLAY,  // BIAS_REPLAY
    SYMBOL_CHERRY,  // BIAS_CHERRY
    SYMBOL_LOTAD,   // BIAS_LOTAD
    SYMBOL_AZURILL, // BIAS_AZURILL
    SYMBOL_POWER,   // BIAS_POWER
    SYMBOL_7_RED,   // BIAS_REELTIME
    SYMBOL_7_RED,   // BIAS_MIXED_7
    SYMBOL_7_RED    // BIAS_STRAIGHT_7
};

static u8 GetBiasSymbol(u8 machineBias)
{
    u8 i;

    for (i = 0; i < 8; i++)
    {
        if (machineBias & 1)
            return sBiasSymbols[i];
        machineBias >>= 1;
    }
    return 0;
}

__attribute__((section(".rodata.sDecideStop_Bias_Reel1_Bets")))
static bool8 (*const sDecideStop_Bias_Reel1_Bets[MAX_BET])(u8 sym1, u8 sym2) =
{
    DecideStop_Bias_Reel1_Bet1,
    DecideStop_Bias_Reel1_Bet2or3,
    DecideStop_Bias_Reel1_Bet2or3,
};

bool8 DecideStop_Bias_Reel1(void)
{
    u8 sym2 = GetBiasSymbol(sSlotMachine->machineBias);
    u8 sym1 = sym2;
    if (sSlotMachine->machineBias & (BIAS_STRAIGHT_7 | BIAS_MIXED_7))
    {
        sym1 = SYMBOL_7_RED;
        sym2 = SYMBOL_7_BLUE;
    }
    return sDecideStop_Bias_Reel1_Bets[sSlotMachine->bet - 1](sym1, sym2);
}



static bool8 AreCherriesOnScreen_Reel1(s16 turns)
{
    if (GetSymbol(LEFT_REEL, 1 - turns) == SYMBOL_CHERRY
        || GetSymbol(LEFT_REEL, 2 - turns) == SYMBOL_CHERRY
        || GetSymbol(LEFT_REEL, 3 - turns) == SYMBOL_CHERRY)
        return TRUE;
    else
        return FALSE;
}

static bool8 BiasedTowardCherryOr7s(void)
{
    if (sSlotMachine->machineBias & (BIAS_STRAIGHT_7 | BIAS_MIXED_7 | BIAS_CHERRY))
        return TRUE;
    else
        return FALSE;
}

// If a bias symbol appears in the center of reel 1 within the next 4 turns,
// stop there. That symbol becomes the biasSymbol for the subsequent reels.
static bool8 DecideStop_Bias_Reel1_Bet1(u8 sym1, u8 sym2)
{
    s16 i;

    for (i = 0; i <= MAX_EXTRA_TURNS; i++)
    {
        if (EitherSymbolAtPos_Reel1(2 - i, sym1, sym2))
        {
            sSlotMachine->winnerRows[LEFT_REEL] = 2;
            sSlotMachine->reelExtraTurns[LEFT_REEL] = i;
            return TRUE;
        }
    }
    return FALSE;
}

// There is slightly different behavior depending on the machine's bias.
//
// Bias toward cherry or 7s:
//  - Check if a cherry or 7 is currently on screen. If so, stop immediately.
//  - Roll up to 4 extra turns to see if a cherry or 7 enters the screen:
//     - If it enters after 1 turn, stop the reel when it gets the bottom row.
//     - Otherwise, if it enters before the 4th turn, stop the reel when it gets
//       to the middle row.
//     - If it enters on the 4th turn, stop here. It will be in the top row.
//
// Other bias:
//  - This is very similar, except the game is checking for the bias symbol
//    rather than cherries / 7s.
//
//    However, the game adds an additional constraint: it will not stop if there
//    will be any cherries on screen. Presumably, this ensures that you will not
//    get any matches if you fail to line up the bias symbol in the remaining
//    reels.
static bool8 DecideStop_Bias_Reel1_Bet2or3(u8 sym1, u8 sym2)
{
    s16 i;
    bool8 cherry7Bias = BiasedTowardCherryOr7s();
    if (cherry7Bias || !AreCherriesOnScreen_Reel1(0))
    {
        // Check the current screen
        for (i = 1; i <= 3; i++)
        {
            if (EitherSymbolAtPos_Reel1(i, sym1, sym2))
            {
                sSlotMachine->winnerRows[0] = i;
                sSlotMachine->reelExtraTurns[0] = 0;
                return TRUE;
            }
        }
    }

    // Check the next 4 turns
    for (i = 1; i <= MAX_EXTRA_TURNS; i++)
    {
        bool8 cherry7BiasCopy = cherry7Bias; // redundant
        if (cherry7BiasCopy || !AreCherriesOnScreen_Reel1(i))
        {
            if (EitherSymbolAtPos_Reel1(1 - i, sym1, sym2))
            {
                if (i == 1 && (cherry7BiasCopy || !AreCherriesOnScreen_Reel1(3)))
                {
                    sSlotMachine->winnerRows[0] = 3;
                    sSlotMachine->reelExtraTurns[0] = 3;
                    return TRUE;
                }
                if (i <= 3 && (cherry7BiasCopy || !AreCherriesOnScreen_Reel1(i + 1)))
                {
                    sSlotMachine->winnerRows[0] = 2;
                    sSlotMachine->reelExtraTurns[0] = i + 1;
                    return TRUE;
                }
                sSlotMachine->winnerRows[0] = 1;
                sSlotMachine->reelExtraTurns[0] = i;
                return TRUE;
            }
        }
    }
    return FALSE;
}










__attribute__((section(".rodata.sDecideStop_Bias_Reel2_Bets")))
static bool8 (*const sDecideStop_Bias_Reel2_Bets[MAX_BET])(void) =
{
    DecideStop_Bias_Reel2_Bet1or2,
    DecideStop_Bias_Reel2_Bet1or2,
    DecideStop_Bias_Reel2_Bet3,
};

bool8 DecideStop_Bias_Reel2(void)
{
    return sDecideStop_Bias_Reel2_Bets[sSlotMachine->bet - 1]();
}

// Turn at most 4 extra turns to try to line up the bias symbol in the same row
// as reel 1.
static bool8 DecideStop_Bias_Reel2_Bet1or2(void)
{
    s16 i;
    s16 reel1BiasRow = sSlotMachine->winnerRows[0];

    for (i = 0; i <= MAX_EXTRA_TURNS; i++)
    {
        if (GetSymbol(MIDDLE_REEL, reel1BiasRow - i) == sSlotMachine->biasSymbol)
        {
            sSlotMachine->winnerRows[1] = reel1BiasRow;
            sSlotMachine->reelExtraTurns[1] = i;
            return TRUE;
        }
    }
    return FALSE;
}

static bool8 DecideStop_Bias_Reel2_Bet3(void)
{
    s16 i;
    // If you can line up the bias symbol in the same row as reel 1 within 4
    // turns
    if (DecideStop_Bias_Reel2_Bet1or2())
    {
        // If bias symbol is not in the middle row of reel 1 and it takes either
        // 2 or 3 turns to get it in the same row for reel 2
        if (sSlotMachine->winnerRows[0] != 2 && sSlotMachine->reelExtraTurns[1] > 1 && sSlotMachine->reelExtraTurns[1] != 4)
        {
            // Try turning this into a diagonal match by lining up the bias
            // symbol in the middle row of reel 2 within 4 turns.
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                if (GetSymbol(MIDDLE_REEL, 2 - i) == sSlotMachine->biasSymbol)
                {
                    sSlotMachine->winnerRows[1] = 2;
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
        return TRUE;
    }

    // If you can't line up the bias symbol in the same row in 4 turns, and the
    // bias symbol is not in the middle row of reel 1
    if (sSlotMachine->winnerRows[0] != 2)
    {
        // Try to match the bias symbol in middle row of reel 2 within 4 turns.
        for (i = 0; i <= MAX_EXTRA_TURNS; i++)
        {
            if (GetSymbol(MIDDLE_REEL, 2 - i) == sSlotMachine->biasSymbol)
            {
                sSlotMachine->winnerRows[1] = 2;
                sSlotMachine->reelExtraTurns[1] = i;
                return TRUE;
            }
        }
    }
    return FALSE;
}








__attribute__((section(".rodata.sDecideStop_Bias_Reel3_Bets")))
static bool8 (*const sDecideStop_Bias_Reel3_Bets[MAX_BET])(u8 biasSymbol) =
{
    DecideStop_Bias_Reel3_Bet1or2,
    DecideStop_Bias_Reel3_Bet1or2,
    DecideStop_Bias_Reel3_Bet3,
};

// If the machine is biased toward mixed 7's, swap the color of the bias symbol
// from red 7 to blue 7, or vice versa.
bool8 DecideStop_Bias_Reel3(void)
{
    u8 biasSymbol = sSlotMachine->biasSymbol;
    if (sSlotMachine->machineBias & BIAS_MIXED_7)
    {
        biasSymbol = SYMBOL_7_RED;
        if (sSlotMachine->biasSymbol == SYMBOL_7_RED)
        {
            biasSymbol = SYMBOL_7_BLUE;
        }
    }
    return sDecideStop_Bias_Reel3_Bets[sSlotMachine->bet - 1](biasSymbol);
}

// Turn at most 4 extra turns to try to line up the bias symbol in the same
// row as reel 2.
static bool8 DecideStop_Bias_Reel3_Bet1or2(u8 biasSymbol)
{
    s16 i;
    s16 reel2BiasRow = sSlotMachine->winnerRows[1];

    for (i = 0; i <= MAX_EXTRA_TURNS; i++)
    {
        if (GetSymbol(RIGHT_REEL, reel2BiasRow - i) == biasSymbol)
        {
            sSlotMachine->winnerRows[2] = reel2BiasRow;
            sSlotMachine->reelExtraTurns[2] = i;
            return TRUE;
        }
    }
    return FALSE;
}

// Try to complete a match in reel 3 by lining up a bias symbol with the bias
// symbols from the first two reels.
static bool8 DecideStop_Bias_Reel3_Bet3(u8 biasSymbol)
{
    s16 i;
    s16 biasRow;

    // First two bias symbols in the same row. Try to line up bias symbol in
    // same the row here too
    if (sSlotMachine->winnerRows[0] == sSlotMachine->winnerRows[1])
        return DecideStop_Bias_Reel3_Bet1or2(biasSymbol);

    // Otherwise, try to line up the bias symbol diagonally
    if (sSlotMachine->winnerRows[0] == 1)
        biasRow = 3;
    else
        biasRow = 1;
    for (i = 0; i <= MAX_EXTRA_TURNS; i++)
    {
        if (GetSymbol(RIGHT_REEL, biasRow - i) == biasSymbol)
        {
            sSlotMachine->reelExtraTurns[2] = i;
            sSlotMachine->winnerRows[2] = biasRow;
            return TRUE;
        }
    }
    return FALSE;
}








__attribute__((section(".rodata.sDecideStop_NoBias_Reel2_Bets")))
static void (*const sDecideStop_NoBias_Reel2_Bets[MAX_BET])(void) =
{
    DecideStop_NoBias_Reel2_Bet1,
    DecideStop_NoBias_Reel2_Bet2,
    DecideStop_NoBias_Reel2_Bet3,
};

// Advance as many turns as needed until there are no cherries on screen in
// reel 1, as cherries would cause a match.
//
// Based on the distribution of reel 1, this will add at most 3 extra turns.
void DecideStop_NoBias_Reel1(void)
{
    s16 i = 0;

    while (AreCherriesOnScreen_Reel1(i) != 0)
        i++;
    sSlotMachine->reelExtraTurns[0] = i;
}

// If the machine doesn't have a bias, the reel stops immediately.
//
// Otherwise, the machine tries to taunt the player if it is biased toward
// straight 7's. This would only happen if the player did not stop near the
// correct-color 7, so the machine couldn't force a match.
//
// Instead, the machine now tries to line up the opposite-color 7, which is not
// a valid match.
void DecideStop_NoBias_Reel2(void)
{
    sDecideStop_NoBias_Reel2_Bets[sSlotMachine->bet - 1]();
}

// If the machine has no bias, stop immediately.
//
// Otherwise, the machine manipulates the results if all the following
// conditions are met:
// If
//  - The machine is biased toward straight 7's
//  - The machine managed to match a 7 in the middle of reel 1
//  - The machine could not line up a 7 of the same color in reel 2
// Then
//    The machine will try to line up a 7 of the opposite color in reel 2
static void DecideStop_NoBias_Reel2_Bet1(void)
{
    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        // Note here and in other NoBias functions, reelExtraTurns is 0 if it
        // corresponds to a previous reel. That reel has already stopped and any
        // extra turns were applied.
        u8 reel1MiddleSym = GetSymbol(LEFT_REEL, 2 - sSlotMachine->reelExtraTurns[0]);
        if (IfSymbol7_SwitchColor(&reel1MiddleSym))
        {
            s16 i;
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                if (reel1MiddleSym == GetSymbol(MIDDLE_REEL, 2 - i))
                {
                    sSlotMachine->winnerRows[1] = 2;
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
    }
}

// If the machine has no bias, stop immediately.
//
// Otherwise, the machine manipulates the results if all the following
// conditions are met:
// If
//  - The machine is biased toward straight 7's
//  - The machine managed to match a 7 anywhere in reel 1
//  - The machine could not line up a 7 of the same color in reel 2
// Then
//    The machine will try to line up a 7 of the opposite color in reel 2
static void DecideStop_NoBias_Reel2_Bet2(void)
{
    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        u8 reel1BiasSym = GetSymbol(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        if (IfSymbol7_SwitchColor(&reel1BiasSym))
        {
            s16 i;
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                if (reel1BiasSym == GetSymbol(MIDDLE_REEL, sSlotMachine->winnerRows[0] - i))
                {
                    sSlotMachine->winnerRows[1] = sSlotMachine->winnerRows[0];
                    sSlotMachine->reelExtraTurns[1] = i;
                    break;
                }
            }
        }
    }
}



bool8 IfSymbol7_SwitchColor(u8 *symbol)
{
    if (*symbol == SYMBOL_7_RED)
    {
        *symbol = SYMBOL_7_BLUE;
        return TRUE;
    }
    if (*symbol == SYMBOL_7_BLUE)
    {
        *symbol = SYMBOL_7_RED;
        return TRUE;
    }
    return FALSE;
}








__attribute__((section(".rodata.sDecideStop_NoBias_Reel3_Bets")))
static void (*const sDecideStop_NoBias_Reel3_Bets[MAX_BET])(void) =
{
    DecideStop_NoBias_Reel3_Bet1,
    DecideStop_NoBias_Reel3_Bet2,
    DecideStop_NoBias_Reel3_Bet3,
};

// Returns true if the reel 1 and reel 2 symbols are opposite-color 7's.
//
// Note that if true, this does not constitue a MATCH_MIXED_7, as the first two
// reels are not the same color.
static bool8 MismatchedSyms_77(u8 sym1, u8 sym2)
{
    if ((sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_BLUE) || (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_RED))
        return TRUE;
    else
        return FALSE;
}

// Returns true if the reel 1, reel 2 and reel 3 symbolss form a 7 mismatch,
// i.e. {7R, 7B, 7R} or {7B, 7R, 7B}.
static bool8 MismatchedSyms_777(u8 sym1, u8 sym2, u8 sym3)
{
    if ((sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED) ||
        (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE))
        return TRUE;
    else
        return FALSE;
}

// Returns false if either:
//  - The symbols form a match (including MATCH_MIXED_7)
//  - Or, the symbols form a 7 mismatch (i.e., {7R, 7B, 7R} or {7B, 7R, 7B})
//
// Note, this does not account for cherry matches.
static bool8 NeitherMatchNor7Mismatch(u8 sym1, u8 sym2, u8 sym3)
{
    if ((sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED)
        || (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE)
        || (sym1 == SYMBOL_7_RED && sym2 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE)
        || (sym1 == SYMBOL_7_BLUE && sym2 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED)
        || (sym1 == sym2 && sym1 == sym3))
    {
        return FALSE;
    }
    return TRUE;
}

// Spin until there's no match, or try to taunt the player with a 7 mismatch if
// they failed the straight 7 bias.
void DecideStop_NoBias_Reel3(void)
{
    sDecideStop_NoBias_Reel3_Bets[sSlotMachine->bet - 1]();
}

// Spin until there is no match in reel 3. Additionally, if the player failed a
// straight 7 bias, try to taunt them with a 7 mismatch.
static void DecideStop_NoBias_Reel3_Bet1(void)
{
    s16 i = 0;
    u8 sym1 = GetSymbol(LEFT_REEL, 2 - sSlotMachine->reelExtraTurns[0]);
    u8 sym2 = GetSymbol(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);

    // If first two symbols match, spin until you get a non-matching symbol
    if (sym1 == sym2)
    {
        while (TRUE)
        {
            u8 sym3;
            if (!((sym1 == (sym3 = GetSymbol(RIGHT_REEL, 2 - i)))
                  || (sym1 == SYMBOL_7_RED && sym3 == SYMBOL_7_BLUE)
                  || (sym1 == SYMBOL_7_BLUE && sym3 == SYMBOL_7_RED)))
                break;
            i++;
        }
    }
    // First two symbols are opposite-color 7's
    else if (MismatchedSyms_77(sym1, sym2))
    {
        // If biased toward straight 7's, try to complete the 7 mismatch in 4
        // turns
        if (sSlotMachine->machineBias & BIAS_STRAIGHT_7)
        {
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                if (sym1 == GetSymbol(RIGHT_REEL, 2 - i))
                {
                    sSlotMachine->reelExtraTurns[2] = i;
                    return;
                }
            }
        }

        // Otherwise, just spin until you get a non-matching symbol
        i = 0;
        while (TRUE)
        {
            if (sym1 != GetSymbol(RIGHT_REEL, 2 - i))
                break;
            i++;
        }
    }
    sSlotMachine->reelExtraTurns[2] = i;
}

// Try to spin until there is no match in reel 3. Additionally, if the player
// failed a straight 7 bias, try to taunt them with a 7 mismatch.
//
// There are up to two stages:
//
// 1. Advance the reel as if 2 coins were bet: to mildly oversimplify, spin
//    until there's no matches straight across in any rows.
//
// 2. [Optional] If you've lined up two opposite-color 7's in the same row and
//    the machine is biased toward straight 7's, try to line up a 7 mismatch in
//    that row within 4 turns.
static void DecideStop_NoBias_Reel3_Bet2(void)
{
    s16 extraTurns = 0;
    s16 i;
    u8 sym1;
    u8 sym2;
    u8 sym3;

    // Effectively, if you lined up two 7's in the same row
    if (sSlotMachine->winnerRows[1] != 0 &&
        sSlotMachine->winnerRows[0] == sSlotMachine->winnerRows[1] &&
        sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        sym1 = GetSymbol(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        sym2 = GetSymbol(MIDDLE_REEL, sSlotMachine->winnerRows[1] - sSlotMachine->reelExtraTurns[1]);

        // If the first two 7's are opposite colors, see if you can line up a 7
        // mismatch in the same row. If so, advance initially to that position.
        // More turns may be added further below.
        if (MismatchedSyms_77(sym1, sym2))
        {
            // Iterate over the next 4 turns
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                sym3 = GetSymbol(RIGHT_REEL, sSlotMachine->winnerRows[1] - i);
                if (sym1 == sym3)
                {
                    extraTurns = i;
                    break;
                }
            }
        }
    }

    while (TRUE)
    {
        s16 numMatches;
        // Iterate over the rows of the screen after `extraTurns` turns
        for (i = 1, numMatches = 0; i <= 3; i++)
        {
            sym1 = GetSymbol(LEFT_REEL, i - sSlotMachine->reelExtraTurns[0]);
            sym2 = GetSymbol(MIDDLE_REEL, i - sSlotMachine->reelExtraTurns[1]);
            sym3 = GetSymbol(RIGHT_REEL, i - extraTurns);

            // This boils down to:
            //   If there's a match on screen, keep spinning. Otherwise, if
            //   there's a 7 mismatch on screen, keep spinning if the machine
            //   isn't biased toward straight 7's.
            if (!NeitherMatchNor7Mismatch(sym1, sym2, sym3) &&
                !(MismatchedSyms_777(sym1, sym2, sym3) && (sSlotMachine->machineBias & BIAS_STRAIGHT_7)))
            {
                numMatches++;
                break;
            }
        }

        // If no matches were found, stop here. Otherwise, add an extra spin and
        // check again.
        if (numMatches == 0)
            break;
        extraTurns++;
    }
    sSlotMachine->reelExtraTurns[2] = extraTurns;
}

// Try to spin until there is no match in reel 3. Additionally, if the player
// failed a straight 7 bias, try to taunt them with a 7 mismatch.
//
// There are up to four stages:
//
// 1. Advance the reel as if 2 coins were bet: to mildly oversimplify, spin
//    until there's no matches straight across in any rows.
//
// 2. [Optional] If you've lined up two opposite-color 7's diagonally and the
//    machine is biased toward straight 7's:
//      Check if a 7 with the same color as reel 1 appears in the final diagonal
//      position within 4 turns. If so, advance to that position.
//
// 3. Check NWSE diagonal. Keep advancing the reel a turn at a time as long as:
//     - There is a match in the diagonal
//     - Or, there is a 7 mismatch in the diagonal and the machine isn't
//       biased toward straight 7's
//
// 4. Check NESW diagonal. Keep advancing the reel a turn at a time as long as:
//     - There is a match in the diagonal
//     - Or, there is a 7 mismatch in the diagonal and the machine isn't
//       biased toward straight 7's
//
// Note that stages 3 and 4 are not limited to 4 turns.
//
// Also, note that it actually is possible to win a match here. After stage 1,
// the game never again checks whether it will be matching any rows straight
// across. So any extra turns added in stages 2-4 could result in a match
// occurring straight across.
static void DecideStop_NoBias_Reel3_Bet3(void)
{
    u8 sym1;
    u8 sym2;
    u8 sym3;
    s16 row;
    s16 i;

    // Spin until there's no matches in any row straight across, potentially
    // skewing toward a 7 mismatch. Consider this the new starting position for
    // this function.
    DecideStop_NoBias_Reel3_Bet2();

    // Essentially, if you lined up two 7's diagonally
    if (sSlotMachine->winnerRows[1] != 0 &&
        sSlotMachine->winnerRows[0] != sSlotMachine->winnerRows[1] &&
        sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        sym1 = GetSymbol(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        sym2 = GetSymbol(MIDDLE_REEL, sSlotMachine->winnerRows[1] - sSlotMachine->reelExtraTurns[1]);

        // If the first two 7's are opposite colors, try advancing up to 4
        // additional turns to line up a diagonal 7 mismatch. More turns may be
        // added further below.
        if (MismatchedSyms_77(sym1, sym2))
        {
            row = 1;
            if (sSlotMachine->winnerRows[0] == 1)
                row = 3;
            for (i = 0; i <= MAX_EXTRA_TURNS; i++)
            {
                sym3 = GetSymbol(RIGHT_REEL, row - (sSlotMachine->reelExtraTurns[2] + i));
                if (sym1 == sym3)
                {
                    sSlotMachine->reelExtraTurns[2] += i;
                    break;
                }
            }
        }
    }

    while (TRUE)
    {
        // Check NWSE diagonal
        sym1 = GetSymbol(LEFT_REEL, 1 - sSlotMachine->reelExtraTurns[0]);
        sym2 = GetSymbol(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);
        sym3 = GetSymbol(RIGHT_REEL, 3 - sSlotMachine->reelExtraTurns[2]);
        if (NeitherMatchNor7Mismatch(sym1, sym2, sym3)
            || (MismatchedSyms_777(sym1, sym2, sym3) && sSlotMachine->machineBias & BIAS_STRAIGHT_7))
            break;
        sSlotMachine->reelExtraTurns[2]++;
    }

    while (TRUE)
    {
        // Check NESW diagonal
        sym1 = GetSymbol(LEFT_REEL, 3 - sSlotMachine->reelExtraTurns[0]);
        sym2 = GetSymbol(MIDDLE_REEL, 2 - sSlotMachine->reelExtraTurns[1]);
        sym3 = GetSymbol(RIGHT_REEL, 1 - sSlotMachine->reelExtraTurns[2]);
        if (NeitherMatchNor7Mismatch(sym1, sym2, sym3)
            || (MismatchedSyms_777(sym1, sym2, sym3) && sSlotMachine->machineBias & BIAS_STRAIGHT_7))
            break;
        sSlotMachine->reelExtraTurns[2]++;
    }
}

__attribute__((section(".rodata.sReelStopButtonTasks")))
static void (*const sReelStopButtonTasks[])(struct Task *task, u8 taskId) =
{
    StopReelButton_Press,
    StopReelButton_Wait,
    StopReelButton_Unpress,
};

// The 4th entry is alignment padding in the JP ROM before the next pointer table.
__attribute__((section(".rodata.sReelButtonOffsets")))
static const s16 sReelButtonOffsets[] = {5, 10, 15, 0};

__attribute__((section(".rodata.sMatchLinePalOffsets")))
static const u8 sMatchLinePalOffsets[NUM_MATCH_LINES] =
{
    [MATCH_MIDDLE_ROW] = BG_PLTT_ID(4) + 10,
    [MATCH_TOP_ROW]    = BG_PLTT_ID(4) + 11,
    [MATCH_BOTTOM_ROW] = BG_PLTT_ID(4) + 12,
    [MATCH_NWSE_DIAG]  = BG_PLTT_ID(4) + 14, // Diag colors flipped for some reason
    [MATCH_NESW_DIAG]  = BG_PLTT_ID(4) + 13  // Doesn't matter as both are identical
};

static void PressStopReelButton(u8 reelNum)
{
    u8 taskId = CreateTask(Task_PressStopReelButton, 5);
    gTasks[taskId].data[15] = reelNum;
    Task_PressStopReelButton(taskId);
}

void Task_PressStopReelButton(u8 taskId)
{
    sReelStopButtonTasks[gTasks[taskId].data[0]](&gTasks[taskId], taskId);
}

static void StopReelButton_Press(struct Task *task, u8 taskId)
{
    SetReelButtonTilemap(sReelButtonOffsets[task->data[15]], 0x62, 0x63, 0x72, 0x73);
    task->data[0]++;
}

static void StopReelButton_Wait(struct Task *task, u8 taskId)
{
    if (++task->data[1] > 11)
        task->data[0]++;
}

static void StopReelButton_Unpress(struct Task *task, u8 taskId)
{
    SetReelButtonTilemap(sReelButtonOffsets[task->data[15]], 0x42, 0x43, 0x52, 0x53);
    DestroyTask(taskId);
}

// JP packs the 5 match-line colors into a single array; the palette table
// entries point 2 bytes deeper (a one-color palette), ending with a 0x0000
// terminator. The color values are JP-specific (differ from the US ROM).
__attribute__((section(".rodata.sDarkMatchLinePaletteColors")))
static const u16 sDarkMatchLinePaletteColors[] =
{
    0x7A6D, 0x0339, 0x0339, 0x25BE, 0x25BE, 0x0000,
};

__attribute__((section(".rodata.sLitMatchLinePaletteColors")))
static const u16 sLitMatchLinePaletteColors[] =
{
    0x7F91, 0x43BF, 0x43BF, 0x4ABF, 0x4ABF, 0x0000,
};

__attribute__((section(".rodata.sLitMatchLinePalTable")))
static const u16 *const sLitMatchLinePalTable[NUM_MATCH_LINES] =
{
    [MATCH_MIDDLE_ROW] = &sLitMatchLinePaletteColors[0],
    [MATCH_TOP_ROW]    = &sLitMatchLinePaletteColors[1],
    [MATCH_BOTTOM_ROW] = &sLitMatchLinePaletteColors[2],
    [MATCH_NWSE_DIAG]  = &sLitMatchLinePaletteColors[3],
    [MATCH_NESW_DIAG]  = &sLitMatchLinePaletteColors[4],
};

__attribute__((section(".rodata.sDarkMatchLinePalTable")))
static const u16 *const sDarkMatchLinePalTable[NUM_MATCH_LINES] =
{
    [MATCH_MIDDLE_ROW] = &sDarkMatchLinePaletteColors[0],
    [MATCH_TOP_ROW]    = &sDarkMatchLinePaletteColors[1],
    [MATCH_BOTTOM_ROW] = &sDarkMatchLinePaletteColors[2],
    [MATCH_NWSE_DIAG]  = &sDarkMatchLinePaletteColors[3],
    [MATCH_NESW_DIAG]  = &sDarkMatchLinePaletteColors[4],
};

__attribute__((section(".rodata.sBetToMatchLineIds")))
static const u8 sBetToMatchLineIds[MAX_BET][2] =
{
    {MATCH_MIDDLE_ROW, MATCH_MIDDLE_ROW}, // Bet 1
    {MATCH_TOP_ROW,    MATCH_BOTTOM_ROW}, // Bet 2
    {MATCH_NWSE_DIAG,  MATCH_NESW_DIAG},  // Bet 3
};

__attribute__((section(".rodata.sMatchLinesPerBet")))
static const u8 sMatchLinesPerBet[MAX_BET] = { 1, 2, 2 };

void LightenMatchLine(u8 matchLineId)
{
    LoadPalette(sLitMatchLinePalTable[matchLineId], sMatchLinePalOffsets[matchLineId], PLTT_SIZEOF(1));
}

void DarkenMatchLine(u8 matchLineId)
{
    LoadPalette(sDarkMatchLinePalTable[matchLineId], sMatchLinePalOffsets[matchLineId], PLTT_SIZEOF(1));
}

// light up the match line for each bet by the player
void LightenBetTiles(u8 betVal)
{
    u8 i;
    for (i = 0; i < sMatchLinesPerBet[betVal]; i++)
        LightenMatchLine(sBetToMatchLineIds[betVal][i]);
}

void DarkenBetTiles(u8 betVal)
{
    u8 i;
    for (i = 0; i < sMatchLinesPerBet[betVal]; i++)
        DarkenMatchLine(sBetToMatchLineIds[betVal][i]);
}

#define sMatchLineId     data[0]
#define sFlashing        data[1]
#define sNumFullFlashes  data[2]
#define sDelayTimer      data[3]
#define sColor           data[4]
#define sColorIncr       data[5]
#define sAtOriginalColor data[7]

// Creates invisible sprites that flash the bet lines/numbers where a match occurs
// 5 are created, 1 for each possible match line (3 rows, 2 diagonals)
void CreateInvisibleFlashMatchLineSprites(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->flashMatchLineSpriteIds); i++)
    {
        u8 spriteId = CreateInvisibleSprite(SpriteCB_FlashMatchingLines);
        gSprites[spriteId].sMatchLineId = i;
        sSlotMachine->flashMatchLineSpriteIds[i] = spriteId;
    }
}

void FlashMatchLine(u8 matchLineId)
{
    struct Sprite *sprite = &gSprites[sSlotMachine->flashMatchLineSpriteIds[matchLineId]];
    sprite->sFlashing = TRUE;
    sprite->sNumFullFlashes = 4;
    sprite->sDelayTimer = 0;
    sprite->sColor = 0;
    sprite->sColorIncr = 2;
    sprite->sAtOriginalColor = FALSE;
}

// Match line flashes 4 times before the payout begins
// After this it does half-brightness flashes until the payout finishes
static bool8 IsMatchLineDoneFlashingBeforePayout(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->flashMatchLineSpriteIds); i++)
    {
        struct Sprite *sprite = &gSprites[sSlotMachine->flashMatchLineSpriteIds[i]];
        if (sprite->sFlashing && sprite->sNumFullFlashes)
            return FALSE;
    }
    return TRUE;
}

// When payout is finished, stop lines flashing (but not if they're in the middle of a flash)
static bool8 TryStopMatchLinesFlashing(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->flashMatchLineSpriteIds); i++)
    {
        if (!TryStopMatchLineFlashing(sSlotMachine->flashMatchLineSpriteIds[i]))
            return FALSE;
    }
    return TRUE;
}

static bool8 TryStopMatchLineFlashing(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    if (!sprite->sFlashing)
        return TRUE;
    if (sprite->sAtOriginalColor)
        sprite->sFlashing = FALSE;

    return sprite->sAtOriginalColor;
}

static void SpriteCB_FlashMatchingLines(struct Sprite *sprite)
{
    s16 maxColorChange;
    if (sprite->sFlashing)
    {
        if (!sprite->sDelayTimer--)
        {
            sprite->sAtOriginalColor = FALSE;
            sprite->sDelayTimer = 1;
            sprite->sColor += sprite->sColorIncr;
            maxColorChange = 4;
            if (sprite->sNumFullFlashes)
                maxColorChange = 8;
            if (sprite->sColor <= 0)
            {
                // Returned to original color, reverse
                sprite->sAtOriginalColor = TRUE;
                sprite->sColorIncr = -sprite->sColorIncr;
                if (sprite->sNumFullFlashes)
                    sprite->sNumFullFlashes--;
            }
            else if (sprite->sColor >= maxColorChange)
            {
                // Reached peak darkness, reverse
                sprite->sColorIncr = -sprite->sColorIncr;
            }
            if (sprite->sNumFullFlashes)
                sprite->sDelayTimer <<= 1;
        }
        MultiplyPaletteRGBComponents(sMatchLinePalOffsets[sprite->sMatchLineId], sprite->sColor, sprite->sColor, sprite->sColor);
    }
}

#undef sMatchLineId
#undef sFlashing
#undef sNumFullFlashes
#undef sDelayTimer
#undef sColor
#undef sColorIncr
#undef sAtOriginalColor

// The flashing lights palettes stay packed in data_b2d_mid62.s
// (gUnknown_8585542); these pointers select the inside/middle/outside
// 16-color palettes within it.
extern const u8 gUnknown_8585542[];
__attribute__((section(".rodata.sFlashingLightsPalTable")))
static const u16 *const sFlashingLightsPalTable[] =
{
    (const u16 *)&gUnknown_8585542[0x00],
    (const u16 *)&gUnknown_8585542[0x20],
    (const u16 *)&gUnknown_8585542[0x40],
};

// Menu palette slice used to restore the machine lights after flashing.
extern const u16 gSlotMachineMenu_Pal[];
__attribute__((section(".rodata.sSlotMachineMenu_Pal")))
// Mutable pointer on purpose: agbcc folds a const pointer initialised with a
// constant address into the call site (dropping the memory load), which would
// make TryStopSlotMachineLights 2 bytes short. The section attribute keeps it
// in .rodata at 0x85855B0.
static const u16 *sSlotMachineMenu_Pal = (const u16 *)&gSlotMachineMenu_Pal[0x10];

#define sDelayTimer data[1]
#define sFlashState data[2]
#define sFlashDir   data[3]

void FlashSlotMachineLights(void)
{
    u8 taskId = CreateTask(Task_FlashSlotMachineLights, 6);
    gTasks[taskId].sFlashDir = 1;
    Task_FlashSlotMachineLights(taskId);
}

bool8 TryStopSlotMachineLights(void)
{
    u8 taskId = FindTaskIdByFunc(Task_FlashSlotMachineLights);
    if (gTasks[taskId].sFlashState == 0)
    {
        DestroyTask(taskId);
        LoadPalette(sSlotMachineMenu_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        return TRUE;
    }
    return FALSE;
}

static void Task_FlashSlotMachineLights(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    if (!task->sDelayTimer--)
    {
        task->sDelayTimer = 4;
        task->sFlashState += task->sFlashDir;
        if (task->sFlashState == 0 || task->sFlashState == 2)
            task->sFlashDir = -task->sFlashDir;
    }
    LoadPalette(sFlashingLightsPalTable[task->sFlashState], BG_PLTT_ID(1), PLTT_SIZE_4BPP);
}

#undef sDelayTimer
#undef sFlashState
#undef sFlashDir

#define tState     data[0]
#define tNumBolts  data[1]
#define tSpriteId  data[2]
#define tTimer     data[2] // re-used
#define tAnimating data[15]

__attribute__((section(".rodata.sPikaPowerBoltTasks")))
static void (*const sPikaPowerBoltTasks[])(struct Task *task) =
{
    PikaPowerBolt_Idle,
    PikaPowerBolt_AddBolt,
    PikaPowerBolt_WaitAnim,
    PikaPowerBolt_ClearAll,
};

__attribute__((section(".rodata.sPikaPowerTileTable")))
static const u16 sPikaPowerTileTable[][2] =
{
    {0x9e, 0x6e},
    {0x9f, 0x6f},
    {0xaf, 0x7f},
};

static void CreatePikaPowerBoltTask(void)
{
    sSlotMachine->pikaPowerBoltTaskId = CreateTask(Task_CreatePikaPowerBolt, 8);
}

static void AddPikaPowerBolt(u8 bolts)
{
    struct Task *task = &gTasks[sSlotMachine->pikaPowerBoltTaskId];
    ResetPikaPowerBoltTask(task);
    task->tState = PIKABOLT_TASK_ADD_BOLT;
    task->tNumBolts++;
    task->tAnimating = TRUE;
}

void ResetPikaPowerBolts(void)
{
    struct Task *task = &gTasks[sSlotMachine->pikaPowerBoltTaskId];
    ResetPikaPowerBoltTask(task);
    task->tState = PIKABOLT_TASK_CLEAR_ALL;
    task->tAnimating = TRUE;
}

bool8 IsPikaPowerBoltAnimating(void)
{
    return gTasks[sSlotMachine->pikaPowerBoltTaskId].tAnimating;
}


static void Task_CreatePikaPowerBolt(u8 taskId)
{
    sPikaPowerBoltTasks[gTasks[taskId].tState](&gTasks[taskId]);
}

static void PikaPowerBolt_Idle(struct Task *task)
{
}
static void PikaPowerBolt_AddBolt(struct Task *task)
{
    task->tSpriteId = CreatePikaPowerBoltSprite((task->tNumBolts << 3) + 20, 20);
    task->tState++; // PIKABOLT_TASK_WAIT_ANIM
}

// The bolt sprite spins around as it appears
// Once the anim is done, destroy the sprite and set the bolt in the tilemap instead
static void PikaPowerBolt_WaitAnim(struct Task *task)
{
    if (gSprites[task->tSpriteId].data[7])
    {
        s16 r5 = task->tNumBolts + 2;
        s16 r3 = 0;
        s16 r2 = 0;
        if (task->tNumBolts == 1)
            r3 = 1, r2 = 1;
        else if (task->tNumBolts == 16)
            r3 = 2, r2 = 2;
        sSelectedPikaPowerTile[r2] = sPikaPowerTileTable[r3][0];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r2], 2, (u16)(r5 + 0x40));
        DestroyPikaPowerBoltSprite(task->tSpriteId);
        task->tState = PIKABOLT_TASK_IDLE;
        task->tAnimating = 0;
    }
}

static void PikaPowerBolt_ClearAll(struct Task *task)
{
    s16 r5 = task->tNumBolts + 2;
    s16 r3 = 0;
    s16 r2 = 3;
    if (task->tNumBolts == 1)
        r3 = 1, r2 = 1;
    else if (task->tNumBolts == 16)
        r3 = 2, r2 = 2;
    if (task->tTimer == 0)
    {
        sSelectedPikaPowerTile[r2] = sPikaPowerTileTable[r3][1];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r2], 2, (u16)(r5 + 0x40));
        task->tNumBolts--;
    }
    if (++task->tTimer >= 20)
        task->tTimer = 0;
    if (task->tNumBolts == 0)
    {
        task->tState = PIKABOLT_TASK_IDLE;
        task->tAnimating = 0;
    }
}

static void ResetPikaPowerBoltTask(struct Task *task)
{
    u8 i;

    for (i = 2; i < NUM_TASK_DATA; i++)
        task->data[i] = 0;
}

void LoadPikaPowerMeter(u8 bolts)
{
    s16 i;
    s16 r3 = 0, r1 = 0;
    s16 r4 = 3;
    for (i = 0; i < bolts; i++, r4++)
    {
        r3 = 0, r1 = 0;
        if (i == 0)
            r3 = 1, r1 = 1;
        else if (i == 15) // meter is full
            r3 = 2, r1 = 2;
        sSelectedPikaPowerTile[r1] = sPikaPowerTileTable[r3][0];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r1], 2, (u16)(r4 + 0x40));
    }
    for (; i < 16; i++, r4++)
    {
        r3 = 0, r1 = 3;
        if (i == 0)
            r3 = 1, r1 = 1;
        else if (i == 15)
            r3 = 2, r1 = 2;
        sSelectedPikaPowerTile[r1] = sPikaPowerTileTable[r3][1];
        LoadBgTilemap(2, &sSelectedPikaPowerTile[r1], 2, (u16)(r4 + 0x40));
    }
    gTasks[sSlotMachine->pikaPowerBoltTaskId].data[1] = bolts;
}

#undef tState
#undef tNumBolts
#undef tSpriteId
#undef tTimer
#undef tAnimating

#define tState         data[0]
#define tReelSpeed     data[1]
#define tTimer3        data[2]
#define tRtReelSpeed   data[4]
#define tTimer2        data[4]
#define tTimer1        data[5]
#define tExplodeChecks data[6]

__attribute__((section(".rodata.sReelTimeTasks")))
static void (*const sReelTimeTasks[])(struct Task *task) =
{
    ReelTime_Init,
    ReelTime_WindowEnter,
    ReelTime_WaitStartPikachu,
    ReelTime_PikachuSpeedUp1,
    ReelTime_PikachuSpeedUp2,
    ReelTime_WaitReel,
    ReelTime_CheckExplode,
    ReelTime_LandOnOutcome,
    ReelTime_PikachuReact,
    ReelTime_WaitClearPikaPower,
    ReelTime_CloseWindow,
    ReelTime_DestroySprites,
    ReelTime_SetReelSpeed,
    ReelTime_EndSuccess,
    ReelTime_ExplodeMachine,
    ReelTime_WaitExplode,
    ReelTime_WaitSmoke,
    ReelTime_CloseWindow,
    ReelTime_EndFailure,
};

void BeginReelTime(void)
{
    u8 taskId = CreateTask(Task_ReelTime, 7);
    Task_ReelTime(taskId);
}

bool8 IsReelTimeTaskDone(void)
{
    if (FindTaskIdByFunc(Task_ReelTime) == TAIL_SENTINEL)
        return TRUE;
    return FALSE;
}

static void Task_ReelTime(u8 taskId)
{
    sReelTimeTasks[gTasks[taskId].tState](&gTasks[taskId]);
}

static void ReelTime_Init(struct Task *task)
{
    sSlotMachine->reelTimeSpinsLeft = 0;
    sSlotMachine->reeltimePixelOffset = 0;
    sSlotMachine->reeltimePosition = 0;
    task->tState++; // RT_TASK_WINDOW_ENTER
    task->data[1] = 0;
    task->data[2] = 30;
    task->tRtReelSpeed = 1280;
    gSpriteCoordOffsetX = 0;
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    LoadReelTimeWindowTilemap(REG_OFFSET_BG3VOFS, 0);
    CreateReelTimeMachineSprites();
    CreateReelTimePikachuSprite();
    CreateReelTimeNumberSprites();
    CreateReelTimeShadowSprites();
    CreateReelTimeNumberGapSprite();
    GetReelTimeDraw();
    StopMapMusic();
    PlayNewMapMusic(MUS_ROULETTE);
}

static void ReelTime_WindowEnter(struct Task *task)
{
    s16 r3;
    gSpriteCoordOffsetX -= 8;
    task->data[1] += 8;
    r3 = ((task->data[1] + 240) & 0xff) >> 3;
    SetGpuReg(REG_OFFSET_BG1HOFS, task->data[1] & 0x1ff);
    if (r3 != task->data[2] && task->data[3] <= 18)
    {
        task->data[2] = r3;
        task->data[3] = task->data[1] >> 3;
        LoadReelTimeWindowTilemap(r3, task->data[3]);
    }
    if (task->data[1] >= 200)
    {
        task->tState++; // RT_TASK_WAIT_START_PIKA
        task->data[3] = 0;
    }
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
}

#undef tState
#undef tReelSpeed
#undef tTimer3
#undef tRtReelSpeed
#undef tTimer2
#undef tTimer1
#undef tExplodeChecks

#define tState         data[0]
#define tReelSpeed     data[1]
#define tTimer3        data[2]
#define tRtReelSpeed   data[4]
#define tTimer2        data[4]
#define tTimer1        data[5]
#define tExplodeChecks data[6]

__attribute__((section(".rodata.sReelTimePikachuAnimIds")))
static const u8 sReelTimePikachuAnimIds[] = {1, 1, 2, 2};

__attribute__((section(".rodata.sReelTimeBoltDelays")))
static const s16 sReelTimeBoltDelays[] = {64, 48, 24, 8};

__attribute__((section(".rodata.sPikachuAuraFlashDelays")))
static const s16 sPikachuAuraFlashDelays[] = {10, 8, 6, 4};

static void ReelTime_WaitStartPikachu(struct Task *task)
{
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    if (++task->tTimer1 >= 60)
    {
        task->tState++; // RT_TASK_PIKA_SPEEDUP1
        CreateReelTimeBoltSprites();
        CreateReelTimePikachuAuraSprites();
    }
}

static void ReelTime_PikachuSpeedUp1(struct Task *task)
{
    int i;
    u8 pikachuAnimIds[ARRAY_COUNT(sReelTimePikachuAnimIds)];
    s16 reelTimeBoltDelays[ARRAY_COUNT(sReelTimeBoltDelays)];
    s16 pikachuAuraFlashDelays[ARRAY_COUNT(sPikachuAuraFlashDelays)];

    memcpy(pikachuAnimIds, sReelTimePikachuAnimIds, sizeof(sReelTimePikachuAnimIds));
    memcpy(reelTimeBoltDelays, sReelTimeBoltDelays, sizeof(sReelTimeBoltDelays));
    memcpy(pikachuAuraFlashDelays, sPikachuAuraFlashDelays, sizeof(sPikachuAuraFlashDelays));

    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    // gradually slow down the reel
    task->tRtReelSpeed -= 4;
    i = 4 - (task->tRtReelSpeed >> 8);
    SetReelTimeBoltDelay(reelTimeBoltDelays[i]);
    SetReelTimePikachuAuraFlashDelay(pikachuAuraFlashDelays[i]);
    StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], pikachuAnimIds[i]);
    // once speed goes below 256, go to next ReelTime task and keep the speed level
    if (task->tRtReelSpeed <= 0x100)
    {
        task->tState++; // RT_TASK_PIKA_SPEEDUP2
        task->tRtReelSpeed = 0x100;
        task->tTimer1 = 0;
    }
}

static void ReelTime_PikachuSpeedUp2(struct Task *task)
{
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    if (++task->tTimer1 >= 80)
    {
        task->tState++; // RT_TASK_WAIT_REEL
        task->tTimer1 = 0;
        SetReelTimePikachuAuraFlashDelay(2);
        StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 3);
    }
}

static void ReelTime_WaitReel(struct Task *task)
{
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    task->tRtReelSpeed = (u8)task->tRtReelSpeed + 0x80;
    if (++task->tTimer1 >= 80)
    {
        task->tState++; // RT_TASK_CHECK_EXPLODE
        task->tTimer1 = 0;
    }
}

#undef tState
#undef tReelSpeed
#undef tTimer3
#undef tRtReelSpeed
#undef tTimer2
#undef tTimer1
#undef tExplodeChecks

#define tState         data[0]
#define tReelSpeed     data[1]
#define tTimer3        data[2]
#define tRtReelSpeed   data[4]
#define tTimer2        data[4]
#define tTimer1        data[5]
#define tExplodeChecks data[6]

// Check whether the ReelTime machine should explode.
//
// The ReelTime machine displays 0 when this task starts. If there is a positive
// ReelTime draw, the machine keeps spinning until it lands on that number.
//
// Otherwise, it checks every 40 frames whether it should explode. If so, it
// explodes immediately. After 4 checks, the machine won't explode but continues
// to spin until it lands on 0.
static void ReelTime_CheckExplode(struct Task *task)
{
    AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
    task->tRtReelSpeed = (u8)task->tRtReelSpeed + 0x40;
    if (++task->tTimer1 >= 40)
    {
        task->tTimer1 = 0;
        if (sSlotMachine->reelTimeDraw)
        {
            if (sSlotMachine->reelTimeSpinsLeft <= task->tExplodeChecks)
                task->tState++; // RT_TASK_LAND
        }
        else if (task->tExplodeChecks > 3)
        {
            task->tState++; // RT_TASK_LAND
        }
        else if (ShouldReelTimeMachineExplode(task->tExplodeChecks))
        {
            task->tState = RT_TASK_EXPLODE;
        }
        task->tExplodeChecks++;
    }
}

// Reel spins until it lands on the selected outcome.
static void ReelTime_LandOnOutcome(struct Task *task)
{
    s16 reeltimePixelOffset = sSlotMachine->reeltimePixelOffset % 20;
    if (reeltimePixelOffset)
    {
        reeltimePixelOffset = AdvanceReeltimeReelToNextSymbol(task->tRtReelSpeed >> 8);
        task->tRtReelSpeed = (u8)task->tRtReelSpeed + 0x40;
    }
    else if (GetReelTimeSymbol(1) != sSlotMachine->reelTimeDraw)
    {
        AdvanceReeltimeReel(task->tRtReelSpeed >> 8);
        reeltimePixelOffset = sSlotMachine->reeltimePixelOffset % 20;
        task->tRtReelSpeed = (u8)task->tRtReelSpeed + 0x40;
    }
    if (reeltimePixelOffset == 0 && GetReelTimeSymbol(1) == sSlotMachine->reelTimeDraw)
    {
        task->tRtReelSpeed = 0; // Also initializes task->tTimer2
        task->tState++; // RT_TASK_PIKA_REACT
    }
}

// Animate Pikachu reaction. Clear any power bolts the player may have won if
// they got a positive ReelTime draw.
static void ReelTime_PikachuReact(struct Task *task)
{
    if (++task->tTimer2 >= 60)
    {
        StopMapMusic();
        DestroyReelTimeBoltSprites();
        DestroyReelTimePikachuAuraSprites();
        task->tState++; // RT_TASK_WAIT_CLEAR_POWER
        if(sSlotMachine->reelTimeDraw == 0)
        {
            task->tTimer2 = 0xa0;
            StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 5);
            PlayFanfare(MUS_TOO_BAD);
        }
        else
        {
            task->tTimer2 = 0xc0;
            StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 4);
            gSprites[sSlotMachine->reelTimePikachuSpriteId].animCmdIndex = 0;
            if (sSlotMachine->pikaPowerBolts)
            {
                ResetPikaPowerBolts();
                sSlotMachine->pikaPowerBolts = 0;
            }
            PlayFanfare(MUS_SLOTS_WIN);
        }
    }
}

static void ReelTime_WaitClearPikaPower(struct Task *task)
{
    if ((task->tTimer2 == 0 || --task->tTimer2 == 0) && !IsPikaPowerBoltAnimating())
        task->tState++; // RT_TASK_CLOSE_WINDOW_SUCCESS
}


static void ReelTime_CloseWindow(struct Task *task)
{
    s16 r4;
    gSpriteCoordOffsetX -= 8;
    task->data[1] += 8;
    task->data[3] += 8;
    r4 = ((task->data[1] - 8) & 0xff) >> 3;
    SetGpuReg(REG_OFFSET_BG1HOFS, task->data[1] & 0x1ff);
    if (task->data[3] >> 3 <= 25)
        ClearReelTimeWindowTilemap(r4);
    else
        task->tState++; // RT_TASK_DESTROY_SPRITES
}

// Destroy sprites and wrap up the ReelTime task.
//
// If the player got a positive ReelTime draw, select the speed that the slot
// reels will initially move at.
static void ReelTime_DestroySprites(struct Task *task)
{
    sSlotMachine->reelTimeSpinsUsed = 0;
    sSlotMachine->reelTimeSpinsLeft = sSlotMachine->reelTimeDraw;
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    sSlotMachine->reelSpeed = REEL_NORMAL_SPEED;
    DestroyReelTimePikachuSprite();
    DestroyReelTimeMachineSprites();
    DestroyReelTimeShadowSprites();
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    if (sSlotMachine->reelTimeSpinsLeft == 0)
    {
        DestroyTask(FindTaskIdByFunc(Task_ReelTime));
    }
    else
    {
        CreateDigitalDisplayScene(DIG_DISPLAY_REEL_TIME);
        task->tReelSpeed = ReelTimeSpeed();
        task->tTimer3 = 0;
        task->data[3] = 0;
        task->tState++; // RT_TASK_SET_REEL_SPEED
    }
}

// Slow the slot reels down until they match the selected speed.
static void ReelTime_SetReelSpeed(struct Task *task)
{
    if (sSlotMachine->reelSpeed == task->tReelSpeed)
        task->tState++; // RT_TASK_END_SUCCESS
    else if (sSlotMachine->reelPixelOffsets[0] % REEL_SYMBOL_HEIGHT == 0 && (++task->tTimer3 & 0x07) == 0)
        sSlotMachine->reelSpeed >>= 1;
}

static void ReelTime_EndSuccess(struct Task *task)
{
    if (IsDigitalDisplayAnimFinished())
        DestroyTask(FindTaskIdByFunc(Task_ReelTime));
}

static void ReelTime_ExplodeMachine(struct Task *task)
{
    DestroyReelTimeMachineSprites();
    DestroyReelTimeBoltSprites();
    DestroyReelTimePikachuAuraSprites();
    CreateReelTimeExplosionSprite();
    gSprites[sSlotMachine->reelTimeShadowSpriteIds[0]].invisible = TRUE;
    StartSpriteAnimIfDifferent(&gSprites[sSlotMachine->reelTimePikachuSpriteId], 5);
    task->tState++; // RT_TASK_WAIT_EXPLODE
    task->data[4] = 4;
    task->tTimer1 = 0;
    StopMapMusic();
    PlayFanfare(MUS_TOO_BAD);
    PlaySE(SE_M_EXPLOSION);
}

static void ReelTime_WaitExplode(struct Task *task)
{
    gSpriteCoordOffsetY = task->data[4];
    SetGpuReg(REG_OFFSET_BG1VOFS, (u16)task->data[4]);
    if (task->tTimer1 & 0x01)
        task->data[4] = -task->data[4];
    if ((++task->tTimer1 & 0x1f) == 0)
        task->data[4] >>= 1;
    if (task->data[4] == 0)
    {
        DestroyReelTimeExplosionSprite();
        CreateReelTimeDuckSprites();
        CreateBrokenReelTimeMachineSprite();
        CreateReelTimeSmokeSprite();
        gSprites[sSlotMachine->reelTimeShadowSpriteIds[0]].invisible = FALSE;
        task->tState++; // RT_TASK_WAIT_SMOKE
        task->tTimer1 = 0;
    }
}

static void ReelTime_WaitSmoke(struct Task *task)
{
    gSpriteCoordOffsetY = 0;
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    if (IsReelTimeSmokeAnimFinished())
    {
        task->tState++; // RT_TASK_CLOSE_WINDOW_FAILURE
        DestroyReelTimeSmokeSprite();
    }
}

static void ReelTime_EndFailure(struct Task *task)
{
    gSpriteCoordOffsetX = 0;
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    PlayNewMapMusic(sSlotMachine->backupMapMusic);
    DestroyReelTimePikachuSprite();
    DestroyBrokenReelTimeMachineSprite();
    DestroyReelTimeShadowSprites();
    DestroyReelTimeDuckSprites();
    DestroyTask(FindTaskIdByFunc(Task_ReelTime));
}

#undef tState
#undef tReelSpeed
#undef tTimer3
#undef tRtReelSpeed
#undef tTimer2
#undef tTimer1
#undef tExplodeChecks

__attribute__((section(".rodata.sReelTimeWindow_Tilemap")))
static const u16 sReelTimeWindow_Tilemap[] = {
    0x30A0, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1, 0x30A1,
    0x30A1, 0x30A1, 0x30A1, 0x34A0, 0x30B0, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3,
    0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x34B0, 0x30B0, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3,
    0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x30C3, 0x34B0, 0x30C0, 0x30C4, 0x30C4, 0x30C4,
    0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x30C4, 0x34C0,
    0x30A2, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5, 0x30C5,
    0x30C5, 0x30C5, 0x30C5, 0x34A2, 0x30B2, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1,
    0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x34B2, 0x30B2, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1,
    0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x34B2, 0x30B2, 0x30B1, 0x30B1, 0x30B1,
    0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x34B2,
    0x30B2, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1,
    0x30B1, 0x30B1, 0x30B1, 0x34B2, 0x30B2, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1,
    0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x30B1, 0x34B2, 0x30C2, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1,
    0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x30C1, 0x34C2,
};

__attribute__((section(".rodata.sEmptyTilemap")))
static const u16 sEmptyTilemap[] = {0};

void LoadReelTimeWindowTilemap(s16 a0, s16 a1)
{
    s16 i;
    for (i = 4; i < 15; i++)
        LoadBgTilemap(1, &sReelTimeWindow_Tilemap[a1 + (i - 4) * 20], 2, (u16)(32 * i + a0));
}

void ClearReelTimeWindowTilemap(s16 a0)
{
    u8 i;
    for (i = 4; i < 15; i++)
        LoadBgTilemap(1, sEmptyTilemap, 2, (u16)(32 * i + a0));
}

#define tState data[0]

__attribute__((section(".rodata.sInfoBoxTasks")))
static void (*const sInfoBoxTasks[])(struct Task *task) =
{
    InfoBox_FadeIn,
    InfoBox_WaitFade,
    InfoBox_DrawWindow,
    InfoBox_WaitFade,
    InfoBox_AddText,
    InfoBox_WaitFade,
    InfoBox_WaitInput,
    InfoBox_WaitFade,
    InfoBox_LoadSlotMachineTilemap,
    InfoBox_WaitFade,
    InfoBox_CreateDigitalDisplay,
    InfoBox_WaitFade,
    InfoBox_LoadPikaPowerMeter,
    InfoBox_WaitFade,
    InfoBox_FreeTask,
};

// Info Box is the screen shown when Select is pressed
static void OpenInfoBox(u8 digDisplayId)
{
    u8 taskId = CreateTask(Task_InfoBox, 1);
    gTasks[taskId].data[1] = digDisplayId;
    Task_InfoBox(taskId);
}

static bool8 IsInfoBoxClosed(void)
{
    if (FindTaskIdByFunc(Task_InfoBox) == TASK_NONE)
        return TRUE;
    else
        return FALSE;
}

static void Task_InfoBox(u8 taskId)
{
    sInfoBoxTasks[gTasks[taskId].tState](&gTasks[taskId]);
}

static void InfoBox_FadeIn(struct Task *task)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    task->tState++;
}

static void InfoBox_WaitFade(struct Task *task)
{
    if (!gPaletteFade.active)
        task->tState++;
}

#undef tState

#define tState data[0]

// JP window layout differs from the US ROM (left/top/width/height).
__attribute__((section(".rodata.sWindowTemplate_InfoBox")))
static const struct WindowTemplate sWindowTemplate_InfoBox =
{
    .bg = 0,
    .tilemapLeft = 2,
    .tilemapTop = 4,
    .width = 18,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 1
};

static void InfoBox_DrawWindow(struct Task *task)
{
    DestroyDigitalDisplayScene();
    LoadInfoBoxTilemap();
    AddWindow(&sWindowTemplate_InfoBox);
    PutWindowTilemap(WIN_INFO);
    FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
    task->tState++;
}

// JP has a trailing 0 byte after the three colors.
__attribute__((section(".rodata.sColors_ReeltimeHelp")))
static const u8 sColors_ReeltimeHelp[] = {TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY, 0};

static void InfoBox_AddText(struct Task *task)
{
    // JP text position (x=0, y=2) and COPYWIN_ALL differ from the US source.
    AddTextPrinterParameterized3(WIN_INFO, FONT_NORMAL, 0, 2, sColors_ReeltimeHelp, 0, gText_ReelTimeHelp);
    CopyWindowToVram(WIN_INFO, COPYWIN_FULL);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    task->tState++;
}

static void InfoBox_WaitInput(struct Task *task)
{
    if (JOY_NEW(B_BUTTON | SELECT_BUTTON))
    {
        FillWindowPixelBuffer(WIN_INFO, PIXEL_FILL(0));
        ClearWindowTilemap(WIN_INFO);
        CopyWindowToVram(WIN_INFO, COPYWIN_MAP);
        RemoveWindow(WIN_INFO);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        task->tState++;
    }
}

static void InfoBox_LoadSlotMachineTilemap(struct Task *task)
{
    LoadSlotMachineMenuTilemap();
    ShowBg(3);
    task->tState++;
}

static void InfoBox_CreateDigitalDisplay(struct Task *task)
{
    CreateDigitalDisplayScene(task->data[1]);
    task->tState++;
}


static void InfoBox_LoadPikaPowerMeter(struct Task *task)
{
    LoadPikaPowerMeter(sSlotMachine->pikaPowerBolts);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    task->tState++;
}

static void InfoBox_FreeTask(struct Task *task)
{
    DestroyTask(FindTaskIdByFunc(Task_InfoBox));
}

#undef tState

#define sWaitForAnim data[7]

__attribute__((section(".rodata.sDigitalDisplayTasks")))
static void (*const sDigitalDisplayTasks[])(struct Task *task) =
{
    DigitalDisplay_Idle,
};

void CreateDigitalDisplayTask(void)
{
    u8 i;
    struct Task *task;
    i = CreateTask(Task_DigitalDisplay, 3);
    sSlotMachine->digDisplayTaskId = i;
    task = &gTasks[i];
    task->data[1] = -1;
    for (i = 4; i < NUM_TASK_DATA; i++)
        task->data[i] = MAX_SPRITES;
}

// JP stores the scene arrays in this address order (BonusBig before
// BonusRegular).
__attribute__((section(".rodata.sDigitalDisplayScenesData")))
static const struct DigitalDisplaySprite sDigitalDisplay_InsertBet[] = {
    {DIG_SPRITE_EMPTY, DIG_DISPINFO_A_BUTTON_START, 0}, // Sprite replaced with DIG_SPRITE_A_BUTTON after first bet
    {DIG_SPRITE_INSERT, DIG_DISPINFO_INSERT, 0},
    {DIG_SPRITE_D_PAD, DIG_DISPINFO_DPAD, 0},
    DIG_SPRITE_DUMMY
};

__attribute__((section(".rodata.sDigitalDisplayScenesData")))
static const struct DigitalDisplaySprite sDigitalDisplay_StopReel[] = {
    {DIG_SPRITE_STOP_S, DIG_DISPINFO_STOP_S, 0},
    {DIG_SPRITE_STOP_T, DIG_DISPINFO_STOP_T, 0},
    {DIG_SPRITE_STOP_O, DIG_DISPINFO_STOP_O, 0},
    {DIG_SPRITE_STOP_P, DIG_DISPINFO_STOP_P, 0},
    {DIG_SPRITE_A_BUTTON, DIG_DISPINFO_A_BUTTON_STOP, 0},
    {DIG_SPRITE_POKE_BALL, DIG_DISPINFO_POKE_BALL_ROCKING, 0},
    DIG_SPRITE_DUMMY
};

__attribute__((section(".rodata.sDigitalDisplayScenesData")))
static const struct DigitalDisplaySprite sDigitalDisplay_Win[] = {
    {DIG_SPRITE_WIN, DIG_DISPINFO_WIN, 0},
    {DIG_SPRITE_POKE_BALL, DIG_DISPINFO_POKE_BALL_SHINING, 0},
    DIG_SPRITE_DUMMY
};

__attribute__((section(".rodata.sDigitalDisplayScenesData")))
static const struct DigitalDisplaySprite sDigitalDisplay_Lose[] = {
    {DIG_SPRITE_LOSE, DIG_DISPINFO_LOSE, 0},
    {DIG_SPRITE_SMOKE, DIG_DISPINFO_SMOKE_NW, 0},
    {DIG_SPRITE_SMOKE, DIG_DISPINFO_SMOKE_NE, 1},
    {DIG_SPRITE_SMOKE, DIG_DISPINFO_SMOKE_SW, 2},
    {DIG_SPRITE_SMOKE, DIG_DISPINFO_SMOKE_SE, 3},
    DIG_SPRITE_DUMMY
};

__attribute__((section(".rodata.sDigitalDisplayScenesData")))
static const struct DigitalDisplaySprite sDigitalDisplay_ReelTime[] = {
    {DIG_SPRITE_REEL, DIG_DISPINFO_REEL, 0},
    {DIG_SPRITE_TIME, DIG_DISPINFO_TIME, 0},
    {DIG_SPRITE_NUMBER, DIG_DISPINFO_NUMBER, 0}, // Number of reel time spins left
    DIG_SPRITE_DUMMY
};

__attribute__((section(".rodata.sDigitalDisplayScenesData")))
static const struct DigitalDisplaySprite sDigitalDisplay_BonusBig[] = {
    {DIG_SPRITE_BIG_B, DIG_DISPINFO_BIG_B, 0},
    {DIG_SPRITE_BIG_I, DIG_DISPINFO_BIG_I, 1},
    {DIG_SPRITE_BIG_G, DIG_DISPINFO_BIG_G, 2},
    {DIG_SPRITE_BONUS_B, DIG_DISPINFO_BIG_BONUS_B, 3},
    {DIG_SPRITE_BONUS_O, DIG_DISPINFO_BIG_BONUS_O, 4},
    {DIG_SPRITE_BONUS_N, DIG_DISPINFO_BIG_BONUS_N, 5},
    {DIG_SPRITE_BONUS_U, DIG_DISPINFO_BIG_BONUS_U, 6},
    {DIG_SPRITE_BONUS_S, DIG_DISPINFO_BIG_BONUS_S, 7},
    {DIG_SPRITE_POKE_BALL, DIG_DISPINFO_POKE_BALL_SHINING, 0},
    DIG_SPRITE_DUMMY
};

__attribute__((section(".rodata.sDigitalDisplayScenesData")))
static const struct DigitalDisplaySprite sDigitalDisplay_BonusRegular[] = {
    {DIG_SPRITE_REG_R, DIG_DISPINFO_REG_R, 0},
    {DIG_SPRITE_REG_E, DIG_DISPINFO_REG_E, 1},
    {DIG_SPRITE_REG_G, DIG_DISPINFO_REG_G, 2},
    {DIG_SPRITE_BONUS_B, DIG_DISPINFO_REG_BONUS_B, 3},
    {DIG_SPRITE_BONUS_O, DIG_DISPINFO_REG_BONUS_O, 4},
    {DIG_SPRITE_BONUS_N, DIG_DISPINFO_REG_BONUS_N, 5},
    {DIG_SPRITE_BONUS_U, DIG_DISPINFO_REG_BONUS_U, 6},
    {DIG_SPRITE_BONUS_S, DIG_DISPINFO_REG_BONUS_S, 7},
    {DIG_SPRITE_POKE_BALL, DIG_DISPINFO_POKE_BALL_SHINING, 0},
    DIG_SPRITE_DUMMY
};

__attribute__((section(".rodata.sDigitalDisplayScenes")))
static const struct DigitalDisplaySprite *const sDigitalDisplayScenes[] = {
    [DIG_DISPLAY_INSERT_BET] = sDigitalDisplay_InsertBet,
    [DIG_DISPLAY_STOP_REEL]  = sDigitalDisplay_StopReel,
    [DIG_DISPLAY_WIN]        = sDigitalDisplay_Win,
    [DIG_DISPLAY_LOSE]       = sDigitalDisplay_Lose,
    [DIG_DISPLAY_REEL_TIME]  = sDigitalDisplay_ReelTime,
    [DIG_DISPLAY_BONUS_REG]  = sDigitalDisplay_BonusRegular,
    [DIG_DISPLAY_BONUS_BIG]  = sDigitalDisplay_BonusBig
};

// JP reuses EndDigitalDisplayScene_Win for the Bonus scenes (US uses Dummy).
__attribute__((section(".rodata.sDigitalDisplaySceneExitCallbacks")))
static void (*const sDigitalDisplaySceneExitCallbacks[])(void) = {
    [DIG_DISPLAY_INSERT_BET] = EndDigitalDisplayScene_InsertBet,
    [DIG_DISPLAY_STOP_REEL]  = EndDigitalDisplayScene_StopReel,
    [DIG_DISPLAY_WIN]        = EndDigitalDisplayScene_Win,
    [DIG_DISPLAY_LOSE]       = EndDigitalDisplayScene_Dummy,
    [DIG_DISPLAY_REEL_TIME]  = EndDigitalDisplayScene_Dummy,
    [DIG_DISPLAY_BONUS_REG]  = EndDigitalDisplayScene_Win,
    [DIG_DISPLAY_BONUS_BIG]  = EndDigitalDisplayScene_Win
};

// For the panel on the right side of the slot screen
void CreateDigitalDisplayScene(u8 id)
{
    u8 i;
    struct Task *task;

    DestroyDigitalDisplayScene();

    task = &gTasks[sSlotMachine->digDisplayTaskId];
    task->data[1] = id;

    for (i = 0; sDigitalDisplayScenes[id][i].spriteTemplateId != 255; i++)
    {
        u8 spriteId;
        spriteId = CreateStdDigitalDisplaySprite(
                sDigitalDisplayScenes[id][i].spriteTemplateId,
                sDigitalDisplayScenes[id][i].dispInfoId,
                sDigitalDisplayScenes[id][i].spriteId
        );
        task->data[4 + i] = spriteId;
    }
}

void AddDigitalDisplaySprite(u8 templateIdx, SpriteCallback callback, s16 x, s16 y, s16 spriteId)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->digDisplayTaskId];
    for (i = 4; i < NUM_TASK_DATA; i++)
    {
        if (task->data[i] == MAX_SPRITES)
        {
            task->data[i] = CreateDigitalDisplaySprite(templateIdx, callback, x, y, spriteId);
            break;
        }
    }
}

void DestroyDigitalDisplayScene(void)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->digDisplayTaskId];

    if ((u16)task->data[1] != 0xFFFF)
        sDigitalDisplaySceneExitCallbacks[task->data[1]]();

    for (i = 4; i < NUM_TASK_DATA; i++)
    {
        if (task->data[i] != MAX_SPRITES)
        {
            DestroySprite(&gSprites[task->data[i]]);
            task->data[i] = MAX_SPRITES;
        }
    }
}

static bool8 IsDigitalDisplayAnimFinished(void)
{
    u8 i;
    struct Task *task = &gTasks[sSlotMachine->digDisplayTaskId];
    for (i = 4; i < NUM_TASK_DATA; i++)
    {
        if (task->data[i] != MAX_SPRITES)
        {
            if (gSprites[task->data[i]].sWaitForAnim)
                return FALSE;
        }
    }
    return TRUE;
}

#undef sWaitForAnim

static void Task_DigitalDisplay(u8 taskId)
{
    sDigitalDisplayTasks[gTasks[taskId].data[0]](&gTasks[taskId]);
}

static void DigitalDisplay_Idle(struct Task *task)
{
}
void CreateReelSymbolSprites(void)
{
    s16 i;
    s16 j;
    s16 x;
    for (i = 0, x = 0x30; i < 3; i++, x += 0x28)
    {
        for (j = 0; j < 120; j += 24)
        {
            struct Sprite *sprite = gSprites + CreateSprite(&sSpriteTemplate_ReelSymbol, x, 0, 14);
            sprite->oam.priority = 3;
            sprite->data[0] = i;
            sprite->data[1] = j;
            sprite->data[3] = -1;
        }
    }
}

static void SpriteCB_ReelSymbol(struct Sprite *sprite)
{
    sprite->data[2] = sSlotMachine->reelPixelOffsets[sprite->data[0]] + sprite->data[1];
    sprite->data[2] %= 120;
    sprite->y = sSlotMachine->reelShockOffsets[sprite->data[0]] + 28 + sprite->data[2];
    sprite->sheetTileStart = GetSpriteTileStartByTag(GetSymbolAtRest(sprite->data[0], sprite->data[2] / 24));
    SetSpriteSheetFrameTileNum(sprite);
}

void CreateCreditPayoutNumberSprites(void)
{
    s16 i;
    s16 x;

    // Credit number sprite
    for (x = 203, i = 1; i <= MAX_COINS; i *= 10, x -= 7)
        CreateCoinNumberSprite(x, 23, FALSE, i);

    // Payout number sprite
    for (x = 235, i = 1; i <= MAX_COINS; i *= 10, x -= 7)
        CreateCoinNumberSprite(x, 23, TRUE, i);
}

#define sIsPayout data[0]
#define sDigitMin data[1]
#define sDigitMax data[2]
#define sCurNum   data[3] // Only used to determine whether the sprite has already been updated to show the correct digit

void CreateCoinNumberSprite(s16 x, s16 y, bool8 isPayout, s16 digitMult)
{
    struct Sprite *sprite = &gSprites[CreateSprite(&sSpriteTemplate_CoinNumber, x, y, 13)];
    sprite->oam.priority = 2;
    sprite->sIsPayout = isPayout;
    sprite->sDigitMin = digitMult;
    sprite->sDigitMax = digitMult * 10;
    sprite->sCurNum = -1;
}

#undef sIsPayout
#undef sDigitMin
#undef sDigitMax
#undef sCurNum

#define sIsPayout data[0]
#define sDigitMin data[1]
#define sDigitMax data[2]
#define sCurNum   data[3] // Only used to determine whether the sprite has already been updated to show the correct digit

static void SpriteCB_CoinNumber(struct Sprite *sprite)
{
    u16 tag = sSlotMachine->coins;
    if (sprite->sIsPayout)
        tag = sSlotMachine->payout;
    if (sprite->sCurNum != tag)
    {
        // Convert total to current digit
        sprite->sCurNum = tag;
        tag %= (u16)sprite->sDigitMax;
        tag /= (u16)sprite->sDigitMin;

        tag = (u16)((((u32)tag << 16) + GFXTAG_NUM_0) >> 16);
        sprite->sheetTileStart = GetSpriteTileStartByTag(tag);
        SetSpriteSheetFrameTileNum(sprite);
    }
}

#undef sIsPayout
#undef sDigitMin
#undef sDigitMax
#undef sCurNum

void CreateReelBackgroundSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelBackground, 88, 72, 15);
    gSprites[spriteId].oam.priority = 3;
    SetSubspriteTables(&gSprites[spriteId], sSubspriteTable_ReelBackground);
}

void CreateReelTimePikachuSprite(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    if (sImageTable_ReelTimePikachu == NULL)
        sImageTable_ReelTimePikachu = AllocZeroed(sizeof(struct SpriteFrameImage) * 5);

    sImageTable_ReelTimePikachu[0].data = sReelTimeGfxPtr + (0 * 0x800);
    sImageTable_ReelTimePikachu[0].size = 0x800;
    sImageTable_ReelTimePikachu[1].data = sReelTimeGfxPtr + (1 * 0x800);
    sImageTable_ReelTimePikachu[1].size = 0x800;
    sImageTable_ReelTimePikachu[2].data = sReelTimeGfxPtr + (2 * 0x800);
    sImageTable_ReelTimePikachu[2].size = 0x800;
    sImageTable_ReelTimePikachu[3].data = sReelTimeGfxPtr + (3 * 0x800);
    sImageTable_ReelTimePikachu[3].size = 0x800;
    sImageTable_ReelTimePikachu[4].data = sReelTimeGfxPtr + (4 * 0x800);
    sImageTable_ReelTimePikachu[4].size = 0x800;

    spriteTemplate = sSpriteTemplate_ReelTimePikachu;
    spriteTemplate.images = sImageTable_ReelTimePikachu;
    spriteId = CreateSprite(&spriteTemplate, 280, 80, 1);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    sSlotMachine->reelTimePikachuSpriteId = spriteId;
}

void DestroyReelTimePikachuSprite(void)
{
    DestroySprite(&gSprites[sSlotMachine->reelTimePikachuSpriteId]);
    TRY_FREE_AND_SET_NULL(sImageTable_ReelTimePikachu);
}

static void SpriteCB_ReelTimePikachu(struct Sprite *sprite)
{
    sprite->y2 = sprite->x2 = 0;
    if (sprite->animNum == 4)
    {
        sprite->y2 = sprite->x2 = 8;
        if ((sprite->animCmdIndex != 0 && sprite->animDelayCounter != 0) || (sprite->animCmdIndex == 0 && sprite->animDelayCounter == 0))
            sprite->y2 = -8;
    }
}

void CreateReelTimeMachineSprites(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    if (sImageTable_ReelTimeMachineAntennae == NULL)
        sImageTable_ReelTimeMachineAntennae = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sImageTable_ReelTimeMachineAntennae[0].data = sReelTimeGfxPtr + 0x2800;
    sImageTable_ReelTimeMachineAntennae[0].size = 0x300;
    spriteTemplate = sSpriteTemplate_ReelTimeMachineAntennae;
    spriteTemplate.images = sImageTable_ReelTimeMachineAntennae;
    spriteId = CreateSprite(&spriteTemplate, 368, 52, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeMachineAntennae);
    sSlotMachine->reelTimeMachineSpriteIds[0] = spriteId;

    if (sImageTable_ReelTimeMachine == NULL)
        sImageTable_ReelTimeMachine = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sImageTable_ReelTimeMachine[0].data = sReelTimeGfxPtr + 0x2800 + 0x300;
    sImageTable_ReelTimeMachine[0].size = 0x500;
    spriteTemplate = sSpriteTemplate_ReelTimeMachine;
    spriteTemplate.images = sImageTable_ReelTimeMachine;
    spriteId = CreateSprite(&spriteTemplate, 368, 84, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeMachine);
    sSlotMachine->reelTimeMachineSpriteIds[1] = spriteId;
}

void CreateBrokenReelTimeMachineSprite(void)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    if (sImageTable_BrokenReelTimeMachine == NULL)
        sImageTable_BrokenReelTimeMachine = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);

    sImageTable_BrokenReelTimeMachine[0].data = sReelTimeGfxPtr + 0x3000;
    sImageTable_BrokenReelTimeMachine[0].size = 0x600;
    spriteTemplate = sSpriteTemplate_BrokenReelTimeMachine;
    spriteTemplate.images = sImageTable_BrokenReelTimeMachine;
    spriteId = CreateSprite(&spriteTemplate, 168 - gSpriteCoordOffsetX, 80, 7);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->coordOffsetEnabled = TRUE;
    SetSubspriteTables(sprite, sSubspriteTable_BrokenReelTimeMachine);
    sSlotMachine->reelTimeBrokenMachineSpriteId = spriteId;
}


void CreateReelTimeNumberSprites(void)
{
    u8 i;
    s16 r5;
    for (i = 0, r5 = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeNumberSpriteIds); i++, r5 += 20)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeNumbers, 368, 0, 10);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[7] = r5;
        sSlotMachine->reelTimeNumberSpriteIds[i] = spriteId;
    }
}

static void SpriteCB_ReelTimeNumbers(struct Sprite *sprite)
{
    s16 r0 = (u16)(sSlotMachine->reeltimePixelOffset + sprite->data[7]);
    r0 %= 40;
    sprite->y = r0 + 59;
    StartSpriteAnimIfDifferent(sprite, GetReelTimeSymbol(r0 / 20));
}

void CreateReelTimeShadowSprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeShadow, 368, 100, 9);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeShadow);
    sSlotMachine->reelTimeShadowSpriteIds[0] = spriteId;

    spriteId = CreateSprite(&sSpriteTemplate_ReelTimeShadow, 288, 104, 4);
    sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeShadow);
    sSlotMachine->reelTimeShadowSpriteIds[1] = spriteId;
}

// Creates a small black bar on the Reel Time machine to fill the gap between the numbers
void CreateReelTimeNumberGapSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeNumberGap, 368, 76, 11);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->coordOffsetEnabled = TRUE;
    sprite->oam.priority = 1;
    SetSubspriteTables(sprite, sSubspriteTable_ReelTimeNumberGap);
    sSlotMachine->reelTimeNumberGapSpriteId = spriteId;
}

void DestroyReelTimeMachineSprites(void)
{
    u8 i;

    DestroySprite(&gSprites[sSlotMachine->reelTimeNumberGapSpriteId]);
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeMachineSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeMachineSpriteIds[i]]);

    TRY_FREE_AND_SET_NULL(sImageTable_ReelTimeMachineAntennae);
    TRY_FREE_AND_SET_NULL(sImageTable_ReelTimeMachine);

    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeNumberSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeNumberSpriteIds[i]]);
}

void DestroyReelTimeShadowSprites(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeShadowSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeShadowSpriteIds[i]]);
}

void DestroyBrokenReelTimeMachineSprite(void)
{
    DestroySprite(&gSprites[sSlotMachine->reelTimeBrokenMachineSpriteId]);
    TRY_FREE_AND_SET_NULL(sImageTable_BrokenReelTimeMachine);
}

#define sDelayTimer data[0]
#define sXDir       data[1]
#define sYDir       data[2]
#define sCounter    data[3]
#define sDelay      data[7]

void CreateReelTimeBoltSprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeBolt, 152, 32, 5);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->hFlip = TRUE;
    sSlotMachine->reelTimeBoltSpriteIds[0] = spriteId;
    sprite->sDelayTimer = 8;
    sprite->sXDir = -1;
    sprite->sYDir = -1;
    sprite->sDelay = 32;

    spriteId = CreateSprite(&sSpriteTemplate_ReelTimeBolt, 184, 32, 5);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sSlotMachine->reelTimeBoltSpriteIds[1] = spriteId;
    sprite->sXDir = 1;
    sprite->sYDir = -1;
    sprite->sDelay = 32;
}

static void SpriteCB_ReelTimeBolt(struct Sprite *sprite)
{
    if (sprite->sDelayTimer != 0)
    {
        sprite->sDelayTimer--;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->x2 += sprite->sXDir;
        sprite->y2 += sprite->sYDir;
        if (++sprite->sCounter >= 8)
        {
            sprite->sDelayTimer = sprite->sDelay;
            sprite->sCounter = 0;
        }
    }
}

void SetReelTimeBoltDelay(s16 delay)
{
    gSprites[sSlotMachine->reelTimeBoltSpriteIds[0]].sDelay = delay;
    gSprites[sSlotMachine->reelTimeBoltSpriteIds[1]].sDelay = delay;
}

void DestroyReelTimeBoltSprites(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeBoltSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimeBoltSpriteIds[i]]);
}

#undef sDelayTimer
#undef sXDir
#undef sYDir
#undef sCounter
#undef sDelay

#define sFlashPal   data[0]
#define sColorIdx   data[5]
#define sDelayTimer data[6]
#define sDelay      data[7]

void CreateReelTimePikachuAuraSprites(void)
{
    // Left half of electricity orb
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimePikachuAura, 72, 80, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].sFlashPal = TRUE; // Only one of them needs to do the flashing, they share the palette
    gSprites[spriteId].sColorIdx = 0;
    gSprites[spriteId].sDelayTimer = 16;
    gSprites[spriteId].sDelay = 8;
    sSlotMachine->reelTimePikachuAuraSpriteIds[0] = spriteId;

    // Right half
    spriteId = CreateSprite(&sSpriteTemplate_ReelTimePikachuAura, 104, 80, 3);
    gSprites[spriteId].oam.priority = 1;
    gSprites[spriteId].hFlip = TRUE;
    sSlotMachine->reelTimePikachuAuraSpriteIds[1] = spriteId;
}

static void SpriteCB_ReelTimePikachuAura(struct Sprite *sprite)
{
    u8 colors[2];
    memcpy(colors, sReelTimeAuraColors, sizeof(colors));
    if (sprite->sFlashPal && --sprite->sDelayTimer <= 0)
    {
        MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_PIKA_AURA)) + 3, colors[sprite->sColorIdx], colors[sprite->sColorIdx], colors[sprite->sColorIdx]);
        ++sprite->sColorIdx;
        sprite->sColorIdx &= 1;
        sprite->sDelayTimer = sprite->sDelay;
    }
}

void SetReelTimePikachuAuraFlashDelay(s16 delay)
{
    gSprites[sSlotMachine->reelTimePikachuAuraSpriteIds[0]].sDelay = delay;
}

void DestroyReelTimePikachuAuraSprites(void)
{
    u8 i;
    MultiplyInvertedPaletteRGBComponents(OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_PIKA_AURA)) + 3, 0, 0, 0);
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimePikachuAuraSpriteIds); i++)
        DestroySprite(&gSprites[sSlotMachine->reelTimePikachuAuraSpriteIds[i]]);
}

#undef sFlashPal
#undef sColorIdx
#undef sDelayTimer
#undef sDelay

void CreateReelTimeExplosionSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeExplosion, 168, 80, 6);
    gSprites[spriteId].oam.priority = 1;
    sSlotMachine->reelTimeExplosionSpriteId = spriteId;
}

static void SpriteCB_ReelTimeExplosion(struct Sprite *sprite)
{
    sprite->y2 = gSpriteCoordOffsetY;
}

void DestroyReelTimeExplosionSprite(void)
{
    DestroySprite(&gSprites[sSlotMachine->reelTimeExplosionSpriteId]);
}

// The "confusion" ducks that circle Pikachu if the Reel Time machine explodes
void CreateReelTimeDuckSprites(void)
{
    u8 i;
    u16 sp[4];
    memcpy(sp, sReelTimeDuckOffsets, sizeof(sp));
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeDuckSpriteIds); i++)
    {
        u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeDuck, 80 - gSpriteCoordOffsetX, 68, 0);
        struct Sprite *sprite = &gSprites[spriteId];
        sprite->oam.priority = 1;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = sp[i];
        sSlotMachine->reelTimeDuckSpriteIds[i] = spriteId;
    }
}

static void SpriteCB_ReelTimeDuck(struct Sprite *sprite)
{
    sprite->data[0] -= 2;
    sprite->data[0] &= 0xff;
    sprite->x2 = Cos(sprite->data[0], 20);
    sprite->y2 = Sin(sprite->data[0], 6);
    sprite->subpriority = 0;
    if (sprite->data[0] >= 0x80)
    {
        sprite->subpriority = 2;
    }
    if (++sprite->data[1] >= 16)
    {
        sprite->hFlip ^= 1;
        sprite->data[1] = 0;
    }
}

void DestroyReelTimeDuckSprites(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sSlotMachine->reelTimeDuckSpriteIds); i++)
    {
        DestroySprite(&gSprites[sSlotMachine->reelTimeDuckSpriteIds[i]]);
    }
}

#define sState        data[0]
#define sMoveY        data[1]
#define sTimer        data[2]
#define sAnimFinished data[7]

void CreateReelTimeSmokeSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_ReelTimeSmoke, 168, 60, 8);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 1;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    sSlotMachine->reelTimeSmokeSpriteId = spriteId;
}

static void SpriteCB_ReelTimeSmoke(struct Sprite *sprite)
{
    if (sprite->sState == 0)
    {
        if (sprite->affineAnimEnded)
            sprite->sState++;
    }
    else if (sprite->sState == 1)
    {
        sprite->invisible ^= 1;
        if (++sprite->sTimer >= 24)
        {
            sprite->sState++;
            sprite->sTimer = 0;
        }
    }
    else
    {
        sprite->invisible = TRUE;
        if (++sprite->sTimer >= 16)
            sprite->sAnimFinished = TRUE;
    }
    sprite->sMoveY &= 0xff;
    sprite->sMoveY += 16;
    sprite->y2 -= (sprite->sMoveY >> 8);
}

bool8 IsReelTimeSmokeAnimFinished(void)
{
    return gSprites[sSlotMachine->reelTimeSmokeSpriteId].sAnimFinished;
}

void DestroyReelTimeSmokeSprite(void)
{
    struct Sprite *sprite = &gSprites[sSlotMachine->reelTimeSmokeSpriteId];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

#undef sState
#undef sMoveY
#undef sTimer
#undef sAnimFinished

u8 CreatePikaPowerBoltSprite(s16 x, s16 y)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_PikaPowerBolt, x, y, 12);
    struct Sprite *sprite = &gSprites[spriteId];
    sprite->oam.priority = 2;
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    return spriteId;
}

static void SpriteCB_PikaPowerBolt(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
        sprite->data[7] = TRUE;
}

void DestroyPikaPowerBoltSprite(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];
    FreeOamMatrix(sprite->oam.matrixNum);
    DestroySprite(sprite);
}

#define sState       data[0]
#define sCounter     data[1]
#define sSpriteId    data[6]
#define sWaitForAnim data[7]

u8 CreateStdDigitalDisplaySprite(u8 templateIdx, u8 dispInfoId, s16 spriteId)
{
    return CreateDigitalDisplaySprite(templateIdx, sDigitalDisplay_SpriteCallbacks[dispInfoId], sDigitalDisplay_SpriteCoords[dispInfoId][0], sDigitalDisplay_SpriteCoords[dispInfoId][1], spriteId);
}

u8 CreateDigitalDisplaySprite(u8 templateIdx, SpriteCallback callback, s16 x, s16 y, s16 internalSpriteId)
{
    struct SpriteTemplate spriteTemplate;
    u8 spriteId;
    struct Sprite *sprite;

    spriteTemplate = *sSpriteTemplates_DigitalDisplay[templateIdx];
    spriteTemplate.images = sImageTables_DigitalDisplay[templateIdx];
    spriteId = CreateSprite(&spriteTemplate, x, y, 16);
    sprite = &gSprites[spriteId];
    sprite->oam.priority = 3;
    sprite->callback = callback;
    sprite->sSpriteId = internalSpriteId;
    sprite->sWaitForAnim = TRUE;
    if (sSubspriteTables_DigitalDisplay[templateIdx])
        SetSubspriteTables(sprite, sSubspriteTables_DigitalDisplay[templateIdx]);
    return spriteId;
}

static void SpriteCB_DigitalDisplay_Static(struct Sprite *sprite)
{
    sprite->sWaitForAnim = FALSE;
}

void SpriteCB_DigitalDisplay_Smoke(struct Sprite *sprite)
{
    s16 targetX[4];
    s16 targetY[4];
    memcpy(targetX, sDigitalDisplaySmokeXOffsets, sizeof(targetX));
    memcpy(targetY, sDigitalDisplaySmokeYOffsets, sizeof(targetY));

    if (sprite->sCounter++ >= 16)
    {
        sprite->subspriteTableNum ^= 1;
        sprite->sCounter = 0;
    }
    sprite->x2 = 0;
    sprite->y2 = 0;
    if (sprite->subspriteTableNum != 0)
    {
        sprite->x2 = targetX[sprite->sSpriteId];
        sprite->y2 = targetY[sprite->sSpriteId];
    }
}

static void SpriteCB_DigitalDisplay_SmokeNE(struct Sprite *sprite)
{
    sprite->hFlip = TRUE;
    SpriteCB_DigitalDisplay_Smoke(sprite);
}

static void SpriteCB_DigitalDisplay_SmokeSW(struct Sprite *sprite)
{
    sprite->vFlip = TRUE;
    SpriteCB_DigitalDisplay_Smoke(sprite);
}

static void SpriteCB_DigitalDisplay_SmokeSE(struct Sprite *sprite)
{
    sprite->hFlip = TRUE;
    sprite->vFlip = TRUE;
    SpriteCB_DigitalDisplay_Smoke(sprite);
}

// The word "Reel" in Reel Time
static void SpriteCB_DigitalDisplay_Reel(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->x += 4;
        if (sprite->x >= DISPLAY_WIDTH - 32)
        {
            sprite->x = DISPLAY_WIDTH - 32;
            sprite->sState++;
        }
        break;
    case 1:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 2:
        sprite->x += 4;
        if (sprite->x >= DISPLAY_WIDTH + 32)
            sprite->sState++;
        break;
    case 3:
        sprite->sWaitForAnim = FALSE;
        break;
    }
}

// The word "Time" in Reel Time
static void SpriteCB_DigitalDisplay_Time(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->x -= 4;
        if (sprite->x <= DISPLAY_WIDTH - 32)
        {
            sprite->x = DISPLAY_WIDTH - 32;
            sprite->sState++;
        }
        break;
    case 1:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 2:
        sprite->x -= 4;
        if (sprite->x <= 144)
            sprite->sState++;
        break;
    case 3:
        sprite->sWaitForAnim = FALSE;
        break;
    }
}

static void SpriteCB_DigitalDisplay_ReelTimeNumber(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        StartSpriteAnim(sprite, sSlotMachine->reelTimeSpinsLeft - 1);
        sprite->sState++;
        // fallthrough
    case 1:
        if (++sprite->sCounter >= 4)
        {
            sprite->sState++;
            sprite->sCounter = 0;
        }
        break;
    case 2:
        sprite->x += 4;
        if (sprite->x >= DISPLAY_WIDTH - 32)
        {
            sprite->x = DISPLAY_WIDTH - 32;
            sprite->sState++;
        }
        break;
    case 3:
        if (++sprite->sCounter > 90)
            sprite->sState++;
        break;
    case 4:
        sprite->x += 4;
        if (sprite->x >= DISPLAY_WIDTH + 8)
            sprite->sState++;
        break;
    case 5:
        sprite->sWaitForAnim = FALSE;
        break;
    }
}

static void SpriteCB_DigitalDisplay_PokeballRocking(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->animPaused = TRUE;
        sprite->sState++;
        // fallthrough
    case 1:
        sprite->y += 8;
        if (sprite->y >= 0x70)
        {
            sprite->y = 0x70;
            sprite->sCounter = 16;
            sprite->sState++;
        }
        break;
    case 2:
        if (sprite->data[2] == 0)
        {
            sprite->y -= sprite->sCounter;
            sprite->sCounter = -sprite->sCounter;
            if (++sprite->data[3] >= 2)
            {
                sprite->sCounter >>= 2;
                sprite->data[3] = 0;
                if (sprite->sCounter == 0)
                {
                    sprite->sState++;
                    sprite->sWaitForAnim = FALSE;
                    sprite->animPaused = FALSE;
                }
            }
        }
        sprite->data[2]++;
        sprite->data[2] &= 0x07;
        break;
    }
}

static void SpriteCB_DigitalDisplay_Stop(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (++sprite->sCounter > 8)
            sprite->sState++;
        break;
    case 1:
        sprite->y += 2;
        if (sprite->y >= 0x30)
        {
            sprite->y = 0x30;
            sprite->sState++;
            sprite->sWaitForAnim = FALSE;
        }
        break;
    }
}

static void SpriteCB_DigitalDisplay_AButtonStop(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        sprite->invisible = TRUE;
        if (++sprite->sCounter > 0x20)
        {
            sprite->sState++;
            sprite->sCounter = 5;
            sprite->oam.mosaic = TRUE;
            sprite->invisible = FALSE;
            StartSpriteAnim(sprite, 1);
            SetGpuReg(REG_OFFSET_MOSAIC, ((sprite->sCounter << 4) | sprite->sCounter) << 8);
        }
        break;
    case 1:
        sprite->sCounter -= (sprite->data[2] >> 8);
        if (sprite->sCounter < 0)
            sprite->sCounter = 0;
        SetGpuReg(REG_OFFSET_MOSAIC, ((sprite->sCounter << 4) | sprite->sCounter) << 8);
        sprite->data[2] &= 0xff;
        sprite->data[2] += 0x80;
        if (sprite->sCounter == 0)
        {
            sprite->sState++;
            sprite->sWaitForAnim = FALSE;
            sprite->oam.mosaic = FALSE;
            StartSpriteAnim(sprite, 0);
        }
        break;
    }
}

static void SpriteCB_DigitalDisplay_PokeballShining(struct Sprite *sprite)
{
    if (sprite->sCounter < 3)
    {
        LoadPalette(sPokeballShiningPalTable[sprite->sCounter], OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY)), PLTT_SIZE_4BPP);
        if (++sprite->data[2] >= 4)
        {
            sprite->data[1]++;
            sprite->data[2] = 0;
        }
    }
    else
    {
        LoadPalette(sPokeballShiningPalTable[sprite->sCounter], OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY)), PLTT_SIZE_4BPP);
        if (++sprite->data[2] >= 25)
        {
            sprite->sCounter = 0;
            sprite->data[2] = 0;
        }
    }
    StartSpriteAnimIfDifferent(sprite, 1);
    sprite->sWaitForAnim = FALSE;
}

static void SpriteCB_DigitalDisplay_RegBonus(struct Sprite *sprite)
{
    // Elements in array correspond to R E G B O N U S
    s16 letterXOffset[8];
    s16 letterYOffset[8];
    s16 letterDelay[8];
    memcpy(letterXOffset, sDigitalDisplayRegBonusXOffsets, sizeof(letterXOffset));
    memcpy(letterYOffset, sDigitalDisplayRegBonusYOffsets, sizeof(letterYOffset));
    memcpy(letterDelay, sDigitalDisplayRegBonusDelays, sizeof(letterDelay));

    switch (sprite->sState)
    {
    case 0:
        sprite->x2 = letterXOffset[sprite->sSpriteId];
        sprite->y2 = letterYOffset[sprite->sSpriteId];
        sprite->sCounter = letterDelay[sprite->sSpriteId];
        sprite->sState++;
        // fallthrough
    case 1:
        if (sprite->sCounter-- == 0)
            sprite->sState++;
        break;
    case 2:
        if (sprite->x2 > 0)
            sprite->x2 -= 4;
        else if (sprite->x2 < 0)
            sprite->x2 += 4;

        if (sprite->y2 > 0)
            sprite->y2 -= 4;
        else if (sprite->y2 < 0)
            sprite->y2 += 4;

        if (sprite->x2 == 0 && sprite->y2 == 0)
            sprite->sState++;
        break;
    }
}

static void SpriteCB_DigitalDisplay_BigBonus(struct Sprite *sprite)
{
    s16 sp0[8];
    memcpy(sp0, sDigitalDisplayBigBonusOffsets, sizeof(sp0));

    if (sprite->sState == 0)
    {
        sprite->sState++;
        sprite->sCounter = 12;
    }
    sprite->x2 = Cos(sp0[sprite->sSpriteId], sprite->sCounter);
    sprite->y2 = Sin(sp0[sprite->sSpriteId], sprite->sCounter);
    if (sprite->sCounter != 0)
        sprite->sCounter--;
}

// For the A Button prompt when inserting bet
// Initially no sprite until after the first bet
static void SpriteCB_DigitalDisplay_AButtonStart(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
        case 0:
            sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_CLR;
            sSlotMachine->winOut = WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
            sSlotMachine->win0v = WIN_RANGE(32, 136);
            sprite->invisible = TRUE;
            sprite->sState++;
            // fallthrough
        case 1:
            sprite->sCounter += 2;
            sprite->data[2] = sprite->sCounter + 176;
            sprite->data[3] = DISPLAY_WIDTH - sprite->sCounter;
            if (sprite->data[2] > 208)
                sprite->data[2] = 208;
            if (sprite->data[3] < 208)
                sprite->data[3] = 208;
            sSlotMachine->win0h = (sprite->data[2] << 8) | sprite->data[3];
            if (sprite->sCounter > 51)
            {
                sprite->sState++;
                sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
            }
            break;
        case 2:
            if (sSlotMachine->bet == 0)
                break;
            AddDigitalDisplaySprite(DIG_SPRITE_A_BUTTON, SpriteCallbackDummy, 208, 116, 0);
            sSlotMachine->win0h = WIN_RANGE(192, 224);
            sSlotMachine->win0v = WIN_RANGE(104, 128);
            sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_CLR;
            sprite->sState++;
            sprite->sCounter = 0;
            // fallthrough
        case 3:
            sprite->sCounter += 2;
            sprite->data[2] = sprite->sCounter + 192;
            sprite->data[3] = DISPLAY_WIDTH - 16 - sprite->sCounter;
            if (sprite->data[2] > 208)
                sprite->data[2] = 208;
            if (sprite->data[3] < 208)
                sprite->data[3] = 208;
            sSlotMachine->win0h = (sprite->data[2] << 8) | sprite->data[3];
            if (sprite->sCounter > 15)
            {
                sprite->sState++;
                sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
            }
            break;
    }
}

static void EndDigitalDisplayScene_Dummy(void)
{
}

static void EndDigitalDisplayScene_StopReel(void)
{
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
}

static void EndDigitalDisplayScene_Win(void)
{
    LoadPalette(sDigitalDisplay_Pal, OBJ_PLTT_ID(IndexOfSpritePaletteTag(PALTAG_DIG_DISPLAY)), PLTT_SIZE_4BPP);
}

static void EndDigitalDisplayScene_InsertBet(void)
{
    sSlotMachine->win0h = DISPLAY_WIDTH;
    sSlotMachine->win0v = DISPLAY_HEIGHT;
    sSlotMachine->winIn = WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR;
    sSlotMachine->winOut = WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
}

void LoadSlotMachineGfx(void)
{
    u8 i;

    LoadReelBackground();
    sDigitalDisplayGfxPtr = Alloc(0x3200);
    LZDecompressVram(gSlotMachineDigitalDisplay_Gfx, sDigitalDisplayGfxPtr);
    sReelTimeGfxPtr = Alloc(0x3600);
    LZDecompressVram(sReelTimeGfx, sReelTimeGfxPtr);
    sSlotMachineSpritesheetsPtr = AllocZeroed(sizeof(struct SpriteSheet) * ARRAY_COUNT(sSlotMachineSpriteSheets));
    for (i = 0; i < ARRAY_COUNT(sSlotMachineSpriteSheets); i++)
    {
        sSlotMachineSpritesheetsPtr[i].data = sSlotMachineSpriteSheets[i].data;
        sSlotMachineSpritesheetsPtr[i].size = sSlotMachineSpriteSheets[i].size;
        sSlotMachineSpritesheetsPtr[i].tag = sSlotMachineSpriteSheets[i].tag;
    }
    sSlotMachineSpritesheetsPtr[GFXTAG_STOP - 1].data = sDigitalDisplayGfxPtr + 0xA00;
    sSlotMachineSpritesheetsPtr[GFXTAG_BONUS - 1].data = sDigitalDisplayGfxPtr + 0x1400;
    sSlotMachineSpritesheetsPtr[GFXTAG_BIG - 1].data = sDigitalDisplayGfxPtr + 0x1600;
    sSlotMachineSpritesheetsPtr[GFXTAG_REG - 1].data = sDigitalDisplayGfxPtr + 0x1900;
    LoadSpriteSheets(sSlotMachineSpritesheetsPtr);
    LoadSpritePalettes(sSlotMachineSpritePalettes);
}

void LoadReelBackground(void)
{
    u8 *dest;
    u8 i, j;

    sReelBackgroundSpriteSheet = AllocZeroed(sizeof(struct SpriteSheet));
    sReelBackground_Gfx = AllocZeroed(0x2000); // Background is plain white
    dest = sReelBackground_Gfx;
    for (i = 0; i < 0x40; i++)
    {
        for (j = 0; j < 0x20; j++, dest++)
            *dest = sReelBackground_Tilemap[j];
    }
    sReelBackgroundSpriteSheet->data = sReelBackground_Gfx;
    sReelBackgroundSpriteSheet->size = 0x800;
    sReelBackgroundSpriteSheet->tag  = GFXTAG_REEL_BG;
    LoadSpriteSheet(sReelBackgroundSpriteSheet);
}

void LoadMenuGfx(void)
{
    sMenuGfx = Alloc(0x2000);
    LZDecompressVram(gSlotMachineMenu_Gfx, sMenuGfx);
    LoadBgTiles(2, sMenuGfx, 0x1D20, 0);
    LoadPalette(gSlotMachineMenu_Pal, BG_PLTT_ID(0), 5 * PLTT_SIZE_4BPP);
    LoadPalette(sUnkPalette, BG_PLTT_ID(13), PLTT_SIZE_4BPP);
}

void LoadMenuAndReelOverlayTilemaps(void)
{
    LoadSlotMachineMenuTilemap();
    LoadSlotMachineReelOverlay();
}

static void LoadSlotMachineMenuTilemap(void)
{
    u8 i;

    for (i = 0; i <= 0x13; i++)
        LoadBgTilemap(2, (const u8 *)gSlotMachineMenu_Tilemap + i * 60, 0x3c, i * 32);
}

void LoadSlotMachineReelOverlay(void)
{
    s16 x, y, dx;

    for (x = 4; x < 18; x += 5)
    {
        for (dx = 0; dx < 4; dx++)
        {
            LoadBgTilemap(3, sReelOverlay_Tilemap,     2, x + dx + 5  * 32);
            LoadBgTilemap(3, sReelOverlay_Tilemap + 1, 2, x + dx + 13 * 32);
            LoadBgTilemap(3, sReelOverlay_Tilemap + 2, 2, x + dx + 6  * 32);
            LoadBgTilemap(3, sReelOverlay_Tilemap + 3, 2, x + dx + 12 * 32);
        }

        LoadBgTilemap(3, sReelOverlay_Tilemap + 4, 2, x + 6 * 32);
        LoadBgTilemap(3, sReelOverlay_Tilemap + 5, 2, x + 12 * 32);

        for (y = 7; y <= 11; y++)
            LoadBgTilemap(3, sReelOverlay_Tilemap + 6, 2, x + y * 32);
    }
}

// For (un)shading the gray button at the bottom of a reel when A is pressed. The button is colored in quadrants
void SetReelButtonTilemap(s16 offset, u16 topLeft, u16 topRight, u16 bottomLeft, u16 bottomRight)
{
    sReelButtonPress_Tilemap[0] = topLeft;
    sReelButtonPress_Tilemap[1] = topRight;
    sReelButtonPress_Tilemap[2] = bottomLeft;
    sReelButtonPress_Tilemap[3] = bottomRight;

    LoadBgTilemap(2, sReelButtonPress_Tilemap,     2, 15 * 32 + offset);     // Top left
    LoadBgTilemap(2, sReelButtonPress_Tilemap + 1, 2, 15 * 32 + 1 + offset); // Top right
    LoadBgTilemap(2, sReelButtonPress_Tilemap + 2, 2, 16 * 32 + offset);     // Bottom left
    LoadBgTilemap(2, sReelButtonPress_Tilemap + 3, 2, 16 * 32 + 1 + offset); // Bottom Right
}

static void LoadInfoBoxTilemap(void)
{
    u8 i;

    for (i = 0; i <= 0x13; i++)
        LoadBgTilemap(2, (const u8 *)gSlotMachineInfoBox_Tilemap + i * 60, 0x3c, i * 32);
    HideBg(3);
}

void SetDigitalDisplayImagePtrs(void)
{
    sImageTables_DigitalDisplay[DIG_SPRITE_REEL]      = sImageTable_DigitalDisplay_Reel;
    sImageTables_DigitalDisplay[DIG_SPRITE_TIME]      = sImageTable_DigitalDisplay_Time;
    sImageTables_DigitalDisplay[DIG_SPRITE_INSERT]    = sImageTable_DigitalDisplay_Insert;
    sImageTables_DigitalDisplay[DIG_SPRITE_WIN]       = sImageTable_DigitalDisplay_Win;
    sImageTables_DigitalDisplay[DIG_SPRITE_LOSE]      = sImageTable_DigitalDisplay_Lose;
    sImageTables_DigitalDisplay[DIG_SPRITE_A_BUTTON]  = sImageTable_DigitalDisplay_AButton;
    sImageTables_DigitalDisplay[DIG_SPRITE_SMOKE]     = sImageTable_DigitalDisplay_Smoke;
    sImageTables_DigitalDisplay[DIG_SPRITE_NUMBER]    = sImageTable_DigitalDisplay_Number;
    sImageTables_DigitalDisplay[DIG_SPRITE_POKE_BALL] = sImageTable_DigitalDisplay_Pokeball;
    sImageTables_DigitalDisplay[DIG_SPRITE_D_PAD]     = sImageTable_DigitalDisplay_DPad;
    sImageTables_DigitalDisplay[DIG_SPRITE_STOP_S]    = sImageTable_DigitalDisplay_Stop;
    sImageTables_DigitalDisplay[DIG_SPRITE_STOP_T]    = sImageTable_DigitalDisplay_Stop;
    sImageTables_DigitalDisplay[DIG_SPRITE_STOP_O]    = sImageTable_DigitalDisplay_Stop;
    sImageTables_DigitalDisplay[DIG_SPRITE_STOP_P]    = sImageTable_DigitalDisplay_Stop;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_B]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_O]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_N]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_U]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BONUS_S]   = sImageTable_DigitalDisplay_Bonus;
    sImageTables_DigitalDisplay[DIG_SPRITE_BIG_B]     = sImageTable_DigitalDisplay_Big;
    sImageTables_DigitalDisplay[DIG_SPRITE_BIG_I]     = sImageTable_DigitalDisplay_Big;
    sImageTables_DigitalDisplay[DIG_SPRITE_BIG_G]     = sImageTable_DigitalDisplay_Big;
    sImageTables_DigitalDisplay[DIG_SPRITE_REG_R]     = sImageTable_DigitalDisplay_Reg;
    sImageTables_DigitalDisplay[DIG_SPRITE_REG_E]     = sImageTable_DigitalDisplay_Reg;
    sImageTables_DigitalDisplay[DIG_SPRITE_REG_G]     = sImageTable_DigitalDisplay_Reg;
    sImageTables_DigitalDisplay[DIG_SPRITE_EMPTY]     = NULL;
}

void AllocDigitalDisplayGfx(void)
{
    sImageTable_DigitalDisplay_Reel = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Reel[0].data = sDigitalDisplayGfxPtr;
    sImageTable_DigitalDisplay_Reel[0].size = 0x600;

    sImageTable_DigitalDisplay_Time = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Time[0].data = sDigitalDisplayGfxPtr + 0x600;
    sImageTable_DigitalDisplay_Time[0].size = 0x200;

    sImageTable_DigitalDisplay_Insert = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Insert[0].data = sDigitalDisplayGfxPtr + 0x800;
    sImageTable_DigitalDisplay_Insert[0].size = 0x200;

    sImageTable_DigitalDisplay_Stop = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Stop[0].data = sDigitalDisplayGfxPtr + 0xA00;
    sImageTable_DigitalDisplay_Stop[0].size = 0x200;

    sImageTable_DigitalDisplay_Win = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Win[0].data = sDigitalDisplayGfxPtr + 0xC00;
    sImageTable_DigitalDisplay_Win[0].size = 0x300;

    sImageTable_DigitalDisplay_Lose = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Lose[0].data = sDigitalDisplayGfxPtr + 0x1000;
    sImageTable_DigitalDisplay_Lose[0].size = 0x400;

    sImageTable_DigitalDisplay_Bonus = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Bonus[0].data = sDigitalDisplayGfxPtr + 0x1400;
    sImageTable_DigitalDisplay_Bonus[0].size = 0x200;

    sImageTable_DigitalDisplay_Big = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Big[0].data = sDigitalDisplayGfxPtr + 0x1600;
    sImageTable_DigitalDisplay_Big[0].size = 0x300;

    sImageTable_DigitalDisplay_Reg = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Reg[0].data = sDigitalDisplayGfxPtr + 0x1900;
    sImageTable_DigitalDisplay_Reg[0].size = 0x300;

    sImageTable_DigitalDisplay_AButton = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sImageTable_DigitalDisplay_AButton[0].data = sDigitalDisplayGfxPtr + 0x1C00;
    sImageTable_DigitalDisplay_AButton[0].size = 0x200;
    sImageTable_DigitalDisplay_AButton[1].data = sDigitalDisplayGfxPtr + 0x1E00;
    sImageTable_DigitalDisplay_AButton[1].size = 0x200;

    sImageTable_DigitalDisplay_Smoke = AllocZeroed(sizeof(struct SpriteFrameImage) * 1);
    sImageTable_DigitalDisplay_Smoke[0].data = sDigitalDisplayGfxPtr + 0x2000;
    sImageTable_DigitalDisplay_Smoke[0].size = 640;

    sImageTable_DigitalDisplay_Number = AllocZeroed(sizeof(struct SpriteFrameImage) * 5);
    sImageTable_DigitalDisplay_Number[0].data = sDigitalDisplayGfxPtr + 0x2280;
    sImageTable_DigitalDisplay_Number[0].size = 0x80;
    sImageTable_DigitalDisplay_Number[1].data = sDigitalDisplayGfxPtr + 0x2300;
    sImageTable_DigitalDisplay_Number[1].size = 0x80;
    sImageTable_DigitalDisplay_Number[2].data = sDigitalDisplayGfxPtr + 0x2380;
    sImageTable_DigitalDisplay_Number[2].size = 0x80;
    sImageTable_DigitalDisplay_Number[3].data = sDigitalDisplayGfxPtr + 0x2400;
    sImageTable_DigitalDisplay_Number[3].size = 0x80;
    sImageTable_DigitalDisplay_Number[4].data = sDigitalDisplayGfxPtr + 0x2480;
    sImageTable_DigitalDisplay_Number[4].size = 0x80;

    sImageTable_DigitalDisplay_Pokeball = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sImageTable_DigitalDisplay_Pokeball[0].data = sDigitalDisplayGfxPtr + 0x2600;
    sImageTable_DigitalDisplay_Pokeball[0].size = 0x480;
    sImageTable_DigitalDisplay_Pokeball[1].data = sDigitalDisplayGfxPtr + 10880;
    sImageTable_DigitalDisplay_Pokeball[1].size = 0x480;

    sImageTable_DigitalDisplay_DPad = AllocZeroed(sizeof(struct SpriteFrameImage) * 2);
    sImageTable_DigitalDisplay_DPad[0].data = sDigitalDisplayGfxPtr + 0x2F00;
    sImageTable_DigitalDisplay_DPad[0].size = 0x180;
    sImageTable_DigitalDisplay_DPad[1].data = sDigitalDisplayGfxPtr + 0x3080;
    sImageTable_DigitalDisplay_DPad[1].size = 0x180;
}

// NOTE: these functions are placed at the end of the file on purpose: agbcc's
// register allocation for LoadReelBackground changes if C code precedes it
// (the ROM only matches when the ReelTime bias/draw helpers come after it).
static void DrawMachineBias(void)
{
    u8 whichBias;

    if (sSlotMachine->reelTimeSpinsLeft == 0)
    {
        if (!(sSlotMachine->machineBias & (BIAS_STRAIGHT_7 | BIAS_MIXED_7)))
        {
            if (ShouldTrySpecialBias())
            {
                whichBias = TrySelectBias_Special();
                if (whichBias != ARRAY_COUNT(sBiasesSpecial)) // A bias was selected
                {
                    sSlotMachine->machineBias |= sBiasesSpecial[whichBias];

                    // ReelTime was not selected; don't add other biases
                    if (whichBias != 1) return;
                }
            }

            whichBias = TrySelectBias_Regular();
            if (whichBias != ARRAY_COUNT(sBiasesRegular)) // A bias was selected
                sSlotMachine->machineBias |= sBiasesRegular[whichBias];
        }
    }
}

// Reset `didNotFailBias` to match `machineBias`.
static void ResetBiasFailure(void)
{
    sSlotMachine->didNotFailBias = FALSE;
    if (sSlotMachine->machineBias)
        sSlotMachine->didNotFailBias = TRUE;
}

// JP-specific: decides whether this round is lucky. JP indexes the odds table
// as a flat array (bet + machineId * 3 - 1); US uses [machineId][bet - 1].
static bool8 ShouldTrySpecialBias(void)
{
    u8 rval = Random();
    if (sSpecialDrawOdds[sSlotMachine->machineId][sSlotMachine->bet - 1] > rval)
        return TRUE;
    return FALSE;
}

// Draws for a Special bias. Note that even when you're given the opportunity to
// draw a Special bias, you can still miss.
static u8 TrySelectBias_Special(void)
{
    s16 whichBias;

    for (whichBias = 0; whichBias < (int)ARRAY_COUNT(sBiasesSpecial); whichBias++)
    {
        s16 rval = Random() & 0xff;
        s16 value = sBiasProbabilities_Special[whichBias][sSlotMachine->machineId];
        if (value > rval)
            break;
    }
    return whichBias;
}

static u8 TrySelectBias_Regular(void)
{
    s16 whichBias;

    for (whichBias = 0; whichBias < (int)ARRAY_COUNT(sBiasesRegular); whichBias++)
    {
        s16 rval = Random() & 0xff;
        s16 value = sBiasProbabilities_Regular[whichBias][sSlotMachine->machineId];

        // Boost odds of BIAS_POWER if it's a lucky game.
        if (whichBias == 0 && sSlotMachine->luckyGame == TRUE)
        {
            value += 10;
            if (value > 0x100)
                value = 0x100;
        }
        // Reduce odds of BIAS_REPLAY if it's a lucky game
        else if (whichBias == 4 && sSlotMachine->luckyGame == TRUE)
        {
            value -= 10;
            if (value < 0)
                value = 0;
        }
        if (value > rval)
            break;
    }
    return whichBias;
}

// Return the probability of drawing the given number of ReelTime spins.
//
// This depends on whether it is a lucky game and the number of Power bolts you
// have collected.
static u8 GetReelTimeSpinProbability(u8 spins)
{
    if (sSlotMachine->luckyGame == FALSE)
        return sReelTimeProbabilities_NormalGame[spins][sSlotMachine->pikaPowerBolts];
    else
        return sReelTimeProbabilities_LuckyGame[spins][sSlotMachine->pikaPowerBolts];
}

// The way this is computed skews the odds much more toward drawing a 0 than
// intended. It initially checks whether you draw a 0 (using the intended
// probability). It then tries to draw positive values, but if these draws all
// miss, you'll still draw a 0.
static void GetReelTimeDraw(void)
{
    u8 rval;
    s16 spins;

    sSlotMachine->reelTimeDraw = 0;
    rval = Random();
    if (rval < GetReelTimeSpinProbability(0))
        return;
    for (spins = 5; spins > 0; spins--)
    {
        rval = Random();
        if (rval < GetReelTimeSpinProbability(spins))
            break;
    }
    sSlotMachine->reelTimeDraw = spins;
}

static u16 ReelTimeSpeed(void)
{
    u8 i = 0;
    u8 rval;
    u8 value;
    if (sSlotMachine->netCoinLoss > 299) // JP threshold uses SPECIAL_DoContestHallWarp (299)
        i = 4;
    else if (sSlotMachine->netCoinLoss > 249)
        i = 3;
    else if (sSlotMachine->netCoinLoss > 199)
        i = 2;
    else if (sSlotMachine->netCoinLoss > 149)
        i = 1;

    rval = Random() % 100;
    value = sReelTimeSpeed_Probabilities[i][0];
    if (rval < value)
        return REEL_HALF_SPEED;

    rval = Random() % 100;
    value = sReelTimeSpeed_Probabilities[i][1] + sQuarterSpeed_ProbabilityBoost[sSlotMachine->reelTimeSpinsUsed];
    if (rval < value)
        return REEL_QUARTER_SPEED;

    return REEL_NORMAL_SPEED;
}

// NOTE: kept at the end of the file (same agbcc position quirk as the
// ReelTime bias/draw helpers): C code before LoadReelBackground changes its
// register allocation and breaks byte-matching.
static bool8 EitherSymbolAtPos_Reel1(s16 pos, u8 sym1, u8 sym2)
{
    u8 sym = GetSymbol(LEFT_REEL, pos);
    if (sym == sym1 || sym == sym2)
    {
        sSlotMachine->biasSymbol = sym;
        return TRUE;
    }
    return FALSE;
}

static void DecideStop_NoBias_Reel2_Bet3(void)
{
    s16 i;
    s16 j;
    u8 reel1BiasSym;

    if (sSlotMachine->winnerRows[0] != 0 && sSlotMachine->machineBias & BIAS_STRAIGHT_7)
    {
        // Lined up 7 in middle of reel 1
        if (sSlotMachine->winnerRows[0] == 2)
        {
            DecideStop_NoBias_Reel2_Bet2();
            return;
        }

        reel1BiasSym = GetSymbol(LEFT_REEL, sSlotMachine->winnerRows[0] - sSlotMachine->reelExtraTurns[0]);
        if (IfSymbol7_SwitchColor(&reel1BiasSym))
        {
            // Check current screen to see if there is already an opposite-color
            // 7 lined up for a match.
            j = 2;
            if (sSlotMachine->winnerRows[0] == 3)
                j = 3;
            for (i = 0; i < 2; i++, j--)
            {
                if (reel1BiasSym == GetSymbol(MIDDLE_REEL, j))
                {
                    sSlotMachine->winnerRows[1] = j;
                    sSlotMachine->reelExtraTurns[1] = 0;
                    return;
                }
            }

            // Check if opposite-color 7 will appear in same row as reel 1 in
            // over the next 4 turns
            for (j = 1; j <= MAX_EXTRA_TURNS; j++)
            {
                if (reel1BiasSym == GetSymbol(MIDDLE_REEL, sSlotMachine->winnerRows[0] - j))
                {
                    // If 7 appeared in top row of reel 1
                    if (sSlotMachine->winnerRows[0] == 1)
                    {
                        if (j <= 2)
                        {
                            sSlotMachine->winnerRows[1] = 2;
                            sSlotMachine->reelExtraTurns[1] = j + 1;
                        }
                        else
                        {
                            sSlotMachine->winnerRows[1] = 1;
                            sSlotMachine->reelExtraTurns[1] = j;
                        }
                    }
                    // If 7 appeared in bottom row of reel 1
                    else
                    {
                        if (j <= 2)
                        {
                            sSlotMachine->winnerRows[1] = 3;
                            sSlotMachine->reelExtraTurns[1] = j;
                        }
                        else
                        {
                            sSlotMachine->winnerRows[1] = 2;
                            sSlotMachine->reelExtraTurns[1] = j - 1;
                        }
                    }
                    return;
                }
            }
        }
    }
}

