.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start ProcessRecvCmds
ProcessRecvCmds: @ 0x0800963C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r6, #0
_0800964A:
	ldr r0, _08009694
	lsls r1, r6, #1
	adds r3, r1, r0
	movs r0, #0
	strh r0, [r3]
	lsls r4, r6, #4
	ldr r5, _08009698
	adds r2, r4, r5
	ldrh r0, [r2]
	mov ip, r1
	adds r7, r6, #1
	str r7, [sp]
	cmp r0, #0
	bne _08009668
	b _08009906
_08009668:
	ldrh r1, [r2]
	ldr r0, _0800969C
	cmp r1, r0
	bne _08009672
	b _080098B8
_08009672:
	cmp r1, r0
	bgt _080096C0
	ldr r0, _080096A0
	cmp r1, r0
	bne _0800967E
	b _080098FC
_0800967E:
	cmp r1, r0
	bgt _080096AC
	ldr r0, _080096A4
	cmp r1, r0
	beq _08009704
	ldr r0, _080096A8
	cmp r1, r0
	bne _08009690
	b _080098C0
_08009690:
	b _08009906
	.align 2, 0
_08009694: .4byte 0x030030C0
_08009698: .4byte 0x03003130
_0800969C: .4byte 0x00005FFF
_080096A0: .4byte 0x00004444
_080096A4: .4byte 0x00002222
_080096A8: .4byte 0x00002FFE
_080096AC:
	ldr r0, _080096BC
	cmp r1, r0
	beq _08009754
	adds r0, #0x11
	cmp r1, r0
	beq _08009754
	b _08009906
	.align 2, 0
_080096BC: .4byte 0x00005555
_080096C0:
	ldr r0, _080096DC
	cmp r1, r0
	beq _08009760
	cmp r1, r0
	bgt _080096E8
	ldr r0, _080096E0
	cmp r1, r0
	beq _0800978C
	ldr r0, _080096E4
	cmp r1, r0
	bne _080096D8
	b _080098D0
_080096D8:
	b _08009906
	.align 2, 0
_080096DC: .4byte 0x0000BBBB
_080096E0: .4byte 0x00008888
_080096E4: .4byte 0x0000AAAA
_080096E8:
	ldr r0, _080096FC
	cmp r1, r0
	bne _080096F0
	b _080098FC
_080096F0:
	ldr r0, _08009700
	cmp r1, r0
	bne _080096F8
	b _080098D6
_080096F8:
	b _08009906
	.align 2, 0
_080096FC: .4byte 0x0000CAFE
_08009700: .4byte 0x0000CCCC
_08009704:
	bl InitLocalLinkPlayer
	ldr r1, _08009748
	adds r1, #0x10
	ldr r0, _0800974C
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r5, r7}
	stm r1!, {r2, r5, r7}
	ldr r0, [r0]
	str r0, [r1]
	ldr r3, _08009750
	ldr r1, _08009748
	adds r0, r3, #0
	ldm r0!, {r4, r5, r7}
	stm r1!, {r4, r5, r7}
	ldrh r2, [r0]
	strh r2, [r1]
	ldrb r0, [r0, #2]
	strb r0, [r1, #2]
	ldr r0, _08009748
	adds r0, #0x2c
	ldm r3!, {r1, r2, r4}
	stm r0!, {r1, r2, r4}
	ldrh r1, [r3]
	strh r1, [r0]
	ldrb r1, [r3, #2]
	strb r1, [r0, #2]
	ldr r0, _08009748
	movs r1, #0x3c
	bl InitBlockSend
	b _08009906
	.align 2, 0
_08009748: .4byte 0x030030D0
_0800974C: .4byte 0x02022684
_08009750: .4byte 0x082BFF24
_08009754:
	ldr r1, _0800975C
	movs r0, #1
	strb r0, [r1]
	b _08009906
	.align 2, 0
_0800975C: .4byte 0x03003188
_08009760:
	mov r5, ip
	adds r1, r5, r6
	lsls r1, r1, #2
	ldr r7, _08009784
	adds r1, r1, r7
	movs r0, #0
	strh r0, [r1]
	ldr r0, _08009788
	adds r0, #2
	adds r0, r4, r0
	ldrh r0, [r0]
	strh r0, [r1, #2]
	ldr r0, _08009788
	adds r0, #4
	adds r0, r4, r0
	ldrh r0, [r0]
	strb r0, [r1, #9]
	b _08009906
	.align 2, 0
_08009784: .4byte 0x03000D20
_08009788: .4byte 0x03003130
_0800978C:
	mov r1, ip
	adds r0, r1, r6
	lsls r0, r0, #2
	ldr r2, _080097D0
	adds r3, r0, r2
	ldrh r1, [r3, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r5, r2, #0
	mov sl, r5
	cmp r1, r0
	bls _080097DC
	ldr r7, _080097D4
	mov r8, r7
	movs r2, #0
	adds r5, r3, #0
	ldr r7, _080097D8
	adds r3, r4, #0
_080097B0:
	ldrh r1, [r5]
	lsrs r1, r1, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	add r1, r8
	adds r2, #1
	lsls r0, r2, #1
	adds r0, r0, r3
	adds r0, r0, r7
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #6
	bls _080097B0
	b _0800980C
	.align 2, 0
_080097D0: .4byte 0x03000D20
_080097D4: .4byte 0x0201C000
_080097D8: .4byte 0x03003130
_080097DC:
	movs r2, #0
	ldr r0, _0800988C
	mov sb, r0
	adds r7, r3, #0
	ldr r1, _08009890
	mov r8, r1
	lsls r5, r6, #8
	adds r3, r4, #0
_080097EC:
	ldrh r1, [r7]
	lsrs r1, r1, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r5
	add r1, sb
	adds r2, #1
	lsls r0, r2, #1
	adds r0, r0, r3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #6
	bls _080097EC
_0800980C:
	mov r2, ip
	adds r1, r2, r6
	lsls r1, r1, #2
	add r1, sl
	ldrh r0, [r1]
	adds r0, #0xe
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1, #2]
	cmp r0, r1
	blo _08009906
	ldr r0, _08009894
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #1
	bne _080098AE
	lsls r1, r6, #8
	ldr r0, _0800988C
	adds r1, r1, r0
	mov r8, r1
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #2
	ldr r1, _08009898
	adds r2, r0, r1
	adds r1, r2, #0
	mov r0, r8
	adds r0, #0x10
	ldm r0!, {r4, r5, r7}
	stm r1!, {r4, r5, r7}
	ldm r0!, {r4, r5, r7}
	stm r1!, {r4, r5, r7}
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08009866
	strb r3, [r2, #0x12]
	strb r3, [r2, #0x11]
	strb r3, [r2, #0x10]
_08009866:
	ldr r5, _0800989C
	mov r0, r8
	adds r1, r5, #0
	bl strcmp
	cmp r0, #0
	bne _08009882
	mov r0, r8
	adds r0, #0x2c
	adds r1, r5, #0
	bl strcmp
	cmp r0, #0
	beq _080098A4
_08009882:
	ldr r0, _080098A0
	bl SetMainCallback2
	b _08009906
	.align 2, 0
_0800988C: .4byte 0x0202207C
_08009890: .4byte 0x03003130
_08009894: .4byte 0x03003118
_08009898: .4byte 0x020226A0
_0800989C: .4byte 0x082BFF24
_080098A0: .4byte 0x0800AA0D
_080098A4:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl HandleReceiveRemoteLinkPlayer
	b _08009906
_080098AE:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl SetBlockReceivedFlag
	b _08009906
_080098B8:
	ldr r0, _080098BC
	b _080098C2
	.align 2, 0
_080098BC: .4byte 0x03003190
_080098C0:
	ldr r0, _080098CC
_080098C2:
	adds r0, r6, r0
	movs r1, #1
	strb r1, [r0]
	b _08009906
	.align 2, 0
_080098CC: .4byte 0x0300318C
_080098D0:
	bl sub_08009FDC
	b _08009906
_080098D6:
	ldr r3, _080098F4
	ldr r0, _080098F8
	adds r0, #2
	adds r0, r4, r0
	ldrh r2, [r0]
	lsls r2, r2, #3
	adds r0, r2, r3
	ldr r1, [r0]
	adds r3, #4
	adds r2, r2, r3
	ldrh r2, [r2]
	movs r0, #0
	bl SendBlock
	b _08009906
	.align 2, 0
_080098F4: .4byte 0x082BFEF8
_080098F8: .4byte 0x03003130
_080098FC:
	ldr r0, _08009924
	adds r0, #2
	adds r0, r4, r0
	ldrh r0, [r0]
	strh r0, [r3]
_08009906:
	ldr r1, [sp]
	lsls r0, r1, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #3
	bhi _08009912
	b _0800964A
_08009912:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08009924: .4byte 0x03003130
	thumb_func_end ProcessRecvCmds


