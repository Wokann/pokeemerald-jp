.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start MovementAction_JumpInPlaceLeftRight_Step0
MovementAction_JumpInPlaceLeftRight_Step0: @ 0x08094CF8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	movs r3, #0
	bl maybe_shadow_1
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_JumpInPlaceLeftRight_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_JumpInPlaceLeftRight_Step0

	thumb_func_start MovementAction_JumpInPlaceLeftRight_Step1
MovementAction_JumpInPlaceLeftRight_Step1: @ 0x08094D24
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B50
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D38
	movs r0, #0
	b _08094D48
_08094D38:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08094D48:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_JumpInPlaceLeftRight_Step1

	thumb_func_start MovementAction_JumpInPlaceRightLeft_Step0
MovementAction_JumpInPlaceRightLeft_Step0: @ 0x08094D50
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #0
	bl maybe_shadow_1
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_JumpInPlaceRightLeft_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_JumpInPlaceRightLeft_Step0

	thumb_func_start MovementAction_JumpInPlaceRightLeft_Step1
MovementAction_JumpInPlaceRightLeft_Step1: @ 0x08094D7C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B50
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094D90
	movs r0, #0
	b _08094DA0
_08094D90:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08094DA0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_JumpInPlaceRightLeft_Step1

	thumb_func_start MovementAction_FaceOriginalDirection_Step0
MovementAction_FaceOriginalDirection_Step0: @ 0x08094DA8
	push {lr}
	ldr r3, _08094DBC
	ldrb r2, [r0, #6]
	adds r2, r2, r3
	ldrb r2, [r2]
	bl FaceDirection
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_08094DBC: .4byte 0x084DDA21
	thumb_func_end MovementAction_FaceOriginalDirection_Step0

	thumb_func_start MovementAction_NurseJoyBowDown_Step0
MovementAction_NurseJoyBowDown_Step0: @ 0x08094DC0
	push {lr}
	movs r2, #1
	movs r3, #0x14
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r1}
	bx r1
	thumb_func_end MovementAction_NurseJoyBowDown_Step0

	thumb_func_start MovementAction_EnableJumpLandingGroundEffect_Step0
MovementAction_EnableJumpLandingGroundEffect_Step0: @ 0x08094DD0
	ldrb r3, [r0, #3]
	movs r2, #3
	rsbs r2, r2, #0
	ands r2, r3
	strb r2, [r0, #3]
	movs r0, #1
	strh r0, [r1, #0x32]
	bx lr
	thumb_func_end MovementAction_EnableJumpLandingGroundEffect_Step0

	thumb_func_start MovementAction_DisableJumpLandingGroundEffect_Step0
MovementAction_DisableJumpLandingGroundEffect_Step0: @ 0x08094DE0
	ldrb r2, [r0, #3]
	movs r3, #2
	orrs r2, r3
	strb r2, [r0, #3]
	movs r0, #1
	strh r0, [r1, #0x32]
	bx lr
	.align 2, 0
	thumb_func_end MovementAction_DisableJumpLandingGroundEffect_Step0

	thumb_func_start MovementAction_DisableAnimation_Step0
MovementAction_DisableAnimation_Step0: @ 0x08094DF0
	ldrb r2, [r0, #1]
	movs r3, #0x10
	orrs r2, r3
	strb r2, [r0, #1]
	movs r0, #1
	strh r0, [r1, #0x32]
	bx lr
	.align 2, 0
	thumb_func_end MovementAction_DisableAnimation_Step0

	thumb_func_start MovementAction_RestoreAnimation_Step0
MovementAction_RestoreAnimation_Step0: @ 0x08094E00
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #5]
	bl GetObjectEventGraphicsInfo
	ldrb r1, [r0, #0xc]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x1f
	lsls r1, r1, #4
	ldrb r2, [r4, #1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #1]
	movs r0, #1
	strh r0, [r5, #0x32]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_RestoreAnimation_Step0

	thumb_func_start MovementAction_SetInvisible_Step0
MovementAction_SetInvisible_Step0: @ 0x08094E2C
	ldrb r2, [r0, #1]
	movs r3, #0x20
	orrs r2, r3
	strb r2, [r0, #1]
	movs r0, #1
	strh r0, [r1, #0x32]
	bx lr
	.align 2, 0
	thumb_func_end MovementAction_SetInvisible_Step0

	thumb_func_start MovementAction_SetVisible_Step0
MovementAction_SetVisible_Step0: @ 0x08094E3C
	ldrb r3, [r0, #1]
	movs r2, #0x21
	rsbs r2, r2, #0
	ands r2, r3
	strb r2, [r0, #1]
	movs r0, #1
	strh r0, [r1, #0x32]
	bx lr
	thumb_func_end MovementAction_SetVisible_Step0

	thumb_func_start MovementAction_EmoteExclamationMark_Step0
MovementAction_EmoteExclamationMark_Step0: @ 0x08094E4C
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, _08094E6C
	adds r2, r1, #4
	adds r3, r1, #0
	adds r3, #8
	bl EventObjectGetLocalIdAndMap
	movs r0, #0
	bl FieldEffectStart
	movs r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08094E6C: .4byte 0x020388A8
	thumb_func_end MovementAction_EmoteExclamationMark_Step0

	thumb_func_start MovementAction_EmoteQuestionMark_Step0
MovementAction_EmoteQuestionMark_Step0: @ 0x08094E70
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, _08094E90
	adds r2, r1, #4
	adds r3, r1, #0
	adds r3, #8
	bl EventObjectGetLocalIdAndMap
	movs r0, #0x21
	bl FieldEffectStart
	movs r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08094E90: .4byte 0x020388A8
	thumb_func_end MovementAction_EmoteQuestionMark_Step0

	thumb_func_start MovementAction_EmoteHeart_Step0
MovementAction_EmoteHeart_Step0: @ 0x08094E94
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, _08094EB4
	adds r2, r1, #4
	adds r3, r1, #0
	adds r3, #8
	bl EventObjectGetLocalIdAndMap
	movs r0, #0x2e
	bl FieldEffectStart
	movs r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08094EB4: .4byte 0x020388A8
	thumb_func_end MovementAction_EmoteHeart_Step0

	thumb_func_start MovementAction_RevealTrainer_Step0
MovementAction_RevealTrainer_Step0: @ 0x08094EB8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #6]
	cmp r0, #0x3f
	bne _08094ECE
	adds r0, r4, #0
	bl sub_080B3CD0
	movs r0, #0
	b _08094EF6
_08094ECE:
	subs r0, #0x39
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08094EF0
	adds r0, r4, #0
	bl StartRevealDisguise
	movs r0, #1
	strh r0, [r5, #0x32]
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_RevealTrainer_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _08094EF6
_08094EF0:
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08094EF6:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_RevealTrainer_Step0

	thumb_func_start MovementAction_RevealTrainer_Step1
MovementAction_RevealTrainer_Step1: @ 0x08094EFC
	push {r4, lr}
	adds r4, r1, #0
	bl UpdateRevealDisguise
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08094F0E
	movs r0, #0
	b _08094F14
_08094F0E:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08094F14:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_RevealTrainer_Step1

	thumb_func_start MovementAction_RockSmashBreak_Step0
MovementAction_RockSmashBreak_Step0: @ 0x08094F1C
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl SetAndStartSpriteAnim
	movs r0, #1
	strh r0, [r4, #0x32]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_RockSmashBreak_Step0

	thumb_func_start MovementAction_RockSmashBreak_Step1
MovementAction_RockSmashBreak_Step1: @ 0x08094F38
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	bl SpriteAnimEnded
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08094F54
	adds r0, r4, #0
	movs r1, #0x20
	bl SetMovementDelay
	movs r0, #2
	strh r0, [r4, #0x32]
_08094F54:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_RockSmashBreak_Step1

	thumb_func_start MovementAction_RockSmashBreak_Step2
MovementAction_RockSmashBreak_Step2: @ 0x08094F5C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r2, [r4, #1]
	lsls r1, r2, #0x1a
	lsrs r1, r1, #0x1f
	movs r0, #1
	eors r1, r0
	lsls r1, r1, #5
	subs r0, #0x22
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #1]
	adds r0, r5, #0
	bl WaitForMovementDelay
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08094F8E
	ldrb r0, [r4, #1]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r4, #1]
	movs r0, #3
	strh r0, [r5, #0x32]
_08094F8E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_RockSmashBreak_Step2

	thumb_func_start MovementAction_CutTree_Step0
MovementAction_CutTree_Step0: @ 0x08094F98
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl SetAndStartSpriteAnim
	movs r0, #1
	strh r0, [r4, #0x32]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_CutTree_Step0

	thumb_func_start MovementAction_CutTree_Step1
MovementAction_CutTree_Step1: @ 0x08094FB4
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	bl SpriteAnimEnded
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08094FD0
	adds r0, r4, #0
	movs r1, #0x20
	bl SetMovementDelay
	movs r0, #2
	strh r0, [r4, #0x32]
_08094FD0:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_CutTree_Step1

	thumb_func_start MovementAction_CutTree_Step2
MovementAction_CutTree_Step2: @ 0x08094FD8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r2, [r4, #1]
	lsls r1, r2, #0x1a
	lsrs r1, r1, #0x1f
	movs r0, #1
	eors r1, r0
	lsls r1, r1, #5
	subs r0, #0x22
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #1]
	adds r0, r5, #0
	bl WaitForMovementDelay
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809500A
	ldrb r0, [r4, #1]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r4, #1]
	movs r0, #3
	strh r0, [r5, #0x32]
_0809500A:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_CutTree_Step2

	thumb_func_start MovementAction_SetFixedPriority_Step0
MovementAction_SetFixedPriority_Step0: @ 0x08095014
	ldrb r2, [r0, #3]
	movs r3, #4
	orrs r2, r3
	strb r2, [r0, #3]
	movs r0, #1
	strh r0, [r1, #0x32]
	bx lr
	.align 2, 0
	thumb_func_end MovementAction_SetFixedPriority_Step0

	thumb_func_start MovementAction_ClearFixedPriority_Step0
MovementAction_ClearFixedPriority_Step0: @ 0x08095024
	ldrb r3, [r0, #3]
	movs r2, #5
	rsbs r2, r2, #0
	ands r2, r3
	strb r2, [r0, #3]
	movs r0, #1
	strh r0, [r1, #0x32]
	bx lr
	thumb_func_end MovementAction_ClearFixedPriority_Step0

	thumb_func_start MovementAction_InitAffineAnim_Step0
MovementAction_InitAffineAnim_Step0: @ 0x08095034
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	movs r1, #3
	orrs r0, r1
	strb r0, [r4, #1]
	adds r0, r4, #0
	bl InitSpriteAffineAnim
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	adds r4, #0x42
	ldrb r1, [r4]
	movs r0, #0x3f
	ands r0, r1
	strb r0, [r4]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_InitAffineAnim_Step0

	thumb_func_start MovementAction_ClearAffineAnim_Step0
MovementAction_ClearAffineAnim_Step0: @ 0x08095064
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1b
	bl FreeOamMatrix
	ldrb r0, [r4, #1]
	movs r1, #4
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #1]
	lsrs r1, r1, #6
	ldrb r2, [r4, #3]
	lsrs r2, r2, #6
	movs r3, #0
	adds r0, r4, #0
	bl CalcCenterToCornerVec
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_ClearAffineAnim_Step0

	thumb_func_start MovementAction_Unknown1_Step0
MovementAction_Unknown1_Step0: @ 0x08095094
	ldrb r1, [r0, #3]
	movs r2, #8
	orrs r1, r2
	strb r1, [r0, #3]
	movs r0, #1
	bx lr
	thumb_func_end MovementAction_Unknown1_Step0

	thumb_func_start MovementAction_Unknown2_Step0
MovementAction_Unknown2_Step0: @ 0x080950A0
	ldrb r2, [r0, #3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #3]
	movs r0, #1
	bx lr
	.align 2, 0
	thumb_func_end MovementAction_Unknown2_Step0

	thumb_func_start MovementAction_WalkDownStartAffine_Step0
MovementAction_WalkDownStartAffine_Step0: @ 0x080950B0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r2, #1
	bl sub_080934D0
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #0
	bl StartSpriteAffineAnimIfDifferent
	adds r0, r5, #0
	adds r1, r4, #0
	bl MovementAction_WalkDownStartAffine_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_WalkDownStartAffine_Step0

	thumb_func_start MovementAction_WalkDownStartAffine_Step1
MovementAction_WalkDownStartAffine_Step1: @ 0x080950E4
	push {r4, lr}
	adds r4, r1, #0
	bl an_walk_any_2
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080950F6
	movs r0, #0
	b _08095108
_080950F6:
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095108:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_WalkDownStartAffine_Step1

	thumb_func_start MovementAction_WalkDownAffine_Step0
MovementAction_WalkDownAffine_Step0: @ 0x08095110
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r2, #1
	bl sub_080934D0
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl ChangeSpriteAffineAnimIfDifferent
	adds r0, r5, #0
	adds r1, r4, #0
	bl MovementAction_WalkDownAffine_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_WalkDownAffine_Step0

	thumb_func_start MovementAction_WalkDownAffine_Step1
MovementAction_WalkDownAffine_Step1: @ 0x08095144
	push {r4, lr}
	adds r4, r1, #0
	bl an_walk_any_2
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095156
	movs r0, #0
	b _08095168
_08095156:
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095168:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_WalkDownAffine_Step1

	thumb_func_start MovementAction_WalkLeftAffine_Step0
MovementAction_WalkLeftAffine_Step0: @ 0x08095170
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r2, #3
	movs r3, #1
	bl do_go_anim
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #2
	bl ChangeSpriteAffineAnimIfDifferent
	adds r0, r5, #0
	adds r1, r4, #0
	bl MovementAction_WalkLeftAffine_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_WalkLeftAffine_Step0

	thumb_func_start MovementAction_WalkLeftAffine_Step1
MovementAction_WalkLeftAffine_Step1: @ 0x080951A4
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080951B6
	movs r0, #0
	b _080951C8
_080951B6:
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_080951C8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_WalkLeftAffine_Step1

	thumb_func_start MovementAction_WalkRightAffine_Step0
MovementAction_WalkRightAffine_Step0: @ 0x080951D0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r2, #4
	movs r3, #1
	bl do_go_anim
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #3
	bl ChangeSpriteAffineAnimIfDifferent
	adds r0, r5, #0
	adds r1, r4, #0
	bl MovementAction_WalkRightAffine_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_WalkRightAffine_Step0

	thumb_func_start MovementAction_WalkRightAffine_Step1
MovementAction_WalkRightAffine_Step1: @ 0x08095204
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095216
	movs r0, #0
	b _08095228
_08095216:
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095228:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_WalkRightAffine_Step1

	thumb_func_start sub_08095230
sub_08095230: @ 0x08095230
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r4, r2, #0x18
	lsrs r4, r4, #0x18
	adds r1, r4, #0
	bl SetEventObjectDirection
	adds r0, r5, #0
	bl ShiftStillEventObjectCoords
	adds r0, r4, #0
	bl GetWalkInPlaceFastestMovementAction
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	adds r1, r6, #0
	bl obj_npc_animation_step
	adds r2, r6, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, #1
	strh r0, [r6, #0x32]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_08095230

	thumb_func_start MovementAction_AcroWheelieFaceDown_Step0
MovementAction_AcroWheelieFaceDown_Step0: @ 0x08095270
	push {lr}
	movs r2, #1
	bl sub_08095230
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieFaceDown_Step0

	thumb_func_start MovementAction_AcroWheelieFaceUp_Step0
MovementAction_AcroWheelieFaceUp_Step0: @ 0x08095280
	push {lr}
	movs r2, #2
	bl sub_08095230
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieFaceUp_Step0

	thumb_func_start MovementAction_AcroWheelieFaceLeft_Step0
MovementAction_AcroWheelieFaceLeft_Step0: @ 0x08095290
	push {lr}
	movs r2, #3
	bl sub_08095230
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieFaceLeft_Step0

	thumb_func_start MovementAction_AcroWheelieFaceRight_Step0
MovementAction_AcroWheelieFaceRight_Step0: @ 0x080952A0
	push {lr}
	movs r2, #4
	bl sub_08095230
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieFaceRight_Step0

	thumb_func_start MovementAction_AcroPopWheelieDown_Step0
MovementAction_AcroPopWheelieDown_Step0: @ 0x080952B0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	bl GetSlideMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroPopWheelieDown_Step0

	thumb_func_start MovementAction_AcroPopWheelieUp_Step0
MovementAction_AcroPopWheelieUp_Step0: @ 0x080952D4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	bl GetSlideMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #2
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroPopWheelieUp_Step0

	thumb_func_start MovementAction_AcroPopWheelieLeft_Step0
MovementAction_AcroPopWheelieLeft_Step0: @ 0x080952F8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #3
	bl GetSlideMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroPopWheelieLeft_Step0

	thumb_func_start MovementAction_AcroPopWheelieRight_Step0
MovementAction_AcroPopWheelieRight_Step0: @ 0x0809531C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #4
	bl GetSlideMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #4
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroPopWheelieRight_Step0

	thumb_func_start MovementAction_AcroEndWheelieFaceDown_Step0
MovementAction_AcroEndWheelieFaceDown_Step0: @ 0x08095340
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	bl GetWalkFastestMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroEndWheelieFaceDown_Step0

	thumb_func_start MovementAction_AcroEndWheelieFaceUp_Step0
MovementAction_AcroEndWheelieFaceUp_Step0: @ 0x08095364
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	bl GetWalkFastestMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #2
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroEndWheelieFaceUp_Step0

	thumb_func_start sub_08095388
sub_08095388: @ 0x08095388
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #3
	bl GetWalkFastestMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08095388

	thumb_func_start MovementAction_AcroEndWheelieFaceRight_Step0
MovementAction_AcroEndWheelieFaceRight_Step0: @ 0x080953AC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #4
	bl GetWalkFastestMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #4
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroEndWheelieFaceRight_Step0

	thumb_func_start MovementAction_UnusedAcroActionDown_Step0
MovementAction_UnusedAcroActionDown_Step0: @ 0x080953D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	bl GetWalkInPlaceFastMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_UnusedAcroActionDown_Step0

	thumb_func_start MovementAction_UnusedAcroActionUp_Step0
MovementAction_UnusedAcroActionUp_Step0: @ 0x080953F4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	bl GetWalkInPlaceFastMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #2
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_UnusedAcroActionUp_Step0

	thumb_func_start MovementAction_UnusedAcroActionLeft_Step0
MovementAction_UnusedAcroActionLeft_Step0: @ 0x08095418
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #3
	bl GetWalkInPlaceFastMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_UnusedAcroActionLeft_Step0

	thumb_func_start MovementAction_UnusedAcroActionRight_Step0
MovementAction_UnusedAcroActionRight_Step0: @ 0x0809543C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #4
	bl GetWalkInPlaceFastMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #4
	bl StartSpriteAnimInDirection
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_UnusedAcroActionRight_Step0

	thumb_func_start sub_08095460
sub_08095460: @ 0x08095460
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	bl sub_080970C0
	adds r4, #0x2c
	ldrb r1, [r4]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_08095460

	thumb_func_start sub_0809547C
sub_0809547C: @ 0x0809547C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	bl sub_080970C8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095492
	movs r0, #0
	b _080954AE
_08095492:
	adds r0, r4, #0
	bl ShiftStillEventObjectCoords
	ldrb r0, [r4]
	movs r1, #8
	orrs r0, r1
	strb r0, [r4]
	adds r2, r5, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	movs r0, #1
_080954AE:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_0809547C

	thumb_func_start MovementAction_Figure8_Step0
MovementAction_Figure8_Step0: @ 0x080954B4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl sub_08095460
	movs r0, #1
	strh r0, [r4, #0x32]
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080954D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_Figure8_Step0

	thumb_func_start sub_080954D4
sub_080954D4: @ 0x080954D4
	push {r4, lr}
	adds r4, r1, #0
	bl sub_0809547C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080954E6
	movs r0, #0
	b _080954EC
_080954E6:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_080954EC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080954D4

	thumb_func_start sub_080954F4
sub_080954F4: @ 0x080954F4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r0, [sp, #0x14]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	adds r2, r4, #0
	bl sub_08093934
	adds r0, r4, #0
	bl GetSlideMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl StartSpriteAnimIfDifferent
	adds r0, r6, #0
	bl DoShadowFieldEffect
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080954F4

	thumb_func_start MovementAction_AcroWheelieHopFaceDown_Step0
MovementAction_AcroWheelieHopFaceDown_Step0: @ 0x08095538
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieHopFaceDown_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopFaceDown_Step0

	thumb_func_start MovementAction_AcroWheelieHopFaceDown_Step1
MovementAction_AcroWheelieHopFaceDown_Step1: @ 0x08095564
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095578
	movs r0, #0
	b _08095588
_08095578:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08095588:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopFaceDown_Step1

	thumb_func_start MovementAction_AcroWheelieHopFaceUp_Step0
MovementAction_AcroWheelieHopFaceUp_Step0: @ 0x08095590
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieHopFaceUp_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopFaceUp_Step0

	thumb_func_start MovementAction_AcroWheelieHopFaceUp_Step1
MovementAction_AcroWheelieHopFaceUp_Step1: @ 0x080955BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080955D0
	movs r0, #0
	b _080955E0
_080955D0:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_080955E0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopFaceUp_Step1

	thumb_func_start MovementAction_AcroWheelieHopFaceLeft_Step0
MovementAction_AcroWheelieHopFaceLeft_Step0: @ 0x080955E8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	movs r3, #0
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieHopFaceLeft_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopFaceLeft_Step0

	thumb_func_start MovementAction_AcroWheelieHopFaceLeft_Step1
MovementAction_AcroWheelieHopFaceLeft_Step1: @ 0x08095614
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095628
	movs r0, #0
	b _08095638
_08095628:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08095638:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopFaceLeft_Step1

	thumb_func_start MovementAction_AcroWheelieHopFaceRight_Step0
MovementAction_AcroWheelieHopFaceRight_Step0: @ 0x08095640
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #0
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieHopFaceRight_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopFaceRight_Step0

	thumb_func_start MovementAction_AcroWheelieHopFaceRight_Step1
MovementAction_AcroWheelieHopFaceRight_Step1: @ 0x0809566C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095680
	movs r0, #0
	b _08095690
_08095680:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08095690:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopFaceRight_Step1

	thumb_func_start MovementAction_AcroWheelieHopDown_Step0
MovementAction_AcroWheelieHopDown_Step0: @ 0x08095698
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieHopDown_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopDown_Step0

	thumb_func_start MovementAction_AcroWheelieHopDown_Step1
MovementAction_AcroWheelieHopDown_Step1: @ 0x080956C4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080956D8
	movs r0, #0
	b _080956E8
_080956D8:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_080956E8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopDown_Step1

	thumb_func_start MovementAction_AcroWheelieHopUp_Step0
MovementAction_AcroWheelieHopUp_Step0: @ 0x080956F0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #1
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieHopUp_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopUp_Step0

	thumb_func_start MovementAction_AcroWheelieHopUp_Step1
MovementAction_AcroWheelieHopUp_Step1: @ 0x0809571C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095730
	movs r0, #0
	b _08095740
_08095730:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08095740:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopUp_Step1

	thumb_func_start MovementAction_AcroWheelieHopLeft_Step0
MovementAction_AcroWheelieHopLeft_Step0: @ 0x08095748
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	movs r3, #1
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieHopLeft_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopLeft_Step0

	thumb_func_start MovementAction_AcroWheelieHopLeft_Step1
MovementAction_AcroWheelieHopLeft_Step1: @ 0x08095774
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095788
	movs r0, #0
	b _08095798
_08095788:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08095798:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopLeft_Step1

	thumb_func_start MovementAction_AcroWheelieHopRight_Step0
MovementAction_AcroWheelieHopRight_Step0: @ 0x080957A0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #1
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieHopRight_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopRight_Step0

	thumb_func_start MovementAction_AcroWheelieHopRight_Step1
MovementAction_AcroWheelieHopRight_Step1: @ 0x080957CC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080957E0
	movs r0, #0
	b _080957F0
_080957E0:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_080957F0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieHopRight_Step1

	thumb_func_start MovementAction_AcroWheelieJumpDown_Step0
MovementAction_AcroWheelieJumpDown_Step0: @ 0x080957F8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #2
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieJumpDown_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieJumpDown_Step0

	thumb_func_start MovementAction_AcroWheelieJumpDown_Step1
MovementAction_AcroWheelieJumpDown_Step1: @ 0x08095824
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095838
	movs r0, #0
	b _08095848
_08095838:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08095848:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieJumpDown_Step1

	thumb_func_start MovementAction_AcroWheelieJumpUp_Step0
MovementAction_AcroWheelieJumpUp_Step0: @ 0x08095850
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #2
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieJumpUp_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieJumpUp_Step0

	thumb_func_start MovementAction_AcroWheelieJumpUp_Step1
MovementAction_AcroWheelieJumpUp_Step1: @ 0x0809587C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095890
	movs r0, #0
	b _080958A0
_08095890:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_080958A0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieJumpUp_Step1

	thumb_func_start MovementAction_AcroWheelieJumpLeft_Step0
MovementAction_AcroWheelieJumpLeft_Step0: @ 0x080958A8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	movs r3, #2
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieJumpLeft_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieJumpLeft_Step0

	thumb_func_start MovementAction_AcroWheelieJumpLeft_Step1
MovementAction_AcroWheelieJumpLeft_Step1: @ 0x080958D4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080958E8
	movs r0, #0
	b _080958F8
_080958E8:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_080958F8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieJumpLeft_Step1

	thumb_func_start MovementAction_AcroWheelieJumpRight_Step0
MovementAction_AcroWheelieJumpRight_Step0: @ 0x08095900
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	movs r3, #2
	bl sub_080954F4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieJumpRight_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieJumpRight_Step0

	thumb_func_start MovementAction_AcroWheelieJumpRight_Step1
MovementAction_AcroWheelieJumpRight_Step1: @ 0x0809592C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08093B20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095940
	movs r0, #0
	b _08095950
_08095940:
	ldrb r0, [r4, #2]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r4, #2]
	movs r0, #2
	strh r0, [r5, #0x32]
	movs r0, #1
_08095950:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieJumpRight_Step1

	thumb_func_start MovementAction_AcroWheelieInPlaceDown_Step0
MovementAction_AcroWheelieInPlaceDown_Step0: @ 0x08095958
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #1
	bl GetWalkInPlaceFastestMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #8
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl sub_08093EC4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_WalkInPlace_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieInPlaceDown_Step0

	thumb_func_start MovementAction_AcroWheelieInPlaceUp_Step0
MovementAction_AcroWheelieInPlaceUp_Step0: @ 0x08095990
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	bl GetWalkInPlaceFastestMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #8
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #2
	bl sub_08093EC4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_WalkInPlace_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieInPlaceUp_Step0

	thumb_func_start MovementAction_AcroWheelieInPlaceLeft_Step0
MovementAction_AcroWheelieInPlaceLeft_Step0: @ 0x080959C8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #3
	bl GetWalkInPlaceFastestMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #8
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl sub_08093EC4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_WalkInPlace_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieInPlaceLeft_Step0

	thumb_func_start MovementAction_AcroWheelieInPlaceRight_Step0
MovementAction_AcroWheelieInPlaceRight_Step0: @ 0x08095A00
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #4
	bl GetWalkInPlaceFastestMovementAction
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #8
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #4
	bl sub_08093EC4
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_WalkInPlace_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieInPlaceRight_Step0

	thumb_func_start sub_08095A38
sub_08095A38: @ 0x08095A38
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	bl npc_apply_direction
	ldrb r0, [r5, #0x18]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	bl GetSlideMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	adds r0, r4, #0
	movs r1, #0
	bl SeekSpriteAnim
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08095A38

	thumb_func_start sub_08095A70
sub_08095A70: @ 0x08095A70
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #1
	movs r3, #1
	bl sub_08095A38
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroPopWheelieMoveDown_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08095A70

	thumb_func_start MovementAction_AcroPopWheelieMoveDown_Step1
MovementAction_AcroPopWheelieMoveDown_Step1: @ 0x08095A90
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095AA2
	movs r0, #0
	b _08095AA8
_08095AA2:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095AA8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroPopWheelieMoveDown_Step1

	thumb_func_start sub_08095AB0
sub_08095AB0: @ 0x08095AB0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #2
	movs r3, #1
	bl sub_08095A38
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroPopWheelieMoveUp_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08095AB0

	thumb_func_start MovementAction_AcroPopWheelieMoveUp_Step1
MovementAction_AcroPopWheelieMoveUp_Step1: @ 0x08095AD0
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095AE2
	movs r0, #0
	b _08095AE8
_08095AE2:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095AE8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroPopWheelieMoveUp_Step1

	thumb_func_start sub_08095AF0
sub_08095AF0: @ 0x08095AF0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #3
	movs r3, #1
	bl sub_08095A38
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroPopWheelieMoveLeft_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08095AF0

	thumb_func_start MovementAction_AcroPopWheelieMoveLeft_Step1
MovementAction_AcroPopWheelieMoveLeft_Step1: @ 0x08095B10
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095B22
	movs r0, #0
	b _08095B28
_08095B22:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095B28:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroPopWheelieMoveLeft_Step1

	thumb_func_start sub_08095B30
sub_08095B30: @ 0x08095B30
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #4
	movs r3, #1
	bl sub_08095A38
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroPopWheelieMoveRight_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08095B30

	thumb_func_start MovementAction_AcroPopWheelieMoveRight_Step1
MovementAction_AcroPopWheelieMoveRight_Step1: @ 0x08095B50
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095B62
	movs r0, #0
	b _08095B68
_08095B62:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095B68:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroPopWheelieMoveRight_Step1

	thumb_func_start sub_08095B70
sub_08095B70: @ 0x08095B70
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	bl npc_apply_direction
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	bl GetWalkInPlaceFastestMovementAction
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	bl npc_apply_anim_looping
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08095B70

	thumb_func_start MovementAction_AcroWheelieMoveDown_Step0
MovementAction_AcroWheelieMoveDown_Step0: @ 0x08095BA0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #1
	movs r3, #1
	bl sub_08095B70
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieMoveDown_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroWheelieMoveDown_Step0

	thumb_func_start MovementAction_AcroWheelieMoveDown_Step1
MovementAction_AcroWheelieMoveDown_Step1: @ 0x08095BC0
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095BD2
	movs r0, #0
	b _08095BD8
_08095BD2:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095BD8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieMoveDown_Step1

	thumb_func_start MovementAction_AcroWheelieMoveUp_Step0
MovementAction_AcroWheelieMoveUp_Step0: @ 0x08095BE0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #2
	movs r3, #1
	bl sub_08095B70
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieMoveUp_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroWheelieMoveUp_Step0

	thumb_func_start MovementAction_AcroWheelieMoveUp_Step1
MovementAction_AcroWheelieMoveUp_Step1: @ 0x08095C00
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095C12
	movs r0, #0
	b _08095C18
_08095C12:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095C18:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieMoveUp_Step1

	thumb_func_start MovementAction_AcroWheelieMoveLeft_Step0
MovementAction_AcroWheelieMoveLeft_Step0: @ 0x08095C20
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #3
	movs r3, #1
	bl sub_08095B70
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieMoveLeft_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroWheelieMoveLeft_Step0

	thumb_func_start MovementAction_AcroWheelieMoveLeft_Step1
MovementAction_AcroWheelieMoveLeft_Step1: @ 0x08095C40
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095C52
	movs r0, #0
	b _08095C58
_08095C52:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095C58:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieMoveLeft_Step1

	thumb_func_start MovementAction_AcroWheelieMoveRight_Step0
MovementAction_AcroWheelieMoveRight_Step0: @ 0x08095C60
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #4
	movs r3, #1
	bl sub_08095B70
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroWheelieMoveRight_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroWheelieMoveRight_Step0

	thumb_func_start MovementAction_AcroWheelieMoveRight_Step1
MovementAction_AcroWheelieMoveRight_Step1: @ 0x08095C80
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095C92
	movs r0, #0
	b _08095C98
_08095C92:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095C98:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroWheelieMoveRight_Step1

	thumb_func_start sub_08095CA0
sub_08095CA0: @ 0x08095CA0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	bl npc_apply_direction
	ldrb r0, [r5, #0x18]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	bl GetWalkFastestMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	adds r0, r4, #0
	movs r1, #0
	bl SeekSpriteAnim
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08095CA0

	thumb_func_start MovementAction_AcroEndWheelieMoveDown_Step0
MovementAction_AcroEndWheelieMoveDown_Step0: @ 0x08095CD8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #1
	movs r3, #1
	bl sub_08095CA0
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroEndWheelieMoveDown_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroEndWheelieMoveDown_Step0

	thumb_func_start MovementAction_AcroEndWheelieMoveDown_Step1
MovementAction_AcroEndWheelieMoveDown_Step1: @ 0x08095CF8
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095D0A
	movs r0, #0
	b _08095D10
_08095D0A:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095D10:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroEndWheelieMoveDown_Step1

	thumb_func_start MovementAction_AcroEndWheelieMoveUp_Step0
MovementAction_AcroEndWheelieMoveUp_Step0: @ 0x08095D18
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #2
	movs r3, #1
	bl sub_08095CA0
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroEndWheelieMoveUp_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroEndWheelieMoveUp_Step0

	thumb_func_start MovementAction_AcroEndWheelieMoveUp_Step1
MovementAction_AcroEndWheelieMoveUp_Step1: @ 0x08095D38
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095D4A
	movs r0, #0
	b _08095D50
_08095D4A:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095D50:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroEndWheelieMoveUp_Step1

	thumb_func_start MovementAction_AcroEndWheelieMoveLeft_Step0
MovementAction_AcroEndWheelieMoveLeft_Step0: @ 0x08095D58
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #3
	movs r3, #1
	bl sub_08095CA0
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroEndWheelieMoveLeft_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroEndWheelieMoveLeft_Step0

	thumb_func_start MovementAction_AcroEndWheelieMoveLeft_Step1
MovementAction_AcroEndWheelieMoveLeft_Step1: @ 0x08095D78
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095D8A
	movs r0, #0
	b _08095D90
_08095D8A:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095D90:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroEndWheelieMoveLeft_Step1

	thumb_func_start MovementAction_AcroEndWheelieMoveRight_Step0
MovementAction_AcroEndWheelieMoveRight_Step0: @ 0x08095D98
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #4
	movs r3, #1
	bl sub_08095CA0
	adds r0, r4, #0
	adds r1, r5, #0
	bl MovementAction_AcroEndWheelieMoveRight_Step1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_AcroEndWheelieMoveRight_Step0

	thumb_func_start MovementAction_AcroEndWheelieMoveRight_Step1
MovementAction_AcroEndWheelieMoveRight_Step1: @ 0x08095DB8
	push {r4, lr}
	adds r4, r1, #0
	bl npc_obj_ministep_stop_on_arrival
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08095DCA
	movs r0, #0
	b _08095DD0
_08095DCA:
	movs r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
_08095DD0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_AcroEndWheelieMoveRight_Step1

	thumb_func_start MovementAction_Levitate_Step0
MovementAction_Levitate_Step0: @ 0x08095DD8
	push {r4, lr}
	adds r4, r1, #0
	bl CreateLevitateMovementTask
	movs r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_Levitate_Step0

	thumb_func_start MovementAction_StopLevitate_Step0
MovementAction_StopLevitate_Step0: @ 0x08095DEC
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #0x1b]
	bl DestroyExtraMovementTask
	movs r0, #0
	strh r0, [r4, #0x26]
	movs r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_StopLevitate_Step0

	thumb_func_start MovementAction_DestroyExtraTaskIfAtTop_Step0
MovementAction_DestroyExtraTaskIfAtTop_Step0: @ 0x08095E04
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	movs r1, #0x26
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _08095E16
	movs r0, #0
	b _08095E20
_08095E16:
	ldrb r0, [r2, #0x1b]
	bl DestroyExtraMovementTask
	movs r0, #1
	strh r0, [r4, #0x32]
_08095E20:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_DestroyExtraTaskIfAtTop_Step0

	thumb_func_start sub_08095E28
sub_08095E28: @ 0x08095E28
	movs r0, #1
	bx lr
	thumb_func_end sub_08095E28

	thumb_func_start MovementAction_PauseSpriteAnim
MovementAction_PauseSpriteAnim: @ 0x08095E2C
	adds r1, #0x2c
	ldrb r0, [r1]
	movs r2, #0x40
	orrs r0, r2
	strb r0, [r1]
	movs r0, #1
	bx lr
	.align 2, 0
	thumb_func_end MovementAction_PauseSpriteAnim

	thumb_func_start UpdateEventObjectSpriteAnimPause
UpdateEventObjectSpriteAnimPause: @ 0x08095E3C
	push {lr}
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _08095E52
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r0]
_08095E52:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end UpdateEventObjectSpriteAnimPause

	thumb_func_start TryEnableEventObjectAnim
TryEnableEventObjectAnim: @ 0x08095E58
	push {r4, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r0, r3, #0x1c
	cmp r0, #0
	bge _08095E80
	adds r2, r1, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r3
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #1]
_08095E80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end TryEnableEventObjectAnim

	thumb_func_start UpdateEventObjectVisibility
UpdateEventObjectVisibility: @ 0x08095E88
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl sub_08095EA0
	adds r0, r4, #0
	adds r1, r5, #0
	bl UpdateEventObjSpriteVisibility
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end UpdateEventObjectVisibility

	thumb_func_start sub_08095EA0
sub_08095EA0: @ 0x08095EA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r1, [r5, #1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r5, #1]
	ldrb r0, [r5, #5]
	bl GetObjectEventGraphicsInfo
	adds r6, r0, #0
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08095F04
	ldrh r1, [r4, #0x24]
	ldrh r0, [r4, #0x20]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r2, _08095EFC
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r1, [r4, #0x26]
	ldrh r0, [r4, #0x22]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r2, _08095F00
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	b _08095F2C
	.align 2, 0
_08095EFC: .4byte 0x02021B38
_08095F00: .4byte 0x02021B3A
_08095F04:
	ldrh r1, [r4, #0x24]
	ldrh r0, [r4, #0x20]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrh r1, [r4, #0x26]
	ldrh r0, [r4, #0x22]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
_08095F2C:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r6, #8]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrh r0, [r6, #0xa]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	bgt _08095F54
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x10
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08095F5C
_08095F54:
	ldrb r0, [r5, #1]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r5, #1]
_08095F5C:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xaf
	bgt _08095F70
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x10
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08095F78
_08095F70:
	ldrb r0, [r5, #1]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r5, #1]
_08095F78:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08095EA0

	thumb_func_start UpdateEventObjSpriteVisibility
UpdateEventObjSpriteVisibility: @ 0x08095F80
	push {lr}
	adds r2, r1, #0
	adds r2, #0x3e
	ldrb r1, [r2]
	movs r3, #5
	rsbs r3, r3, #0
	ands r3, r1
	strb r3, [r2]
	ldrb r1, [r0, #1]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _08095FA2
	movs r1, #4
	adds r0, r3, #0
	orrs r0, r1
	strb r0, [r2]
_08095FA2:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end UpdateEventObjSpriteVisibility

	thumb_func_start GetAllGroundEffectFlags_OnSpawn
GetAllGroundEffectFlags_OnSpawn: @ 0x08095FA8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl EventObjectUpdateMetatileBehaviors
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_Reflection
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_TallGrassOnSpawn
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0809615C
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_SandHeap
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_ShallowFlowingWater
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_ShortGrass
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_HotSprings
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end GetAllGroundEffectFlags_OnSpawn

	thumb_func_start GetAllGroundEffectFlags_OnBeginStep
GetAllGroundEffectFlags_OnBeginStep: @ 0x08095FF0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl EventObjectUpdateMetatileBehaviors
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_Reflection
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_LongGrassOnSpawn
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_LongGrassOnBeginStep
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_Tracks
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_SandHeap
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_ShallowFlowingWater
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_Puddle
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_ShortGrass
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_HotSprings
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end GetAllGroundEffectFlags_OnBeginStep

	thumb_func_start GetAllGroundEffectFlags_OnFinishStep
GetAllGroundEffectFlags_OnFinishStep: @ 0x08096048
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl EventObjectUpdateMetatileBehaviors
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_ShallowFlowingWater
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_SandHeap
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_Puddle
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_Ripple
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_ShortGrass
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_HotSprings
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_Seaweed
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetGroundEffectFlags_JumpLanding
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end GetAllGroundEffectFlags_OnFinishStep

	thumb_func_start EventObjectUpdateMetatileBehaviors
EventObjectUpdateMetatileBehaviors: @ 0x08096098
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	movs r2, #0x16
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	strb r0, [r4, #0x1f]
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	movs r2, #0x12
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	strb r0, [r4, #0x1e]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end EventObjectUpdateMetatileBehaviors

	thumb_func_start GetGroundEffectFlags_Reflection
GetGroundEffectFlags_Reflection: @ 0x080960C0
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08096104
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	adds r0, r4, #0
	bl EventObjectCheckForReflectiveSurface
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08096108
	ldrb r1, [r4, #2]
	lsls r0, r1, #0x1e
	cmp r0, #0
	blt _08096112
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #2]
	subs r0, r2, #1
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r5]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r5]
	b _08096112
	.align 2, 0
_08096104: .4byte 0x084E6A30
_08096108:
	ldrb r1, [r4, #2]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #2]
_08096112:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetGroundEffectFlags_Reflection

	thumb_func_start GetGroundEffectFlags_TallGrassOnSpawn
GetGroundEffectFlags_TallGrassOnSpawn: @ 0x0809611C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #0x1e]
	bl MetatileBehavior_IsTallGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096134
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_08096134:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetGroundEffectFlags_TallGrassOnSpawn

	thumb_func_start GetGroundEffectFlags_LongGrassOnSpawn
GetGroundEffectFlags_LongGrassOnSpawn: @ 0x0809613C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #0x1e]
	bl MetatileBehavior_IsTallGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096154
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
_08096154:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetGroundEffectFlags_LongGrassOnSpawn

	thumb_func_start sub_0809615C
sub_0809615C: @ 0x0809615C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #0x1e]
	bl MetatileBehavior_IsLongGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096174
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	str r0, [r4]
_08096174:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0809615C

	thumb_func_start GetGroundEffectFlags_LongGrassOnBeginStep
GetGroundEffectFlags_LongGrassOnBeginStep: @ 0x0809617C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #0x1e]
	bl MetatileBehavior_IsLongGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096194
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	str r0, [r4]
_08096194:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetGroundEffectFlags_LongGrassOnBeginStep

	thumb_func_start GetGroundEffectFlags_Tracks
GetGroundEffectFlags_Tracks: @ 0x0809619C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsDeepSand
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080961B6
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #1
	b _080961D2
_080961B6:
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsSandOrDeepSand
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080961CE
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsFootprints
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080961D6
_080961CE:
	ldr r0, [r5]
	movs r1, #0x80
_080961D2:
	orrs r0, r1
	str r0, [r5]
_080961D6:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_Tracks

	thumb_func_start GetGroundEffectFlags_SandHeap
GetGroundEffectFlags_SandHeap: @ 0x080961DC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #0x1e]
	bl MetatileBehavior_IsDeepSand
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809621A
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsDeepSand
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809621A
	ldrb r1, [r4, #2]
	lsls r0, r1, #0x1b
	cmp r0, #0
	blt _08096224
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #2]
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r5]
	b _08096224
_0809621A:
	ldrb r1, [r4, #2]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #2]
_08096224:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetGroundEffectFlags_SandHeap

	thumb_func_start GetGroundEffectFlags_ShallowFlowingWater
GetGroundEffectFlags_ShallowFlowingWater: @ 0x0809622C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #0x1e]
	bl MetatileBehavior_IsShallowFlowingWater
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809624A
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsShallowFlowingWater
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08096262
_0809624A:
	ldrb r0, [r4, #0x1e]
	bl MetatileBehavior_IsPacifidlogLog
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096280
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsPacifidlogLog
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096280
_08096262:
	ldrb r1, [r4, #2]
	lsls r0, r1, #0x1c
	cmp r0, #0
	blt _0809628A
	movs r0, #9
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #2]
	ldr r0, [r5]
	movs r1, #0x40
	orrs r0, r1
	str r0, [r5]
	b _0809628A
_08096280:
	ldrb r1, [r4, #2]
	movs r0, #9
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #2]
_0809628A:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_ShallowFlowingWater

	thumb_func_start GetGroundEffectFlags_Puddle
GetGroundEffectFlags_Puddle: @ 0x08096290
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #0x1e]
	bl MetatileBehavior_IsPuddle
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080962B8
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsPuddle
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080962B8
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r5]
_080962B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetGroundEffectFlags_Puddle

	thumb_func_start GetGroundEffectFlags_Ripple
GetGroundEffectFlags_Ripple: @ 0x080962C0
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #0x1e]
	bl MetatileBehavior_HasRipples
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080962DA
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r4]
_080962DA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_Ripple

	thumb_func_start GetGroundEffectFlags_ShortGrass
GetGroundEffectFlags_ShortGrass: @ 0x080962E0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #0x1e]
	bl MetatileBehavior_IsShortGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809631E
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsShortGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809631E
	ldrb r1, [r4, #2]
	lsls r0, r1, #0x1d
	cmp r0, #0
	blt _08096328
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #2]
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xa
	orrs r0, r1
	str r0, [r5]
	b _08096328
_0809631E:
	ldrb r1, [r4, #2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #2]
_08096328:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetGroundEffectFlags_ShortGrass

	thumb_func_start GetGroundEffectFlags_HotSprings
GetGroundEffectFlags_HotSprings: @ 0x08096330
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #0x1e]
	bl MetatileBehavior_IsHotSprings
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809636E
	ldrb r0, [r4, #0x1f]
	bl MetatileBehavior_IsHotSprings
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809636E
	ldrb r1, [r4, #2]
	lsls r0, r1, #0x1a
	cmp r0, #0
	blt _08096378
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r4, #2]
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xb
	orrs r0, r1
	str r0, [r5]
	b _08096378
_0809636E:
	ldrb r1, [r4, #2]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #2]
_08096378:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetGroundEffectFlags_HotSprings

	thumb_func_start GetGroundEffectFlags_Seaweed
GetGroundEffectFlags_Seaweed: @ 0x08096380
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #0x1e]
	bl MetatileBehavior_IsSeaweed
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809639A
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [r4]
_0809639A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_Seaweed

	thumb_func_start GetGroundEffectFlags_JumpLanding
GetGroundEffectFlags_JumpLanding: @ 0x080963A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7]
	ldr r1, _080963DC
	ands r0, r1
	cmp r0, #0x20
	bne _080963F2
	movs r5, #0
	ldr r0, _080963E0
	mov r8, r0
_080963BA:
	lsls r4, r5, #2
	mov r0, r8
	adds r1, r4, r0
	ldrb r0, [r7, #0x1e]
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080963E8
	ldr r0, _080963E4
	adds r0, r4, r0
	ldr r1, [r6]
	ldr r0, [r0]
	orrs r1, r0
	str r1, [r6]
	b _080963F2
	.align 2, 0
_080963DC: .4byte 0x02000020
_080963E0: .4byte 0x084E6A38
_080963E4: .4byte 0x084E6A50
_080963E8:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #5
	bls _080963BA
_080963F2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end GetGroundEffectFlags_JumpLanding

	thumb_func_start EventObjectCheckForReflectiveSurface
EventObjectCheckForReflectiveSurface: @ 0x080963FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #5]
	bl GetObjectEventGraphicsInfo
	movs r2, #8
	ldrsh r1, [r0, r2]
	adds r1, #8
	lsls r1, r1, #0xc
	lsrs r1, r1, #0x10
	str r1, [sp]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	adds r0, #8
	lsls r0, r0, #0xc
	movs r4, #0
	lsrs r2, r0, #0x10
	str r2, [sp, #4]
	asrs r0, r0, #0x10
	cmp r4, r0
	blt _08096432
	b _08096538
_08096432:
	movs r0, #1
	mov sl, r0
_08096436:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	movs r2, #0x12
	ldrsh r1, [r5, r2]
	add r1, sl
	lsls r4, r4, #0x10
	asrs r6, r4, #0x10
	adds r1, r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r4
	cmp r0, #0
	bne _0809653A
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	movs r2, #0x16
	ldrsh r1, [r5, r2]
	add r1, sl
	adds r1, r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0809653A
	movs r2, #1
	ldr r1, [sp]
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	mov r8, r0
	cmp r2, r1
	bge _08096526
	movs r0, #0x80
	lsls r0, r0, #9
	asrs r7, r0, #0x10
_08096490:
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	lsls r1, r2, #0x10
	asrs r4, r1, #0x10
	adds r0, r0, r4
	movs r2, #0x12
	ldrsh r1, [r5, r2]
	adds r1, r1, r7
	adds r1, r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0809653A
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	subs r0, r0, r4
	movs r2, #0x12
	ldrsh r1, [r5, r2]
	adds r1, r1, r7
	adds r1, r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0809653A
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	adds r0, r0, r4
	movs r2, #0x16
	ldrsh r1, [r5, r2]
	adds r1, r1, r7
	adds r1, r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0809653A
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	subs r0, r0, r4
	movs r2, #0x16
	ldrsh r1, [r5, r2]
	adds r1, r1, r7
	adds r1, r1, r6
	bl MapGridGetMetatileBehaviorAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetReflectionTypeByMetatileBehavior
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _0809653A
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r0, r8
	blt _08096490
_08096526:
	movs r1, #0x80
	lsls r1, r1, #9
	add r1, sb
	lsrs r4, r1, #0x10
	ldr r2, [sp, #4]
	lsls r0, r2, #0x10
	cmp r1, r0
	bge _08096538
	b _08096436
_08096538:
	movs r0, #0
_0809653A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end EventObjectCheckForReflectiveSurface

	thumb_func_start GetReflectionTypeByMetatileBehavior
GetReflectionTypeByMetatileBehavior: @ 0x0809654C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	bl MetatileBehavior_IsIce_2
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096562
	movs r0, #1
	b _08096574
_08096562:
	adds r0, r4, #0
	bl MetatileBehavior_IsReflective
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08096572
	movs r0, #0
	b _08096574
_08096572:
	movs r0, #2
_08096574:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetReflectionTypeByMetatileBehavior

	thumb_func_start GetLedgeJumpDirection
GetLedgeJumpDirection: @ 0x0809657C
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	cmp r4, #0
	beq _080965C2
	cmp r4, #4
	bls _08096598
	subs r0, r4, #4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08096598:
	subs r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl MapGridGetMetatileBehaviorAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080965C8
	lsls r1, r4, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080965CC
_080965C2:
	movs r0, #0
	b _080965D2
	.align 2, 0
_080965C8: .4byte 0x084E6A68
_080965CC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080965D2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetLedgeJumpDirection

	thumb_func_start SetEventObjectSpriteOamTableForLongGrass
SetEventObjectSpriteOamTableForLongGrass: @ 0x080965D8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r5]
	lsls r0, r0, #0x1b
	cmp r0, #0
	blt _0809662C
	ldrb r0, [r5, #0x1e]
	bl MetatileBehavior_IsLongGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809662C
	ldrb r0, [r5, #0x1f]
	bl MetatileBehavior_IsLongGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809662C
	adds r4, #0x42
	ldrb r1, [r4]
	movs r6, #0x40
	rsbs r6, r6, #0
	adds r0, r6, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #4
	bl ElevationToPriority
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0809662C
	ldrb r0, [r4]
	adds r1, r6, #0
	ands r1, r0
	movs r0, #5
	orrs r1, r0
	strb r1, [r4]
_0809662C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SetEventObjectSpriteOamTableForLongGrass

	thumb_func_start IsZCoordMismatchAt
IsZCoordMismatchAt: @ 0x08096634
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r1, r2, #0x10
	cmp r4, #0
	beq _08096662
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl MapGridGetElevationAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08096662
	cmp r0, #0xf
	beq _08096662
	cmp r0, r4
	bne _08096666
_08096662:
	movs r0, #0
	b _08096668
_08096666:
	movs r0, #1
_08096668:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsZCoordMismatchAt

	thumb_func_start UpdateEventObjectZCoordAndPriority
UpdateEventObjectZCoordAndPriority: @ 0x08096670
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #3]
	lsls r0, r0, #0x1d
	cmp r0, #0
	blt _080966BE
	adds r0, r4, #0
	bl EventObjectUpdateZCoord
	ldr r1, _080966C4
	ldrb r2, [r4, #0xb]
	lsls r2, r2, #0x18
	lsrs r0, r2, #0x1c
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r4, r5, #0
	adds r4, #0x42
	movs r1, #0x3f
	ands r1, r0
	ldrb r3, [r4]
	movs r0, #0x40
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	ldr r0, _080966C8
	lsrs r2, r2, #0x1c
	adds r2, r2, r0
	movs r0, #3
	ldrb r1, [r2]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #5]
_080966BE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080966C4: .4byte 0x084E6A98
_080966C8: .4byte 0x084E6A88
	thumb_func_end UpdateEventObjectZCoordAndPriority

	thumb_func_start InitObjectPriorityByZCoord
InitObjectPriorityByZCoord: @ 0x080966CC
	push {r4, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _08096710
	adds r2, r1, r2
	ldrb r2, [r2]
	movs r3, #0x42
	adds r3, r3, r0
	mov ip, r3
	movs r3, #0x3f
	ands r3, r2
	mov r2, ip
	ldrb r4, [r2]
	movs r2, #0x40
	rsbs r2, r2, #0
	ands r2, r4
	orrs r2, r3
	mov r3, ip
	strb r2, [r3]
	ldr r2, _08096714
	adds r1, r1, r2
	movs r3, #3
	ldrb r2, [r1]
	ands r2, r3
	lsls r2, r2, #2
	ldrb r3, [r0, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, #5]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096710: .4byte 0x084E6A98
_08096714: .4byte 0x084E6A88
	thumb_func_end InitObjectPriorityByZCoord

	thumb_func_start ElevationToPriority
ElevationToPriority: @ 0x08096718
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08096724
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08096724: .4byte 0x084E6A88
	thumb_func_end ElevationToPriority

	thumb_func_start EventObjectUpdateZCoord
EventObjectUpdateZCoord: @ 0x08096728
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	movs r2, #0x12
	ldrsh r1, [r4, r2]
	bl MapGridGetElevationAt
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	movs r2, #0x16
	ldrsh r1, [r4, r2]
	bl MapGridGetElevationAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r5, #0xf
	beq _08096776
	cmp r0, #0xf
	beq _08096776
	movs r3, #0xf
	adds r0, r5, #0
	ands r0, r3
	ldrb r1, [r4, #0xb]
	movs r2, #0x10
	rsbs r2, r2, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #0xb]
	cmp r5, #0
	beq _08096776
	cmp r5, #0xf
	beq _08096776
	lsls r0, r5, #4
	ands r2, r3
	orrs r2, r0
	strb r2, [r4, #0xb]
_08096776:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end EventObjectUpdateZCoord

	thumb_func_start SetObjectSubpriorityByElevation
SetObjectSubpriorityByElevation: @ 0x0809677C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r3, r1, #0
	adds r3, #0x29
	movs r5, #0
	ldrsb r5, [r3, r5]
	ldrh r4, [r1, #0x22]
	ldr r3, _080967BC
	subs r4, r4, r5
	ldrh r3, [r3]
	adds r4, r4, r3
	adds r4, #8
	movs r3, #0xff
	ands r4, r3
	lsrs r4, r4, #4
	movs r3, #0x10
	subs r3, r3, r4
	lsls r3, r3, #0x11
	ldr r4, _080967C0
	adds r0, r0, r4
	lsrs r3, r3, #0x10
	ldrb r0, [r0]
	adds r3, r3, r0
	adds r2, r2, r3
	adds r1, #0x43
	strb r2, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080967BC: .4byte 0x02021B3A
_080967C0: .4byte 0x084E6A78
	thumb_func_end SetObjectSubpriorityByElevation

	thumb_func_start EventObjectUpdateSubpriority
EventObjectUpdateSubpriority: @ 0x080967C4
	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x1d
	cmp r0, #0
	blt _080967DA
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #4
	movs r2, #1
	bl SetObjectSubpriorityByElevation
_080967DA:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end EventObjectUpdateSubpriority

	thumb_func_start AreZCoordsCompatible
AreZCoordsCompatible: @ 0x080967E0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r0, #0
	beq _080967F6
	cmp r1, #0
	beq _080967F6
	cmp r0, r1
	bne _080967FA
_080967F6:
	movs r0, #1
	b _080967FC
_080967FA:
	movs r0, #0
_080967FC:
	pop {r1}
	bx r1
	thumb_func_end AreZCoordsCompatible

	thumb_func_start GroundEffect_SpawnOnTallGrass
GroundEffect_SpawnOnTallGrass: @ 0x08096800
	push {lr}
	ldr r3, _08096844
	movs r2, #0x10
	ldrsh r1, [r0, r2]
	str r1, [r3]
	movs r2, #0x12
	ldrsh r1, [r0, r2]
	str r1, [r3, #4]
	ldrb r1, [r0, #0xb]
	lsrs r1, r1, #4
	str r1, [r3, #8]
	movs r1, #2
	str r1, [r3, #0xc]
	ldrb r1, [r0, #8]
	lsls r1, r1, #8
	ldrb r2, [r0, #9]
	orrs r1, r2
	str r1, [r3, #0x10]
	ldrb r0, [r0, #0xa]
	str r0, [r3, #0x14]
	ldr r0, _08096848
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	lsls r0, r0, #8
	ldrb r1, [r1, #4]
	orrs r0, r1
	str r0, [r3, #0x18]
	movs r0, #1
	str r0, [r3, #0x1c]
	movs r0, #4
	bl FieldEffectStart
	pop {r0}
	bx r0
	.align 2, 0
_08096844: .4byte 0x020388A8
_08096848: .4byte 0x03005AEC
	thumb_func_end GroundEffect_SpawnOnTallGrass

	thumb_func_start GroundEffect_StepOnTallGrass
GroundEffect_StepOnTallGrass: @ 0x0809684C
	push {lr}
	ldr r3, _08096890
	movs r2, #0x10
	ldrsh r1, [r0, r2]
	str r1, [r3]
	movs r2, #0x12
	ldrsh r1, [r0, r2]
	str r1, [r3, #4]
	ldrb r1, [r0, #0xb]
	lsrs r1, r1, #4
	str r1, [r3, #8]
	movs r1, #2
	str r1, [r3, #0xc]
	ldrb r1, [r0, #8]
	lsls r1, r1, #8
	ldrb r2, [r0, #9]
	orrs r1, r2
	str r1, [r3, #0x10]
	ldrb r0, [r0, #0xa]
	str r0, [r3, #0x14]
	ldr r0, _08096894
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	lsls r0, r0, #8
	ldrb r1, [r1, #4]
	orrs r0, r1
	str r0, [r3, #0x18]
	movs r0, #0
	str r0, [r3, #0x1c]
	movs r0, #4
	bl FieldEffectStart
	pop {r0}
	bx r0
	.align 2, 0
_08096890: .4byte 0x020388A8
_08096894: .4byte 0x03005AEC
	thumb_func_end GroundEffect_StepOnTallGrass

	thumb_func_start GroundEffect_SpawnOnLongGrass
GroundEffect_SpawnOnLongGrass: @ 0x08096898
	push {lr}
	ldr r3, _080968DC
	movs r2, #0x10
	ldrsh r1, [r0, r2]
	str r1, [r3]
	movs r2, #0x12
	ldrsh r1, [r0, r2]
	str r1, [r3, #4]
	ldrb r1, [r0, #0xb]
	lsrs r1, r1, #4
	str r1, [r3, #8]
	movs r1, #2
	str r1, [r3, #0xc]
	ldrb r1, [r0, #8]
	lsls r1, r1, #8
	ldrb r2, [r0, #9]
	orrs r1, r2
	str r1, [r3, #0x10]
	ldrb r0, [r0, #0xa]
	str r0, [r3, #0x14]
	ldr r0, _080968E0
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	lsls r0, r0, #8
	ldrb r1, [r1, #4]
	orrs r0, r1
	str r0, [r3, #0x18]
	movs r0, #1
	str r0, [r3, #0x1c]
	movs r0, #0x11
	bl FieldEffectStart
	pop {r0}
	bx r0
	.align 2, 0
_080968DC: .4byte 0x020388A8
_080968E0: .4byte 0x03005AEC
	thumb_func_end GroundEffect_SpawnOnLongGrass

	thumb_func_start GroundEffect_StepOnLongGrass
GroundEffect_StepOnLongGrass: @ 0x080968E4
	push {lr}
	ldr r3, _08096928
	movs r2, #0x10
	ldrsh r1, [r0, r2]
	str r1, [r3]
	movs r2, #0x12
	ldrsh r1, [r0, r2]
	str r1, [r3, #4]
	ldrb r1, [r0, #0xb]
	lsrs r1, r1, #4
	str r1, [r3, #8]
	movs r1, #2
	str r1, [r3, #0xc]
	ldrb r1, [r0, #8]
	lsls r1, r1, #8
	ldrb r2, [r0, #9]
	orrs r1, r2
	str r1, [r3, #0x10]
	ldrb r0, [r0, #0xa]
	str r0, [r3, #0x14]
	ldr r0, _0809692C
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	lsls r0, r0, #8
	ldrb r1, [r1, #4]
	orrs r0, r1
	str r0, [r3, #0x18]
	movs r0, #0
	str r0, [r3, #0x1c]
	movs r0, #0x11
	bl FieldEffectStart
	pop {r0}
	bx r0
	.align 2, 0
_08096928: .4byte 0x020388A8
_0809692C: .4byte 0x03005AEC
	thumb_func_end GroundEffect_StepOnLongGrass

	thumb_func_start GroundEffect_WaterReflection
GroundEffect_WaterReflection: @ 0x08096930
	@ From src/event_object_movement.c
	push {lr}
	movs r2, #0
	bl SetUpReflection
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_WaterReflection

	thumb_func_start GroundEffect_IceReflection
GroundEffect_IceReflection: @ 0x0809693C
	@ From src/event_object_movement.c
	push {lr}
	movs r2, #1
	bl SetUpReflection
	pop {r0}
	bx r0
	thumb_func_end GroundEffect_IceReflection

	thumb_func_start GroundEffect_FlowingWater
GroundEffect_FlowingWater: @ 0x08096948
	push {lr}
	adds r1, r0, #0
	movs r0, #0x22
	bl sub_08097758
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GroundEffect_FlowingWater

	thumb_func_start GroundEffect_SandTracks
GroundEffect_SandTracks: @ 0x08096958
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #5]
	bl GetObjectEventGraphicsInfo
	ldr r1, _08096980
	ldrb r0, [r0, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl _call_via_r3
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096980: .4byte 0x084E6AA8
	thumb_func_end GroundEffect_SandTracks

	thumb_func_start sub_08096984
sub_08096984: @ 0x08096984
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4, #5]
	bl GetObjectEventGraphicsInfo
	ldr r1, _080969AC
	ldrb r0, [r0, #0xd]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl _call_via_r3
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080969AC: .4byte 0x084E6AA8
	thumb_func_end sub_08096984

	thumb_func_start DoTracksGroundEffect_None
DoTracksGroundEffect_None: @ 0x080969B0
	bx lr
	.align 2, 0
	thumb_func_end DoTracksGroundEffect_None

	thumb_func_start DoTracksGroundEffect_Footprints
DoTracksGroundEffect_Footprints: @ 0x080969B4
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	lsls r4, r2, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _080969FC
	mov r0, sp
	movs r2, #4
	bl memcpy
	ldr r1, _08096A00
	movs r2, #0x14
	ldrsh r0, [r5, r2]
	str r0, [r1]
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	str r0, [r1, #4]
	movs r0, #0x95
	str r0, [r1, #8]
	movs r0, #2
	str r0, [r1, #0xc]
	ldrb r0, [r5, #0x18]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	str r0, [r1, #0x10]
	lsls r4, r4, #1
	mov r1, sp
	adds r0, r1, r4
	ldrb r0, [r0]
	bl FieldEffectStart
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080969FC: .4byte 0x084E6AB4
_08096A00: .4byte 0x020388A8
	thumb_func_end DoTracksGroundEffect_Footprints

	thumb_func_start DoTracksGroundEffect_BikeTireTracks
DoTracksGroundEffect_BikeTireTracks: @ 0x08096A04
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0x14]
	cmp r1, r0
	beq _08096A46
	ldr r2, _08096A4C
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	str r0, [r2]
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	str r0, [r2, #4]
	movs r0, #0x95
	str r0, [r2, #8]
	movs r0, #2
	str r0, [r2, #0xc]
	ldr r3, _08096A50
	ldrb r1, [r4, #0x18]
	lsls r1, r1, #0x1c
	lsrs r1, r1, #0x1c
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	lsls r0, r0, #2
	subs r0, #5
	adds r1, r1, r0
	adds r1, r1, r3
	ldrb r0, [r1]
	str r0, [r2, #0x10]
	movs r0, #0x23
	bl FieldEffectStart
_08096A46:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096A4C: .4byte 0x020388A8
_08096A50: .4byte 0x084E6AB8
	thumb_func_end DoTracksGroundEffect_BikeTireTracks

	thumb_func_start sub_08096A54
sub_08096A54: @ 0x08096A54
	push {lr}
	bl DoRippleFieldEffect
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08096A54

	thumb_func_start GroundEffect_StepOnPuddle
GroundEffect_StepOnPuddle: @ 0x08096A60
	push {lr}
	adds r1, r0, #0
	movs r0, #0xf
	bl sub_08097758
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GroundEffect_StepOnPuddle

	thumb_func_start GroundEffect_SandHeap
GroundEffect_SandHeap: @ 0x08096A70
	push {lr}
	adds r1, r0, #0
	movs r0, #0x27
	bl sub_08097758
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GroundEffect_SandHeap

	thumb_func_start GroundEffect_JumpOnTallGrass
GroundEffect_JumpOnTallGrass: @ 0x08096A80
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _08096AD4
	movs r2, #0x10
	ldrsh r0, [r5, r2]
	str r0, [r1]
	movs r4, #0x12
	ldrsh r0, [r5, r4]
	str r0, [r1, #4]
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #4
	str r0, [r1, #8]
	movs r0, #2
	str r0, [r1, #0xc]
	movs r0, #0xc
	bl FieldEffectStart
	ldrb r0, [r5, #8]
	ldrb r1, [r5, #9]
	ldrb r2, [r5, #0xa]
	movs r7, #0x10
	ldrsh r3, [r5, r7]
	movs r7, #0x12
	ldrsh r4, [r5, r7]
	str r4, [sp]
	bl FindTallGrassFieldEffectSpriteId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	bne _08096ACA
	adds r0, r5, #0
	adds r1, r6, #0
	bl GroundEffect_SpawnOnTallGrass
_08096ACA:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096AD4: .4byte 0x020388A8
	thumb_func_end GroundEffect_JumpOnTallGrass

	thumb_func_start GroundEffect_JumpOnLongGrass
GroundEffect_JumpOnLongGrass: @ 0x08096AD8
	push {lr}
	ldr r2, _08096AFC
	movs r3, #0x10
	ldrsh r1, [r0, r3]
	str r1, [r2]
	movs r3, #0x12
	ldrsh r1, [r0, r3]
	str r1, [r2, #4]
	ldrb r0, [r0, #0xb]
	lsrs r0, r0, #4
	str r0, [r2, #8]
	movs r0, #2
	str r0, [r2, #0xc]
	movs r0, #0x12
	bl FieldEffectStart
	pop {r0}
	bx r0
	.align 2, 0
_08096AFC: .4byte 0x020388A8
	thumb_func_end GroundEffect_JumpOnLongGrass

	thumb_func_start GroundEffect_JumpOnShallowWater
GroundEffect_JumpOnShallowWater: @ 0x08096B00
	push {r4, lr}
	ldr r3, _08096B2C
	movs r4, #0x10
	ldrsh r2, [r0, r4]
	str r2, [r3]
	movs r4, #0x12
	ldrsh r2, [r0, r4]
	str r2, [r3, #4]
	ldrb r0, [r0, #0xb]
	lsrs r0, r0, #4
	str r0, [r3, #8]
	ldrb r0, [r1, #5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	str r0, [r3, #0xc]
	movs r0, #0x10
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096B2C: .4byte 0x020388A8
	thumb_func_end GroundEffect_JumpOnShallowWater

	thumb_func_start GroundEffect_JumpOnWater
GroundEffect_JumpOnWater: @ 0x08096B30
	push {r4, lr}
	ldr r3, _08096B5C
	movs r4, #0x10
	ldrsh r2, [r0, r4]
	str r2, [r3]
	movs r4, #0x12
	ldrsh r2, [r0, r4]
	str r2, [r3, #4]
	ldrb r0, [r0, #0xb]
	lsrs r0, r0, #4
	str r0, [r3, #8]
	ldrb r0, [r1, #5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	str r0, [r3, #0xc]
	movs r0, #0xe
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096B5C: .4byte 0x020388A8
	thumb_func_end GroundEffect_JumpOnWater

	thumb_func_start GroundEffect_JumpLandingDust
GroundEffect_JumpLandingDust: @ 0x08096B60
	push {r4, lr}
	ldr r3, _08096B8C
	movs r4, #0x10
	ldrsh r2, [r0, r4]
	str r2, [r3]
	movs r4, #0x12
	ldrsh r2, [r0, r4]
	str r2, [r3, #4]
	ldrb r0, [r0, #0xb]
	lsrs r0, r0, #4
	str r0, [r3, #8]
	ldrb r0, [r1, #5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	str r0, [r3, #0xc]
	movs r0, #0xa
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096B8C: .4byte 0x020388A8
	thumb_func_end GroundEffect_JumpLandingDust

	thumb_func_start GroundEffect_ShortGrass
GroundEffect_ShortGrass: @ 0x08096B90
	push {lr}
	adds r1, r0, #0
	movs r0, #0x29
	bl sub_08097758
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GroundEffect_ShortGrass

	thumb_func_start GroundEffect_HotSprings
GroundEffect_HotSprings: @ 0x08096BA0
	push {lr}
	adds r1, r0, #0
	movs r0, #0x2a
	bl sub_08097758
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GroundEffect_HotSprings

	thumb_func_start GroundEffect_Seaweed
GroundEffect_Seaweed: @ 0x08096BB0
	push {lr}
	ldr r2, _08096BCC
	movs r3, #0x10
	ldrsh r1, [r0, r3]
	str r1, [r2]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	str r0, [r2, #4]
	movs r0, #0x35
	bl FieldEffectStart
	pop {r0}
	bx r0
	.align 2, 0
_08096BCC: .4byte 0x020388A8
	thumb_func_end GroundEffect_Seaweed

	thumb_func_start DoFlaggedGroundEffects
DoFlaggedGroundEffects: @ 0x08096BD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	bl ObjectEventIsFarawayIslandMew
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08096BF4
	adds r0, r6, #0
	bl ShouldMewShakeGrass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08096C1C
_08096BF4:
	movs r4, #0
	ldr r0, _08096C28
	mov r8, r0
_08096BFA:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _08096C10
	lsls r0, r4, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	bl _call_via_r2
_08096C10:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsrs r5, r5, #1
	cmp r4, #0x13
	bls _08096BFA
_08096C1C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096C28: .4byte 0x084E6AC8
	thumb_func_end DoFlaggedGroundEffects

	thumb_func_start filters_out_some_ground_effects
filters_out_some_ground_effects: @ 0x08096C2C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r0, [r2]
	lsls r0, r0, #0x1b
	cmp r0, #0
	bge _08096C5A
	ldrb r1, [r2, #2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	adds r1, #8
	ands r0, r1
	subs r1, #0x18
	ands r0, r1
	strb r0, [r2, #2]
	ldr r0, [r3]
	ldr r1, _08096C60
	ands r0, r1
	str r0, [r3]
_08096C5A:
	pop {r0}
	bx r0
	.align 2, 0
_08096C60: .4byte 0xFFF9F7BD
	thumb_func_end filters_out_some_ground_effects

	thumb_func_start FilterOutStepOnPuddleGroundEffectIfJumping
FilterOutStepOnPuddleGroundEffectIfJumping: @ 0x08096C64
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bge _08096C78
	ldr r0, [r2]
	ldr r1, _08096C7C
	ands r0, r1
	str r0, [r2]
_08096C78:
	pop {r0}
	bx r0
	.align 2, 0
_08096C7C: .4byte 0xFFFFFBFF
	thumb_func_end FilterOutStepOnPuddleGroundEffectIfJumping

	thumb_func_start DoGroundEffects_OnSpawn
DoGroundEffects_OnSpawn: @ 0x08096C80
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _08096CC4
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	bl UpdateEventObjectZCoordAndPriority
	adds r0, r4, #0
	mov r1, sp
	bl GetAllGroundEffectFlags_OnSpawn
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetEventObjectSpriteOamTableForLongGrass
	ldr r2, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl DoFlaggedGroundEffects
	ldrb r1, [r4]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4]
_08096CC4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end DoGroundEffects_OnSpawn

	thumb_func_start DoGroundEffects_OnBeginStep
DoGroundEffects_OnBeginStep: @ 0x08096CCC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _08096D18
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	bl UpdateEventObjectZCoordAndPriority
	adds r0, r4, #0
	mov r1, sp
	bl GetAllGroundEffectFlags_OnBeginStep
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetEventObjectSpriteOamTableForLongGrass
	adds r0, r4, #0
	mov r1, sp
	bl filters_out_some_ground_effects
	ldr r2, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl DoFlaggedGroundEffects
	ldrb r1, [r4]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4]
_08096D18:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end DoGroundEffects_OnBeginStep

	thumb_func_start DoGroundEffects_OnFinishStep
DoGroundEffects_OnFinishStep: @ 0x08096D20
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _08096D6C
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	bl UpdateEventObjectZCoordAndPriority
	adds r0, r4, #0
	mov r1, sp
	bl GetAllGroundEffectFlags_OnFinishStep
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetEventObjectSpriteOamTableForLongGrass
	adds r0, r4, #0
	mov r1, sp
	bl FilterOutStepOnPuddleGroundEffectIfJumping
	ldr r2, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl DoFlaggedGroundEffects
	ldrb r1, [r4]
	movs r0, #9
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4]
_08096D6C:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end DoGroundEffects_OnFinishStep

	thumb_func_start FreezeEventObject
FreezeEventObject: @ 0x08096D74
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r1, [r5]
	movs r0, #0xa0
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08096DFC
	ldrb r0, [r5, #1]
	movs r4, #1
	orrs r0, r4
	strb r0, [r5, #1]
	ldr r3, _08096DF8
	ldrb r1, [r5, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x2c
	ldrb r1, [r0]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x1f
	lsls r1, r1, #7
	ldrb r2, [r5, #2]
	movs r0, #0x7f
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #2]
	ldrb r1, [r5, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x2c
	ldrb r1, [r0]
	lsrs r1, r1, #7
	ands r1, r4
	ldrb r2, [r5, #3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #3]
	ldrb r1, [r5, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r2, #0x40
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r5, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x2c
	ldrb r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strb r1, [r0]
	movs r0, #0
	b _08096DFE
	.align 2, 0
_08096DF8: .4byte 0x020205AC
_08096DFC:
	movs r0, #1
_08096DFE:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end FreezeEventObject

	thumb_func_start FreezeObjectEvents
FreezeObjectEvents: @ 0x08096E04
	push {r4, r5, lr}
	movs r4, #0
	ldr r5, _08096E38
_08096E0A:
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, r0, r5
	ldrb r0, [r1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08096E28
	ldr r0, _08096E3C
	ldrb r0, [r0, #5]
	cmp r4, r0
	beq _08096E28
	adds r0, r1, #0
	bl FreezeEventObject
_08096E28:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _08096E0A
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096E38: .4byte 0x02036FF0
_08096E3C: .4byte 0x02037230
	thumb_func_end FreezeObjectEvents

	thumb_func_start FreezeEventObjectsExceptOne
FreezeEventObjectsExceptOne: @ 0x08096E40
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #0
	ldr r6, _08096E7C
_08096E4A:
	cmp r4, r5
	beq _08096E6C
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, r0, r6
	ldrb r0, [r1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08096E6C
	ldr r0, _08096E80
	ldrb r0, [r0, #5]
	cmp r4, r0
	beq _08096E6C
	adds r0, r1, #0
	bl FreezeEventObject
_08096E6C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _08096E4A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096E7C: .4byte 0x02036FF0
_08096E80: .4byte 0x02037230
	thumb_func_end FreezeEventObjectsExceptOne

	thumb_func_start UnfreezeEventObject
UnfreezeEventObject: @ 0x08096E84
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r2, [r5]
	ldr r1, _08096EE4
	adds r0, r1, #0
	ands r0, r2
	cmp r0, r1
	bne _08096EDC
	ldrb r1, [r5, #1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r5, #1]
	ldr r4, _08096EE8
	ldrb r0, [r5, #4]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r2, [r5, #2]
	adds r1, #0x2c
	lsrs r2, r2, #7
	lsls r2, r2, #6
	ldrb r3, [r1]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r5, #4]
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r4
	ldrb r1, [r5, #3]
	lsls r1, r1, #0x1f
	lsrs r1, r1, #0x1f
	adds r2, #0x2c
	lsls r1, r1, #7
	ldrb r3, [r2]
	movs r0, #0x7f
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_08096EDC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096EE4: .4byte 0x00000101
_08096EE8: .4byte 0x020205AC
	thumb_func_end UnfreezeEventObject

	thumb_func_start UnfreezeObjectEvents
UnfreezeObjectEvents: @ 0x08096EEC
	push {r4, r5, lr}
	movs r4, #0
	ldr r5, _08096F18
_08096EF2:
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, r0, r5
	ldrb r0, [r1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08096F08
	adds r0, r1, #0
	bl UnfreezeEventObject
_08096F08:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _08096EF2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096F18: .4byte 0x02036FF0
	thumb_func_end UnfreezeObjectEvents

	thumb_func_start Step1
Step1: @ 0x08096F1C
	lsls r1, r1, #0x18
	ldr r2, _08096F38
	lsrs r1, r1, #0x16
	adds r1, r1, r2
	ldrh r2, [r1]
	ldrh r3, [r0, #0x20]
	adds r2, r2, r3
	strh r2, [r0, #0x20]
	ldrh r1, [r1, #2]
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	strh r1, [r0, #0x22]
	bx lr
	.align 2, 0
_08096F38: .4byte 0x084E5FD0
	thumb_func_end Step1

	thumb_func_start Step2
Step2: @ 0x08096F3C
	lsls r1, r1, #0x18
	ldr r2, _08096F5C
	lsrs r1, r1, #0x16
	adds r1, r1, r2
	ldrh r2, [r1]
	lsls r2, r2, #1
	ldrh r3, [r0, #0x20]
	adds r2, r2, r3
	strh r2, [r0, #0x20]
	ldrh r1, [r1, #2]
	lsls r1, r1, #1
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	strh r1, [r0, #0x22]
	bx lr
	.align 2, 0
_08096F5C: .4byte 0x084E5FD0
	thumb_func_end Step2

	thumb_func_start Step3
Step3: @ 0x08096F60
	lsls r1, r1, #0x18
	ldr r2, _08096F84
	lsrs r1, r1, #0x16
	adds r1, r1, r2
	ldrh r2, [r1]
	lsls r3, r2, #1
	adds r2, r2, r3
	ldrh r3, [r0, #0x20]
	adds r2, r2, r3
	strh r2, [r0, #0x20]
	ldrh r1, [r1, #2]
	lsls r2, r1, #1
	adds r1, r1, r2
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	strh r1, [r0, #0x22]
	bx lr
	.align 2, 0
_08096F84: .4byte 0x084E5FD0
	thumb_func_end Step3

	thumb_func_start Step4
Step4: @ 0x08096F88
	lsls r1, r1, #0x18
	ldr r2, _08096FA8
	lsrs r1, r1, #0x16
	adds r1, r1, r2
	ldrh r2, [r1]
	lsls r2, r2, #2
	ldrh r3, [r0, #0x20]
	adds r2, r2, r3
	strh r2, [r0, #0x20]
	ldrh r1, [r1, #2]
	lsls r1, r1, #2
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	strh r1, [r0, #0x22]
	bx lr
	.align 2, 0
_08096FA8: .4byte 0x084E5FD0
	thumb_func_end Step4

	thumb_func_start Step8
Step8: @ 0x08096FAC
	lsls r1, r1, #0x18
	ldr r2, _08096FCC
	lsrs r1, r1, #0x16
	adds r1, r1, r2
	ldrh r2, [r1]
	lsls r2, r2, #3
	ldrh r3, [r0, #0x20]
	adds r2, r2, r3
	strh r2, [r0, #0x20]
	ldrh r1, [r1, #2]
	lsls r1, r1, #3
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	strh r1, [r0, #0x22]
	bx lr
	.align 2, 0
_08096FCC: .4byte 0x084E5FD0
	thumb_func_end Step8

	thumb_func_start oamt_npc_ministep_reset
oamt_npc_ministep_reset: @ 0x08096FD0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #0
	strh r1, [r0, #0x34]
	strh r2, [r0, #0x36]
	strh r3, [r0, #0x38]
	bx lr
	.align 2, 0
	thumb_func_end oamt_npc_ministep_reset

	thumb_func_start obj_npc_ministep
obj_npc_ministep: @ 0x08096FE4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0809703C
	movs r0, #0x36
	ldrsh r2, [r4, r0]
	lsls r0, r2, #1
	adds r0, r0, r5
	movs r3, #0x38
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _08097044
	ldr r1, _08097040
	lsls r0, r2, #2
	adds r0, r0, r1
	movs r1, #0x38
	ldrsh r2, [r4, r1]
	ldr r0, [r0]
	lsls r2, r2, #2
	adds r2, r2, r0
	ldrh r1, [r4, #0x34]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, [r2]
	adds r0, r4, #0
	bl _call_via_r2
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
	movs r2, #0x36
	ldrsh r1, [r4, r2]
	lsls r1, r1, #1
	adds r1, r1, r5
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	blt _08097044
	movs r0, #1
	b _08097046
	.align 2, 0
_0809703C: .4byte 0x084E6BBC
_08097040: .4byte 0x084E6BA8
_08097044:
	movs r0, #0
_08097046:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end obj_npc_ministep

	thumb_func_start sub_0809704C
sub_0809704C: @ 0x0809704C
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r2, #0
	strh r1, [r0, #0x34]
	strh r2, [r0, #0x36]
	strh r2, [r0, #0x38]
	bx lr
	.align 2, 0
	thumb_func_end sub_0809704C

	thumb_func_start sub_0809705C
sub_0809705C: @ 0x0809705C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x36]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0809707C
	ldrh r1, [r4, #0x34]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl Step1
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
_0809707C:
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	cmp r0, #0xf
	bgt _0809708E
	movs r0, #0
	b _08097090
_0809708E:
	movs r0, #1
_08097090:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0809705C

	thumb_func_start GetFigure8YOffset
GetFigure8YOffset: @ 0x08097098
	ldr r1, _080970A8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr
	.align 2, 0
_080970A8: .4byte 0x084E6C0E
	thumb_func_end GetFigure8YOffset

	thumb_func_start GetFigure8XOffset
GetFigure8XOffset: @ 0x080970AC
	ldr r1, _080970BC
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr
	.align 2, 0
_080970BC: .4byte 0x084E6BC6
	thumb_func_end GetFigure8XOffset

	thumb_func_start sub_080970C0
sub_080970C0: @ 0x080970C0
	movs r1, #0
	strh r1, [r0, #0x3a]
	strh r1, [r0, #0x3c]
	bx lr
	thumb_func_end sub_080970C0

	thumb_func_start sub_080970C8
sub_080970C8: @ 0x080970C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080970FE
	cmp r0, #1
	bgt _080970E0
	cmp r0, #0
	beq _080970EA
	b _08097162
_080970E0:
	cmp r0, #2
	beq _08097126
	cmp r0, #3
	beq _0809713A
	b _08097162
_080970EA:
	movs r2, #0x3a
	ldrsh r0, [r5, r2]
	bl GetFigure8XOffset
	ldrh r1, [r5, #0x24]
	adds r0, r0, r1
	strh r0, [r5, #0x24]
	movs r2, #0x3a
	ldrsh r0, [r5, r2]
	b _08097158
_080970FE:
	ldrh r0, [r5, #0x3a]
	movs r4, #0x47
	subs r0, r4, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl GetFigure8XOffset
	ldrh r1, [r5, #0x24]
	subs r1, r1, r0
	strh r1, [r5, #0x24]
	ldrh r0, [r5, #0x3a]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl GetFigure8YOffset
	ldrh r2, [r5, #0x26]
	adds r0, r0, r2
	b _08097160
_08097126:
	movs r1, #0x3a
	ldrsh r0, [r5, r1]
	bl GetFigure8XOffset
	ldrh r1, [r5, #0x24]
	subs r1, r1, r0
	strh r1, [r5, #0x24]
	movs r2, #0x3a
	ldrsh r0, [r5, r2]
	b _08097158
_0809713A:
	ldrh r0, [r5, #0x3a]
	movs r4, #0x47
	subs r0, r4, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl GetFigure8XOffset
	ldrh r2, [r5, #0x24]
	adds r0, r0, r2
	strh r0, [r5, #0x24]
	ldrh r0, [r5, #0x3a]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
_08097158:
	bl GetFigure8YOffset
	ldrh r1, [r5, #0x26]
	adds r0, r0, r1
_08097160:
	strh r0, [r5, #0x26]
_08097162:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0x3a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x48
	bne _0809717A
	strh r1, [r5, #0x3a]
	ldrh r0, [r5, #0x3c]
	adds r0, #1
	strh r0, [r5, #0x3c]
_0809717A:
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	cmp r0, #4
	bne _08097188
	strh r1, [r5, #0x26]
	strh r1, [r5, #0x24]
	movs r6, #1
_08097188:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_080970C8

	thumb_func_start sub_08097190
sub_08097190: @ 0x08097190
	lsls r1, r1, #0x18
	ldr r2, _080971A8
	lsrs r1, r1, #0x16
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r1]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	bx lr
	.align 2, 0
_080971A8: .4byte 0x084E6C88
	thumb_func_end sub_08097190

	thumb_func_start sub_080971AC
sub_080971AC: @ 0x080971AC
	push {r4, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r4, #0
	strh r1, [r0, #0x34]
	strh r2, [r0, #0x36]
	strh r3, [r0, #0x38]
	strh r4, [r0, #0x3a]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080971AC

	thumb_func_start sub_080971CC
sub_080971CC: @ 0x080971CC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _0809724C
	mov r0, sp
	movs r2, #6
	bl memcpy
	add r5, sp, #8
	ldr r1, _08097250
	adds r0, r5, #0
	movs r2, #3
	bl memcpy
	movs r6, #0
	movs r1, #0x36
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _080971FE
	ldrh r1, [r4, #0x34]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl Step1
_080971FE:
	movs r2, #0x3a
	ldrsh r0, [r4, r2]
	movs r2, #0x36
	ldrsh r1, [r4, r2]
	adds r1, r5, r1
	ldrb r1, [r1]
	asrs r0, r1
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_08097190
	strh r0, [r4, #0x26]
	ldrh r1, [r4, #0x3a]
	adds r1, #1
	strh r1, [r4, #0x3a]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	asrs r0, r0, #0x11
	cmp r1, r0
	bne _08097238
	movs r6, #1
_08097238:
	cmp r1, r2
	blt _08097242
	movs r0, #0
	strh r0, [r4, #0x26]
	movs r6, #0xff
_08097242:
	adds r0, r6, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809724C: .4byte 0x084E6C94
_08097250: .4byte 0x084E6C9A
	thumb_func_end sub_080971CC

	thumb_func_start sub_08097254
sub_08097254: @ 0x08097254
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080972E0
	mov r0, sp
	movs r2, #6
	bl memcpy
	add r4, sp, #8
	ldr r1, _080972E4
	adds r0, r4, #0
	movs r2, #3
	bl memcpy
	movs r6, #0
	movs r1, #0x36
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq _08097290
	ldrh r1, [r5, #0x3a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08097290
	ldrh r1, [r5, #0x34]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl Step1
_08097290:
	movs r2, #0x3a
	ldrsh r0, [r5, r2]
	movs r2, #0x36
	ldrsh r1, [r5, r2]
	adds r1, r4, r1
	ldrb r1, [r1]
	asrs r0, r1
	ldrh r1, [r5, #0x38]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_08097190
	strh r0, [r5, #0x26]
	ldrh r1, [r5, #0x3a]
	adds r1, #1
	strh r1, [r5, #0x3a]
	movs r2, #0x36
	ldrsh r0, [r5, r2]
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	asrs r0, r0, #0x11
	cmp r1, r0
	bne _080972CA
	movs r6, #1
_080972CA:
	cmp r1, r2
	blt _080972D4
	movs r0, #0
	strh r0, [r5, #0x26]
	movs r6, #0xff
_080972D4:
	adds r0, r6, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080972E0: .4byte 0x084E6C9E
_080972E4: .4byte 0x084E6CA4
	thumb_func_end sub_08097254

	thumb_func_start SetMovementDelay
SetMovementDelay: @ 0x080972E8
	strh r1, [r0, #0x34]
	bx lr
	thumb_func_end SetMovementDelay

	thumb_func_start WaitForMovementDelay
WaitForMovementDelay: @ 0x080972EC
	push {lr}
	ldrh r1, [r0, #0x34]
	subs r1, #1
	strh r1, [r0, #0x34]
	lsls r1, r1, #0x10
	cmp r1, #0
	beq _080972FE
	movs r0, #0
	b _08097300
_080972FE:
	movs r0, #1
_08097300:
	pop {r1}
	bx r1
	thumb_func_end WaitForMovementDelay

	thumb_func_start SetAndStartSpriteAnim
SetAndStartSpriteAnim: @ 0x08097304
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r3, r0, #0
	adds r3, #0x2a
	strb r1, [r3]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrb r3, [r4]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r3
	strb r1, [r4]
	adds r1, r2, #0
	bl SeekSpriteAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SetAndStartSpriteAnim

	thumb_func_start SpriteAnimEnded
SpriteAnimEnded: @ 0x0809732C
	push {lr}
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809733E
	movs r0, #0
	b _08097340
_0809733E:
	movs r0, #1
_08097340:
	pop {r1}
	bx r1
	thumb_func_end SpriteAnimEnded

	thumb_func_start UpdateObjectEventSpriteInvisibility
UpdateObjectEventSpriteInvisibility: @ 0x08097344
	push {r4, r5, r6, lr}
	mov ip, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r3, ip
	adds r3, #0x3e
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080973AC
	mov r0, ip
	ldrh r1, [r0, #0x24]
	ldrh r2, [r0, #0x20]
	adds r1, r1, r2
	mov r4, ip
	adds r4, #0x28
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r2, _080973A4
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, ip
	ldrh r1, [r0, #0x26]
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	subs r3, #0x15
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldr r2, _080973A8
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r2, r3, #0
	b _080973DA
	.align 2, 0
_080973A4: .4byte 0x02021B38
_080973A8: .4byte 0x02021B3A
_080973AC:
	mov r0, ip
	ldrh r1, [r0, #0x24]
	ldrh r2, [r0, #0x20]
	adds r1, r1, r2
	mov r3, ip
	adds r3, #0x28
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, ip
	ldrh r1, [r0, #0x26]
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	mov r2, ip
	adds r2, #0x29
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r4, r3, #0
_080973DA:
	ldrb r0, [r4]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x19
	subs r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x19
	subs r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	bgt _08097406
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x10
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08097412
_08097406:
	mov r4, ip
	adds r4, #0x3e
	ldrb r0, [r4]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
_08097412:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xaf
	bgt _08097426
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x10
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08097432
_08097426:
	mov r0, ip
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
_08097432:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end UpdateObjectEventSpriteInvisibility

	thumb_func_start UpdateEventObjectSpriteSubpriorityAndVisibility
UpdateEventObjectSpriteSubpriorityAndVisibility: @ 0x08097438
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080976D8
	ldrh r0, [r4, #0x30]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	movs r2, #1
	bl SetObjectSubpriorityByElevation
	ldrh r1, [r4, #0x32]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl UpdateObjectEventSpriteInvisibility
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end UpdateEventObjectSpriteSubpriorityAndVisibility

	thumb_func_start sub_08097460
sub_08097460: @ 0x08097460
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0x3f
_08097466:
	ldr r0, _08097494
	adds r2, r5, r0
	adds r0, r2, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08097486
	ldr r1, [r2, #0x1c]
	ldr r0, _08097498
	cmp r1, r0
	bne _08097486
	adds r0, r2, #0
	bl DestroySprite
_08097486:
	adds r5, #0x44
	subs r4, #1
	cmp r4, #0
	bge _08097466
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08097494: .4byte 0x020205AC
_08097498: .4byte 0x08097439
	thumb_func_end sub_08097460

	thumb_func_start sub_0809749C
sub_0809749C: @ 0x0809749C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r3, #0
	ldr r6, _080974D0
	movs r4, #0
_080974A8:
	adds r2, r4, r6
	adds r0, r2, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080974D8
	ldr r1, [r2, #0x1c]
	ldr r0, _080974D4
	cmp r1, r0
	bne _080974D8
	ldrh r0, [r2, #0x2e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	bne _080974D8
	adds r0, r3, #0
	b _080974E2
	.align 2, 0
_080974D0: .4byte 0x020205AC
_080974D4: .4byte 0x08097439
_080974D8:
	adds r4, #0x44
	adds r3, #1
	cmp r3, #0x3f
	ble _080974A8
	movs r0, #0x40
_080974E2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_0809749C

	thumb_func_start sub_080974E8
sub_080974E8: @ 0x080974E8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	beq _0809751A
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _08097520
	adds r4, r4, r0
	adds r0, r5, #0
	bl GetJumpInPlaceMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
_0809751A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08097520: .4byte 0x020205AC
	thumb_func_end sub_080974E8

	thumb_func_start sub_08097524
sub_08097524: @ 0x08097524
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	bl sub_0809749C
	adds r1, r0, #0
	cmp r1, #0x40
	beq _080975AE
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08097588
	adds r4, r0, r1
	adds r0, r5, #0
	bl GetObjectEventGraphicsInfo
	ldrh r3, [r4, #4]
	lsls r3, r3, #0x16
	ldr r1, [r0, #0x10]
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r4]
	str r2, [r4, #4]
	lsrs r3, r3, #0x16
	ldrh r2, [r4, #4]
	ldr r1, _0809758C
	ands r1, r2
	orrs r1, r3
	strh r1, [r4, #4]
	ldrb r2, [r0, #0xc]
	lsls r2, r2, #0x1c
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #5]
	movs r1, #0xf
	ands r1, r3
	orrs r1, r2
	strb r1, [r4, #5]
	ldr r1, [r0, #0x1c]
	str r1, [r4, #0xc]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	bne _08097590
	str r1, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
	b _080975A6
	.align 2, 0
_08097588: .4byte 0x020205AC
_0809758C: .4byte 0xFFFFFC00
_08097590:
	adds r0, r4, #0
	bl SetSubspriteTables
	adds r2, r4, #0
	adds r2, #0x42
	ldrb r0, [r2]
	movs r1, #0x3f
	ands r1, r0
	movs r0, #0x80
	orrs r1, r0
	strb r1, [r2]
_080975A6:
	adds r0, r4, #0
	movs r1, #0
	bl StartSpriteAnim
_080975AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08097524

	thumb_func_start sub_080975B4
sub_080975B4: @ 0x080975B4
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r2, #0
	cmp r2, #0x40
	beq _080975F0
	cmp r4, #0
	beq _080975E4
	ldr r0, _080975E0
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #1
	strh r0, [r1, #0x32]
	b _080975F0
	.align 2, 0
_080975E0: .4byte 0x020205AC
_080975E4:
	ldr r1, _080975F8
	lsls r0, r3, #4
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	strh r4, [r0, #0x32]
_080975F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080975F8: .4byte 0x020205AC
	thumb_func_end sub_080975B4

	thumb_func_start sub_080975FC
sub_080975FC: @ 0x080975FC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	bne _08097612
	movs r0, #0
	b _0809762A
_08097612:
	movs r3, #0
	ldr r0, _08097630
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r2, #0x32
	ldrsh r0, [r1, r2]
	cmp r0, #1
	bne _08097628
	movs r3, #1
_08097628:
	adds r0, r3, #0
_0809762A:
	pop {r1}
	bx r1
	.align 2, 0
_08097630: .4byte 0x020205AC
	thumb_func_end sub_080975FC

	thumb_func_start sub_08097634
sub_08097634: @ 0x08097634
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _0809765A
	ldr r0, _08097660
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #0
	strh r4, [r1, #0x34]
	strh r0, [r1, #0x36]
_0809765A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097660: .4byte 0x020205AC
	thumb_func_end sub_08097634

	thumb_func_start sub_08097664
sub_08097664: @ 0x08097664
	push {lr}
	adds r2, r0, #0
	movs r1, #0x36
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08097676
	cmp r0, #1
	beq _0809767E
	b _0809769C
_08097676:
	strh r0, [r2, #0x26]
	ldrh r0, [r2, #0x36]
	adds r0, #1
	strh r0, [r2, #0x36]
_0809767E:
	ldrh r0, [r2, #0x26]
	subs r0, #8
	movs r3, #0
	strh r0, [r2, #0x26]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0809769C
	strh r3, [r2, #0x26]
	movs r0, #1
	strh r0, [r2, #0x32]
	strh r3, [r2, #0x34]
	strh r3, [r2, #0x36]
_0809769C:
	pop {r0}
	bx r0
	thumb_func_end sub_08097664

	thumb_func_start sub_080976A0
sub_080976A0: @ 0x080976A0
	push {lr}
	adds r1, r0, #0
	movs r2, #0x36
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080976B2
	cmp r0, #1
	beq _080976BC
	b _080976CE
_080976B2:
	ldr r0, _080976D4
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
_080976BC:
	ldrh r0, [r1, #0x26]
	adds r0, #8
	strh r0, [r1, #0x26]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _080976CE
	strh r0, [r1, #0x34]
	strh r0, [r1, #0x36]
_080976CE:
	pop {r0}
	bx r0
	.align 2, 0
_080976D4: .4byte 0x0000FF60
	thumb_func_end sub_080976A0

	thumb_func_start sub_080976D8
sub_080976D8: @ 0x080976D8
	push {lr}
	adds r1, r0, #0
	movs r2, #0x34
	ldrsh r0, [r1, r2]
	cmp r0, #1
	beq _080976F4
	cmp r0, #1
	bgt _080976EE
	cmp r0, #0
	beq _08097714
	b _08097704
_080976EE:
	cmp r0, #2
	beq _080976FC
	b _08097704
_080976F4:
	adds r0, r1, #0
	bl sub_080976A0
	b _08097714
_080976FC:
	adds r0, r1, #0
	bl sub_08097664
	b _08097714
_08097704:
	movs r0, #0
	strh r0, [r1, #0x34]
	ldr r0, _08097718
	ldr r1, _0809771C
	ldr r2, _08097720
	movs r3, #1
	bl AGBAssert
_08097714:
	pop {r0}
	bx r0
	.align 2, 0
_08097718: .4byte 0x084E6CA8
_0809771C: .4byte 0x00003106
_08097720: .4byte 0x084E6CB4
	thumb_func_end sub_080976D8

	thumb_func_start sub_08097724
sub_08097724: @ 0x08097724
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _08097748
	ldr r0, _0809774C
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r2, #0x34
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _08097750
_08097748:
	movs r0, #0
	b _08097752
	.align 2, 0
_0809774C: .4byte 0x020205AC
_08097750:
	movs r0, #1
_08097752:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08097724

	thumb_func_start sub_08097758
sub_08097758: @ 0x08097758
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _0809777C
	adds r2, r1, #4
	adds r3, r1, #0
	adds r3, #8
	bl EventObjectGetLocalIdAndMap
	adds r0, r4, #0
	bl FieldEffectStart
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809777C: .4byte 0x020388A8
	thumb_func_end sub_08097758

	thumb_func_start DoShadowFieldEffect
DoShadowFieldEffect: @ 0x08097780
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #2]
	lsls r0, r2, #0x19
	cmp r0, #0
	blt _08097798
	movs r0, #0x40
	orrs r0, r2
	strb r0, [r1, #2]
	movs r0, #3
	bl sub_08097758
_08097798:
	pop {r0}
	bx r0
	thumb_func_end DoShadowFieldEffect

	thumb_func_start DoRippleFieldEffect
DoRippleFieldEffect: @ 0x0809779C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #5]
	bl GetObjectEventGraphicsInfo
	ldr r2, _080977D4
	movs r3, #0x20
	ldrsh r1, [r4, r3]
	str r1, [r2]
	movs r3, #0x22
	ldrsh r1, [r4, r3]
	ldrh r0, [r0, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r1, r1, r0
	subs r1, #2
	str r1, [r2, #4]
	movs r0, #0x97
	str r0, [r2, #8]
	movs r0, #3
	str r0, [r2, #0xc]
	movs r0, #5
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080977D4: .4byte 0x020388A8
	thumb_func_end DoRippleFieldEffect

	thumb_func_start MovementAction_StoreAndLockAnim_Step0
MovementAction_StoreAndLockAnim_Step0: @ 0x080977D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r1
	movs r0, #0
	mov ip, r0
	ldr r0, _08097804
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08097808
	movs r0, #0x14
	bl AllocZeroed
	str r0, [r6]
	ldrb r1, [r4, #8]
	strb r1, [r0]
	ldr r1, [r6]
	movs r0, #1
	strb r0, [r1, #0x10]
	b _08097854
	.align 2, 0
_08097804: .4byte 0x02037258
_08097808:
	movs r2, #0x10
	movs r5, #0
	movs r1, #0
	adds r3, r6, #0
	b _08097818
_08097812:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_08097818:
	cmp r1, #0xf
	bhi _0809783A
	cmp r2, #0x10
	bne _0809782C
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809782C
	adds r2, r1, #0
_0809782C:
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r7, [r4, #8]
	cmp r0, r7
	bne _08097812
	movs r5, #1
_0809783A:
	cmp r5, #0
	bne _08097856
	cmp r2, #0x10
	beq _08097856
	ldr r0, [r6]
	adds r0, r0, r2
	ldrb r1, [r4, #8]
	strb r1, [r0]
	ldr r1, [r6]
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	movs r0, #1
_08097854:
	mov ip, r0
_08097856:
	mov r1, ip
	cmp r1, #1
	bne _08097868
	ldrb r0, [r4, #1]
	movs r1, #0x10
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #1]
_08097868:
	movs r0, #1
	mov r7, r8
	strh r0, [r7, #0x32]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_StoreAndLockAnim_Step0

	thumb_func_start MovementAction_FreeAndUnlockAnim_Step0
MovementAction_FreeAndUnlockAnim_Step0: @ 0x08097878
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	movs r0, #1
	strh r0, [r1, #0x32]
	ldr r5, _080978FC
	ldr r0, [r5]
	cmp r0, #0
	beq _080978F0
	movs r7, #0
	adds r0, r6, #0
	bl FindLockedEventObjectIndex
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x10
	beq _080978B0
	ldr r0, [r5]
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, #0x10]
	subs r0, #1
	strb r0, [r1, #0x10]
	movs r7, #1
_080978B0:
	ldr r0, [r5]
	ldrb r4, [r0, #0x10]
	cmp r4, #0
	bne _080978BE
	bl Free
	str r4, [r5]
_080978BE:
	cmp r7, #1
	bne _080978F0
	ldrb r0, [r6, #5]
	bl GetObjectEventGraphicsInfo
	ldrb r1, [r0, #0xc]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x1f
	lsls r1, r1, #4
	ldrb r2, [r6, #1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r6, #1]
	mov r2, r8
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_080978F0:
	movs r0, #1
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080978FC: .4byte 0x02037258
	thumb_func_end MovementAction_FreeAndUnlockAnim_Step0

	thumb_func_start FindLockedEventObjectIndex
FindLockedEventObjectIndex: @ 0x08097900
	push {lr}
	movs r2, #0
	ldr r1, _08097918
	ldr r1, [r1]
	ldrb r3, [r0, #8]
_0809790A:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r3
	bne _0809791C
	adds r0, r2, #0
	b _08097928
	.align 2, 0
_08097918: .4byte 0x02037258
_0809791C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bls _0809790A
	movs r0, #0x10
_08097928:
	pop {r1}
	bx r1
	thumb_func_end FindLockedEventObjectIndex

	thumb_func_start CreateLevitateMovementTask
CreateLevitateMovementTask: @ 0x0809792C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08097960
	movs r1, #0xff
	bl CreateTask
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	ldr r0, _08097964
	adds r4, r4, r0
	adds r0, r4, #0
	adds r0, #8
	adds r1, r6, #0
	bl StoreWordInTwoHalfwords
	strb r5, [r6, #0x1b]
	ldr r0, _08097968
	strh r0, [r4, #0xe]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08097960: .4byte 0x0809796D
_08097964: .4byte 0x03005B60
_08097968: .4byte 0x0000FFFF
	thumb_func_end CreateLevitateMovementTask

	thumb_func_start ApplyLevitateMovement
ApplyLevitateMovement: @ 0x0809796C
	push {r4, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080979C4
	adds r4, r1, r0
	adds r0, r4, #0
	adds r0, #8
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	ldr r0, [sp]
	ldrb r1, [r0, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080979C8
	adds r2, r0, r1
	ldrh r1, [r4, #0xc]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080979A8
	ldrh r0, [r4, #0xe]
	ldrh r1, [r2, #0x26]
	adds r0, r0, r1
	strh r0, [r2, #0x26]
_080979A8:
	ldrh r1, [r4, #0xc]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080979B8
	ldrh r0, [r4, #0xe]
	rsbs r0, r0, #0
	strh r0, [r4, #0xe]
_080979B8:
	adds r0, r1, #1
	strh r0, [r4, #0xc]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080979C4: .4byte 0x03005B60
_080979C8: .4byte 0x020205AC
	thumb_func_end ApplyLevitateMovement

	thumb_func_start DestroyExtraMovementTask
DestroyExtraMovementTask: @ 0x080979CC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _080979F8
	adds r0, r0, r1
	adds r0, #8
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	adds r0, r4, #0
	bl DestroyTask
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080979F8: .4byte 0x03005B60
	thumb_func_end DestroyExtraMovementTask

	thumb_func_start sub_080979FC
sub_080979FC: @ 0x080979FC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r4, #0
	ldr r7, _08097A40
_08097A0A:
	cmp r4, r6
	beq _08097A30
	cmp r4, r5
	beq _08097A30
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, r0, r7
	ldrb r0, [r1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08097A30
	ldr r0, _08097A44
	ldrb r0, [r0, #5]
	cmp r4, r0
	beq _08097A30
	adds r0, r1, #0
	bl FreezeEventObject
_08097A30:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _08097A0A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097A40: .4byte 0x02036FF0
_08097A44: .4byte 0x02037230
	thumb_func_end sub_080979FC

	thumb_func_start MovementAction_FlyUp_Step0
MovementAction_FlyUp_Step0: @ 0x08097A48
	movs r0, #0
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x32]
	adds r0, #1
	strh r0, [r1, #0x32]
	movs r0, #0
	bx lr
	.align 2, 0
	thumb_func_end MovementAction_FlyUp_Step0

	thumb_func_start MovementAction_FlyUp_Step1
MovementAction_FlyUp_Step1: @ 0x08097A58
	push {lr}
	adds r2, r1, #0
	ldrh r0, [r2, #0x26]
	subs r0, #8
	strh r0, [r2, #0x26]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bne _08097A74
	ldrh r0, [r2, #0x32]
	adds r0, #1
	strh r0, [r2, #0x32]
_08097A74:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_FlyUp_Step1

	thumb_func_start MovementAction_FlyDown_Step0
MovementAction_FlyDown_Step0: @ 0x08097A7C
	ldr r0, _08097A8C
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x32]
	adds r0, #1
	strh r0, [r1, #0x32]
	movs r0, #0
	bx lr
	.align 2, 0
_08097A8C: .4byte 0x0000FF60
	thumb_func_end MovementAction_FlyDown_Step0

	thumb_func_start MovementAction_FlyDown_Step1
MovementAction_FlyDown_Step1: @ 0x08097A90
	push {lr}
	ldrh r0, [r1, #0x26]
	adds r0, #8
	strh r0, [r1, #0x26]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08097AA4
	ldrh r0, [r1, #0x32]
	adds r0, #1
	strh r0, [r1, #0x32]
_08097AA4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_FlyDown_Step1

	thumb_func_start MovementAction_Finish
MovementAction_Finish: @ 0x08097AAC
	movs r0, #1
	bx lr
	thumb_func_end MovementAction_Finish


	.globl SetVirtualObjectInvisibility
	.set SetVirtualObjectInvisibility, sub_080975B4

	.globl SetVirtualObjectGraphics
	.set SetVirtualObjectGraphics, sub_08097524

	.globl IsVirtualObjectInvisible
	.set IsVirtualObjectInvisible, sub_080975FC

	.globl SetVirtualObjectSpriteAnim
	.set SetVirtualObjectSpriteAnim, sub_08097634

	.globl TurnVirtualObject
	.set TurnVirtualObject, sub_080974E8

	.globl IsVirtualObjectAnimating
	.set IsVirtualObjectAnimating, sub_08097724

	.globl ObjectEventFaceOppositeDirection
	.set ObjectEventFaceOppositeDirection, EventObjectFaceOppositeDirection


	.globl TryMoveObjectEventToMapCoords

	.globl TurnVirtualObject
	.set TurnVirtualObject, sub_080974E8
