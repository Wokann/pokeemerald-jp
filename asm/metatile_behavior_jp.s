.include "asm/macros.inc"
.include "constants/constants.inc"
.syntax unified

	.section .text.Unref_MetatileBehavior_IsSecretBaseUnused_B2_2, "ax", %progbits
thumb_func_start Unref_MetatileBehavior_IsSecretBaseUnused_B2_2
Unref_MetatileBehavior_IsSecretBaseUnused_B2_2: @ 0x08088C14
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb2
	beq _08088C22
	movs r0, #0
	b _08088C24
_08088C22:
	movs r0, #1
_08088C24:
	pop {r1}
	bx r1
	thumb_func_end Unref_MetatileBehavior_IsSecretBaseUnused_B2_2

	.section .text.MetatileBehavior_IsBlockDecoration, "ax", %progbits
thumb_func_start MetatileBehavior_IsBlockDecoration
MetatileBehavior_IsBlockDecoration: @ 0x08088C28
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb3
	beq _08088C36
	movs r0, #0
	b _08088C38
_08088C36:
	movs r0, #1
_08088C38:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsBlockDecoration

	.section .text.MetatileBehavior_IsMB_C6, "ax", %progbits
thumb_func_start MetatileBehavior_IsMB_C6
MetatileBehavior_IsMB_C6: @ 0x08088C50
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc6
	beq _08088C5E
	movs r0, #0
	b _08088C60
_08088C5E:
	movs r0, #1
_08088C60:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsMB_C6

	.section .text.Unref_MetatileBehavior_IsSecretBaseUnused_B2, "ax", %progbits
thumb_func_start Unref_MetatileBehavior_IsSecretBaseUnused_B2
Unref_MetatileBehavior_IsSecretBaseUnused_B2: @ 0x08088CA0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb2
	beq _08088CAE
	movs r0, #0
	b _08088CB0
_08088CAE:
	movs r0, #1
_08088CB0:
	pop {r1}
	bx r1
	thumb_func_end Unref_MetatileBehavior_IsSecretBaseUnused_B2

	.section .text.MetatileBehavior_IsBridge, "ax", %progbits
thumb_func_start MetatileBehavior_IsBridge
MetatileBehavior_IsBridge: @ 0x08088E10
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r2, #0x90
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _08088E2E
	adds r0, r1, #0
	subs r0, #0x7c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08088E32
_08088E2E:
	movs r0, #1
	b _08088E34
_08088E32:
	movs r0, #0
_08088E34:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsBridge

	.section .text.MetatileBehavior_8089510, "ax", %progbits
thumb_func_start MetatileBehavior_8089510
MetatileBehavior_8089510: @ 0x08088E74
	push {lr}
	lsls r0, r0, #0x18
	movs r1, #0x90
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _08088E88
	movs r0, #0
	b _08088E8A
_08088E88:
	movs r0, #1
_08088E8A:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MetatileBehavior_8089510

	.section .text.MetatileBehavior_IsUnknownClosedDoor, "ax", %progbits
thumb_func_start MetatileBehavior_IsUnknownClosedDoor
MetatileBehavior_IsUnknownClosedDoor: @ 0x08089170
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xea
	beq _0808917E
	movs r0, #0
	b _08089180
_0808917E:
	movs r0, #1
_08089180:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsUnknownClosedDoor

	.section .text.MetatileBehavior_IsWarpOrBridge, "ax", %progbits
thumb_func_start MetatileBehavior_IsWarpOrBridge
MetatileBehavior_IsWarpOrBridge: @ 0x08089210
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x70
	beq _0808921E
	movs r0, #0
	b _08089220
_0808921E:
	movs r0, #1
_08089220:
	pop {r1}
	bx r1
	thumb_func_end MetatileBehavior_IsWarpOrBridge
