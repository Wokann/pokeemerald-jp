.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start CheckForFlashMemory
CheckForFlashMemory: @ 0x08076570
	push {lr}
	bl IdentifyFlash
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0807658C
	ldr r1, _08076588
	movs r0, #1
	str r0, [r1]
	bl InitFlashTimer
	b _08076592
	.align 2, 0
_08076588: .4byte 0x03005AE8
_0807658C:
	ldr r1, _08076598
	movs r0, #0
	str r0, [r1]
_08076592:
	pop {r0}
	bx r0
	.align 2, 0
_08076598: .4byte 0x03005AE8
	thumb_func_end CheckForFlashMemory

	thumb_func_start ClearSav1
ClearSav1: @ 0x0807659C
	push {lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080765B8
	ldr r2, _080765BC
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080765B8: .4byte 0x020246F8
_080765BC: .4byte 0x010007D6
	thumb_func_end ClearSav1

	thumb_func_start ClearSav2
ClearSav2: @ 0x080765C0
	push {lr}
	sub sp, #4
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080765DC
	ldr r2, _080765E0
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080765DC: .4byte 0x020256A4
_080765E0: .4byte 0x01001F04
	thumb_func_end ClearSav2

	thumb_func_start SetSaveBlocksPointers
SetSaveBlocksPointers: @ 0x080765E4
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r5, _0807661C
	bl Random
	adds r4, r4, r0
	movs r0, #0x7c
	ands r4, r0
	ldr r1, _08076620
	ldr r0, _08076624
	adds r0, r4, r0
	str r0, [r1]
	ldr r0, _08076628
	adds r0, r4, r0
	str r0, [r5]
	ldr r1, _0807662C
	ldr r0, _08076630
	adds r4, r4, r0
	str r4, [r1]
	bl SetBagItemsPointers
	bl SetDecorationInventoriesPointers
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807661C: .4byte 0x03005AEC
_08076620: .4byte 0x03005AF0
_08076624: .4byte 0x020246F8
_08076628: .4byte 0x020256A4
_0807662C: .4byte 0x03005AF4
_08076630: .4byte 0x020294AC
	thumb_func_end SetSaveBlocksPointers

	thumb_func_start MoveSaveBlocks_ResetHeap
MoveSaveBlocks_ResetHeap: @ 0x08076634
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r5, _08076700
	ldr r0, [r5, #0xc]
	str r0, [sp]
	ldr r1, [r5, #0x10]
	str r1, [sp, #4]
	movs r0, #0
	str r0, [r5, #0xc]
	str r0, [r5, #0x10]
	ldr r1, _08076704
	str r0, [r1]
	ldr r4, _08076708
	ldr r0, _0807670C
	ldr r1, [r0]
	ldr r6, _08076710
	adds r0, r4, #0
	adds r2, r6, #0
	bl memcpy
	ldr r1, _08076714
	mov sl, r1
	ldr r1, [r1]
	ldr r7, _08076718
	ldr r0, _0807671C
	adds r2, r7, #0
	bl memcpy
	ldr r0, _08076720
	mov r8, r0
	ldr r1, [r0]
	ldr r0, _08076724
	mov sb, r0
	ldr r0, _08076728
	mov r2, sb
	bl memcpy
	ldrb r1, [r4, #0xa]
	ldrb r0, [r4, #0xb]
	adds r1, r1, r0
	ldrb r0, [r4, #0xc]
	adds r1, r1, r0
	ldrb r0, [r4, #0xd]
	adds r0, r0, r1
	bl SetSaveBlocksPointers
	ldr r1, _0807670C
	ldr r0, [r1]
	adds r1, r4, #0
	adds r2, r6, #0
	bl memcpy
	mov r1, sl
	ldr r0, [r1]
	ldr r1, _0807671C
	adds r2, r7, #0
	bl memcpy
	mov r1, r8
	ldr r0, [r1]
	ldr r1, _08076728
	mov r2, sb
	bl memcpy
	movs r1, #0xe0
	lsls r1, r1, #9
	adds r0, r4, #0
	bl InitHeap
	ldr r0, [sp, #4]
	str r0, [r5, #0x10]
	ldr r1, [sp]
	str r1, [r5, #0xc]
	bl Random
	adds r4, r0, #0
	bl Random
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r0
	adds r0, r4, #0
	bl ApplyNewEncryptionKeyToAllEncryptedData
	ldr r1, _0807670C
	ldr r0, [r1]
	adds r0, #0xac
	str r4, [r0]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076700: .4byte 0x03002360
_08076704: .4byte 0x0203CC28
_08076708: .4byte 0x02000000
_0807670C: .4byte 0x03005AF0
_08076710: .4byte 0x00000F2C
_08076714: .4byte 0x03005AEC
_08076718: .4byte 0x00003D88
_0807671C: .4byte 0x02000F2C
_08076720: .4byte 0x03005AF4
_08076724: .4byte 0x000083D0
_08076728: .4byte 0x02004CB4
	thumb_func_end MoveSaveBlocks_ResetHeap

	thumb_func_start UseContinueGameWarp
UseContinueGameWarp: @ 0x0807672C
	ldr r0, _08076738
	ldr r0, [r0]
	ldrb r1, [r0, #9]
	movs r0, #1
	ands r0, r1
	bx lr
	.align 2, 0
_08076738: .4byte 0x03005AF0
	thumb_func_end UseContinueGameWarp

