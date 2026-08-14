.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0807A498
sub_0807A498: @ 0x0807A498
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	bne _0807A4B4
	movs r0, #0x17
	bl PlaySE
	movs r0, #0
	strh r0, [r4, #0x2e]
_0807A4B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807A498

	thumb_func_start sub_0807A4BC
sub_0807A4BC: @ 0x0807A4BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0807A4E6
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	bne _0807A4E6
	movs r0, #0xc2
	bl PlaySE
	strh r5, [r4, #0x2e]
_0807A4E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0807A4BC

	thumb_func_start sub_0807A4EC
sub_0807A4EC: @ 0x0807A4EC
	push {lr}
	adds r2, r0, #0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	cmp r1, #0
	bne _0807A522
	ldrh r0, [r2, #0x2e]
	adds r0, #1
	strh r0, [r2, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	bne _0807A508
	strh r1, [r2, #0x2e]
_0807A508:
	movs r1, #0x2e
	ldrsh r0, [r2, r1]
	lsls r0, r0, #1
	ldr r1, _0807A528
	adds r0, r0, r1
	ldrb r1, [r2, #5]
	lsrs r1, r1, #4
	adds r1, #0x10
	lsls r1, r1, #4
	adds r1, #4
	movs r2, #2
	bl LoadPalette
_0807A522:
	pop {r0}
	bx r0
	.align 2, 0
_0807A528: .4byte 0x0830D0E8
	thumb_func_end sub_0807A4EC

	thumb_func_start sub_0807A52C
sub_0807A52C: @ 0x0807A52C
	push {lr}
	adds r2, r0, #0
	ldrh r1, [r2, #0x2e]
	adds r1, #1
	strh r1, [r2, #0x2e]
	ldrh r0, [r2, #0x26]
	adds r0, #1
	strh r0, [r2, #0x26]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa
	bne _0807A54A
	adds r0, r2, #0
	bl DestroySprite
_0807A54A:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807A52C

	thumb_func_start sub_0807A550
sub_0807A550: @ 0x0807A550
	push {lr}
	adds r2, r0, #0
	ldrh r1, [r2, #0x2e]
	adds r1, #1
	strh r1, [r2, #0x2e]
	ldrh r0, [r2, #0x26]
	subs r0, #1
	strh r0, [r2, #0x26]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0xa
	bne _0807A56E
	adds r0, r2, #0
	bl DestroySprite
_0807A56E:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807A550

	thumb_func_start sub_0807A574
sub_0807A574: @ 0x0807A574
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bne _0807A590
	movs r0, #0xcc
	bl PlaySE
	movs r0, #0
	strh r0, [r4, #0x2e]
_0807A590:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807A574

	thumb_func_start sub_0807A598
sub_0807A598: @ 0x0807A598
	push {r4, r5, lr}
	sub sp, #0x20
	ldr r0, _0807A624
	ldr r0, [r0]
	mov ip, r0
	adds r0, #0xd4
	ldrh r1, [r0]
	lsls r1, r1, #8
	adds r0, #2
	ldrh r2, [r0]
	lsls r2, r2, #8
	adds r0, #6
	movs r4, #0
	ldrsh r3, [r0, r4]
	adds r0, #2
	movs r5, #0
	ldrsh r0, [r0, r5]
	str r0, [sp]
	mov r4, ip
	adds r4, #0xe8
	movs r5, #0
	ldrsh r0, [r4, r5]
	str r0, [sp, #4]
	movs r5, #0
	ldrsh r0, [r4, r5]
	str r0, [sp, #8]
	mov r0, ip
	adds r0, #0xec
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	bl DoBgAffineSet
	add r0, sp, #0x10
	ldrh r1, [r0]
	movs r0, #0x20
	bl SetGpuReg
	add r0, sp, #0x10
	ldrh r1, [r0, #2]
	movs r0, #0x22
	bl SetGpuReg
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	movs r0, #0x24
	bl SetGpuReg
	add r0, sp, #0x10
	ldrh r1, [r0, #6]
	movs r0, #0x26
	bl SetGpuReg
	ldr r1, [sp, #0x18]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x28
	bl SetGpuReg
	ldr r1, [sp, #0x1c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x2c
	bl SetGpuReg
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A624: .4byte 0x02031F40
	thumb_func_end sub_0807A598

	thumb_func_start sub_0807A628
sub_0807A628: @ 0x0807A628
	push {r4, lr}
	ldr r4, _0807A670
	ldr r0, [r4]
	adds r0, #0xe0
	ldrh r1, [r0]
	movs r0, #0x16
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, #0xe2
	ldrh r1, [r0]
	movs r0, #0x14
	bl SetGpuReg
	movs r0, #0
	bl GetGpuReg
	lsls r0, r0, #0x10
	movs r1, #0xe0
	lsls r1, r1, #0xb
	ands r1, r0
	cmp r1, #0
	bne _0807A674
	ldr r0, [r4]
	adds r0, #0xe4
	ldrh r1, [r0]
	movs r0, #0x1a
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, #0xe6
	ldrh r1, [r0]
	movs r0, #0x18
	bl SetGpuReg
	b _0807A678
	.align 2, 0
_0807A670: .4byte 0x02031F40
_0807A674:
	bl sub_0807A598
_0807A678:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807A628

	thumb_func_start sub_0807A680
sub_0807A680: @ 0x0807A680
	push {lr}
	bl sub_0807A628
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807A680

	thumb_func_start sub_0807A698
sub_0807A698: @ 0x0807A698
	push {r4, lr}
	ldr r3, _0807A6BC
	ldr r1, [r3]
	movs r0, #0x8a
	adds r0, r0, r1
	mov ip, r0
	movs r2, #0
	movs r0, #0
	mov r4, ip
	strh r0, [r4]
	adds r1, #0x88
	strb r2, [r1]
	ldr r0, [r3]
	adds r0, #0x89
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A6BC: .4byte 0x02031F40
	thumb_func_end sub_0807A698

	thumb_func_start sub_0807A6C0
sub_0807A6C0: @ 0x0807A6C0
	push {r4, r5, lr}
	ldr r0, _0807A6E4
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x88
	adds r3, r2, #0
	adds r3, #0x89
	ldrb r1, [r1]
	adds r5, r0, #0
	ldrb r3, [r3]
	cmp r1, r3
	bne _0807A6E8
	adds r1, r2, #0
	adds r1, #0x8a
	ldrh r0, [r1]
	adds r0, #1
	b _0807A6EE
	.align 2, 0
_0807A6E4: .4byte 0x02031F40
_0807A6E8:
	adds r1, r2, #0
	adds r1, #0x8a
	movs r0, #0
_0807A6EE:
	strh r0, [r1]
	adds r4, r5, #0
	ldr r0, [r4]
	adds r0, #0x8a
	ldrh r1, [r0]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bls _0807A720
	bl CloseLink
	ldr r0, _0807A734
	bl SetMainCallback2
	ldr r1, [r4]
	adds r3, r1, #0
	adds r3, #0x8a
	movs r2, #0
	movs r0, #0
	strh r0, [r3]
	adds r1, #0x89
	strb r2, [r1]
	ldr r0, [r4]
	adds r0, #0x88
	strb r2, [r0]
_0807A720:
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0x88
	ldrb r1, [r1]
	adds r0, #0x89
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807A734: .4byte 0x0800AA0D
	thumb_func_end sub_0807A6C0

	thumb_func_start sub_0807A738
sub_0807A738: @ 0x0807A738
	push {lr}
	ldr r0, _0807A748
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807A74C
	movs r0, #0
	b _0807A754
	.align 2, 0
_0807A748: .4byte 0x030031C4
_0807A74C:
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0807A754:
	pop {r1}
	bx r1
	thumb_func_end sub_0807A738

	thumb_func_start sub_0807A758
sub_0807A758: @ 0x0807A758
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r4, #0
	mov r8, r4
	cmp r6, #0
	bne _0807A77E
	ldr r0, _0807A7A8
	ldrb r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _0807A7AC
	adds r1, r1, r0
	mov r8, r1
	movs r4, #1
_0807A77E:
	cmp r6, #1
	bne _0807A79C
	ldr r0, _0807A7A8
	ldrb r0, [r0, #1]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x64
	muls r1, r0, r1
	ldr r0, _0807A7B0
	adds r1, r1, r0
	mov r8, r1
	movs r4, #3
_0807A79C:
	cmp r5, #0
	beq _0807A7B4
	cmp r5, #1
	beq _0807A83C
	b _0807A892
	.align 2, 0
_0807A7A8: .4byte 0x02031F38
_0807A7AC: .4byte 0x02024190
_0807A7B0: .4byte 0x020243E8
_0807A7B4:
	mov r0, r8
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	movs r1, #0
	bl GetMonData3
	adds r7, r0, #0
	cmp r6, #0
	bne _0807A7F0
	lsls r0, r5, #3
	ldr r1, _0807A7E8
	adds r0, r0, r1
	ldr r1, _0807A7EC
	ldr r1, [r1]
	ldr r1, [r1, #8]
	adds r2, r5, #0
	adds r3, r7, #0
	bl HandleLoadSpecialPokePic_2
	movs r4, #0
	b _0807A80E
	.align 2, 0
_0807A7E8: .4byte 0x082DDA1C
_0807A7EC: .4byte 0x02024178
_0807A7F0:
	lsls r0, r5, #3
	ldr r1, _0807A830
	adds r0, r0, r1
	ldr r1, _0807A834
	ldr r2, [r1]
	lsls r4, r6, #1
	adds r1, r4, #1
	lsls r1, r1, #2
	adds r2, #4
	adds r2, r2, r1
	ldr r1, [r2]
	adds r2, r5, #0
	adds r3, r7, #0
	bl HandleLoadSpecialPokePic_DontHandleDeoxys
_0807A80E:
	mov r0, r8
	bl GetMonSpritePalStruct
	bl LoadCompressedSpritePalette
	ldr r0, _0807A838
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0xf0
	adds r0, r0, r4
	strh r5, [r0]
	lsls r0, r6, #2
	adds r1, #0x68
	adds r1, r1, r0
	str r7, [r1]
	b _0807A892
	.align 2, 0
_0807A830: .4byte 0x082DDA1C
_0807A834: .4byte 0x02024178
_0807A838: .4byte 0x02031F40
_0807A83C:
	mov r0, r8
	bl GetMonSpritePalStruct
	ldrh r0, [r0, #4]
	adds r1, r4, #0
	bl SetMultiuseSpriteTemplateToPokemon
	ldr r0, _0807A89C
	movs r1, #0x78
	movs r2, #0x3c
	movs r3, #6
	bl CreateSprite
	ldr r4, _0807A8A0
	ldr r1, [r4]
	adds r1, #0x8e
	adds r1, r1, r6
	strb r0, [r1]
	ldr r3, _0807A8A4
	ldr r0, [r4]
	adds r0, #0x8e
	adds r0, r0, r6
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x8e
	adds r0, r0, r6
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, #0x1c
	adds r0, r0, r3
	ldr r1, _0807A8A8
	str r1, [r0]
_0807A892:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807A89C: .4byte 0x02024640
_0807A8A0: .4byte 0x02031F40
_0807A8A4: .4byte 0x020205AC
_0807A8A8: .4byte 0x08007141
	thumb_func_end sub_0807A758

	thumb_func_start sub_0807A8AC
sub_0807A8AC: @ 0x0807A8AC
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, _0807A8CC
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0xc
	bls _0807A8C2
	b _0807AB72
_0807A8C2:
	lsls r0, r0, #2
	ldr r1, _0807A8D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807A8CC: .4byte 0x03002360
_0807A8D0: .4byte 0x0807A8D4
_0807A8D4: @ jump table
	.4byte _0807A908 @ case 0
	.4byte _0807A9B4 @ case 1
	.4byte _0807A9F8 @ case 2
	.4byte _0807AA18 @ case 3
	.4byte _0807AA62 @ case 4
	.4byte _0807AA90 @ case 5
	.4byte _0807AAB4 @ case 6
	.4byte _0807AACC @ case 7
	.4byte _0807AAD6 @ case 8
	.4byte _0807AAF0 @ case 9
	.4byte _0807AB0C @ case 10
	.4byte _0807AB30 @ case 11
	.4byte _0807AB4C @ case 12
_0807A908:
	ldr r0, _0807A99C
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807A91C
	ldr r1, _0807A9A0
	ldr r2, _0807A9A4
	adds r0, r2, #0
	strh r0, [r1]
	bl CloseLink
_0807A91C:
	ldr r4, _0807A9A8
	movs r5, #0x80
	lsls r5, r5, #1
	adds r0, r5, #0
	bl AllocZeroed
	str r0, [r4]
	bl AllocateMonSpritesGfx
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, _0807A9AC
	bl SetVBlankCallback
	bl sub_0807ABCC
	bl sub_0807A698
	ldr r1, _0807A9B0
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x8c
	strh r2, [r0]
	adds r0, #8
	strh r2, [r0]
	adds r1, #0xee
	movs r0, #1
	strb r0, [r1]
	ldr r3, [r4]
	adds r0, r3, #0
	adds r0, #0xd4
	movs r1, #0x40
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r1, r3, #0
	adds r1, #0xdc
	movs r0, #0x78
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x50
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xe8
	strh r5, [r0]
	adds r0, #4
	strh r2, [r0]
	b _0807AB72
	.align 2, 0
_0807A99C: .4byte 0x030031C4
_0807A9A0: .4byte 0x0202267E
_0807A9A4: .4byte 0x00001144
_0807A9A8: .4byte 0x02031F40
_0807A9AC: .4byte 0x0807A681
_0807A9B0: .4byte 0x03002360
_0807A9B4:
	ldr r0, _0807A9E0
	ldrb r5, [r0]
	cmp r5, #0
	bne _0807A9EC
	ldr r4, _0807A9E4
	ldr r0, [r4]
	adds r0, #0xfa
	movs r1, #1
	strb r1, [r0]
	bl OpenLink
	ldr r1, _0807A9E8
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	str r5, [r0, #0x64]
	b _0807AB72
	.align 2, 0
_0807A9E0: .4byte 0x030031C4
_0807A9E4: .4byte 0x02031F40
_0807A9E8: .4byte 0x03002360
_0807A9EC:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	b _0807AB72
_0807A9F8:
	ldr r0, _0807AA14
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x3c
	bhi _0807AA08
	b _0807AB72
_0807AA08:
	movs r0, #0
	str r0, [r1, #0x64]
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	b _0807AB40
	.align 2, 0
_0807AA14: .4byte 0x02031F40
_0807AA18:
	bl IsLinkMaster
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807AA24
	b _0807AB38
_0807AA24:
	bl GetLinkPlayerCount_2
	adds r4, r0, #0
	bl GetSavedPlayerCount
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	blo _0807AA5C
	ldr r0, _0807AA54
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x1e
	bhi _0807AA46
	b _0807AB72
_0807AA46:
	bl CheckShouldAdvanceLinkState
	ldr r1, _0807AA58
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	b _0807AB40
	.align 2, 0
_0807AA54: .4byte 0x02031F40
_0807AA58: .4byte 0x03002360
_0807AA5C:
	bl sub_0807A6C0
	b _0807AB72
_0807AA62:
	bl sub_0807A6C0
	ldr r0, _0807AA88
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807AA70
	b _0807AB72
_0807AA70:
	bl IsLinkPlayerDataExchangeComplete
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0807AA7E
	b _0807AB72
_0807AA7E:
	ldr r1, _0807AA8C
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	b _0807AB40
	.align 2, 0
_0807AA88: .4byte 0x030031C4
_0807AA8C: .4byte 0x03002360
_0807AA90:
	ldr r2, _0807AAB0
	ldr r0, [r2]
	adds r0, #0x72
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x73
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0x93
	strb r1, [r0]
	movs r0, #0
	bl sub_0807A758
	b _0807AB38
	.align 2, 0
_0807AAB0: .4byte 0x02031F40
_0807AAB4:
	movs r0, #0
	movs r1, #1
	bl sub_0807A758
	ldr r1, _0807AAC8
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	b _0807AB40
	.align 2, 0
_0807AAC8: .4byte 0x03002360
_0807AACC:
	movs r0, #1
	movs r1, #0
	bl sub_0807A758
	b _0807AB38
_0807AAD6:
	movs r0, #1
	movs r1, #1
	bl sub_0807A758
	bl sub_0807ABB0
	ldr r1, _0807AAEC
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	b _0807AB40
	.align 2, 0
_0807AAEC: .4byte 0x03002360
_0807AAF0:
	bl sub_0807B4CC
	ldr r0, _0807AB04
	bl LoadSpriteSheet
	ldr r0, _0807AB08
	bl LoadSpritePalette
	b _0807AB38
	.align 2, 0
_0807AB04: .4byte 0x0830CF5C
_0807AB08: .4byte 0x0830CF64
_0807AB0C:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	movs r0, #0
	bl ShowBg
	ldr r1, _0807AB2C
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	b _0807AB40
	.align 2, 0
_0807AB2C: .4byte 0x03002360
_0807AB30:
	bl sub_0807AB9C
	bl SetTradeSceneStrings
_0807AB38:
	ldr r1, _0807AB48
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r1, r0
_0807AB40:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0807AB72
	.align 2, 0
_0807AB48: .4byte 0x03002360
_0807AB4C:
	ldr r0, _0807AB90
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807AB72
	ldr r0, _0807AB94
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807AB6C
	bl LoadWirelessStatusIndicatorSpriteGfx
	movs r0, #0
	movs r1, #0
	bl CreateWirelessStatusIndicatorSprite
_0807AB6C:
	ldr r0, _0807AB98
	bl SetMainCallback2
_0807AB72:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807AB90: .4byte 0x02037C74
_0807AB94: .4byte 0x0300319C
_0807AB98: .4byte 0x0807E465
	thumb_func_end sub_0807A8AC

	thumb_func_start sub_0807AB9C
sub_0807AB9C: @ 0x0807AB9C
	push {lr}
	movs r0, #5
	bl sub_0807B064
	movs r0, #0
	bl sub_0807B064
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807AB9C

	thumb_func_start sub_0807ABB0
sub_0807ABB0: @ 0x0807ABB0
	push {lr}
	movs r0, #0
	movs r1, #0xff
	bl FillWindowPixelBuffer
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_0807ABB0

	thumb_func_start sub_0807ABCC
sub_0807ABCC: @ 0x0807ABCC
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, _0807ACB4
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
	movs r5, #0x80
	lsls r5, r5, #4
	adds r0, r5, #0
	bl Alloc
	adds r1, r0, #0
	movs r0, #0
	bl SetBgTilemapBuffer
	adds r0, r5, #0
	bl Alloc
	adds r1, r0, #0
	movs r0, #1
	bl SetBgTilemapBuffer
	adds r0, r5, #0
	bl Alloc
	adds r1, r0, #0
	movs r0, #3
	bl SetBgTilemapBuffer
	bl DeactivateAllTextPrinters
	movs r0, #0x8c
	lsls r0, r0, #0x14
	mov sl, r0
	movs r0, #0
	mov sb, r0
	str r0, [sp]
	mov r1, sl
	movs r2, #0
	movs r3, #0
	bl DecompressAndLoadBgGfxUsingHeap
	ldr r0, _0807ACB8
	mov r8, r0
	ldr r4, _0807ACBC
	adds r1, r4, #0
	bl LZDecompressVram
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	ldr r6, _0807ACC0
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r0, _0807ACC4
	bl InitWindows
	mov r0, sb
	str r0, [sp]
	movs r0, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0
	bl DecompressAndLoadBgGfxUsingHeap
	mov r0, r8
	adds r1, r4, #0
	bl LZDecompressVram
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x20
	bl LoadCompressedPalette
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807ACB4: .4byte 0x0830D294
_0807ACB8: .4byte 0x08C00530
_0807ACBC: .4byte 0x0201C000
_0807ACC0: .4byte 0x08C004EC
_0807ACC4: .4byte 0x0830D27C
	thumb_func_end sub_0807ABCC

	thumb_func_start sub_0807ACC8
sub_0807ACC8: @ 0x0807ACC8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r0, _0807ACE8
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	bls _0807ACDC
	b _0807AE7A
_0807ACDC:
	lsls r0, r0, #2
	ldr r1, _0807ACEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807ACE8: .4byte 0x03002360
_0807ACEC: .4byte 0x0807ACF0
_0807ACF0: @ jump table
	.4byte _0807AD24 @ case 0
	.4byte _0807AE7A @ case 1
	.4byte _0807AE7A @ case 2
	.4byte _0807AE7A @ case 3
	.4byte _0807AE7A @ case 4
	.4byte _0807ADE8 @ case 5
	.4byte _0807ADF2 @ case 6
	.4byte _0807ADFC @ case 7
	.4byte _0807AE0C @ case 8
	.4byte _0807AE2C @ case 9
	.4byte _0807AE48 @ case 10
	.4byte _0807AE50 @ case 11
	.4byte _0807AE74 @ case 12
_0807AD24:
	ldr r1, _0807ADC8
	ldr r0, _0807ADCC
	ldrh r0, [r0]
	movs r5, #0
	strb r0, [r1]
	movs r0, #6
	strb r0, [r1, #1]
	ldr r4, _0807ADD0
	ldr r0, _0807ADD4
	ldr r1, [r0]
	adds r0, r4, #0
	bl StringCopy
	ldr r0, _0807ADD8
	movs r1, #7
	mov r2, sp
	bl GetMonData3
	adds r4, #0x1c
	adds r0, r4, #0
	mov r1, sp
	bl StringCopy
	ldr r4, _0807ADDC
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r6, #0
	bl AllocZeroed
	str r0, [r4]
	bl AllocateMonSpritesGfx
	bl ResetTasks
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	ldr r0, _0807ADE0
	bl SetVBlankCallback
	bl sub_0807ABCC
	ldr r0, [r4]
	adds r0, #0xee
	strb r5, [r0]
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x8c
	strh r5, [r0]
	adds r0, #8
	strh r5, [r0]
	adds r0, #0x40
	movs r1, #0x40
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r1, r2, #0
	adds r1, #0xdc
	movs r0, #0x78
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x50
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xe8
	strh r6, [r0]
	adds r0, #4
	strh r5, [r0]
	str r5, [r2, #0x64]
	ldr r0, _0807ADE4
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	b _0807AE7A
	.align 2, 0
_0807ADC8: .4byte 0x02031F38
_0807ADCC: .4byte 0x02037282
_0807ADD0: .4byte 0x020226A8
_0807ADD4: .4byte 0x03005AF0
_0807ADD8: .4byte 0x020243E8
_0807ADDC: .4byte 0x02031F40
_0807ADE0: .4byte 0x0807A681
_0807ADE4: .4byte 0x03002360
_0807ADE8:
	movs r0, #0
	movs r1, #0
	bl sub_0807A758
	b _0807AE60
_0807ADF2:
	movs r0, #0
	movs r1, #1
	bl sub_0807A758
	b _0807AE60
_0807ADFC:
	movs r0, #1
	movs r1, #0
	bl sub_0807A758
	movs r0, #0
	bl ShowBg
	b _0807AE60
_0807AE0C:
	movs r0, #1
	movs r1, #1
	bl sub_0807A758
	movs r0, #0
	movs r1, #0xff
	bl FillWindowPixelBuffer
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	b _0807AE60
_0807AE2C:
	bl sub_0807B4CC
	ldr r0, _0807AE40
	bl LoadSpriteSheet
	ldr r0, _0807AE44
	bl LoadSpritePalette
	b _0807AE60
	.align 2, 0
_0807AE40: .4byte 0x0830CF5C
_0807AE44: .4byte 0x0830CF64
_0807AE48:
	movs r0, #0
	bl ShowBg
	b _0807AE60
_0807AE50:
	movs r0, #5
	bl sub_0807B064
	movs r0, #0
	bl sub_0807B064
	bl SetTradeSceneStrings
_0807AE60:
	ldr r1, _0807AE70
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0807AE7A
	.align 2, 0
_0807AE70: .4byte 0x03002360
_0807AE74:
	ldr r0, _0807AE98
	bl SetMainCallback2
_0807AE7A:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807AE98: .4byte 0x0807B045
	thumb_func_end sub_0807ACC8

	thumb_func_start sub_0807AE9C
sub_0807AE9C: @ 0x0807AE9C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x64
	muls r1, r0, r1
	ldr r0, _0807AEF8
	adds r5, r1, r0
	adds r0, r5, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	bne _0807AEF0
	adds r0, r5, #0
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl GetMonData3
	adds r5, r0, #0
	adds r0, r4, #0
	bl HoennToNationalOrder
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #2
	bl GetSetPokedexFlag
	adds r0, r4, #0
	movs r1, #3
	adds r2, r5, #0
	bl HandleSetPokedexFlag
_0807AEF0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807AEF8: .4byte 0x02024190
	thumb_func_end sub_0807AE9C

	thumb_func_start sub_0807AEFC
sub_0807AEFC: @ 0x0807AEFC
	push {lr}
	bl GetMultiplayerId
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807AEFC

	thumb_func_start sub_0807AF08
sub_0807AF08: @ 0x0807AF08
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r5, #0x64
	mov r1, sb
	muls r1, r5, r1
	ldr r0, _0807AFD4
	adds r7, r1, r0
	adds r0, r7, #0
	movs r1, #0x40
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r1, r4, #0
	muls r1, r5, r1
	ldr r0, _0807AFD8
	adds r5, r1, r0
	adds r0, r5, #0
	movs r1, #0x40
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r6, #0xff
	beq _0807AF62
	ldr r0, _0807AFDC
	lsls r1, r6, #3
	adds r1, r1, r6
	lsls r1, r1, #2
	ldr r2, _0807AFE0
	adds r1, r1, r2
	ldr r0, [r0]
	adds r0, r0, r1
	bl ClearMail
_0807AF62:
	ldr r4, _0807AFE4
	ldr r0, [r4]
	adds r1, r7, #0
	movs r2, #0x64
	bl memcpy
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0x64
	bl memcpy
	ldr r1, [r4]
	adds r0, r5, #0
	movs r2, #0x64
	bl memcpy
	movs r1, #0x46
	mov r0, sp
	strb r1, [r0]
	adds r0, r7, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	bne _0807AF9E
	adds r0, r7, #0
	movs r1, #0x20
	mov r2, sp
	bl SetMonData
_0807AF9E:
	mov r0, r8
	cmp r0, #0xff
	beq _0807AFB4
	lsls r1, r0, #3
	add r1, r8
	lsls r1, r1, #2
	ldr r0, _0807AFE8
	adds r1, r1, r0
	adds r0, r7, #0
	bl GiveMailToMon
_0807AFB4:
	mov r0, sb
	bl sub_0807AE9C
	ldr r0, _0807AFEC
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807AFC6
	bl sub_0807AEFC
_0807AFC6:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807AFD4: .4byte 0x02024190
_0807AFD8: .4byte 0x020243E8
_0807AFDC: .4byte 0x03005AEC
_0807AFE0: .4byte 0x00002BE0
_0807AFE4: .4byte 0x02031F40
_0807AFE8: .4byte 0x02031E60
_0807AFEC: .4byte 0x030031C4
	thumb_func_end sub_0807AF08

	thumb_func_start sub_0807AFF0
sub_0807AFF0: @ 0x0807AFF0
	push {r4, lr}
	ldr r4, _0807B004
	ldr r0, [r4]
	adds r0, #0x93
	ldrb r0, [r0]
	cmp r0, #1
	beq _0807B008
	cmp r0, #2
	beq _0807B02E
	b _0807B038
	.align 2, 0
_0807B004: .4byte 0x02031F40
_0807B008:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807B02E
	bl bitmask_all_link_players_but_self
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r4]
	adds r1, #0x74
	movs r2, #0x14
	bl SendBlock
	ldr r1, [r4]
	adds r1, #0x93
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0807B02E:
	ldr r0, _0807B040
	ldr r0, [r0]
	adds r0, #0x93
	movs r1, #0
	strb r1, [r0]
_0807B038:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B040: .4byte 0x02031F40
	thumb_func_end sub_0807AFF0

	thumb_func_start sub_0807B044
sub_0807B044: @ 0x0807B044
	push {lr}
	bl sub_0807B600
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807B044

	thumb_func_start sub_0807B064
sub_0807B064: @ 0x0807B064
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0807B070
	b _0807B4A0
_0807B070:
	lsls r0, r0, #2
	ldr r1, _0807B07C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807B07C: .4byte 0x0807B080
_0807B080: @ jump table
	.4byte _0807B0A0 @ case 0
	.4byte _0807B114 @ case 1
	.4byte _0807B1BC @ case 2
	.4byte _0807B230 @ case 3
	.4byte _0807B278 @ case 4
	.4byte _0807B344 @ case 5
	.4byte _0807B35C @ case 6
	.4byte _0807B434 @ case 7
_0807B0A0:
	ldr r0, _0807B0F8
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0xe4
	movs r0, #0
	strh r0, [r2]
	adds r1, #0xe6
	movs r0, #0xb4
	strh r0, [r1]
	movs r1, #0xaa
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r1, _0807B0FC
	movs r0, #0xc
	bl SetGpuReg
	ldr r0, _0807B100
	movs r1, #0x10
	movs r2, #0x60
	bl LoadPalette
	ldr r3, _0807B104
	ldr r4, _0807B108
	movs r5, #0xa1
	lsls r5, r5, #5
	ldr r1, _0807B10C
	ldr r6, _0807B110
	movs r2, #0x80
	lsls r2, r2, #5
	movs r7, #0x80
	lsls r7, r7, #0x18
_0807B0E2:
	str r3, [r1]
	str r4, [r1, #4]
	str r6, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, r3, r2
	adds r4, r4, r2
	subs r5, r5, r2
	cmp r5, r2
	bhi _0807B0E2
	b _0807B484
	.align 2, 0
_0807B0F8: .4byte 0x02031F40
_0807B0FC: .4byte 0x00005206
_0807B100: .4byte 0x08305D24
_0807B104: .4byte 0x08305D84
_0807B108: .4byte 0x06004000
_0807B10C: .4byte 0x040000D4
_0807B110: .4byte 0x80000800
_0807B114:
	ldr r4, _0807B14C
	ldr r2, [r4]
	adds r1, r2, #0
	adds r1, #0xe2
	movs r0, #0
	strh r0, [r1]
	adds r2, #0xe0
	movs r1, #0xae
	lsls r1, r1, #1
	strh r1, [r2]
	movs r0, #0x16
	bl SetGpuReg
	ldr r1, _0807B150
	movs r0, #0xa
	bl SetGpuReg
	ldr r1, _0807B154
	movs r0, #0xc
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807B15C
	ldr r1, _0807B158
	b _0807B15E
	.align 2, 0
_0807B14C: .4byte 0x02031F40
_0807B150: .4byte 0x00008502
_0807B154: .4byte 0x00009206
_0807B158: .4byte 0x0830ABE4
_0807B15C:
	ldr r1, _0807B1A8
_0807B15E:
	ldr r2, _0807B1AC
	ldr r0, _0807B1B0
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _0807B1B4
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	ldr r3, _0807B1B8
	movs r4, #0xc0
	lsls r4, r4, #0x13
	movs r5, #0xa1
	lsls r5, r5, #5
	ldr r1, _0807B1B0
	ldr r6, _0807B1B4
	movs r2, #0x80
	lsls r2, r2, #5
	movs r7, #0x80
	lsls r7, r7, #0x18
_0807B182:
	str r3, [r1]
	str r4, [r1, #4]
	str r6, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, r3, r2
	adds r4, r4, r2
	subs r5, r5, r2
	cmp r5, r2
	bhi _0807B182
	str r3, [r1]
	str r4, [r1, #4]
	lsrs r0, r5, #1
	orrs r0, r7
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r1, #0x92
	lsls r1, r1, #5
	b _0807B258
	.align 2, 0
_0807B1A8: .4byte 0x08309BE4
_0807B1AC: .4byte 0x06002800
_0807B1B0: .4byte 0x040000D4
_0807B1B4: .4byte 0x80000800
_0807B1B8: .4byte 0x08305D84
_0807B1BC:
	ldr r0, _0807B1E8
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0xe0
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #0x18
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807B1F8
	ldr r1, _0807B1EC
	movs r0, #0
	bl SetGpuReg
	ldr r0, _0807B1F0
	ldr r1, _0807B1F4
	bl LZ77UnCompVram
	movs r0, #8
	b _0807B212
	.align 2, 0
_0807B1E8: .4byte 0x02031F40
_0807B1EC: .4byte 0x00001241
_0807B1F0: .4byte 0x0830BBE4
_0807B1F4: .4byte 0x06002800
_0807B1F8:
	ldr r1, _0807B21C
	movs r0, #0
	bl SetGpuReg
	ldr r1, _0807B220
	ldr r2, _0807B224
	ldr r0, _0807B228
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _0807B22C
	str r1, [r0, #8]
	ldr r0, [r0, #8]
	movs r0, #1
_0807B212:
	movs r1, #0x10
	movs r2, #0
	bl BlendPalettes
	b _0807B4A0
	.align 2, 0
_0807B21C: .4byte 0x00001241
_0807B220: .4byte 0x08302D64
_0807B224: .4byte 0x06002800
_0807B228: .4byte 0x040000D4
_0807B22C: .4byte 0x80000400
_0807B230:
	ldr r0, _0807B260
	movs r1, #0x30
	movs r2, #0x20
	bl LoadPalette
	ldr r0, _0807B264
	ldr r1, _0807B268
	bl LZ77UnCompVram
	ldr r0, _0807B26C
	ldr r1, _0807B270
	bl LZ77UnCompVram
	ldr r0, _0807B274
	ldr r0, [r0]
	adds r0, #0xe4
	movs r1, #0x50
	strh r1, [r0]
	movs r1, #0xb2
	lsls r1, r1, #5
_0807B258:
	movs r0, #0
	bl SetGpuReg
	b _0807B4A0
	.align 2, 0
_0807B260: .4byte 0x0830C0E4
_0807B264: .4byte 0x0830C104
_0807B268: .4byte 0x06004000
_0807B26C: .4byte 0x0830C794
_0807B270: .4byte 0x06009000
_0807B274: .4byte 0x02031F40
_0807B278:
	ldr r1, _0807B2FC
	movs r0, #0
	bl SetGpuReg
	ldr r1, _0807B300
	movs r0, #0xc
	bl SetGpuReg
	ldr r0, _0807B304
	ldr r3, [r0]
	adds r1, r3, #0
	adds r1, #0xd4
	movs r2, #0
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x5c
	strh r0, [r1]
	adds r1, #0x12
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xec
	strh r2, [r0]
	ldr r3, _0807B308
	ldr r4, _0807B30C
	movs r5, #0xa1
	lsls r5, r5, #6
	ldr r1, _0807B310
	ldr r6, _0807B314
	movs r2, #0x80
	lsls r2, r2, #5
	movs r7, #0x80
	lsls r7, r7, #0x18
_0807B2C4:
	str r3, [r1]
	str r4, [r1, #4]
	str r6, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, r3, r2
	adds r4, r4, r2
	subs r5, r5, r2
	cmp r5, r2
	bhi _0807B2C4
	str r3, [r1]
	str r4, [r1, #4]
	lsrs r0, r5, #1
	orrs r0, r7
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0807B304
	ldr r0, [r0]
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807B324
	ldr r1, _0807B318
	ldr r2, _0807B31C
	ldr r0, _0807B310
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _0807B320
	b _0807B49C
	.align 2, 0
_0807B2FC: .4byte 0x00001441
_0807B300: .4byte 0x00001287
_0807B304: .4byte 0x02031F40
_0807B308: .4byte 0x083071A4
_0807B30C: .4byte 0x06004000
_0807B310: .4byte 0x040000D4
_0807B314: .4byte 0x80000800
_0807B318: .4byte 0x083099E4
_0807B31C: .4byte 0x06009000
_0807B320: .4byte 0x80000080
_0807B324:
	ldr r1, _0807B334
	ldr r2, _0807B338
	ldr r0, _0807B33C
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _0807B340
	b _0807B49C
	.align 2, 0
_0807B334: .4byte 0x08309AE4
_0807B338: .4byte 0x06009000
_0807B33C: .4byte 0x040000D4
_0807B340: .4byte 0x80000080
_0807B344:
	ldr r0, _0807B358
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	movs r2, #0
	strh r2, [r1]
	adds r0, #0xe2
	strh r2, [r0]
	b _0807B4A0
	.align 2, 0
_0807B358: .4byte 0x02031F40
_0807B35C:
	ldr r1, _0807B3EC
	movs r0, #0
	bl SetGpuReg
	ldr r1, _0807B3F0
	movs r0, #0xc
	bl SetGpuReg
	ldr r0, _0807B3F4
	ldr r3, [r0]
	adds r1, r3, #0
	adds r1, #0xd4
	movs r2, #0
	movs r0, #0x40
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x5c
	strh r0, [r1]
	adds r1, #0x12
	adds r0, #0xa4
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x80
	strh r0, [r1]
	subs r1, #0xe
	movs r0, #0x78
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x50
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xec
	strh r2, [r0]
	ldr r3, _0807B3F8
	ldr r4, _0807B3FC
	movs r5, #0xa1
	lsls r5, r5, #6
	ldr r1, _0807B400
	ldr r6, _0807B404
	movs r2, #0x80
	lsls r2, r2, #5
	movs r7, #0x80
	lsls r7, r7, #0x18
_0807B3B2:
	str r3, [r1]
	str r4, [r1, #4]
	str r6, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, r3, r2
	adds r4, r4, r2
	subs r5, r5, r2
	cmp r5, r2
	bhi _0807B3B2
	str r3, [r1]
	str r4, [r1, #4]
	lsrs r0, r5, #1
	orrs r0, r7
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _0807B3F4
	ldr r0, [r0]
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807B414
	ldr r1, _0807B408
	ldr r2, _0807B40C
	ldr r0, _0807B400
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _0807B410
	b _0807B49C
	.align 2, 0
_0807B3EC: .4byte 0x00001441
_0807B3F0: .4byte 0x00001287
_0807B3F4: .4byte 0x02031F40
_0807B3F8: .4byte 0x083071A4
_0807B3FC: .4byte 0x06004000
_0807B400: .4byte 0x040000D4
_0807B404: .4byte 0x80000800
_0807B408: .4byte 0x083099E4
_0807B40C: .4byte 0x06009000
_0807B410: .4byte 0x80000080
_0807B414:
	ldr r1, _0807B424
	ldr r2, _0807B428
	ldr r0, _0807B42C
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _0807B430
	b _0807B49C
	.align 2, 0
_0807B424: .4byte 0x08309AE4
_0807B428: .4byte 0x06009000
_0807B42C: .4byte 0x040000D4
_0807B430: .4byte 0x80000080
_0807B434:
	ldr r0, _0807B4A8
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe4
	movs r2, #0
	strh r2, [r1]
	adds r0, #0xe6
	strh r2, [r0]
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	ldr r1, _0807B4AC
	movs r0, #0xc
	bl SetGpuReg
	ldr r0, _0807B4B0
	movs r1, #0x10
	movs r2, #0x60
	bl LoadPalette
	ldr r3, _0807B4B4
	ldr r4, _0807B4B8
	movs r5, #0xa1
	lsls r5, r5, #5
	ldr r1, _0807B4BC
	ldr r6, _0807B4C0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r7, #0x80
	lsls r7, r7, #0x18
_0807B472:
	str r3, [r1]
	str r4, [r1, #4]
	str r6, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, r3, r2
	adds r4, r4, r2
	subs r5, r5, r2
	cmp r5, r2
	bhi _0807B472
_0807B484:
	str r3, [r1]
	str r4, [r1, #4]
	lsrs r0, r5, #1
	orrs r0, r7
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _0807B4C4
	ldr r2, _0807B4C8
	ldr r0, _0807B4BC
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _0807B4C0
_0807B49C:
	str r1, [r0, #8]
	ldr r0, [r0, #8]
_0807B4A0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807B4A8: .4byte 0x02031F40
_0807B4AC: .4byte 0x00005206
_0807B4B0: .4byte 0x08305D24
_0807B4B4: .4byte 0x08305D84
_0807B4B8: .4byte 0x06004000
_0807B4BC: .4byte 0x040000D4
_0807B4C0: .4byte 0x80000800
_0807B4C4: .4byte 0x08304D04
_0807B4C8: .4byte 0x06009000
	thumb_func_end sub_0807B064

	thumb_func_start sub_0807B4CC
sub_0807B4CC: @ 0x0807B4CC
	push {lr}
	ldr r0, _0807B4F8
	bl LoadSpriteSheet
	ldr r0, _0807B4FC
	bl LoadSpriteSheet
	ldr r0, _0807B500
	bl LoadSpriteSheet
	ldr r0, _0807B504
	bl LoadSpriteSheet
	ldr r0, _0807B508
	bl LoadSpritePalette
	ldr r0, _0807B50C
	bl LoadSpritePalette
	pop {r0}
	bx r0
	.align 2, 0
_0807B4F8: .4byte 0x0830CFB4
_0807B4FC: .4byte 0x0830D004
_0807B500: .4byte 0x0830D038
_0807B504: .4byte 0x0830D0B0
_0807B508: .4byte 0x0830CFBC
_0807B50C: .4byte 0x0830CFC4
	thumb_func_end sub_0807B4CC

	thumb_func_start SetTradeSceneStrings
SetTradeSceneStrings: @ 0x0807B510
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r0, _0807B580
	ldr r0, [r0]
	adds r0, #0xee
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807B5A0
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	ldr r3, _0807B584
	movs r2, #0x80
	lsls r2, r2, #0x11
	eors r2, r0
	lsrs r2, r2, #0x18
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	ldr r0, _0807B588
	adds r1, r1, r0
	adds r0, r3, #0
	bl StringCopy
	ldr r5, _0807B58C
	ldrb r0, [r5, #1]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0x64
	muls r0, r4, r0
	ldr r1, _0807B590
	adds r0, r0, r1
	movs r1, #2
	mov r2, sp
	bl GetMonData3
	ldr r0, _0807B594
	mov r1, sp
	bl StringCopy10
	ldrb r0, [r5]
	muls r0, r4, r0
	ldr r1, _0807B598
	adds r0, r0, r1
	movs r1, #2
	mov r2, sp
	bl GetMonData3
	ldr r0, _0807B59C
	mov r1, sp
	bl StringCopy10
	b _0807B5DC
	.align 2, 0
_0807B580: .4byte 0x02031F40
_0807B584: .4byte 0x02021C40
_0807B588: .4byte 0x020226A8
_0807B58C: .4byte 0x02031F38
_0807B590: .4byte 0x020243E8
_0807B594: .4byte 0x02021C68
_0807B598: .4byte 0x02024190
_0807B59C: .4byte 0x02021C54
_0807B5A0:
	ldr r0, _0807B5E4
	ldrh r0, [r0]
	lsls r4, r0, #4
	subs r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _0807B5E8
	adds r4, r4, r0
	ldr r0, _0807B5EC
	adds r1, r4, #0
	adds r1, #0x2b
	bl StringCopy
	ldr r0, _0807B5F0
	adds r1, r4, #0
	bl StringCopy10
	ldr r0, _0807B5F4
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _0807B5F8
	adds r0, r0, r1
	movs r1, #2
	mov r2, sp
	bl GetMonData3
	ldr r0, _0807B5FC
	mov r1, sp
	bl StringCopy10
_0807B5DC:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807B5E4: .4byte 0x02037280
_0807B5E8: .4byte 0x0830D114
_0807B5EC: .4byte 0x02021C40
_0807B5F0: .4byte 0x02021C68
_0807B5F4: .4byte 0x02037282
_0807B5F8: .4byte 0x02024190
_0807B5FC: .4byte 0x02021C54
	thumb_func_end SetTradeSceneStrings

	thumb_func_start sub_0807B600
sub_0807B600: @ 0x0807B600
	push {lr}
	ldr r0, _0807B614
	ldr r0, [r0]
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807B618
	bl sub_0807CA00
	b _0807B61C
	.align 2, 0
_0807B614: .4byte 0x02031F40
_0807B618:
	bl sub_0807B624
_0807B61C:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	thumb_func_end sub_0807B600

	thumb_func_start sub_0807B624
sub_0807B624: @ 0x0807B624
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	ldr r0, _0807B648
	ldr r1, [r0]
	adds r1, #0x94
	ldrh r5, [r1]
	ldr r1, _0807B64C
	adds r7, r0, #0
	cmp r5, r1
	bls _0807B63C
	bl _0807C9EC
_0807B63C:
	lsls r0, r5, #2
	ldr r1, _0807B650
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807B648: .4byte 0x02031F40
_0807B64C: .4byte 0x0000010B
_0807B650: .4byte 0x0807B654
_0807B654: @ jump table
	.4byte _0807BA84 @ case 0
	.4byte _0807BAFC @ case 1
	.4byte _0807C9EC @ case 2
	.4byte _0807C9EC @ case 3
	.4byte _0807C9EC @ case 4
	.4byte _0807C9EC @ case 5
	.4byte _0807C9EC @ case 6
	.4byte _0807C9EC @ case 7
	.4byte _0807C9EC @ case 8
	.4byte _0807C9EC @ case 9
	.4byte _0807BB58 @ case 10
	.4byte _0807BBA0 @ case 11
	.4byte _0807BC14 @ case 12
	.4byte _0807C9EC @ case 13
	.4byte _0807BC80 @ case 14
	.4byte _0807C9EC @ case 15
	.4byte _0807C9EC @ case 16
	.4byte _0807C9EC @ case 17
	.4byte _0807C9EC @ case 18
	.4byte _0807C9EC @ case 19
	.4byte _0807BCA4 @ case 20
	.4byte _0807BCD4 @ case 21
	.4byte _0807BCE6 @ case 22
	.4byte _0807BD08 @ case 23
	.4byte _0807BD50 @ case 24
	.4byte _0807BD80 @ case 25
	.4byte _0807BDC8 @ case 26
	.4byte _0807BE18 @ case 27
	.4byte _0807BE6C @ case 28
	.4byte _0807BEF0 @ case 29
	.4byte _0807BF14 @ case 30
	.4byte _0807BF60 @ case 31
	.4byte _0807BFAC @ case 32
	.4byte _0807C008 @ case 33
	.4byte _0807C068 @ case 34
	.4byte _0807C07C @ case 35
	.4byte _0807C090 @ case 36
	.4byte _0807C0A4 @ case 37
	.4byte _0807C1CC @ case 38
	.4byte _0807C29C @ case 39
	.4byte _0807C324 @ case 40
	.4byte _0807C39C @ case 41
	.4byte _0807C3AC @ case 42
	.4byte _0807C3CC @ case 43
	.4byte _0807C41C @ case 44
	.4byte _0807C43A @ case 45
	.4byte _0807C478 @ case 46
	.4byte _0807C488 @ case 47
	.4byte _0807C500 @ case 48
	.4byte _0807C9EC @ case 49
	.4byte _0807C528 @ case 50
	.4byte _0807C568 @ case 51
	.4byte _0807C5A8 @ case 52
	.4byte _0807C9EC @ case 53
	.4byte _0807C9EC @ case 54
	.4byte _0807C9EC @ case 55
	.4byte _0807C9EC @ case 56
	.4byte _0807C9EC @ case 57
	.4byte _0807C9EC @ case 58
	.4byte _0807C9EC @ case 59
	.4byte _0807C5C8 @ case 60
	.4byte _0807C5F0 @ case 61
	.4byte _0807C60C @ case 62
	.4byte _0807C62C @ case 63
	.4byte _0807C6D4 @ case 64
	.4byte _0807C708 @ case 65
	.4byte _0807C754 @ case 66
	.4byte _0807C814 @ case 67
	.4byte _0807C88C @ case 68
	.4byte _0807C8D8 @ case 69
	.4byte _0807C8E8 @ case 70
	.4byte _0807C8EE @ case 71
	.4byte _0807C914 @ case 72
	.4byte _0807C970 @ case 73
	.4byte _0807C994 @ case 74
	.4byte _0807C9EC @ case 75
	.4byte _0807C9EC @ case 76
	.4byte _0807C9EC @ case 77
	.4byte _0807C9EC @ case 78
	.4byte _0807C9EC @ case 79
	.4byte _0807C9EC @ case 80
	.4byte _0807C9EC @ case 81
	.4byte _0807C9EC @ case 82
	.4byte _0807C9EC @ case 83
	.4byte _0807C9EC @ case 84
	.4byte _0807C9EC @ case 85
	.4byte _0807C9EC @ case 86
	.4byte _0807C9EC @ case 87
	.4byte _0807C9EC @ case 88
	.4byte _0807C9EC @ case 89
	.4byte _0807C9EC @ case 90
	.4byte _0807C9EC @ case 91
	.4byte _0807C9EC @ case 92
	.4byte _0807C9EC @ case 93
	.4byte _0807C9EC @ case 94
	.4byte _0807C9EC @ case 95
	.4byte _0807C9EC @ case 96
	.4byte _0807C9EC @ case 97
	.4byte _0807C9EC @ case 98
	.4byte _0807C9EC @ case 99
	.4byte _0807C9EC @ case 100
	.4byte _0807C9EC @ case 101
	.4byte _0807C9EC @ case 102
	.4byte _0807C9EC @ case 103
	.4byte _0807C9EC @ case 104
	.4byte _0807C9EC @ case 105
	.4byte _0807C9EC @ case 106
	.4byte _0807C9EC @ case 107
	.4byte _0807C9EC @ case 108
	.4byte _0807C9EC @ case 109
	.4byte _0807C9EC @ case 110
	.4byte _0807C9EC @ case 111
	.4byte _0807C9EC @ case 112
	.4byte _0807C9EC @ case 113
	.4byte _0807C9EC @ case 114
	.4byte _0807C9EC @ case 115
	.4byte _0807C9EC @ case 116
	.4byte _0807C9EC @ case 117
	.4byte _0807C9EC @ case 118
	.4byte _0807C9EC @ case 119
	.4byte _0807C9EC @ case 120
	.4byte _0807C9EC @ case 121
	.4byte _0807C9EC @ case 122
	.4byte _0807C9EC @ case 123
	.4byte _0807C9EC @ case 124
	.4byte _0807C9EC @ case 125
	.4byte _0807C9EC @ case 126
	.4byte _0807C9EC @ case 127
	.4byte _0807C9EC @ case 128
	.4byte _0807C9EC @ case 129
	.4byte _0807C9EC @ case 130
	.4byte _0807C9EC @ case 131
	.4byte _0807C9EC @ case 132
	.4byte _0807C9EC @ case 133
	.4byte _0807C9EC @ case 134
	.4byte _0807C9EC @ case 135
	.4byte _0807C9EC @ case 136
	.4byte _0807C9EC @ case 137
	.4byte _0807C9EC @ case 138
	.4byte _0807C9EC @ case 139
	.4byte _0807C9EC @ case 140
	.4byte _0807C9EC @ case 141
	.4byte _0807C9EC @ case 142
	.4byte _0807C9EC @ case 143
	.4byte _0807C9EC @ case 144
	.4byte _0807C9EC @ case 145
	.4byte _0807C9EC @ case 146
	.4byte _0807C9EC @ case 147
	.4byte _0807C9EC @ case 148
	.4byte _0807C9EC @ case 149
	.4byte _0807C9EC @ case 150
	.4byte _0807C9EC @ case 151
	.4byte _0807C9EC @ case 152
	.4byte _0807C9EC @ case 153
	.4byte _0807C9EC @ case 154
	.4byte _0807C9EC @ case 155
	.4byte _0807C9EC @ case 156
	.4byte _0807C9EC @ case 157
	.4byte _0807C9EC @ case 158
	.4byte _0807C9EC @ case 159
	.4byte _0807C9EC @ case 160
	.4byte _0807C9EC @ case 161
	.4byte _0807C9EC @ case 162
	.4byte _0807C9EC @ case 163
	.4byte _0807C9EC @ case 164
	.4byte _0807C9EC @ case 165
	.4byte _0807C9EC @ case 166
	.4byte _0807C850 @ case 167
	.4byte _0807C9EC @ case 168
	.4byte _0807C9EC @ case 169
	.4byte _0807C9EC @ case 170
	.4byte _0807C9EC @ case 171
	.4byte _0807C9EC @ case 172
	.4byte _0807C9EC @ case 173
	.4byte _0807C9EC @ case 174
	.4byte _0807C9EC @ case 175
	.4byte _0807C9EC @ case 176
	.4byte _0807C9EC @ case 177
	.4byte _0807C9EC @ case 178
	.4byte _0807C9EC @ case 179
	.4byte _0807C9EC @ case 180
	.4byte _0807C9EC @ case 181
	.4byte _0807C9EC @ case 182
	.4byte _0807C9EC @ case 183
	.4byte _0807C9EC @ case 184
	.4byte _0807C9EC @ case 185
	.4byte _0807C9EC @ case 186
	.4byte _0807C9EC @ case 187
	.4byte _0807C9EC @ case 188
	.4byte _0807C9EC @ case 189
	.4byte _0807C9EC @ case 190
	.4byte _0807C9EC @ case 191
	.4byte _0807C9EC @ case 192
	.4byte _0807C9EC @ case 193
	.4byte _0807C9EC @ case 194
	.4byte _0807C9EC @ case 195
	.4byte _0807C9EC @ case 196
	.4byte _0807C9EC @ case 197
	.4byte _0807C9EC @ case 198
	.4byte _0807C9EC @ case 199
	.4byte _0807BE98 @ case 200
	.4byte _0807C9EC @ case 201
	.4byte _0807C9EC @ case 202
	.4byte _0807C9EC @ case 203
	.4byte _0807C9EC @ case 204
	.4byte _0807C9EC @ case 205
	.4byte _0807C9EC @ case 206
	.4byte _0807C9EC @ case 207
	.4byte _0807C9EC @ case 208
	.4byte _0807C9EC @ case 209
	.4byte _0807C9EC @ case 210
	.4byte _0807C9EC @ case 211
	.4byte _0807C9EC @ case 212
	.4byte _0807C9EC @ case 213
	.4byte _0807C9EC @ case 214
	.4byte _0807C9EC @ case 215
	.4byte _0807C9EC @ case 216
	.4byte _0807C9EC @ case 217
	.4byte _0807C9EC @ case 218
	.4byte _0807C9EC @ case 219
	.4byte _0807C9EC @ case 220
	.4byte _0807C9EC @ case 221
	.4byte _0807C9EC @ case 222
	.4byte _0807C9EC @ case 223
	.4byte _0807C9EC @ case 224
	.4byte _0807C9EC @ case 225
	.4byte _0807C9EC @ case 226
	.4byte _0807C9EC @ case 227
	.4byte _0807C9EC @ case 228
	.4byte _0807C9EC @ case 229
	.4byte _0807C9EC @ case 230
	.4byte _0807C9EC @ case 231
	.4byte _0807C9EC @ case 232
	.4byte _0807C9EC @ case 233
	.4byte _0807C9EC @ case 234
	.4byte _0807C9EC @ case 235
	.4byte _0807C9EC @ case 236
	.4byte _0807C9EC @ case 237
	.4byte _0807C9EC @ case 238
	.4byte _0807C9EC @ case 239
	.4byte _0807C9EC @ case 240
	.4byte _0807C9EC @ case 241
	.4byte _0807C9EC @ case 242
	.4byte _0807C9EC @ case 243
	.4byte _0807C9EC @ case 244
	.4byte _0807C9EC @ case 245
	.4byte _0807C9EC @ case 246
	.4byte _0807C9EC @ case 247
	.4byte _0807C9EC @ case 248
	.4byte _0807C9EC @ case 249
	.4byte _0807C9EC @ case 250
	.4byte _0807C9EC @ case 251
	.4byte _0807C9EC @ case 252
	.4byte _0807C9EC @ case 253
	.4byte _0807C9EC @ case 254
	.4byte _0807C9EC @ case 255
	.4byte _0807C9EC @ case 256
	.4byte _0807C9EC @ case 257
	.4byte _0807C9EC @ case 258
	.4byte _0807C9EC @ case 259
	.4byte _0807C9EC @ case 260
	.4byte _0807C9EC @ case 261
	.4byte _0807C9EC @ case 262
	.4byte _0807C9EC @ case 263
	.4byte _0807C9EC @ case 264
	.4byte _0807C9EC @ case 265
	.4byte _0807C9EC @ case 266
	.4byte _0807C870 @ case 267
_0807BA84:
	ldr r3, _0807BAEC
	ldr r0, [r7]
	adds r0, #0x8e
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
	ldr r4, [r7]
	adds r2, r4, #0
	adds r2, #0x8e
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, _0807BAF0
	strh r1, [r0, #0x24]
	ldrb r0, [r2]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r2, _0807BAF4
	adds r0, r4, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	strh r0, [r1, #0x26]
	adds r1, r4, #0
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl GetCurrentMapMusic
	ldr r1, [r7]
	adds r1, #0xf4
	strh r0, [r1]
	ldr r0, _0807BAF8
	bl PlayNewMapMusic
	bl _0807C9EC
	.align 2, 0
_0807BAEC: .4byte 0x020205AC
_0807BAF0: .4byte 0x0000FF4C
_0807BAF4: .4byte 0x082D45C8
_0807BAF8: .4byte 0x00000179
_0807BAFC:
	ldr r5, [r7]
	adds r6, r5, #0
	adds r6, #0xe6
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	ble _0807BB30
	ldr r2, _0807BB2C
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x24]
	adds r1, #3
	strh r1, [r0, #0x24]
	ldrh r0, [r6]
	subs r0, #3
	strh r0, [r6]
	bl _0807C9EC
	.align 2, 0
_0807BB2C: .4byte 0x020205AC
_0807BB30:
	ldr r2, _0807BB54
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #0
	strh r1, [r0, #0x24]
	strh r1, [r6]
	adds r1, r5, #0
	adds r1, #0x94
	movs r0, #0xa
	strh r0, [r1]
	bl _0807C9EC
	.align 2, 0
_0807BB54: .4byte 0x020205AC
_0807BB58:
	ldr r4, _0807BB94
	ldr r1, _0807BB98
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	ldr r4, _0807BB9C
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0xf0
	ldrh r1, [r2]
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807BB86
	adds r0, r1, #0
	movs r1, #0
	bl PlayCry1
_0807BB86:
	ldr r3, [r4]
	adds r1, r3, #0
	adds r1, #0x94
	movs r2, #0
	movs r0, #0xb
	bl _0807C83E
	.align 2, 0
_0807BB94: .4byte 0x02021C7C
_0807BB98: .4byte 0x0830D240
_0807BB9C: .4byte 0x02031F40
_0807BBA0:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x50
	beq _0807BBB0
	bl _0807C9EC
_0807BBB0:
	adds r0, r1, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	ldr r2, _0807BC04
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #5]
	lsrs r1, r1, #4
	movs r2, #2
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0x14
	str r2, [sp, #8]
	ldr r2, _0807BC08
	str r2, [sp, #0xc]
	movs r2, #0x78
	movs r3, #0x20
	bl sub_08076124
	ldr r1, [r7]
	adds r1, #0xd2
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r4, _0807BC0C
	ldr r1, _0807BC10
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	bl _0807C9EC
	.align 2, 0
_0807BC04: .4byte 0x020205AC
_0807BC08: .4byte 0x000FFFFF
_0807BC0C: .4byte 0x02021C7C
_0807BC10: .4byte 0x0830D24F
_0807BC14:
	ldr r5, _0807BC70
	ldr r0, [r7]
	adds r0, #0xd2
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r0, _0807BC74
	cmp r1, r0
	beq _0807BC34
	bl _0807C9EC
_0807BC34:
	ldr r0, _0807BC78
	movs r1, #0x78
	movs r2, #0x20
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0xd3
	strb r0, [r1]
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, _0807BC7C
	str r1, [r0]
	adds r2, #0xd2
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	bl DestroySprite
	ldr r1, [r7]
	bl _0807C984
	.align 2, 0
_0807BC70: .4byte 0x020205AC
_0807BC74: .4byte 0x08007141
_0807BC78: .4byte 0x0830CF6C
_0807BC7C: .4byte 0x0807E011
_0807BC80:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0807BCA0
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x14
	strh r1, [r0]
	bl _0807C9EC
	.align 2, 0
_0807BCA0: .4byte 0x02031F40
_0807BCA4:
	ldr r0, _0807BCD0
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807BCB4
	bl _0807C9EC
_0807BCB4:
	movs r0, #4
	bl sub_0807B064
	movs r0, #0
	movs r1, #0xff
	bl FillWindowPixelBuffer
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	bl _0807C980
	.align 2, 0
_0807BCD0: .4byte 0x02037C74
_0807BCD4:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0x10
	movs r3, #0
	bl _0807C97C
_0807BCE6:
	ldr r0, _0807BD04
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807BCF6
	bl _0807C9EC
_0807BCF6:
	ldr r0, [r7]
	adds r0, #0x94
	movs r1, #0x17
	strh r1, [r0]
	bl _0807C9EC
	.align 2, 0
_0807BD04: .4byte 0x02037C74
_0807BD08:
	ldr r4, _0807BD24
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0xea
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _0807BD28
	adds r0, r1, #0
	subs r0, #0x34
	strh r0, [r2]
	b _0807BD44
	.align 2, 0
_0807BD24: .4byte 0x02031F40
_0807BD28:
	movs r0, #1
	bl sub_0807B064
	ldr r3, [r4]
	adds r1, r3, #0
	adds r1, #0xea
	movs r2, #0
	movs r0, #0x80
	strh r0, [r1]
	subs r1, #0x56
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	str r2, [r3, #0x64]
_0807BD44:
	ldr r0, _0807BD4C
	ldr r4, [r0]
	bl _0807C594
	.align 2, 0
_0807BD4C: .4byte 0x02031F40
_0807BD50:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x14
	bhi _0807BD60
	bl _0807C9EC
_0807BD60:
	bl sub_0807A598
	ldr r0, _0807BD7C
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0x91
	strb r0, [r1]
	ldr r1, [r7]
	bl _0807C984
	.align 2, 0
_0807BD7C: .4byte 0x0830D0B8
_0807BD80:
	ldr r2, _0807BDC0
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	cmp r0, #0
	blt _0807BDA0
	bl _0807C9EC
_0807BDA0:
	adds r0, r1, #0
	bl DestroySprite
	movs r1, #0xc8
	lsls r1, r1, #3
	movs r0, #0x50
	bl SetGpuReg
	ldr r1, _0807BDC4
	movs r0, #0x52
	bl SetGpuReg
	ldr r1, [r7]
	bl _0807C984
	.align 2, 0
_0807BDC0: .4byte 0x020205AC
_0807BDC4: .4byte 0x0000040C
_0807BDC8:
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0xe0
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x9e
	lsls r0, r0, #0x11
	cmp r1, r0
	bne _0807BDE8
	adds r1, r2, #0
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807BDE8:
	ldr r0, [r7]
	adds r0, #0xe0
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xa4
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807BDFC
	bl _0807C9EC
_0807BDFC:
	ldr r0, _0807BE14
	movs r1, #0x80
	movs r2, #0x41
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0x92
	strb r0, [r1]
	bl _0807C9EC
	.align 2, 0
_0807BE14: .4byte 0x0830D040
_0807BE18:
	ldr r0, _0807BE5C
	movs r1, #0x80
	movs r2, #0x50
	movs r3, #3
	bl CreateSprite
	ldr r4, _0807BE60
	ldr r1, [r4]
	adds r1, #0x90
	strb r0, [r1]
	ldr r0, _0807BE64
	movs r1, #0x80
	movs r2, #0x50
	movs r3, #0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, #0x91
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0807BE68
	adds r0, r0, r1
	movs r1, #1
	bl StartSpriteAnim
	ldr r1, [r4]
	bl _0807C984
	.align 2, 0
_0807BE5C: .4byte 0x0830CFCC
_0807BE60: .4byte 0x02031F40
_0807BE64: .4byte 0x0830D00C
_0807BE68: .4byte 0x020205AC
_0807BE6C:
	ldr r2, [r7]
	adds r1, r2, #0
	adds r1, #0xe0
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa6
	bne _0807BE86
	subs r1, #0x4c
	movs r0, #0xc8
	strh r0, [r1]
_0807BE86:
	ldr r1, _0807BE94
	movs r0, #0
	bl SetGpuReg
	bl _0807C9EC
	.align 2, 0
_0807BE94: .4byte 0x00001241
_0807BE98:
	ldr r2, _0807BEEC
	ldr r4, [r7]
	adds r3, r4, #0
	adds r3, #0x90
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x22]
	subs r1, #2
	strh r1, [r0, #0x22]
	adds r0, r4, #0
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x22]
	subs r1, #2
	strh r1, [r0, #0x22]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r3, #0x22
	ldrsh r1, [r0, r3]
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0807BEDE
	bl _0807C9EC
_0807BEDE:
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0x1d
	strh r0, [r1]
	bl _0807C9EC
	.align 2, 0
_0807BEEC: .4byte 0x020205AC
_0807BEF0:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0807BF10
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x1e
	strh r1, [r0]
	bl _0807C9EC
	.align 2, 0
_0807BF10: .4byte 0x02031F40
_0807BF14:
	ldr r0, _0807BF58
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807BF24
	bl _0807C9EC
_0807BF24:
	ldr r0, [r7]
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0807BF5C
	adds r0, r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	movs r0, #2
	bl sub_0807B064
	ldr r1, [r7]
	bl _0807C984
	.align 2, 0
_0807BF58: .4byte 0x02037C74
_0807BF5C: .4byte 0x020205AC
_0807BF60:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	ldr r5, _0807BFA4
	adds r0, r5, #0
	movs r1, #0x6f
	movs r2, #0xaa
	movs r3, #0
	bl CreateSprite
	ldr r4, _0807BFA8
	ldr r1, [r4]
	adds r1, #0x90
	strb r0, [r1]
	movs r2, #0xa
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0x81
	movs r3, #0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, #0x91
	strb r0, [r1]
	ldr r1, [r4]
	bl _0807C984
	.align 2, 0
_0807BFA4: .4byte 0x0830D00C
_0807BFA8: .4byte 0x02031F40
_0807BFAC:
	ldr r0, _0807BFFC
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807BFCA
	movs r0, #0x2e
	bl PlaySE
	ldr r0, _0807C000
	ldr r1, [r0]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807BFCA:
	ldr r3, _0807C004
	ldr r0, _0807C000
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r1, [r0, #0x26]
	subs r1, #3
	strh r1, [r0, #0x26]
	adds r2, #0x91
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	bl _0807C9EC
	.align 2, 0
_0807BFFC: .4byte 0x02037C74
_0807C000: .4byte 0x02031F40
_0807C004: .4byte 0x020205AC
_0807C008:
	ldr r5, _0807C064
	ldr r4, [r7]
	adds r2, r4, #0
	adds r2, #0x90
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r1, [r0, #0x26]
	subs r1, #3
	strh r1, [r0, #0x26]
	adds r6, r4, #0
	adds r6, #0x91
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r0, r5
	movs r0, #0x26
	ldrsh r1, [r3, r0]
	movs r0, #0x5a
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0807C04E
	bl _0807C9EC
_0807C04E:
	movs r2, #1
	strh r2, [r3, #0x30]
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	strh r2, [r0, #0x30]
	adds r1, r4, #0
	bl _0807C984
	.align 2, 0
_0807C064: .4byte 0x020205AC
_0807C068:
	ldr r2, _0807C078
	movs r0, #1
	movs r1, #0x10
	bl BlendPalettes
	bl _0807C980
	.align 2, 0
_0807C078: .4byte 0x0000FFFF
_0807C07C:
	ldr r2, _0807C08C
	movs r0, #1
	movs r1, #0
	bl BlendPalettes
	bl _0807C980
	.align 2, 0
_0807C08C: .4byte 0x0000FFFF
_0807C090:
	ldr r2, _0807C0A0
	movs r0, #1
	movs r1, #0x10
	bl BlendPalettes
	bl _0807C980
	.align 2, 0
_0807C0A0: .4byte 0x0000FFFF
_0807C0A4:
	ldr r5, _0807C110
	ldr r0, [r5]
	adds r0, #0xf0
	ldrh r0, [r0]
	bl IsMonSpriteNotFlipped
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807C11C
	ldr r4, _0807C114
	ldr r2, [r5]
	adds r2, #0x8e
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _0807C118
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r1, [r0, #1]
	movs r2, #3
	orrs r1, r2
	strb r1, [r0, #1]
	ldr r0, [r5]
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0
	movs r2, #3
	movs r3, #3
	bl CalcCenterToCornerVec
	ldr r0, [r5]
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0
	bl StartSpriteAffineAnim
	b _0807C132
	.align 2, 0
_0807C110: .4byte 0x02031F40
_0807C114: .4byte 0x020205AC
_0807C118: .4byte 0x0830D110
_0807C11C:
	ldr r0, [r5]
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0807C1C0
	adds r0, r0, r1
	movs r1, #0
	bl StartSpriteAffineAnim
_0807C132:
	ldr r5, _0807C1C4
	ldr r0, [r5]
	adds r0, #0x8f
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0807C1C0
	adds r0, r0, r4
	movs r1, #0
	bl StartSpriteAffineAnim
	ldr r2, [r5]
	adds r3, r2, #0
	adds r3, #0x8e
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0x3c
	strh r1, [r0, #0x20]
	adds r2, #0x8f
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0xb4
	strh r1, [r0, #0x20]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0xc0
	strh r1, [r0, #0x22]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, _0807C1C8
	strh r1, [r0, #0x22]
	ldrb r0, [r3]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, #0x3e
	ldrb r3, [r1]
	movs r2, #5
	rsbs r2, r2, #0
	adds r0, r2, #0
	ands r0, r3
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #0x8f
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x3e
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	ldr r1, [r5]
	bl _0807C984
	.align 2, 0
_0807C1C0: .4byte 0x020205AC
_0807C1C4: .4byte 0x02031F40
_0807C1C8: .4byte 0x0000FFE0
_0807C1CC:
	ldr r4, _0807C294
	ldr r2, [r7]
	adds r3, r2, #0
	adds r3, #0x8e
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x26]
	subs r1, #3
	movs r5, #0
	strh r1, [r0, #0x26]
	adds r2, #0x8f
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r0, [r0, #0x26]
	adds r0, #0xa3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0807C214
	movs r0, #0x2d
	bl PlaySE
_0807C214:
	ldr r2, [r7]
	adds r3, r2, #0
	adds r3, #0x8e
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r6, #0x26
	ldrsh r1, [r0, r6]
	movs r0, #0xde
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0807C234
	bl _0807C9EC
_0807C234:
	adds r0, r2, #0
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r5, [r0, #0x30]
	adds r0, r2, #0
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r5, [r0, #0x30]
	adds r1, r2, #0
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0x8f
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldr r2, _0807C298
	movs r0, #1
	movs r1, #0
	bl BlendPalettes
	b _0807C9EC
	.align 2, 0
_0807C294: .4byte 0x020205AC
_0807C298: .4byte 0x0000FFFF
_0807C29C:
	ldr r4, _0807C320
	ldr r2, [r7]
	adds r3, r2, #0
	adds r3, #0x90
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x26]
	subs r1, #3
	strh r1, [r0, #0x26]
	adds r2, #0x91
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r2, #0x26
	ldrsh r1, [r0, r2]
	movs r0, #0xde
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0807C2DE
	b _0807C9EC
_0807C2DE:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r1, [r7]
	adds r2, r1, #0
	adds r2, #0x94
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, #0x90
	ldrb r1, [r1]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	b _0807C9EC
	.align 2, 0
_0807C320: .4byte 0x020205AC
_0807C324:
	ldr r0, _0807C38C
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807C332
	b _0807C9EC
_0807C332:
	ldr r1, [r7]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #1
	bl sub_0807B064
	ldr r0, [r7]
	adds r0, #0xe0
	movs r1, #0xa6
	strh r1, [r0]
	ldr r0, _0807C390
	movs r4, #0x14
	rsbs r4, r4, #0
	movs r1, #0x80
	adds r2, r4, #0
	movs r3, #3
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0x90
	strb r0, [r1]
	ldr r0, _0807C394
	movs r1, #0x80
	adds r2, r4, #0
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0x91
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0807C398
	adds r0, r0, r1
	movs r1, #1
	bl StartSpriteAnim
	b _0807C9EC
	.align 2, 0
_0807C38C: .4byte 0x02037C74
_0807C390: .4byte 0x0830CFCC
_0807C394: .4byte 0x0830D00C
_0807C398: .4byte 0x020205AC
_0807C39C:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0x10
	movs r3, #0
	b _0807C97C
_0807C3AC:
	movs r1, #0x92
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r0, _0807C3C8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807C3C4
	b _0807C9EC
_0807C3C4:
	b _0807C980
	.align 2, 0
_0807C3C8: .4byte 0x02037C74
_0807C3CC:
	ldr r2, _0807C418
	ldr r4, [r7]
	adds r3, r4, #0
	adds r3, #0x90
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	adds r0, r4, #0
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r3, #0x26
	ldrsh r1, [r0, r3]
	movs r6, #0x22
	ldrsh r0, [r0, r6]
	adds r1, r1, r0
	cmp r1, #0x40
	beq _0807C412
	b _0807C9EC
_0807C412:
	adds r1, r4, #0
	b _0807C984
	.align 2, 0
_0807C418: .4byte 0x020205AC
_0807C41C:
	ldr r1, [r7]
	adds r5, r1, #0
	adds r5, #0xe0
	ldrh r0, [r5]
	adds r0, #2
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r6, #0x9e
	lsls r6, r6, #1
	cmp r0, r6
	bgt _0807C436
	b _0807C9EC
_0807C436:
	strh r6, [r5]
	b _0807C984
_0807C43A:
	ldr r0, [r7]
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0807C474
	adds r0, r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	ldr r3, [r7]
	adds r2, r3, #0
	adds r2, #0x94
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	str r1, [r3, #0x64]
	b _0807C9EC
	.align 2, 0
_0807C474: .4byte 0x020205AC
_0807C478:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0xa
	beq _0807C486
	b _0807C9EC
_0807C486:
	b _0807C984
_0807C488:
	ldr r1, [r7]
	adds r2, r1, #0
	adds r2, #0xe0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0xae
	lsls r3, r3, #1
	cmp r0, r3
	ble _0807C4AA
	strh r3, [r2]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807C4AA:
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0xe0
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xa4
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807C4BE
	b _0807C9EC
_0807C4BE:
	adds r0, r2, #0
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _0807C4CA
	b _0807C9EC
_0807C4CA:
	ldr r0, _0807C4F4
	movs r1, #0x80
	movs r2, #0x41
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0x92
	strb r0, [r1]
	ldr r2, _0807C4F8
	ldr r0, [r7]
	adds r0, #0x92
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #0x1c
	adds r0, r0, r2
	ldr r1, _0807C4FC
	str r1, [r0]
	b _0807C9EC
	.align 2, 0
_0807C4F4: .4byte 0x0830D040
_0807C4F8: .4byte 0x020205AC
_0807C4FC: .4byte 0x0807A551
_0807C500:
	ldr r0, _0807C520
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #0
	bl CreateSprite
	ldr r2, _0807C524
	ldr r1, [r2]
	adds r1, #0x91
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, #0x94
	movs r1, #0x32
	strh r1, [r0]
	b _0807C9EC
	.align 2, 0
_0807C520: .4byte 0x0830D0B8
_0807C524: .4byte 0x02031F40
_0807C528:
	ldr r2, _0807C564
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	cmp r0, #0
	blt _0807C546
	b _0807C9EC
_0807C546:
	adds r0, r1, #0
	bl DestroySprite
	movs r0, #6
	bl sub_0807B064
	ldr r1, [r7]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0x9f
	bl PlaySE
	b _0807C9EC
	.align 2, 0
_0807C564: .4byte 0x020205AC
_0807C568:
	ldr r1, [r7]
	adds r2, r1, #0
	adds r2, #0xea
	ldrh r3, [r2]
	ldr r0, _0807C580
	cmp r3, r0
	bhi _0807C584
	adds r0, r3, #0
	adds r0, #0x34
	strh r0, [r2]
	b _0807C592
	.align 2, 0
_0807C580: .4byte 0x000003FF
_0807C584:
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r2]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807C592:
	ldr r4, [r7]
_0807C594:
	adds r0, r4, #0
	adds r0, #0xea
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	bl __divsi3
	adds r4, #0xe8
	strh r0, [r4]
	b _0807C9EC
_0807C5A8:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0807C5C4
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x3c
	strh r1, [r0]
	b _0807C9EC
	.align 2, 0
_0807C5C4: .4byte 0x02031F40
_0807C5C8:
	ldr r4, _0807C5EC
	ldrb r1, [r4, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807C5D6
	b _0807C9EC
_0807C5D6:
	movs r0, #5
	bl sub_0807B064
	movs r0, #7
	bl sub_0807B064
	ldrb r0, [r4, #8]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r4, #8]
	b _0807C980
	.align 2, 0
_0807C5EC: .4byte 0x02037C74
_0807C5F0:
	ldr r2, _0807C608
	ldrb r1, [r2, #8]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #8]
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0x10
	movs r3, #0
	b _0807C97C
	.align 2, 0
_0807C608: .4byte 0x02037C74
_0807C60C:
	movs r1, #0xa2
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r0, _0807C628
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807C624
	b _0807C9EC
_0807C624:
	b _0807C980
	.align 2, 0
_0807C628: .4byte 0x02037C74
_0807C62C:
	ldr r0, _0807C6C0
	movs r2, #8
	rsbs r2, r2, #0
	movs r1, #0x78
	movs r3, #0
	bl CreateSprite
	ldr r5, _0807C6C4
	ldr r1, [r5]
	adds r1, #0xd3
	movs r6, #0
	strb r0, [r1]
	ldr r4, _0807C6C8
	ldr r2, [r5]
	adds r2, #0xd3
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0x4a
	strh r1, [r0, #0x34]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _0807C6CC
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #1
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #2
	bl StartSpriteAffineAnim
	ldr r0, [r5]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r1, [r0, #5]
	lsrs r1, r1, #4
	adds r1, #0x10
	movs r0, #1
	lsls r0, r1
	ldr r2, _0807C6D0
	movs r1, #0x10
	bl BlendPalettes
	ldr r2, [r5]
	adds r1, r2, #0
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	str r6, [r2, #0x64]
	b _0807C9EC
	.align 2, 0
_0807C6C0: .4byte 0x0830CF6C
_0807C6C4: .4byte 0x02031F40
_0807C6C8: .4byte 0x020205AC
_0807C6CC: .4byte 0x0807E0E5
_0807C6D0: .4byte 0x0000FFFF
_0807C6D4:
	ldr r2, _0807C700
	ldr r0, [r7]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0, #5]
	lsrs r1, r1, #4
	adds r1, #0x10
	movs r0, #1
	lsls r0, r1
	ldr r1, _0807C704
	str r1, [sp]
	movs r1, #1
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	ldr r1, [r7]
	b _0807C984
	.align 2, 0
_0807C700: .4byte 0x020205AC
_0807C704: .4byte 0x0000FFFF
_0807C708:
	ldr r2, _0807C744
	ldr r3, [r7]
	adds r0, r3, #0
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #0x1c
	adds r0, r0, r2
	ldr r1, [r0]
	ldr r0, _0807C748
	cmp r1, r0
	beq _0807C726
	b _0807C9EC
_0807C726:
	adds r0, r3, #0
	adds r0, #0xf2
	ldrh r2, [r0]
	lsls r0, r2, #3
	ldr r1, _0807C74C
	adds r0, r0, r1
	ldr r1, _0807C750
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	ldr r3, [r3, #0x6c]
	bl HandleLoadSpecialPokePic_2
	ldr r1, [r7]
	b _0807C984
	.align 2, 0
_0807C744: .4byte 0x020205AC
_0807C748: .4byte 0x08007141
_0807C74C: .4byte 0x082DDA1C
_0807C750: .4byte 0x02024178
_0807C754:
	ldr r4, _0807C808
	ldr r2, [r7]
	adds r6, r2, #0
	adds r6, #0x8f
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r5, #0
	movs r1, #0x78
	strh r1, [r0, #0x20]
	ldrb r0, [r6]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r3, _0807C80C
	adds r2, #0xf2
	ldrh r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #1]
	adds r0, #0x3c
	strh r0, [r1, #0x22]
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r5, [r0, #0x24]
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r5, [r0, #0x26]
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0
	bl StartSpriteAnim
	ldr r3, [r7]
	adds r0, r3, #0
	adds r0, #0x8f
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r1, [r1, #5]
	lsrs r1, r1, #4
	movs r2, #2
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0x14
	str r2, [sp, #8]
	ldr r2, _0807C810
	str r2, [sp, #0xc]
	adds r3, #0xf2
	ldrh r2, [r3]
	str r2, [sp, #0x10]
	movs r2, #0x78
	movs r3, #0x54
	bl CreatePokeballSpriteToReleaseMon
	ldr r0, [r7]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl FreeSpriteOamMatrix
	ldr r0, [r7]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	ldr r1, [r7]
	b _0807C984
	.align 2, 0
_0807C808: .4byte 0x020205AC
_0807C80C: .4byte 0x082D45C8
_0807C810: .4byte 0x000FFFFF
_0807C814:
	movs r1, #0xaa
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r4, _0807C844
	ldr r1, _0807C848
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	ldr r0, _0807C84C
	ldr r3, [r0]
	adds r1, r3, #0
	adds r1, #0x94
	movs r2, #0
	movs r0, #0xa7
_0807C83E:
	strh r0, [r1]
	str r2, [r3, #0x64]
	b _0807C9EC
	.align 2, 0
_0807C844: .4byte 0x02021C7C
_0807C848: .4byte 0x0830D258
_0807C84C: .4byte 0x02031F40
_0807C850:
	ldr r3, [r7]
	ldr r0, [r3, #0x64]
	adds r0, #1
	str r0, [r3, #0x64]
	cmp r0, #0x3c
	bhi _0807C85E
	b _0807C9EC
_0807C85E:
	adds r0, r3, #0
	adds r0, #0x94
	movs r2, #0
	ldr r1, _0807C86C
	strh r1, [r0]
	str r2, [r3, #0x64]
	b _0807C9EC
	.align 2, 0
_0807C86C: .4byte 0x0000010B
_0807C870:
	bl IsCryFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807C87C
	b _0807C9EC
_0807C87C:
	ldr r0, _0807C888
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x44
	strh r1, [r0]
	b _0807C9EC
	.align 2, 0
_0807C888: .4byte 0x02031F40
_0807C88C:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0xa
	bne _0807C89E
	ldr r0, _0807C8CC
	bl PlayFanfare
_0807C89E:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	cmp r0, #0xfa
	beq _0807C8A8
	b _0807C9EC
_0807C8A8:
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	ldr r4, _0807C8D0
	ldr r1, _0807C8D4
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	ldr r0, [r7]
	str r5, [r0, #0x64]
	b _0807C9EC
	.align 2, 0
_0807C8CC: .4byte 0x00000173
_0807C8D0: .4byte 0x02021C7C
_0807C8D4: .4byte 0x0830D26A
_0807C8D8:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x3c
	beq _0807C8E6
	b _0807C9EC
_0807C8E6:
	b _0807C984
_0807C8E8:
	bl sub_0807EB84
	b _0807C980
_0807C8EE:
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0xee
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807C8FE
	movs r0, #1
	b _0807C9EE
_0807C8FE:
	ldr r0, _0807C910
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807C9EC
	adds r1, r2, #0
	b _0807C984
	.align 2, 0
_0807C910: .4byte 0x03002360
_0807C914:
	ldr r0, _0807C958
	ldrb r0, [r0]
	movs r1, #0
	bl sub_0807AF08
	ldr r1, _0807C95C
	ldr r0, _0807C960
	str r0, [r1]
	ldr r7, _0807C964
	ldrb r0, [r7]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _0807C968
	adds r0, r0, r5
	movs r1, #1
	movs r2, #0
	bl GetEvolutionTargetSpecies
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0807C980
	ldrb r3, [r7]
	adds r0, r3, #0
	muls r0, r6, r0
	adds r0, r0, r5
	ldr r1, _0807C96C
	ldr r1, [r1]
	adds r1, #0x8f
	ldrb r2, [r1]
	adds r1, r4, #0
	bl TradeEvolutionScene
	b _0807C980
	.align 2, 0
_0807C958: .4byte 0x02037282
_0807C95C: .4byte 0x03005F28
_0807C960: .4byte 0x0807B045
_0807C964: .4byte 0x02031F38
_0807C968: .4byte 0x02024190
_0807C96C: .4byte 0x02031F40
_0807C970:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
_0807C97C:
	bl BeginNormalPaletteFade
_0807C980:
	ldr r0, _0807C990
	ldr r1, [r0]
_0807C984:
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0807C9EC
	.align 2, 0
_0807C990: .4byte 0x02031F40
_0807C994:
	ldr r0, _0807C9F8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0807C9EC
	ldr r0, [r7]
	adds r0, #0xf4
	ldrh r0, [r0]
	bl PlayNewMapMusic
	ldr r0, [r7]
	cmp r0, #0
	beq _0807C9E2
	bl FreeAllWindowBuffers
	movs r0, #3
	bl GetBgTilemapBuffer
	bl Free
	movs r0, #1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, #0
	bl GetBgTilemapBuffer
	bl Free
	bl FreeMonSpritesGfx
	ldr r0, [r7]
	bl Free
	str r4, [r7]
_0807C9E2:
	ldr r0, _0807C9FC
	bl SetMainCallback2
	bl sub_0807E1C4
_0807C9EC:
	movs r0, #0
_0807C9EE:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807C9F8: .4byte 0x02037C74
_0807C9FC: .4byte 0x08085A31
	thumb_func_end sub_0807B624

	thumb_func_start sub_0807CA00
sub_0807CA00: @ 0x0807CA00
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	ldr r0, _0807CA24
	ldr r1, [r0]
	adds r1, #0x94
	ldrh r5, [r1]
	ldr r1, _0807CA28
	adds r7, r0, #0
	cmp r5, r1
	bls _0807CA18
	bl _0807DE38
_0807CA18:
	lsls r0, r5, #2
	ldr r1, _0807CA2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807CA24: .4byte 0x02031F40
_0807CA28: .4byte 0x0000010B
_0807CA2C: .4byte 0x0807CA30
_0807CA30: @ jump table
	.4byte _0807CE60 @ case 0
	.4byte _0807CED8 @ case 1
	.4byte _0807DE38 @ case 2
	.4byte _0807DE38 @ case 3
	.4byte _0807DE38 @ case 4
	.4byte _0807DE38 @ case 5
	.4byte _0807DE38 @ case 6
	.4byte _0807DE38 @ case 7
	.4byte _0807DE38 @ case 8
	.4byte _0807DE38 @ case 9
	.4byte _0807CF34 @ case 10
	.4byte _0807CF7C @ case 11
	.4byte _0807CFF0 @ case 12
	.4byte _0807DE38 @ case 13
	.4byte _0807D05C @ case 14
	.4byte _0807DE38 @ case 15
	.4byte _0807DE38 @ case 16
	.4byte _0807DE38 @ case 17
	.4byte _0807DE38 @ case 18
	.4byte _0807DE38 @ case 19
	.4byte _0807D080 @ case 20
	.4byte _0807D0B0 @ case 21
	.4byte _0807D0C2 @ case 22
	.4byte _0807D0E4 @ case 23
	.4byte _0807DE38 @ case 24
	.4byte _0807DE38 @ case 25
	.4byte _0807D1DC @ case 26
	.4byte _0807D1FC @ case 27
	.4byte _0807D268 @ case 28
	.4byte _0807D2EC @ case 29
	.4byte _0807D310 @ case 30
	.4byte _0807D35C @ case 31
	.4byte _0807D3A8 @ case 32
	.4byte _0807D404 @ case 33
	.4byte _0807D470 @ case 34
	.4byte _0807D484 @ case 35
	.4byte _0807D498 @ case 36
	.4byte _0807D4AC @ case 37
	.4byte _0807D5D4 @ case 38
	.4byte _0807D6A4 @ case 39
	.4byte _0807D72C @ case 40
	.4byte _0807D7CC @ case 41
	.4byte _0807D7DC @ case 42
	.4byte _0807D7FC @ case 43
	.4byte _0807DE38 @ case 44
	.4byte _0807DE38 @ case 45
	.4byte _0807D920 @ case 46
	.4byte _0807D930 @ case 47
	.4byte _0807D94E @ case 48
	.4byte _0807DE38 @ case 49
	.4byte _0807D974 @ case 50
	.4byte _0807D9B4 @ case 51
	.4byte _0807D9F4 @ case 52
	.4byte _0807DE38 @ case 53
	.4byte _0807DE38 @ case 54
	.4byte _0807DE38 @ case 55
	.4byte _0807DE38 @ case 56
	.4byte _0807DE38 @ case 57
	.4byte _0807DE38 @ case 58
	.4byte _0807DE38 @ case 59
	.4byte _0807DA14 @ case 60
	.4byte _0807DA3C @ case 61
	.4byte _0807DA58 @ case 62
	.4byte _0807DA78 @ case 63
	.4byte _0807DB20 @ case 64
	.4byte _0807DB54 @ case 65
	.4byte _0807DBA0 @ case 66
	.4byte _0807DC60 @ case 67
	.4byte _0807DCD8 @ case 68
	.4byte _0807DD24 @ case 69
	.4byte _0807DD34 @ case 70
	.4byte _0807DD3A @ case 71
	.4byte _0807DD60 @ case 72
	.4byte _0807DDBC @ case 73
	.4byte _0807DDE0 @ case 74
	.4byte _0807DE38 @ case 75
	.4byte _0807DE38 @ case 76
	.4byte _0807DE38 @ case 77
	.4byte _0807DE38 @ case 78
	.4byte _0807DE38 @ case 79
	.4byte _0807DE38 @ case 80
	.4byte _0807DE38 @ case 81
	.4byte _0807DE38 @ case 82
	.4byte _0807DE38 @ case 83
	.4byte _0807DE38 @ case 84
	.4byte _0807DE38 @ case 85
	.4byte _0807DE38 @ case 86
	.4byte _0807DE38 @ case 87
	.4byte _0807DE38 @ case 88
	.4byte _0807DE38 @ case 89
	.4byte _0807DE38 @ case 90
	.4byte _0807DE38 @ case 91
	.4byte _0807DE38 @ case 92
	.4byte _0807DE38 @ case 93
	.4byte _0807DE38 @ case 94
	.4byte _0807DE38 @ case 95
	.4byte _0807DE38 @ case 96
	.4byte _0807DE38 @ case 97
	.4byte _0807DE38 @ case 98
	.4byte _0807DE38 @ case 99
	.4byte _0807DE38 @ case 100
	.4byte _0807DE38 @ case 101
	.4byte _0807DE38 @ case 102
	.4byte _0807DE38 @ case 103
	.4byte _0807DE38 @ case 104
	.4byte _0807DE38 @ case 105
	.4byte _0807DE38 @ case 106
	.4byte _0807DE38 @ case 107
	.4byte _0807DE38 @ case 108
	.4byte _0807DE38 @ case 109
	.4byte _0807DE38 @ case 110
	.4byte _0807DE38 @ case 111
	.4byte _0807DE38 @ case 112
	.4byte _0807DE38 @ case 113
	.4byte _0807DE38 @ case 114
	.4byte _0807DE38 @ case 115
	.4byte _0807DE38 @ case 116
	.4byte _0807DE38 @ case 117
	.4byte _0807DE38 @ case 118
	.4byte _0807DE38 @ case 119
	.4byte _0807DE38 @ case 120
	.4byte _0807DE38 @ case 121
	.4byte _0807DE38 @ case 122
	.4byte _0807DE38 @ case 123
	.4byte _0807D12C @ case 124
	.4byte _0807D160 @ case 125
	.4byte _0807D1B4 @ case 126
	.4byte _0807DE38 @ case 127
	.4byte _0807DE38 @ case 128
	.4byte _0807DE38 @ case 129
	.4byte _0807DE38 @ case 130
	.4byte _0807DE38 @ case 131
	.4byte _0807DE38 @ case 132
	.4byte _0807DE38 @ case 133
	.4byte _0807DE38 @ case 134
	.4byte _0807DE38 @ case 135
	.4byte _0807DE38 @ case 136
	.4byte _0807DE38 @ case 137
	.4byte _0807DE38 @ case 138
	.4byte _0807DE38 @ case 139
	.4byte _0807DE38 @ case 140
	.4byte _0807DE38 @ case 141
	.4byte _0807DE38 @ case 142
	.4byte _0807DE38 @ case 143
	.4byte _0807D854 @ case 144
	.4byte _0807D8BC @ case 145
	.4byte _0807D8F8 @ case 146
	.4byte _0807DE38 @ case 147
	.4byte _0807DE38 @ case 148
	.4byte _0807DE38 @ case 149
	.4byte _0807DE38 @ case 150
	.4byte _0807DE38 @ case 151
	.4byte _0807DE38 @ case 152
	.4byte _0807DE38 @ case 153
	.4byte _0807DE38 @ case 154
	.4byte _0807DE38 @ case 155
	.4byte _0807DE38 @ case 156
	.4byte _0807DE38 @ case 157
	.4byte _0807DE38 @ case 158
	.4byte _0807DE38 @ case 159
	.4byte _0807DE38 @ case 160
	.4byte _0807DE38 @ case 161
	.4byte _0807DE38 @ case 162
	.4byte _0807DE38 @ case 163
	.4byte _0807DE38 @ case 164
	.4byte _0807DE38 @ case 165
	.4byte _0807DE38 @ case 166
	.4byte _0807DC9C @ case 167
	.4byte _0807DE38 @ case 168
	.4byte _0807DE38 @ case 169
	.4byte _0807DE38 @ case 170
	.4byte _0807DE38 @ case 171
	.4byte _0807DE38 @ case 172
	.4byte _0807DE38 @ case 173
	.4byte _0807DE38 @ case 174
	.4byte _0807DE38 @ case 175
	.4byte _0807DE38 @ case 176
	.4byte _0807DE38 @ case 177
	.4byte _0807DE38 @ case 178
	.4byte _0807DE38 @ case 179
	.4byte _0807DE38 @ case 180
	.4byte _0807DE38 @ case 181
	.4byte _0807DE38 @ case 182
	.4byte _0807DE38 @ case 183
	.4byte _0807DE38 @ case 184
	.4byte _0807DE38 @ case 185
	.4byte _0807DE38 @ case 186
	.4byte _0807DE38 @ case 187
	.4byte _0807DE38 @ case 188
	.4byte _0807DE38 @ case 189
	.4byte _0807DE38 @ case 190
	.4byte _0807DE38 @ case 191
	.4byte _0807DE38 @ case 192
	.4byte _0807DE38 @ case 193
	.4byte _0807DE38 @ case 194
	.4byte _0807DE38 @ case 195
	.4byte _0807DE38 @ case 196
	.4byte _0807DE38 @ case 197
	.4byte _0807DE38 @ case 198
	.4byte _0807DE38 @ case 199
	.4byte _0807D294 @ case 200
	.4byte _0807DE38 @ case 201
	.4byte _0807DE38 @ case 202
	.4byte _0807DE38 @ case 203
	.4byte _0807DE38 @ case 204
	.4byte _0807DE38 @ case 205
	.4byte _0807DE38 @ case 206
	.4byte _0807DE38 @ case 207
	.4byte _0807DE38 @ case 208
	.4byte _0807DE38 @ case 209
	.4byte _0807DE38 @ case 210
	.4byte _0807DE38 @ case 211
	.4byte _0807DE38 @ case 212
	.4byte _0807DE38 @ case 213
	.4byte _0807DE38 @ case 214
	.4byte _0807DE38 @ case 215
	.4byte _0807DE38 @ case 216
	.4byte _0807DE38 @ case 217
	.4byte _0807DE38 @ case 218
	.4byte _0807DE38 @ case 219
	.4byte _0807DE38 @ case 220
	.4byte _0807DE38 @ case 221
	.4byte _0807DE38 @ case 222
	.4byte _0807DE38 @ case 223
	.4byte _0807DE38 @ case 224
	.4byte _0807DE38 @ case 225
	.4byte _0807DE38 @ case 226
	.4byte _0807DE38 @ case 227
	.4byte _0807DE38 @ case 228
	.4byte _0807DE38 @ case 229
	.4byte _0807DE38 @ case 230
	.4byte _0807DE38 @ case 231
	.4byte _0807DE38 @ case 232
	.4byte _0807DE38 @ case 233
	.4byte _0807DE38 @ case 234
	.4byte _0807DE38 @ case 235
	.4byte _0807DE38 @ case 236
	.4byte _0807DE38 @ case 237
	.4byte _0807DE38 @ case 238
	.4byte _0807DE38 @ case 239
	.4byte _0807DE38 @ case 240
	.4byte _0807DE38 @ case 241
	.4byte _0807DE38 @ case 242
	.4byte _0807DE38 @ case 243
	.4byte _0807DE38 @ case 244
	.4byte _0807DE38 @ case 245
	.4byte _0807DE38 @ case 246
	.4byte _0807DE38 @ case 247
	.4byte _0807DE38 @ case 248
	.4byte _0807DE38 @ case 249
	.4byte _0807DE38 @ case 250
	.4byte _0807DE38 @ case 251
	.4byte _0807DE38 @ case 252
	.4byte _0807DE38 @ case 253
	.4byte _0807DE38 @ case 254
	.4byte _0807DE38 @ case 255
	.4byte _0807DE38 @ case 256
	.4byte _0807DE38 @ case 257
	.4byte _0807DE38 @ case 258
	.4byte _0807DE38 @ case 259
	.4byte _0807DE38 @ case 260
	.4byte _0807DE38 @ case 261
	.4byte _0807DE38 @ case 262
	.4byte _0807DE38 @ case 263
	.4byte _0807DE38 @ case 264
	.4byte _0807DE38 @ case 265
	.4byte _0807DE38 @ case 266
	.4byte _0807DCBC @ case 267
_0807CE60:
	ldr r3, _0807CEC8
	ldr r0, [r7]
	adds r0, #0x8e
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
	ldr r4, [r7]
	adds r2, r4, #0
	adds r2, #0x8e
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, _0807CECC
	strh r1, [r0, #0x24]
	ldrb r0, [r2]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r2, _0807CED0
	adds r0, r4, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	strh r0, [r1, #0x26]
	adds r1, r4, #0
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl GetCurrentMapMusic
	ldr r1, [r7]
	adds r1, #0xf4
	strh r0, [r1]
	ldr r0, _0807CED4
	bl PlayNewMapMusic
	bl _0807DE38
	.align 2, 0
_0807CEC8: .4byte 0x020205AC
_0807CECC: .4byte 0x0000FF4C
_0807CED0: .4byte 0x082D45C8
_0807CED4: .4byte 0x00000179
_0807CED8:
	ldr r5, [r7]
	adds r6, r5, #0
	adds r6, #0xe6
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	ble _0807CF0C
	ldr r2, _0807CF08
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x24]
	adds r1, #3
	strh r1, [r0, #0x24]
	ldrh r0, [r6]
	subs r0, #3
	strh r0, [r6]
	bl _0807DE38
	.align 2, 0
_0807CF08: .4byte 0x020205AC
_0807CF0C:
	ldr r2, _0807CF30
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #0
	strh r1, [r0, #0x24]
	strh r1, [r6]
	adds r1, r5, #0
	adds r1, #0x94
	movs r0, #0xa
	strh r0, [r1]
	bl _0807DE38
	.align 2, 0
_0807CF30: .4byte 0x020205AC
_0807CF34:
	ldr r4, _0807CF70
	ldr r1, _0807CF74
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	ldr r4, _0807CF78
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0xf0
	ldrh r1, [r2]
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807CF62
	adds r0, r1, #0
	movs r1, #0
	bl PlayCry1
_0807CF62:
	ldr r3, [r4]
	adds r1, r3, #0
	adds r1, #0x94
	movs r2, #0
	movs r0, #0xb
	bl _0807DC8A
	.align 2, 0
_0807CF70: .4byte 0x02021C7C
_0807CF74: .4byte 0x0830D240
_0807CF78: .4byte 0x02031F40
_0807CF7C:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x50
	beq _0807CF8C
	bl _0807DE38
_0807CF8C:
	adds r0, r1, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	ldr r2, _0807CFE0
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1, #5]
	lsrs r1, r1, #4
	movs r2, #2
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0x14
	str r2, [sp, #8]
	ldr r2, _0807CFE4
	str r2, [sp, #0xc]
	movs r2, #0x78
	movs r3, #0x20
	bl sub_08076124
	ldr r1, [r7]
	adds r1, #0xd2
	strb r0, [r1]
	ldr r1, [r7]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r4, _0807CFE8
	ldr r1, _0807CFEC
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	bl _0807DE38
	.align 2, 0
_0807CFE0: .4byte 0x020205AC
_0807CFE4: .4byte 0x000FFFFF
_0807CFE8: .4byte 0x02021C7C
_0807CFEC: .4byte 0x0830D24F
_0807CFF0:
	ldr r5, _0807D04C
	ldr r0, [r7]
	adds r0, #0xd2
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r0, r4
	ldr r1, [r0]
	ldr r0, _0807D050
	cmp r1, r0
	beq _0807D010
	bl _0807DE38
_0807D010:
	ldr r0, _0807D054
	movs r1, #0x78
	movs r2, #0x20
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0xd3
	strb r0, [r1]
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, _0807D058
	str r1, [r0]
	adds r2, #0xd2
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	bl DestroySprite
	ldr r1, [r7]
	bl _0807DDD0
	.align 2, 0
_0807D04C: .4byte 0x020205AC
_0807D050: .4byte 0x08007141
_0807D054: .4byte 0x0830CF6C
_0807D058: .4byte 0x0807E011
_0807D05C:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0807D07C
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x14
	strh r1, [r0]
	bl _0807DE38
	.align 2, 0
_0807D07C: .4byte 0x02031F40
_0807D080:
	ldr r0, _0807D0AC
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807D090
	bl _0807DE38
_0807D090:
	movs r0, #4
	bl sub_0807B064
	movs r0, #0
	movs r1, #0xff
	bl FillWindowPixelBuffer
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	bl _0807DDCC
	.align 2, 0
_0807D0AC: .4byte 0x02037C74
_0807D0B0:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0x10
	movs r3, #0
	bl _0807DDC8
_0807D0C2:
	ldr r0, _0807D0E0
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807D0D2
	bl _0807DE38
_0807D0D2:
	ldr r0, [r7]
	adds r0, #0x94
	movs r1, #0x17
	strh r1, [r0]
	bl _0807DE38
	.align 2, 0
_0807D0E0: .4byte 0x02037C74
_0807D0E4:
	ldr r4, _0807D100
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0xea
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _0807D104
	adds r0, r1, #0
	subs r0, #0x34
	strh r0, [r2]
	b _0807D11E
	.align 2, 0
_0807D100: .4byte 0x02031F40
_0807D104:
	movs r0, #1
	bl sub_0807B064
	ldr r3, [r4]
	adds r1, r3, #0
	adds r1, #0xea
	movs r2, #0
	movs r0, #0x80
	strh r0, [r1]
	subs r1, #0x56
	movs r0, #0x7c
	strh r0, [r1]
	str r2, [r3, #0x64]
_0807D11E:
	ldr r0, _0807D128
	ldr r4, [r0]
	bl _0807D9E0
	.align 2, 0
_0807D128: .4byte 0x02031F40
_0807D12C:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x14
	bhi _0807D13C
	bl _0807DE38
_0807D13C:
	movs r0, #3
	bl sub_0807B064
	ldr r0, _0807D15C
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0x91
	strb r0, [r1]
	ldr r1, [r7]
	bl _0807DDD0
	.align 2, 0
_0807D15C: .4byte 0x0830D0D0
_0807D160:
	ldr r2, _0807D1A8
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	cmp r0, #0
	blt _0807D180
	bl _0807DE38
_0807D180:
	adds r0, r1, #0
	bl DestroySprite
	ldr r1, _0807D1AC
	movs r0, #0x50
	bl SetGpuReg
	movs r1, #0x82
	lsls r1, r1, #3
	movs r0, #0x52
	bl SetGpuReg
	ldr r0, _0807D1B0
	movs r1, #5
	bl CreateTask
	ldr r1, [r7]
	bl _0807DDD0
	.align 2, 0
_0807D1A8: .4byte 0x020205AC
_0807D1AC: .4byte 0x00000452
_0807D1B0: .4byte 0x0807EC49
_0807D1B4:
	ldr r0, _0807D1D4
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807D1C4
	bl _0807DE38
_0807D1C4:
	ldr r0, _0807D1D8
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x1a
	strh r1, [r0]
	bl _0807DE38
	.align 2, 0
_0807D1D4: .4byte 0x0807EC49
_0807D1D8: .4byte 0x02031F40
_0807D1DC:
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0xe0
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x9e
	lsls r0, r0, #0x11
	cmp r1, r0
	beq _0807D1F6
	bl _0807DE38
_0807D1F6:
	adds r1, r2, #0
	bl _0807DDD0
_0807D1FC:
	ldr r0, _0807D254
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #3
	bl CreateSprite
	ldr r4, _0807D258
	ldr r1, [r4]
	adds r1, #0x90
	strb r0, [r1]
	ldr r5, _0807D25C
	ldr r0, [r4]
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _0807D260
	str r1, [r0]
	ldr r0, _0807D264
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, #0x91
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #1
	bl StartSpriteAnim
	ldr r1, [r4]
	bl _0807DDD0
	.align 2, 0
_0807D254: .4byte 0x0830CFCC
_0807D258: .4byte 0x02031F40
_0807D25C: .4byte 0x020205AC
_0807D260: .4byte 0x0807A4BD
_0807D264: .4byte 0x0830D00C
_0807D268:
	ldr r2, [r7]
	adds r1, r2, #0
	adds r1, #0xe0
	ldrh r0, [r1]
	subs r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa6
	bne _0807D282
	subs r1, #0x4c
	movs r0, #0xc8
	strh r0, [r1]
_0807D282:
	ldr r1, _0807D290
	movs r0, #0
	bl SetGpuReg
	bl _0807DE38
	.align 2, 0
_0807D290: .4byte 0x00001241
_0807D294:
	ldr r2, _0807D2E8
	ldr r4, [r7]
	adds r3, r4, #0
	adds r3, #0x90
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x22]
	subs r1, #2
	strh r1, [r0, #0x22]
	adds r0, r4, #0
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x22]
	subs r1, #2
	strh r1, [r0, #0x22]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r2, #0x22
	ldrsh r1, [r0, r2]
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0807D2DA
	bl _0807DE38
_0807D2DA:
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0x1d
	strh r0, [r1]
	bl _0807DE38
	.align 2, 0
_0807D2E8: .4byte 0x020205AC
_0807D2EC:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0807D30C
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x1e
	strh r1, [r0]
	bl _0807DE38
	.align 2, 0
_0807D30C: .4byte 0x02031F40
_0807D310:
	ldr r0, _0807D354
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807D320
	bl _0807DE38
_0807D320:
	ldr r0, [r7]
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0807D358
	adds r0, r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	movs r0, #2
	bl sub_0807B064
	ldr r1, [r7]
	bl _0807DDD0
	.align 2, 0
_0807D354: .4byte 0x02037C74
_0807D358: .4byte 0x020205AC
_0807D35C:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	ldr r5, _0807D3A0
	adds r0, r5, #0
	movs r1, #0x6f
	movs r2, #0xaa
	movs r3, #0
	bl CreateSprite
	ldr r4, _0807D3A4
	ldr r1, [r4]
	adds r1, #0x90
	strb r0, [r1]
	movs r2, #0xa
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0x81
	movs r3, #0
	bl CreateSprite
	ldr r1, [r4]
	adds r1, #0x91
	strb r0, [r1]
	ldr r1, [r4]
	bl _0807DDD0
	.align 2, 0
_0807D3A0: .4byte 0x0830D00C
_0807D3A4: .4byte 0x02031F40
_0807D3A8:
	ldr r0, _0807D3F8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807D3C6
	movs r0, #0x2e
	bl PlaySE
	ldr r0, _0807D3FC
	ldr r1, [r0]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807D3C6:
	ldr r3, _0807D400
	ldr r0, _0807D3FC
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r1, [r0, #0x26]
	subs r1, #3
	strh r1, [r0, #0x26]
	adds r2, #0x91
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	bl _0807DE38
	.align 2, 0
_0807D3F8: .4byte 0x02037C74
_0807D3FC: .4byte 0x02031F40
_0807D400: .4byte 0x020205AC
_0807D404:
	ldr r5, _0807D468
	ldr r4, [r7]
	adds r2, r4, #0
	adds r2, #0x90
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r1, [r0, #0x26]
	subs r1, #3
	strh r1, [r0, #0x26]
	adds r6, r4, #0
	adds r6, #0x91
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r3, r0, r5
	movs r0, #0x26
	ldrsh r1, [r3, r0]
	movs r0, #0x5a
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0807D44A
	bl _0807DE38
_0807D44A:
	movs r2, #1
	strh r2, [r3, #0x30]
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	strh r2, [r0, #0x30]
	adds r1, r4, #0
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _0807D46C
	b _0807D692
	.align 2, 0
_0807D468: .4byte 0x020205AC
_0807D46C: .4byte 0x0807ED1D
_0807D470:
	ldr r2, _0807D480
	movs r0, #8
	movs r1, #0x10
	bl BlendPalettes
	bl _0807DDCC
	.align 2, 0
_0807D480: .4byte 0x0000FFFF
_0807D484:
	ldr r2, _0807D494
	movs r0, #8
	movs r1, #0x10
	bl BlendPalettes
	bl _0807DDCC
	.align 2, 0
_0807D494: .4byte 0x0000FFFF
_0807D498:
	ldr r2, _0807D4A8
	movs r0, #8
	movs r1, #0x10
	bl BlendPalettes
	bl _0807DDCC
	.align 2, 0
_0807D4A8: .4byte 0x0000FFFF
_0807D4AC:
	ldr r5, _0807D518
	ldr r0, [r5]
	adds r0, #0xf0
	ldrh r0, [r0]
	bl IsMonSpriteNotFlipped
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807D524
	ldr r4, _0807D51C
	ldr r2, [r5]
	adds r2, #0x8e
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _0807D520
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r1, [r0, #1]
	movs r2, #3
	orrs r1, r2
	strb r1, [r0, #1]
	ldr r0, [r5]
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0
	movs r2, #3
	movs r3, #3
	bl CalcCenterToCornerVec
	ldr r0, [r5]
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0
	bl StartSpriteAffineAnim
	b _0807D53A
	.align 2, 0
_0807D518: .4byte 0x02031F40
_0807D51C: .4byte 0x020205AC
_0807D520: .4byte 0x0830D110
_0807D524:
	ldr r0, [r5]
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0807D5C8
	adds r0, r0, r1
	movs r1, #0
	bl StartSpriteAffineAnim
_0807D53A:
	ldr r5, _0807D5CC
	ldr r0, [r5]
	adds r0, #0x8f
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0807D5C8
	adds r0, r0, r4
	movs r1, #0
	bl StartSpriteAffineAnim
	ldr r2, [r5]
	adds r3, r2, #0
	adds r3, #0x8e
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0x28
	strh r1, [r0, #0x20]
	adds r2, #0x8f
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0xc8
	strh r1, [r0, #0x20]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0xc0
	strh r1, [r0, #0x22]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r1, _0807D5D0
	strh r1, [r0, #0x22]
	ldrb r0, [r3]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, #0x3e
	ldrb r3, [r1]
	movs r2, #5
	rsbs r2, r2, #0
	adds r0, r2, #0
	ands r0, r3
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #0x8f
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x3e
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	ldr r1, [r5]
	bl _0807DDD0
	.align 2, 0
_0807D5C8: .4byte 0x020205AC
_0807D5CC: .4byte 0x02031F40
_0807D5D0: .4byte 0x0000FFE0
_0807D5D4:
	ldr r4, _0807D69C
	ldr r2, [r7]
	adds r3, r2, #0
	adds r3, #0x8e
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x26]
	subs r1, #3
	movs r5, #0
	strh r1, [r0, #0x26]
	adds r2, #0x8f
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r0, [r0, #0x26]
	adds r0, #0xa3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0807D61C
	movs r0, #0x2d
	bl PlaySE
_0807D61C:
	ldr r2, [r7]
	adds r3, r2, #0
	adds r3, #0x8e
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r6, #0x26
	ldrsh r1, [r0, r6]
	movs r0, #0xde
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0807D63C
	bl _0807DE38
_0807D63C:
	adds r0, r2, #0
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r5, [r0, #0x30]
	adds r0, r2, #0
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r5, [r0, #0x30]
	adds r1, r2, #0
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	ldr r0, [r7]
	adds r0, #0x8f
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldr r0, _0807D6A0
_0807D692:
	movs r1, #5
	bl CreateTask
	b _0807DE38
	.align 2, 0
_0807D69C: .4byte 0x020205AC
_0807D6A0: .4byte 0x0807EDD5
_0807D6A4:
	ldr r4, _0807D728
	ldr r2, [r7]
	adds r3, r2, #0
	adds r3, #0x90
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x26]
	subs r1, #3
	strh r1, [r0, #0x26]
	adds r2, #0x91
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x26]
	adds r1, #3
	strh r1, [r0, #0x26]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r2, #0x26
	ldrsh r1, [r0, r2]
	movs r0, #0xde
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0807D6E6
	b _0807DE38
_0807D6E6:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r1, [r7]
	adds r2, r1, #0
	adds r2, #0x94
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r1, #0x90
	ldrb r1, [r1]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	b _0807DE38
	.align 2, 0
_0807D728: .4byte 0x020205AC
_0807D72C:
	ldr r0, _0807D7B8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807D73A
	b _0807DE38
_0807D73A:
	ldr r1, [r7]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #1
	bl sub_0807B064
	ldr r0, [r7]
	adds r0, #0xe0
	movs r1, #0xa6
	strh r1, [r0]
	movs r0, #3
	bl sub_0807B064
	ldr r0, [r7]
	adds r0, #0xe4
	movs r1, #0xce
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r0, _0807D7BC
	movs r4, #0x14
	rsbs r4, r4, #0
	movs r1, #0x78
	adds r2, r4, #0
	movs r3, #3
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0x90
	strb r0, [r1]
	ldr r5, _0807D7C0
	ldr r0, [r7]
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _0807D7C4
	str r1, [r0]
	ldr r0, _0807D7C8
	movs r1, #0x78
	adds r2, r4, #0
	movs r3, #0
	bl CreateSprite
	ldr r1, [r7]
	adds r1, #0x91
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #1
	bl StartSpriteAnim
	b _0807DE38
	.align 2, 0
_0807D7B8: .4byte 0x02037C74
_0807D7BC: .4byte 0x0830CFCC
_0807D7C0: .4byte 0x020205AC
_0807D7C4: .4byte 0x0807A4BD
_0807D7C8: .4byte 0x0830D00C
_0807D7CC:
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0x10
	movs r3, #0
	b _0807DDC8
_0807D7DC:
	movs r1, #0x92
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r0, _0807D7F8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807D7F4
	b _0807DE38
_0807D7F4:
	b _0807DDCC
	.align 2, 0
_0807D7F8: .4byte 0x02037C74
_0807D7FC:
	ldr r2, _0807D850
	ldr r4, [r7]
	adds r3, r4, #0
	adds r3, #0x90
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x26]
	adds r1, #4
	strh r1, [r0, #0x26]
	adds r0, r4, #0
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x26]
	adds r1, #4
	strh r1, [r0, #0x26]
	ldrb r1, [r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r6, #0x26
	ldrsh r1, [r0, r6]
	movs r2, #0x22
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	cmp r1, #0x40
	beq _0807D842
	b _0807DE38
_0807D842:
	adds r0, r4, #0
	adds r0, #0x94
	movs r1, #0x90
	strh r1, [r0]
	movs r0, #0
	str r0, [r4, #0x64]
	b _0807DE38
	.align 2, 0
_0807D850: .4byte 0x020205AC
_0807D854:
	movs r1, #0xb2
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r4, _0807D8B0
	ldr r2, [r4]
	adds r1, r2, #0
	adds r1, #0xe0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r0, [r2, #0x64]
	adds r0, #1
	str r0, [r2, #0x64]
	cmp r0, #0xa
	bne _0807D898
	ldr r0, _0807D8B4
	movs r1, #5
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0807D8B8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	movs r0, #1
	strh r0, [r1, #0xc]
_0807D898:
	ldr r1, [r4]
	adds r3, r1, #0
	adds r3, #0xe0
	movs r6, #0
	ldrsh r0, [r3, r6]
	movs r2, #0x9e
	lsls r2, r2, #1
	cmp r0, r2
	bgt _0807D8AC
	b _0807DE38
_0807D8AC:
	strh r2, [r3]
	b _0807DDD0
	.align 2, 0
_0807D8B0: .4byte 0x02031F40
_0807D8B4: .4byte 0x0807EC49
_0807D8B8: .4byte 0x03005B60
_0807D8BC:
	ldr r0, [r7]
	adds r0, #0x90
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0807D8F4
	adds r0, r0, r4
	bl DestroySprite
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	ldr r3, [r7]
	adds r2, r3, #0
	adds r2, #0x94
	ldrh r0, [r2]
	adds r0, #1
	movs r1, #0
	strh r0, [r2]
	str r1, [r3, #0x64]
	b _0807DE38
	.align 2, 0
_0807D8F4: .4byte 0x020205AC
_0807D8F8:
	ldr r0, _0807D918
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0807D908
	b _0807DE38
_0807D908:
	ldr r0, _0807D91C
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x94
	movs r0, #0x2e
	strh r0, [r1]
	str r3, [r2, #0x64]
	b _0807DE38
	.align 2, 0
_0807D918: .4byte 0x0807EC49
_0807D91C: .4byte 0x02031F40
_0807D920:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0xa
	beq _0807D92E
	b _0807DE38
_0807D92E:
	b _0807DDD0
_0807D930:
	ldr r1, [r7]
	adds r5, r1, #0
	adds r5, #0xe0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r6, #0xae
	lsls r6, r6, #1
	cmp r0, r6
	bgt _0807D94A
	b _0807DE38
_0807D94A:
	strh r6, [r5]
	b _0807DDD0
_0807D94E:
	ldr r0, _0807D96C
	movs r1, #0x78
	movs r2, #0x50
	movs r3, #0
	bl CreateSprite
	ldr r2, _0807D970
	ldr r1, [r2]
	adds r1, #0x91
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, #0x94
	movs r1, #0x32
	strh r1, [r0]
	b _0807DE38
	.align 2, 0
_0807D96C: .4byte 0x0830D0B8
_0807D970: .4byte 0x02031F40
_0807D974:
	ldr r2, _0807D9B0
	ldr r0, [r7]
	adds r0, #0x91
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	cmp r0, #0
	blt _0807D992
	b _0807DE38
_0807D992:
	adds r0, r1, #0
	bl DestroySprite
	movs r0, #6
	bl sub_0807B064
	ldr r1, [r7]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0x9f
	bl PlaySE
	b _0807DE38
	.align 2, 0
_0807D9B0: .4byte 0x020205AC
_0807D9B4:
	ldr r1, [r7]
	adds r2, r1, #0
	adds r2, #0xea
	ldrh r3, [r2]
	ldr r0, _0807D9CC
	cmp r3, r0
	bhi _0807D9D0
	adds r0, r3, #0
	adds r0, #0x34
	strh r0, [r2]
	b _0807D9DE
	.align 2, 0
_0807D9CC: .4byte 0x000003FF
_0807D9D0:
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r2]
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0807D9DE:
	ldr r4, [r7]
_0807D9E0:
	adds r0, r4, #0
	adds r0, #0xea
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	bl __divsi3
	adds r4, #0xe8
	strh r0, [r4]
	b _0807DE38
_0807D9F4:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0807DA10
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x3c
	strh r1, [r0]
	b _0807DE38
	.align 2, 0
_0807DA10: .4byte 0x02031F40
_0807DA14:
	ldr r4, _0807DA38
	ldrb r1, [r4, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807DA22
	b _0807DE38
_0807DA22:
	movs r0, #5
	bl sub_0807B064
	movs r0, #7
	bl sub_0807B064
	ldrb r0, [r4, #8]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r4, #8]
	b _0807DDCC
	.align 2, 0
_0807DA38: .4byte 0x02037C74
_0807DA3C:
	ldr r2, _0807DA54
	ldrb r1, [r2, #8]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #8]
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0x10
	movs r3, #0
	b _0807DDC8
	.align 2, 0
_0807DA54: .4byte 0x02037C74
_0807DA58:
	movs r1, #0xa2
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r0, _0807DA74
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0807DA70
	b _0807DE38
_0807DA70:
	b _0807DDCC
	.align 2, 0
_0807DA74: .4byte 0x02037C74
_0807DA78:
	ldr r0, _0807DB0C
	movs r2, #8
	rsbs r2, r2, #0
	movs r1, #0x78
	movs r3, #0
	bl CreateSprite
	ldr r5, _0807DB10
	ldr r1, [r5]
	adds r1, #0xd3
	movs r6, #0
	strb r0, [r1]
	ldr r4, _0807DB14
	ldr r2, [r5]
	adds r2, #0xd3
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0x4a
	strh r1, [r0, #0x34]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _0807DB18
	str r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #1
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #2
	bl StartSpriteAffineAnim
	ldr r0, [r5]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r1, [r0, #5]
	lsrs r1, r1, #4
	adds r1, #0x10
	movs r0, #1
	lsls r0, r1
	ldr r2, _0807DB1C
	movs r1, #0x10
	bl BlendPalettes
	ldr r2, [r5]
	adds r1, r2, #0
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	str r6, [r2, #0x64]
	b _0807DE38
	.align 2, 0
_0807DB0C: .4byte 0x0830CF6C
_0807DB10: .4byte 0x02031F40
_0807DB14: .4byte 0x020205AC
_0807DB18: .4byte 0x0807E0E5
_0807DB1C: .4byte 0x0000FFFF
_0807DB20:
	ldr r2, _0807DB4C
	ldr r0, [r7]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0, #5]
	lsrs r1, r1, #4
	adds r1, #0x10
	movs r0, #1
	lsls r0, r1
	ldr r1, _0807DB50
	str r1, [sp]
	movs r1, #1
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	ldr r1, [r7]
	b _0807DDD0
	.align 2, 0
_0807DB4C: .4byte 0x020205AC
_0807DB50: .4byte 0x0000FFFF
_0807DB54:
	ldr r2, _0807DB90
	ldr r3, [r7]
	adds r0, r3, #0
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #0x1c
	adds r0, r0, r2
	ldr r1, [r0]
	ldr r0, _0807DB94
	cmp r1, r0
	beq _0807DB72
	b _0807DE38
_0807DB72:
	adds r0, r3, #0
	adds r0, #0xf2
	ldrh r2, [r0]
	lsls r0, r2, #3
	ldr r1, _0807DB98
	adds r0, r0, r1
	ldr r1, _0807DB9C
	ldr r1, [r1]
	ldr r1, [r1, #0x10]
	ldr r3, [r3, #0x6c]
	bl HandleLoadSpecialPokePic_2
	ldr r1, [r7]
	b _0807DDD0
	.align 2, 0
_0807DB90: .4byte 0x020205AC
_0807DB94: .4byte 0x08007141
_0807DB98: .4byte 0x082DDA1C
_0807DB9C: .4byte 0x02024178
_0807DBA0:
	ldr r4, _0807DC54
	ldr r2, [r7]
	adds r6, r2, #0
	adds r6, #0x8f
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r5, #0
	movs r1, #0x78
	strh r1, [r0, #0x20]
	ldrb r0, [r6]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r3, _0807DC58
	adds r2, #0xf2
	ldrh r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #1]
	adds r0, #0x3c
	strh r0, [r1, #0x22]
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r5, [r0, #0x24]
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r5, [r0, #0x26]
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #0
	bl StartSpriteAnim
	ldr r3, [r7]
	adds r0, r3, #0
	adds r0, #0x8f
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r1, [r1, #5]
	lsrs r1, r1, #4
	movs r2, #2
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0x14
	str r2, [sp, #8]
	ldr r2, _0807DC5C
	str r2, [sp, #0xc]
	adds r3, #0xf2
	ldrh r2, [r3]
	str r2, [sp, #0x10]
	movs r2, #0x78
	movs r3, #0x54
	bl CreatePokeballSpriteToReleaseMon
	ldr r0, [r7]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl FreeSpriteOamMatrix
	ldr r0, [r7]
	adds r0, #0xd3
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	ldr r1, [r7]
	b _0807DDD0
	.align 2, 0
_0807DC54: .4byte 0x020205AC
_0807DC58: .4byte 0x082D45C8
_0807DC5C: .4byte 0x000FFFFF
_0807DC60:
	movs r1, #0xaa
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r4, _0807DC90
	ldr r1, _0807DC94
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	ldr r0, _0807DC98
	ldr r3, [r0]
	adds r1, r3, #0
	adds r1, #0x94
	movs r2, #0
	movs r0, #0xa7
_0807DC8A:
	strh r0, [r1]
	str r2, [r3, #0x64]
	b _0807DE38
	.align 2, 0
_0807DC90: .4byte 0x02021C7C
_0807DC94: .4byte 0x0830D258
_0807DC98: .4byte 0x02031F40
_0807DC9C:
	ldr r3, [r7]
	ldr r0, [r3, #0x64]
	adds r0, #1
	str r0, [r3, #0x64]
	cmp r0, #0x3c
	bhi _0807DCAA
	b _0807DE38
_0807DCAA:
	adds r0, r3, #0
	adds r0, #0x94
	movs r2, #0
	ldr r1, _0807DCB8
	strh r1, [r0]
	str r2, [r3, #0x64]
	b _0807DE38
	.align 2, 0
_0807DCB8: .4byte 0x0000010B
_0807DCBC:
	bl IsCryFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807DCC8
	b _0807DE38
_0807DCC8:
	ldr r0, _0807DCD4
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0x44
	strh r1, [r0]
	b _0807DE38
	.align 2, 0
_0807DCD4: .4byte 0x02031F40
_0807DCD8:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0xa
	bne _0807DCEA
	ldr r0, _0807DD18
	bl PlayFanfare
_0807DCEA:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	cmp r0, #0xfa
	beq _0807DCF4
	b _0807DE38
_0807DCF4:
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	ldr r4, _0807DD1C
	ldr r1, _0807DD20
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	ldr r0, [r7]
	str r5, [r0, #0x64]
	b _0807DE38
	.align 2, 0
_0807DD18: .4byte 0x00000173
_0807DD1C: .4byte 0x02021C7C
_0807DD20: .4byte 0x0830D26A
_0807DD24:
	ldr r1, [r7]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x3c
	beq _0807DD32
	b _0807DE38
_0807DD32:
	b _0807DDD0
_0807DD34:
	bl sub_0807EB84
	b _0807DDCC
_0807DD3A:
	ldr r2, [r7]
	adds r0, r2, #0
	adds r0, #0xee
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807DD4A
	movs r0, #1
	b _0807DE3A
_0807DD4A:
	ldr r0, _0807DD5C
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0807DE38
	adds r1, r2, #0
	b _0807DDD0
	.align 2, 0
_0807DD5C: .4byte 0x03002360
_0807DD60:
	ldr r0, _0807DDA4
	ldrb r0, [r0]
	movs r1, #0
	bl sub_0807AF08
	ldr r1, _0807DDA8
	ldr r0, _0807DDAC
	str r0, [r1]
	ldr r7, _0807DDB0
	ldrb r0, [r7]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _0807DDB4
	adds r0, r0, r5
	movs r1, #1
	movs r2, #0
	bl GetEvolutionTargetSpecies
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0807DDCC
	ldrb r3, [r7]
	adds r0, r3, #0
	muls r0, r6, r0
	adds r0, r0, r5
	ldr r1, _0807DDB8
	ldr r1, [r1]
	adds r1, #0x8f
	ldrb r2, [r1]
	adds r1, r4, #0
	bl TradeEvolutionScene
	b _0807DDCC
	.align 2, 0
_0807DDA4: .4byte 0x02037282
_0807DDA8: .4byte 0x03005F28
_0807DDAC: .4byte 0x0807B045
_0807DDB0: .4byte 0x02031F38
_0807DDB4: .4byte 0x02024190
_0807DDB8: .4byte 0x02031F40
_0807DDBC:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
_0807DDC8:
	bl BeginNormalPaletteFade
_0807DDCC:
	ldr r0, _0807DDDC
	ldr r1, [r0]
_0807DDD0:
	adds r1, #0x94
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0807DE38
	.align 2, 0
_0807DDDC: .4byte 0x02031F40
_0807DDE0:
	ldr r0, _0807DE44
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0807DE38
	ldr r0, [r7]
	adds r0, #0xf4
	ldrh r0, [r0]
	bl PlayNewMapMusic
	ldr r0, [r7]
	cmp r0, #0
	beq _0807DE2E
	bl FreeAllWindowBuffers
	movs r0, #3
	bl GetBgTilemapBuffer
	bl Free
	movs r0, #1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, #0
	bl GetBgTilemapBuffer
	bl Free
	bl FreeMonSpritesGfx
	ldr r0, [r7]
	bl Free
	str r4, [r7]
_0807DE2E:
	ldr r0, _0807DE48
	bl SetMainCallback2
	bl sub_0807E1C4
_0807DE38:
	movs r0, #0
_0807DE3A:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0807DE44: .4byte 0x02037C74
_0807DE48: .4byte 0x08085A31
	thumb_func_end sub_0807CA00

	thumb_func_start c2_08053788
c2_08053788: @ 0x0807DE4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0807DE68
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0807DE6C
	cmp r0, #4
	beq _0807DE7C
	b _0807DEEC
	.align 2, 0
_0807DE68: .4byte 0x03002360
_0807DE6C:
	movs r0, #4
	strb r0, [r1]
	ldr r1, _0807DE78
	movs r0, #1
	b _0807DEEA
	.align 2, 0
_0807DE78: .4byte 0x030027A0
_0807DE7C:
	ldr r0, _0807DEB8
	ldr r1, _0807DEBC
	mov r8, r1
	str r1, [r0]
	ldr r7, _0807DEC0
	ldrb r0, [r7]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _0807DEC4
	adds r0, r0, r5
	movs r1, #1
	movs r2, #0
	bl GetEvolutionTargetSpecies
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0807DECC
	ldrb r3, [r7]
	adds r0, r3, #0
	muls r0, r6, r0
	adds r0, r0, r5
	ldr r1, _0807DEC8
	ldr r1, [r1]
	adds r1, #0x8f
	ldrb r2, [r1]
	adds r1, r4, #0
	bl TradeEvolutionScene
	b _0807DEE6
	.align 2, 0
_0807DEB8: .4byte 0x03005F28
_0807DEBC: .4byte 0x0807E589
_0807DEC0: .4byte 0x02031F38
_0807DEC4: .4byte 0x02024190
_0807DEC8: .4byte 0x02031F40
_0807DECC:
	bl sub_08076C68
	cmp r0, #0
	beq _0807DEE0
	ldr r0, _0807DEDC
	bl SetMainCallback2
	b _0807DEE6
	.align 2, 0
_0807DEDC: .4byte 0x0807EE9D
_0807DEE0:
	mov r0, r8
	bl SetMainCallback2
_0807DEE6:
	ldr r1, _0807DF10
	movs r0, #0xff
_0807DEEA:
	strb r0, [r1]
_0807DEEC:
	bl HasLinkErrorOccurred
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807DEFA
	bl RunTasks
_0807DEFA:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807DF10: .4byte 0x02031F38
	thumb_func_end c2_08053788

	thumb_func_start sub_0807DF14
sub_0807DF14: @ 0x0807DF14
	push {r4, r5, r6, lr}
	bl sub_0807A738
	bl GetBlockReceivedStatus
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r6, #1
	adds r0, r5, #0
	ands r0, r6
	cmp r0, #0
	beq _0807DF52
	ldr r4, _0807DF80
	ldrh r1, [r4]
	ldr r0, _0807DF84
	cmp r1, r0
	bne _0807DF3C
	ldr r0, _0807DF88
	bl SetMainCallback2
_0807DF3C:
	ldrh r1, [r4]
	ldr r0, _0807DF8C
	cmp r1, r0
	bne _0807DF4C
	ldr r0, _0807DF90
	ldr r0, [r0]
	adds r0, #0x72
	strb r6, [r0]
_0807DF4C:
	movs r0, #0
	bl ResetBlockReceivedFlag
_0807DF52:
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq _0807DF7A
	ldr r0, _0807DF80
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _0807DF8C
	cmp r1, r0
	bne _0807DF74
	ldr r0, _0807DF90
	ldr r0, [r0]
	adds r0, #0x73
	movs r1, #1
	strb r1, [r0]
_0807DF74:
	movs r0, #1
	bl ResetBlockReceivedFlag
_0807DF7A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807DF80: .4byte 0x0202207C
_0807DF84: .4byte 0x0000DCBA
_0807DF88: .4byte 0x0807DE4D
_0807DF8C: .4byte 0x0000ABCD
_0807DF90: .4byte 0x02031F40
	thumb_func_end sub_0807DF14

	thumb_func_start sub_0807DF94
sub_0807DF94: @ 0x0807DF94
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	ldrh r4, [r5, #0x22]
	adds r4, r4, r0
	strh r4, [r5, #0x22]
	ldrh r0, [r5, #0x30]
	ldrh r2, [r5, #0x38]
	adds r0, r0, r2
	strh r0, [r5, #0x38]
	movs r1, #0x38
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r5, #0x20]
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0x4c
	ble _0807DFE2
	movs r0, #0x4c
	strh r0, [r5, #0x22]
	movs r2, #0x2e
	ldrsh r1, [r5, r2]
	movs r2, #0x32
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	rsbs r0, r0, #0
	movs r1, #0x64
	bl __divsi3
	strh r0, [r5, #0x2e]
	ldrh r0, [r5, #0x34]
	adds r0, #1
	strh r0, [r5, #0x34]
_0807DFE2:
	movs r1, #0x20
	ldrsh r0, [r5, r1]
	cmp r0, #0x78
	bne _0807DFEE
	movs r0, #0
	strh r0, [r5, #0x30]
_0807DFEE:
	ldrh r0, [r5, #0x36]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	strh r0, [r5, #0x2e]
	movs r1, #0x34
	ldrsh r0, [r5, r1]
	cmp r0, #4
	bne _0807E006
	movs r0, #1
	strh r0, [r5, #0x3c]
	ldr r0, _0807E00C
	str r0, [r5, #0x1c]
_0807E006:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807E00C: .4byte 0x08007141
	thumb_func_end sub_0807DF94

	thumb_func_start sub_0807E010
sub_0807E010: @ 0x0807E010
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _0807E078
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	strh r0, [r4, #0x26]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r0, #0x16
	bne _0807E038
	movs r0, #0x38
	bl PlaySE
_0807E038:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x2c
	bne _0807E06E
	movs r0, #0x8c
	bl PlaySE
	ldr r0, _0807E07C
	str r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x2e]
	ldrb r1, [r4, #5]
	lsrs r1, r1, #4
	adds r1, #0x10
	movs r0, #1
	lsls r0, r1
	movs r1, #1
	rsbs r1, r1, #0
	ldr r2, _0807E080
	str r2, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
_0807E06E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E078: .4byte 0x0830D2A4
_0807E07C: .4byte 0x0807E085
_0807E080: .4byte 0x0000FFFF
	thumb_func_end sub_0807E010

	thumb_func_start sub_0807E084
sub_0807E084: @ 0x0807E084
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	cmp r0, #0x14
	bne _0807E098
	adds r0, r4, #0
	movs r1, #1
	bl StartSpriteAffineAnim
_0807E098:
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _0807E0D6
	ldr r1, _0807E0DC
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r4, #0x26]
	subs r0, r0, r1
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x17
	bne _0807E0D6
	adds r0, r4, #0
	bl DestroySprite
	ldr r0, _0807E0E0
	ldr r0, [r0]
	adds r0, #0x94
	movs r1, #0xe
	strh r1, [r0]
_0807E0D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E0DC: .4byte 0x0830D2A4
_0807E0E0: .4byte 0x02031F40
	thumb_func_end sub_0807E084

	thumb_func_start sub_0807E0E4
sub_0807E0E4: @ 0x0807E0E4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r2, [r4, #0x32]
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0807E114
	ldrh r0, [r4, #0x22]
	adds r0, #4
	strh r0, [r4, #0x22]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x34
	ldrsh r1, [r4, r3]
	cmp r0, r1
	ble _0807E164
	adds r0, r2, #1
	strh r0, [r4, #0x32]
	movs r0, #0x16
	strh r0, [r4, #0x2e]
	movs r0, #0x38
	bl PlaySE
	b _0807E164
_0807E114:
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0x42
	bne _0807E122
	movs r0, #0x39
	bl PlaySE
_0807E122:
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r0, #0x5c
	bne _0807E130
	movs r0, #0x3a
	bl PlaySE
_0807E130:
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	cmp r0, #0x6b
	bne _0807E13E
	movs r0, #0x3b
	bl PlaySE
_0807E13E:
	ldr r1, _0807E16C
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r3, [r4, #0x26]
	adds r0, r0, r3
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x6c
	bne _0807E164
	ldr r0, _0807E170
	str r0, [r4, #0x1c]
_0807E164:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E16C: .4byte 0x0830D2A4
_0807E170: .4byte 0x08007141
	thumb_func_end sub_0807E0E4

	thumb_func_start GetInGameTradeSpeciesInfo
GetInGameTradeSpeciesInfo: @ 0x0807E174
	push {r4, r5, lr}
	ldr r0, _0807E1B0
	ldrh r0, [r0]
	lsls r4, r0, #4
	subs r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _0807E1B4
	adds r4, r4, r0
	ldr r0, _0807E1B8
	ldrh r2, [r4, #0x38]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r5, _0807E1BC
	adds r1, r1, r5
	bl StringCopy
	ldr r0, _0807E1C0
	ldrh r2, [r4, #0xc]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r5
	bl StringCopy
	ldrh r0, [r4, #0x38]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807E1B0: .4byte 0x02037280
_0807E1B4: .4byte 0x0830D114
_0807E1B8: .4byte 0x02021C40
_0807E1BC: .4byte 0x082EA31C
_0807E1C0: .4byte 0x02021C54
	thumb_func_end GetInGameTradeSpeciesInfo

	thumb_func_start sub_0807E1C4
sub_0807E1C4: @ 0x0807E1C4
	push {r4, lr}
	sub sp, #0x20
	ldr r0, _0807E20C
	ldrh r0, [r0]
	lsls r4, r0, #4
	subs r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _0807E210
	adds r4, r4, r0
	ldr r0, _0807E214
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _0807E218
	adds r0, r0, r1
	movs r1, #2
	mov r2, sp
	bl GetMonData3
	ldr r0, _0807E21C
	mov r1, sp
	bl StringCopy10
	ldr r0, _0807E220
	ldrh r2, [r4, #0xc]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _0807E224
	adds r1, r1, r2
	bl StringCopy
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E20C: .4byte 0x02037280
_0807E210: .4byte 0x0830D114
_0807E214: .4byte 0x02037282
_0807E218: .4byte 0x02024190
_0807E21C: .4byte 0x02021C40
_0807E220: .4byte 0x02021C54
_0807E224: .4byte 0x082EA31C
	thumb_func_end sub_0807E1C4

	thumb_func_start _CreateInGameTradePokemon
_CreateInGameTradePokemon: @ 0x0807E228
	push {r4, r5, r6, r7, lr}
	sub sp, #0x38
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	ldr r1, _0807E384
	adds r5, r2, r1
	movs r1, #0x64
	muls r0, r1, r0
	ldr r1, _0807E388
	adds r0, r0, r1
	movs r1, #0x38
	bl GetMonData3
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	add r4, sp, #0x34
	movs r0, #0xfe
	strb r0, [r4]
	ldr r6, _0807E38C
	ldrh r1, [r5, #0xc]
	movs r3, #1
	str r3, [sp]
	ldr r0, [r5, #0x24]
	str r0, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [r5, #0x18]
	str r0, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0x20
	bl CreateMon
	adds r2, r5, #0
	adds r2, #0xe
	adds r0, r6, #0
	movs r1, #0x27
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0xf
	adds r0, r6, #0
	movs r1, #0x28
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x10
	adds r0, r6, #0
	movs r1, #0x29
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x11
	adds r0, r6, #0
	movs r1, #0x2a
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x12
	adds r0, r6, #0
	movs r1, #0x2b
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x13
	adds r0, r6, #0
	movs r1, #0x2c
	bl SetMonData
	adds r0, r6, #0
	movs r1, #2
	adds r2, r5, #0
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x2b
	adds r0, r6, #0
	movs r1, #7
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x36
	adds r0, r6, #0
	movs r1, #0x31
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x14
	adds r0, r6, #0
	movs r1, #0x2e
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x1d
	adds r0, r6, #0
	movs r1, #0x17
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x1e
	adds r0, r6, #0
	movs r1, #0x18
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x1c
	adds r0, r6, #0
	movs r1, #0x16
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x1f
	adds r0, r6, #0
	movs r1, #0x21
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x20
	adds r0, r6, #0
	movs r1, #0x2f
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x37
	adds r0, r6, #0
	movs r1, #0x30
	bl SetMonData
	adds r0, r6, #0
	movs r1, #0x23
	adds r2, r4, #0
	bl SetMonData
	mov r4, sp
	adds r4, #0x35
	movs r0, #0
	strb r0, [r4]
	ldrh r0, [r5, #0x28]
	cmp r0, #0
	beq _0807E3A0
	bl ItemIsMail
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0807E394
	add r0, sp, #0x10
	adds r1, r5, #0
	bl sub_0807E3B4
	ldr r0, _0807E390
	add r1, sp, #0x10
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	ldm r1!, {r2, r3, r7}
	stm r0!, {r2, r3, r7}
	adds r0, r6, #0
	movs r1, #0x40
	adds r2, r4, #0
	bl SetMonData
	adds r2, r5, #0
	adds r2, #0x28
	adds r0, r6, #0
	movs r1, #0xc
	bl SetMonData
	b _0807E3A0
	.align 2, 0
_0807E384: .4byte 0x0830D114
_0807E388: .4byte 0x02024190
_0807E38C: .4byte 0x020243E8
_0807E390: .4byte 0x02031E60
_0807E394:
	adds r2, r5, #0
	adds r2, #0x28
	adds r0, r6, #0
	movs r1, #0xc
	bl SetMonData
_0807E3A0:
	ldr r0, _0807E3B0
	bl CalculateMonStats
	add sp, #0x38
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E3B0: .4byte 0x020243E8
	thumb_func_end _CreateInGameTradePokemon

	thumb_func_start sub_0807E3B4
sub_0807E3B4: @ 0x0807E3B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r2, _0807E408
	adds r0, r5, #0
	adds r0, #0x2a
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r0, r2
	adds r1, r4, #0
	movs r3, #8
_0807E3CE:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _0807E3CE
	adds r0, r4, #0
	adds r0, #0x12
	adds r1, r5, #0
	adds r1, #0x2b
	bl StringCopy
	ldr r1, [r5, #0x18]
	lsrs r0, r1, #0x18
	strb r0, [r4, #0x1a]
	lsrs r0, r1, #0x10
	strb r0, [r4, #0x1b]
	lsrs r0, r1, #8
	strb r0, [r4, #0x1c]
	strb r1, [r4, #0x1d]
	ldrh r0, [r5, #0xc]
	strh r0, [r4, #0x1e]
	ldrh r0, [r5, #0x28]
	strh r0, [r4, #0x20]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807E408: .4byte 0x0830D204
	thumb_func_end sub_0807E3B4

	thumb_func_start GetTradeSpecies
GetTradeSpecies: @ 0x0807E40C
	push {r4, r5, r6, lr}
	ldr r6, _0807E438
	ldrh r0, [r6]
	movs r5, #0x64
	muls r0, r5, r0
	ldr r4, _0807E43C
	adds r0, r0, r4
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	bne _0807E440
	ldrh r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r4
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _0807E442
	.align 2, 0
_0807E438: .4byte 0x02037282
_0807E43C: .4byte 0x02024190
_0807E440:
	movs r0, #0
_0807E442:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end GetTradeSpecies

	thumb_func_start CreateInGameTradePokemon
CreateInGameTradePokemon: @ 0x0807E448
	push {lr}
	ldr r0, _0807E45C
	ldrb r0, [r0]
	ldr r1, _0807E460
	ldrb r1, [r1]
	bl _CreateInGameTradePokemon
	pop {r0}
	bx r0
	.align 2, 0
_0807E45C: .4byte 0x02037282
_0807E460: .4byte 0x02037280
	thumb_func_end CreateInGameTradePokemon

	thumb_func_start sub_0807E464
sub_0807E464: @ 0x0807E464
	push {r4, r5, r6, lr}
	bl sub_0807B600
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	bne _0807E4CE
	ldr r5, _0807E4F0
	ldr r0, [r5]
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0807E4F4
	adds r0, r0, r4
	bl DestroySprite
	ldr r0, [r5]
	adds r0, #0x8f
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl FreeSpriteOamMatrix
	ldr r0, _0807E4F8
	ldrb r4, [r0]
	ldrb r0, [r0, #1]
	movs r1, #6
	bl __umodsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_0807AF08
	bl sub_08076C68
	cmp r0, #0
	bne _0807E4C8
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0x74
	ldr r1, _0807E4FC
	strh r1, [r2]
	adds r0, #0x93
	strb r6, [r0]
_0807E4C8:
	ldr r0, _0807E500
	bl SetMainCallback2
_0807E4CE:
	bl sub_0807AFF0
	bl sub_0807DF14
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807E4F0: .4byte 0x02031F40
_0807E4F4: .4byte 0x020205AC
_0807E4F8: .4byte 0x02031F38
_0807E4FC: .4byte 0x0000ABCD
_0807E500: .4byte 0x0807E505
	thumb_func_end sub_0807E464

	thumb_func_start sub_0807E504
sub_0807E504: @ 0x0807E504
	push {r4, lr}
	bl sub_0807A738
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_08076C68
	cmp r0, #0
	beq _0807E524
	ldr r0, _0807E520
	bl SetMainCallback2
	b _0807E564
	.align 2, 0
_0807E520: .4byte 0x0807DE4D
_0807E524:
	bl sub_0807DF14
	cmp r4, #0
	bne _0807E564
	ldr r4, _0807E57C
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x72
	ldrh r1, [r0]
	ldr r0, _0807E580
	cmp r1, r0
	bne _0807E564
	adds r1, r2, #0
	adds r1, #0x74
	ldr r0, _0807E584
	strh r0, [r1]
	bl bitmask_all_link_players_but_self
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r4]
	adds r1, #0x74
	movs r2, #0x14
	bl SendBlock
	ldr r0, [r4]
	adds r0, #0x72
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x73
	strb r1, [r0]
_0807E564:
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E57C: .4byte 0x02031F40
_0807E580: .4byte 0x00000101
_0807E584: .4byte 0x0000DCBA
	thumb_func_end sub_0807E504

	thumb_func_start sub_0807E588
sub_0807E588: @ 0x0807E588
	push {r4, lr}
	sub sp, #4
	ldr r1, _0807E5A8
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x65
	bls _0807E59E
	b _0807EA72
_0807E59E:
	lsls r0, r0, #2
	ldr r1, _0807E5AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807E5A8: .4byte 0x03002360
_0807E5AC: .4byte 0x0807E5B0
_0807E5B0: @ jump table
	.4byte _0807E748 @ case 0
	.4byte _0807E764 @ case 1
	.4byte _0807E7D0 @ case 2
	.4byte _0807EA72 @ case 3
	.4byte _0807E8B0 @ case 4
	.4byte _0807E974 @ case 5
	.4byte _0807E99C @ case 6
	.4byte _0807E9B6 @ case 7
	.4byte _0807E9DC @ case 8
	.4byte _0807EA28 @ case 9
	.4byte _0807EA72 @ case 10
	.4byte _0807EA72 @ case 11
	.4byte _0807EA72 @ case 12
	.4byte _0807EA72 @ case 13
	.4byte _0807EA72 @ case 14
	.4byte _0807EA72 @ case 15
	.4byte _0807EA72 @ case 16
	.4byte _0807EA72 @ case 17
	.4byte _0807EA72 @ case 18
	.4byte _0807EA72 @ case 19
	.4byte _0807EA72 @ case 20
	.4byte _0807EA72 @ case 21
	.4byte _0807EA72 @ case 22
	.4byte _0807EA72 @ case 23
	.4byte _0807EA72 @ case 24
	.4byte _0807EA72 @ case 25
	.4byte _0807EA72 @ case 26
	.4byte _0807EA72 @ case 27
	.4byte _0807EA72 @ case 28
	.4byte _0807EA72 @ case 29
	.4byte _0807EA72 @ case 30
	.4byte _0807EA72 @ case 31
	.4byte _0807EA72 @ case 32
	.4byte _0807EA72 @ case 33
	.4byte _0807EA72 @ case 34
	.4byte _0807EA72 @ case 35
	.4byte _0807EA72 @ case 36
	.4byte _0807EA72 @ case 37
	.4byte _0807EA72 @ case 38
	.4byte _0807EA72 @ case 39
	.4byte _0807E8D4 @ case 40
	.4byte _0807E924 @ case 41
	.4byte _0807E952 @ case 42
	.4byte _0807EA72 @ case 43
	.4byte _0807EA72 @ case 44
	.4byte _0807EA72 @ case 45
	.4byte _0807EA72 @ case 46
	.4byte _0807EA72 @ case 47
	.4byte _0807EA72 @ case 48
	.4byte _0807EA72 @ case 49
	.4byte _0807E7F8 @ case 50
	.4byte _0807E854 @ case 51
	.4byte _0807E870 @ case 52
	.4byte _0807EA72 @ case 53
	.4byte _0807EA72 @ case 54
	.4byte _0807EA72 @ case 55
	.4byte _0807EA72 @ case 56
	.4byte _0807EA72 @ case 57
	.4byte _0807EA72 @ case 58
	.4byte _0807EA72 @ case 59
	.4byte _0807EA72 @ case 60
	.4byte _0807EA72 @ case 61
	.4byte _0807EA72 @ case 62
	.4byte _0807EA72 @ case 63
	.4byte _0807EA72 @ case 64
	.4byte _0807EA72 @ case 65
	.4byte _0807EA72 @ case 66
	.4byte _0807EA72 @ case 67
	.4byte _0807EA72 @ case 68
	.4byte _0807EA72 @ case 69
	.4byte _0807EA72 @ case 70
	.4byte _0807EA72 @ case 71
	.4byte _0807EA72 @ case 72
	.4byte _0807EA72 @ case 73
	.4byte _0807EA72 @ case 74
	.4byte _0807EA72 @ case 75
	.4byte _0807EA72 @ case 76
	.4byte _0807EA72 @ case 77
	.4byte _0807EA72 @ case 78
	.4byte _0807EA72 @ case 79
	.4byte _0807EA72 @ case 80
	.4byte _0807EA72 @ case 81
	.4byte _0807EA72 @ case 82
	.4byte _0807EA72 @ case 83
	.4byte _0807EA72 @ case 84
	.4byte _0807EA72 @ case 85
	.4byte _0807EA72 @ case 86
	.4byte _0807EA72 @ case 87
	.4byte _0807EA72 @ case 88
	.4byte _0807EA72 @ case 89
	.4byte _0807EA72 @ case 90
	.4byte _0807EA72 @ case 91
	.4byte _0807EA72 @ case 92
	.4byte _0807EA72 @ case 93
	.4byte _0807EA72 @ case 94
	.4byte _0807EA72 @ case 95
	.4byte _0807EA72 @ case 96
	.4byte _0807EA72 @ case 97
	.4byte _0807EA72 @ case 98
	.4byte _0807EA72 @ case 99
	.4byte _0807E77C @ case 100
	.4byte _0807E7B4 @ case 101
_0807E748:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r4, _0807E75C
	ldr r1, _0807E760
	b _0807E7DE
	.align 2, 0
_0807E75C: .4byte 0x02021C7C
_0807E760: .4byte 0x08595430
_0807E764:
	movs r0, #0
	bl sub_08076C90
	ldr r0, _0807E778
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x64
	b _0807E8C0
	.align 2, 0
_0807E778: .4byte 0x03002360
_0807E77C:
	ldr r0, _0807E7AC
	ldr r3, [r0]
	ldr r0, [r3, #0x64]
	adds r0, #1
	str r0, [r3, #0x64]
	cmp r0, #0xb4
	bls _0807E798
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r2, #0
	movs r1, #0x65
	strb r1, [r0]
	str r2, [r3, #0x64]
_0807E798:
	bl _IsLinkTaskFinished
	cmp r0, #0
	bne _0807E7A2
	b _0807EA72
_0807E7A2:
	ldr r0, _0807E7B0
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	b _0807E7C6
	.align 2, 0
_0807E7AC: .4byte 0x02031F40
_0807E7B0: .4byte 0x03002360
_0807E7B4:
	bl _IsLinkTaskFinished
	cmp r0, #0
	bne _0807E7BE
	b _0807EA72
_0807E7BE:
	ldr r0, _0807E7CC
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
_0807E7C6:
	movs r1, #2
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E7CC: .4byte 0x03002360
_0807E7D0:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #0x32
	strb r0, [r1]
	ldr r4, _0807E7F0
	ldr r1, _0807E7F4
_0807E7DE:
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	b _0807EA72
	.align 2, 0
_0807E7F0: .4byte 0x02021C7C
_0807E7F4: .4byte 0x08277071
_0807E7F8:
	bl InUnionRoom
	cmp r0, #0
	bne _0807E806
	movs r0, #0x15
	bl IncrementGameStat
_0807E806:
	ldr r0, _0807E848
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807E82E
	ldr r4, _0807E84C
	bl GetMultiplayerId
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r4, #4
	adds r1, r1, r4
	ldr r1, [r1]
	movs r0, #2
	bl MysteryGift_TryIncrementStat
_0807E82E:
	bl SetContinueGameWarpStatusToDynamicWarp
	bl sub_081532BC
	ldr r1, _0807E850
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	b _0807E8C2
	.align 2, 0
_0807E848: .4byte 0x0300319C
_0807E84C: .4byte 0x020226A0
_0807E850: .4byte 0x03002360
_0807E854:
	ldr r0, _0807E86C
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #5
	beq _0807E864
	b _0807EA72
_0807E864:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	b _0807EA1C
	.align 2, 0
_0807E86C: .4byte 0x02031F40
_0807E870:
	bl sub_081532E8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0807E894
	bl ClearContinueGameWarpStatus
	ldr r0, _0807E890
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E890: .4byte 0x03002360
_0807E894:
	ldr r0, _0807E8A8
	ldr r0, [r0]
	str r1, [r0, #0x64]
	ldr r0, _0807E8AC
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0x33
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E8A8: .4byte 0x02031F40
_0807E8AC: .4byte 0x03002360
_0807E8B0:
	bl sub_0815331C
	ldr r0, _0807E8CC
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x28
_0807E8C0:
	strb r1, [r0]
_0807E8C2:
	ldr r0, _0807E8D0
	ldr r0, [r0]
	str r2, [r0, #0x64]
	b _0807EA72
	.align 2, 0
_0807E8CC: .4byte 0x03002360
_0807E8D0: .4byte 0x02031F40
_0807E8D4:
	ldr r4, _0807E908
	ldr r1, [r4]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x32
	bhi _0807E8E4
	b _0807EA72
_0807E8E4:
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807E90C
	bl Random
	ldr r4, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x1e
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4, #0x64]
	b _0807E912
	.align 2, 0
_0807E908: .4byte 0x02031F40
_0807E90C:
	ldr r1, [r4]
	movs r0, #0
	str r0, [r1, #0x64]
_0807E912:
	ldr r0, _0807E920
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0x29
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E920: .4byte 0x03002360
_0807E924:
	ldr r0, _0807E944
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	cmp r0, #0
	bne _0807E94C
	movs r0, #1
	bl sub_08076C90
	ldr r0, _0807E948
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0x2a
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E944: .4byte 0x02031F40
_0807E948: .4byte 0x03002360
_0807E94C:
	subs r0, #1
	str r0, [r1, #0x64]
	b _0807EA72
_0807E952:
	bl _IsLinkTaskFinished
	cmp r0, #0
	bne _0807E95C
	b _0807EA72
_0807E95C:
	bl sub_08153344
	ldr r0, _0807E970
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #5
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E970: .4byte 0x03002360
_0807E974:
	ldr r0, _0807E998
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x3c
	bls _0807EA72
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #2
	bl sub_08076C90
	b _0807EA72
	.align 2, 0
_0807E998: .4byte 0x02031F40
_0807E99C:
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807EA72
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	b _0807EA14
_0807E9B6:
	ldr r0, _0807E9D4
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807EA72
	movs r0, #3
	bl FadeOutBGMTemporarily
	ldr r1, _0807E9D8
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r1, r0
	b _0807EA1C
	.align 2, 0
_0807E9D4: .4byte 0x02037C74
_0807E9D8: .4byte 0x03002360
_0807E9DC:
	bl IsBGMStopped
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0807EA72
	ldr r0, _0807EA04
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EA10
	ldr r0, _0807EA08
	ldr r1, [r0, #8]
	ldr r0, _0807EA0C
	cmp r1, r0
	bne _0807EA10
	movs r0, #3
	bl sub_08076C90
	b _0807EA14
	.align 2, 0
_0807EA04: .4byte 0x0300319C
_0807EA08: .4byte 0x03002360
_0807EA0C: .4byte 0x08076DB5
_0807EA10:
	bl SetCloseLinkCallback
_0807EA14:
	ldr r1, _0807EA24
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
_0807EA1C:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0807EA72
	.align 2, 0
_0807EA24: .4byte 0x03002360
_0807EA28:
	ldr r0, _0807EA50
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EA60
	ldr r1, [r2, #8]
	ldr r0, _0807EA54
	cmp r1, r0
	bne _0807EA60
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807EA72
	ldr r0, _0807EA58
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0807EA5C
	bl SetMainCallback2
	b _0807EA72
	.align 2, 0
_0807EA50: .4byte 0x0300319C
_0807EA54: .4byte 0x08076DB5
_0807EA58: .4byte 0x030027A0
_0807EA5C: .4byte 0x0807EAA1
_0807EA60:
	ldr r0, _0807EA94
	ldrb r1, [r0]
	cmp r1, #0
	bne _0807EA72
	ldr r0, _0807EA98
	strb r1, [r0]
	ldr r0, _0807EA9C
	bl SetMainCallback2
_0807EA72:
	bl HasLinkErrorOccurred
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807EA80
	bl RunTasks
_0807EA80:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807EA94: .4byte 0x030031C4
_0807EA98: .4byte 0x030027A0
_0807EA9C: .4byte 0x0807EAA1
	thumb_func_end sub_0807E588

	thumb_func_start c2_080543C4
c2_080543C4: @ 0x0807EAA0
	push {r4, r5, lr}
	ldr r0, _0807EB0C
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0807EAF6
	bl FreeAllWindowBuffers
	movs r0, #3
	bl GetBgTilemapBuffer
	bl Free
	movs r0, #1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, #0
	bl GetBgTilemapBuffer
	bl Free
	bl FreeMonSpritesGfx
	ldr r4, _0807EB10
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r0, _0807EB14
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EAEE
	bl DestroyWirelessStatusIndicatorSprite
_0807EAEE:
	ldr r0, _0807EB18
	ldr r0, [r0, #8]
	bl SetMainCallback2
_0807EAF6:
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807EB0C: .4byte 0x02037C74
_0807EB10: .4byte 0x02031F40
_0807EB14: .4byte 0x0300319C
_0807EB18: .4byte 0x03002360
	thumb_func_end c2_080543C4

	thumb_func_start DoInGameTradeScene
DoInGameTradeScene: @ 0x0807EB1C
	push {lr}
	sub sp, #4
	bl LockPlayerFieldControls
	ldr r0, _0807EB44
	movs r1, #0xa
	bl CreateTask
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0807EB44: .4byte 0x0807EB49
	thumb_func_end DoInGameTradeScene

	thumb_func_start sub_0807EB48
sub_0807EB48: @ 0x0807EB48
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _0807EB74
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807EB6C
	ldr r0, _0807EB78
	bl SetMainCallback2
	ldr r1, _0807EB7C
	ldr r0, _0807EB80
	str r0, [r1]
	adds r0, r4, #0
	bl DestroyTask
_0807EB6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807EB74: .4byte 0x02037C74
_0807EB78: .4byte 0x0807ACC9
_0807EB7C: .4byte 0x03005B0C
_0807EB80: .4byte 0x080AEA65
	thumb_func_end sub_0807EB48

	thumb_func_start sub_0807EB84
sub_0807EB84: @ 0x0807EB84
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
_0807EB8A:
	ldr r0, _0807EBC8
	ldrb r0, [r0, #1]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x64
	muls r0, r1, r0
	ldr r1, _0807EBCC
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x43
	bl GetMonData3
	adds r0, r5, r0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xb
	bls _0807EB8A
	cmp r5, #0
	beq _0807EBC2
	ldr r0, _0807EBD0
	bl FlagSet
_0807EBC2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807EBC8: .4byte 0x02031F38
_0807EBCC: .4byte 0x020243E8
_0807EBD0: .4byte 0x0000089B
	thumb_func_end sub_0807EB84

	thumb_func_start sub_0807EBD4
sub_0807EBD4: @ 0x0807EBD4
	push {lr}
	bl sub_0807ABCC
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807EBD4

	thumb_func_start sub_0807EBE0
sub_0807EBE0: @ 0x0807EBE0
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #0xff
	bl FillWindowPixelBuffer
	ldr r2, _0807EC44
	ldr r0, [r2]
	adds r0, #0xf6
	movs r3, #0
	movs r1, #0xf
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xf7
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xf8
	movs r1, #6
	strb r1, [r0]
	str r3, [sp]
	str r3, [sp, #4]
	ldr r0, [r2]
	adds r0, #0xf6
	str r0, [sp, #8]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	str r4, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl AddTextPrinterParameterized4
	adds r0, r5, #0
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807EC44: .4byte 0x02031F40
	thumb_func_end sub_0807EBE0

	thumb_func_start c3_08054588
c3_08054588: @ 0x0807EC48
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _0807EC80
	adds r4, r0, r1
	ldr r1, _0807EC84
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r2, r1, #0
	movs r3, #4
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bne _0807EC8C
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807EC94
	lsls r0, r1, #1
	ldr r1, _0807EC88
	adds r0, r0, r1
	b _0807EC96
	.align 2, 0
_0807EC80: .4byte 0x03005B68
_0807EC84: .4byte 0x0830D310
_0807EC88: .4byte 0x0830BCE4
_0807EC8C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _0807ECA4
_0807EC94:
	ldr r0, _0807ECA0
_0807EC96:
	movs r1, #0x30
	movs r2, #0x20
	bl LoadPalette
	b _0807ECB2
	.align 2, 0
_0807ECA0: .4byte 0x0830C0E4
_0807ECA4:
	lsls r0, r2, #1
	ldr r1, _0807ED08
	adds r0, r0, r1
	movs r1, #0x30
	movs r2, #0x20
	bl LoadPalette
_0807ECB2:
	ldr r0, _0807ED0C
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0807ECD0
	movs r3, #2
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bne _0807ECD0
	movs r0, #0xc3
	bl PlaySE
_0807ECD0:
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldr r1, _0807ED0C
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _0807ED10
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r0, #0
	strh r0, [r4, #2]
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0807ED16
	adds r0, r5, #0
	bl DestroyTask
	b _0807ED16
	.align 2, 0
_0807ED08: .4byte 0x0830BEE4
_0807ED0C: .4byte 0x0830D310
_0807ED10:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_0807ED16:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end c3_08054588

	thumb_func_start c3_0805465C
c3_0805465C: @ 0x0807ED1C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _0807EDCC
	adds r5, r0, r1
	movs r0, #0
	ldrsh r4, [r5, r0]
	cmp r4, #0
	bne _0807ED6E
	ldr r2, _0807EDD0
	ldr r0, [r2]
	adds r3, r0, #0
	adds r3, #0xfd
	movs r1, #0x78
	strb r1, [r3]
	adds r0, #0xfb
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xfc
	strb r4, [r0]
	ldr r0, [r2]
	adds r0, #0xfe
	movs r1, #0xa0
	strb r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0
	bl SetGpuRegBits
	movs r0, #0x4a
	movs r1, #0x10
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0x13
	bl SetGpuReg
_0807ED6E:
	ldr r4, _0807EDD0
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfd
	ldrb r1, [r1]
	adds r0, #0xfb
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r0, #0x40
	bl SetGpuReg
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfe
	ldrb r1, [r1]
	adds r0, #0xfc
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r0, #0x44
	bl SetGpuReg
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r1, [r4]
	adds r1, #0xfb
	ldrb r0, [r1]
	subs r0, #5
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, #0xfd
	ldrb r0, [r1]
	adds r0, #5
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0xfb
	ldrb r0, [r0]
	cmp r0, #0x4f
	bhi _0807EDC6
	adds r0, r6, #0
	bl DestroyTask
_0807EDC6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807EDCC: .4byte 0x03005B68
_0807EDD0: .4byte 0x02031F40
	thumb_func_end c3_0805465C

	thumb_func_start sub_0807EDD4
sub_0807EDD4: @ 0x0807EDD4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _0807EE78
	adds r5, r0, r1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0807EE10
	ldr r2, _0807EE7C
	ldr r0, [r2]
	adds r0, #0xfb
	movs r1, #0x50
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xfd
	movs r1, #0xa0
	strb r1, [r0]
	movs r0, #0x4a
	movs r1, #0x10
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0x13
	bl SetGpuReg
_0807EE10:
	ldr r4, _0807EE7C
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfd
	ldrb r1, [r1]
	adds r0, #0xfb
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r0, #0x40
	bl SetGpuReg
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfe
	ldrb r1, [r1]
	adds r0, #0xfc
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r0, #0x44
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, #0xfb
	ldrb r0, [r0]
	cmp r0, #0x78
	beq _0807EE84
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r1, [r4]
	adds r1, #0xfb
	ldrb r0, [r1]
	adds r0, #5
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, #0xfd
	ldrb r0, [r1]
	subs r0, #5
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0xfb
	ldrb r0, [r0]
	cmp r0, #0x73
	bls _0807EE94
	ldr r2, _0807EE80
	movs r0, #8
	movs r1, #0
	bl BlendPalettes
	b _0807EE94
	.align 2, 0
_0807EE78: .4byte 0x03005B68
_0807EE7C: .4byte 0x02031F40
_0807EE80: .4byte 0x0000FFFF
_0807EE84:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0
	bl ClearGpuRegBits
	adds r0, r6, #0
	bl DestroyTask
_0807EE94:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807EDD4

	thumb_func_start sub_0807EE9C
sub_0807EE9C: @ 0x0807EE9C
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, _0807EEBC
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0xc
	bls _0807EEB2
	b _0807F144
_0807EEB2:
	lsls r0, r0, #2
	ldr r1, _0807EEC0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807EEBC: .4byte 0x03002360
_0807EEC0: .4byte 0x0807EEC4
_0807EEC4: @ jump table
	.4byte _0807EEF8 @ case 0
	.4byte _0807EF20 @ case 1
	.4byte _0807EF38 @ case 2
	.4byte _0807EF88 @ case 3
	.4byte _0807EFA8 @ case 4
	.4byte _0807EFE4 @ case 5
	.4byte _0807F008 @ case 6
	.4byte _0807F058 @ case 7
	.4byte _0807F086 @ case 8
	.4byte _0807F0A4 @ case 9
	.4byte _0807F0CC @ case 10
	.4byte _0807F0FC @ case 11
	.4byte _0807F130 @ case 12
_0807EEF8:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	ldr r4, _0807EF18
	ldr r1, _0807EF1C
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	b _0807F144
	.align 2, 0
_0807EF18: .4byte 0x02021C7C
_0807EF1C: .4byte 0x08595430
_0807EF20:
	movs r0, #0
	bl sub_08076C90
	ldr r0, _0807EF34
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	movs r1, #2
	b _0807EFF4
	.align 2, 0
_0807EF34: .4byte 0x03002360
_0807EF38:
	bl _IsLinkTaskFinished
	cmp r0, #0
	bne _0807EF42
	b _0807F144
_0807EF42:
	ldr r0, _0807EF78
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r5, #0
	movs r1, #3
	strb r1, [r0]
	ldr r4, _0807EF7C
	ldr r1, _0807EF80
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	movs r0, #0x15
	bl IncrementGameStat
	bl sub_081532BC
	ldr r0, _0807EF84
	ldr r0, [r0]
	str r5, [r0, #0x64]
	b _0807F144
	.align 2, 0
_0807EF78: .4byte 0x03002360
_0807EF7C: .4byte 0x02021C7C
_0807EF80: .4byte 0x08277071
_0807EF84: .4byte 0x02031F40
_0807EF88:
	ldr r0, _0807EFA4
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #5
	beq _0807EF98
	b _0807F144
_0807EF98:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	b _0807F144
	.align 2, 0
_0807EFA4: .4byte 0x02031F40
_0807EFA8:
	bl sub_081532E8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0807EFC8
	ldr r0, _0807EFC4
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807EFC4: .4byte 0x03002360
_0807EFC8:
	ldr r0, _0807EFDC
	ldr r0, [r0]
	str r1, [r0, #0x64]
	ldr r0, _0807EFE0
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #3
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807EFDC: .4byte 0x02031F40
_0807EFE0: .4byte 0x03002360
_0807EFE4:
	bl sub_0815331C
	ldr r0, _0807F000
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	movs r1, #6
_0807EFF4:
	strb r1, [r0]
	ldr r0, _0807F004
	ldr r0, [r0]
	str r2, [r0, #0x64]
	b _0807F144
	.align 2, 0
_0807F000: .4byte 0x03002360
_0807F004: .4byte 0x02031F40
_0807F008:
	ldr r4, _0807F03C
	ldr r1, [r4]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0xa
	bhi _0807F018
	b _0807F144
_0807F018:
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807F040
	bl Random
	ldr r4, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x1e
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4, #0x64]
	b _0807F046
	.align 2, 0
_0807F03C: .4byte 0x02031F40
_0807F040:
	ldr r1, [r4]
	movs r0, #0
	str r0, [r1, #0x64]
_0807F046:
	ldr r0, _0807F054
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #7
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F054: .4byte 0x03002360
_0807F058:
	ldr r0, _0807F078
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	cmp r0, #0
	bne _0807F080
	movs r0, #1
	bl sub_08076C90
	ldr r0, _0807F07C
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F078: .4byte 0x02031F40
_0807F07C: .4byte 0x03002360
_0807F080:
	subs r0, #1
	str r0, [r1, #0x64]
	b _0807F144
_0807F086:
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807F144
	bl sub_08153344
	ldr r0, _0807F0A0
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #9
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F0A0: .4byte 0x03002360
_0807F0A4:
	ldr r0, _0807F0C8
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x3c
	bls _0807F144
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #2
	bl sub_08076C90
	b _0807F144
	.align 2, 0
_0807F0C8: .4byte 0x02031F40
_0807F0CC:
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807F144
	movs r0, #3
	bl FadeOutBGMTemporarily
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0807F0F8
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0xb
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F0F8: .4byte 0x03002360
_0807F0FC:
	ldr r0, _0807F128
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807F144
	bl IsBGMStopped
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0807F144
	movs r0, #3
	bl sub_08076C90
	ldr r0, _0807F12C
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0xc
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F128: .4byte 0x02037C74
_0807F12C: .4byte 0x03002360
_0807F130:
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807F144
	ldr r0, _0807F168
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0807F16C
	bl SetMainCallback2
_0807F144:
	bl HasLinkErrorOccurred
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807F152
	bl RunTasks
_0807F152:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807F168: .4byte 0x030027A0
_0807F16C: .4byte 0x0807EAA1
	thumb_func_end sub_0807EE9C
