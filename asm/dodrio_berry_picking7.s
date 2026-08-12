.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	thumb_func_start sub_08028600
sub_08028600: @ 0x08028600
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xa
	bls _0802863C
	movs r4, #0
_0802860C:
	ldr r0, _08028634
	ldr r0, [r0]
	lsls r1, r4, #1
	adds r0, #0x2a
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08028638
	adds r0, r0, r1
	movs r1, #1
	bl StartSpriteAnim
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #9
	bls _0802860C
	b _08028706
	.align 2, 0
_08028634: .4byte 0x020229A8
_08028638: .4byte 0x020205AC
_0802863C:
	movs r4, #0
	movs r0, #0xa
	subs r0, r0, r5
	cmp r4, r0
	bge _08028702
	ldr r6, _0802866C
_08028648:
	cmp r5, #6
	bls _080286B0
	ldr r0, _08028670
	ldr r2, [r0]
	ldr r1, _08028674
	adds r0, r1, #0
	ldrh r1, [r2, #0x3e]
	adds r0, r0, r1
	adds r0, r0, r5
	movs r1, #0
	strh r0, [r2, #0x3e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _08028678
	strh r1, [r2, #0x3e]
	b _080286CA
	.align 2, 0
_0802866C: .4byte 0x020205AC
_08028670: .4byte 0x020229A8
_08028674: .4byte 0x0000FFFA
_08028678:
	cmp r0, #0xa
	bls _08028696
	lsls r1, r4, #1
	adds r0, r2, #0
	adds r0, #0x2a
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	movs r1, #2
	bl StartSpriteAnim
	b _080286CA
_08028696:
	lsls r1, r4, #1
	adds r0, r2, #0
	adds r0, #0x2a
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	movs r1, #0
	bl StartSpriteAnim
	b _080286CA
_080286B0:
	ldr r0, _080286DC
	ldr r0, [r0]
	lsls r1, r4, #1
	adds r0, #0x2a
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	movs r1, #0
	bl StartSpriteAnim
_080286CA:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0xa
	subs r0, r0, r5
	cmp r4, r0
	blt _08028648
	b _08028702
	.align 2, 0
_080286DC: .4byte 0x020229A8
_080286E0:
	ldr r0, _0802870C
	ldr r0, [r0]
	lsls r1, r4, #1
	adds r0, #0x2a
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08028710
	adds r0, r0, r1
	movs r1, #1
	bl StartSpriteAnim
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08028702:
	cmp r4, #9
	bls _080286E0
_08028706:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802870C: .4byte 0x020229A8
_08028710: .4byte 0x020205AC
	thumb_func_end sub_08028600

	thumb_func_start sub_08028714
sub_08028714: @ 0x08028714
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #0
	ldr r7, _08028758
	movs r1, #1
	ands r0, r1
	lsls r4, r0, #2
	movs r6, #5
	rsbs r6, r6, #0
	ldr r5, _0802875C
_0802872A:
	ldr r0, [r5]
	lsls r1, r3, #1
	adds r0, #0x2a
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	adds r1, #0x3e
	ldrb r2, [r1]
	adds r0, r6, #0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #9
	bls _0802872A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028758: .4byte 0x020205AC
_0802875C: .4byte 0x020229A8
	thumb_func_end sub_08028714

	thumb_func_start sub_08028760
sub_08028760: @ 0x08028760
	push {r4, r5, lr}
	sub sp, #0x10
	movs r5, #0x90
	lsls r5, r5, #3
	adds r0, r5, #0
	bl AllocZeroed
	adds r4, r0, #0
	ldr r0, _080287AC
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, _080287B0
	adds r1, r4, #0
	bl LZ77UnCompWram
	cmp r4, #0
	beq _08028796
	str r4, [sp]
	movs r0, #0x80
	lsls r0, r0, #0xa
	orrs r0, r5
	str r0, [sp, #4]
	mov r0, sp
	bl LoadSpriteSheet
_08028796:
	add r0, sp, #8
	bl LoadSpritePalette
	adds r0, r4, #0
	bl Free
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080287AC: .4byte 0x082CEBA0
_080287B0: .4byte 0x082CB73C
	thumb_func_end sub_08028760

	thumb_func_start sub_080287B4
sub_080287B4: @ 0x080287B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x30
	mov r1, sp
	ldr r0, _08028844
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	add r2, sp, #0x18
	adds r1, r2, #0
	ldr r0, _08028848
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	movs r5, #0
	mov sb, r2
_080287DC:
	movs r0, #4
	bl AllocZeroed
	ldr r1, _0802884C
	lsls r4, r5, #2
	adds r4, r4, r1
	str r0, [r4]
	lsls r0, r5, #3
	lsls r1, r5, #4
	adds r1, r1, r0
	mov r0, sp
	movs r2, #8
	movs r3, #1
	bl CreateSprite
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl sub_08028924
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xa
	bls _080287DC
	movs r5, #0
	ldr r7, _08028850
	ldr r4, _08028854
	mov r8, r4
_0802881C:
	movs r0, #4
	bl AllocZeroed
	lsls r1, r5, #2
	adds r4, r1, r7
	str r0, [r4]
	adds r6, r1, #0
	cmp r5, #3
	bne _08028858
	mov r0, r8
	movs r2, #6
	ldrsh r1, [r0, r2]
	mov r0, sb
	movs r2, #0x39
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7, #0xc]
	b _0802886C
	.align 2, 0
_08028844: .4byte 0x082CEBB0
_08028848: .4byte 0x082CEBC8
_0802884C: .4byte 0x0202296C
_08028850: .4byte 0x02022998
_08028854: .4byte 0x082CEBA8
_08028858:
	lsls r0, r5, #1
	add r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r0, sb
	movs r2, #0x3c
	movs r3, #0
	bl CreateSprite
	ldr r1, [r4]
_0802886C:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r1]
	adds r0, r6, r7
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080288A8
	adds r0, r0, r1
	adds r1, r5, #0
	bl StartSpriteAnim
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _0802881C
	movs r0, #1
	bl sub_0802895C
	add sp, #0x30
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080288A8: .4byte 0x020205AC
	thumb_func_end sub_080287B4

	thumb_func_start sub_080288AC
sub_080288AC: @ 0x080288AC
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _08028918
_080288B2:
	lsls r0, r5, #2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0802891C
	adds r0, r0, r1
	cmp r0, #0
	beq _080288CC
	bl DestroySprite
_080288CC:
	ldr r0, [r4]
	bl Free
	movs r0, #0
	str r0, [r4]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xa
	bls _080288B2
	movs r5, #0
	ldr r6, _08028920
_080288E4:
	lsls r0, r5, #2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0802891C
	adds r0, r0, r1
	cmp r0, #0
	beq _080288FE
	bl DestroySprite
_080288FE:
	ldr r0, [r4]
	bl Free
	movs r0, #0
	str r0, [r4]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _080288E4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028918: .4byte 0x0202296C
_0802891C: .4byte 0x020205AC
_08028920: .4byte 0x02022998
	thumb_func_end sub_080288AC

	thumb_func_start sub_08028924
sub_08028924: @ 0x08028924
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _08028954
	ldr r2, _08028958
	lsrs r0, r0, #0x16
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r3
	adds r2, #0x3e
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	ldrb r3, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.align 2, 0
_08028954: .4byte 0x020205AC
_08028958: .4byte 0x0202296C
	thumb_func_end sub_08028924

	thumb_func_start sub_0802895C
sub_0802895C: @ 0x0802895C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #0
	ldr r7, _080289A0
	ldr r6, _080289A4
	movs r1, #1
	ands r0, r1
	lsls r4, r0, #2
	movs r5, #5
	rsbs r5, r5, #0
_08028972:
	lsls r0, r3, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	adds r1, #0x3e
	ldrb r2, [r1]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _08028972
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080289A0: .4byte 0x020205AC
_080289A4: .4byte 0x02022998
	thumb_func_end sub_0802895C

	thumb_func_start sub_080289A8
sub_080289A8: @ 0x080289A8
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	ldr r3, _080289C8
	ldr r2, _080289CC
	lsrs r0, r0, #0x16
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r2, [r0]
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r3
	lsrs r1, r1, #0x15
	strh r1, [r0, #0x22]
	bx lr
	.align 2, 0
_080289C8: .4byte 0x020205AC
_080289CC: .4byte 0x0202296C
	thumb_func_end sub_080289A8

	thumb_func_start sub_080289D0
sub_080289D0: @ 0x080289D0
	push {lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _080289F4
	lsrs r0, r0, #0xe
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r2, [r0]
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r2, _080289F8
	adds r0, r0, r2
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.align 2, 0
_080289F4: .4byte 0x0202296C
_080289F8: .4byte 0x020205AC
	thumb_func_end sub_080289D0

	thumb_func_start sub_080289FC
sub_080289FC: @ 0x080289FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08028A1C
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r1
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0x32
	strh r1, [r2, #0x20]
	movs r0, #0x32
	strh r0, [r2, #0x22]
	bx lr
	.align 2, 0
_08028A1C: .4byte 0x020205AC
	thumb_func_end sub_080289FC

	thumb_func_start sub_08028A20
sub_08028A20: @ 0x08028A20
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08028A62
	movs r3, #0
	ldr r7, _08028A68
	ldr r6, _08028A6C
	movs r5, #0
_08028A36:
	lsls r0, r3, #2
	adds r2, r0, r6
	ldr r1, [r2]
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	adds r1, r3, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1]
	cmp r0, r1
	bls _08028A58
	ldrh r0, [r4, #0x20]
	subs r0, #1
	strh r0, [r4, #0x20]
	ldr r0, [r2]
	strh r5, [r0, #2]
_08028A58:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _08028A36
_08028A62:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028A68: .4byte 0x082CEBE0
_08028A6C: .4byte 0x02022964
	thumb_func_end sub_08028A20

	thumb_func_start sub_08028A70
sub_08028A70: @ 0x08028A70
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x28
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r4, #0
	bl AllocZeroed
	adds r6, r0, #0
	ldr r0, _08028B14
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, _08028B18
	adds r1, r6, #0
	bl LZ77UnCompWram
	cmp r6, #0
	beq _08028AFE
	str r6, [sp, #0x18]
	add r0, sp, #0x18
	movs r1, #0xa0
	lsls r1, r1, #0xb
	orrs r1, r4
	str r1, [r0, #4]
	mov r2, sp
	ldr r1, _08028B1C
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	bl LoadSpriteSheet
	add r0, sp, #0x20
	bl LoadSpritePalette
	movs r5, #0
	ldr r7, _08028B20
	adds r0, r7, #2
	mov sb, r0
	ldr r1, _08028B24
	mov r8, r1
_08028ACA:
	movs r0, #4
	bl AllocZeroed
	lsls r2, r5, #2
	mov r3, r8
	adds r4, r2, r3
	str r0, [r4]
	adds r0, r2, r7
	movs r3, #0
	ldrsh r1, [r0, r3]
	add r2, sb
	movs r0, #0
	ldrsh r2, [r2, r0]
	mov r0, sp
	movs r3, #4
	bl CreateSprite
	ldr r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #1
	bls _08028ACA
_08028AFE:
	adds r0, r6, #0
	bl Free
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028B14: .4byte 0x082CEBEC
_08028B18: .4byte 0x082CD000
_08028B1C: .4byte 0x082CEBF4
_08028B20: .4byte 0x082CEBE2
_08028B24: .4byte 0x02022964
	thumb_func_end sub_08028A70

	thumb_func_start sub_08028B28
sub_08028B28: @ 0x08028B28
	push {r4, r5, r6, r7, lr}
	movs r3, #0
	ldr r0, _08028B6C
	mov ip, r0
	ldr r4, _08028B70
	adds r7, r4, #2
	ldr r6, _08028B74
	movs r5, #1
_08028B38:
	lsls r2, r3, #2
	mov r1, ip
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0x42
	strh r5, [r0]
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1, #0x20]
	adds r2, r2, r7
	ldrh r0, [r2]
	strh r0, [r1, #0x22]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _08028B38
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028B6C: .4byte 0x02022964
_08028B70: .4byte 0x082CEBE2
_08028B74: .4byte 0x020205AC
	thumb_func_end sub_08028B28

	thumb_func_start sub_08028B78
sub_08028B78: @ 0x08028B78
	push {r4, r5, lr}
	movs r2, #0
	ldr r5, _08028BA8
	ldr r4, _08028BAC
	movs r3, #0
_08028B82:
	lsls r0, r2, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x42
	strh r3, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #1
	bls _08028B82
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08028BA8: .4byte 0x02022964
_08028BAC: .4byte 0x020205AC
	thumb_func_end sub_08028B78

	thumb_func_start sub_08028BB0
sub_08028BB0: @ 0x08028BB0
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _08028BEC
_08028BB6:
	lsls r0, r5, #2
	adds r4, r0, r6
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08028BF0
	adds r0, r0, r1
	cmp r0, #0
	beq _08028BD0
	bl DestroySprite
_08028BD0:
	ldr r0, [r4]
	bl Free
	movs r0, #0
	str r0, [r4]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #1
	bls _08028BB6
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08028BEC: .4byte 0x02022964
_08028BF0: .4byte 0x020205AC
	thumb_func_end sub_08028BB0

	thumb_func_start sub_08028BF4
sub_08028BF4: @ 0x08028BF4
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #0
	ldr r7, _08028C38
	ldr r6, _08028C3C
	movs r1, #1
	ands r0, r1
	lsls r4, r0, #2
	movs r5, #5
	rsbs r5, r5, #0
_08028C0A:
	lsls r0, r3, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	adds r1, #0x3e
	ldrb r2, [r1]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _08028C0A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028C38: .4byte 0x020205AC
_08028C3C: .4byte 0x02022964
	thumb_func_end sub_08028BF4

	thumb_func_start sub_08028C40
sub_08028C40: @ 0x08028C40
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r3, #0
	subs r0, r1, #1
	cmp r0, #4
	bhi _08028CF2
	lsls r0, r0, #2
	ldr r1, _08028C5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028C5C: .4byte 0x08028C60
_08028C60: @ jump table
	.4byte _08028CE0 @ case 0
	.4byte _08028C74 @ case 1
	.4byte _08028C7E @ case 2
	.4byte _08028C92 @ case 3
	.4byte _08028CBA @ case 4
_08028C74:
	cmp r2, #0
	beq _08028CAA
	cmp r2, #1
	bne _08028CF2
	b _08028CAE
_08028C7E:
	cmp r2, #1
	beq _08028CE4
	cmp r2, #1
	bgt _08028C8C
	cmp r2, #0
	beq _08028CE0
	b _08028CF2
_08028C8C:
	cmp r2, #2
	bne _08028CF2
	b _08028CF0
_08028C92:
	cmp r2, #1
	beq _08028CAE
	cmp r2, #1
	bgt _08028CA0
	cmp r2, #0
	beq _08028CAA
	b _08028CF2
_08028CA0:
	cmp r2, #2
	beq _08028CB2
	cmp r2, #3
	beq _08028CB6
	b _08028CF2
_08028CAA:
	movs r3, #0xc
	b _08028CF2
_08028CAE:
	movs r3, #0x12
	b _08028CF2
_08028CB2:
	movs r3, #0x18
	b _08028CF2
_08028CB6:
	movs r3, #6
	b _08028CF2
_08028CBA:
	cmp r2, #4
	bhi _08028CF2
	lsls r0, r2, #2
	ldr r1, _08028CC8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08028CC8: .4byte 0x08028CCC
_08028CCC: @ jump table
	.4byte _08028CE0 @ case 0
	.4byte _08028CE4 @ case 1
	.4byte _08028CE8 @ case 2
	.4byte _08028CEC @ case 3
	.4byte _08028CF0 @ case 4
_08028CE0:
	movs r3, #0xf
	b _08028CF2
_08028CE4:
	movs r3, #0x15
	b _08028CF2
_08028CE8:
	movs r3, #0x1b
	b _08028CF2
_08028CEC:
	movs r3, #3
	b _08028CF2
_08028CF0:
	movs r3, #9
_08028CF2:
	lsls r0, r3, #3
	pop {r1}
	bx r1
	thumb_func_end sub_08028C40

	thumb_func_start sub_08028CF8
sub_08028CF8: @ 0x08028CF8
	push {r4, lr}
	movs r4, #0
_08028CFC:
	adds r0, r4, #0
	movs r1, #1
	bl sub_08028924
	adds r0, r4, #0
	movs r1, #1
	bl sub_080289A8
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xa
	bls _08028CFC
	movs r0, #0
	bl sub_08028714
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08028CF8

	thumb_func_start sub_08028D24
sub_08028D24: @ 0x08028D24
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl GetWindowFrameTilesPal
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #1
	movs r0, #0
	movs r3, #1
	bl LoadBgTiles
	adds r0, r4, #0
	bl GetWindowFrameTilesPal
	ldr r0, [r0, #4]
	movs r1, #0xa0
	movs r2, #0x20
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08028D24

	thumb_func_start nullsub_16
nullsub_16: @ 0x08028D58
	push {lr}
	movs r0, #0
	movs r1, #0xa
	movs r2, #0xb0
	bl LoadUserWindowBorderGfx_
	pop {r0}
	bx r0
	thumb_func_end nullsub_16

	thumb_func_start sub_08028D68
sub_08028D68: @ 0x08028D68
	ldr r3, _08028D98
	ldr r0, [r3]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r0, r2
	movs r2, #0
	str r2, [r1]
	ldr r1, _08028D9C
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, #4
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, #8
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r3]
	adds r1, #4
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_08028D98: .4byte 0x020229AC
_08028D9C: .4byte 0x00003014
	thumb_func_end sub_08028D68

	thumb_func_start sub_08028DA0
sub_08028DA0: @ 0x08028DA0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r6, #0xa
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r5, #1
	str r5, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #1
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #1]
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r0, [r4, #3]
	str r0, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #2
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #3]
	ldrb r0, [r4, #1]
	adds r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #3
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	str r5, [sp]
	ldrb r0, [r4, #4]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #4
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #3]
	ldrb r0, [r4, #1]
	adds r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	str r5, [sp]
	ldrb r0, [r4, #4]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #6
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #4]
	ldrb r0, [r4, #2]
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #7
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #1]
	ldrb r3, [r4, #4]
	ldrb r0, [r4, #2]
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r0, [r4, #3]
	str r0, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #8
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #3]
	ldrb r0, [r4, #1]
	adds r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #4]
	ldrb r4, [r4, #2]
	adds r3, r3, r4
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #9
	bl FillBgTilemapBufferRect
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08028DA0

	thumb_func_start sub_08028EA0
sub_08028EA0: @ 0x08028EA0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r6, #0xb
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r5, #1
	str r5, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #0xa
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #1]
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r0, [r4, #3]
	str r0, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #0xb
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #3]
	ldrb r0, [r4, #1]
	adds r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #0xc
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	str r5, [sp]
	ldrb r0, [r4, #4]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #0xd
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #3]
	ldrb r0, [r4, #1]
	adds r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	str r5, [sp]
	ldrb r0, [r4, #4]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #0xf
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #4]
	ldrb r0, [r4, #2]
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #0x10
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #1]
	ldrb r3, [r4, #4]
	ldrb r0, [r4, #2]
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r0, [r4, #3]
	str r0, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #0x11
	bl FillBgTilemapBufferRect
	ldrb r2, [r4, #3]
	ldrb r0, [r4, #1]
	adds r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #4]
	ldrb r4, [r4, #2]
	adds r3, r3, r4
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	movs r1, #0x12
	bl FillBgTilemapBufferRect
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08028EA0

	thumb_func_start sub_08028FA0
sub_08028FA0: @ 0x08028FA0
	push {r4, lr}
	ldr r4, _08028FE8
	str r0, [r4]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r0, r2
	movs r2, #0
	str r2, [r1]
	ldr r3, _08028FEC
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _08028FF0
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r3, #0xc
	adds r0, r0, r3
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, #0xc
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, _08028FF4
	movs r1, #3
	bl CreateTask
	ldr r1, [r4]
	ldr r2, _08028FF8
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, _08028FFC
	bl sub_0802A420
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08028FE8: .4byte 0x020229AC
_08028FEC: .4byte 0x00003014
_08028FF0: .4byte 0x00003018
_08028FF4: .4byte 0x08029041
_08028FF8: .4byte 0x00003004
_08028FFC: .4byte 0x08029065
	thumb_func_end sub_08028FA0

	thumb_func_start sub_08029000
sub_08029000: @ 0x08029000
	push {lr}
	bl FreeAllWindowBuffers
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08029000

	thumb_func_start sub_0802900C
sub_0802900C: @ 0x0802900C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r4, #0
	ldr r5, _0802903C
	adds r7, r5, #4
_08029018:
	lsls r1, r4, #3
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, r6
	bne _0802902A
	adds r0, r1, r7
	ldr r0, [r0]
	bl sub_0802A420
_0802902A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #9
	bls _08029018
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802903C: .4byte 0x082CEC98
	thumb_func_end sub_0802900C

	thumb_func_start sub_08029040
sub_08029040: @ 0x08029040
	push {lr}
	ldr r0, _08029060
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0802905A
	bl sub_0802A450
	bl _call_via_r0
_0802905A:
	pop {r0}
	bx r0
	.align 2, 0
_08029060: .4byte 0x020229AC
	thumb_func_end sub_08029040

	thumb_func_start sub_08029064
sub_08029064: @ 0x08029064
	push {lr}
	ldr r0, _08029080
	ldr r1, [r0]
	ldr r2, _08029084
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _0802915C
	lsls r0, r0, #2
	ldr r1, _08029088
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08029080: .4byte 0x020229AC
_08029084: .4byte 0x00003014
_08029088: .4byte 0x0802908C
_0802908C: @ jump table
	.4byte _080290A0 @ case 0
	.4byte _080290A6 @ case 1
	.4byte _080290C0 @ case 2
	.4byte _08029104 @ case 3
	.4byte _08029130 @ case 4
_080290A0:
	bl sub_0802A49C
	b _08029140
_080290A6:
	bl sub_0802A5DC
	cmp r0, #1
	bne _08029166
	ldr r0, _080290B8
	ldr r1, [r0]
	ldr r2, _080290BC
	adds r1, r1, r2
	b _08029148
	.align 2, 0
_080290B8: .4byte 0x020229AC
_080290BC: .4byte 0x00003014
_080290C0:
	ldr r1, _080290F8
	movs r0, #3
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	ldr r1, _080290FC
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	ldr r1, _08029100
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	movs r0, #3
	bl CopyBgTilemapBufferToVram
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	b _08029140
	.align 2, 0
_080290F8: .4byte 0x082CE364
_080290FC: .4byte 0x082CE820
_08029100: .4byte 0x082CE5D0
_08029104:
	movs r0, #0
	bl ShowBg
	movs r0, #3
	bl ShowBg
	movs r0, #1
	bl ShowBg
	movs r0, #2
	bl ShowBg
	ldr r0, _08029128
	ldr r1, [r0]
	ldr r2, _0802912C
	adds r1, r1, r2
	b _08029148
	.align 2, 0
_08029128: .4byte 0x020229AC
_0802912C: .4byte 0x00003014
_08029130:
	ldr r0, _08029150
	ldr r0, [r0]
	ldrb r0, [r0, #0x14]
	lsrs r0, r0, #3
	bl sub_08028D24
	bl nullsub_16
_08029140:
	ldr r0, _08029154
	ldr r1, [r0]
	ldr r0, _08029158
	adds r1, r1, r0
_08029148:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08029166
	.align 2, 0
_08029150: .4byte 0x03005AF0
_08029154: .4byte 0x020229AC
_08029158: .4byte 0x00003014
_0802915C:
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r1, r1, r2
	movs r0, #1
	str r0, [r1]
_08029166:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08029064

	thumb_func_start sub_0802916C
sub_0802916C: @ 0x0802916C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r4, _080291AC
	ldr r0, [r4]
	ldr r2, _080291B0
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080291B4
	cmp r0, #1
	bne _0802918C
	b _08029318
_0802918C:
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb4
	bhi _0802919A
	b _080293BA
_0802919A:
	bl sub_08027410
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r6, #0
	cmp r6, r7
	blo _080291AA
	b _08029392
_080291AA:
	b _0802936C
	.align 2, 0
_080291AC: .4byte 0x020229AC
_080291B0: .4byte 0x00003014
_080291B4:
	bl sub_08027410
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _080292F0
	subs r0, r7, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r2, _080292F4
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r1, _080292F8
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #0x13
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #2
	orrs r0, r1
	ldr r1, _080292FC
	ands r0, r1
	movs r1, #0xd0
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _08029300
	ands r0, r1
	movs r1, #0x98
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r6, #0
	cmp r6, r7
	bhs _080292E4
	mov r3, sp
	adds r3, #0xc
	str r3, [sp, #0x18]
	mov sl, r4
	ldr r0, _08029304
	mov sb, r0
_08029208:
	movs r1, #0
	mov r8, r1
	adds r0, r6, #0
	bl sub_08027808
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	bl sub_08027420
	adds r1, r0, #0
	movs r0, #0
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	movs r1, #0x38
	subs r1, r1, r0
	lsrs r1, r1, #1
	str r1, [sp, #0x14]
	ldrb r0, [r5]
	lsls r0, r0, #8
	ldr r2, _080292FC
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	ldrb r2, [r5, #1]
	lsls r2, r2, #0x10
	ldr r0, _08029308
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl AddWindow
	mov r2, sl
	ldr r1, [r2]
	add r1, sb
	adds r1, r1, r6
	strb r0, [r1]
	ldr r0, [r2]
	add r0, sb
	adds r0, r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	mov r3, sl
	ldr r0, [r3]
	add r0, sb
	adds r0, r0, r6
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bne _08029286
	movs r0, #2
	mov r8, r0
_08029286:
	adds r0, r4, #0
	bl sub_08027420
	adds r4, r0, #0
	mov r1, sl
	ldr r0, [r1]
	add r0, sb
	adds r0, r0, r6
	ldrb r0, [r0]
	ldr r3, [sp, #0x14]
	lsls r2, r3, #0x18
	lsrs r2, r2, #0x18
	mov r3, r8
	lsls r1, r3, #1
	add r1, r8
	ldr r3, _0802930C
	adds r1, r1, r3
	str r1, [sp]
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	movs r3, #1
	bl AddTextPrinterParameterized3
	mov r2, sl
	ldr r0, [r2]
	add r0, sb
	adds r0, r0, r6
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r3, [sp, #0x18]
	ldrh r0, [r3, #6]
	adds r0, #0xe
	strh r0, [r3, #6]
	add r0, sp, #0xc
	bl sub_08028EA0
	adds r5, #4
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r7
	blo _08029208
_080292E4:
	ldr r0, _08029310
	ldr r1, [r0]
	ldr r0, _08029314
	adds r1, r1, r0
	b _08029356
	.align 2, 0
_080292F0: .4byte 0x082CEC54
_080292F4: .4byte 0xFFFFFF00
_080292F8: .4byte 0x00FFFFFF
_080292FC: .4byte 0xFFFF00FF
_08029300: .4byte 0x0000FFFF
_08029304: .4byte 0x00003008
_08029308: .4byte 0xFF00FFFF
_0802930C: .4byte 0x082CEC0C
_08029310: .4byte 0x020229AC
_08029314: .4byte 0x00003014
_08029318:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080293BA
	bl sub_08027410
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r6, #0
	cmp r6, r7
	bhs _08029348
_08029330:
	ldr r0, [r4]
	ldr r1, _08029360
	adds r0, r0, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r7
	blo _08029330
_08029348:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _08029364
	ldr r1, [r0]
	ldr r2, _08029368
	adds r1, r1, r2
_08029356:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080293BA
	.align 2, 0
_08029360: .4byte 0x00003008
_08029364: .4byte 0x020229AC
_08029368: .4byte 0x00003014
_0802936C:
	ldr r5, _080293CC
	ldr r0, [r5]
	ldr r4, _080293D0
	adds r0, r0, r4
	adds r0, r0, r6
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, r0, r6
	ldrb r0, [r0]
	bl RemoveWindow
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r7
	blo _0802936C
_08029392:
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _080293CC
	ldr r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #6
	adds r0, r0, r3
	movs r1, #1
	str r1, [r0]
_080293BA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080293CC: .4byte 0x020229AC
_080293D0: .4byte 0x00003008
	thumb_func_end sub_0802916C

	thumb_func_start sub_080293D4
sub_080293D4: @ 0x080293D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	lsls r0, r0, #0x18
	movs r1, #0
	mov r8, r1
	movs r6, #0
	lsrs r7, r0, #0x18
	add r4, sp, #0x2c
	ldr r1, _08029588
	adds r0, r4, #0
	movs r2, #5
	bl memcpy
	movs r5, #0
	cmp r5, r7
	bhs _08029424
	add r4, sp, #0x34
_080293FE:
	mov r0, sp
	adds r0, r0, r5
	adds r0, #0x2c
	strb r5, [r0]
	add r0, sp, #0x5c
	adds r1, r5, #0
	bl sub_080276FC
	lsls r2, r5, #3
	adds r2, r4, r2
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x60]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r7
	blo _080293FE
_08029424:
	bl sub_08027508
	cmp r0, #0
	beq _0802945A
_0802942C:
	movs r5, #0
	cmp r5, r7
	bhs _08029454
	add r2, sp, #0x34
	add r1, sp, #0x2c
_08029436:
	lsls r0, r5, #3
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, r8
	bne _0802944A
	adds r0, r1, r6
	strb r5, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_0802944A:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r7
	blo _08029436
_08029454:
	mov r8, r6
	cmp r6, r7
	blo _0802942C
_0802945A:
	movs r5, #0
	cmp r5, r7
	bhs _0802947E
	add r6, sp, #0x34
	add r3, sp, #0x38
	subs r2, r7, #1
_08029466:
	lsls r1, r5, #3
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08029474
	adds r0, r6, r1
	strb r2, [r0]
_08029474:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r7
	blo _08029466
_0802947E:
	movs r5, #0
	cmp r5, r7
	bhs _08029576
	mov r2, sp
	adds r2, #0x34
	str r2, [sp, #0x64]
	ldr r3, _0802958C
	mov sl, r3
_0802948E:
	movs r0, #0
	mov r8, r0
	mov r0, sp
	adds r0, r0, r5
	adds r0, #0x2c
	ldrb r0, [r0]
	adds r4, r0, #0
	lsls r1, r4, #3
	add r0, sp, #0x38
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _08029590
	ldr r0, [r2]
	add r0, sl
	ldrb r0, [r0]
	ldr r2, _08029594
	ldr r3, [sp, #0x64]
	adds r1, r3, r1
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	ldr r3, _08029598
	lsls r1, r5, #1
	adds r1, r1, r3
	ldrb r6, [r1]
	str r6, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #8
	bl AddTextPrinterParameterized
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bne _080294E6
	movs r0, #2
	mov r8, r0
_080294E6:
	adds r0, r4, #0
	bl sub_08027420
	adds r3, r0, #0
	ldr r1, _08029590
	ldr r0, [r1]
	add r0, sl
	ldrb r0, [r0]
	mov r2, r8
	lsls r1, r2, #1
	add r1, r8
	ldr r2, _0802959C
	adds r1, r1, r2
	str r1, [sp]
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r2, #0x1c
	adds r3, r6, #0
	bl AddTextPrinterParameterized3
	add r0, sp, #0xc
	mov r1, sb
	movs r2, #0
	movs r3, #7
	bl ConvertIntToDecimalStringN
	movs r0, #0
	add r1, sp, #0xc
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	ldr r2, _08029590
	ldr r1, [r2]
	add r1, sl
	ldrb r1, [r1]
	movs r3, #0x91
	subs r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r6, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r2, #0
	str r2, [sp, #8]
	adds r0, r1, #0
	movs r1, #0
	add r2, sp, #0xc
	bl AddTextPrinterParameterized
	ldr r3, _08029590
	ldr r0, [r3]
	add r0, sl
	ldrb r0, [r0]
	str r6, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r2, #0
	str r2, [sp, #8]
	movs r1, #0
	ldr r2, _080295A0
	movs r3, #0x9b
	bl AddTextPrinterParameterized
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, r7
	blo _0802948E
_08029576:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029588: .4byte 0x082CECE8
_0802958C: .4byte 0x00003009
_08029590: .4byte 0x020229AC
_08029594: .4byte 0x082CEC68
_08029598: .4byte 0x082CEC8E
_0802959C: .4byte 0x082CEC0C
_080295A0: .4byte 0x085CCDE7
	thumb_func_end sub_080293D4

	thumb_func_start sub_080295A4
sub_080295A4: @ 0x080295A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	bl sub_08027410
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r6, _080295D4
	ldr r1, [r6]
	ldr r2, _080295D8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0xb
	bls _080295CA
	b _08029CC0
_080295CA:
	lsls r0, r0, #2
	ldr r1, _080295DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080295D4: .4byte 0x020229AC
_080295D8: .4byte 0x00003014
_080295DC: .4byte 0x080295E0
_080295E0: @ jump table
	.4byte _08029610 @ case 0
	.4byte _0802962C @ case 1
	.4byte _08029684 @ case 2
	.4byte _08029888 @ case 3
	.4byte _080298D4 @ case 4
	.4byte _08029918 @ case 5
	.4byte _0802997C @ case 6
	.4byte _080299B8 @ case 7
	.4byte _080299FC @ case 8
	.4byte _08029ABC @ case 9
	.4byte _08029C20 @ case 10
	.4byte _08029C74 @ case 11
_08029610:
	bl sub_0802760C
	ldr r0, _08029624
	ldr r1, [r0]
	ldr r0, _08029628
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	b _08029CA2
	.align 2, 0
_08029624: .4byte 0x020229AC
_08029628: .4byte 0x0000301C
_0802962C:
	ldr r6, _08029674
	adds r0, r6, #0
	bl AddWindow
	ldr r4, _08029678
	ldr r1, [r4]
	ldr r2, _0802967C
	mov r8, r2
	add r1, r8
	strb r0, [r1]
	movs r0, #8
	adds r0, r0, r6
	mov sb, r0
	bl AddWindow
	ldr r1, [r4]
	ldr r5, _08029680
	adds r1, r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, #0
	bl sub_08028EA0
	mov r0, sb
	bl sub_08028EA0
	b _08029CA0
	.align 2, 0
_08029674: .4byte 0x082CB448
_08029678: .4byte 0x020229AC
_0802967C: .4byte 0x00003008
_08029680: .4byte 0x00003009
_08029684:
	ldr r4, _080297D0
	ldr r0, [r4]
	ldr r5, _080297D4
	adds r0, r0, r5
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, _080297D8
	mov sb, r1
	add r0, sb
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r2, _080297DC
	mov r8, r2
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #0
	mov r1, r8
	bl GetStringWidth
	adds r1, r0, #0
	movs r0, #0xe0
	subs r0, r0, r1
	lsrs r3, r0, #1
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r1, #2
	str r1, [sp]
	movs r6, #0xff
	str r6, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r1, #0
	mov r2, r8
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	add r0, sb
	ldrb r0, [r0]
	ldr r2, _080297E0
	movs r1, #0x10
	str r1, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r3, #0x44
	bl AddTextPrinterParameterized
	movs r0, #0
	mov sb, r0
	ldr r1, [sp, #0xc]
	cmp sb, r1
	blo _080296FE
	b _08029844
_080296FE:
	movs r4, #0
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp sb, r0
	bne _0802970E
	movs r4, #2
_0802970E:
	mov r0, sb
	bl sub_08027420
	adds r6, r0, #0
	ldr r0, _080297D0
	ldr r0, [r0]
	ldr r2, _080297D8
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r1, sb
	lsls r5, r1, #1
	ldr r2, _080297E4
	adds r1, r5, r2
	ldrb r3, [r1]
	lsls r1, r4, #1
	adds r1, r1, r4
	ldr r2, _080297E8
	adds r1, r1, r2
	str r1, [sp]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #4]
	str r6, [sp, #8]
	movs r1, #0
	movs r2, #2
	bl AddTextPrinterParameterized3
	movs r7, #0
	mov r8, r5
	mov r0, sb
	adds r0, #1
	str r0, [sp, #0x10]
	ldr r1, _080297EC
	mov sl, r1
_08029752:
	mov r0, sb
	adds r1, r7, #0
	bl sub_08027460
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080297F0
	bl Min
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r7, #0
	bl sub_0802754C
	ldr r1, _080297F0
	bl Min
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, sl
	adds r1, r4, #0
	movs r2, #0
	movs r3, #4
	bl ConvertIntToDecimalStringN
	movs r0, #0
	mov r1, sl
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	adds r5, r0, #0
	cmp r6, r4
	bne _080297FC
	cmp r6, #0
	beq _080297FC
	ldr r0, _080297D0
	ldr r0, [r0]
	ldr r2, _080297D8
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r1, r7, #1
	ldr r2, _080297F4
	adds r1, r1, r2
	ldrb r2, [r1]
	subs r2, r2, r5
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _080297E4
	add r1, r8
	ldrb r3, [r1]
	ldr r1, _080297F8
	str r1, [sp]
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	movs r1, #0
	bl AddTextPrinterParameterized3
	b _0802982A
	.align 2, 0
_080297D0: .4byte 0x020229AC
_080297D4: .4byte 0x00003008
_080297D8: .4byte 0x00003009
_080297DC: .4byte 0x085CCD34
_080297E0: .4byte 0x085CCD45
_080297E4: .4byte 0x082CEC84
_080297E8: .4byte 0x082CEC0C
_080297EC: .4byte 0x02021C7C
_080297F0: .4byte 0x0000270F
_080297F4: .4byte 0x082CEC7C
_080297F8: .4byte 0x082CEC0F
_080297FC:
	ldr r0, _0802986C
	ldr r0, [r0]
	ldr r2, _08029870
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r1, r7, #1
	ldr r2, _08029874
	adds r1, r1, r2
	ldrb r3, [r1]
	subs r3, r3, r5
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r1, _08029878
	add r1, r8
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	ldr r2, _0802987C
	bl AddTextPrinterParameterized
_0802982A:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _08029752
	ldr r1, [sp, #0x10]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r2, [sp, #0xc]
	cmp sb, r2
	bhs _08029844
	b _080296FE
_08029844:
	ldr r4, _0802986C
	ldr r0, [r4]
	ldr r1, _08029880
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, _08029870
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, _08029884
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_0802986C: .4byte 0x020229AC
_08029870: .4byte 0x00003009
_08029874: .4byte 0x082CEC7C
_08029878: .4byte 0x082CEC84
_0802987C: .4byte 0x02021C7C
_08029880: .4byte 0x00003008
_08029884: .4byte 0x00003014
_08029888:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080298AC
	ldr r4, _080298C4
	ldr r0, [r4]
	ldr r1, _080298C8
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, _080298CC
	adds r0, r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_080298AC:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #0
	bl sub_0802895C
	ldr r0, _080298C4
	ldr r1, [r0]
	ldr r0, _080298D0
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_080298C4: .4byte 0x020229AC
_080298C8: .4byte 0x00003008
_080298CC: .4byte 0x00003009
_080298D0: .4byte 0x00003014
_080298D4:
	ldr r4, _0802990C
	ldr r0, [r4]
	ldr r1, _08029910
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _080298EC
	b _08029D10
_080298EC:
	ldr r0, _08029914
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080298FA
	b _08029D10
_080298FA:
	movs r0, #0
	strh r0, [r2]
	movs r0, #5
	bl PlaySE
	movs r0, #1
	bl sub_0802895C
	b _08029CA0
	.align 2, 0
_0802990C: .4byte 0x020229AC
_08029910: .4byte 0x0000301C
_08029914: .4byte 0x03002360
_08029918:
	ldr r4, _0802996C
	ldr r0, [r4]
	ldr r5, _08029970
	adds r0, r0, r5
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, _08029974
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r6, _08029978
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #0
	adds r1, r6, #0
	bl GetStringWidth
	adds r1, r0, #0
	movs r0, #0xe0
	subs r0, r0, r1
	lsrs r3, r0, #1
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	adds r2, r6, #0
	bl AddTextPrinterParameterized
	b _08029CA0
	.align 2, 0
_0802996C: .4byte 0x020229AC
_08029970: .4byte 0x00003008
_08029974: .4byte 0x00003009
_08029978: .4byte 0x085CCD5A
_0802997C:
	ldr r0, [sp, #0xc]
	bl sub_080293D4
	ldr r4, _080299A8
	ldr r0, [r4]
	ldr r1, _080299AC
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, _080299B0
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, _080299B4
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_080299A8: .4byte 0x020229AC
_080299AC: .4byte 0x00003008
_080299B0: .4byte 0x00003009
_080299B4: .4byte 0x00003014
_080299B8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080299DC
	ldr r4, _080299EC
	ldr r0, [r4]
	ldr r1, _080299F0
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, _080299F4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_080299DC:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _080299EC
	ldr r1, [r0]
	ldr r0, _080299F8
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_080299EC: .4byte 0x020229AC
_080299F0: .4byte 0x00003008
_080299F4: .4byte 0x00003009
_080299F8: .4byte 0x00003014
_080299FC:
	ldr r4, _08029A44
	ldr r0, [r4]
	ldr r1, _08029A48
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _08029A14
	b _08029D10
_08029A14:
	ldr r0, _08029A4C
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08029A22
	b _08029D10
_08029A22:
	movs r0, #0
	strh r0, [r2]
	movs r0, #5
	bl PlaySE
	bl sub_08027508
	ldr r1, _08029A50
	cmp r0, r1
	bhi _08029A58
	ldr r0, [r4]
	ldr r2, _08029A54
	adds r0, r0, r2
	movs r1, #0x7f
	strb r1, [r0]
	b _08029A68
	.align 2, 0
_08029A44: .4byte 0x020229AC
_08029A48: .4byte 0x0000301C
_08029A4C: .4byte 0x03002360
_08029A50: .4byte 0x00000BB7
_08029A54: .4byte 0x00003014
_08029A58:
	bl StopMapMusic
	ldr r1, [r4]
	ldr r0, _08029AAC
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08029A68:
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #5
	bl FillBgTilemapBufferRect_Palette0
	ldr r5, _08029AB0
	ldr r0, [r5]
	ldr r4, _08029AB4
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r6, _08029AB8
	adds r0, r6, #0
	bl AddWindow
	ldr r1, [r5]
	adds r1, r1, r4
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, #0
	bl sub_08028EA0
	b _08029D10
	.align 2, 0
_08029AAC: .4byte 0x00003014
_08029AB0: .4byte 0x020229AC
_08029AB4: .4byte 0x00003009
_08029AB8: .4byte 0x082CB458
_08029ABC:
	ldr r0, _08029B94
	bl PlayNewMapMusic
	ldr r4, _08029B98
	ldr r0, [r4]
	ldr r6, _08029B9C
	adds r0, r0, r6
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, _08029BA0
	mov sl, r1
	add r0, sl
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r5, _08029BA4
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #0
	adds r1, r5, #0
	bl GetStringWidth
	adds r1, r0, #0
	movs r0, #0xe0
	subs r0, r0, r1
	lsrs r3, r0, #1
	ldr r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r2, #2
	mov sb, r2
	str r2, [sp]
	movs r1, #0xff
	mov r8, r1
	str r1, [sp, #4]
	movs r6, #0
	str r6, [sp, #8]
	movs r1, #0
	adds r2, r5, #0
	bl AddTextPrinterParameterized
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_080273EC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08029BA8
	adds r1, r5, #0
	bl CopyItemName
	movs r0, #0
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r7, _08029BAC
	ldr r1, _08029BB0
	adds r0, r7, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r4]
	add r0, sl
	ldrb r0, [r0]
	mov r2, sb
	str r2, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r6, [sp, #8]
	movs r1, #0
	adds r2, r7, #0
	movs r3, #8
	bl AddTextPrinterParameterized
	bl sub_08027788
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, r4, #0
	cmp r4, #0
	beq _08029BE2
	cmp r4, #3
	beq _08029BE2
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_080273EC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl CopyItemName
	movs r0, #0
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	cmp r4, #2
	bne _08029BB8
	ldr r1, _08029BB4
	adds r0, r7, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	b _08029BC4
	.align 2, 0
_08029B94: .4byte 0x0000016F
_08029B98: .4byte 0x020229AC
_08029B9C: .4byte 0x00003008
_08029BA0: .4byte 0x00003009
_08029BA4: .4byte 0x085CCD68
_08029BA8: .4byte 0x02021C40
_08029BAC: .4byte 0x02021C7C
_08029BB0: .4byte 0x085CCD86
_08029BB4: .4byte 0x085CCD9F
_08029BB8:
	cmp r6, #1
	bne _08029BC4
	ldr r1, _08029C08
	adds r0, r7, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
_08029BC4:
	ldr r0, _08029C0C
	ldr r0, [r0]
	ldr r2, _08029C10
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r2, _08029C14
	movs r1, #0x28
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r3, #8
	bl AddTextPrinterParameterized
_08029BE2:
	ldr r4, _08029C0C
	ldr r0, [r4]
	ldr r1, _08029C18
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, _08029C10
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, _08029C1C
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_08029C08: .4byte 0x085CCDAB
_08029C0C: .4byte 0x020229AC
_08029C10: .4byte 0x00003009
_08029C14: .4byte 0x02021C7C
_08029C18: .4byte 0x00003008
_08029C1C: .4byte 0x00003014
_08029C20:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08029C44
	ldr r4, _08029C60
	ldr r0, [r4]
	ldr r1, _08029C64
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, _08029C68
	adds r0, r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029C44:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _08029C6C
	movs r1, #0x14
	movs r2, #0xa
	bl FadeOutAndFadeInNewMapMusic
	ldr r0, _08029C60
	ldr r1, [r0]
	ldr r0, _08029C70
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_08029C60: .4byte 0x020229AC
_08029C64: .4byte 0x00003008
_08029C68: .4byte 0x00003009
_08029C6C: .4byte 0x0000020B
_08029C70: .4byte 0x00003014
_08029C74:
	ldr r4, _08029CB0
	ldr r0, [r4]
	ldr r1, _08029CB4
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08029D10
	ldr r0, _08029CB8
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029D10
	movs r0, #0
	strh r0, [r2]
	movs r0, #5
	bl PlaySE
_08029CA0:
	ldr r1, [r4]
_08029CA2:
	ldr r2, _08029CBC
	adds r1, r1, r2
_08029CA6:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08029D10
	.align 2, 0
_08029CB0: .4byte 0x020229AC
_08029CB4: .4byte 0x0000301C
_08029CB8: .4byte 0x03002360
_08029CBC: .4byte 0x00003014
_08029CC0:
	ldr r5, _08029D20
	adds r0, r1, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	ldr r4, _08029D24
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r5
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_08029D10:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029D20: .4byte 0x00003008
_08029D24: .4byte 0x00003009
	thumb_func_end sub_080295A4

	thumb_func_start sub_08029D28
sub_08029D28: @ 0x08029D28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r1, _08029D50
	ldr r2, [r1]
	ldr r3, _08029D54
	adds r0, r2, r3
	ldrb r7, [r0]
	adds r6, r1, #0
	cmp r7, #1
	beq _08029DDC
	cmp r7, #1
	bgt _08029D58
	cmp r7, #0
	beq _08029D66
	b _08029FF4
	.align 2, 0
_08029D50: .4byte 0x020229AC
_08029D54: .4byte 0x00003014
_08029D58:
	cmp r7, #2
	bne _08029D5E
	b _08029EA0
_08029D5E:
	cmp r7, #3
	bne _08029D64
	b _08029ED4
_08029D64:
	b _08029FF4
_08029D66:
	ldr r0, _08029DC4
	bl AddWindow
	ldr r1, [r6]
	ldr r5, _08029DC8
	adds r1, r1, r5
	strb r0, [r1]
	ldr r0, _08029DC4
	adds r0, #8
	mov r8, r0
	bl AddWindow
	ldr r1, [r6]
	ldr r4, _08029DCC
	adds r1, r1, r4
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, _08029DC4
	bl sub_08028EA0
	mov r0, r8
	bl sub_08028DA0
	ldr r1, [r6]
	ldr r2, _08029DD0
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r3, _08029DD4
	adds r0, r0, r3
	strb r7, [r0]
	ldr r0, [r6]
	ldr r1, _08029DD8
	adds r0, r0, r1
	strb r7, [r0]
	b _0802A054
	.align 2, 0
_08029DC4: .4byte 0x082CB460
_08029DC8: .4byte 0x00003008
_08029DCC: .4byte 0x00003009
_08029DD0: .4byte 0x00003014
_08029DD4: .4byte 0x00003020
_08029DD8: .4byte 0x00003024
_08029DDC:
	ldr r3, _08029E84
	mov r8, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	ldr r7, _08029E88
	adds r0, r0, r7
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, _08029E8C
	movs r1, #6
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #8
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	ldr r2, _08029E90
	movs r3, #2
	mov sb, r3
	str r3, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0xc
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	ldr r2, _08029E94
	movs r1, #0x12
	str r1, [sp]
	movs r3, #0xff
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0xc
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	ldr r2, _08029E98
	mov r1, sb
	str r1, [sp]
	movs r3, #0xff
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r6]
	ldr r0, _08029E9C
	adds r1, r1, r0
	b _08029FE8
	.align 2, 0
_08029E84: .4byte 0x00003008
_08029E88: .4byte 0x00003009
_08029E8C: .4byte 0x085CCDBD
_08029E90: .4byte 0x085CAAD8
_08029E94: .4byte 0x085CAADB
_08029E98: .4byte 0x085C9421
_08029E9C: .4byte 0x00003014
_08029EA0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08029EC2
	ldr r0, [r6]
	ldr r1, _08029ECC
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r6]
	ldr r2, _08029ED0
	adds r0, r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029EC2:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	b _08029FE2
	.align 2, 0
_08029ECC: .4byte 0x00003008
_08029ED0: .4byte 0x00003009
_08029ED4:
	ldr r0, _08029F7C
	mov sl, r0
	adds r0, r2, r0
	ldrb r7, [r0]
	cmp r7, #0
	bne _08029EE2
	movs r7, #1
_08029EE2:
	ldr r1, _08029F80
	mov r8, r1
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, _08029F84
	movs r3, #2
	mov sb, r3
	str r3, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0xc
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, _08029F88
	movs r1, #0x12
	str r1, [sp]
	movs r3, #0xff
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0xc
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, _08029F8C
	subs r1, r7, #1
	lsls r1, r1, #4
	adds r1, #2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram
	ldr r0, _08029F90
	ldrh r1, [r0, #0x2e]
	movs r4, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029F94
	movs r0, #5
	bl PlaySE
	ldr r0, [r6]
	mov r2, sl
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _08029FE2
	strb r4, [r1]
	b _08029FE2
	.align 2, 0
_08029F7C: .4byte 0x00003020
_08029F80: .4byte 0x00003009
_08029F84: .4byte 0x085CAAD8
_08029F88: .4byte 0x085CAADB
_08029F8C: .4byte 0x085C9421
_08029F90: .4byte 0x03002360
_08029F94:
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _08029FCC
	movs r0, #5
	bl PlaySE
	ldr r0, [r6]
	add r0, sl
	ldrb r2, [r0]
	cmp r2, #1
	beq _08029FC2
	cmp r2, #1
	bgt _08029FB6
	cmp r2, #0
	beq _08029FBC
	b _0802A054
_08029FB6:
	cmp r2, #2
	beq _08029FC8
	b _0802A054
_08029FBC:
	mov r1, sb
	strb r1, [r0]
	b _0802A054
_08029FC2:
	mov r2, sb
	strb r2, [r0]
	b _0802A054
_08029FC8:
	strb r4, [r0]
	b _0802A054
_08029FCC:
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0802A054
	movs r0, #5
	bl PlaySE
	ldr r0, [r6]
	add r0, sl
	movs r1, #2
	strb r1, [r0]
_08029FE2:
	ldr r1, [r6]
	ldr r3, _08029FF0
	adds r1, r1, r3
_08029FE8:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A054
	.align 2, 0
_08029FF0: .4byte 0x00003014
_08029FF4:
	ldr r0, [r6]
	ldr r2, _0802A064
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0802A068
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	ldr r7, _0802A06C
	adds r0, r0, r7
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	ldr r4, _0802A070
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_0802A054:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A064: .4byte 0x00003020
_0802A068: .4byte 0x00003024
_0802A06C: .4byte 0x00003008
_0802A070: .4byte 0x00003009
	thumb_func_end sub_08029D28

	thumb_func_start sub_0802A074
sub_0802A074: @ 0x0802A074
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r5, _0802A090
	ldr r0, [r5]
	ldr r6, _0802A094
	adds r0, r0, r6
	ldrb r4, [r0]
	cmp r4, #1
	beq _0802A0CC
	cmp r4, #1
	bgt _0802A098
	cmp r4, #0
	beq _0802A0A2
	b _0802A114
	.align 2, 0
_0802A090: .4byte 0x020229AC
_0802A094: .4byte 0x00003014
_0802A098:
	cmp r4, #2
	beq _0802A0E0
	cmp r4, #3
	beq _0802A0F8
	b _0802A114
_0802A0A2:
	movs r0, #0
	movs r1, #0
	bl DrawDialogueFrame
	ldr r2, _0802A0C8
	str r4, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized2
	b _0802A104
	.align 2, 0
_0802A0C8: .4byte 0x08277071
_0802A0CC:
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, _0802A0DC
	adds r1, r1, r0
	b _0802A108
	.align 2, 0
_0802A0DC: .4byte 0x00003014
_0802A0E0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A13C
	ldr r0, _0802A0F4
	movs r1, #0
	bl CreateTask
	b _0802A104
	.align 2, 0
_0802A0F4: .4byte 0x081535C5
_0802A0F8:
	ldr r0, _0802A110
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A13C
_0802A104:
	ldr r1, [r5]
	adds r1, r1, r6
_0802A108:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A13C
	.align 2, 0
_0802A110: .4byte 0x081535C5
_0802A114:
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _0802A144
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_0802A13C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802A144: .4byte 0x020229AC
	thumb_func_end sub_0802A074

	thumb_func_start sub_0802A148
sub_0802A148: @ 0x0802A148
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r1, _0802A168
	ldr r2, [r1]
	ldr r6, _0802A16C
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #1
	beq _0802A1A0
	cmp r0, #1
	bgt _0802A170
	cmp r0, #0
	beq _0802A176
	b _0802A214
	.align 2, 0
_0802A168: .4byte 0x020229AC
_0802A16C: .4byte 0x00003014
_0802A170:
	cmp r0, #2
	beq _0802A1E8
	b _0802A214
_0802A176:
	ldr r4, _0802A198
	adds r0, r4, #0
	bl AddWindow
	ldr r1, [r5]
	ldr r2, _0802A19C
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, #0
	bl sub_08028EA0
	b _0802A204
	.align 2, 0
_0802A198: .4byte 0x082CB478
_0802A19C: .4byte 0x00003008
_0802A1A0:
	ldr r4, _0802A1DC
	adds r0, r2, r4
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r2, _0802A1E0
	movs r1, #6
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #4
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, _0802A1E4
	adds r1, r1, r0
	b _0802A208
	.align 2, 0
_0802A1DC: .4byte 0x00003008
_0802A1E0: .4byte 0x085CCDEA
_0802A1E4: .4byte 0x00003014
_0802A1E8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A1FE
	ldr r0, [r5]
	ldr r1, _0802A210
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A1FE:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
_0802A204:
	ldr r1, [r5]
	adds r1, r1, r6
_0802A208:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A220
	.align 2, 0
_0802A210: .4byte 0x00003008
_0802A214:
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_0802A220:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_0802A148

	thumb_func_start sub_0802A228
sub_0802A228: @ 0x0802A228
	push {r4, r5, lr}
	sub sp, #8
	ldr r5, _0802A274
	ldr r0, [r5]
	ldr r4, _0802A278
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802A274: .4byte 0x020229AC
_0802A278: .4byte 0x00003008
	thumb_func_end sub_0802A228

	thumb_func_start sub_0802A27C
sub_0802A27C: @ 0x0802A27C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _0802A29C
	ldr r1, [r0]
	ldr r7, _0802A2A0
	adds r2, r1, r7
	ldrb r5, [r2]
	adds r6, r0, #0
	cmp r5, #1
	beq _0802A304
	cmp r5, #1
	bgt _0802A2A4
	cmp r5, #0
	beq _0802A2AE
	b _0802A398
	.align 2, 0
_0802A29C: .4byte 0x020229AC
_0802A2A0: .4byte 0x00003014
_0802A2A4:
	cmp r5, #2
	beq _0802A34C
	cmp r5, #3
	beq _0802A378
	b _0802A398
_0802A2AE:
	ldr r4, _0802A2F4
	adds r0, r4, #0
	bl AddWindow
	ldr r1, [r6]
	ldr r2, _0802A2F8
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, #0
	bl sub_08028EA0
	ldr r1, [r6]
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r2, _0802A2FC
	adds r1, r0, r2
	movs r2, #0
	strh r5, [r1]
	ldr r1, _0802A300
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r1, #4
	adds r0, r0, r1
	strb r2, [r0]
	b _0802A3DE
	.align 2, 0
_0802A2F4: .4byte 0x082CB470
_0802A2F8: .4byte 0x00003008
_0802A2FC: .4byte 0x0000301C
_0802A300: .4byte 0x00003020
_0802A304:
	ldr r4, _0802A340
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r2, _0802A344
	movs r1, #6
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r6]
	ldr r2, _0802A348
	adds r1, r1, r2
	b _0802A36C
	.align 2, 0
_0802A340: .4byte 0x00003008
_0802A344: .4byte 0x085CCDCB
_0802A348: .4byte 0x00003014
_0802A34C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A362
	ldr r0, [r6]
	ldr r1, _0802A374
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A362:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r6]
	adds r1, r1, r7
_0802A36C:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A3DE
	.align 2, 0
_0802A374: .4byte 0x00003008
_0802A378:
	ldr r0, _0802A394
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0802A3DE
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0802A3DE
	.align 2, 0
_0802A394: .4byte 0x0000301C
_0802A398:
	ldr r0, [r6]
	ldr r1, _0802A3E8
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, _0802A3EC
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r0, r0, r2
	movs r1, #1
	str r1, [r0]
_0802A3DE:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A3E8: .4byte 0x00003024
_0802A3EC: .4byte 0x00003008
	thumb_func_end sub_0802A27C

	thumb_func_start sub_0802A3F0
sub_0802A3F0: @ 0x0802A3F0
	push {r4, lr}
	ldr r4, _0802A414
	ldr r0, [r4]
	ldr r1, _0802A418
	adds r0, r0, r1
	ldrb r0, [r0]
	bl DestroyTask
	ldr r0, [r4]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A414: .4byte 0x020229AC
_0802A418: .4byte 0x00003004
	thumb_func_end sub_0802A3F0

	thumb_func_start sub_0802A41C
sub_0802A41C: @ 0x0802A41C
	bx lr
	.align 2, 0
	thumb_func_end sub_0802A41C

	thumb_func_start sub_0802A420
sub_0802A420: @ 0x0802A420
	push {r4, lr}
	ldr r2, _0802A444
	ldr r1, [r2]
	ldr r3, _0802A448
	adds r1, r1, r3
	movs r3, #0
	strb r3, [r1]
	ldr r1, [r2]
	movs r4, #0xc0
	lsls r4, r4, #6
	adds r2, r1, r4
	str r3, [r2]
	ldr r2, _0802A44C
	adds r1, r1, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A444: .4byte 0x020229AC
_0802A448: .4byte 0x00003014
_0802A44C: .4byte 0x00003028
	thumb_func_end sub_0802A420

	thumb_func_start sub_0802A450
sub_0802A450: @ 0x0802A450
	ldr r0, _0802A45C
	ldr r0, [r0]
	ldr r1, _0802A460
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0802A45C: .4byte 0x020229AC
_0802A460: .4byte 0x00003028
	thumb_func_end sub_0802A450

	thumb_func_start sub_0802A464
sub_0802A464: @ 0x0802A464
	push {lr}
	ldr r0, _0802A47C
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _0802A480
	movs r0, #1
	b _0802A482
	.align 2, 0
_0802A47C: .4byte 0x020229AC
_0802A480:
	movs r0, #0
_0802A482:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802A464

	thumb_func_start sub_0802A488
sub_0802A488: @ 0x0802A488
	ldr r0, _0802A494
	ldr r0, [r0]
	ldr r1, _0802A498
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0802A494: .4byte 0x020229AC
_0802A498: .4byte 0x00003024
	thumb_func_end sub_0802A488

	thumb_func_start sub_0802A49C
sub_0802A49C: @ 0x0802A49C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	movs r3, #0xc0
	lsls r3, r3, #0x13
	movs r4, #0xc0
	lsls r4, r4, #9
	add r0, sp, #4
	mov r8, r0
	mov r2, sp
	movs r6, #0
	ldr r1, _0802A5CC
	movs r5, #0x80
	lsls r5, r5, #5
	ldr r7, _0802A5D0
	movs r0, #0x81
	lsls r0, r0, #0x18
	mov ip, r0
_0802A4C2:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, #4]
	str r7, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, r3, r5
	subs r4, r4, r5
	cmp r4, r5
	bhi _0802A4C2
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, #4]
	lsrs r0, r4, #1
	mov r2, ip
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	movs r3, #0x80
	lsls r3, r3, #3
	movs r4, #0
	str r4, [sp, #4]
	ldr r2, _0802A5CC
	mov r1, r8
	str r1, [r2]
	str r0, [r2, #4]
	lsrs r0, r3, #2
	movs r1, #0x85
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	lsrs r3, r3, #1
	movs r0, #0x81
	lsls r0, r0, #0x18
	orrs r3, r0
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, _0802A5D4
	movs r0, #0
	movs r2, #4
	bl InitBgsFromTemplates
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	bl InitStandardTextBoxWindows
	bl sub_08196DF4
	movs r1, #0x82
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r4, _0802A5D8
	ldr r1, [r4]
	movs r0, #3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	movs r0, #1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	adds r1, r1, r0
	movs r0, #2
	bl SetBgTilemapBuffer
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A5CC: .4byte 0x040000D4
_0802A5D0: .4byte 0x81000800
_0802A5D4: .4byte 0x082CB430
_0802A5D8: .4byte 0x020229AC
	thumb_func_end sub_0802A49C

	thumb_func_start sub_0802A5DC
sub_0802A5DC: @ 0x0802A5DC
	push {lr}
	sub sp, #4
	ldr r0, _0802A5F8
	ldr r0, [r0]
	ldr r2, _0802A5FC
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #5
	bhi _0802A676
	lsls r0, r0, #2
	ldr r1, _0802A600
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A5F8: .4byte 0x020229AC
_0802A5FC: .4byte 0x00003018
_0802A600: .4byte 0x0802A604
_0802A604: @ jump table
	.4byte _0802A61C @ case 0
	.4byte _0802A62C @ case 1
	.4byte _0802A632 @ case 2
	.4byte _0802A640 @ case 3
	.4byte _0802A658 @ case 4
	.4byte _0802A666 @ case 5
_0802A61C:
	ldr r0, _0802A628
	movs r1, #0
	movs r2, #0x40
	bl LoadPalette
	b _0802A67E
	.align 2, 0
_0802A628: .4byte 0x082CB67C
_0802A62C:
	bl ResetTempTileDataBuffers
	b _0802A67E
_0802A632:
	ldr r1, _0802A63C
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	b _0802A648
	.align 2, 0
_0802A63C: .4byte 0x082CB910
_0802A640:
	ldr r1, _0802A654
	movs r0, #0
	str r0, [sp]
	movs r0, #1
_0802A648:
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	b _0802A67E
	.align 2, 0
_0802A654: .4byte 0x082CC1A0
_0802A658:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0802A67E
	b _0802A68C
_0802A666:
	movs r0, #3
	bl GetTextWindowPalette
	movs r1, #0xd0
	movs r2, #0x20
	bl LoadPalette
	b _0802A67E
_0802A676:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0802A68E
_0802A67E:
	ldr r0, _0802A694
	ldr r1, [r0]
	ldr r0, _0802A698
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802A68C:
	movs r0, #0
_0802A68E:
	add sp, #4
	pop {r1}
	bx r1
	.align 2, 0
_0802A694: .4byte 0x020229AC
_0802A698: .4byte 0x00003018
	thumb_func_end sub_0802A5DC
