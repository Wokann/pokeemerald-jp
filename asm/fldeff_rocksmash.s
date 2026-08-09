.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified











	thumb_func_start sub_08135780
sub_08135780: @ 0x08135780
	push {lr}
	bl CanUseEscapeRopeOnCurrMap
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08135792
	movs r0, #0
	b _081357A0
_08135792:
	ldr r1, _081357A4
	ldr r0, _081357A8
	str r0, [r1]
	ldr r1, _081357AC
	ldr r0, _081357B0
	str r0, [r1]
	movs r0, #1
_081357A0:
	pop {r1}
	bx r1
	.align 2, 0
_081357A4: .4byte 0x03005B10
_081357A8: .4byte 0x081B53D9
_081357AC: .4byte 0x0203CBB8
_081357B0: .4byte 0x081357B5
	thumb_func_end sub_08135780

	thumb_func_start sub_081357B4
sub_081357B4: @ 0x081357B4
	push {lr}
	bl Overworld_ResetStateAfterFly
	movs r0, #0x26
	bl FieldEffectStart
	bl GetCursorSelectionMonId
	ldr r1, _081357D0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081357D0: .4byte 0x020388A8
	thumb_func_end sub_081357B4

	thumb_func_start sub_081357D4
sub_081357D4: @ 0x081357D4
	push {lr}
	bl CreateFieldMoveTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08135808
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldr r2, _0813580C
	lsrs r0, r2, #0x10
	strh r0, [r1, #0x18]
	strh r2, [r1, #0x1a]
	bl ShouldDoBrailleDigEffect
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08135800
	movs r0, #1
	bl SetPlayerAvatarTransitionFlags
_08135800:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08135808: .4byte 0x03005B60
_0813580C: .4byte 0x08135811
	thumb_func_end sub_081357D4

	thumb_func_start sub_08135810
sub_08135810: @ 0x08135810
	push {r4, lr}
	movs r0, #0x26
	bl FieldEffectActiveListRemove
	bl ShouldDoBrailleDigEffect
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0813582A
	bl DoBrailleDigEffect
	b _08135842
_0813582A:
	ldr r0, _08135848
	movs r1, #8
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0813584C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	strh r4, [r1, #8]
_08135842:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08135848: .4byte 0x080FEB0D
_0813584C: .4byte 0x03005B60
	thumb_func_end sub_08135810
