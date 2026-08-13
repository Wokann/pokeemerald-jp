.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start SpriteCB_AnimFaintOpponent
SpriteCB_AnimFaintOpponent: @ 0x0803968C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x36]
	subs r0, #1
	strh r0, [r4, #0x36]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803970C
	movs r0, #2
	strh r0, [r4, #0x36]
	ldrh r0, [r4, #0x26]
	adds r0, #8
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x34]
	subs r0, #1
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080396C0
	adds r0, r4, #0
	bl FreeSpriteOamMatrix
	adds r0, r4, #0
	bl DestroySprite
	b _0803970C
_080396C0:
	ldrh r0, [r4, #0x2e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerPosition
	ldr r1, _08039714
	ldr r1, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r1, #4
	adds r1, r1, r0
	ldr r2, _08039718
	movs r3, #0x2e
	ldrsh r0, [r4, r3]
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0xb
	ldr r1, [r1]
	adds r1, r1, r0
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	lsls r0, r0, #8
	adds r1, r1, r0
	movs r2, #0
	movs r0, #0xff
_080396F2:
	strb r2, [r1]
	adds r1, #1
	subs r0, #1
	cmp r0, #0
	bge _080396F2
	ldr r0, _08039718
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	adds r1, r1, r0
	ldrb r1, [r1]
	adds r0, r4, #0
	bl StartSpriteAnim
_0803970C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08039714: .4byte 0x02024178
_08039718: .4byte 0x02024188
	thumb_func_end SpriteCB_AnimFaintOpponent
