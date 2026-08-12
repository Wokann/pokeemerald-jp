.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



































	thumb_func_start sub_080260EC
sub_080260EC: @ 0x080260EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _080261C0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x44
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r1, #0
	adds r0, #0x48
	ldrb r0, [r0]
	str r0, [sp, #4]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	str r0, [sp, #8]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _08026120
	b _080263DC
_08026120:
	movs r6, #0
	ldr r0, [sp, #8]
	cmp r6, r0
	bhs _08026208
_08026128:
	ldr r3, _080261C0
	lsls r0, r6, #4
	subs r1, r0, r6
	lsls r1, r1, #2
	ldr r2, [r3]
	adds r1, r1, r2
	ldr r4, _080261C4
	adds r4, r4, r1
	mov r8, r4
	ldrb r1, [r4]
	mov sb, r0
	adds r0, r6, #1
	str r0, [sp, #0xc]
	cmp r1, #0
	beq _080261FC
	adds r0, r2, #0
	adds r0, #0xa8
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #1
	bne _080261FC
	ldr r1, [sp]
	mov sl, r1
	ldr r2, [sp, #4]
	cmp sl, r2
	bhs _080261FC
	adds r7, r3, #0
_0802615E:
	ldr r0, _080261C8
	add r0, sl
	ldrb r5, [r0]
	ldr r1, [r7]
	lsls r4, r5, #1
	adds r0, r1, #0
	adds r0, #0xf4
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, r6
	beq _080261FC
	adds r0, r1, #0
	adds r0, #0xf5
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, r6
	beq _080261FC
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r2, r5, #0
	bl sub_080263FC
	cmp r0, #1
	bne _080261D8
	movs r2, #0
	ldr r3, _080261C0
	mov r8, r4
_08026196:
	ldr r0, [r3]
	mov r4, r8
	adds r1, r2, r4
	adds r0, #0xf4
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080261CC
	strb r6, [r1]
	ldr r0, [r3]
	adds r0, #0xa8
	adds r0, r0, r6
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0xc4
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	b _080261FC
	.align 2, 0
_080261C0: .4byte 0x0202294C
_080261C4: .4byte 0x000031CC
_080261C8: .4byte 0x082C7D28
_080261CC:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #1
	bls _08026196
	b _080261FC
_080261D8:
	ldr r0, [r7]
	mov r2, sb
	subs r1, r2, r6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r4, _080262CC
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _080261FC
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r0, [sp, #4]
	cmp sl, r0
	blo _0802615E
_080261FC:
	ldr r1, [sp, #0xc]
	lsls r0, r1, #0x18
	lsrs r6, r0, #0x18
	ldr r2, [sp, #8]
	cmp r6, r2
	blo _08026128
_08026208:
	ldr r4, [sp]
	mov sl, r4
	ldr r0, [sp, #4]
	cmp sl, r0
	blo _08026214
	b _080263DC
_08026214:
	ldr r1, _080262D0
	mov sb, r1
_08026218:
	movs r6, #0xff
	ldr r0, _080262D4
	add r0, sl
	ldrb r5, [r0]
	mov r2, sb
	ldr r0, [r2]
	adds r0, #0xc4
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #1
	beq _08026230
	b _080263CA
_08026230:
	adds r0, r5, #0
	bl sub_08026B4C
	mov r1, sb
	ldr r4, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	adds r1, #0x90
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _08026256
	movs r3, #2
_08026256:
	ldr r2, _080262D8
	ldr r0, _080262DC
	adds r1, r4, r0
	adds r1, r1, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xd0
	adds r0, r0, r5
	ldrb r0, [r0]
	subs r2, r1, r0
	cmp r2, #5
	bgt _08026284
	adds r1, r4, #0
	adds r1, #0x9c
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, r0, r2
	strb r0, [r1]
_08026284:
	mov r2, sb
	ldr r1, [r2]
	adds r1, #0x9c
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r4, #0xff
	ands r0, r4
	cmp r0, #5
	bhi _0802629E
	b _080263CA
_0802629E:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x9c
	adds r0, r0, r5
	strb r2, [r0]
	ldr r3, [r1]
	lsls r1, r5, #1
	adds r0, r3, #0
	adds r0, #0xf4
	adds r2, r0, r1
	ldrb r0, [r2]
	mov r8, r1
	cmp r0, #0xff
	bne _080262E0
	adds r0, r3, #0
	adds r0, #0xf5
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080262C8
	b _080263CA
_080262C8:
	b _080262F0
	.align 2, 0
_080262CC: .4byte 0x000031D4
_080262D0: .4byte 0x0202294C
_080262D4: .4byte 0x082C7D28
_080262D8: .4byte 0x082CB314
_080262DC: .4byte 0x000031B4
_080262E0:
	adds r0, r3, #0
	adds r0, #0xf5
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080262F0
	ldrb r4, [r2]
	b _08026316
_080262F0:
	mov r2, sb
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0xf4
	add r0, r8
	ldrb r7, [r0]
	adds r1, #0xf5
	add r1, r8
	ldrb r6, [r1]
	bl Random
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08026312
	adds r4, r7, #0
	b _08026316
_08026312:
	adds r4, r6, #0
	adds r6, r7, #0
_08026316:
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _080263EC
	adds r0, r0, r2
	adds r0, r0, r5
	movs r1, #7
	strb r1, [r0]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0xc4
	adds r0, r0, r5
	movs r1, #2
	strb r1, [r0]
	mov r2, sb
	ldr r0, [r2]
	adds r0, #0xa8
	adds r0, r0, r4
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xb8
	adds r0, r0, r5
	strb r4, [r0]
	ldr r1, [r2]
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r2, _080263F0
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r6, #4
	subs r0, r0, r6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, _080263F4
	adds r1, r1, r0
	movs r2, #1
	strb r2, [r1]
	mov r0, sb
	ldr r1, [r0]
	lsls r0, r4, #1
	adds r1, #0x86
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl sub_08026CDC
	movs r0, #1
	bl sub_08026FF4
	adds r0, r4, #0
	bl sub_08026ADC
	mov r1, sb
	ldr r0, [r1]
	adds r1, r0, #0
	adds r1, #0xe8
	adds r1, r1, r5
	ldr r2, _080263F8
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	mov r4, sb
	ldr r0, [r4]
	adds r0, r0, r2
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, #0xf4
	add r1, r8
	ldrb r0, [r1]
	movs r2, #0xff
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, #0xf5
	add r1, r8
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
_080263CA:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r4, [sp, #4]
	cmp sl, r4
	bhs _080263DC
	b _08026218
_080263DC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080263EC: .4byte 0x000032EB
_080263F0: .4byte 0x000031D0
_080263F4: .4byte 0x000031D4
_080263F8: .4byte 0x000032E0
	thumb_func_end sub_080260EC
