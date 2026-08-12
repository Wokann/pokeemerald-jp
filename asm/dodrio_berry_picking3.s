.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified






	thumb_func_start sub_08026B4C
sub_08026B4C: @ 0x08026B4C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _08026B68
	ldr r1, _08026B6C
	ldr r1, [r1]
	adds r1, #0x24
	ldrb r1, [r1]
	subs r1, #1
	movs r2, #0xb
	muls r1, r2, r1
	adds r0, r0, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08026B68: .4byte 0x082C7ED4
_08026B6C: .4byte 0x0202294C
	thumb_func_end sub_08026B4C

	thumb_func_start sub_08026B70
sub_08026B70: @ 0x08026B70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r4, _08026BF0
	ldr r1, [r4]
	adds r1, #0x24
	ldrb r2, [r1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r3, _08026BF4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r2, #4
	subs r0, r0, r2
	adds r1, r1, r0
	adds r0, r1, r3
	ldrb r0, [r0]
	mov ip, r0
	adds r0, r3, #1
	adds r0, r1, r0
	ldrb r7, [r0]
	adds r3, #2
	adds r1, r1, r3
	ldrb r1, [r1]
	mov r8, r1
	movs r3, #0
	ldr r1, _08026BF8
	lsls r0, r2, #2
	adds r2, r0, r2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08026BD8
	adds r6, r1, #0
_08026BBE:
	adds r0, r3, r2
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r5, r0
	beq _08026BFC
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r0, r3, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08026BBE
_08026BD8:
	ldr r0, [r4]
	adds r0, #0x90
	mov r1, ip
	adds r2, r0, r1
	adds r1, r0, r7
	ldrb r0, [r2]
	ldrb r3, [r1]
	cmp r0, r3
	bls _08026C06
	adds r1, r0, #0
	b _08026C08
	.align 2, 0
_08026BF0: .4byte 0x0202294C
_08026BF4: .4byte 0x082C7E86
_08026BF8: .4byte 0x082C7F0B
_08026BFC:
	ldr r0, [r4]
	adds r0, #0x90
	adds r0, r0, r7
	ldrb r0, [r0]
	b _08026C1A
_08026C06:
	ldrb r1, [r1]
_08026C08:
	ldr r0, [r4]
	adds r0, #0x90
	mov r2, r8
	adds r4, r0, r2
	ldrb r0, [r4]
	cmp r0, r1
	bls _08026C18
	adds r1, r0, #0
_08026C18:
	adds r0, r1, #0
_08026C1A:
	adds r1, r5, #0
	bl sub_08026C30
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08026B70
