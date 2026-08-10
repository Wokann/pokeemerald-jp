.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified





thumb_func_start _i2b
_i2b: @ 0x0829AFEC
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #1
	bl _Balloc
	str r4, [r0, #0x14]
	movs r1, #1
	str r1, [r0, #0x10]
	pop {r4, pc}
	.align 2, 0
	thumb_func_end _i2b

thumb_func_start _multiply
_multiply: @ 0x0829B000
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, [r4, #0x10]
	ldr r0, [r5, #0x10]
	cmp r1, r0
	bge _0829B020
	str r4, [sp]
	adds r4, r5, #0
	ldr r5, [sp]
_0829B020:
	ldr r1, [r4, #4]
	ldr r6, [r4, #0x10]
	ldr r0, [r5, #0x10]
	mov r8, r0
	mov r2, r8
	adds r2, r6, r2
	str r2, [sp, #4]
	ldr r0, [r4, #8]
	cmp r2, r0
	ble _0829B036
	adds r1, #1
_0829B036:
	adds r0, r3, #0
	bl _Balloc
	str r0, [sp]
	adds r7, r0, #0
	adds r7, #0x14
	ldr r1, [sp, #4]
	lsls r0, r1, #2
	adds r2, r7, r0
	str r2, [sp, #8]
	str r0, [sp, #0x18]
	adds r1, r4, #0
	adds r1, #0x14
	lsls r3, r6, #2
	adds r2, r5, #0
	adds r2, #0x14
	mov r5, r8
	lsls r4, r5, #2
	ldr r0, [sp, #8]
	cmp r7, r0
	bhs _0829B06A
	movs r0, #0
_0829B062:
	stm r7!, {r0}
	ldr r5, [sp, #8]
	cmp r7, r5
	blo _0829B062
_0829B06A:
	str r1, [sp, #8]
	adds r3, r1, r3
	str r3, [sp, #0xc]
	mov r8, r2
	add r4, r8
	str r4, [sp, #0x10]
	ldr r0, [sp]
	adds r0, #0x14
	mov sb, r0
	mov r1, sb
	str r1, [sp, #0x20]
	cmp r8, r4
	bhs _0829B132
_0829B084:
	mov r2, r8
	ldm r2!, {r6}
	str r2, [sp, #0x14]
	ldr r0, _0829B140
	ands r6, r0
	mov r4, sb
	adds r4, #4
	str r4, [sp, #0x1c]
	cmp r6, #0
	beq _0829B0DC
	ldr r7, [sp, #8]
	mov r5, sb
	movs r1, #0
	mov ip, r1
	mov sl, r0
_0829B0A2:
	ldm r7!, {r3}
	adds r0, r3, #0
	mov r2, sl
	ands r0, r2
	adds r1, r0, #0
	muls r1, r6, r1
	ldr r2, [r5]
	adds r0, r2, #0
	mov r4, sl
	ands r0, r4
	adds r1, r1, r0
	mov r0, ip
	adds r4, r1, r0
	lsrs r1, r4, #0x10
	lsrs r3, r3, #0x10
	adds r0, r3, #0
	muls r0, r6, r0
	lsrs r2, r2, #0x10
	adds r0, r0, r2
	adds r2, r0, r1
	lsrs r0, r2, #0x10
	mov ip, r0
	strh r2, [r5]
	strh r4, [r5, #2]
	adds r5, #4
	ldr r1, [sp, #0xc]
	cmp r7, r1
	blo _0829B0A2
	str r0, [r5]
_0829B0DC:
	mov r2, r8
	ldrh r6, [r2, #2]
	cmp r6, #0
	beq _0829B124
	ldr r7, [sp, #8]
	mov r5, sb
	movs r4, #0
	mov ip, r4
	ldr r2, [r5]
	ldr r3, _0829B140
_0829B0F0:
	ldm r7!, {r1}
	adds r0, r1, #0
	ands r0, r3
	muls r0, r6, r0
	ldrh r4, [r5, #2]
	adds r4, r4, r0
	mov r8, r4
	add r4, ip
	lsrs r0, r4, #0x10
	mov ip, r0
	strh r4, [r5]
	strh r2, [r5, #2]
	adds r5, #4
	lsrs r1, r1, #0x10
	muls r1, r6, r1
	ldr r0, [r5]
	ands r0, r3
	adds r1, r1, r0
	mov r4, ip
	adds r2, r1, r4
	lsrs r0, r2, #0x10
	mov ip, r0
	ldr r1, [sp, #0xc]
	cmp r7, r1
	blo _0829B0F0
	str r2, [r5]
_0829B124:
	ldr r2, [sp, #0x14]
	mov r8, r2
	ldr r4, [sp, #0x1c]
	mov sb, r4
	ldr r5, [sp, #0x10]
	cmp r8, r5
	blo _0829B084
_0829B132:
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x18]
	adds r5, r0, r1
	ldr r2, [sp, #4]
	cmp r2, #0
	ble _0829B156
	b _0829B14E
	.align 2, 0
_0829B140: .4byte 0x0000FFFF
_0829B144:
	ldr r4, [sp, #4]
	subs r4, #1
	str r4, [sp, #4]
	cmp r4, #0
	ble _0829B156
_0829B14E:
	subs r5, #4
	ldr r0, [r5]
	cmp r0, #0
	beq _0829B144
_0829B156:
	ldr r5, [sp, #4]
	ldr r0, [sp]
	str r5, [r0, #0x10]
	ldr r0, [sp]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	thumb_func_end _multiply

thumb_func_start _pow5mult
_pow5mult: @ 0x0829B16C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r1, #3
	ands r1, r6
	cmp r1, #0
	beq _0829B196
	ldr r0, _0829B1B8
	subs r1, #1
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r2, [r1]
	mov r0, r8
	adds r1, r7, #0
	movs r3, #0
	bl _multadd
	adds r7, r0, #0
_0829B196:
	asrs r6, r6, #2
	cmp r6, #0
	beq _0829B1FC
	mov r0, r8
	ldr r5, [r0, #0x48]
	adds r4, r5, #0
	cmp r5, #0
	bne _0829B1D8
	ldr r1, _0829B1BC
	bl _i2b
	mov r1, r8
	str r0, [r1, #0x48]
	adds r5, r0, #0
	str r4, [r5]
	b _0829B1D8
	.align 2, 0
_0829B1B8: .4byte 0x0890F228
_0829B1BC: .4byte 0x00000271
_0829B1C0:
	ldr r0, [r5]
	adds r4, r0, #0
	cmp r0, #0
	bne _0829B1D6
	mov r0, r8
	adds r1, r5, #0
	adds r2, r5, #0
	bl _multiply
	str r0, [r5]
	str r4, [r0]
_0829B1D6:
	adds r5, r0, #0
_0829B1D8:
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _0829B1F6
	mov r0, r8
	adds r1, r7, #0
	adds r2, r5, #0
	bl _multiply
	adds r4, r0, #0
	mov r0, r8
	adds r1, r7, #0
	bl _Bfree
	adds r7, r4, #0
_0829B1F6:
	asrs r6, r6, #1
	cmp r6, #0
	bne _0829B1C0
_0829B1FC:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	thumb_func_end _pow5mult

thumb_func_start _lshift
_lshift: @ 0x0829B204
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	mov r8, r1
	adds r5, r2, #0
	asrs r6, r5, #5
	ldr r1, [r1, #4]
	mov r2, r8
	ldr r0, [r2, #0x10]
	adds r0, r6, r0
	adds r7, r0, #1
	ldr r2, [r2, #8]
	cmp r7, r2
	ble _0829B22E
_0829B226:
	adds r1, #1
	lsls r2, r2, #1
	cmp r7, r2
	bgt _0829B226
_0829B22E:
	mov r0, sl
	bl _Balloc
	mov sb, r0
	mov r4, sb
	adds r4, #0x14
	mov r0, r8
	adds r0, #0x14
	cmp r6, #0
	ble _0829B24E
	movs r1, #0
	adds r2, r6, #0
_0829B246:
	stm r4!, {r1}
	subs r2, #1
	cmp r2, #0
	bne _0829B246
_0829B24E:
	adds r3, r0, #0
	mov r1, r8
	ldr r0, [r1, #0x10]
	lsls r0, r0, #2
	adds r6, r3, r0
	movs r0, #0x1f
	ands r5, r0
	cmp r5, #0
	beq _0829B280
	movs r0, #0x20
	subs r1, r0, r5
	movs r2, #0
_0829B266:
	ldr r0, [r3]
	lsls r0, r5
	orrs r0, r2
	stm r4!, {r0}
	ldm r3!, {r2}
	lsrs r2, r1
	cmp r3, r6
	blo _0829B266
	str r2, [r4]
	cmp r2, #0
	beq _0829B288
	adds r7, #1
	b _0829B288
_0829B280:
	ldm r3!, {r0}
	stm r4!, {r0}
	cmp r3, r6
	blo _0829B280
_0829B288:
	subs r0, r7, #1
	mov r2, sb
	str r0, [r2, #0x10]
	mov r0, sl
	mov r1, r8
	bl _Bfree
	mov r0, sb
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	thumb_func_end _lshift

