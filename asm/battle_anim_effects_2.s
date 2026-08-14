.include "asm/macros.inc"
.include "constants/constants.inc"
.syntax unified


	.section .text.battle_anim_effects_2_step,"ax",%progbits










	thumb_func_start AnimTask_AttackerStretchAndDisappear_Step
AnimTask_AttackerStretchAndDisappear_Step: @ 0x08106008
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _08106058
	adds r4, r0, r1
	adds r0, r4, #0
	bl RunAffineAnimFromTaskData
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08106052
	ldr r2, _0810605C
	movs r0, #8
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	strh r3, [r0, #0x26]
	movs r0, #8
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl DestroyAnimVisualTask
_08106052:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08106058: .4byte 0x03005B60
_0810605C: .4byte 0x020205AC
	thumb_func_end AnimTask_AttackerStretchAndDisappear_Step


