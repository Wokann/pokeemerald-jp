.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start CreateStarterPokemonLabel
CreateStarterPokemonLabel: @ 0x08134480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r6, #0
	bl GetStarterPokemon
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r7, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_080BFB68
	adds r2, r0, #0
	movs r3, #0
	movs r5, #0
	ldrb r0, [r2]
	add r1, sp, #0x18
	mov sl, r1
	mov r1, sp
	adds r1, #0x24
	str r1, [sp, #0x2c]
	cmp r0, #0
	beq _081344E2
_081344BE:
	mov r1, sp
	adds r1, r1, r5
	adds r1, #0xc
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081344E2
	cmp r3, #4
	bls _081344BE
_081344E2:
	movs r3, #0
	ldr r2, _0813462C
	mov r8, r2
	lsls r4, r7, #1
	ldr r0, _08134630
	mov sb, r0
	lsls r6, r6, #1
	mov ip, r6
	ldr r2, _08134634
_081344F4:
	mov r1, sp
	adds r1, r1, r5
	adds r1, #0xc
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r3, #4
	bls _081344F4
	mov r1, sp
	adds r1, r1, r5
	adds r1, #0xc
	movs r0, #0xff
	strb r0, [r1]
	movs r3, #0
	movs r5, #0
	adds r0, r4, r7
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08134558
	mov r6, r8
	mov r8, sl
_0813452E:
	mov r1, r8
	adds r2, r1, r5
	adds r1, r4, r7
	lsls r1, r1, #1
	adds r0, r3, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	strb r0, [r2]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r1, r3, r1
	adds r1, r1, r6
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _08134558
	cmp r3, #9
	bls _0813452E
_08134558:
	mov r2, sl
	adds r1, r2, r5
	movs r0, #0xff
	strb r0, [r1]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	ldr r0, _08134638
	add r0, ip
	mov sb, r0
	ldrb r0, [r0]
	lsls r0, r0, #8
	ldr r1, _0813463C
	ldr r2, [sp, #0x24]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x24]
	ldr r1, _08134638
	adds r1, #1
	mov r8, r1
	add r8, ip
	mov r0, r8
	ldrb r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _08134640
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x2c]
	bl AddWindow
	ldr r4, _08134644
	strh r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl FillWindowPixelBuffer
	ldrb r0, [r4]
	ldr r6, _08134648
	str r6, [sp]
	movs r5, #0
	str r5, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl AddTextPrinterParameterized3
	ldrb r0, [r4]
	str r6, [sp]
	str r5, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0x12
	bl AddTextPrinterParameterized3
	ldrb r0, [r4]
	bl PutWindowTilemap
	movs r0, #0
	bl ScheduleBgCopyTilemapToVram
	mov r0, sb
	ldrb r1, [r0]
	lsls r0, r1, #0x1b
	movs r2, #0xfc
	lsls r2, r2, #0x18
	adds r0, r0, r2
	adds r1, #9
	lsls r1, r1, #3
	adds r1, #4
	lsls r1, r1, #0x18
	mov r2, r8
	ldrb r4, [r2]
	lsls r5, r4, #0x1b
	lsrs r5, r5, #0x18
	adds r4, #4
	lsls r4, r4, #0x1b
	lsrs r4, r4, #0x18
	lsrs r1, r1, #8
	orrs r1, r0
	lsrs r1, r1, #0x10
	movs r0, #0x40
	bl SetGpuReg
	lsls r5, r5, #8
	orrs r5, r4
	movs r0, #0x44
	adds r1, r5, #0
	bl SetGpuReg
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813462C: .4byte 0x082EA31C
_08134630: .4byte 0x08590BF4
_08134634: .4byte 0x085C9393
_08134638: .4byte 0x08590C02
_0813463C: .4byte 0xFFFF00FF
_08134640: .4byte 0xFF00FFFF
_08134644: .4byte 0x030011F8
_08134648: .4byte 0x08590C1C
	thumb_func_end CreateStarterPokemonLabel
