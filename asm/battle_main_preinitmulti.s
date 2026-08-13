.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start CB2_PreInitMultiBattle
CB2_PreInitMultiBattle: @ 0x0803782C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #4
	mov sb, r0
	movs r4, #0xf
	ldr r6, _08037890
	ldr r0, [r6]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08037852
	movs r1, #2
	mov sb, r1
	movs r4, #3
_08037852:
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _08037894
	adds r0, #0x25
	movs r2, #0
	mov r8, r2
	strb r7, [r0]
	ldr r0, _08037898
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0xb4
	str r1, [sp]
	adds r0, #0xac
	mov sl, r0
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	ldr r5, _0803789C
	ldrb r0, [r5]
	cmp r0, #1
	beq _080378F4
	cmp r0, #1
	bgt _080378A0
	cmp r0, #0
	beq _080378AE
	b _08037A5A
	.align 2, 0
_08037890: .4byte 0x02022C90
_08037894: .4byte 0x02024118
_08037898: .4byte 0x02024140
_0803789C: .4byte 0x02023FD6
_080378A0:
	cmp r0, #2
	bne _080378A6
	b _080379B4
_080378A6:
	cmp r0, #3
	bne _080378AC
	b _080379EE
_080378AC:
	b _08037A5A
_080378AE:
	ldr r0, _080378EC
	ldrb r0, [r0]
	cmp r0, #0
	bne _080378B8
	b _08037A5A
_080378B8:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080378C4
	b _08037A5A
_080378C4:
	ldr r4, _080378F0
	movs r0, #0x60
	bl Alloc
	str r0, [r4]
	movs r0, #0
	bl sub_08037770
	bl bitmask_all_link_players_but_self
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r4]
	movs r2, #0x60
	bl SendBlock
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08037A5A
	.align 2, 0
_080378EC: .4byte 0x030031C4
_080378F0: .4byte 0x02022CFC
_080378F4:
	bl GetBlockReceivedStatus
	adds r1, r4, #0
	ands r1, r0
	cmp r1, r4
	beq _08037902
	b _08037A5A
_08037902:
	bl ResetBlockReceivedFlags
	movs r5, #0
	cmp r8, sb
	bge _0803797E
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r6, r0, #2
	mov r8, r5
	ldr r4, _08037940
_08037916:
	cmp r5, r7
	beq _0803796E
	mov r2, sb
	cmp r2, #4
	bne _08037964
	ldr r2, _08037944
	mov r1, r8
	adds r0, r1, r2
	ldrh r1, [r0, #0x18]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _08037948
	adds r0, r6, r2
	ldrh r1, [r0, #0x18]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08037954
	b _0803796E
	.align 2, 0
_08037940: .4byte 0x0202207C
_08037944: .4byte 0x020226A0
_08037948:
	adds r0, r6, r2
	ldrh r1, [r0, #0x18]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0803796E
_08037954:
	ldr r0, _08037960
	adds r1, r4, #0
	movs r2, #0x60
	bl memcpy
	b _0803796E
	.align 2, 0
_08037960: .4byte 0x02022C9C
_08037964:
	ldr r0, _080379A0
	adds r1, r4, #0
	movs r2, #0x60
	bl memcpy
_0803796E:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r4, r4, r2
	movs r0, #0x1c
	add r8, r0
	adds r5, #1
	cmp r5, sb
	blt _08037916
_0803797E:
	ldr r1, _080379A4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _080379A8
	ldr r0, [r1, #8]
	ldr r2, [sp]
	str r0, [r2]
	ldr r0, _080379AC
	ldr r0, [r0]
	mov r2, sl
	str r0, [r2]
	ldr r0, _080379B0
	str r0, [r1, #8]
	bl sub_081B8DF0
	b _08037A5A
	.align 2, 0
_080379A0: .4byte 0x02022C9C
_080379A4: .4byte 0x02023FD6
_080379A8: .4byte 0x03002360
_080379AC: .4byte 0x02022C90
_080379B0: .4byte 0x0803782D
_080379B4:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08037A5A
	ldr r0, _080379E0
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08037A5A
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r0, _080379E4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080379E8
	bl SetLinkStandbyCallback
	b _08037A5A
	.align 2, 0
_080379E0: .4byte 0x02037C74
_080379E4: .4byte 0x0300319C
_080379E8:
	bl SetCloseLinkCallback
	b _08037A5A
_080379EE:
	ldr r0, _08037A24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037A34
	bl IsLinkRfuTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08037A5A
	mov r1, sl
	ldr r0, [r1]
	str r0, [r6]
	ldr r1, _08037A28
	ldr r2, [sp]
	ldr r0, [r2]
	str r0, [r1, #8]
	ldr r0, _08037A2C
	bl SetMainCallback2
	ldr r4, _08037A30
	ldr r0, [r4]
	bl Free
	mov r0, r8
	str r0, [r4]
	b _08037A5A
	.align 2, 0
_08037A24: .4byte 0x0300319C
_08037A28: .4byte 0x03002360
_08037A2C: .4byte 0x08036629
_08037A30: .4byte 0x02022CFC
_08037A34:
	ldr r0, _08037A6C
	ldrb r5, [r0]
	cmp r5, #0
	bne _08037A5A
	mov r1, sl
	ldr r0, [r1]
	str r0, [r6]
	ldr r1, _08037A70
	ldr r2, [sp]
	ldr r0, [r2]
	str r0, [r1, #8]
	ldr r0, _08037A74
	bl SetMainCallback2
	ldr r4, _08037A78
	ldr r0, [r4]
	bl Free
	str r5, [r4]
_08037A5A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037A6C: .4byte 0x030031C4
_08037A70: .4byte 0x03002360
_08037A74: .4byte 0x08036629
_08037A78: .4byte 0x02022CFC
	thumb_func_end CB2_PreInitMultiBattle

