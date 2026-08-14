.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

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
