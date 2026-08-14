.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
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

