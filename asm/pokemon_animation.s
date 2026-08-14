.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start pokemonanimfunc_88
pokemonanimfunc_88: @ 0x08184598
	push {r4, lr}
	adds r4, r0, #0
	bl HandleStartAffineAnim
	movs r2, #0
	movs r1, #4
	strh r1, [r4, #0x3c]
	movs r0, #0xc
	strh r0, [r4, #0x3a]
	movs r0, #0x10
	strh r0, [r4, #0x38]
	strh r1, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #2
	strh r0, [r4, #0x32]
	ldr r0, _081845C0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081845C0: .4byte 0x08184481
	thumb_func_end pokemonanimfunc_88

	thumb_func_start pokemonanimfunc_89
pokemonanimfunc_89: @ 0x081845C4
	push {r4, lr}
	adds r4, r0, #0
	bl HandleStartAffineAnim
	movs r2, #0
	movs r1, #2
	strh r1, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x3a]
	movs r0, #0xc
	strh r0, [r4, #0x38]
	strh r1, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #1
	strh r0, [r4, #0x32]
	ldr r0, _081845EC
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081845EC: .4byte 0x08184481
	thumb_func_end pokemonanimfunc_89

	thumb_func_start pokemonanimfunc_8A
pokemonanimfunc_8A: @ 0x081845F0
	push {r4, lr}
	adds r4, r0, #0
	bl HandleStartAffineAnim
	movs r1, #0
	strh r1, [r4, #0x3c]
	movs r0, #6
	strh r0, [r4, #0x3a]
	strh r0, [r4, #0x38]
	movs r0, #2
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x34]
	movs r0, #1
	strh r0, [r4, #0x32]
	ldr r0, _08184618
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08184618: .4byte 0x08184481
	thumb_func_end pokemonanimfunc_8A

	thumb_func_start sub_0818461C
sub_0818461C: @ 0x0818461C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x30]
	strh r0, [r1, #0x24]
	ldrh r2, [r1, #0x2e]
	movs r3, #0x2e
	ldrsh r0, [r1, r3]
	cmp r0, #1
	ble _0818463A
	movs r2, #0x30
	ldrsh r0, [r1, r2]
	rsbs r0, r0, #0
	strh r0, [r1, #0x30]
	movs r0, #0
	b _0818463C
_0818463A:
	adds r0, r2, #1
_0818463C:
	strh r0, [r1, #0x2e]
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0818461C

	thumb_func_start BackAnimBlendYellow
BackAnimBlendYellow: @ 0x08184644
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08184674
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl sub_0818461C
	movs r1, #0x3a
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r1, r0, r5
	ldrb r0, [r1, #1]
	cmp r0, #0xff
	bne _0818467C
	movs r0, #0
	strh r0, [r4, #0x24]
	ldr r0, _08184678
	str r0, [r4, #0x1c]
	b _081846DA
	.align 2, 0
_08184674: .4byte 0x085D38DC
_08184678: .4byte 0x08184C35
_0818467C:
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	cmp r0, #1
	bne _081846AC
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818469C
	ldrh r0, [r4, #0x3c]
	ldr r3, _08184698
	movs r1, #0x10
	movs r2, #0x10
	bl BlendPalette
	b _081846A8
	.align 2, 0
_08184698: .4byte 0x000003FF
_0818469C:
	ldrh r0, [r4, #0x3c]
	ldr r3, _081846D0
	movs r1, #0x10
	movs r2, #0
	bl BlendPalette
_081846A8:
	movs r0, #0
	strh r0, [r4, #0x36]
_081846AC:
	movs r1, #0x3a
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r1, [r0, #1]
	movs r2, #0x38
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _081846D4
	movs r1, #0
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x38]
	ldrh r0, [r4, #0x3a]
	adds r0, #1
	strh r0, [r4, #0x3a]
	b _081846DA
	.align 2, 0
_081846D0: .4byte 0x000003FF
_081846D4:
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
_081846DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end BackAnimBlendYellow

	thumb_func_start pokemonanimfunc_8B
pokemonanimfunc_8B: @ 0x081846E0
	push {r4, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x32]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _0818470C
	ldrb r0, [r2, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	strh r3, [r2, #0x3a]
	strh r3, [r2, #0x38]
	strh r3, [r2, #0x36]
	strh r3, [r2, #0x34]
_0818470C:
	adds r0, r2, #0
	bl BackAnimBlendYellow
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8B

	thumb_func_start pokemonanimfunc_8C
pokemonanimfunc_8C: @ 0x08184718
	push {r4, r5, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x32]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x32]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #1
	bne _08184744
	ldrb r0, [r2, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r5, #0
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	strh r3, [r2, #0x3a]
	strh r3, [r2, #0x38]
	strh r3, [r2, #0x36]
	strh r4, [r2, #0x34]
_08184744:
	adds r0, r2, #0
	bl BackAnimBlendYellow
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8C

	thumb_func_start pokemonanimfunc_8D
pokemonanimfunc_8D: @ 0x08184750
	push {r4, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x32]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _0818477E
	ldrb r0, [r2, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	strh r3, [r2, #0x3a]
	strh r3, [r2, #0x38]
	strh r3, [r2, #0x36]
	movs r0, #2
	strh r0, [r2, #0x34]
_0818477E:
	adds r0, r2, #0
	bl BackAnimBlendYellow
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_8D

	thumb_func_start BackAnimBlend
BackAnimBlend: @ 0x0818478C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0x7f
	ble _081847B0
	ldrh r0, [r4, #0x3c]
	movs r1, #0x10
	movs r2, #0
	movs r3, #0x1f
	bl BlendPalette
	ldr r0, _081847AC
	str r0, [r4, #0x1c]
	b _081847D6
	.align 2, 0
_081847AC: .4byte 0x08184C35
_081847B0:
	movs r5, #0x32
	ldrsh r0, [r4, r5]
	movs r1, #0xc
	bl Sin
	adds r2, r0, #0
	strh r2, [r4, #0x3a]
	ldrh r0, [r4, #0x3c]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r3, _081847DC
	movs r5, #0x30
	ldrsh r1, [r4, r5]
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r3, [r1]
	movs r1, #0x10
	bl BlendPalette
_081847D6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081847DC: .4byte 0x085D38E8
	thumb_func_end BackAnimBlend

	thumb_func_start sub_081847E0
sub_081847E0: @ 0x081847E0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _08184878
	adds r0, r4, #0
	bl sub_0817F5B8
	movs r3, #0x38
	ldrsh r1, [r4, r3]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _0818481C
	ldrh r0, [r4, #0x34]
	adds r0, #1
	movs r2, #0
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x36
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _08184818
	strh r2, [r4, #0x38]
_08184818:
	strh r2, [r4, #0x24]
	b _08184872
_0818481C:
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0xf
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	bl __divsi3
	adds r1, r0, #0
	cmp r1, #0
	bge _08184850
	adds r0, #0xff
_08184850:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #6
	bl Sin
	lsls r1, r5, #0x18
	asrs r1, r1, #0x18
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, #0
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
_08184872:
	adds r0, r4, #0
	bl sub_0817F5B8
_08184878:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081847E0

	thumb_func_start pokemonanimfunc_8E
pokemonanimfunc_8E: @ 0x08184880
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _081848AA
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0xa
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #2
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r2, [r4, #0x30]
_081848AA:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081848BA
	adds r0, r4, #0
	bl BackAnimBlend
_081848BA:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _081848DC
	adds r0, r4, #0
	bl sub_081847E0
_081848DC:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8E

	thumb_func_start pokemonanimfunc_8F
pokemonanimfunc_8F: @ 0x081848E8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184912
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r2, [r4, #0x30]
_08184912:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184922
	adds r0, r4, #0
	bl BackAnimBlend
_08184922:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184944
	adds r0, r4, #0
	bl sub_081847E0
_08184944:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8F

	thumb_func_start pokemonanimfunc_90
pokemonanimfunc_90: @ 0x08184950
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _0818497A
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x50
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r2, [r4, #0x30]
_0818497A:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0818498A
	adds r0, r4, #0
	bl BackAnimBlend
_0818498A:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _081849AC
	adds r0, r4, #0
	bl sub_081847E0
_081849AC:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_90

	thumb_func_start pokemonanimfunc_91
pokemonanimfunc_91: @ 0x081849B8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _081849E4
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0xa
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #2
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #1
	strh r0, [r4, #0x30]
_081849E4:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081849F4
	adds r0, r4, #0
	bl BackAnimBlend
_081849F4:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184A16
	adds r0, r4, #0
	bl sub_081847E0
_08184A16:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_91

	thumb_func_start pokemonanimfunc_92
pokemonanimfunc_92: @ 0x08184A24
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184A4E
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r0, [r4, #0x30]
_08184A4E:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184A5E
	adds r0, r4, #0
	bl BackAnimBlend
_08184A5E:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184A80
	adds r0, r4, #0
	bl sub_081847E0
_08184A80:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_92

	thumb_func_start pokemonanimfunc_93
pokemonanimfunc_93: @ 0x08184A8C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184AB6
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x50
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r0, [r4, #0x30]
_08184AB6:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184AC6
	adds r0, r4, #0
	bl BackAnimBlend
_08184AC6:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184AE8
	adds r0, r4, #0
	bl sub_081847E0
_08184AE8:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_93

	thumb_func_start pokemonanimfunc_94
pokemonanimfunc_94: @ 0x08184AF4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184B1E
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0xa
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #2
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r0, [r4, #0x30]
_08184B1E:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184B2E
	adds r0, r4, #0
	bl BackAnimBlend
_08184B2E:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184B50
	adds r0, r4, #0
	bl sub_081847E0
_08184B50:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_94

	thumb_func_start pokemonanimfunc_95
pokemonanimfunc_95: @ 0x08184B5C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184B88
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #2
	strh r0, [r4, #0x30]
_08184B88:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184B98
	adds r0, r4, #0
	bl BackAnimBlend
_08184B98:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184BBA
	adds r0, r4, #0
	bl sub_081847E0
_08184BBA:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_95

	thumb_func_start pokemonanimfunc_96
pokemonanimfunc_96: @ 0x08184BC8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184BF4
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x50
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #2
	strh r0, [r4, #0x30]
_08184BF4:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184C04
	adds r0, r4, #0
	bl BackAnimBlend
_08184C04:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184C26
	adds r0, r4, #0
	bl sub_081847E0
_08184C26:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_96

	thumb_func_start SpriteCB_SetDummyOnAnimEnd
SpriteCB_SetDummyOnAnimEnd: @ 0x08184C34
	push {lr}
	adds r2, r0, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08184C48
	ldr r0, _08184C4C
	str r0, [r2, #0x1c]
_08184C48:
	pop {r0}
	bx r0
	.align 2, 0
_08184C4C: .4byte 0x08007141
	thumb_func_end SpriteCB_SetDummyOnAnimEnd

