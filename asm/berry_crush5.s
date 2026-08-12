.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified





	thumb_func_start sub_0802420C
sub_0802420C: @ 0x0802420C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _08024284
	cmp r4, #1
	bgt _08024222
	cmp r4, #0
	beq _08024228
	b _080242BE
_08024222:
	cmp r4, #2
	beq _0802429C
	b _080242BE
_08024228:
	movs r0, #0
	movs r1, #0
	bl DrawDialogueFrame
	ldrh r1, [r5, #0x14]
	cmp r1, #3
	bne _08024258
	ldr r0, _08024254
	ldr r2, [r0, #0x14]
	ldrb r3, [r5, #0xb]
	str r4, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	bl AddTextPrinterParameterized2
	b _08024274
	.align 2, 0
_08024254: .4byte 0x082C5EBC
_08024258:
	ldr r0, _08024280
	ldr r2, [r0, #0x18]
	ldrb r3, [r5, #0xb]
	str r4, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	bl AddTextPrinterParameterized2
_08024274:
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	b _080242BE
	.align 2, 0
_08024280: .4byte 0x082C5EBC
_08024284:
	movs r0, #0
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080242C4
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x78
	strb r0, [r1]
	b _080242BE
_0802429C:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq _080242B0
	subs r0, #1
	strb r0, [r1]
	b _080242C4
_080242B0:
	movs r0, #0x18
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _080242C4
_080242BE:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_080242C4:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802420C

	thumb_func_start sub_080242D0
sub_080242D0: @ 0x080242D0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _080242F0
	cmp r4, #1
	bgt _080242E4
	cmp r4, #0
	beq _080242EA
	b _08024320
_080242E4:
	cmp r4, #2
	beq _08024300
	b _08024320
_080242EA:
	bl Rfu_SetLinkStandbyCallback
	b _08024320
_080242F0:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08024326
	bl SetCloseLinkCallback
	b _08024320
_08024300:
	ldr r0, _0802431C
	ldrb r0, [r0]
	cmp r0, #0
	bne _08024326
	movs r0, #0x19
	strb r0, [r5, #0xe]
	movs r0, #5
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _08024326
	.align 2, 0
_0802431C: .4byte 0x030031C4
_08024320:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_08024326:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080242D0

	thumb_func_start sub_08024330
sub_08024330: @ 0x08024330
	push {lr}
	movs r0, #0
	bl sub_08020924
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08024330

	thumb_func_start sub_08024340
sub_08024340: @ 0x08024340
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r0, #0x33
	bl IncrementGameStat
	strb r5, [r4, #0xd]
	movs r1, #0
	strh r5, [r4, #0x10]
	movs r0, #2
	strh r0, [r4, #0x12]
	strh r5, [r4, #0x14]
	str r5, [r4, #0x1c]
	strh r5, [r4, #0x18]
	strh r5, [r4, #0x1a]
	str r5, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0
	strb r0, [r1]
	strh r5, [r4, #0x26]
	strh r5, [r4, #0x28]
	strh r5, [r4, #0x2e]
	ldr r0, _080243CC
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x30]
	strh r5, [r4, #0x34]
	movs r6, #0
	movs r3, #0
_08024380:
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r1, r2, #0
	adds r1, #0xa0
	ldr r0, _080243CC
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xa2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r1, #6
	movs r0, #1
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xa8
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _08024380
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080243CC: .4byte 0x0000FFFF
	thumb_func_end sub_08024340

	thumb_func_start sub_080243D0
sub_080243D0: @ 0x080243D0
	push {r4, r5, r6, lr}
	sub sp, #8
	str r2, [sp, #4]
	ldr r5, [sp, #0x18]
	ldr r6, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	mov r2, sp
	strh r4, [r2]
	add r4, sp, #4
	ldrb r2, [r4]
	strb r2, [r0]
	ldrb r2, [r4, #1]
	strb r2, [r0, #1]
	ldrb r2, [r4, #2]
	strb r2, [r0, #2]
	ldrb r2, [r4, #3]
	strb r2, [r0, #3]
	strb r3, [r0, #4]
	strb r5, [r0, #5]
	strb r6, [r0, #6]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0, #7]
	mov r2, sp
	ldrb r2, [r2, #1]
	strb r2, [r0, #8]
	strb r1, [r0, #9]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080243D0

	thumb_func_start sub_08024410
sub_08024410: @ 0x08024410
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, [sp, #0x10]
	mov r4, sp
	strh r3, [r4]
	strb r1, [r0]
	strb r2, [r0, #1]
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0, #2]
	mov r1, sp
	ldrb r1, [r1, #1]
	strb r1, [r0, #3]
	strb r5, [r0, #4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08024410
