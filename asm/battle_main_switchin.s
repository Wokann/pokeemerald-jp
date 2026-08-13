.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start SwitchInClearSetData
SwitchInClearSetData: @ 0x08039EC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r4, _0803A02C
	ldr r5, _0803A030
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	mov r1, sp
	adds r0, r0, r4
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, _0803A034
	ldr r3, _0803A038
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	mov ip, r4
	mov sb, r5
	ldr r6, _0803A03C
	mov sl, r6
	cmp r0, #0x7f
	beq _08039FA0
	movs r5, #0
	mov r6, sb
	movs r4, #0x58
	ldr r2, _0803A040
	adds r2, #0x18
	movs r1, #6
_08039F18:
	ldrb r0, [r6]
	muls r0, r4, r0
	adds r0, r5, r0
	adds r0, r0, r2
	strb r1, [r0]
	adds r5, #1
	cmp r5, #7
	ble _08039F18
	movs r5, #0
	ldr r7, _0803A044
	ldrb r7, [r7]
	cmp r5, r7
	bge _08039F8C
	ldr r0, _0803A048
	mov r8, r0
	ldr r4, _0803A02C
	ldr r3, _0803A03C
_08039F3A:
	movs r0, #0x58
	muls r0, r5, r0
	mov r1, r8
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	beq _08039F5E
	ldrb r0, [r4, #0x14]
	ldr r6, _0803A030
	ldrb r6, [r6]
	cmp r0, r6
	bne _08039F5E
	ldr r0, _0803A04C
	ands r1, r0
	str r1, [r2]
_08039F5E:
	ldr r1, [r3]
	movs r0, #0x18
	ands r0, r1
	cmp r0, #0
	beq _08039F7E
	ldrb r0, [r4, #0x15]
	ldr r7, _0803A030
	ldrb r7, [r7]
	cmp r0, r7
	bne _08039F7E
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r3]
	movs r0, #0
	strb r0, [r4, #0x15]
_08039F7E:
	adds r4, #0x1c
	adds r3, #4
	adds r5, #1
	ldr r0, _0803A044
	ldrb r0, [r0]
	cmp r5, r0
	blt _08039F3A
_08039F8C:
	ldr r1, _0803A038
	ldrh r0, [r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _0803A034
	adds r1, r1, r2
	ldrb r0, [r1]
	cmp r0, #0x7f
	bne _0803A058
_08039FA0:
	mov r3, sb
	ldrb r1, [r3]
	movs r0, #0x58
	adds r2, r1, #0
	muls r2, r0, r2
	ldr r0, _0803A040
	adds r0, #0x50
	adds r2, r2, r0
	ldr r0, [r2]
	ldr r1, _0803A050
	ands r0, r1
	str r0, [r2]
	ldrb r1, [r3]
	lsls r1, r1, #2
	add r1, sl
	ldr r0, [r1]
	ldr r2, _0803A054
	ands r0, r2
	str r0, [r1]
	movs r5, #0
	ldr r6, _0803A044
	ldrb r6, [r6]
	cmp r5, r6
	bge _0803A074
	mov r7, sb
	movs r6, #0
_08039FD4:
	ldrb r0, [r7]
	bl GetBattlerSide
	adds r4, r0, #0
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803A014
	ldr r1, _0803A03C
	lsls r0, r5, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #0x18
	ands r0, r1
	cmp r0, #0
	beq _0803A014
	ldr r0, _0803A02C
	adds r0, r6, r0
	ldrb r0, [r0, #0x15]
	ldrb r3, [r7]
	cmp r0, r3
	bne _0803A014
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r1, r0
	movs r0, #0x10
	orrs r1, r0
	str r1, [r2]
_0803A014:
	adds r6, #0x1c
	adds r5, #1
	ldr r0, _0803A044
	ldrb r0, [r0]
	cmp r5, r0
	blt _08039FD4
	ldr r6, _0803A02C
	mov ip, r6
	ldr r7, _0803A030
	mov sb, r7
	b _0803A074
	.align 2, 0
_0803A02C: .4byte 0x02023F60
_0803A030: .4byte 0x02023D08
_0803A034: .4byte 0x082ED220
_0803A038: .4byte 0x02023E8E
_0803A03C: .4byte 0x02023F50
_0803A040: .4byte 0x02023D28
_0803A044: .4byte 0x02023D10
_0803A048: .4byte 0x02023D78
_0803A04C: .4byte 0xFBFFFFFF
_0803A050: .4byte 0x15100007
_0803A054: .4byte 0x0003043F
_0803A058:
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	ldr r1, _0803A354
	adds r1, #0x50
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	mov r2, sb
	ldrb r0, [r2]
	lsls r0, r0, #2
	add r0, sl
	str r1, [r0]
_0803A074:
	movs r5, #0
	ldr r3, _0803A358
	mov r8, r3
	ldr r6, _0803A35C
	mov sl, r6
	ldr r7, _0803A360
	ldrb r7, [r7]
	cmp r5, r7
	bge _0803A0D4
	ldr r3, _0803A364
	ldr r7, _0803A368
	ldr r6, _0803A36C
_0803A08C:
	movs r0, #0x58
	muls r0, r5, r0
	adds r4, r0, r3
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	lsls r2, r0, #0x10
	ldr r1, [r4]
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0803A0AA
	bics r1, r2
	str r1, [r4]
_0803A0AA:
	ldr r1, [r4]
	movs r0, #0xe0
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0803A0CA
	mov r2, r8
	ldr r0, [r2]
	adds r0, r5, r0
	ldrb r0, [r0, #0x14]
	ldrb r2, [r6]
	cmp r0, r2
	bne _0803A0CA
	ldr r0, _0803A370
	ands r1, r0
	str r1, [r4]
_0803A0CA:
	adds r5, #1
	ldr r0, _0803A360
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A08C
_0803A0D4:
	mov r1, sb
	ldrb r0, [r1]
	add r0, sl
	movs r1, #0
	strb r1, [r0]
	mov r2, sb
	ldrb r0, [r2]
	ldr r3, _0803A374
	adds r0, r0, r3
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	mov r6, ip
	adds r1, r0, r6
	movs r5, #0
	movs r2, #0
_0803A0F8:
	adds r0, r1, r5
	strb r2, [r0]
	adds r5, #1
	cmp r5, #0x1b
	bls _0803A0F8
	ldr r7, _0803A378
	ldrh r0, [r7]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0803A37C
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x7f
	bne _0803A184
	mov r2, sb
	ldrb r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	mov r1, sp
	ldrb r1, [r1, #0xa]
	strb r1, [r0, #0xa]
	ldrb r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	mov r1, sp
	ldrb r1, [r1, #0x15]
	strb r1, [r0, #0x15]
	ldrb r0, [r2]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, ip
	mov r0, sp
	ldrb r2, [r0, #0xf]
	lsls r2, r2, #0x1c
	movs r4, #0xf
	lsrs r2, r2, #0x1c
	ldrb r3, [r1, #0xf]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #0xf]
	mov r3, sb
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	mov r1, sp
	ldrb r1, [r1, #0xf]
	lsrs r1, r1, #4
	lsls r1, r1, #4
	ldrb r2, [r0, #0xf]
	ands r4, r2
	orrs r4, r1
	strb r4, [r0, #0xf]
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	mov r1, sp
	ldrb r1, [r1, #0x14]
	strb r1, [r0, #0x14]
_0803A184:
	movs r0, #0
	ldr r6, _0803A380
	strb r0, [r6]
	mov r7, sb
	ldrb r1, [r7]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	movs r4, #0
	movs r1, #2
	strb r1, [r0, #0x16]
	ldrb r0, [r7]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, ip
	mov r0, sp
	ldrb r0, [r0, #0x18]
	movs r2, #2
	ands r2, r0
	ldrb r3, [r1, #0x18]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #0x18]
	ldrb r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0803A384
	adds r0, r0, r1
	movs r2, #0
	strh r4, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #1
	ldr r3, _0803A388
	adds r0, r0, r3
	strh r4, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #1
	ldr r6, _0803A38C
	adds r0, r0, r6
	strh r4, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #1
	ldr r7, _0803A390
	adds r0, r0, r7
	strh r4, [r0]
	mov r1, sb
	ldrb r0, [r1]
	lsls r0, r0, #1
	ldr r3, _0803A394
	adds r0, r0, r3
	strh r4, [r0]
	ldrb r0, [r1]
	ldr r6, _0803A398
	adds r0, r0, r6
	movs r1, #0xff
	strb r1, [r0]
	mov r7, sb
	ldrb r0, [r7]
	mov r3, r8
	ldr r1, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x98
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x99
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe0
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe1
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe2
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe3
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe4
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe5
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe6
	strb r2, [r0]
	ldrb r0, [r7]
	ldr r1, [r3]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe7
	strb r2, [r0]
	ldr r1, [r3]
	adds r1, #0x92
	ldrb r0, [r7]
	lsls r0, r0, #2
	ldr r6, _0803A368
	adds r0, r0, r6
	ldr r2, [r0]
	ldrb r0, [r1]
	bics r0, r2
	strb r0, [r1]
	movs r5, #0
	ldr r7, _0803A360
	ldrb r7, [r7]
	cmp r5, r7
	bge _0803A2F8
	mov r3, sb
	mov r7, r8
	movs r6, #0
_0803A29A:
	ldrb r0, [r3]
	cmp r5, r0
	beq _0803A2D0
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	str r3, [sp, #0x1c]
	bl GetBattlerSide
	adds r4, r0, #0
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	ldr r3, [sp, #0x1c]
	cmp r4, r0
	beq _0803A2D0
	ldr r0, [r7]
	lsls r1, r5, #1
	adds r0, r1, r0
	adds r0, #0x98
	strb r6, [r0]
	ldr r0, [r7]
	adds r1, r1, r0
	adds r1, #0x99
	strb r6, [r1]
_0803A2D0:
	ldrb r0, [r3]
	ldr r1, [r7]
	lsls r0, r0, #1
	lsls r2, r5, #3
	adds r0, r0, r2
	adds r0, r0, r1
	adds r0, #0xe0
	strb r6, [r0]
	ldrb r0, [r3]
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r2
	adds r0, r0, r1
	adds r0, #0xe1
	strb r6, [r0]
	adds r5, #1
	ldr r0, _0803A360
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A29A
_0803A2F8:
	mov r1, sb
	ldrb r0, [r1]
	mov r2, r8
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc8
	movs r2, #0
	strb r2, [r0]
	mov r3, sb
	ldrb r0, [r3]
	mov r6, r8
	ldr r1, [r6]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc9
	strb r2, [r0]
	ldr r0, _0803A39C
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0
	str r2, [r1]
	ldr r0, _0803A378
	strh r2, [r0]
	ldr r0, [r6]
	adds r0, #0xda
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r3]
	bl ClearBattlerMoveHistory
	mov r7, sb
	ldrb r0, [r7]
	bl ClearBattlerAbilityHistory
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A354: .4byte 0x02023D28
_0803A358: .4byte 0x02024140
_0803A35C: .4byte 0x02024150
_0803A360: .4byte 0x02023D10
_0803A364: .4byte 0x02023D78
_0803A368: .4byte 0x082FACB4
_0803A36C: .4byte 0x02023D08
_0803A370: .4byte 0xFFFF1FFF
_0803A374: .4byte 0x02024154
_0803A378: .4byte 0x02023E8E
_0803A37C: .4byte 0x082ED220
_0803A380: .4byte 0x02023F20
_0803A384: .4byte 0x02023EEC
_0803A388: .4byte 0x02023EF4
_0803A38C: .4byte 0x02023EFC
_0803A390: .4byte 0x02023F04
_0803A394: .4byte 0x02023EE4
_0803A398: .4byte 0x02023F14
_0803A39C: .4byte 0x0202414C
	thumb_func_end SwitchInClearSetData
