.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified







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

