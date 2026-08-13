.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	.section .text.cable_car_mid,"ax",%progbits





	.section .text.cable_car_mid2,"ax",%progbits

	thumb_func_start sub_081511F0
sub_081511F0: @ 0x081511F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r7, #0
	ldr r3, _08151354
	ldr r0, [r3]
	strb r7, [r0, #0x1e]
	strb r7, [r0, #0x1d]
	ldr r1, [r3]
	ldrb r0, [r1, #8]
	strb r0, [r1, #0x1f]
	ldr r0, [r3]
	ldrb r1, [r0, #9]
	adds r0, #0x20
	strb r1, [r0]
	ldr r4, [r3]
	ldrb r1, [r4, #0x19]
	adds r2, r1, #0
	adds r2, #0x1e
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r4, #0x19]
	ldr r1, [r3]
	ldrb r0, [r1, #0x18]
	subs r0, #2
	strb r0, [r1, #0x18]
	ldr r4, _08151358
	ldr r0, [r3]
	ldrb r1, [r0, #0x1a]
	adds r2, r1, #0
	adds r2, #0x17
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r4]
	ldr r6, _0815135C
	mov sb, r3
	ldr r0, _08151360
	mov r8, r0
_0815124A:
	mov r1, sb
	ldr r2, [r1]
	ldrb r0, [r2, #0x19]
	strb r0, [r6]
	ldr r0, _08151358
	ldrb r0, [r0]
	adds r1, r0, r7
	adds r0, r1, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r1, r0
	mov r1, r8
	strb r0, [r1]
	ldrb r1, [r2, #0x18]
	lsls r1, r1, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r5, r0, #3
	adds r1, r1, r5
	adds r0, r2, #0
	adds r0, #0x22
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrb r2, [r6]
	mov r0, r8
	ldrb r3, [r0]
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x11
	mov sl, r0
	str r0, [sp, #8]
	movs r0, #0
	bl FillBgTilemapBufferRect
	ldrb r1, [r6]
	adds r2, r1, #1
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r6]
	mov r0, sb
	ldr r1, [r0]
	ldrb r0, [r1, #0x18]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	adds r1, #0x22
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrb r2, [r6]
	mov r0, r8
	ldrb r3, [r0]
	str r4, [sp]
	str r4, [sp, #4]
	mov r0, sl
	str r0, [sp, #8]
	movs r0, #0
	bl FillBgTilemapBufferRect
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #8
	bls _0815124A
	ldr r5, _0815135C
	ldr r4, _08151354
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	adds r2, r1, #0
	adds r2, #0x1e
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r5]
	ldrb r2, [r5]
	movs r0, #2
	str r0, [sp]
	movs r6, #0x20
	str r6, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FillBgTilemapBufferRect
	ldr r1, [r4]
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	bne _08151344
	ldrb r2, [r1, #0x1a]
	adds r3, r2, #0
	adds r3, #0x1d
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1, #0x1a]
	ldr r1, [r4]
	movs r0, #0xc
	strb r0, [r1, #0x18]
	bl BufferNextGroundSegment
	ldr r0, [r4]
	ldrb r1, [r0, #0x1a]
	adds r2, r1, #1
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r5]
	ldrb r3, [r5]
	str r6, [sp]
	movs r0, #9
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FillBgTilemapBufferRect
_08151344:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08151354: .4byte 0x0203A878
_08151358: .4byte 0x0203A87E
_0815135C: .4byte 0x0203A87C
_08151360: .4byte 0x0203A87D
	thumb_func_end sub_081511F0

	thumb_func_start DrawNextGroundSegmentGoingDown
DrawNextGroundSegmentGoingDown: @ 0x08151364
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r7, #0
	ldr r2, _08151494
	ldr r0, [r2]
	strb r7, [r0, #0x1e]
	strb r7, [r0, #0x1d]
	ldr r1, [r2]
	ldrb r0, [r1, #8]
	strb r0, [r1, #0x1f]
	ldr r0, [r2]
	ldrb r1, [r0, #9]
	adds r0, #0x20
	strb r1, [r0]
	ldr r4, [r2]
	ldrb r1, [r4, #0x19]
	adds r3, r1, #2
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r4, #0x19]
	ldr r1, [r2]
	ldrb r0, [r1, #0x18]
	adds r0, #2
	strb r0, [r1, #0x18]
	ldr r1, _08151498
	ldr r0, [r2]
	ldrb r0, [r0, #0x1a]
	strb r0, [r1]
	ldr r6, _0815149C
	mov sl, r2
	ldr r0, _081514A0
	mov sb, r0
_081513B0:
	mov r1, sl
	ldr r2, [r1]
	ldrb r0, [r2, #0x19]
	strb r0, [r6]
	ldr r0, _08151498
	ldrb r0, [r0]
	adds r1, r0, r7
	adds r0, r1, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r1, r0
	mov r1, sb
	strb r0, [r1]
	ldrb r1, [r2, #0x18]
	lsls r1, r1, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r5, r0, #3
	adds r1, r1, r5
	adds r0, r2, #0
	adds r0, #0x22
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrb r2, [r6]
	mov r0, sb
	ldrb r3, [r0]
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x11
	mov r8, r0
	str r0, [sp, #8]
	movs r0, #0
	bl FillBgTilemapBufferRect
	ldrb r1, [r6]
	adds r2, r1, #1
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r6]
	mov r0, sl
	ldr r1, [r0]
	ldrb r0, [r1, #0x18]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	adds r1, #0x22
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrb r2, [r6]
	mov r0, sb
	ldrb r3, [r0]
	str r4, [sp]
	str r4, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	movs r0, #0
	bl FillBgTilemapBufferRect
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #8
	bls _081513B0
	ldr r4, _081514A0
	ldr r5, _08151494
	ldr r3, [r5]
	ldrb r1, [r3, #0x1a]
	adds r2, r1, #0
	adds r2, #0x17
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r4]
	ldrb r2, [r3, #0x19]
	ldrb r3, [r4]
	movs r0, #2
	str r0, [sp]
	movs r0, #9
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	bl FillBgTilemapBufferRect
	ldr r1, [r5]
	ldrb r0, [r1, #0x18]
	cmp r0, #0xa
	bne _08151482
	ldrb r2, [r1, #0x1a]
	adds r3, r2, #3
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1, #0x1a]
	ldr r1, [r5]
	movs r0, #0xfe
	strb r0, [r1, #0x18]
	bl BufferNextGroundSegment
_08151482:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08151494: .4byte 0x0203A878
_08151498: .4byte 0x0203A881
_0815149C: .4byte 0x0203A87F
_081514A0: .4byte 0x0203A880
	thumb_func_end DrawNextGroundSegmentGoingDown
