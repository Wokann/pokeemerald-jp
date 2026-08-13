.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleStartClearSetData
BattleStartClearSetData: @ 0x08039B84
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	bl TurnValuesCleanUp
	bl SpecialStatusesClear
	movs r2, #0
	movs r3, #0
	ldr r0, _08039C80
	mov sl, r0
	ldr r1, _08039C84
	mov sb, r1
	ldr r0, _08039C88
	mov r8, r0
	ldr r1, _08039C8C
	mov ip, r1
	ldr r5, _08039C90
	movs r4, #0
	ldr r7, _08039C94
	ldr r6, _08039C98
_08039BB4:
	ldr r0, _08039C9C
	adds r0, r4, r0
	str r3, [r0]
	movs r1, #0
_08039BBC:
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #1
	cmp r1, #0x1b
	bls _08039BBC
	movs r0, #2
	strb r0, [r5, #0x16]
	ldr r1, _08039CA0
	adds r0, r2, r1
	strb r3, [r0]
	mov r0, ip
	strh r3, [r0]
	mov r1, r8
	strh r3, [r1]
	mov r0, sb
	strh r3, [r0]
	mov r1, sl
	strh r3, [r1]
	ldr r0, _08039CA4
	adds r1, r2, r0
	movs r0, #0xff
	strb r0, [r1]
	strh r3, [r6]
	strh r3, [r7]
	ldr r1, _08039CA8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r4
	str r3, [r0]
	ldr r1, _08039CAC
	adds r0, r4, r1
	str r3, [r0]
	movs r0, #2
	add sl, r0
	add sb, r0
	add r8, r0
	add ip, r0
	adds r5, #0x1c
	adds r4, #4
	adds r7, #2
	adds r6, #2
	adds r2, #1
	cmp r2, #3
	ble _08039BB4
	movs r5, #0
	ldr r3, _08039CB0
	ldr r4, _08039CB4
	movs r2, #1
_08039C1C:
	strh r5, [r4]
	movs r1, #0
_08039C20:
	adds r0, r3, r1
	strb r5, [r0]
	adds r1, #1
	cmp r1, #0xb
	bls _08039C20
	adds r3, #0xc
	adds r4, #2
	subs r2, #1
	cmp r2, #0
	bge _08039C1C
	movs r1, #0
	ldr r2, _08039CB8
	strb r1, [r2]
	ldr r0, _08039CBC
	strb r1, [r0]
	ldr r2, _08039CC0
	strh r1, [r2]
	ldr r1, _08039CC4
	movs r2, #0
	movs r3, #0
_08039C48:
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	cmp r2, #0x2b
	bls _08039C48
	ldr r2, _08039CC8
	movs r0, #0
	str r0, [r2]
	ldr r0, _08039CCC
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r1
	cmp r0, #0
	bne _08039CD4
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	bne _08039CF2
	ldr r0, _08039CD0
	ldr r0, [r0]
	ldrb r1, [r0, #0x15]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08039CF2
	movs r0, #0x80
	b _08039CF0
	.align 2, 0
_08039C80: .4byte 0x02023F04
_08039C84: .4byte 0x02023EFC
_08039C88: .4byte 0x02023EF4
_08039C8C: .4byte 0x02023EEC
_08039C90: .4byte 0x02023F60
_08039C94: .4byte 0x02023EE4
_08039C98: .4byte 0x02023F0C
_08039C9C: .4byte 0x02023F50
_08039CA0: .4byte 0x02023F28
_08039CA4: .4byte 0x02023F14
_08039CA8: .4byte 0x0202414C
_08039CAC: .4byte 0x02023ED4
_08039CB0: .4byte 0x02023F38
_08039CB4: .4byte 0x02023F32
_08039CB8: .4byte 0x02023EAF
_08039CBC: .4byte 0x02023EB0
_08039CC0: .4byte 0x02024070
_08039CC4: .4byte 0x02024074
_08039CC8: .4byte 0x02023F24
_08039CCC: .4byte 0x02022C90
_08039CD0: .4byte 0x03005AF0
_08039CD4:
	ldr r0, _08039E70
	ands r1, r0
	cmp r1, #0
	bne _08039CF2
	bl GetRecordedBattleRecordMixFriendClass
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08039CF2
	ldr r1, _08039E74
	ldr r0, [r1]
	movs r1, #0x80
	orrs r0, r1
	ldr r2, _08039E74
_08039CF0:
	str r0, [r2]
_08039CF2:
	ldr r3, _08039E78
	ldr r0, _08039E7C
	ldr r0, [r0]
	ldrb r0, [r0, #0x15]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	movs r1, #0
	strb r0, [r3, #0x1d]
	ldr r0, _08039E80
	strb r1, [r0]
	ldr r0, _08039E84
	strb r1, [r0]
	ldr r0, _08039E88
	str r1, [r0]
	ldr r0, _08039E8C
	movs r2, #0
	strh r1, [r0]
	ldr r1, _08039E90
	ldr r0, [r1]
	ldr r0, [r0, #8]
	adds r0, #0x20
	strb r2, [r0]
	ldr r0, [r1]
	ldr r0, [r0, #0xc]
	adds r0, #0x20
	strb r2, [r0]
	ldr r5, _08039E94
	ldr r6, _08039E98
	ldr r7, _08039E9C
	ldr r0, _08039EA0
	mov r8, r0
	ldr r1, _08039EA4
	mov sb, r1
	ldr r2, _08039EA8
	mov sl, r2
	ldr r1, _08039EAC
	movs r2, #0
	adds r0, r1, #7
_08039D3E:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08039D3E
	movs r4, #0
	strh r4, [r5]
	movs r0, #0
	str r0, [r6]
	strh r0, [r7]
	strb r4, [r3, #0x18]
	strb r4, [r3, #0x19]
	mov r0, r8
	strb r4, [r0]
	mov r1, sb
	strb r4, [r1]
	ldr r5, _08039EB0
	ldr r0, [r5]
	adds r0, #0x6c
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, #0x79
	strb r4, [r0]
	ldr r0, [r5]
	adds r0, #0x7a
	strb r4, [r0]
	mov r0, sl
	movs r1, #0xb
	bl GetMonData3
	ldr r6, [r5]
	adds r6, #0x7c
	ldr r2, _08039EB4
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #8]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _08039EB8
	bl __divsi3
	strb r0, [r6]
	ldr r0, [r5]
	adds r0, #0x7b
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r5]
	strb r4, [r0, #0x12]
	ldr r0, [r5]
	adds r0, #0x4a
	movs r1, #1
	strb r1, [r0]
	movs r2, #0
	movs r1, #0
	adds r6, r5, #0
_08039DAE:
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, #0x98
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, #0xb8
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, #0xc8
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, #0xd0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, #0xe0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, #0xe8
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, #0xf0
	strb r1, [r0]
	ldr r0, [r5]
	adds r0, r2, r0
	adds r0, #0xf8
	strb r1, [r0]
	adds r2, #1
	cmp r2, #7
	ble _08039DAE
	movs r2, #0
	ldr r4, _08039EB0
	movs r3, #0xa5
	lsls r3, r3, #2
	movs r1, #6
_08039DFE:
	ldr r0, [r4]
	adds r0, r2, r0
	adds r0, r0, r3
	strb r1, [r0]
	adds r2, #1
	cmp r2, #3
	ble _08039DFE
	ldr r0, [r6]
	adds r0, #0xdf
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, #0x92
	strb r1, [r0]
	bl Random
	ldr r1, _08039EBC
	strh r0, [r1]
	ldr r1, _08039EC0
	movs r2, #0
	movs r3, #0
_08039E28:
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	cmp r2, #0x43
	bls _08039E28
	ldr r0, _08039EA8
	bl IsMonShiny
	ldr r3, _08039EC0
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #6
	ldrb r2, [r3, #5]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldr r2, _08039EB0
	ldr r0, [r2]
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r2, _08039EC4
	adds r0, r0, r2
	strb r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039E70: .4byte 0x02000002
_08039E74: .4byte 0x02023F24
_08039E78: .4byte 0x02024118
_08039E7C: .4byte 0x03005AF0
_08039E80: .4byte 0x02023EB6
_08039E84: .4byte 0x02023FDE
_08039E88: .4byte 0x02023D0C
_08039E8C: .4byte 0x02023FD2
_08039E90: .4byte 0x0202414C
_08039E94: .4byte 0x02023FD0
_08039E98: .4byte 0x02023E94
_08039E9C: .4byte 0x020240A0
_08039EA0: .4byte 0x03005AB4
_08039EA4: .4byte 0x02023EB4
_08039EA8: .4byte 0x020243E8
_08039EAC: .4byte 0x02023FD6
_08039EB0: .4byte 0x02024140
_08039EB4: .4byte 0x082F0D54
_08039EB8: .4byte 0x000004FB
_08039EBC: .4byte 0x02023FD4
_08039EC0: .4byte 0x03005A70
_08039EC4: .4byte 0x000002A1
	thumb_func_end BattleStartClearSetData
