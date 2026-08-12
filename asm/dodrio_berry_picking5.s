.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_08027A64
sub_08027A64: @ 0x08027A64
	push {r4, r5, r6, r7, lr}
	ldr r0, _08027AEC
	ldr r0, [r0]
	adds r0, #0x24
	ldrb r4, [r0]
	cmp r4, #4
	bhi _08027A92
	ldr r5, _08027AF0
_08027A74:
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _08027AF4
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r5
	ldr r1, [r1]
	bl StringCopy
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #4
	bls _08027A74
_08027A92:
	ldr r0, _08027AEC
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #5
	strb r2, [r1]
	movs r1, #0
	mov ip, r0
_08027AA0:
	movs r4, #0
	mov r2, ip
	ldr r0, [r2]
	adds r0, #0x24
	adds r5, r1, #1
	ldrb r0, [r0]
	cmp r4, r0
	bhs _08027ADE
	ldr r7, _08027AEC
	lsls r3, r1, #1
	ldr r6, _08027AF8
_08027AB6:
	ldr r2, [r7]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r3, r0
	adds r1, r2, #0
	adds r1, #0x4a
	adds r1, r1, r0
	lsls r0, r4, #3
	adds r0, r3, r0
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r2, #0x24
	ldrb r2, [r2]
	cmp r4, r2
	blo _08027AB6
_08027ADE:
	lsls r0, r5, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _08027AA0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027AEC: .4byte 0x0202294C
_08027AF0: .4byte 0x082CB41C
_08027AF4: .4byte 0x020226A8
_08027AF8: .4byte 0x082CB3DC
	thumb_func_end sub_08027A64

