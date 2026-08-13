.include "asm/macros.inc"
.include "constants/constants.inc"
.syntax unified


	.section .text.battle_anim_effects_2_part2,"ax",%progbits










	thumb_func_start AnimTask_AttackerStretchAndDisappear_Step
AnimTask_AttackerStretchAndDisappear_Step: @ 0x08106008
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _08106058
	adds r4, r0, r1
	adds r0, r4, #0
	bl RunAffineAnimFromTaskData
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08106052
	ldr r2, _0810605C
	movs r0, #8
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	strh r3, [r0, #0x26]
	movs r0, #8
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl DestroyAnimVisualTask
_08106052:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08106058: .4byte 0x03005B60
_0810605C: .4byte 0x020205AC
	thumb_func_end AnimTask_AttackerStretchAndDisappear_Step

	thumb_func_start sub_08106060
sub_08106060: @ 0x08106060
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _08106094
	adds r4, r1, r0
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xa]
	strh r0, [r4, #0xc]
	strh r0, [r4, #0xe]
	movs r0, #3
	strh r0, [r4, #0x20]
	ldr r0, _08106098
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081060A0
	ldr r0, _0810609C
	strh r0, [r4, #0x22]
	movs r0, #8
	b _081060A6
	.align 2, 0
_08106094: .4byte 0x03005B60
_08106098: .4byte 0x020380D7
_0810609C: .4byte 0x0000FFFF
_081060A0:
	movs r0, #1
	strh r0, [r4, #0x22]
	ldr r0, _081060C0
_081060A6:
	strh r0, [r4, #0x24]
	movs r0, #1
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x26]
	ldr r0, _081060C4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081060C0: .4byte 0x0000FFF8
_081060C4: .4byte 0x081060C9
	thumb_func_end sub_08106060

	thumb_func_start sub_081060C8
sub_081060C8: @ 0x081060C8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _081060EC
	adds r3, r0, r1
	movs r0, #8
	ldrsh r4, [r3, r0]
	cmp r4, #1
	beq _0810611C
	cmp r4, #1
	bgt _081060F0
	cmp r4, #0
	beq _081060FA
	b _081061E2
	.align 2, 0
_081060EC: .4byte 0x03005B60
_081060F0:
	cmp r4, #2
	beq _08106198
	cmp r4, #3
	beq _081061B2
	b _081061E2
_081060FA:
	ldr r2, _08106118
	movs r0, #0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r3, #0x24]
	ldrh r2, [r0, #0x24]
	adds r1, r1, r2
	strh r1, [r0, #0x24]
	strh r4, [r3, #0xa]
	strh r4, [r3, #0xc]
	strh r4, [r3, #0xe]
	b _081061AA
	.align 2, 0
_08106118: .4byte 0x020205AC
_0810611C:
	ldrh r0, [r3, #0xa]
	adds r0, #1
	strh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _081061E2
	movs r0, #0
	strh r0, [r3, #0xa]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	ands r0, r4
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08106154
	ldr r2, _08106150
	movs r4, #0x26
	ldrsh r1, [r3, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x24]
	adds r1, #6
	b _08106166
	.align 2, 0
_08106150: .4byte 0x020205AC
_08106154:
	ldr r2, _08106194
	movs r0, #0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r0, #0x24]
	subs r1, #6
_08106166:
	strh r1, [r0, #0x24]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _081061E2
	ldrh r1, [r3, #0xc]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081061AA
	movs r1, #0x26
	ldrsh r0, [r3, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r1, #0x24]
	subs r0, #6
	strh r0, [r1, #0x24]
	b _081061AA
	.align 2, 0
_08106194: .4byte 0x020205AC
_08106198:
	ldrh r0, [r3, #0x20]
	subs r0, #1
	strh r0, [r3, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _081061AA
	movs r0, #0
	strh r0, [r3, #8]
	b _081061E2
_081061AA:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	b _081061E2
_081061B2:
	ldr r2, _081061E8
	movs r4, #0x26
	ldrsh r1, [r3, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r3, #0x22]
	ldrh r4, [r0, #0x24]
	adds r1, r1, r4
	strh r1, [r0, #0x24]
	movs r0, #0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #0x24
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081061E2
	adds r0, r5, #0
	bl DestroyAnimVisualTask
_081061E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081061E8: .4byte 0x020205AC
	thumb_func_end sub_081060C8

	thumb_func_start sub_081061EC
sub_081061EC: @ 0x081061EC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #3
	ldr r0, _08106228
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xa]
	strh r0, [r4, #0xc]
	strh r0, [r4, #0xe]
	movs r0, #1
	strh r0, [r4, #0x10]
	movs r0, #0xe
	strh r0, [r4, #0x22]
	movs r0, #2
	strh r0, [r4, #0x24]
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x26]
	ldr r0, _0810622C
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08106228: .4byte 0x03005B60
_0810622C: .4byte 0x08106231
	thumb_func_end sub_081061EC

	thumb_func_start sub_08106230
sub_08106230: @ 0x08106230
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _08106284
	adds r4, r0, r1
	movs r0, #8
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _081062F6
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x10
	ldrsh r1, [r4, r3]
	cmp r0, r1
	ble _081062F6
	strh r2, [r4, #0xa]
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0810628C
	ldr r3, _08106288
	movs r6, #0x26
	ldrsh r1, [r4, r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	b _081062A2
	.align 2, 0
_08106284: .4byte 0x03005B60
_08106288: .4byte 0x020205AC
_0810628C:
	ldr r3, _081062D4
	movs r0, #0x26
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
_081062A2:
	strb r1, [r0]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r2, #0
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r6, #0x22
	ldrsh r1, [r4, r6]
	cmp r0, r1
	blt _081062F6
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r6, #0x24
	ldrsh r1, [r4, r6]
	cmp r0, r1
	bge _081062D8
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	strh r2, [r4, #0xe]
	b _081062F6
	.align 2, 0
_081062D4: .4byte 0x020205AC
_081062D8:
	movs r0, #0x26
	ldrsh r1, [r4, r0]
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
	adds r0, r5, #0
	bl DestroyAnimVisualTask
_081062F6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_08106230

	thumb_func_start sub_081062FC
sub_081062FC: @ 0x081062FC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #3
	ldr r0, _0810634C
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4, #8]
	movs r1, #4
	strh r1, [r4, #0xa]
	strh r0, [r4, #0xc]
	strh r0, [r4, #0xe]
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	strh r0, [r4, #0x14]
	strh r0, [r4, #0x16]
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x22]
	ldr r5, _08106350
	ldrb r0, [r5]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x24]
	ldrb r0, [r5]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x26]
	ldr r0, _08106354
	str r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810634C: .4byte 0x03005B60
_08106350: .4byte 0x020380D6
_08106354: .4byte 0x08106359
	thumb_func_end sub_081062FC

	thumb_func_start sub_08106358
sub_08106358: @ 0x08106358
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _0810637C
	adds r4, r0, r1
	movs r0, #0x18
	ldrsh r2, [r4, r0]
	cmp r2, #1
	beq _081063C4
	cmp r2, #1
	bgt _08106380
	cmp r2, #0
	beq _08106386
	b _081063E0
	.align 2, 0
_0810637C: .4byte 0x03005B60
_08106380:
	cmp r2, #2
	beq _081063DC
	b _081063E0
_08106386:
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _081063E0
	strh r2, [r4, #0x10]
	ldrh r0, [r4, #0x12]
	adds r0, #1
	movs r1, #1
	ands r0, r1
	strh r0, [r4, #0x12]
	ldrh r0, [r4, #0x14]
	adds r0, #1
	strh r0, [r4, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _081063E0
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _081063BE
	strh r2, [r4, #0x14]
	movs r0, #1
	strh r0, [r4, #0x18]
	b _081063E0
_081063BE:
	movs r0, #2
	strh r0, [r4, #0x18]
	b _081063E0
_081063C4:
	movs r1, #0
	strh r1, [r4, #0x12]
	ldrh r0, [r4, #0x10]
	adds r0, #1
	strh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _081063E0
	strh r2, [r4, #0x16]
	strh r1, [r4, #0x18]
	b _081063E0
_081063DC:
	movs r0, #1
	strh r0, [r4, #0x12]
_081063E0:
	movs r2, #8
	ldrsh r5, [r4, r2]
	cmp r5, #0
	beq _081063EE
	cmp r5, #1
	beq _08106484
	b _08106492
_081063EE:
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _08106492
	strh r5, [r4, #0xa]
	ldr r0, _08106478
	movs r3, #0x24
	ldrsh r1, [r4, r3]
	movs r3, #0x26
	ldrsh r2, [r4, r3]
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _08106492
	ldr r0, _0810647C
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	strh r6, [r1, #0x2e]
	movs r0, #0xd
	strh r0, [r1, #0x30]
	ldr r2, _08106480
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #0x24]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1, #0x26]
	ldrh r0, [r4, #0x22]
	adds r0, #1
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _08106492
	strh r5, [r4, #0xc]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08106492
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _08106492
	.align 2, 0
_08106478: .4byte 0x0856F4C0
_0810647C: .4byte 0x020205AC
_08106480: .4byte 0x0856F4D8
_08106484:
	movs r1, #0x22
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08106492
	adds r0, r6, #0
	bl DestroyAnimVisualTask
_08106492:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_08106358

	thumb_func_start sub_08106498
sub_08106498: @ 0x08106498
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _08106500
	movs r0, #0x2e
	ldrsh r1, [r3, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r1, #0x3e
	adds r1, r1, r3
	mov ip, r1
	movs r2, #1
	ldrb r1, [r0, #0x12]
	ands r1, r2
	lsls r1, r1, #2
	mov r0, ip
	ldrb r2, [r0]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081064FA
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	lsls r1, r1, #1
	movs r0, #0x2e
	ldrsh r2, [r3, r0]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r0, r3, #0
	bl DestroySprite
_081064FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08106500: .4byte 0x03005B60
	thumb_func_end sub_08106498

	thumb_func_start sub_08106504
sub_08106504: @ 0x08106504
	push {r4, r5, r6, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _081065A0
	bl IndexOfSpritePaletteTag
	mov r1, sp
	strb r0, [r1]
	movs r4, #1
	ldr r0, _081065A4
	adds r5, r0, #0
_0810651C:
	subs r0, r5, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl AllocSpritePalette
	mov r2, sp
	adds r1, r2, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #2
	ble _0810651C
	movs r0, #0x80
	lsls r0, r0, #6
	bl AllocZeroed
	adds r1, r0, #0
	ldr r0, _081065A8
	ldr r0, [r0]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r0, r2
	str r1, [r0]
	ldr r0, _081065AC
	bl LZDecompressVram
	movs r4, #0
_08106550:
	ldr r5, _081065A8
	ldr r0, [r5]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r1, r4, #6
	ldr r0, [r0]
	adds r0, r0, r1
	mov r2, sp
	adds r1, r2, r4
	ldrb r1, [r1]
	lsls r1, r1, #0x14
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	movs r2, #0x20
	bl LoadPalette
	adds r4, #1
	cmp r4, #2
	ble _08106550
	ldr r0, [r5]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	str r1, [r0]
	adds r0, r6, #0
	bl DestroyAnimVisualTask
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081065A0: .4byte 0x000027DE
_081065A4: .4byte 0x00002710
_081065A8: .4byte 0x02024178
_081065AC: .4byte 0x08C226B4
	thumb_func_end sub_08106504

	thumb_func_start sub_081065B0
sub_081065B0: @ 0x081065B0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r5, _081065D4
	movs r4, #2
_081065BA:
	ldrh r0, [r5]
	bl FreeSpritePaletteByTag
	adds r5, #2
	subs r4, #1
	cmp r4, #0
	bge _081065BA
	adds r0, r6, #0
	bl DestroyAnimVisualTask
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081065D4: .4byte 0x0856F534
	thumb_func_end sub_081065B0

	thumb_func_start sub_081065D8
sub_081065D8: @ 0x081065D8
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r3, r2, #0x18
	movs r0, #1
	ands r3, r0
	rsbs r0, r3, #0
	orrs r0, r3
	asrs r0, r0, #0x1f
	movs r3, #0x20
	ands r0, r3
	ldrh r4, [r5, #4]
	lsls r3, r4, #0x16
	lsrs r3, r3, #0x16
	lsrs r1, r1, #0x16
	adds r0, r0, r1
	adds r3, r3, r0
	ldr r1, _0810662C
	adds r0, r1, #0
	ands r3, r0
	ldr r0, _08106630
	ands r0, r4
	orrs r0, r3
	strh r0, [r5, #4]
	ldr r0, _08106634
	lsrs r2, r2, #0x19
	lsls r2, r2, #1
	adds r2, r2, r0
	ldrh r0, [r2]
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #4
	ldrb r2, [r5, #5]
	movs r1, #0xf
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810662C: .4byte 0x000003FF
_08106630: .4byte 0xFFFFFC00
_08106634: .4byte 0x0856F534
	thumb_func_end sub_081065D8

	thumb_func_start sub_08106638
sub_08106638: @ 0x08106638
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0
	bl InitSpritePosToAnimAttacker
	ldr r6, _081066A0
	ldrb r0, [r6]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08106658
	ldr r1, _081066A4
	ldrh r0, [r1, #4]
	rsbs r0, r0, #0
	strh r0, [r1, #4]
_08106658:
	ldr r4, _081066A4
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x2e]
	ldrb r0, [r6]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r5, #0x32]
	ldrb r0, [r6]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r4, #6]
	adds r0, r0, r1
	strh r0, [r5, #0x36]
	ldr r0, _081066A8
	str r0, [r5, #0x1c]
	ldr r1, _081066AC
	adds r0, r5, #0
	bl StoreSpriteCallbackInData6
	ldrb r1, [r4, #0xa]
	ldrb r2, [r4, #0xc]
	adds r0, r5, #0
	bl sub_081065D8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081066A0: .4byte 0x020380D6
_081066A4: .4byte 0x020380BE
_081066A8: .4byte 0x080A67B5
_081066AC: .4byte 0x080A34C5
	thumb_func_end sub_08106638

	thumb_func_start sub_081066B0
sub_081066B0: @ 0x081066B0
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _081066CA
	adds r0, r4, #0
	movs r1, #0
	bl InitSpritePosToAnimAttacker
_081066CA:
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	movs r1, #8
	bl Sin
	strh r0, [r4, #0x24]
	ldrh r2, [r4, #0x32]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x30]
	adds r0, #7
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x30]
	subs r2, #0x80
	strh r2, [r4, #0x32]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0x3c
	bne _081066FA
	adds r0, r4, #0
	bl DestroyAnimSprite
_081066FA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081066B0

	thumb_func_start sub_08106700
sub_08106700: @ 0x08106700
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	bl IsContest
	lsls r0, r0, #0x18
	movs r6, #0xf0
	cmp r0, #0
	beq _08106714
	movs r6, #0x98
_08106714:
	movs r5, #0
	ldr r1, _08106768
	strh r6, [r1]
	ldr r4, _0810676C
	movs r0, #0xa0
	strh r0, [r4]
	ldrh r1, [r1]
	movs r0, #0x40
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, #0x44
	bl SetGpuReg
	ldr r1, _08106770
	movs r0, #0x48
	bl SetGpuReg
	ldr r1, _08106774
	movs r0, #0x4a
	bl SetGpuReg
	movs r0, #0x50
	movs r1, #0xc8
	bl SetGpuReg
	movs r0, #0x54
	movs r1, #0x10
	bl SetGpuReg
	ldr r1, _08106778
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	strh r5, [r0, #8]
	strh r6, [r0, #0xa]
	ldr r1, _0810677C
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08106768: .4byte 0x02022AD8
_0810676C: .4byte 0x02022ADA
_08106770: .4byte 0x00003F1F
_08106774: .4byte 0x00003F3F
_08106778: .4byte 0x03005B60
_0810677C: .4byte 0x08106781
	thumb_func_end sub_08106700

	thumb_func_start sub_08106780
sub_08106780: @ 0x08106780
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _081067B4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r3, r1, r2
	ldrh r0, [r3, #8]
	adds r4, r0, #0
	adds r4, #0xd
	strh r4, [r3, #8]
	ldrh r0, [r3, #0xa]
	adds r2, r0, #0
	subs r2, #0xd
	strh r2, [r3, #0xa]
	lsls r1, r4, #0x10
	lsls r0, r2, #0x10
	cmp r1, r0
	blt _081067C0
	ldr r0, _081067B8
	movs r1, #0
	strh r1, [r0]
	ldr r0, _081067BC
	str r0, [r3]
	b _081067C8
	.align 2, 0
_081067B4: .4byte 0x03005B60
_081067B8: .4byte 0x02022AD8
_081067BC: .4byte 0x081067D5
_081067C0:
	ldr r1, _081067D0
	lsls r0, r4, #8
	orrs r2, r0
	strh r2, [r1]
_081067C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081067D0: .4byte 0x02022AD8
	thumb_func_end sub_08106780

	thumb_func_start sub_081067D4
sub_081067D4: @ 0x081067D4
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r5, r0, #0
	ldr r1, _08106820
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r1, r0, r1
	ldrh r0, [r1, #0x1c]
	adds r0, #1
	movs r4, #0
	strh r0, [r1, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bne _08106828
	movs r0, #0x88
	strh r0, [r1, #0x1e]
	movs r0, #0x50
	movs r1, #0x88
	bl SetGpuReg
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_080A6E74
	ldr r2, _08106824
	movs r1, #0x10
	bl BlendPalettes
	b _0810685C
	.align 2, 0
_08106820: .4byte 0x03005B60
_08106824: .4byte 0x00007FFF
_08106828:
	cmp r0, #4
	ble _0810685C
	ldr r0, _08106864
	strh r4, [r0]
	ldr r0, _08106868
	strh r4, [r0]
	ldr r4, _0810686C
	movs r0, #0x48
	adds r1, r4, #0
	bl SetGpuReg
	movs r0, #0x4a
	adds r1, r4, #0
	bl SetGpuReg
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x54
	movs r1, #0
	bl SetGpuReg
	adds r0, r5, #0
	bl DestroyAnimVisualTask
_0810685C:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08106864: .4byte 0x02022AD8
_08106868: .4byte 0x02022ADA
_0810686C: .4byte 0x00003F3F
	thumb_func_end sub_081067D4

	thumb_func_start sub_08106870
sub_08106870: @ 0x08106870
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0
	movs r0, #1
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _081068C0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r5, r0, r1
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _081068CC
	movs r0, #1
	bl GetAnimBattlerSpriteId
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _081068C4
	adds r0, r5, #0
	bl PrepareAffineAnimInTaskData
	ldr r1, _081068C8
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	strh r1, [r0, #0x24]
	b _081068F4
	.align 2, 0
_081068C0: .4byte 0x03005B60
_081068C4: .4byte 0x0856F56C
_081068C8: .4byte 0x020205AC
_081068CC:
	ldr r1, _081068FC
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r4, r0, r1
	ldrh r0, [r4, #0x24]
	rsbs r0, r0, #0
	strh r0, [r4, #0x24]
	adds r0, r5, #0
	bl RunAffineAnimFromTaskData
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _081068F4
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	adds r0, r6, #0
	bl DestroyAnimVisualTask
_081068F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081068FC: .4byte 0x020205AC
	thumb_func_end sub_08106870

	thumb_func_start sub_08106900
sub_08106900: @ 0x08106900
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _08106950
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r5, r0, r1
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _0810695C
	movs r0, #0
	bl GetAnimBattlerSpriteId
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _08106954
	adds r0, r5, #0
	bl PrepareAffineAnimInTaskData
	ldr r1, _08106958
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #4
	strh r1, [r0, #0x24]
	b _08106984
	.align 2, 0
_08106950: .4byte 0x03005B60
_08106954: .4byte 0x0856F56C
_08106958: .4byte 0x020205AC
_0810695C:
	ldr r1, _0810698C
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r4, r0, r1
	ldrh r0, [r4, #0x24]
	rsbs r0, r0, #0
	strh r0, [r4, #0x24]
	adds r0, r5, #0
	bl RunAffineAnimFromTaskData
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08106984
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	adds r0, r6, #0
	bl DestroyAnimVisualTask
_08106984:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810698C: .4byte 0x020205AC
	thumb_func_end sub_08106900

	thumb_func_start sub_08106990
sub_08106990: @ 0x08106990
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #1
	bl InitSpritePosToAnimAttacker
	movs r0, #0x5f
	strh r0, [r4, #0x2e]
	ldrh r0, [r4, #0x20]
	strh r0, [r4, #0x30]
	ldr r5, _081069D4
	ldrb r0, [r5]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x32]
	ldrh r0, [r4, #0x22]
	strh r0, [r4, #0x34]
	ldrb r0, [r5]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x36]
	adds r0, r4, #0
	bl InitAnimLinearTranslation
	ldr r0, _081069D8
	str r0, [r4, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081069D4: .4byte 0x020380D7
_081069D8: .4byte 0x081069DD
	thumb_func_end sub_08106990

	thumb_func_start sub_081069DC
sub_081069DC: @ 0x081069DC
	push {r4, lr}
	adds r4, r0, #0
	bl AnimTranslateLinear
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08106A06
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	movs r1, #0xe
	bl Sin
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x38]
	adds r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x38]
	b _08106A0C
_08106A06:
	adds r0, r4, #0
	bl DestroyAnimSprite
_08106A0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081069DC

	thumb_func_start sub_08106A14
sub_08106A14: @ 0x08106A14
	push {r4, lr}
	adds r4, r0, #0
	ldrh r2, [r4, #0x2e]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08106A38
	ldr r1, _08106A34
	ldrh r0, [r1]
	strh r0, [r4, #0x30]
	ldrh r0, [r1, #2]
	strh r0, [r4, #0x32]
	adds r0, r2, #1
	strh r0, [r4, #0x2e]
	b _08106A94
	.align 2, 0
_08106A34: .4byte 0x020380BE
_08106A38:
	ldrh r0, [r4, #0x30]
	ldrh r2, [r4, #0x36]
	adds r0, r0, r2
	strh r0, [r4, #0x36]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x24]
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x34]
	adds r0, #3
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x34]
	cmp r0, #0x64
	ble _08106A86
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r3, r4, #0
	adds r3, #0x3e
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_08106A86:
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	cmp r0, #0x78
	ble _08106A94
	adds r0, r4, #0
	bl DestroyAnimSprite
_08106A94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08106A14

	thumb_func_start sub_08106A9C
sub_08106A9C: @ 0x08106A9C
	push {lr}
	ldr r2, _08106AC0
	ldrh r1, [r2]
	strh r1, [r0, #0x20]
	movs r1, #0xa0
	strh r1, [r0, #0x22]
	ldrh r1, [r2, #4]
	strh r1, [r0, #0x2e]
	ldrh r1, [r2, #2]
	strh r1, [r0, #0x30]
	ldr r1, _08106AC4
	str r1, [r0, #0x1c]
	ldr r1, _08106AC8
	bl StoreSpriteCallbackInData6
	pop {r0}
	bx r0
	.align 2, 0
_08106AC0: .4byte 0x020380BE
_08106AC4: .4byte 0x080A5D79
_08106AC8: .4byte 0x08106ACD
	thumb_func_end sub_08106A9C

	thumb_func_start sub_08106ACC
sub_08106ACC: @ 0x08106ACC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x32]
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	strh r0, [r4, #0x26]
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	movs r1, #4
	bl Sin
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x34]
	adds r0, #3
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x34]
	ldrh r0, [r4, #0x26]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0x48
	bgt _08106B32
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r3, r4, #0
	adds r3, #0x3e
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	cmp r5, #0x40
	bgt _08106B32
	adds r0, r4, #0
	bl DestroyAnimSprite
_08106B32:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08106ACC

	thumb_func_start AnimTask_HeartsBackground
AnimTask_HeartsBackground: @ 0x08106B38
	push {r4, r5, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08106BD8
	movs r0, #0x50
	bl SetGpuReg
	movs r1, #0x80
	lsls r1, r1, #5
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #1
	movs r1, #4
	movs r2, #3
	bl SetAnimBgAttribute
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08106B7A
	movs r0, #1
	movs r1, #3
	movs r2, #1
	bl SetAnimBgAttribute
_08106B7A:
	ldr r0, _08106BDC
	movs r1, #0
	strh r1, [r0]
	ldr r4, _08106BE0
	strh r1, [r4]
	movs r0, #0x14
	movs r1, #0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, #0x16
	bl SetGpuReg
	mov r0, sp
	bl sub_080A63F8
	mov r0, sp
	ldrb r0, [r0, #9]
	ldr r1, _08106BE4
	mov r2, sp
	ldrh r2, [r2, #0xa]
	bl AnimLoadCompressedBgGfx
	ldr r1, _08106BE8
	mov r0, sp
	movs r2, #0
	bl sub_080A6628
	ldr r0, _08106BEC
	mov r1, sp
	ldrb r1, [r1, #8]
	lsls r1, r1, #4
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r1, _08106BF0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _08106BF4
	str r1, [r0]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08106BD8: .4byte 0x00003F42
_08106BDC: .4byte 0x02022ACC
_08106BE0: .4byte 0x02022ACE
_08106BE4: .4byte 0x08C23384
_08106BE8: .4byte 0x08C23E1C
_08106BEC: .4byte 0x08C23DF4
_08106BF0: .4byte 0x03005B60
_08106BF4: .4byte 0x08106BF9
	thumb_func_end AnimTask_HeartsBackground

	thumb_func_start sub_08106BF8
sub_08106BF8: @ 0x08106BF8
	push {r4, r5, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _08106C20
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #0x20
	ldrsh r0, [r0, r2]
	adds r2, r1, #0
	cmp r0, #4
	bls _08106C16
	b _08106D40
_08106C16:
	lsls r0, r0, #2
	ldr r1, _08106C24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08106C20: .4byte 0x03005B60
_08106C24: .4byte 0x08106C28
_08106C28: @ jump table
	.4byte _08106C3C @ case 0
	.4byte _08106C80 @ case 1
	.4byte _08106CA2 @ case 2
	.4byte _08106CE6 @ case 3
	.4byte _08106D0C @ case 4
_08106C3C:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r4, r0, r2
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _08106D40
	strh r5, [r4, #0x1c]
	ldrh r1, [r4, #0x1e]
	adds r1, #1
	strh r1, [r4, #0x1e]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0x10
	bne _08106D40
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
	strh r5, [r4, #0x1e]
	b _08106D40
_08106C80:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r1, r0, r2
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	strh r0, [r1, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x8d
	bne _08106D40
	movs r0, #0x10
	strh r0, [r1, #0x1e]
	ldrh r0, [r1, #0x20]
	adds r0, #1
	strh r0, [r1, #0x20]
	b _08106D40
_08106CA2:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r4, r0, r2
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _08106D40
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldrh r1, [r4, #0x1e]
	subs r1, #1
	strh r1, [r4, #0x1e]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r2, #0x1e
	ldrsh r1, [r4, r2]
	cmp r1, #0
	bne _08106D40
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
	strh r1, [r4, #0x1e]
	b _08106D40
_08106CE6:
	mov r0, sp
	bl sub_080A63F8
	mov r0, sp
	ldrb r0, [r0, #9]
	bl sub_080A6530
	ldr r1, _08106D08
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #0x20]
	adds r1, #1
	strh r1, [r0, #0x20]
	b _08106D40
	.align 2, 0
_08106D08: .4byte 0x03005B60
_08106D0C:
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08106D20
	movs r0, #1
	movs r1, #3
	movs r2, #0
	bl SetAnimBgAttribute
_08106D20:
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	adds r0, r4, #0
	bl DestroyAnimVisualTask
_08106D40:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08106BF8

	thumb_func_start sub_08106D48
sub_08106D48: @ 0x08106D48
	push {r4, r5, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08106DB8
	movs r0, #0x50
	bl SetGpuReg
	movs r1, #0x80
	lsls r1, r1, #5
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08106D8A
	movs r0, #1
	movs r1, #3
	movs r2, #1
	bl SetAnimBgAttribute
_08106D8A:
	ldr r0, _08106DBC
	movs r1, #0
	strh r1, [r0]
	ldr r4, _08106DC0
	strh r1, [r4]
	movs r0, #0x14
	movs r1, #0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, #0x16
	bl SetGpuReg
	mov r0, sp
	bl sub_080A63F8
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08106DC8
	ldr r1, _08106DC4
	b _08106DDA
	.align 2, 0
_08106DB8: .4byte 0x00003F42
_08106DBC: .4byte 0x02022ACC
_08106DC0: .4byte 0x02022ACE
_08106DC4: .4byte 0x08D93914
_08106DC8:
	ldr r0, _08106DE4
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08106DEC
	ldr r1, _08106DE8
_08106DDA:
	mov r0, sp
	movs r2, #0
	bl sub_080A6628
	b _08106DF6
	.align 2, 0
_08106DE4: .4byte 0x020380D7
_08106DE8: .4byte 0x08D9354C
_08106DEC:
	ldr r1, _08106E28
	mov r0, sp
	movs r2, #0
	bl sub_080A6628
_08106DF6:
	mov r0, sp
	ldrb r0, [r0, #9]
	ldr r1, _08106E2C
	mov r2, sp
	ldrh r2, [r2, #0xa]
	bl AnimLoadCompressedBgGfx
	ldr r0, _08106E30
	mov r1, sp
	ldrb r1, [r1, #8]
	lsls r1, r1, #4
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r1, _08106E34
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _08106E38
	str r1, [r0]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08106E28: .4byte 0x08D93730
_08106E2C: .4byte 0x08C24A9C
_08106E30: .4byte 0x08C24A74
_08106E34: .4byte 0x03005B60
_08106E38: .4byte 0x08106E3D
	thumb_func_end sub_08106D48

	thumb_func_start sub_08106E3C
sub_08106E3C: @ 0x08106E3C
	push {r4, r5, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _08106E64
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #0x20
	ldrsh r0, [r0, r2]
	adds r2, r1, #0
	cmp r0, #4
	bls _08106E5A
	b _08106F80
_08106E5A:
	lsls r0, r0, #2
	ldr r1, _08106E68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08106E64: .4byte 0x03005B60
_08106E68: .4byte 0x08106E6C
_08106E6C: @ jump table
	.4byte _08106E80 @ case 0
	.4byte _08106EC4 @ case 1
	.4byte _08106EE6 @ case 2
	.4byte _08106F2A @ case 3
	.4byte _08106F4C @ case 4
_08106E80:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r4, r0, r2
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne _08106F80
	strh r5, [r4, #0x1c]
	ldrh r1, [r4, #0x1e]
	adds r1, #1
	strh r1, [r4, #0x1e]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0xe
	bne _08106F80
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
	strh r5, [r4, #0x1e]
	b _08106F80
_08106EC4:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r1, r0, r2
	ldrh r0, [r1, #0x1e]
	adds r0, #1
	strh r0, [r1, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x15
	bne _08106F80
	movs r0, #0xe
	strh r0, [r1, #0x1e]
	ldrh r0, [r1, #0x20]
	adds r0, #1
	strh r0, [r1, #0x20]
	b _08106F80
_08106EE6:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r4, r0, r2
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	bne _08106F80
	movs r0, #0
	strh r0, [r4, #0x1c]
	ldrh r1, [r4, #0x1e]
	subs r1, #1
	strh r1, [r4, #0x1e]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r2, #0x1e
	ldrsh r1, [r4, r2]
	cmp r1, #0
	bne _08106F80
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
	strh r1, [r4, #0x1e]
	b _08106F80
_08106F2A:
	mov r0, sp
	bl sub_080A63F8
	movs r0, #1
	bl sub_080A6530
	movs r0, #2
	bl sub_080A6530
	ldr r0, _08106F88
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #0x20]
	adds r0, #1
	strh r0, [r1, #0x20]
_08106F4C:
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08106F60
	movs r0, #1
	movs r1, #3
	movs r2, #0
	bl SetAnimBgAttribute
_08106F60:
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	adds r0, r4, #0
	bl DestroyAnimVisualTask
_08106F80:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08106F88: .4byte 0x03005B60
	thumb_func_end sub_08106E3C

	thumb_func_start AnimOrbitFast
AnimOrbitFast: @ 0x08106F8C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08106FE0
	ldrb r0, [r5]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x20]
	ldrb r0, [r5]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x22]
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08106FE4
	ldrh r0, [r1]
	strh r0, [r4, #0x2e]
	ldrh r0, [r1, #2]
	strh r0, [r4, #0x30]
	ldrb r0, [r5]
	bl GetBattlerSpriteSubpriority
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x3c]
	ldr r1, _08106FE8
	str r1, [r4, #0x1c]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08106FE0: .4byte 0x020380D6
_08106FE4: .4byte 0x020380BE
_08106FE8: .4byte 0x08106FED
	thumb_func_end AnimOrbitFast

	thumb_func_start AnimOrbitFastStep
AnimOrbitFastStep: @ 0x08106FEC
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x30]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bhi _08107002
	ldrh r0, [r4, #0x3c]
	adds r0, #1
	b _08107006
_08107002:
	ldrh r0, [r4, #0x3c]
	subs r0, #1
_08107006:
	adds r1, r4, #0
	adds r1, #0x43
	strb r0, [r1]
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, #0x32]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	bl Sin
	strh r0, [r4, #0x24]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	ldrh r1, [r4, #0x34]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	bl Cos
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x30]
	adds r0, #9
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x30]
	movs r3, #0x38
	ldrsh r2, [r4, r3]
	cmp r2, #0
	beq _08107078
	cmp r2, #1
	bne _081070A8
	ldr r1, _08107070
	adds r0, r1, #0
	ldrh r2, [r4, #0x32]
	adds r0, r0, r2
	strh r0, [r4, #0x32]
	ldr r3, _08107074
	adds r0, r3, #0
	ldrh r1, [r4, #0x34]
	adds r0, r0, r1
	strh r0, [r4, #0x34]
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x2e
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _081070A8
	movs r0, #2
	strh r0, [r4, #0x38]
	b _081070B8
	.align 2, 0
_08107070: .4byte 0xFFFFFC00
_08107074: .4byte 0xFFFFFF00
_08107078:
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r3, #0
	ldrh r1, [r4, #0x32]
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r4, #0x34]
	adds r0, r0, r1
	strh r0, [r4, #0x34]
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bne _081070A8
	strh r2, [r4, #0x36]
	movs r0, #1
	strh r0, [r4, #0x38]
_081070A8:
	ldr r0, _081070C0
	ldrh r1, [r0, #0xe]
	ldr r0, _081070C4
	cmp r1, r0
	bne _081070B8
	adds r0, r4, #0
	bl DestroyAnimSprite
_081070B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081070C0: .4byte 0x020380BE
_081070C4: .4byte 0x0000FFFF
	thumb_func_end AnimOrbitFastStep

	thumb_func_start AnimOrbitScatter
AnimOrbitScatter: @ 0x081070C8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _08107110
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x22]
	ldr r4, _08107114
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Sin
	strh r0, [r5, #0x2e]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #7
	bl Cos
	strh r0, [r5, #0x30]
	ldr r0, _08107118
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08107110: .4byte 0x020380D6
_08107114: .4byte 0x020380BE
_08107118: .4byte 0x0810711D
	thumb_func_end AnimOrbitScatter

	thumb_func_start AnimOrbitScatterStep
AnimOrbitScatterStep: @ 0x0810711C
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2e]
	ldrh r1, [r2, #0x24]
	adds r0, r0, r1
	strh r0, [r2, #0x24]
	ldrh r0, [r2, #0x30]
	ldrh r3, [r2, #0x26]
	adds r0, r0, r3
	strh r0, [r2, #0x26]
	movs r1, #0x20
	ldrsh r0, [r2, r1]
	movs r3, #0x24
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #1
	cmp r0, r1
	bhi _0810715A
	movs r0, #0x22
	ldrsh r1, [r2, r0]
	movs r3, #0x26
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
	cmp r1, #0xa0
	bgt _0810715A
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08107160
_0810715A:
	adds r0, r2, #0
	bl DestroyAnimSprite
_08107160:
	pop {r0}
	bx r0
	thumb_func_end AnimOrbitScatterStep

	thumb_func_start sub_08107164
sub_08107164: @ 0x08107164
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2e]
	ldrh r1, [r2, #0x24]
	adds r0, r0, r1
	strh r0, [r2, #0x24]
	ldrh r0, [r2, #0x30]
	ldrh r3, [r2, #0x26]
	adds r0, r0, r3
	strh r0, [r2, #0x26]
	ldrh r0, [r2, #0x34]
	adds r1, r0, #1
	strh r1, [r2, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x32
	ldrsh r1, [r2, r3]
	cmp r0, r1
	blt _08107190
	adds r0, r2, #0
	bl DestroyAnimSprite
_08107190:
	pop {r0}
	bx r0
	thumb_func_end sub_08107164

	thumb_func_start sub_08107194
sub_08107194: @ 0x08107194
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _081071E0
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x22]
	ldr r4, _081071E4
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Sin
	strh r0, [r5, #0x2e]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #7
	bl Cos
	strh r0, [r5, #0x30]
	ldrh r0, [r4, #2]
	strh r0, [r5, #0x32]
	ldr r0, _081071E8
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081071E0: .4byte 0x020380D6
_081071E4: .4byte 0x020380BE
_081071E8: .4byte 0x08107165
	thumb_func_end sub_08107194

	thumb_func_start sub_081071EC
sub_081071EC: @ 0x081071EC
	push {lr}
	adds r2, r0, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08107202
	adds r0, r2, #0
	bl DestroyAnimSprite
_08107202:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081071EC

	thumb_func_start sub_08107208
sub_08107208: @ 0x08107208
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #1
	bl InitSpritePosToAnimAttacker
	ldr r0, _0810721C
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0810721C: .4byte 0x081071ED
	thumb_func_end sub_08107208

	thumb_func_start sub_08107220
sub_08107220: @ 0x08107220
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0810723E
	ldr r0, _081072B0
	ldrh r1, [r0]
	ldrh r2, [r4, #0x20]
	adds r1, r1, r2
	strh r1, [r4, #0x20]
	ldrh r0, [r0, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
_0810723E:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r2, #0x2e
	ldrsh r1, [r4, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r5, r0, #1
	movs r0, #0xff
	ands r5, r0
	adds r0, r5, #0
	movs r1, #0x50
	bl Sin
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x24]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0x4f
	bgt _08107282
	adds r0, r5, #0
	movs r1, #0x50
	bl Cos
	movs r2, #0x2e
	ldrsh r1, [r4, r2]
	lsrs r2, r1, #0x1f
	adds r1, r1, r2
	asrs r1, r1, #1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r1, r1, r0
	strh r1, [r4, #0x26]
_08107282:
	movs r0, #0x2e
	ldrsh r2, [r4, r0]
	cmp r2, #0x5a
	ble _081072A0
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	lsrs r0, r1, #0x1f
	adds r1, r1, r0
	asrs r1, r1, #1
	ldrh r0, [r4, #0x24]
	subs r0, r0, r1
	strh r0, [r4, #0x24]
_081072A0:
	cmp r2, #0x64
	ble _081072AA
	adds r0, r4, #0
	bl DestroyAnimSprite
_081072AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081072B0: .4byte 0x020380BE
	thumb_func_end sub_08107220

	thumb_func_start sub_081072B4
sub_081072B4: @ 0x081072B4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	movs r1, #5
	bl Sin
	strh r0, [r4, #0x24]
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x34]
	adds r0, #3
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x34]
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	cmp r0, #0x14
	ble _0810730A
	adds r1, r0, #0
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r3, r4, #0
	adds r3, #0x3e
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0810730A:
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	cmp r0, #0x1e
	ble _08107318
	adds r0, r4, #0
	bl DestroyAnimSprite
_08107318:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081072B4

	thumb_func_start sub_08107320
sub_08107320: @ 0x08107320
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r2, [r4, #0x2e]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08107344
	ldr r1, _08107340
	ldrh r0, [r1]
	strh r0, [r4, #0x30]
	ldrh r0, [r1, #2]
	strh r0, [r4, #0x32]
	adds r0, r2, #1
	strh r0, [r4, #0x2e]
	b _08107398
	.align 2, 0
_08107340: .4byte 0x020380BE
_08107344:
	ldrh r0, [r4, #0x30]
	ldrh r2, [r4, #0x36]
	adds r0, r0, r2
	movs r5, #0
	strh r0, [r4, #0x36]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x24]
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	bl Sin
	adds r2, r0, #0
	strh r2, [r4, #0x26]
	ldrh r0, [r4, #0x34]
	adds r0, #3
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x34]
	cmp r0, #0x46
	ble _08107398
	ldr r0, _081073A0
	str r0, [r4, #0x1c]
	ldrh r0, [r4, #0x24]
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r1, [r4, #0x22]
	adds r0, r2, r1
	strh r0, [r4, #0x22]
	strh r5, [r4, #0x24]
	strh r5, [r4, #0x26]
	bl Random2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xb4
	bl __umodsi3
	strh r0, [r4, #0x34]
_08107398:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081073A0: .4byte 0x081072B5
	thumb_func_end sub_08107320

	thumb_func_start sub_081073A4
sub_081073A4: @ 0x081073A4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _081073DE
	ldr r1, _081074A0
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	ldrh r0, [r1, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
	adds r0, r4, #0
	movs r1, #0
	bl StartSpriteAnim
	ldr r0, _081074A4
	ldrb r0, [r0]
	bl GetBattlerSpriteSubpriority
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0x43
	strb r0, [r1]
	movs r0, #1
	strh r0, [r4, #0x32]
_081073DE:
	ldrh r0, [r4, #0x32]
	ldrh r2, [r4, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #0x2e]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	lsls r1, r0, #2
	adds r0, r1, #0
	cmp r1, #0
	bge _081073F4
	adds r0, #0xff
_081073F4:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08107406
	movs r0, #0
	strh r0, [r4, #0x30]
_08107406:
	movs r0, #0x30
	ldrsh r2, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _08107414
	adds r0, #3
_08107414:
	asrs r0, r0, #2
	movs r1, #0x1e
	subs r1, r1, r0
	adds r0, r2, #0
	bl Cos
	strh r0, [r4, #0x24]
	movs r0, #0x30
	ldrsh r2, [r4, r0]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _08107430
	adds r0, #7
_08107430:
	asrs r0, r0, #3
	movs r1, #0xa
	subs r1, r1, r0
	adds r0, r2, #0
	bl Sin
	strh r0, [r4, #0x26]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	cmp r0, #0x80
	ble _08107454
	ldrh r1, [r4, #0x32]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _08107454
	ldr r0, _081074A8
	strh r0, [r4, #0x32]
_08107454:
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08107468
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _08107468
	movs r0, #1
	strh r0, [r4, #0x32]
_08107468:
	ldrh r0, [r4, #0x34]
	adds r1, r0, #1
	strh r1, [r4, #0x34]
	subs r0, #9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x46
	bls _081074AC
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r3, r4, #0
	adds r3, #0x3e
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _081074BA
	.align 2, 0
_081074A0: .4byte 0x020380BE
_081074A4: .4byte 0x020380D7
_081074A8: .4byte 0x0000FFFF
_081074AC:
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_081074BA:
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	cmp r0, #0x5a
	ble _081074C8
	adds r0, r4, #0
	bl DestroyAnimSprite
_081074C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081073A4

	thumb_func_start sub_081074D0
sub_081074D0: @ 0x081074D0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08107504
	ldr r1, _08107500
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #0x22]
	adds r0, r0, r2
	strh r0, [r4, #0x22]
	ldrb r1, [r1, #4]
	adds r0, r4, #0
	bl StartSpriteAnim
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	b _08107518
	.align 2, 0
_08107500: .4byte 0x020380BE
_08107504:
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08107518
	adds r0, r4, #0
	bl DestroyAnimSprite
_08107518:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081074D0

	thumb_func_start sub_08107520
sub_08107520: @ 0x08107520
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08107538
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _0810753C
	adds r0, r5, #0
	bl DestroyAnimSprite
	b _081075A0
	.align 2, 0
_08107538: .4byte 0x020380BE
_0810753C:
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _0810754C
	ldr r4, _08107548
	b _0810754E
	.align 2, 0
_08107548: .4byte 0x020380D6
_0810754C:
	ldr r4, _0810757C
_0810754E:
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x22]
	ldr r0, _08107580
	movs r2, #2
	ldrsh r1, [r0, r2]
	adds r2, r0, #0
	cmp r1, #0
	bne _08107584
	ldrh r0, [r5, #0x20]
	adds r0, #0x20
	b _08107588
	.align 2, 0
_0810757C: .4byte 0x020380D7
_08107580: .4byte 0x020380BE
_08107584:
	ldrh r0, [r5, #0x20]
	subs r0, #0x20
_08107588:
	strh r0, [r5, #0x20]
	ldrh r0, [r2, #4]
	strh r0, [r5, #0x2e]
	ldrh r1, [r2, #2]
	strh r1, [r5, #0x30]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl StartSpriteAnim
	ldr r0, _081075A8
	str r0, [r5, #0x1c]
_081075A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081075A8: .4byte 0x081075AD
	thumb_func_end sub_08107520

	thumb_func_start sub_081075AC
sub_081075AC: @ 0x081075AC
	push {lr}
	adds r2, r0, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081075DC
	ldrh r0, [r2, #0x2e]
	subs r0, #1
	strh r0, [r2, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _081075D6
	ldrh r1, [r2, #0x30]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r2, #0
	bl StartSpriteAnim
	b _081075DC
_081075D6:
	adds r0, r2, #0
	bl DestroyAnimSprite
_081075DC:
	pop {r0}
	bx r0
	thumb_func_end sub_081075AC

	thumb_func_start sub_081075E0
sub_081075E0: @ 0x081075E0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _08107614
	ldrb r0, [r0]
	bl GetAnimBattlerSpriteId
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	ldr r0, _08107618
	adds r4, r4, r0
	ldr r2, _0810761C
	adds r0, r4, #0
	bl PrepareAffineAnimInTaskData
	ldr r0, _08107620
	str r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08107614: .4byte 0x020380BE
_08107618: .4byte 0x03005B60
_0810761C: .4byte 0x0856F77C
_08107620: .4byte 0x08107625
	thumb_func_end sub_081075E0

	thumb_func_start sub_08107624
sub_08107624: @ 0x08107624
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _0810764C
	adds r0, r0, r1
	bl RunAffineAnimFromTaskData
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08107644
	adds r0, r4, #0
	bl DestroyAnimVisualTask
_08107644:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0810764C: .4byte 0x03005B60
	thumb_func_end sub_08107624

	thumb_func_start sub_08107650
sub_08107650: @ 0x08107650
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08107664
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0810766C
	ldr r0, _08107668
	b _0810766E
	.align 2, 0
_08107664: .4byte 0x020380BE
_08107668: .4byte 0x020380D6
_0810766C:
	ldr r0, _08107704
_0810766E:
	ldrb r6, [r0]
	adds r0, r6, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08107688
	ldr r1, _08107708
	movs r2, #2
	ldrsh r0, [r1, r2]
	rsbs r0, r0, #0
	strh r0, [r1, #2]
_08107688:
	adds r0, r6, #0
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	ldr r7, _08107708
	lsrs r0, r0, #0x18
	ldrh r3, [r7, #2]
	adds r0, r0, r3
	movs r4, #0
	strh r0, [r5, #0x20]
	adds r0, r6, #0
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r7, #4]
	adds r0, r0, r1
	strh r0, [r5, #0x22]
	strh r4, [r5, #0x2e]
	ldrh r1, [r5, #0x20]
	lsls r1, r1, #3
	strh r1, [r5, #0x30]
	lsls r0, r0, #3
	strh r0, [r5, #0x32]
	movs r2, #2
	ldrsh r0, [r7, r2]
	lsls r0, r0, #3
	cmp r0, #0
	bge _081076C8
	adds r0, #7
_081076C8:
	asrs r0, r0, #3
	strh r0, [r5, #0x34]
	movs r3, #4
	ldrsh r0, [r7, r3]
	lsls r0, r0, #3
	cmp r0, #0
	bge _081076D8
	adds r0, #7
_081076D8:
	asrs r0, r0, #3
	strh r0, [r5, #0x36]
	ldrh r2, [r5, #4]
	lsls r1, r2, #0x16
	lsrs r1, r1, #0x16
	movs r3, #6
	ldrsh r0, [r7, r3]
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r3, _0810770C
	adds r0, r3, #0
	ands r1, r0
	ldr r0, _08107710
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #4]
	ldr r0, _08107714
	str r0, [r5, #0x1c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08107704: .4byte 0x020380D7
_08107708: .4byte 0x020380BE
_0810770C: .4byte 0x000003FF
_08107710: .4byte 0xFFFFFC00
_08107714: .4byte 0x08107719
	thumb_func_end sub_08107650

	thumb_func_start sub_08107718
sub_08107718: @ 0x08107718
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x34]
	ldrh r1, [r2, #0x30]
	adds r0, r0, r1
	strh r0, [r2, #0x30]
	ldrh r1, [r2, #0x36]
	ldrh r3, [r2, #0x32]
	adds r1, r1, r3
	strh r1, [r2, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	strh r0, [r2, #0x20]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	strh r1, [r2, #0x22]
	ldrh r0, [r2, #0x2e]
	adds r0, #1
	strh r0, [r2, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble _0810774C
	adds r0, r2, #0
	bl DestroyAnimSprite
_0810774C:
	pop {r0}
	bx r0
	thumb_func_end sub_08107718

	thumb_func_start sub_08107750
sub_08107750: @ 0x08107750
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08107772
	ldr r0, _081077AC
	ldrh r1, [r0]
	movs r0, #0x78
	subs r0, r0, r1
	strh r0, [r4, #0x30]
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
_08107772:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08107790
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	adds r0, #0x10
	movs r1, #0
	bl SetGreyscaleOrOriginalPalette
_08107790:
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	adds r0, #0x50
	cmp r1, r0
	bne _081077A4
	adds r0, r4, #0
	bl DestroyAnimSprite
_081077A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081077AC: .4byte 0x020380BE
	thumb_func_end sub_08107750

	thumb_func_start sub_081077B0
sub_081077B0: @ 0x081077B0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _081077DE
	movs r5, #0x78
	strh r5, [r6, #0x20]
	ldr r4, _08107860
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	subs r0, #0xf
	strh r0, [r6, #0x22]
	ldrb r1, [r4, #2]
	adds r0, r6, #0
	bl StartSpriteAnim
	strh r5, [r6, #0x38]
	ldrh r0, [r4, #4]
	strh r0, [r6, #0x34]
_081077DE:
	ldrh r0, [r6, #0x2e]
	adds r0, #1
	movs r5, #0
	strh r0, [r6, #0x2e]
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r6, #0x30]
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	lsls r4, r0, #1
	adds r4, r4, r0
	ldrh r0, [r6, #0x34]
	adds r4, r4, r0
	movs r2, #0xff
	ldrh r0, [r6, #0x3a]
	adds r0, #0xa
	movs r1, #0xff
	ands r0, r1
	strh r0, [r6, #0x3a]
	ands r4, r2
	adds r0, r4, #0
	movs r1, #0x64
	bl Cos
	strh r0, [r6, #0x24]
	adds r0, r4, #0
	movs r1, #0xa
	bl Sin
	adds r4, r0, #0
	movs r1, #0x3a
	ldrsh r0, [r6, r1]
	movs r1, #4
	bl Cos
	ldrh r2, [r6, #0x30]
	adds r4, r4, r2
	adds r0, r0, r4
	strh r0, [r6, #0x26]
	movs r0, #0x2e
	ldrsh r1, [r6, r0]
	movs r2, #0x38
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0810785A
	ldr r0, _08107864
	str r0, [r6, #0x1c]
	strh r5, [r6, #0x2e]
	adds r0, r6, #0
	bl SetSpritePrimaryCoordsFromSecondaryCoords
	movs r0, #5
	strh r0, [r6, #0x32]
	strh r5, [r6, #0x36]
	strh r5, [r6, #0x34]
	adds r0, r6, #0
	movs r1, #1
	bl StartSpriteAffineAnim
_0810785A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08107860: .4byte 0x020380BE
_08107864: .4byte 0x08107869
	thumb_func_end sub_081077B0

	thumb_func_start sub_08107868
sub_08107868: @ 0x08107868
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2e]
	adds r0, #1
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble _08107882
	movs r0, #0
	strh r0, [r1, #0x2e]
	ldr r0, _08107888
	str r0, [r1, #0x1c]
_08107882:
	pop {r0}
	bx r0
	.align 2, 0
_08107888: .4byte 0x0810788D
	thumb_func_end sub_08107868

	thumb_func_start sub_0810788C
sub_0810788C: @ 0x0810788C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x32]
	ldrh r2, [r4, #0x34]
	adds r0, r1, r2
	strh r0, [r4, #0x34]
	strh r0, [r4, #0x26]
	adds r1, #1
	strh r1, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x30
	ble _081078B6
	lsls r0, r1, #0x10
	cmp r0, #0
	ble _081078B6
	ldrh r0, [r4, #0x36]
	subs r1, r0, #5
	strh r1, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x36]
_081078B6:
	movs r1, #0x36
	ldrsh r0, [r4, r1]
	cmp r0, #3
	ble _081078E8
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r1, r1, r0
	adds r3, r4, #0
	adds r3, #0x3e
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r0, r4, #0
	bl DestroyAnimSprite
_081078E8:
	movs r1, #0x36
	ldrsh r0, [r4, r1]
	cmp r0, #4
	bne _081078F6
	adds r0, r4, #0
	bl DestroyAnimSprite
_081078F6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0810788C

	thumb_func_start sub_081078FC
sub_081078FC: @ 0x081078FC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08107940
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08107948
	ldr r4, _08107944
	ldrb r1, [r4]
	movs r0, #2
	eors r0, r1
	bl IsBattlerSpriteVisible
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08107948
	ldrb r0, [r4]
	adds r2, r5, #0
	adds r2, #0x20
	adds r3, r5, #0
	adds r3, #0x22
	movs r1, #0
	bl SetAverageBattlerPositions
	ldrh r0, [r5, #0x22]
	adds r0, #0x28
	strh r0, [r5, #0x22]
	adds r0, r5, #0
	movs r1, #1
	bl StartSpriteAffineAnim
	b _08107968
	.align 2, 0
_08107940: .4byte 0x02022C90
_08107944: .4byte 0x020380D6
_08107948:
	ldr r4, _08107988
	ldrb r0, [r4]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x28
	strh r0, [r5, #0x22]
_08107968:
	movs r0, #0xd
	strh r0, [r5, #0x2e]
	ldrh r0, [r5, #0x20]
	strh r0, [r5, #0x32]
	ldrh r0, [r5, #0x22]
	subs r0, #0x48
	strh r0, [r5, #0x36]
	ldr r0, _0810798C
	str r0, [r5, #0x1c]
	ldr r1, _08107990
	adds r0, r5, #0
	bl StoreSpriteCallbackInData6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08107988: .4byte 0x020380D6
_0810798C: .4byte 0x080A67B5
_08107990: .4byte 0x080A34C5
	thumb_func_end sub_081078FC

	thumb_func_start AnimTask_IsFuryCutterHitRight
AnimTask_IsFuryCutterHitRight: @ 0x08107994
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _081079B0
	ldr r1, _081079B4
	ldr r1, [r1]
	ldrb r2, [r1, #0x10]
	movs r1, #1
	ands r1, r2
	strh r1, [r3, #0xe]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.align 2, 0
_081079B0: .4byte 0x020380BE
_081079B4: .4byte 0x020380A0
	thumb_func_end AnimTask_IsFuryCutterHitRight

	thumb_func_start AnimTask_GetFuryCutterHitCount
AnimTask_GetFuryCutterHitCount: @ 0x081079B8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _081079D0
	ldr r1, _081079D4
	ldr r1, [r1]
	ldrb r1, [r1, #0x10]
	strh r1, [r2, #0xe]
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.align 2, 0
_081079D0: .4byte 0x020380BE
_081079D4: .4byte 0x020380A0
	thumb_func_end AnimTask_GetFuryCutterHitCount
