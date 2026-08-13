.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	.section .text.cable_car_rest,"ax",%progbits





	thumb_func_start sub_08150924
sub_08150924: @ 0x08150924
	thumb_func_start sub_08150A44
sub_08150A44: @ 0x08150A44
	thumb_func_start sub_08150AD0
sub_08150AD0: @ 0x08150AD0
	thumb_func_start sub_08150B48
sub_08150B48: @ 0x08150B48
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08150B56
	cmp r0, #1
	beq _08150BF8
_08150B56:
	movs r0, #0x48
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x4a
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x40
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x42
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x44
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x46
	movs r1, #0
	bl SetGpuReg
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	movs r0, #0xe
	movs r1, #0
	bl SetGpuReg
	movs r0, #0xc
	movs r1, #0
	bl SetGpuReg
	movs r0, #0xa
	movs r1, #0
	bl SetGpuReg
	movs r0, #8
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1c
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1e
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x18
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1a
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x14
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x16
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x10
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x12
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	b _08150CF8
_08150BF8:
	movs r0, #0x48
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x4a
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x40
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x42
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x44
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x46
	movs r1, #0
	bl SetGpuReg
	ldr r0, _08150C48
	ldrh r3, [r0]
	cmp r3, #0
	bne _08150C50
	ldr r1, _08150C4C
	ldr r2, [r1]
	movs r0, #0xb0
	strb r0, [r2, #0x14]
	ldr r2, [r1]
	movs r0, #0x10
	strb r0, [r2, #0x15]
	ldr r0, [r1]
	strb r3, [r0, #0xc]
	ldr r2, [r1]
	movs r0, #0x50
	b _08150C68
	.align 2, 0
_08150C48: .4byte 0x02037280
_08150C4C: .4byte 0x0203A878
_08150C50:
	ldr r1, _08150D00
	ldr r2, [r1]
	movs r3, #0
	movs r0, #0x60
	strb r0, [r2, #0x14]
	ldr r2, [r1]
	movs r0, #0xe8
	strb r0, [r2, #0x15]
	ldr r0, [r1]
	strb r3, [r0, #0xc]
	ldr r2, [r1]
	movs r0, #4
_08150C68:
	strb r0, [r2, #0xd]
	ldr r0, [r1]
	strb r3, [r0, #9]
	ldr r0, [r1]
	strb r3, [r0, #9]
	adds r4, r1, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x14]
	movs r0, #0x1c
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, #0x15]
	movs r0, #0x1e
	bl SetGpuReg
	movs r0, #0x18
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1a
	movs r1, #0
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, #0xc]
	movs r0, #0x14
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, #0xd]
	movs r0, #0x16
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, #8]
	movs r0, #0x10
	bl SetGpuReg
	ldr r0, [r4]
	ldrb r1, [r0, #9]
	movs r0, #0x12
	bl SetGpuReg
	movs r1, #0x82
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	movs r0, #0
	bl ShowBg
	movs r0, #1
	bl ShowBg
	movs r0, #2
	bl ShowBg
	movs r0, #3
	bl ShowBg
	movs r1, #0xfc
	lsls r1, r1, #6
	movs r0, #0x50
	bl SetGpuReg
_08150CF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08150D00: .4byte 0x0203A878
	thumb_func_end sub_08150B48

	.section .text.cable_car_mid,"ax",%progbits

	thumb_func_start LoadCableCarSprites
LoadCableCarSprites: @ 0x08150D04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	ldr r1, _08150E18
	add r0, sp, #0xc
	movs r2, #2
	bl memcpy
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	add r6, sp, #0x10
	ldr r1, _08150E1C
	adds r0, r6, #0
	movs r2, #4
	bl memcpy
	add r5, sp, #0x14
	ldr r1, _08150E20
	adds r0, r5, #0
	movs r2, #8
	bl memcpy
	add r4, sp, #0x1c
	ldr r1, _08150E24
	adds r0, r4, #0
	movs r2, #4
	bl memcpy
	ldr r0, _08150E28
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, _08150E2C
	ldrh r0, [r0]
	mov r8, r6
	mov sl, r5
	cmp r0, #0
	beq _08150D62
	cmp r0, #1
	beq _08150E44
_08150D62:
	ldr r0, _08150E30
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	add r0, sp
	adds r0, #0xc
	ldrb r0, [r0]
	ldr r1, _08150E34
	movs r2, #0x66
	str r2, [sp]
	movs r2, #0xc8
	movs r3, #0x49
	bl AddPseudoEventObject
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x40
	beq _08150DAC
	ldr r0, _08150E38
	lsls r1, r6, #4
	adds r1, r1, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #8
	orrs r0, r2
	strb r0, [r1, #5]
	movs r0, #8
	strh r0, [r1, #0x24]
	movs r0, #0x10
	strh r0, [r1, #0x26]
	movs r0, #0xc8
	strh r0, [r1, #0x2e]
	movs r0, #0x49
	strh r0, [r1, #0x30]
_08150DAC:
	ldr r4, _08150E3C
	adds r0, r4, #0
	movs r1, #0xb0
	movs r2, #0x2b
	movs r3, #0x67
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r5, _08150E38
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0x20
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x24]
	movs r1, #0xb0
	strh r1, [r0, #0x2e]
	movs r1, #0x2b
	strh r1, [r0, #0x30]
	adds r4, #0x18
	adds r0, r4, #0
	movs r1, #0xc8
	movs r2, #0x63
	movs r3, #0x65
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #8
	strh r1, [r0, #0x24]
	movs r1, #4
	strh r1, [r0, #0x26]
	movs r1, #0xc8
	strh r1, [r0, #0x2e]
	movs r1, #0x63
	strh r1, [r0, #0x30]
	ldr r2, _08150E40
	ldr r1, [r2]
	movs r0, #7
	strb r0, [r1, #2]
	ldr r1, [r2]
	movs r0, #0xaf
	lsls r0, r0, #1
	strh r0, [r1, #4]
	movs r0, #2
	bl SetCurrentAndNextWeatherNoDelay
	b _08150F16
	.align 2, 0
_08150E18: .4byte 0x085AC9EC
_08150E1C: .4byte 0x085AC9EE
_08150E20: .4byte 0x085AC9F2
_08150E24: .4byte 0x085AC9FA
_08150E28: .4byte 0x085ACA00
_08150E2C: .4byte 0x02037280
_08150E30: .4byte 0x03005AF0
_08150E34: .4byte 0x08150925
_08150E38: .4byte 0x020205AC
_08150E3C: .4byte 0x085AC9A4
_08150E40: .4byte 0x0203A878
_08150E44:
	ldr r7, _08150FE4
	ldr r0, [r7]
	ldr r1, _08150FE8
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, #0x48
	movs r0, #0xc
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	movs r2, #0x18
	movs r3, #0x1a
	bl CopyToBgTilemapBufferRect_ChangePalette
	ldr r0, _08150FEC
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	add r0, sp
	adds r0, #0xc
	ldrb r0, [r0]
	ldr r1, _08150FF0
	movs r2, #0x66
	str r2, [sp]
	movs r2, #0x80
	movs r3, #0x27
	bl AddPseudoEventObject
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x40
	beq _08150EB0
	ldr r0, _08150FF4
	lsls r1, r6, #4
	adds r1, r1, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #8
	orrs r0, r2
	strb r0, [r1, #5]
	movs r0, #8
	strh r0, [r1, #0x24]
	movs r0, #0x10
	strh r0, [r1, #0x26]
	movs r0, #0x80
	strh r0, [r1, #0x2e]
	movs r0, #0x27
	strh r0, [r1, #0x30]
_08150EB0:
	ldr r4, _08150FF8
	adds r0, r4, #0
	movs r1, #0x68
	movs r2, #9
	movs r3, #0x67
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r5, _08150FF4
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0x20
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x24]
	movs r1, #0x68
	strh r1, [r0, #0x2e]
	movs r1, #9
	strh r1, [r0, #0x30]
	adds r4, #0x18
	adds r0, r4, #0
	movs r1, #0x80
	movs r2, #0x41
	movs r3, #0x65
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #8
	strh r1, [r0, #0x24]
	movs r1, #4
	strh r1, [r0, #0x26]
	movs r1, #0x80
	strh r1, [r0, #0x2e]
	movs r1, #0x41
	strh r1, [r0, #0x30]
	ldr r1, [r7]
	movs r0, #2
	strb r0, [r1, #2]
	ldr r1, [r7]
	ldr r0, _08150FFC
	strh r0, [r1, #4]
	movs r0, #7
	bl SetCurrentAndNextWeatherNoDelay
_08150F16:
	movs r4, #0
	ldr r5, _08150FF4
_08150F1A:
	lsls r1, r4, #0x14
	movs r2, #0xc0
	lsls r2, r2, #0xf
	adds r1, r1, r2
	asrs r1, r1, #0x10
	lsls r2, r4, #0x13
	ldr r3, _08151000
	adds r2, r2, r3
	asrs r2, r2, #0x10
	ldr r0, _08151004
	movs r3, #0x68
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #8
	strh r1, [r0, #0x24]
	strh r1, [r0, #0x26]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #8
	bls _08150F1A
	movs r0, #0x3f
	mov r4, sb
	ands r0, r4
	cmp r0, #0
	bne _08151050
	mov r0, sb
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r0, r8
	ldrb r0, [r0]
	ldr r5, _08151008
	ldrh r4, [r5]
	lsls r4, r4, #2
	add r1, sp, #0x20
	adds r1, r4, r1
	ldr r1, [r1]
	mov r3, sl
	adds r2, r3, r4
	movs r3, #0
	ldrsh r2, [r2, r3]
	mov r3, sp
	adds r3, #0x16
	adds r3, r3, r4
	movs r4, #0
	ldrsh r3, [r3, r4]
	movs r4, #0x6a
	str r4, [sp]
	bl AddPseudoEventObject
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0x40
	beq _08151050
	ldr r1, _08150FF4
	lsls r2, r6, #4
	adds r0, r2, r6
	lsls r0, r0, #2
	adds r4, r0, r1
	ldrb r1, [r4, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r4, #5]
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	rsbs r0, r0, #0
	strh r0, [r4, #0x24]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	rsbs r0, r0, #0
	strh r0, [r4, #0x26]
	ldrh r0, [r5]
	mov r8, r2
	cmp r0, #0
	bne _08151012
	movs r7, #1
	mov r5, sb
	ands r5, r7
	cmp r5, #0
	beq _0815100C
	adds r0, r4, #0
	movs r1, #6
	b _08151020
	.align 2, 0
_08150FE4: .4byte 0x0203A878
_08150FE8: .4byte 0x000040FC
_08150FEC: .4byte 0x03005AF0
_08150FF0: .4byte 0x08150925
_08150FF4: .4byte 0x020205AC
_08150FF8: .4byte 0x085AC9A4
_08150FFC: .4byte 0x00000109
_08151000: .4byte 0xFFF80000
_08151004: .4byte 0x085AC9D4
_08151008: .4byte 0x02037280
_0815100C:
	adds r0, r4, #0
	movs r1, #7
	b _08151032
_08151012:
	movs r7, #1
	mov r5, sb
	ands r5, r7
	cmp r5, #0
	beq _0815102E
	adds r0, r4, #0
	movs r1, #7
_08151020:
	bl StartSpriteAnim
	strh r7, [r4, #0x30]
	ldrh r0, [r4, #0x22]
	adds r0, #2
	strh r0, [r4, #0x22]
	b _08151038
_0815102E:
	adds r0, r4, #0
	movs r1, #6
_08151032:
	bl StartSpriteAnim
	strh r5, [r4, #0x30]
_08151038:
	ldr r0, _08151060
	mov r2, r8
	adds r1, r2, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #3
	mov r3, sb
	ands r0, r3
	add r0, sp
	adds r0, #0x1c
	ldrb r0, [r0]
	strh r0, [r1, #0x32]
_08151050:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08151060: .4byte 0x020205AC
	thumb_func_end LoadCableCarSprites

	thumb_func_start BufferNextGroundSegment
BufferNextGroundSegment: @ 0x08151064
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r3, #0
	mov sb, r3
	ldr r2, _08151130
	ldr r0, [r2]
	ldrb r1, [r0, #0x1b]
	adds r1, #2
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x18
	mov ip, r0
_08151086:
	movs r7, #0
	lsls r0, r3, #1
	adds r1, r3, #3
	adds r2, r3, #6
	adds r4, r3, #1
	str r4, [sp, #4]
	adds r0, r0, r3
	lsls r0, r0, #3
	str r0, [sp]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov sl, r0
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	mov r8, r0
_081510A8:
	ldr r0, _08151130
	ldr r6, [r0]
	lsls r3, r7, #1
	ldr r1, [sp]
	adds r2, r3, r1
	adds r4, r6, #0
	adds r4, #0x22
	adds r2, r4, r2
	mov r1, ip
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	ldr r0, _08151134
	adds r5, r6, r0
	ldr r0, [r5]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	strh r0, [r2]
	mov r1, sl
	adds r2, r3, r1
	adds r2, r4, r2
	str r2, [sp, #8]
	ldr r0, [r5]
	mov r2, sb
	lsls r1, r2, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldr r2, [sp, #8]
	strh r0, [r2]
	add r3, r8
	adds r4, r4, r3
	ldr r0, [r5]
	adds r1, r1, r0
	adds r1, #0x48
	ldrh r0, [r1]
	strh r0, [r4]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0xb
	bls _081510A8
	ldr r4, [sp, #4]
	lsls r0, r4, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #2
	bls _08151086
	ldrb r0, [r6, #0x1b]
	adds r0, #1
	movs r1, #3
	bl __modsi3
	strb r0, [r6, #0x1b]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08151130: .4byte 0x0203A878
_08151134: .4byte 0x000040FC
	thumb_func_end BufferNextGroundSegment



	.section .text.cable_car_mid2,"ax",%progbits

	thumb_func_start sub_081511F0
sub_081511F0: @ 0x081511F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r7, #0
	ldr r3, _08151354
	ldr r0, [r3]
	strb r7, [r0, #0x1e]
	strb r7, [r0, #0x1d]
	ldr r1, [r3]
	ldrb r0, [r1, #8]
	strb r0, [r1, #0x1f]
	ldr r0, [r3]
	ldrb r1, [r0, #9]
	adds r0, #0x20
	strb r1, [r0]
	ldr r4, [r3]
	ldrb r1, [r4, #0x19]
	adds r2, r1, #0
	adds r2, #0x1e
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r4, #0x19]
	ldr r1, [r3]
	ldrb r0, [r1, #0x18]
	subs r0, #2
	strb r0, [r1, #0x18]
	ldr r4, _08151358
	ldr r0, [r3]
	ldrb r1, [r0, #0x1a]
	adds r2, r1, #0
	adds r2, #0x17
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r4]
	ldr r6, _0815135C
	mov sb, r3
	ldr r0, _08151360
	mov r8, r0
_0815124A:
	mov r1, sb
	ldr r2, [r1]
	ldrb r0, [r2, #0x19]
	strb r0, [r6]
	ldr r0, _08151358
	ldrb r0, [r0]
	adds r1, r0, r7
	adds r0, r1, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r1, r0
	mov r1, r8
	strb r0, [r1]
	ldrb r1, [r2, #0x18]
	lsls r1, r1, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r5, r0, #3
	adds r1, r1, r5
	adds r0, r2, #0
	adds r0, #0x22
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrb r2, [r6]
	mov r0, r8
	ldrb r3, [r0]
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x11
	mov sl, r0
	str r0, [sp, #8]
	movs r0, #0
	bl FillBgTilemapBufferRect
	ldrb r1, [r6]
	adds r2, r1, #1
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r6]
	mov r0, sb
	ldr r1, [r0]
	ldrb r0, [r1, #0x18]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	adds r1, #0x22
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrb r2, [r6]
	mov r0, r8
	ldrb r3, [r0]
	str r4, [sp]
	str r4, [sp, #4]
	mov r0, sl
	str r0, [sp, #8]
	movs r0, #0
	bl FillBgTilemapBufferRect
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #8
	bls _0815124A
	ldr r5, _0815135C
	ldr r4, _08151354
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	adds r2, r1, #0
	adds r2, #0x1e
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r5]
	ldrb r2, [r5]
	movs r0, #2
	str r0, [sp]
	movs r6, #0x20
	str r6, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FillBgTilemapBufferRect
	ldr r1, [r4]
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	bne _08151344
	ldrb r2, [r1, #0x1a]
	adds r3, r2, #0
	adds r3, #0x1d
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1, #0x1a]
	ldr r1, [r4]
	movs r0, #0xc
	strb r0, [r1, #0x18]
	bl BufferNextGroundSegment
	ldr r0, [r4]
	ldrb r1, [r0, #0x1a]
	adds r2, r1, #1
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r5]
	ldrb r3, [r5]
	str r6, [sp]
	movs r0, #9
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FillBgTilemapBufferRect
_08151344:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08151354: .4byte 0x0203A878
_08151358: .4byte 0x0203A87E
_0815135C: .4byte 0x0203A87C
_08151360: .4byte 0x0203A87D
	thumb_func_end sub_081511F0

	thumb_func_start DrawNextGroundSegmentGoingDown
DrawNextGroundSegmentGoingDown: @ 0x08151364
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r7, #0
	ldr r2, _08151494
	ldr r0, [r2]
	strb r7, [r0, #0x1e]
	strb r7, [r0, #0x1d]
	ldr r1, [r2]
	ldrb r0, [r1, #8]
	strb r0, [r1, #0x1f]
	ldr r0, [r2]
	ldrb r1, [r0, #9]
	adds r0, #0x20
	strb r1, [r0]
	ldr r4, [r2]
	ldrb r1, [r4, #0x19]
	adds r3, r1, #2
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r4, #0x19]
	ldr r1, [r2]
	ldrb r0, [r1, #0x18]
	adds r0, #2
	strb r0, [r1, #0x18]
	ldr r1, _08151498
	ldr r0, [r2]
	ldrb r0, [r0, #0x1a]
	strb r0, [r1]
	ldr r6, _0815149C
	mov sl, r2
	ldr r0, _081514A0
	mov sb, r0
_081513B0:
	mov r1, sl
	ldr r2, [r1]
	ldrb r0, [r2, #0x19]
	strb r0, [r6]
	ldr r0, _08151498
	ldrb r0, [r0]
	adds r1, r0, r7
	adds r0, r1, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r1, r0
	mov r1, sb
	strb r0, [r1]
	ldrb r1, [r2, #0x18]
	lsls r1, r1, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r5, r0, #3
	adds r1, r1, r5
	adds r0, r2, #0
	adds r0, #0x22
	adds r0, r0, r1
	ldrh r1, [r0]
	ldrb r2, [r6]
	mov r0, sb
	ldrb r3, [r0]
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x11
	mov r8, r0
	str r0, [sp, #8]
	movs r0, #0
	bl FillBgTilemapBufferRect
	ldrb r1, [r6]
	adds r2, r1, #1
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r6]
	mov r0, sl
	ldr r1, [r0]
	ldrb r0, [r1, #0x18]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r5
	adds r1, #0x22
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrb r2, [r6]
	mov r0, sb
	ldrb r3, [r0]
	str r4, [sp]
	str r4, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	movs r0, #0
	bl FillBgTilemapBufferRect
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #8
	bls _081513B0
	ldr r4, _081514A0
	ldr r5, _08151494
	ldr r3, [r5]
	ldrb r1, [r3, #0x1a]
	adds r2, r1, #0
	adds r2, #0x17
	adds r0, r2, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r2, r0
	strb r0, [r4]
	ldrb r2, [r3, #0x19]
	ldrb r3, [r4]
	movs r0, #2
	str r0, [sp]
	movs r0, #9
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	bl FillBgTilemapBufferRect
	ldr r1, [r5]
	ldrb r0, [r1, #0x18]
	cmp r0, #0xa
	bne _08151482
	ldrb r2, [r1, #0x1a]
	adds r3, r2, #3
	adds r0, r3, #0
	asrs r0, r0, #5
	lsls r0, r0, #5
	subs r0, r3, r0
	strb r0, [r1, #0x1a]
	ldr r1, [r5]
	movs r0, #0xfe
	strb r0, [r1, #0x18]
	bl BufferNextGroundSegment
_08151482:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08151494: .4byte 0x0203A878
_08151498: .4byte 0x0203A881
_0815149C: .4byte 0x0203A87F
_081514A0: .4byte 0x0203A880
	thumb_func_end DrawNextGroundSegmentGoingDown
