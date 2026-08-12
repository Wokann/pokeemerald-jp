.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified






	thumb_func_start sub_08026888
sub_08026888: @ 0x08026888
	push {r4, r5, lr}
	ldr r0, _080268B0
	ldr r0, [r0]
	adds r0, #0x24
	ldrb r5, [r0]
	movs r4, #0
	cmp r4, r5
	bhs _080268AA
_08026898:
	adds r0, r4, #0
	movs r1, #4
	bl sub_080283E0
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r5
	blo _08026898
_080268AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080268B0: .4byte 0x0202294C
	thumb_func_end sub_08026888

	thumb_func_start sub_080268B4
sub_080268B4: @ 0x080268B4
	push {lr}
	bl sub_08026748
	ldr r0, _080268CC
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _080268D0
	bl sub_08026888
	b _080268D4
	.align 2, 0
_080268CC: .4byte 0x0202294C
_080268D0:
	bl sub_08026848
_080268D4:
	ldr r0, _080268E4
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	bl sub_08028600
	pop {r0}
	bx r0
	.align 2, 0
_080268E4: .4byte 0x0202294C
	thumb_func_end sub_080268B4

	thumb_func_start sub_080268E8
sub_080268E8: @ 0x080268E8
	push {lr}
	bl sub_08026748
	ldr r0, _08026900
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _08026904
	bl sub_08026888
	b _08026908
	.align 2, 0
_08026900: .4byte 0x0202294C
_08026904:
	bl sub_08026848
_08026908:
	ldr r0, _08026918
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	bl sub_08028600
	pop {r0}
	bx r0
	.align 2, 0
_08026918: .4byte 0x0202294C
	thumb_func_end sub_080268E8

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
