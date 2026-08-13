.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	.section .text.battle_anim_effects_3_rest,"ax",%progbits

	thumb_func_start sub_0815A440
sub_0815A440: @ 0x0815A440
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0815A45C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldr r0, _0815A460
	str r0, [r1]
	ldr r1, _0815A464
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0815A45C: .4byte 0x03005B60
_0815A460: .4byte 0x0815A469
_0815A464: .4byte 0x0203809E
	thumb_func_end sub_0815A440

	thumb_func_start sub_0815A468
sub_0815A468: @ 0x0815A468
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_080A665C
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r7, _0815A4F4
	lsls r5, r4, #2
	adds r1, r5, r4
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrh r0, [r1, #0x12]
	adds r0, #1
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _0815A4D8
	ldr r0, _0815A4F8
	lsls r2, r6, #4
	adds r1, r2, #0
	adds r1, #0xb
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r3, [r1]
	mov r8, r3
	movs r3, #0xa
	mov sb, r7
	adds r7, r5, #0
	mov ip, r0
	adds r5, r2, #0
	lsls r0, r6, #5
	add r0, ip
	adds r2, r0, #0
	adds r2, #0x14
_0815A4B6:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r2, #2
	subs r1, #2
	subs r3, #1
	cmp r3, #0
	bgt _0815A4B6
	adds r0, r5, #1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	mov r2, r8
	strh r2, [r0]
	adds r0, r7, r4
	lsls r0, r0, #3
	add r0, sb
	strh r1, [r0, #0x12]
_0815A4D8:
	ldr r0, _0815A4FC
	ldrh r1, [r0, #0xe]
	ldr r0, _0815A500
	cmp r1, r0
	bne _0815A4E8
	adds r0, r4, #0
	bl DestroyTask
_0815A4E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815A4F4: .4byte 0x03005B60
_0815A4F8: .4byte 0x020377B4
_0815A4FC: .4byte 0x020380BE
_0815A500: .4byte 0x0000FFFF
	thumb_func_end sub_0815A468


	.section .text.battle_anim_effects_3_rest5,"ax",%progbits







	thumb_func_start sub_0815B70C
sub_0815B70C: @ 0x0815B70C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r1, _0815B73C
	lsls r0, r0, #2
	add r0, r8
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #8
	ldrsh r0, [r0, r2]
	adds r3, r1, #0
	cmp r0, #4
	bls _0815B732
	b _0815BA38
_0815B732:
	lsls r0, r0, #2
	ldr r1, _0815B740
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815B73C: .4byte 0x03005B60
_0815B740: .4byte 0x0815B744
_0815B744: @ jump table
	.4byte _0815B758 @ case 0
	.4byte _0815B7A8 @ case 1
	.4byte _0815B7E4 @ case 2
	.4byte _0815B980 @ case 3
	.4byte _0815B9BE @ case 4
_0815B758:
	movs r0, #0x4c
	movs r1, #0
	bl SetGpuReg
	ldr r0, _0815B77C
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815B780
	movs r0, #1
	movs r1, #2
	movs r2, #1
	bl SetAnimBgAttribute
	b _0815B78A
	.align 2, 0
_0815B77C: .4byte 0x020380D6
_0815B780:
	movs r0, #2
	movs r1, #2
	movs r2, #1
	bl SetAnimBgAttribute
_0815B78A:
	ldr r0, _0815B7A0
	mov r6, r8
	lsls r1, r6, #2
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _0815B7A4
	ldrh r0, [r0]
	strh r0, [r1, #0x1c]
	b _0815B962
	.align 2, 0
_0815B7A0: .4byte 0x03005B60
_0815B7A4: .4byte 0x020380BE
_0815B7A8:
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r0, r0, #3
	adds r4, r0, r3
	ldrh r0, [r4, #0xc]
	adds r1, r0, #1
	strh r1, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _0815B7C2
	b _0815BA38
_0815B7C2:
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	ldrh r5, [r4, #0xa]
	lsls r1, r5, #4
	orrs r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x4c
	bl SetGpuReg
	cmp r5, #0xf
	beq _0815B7E2
	b _0815BA38
_0815B7E2:
	b _0815B9B6
_0815B7E4:
	ldr r5, _0815B814
	ldrb r0, [r5]
	ldr r1, _0815B818
	ldrb r1, [r1]
	mov r2, r8
	lsls r4, r2, #2
	adds r2, r4, r2
	lsls r2, r2, #3
	adds r2, r2, r3
	ldrb r2, [r2, #0x1c]
	bl HandleSpeciesGfxDataChange
	ldrb r1, [r5]
	mov r0, sp
	bl sub_080A64C4
	bl IsContest
	lsls r0, r0, #0x18
	mov sb, r4
	cmp r0, #0
	beq _0815B81C
	movs r1, #0
	b _0815B826
	.align 2, 0
_0815B814: .4byte 0x020380D6
_0815B818: .4byte 0x020380D7
_0815B81C:
	ldrb r0, [r5]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0815B826:
	ldr r0, _0815B908
	ldr r2, [r0]
	lsls r0, r1, #2
	adds r2, #4
	adds r2, r2, r0
	ldr r1, _0815B90C
	ldr r0, _0815B910
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r1, r1, #0xb
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, [sp]
	ldr r2, _0815B914
	bl CpuSet
	ldr r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #4
	mov r0, sp
	ldrh r3, [r0, #0xa]
	movs r0, #1
	bl LoadBgTiles
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815B958
	ldr r5, _0815B918
	ldr r0, [r5]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0]
	bl IsSpeciesNotUnown
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #2]
	bl IsSpeciesNotUnown
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0815B8D8
	ldr r6, [sp, #4]
	movs r5, #0
	movs r0, #7
	mov ip, r0
	movs r7, #0
_0815B88C:
	movs r4, #0
	adds r3, r7, r6
	mov r1, ip
	lsls r0, r1, #1
	adds r2, r0, r6
_0815B896:
	ldrh r1, [r3]
	ldrh r0, [r2]
	strh r0, [r3]
	strh r1, [r2]
	adds r3, #2
	subs r2, #2
	adds r4, #1
	cmp r4, #3
	ble _0815B896
	movs r2, #0x20
	add ip, r2
	adds r7, #0x40
	adds r5, #1
	cmp r5, #7
	ble _0815B88C
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #3
	adds r3, r0, #0
_0815B8BC:
	adds r2, r5, #1
	lsls r0, r5, #6
	adds r1, r0, r6
	movs r4, #7
_0815B8C4:
	ldrh r0, [r1]
	eors r0, r3
	strh r0, [r1]
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0815B8C4
	adds r5, r2, #0
	cmp r5, #7
	ble _0815B8BC
_0815B8D8:
	ldr r0, _0815B918
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #2]
	bl IsSpeciesNotUnown
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815B928
	ldr r3, _0815B91C
	ldr r4, _0815B920
	ldr r2, _0815B910
	ldrb r0, [r2]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _0815B924
	b _0815B942
	.align 2, 0
_0815B908: .4byte 0x02024178
_0815B90C: .4byte 0x02024188
_0815B910: .4byte 0x020380D6
_0815B914: .4byte 0x04000200
_0815B918: .4byte 0x02039BD4
_0815B91C: .4byte 0x020205AC
_0815B920: .4byte 0x02023E88
_0815B924: .4byte 0x082D2F50
_0815B928:
	ldr r3, _0815B96C
	ldr r4, _0815B970
	ldr r2, _0815B974
	ldrb r0, [r2]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _0815B978
_0815B942:
	str r1, [r0]
	ldrb r0, [r2]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #0
	bl StartSpriteAffineAnim
_0815B958:
	ldr r0, _0815B97C
	mov r1, sb
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
_0815B962:
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0815BA38
	.align 2, 0
_0815B96C: .4byte 0x020205AC
_0815B970: .4byte 0x02023E88
_0815B974: .4byte 0x020380D6
_0815B978: .4byte 0x082D2F24
_0815B97C: .4byte 0x03005B60
_0815B980:
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r0, r0, #3
	adds r4, r0, r3
	ldrh r0, [r4, #0xc]
	adds r1, r0, #1
	strh r1, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0815BA38
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xa]
	subs r0, #1
	strh r0, [r4, #0xa]
	ldrh r5, [r4, #0xa]
	lsls r1, r5, #4
	orrs r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x4c
	bl SetGpuReg
	cmp r5, #0
	bne _0815BA38
_0815B9B6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815BA38
_0815B9BE:
	movs r0, #0x4c
	movs r1, #0
	bl SetGpuReg
	ldr r0, _0815B9E4
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815B9E8
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl SetAnimBgAttribute
	b _0815B9F2
	.align 2, 0
_0815B9E4: .4byte 0x020380D6
_0815B9E8:
	movs r0, #2
	movs r1, #2
	movs r2, #0
	bl SetAnimBgAttribute
_0815B9F2:
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815BA32
	ldr r4, _0815BA48
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815BA32
	ldr r0, _0815BA4C
	mov r2, r8
	lsls r1, r2, #2
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r6, #0x1c
	ldrsh r0, [r1, r6]
	cmp r0, #0
	bne _0815BA32
	ldrb r0, [r4]
	ldr r1, _0815BA50
	ldr r1, [r1]
	ldr r2, [r1]
	lsls r1, r0, #2
	adds r1, r1, r2
	ldrh r1, [r1, #2]
	bl SetBattlerShadowSpriteCallback
_0815BA32:
	mov r0, r8
	bl DestroyAnimVisualTask
_0815BA38:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815BA48: .4byte 0x020380D6
_0815BA4C: .4byte 0x03005B60
_0815BA50: .4byte 0x02024174
	thumb_func_end sub_0815B70C




