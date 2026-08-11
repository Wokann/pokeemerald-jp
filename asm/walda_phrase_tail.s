.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_081D9690
sub_081D9690: @ 0x081D9690
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _081D96B4
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r1, #0x1a
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bhi _081D9750
	lsls r0, r0, #2
	ldr r1, _081D96B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081D96B4: .4byte 0x03005B60
_081D96B8: .4byte 0x081D96BC
_081D96BC: @ jump table
	.4byte _081D96D0 @ case 0
	.4byte _081D96F0 @ case 1
	.4byte _081D9710 @ case 2
	.4byte _081D9730 @ case 3
	.4byte _081D9750 @ case 4
_081D96D0:
	ldr r4, _081D96E4
	ldr r0, _081D96E8
	ldrb r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081D96EC
	adds r0, r0, r1
	movs r1, #0x32
	b _081D9760
	.align 2, 0
_081D96E4: .4byte 0x02039BD1
_081D96E8: .4byte 0x02039BC4
_081D96EC: .4byte 0x02024190
_081D96F0:
	ldr r4, _081D9704
	ldr r0, _081D9708
	ldrb r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081D970C
	adds r0, r0, r1
	movs r1, #0x33
	b _081D9760
	.align 2, 0
_081D9704: .4byte 0x02039BD1
_081D9708: .4byte 0x02039BC4
_081D970C: .4byte 0x02024190
_081D9710:
	ldr r4, _081D9724
	ldr r0, _081D9728
	ldrb r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081D972C
	adds r0, r0, r1
	movs r1, #0x34
	b _081D9760
	.align 2, 0
_081D9724: .4byte 0x02039BD1
_081D9728: .4byte 0x02039BC4
_081D972C: .4byte 0x02024190
_081D9730:
	ldr r4, _081D9744
	ldr r0, _081D9748
	ldrb r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081D974C
	adds r0, r0, r1
	movs r1, #0x35
	b _081D9760
	.align 2, 0
_081D9744: .4byte 0x02039BD1
_081D9748: .4byte 0x02039BC4
_081D974C: .4byte 0x02024190
_081D9750:
	ldr r4, _081D97A0
	ldr r0, _081D97A4
	ldrb r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081D97A8
	adds r0, r0, r1
	movs r1, #0x36
_081D9760:
	bl GetMonData3
	strb r0, [r4]
	ldr r5, _081D97AC
	ldr r4, _081D97B0
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldr r1, _081D97A0
	ldrb r1, [r1]
	adds r0, #0x2c
	strb r1, [r0]
	ldr r0, _081D97B4
	bl FlagGet
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	ldrb r1, [r4]
	lsls r1, r1, #6
	adds r1, r1, r5
	adds r1, #0x2d
	strb r0, [r1]
	ldr r1, _081D97B8
	ldr r2, _081D97BC
	adds r0, r6, #0
	bl SetTaskFuncWithFollowupFunc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D97A0: .4byte 0x02039BD1
_081D97A4: .4byte 0x02039BC4
_081D97A8: .4byte 0x02024190
_081D97AC: .4byte 0x02039AA0
_081D97B0: .4byte 0x02039BC5
_081D97B4: .4byte 0x00000864
_081D97B8: .4byte 0x081D9A0D
_081D97BC: .4byte 0x081D97C1
	thumb_func_end sub_081D9690

	thumb_func_start GetLetterTableId
GetLetterTableId: @ 0x081D97C0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _081D97D4
	ldr r2, _081D97D8
	bl SetTaskFuncWithFollowupFunc
	pop {r0}
	bx r0
	.align 2, 0
_081D97D4: .4byte 0x081D9AD5
_081D97D8: .4byte 0x081D97DD
	thumb_func_end GetLetterTableId
