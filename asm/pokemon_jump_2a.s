.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0802D884
sub_0802D884: @ 0x0802D884
	push {r4, lr}
	sub sp, #0x10
	ldr r1, _0802D8E4
	add r0, sp, #0xc
	movs r2, #3
	bl memcpy
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #1
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #1
	movs r1, #0
	bl FillWindowPixelBuffer
	add r0, sp, #0xc
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	ldr r0, _0802D8E8
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #2
	bl AddTextPrinterParameterized3
	add r0, sp, #0xc
	str r0, [sp]
	str r4, [sp, #4]
	ldr r0, _0802D8EC
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #2
	bl AddTextPrinterParameterized3
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D8E4: .4byte 0x082D1A68
_0802D8E8: .4byte 0x085CCDF8
_0802D8EC: .4byte 0x085CCDFB
	thumb_func_end sub_0802D884

	thumb_func_start sub_0802D8F0
sub_0802D8F0: @ 0x0802D8F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r1, _0802D96C
	subs r0, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	movs r6, #0
	cmp r6, sl
	bge _0802D95A
	ldr r0, _0802D970
	mov sb, r0
	ldr r1, _0802D974
	mov r8, r1
_0802D91E:
	lsls r4, r6, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl sub_0802C5BC
	adds r1, r0, #0
	ldrh r0, [r1]
	lsls r0, r0, #2
	add r0, sb
	ldrb r3, [r0, #1]
	mov r2, r8
	ldr r0, [r2]
	movs r7, #0
	ldrsh r2, [r5, r7]
	adds r3, #0x70
	str r4, [sp]
	bl sub_0802C6C8
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	movs r2, #0x70
	adds r3, r4, #0
	bl sub_0802CB3C
	adds r5, #2
	adds r6, #1
	cmp r6, sl
	blt _0802D91E
_0802D95A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D96C: .4byte 0x082D1AEC
_0802D970: .4byte 0x082D45C8
_0802D974: .4byte 0x020229B4
	thumb_func_end sub_0802D8F0

	thumb_func_start sub_0802D978
sub_0802D978: @ 0x0802D978
	ldr r2, _0802D98C
	ldr r2, [r2]
	lsls r0, r0, #2
	ldr r3, _0802D990
	adds r2, r2, r3
	adds r2, r2, r0
	ldr r0, [r2]
	strh r1, [r0, #0x26]
	bx lr
	.align 2, 0
_0802D98C: .4byte 0x020229B4
_0802D990: .4byte 0x000081A8
	thumb_func_end sub_0802D978

	thumb_func_start sub_0802D994
sub_0802D994: @ 0x0802D994
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0802D9BC
	ldr r0, [r0]
	adds r1, r4, #0
	bl sub_0802CC44
	ldr r0, _0802D9C0
	adds r4, r4, r0
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	movs r0, #2
	movs r2, #0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D9BC: .4byte 0x020229B4
_0802D9C0: .4byte 0x082D1A6B
	thumb_func_end sub_0802D994

	thumb_func_start sub_0802D9C4
sub_0802D9C4: @ 0x0802D9C4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r5, #0
	movs r6, #0
_0802D9CE:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _0802D9E2
	ldr r0, _0802D9FC
	ldr r0, [r0]
	adds r1, r5, #0
	bl sub_0802C808
	adds r6, #1
_0802D9E2:
	lsrs r4, r4, #1
	adds r5, #1
	cmp r5, #4
	ble _0802D9CE
	subs r0, r6, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0802DD04
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802D9FC: .4byte 0x020229B4
	thumb_func_end sub_0802D9C4

	thumb_func_start sub_0802DA00
sub_0802DA00: @ 0x0802DA00
	push {r4, lr}
	sub sp, #0x10
	mov r1, sp
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	movs r0, #8
	strb r0, [r1, #2]
	movs r0, #0x6c
	strh r0, [r1, #4]
	movs r4, #6
	strh r4, [r1, #6]
	ldr r0, _0802DA54
	str r0, [sp, #8]
	ldr r0, _0802DA58
	str r0, [sp, #0xc]
	movs r0, #2
	bl sub_08034AAC
	movs r0, #0
	movs r1, #0
	mov r2, sp
	bl sub_08034B6C
	mov r1, sp
	movs r0, #4
	strb r0, [r1, #1]
	movs r0, #0x1e
	strh r0, [r1, #4]
	mov r0, sp
	strh r4, [r0, #6]
	movs r0, #1
	movs r1, #0
	mov r2, sp
	bl sub_08034B6C
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DA54: .4byte 0x082D1A78
_0802DA58: .4byte 0x082D1A80
	thumb_func_end sub_0802DA00

	thumb_func_start sub_0802DA5C
sub_0802DA5C: @ 0x0802DA5C
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	bl sub_08034E9C
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DA5C

	thumb_func_start sub_0802DA6C
sub_0802DA6C: @ 0x0802DA6C
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #1
	bl sub_08034E9C
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DA6C

	thumb_func_start sub_0802DA80
sub_0802DA80: @ 0x0802DA80
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0802DA94
	ldr r0, [r0]
	bl sub_0802C8E4
	pop {r0}
	bx r0
	.align 2, 0
_0802DA94: .4byte 0x020229B4
	thumb_func_end sub_0802DA80

	thumb_func_start sub_0802DA98
sub_0802DA98: @ 0x0802DA98
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0802DAAC
	ldr r0, [r0]
	bl sub_0802C97C
	pop {r0}
	bx r0
	.align 2, 0
_0802DAAC: .4byte 0x020229B4
	thumb_func_end sub_0802DA98

	thumb_func_start sub_0802DAB0
sub_0802DAB0: @ 0x0802DAB0
	push {lr}
	adds r1, r0, #0
	ldr r0, _0802DAC0
	ldr r0, [r0]
	bl sub_0802C90C
	pop {r1}
	bx r1
	.align 2, 0
_0802DAC0: .4byte 0x020229B4
	thumb_func_end sub_0802DAB0

	thumb_func_start sub_0802DAC4
sub_0802DAC4: @ 0x0802DAC4
	push {lr}
	ldr r0, _0802DAD4
	ldr r0, [r0]
	bl sub_0802C9A4
	pop {r0}
	bx r0
	.align 2, 0
_0802DAD4: .4byte 0x020229B4
	thumb_func_end sub_0802DAC4

	thumb_func_start sub_0802DAD8
sub_0802DAD8: @ 0x0802DAD8
	push {lr}
	ldr r0, _0802DAE8
	ldr r0, [r0]
	bl sub_0802CA30
	pop {r0}
	bx r0
	.align 2, 0
_0802DAE8: .4byte 0x020229B4
	thumb_func_end sub_0802DAD8

	thumb_func_start sub_0802DAEC
sub_0802DAEC: @ 0x0802DAEC
	push {lr}
	adds r1, r0, #0
	ldr r0, _0802DAFC
	ldr r0, [r0]
	bl sub_0802CA64
	pop {r0}
	bx r0
	.align 2, 0
_0802DAFC: .4byte 0x020229B4
	thumb_func_end sub_0802DAEC

	thumb_func_start sub_0802DB00
sub_0802DB00: @ 0x0802DB00
	push {lr}
	ldr r0, _0802DB10
	ldr r0, [r0]
	bl sub_0802CA8C
	pop {r1}
	bx r1
	.align 2, 0
_0802DB10: .4byte 0x020229B4
	thumb_func_end sub_0802DB00

	thumb_func_start sub_0802DB14
sub_0802DB14: @ 0x0802DB14
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, _0802DBB4
	subs r0, r7, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r2, _0802DBB8
	ldr r0, [sp]
	ands r0, r2
	ldr r1, _0802DBBC
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x14
	orrs r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r2
	movs r1, #2
	orrs r0, r1
	ldr r1, _0802DBC0
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	ldr r1, _0802DBC4
	ands r0, r1
	movs r1, #0xd8
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #4]
	movs r5, #0
	cmp r5, r7
	bge _0802DBA4
	mov r6, sp
_0802DB62:
	ldrb r0, [r4]
	lsls r0, r0, #8
	ldr r2, _0802DBC0
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrb r2, [r4, #2]
	lsls r2, r2, #0x10
	ldr r0, _0802DBC8
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	bl AddWindow
	ldr r1, _0802DBCC
	ldr r1, [r1]
	lsls r2, r5, #1
	adds r1, #0x1c
	adds r1, r1, r2
	strh r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl ClearWindowTilemap
	ldrh r0, [r6, #6]
	adds r0, #0x10
	strh r0, [r6, #6]
	adds r4, #4
	adds r5, #1
	cmp r5, r7
	blt _0802DB62
_0802DBA4:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DBB4: .4byte 0x082D1AC0
_0802DBB8: .4byte 0xFFFFFF00
_0802DBBC: .4byte 0x00FFFFFF
_0802DBC0: .4byte 0xFFFF00FF
_0802DBC4: .4byte 0x0000FFFF
_0802DBC8: .4byte 0xFF00FFFF
_0802DBCC: .4byte 0x020229B4
	thumb_func_end sub_0802DB14

	thumb_func_start sub_0802DBD0
sub_0802DBD0: @ 0x0802DBD0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	adds r5, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	add r0, sp, #0xc
	strb r1, [r0]
	strb r2, [r0, #1]
	strb r3, [r0, #2]
	ldr r6, _0802DC64
	ldr r0, [r6]
	lsls r1, r5, #1
	mov r8, r1
	adds r0, #0x1c
	add r0, r8
	ldrb r0, [r0]
	movs r1, #0
	bl FillWindowPixelBuffer
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	adds r0, r5, #0
	bl sub_0802C5DC
	adds r1, r0, #0
	movs r2, #1
	rsbs r2, r2, #0
	mov sb, r2
	movs r0, #0
	bl GetStringWidth
	movs r4, #0x40
	subs r4, r4, r0
	lsrs r4, r4, #1
	adds r0, r5, #0
	bl sub_0802C5DC
	adds r1, r0, #0
	ldr r0, [r6]
	adds r0, #0x1c
	add r0, r8
	ldrb r0, [r0]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	add r2, sp, #0xc
	str r2, [sp]
	mov r2, sb
	str r2, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	adds r2, r4, #0
	movs r3, #2
	bl AddTextPrinterParameterized3
	ldr r0, [r6]
	adds r0, #0x1c
	add r0, r8
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802DC64: .4byte 0x020229B4
	thumb_func_end sub_0802DBD0

	thumb_func_start sub_0802DC68
sub_0802DC68: @ 0x0802DC68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r4, #0
	bne _0802DC92
	movs r4, #0
	cmp r4, r5
	bge _0802DCC4
_0802DC7E:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #3
	bl sub_0802DBD0
	adds r4, #1
	cmp r4, r5
	blt _0802DC7E
	b _0802DCC4
_0802DC92:
	bl sub_0802C5B0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r4, #0
	cmp r4, r5
	bge _0802DCC4
_0802DCA0:
	cmp r6, r4
	beq _0802DCB2
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #3
	bl sub_0802DBD0
	b _0802DCBE
_0802DCB2:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	movs r3, #5
	bl sub_0802DBD0
_0802DCBE:
	adds r4, #1
	cmp r4, r5
	blt _0802DCA0
_0802DCC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DC68

	thumb_func_start sub_0802DCCC
sub_0802DCCC: @ 0x0802DCCC
	push {r4, r5, lr}
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0
	cmp r4, r5
	bge _0802DCF2
_0802DCDC:
	ldr r0, _0802DD00
	ldr r0, [r0]
	lsls r1, r4, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r4, #1
	cmp r4, r5
	blt _0802DCDC
_0802DCF2:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802DD00: .4byte 0x020229B4
	thumb_func_end sub_0802DCCC

	thumb_func_start sub_0802DD04
sub_0802DD04: @ 0x0802DD04
	push {r4, lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0802DD48
	ldr r2, [r0]
	movs r0, #0
	str r0, [r2, #0x18]
	lsrs r1, r1, #0x19
	lsls r1, r1, #0x10
	movs r0, #1
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	ands r4, r0
	lsls r4, r4, #8
	subs r4, #0x28
	lsls r4, r4, #8
	adds r1, r4, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	bl ShowBg
	ldr r0, _0802DD4C
	movs r1, #4
	bl CreateTask
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DD48: .4byte 0x020229B4
_0802DD4C: .4byte 0x0802DD89
	thumb_func_end sub_0802DD04

	thumb_func_start sub_0802DD50
sub_0802DD50: @ 0x0802DD50
	push {r4, lr}
	ldr r4, _0802DD60
	ldr r0, [r4]
	ldr r0, [r0, #0x18]
	cmp r0, #0x1f
	bls _0802DD64
	movs r0, #0
	b _0802DD82
	.align 2, 0
_0802DD60: .4byte 0x020229B4
_0802DD64:
	movs r0, #1
	movs r1, #0x80
	movs r2, #1
	bl ChangeBgY
	ldr r1, [r4]
	ldr r0, [r1, #0x18]
	adds r0, #1
	str r0, [r1, #0x18]
	cmp r0, #0x1f
	bls _0802DD80
	movs r0, #1
	bl HideBg
_0802DD80:
	movs r0, #1
_0802DD82:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802DD50

	thumb_func_start sub_0802DD88
sub_0802DD88: @ 0x0802DD88
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_0802DD50
	cmp r0, #0
	bne _0802DD9C
	adds r0, r4, #0
	bl DestroyTask
_0802DD9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DD88

	thumb_func_start sub_0802DDA4
sub_0802DDA4: @ 0x0802DDA4
	push {lr}
	sub sp, #0xc
	mov r2, sp
	movs r1, #1
	strb r1, [r2]
	ldrh r1, [r0]
	strh r1, [r2, #2]
	ldr r1, [r0, #4]
	str r1, [sp, #8]
	ldr r0, [r0, #8]
	str r0, [sp, #4]
	mov r0, sp
	bl Rfu_SendPacket
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DDA4

	thumb_func_start sub_0802DDC8
sub_0802DDC8: @ 0x0802DDC8
	push {r4, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldr r3, _0802DDFC
	lsls r2, r0, #4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, r1
	bne _0802DDF8
	adds r1, r3, #2
	adds r1, r2, r1
	mov r0, sp
	movs r2, #0xc
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #1
	beq _0802DE00
_0802DDF8:
	movs r0, #0
	b _0802DE10
	.align 2, 0
_0802DDFC: .4byte 0x03003130
_0802DE00:
	mov r0, sp
	ldrh r0, [r0, #2]
	strh r0, [r4]
	ldr r0, [sp, #8]
	str r0, [r4, #4]
	ldr r0, [sp, #4]
	str r0, [r4, #8]
	movs r0, #1
_0802DE10:
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802DDC8

	thumb_func_start sub_0802DE18
sub_0802DE18: @ 0x0802DE18
	push {lr}
	sub sp, #0xc
	mov r2, sp
	movs r1, #2
	strb r1, [r2]
	str r0, [sp, #4]
	mov r0, sp
	bl Rfu_SendPacket
	add sp, #0xc
	pop {r0}
	bx r0
	thumb_func_end sub_0802DE18

	thumb_func_start sub_0802DE30
sub_0802DE30: @ 0x0802DE30
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	mov r3, sp
	movs r2, #3
	strb r2, [r3]
	ldr r3, [r1, #8]
	lsls r3, r3, #0xf
	ldr r2, [sp, #8]
	ldr r4, _0802DEAC
	mov r8, r4
	ands r2, r4
	orrs r2, r3
	str r2, [sp, #8]
	mov r6, sp
	ldrb r2, [r1, #1]
	movs r5, #0x1f
	adds r3, r5, #0
	ands r3, r2
	ldrb r4, [r6, #3]
	movs r2, #0x20
	rsbs r2, r2, #0
	ands r2, r4
	orrs r2, r3
	strb r2, [r6, #3]
	mov r3, sp
	ldrb r2, [r1]
	strb r2, [r3, #1]
	ldrh r2, [r1, #2]
	strh r2, [r3, #6]
	mov r4, sp
	ldrh r2, [r1, #4]
	mov r1, r8
	ands r2, r1
	ldrh r3, [r4, #8]
	ldr r1, _0802DEB0
	ands r1, r3
	orrs r1, r2
	strh r1, [r4, #8]
	mov r2, sp
	ldrh r1, [r0, #0x10]
	strb r1, [r2, #2]
	mov r3, sp
	ldr r1, [r0, #0x14]
	lsls r1, r1, #5
	ldrb r2, [r3, #3]
	ands r5, r2
	orrs r5, r1
	strb r5, [r3, #3]
	mov r1, sp
	ldrh r0, [r0, #0xe]
	strh r0, [r1, #4]
	mov r0, sp
	bl Rfu_SendPacket
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802DEAC: .4byte 0x00007FFF
_0802DEB0: .4byte 0xFFFF8000
	thumb_func_end sub_0802DE30

	thumb_func_start sub_0802DEB4
sub_0802DEB4: @ 0x0802DEB4
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r2, _0802DF1C
	ldrh r0, [r2]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xbc
	lsls r0, r0, #6
	cmp r1, r0
	bne _0802DF20
	adds r1, r2, #2
	mov r0, sp
	movs r2, #0xc
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802DF20
	ldr r0, [sp, #8]
	lsrs r0, r0, #0xf
	str r0, [r4, #8]
	mov r0, sp
	ldrb r1, [r0, #3]
	lsls r0, r1, #0x1b
	lsrs r0, r0, #0x1b
	strb r0, [r4, #1]
	mov r0, sp
	ldrb r0, [r0, #1]
	strb r0, [r4]
	mov r0, sp
	ldrh r0, [r0, #6]
	strh r0, [r4, #2]
	mov r0, sp
	ldrh r0, [r0, #8]
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x11
	strh r0, [r4, #4]
	mov r0, sp
	ldrb r0, [r0, #2]
	strh r0, [r5, #0x10]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	str r1, [r5, #0x14]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r5, #0xe]
	movs r0, #1
	b _0802DF22
	.align 2, 0
_0802DF1C: .4byte 0x03003130
_0802DF20:
	movs r0, #0
_0802DF22:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802DEB4

	thumb_func_start sub_0802DF2C
sub_0802DF2C: @ 0x0802DF2C
	push {r4, lr}
	sub sp, #0xc
	mov r4, sp
	movs r3, #4
	strb r3, [r4]
	ldrh r3, [r0, #0x10]
	strb r3, [r4, #1]
	ldr r3, [r0, #0x14]
	strb r3, [r4, #2]
	ldr r3, [r0, #0x18]
	strb r3, [r4, #3]
	mov r3, sp
	ldrh r0, [r0, #0xe]
	strh r0, [r3, #4]
	mov r0, sp
	strb r1, [r0, #6]
	strh r2, [r0, #8]
	bl Rfu_SendPacket
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DF2C

	thumb_func_start sub_0802DF5C
sub_0802DF5C: @ 0x0802DF5C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r3, _0802DFB8
	lsls r2, r1, #4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, r1
	bne _0802DFBC
	adds r1, r3, #2
	adds r1, r2, r1
	mov r0, sp
	movs r2, #0xc
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #4
	bne _0802DFBC
	mov r0, sp
	ldrb r0, [r0, #1]
	strh r0, [r4, #0x10]
	mov r0, sp
	ldrb r0, [r0, #2]
	str r0, [r4, #0x14]
	mov r0, sp
	ldrb r0, [r0, #3]
	str r0, [r4, #0x18]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r4, #0xe]
	mov r0, sp
	ldrb r0, [r0, #6]
	strb r0, [r5]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r6]
	movs r0, #1
	b _0802DFBE
	.align 2, 0
_0802DFB8: .4byte 0x03003130
_0802DFBC:
	movs r0, #0
_0802DFBE:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802DF5C

	thumb_func_start sub_0802DFC8
sub_0802DFC8: @ 0x0802DFC8
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r3, _0802E014
	lsls r2, r1, #4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, r1
	bne _0802E018
	adds r1, r3, #2
	adds r1, r2, r1
	mov r0, sp
	movs r2, #0xc
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #4
	bne _0802E018
	mov r0, sp
	ldrb r0, [r0, #1]
	strh r0, [r4, #0x10]
	mov r0, sp
	ldrb r0, [r0, #2]
	str r0, [r4, #0x14]
	mov r0, sp
	ldrb r0, [r0, #3]
	str r0, [r4, #0x18]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r4, #0xe]
	movs r0, #1
	b _0802E01A
	.align 2, 0
_0802E014: .4byte 0x03003130
_0802E018:
	movs r0, #0
_0802E01A:
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802DFC8
