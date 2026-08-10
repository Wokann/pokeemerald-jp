.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start RedrawMapSlicesForCameraUpdate
RedrawMapSlicesForCameraUpdate: @ 0x08089648
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _08089690
	ldr r4, [r0]
	cmp r6, #0
	ble _08089660
	adds r0, r5, #0
	adds r1, r4, #0
	bl RedrawMapSliceWest
_08089660:
	cmp r6, #0
	bge _0808966C
	adds r0, r5, #0
	adds r1, r4, #0
	bl RedrawMapSliceEast
_0808966C:
	cmp r7, #0
	ble _08089678
	adds r0, r5, #0
	adds r1, r4, #0
	bl RedrawMapSliceNorth
_08089678:
	cmp r7, #0
	bge _08089684
	adds r0, r5, #0
	adds r1, r4, #0
	bl RedrawMapSliceSouth
_08089684:
	movs r0, #1
	strb r0, [r5, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08089690: .4byte 0x02036FB8
	thumb_func_end RedrawMapSlicesForCameraUpdate
	thumb_func_start RedrawMapSliceNorth
RedrawMapSliceNorth: @ 0x08089694
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	ldrb r0, [r5, #3]
	adds r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080896AC
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080896AC:
	lsls r6, r0, #5
	movs r4, #0
_080896B0:
	ldrb r0, [r5, #2]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080896C2
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080896C2:
	adds r1, r6, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080896F0
	ldr r3, [r0]
	movs r0, #0
	ldrsh r2, [r3, r0]
	lsrs r0, r4, #1
	adds r2, r2, r0
	movs r0, #2
	ldrsh r3, [r3, r0]
	adds r3, #0xe
	adds r0, r7, #0
	bl DrawMetatileAt
	adds r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x1f
	bls _080896B0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080896F0: .4byte 0x03005AEC
	thumb_func_end RedrawMapSliceNorth
	thumb_func_start RedrawMapSliceSouth
RedrawMapSliceSouth: @ 0x080896F4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	ldrb r0, [r5, #3]
	lsls r6, r0, #5
	movs r4, #0
_08089700:
	ldrb r0, [r5, #2]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08089712
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08089712:
	adds r1, r6, r0
	ldr r0, _0808973C
	ldr r3, [r0]
	movs r0, #0
	ldrsh r2, [r3, r0]
	lsrs r0, r4, #1
	adds r2, r2, r0
	movs r0, #2
	ldrsh r3, [r3, r0]
	adds r0, r7, #0
	bl DrawMetatileAt
	adds r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x1f
	bls _08089700
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808973C: .4byte 0x03005AEC
	thumb_func_end RedrawMapSliceSouth
	thumb_func_start RedrawMapSliceEast
RedrawMapSliceEast: @ 0x08089740
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r1
	ldrb r6, [r5, #2]
	movs r4, #0
_0808974E:
	ldrb r0, [r5, #3]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _08089760
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08089760:
	lsls r1, r0, #5
	adds r1, r1, r6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08089794
	ldr r0, [r0]
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r7, #2
	ldrsh r3, [r0, r7]
	lsrs r0, r4, #1
	adds r3, r3, r0
	mov r0, r8
	bl DrawMetatileAt
	adds r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x1f
	bls _0808974E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08089794: .4byte 0x03005AEC
	thumb_func_end RedrawMapSliceEast
	thumb_func_start RedrawMapSliceWest
RedrawMapSliceWest: @ 0x08089798
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	ldrb r0, [r6, #2]
	adds r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x1f
	bls _080897B6
	adds r0, r5, #0
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080897B6:
	movs r4, #0
_080897B8:
	ldrb r0, [r6, #3]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080897CA
	subs r0, #0x20
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080897CA:
	lsls r1, r0, #5
	adds r1, r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08089800
	ldr r0, [r0]
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r2, #0xe
	movs r7, #2
	ldrsh r3, [r0, r7]
	lsrs r0, r4, #1
	adds r3, r3, r0
	mov r0, r8
	bl DrawMetatileAt
	adds r0, r4, #2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x1f
	bls _080897B8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08089800: .4byte 0x03005AEC
	thumb_func_end RedrawMapSliceWest
	thumb_func_start CurrentMapDrawMetatileAt
CurrentMapDrawMetatileAt: @ 0x08089804
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r6, _08089838
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl MapPosToBgTilemapOffset
	adds r1, r0, #0
	cmp r1, #0
	blt _08089830
	ldr r0, _0808983C
	ldr r0, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r2, r4, #0
	adds r3, r5, #0
	bl DrawMetatileAt
	movs r0, #1
	strb r0, [r6, #4]
_08089830:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08089838: .4byte 0x03000E20
_0808983C: .4byte 0x02036FB8
	thumb_func_end CurrentMapDrawMetatileAt
	thumb_func_start DrawDoorMetatileAt
DrawDoorMetatileAt: @ 0x08089840
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r6, _08089870
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r4, #0
	bl MapPosToBgTilemapOffset
	cmp r0, #0
	blt _08089868
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	movs r0, #1
	adds r1, r5, #0
	bl DrawMetatile
	movs r0, #1
	strb r0, [r6, #4]
_08089868:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08089870: .4byte 0x03000E20
	thumb_func_end DrawDoorMetatileAt
	thumb_func_start DrawMetatileAt
DrawMetatileAt: @ 0x08089874
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r2, #0
	adds r7, r3, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	adds r0, r6, #0
	adds r1, r7, #0
	bl MapGridGetMetatileIdAt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r4, r0
	bls _0808989C
	movs r4, #0
_0808989C:
	ldr r0, _080898A8
	cmp r4, r0
	bhi _080898AC
	ldr r0, [r5, #0x10]
	ldr r5, [r0, #0xc]
	b _080898B8
	.align 2, 0
_080898A8: .4byte 0x000001FF
_080898AC:
	ldr r0, [r5, #0x14]
	ldr r5, [r0, #0xc]
	ldr r1, _080898D8
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080898B8:
	adds r0, r6, #0
	adds r1, r7, #0
	bl MapGridGetMetatileLayerTypeAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r4, #4
	adds r1, r5, r1
	mov r2, r8
	bl DrawMetatile
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080898D8: .4byte 0xFFFFFE00
	thumb_func_end DrawMetatileAt
