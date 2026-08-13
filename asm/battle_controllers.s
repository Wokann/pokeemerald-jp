.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	thumb_func_start BtlController_EmitGetMonData
BtlController_EmitGetMonData: @ 0x0803374C
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803376C
	movs r3, #0
	strb r3, [r1]
	strb r4, [r1, #1]
	strb r2, [r1, #2]
	strb r3, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803376C: .4byte 0x020229C4
	thumb_func_end BtlController_EmitGetMonData

	thumb_func_start BtlController_EmitGetRawMonData
BtlController_EmitGetRawMonData: @ 0x08033770
	push {r4, r5, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033794
	movs r4, #0
	movs r3, #1
	strb r3, [r1]
	strb r5, [r1, #1]
	strb r2, [r1, #2]
	strb r4, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08033794: .4byte 0x020229C4
	thumb_func_end BtlController_EmitGetRawMonData

	thumb_func_start BtlController_EmitSetMonData
BtlController_EmitSetMonData: @ 0x08033798
	push {r4, r5, r6, lr}
	ldr r4, [sp, #0x10]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	ldr r0, _080337D4
	movs r3, #2
	strb r3, [r0]
	strb r1, [r0, #1]
	strb r2, [r0, #2]
	adds r1, r0, #0
	cmp r5, #0
	beq _080337C6
	adds r3, r1, #3
	adds r2, r5, #0
_080337B8:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, #1
	adds r3, #1
	subs r2, #1
	cmp r2, #0
	bne _080337B8
_080337C6:
	adds r2, r5, #3
	adds r0, r6, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080337D4: .4byte 0x020229C4
	thumb_func_end BtlController_EmitSetMonData

	thumb_func_start BtlController_EmitSetRawMonData
BtlController_EmitSetRawMonData: @ 0x080337D8
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	ldr r0, _08033814
	movs r2, #3
	strb r2, [r0]
	strb r1, [r0, #1]
	strb r4, [r0, #2]
	adds r5, r0, #0
	cmp r4, #0
	beq _08033804
	adds r1, r5, #3
	adds r2, r4, #0
_080337F6:
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, #1
	adds r1, #1
	subs r2, #1
	cmp r2, #0
	bne _080337F6
_08033804:
	adds r2, r4, #3
	adds r0, r6, #0
	adds r1, r5, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033814: .4byte 0x020229C4
	thumb_func_end BtlController_EmitSetRawMonData

	thumb_func_start BtlController_EmitLoadMonSprite
BtlController_EmitLoadMonSprite: @ 0x08033818
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033834
	movs r2, #4
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033834: .4byte 0x020229C4
	thumb_func_end BtlController_EmitLoadMonSprite

	thumb_func_start BtlController_EmitSwitchInAnim
BtlController_EmitSwitchInAnim: @ 0x08033838
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033858
	movs r3, #5
	strb r3, [r1]
	strb r4, [r1, #1]
	strb r2, [r1, #2]
	strb r3, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033858: .4byte 0x020229C4
	thumb_func_end BtlController_EmitSwitchInAnim

	thumb_func_start BtlController_EmitReturnMonToBall
BtlController_EmitReturnMonToBall: @ 0x0803385C
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033878
	movs r2, #6
	strb r2, [r1]
	strb r3, [r1, #1]
	movs r2, #2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033878: .4byte 0x020229C4
	thumb_func_end BtlController_EmitReturnMonToBall

	thumb_func_start BtlController_EmitDrawTrainerPic
BtlController_EmitDrawTrainerPic: @ 0x0803387C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033898
	movs r2, #7
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033898: .4byte 0x020229C4
	thumb_func_end BtlController_EmitDrawTrainerPic

	thumb_func_start BtlController_EmitTrainerSlide
BtlController_EmitTrainerSlide: @ 0x0803389C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080338B8
	movs r2, #8
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080338B8: .4byte 0x020229C4
	thumb_func_end BtlController_EmitTrainerSlide

	thumb_func_start BtlController_EmitTrainerSlideBack
BtlController_EmitTrainerSlideBack: @ 0x080338BC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080338D8
	movs r2, #9
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080338D8: .4byte 0x020229C4
	thumb_func_end BtlController_EmitTrainerSlideBack

	thumb_func_start BtlController_EmitFaintAnimation
BtlController_EmitFaintAnimation: @ 0x080338DC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080338F8
	movs r2, #0xa
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080338F8: .4byte 0x020229C4
	thumb_func_end BtlController_EmitFaintAnimation

	thumb_func_start BtlController_EmitPaletteFade
BtlController_EmitPaletteFade: @ 0x080338FC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033918
	movs r2, #0xb
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033918: .4byte 0x020229C4
	thumb_func_end BtlController_EmitPaletteFade

	thumb_func_start BtlController_EmitSuccessBallThrowAnim
BtlController_EmitSuccessBallThrowAnim: @ 0x0803391C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033938
	movs r2, #0xc
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033938: .4byte 0x020229C4
	thumb_func_end BtlController_EmitSuccessBallThrowAnim

	thumb_func_start BtlController_EmitBallThrowAnim
BtlController_EmitBallThrowAnim: @ 0x0803393C
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033958
	movs r2, #0xd
	strb r2, [r1]
	strb r3, [r1, #1]
	movs r2, #2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033958: .4byte 0x020229C4
	thumb_func_end BtlController_EmitBallThrowAnim

	thumb_func_start BtlController_EmitPause
BtlController_EmitPause: @ 0x0803395C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r1, _080339A0
	movs r0, #0xe
	strb r0, [r1]
	strb r4, [r1, #1]
	lsls r0, r4, #1
	adds r0, r0, r4
	adds r5, r1, #0
	cmp r0, #0
	beq _0803398A
	adds r1, r5, #2
	adds r3, r0, #0
_0803397C:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bne _0803397C
_0803398A:
	lsls r2, r4, #1
	adds r2, r2, r4
	adds r2, #2
	adds r0, r6, #0
	adds r1, r5, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080339A0: .4byte 0x020229C4
	thumb_func_end BtlController_EmitPause

	thumb_func_start BtlController_EmitMoveAnimation
BtlController_EmitMoveAnimation: @ 0x080339A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r6, [sp, #0x2c]
	mov r8, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r7, _08033A3C
	movs r0, #0
	mov ip, r0
	movs r0, #0xf
	strb r0, [r7]
	strb r1, [r7, #1]
	lsrs r1, r1, #8
	strb r1, [r7, #2]
	strb r2, [r7, #3]
	strb r3, [r7, #4]
	movs r6, #0xff
	lsls r6, r6, #8
	lsrs r3, r3, #8
	strb r3, [r7, #5]
	strb r4, [r7, #6]
	adds r0, r4, #0
	ands r0, r6
	asrs r0, r0, #8
	strb r0, [r7, #7]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r4
	asrs r0, r0, #0x10
	strb r0, [r7, #8]
	lsrs r4, r4, #0x18
	strb r4, [r7, #9]
	strb r5, [r7, #0xa]
	mov r0, r8
	strb r0, [r7, #0xb]
	mov r0, ip
	str r0, [sp]
	movs r0, #0xe
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08033A44
	str r0, [sp]
	movs r0, #0xe
	movs r1, #0
	movs r2, #0x4d
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08033A44
	ldr r0, _08033A40
	ldrh r0, [r0]
	strb r0, [r7, #0xc]
	ands r6, r0
	lsrs r0, r6, #8
	strb r0, [r7, #0xd]
	adds r4, r7, #0
	b _08033A4E
	.align 2, 0
_08033A3C: .4byte 0x020229C4
_08033A40: .4byte 0x02024070
_08033A44:
	ldr r0, _08033A78
	movs r1, #0
	strb r1, [r0, #0xc]
	strb r1, [r0, #0xd]
	adds r4, r0, #0
_08033A4E:
	movs r0, #0
	strb r0, [r4, #0xe]
	strb r0, [r4, #0xf]
	adds r0, r4, #0
	adds r0, #0x10
	ldr r1, [sp, #0x28]
	movs r2, #0x1c
	bl memcpy
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0x2c
	bl PrepareBufferDataTransfer
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033A78: .4byte 0x020229C4
	thumb_func_end BtlController_EmitMoveAnimation

	thumb_func_start BtlController_EmitPrintString
BtlController_EmitPrintString: @ 0x08033A7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08033B40
	movs r0, #0x10
	strb r0, [r2]
	ldr r0, _08033B44
	ldrb r0, [r0]
	strb r0, [r2, #1]
	strb r1, [r2, #2]
	lsrs r1, r1, #8
	strb r1, [r2, #3]
	adds r0, r2, #4
	mov ip, r0
	ldr r4, _08033B48
	ldrh r0, [r4]
	strh r0, [r2, #4]
	ldr r0, _08033B4C
	ldrh r0, [r0]
	mov r1, ip
	strh r0, [r1, #2]
	ldr r0, _08033B50
	ldrh r0, [r0]
	strh r0, [r1, #4]
	ldr r0, _08033B54
	ldrb r0, [r0]
	strb r0, [r1, #6]
	ldr r0, _08033B58
	ldrb r0, [r0, #0x17]
	strb r0, [r1, #7]
	ldr r0, _08033B5C
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x52
	ldrb r1, [r1]
	mov r3, ip
	strb r1, [r3, #8]
	adds r0, #0xb1
	ldrb r0, [r0]
	strb r0, [r3, #9]
	ldr r0, _08033B60
	ldrb r0, [r0]
	strb r0, [r3, #0xa]
	ldr r3, _08033B64
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #2]
	mov r1, ip
	strb r0, [r1, #0xb]
	movs r3, #0
	adds r7, r2, #0
	adds r2, #0x10
	ldr r0, _08033B68
	adds r4, r0, #0
	adds r4, #0x20
_08033AFA:
	adds r1, r2, r3
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #0x58
	adds r3, #1
	cmp r3, #3
	ble _08033AFA
	movs r3, #0
	mov r4, ip
	adds r4, #0x10
	ldr r6, _08033B6C
	mov r2, ip
	adds r2, #0x20
	ldr r5, _08033B70
_08033B16:
	adds r1, r4, r3
	adds r0, r3, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r3
	adds r0, r3, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	cmp r3, #0xf
	ble _08033B16
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0x34
	bl PrepareBufferDataTransfer
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033B40: .4byte 0x020229C4
_08033B44: .4byte 0x02023FDE
_08033B48: .4byte 0x02023E8E
_08033B4C: .4byte 0x02023E90
_08033B50: .4byte 0x02023EAC
_08033B54: .4byte 0x02023EAE
_08033B58: .4byte 0x02024118
_08033B5C: .4byte 0x02024140
_08033B60: .4byte 0x02023EB3
_08033B64: .4byte 0x082ED220
_08033B68: .4byte 0x02023D28
_08033B6C: .4byte 0x02022C0C
_08033B70: .4byte 0x02022C1C
	thumb_func_end BtlController_EmitPrintString

	thumb_func_start BtlController_EmitPrintSelectionString
BtlController_EmitPrintSelectionString: @ 0x08033B74
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08033C14
	movs r0, #0x11
	strb r0, [r2]
	strb r0, [r2, #1]
	strb r1, [r2, #2]
	lsrs r1, r1, #8
	strb r1, [r2, #3]
	adds r0, r2, #4
	mov ip, r0
	ldr r0, _08033C18
	ldrh r0, [r0]
	strh r0, [r2, #4]
	ldr r0, _08033C1C
	ldrh r0, [r0]
	mov r1, ip
	strh r0, [r1, #2]
	ldr r0, _08033C20
	ldrh r0, [r0]
	strh r0, [r1, #4]
	ldr r0, _08033C24
	ldrb r0, [r0]
	strb r0, [r1, #6]
	ldr r0, _08033C28
	ldrb r0, [r0, #0x17]
	strb r0, [r1, #7]
	ldr r0, _08033C2C
	ldr r0, [r0]
	adds r0, #0x52
	ldrb r0, [r0]
	strb r0, [r1, #8]
	movs r3, #0
	adds r7, r2, #0
	adds r4, r7, #0
	adds r4, #0x10
	ldr r0, _08033C30
	adds r2, r0, #0
	adds r2, #0x20
_08033BCE:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #0x58
	adds r3, #1
	cmp r3, #3
	ble _08033BCE
	movs r3, #0
	mov r4, ip
	adds r4, #0x10
	ldr r6, _08033C34
	mov r2, ip
	adds r2, #0x20
	ldr r5, _08033C38
_08033BEA:
	adds r1, r4, r3
	adds r0, r3, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r3
	adds r0, r3, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	cmp r3, #0xf
	ble _08033BEA
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0x34
	bl PrepareBufferDataTransfer
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033C14: .4byte 0x020229C4
_08033C18: .4byte 0x02023E8E
_08033C1C: .4byte 0x02023E90
_08033C20: .4byte 0x02023EAC
_08033C24: .4byte 0x02023EAE
_08033C28: .4byte 0x02024118
_08033C2C: .4byte 0x02024140
_08033C30: .4byte 0x02023D28
_08033C34: .4byte 0x02022C0C
_08033C38: .4byte 0x02022C1C
	thumb_func_end BtlController_EmitPrintSelectionString

	thumb_func_start BtlController_EmitChooseAction
BtlController_EmitChooseAction: @ 0x08033C3C
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, _08033C64
	movs r3, #0x12
	strb r3, [r1]
	strb r4, [r1, #1]
	strb r2, [r1, #2]
	lsrs r2, r2, #8
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033C64: .4byte 0x020229C4
	thumb_func_end BtlController_EmitChooseAction

	thumb_func_start BtlController_EmitUnknownYesNoBox
BtlController_EmitUnknownYesNoBox: @ 0x08033C68
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033C84
	movs r2, #0x13
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033C84: .4byte 0x020229C4
	thumb_func_end BtlController_EmitUnknownYesNoBox

	thumb_func_start BtlController_EmitChooseMove
BtlController_EmitChooseMove: @ 0x08033C88
	push {r4, r5, r6, lr}
	adds r5, r3, #0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r3, _08033CC0
	movs r4, #0
	movs r0, #0x14
	strb r0, [r3]
	strb r1, [r3, #1]
	strb r2, [r3, #2]
	strb r4, [r3, #3]
	movs r2, #0
	adds r1, r3, #0
	adds r4, r1, #4
_08033CA4:
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r4]
	adds r4, #1
	adds r2, #1
	cmp r2, #0x13
	bls _08033CA4
	adds r0, r6, #0
	movs r2, #0x18
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033CC0: .4byte 0x020229C4
	thumb_func_end BtlController_EmitChooseMove

	thumb_func_start BtlController_EmitChooseItem
BtlController_EmitChooseItem: @ 0x08033CC4
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08033CF4
	movs r0, #0x15
	strb r0, [r1]
	movs r2, #0
	adds r3, r1, #1
_08033CD6:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, #1
	adds r2, #1
	cmp r2, #2
	ble _08033CD6
	adds r0, r5, #0
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08033CF4: .4byte 0x020229C4
	thumb_func_end BtlController_EmitChooseItem

	thumb_func_start BtlController_EmitChoosePokemon
BtlController_EmitChoosePokemon: @ 0x08033CF8
	push {r4, r5, r6, lr}
	ldr r6, [sp, #0x10]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r4, _08033D30
	movs r0, #0x16
	strb r0, [r4]
	strb r1, [r4, #1]
	strb r2, [r4, #2]
	strb r3, [r4, #3]
	movs r2, #0
	adds r1, r4, #0
	adds r3, r1, #4
_08033D12:
	adds r0, r6, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, #1
	adds r2, #1
	cmp r2, #2
	ble _08033D12
	adds r0, r5, #0
	movs r2, #8
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033D30: .4byte 0x020229C4
	thumb_func_end BtlController_EmitChoosePokemon

	thumb_func_start BtlController_EmitCmd23
BtlController_EmitCmd23: @ 0x08033D34
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033D50
	movs r2, #0x17
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033D50: .4byte 0x020229C4
	thumb_func_end BtlController_EmitCmd23

	thumb_func_start BtlController_EmitHealthBarUpdate
BtlController_EmitHealthBarUpdate: @ 0x08033D54
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08033D88
	movs r4, #0
	movs r2, #0x18
	strb r2, [r3]
	strb r4, [r3, #1]
	strb r1, [r3, #2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0xff
	lsls r2, r2, #8
	ands r1, r2
	asrs r1, r1, #8
	strb r1, [r3, #3]
	adds r1, r3, #0
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033D88: .4byte 0x020229C4
	thumb_func_end BtlController_EmitHealthBarUpdate

	thumb_func_start BtlController_EmitExpUpdate
BtlController_EmitExpUpdate: @ 0x08033D8C
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, _08033DBC
	movs r3, #0x19
	strb r3, [r1]
	strb r4, [r1, #1]
	strb r2, [r1, #2]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #0xff
	lsls r3, r3, #8
	ands r2, r3
	asrs r2, r2, #8
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033DBC: .4byte 0x020229C4
	thumb_func_end BtlController_EmitExpUpdate

	thumb_func_start BtlController_EmitStatusIconUpdate
BtlController_EmitStatusIconUpdate: @ 0x08033DC0
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033E10
	movs r3, #0x1a
	strb r3, [r1]
	strb r4, [r1, #1]
	movs r6, #0xff
	lsls r6, r6, #8
	adds r3, r4, #0
	ands r3, r6
	lsrs r3, r3, #8
	strb r3, [r1, #2]
	movs r5, #0xff
	lsls r5, r5, #0x10
	adds r3, r4, #0
	ands r3, r5
	lsrs r3, r3, #0x10
	strb r3, [r1, #3]
	lsrs r4, r4, #0x18
	strb r4, [r1, #4]
	strb r2, [r1, #5]
	adds r3, r2, #0
	ands r3, r6
	lsrs r3, r3, #8
	strb r3, [r1, #6]
	adds r3, r2, #0
	ands r3, r5
	lsrs r3, r3, #0x10
	strb r3, [r1, #7]
	lsrs r2, r2, #0x18
	strb r2, [r1, #8]
	movs r2, #9
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033E10: .4byte 0x020229C4
	thumb_func_end BtlController_EmitStatusIconUpdate

	thumb_func_start BtlController_EmitStatusAnimation
BtlController_EmitStatusAnimation: @ 0x08033E14
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033E4C
	movs r3, #0x1b
	strb r3, [r1]
	strb r4, [r1, #1]
	strb r2, [r1, #2]
	movs r3, #0xff
	lsls r3, r3, #8
	ands r3, r2
	lsrs r3, r3, #8
	strb r3, [r1, #3]
	movs r3, #0xff
	lsls r3, r3, #0x10
	ands r3, r2
	lsrs r3, r3, #0x10
	strb r3, [r1, #4]
	lsrs r2, r2, #0x18
	strb r2, [r1, #5]
	movs r2, #6
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033E4C: .4byte 0x020229C4
	thumb_func_end BtlController_EmitStatusAnimation

	thumb_func_start BtlController_EmitStatusXor
BtlController_EmitStatusXor: @ 0x08033E50
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08033E6C
	movs r2, #0x1c
	strb r2, [r1]
	strb r3, [r1, #1]
	movs r2, #2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08033E6C: .4byte 0x020229C4
	thumb_func_end BtlController_EmitStatusXor

	thumb_func_start BtlController_EmitDataTransfer
BtlController_EmitDataTransfer: @ 0x08033E70
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r1, _08033EB4
	movs r0, #0x1d
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r4, [r1, #2]
	lsrs r0, r4, #8
	strb r0, [r1, #3]
	adds r5, r1, #0
	cmp r4, #0
	beq _08033EA0
	adds r1, r5, #4
	adds r3, r4, #0
_08033E92:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bne _08033E92
_08033EA0:
	adds r2, r4, #4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033EB4: .4byte 0x020229C4
	thumb_func_end BtlController_EmitDataTransfer

	thumb_func_start BtlController_EmitDMA3Transfer
BtlController_EmitDMA3Transfer: @ 0x08033EB8
	push {r4, r5, r6, lr}
	adds r4, r3, #0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r2, _08033F1C
	movs r0, #0x1e
	strb r0, [r2]
	strb r1, [r2, #1]
	movs r3, #0xff
	lsls r3, r3, #8
	adds r0, r1, #0
	ands r0, r3
	lsrs r0, r0, #8
	strb r0, [r2, #2]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	lsrs r0, r0, #0x10
	strb r0, [r2, #3]
	lsrs r1, r1, #0x18
	strb r1, [r2, #4]
	strb r5, [r2, #5]
	adds r0, r5, #0
	ands r0, r3
	lsrs r0, r0, #8
	strb r0, [r2, #6]
	adds r1, r2, #0
	cmp r5, #0
	beq _08033F08
	adds r3, r1, #7
	adds r2, r5, #0
_08033EFA:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, #1
	adds r3, #1
	subs r2, #1
	cmp r2, #0
	bne _08033EFA
_08033F08:
	adds r2, r5, #7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033F1C: .4byte 0x020229C4
	thumb_func_end BtlController_EmitDMA3Transfer

	thumb_func_start BtlController_EmitPlayBGM
BtlController_EmitPlayBGM: @ 0x08033F20
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r1, _08033F64
	movs r0, #0x1f
	strb r0, [r1]
	strb r4, [r1, #1]
	lsrs r0, r4, #8
	strb r0, [r1, #2]
	adds r5, r1, #0
	cmp r4, #0
	beq _08033F4E
	adds r1, r5, #3
	adds r3, r4, #0
_08033F40:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bne _08033F40
_08033F4E:
	adds r2, r4, #3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033F64: .4byte 0x020229C4
	thumb_func_end BtlController_EmitPlayBGM

	thumb_func_start BtlController_EmitCmd32
BtlController_EmitCmd32: @ 0x08033F68
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r1, _08033FAC
	movs r0, #0x20
	strb r0, [r1]
	strb r4, [r1, #1]
	lsrs r0, r4, #8
	strb r0, [r1, #2]
	adds r5, r1, #0
	cmp r4, #0
	beq _08033F96
	adds r1, r5, #3
	adds r3, r4, #0
_08033F88:
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bne _08033F88
_08033F96:
	adds r2, r4, #3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08033FAC: .4byte 0x020229C4
	thumb_func_end BtlController_EmitCmd32

	thumb_func_start BtlController_EmitTwoReturnValues
BtlController_EmitTwoReturnValues: @ 0x08033FB0
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, _08033FD8
	movs r3, #0x21
	strb r3, [r1]
	strb r4, [r1, #1]
	strb r2, [r1, #2]
	lsrs r2, r2, #8
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08033FD8: .4byte 0x020229C4
	thumb_func_end BtlController_EmitTwoReturnValues

	thumb_func_start BtlController_EmitChosenMonReturnValue
BtlController_EmitChosenMonReturnValue: @ 0x08033FDC
	push {r4, r5, lr}
	adds r4, r2, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _08034010
	movs r0, #0x22
	strb r0, [r2]
	strb r1, [r2, #1]
	movs r3, #0
	adds r1, r2, #2
_08033FF0:
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, #1
	adds r3, #1
	cmp r3, #2
	ble _08033FF0
	adds r0, r5, #0
	adds r1, r2, #0
	movs r2, #5
	bl PrepareBufferDataTransfer
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034010: .4byte 0x020229C4
	thumb_func_end BtlController_EmitChosenMonReturnValue

	thumb_func_start BtlController_EmitOneReturnValue
BtlController_EmitOneReturnValue: @ 0x08034014
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0803403C
	movs r4, #0
	movs r2, #0x23
	strb r2, [r3]
	strb r1, [r3, #1]
	lsrs r1, r1, #8
	strb r1, [r3, #2]
	strb r4, [r3, #3]
	adds r1, r3, #0
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803403C: .4byte 0x020229C4
	thumb_func_end BtlController_EmitOneReturnValue

	thumb_func_start BtlController_EmitOneReturnValue_Duplicate
BtlController_EmitOneReturnValue_Duplicate: @ 0x08034040
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08034068
	movs r4, #0
	movs r2, #0x24
	strb r2, [r3]
	strb r1, [r3, #1]
	lsrs r1, r1, #8
	strb r1, [r3, #2]
	strb r4, [r3, #3]
	adds r1, r3, #0
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034068: .4byte 0x020229C4
	thumb_func_end BtlController_EmitOneReturnValue_Duplicate

	thumb_func_start BtlController_EmitCmd37
BtlController_EmitCmd37: @ 0x0803406C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08034088
	movs r2, #0x25
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08034088: .4byte 0x020229C4
	thumb_func_end BtlController_EmitCmd37

	thumb_func_start BtlController_EmitCmd38
BtlController_EmitCmd38: @ 0x0803408C
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080340A8
	movs r2, #0x26
	strb r2, [r1]
	strb r3, [r1, #1]
	movs r2, #2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080340A8: .4byte 0x020229C4
	thumb_func_end BtlController_EmitCmd38

	thumb_func_start BtlController_EmitCmd39
BtlController_EmitCmd39: @ 0x080340AC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080340C8
	movs r2, #0x27
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080340C8: .4byte 0x020229C4
	thumb_func_end BtlController_EmitCmd39

	thumb_func_start BtlController_EmitCmd40
BtlController_EmitCmd40: @ 0x080340CC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080340E8
	movs r2, #0x28
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080340E8: .4byte 0x020229C4
	thumb_func_end BtlController_EmitCmd40

	thumb_func_start BtlController_EmitHitAnimation
BtlController_EmitHitAnimation: @ 0x080340EC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08034108
	movs r2, #0x29
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08034108: .4byte 0x020229C4
	thumb_func_end BtlController_EmitHitAnimation

	thumb_func_start BtlController_EmitCmd42
BtlController_EmitCmd42: @ 0x0803410C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08034128
	movs r2, #0x2a
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08034128: .4byte 0x020229C4
	thumb_func_end BtlController_EmitCmd42

	thumb_func_start BtlController_EmitPlaySE
BtlController_EmitPlaySE: @ 0x0803412C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08034154
	movs r4, #0
	movs r2, #0x2b
	strb r2, [r3]
	strb r1, [r3, #1]
	lsrs r1, r1, #8
	strb r1, [r3, #2]
	strb r4, [r3, #3]
	adds r1, r3, #0
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034154: .4byte 0x020229C4
	thumb_func_end BtlController_EmitPlaySE

	thumb_func_start BtlController_EmitPlayFanfareOrBGM
BtlController_EmitPlayFanfareOrBGM: @ 0x08034158
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _08034180
	movs r3, #0x2c
	strb r3, [r4]
	strb r1, [r4, #1]
	lsrs r1, r1, #8
	strb r1, [r4, #2]
	strb r2, [r4, #3]
	adds r1, r4, #0
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08034180: .4byte 0x020229C4
	thumb_func_end BtlController_EmitPlayFanfareOrBGM

	thumb_func_start BtlController_EmitFaintingCry
BtlController_EmitFaintingCry: @ 0x08034184
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080341A0
	movs r2, #0x2d
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080341A0: .4byte 0x020229C4
	thumb_func_end BtlController_EmitFaintingCry

	thumb_func_start BtlController_EmitIntroSlide
BtlController_EmitIntroSlide: @ 0x080341A4
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080341C0
	movs r2, #0x2e
	strb r2, [r1]
	strb r3, [r1, #1]
	movs r2, #2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080341C0: .4byte 0x020229C4
	thumb_func_end BtlController_EmitIntroSlide

	thumb_func_start BtlController_EmitIntroTrainerBallThrow
BtlController_EmitIntroTrainerBallThrow: @ 0x080341C4
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080341E0
	movs r2, #0x2f
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_080341E0: .4byte 0x020229C4
	thumb_func_end BtlController_EmitIntroTrainerBallThrow

	thumb_func_start BtlController_EmitDrawPartyStatusSummary
BtlController_EmitDrawPartyStatusSummary: @ 0x080341E4
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _08034228
	movs r3, #0x30
	strb r3, [r1]
	movs r0, #0x7f
	ands r0, r2
	strb r0, [r1, #1]
	movs r0, #0x80
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1f
	strb r0, [r1, #2]
	strb r3, [r1, #3]
	movs r2, #0
	adds r3, r1, #4
_0803420C:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, #1
	adds r2, #1
	cmp r2, #0x2f
	ble _0803420C
	adds r0, r5, #0
	movs r2, #0x34
	bl PrepareBufferDataTransfer
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034228: .4byte 0x020229C4
	thumb_func_end BtlController_EmitDrawPartyStatusSummary

	thumb_func_start BtlController_EmitHidePartyStatusSummary
BtlController_EmitHidePartyStatusSummary: @ 0x0803422C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08034248
	movs r2, #0x31
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08034248: .4byte 0x020229C4
	thumb_func_end BtlController_EmitHidePartyStatusSummary

	thumb_func_start BtlController_EmitEndBounceEffect
BtlController_EmitEndBounceEffect: @ 0x0803424C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08034268
	movs r2, #0x32
	strb r2, [r1]
	strb r2, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_08034268: .4byte 0x020229C4
	thumb_func_end BtlController_EmitEndBounceEffect

	thumb_func_start BtlController_EmitSpriteInvisibility
BtlController_EmitSpriteInvisibility: @ 0x0803426C
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803428C
	movs r2, #0x33
	strb r2, [r1]
	strb r3, [r1, #1]
	strb r2, [r1, #2]
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_0803428C: .4byte 0x020229C4
	thumb_func_end BtlController_EmitSpriteInvisibility

	thumb_func_start BtlController_EmitBattleAnimation
BtlController_EmitBattleAnimation: @ 0x08034290
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, _080342B8
	movs r3, #0x34
	strb r3, [r1]
	strb r4, [r1, #1]
	strb r2, [r1, #2]
	lsrs r2, r2, #8
	strb r2, [r1, #3]
	movs r2, #4
	bl PrepareBufferDataTransfer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080342B8: .4byte 0x020229C4
	thumb_func_end BtlController_EmitBattleAnimation

	thumb_func_start BtlController_EmitLinkStandbyMsg
BtlController_EmitLinkStandbyMsg: @ 0x080342BC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, _080342E0
	movs r0, #0x35
	strb r0, [r4]
	strb r1, [r4, #1]
	cmp r2, #0
	beq _080342E4
	adds r0, r4, #4
	bl sub_08184F3C
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	b _080342E8
	.align 2, 0
_080342E0: .4byte 0x020229C4
_080342E4:
	strb r2, [r4, #2]
	strb r2, [r4, #3]
_080342E8:
	ldr r1, _080342FC
	ldrb r2, [r1, #2]
	adds r2, #4
	adds r0, r5, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080342FC: .4byte 0x020229C4
	thumb_func_end BtlController_EmitLinkStandbyMsg

	thumb_func_start BtlController_EmitResetActionMoveSelection
BtlController_EmitResetActionMoveSelection: @ 0x08034300
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803431C
	movs r2, #0x36
	strb r2, [r1]
	strb r3, [r1, #1]
	movs r2, #2
	bl PrepareBufferDataTransfer
	pop {r0}
	bx r0
	.align 2, 0
_0803431C: .4byte 0x020229C4
	thumb_func_end BtlController_EmitResetActionMoveSelection

	thumb_func_start BtlController_EmitCmd55
BtlController_EmitCmd55: @ 0x08034320
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r4, _08034364
	movs r0, #0x37
	strb r0, [r4]
	strb r1, [r4, #1]
	ldr r0, _08034368
	ldr r1, [r0]
	ldr r0, _0803436C
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1f
	strb r0, [r4, #2]
	ldrb r0, [r1]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1f
	strb r0, [r4, #3]
	adds r0, r4, #6
	bl sub_08184F3C
	strb r0, [r4, #4]
	strb r0, [r4, #5]
	ldrb r2, [r4, #4]
	adds r2, #6
	adds r0, r5, #0
	adds r1, r4, #0
	bl PrepareBufferDataTransfer
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034364: .4byte 0x020229C4
_08034368: .4byte 0x03005AF0
_0803436C: .4byte 0x00000CA9
	thumb_func_end BtlController_EmitCmd55

