.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0811EF44
sub_0811EF44: @ 0x0811EF44
	ldr r3, _0811EF70
	ldr r0, [r3]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, #0x3e
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.align 2, 0
_0811EF70: .4byte 0x02039DE8
	thumb_func_end sub_0811EF44

	thumb_func_start sub_0811EF74
sub_0811EF74: @ 0x0811EF74
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl GetDisplayedPersonType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0811EF98
	cmp r0, #1
	bgt _0811EF8E
	cmp r0, #0
	beq _0811EF94
	b _0811F02E
_0811EF8E:
	cmp r0, #2
	beq _0811EF9C
	b _0811F02E
_0811EF94:
	movs r4, #0x43
	b _0811EF9E
_0811EF98:
	movs r4, #0x44
	b _0811EF9E
_0811EF9C:
	movs r4, #7
_0811EF9E:
	bl GetEasyChatScreenFrameId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _0811EFB0
	cmp r0, #5
	beq _0811EFB6
	b _0811F02E
_0811EFB0:
	movs r5, #0x4c
	movs r3, #0x28
	b _0811EFBA
_0811EFB6:
	movs r5, #0x30
	movs r3, #0x30
_0811EFBA:
	adds r0, r4, #0
	ldr r7, _0811F038
	adds r2, r5, #0
	adds r4, r3, #0
	movs r6, #0
	str r6, [sp]
	adds r1, r7, #0
	bl AddPseudoEventObject
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _0811EFEE
	ldr r1, _0811F03C
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #5]
	movs r1, #2
	bl StartSpriteAnim
_0811EFEE:
	ldr r0, _0811F040
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	movs r1, #0x69
	cmp r0, #0
	bne _0811EFFC
	movs r1, #0x64
_0811EFFC:
	adds r2, r5, #0
	subs r2, #0x18
	str r6, [sp]
	adds r0, r1, #0
	adds r1, r7, #0
	adds r3, r4, #0
	bl AddPseudoEventObject
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _0811F02E
	ldr r1, _0811F03C
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #5]
	movs r1, #3
	bl StartSpriteAnim
_0811F02E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F038: .4byte 0x08007141
_0811F03C: .4byte 0x020205AC
_0811F040: .4byte 0x03005AF0
	thumb_func_end sub_0811EF74

	thumb_func_start sub_0811F044
sub_0811F044: @ 0x0811F044
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0x14
	beq _0811F06A
	cmp r0, #0x14
	bgt _0811F064
	cmp r0, #0x11
	blt _0811F082
	ldr r0, _0811F060
	bl FlagGet
	b _0811F07C
	.align 2, 0
_0811F060: .4byte 0x00000864
_0811F064:
	cmp r1, #0x15
	beq _0811F078
	b _0811F082
_0811F06A:
	ldr r0, _0811F074
	bl FlagGet
	b _0811F07C
	.align 2, 0
_0811F074: .4byte 0x00000866
_0811F078:
	bl sub_0811F5D8
_0811F07C:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811F084
_0811F082:
	movs r0, #1
_0811F084:
	pop {r1}
	bx r1
	thumb_func_end sub_0811F044

	thumb_func_start EasyChat_GetNumWordsInGroup
EasyChat_GetNumWordsInGroup: @ 0x0811F088
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #0
	bne _0811F0A0
	movs r0, #0
	bl GetNationalPokedexCount
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _0811F0B6
_0811F0A0:
	bl sub_0811F044
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F0AE
	movs r0, #0
	b _0811F0B6
_0811F0AE:
	ldr r0, _0811F0BC
	lsls r1, r4, #3
	adds r1, r1, r0
	ldrh r0, [r1, #6]
_0811F0B6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0811F0BC: .4byte 0x08578D14
	thumb_func_end EasyChat_GetNumWordsInGroup

	thumb_func_start sub_0811F0C0
sub_0811F0C0: @ 0x0811F0C0
	push {r4, r5, lr}
	lsls r2, r0, #0x10
	lsrs r1, r2, #0x10
	ldr r0, _0811F0EC
	cmp r1, r0
	beq _0811F120
	lsrs r3, r2, #0x19
	ldr r5, _0811F0F0
	ands r5, r1
	cmp r3, #0x15
	bhi _0811F124
	ldr r0, _0811F0F4
	lsls r2, r3, #3
	adds r1, r2, r0
	ldrh r4, [r1, #4]
	cmp r3, #0x13
	bgt _0811F0F8
	cmp r3, #0x12
	bge _0811F0FC
	cmp r3, #0
	beq _0811F0FC
	b _0811F11C
	.align 2, 0
_0811F0EC: .4byte 0x0000FFFF
_0811F0F0: .4byte 0x000001FF
_0811F0F4: .4byte 0x08578D14
_0811F0F8:
	cmp r3, #0x15
	bne _0811F11C
_0811F0FC:
	adds r0, r2, r0
	ldr r2, [r0]
	movs r1, #0
	cmp r1, r4
	bhs _0811F124
_0811F106:
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811F120
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r4
	blo _0811F106
	b _0811F124
_0811F11C:
	cmp r5, r4
	bhs _0811F124
_0811F120:
	movs r0, #0
	b _0811F126
_0811F124:
	movs r0, #1
_0811F126:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_0811F0C0

	thumb_func_start GetEasyChatWord
GetEasyChatWord: @ 0x0811F12C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r0, #0x13
	bgt _0811F144
	cmp r0, #0x12
	bge _0811F158
	cmp r0, #0
	beq _0811F148
	b _0811F164
_0811F144:
	cmp r0, #0x15
	bne _0811F164
_0811F148:
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #1
	ldr r1, _0811F154
	adds r0, r0, r1
	b _0811F176
	.align 2, 0
_0811F154: .4byte 0x082EA31C
_0811F158:
	lsls r0, r2, #3
	ldr r1, _0811F160
	adds r0, r0, r1
	b _0811F176
	.align 2, 0
_0811F160: .4byte 0x082EACC4
_0811F164:
	ldr r1, _0811F17C
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
_0811F176:
	pop {r1}
	bx r1
	.align 2, 0
_0811F17C: .4byte 0x08578D14
	thumb_func_end GetEasyChatWord

	thumb_func_start CopyEasyChatWord
CopyEasyChatWord: @ 0x0811F180
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r6, r1, #0x10
	lsrs r0, r6, #0x10
	adds r4, r0, #0
	bl sub_0811F0C0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F19C
	ldr r1, _0811F198
	b _0811F1AE
	.align 2, 0
_0811F198: .4byte 0x08579F30
_0811F19C:
	ldr r0, _0811F1B8
	cmp r4, r0
	beq _0811F1C0
	ldr r1, _0811F1BC
	ands r1, r4
	lsrs r0, r6, #0x19
	bl GetEasyChatWord
	adds r1, r0, #0
_0811F1AE:
	adds r0, r5, #0
	bl StringCopy
	b _0811F1C6
	.align 2, 0
_0811F1B8: .4byte 0x0000FFFF
_0811F1BC: .4byte 0x000001FF
_0811F1C0:
	movs r0, #0xff
	strb r0, [r5]
	adds r0, r5, #0
_0811F1C6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end CopyEasyChatWord

	thumb_func_start ConvertEasyChatWordsToString
ConvertEasyChatWordsToString: @ 0x0811F1CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sb, r3
	ldr r0, _0811F254
	adds r2, r2, r0
	lsrs r7, r2, #0x10
	movs r0, #0
	cmp r0, sb
	bhs _0811F23C
_0811F1EE:
	movs r6, #0
	adds r0, #1
	mov r8, r0
	cmp r6, r7
	bhs _0811F220
	ldr r2, _0811F258
_0811F1FA:
	ldrh r1, [r5]
	adds r0, r4, #0
	str r2, [sp]
	bl CopyEasyChatWord
	adds r4, r0, #0
	ldrh r0, [r5]
	ldr r2, [sp]
	cmp r0, r2
	beq _0811F214
	movs r0, #0
	strb r0, [r4]
	adds r4, #1
_0811F214:
	adds r5, #2
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r7
	blo _0811F1FA
_0811F220:
	ldrh r1, [r5]
	adds r5, #2
	adds r0, r4, #0
	bl CopyEasyChatWord
	adds r4, r0, #0
	movs r0, #0xfe
	strb r0, [r4]
	adds r4, #1
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, sb
	blo _0811F1EE
_0811F23C:
	subs r4, #1
	movs r0, #0xff
	strb r0, [r4]
	adds r0, r4, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811F254: .4byte 0xFFFF0000
_0811F258: .4byte 0x0000FFFF
	thumb_func_end ConvertEasyChatWordsToString

	thumb_func_start GetEasyChatWordStringLength
GetEasyChatWordStringLength: @ 0x0811F25C
	push {r4, r5, lr}
	lsls r5, r0, #0x10
	lsrs r0, r5, #0x10
	adds r4, r0, #0
	ldr r0, _0811F270
	cmp r4, r0
	bne _0811F274
	movs r0, #0
	b _0811F29A
	.align 2, 0
_0811F270: .4byte 0x0000FFFF
_0811F274:
	adds r0, r4, #0
	bl sub_0811F0C0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F290
	ldr r1, _0811F28C
	ands r1, r4
	lsrs r0, r5, #0x19
	bl GetEasyChatWord
	b _0811F292
	.align 2, 0
_0811F28C: .4byte 0x000001FF
_0811F290:
	ldr r0, _0811F2A0
_0811F292:
	bl StringLength
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_0811F29A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0811F2A0: .4byte 0x08579F30
	thumb_func_end GetEasyChatWordStringLength

	thumb_func_start sub_0811F2A4
sub_0811F2A4: @ 0x0811F2A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	movs r7, #0
	cmp r7, r8
	bhs _0811F306
	subs r0, r1, #1
	lsls r0, r0, #0x10
	mov sb, r0
_0811F2CE:
	mov r0, sb
	lsrs r4, r0, #0x10
	movs r5, #0
	cmp r5, r1
	bhs _0811F2F4
_0811F2D8:
	ldrh r0, [r6]
	adds r6, #2
	str r1, [sp]
	bl GetEasyChatWordStringLength
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, [sp]
	cmp r5, r1
	blo _0811F2D8
_0811F2F4:
	cmp r4, sl
	bls _0811F2FC
	movs r0, #1
	b _0811F308
_0811F2FC:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, r8
	blo _0811F2CE
_0811F306:
	movs r0, #0
_0811F308:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_0811F2A4

	thumb_func_start sub_0811F318
	.globl GetRandomEasyChatWordFromGroup
	.set GetRandomEasyChatWordFromGroup, sub_0811F318
sub_0811F318: @ 0x0811F318
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl Random
	ldr r2, _0811F368
	lsls r1, r4, #3
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1, #4]
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r4, #0
	beq _0811F346
	cmp r4, #0x15
	beq _0811F346
	cmp r4, #0x12
	beq _0811F346
	cmp r4, #0x13
	bne _0811F354
_0811F346:
	ldr r1, _0811F368
	lsls r0, r4, #3
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r2, [r0]
_0811F354:
	movs r0, #0x7f
	ands r0, r4
	lsls r0, r0, #9
	ldr r1, _0811F36C
	ands r2, r1
	orrs r0, r2
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0811F368: .4byte 0x08578D14
_0811F36C: .4byte 0x000001FF
	thumb_func_end sub_0811F318

	thumb_func_start sub_0811F370
sub_0811F370: @ 0x0811F370
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r0, #0
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_0811F044
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F390
	ldr r0, _0811F38C
	b _0811F3A4
	.align 2, 0
_0811F38C: .4byte 0x0000FFFF
_0811F390:
	cmp r4, #0
	beq _0811F39C
	adds r0, r4, #0
	bl sub_0811F318
	b _0811F3A0
_0811F39C:
	bl sub_0811F5E8
_0811F3A0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_0811F3A4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811F370

	thumb_func_start sub_0811F3AC
sub_0811F3AC: @ 0x0811F3AC
	push {r4, r5, lr}
	ldr r0, _0811F3C0
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811F3E4
	cmp r0, #1
	bgt _0811F3C4
	cmp r0, #0
	beq _0811F3CE
	b _0811F438
	.align 2, 0
_0811F3C0: .4byte 0x02037280
_0811F3C4:
	cmp r0, #2
	beq _0811F40C
	cmp r0, #3
	beq _0811F41C
	b _0811F438
_0811F3CE:
	ldr r0, _0811F3DC
	ldr r0, [r0]
	ldr r1, _0811F3E0
	adds r5, r0, r1
	movs r2, #2
	b _0811F426
	.align 2, 0
_0811F3DC: .4byte 0x03005AEC
_0811F3E0: .4byte 0x00002BB0
_0811F3E4:
	ldr r0, _0811F404
	ldr r0, [r0]
	ldr r1, _0811F408
	adds r5, r0, r1
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	movs r3, #0x12
	bl sub_0811F2A4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F424
	movs r2, #2
	movs r3, #3
	b _0811F428
	.align 2, 0
_0811F404: .4byte 0x03005AEC
_0811F408: .4byte 0x00002BBC
_0811F40C:
	ldr r0, _0811F414
	ldr r0, [r0]
	ldr r1, _0811F418
	b _0811F422
	.align 2, 0
_0811F414: .4byte 0x03005AEC
_0811F418: .4byte 0x00002BC8
_0811F41C:
	ldr r0, _0811F440
	ldr r0, [r0]
	ldr r1, _0811F444
_0811F422:
	adds r5, r0, r1
_0811F424:
	movs r2, #3
_0811F426:
	movs r3, #2
_0811F428:
	ldr r4, _0811F448
	adds r0, r4, #0
	adds r1, r5, #0
	bl ConvertEasyChatWordsToString
	adds r0, r4, #0
	bl ShowFieldAutoScrollMessage
_0811F438:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0811F440: .4byte 0x03005AEC
_0811F444: .4byte 0x00002BD4
_0811F448: .4byte 0x02021C7C
	thumb_func_end sub_0811F3AC

	thumb_func_start sub_0811F44C
sub_0811F44C: @ 0x0811F44C
	push {lr}
	bl Random
	movs r1, #1
	ands r1, r0
	movs r0, #0xc
	cmp r1, #0
	beq _0811F45E
	movs r0, #0xd
_0811F45E:
	bl sub_0811F370
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0811F474
	bl CopyEasyChatWord
	pop {r0}
	bx r0
	.align 2, 0
_0811F474: .4byte 0x02021C54
	thumb_func_end sub_0811F44C

	thumb_func_start sub_0811F478
sub_0811F478: @ 0x0811F478
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x1b
	movs r1, #0xe0
	lsls r1, r1, #0x13
	ands r1, r0
	lsrs r1, r1, #0x18
	ldr r0, _0811F498
	ldr r0, [r0]
	ldr r3, _0811F49C
	adds r0, r0, r3
	adds r0, r0, r2
	ldrb r0, [r0]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	bx lr
	.align 2, 0
_0811F498: .4byte 0x03005AEC
_0811F49C: .4byte 0x00002E20
	thumb_func_end sub_0811F478

	thumb_func_start sub_0811F4A0
sub_0811F4A0: @ 0x0811F4A0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x20
	bhi _0811F4C4
	lsrs r3, r0, #0x1b
	movs r2, #7
	ands r2, r1
	ldr r0, _0811F4C8
	ldr r1, [r0]
	ldr r0, _0811F4CC
	adds r1, r1, r0
	adds r1, r1, r3
	movs r0, #1
	lsls r0, r2
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
_0811F4C4:
	pop {r0}
	bx r0
	.align 2, 0
_0811F4C8: .4byte 0x03005AEC
_0811F4CC: .4byte 0x00002E20
	thumb_func_end sub_0811F4A0

	thumb_func_start sub_0811F4D0
sub_0811F4D0: @ 0x0811F4D0
	push {r4, r5, lr}
	movs r4, #0
	movs r5, #0
_0811F4D6:
	adds r0, r4, #0
	bl sub_0811F478
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F4E8
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0811F4E8:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x20
	bls _0811F4D6
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811F4D0

	thumb_func_start sub_0811F4FC
sub_0811F4FC: @ 0x0811F4FC
	push {r4, r5, r6, lr}
	bl sub_0811F4D0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x21
	bne _0811F528
	b _0811F562
_0811F50C:
	adds r0, r5, #0
	bl sub_0811F4A0
	ldr r0, _0811F524
	ands r4, r0
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r1, #0
	orrs r4, r0
	adds r0, r4, #0
	b _0811F564
	.align 2, 0
_0811F524: .4byte 0x000001FF
_0811F528:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x21
	subs r1, r1, r4
	bl __modsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r4, #0
_0811F53E:
	lsls r0, r4, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, #0
	bl sub_0811F478
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F558
	cmp r6, #0
	beq _0811F50C
	subs r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_0811F558:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x20
	bls _0811F53E
_0811F562:
	ldr r0, _0811F56C
_0811F564:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0811F56C: .4byte 0x0000FFFF
	thumb_func_end sub_0811F4FC

	thumb_func_start sub_0811F570
sub_0811F570: @ 0x0811F570
	push {r4, r5, lr}
	bl sub_0811F4D0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0811F594
	b _0811F5CA
_0811F580:
	ldr r0, _0811F590
	ands r4, r0
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r1, #0
	orrs r4, r0
	adds r0, r4, #0
	b _0811F5CC
	.align 2, 0
_0811F590: .4byte 0x000001FF
_0811F594:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0
_0811F5A8:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_0811F478
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F5C0
	cmp r5, #0
	beq _0811F580
	subs r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0811F5C0:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x20
	bls _0811F5A8
_0811F5CA:
	ldr r0, _0811F5D4
_0811F5CC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0811F5D4: .4byte 0x0000FFFF
	thumb_func_end sub_0811F570

	thumb_func_start sub_0811F5D8
sub_0811F5D8: @ 0x0811F5D8
	push {lr}
	bl IsNationalPokedexEnabled
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811F5D8

	thumb_func_start sub_0811F5E8
sub_0811F5E8: @ 0x0811F5E8
	push {r4, r5, r6, r7, lr}
	movs r0, #0
	bl EasyChat_GetNumWordsInGroup
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0811F608
	b _0811F652
_0811F5FA:
	ldrh r1, [r5]
	ldr r0, _0811F604
	ands r0, r1
	b _0811F654
	.align 2, 0
_0811F604: .4byte 0x000001FF
_0811F608:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0811F65C
	ldr r5, [r0]
	ldrh r7, [r0, #4]
	movs r6, #0
	cmp r6, r7
	bhs _0811F652
_0811F626:
	ldrh r0, [r5]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F646
	cmp r4, #0
	beq _0811F5FA
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0811F646:
	adds r5, #2
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r7
	blo _0811F626
_0811F652:
	ldr r0, _0811F660
_0811F654:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811F65C: .4byte 0x08578D14
_0811F660: .4byte 0x0000FFFF
	thumb_func_end sub_0811F5E8

	thumb_func_start InitEasyChatPhrases
InitEasyChatPhrases: @ 0x0811F664
	push {r4, r5, r6, r7, lr}
	ldr r4, _0811F770
	ldr r1, [r4]
	ldr r0, _0811F774
	adds r2, r1, r0
	ldr r0, _0811F778
	strh r0, [r2]
	ldr r5, _0811F77C
	adds r2, r1, r5
	ldr r0, _0811F780
	strh r0, [r2]
	ldr r0, _0811F784
	adds r2, r1, r0
	ldr r0, _0811F788
	strh r0, [r2]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F78C
	strh r0, [r2]
	ldr r0, _0811F790
	adds r2, r1, r0
	ldr r0, _0811F794
	strh r0, [r2]
	adds r5, #8
	adds r2, r1, r5
	ldr r0, _0811F798
	strh r0, [r2]
	movs r0, #0xaf
	lsls r0, r0, #6
	adds r2, r1, r0
	ldr r0, _0811F79C
	strh r0, [r2]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F7A0
	strh r0, [r2]
	ldr r0, _0811F7A4
	adds r2, r1, r0
	ldr r0, _0811F7A8
	strh r0, [r2]
	ldr r2, _0811F7AC
	adds r0, r1, r2
	ldr r3, _0811F7B0
	strh r3, [r0]
	adds r5, #6
	adds r2, r1, r5
	ldr r0, _0811F7B4
	strh r0, [r2]
	ldr r2, _0811F7B8
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F7BC
	strh r0, [r2]
	ldr r2, _0811F7C0
	adds r0, r1, r2
	ldr r2, _0811F7C4
	strh r2, [r0]
	adds r5, #4
	adds r0, r1, r5
	strh r2, [r0]
	ldr r2, _0811F7C8
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F7CC
	strh r0, [r2]
	ldr r2, _0811F7D0
	adds r0, r1, r2
	adds r3, #5
	strh r3, [r0]
	adds r5, #4
	adds r2, r1, r5
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2]
	ldr r0, _0811F7D4
	adds r2, r1, r0
	movs r0, #0xc6
	lsls r0, r0, #3
	strh r0, [r2]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F7D8
	strh r0, [r2]
	ldr r0, _0811F7DC
	adds r1, r1, r0
	strh r3, [r1]
	movs r3, #0
	adds r7, r4, #0
	ldr r6, _0811F7E0
	movs r2, #1
	rsbs r2, r2, #0
	adds r5, r2, #0
_0811F724:
	movs r2, #0
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r4, r0, #2
_0811F72C:
	ldr r1, [r7]
	lsls r0, r2, #1
	adds r0, r0, r4
	adds r1, r1, r6
	adds r1, r1, r0
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #8
	bls _0811F72C
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0xf
	bls _0811F724
	movs r3, #0
	ldr r4, _0811F770
	ldr r2, _0811F7E4
	movs r1, #0
_0811F758:
	ldr r0, [r4]
	adds r0, r0, r2
	adds r0, r0, r3
	strb r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x3f
	bls _0811F758
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F770: .4byte 0x03005AEC
_0811F774: .4byte 0x00002BB0
_0811F778: .4byte 0x0000020E
_0811F77C: .4byte 0x00002BB2
_0811F780: .4byte 0x00001228
_0811F784: .4byte 0x00002BB4
_0811F788: .4byte 0x0000020B
_0811F78C: .4byte 0x0000101F
_0811F790: .4byte 0x00002BBC
_0811F794: .4byte 0x00000603
_0811F798: .4byte 0x00001405
_0811F79C: .4byte 0x00000C02
_0811F7A0: .4byte 0x00000E0E
_0811F7A4: .4byte 0x00002BC4
_0811F7A8: .4byte 0x00000803
_0811F7AC: .4byte 0x00002BC6
_0811F7B0: .4byte 0x00000C01
_0811F7B4: .4byte 0x0000123C
_0811F7B8: .4byte 0x00002BCA
_0811F7BC: .4byte 0x0000FFFF
_0811F7C0: .4byte 0x00002BCE
_0811F7C4: .4byte 0x00000607
_0811F7C8: .4byte 0x00002BD2
_0811F7CC: .4byte 0x0000121B
_0811F7D0: .4byte 0x00002BD6
_0811F7D4: .4byte 0x00002BDA
_0811F7D8: .4byte 0x0000121F
_0811F7DC: .4byte 0x00002BDE
_0811F7E0: .4byte 0x00002BE0
_0811F7E4: .4byte 0x00002E20
	thumb_func_end InitEasyChatPhrases

	thumb_func_start sub_0811F7E8
sub_0811F7E8: @ 0x0811F7E8
	push {r4, lr}
	ldr r4, _0811F804
	ldr r0, _0811F808
	bl Alloc
	str r0, [r4]
	cmp r0, #0
	beq _0811F80C
	bl sub_0811F830
	bl sub_0811F9C8
	movs r0, #1
	b _0811F80E
	.align 2, 0
_0811F804: .4byte 0x02039DEC
_0811F808: .4byte 0x00002CE8
_0811F80C:
	movs r0, #0
_0811F80E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811F7E8

	thumb_func_start sub_0811F814
sub_0811F814: @ 0x0811F814
	push {r4, lr}
	ldr r4, _0811F82C
	ldr r0, [r4]
	cmp r0, #0
	beq _0811F826
	bl Free
	movs r0, #0
	str r0, [r4]
_0811F826:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0811F82C: .4byte 0x02039DEC
	thumb_func_end sub_0811F814

	thumb_func_start sub_0811F830
sub_0811F830: @ 0x0811F830
	push {r4, r5, lr}
	ldr r4, _0811F8FC
	ldr r0, [r4]
	movs r5, #0
	strh r5, [r0]
	movs r0, #0
	bl GetNationalPokedexCount
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0811F858
	ldr r0, [r4]
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r0, #2
	adds r0, r0, r1
	strh r5, [r0]
_0811F858:
	movs r3, #1
_0811F85A:
	ldr r0, [r4]
	ldrh r2, [r0]
	adds r1, r2, #1
	strh r1, [r0]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r0, #2
	adds r0, r0, r2
	strh r3, [r0]
	adds r3, #1
	cmp r3, #0x10
	ble _0811F85A
	ldr r0, _0811F900
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F8B4
	ldr r0, _0811F8FC
	ldr r2, [r0]
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r3, r2, #2
	adds r0, r3, r0
	movs r1, #0x11
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r3, r0
	movs r1, #0x12
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r3, r3, r0
	movs r0, #0x13
	strh r0, [r3]
_0811F8B4:
	ldr r0, _0811F904
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F8D6
	ldr r0, _0811F8FC
	ldr r0, [r0]
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r0, #2
	adds r0, r0, r1
	movs r1, #0x14
	strh r1, [r0]
_0811F8D6:
	bl IsNationalPokedexEnabled
	cmp r0, #0
	beq _0811F8F4
	ldr r0, _0811F8FC
	ldr r0, [r0]
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r0, #2
	adds r0, r0, r1
	movs r1, #0x15
	strh r1, [r0]
_0811F8F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0811F8FC: .4byte 0x02039DEC
_0811F900: .4byte 0x00000864
_0811F904: .4byte 0x00000866
	thumb_func_end sub_0811F830

	thumb_func_start sub_0811F908
sub_0811F908: @ 0x0811F908
	ldr r0, _0811F910
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0811F910: .4byte 0x02039DEC
	thumb_func_end sub_0811F908

	thumb_func_start sub_0811F914
sub_0811F914: @ 0x0811F914
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _0811F930
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r2, r0
	bhs _0811F934
	lsls r0, r2, #1
	adds r1, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	b _0811F936
	.align 2, 0
_0811F930: .4byte 0x02039DEC
_0811F934:
	movs r0, #0x16
_0811F936:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811F914

	thumb_func_start unref_sub_811F3E0
unref_sub_811F3E0: @ 0x0811F93C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r0, _0811F97C
	lsrs r1, r1, #0x16
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl StringCopy
	adds r1, r0, #0
	subs r4, r1, r4
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	cmp r0, r5
	bhs _0811F970
	movs r2, #0
_0811F962:
	strb r2, [r1]
	adds r1, #1
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	blo _0811F962
_0811F970:
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0811F97C: .4byte 0x08579ED8
	thumb_func_end unref_sub_811F3E0

	thumb_func_start GetEasyChatWordGroupName
GetEasyChatWordGroupName: @ 0x0811F980
	lsls r0, r0, #0x18
	ldr r1, _0811F98C
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0811F98C: .4byte 0x08579ED8
	thumb_func_end GetEasyChatWordGroupName

	thumb_func_start CopyEasyChatWordPadded
CopyEasyChatWordPadded: @ 0x0811F990
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	bl CopyEasyChatWord
	adds r1, r0, #0
	subs r4, r1, r4
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	cmp r0, r5
	bhs _0811F9BC
	movs r2, #0
_0811F9AE:
	strb r2, [r1]
	adds r1, #1
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	blo _0811F9AE
_0811F9BC:
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end CopyEasyChatWordPadded

	thumb_func_start sub_0811F9C8
sub_0811F9C8: @ 0x0811F9C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r3, #0
_0811F9D6:
	ldr r2, _0811FA18
	lsls r1, r3, #3
	adds r0, r2, #4
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp]
	adds r1, r1, r2
	ldr r7, [r1]
	ldr r0, _0811FA1C
	ldr r1, [r0]
	lsls r2, r3, #1
	adds r1, #0x2e
	adds r1, r1, r2
	movs r0, #0
	strh r0, [r1]
	mov sl, r0
	movs r1, #0
	str r2, [sp, #4]
	adds r0, r3, #1
	str r0, [sp, #8]
	ldr r2, [sp]
	cmp r1, r2
	bge _0811FA88
_0811FA04:
	ldrh r0, [r7]
	ldr r2, _0811FA20
	cmp r0, r2
	bne _0811FA54
	adds r7, #2
	ldrh r4, [r7]
	adds r7, #2
	adds r0, r1, #1
	adds r1, r0, r4
	b _0811FA56
	.align 2, 0
_0811FA18: .4byte 0x08579D04
_0811FA1C: .4byte 0x02039DEC
_0811FA20: .4byte 0x0000FFFF
_0811FA24:
	ldr r0, _0811FA50
	ldr r2, [r0]
	mov r0, sl
	lsls r1, r0, #1
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x88
	adds r0, r0, r1
	ldrh r1, [r5]
	strh r1, [r0]
	movs r0, #1
	add sl, r0
	adds r2, #0x2e
	ldr r0, [sp, #4]
	adds r2, r2, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	b _0811FA7E
	.align 2, 0
_0811FA50: .4byte 0x02039DEC
_0811FA54:
	movs r4, #1
_0811FA56:
	movs r6, #0
	adds r1, #1
	mov sb, r1
	lsls r2, r4, #1
	mov r8, r2
	cmp r6, r4
	bge _0811FA7E
	adds r5, r7, #0
_0811FA66:
	ldrh r0, [r5]
	str r3, [sp, #0xc]
	bl sub_0811FDB4
	lsls r0, r0, #0x18
	ldr r3, [sp, #0xc]
	cmp r0, #0
	bne _0811FA24
	adds r5, #2
	adds r6, #1
	cmp r6, r4
	blt _0811FA66
_0811FA7E:
	add r7, r8
	mov r1, sb
	ldr r0, [sp]
	cmp r1, r0
	blt _0811FA04
_0811FA88:
	ldr r3, [sp, #8]
	cmp r3, #0x2c
	ble _0811F9D6
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811F9C8

	thumb_func_start sub_0811FAA0
sub_0811FAA0: @ 0x0811FAA0
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r0, #0
	bne _0811FAB2
	adds r0, r1, #0
	bl sub_0811FB1C
	b _0811FAB8
_0811FAB2:
	adds r0, r1, #0
	bl sub_0811FC10
_0811FAB8:
	ldr r1, _0811FAC8
	ldr r1, [r1]
	ldr r2, _0811FACC
	adds r1, r1, r2
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0811FAC8: .4byte 0x02039DEC
_0811FACC: .4byte 0x00002CE4
	thumb_func_end sub_0811FAA0

	thumb_func_start sub_0811FAD0
sub_0811FAD0: @ 0x0811FAD0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _0811FAF0
	ldr r1, [r0]
	ldr r3, _0811FAF4
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bhs _0811FAFC
	lsls r0, r2, #1
	ldr r2, _0811FAF8
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	b _0811FAFE
	.align 2, 0
_0811FAF0: .4byte 0x02039DEC
_0811FAF4: .4byte 0x00002CE4
_0811FAF8: .4byte 0x00002AE4
_0811FAFC:
	ldr r0, _0811FB04
_0811FAFE:
	pop {r1}
	bx r1
	.align 2, 0
_0811FB04: .4byte 0x0000FFFF
	thumb_func_end sub_0811FAD0

	thumb_func_start sub_0811FB08
sub_0811FB08: @ 0x0811FB08
	ldr r0, _0811FB14
	ldr r0, [r0]
	ldr r1, _0811FB18
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_0811FB14: .4byte 0x02039DEC
_0811FB18: .4byte 0x00002CE4
	thumb_func_end sub_0811FB08

	thumb_func_start sub_0811FB1C
sub_0811FB1C: @ 0x0811FB1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, _0811FB94
	lsls r0, r2, #3
	adds r0, r0, r1
	ldrh r3, [r0, #4]
	mov r8, r3
	cmp r2, #0
	beq _0811FB44
	cmp r2, #0x15
	beq _0811FB44
	cmp r2, #0x12
	beq _0811FB44
	cmp r2, #0x13
	bne _0811FBA4
_0811FB44:
	lsls r0, r2, #3
	adds r0, r0, r1
	ldr r1, [r0]
	movs r7, #0
	movs r5, #0
	cmp r5, r8
	bhs _0811FBF0
	movs r0, #0x7f
	ands r0, r2
	lsls r0, r0, #9
	mov sb, r0
	adds r4, r1, #0
	lsls r6, r2, #0x18
_0811FB5E:
	ldrh r0, [r4]
	lsrs r1, r6, #0x18
	bl sub_0811FCB8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811FB88
	ldr r0, _0811FB98
	ldr r2, [r0]
	lsls r0, r5, #1
	ldr r1, _0811FB9C
	adds r2, r2, r1
	adds r2, r2, r0
	ldrh r0, [r4]
	ldr r3, _0811FBA0
	adds r1, r3, #0
	ands r0, r1
	mov r1, sb
	orrs r0, r1
	strh r0, [r2]
	adds r5, #1
_0811FB88:
	adds r4, #2
	adds r7, #1
	cmp r7, r8
	blo _0811FB5E
	b _0811FBF0
	.align 2, 0
_0811FB94: .4byte 0x08578D14
_0811FB98: .4byte 0x02039DEC
_0811FB9C: .4byte 0x00002AE4
_0811FBA0: .4byte 0x000001FF
_0811FBA4:
	ldr r1, [r0]
	movs r7, #0
	movs r5, #0
	cmp r5, r8
	bhs _0811FBF0
	movs r0, #0x7f
	ands r0, r2
	lsls r0, r0, #9
	mov sl, r0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	mov sb, r2
_0811FBBC:
	ldrh r4, [r6, #4]
	adds r0, r4, #0
	mov r2, sb
	lsrs r1, r2, #0x18
	bl sub_0811FCB8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811FBE8
	ldr r0, _0811FC04
	ldr r1, [r0]
	lsls r0, r5, #1
	ldr r3, _0811FC08
	adds r1, r1, r3
	adds r1, r1, r0
	ldr r2, _0811FC0C
	adds r0, r2, #0
	ands r4, r0
	mov r3, sl
	orrs r4, r3
	strh r4, [r1]
	adds r5, #1
_0811FBE8:
	adds r6, #0xc
	adds r7, #1
	cmp r7, r8
	blo _0811FBBC
_0811FBF0:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811FC04: .4byte 0x02039DEC
_0811FC08: .4byte 0x00002AE4
_0811FC0C: .4byte 0x000001FF
	thumb_func_end sub_0811FB1C

	thumb_func_start sub_0811FC10
sub_0811FC10: @ 0x0811FC10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r4, #0
	movs r6, #0
	ldr r3, _0811FC78
	ldr r0, [r3]
	lsls r5, r1, #1
	adds r0, #0x2e
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r6, r0
	bhs _0811FC6C
	mov r8, r3
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r7, r0, #4
	ldr r0, _0811FC7C
	mov ip, r0
_0811FC3A:
	mov r0, r8
	ldr r3, [r0]
	adds r1, r6, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #1
	mov r0, ip
	adds r2, r3, r0
	adds r2, r2, r1
	lsls r1, r4, #1
	adds r1, r1, r7
	adds r0, r3, #0
	adds r0, #0x88
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r3, #0x2e
	adds r3, r3, r5
	ldrh r3, [r3]
	cmp r4, r3
	blo _0811FC3A
_0811FC6C:
	adds r0, r6, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811FC78: .4byte 0x02039DEC
_0811FC7C: .4byte 0x00002AE4
	thumb_func_end sub_0811FC10

	thumb_func_start sub_0811FC80
sub_0811FC80: @ 0x0811FC80
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r0, _0811FCA4
	ldr r0, [r0]
	ldrh r1, [r0]
	cmp r2, r1
	bge _0811FCB0
	adds r4, r3, #0
	adds r3, r1, #0
	adds r1, r0, #2
_0811FC98:
	ldrh r0, [r1]
	cmp r0, r4
	bne _0811FCA8
	movs r0, #1
	b _0811FCB2
	.align 2, 0
_0811FCA4: .4byte 0x02039DEC
_0811FCA8:
	adds r1, #2
	adds r2, #1
	cmp r2, r3
	blt _0811FC98
_0811FCB0:
	movs r0, #0
_0811FCB2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811FC80

	thumb_func_start sub_0811FCB8
sub_0811FCB8: @ 0x0811FCB8
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0x15
	bhi _0811FD6E
	lsls r0, r2, #2
	ldr r1, _0811FCD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811FCD0: .4byte 0x0811FCD4
_0811FCD4: @ jump table
	.4byte _0811FD2C @ case 0
	.4byte _0811FD6E @ case 1
	.4byte _0811FD6E @ case 2
	.4byte _0811FD6E @ case 3
	.4byte _0811FD6E @ case 4
	.4byte _0811FD6E @ case 5
	.4byte _0811FD6E @ case 6
	.4byte _0811FD6E @ case 7
	.4byte _0811FD6E @ case 8
	.4byte _0811FD6E @ case 9
	.4byte _0811FD6E @ case 10
	.4byte _0811FD6E @ case 11
	.4byte _0811FD6E @ case 12
	.4byte _0811FD6E @ case 13
	.4byte _0811FD6E @ case 14
	.4byte _0811FD6E @ case 15
	.4byte _0811FD6E @ case 16
	.4byte _0811FD6E @ case 17
	.4byte _0811FD5C @ case 18
	.4byte _0811FD5C @ case 19
	.4byte _0811FD60 @ case 20
	.4byte _0811FD42 @ case 21
_0811FD2C:
	adds r0, r4, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811FD80
_0811FD42:
	adds r0, r4, #0
	bl GetFooterOptionXOffset
	cmp r0, #0
	beq _0811FD5C
	adds r0, r4, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl GetSetPokedexFlag
_0811FD5C:
	movs r0, #1
	b _0811FD80
_0811FD60:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_0811F478
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811FD80
_0811FD6E:
	ldr r1, _0811FD88
	lsls r0, r2, #3
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #8]
_0811FD80:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0811FD88: .4byte 0x08578D14
	thumb_func_end sub_0811FCB8

	thumb_func_start GetFooterOptionXOffset
GetFooterOptionXOffset: @ 0x0811FD8C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0
	ldr r1, _0811FDA0
_0811FD96:
	ldrh r0, [r1]
	cmp r0, r3
	bne _0811FDA4
	movs r0, #1
	b _0811FDAE
	.align 2, 0
_0811FDA0: .4byte 0x08579F34
_0811FDA4:
	adds r1, #2
	adds r2, #1
	cmp r2, #0
	beq _0811FD96
	movs r0, #0
_0811FDAE:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetFooterOptionXOffset

	thumb_func_start sub_0811FDB4
sub_0811FDB4: @ 0x0811FDB4
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x19
	lsls r0, r0, #7
	lsrs r4, r0, #0x17
	adds r0, r5, #0
	bl sub_0811FC80
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811FDD8
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0811FCB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811FDDA
_0811FDD8:
	movs r0, #0
_0811FDDA:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_0811FDB4

	thumb_func_start InitializeEasyChatWordArray
InitializeEasyChatWordArray: @ 0x0811FDE0
	push {lr}
	adds r2, r0, #0
	lsls r1, r1, #0x10
	ldr r0, _0811FE08
	adds r1, r1, r0
	lsrs r0, r1, #0x10
	ldr r1, _0811FE0C
	cmp r0, r1
	beq _0811FE02
	adds r3, r1, #0
_0811FDF4:
	strh r3, [r2]
	adds r2, #2
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bne _0811FDF4
_0811FE02:
	pop {r0}
	bx r0
	.align 2, 0
_0811FE08: .4byte 0xFFFF0000
_0811FE0C: .4byte 0x0000FFFF
	thumb_func_end InitializeEasyChatWordArray

	thumb_func_start sub_0811FE10
sub_0811FE10: @ 0x0811FE10
	push {lr}
	bl GetQuestionnaireWordsPtr
	ldr r1, _0811FE28
	adds r2, r1, #0
	adds r1, r0, #6
_0811FE1C:
	strh r2, [r1]
	subs r1, #2
	cmp r1, r0
	bge _0811FE1C
	pop {r0}
	bx r0
	.align 2, 0
_0811FE28: .4byte 0x0000FFFF
	thumb_func_end sub_0811FE10
