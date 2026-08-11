.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start sub_0801785C
sub_0801785C: @ 0x0801785C
	push {lr}
	adds r3, r0, #0
	cmp r1, #0x44
	beq _08017898
	cmp r1, #0x44
	bgt _0801786E
	cmp r1, #0x41
	beq _08017878
	b _080178B6
_0801786E:
	cmp r1, #0x45
	beq _08017888
	cmp r1, #0x48
	beq _080178A8
	b _080178B6
_08017878:
	ldr r0, _08017884
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	b _0801789A
	.align 2, 0
_08017884: .4byte 0x082C1224
_08017888:
	ldr r0, _08017894
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	b _0801789A
	.align 2, 0
_08017894: .4byte 0x082C13C4
_08017898:
	ldr r1, _080178A4
_0801789A:
	adds r0, r3, #0
	bl StringExpandPlaceholders
	b _080178B6
	.align 2, 0
_080178A4: .4byte 0x082C1998
_080178A8:
	ldr r0, _080178BC
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r3, #0
	bl StringExpandPlaceholders
_080178B6:
	pop {r0}
	bx r0
	.align 2, 0
_080178BC: .4byte 0x082C127C
	thumb_func_end sub_0801785C

	thumb_func_start sub_080178C0
sub_080178C0: @ 0x080178C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r6, r4, #0
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r2, _080178F4
	movs r0, #1
	adds r1, r3, #0
	eors r1, r0
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #0x13]
	cmp r4, #0x44
	beq _08017914
	cmp r4, #0x44
	bgt _080178F8
	cmp r4, #0x41
	beq _080178FE
	b _08017954
	.align 2, 0
_080178F4: .4byte 0x020226A0
_080178F8:
	cmp r6, #0x45
	beq _08017938
	b _08017954
_080178FE:
	ldr r2, _08017910
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r1, r1, r0
	b _08017926
	.align 2, 0
_08017910: .4byte 0x082C1188
_08017914:
	ldr r2, _08017934
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r2, #8
_08017926:
	adds r1, r1, r2
	ldr r1, [r1]
	adds r0, r5, #0
	bl StringCopy
	b _08017954
	.align 2, 0
_08017934: .4byte 0x082C1188
_08017938:
	ldr r2, _0801795C
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r2, #4
	adds r1, r1, r2
	ldr r1, [r1]
	adds r0, r5, #0
	bl StringCopy
_08017954:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801795C: .4byte 0x082C1188
	thumb_func_end sub_080178C0
