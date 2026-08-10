.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start LinkMain1
LinkMain1: @ 0x0800B0F4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, _0800B110
	ldrb r0, [r0, #1]
	cmp r0, #4
	bhi _0800B1A6
	lsls r0, r0, #2
	ldr r1, _0800B114
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0800B110: .4byte 0x03003210
_0800B114: .4byte 0x0800B118
_0800B118: @ jump table
	.4byte _0800B12C @ case 0
	.4byte _0800B13C @ case 1
	.4byte _0800B154 @ case 2
	.4byte _0800B190 @ case 3
	.4byte _0800B19A @ case 4
_0800B12C:
	bl DisableSerial
	ldr r1, _0800B138
	movs r0, #1
	strb r0, [r1, #1]
	b _0800B1A6
	.align 2, 0
_0800B138: .4byte 0x03003210
_0800B13C:
	ldrb r0, [r4]
	cmp r0, #1
	bne _0800B1A6
	bl EnableSerial
	ldr r1, _0800B150
	movs r0, #2
	strb r0, [r1, #1]
	b _0800B1A6
	.align 2, 0
_0800B150: .4byte 0x03003210
_0800B154:
	ldrb r1, [r4]
	cmp r1, #1
	beq _0800B164
	cmp r1, #2
	beq _0800B17C
	bl CheckMasterOrSlave
	b _0800B1A6
_0800B164:
	ldr r2, _0800B178
	ldrb r0, [r2]
	cmp r0, #8
	bne _0800B1A6
	ldrb r0, [r2, #3]
	cmp r0, #1
	bls _0800B1A6
	strb r1, [r2, #0xe]
	b _0800B1A6
	.align 2, 0
_0800B178: .4byte 0x03003210
_0800B17C:
	ldr r0, _0800B188
	movs r1, #0
	strb r1, [r0, #1]
	ldr r0, _0800B18C
	strh r1, [r0]
	b _0800B1A6
	.align 2, 0
_0800B188: .4byte 0x03003210
_0800B18C: .4byte 0x0400012A
_0800B190:
	bl InitTimer
	ldr r1, _0800B1E0
	movs r0, #4
	strb r0, [r1, #1]
_0800B19A:
	adds r0, r5, #0
	bl EnqueueSendCmd
	adds r0, r6, #0
	bl DequeueRecvCmds
_0800B1A6:
	movs r0, #0
	strb r0, [r4]
	ldr r1, _0800B1E0
	ldrb r2, [r1, #2]
	ldrb r0, [r1, #3]
	lsls r0, r0, #2
	orrs r2, r0
	ldrb r0, [r1]
	cmp r0, #8
	bne _0800B1BE
	movs r0, #0x20
	orrs r2, r0
_0800B1BE:
	ldrb r0, [r1, #0xc]
	lsls r3, r0, #8
	ldrb r0, [r1, #0xf]
	lsls r4, r0, #9
	ldrb r0, [r1, #0x10]
	lsls r5, r0, #0xc
	ldrb r0, [r1, #0x11]
	lsls r6, r0, #0xd
	ldrb r0, [r1, #0x12]
	lsls r7, r0, #0xe
	ldrb r0, [r1, #1]
	cmp r0, #4
	bne _0800B1E4
	movs r0, #0x40
	orrs r0, r3
	orrs r0, r2
	b _0800B1E8
	.align 2, 0
_0800B1E0: .4byte 0x03003210
_0800B1E4:
	adds r0, r2, #0
	orrs r0, r3
_0800B1E8:
	orrs r0, r4
	orrs r0, r5
	orrs r0, r6
	orrs r0, r7
	adds r2, r0, #0
	ldrb r3, [r1, #0x13]
	cmp r3, #1
	bne _0800B1FE
	movs r0, #0x80
	lsls r0, r0, #9
	orrs r2, r0
_0800B1FE:
	ldrb r0, [r1, #2]
	cmp r0, #3
	bls _0800B20A
	movs r0, #0x80
	lsls r0, r0, #0xa
	orrs r2, r0
_0800B20A:
	adds r1, r2, #0
	cmp r3, #2
	bne _0800B216
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
_0800B216:
	adds r0, r1, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end LinkMain1


