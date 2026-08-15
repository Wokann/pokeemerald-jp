.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start ScanlineEffect_Stop
ScanlineEffect_Stop: @ 0x080B9710
	push {r4, lr}
	ldr r4, _080B9740
	movs r0, #0
	strb r0, [r4, #0x15]
	ldr r1, _080B9744
	ldrh r2, [r1, #0xa]
	ldr r0, _080B9748
	ands r0, r2
	strh r0, [r1, #0xa]
	ldrh r2, [r1, #0xa]
	ldr r0, _080B974C
	ands r0, r2
	strh r0, [r1, #0xa]
	ldrh r0, [r1, #0xa]
	ldrb r0, [r4, #0x18]
	cmp r0, #0xff
	beq _080B973A
	bl DestroyTask
	movs r0, #0xff
	strb r0, [r4, #0x18]
_080B973A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9740: .4byte 0x020397C8
_080B9744: .4byte 0x040000B0
_080B9748: .4byte 0x0000C5FF
_080B974C: .4byte 0x00007FFF
	thumb_func_end ScanlineEffect_Stop

	thumb_func_start ScanlineEffect_Clear
ScanlineEffect_Clear: @ 0x080B9750
	push {r4, lr}
	sub sp, #4
	mov r0, sp
	movs r4, #0
	strh r4, [r0]
	ldr r1, _080B9784
	ldr r2, _080B9788
	bl CpuSet
	ldr r0, _080B978C
	movs r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	str r1, [r0, #0xc]
	strb r4, [r0, #0x14]
	strb r4, [r0, #0x15]
	strb r4, [r0, #0x16]
	strb r4, [r0, #0x17]
	movs r1, #0xff
	strb r1, [r0, #0x18]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9784: .4byte 0x020388C8
_080B9788: .4byte 0x01000780
_080B978C: .4byte 0x020397C8
	thumb_func_end ScanlineEffect_Clear

	thumb_func_start ScanlineEffect_SetParams
ScanlineEffect_SetParams: @ 0x080B9790
	push {lr}
	sub sp, #0xc
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r0, _080B97B4
	cmp r1, r0
	bne _080B97C4
	ldr r0, _080B97B8
	ldr r1, _080B97BC
	str r1, [r0]
	movs r2, #0xf0
	lsls r2, r2, #3
	adds r1, r1, r2
	str r1, [r0, #4]
	ldr r1, _080B97C0
	b _080B97D4
	.align 2, 0
_080B97B4: .4byte 0xA2600001
_080B97B8: .4byte 0x020397C8
_080B97BC: .4byte 0x020388CA
_080B97C0: .4byte 0x080B988D
_080B97C4:
	ldr r0, _080B97F4
	ldr r1, _080B97F8
	str r1, [r0]
	movs r2, #0xf0
	lsls r2, r2, #3
	adds r1, r1, r2
	str r1, [r0, #4]
	ldr r1, _080B97FC
_080B97D4:
	str r1, [r0, #0x10]
	adds r1, r0, #0
	ldr r0, [sp, #4]
	str r0, [r1, #0xc]
	ldr r0, [sp]
	str r0, [r1, #8]
	mov r0, sp
	ldrb r0, [r0, #8]
	strb r0, [r1, #0x15]
	mov r0, sp
	ldrb r0, [r0, #9]
	strb r0, [r1, #0x16]
	strb r0, [r1, #0x17]
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_080B97F4: .4byte 0x020397C8
_080B97F8: .4byte 0x020388CC
_080B97FC: .4byte 0x080B98AD
	thumb_func_end ScanlineEffect_SetParams
