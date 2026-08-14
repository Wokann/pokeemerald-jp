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


