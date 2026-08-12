.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
















	thumb_func_start sub_0802048C
sub_0802048C: @ 0x0802048C
	push {lr}
	sub sp, #0x10
	ldr r0, _080204C8
	str r0, [sp, #4]
	ldr r0, _080204CC
	str r0, [sp]
	mov r2, sp
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #8]
	mov r0, sp
	strb r1, [r0, #9]
	ldr r0, _080204D0
	ldr r0, [r0]
	strh r1, [r0, #0x20]
	str r1, [sp, #0xc]
	add r0, sp, #0xc
	ldr r1, _080204D4
	ldr r2, _080204D8
	bl CpuFastSet
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl ScanlineEffect_SetParams
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_080204C8: .4byte 0xA2600001
_080204CC: .4byte 0x04000014
_080204D0: .4byte 0x0202293C
_080204D4: .4byte 0x020388C8
_080204D8: .4byte 0x010003C0
	thumb_func_end sub_0802048C

	thumb_func_start sub_080204DC
sub_080204DC: @ 0x080204DC
	push {r4, r5, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	strh r0, [r1]
	ldr r5, _08020524
	ldrb r0, [r5, #0x14]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #7
	ldr r4, _08020528
	adds r1, r1, r4
	ldr r2, _0802052C
	mov r0, sp
	bl CpuSet
	mov r0, sp
	adds r0, #2
	movs r1, #0
	strh r1, [r0]
	ldrb r2, [r5, #0x14]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #7
	movs r2, #0x90
	lsls r2, r2, #1
	adds r4, r4, r2
	adds r1, r1, r4
	ldr r2, _08020530
	bl CpuSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020524: .4byte 0x020397C8
_08020528: .4byte 0x020388C8
_0802052C: .4byte 0x01000090
_08020530: .4byte 0x01000010
	thumb_func_end sub_080204DC

	thumb_func_start sub_08020534
sub_08020534: @ 0x08020534
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, sp
	strh r4, [r0]
	ldr r5, _080205A0
	ldr r0, _080205A4
	mov sb, r0
	mov r0, sp
	adds r1, r5, #0
	mov r2, sb
	bl CpuSet
	mov r0, sp
	adds r0, #2
	movs r6, #0
	strh r6, [r0]
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, _080205A8
	mov r8, r2
	bl CpuSet
	add r0, sp, #4
	strh r4, [r0]
	movs r2, #0xf0
	lsls r2, r2, #3
	adds r1, r5, r2
	mov r2, sb
	bl CpuSet
	mov r0, sp
	adds r0, #6
	strh r6, [r0]
	movs r1, #0x8a
	lsls r1, r1, #4
	adds r5, r5, r1
	adds r1, r5, #0
	mov r2, r8
	bl CpuSet
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080205A0: .4byte 0x020388C8
_080205A4: .4byte 0x01000090
_080205A8: .4byte 0x01000010
	thumb_func_end sub_08020534

	thumb_func_start sub_080205AC
sub_080205AC: @ 0x080205AC
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _080205D8
_080205B2:
	adds r0, r4, #0
	bl LoadCompressedSpriteSheet
	adds r4, #8
	adds r5, #1
	cmp r5, #4
	bls _080205B2
	ldr r0, _080205DC
	bl LoadSpritePalette
	ldr r4, _080205E0
	movs r0, #0x18
	bl Alloc
	str r0, [r4]
	cmp r0, #0
	beq _080205E4
	movs r0, #1
	b _080205E6
	.align 2, 0
_080205D8: .4byte 0x082C5D4C
_080205DC: .4byte 0x082C5D74
_080205E0: .4byte 0x02022940
_080205E4:
	movs r0, #0
_080205E6:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_080205AC

	thumb_func_start sub_080205EC
sub_080205EC: @ 0x080205EC
	push {lr}
	ldr r0, _08020600
	ldr r0, [r0]
	cmp r0, #0
	beq _080205FA
	bl Free
_080205FA:
	pop {r0}
	bx r0
	.align 2, 0
_08020600: .4byte 0x02022940
	thumb_func_end sub_080205EC

	thumb_func_start sub_08020604
sub_08020604: @ 0x08020604
	push {lr}
	ldr r0, _0802062C
	movs r1, #0xa
	movs r2, #0x18
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08020630
	ldr r2, [r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _08020634
	adds r1, r1, r0
	str r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0802062C: .4byte 0x082C5DB4
_08020630: .4byte 0x02022940
_08020634: .4byte 0x020205AC
	thumb_func_end sub_08020604

	thumb_func_start sub_08020638
sub_08020638: @ 0x08020638
	ldr r1, _08020654
	ldr r1, [r1]
	ldr r2, [r1]
	adds r2, #0x3e
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	ldrb r3, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r3
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.align 2, 0
_08020654: .4byte 0x02022940
	thumb_func_end sub_08020638

	thumb_func_start sub_08020658
sub_08020658: @ 0x08020658
	push {r4, r5, lr}
	sub sp, #4
	bl sub_0801EEB0
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r5, sp
	adds r5, #1
	mov r0, sp
	adds r1, r5, #0
	bl sub_0801EEBC
	cmp r4, #4
	beq _08020698
	ldr r4, _08020694
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, #0
	bl StartSpriteAnim
	ldr r1, [r4]
	ldr r2, [r1]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, #0xa
	strh r0, [r2, #0x20]
	ldr r2, [r1]
	b _080206AE
	.align 2, 0
_08020694: .4byte 0x02022940
_08020698:
	ldr r4, _080206C0
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, #2
	bl StartSpriteAnim
	ldr r2, [r4]
	ldr r1, [r2]
	movs r0, #0x18
	strh r0, [r1, #0x20]
	ldr r2, [r2]
_080206AE:
	ldrb r1, [r5]
	movs r0, #0xb
	muls r0, r1, r0
	adds r0, #0x18
	strh r0, [r2, #0x22]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080206C0: .4byte 0x02022940
	thumb_func_end sub_08020658

	thumb_func_start sub_080206C4
sub_080206C4: @ 0x080206C4
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #2
	ldr r0, _080206F0
	adds r4, r4, r0
	movs r0, #0
	bl IndexOfSpritePaletteTag
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #4
	ldr r0, _080206F4
	adds r1, r1, r0
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #4
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080206F0: .4byte 0x082C588A
_080206F4: .4byte 0x01010000
	thumb_func_end sub_080206C4

	thumb_func_start sub_080206F8
sub_080206F8: @ 0x080206F8
	push {lr}
	bl sub_0801EEB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _08020718
	ldr r0, _08020714
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #1
	bl StartSpriteAnim
	b _08020724
	.align 2, 0
_08020714: .4byte 0x02022940
_08020718:
	ldr r0, _08020730
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #3
	bl StartSpriteAnim
_08020724:
	ldr r0, _08020730
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x14]
	pop {r0}
	bx r0
	.align 2, 0
_08020730: .4byte 0x02022940
	thumb_func_end sub_080206F8

	thumb_func_start sub_08020734
sub_08020734: @ 0x08020734
	push {r4, lr}
	ldr r4, _08020744
	ldr r1, [r4]
	ldrh r0, [r1, #0x14]
	cmp r0, #3
	bls _08020748
_08020740:
	movs r0, #0
	b _0802077A
	.align 2, 0
_08020744: .4byte 0x02022940
_08020748:
	adds r0, #1
	strh r0, [r1, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08020778
	bl sub_0801EEB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _0802076C
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, #0
	bl StartSpriteAnim
	b _08020740
_0802076C:
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, #2
	bl StartSpriteAnim
	b _08020740
_08020778:
	movs r0, #1
_0802077A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_08020734

	thumb_func_start sub_08020780
sub_08020780: @ 0x08020780
	push {r4, r5, lr}
	ldr r0, _080207C4
	movs r1, #0x4c
	movs r2, #0x98
	movs r3, #2
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080207C8
	ldr r2, [r5]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _080207CC
	adds r1, r1, r4
	str r1, [r2, #8]
	ldr r0, _080207D0
	movs r1, #0x40
	movs r2, #0x98
	movs r3, #1
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [r5]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	str r1, [r2, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080207C4: .4byte 0x082C5DD4
_080207C8: .4byte 0x02022940
_080207CC: .4byte 0x020205AC
_080207D0: .4byte 0x082C5DEC
	thumb_func_end sub_08020780

	thumb_func_start sub_080207D4
sub_080207D4: @ 0x080207D4
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0801EF98
	adds r3, r0, #0
	cmp r3, #0xf
	bne _080207F0
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	b _08020804
_080207F0:
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r2]
	lsls r0, r3, #3
	adds r0, #0x4c
	strh r0, [r4, #0x20]
_08020804:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080207D4

	thumb_func_start sub_0802080C
sub_0802080C: @ 0x0802080C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2e]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _08020832
	strh r2, [r1, #0x2e]
	ldrh r0, [r1, #0x24]
	adds r0, #1
	strh r0, [r1, #0x24]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _08020832
	strh r2, [r1, #0x24]
_08020832:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802080C

	thumb_func_start sub_08020838
sub_08020838: @ 0x08020838
	push {r4, r5, lr}
	ldr r0, _08020888
	movs r1, #8
	movs r2, #0x98
	movs r3, #3
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0802088C
	ldr r2, [r5]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08020890
	adds r1, r1, r4
	str r1, [r2, #0xc]
	ldr r0, _08020894
	movs r1, #0x20
	movs r2, #0x98
	movs r3, #4
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [r5]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	str r1, [r2, #0x10]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020888: .4byte 0x082C5E44
_0802088C: .4byte 0x02022940
_08020890: .4byte 0x020205AC
_08020894: .4byte 0x082C5E5C
	thumb_func_end sub_08020838

	thumb_func_start sub_08020898
sub_08020898: @ 0x08020898
	push {r4, lr}
	bl sub_0801EEB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _080208D0
	bl sub_0801EEDC
	cmp r0, #0
	beq _080208DA
	ldr r3, _080208CC
	ldr r0, [r3]
	ldr r1, [r0, #0x10]
	adds r1, #0x3e
	ldrb r2, [r1]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, #0x10]
	movs r1, #3
	bl StartSpriteAnim
	b _0802090E
	.align 2, 0
_080208CC: .4byte 0x02022940
_080208D0:
	bl sub_0801EFA4
	adds r4, r0, #0
	cmp r4, #3
	bne _080208F0
_080208DA:
	ldr r0, _080208EC
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	b _0802090E
	.align 2, 0
_080208EC: .4byte 0x02022940
_080208F0:
	ldr r3, _08020914
	ldr r0, [r3]
	ldr r1, [r0, #0x10]
	adds r1, #0x3e
	ldrb r2, [r1]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, #0x10]
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	bl StartSpriteAnim
_0802090E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020914: .4byte 0x02022940
	thumb_func_end sub_08020898
