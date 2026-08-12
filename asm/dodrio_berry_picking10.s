.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified









	thumb_func_start sub_0802691C
sub_0802691C: @ 0x0802691C
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #4
	bhi _08026974
	lsls r0, r0, #2
	ldr r1, _08026934
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026934: .4byte 0x08026938
_08026938: @ jump table
	.4byte _0802694C @ case 0
	.4byte _08026954 @ case 1
	.4byte _0802695C @ case 2
	.4byte _08026964 @ case 3
	.4byte _0802696C @ case 4
_0802694C:
	movs r0, #4
	strb r0, [r3]
	movs r0, #7
	b _08026972
_08026954:
	movs r0, #3
	strb r0, [r3]
	movs r0, #8
	b _08026972
_0802695C:
	movs r0, #2
	strb r0, [r3]
	movs r0, #9
	b _08026972
_08026964:
	movs r0, #1
	strb r0, [r3]
	movs r0, #0xa
	b _08026972
_0802696C:
	movs r0, #0
	strb r0, [r3]
	movs r0, #0xb
_08026972:
	strb r0, [r2]
_08026974:
	pop {r0}
	bx r0
	thumb_func_end sub_0802691C
