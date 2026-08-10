.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


thumb_func_start SiiRtcSetAlarm
SiiRtcSetAlarm: @ 0x08290C74
	push {r4, r7, lr}
	sub sp, #0xc
	mov r7, sp
	str r0, [r7]
	ldr r0, _08290C88
	ldrb r1, [r0]
	cmp r1, #1
	bne _08290C8C
	movs r0, #0
	b _08290DA0
	.align 2, 0
_08290C88: .4byte 0x03001A76
_08290C8C:
	ldr r0, _08290CF4
	movs r1, #1
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r7]
	ldrb r2, [r1, #8]
	movs r3, #0xf
	adds r1, r2, #0
	ands r1, r3
	ldr r2, [r7]
	ldrb r3, [r2, #8]
	lsrs r2, r3, #4
	adds r3, r2, #0
	movs r4, #0xf
	adds r2, r3, #0
	ands r2, r4
	adds r4, r2, #0
	lsls r3, r4, #0x18
	lsrs r2, r3, #0x18
	adds r4, r2, #0
	lsls r3, r4, #2
	adds r3, r3, r2
	lsls r2, r3, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #8
	ldrb r1, [r0]
	cmp r1, #0xb
	bhi _08290CF8
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r7]
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1, #8]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
	b _08290D16
	.align 2, 0
_08290CF4: .4byte 0x03001A76
_08290CF8:
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r7]
	ldrb r2, [r1, #8]
	movs r3, #0x80
	adds r1, r2, #0
	orrs r1, r3
	ldrb r2, [r0]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0]
_08290D16:
	adds r0, r7, #0
	adds r0, #8
	ldr r1, [r7]
	ldrb r2, [r0, #1]
	movs r3, #0
	ands r2, r3
	adds r3, r2, #0
	ldrb r1, [r1, #9]
	adds r2, r3, #0
	orrs r2, r1
	adds r1, r2, #0
	strb r1, [r0, #1]
	ldr r0, _08290D58
	movs r1, #1
	strh r1, [r0]
	ldr r0, _08290D58
	movs r1, #5
	strh r1, [r0]
	ldr r0, _08290D5C
	movs r1, #7
	strh r1, [r0]
	movs r0, #0x68
	bl WriteCommand
	adds r0, r7, #4
	movs r1, #0
	strb r1, [r0]
_08290D4C:
	adds r0, r7, #4
	ldrb r1, [r0]
	cmp r1, #1
	bls _08290D60
	b _08290D82
	.align 2, 0
_08290D58: .4byte 0x080000C4
_08290D5C: .4byte 0x080000C6
_08290D60:
	adds r0, r7, #0
	adds r0, #8
	adds r1, r7, #4
	ldrb r2, [r1]
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r0, r1, #0
	bl WriteData
	adds r1, r7, #4
	adds r0, r7, #4
	adds r1, r7, #4
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
	b _08290D4C
_08290D82:
	ldr r0, _08290D98
	movs r1, #1
	strh r1, [r0]
	ldr r0, _08290D98
	movs r1, #1
	strh r1, [r0]
	ldr r0, _08290D9C
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	b _08290DA0
	.align 2, 0
_08290D98: .4byte 0x080000C4
_08290D9C: .4byte 0x03001A76
_08290DA0:
	add sp, #0xc
	pop {r4, r7}
	pop {r1}
	bx r1
	thumb_func_end SiiRtcSetAlarm

thumb_func_start WriteCommand
WriteCommand: @ 0x08290DA8
	push {r4, r5, r7, lr}
	sub sp, #4
	mov r7, sp
	adds r1, r0, #0
	adds r2, r7, #0
	strb r1, [r2]
	adds r1, r7, #1
	movs r2, #0
	strb r2, [r1]
_08290DBA:
	adds r1, r7, #1
	ldrb r2, [r1]
	cmp r2, #7
	bls _08290DC4
	b _08290E44
_08290DC4:
	adds r1, r7, #2
	adds r3, r7, #0
	ldrb r2, [r3]
	adds r3, r7, #1
	ldrb r4, [r3]
	movs r5, #7
	subs r3, r5, r4
	asrs r2, r3
	adds r3, r2, #0
	movs r4, #1
	adds r2, r3, #0
	ands r2, r4
	adds r3, r2, #0
	strb r3, [r1]
	ldr r1, _08290E40
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _08290E40
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _08290E40
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _08290E40
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #5
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	adds r2, r7, #1
	adds r1, r7, #1
	adds r2, r7, #1
	ldrb r3, [r2]
	adds r2, r3, #1
	adds r3, r2, #0
	strb r3, [r1]
	b _08290DBA
	.align 2, 0
_08290E40: .4byte 0x080000C4
_08290E44:
	add sp, #4
	pop {r4, r5, r7}
	pop {r1}
	bx r1
	thumb_func_end WriteCommand

thumb_func_start WriteData
WriteData: @ 0x08290E4C
	push {r4, r7, lr}
	sub sp, #4
	mov r7, sp
	adds r1, r0, #0
	adds r2, r7, #0
	strb r1, [r2]
	adds r1, r7, #1
	movs r2, #0
	strb r2, [r1]
_08290E5E:
	adds r1, r7, #1
	ldrb r2, [r1]
	cmp r2, #7
	bls _08290E68
	b _08290EE4
_08290E68:
	adds r1, r7, #2
	adds r3, r7, #0
	ldrb r2, [r3]
	adds r3, r7, #1
	ldrb r4, [r3]
	asrs r2, r4
	adds r3, r2, #0
	movs r4, #1
	adds r2, r3, #0
	ands r2, r4
	adds r3, r2, #0
	strb r3, [r1]
	ldr r1, _08290EE0
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _08290EE0
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _08290EE0
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #4
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	ldr r1, _08290EE0
	adds r2, r7, #2
	ldrb r3, [r2]
	adds r2, r3, #0
	lsls r3, r2, #1
	adds r2, r3, #0
	movs r3, #5
	orrs r2, r3
	adds r3, r2, #0
	strh r3, [r1]
	adds r2, r7, #1
	adds r1, r7, #1
	adds r2, r7, #1
	ldrb r3, [r2]
	adds r2, r3, #1
	adds r3, r2, #0
	strb r3, [r1]
	b _08290E5E
	.align 2, 0
_08290EE0: .4byte 0x080000C4
_08290EE4:
	add sp, #4
	pop {r4, r7}
	pop {r1}
	bx r1
	thumb_func_end WriteData

thumb_func_start ReadData
ReadData: @ 0x08290EEC
	push {r7, lr}
	sub sp, #4
	mov r7, sp
	adds r0, r7, #0
	movs r1, #0
	strb r1, [r0]
_08290EF8:
	adds r0, r7, #0
	ldrb r1, [r0]
	cmp r1, #7
	bls _08290F02
	b _08290F68
_08290F02:
	ldr r0, _08290F64
	movs r1, #4
	strh r1, [r0]
	ldr r0, _08290F64
	movs r1, #4
	strh r1, [r0]
	ldr r0, _08290F64
	movs r1, #4
	strh r1, [r0]
	ldr r0, _08290F64
	movs r1, #4
	strh r1, [r0]
	ldr r0, _08290F64
	movs r1, #4
	strh r1, [r0]
	ldr r0, _08290F64
	movs r1, #5
	strh r1, [r0]
	adds r0, r7, #1
	ldr r1, _08290F64
	ldrh r2, [r1]
	movs r3, #2
	adds r1, r2, #0
	ands r1, r3
	adds r3, r1, #0
	lsls r2, r3, #0x10
	lsrs r1, r2, #0x10
	lsrs r2, r1, #1
	adds r1, r2, #0
	strb r1, [r0]
	adds r0, r7, #2
	adds r1, r7, #2
	ldrb r2, [r1]
	lsrs r1, r2, #1
	adds r2, r7, #1
	ldrb r3, [r2]
	lsls r2, r3, #7
	orrs r1, r2
	adds r2, r1, #0
	strb r2, [r0]
	adds r1, r7, #0
	adds r0, r7, #0
	adds r1, r7, #0
	ldrb r2, [r1]
	adds r1, r2, #1
	adds r2, r1, #0
	strb r2, [r0]
	b _08290EF8
	.align 2, 0
_08290F64: .4byte 0x080000C4
_08290F68:
	adds r0, r7, #2
	ldrb r1, [r0]
	adds r0, r1, #0
	b _08290F70
_08290F70:
	add sp, #4
	pop {r7}
	pop {r1}
	bx r1
	thumb_func_end ReadData

thumb_func_start EnableGpioPortRead
EnableGpioPortRead: @ 0x08290F78
	push {r7, lr}
	mov r7, sp
	ldr r0, _08290F88
	movs r1, #1
	strh r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_08290F88: .4byte 0x080000C8
	thumb_func_end EnableGpioPortRead

thumb_func_start DisableGpioPortRead
DisableGpioPortRead: @ 0x08290F8C
	push {r7, lr}
	mov r7, sp
	ldr r0, _08290F9C
	movs r1, #0
	strh r1, [r0]
	pop {r7}
	pop {r0}
	bx r0
	.align 2, 0
_08290F9C: .4byte 0x080000C8
	thumb_func_end DisableGpioPortRead

