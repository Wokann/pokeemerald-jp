.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start AddTextPrinterAndCreateWindowOnHealthbox
AddTextPrinterAndCreateWindowOnHealthbox: @ 0x080741E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08074254
	lsls r0, r5, #4
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerPosition
	ldr r1, _08074258
	ldr r2, [r1]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r2, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #7
	movs r0, #0xa4
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r2]
	adds r6, r0, r1
	movs r1, #7
	mov r8, r1
	ldr r2, _0807425C
	adds r0, r6, #0
	bl RenderTextFont9
	movs r7, #3
	movs r4, #0
_08074230:
	ldr r0, _0807425C
	adds r0, r7, r0
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0x37
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _0807424E
	adds r0, r1, #0
	adds r0, #0x79
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bhi _08074260
_0807424E:
	movs r0, #0x2c
	b _0807427E
	.align 2, 0
_08074254: .4byte 0x020205AC
_08074258: .4byte 0x02024178
_0807425C: .4byte 0x085ABC38
_08074260:
	adds r0, r1, #0
	subs r0, #0x4b
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08074278
	adds r0, r1, #0
	adds r0, #0x65
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0807427C
_08074278:
	movs r0, #0x2d
	b _0807427E
_0807427C:
	movs r0, #0x2b
_0807427E:
	bl GetHealthboxElementGfxPtr
	lsls r1, r4, #6
	adds r1, r6, r1
	ldr r2, _08074314
	bl CpuSet
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r7, #1
	cmp r4, r8
	blo _08074230
	movs r7, #3
	movs r2, #3
	add r2, r8
	mov sb, r2
	cmp r7, sb
	bge _08074304
	ldr r1, _08074318
	ldr r0, _08074314
	mov sl, r0
	lsls r0, r5, #4
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r8, r0
_080742B4:
	mov r1, r8
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	adds r5, r7, #0
	cmp r7, #0
	bge _080742C4
	adds r5, r7, #7
_080742C4:
	asrs r5, r5, #3
	lsls r4, r5, #3
	subs r4, r7, r4
	adds r0, r0, r4
	lsls r5, r5, #6
	adds r0, r0, r5
	lsls r0, r0, #5
	ldr r2, _0807431C
	adds r1, r0, r2
	adds r0, r6, #0
	mov r2, sl
	bl CpuSet
	adds r6, #0x20
	mov r1, r8
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	adds r4, #8
	adds r0, r0, r4
	adds r0, r0, r5
	lsls r0, r0, #5
	ldr r2, _0807431C
	adds r1, r0, r2
	adds r0, r6, #0
	mov r2, sl
	bl CpuSet
	adds r6, #0x20
	adds r7, #1
	cmp r7, sb
	blt _080742B4
_08074304:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074314: .4byte 0x04000008
_08074318: .4byte 0x020205AC
_0807431C: .4byte 0x06010000
	thumb_func_end AddTextPrinterAndCreateWindowOnHealthbox

	thumb_func_start UpdateLeftNoOfBallsTextOnHealthbox
UpdateLeftNoOfBallsTextOnHealthbox: @ 0x08074320
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _080743D0
	mov r8, r0
	ldr r1, _080743D4
	bl StringCopy
	adds r7, r0, #0
	ldr r0, _080743D8
	ldrb r1, [r0]
	adds r0, r7, #0
	movs r2, #1
	movs r3, #2
	bl ConvertIntToDecimalStringN
	adds r7, r0, #0
	ldr r1, _080743DC
	bl StringAppend
	ldr r0, _080743E0
	lsls r4, r5, #4
	adds r4, r4, r5
	lsls r4, r4, #2
	adds r4, r4, r0
	ldrh r0, [r4, #0x3a]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerPosition
	ldr r1, _080743E4
	ldr r2, [r1]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r2, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #7
	movs r0, #0xa4
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r2]
	adds r7, r0, r1
	movs r6, #7
	adds r0, r7, #0
	movs r1, #7
	mov r2, r8
	bl RenderTextFont9
	adds r7, #0x20
	movs r5, #4
_08074390:
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x16
	lsrs r2, r0, #0x16
	adds r0, r5, #0
	cmp r5, #0
	bge _0807439E
	adds r0, r5, #7
_0807439E:
	asrs r0, r0, #3
	lsls r1, r0, #3
	subs r1, r5, r1
	adds r1, #0x18
	adds r1, r2, r1
	lsls r0, r0, #6
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _080743E8
	adds r1, r1, r0
	adds r0, r7, #0
	ldr r2, _080743EC
	bl CpuSet
	adds r7, #0x40
	adds r5, #1
	adds r0, r6, #4
	cmp r5, r0
	blt _08074390
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080743D0: .4byte 0x02022AE0
_080743D4: .4byte 0x085ABC43
_080743D8: .4byte 0x02039D18
_080743DC: .4byte 0x085ABC4B
_080743E0: .4byte 0x020205AC
_080743E4: .4byte 0x02024178
_080743E8: .4byte 0x06010000
_080743EC: .4byte 0x04000008
	thumb_func_end UpdateLeftNoOfBallsTextOnHealthbox
