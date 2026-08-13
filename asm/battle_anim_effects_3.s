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

	thumb_func_start sub_0815BA54
sub_0815BA54: @ 0x0815BA54
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _0815BA84
	ldr r3, _0815BA88
	ldr r2, _0815BA8C
	ldr r1, _0815BA90
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	adds r1, #0x3e
	ldrb r1, [r1]
	lsls r1, r1, #0x1d
	lsrs r1, r1, #0x1f
	strh r1, [r4, #0xe]
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815BA84: .4byte 0x020380BE
_0815BA88: .4byte 0x020205AC
_0815BA8C: .4byte 0x02023E88
_0815BA90: .4byte 0x020380D6
	thumb_func_end sub_0815BA54

	thumb_func_start sub_0815BA94
sub_0815BA94: @ 0x0815BA94
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _0815BAB8
	ldrb r0, [r0]
	ldr r1, _0815BABC
	ldrb r1, [r1]
	movs r2, #1
	bl HandleSpeciesGfxDataChange
	adds r0, r4, #0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815BAB8: .4byte 0x020380D6
_0815BABC: .4byte 0x020380D7
	thumb_func_end sub_0815BA94

	thumb_func_start sub_0815BAC0
sub_0815BAC0: @ 0x0815BAC0
	push {r4, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _0815BAE8
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #8
	ldrsh r0, [r0, r2]
	adds r2, r1, #0
	cmp r0, #4
	bls _0815BADE
	b _0815BD2E
_0815BADE:
	lsls r0, r0, #2
	ldr r1, _0815BAEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815BAE8: .4byte 0x03005B60
_0815BAEC: .4byte 0x0815BAF0
_0815BAF0: @ jump table
	.4byte _0815BB04 @ case 0
	.4byte _0815BBF4 @ case 1
	.4byte _0815BC44 @ case 2
	.4byte _0815BCAE @ case 3
	.4byte _0815BCE2 @ case 4
_0815BB04:
	ldr r1, _0815BB60
	movs r0, #0x50
	bl SetGpuReg
	movs r1, #0x80
	lsls r1, r1, #5
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetAnimBgAttribute
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815BB3E
	movs r0, #1
	movs r1, #3
	movs r2, #1
	bl SetAnimBgAttribute
_0815BB3E:
	mov r0, sp
	bl sub_080A63F8
	ldr r1, _0815BB64
	mov r0, sp
	movs r2, #0
	bl sub_080A6628
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815BB70
	ldr r1, _0815BB68
	ldr r3, _0815BB6C
	b _0815BB98
	.align 2, 0
_0815BB60: .4byte 0x00003F42
_0815BB64: .4byte 0x08C2A790
_0815BB68: .4byte 0x02022ACC
_0815BB6C: .4byte 0x0000FFC8
_0815BB70:
	ldr r0, _0815BB88
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815BB94
	ldr r1, _0815BB8C
	ldr r2, _0815BB90
	adds r0, r2, #0
	b _0815BB9A
	.align 2, 0
_0815BB88: .4byte 0x020380D6
_0815BB8C: .4byte 0x02022ACC
_0815BB90: .4byte 0x0000FF79
_0815BB94:
	ldr r1, _0815BBDC
	ldr r3, _0815BBE0
_0815BB98:
	adds r0, r3, #0
_0815BB9A:
	strh r0, [r1]
	ldr r1, _0815BBE4
	movs r0, #0
	strh r0, [r1]
	mov r0, sp
	ldrb r0, [r0, #9]
	ldr r1, _0815BBE8
	mov r2, sp
	ldrh r2, [r2, #0xa]
	bl AnimLoadCompressedBgGfx
	ldr r0, _0815BBEC
	mov r1, sp
	ldrb r1, [r1, #8]
	lsls r1, r1, #4
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r0, _0815BBF0
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _0815BBDC
	ldrh r0, [r0]
	strh r0, [r1, #0x1c]
	ldr r0, _0815BBE4
	ldrh r0, [r0]
	strh r0, [r1, #0x1e]
	ldrh r0, [r1, #8]
	adds r0, #1
	b _0815BCCA
	.align 2, 0
_0815BBDC: .4byte 0x02022ACC
_0815BBE0: .4byte 0x0000FFF6
_0815BBE4: .4byte 0x02022ACE
_0815BBE8: .4byte 0x08C2A6D8
_0815BBEC: .4byte 0x08C2A778
_0815BBF0: .4byte 0x03005B60
_0815BBF4:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r4, r0, r2
	ldrh r0, [r4, #0x10]
	adds r1, r0, #1
	strh r1, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0815BC0A
	b _0815BD2E
_0815BC0A:
	movs r0, #0
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble _0815BC20
	movs r0, #0xc
	strh r0, [r4, #0xa]
_0815BC20:
	ldrh r0, [r4, #0xa]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0xc
	bne _0815BD2E
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815BD2E
_0815BC44:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r4, r0, r2
	ldrh r0, [r4, #0xa]
	subs r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0815BC5C
	movs r0, #0
	strh r0, [r4, #0xa]
_0815BC5C:
	ldrh r0, [r4, #0xa]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _0815BD2E
	ldr r2, _0815BCA0
	ldr r1, _0815BCA4
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _0815BCA8
	strh r0, [r4, #8]
	b _0815BD2E
	.align 2, 0
_0815BCA0: .4byte 0x02022ACC
_0815BCA4: .4byte 0x085AD268
_0815BCA8:
	movs r0, #3
	strh r0, [r4, #8]
	b _0815BD2E
_0815BCAE:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r1, r0, r2
	ldrh r0, [r1, #0xe]
	adds r0, #1
	strh r0, [r1, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _0815BD2E
	movs r0, #0
	strh r0, [r1, #0xe]
	movs r0, #1
_0815BCCA:
	strh r0, [r1, #8]
	movs r0, #0x40
	rsbs r0, r0, #0
	bl BattleAnimAdjustPanning
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0xe4
	bl PlaySE12WithPanning
	b _0815BD2E
_0815BCE2:
	mov r0, sp
	bl sub_080A63F8
	mov r0, sp
	ldrb r0, [r0, #9]
	bl sub_080A6530
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815BD04
	movs r0, #1
	movs r1, #3
	movs r2, #0
	bl SetAnimBgAttribute
_0815BD04:
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	ldr r0, _0815BD38
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0815BD3C
	strh r1, [r0]
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	adds r0, r4, #0
	bl DestroyAnimVisualTask
_0815BD2E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815BD38: .4byte 0x02022ACC
_0815BD3C: .4byte 0x02022ACE
	thumb_func_end sub_0815BAC0

	thumb_func_start sub_0815BD40
sub_0815BD40: @ 0x0815BD40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	bl Random2
	lsls r0, r0, #0x10
	movs r1, #0xfc
	lsls r1, r1, #0xe
	ands r1, r0
	lsrs r5, r1, #0x10
	adds r1, r5, #0
	cmp r1, #0x1f
	ble _0815BD6A
	movs r0, #0x20
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0815BD6A:
	ldr r4, _0815BE64
	ldrb r0, [r4]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r5
	strh r0, [r7, #0x20]
	ldrb r0, [r4]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x20
	strh r0, [r7, #0x22]
	ldr r1, _0815BE68
	ldrh r0, [r1]
	strh r0, [r7, #0x30]
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x32]
	ldr r4, _0815BE6C
	movs r0, #0x20
	ldrsh r1, [r7, r0]
	movs r0, #0x22
	ldrsh r2, [r7, r0]
	adds r5, r7, #0
	adds r5, #0x43
	ldrb r3, [r5]
	adds r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	bl CreateSprite
	mov sb, r0
	mov r1, sb
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	movs r0, #0x20
	ldrsh r1, [r7, r0]
	movs r0, #0x22
	ldrsh r2, [r7, r0]
	ldrb r3, [r5]
	adds r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	bl CreateSprite
	mov r8, r0
	mov r1, r8
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	mov r0, sb
	lsls r2, r0, #4
	add r2, sb
	lsls r2, r2, #2
	ldr r1, _0815BE70
	mov sl, r1
	adds r5, r2, r1
	adds r0, r5, #0
	movs r1, #1
	str r2, [sp]
	bl StartSpriteAnim
	mov r0, r8
	lsls r6, r0, #4
	add r6, r8
	lsls r6, r6, #2
	mov r1, sl
	adds r4, r6, r1
	adds r0, r4, #0
	movs r1, #2
	bl StartSpriteAnim
	ldr r1, _0815BE68
	ldrh r0, [r1]
	strh r0, [r5, #0x30]
	ldrh r0, [r1, #2]
	strh r0, [r5, #0x32]
	ldrh r0, [r1]
	strh r0, [r4, #0x30]
	ldrh r0, [r1, #2]
	strh r0, [r4, #0x32]
	ldr r0, _0815BE74
	strh r0, [r5, #0x3c]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r4, #0x3c]
	adds r5, #0x3e
	ldrb r0, [r5]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5]
	adds r4, #0x3e
	ldrb r0, [r4]
	orrs r0, r1
	strb r0, [r4]
	movs r0, #0x1c
	add sl, r0
	ldr r2, [sp]
	add r2, sl
	ldr r0, _0815BE78
	str r0, [r2]
	add r6, sl
	str r0, [r6]
	mov r1, sb
	strh r1, [r7, #0x3a]
	mov r0, r8
	strh r0, [r7, #0x3c]
	ldr r0, _0815BE7C
	str r0, [r7, #0x1c]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815BE64: .4byte 0x020380D6
_0815BE68: .4byte 0x020380BE
_0815BE6C: .4byte 0x085AD294
_0815BE70: .4byte 0x020205AC
_0815BE74: .4byte 0x0000FFFF
_0815BE78: .4byte 0x0815BF8D
_0815BE7C: .4byte 0x0815BE81
	thumb_func_end sub_0815BD40

	thumb_func_start sub_0815BE80
sub_0815BE80: @ 0x0815BE80
	push {lr}
	adds r3, r0, #0
	ldrh r2, [r3, #0x32]
	ldrh r0, [r3, #0x34]
	adds r2, r2, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x18
	ldrh r1, [r3, #0x26]
	subs r1, r1, r0
	strh r1, [r3, #0x26]
	movs r0, #0xff
	ands r2, r0
	strh r2, [r3, #0x34]
	movs r2, #0x36
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne _0815BECE
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0815BECE
	ldr r2, _0815BF28
	movs r0, #0x3a
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	ldrh r0, [r3, #0x36]
	adds r0, #1
	strh r0, [r3, #0x36]
_0815BECE:
	movs r1, #0x36
	ldrsh r0, [r3, r1]
	cmp r0, #1
	bne _0815BF02
	movs r2, #0x26
	ldrsh r1, [r3, r2]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0815BF02
	ldr r2, _0815BF28
	movs r0, #0x3c
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	ldrh r0, [r3, #0x36]
	adds r0, #1
	strh r0, [r3, #0x36]
_0815BF02:
	ldrh r0, [r3, #0x30]
	subs r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0815BF24
	adds r2, r3, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0815BF2C
	str r0, [r3, #0x1c]
_0815BF24:
	pop {r0}
	bx r0
	.align 2, 0
_0815BF28: .4byte 0x020205AC
_0815BF2C: .4byte 0x0815BF31
	thumb_func_end sub_0815BE80

	thumb_func_start sub_0815BF30
sub_0815BF30: @ 0x0815BF30
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, _0815BF84
	movs r0, #0x3a
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r3, r0, #2
	adds r6, r5, #0
	adds r6, #0x1c
	adds r0, r3, r6
	ldr r2, [r0]
	ldr r0, _0815BF88
	cmp r2, r0
	bne _0815BF7C
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r0, [r1]
	cmp r0, r2
	bne _0815BF7C
	adds r0, r3, r5
	bl DestroySprite
	movs r0, #0x3c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	bl DestroySprite
	adds r0, r4, #0
	bl DestroyAnimSprite
_0815BF7C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815BF84: .4byte 0x020205AC
_0815BF88: .4byte 0x08007141
	thumb_func_end sub_0815BF30

	thumb_func_start sub_0815BF8C
sub_0815BF8C: @ 0x0815BF8C
	push {lr}
	adds r3, r0, #0
	movs r0, #0x3e
	adds r0, r0, r3
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0815BFD8
	ldrh r2, [r3, #0x32]
	ldrh r1, [r3, #0x34]
	adds r2, r2, r1
	lsls r1, r2, #0x10
	asrs r1, r1, #0x18
	ldrh r0, [r3, #0x26]
	subs r0, r0, r1
	strh r0, [r3, #0x26]
	movs r0, #0xff
	ands r2, r0
	strh r2, [r3, #0x34]
	ldrh r0, [r3, #0x30]
	subs r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0815BFD8
	mov r1, ip
	ldrb r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldr r0, _0815BFDC
	str r0, [r3, #0x1c]
_0815BFD8:
	pop {r0}
	bx r0
	.align 2, 0
_0815BFDC: .4byte 0x08007141
	thumb_func_end sub_0815BF8C

	thumb_func_start sub_0815BFE0
sub_0815BFE0: @ 0x0815BFE0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _0815C008
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #8
	ldrsh r0, [r0, r2]
	adds r4, r1, #0
	cmp r0, #5
	bls _0815BFFE
	b _0815C2D2
_0815BFFE:
	lsls r0, r0, #2
	ldr r1, _0815C00C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815C008: .4byte 0x03005B60
_0815C00C: .4byte 0x0815C010
_0815C010: @ jump table
	.4byte _0815C028 @ case 0
	.4byte _0815C160 @ case 1
	.4byte _0815C1E8 @ case 2
	.4byte _0815C21E @ case 3
	.4byte _0815C24C @ case 4
	.4byte _0815C286 @ case 5
_0815C028:
	ldr r1, _0815C084
	movs r0, #0x50
	bl SetGpuReg
	ldr r1, _0815C088
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetAnimBgAttribute
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815C060
	movs r0, #1
	movs r1, #3
	movs r2, #1
	bl SetAnimBgAttribute
_0815C060:
	mov r0, sp
	bl sub_080A63F8
	ldr r1, _0815C08C
	mov r0, sp
	movs r2, #0
	bl sub_080A6628
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815C098
	ldr r1, _0815C090
	ldr r3, _0815C094
	adds r0, r3, #0
	b _0815C106
	.align 2, 0
_0815C084: .4byte 0x00003F42
_0815C088: .4byte 0x00000D03
_0815C08C: .4byte 0x08C2A790
_0815C090: .4byte 0x02022ACC
_0815C094: .4byte 0x0000FFC8
_0815C098:
	ldr r0, _0815C0DC
	ldrb r0, [r0]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815C0F0
	cmp r4, #1
	bne _0815C0BC
	ldr r1, _0815C0E0
	ldr r2, _0815C0E4
	adds r0, r2, #0
	strh r0, [r1]
_0815C0BC:
	cmp r4, #3
	bne _0815C0C8
	ldr r1, _0815C0E0
	ldr r3, _0815C0E8
	adds r0, r3, #0
	strh r0, [r1]
_0815C0C8:
	cmp r4, #0
	bne _0815C0D2
	ldr r1, _0815C0E0
	movs r0, #0xe
	strh r0, [r1]
_0815C0D2:
	cmp r4, #2
	bne _0815C108
	ldr r1, _0815C0E0
	ldr r2, _0815C0EC
	b _0815C104
	.align 2, 0
_0815C0DC: .4byte 0x020380D7
_0815C0E0: .4byte 0x02022ACC
_0815C0E4: .4byte 0x0000FF65
_0815C0E8: .4byte 0x0000FF8D
_0815C0EC: .4byte 0x0000FFEC
_0815C0F0:
	cmp r4, #1
	bne _0815C0FC
	ldr r1, _0815C144
	ldr r3, _0815C148
	adds r0, r3, #0
	strh r0, [r1]
_0815C0FC:
	cmp r4, #0
	bne _0815C108
	ldr r1, _0815C144
	ldr r2, _0815C14C
_0815C104:
	adds r0, r2, #0
_0815C106:
	strh r0, [r1]
_0815C108:
	ldr r1, _0815C150
	movs r0, #0
	strh r0, [r1]
	mov r0, sp
	ldrb r0, [r0, #9]
	ldr r1, _0815C154
	mov r2, sp
	ldrh r2, [r2, #0xa]
	bl AnimLoadCompressedBgGfx
	ldr r0, _0815C158
	mov r1, sp
	ldrb r1, [r1, #8]
	lsls r1, r1, #4
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r0, _0815C15C
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _0815C144
	ldrh r0, [r0]
	strh r0, [r1, #0x1c]
	ldr r0, _0815C150
	ldrh r0, [r0]
	strh r0, [r1, #0x1e]
	b _0815C1E0
	.align 2, 0
_0815C144: .4byte 0x02022ACC
_0815C148: .4byte 0x0000FF79
_0815C14C: .4byte 0x0000FFF6
_0815C150: .4byte 0x02022ACE
_0815C154: .4byte 0x08C2A6D8
_0815C158: .4byte 0x08C2A778
_0815C15C: .4byte 0x03005B60
_0815C160:
	ldr r1, _0815C194
	lsls r4, r6, #2
	adds r0, r4, r6
	lsls r0, r0, #3
	adds r5, r0, r1
	movs r0, #0
	strh r0, [r5, #0xe]
	ldr r0, _0815C198
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815C1A4
	ldr r2, _0815C19C
	ldr r1, _0815C1A0
	movs r3, #0xc
	ldrsh r0, [r5, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r5, [r5, #0x1c]
	adds r0, r0, r5
	b _0815C1B6
	.align 2, 0
_0815C194: .4byte 0x03005B60
_0815C198: .4byte 0x020380D7
_0815C19C: .4byte 0x02022ACC
_0815C1A0: .4byte 0x085AD2AC
_0815C1A4:
	ldr r2, _0815C1D4
	ldr r1, _0815C1D8
	movs r3, #0xc
	ldrsh r0, [r5, r3]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r5, #0x1c]
	subs r0, r0, r1
_0815C1B6:
	strh r0, [r2]
	ldr r0, _0815C1DC
	adds r1, r4, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #0xc]
	adds r0, #1
	strh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bne _0815C1E0
	strh r0, [r1, #8]
	b _0815C2D2
	.align 2, 0
_0815C1D4: .4byte 0x02022ACC
_0815C1D8: .4byte 0x085AD2AC
_0815C1DC: .4byte 0x03005B60
_0815C1E0:
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0815C2D2
_0815C1E8:
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r4, r0, r4
	ldrh r0, [r4, #0xa]
	subs r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _0815C202
	movs r0, #5
	strh r0, [r4, #0xa]
_0815C202:
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #8
	movs r0, #3
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #5
	bne _0815C2D2
	b _0815C23E
_0815C21E:
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r4, r0, r4
	ldrh r1, [r4, #0xe]
	adds r1, #1
	strh r1, [r4, #0xe]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, _0815C248
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _0815C2D2
_0815C23E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815C2D2
	.align 2, 0
_0815C248: .4byte 0x085AD2B0
_0815C24C:
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r4, r0, r4
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd
	ble _0815C266
	movs r0, #0xd
	strh r0, [r4, #0xa]
_0815C266:
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #8
	movs r0, #3
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0xd
	bne _0815C2D2
	movs r0, #1
	strh r0, [r4, #8]
	b _0815C2D2
_0815C286:
	mov r0, sp
	bl sub_080A63F8
	mov r0, sp
	ldrb r0, [r0, #9]
	bl sub_080A6530
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815C2A8
	movs r0, #1
	movs r1, #3
	movs r2, #0
	bl SetAnimBgAttribute
_0815C2A8:
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	ldr r0, _0815C2DC
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0815C2E0
	strh r1, [r0]
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	adds r0, r6, #0
	bl DestroyAnimVisualTask
_0815C2D2:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815C2DC: .4byte 0x02022ACC
_0815C2E0: .4byte 0x02022ACE
	thumb_func_end sub_0815BFE0

