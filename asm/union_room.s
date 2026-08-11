.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified




	thumb_func_start var_800D_set_xB
var_800D_set_xB: @ 0x08016398
	push {lr}
	bl InUnionRoom
	cmp r0, #1
	bne _080163A8
	ldr r1, _080163AC
	movs r0, #0xb
	strh r0, [r1]
_080163A8:
	pop {r0}
	bx r0
	.align 2, 0
_080163AC: .4byte 0x02037290
	thumb_func_end var_800D_set_xB

	thumb_func_start sub_080163B0
sub_080163B0: @ 0x080163B0
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r3, _080163EC
	ldrh r5, [r3, #0x12]
	adds r4, r5, #0
	cmp r4, #0
	beq _080163E4
	ldrh r0, [r3, #0x10]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xbc
	lsls r0, r0, #6
	cmp r1, r0
	bne _080163E4
	adds r0, r2, #0
	adds r0, #0x82
	strh r5, [r0]
	cmp r4, #0x44
	bne _080163E4
	ldrh r1, [r3, #0x14]
	adds r0, #2
	strh r1, [r0]
	ldrh r1, [r3, #0x16]
	adds r0, #2
	strh r1, [r0]
_080163E4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080163EC: .4byte 0x03003130
	thumb_func_end sub_080163B0

	thumb_func_start sub_080163F0
sub_080163F0: @ 0x080163F0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x82
	ldrh r0, [r5]
	cmp r0, #0
	beq _08016440
	ldr r0, _08016424
	ldr r1, _08016428
	adds r1, #0x2f
	ldrb r1, [r1]
	adds r2, r5, #0
	adds r3, r4, #0
	bl sub_08017960
	cmp r0, #0
	beq _08016440
	cmp r0, #1
	bne _08016430
	movs r0, #0x23
	strb r0, [r4, #0x14]
	ldr r1, _0801642C
	ldrh r0, [r5]
	strb r0, [r1]
	movs r0, #0
	b _08016442
	.align 2, 0
_08016424: .4byte 0x02021C7C
_08016428: .4byte 0x020226A0
_0801642C: .4byte 0x020228E0
_08016430:
	cmp r0, #2
	bne _08016440
	movs r0, #0x24
	strb r0, [r4, #0x14]
	bl SetCloseLinkCallback
	movs r0, #0
	b _08016442
_08016440:
	movs r0, #1
_08016442:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_080163F0

	thumb_func_start sub_08016448
sub_08016448: @ 0x08016448
	push {r4, r5, lr}
	ldr r5, _08016480
	movs r0, #0xff
	strb r0, [r5]
	ldr r0, _08016484
	movs r1, #0
	bl CreateTask
	ldr r4, _08016488
	movs r0, #0x89
	lsls r0, r0, #2
	bl AllocZeroed
	str r0, [r4]
	ldr r1, _0801648C
	str r0, [r1]
	movs r1, #0
	strb r1, [r0, #0x14]
	strb r1, [r0, #0x16]
	strh r1, [r0, #0x10]
	strh r1, [r0, #0x12]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016480: .4byte 0x020228D8
_08016484: .4byte 0x08016491
_08016488: .4byte 0x020228E4
_0801648C: .4byte 0x03000DA8
	thumb_func_end sub_08016448

	thumb_func_start sub_08016490
sub_08016490: @ 0x08016490
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080164AC
	ldr r4, [r0]
	ldrb r0, [r4, #0x14]
	cmp r0, #4
	bls _080164A2
	b _080165D8
_080164A2:
	lsls r0, r0, #2
	ldr r1, _080164B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080164AC: .4byte 0x020228E4
_080164B0: .4byte 0x080164B4
_080164B4: @ jump table
	.4byte _080164C8 @ case 0
	.4byte _080164CE @ case 1
	.4byte _080164F0 @ case 2
	.4byte _08016540 @ case 3
	.4byte _080165A4 @ case 4
_080164C8:
	movs r0, #1
	strb r0, [r4, #0x14]
	b _080165D8
_080164CE:
	movs r0, #0xc
	movs r1, #0
	movs r2, #0
	bl SetHostRfuGameData
	bl sub_0800AF5C
	bl OpenLink
	bl InitializeRfuLinkManager_EnterUnionRoom
	movs r0, #1
	bl RfuSetIgnoreError
	movs r0, #2
	strb r0, [r4, #0x14]
	b _080165D8
_080164F0:
	movs r0, #0x70
	bl AllocZeroed
	str r0, [r4, #4]
	movs r1, #4
	bl sub_080170B0
	movs r0, #0x70
	bl AllocZeroed
	str r0, [r4, #0xc]
	movs r1, #4
	bl sub_080170B0
	movs r0, #0x80
	lsls r0, r0, #1
	bl AllocZeroed
	str r0, [r4]
	movs r1, #8
	bl sub_08017044
	movs r0, #0x20
	bl AllocZeroed
	str r0, [r4, #8]
	movs r1, #1
	bl sub_08017044
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #4]
	movs r2, #0xa
	bl sub_08016900
	adds r1, r4, #0
	adds r1, #0x20
	strb r0, [r1]
	movs r0, #3
	strb r0, [r4, #0x14]
	b _080165D8
_08016540:
	bl sub_08016610
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	blt _080165D8
	cmp r0, #2
	bgt _080165D8
	ldr r0, _0801658C
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080165D8
	movs r6, #0
_0801655A:
	ldr r0, [r4]
	lsls r5, r6, #5
	adds r1, r0, r5
	ldrb r0, [r1, #0x1a]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1e
	cmp r0, #1
	bne _08016582
	adds r0, r1, #2
	bl ReadAsU16
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4]
	adds r1, r1, r5
	adds r1, #0x10
	bl PlayerHasMetTrainerBefore
	cmp r0, #0
	bne _08016590
_08016582:
	adds r6, #1
	cmp r6, #7
	ble _0801655A
	b _080165D8
	.align 2, 0
_0801658C: .4byte 0x020228D8
_08016590:
	ldr r0, _080165A0
	ldr r1, [r4]
	adds r1, r1, r5
	adds r1, #0x10
	bl StringCopy
	b _080165D8
	.align 2, 0
_080165A0: .4byte 0x020228D8
_080165A4:
	ldr r0, [r4, #8]
	bl Free
	ldr r0, [r4]
	bl Free
	ldr r0, [r4, #0xc]
	bl Free
	ldr r0, [r4, #4]
	bl Free
	adds r0, r4, #0
	adds r0, #0x20
	ldrb r0, [r0]
	bl DestroyTask
	ldr r0, _080165E0
	ldr r0, [r0]
	bl Free
	bl LinkRfu_Shutdown
	adds r0, r5, #0
	bl DestroyTask
_080165D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080165E0: .4byte 0x020228E4
	thumb_func_end sub_08016490

	thumb_func_start sp182_move_string
sp182_move_string: @ 0x080165E4
	push {r4, lr}
	ldr r4, _080165F4
	ldrb r0, [r4]
	cmp r0, #0xff
	bne _080165F8
	movs r0, #0
	b _08016606
	.align 2, 0
_080165F4: .4byte 0x020228D8
_080165F8:
	ldr r0, _0801660C
	adds r1, r4, #0
	bl StringCopy
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #1
_08016606:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801660C: .4byte 0x02021C40
	thumb_func_end sp182_move_string

	thumb_func_start sub_08016610
sub_08016610: @ 0x08016610
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _08016664
	ldr r4, [r0]
	movs r7, #0
	movs r6, #0
	movs r5, #0
_08016622:
	ldr r0, [r4, #0xc]
	adds r0, r0, r5
	ldr r1, _08016668
	bl sub_080170F4
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bne _0801666C
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #8]
	adds r1, r1, r5
	ldm r1!, {r2, r5, r6}
	stm r0!, {r2, r5, r6}
	ldm r1!, {r2, r5, r6}
	stm r0!, {r2, r5, r6}
	ldr r1, [r4, #8]
	movs r0, #0
	strh r0, [r1, #0x18]
	ldr r2, [r4, #8]
	ldrb r1, [r2, #0x1a]
	movs r5, #4
	rsbs r5, r5, #0
	adds r0, r5, #0
	ands r1, r0
	movs r0, #1
	orrs r1, r0
	strb r1, [r2, #0x1a]
	ldr r0, [r4, #8]
	strb r3, [r0, #0x1b]
	movs r0, #4
	b _080167A0
	.align 2, 0
_08016664: .4byte 0x020228E4
_08016668: .4byte 0x082C2364
_0801666C:
	adds r5, #0x1c
	adds r6, #1
	cmp r6, #3
	ble _08016622
	movs r6, #0
	mov sb, r6
_08016678:
	ldr r0, [r4]
	mov r1, sb
	lsls r5, r1, #5
	adds r2, r0, r5
	ldrb r0, [r2, #0x1a]
	lsls r0, r0, #0x1e
	mov r8, r5
	cmp r0, #0
	beq _0801676C
	ldr r1, [r4, #4]
	adds r0, r2, #0
	bl sub_080171A8
	adds r6, r0, #0
	cmp r6, #0xff
	beq _08016712
	ldr r0, [r4]
	adds r2, r0, r5
	ldrb r1, [r2, #0x1a]
	lsls r0, r1, #0x1e
	lsrs r0, r0, #0x1e
	cmp r0, #1
	bne _080166F0
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r6, r0, #2
	ldr r1, [r4, #4]
	adds r1, r1, r6
	adds r0, r2, #0
	bl sub_0801713C
	cmp r0, #0
	beq _080166D6
	ldr r1, [r4]
	ldr r0, [r4, #4]
	adds r1, r1, r5
	adds r0, r0, r6
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldm r0!, {r2, r3, r6}
	stm r1!, {r2, r3, r6}
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0x40
	strb r1, [r0, #0x1b]
	movs r7, #1
	b _08016708
_080166D6:
	ldr r0, [r4]
	adds r1, r0, r5
	ldrb r0, [r1, #0x1b]
	cmp r0, #0
	beq _08016708
	subs r0, #1
	strb r0, [r1, #0x1b]
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0, #0x1b]
	cmp r0, #0
	bne _08016708
	b _08016706
_080166F0:
	movs r3, #4
	rsbs r3, r3, #0
	adds r0, r3, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #0x1a]
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #0
	strb r1, [r0, #0x1b]
_08016706:
	movs r7, #2
_08016708:
	ldr r0, [r4]
	add r0, r8
	movs r1, #0
	strh r1, [r0, #0x18]
	b _0801676C
_08016712:
	ldr r0, [r4]
	adds r1, r0, r5
	ldrb r0, [r1, #0x1a]
	lsls r2, r0, #0x1e
	lsrs r0, r2, #0x1e
	cmp r0, #2
	beq _0801674C
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	ldr r0, [r4]
	adds r2, r0, r5
	ldrh r1, [r2, #0x18]
	ldr r0, _08016748
	cmp r1, r0
	bls _0801676C
	ldrb r0, [r2, #0x1a]
	movs r5, #4
	rsbs r5, r5, #0
	adds r1, r5, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x1a]
	movs r7, #2
	b _0801676C
	.align 2, 0
_08016748: .4byte 0x00000257
_0801674C:
	lsrs r0, r2, #0x1e
	cmp r0, #2
	bne _0801676C
	ldrh r0, [r1, #0x18]
	adds r0, #1
	strh r0, [r1, #0x18]
	ldr r0, [r4]
	adds r2, r0, r5
	ldrh r1, [r2, #0x18]
	ldr r0, _080167AC
	cmp r1, r0
	bls _0801676C
	adds r0, r2, #0
	movs r1, #1
	bl sub_08017044
_0801676C:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #7
	bhi _0801677C
	b _08016678
_0801677C:
	movs r5, #0
	movs r6, #3
_08016780:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	adds r1, r1, r5
	movs r2, #8
	bl sub_080171F8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _08016796
	movs r7, #1
_08016796:
	adds r5, #0x1c
	subs r6, #1
	cmp r6, #0
	bge _08016780
	adds r0, r7, #0
_080167A0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080167AC: .4byte 0x00000383
	thumb_func_end sub_08016610

	thumb_func_start sub_080167B0
sub_080167B0: @ 0x080167B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r0, r0, #2
	add r0, sl
	lsls r0, r0, #3
	ldr r1, _080168A0
	adds r6, r0, r1
	movs r7, #0
	mov r0, sp
	adds r0, #0x10
	str r0, [sp, #0x18]
_080167D4:
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	mov r0, sp
	ldr r1, [sp, #0x18]
	bl Rfu_GetCompatiblePlayerData
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, sp
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x19
	mov r2, sl
	lsls r1, r2, #2
	add r1, sl
	lsls r1, r1, #3
	ldr r3, _080168A4
	adds r1, r1, r3
	movs r5, #0x10
	ldrsh r1, [r1, r5]
	bl IsPartnerActivityAcceptable
	cmp r0, #0
	bne _08016810
	mov r1, sp
	ldr r0, _080168A8
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
_08016810:
	mov r0, sp
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #1
	beq _08016828
	mov r1, sp
	ldr r0, _080168A8
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
_08016828:
	cmp r4, #0
	bne _080168AC
	lsls r0, r7, #3
	mov r8, r0
	adds r1, r7, #1
	mov sb, r1
	cmp r7, #0
	ble _08016868
	movs r2, #0
	str r2, [sp, #0x1c]
	adds r4, r7, #0
_0801683E:
	ldr r0, [r6, #4]
	ldr r3, [sp, #0x1c]
	adds r0, r0, r3
	mov r1, sp
	bl sub_080170F4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801685C
	mov r1, sp
	ldr r0, _080168A8
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
_0801685C:
	ldr r5, [sp, #0x1c]
	adds r5, #0x1c
	str r5, [sp, #0x1c]
	subs r4, #1
	cmp r4, #0
	bne _0801683E
_08016868:
	ldr r1, [r6, #4]
	mov r0, r8
	subs r4, r0, r7
	lsls r4, r4, #2
	adds r1, r1, r4
	mov r0, sp
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r6, #4]
	adds r0, r0, r4
	ldr r1, _080168A8
	bl sub_080170F4
	ldr r3, [r6, #4]
	adds r3, r3, r4
	movs r2, #1
	ands r2, r0
	ldrb r0, [r3, #0x18]
	movs r4, #2
	rsbs r4, r4, #0
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #0x18]
	b _080168E4
	.align 2, 0
_080168A0: .4byte 0x03005B68
_080168A4: .4byte 0x03005B60
_080168A8: .4byte 0x082C2364
_080168AC:
	ldr r1, [r6]
	lsls r4, r7, #3
	subs r4, r4, r7
	lsls r4, r4, #2
	adds r1, r1, r4
	mov r0, sp
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r1, _080168FC
	bl sub_080170F4
	ldr r3, [r6]
	adds r3, r3, r4
	movs r2, #1
	ands r2, r0
	ldrb r0, [r3, #0x18]
	movs r4, #2
	rsbs r4, r4, #0
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #0x18]
	adds r7, #1
	mov sb, r7
_080168E4:
	mov r7, sb
	cmp r7, #3
	bgt _080168EC
	b _080167D4
_080168EC:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080168FC: .4byte 0x082C2364
	thumb_func_end sub_080167B0

	thumb_func_start sub_08016900
sub_08016900: @ 0x08016900
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, _0801692C
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r2, _08016930
	adds r3, r1, r2
	str r4, [r3]
	str r5, [r3, #4]
	adds r2, r2, r1
	strh r6, [r2, #8]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801692C: .4byte 0x080167B1
_08016930: .4byte 0x03005B68
	thumb_func_end sub_08016900

	thumb_func_start sub_08016934
sub_08016934: @ 0x08016934
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r0, r0, #2
	add r0, sl
	lsls r0, r0, #3
	ldr r1, _08016A20
	adds r6, r0, r1
	movs r3, #0
_08016952:
	lsls r4, r3, #3
	subs r0, r4, r3
	lsls r5, r0, #2
	ldr r0, [r6]
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0x10
	lsls r2, r3, #0x18
	lsrs r2, r2, #0x18
	str r3, [sp]
	bl Rfu_GetCompatiblePlayerData
	ldr r0, [r6]
	adds r0, r0, r5
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x19
	mov r2, sl
	lsls r1, r2, #2
	add r1, sl
	lsls r1, r1, #3
	ldr r7, _08016A24
	adds r1, r1, r7
	movs r2, #0xc
	ldrsh r1, [r1, r2]
	bl IsPartnerActivityAcceptable
	mov r8, r4
	ldr r3, [sp]
	cmp r0, #0
	bne _0801699E
	ldr r1, [r6]
	adds r1, r1, r5
	ldr r0, _08016A28
	ldm r0!, {r2, r4, r7}
	stm r1!, {r2, r4, r7}
	ldm r0!, {r2, r4, r7}
	stm r1!, {r2, r4, r7}
_0801699E:
	adds r4, r3, #1
	mov sb, r4
	cmp r3, #0
	ble _080169E2
	str r5, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	adds r4, r3, #0
_080169AE:
	ldr r1, [r6]
	ldr r7, [sp, #8]
	adds r0, r1, r7
	ldr r2, [sp, #4]
	adds r1, r1, r2
	str r3, [sp]
	bl sub_080170F4
	lsls r0, r0, #0x18
	ldr r3, [sp]
	cmp r0, #0
	bne _080169D6
	ldr r1, [r6]
	ldr r5, [sp, #4]
	adds r1, r1, r5
	ldr r0, _08016A28
	ldm r0!, {r2, r5, r7}
	stm r1!, {r2, r5, r7}
	ldm r0!, {r2, r5, r7}
	stm r1!, {r2, r5, r7}
_080169D6:
	ldr r7, [sp, #8]
	adds r7, #0x1c
	str r7, [sp, #8]
	subs r4, #1
	cmp r4, #0
	bne _080169AE
_080169E2:
	mov r0, r8
	subs r4, r0, r3
	lsls r4, r4, #2
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r1, _08016A28
	bl sub_080170F4
	ldr r3, [r6]
	adds r3, r3, r4
	movs r2, #1
	ands r2, r0
	ldrb r0, [r3, #0x18]
	movs r4, #2
	rsbs r4, r4, #0
	adds r1, r4, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #0x18]
	mov r3, sb
	cmp r3, #3
	ble _08016952
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016A20: .4byte 0x03005B68
_08016A24: .4byte 0x03005B60
_08016A28: .4byte 0x082C2364
	thumb_func_end sub_08016934

	thumb_func_start sub_08016A2C
sub_08016A2C: @ 0x08016A2C
	push {lr}
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #7
	bne _08016A3C
	ldrb r1, [r0]
	movs r0, #0x20
	b _08016A44
_08016A3C:
	cmp r1, #8
	bne _08016A4E
	ldrb r1, [r0]
	movs r0, #0x10
_08016A44:
	ands r0, r1
	cmp r0, #0
	beq _08016A4E
	movs r0, #1
	b _08016A50
_08016A4E:
	movs r0, #0
_08016A50:
	pop {r1}
	bx r1
	thumb_func_end sub_08016A2C

	thumb_func_start sub_08016A54
sub_08016A54: @ 0x08016A54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _08016AC8
	adds r4, r1, r0
	movs r6, #0
	subs r0, #8
	movs r5, #0
	adds r1, r1, r0
	mov r8, r1
_08016A72:
	ldr r0, [r4]
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0x10
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	bl Rfu_GetWonderDistributorPlayerData
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08016A96
	ldr r0, [r4]
	adds r0, r0, r5
	mov r2, r8
	movs r3, #0xc
	ldrsh r1, [r2, r3]
	bl sub_08016A2C
_08016A96:
	ldr r0, [r4]
	adds r0, r0, r5
	ldr r1, _08016ACC
	bl sub_080170F4
	ldr r3, [r4]
	adds r3, r3, r5
	movs r2, #1
	ands r2, r0
	ldrb r0, [r3, #0x18]
	movs r7, #2
	rsbs r7, r7, #0
	adds r1, r7, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3, #0x18]
	adds r5, #0x1c
	adds r6, #1
	cmp r6, #3
	ble _08016A72
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016AC8: .4byte 0x03005B68
_08016ACC: .4byte 0x082C2364
	thumb_func_end sub_08016A54

	thumb_func_start sub_08016AD0
sub_08016AD0: @ 0x08016AD0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08016AF8
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #3
	ldr r1, _08016AFC
	adds r3, r2, r1
	str r4, [r3]
	adds r1, r1, r2
	strh r5, [r1, #4]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08016AF8: .4byte 0x08016935
_08016AFC: .4byte 0x03005B68
	thumb_func_end sub_08016AD0

	thumb_func_start sub_08016B00
sub_08016B00: @ 0x08016B00
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08016B28
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #3
	ldr r1, _08016B2C
	adds r3, r2, r1
	str r4, [r3]
	adds r1, r1, r2
	strh r5, [r1, #4]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08016B28: .4byte 0x08016A55
_08016B2C: .4byte 0x03005B68
	thumb_func_end sub_08016B00

	thumb_func_start sub_08016B30
sub_08016B30: @ 0x08016B30
	push {r4, lr}
	adds r4, r0, #0
	bl LoadMessageBoxAndBorderGfx
	movs r0, #0
	movs r1, #1
	bl DrawDialogueFrame
	ldr r0, _08016B58
	adds r1, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	movs r1, #1
	bl AddTextPrinterWithCustomSpeedForMessage
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08016B58: .4byte 0x02021C7C
	thumb_func_end sub_08016B30

	thumb_func_start sub_08016B5C
sub_08016B5C: @ 0x08016B5C
	push {lr}
	bl RunTextPrintersAndIsPrinter0Active
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08016B6C
	movs r0, #0
	b _08016B6E
_08016B6C:
	movs r0, #1
_08016B6E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08016B5C

	thumb_func_start PrintOnTextbox
PrintOnTextbox: @ 0x08016B74
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08016B86
	cmp r0, #1
	beq _08016BAC
	b _08016BBE
_08016B86:
	bl LoadMessageBoxAndBorderGfx
	movs r0, #0
	movs r1, #1
	bl DrawDialogueFrame
	ldr r0, _08016BA8
	adds r1, r5, #0
	bl StringExpandPlaceholders
	movs r0, #1
	bl AddTextPrinterForMessage_2
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08016BBE
	.align 2, 0
_08016BA8: .4byte 0x02021C7C
_08016BAC:
	bl RunTextPrintersAndIsPrinter0Active
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _08016BBE
	strb r0, [r4]
	movs r0, #1
	b _08016BC0
_08016BBE:
	movs r0, #0
_08016BC0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end PrintOnTextbox

	thumb_func_start sub_08016BC8
sub_08016BC8: @ 0x08016BC8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08016BDA
	cmp r0, #1
	beq _08016BF0
	b _08016C1C
_08016BDA:
	cmp r5, #0
	beq _08016BE4
	movs r0, #3
	rsbs r0, r0, #0
	b _08016C20
_08016BE4:
	bl DisplayYesNoMenuDefaultYes
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08016C1C
_08016BF0:
	cmp r5, #0
	beq _08016C02
	bl sub_08198D88
	movs r0, #0
	strb r0, [r4]
	movs r0, #3
	rsbs r0, r0, #0
	b _08016C20
_08016C02:
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08016C1C
	strb r5, [r4]
	adds r0, r1, #0
	b _08016C20
_08016C1C:
	movs r0, #2
	rsbs r0, r0, #0
_08016C20:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08016BC8

	thumb_func_start sub_08016C28
sub_08016C28: @ 0x08016C28
	push {r4, lr}
	sub sp, #8
	bl AddWindow
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0
	bl DrawStdWindowFrame
	adds r0, r4, #0
	movs r1, #0xff
	bl FillWindowPixelBuffer
	ldr r2, _08016C74
	movs r0, #1
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #1
	movs r3, #8
	bl sub_08016EA4
	adds r0, r4, #0
	movs r1, #2
	bl CopyWindowToVram
	adds r0, r4, #0
	bl PutWindowTilemap
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08016C74: .4byte 0x082C1D60
	thumb_func_end sub_08016C28

	thumb_func_start sub_08016C78
sub_08016C78: @ 0x08016C78
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl RemoveWindow
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08016C78

	thumb_func_start sub_08016C88
sub_08016C88: @ 0x08016C88
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	mov sb, r2
	adds r0, r3, #0
	ldrb r4, [r7]
	cmp r4, #0
	beq _08016CA4
	cmp r4, #1
	beq _08016CE4
	b _08016D4A
_08016CA4:
	bl AddWindow
	strb r0, [r5]
	ldrb r0, [r5]
	movs r1, #0
	bl DrawStdWindowFrame
	ldr r0, _08016CE0
	adds r2, r0, #0
	ldr r1, [sp, #0x1c]
	ldm r1!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r1!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldrb r1, [r5]
	strb r1, [r0, #0x10]
	movs r1, #0
	movs r2, #0
	bl ListMenuInit
	mov r1, sb
	strb r0, [r1]
	ldrb r0, [r5]
	movs r1, #1
	bl CopyWindowToVram
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	b _08016D4A
	.align 2, 0
_08016CE0: .4byte 0x03006050
_08016CE4:
	mov r3, sb
	ldrb r0, [r3]
	bl ListMenu_ProcessInput
	mov r8, r0
	ldr r0, _08016D1C
	ldrh r1, [r0, #0x2e]
	ands r4, r1
	cmp r4, #0
	beq _08016D20
	mov r4, sb
	ldrb r0, [r4]
	movs r1, #0
	movs r2, #0
	bl DestroyListMenuTask
	ldrb r0, [r5]
	movs r1, #1
	bl ClearStdWindowAndFrame
	ldrb r0, [r5]
	bl RemoveWindow
	movs r0, #0
	strb r0, [r7]
	mov r0, r8
	b _08016D4E
	.align 2, 0
_08016D1C: .4byte 0x03002360
_08016D20:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08016D4A
	mov r6, sb
	ldrb r0, [r6]
	movs r1, #0
	movs r2, #0
	bl DestroyListMenuTask
	ldrb r0, [r5]
	movs r1, #1
	bl ClearStdWindowAndFrame
	ldrb r0, [r5]
	bl RemoveWindow
	strb r4, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	b _08016D4E
_08016D4A:
	movs r0, #1
	rsbs r0, r0, #0
_08016D4E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08016C88

	thumb_func_start sub_08016D5C
sub_08016D5C: @ 0x08016D5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r5, r1, #0
	mov sl, r2
	mov r8, r3
	ldrb r4, [r6]
	cmp r4, #1
	beq _08016DC8
	cmp r4, #1
	bgt _08016D7E
	cmp r4, #0
	beq _08016D84
	b _08016E60
_08016D7E:
	cmp r4, #2
	beq _08016DD8
	b _08016E60
_08016D84:
	ldr r0, _08016DC0
	bl sub_08016C28
	mov r1, r8
	strb r0, [r1]
	ldr r0, [sp, #0x20]
	bl AddWindow
	strb r0, [r5]
	ldrb r0, [r5]
	movs r1, #0
	bl DrawStdWindowFrame
	ldr r0, _08016DC4
	adds r2, r0, #0
	ldr r1, [sp, #0x24]
	ldm r1!, {r3, r4, r7}
	stm r2!, {r3, r4, r7}
	ldm r1!, {r3, r4, r7}
	stm r2!, {r3, r4, r7}
	ldrb r1, [r5]
	strb r1, [r0, #0x10]
	movs r1, #0
	movs r2, #1
	bl ListMenuInit
	mov r1, sl
	strb r0, [r1]
	b _08016DD0
	.align 2, 0
_08016DC0: .4byte 0x082C224C
_08016DC4: .4byte 0x03006050
_08016DC8:
	ldrb r0, [r5]
	movs r1, #1
	bl CopyWindowToVram
_08016DD0:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _08016E60
_08016DD8:
	mov r3, sl
	ldrb r0, [r3]
	bl ListMenu_ProcessInput
	adds r1, r0, #0
	ldr r0, _08016E20
	ldrh r2, [r0, #0x2e]
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	beq _08016E60
	cmp r1, #8
	beq _08016DFA
	ands r4, r2
	mov sb, r4
	cmp r4, #0
	beq _08016E24
_08016DFA:
	mov r4, sl
	ldrb r0, [r4]
	movs r1, #0
	movs r2, #0
	bl DestroyListMenuTask
	ldrb r0, [r5]
	bl RemoveWindow
	mov r7, r8
	ldrb r0, [r7]
	bl sub_08016C78
	movs r0, #0
	strb r0, [r6]
	movs r0, #2
	rsbs r0, r0, #0
	b _08016E64
	.align 2, 0
_08016E20: .4byte 0x03002360
_08016E24:
	ldr r0, [sp, #0x28]
	bl sub_08017770
	adds r4, r0, #0
	cmp r4, #0
	blt _08016E5A
	mov r1, sl
	ldrb r0, [r1]
	movs r1, #0
	movs r2, #0
	bl DestroyListMenuTask
	ldrb r0, [r5]
	movs r1, #1
	bl ClearStdWindowAndFrame
	ldrb r0, [r5]
	bl RemoveWindow
	mov r3, r8
	ldrb r0, [r3]
	bl sub_08016C78
	mov r7, sb
	strb r7, [r6]
	adds r0, r4, #0
	b _08016E64
_08016E5A:
	movs r0, #7
	bl PlaySE
_08016E60:
	movs r0, #1
	rsbs r0, r0, #0
_08016E64:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08016D5C

	thumb_func_start sub_08016E74
sub_08016E74: @ 0x08016E74
	push {lr}
	sub sp, #0xc
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #0xc
	pop {r0}
	bx r0
	thumb_func_end sub_08016E74

	thumb_func_start sub_08016E98
sub_08016E98: @ 0x08016E98
	push {lr}
	bl ScriptContext_Enable
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08016E98

	thumb_func_start sub_08016EA4
sub_08016EA4: @ 0x08016EA4
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r5, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r2, [sp]
	mov r2, sp
	strb r0, [r2, #4]
	mov r0, sp
	strb r1, [r0, #5]
	strb r3, [r0, #6]
	strb r5, [r0, #7]
	strb r3, [r0, #8]
	strb r5, [r0, #9]
	ldrb r1, [r2, #0xc]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #0xc]
	ldr r2, _08016EF0
	ldrb r1, [r2]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	cmp r4, #6
	bls _08016EE6
	b _08017032
_08016EE6:
	lsls r0, r4, #2
	ldr r1, _08016EF4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08016EF0: .4byte 0x030030B4
_08016EF4: .4byte 0x08016EF8
_08016EF8: @ jump table
	.4byte _08016F14 @ case 0
	.4byte _08016F40 @ case 1
	.4byte _08016F6C @ case 2
	.4byte _08016F98 @ case 3
	.4byte _08016FC4 @ case 4
	.4byte _08016FF0 @ case 5
	.4byte _08017008 @ case 6
_08016F14:
	mov r0, sp
	movs r1, #0
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	mov r2, sp
	ldrb r1, [r2, #0xc]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldrb r1, [r2, #0xd]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #0xd]
	ands r0, r3
	movs r1, #0x30
	b _0801702E
_08016F40:
	mov r0, sp
	movs r1, #0
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	mov r2, sp
	ldrb r1, [r2, #0xc]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldrb r1, [r2, #0xd]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #0xd]
	ands r0, r3
	movs r1, #0x50
	b _0801702E
_08016F6C:
	mov r0, sp
	movs r1, #0
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	mov r2, sp
	ldrb r1, [r2, #0xc]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x60
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldrb r1, [r2, #0xd]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #0xd]
	ands r0, r3
	movs r1, #0x70
	b _0801702E
_08016F98:
	mov r0, sp
	movs r1, #0
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	mov r2, sp
	ldrb r1, [r2, #0xc]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldrb r1, [r2, #0xd]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #0xd]
	ands r0, r3
	movs r1, #0x30
	b _0801702E
_08016FC4:
	mov r0, sp
	movs r1, #0
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	mov r2, sp
	ldrb r1, [r2, #0xc]
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldrb r1, [r2, #0xd]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0xd]
	ands r0, r3
	movs r1, #0x30
	b _0801702E
_08016FF0:
	mov r0, sp
	movs r1, #0
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	mov r2, sp
	ldrb r1, [r2, #0xc]
	movs r4, #0xf
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0x70
	b _0801701E
_08017008:
	mov r0, sp
	movs r1, #0
	strb r1, [r0, #0xa]
	strb r1, [r0, #0xb]
	mov r2, sp
	ldrb r1, [r2, #0xc]
	movs r4, #0xf
	movs r3, #0xf
	adds r0, r3, #0
	ands r0, r1
	movs r1, #0xe0
_0801701E:
	orrs r0, r1
	strb r0, [r2, #0xc]
	mov r1, sp
	ldrb r0, [r1, #0xd]
	orrs r0, r4
	strb r0, [r1, #0xd]
	ands r0, r3
	movs r1, #0x90
_0801702E:
	orrs r0, r1
	strb r0, [r2, #0xd]
_08017032:
	mov r0, sp
	movs r1, #0xff
	movs r2, #0
	bl AddTextPrinter
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08016EA4

	thumb_func_start sub_08017044
sub_08017044: @ 0x08017044
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	beq _0801709C
	ldr r2, _080170AC
	mov r8, r2
	movs r5, #0
	mov sb, r5
	movs r6, #4
	rsbs r6, r6, #0
	mov ip, r6
	adds r2, r0, #0
	adds r2, #0x18
	adds r4, r0, #0
	movs r7, #0xff
	mov sl, r7
	adds r3, r1, #0
_08017070:
	adds r1, r4, #0
	mov r0, r8
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	mov r0, sl
	strh r0, [r2]
	ldrb r1, [r2, #2]
	mov r0, ip
	ands r0, r1
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r2, #2]
	mov r5, sb
	strb r5, [r2, #3]
	adds r2, #0x20
	adds r4, #0x20
	subs r3, #1
	cmp r3, #0
	bne _08017070
_0801709C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080170AC: .4byte 0x082C2364
	thumb_func_end sub_08017044

	thumb_func_start sub_080170B0
sub_080170B0: @ 0x080170B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _080170F0
	mov ip, r1
	movs r5, #2
	rsbs r5, r5, #0
	mov r8, r5
	adds r2, r0, #0
	adds r2, #0x18
	adds r3, r0, #0
	movs r4, #3
_080170C8:
	adds r1, r3, #0
	mov r0, ip
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldrb r1, [r2]
	mov r0, r8
	ands r0, r1
	strb r0, [r2]
	adds r2, #0x1c
	adds r3, #0x1c
	subs r4, #1
	cmp r4, #0
	bge _080170C8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080170F0: .4byte 0x082C2364
	thumb_func_end sub_080170B0

	thumb_func_start sub_080170F4
sub_080170F4: @ 0x080170F4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r2, #0
	adds r4, r5, #2
	adds r3, r6, #2
_08017100:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08017128
	adds r2, #1
	cmp r2, #1
	ble _08017100
	movs r2, #0
	adds r4, r5, #0
	adds r4, #0x10
	adds r3, r6, #0
	adds r3, #0x10
_0801711C:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	beq _0801712C
_08017128:
	movs r0, #1
	b _08017134
_0801712C:
	adds r2, #1
	cmp r2, #7
	ble _0801711C
	movs r0, #0
_08017134:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080170F4

	thumb_func_start sub_0801713C
sub_0801713C: @ 0x0801713C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldrb r3, [r5, #0xa]
	movs r0, #0x7f
	ldrb r2, [r6, #0xa]
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _080171A0
	movs r0, #0x80
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _080171A0
	movs r2, #0
	adds r4, r5, #4
	adds r3, r6, #4
_08017164:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080171A0
	adds r2, #1
	cmp r2, #3
	ble _08017164
	ldrh r2, [r5, #8]
	ldr r0, _0801719C
	ldrh r3, [r6, #8]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _080171A0
	ldrb r2, [r5, #9]
	movs r0, #0xfc
	ldrb r3, [r6, #9]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _080171A0
	movs r0, #0
	b _080171A2
	.align 2, 0
_0801719C: .4byte 0x000003FF
_080171A0:
	movs r0, #1
_080171A2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_0801713C

	thumb_func_start sub_080171A8
sub_080171A8: @ 0x080171A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r7, #0xff
	movs r6, #0
	adds r4, r1, #0
	adds r4, #0x18
	adds r5, r1, #0
_080171BA:
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080171E2
	mov r0, r8
	adds r1, r5, #0
	bl sub_080170F4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080171E2
	lsls r0, r6, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r4]
	movs r2, #2
	rsbs r2, r2, #0
	adds r1, r2, #0
	ands r0, r1
	strb r0, [r4]
_080171E2:
	adds r4, #0x1c
	adds r5, #0x1c
	adds r6, #1
	cmp r6, #3
	ble _080171BA
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080171A8

	thumb_func_start sub_080171F8
sub_080171F8: @ 0x080171F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r3, r0, #0
	mov r8, r1
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldrb r1, [r1, #0x18]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801726C
	movs r5, #0
	cmp r5, r6
	bge _0801726C
	movs r0, #4
	rsbs r0, r0, #0
	mov sb, r0
	movs r1, #2
	rsbs r1, r1, #0
	mov ip, r1
	adds r2, r3, #0
	adds r2, #0x18
	adds r1, r3, #0
_0801722A:
	ldrb r0, [r2, #2]
	movs r3, #3
	ands r3, r0
	cmp r3, #0
	bne _08017262
	mov r0, r8
	ldm r0!, {r4, r6, r7}
	stm r1!, {r4, r6, r7}
	ldm r0!, {r4, r6, r7}
	stm r1!, {r4, r6, r7}
	strh r3, [r2]
	ldrb r1, [r2, #2]
	mov r0, sb
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #2]
	movs r0, #0x40
	strb r0, [r2, #3]
	mov r0, r8
	ldrb r1, [r0, #0x18]
	mov r0, ip
	ands r0, r1
	mov r1, r8
	strb r0, [r1, #0x18]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	b _0801726E
_08017262:
	adds r2, #0x20
	adds r1, #0x20
	adds r5, #1
	cmp r5, r6
	blt _0801722A
_0801726C:
	movs r0, #0xff
_0801726E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080171F8

	thumb_func_start sub_0801727C
sub_0801727C: @ 0x0801727C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r4, r1, #0
	adds r5, r3, #0
	ldr r3, [sp, #0x2c]
	ldr r1, [sp, #0x30]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r6, _08017354
	adds r1, #1
	adds r0, r6, #0
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	ldr r1, _08017358
	adds r0, r6, #0
	bl StringAppend
	str r7, [sp]
	movs r0, #0
	str r0, [sp, #4]
	mov r0, r8
	movs r1, #1
	adds r2, r6, #0
	adds r3, r4, #0
	bl sub_08016EA4
	adds r4, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldrb r0, [r5, #0xa]
	lsls r0, r0, #0x19
	lsrs r2, r0, #0x19
	ldrb r1, [r5, #0x1a]
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bne _08017344
	movs r0, #0x40
	ands r2, r0
	cmp r2, #0
	bne _08017344
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, r6, #0
	movs r2, #5
	bl StringCopyN_Multibyte
	str r7, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r0, r8
	movs r1, #2
	adds r2, r6, #0
	adds r3, r4, #0
	bl sub_08016EA4
	ldrb r1, [r5, #2]
	ldrb r0, [r5, #3]
	lsls r0, r0, #8
	orrs r1, r0
	add r0, sp, #8
	movs r2, #2
	movs r3, #5
	bl ConvertIntToDecimalStringN
	ldr r1, _0801735C
	adds r0, r6, #0
	bl StringCopy
	adds r0, r6, #0
	add r1, sp, #8
	bl StringAppend
	adds r3, r4, #0
	adds r3, #0x38
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r7, [sp]
	mov r0, sb
	str r0, [sp, #4]
	mov r0, r8
	movs r1, #1
	adds r2, r6, #0
	bl sub_08016EA4
_08017344:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017354: .4byte 0x02021C7C
_08017358: .4byte 0x082C0644
_0801735C: .4byte 0x082C0648
	thumb_func_end sub_0801727C

	thumb_func_start sub_08017360
sub_08017360: @ 0x08017360
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r3, #0
	ldr r3, [sp, #0x2c]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	ldrb r1, [r5, #0x1a]
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bne _080173E6
	ldr r4, _080173F4
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, r4, #0
	movs r2, #5
	bl StringCopyN_Multibyte
	mov r0, r8
	str r0, [sp]
	str r7, [sp, #4]
	mov r0, sb
	movs r1, #2
	adds r2, r4, #0
	adds r3, r6, #0
	bl sub_08016EA4
	ldrb r1, [r5, #2]
	ldrb r0, [r5, #3]
	lsls r0, r0, #8
	orrs r1, r0
	add r0, sp, #8
	movs r2, #2
	movs r3, #5
	bl ConvertIntToDecimalStringN
	ldr r1, _080173F8
	adds r0, r4, #0
	bl StringCopy
	adds r0, r4, #0
	add r1, sp, #8
	bl StringAppend
	adds r3, r6, #0
	adds r3, #0x38
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r0, r8
	str r0, [sp]
	str r7, [sp, #4]
	mov r0, sb
	movs r1, #1
	adds r2, r4, #0
	bl sub_08016EA4
_080173E6:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080173F4: .4byte 0x02021C7C
_080173F8: .4byte 0x082C0648
	thumb_func_end sub_08017360

	thumb_func_start sub_080173FC
sub_080173FC: @ 0x080173FC
	push {r4, lr}
	sub sp, #4
	mov r4, sp
	adds r4, #2
	mov r0, sp
	adds r1, r4, #0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _08017434
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #8
	bne _08017434
	ldr r0, _08017430
	ldrb r0, [r0, #3]
	cmp r0, #2
	beq _0801742A
	cmp r0, #0
	bne _08017434
_0801742A:
	movs r0, #1
	b _08017436
	.align 2, 0
_08017430: .4byte 0x02037230
_08017434:
	movs r0, #0
_08017436:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080173FC

	thumb_func_start sub_08017440
sub_08017440: @ 0x08017440
	push {lr}
	cmp r0, #4
	beq _08017458
	cmp r0, #4
	ble _08017460
	cmp r0, #5
	beq _08017454
	cmp r0, #8
	beq _0801745C
	b _08017460
_08017454:
	movs r0, #1
	b _08017462
_08017458:
	movs r0, #2
	b _08017462
_0801745C:
	movs r0, #3
	b _08017462
_08017460:
	movs r0, #0
_08017462:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08017440

	thumb_func_start sub_08017468
sub_08017468: @ 0x08017468
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r4, #2
	bl ReadAsU16
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, #0x10
	adds r1, r4, #0
	bl PlayerHasMetTrainerBefore
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_08017468

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
	bl sub_08016B30
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
	bl sub_08016EA4
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
	bl sub_08016EA4
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
	bl sub_08016EA4
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
	bl sub_08016EA4
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

	thumb_func_start sub_08017960
sub_08017960: @ 0x08017960
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r2, #0
	adds r5, r3, #0
	movs r2, #0
	mov r8, r2
	ldrh r0, [r6]
	subs r0, #0x40
	cmp r0, #8
	bls _0801797A
	b _08017A82
_0801797A:
	lsls r0, r0, #2
	ldr r1, _08017984
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08017984: .4byte 0x08017988
_08017988: @ jump table
	.4byte _08017A78 @ case 0
	.4byte _080179AC @ case 1
	.4byte _08017A82 @ case 2
	.4byte _08017A82 @ case 3
	.4byte _080179E8 @ case 4
	.4byte _080179B4 @ case 5
	.4byte _08017A82 @ case 6
	.4byte _08017A82 @ case 7
	.4byte _08017A68 @ case 8
_080179AC:
	ldr r1, _080179B0
	b _08017A6A
	.align 2, 0
_080179B0: .4byte 0x082C0E1C
_080179B4:
	ldr r1, _080179B8
	b _08017A6A
	.align 2, 0
_080179B8: .4byte 0x082C0E40
_080179BC:
	adds r0, r5, #0
	adds r0, #0x6c
	ldrh r1, [r6, #4]
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	adds r0, r5, #0
	adds r0, #0x76
	ldrh r2, [r6, #2]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080179E4
	adds r1, r1, r2
	bl StringCopy
	ldrh r6, [r6, #2]
	mov r8, r6
	b _08017A20
	.align 2, 0
_080179E4: .4byte 0x082EA31C
_080179E8:
	adds r0, r5, #0
	adds r0, #0x58
	ldr r4, _08017A34
	ldrh r1, [r4, #0xc]
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r2, [r4, #0xa]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _08017A38
	adds r1, r1, r2
	bl StringCopy
	movs r4, #0
	ldr r0, _08017A3C
	ldr r1, [r0]
_08017A12:
	ldrh r0, [r1, #0x18]
	cmp r0, #2
	beq _080179BC
	adds r1, #0x20
	adds r4, #1
	cmp r4, #3
	ble _08017A12
_08017A20:
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r8, r0
	bne _08017A44
	ldr r1, _08017A40
	adds r0, r7, #0
	bl StringCopy
	b _08017A70
	.align 2, 0
_08017A34: .4byte 0x020228F4
_08017A38: .4byte 0x082EA31C
_08017A3C: .4byte 0x03007630
_08017A40: .4byte 0x082C0EA8
_08017A44:
	movs r4, #0
	adds r5, #0x58
_08017A48:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	adds r5, #0xa
	adds r4, #1
	cmp r4, #3
	ble _08017A48
	ldr r1, _08017A64
	adds r0, r7, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	b _08017A70
	.align 2, 0
_08017A64: .4byte 0x082C0E68
_08017A68:
	ldr r1, _08017A74
_08017A6A:
	adds r0, r7, #0
	bl StringExpandPlaceholders
_08017A70:
	movs r2, #1
	b _08017A82
	.align 2, 0
_08017A74: .4byte 0x082C0DEC
_08017A78:
	ldr r1, _08017A90
	adds r0, r7, #0
	bl StringExpandPlaceholders
	movs r2, #2
_08017A82:
	adds r0, r2, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017A90: .4byte 0x082C0ED4
	thumb_func_end sub_08017960

	thumb_func_start sub_08017A94
sub_08017A94: @ 0x08017A94
	push {lr}
	adds r2, r0, #0
	ldr r0, _08017AB4
	ldrh r1, [r0, #2]
	cmp r1, #0
	beq _08017AB8
	cmp r1, #0x51
	beq _08017AA8
	cmp r1, #0x52
	bne _08017AB8
_08017AA8:
	adds r0, r2, #0
	adds r0, #0x80
	strh r1, [r0]
	movs r0, #1
	b _08017ABA
	.align 2, 0
_08017AB4: .4byte 0x03003130
_08017AB8:
	movs r0, #0
_08017ABA:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08017A94

	thumb_func_start InUnionRoom
InUnionRoom: @ 0x08017AC0
	push {lr}
	movs r2, #0
	ldr r0, _08017AD8
	ldr r0, [r0]
	ldrh r1, [r0, #4]
	ldr r0, _08017ADC
	cmp r1, r0
	bne _08017AD2
	movs r2, #1
_08017AD2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_08017AD8: .4byte 0x03005AEC
_08017ADC: .4byte 0x00003C19
	thumb_func_end InUnionRoom

	thumb_func_start sub_08017AE0
sub_08017AE0: @ 0x08017AE0
	push {r4, r5, r6, lr}
	movs r6, #0
	movs r5, #0
	ldr r0, _08017B28
	ldrb r0, [r0]
	cmp r6, r0
	bge _08017B20
_08017AEE:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _08017B2C
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0x38
	bl GetMonData3
	cmp r0, #0x1e
	bhi _08017B16
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	movs r1, #0xce
	lsls r1, r1, #1
	cmp r0, r1
	beq _08017B16
	adds r6, #1
_08017B16:
	adds r5, #1
	ldr r0, _08017B28
	ldrb r0, [r0]
	cmp r5, r0
	blt _08017AEE
_08017B20:
	cmp r6, #1
	bgt _08017B30
	movs r0, #0
	b _08017B32
	.align 2, 0
_08017B28: .4byte 0x0202418D
_08017B2C: .4byte 0x02024190
_08017B30:
	movs r0, #1
_08017B32:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_08017AE0

	thumb_func_start sub_08017B38
sub_08017B38: @ 0x08017B38
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	str r1, [r0, #4]
	strh r1, [r0, #0xa]
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
	strh r1, [r0, #0x10]
	str r1, [r0, #0x14]
	bx lr
	thumb_func_end sub_08017B38

	thumb_func_start sub_08017B4C
sub_08017B4C: @ 0x08017B4C
	push {lr}
	ldr r0, _08017B58
	bl sub_08017B38
	pop {r0}
	bx r0
	.align 2, 0
_08017B58: .4byte 0x020228F4
	thumb_func_end sub_08017B4C

	thumb_func_start sub_08017B5C
sub_08017B5C: @ 0x08017B5C
	push {r4, r5, lr}
	adds r5, r1, #0
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r0, _08017B98
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	strh r0, [r5, #0xa]
	adds r0, r4, #0
	movs r1, #0x38
	bl GetMonData3
	strh r0, [r5, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl GetMonData3
	str r0, [r5, #4]
	ldrh r1, [r5, #0xa]
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r1, r0
	beq _08017B9C
	movs r0, #0
	b _08017B9E
	.align 2, 0
_08017B98: .4byte 0x02024190
_08017B9C:
	movs r0, #1
_08017B9E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08017B5C

	thumb_func_start sub_08017BA4
sub_08017BA4: @ 0x08017BA4
	push {r4, r5, lr}
	adds r5, r1, #0
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r0, _08017BD8
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	strh r0, [r5, #0xe]
	adds r0, r4, #0
	movs r1, #0x38
	bl GetMonData3
	strh r0, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl GetMonData3
	str r0, [r5, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08017BD8: .4byte 0x02024190
	thumb_func_end sub_08017BA4

	thumb_func_start sub_08017BDC
sub_08017BDC: @ 0x08017BDC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r1, r1, #0x18
	movs r2, #0
	mov r8, r2
	cmp r1, #0
	bne _08017BFA
	ldrh r7, [r0, #0xa]
	ldr r6, [r0, #4]
	b _08017BFE
_08017BF2:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	b _08017C32
_08017BFA:
	ldrh r7, [r0, #0xe]
	ldr r6, [r0, #0x14]
_08017BFE:
	movs r5, #0
	b _08017C2A
_08017C02:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _08017C40
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0
	bl GetMonData3
	cmp r0, r6
	bne _08017C28
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r7
	beq _08017BF2
_08017C28:
	adds r5, #1
_08017C2A:
	ldr r0, _08017C44
	ldrb r0, [r0]
	cmp r5, r0
	blt _08017C02
_08017C32:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017C40: .4byte 0x02024190
_08017C44: .4byte 0x0202418D
	thumb_func_end sub_08017BDC

	thumb_func_start sub_08017C48
sub_08017C48: @ 0x08017C48
	push {r4, lr}
	adds r4, r0, #0
	bl sub_08016E74
	bl UnlockPlayerFieldControls
	bl sub_08097EAC
	ldr r1, _08017C80
	movs r0, #0
	strb r0, [r1]
	cmp r4, #0
	beq _08017C78
	ldr r2, _08017C84
	ldrh r0, [r2, #2]
	ldrh r1, [r2, #0xa]
	ldrh r2, [r2, #0xc]
	bl SetTradeBoardRegisteredMonInfo
	movs r0, #0x40
	movs r1, #0
	movs r2, #0
	bl UpdateGameData_SetActivity
_08017C78:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017C80: .4byte 0x020228E0
_08017C84: .4byte 0x020228F4
	thumb_func_end sub_08017C48

	thumb_func_start sub_08017C88
sub_08017C88: @ 0x08017C88
	push {lr}
	bl LockPlayerFieldControls
	bl ScriptFreezeEventObjects
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08017C88

	thumb_func_start sub_08017C98
sub_08017C98: @ 0x08017C98
	push {r4, lr}
	movs r3, #0x80
	movs r2, #0
	ldr r4, [r0, #0xc]
_08017CA0:
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1, #0x18]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08017CC8
	ldrb r0, [r1, #0xb]
	lsls r0, r0, #0x1f
	lsrs r0, r0, #0x1f
	lsls r0, r0, #3
	orrs r3, r0
	ldrb r1, [r1, #2]
	movs r0, #7
	ands r0, r1
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	b _08017CD2
_08017CC8:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08017CA0
_08017CD2:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08017C98

	thumb_func_start sub_08017CDC
sub_08017CDC: @ 0x08017CDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	bl GetMultiplayerId
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x64
	muls r1, r0, r1
	ldr r0, _08017E68
	adds r1, r1, r0
	mov r8, r1
	bl DynamicPlaceholderTextUtil_Reset
	mov r7, sb
	adds r7, #0xa8
	bl sub_080686F0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xb
	muls r1, r0, r1
	ldr r0, _08017E6C
	adds r1, r1, r0
	adds r0, r7, #0
	bl StringCopy
	movs r0, #0
	adds r1, r7, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r1, r8
	adds r1, #0x30
	movs r0, #1
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r6, sb
	adds r6, #0xb7
	ldr r1, _08017E70
	mov r2, r8
	ldrb r0, [r2, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl StringCopy
	movs r0, #2
	adds r1, r6, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r5, sb
	adds r5, #0xc6
	mov r0, r8
	ldrh r1, [r0, #0xc]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	movs r0, #3
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r2, #0xd5
	add r2, sb
	mov sl, r2
	mov r0, r8
	ldrh r1, [r0, #0x10]
	mov r0, sl
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	mov r4, sb
	adds r4, #0xe4
	mov r2, r8
	ldrh r1, [r2, #0x12]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	movs r0, #4
	mov r1, sl
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, #5
	adds r1, r4, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, sb
	ldr r1, _08017E74
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, _08017E78
	adds r1, r4, #0
	bl StringCopy
	mov r0, r8
	ldrh r1, [r0, #0x14]
	ldr r4, _08017E7C
	cmp r1, r4
	ble _08017DC6
	adds r1, r4, #0
_08017DC6:
	adds r0, r7, #0
	movs r2, #0
	movs r3, #4
	bl ConvertIntToDecimalStringN
	movs r0, #0
	adds r1, r7, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r2, r8
	ldrh r1, [r2, #0x16]
	cmp r1, r4
	ble _08017DE2
	adds r1, r4, #0
_08017DE2:
	adds r0, r6, #0
	movs r2, #0
	movs r3, #4
	bl ConvertIntToDecimalStringN
	movs r0, #2
	adds r1, r6, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r0, r8
	ldrh r1, [r0, #0x20]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #5
	bl ConvertIntToDecimalStringN
	movs r0, #3
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r7, #0
	movs r6, #0x80
	lsls r6, r6, #0x13
	mov r5, r8
	adds r5, #0x28
	mov r4, sl
_08017E16:
	ldrh r1, [r5]
	adds r0, r4, #0
	bl CopyEasyChatWord
	lsrs r0, r6, #0x18
	adds r1, r4, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r6, r6, r2
	adds r5, #2
	adds r4, #0xf
	adds r7, #1
	cmp r7, #3
	ble _08017E16
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, sb
	ldr r1, _08017E80
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r5, _08017E78
	adds r0, r5, #0
	adds r1, r4, #0
	bl StringAppend
	ldr r0, [sp]
	cmp r0, #1
	bne _08017E88
	ldr r1, _08017E84
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	adds r0, r5, #0
	adds r1, r4, #0
	bl StringAppend
	b _08017EA8
	.align 2, 0
_08017E68: .4byte 0x020397F8
_08017E6C: .4byte 0x082E3564
_08017E70: .4byte 0x082C1F08
_08017E74: .4byte 0x082C1F1C
_08017E78: .4byte 0x02021C7C
_08017E7C: .4byte 0x0000270F
_08017E80: .4byte 0x082C1F54
_08017E84: .4byte 0x082C1FAC
_08017E88:
	ldr r2, [sp]
	cmp r2, #0
	bne _08017EA8
	ldr r0, _08017EB8
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	adds r0, r5, #0
	adds r1, r4, #0
	bl StringAppend
_08017EA8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017EB8: .4byte 0x082C1FA4
	thumb_func_end sub_08017CDC
