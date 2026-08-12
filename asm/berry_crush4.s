.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified















	thumb_func_start sub_08023444
sub_08023444: @ 0x08023444
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r3, _080234DC
	ldrh r1, [r3, #0x2e]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08023466
	adds r2, r5, #0
	adds r2, #0x5e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
_08023466:
	ldrh r1, [r3, #0x2c]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0802348A
	ldrb r1, [r5, #8]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r1, r0, #0
	adds r1, #0xae
	ldrh r0, [r1]
	ldrh r2, [r5, #0x28]
	cmp r0, r2
	bhs _0802348A
	adds r0, #1
	strh r0, [r1]
_0802348A:
	ldrb r0, [r5, #8]
	adds r7, r5, #0
	adds r7, #0x5e
	cmp r0, #0
	beq _080234A0
	ldrb r1, [r7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080234A0
	b _080235DC
_080234A0:
	adds r4, r5, #0
	adds r4, #0x5c
	movs r0, #2
	strh r0, [r4]
	ldrh r0, [r5, #0x28]
	movs r1, #0x1e
	bl __umodsi3
	lsls r0, r0, #0x10
	mov r8, r4
	adds r6, r5, #0
	adds r6, #0x25
	cmp r0, #0
	bne _080234F8
	movs r0, #0x2e
	ldrsh r2, [r5, r0]
	ldr r1, _080234E0
	ldrb r0, [r5, #9]
	subs r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	ble _080234E4
	ldrh r0, [r5, #0x30]
	adds r0, #1
	strh r0, [r5, #0x30]
	ldrb r0, [r6]
	movs r1, #0x10
	orrs r0, r1
	b _080234EC
	.align 2, 0
_080234DC: .4byte 0x03002360
_080234E0: .4byte 0x082C7CD0
_080234E4:
	ldrb r1, [r6]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
_080234EC:
	strb r0, [r6]
	movs r0, #0
	strh r0, [r5, #0x2e]
	ldrh r0, [r5, #0x32]
	adds r0, #1
	strh r0, [r5, #0x32]
_080234F8:
	ldrh r0, [r5, #0x28]
	movs r1, #0xf
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0802356E
	movs r0, #0x34
	ldrsh r2, [r5, r0]
	ldr r3, _08023524
	ldrb r0, [r5, #9]
	subs r0, #2
	lsls r1, r0, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bge _08023528
	ldrb r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	strb r0, [r6]
	b _08023568
	.align 2, 0
_08023524: .4byte 0x082C7CC0
_08023528:
	adds r0, r3, #1
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _0802353C
	ldrb r0, [r6]
	movs r1, #0x1f
	ands r1, r0
	movs r0, #0x20
	b _08023564
_0802353C:
	adds r0, r3, #2
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _0802354C
	movs r0, #2
	strh r0, [r5, #0x34]
	b _08023568
_0802354C:
	adds r0, r3, #3
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _0802355C
	movs r0, #3
	strh r0, [r5, #0x34]
	b _08023568
_0802355C:
	ldrb r0, [r6]
	movs r1, #0x1f
	ands r1, r0
	movs r0, #0x80
_08023564:
	orrs r1, r0
	strb r1, [r6]
_08023568:
	movs r0, #0
	strh r0, [r5, #0x34]
	b _0802359A
_0802356E:
	ldrh r0, [r5, #0x10]
	adds r0, #1
	strh r0, [r5, #0x10]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bls _0802359A
	cmp r0, #0x46
	bls _0802358A
	bl ClearRecvCommands
	movs r0, #0
	strh r0, [r5, #0x10]
	b _0802359A
_0802358A:
	ldrb r0, [r7]
	movs r4, #0xf8
	ands r4, r0
	cmp r4, #0
	bne _0802359A
	bl ClearRecvCommands
	strh r4, [r5, #0x10]
_0802359A:
	ldrh r1, [r5, #0x28]
	ldr r0, _080235E8
	cmp r1, r0
	bls _080235AA
	ldrb r0, [r7]
	movs r1, #1
	orrs r0, r1
	strb r0, [r7]
_080235AA:
	ldrb r1, [r6]
	lsls r1, r1, #0x1b
	lsrs r1, r1, #0x1f
	lsls r1, r1, #1
	ldrb r2, [r7]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r7]
	ldrb r0, [r6]
	lsrs r0, r0, #5
	adds r2, r5, #0
	adds r2, #0x66
	strh r0, [r2]
	adds r4, r5, #0
	adds r4, #0x42
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0xc
	bl memcpy
	adds r0, r4, #0
	bl Rfu_SendPacket
_080235DC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080235E8: .4byte 0x00008C9F
	thumb_func_end sub_08023444

	thumb_func_start sub_080235EC
sub_080235EC: @ 0x080235EC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r3, _0802363C
	ldrb r0, [r5, #9]
	cmp r4, r0
	bhs _08023614
	movs r1, #0
_080235FC:
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r0, #0xb1
	strb r1, [r0]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldrb r0, [r5, #9]
	cmp r4, r0
	blo _080235FC
_08023614:
	adds r2, r3, #0
	ldrh r0, [r2]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xbc
	lsls r0, r0, #6
	cmp r1, r0
	bne _0802362C
	ldrh r0, [r2, #2]
	cmp r0, #2
	beq _08023640
_0802362C:
	adds r2, r5, #0
	adds r2, #0x25
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	b _0802367E
	.align 2, 0
_0802363C: .4byte 0x03003130
_08023640:
	adds r4, r5, #0
	adds r4, #0x4e
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0xe
	bl memcpy
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x2a]
	movs r0, #5
	ldrsb r0, [r4, r0]
	strh r0, [r5, #0x2c]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x28]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	bl sub_08021410
	ldrb r1, [r4, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802367E
	adds r0, r5, #0
	adds r0, #0x25
	ldrb r1, [r0]
	movs r2, #8
	orrs r1, r2
	strb r1, [r0]
_0802367E:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_080235EC

	thumb_func_start sub_08023684
sub_08023684: @ 0x08023684
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x5c
	movs r1, #0
	movs r2, #0xc
	bl memset
	adds r0, r4, #0
	adds r0, #0x4e
	movs r1, #0
	movs r2, #0xe
	bl memset
	adds r0, r4, #0
	bl sub_080235EC
	ldrh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x12
	bl SetGpuReg
	ldrh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x1a
	bl SetGpuReg
	ldrh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x1e
	bl SetGpuReg
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0802370C
	ldrh r1, [r4, #0x28]
	ldr r0, _080236F4
	cmp r1, r0
	bls _080236F8
	adds r0, #1
	strh r0, [r4, #0x28]
	movs r0, #0x10
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	b _08023702
	.align 2, 0
_080236F4: .4byte 0x00008C9F
_080236F8:
	movs r0, #0xf
	movs r1, #1
	movs r2, #0
	bl sub_08022950
_08023702:
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x10]
	strb r1, [r4, #0xc]
	b _08023726
_0802370C:
	ldrh r0, [r4, #0x26]
	adds r0, #1
	strh r0, [r4, #0x26]
	adds r0, r4, #0
	bl sub_08023108
	adds r0, r4, #0
	bl sub_080232E0
	adds r0, r4, #0
	bl sub_08023444
	movs r0, #0
_08023726:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_08023684

	thumb_func_start sub_0802372C
sub_0802372C: @ 0x0802372C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x5c
	movs r1, #0
	movs r2, #0xc
	bl memset
	adds r0, r4, #0
	adds r0, #0x4e
	movs r1, #0
	movs r2, #0xe
	bl memset
	adds r0, r4, #0
	bl sub_080235EC
	ldrh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x12
	bl SetGpuReg
	ldrh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x1a
	bl SetGpuReg
	ldrh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x1e
	bl SetGpuReg
	adds r0, r4, #0
	adds r0, #0x25
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080237B4
	ldrh r1, [r4, #0x28]
	ldr r0, _0802379C
	cmp r1, r0
	bls _080237A0
	adds r0, #1
	strh r0, [r4, #0x28]
	movs r0, #0x10
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	b _080237AA
	.align 2, 0
_0802379C: .4byte 0x00008C9F
_080237A0:
	movs r0, #0xf
	movs r1, #1
	movs r2, #0
	bl sub_08022950
_080237AA:
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x10]
	strb r1, [r4, #0xc]
	b _080237BC
_080237B4:
	adds r0, r4, #0
	bl sub_08023444
	movs r0, #0
_080237BC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802372C

	thumb_func_start sub_080237C4
sub_080237C4: @ 0x080237C4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xc]
	cmp r0, #5
	bls _080237D0
	b _08023946
_080237D0:
	lsls r0, r0, #2
	ldr r1, _080237DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080237DC: .4byte 0x080237E0
_080237E0: @ jump table
	.4byte _080237F8 @ case 0
	.4byte _08023820 @ case 1
	.4byte _08023870 @ case 2
	.4byte _080238F0 @ case 3
	.4byte _0802390E @ case 4
	.4byte _08023928 @ case 5
_080237F8:
	movs r0, #8
	strh r0, [r4, #0x12]
	movs r0, #0xd6
	bl PlaySE
	movs r0, #1
	rsbs r0, r0, #0
	ldr r2, _0802381C
	movs r1, #8
	bl BlendPalettes
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	b _08023946
	.align 2, 0
_0802381C: .4byte 0x000003FF
_08023820:
	movs r1, #0x92
	lsls r1, r1, #1
	adds r5, r4, r1
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _08023836
	b _0802394C
_08023836:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r2, _08023864
	movs r1, #0
	bl BlendPalettes
	ldr r2, _08023868
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	movs r0, #0
	strb r0, [r5]
	ldr r2, _0802386C
	ldrb r1, [r1]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	b _08023946
	.align 2, 0
_08023864: .4byte 0x000003FF
_08023868: .4byte 0x00000125
_0802386C: .4byte 0x082C5E84
_08023870:
	ldr r7, _080238E8
	movs r0, #0x92
	lsls r0, r0, #1
	adds r6, r4, r0
	ldr r1, _080238EC
	adds r5, r4, r1
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	ldrb r2, [r6]
	adds r0, r0, r2
	adds r0, r0, r7
	movs r1, #0
	ldrsb r1, [r0, r1]
	strh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x12
	bl SetGpuReg
	ldrh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x1a
	bl SetGpuReg
	ldrh r1, [r4, #0x2c]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x1e
	bl SetGpuReg
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r1, #0x93
	lsls r1, r1, #1
	adds r2, r4, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r2]
	cmp r0, r1
	blo _0802394C
	ldrb r0, [r5]
	cmp r0, #0
	beq _08023946
	subs r0, #1
	strb r0, [r5]
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r7
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, #0
	strb r0, [r6]
	b _0802394C
	.align 2, 0
_080238E8: .4byte 0x082C5E84
_080238EC: .4byte 0x00000125
_080238F0:
	movs r0, #0
	strh r0, [r4, #0x2c]
	movs r0, #0x12
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1a
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1e
	movs r1, #0
	bl SetGpuReg
	b _08023946
_0802390E:
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r4, r2
	adds r0, r4, #0
	bl sub_08021604
	cmp r0, #0
	beq _0802394C
	bl Rfu_SetLinkStandbyCallback
	movs r0, #0
	strh r0, [r4, #0x10]
	b _08023946
_08023928:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802394C
	movs r0, #0x11
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x10]
	strb r1, [r4, #0xc]
	b _0802394E
_08023946:
	ldrb r0, [r4, #0xc]
	adds r0, #1
	strb r0, [r4, #0xc]
_0802394C:
	movs r0, #0
_0802394E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080237C4

	thumb_func_start sub_08023954
sub_08023954: @ 0x08023954
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	beq _08023998
	cmp r0, #1
	bgt _0802396C
	cmp r0, #0
	beq _08023976
	b _08023A30
_0802396C:
	cmp r0, #2
	beq _080239BE
	cmp r0, #3
	beq _080239F0
	b _08023A30
_08023976:
	movs r0, #9
	strh r0, [r5, #0x12]
	movs r0, #0x20
	bl PlaySE
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #8
	movs r2, #0x1f
	bl BlendPalettes
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	b _08023A30
_08023998:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08023A36
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	movs r2, #0x1f
	bl BlendPalettes
	movs r0, #0
	strb r0, [r4]
	b _08023A30
_080239BE:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	bl sub_08021604
	cmp r0, #0
	beq _08023A36
	bl Rfu_SetLinkStandbyCallback
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r0, #0x12
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1a
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1e
	movs r1, #0
	bl SetGpuReg
	b _08023A30
_080239F0:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08023A36
	ldr r0, _08023A2C
	ldr r1, [r5, #0x1c]
	movs r2, #0
	movs r3, #6
	bl ConvertIntToDecimalStringN
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl sub_08024410
	movs r0, #0x13
	strb r0, [r5, #0xe]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r0, #0
	strh r4, [r5, #0x10]
	b _08023A34
	.align 2, 0
_08023A2C: .4byte 0x02021C40
_08023A30:
	ldrb r0, [r5, #0xc]
	adds r0, #1
_08023A34:
	strb r0, [r5, #0xc]
_08023A36:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_08023954

	thumb_func_start sub_08023A40
sub_08023A40: @ 0x08023A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	ldrb r0, [r0, #0xc]
	cmp r0, #7
	bls _08023A56
	b _08023DF4
_08023A56:
	lsls r0, r0, #2
	ldr r1, _08023A60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08023A60: .4byte 0x08023A64
_08023A64: @ jump table
	.4byte _08023A84 @ case 0
	.4byte _08023ACA @ case 1
	.4byte _08023ADE @ case 2
	.4byte _08023B52 @ case 3
	.4byte _08023CE2 @ case 4
	.4byte _08023D8E @ case 5
	.4byte _08023DA0 @ case 6
	.4byte _08023DD4 @ case 7
_08023A84:
	mov r4, r8
	adds r4, #0x42
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	bl memset
	mov r1, r8
	ldrb r0, [r1, #8]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, r8
	adds r1, #0xae
	mov r3, r8
	ldrh r2, [r3, #0x28]
	ldrh r0, [r1]
	cmp r0, r2
	bls _08023AAC
	strh r2, [r1]
_08023AAC:
	mov r5, r8
	ldrb r0, [r5, #8]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, r8
	adds r1, #0xae
	ldrh r0, [r1]
	strh r0, [r4]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #2
	bl SendBlock
	b _08023DF4
_08023ACA:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08023AD6
	b _08023DFC
_08023AD6:
	movs r0, #0
	mov r6, r8
	strh r0, [r6, #0x10]
	b _08023DF4
_08023ADE:
	bl GetBlockReceivedStatus
	ldr r2, _08023B44
	mov r1, r8
	ldrb r3, [r1, #9]
	subs r1, r3, #2
	adds r1, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	beq _08023AF8
	b _08023DFC
_08023AF8:
	movs r2, #0
	mov sb, r2
	mov r4, r8
	adds r4, #0x42
	cmp sb, r3
	bhs _08023B2C
	ldr r2, _08023B48
_08023B06:
	mov r3, sb
	lsls r1, r3, #3
	subs r1, r1, r3
	lsls r1, r1, #2
	add r1, r8
	lsls r0, r3, #8
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #0xae
	strh r0, [r1]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	mov r5, r8
	ldrb r5, [r5, #9]
	cmp sb, r5
	blo _08023B06
_08023B2C:
	movs r0, #0
	mov r6, r8
	strh r0, [r6, #0x10]
	strh r0, [r4]
	bl ResetBlockReceivedFlags
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _08023B4C
	movs r0, #3
	strb r0, [r6, #0xc]
	b _08023DFC
	.align 2, 0
_08023B44: .4byte 0x082C7CD4
_08023B48: .4byte 0x0202207C
_08023B4C:
	movs r0, #6
	mov r1, r8
	b _08023DFA
_08023B52:
	mov r0, r8
	adds r0, #0x68
	movs r1, #0
	movs r2, #0x30
	bl memset
	mov r2, r8
	ldrh r1, [r2, #0x28]
	mov r0, r8
	adds r0, #0x6c
	strh r1, [r0]
	movs r3, #0x18
	ldrsh r4, [r2, r3]
	ldrh r0, [r2, #0x28]
	movs r1, #0x3c
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl __divsi3
	mov r1, r8
	adds r1, #0x6e
	strh r0, [r1]
	mov r5, r8
	movs r6, #0x30
	ldrsh r0, [r5, r6]
	lsls r0, r0, #8
	movs r4, #0xc8
	lsls r4, r4, #6
	adds r1, r4, #0
	bl MathUtil_Mul32
	adds r2, r0, #0
	movs r0, #0x32
	ldrsh r1, [r5, r0]
	lsls r1, r1, #8
	adds r0, r2, #0
	bl MathUtil_Div32
	adds r2, r0, r4
	asrs r2, r2, #8
	movs r1, #0x7f
	adds r0, r2, #0
	ands r0, r1
	mov r1, r8
	adds r1, #0x70
	strh r0, [r1]
	lsls r2, r2, #8
	movs r1, #0xc8
	lsls r1, r1, #7
	adds r0, r2, #0
	bl MathUtil_Div32
	adds r2, r0, #0
	ldrb r1, [r5, #9]
	ldr r0, [r5, #0x1c]
	muls r0, r1, r0
	lsls r4, r0, #8
	adds r0, r4, #0
	adds r1, r2, #0
	bl MathUtil_Mul32
	adds r4, r0, #0
	asrs r0, r4, #8
	str r0, [r5, #0x68]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	mov r1, r8
	adds r1, #0x8f
	strb r0, [r1]
	movs r2, #0
	mov sb, r2
	adds r7, r1, #0
	ldrb r3, [r5, #9]
	cmp sb, r3
	blo _08023BFC
	b _08023DF4
_08023BFC:
	mov r0, r8
	adds r0, #0x88
	add r0, sb
	mov r5, sb
	strb r5, [r0]
	mov r0, r8
	adds r0, #0x90
	add r0, sb
	strb r5, [r0]
	mov r6, sb
	lsls r2, r6, #1
	mov r1, r8
	adds r1, #0x74
	adds r1, r1, r2
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #2
	mov r5, r8
	adds r3, r5, r0
	adds r5, r3, #0
	adds r5, #0xaa
	ldrh r0, [r5]
	strh r0, [r1]
	mov r1, r8
	adds r1, #0x72
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	ldrb r0, [r7]
	adds r6, r2, #0
	cmp r0, #1
	beq _08023C6A
	cmp r0, #1
	bgt _08023C46
	cmp r0, #0
	beq _08023C4C
	b _08023CC4
_08023C46:
	cmp r0, #2
	beq _08023C88
	b _08023CC4
_08023C4C:
	ldrh r0, [r5]
	cmp r0, #0
	beq _08023C8E
	adds r0, r3, #0
	adds r0, #0xa8
	ldrh r2, [r0]
	lsls r2, r2, #8
	adds r0, r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	bl MathUtil_Mul32
	adds r2, r0, #0
	ldrh r4, [r5]
	b _08023CBA
_08023C6A:
	ldrh r0, [r5]
	cmp r0, #0
	beq _08023C8E
	adds r0, r3, #0
	adds r0, #0xac
	ldrh r2, [r0]
	lsls r2, r2, #8
	adds r0, r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	bl MathUtil_Mul32
	adds r2, r0, #0
	ldrh r4, [r5]
	b _08023CBA
_08023C88:
	ldrh r0, [r5]
	cmp r0, #0
	bne _08023C92
_08023C8E:
	movs r4, #0
	b _08023CC4
_08023C92:
	adds r1, r3, #0
	adds r1, #0xae
	ldrh r0, [r1]
	mov r2, r8
	ldrh r2, [r2, #0x28]
	cmp r0, r2
	blo _08023CA6
	movs r4, #0xc8
	lsls r4, r4, #7
	b _08023CC4
_08023CA6:
	ldrh r2, [r1]
	lsls r2, r2, #8
	adds r0, r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	bl MathUtil_Mul32
	adds r2, r0, #0
	mov r3, r8
	ldrh r4, [r3, #0x28]
_08023CBA:
	lsls r4, r4, #8
	adds r1, r4, #0
	bl MathUtil_Div32
	adds r4, r0, #0
_08023CC4:
	asrs r4, r4, #4
	mov r0, r8
	adds r0, #0x7e
	adds r0, r0, r6
	strh r4, [r0]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	mov r5, r8
	ldrb r5, [r5, #9]
	cmp sb, r5
	blo _08023BFC
	b _08023DF4
_08023CE2:
	movs r6, #0
	mov sb, r6
	mov r1, r8
	ldrb r0, [r1, #9]
	subs r0, #1
	adds r1, #0x68
	str r1, [sp, #0xc]
	cmp sb, r0
	bge _08023D82
_08023CF4:
	mov r2, r8
	ldrb r0, [r2, #9]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r3, sb
	adds r3, #1
	str r3, [sp, #8]
	cmp r4, sb
	bls _08023D70
	adds r2, #0x74
	str r2, [sp]
	mov r5, r8
	adds r5, #0x88
	str r5, [sp, #4]
	movs r6, #0x90
	add r6, r8
	mov sl, r6
	movs r0, #0x7e
	add r0, r8
	mov ip, r0
_08023D1E:
	subs r7, r4, #1
	lsls r6, r7, #1
	ldr r1, [sp]
	adds r3, r1, r6
	lsls r5, r4, #1
	adds r1, r1, r5
	ldrh r2, [r3]
	ldrh r0, [r1]
	cmp r2, r0
	bhs _08023D46
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	ldr r1, [sp, #4]
	adds r2, r1, r4
	ldrb r3, [r2]
	adds r1, r1, r7
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023D46:
	mov r2, ip
	adds r3, r2, r6
	adds r1, r2, r5
	ldrh r2, [r3]
	ldrh r5, [r1]
	cmp r2, r5
	bhs _08023D68
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	mov r6, sl
	adds r2, r6, r4
	ldrb r3, [r2]
	adds r1, r6, r7
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023D68:
	lsls r0, r7, #0x18
	lsrs r4, r0, #0x18
	cmp r4, sb
	bhi _08023D1E
_08023D70:
	ldr r1, [sp, #8]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	mov r2, r8
	ldrb r0, [r2, #9]
	subs r0, #1
	cmp sb, r0
	blt _08023CF4
_08023D82:
	movs r0, #0
	ldr r1, [sp, #0xc]
	movs r2, #0x30
	bl SendBlock
	b _08023DF4
_08023D8E:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08023DFC
	movs r0, #0
	mov r3, r8
	strh r0, [r3, #0x10]
	b _08023DF4
_08023DA0:
	bl GetBlockReceivedStatus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08023DFC
	mov r4, r8
	adds r4, #0x68
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x30
	bl memset
	ldr r1, _08023DD0
	adds r0, r4, #0
	movs r2, #0x30
	bl memcpy
	bl ResetBlockReceivedFlags
	movs r0, #0
	mov r5, r8
	strh r0, [r5, #0x10]
	b _08023DF4
	.align 2, 0
_08023DD0: .4byte 0x0202207C
_08023DD4:
	bl sub_08020B74
	movs r0, #0x12
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r0, #0
	movs r1, #0xb
	mov r6, r8
	strh r1, [r6, #0x12]
	strb r0, [r6, #0xc]
	mov r1, r8
	adds r1, #0x24
	strb r0, [r1]
	b _08023DFC
_08023DF4:
	mov r1, r8
	ldrb r0, [r1, #0xc]
	adds r0, #1
_08023DFA:
	strb r0, [r1, #0xc]
_08023DFC:
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08023A40

	thumb_func_start sub_08023E10
sub_08023E10: @ 0x08023E10
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bhi _08023EEC
	lsls r0, r0, #2
	ldr r1, _08023E28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08023E28: .4byte 0x08023E2C
_08023E2C: @ jump table
	.4byte _08023E40 @ case 0
	.4byte _08023E52 @ case 1
	.4byte _08023E64 @ case 2
	.4byte _08023E94 @ case 3
	.4byte _08023EA4 @ case 4
_08023E40:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	bl sub_08021DDC
	cmp r0, #0
	bne _08023EEC
	b _08023EF2
_08023E52:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x1e
	strb r0, [r1]
	b _08023EEC
_08023E64:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08023E76
	subs r0, #1
	strb r0, [r1]
	b _08023EF2
_08023E76:
	ldr r0, _08023E90
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08023EF2
	movs r0, #5
	bl PlaySE
	adds r0, r5, #0
	bl sub_08021F9C
	b _08023EEC
	.align 2, 0
_08023E90: .4byte 0x03002360
_08023E94:
	ldrh r0, [r5, #0x12]
	cmp r0, #0xc
	bhi _08023EEC
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0x12]
	strb r1, [r5, #0xc]
	b _08023EF2
_08023EA4:
	ldr r0, _08023EE4
	ldr r1, [r5, #0x1c]
	movs r2, #0
	movs r3, #6
	bl ConvertIntToDecimalStringN
	ldr r4, _08023EE8
	bl GetBerryPowder
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	movs r3, #6
	bl ConvertIntToDecimalStringN
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r1, #2
	movs r2, #3
	movs r3, #0
	bl sub_08024410
	movs r0, #0x13
	strb r0, [r5, #0xe]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _08023EF2
	.align 2, 0
_08023EE4: .4byte 0x02021C40
_08023EE8: .4byte 0x02021C54
_08023EEC:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_08023EF2:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_08023E10

	thumb_func_start sub_08023EFC
sub_08023EFC: @ 0x08023EFC
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bhi _08023FE0
	lsls r0, r0, #2
	ldr r1, _08023F14
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08023F14: .4byte 0x08023F18
_08023F18: @ jump table
	.4byte _08023F2C @ case 0
	.4byte _08023F68 @ case 1
	.4byte _08023F6E @ case 2
	.4byte _08023FB8 @ case 3
	.4byte _08023FCC @ case 4
_08023F2C:
	ldrh r1, [r5, #0x28]
	ldr r0, _08023F64
	cmp r1, r0
	bls _08023F3E
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r5, r1
	bl sub_080222B4
_08023F3E:
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl sub_08024410
	movs r4, #0
	movs r0, #0x13
	strb r0, [r5, #0xe]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _08023FE6
	.align 2, 0
_08023F64: .4byte 0x00008C9F
_08023F68:
	bl Rfu_SetLinkStandbyCallback
	b _08023FE0
_08023F6E:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08023FE6
	movs r0, #0
	movs r1, #0
	bl DrawDialogueFrame
	ldr r2, _08023FB0
	movs r0, #0
	str r0, [sp]
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
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	ldr r0, _08023FB4
	movs r1, #0
	bl CreateTask
	b _08023FE0
	.align 2, 0
_08023FB0: .4byte 0x08277071
_08023FB4: .4byte 0x081535C5
_08023FB8:
	ldr r0, _08023FC8
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08023FE0
	b _08023FE6
	.align 2, 0
_08023FC8: .4byte 0x081535C5
_08023FCC:
	movs r0, #0x14
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r1, #0
	movs r0, #0xf
	strh r0, [r5, #0x12]
	strb r1, [r5, #0xc]
	b _08023FE6
_08023FE0:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_08023FE6:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08023EFC

	thumb_func_start sub_08023FF0
sub_08023FF0: @ 0x08023FF0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	beq _08024032
	cmp r0, #1
	bgt _08024008
	cmp r0, #0
	beq _0802400E
	b _08024098
_08024008:
	cmp r0, #2
	beq _08024038
	b _08024098
_0802400E:
	movs r0, #1
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sub_08024410
	movs r0, #0x14
	strb r0, [r5, #0xe]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r0, #0
	strb r0, [r5, #0xc]
	b _080240A0
_08024032:
	bl DisplayYesNoMenuDefaultYes
	b _08024098
_08024038:
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	movs r0, #2
	rsbs r0, r0, #0
	cmp r4, r0
	beq _0802409E
	adds r0, r5, #0
	adds r0, #0x42
	movs r1, #0
	movs r2, #0xc
	bl memset
	cmp r4, #0
	bne _0802406A
	bl HasAtLeastOneBerry
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08024066
	strh r4, [r5, #0x14]
	b _0802406E
_08024066:
	movs r0, #3
	b _0802406C
_0802406A:
	movs r0, #1
_0802406C:
	strh r0, [r5, #0x14]
_0802406E:
	movs r0, #0
	movs r1, #1
	bl ClearDialogWindowAndFrame
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl sub_08024410
	movs r0, #0x15
	strb r0, [r5, #0xe]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _0802409E
_08024098:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_0802409E:
	movs r0, #0
_080240A0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_08023FF0

	thumb_func_start sub_080240A8
sub_080240A8: @ 0x080240A8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r5, #0
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	beq _080240CE
	cmp r0, #1
	bgt _080240BE
	cmp r0, #0
	beq _080240C8
	b _08024174
_080240BE:
	cmp r0, #2
	beq _080240F0
	cmp r0, #3
	beq _080240FE
	b _08024174
_080240C8:
	bl Rfu_SetLinkStandbyCallback
	b _08024174
_080240CE:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802417A
	ldrh r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x4e
	strh r5, [r0]
	movs r0, #0
	movs r2, #2
	bl SendBlock
	b _08024174
_080240F0:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802417A
	strh r5, [r4, #0x10]
	b _08024174
_080240FE:
	bl GetBlockReceivedStatus
	ldr r2, _08024150
	ldrb r3, [r4, #9]
	subs r1, r3, #2
	adds r1, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _0802417A
	adds r7, r4, #0
	adds r7, #0x42
	adds r6, r4, #0
	adds r6, #0x4e
	cmp r5, r3
	bhs _0802413C
	adds r1, r6, #0
	ldr r2, _08024154
_08024124:
	lsls r0, r5, #8
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r0, [r4, #9]
	cmp r5, r0
	blo _08024124
_0802413C:
	ldrh r0, [r6]
	cmp r0, #0
	beq _08024158
	movs r0, #0x17
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	b _08024162
	.align 2, 0
_08024150: .4byte 0x082C7CD4
_08024154: .4byte 0x0202207C
_08024158:
	movs r0, #0x16
	movs r1, #1
	movs r2, #0
	bl sub_08022950
_08024162:
	bl ResetBlockReceivedFlags
	movs r1, #0
	movs r0, #0
	strh r0, [r7]
	strh r0, [r6]
	strh r0, [r4, #0x10]
	strb r1, [r4, #0xc]
	b _0802417C
_08024174:
	ldrb r0, [r4, #0xc]
	adds r0, #1
	strb r0, [r4, #0xc]
_0802417A:
	movs r0, #0
_0802417C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080240A8

	thumb_func_start sub_08024184
sub_08024184: @ 0x08024184
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _080241B2
	cmp r4, #1
	bgt _0802419A
	cmp r4, #0
	beq _080241A4
	b _080241FC
_0802419A:
	cmp r4, #2
	beq _080241BE
	cmp r4, #3
	beq _080241E2
	b _080241FC
_080241A4:
	movs r0, #1
	rsbs r0, r0, #0
	str r4, [sp]
	movs r1, #1
	movs r2, #0
	movs r3, #0x10
	b _080241D8
_080241B2:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080241FC
	b _08024202
_080241BE:
	movs r0, #0
	movs r1, #1
	bl ClearDialogWindowAndFrame
	adds r0, r5, #0
	bl sub_080211B4
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0x10
	movs r3, #0
_080241D8:
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _080241FC
_080241E2:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08024202
	movs r0, #7
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r0, #0
	strh r4, [r5, #0x12]
	b _08024200
_080241FC:
	ldrb r0, [r5, #0xc]
	adds r0, #1
_08024200:
	strb r0, [r5, #0xc]
_08024202:
	movs r0, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08024184

	thumb_func_start sub_0802420C
sub_0802420C: @ 0x0802420C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _08024284
	cmp r4, #1
	bgt _08024222
	cmp r4, #0
	beq _08024228
	b _080242BE
_08024222:
	cmp r4, #2
	beq _0802429C
	b _080242BE
_08024228:
	movs r0, #0
	movs r1, #0
	bl DrawDialogueFrame
	ldrh r1, [r5, #0x14]
	cmp r1, #3
	bne _08024258
	ldr r0, _08024254
	ldr r2, [r0, #0x14]
	ldrb r3, [r5, #0xb]
	str r4, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	bl AddTextPrinterParameterized2
	b _08024274
	.align 2, 0
_08024254: .4byte 0x082C5EBC
_08024258:
	ldr r0, _08024280
	ldr r2, [r0, #0x18]
	ldrb r3, [r5, #0xb]
	str r4, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	bl AddTextPrinterParameterized2
_08024274:
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	b _080242BE
	.align 2, 0
_08024280: .4byte 0x082C5EBC
_08024284:
	movs r0, #0
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080242C4
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x78
	strb r0, [r1]
	b _080242BE
_0802429C:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq _080242B0
	subs r0, #1
	strb r0, [r1]
	b _080242C4
_080242B0:
	movs r0, #0x18
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _080242C4
_080242BE:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_080242C4:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802420C

	thumb_func_start sub_080242D0
sub_080242D0: @ 0x080242D0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _080242F0
	cmp r4, #1
	bgt _080242E4
	cmp r4, #0
	beq _080242EA
	b _08024320
_080242E4:
	cmp r4, #2
	beq _08024300
	b _08024320
_080242EA:
	bl Rfu_SetLinkStandbyCallback
	b _08024320
_080242F0:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08024326
	bl SetCloseLinkCallback
	b _08024320
_08024300:
	ldr r0, _0802431C
	ldrb r0, [r0]
	cmp r0, #0
	bne _08024326
	movs r0, #0x19
	strb r0, [r5, #0xe]
	movs r0, #5
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _08024326
	.align 2, 0
_0802431C: .4byte 0x030031C4
_08024320:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_08024326:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080242D0

	thumb_func_start sub_08024330
sub_08024330: @ 0x08024330
	push {lr}
	movs r0, #0
	bl sub_08020924
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08024330

	thumb_func_start sub_08024340
sub_08024340: @ 0x08024340
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r0, #0x33
	bl IncrementGameStat
	strb r5, [r4, #0xd]
	movs r1, #0
	strh r5, [r4, #0x10]
	movs r0, #2
	strh r0, [r4, #0x12]
	strh r5, [r4, #0x14]
	str r5, [r4, #0x1c]
	strh r5, [r4, #0x18]
	strh r5, [r4, #0x1a]
	str r5, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0
	strb r0, [r1]
	strh r5, [r4, #0x26]
	strh r5, [r4, #0x28]
	strh r5, [r4, #0x2e]
	ldr r0, _080243CC
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x30]
	strh r5, [r4, #0x34]
	movs r6, #0
	movs r3, #0
_08024380:
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r1, r2, #0
	adds r1, #0xa0
	ldr r0, _080243CC
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xa2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r1, #6
	movs r0, #1
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xa8
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _08024380
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080243CC: .4byte 0x0000FFFF
	thumb_func_end sub_08024340

	thumb_func_start sub_080243D0
sub_080243D0: @ 0x080243D0
	push {r4, r5, r6, lr}
	sub sp, #8
	str r2, [sp, #4]
	ldr r5, [sp, #0x18]
	ldr r6, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	mov r2, sp
	strh r4, [r2]
	add r4, sp, #4
	ldrb r2, [r4]
	strb r2, [r0]
	ldrb r2, [r4, #1]
	strb r2, [r0, #1]
	ldrb r2, [r4, #2]
	strb r2, [r0, #2]
	ldrb r2, [r4, #3]
	strb r2, [r0, #3]
	strb r3, [r0, #4]
	strb r5, [r0, #5]
	strb r6, [r0, #6]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0, #7]
	mov r2, sp
	ldrb r2, [r2, #1]
	strb r2, [r0, #8]
	strb r1, [r0, #9]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080243D0

	thumb_func_start sub_08024410
sub_08024410: @ 0x08024410
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, [sp, #0x10]
	mov r4, sp
	strh r3, [r4]
	strb r1, [r0]
	strb r2, [r0, #1]
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0, #2]
	mov r1, sp
	ldrb r1, [r1, #1]
	strb r1, [r0, #3]
	strb r5, [r0, #4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08024410
