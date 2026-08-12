.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start ResetPokemonJumpRecords
ResetPokemonJumpRecords: @ 0x0802E034
	push {lr}
	bl sub_0802E024
	movs r1, #0
	strh r1, [r0]
	str r1, [r0, #0xc]
	strh r1, [r0, #4]
	strh r1, [r0, #6]
	str r1, [r0, #8]
	strh r1, [r0, #2]
	pop {r0}
	bx r0
	thumb_func_end ResetPokemonJumpRecords

	thumb_func_start sub_0802E04C
sub_0802E04C: @ 0x0802E04C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	bl sub_0802E024
	adds r1, r0, #0
	movs r2, #0
	ldr r0, [r1, #0xc]
	cmp r0, r4
	bhs _0802E070
	ldr r0, _0802E098
	cmp r4, r0
	bhi _0802E070
	str r4, [r1, #0xc]
	movs r2, #1
_0802E070:
	ldrh r0, [r1]
	cmp r0, r5
	bhs _0802E080
	ldr r0, _0802E09C
	cmp r5, r0
	bhi _0802E080
	strh r5, [r1]
	movs r2, #1
_0802E080:
	ldrh r0, [r1, #4]
	cmp r0, r6
	bhs _0802E090
	ldr r0, _0802E09C
	cmp r6, r0
	bhi _0802E090
	strh r6, [r1, #4]
	movs r2, #1
_0802E090:
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802E098: .4byte 0x00018696
_0802E09C: .4byte 0x0000270F
	thumb_func_end sub_0802E04C
