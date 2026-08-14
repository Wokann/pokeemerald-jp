.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_081B7D28
sub_081B7D28: @ 0x081B7D28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _081B7D90
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B7D84
	ldr r4, _081B7D94
	ldrh r5, [r4, #0xc]
	movs r0, #9
	ldrsb r0, [r4, r0]
	movs r1, #0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _081B7D98
	adds r0, r0, r6
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl sub_081B1954
	movs r0, #9
	ldrsb r0, [r4, r0]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	adds r1, r5, #0
	bl sub_081B1A88
	adds r0, r5, #0
	bl sub_081B8090
	ldr r1, _081B7D9C
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B7DA0
	str r1, [r0]
_081B7D84:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7D90: .4byte 0x02037C74
_081B7D94: .4byte 0x0203CB94
_081B7D98: .4byte 0x02024190
_081B7D9C: .4byte 0x03005B60
_081B7DA0: .4byte 0x081B7DA5
	thumb_func_end sub_081B7D28

	thumb_func_start sub_081B7DA4
sub_081B7DA4: @ 0x081B7DA4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B7DE0
	ldrb r4, [r0, #9]
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B7DD8
	lsls r2, r4, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x64
	muls r0, r2, r0
	ldr r1, _081B7DE4
	adds r0, r0, r1
	ldr r1, _081B7DE8
	lsls r2, r2, #4
	ldr r1, [r1]
	adds r1, r1, r2
	bl sub_081B5934
	adds r0, r5, #0
	bl sub_081B0F90
_081B7DD8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B7DE0: .4byte 0x0203CB94
_081B7DE4: .4byte 0x02024190
_081B7DE8: .4byte 0x0203CBA8
	thumb_func_end sub_081B7DA4

	thumb_func_start sub_081B7DEC
sub_081B7DEC: @ 0x081B7DEC
	push {r4, r5, r6, lr}
	ldr r4, _081B7E34
	movs r0, #9
	ldrsb r0, [r4, r0]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _081B7E38
	adds r0, r0, r5
	ldrh r1, [r4, #0xc]
	bl sub_081B1A88
	movs r0, #9
	ldrsb r0, [r4, r0]
	muls r0, r6, r0
	adds r0, r0, r5
	movs r1, #0x40
	bl GetMonData3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _081B7E3C
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r0, _081B7E40
	adds r2, r2, r0
	ldr r1, [r1]
	adds r1, r1, r2
	ldr r2, _081B7E44
	movs r0, #4
	movs r3, #3
	bl DoEasyChatScreen
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B7E34: .4byte 0x0203CB94
_081B7E38: .4byte 0x02024190
_081B7E3C: .4byte 0x03005AEC
_081B7E40: .4byte 0x00002BE0
_081B7E44: .4byte 0x081B7E49
	thumb_func_end sub_081B7DEC

	thumb_func_start sub_081B7E48
sub_081B7E48: @ 0x081B7E48
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r6, _081B7E98
	movs r1, #9
	ldrsb r1, [r6, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B7E9C
	adds r5, r1, r0
	adds r0, r5, #0
	movs r1, #0xc
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _081B7EA0
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B7EA8
	adds r0, r5, #0
	bl TakeMailFromMon
	ldr r4, _081B7EA4
	adds r0, r5, #0
	movs r1, #0xc
	adds r2, r4, #0
	bl SetMonData
	ldrh r0, [r4]
	movs r1, #1
	bl RemoveBagItem
	adds r0, r7, #0
	bl sub_081B80BC
	ldr r0, [r6]
	bl SetMainCallback2
	b _081B7EC4
	.align 2, 0
_081B7E98: .4byte 0x0203CB94
_081B7E9C: .4byte 0x02024190
_081B7EA0: .4byte 0x02037290
_081B7EA4: .4byte 0x0203CBC8
_081B7EA8:
	ldrb r0, [r6, #8]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldrb r2, [r6, #0xb]
	movs r1, #0x7f
	str r1, [sp]
	ldr r1, _081B7ECC
	str r1, [sp, #4]
	ldr r1, [r6]
	str r1, [sp, #8]
	movs r1, #0xff
	movs r3, #1
	bl InitPartyMenu
_081B7EC4:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7ECC: .4byte 0x081B7ED1
	thumb_func_end sub_081B7E48

	thumb_func_start sub_081B7ED0
sub_081B7ED0: @ 0x081B7ED0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _081B7EF8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B7F2A
	ldr r1, _081B7EFC
	ldrh r0, [r1]
	cmp r0, #0
	beq _081B7F04
	ldr r0, _081B7F00
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1]
	movs r2, #0
	bl sub_081B1A38
	b _081B7F1C
	.align 2, 0
_081B7EF8: .4byte 0x02037C74
_081B7EFC: .4byte 0x0203CBC8
_081B7F00: .4byte 0x0203CB94
_081B7F04:
	ldr r2, _081B7F30
	movs r1, #9
	ldrsb r1, [r2, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B7F34
	adds r0, r0, r1
	ldrh r1, [r2, #0xc]
	movs r2, #0
	movs r3, #1
	bl sub_081B1954
_081B7F1C:
	ldr r0, _081B7F38
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7F3C
	str r0, [r1]
_081B7F2A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B7F30: .4byte 0x0203CB94
_081B7F34: .4byte 0x02024190
_081B7F38: .4byte 0x03005B60
_081B7F3C: .4byte 0x081B7DA5
	thumb_func_end sub_081B7ED0

	thumb_func_start sub_081B7F40
sub_081B7F40: @ 0x081B7F40
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B7F64
	bl sub_081B2FDC
	ldr r0, _081B7F6C
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7F70
	str r0, [r1]
_081B7F64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B7F6C: .4byte 0x03005B60
_081B7F70: .4byte 0x081B7F75
	thumb_func_end sub_081B7F40

	thumb_func_start sub_081B7F74
sub_081B7F74: @ 0x081B7F74
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	beq _081B7F9A
	cmp r1, #0
	bgt _081B7F94
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081B8034
	b _081B8048
_081B7F94:
	cmp r1, #1
	beq _081B803A
	b _081B8048
_081B7F9A:
	ldr r7, _081B7FCC
	ldrh r4, [r7, #0xc]
	adds r0, r4, #0
	bl sub_081B8090
	ldr r6, _081B7FD0
	ldrh r0, [r6]
	movs r1, #1
	bl AddBagItem
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B7FD8
	adds r0, r4, #0
	bl sub_081B80BC
	ldrh r0, [r6]
	bl pokemon_item_not_removed
	ldr r0, _081B7FD4
	movs r1, #0
	bl DisplayPartyMenuMessage
	b _081B8018
	.align 2, 0
_081B7FCC: .4byte 0x0203CB94
_081B7FD0: .4byte 0x0203CBC8
_081B7FD4: .4byte 0x02021C7C
_081B7FD8:
	adds r0, r4, #0
	bl ItemIsMail
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B7FFC
	ldr r0, _081B7FF4
	ldr r1, [r0]
	ldr r0, _081B7FF8
	str r0, [r1, #4]
	adds r0, r5, #0
	bl sub_081B0F90
	b _081B8048
	.align 2, 0
_081B7FF4: .4byte 0x0203CB90
_081B7FF8: .4byte 0x081B7DED
_081B7FFC:
	movs r1, #9
	ldrsb r1, [r7, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B8028
	adds r0, r0, r1
	adds r1, r4, #0
	bl sub_081B1A88
	ldrh r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl sub_081B1A38
_081B8018:
	ldr r1, _081B802C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B8030
	str r1, [r0]
	b _081B8048
	.align 2, 0
_081B8028: .4byte 0x02024190
_081B802C: .4byte 0x03005B60
_081B8030: .4byte 0x081B7DA5
_081B8034:
	movs r0, #5
	bl PlaySE
_081B803A:
	ldr r0, _081B8050
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B8054
	str r0, [r1]
_081B8048:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8050: .4byte 0x03005B60
_081B8054: .4byte 0x081B7DA5
	thumb_func_end sub_081B7F74

	thumb_func_start sub_081B8058
sub_081B8058: @ 0x081B8058
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _081B8084
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B8088
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B808C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8084: .4byte 0x085C9C5C
_081B8088: .4byte 0x03005B60
_081B808C: .4byte 0x081B7DA5
	thumb_func_end sub_081B8058

	thumb_func_start sub_081B8090
sub_081B8090: @ 0x081B8090
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _081B80AC
	ldrb r0, [r0, #0xb]
	cmp r0, #6
	bne _081B80B0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl RemovePCItem
	b _081B80B8
	.align 2, 0
_081B80AC: .4byte 0x0203CB94
_081B80B0:
	adds r0, r1, #0
	movs r1, #1
	bl RemoveBagItem
_081B80B8:
	pop {r0}
	bx r0
	thumb_func_end sub_081B8090

	thumb_func_start sub_081B80BC
sub_081B80BC: @ 0x081B80BC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _081B80D4
	ldrb r0, [r0, #0xb]
	cmp r0, #5
	beq _081B80D8
	adds r0, r1, #0
	movs r1, #1
	bl AddPCItem
	b _081B80E0
	.align 2, 0
_081B80D4: .4byte 0x0203CB94
_081B80D8:
	adds r0, r1, #0
	movs r1, #1
	bl AddBagItem
_081B80E0:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	thumb_func_end sub_081B80BC

	thumb_func_start sub_081B80E8
sub_081B80E8: @ 0x081B80E8
	push {lr}
	sub sp, #0xc
	movs r0, #6
	str r0, [sp]
	ldr r0, _081B810C
	str r0, [sp, #4]
	ldr r0, _081B8110
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B810C: .4byte 0x081B1041
_081B8110: .4byte 0x0816B969
	thumb_func_end sub_081B80E8

	thumb_func_start sub_081B8114
sub_081B8114: @ 0x081B8114
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _081B8160
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B8164
	adds r5, r1, r0
	ldr r1, _081B8168
	movs r0, #0
	strb r0, [r1]
	ldr r2, _081B816C
	ldr r0, _081B8170
	ldrh r1, [r0]
	adds r1, #6
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _081B8174
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	adds r0, r5, #0
	movs r1, #0xc
	bl GetMonData3
	cmp r0, #0
	beq _081B817C
	ldr r0, _081B8178
	movs r1, #1
	bl DisplayPartyMenuMessage
	b _081B8192
	.align 2, 0
_081B8160: .4byte 0x0203CB94
_081B8164: .4byte 0x02024190
_081B8168: .4byte 0x0203CBB4
_081B816C: .4byte 0x03005AEC
_081B8170: .4byte 0x0203B984
_081B8174: .4byte 0x00002BE0
_081B8178: .4byte 0x085C9D0C
_081B817C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl GiveMailToMon
	adds r0, r4, #0
	bl ClearMail
	ldr r0, _081B81AC
	movs r1, #1
	bl DisplayPartyMenuMessage
_081B8192:
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r0, _081B81B0
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B81B4
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B81AC: .4byte 0x085C9D32
_081B81B0: .4byte 0x03005B60
_081B81B4: .4byte 0x081B7DA5
	thumb_func_end sub_081B8114

	thumb_func_start InitChooseHalfPartyForBattle
InitChooseHalfPartyForBattle: @ 0x081B81B8
	push {lr}
	sub sp, #0xc
	bl sub_081B81F8
	movs r0, #0
	str r0, [sp]
	ldr r0, _081B81E8
	str r0, [sp, #4]
	ldr r0, _081B81EC
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	movs r0, #4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	ldr r1, _081B81F0
	ldr r0, _081B81F4
	str r0, [r1, #4]
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B81E8: .4byte 0x081B1041
_081B81EC: .4byte 0x03002360
_081B81F0: .4byte 0x0203CB94
_081B81F4: .4byte 0x081B843D
	thumb_func_end InitChooseHalfPartyForBattle

	thumb_func_start sub_081B81F8
sub_081B81F8: @ 0x081B81F8
	push {lr}
	ldr r0, _081B8208
	movs r1, #0
	movs r2, #4
	bl memset
	pop {r0}
	bx r0
	.align 2, 0
_081B8208: .4byte 0x0203CBC4
	thumb_func_end sub_081B81F8

	thumb_func_start sub_081B820C
sub_081B820C: @ 0x081B820C
	push {r4, lr}
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _081B8228
	adds r0, r0, r1
	bl GetBattleEntryEligibility
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B822C
	movs r0, #2
	b _081B8244
	.align 2, 0
_081B8228: .4byte 0x02024190
_081B822C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_081B8410
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B8242
	movs r0, #0
	b _081B8244
_081B8242:
	movs r0, #1
_081B8244:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081B820C

	thumb_func_start GetBattleEntryEligibility
GetBattleEntryEligibility: @ 0x081B824C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	bne _081B82A8
	adds r0, r5, #0
	movs r1, #0x38
	bl GetMonData3
	adds r4, r0, #0
	bl sub_081B8528
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bhi _081B82A8
	ldr r0, _081B82AC
	ldr r0, [r0]
	ldrh r1, [r0, #4]
	ldr r0, _081B82B0
	cmp r1, r0
	bne _081B828A
	adds r0, r5, #0
	movs r1, #0xc
	bl GetMonData3
	cmp r0, #0
	bne _081B82A8
_081B828A:
	ldr r0, _081B82B4
	bl VarGet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	beq _081B82EA
	cmp r0, #9
	bne _081B82B8
	adds r0, r5, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	bne _081B82EA
_081B82A8:
	movs r0, #0
	b _081B82EC
	.align 2, 0
_081B82AC: .4byte 0x03005AEC
_081B82B0: .4byte 0x0000191A
_081B82B4: .4byte 0x000040CF
_081B82B8:
	adds r0, r5, #0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r3, _081B82F4
	lsls r1, r6, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	ldr r2, _081B82F8
	cmp r0, r2
	beq _081B82EA
_081B82D2:
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r4
	beq _081B82A8
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r6, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _081B82D2
_081B82EA:
	movs r0, #1
_081B82EC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081B82F4: .4byte 0x085DD48E
_081B82F8: .4byte 0x0000FFFF
	thumb_func_end GetBattleEntryEligibility

	thumb_func_start sub_081B82FC
sub_081B82FC: @ 0x081B82FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl sub_081B84FC
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, r2, #0
	ldr r3, _081B8324
	adds r0, r2, r3
	subs r0, #1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B833C
	cmp r2, #1
	bne _081B8328
	movs r0, #0xe
	b _081B83F8
	.align 2, 0
_081B8324: .4byte 0x0203CBC4
_081B8328:
	ldr r0, _081B8338
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	movs r0, #0x11
	b _081B83F8
	.align 2, 0
_081B8338: .4byte 0x02021C40
_081B833C:
	ldr r0, _081B8354
	bl VarGet
	lsls r0, r0, #0x18
	movs r1, #0xf8
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _081B8360
	b _081B83F6
	.align 2, 0
_081B8354: .4byte 0x000040CF
_081B8358:
	movs r0, #0x12
	b _081B83F8
_081B835C:
	movs r0, #0x13
	b _081B83F8
_081B8360:
	bl sub_081B84D0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r5, #0
	b _081B83F0
_081B836E:
	ldr r3, _081B8408
	adds r4, r3, r5
	ldrb r0, [r4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r0, #0x64
	ldr r3, _081B840C
	adds r0, r3, r0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldrb r0, [r4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r0, #0x64
	ldr r3, _081B840C
	adds r0, r3, r0
	movs r1, #0xc
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r1, r5, #1
	lsls r0, r1, #0x18
	lsrs r4, r0, #0x18
	mov sb, r1
	cmp r4, r8
	bhs _081B83E8
	movs r7, #0x64
_081B83AE:
	ldr r0, _081B8408
	adds r5, r0, r4
	ldrb r0, [r5]
	muls r0, r7, r0
	subs r0, #0x64
	ldr r1, _081B840C
	adds r0, r1, r0
	movs r1, #0xb
	bl GetMonData3
	cmp sl, r0
	beq _081B8358
	cmp r6, #0
	beq _081B83DE
	ldrb r0, [r5]
	muls r0, r7, r0
	subs r0, #0x64
	ldr r3, _081B840C
	adds r0, r3, r0
	movs r1, #0xc
	bl GetMonData3
	cmp r6, r0
	beq _081B835C
_081B83DE:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r8
	blo _081B83AE
_081B83E8:
	mov r1, sb
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	mov r0, r8
_081B83F0:
	subs r0, #1
	cmp r5, r0
	blt _081B836E
_081B83F6:
	movs r0, #0xff
_081B83F8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B8408: .4byte 0x0203CBC4
_081B840C: .4byte 0x02024190
	thumb_func_end sub_081B82FC

	thumb_func_start sub_081B8410
sub_081B8410: @ 0x081B8410
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #0
	ldr r3, _081B8428
_081B841A:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081B842C
	movs r0, #1
	b _081B8438
	.align 2, 0
_081B8428: .4byte 0x0203CBC4
_081B842C:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _081B841A
	movs r0, #0
_081B8438:
	pop {r1}
	bx r1
	thumb_func_end sub_081B8410

	thumb_func_start sub_081B843C
sub_081B843C: @ 0x081B843C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl sub_081B82FC
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xff
	beq _081B8474
	movs r0, #0x20
	bl PlaySE
	adds r0, r4, #0
	bl DisplayPartyMenuStdMessage
	ldr r0, _081B846C
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B8470
	str r0, [r1]
	b _081B8480
	.align 2, 0
_081B846C: .4byte 0x03005B60
_081B8470: .4byte 0x081B8489
_081B8474:
	movs r0, #5
	bl PlaySE
	adds r0, r5, #0
	bl sub_081B0F90
_081B8480:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B843C

	thumb_func_start sub_081B8488
sub_081B8488: @ 0x081B8488
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _081B84C4
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081B84A2
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B84BC
_081B84A2:
	movs r0, #5
	bl PlaySE
	movs r0, #0
	bl DisplayPartyMenuStdMessage
	ldr r0, _081B84C8
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B84CC
	str r0, [r1]
_081B84BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B84C4: .4byte 0x03002360
_081B84C8: .4byte 0x03005B60
_081B84CC: .4byte 0x081B1041
	thumb_func_end sub_081B8488

	thumb_func_start sub_081B84D0
sub_081B84D0: @ 0x081B84D0
	push {lr}
	ldr r0, _081B84E8
	bl VarGet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	beq _081B84EC
	cmp r0, #9
	bne _081B84F0
	movs r0, #3
	b _081B84F4
	.align 2, 0
_081B84E8: .4byte 0x000040CF
_081B84EC:
	movs r0, #2
	b _081B84F4
_081B84F0:
	ldr r0, _081B84F8
	ldrb r0, [r0]
_081B84F4:
	pop {r1}
	bx r1
	.align 2, 0
_081B84F8: .4byte 0x02037282
	thumb_func_end sub_081B84D0

	thumb_func_start sub_081B84FC
sub_081B84FC: @ 0x081B84FC
	push {lr}
	ldr r0, _081B8514
	bl VarGet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	beq _081B8518
	cmp r0, #9
	bne _081B851C
	movs r0, #1
	b _081B8520
	.align 2, 0
_081B8514: .4byte 0x000040CF
_081B8518:
	movs r0, #2
	b _081B8520
_081B851C:
	ldr r0, _081B8524
	ldrb r0, [r0]
_081B8520:
	pop {r1}
	bx r1
	.align 2, 0
_081B8524: .4byte 0x02037282
	thumb_func_end sub_081B84FC

	thumb_func_start sub_081B8528
sub_081B8528: @ 0x081B8528
	push {lr}
	ldr r0, _081B8540
	bl VarGet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	beq _081B8544
	cmp r0, #9
	bne _081B8548
_081B853C:
	movs r0, #0x64
	b _081B8552
	.align 2, 0
_081B8540: .4byte 0x000040CF
_081B8544:
	movs r0, #0x1e
	b _081B8552
_081B8548:
	ldr r0, _081B8558
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B853C
	movs r0, #0x32
_081B8552:
	pop {r1}
	bx r1
	.align 2, 0
_081B8558: .4byte 0x02037280
	thumb_func_end sub_081B8528

	thumb_func_start sub_081B855C
sub_081B855C: @ 0x081B855C
	push {lr}
	ldr r0, _081B8578
	bl VarGet
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r2, #0xf8
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _081B8580
	ldr r0, _081B857C
	b _081B859A
	.align 2, 0
_081B8578: .4byte 0x000040CF
_081B857C: .4byte 0x085CA21C
_081B8580:
	cmp r1, #1
	bne _081B8598
	ldr r0, _081B8590
	ldrh r0, [r0]
	cmp r0, #2
	bne _081B8598
	ldr r0, _081B8594
	b _081B859A
	.align 2, 0
_081B8590: .4byte 0x02037282
_081B8594: .4byte 0x085CA229
_081B8598:
	ldr r0, _081B85A0
_081B859A:
	pop {r1}
	bx r1
	.align 2, 0
_081B85A0: .4byte 0x085CA238
	thumb_func_end sub_081B855C

	thumb_func_start sub_081B85A4
sub_081B85A4: @ 0x081B85A4
	push {lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	str r2, [sp]
	ldr r2, _081B85C8
	str r2, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B85C8: .4byte 0x081B1041
	thumb_func_end sub_081B85A4

	thumb_func_start sub_081B85CC
sub_081B85CC: @ 0x081B85CC
	push {lr}
	sub sp, #0xc
	movs r0, #4
	str r0, [sp]
	ldr r0, _081B85F0
	str r0, [sp, #4]
	ldr r0, _081B85F4
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0xc
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B85F0: .4byte 0x081B1041
_081B85F4: .4byte 0x08085B35
	thumb_func_end sub_081B85CC

	thumb_func_start sub_081B85F8
sub_081B85F8: @ 0x081B85F8
	push {lr}
	sub sp, #0xc
	movs r0, #1
	str r0, [sp]
	ldr r0, _081B861C
	str r0, [sp, #4]
	ldr r0, _081B8620
	str r0, [sp, #8]
	movs r0, #0xb
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B861C: .4byte 0x081B1041
_081B8620: .4byte 0x08085B35
	thumb_func_end sub_081B85F8

	thumb_func_start sub_081B8624
sub_081B8624: @ 0x081B8624
	push {lr}
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B8634
	movs r0, #0
	b _081B8646
_081B8634:
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B8644
	movs r0, #1
	b _081B8646
_081B8644:
	movs r0, #2
_081B8646:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081B8624

	thumb_func_start OpenPartyMenuInBattle
OpenPartyMenuInBattle: @ 0x081B864C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_081B8624
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0
	str r0, [sp]
	ldr r0, _081B8688
	str r0, [sp, #4]
	ldr r0, _081B868C
	str r0, [sp, #8]
	movs r0, #1
	adds r2, r4, #0
	movs r3, #0
	bl InitPartyMenu
	bl nullsub_35
	bl pokemon_change_order
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8688: .4byte 0x081B1041
_081B868C: .4byte 0x0805995D
	thumb_func_end OpenPartyMenuInBattle

	thumb_func_start sub_081B8690
sub_081B8690: @ 0x081B8690
	push {lr}
	sub sp, #0xc
	bl sub_081B8624
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #5
	str r0, [sp]
	ldr r0, _081B86C4
	str r0, [sp, #4]
	ldr r0, _081B86C8
	str r0, [sp, #8]
	movs r0, #1
	movs r2, #3
	movs r3, #0
	bl InitPartyMenu
	bl nullsub_35
	bl pokemon_change_order
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B86C4: .4byte 0x081B1041
_081B86C8: .4byte 0x081B5EF5
	thumb_func_end sub_081B8690

	thumb_func_start sub_081B86CC
sub_081B86CC: @ 0x081B86CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081B86F4
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B8714
	adds r0, r4, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	bne _081B8714
	ldr r0, _081B86F8
	ldrb r0, [r0, #0xb]
	cmp r0, #1
	bne _081B86FC
	movs r0, #3
	b _081B8716
	.align 2, 0
_081B86F4: .4byte 0x020241F4
_081B86F8: .4byte 0x0203CB94
_081B86FC:
	ldr r0, _081B8710
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	bne _081B8714
	movs r0, #2
	b _081B8716
	.align 2, 0
_081B8710: .4byte 0x02022C90
_081B8714:
	movs r0, #7
_081B8716:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081B86CC

	thumb_func_start sub_081B871C
sub_081B871C: @ 0x081B871C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl GetCursorSelectionMonId
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B8764
	cmp r5, #1
	beq _081B8742
	cmp r5, #4
	beq _081B8742
	cmp r5, #5
	bne _081B8764
_081B8742:
	ldr r4, _081B8758
	bl GetTrainerPartnerName
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldr r0, _081B875C
	ldr r1, _081B8760
	b _081B88E2
	.align 2, 0
_081B8758: .4byte 0x02021C40
_081B875C: .4byte 0x02021C7C
_081B8760: .4byte 0x085C9B76
_081B8764:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _081B8788
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	bne _081B8798
	ldr r1, _081B878C
	adds r0, r4, #0
	bl GetMonNickname
	ldr r0, _081B8790
	ldr r1, _081B8794
	b _081B88E2
	.align 2, 0
_081B8788: .4byte 0x02024190
_081B878C: .4byte 0x02021C40
_081B8790: .4byte 0x02021C7C
_081B8794: .4byte 0x085C9B59
_081B8798:
	movs r4, #0
	b _081B87C4
_081B879C:
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B87BE
	adds r0, r5, #0
	bl sub_081B8BD8
	lsls r0, r0, #0x18
	ldr r2, _081B87EC
	lsls r1, r4, #1
	adds r1, r1, r2
	lsrs r0, r0, #0x18
	ldrh r1, [r1]
	cmp r0, r1
	beq _081B889C
_081B87BE:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_081B87C4:
	ldr r0, _081B87F0
	ldrb r0, [r0]
	cmp r4, r0
	blo _081B879C
	movs r7, #0x64
	adds r0, r5, #0
	muls r0, r7, r0
	ldr r1, _081B87F4
	mov r8, r1
	adds r6, r0, r1
	adds r0, r6, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	beq _081B8800
	ldr r0, _081B87F8
	ldr r1, _081B87FC
	b _081B88E2
	.align 2, 0
_081B87EC: .4byte 0x02023D12
_081B87F0: .4byte 0x02023D10
_081B87F4: .4byte 0x02024190
_081B87F8: .4byte 0x02021C7C
_081B87FC: .4byte 0x085C9B9D
_081B8800:
	adds r0, r5, #0
	bl sub_081B8BD8
	ldr r1, _081B8824
	ldr r1, [r1]
	adds r1, #0x8b
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _081B8834
	ldr r1, _081B8828
	adds r0, r6, #0
	bl GetMonNickname
	ldr r0, _081B882C
	ldr r1, _081B8830
	b _081B88E2
	.align 2, 0
_081B8824: .4byte 0x02024140
_081B8828: .4byte 0x02021C40
_081B882C: .4byte 0x02021C7C
_081B8830: .4byte 0x085C9B43
_081B8834:
	ldr r0, _081B8844
	ldrb r0, [r0, #0xb]
	cmp r0, #4
	bne _081B8848
	bl SetMonPreventsSwitchingString
	b _081B88E6
	.align 2, 0
_081B8844: .4byte 0x0203CB94
_081B8848:
	cmp r0, #2
	beq _081B88C0
	adds r0, r5, #0
	bl sub_081B8BD8
	ldr r1, _081B888C
	strb r0, [r1]
	ldr r1, _081B8890
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B8894
	ldr r0, _081B8898
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_081B8C50
	adds r0, r4, #0
	muls r0, r7, r0
	add r0, r8
	adds r1, r6, #0
	bl sub_081B0F58
	movs r0, #1
	b _081B88E8
	.align 2, 0
_081B888C: .4byte 0x0203CBB5
_081B8890: .4byte 0x0203CBB4
_081B8894: .4byte 0x02023D12
_081B8898: .4byte 0x0202415C
_081B889C:
	movs r0, #0x64
	muls r0, r5, r0
	ldr r1, _081B88B0
	adds r0, r0, r1
	ldr r1, _081B88B4
	bl GetMonNickname
	ldr r0, _081B88B8
	ldr r1, _081B88BC
	b _081B88E2
	.align 2, 0
_081B88B0: .4byte 0x02024190
_081B88B4: .4byte 0x02021C40
_081B88B8: .4byte 0x02021C7C
_081B88BC: .4byte 0x085C9B2D
_081B88C0:
	ldr r0, _081B88F4
	ldrb r0, [r0]
	ldr r1, _081B88F8
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r7, r0
	add r0, r8
	ldr r1, _081B88FC
	bl GetMonNickname
	ldr r0, _081B8900
	ldr r1, _081B8904
_081B88E2:
	bl StringExpandPlaceholders
_081B88E6:
	movs r0, #0
_081B88E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B88F4: .4byte 0x0202415C
_081B88F8: .4byte 0x02023D12
_081B88FC: .4byte 0x02021C40
_081B8900: .4byte 0x02021C7C
_081B8904: .4byte 0x085C9B1A
	thumb_func_end sub_081B871C

	thumb_func_start sub_081B8908
sub_081B8908: @ 0x081B8908
	push {r4, lr}
	ldr r4, _081B8924
	bl sub_0806D288
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_081B8928
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8924: .4byte 0x0203CBCC
	thumb_func_end sub_081B8908

	thumb_func_start sub_081B8928
sub_081B8928: @ 0x081B8928
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B895E
	cmp r4, #0
	beq _081B8950
	movs r0, #0x30
	strb r0, [r6]
	movs r0, #0x45
	strb r0, [r6, #1]
	movs r0, #0x12
	strb r0, [r6, #2]
	b _081B89F8
_081B8950:
	movs r0, #3
	strb r0, [r6]
	movs r0, #0x12
	strb r0, [r6, #1]
	movs r0, #0x45
	strb r0, [r6, #2]
	b _081B89F8
_081B895E:
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B899C
	movs r5, #1
	movs r0, #0
	bl GetBattlerAtPosition
	mov r2, sp
	ldr r1, _081B8998
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	movs r4, #0
	mov r1, sp
_081B8982:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8990
	mov r2, sp
	adds r0, r2, r5
	strb r4, [r0]
	adds r5, #1
_081B8990:
	adds r4, #1
	cmp r4, #5
	ble _081B8982
	b _081B89E0
	.align 2, 0
_081B8998: .4byte 0x02023D12
_081B899C:
	movs r5, #2
	movs r0, #0
	bl GetBattlerAtPosition
	mov r1, sp
	ldr r4, _081B8A00
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r1]
	movs r0, #2
	bl GetBattlerAtPosition
	mov r1, sp
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r1, #1]
	movs r4, #0
_081B89C6:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B89DA
	ldrb r0, [r1, #1]
	cmp r4, r0
	beq _081B89DA
	mov r2, sp
	adds r0, r2, r5
	strb r4, [r0]
	adds r5, #1
_081B89DA:
	adds r4, #1
	cmp r4, #5
	ble _081B89C6
_081B89E0:
	movs r4, #0
	mov r3, sp
_081B89E4:
	adds r0, r6, r4
	ldrb r1, [r3]
	lsls r1, r1, #4
	ldrb r2, [r3, #1]
	orrs r1, r2
	strb r1, [r0]
	adds r3, #2
	adds r4, #1
	cmp r4, #2
	ble _081B89E4
_081B89F8:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8A00: .4byte 0x02023D12
	thumb_func_end sub_081B8928

	thumb_func_start sub_081B8A04
sub_081B8A04: @ 0x081B8A04
	push {lr}
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _081B8A24
	lsls r3, r2, #1
	adds r3, r3, r2
	adds r3, #0x60
	ldr r0, [r0]
	adds r0, r0, r3
	bl sub_081B8A28
	pop {r0}
	bx r0
	.align 2, 0
_081B8A24: .4byte 0x02024140
	thumb_func_end sub_081B8A04

	thumb_func_start sub_081B8A28
sub_081B8A28: @ 0x081B8A28
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, r2, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B8A50
	movs r0, #0
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #2
	b _081B8A5C
_081B8A50:
	movs r0, #1
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #3
_081B8A5C:
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B8A90
	cmp r7, #0
	beq _081B8A82
	movs r0, #0x30
	strb r0, [r5]
	movs r0, #0x45
	strb r0, [r5, #1]
	movs r0, #0x12
	strb r0, [r5, #2]
	b _081B8B12
_081B8A82:
	movs r0, #3
	strb r0, [r5]
	movs r0, #0x12
	strb r0, [r5, #1]
	movs r0, #0x45
	strb r0, [r5, #2]
	b _081B8B12
_081B8A90:
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B8AC8
	movs r3, #1
	mov r2, sp
	ldr r1, _081B8AC4
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	movs r4, #0
	mov r1, sp
_081B8AAC:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8ABA
	mov r2, sp
	adds r0, r2, r3
	strb r4, [r0]
	adds r3, #1
_081B8ABA:
	adds r4, #1
	cmp r4, #5
	ble _081B8AAC
	b _081B8AFA
	.align 2, 0
_081B8AC4: .4byte 0x02023D12
_081B8AC8:
	movs r3, #2
	mov r1, sp
	ldr r2, _081B8B1C
	lsls r0, r4, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	lsls r0, r6, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1, #1]
	movs r4, #0
_081B8AE0:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8AF4
	ldrb r0, [r1, #1]
	cmp r4, r0
	beq _081B8AF4
	mov r2, sp
	adds r0, r2, r3
	strb r4, [r0]
	adds r3, #1
_081B8AF4:
	adds r4, #1
	cmp r4, #5
	ble _081B8AE0
_081B8AFA:
	movs r4, #0
	mov r3, sp
_081B8AFE:
	adds r0, r5, r4
	ldrb r1, [r3]
	lsls r1, r1, #4
	ldrb r2, [r3, #1]
	orrs r1, r2
	strb r1, [r0]
	adds r3, #2
	adds r4, #1
	cmp r4, #2
	ble _081B8AFE
_081B8B12:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8B1C: .4byte 0x02023D12
	thumb_func_end sub_081B8A28

	thumb_func_start sub_081B8B20
sub_081B8B20: @ 0x081B8B20
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r7, #0
	bl IsMultiBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B8BCE
	ldr r0, _081B8B84
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r1, #0x60
	ldr r0, [r0]
	adds r4, r0, r1
	movs r2, #0
	add r6, sp
	mov ip, r6
	movs r6, #0xf
	mov r3, sp
_081B8B52:
	adds r1, r4, r2
	ldrb r0, [r1]
	lsrs r0, r0, #4
	strb r0, [r3]
	adds r3, #1
	ldrb r1, [r1]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r3]
	adds r3, #1
	adds r2, #1
	cmp r2, #2
	ble _081B8B52
	mov r0, ip
	ldrb r3, [r0]
	movs r2, #0
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, r5
	bne _081B8B88
	mov r0, sp
	ldrb r7, [r0]
	strb r3, [r0]
	b _081B8B9C
	.align 2, 0
_081B8B84: .4byte 0x02024140
_081B8B88:
	adds r2, #1
	cmp r2, #5
	bgt _081B8B9C
	mov r0, sp
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, r5
	bne _081B8B88
	adds r7, r0, #0
	strb r3, [r1]
_081B8B9C:
	cmp r2, #6
	beq _081B8BCE
	mov r0, ip
	strb r7, [r0]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #4
	mov r1, sp
	ldrb r1, [r1, #1]
	orrs r0, r1
	strb r0, [r4]
	mov r0, sp
	ldrb r0, [r0, #2]
	lsls r0, r0, #4
	mov r1, sp
	ldrb r1, [r1, #3]
	orrs r0, r1
	strb r0, [r4, #1]
	mov r0, sp
	ldrb r0, [r0, #4]
	lsls r0, r0, #4
	mov r1, sp
	ldrb r1, [r1, #5]
	orrs r0, r1
	strb r0, [r4, #2]
_081B8BCE:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B8B20

	thumb_func_start sub_081B8BD8
sub_081B8BD8: @ 0x081B8BD8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #1
	ands r1, r2
	lsrs r2, r0, #0x19
	cmp r1, #0
	beq _081B8BF8
	ldr r0, _081B8BF4
	adds r0, r2, r0
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	b _081B8C00
	.align 2, 0
_081B8BF4: .4byte 0x0203CBCC
_081B8BF8:
	ldr r0, _081B8C08
	adds r0, r2, r0
	ldrb r0, [r0]
	lsrs r1, r0, #4
_081B8C00:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_081B8C08: .4byte 0x0203CBCC
	thumb_func_end sub_081B8BD8

	thumb_func_start sub_081B8C0C
sub_081B8C0C: @ 0x081B8C0C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r1, #1
	ands r1, r3
	lsrs r3, r0, #0x19
	cmp r1, #0
	beq _081B8C34
	ldr r0, _081B8C30
	adds r0, r3, r0
	ldrb r2, [r0]
	movs r1, #0xf0
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	b _081B8C44
	.align 2, 0
_081B8C30: .4byte 0x0203CBCC
_081B8C34:
	ldr r2, _081B8C4C
	adds r2, r3, r2
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r1, r4, #4
	orrs r0, r1
	strb r0, [r2]
_081B8C44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8C4C: .4byte 0x0203CBCC
	thumb_func_end sub_081B8C0C

	thumb_func_start sub_081B8C50
sub_081B8C50: @ 0x081B8C50
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	adds r0, r5, #0
	bl sub_081B8BD8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r6, #0
	bl sub_081B8BD8
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl sub_081B8C0C
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_081B8C0C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B8C50

	thumb_func_start pokemon_order_func
pokemon_order_func: @ 0x081B8C8C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r3, #0
	movs r2, #0
	ldr r5, _081B8CB4
_081B8C98:
	adds r0, r3, r5
	ldrb r1, [r0]
	lsrs r0, r1, #4
	cmp r0, r4
	beq _081B8CB0
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0xf
	ands r0, r1
	cmp r0, r4
	bne _081B8CB8
_081B8CB0:
	adds r0, r2, #0
	b _081B8CCA
	.align 2, 0
_081B8CB4: .4byte 0x0203CBCC
_081B8CB8:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #2
	bls _081B8C98
	movs r0, #0
_081B8CCA:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end pokemon_order_func

	thumb_func_start pokemon_change_order
pokemon_change_order: @ 0x081B8CD0
	push {r4, r5, r6, lr}
	movs r4, #0x96
	lsls r4, r4, #2
	adds r0, r4, #0
	bl Alloc
	adds r5, r0, #0
	ldr r1, _081B8D1C
	adds r2, r4, #0
	bl memcpy
	movs r4, #0
	movs r6, #0x64
_081B8CEA:
	adds r0, r4, #0
	bl pokemon_order_func
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r6, r0
	ldr r1, _081B8D1C
	adds r0, r0, r1
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	movs r2, #0x64
	bl memcpy
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _081B8CEA
	adds r0, r5, #0
	bl Free
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8D1C: .4byte 0x02024190
	thumb_func_end pokemon_change_order

	thumb_func_start sub_081B8D20
sub_081B8D20: @ 0x081B8D20
	push {r4, r5, r6, lr}
	movs r4, #0x96
	lsls r4, r4, #2
	adds r0, r4, #0
	bl Alloc
	adds r5, r0, #0
	ldr r1, _081B8D6C
	adds r2, r4, #0
	bl memcpy
	movs r4, #0
	movs r6, #0x64
_081B8D3A:
	adds r0, r4, #0
	bl sub_081B8BD8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r6, r0
	ldr r1, _081B8D6C
	adds r0, r0, r1
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	movs r2, #0x64
	bl memcpy
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _081B8D3A
	adds r0, r5, #0
	bl Free
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8D6C: .4byte 0x02024190
	thumb_func_end sub_081B8D20

	thumb_func_start sub_081B8D70
sub_081B8D70: @ 0x081B8D70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #1
	movs r7, #0x64
	ldr r0, _081B8DC8
	mov r8, r0
_081B8D7E:
	adds r0, r6, #0
	bl sub_081B8BD8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r7, r0
	mov r1, r8
	adds r5, r0, r1
	adds r0, r5, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B8DCC
	adds r0, r5, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	beq _081B8DCC
	movs r0, #0
	bl sub_081B8BD8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0
	adds r1, r6, #0
	bl sub_081B8C50
	adds r0, r4, #0
	muls r0, r7, r0
	add r0, r8
	adds r1, r5, #0
	bl sub_081B0F58
	b _081B8DD6
	.align 2, 0
_081B8DC8: .4byte 0x02024190
_081B8DCC:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #5
	bls _081B8D7E
_081B8DD6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_081B8D70

	thumb_func_start sub_081B8DE0
sub_081B8DE0: @ 0x081B8DE0
	push {lr}
	ldr r0, _081B8DEC
	bl SetMainCallback2
	pop {r0}
	bx r0
	.align 2, 0
_081B8DEC: .4byte 0x0805995D
	thumb_func_end sub_081B8DE0

	thumb_func_start sub_081B8DF0
sub_081B8DF0: @ 0x081B8DF0
	push {lr}
	sub sp, #0xc
	movs r0, #0x7f
	str r0, [sp]
	ldr r0, _081B8E14
	str r0, [sp, #4]
	ldr r0, _081B8E18
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	movs r0, #5
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B8E14: .4byte 0x081B8E1D
_081B8E18: .4byte 0x03002360
	thumb_func_end sub_081B8DF0

	thumb_func_start sub_081B8E1C
sub_081B8E1C: @ 0x081B8E1C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _081B8E4C
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #3
	adds r4, r4, r1
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r4, #8]
	bl sub_081B8F34
	movs r1, #0x80
	lsls r1, r1, #9
	movs r0, #2
	movs r2, #0
	bl ChangeBgX
	ldr r0, _081B8E50
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8E4C: .4byte 0x03005B60
_081B8E50: .4byte 0x081B8E55
	thumb_func_end sub_081B8E1C

	thumb_func_start sub_081B8E54
sub_081B8E54: @ 0x081B8E54
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r6, r5, #2
	adds r0, r6, r5
	lsls r0, r0, #3
	ldr r1, _081B8EC8
	adds r4, r0, r1
	ldr r0, _081B8ECC
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B8EC0
	ldrh r0, [r4]
	subs r0, #8
	strh r0, [r4]
	adds r0, r5, #0
	bl sub_081B8F34
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _081B8EC0
	movs r4, #3
	ldr r7, _081B8ED0
_081B8E88:
	subs r0, r4, #3
	lsls r0, r0, #5
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _081B8EA4
	ldr r0, _081B8ED4
	ldr r1, [r0]
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrb r0, [r0, #9]
	movs r1, #0
	bl AnimateSelectedPartyIcon
_081B8EA4:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _081B8E88
	movs r0, #0x78
	bl PlaySE
	ldr r0, _081B8ED8
	adds r1, r6, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B8EDC
	str r0, [r1]
_081B8EC0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8EC8: .4byte 0x03005B68
_081B8ECC: .4byte 0x02037C74
_081B8ED0: .4byte 0x02022C9C
_081B8ED4: .4byte 0x0203CBA8
_081B8ED8: .4byte 0x03005B60
_081B8EDC: .4byte 0x081B8EE1
	thumb_func_end sub_081B8E54

	thumb_func_start sub_081B8EE0
sub_081B8EE0: @ 0x081B8EE0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _081B8F0C
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	cmp r1, r0
	bne _081B8F06
	adds r0, r2, #0
	bl sub_081B0F90
_081B8F06:
	pop {r0}
	bx r0
	.align 2, 0
_081B8F0C: .4byte 0x03005B68
	thumb_func_end sub_081B8EE0

	thumb_func_start sub_081B8F10
sub_081B8F10: @ 0x081B8F10
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	cmp r1, #0
	blt _081B8F2A
	ldr r1, _081B8F30
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	strh r3, [r0, #0x24]
_081B8F2A:
	pop {r0}
	bx r0
	.align 2, 0
_081B8F30: .4byte 0x020205AC
	thumb_func_end sub_081B8F10

	thumb_func_start sub_081B8F34
sub_081B8F34: @ 0x081B8F34
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _081B8FBC
	adds r5, r1, r0
	movs r6, #3
	ldr r7, _081B8FC0
_081B8F48:
	ldr r0, _081B8FC4
	subs r1, r6, #3
	lsls r1, r1, #5
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081B8FA0
	ldr r0, [r7]
	lsls r4, r6, #4
	adds r0, r4, r0
	ldrb r0, [r0, #9]
	ldrh r1, [r5]
	subs r1, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_081B8F10
	ldr r0, [r7]
	adds r0, r4, r0
	ldrb r0, [r0, #0xa]
	ldrh r1, [r5]
	subs r1, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_081B8F10
	ldr r0, [r7]
	adds r0, r4, r0
	ldrb r0, [r0, #0xb]
	ldrh r1, [r5]
	subs r1, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_081B8F10
	ldr r0, [r7]
	adds r4, r4, r0
	ldrb r0, [r4, #0xc]
	ldrh r1, [r5]
	subs r1, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_081B8F10
_081B8FA0:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #5
	bls _081B8F48
	movs r1, #0x80
	lsls r1, r1, #4
	movs r0, #2
	movs r2, #1
	bl ChangeBgX
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8FBC: .4byte 0x03005B68
_081B8FC0: .4byte 0x0203CBA8
_081B8FC4: .4byte 0x02022C9C
	thumb_func_end sub_081B8F34

	thumb_func_start sub_081B8FC8
sub_081B8FC8: @ 0x081B8FC8
	push {lr}
	sub sp, #0xc
	movs r0, #0xf
	str r0, [sp]
	ldr r0, _081B8FEC
	str r0, [sp, #4]
	ldr r0, _081B8FF0
	str r0, [sp, #8]
	movs r0, #6
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B8FEC: .4byte 0x081B1041
_081B8FF0: .4byte 0x081B9031
	thumb_func_end sub_081B8FC8

	thumb_func_start sub_081B8FF4
sub_081B8FF4: @ 0x081B8FF4
	push {lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _081B9020
	ldr r1, _081B9024
	str r1, [r2]
	movs r1, #0
	str r1, [sp]
	ldr r1, _081B9028
	str r1, [sp, #4]
	ldr r1, _081B902C
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xb
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B9020: .4byte 0x03005B10
_081B9024: .4byte 0x081B9069
_081B9028: .4byte 0x081B1041
_081B902C: .4byte 0x08085A31
	thumb_func_end sub_081B8FF4

	thumb_func_start sub_081B9030
sub_081B9030: @ 0x081B9030
	push {r4, lr}
	ldr r4, _081B9058
	bl GetCursorSelectionMonId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4]
	cmp r0, #5
	bls _081B9046
	movs r0, #0xff
	strh r0, [r4]
_081B9046:
	ldr r0, _081B905C
	ldr r1, _081B9060
	str r1, [r0]
	ldr r0, _081B9064
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B9058: .4byte 0x02037280
_081B905C: .4byte 0x03005B10
_081B9060: .4byte 0x081B9069
_081B9064: .4byte 0x08085A31
	thumb_func_end sub_081B9030

	thumb_func_start hm_add_c3_without_phase_2
hm_add_c3_without_phase_2: @ 0x081B9068
	push {lr}
	bl FadeInFromBlack
	ldr r0, _081B907C
	movs r1, #0xa
	bl CreateTask
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081B907C: .4byte 0x081B9081
	thumb_func_end hm_add_c3_without_phase_2

	thumb_func_start task_hm_without_phase_2
task_hm_without_phase_2: @ 0x081B9080
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsWeatherNotFadingIn
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B909E
	adds r0, r4, #0
	bl DestroyTask
	bl UnlockPlayerFieldControls
	bl ScriptContext_Enable
_081B909E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task_hm_without_phase_2

	thumb_func_start sub_081B90A4
sub_081B90A4: @ 0x081B90A4
	push {lr}
	bl LockPlayerFieldControls
	movs r0, #1
	movs r1, #0
	bl FadeScreen
	ldr r0, _081B90C0
	movs r1, #0xa
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
_081B90C0: .4byte 0x081B90C5
	thumb_func_end sub_081B90A4

	thumb_func_start sub_081B90C4
sub_081B90C4: @ 0x081B90C4
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B9104
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081B90FC
	bl CleanupOverworldWindowsAndTilemaps
	str r4, [sp]
	ldr r0, _081B9108
	str r0, [sp, #4]
	ldr r0, _081B910C
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r2, #0xb
	movs r3, #0
	bl InitPartyMenu
	adds r0, r5, #0
	bl DestroyTask
_081B90FC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B9104: .4byte 0x02037C74
_081B9108: .4byte 0x081B1041
_081B910C: .4byte 0x081B9111
	thumb_func_end sub_081B90C4

	thumb_func_start sub_081B9110
sub_081B9110: @ 0x081B9110
	push {lr}
	bl GetCursorSelectionMonId
	ldr r2, _081B913C
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _081B9126
	movs r0, #0xff
	strb r0, [r2]
_081B9126:
	ldr r1, _081B9140
	ldrb r0, [r2]
	strh r0, [r1]
	ldr r1, _081B9144
	ldr r0, _081B9148
	str r0, [r1]
	ldr r0, _081B914C
	bl SetMainCallback2
	pop {r0}
	bx r0
	.align 2, 0
_081B913C: .4byte 0x02039BC4
_081B9140: .4byte 0x02037280
_081B9144: .4byte 0x03005B10
_081B9148: .4byte 0x081B9069
_081B914C: .4byte 0x08085A31
	thumb_func_end sub_081B9110

	thumb_func_start sub_081B9150
sub_081B9150: @ 0x081B9150
	push {lr}
	bl LockPlayerFieldControls
	movs r0, #1
	movs r1, #0
	bl FadeScreen
	ldr r0, _081B916C
	movs r1, #0xa
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
_081B916C: .4byte 0x081B9171
	thumb_func_end sub_081B9150

	thumb_func_start sub_081B9170
sub_081B9170: @ 0x081B9170
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B91B0
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081B91A8
	bl CleanupOverworldWindowsAndTilemaps
	str r4, [sp]
	ldr r0, _081B91B4
	str r0, [sp, #4]
	ldr r0, _081B91B8
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #0
	movs r2, #0xb
	movs r3, #0
	bl InitPartyMenu
	adds r0, r5, #0
	bl DestroyTask
_081B91A8:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B91B0: .4byte 0x02037C74
_081B91B4: .4byte 0x081B1041
_081B91B8: .4byte 0x081B9031
	thumb_func_end sub_081B9170

	thumb_func_start sub_081B91BC
sub_081B91BC: @ 0x081B91BC
	push {lr}
	bl LockPlayerFieldControls
	movs r0, #1
	movs r1, #0
	bl FadeScreen
	ldr r0, _081B91D8
	movs r1, #0xa
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
_081B91D8: .4byte 0x081B91DD
	thumb_func_end sub_081B91BC

	thumb_func_start sub_081B91DC
sub_081B91DC: @ 0x081B91DC
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B921C
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081B9214
	bl CleanupOverworldWindowsAndTilemaps
	str r4, [sp]
	ldr r0, _081B9220
	str r0, [sp, #4]
	ldr r0, _081B9224
	str r0, [sp, #8]
	movs r0, #7
	movs r1, #0
	movs r2, #0xb
	movs r3, #0
	bl InitPartyMenu
	adds r0, r5, #0
	bl DestroyTask
_081B9214:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B921C: .4byte 0x02037C74
_081B9220: .4byte 0x081B1041
_081B9224: .4byte 0x081B9229
	thumb_func_end sub_081B91DC

	thumb_func_start sub_081B9228
sub_081B9228: @ 0x081B9228
	push {r4, r5, lr}
	ldr r5, _081B9240
	bl GetCursorSelectionMonId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5]
	cmp r0, #5
	bls _081B9244
	movs r0, #0xff
	strh r0, [r5]
	b _081B925A
	.align 2, 0
_081B9240: .4byte 0x02037280
_081B9244:
	ldr r4, _081B926C
	ldrh r1, [r5]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B9270
	adds r0, r0, r1
	bl GetNumberOfRelearnableMoves
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4]
_081B925A:
	ldr r0, _081B9274
	ldr r1, _081B9278
	str r1, [r0]
	ldr r0, _081B927C
	bl SetMainCallback2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B926C: .4byte 0x02037282
_081B9270: .4byte 0x02024190
_081B9274: .4byte 0x03005B10
_081B9278: .4byte 0x081B9069
_081B927C: .4byte 0x08085A31
	thumb_func_end sub_081B9228

	thumb_func_start sub_081B9280
sub_081B9280: @ 0x081B9280
	push {r4, r5, lr}
	ldr r1, _081B9290
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	adds r5, r1, #0
	b _081B929A
	.align 2, 0
_081B9290: .4byte 0x02037290
_081B9294:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_081B929A:
	cmp r4, #2
	bhi _081B92B4
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _081B92BC
	adds r0, r0, r1
	movs r1, #0xc
	bl GetMonData3
	cmp r0, #0
	beq _081B9294
	movs r0, #1
	strh r0, [r5]
_081B92B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B92BC: .4byte 0x02024190
	thumb_func_end sub_081B9280

	thumb_func_start sub_081B92C0
sub_081B92C0: @ 0x081B92C0
	push {lr}
	bl LockPlayerFieldControls
	movs r0, #1
	movs r1, #0
	bl FadeScreen
	ldr r0, _081B92DC
	movs r1, #0xa
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
_081B92DC: .4byte 0x081B92E1
	thumb_func_end sub_081B92C0

	thumb_func_start sub_081B92E0
sub_081B92E0: @ 0x081B92E0
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B9320
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081B9318
	bl CleanupOverworldWindowsAndTilemaps
	str r4, [sp]
	ldr r0, _081B9324
	str r0, [sp, #4]
	ldr r0, _081B9328
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	adds r0, r5, #0
	bl DestroyTask
_081B9318:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B9320: .4byte 0x02037C74
_081B9324: .4byte 0x081B1041
_081B9328: .4byte 0x081B9031
	thumb_func_end sub_081B92E0

	thumb_func_start sub_081B932C
sub_081B932C: @ 0x081B932C
	push {lr}
	sub sp, #4
	ldr r1, _081B9358
	ldr r0, _081B935C
	ldrb r2, [r0]
	ldr r0, _081B9360
	ldrb r3, [r0]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, _081B9364
	str r0, [sp]
	movs r0, #3
	bl ShowPokemonSummaryScreen
	ldr r1, _081B9368
	ldr r0, _081B936C
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_081B9358: .4byte 0x02024190
_081B935C: .4byte 0x02037280
_081B9360: .4byte 0x0202418D
_081B9364: .4byte 0x08085A31
_081B9368: .4byte 0x03005B0C
_081B936C: .4byte 0x080AEA65
	thumb_func_end sub_081B932C

	thumb_func_start sub_081B9370
sub_081B9370: @ 0x081B9370
	push {r4, r5, lr}
	ldr r1, _081B93AC
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	adds r5, r1, #0
_081B937C:
	ldr r0, _081B93B0
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B93B4
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xd
	bl GetMonData3
	cmp r0, #0
	beq _081B939A
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_081B939A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _081B937C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B93AC: .4byte 0x02037290
_081B93B0: .4byte 0x02037280
_081B93B4: .4byte 0x02024190
	thumb_func_end sub_081B9370

	thumb_func_start sub_081B93B8
sub_081B93B8: @ 0x081B93B8
	push {r4, r5, lr}
	ldr r0, _081B93F8
	ldrh r1, [r0]
	movs r0, #0x64
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r0, _081B93FC
	adds r5, r5, r0
	ldr r0, _081B9400
	ldrh r1, [r0]
	adds r1, #0xd
	adds r0, r5, #0
	bl GetMonData3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, _081B9404
	adds r0, r5, #0
	bl GetMonNickname
	ldr r0, _081B9408
	lsls r4, r4, #3
	ldr r1, _081B940C
	adds r4, r4, r1
	adds r1, r4, #0
	bl StringCopy
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B93F8: .4byte 0x02037280
_081B93FC: .4byte 0x02024190
_081B9400: .4byte 0x02037282
_081B9404: .4byte 0x02021C40
_081B9408: .4byte 0x02021C54
_081B940C: .4byte 0x082EACC4
	thumb_func_end sub_081B93B8

	thumb_func_start sub_081B9410
sub_081B9410: @ 0x081B9410
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, _081B9470
	mov r8, r0
	ldrh r0, [r0]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _081B9474
	adds r0, r0, r5
	ldr r4, _081B9478
	ldrb r2, [r4]
	movs r1, #0
	bl SetMonMoveSlot
	mov r1, r8
	ldrh r0, [r1]
	muls r0, r6, r0
	adds r0, r0, r5
	ldrb r1, [r4]
	bl RemoveMonPPBonus
	ldrh r4, [r4]
	cmp r4, #2
	bhi _081B9464
_081B9442:
	ldr r0, _081B9470
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B9474
	adds r0, r0, r1
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r4, #1
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	bl sub_081B947C
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #2
	bls _081B9442
_081B9464:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B9470: .4byte 0x02037280
_081B9474: .4byte 0x02024190
_081B9478: .4byte 0x02037282
	thumb_func_end sub_081B9410

	thumb_func_start sub_081B947C
sub_081B947C: @ 0x081B947C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	adds r5, r1, #0
	adds r4, r2, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	adds r0, #0xd
	str r0, [sp, #8]
	mov r0, r8
	ldr r1, [sp, #8]
	bl GetMonData3
	mov r1, sp
	adds r1, #2
	str r1, [sp, #0x14]
	strh r0, [r1]
	adds r3, r4, #0
	adds r3, #0xd
	str r3, [sp, #0xc]
	mov r0, r8
	adds r1, r3, #0
	bl GetMonData3
	mov r1, sp
	strh r0, [r1]
	adds r7, r5, #0
	adds r7, #0x11
	str r7, [sp, #0x10]
	mov r0, r8
	adds r1, r7, #0
	bl GetMonData3
	mov r1, sp
	adds r1, #5
	str r1, [sp, #0x18]
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x11
	str r3, [sp, #0x1c]
	mov r0, r8
	adds r1, r3, #0
	bl GetMonData3
	add r7, sp, #4
	mov sl, r7
	strb r0, [r7]
	mov r0, r8
	movs r1, #0x15
	bl GetMonData3
	mov r6, sp
	adds r6, #6
	strb r0, [r6]
	ldr r1, _081B9578
	adds r0, r5, r1
	ldrb r0, [r0]
	mov sb, r0
	ldrb r0, [r6]
	adds r2, r0, #0
	mov r3, sb
	ands r2, r3
	lsls r5, r5, #1
	asrs r2, r5
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r1, r4, r1
	ldrb r3, [r1]
	adds r1, r0, #0
	ands r1, r3
	lsls r4, r4, #1
	asrs r1, r4
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r7, sb
	bics r0, r7
	strb r0, [r6]
	ldrb r0, [r6]
	bics r0, r3
	strb r0, [r6]
	lsls r2, r4
	lsls r1, r5
	adds r2, r2, r1
	ldrb r0, [r6]
	orrs r0, r2
	strb r0, [r6]
	mov r0, r8
	ldr r1, [sp, #8]
	mov r2, sp
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x14]
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, #0x10]
	mov r2, sl
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	bl SetMonData
	mov r0, r8
	movs r1, #0x15
	adds r2, r6, #0
	bl SetMonData
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B9578: .4byte 0x082FA6AA
	thumb_func_end sub_081B947C

	thumb_func_start sub_081B957C
sub_081B957C: @ 0x081B957C
	push {lr}
	ldr r0, _081B95A0
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B95A4
	adds r0, r0, r1
	movs r1, #0x2d
	bl GetMonData3
	adds r1, r0, #0
	cmp r1, #0
	beq _081B95AC
	ldr r1, _081B95A8
	movs r0, #1
	strh r0, [r1]
	b _081B95B0
	.align 2, 0
_081B95A0: .4byte 0x02037280
_081B95A4: .4byte 0x02024190
_081B95A8: .4byte 0x02037290
_081B95AC:
	ldr r0, _081B95B4
	strh r1, [r0]
_081B95B0:
	pop {r0}
	bx r0
	.align 2, 0
_081B95B4: .4byte 0x02037290
	thumb_func_end sub_081B957C

	thumb_func_start sub_081B95B8
sub_081B95B8: @ 0x081B95B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _081B95E8
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081B95EC
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B95F0
	adds r0, r0, r1
	ldr r1, _081B95F4
	ldrh r1, [r1]
	adds r1, #0xd
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0x39
	bne _081B963C
	movs r6, #0
	b _081B9620
	.align 2, 0
_081B95E8: .4byte 0x02037290
_081B95EC: .4byte 0x02037280
_081B95F0: .4byte 0x02024190
_081B95F4: .4byte 0x02037282
_081B95F8:
	ldr r0, _081B9648
	ldrh r0, [r0]
	cmp r6, r0
	beq _081B961E
	movs r4, #0
	movs r0, #0x64
	adds r5, r6, #0
	muls r5, r0, r5
	ldr r7, _081B964C
_081B960A:
	adds r1, r4, #0
	adds r1, #0xd
	adds r0, r5, r7
	bl GetMonData3
	cmp r0, #0x39
	beq _081B963C
	adds r4, #1
	cmp r4, #3
	bls _081B960A
_081B961E:
	adds r6, #1
_081B9620:
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r0
	blo _081B95F8
	mov r0, r8
	bl AnyStorageMonWithMove
	cmp r0, #1
	beq _081B963C
	ldr r1, _081B9650
	movs r0, #1
	strh r0, [r1]
_081B963C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B9648: .4byte 0x02037280
_081B964C: .4byte 0x02024190
_081B9650: .4byte 0x02037290
	thumb_func_end sub_081B95B8

	.globl ShowContestResults
	.set ShowContestResults, sub_081B90A4
