.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified








































	thumb_func_start sub_080175F0
sub_080175F0: @ 0x080175F0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	ldr r4, [sp, #0x28]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r4, r4, #0x18
	lsrs r7, r4, #0x18
	ldrh r0, [r2, #8]
	lsls r0, r0, #0x16
	lsrs r4, r0, #0x16
	ldrb r0, [r2, #9]
	lsrs r0, r0, #2
	mov r8, r0
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #1
	mov sb, r0
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #1
	adds r2, r3, #0
	movs r3, #0xa
	bl PrintUnionRoomText
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r4, r0
	bne _08017648
	ldr r2, _08017644
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #1
	movs r3, #0x46
	bl PrintUnionRoomText
	b _0801769E
	.align 2, 0
_08017644: .4byte 0x082C19AC
_08017648:
	mov r1, r8
	adds r1, #1
	adds r0, r6, #0
	movs r2, #0x46
	adds r3, r5, #0
	bl blit_move_info_icon
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #1
	ldr r0, _080176AC
	adds r2, r2, r0
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #1
	movs r3, #0x78
	bl PrintUnionRoomText
	add r0, sp, #8
	mov r1, sb
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	movs r0, #1
	add r1, sp, #8
	movs r2, #0
	bl GetStringWidth
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r3, #0xdc
	subs r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r1, #1
	add r2, sp, #8
	bl PrintUnionRoomText
_0801769E:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080176AC: .4byte 0x082EA31C
	thumb_func_end sub_080175F0

	thumb_func_start sub_080176B0
sub_080176B0: @ 0x080176B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sb, r2
	ldr r0, _08017700
	ldr r0, [r0]
	mov r8, r0
	movs r0, #3
	rsbs r0, r0, #0
	cmp r4, r0
	bne _0801772C
	cmp r2, #1
	bne _0801772C
	bl GetHostRfuGameData
	adds r2, r0, #0
	ldrh r1, [r2, #8]
	ldr r0, _08017704
	ands r0, r1
	cmp r0, #0
	beq _08017760
	ldr r0, _08017708
	ldr r3, [r0]
	movs r0, #5
	str r0, [sp]
	mov r0, sl
	movs r1, #1
	bl sub_080175F0
	b _08017760
	.align 2, 0
_08017700: .4byte 0x020228E4
_08017704: .4byte 0x000003FF
_08017708: .4byte 0x03005AF0
_0801770C:
	adds r1, r7, r4
	adds r1, #0x10
	add r0, sp, #4
	bl StringCopy
	mov r0, r8
	ldr r2, [r0]
	adds r2, r2, r4
	movs r0, #6
	str r0, [sp]
	mov r0, sl
	mov r1, sb
	add r3, sp, #4
	bl sub_080175F0
	b _08017760
_0801772C:
	movs r5, #0
	movs r1, #0
	mov r0, r8
	ldr r7, [r0]
	adds r2, r7, #0
	adds r2, #8
	movs r3, #0
	adds r6, r4, #1
_0801773C:
	ldrb r0, [r2, #0x12]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1e
	adds r4, r3, #0
	cmp r0, #1
	bne _08017752
	ldrh r0, [r2]
	lsls r0, r0, #0x16
	cmp r0, #0
	beq _08017752
	adds r5, #1
_08017752:
	cmp r5, r6
	beq _0801770C
	adds r2, #0x20
	adds r3, #0x20
	adds r1, #1
	cmp r1, #7
	ble _0801773C
_08017760:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_080176B0

	thumb_func_start sub_08017770
sub_08017770: @ 0x08017770
	push {r4, r5, r6, r7, lr}
	movs r4, #0
	movs r3, #0
	movs r7, #3
	ldr r6, _080177A0
	adds r2, r0, #0
	adds r2, #8
	adds r5, r1, #1
_08017780:
	ldrb r1, [r2, #0x12]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #1
	bne _08017796
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08017796
	adds r4, #1
_08017796:
	cmp r4, r5
	bne _080177A4
	adds r0, r3, #0
	b _080177B0
	.align 2, 0
_080177A0: .4byte 0x000003FF
_080177A4:
	adds r2, #0x20
	adds r3, #1
	cmp r3, #7
	ble _08017780
	movs r0, #1
	rsbs r0, r0, #0
_080177B0:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08017770

