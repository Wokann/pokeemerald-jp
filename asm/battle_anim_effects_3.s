.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	.section .text.battle_anim_effects_3_rest,"ax",%progbits

	thumb_func_start sub_0815A440
sub_0815A440: @ 0x0815A440
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0815A45C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldr r0, _0815A460
	str r0, [r1]
	ldr r1, _0815A464
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0815A45C: .4byte 0x03005B60
_0815A460: .4byte 0x0815A469
_0815A464: .4byte 0x0203809E
	thumb_func_end sub_0815A440

	thumb_func_start sub_0815A468
sub_0815A468: @ 0x0815A468
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_080A665C
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r7, _0815A4F4
	lsls r5, r4, #2
	adds r1, r5, r4
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrh r0, [r1, #0x12]
	adds r0, #1
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _0815A4D8
	ldr r0, _0815A4F8
	lsls r2, r6, #4
	adds r1, r2, #0
	adds r1, #0xb
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r3, [r1]
	mov r8, r3
	movs r3, #0xa
	mov sb, r7
	adds r7, r5, #0
	mov ip, r0
	adds r5, r2, #0
	lsls r0, r6, #5
	add r0, ip
	adds r2, r0, #0
	adds r2, #0x14
_0815A4B6:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r2, #2
	subs r1, #2
	subs r3, #1
	cmp r3, #0
	bgt _0815A4B6
	adds r0, r5, #1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	mov r2, r8
	strh r2, [r0]
	adds r0, r7, r4
	lsls r0, r0, #3
	add r0, sb
	strh r1, [r0, #0x12]
_0815A4D8:
	ldr r0, _0815A4FC
	ldrh r1, [r0, #0xe]
	ldr r0, _0815A500
	cmp r1, r0
	bne _0815A4E8
	adds r0, r4, #0
	bl DestroyTask
_0815A4E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815A4F4: .4byte 0x03005B60
_0815A4F8: .4byte 0x020377B4
_0815A4FC: .4byte 0x020380BE
_0815A500: .4byte 0x0000FFFF
	thumb_func_end sub_0815A468


	.section .text.battle_anim_effects_3_rest5,"ax",%progbits











