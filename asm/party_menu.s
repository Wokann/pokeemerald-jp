.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start SetUpFieldMove_Surf
SetUpFieldMove_Surf: @ 0x081B54C0
	push {lr}
	bl PartyHasMonWithSurf
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B54FC
	bl IsPlayerFacingSurfableFishableWater
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B54FC
	ldr r1, _081B54EC
	ldr r0, _081B54F0
	str r0, [r1]
	ldr r1, _081B54F4
	ldr r0, _081B54F8
	str r0, [r1]
	movs r0, #1
	b _081B54FE
	.align 2, 0
_081B54EC: .4byte 0x03005B10
_081B54F0: .4byte 0x081B53D9
_081B54F4: .4byte 0x0203CBB8
_081B54F8: .4byte 0x081B54A5
_081B54FC:
	movs r0, #0
_081B54FE:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end SetUpFieldMove_Surf

	thumb_func_start sub_081B5504
sub_081B5504: @ 0x081B5504
	push {lr}
	movs r0, #8
	bl TestPlayerAvatarFlags
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B551A
	movs r0, #9
	bl DisplayPartyMenuStdMessage
	b _081B5520
_081B551A:
	movs r0, #8
	bl DisplayPartyMenuStdMessage
_081B5520:
	pop {r0}
	bx r0
	thumb_func_end sub_081B5504

	thumb_func_start SetUpFieldMove_Fly
SetUpFieldMove_Fly: @ 0x081B5524
	push {lr}
	ldr r0, _081B553C
	ldrb r0, [r0, #0x17]
	bl Overworld_MapTypeAllowsTeleportAndFly
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B5540
	movs r0, #0
	b _081B5542
	.align 2, 0
_081B553C: .4byte 0x02036FB8
_081B5540:
	movs r0, #1
_081B5542:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end SetUpFieldMove_Fly

	thumb_func_start sub_081B5548
sub_081B5548: @ 0x081B5548
	push {lr}
	sub sp, #0xc
	movs r0, #0
	str r0, [sp]
	ldr r0, _081B556C
	str r0, [sp, #4]
	ldr r0, _081B5570
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B556C: .4byte 0x081B1041
_081B5570: .4byte 0x08085AFD
	thumb_func_end sub_081B5548

	thumb_func_start hm2_waterfall
hm2_waterfall: @ 0x081B5574
	push {lr}
	bl GetCursorSelectionMonId
	ldr r1, _081B558C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	movs r0, #0x2b
	bl FieldEffectStart
	pop {r0}
	bx r0
	.align 2, 0
_081B558C: .4byte 0x020388A8
	thumb_func_end hm2_waterfall

	thumb_func_start SetUpFieldMove_Waterfall
SetUpFieldMove_Waterfall: @ 0x081B5590
	push {r4, lr}
	sub sp, #4
	mov r4, sp
	adds r4, #2
	mov r0, sp
	adds r1, r4, #0
	bl GetXYCoordsOneStepInFrontOfPlayer
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl MapGridGetMetatileBehaviorAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl MetatileBehavior_IsWaterfall
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B55EC
	bl IsPlayerSurfingNorth
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B55EC
	ldr r1, _081B55DC
	ldr r0, _081B55E0
	str r0, [r1]
	ldr r1, _081B55E4
	ldr r0, _081B55E8
	str r0, [r1]
	movs r0, #1
	b _081B55EE
	.align 2, 0
_081B55DC: .4byte 0x03005B10
_081B55E0: .4byte 0x081B53D9
_081B55E4: .4byte 0x0203CBB8
_081B55E8: .4byte 0x081B5575
_081B55EC:
	movs r0, #0
_081B55EE:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end SetUpFieldMove_Waterfall

	thumb_func_start sub_081B55F8
sub_081B55F8: @ 0x081B55F8
	push {lr}
	bl GetCursorSelectionMonId
	ldr r1, _081B5610
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	movs r0, #0x2c
	bl FieldEffectStart
	pop {r0}
	bx r0
	.align 2, 0
_081B5610: .4byte 0x020388A8
	thumb_func_end sub_081B55F8

	thumb_func_start SetUpFieldMove_Dive
SetUpFieldMove_Dive: @ 0x081B5614
	push {lr}
	bl TrySetDiveWarp
	ldr r1, _081B562C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1, #4]
	cmp r0, #0
	bne _081B5630
	movs r0, #0
	b _081B563E
	.align 2, 0
_081B562C: .4byte 0x020388A8
_081B5630:
	ldr r1, _081B5644
	ldr r0, _081B5648
	str r0, [r1]
	ldr r1, _081B564C
	ldr r0, _081B5650
	str r0, [r1]
	movs r0, #1
_081B563E:
	pop {r1}
	bx r1
	.align 2, 0
_081B5644: .4byte 0x03005B10
_081B5648: .4byte 0x081B53D9
_081B564C: .4byte 0x0203CBB8
_081B5650: .4byte 0x081B55F9
	thumb_func_end SetUpFieldMove_Dive

	thumb_func_start party_menu_icon_anim
party_menu_icon_anim: @ 0x081B5654
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	movs r6, #1
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B568A
	ldr r0, _081B56C0
	ldr r1, _081B56C4
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B568A
	ldr r0, _081B56C8
	adds r0, r4, r0
	ldrb r1, [r0]
	eors r1, r6
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r6, r0, #0x1f
_081B568A:
	adds r0, r5, #0
	movs r1, #0x41
	bl GetMonData3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	movs r1, #0
	bl GetMonData3
	adds r1, r0, #0
	str r6, [sp]
	adds r0, r4, #0
	adds r2, r7, #0
	movs r3, #1
	bl party_menu_link_mon_icon_anim
	ldrb r0, [r7, #9]
	adds r1, r5, #0
	bl sub_081B57D8
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B56C0: .4byte 0x03002360
_081B56C4: .4byte 0x00000439
_081B56C8: .4byte 0x085E18D8
	thumb_func_end party_menu_icon_anim

	thumb_func_start party_menu_link_mon_icon_anim
party_menu_link_mon_icon_anim: @ 0x081B56CC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r1, #0
	adds r4, r2, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	cmp r5, #0
	beq _081B571A
	ldr r1, _081B5724
	ldr r0, [r4, #4]
	ldrb r2, [r0]
	ldrb r3, [r0, #1]
	movs r0, #4
	str r0, [sp]
	str r6, [sp, #4]
	ldr r0, [sp, #0x20]
	str r0, [sp, #8]
	adds r0, r5, #0
	bl CreateMonIcon
	strb r0, [r4, #9]
	ldr r2, _081B5728
	ldrb r0, [r4, #9]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r0, #3
	adds r2, r7, #0
	ands r2, r0
	lsls r2, r2, #2
	ldrb r3, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #5]
_081B571A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B5724: .4byte 0x080D28B5
_081B5728: .4byte 0x020205AC
	thumb_func_end party_menu_link_mon_icon_anim

	thumb_func_start sub_081B572C
sub_081B572C: @ 0x081B572C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r0, r1, #0
	adds r1, r2, #0
	bl GetHPBarLevel
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq _081B578C
	cmp r0, #2
	bgt _081B5754
	cmp r0, #1
	beq _081B57A4
	b _081B57BC
_081B5754:
	cmp r0, #3
	beq _081B5774
	cmp r0, #4
	bne _081B57BC
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _081B5770
	adds r0, r0, r1
	movs r1, #0
	bl SetPartyHPBarSprite
	b _081B57CC
	.align 2, 0
_081B5770: .4byte 0x020205AC
_081B5774:
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _081B5788
	adds r0, r0, r1
	movs r1, #1
	bl SetPartyHPBarSprite
	b _081B57CC
	.align 2, 0
_081B5788: .4byte 0x020205AC
_081B578C:
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _081B57A0
	adds r0, r0, r1
	movs r1, #2
	bl SetPartyHPBarSprite
	b _081B57CC
	.align 2, 0
_081B57A0: .4byte 0x020205AC
_081B57A4:
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _081B57B8
	adds r0, r0, r1
	movs r1, #3
	bl SetPartyHPBarSprite
	b _081B57CC
	.align 2, 0
_081B57B8: .4byte 0x020205AC
_081B57BC:
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, _081B57D4
	adds r0, r0, r1
	movs r1, #4
	bl SetPartyHPBarSprite
_081B57CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B57D4: .4byte 0x020205AC
	thumb_func_end sub_081B572C

	thumb_func_start sub_081B57D8
sub_081B57D8: @ 0x081B57D8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	adds r0, r6, #0
	movs r1, #0x39
	bl GetMonData3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r6, #0
	movs r1, #0x3a
	bl GetMonData3
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_081B572C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_081B57D8

	thumb_func_start AnimateSelectedPartyIcon
AnimateSelectedPartyIcon: @ 0x081B580C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	ldr r5, _081B583C
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r6, r0, #2
	adds r2, r6, r5
	movs r7, #0
	movs r3, #0
	strh r3, [r2, #0x2e]
	mov ip, r5
	cmp r1, #0
	bne _081B5864
	movs r1, #0x20
	ldrsh r0, [r2, r1]
	cmp r0, #0x18
	bne _081B5844
	strh r3, [r2, #0x24]
	ldr r0, _081B5840
	strh r0, [r2, #0x26]
	b _081B584A
	.align 2, 0
_081B583C: .4byte 0x020205AC
_081B5840: .4byte 0x0000FFFC
_081B5844:
	ldr r0, _081B585C
	strh r0, [r2, #0x24]
	strh r3, [r2, #0x26]
_081B584A:
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	mov r1, ip
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _081B5860
	b _081B5870
	.align 2, 0
_081B585C: .4byte 0x0000FFFC
_081B5860: .4byte 0x081B58A9
_081B5864:
	strh r3, [r2, #0x24]
	strh r3, [r2, #0x26]
	adds r0, r5, #0
	adds r0, #0x1c
	adds r0, r6, r0
	ldr r1, _081B5878
_081B5870:
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B5878: .4byte 0x081B587D
	thumb_func_end AnimateSelectedPartyIcon

	thumb_func_start UpdatePartyMonIconFrameAndBounce
UpdatePartyMonIconFrameAndBounce: @ 0x081B587C
	push {r4, lr}
	adds r4, r0, #0
	bl UpdateMonIconFrame
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _081B58A2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081B58A0
	ldr r0, _081B589C
	strh r0, [r4, #0x26]
	b _081B58A2
	.align 2, 0
_081B589C: .4byte 0x0000FFFD
_081B58A0:
	strh r1, [r4, #0x26]
_081B58A2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end UpdatePartyMonIconFrameAndBounce

	thumb_func_start UpdatePartyMonIconFrame
UpdatePartyMonIconFrame: @ 0x081B58A8
	push {lr}
	bl UpdateMonIconFrame
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end UpdatePartyMonIconFrame

	thumb_func_start party_menu_held_item_object
party_menu_held_item_object: @ 0x081B58B4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B58DC
	ldr r0, _081B58E4
	ldr r2, [r4, #4]
	ldrb r1, [r2, #2]
	ldrb r2, [r2, #3]
	movs r3, #0
	bl CreateSprite
	strb r0, [r4, #0xa]
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_081B5934
_081B58DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B58E4: .4byte 0x085E1778
	thumb_func_end party_menu_held_item_object

	thumb_func_start party_menu_link_mon_held_item_object
party_menu_link_mon_held_item_object: @ 0x081B58E8
	push {r4, r5, lr}
	adds r4, r2, #0
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r0, #0
	beq _081B5924
	ldr r0, _081B592C
	ldr r2, [r4, #4]
	ldrb r1, [r2, #2]
	ldrb r2, [r2, #3]
	movs r3, #0
	bl CreateSprite
	strb r0, [r4, #0xa]
	ldr r2, _081B5930
	ldrb r0, [r4, #0xa]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_081B5950
_081B5924:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B592C: .4byte 0x085E1778
_081B5930: .4byte 0x020205AC
	thumb_func_end party_menu_link_mon_held_item_object

	thumb_func_start sub_081B5934
sub_081B5934: @ 0x081B5934
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0xc
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl sub_081B5950
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B5934

	thumb_func_start sub_081B5950
sub_081B5950: @ 0x081B5950
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _081B5978
	ldr r2, _081B5974
	ldrb r1, [r4, #0xa]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _081B59C4
	.align 2, 0
_081B5974: .4byte 0x020205AC
_081B5978:
	bl ItemIsMail
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B599C
	ldrb r1, [r4, #0xa]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _081B5998
	adds r0, r0, r1
	movs r1, #1
	bl StartSpriteAnim
	b _081B59AE
	.align 2, 0
_081B5998: .4byte 0x020205AC
_081B599C:
	ldrb r1, [r4, #0xa]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _081B59CC
	adds r0, r0, r1
	movs r1, #0
	bl StartSpriteAnim
_081B59AE:
	ldr r2, _081B59CC
	ldrb r1, [r4, #0xa]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
_081B59C4:
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B59CC: .4byte 0x020205AC
	thumb_func_end sub_081B5950

	thumb_func_start LoadHeldItemIcons
LoadHeldItemIcons: @ 0x081B59D0
	push {lr}
	ldr r0, _081B59E4
	bl LoadSpriteSheet
	ldr r0, _081B59E8
	bl LoadSpritePalette
	pop {r0}
	bx r0
	.align 2, 0
_081B59E4: .4byte 0x085E1768
_081B59E8: .4byte 0x085E1770
	thumb_func_end LoadHeldItemIcons

	thumb_func_start sub_081B59EC
sub_081B59EC: @ 0x081B59EC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r2, #0
	beq _081B5A00
	cmp r2, #1
	beq _081B5A48
	b _081B5A84
_081B5A00:
	movs r5, #0
	ldrb r0, [r6]
	cmp r5, r0
	bhs _081B5A84
_081B5A08:
	movs r0, #0x64
	muls r0, r5, r0
	ldr r1, _081B5A44
	adds r0, r0, r1
	movs r1, #0xc
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _081B5A34
	adds r0, r7, r5
	ldrb r4, [r0]
	adds r0, r1, #0
	bl ItemIsMail
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_081B5A90
_081B5A34:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrb r0, [r6]
	cmp r5, r0
	blo _081B5A08
	b _081B5A84
	.align 2, 0
_081B5A44: .4byte 0x02024190
_081B5A48:
	movs r5, #0
	b _081B5A7E
_081B5A4C:
	movs r0, #0x64
	muls r0, r5, r0
	ldr r1, _081B5A8C
	adds r0, r0, r1
	movs r1, #0xc
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _081B5A78
	adds r0, r5, r7
	ldrb r4, [r0, #6]
	adds r0, r1, #0
	bl ItemIsMail
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_081B5A90
_081B5A78:
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_081B5A7E:
	ldrb r0, [r6, #1]
	cmp r5, r0
	blo _081B5A4C
_081B5A84:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B5A8C: .4byte 0x020243E8
	thumb_func_end sub_081B59EC

	thumb_func_start sub_081B5A90
sub_081B5A90: @ 0x081B5A90
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r6, r0, #0
	mov sb, r1
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r0, sb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r0, _081B5B08
	mov r8, r0
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	add r0, r8
	adds r0, #0x43
	ldrb r3, [r0]
	ldr r0, _081B5B0C
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r1, #0xfa
	movs r2, #0xaa
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	mov r0, r8
	adds r5, r4, r0
	movs r0, #4
	strh r0, [r5, #0x24]
	movs r0, #0xa
	strh r0, [r5, #0x26]
	movs r0, #0x1c
	add r8, r0
	add r4, r8
	ldr r0, _081B5B10
	str r0, [r4]
	strh r6, [r5, #0x3c]
	adds r0, r5, #0
	mov r1, sb
	bl StartSpriteAnim
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B5B08: .4byte 0x020205AC
_081B5B0C: .4byte 0x085E1778
_081B5B10: .4byte 0x081B5B15
	thumb_func_end sub_081B5A90

	thumb_func_start SpriteCB_HeldItem
SpriteCB_HeldItem: @ 0x081B5B14
	push {r4, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x3c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _081B5B44
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r0, r2
	adds r0, r2, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _081B5B48
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	b _081B5B66
	.align 2, 0
_081B5B44: .4byte 0x020205AC
_081B5B48:
	adds r3, r4, #0
	adds r3, #0x3e
	ldrb r1, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrh r0, [r2, #0x24]
	ldrh r1, [r2, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r2, #0x26]
	ldrh r2, [r2, #0x22]
	adds r0, r0, r2
	strh r0, [r4, #0x22]
_081B5B66:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end SpriteCB_HeldItem

	thumb_func_start party_menu_pokeball_object
party_menu_pokeball_object: @ 0x081B5B6C
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B5B8A
	ldr r0, _081B5B90
	ldr r2, [r4, #4]
	ldrb r1, [r2, #6]
	ldrb r2, [r2, #7]
	movs r3, #8
	bl CreateSprite
	strb r0, [r4, #0xb]
_081B5B8A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B5B90: .4byte 0x085E17C0
	thumb_func_end party_menu_pokeball_object

	thumb_func_start party_menu_link_mon_pokeball_object
party_menu_link_mon_pokeball_object: @ 0x081B5B94
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _081B5BC4
	ldr r0, _081B5BCC
	ldr r2, [r4, #4]
	ldrb r1, [r2, #6]
	ldrb r2, [r2, #7]
	movs r3, #8
	bl CreateSprite
	strb r0, [r4, #0xb]
	ldr r2, _081B5BD0
	ldrb r0, [r4, #0xb]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
_081B5BC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B5BCC: .4byte 0x085E17C0
_081B5BD0: .4byte 0x020205AC
	thumb_func_end party_menu_link_mon_pokeball_object

	thumb_func_start sub_081B5BD4
sub_081B5BD4: @ 0x081B5BD4
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _081B5C0C
	adds r1, r3, #0
	movs r3, #8
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _081B5C10
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r3, [r1, #5]
	movs r2, #0xd
	rsbs r2, r2, #0
	ands r2, r3
	movs r3, #8
	orrs r2, r3
	strb r2, [r1, #5]
	pop {r1}
	bx r1
	.align 2, 0
_081B5C0C: .4byte 0x085E17C0
_081B5C10: .4byte 0x020205AC
	thumb_func_end sub_081B5BD4

	thumb_func_start sub_081B5C14
sub_081B5C14: @ 0x081B5C14
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _081B5C34
	adds r1, r3, #0
	movs r3, #8
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_081B5C34: .4byte 0x085E1830
	thumb_func_end sub_081B5C14

	thumb_func_start sub_081B5C38
sub_081B5C38: @ 0x081B5C38
	push {lr}
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r2, _081B5C58
	adds r0, r0, r2
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.align 2, 0
_081B5C58: .4byte 0x020205AC
	thumb_func_end sub_081B5C38

	thumb_func_start sub_081B5C5C
sub_081B5C5C: @ 0x081B5C5C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	cmp r6, #0
	bne _081B5CA0
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _081B5C9C
	mov r8, r0
	add r4, r8
	adds r0, r4, #0
	movs r1, #2
	bl StartSpriteAnim
	lsls r5, r7, #4
	adds r5, r5, r7
	lsls r5, r5, #2
	add r5, r8
	adds r0, r5, #0
	movs r1, #4
	bl StartSpriteAnim
	strh r6, [r4, #0x26]
	strh r6, [r5, #0x26]
	b _081B5CCC
	.align 2, 0
_081B5C9C: .4byte 0x020205AC
_081B5CA0:
	lsls r5, r0, #4
	adds r5, r5, r0
	lsls r5, r5, #2
	ldr r0, _081B5CD8
	mov r8, r0
	add r5, r8
	adds r0, r5, #0
	movs r1, #3
	bl StartSpriteAnim
	lsls r4, r7, #4
	adds r4, r4, r7
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	movs r1, #5
	bl StartSpriteAnim
	ldr r0, _081B5CDC
	strh r0, [r5, #0x26]
	movs r0, #4
	strh r0, [r4, #0x26]
_081B5CCC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B5CD8: .4byte 0x020205AC
_081B5CDC: .4byte 0x0000FFFC
	thumb_func_end sub_081B5C5C

	thumb_func_start LoadPartyMenuPokeballGfx
LoadPartyMenuPokeballGfx: @ 0x081B5CE0
	push {lr}
	ldr r0, _081B5CF8
	bl LoadCompressedSpriteSheet
	ldr r0, _081B5CFC
	bl LoadCompressedSpriteSheet
	ldr r0, _081B5D00
	bl LoadCompressedSpritePalette
	pop {r0}
	bx r0
	.align 2, 0
_081B5CF8: .4byte 0x085E17B0
_081B5CFC: .4byte 0x085E1828
_081B5D00: .4byte 0x085E17B8
	thumb_func_end LoadPartyMenuPokeballGfx

	thumb_func_start party_menu_status_condition_object
party_menu_status_condition_object: @ 0x081B5D04
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B5D2C
	ldr r0, _081B5D34
	ldr r2, [r4, #4]
	ldrb r1, [r2, #4]
	ldrb r2, [r2, #5]
	movs r3, #0
	bl CreateSprite
	strb r0, [r4, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	bl party_menu_get_status_condition_and_update_object
_081B5D2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B5D34: .4byte 0x085E18C0
	thumb_func_end party_menu_status_condition_object

	thumb_func_start party_menu_link_mon_status_condition_object
party_menu_link_mon_status_condition_object: @ 0x081B5D38
	push {r4, r5, lr}
	adds r4, r2, #0
	lsls r0, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	cmp r0, #0
	beq _081B5D74
	ldr r0, _081B5D7C
	ldr r2, [r4, #4]
	ldrb r1, [r2, #4]
	ldrb r2, [r2, #5]
	movs r3, #0
	bl CreateSprite
	strb r0, [r4, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	bl party_menu_update_status_condition_object
	ldr r2, _081B5D80
	ldrb r0, [r4, #0xc]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
_081B5D74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B5D7C: .4byte 0x085E18C0
_081B5D80: .4byte 0x020205AC
	thumb_func_end party_menu_link_mon_status_condition_object

	thumb_func_start party_menu_get_status_condition_and_update_object
party_menu_get_status_condition_and_update_object: @ 0x081B5D84
	push {r4, lr}
	adds r4, r1, #0
	bl GetMonAilment
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	bl party_menu_update_status_condition_object
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end party_menu_get_status_condition_and_update_object

	thumb_func_start party_menu_update_status_condition_object
party_menu_update_status_condition_object: @ 0x081B5D9C
	push {r4, r5, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _081B5DAC
	cmp r2, #6
	bne _081B5DC8
_081B5DAC:
	ldr r2, _081B5DC4
	ldrb r1, [r5, #0xc]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _081B5DF2
	.align 2, 0
_081B5DC4: .4byte 0x020205AC
_081B5DC8:
	ldrb r1, [r5, #0xc]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _081B5DFC
	adds r0, r0, r4
	subs r1, r2, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl StartSpriteAnim
	ldrb r1, [r5, #0xc]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
_081B5DF2:
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B5DFC: .4byte 0x020205AC
	thumb_func_end party_menu_update_status_condition_object

	thumb_func_start LoadPartyMenuAilmentGfx
LoadPartyMenuAilmentGfx: @ 0x081B5E00
	push {lr}
	ldr r0, _081B5E14
	bl LoadCompressedSpriteSheet
	ldr r0, _081B5E18
	bl LoadCompressedSpritePalette
	pop {r0}
	bx r0
	.align 2, 0
_081B5E14: .4byte 0x085E18B0
_081B5E18: .4byte 0x085E18B8
	thumb_func_end LoadPartyMenuAilmentGfx

	thumb_func_start sub_081B5E1C
sub_081B5E1C: @ 0x081B5E1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r0, _081B5E44
	mov r8, r0
	ldr r0, _081B5E48
	ldr r1, _081B5E4C
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B5E5C
	movs r7, #1
	bl sub_081B8624
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _081B5E60
	.align 2, 0
_081B5E44: .4byte 0x081B5EF5
_081B5E48: .4byte 0x03002360
_081B5E4C: .4byte 0x00000439
_081B5E50:
	ldr r0, _081B5E58
	strb r5, [r0, #9]
	b _081B5EA4
	.align 2, 0
_081B5E58: .4byte 0x0203CB94
_081B5E5C:
	movs r7, #0
	movs r6, #0
_081B5E60:
	ldr r4, _081B5EAC
	ldrh r0, [r4]
	bl GetItemEffectType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _081B5EBC
	ldr r1, _081B5EB0
	movs r0, #0
	strb r0, [r1, #9]
	movs r5, #0
_081B5E78:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _081B5EB4
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B5E9A
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	beq _081B5E50
_081B5E9A:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #5
	bls _081B5E78
_081B5EA4:
	ldr r0, _081B5EB8
	movs r1, #0x7f
	b _081B5ED0
	.align 2, 0
_081B5EAC: .4byte 0x0203CB48
_081B5EB0: .4byte 0x0203CB94
_081B5EB4: .4byte 0x02024190
_081B5EB8: .4byte 0x081B5F21
_081B5EBC:
	ldrh r0, [r4]
	bl GetPocketByItemId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #5
	cmp r0, #3
	bne _081B5ECE
	movs r1, #4
_081B5ECE:
	ldr r0, _081B5EF0
_081B5ED0:
	str r1, [sp]
	str r0, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl InitPartyMenu
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B5EF0: .4byte 0x081B1041
	thumb_func_end sub_081B5E1C

	thumb_func_start c2_815ABFC
c2_815ABFC: @ 0x081B5EF4
	push {lr}
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B5F0C
	movs r0, #0xc
	movs r1, #5
	movs r2, #0
	bl GoToBagMenu
	b _081B5F16
_081B5F0C:
	ldr r0, _081B5F1C
	ldr r1, [r0]
	movs r0, #4
	bl sub_081C47A0
_081B5F16:
	pop {r0}
	bx r0
	.align 2, 0
_081B5F1C: .4byte 0x0203CBFC
	thumb_func_end c2_815ABFC

	thumb_func_start sub_081B5F20
sub_081B5F20: @ 0x081B5F20
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _081B5F58
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B5F52
	ldr r0, _081B5F5C
	ldrb r1, [r0, #8]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #1
	bne _081B5F46
	ldr r0, _081B5F60
	ldr r1, [r0]
	ldr r0, _081B5F64
	str r0, [r1, #4]
_081B5F46:
	ldr r0, _081B5F68
	ldr r1, _081B5F6C
	ldr r2, [r0]
	adds r0, r3, #0
	bl _call_via_r2
_081B5F52:
	pop {r0}
	bx r0
	.align 2, 0
_081B5F58: .4byte 0x02037C74
_081B5F5C: .4byte 0x0203CB94
_081B5F60: .4byte 0x0203CB90
_081B5F64: .4byte 0x081B8DE1
_081B5F68: .4byte 0x03006068
_081B5F6C: .4byte 0x081B6435
	thumb_func_end sub_081B5F20

	thumb_func_start IsHPRecoveryItem
IsHPRecoveryItem: @ 0x081B5F70
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xaf
	bne _081B5F8C
	ldr r0, _081B5F84
	ldr r0, [r0]
	ldr r1, _081B5F88
	adds r0, r0, r1
	b _081B5F96
	.align 2, 0
_081B5F84: .4byte 0x03005AEC
_081B5F88: .4byte 0x00003214
_081B5F8C:
	ldr r1, _081B5FA4
	subs r0, #0xd
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
_081B5F96:
	ldrb r1, [r0, #4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _081B5FA8
	movs r0, #0
	b _081B5FAA
	.align 2, 0
_081B5FA4: .4byte 0x082EEF14
_081B5FA8:
	movs r0, #1
_081B5FAA:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsHPRecoveryItem

	thumb_func_start GetMedicineItemEffectMessage
GetMedicineItemEffectMessage: @ 0x081B5FB0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl GetItemEffectType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #3
	cmp r0, #0x12
	bls _081B5FC6
	b _081B615C
_081B5FC6:
	lsls r0, r0, #2
	ldr r1, _081B5FD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081B5FD0: .4byte 0x081B5FD4
_081B5FD4: @ jump table
	.4byte _081B6020 @ case 0
	.4byte _081B6034 @ case 1
	.4byte _081B6048 @ case 2
	.4byte _081B605C @ case 3
	.4byte _081B6070 @ case 4
	.4byte _081B6084 @ case 5
	.4byte _081B6098 @ case 6
	.4byte _081B615C @ case 7
	.4byte _081B60AC @ case 8
	.4byte _081B60D0 @ case 9
	.4byte _081B60C0 @ case 10
	.4byte _081B6100 @ case 11
	.4byte _081B6110 @ case 12
	.4byte _081B60F0 @ case 13
	.4byte _081B60E0 @ case 14
	.4byte _081B615C @ case 15
	.4byte _081B6134 @ case 16
	.4byte _081B6134 @ case 17
	.4byte _081B6148 @ case 18
_081B6020:
	ldr r0, _081B602C
	ldr r1, _081B6030
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B602C: .4byte 0x02021C7C
_081B6030: .4byte 0x085C9EA6
_081B6034:
	ldr r0, _081B6040
	ldr r1, _081B6044
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B6040: .4byte 0x02021C7C
_081B6044: .4byte 0x085C9ED4
_081B6048:
	ldr r0, _081B6054
	ldr r1, _081B6058
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B6054: .4byte 0x02021C7C
_081B6058: .4byte 0x085C9EE2
_081B605C:
	ldr r0, _081B6068
	ldr r1, _081B606C
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B6068: .4byte 0x02021C7C
_081B606C: .4byte 0x085C9EF2
_081B6070:
	ldr r0, _081B607C
	ldr r1, _081B6080
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B607C: .4byte 0x02021C7C
_081B6080: .4byte 0x085C9EC0
_081B6084:
	ldr r0, _081B6090
	ldr r1, _081B6094
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B6090: .4byte 0x02021C7C
_081B6094: .4byte 0x085C9FE7
_081B6098:
	ldr r0, _081B60A4
	ldr r1, _081B60A8
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B60A4: .4byte 0x02021C7C
_081B60A8: .4byte 0x085C9FF7
_081B60AC:
	ldr r0, _081B60B8
	ldr r1, _081B60BC
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B60B8: .4byte 0x02021C7C
_081B60BC: .4byte 0x085C9F2B
_081B60C0:
	ldr r0, _081B60C8
	ldr r1, _081B60CC
	b _081B6114
	.align 2, 0
_081B60C8: .4byte 0x02021C54
_081B60CC: .4byte 0x085C9AE7
_081B60D0:
	ldr r0, _081B60D8
	ldr r1, _081B60DC
	b _081B6114
	.align 2, 0
_081B60D8: .4byte 0x02021C54
_081B60DC: .4byte 0x085CA36F
_081B60E0:
	ldr r0, _081B60E8
	ldr r1, _081B60EC
	b _081B6114
	.align 2, 0
_081B60E8: .4byte 0x02021C54
_081B60EC: .4byte 0x085CA374
_081B60F0:
	ldr r0, _081B60F8
	ldr r1, _081B60FC
	b _081B6114
	.align 2, 0
_081B60F8: .4byte 0x02021C54
_081B60FC: .4byte 0x085CA383
_081B6100:
	ldr r0, _081B6108
	ldr r1, _081B610C
	b _081B6114
	.align 2, 0
_081B6108: .4byte 0x02021C54
_081B610C: .4byte 0x085C9AED
_081B6110:
	ldr r0, _081B6124
	ldr r1, _081B6128
_081B6114:
	bl StringCopy
	ldr r0, _081B612C
	ldr r1, _081B6130
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B6124: .4byte 0x02021C54
_081B6128: .4byte 0x085C9AF2
_081B612C: .4byte 0x02021C7C
_081B6130: .4byte 0x085C9F5F
_081B6134:
	ldr r0, _081B6140
	ldr r1, _081B6144
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B6140: .4byte 0x02021C7C
_081B6144: .4byte 0x085C9F3B
_081B6148:
	ldr r0, _081B6154
	ldr r1, _081B6158
	bl StringExpandPlaceholders
	b _081B6164
	.align 2, 0
_081B6154: .4byte 0x02021C7C
_081B6158: .4byte 0x085C9F06
_081B615C:
	ldr r0, _081B6168
	ldr r1, _081B616C
	bl StringExpandPlaceholders
_081B6164:
	pop {r0}
	bx r0
	.align 2, 0
_081B6168: .4byte 0x02021C7C
_081B616C: .4byte 0x085C9AF7
	thumb_func_end GetMedicineItemEffectMessage

	thumb_func_start UsingHPEVItemOnShedinja
UsingHPEVItemOnShedinja: @ 0x081B6170
	push {r4, lr}
	adds r4, r0, #0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	bl GetItemEffectType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bne _081B619C
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	ldr r1, _081B6198
	cmp r0, r1
	bne _081B619C
	movs r0, #0
	b _081B619E
	.align 2, 0
_081B6198: .4byte 0x0000012F
_081B619C:
	movs r0, #1
_081B619E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end UsingHPEVItemOnShedinja

	thumb_func_start IsItemFlute
IsItemFlute: @ 0x081B61A4
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x27
	beq _081B61B6
	cmp r0, #0x29
	beq _081B61B6
	cmp r0, #0x28
	bne _081B61BA
_081B61B6:
	movs r0, #1
	b _081B61BC
_081B61BA:
	movs r0, #0
_081B61BC:
	pop {r1}
	bx r1
	thumb_func_end IsItemFlute

	thumb_func_start ExecuteTableBasedItemEffect__
ExecuteTableBasedItemEffect__: @ 0x081B61C0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _081B61EC
	ldr r1, _081B61F0
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081B61F8
	movs r0, #0x64
	muls r0, r3, r0
	ldr r1, _081B61F4
	adds r0, r0, r1
	adds r1, r5, #0
	adds r2, r3, #0
	b _081B6212
	.align 2, 0
_081B61EC: .4byte 0x03002360
_081B61F0: .4byte 0x00000439
_081B61F4: .4byte 0x02024190
_081B61F8:
	movs r0, #0x64
	adds r4, r3, #0
	muls r4, r0, r4
	ldr r0, _081B6224
	adds r4, r4, r0
	adds r0, r3, #0
	bl sub_081B8BD8
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
_081B6212:
	adds r3, r6, #0
	bl ExecuteTableBasedItemEffect
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081B6224: .4byte 0x02024190
	thumb_func_end ExecuteTableBasedItemEffect__

	thumb_func_start ItemUseCB_Medicine
ItemUseCB_Medicine: @ 0x081B6228
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r1, [sp, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r0, #0
	mov sl, r0
	ldr r0, _081B62B0
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B62B4
	adds r5, r1, r0
	ldr r0, _081B62B8
	ldrh r6, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl UsingHPEVItemOnShedinja
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B62A0
	adds r0, r6, #0
	bl IsHPRecoveryItem
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #1
	bne _081B628E
	adds r0, r5, #0
	movs r1, #0x39
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	adds r0, r5, #0
	movs r1, #0x3a
	bl GetMonData3
	cmp sl, r0
	bne _081B628E
	movs r1, #0
	mov r8, r1
_081B628E:
	ldr r4, _081B62B0
	ldrb r0, [r4, #9]
	adds r1, r6, #0
	movs r2, #0
	bl ExecuteTableBasedItemEffect__
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B62C4
_081B62A0:
	ldr r1, _081B62BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #5
	bl PlaySE
	ldr r0, _081B62C0
	b _081B6394
	.align 2, 0
_081B62B0: .4byte 0x0203CB94
_081B62B4: .4byte 0x02024190
_081B62B8: .4byte 0x0203CB48
_081B62BC: .4byte 0x0203CBB4
_081B62C0: .4byte 0x085C9AF7
_081B62C4:
	ldr r1, _081B62EC
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl IsItemFlute
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B62F0
	movs r0, #1
	bl PlaySE
	ldrb r0, [r4, #0xb]
	cmp r0, #0xe
	beq _081B62F6
	adds r0, r6, #0
	movs r1, #1
	bl RemoveBagItem
	b _081B62F6
	.align 2, 0
_081B62EC: .4byte 0x0203CBB4
_081B62F0:
	movs r0, #0x75
	bl PlaySE
_081B62F6:
	ldr r4, _081B6374
	ldr r7, _081B6378
	movs r0, #9
	ldrsb r0, [r7, r0]
	lsls r0, r0, #4
	ldr r1, [r4]
	adds r1, r1, r0
	adds r0, r5, #0
	bl party_menu_get_status_condition_and_update_object
	ldr r2, _081B637C
	movs r0, #9
	ldrsb r0, [r7, r0]
	ldr r1, [r4]
	lsls r0, r0, #4
	adds r3, r0, r1
	ldrb r1, [r3, #0xc]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _081B6334
	adds r0, r5, #0
	adds r1, r3, #0
	movs r2, #1
	bl DisplayPartyPokemonLevelCheck
_081B6334:
	mov r2, r8
	cmp r2, #1
	bne _081B6384
	mov r0, sl
	cmp r0, #0
	bne _081B6348
	ldrb r0, [r7, #9]
	movs r1, #1
	bl AnimatePartySlot
_081B6348:
	adds r0, r5, #0
	movs r1, #0x39
	bl GetMonData3
	adds r3, r0, #0
	mov r1, sl
	subs r3, r3, r1
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	ldrb r1, [r7, #9]
	ldr r0, _081B6380
	str r0, [sp]
	mov r0, sb
	movs r2, #1
	bl PartyMenuModifyHP
	mov r0, sb
	movs r1, #0
	mov r2, sl
	bl sub_081B1C78
	b _081B63B0
	.align 2, 0
_081B6374: .4byte 0x0203CBA8
_081B6378: .4byte 0x0203CB94
_081B637C: .4byte 0x020205AC
_081B6380: .4byte 0x081B63CD
_081B6384:
	ldr r1, _081B63C0
	adds r0, r5, #0
	bl GetMonNickname
	adds r0, r6, #0
	bl GetMedicineItemEffectMessage
	ldr r0, _081B63C4
_081B6394:
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B63C8
	mov r2, sb
	lsls r0, r2, #2
	add r0, sb
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [sp, #4]
	str r1, [r0]
_081B63B0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B63C0: .4byte 0x02021C40
_081B63C4: .4byte 0x02021C7C
_081B63C8: .4byte 0x03005B60
	thumb_func_end ItemUseCB_Medicine

	thumb_func_start sub_081B63CC
sub_081B63CC: @ 0x081B63CC
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _081B6418
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B641C
	adds r0, r0, r1
	ldr r1, _081B6420
	bl GetMonNickname
	ldr r4, _081B6424
	ldr r1, _081B6428
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #0
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	bl HandleBattleLowHpMusicChange
	ldr r1, _081B642C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6430
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B6418: .4byte 0x0203CB94
_081B641C: .4byte 0x02024190
_081B6420: .4byte 0x02021C40
_081B6424: .4byte 0x02021C7C
_081B6428: .4byte 0x085C9E8F
_081B642C: .4byte 0x03005B60
_081B6430: .4byte 0x081B6435
	thumb_func_end sub_081B63CC

	thumb_func_start sub_081B6434
sub_081B6434: @ 0x081B6434
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B645A
	ldr r0, _081B6460
	ldrb r1, [r0]
	cmp r1, #0
	bne _081B6454
	ldr r0, _081B6464
	ldr r0, [r0]
	str r1, [r0, #4]
_081B6454:
	adds r0, r4, #0
	bl sub_081B0F90
_081B645A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6460: .4byte 0x0203CBB4
_081B6464: .4byte 0x0203CB90
	thumb_func_end sub_081B6434

	thumb_func_start sub_081B6468
sub_081B6468: @ 0x081B6468
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r1, [sp]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r4, _081B6500
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B6504
	adds r5, r1, r0
	ldr r0, _081B6508
	ldrh r6, [r0]
	adds r0, r6, #0
	bl GetItemEffectType
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r5, #0
	movs r1, #0x20
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r7, #0
	bl ItemEffectToMonEv
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	ldrb r0, [r4, #9]
	adds r1, r6, #0
	movs r2, #0
	bl ExecuteTableBasedItemEffect__
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #0x20
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	adds r0, r5, #0
	adds r1, r7, #0
	bl ItemEffectToMonEv
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r4, #0
	bne _081B64F0
	ldr r0, [sp, #4]
	cmp r0, sb
	bne _081B6514
	ldr r1, [sp, #8]
	cmp r1, r8
	bne _081B6514
_081B64F0:
	ldr r1, _081B650C
	movs r0, #0
	strb r0, [r1]
	movs r0, #5
	bl PlaySE
	ldr r0, _081B6510
	b _081B6582
	.align 2, 0
_081B6500: .4byte 0x0203CB94
_081B6504: .4byte 0x02024190
_081B6508: .4byte 0x0203CB48
_081B650C: .4byte 0x0203CBB4
_081B6510: .4byte 0x085C9AF7
_081B6514:
	ldr r1, _081B6550
	movs r0, #1
	strb r0, [r1]
	movs r0, #1
	bl PlaySE
	adds r0, r6, #0
	movs r1, #1
	bl RemoveBagItem
	ldr r1, _081B6554
	adds r0, r5, #0
	bl GetMonNickname
	ldr r1, _081B6558
	adds r0, r7, #0
	bl ItemEffectToStatString
	ldr r2, [sp, #4]
	cmp r2, sb
	beq _081B6578
	ldr r0, [sp, #8]
	cmp r0, r8
	beq _081B6564
	ldr r0, _081B655C
	ldr r1, _081B6560
	bl StringExpandPlaceholders
	b _081B6580
	.align 2, 0
_081B6550: .4byte 0x0203CBB4
_081B6554: .4byte 0x02021C40
_081B6558: .4byte 0x02021C54
_081B655C: .4byte 0x02021C7C
_081B6560: .4byte 0x085C9F78
_081B6564:
	ldr r0, _081B6570
	ldr r1, _081B6574
	bl StringExpandPlaceholders
	b _081B6580
	.align 2, 0
_081B6570: .4byte 0x02021C7C
_081B6574: .4byte 0x085C9FC1
_081B6578:
	ldr r0, _081B65B0
	ldr r1, _081B65B4
	bl StringExpandPlaceholders
_081B6580:
	ldr r0, _081B65B0
_081B6582:
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B65B8
	mov r2, sl
	lsls r0, r2, #2
	add r0, sl
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [sp]
	str r1, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B65B0: .4byte 0x02021C7C
_081B65B4: .4byte 0x085C9F9B
_081B65B8: .4byte 0x03005B60
	thumb_func_end sub_081B6468

	thumb_func_start ItemEffectToMonEv
ItemEffectToMonEv: @ 0x081B65BC
	push {r4, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r1, #0
	subs r0, #0xc
	cmp r0, #5
	bhi _081B6632
	lsls r0, r0, #2
	ldr r1, _081B65D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081B65D8: .4byte 0x081B65DC
_081B65DC: @ jump table
	.4byte _081B660C @ case 0
	.4byte _081B65F4 @ case 1
	.4byte _081B661E @ case 2
	.4byte _081B6624 @ case 3
	.4byte _081B6618 @ case 4
	.4byte _081B6612 @ case 5
_081B65F4:
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	ldr r1, _081B6608
	cmp r0, r1
	beq _081B6632
	adds r0, r4, #0
	movs r1, #0x1a
	b _081B6628
	.align 2, 0
_081B6608: .4byte 0x0000012F
_081B660C:
	adds r0, r4, #0
	movs r1, #0x1b
	b _081B6628
_081B6612:
	adds r0, r4, #0
	movs r1, #0x1c
	b _081B6628
_081B6618:
	adds r0, r4, #0
	movs r1, #0x1d
	b _081B6628
_081B661E:
	adds r0, r4, #0
	movs r1, #0x1e
	b _081B6628
_081B6624:
	adds r0, r4, #0
	movs r1, #0x1f
_081B6628:
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _081B6634
_081B6632:
	movs r0, #0
_081B6634:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end ItemEffectToMonEv

	thumb_func_start ItemEffectToStatString
ItemEffectToStatString: @ 0x081B663C
	push {lr}
	adds r2, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #0xc
	cmp r0, #5
	bhi _081B66A8
	lsls r0, r0, #2
	ldr r1, _081B6654
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081B6654: .4byte 0x081B6658
_081B6658: @ jump table
	.4byte _081B6678 @ case 0
	.4byte _081B6670 @ case 1
	.4byte _081B6690 @ case 2
	.4byte _081B66A0 @ case 3
	.4byte _081B6688 @ case 4
	.4byte _081B6680 @ case 5
_081B6670:
	ldr r1, _081B6674
	b _081B6692
	.align 2, 0
_081B6674: .4byte 0x085C9AE7
_081B6678:
	ldr r1, _081B667C
	b _081B6692
	.align 2, 0
_081B667C: .4byte 0x085CA36F
_081B6680:
	ldr r1, _081B6684
	b _081B6692
	.align 2, 0
_081B6684: .4byte 0x085CA374
_081B6688:
	ldr r1, _081B668C
	b _081B6692
	.align 2, 0
_081B668C: .4byte 0x085CA383
_081B6690:
	ldr r1, _081B669C
_081B6692:
	adds r0, r2, #0
	bl StringCopy
	b _081B66A8
	.align 2, 0
_081B669C: .4byte 0x085C9AED
_081B66A0:
	ldr r1, _081B66AC
	adds r0, r2, #0
	bl StringCopy
_081B66A8:
	pop {r0}
	bx r0
	.align 2, 0
_081B66AC: .4byte 0x085C9AF2
	thumb_func_end ItemEffectToStatString

	thumb_func_start sub_081B66B0
sub_081B66B0: @ 0x081B66B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0
	mov sl, r0
	movs r1, #1
	mov r8, r1
	movs r0, #3
	bl sub_081B2E34
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r6, #0
	movs r0, #0x64
	adds r2, r4, #0
	muls r2, r0, r2
	str r2, [sp, #0xc]
_081B66E0:
	ldr r0, _081B6774
	adds r1, r6, #0
	adds r1, #0xd
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	bl GetMonData3
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r0, r8
	movs r1, #0
	bl GetFontAttribute
	adds r4, r0, #0
	mov r0, r8
	movs r1, #2
	bl GetFontAttribute
	adds r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r2, r5, #3
	ldr r0, _081B6778
	adds r2, r2, r0
	lsls r0, r6, #4
	adds r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r7, #0
	str r7, [sp, #8]
	mov r0, sb
	mov r1, r8
	adds r3, r4, #0
	bl AddTextPrinterParameterized
	cmp r5, #0
	beq _081B673C
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
_081B673C:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls _081B66E0
	movs r0, #0x10
	str r0, [sp]
	mov r0, sl
	str r0, [sp, #4]
	str r7, [sp, #8]
	mov r0, sb
	mov r1, r8
	movs r2, #0
	movs r3, #2
	bl sub_081984B0
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B6774: .4byte 0x02024190
_081B6778: .4byte 0x082EACC4
	thumb_func_end sub_081B66B0

	thumb_func_start ether_effect_related_3
ether_effect_related_3: @ 0x081B677C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	bl Menu_ProcessInput
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081B67B8
	adds r0, #1
	cmp r1, r0
	bne _081B67A8
	movs r0, #5
	bl PlaySE
	adds r0, r4, #0
	bl sub_081B687C
	b _081B67B8
_081B67A8:
	ldr r0, _081B67C0
	ldr r0, [r0]
	adds r0, #0xd
	bl sub_081B2CB0
	adds r0, r5, #0
	bl ether_effect_related_2
_081B67B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B67C0: .4byte 0x0203CB90
	thumb_func_end ether_effect_related_3

	thumb_func_start dp05_ether
dp05_ether: @ 0x081B67C4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _081B67DC
	ldrh r0, [r0]
	cmp r0, #0xaf
	bne _081B67E8
	ldr r0, _081B67E0
	ldr r0, [r0]
	ldr r1, _081B67E4
	adds r0, r0, r1
	b _081B67F2
	.align 2, 0
_081B67DC: .4byte 0x0203CB48
_081B67E0: .4byte 0x03005AEC
_081B67E4: .4byte 0x00003214
_081B67E8:
	ldr r1, _081B680C
	subs r0, #0xd
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
_081B67F2:
	ldrb r1, [r0, #4]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _081B6814
	ldr r0, _081B6810
	strh r1, [r0, #0xe]
	adds r0, r4, #0
	bl ether_effect_related
	b _081B6836
	.align 2, 0
_081B680C: .4byte 0x082EEF14
_081B6810: .4byte 0x0203CB94
_081B6814:
	movs r0, #5
	bl PlaySE
	movs r0, #0x16
	bl DisplayPartyMenuStdMessage
	ldr r0, _081B683C
	ldrb r0, [r0, #9]
	bl sub_081B66B0
	ldr r1, _081B6840
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6844
	str r1, [r0]
_081B6836:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B683C: .4byte 0x0203CB94
_081B6840: .4byte 0x03005B60
_081B6844: .4byte 0x081B677D
	thumb_func_end dp05_ether

	thumb_func_start ether_effect_related_2
ether_effect_related_2: @ 0x081B6848
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _081B6874
	ldr r0, [r0]
	adds r0, #0xc
	bl sub_081B2CB0
	bl Menu_GetCursorPos
	ldr r1, _081B6878
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r1, #0xe]
	adds r0, r4, #0
	bl ether_effect_related
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6874: .4byte 0x0203CB90
_081B6878: .4byte 0x0203CB94
	thumb_func_end ether_effect_related_2

	thumb_func_start sub_081B687C
sub_081B687C: @ 0x081B687C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _081B68A8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldr r0, _081B68AC
	str r0, [r1]
	ldr r0, _081B68B0
	ldr r0, [r0]
	movs r1, #0
	str r1, [r0, #4]
	adds r0, #0xc
	bl sub_081B2CB0
	movs r0, #5
	bl DisplayPartyMenuStdMessage
	pop {r0}
	bx r0
	.align 2, 0
_081B68A8: .4byte 0x03005B60
_081B68AC: .4byte 0x081B1041
_081B68B0: .4byte 0x0203CB90
	thumb_func_end sub_081B687C

	thumb_func_start ether_effect_related
ether_effect_related: @ 0x081B68B4
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r7, _081B68E4
	ldr r0, _081B68E8
	ldrh r5, [r0]
	adds r4, r7, #0
	subs r4, #0xe
	ldrb r0, [r4, #9]
	ldrb r2, [r7]
	adds r1, r5, #0
	bl ExecuteTableBasedItemEffect__
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B68F4
	ldr r1, _081B68EC
	movs r0, #0
	strb r0, [r1]
	movs r0, #5
	bl PlaySE
	ldr r0, _081B68F0
	b _081B693A
	.align 2, 0
_081B68E4: .4byte 0x0203CBA2
_081B68E8: .4byte 0x0203CB48
_081B68EC: .4byte 0x0203CBB4
_081B68F0: .4byte 0x085C9AF7
_081B68F4:
	ldr r1, _081B695C
	movs r0, #1
	strb r0, [r1]
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #0x64
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _081B6960
	adds r4, r4, r0
	movs r0, #1
	bl PlaySE
	adds r0, r5, #0
	movs r1, #1
	bl RemoveBagItem
	movs r0, #0
	ldrsh r1, [r7, r0]
	adds r1, #0xd
	adds r0, r4, #0
	bl GetMonData3
	adds r1, r0, #0
	lsls r1, r1, #0x10
	ldr r0, _081B6964
	lsrs r1, r1, #0xd
	ldr r2, _081B6968
	adds r1, r1, r2
	bl StringCopy
	adds r0, r5, #0
	bl GetMedicineItemEffectMessage
	ldr r0, _081B696C
_081B693A:
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B6970
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6974
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B695C: .4byte 0x0203CBB4
_081B6960: .4byte 0x02024190
_081B6964: .4byte 0x02021C40
_081B6968: .4byte 0x082EACC4
_081B696C: .4byte 0x02021C7C
_081B6970: .4byte 0x03005B60
_081B6974: .4byte 0x081B6435
	thumb_func_end ether_effect_related

	thumb_func_start dp05_pp_up
dp05_pp_up: @ 0x081B6978
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #5
	bl PlaySE
	movs r0, #0x17
	bl DisplayPartyMenuStdMessage
	ldr r0, _081B69A8
	ldrb r0, [r0, #9]
	bl sub_081B66B0
	ldr r1, _081B69AC
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B69B0
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B69A8: .4byte 0x0203CB94
_081B69AC: .4byte 0x03005B60
_081B69B0: .4byte 0x081B677D
	thumb_func_end dp05_pp_up

	thumb_func_start ItemIdToBattleMoveId
ItemIdToBattleMoveId: @ 0x081B69B4
	lsls r0, r0, #0x10
	ldr r1, _081B69C4
	adds r0, r0, r1
	ldr r1, _081B69C8
	lsrs r0, r0, #0xf
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_081B69C4: .4byte 0xFEDF0000
_081B69C8: .4byte 0x085E18F8
	thumb_func_end ItemIdToBattleMoveId

	thumb_func_start IsMoveHm
IsMoveHm: @ 0x081B69CC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0
	ldr r3, _081B69E8
_081B69D6:
	adds r0, r1, #0
	adds r0, #0x32
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _081B69EC
	movs r0, #1
	b _081B69F8
	.align 2, 0
_081B69E8: .4byte 0x085E18F8
_081B69EC:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #7
	bls _081B69D6
	movs r0, #0
_081B69F8:
	pop {r1}
	bx r1
	thumb_func_end IsMoveHm

	thumb_func_start MonKnowsMove
MonKnowsMove: @ 0x081B69FC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r4, #0
_081B6A06:
	adds r1, r4, #0
	adds r1, #0xd
	adds r0, r6, #0
	bl GetMonData3
	cmp r0, r5
	bne _081B6A18
	movs r0, #1
	b _081B6A24
_081B6A18:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _081B6A06
	movs r0, #0
_081B6A24:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MonKnowsMove

	thumb_func_start sub_081B6A2C
sub_081B6A2C: @ 0x081B6A2C
	push {r4, lr}
	adds r1, r0, #0
	ldr r4, _081B6A4C
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6A4C: .4byte 0x02021C7C
	thumb_func_end sub_081B6A2C

	thumb_func_start sub_081B6A50
sub_081B6A50: @ 0x081B6A50
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_081B6A2C
	ldr r1, _081B6A74
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6A78
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6A74: .4byte 0x03005B60
_081B6A78: .4byte 0x081B6435
	thumb_func_end sub_081B6A50

	thumb_func_start sub_081B6A7C
sub_081B6A7C: @ 0x081B6A7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #5
	bl PlaySE
	ldr r7, _081B6B00
	movs r1, #9
	ldrsb r1, [r7, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B6B04
	adds r5, r1, r0
	movs r0, #0xe
	adds r0, r0, r7
	mov r8, r0
	ldr r0, _081B6B08
	ldrh r4, [r0]
	ldr r1, _081B6B0C
	adds r0, r5, #0
	bl GetMonNickname
	adds r0, r4, #0
	bl ItemIdToBattleMoveId
	strh r0, [r7, #0xe]
	ldr r0, _081B6B10
	movs r2, #0xe
	ldrsh r1, [r7, r2]
	lsls r1, r1, #3
	ldr r2, _081B6B14
	adds r1, r1, r2
	bl StringCopy
	movs r0, #0
	mov r1, r8
	strh r0, [r1, #2]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl CanMonLearnTMTutor
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B6B24
	cmp r0, #2
	beq _081B6B2C
	ldrh r1, [r7, #0xe]
	adds r0, r5, #0
	bl GiveMoveToMon
	lsls r0, r0, #0x10
	ldr r1, _081B6B18
	cmp r0, r1
	beq _081B6B3C
	ldr r0, _081B6B1C
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B6B20
	str r0, [r1]
	b _081B6B50
	.align 2, 0
_081B6B00: .4byte 0x0203CB94
_081B6B04: .4byte 0x02024190
_081B6B08: .4byte 0x0203CB48
_081B6B0C: .4byte 0x02021C40
_081B6B10: .4byte 0x02021C54
_081B6B14: .4byte 0x082EACC4
_081B6B18: .4byte 0xFFFF0000
_081B6B1C: .4byte 0x03005B60
_081B6B20: .4byte 0x081B6B69
_081B6B24:
	ldr r1, _081B6B28
	b _081B6B2E
	.align 2, 0
_081B6B28: .4byte 0x085C9D7C
_081B6B2C:
	ldr r1, _081B6B38
_081B6B2E:
	adds r0, r6, #0
	bl sub_081B6A50
	b _081B6B50
	.align 2, 0
_081B6B38: .4byte 0x085C9E79
_081B6B3C:
	ldr r0, _081B6B5C
	bl sub_081B6A2C
	ldr r1, _081B6B60
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6B64
	str r1, [r0]
_081B6B50:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B6B5C: .4byte 0x085C9DA1
_081B6B60: .4byte 0x03005B60
_081B6B64: .4byte 0x081B6CA5
	thumb_func_end sub_081B6A7C

	thumb_func_start sub_081B6B68
sub_081B6B68: @ 0x081B6B68
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r2, _081B6BE8
	movs r1, #9
	ldrsb r1, [r2, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B6BEC
	adds r5, r1, r0
	adds r7, r2, #0
	adds r7, #0xe
	ldr r0, _081B6BF0
	ldrh r4, [r0]
	movs r1, #2
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bne _081B6BA4
	adds r0, r5, #0
	movs r1, #4
	bl AdjustFriendship
	movs r0, #0xa9
	lsls r0, r0, #1
	cmp r4, r0
	bhi _081B6BA4
	adds r0, r4, #0
	movs r1, #1
	bl RemoveBagItem
_081B6BA4:
	ldr r1, _081B6BF4
	adds r0, r5, #0
	bl GetMonNickname
	ldr r0, _081B6BF8
	movs r2, #0
	ldrsh r1, [r7, r2]
	lsls r1, r1, #3
	ldr r2, _081B6BFC
	adds r1, r1, r2
	bl StringCopy
	ldr r4, _081B6C00
	ldr r1, _081B6C04
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B6C08
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6C0C
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B6BE8: .4byte 0x0203CB94
_081B6BEC: .4byte 0x02024190
_081B6BF0: .4byte 0x0203CB48
_081B6BF4: .4byte 0x02021C40
_081B6BF8: .4byte 0x02021C54
_081B6BFC: .4byte 0x082EACC4
_081B6C00: .4byte 0x02021C7C
_081B6C04: .4byte 0x085C9D68
_081B6C08: .4byte 0x03005B60
_081B6C0C: .4byte 0x081B6C11
	thumb_func_end sub_081B6B68

	thumb_func_start sub_081B6C10
sub_081B6C10: @ 0x081B6C10
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B6C36
	ldr r0, _081B6C3C
	bl PlayFanfare
	ldr r1, _081B6C40
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6C44
	str r1, [r0]
_081B6C36:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6C3C: .4byte 0x0000016F
_081B6C40: .4byte 0x03005B60
_081B6C44: .4byte 0x081B6C49
	thumb_func_end sub_081B6C10

	thumb_func_start sub_081B6C48
sub_081B6C48: @ 0x081B6C48
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	bl IsFanfareTaskInactive
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B6C9A
	ldr r0, _081B6C84
	ldrh r1, [r0, #0x2e]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _081B6C70
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B6C9A
_081B6C70:
	ldr r0, _081B6C88
	movs r1, #0x10
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne _081B6C8C
	adds r0, r4, #0
	bl sub_081B7458
	b _081B6C9A
	.align 2, 0
_081B6C84: .4byte 0x03002360
_081B6C88: .4byte 0x0203CB94
_081B6C8C:
	cmp r0, #2
	bne _081B6C94
	ldr r0, _081B6CA0
	strh r2, [r0]
_081B6C94:
	adds r0, r5, #0
	bl sub_081B0F90
_081B6C9A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B6CA0: .4byte 0x02037290
	thumb_func_end sub_081B6C48

	thumb_func_start sub_081B6CA4
sub_081B6CA4: @ 0x081B6CA4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B6CC8
	bl sub_081B2FDC
	ldr r0, _081B6CD0
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B6CD4
	str r0, [r1]
_081B6CC8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6CD0: .4byte 0x03005B60
_081B6CD4: .4byte 0x081B6CD9
	thumb_func_end sub_081B6CA4

	thumb_func_start sub_081B6CD8
sub_081B6CD8: @ 0x081B6CD8
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	beq _081B6CFE
	cmp r1, #0
	bgt _081B6CF8
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081B6D24
	b _081B6D30
_081B6CF8:
	cmp r1, #1
	beq _081B6D2A
	b _081B6D30
_081B6CFE:
	ldr r0, _081B6D18
	movs r1, #1
	bl DisplayPartyMenuMessage
	ldr r1, _081B6D1C
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6D20
	str r1, [r0]
	b _081B6D30
	.align 2, 0
_081B6D18: .4byte 0x085C9E23
_081B6D1C: .4byte 0x03005B60
_081B6D20: .4byte 0x081B6D39
_081B6D24:
	movs r0, #5
	bl PlaySE
_081B6D2A:
	adds r0, r4, #0
	bl sub_081B6EE0
_081B6D30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B6CD8

	thumb_func_start sub_081B6D38
sub_081B6D38: @ 0x081B6D38
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B6D58
	ldr r0, _081B6D60
	ldr r1, [r0]
	ldr r0, _081B6D64
	str r0, [r1, #4]
	adds r0, r4, #0
	bl sub_081B0F90
_081B6D58:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6D60: .4byte 0x0203CB90
_081B6D64: .4byte 0x081B6D69
	thumb_func_end sub_081B6D38

	thumb_func_start sub_081B6D68
sub_081B6D68: @ 0x081B6D68
	push {r4, lr}
	sub sp, #4
	ldr r0, _081B6D90
	ldr r4, _081B6D94
	ldrb r1, [r4, #9]
	ldr r2, _081B6D98
	ldrb r2, [r2]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r3, _081B6D9C
	ldrh r4, [r4, #0xe]
	str r4, [sp]
	bl ShowSelectMovePokemonSummaryScreen
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6D90: .4byte 0x02024190
_081B6D94: .4byte 0x0203CB94
_081B6D98: .4byte 0x0202418D
_081B6D9C: .4byte 0x081B6DA1
	thumb_func_end sub_081B6D68

	thumb_func_start sub_081B6DA0
sub_081B6DA0: @ 0x081B6DA0
	push {lr}
	sub sp, #0xc
	movs r0, #0x7f
	str r0, [sp]
	ldr r0, _081B6DC4
	str r0, [sp, #4]
	ldr r0, _081B6DC8
	ldr r0, [r0]
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B6DC4: .4byte 0x081B6DCD
_081B6DC8: .4byte 0x0203CB94
	thumb_func_end sub_081B6DA0

	thumb_func_start sub_081B6DCC
sub_081B6DCC: @ 0x081B6DCC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	ldr r0, _081B6DF4
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B6DFE
	bl sub_081C14C8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _081B6DF8
	adds r0, r4, #0
	bl sub_081B6E04
	b _081B6DFE
	.align 2, 0
_081B6DF4: .4byte 0x02037C74
_081B6DF8:
	adds r0, r5, #0
	bl sub_081B6EE0
_081B6DFE:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_081B6DCC

	thumb_func_start sub_081B6E04
sub_081B6E04: @ 0x081B6E04
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r0, _081B6E64
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r0, _081B6E68
	adds r5, r5, r0
	bl sub_081C14C8
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r1, #0xd
	adds r0, r5, #0
	bl GetMonData3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, _081B6E6C
	adds r0, r5, #0
	bl GetMonNickname
	ldr r0, _081B6E70
	lsls r4, r4, #3
	ldr r1, _081B6E74
	adds r4, r4, r1
	adds r1, r4, #0
	bl StringCopy
	ldr r0, _081B6E78
	bl sub_081B6A2C
	ldr r1, _081B6E7C
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6E80
	str r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B6E64: .4byte 0x0203CB94
_081B6E68: .4byte 0x02024190
_081B6E6C: .4byte 0x02021C40
_081B6E70: .4byte 0x02021C54
_081B6E74: .4byte 0x082EACC4
_081B6E78: .4byte 0x085C9E35
_081B6E7C: .4byte 0x03005B60
_081B6E80: .4byte 0x081B6E85
	thumb_func_end sub_081B6E04

	thumb_func_start sub_081B6E84
sub_081B6E84: @ 0x081B6E84
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B6ED0
	ldr r5, _081B6ED8
	movs r1, #9
	ldrsb r1, [r5, r1]
	movs r0, #0x64
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _081B6EDC
	adds r4, r4, r0
	bl sub_081C14C8
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl RemoveMonPPBonus
	ldrh r5, [r5, #0xe]
	bl sub_081C14C8
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetMonMoveSlot
	adds r0, r6, #0
	bl sub_081B6B68
_081B6ED0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B6ED8: .4byte 0x0203CB94
_081B6EDC: .4byte 0x02024190
	thumb_func_end sub_081B6E84

	thumb_func_start sub_081B6EE0
sub_081B6EE0: @ 0x081B6EE0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _081B6F28
	ldr r1, _081B6F2C
	movs r2, #0xe
	ldrsh r1, [r1, r2]
	lsls r1, r1, #3
	ldr r2, _081B6F30
	adds r1, r1, r2
	bl StringCopy
	ldr r4, _081B6F34
	ldr r1, _081B6F38
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B6F3C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B6F40
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B6F28: .4byte 0x02021C54
_081B6F2C: .4byte 0x0203CB94
_081B6F30: .4byte 0x082EACC4
_081B6F34: .4byte 0x02021C7C
_081B6F38: .4byte 0x085C9DF2
_081B6F3C: .4byte 0x03005B60
_081B6F40: .4byte 0x081B6F45
	thumb_func_end sub_081B6EE0

	thumb_func_start sub_081B6F44
sub_081B6F44: @ 0x081B6F44
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B6F68
	bl sub_081B2FDC
	ldr r0, _081B6F70
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B6F74
	str r0, [r1]
_081B6F68:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B6F70: .4byte 0x03005B60
_081B6F74: .4byte 0x081B6F79
	thumb_func_end sub_081B6F44

	thumb_func_start sub_081B6F78
sub_081B6F78: @ 0x081B6F78
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r7, _081B6FA8
	movs r1, #9
	ldrsb r1, [r7, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B6FAC
	adds r4, r1, r0
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #0
	beq _081B6FB6
	cmp r5, #0
	bgt _081B6FB0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r5, r0
	beq _081B7038
	b _081B706C
	.align 2, 0
_081B6FA8: .4byte 0x0203CB94
_081B6FAC: .4byte 0x02024190
_081B6FB0:
	cmp r5, #1
	beq _081B703E
	b _081B706C
_081B6FB6:
	ldr r1, _081B6FF8
	adds r0, r4, #0
	bl GetMonNickname
	ldr r0, _081B6FFC
	movs r2, #0xe
	ldrsh r1, [r7, r2]
	lsls r1, r1, #3
	ldr r2, _081B7000
	adds r1, r1, r2
	bl StringCopy
	ldr r4, _081B7004
	ldr r1, _081B7008
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r1, #0x10
	ldrsh r0, [r7, r1]
	cmp r0, #1
	bne _081B7014
	ldr r0, _081B700C
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7010
	str r0, [r1]
	b _081B706C
	.align 2, 0
_081B6FF8: .4byte 0x02021C40
_081B6FFC: .4byte 0x02021C54
_081B7000: .4byte 0x082EACC4
_081B7004: .4byte 0x02021C7C
_081B7008: .4byte 0x085C9E0D
_081B700C: .4byte 0x03005B60
_081B7010: .4byte 0x081B7091
_081B7014:
	cmp r0, #2
	bne _081B701C
	ldr r0, _081B702C
	strh r5, [r0]
_081B701C:
	ldr r0, _081B7030
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7034
	str r0, [r1]
	b _081B706C
	.align 2, 0
_081B702C: .4byte 0x02037290
_081B7030: .4byte 0x03005B60
_081B7034: .4byte 0x081B6435
_081B7038:
	movs r0, #5
	bl PlaySE
_081B703E:
	ldr r1, _081B7074
	adds r0, r4, #0
	bl GetMonNickname
	ldr r0, _081B7078
	ldr r1, _081B707C
	movs r2, #0xe
	ldrsh r1, [r1, r2]
	lsls r1, r1, #3
	ldr r2, _081B7080
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _081B7084
	bl sub_081B6A2C
	ldr r1, _081B7088
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B708C
	str r1, [r0]
_081B706C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7074: .4byte 0x02021C40
_081B7078: .4byte 0x02021C54
_081B707C: .4byte 0x0203CB94
_081B7080: .4byte 0x082EACC4
_081B7084: .4byte 0x085C9DA1
_081B7088: .4byte 0x03005B60
_081B708C: .4byte 0x081B6CA5
	thumb_func_end sub_081B6F78

	thumb_func_start sub_081B7090
sub_081B7090: @ 0x081B7090
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B70A8
	adds r0, r4, #0
	bl sub_081B7458
_081B70A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B7090

	thumb_func_start dp05_rare_candy
dp05_rare_candy: @ 0x081B70B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _081B7114
	mov sb, r0
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B7118
	adds r5, r1, r0
	ldr r0, _081B711C
	ldr r6, [r0]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r4, r6, r1
	ldr r2, _081B7120
	mov r8, r2
	adds r0, r5, #0
	movs r1, #0x38
	bl GetMonData3
	cmp r0, #0x64
	beq _081B7124
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_081B7644
	mov r1, sb
	ldrb r0, [r1, #9]
	mov r2, r8
	ldrh r1, [r2]
	movs r2, #0
	bl ExecuteTableBasedItemEffect__
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r5, #0
	bl sub_081B7644
	b _081B7126
	.align 2, 0
_081B7114: .4byte 0x0203CB94
_081B7118: .4byte 0x02024190
_081B711C: .4byte 0x0203CB90
_081B7120: .4byte 0x0203CB48
_081B7124:
	movs r4, #1
_081B7126:
	movs r0, #5
	bl PlaySE
	cmp r4, #0
	beq _081B7160
	ldr r1, _081B7154
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081B7158
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B715C
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	mov r1, sl
	b _081B71C2
	.align 2, 0
_081B7154: .4byte 0x0203CBB4
_081B7158: .4byte 0x085C9AF7
_081B715C: .4byte 0x03005B60
_081B7160:
	ldr r1, _081B71D4
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
	bl PlayFanfareByFanfareNum
	ldr r0, _081B71D8
	ldrb r0, [r0, #9]
	adds r1, r5, #0
	bl sub_081B71F8
	ldr r0, _081B71DC
	ldrh r0, [r0]
	movs r1, #1
	bl RemoveBagItem
	ldr r1, _081B71E0
	adds r0, r5, #0
	bl GetMonNickname
	ldr r4, _081B71E4
	adds r0, r5, #0
	movs r1, #0x38
	bl GetMonData3
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r4, _081B71E8
	ldr r1, _081B71EC
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B71F0
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B71F4
_081B71C2:
	str r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B71D4: .4byte 0x0203CBB4
_081B71D8: .4byte 0x0203CB94
_081B71DC: .4byte 0x0203CB48
_081B71E0: .4byte 0x02021C40
_081B71E4: .4byte 0x02021C54
_081B71E8: .4byte 0x02021C7C
_081B71EC: .4byte 0x085C9F4E
_081B71F0: .4byte 0x03005B60
_081B71F4: .4byte 0x081B7281
	thumb_func_end dp05_rare_candy

	thumb_func_start sub_081B71F8
sub_081B71F8: @ 0x081B71F8
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r0, #0
	ldr r6, _081B7278
	lsls r4, r7, #4
	ldr r1, [r6]
	adds r1, r1, r4
	adds r0, r5, #0
	bl party_menu_get_status_condition_and_update_object
	ldr r2, _081B727C
	ldr r0, [r6]
	adds r3, r4, r0
	ldrb r1, [r3, #0xc]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _081B7234
	adds r0, r5, #0
	adds r1, r3, #0
	movs r2, #1
	bl DisplayPartyPokemonLevelCheck
_081B7234:
	ldr r1, [r6]
	adds r1, r1, r4
	adds r0, r5, #0
	movs r2, #1
	bl DisplayPartyPokemonHPCheck
	ldr r1, [r6]
	adds r1, r1, r4
	adds r0, r5, #0
	movs r2, #1
	bl DisplayPartyPokemonMaxHPCheck
	ldr r1, [r6]
	adds r1, r1, r4
	adds r0, r5, #0
	bl DisplayPartyPokemonHPBarCheck
	ldr r0, [r6]
	adds r0, r4, r0
	ldrb r0, [r0, #9]
	adds r1, r5, #0
	bl sub_081B57D8
	adds r0, r7, #0
	movs r1, #1
	bl AnimatePartySlot
	movs r0, #0
	bl ScheduleBgCopyTilemapToVram
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7278: .4byte 0x0203CBA8
_081B727C: .4byte 0x020205AC
	thumb_func_end sub_081B71F8

	thumb_func_start sub_081B7280
sub_081B7280: @ 0x081B7280
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0
	bl WaitFanfare
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B72CC
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B72CC
	ldr r0, _081B72D4
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081B72B2
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B72CC
_081B72B2:
	movs r0, #5
	bl PlaySE
	adds r0, r4, #0
	bl sub_081B7328
	ldr r0, _081B72D8
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B72DC
	str r0, [r1]
_081B72CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B72D4: .4byte 0x03002360
_081B72D8: .4byte 0x03005B60
_081B72DC: .4byte 0x081B72E1
	thumb_func_end sub_081B7280

	thumb_func_start sub_081B72E0
sub_081B72E0: @ 0x081B72E0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _081B731C
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081B72FA
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B7314
_081B72FA:
	movs r0, #5
	bl PlaySE
	adds r0, r4, #0
	bl sub_081B7374
	ldr r0, _081B7320
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7324
	str r0, [r1]
_081B7314:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B731C: .4byte 0x03002360
_081B7320: .4byte 0x03005B60
_081B7324: .4byte 0x081B73B1
	thumb_func_end sub_081B72E0

	thumb_func_start sub_081B7328
sub_081B7328: @ 0x081B7328
	push {r4, r5, lr}
	sub sp, #8
	ldr r0, _081B7370
	ldr r5, [r0]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r4, r5, r0
	bl sub_081B3004
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x18]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r2, r5, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #3
	str r1, [sp, #4]
	adds r1, r4, #0
	movs r3, #1
	bl DrawLevelUpWindowPg1
	ldrb r0, [r4, #0x18]
	movs r1, #2
	bl CopyWindowToVram
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B7370: .4byte 0x0203CB90
	thumb_func_end sub_081B7328

	thumb_func_start sub_081B7374
sub_081B7374: @ 0x081B7374
	push {r4, lr}
	sub sp, #4
	ldr r0, _081B73AC
	ldr r1, [r0]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrh r0, [r4, #0x18]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r2, #3
	str r2, [sp]
	movs r2, #1
	movs r3, #2
	bl DrawLevelUpWindowPg2
	ldrb r0, [r4, #0x18]
	movs r1, #2
	bl CopyWindowToVram
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B73AC: .4byte 0x0203CB90
	thumb_func_end sub_081B7374

	thumb_func_start sub_081B73B0
sub_081B73B0: @ 0x081B73B0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r0, #0
	bl WaitFanfare
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B7452
	ldr r0, _081B7408
	ldrh r1, [r0, #0x2e]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _081B73D8
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B7452
_081B73D8:
	bl sub_081B3034
	ldr r4, _081B740C
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B7410
	adds r0, r0, r1
	movs r1, #1
	bl MonTryLearningNewMove
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	strh r6, [r4, #0x10]
	ldr r0, _081B7414
	cmp r1, r0
	beq _081B7434
	cmp r1, r0
	bgt _081B7418
	cmp r1, #0
	beq _081B7424
	b _081B744C
	.align 2, 0
_081B7408: .4byte 0x03002360
_081B740C: .4byte 0x0203CB94
_081B7410: .4byte 0x02024190
_081B7414: .4byte 0x0000FFFE
_081B7418:
	ldr r0, _081B7420
	cmp r1, r0
	beq _081B742C
	b _081B744C
	.align 2, 0
_081B7420: .4byte 0x0000FFFF
_081B7424:
	adds r0, r5, #0
	bl sub_081B74BC
	b _081B7452
_081B742C:
	adds r0, r5, #0
	bl sub_081B7528
	b _081B7452
_081B7434:
	ldr r0, _081B7444
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7448
	str r0, [r1]
	b _081B7452
	.align 2, 0
_081B7444: .4byte 0x03005B60
_081B7448: .4byte 0x081B7459
_081B744C:
	adds r0, r5, #0
	bl sub_081B75B8
_081B7452:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_081B73B0

	thumb_func_start sub_081B7458
sub_081B7458: @ 0x081B7458
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _081B7488
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B748C
	adds r0, r0, r1
	movs r1, #0
	bl MonTryLearningNewMove
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _081B7490
	cmp r1, r0
	beq _081B74B6
	cmp r1, r0
	bgt _081B7494
	cmp r1, #0
	beq _081B74A0
	b _081B74B0
	.align 2, 0
_081B7488: .4byte 0x0203CB94
_081B748C: .4byte 0x02024190
_081B7490: .4byte 0x0000FFFE
_081B7494:
	ldr r0, _081B749C
	cmp r1, r0
	beq _081B74A8
	b _081B74B0
	.align 2, 0
_081B749C: .4byte 0x0000FFFF
_081B74A0:
	adds r0, r4, #0
	bl sub_081B74BC
	b _081B74B6
_081B74A8:
	adds r0, r4, #0
	bl sub_081B7528
	b _081B74B6
_081B74B0:
	adds r0, r4, #0
	bl sub_081B75B8
_081B74B6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081B7458

	thumb_func_start sub_081B74BC
sub_081B74BC: @ 0x081B74BC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r6, _081B7500
	movs r1, #9
	ldrsb r1, [r6, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B7504
	adds r7, r1, r0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl GetEvolutionTargetSpecies
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B750C
	bl FreePartyPointers
	ldr r0, _081B7508
	ldr r1, [r6]
	str r1, [r0]
	ldrb r3, [r6, #9]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #1
	bl BeginEvolutionScene
	adds r0, r5, #0
	bl DestroyTask
	b _081B751A
	.align 2, 0
_081B7500: .4byte 0x0203CB94
_081B7504: .4byte 0x02024190
_081B7508: .4byte 0x03005F28
_081B750C:
	ldr r0, _081B7520
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7524
	str r0, [r1]
_081B751A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7520: .4byte 0x03005B60
_081B7524: .4byte 0x081B6435
	thumb_func_end sub_081B74BC

	thumb_func_start sub_081B7528
sub_081B7528: @ 0x081B7528
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _081B7590
	mov r8, r0
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B7594
	adds r0, r0, r1
	ldr r1, _081B7598
	bl GetMonNickname
	ldr r0, _081B759C
	ldr r6, _081B75A0
	ldrh r1, [r6]
	lsls r1, r1, #3
	ldr r2, _081B75A4
	adds r1, r1, r2
	bl StringCopy
	ldr r4, _081B75A8
	ldr r1, _081B75AC
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldrh r0, [r6]
	mov r1, r8
	strh r0, [r1, #0xe]
	ldr r1, _081B75B0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B75B4
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B7590: .4byte 0x0203CB94
_081B7594: .4byte 0x02024190
_081B7598: .4byte 0x02021C40
_081B759C: .4byte 0x02021C54
_081B75A0: .4byte 0x02024186
_081B75A4: .4byte 0x082EACC4
_081B75A8: .4byte 0x02021C7C
_081B75AC: .4byte 0x085C9DA1
_081B75B0: .4byte 0x03005B60
_081B75B4: .4byte 0x081B6CA5
	thumb_func_end sub_081B7528

	thumb_func_start sub_081B75B8
sub_081B75B8: @ 0x081B75B8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r6, r0, #0
	adds r5, r1, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r0, _081B7620
	mov r8, r0
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B7624
	adds r0, r0, r1
	ldr r1, _081B7628
	bl GetMonNickname
	ldr r0, _081B762C
	lsls r1, r5, #3
	ldr r2, _081B7630
	adds r1, r1, r2
	bl StringCopy
	ldr r4, _081B7634
	ldr r1, _081B7638
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	mov r0, r8
	strh r5, [r0, #0xe]
	ldr r1, _081B763C
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B7640
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B7620: .4byte 0x0203CB94
_081B7624: .4byte 0x02024190
_081B7628: .4byte 0x02021C40
_081B762C: .4byte 0x02021C54
_081B7630: .4byte 0x082EACC4
_081B7634: .4byte 0x02021C7C
_081B7638: .4byte 0x085C9D68
_081B763C: .4byte 0x03005B60
_081B7640: .4byte 0x081B6C11
	thumb_func_end sub_081B75B8

	thumb_func_start sub_081B7644
sub_081B7644: @ 0x081B7644
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x3a
	bl GetMonData3
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #0x3b
	bl GetMonData3
	strh r0, [r5, #2]
	adds r0, r4, #0
	movs r1, #0x3c
	bl GetMonData3
	strh r0, [r5, #4]
	adds r0, r4, #0
	movs r1, #0x3e
	bl GetMonData3
	strh r0, [r5, #8]
	adds r0, r4, #0
	movs r1, #0x3f
	bl GetMonData3
	strh r0, [r5, #0xa]
	adds r0, r4, #0
	movs r1, #0x3d
	bl GetMonData3
	strh r0, [r5, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B7644

	thumb_func_start sub_081B768C
sub_081B768C: @ 0x081B768C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _081B76C0
	ldr r2, [r1]
	movs r3, #0x86
	lsls r3, r3, #2
	adds r1, r2, r3
	movs r3, #0
	strh r3, [r1]
	ldr r4, _081B76C4
	adds r1, r2, r4
	strh r3, [r1]
	ldr r1, _081B76C8
	ldrb r1, [r1, #9]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r2, r3
	strh r1, [r2]
	bl sub_081B76CC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B76C0: .4byte 0x0203CB90
_081B76C4: .4byte 0x0000021A
_081B76C8: .4byte 0x0203CB94
	thumb_func_end sub_081B768C

	thumb_func_start sub_081B76CC
sub_081B76CC: @ 0x081B76CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r8, r4
	ldr r6, _081B7724
	movs r1, #9
	ldrsb r1, [r6, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B7728
	adds r5, r1, r0
	adds r0, r5, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B7712
	adds r0, r5, #0
	movs r1, #0x39
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrb r0, [r6, #9]
	ldr r1, _081B772C
	ldrh r1, [r1]
	movs r2, #0
	bl ExecuteTableBasedItemEffect__
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B7738
_081B7712:
	ldr r0, _081B7730
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7734
	str r0, [r1]
	b _081B77CE
	.align 2, 0
_081B7724: .4byte 0x0203CB94
_081B7728: .4byte 0x02024190
_081B772C: .4byte 0x0203CB48
_081B7730: .4byte 0x03005B60
_081B7734: .4byte 0x081B77F1
_081B7738:
	movs r0, #1
	bl PlaySE
	ldr r4, _081B77DC
	movs r0, #9
	ldrsb r0, [r6, r0]
	lsls r0, r0, #4
	ldr r1, [r4]
	adds r1, r1, r0
	adds r0, r5, #0
	bl party_menu_get_status_condition_and_update_object
	ldr r2, _081B77E0
	movs r0, #9
	ldrsb r0, [r6, r0]
	ldr r1, [r4]
	lsls r0, r0, #4
	adds r3, r0, r1
	ldrb r1, [r3, #0xc]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _081B777A
	adds r0, r5, #0
	adds r1, r3, #0
	movs r2, #1
	bl DisplayPartyPokemonLevelCheck
_081B777A:
	ldr r4, _081B77E4
	ldr r0, [r4]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0
	bl AnimatePartySlot
	ldrb r0, [r6, #9]
	movs r1, #1
	bl AnimatePartySlot
	adds r0, r5, #0
	movs r1, #0x39
	bl GetMonData3
	adds r3, r0, #0
	subs r3, r3, r7
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	ldrb r1, [r6, #9]
	ldr r0, _081B77E8
	str r0, [sp]
	mov r0, r8
	movs r2, #1
	bl PartyMenuModifyHP
	mov r0, r8
	movs r1, #0
	adds r2, r7, #0
	bl sub_081B1C78
	ldr r0, [r4]
	movs r2, #0x86
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #1
	strh r2, [r1]
	ldr r1, _081B77EC
	adds r0, r0, r1
	strh r2, [r0]
_081B77CE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B77DC: .4byte 0x0203CBA8
_081B77E0: .4byte 0x020205AC
_081B77E4: .4byte 0x0203CB90
_081B77E8: .4byte 0x081B78B5
_081B77EC: .4byte 0x0000021A
	thumb_func_end sub_081B76CC

	thumb_func_start task_sacred_ash_party_loop
task_sacred_ash_party_loop: @ 0x081B77F0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B78AE
	ldr r5, _081B7858
	ldr r2, [r5]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r3, _081B785C
	cmp r0, #1
	bne _081B7826
	movs r0, #0
	strh r0, [r1]
	movs r1, #9
	ldrsb r1, [r3, r1]
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r2, r6
	strh r1, [r0]
_081B7826:
	ldrb r0, [r3, #9]
	adds r0, #1
	strb r0, [r3, #9]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	bne _081B78A8
	ldr r0, [r5]
	ldr r1, _081B7860
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bne _081B786C
	ldr r0, _081B7864
	strb r1, [r0]
	ldr r0, _081B7868
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	b _081B787C
	.align 2, 0
_081B7858: .4byte 0x0203CB90
_081B785C: .4byte 0x0203CB94
_081B7860: .4byte 0x0000021A
_081B7864: .4byte 0x0203CBB4
_081B7868: .4byte 0x085C9AF7
_081B786C:
	ldr r1, _081B7894
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081B7898
	ldrh r0, [r0]
	movs r1, #1
	bl RemoveBagItem
_081B787C:
	ldr r1, _081B789C
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B78A0
	str r1, [r0]
	ldr r1, _081B78A4
	movs r0, #0
	strb r0, [r1, #9]
	b _081B78AE
	.align 2, 0
_081B7894: .4byte 0x0203CBB4
_081B7898: .4byte 0x0203CB48
_081B789C: .4byte 0x03005B60
_081B78A0: .4byte 0x081B6435
_081B78A4: .4byte 0x0203CB94
_081B78A8:
	adds r0, r4, #0
	bl sub_081B76CC
_081B78AE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end task_sacred_ash_party_loop

	thumb_func_start sub_081B78B4
sub_081B78B4: @ 0x081B78B4
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _081B78FC
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B7900
	adds r0, r0, r1
	ldr r1, _081B7904
	bl GetMonNickname
	ldr r4, _081B7908
	ldr r1, _081B790C
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	movs r1, #0
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B7910
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B7914
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B78FC: .4byte 0x0203CB94
_081B7900: .4byte 0x02024190
_081B7904: .4byte 0x02021C40
_081B7908: .4byte 0x02021C7C
_081B790C: .4byte 0x085C9E8F
_081B7910: .4byte 0x03005B60
_081B7914: .4byte 0x081B77F1
	thumb_func_end sub_081B78B4

	thumb_func_start sub_081B7918
sub_081B7918: @ 0x081B7918
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r0, #5
	bl PlaySE
	ldr r2, _081B7964
	ldr r1, _081B7968
	ldr r0, [r1]
	str r0, [r2]
	ldrb r0, [r1, #9]
	ldr r4, _081B796C
	ldrh r1, [r4]
	movs r2, #0
	bl ExecuteTableBasedItemEffect__
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B797C
	ldr r1, _081B7970
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081B7974
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B7978
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	str r6, [r0]
	b _081B7988
	.align 2, 0
_081B7964: .4byte 0x03005F28
_081B7968: .4byte 0x0203CB94
_081B796C: .4byte 0x0203CB48
_081B7970: .4byte 0x0203CBB4
_081B7974: .4byte 0x085C9AF7
_081B7978: .4byte 0x03005B60
_081B797C:
	ldrh r0, [r4]
	movs r1, #1
	bl RemoveBagItem
	bl FreePartyPointers
_081B7988:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B7918

	thumb_func_start GetItemEffectType
GetItemEffectType: @ 0x081B7990
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r2, r1, #0
	subs r2, #0xd
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa5
	bls _081B79A4
	b _081B7AE4
_081B79A4:
	cmp r1, #0xaf
	bne _081B79BC
	ldr r0, _081B79B4
	ldr r0, [r0]
	ldr r1, _081B79B8
	adds r4, r0, r1
	b _081B79C4
	.align 2, 0
_081B79B4: .4byte 0x03005AEC
_081B79B8: .4byte 0x00003214
_081B79BC:
	ldr r1, _081B79EC
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r4, [r0]
_081B79C4:
	ldrb r1, [r4]
	movs r5, #0x3f
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _081B79E6
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _081B79E6
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _081B79E6
	ldrb r3, [r4, #3]
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _081B79F0
_081B79E6:
	movs r0, #0
	b _081B7AEA
	.align 2, 0
_081B79EC: .4byte 0x082EEF14
_081B79F0:
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081B79FE
	movs r0, #0xa
	b _081B7AEA
_081B79FE:
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _081B7A0A
	movs r0, #1
	b _081B7AEA
_081B7A0A:
	adds r2, r5, #0
	ands r2, r3
	cmp r2, #0
	bne _081B7A18
	lsrs r0, r1, #7
	cmp r0, #0
	beq _081B7A5A
_081B7A18:
	cmp r2, #0x20
	bne _081B7A20
	movs r0, #4
	b _081B7AEA
_081B7A20:
	cmp r2, #0x10
	bne _081B7A28
	movs r0, #3
	b _081B7AEA
_081B7A28:
	cmp r2, #8
	bne _081B7A30
	movs r0, #5
	b _081B7AEA
_081B7A30:
	cmp r2, #4
	bne _081B7A38
	movs r0, #6
	b _081B7AEA
_081B7A38:
	cmp r2, #2
	bne _081B7A40
	movs r0, #7
	b _081B7AEA
_081B7A40:
	cmp r2, #1
	bne _081B7A48
	movs r0, #8
	b _081B7AEA
_081B7A48:
	lsrs r0, r1, #7
	cmp r0, #0
	beq _081B7A56
	cmp r2, #0
	bne _081B7A56
	movs r0, #9
	b _081B7AEA
_081B7A56:
	movs r0, #0xb
	b _081B7AEA
_081B7A5A:
	ldrb r1, [r4, #4]
	movs r0, #0x44
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081B7A6A
	movs r0, #2
	b _081B7AEA
_081B7A6A:
	movs r5, #2
	adds r0, r5, #0
	ands r0, r2
	cmp r0, #0
	beq _081B7A78
	movs r0, #0xc
	b _081B7AEA
_081B7A78:
	movs r3, #1
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _081B7A86
	movs r0, #0xd
	b _081B7AEA
_081B7A86:
	ldrb r1, [r4, #5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081B7A94
	movs r0, #0xe
	b _081B7AEA
_081B7A94:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081B7AA0
	movs r0, #0xf
	b _081B7AEA
_081B7AA0:
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _081B7AAC
	movs r0, #0x10
	b _081B7AEA
_081B7AAC:
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _081B7AB8
	movs r0, #0x11
	b _081B7AEA
_081B7AB8:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081B7AC4
	movs r0, #0x12
	b _081B7AEA
_081B7AC4:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081B7AD0
	movs r0, #0x13
	b _081B7AEA
_081B7AD0:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081B7ADC
	movs r0, #0x14
	b _081B7AEA
_081B7ADC:
	movs r0, #0x18
	ands r0, r2
	cmp r0, #0
	bne _081B7AE8
_081B7AE4:
	movs r0, #0x16
	b _081B7AEA
_081B7AE8:
	movs r0, #0x15
_081B7AEA:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end GetItemEffectType

	thumb_func_start sub_081B7AF0
sub_081B7AF0: @ 0x081B7AF0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _081B7B70
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B7BBC
	ldr r7, _081B7B74
	movs r1, #9
	ldrsb r1, [r7, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B7B78
	adds r5, r1, r0
	movs r0, #0xe
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081B7B7C
	adds r0, r5, #0
	bl GetMonNickname
	ldr r4, _081B7B80
	ldrb r0, [r4]
	bl GetTutorMove
	strh r0, [r7, #0xe]
	ldr r0, _081B7B84
	movs r2, #0xe
	ldrsh r1, [r7, r2]
	lsls r1, r1, #3
	ldr r2, _081B7B88
	adds r1, r1, r2
	bl StringCopy
	movs r0, #2
	mov r1, r8
	strh r0, [r1, #2]
	ldrb r2, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl CanMonLearnTMTutor
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B7B90
	cmp r0, #2
	beq _081B7B98
	ldrh r1, [r7, #0xe]
	adds r0, r5, #0
	bl GiveMoveToMon
	lsls r0, r0, #0x10
	ldr r1, _081B7B8C
	cmp r0, r1
	beq _081B7BA8
	adds r0, r6, #0
	bl sub_081B6B68
	b _081B7BBC
	.align 2, 0
_081B7B70: .4byte 0x02037C74
_081B7B74: .4byte 0x0203CB94
_081B7B78: .4byte 0x02024190
_081B7B7C: .4byte 0x02021C40
_081B7B80: .4byte 0x02037282
_081B7B84: .4byte 0x02021C54
_081B7B88: .4byte 0x082EACC4
_081B7B8C: .4byte 0xFFFF0000
_081B7B90:
	ldr r1, _081B7B94
	b _081B7B9A
	.align 2, 0
_081B7B94: .4byte 0x085C9D7C
_081B7B98:
	ldr r1, _081B7BA4
_081B7B9A:
	adds r0, r6, #0
	bl sub_081B6A50
	b _081B7BBC
	.align 2, 0
_081B7BA4: .4byte 0x085C9E79
_081B7BA8:
	ldr r0, _081B7BC8
	bl sub_081B6A2C
	ldr r1, _081B7BCC
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B7BD0
	str r1, [r0]
_081B7BBC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7BC8: .4byte 0x085C9DA1
_081B7BCC: .4byte 0x03005B60
_081B7BD0: .4byte 0x081B6CA5
	thumb_func_end sub_081B7AF0

	thumb_func_start CB2_PartyMenuFromStartMenu
CB2_PartyMenuFromStartMenu: @ 0x081B7BD4
	push {lr}
	sub sp, #0xc
	movs r0, #0
	str r0, [sp]
	ldr r0, _081B7BF8
	str r0, [sp, #4]
	ldr r0, _081B7BFC
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B7BF8: .4byte 0x081B1041
_081B7BFC: .4byte 0x08085AFD
	thumb_func_end CB2_PartyMenuFromStartMenu

	thumb_func_start sub_081B7C00
sub_081B7C00: @ 0x081B7C00
	push {lr}
	sub sp, #0xc
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	ldr r1, _081B7C38
	cmp r0, #0
	bne _081B7C12
	ldr r1, _081B7C3C
_081B7C12:
	movs r0, #6
	str r0, [sp]
	ldr r0, _081B7C40
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #5
	movs r3, #0
	bl InitPartyMenu
	ldr r1, _081B7C44
	ldr r0, _081B7C48
	ldrh r0, [r0]
	strh r0, [r1, #0xc]
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B7C38: .4byte 0x081C478D
_081B7C3C: .4byte 0x081B5EF5
_081B7C40: .4byte 0x081B1041
_081B7C44: .4byte 0x0203CB94
_081B7C48: .4byte 0x0203CB48
	thumb_func_end sub_081B7C00

	thumb_func_start sub_081B7C4C
sub_081B7C4C: @ 0x081B7C4C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, r4, #0
	ldr r5, _081B7C8C
	ldr r0, _081B7C90
	mov sb, r0
	ldrb r0, [r0, #9]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r7, _081B7C94
	adds r0, r0, r7
	movs r1, #0xc
	bl GetMonData3
	strh r0, [r5]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081B7C98
	adds r0, r4, #0
	bl sub_081B7CE4
	b _081B7CD0
	.align 2, 0
_081B7C8C: .4byte 0x0203CBC8
_081B7C90: .4byte 0x0203CB94
_081B7C94: .4byte 0x02024190
_081B7C98:
	ldrh r0, [r5]
	bl ItemIsMail
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B7CAC
	adds r0, r4, #0
	bl sub_081B8058
	b _081B7CD0
_081B7CAC:
	mov r1, sb
	movs r0, #9
	ldrsb r0, [r1, r0]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r7
	ldrh r1, [r5]
	movs r2, #1
	bl sub_081B19EC
	ldr r1, _081B7CDC
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B7CE0
	str r1, [r0]
_081B7CD0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7CDC: .4byte 0x03005B60
_081B7CE0: .4byte 0x081B7F41
	thumb_func_end sub_081B7C4C

	thumb_func_start sub_081B7CE4
sub_081B7CE4: @ 0x081B7CE4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r5, _081B7D10
	ldrh r0, [r5, #0xc]
	bl ItemIsMail
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B7D1C
	ldrh r0, [r5, #0xc]
	bl sub_081B8090
	ldr r0, _081B7D14
	ldr r1, [r0]
	ldr r0, _081B7D18
	str r0, [r1, #4]
	adds r0, r4, #0
	bl sub_081B0F90
	b _081B7D22
	.align 2, 0
_081B7D10: .4byte 0x0203CB94
_081B7D14: .4byte 0x0203CB90
_081B7D18: .4byte 0x081B7DED
_081B7D1C:
	adds r0, r4, #0
	bl sub_081B7D28
_081B7D22:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_081B7CE4

	thumb_func_start sub_081B7D28
sub_081B7D28: @ 0x081B7D28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _081B7D90
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B7D84
	ldr r4, _081B7D94
	ldrh r5, [r4, #0xc]
	movs r0, #9
	ldrsb r0, [r4, r0]
	movs r1, #0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _081B7D98
	adds r0, r0, r6
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl sub_081B1954
	movs r0, #9
	ldrsb r0, [r4, r0]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	adds r1, r5, #0
	bl sub_081B1A88
	adds r0, r5, #0
	bl sub_081B8090
	ldr r1, _081B7D9C
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B7DA0
	str r1, [r0]
_081B7D84:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7D90: .4byte 0x02037C74
_081B7D94: .4byte 0x0203CB94
_081B7D98: .4byte 0x02024190
_081B7D9C: .4byte 0x03005B60
_081B7DA0: .4byte 0x081B7DA5
	thumb_func_end sub_081B7D28

	thumb_func_start sub_081B7DA4
sub_081B7DA4: @ 0x081B7DA4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B7DE0
	ldrb r4, [r0, #9]
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B7DD8
	lsls r2, r4, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x64
	muls r0, r2, r0
	ldr r1, _081B7DE4
	adds r0, r0, r1
	ldr r1, _081B7DE8
	lsls r2, r2, #4
	ldr r1, [r1]
	adds r1, r1, r2
	bl sub_081B5934
	adds r0, r5, #0
	bl sub_081B0F90
_081B7DD8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B7DE0: .4byte 0x0203CB94
_081B7DE4: .4byte 0x02024190
_081B7DE8: .4byte 0x0203CBA8
	thumb_func_end sub_081B7DA4

	thumb_func_start sub_081B7DEC
sub_081B7DEC: @ 0x081B7DEC
	push {r4, r5, r6, lr}
	ldr r4, _081B7E34
	movs r0, #9
	ldrsb r0, [r4, r0]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _081B7E38
	adds r0, r0, r5
	ldrh r1, [r4, #0xc]
	bl sub_081B1A88
	movs r0, #9
	ldrsb r0, [r4, r0]
	muls r0, r6, r0
	adds r0, r0, r5
	movs r1, #0x40
	bl GetMonData3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _081B7E3C
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r0, _081B7E40
	adds r2, r2, r0
	ldr r1, [r1]
	adds r1, r1, r2
	ldr r2, _081B7E44
	movs r0, #4
	movs r3, #3
	bl DoEasyChatScreen
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B7E34: .4byte 0x0203CB94
_081B7E38: .4byte 0x02024190
_081B7E3C: .4byte 0x03005AEC
_081B7E40: .4byte 0x00002BE0
_081B7E44: .4byte 0x081B7E49
	thumb_func_end sub_081B7DEC

	thumb_func_start sub_081B7E48
sub_081B7E48: @ 0x081B7E48
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r6, _081B7E98
	movs r1, #9
	ldrsb r1, [r6, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B7E9C
	adds r5, r1, r0
	adds r0, r5, #0
	movs r1, #0xc
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, _081B7EA0
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B7EA8
	adds r0, r5, #0
	bl TakeMailFromMon
	ldr r4, _081B7EA4
	adds r0, r5, #0
	movs r1, #0xc
	adds r2, r4, #0
	bl SetMonData
	ldrh r0, [r4]
	movs r1, #1
	bl RemoveBagItem
	adds r0, r7, #0
	bl sub_081B80BC
	ldr r0, [r6]
	bl SetMainCallback2
	b _081B7EC4
	.align 2, 0
_081B7E98: .4byte 0x0203CB94
_081B7E9C: .4byte 0x02024190
_081B7EA0: .4byte 0x02037290
_081B7EA4: .4byte 0x0203CBC8
_081B7EA8:
	ldrb r0, [r6, #8]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldrb r2, [r6, #0xb]
	movs r1, #0x7f
	str r1, [sp]
	ldr r1, _081B7ECC
	str r1, [sp, #4]
	ldr r1, [r6]
	str r1, [sp, #8]
	movs r1, #0xff
	movs r3, #1
	bl InitPartyMenu
_081B7EC4:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B7ECC: .4byte 0x081B7ED1
	thumb_func_end sub_081B7E48

	thumb_func_start sub_081B7ED0
sub_081B7ED0: @ 0x081B7ED0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _081B7EF8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B7F2A
	ldr r1, _081B7EFC
	ldrh r0, [r1]
	cmp r0, #0
	beq _081B7F04
	ldr r0, _081B7F00
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1]
	movs r2, #0
	bl sub_081B1A38
	b _081B7F1C
	.align 2, 0
_081B7EF8: .4byte 0x02037C74
_081B7EFC: .4byte 0x0203CBC8
_081B7F00: .4byte 0x0203CB94
_081B7F04:
	ldr r2, _081B7F30
	movs r1, #9
	ldrsb r1, [r2, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B7F34
	adds r0, r0, r1
	ldrh r1, [r2, #0xc]
	movs r2, #0
	movs r3, #1
	bl sub_081B1954
_081B7F1C:
	ldr r0, _081B7F38
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7F3C
	str r0, [r1]
_081B7F2A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B7F30: .4byte 0x0203CB94
_081B7F34: .4byte 0x02024190
_081B7F38: .4byte 0x03005B60
_081B7F3C: .4byte 0x081B7DA5
	thumb_func_end sub_081B7ED0

	thumb_func_start sub_081B7F40
sub_081B7F40: @ 0x081B7F40
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsPartyMenuTextPrinterActive
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B7F64
	bl sub_081B2FDC
	ldr r0, _081B7F6C
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B7F70
	str r0, [r1]
_081B7F64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B7F6C: .4byte 0x03005B60
_081B7F70: .4byte 0x081B7F75
	thumb_func_end sub_081B7F40

	thumb_func_start sub_081B7F74
sub_081B7F74: @ 0x081B7F74
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	beq _081B7F9A
	cmp r1, #0
	bgt _081B7F94
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081B8034
	b _081B8048
_081B7F94:
	cmp r1, #1
	beq _081B803A
	b _081B8048
_081B7F9A:
	ldr r7, _081B7FCC
	ldrh r4, [r7, #0xc]
	adds r0, r4, #0
	bl sub_081B8090
	ldr r6, _081B7FD0
	ldrh r0, [r6]
	movs r1, #1
	bl AddBagItem
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B7FD8
	adds r0, r4, #0
	bl sub_081B80BC
	ldrh r0, [r6]
	bl pokemon_item_not_removed
	ldr r0, _081B7FD4
	movs r1, #0
	bl DisplayPartyMenuMessage
	b _081B8018
	.align 2, 0
_081B7FCC: .4byte 0x0203CB94
_081B7FD0: .4byte 0x0203CBC8
_081B7FD4: .4byte 0x02021C7C
_081B7FD8:
	adds r0, r4, #0
	bl ItemIsMail
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B7FFC
	ldr r0, _081B7FF4
	ldr r1, [r0]
	ldr r0, _081B7FF8
	str r0, [r1, #4]
	adds r0, r5, #0
	bl sub_081B0F90
	b _081B8048
	.align 2, 0
_081B7FF4: .4byte 0x0203CB90
_081B7FF8: .4byte 0x081B7DED
_081B7FFC:
	movs r1, #9
	ldrsb r1, [r7, r1]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B8028
	adds r0, r0, r1
	adds r1, r4, #0
	bl sub_081B1A88
	ldrh r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl sub_081B1A38
_081B8018:
	ldr r1, _081B802C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B8030
	str r1, [r0]
	b _081B8048
	.align 2, 0
_081B8028: .4byte 0x02024190
_081B802C: .4byte 0x03005B60
_081B8030: .4byte 0x081B7DA5
_081B8034:
	movs r0, #5
	bl PlaySE
_081B803A:
	ldr r0, _081B8050
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B8054
	str r0, [r1]
_081B8048:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8050: .4byte 0x03005B60
_081B8054: .4byte 0x081B7DA5
	thumb_func_end sub_081B7F74

	thumb_func_start sub_081B8058
sub_081B8058: @ 0x081B8058
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _081B8084
	movs r1, #1
	bl DisplayPartyMenuMessage
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r1, _081B8088
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _081B808C
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8084: .4byte 0x085C9C5C
_081B8088: .4byte 0x03005B60
_081B808C: .4byte 0x081B7DA5
	thumb_func_end sub_081B8058

	thumb_func_start sub_081B8090
sub_081B8090: @ 0x081B8090
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _081B80AC
	ldrb r0, [r0, #0xb]
	cmp r0, #6
	bne _081B80B0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl RemovePCItem
	b _081B80B8
	.align 2, 0
_081B80AC: .4byte 0x0203CB94
_081B80B0:
	adds r0, r1, #0
	movs r1, #1
	bl RemoveBagItem
_081B80B8:
	pop {r0}
	bx r0
	thumb_func_end sub_081B8090

	thumb_func_start sub_081B80BC
sub_081B80BC: @ 0x081B80BC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _081B80D4
	ldrb r0, [r0, #0xb]
	cmp r0, #5
	beq _081B80D8
	adds r0, r1, #0
	movs r1, #1
	bl AddPCItem
	b _081B80E0
	.align 2, 0
_081B80D4: .4byte 0x0203CB94
_081B80D8:
	adds r0, r1, #0
	movs r1, #1
	bl AddBagItem
_081B80E0:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	thumb_func_end sub_081B80BC

	thumb_func_start sub_081B80E8
sub_081B80E8: @ 0x081B80E8
	push {lr}
	sub sp, #0xc
	movs r0, #6
	str r0, [sp]
	ldr r0, _081B810C
	str r0, [sp, #4]
	ldr r0, _081B8110
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #7
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B810C: .4byte 0x081B1041
_081B8110: .4byte 0x0816B969
	thumb_func_end sub_081B80E8

	thumb_func_start sub_081B8114
sub_081B8114: @ 0x081B8114
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _081B8160
	movs r1, #9
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _081B8164
	adds r5, r1, r0
	ldr r1, _081B8168
	movs r0, #0
	strb r0, [r1]
	ldr r2, _081B816C
	ldr r0, _081B8170
	ldrh r1, [r0]
	adds r1, #6
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _081B8174
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	adds r0, r5, #0
	movs r1, #0xc
	bl GetMonData3
	cmp r0, #0
	beq _081B817C
	ldr r0, _081B8178
	movs r1, #1
	bl DisplayPartyMenuMessage
	b _081B8192
	.align 2, 0
_081B8160: .4byte 0x0203CB94
_081B8164: .4byte 0x02024190
_081B8168: .4byte 0x0203CBB4
_081B816C: .4byte 0x03005AEC
_081B8170: .4byte 0x0203B984
_081B8174: .4byte 0x00002BE0
_081B8178: .4byte 0x085C9D0C
_081B817C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl GiveMailToMon
	adds r0, r4, #0
	bl ClearMail
	ldr r0, _081B81AC
	movs r1, #1
	bl DisplayPartyMenuMessage
_081B8192:
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	ldr r0, _081B81B0
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B81B4
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B81AC: .4byte 0x085C9D32
_081B81B0: .4byte 0x03005B60
_081B81B4: .4byte 0x081B7DA5
	thumb_func_end sub_081B8114

	thumb_func_start InitChooseHalfPartyForBattle
InitChooseHalfPartyForBattle: @ 0x081B81B8
	push {lr}
	sub sp, #0xc
	bl sub_081B81F8
	movs r0, #0
	str r0, [sp]
	ldr r0, _081B81E8
	str r0, [sp, #4]
	ldr r0, _081B81EC
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	movs r0, #4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	ldr r1, _081B81F0
	ldr r0, _081B81F4
	str r0, [r1, #4]
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B81E8: .4byte 0x081B1041
_081B81EC: .4byte 0x03002360
_081B81F0: .4byte 0x0203CB94
_081B81F4: .4byte 0x081B843D
	thumb_func_end InitChooseHalfPartyForBattle

	thumb_func_start sub_081B81F8
sub_081B81F8: @ 0x081B81F8
	push {lr}
	ldr r0, _081B8208
	movs r1, #0
	movs r2, #4
	bl memset
	pop {r0}
	bx r0
	.align 2, 0
_081B8208: .4byte 0x0203CBC4
	thumb_func_end sub_081B81F8

	thumb_func_start sub_081B820C
sub_081B820C: @ 0x081B820C
	push {r4, lr}
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _081B8228
	adds r0, r0, r1
	bl GetBattleEntryEligibility
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B822C
	movs r0, #2
	b _081B8244
	.align 2, 0
_081B8228: .4byte 0x02024190
_081B822C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_081B8410
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B8242
	movs r0, #0
	b _081B8244
_081B8242:
	movs r0, #1
_081B8244:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081B820C

	thumb_func_start GetBattleEntryEligibility
GetBattleEntryEligibility: @ 0x081B824C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	bne _081B82A8
	adds r0, r5, #0
	movs r1, #0x38
	bl GetMonData3
	adds r4, r0, #0
	bl sub_081B8528
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bhi _081B82A8
	ldr r0, _081B82AC
	ldr r0, [r0]
	ldrh r1, [r0, #4]
	ldr r0, _081B82B0
	cmp r1, r0
	bne _081B828A
	adds r0, r5, #0
	movs r1, #0xc
	bl GetMonData3
	cmp r0, #0
	bne _081B82A8
_081B828A:
	ldr r0, _081B82B4
	bl VarGet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	beq _081B82EA
	cmp r0, #9
	bne _081B82B8
	adds r0, r5, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	bne _081B82EA
_081B82A8:
	movs r0, #0
	b _081B82EC
	.align 2, 0
_081B82AC: .4byte 0x03005AEC
_081B82B0: .4byte 0x0000191A
_081B82B4: .4byte 0x000040CF
_081B82B8:
	adds r0, r5, #0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r3, _081B82F4
	lsls r1, r6, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	ldr r2, _081B82F8
	cmp r0, r2
	beq _081B82EA
_081B82D2:
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r4
	beq _081B82A8
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r6, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, r2
	bne _081B82D2
_081B82EA:
	movs r0, #1
_081B82EC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081B82F4: .4byte 0x085DD48E
_081B82F8: .4byte 0x0000FFFF
	thumb_func_end GetBattleEntryEligibility

	thumb_func_start sub_081B82FC
sub_081B82FC: @ 0x081B82FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl sub_081B84FC
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, r2, #0
	ldr r3, _081B8324
	adds r0, r2, r3
	subs r0, #1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081B833C
	cmp r2, #1
	bne _081B8328
	movs r0, #0xe
	b _081B83F8
	.align 2, 0
_081B8324: .4byte 0x0203CBC4
_081B8328:
	ldr r0, _081B8338
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	movs r0, #0x11
	b _081B83F8
	.align 2, 0
_081B8338: .4byte 0x02021C40
_081B833C:
	ldr r0, _081B8354
	bl VarGet
	lsls r0, r0, #0x18
	movs r1, #0xf8
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _081B8360
	b _081B83F6
	.align 2, 0
_081B8354: .4byte 0x000040CF
_081B8358:
	movs r0, #0x12
	b _081B83F8
_081B835C:
	movs r0, #0x13
	b _081B83F8
_081B8360:
	bl sub_081B84D0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r5, #0
	b _081B83F0
_081B836E:
	ldr r3, _081B8408
	adds r4, r3, r5
	ldrb r0, [r4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r0, #0x64
	ldr r3, _081B840C
	adds r0, r3, r0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldrb r0, [r4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r0, #0x64
	ldr r3, _081B840C
	adds r0, r3, r0
	movs r1, #0xc
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r1, r5, #1
	lsls r0, r1, #0x18
	lsrs r4, r0, #0x18
	mov sb, r1
	cmp r4, r8
	bhs _081B83E8
	movs r7, #0x64
_081B83AE:
	ldr r0, _081B8408
	adds r5, r0, r4
	ldrb r0, [r5]
	muls r0, r7, r0
	subs r0, #0x64
	ldr r1, _081B840C
	adds r0, r1, r0
	movs r1, #0xb
	bl GetMonData3
	cmp sl, r0
	beq _081B8358
	cmp r6, #0
	beq _081B83DE
	ldrb r0, [r5]
	muls r0, r7, r0
	subs r0, #0x64
	ldr r3, _081B840C
	adds r0, r3, r0
	movs r1, #0xc
	bl GetMonData3
	cmp r6, r0
	beq _081B835C
_081B83DE:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r8
	blo _081B83AE
_081B83E8:
	mov r1, sb
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	mov r0, r8
_081B83F0:
	subs r0, #1
	cmp r5, r0
	blt _081B836E
_081B83F6:
	movs r0, #0xff
_081B83F8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B8408: .4byte 0x0203CBC4
_081B840C: .4byte 0x02024190
	thumb_func_end sub_081B82FC

	thumb_func_start sub_081B8410
sub_081B8410: @ 0x081B8410
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #0
	ldr r3, _081B8428
_081B841A:
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, r2
	bne _081B842C
	movs r0, #1
	b _081B8438
	.align 2, 0
_081B8428: .4byte 0x0203CBC4
_081B842C:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _081B841A
	movs r0, #0
_081B8438:
	pop {r1}
	bx r1
	thumb_func_end sub_081B8410

	thumb_func_start sub_081B843C
sub_081B843C: @ 0x081B843C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl sub_081B82FC
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xff
	beq _081B8474
	movs r0, #0x20
	bl PlaySE
	adds r0, r4, #0
	bl DisplayPartyMenuStdMessage
	ldr r0, _081B846C
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B8470
	str r0, [r1]
	b _081B8480
	.align 2, 0
_081B846C: .4byte 0x03005B60
_081B8470: .4byte 0x081B8489
_081B8474:
	movs r0, #5
	bl PlaySE
	adds r0, r5, #0
	bl sub_081B0F90
_081B8480:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B843C

	thumb_func_start sub_081B8488
sub_081B8488: @ 0x081B8488
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _081B84C4
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081B84A2
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B84BC
_081B84A2:
	movs r0, #5
	bl PlaySE
	movs r0, #0
	bl DisplayPartyMenuStdMessage
	ldr r0, _081B84C8
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B84CC
	str r0, [r1]
_081B84BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B84C4: .4byte 0x03002360
_081B84C8: .4byte 0x03005B60
_081B84CC: .4byte 0x081B1041
	thumb_func_end sub_081B8488

	thumb_func_start sub_081B84D0
sub_081B84D0: @ 0x081B84D0
	push {lr}
	ldr r0, _081B84E8
	bl VarGet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	beq _081B84EC
	cmp r0, #9
	bne _081B84F0
	movs r0, #3
	b _081B84F4
	.align 2, 0
_081B84E8: .4byte 0x000040CF
_081B84EC:
	movs r0, #2
	b _081B84F4
_081B84F0:
	ldr r0, _081B84F8
	ldrb r0, [r0]
_081B84F4:
	pop {r1}
	bx r1
	.align 2, 0
_081B84F8: .4byte 0x02037282
	thumb_func_end sub_081B84D0

	thumb_func_start sub_081B84FC
sub_081B84FC: @ 0x081B84FC
	push {lr}
	ldr r0, _081B8514
	bl VarGet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	beq _081B8518
	cmp r0, #9
	bne _081B851C
	movs r0, #1
	b _081B8520
	.align 2, 0
_081B8514: .4byte 0x000040CF
_081B8518:
	movs r0, #2
	b _081B8520
_081B851C:
	ldr r0, _081B8524
	ldrb r0, [r0]
_081B8520:
	pop {r1}
	bx r1
	.align 2, 0
_081B8524: .4byte 0x02037282
	thumb_func_end sub_081B84FC

	thumb_func_start sub_081B8528
sub_081B8528: @ 0x081B8528
	push {lr}
	ldr r0, _081B8540
	bl VarGet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	beq _081B8544
	cmp r0, #9
	bne _081B8548
_081B853C:
	movs r0, #0x64
	b _081B8552
	.align 2, 0
_081B8540: .4byte 0x000040CF
_081B8544:
	movs r0, #0x1e
	b _081B8552
_081B8548:
	ldr r0, _081B8558
	ldrh r0, [r0]
	cmp r0, #0
	bne _081B853C
	movs r0, #0x32
_081B8552:
	pop {r1}
	bx r1
	.align 2, 0
_081B8558: .4byte 0x02037280
	thumb_func_end sub_081B8528

	thumb_func_start sub_081B855C
sub_081B855C: @ 0x081B855C
	push {lr}
	ldr r0, _081B8578
	bl VarGet
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r2, #0xf8
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _081B8580
	ldr r0, _081B857C
	b _081B859A
	.align 2, 0
_081B8578: .4byte 0x000040CF
_081B857C: .4byte 0x085CA21C
_081B8580:
	cmp r1, #1
	bne _081B8598
	ldr r0, _081B8590
	ldrh r0, [r0]
	cmp r0, #2
	bne _081B8598
	ldr r0, _081B8594
	b _081B859A
	.align 2, 0
_081B8590: .4byte 0x02037282
_081B8594: .4byte 0x085CA229
_081B8598:
	ldr r0, _081B85A0
_081B859A:
	pop {r1}
	bx r1
	.align 2, 0
_081B85A0: .4byte 0x085CA238
	thumb_func_end sub_081B855C

	thumb_func_start sub_081B85A4
sub_081B85A4: @ 0x081B85A4
	push {lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0
	str r2, [sp]
	ldr r2, _081B85C8
	str r2, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B85C8: .4byte 0x081B1041
	thumb_func_end sub_081B85A4

	thumb_func_start sub_081B85CC
sub_081B85CC: @ 0x081B85CC
	push {lr}
	sub sp, #0xc
	movs r0, #4
	str r0, [sp]
	ldr r0, _081B85F0
	str r0, [sp, #4]
	ldr r0, _081B85F4
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0xc
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B85F0: .4byte 0x081B1041
_081B85F4: .4byte 0x08085B35
	thumb_func_end sub_081B85CC

	thumb_func_start sub_081B85F8
sub_081B85F8: @ 0x081B85F8
	push {lr}
	sub sp, #0xc
	movs r0, #1
	str r0, [sp]
	ldr r0, _081B861C
	str r0, [sp, #4]
	ldr r0, _081B8620
	str r0, [sp, #8]
	movs r0, #0xb
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B861C: .4byte 0x081B1041
_081B8620: .4byte 0x08085B35
	thumb_func_end sub_081B85F8

	thumb_func_start sub_081B8624
sub_081B8624: @ 0x081B8624
	push {lr}
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B8634
	movs r0, #0
	b _081B8646
_081B8634:
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _081B8644
	movs r0, #1
	b _081B8646
_081B8644:
	movs r0, #2
_081B8646:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081B8624

	thumb_func_start OpenPartyMenuInBattle
OpenPartyMenuInBattle: @ 0x081B864C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_081B8624
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0
	str r0, [sp]
	ldr r0, _081B8688
	str r0, [sp, #4]
	ldr r0, _081B868C
	str r0, [sp, #8]
	movs r0, #1
	adds r2, r4, #0
	movs r3, #0
	bl InitPartyMenu
	bl nullsub_35
	bl pokemon_change_order
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8688: .4byte 0x081B1041
_081B868C: .4byte 0x0805995D
	thumb_func_end OpenPartyMenuInBattle

	thumb_func_start sub_081B8690
sub_081B8690: @ 0x081B8690
	push {lr}
	sub sp, #0xc
	bl sub_081B8624
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #5
	str r0, [sp]
	ldr r0, _081B86C4
	str r0, [sp, #4]
	ldr r0, _081B86C8
	str r0, [sp, #8]
	movs r0, #1
	movs r2, #3
	movs r3, #0
	bl InitPartyMenu
	bl nullsub_35
	bl pokemon_change_order
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B86C4: .4byte 0x081B1041
_081B86C8: .4byte 0x081B5EF5
	thumb_func_end sub_081B8690

	thumb_func_start sub_081B86CC
sub_081B86CC: @ 0x081B86CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081B86F4
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B8714
	adds r0, r4, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	bne _081B8714
	ldr r0, _081B86F8
	ldrb r0, [r0, #0xb]
	cmp r0, #1
	bne _081B86FC
	movs r0, #3
	b _081B8716
	.align 2, 0
_081B86F4: .4byte 0x020241F4
_081B86F8: .4byte 0x0203CB94
_081B86FC:
	ldr r0, _081B8710
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	bne _081B8714
	movs r0, #2
	b _081B8716
	.align 2, 0
_081B8710: .4byte 0x02022C90
_081B8714:
	movs r0, #7
_081B8716:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081B86CC

	thumb_func_start sub_081B871C
sub_081B871C: @ 0x081B871C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl GetCursorSelectionMonId
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B8764
	cmp r5, #1
	beq _081B8742
	cmp r5, #4
	beq _081B8742
	cmp r5, #5
	bne _081B8764
_081B8742:
	ldr r4, _081B8758
	bl GetTrainerPartnerName
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldr r0, _081B875C
	ldr r1, _081B8760
	b _081B88E2
	.align 2, 0
_081B8758: .4byte 0x02021C40
_081B875C: .4byte 0x02021C7C
_081B8760: .4byte 0x085C9B76
_081B8764:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _081B8788
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	bne _081B8798
	ldr r1, _081B878C
	adds r0, r4, #0
	bl GetMonNickname
	ldr r0, _081B8790
	ldr r1, _081B8794
	b _081B88E2
	.align 2, 0
_081B8788: .4byte 0x02024190
_081B878C: .4byte 0x02021C40
_081B8790: .4byte 0x02021C7C
_081B8794: .4byte 0x085C9B59
_081B8798:
	movs r4, #0
	b _081B87C4
_081B879C:
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B87BE
	adds r0, r5, #0
	bl sub_081B8BD8
	lsls r0, r0, #0x18
	ldr r2, _081B87EC
	lsls r1, r4, #1
	adds r1, r1, r2
	lsrs r0, r0, #0x18
	ldrh r1, [r1]
	cmp r0, r1
	beq _081B889C
_081B87BE:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_081B87C4:
	ldr r0, _081B87F0
	ldrb r0, [r0]
	cmp r4, r0
	blo _081B879C
	movs r7, #0x64
	adds r0, r5, #0
	muls r0, r7, r0
	ldr r1, _081B87F4
	mov r8, r1
	adds r6, r0, r1
	adds r0, r6, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	beq _081B8800
	ldr r0, _081B87F8
	ldr r1, _081B87FC
	b _081B88E2
	.align 2, 0
_081B87EC: .4byte 0x02023D12
_081B87F0: .4byte 0x02023D10
_081B87F4: .4byte 0x02024190
_081B87F8: .4byte 0x02021C7C
_081B87FC: .4byte 0x085C9B9D
_081B8800:
	adds r0, r5, #0
	bl sub_081B8BD8
	ldr r1, _081B8824
	ldr r1, [r1]
	adds r1, #0x8b
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _081B8834
	ldr r1, _081B8828
	adds r0, r6, #0
	bl GetMonNickname
	ldr r0, _081B882C
	ldr r1, _081B8830
	b _081B88E2
	.align 2, 0
_081B8824: .4byte 0x02024140
_081B8828: .4byte 0x02021C40
_081B882C: .4byte 0x02021C7C
_081B8830: .4byte 0x085C9B43
_081B8834:
	ldr r0, _081B8844
	ldrb r0, [r0, #0xb]
	cmp r0, #4
	bne _081B8848
	bl SetMonPreventsSwitchingString
	b _081B88E6
	.align 2, 0
_081B8844: .4byte 0x0203CB94
_081B8848:
	cmp r0, #2
	beq _081B88C0
	adds r0, r5, #0
	bl sub_081B8BD8
	ldr r1, _081B888C
	strb r0, [r1]
	ldr r1, _081B8890
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081B8894
	ldr r0, _081B8898
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_081B8C50
	adds r0, r4, #0
	muls r0, r7, r0
	add r0, r8
	adds r1, r6, #0
	bl sub_081B0F58
	movs r0, #1
	b _081B88E8
	.align 2, 0
_081B888C: .4byte 0x0203CBB5
_081B8890: .4byte 0x0203CBB4
_081B8894: .4byte 0x02023D12
_081B8898: .4byte 0x0202415C
_081B889C:
	movs r0, #0x64
	muls r0, r5, r0
	ldr r1, _081B88B0
	adds r0, r0, r1
	ldr r1, _081B88B4
	bl GetMonNickname
	ldr r0, _081B88B8
	ldr r1, _081B88BC
	b _081B88E2
	.align 2, 0
_081B88B0: .4byte 0x02024190
_081B88B4: .4byte 0x02021C40
_081B88B8: .4byte 0x02021C7C
_081B88BC: .4byte 0x085C9B2D
_081B88C0:
	ldr r0, _081B88F4
	ldrb r0, [r0]
	ldr r1, _081B88F8
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r7, r0
	add r0, r8
	ldr r1, _081B88FC
	bl GetMonNickname
	ldr r0, _081B8900
	ldr r1, _081B8904
_081B88E2:
	bl StringExpandPlaceholders
_081B88E6:
	movs r0, #0
_081B88E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081B88F4: .4byte 0x0202415C
_081B88F8: .4byte 0x02023D12
_081B88FC: .4byte 0x02021C40
_081B8900: .4byte 0x02021C7C
_081B8904: .4byte 0x085C9B1A
	thumb_func_end sub_081B871C

	thumb_func_start sub_081B8908
sub_081B8908: @ 0x081B8908
	push {r4, lr}
	ldr r4, _081B8924
	bl sub_0806D288
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_081B8928
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8924: .4byte 0x0203CBCC
	thumb_func_end sub_081B8908

	thumb_func_start sub_081B8928
sub_081B8928: @ 0x081B8928
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B895E
	cmp r4, #0
	beq _081B8950
	movs r0, #0x30
	strb r0, [r6]
	movs r0, #0x45
	strb r0, [r6, #1]
	movs r0, #0x12
	strb r0, [r6, #2]
	b _081B89F8
_081B8950:
	movs r0, #3
	strb r0, [r6]
	movs r0, #0x12
	strb r0, [r6, #1]
	movs r0, #0x45
	strb r0, [r6, #2]
	b _081B89F8
_081B895E:
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B899C
	movs r5, #1
	movs r0, #0
	bl GetBattlerAtPosition
	mov r2, sp
	ldr r1, _081B8998
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	movs r4, #0
	mov r1, sp
_081B8982:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8990
	mov r2, sp
	adds r0, r2, r5
	strb r4, [r0]
	adds r5, #1
_081B8990:
	adds r4, #1
	cmp r4, #5
	ble _081B8982
	b _081B89E0
	.align 2, 0
_081B8998: .4byte 0x02023D12
_081B899C:
	movs r5, #2
	movs r0, #0
	bl GetBattlerAtPosition
	mov r1, sp
	ldr r4, _081B8A00
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r1]
	movs r0, #2
	bl GetBattlerAtPosition
	mov r1, sp
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r0, [r0]
	strb r0, [r1, #1]
	movs r4, #0
_081B89C6:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B89DA
	ldrb r0, [r1, #1]
	cmp r4, r0
	beq _081B89DA
	mov r2, sp
	adds r0, r2, r5
	strb r4, [r0]
	adds r5, #1
_081B89DA:
	adds r4, #1
	cmp r4, #5
	ble _081B89C6
_081B89E0:
	movs r4, #0
	mov r3, sp
_081B89E4:
	adds r0, r6, r4
	ldrb r1, [r3]
	lsls r1, r1, #4
	ldrb r2, [r3, #1]
	orrs r1, r2
	strb r1, [r0]
	adds r3, #2
	adds r4, #1
	cmp r4, #2
	ble _081B89E4
_081B89F8:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8A00: .4byte 0x02023D12
	thumb_func_end sub_081B8928

	thumb_func_start sub_081B8A04
sub_081B8A04: @ 0x081B8A04
	push {lr}
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _081B8A24
	lsls r3, r2, #1
	adds r3, r3, r2
	adds r3, #0x60
	ldr r0, [r0]
	adds r0, r0, r3
	bl sub_081B8A28
	pop {r0}
	bx r0
	.align 2, 0
_081B8A24: .4byte 0x02024140
	thumb_func_end sub_081B8A04

	thumb_func_start sub_081B8A28
sub_081B8A28: @ 0x081B8A28
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r0, r2, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B8A50
	movs r0, #0
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #2
	b _081B8A5C
_081B8A50:
	movs r0, #1
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #3
_081B8A5C:
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl IsMultiBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _081B8A90
	cmp r7, #0
	beq _081B8A82
	movs r0, #0x30
	strb r0, [r5]
	movs r0, #0x45
	strb r0, [r5, #1]
	movs r0, #0x12
	strb r0, [r5, #2]
	b _081B8B12
_081B8A82:
	movs r0, #3
	strb r0, [r5]
	movs r0, #0x12
	strb r0, [r5, #1]
	movs r0, #0x45
	strb r0, [r5, #2]
	b _081B8B12
_081B8A90:
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B8AC8
	movs r3, #1
	mov r2, sp
	ldr r1, _081B8AC4
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r2]
	movs r4, #0
	mov r1, sp
_081B8AAC:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8ABA
	mov r2, sp
	adds r0, r2, r3
	strb r4, [r0]
	adds r3, #1
_081B8ABA:
	adds r4, #1
	cmp r4, #5
	ble _081B8AAC
	b _081B8AFA
	.align 2, 0
_081B8AC4: .4byte 0x02023D12
_081B8AC8:
	movs r3, #2
	mov r1, sp
	ldr r2, _081B8B1C
	lsls r0, r4, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	lsls r0, r6, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1, #1]
	movs r4, #0
_081B8AE0:
	ldrb r0, [r1]
	cmp r4, r0
	beq _081B8AF4
	ldrb r0, [r1, #1]
	cmp r4, r0
	beq _081B8AF4
	mov r2, sp
	adds r0, r2, r3
	strb r4, [r0]
	adds r3, #1
_081B8AF4:
	adds r4, #1
	cmp r4, #5
	ble _081B8AE0
_081B8AFA:
	movs r4, #0
	mov r3, sp
_081B8AFE:
	adds r0, r5, r4
	ldrb r1, [r3]
	lsls r1, r1, #4
	ldrb r2, [r3, #1]
	orrs r1, r2
	strb r1, [r0]
	adds r3, #2
	adds r4, #1
	cmp r4, #2
	ble _081B8AFE
_081B8B12:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8B1C: .4byte 0x02023D12
	thumb_func_end sub_081B8A28

	thumb_func_start sub_081B8B20
sub_081B8B20: @ 0x081B8B20
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r7, #0
	bl IsMultiBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B8BCE
	ldr r0, _081B8B84
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r1, #0x60
	ldr r0, [r0]
	adds r4, r0, r1
	movs r2, #0
	add r6, sp
	mov ip, r6
	movs r6, #0xf
	mov r3, sp
_081B8B52:
	adds r1, r4, r2
	ldrb r0, [r1]
	lsrs r0, r0, #4
	strb r0, [r3]
	adds r3, #1
	ldrb r1, [r1]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r3]
	adds r3, #1
	adds r2, #1
	cmp r2, #2
	ble _081B8B52
	mov r0, ip
	ldrb r3, [r0]
	movs r2, #0
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, r5
	bne _081B8B88
	mov r0, sp
	ldrb r7, [r0]
	strb r3, [r0]
	b _081B8B9C
	.align 2, 0
_081B8B84: .4byte 0x02024140
_081B8B88:
	adds r2, #1
	cmp r2, #5
	bgt _081B8B9C
	mov r0, sp
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, r5
	bne _081B8B88
	adds r7, r0, #0
	strb r3, [r1]
_081B8B9C:
	cmp r2, #6
	beq _081B8BCE
	mov r0, ip
	strb r7, [r0]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #4
	mov r1, sp
	ldrb r1, [r1, #1]
	orrs r0, r1
	strb r0, [r4]
	mov r0, sp
	ldrb r0, [r0, #2]
	lsls r0, r0, #4
	mov r1, sp
	ldrb r1, [r1, #3]
	orrs r0, r1
	strb r0, [r4, #1]
	mov r0, sp
	ldrb r0, [r0, #4]
	lsls r0, r0, #4
	mov r1, sp
	ldrb r1, [r1, #5]
	orrs r0, r1
	strb r0, [r4, #2]
_081B8BCE:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B8B20

	thumb_func_start sub_081B8BD8
sub_081B8BD8: @ 0x081B8BD8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #1
	ands r1, r2
	lsrs r2, r0, #0x19
	cmp r1, #0
	beq _081B8BF8
	ldr r0, _081B8BF4
	adds r0, r2, r0
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	b _081B8C00
	.align 2, 0
_081B8BF4: .4byte 0x0203CBCC
_081B8BF8:
	ldr r0, _081B8C08
	adds r0, r2, r0
	ldrb r0, [r0]
	lsrs r1, r0, #4
_081B8C00:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_081B8C08: .4byte 0x0203CBCC
	thumb_func_end sub_081B8BD8

	thumb_func_start sub_081B8C0C
sub_081B8C0C: @ 0x081B8C0C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r1, #1
	ands r1, r3
	lsrs r3, r0, #0x19
	cmp r1, #0
	beq _081B8C34
	ldr r0, _081B8C30
	adds r0, r3, r0
	ldrb r2, [r0]
	movs r1, #0xf0
	ands r1, r2
	orrs r1, r4
	strb r1, [r0]
	b _081B8C44
	.align 2, 0
_081B8C30: .4byte 0x0203CBCC
_081B8C34:
	ldr r2, _081B8C4C
	adds r2, r3, r2
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	lsls r1, r4, #4
	orrs r0, r1
	strb r0, [r2]
_081B8C44:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8C4C: .4byte 0x0203CBCC
	thumb_func_end sub_081B8C0C

	thumb_func_start sub_081B8C50
sub_081B8C50: @ 0x081B8C50
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	adds r0, r5, #0
	bl sub_081B8BD8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r6, #0
	bl sub_081B8BD8
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl sub_081B8C0C
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_081B8C0C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081B8C50

	thumb_func_start pokemon_order_func
pokemon_order_func: @ 0x081B8C8C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r3, #0
	movs r2, #0
	ldr r5, _081B8CB4
_081B8C98:
	adds r0, r3, r5
	ldrb r1, [r0]
	lsrs r0, r1, #4
	cmp r0, r4
	beq _081B8CB0
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0xf
	ands r0, r1
	cmp r0, r4
	bne _081B8CB8
_081B8CB0:
	adds r0, r2, #0
	b _081B8CCA
	.align 2, 0
_081B8CB4: .4byte 0x0203CBCC
_081B8CB8:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #2
	bls _081B8C98
	movs r0, #0
_081B8CCA:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end pokemon_order_func

	thumb_func_start pokemon_change_order
pokemon_change_order: @ 0x081B8CD0
	push {r4, r5, r6, lr}
	movs r4, #0x96
	lsls r4, r4, #2
	adds r0, r4, #0
	bl Alloc
	adds r5, r0, #0
	ldr r1, _081B8D1C
	adds r2, r4, #0
	bl memcpy
	movs r4, #0
	movs r6, #0x64
_081B8CEA:
	adds r0, r4, #0
	bl pokemon_order_func
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r6, r0
	ldr r1, _081B8D1C
	adds r0, r0, r1
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	movs r2, #0x64
	bl memcpy
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _081B8CEA
	adds r0, r5, #0
	bl Free
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8D1C: .4byte 0x02024190
	thumb_func_end pokemon_change_order

	thumb_func_start sub_081B8D20
sub_081B8D20: @ 0x081B8D20
	push {r4, r5, r6, lr}
	movs r4, #0x96
	lsls r4, r4, #2
	adds r0, r4, #0
	bl Alloc
	adds r5, r0, #0
	ldr r1, _081B8D6C
	adds r2, r4, #0
	bl memcpy
	movs r4, #0
	movs r6, #0x64
_081B8D3A:
	adds r0, r4, #0
	bl sub_081B8BD8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r6, r0
	ldr r1, _081B8D6C
	adds r0, r0, r1
	adds r1, r4, #0
	muls r1, r6, r1
	adds r1, r1, r5
	movs r2, #0x64
	bl memcpy
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _081B8D3A
	adds r0, r5, #0
	bl Free
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8D6C: .4byte 0x02024190
	thumb_func_end sub_081B8D20

	thumb_func_start sub_081B8D70
sub_081B8D70: @ 0x081B8D70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #1
	movs r7, #0x64
	ldr r0, _081B8DC8
	mov r8, r0
_081B8D7E:
	adds r0, r6, #0
	bl sub_081B8BD8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r7, r0
	mov r1, r8
	adds r5, r0, r1
	adds r0, r5, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _081B8DCC
	adds r0, r5, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	beq _081B8DCC
	movs r0, #0
	bl sub_081B8BD8
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0
	adds r1, r6, #0
	bl sub_081B8C50
	adds r0, r4, #0
	muls r0, r7, r0
	add r0, r8
	adds r1, r5, #0
	bl sub_081B0F58
	b _081B8DD6
	.align 2, 0
_081B8DC8: .4byte 0x02024190
_081B8DCC:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #5
	bls _081B8D7E
_081B8DD6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_081B8D70

	thumb_func_start sub_081B8DE0
sub_081B8DE0: @ 0x081B8DE0
	push {lr}
	ldr r0, _081B8DEC
	bl SetMainCallback2
	pop {r0}
	bx r0
	.align 2, 0
_081B8DEC: .4byte 0x0805995D
	thumb_func_end sub_081B8DE0

	thumb_func_start sub_081B8DF0
sub_081B8DF0: @ 0x081B8DF0
	push {lr}
	sub sp, #0xc
	movs r0, #0x7f
	str r0, [sp]
	ldr r0, _081B8E14
	str r0, [sp, #4]
	ldr r0, _081B8E18
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	movs r0, #5
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B8E14: .4byte 0x081B8E1D
_081B8E18: .4byte 0x03002360
	thumb_func_end sub_081B8DF0

	thumb_func_start sub_081B8E1C
sub_081B8E1C: @ 0x081B8E1C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _081B8E4C
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #3
	adds r4, r4, r1
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r4, #8]
	bl sub_081B8F34
	movs r1, #0x80
	lsls r1, r1, #9
	movs r0, #2
	movs r2, #0
	bl ChangeBgX
	ldr r0, _081B8E50
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B8E4C: .4byte 0x03005B60
_081B8E50: .4byte 0x081B8E55
	thumb_func_end sub_081B8E1C

	thumb_func_start sub_081B8E54
sub_081B8E54: @ 0x081B8E54
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r6, r5, #2
	adds r0, r6, r5
	lsls r0, r0, #3
	ldr r1, _081B8EC8
	adds r4, r0, r1
	ldr r0, _081B8ECC
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081B8EC0
	ldrh r0, [r4]
	subs r0, #8
	strh r0, [r4]
	adds r0, r5, #0
	bl sub_081B8F34
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _081B8EC0
	movs r4, #3
	ldr r7, _081B8ED0
_081B8E88:
	subs r0, r4, #3
	lsls r0, r0, #5
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _081B8EA4
	ldr r0, _081B8ED4
	ldr r1, [r0]
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrb r0, [r0, #9]
	movs r1, #0
	bl AnimateSelectedPartyIcon
_081B8EA4:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #5
	bls _081B8E88
	movs r0, #0x78
	bl PlaySE
	ldr r0, _081B8ED8
	adds r1, r6, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _081B8EDC
	str r0, [r1]
_081B8EC0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8EC8: .4byte 0x03005B68
_081B8ECC: .4byte 0x02037C74
_081B8ED0: .4byte 0x02022C9C
_081B8ED4: .4byte 0x0203CBA8
_081B8ED8: .4byte 0x03005B60
_081B8EDC: .4byte 0x081B8EE1
	thumb_func_end sub_081B8E54

	thumb_func_start sub_081B8EE0
sub_081B8EE0: @ 0x081B8EE0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _081B8F0C
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	cmp r1, r0
	bne _081B8F06
	adds r0, r2, #0
	bl sub_081B0F90
_081B8F06:
	pop {r0}
	bx r0
	.align 2, 0
_081B8F0C: .4byte 0x03005B68
	thumb_func_end sub_081B8EE0

	thumb_func_start sub_081B8F10
sub_081B8F10: @ 0x081B8F10
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	cmp r1, #0
	blt _081B8F2A
	ldr r1, _081B8F30
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	strh r3, [r0, #0x24]
_081B8F2A:
	pop {r0}
	bx r0
	.align 2, 0
_081B8F30: .4byte 0x020205AC
	thumb_func_end sub_081B8F10

	thumb_func_start sub_081B8F34
sub_081B8F34: @ 0x081B8F34
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _081B8FBC
	adds r5, r1, r0
	movs r6, #3
	ldr r7, _081B8FC0
_081B8F48:
	ldr r0, _081B8FC4
	subs r1, r6, #3
	lsls r1, r1, #5
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081B8FA0
	ldr r0, [r7]
	lsls r4, r6, #4
	adds r0, r4, r0
	ldrb r0, [r0, #9]
	ldrh r1, [r5]
	subs r1, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_081B8F10
	ldr r0, [r7]
	adds r0, r4, r0
	ldrb r0, [r0, #0xa]
	ldrh r1, [r5]
	subs r1, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_081B8F10
	ldr r0, [r7]
	adds r0, r4, r0
	ldrb r0, [r0, #0xb]
	ldrh r1, [r5]
	subs r1, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_081B8F10
	ldr r0, [r7]
	adds r4, r4, r0
	ldrb r0, [r4, #0xc]
	ldrh r1, [r5]
	subs r1, #8
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl sub_081B8F10
_081B8FA0:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #5
	bls _081B8F48
	movs r1, #0x80
	lsls r1, r1, #4
	movs r0, #2
	movs r2, #1
	bl ChangeBgX
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8FBC: .4byte 0x03005B68
_081B8FC0: .4byte 0x0203CBA8
_081B8FC4: .4byte 0x02022C9C
	thumb_func_end sub_081B8F34

	thumb_func_start sub_081B8FC8
sub_081B8FC8: @ 0x081B8FC8
	push {lr}
	sub sp, #0xc
	movs r0, #0xf
	str r0, [sp]
	ldr r0, _081B8FEC
	str r0, [sp, #4]
	ldr r0, _081B8FF0
	str r0, [sp, #8]
	movs r0, #6
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B8FEC: .4byte 0x081B1041
_081B8FF0: .4byte 0x081B9031
	thumb_func_end sub_081B8FC8

	thumb_func_start sub_081B8FF4
sub_081B8FF4: @ 0x081B8FF4
	push {lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _081B9020
	ldr r1, _081B9024
	str r1, [r2]
	movs r1, #0
	str r1, [sp]
	ldr r1, _081B9028
	str r1, [sp, #4]
	ldr r1, _081B902C
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0xb
	movs r3, #0
	bl InitPartyMenu
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081B9020: .4byte 0x03005B10
_081B9024: .4byte 0x081B9069
_081B9028: .4byte 0x081B1041
_081B902C: .4byte 0x08085A31
	thumb_func_end sub_081B8FF4

	thumb_func_start sub_081B9030
sub_081B9030: @ 0x081B9030
	push {r4, lr}
	ldr r4, _081B9058
	bl GetCursorSelectionMonId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4]
	cmp r0, #5
	bls _081B9046
	movs r0, #0xff
	strh r0, [r4]
_081B9046:
	ldr r0, _081B905C
	ldr r1, _081B9060
	str r1, [r0]
	ldr r0, _081B9064
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081B9058: .4byte 0x02037280
_081B905C: .4byte 0x03005B10
_081B9060: .4byte 0x081B9069
_081B9064: .4byte 0x08085A31
	thumb_func_end sub_081B9030

	thumb_func_start hm_add_c3_without_phase_2
hm_add_c3_without_phase_2: @ 0x081B9068
	push {lr}
	bl FadeInFromBlack
	ldr r0, _081B907C
	movs r1, #0xa
	bl CreateTask
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081B907C: .4byte 0x081B9081
	thumb_func_end hm_add_c3_without_phase_2

	thumb_func_start task_hm_without_phase_2
task_hm_without_phase_2: @ 0x081B9080
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsWeatherNotFadingIn
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B909E
	adds r0, r4, #0
	bl DestroyTask
	bl UnlockPlayerFieldControls
	bl ScriptContext_Enable
_081B909E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end task_hm_without_phase_2

	thumb_func_start sub_081B90A4
sub_081B90A4: @ 0x081B90A4
	push {lr}
	bl LockPlayerFieldControls
	movs r0, #1
	movs r1, #0
	bl FadeScreen
	ldr r0, _081B90C0
	movs r1, #0xa
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
_081B90C0: .4byte 0x081B90C5
	thumb_func_end sub_081B90A4

	thumb_func_start sub_081B90C4
sub_081B90C4: @ 0x081B90C4
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B9104
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081B90FC
	bl CleanupOverworldWindowsAndTilemaps
	str r4, [sp]
	ldr r0, _081B9108
	str r0, [sp, #4]
	ldr r0, _081B910C
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r2, #0xb
	movs r3, #0
	bl InitPartyMenu
	adds r0, r5, #0
	bl DestroyTask
_081B90FC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B9104: .4byte 0x02037C74
_081B9108: .4byte 0x081B1041
_081B910C: .4byte 0x081B9111
	thumb_func_end sub_081B90C4

	thumb_func_start sub_081B9110
sub_081B9110: @ 0x081B9110
	push {lr}
	bl GetCursorSelectionMonId
	ldr r2, _081B913C
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _081B9126
	movs r0, #0xff
	strb r0, [r2]
_081B9126:
	ldr r1, _081B9140
	ldrb r0, [r2]
	strh r0, [r1]
	ldr r1, _081B9144
	ldr r0, _081B9148
	str r0, [r1]
	ldr r0, _081B914C
	bl SetMainCallback2
	pop {r0}
	bx r0
	.align 2, 0
_081B913C: .4byte 0x02039BC4
_081B9140: .4byte 0x02037280
_081B9144: .4byte 0x03005B10
_081B9148: .4byte 0x081B9069
_081B914C: .4byte 0x08085A31
	thumb_func_end sub_081B9110

	thumb_func_start sub_081B9150
sub_081B9150: @ 0x081B9150
	push {lr}
	bl LockPlayerFieldControls
	movs r0, #1
	movs r1, #0
	bl FadeScreen
	ldr r0, _081B916C
	movs r1, #0xa
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
_081B916C: .4byte 0x081B9171
	thumb_func_end sub_081B9150

	thumb_func_start sub_081B9170
sub_081B9170: @ 0x081B9170
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B91B0
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081B91A8
	bl CleanupOverworldWindowsAndTilemaps
	str r4, [sp]
	ldr r0, _081B91B4
	str r0, [sp, #4]
	ldr r0, _081B91B8
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #0
	movs r2, #0xb
	movs r3, #0
	bl InitPartyMenu
	adds r0, r5, #0
	bl DestroyTask
_081B91A8:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B91B0: .4byte 0x02037C74
_081B91B4: .4byte 0x081B1041
_081B91B8: .4byte 0x081B9031
	thumb_func_end sub_081B9170

	thumb_func_start sub_081B91BC
sub_081B91BC: @ 0x081B91BC
	push {lr}
	bl LockPlayerFieldControls
	movs r0, #1
	movs r1, #0
	bl FadeScreen
	ldr r0, _081B91D8
	movs r1, #0xa
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
_081B91D8: .4byte 0x081B91DD
	thumb_func_end sub_081B91BC

	thumb_func_start sub_081B91DC
sub_081B91DC: @ 0x081B91DC
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B921C
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081B9214
	bl CleanupOverworldWindowsAndTilemaps
	str r4, [sp]
	ldr r0, _081B9220
	str r0, [sp, #4]
	ldr r0, _081B9224
	str r0, [sp, #8]
	movs r0, #7
	movs r1, #0
	movs r2, #0xb
	movs r3, #0
	bl InitPartyMenu
	adds r0, r5, #0
	bl DestroyTask
_081B9214:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B921C: .4byte 0x02037C74
_081B9220: .4byte 0x081B1041
_081B9224: .4byte 0x081B9229
	thumb_func_end sub_081B91DC

	thumb_func_start sub_081B9228
sub_081B9228: @ 0x081B9228
	push {r4, r5, lr}
	ldr r5, _081B9240
	bl GetCursorSelectionMonId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5]
	cmp r0, #5
	bls _081B9244
	movs r0, #0xff
	strh r0, [r5]
	b _081B925A
	.align 2, 0
_081B9240: .4byte 0x02037280
_081B9244:
	ldr r4, _081B926C
	ldrh r1, [r5]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B9270
	adds r0, r0, r1
	bl GetNumberOfRelearnableMoves
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4]
_081B925A:
	ldr r0, _081B9274
	ldr r1, _081B9278
	str r1, [r0]
	ldr r0, _081B927C
	bl SetMainCallback2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B926C: .4byte 0x02037282
_081B9270: .4byte 0x02024190
_081B9274: .4byte 0x03005B10
_081B9278: .4byte 0x081B9069
_081B927C: .4byte 0x08085A31
	thumb_func_end sub_081B9228

	thumb_func_start sub_081B9280
sub_081B9280: @ 0x081B9280
	push {r4, r5, lr}
	ldr r1, _081B9290
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	adds r5, r1, #0
	b _081B929A
	.align 2, 0
_081B9290: .4byte 0x02037290
_081B9294:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_081B929A:
	cmp r4, #2
	bhi _081B92B4
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _081B92BC
	adds r0, r0, r1
	movs r1, #0xc
	bl GetMonData3
	cmp r0, #0
	beq _081B9294
	movs r0, #1
	strh r0, [r5]
_081B92B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B92BC: .4byte 0x02024190
	thumb_func_end sub_081B9280

	thumb_func_start sub_081B92C0
sub_081B92C0: @ 0x081B92C0
	push {lr}
	bl LockPlayerFieldControls
	movs r0, #1
	movs r1, #0
	bl FadeScreen
	ldr r0, _081B92DC
	movs r1, #0xa
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
_081B92DC: .4byte 0x081B92E1
	thumb_func_end sub_081B92C0

	thumb_func_start sub_081B92E0
sub_081B92E0: @ 0x081B92E0
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _081B9320
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081B9318
	bl CleanupOverworldWindowsAndTilemaps
	str r4, [sp]
	ldr r0, _081B9324
	str r0, [sp, #4]
	ldr r0, _081B9328
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitPartyMenu
	adds r0, r5, #0
	bl DestroyTask
_081B9318:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B9320: .4byte 0x02037C74
_081B9324: .4byte 0x081B1041
_081B9328: .4byte 0x081B9031
	thumb_func_end sub_081B92E0

	thumb_func_start sub_081B932C
sub_081B932C: @ 0x081B932C
	push {lr}
	sub sp, #4
	ldr r1, _081B9358
	ldr r0, _081B935C
	ldrb r2, [r0]
	ldr r0, _081B9360
	ldrb r3, [r0]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, _081B9364
	str r0, [sp]
	movs r0, #3
	bl ShowPokemonSummaryScreen
	ldr r1, _081B9368
	ldr r0, _081B936C
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_081B9358: .4byte 0x02024190
_081B935C: .4byte 0x02037280
_081B9360: .4byte 0x0202418D
_081B9364: .4byte 0x08085A31
_081B9368: .4byte 0x03005B0C
_081B936C: .4byte 0x080AEA65
	thumb_func_end sub_081B932C

	thumb_func_start sub_081B9370
sub_081B9370: @ 0x081B9370
	push {r4, r5, lr}
	ldr r1, _081B93AC
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	adds r5, r1, #0
_081B937C:
	ldr r0, _081B93B0
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B93B4
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xd
	bl GetMonData3
	cmp r0, #0
	beq _081B939A
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_081B939A:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _081B937C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B93AC: .4byte 0x02037290
_081B93B0: .4byte 0x02037280
_081B93B4: .4byte 0x02024190
	thumb_func_end sub_081B9370

	thumb_func_start sub_081B93B8
sub_081B93B8: @ 0x081B93B8
	push {r4, r5, lr}
	ldr r0, _081B93F8
	ldrh r1, [r0]
	movs r0, #0x64
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r0, _081B93FC
	adds r5, r5, r0
	ldr r0, _081B9400
	ldrh r1, [r0]
	adds r1, #0xd
	adds r0, r5, #0
	bl GetMonData3
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, _081B9404
	adds r0, r5, #0
	bl GetMonNickname
	ldr r0, _081B9408
	lsls r4, r4, #3
	ldr r1, _081B940C
	adds r4, r4, r1
	adds r1, r4, #0
	bl StringCopy
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081B93F8: .4byte 0x02037280
_081B93FC: .4byte 0x02024190
_081B9400: .4byte 0x02037282
_081B9404: .4byte 0x02021C40
_081B9408: .4byte 0x02021C54
_081B940C: .4byte 0x082EACC4
	thumb_func_end sub_081B93B8

	thumb_func_start sub_081B9410
sub_081B9410: @ 0x081B9410
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r0, _081B9470
	mov r8, r0
	ldrh r0, [r0]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _081B9474
	adds r0, r0, r5
	ldr r4, _081B9478
	ldrb r2, [r4]
	movs r1, #0
	bl SetMonMoveSlot
	mov r1, r8
	ldrh r0, [r1]
	muls r0, r6, r0
	adds r0, r0, r5
	ldrb r1, [r4]
	bl RemoveMonPPBonus
	ldrh r4, [r4]
	cmp r4, #2
	bhi _081B9464
_081B9442:
	ldr r0, _081B9470
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B9474
	adds r0, r0, r1
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	adds r4, #1
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	bl sub_081B947C
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	cmp r4, #2
	bls _081B9442
_081B9464:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B9470: .4byte 0x02037280
_081B9474: .4byte 0x02024190
_081B9478: .4byte 0x02037282
	thumb_func_end sub_081B9410

	thumb_func_start sub_081B947C
sub_081B947C: @ 0x081B947C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	adds r5, r1, #0
	adds r4, r2, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	adds r0, #0xd
	str r0, [sp, #8]
	mov r0, r8
	ldr r1, [sp, #8]
	bl GetMonData3
	mov r1, sp
	adds r1, #2
	str r1, [sp, #0x14]
	strh r0, [r1]
	adds r3, r4, #0
	adds r3, #0xd
	str r3, [sp, #0xc]
	mov r0, r8
	adds r1, r3, #0
	bl GetMonData3
	mov r1, sp
	strh r0, [r1]
	adds r7, r5, #0
	adds r7, #0x11
	str r7, [sp, #0x10]
	mov r0, r8
	adds r1, r7, #0
	bl GetMonData3
	mov r1, sp
	adds r1, #5
	str r1, [sp, #0x18]
	strb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x11
	str r3, [sp, #0x1c]
	mov r0, r8
	adds r1, r3, #0
	bl GetMonData3
	add r7, sp, #4
	mov sl, r7
	strb r0, [r7]
	mov r0, r8
	movs r1, #0x15
	bl GetMonData3
	mov r6, sp
	adds r6, #6
	strb r0, [r6]
	ldr r1, _081B9578
	adds r0, r5, r1
	ldrb r0, [r0]
	mov sb, r0
	ldrb r0, [r6]
	adds r2, r0, #0
	mov r3, sb
	ands r2, r3
	lsls r5, r5, #1
	asrs r2, r5
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r1, r4, r1
	ldrb r3, [r1]
	adds r1, r0, #0
	ands r1, r3
	lsls r4, r4, #1
	asrs r1, r4
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r7, sb
	bics r0, r7
	strb r0, [r6]
	ldrb r0, [r6]
	bics r0, r3
	strb r0, [r6]
	lsls r2, r4
	lsls r1, r5
	adds r2, r2, r1
	ldrb r0, [r6]
	orrs r0, r2
	strb r0, [r6]
	mov r0, r8
	ldr r1, [sp, #8]
	mov r2, sp
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x14]
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, #0x10]
	mov r2, sl
	bl SetMonData
	mov r0, r8
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	bl SetMonData
	mov r0, r8
	movs r1, #0x15
	adds r2, r6, #0
	bl SetMonData
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B9578: .4byte 0x082FA6AA
	thumb_func_end sub_081B947C

	thumb_func_start sub_081B957C
sub_081B957C: @ 0x081B957C
	push {lr}
	ldr r0, _081B95A0
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B95A4
	adds r0, r0, r1
	movs r1, #0x2d
	bl GetMonData3
	adds r1, r0, #0
	cmp r1, #0
	beq _081B95AC
	ldr r1, _081B95A8
	movs r0, #1
	strh r0, [r1]
	b _081B95B0
	.align 2, 0
_081B95A0: .4byte 0x02037280
_081B95A4: .4byte 0x02024190
_081B95A8: .4byte 0x02037290
_081B95AC:
	ldr r0, _081B95B4
	strh r1, [r0]
_081B95B0:
	pop {r0}
	bx r0
	.align 2, 0
_081B95B4: .4byte 0x02037290
	thumb_func_end sub_081B957C

	thumb_func_start sub_081B95B8
sub_081B95B8: @ 0x081B95B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _081B95E8
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081B95EC
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _081B95F0
	adds r0, r0, r1
	ldr r1, _081B95F4
	ldrh r1, [r1]
	adds r1, #0xd
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0x39
	bne _081B963C
	movs r6, #0
	b _081B9620
	.align 2, 0
_081B95E8: .4byte 0x02037290
_081B95EC: .4byte 0x02037280
_081B95F0: .4byte 0x02024190
_081B95F4: .4byte 0x02037282
_081B95F8:
	ldr r0, _081B9648
	ldrh r0, [r0]
	cmp r6, r0
	beq _081B961E
	movs r4, #0
	movs r0, #0x64
	adds r5, r6, #0
	muls r5, r0, r5
	ldr r7, _081B964C
_081B960A:
	adds r1, r4, #0
	adds r1, #0xd
	adds r0, r5, r7
	bl GetMonData3
	cmp r0, #0x39
	beq _081B963C
	adds r4, #1
	cmp r4, #3
	bls _081B960A
_081B961E:
	adds r6, #1
_081B9620:
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r0
	blo _081B95F8
	mov r0, r8
	bl AnyStorageMonWithMove
	cmp r0, #1
	beq _081B963C
	ldr r1, _081B9650
	movs r0, #1
	strh r0, [r1]
_081B963C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B9648: .4byte 0x02037280
_081B964C: .4byte 0x02024190
_081B9650: .4byte 0x02037290
	thumb_func_end sub_081B95B8

	.globl ShowContestResults
	.set ShowContestResults, sub_081B90A4
