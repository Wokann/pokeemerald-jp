.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start BtlController_EmitPrintString
BtlController_EmitPrintString: @ 0x08033A7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08033B40
	movs r0, #0x10
	strb r0, [r2]
	ldr r0, _08033B44
	ldrb r0, [r0]
	strb r0, [r2, #1]
	strb r1, [r2, #2]
	lsrs r1, r1, #8
	strb r1, [r2, #3]
	adds r0, r2, #4
	mov ip, r0
	ldr r4, _08033B48
	ldrh r0, [r4]
	strh r0, [r2, #4]
	ldr r0, _08033B4C
	ldrh r0, [r0]
	mov r1, ip
	strh r0, [r1, #2]
	ldr r0, _08033B50
	ldrh r0, [r0]
	strh r0, [r1, #4]
	ldr r0, _08033B54
	ldrb r0, [r0]
	strb r0, [r1, #6]
	ldr r0, _08033B58
	ldrb r0, [r0, #0x17]
	strb r0, [r1, #7]
	ldr r0, _08033B5C
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x52
	ldrb r1, [r1]
	mov r3, ip
	strb r1, [r3, #8]
	adds r0, #0xb1
	ldrb r0, [r0]
	strb r0, [r3, #9]
	ldr r0, _08033B60
	ldrb r0, [r0]
	strb r0, [r3, #0xa]
	ldr r3, _08033B64
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #2]
	mov r1, ip
	strb r0, [r1, #0xb]
	movs r3, #0
	adds r7, r2, #0
	adds r2, #0x10
	ldr r0, _08033B68
	adds r4, r0, #0
	adds r4, #0x20
_08033AFA:
	adds r1, r2, r3
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #0x58
	adds r3, #1
	cmp r3, #3
	ble _08033AFA
	movs r3, #0
	mov r4, ip
	adds r4, #0x10
	ldr r6, _08033B6C
	mov r2, ip
	adds r2, #0x20
	ldr r5, _08033B70
_08033B16:
	adds r1, r4, r3
	adds r0, r3, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r3
	adds r0, r3, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	cmp r3, #0xf
	ble _08033B16
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0x34
	bl PrepareBufferDataTransfer
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033B40: .4byte 0x020229C4
_08033B44: .4byte 0x02023FDE
_08033B48: .4byte 0x02023E8E
_08033B4C: .4byte 0x02023E90
_08033B50: .4byte 0x02023EAC
_08033B54: .4byte 0x02023EAE
_08033B58: .4byte 0x02024118
_08033B5C: .4byte 0x02024140
_08033B60: .4byte 0x02023EB3
_08033B64: .4byte 0x082ED220
_08033B68: .4byte 0x02023D28
_08033B6C: .4byte 0x02022C0C
_08033B70: .4byte 0x02022C1C
	thumb_func_end BtlController_EmitPrintString

	thumb_func_start BtlController_EmitPrintSelectionString
BtlController_EmitPrintSelectionString: @ 0x08033B74
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08033C14
	movs r0, #0x11
	strb r0, [r2]
	strb r0, [r2, #1]
	strb r1, [r2, #2]
	lsrs r1, r1, #8
	strb r1, [r2, #3]
	adds r0, r2, #4
	mov ip, r0
	ldr r0, _08033C18
	ldrh r0, [r0]
	strh r0, [r2, #4]
	ldr r0, _08033C1C
	ldrh r0, [r0]
	mov r1, ip
	strh r0, [r1, #2]
	ldr r0, _08033C20
	ldrh r0, [r0]
	strh r0, [r1, #4]
	ldr r0, _08033C24
	ldrb r0, [r0]
	strb r0, [r1, #6]
	ldr r0, _08033C28
	ldrb r0, [r0, #0x17]
	strb r0, [r1, #7]
	ldr r0, _08033C2C
	ldr r0, [r0]
	adds r0, #0x52
	ldrb r0, [r0]
	strb r0, [r1, #8]
	movs r3, #0
	adds r7, r2, #0
	adds r4, r7, #0
	adds r4, #0x10
	ldr r0, _08033C30
	adds r2, r0, #0
	adds r2, #0x20
_08033BCE:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #0x58
	adds r3, #1
	cmp r3, #3
	ble _08033BCE
	movs r3, #0
	mov r4, ip
	adds r4, #0x10
	ldr r6, _08033C34
	mov r2, ip
	adds r2, #0x20
	ldr r5, _08033C38
_08033BEA:
	adds r1, r4, r3
	adds r0, r3, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r2, r3
	adds r0, r3, r5
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	cmp r3, #0xf
	ble _08033BEA
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0x34
	bl PrepareBufferDataTransfer
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033C14: .4byte 0x020229C4
_08033C18: .4byte 0x02023E8E
_08033C1C: .4byte 0x02023E90
_08033C20: .4byte 0x02023EAC
_08033C24: .4byte 0x02023EAE
_08033C28: .4byte 0x02024118
_08033C2C: .4byte 0x02024140
_08033C30: .4byte 0x02023D28
_08033C34: .4byte 0x02022C0C
_08033C38: .4byte 0x02022C1C
	thumb_func_end BtlController_EmitPrintSelectionString
