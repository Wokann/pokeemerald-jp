.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0803B1DC
sub_0803B1DC: @ 0x0803B1DC
	push {r4, r5, lr}
	ldr r0, _0803B250
	ldr r1, [r0]
	cmp r1, #0
	bne _0803B24A
	ldr r2, _0803B254
	strb r1, [r2]
	ldr r0, _0803B258
	ldrb r0, [r0]
	cmp r1, r0
	bhs _0803B22A
	adds r4, r2, #0
	ldr r5, _0803B25C
_0803B1F6:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803B218
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r1, [r0]
	movs r0, #0
	movs r2, #0
	bl BtlController_EmitSwitchInAnim
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803B218:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803B258
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803B1F6
_0803B22A:
	ldr r2, _0803B260
	ldr r0, [r2]
	adds r0, #0x4c
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xd9
	strb r1, [r0]
	ldr r0, [r2]
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, _0803B264
	ldr r0, _0803B268
	str r0, [r1]
_0803B24A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B250: .4byte 0x02023D0C
_0803B254: .4byte 0x02023D08
_0803B258: .4byte 0x02023D10
_0803B25C: .4byte 0x02023D12
_0803B260: .4byte 0x02024140
_0803B264: .4byte 0x03005A64
_0803B268: .4byte 0x0803B26D
	thumb_func_end sub_0803B1DC
