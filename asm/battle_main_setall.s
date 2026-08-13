.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start SetAllPlayersBerryData
SetAllPlayersBerryData: @ 0x08036A5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08036B14
	ldr r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08036A74
	b _08036BA0
_08036A74:
	bl IsEnigmaBerryValid
	cmp r0, #1
	bne _08036B30
	movs r5, #0
	ldr r3, _08036B18
	ldr r0, _08036B1C
	mov r8, r0
	adds r6, r3, #0
	mov r4, r8
	ldr r2, _08036B20
	adds r7, r3, #0
	adds r7, #0x38
_08036A8E:
	adds r1, r5, r6
	ldr r0, [r4]
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r5, r7
	ldr r0, [r4]
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r5, #1
	cmp r5, #5
	ble _08036A8E
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x38
	adds r0, r5, r0
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0]
	movs r5, #0
	adds r7, r3, #0
	adds r7, #8
	ldr r4, _08036B1C
	ldr r2, _08036B24
	adds r6, r3, #0
	adds r6, #0x40
_08036ACC:
	adds r1, r5, r7
	ldr r0, [r4]
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r5, r6
	ldr r0, [r4]
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r5, #1
	cmp r5, #0x11
	ble _08036ACC
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08036B28
	adds r0, r0, r2
	ldrb r1, [r0]
	strb r1, [r3, #7]
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x3f
	strb r0, [r1]
	mov r4, r8
	ldr r0, [r4]
	ldr r1, _08036B2C
	adds r0, r0, r1
	ldrb r1, [r0]
	strb r1, [r3, #0x1a]
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x52
	strb r1, [r0]
	b _08036CF4
	.align 2, 0
_08036B14: .4byte 0x02022C90
_08036B18: .4byte 0x020240A8
_08036B1C: .4byte 0x03005AEC
_08036B20: .4byte 0x000031F8
_08036B24: .4byte 0x00003214
_08036B28: .4byte 0x00003226
_08036B2C: .4byte 0x00003227
_08036B30:
	movs r0, #0xaf
	bl ItemIdToBerryType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBerryInfo
	adds r6, r0, #0
	movs r5, #0
	ldr r4, _08036B9C
	adds r7, r4, #0
	adds r7, #0x38
	adds r3, r4, #0
_08036B4A:
	adds r1, r5, r4
	adds r2, r6, r5
	ldrb r0, [r2]
	strb r0, [r1]
	adds r1, r5, r7
	ldrb r0, [r2]
	strb r0, [r1]
	adds r5, #1
	cmp r5, #5
	ble _08036B4A
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x38
	adds r0, r5, r0
	movs r1, #1
	rsbs r1, r1, #0
	strb r1, [r0]
	movs r5, #0
	adds r4, r3, #0
	adds r4, #8
	movs r1, #0
	adds r2, r3, #0
	adds r2, #0x40
_08036B7C:
	adds r0, r5, r4
	strb r1, [r0]
	adds r0, r5, r2
	strb r1, [r0]
	adds r5, #1
	cmp r5, #0x11
	ble _08036B7C
	movs r1, #0
	strb r1, [r3, #7]
	adds r0, r3, #0
	adds r0, #0x3f
	strb r1, [r0]
	strb r1, [r3, #0x1a]
	adds r0, #0x13
	strb r1, [r0]
	b _08036CF4
	.align 2, 0
_08036B9C: .4byte 0x020240A8
_08036BA0:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08036C44
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	movs r2, #4
	mov r8, r2
	cmp r1, #0
	beq _08036BBA
	movs r4, #2
	mov r8, r4
_08036BBA:
	movs r5, #0
	cmp r5, r8
	blt _08036BC2
	b _08036CF4
_08036BC2:
	ldr r0, _08036C38
	mov ip, r0
	ldr r3, _08036C3C
	adds r6, r3, #0
	movs r1, #8
	adds r1, r1, r6
	mov sb, r1
_08036BD0:
	lsls r1, r5, #8
	ldr r0, _08036C40
	adds r7, r1, r0
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	add r0, ip
	ldrb r3, [r0, #0x18]
	movs r4, #0
	adds r5, #1
	mov sl, r5
	lsls r1, r3, #3
	subs r0, r1, r3
	adds r5, r1, #0
	lsls r0, r0, #2
	adds r1, r0, r6
_08036BF0:
	adds r0, r7, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, #1
	adds r4, #1
	cmp r4, #5
	ble _08036BF0
	subs r0, r5, r3
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r1, r1, r6
	movs r2, #0xff
	strb r2, [r1]
	movs r4, #0
	mov r2, sb
	adds r1, r0, r2
	adds r2, r7, #0
	adds r2, #8
_08036C14:
	adds r0, r2, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, #1
	adds r4, #1
	cmp r4, #0x11
	ble _08036C14
	subs r0, r5, r3
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r1, [r7, #7]
	strb r1, [r0, #7]
	ldrb r1, [r7, #0x1a]
	strb r1, [r0, #0x1a]
	mov r5, sl
	cmp r5, r8
	blt _08036BD0
	b _08036CF4
	.align 2, 0
_08036C38: .4byte 0x020226A0
_08036C3C: .4byte 0x020240A8
_08036C40: .4byte 0x02022080
_08036C44:
	movs r5, #0
	ldr r4, _08036D04
	mov sb, r4
_08036C4A:
	lsls r0, r5, #8
	ldr r1, _08036D08
	adds r7, r0, r1
	movs r4, #0
	adds r2, r5, #1
	mov sl, r2
	lsls r0, r5, #3
	mov r8, r0
	adds r1, r5, #2
	mov ip, r1
	subs r1, r0, r5
	mov r2, ip
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	mov r2, sb
	adds r3, r0, r2
	lsls r1, r1, #2
	adds r2, r1, r2
_08036C70:
	adds r0, r7, r4
	ldrb r1, [r0]
	strb r1, [r2]
	ldrb r0, [r0]
	strb r0, [r3]
	adds r3, #1
	adds r2, #1
	adds r4, #1
	cmp r4, #5
	ble _08036C70
	mov r0, r8
	subs r3, r0, r5
	lsls r3, r3, #2
	adds r1, r4, r3
	add r1, sb
	ldrb r0, [r1]
	movs r2, #0xff
	orrs r0, r2
	strb r0, [r1]
	mov r0, ip
	lsls r2, r0, #3
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r1, r4, r2
	add r1, sb
	ldrb r0, [r1]
	movs r4, #0xff
	orrs r0, r4
	strb r0, [r1]
	movs r4, #0
	ldr r0, _08036D04
	adds r0, #8
	adds r2, r2, r0
	adds r3, r3, r0
	adds r6, r7, #0
	adds r6, #8
_08036CB8:
	adds r0, r6, r4
	ldrb r1, [r0]
	strb r1, [r3]
	ldrb r0, [r0]
	strb r0, [r2]
	adds r2, #1
	adds r3, #1
	adds r4, #1
	cmp r4, #0x11
	ble _08036CB8
	mov r0, r8
	subs r2, r0, r5
	lsls r2, r2, #2
	add r2, sb
	ldrb r0, [r7, #7]
	strb r0, [r2, #7]
	mov r1, ip
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, sb
	ldrb r1, [r7, #7]
	strb r1, [r0, #7]
	ldrb r1, [r7, #0x1a]
	strb r1, [r2, #0x1a]
	ldrb r1, [r7, #0x1a]
	strb r1, [r0, #0x1a]
	mov r5, sl
	cmp r5, #1
	ble _08036C4A
_08036CF4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036D04: .4byte 0x020240A8
_08036D08: .4byte 0x02022080
	thumb_func_end SetAllPlayersBerryData

