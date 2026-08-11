.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start HandleLoadWonderCardOrNews
HandleLoadWonderCardOrNews: @ 0x08018818
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08018828
	cmp r0, #1
	beq _08018850
	b _0801886C
_08018828:
	cmp r1, #0
	bne _08018840
	bl GetSavedWonderCard
	adds r4, r0, #0
	bl sav1_get_mevent_buffer_2
	adds r1, r0, #0
	adds r0, r4, #0
	bl InitWonderCardResources
	b _08018848
_08018840:
	bl GetSavedWonderNews
	bl InitWonderNewsResources
_08018848:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _0801886C
_08018850:
	cmp r1, #0
	bne _0801885E
	bl FadeToWonderCardMenu
_08018858:
	cmp r0, #0
	bne _08018864
	b _0801886C
_0801885E:
	bl FadeToWonderNewsMenu
	b _08018858
_08018864:
	movs r0, #0
	strb r0, [r5]
	movs r0, #1
	b _0801886E
_0801886C:
	movs r0, #0
_0801886E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end HandleLoadWonderCardOrNews
