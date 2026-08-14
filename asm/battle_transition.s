.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start CreatePhase1Task
CreatePhase1Task: @ 0x08149E38
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r3, [sp, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, _08149E94
	movs r1, #3
	str r3, [sp]
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08149E98
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	mov r0, r8
	strh r0, [r1, #0xa]
	strh r4, [r1, #0xc]
	strh r5, [r1, #0xe]
	strh r6, [r1, #0x10]
	ldr r3, [sp]
	strh r3, [r1, #0x12]
	strh r0, [r1, #0x14]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08149E94: .4byte 0x08149EBD
_08149E98: .4byte 0x03005B60
	thumb_func_end CreatePhase1Task

	thumb_func_start IsPhase1Done
IsPhase1Done: @ 0x08149E9C
	push {lr}
	ldr r0, _08149EB0
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _08149EB4
	movs r0, #0
	b _08149EB6
	.align 2, 0
_08149EB0: .4byte 0x08149EBD
_08149EB4:
	movs r0, #1
_08149EB6:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsPhase1Done

	thumb_func_start Phase2Task_Magma
Phase2Task_Magma: @ 0x08149EBC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _08149EEC
	ldr r2, _08149EF0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
_08149ECE:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08149ECE
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08149EEC: .4byte 0x085A88D4
_08149EF0: .4byte 0x03005B60
	thumb_func_end Phase2Task_Magma

	thumb_func_start Phase1_TransitionAll_Func1
Phase1_TransitionAll_Func1: @ 0x08149EF4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x14]
	movs r2, #0x14
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _08149F0C
	subs r0, r1, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08149F30
_08149F0C:
	ldrh r0, [r4, #0xa]
	strh r0, [r4, #0x14]
	ldrh r0, [r4, #0x10]
	ldrh r1, [r4, #0x16]
	adds r0, r0, r1
	strh r0, [r4, #0x16]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble _08149F24
	movs r0, #0x10
	strh r0, [r4, #0x16]
_08149F24:
	movs r0, #1
	rsbs r0, r0, #0
	ldrb r1, [r4, #0x16]
	ldr r2, _08149F4C
	bl BlendPalettes
_08149F30:
	movs r2, #0x16
	ldrsh r0, [r4, r2]
	cmp r0, #0xf
	ble _08149F42
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	strh r0, [r4, #0x14]
_08149F42:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08149F4C: .4byte 0x00002D6B
	thumb_func_end Phase1_TransitionAll_Func1

	thumb_func_start Phase1_TransitionAll_Func2
Phase1_TransitionAll_Func2: @ 0x08149F50
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x14]
	movs r2, #0x14
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _08149F68
	subs r0, r1, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08149F8A
_08149F68:
	ldrh r0, [r4, #0xc]
	strh r0, [r4, #0x14]
	ldrh r0, [r4, #0x16]
	ldrh r1, [r4, #0x12]
	subs r0, r0, r1
	strh r0, [r4, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08149F7E
	movs r0, #0
	strh r0, [r4, #0x16]
_08149F7E:
	movs r0, #1
	rsbs r0, r0, #0
	ldrb r1, [r4, #0x16]
	ldr r2, _08149FB0
	bl BlendPalettes
_08149F8A:
	movs r0, #0x16
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bne _08149FBE
	ldrh r0, [r4, #0xe]
	subs r0, #1
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08149FB8
	ldr r0, _08149FB4
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl DestroyTask
	b _08149FBE
	.align 2, 0
_08149FB0: .4byte 0x00002D6B
_08149FB4: .4byte 0x08149EBD
_08149FB8:
	ldrh r0, [r4, #0xa]
	strh r0, [r4, #0x14]
	strh r1, [r4, #8]
_08149FBE:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end Phase1_TransitionAll_Func2

	thumb_func_start sub_08149FC8
sub_08149FC8: @ 0x08149FC8
	push {r4, lr}
	ldr r4, _08149FE8
	ldr r0, [r4]
	movs r1, #0
	movs r2, #0x3c
	bl memset
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x14
	adds r1, #0x16
	bl GetCameraOffsetWithPan
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08149FE8: .4byte 0x0203A86C
	thumb_func_end sub_08149FC8

	thumb_func_start VBlankCB_BattleTransition
VBlankCB_BattleTransition: @ 0x08149FEC
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end VBlankCB_BattleTransition

	thumb_func_start sub_0814A000
sub_0814A000: @ 0x0814A000
	ldr r1, _0814A014
	ldrh r1, [r1]
	lsrs r1, r1, #2
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x10
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_0814A014: .4byte 0x04000008
	thumb_func_end sub_0814A000

	thumb_func_start sub_0814A018
sub_0814A018: @ 0x0814A018
	push {r4, lr}
	ldr r3, _0814A040
	ldrh r2, [r3]
	lsrs r2, r2, #8
	ldrh r3, [r3]
	lsrs r3, r3, #2
	lsls r2, r2, #0x1b
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x10
	movs r4, #0xc0
	lsls r4, r4, #0x13
	adds r2, r2, r4
	str r2, [r0]
	adds r3, r3, r4
	str r3, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814A040: .4byte 0x04000008
	thumb_func_end sub_0814A018

	thumb_func_start sub_0814A044
sub_0814A044: @ 0x0814A044
	push {lr}
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0x10
	movs r2, #0
	bl BlendPalettes
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0814A044

	thumb_func_start sub_0814A058
sub_0814A058: @ 0x0814A058
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	ldr r0, [sp, #0x20]
	ldr r4, [sp, #0x24]
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	lsls r4, r4, #0x10
	movs r6, #0
	lsrs r5, r4, #0x10
	cmp r4, #0
	ble _0814A0C0
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	mov sb, r0
	lsls r1, r1, #0x10
	mov r8, r1
	lsls r0, r3, #0x10
	asrs r7, r0, #0x10
_0814A090:
	lsls r4, r2, #0x10
	asrs r4, r4, #0x10
	movs r0, #0xff
	ands r0, r4
	mov r2, r8
	asrs r1, r2, #0x10
	bl Sin
	lsls r1, r6, #1
	add r1, sl
	add r0, sb
	strh r0, [r1]
	lsls r1, r5, #0x10
	ldr r0, _0814A0D0
	adds r1, r1, r0
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r4, r4, r7
	lsls r4, r4, #0x10
	lsrs r2, r4, #0x10
	lsrs r5, r1, #0x10
	cmp r1, #0
	bgt _0814A090
_0814A0C0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814A0D0: .4byte 0xFFFF0000
	thumb_func_end sub_0814A058

	thumb_func_start sub_0814A0D4
sub_0814A0D4: @ 0x0814A0D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	adds r5, r2, #0
	adds r4, r3, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r1, #0xa
	bl memset
	movs r1, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	str r4, [sp, #4]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	str r5, [sp, #8]
_0814A10C:
	lsls r5, r1, #0x10
	asrs r0, r5, #0x10
	mov sl, r0
	ldr r1, [sp, #4]
	bl Sin
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, sl
	ldr r1, [sp, #4]
	bl Cos
	ldr r2, [sp]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	subs r2, r1, r4
	lsls r2, r2, #0x10
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r3, [sp, #8]
	subs r1, r3, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsrs r1, r2, #0x10
	str r5, [sp, #0x10]
	cmp r2, #0
	bge _0814A158
	movs r1, #0
_0814A158:
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf0
	ble _0814A162
	movs r6, #0xf0
_0814A162:
	lsls r0, r7, #0x10
	cmp r0, #0
	bge _0814A16A
	movs r7, #0
_0814A16A:
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble _0814A178
	movs r3, #0x9f
	mov r8, r3
_0814A178:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x10
	orrs r6, r0
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0xc]
	lsls r0, r0, #1
	add r0, sb
	strh r6, [r0]
	mov r0, r8
	lsls r4, r0, #0x10
	asrs r0, r4, #0xf
	add r0, sb
	strh r6, [r0]
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [sp, #4]
	bl Cos
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r2, [sp, #8]
	subs r1, r2, r0
	lsls r1, r1, #0x10
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsrs r3, r1, #0x10
	cmp r1, #0
	bge _0814A1BA
	movs r3, #0
_0814A1BA:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x9f
	ble _0814A1C4
	movs r2, #0x9f
_0814A1C4:
	lsls r0, r3, #0x10
	asrs r1, r0, #0x10
	adds r3, r0, #0
	lsls r5, r2, #0x10
	ldr r0, [sp, #0xc]
	cmp r0, r1
	ble _0814A1E8
	adds r2, r1, #0
_0814A1D4:
	lsls r1, r7, #0x10
	ldr r0, _0814A268
	adds r1, r1, r0
	asrs r0, r1, #0xf
	add r0, sb
	strh r6, [r0]
	lsrs r7, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, r2
	bgt _0814A1D4
_0814A1E8:
	lsls r1, r7, #0x10
	asrs r0, r3, #0x10
	cmp r1, r3
	bge _0814A206
	adds r2, r0, #0
_0814A1F2:
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r1, r3
	asrs r1, r0, #0xf
	add r1, sb
	strh r6, [r1]
	adds r1, r0, #0
	asrs r0, r1, #0x10
	cmp r0, r2
	blt _0814A1F2
_0814A206:
	asrs r0, r5, #0x10
	cmp r4, r5
	ble _0814A224
	adds r1, r0, #0
_0814A20E:
	ldr r2, _0814A268
	adds r0, r4, r2
	lsrs r3, r0, #0x10
	mov r8, r3
	asrs r0, r0, #0xf
	add r0, sb
	strh r6, [r0]
	lsls r4, r3, #0x10
	asrs r0, r4, #0x10
	cmp r0, r1
	bgt _0814A20E
_0814A224:
	mov r0, r8
	lsls r4, r0, #0x10
	asrs r0, r5, #0x10
	cmp r4, r5
	bge _0814A244
	adds r2, r0, #0
_0814A230:
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, r1
	asrs r1, r0, #0xf
	add r1, sb
	strh r6, [r1]
	adds r4, r0, #0
	asrs r0, r4, #0x10
	cmp r0, r2
	blt _0814A230
_0814A244:
	ldr r2, [sp, #0x10]
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r2, r3
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	bgt _0814A256
	b _0814A10C
_0814A256:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814A268: .4byte 0xFFFF0000
	thumb_func_end sub_0814A0D4

	thumb_func_start sub_0814A26C
sub_0814A26C: @ 0x0814A26C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [sp, #0x14]
	ldr r5, [sp, #0x18]
	ldr r4, [sp, #0x1c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r7, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	strh r1, [r6]
	strh r2, [r6, #2]
	strh r1, [r6, #4]
	strh r2, [r6, #6]
	strh r3, [r6, #8]
	strh r7, [r6, #0xa]
	strh r5, [r6, #0xc]
	strh r4, [r6, #0xe]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	subs r3, r3, r1
	strh r3, [r6, #0x10]
	lsls r0, r3, #0x10
	cmp r0, #0
	bge _0814A2BE
	rsbs r0, r3, #0
	strh r0, [r6, #0x10]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	strh r0, [r6, #0xc]
_0814A2BE:
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	subs r1, r0, r1
	strh r1, [r6, #0x12]
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _0814A2DC
	rsbs r0, r1, #0
	strh r0, [r6, #0x12]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
	strh r0, [r6, #0xe]
_0814A2DC:
	movs r0, #0
	strh r0, [r6, #0x14]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0814A26C

	thumb_func_start sub_0814A2E8
sub_0814A2E8: @ 0x0814A2E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sl, r2
	ldrh r0, [r3, #0x10]
	mov r8, r0
	movs r1, #0x10
	ldrsh r6, [r3, r1]
	ldrh r2, [r3, #0x12]
	mov ip, r2
	movs r4, #0x12
	ldrsh r5, [r3, r4]
	cmp r6, r5
	ble _0814A338
	ldrh r0, [r3, #0xc]
	ldrh r2, [r3, #4]
	adds r1, r0, r2
	strh r1, [r3, #4]
	ldrh r2, [r3, #0x14]
	add r2, ip
	strh r2, [r3, #0x14]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	adds r4, r0, #0
	ldrh r7, [r3, #0xe]
	cmp r1, r6
	ble _0814A35E
	ldrh r1, [r3, #6]
	adds r0, r7, r1
	strh r0, [r3, #6]
	mov r1, r8
	b _0814A35A
_0814A338:
	ldrh r0, [r3, #0xe]
	ldrh r2, [r3, #6]
	adds r1, r0, r2
	strh r1, [r3, #6]
	ldrh r2, [r3, #0x14]
	add r2, r8
	strh r2, [r3, #0x14]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldrh r4, [r3, #0xc]
	adds r7, r0, #0
	cmp r1, r5
	ble _0814A35E
	ldrh r1, [r3, #4]
	adds r0, r4, r1
	strh r0, [r3, #4]
	mov r1, ip
_0814A35A:
	subs r0, r2, r1
	strh r0, [r3, #0x14]
_0814A35E:
	movs r5, #0
	lsls r0, r4, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	ble _0814A376
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r4, #8
	ldrsh r0, [r3, r4]
	ldrh r4, [r3, #8]
	cmp r1, r0
	bge _0814A388
_0814A376:
	cmp r2, #0
	bge _0814A396
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #8
	ldrsh r0, [r3, r2]
	ldrh r4, [r3, #8]
	cmp r1, r0
	bgt _0814A396
_0814A388:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r0, sb
	cmp r0, #0
	beq _0814A396
	strh r4, [r3, #4]
_0814A396:
	lsls r0, r7, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	ble _0814A3AC
	movs r4, #6
	ldrsh r1, [r3, r4]
	movs r4, #0xa
	ldrsh r0, [r3, r4]
	ldrh r4, [r3, #0xa]
	cmp r1, r0
	bge _0814A3BE
_0814A3AC:
	cmp r2, #0
	bge _0814A3CC
	movs r0, #6
	ldrsh r1, [r3, r0]
	movs r2, #0xa
	ldrsh r0, [r3, r2]
	ldrh r4, [r3, #0xa]
	cmp r1, r0
	bgt _0814A3CC
_0814A3BE:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r0, sl
	cmp r0, #0
	beq _0814A3CC
	strh r4, [r3, #6]
_0814A3CC:
	cmp r5, #2
	beq _0814A3D4
	movs r0, #0
	b _0814A3D6
_0814A3D4:
	movs r0, #1
_0814A3D6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_0814A2E8

	thumb_func_start Phase2_29_Func1
Phase2_29_Func1: @ 0x0814A3E4
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl sub_0814675C
	add r0, sp, #4
	add r1, sp, #8
	bl sub_0814A018
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, [sp, #4]
	ldr r2, _0814A428
	mov r0, sp
	bl CpuSet
	ldr r0, _0814A42C
	ldr r1, [sp, #8]
	bl LZ77UnCompVram
	ldr r0, _0814A430
	movs r1, #0xf0
	movs r2, #0x20
	bl LoadPalette
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	movs r0, #0
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814A428: .4byte 0x01000400
_0814A42C: .4byte 0x085A76B0
_0814A430: .4byte 0x085A7690
	thumb_func_end Phase2_29_Func1

	thumb_func_start Phase2_29_Func2
Phase2_29_Func2: @ 0x0814A434
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	add r1, sp, #0xc
	add r0, sp, #8
	bl sub_0814A018
	ldr r0, _0814A474
	ldr r1, [sp, #8]
	bl LZ77UnCompVram
	ldr r0, _0814A478
	movs r1, #0x10
	ldrsh r2, [r4, r1]
	movs r3, #0x12
	ldrsh r1, [r4, r3]
	str r1, [sp]
	movs r1, #0xa0
	str r1, [sp, #4]
	movs r1, #0
	movs r3, #0x84
	bl sub_0814A058
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	movs r0, #1
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814A474: .4byte 0x085A7D3C
_0814A478: .4byte 0x020388C8
	thumb_func_end Phase2_29_Func2

	thumb_func_start Phase2Task_Swirl
Phase2Task_Swirl: @ 0x0814A47C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0814A4AC
	ldr r2, _0814A4B0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
_0814A48E:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814A48E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814A4AC: .4byte 0x085A9480
_0814A4B0: .4byte 0x03005B60
	thumb_func_end Phase2Task_Swirl

	thumb_func_start Phase2Task_Wave
Phase2Task_Wave: @ 0x0814A4B4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0814A4E4
	ldr r2, _0814A4E8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
_0814A4C6:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814A4C6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814A4E4: .4byte 0x085A9498
_0814A4E8: .4byte 0x03005B60
	thumb_func_end Phase2Task_Wave

	thumb_func_start Phase2_30_Func1
Phase2_30_Func1: @ 0x0814A4EC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl sub_08149FC8
	bl ScanlineEffect_Clear
	movs r1, #0xc0
	lsls r1, r1, #7
	movs r0, #0
	bl ClearGpuRegBits
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #6
	strh r0, [r4, #0xc]
	ldr r0, _0814A574
	strh r0, [r4, #0xa]
	strh r5, [r4, #0x12]
	movs r0, #0x10
	strh r0, [r4, #0x14]
	movs r0, #0xa0
	lsls r0, r0, #4
	strh r0, [r4, #0x16]
	ldr r6, _0814A578
	ldr r2, [r6]
	ldr r3, _0814A57C
	strh r3, [r2, #0xe]
	ldrh r0, [r4, #0x14]
	lsls r0, r0, #8
	ldrh r1, [r4, #0x12]
	orrs r0, r1
	strh r0, [r2, #0x10]
	ldr r0, _0814A580
	strh r3, [r0]
	ldr r1, _0814A584
	ldrh r0, [r2, #0x10]
	strh r0, [r1]
	add r0, sp, #4
	add r1, sp, #8
	bl sub_0814A018
	mov r0, sp
	strh r5, [r0]
	ldr r1, [sp, #4]
	ldr r2, _0814A588
	bl CpuSet
	ldr r0, _0814A58C
	ldr r1, [sp, #8]
	bl LZ77UnCompVram
	ldr r0, _0814A590
	movs r1, #0xf0
	movs r2, #0x20
	bl LoadPalette
	ldr r0, [r6]
	strh r5, [r0, #0x16]
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0814A574: .4byte 0x00007FFF
_0814A578: .4byte 0x0203A86C
_0814A57C: .4byte 0x00003F41
_0814A580: .4byte 0x04000050
_0814A584: .4byte 0x04000052
_0814A588: .4byte 0x01000400
_0814A58C: .4byte 0x085A76B0
_0814A590: .4byte 0x085A7690
	thumb_func_end Phase2_30_Func1

	thumb_func_start Phase2_30_Func2
Phase2_30_Func2: @ 0x0814A594
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	add r1, sp, #4
	mov r0, sp
	bl sub_0814A018
	ldr r0, _0814A5BC
	ldr r1, [sp]
	bl LZ77UnCompVram
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	movs r0, #1
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814A5BC: .4byte 0x085A7D3C
	thumb_func_end Phase2_30_Func2

	thumb_func_start Phase2_30_Func3
Phase2_30_Func3: @ 0x0814A5C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r2, #0
	ldr r6, _0814A600
	ldr r4, _0814A604
	ldr r3, _0814A608
_0814A5CC:
	lsls r1, r2, #1
	adds r1, r1, r4
	ldr r0, [r3]
	ldrh r0, [r0, #0x16]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x9f
	bls _0814A5CC
	adds r0, r6, #0
	bl SetVBlankCallback
	ldr r0, _0814A60C
	bl SetHBlankCallback
	movs r0, #2
	bl EnableInterrupts
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	movs r0, #1
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0814A600: .4byte 0x0814A745
_0814A604: .4byte 0x02039048
_0814A608: .4byte 0x0203A86C
_0814A60C: .4byte 0x0814A78D
	thumb_func_end Phase2_30_Func3

	thumb_func_start Phase2_30_Func4
Phase2_30_Func4: @ 0x0814A610
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _0814A658
	ldr r0, [r1]
	ldrb r2, [r0]
	movs r3, #0
	strb r3, [r0]
	ldrh r2, [r4, #0xc]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrh r6, [r4, #0xa]
	movs r0, #0xc0
	lsls r0, r0, #1
	mov r8, r0
	ldrh r0, [r4, #0x16]
	subs r0, r6, r0
	strh r0, [r4, #0xa]
	movs r5, #0xe
	ldrsh r0, [r4, r5]
	adds r5, r1, #0
	cmp r0, #0x45
	ble _0814A662
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	ldr r1, _0814A65C
	adds r0, r0, r1
	cmp r0, #0
	blt _0814A660
	adds r0, r2, r1
	strh r0, [r4, #0xc]
	b _0814A662
	.align 2, 0
_0814A658: .4byte 0x0203A86C
_0814A65C: .4byte 0xFFFFFE80
_0814A660:
	strh r3, [r4, #0xc]
_0814A662:
	movs r2, #0xe
	ldrsh r0, [r4, r2]
	cmp r0, #0
	blt _0814A6A0
	movs r1, #3
	bl __modsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0814A6A0
	ldrh r1, [r4, #0x12]
	movs r2, #0x12
	ldrsh r0, [r4, r2]
	cmp r0, #0xf
	bgt _0814A686
	adds r0, r1, #1
	strh r0, [r4, #0x12]
	b _0814A694
_0814A686:
	ldrh r1, [r4, #0x14]
	movs r2, #0x14
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _0814A694
	subs r0, r1, #1
	strh r0, [r4, #0x14]
_0814A694:
	ldr r0, [r5]
	ldrh r1, [r4, #0x14]
	lsls r1, r1, #8
	ldrh r2, [r4, #0x12]
	orrs r1, r2
	strh r1, [r0, #0x10]
_0814A6A0:
	movs r5, #0
	lsls r7, r7, #0x10
_0814A6A4:
	lsrs r0, r6, #8
	asrs r1, r7, #0x10
	bl Sin
	ldr r1, _0814A734
	lsls r2, r5, #1
	adds r2, r2, r1
	ldr r1, _0814A738
	ldr r1, [r1]
	ldrh r1, [r1, #0x16]
	adds r0, r0, r1
	strh r0, [r2]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r1, r8
	adds r0, r6, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r5, #0x9f
	bls _0814A6A4
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x65
	bne _0814A6F2
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
_0814A6F2:
	movs r2, #0x10
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _0814A714
	ldr r0, _0814A73C
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0814A714
	ldr r0, _0814A740
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl DestroyTask
_0814A714:
	ldrh r0, [r4, #0x16]
	subs r0, #0x11
	strh r0, [r4, #0x16]
	ldr r0, _0814A738
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, #1
	ldrb r2, [r1]
	strb r0, [r1]
	movs r0, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0814A734: .4byte 0x020388C8
_0814A738: .4byte 0x0203A86C
_0814A73C: .4byte 0x02037C74
_0814A740: .4byte 0x0814A4B5
	thumb_func_end Phase2_30_Func4

	thumb_func_start VBlankCB_Phase2_30
VBlankCB_Phase2_30: @ 0x0814A744
	push {lr}
	bl VBlankCB_BattleTransition
	ldr r2, _0814A778
	ldr r0, _0814A77C
	ldr r1, [r0]
	ldrh r0, [r1, #0xe]
	strh r0, [r2]
	adds r2, #2
	ldrh r0, [r1, #0x10]
	strh r0, [r2]
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814A774
	ldr r1, _0814A780
	ldr r0, _0814A784
	str r0, [r1]
	movs r2, #0xf0
	lsls r2, r2, #3
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _0814A788
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_0814A774:
	pop {r0}
	bx r0
	.align 2, 0
_0814A778: .4byte 0x04000050
_0814A77C: .4byte 0x0203A86C
_0814A780: .4byte 0x040000D4
_0814A784: .4byte 0x020388C8
_0814A788: .4byte 0x800000A0
	thumb_func_end VBlankCB_Phase2_30

	thumb_func_start HBlankCB_Phase2_30
HBlankCB_Phase2_30: @ 0x0814A78C
	ldr r1, _0814A7A4
	ldr r0, _0814A7A8
	ldrh r0, [r0]
	lsls r0, r0, #1
	movs r2, #0xf0
	lsls r2, r2, #3
	adds r1, r1, r2
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _0814A7AC
	strh r1, [r0]
	bx lr
	.align 2, 0
_0814A7A4: .4byte 0x020388C8
_0814A7A8: .4byte 0x04000006
_0814A7AC: .4byte 0x04000012
	thumb_func_end HBlankCB_Phase2_30

	thumb_func_start Phase2Task_WhiteFade
Phase2Task_WhiteFade: @ 0x0814A7B0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0814A7E0
	ldr r2, _0814A7E4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
_0814A7C2:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814A7C2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814A7E0: .4byte 0x085A94A8
_0814A7E4: .4byte 0x03005B60
	thumb_func_end Phase2Task_WhiteFade

	thumb_func_start Task_BattleTransitionMain
Task_BattleTransitionMain: @ 0x0814A7E8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0814A818
	ldr r2, _0814A81C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
_0814A7FA:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814A7FA
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814A818: .4byte 0x085A94B8
_0814A81C: .4byte 0x03005B60
	thumb_func_end Task_BattleTransitionMain

	thumb_func_start TransitionPhase1_Task_RunFuncs
TransitionPhase1_Task_RunFuncs: @ 0x0814A820
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0814A850
	ldr r2, _0814A854
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
_0814A832:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814A832
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814A850: .4byte 0x085A94CC
_0814A854: .4byte 0x03005B60
	thumb_func_end TransitionPhase1_Task_RunFuncs

	thumb_func_start Phase2_31_Func1
Phase2_31_Func1: @ 0x0814A858
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x14
	mov r8, r0
	add r1, sp, #0x10
	add r0, sp, #0xc
	bl sub_0814A018
	ldr r0, _0814A8E0
	ldr r1, [sp, #0x10]
	bl LZ77UnCompVram
	movs r4, #0x20
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r6, #1
	str r6, [sp]
	str r4, [sp, #4]
	movs r5, #0xf
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #1
	movs r2, #0x1d
	movs r3, #0
	bl FillBgTilemapBufferRect
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _0814A8E4
	movs r1, #0xf0
	movs r2, #0x20
	bl LoadPalette
	movs r0, #0
	mov r1, r8
	strh r6, [r1, #0xc]
	strh r0, [r1, #0xe]
	strh r0, [r1, #0x10]
	movs r0, #0xa
	strh r0, [r1, #0x16]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	movs r0, #0
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0814A8E0: .4byte 0x085A8048
_0814A8E4: .4byte 0x085A8028
	thumb_func_end Phase2_31_Func1

	thumb_func_start Phase2_31_Func2
Phase2_31_Func2: @ 0x0814A8E8
	push {r4, r5, lr}
	sub sp, #0x24
	adds r4, r0, #0
	ldr r1, _0814A954
	movs r2, #4
	str r2, [sp]
	str r2, [sp, #4]
	ldrb r0, [r4, #0xc]
	str r0, [sp, #8]
	ldrb r0, [r4, #0xe]
	str r0, [sp, #0xc]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r5, #0
	str r5, [sp, #0x1c]
	str r5, [sp, #0x20]
	movs r0, #0
	movs r2, #0
	movs r3, #0
	bl CopyRectToBgTilemapBufferRect
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, #0xc]
	adds r0, #4
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	bne _0814A94A
	movs r0, #1
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	adds r0, #4
	strh r0, [r4, #0xe]
	strh r5, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	ble _0814A94A
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
_0814A94A:
	movs r0, #0
	add sp, #0x24
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0814A954: .4byte 0x085A83D8
	thumb_func_end Phase2_31_Func2

	thumb_func_start Phase2_31_Func3
Phase2_31_Func3: @ 0x0814A958
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r4, r0, #0
	add r1, sp, #0xc
	add r0, sp, #8
	bl sub_0814A018
	ldrh r0, [r4, #0x14]
	adds r1, r0, #1
	strh r1, [r4, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x16
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _0814AA16
	movs r1, #0x12
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _0814A9BC
	cmp r0, #1
	bgt _0814A98A
	cmp r0, #0
	beq _0814A994
	b _0814A9EC
_0814A98A:
	cmp r0, #2
	beq _0814A9D4
	cmp r0, #3
	beq _0814A9DC
	b _0814A9EC
_0814A994:
	movs r2, #0xfa
	ldr r6, _0814A9B4
	movs r3, #0
	ldr r5, _0814A9B8
_0814A99C:
	lsls r1, r2, #1
	adds r0, r1, r6
	strh r3, [r0]
	adds r1, r1, r5
	strh r3, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xfe
	bls _0814A99C
	b _0814AA0C
	.align 2, 0
_0814A9B4: .4byte 0x020373B4
_0814A9B8: .4byte 0x020377B4
_0814A9BC:
	ldr r0, _0814A9CC
	movs r1, #0x10
	movs r2, #0
	bl BlendPalettes
	ldr r0, _0814A9D0
	b _0814A9DE
	.align 2, 0
_0814A9CC: .4byte 0xFFFF7FFF
_0814A9D0: .4byte 0x085A81A4
_0814A9D4:
	ldr r0, _0814A9D8
	b _0814A9DE
	.align 2, 0
_0814A9D8: .4byte 0x085A82A4
_0814A9DC:
	ldr r0, _0814A9E8
_0814A9DE:
	ldr r1, [sp, #0xc]
	bl LZ77UnCompVram
	b _0814AA0C
	.align 2, 0
_0814A9E8: .4byte 0x085A8354
_0814A9EC:
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0814AA16
_0814AA0C:
	movs r0, #0
	strh r0, [r4, #0x14]
	ldrh r0, [r4, #0x12]
	adds r0, #1
	strh r0, [r4, #0x12]
_0814AA16:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end Phase2_31_Func3

	thumb_func_start Phase2_33_Func1
Phase2_33_Func1: @ 0x0814AA20
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x14
	mov r8, r0
	add r1, sp, #0x10
	add r0, sp, #0xc
	bl sub_0814A018
	ldr r0, _0814AABC
	ldr r1, [sp, #0x10]
	bl LZ77UnCompVram
	movs r4, #0x20
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r6, #1
	str r6, [sp]
	str r4, [sp, #4]
	movs r5, #0xf
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect
	str r6, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #1
	movs r2, #0x1d
	movs r3, #0
	bl FillBgTilemapBufferRect
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r4, _0814AAC0
	adds r0, r4, #0
	movs r1, #0xe0
	movs r2, #0x20
	bl LoadPalette
	adds r0, r4, #0
	movs r1, #0xf0
	movs r2, #0x20
	bl LoadPalette
	movs r0, #0xe0
	movs r1, #0x10
	movs r2, #8
	movs r3, #0
	bl BlendPalette
	movs r1, #0
	movs r0, #0x22
	mov r2, r8
	strh r0, [r2, #0xc]
	strh r1, [r2, #0xe]
	ldrh r0, [r2, #8]
	adds r0, #1
	strh r0, [r2, #8]
	movs r0, #0
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0814AABC: .4byte 0x085A8048
_0814AAC0: .4byte 0x085A8028
	thumb_func_end Phase2_33_Func1

	thumb_func_start Phase2_33_Func2
Phase2_33_Func2: @ 0x0814AAC4
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r1, _0814AB3C
	movs r2, #0xc
	ldrsh r0, [r6, r2]
	adds r0, r0, r1
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #7
	bl __umodsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #7
	bl __udivsi3
	ldr r1, _0814AB40
	movs r2, #4
	str r2, [sp]
	str r2, [sp, #4]
	lsls r4, r4, #2
	adds r4, #1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #8]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	movs r2, #0
	movs r3, #0
	bl CopyRectToBgTilemapBufferRect
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r6, #0xc]
	subs r0, #1
	strh r0, [r6, #0xc]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0814AB30
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
_0814AB30:
	movs r0, #0
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0814AB3C: .4byte 0x085A94E0
_0814AB40: .4byte 0x085A83D8
	thumb_func_end Phase2_33_Func2

	thumb_func_start Phase2_33_Func3
Phase2_33_Func3: @ 0x0814AB44
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	movs r1, #0x10
	movs r2, #3
	movs r3, #0
	bl BlendPalette
	ldr r0, _0814AB74
	movs r1, #0x10
	movs r2, #0
	bl BlendPalettes
	movs r0, #0
	strh r0, [r4, #0xc]
	strh r0, [r4, #0xe]
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814AB74: .4byte 0xFFFF3FFF
	thumb_func_end Phase2_33_Func3

	thumb_func_start Phase2_33_Func4
Phase2_33_Func4: @ 0x0814AB78
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldrh r0, [r7, #0xe]
	movs r1, #1
	eors r0, r1
	movs r6, #0
	strh r0, [r7, #0xe]
	cmp r0, #0
	beq _0814ABEC
	ldr r0, _0814ABE4
	mov r8, r0
	movs r4, #4
	str r4, [sp]
	str r4, [sp, #4]
	ldr r5, _0814ABE8
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	adds r0, r0, r5
	ldrb r0, [r0]
	movs r1, #7
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	movs r2, #0xc
	ldrsh r0, [r7, r2]
	adds r0, r0, r5
	ldrb r0, [r0]
	movs r1, #7
	bl __udivsi3
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #0xe
	str r0, [sp, #0x18]
	str r6, [sp, #0x1c]
	str r6, [sp, #0x20]
	movs r0, #0
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl CopyRectToBgTilemapBufferRect
	b _0814AC38
	.align 2, 0
_0814ABE4: .4byte 0x085A83D8
_0814ABE8: .4byte 0x085A94E0
_0814ABEC:
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	cmp r0, #0
	ble _0814AC32
	ldr r1, _0814AC5C
	subs r0, #1
	adds r0, r0, r1
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #7
	bl __umodsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x16
	adds r4, #1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #7
	bl __udivsi3
	adds r3, r0, #0
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x18
	movs r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl FillBgTilemapBufferRect
_0814AC32:
	ldrh r0, [r7, #0xc]
	adds r0, #1
	strh r0, [r7, #0xc]
_0814AC38:
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	cmp r0, #0x22
	ble _0814AC46
	ldrh r0, [r7, #8]
	adds r0, #1
	strh r0, [r7, #8]
_0814AC46:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #0
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0814AC5C: .4byte 0x085A94E0
	thumb_func_end Phase2_33_Func4

	thumb_func_start Phase2_31_33_Func5
Phase2_31_33_Func5: @ 0x0814AC60
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0x10
	movs r2, #0
	bl BlendPalettes
	ldr r0, [r4]
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl DestroyTask
	movs r0, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end Phase2_31_33_Func5

	thumb_func_start sub_0814ACA4
sub_0814ACA4: @ 0x0814ACA4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0814ACEC
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r6, r1, r2
	ldrh r0, [r6, #0xc]
	movs r1, #1
	eors r0, r1
	strh r0, [r6, #0xc]
	cmp r0, #0
	bne _0814ACE4
	ldr r5, _0814ACF0
	ldrh r1, [r5]
	movs r0, #0x12
	bl SetGpuReg
	ldr r4, _0814ACF4
	ldrh r1, [r4]
	movs r0, #0x10
	bl SetGpuReg
	ldrh r0, [r6, #8]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #0xa]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
_0814ACE4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814ACEC: .4byte 0x03005B60
_0814ACF0: .4byte 0x02022AC8
_0814ACF4: .4byte 0x02022ACA
	thumb_func_end sub_0814ACA4

	thumb_func_start Phase2_32_Func1
Phase2_32_Func1: @ 0x0814ACF8
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r5, #0
	add r1, sp, #0xc
	add r0, sp, #8
	bl sub_0814A018
	ldr r0, _0814AD74
	ldr r1, [sp, #0xc]
	bl LZ77UnCompVram
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _0814AD78
	movs r1, #0xf0
	movs r2, #0x20
	bl LoadPalette
	ldr r0, _0814AD7C
	strh r5, [r0]
	ldr r4, _0814AD80
	strh r5, [r4]
	movs r0, #0x12
	movs r1, #0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, #0x10
	bl SetGpuReg
	strh r5, [r6, #0xc]
	ldr r0, _0814AD84
	movs r1, #1
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl Random
	lsls r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r0
	lsrs r1, r1, #0x10
	cmp r1, #1
	beq _0814ADA4
	cmp r1, #1
	bgt _0814AD88
	cmp r1, #0
	beq _0814AD8E
	b _0814ADDC
	.align 2, 0
_0814AD74: .4byte 0x085A8048
_0814AD78: .4byte 0x085A8028
_0814AD7C: .4byte 0x02022AC8
_0814AD80: .4byte 0x02022ACA
_0814AD84: .4byte 0x0814ACA5
_0814AD88:
	cmp r1, #2
	beq _0814ADC0
	b _0814ADDC
_0814AD8E:
	ldr r0, _0814ADA0
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r0, #1
	strh r0, [r1, #8]
	strh r0, [r1, #0xa]
	b _0814ADEE
	.align 2, 0
_0814ADA0: .4byte 0x03005B60
_0814ADA4:
	ldr r1, _0814ADB8
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _0814ADBC
	strh r1, [r0, #8]
	movs r1, #1
	rsbs r1, r1, #0
	b _0814ADEC
	.align 2, 0
_0814ADB8: .4byte 0x03005B60
_0814ADBC: .4byte 0x0000FFFF
_0814ADC0:
	ldr r1, _0814ADD4
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0, #8]
	ldr r1, _0814ADD8
	b _0814ADEC
	.align 2, 0
_0814ADD4: .4byte 0x03005B60
_0814ADD8: .4byte 0x0000FFFF
_0814ADDC:
	ldr r1, _0814AE00
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _0814AE04
	strh r1, [r0, #8]
	movs r1, #1
_0814ADEC:
	strh r1, [r0, #0xa]
_0814ADEE:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0814AE00: .4byte 0x03005B60
_0814AE04: .4byte 0x0000FFFF
	thumb_func_end Phase2_32_Func1

	thumb_func_start Phase2_32_Func2
Phase2_32_Func2: @ 0x0814AE08
	push {r4, lr}
	sub sp, #0x24
	adds r4, r0, #0
	ldr r1, _0814AE6C
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	adds r0, r0, r1
	ldrb r3, [r0]
	lsrs r2, r3, #3
	movs r0, #7
	ands r3, r0
	ldr r1, _0814AE70
	movs r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	lsls r2, r2, #2
	adds r2, #1
	str r2, [sp, #8]
	lsls r3, r3, #2
	str r3, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	movs r2, #0
	movs r3, #0
	bl CopyRectToBgTilemapBufferRect
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	ble _0814AE60
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
_0814AE60:
	movs r0, #0
	add sp, #0x24
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814AE6C: .4byte 0x085A9503
_0814AE70: .4byte 0x085A83D8
	thumb_func_end Phase2_32_Func2

	thumb_func_start Phase2_32_Func3
Phase2_32_Func3: @ 0x0814AE74
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0814AE94
	movs r1, #0x10
	movs r2, #0
	bl BlendPalettes
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814AE94: .4byte 0xFFFF7FFF
	thumb_func_end Phase2_32_Func3

	thumb_func_start Phase2_32_Func4
Phase2_32_Func4: @ 0x0814AE98
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _0814AEF8
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	adds r0, r0, r1
	ldrb r3, [r0]
	lsrs r2, r3, #3
	movs r0, #7
	ands r3, r0
	lsls r2, r2, #2
	adds r2, #1
	lsls r3, r3, #2
	movs r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #1
	bl FillBgTilemapBufferRect
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	ble _0814AEEE
	ldr r0, _0814AEFC
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl DestroyTask
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
_0814AEEE:
	movs r0, #0
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814AEF8: .4byte 0x085A9503
_0814AEFC: .4byte 0x0814ACA5
	thumb_func_end Phase2_32_Func4

	thumb_func_start Phase2_32_Func5
Phase2_32_Func5: @ 0x0814AF00
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0814AF64
	movs r1, #0
	strh r1, [r0]
	ldr r4, _0814AF68
	strh r1, [r4]
	movs r0, #0x12
	movs r1, #0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, #0x10
	bl SetGpuReg
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0x10
	movs r2, #0
	bl BlendPalettes
	ldr r0, [r5]
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl DestroyTask
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0814AF64: .4byte 0x02022AC8
_0814AF68: .4byte 0x02022ACA
	thumb_func_end Phase2_32_Func5

