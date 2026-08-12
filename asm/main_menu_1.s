.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start Task_MainMenuCheckSaveFile
Task_MainMenuCheckSaveFile: @ 0x0802F53C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r6, r0, #3
	ldr r0, _0802F5C0
	mov r8, r0
	adds r4, r6, r0
	ldr r0, _0802F5C4
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _0802F564
	b _0802F704
_0802F564:
	movs r0, #0x40
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x44
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0x11
	bl SetGpuReg
	movs r0, #0x4a
	movs r1, #0x31
	bl SetGpuReg
	movs r0, #0x50
	movs r1, #0xc1
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x54
	movs r1, #7
	bl SetGpuReg
	bl IsWirelessAdapterConnected
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802F5AA
	movs r0, #1
	strh r0, [r4, #0x1e]
_0802F5AA:
	ldr r0, _0802F5C8
	ldrh r0, [r0]
	cmp r0, #2
	beq _0802F614
	cmp r0, #2
	bgt _0802F5CC
	cmp r0, #0
	beq _0802F66C
	cmp r0, #1
	beq _0802F5D6
	b _0802F66C
	.align 2, 0
_0802F5C0: .4byte 0x03005B68
_0802F5C4: .4byte 0x02037C74
_0802F5C8: .4byte 0x03005F50
_0802F5CC:
	cmp r0, #4
	beq _0802F688
	cmp r0, #0xff
	beq _0802F628
	b _0802F66C
_0802F5D6:
	strh r0, [r4]
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0802F5EE
	bl IsMysteryEventEnabled
	cmp r0, #0
	beq _0802F5EE
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802F5EE:
	bl IsMysteryGiftEnabled
	cmp r0, #0
	beq _0802F5FC
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802F5FC:
	ldr r0, _0802F60C
	lsls r1, r7, #2
	adds r1, r1, r7
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _0802F610
	str r0, [r1]
	b _0802F69A
	.align 2, 0
_0802F60C: .4byte 0x03005B60
_0802F610: .4byte 0x0802F76D
_0802F614:
	ldr r0, _0802F624
	bl CreateMainMenuErrorWindow
	strh r5, [r4]
	mov r0, r8
	subs r0, #8
	adds r0, r6, r0
	b _0802F696
	.align 2, 0
_0802F624: .4byte 0x085C8D6B
_0802F628:
	ldr r0, _0802F664
	bl CreateMainMenuErrorWindow
	mov r0, r8
	subs r0, #8
	adds r0, r6, r0
	ldr r1, _0802F668
	str r1, [r0]
	movs r0, #1
	strh r0, [r4]
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0802F652
	bl IsMysteryEventEnabled
	cmp r0, #1
	bne _0802F652
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802F652:
	bl IsMysteryGiftEnabled
	cmp r0, #1
	bne _0802F69A
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0802F69A
	.align 2, 0
_0802F664: .4byte 0x085C8D44
_0802F668: .4byte 0x0802F719
_0802F66C:
	movs r0, #0
	strh r0, [r4]
	ldr r1, _0802F680
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _0802F684
	b _0802F698
	.align 2, 0
_0802F680: .4byte 0x03005B60
_0802F684: .4byte 0x0802F76D
_0802F688:
	ldr r0, _0802F6BC
	bl CreateMainMenuErrorWindow
	mov r0, r8
	subs r0, #8
	adds r0, r6, r0
	strh r5, [r0, #8]
_0802F696:
	ldr r1, _0802F6C0
_0802F698:
	str r1, [r0]
_0802F69A:
	ldr r5, _0802F6C4
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0802F6F2
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #2
	beq _0802F6D2
	cmp r0, #2
	ble _0802F6C8
	cmp r0, #3
	beq _0802F6EE
	b _0802F6F2
	.align 2, 0
_0802F6BC: .4byte 0x085C8D80
_0802F6C0: .4byte 0x0802F719
_0802F6C4: .4byte 0x020229BA
_0802F6C8:
	cmp r0, #0
	blt _0802F6F2
	ldrh r0, [r4]
	adds r0, #1
	b _0802F6F0
_0802F6D2:
	bl IsMysteryEventEnabled
	cmp r0, #0
	bne _0802F6EA
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _0802F6F2
	bl IsMysteryGiftEnabled
	cmp r0, #0
	beq _0802F6F2
_0802F6EA:
	movs r0, #3
	b _0802F6F0
_0802F6EE:
	movs r0, #4
_0802F6F0:
	strh r0, [r5]
_0802F6F2:
	ldr r2, _0802F710
	ldrh r1, [r2]
	ldr r0, _0802F714
	ands r0, r1
	strh r0, [r2]
	strh r0, [r4, #2]
	ldrh r0, [r4]
	adds r0, #2
	strh r0, [r4, #0x18]
_0802F704:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F710: .4byte 0x020229BA
_0802F714: .4byte 0x00007FFF
	thumb_func_end Task_MainMenuCheckSaveFile

