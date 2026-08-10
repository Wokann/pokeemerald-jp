.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified





thumb_func_start __mdiff
__mdiff: @ 0x0829B2E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	adds r0, r5, #0
	mov r1, r8
	bl __mcmp
	adds r4, r0, #0
	cmp r4, #0
	bne _0829B316
	adds r0, r6, #0
	movs r1, #0
	bl _Balloc
	adds r7, r0, #0
	movs r0, #1
	str r0, [r7, #0x10]
	str r4, [r7, #0x14]
	b _0829B3C6
_0829B316:
	cmp r4, #0
	bge _0829B324
	adds r7, r5, #0
	mov r5, r8
	mov r8, r7
	movs r4, #1
	b _0829B326
_0829B324:
	movs r4, #0
_0829B326:
	ldr r1, [r5, #4]
	adds r0, r6, #0
	bl _Balloc
	adds r7, r0, #0
	str r4, [r7, #0xc]
	ldr r0, [r5, #0x10]
	mov sb, r0
	adds r6, r5, #0
	adds r6, #0x14
	lsls r0, r0, #2
	adds r0, r0, r6
	mov sl, r0
	mov r1, r8
	ldr r0, [r1, #0x10]
	movs r3, #0x14
	add r3, r8
	mov ip, r3
	lsls r0, r0, #2
	add r0, ip
	str r0, [sp]
	adds r4, r7, #0
	adds r4, #0x14
	movs r5, #0
	ldr r0, _0829B3B0
	mov r8, r0
_0829B35A:
	ldm r6!, {r1}
	str r1, [sp, #4]
	mov r3, r8
	ands r1, r3
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r0, r2, #0
	ands r0, r3
	subs r1, r1, r0
	adds r0, r1, r5
	asrs r5, r0, #0x10
	ldr r1, [sp, #4]
	lsrs r3, r1, #0x10
	lsrs r2, r2, #0x10
	subs r3, r3, r2
	adds r1, r3, r5
	asrs r5, r1, #0x10
	strh r1, [r4]
	strh r0, [r4, #2]
	adds r4, #4
	ldr r3, [sp]
	cmp ip, r3
	blo _0829B35A
	cmp r6, sl
	bhs _0829B3BA
	ldr r2, _0829B3B0
_0829B394:
	ldm r6!, {r1}
	adds r0, r1, #0
	ands r0, r2
	adds r0, r0, r5
	asrs r5, r0, #0x10
	lsrs r1, r1, #0x10
	adds r1, r1, r5
	asrs r5, r1, #0x10
	strh r1, [r4]
	strh r0, [r4, #2]
	adds r4, #4
	cmp r6, sl
	blo _0829B394
	b _0829B3BA
	.align 2, 0
_0829B3B0: .4byte 0x0000FFFF
_0829B3B4:
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
_0829B3BA:
	subs r4, #4
	ldr r0, [r4]
	cmp r0, #0
	beq _0829B3B4
	mov r1, sb
	str r1, [r7, #0x10]
_0829B3C6:
	adds r0, r7, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	thumb_func_end __mdiff

thumb_func_start _ulp
_ulp: @ 0x0829B3D4
	push {r4, lr}
	ldr r2, _0829B3E8
	ands r2, r0
	ldr r0, _0829B3EC
	adds r2, r2, r0
	cmp r2, #0
	ble _0829B3F0
	adds r3, r2, #0
	movs r4, #0
	b _0829B41A
	.align 2, 0
_0829B3E8: .4byte 0x7FF00000
_0829B3EC: .4byte 0xFCC00000
_0829B3F0:
	rsbs r0, r2, #0
	asrs r2, r0, #0x14
	cmp r2, #0x13
	bgt _0829B404
	movs r0, #0x80
	lsls r0, r0, #0xc
	adds r3, r0, #0
	asrs r3, r2
	movs r4, #0
	b _0829B41A
_0829B404:
	movs r3, #0
	subs r2, #0x14
	cmp r2, #0x1e
	bgt _0829B416
	movs r0, #0x1f
	subs r0, r0, r2
	movs r1, #1
	lsls r1, r0
	b _0829B418
_0829B416:
	movs r1, #1
_0829B418:
	adds r4, r1, #0
_0829B41A:
	adds r1, r4, #0
	adds r0, r3, #0
	pop {r4, pc}
	thumb_func_end _ulp

thumb_func_start _b2d
_b2d: @ 0x0829B420
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r1, #0
	movs r1, #0x14
	adds r1, r1, r0
	mov r8, r1
	ldr r0, [r0, #0x10]
	lsls r0, r0, #2
	adds r5, r1, r0
	subs r5, #4
	ldr r2, [r5]
	adds r0, r2, #0
	str r2, [sp]
	bl _hi0bits
	adds r3, r0, #0
	movs r0, #0x20
	subs r0, r0, r3
	str r0, [r4]
	ldr r2, [sp]
	cmp r3, #0xa
	bgt _0829B480
	movs r0, #0xb
	subs r0, r0, r3
	adds r1, r2, #0
	lsrs r1, r0
	ldr r0, _0829B468
	adds r6, r1, #0
	orrs r6, r0
	cmp r5, r8
	bls _0829B46C
	subs r5, #4
	ldr r1, [r5]
	b _0829B46E
	.align 2, 0
_0829B468: .4byte 0x3FF00000
_0829B46C:
	movs r1, #0
_0829B46E:
	adds r0, r3, #0
	adds r0, #0x15
	lsls r2, r0
	movs r0, #0xb
	subs r0, r0, r3
	lsrs r1, r0
	adds r7, r2, #0
	orrs r7, r1
	b _0829B4CC
_0829B480:
	cmp r5, r8
	bls _0829B48A
	subs r5, #4
	ldr r4, [r5]
	b _0829B48C
_0829B48A:
	movs r4, #0
_0829B48C:
	subs r3, #0xb
	cmp r3, #0
	beq _0829B4C4
	lsls r2, r3
	movs r0, #0x20
	subs r0, r0, r3
	adds r1, r4, #0
	lsrs r1, r0
	ldr r0, _0829B4B0
	orrs r1, r0
	adds r6, r2, #0
	orrs r6, r1
	cmp r5, r8
	bls _0829B4B4
	subs r5, #4
	ldr r2, [r5]
	b _0829B4B6
	.align 2, 0
_0829B4B0: .4byte 0x3FF00000
_0829B4B4:
	movs r2, #0
_0829B4B6:
	lsls r4, r3
	movs r0, #0x20
	subs r0, r0, r3
	lsrs r2, r0
	adds r7, r4, #0
	orrs r7, r2
	b _0829B4CC
_0829B4C4:
	ldr r0, _0829B4D8
	adds r6, r2, #0
	orrs r6, r0
	adds r7, r4, #0
_0829B4CC:
	adds r1, r7, #0
	adds r0, r6, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829B4D8: .4byte 0x3FF00000
	thumb_func_end _b2d

thumb_func_start _d2b
_d2b: @ 0x0829B4DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r3
	ldr r3, [sp, #0x28]
	mov sl, r3
	adds r5, r2, #0
	adds r4, r1, #0
	movs r1, #1
	bl _Balloc
	adds r6, r0, #0
	movs r0, #0x14
	adds r0, r0, r6
	mov r8, r0
	ldr r2, _0829B544
	adds r1, r4, #0
	ands r2, r1
	str r2, [sp, #4]
	ldr r0, _0829B548
	ands r4, r0
	lsrs r7, r4, #0x14
	cmp r7, #0
	beq _0829B51A
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r0, r2
	str r0, [sp, #4]
_0829B51A:
	str r5, [sp]
	cmp r5, #0
	beq _0829B564
	mov r0, sp
	bl _lo0bits
	adds r2, r0, #0
	cmp r2, #0
	beq _0829B54C
	movs r0, #0x20
	subs r0, r0, r2
	ldr r1, [sp, #4]
	lsls r1, r0
	ldr r0, [sp]
	orrs r0, r1
	str r0, [r6, #0x14]
	ldr r0, [sp, #4]
	lsrs r0, r2
	str r0, [sp, #4]
	b _0829B550
	.align 2, 0
_0829B544: .4byte 0x000FFFFF
_0829B548: .4byte 0x7FFFFFFF
_0829B54C:
	ldr r0, [sp]
	str r0, [r6, #0x14]
_0829B550:
	ldr r0, [sp, #4]
	mov r1, r8
	str r0, [r1, #4]
	movs r1, #1
	cmp r0, #0
	beq _0829B55E
	movs r1, #2
_0829B55E:
	str r1, [r6, #0x10]
	adds r4, r1, #0
	b _0829B578
_0829B564:
	add r0, sp, #4
	bl _lo0bits
	adds r2, r0, #0
	ldr r0, [sp, #4]
	str r0, [r6, #0x14]
	movs r0, #1
	str r0, [r6, #0x10]
	movs r4, #1
	adds r2, #0x20
_0829B578:
	cmp r7, #0
	beq _0829B594
	ldr r3, _0829B590
	adds r0, r2, r3
	adds r0, r7, r0
	mov r1, sb
	str r0, [r1]
	movs r0, #0x35
	subs r0, r0, r2
	mov r3, sl
	str r0, [r3]
	b _0829B5B0
	.align 2, 0
_0829B590: .4byte 0xFFFFFBCD
_0829B594:
	ldr r1, _0829B5C0
	adds r0, r2, r1
	mov r3, sb
	str r0, [r3]
	lsls r0, r4, #2
	add r0, r8
	subs r0, #4
	ldr r0, [r0]
	bl _hi0bits
	lsls r1, r4, #5
	subs r1, r1, r0
	mov r0, sl
	str r1, [r0]
_0829B5B0:
	adds r0, r6, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829B5C0: .4byte 0xFFFFFBCE
	thumb_func_end _d2b

thumb_func_start _ratio
_ratio: @ 0x0829B5C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	mov r1, sp
	bl _b2d
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #4
	adds r0, r5, #0
	bl _b2d
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, [sp]
	ldr r0, [sp, #4]
	subs r2, r2, r0
	ldr r0, [r4, #0x10]
	ldr r1, [r5, #0x10]
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r0, r2, r0
	cmp r0, #0
	ble _0829B600
	lsls r0, r0, #0x14
	ldr r1, [sp, #8]
	adds r0, r1, r0
	str r0, [sp, #8]
	b _0829B604
_0829B600:
	lsls r0, r0, #0x14
	subs r6, r6, r0
_0829B604:
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __divdf3
	add sp, #0x10
	pop {r4, r5, r6, r7, pc}
	thumb_func_end _ratio

thumb_func_start _mprec_log10
_mprec_log10: @ 0x0829B614
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0829B630
	ldr r0, _0829B62C
	cmp r4, #0x17
	bgt _0829B638
	ldr r0, _0829B634
	lsls r1, r4, #3
	adds r1, r1, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	b _0829B64A
	.align 2, 0
_0829B62C: .4byte 0x3FF00000
_0829B630: .4byte 0x00000000
_0829B634: .4byte 0x0890F234
_0829B638:
	cmp r4, #0
	ble _0829B64A
_0829B63C:
	ldr r3, _0829B650
	ldr r2, _0829B64C
	bl __muldf3
	subs r4, #1
	cmp r4, #0
	bgt _0829B63C
_0829B64A:
	pop {r4, pc}
	.align 2, 0
_0829B64C: .4byte 0x40240000
_0829B650: .4byte 0x00000000
	thumb_func_end _mprec_log10

thumb_func_start isinf
isinf: @ 0x0829B654
	ldr r3, _0829B670
	ands r3, r0
	rsbs r2, r1, #0
	orrs r2, r1
	lsrs r2, r2, #0x1f
	orrs r3, r2
	ldr r0, _0829B674
	subs r3, r0, r3
	rsbs r0, r3, #0
	orrs r3, r0
	lsrs r3, r3, #0x1f
	movs r0, #1
	subs r0, r0, r3
	bx lr
	.align 2, 0
_0829B670: .4byte 0x7FFFFFFF
_0829B674: .4byte 0x7FF00000
	thumb_func_end isinf

thumb_func_start isnan
isnan: @ 0x0829B678
	ldr r3, _0829B690
	ands r3, r0
	rsbs r2, r1, #0
	orrs r2, r1
	lsrs r2, r2, #0x1f
	orrs r3, r2
	ldr r0, _0829B694
	subs r3, r0, r3
	lsrs r3, r3, #0x1f
	adds r0, r3, #0
	bx lr
	.align 2, 0
_0829B690: .4byte 0x7FFFFFFF
_0829B694: .4byte 0x7FF00000
	thumb_func_end isnan

thumb_func_start _sbrk_r
_sbrk_r: @ 0x0829B698
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	ldr r4, _0829B6C0
	movs r1, #0
	str r1, [r4]
	bl _sbrk
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0829B6BA
	ldr r0, [r4]
	cmp r0, #0
	beq _0829B6BA
	str r0, [r5]
_0829B6BA:
	adds r0, r1, #0
	pop {r4, r5, pc}
	.align 2, 0
_0829B6C0: .4byte 0x0300764C
	thumb_func_end _sbrk_r

thumb_func_start __sread
__sread: @ 0x0829B6C4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	ldr r0, [r5, #0x54]
	movs r2, #0xe
	ldrsh r1, [r5, r2]
	adds r2, r4, #0
	bl _read_r
	adds r1, r0, #0
	cmp r1, #0
	blt _0829B6E6
	ldr r0, [r5, #0x50]
	adds r0, r0, r1
	str r0, [r5, #0x50]
	b _0829B6EE
_0829B6E6:
	ldr r0, _0829B6F4
	ldrh r2, [r5, #0xc]
	ands r0, r2
	strh r0, [r5, #0xc]
_0829B6EE:
	adds r0, r1, #0
	pop {r4, r5, pc}
	.align 2, 0
_0829B6F4: .4byte 0xFFFFEFFF
	thumb_func_end __sread

thumb_func_start __swrite
__swrite: @ 0x0829B6F8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0829B71A
	ldr r0, [r4, #0x54]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	movs r2, #0
	movs r3, #2
	bl _lseek_r
_0829B71A:
	ldr r0, _0829B734
	ldrh r1, [r4, #0xc]
	ands r0, r1
	strh r0, [r4, #0xc]
	ldr r0, [r4, #0x54]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	adds r2, r5, #0
	adds r3, r6, #0
	bl _write_r
	pop {r4, r5, r6, pc}
	.align 2, 0
_0829B734: .4byte 0xFFFFEFFF
	thumb_func_end __swrite

thumb_func_start __sseek
__sseek: @ 0x0829B738
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	ldr r0, [r5, #0x54]
	movs r2, #0xe
	ldrsh r1, [r5, r2]
	adds r2, r4, #0
	bl _lseek_r
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0829B764
	ldr r0, _0829B760
	ldrh r2, [r5, #0xc]
	ands r0, r2
	strh r0, [r5, #0xc]
	b _0829B772
	.align 2, 0
_0829B760: .4byte 0xFFFFEFFF
_0829B764:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	ldrh r2, [r5, #0xc]
	orrs r0, r2
	strh r0, [r5, #0xc]
	str r1, [r5, #0x50]
_0829B772:
	adds r0, r1, #0
	pop {r4, r5, pc}
	.align 2, 0
	thumb_func_end __sseek

thumb_func_start __sclose
__sclose: @ 0x0829B778
	push {lr}
	ldr r2, [r0, #0x54]
	movs r3, #0xe
	ldrsh r1, [r0, r3]
	adds r0, r2, #0
	bl _close_r
	pop {pc}
	thumb_func_end __sclose

