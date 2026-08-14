.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start SpawnLinkPlayerEventObject
SpawnLinkPlayerEventObject: @ 0x08087054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r1
	mov sl, r2
	mov r8, r3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	mov r2, r8
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	bl GetFirstInactiveEventObjectId
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r4, r7, #2
	ldr r0, _080870F8
	adds r4, r4, r0
	lsls r5, r6, #3
	adds r5, r5, r6
	lsls r5, r5, #2
	ldr r0, _080870FC
	adds r5, r5, r0
	adds r0, r4, #0
	bl ZeroLinkPlayerObjectEvent
	adds r0, r5, #0
	bl ZeroEventObject
	movs r2, #0
	movs r1, #1
	movs r0, #1
	strb r0, [r4]
	strb r7, [r4, #1]
	strb r6, [r4, #2]
	strb r2, [r4, #3]
	ldrb r0, [r5]
	orrs r0, r1
	mov r2, r8
	ands r2, r1
	lsls r2, r2, #1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	movs r0, #2
	strb r0, [r5, #0x19]
	movs r0, #0x40
	strb r0, [r5, #4]
	mov r0, sb
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov sb, r0
	mov r1, sl
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov sl, r1
	adds r0, r5, #0
	mov r1, sb
	mov r2, sl
	bl InitLinkPlayerEventObjectPos
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080870F8: .4byte 0x02031FA8
_080870FC: .4byte 0x02036FF0
	thumb_func_end SpawnLinkPlayerEventObject

	thumb_func_start InitLinkPlayerEventObjectPos
InitLinkPlayerEventObjectPos: @ 0x08087100
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	strh r0, [r4, #0x10]
	strh r1, [r4, #0x12]
	strh r0, [r4, #0x14]
	strh r1, [r4, #0x16]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, r4, #0
	adds r2, #0xc
	adds r3, r4, #0
	adds r3, #0xe
	bl SetSpritePosToMapCoords
	ldrh r0, [r4, #0xc]
	adds r0, #8
	strh r0, [r4, #0xc]
	adds r0, r4, #0
	bl EventObjectUpdateZCoord
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end InitLinkPlayerEventObjectPos

	thumb_func_start sub_08087140
sub_08087140: @ 0x08087140
	push {lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	ldr r1, _08087168
	lsrs r0, r0, #0x16
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _08087162
	ldrb r0, [r1, #2]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0808716C
	adds r1, r1, r0
	strb r2, [r1, #0x19]
_08087162:
	pop {r0}
	bx r0
	.align 2, 0
_08087168: .4byte 0x02031FA8
_0808716C: .4byte 0x02036FF0
	thumb_func_end sub_08087140

	thumb_func_start sub_08087170
sub_08087170: @ 0x08087170
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	ldr r1, _080871B0
	adds r5, r0, r1
	ldrb r1, [r5, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871B4
	adds r4, r0, r1
	ldrb r0, [r4, #4]
	cmp r0, #0x40
	beq _0808719C
	adds r1, r0, #0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871B8
	adds r0, r0, r1
	bl DestroySprite
_0808719C:
	movs r0, #0
	strb r0, [r5]
	ldrb r1, [r4]
	subs r0, #2
	ands r0, r1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080871B0: .4byte 0x02031FA8
_080871B4: .4byte 0x02036FF0
_080871B8: .4byte 0x020205AC
	thumb_func_end sub_08087170

	thumb_func_start GetSpriteForLinkedPlayer
GetSpriteForLinkedPlayer: @ 0x080871BC
	lsls r0, r0, #0x18
	ldr r1, _080871D4
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871D8
	adds r0, r0, r1
	ldrb r0, [r0, #4]
	bx lr
	.align 2, 0
_080871D4: .4byte 0x02031FA8
_080871D8: .4byte 0x02036FF0
	thumb_func_end GetSpriteForLinkedPlayer

	thumb_func_start GetLinkPlayerCoords
GetLinkPlayerCoords: @ 0x080871DC
	lsls r0, r0, #0x18
	ldr r3, _080871FC
	lsrs r0, r0, #0x16
	adds r0, r0, r3
	ldrb r3, [r0, #2]
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r3, _08087200
	adds r0, r0, r3
	ldrh r3, [r0, #0x10]
	strh r3, [r1]
	ldrh r0, [r0, #0x12]
	strh r0, [r2]
	bx lr
	.align 2, 0
_080871FC: .4byte 0x02031FA8
_08087200: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerCoords

	thumb_func_start GetLinkPlayerFacingDirection
GetLinkPlayerFacingDirection: @ 0x08087204
	lsls r0, r0, #0x18
	ldr r1, _0808721C
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087220
	adds r0, r0, r1
	ldrb r0, [r0, #0x19]
	bx lr
	.align 2, 0
_0808721C: .4byte 0x02031FA8
_08087220: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerFacingDirection

	thumb_func_start GetLinkPlayerElevation
GetLinkPlayerElevation: @ 0x08087224
	lsls r0, r0, #0x18
	ldr r1, _08087240
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087244
	adds r0, r0, r1
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	bx lr
	.align 2, 0
_08087240: .4byte 0x02031FA8
_08087244: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerElevation

	thumb_func_start sub_08087248
sub_08087248: @ 0x08087248
	lsls r0, r0, #0x18
	ldr r1, _08087268
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0808726C
	adds r0, r0, r1
	adds r0, #0x21
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x10
	subs r0, r0, r1
	bx lr
	.align 2, 0
_08087268: .4byte 0x02031FA8
_0808726C: .4byte 0x02036FF0
	thumb_func_end sub_08087248

	thumb_func_start GetLinkPlayerIdAt
GetLinkPlayerIdAt: @ 0x08087270
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r5, _080872B4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	lsls r1, r1, #0x10
	asrs r3, r1, #0x10
_0808727E:
	lsls r0, r2, #2
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0
	beq _080872BC
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _08087292
	cmp r0, #2
	bne _080872BC
_08087292:
	ldrb r1, [r1, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080872B8
	adds r1, r0, r1
	movs r6, #0x10
	ldrsh r0, [r1, r6]
	cmp r0, r4
	bne _080872BC
	movs r6, #0x12
	ldrsh r0, [r1, r6]
	cmp r0, r3
	bne _080872BC
	adds r0, r2, #0
	b _080872C8
	.align 2, 0
_080872B4: .4byte 0x02031FA8
_080872B8: .4byte 0x02036FF0
_080872BC:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _0808727E
	movs r0, #4
_080872C8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetLinkPlayerIdAt

	thumb_func_start SetPlayerFacingDirection
SetPlayerFacingDirection: @ 0x080872D0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	adds r2, r3, #0
	lsrs r0, r0, #0x16
	ldr r1, _08087300
	adds r5, r0, r1
	ldrb r1, [r5, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087304
	adds r6, r0, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _0808732C
	cmp r3, #0xa
	bls _08087308
	ldrb r0, [r6]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6]
	b _0808732C
	.align 2, 0
_08087300: .4byte 0x02031FA8
_08087304: .4byte 0x02036FF0
_08087308:
	ldr r4, _08087334
	ldr r1, _08087338
	ldrb r0, [r5, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
_0808732C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087334: .4byte 0x0830FD4C
_08087338: .4byte 0x0830FD14
	thumb_func_end SetPlayerFacingDirection

	thumb_func_start MovementEventModeCB_Normal
MovementEventModeCB_Normal: @ 0x0808733C
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, _08087358
	lsls r3, r2, #2
	adds r3, r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08087358: .4byte 0x0830FD20
	thumb_func_end MovementEventModeCB_Normal

	thumb_func_start MovementEventModeCB_Ignored
MovementEventModeCB_Ignored: @ 0x0808735C
	movs r0, #1
	bx lr
	thumb_func_end MovementEventModeCB_Ignored

	thumb_func_start MovementEventModeCB_Normal_2
MovementEventModeCB_Normal_2: @ 0x08087360
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, _0808737C
	lsls r3, r2, #2
	adds r3, r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808737C: .4byte 0x0830FD20
	thumb_func_end MovementEventModeCB_Normal_2

	thumb_func_start FacingHandler_DoNothing
FacingHandler_DoNothing: @ 0x08087380
	movs r0, #0
	bx lr
	thumb_func_end FacingHandler_DoNothing

	thumb_func_start FacingHandler_DpadMovement
FacingHandler_DpadMovement: @ 0x08087384
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #0x19]
	bl FlipVerticalAndClearForced
	strb r0, [r5, #0x19]
	ldrb r1, [r5, #0x19]
	mov r6, sp
	adds r6, #2
	adds r0, r5, #0
	mov r2, sp
	adds r3, r6, #0
	bl EventObjectMoveDestCoords
	ldrb r0, [r4, #2]
	ldrb r1, [r5, #0x19]
	mov r2, sp
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r4, #0
	ldrsh r3, [r6, r4]
	bl LinkPlayerDetectCollision
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080873E2
	adds r1, r5, #0
	adds r1, #0x21
	movs r0, #0x10
	strb r0, [r1]
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r2, [r6, r3]
	adds r0, r5, #0
	bl ShiftEventObjectCoords
	adds r0, r5, #0
	bl EventObjectUpdateZCoord
	movs r0, #1
	b _080873E4
_080873E2:
	movs r0, #0
_080873E4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end FacingHandler_DpadMovement

	thumb_func_start FacingHandler_ForcedFacingChange
FacingHandler_ForcedFacingChange: @ 0x080873EC
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #0x19]
	bl FlipVerticalAndClearForced
	strb r0, [r4, #0x19]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FacingHandler_ForcedFacingChange

	thumb_func_start MovementStatusHandler_EnterFreeMode
MovementStatusHandler_EnterFreeMode: @ 0x08087404
	@ From src/overworld.c
	movs r1, #0
	strb r1, [r0, #3]
	bx lr
	.align 2, 0
	thumb_func_end MovementStatusHandler_EnterFreeMode

	thumb_func_start MovementStatusHandler_TryAdvanceScript
MovementStatusHandler_TryAdvanceScript: @ 0x0808740C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x21
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	movs r0, #1
	strb r0, [r6, #3]
	ldrb r0, [r4, #0x19]
	adds r1, #0xc
	adds r2, r4, #0
	adds r2, #0xe
	bl MoveCoords
	ldrb r0, [r5]
	cmp r0, #0
	bne _0808743C
	adds r0, r4, #0
	bl ShiftStillEventObjectCoords
	movs r0, #2
	strb r0, [r6, #3]
_0808743C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end MovementStatusHandler_TryAdvanceScript

	thumb_func_start FlipVerticalAndClearForced
FlipVerticalAndClearForced: @ 0x08087444
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	subs r0, #1
	cmp r0, #9
	bhi _0808749C
	lsls r0, r0, #2
	ldr r1, _08087460
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087460: .4byte 0x08087464
_08087464: @ jump table
	.4byte _0808748C @ case 0
	.4byte _08087490 @ case 1
	.4byte _08087494 @ case 2
	.4byte _08087498 @ case 3
	.4byte _0808749C @ case 4
	.4byte _0808749C @ case 5
	.4byte _0808748C @ case 6
	.4byte _08087490 @ case 7
	.4byte _08087494 @ case 8
	.4byte _08087498 @ case 9
_0808748C:
	movs r0, #2
	b _0808749E
_08087490:
	movs r0, #1
	b _0808749E
_08087494:
	movs r0, #3
	b _0808749E
_08087498:
	movs r0, #4
	b _0808749E
_0808749C:
	adds r0, r2, #0
_0808749E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end FlipVerticalAndClearForced

	thumb_func_start LinkPlayerDetectCollision
LinkPlayerDetectCollision: @ 0x080874A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov ip, r2
	lsls r3, r3, #0x10
	movs r4, #0
	ldr r0, _08087508
	mov sb, r0
	lsrs r2, r3, #0x10
	mov sl, r2
	asrs r6, r3, #0x10
_080874C8:
	mov r7, ip
	lsls r3, r7, #0x10
	mov r0, sl
	lsls r5, r0, #0x10
	cmp r4, r8
	beq _0808750C
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	mov r2, sb
	adds r1, r0, r2
	movs r7, #0x10
	ldrsh r0, [r1, r7]
	asrs r2, r3, #0x10
	cmp r0, r2
	bne _080874F0
	movs r7, #0x12
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _08087502
_080874F0:
	movs r7, #0x14
	ldrsh r0, [r1, r7]
	cmp r0, r2
	bne _0808750C
	movs r0, #0x16
	ldrsh r1, [r1, r0]
	asrs r0, r5, #0x10
	cmp r1, r0
	bne _0808750C
_08087502:
	movs r0, #1
	b _08087522
	.align 2, 0
_08087508: .4byte 0x02036FF0
_0808750C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _080874C8
	asrs r0, r3, #0x10
	asrs r1, r5, #0x10
	bl MapGridGetCollisionAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08087522:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end LinkPlayerDetectCollision

	thumb_func_start CreateLinkPlayerSprite
CreateLinkPlayerSprite: @ 0x08087530
	push {r4, r5, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	lsls r2, r5, #2
	ldr r0, _08087564
	adds r2, r2, r0
	ldrb r1, [r2, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087568
	adds r4, r0, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080875DE
	subs r0, r3, #1
	cmp r0, #4
	bhi _080875BA
	lsls r0, r0, #2
	ldr r1, _0808756C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087564: .4byte 0x02031FA8
_08087568: .4byte 0x02036FF0
_0808756C: .4byte 0x08087570
_08087570: @ jump table
	.4byte _08087590 @ case 0
	.4byte _08087590 @ case 1
	.4byte _0808759C @ case 2
	.4byte _08087584 @ case 3
	.4byte _08087584 @ case 4
_08087584:
	ldrb r0, [r4]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	bl sub_0808B6D0
	b _080875A8
_08087590:
	ldrb r0, [r4]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	bl GetFRLGAvatarGraphicsIdByGender
	b _080875A8
_0808759C:
	ldrb r1, [r4]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1f
	movs r0, #0
	bl GetPlayerAvatarGraphicsIdByStateIdAndGender
_080875A8:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080875E8
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl AddPseudoEventObject
	strb r0, [r4, #4]
_080875BA:
	ldrb r1, [r4, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080875EC
	adds r0, r0, r1
	adds r3, r0, #0
	adds r3, #0x3e
	ldrb r1, [r3]
	movs r2, #2
	orrs r1, r2
	strb r1, [r3]
	strh r5, [r0, #0x2e]
	ldrb r1, [r4]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4]
_080875DE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080875E8: .4byte 0x080875F1
_080875EC: .4byte 0x020205AC
	thumb_func_end CreateLinkPlayerSprite

	thumb_func_start SpriteCB_LinkPlayer
SpriteCB_LinkPlayer: @ 0x080875F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x2e
	ldrsh r4, [r5, r0]
	lsls r4, r4, #2
	ldr r0, _08087654
	adds r4, r4, r0
	ldrb r1, [r4, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087658
	adds r6, r0, r1
	ldrh r0, [r6, #0xc]
	strh r0, [r5, #0x20]
	ldrh r0, [r6, #0xe]
	strh r0, [r5, #0x22]
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #4
	adds r1, r5, #0
	movs r2, #1
	bl SetObjectSubpriorityByElevation
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #4
	bl ElevationToPriority
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #5]
	ldrb r0, [r4, #3]
	cmp r0, #0
	bne _0808765C
	ldrb r0, [r6, #0x19]
	bl GetJumpInPlaceMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl StartSpriteAnim
	b _0808766E
	.align 2, 0
_08087654: .4byte 0x02031FA8
_08087658: .4byte 0x02036FF0
_0808765C:
	ldrb r0, [r6, #0x19]
	bl GetJumpInPlaceTurnAroundMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl StartSpriteAnimIfDifferent
_0808766E:
	adds r0, r5, #0
	movs r1, #0
	bl UpdateObjectEventSpriteInvisibility
	ldrb r0, [r6]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _080876A0
	ldrh r0, [r5, #0x3c]
	movs r1, #4
	ands r1, r0
	lsls r1, r1, #0x10
	adds r3, r5, #0
	adds r3, #0x3e
	lsrs r1, r1, #0x12
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r5, #0x3c]
	adds r0, #1
	strh r0, [r5, #0x3c]
_080876A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SpriteCB_LinkPlayer



