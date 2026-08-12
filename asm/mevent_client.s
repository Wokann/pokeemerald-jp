.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start mainseq_4
mainseq_4: @ 0x0801D44C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x10]
	lsls r2, r0, #3
	ldr r1, [r4, #0x1c]
	adds r2, r1, r2
	adds r0, #1
	str r0, [r4, #0x10]
	ldr r0, [r2]
	cmp r0, #0x15
	bls _0801D464
	b _0801D614
_0801D464:
	lsls r0, r0, #2
	ldr r1, _0801D470
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D470: .4byte 0x0801D474
_0801D474: @ jump table
	.4byte _0801D614 @ case 0
	.4byte _0801D4CC @ case 1
	.4byte _0801D4D4 @ case 2
	.4byte _0801D4E4 @ case 3
	.4byte _0801D51E @ case 4
	.4byte _0801D526 @ case 5
	.4byte _0801D50E @ case 6
	.4byte _0801D518 @ case 7
	.4byte _0801D574 @ case 8
	.4byte _0801D5A0 @ case 9
	.4byte _0801D598 @ case 10
	.4byte _0801D53C @ case 11
	.4byte _0801D552 @ case 12
	.4byte _0801D568 @ case 13
	.4byte _0801D58C @ case 14
	.4byte _0801D5C8 @ case 15
	.4byte _0801D5CC @ case 16
	.4byte _0801D5D4 @ case 17
	.4byte _0801D5E0 @ case 18
	.4byte _0801D4FA @ case 19
	.4byte _0801D4E8 @ case 20
	.4byte _0801D600 @ case 21
_0801D4CC:
	ldr r0, [r2, #4]
	str r0, [r4, #4]
	movs r0, #1
	b _0801D60E
_0801D4D4:
	adds r0, r4, #0
	adds r0, #0x24
	ldr r1, [r2, #4]
	ldr r2, [r4, #0x18]
	bl mevent_srv_sub_init_recv
	movs r0, #2
	b _0801D60E
_0801D4E4:
	movs r0, #3
	b _0801D60E
_0801D4E8:
	adds r0, r4, #0
	adds r0, #0x24
	ldr r2, [r4, #0x14]
	movs r1, #0x14
	movs r3, #0
	bl mevent_srv_sub_init_send
	movs r0, #3
	b _0801D60E
_0801D4FA:
	ldrb r0, [r2, #4]
	bl GetGameStat
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0x12
	bl mevent_client_send_word
	movs r0, #3
	b _0801D60E
_0801D50E:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0801D516
	b _0801D614
_0801D516:
	b _0801D51E
_0801D518:
	ldr r0, [r4, #4]
	cmp r0, #1
	bne _0801D614
_0801D51E:
	adds r0, r4, #0
	bl mevent_client_jmp_buffer
	b _0801D614
_0801D526:
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x18]
	movs r2, #0x40
	bl memcpy
	movs r0, #5
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r4, #0xc]
	movs r0, #2
	b _0801D616
_0801D53C:
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x18]
	movs r2, #0x40
	bl memcpy
	movs r0, #5
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r4, #0xc]
	movs r0, #3
	b _0801D616
_0801D552:
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x18]
	movs r2, #0x40
	bl memcpy
	movs r0, #5
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r4, #0xc]
	movs r0, #5
	b _0801D616
_0801D568:
	movs r0, #5
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r4, #0xc]
	movs r0, #4
	b _0801D616
_0801D574:
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x4c]
	bl MysteryGift_LoadLinkGameData
	adds r0, r4, #0
	adds r0, #0x24
	ldr r2, [r4, #0x14]
	movs r1, #0x11
	movs r3, #0x64
	bl mevent_srv_sub_init_send
	b _0801D614
_0801D58C:
	ldr r2, [r4, #4]
	adds r0, r4, #0
	movs r1, #0x13
	bl mevent_client_send_word
	b _0801D614
_0801D598:
	ldr r0, [r4, #0x18]
	bl SaveWonderCard
	b _0801D614
_0801D5A0:
	ldr r0, [r4, #0x18]
	bl IsWonderNewsSameAsSaved
	cmp r0, #0
	bne _0801D5BC
	ldr r0, [r4, #0x18]
	bl SaveWonderNews
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0
	bl mevent_client_send_word
	b _0801D614
_0801D5BC:
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #1
	bl mevent_client_send_word
	b _0801D614
_0801D5C8:
	movs r0, #6
	b _0801D60E
_0801D5CC:
	ldr r0, [r4, #0x18]
	bl MysteryGift_TrySaveStamp
	b _0801D614
_0801D5D4:
	ldr r0, [r4, #0x18]
	movs r1, #0xfa
	lsls r1, r1, #2
	bl InitRamScript_NoEventObject
	b _0801D614
_0801D5E0:
	ldr r0, _0801D5F8
	ldr r0, [r0]
	ldr r1, _0801D5FC
	adds r0, r0, r1
	ldr r1, [r4, #0x18]
	movs r2, #0xbc
	bl memcpy
	bl ValidateEReaderTrainer
	b _0801D614
	.align 2, 0
_0801D5F8: .4byte 0x03005AF0
_0801D5FC: .4byte 0x00000BEC
_0801D600:
	ldr r0, _0801D61C
	ldr r1, [r4, #0x18]
	movs r2, #0x80
	lsls r2, r2, #3
	bl memcpy
	movs r0, #7
_0801D60E:
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r4, #0xc]
_0801D614:
	movs r0, #1
_0801D616:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801D61C: .4byte 0x0201C000
	thumb_func_end mainseq_4

	thumb_func_start mainseq_5
mainseq_5: @ 0x0801D620
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0xc]
	cmp r0, #0
	beq _0801D632
	movs r0, #4
	str r0, [r1, #8]
	movs r0, #0
	str r0, [r1, #0xc]
_0801D632:
	movs r0, #1
	pop {r1}
	bx r1
	thumb_func_end mainseq_5

	thumb_func_start mainseq_6
mainseq_6: @ 0x0801D638
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0801D648
	cmp r0, #1
	beq _0801D656
	b _0801D668
_0801D648:
	ldr r0, [r4, #0x18]
	bl sub_081537AC
	ldr r0, [r4, #0xc]
	adds r0, #1
	str r0, [r4, #0xc]
	b _0801D668
_0801D656:
	adds r0, r4, #4
	bl sub_081537C0
	adds r1, r0, #0
	cmp r1, #0
	bne _0801D668
	movs r0, #4
	str r0, [r4, #8]
	str r1, [r4, #0xc]
_0801D668:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end mainseq_6

	thumb_func_start mainseq_7
mainseq_7: @ 0x0801D670
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _0801D698
	adds r0, r4, #4
	ldr r1, _0801D69C
	ldr r1, [r1]
	ldr r2, _0801D6A0
	ldr r2, [r2]
	bl _call_via_r3
	cmp r0, #1
	bne _0801D690
	movs r0, #4
	str r0, [r4, #8]
	movs r0, #0
	str r0, [r4, #0xc]
_0801D690:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801D698: .4byte 0x0201C000
_0801D69C: .4byte 0x03005AF0
_0801D6A0: .4byte 0x03005AEC
	thumb_func_end mainseq_7
