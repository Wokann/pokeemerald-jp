.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_080DB694
sub_080DB694: @ 0x080DB694
	push {lr}
	lsls r0, r0, #4
	adds r0, r0, r2
	lsls r1, r1, #4
	adds r3, r1, r2
	ldr r2, [r0]
	ldr r1, [r3]
	cmp r2, r1
	blt _080DB6C4
	cmp r2, r1
	bgt _080DB6B6
	ldr r2, [r0, #4]
	ldr r1, [r3, #4]
	cmp r2, r1
	blt _080DB6C4
	cmp r2, r1
	ble _080DB6BA
_080DB6B6:
	movs r2, #0
	b _080DB6C6
_080DB6BA:
	ldr r1, [r0, #8]
	ldr r0, [r3, #8]
	movs r2, #0
	cmp r1, r0
	bge _080DB6C6
_080DB6C4:
	movs r2, #1
_080DB6C6:
	adds r0, r2, #0
	pop {r1}
	bx r1
	thumb_func_end sub_080DB694

	thumb_func_start ContestPrintLinkStandby
ContestPrintLinkStandby: @ 0x080DB6CC
	push {lr}
	ldr r0, _080DB6E8
	movs r1, #0
	strh r1, [r0]
	ldr r0, _080DB6EC
	strh r1, [r0]
	bl sub_080DB000
	ldr r0, _080DB6F0
	movs r1, #0
	bl Contest_StartTextPrinter
	pop {r0}
	bx r0
	.align 2, 0
_080DB6E8: .4byte 0x02022ACA
_080DB6EC: .4byte 0x02022AD2
_080DB6F0: .4byte 0x0824C140
	thumb_func_end ContestPrintLinkStandby

	thumb_func_start FillContestantWindowBgs
FillContestantWindowBgs: @ 0x080DB6F4
	push {r4, r5, lr}
	sub sp, #0xc
	movs r5, #0x80
	lsls r5, r5, #0x12
	movs r4, #3
_080DB6FE:
	lsrs r3, r5, #0x18
	movs r0, #8
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0x16
	bl ContestBG_FillBoxWithTile
	movs r0, #0xa0
	lsls r0, r0, #0x13
	adds r5, r5, r0
	subs r4, #1
	cmp r4, #0
	bge _080DB6FE
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end FillContestantWindowBgs

	thumb_func_start sub_080DB72C
sub_080DB72C: @ 0x080DB72C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080DB750
	cmp r0, #0
	beq _080DB746
	ldr r1, _080DB754
	cmp r0, #1
	beq _080DB746
	ldr r1, _080DB758
	cmp r0, #2
	bne _080DB746
	ldr r1, _080DB75C
_080DB746:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.align 2, 0
_080DB750: .4byte 0x00005011
_080DB754: .4byte 0x00006011
_080DB758: .4byte 0x00008011
_080DB75C: .4byte 0x00007011
	thumb_func_end sub_080DB72C

	thumb_func_start sub_080DB760
sub_080DB760: @ 0x080DB760
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	asrs r2, r0, #0x18
	cmp r2, #0x10
	ble _080DB77A
	movs r1, #0x10
	b _080DB784
_080DB77A:
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r2, r0
	bge _080DB784
	movs r1, #0xf0
_080DB784:
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	thumb_func_end sub_080DB760

	thumb_func_start sub_080DB78C
sub_080DB78C: @ 0x080DB78C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	ldr r0, _080DB820
	ldr r0, [r0]
	ldr r0, [r0, #0x14]
	lsls r1, r2, #2
	adds r1, r1, r0
	ldrb r0, [r1, #2]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1, #2]
	ldr r0, _080DB824
	movs r1, #0x14
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r0, r5, #0
	bl sub_080DB760
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	adds r5, r5, r6
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r0, r5, #0
	bl sub_080DB760
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	subs r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r0, r8
	bl sub_080DB72C
	ldr r2, _080DB828
	lsls r3, r7, #2
	adds r0, r3, r7
	lsls r0, r0, #3
	adds r1, r0, r2
	adds r0, r4, #0
	cmp r4, #0
	bge _080DB804
	rsbs r0, r4, #0
_080DB804:
	strh r0, [r1, #8]
	lsls r0, r5, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #0xa]
	cmp r4, #0
	bgt _080DB818
	cmp r4, #0
	bne _080DB82C
	cmp r0, #0
	ble _080DB82C
_080DB818:
	movs r0, #1
	strh r0, [r1, #0xc]
	b _080DB83A
	.align 2, 0
_080DB820: .4byte 0x02039BD4
_080DB824: .4byte 0x080DB859
_080DB828: .4byte 0x03005B60
_080DB82C:
	ldr r2, _080DB850
	lsls r3, r7, #2
	adds r0, r3, r7
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, _080DB854
	strh r1, [r0, #0xc]
_080DB83A:
	adds r0, r3, r7
	lsls r0, r0, #3
	adds r0, r0, r2
	mov r1, r8
	strh r1, [r0, #0xe]
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DB850: .4byte 0x03005B60
_080DB854: .4byte 0x0000FFFF
	thumb_func_end sub_080DB78C

	thumb_func_start sub_080DB858
sub_080DB858: @ 0x080DB858
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _080DB8B8
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r4, r0, r1
	ldrb r0, [r4, #0xe]
	mov sb, r0
	ldrh r3, [r4, #8]
	ldrh r1, [r4, #0xa]
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bgt _080DB88A
	b _080DBA0C
_080DB88A:
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldrh r2, [r4, #0xa]
	movs r5, #0xa
	ldrsh r0, [r4, r5]
	cmp r0, #0
	bne _080DB8C0
	adds r0, r7, #0
	bl DestroyTask
	ldr r0, _080DB8BC
	ldr r0, [r0]
	ldr r0, [r0, #0x14]
	mov r2, sb
	lsls r1, r2, #2
	adds r1, r1, r0
	ldrb r2, [r1, #2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #2]
	b _080DBA0C
	.align 2, 0
_080DB8B8: .4byte 0x03005B60
_080DB8BC: .4byte 0x02039BD4
_080DB8C0:
	cmp r3, #0
	bne _080DB908
	lsls r0, r1, #0x10
	mov r8, r0
	cmp r0, #0
	bge _080DB8DE
	mov r0, sb
	bl sub_080DB72C
	adds r0, #2
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r0, [r4, #0xa]
	adds r0, #1
	b _080DB8EC
_080DB8DE:
	mov r0, sb
	bl sub_080DB72C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r0, [r4, #0xa]
	subs r0, #1
_080DB8EC:
	strh r0, [r4, #0xa]
	ldr r1, _080DB904
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #8]
	adds r2, r1, #1
	strh r2, [r0, #8]
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	b _080DB974
	.align 2, 0
_080DB904: .4byte 0x03005B60
_080DB908:
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bge _080DB942
	lsls r0, r1, #0x10
	mov r8, r0
	cmp r0, #0
	bge _080DB930
	ldrh r0, [r4, #8]
	adds r1, r0, #1
	strh r1, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r2, #1
	strh r0, [r4, #0xa]
	mov r0, sb
	bl sub_080DB72C
	adds r0, #2
	b _080DB970
_080DB930:
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r6, #0
	subs r0, r2, #1
	strh r0, [r4, #0xa]
	b _080DB974
_080DB942:
	lsls r0, r1, #0x10
	mov r8, r0
	cmp r0, #0
	bge _080DB95C
	ldrh r0, [r4, #8]
	subs r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r6, #0
	adds r0, r2, #1
	strh r0, [r4, #0xa]
	b _080DB974
_080DB95C:
	ldrh r0, [r4, #8]
	adds r1, r0, #1
	strh r1, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	subs r0, r2, #1
	strh r0, [r4, #0xa]
	mov r0, sb
	bl sub_080DB72C
_080DB970:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_080DB974:
	str r5, [sp, #0xc]
	movs r0, #0
	mov sl, r0
	cmp r5, #7
	bls _080DB98A
	movs r2, #1
	mov sl, r2
	adds r0, r5, #0
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080DB98A:
	adds r2, r5, #0
	adds r2, #0x16
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _080DB9DC
	add r0, sb
	ldrb r0, [r0]
	lsls r3, r0, #2
	adds r3, r3, r0
	adds r3, #2
	add r3, sl
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	adds r1, r6, #0
	bl ContestBG_FillBoxWithTile
	mov r3, r8
	cmp r3, #0
	ble _080DB9E8
	movs r0, #0x60
	bl PlaySE
	ldr r4, _080DB9E0
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _080DB9E4
	ldr r0, [sp, #0xc]
	lsls r2, r0, #0x18
	asrs r2, r2, #0x10
	adds r0, r4, #0
	bl m4aMPlayPitchControl
	b _080DB9EE
	.align 2, 0
_080DB9DC: .4byte 0x02039BC6
_080DB9E0: .4byte 0x03007510
_080DB9E4: .4byte 0x0000FFFF
_080DB9E8:
	movs r0, #0x16
	bl PlaySE
_080DB9EE:
	mov r2, sl
	cmp r2, #0
	bne _080DBA0C
	cmp r5, #0
	bne _080DBA0C
	cmp r6, #0
	bne _080DBA0C
	ldr r0, _080DBA1C
	lsls r1, r7, #2
	adds r1, r1, r7
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #0xc]
	rsbs r0, r0, #0
	strh r0, [r1, #0xc]
_080DBA0C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DBA1C: .4byte 0x03005B60
	thumb_func_end sub_080DB858

	thumb_func_start sub_080DBA20
sub_080DBA20: @ 0x080DBA20
	push {r4, r5, lr}
	ldr r0, _080DBA58
	bl LoadSpriteSheet
	movs r4, #0
	ldr r5, _080DBA5C
_080DBA2C:
	ldr r0, _080DBA60
	adds r0, r4, r0
	ldrb r0, [r0]
	adds r0, r0, r5
	ldrb r2, [r0]
	ldr r0, _080DBA64
	movs r1, #0xb4
	movs r3, #1
	bl CreateSprite
	ldr r1, _080DBA68
	ldr r1, [r1]
	ldr r2, [r1, #0x14]
	lsls r1, r4, #2
	adds r1, r1, r2
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _080DBA2C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DBA58: .4byte 0x085609D8
_080DBA5C: .4byte 0x085609D0
_080DBA60: .4byte 0x02039BC6
_080DBA64: .4byte 0x08560A34
_080DBA68: .4byte 0x02039BD4
	thumb_func_end sub_080DBA20

	thumb_func_start sub_080DBA6C
sub_080DBA6C: @ 0x080DBA6C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r4, _080DBAB0
	ldr r0, [r4]
	ldr r2, [r0, #0x14]
	lsls r3, r6, #2
	adds r2, r3, r2
	ldrb r0, [r2, #2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #2]
	ldr r1, [r4]
	ldr r0, [r1, #0x14]
	adds r3, r3, r0
	ldrb r7, [r3]
	ldr r1, [r1, #4]
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl __divsi3
	lsls r0, r0, #0x11
	lsrs r5, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x38
	ble _080DBAB4
	movs r5, #0x38
	b _080DBABA
	.align 2, 0
_080DBAB0: .4byte 0x02039BD4
_080DBAB4:
	cmp r0, #0
	bge _080DBABA
	movs r5, #0
_080DBABA:
	ldr r2, _080DBAEC
	lsls r3, r7, #4
	adds r0, r3, r7
	lsls r0, r0, #2
	adds r4, r0, r2
	movs r0, #0x3e
	adds r0, r0, r4
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	mov r1, ip
	strb r0, [r1]
	strh r6, [r4, #0x2e]
	strh r5, [r4, #0x30]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r5, #0x24
	ldrsh r1, [r4, r5]
	cmp r0, r1
	ble _080DBAF0
	movs r0, #1
	b _080DBAF2
	.align 2, 0
_080DBAEC: .4byte 0x020205AC
_080DBAF0:
	ldr r0, _080DBB08
_080DBAF2:
	strh r0, [r4, #0x32]
	adds r0, r3, r7
	lsls r0, r0, #2
	adds r1, r2, #0
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _080DBB0C
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DBB08: .4byte 0x0000FFFF
_080DBB0C: .4byte 0x080DBB6D
	thumb_func_end sub_080DBA6C

	thumb_func_start sub_080DBB10
sub_080DBB10: @ 0x080DBB10
	push {r4, lr}
	movs r4, #0
_080DBB14:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_080DBA6C
	adds r4, #1
	cmp r4, #3
	ble _080DBB14
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_080DBB10

	thumb_func_start sub_080DBB28
sub_080DBB28: @ 0x080DBB28
	push {r4, lr}
	movs r2, #0
	ldr r3, _080DBB60
	ldr r0, [r3]
	ldr r0, [r0, #0x14]
	ldrb r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DBB56
	movs r4, #1
_080DBB3E:
	adds r2, #1
	cmp r2, #3
	bgt _080DBB56
	ldr r0, [r3]
	ldr r1, [r0, #0x14]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080DBB3E
_080DBB56:
	cmp r2, #4
	beq _080DBB64
	movs r0, #0
	b _080DBB66
	.align 2, 0
_080DBB60: .4byte 0x02039BD4
_080DBB64:
	movs r0, #1
_080DBB66:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_080DBB28

	thumb_func_start sub_080DBB6C
sub_080DBB6C: @ 0x080DBB6C
	push {r4, lr}
	adds r3, r0, #0
	ldrh r2, [r3, #0x24]
	movs r0, #0x24
	ldrsh r1, [r3, r0]
	movs r4, #0x30
	ldrsh r0, [r3, r4]
	cmp r1, r0
	bne _080DBBA4
	ldr r0, _080DBB9C
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r1, [r3, r2]
	ldr r0, [r0, #0x14]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r2, [r1, #2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #2]
	ldr r0, _080DBBA0
	str r0, [r3, #0x1c]
	b _080DBBAA
	.align 2, 0
_080DBB9C: .4byte 0x02039BD4
_080DBBA0: .4byte 0x08007141
_080DBBA4:
	ldrh r0, [r3, #0x32]
	adds r0, r2, r0
	strh r0, [r3, #0x24]
_080DBBAA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_080DBB6C

	thumb_func_start sub_080DBBB0
sub_080DBBB0: @ 0x080DBBB0
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r6, _080DBBE4
	ldr r5, _080DBBE8
	ldr r4, _080DBBEC
	ldr r3, _080DBBF0
_080DBBBC:
	ldr r0, [r5]
	ldr r1, [r0, #0x14]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r6
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, r0, r4
	ldrb r0, [r0]
	strh r0, [r1, #0x22]
	adds r2, #1
	cmp r2, #3
	ble _080DBBBC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DBBE4: .4byte 0x020205AC
_080DBBE8: .4byte 0x02039BD4
_080DBBEC: .4byte 0x085609D0
_080DBBF0: .4byte 0x02039BC6
	thumb_func_end sub_080DBBB0

	thumb_func_start sub_080DBBF4
sub_080DBBF4: @ 0x080DBBF4
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r3, #0
	ldr r7, _080DBC24
	ldr r5, _080DBC28
	ldr r4, _080DBC2C
	movs r2, #0
_080DBC04:
	adds r0, r3, r7
	ldrb r0, [r0]
	cmp r0, #1
	bls _080DBC46
	cmp r6, #0
	bne _080DBC30
	ldr r0, [r4]
	ldr r0, [r0, #0x14]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0xb4
	b _080DBC44
	.align 2, 0
_080DBC24: .4byte 0x02039BC6
_080DBC28: .4byte 0x020205AC
_080DBC2C: .4byte 0x02039BD4
_080DBC30:
	ldr r0, [r4]
	ldr r0, [r0, #0x14]
	adds r0, r2, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0x80
	lsls r1, r1, #1
_080DBC44:
	strh r1, [r0, #0x20]
_080DBC46:
	adds r2, #4
	adds r3, #1
	cmp r3, #3
	ble _080DBC04
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_080DBBF4

	thumb_func_start sub_080DBC54
sub_080DBC54: @ 0x080DBC54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080DBCD8
	bl LoadSpritePalette
	movs r5, #0
	ldr r7, _080DBCDC
	ldr r0, _080DBCE0
	mov r8, r0
	movs r6, #0
_080DBC6A:
	lsls r0, r5, #3
	ldr r1, _080DBCE4
	adds r0, r0, r1
	bl LoadCompressedSpriteSheet
	ldr r0, _080DBCE8
	adds r0, r6, r0
	ldr r2, _080DBCEC
	ldr r1, _080DBCF0
	adds r1, r5, r1
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r2, [r1]
	movs r1, #0xcc
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	ldr r1, [r1, #0x14]
	lsls r4, r5, #2
	adds r1, r4, r1
	strb r0, [r1, #1]
	ldr r0, [r7]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0, #1]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080DBCF4
	bl SetSubspriteTables
	ldr r0, [r7]
	ldr r0, [r0, #0x14]
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	adds r6, #0x18
	adds r5, #1
	cmp r5, #3
	ble _080DBC6A
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DBCD8: .4byte 0x08560A6C
_080DBCDC: .4byte 0x02039BD4
_080DBCE0: .4byte 0x020205AC
_080DBCE4: .4byte 0x08560A4C
_080DBCE8: .4byte 0x08560A7C
_080DBCEC: .4byte 0x085609D4
_080DBCF0: .4byte 0x02039BC6
_080DBCF4: .4byte 0x08560AE4
	thumb_func_end sub_080DBC54

	thumb_func_start CreateApplauseMeterSprite
CreateApplauseMeterSprite: @ 0x080DBCF8
	push {lr}
	ldr r0, _080DBD38
	bl LoadCompressedSpriteSheet
	ldr r0, _080DBD3C
	bl LoadSpritePalette
	ldr r0, _080DBD40
	movs r1, #0x1e
	movs r2, #0x2c
	movs r3, #1
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DBD44
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	adds r1, #0x3e
	ldrb r2, [r1]
	movs r3, #4
	orrs r2, r3
	strb r2, [r1]
	ldr r1, _080DBD48
	ldr r1, [r1]
	ldr r1, [r1]
	adds r1, #0x58
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080DBD38: .4byte 0x08560B14
_080DBD3C: .4byte 0x08560B1C
_080DBD40: .4byte 0x08560B2C
_080DBD44: .4byte 0x020205AC
_080DBD48: .4byte 0x02039BD4
	thumb_func_end CreateApplauseMeterSprite

	thumb_func_start sub_080DBD4C
sub_080DBD4C: @ 0x080DBD4C
	push {r4, lr}
	ldr r0, _080DBD88
	movs r1, #0x1e
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080DBD8C
	ldr r1, [r1]
	ldr r1, [r1]
	strb r0, [r1, #0xd]
	movs r2, #0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r4, _080DBD90
	movs r3, #0xff
_080DBD6E:
	lsls r0, r2, #3
	adds r0, r0, r1
	adds r0, r0, r4
	strh r3, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _080DBD6E
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DBD88: .4byte 0x080DBE8D
_080DBD8C: .4byte 0x02039BD4
_080DBD90: .4byte 0x03005B68
	thumb_func_end sub_080DBD4C

	thumb_func_start sub_080DBD94
sub_080DBD94: @ 0x080DBD94
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _080DBDD0
	ldr r1, _080DBDD4
	ldr r5, [r1]
	ldr r1, [r5]
	ldrb r2, [r1, #0xd]
	lsls r1, r2, #2
	adds r1, r1, r2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r3, #8
	adds r1, r1, r3
	movs r4, #0
	strh r4, [r1]
	lsls r0, r0, #2
	adds r0, #1
	lsls r0, r0, #1
	ldr r1, [r5]
	ldrb r2, [r1, #0xd]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r3
	strh r4, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DBDD0: .4byte 0x03005B60
_080DBDD4: .4byte 0x02039BD4
	thumb_func_end sub_080DBD94

	thumb_func_start sub_080DBDD8
sub_080DBDD8: @ 0x080DBDD8
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _080DBE00
	movs r1, #0x1f
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DBE04
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	strh r4, [r1, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DBE00: .4byte 0x080DBE09
_080DBE04: .4byte 0x03005B60
	thumb_func_end sub_080DBDD8

	thumb_func_start sub_080DBE08
sub_080DBE08: @ 0x080DBE08
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0
	ldr r2, _080DBE80
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r0, [r0, #8]
	adds r5, r0, #0
	ldr r0, _080DBE84
	ldr r4, [r0]
	ldr r0, [r4]
	ldrb r1, [r0, #0xd]
	lsls r0, r1, #2
	adds r0, r0, r1
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r7, r2, #0
	adds r7, #8
	adds r1, r0, r7
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DBE40
	cmp r0, #0xff
	bne _080DBE7A
_080DBE40:
	movs r3, #0
	movs r0, #0xff
	strh r0, [r1]
	lsls r1, r5, #2
	adds r1, #1
	lsls r1, r1, #1
	ldr r0, [r4]
	ldrb r2, [r0, #0xd]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r7
	strh r3, [r1]
	ldr r0, [r4]
	adds r0, #0x14
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, #5
	lsls r0, r0, #4
	adds r0, #6
	ldr r3, _080DBE88
	movs r1, #2
	movs r2, #0
	bl BlendPalette
	adds r0, r6, #0
	bl DestroyTask
_080DBE7A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DBE80: .4byte 0x03005B60
_080DBE84: .4byte 0x02039BD4
_080DBE88: .4byte 0x00004BFF
	thumb_func_end sub_080DBE08

	thumb_func_start sub_080DBE8C
sub_080DBE8C: @ 0x080DBE8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r6, #0
	lsls r1, r0, #2
	adds r1, r1, r0
	mov sb, r1
	lsls r7, r1, #3
	ldr r0, _080DBEDC
	mov r8, r0
	movs r1, #8
	rsbs r1, r1, #0
	add r1, r8
	mov sl, r1
_080DBEB0:
	lsls r0, r6, #0x1a
	lsrs r3, r0, #0x18
	lsls r0, r3, #1
	adds r0, r0, r7
	mov r4, r8
	adds r2, r0, r4
	ldrh r4, [r2]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0xff
	beq _080DBF2E
	adds r0, r3, #1
	lsls r1, r0, #1
	adds r1, r1, r7
	add r1, r8
	movs r5, #0
	ldrsh r1, [r1, r5]
	adds r5, r0, #0
	cmp r1, #0
	bne _080DBEE0
	adds r0, r4, #1
	b _080DBEE2
	.align 2, 0
_080DBEDC: .4byte 0x03005B68
_080DBEE0:
	subs r0, r4, #1
_080DBEE2:
	strh r0, [r2]
	lsls r1, r3, #1
	mov r0, sb
	lsls r2, r0, #3
	adds r0, r1, r2
	mov r3, sl
	adds r3, #8
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r4, r1, #0
	cmp r0, #0x10
	beq _080DBF00
	cmp r0, #0
	bne _080DBF0E
_080DBF00:
	lsls r0, r5, #1
	adds r0, r0, r2
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r2, #1
	eors r1, r2
	strh r1, [r0]
_080DBF0E:
	ldr r0, _080DBF48
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, #0x14
	adds r0, r0, r6
	ldrb r0, [r0]
	adds r0, #5
	lsls r0, r0, #4
	adds r0, #6
	adds r1, r4, r7
	add r1, r8
	ldrb r2, [r1]
	movs r1, #2
	ldr r3, _080DBF4C
	bl BlendPalette
_080DBF2E:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls _080DBEB0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DBF48: .4byte 0x02039BD4
_080DBF4C: .4byte 0x00004BFF
	thumb_func_end sub_080DBE8C

	thumb_func_start sub_080DBF50
sub_080DBF50: @ 0x080DBF50
	push {r4, lr}
	ldr r0, _080DBF78
	movs r1, #0x1e
	bl CreateTask
	ldr r1, _080DBF7C
	ldr r1, [r1]
	ldr r1, [r1]
	strb r0, [r1, #0xe]
	movs r4, #0
_080DBF64:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_080DBF80
	adds r4, #1
	cmp r4, #3
	ble _080DBF64
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DBF78: .4byte 0x080DC035
_080DBF7C: .4byte 0x02039BD4
	thumb_func_end sub_080DBF50

	thumb_func_start sub_080DBF80
sub_080DBF80: @ 0x080DBF80
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _080DBFC0
	ldr r1, _080DBFC4
	ldr r4, [r1]
	ldr r1, [r4]
	ldrb r2, [r1, #0xe]
	lsls r1, r2, #2
	adds r1, r1, r2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r3, #8
	adds r1, r1, r3
	movs r5, #0
	movs r2, #0xff
	strh r2, [r1]
	lsls r0, r0, #2
	adds r0, #1
	lsls r0, r0, #1
	ldr r1, [r4]
	ldrb r2, [r1, #0xe]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r0, r0, r3
	strh r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DBFC0: .4byte 0x03005B60
_080DBFC4: .4byte 0x02039BD4
	thumb_func_end sub_080DBF80

	thumb_func_start sub_080DBFC8
sub_080DBFC8: @ 0x080DBFC8
	push {r4, lr}
	movs r4, #0
_080DBFCC:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_080DBFE0
	adds r4, #1
	cmp r4, #3
	ble _080DBFCC
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_080DBFC8

	thumb_func_start sub_080DBFE0
sub_080DBFE0: @ 0x080DBFE0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl sub_080DBF80
	adds r0, r4, #5
	lsls r2, r0, #5
	ldr r3, _080DC024
	adds r6, r2, r3
	ldr r5, _080DC028
	adds r2, r2, r5
	ldr r1, _080DC02C
	str r6, [r1]
	str r2, [r1, #4]
	ldr r2, _080DC030
	str r2, [r1, #8]
	ldr r6, [r1, #8]
	lsls r0, r0, #4
	adds r4, #0xc
	adds r0, r0, r4
	lsls r0, r0, #1
	subs r3, #0x14
	adds r3, r0, r3
	subs r5, #0x14
	adds r0, r0, r5
	str r3, [r1]
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DC024: .4byte 0x020373C8
_080DC028: .4byte 0x020377C8
_080DC02C: .4byte 0x040000D4
_080DC030: .4byte 0x80000001
	thumb_func_end sub_080DBFE0

	thumb_func_start sub_080DC034
sub_080DC034: @ 0x080DC034
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r7, #0
	lsls r1, r0, #2
	adds r1, r1, r0
	mov sb, r1
	lsls r6, r1, #3
	ldr r0, _080DC09C
	mov r8, r0
	ldr r1, _080DC0A0
	mov sl, r1
_080DC054:
	lsls r0, r7, #0x1a
	lsrs r3, r0, #0x18
	lsls r0, r3, #1
	adds r0, r0, r6
	mov r4, r8
	adds r2, r0, r4
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r0, #0xff
	beq _080DC0FA
	adds r0, r3, #2
	lsls r0, r0, #1
	adds r0, r0, r6
	adds r1, r0, r4
	ldrh r0, [r1]
	adds r0, #1
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _080DC0FA
	strh r4, [r1]
	adds r0, r3, #1
	lsls r1, r0, #1
	adds r1, r1, r6
	add r1, r8
	movs r4, #0
	ldrsh r1, [r1, r4]
	adds r4, r0, #0
	cmp r1, #0
	bne _080DC0A4
	ldrh r0, [r2]
	adds r0, #1
	b _080DC0A8
	.align 2, 0
_080DC09C: .4byte 0x03005B68
_080DC0A0: .4byte 0x00004BFF
_080DC0A4:
	ldrh r0, [r2]
	subs r0, #1
_080DC0A8:
	strh r0, [r2]
	lsls r1, r3, #1
	mov r5, sb
	lsls r2, r5, #3
	adds r0, r1, r2
	ldr r3, _080DC114
	adds r3, #8
	adds r0, r0, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r5, r1, #0
	cmp r0, #0x10
	beq _080DC0C6
	cmp r0, #0
	bne _080DC0D4
_080DC0C6:
	lsls r0, r4, #1
	adds r0, r0, r2
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r2, #1
	eors r1, r2
	strh r1, [r0]
_080DC0D4:
	adds r4, r7, #5
	lsls r4, r4, #4
	adds r0, r4, #0
	adds r0, #0xa
	adds r5, r5, r6
	add r5, r8
	ldrb r2, [r5]
	movs r1, #1
	mov r3, sl
	bl BlendPalette
	adds r4, #0xc
	adds r4, r4, r7
	ldrb r2, [r5]
	adds r0, r4, #0
	movs r1, #1
	mov r3, sl
	bl BlendPalette
_080DC0FA:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DC054
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC114: .4byte 0x03005B60
	thumb_func_end sub_080DC034

	thumb_func_start sub_080DC118
sub_080DC118: @ 0x080DC118
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _080DC140
	ldr r0, [r0]
	ldr r1, [r0, #4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DC144
	adds r0, r2, #0
	bl sub_080DBD94
	b _080DC14A
	.align 2, 0
_080DC140: .4byte 0x02039BD4
_080DC144:
	adds r0, r2, #0
	bl sub_080DBDD8
_080DC14A:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080DC118

	thumb_func_start sub_080DC150
sub_080DC150: @ 0x080DC150
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r6, _080DC2AC
	adds r6, r0, r6
	ldrb r0, [r6]
	lsls r5, r0, #2
	adds r5, r5, r0
	lsls r5, r5, #0x1b
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r5, r5, r0
	lsrs r5, r5, #0x18
	ldr r1, [sp, #0xc]
	lsls r4, r1, #3
	ldr r0, _080DC2B0
	adds r0, r4, r0
	bl LoadCompressedSpriteSheet
	ldr r0, _080DC2B4
	adds r4, r4, r0
	adds r0, r4, #0
	bl LoadSpritePalette
	ldr r2, [sp, #0xc]
	lsls r4, r2, #1
	adds r4, r4, r2
	lsls r4, r4, #3
	ldr r0, _080DC2B8
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xb8
	adds r2, r5, #0
	movs r3, #0x1d
	bl CreateSprite
	mov sb, r0
	mov r3, sb
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	adds r0, r4, #0
	movs r1, #0xf8
	adds r2, r5, #0
	movs r3, #0x1d
	bl CreateSprite
	mov r8, r0
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r5, r0, #4
	add r5, r8
	lsls r5, r5, #2
	ldr r1, _080DC2BC
	adds r5, r5, r1
	ldrh r2, [r5, #4]
	lsls r1, r2, #0x16
	lsrs r1, r1, #0x16
	adds r1, #0x40
	ldr r3, _080DC2C0
	adds r0, r3, #0
	ands r1, r0
	ldr r0, _080DC2C4
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #4]
	movs r4, #0xc0
	lsls r4, r4, #0x13
	ldrb r0, [r6]
	lsls r3, r0, #2
	adds r3, r3, r0
	lsls r3, r3, #6
	ldr r0, _080DC2C8
	adds r3, r3, r0
	ldr r7, _080DC2CC
	ldr r0, [r7]
	ldr r0, [r0, #0x34]
	str r0, [sp]
	movs r0, #0
	movs r1, #3
	adds r2, r4, #0
	bl CopySpriteTiles
	ldrb r0, [r6]
	lsls r3, r0, #2
	adds r3, r3, r0
	lsls r3, r3, #6
	ldr r1, _080DC2D0
	adds r3, r3, r1
	ldr r0, [r7]
	ldr r0, [r0, #0x38]
	str r0, [sp]
	movs r0, #0
	movs r1, #3
	adds r2, r4, #0
	bl CopySpriteTiles
	movs r4, #0
	str r4, [sp, #4]
	ldr r0, [r7]
	ldr r1, [r0, #0x34]
	movs r6, #0xa0
	lsls r6, r6, #3
	adds r1, r1, r6
	ldr r2, _080DC2D4
	mov sl, r2
	add r0, sp, #4
	bl CpuSet
	str r4, [sp, #8]
	add r0, sp, #8
	ldr r1, [r7]
	ldr r1, [r1, #0x38]
	adds r1, r1, r6
	mov r2, sl
	bl CpuSet
	ldr r0, [r7]
	ldr r0, [r0, #0x34]
	mov r3, sb
	lsls r4, r3, #4
	add r4, sb
	lsls r4, r4, #2
	ldr r1, _080DC2BC
	adds r4, r4, r1
	ldrh r1, [r4, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	ldr r6, _080DC2D8
	adds r1, r1, r6
	movs r2, #0x80
	lsls r2, r2, #4
	mov sl, r2
	movs r3, #1
	bl RequestDma3Copy
	ldr r0, [r7]
	ldr r0, [r0, #0x38]
	ldrh r1, [r5, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	adds r1, r1, r6
	mov r2, sl
	movs r3, #1
	bl RequestDma3Copy
	mov r3, r8
	strh r3, [r4, #0x2e]
	mov r0, sb
	strh r0, [r5, #0x2e]
	mov r1, sp
	ldrh r1, [r1, #0xc]
	strh r1, [r4, #0x30]
	mov r2, sp
	ldrh r2, [r2, #0xc]
	strh r2, [r5, #0x30]
	mov r0, sb
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DC2AC: .4byte 0x02039BC6
_080DC2B0: .4byte 0x08562888
_080DC2B4: .4byte 0x085628A8
_080DC2B8: .4byte 0x08562910
_080DC2BC: .4byte 0x020205AC
_080DC2C0: .4byte 0x000003FF
_080DC2C4: .4byte 0xFFFFFC00
_080DC2C8: .4byte 0x0600E026
_080DC2CC: .4byte 0x02039BD4
_080DC2D0: .4byte 0x0600E036
_080DC2D4: .4byte 0x050000C0
_080DC2D8: .4byte 0x06010000
	thumb_func_end sub_080DC150

	thumb_func_start sub_080DC2DC
sub_080DC2DC: @ 0x080DC2DC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080DC314
	lsls r5, r0, #4
	adds r5, r5, r0
	lsls r5, r5, #2
	adds r5, r5, r1
	ldrh r0, [r5, #0x2e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	adds r4, r4, r1
	adds r0, r4, #0
	bl FreeSpriteOamMatrix
	adds r0, r4, #0
	bl DestroySprite
	adds r0, r5, #0
	bl DestroySpriteAndFreeResources
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DC314: .4byte 0x020205AC
	thumb_func_end sub_080DC2DC

	thumb_func_start sub_080DC318
sub_080DC318: @ 0x080DC318
	push {lr}
	movs r1, #0xfd
	lsls r1, r1, #6
	movs r0, #0x50
	bl SetGpuReg
	ldr r1, _080DC330
	movs r0, #0x52
	bl SetGpuReg
	pop {r0}
	bx r0
	.align 2, 0
_080DC330: .4byte 0x00000907
	thumb_func_end sub_080DC318

	thumb_func_start sub_080DC334
sub_080DC334: @ 0x080DC334
	push {lr}
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080DC334

	thumb_func_start sub_080DC34C
sub_080DC34C: @ 0x080DC34C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r0, #0
	mov sb, r1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r0, sb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	bl sub_080DC318
	ldr r0, _080DC3C4
	ldr r1, [r0]
	ldr r2, _080DC3C8
	mov r8, r2
	lsls r6, r4, #4
	adds r6, r6, r4
	lsls r6, r6, #2
	adds r0, r6, r2
	movs r3, #0x30
	ldrsh r2, [r0, r3]
	ldr r1, [r1, #0x14]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldrb r1, [r2, #2]
	movs r3, #2
	orrs r1, r3
	strb r1, [r2, #2]
	ldrh r5, [r0, #0x2e]
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	movs r1, #1
	bl StartSpriteAffineAnim
	lsls r4, r5, #4
	adds r4, r4, r5
	lsls r4, r4, #2
	mov r1, r8
	adds r0, r4, r1
	movs r1, #1
	bl StartSpriteAffineAnim
	movs r2, #0x1c
	add r8, r2
	add r6, r8
	ldr r0, _080DC3CC
	str r0, [r6]
	add r4, r8
	ldr r0, _080DC3D0
	str r0, [r4]
	mov r3, sb
	cmp r3, #0
	bne _080DC3D4
	movs r0, #0x65
	bl PlaySE
	b _080DC3DA
	.align 2, 0
_080DC3C4: .4byte 0x02039BD4
_080DC3C8: .4byte 0x020205AC
_080DC3CC: .4byte 0x080DC3E9
_080DC3D0: .4byte 0x08007141
_080DC3D4:
	movs r0, #2
	bl PlaySE
_080DC3DA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080DC34C

	thumb_func_start sub_080DC3E8
sub_080DC3E8: @ 0x080DC3E8
	push {lr}
	mov ip, r0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080DC430
	mov r0, ip
	ldrh r1, [r0, #0x2e]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _080DC434
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bge _080DC430
	mov r3, ip
	adds r3, #0x3e
	ldrb r0, [r3]
	movs r2, #4
	orrs r0, r2
	strb r0, [r3]
	adds r1, #0x3e
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldr r0, _080DC438
	mov r1, ip
	str r0, [r1, #0x1c]
_080DC430:
	pop {r0}
	bx r0
	.align 2, 0
_080DC434: .4byte 0x020205AC
_080DC438: .4byte 0x080DC43D
	thumb_func_end sub_080DC3E8

	thumb_func_start sub_080DC43C
sub_080DC43C: @ 0x080DC43C
	push {lr}
	ldr r1, _080DC468
	ldr r1, [r1]
	movs r3, #0x30
	ldrsh r2, [r0, r3]
	ldr r1, [r1, #0x14]
	lsls r2, r2, #2
	adds r2, r2, r1
	ldrb r3, [r2, #2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r1, r3
	strb r1, [r2, #2]
	ldrh r0, [r0, #0x2e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_080DC2DC
	bl sub_080DC334
	pop {r0}
	bx r0
	.align 2, 0
_080DC468: .4byte 0x02039BD4
	thumb_func_end sub_080DC43C

	thumb_func_start ContestDebugTogglePointTotal
ContestDebugTogglePointTotal: @ 0x080DC46C
	push {lr}
	ldr r0, _080DC484
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r3, r0, #0
	cmp r1, #1
	bne _080DC488
	movs r0, #0
	b _080DC48A
	.align 2, 0
_080DC484: .4byte 0x02000000
_080DC488:
	movs r0, #1
_080DC48A:
	strb r0, [r2]
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DC4A2
	bl DrawContestantWindowText
	bl SwapMoveDescAndContestTilemaps
	b _080DC4A6
_080DC4A2:
	bl ContestDebugDoPrint
_080DC4A6:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ContestDebugTogglePointTotal

	thumb_func_start ContestDebugDoPrint
ContestDebugDoPrint: @ 0x080DC4AC
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _080DC4D8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DC5A6
	ldr r0, _080DC4DC
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DC5A6
	cmp r0, #0
	blt _080DC4E0
	cmp r0, #3
	bgt _080DC4E0
	cmp r0, #2
	blt _080DC4E0
	bl ContestDebugPrintBitStrings
	b _080DC5A6
	.align 2, 0
_080DC4D8: .4byte 0x02031F75
_080DC4DC: .4byte 0x02000000
_080DC4E0:
	movs r4, #0
_080DC4E2:
	adds r0, r4, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	adds r0, r4, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl FillWindowPixelBuffer
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _080DC4E2
	movs r4, #0
_080DC502:
	ldr r0, _080DC5B0
	ldr r0, [r0]
	ldr r1, [r0, #4]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r2, sp
	ldrh r5, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080DC52C
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, sp
	ldr r1, _080DC5B4
	bl StringCopy
	adds r2, r0, #0
_080DC52C:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r2, #0
	movs r2, #0
	movs r3, #4
	bl ConvertIntToDecimalStringN
	ldr r0, _080DC5B8
	adds r0, r4, r0
	ldrb r0, [r0]
	adds r0, #4
	mov r1, sp
	bl Contest_PrintTextToBg0WindowStd
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _080DC502
	movs r4, #0
_080DC554:
	ldr r0, _080DC5B0
	ldr r0, [r0]
	ldr r1, [r0, #4]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r2, sp
	ldrh r5, [r0, #2]
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080DC57E
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, sp
	ldr r1, _080DC5B4
	bl StringCopy
	adds r2, r0, #0
_080DC57E:
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	adds r0, r2, #0
	movs r2, #0
	movs r3, #4
	bl ConvertIntToDecimalStringN
	ldr r0, _080DC5B8
	adds r0, r4, r0
	ldrb r0, [r0]
	mov r1, sp
	bl Contest_PrintTextToBg0WindowStd
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _080DC554
	bl SwapMoveDescAndContestTilemaps
_080DC5A6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DC5B0: .4byte 0x02039BD4
_080DC5B4: .4byte 0x085C9401
_080DC5B8: .4byte 0x02039BC6
	thumb_func_end ContestDebugDoPrint

	thumb_func_start SortContestants
SortContestants: @ 0x080DC5BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	add r4, sp, #4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #8
	bl memset
	movs r5, #0
	add r4, sp, #4
	adds r6, r4, #0
	movs r7, #0
_080DC5E2:
	bl Random
	adds r1, r0, #0
	mov r0, sp
	adds r0, r0, r7
	adds r0, #4
	strh r1, [r0]
	movs r2, #0
	cmp r2, r5
	bge _080DC61A
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	ldrh r1, [r1, #4]
	cmp r0, r1
	beq _080DC614
_080DC602:
	adds r2, #1
	cmp r2, r5
	bge _080DC61A
	lsls r0, r2, #1
	adds r0, r4, r0
	ldrh r1, [r6]
	ldrh r0, [r0]
	cmp r1, r0
	bne _080DC602
_080DC614:
	subs r6, #2
	subs r7, #2
	subs r5, #1
_080DC61A:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #3
	ble _080DC5E2
	mov r2, r8
	cmp r2, #0
	bne _080DC6E4
	movs r5, #0
	ldr r3, _080DC69C
	mov r8, r3
_080DC630:
	mov r6, r8
	strb r5, [r6]
	movs r4, #0
	cmp r4, r5
	bge _080DC6AC
	ldr r7, _080DC6A0
	mov sb, r7
	lsls r0, r5, #1
	adds r1, r0, #0
	add r1, sb
	mov ip, r1
	mov r2, sp
	adds r2, #4
	str r2, [sp, #0xc]
	add r0, sp
	adds r0, #4
	str r0, [sp, #0x10]
	ldr r3, _080DC69C
	adds r6, r3, #0
	mov sl, r6
_080DC658:
	ldrb r0, [r3]
	lsls r2, r0, #1
	mov r7, sb
	adds r0, r2, r7
	movs r6, #0
	ldrsh r1, [r0, r6]
	mov r7, ip
	movs r6, #0
	ldrsh r0, [r7, r6]
	cmp r1, r0
	blt _080DC680
	cmp r1, r0
	bne _080DC6A4
	ldr r7, [sp, #0xc]
	adds r0, r7, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080DC6A4
_080DC680:
	adds r2, r5, #0
	cmp r5, r4
	ble _080DC698
	subs r0, r5, #1
	mov r6, sl
	adds r1, r0, r6
_080DC68C:
	ldrb r0, [r1]
	strb r0, [r1, #1]
	subs r1, #1
	subs r2, #1
	cmp r2, r4
	bgt _080DC68C
_080DC698:
	strb r5, [r3]
	b _080DC6AC
	.align 2, 0
_080DC69C: .4byte 0x02039BC6
_080DC6A0: .4byte 0x02039BA0
_080DC6A4:
	adds r3, #1
	adds r4, #1
	cmp r4, r5
	blt _080DC658
_080DC6AC:
	cmp r4, r5
	bne _080DC6B4
	mov r7, r8
	strb r5, [r7]
_080DC6B4:
	movs r0, #1
	add r8, r0
	adds r5, #1
	cmp r5, #3
	ble _080DC630
	ldr r4, _080DC6E0
	mov r0, sp
	adds r1, r4, #0
	movs r2, #4
	bl memcpy
	movs r5, #0
_080DC6CC:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	adds r0, r0, r4
	strb r5, [r0]
	adds r5, #1
	cmp r5, #3
	ble _080DC6CC
	b _080DC798
	.align 2, 0
_080DC6E0: .4byte 0x02039BC6
_080DC6E4:
	mov r0, sp
	movs r1, #0xff
	movs r2, #4
	bl memset
	movs r5, #0
	ldr r3, _080DC708
	movs r6, #0
_080DC6F4:
	ldr r0, _080DC70C
	ldr r0, [r0]
	ldr r0, [r0, #4]
	adds r0, r6, r0
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x1e
	lsrs r2, r0, #0x1e
	mov r7, sp
	adds r1, r7, r2
	b _080DC71A
	.align 2, 0
_080DC708: .4byte 0x02039BC6
_080DC70C: .4byte 0x02039BD4
_080DC710:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	mov r0, sp
	adds r1, r0, r2
_080DC71A:
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080DC710
	strb r5, [r1]
	strb r2, [r3]
	adds r3, #1
	adds r6, #0x1c
	adds r5, #1
	cmp r5, #3
	ble _080DC6F4
	movs r5, #0
_080DC730:
	movs r4, #3
	adds r1, r5, #1
	mov sl, r1
	cmp r4, r5
	ble _080DC792
	mov sb, r4
	ldr r2, _080DC7A8
	mov r8, r2
	add r3, sp, #4
	mov ip, r3
_080DC744:
	ldr r6, _080DC7AC
	ldr r0, [r6]
	ldr r1, [r0, #4]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	adds r1, r0, #0
	subs r1, #0x1c
	ldrb r2, [r1, #0xb]
	ldrb r3, [r0, #0xb]
	mov r1, sb
	ands r1, r2
	mov r0, sb
	ands r0, r3
	subs r3, r4, #1
	cmp r1, r0
	bne _080DC78C
	mov r0, r8
	adds r7, r3, r0
	adds r2, r4, r0
	ldrb r6, [r7]
	ldrb r1, [r2]
	cmp r6, r1
	bhs _080DC78C
	lsls r0, r3, #1
	add r0, ip
	lsls r1, r4, #1
	add r1, ip
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080DC78C
	ldrb r0, [r2]
	strb r6, [r2]
	strb r0, [r7]
_080DC78C:
	adds r4, r3, #0
	cmp r4, r5
	bgt _080DC744
_080DC792:
	mov r5, sl
	cmp r5, #2
	ble _080DC730
_080DC798:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC7A8: .4byte 0x02039BC6
_080DC7AC: .4byte 0x02039BD4
	thumb_func_end SortContestants

	thumb_func_start DrawContestantWindows
DrawContestantWindows: @ 0x080DC7B0
	push {r4, r5, lr}
	movs r4, #0
	movs r5, #0xa0
_080DC7B6:
	ldr r0, _080DC7DC
	adds r0, r5, r0
	ldr r1, _080DC7E0
	adds r1, r4, r1
	ldrb r1, [r1]
	adds r1, #5
	lsls r1, r1, #4
	movs r2, #0x20
	bl LoadPalette
	adds r5, #0x20
	adds r4, #1
	cmp r4, #3
	ble _080DC7B6
	bl DrawContestantWindowText
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DC7DC: .4byte 0x0201A004
_080DC7E0: .4byte 0x02039BC6
	thumb_func_end DrawContestantWindows

	thumb_func_start sub_080DC7E4
sub_080DC7E4: @ 0x080DC7E4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r4, _080DC86C
	ldr r3, [r4]
	ldr r1, [r3, #4]
	lsls r7, r6, #3
	subs r0, r7, r6
	lsls r5, r0, #2
	adds r1, r5, r1
	movs r2, #0
	strh r2, [r1, #2]
	ldr r0, [r3, #4]
	adds r0, r5, r0
	strh r2, [r0]
	adds r0, r6, #0
	bl ContestantCanUseTurn
	lsls r0, r0, #0x18
	mov r8, r4
	cmp r0, #0
	bne _080DC818
	b _080DCB28
_080DC818:
	ldr r0, [r4]
	ldr r1, [r0, #4]
	adds r1, r5, r1
	ldrh r0, [r1, #6]
	ldr r2, _080DC870
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r2, [r0]
	mov sb, r2
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x1d
	strb r0, [r1, #0xa]
	ldr r0, [r4]
	ldr r0, [r0, #4]
	adds r2, r5, r0
	ldrh r0, [r2, #6]
	ldrh r1, [r2, #8]
	cmp r0, r1
	bne _080DC874
	cmp r0, #0
	beq _080DC874
	ldrb r0, [r2, #0x15]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #0x15]
	ldr r0, [r4]
	ldr r2, [r0, #4]
	adds r2, r5, r2
	ldrb r3, [r2, #0xb]
	lsls r1, r3, #0x19
	lsrs r1, r1, #0x1d
	adds r1, #1
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #4
	movs r0, #0x71
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #0xb]
	b _080DC890
	.align 2, 0
_080DC86C: .4byte 0x02039BD4
_080DC870: .4byte 0x08565FCC
_080DC874:
	ldr r4, _080DC944
	ldr r0, [r4]
	ldr r0, [r0, #4]
	lsls r3, r6, #3
	subs r1, r3, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r2, [r1, #0xb]
	movs r0, #0x71
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #0xb]
	mov r8, r4
	adds r7, r3, #0
_080DC890:
	mov r2, r8
	ldr r4, [r2]
	ldr r2, [r4, #4]
	subs r0, r7, r6
	lsls r0, r0, #2
	adds r2, r0, r2
	ldr r3, _080DC948
	mov r1, sb
	lsls r5, r1, #2
	adds r3, r5, r3
	ldrb r1, [r3, #1]
	strh r1, [r2]
	ldr r1, [r4, #4]
	adds r0, r0, r1
	ldrh r1, [r0]
	strh r1, [r0, #2]
	ldr r1, [r4, #8]
	ldrb r0, [r3, #2]
	strh r0, [r1, #4]
	ldr r1, [r4, #8]
	ldrh r0, [r1, #4]
	strh r0, [r1, #6]
	ldr r0, [r4, #8]
	strb r6, [r0, #0x11]
	movs r2, #0
	mov sb, r5
	mov r4, r8
	movs r3, #0
	movs r1, #0
_080DC8CA:
	ldr r0, [r4]
	ldr r0, [r0, #4]
	adds r0, r1, r0
	strb r3, [r0, #0xe]
	ldr r0, [r4]
	ldr r0, [r0, #8]
	adds r0, #0xd
	adds r0, r0, r2
	strb r3, [r0]
	adds r1, #0x1c
	adds r2, #1
	cmp r2, #3
	ble _080DC8CA
	ldr r5, _080DC944
	ldr r0, [r5]
	ldr r1, [r0, #4]
	subs r0, r7, r6
	lsls r4, r0, #2
	adds r2, r4, r1
	ldrb r1, [r2, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DC918
	ldrh r0, [r2, #8]
	ldrh r1, [r2, #6]
	bl AreMovesContestCombo
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DC918
	ldr r0, [r5]
	ldr r1, [r0, #4]
	adds r1, r4, r1
	ldrb r2, [r1, #0x15]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #0x15]
_080DC918:
	ldr r0, _080DC94C
	add r0, sb
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _080DC944
	ldr r0, [r0]
	ldr r1, [r0, #4]
	subs r0, r7, r6
	lsls r0, r0, #2
	adds r2, r0, r1
	ldrb r1, [r2, #0x10]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0x10
	bne _080DC950
	ldrh r1, [r2, #2]
	subs r1, #0xa
	movs r0, #0xd
	ldrsb r0, [r2, r0]
	b _080DC96A
	.align 2, 0
_080DC944: .4byte 0x02039BD4
_080DC948: .4byte 0x08566AE4
_080DC94C: .4byte 0x08566BE4
_080DC950:
	ldrb r1, [r2, #0x11]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080DC964
	movs r1, #0xd
	ldrsb r1, [r2, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	b _080DC968
_080DC964:
	movs r0, #0xd
	ldrsb r0, [r2, r0]
_080DC968:
	ldrh r1, [r2, #2]
_080DC96A:
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldr r5, _080DC9FC
	ldr r0, [r5]
	ldr r1, [r0, #4]
	subs r0, r7, r6
	lsls r4, r0, #2
	adds r1, r4, r1
	movs r0, #0
	strb r0, [r1, #0x16]
	ldr r0, [r5]
	ldr r1, [r0, #4]
	adds r1, r4, r1
	ldrb r2, [r1, #0x15]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #0x15]
	adds r0, r6, #0
	bl sub_080DD94C
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080DCA46
	ldr r0, [r5]
	ldr r1, [r0, #4]
	adds r1, r4, r1
	ldrh r0, [r1, #8]
	ldrh r1, [r1, #6]
	bl AreMovesContestCombo
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080DCA00
	ldr r0, [r5]
	ldr r0, [r0, #4]
	adds r2, r4, r0
	ldrb r1, [r2, #0x15]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DCA00
	strb r3, [r2, #0x16]
	ldr r0, [r5]
	ldr r1, [r0, #4]
	adds r1, r4, r1
	ldrb r0, [r1, #0x15]
	movs r2, #0x40
	orrs r0, r2
	strb r0, [r1, #0x15]
	ldr r0, [r5]
	ldr r1, [r0, #4]
	adds r1, r4, r1
	ldrb r2, [r1, #0x15]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #0x15]
	ldr r0, [r5]
	ldr r0, [r0, #4]
	adds r0, r4, r0
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldrb r1, [r0, #0x16]
	muls r1, r2, r1
	strb r1, [r0, #0x17]
	ldr r0, [r5]
	ldr r1, [r0, #4]
	adds r1, r4, r1
	ldrb r0, [r1, #0x15]
	movs r2, #8
	b _080DCA2C
	.align 2, 0
_080DC9FC: .4byte 0x02039BD4
_080DCA00:
	ldr r2, _080DCA34
	ldr r5, _080DCA38
	ldr r0, [r5]
	ldr r1, [r0, #4]
	subs r0, r7, r6
	lsls r4, r0, #2
	adds r3, r4, r1
	ldrh r0, [r3, #6]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _080DCA3C
	ldrb r0, [r3, #0x15]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r3, #0x15]
	ldr r0, [r5]
	ldr r1, [r0, #4]
	adds r1, r4, r1
	ldrb r0, [r1, #0x15]
	movs r2, #0x40
_080DCA2C:
	orrs r0, r2
	strb r0, [r1, #0x15]
	b _080DCA46
	.align 2, 0
_080DCA34: .4byte 0x08565FCC
_080DCA38: .4byte 0x02039BD4
_080DCA3C:
	ldrb r1, [r3, #0x15]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3, #0x15]
_080DCA46:
	ldr r5, _080DCAE4
	ldr r0, [r5]
	ldr r1, [r0, #4]
	subs r0, r7, r6
	lsls r4, r0, #2
	adds r2, r4, r1
	ldrb r1, [r2, #0x15]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq _080DCA6E
	ldrb r0, [r2, #0xb]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1d
	adds r0, #1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	strb r1, [r2, #0x18]
_080DCA6E:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	adds r2, r4, r0
	ldrb r1, [r2, #0xc]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _080DCA98
	ldrb r1, [r2, #0x15]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #0x15]
	ldr r2, [r5]
	ldr r0, [r2, #4]
	adds r0, r4, r0
	movs r1, #0
	strh r1, [r0, #2]
	ldr r0, [r2, #4]
	adds r0, r4, r0
	strh r1, [r0]
_080DCA98:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	adds r0, r4, r0
	ldrh r0, [r0, #6]
	bl Contest_GetMoveExcitement
	ldr r1, [r5]
	ldr r1, [r1, #0x10]
	strb r0, [r1]
	ldr r2, [r5]
	ldr r0, [r2, #4]
	adds r0, r4, r0
	ldrb r1, [r0, #0x11]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DCAC0
	ldr r0, [r2, #0x10]
	mov r1, r8
	strb r1, [r0]
_080DCAC0:
	ldr r1, [r5]
	ldr r3, [r1, #0x10]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	ble _080DCAEC
	ldr r0, [r1]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r3, r1]
	adds r0, r0, r1
	cmp r0, #4
	ble _080DCAE8
	movs r0, #0x3c
	b _080DCAEE
	.align 2, 0
_080DCAE4: .4byte 0x02039BD4
_080DCAE8:
	movs r0, #0xa
	b _080DCAEE
_080DCAEC:
	movs r0, #0
_080DCAEE:
	strb r0, [r3, #2]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	b _080DCB12
_080DCB06:
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080DCB0C:
	adds r2, #1
	cmp r2, #3
	bgt _080DCB1A
_080DCB12:
	cmp r2, r6
	beq _080DCB0C
	cmp r0, #0
	bne _080DCB06
_080DCB1A:
	ldr r0, _080DCB34
	ldr r0, [r0]
	ldr r1, [r0, #4]
	subs r0, r7, r6
	lsls r0, r0, #2
	adds r0, r0, r1
	strb r2, [r0, #0x1b]
_080DCB28:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DCB34: .4byte 0x02039BD4
	thumb_func_end sub_080DC7E4

	thumb_func_start SetContestantEffectStringID
SetContestantEffectStringID: @ 0x080DCB38
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DCB50
	ldr r2, [r2]
	ldr r3, [r2, #4]
	lsls r2, r0, #3
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r3
	strb r1, [r2, #0x13]
	bx lr
	.align 2, 0
_080DCB50: .4byte 0x02039BD4
	thumb_func_end SetContestantEffectStringID

	thumb_func_start SetContestantEffectStringID2
SetContestantEffectStringID2: @ 0x080DCB54
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DCB6C
	ldr r2, [r2]
	ldr r3, [r2, #4]
	lsls r2, r0, #3
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r3
	strb r1, [r2, #0x14]
	bx lr
	.align 2, 0
_080DCB6C: .4byte 0x02039BD4
	thumb_func_end SetContestantEffectStringID2

	thumb_func_start SetStartledString
SetStartledString: @ 0x080DCB70
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r2, r1, #0
	cmp r1, #0x3b
	bls _080DCB8A
	movs r1, #0x35
	bl SetContestantEffectStringID
	b _080DCBBA
_080DCB8A:
	cmp r1, #0x27
	bls _080DCB96
	movs r1, #0x34
	bl SetContestantEffectStringID
	b _080DCBBA
_080DCB96:
	cmp r1, #0x1d
	bls _080DCBA2
	movs r1, #0x33
	bl SetContestantEffectStringID
	b _080DCBBA
_080DCBA2:
	cmp r1, #0x13
	bls _080DCBAE
	movs r1, #0x32
	bl SetContestantEffectStringID
	b _080DCBBA
_080DCBAE:
	cmp r2, #9
	bls _080DCBBA
	adds r0, r3, #0
	movs r1, #0x31
	bl SetContestantEffectStringID
_080DCBBA:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SetStartledString

	thumb_func_start sub_080DCBC0
sub_080DCBC0: @ 0x080DCBC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _080DCC20
	lsls r1, r4, #6
	ldr r2, _080DCC24
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _080DCC28
	ldr r5, _080DCC2C
	ldr r1, [r5]
	ldr r2, [r1, #4]
	lsls r1, r4, #3
	subs r1, r1, r4
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1, #6]
	lsls r1, r1, #3
	ldr r2, _080DCC30
	adds r1, r1, r2
	bl StringCopy
	ldr r3, _080DCC34
	ldr r1, [r5]
	ldr r0, [r1, #8]
	ldrb r2, [r0, #0x11]
	ldr r1, [r1, #4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #6]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrb r0, [r0, #1]
	lsls r1, r0, #0x1d
	cmp r1, #0
	bne _080DCC40
	ldr r0, _080DCC38
	ldr r1, _080DCC3C
	bl StringCopy
	b _080DCC90
	.align 2, 0
_080DCC20: .4byte 0x02021C40
_080DCC24: .4byte 0x02039AA2
_080DCC28: .4byte 0x02021C54
_080DCC2C: .4byte 0x02039BD4
_080DCC30: .4byte 0x082EACC4
_080DCC34: .4byte 0x08565FCC
_080DCC38: .4byte 0x02021C68
_080DCC3C: .4byte 0x0824C0D2
_080DCC40:
	lsrs r0, r1, #0x1d
	cmp r0, #1
	bne _080DCC58
	ldr r0, _080DCC50
	ldr r1, _080DCC54
	bl StringCopy
	b _080DCC90
	.align 2, 0
_080DCC50: .4byte 0x02021C68
_080DCC54: .4byte 0x0824C0D7
_080DCC58:
	lsrs r0, r1, #0x1d
	cmp r0, #2
	bne _080DCC70
	ldr r0, _080DCC68
	ldr r1, _080DCC6C
	bl StringCopy
	b _080DCC90
	.align 2, 0
_080DCC68: .4byte 0x02021C68
_080DCC6C: .4byte 0x0824C0DC
_080DCC70:
	lsrs r0, r1, #0x1d
	cmp r0, #3
	bne _080DCC88
	ldr r0, _080DCC80
	ldr r1, _080DCC84
	bl StringCopy
	b _080DCC90
	.align 2, 0
_080DCC80: .4byte 0x02021C68
_080DCC84: .4byte 0x0824C0E1
_080DCC88:
	ldr r0, _080DCCB4
	ldr r1, _080DCCB8
	bl StringCopy
_080DCC90:
	ldr r4, _080DCCBC
	ldr r1, _080DCCC0
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl StringExpandPlaceholders
	bl sub_080DB000
	adds r0, r4, #0
	movs r1, #1
	bl Contest_StartTextPrinter
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DCCB4: .4byte 0x02021C68
_080DCCB8: .4byte 0x0824C0E6
_080DCCBC: .4byte 0x02021C7C
_080DCCC0: .4byte 0x08560D74
	thumb_func_end sub_080DCBC0

	thumb_func_start MakeContestantNervous
MakeContestantNervous: @ 0x080DCCC4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _080DCCF0
	ldr r1, [r4]
	ldr r3, [r1, #4]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r3, r1, r3
	ldrb r0, [r3, #0xc]
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0xc]
	ldr r0, [r4]
	ldr r0, [r0, #4]
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1, #6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DCCF0: .4byte 0x02039BD4
	thumb_func_end MakeContestantNervous

	thumb_func_start ApplyNextTurnOrder
ApplyNextTurnOrder: @ 0x080DCCF4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r0, #0
	mov ip, r0
	movs r4, #0
	ldr r1, _080DCD60
	mov sb, r1
	add r2, sp, #4
	mov r6, sb
	movs r5, #0
	adds r3, r2, #0
_080DCD10:
	mov r0, sp
	adds r1, r0, r4
	adds r0, r4, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r4
	strb r5, [r0]
	adds r4, #1
	cmp r4, #3
	ble _080DCD10
	movs r4, #0
	ldr r7, _080DCD64
	ldr r1, [r7]
	mov r8, r1
	adds r5, r2, #0
_080DCD2E:
	movs r2, #0
	mov r0, r8
	ldr r1, [r0, #4]
_080DCD34:
	ldrb r0, [r1, #0x19]
	cmp r0, r4
	beq _080DCD68
	adds r1, #0x1c
	adds r2, #1
	cmp r2, #3
	ble _080DCD34
_080DCD42:
	cmp r2, #4
	bne _080DCDE8
	movs r2, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080DCD76
	ldr r0, [r7]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x19]
	cmp r0, #0xff
	bne _080DCD76
	mov ip, r2
	movs r2, #1
	b _080DCD9E
	.align 2, 0
_080DCD60: .4byte 0x02039BC6
_080DCD64: .4byte 0x02039BD4
_080DCD68:
	mov r1, sp
	adds r0, r1, r2
	strb r4, [r0]
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080DCD42
_080DCD76:
	adds r2, #1
	cmp r2, #3
	bgt _080DCDDA
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DCD76
	ldr r0, [r7]
	ldr r1, [r0, #4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #0x19]
	cmp r0, #0xff
	bne _080DCD76
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	adds r2, #1
_080DCD9E:
	cmp r2, #3
	bgt _080DCDDA
	ldr r6, _080DCE38
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r3, r0, #2
_080DCDAA:
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DCDD2
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r3, r0
	ldrb r0, [r0, #0x19]
	cmp r0, #0xff
	bne _080DCDD2
	mov r1, ip
	adds r0, r1, r6
	adds r1, r2, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080DCDD2
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
_080DCDD2:
	adds r3, #0x1c
	adds r2, #1
	cmp r2, #3
	ble _080DCDAA
_080DCDDA:
	mov r0, sp
	add r0, ip
	strb r4, [r0]
	mov r0, ip
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080DCDE8:
	adds r4, #1
	cmp r4, #3
	ble _080DCD2E
	movs r4, #0
	ldr r6, _080DCE3C
	movs r5, #0
_080DCDF4:
	ldr r0, [r6]
	ldr r1, [r0, #8]
	adds r1, r1, r4
	mov r0, sp
	adds r3, r0, r4
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r0, [r6]
	ldr r0, [r0, #4]
	adds r0, r5, r0
	movs r1, #0xff
	strb r1, [r0, #0x19]
	ldr r0, [r6]
	ldr r1, [r0, #4]
	adds r1, r5, r1
	ldrb r2, [r1, #0x10]
	movs r0, #0x3f
	ands r0, r2
	strb r0, [r1, #0x10]
	mov r0, sb
	adds r1, r4, r0
	ldrb r0, [r3]
	strb r0, [r1]
	adds r5, #0x1c
	adds r4, #1
	cmp r4, #3
	ble _080DCDF4
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DCE38: .4byte 0x02039BC6
_080DCE3C: .4byte 0x02039BD4
	thumb_func_end ApplyNextTurnOrder

	thumb_func_start sub_080DCE40
sub_080DCE40: @ 0x080DCE40
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x30]
	adds r1, r0, #1
	strh r1, [r2, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x54
	ble _080DCE76
	movs r0, #0
	strh r0, [r2, #0x30]
	adds r3, r2, #0
	adds r3, #0x3e
	ldrb r0, [r3]
	movs r1, #4
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _080DCE7C
	str r0, [r2, #0x1c]
	ldr r0, _080DCE80
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #6]
_080DCE76:
	pop {r0}
	bx r0
	.align 2, 0
_080DCE7C: .4byte 0x08007141
_080DCE80: .4byte 0x02039BD4
	thumb_func_end sub_080DCE40

	thumb_func_start sub_080DCE84
sub_080DCE84: @ 0x080DCE84
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, _080DCEA4
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r5, [r0, #0x12]
	cmp r1, #8
	bls _080DCE98
	b _080DD038
_080DCE98:
	lsls r0, r1, #2
	ldr r1, _080DCEA8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DCEA4: .4byte 0x02039BD4
_080DCEA8: .4byte 0x080DCEAC
_080DCEAC: @ jump table
	.4byte _080DCED0 @ case 0
	.4byte _080DCED0 @ case 1
	.4byte _080DCF00 @ case 2
	.4byte _080DCF34 @ case 3
	.4byte _080DCF68 @ case 4
	.4byte _080DCF9C @ case 5
	.4byte _080DCFD0 @ case 6
	.4byte _080DD038 @ case 7
	.4byte _080DD004 @ case 8
_080DCED0:
	ldr r0, _080DCEF4
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #0x2e]
	ldr r2, _080DCEF8
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCEFC
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x20
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCEF4: .4byte 0x020205AC
_080DCEF8: .4byte 0x000003FF
_080DCEFC: .4byte 0xFFFFFC00
_080DCF00:
	ldr r0, _080DCF28
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #4
	ldr r3, _080DCF2C
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCF30
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x1f
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCF28: .4byte 0x020205AC
_080DCF2C: .4byte 0x000003FF
_080DCF30: .4byte 0xFFFFFC00
_080DCF34:
	ldr r0, _080DCF5C
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #8
	ldr r3, _080DCF60
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCF64
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x1f
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCF5C: .4byte 0x020205AC
_080DCF60: .4byte 0x000003FF
_080DCF64: .4byte 0xFFFFFC00
_080DCF68:
	ldr r0, _080DCF90
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0xc
	ldr r3, _080DCF94
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCF98
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x2d
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCF90: .4byte 0x020205AC
_080DCF94: .4byte 0x000003FF
_080DCF98: .4byte 0xFFFFFC00
_080DCF9C:
	ldr r0, _080DCFC4
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0xc
	ldr r3, _080DCFC8
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCFCC
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x2d
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCFC4: .4byte 0x020205AC
_080DCFC8: .4byte 0x000003FF
_080DCFCC: .4byte 0xFFFFFC00
_080DCFD0:
	ldr r0, _080DCFF8
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0x10
	ldr r3, _080DCFFC
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DD000
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x2d
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCFF8: .4byte 0x020205AC
_080DCFFC: .4byte 0x000003FF
_080DD000: .4byte 0xFFFFFC00
_080DD004:
	ldr r0, _080DD02C
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0x18
	ldr r3, _080DD030
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DD034
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0xc3
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DD02C: .4byte 0x020205AC
_080DD030: .4byte 0x000003FF
_080DD034: .4byte 0xFFFFFC00
_080DD038:
	ldr r0, _080DD090
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0x14
	ldr r3, _080DD094
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DD098
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x2d
	bl PlaySE
_080DD05C:
	adds r2, r4, #0
	ldr r4, _080DD090
	adds r2, r2, r5
	lsls r2, r2, #2
	adds r1, r2, r4
	movs r0, #0
	strh r0, [r1, #0x30]
	adds r1, #0x3e
	ldrb r3, [r1]
	subs r0, #5
	ands r0, r3
	strb r0, [r1]
	adds r4, #0x1c
	adds r2, r2, r4
	ldr r0, _080DD09C
	str r0, [r2]
	ldr r0, _080DD0A0
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #6]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD090: .4byte 0x020205AC
_080DD094: .4byte 0x000003FF
_080DD098: .4byte 0xFFFFFC00
_080DD09C: .4byte 0x080DCE41
_080DD0A0: .4byte 0x02039BD4
	thumb_func_end sub_080DCE84

	thumb_func_start UpdateApplauseMeter
UpdateApplauseMeter: @ 0x080DD0A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r5, #0
	ldr r6, _080DD140
	ldr r0, _080DD144
	mov sb, r0
	ldr r0, _080DD148
	mov r8, r0
	ldr r7, _080DD14C
_080DD0BA:
	ldr r0, [r6]
	ldr r1, [r0]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	ldr r4, _080DD150
	cmp r5, r0
	bge _080DD0CA
	adds r4, #0x40
_080DD0CA:
	adds r0, r1, #0
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sb
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	adds r0, r5, #0
	adds r0, #0x11
	adds r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	adds r2, r7, #0
	bl CpuSet
	adds r0, r4, #0
	adds r0, #0x20
	ldr r1, [r6]
	ldr r1, [r1]
	adds r1, #0x58
	ldrb r2, [r1]
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	add r1, sb
	ldrh r1, [r1, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	adds r2, r5, #0
	adds r2, #0x19
	adds r1, r1, r2
	lsls r1, r1, #5
	add r1, r8
	adds r2, r7, #0
	bl CpuSet
	ldr r0, [r6]
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _080DD12C
	bl StartApplauseOverflowAnimation
_080DD12C:
	adds r5, #1
	cmp r5, #4
	ble _080DD0BA
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD140: .4byte 0x02039BD4
_080DD144: .4byte 0x020205AC
_080DD148: .4byte 0x06010000
_080DD14C: .4byte 0x04000008
_080DD150: .4byte 0x08D8EBD8
	thumb_func_end UpdateApplauseMeter

	thumb_func_start Contest_GetMoveExcitement
Contest_GetMoveExcitement: @ 0x080DD154
	lsls r0, r0, #0x10
	ldr r3, _080DD178
	ldr r1, _080DD17C
	lsrs r0, r0, #0xd
	adds r0, r0, r1
	ldrb r1, [r0, #1]
	lsls r1, r1, #0x1d
	lsrs r1, r1, #0x1d
	ldr r0, _080DD180
	ldrh r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r1, r1, r0
	adds r1, r1, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	bx lr
	.align 2, 0
_080DD178: .4byte 0x08562970
_080DD17C: .4byte 0x08565FCC
_080DD180: .4byte 0x02039BCC
	thumb_func_end Contest_GetMoveExcitement

	thumb_func_start StartApplauseOverflowAnimation
StartApplauseOverflowAnimation: @ 0x080DD184
	push {r4, r5, lr}
	ldr r0, _080DD1B8
	movs r1, #0xa
	bl CreateTask
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _080DD1BC
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	adds r4, r4, r0
	movs r0, #1
	strh r0, [r4, #0xa]
	ldr r0, _080DD1C0
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0xc]
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1B8: .4byte 0x080DD1C5
_080DD1BC: .4byte 0x03005B60
_080DD1C0: .4byte 0x0000ABE2
	thumb_func_end StartApplauseOverflowAnimation

	thumb_func_start Task_ApplauseOverflowAnimation
Task_ApplauseOverflowAnimation: @ 0x080DD1C4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _080DD1F4
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r2, r0, r1
	ldrh r0, [r2, #8]
	adds r0, #1
	strh r0, [r2, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _080DD262
	movs r0, #0
	strh r0, [r2, #8]
	movs r3, #0xe
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _080DD1F8
	ldrh r0, [r2, #0x10]
	adds r0, #1
	b _080DD1FC
	.align 2, 0
_080DD1F4: .4byte 0x03005B60
_080DD1F8:
	ldrh r0, [r2, #0x10]
	subs r0, #1
_080DD1FC:
	strh r0, [r2, #0x10]
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	movs r3, #0x84
	lsls r3, r3, #1
	adds r6, r3, #0
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r2, [r4, #0x10]
	ldr r3, _080DD268
	movs r1, #1
	bl BlendPalette
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _080DD22E
	cmp r0, #0x10
	bne _080DD262
_080DD22E:
	ldrh r0, [r4, #0xe]
	movs r1, #1
	eors r0, r1
	strh r0, [r4, #0xe]
	ldr r0, _080DD26C
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _080DD262
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	lsls r0, r0, #4
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	movs r2, #0
	movs r3, #0x1f
	bl BlendPalette
	adds r0, r5, #0
	bl DestroyTask
_080DD262:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DD268: .4byte 0x00007FFF
_080DD26C: .4byte 0x02039BD4
	thumb_func_end Task_ApplauseOverflowAnimation

	thumb_func_start StartMoveApplauseMeterOnscreen
StartMoveApplauseMeterOnscreen: @ 0x080DD270
	push {r4, lr}
	ldr r0, _080DD2C0
	movs r1, #0xa
	bl CreateTask
	ldr r3, _080DD2C4
	ldr r4, _080DD2C8
	ldr r2, [r4]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, _080DD2CC
	strh r1, [r0, #0x24]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r0, [r2, #6]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DD2C0: .4byte 0x080DD2D1
_080DD2C4: .4byte 0x020205AC
_080DD2C8: .4byte 0x02039BD4
_080DD2CC: .4byte 0x0000FFBA
	thumb_func_end StartMoveApplauseMeterOnscreen

	thumb_func_start Task_MoveApplauseMeterOnscreen
Task_MoveApplauseMeterOnscreen: @ 0x080DD2D0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	ldr r4, _080DD340
	ldr r0, [r4]
	ldr r0, [r0]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DD344
	adds r2, r0, r1
	ldr r0, _080DD348
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r5, #0xd0
	lsls r5, r5, #3
	adds r0, r5, #0
	ldrh r5, [r1, #0x1c]
	adds r0, r0, r5
	strh r0, [r1, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r5, [r2, #0x24]
	adds r0, r0, r5
	strh r0, [r2, #0x24]
	ldrb r0, [r1, #0x1c]
	strh r0, [r1, #0x1c]
	movs r1, #0x24
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _080DD31C
	movs r0, #0
	strh r0, [r2, #0x24]
_080DD31C:
	movs r5, #0x24
	ldrsh r0, [r2, r5]
	cmp r0, #0
	bne _080DD338
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #6]
	adds r0, r3, #0
	bl DestroyTask
_080DD338:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD340: .4byte 0x02039BD4
_080DD344: .4byte 0x020205AC
_080DD348: .4byte 0x03005B60
	thumb_func_end Task_MoveApplauseMeterOnscreen

	thumb_func_start TryMoveApplauseMeterOffscreen
TryMoveApplauseMeterOffscreen: @ 0x080DD34C
	push {r4, r5, lr}
	ldr r5, _080DD378
	ldr r4, _080DD37C
	ldr r0, [r4]
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x3e
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _080DD380
	ldrb r1, [r2, #6]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	b _080DD3A4
	.align 2, 0
_080DD378: .4byte 0x020205AC
_080DD37C: .4byte 0x02039BD4
_080DD380:
	ldr r0, _080DD3AC
	movs r1, #0xa
	bl CreateTask
	ldr r2, [r4]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0, #0x24]
	ldr r2, [r2]
	ldrb r0, [r2, #6]
	movs r1, #0x40
	orrs r0, r1
_080DD3A4:
	strb r0, [r2, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD3AC: .4byte 0x080DD3B1
	thumb_func_end TryMoveApplauseMeterOffscreen

	thumb_func_start Task_MoveApplauseMeterOffscreen
Task_MoveApplauseMeterOffscreen: @ 0x080DD3B0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	ldr r5, _080DD430
	ldr r0, [r5]
	ldr r0, [r0]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DD434
	adds r3, r0, r1
	ldr r0, _080DD438
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #3
	adds r2, r2, r0
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r1, #0
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r1, [r3, #0x24]
	subs r1, r1, r0
	strh r1, [r3, #0x24]
	ldrb r0, [r2, #0x1c]
	strh r0, [r2, #0x1c]
	movs r2, #0x24
	ldrsh r0, [r3, r2]
	movs r1, #0x46
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080DD400
	ldr r0, _080DD43C
	strh r0, [r3, #0x24]
_080DD400:
	movs r2, #0x24
	ldrsh r0, [r3, r2]
	cmp r0, r1
	bne _080DD428
	adds r2, r3, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #6]
	adds r0, r4, #0
	bl DestroyTask
_080DD428:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD430: .4byte 0x02039BD4
_080DD434: .4byte 0x020205AC
_080DD438: .4byte 0x03005B60
_080DD43C: .4byte 0x0000FFBA
	thumb_func_end Task_MoveApplauseMeterOffscreen

	thumb_func_start ShowAndUpdateApplauseMeter
ShowAndUpdateApplauseMeter: @ 0x080DD440
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _080DD478
	movs r1, #5
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DD47C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	strh r4, [r1, #8]
	ldr r0, _080DD480
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #6]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2, #6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DD478: .4byte 0x080DD485
_080DD47C: .4byte 0x03005B60
_080DD480: .4byte 0x02039BD4
	thumb_func_end ShowAndUpdateApplauseMeter

	thumb_func_start Task_ShowAndUpdateApplauseMeter
Task_ShowAndUpdateApplauseMeter: @ 0x080DD484
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _080DD4A8
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _080DD4B8
	cmp r0, #1
	bgt _080DD4AC
	cmp r0, #0
	beq _080DD4B2
	b _080DD500
	.align 2, 0
_080DD4A8: .4byte 0x03005B60
_080DD4AC:
	cmp r0, #2
	beq _080DD4D4
	b _080DD500
_080DD4B2:
	bl StartMoveApplauseMeterOnscreen
	b _080DD4C8
_080DD4B8:
	ldr r0, _080DD4D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, #6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _080DD500
_080DD4C8:
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
	b _080DD500
	.align 2, 0
_080DD4D0: .4byte 0x02039BD4
_080DD4D4:
	ldrh r0, [r4, #0x1e]
	adds r1, r0, #1
	strh r1, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _080DD500
	movs r0, #0
	strh r0, [r4, #0x1e]
	bl UpdateApplauseMeter
	ldr r0, _080DD508
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #6]
	adds r0, r5, #0
	bl DestroyTask
_080DD500:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD508: .4byte 0x02039BD4
	thumb_func_end Task_ShowAndUpdateApplauseMeter

	thumb_func_start HideApplauseMeterNoAnim
HideApplauseMeterNoAnim: @ 0x080DD50C
	ldr r3, _080DD540
	ldr r0, _080DD544
	ldr r2, [r0]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #0
	strh r1, [r0, #0x24]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080DD540: .4byte 0x020205AC
_080DD544: .4byte 0x02039BD4
	thumb_func_end HideApplauseMeterNoAnim

	thumb_func_start ShowApplauseMeterNoAnim
ShowApplauseMeterNoAnim: @ 0x080DD548
	ldr r2, _080DD568
	ldr r0, _080DD56C
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080DD568: .4byte 0x020205AC
_080DD56C: .4byte 0x02039BD4
	thumb_func_end ShowApplauseMeterNoAnim

	thumb_func_start sub_080DD570
sub_080DD570: @ 0x080DD570
	push {lr}
	ldr r0, _080DD58C
	movs r1, #0xf
	bl CreateTask
	ldr r0, _080DD590
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #6]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #6]
	pop {r0}
	bx r0
	.align 2, 0
_080DD58C: .4byte 0x080DD595
_080DD590: .4byte 0x02039BD4
	thumb_func_end sub_080DD570

	thumb_func_start sub_080DD594
sub_080DD594: @ 0x080DD594
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _080DD5D0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	ldrh r0, [r4, #0x1c]
	adds r1, r0, #1
	strh r1, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble _080DD61E
	movs r0, #0
	strh r0, [r4, #0x1c]
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _080DD5DC
	ldr r0, _080DD5D4
	ldr r1, _080DD5D8
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #1
	bl RequestDma3Copy
	b _080DD5F0
	.align 2, 0
_080DD5D0: .4byte 0x03005B60
_080DD5D4: .4byte 0x02019000
_080DD5D8: .4byte 0x06002000
_080DD5DC:
	ldr r0, _080DD624
	ldr r1, _080DD628
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #1
	bl RequestDma3Copy
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
_080DD5F0:
	ldr r1, _080DD62C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #0x1e]
	movs r2, #1
	eors r1, r2
	strh r1, [r0, #0x1e]
	movs r1, #0x20
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080DD61E
	ldr r0, _080DD630
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #6]
	adds r0, r5, #0
	bl DestroyTask
_080DD61E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD624: .4byte 0x02018000
_080DD628: .4byte 0x06002000
_080DD62C: .4byte 0x03005B60
_080DD630: .4byte 0x02039BD4
	thumb_func_end sub_080DD594

	thumb_func_start sub_080DD634
sub_080DD634: @ 0x080DD634
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080DD674
	movs r1, #0xa
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r4, r4, #0x18
	cmp r4, #0
	ble _080DD69C
	ldr r7, _080DD678
	lsls r0, r5, #0x18
	adds r4, r0, #0
	cmp r4, #0
	ble _080DD680
	movs r5, #0
	ldr r2, _080DD67C
	ldr r0, [r2]
	ldr r0, [r0]
	movs r1, #0x13
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	b _080DD6B2
	.align 2, 0
_080DD674: .4byte 0x080DD6E5
_080DD678: .4byte 0x0000237E
_080DD67C: .4byte 0x02039BD4
_080DD680:
	ldr r2, _080DD698
	ldr r0, [r2]
	ldr r0, [r0]
	movs r1, #0x13
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r3, #0
	b _080DD6B2
	.align 2, 0
_080DD698: .4byte 0x02039BD4
_080DD69C:
	movs r7, #0
	lsls r0, r5, #0x18
	adds r4, r0, #0
	cmp r4, #0
	ble _080DD6AC
	movs r5, #0
	movs r3, #0xc
	b _080DD6B0
_080DD6AC:
	movs r5, #0xc
	movs r3, #0
_080DD6B0:
	ldr r2, _080DD6DC
_080DD6B2:
	ldr r1, _080DD6E0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	strh r7, [r0, #8]
	strh r5, [r0, #0xa]
	asrs r1, r4, #0x18
	strh r1, [r0, #0xc]
	strh r3, [r0, #0xe]
	ldr r0, [r2]
	ldr r2, [r0]
	ldrb r1, [r2, #7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD6DC: .4byte 0x02039BD4
_080DD6E0: .4byte 0x03005B60
	thumb_func_end sub_080DD634

	thumb_func_start sub_080DD6E4
sub_080DD6E4: @ 0x080DD6E4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _080DD714
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r3, r0, r2
	ldrh r0, [r3, #0x1c]
	adds r1, r0, #1
	strh r1, [r3, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _080DD760
	movs r0, #0
	strh r0, [r3, #0x1c]
	movs r1, #0xc
	ldrsh r0, [r3, r1]
	cmp r0, #0
	ble _080DD718
	ldrh r0, [r3, #0xa]
	adds r0, #1
	b _080DD71C
	.align 2, 0
_080DD714: .4byte 0x03005B60
_080DD718:
	ldrh r0, [r3, #0xa]
	subs r0, #1
_080DD71C:
	strh r0, [r3, #0xa]
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	adds r4, r4, r2
	ldrb r2, [r4, #0xa]
	ldrh r3, [r4, #8]
	movs r0, #0x11
	movs r1, #1
	bl BlendPalette
	ldrb r2, [r4, #0xa]
	ldrh r3, [r4, #8]
	movs r0, #0x1a
	movs r1, #1
	bl BlendPalette
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	movs r2, #0xe
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _080DD760
	adds r0, r5, #0
	bl DestroyTask
	ldr r0, _080DD768
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, #7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #7]
_080DD760:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD768: .4byte 0x02039BD4
	thumb_func_end sub_080DD6E4

	thumb_func_start sub_080DD76C
sub_080DD76C: @ 0x080DD76C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r5, #0
	ldr r0, _080DD808
	mov sb, r0
	mov r8, sb
	ldr r6, _080DD80C
	movs r4, #0
	movs r7, #0
_080DD78A:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r7, r0
	ldrb r1, [r0, #0x10]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _080DD820
	mov r2, sl
	cmp r2, #0
	beq _080DD820
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl GetTurnOrderNumberGfx
	mov r3, r8
	ldr r1, [r3]
	ldr r1, [r1, #0x14]
	adds r1, r4, r1
	ldrb r2, [r1, #1]
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldrh r1, [r1, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	ldr r2, _080DD810
	adds r1, r1, r2
	ldr r2, _080DD814
	bl CpuSet
	mov r0, r8
	ldr r3, [r0]
	ldr r0, [r3, #0x14]
	adds r0, r4, r0
	ldrb r0, [r0, #1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r2, _080DD818
	ldr r0, _080DD81C
	adds r0, r5, r0
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	strh r0, [r1, #0x22]
	ldr r0, [r3, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0, #1]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r3, #5
	rsbs r3, r3, #0
	adds r2, r3, #0
	ands r1, r2
	b _080DD83A
	.align 2, 0
_080DD808: .4byte 0x02039BD4
_080DD80C: .4byte 0x020205AC
_080DD810: .4byte 0x06010040
_080DD814: .4byte 0x04000008
_080DD818: .4byte 0x085609D4
_080DD81C: .4byte 0x02039BC6
_080DD820:
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0, #1]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
_080DD83A:
	strb r1, [r0]
	adds r4, #4
	adds r7, #0x1c
	adds r5, #1
	cmp r5, #3
	ble _080DD78A
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_080DD76C

	thumb_func_start GetTurnOrderNumberGfx
GetTurnOrderNumberGfx: @ 0x080DD854
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080DD87C
	ldr r1, [r1]
	ldr r2, [r1, #4]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r2, r1, r2
	ldrb r1, [r2, #0x10]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0x40
	bne _080DD884
	ldrb r0, [r2, #0x19]
	lsls r0, r0, #5
	ldr r1, _080DD880
	adds r0, r0, r1
	b _080DD886
	.align 2, 0
_080DD87C: .4byte 0x02039BD4
_080DD880: .4byte 0x08D8E97C
_080DD884:
	ldr r0, _080DD88C
_080DD886:
	pop {r1}
	bx r1
	.align 2, 0
_080DD88C: .4byte 0x08D8E9FC
	thumb_func_end GetTurnOrderNumberGfx

	thumb_func_start sub_080DD890
sub_080DD890: @ 0x080DD890
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r7, #0
	movs r0, #2
	mov sl, r0
	movs r0, #1
	mov r8, r0
	movs r0, #0x11
	mov sb, r0
_080DD8AA:
	ldr r0, _080DD944
	ldr r0, [r0]
	ldr r0, [r0, #8]
	adds r0, #0xd
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DD92E
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	bl Contest_IsMonsTurnDisabled
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DD92E
	ldr r0, _080DD948
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r5, r0, #2
	adds r5, r5, r0
	adds r6, r5, #2
	movs r0, #3
	bl sub_080DAEAC
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r0, sl
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0x14
	adds r3, r6, #0
	bl ContestBG_FillBoxWithIncrementingTile
	adds r4, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r5, #3
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r0, sl
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0x14
	adds r3, r5, #0
	bl ContestBG_FillBoxWithIncrementingTile
	movs r0, #0x63
	bl PlaySE
_080DD92E:
	adds r7, #1
	cmp r7, #3
	ble _080DD8AA
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD944: .4byte 0x02039BD4
_080DD948: .4byte 0x02039BC6
	thumb_func_end sub_080DD890

	thumb_func_start sub_080DD94C
sub_080DD94C: @ 0x080DD94C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080DD97C
	ldr r1, [r1]
	ldr r2, [r1, #4]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r2, r1, r2
	ldrb r1, [r2, #0x15]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _080DD976
	ldrb r1, [r2, #0xc]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DD980
_080DD976:
	movs r0, #0
	b _080DD982
	.align 2, 0
_080DD97C: .4byte 0x02039BD4
_080DD980:
	movs r0, #1
_080DD982:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080DD94C

	thumb_func_start sub_080DD988
sub_080DD988: @ 0x080DD988
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	movs r0, #0xa
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	ldrb r1, [r2]
	movs r4, #4
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r2, #1]
	movs r0, #0x3f
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #1]
	ldrb r1, [r2, #1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #1]
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	mov r8, r0
	ands r0, r1
	strb r0, [r2]
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0xa
	bl SetGpuReg
	movs r0, #8
	bl GetGpuReg
	mov r6, sp
	adds r6, #2
	strh r0, [r6]
	movs r0, #0xc
	bl GetGpuReg
	add r5, sp, #4
	strh r0, [r5]
	ldrb r1, [r6]
	adds r0, r4, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6]
	ldrb r0, [r5]
	ands r4, r0
	orrs r4, r1
	strb r4, [r5]
	ldrh r1, [r6]
	movs r0, #8
	bl SetGpuReg
	ldrh r1, [r5]
	movs r0, #0xc
	bl SetGpuReg
	ldr r1, _080DDA9C
	movs r0, #0xf0
	strh r0, [r1]
	ldr r4, _080DDAA0
	movs r0, #0xa0
	strh r0, [r4]
	movs r0, #0x14
	movs r1, #0xf0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, #0x16
	bl SetGpuReg
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r4, _080DDAA4
	ldr r1, [r4]
	ldr r1, [r1, #0x28]
	ldr r2, _080DDAA8
	bl CpuSet
	ldr r1, _080DDAAC
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	movs r0, #1
	bl Contest_SetBgCopyFlags
	movs r5, #0
	ldr r7, _080DDAB0
	movs r6, #4
_080DDA54:
	ldr r0, [r4]
	ldr r0, [r0, #0x14]
	lsls r3, r5, #2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	mov r0, r8
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, #5]
	ldr r0, [r4]
	ldr r0, [r0, #0x14]
	adds r3, r3, r0
	ldrb r0, [r3, #1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	mov r0, r8
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, #5]
	adds r5, #1
	cmp r5, #3
	ble _080DDA54
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DDA9C: .4byte 0x02022ACC
_080DDAA0: .4byte 0x02022ACE
_080DDAA4: .4byte 0x02039BD4
_080DDAA8: .4byte 0x05000400
_080DDAAC: .4byte 0x08C17988
_080DDAB0: .4byte 0x020205AC
	thumb_func_end sub_080DD988

	thumb_func_start sub_080DDAB4
sub_080DDAB4: @ 0x080DDAB4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r1, _080DDB70
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0
	movs r3, #1
	bl RequestDma3Fill
	movs r5, #0
	str r5, [sp]
	ldr r6, _080DDB74
	ldr r0, [r6]
	ldr r1, [r0, #0x28]
	ldr r2, _080DDB78
	mov r0, sp
	bl CpuSet
	movs r0, #1
	bl Contest_SetBgCopyFlags
	movs r0, #0xa
	bl GetGpuReg
	add r3, sp, #4
	strh r0, [r3]
	ldrb r1, [r3]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r3]
	mov r1, sp
	adds r1, #5
	ldrb r2, [r1]
	movs r0, #0x3f
	ands r0, r2
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r3]
	movs r4, #0xd
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r3]
	ldrh r1, [r3]
	movs r0, #0xa
	bl SetGpuReg
	ldr r0, _080DDB7C
	strh r5, [r0]
	ldr r0, _080DDB80
	strh r5, [r0]
	ldr r7, _080DDB84
_080DDB2E:
	ldr r0, [r6]
	ldr r0, [r0, #0x14]
	lsls r3, r5, #2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	adds r0, r4, #0
	ands r0, r2
	strb r0, [r1, #5]
	ldr r0, [r6]
	ldr r0, [r0, #0x14]
	adds r3, r3, r0
	ldrb r0, [r3, #1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	adds r0, r4, #0
	ands r0, r2
	strb r0, [r1, #5]
	adds r5, #1
	cmp r5, #3
	ble _080DDB2E
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DDB70: .4byte 0x06008000
_080DDB74: .4byte 0x02039BD4
_080DDB78: .4byte 0x05000400
_080DDB7C: .4byte 0x02022ACC
_080DDB80: .4byte 0x02022ACE
_080DDB84: .4byte 0x020205AC
	thumb_func_end sub_080DDAB4

	thumb_func_start sub_080DDB88
sub_080DDB88: @ 0x080DDB88
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _080DDBB8
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080DDBBC
	movs r0, #0xa0
	strh r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl PlaySE12WithPanning
	ldr r1, _080DDBC0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _080DDBC4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DDBB8: .4byte 0x02022ACC
_080DDBBC: .4byte 0x02022ACE
_080DDBC0: .4byte 0x03005B60
_080DDBC4: .4byte 0x080DDBC9
	thumb_func_end sub_080DDB88

	thumb_func_start sub_080DDBC8
sub_080DDBC8: @ 0x080DDBC8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r1, _080DDC00
	ldrh r0, [r1]
	subs r0, #7
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080DDBE0
	movs r0, #0
	strh r0, [r1]
_080DDBE0:
	ldrh r2, [r1]
	cmp r2, #0
	bne _080DDBFA
	ldr r0, _080DDC04
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r0
	strh r2, [r1, #8]
	strh r2, [r1, #0xa]
	strh r2, [r1, #0xc]
	ldr r0, _080DDC08
	str r0, [r1]
_080DDBFA:
	pop {r0}
	bx r0
	.align 2, 0
_080DDC00: .4byte 0x02022ACE
_080DDC04: .4byte 0x03005B60
_080DDC08: .4byte 0x080DDC0D
	thumb_func_end sub_080DDBC8

	thumb_func_start sub_080DDC0C
sub_080DDC0C: @ 0x080DDC0C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _080DDC30
	lsls r3, r4, #2
	adds r0, r3, r4
	lsls r0, r0, #3
	adds r5, r0, r1
	movs r0, #8
	ldrsh r1, [r5, r0]
	cmp r1, #1
	beq _080DDC90
	cmp r1, #1
	bgt _080DDC34
	cmp r1, #0
	beq _080DDC3E
	b _080DDD18
	.align 2, 0
_080DDC30: .4byte 0x03005B60
_080DDC34:
	cmp r1, #2
	beq _080DDCEE
	cmp r1, #3
	beq _080DDD08
	b _080DDD18
_080DDC3E:
	movs r2, #0
	adds r6, r3, #0
	ldr r5, _080DDC84
	ldr r3, _080DDC88
_080DDC46:
	ldr r0, [r5]
	ldr r1, [r0]
	adds r1, #0x14
	adds r1, r1, r2
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	cmp r2, #3
	ble _080DDC46
	bl FillContestantWindowBgs
	bl sub_080DBFC8
	bl sub_080DAE00
	bl DrawContestantWindows
	movs r0, #1
	bl sub_080DD76C
	bl sub_080DBBB0
	ldr r0, _080DDC8C
	adds r1, r6, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r0, #1
	strh r0, [r1, #8]
	b _080DDD18
	.align 2, 0
_080DDC84: .4byte 0x02039BD4
_080DDC88: .4byte 0x02039BC6
_080DDC8C: .4byte 0x03005B60
_080DDC90:
	ldr r0, _080DDCD8
	ldrb r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _080DDCE8
	ldr r0, _080DDCDC
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #7]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #7]
	bl sub_080DA094
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080DDCB6
	bl sub_080DB204
_080DDCB6:
	ldr r4, _080DDCE0
	adds r0, r4, #0
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DDCE4
	adds r1, r4, #0
	bl SetTaskFuncWithFollowupFunc
	bl ContestPrintLinkStandby
	movs r0, #2
	strh r0, [r5, #8]
	b _080DDD18
	.align 2, 0
_080DDCD8: .4byte 0x02039BCA
_080DDCDC: .4byte 0x02039BD4
_080DDCE0: .4byte 0x080FD4DD
_080DDCE4: .4byte 0x080D9901
_080DDCE8:
	bl sub_080DB204
	b _080DDCFE
_080DDCEE:
	ldr r0, _080DDD04
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, #7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080DDD18
_080DDCFE:
	movs r0, #3
	strh r0, [r5, #8]
	b _080DDD18
	.align 2, 0
_080DDD04: .4byte 0x02039BD4
_080DDD08:
	bl sub_080DAFE8
	bl SwapMoveDescAndContestTilemaps
	movs r0, #0
	strh r0, [r5, #8]
	ldr r0, _080DDD20
	str r0, [r5]
_080DDD18:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DDD20: .4byte 0x080DDD59
	thumb_func_end sub_080DDC0C

	thumb_func_start sub_080DDD24
sub_080DDD24: @ 0x080DDD24
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _080DDD4C
	ldrh r0, [r1]
	adds r0, #7
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa0
	ble _080DDD48
	ldr r0, _080DDD50
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _080DDD54
	str r0, [r1]
_080DDD48:
	pop {r0}
	bx r0
	.align 2, 0
_080DDD4C: .4byte 0x02022ACE
_080DDD50: .4byte 0x03005B60
_080DDD54: .4byte 0x080D9CE5
	thumb_func_end sub_080DDD24

	thumb_func_start sub_080DDD58
sub_080DDD58: @ 0x080DDD58
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DDD78
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r2, [r1, #0xc]
	movs r3, #0xc
	ldrsh r0, [r1, r3]
	cmp r0, #9
	bgt _080DDD7C
	adds r0, r2, #1
	strh r0, [r1, #0xc]
	b _080DDDB8
	.align 2, 0
_080DDD78: .4byte 0x03005B60
_080DDD7C:
	ldrh r3, [r1, #0xa]
	movs r4, #0xa
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne _080DDD9A
	ldrh r2, [r1, #8]
	movs r4, #8
	ldrsh r0, [r1, r4]
	cmp r0, #0x10
	bne _080DDD96
	adds r0, r3, #1
	strh r0, [r1, #0xa]
	b _080DDDB8
_080DDD96:
	adds r0, r2, #1
	b _080DDDB6
_080DDD9A:
	ldrh r0, [r1, #8]
	movs r3, #8
	ldrsh r2, [r1, r3]
	cmp r2, #0
	bne _080DDDB4
	strh r2, [r1, #0xa]
	strh r2, [r1, #0xc]
	ldr r0, _080DDDB0
	str r0, [r1]
	b _080DDDB8
	.align 2, 0
_080DDDB0: .4byte 0x080DDDC1
_080DDDB4:
	subs r0, #1
_080DDDB6:
	strh r0, [r1, #8]
_080DDDB8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080DDD58

	thumb_func_start sub_080DDDC0
sub_080DDDC0: @ 0x080DDDC0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DDDE0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
	ldrh r1, [r4, #0xc]
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r0, #9
	bgt _080DDDE4
	adds r0, r1, #1
	strh r0, [r4, #0xc]
	b _080DDDF4
	.align 2, 0
_080DDDE0: .4byte 0x03005B60
_080DDDE4:
	movs r0, #0
	strh r0, [r4, #0xc]
	movs r0, #0x61
	movs r1, #0
	bl PlaySE12WithPanning
	ldr r0, _080DDDFC
	str r0, [r4]
_080DDDF4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DDDFC: .4byte 0x080DDD25
	thumb_func_end sub_080DDDC0

	thumb_func_start sub_080DDE00
sub_080DDE00: @ 0x080DDE00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r7, #0
	ldr r6, _080DDEE8
	ldr r5, _080DDEEC
_080DDE12:
	bl AllocOamMatrix
	ldr r1, [r5]
	ldr r1, [r1, #0x14]
	lsls r4, r7, #2
	adds r1, r4, r1
	ldrb r1, [r1]
	lsls r3, r1, #4
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r3, r3, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #1
	ldrb r1, [r3, #3]
	movs r2, #0x3f
	rsbs r2, r2, #0
	mov ip, r2
	mov r2, ip
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #3]
	ldr r0, [r5]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r2, [r0, #1]
	movs r3, #4
	rsbs r3, r3, #0
	adds r1, r3, #0
	ands r2, r1
	movs r1, #1
	orrs r2, r1
	strb r2, [r0, #1]
	ldr r0, [r5]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	mov r1, r8
	bl StartSpriteAffineAnim
	mov r0, r8
	cmp r0, #2
	bne _080DDEB0
	ldr r0, [r5]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	bl AnimateSprite
	ldr r0, [r5]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r3, #5
	rsbs r3, r3, #0
	adds r2, r3, #0
	ands r1, r2
	strb r1, [r0]
_080DDEB0:
	adds r7, #1
	cmp r7, #3
	ble _080DDE12
	ldr r0, _080DDEF0
	movs r1, #5
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DDEF4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	mov r0, r8
	strh r0, [r1, #8]
	ldr r0, _080DDEEC
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #7]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #7]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DDEE8: .4byte 0x020205AC
_080DDEEC: .4byte 0x02039BD4
_080DDEF0: .4byte 0x080DDEF9
_080DDEF4: .4byte 0x03005B60
	thumb_func_end sub_080DDE00

	thumb_func_start sub_080DDEF8
sub_080DDEF8: @ 0x080DDEF8
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r2, _080DDF8C
	ldr r3, _080DDF90
	ldr r0, [r3]
	ldr r0, [r0, #0x14]
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bge _080DDF86
	ldr r0, _080DDF94
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrb r0, [r1, #8]
	cmp r0, #1
	bne _080DDF50
	movs r4, #0
	adds r5, r2, #0
	movs r2, #4
_080DDF30:
	ldr r0, [r3]
	ldr r1, [r0, #0x14]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r4, #1
	cmp r4, #3
	ble _080DDF30
_080DDF50:
	movs r4, #0
_080DDF52:
	ldr r5, _080DDF90
	ldr r0, [r5]
	ldr r1, [r0, #0x14]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DDF8C
	adds r0, r0, r1
	bl FreeSpriteOamMatrix
	adds r4, #1
	cmp r4, #3
	ble _080DDF52
	ldr r0, [r5]
	ldr r2, [r0]
	ldrb r1, [r2, #7]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #7]
	adds r0, r6, #0
	bl DestroyTask
_080DDF86:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DDF8C: .4byte 0x020205AC
_080DDF90: .4byte 0x02039BD4
_080DDF94: .4byte 0x03005B60
	thumb_func_end sub_080DDEF8

	thumb_func_start SanitizeMove
SanitizeMove: @ 0x080DDF98
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0xb1
	lsls r0, r0, #1
	cmp r1, r0
	bls _080DDFA8
	movs r1, #1
_080DDFA8:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end SanitizeMove

	thumb_func_start SanitizeSpecies
SanitizeSpecies: @ 0x080DDFB0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080DDFC4
	cmp r1, r0
	bls _080DDFBE
	movs r1, #0
_080DDFBE:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_080DDFC4: .4byte 0x0000019B
	thumb_func_end SanitizeSpecies

	thumb_func_start sub_080DDFC8
sub_080DDFC8: @ 0x080DDFC8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r4, _080DE02C
	ldr r0, [r4]
	ldr r1, [r0, #4]
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #6]
	bl SanitizeMove
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r1, _080DE030
	lsls r0, r7, #6
	adds r0, r0, r1
	ldrh r0, [r0]
	bl SanitizeSpecies
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [r4]
	ldr r0, [r0, #0x18]
	movs r1, #0
	movs r2, #0x14
	bl memset
	bl ClearBattleAnimationVars
	ldr r1, _080DE034
	movs r2, #0
	adds r0, r1, #3
_080DE00C:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _080DE00C
	cmp r5, #0x90
	beq _080DE084
	cmp r5, #0x90
	bgt _080DE042
	cmp r5, #0x4c
	beq _080DE0DC
	cmp r5, #0x4c
	bgt _080DE038
	cmp r5, #0xd
	beq _080DE0DC
	b _080DE106
	.align 2, 0
_080DE02C: .4byte 0x02039BD4
_080DE030: .4byte 0x02039AA0
_080DE034: .4byte 0x02024188
_080DE038:
	cmp r5, #0x82
	beq _080DE0DC
	cmp r5, #0x8f
	beq _080DE0DC
	b _080DE106
_080DE042:
	cmp r5, #0xd8
	beq _080DE0C4
	cmp r5, #0xd8
	bgt _080DE050
	cmp r5, #0xae
	beq _080DE05E
	b _080DE106
_080DE050:
	cmp r5, #0xda
	beq _080DE0D0
	movs r0, #0x88
	lsls r0, r0, #1
	cmp r5, r0
	beq _080DE084
	b _080DE106
_080DE05E:
	ldr r0, _080DE07C
	lsls r1, r6, #3
	subs r1, r1, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1, #6]
	cmp r0, #7
	beq _080DE074
	ldrb r0, [r1, #7]
	cmp r0, #7
	bne _080DE100
_080DE074:
	ldr r1, _080DE080
	movs r0, #0
	b _080DE104
	.align 2, 0
_080DE07C: .4byte 0x082F0D54
_080DE080: .4byte 0x020380D2
_080DE084:
	ldr r6, _080DE0BC
	ldr r0, [r6]
	ldr r1, [r0, #4]
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r4, [r0, #0x1b]
	ldr r5, _080DE0C0
	lsls r4, r4, #6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl SanitizeSpecies
	ldr r2, [r6]
	ldr r1, [r2, #0x18]
	strh r0, [r1, #2]
	ldr r2, [r2, #0x18]
	adds r5, #0x38
	adds r4, r4, r5
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldrb r0, [r2, #4]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #4]
	b _080DE106
	.align 2, 0
_080DE0BC: .4byte 0x02039BD4
_080DE0C0: .4byte 0x02039AA0
_080DE0C4:
	ldr r1, _080DE0CC
	movs r0, #0xff
	b _080DE104
	.align 2, 0
_080DE0CC: .4byte 0x020380BA
_080DE0D0:
	ldr r1, _080DE0D8
	movs r0, #0
	b _080DE104
	.align 2, 0
_080DE0D8: .4byte 0x020380BA
_080DE0DC:
	ldr r0, _080DE0F8
	ldr r0, [r0]
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x5a
	ldrb r1, [r2]
	cmp r1, #0
	bne _080DE100
	movs r0, #2
	strb r0, [r2]
	ldr r0, _080DE0FC
	strb r1, [r0]
	b _080DE106
	.align 2, 0
_080DE0F8: .4byte 0x02039BD4
_080DE0FC: .4byte 0x020380D2
_080DE100:
	ldr r1, _080DE110
	movs r0, #1
_080DE104:
	strb r0, [r1]
_080DE106:
	bl sub_080DE1C0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE110: .4byte 0x020380D2
	thumb_func_end sub_080DDFC8

	thumb_func_start sub_080DE114
sub_080DE114: @ 0x080DE114
	push {r4, lr}
	ldr r4, _080DE13C
	ldr r0, [r4]
	ldr r0, [r0, #0x18]
	movs r1, #0
	movs r2, #0x14
	bl memset
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5a
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DE136
	subs r0, #1
	strb r0, [r1]
_080DE136:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DE13C: .4byte 0x02039BD4
	thumb_func_end sub_080DE114

	thumb_func_start sub_080DE140
sub_080DE140: @ 0x080DE140
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r6, _080DE17C
	ldr r0, [r6]
	ldr r0, [r0, #0x18]
	strb r4, [r0, #5]
	ldr r5, _080DE180
	lsls r4, r4, #6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl SanitizeSpecies
	ldr r2, [r6]
	ldr r1, [r2, #0x18]
	strh r0, [r1]
	ldr r1, [r2, #0x18]
	adds r0, r5, #0
	adds r0, #0x38
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [r1, #8]
	adds r5, #0x3c
	adds r4, r4, r5
	ldr r0, [r4]
	str r0, [r1, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DE17C: .4byte 0x02039BD4
_080DE180: .4byte 0x02039AA0
	thumb_func_end sub_080DE140

	thumb_func_start sub_080DE184
sub_080DE184: @ 0x080DE184
	push {lr}
	ldr r0, _080DE1B0
	bl CreateInvisibleSpriteWithCallback
	ldr r1, _080DE1B4
	strb r0, [r1, #3]
	ldr r0, _080DE1B8
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DE1BC
	adds r0, r0, r1
	bl InitSpriteAffineAnim
	bl sub_080DE1C0
	pop {r0}
	bx r0
	.align 2, 0
_080DE1B0: .4byte 0x08007141
_080DE1B4: .4byte 0x02023E88
_080DE1B8: .4byte 0x02023EB0
_080DE1BC: .4byte 0x020205AC
	thumb_func_end sub_080DE184

	thumb_func_start sub_080DE1C0
sub_080DE1C0: @ 0x080DE1C0
	push {r4, lr}
	ldr r0, _080DE204
	ldrb r0, [r0, #3]
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080DE208
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	movs r0, #3
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x20]
	movs r0, #3
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x22]
	adds r4, #0x3e
	ldrb r0, [r4]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DE204: .4byte 0x02023E88
_080DE208: .4byte 0x020205AC
	thumb_func_end sub_080DE1C0

	thumb_func_start SelectContestMoveBankTarget
SelectContestMoveBankTarget: @ 0x080DE20C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080DE22C
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r0, [r1, #6]
	cmp r0, #0x20
	bhi _080DE2C4
	lsls r0, r0, #2
	ldr r1, _080DE230
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE22C: .4byte 0x082ED220
_080DE230: .4byte 0x080DE234
_080DE234: @ jump table
	.4byte _080DE2C4 @ case 0
	.4byte _080DE2C4 @ case 1
	.4byte _080DE2B8 @ case 2
	.4byte _080DE2C4 @ case 3
	.4byte _080DE2C4 @ case 4
	.4byte _080DE2C4 @ case 5
	.4byte _080DE2C4 @ case 6
	.4byte _080DE2C4 @ case 7
	.4byte _080DE2C4 @ case 8
	.4byte _080DE2C4 @ case 9
	.4byte _080DE2C4 @ case 10
	.4byte _080DE2C4 @ case 11
	.4byte _080DE2C4 @ case 12
	.4byte _080DE2C4 @ case 13
	.4byte _080DE2C4 @ case 14
	.4byte _080DE2C4 @ case 15
	.4byte _080DE2B8 @ case 16
	.4byte _080DE2C4 @ case 17
	.4byte _080DE2C4 @ case 18
	.4byte _080DE2C4 @ case 19
	.4byte _080DE2C4 @ case 20
	.4byte _080DE2C4 @ case 21
	.4byte _080DE2C4 @ case 22
	.4byte _080DE2C4 @ case 23
	.4byte _080DE2C4 @ case 24
	.4byte _080DE2C4 @ case 25
	.4byte _080DE2C4 @ case 26
	.4byte _080DE2C4 @ case 27
	.4byte _080DE2C4 @ case 28
	.4byte _080DE2C4 @ case 29
	.4byte _080DE2C4 @ case 30
	.4byte _080DE2C4 @ case 31
	.4byte _080DE2C4 @ case 32
_080DE2B8:
	ldr r1, _080DE2C0
	movs r0, #2
	b _080DE2C8
	.align 2, 0
_080DE2C0: .4byte 0x02023EB0
_080DE2C4:
	ldr r1, _080DE2D0
	movs r0, #3
_080DE2C8:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080DE2D0: .4byte 0x02023EB0
	thumb_func_end SelectContestMoveBankTarget

	thumb_func_start Contest_PrintTextToBg0WindowStd
Contest_PrintTextToBg0WindowStd: @ 0x080DE2D4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp]
	mov r0, sp
	movs r2, #0
	strb r4, [r0, #4]
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #5]
	mov r0, sp
	strb r2, [r0, #6]
	movs r1, #2
	strb r1, [r0, #7]
	strb r2, [r0, #8]
	strb r1, [r0, #9]
	strb r2, [r0, #0xa]
	strb r2, [r0, #0xb]
	mov r3, sp
	ldrb r2, [r3, #0xc]
	subs r1, #0x12
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xc]
	mov r2, sp
	movs r0, #0xf0
	strb r0, [r2, #0xc]
	ldrb r0, [r2, #0xd]
	ands r1, r0
	strb r1, [r2, #0xd]
	mov r1, sp
	movs r0, #0x80
	strb r0, [r1, #0xd]
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl AddTextPrinter
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl PutWindowTilemap
	movs r0, #0
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end Contest_PrintTextToBg0WindowStd

	thumb_func_start Contest_StartTextPrinter
Contest_StartTextPrinter: @ 0x080DE338
	push {r4, r5, lr}
	sub sp, #0x10
	str r0, [sp]
	mov r2, sp
	movs r3, #0
	movs r0, #8
	strb r0, [r2, #4]
	mov r0, sp
	movs r5, #1
	strb r5, [r0, #5]
	strb r3, [r0, #6]
	movs r2, #2
	strb r2, [r0, #7]
	strb r3, [r0, #8]
	strb r2, [r0, #9]
	strb r3, [r0, #0xa]
	strb r3, [r0, #0xb]
	mov r4, sp
	ldrb r3, [r4, #0xc]
	subs r2, #0x12
	adds r0, r2, #0
	ands r0, r3
	strb r0, [r4, #0xc]
	mov r3, sp
	movs r0, #0x10
	strb r0, [r3, #0xc]
	ldrb r0, [r3, #0xd]
	ands r2, r0
	strb r2, [r3, #0xd]
	mov r2, sp
	movs r0, #0x80
	strb r0, [r2, #0xd]
	cmp r1, #0
	bne _080DE388
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl AddTextPrinter
	b _080DE3AC
_080DE388:
	ldr r0, _080DE398
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _080DE39C
	movs r1, #4
	b _080DE3A4
	.align 2, 0
_080DE398: .4byte 0x02039BCA
_080DE39C:
	bl GetPlayerTextSpeedDelay
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_080DE3A4:
	mov r0, sp
	movs r2, #0
	bl AddTextPrinter
_080DE3AC:
	movs r0, #8
	bl PutWindowTilemap
	movs r0, #0
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end Contest_StartTextPrinter

	thumb_func_start ContestBG_FillBoxWithIncrementingTile
ContestBG_FillBoxWithIncrementingTile: @ 0x080DE3C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	ldr r0, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	mov r7, r8
	lsls r7, r7, #0x18
	lsrs r7, r7, #0x18
	mov r8, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r0, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	str r6, [sp, #0xc]
	mov r0, r8
	bl WriteSequenceToBgTilemapBuffer
	mov r0, r8
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ContestBG_FillBoxWithIncrementingTile

	thumb_func_start ContestBG_FillBoxWithTile
ContestBG_FillBoxWithTile: @ 0x080DE418
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r6, [sp, #0x28]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	bl ContestBG_FillBoxWithIncrementingTile
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end ContestBG_FillBoxWithTile

	thumb_func_start Contest_RunTextPrinters
Contest_RunTextPrinters: @ 0x080DE454
	push {lr}
	bl RunTextPrinters
	movs r0, #8
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	thumb_func_end Contest_RunTextPrinters

	thumb_func_start Contest_SetBgCopyFlags
Contest_SetBgCopyFlags: @ 0x080DE468
	ldr r2, _080DE478
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.align 2, 0
_080DE478: .4byte 0x02039BD8
	thumb_func_end Contest_SetBgCopyFlags

	thumb_func_start ResetContestLinkResults
ResetContestLinkResults: @ 0x080DE47C
	push {r4, r5, r6, lr}
	movs r0, #0
	ldr r6, _080DE4A8
	ldr r5, _080DE4AC
	movs r4, #0
_080DE486:
	adds r3, r0, #1
	lsls r1, r0, #3
	movs r2, #3
_080DE48C:
	ldr r0, [r6]
	adds r0, r0, r5
	adds r0, r0, r1
	strh r4, [r0]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _080DE48C
	adds r0, r3, #0
	cmp r0, #4
	ble _080DE486
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DE4A8: .4byte 0x03005AF0
_080DE4AC: .4byte 0x00000624
	thumb_func_end ResetContestLinkResults

	thumb_func_start sub_080DE4B0
sub_080DE4B0: @ 0x080DE4B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r5, #0
	ldr r1, _080DE500
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DE4EE
_080DE4E0:
	adds r5, #1
	cmp r5, #2
	bgt _080DE4EE
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DE4E0
_080DE4EE:
	ldr r0, [sp]
	cmp r0, #0xff
	bne _080DE508
	ldr r0, _080DE504
	ldrb r0, [r0]
	cmp r5, r0
	beq _080DE508
	movs r0, #0
	b _080DE698
	.align 2, 0
_080DE500: .4byte 0x02039BC0
_080DE504: .4byte 0x02039BC5
_080DE508:
	ldr r0, _080DE51C
	ldrh r0, [r0]
	cmp r0, #4
	bhi _080DE554
	lsls r0, r0, #2
	ldr r1, _080DE520
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE51C: .4byte 0x02039BCC
_080DE520: .4byte 0x080DE524
_080DE524: @ jump table
	.4byte _080DE554 @ case 0
	.4byte _080DE538 @ case 1
	.4byte _080DE53E @ case 2
	.4byte _080DE544 @ case 3
	.4byte _080DE54A @ case 4
_080DE538:
	mov r0, r8
	adds r0, #3
	b _080DE54E
_080DE53E:
	mov r0, r8
	adds r0, #6
	b _080DE54E
_080DE544:
	mov r0, r8
	adds r0, #9
	b _080DE54E
_080DE54A:
	mov r0, r8
	adds r0, #0xc
_080DE54E:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_080DE554:
	ldr r1, [sp]
	cmp r1, #0xfe
	bne _080DE55C
	b _080DE658
_080DE55C:
	adds r0, r1, #0
	movs r1, #1
	bl sub_080DE6B0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r2, _080DE5E0
	mov sl, r2
	ldr r0, [r2]
	mov r3, sb
	lsls r7, r3, #5
	ldr r6, _080DE5E4
	adds r2, r0, r6
	adds r2, r2, r7
	ldr r4, _080DE5E8
	lsls r5, r5, #6
	adds r1, r4, #0
	adds r1, #0x38
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r1, r0, r7
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r3, _080DE5EC
	adds r1, r1, r3
	strh r2, [r1]
	ldr r1, _080DE5F0
	adds r2, r0, r1
	adds r2, r2, r7
	adds r1, r4, #0
	adds r1, #0x3c
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r6, r7, r6
	adds r0, r0, r6
	adds r0, #0xb
	adds r1, r4, #2
	adds r1, r5, r1
	bl StringCopy
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r6
	adds r0, #0x16
	adds r4, #0xd
	adds r5, r5, r4
	adds r1, r5, #0
	bl StringCopy
	ldr r0, _080DE5F4
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DE5FC
	mov r3, sl
	ldr r0, [r3]
	adds r0, r0, r7
	ldr r1, _080DE5F8
	adds r0, r0, r1
	movs r1, #4
	b _080DE60A
	.align 2, 0
_080DE5E0: .4byte 0x03005AEC
_080DE5E4: .4byte 0x00002E90
_080DE5E8: .4byte 0x02039AA0
_080DE5EC: .4byte 0x00002E98
_080DE5F0: .4byte 0x00002E94
_080DE5F4: .4byte 0x02039BCA
_080DE5F8: .4byte 0x00002EAE
_080DE5FC:
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r7
	ldr r1, _080DE628
	ldrh r1, [r1]
	ldr r3, _080DE62C
	adds r0, r0, r3
_080DE60A:
	strb r1, [r0]
	ldr r0, [sp]
	cmp r0, #0xff
	beq _080DE63C
	ldr r0, _080DE630
	ldr r0, [r0]
	mov r2, sb
	lsls r1, r2, #5
	adds r0, r0, r1
	ldr r1, _080DE634
	ldrh r1, [r1]
	ldr r3, _080DE638
	adds r0, r0, r3
	strb r1, [r0]
	b _080DE696
	.align 2, 0
_080DE628: .4byte 0x02039BCE
_080DE62C: .4byte 0x00002EAE
_080DE630: .4byte 0x03005AEC
_080DE634: .4byte 0x02039BCC
_080DE638: .4byte 0x00002E9A
_080DE63C:
	ldr r0, _080DE650
	ldr r0, [r0]
	mov r2, sb
	lsls r1, r2, #5
	adds r0, r0, r1
	ldr r3, _080DE654
	adds r0, r0, r3
	mov r1, r8
	strb r1, [r0]
	b _080DE696
	.align 2, 0
_080DE650: .4byte 0x03005AEC
_080DE654: .4byte 0x00002E9A
_080DE658:
	ldr r6, _080DE6A8
	ldr r4, _080DE6AC
	lsls r5, r5, #6
	adds r0, r4, #0
	adds r0, #0x38
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0x3c
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6, #4]
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r6, #8]
	adds r0, r6, #0
	adds r0, #0xb
	adds r1, r4, #2
	adds r1, r5, r1
	bl StringCopy
	adds r0, r6, #0
	adds r0, #0x16
	adds r4, #0xd
	adds r5, r5, r4
	adds r1, r5, #0
	bl StringCopy
	mov r2, r8
	strb r2, [r6, #0xa]
_080DE696:
	movs r0, #1
_080DE698:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DE6A8: .4byte 0x02039BDC
_080DE6AC: .4byte 0x02039AA0
	thumb_func_end sub_080DE4B0

	thumb_func_start sub_080DE6B0
sub_080DE6B0: @ 0x080DE6B0
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r0, #3
	bgt _080DE700
	cmp r0, #0
	blt _080DE700
	cmp r1, #0
	beq _080DE6EE
	movs r2, #5
	ldr r0, _080DE6F4
	mov ip, r0
	ldr r4, _080DE6F8
	ldr r3, _080DE6FC
_080DE6D0:
	mov r1, ip
	ldr r0, [r1]
	lsls r1, r2, #5
	adds r1, r1, r0
	adds r0, r1, r4
	adds r1, r1, r3
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r0!, {r5, r6}
	subs r2, #1
	cmp r2, #0
	bgt _080DE6D0
_080DE6EE:
	movs r0, #0
	b _080DE742
	.align 2, 0
_080DE6F4: .4byte 0x03005AEC
_080DE6F8: .4byte 0x00002E90
_080DE6FC: .4byte 0x00002E70
_080DE700:
	ldr r0, _080DE714
	ldrh r0, [r0]
	cmp r0, #4
	bhi _080DE740
	lsls r0, r0, #2
	ldr r1, _080DE718
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE714: .4byte 0x02039BCC
_080DE718: .4byte 0x080DE71C
_080DE71C: @ jump table
	.4byte _080DE730 @ case 0
	.4byte _080DE734 @ case 1
	.4byte _080DE738 @ case 2
	.4byte _080DE73C @ case 3
	.4byte _080DE740 @ case 4
_080DE730:
	movs r0, #8
	b _080DE742
_080DE734:
	movs r0, #9
	b _080DE742
_080DE738:
	movs r0, #0xa
	b _080DE742
_080DE73C:
	movs r0, #0xb
	b _080DE742
_080DE740:
	movs r0, #0xc
_080DE742:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080DE6B0

	thumb_func_start ClearContestWinnerPicsInContestHall
ClearContestWinnerPicsInContestHall: @ 0x080DE748
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r0, _080DE77C
	mov ip, r0
	ldr r4, _080DE780
	ldr r3, _080DE784
_080DE754:
	mov r1, ip
	ldr r0, [r1]
	lsls r1, r2, #5
	adds r0, r0, r1
	adds r0, r0, r4
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r0!, {r5, r6}
	adds r3, #0x20
	adds r2, #1
	cmp r2, #7
	ble _080DE754
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE77C: .4byte 0x03005AEC
_080DE780: .4byte 0x00002E90
_080DE784: .4byte 0x08560F28
	thumb_func_end ClearContestWinnerPicsInContestHall

	thumb_func_start sub_080DE788
sub_080DE788: @ 0x080DE788
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _080DE8C0
	ldr r3, [r2]
	ldr r5, [r3, #0x10]
	ldrb r1, [r5, #1]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _080DE7DA
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _080DE7DA
	ldr r1, [r3, #4]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x15]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE7DA
	ldr r1, [r3, #0x1c]
	lsls r2, r4, #4
	adds r1, r2, r1
	ldrb r3, [r1, #0xc]
	movs r0, #1
	orrs r0, r3
	strb r0, [r1, #0xc]
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	adds r2, r2, r0
	ldrb r0, [r2, #0xe]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0xe]
_080DE7DA:
	ldr r3, [r6]
	ldr r1, [r3, #4]
	lsls r2, r4, #3
	subs r0, r2, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0xc]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _080DE802
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE802:
	ldr r3, [r6]
	ldr r2, [r3, #0x10]
	ldrb r1, [r2, #1]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE82E
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _080DE82E
	movs r0, #2
	ldrsb r0, [r2, r0]
	cmp r0, #0x3c
	bne _080DE82E
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #4
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE82E:
	ldr r3, [r6]
	ldr r1, [r3, #4]
	subs r0, r7, r4
	lsls r0, r0, #2
	adds r2, r0, r1
	ldrb r1, [r2, #0x15]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DE856
	ldrb r0, [r2, #0x16]
	cmp r0, #0
	beq _080DE856
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #8
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE856:
	movs r3, #0
	movs r5, #0
_080DE85A:
	cmp r3, r4
	beq _080DE888
	ldr r1, [r6]
	ldr r0, [r1, #4]
	adds r0, r5, r0
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _080DE888
	ldr r0, [r1, #0x1c]
	lsls r2, r4, #4
	adds r2, r2, r0
	ldrb r0, [r2, #0xc]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	lsls r2, r3, #4
	adds r2, r2, r0
	ldrb r0, [r2, #0xc]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0xc]
_080DE888:
	adds r5, #0x1c
	adds r3, #1
	cmp r3, #3
	ble _080DE85A
	ldr r2, [r6]
	ldr r1, [r2, #4]
	subs r0, r7, r4
	lsls r5, r0, #2
	adds r1, r5, r1
	ldrb r3, [r1, #0xc]
	movs r0, #6
	ands r0, r3
	cmp r0, #0
	bne _080DE8AE
	ldrb r1, [r1, #0xb]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080DE8C4
_080DE8AE:
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #0x20
	orrs r0, r2
	strb r0, [r1, #0xc]
	b _080DE8FE
	.align 2, 0
_080DE8C0: .4byte 0x02039BD4
_080DE8C4:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	bne _080DE8FE
	ldr r2, [r2, #0x1c]
	lsls r3, r4, #4
	adds r2, r3, r2
	ldrb r0, [r2, #0xc]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldr r0, [r6]
	ldr r1, [r0, #0x1c]
	adds r1, r3, r1
	ldrb r0, [r1, #0xe]
	movs r2, #1
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldr r1, [r6]
	ldr r0, [r1, #0x1c]
	adds r3, r3, r0
	ldr r0, [r1]
	ldrb r0, [r0, #1]
	lsls r0, r0, #1
	adds r3, r3, r0
	ldr r0, [r1, #4]
	adds r0, r5, r0
	ldrh r0, [r0, #6]
	strh r0, [r3]
_080DE8FE:
	ldr r2, [r6]
	ldr r1, [r2, #4]
	subs r0, r7, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x15]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _080DE922
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1, #0xd]
_080DE922:
	ldr r2, [r6]
	ldr r0, [r2]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080DE952
	ldr r3, [r2, #0x10]
	ldrb r1, [r3, #1]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE952
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _080DE952
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #0x20
	orrs r0, r2
	strb r0, [r1, #0xd]
_080DE952:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_080DE788

	thumb_func_start sub_080DE958
sub_080DE958: @ 0x080DE958
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	movs r1, #0
	movs r0, #0
	str r0, [sp, #0x20]
	movs r4, #0
	ldr r6, _080DE998
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x28]
	mov r3, sp
	adds r3, #0x14
	str r3, [sp, #0x2c]
	mov r7, sp
	adds r7, #2
	str r7, [sp, #0x24]
	ldr r5, _080DE99C
	movs r2, #0
	movs r3, #0x80
	lsls r3, r3, #0x11
_080DE988:
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DE9A0
	lsrs r0, r2, #0x18
	str r0, [sp, #0x20]
	b _080DE9A6
	.align 2, 0
_080DE998: .4byte 0x02039BD4
_080DE99C: .4byte 0x02039BC0
_080DE9A0:
	cmp r0, #3
	bne _080DE9A6
	lsrs r1, r2, #0x18
_080DE9A6:
	adds r2, r2, r3
	adds r4, #1
	cmp r4, #3
	ble _080DE988
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1, #0xd]
	movs r4, #0
	ldr r1, [sp, #0x20]
	lsls r1, r1, #4
	str r1, [sp, #0x30]
	mov sb, r4
	mov sl, r4
_080DE9CA:
	ldr r2, [sp, #0x20]
	cmp r4, r2
	beq _080DE9F6
	ldr r1, _080DEB94
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	add r1, sl
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r2, r2, r0
	cmp r2, #0x32
	bgt _080DE9F6
	ldr r7, _080DEB98
	ldr r0, [r7]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DE9F6:
	ldr r1, _080DEB98
	ldr r0, [r1]
	ldr r0, [r0, #0x1c]
	mov r3, sb
	adds r2, r3, r0
	ldrb r1, [r2, #0xe]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080DEA12
	ldrb r0, [r2, #0xd]
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEA12:
	movs r5, #0
	ldr r2, _080DEB9C
	add r2, sl
	movs r6, #0
	ldrsh r1, [r2, r6]
	ldr r7, _080DEB9C
	movs r3, #0
	ldrsh r0, [r7, r3]
	cmp r1, r0
	blt _080DEA3E
	adds r3, r2, #0
	adds r2, r7, #0
_080DEA2A:
	adds r2, #2
	adds r5, #1
	cmp r5, #3
	bgt _080DEA3E
	movs r6, #0
	ldrsh r1, [r3, r6]
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _080DEA2A
_080DEA3E:
	cmp r5, #4
	bne _080DEA5C
	ldr r1, _080DEBA0
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DEA5C
	ldr r2, _080DEB98
	ldr r0, [r2]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEA5C:
	movs r3, #0
	mov ip, r3
	mov r8, r3
	movs r5, #0
	ldr r0, _080DEB9C
	add r0, sl
	movs r7, #0
	ldrsh r6, [r0, r7]
	str r6, [sp, #0x34]
	ldr r2, _080DEB9C
	ldr r0, _080DEBA4
	mov r1, sl
	adds r6, r1, r0
	adds r3, r0, #0
_080DEA78:
	movs r7, #0
	ldrsh r0, [r2, r7]
	ldr r1, [sp, #0x34]
	cmp r1, r0
	ble _080DEA86
	movs r7, #1
	mov ip, r7
_080DEA86:
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble _080DEA96
	movs r0, #1
	mov r8, r0
_080DEA96:
	adds r2, #2
	adds r3, #2
	adds r5, #1
	cmp r5, #3
	ble _080DEA78
	mov r1, ip
	cmp r1, #0
	bne _080DEABC
	mov r2, r8
	cmp r2, #0
	bne _080DEABC
	ldr r3, _080DEB98
	ldr r0, [r3]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEABC:
	ldr r6, _080DEB98
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	mov r7, sb
	adds r2, r7, r0
	ldrb r1, [r2, #0xe]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DEAD8
	ldrb r0, [r2, #0xd]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEAD8:
	movs r0, #0x10
	add sb, r0
	movs r1, #2
	add sl, r1
	adds r4, #1
	cmp r4, #3
	bgt _080DEAE8
	b _080DE9CA
_080DEAE8:
	movs r4, #0
	movs r5, #0
	movs r3, #0
	ldr r2, [sp, #0x28]
	mov r1, sp
_080DEAF2:
	strh r3, [r1]
	adds r0, r2, r4
	strb r5, [r0]
	adds r1, #2
	adds r4, #1
	cmp r4, #4
	ble _080DEAF2
	mov r1, sp
	ldr r0, _080DEBA8
	strh r0, [r1, #0xa]
	movs r0, #0
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
	movs r4, #0
	ldr r0, _080DEB98
	ldr r0, [r0]
	mov r8, r0
	ldr r7, [sp, #0x30]
_080DEB16:
	mov r3, r8
	ldr r0, [r3, #0x1c]
	adds r0, r7, r0
	lsls r1, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, #1
	mov ip, r4
	cmp r0, #0
	beq _080DEB58
	ldr r0, _080DEB98
	ldr r6, [r0]
	ldr r3, [sp, #0x28]
	mov r4, sp
	movs r5, #4
_080DEB34:
	ldr r0, [r6, #0x1c]
	adds r0, r7, r0
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	beq _080DEB48
	cmp r2, #0
	bne _080DEB4E
	strh r0, [r4]
_080DEB48:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_080DEB4E:
	adds r3, #1
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080DEB34
_080DEB58:
	mov r4, ip
	cmp r4, #4
	ble _080DEB16
	mov r0, sp
	ldrh r0, [r0]
	ldr r6, [sp, #0x2c]
	strh r0, [r6]
	ldr r7, [sp, #0x28]
	ldrb r3, [r7]
	movs r6, #0
	movs r4, #1
	ldr r1, [sp, #0x24]
	ldrh r0, [r1]
	ldr r1, _080DEBA8
	cmp r0, r1
	beq _080DEBC8
	ldr r5, [sp, #0x2c]
	adds r7, r1, #0
	mov r2, sp
	adds r2, #2
_080DEB80:
	ldr r0, [sp, #0x28]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r3, r0
	bhs _080DEBAC
	ldrh r0, [r2]
	strh r0, [r5]
	ldrb r3, [r1]
	movs r6, #1
	b _080DEBBE
	.align 2, 0
_080DEB94: .4byte 0x02039BA8
_080DEB98: .4byte 0x02039BD4
_080DEB9C: .4byte 0x02039BA0
_080DEBA0: .4byte 0x02039BC0
_080DEBA4: .4byte 0x02039BB8
_080DEBA8: .4byte 0x0000FFFF
_080DEBAC:
	cmp r3, r0
	bne _080DEBBE
	lsls r0, r6, #1
	adds r0, r5, r0
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_080DEBBE:
	adds r2, #2
	adds r4, #1
	ldrh r0, [r2]
	cmp r0, r7
	bne _080DEB80
_080DEBC8:
	bl Random
	ldr r1, _080DEBFC
	ldr r1, [r1]
	ldr r4, [r1, #0x1c]
	ldr r1, [sp, #0x30]
	adds r4, r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl __modsi3
	lsls r0, r0, #1
	ldr r2, [sp, #0x2c]
	adds r0, r2, r0
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEBFC: .4byte 0x02039BD4
	thumb_func_end sub_080DE958

	thumb_func_start sub_080DEC00
sub_080DEC00: @ 0x080DEC00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r2, _080DED34
	ldr r0, _080DED38
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DEC1C
	b _080DEDCC
_080DEC1C:
	movs r1, #0
	movs r3, #0
	ldr r0, _080DED3C
	mov sb, r0
_080DEC24:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEC30
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
_080DEC30:
	adds r3, #1
	cmp r3, #3
	ble _080DEC24
	movs r2, #0
	mov sl, r2
	movs r4, #0
	str r4, [sp, #4]
	movs r3, #0
	lsls r2, r1, #1
	lsls r1, r1, #4
	mov r8, r1
	ldr r1, _080DED40
	adds r0, r2, r1
	movs r7, #0
	ldrsh r6, [r0, r7]
	adds r5, r1, #0
	ldr r0, _080DED44
	adds r2, r2, r0
	adds r4, r0, #0
_080DEC56:
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r6, r0
	bge _080DEC68
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
_080DEC68:
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r7, #0
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bge _080DEC7E
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
_080DEC7E:
	adds r5, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #3
	ble _080DEC56
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrb r1, [r0, #0xc]
	movs r4, #0
	movs r2, #1
	movs r3, #7
_080DEC98:
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080DECA6
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080DECA6:
	lsrs r1, r1, #1
	subs r3, #1
	cmp r3, #0
	bge _080DEC98
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080DED3C
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrb r1, [r0, #0xc]
	movs r4, #0
	movs r2, #0
	movs r3, #0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DECE2
	cmp r5, #0
	beq _080DECFC
_080DECDC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080DECE2:
	lsrs r1, r1, #1
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, #1
	cmp r3, #7
	bgt _080DECFC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DECE2
	cmp r5, r4
	bne _080DECDC
_080DECFC:
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r0, r2
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080DED3C
	ldr r1, [r0]
	ldr r0, [r1, #0x1c]
	ldrb r4, [r0, #0xd]
	movs r5, #1
	movs r3, #1
	mov r6, sp
_080DED1A:
	ldr r0, [r1, #0x1c]
	lsls r2, r3, #4
	adds r0, r2, r0
	ldrb r0, [r0, #0xd]
	cmp r4, r0
	bhs _080DED48
	strb r3, [r6]
	ldr r0, [r1, #0x1c]
	adds r0, r2, r0
	ldrb r4, [r0, #0xd]
	movs r5, #1
	b _080DED58
	.align 2, 0
_080DED34: .4byte 0x02039BC0
_080DED38: .4byte 0x02039BC5
_080DED3C: .4byte 0x02039BD4
_080DED40: .4byte 0x02039BA0
_080DED44: .4byte 0x02039BB8
_080DED48:
	cmp r4, r0
	bne _080DED58
	mov r2, sp
	adds r0, r2, r5
	strb r3, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080DED58:
	adds r3, #1
	cmp r3, #3
	ble _080DED1A
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl __modsi3
	add r0, sp
	ldrb r7, [r0]
	movs r2, #0x80
	movs r3, #0
	ldr r5, _080DEDDC
	ldr r0, [r5]
	ldr r0, [r0, #0x1c]
	lsls r1, r7, #4
	adds r0, r1, r0
	ldrb r0, [r0, #0xd]
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, sb
	lsls r6, r0, #0x18
	cmp r4, #0
	bne _080DEDA4
_080DED8E:
	lsrs r2, r2, #1
	adds r3, #1
	cmp r3, #7
	bgt _080DEDA4
	ldr r0, [r5]
	ldr r0, [r0, #0x1c]
	adds r0, r1, r0
	ldrb r4, [r0, #0xd]
	ands r4, r2
	cmp r4, #0
	beq _080DED8E
_080DEDA4:
	mov r0, sl
	bl ContestLiveUpdates_BeforeInterview_1
	ldr r0, [sp, #4]
	bl ContestLiveUpdates_BeforeInterview_2
	lsrs r0, r6, #0x18
	bl ContestLiveUpdates_BeforeInterview_3
	ldr r0, _080DEDDC
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrh r0, [r0, #0xa]
	bl ContestLiveUpdates_BeforeInterview_4
	adds r0, r4, #0
	adds r1, r7, #0
	bl ContestLiveUpdates_BeforeInterview_5
_080DEDCC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEDDC: .4byte 0x02039BD4
	thumb_func_end sub_080DEC00

	thumb_func_start ContestDebugToggleBitfields
ContestDebugToggleBitfields: @ 0x080DEDE0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _080DEE00
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r4, r0, #0
	cmp r1, #0
	bne _080DEE08
	cmp r3, #0
	bne _080DEE04
	movs r0, #2
	b _080DEE0A
	.align 2, 0
_080DEE00: .4byte 0x02000000
_080DEE04:
	movs r0, #3
	b _080DEE0A
_080DEE08:
	movs r0, #0
_080DEE0A:
	strb r0, [r2]
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEE22
	bl DrawContestantWindowText
	bl SwapMoveDescAndContestTilemaps
	b _080DEE26
_080DEE22:
	bl ContestDebugPrintBitStrings
_080DEE26:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ContestDebugToggleBitfields

	thumb_func_start ContestDebugPrintBitStrings
ContestDebugPrintBitStrings: @ 0x080DEE2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _080DEF28
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEE42
	b _080DEFD4
_080DEE42:
	ldr r0, _080DEF2C
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080DEE58
	b _080DEFD4
_080DEE58:
	movs r7, #0
	add r2, sp, #0x14
	mov sl, r2
_080DEE5E:
	adds r0, r7, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	adds r0, r7, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl FillWindowPixelBuffer
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEE5E
	ldr r0, _080DEF2C
	movs r4, #0xd0
	lsls r4, r4, #9
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	bne _080DEF3C
	movs r7, #0
	mov sb, sl
_080DEE8E:
	mov r0, sp
	ldr r1, _080DEF30
	bl StringCopy
	adds r6, r0, #0
	ldr r0, _080DEF34
	adds r0, r7, r0
	ldrb r0, [r0]
	mov r1, sp
	bl Contest_PrintTextToBg0WindowStd
	ldr r0, _080DEF38
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	lsls r0, r7, #4
	adds r0, r0, r1
	ldrb r5, [r0, #0xc]
	movs r4, #7
	adds r0, r7, #1
	mov r8, r0
_080DEEB6:
	movs r1, #1
	ands r1, r5
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	adds r6, r0, #0
	lsrs r5, r5, #1
	lsls r0, r4, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	bgt _080DEEB6
	movs r4, #0
	ldr r6, _080DEF34
	mov r3, sl
_080DEEE2:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	adds r2, r3, r0
	mov r4, sp
	adds r1, r4, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #4
	ble _080DEEE2
	mov r0, sb
	adds r1, r0, r5
	movs r0, #0xff
	strb r0, [r1]
	adds r4, r7, r6
	ldrb r0, [r4]
	mov r1, sb
	bl Contest_PrintTextToBg0WindowStd
	ldrb r0, [r4]
	adds r0, #4
	mov r2, sp
	adds r1, r2, r5
	bl Contest_PrintTextToBg0WindowStd
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEE8E
	b _080DEFD0
	.align 2, 0
_080DEF28: .4byte 0x02031F75
_080DEF2C: .4byte 0x02000000
_080DEF30: .4byte 0x085CC49D
_080DEF34: .4byte 0x02039BC6
_080DEF38: .4byte 0x02039BD4
_080DEF3C:
	movs r7, #0
	mov r0, sp
	adds r0, #2
	str r0, [sp, #0x28]
	mov sb, sl
_080DEF46:
	mov r0, sp
	ldr r1, _080DEFE4
	bl StringCopy
	ldr r0, _080DEFE8
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	lsls r0, r7, #4
	adds r0, r0, r1
	ldrb r5, [r0, #0xd]
	ldr r6, [sp, #0x28]
	movs r4, #7
	adds r1, r7, #1
	mov r8, r1
_080DEF62:
	movs r1, #1
	ands r1, r5
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	adds r6, r0, #0
	lsrs r5, r5, #1
	lsls r0, r4, #0x18
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _080DEF62
	movs r4, #0
	ldr r6, _080DEFEC
	mov r3, sl
_080DEF8E:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	adds r2, r3, r0
	mov r4, sp
	adds r1, r4, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #4
	ble _080DEF8E
	mov r0, sb
	adds r1, r0, r5
	movs r0, #0xff
	strb r0, [r1]
	adds r4, r7, r6
	ldrb r0, [r4]
	mov r1, sb
	bl Contest_PrintTextToBg0WindowStd
	ldrb r0, [r4]
	adds r0, #4
	mov r2, sp
	adds r1, r2, r5
	bl Contest_PrintTextToBg0WindowStd
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEF46
_080DEFD0:
	bl SwapMoveDescAndContestTilemaps
_080DEFD4:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEFE4: .4byte 0x085CC4A0
_080DEFE8: .4byte 0x02039BD4
_080DEFEC: .4byte 0x02039BC6
	thumb_func_end ContestDebugPrintBitStrings

