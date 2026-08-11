.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified








































	thumb_func_start sub_08017484
sub_08017484: @ 0x08017484
	push {r4, r5, r6, lr}
	adds r6, r3, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x13
	adds r5, r0, r2
	ldrb r1, [r5, #0xa]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08017500
	cmp r4, #0
	bne _08017500
	ldr r4, _080174E0
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, r4, #0
	bl StringCopy
	adds r0, r5, #2
	bl ReadAsU16
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl PlayerHasMetTrainerBefore
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x45
	bne _080174EC
	ldr r0, _080174E4
	ldr r3, _080174E8
	lsls r1, r6, #2
	lsls r2, r2, #3
	adds r1, r1, r2
	adds r1, r1, r3
	ldr r1, [r1]
	bl StringExpandPlaceholders
	movs r0, #2
	b _080175DE
	.align 2, 0
_080174E0: .4byte 0x02021C40
_080174E4: .4byte 0x02021C7C
_080174E8: .4byte 0x082C0FD0
_080174EC:
	ldr r0, _080174FC
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl UR_PrintFieldMessage
	movs r0, #1
	b _080175DE
	.align 2, 0
_080174FC: .4byte 0x082C0CD8
_08017500:
	ldr r0, _08017530
	adds r1, r5, #0
	adds r1, #0x10
	bl StringCopy
	cmp r4, #0
	beq _08017518
	adds r0, r5, r4
	ldrb r0, [r0, #3]
	lsrs r6, r0, #3
	movs r0, #1
	ands r6, r0
_08017518:
	ldrb r0, [r5, #0xa]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x19
	movs r1, #0x3f
	ands r1, r0
	cmp r1, #4
	beq _08017564
	cmp r1, #4
	bgt _08017534
	cmp r1, #1
	beq _0801753E
	b _080175D4
	.align 2, 0
_08017530: .4byte 0x02021C40
_08017534:
	cmp r1, #5
	beq _08017584
	cmp r1, #8
	beq _080175A8
	b _080175D4
_0801753E:
	ldr r5, _0801755C
	ldr r4, _08017560
	bl Random
	lsls r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r0
	lsrs r1, r1, #0xe
	lsls r0, r6, #4
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r1, [r1]
	b _080175C2
	.align 2, 0
_0801755C: .4byte 0x02021C7C
_08017560: .4byte 0x082C1498
_08017564:
	ldr r5, _0801757C
	ldr r4, _08017580
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	lsls r1, r6, #4
	b _080175BC
	.align 2, 0
_0801757C: .4byte 0x02021C7C
_08017580: .4byte 0x082C1668
_08017584:
	ldr r5, _080175A0
	ldr r4, _080175A4
	bl Random
	lsls r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r0
	lsrs r1, r1, #0xe
	lsls r0, r6, #4
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r1, [r1]
	b _080175C2
	.align 2, 0
_080175A0: .4byte 0x02021C7C
_080175A4: .4byte 0x082C1564
_080175A8:
	ldr r5, _080175CC
	ldr r4, _080175D0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	lsls r1, r6, #3
_080175BC:
	adds r0, r0, r1
	adds r0, r0, r4
	ldr r1, [r0]
_080175C2:
	adds r0, r5, #0
	bl StringExpandPlaceholders
	b _080175DC
	.align 2, 0
_080175CC: .4byte 0x02021C7C
_080175D0: .4byte 0x082C15E8
_080175D4:
	ldr r0, _080175E4
	ldr r1, _080175E8
	bl StringExpandPlaceholders
_080175DC:
	movs r0, #0
_080175DE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080175E4: .4byte 0x02021C7C
_080175E8: .4byte 0x082C0FE0
	thumb_func_end sub_08017484

	thumb_func_start nullsub_89
nullsub_89: @ 0x080175EC
	bx lr
	.align 2, 0
	thumb_func_end nullsub_89

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

	thumb_func_start sub_080177B8
sub_080177B8: @ 0x080177B8
	lsls r0, r0, #5
	adds r0, r0, r1
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x1f
	lsrs r0, r0, #0x1f
	bx lr
	thumb_func_end sub_080177B8

	thumb_func_start sub_080177C4
sub_080177C4: @ 0x080177C4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r1, r0
	bne _08017804
	movs r4, #0
	b _080177EE
_080177D4:
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _080177FC
	adds r0, r0, r1
	movs r1, #0x41
	bl GetMonData3
	adds r1, r0, #0
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r1, r0
	beq _08017834
	adds r4, #1
_080177EE:
	ldr r0, _08017800
	ldrb r0, [r0]
	cmp r4, r0
	blt _080177D4
	movs r0, #2
	b _08017850
	.align 2, 0
_080177FC: .4byte 0x02024190
_08017800: .4byte 0x0202418D
_08017804:
	movs r4, #0
	ldr r0, _08017838
	ldrb r0, [r0]
	cmp r4, r0
	bge _0801784E
	ldr r6, _0801783C
_08017810:
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _08017840
	adds r0, r0, r1
	movs r1, #0x41
	bl GetMonData3
	adds r1, r0, #0
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r6
	ldrb r0, [r1, #6]
	cmp r0, r5
	beq _08017834
	ldrb r0, [r1, #7]
	cmp r0, r5
	bne _08017844
_08017834:
	movs r0, #0
	b _08017850
	.align 2, 0
_08017838: .4byte 0x0202418D
_0801783C: .4byte 0x082F0D54
_08017840: .4byte 0x02024190
_08017844:
	adds r4, #1
	ldr r0, _08017858
	ldrb r0, [r0]
	cmp r4, r0
	blt _08017810
_0801784E:
	movs r0, #1
_08017850:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08017858: .4byte 0x0202418D
	thumb_func_end sub_080177C4

	thumb_func_start sub_0801785C
sub_0801785C: @ 0x0801785C
	push {lr}
	adds r3, r0, #0
	cmp r1, #0x44
	beq _08017898
	cmp r1, #0x44
	bgt _0801786E
	cmp r1, #0x41
	beq _08017878
	b _080178B6
_0801786E:
	cmp r1, #0x45
	beq _08017888
	cmp r1, #0x48
	beq _080178A8
	b _080178B6
_08017878:
	ldr r0, _08017884
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	b _0801789A
	.align 2, 0
_08017884: .4byte 0x082C1224
_08017888:
	ldr r0, _08017894
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	b _0801789A
	.align 2, 0
_08017894: .4byte 0x082C13C4
_08017898:
	ldr r1, _080178A4
_0801789A:
	adds r0, r3, #0
	bl StringExpandPlaceholders
	b _080178B6
	.align 2, 0
_080178A4: .4byte 0x082C1998
_080178A8:
	ldr r0, _080178BC
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl StringExpandPlaceholders
_080178B6:
	pop {r0}
	bx r0
	.align 2, 0
_080178BC: .4byte 0x082C127C
	thumb_func_end sub_0801785C

	thumb_func_start sub_080178C0
sub_080178C0: @ 0x080178C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r6, r4, #0
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r2, _080178F4
	movs r0, #1
	adds r1, r3, #0
	eors r1, r0
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #0x13]
	cmp r4, #0x44
	beq _08017914
	cmp r4, #0x44
	bgt _080178F8
	cmp r4, #0x41
	beq _080178FE
	b _08017954
	.align 2, 0
_080178F4: .4byte 0x020226A0
_080178F8:
	cmp r6, #0x45
	beq _08017938
	b _08017954
_080178FE:
	ldr r2, _08017910
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r1, r1, r0
	b _08017926
	.align 2, 0
_08017910: .4byte 0x082C1188
_08017914:
	ldr r2, _08017934
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r2, #8
_08017926:
	adds r1, r1, r2
	ldr r1, [r1]
	adds r0, r5, #0
	bl StringCopy
	b _08017954
	.align 2, 0
_08017934: .4byte 0x082C1188
_08017938:
	ldr r2, _0801795C
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r2, #4
	adds r1, r1, r2
	ldr r1, [r1]
	adds r0, r5, #0
	bl StringCopy
_08017954:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801795C: .4byte 0x082C1188
	thumb_func_end sub_080178C0
