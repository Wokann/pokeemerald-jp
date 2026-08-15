.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start umul3232H32
umul3232H32: @ 0x0828D5D4
	add r2, pc, #0x0
	bx r2
	thumb_func_end umul3232H32

	arm_func_start __umul3232H32
__umul3232H32: @ 0x0828D5D8
	umull r2, r3, r0, r1
	add r0, r3, #0
	bx lr
	arm_func_end __umul3232H32

	thumb_func_start SoundMain
SoundMain: @ 0x0828D5E4
	ldr r0, _0828D650
	ldr r0, [r0]
	ldr r2, _0828D654
	ldr r3, [r0]
	cmp r2, r3
	beq _0828D5F2
	bx lr
_0828D5F2:
	adds r3, #1
	str r3, [r0]
	push {r4, r5, r6, r7, lr}
	mov r1, r8
	mov r2, sb
	mov r3, sl
	mov r4, fp
	push {r0, r1, r2, r3, r4}
	sub sp, #0x18
	ldrb r1, [r0, #0xc]
	cmp r1, #0
	beq _0828D616
	ldr r2, _0828D65C
	ldrb r2, [r2]
	cmp r2, #0xa0
	bhs _0828D614
	adds r2, #0xe4
_0828D614:
	adds r1, r1, r2
_0828D616:
	str r1, [sp, #0x14]
	ldr r3, [r0, #0x20]
	cmp r3, #0
	beq _0828D626
	ldr r0, [r0, #0x24]
	bl sub_0828DA1E
	ldr r0, [sp, #0x18]
_0828D626:
	ldr r3, [r0, #0x28]
	bl sub_0828DA1E
	ldr r0, [sp, #0x18]
	ldr r3, [r0, #0x10]
	mov r8, r3
	ldr r5, _0828D660
	adds r5, r5, r0
	ldrb r4, [r0, #4]
	subs r7, r4, #1
	bls _0828D646
	ldrb r1, [r0, #0xb]
	subs r1, r1, r7
	mov r2, r8
	muls r2, r1, r2
	adds r5, r5, r2
_0828D646:
	str r5, [sp, #8]
	ldr r6, _0828D664
	ldr r3, _0828D658
	bx r3
	.align 2, 0
_0828D650: .4byte 0x03007FF0
_0828D654: .4byte 0x68736D53
_0828D658: .4byte 0x03001B51
_0828D65C: .4byte 0x04000006
_0828D660: .4byte 0x00000350
_0828D664: .4byte 0x00000630
	thumb_func_end SoundMain

	thumb_func_start SoundMainRAM
SoundMainRAM: @ 0x0828D668
	ldrb r3, [r0, #5]
	cmp r3, #0
	beq _0828D6C8
	add r1, pc, #0x4
	bx r1
	.align 2, 0
	thumb_func_end SoundMainRAM

	arm_func_start SoundMainRAM_Reverb
SoundMainRAM_Reverb: @ 0x0828D674
	cmp r4, #2
	addeq r7, r0, #0x350
	addne r7, r5, r8
	mov r4, r8
_0828D684:
	ldrsb r0, [r5, r6]
	ldrsb r1, [r5]
	add r0, r0, r1
	ldrsb r1, [r7, r6]
	add r0, r0, r1
	ldrsb r1, [r7], #1
	add r0, r0, r1
	mul r1, r0, r3
	asr r0, r1, #9
	tst r0, #0x80
	addne r0, r0, #1
	strb r0, [r5, r6]
	strb r0, [r5], #1
	subs r4, r4, #1
	bgt _0828D684
	add r0, pc, #0x2f
	bx r0
	.thumb
_0828D6C8:
	movs r0, #0
	mov r1, r8
	adds r6, r6, r5
	lsrs r1, r1, #3
	blo _0828D6D6
	stm r5!, {r0}
	stm r6!, {r0}
_0828D6D6:
	lsrs r1, r1, #1
	blo _0828D6E2
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
_0828D6E2:
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	stm r5!, {r0}
	stm r6!, {r0}
	subs r1, #1
	bgt _0828D6E2
	ldr r4, [sp, #0x18]
	ldr r0, [r4, #0x18]
	mov ip, r0
	ldrb r0, [r4, #6]
	adds r4, #0x50
_0828D700:
	str r0, [sp, #4]
	ldr r3, [r4, #0x24]
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _0828D720
	ldr r1, _0828D71C
	ldrb r1, [r1]
	cmp r1, #0xa0
	bhs _0828D714
	adds r1, #0xe4
_0828D714:
	cmp r1, r0
	blo _0828D720
	b _0828DA0A
	.align 2, 0
_0828D71C: .4byte 0x04000006
_0828D720:
	ldrb r6, [r4]
	movs r0, #0xc7
	tst r0, r6
	bne _0828D72A
	b _0828DA00
_0828D72A:
	movs r0, #0x80
	tst r0, r6
	beq _0828D760
	movs r0, #0x40
	tst r0, r6
	bne _0828D770
	movs r6, #3
	strb r6, [r4]
	adds r0, r3, #0
	adds r0, #0x10
	ldr r1, [r4, #0x18]
	adds r0, r0, r1
	str r0, [r4, #0x28]
	ldr r0, [r3, #0xc]
	subs r0, r0, r1
	str r0, [r4, #0x18]
	movs r5, #0
	strb r5, [r4, #9]
	str r5, [r4, #0x1c]
	ldrb r2, [r3, #3]
	movs r0, #0xc0
	tst r0, r2
	beq _0828D7B8
	movs r0, #0x10
	orrs r6, r0
	strb r6, [r4]
	b _0828D7B8
_0828D760:
	ldrb r5, [r4, #9]
	movs r0, #4
	tst r0, r6
	beq _0828D776
	ldrb r0, [r4, #0xd]
	subs r0, #1
	strb r0, [r4, #0xd]
	bhi _0828D7C6
_0828D770:
	movs r0, #0
	strb r0, [r4]
	b _0828DA00
_0828D776:
	movs r0, #0x40
	tst r0, r6
	beq _0828D796
	ldrb r0, [r4, #7]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #0xc]
	cmp r5, r0
	bhi _0828D7C6
_0828D788:
	ldrb r5, [r4, #0xc]
	cmp r5, #0
	beq _0828D770
	movs r0, #4
	orrs r6, r0
	strb r6, [r4]
	b _0828D7C6
_0828D796:
	movs r2, #3
	ands r2, r6
	cmp r2, #2
	bne _0828D7B4
	ldrb r0, [r4, #5]
	muls r5, r0, r5
	lsrs r5, r5, #8
	ldrb r0, [r4, #6]
	cmp r5, r0
	bhi _0828D7C6
	adds r5, r0, #0
	beq _0828D788
	subs r6, #1
	strb r6, [r4]
	b _0828D7C6
_0828D7B4:
	cmp r2, #3
	bne _0828D7C6
_0828D7B8:
	ldrb r0, [r4, #4]
	adds r5, r5, r0
	cmp r5, #0xff
	blo _0828D7C6
	movs r5, #0xff
	subs r6, #1
	strb r6, [r4]
_0828D7C6:
	strb r5, [r4, #9]
	ldr r0, [sp, #0x18]
	ldrb r0, [r0, #7]
	adds r0, #1
	muls r0, r5, r0
	lsrs r5, r0, #4
	ldrb r0, [r4, #2]
	muls r0, r5, r0
	lsrs r0, r0, #8
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #3]
	muls r0, r5, r0
	lsrs r0, r0, #8
	strb r0, [r4, #0xb]
	movs r0, #0x10
	ands r0, r6
	str r0, [sp, #0x10]
	beq _0828D7FA
	adds r0, r3, #0
	adds r0, #0x10
	ldr r1, [r3, #8]
	adds r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r3, #0xc]
	subs r0, r0, r1
	str r0, [sp, #0x10]
_0828D7FA:
	ldr r5, [sp, #8]
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x28]
	add r0, pc, #0x0
	bx r0
	arm_func_end SoundMainRAM_Reverb

	arm_func_start sub_0828D804
sub_0828D804: @ 0x0828D804
	str r8, [sp]
	ldr sb, [r4, #0x1c]
	ldrb sl, [r4, #0xa]
	ldrb fp, [r4, #0xb]
	ldrb r0, [r4, #1]
	tst r0, #0x30
	beq _0828D828
	bl sub_0828DA24
	b _0828D9E8
_0828D828:
	lsl sl, sl, #0x10
	lsl fp, fp, #0x10
	ldrb r0, [r4, #1]
	tst r0, #8
	beq _0828D95C
_0828D83C:
	cmp r2, #4
	ble _0828D8AC
	subs r2, r2, r8
	movgt sb, #0
	bgt _0828D868
	mov sb, r8
	add r2, r2, r8
	sub r8, r2, #4
	sub sb, sb, r8
	ands r2, r2, #3
	moveq r2, #4
_0828D868:
	ldr r6, [r5]
	ldr r7, [r5, #0x630]
_0828D870:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	mul r1, fp, r0
	bic r1, r1, #0xff0000
	add r7, r1, r7, ror #8
	adds r5, r5, #0x40000000
	blo _0828D870
	str r7, [r5, #0x630]
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _0828D868
	adds r8, r8, sb
	beq _0828D9EC
_0828D8AC:
	ldr r6, [r5]
	ldr r7, [r5, #0x630]
_0828D8B4:
	ldrsb r0, [r3], #1
	mul r1, sl, r0
	bic r1, r1, #0xff0000
	add r6, r1, r6, ror #8
	mul r1, fp, r0
	bic r1, r1, #0xff0000
	add r7, r1, r7, ror #8
	subs r2, r2, #1
	beq _0828D924
_0828D8D8:
	adds r5, r5, #0x40000000
	blo _0828D8B4
	str r7, [r5, #0x630]
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _0828D83C
	b _0828D9EC
_0828D8F4:
	ldr r0, [sp, #0x18]
	cmp r0, #0
	beq _0828D918
	ldr r3, [sp, #0x14]
	rsb lr, r2, #0
_0828D908:
	adds r2, r0, r2
	bgt _0828D9BC
	sub lr, lr, r0
	b _0828D908
_0828D918:
	pop {r4, ip}
	mov r2, #0
	b _0828D934
_0828D924:
	ldr r2, [sp, #0x10]
	cmp r2, #0
	ldrne r3, [sp, #0xc]
	bne _0828D8D8
_0828D934:
	strb r2, [r4]
	lsr r0, r5, #0x1e
	bic r5, r5, #0xc0000000
	rsb r0, r0, #3
	lsl r0, r0, #3
	ror r6, r6, r0
	ror r7, r7, r0
	str r7, [r5, #0x630]
	str r6, [r5], #4
	b _0828D9F4
_0828D95C:
	push {r4, ip}
	ldr r1, [r4, #0x20]
	mul r4, ip, r1
	ldrsb r0, [r3]
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
_0828D974:
	ldr r6, [r5]
	ldr r7, [r5, #0x630]
_0828D97C:
	mul lr, sb, r1
	add lr, r0, lr, asr #23
	mul ip, sl, lr
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	mul ip, fp, lr
	bic ip, ip, #0xff0000
	add r7, ip, r7, ror #8
	add sb, sb, r4
	lsrs lr, sb, #0x17
	beq _0828D9C8
	bic sb, sb, #0x3f800000
	subs r2, r2, lr
	ble _0828D8F4
	subs lr, lr, #1
	addeq r0, r0, r1
_0828D9BC:
	ldrsbne r0, [r3, lr]!
	ldrsb r1, [r3, #1]!
	sub r1, r1, r0
_0828D9C8:
	adds r5, r5, #0x40000000
	blo _0828D97C
	str r7, [r5, #0x630]
	str r6, [r5], #4
	subs r8, r8, #4
	bgt _0828D974
	sub r3, r3, #1
	pop {r4, ip}
_0828D9E8:
	str sb, [r4, #0x1c]
_0828D9EC:
	str r2, [r4, #0x18]
	str r3, [r4, #0x28]
_0828D9F4:
	ldr r8, [sp]
	add r0, pc, #1
	bx r0
	.thumb
_0828DA00:
	ldr r0, [sp, #4]
	subs r0, #1
	ble _0828DA0A
	adds r4, #0x40
	b _0828D700
_0828DA0A:
	ldr r0, [sp, #0x18]
	ldr r3, _0828DA20
	str r3, [r0]
	add sp, #0x1c
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}
	arm_func_end sub_0828D804

	non_word_aligned_thumb_func_start sub_0828DA1E
sub_0828DA1E: @ 0x0828DA1E
	bx r3
	.align 2, 0
_0828DA20: .4byte 0x68736D53
	thumb_func_end sub_0828DA1E

	arm_func_start sub_0828DA24
sub_0828DA24: @ 0x0828DA24
	ldr r6, [r4, #0x24]
	ldrb r0, [r4]
	tst r0, #0x20
	bne _0828DA74
	orr r0, r0, #0x20
	strb r0, [r4]
	ldrb r0, [r4, #1]
	tst r0, #0x10
	beq _0828DA5C
	ldr r1, [r6, #0xc]
	add r1, r1, r6, lsl #1
	add r1, r1, #0x20
	sub r3, r1, r3
	str r3, [r4, #0x28]
_0828DA5C:
	ldrh r0, [r6]
	cmp r0, #0
	beq _0828DA74
	sub r3, r3, r6
	sub r3, r3, #0x10
	str r3, [r4, #0x28]
_0828DA74:
	push {r8, ip, lr}
	lsl sl, sl, #0x10
	lsl fp, fp, #0x10
	ldr r1, [r4, #0x20]
	ldrb r0, [r4, #1]
	tst r0, #8
	movne r8, #0x800000
	muleq r8, ip, r1
	ldrh r0, [r6]
	cmp r0, #0
	beq _0828DC28
	mov r0, #-0x1000000
	str r0, [r4, #0x3c]
	ldrb r0, [r4, #1]
	tst r0, #0x10
	bne _0828DB80
	bl sub_0828DCE0
	mov r0, r1
	add r3, r3, #1
	bl sub_0828DCE0
	sub r1, r1, r0
_0828DAC8:
	ldr r6, [r5]
	ldr r7, [r5, #0x630]
_0828DAD0:
	mul lr, sb, r1
	add lr, r0, lr, asr #23
	mul ip, sl, lr
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	mul ip, fp, lr
	bic ip, ip, #0xff0000
	add r7, ip, r7, ror #8
	add sb, sb, r8
	lsrs lr, sb, #0x17
	beq _0828DB30
	bic sb, sb, #0x3f800000
	subs r2, r2, lr
	ble _0828DB58
	subs lr, lr, #1
	bne _0828DB18
	add r0, r0, r1
	b _0828DB24
_0828DB18:
	add r3, r3, lr
	bl sub_0828DCE0
	mov r0, r1
_0828DB24:
	add r3, r3, #1
	bl sub_0828DCE0
	sub r1, r1, r0
_0828DB30:
	adds r5, r5, #0x40000000
	blo _0828DAD0
	str r7, [r5, #0x630]
	str r6, [r5], #4
	ldr r6, [sp]
	subs r6, r6, #4
	str r6, [sp]
	bgt _0828DAC8
	sub r3, r3, #1
	b _0828DCB0
_0828DB58:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	beq _0828DCB4
	ldr r3, [r4, #0x24]
	ldr r3, [r3, #8]
	rsb lr, r2, #0
_0828DB70:
	adds r2, r2, r0
	bgt _0828DB18
	sub lr, lr, r0
	b _0828DB70
_0828DB80:
	sub r3, r3, #1
	bl sub_0828DCE0
	mov r0, r1
	sub r3, r3, #1
	bl sub_0828DCE0
	sub r1, r1, r0
_0828DB98:
	ldr r6, [r5]
	ldr r7, [r5, #0x630]
_0828DBA0:
	mul lr, sb, r1
	add lr, r0, lr, asr #23
	mul ip, sl, lr
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	mul ip, fp, lr
	bic ip, ip, #0xff0000
	add r7, ip, r7, ror #8
	add sb, sb, r8
	lsrs lr, sb, #0x17
	beq _0828DC00
	bic sb, sb, #0x3f800000
	subs r2, r2, lr
	ble _0828DCB4
	subs lr, lr, #1
	bne _0828DBE8
	add r0, r0, r1
	b _0828DBF4
_0828DBE8:
	sub r3, r3, lr
	bl sub_0828DCE0
	mov r0, r1
_0828DBF4:
	sub r3, r3, #1
	bl sub_0828DCE0
	sub r1, r1, r0
_0828DC00:
	adds r5, r5, #0x40000000
	blo _0828DBA0
	str r7, [r5, #0x630]
	str r6, [r5], #4
	ldr r6, [sp]
	subs r6, r6, #4
	str r6, [sp]
	bgt _0828DB98
	add r3, r3, #2
	b _0828DCB0
_0828DC28:
	ldrb r0, [r4, #1]
	tst r0, #0x10
	beq _0828DCB0
	ldrsb r0, [r3, #-1]!
	ldrsb r1, [r3, #-1]
	sub r1, r1, r0
_0828DC40:
	ldr r6, [r5]
	ldr r7, [r5, #0x630]
_0828DC48:
	mul lr, sb, r1
	add lr, r0, lr, asr #23
	mul ip, sl, lr
	bic ip, ip, #0xff0000
	add r6, ip, r6, ror #8
	mul ip, fp, lr
	bic ip, ip, #0xff0000
	add r7, ip, r7, ror #8
	add sb, sb, r8
	lsrs lr, sb, #0x17
	beq _0828DC8C
	bic sb, sb, #0x3f800000
	subs r2, r2, lr
	ble _0828DCB4
	ldrsb r0, [r3, -lr]!
	ldrsb r1, [r3, #-1]
	sub r1, r1, r0
_0828DC8C:
	adds r5, r5, #0x40000000
	blo _0828DC48
	str r7, [r5, #0x630]
	str r6, [r5], #4
	ldr r6, [sp]
	subs r6, r6, #4
	str r6, [sp]
	bgt _0828DC40
	add r3, r3, #1
_0828DCB0:
	pop {r8, ip, pc}
_0828DCB4:
	mov r2, #0
	strb r2, [r4]
	lsr r0, r5, #0x1e
	bic r5, r5, #0xc0000000
	rsb r0, r0, #3
	lsl r0, r0, #3
	ror r6, r6, r0
	ror r7, r7, r0
	str r7, [r5, #0x630]
	str r6, [r5], #4
	pop {r8, ip, pc}
	arm_func_end sub_0828DA24

	arm_func_start sub_0828DCE0
sub_0828DCE0: @ 0x0828DCE0
	push {r0, r2, r5, r6, r7, lr}
	lsr r0, r3, #6
	ldr r1, [r4, #0x3c]
	cmp r0, r1
	beq _0828DD54
	str r0, [r4, #0x3c]
	mov r1, #0x21
	mul r2, r1, r0
	ldr r1, [r4, #0x24]
	add r2, r2, r1
	add r2, r2, #0x10
	ldr r5, _0828DD64
	ldr r6, _0828DD68
	mov r7, #0x40
	ldrb lr, [r2], #1
	strb lr, [r5], #1
	ldrb r1, [r2], #1
	b _0828DD3C
_0828DD28:
	ldrb r1, [r2], #1
	lsr r0, r1, #4
	ldrsb r0, [r6, r0]
	add lr, lr, r0
	strb lr, [r5], #1
_0828DD3C:
	and r0, r1, #0xf
	ldrsb r0, [r6, r0]
	add lr, lr, r0
	strb lr, [r5], #1
	subs r7, r7, #2
	bgt _0828DD28
_0828DD54:
	ldr r5, _0828DD64
	and r0, r3, #0x3f
	ldrsb r1, [r5, r0]
	pop {r0, r2, r5, r6, r7, pc}
	.align 2, 0
_0828DD64: .4byte 0x030012F8
_0828DD68: .4byte 0x085FD590
	arm_func_end sub_0828DCE0

	thumb_func_start SoundMainBTM
SoundMainBTM: @ 0x0828DD6C
	mov ip, r4
	movs r1, #0
	movs r2, #0
	movs r3, #0
	movs r4, #0
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	stm r0!, {r1, r2, r3, r4}
	mov r4, ip
	bx lr
	.align 2, 0
	thumb_func_end SoundMainBTM

	thumb_func_start RealClearChain
RealClearChain: @ 0x0828DD84
	ldr r3, [r0, #0x2c]
	cmp r3, #0
	beq _0828DDA2
	ldr r1, [r0, #0x34]
	ldr r2, [r0, #0x30]
	cmp r2, #0
	beq _0828DD96
	str r1, [r2, #0x34]
	b _0828DD98
_0828DD96:
	str r1, [r3, #0x20]
_0828DD98:
	cmp r1, #0
	beq _0828DD9E
	str r2, [r1, #0x30]
_0828DD9E:
	movs r1, #0
	str r1, [r0, #0x2c]
_0828DDA2:
	bx lr
ply_fine:
	push {r4, r5, lr}
	adds r5, r1, #0
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _0828DDC8
_0828DDAE:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _0828DDBC
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
_0828DDBC:
	adds r0, r4, #0
	bl RealClearChain
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _0828DDAE
_0828DDC8:
	movs r0, #0
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end RealClearChain

	thumb_func_start MPlayJumpTableCopy
MPlayJumpTableCopy: @ 0x0828DDD4
	mov ip, lr
	movs r1, #0x24
	ldr r2, _0828DE04
_0828DDDA:
	ldr r3, [r2]
	bl _0828DDEE
	stm r0!, {r3}
	adds r2, #4
	subs r1, #1
	bgt _0828DDDA
	bx ip
	.align 2, 0
	thumb_func_end MPlayJumpTableCopy

	thumb_func_start sub_0828DDEC
sub_0828DDEC: @ 0x0828DDEC
	ldrb r3, [r2]
_0828DDEE:
	push {r0}
	lsrs r0, r2, #0x19
	bne _0828DE00
	ldr r0, _0828DE04
	cmp r2, r0
	blo _0828DDFE
	lsrs r0, r2, #0xe
	beq _0828DE00
_0828DDFE:
	movs r3, #0
_0828DE00:
	pop {r0}
	bx lr
	.align 2, 0
_0828DE04: .4byte 0x085FD500
	thumb_func_end sub_0828DDEC

	thumb_func_start ld_r3_tp_adr_i
ld_r3_tp_adr_i: @ 0x0828DE08
	ldr r2, [r1, #0x40]
	thumb_func_end ld_r3_tp_adr_i

	non_word_aligned_thumb_func_start sub_0828DE0A
sub_0828DE0A: @ 0x0828DE0A
	adds r3, r2, #1
	str r3, [r1, #0x40]
	ldrb r3, [r2]
	b _0828DDEE
	.align 2, 0
ply_goto:
	push {lr}
_0828DE16:
	ldr r2, [r1, #0x40]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	ldrb r3, [r2, #2]
	orrs r0, r3
	lsls r0, r0, #8
	ldrb r3, [r2, #1]
	orrs r0, r3
	lsls r0, r0, #8
	bl sub_0828DDEC
	orrs r0, r3
	str r0, [r1, #0x40]
	pop {r0}
	bx r0
	thumb_func_end sub_0828DE0A

	thumb_func_start ply_patt
ply_patt: @ 0x0828DE34
	ldrb r2, [r1, #2]
	cmp r2, #3
	bhs _0828DE4C
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r1, #0x40]
	adds r2, #4
	str r2, [r3, #0x44]
	ldrb r2, [r1, #2]
	adds r2, #1
	strb r2, [r1, #2]
	b ply_goto
_0828DE4C:
	b ply_fine
	.align 2, 0
	thumb_func_end ply_patt

	thumb_func_start ply_pend
ply_pend: @ 0x0828DE50
	ldrb r2, [r1, #2]
	cmp r2, #0
	beq _0828DE62
	subs r2, #1
	strb r2, [r1, #2]
	lsls r2, r2, #2
	adds r3, r1, r2
	ldr r2, [r3, #0x44]
	str r2, [r1, #0x40]
_0828DE62:
	bx lr
	thumb_func_end ply_pend

	thumb_func_start ply_rept
ply_rept: @ 0x0828DE64
	push {lr}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0
	bne _0828DE74
	adds r2, #1
	str r2, [r1, #0x40]
	b _0828DE16
_0828DE74:
	ldrb r3, [r1, #3]
	adds r3, #1
	strb r3, [r1, #3]
	mov ip, r3
	bl ld_r3_tp_adr_i
	cmp ip, r3
	bhs _0828DE86
	b _0828DE16
_0828DE86:
	movs r3, #0
	strb r3, [r1, #3]
	adds r2, #5
	str r2, [r1, #0x40]
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ply_rept

	thumb_func_start ply_prio
ply_prio: @ 0x0828DE94
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x1d]
	bx ip
	.align 2, 0
	thumb_func_end ply_prio

	thumb_func_start ply_tempo
ply_tempo: @ 0x0828DEA0
	mov ip, lr
	bl ld_r3_tp_adr_i
	lsls r3, r3, #1
	strh r3, [r0, #0x1c]
	ldrh r2, [r0, #0x1e]
	muls r3, r2, r3
	lsrs r3, r3, #8
	strh r3, [r0, #0x20]
	bx ip
	thumb_func_end ply_tempo

	thumb_func_start ply_keysh
ply_keysh: @ 0x0828DEB4
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0xa]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0
	thumb_func_end ply_keysh

	thumb_func_start ply_voice
ply_voice: @ 0x0828DEC8
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	str r2, [r1, #0x40]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	ldr r3, [r0, #0x30]
	adds r2, r2, r3
	ldr r3, [r2]
	bl _0828DDEE
	str r3, [r1, #0x24]
	ldr r3, [r2, #4]
	bl _0828DDEE
	str r3, [r1, #0x28]
	ldr r3, [r2, #8]
	bl _0828DDEE
	str r3, [r1, #0x2c]
	bx ip
	.align 2, 0
	thumb_func_end ply_voice

	thumb_func_start ply_vol
ply_vol: @ 0x0828DEF8
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x12]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0
	thumb_func_end ply_vol

	thumb_func_start ply_pan
ply_pan: @ 0x0828DF0C
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0x14]
	ldrb r3, [r1]
	movs r2, #3
	orrs r3, r2
	strb r3, [r1]
	bx ip
	thumb_func_end ply_pan

	thumb_func_start ply_bend
ply_bend: @ 0x0828DF20
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0xe]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	thumb_func_end ply_bend

	thumb_func_start ply_bendr
ply_bendr: @ 0x0828DF34
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0xf]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	.align 2, 0
	thumb_func_end ply_bendr

	thumb_func_start ply_lfodl
ply_lfodl: @ 0x0828DF48
	mov ip, lr
	bl ld_r3_tp_adr_i
	strb r3, [r1, #0x1b]
	bx ip
	.align 2, 0
	thumb_func_end ply_lfodl

	thumb_func_start ply_modt
ply_modt: @ 0x0828DF54
	mov ip, lr
	bl ld_r3_tp_adr_i
	ldrb r0, [r1, #0x18]
	cmp r0, r3
	beq _0828DF6A
	strb r3, [r1, #0x18]
	ldrb r3, [r1]
	movs r2, #0xf
	orrs r3, r2
	strb r3, [r1]
_0828DF6A:
	bx ip
	thumb_func_end ply_modt

	thumb_func_start ply_tune
ply_tune: @ 0x0828DF6C
	mov ip, lr
	bl ld_r3_tp_adr_i
	subs r3, #0x40
	strb r3, [r1, #0xc]
	ldrb r3, [r1]
	movs r2, #0xc
	orrs r3, r2
	strb r3, [r1]
	bx ip
	thumb_func_end ply_tune

	thumb_func_start ply_port
ply_port: @ 0x0828DF80
	mov ip, lr
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	adds r2, #1
	ldr r0, _0828DF94
	adds r0, r0, r3
	bl sub_0828DE0A
	strb r3, [r0]
	bx ip
	.align 2, 0
_0828DF94: .4byte 0x04000060
	thumb_func_end ply_port

	thumb_func_start m4aSoundVSync
m4aSoundVSync: @ 0x0828DF98
	ldr r0, _0828E244
	ldr r0, [r0]
	ldr r2, _0828E248
	ldr r3, [r0]
	subs r3, r3, r2
	cmp r3, #1
	bhi _0828DFD8
	ldrb r1, [r0, #4]
	subs r1, #1
	strb r1, [r0, #4]
	bgt _0828DFD8
	ldrb r1, [r0, #0xb]
	strb r1, [r0, #4]
	ldr r2, _0828DFDC
	ldr r1, [r2, #8]
	lsls r1, r1, #7
	blo _0828DFBE
	ldr r1, _0828DFE0
	str r1, [r2, #8]
_0828DFBE:
	ldr r1, [r2, #0x14]
	lsls r1, r1, #7
	blo _0828DFC8
	ldr r1, _0828DFE0
	str r1, [r2, #0x14]
_0828DFC8:
	movs r1, #4
	lsls r1, r1, #8
	strh r1, [r2, #0xa]
	strh r1, [r2, #0x16]
	movs r1, #0xb6
	lsls r1, r1, #8
	strh r1, [r2, #0xa]
	strh r1, [r2, #0x16]
_0828DFD8:
	bx lr
	.align 2, 0
_0828DFDC: .4byte 0x040000BC
_0828DFE0: .4byte 0x84400004
	thumb_func_end m4aSoundVSync

	thumb_func_start MPlayMain
MPlayMain: @ 0x0828DFE4
	ldr r2, _0828E248
	ldr r3, [r0, #0x34]
	cmp r2, r3
	beq _0828DFEE
	bx lr
_0828DFEE:
	adds r3, #1
	str r3, [r0, #0x34]
	push {r0, lr}
	ldr r3, [r0, #0x38]
	cmp r3, #0
	beq _0828E000
	ldr r0, [r0, #0x3c]
	bl sub_0828E23C
_0828E000:
	pop {r0}
	push {r4, r5, r6, r7}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	adds r7, r0, #0
	ldr r0, [r7, #4]
	cmp r0, #0
	bge _0828E018
	b _0828E22C
_0828E018:
	ldr r0, _0828E244
	ldr r0, [r0]
	mov r8, r0
	adds r0, r7, #0
	bl FadeOutBody
	ldr r0, [r7, #4]
	cmp r0, #0
	bge _0828E02C
	b _0828E22C
_0828E02C:
	ldrh r0, [r7, #0x22]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	b _0828E17C
_0828E034:
	ldrb r6, [r7, #8]
	ldr r5, [r7, #0x2c]
	movs r3, #1
	movs r4, #0
_0828E03C:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	bne _0828E046
	b _0828E158
_0828E046:
	mov sl, r3
	orrs r4, r3
	mov fp, r4
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _0828E07A
_0828E052:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _0828E06E
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0828E074
	subs r0, #1
	strb r0, [r4, #0x10]
	bne _0828E074
	movs r0, #0x40
	orrs r1, r0
	strb r1, [r4]
	b _0828E074
_0828E06E:
	adds r0, r4, #0
	bl ClearChain
_0828E074:
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _0828E052
_0828E07A:
	ldrb r3, [r5]
	movs r0, #0x40
	tst r0, r3
	beq _0828E0F8
	adds r0, r5, #0
	bl Clear64byte
	movs r0, #0x80
	strb r0, [r5]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0x40
	strb r0, [r5, #0x13]
	movs r0, #0x16
	strb r0, [r5, #0x19]
	movs r0, #1
	adds r1, r5, #6
	strb r0, [r1, #0x1e]
	b _0828E0F8
_0828E0A0:
	ldr r2, [r5, #0x40]
	ldrb r1, [r2]
	cmp r1, #0x80
	bhs _0828E0AC
	ldrb r1, [r5, #7]
	b _0828E0B6
_0828E0AC:
	adds r2, #1
	str r2, [r5, #0x40]
	cmp r1, #0xbd
	blo _0828E0B6
	strb r1, [r5, #7]
_0828E0B6:
	cmp r1, #0xcf
	blo _0828E0CC
	mov r0, r8
	ldr r3, [r0, #0x38]
	adds r0, r1, #0
	subs r0, #0xcf
	adds r1, r7, #0
	adds r2, r5, #0
	bl sub_0828E23C
	b _0828E0F8
_0828E0CC:
	cmp r1, #0xb0
	bls _0828E0EE
	adds r0, r1, #0
	subs r0, #0xb1
	strb r0, [r7, #0xa]
	mov r3, r8
	ldr r3, [r3, #0x34]
	lsls r0, r0, #2
	ldr r3, [r3, r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl sub_0828E23C
	ldrb r0, [r5]
	cmp r0, #0
	beq _0828E154
	b _0828E0F8
_0828E0EE:
	ldr r0, _0828E240
	subs r1, #0x80
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r5, #1]
_0828E0F8:
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _0828E0A0
	subs r0, #1
	strb r0, [r5, #1]
	ldrb r1, [r5, #0x19]
	cmp r1, #0
	beq _0828E154
	ldrb r0, [r5, #0x17]
	cmp r0, #0
	beq _0828E154
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _0828E11A
	subs r0, #1
	strb r0, [r5, #0x1c]
	b _0828E154
_0828E11A:
	ldrb r0, [r5, #0x1a]
	adds r0, r0, r1
	strb r0, [r5, #0x1a]
	adds r1, r0, #0
	subs r0, #0x40
	lsls r0, r0, #0x18
	bpl _0828E12E
	lsls r2, r1, #0x18
	asrs r2, r2, #0x18
	b _0828E132
_0828E12E:
	movs r0, #0x80
	subs r2, r0, r1
_0828E132:
	ldrb r0, [r5, #0x17]
	muls r0, r2, r0
	asrs r2, r0, #6
	ldrb r0, [r5, #0x16]
	eors r0, r2
	lsls r0, r0, #0x18
	beq _0828E154
	strb r2, [r5, #0x16]
	ldrb r0, [r5]
	ldrb r1, [r5, #0x18]
	cmp r1, #0
	bne _0828E14E
	movs r1, #0xc
	b _0828E150
_0828E14E:
	movs r1, #3
_0828E150:
	orrs r0, r1
	strb r0, [r5]
_0828E154:
	mov r3, sl
	mov r4, fp
_0828E158:
	subs r6, #1
	ble _0828E164
	movs r0, #0x50
	adds r5, r5, r0
	lsls r3, r3, #1
	b _0828E03C
_0828E164:
	ldr r0, [r7, #0xc]
	adds r0, #1
	str r0, [r7, #0xc]
	cmp r4, #0
	bne _0828E176
	movs r0, #0x80
	lsls r0, r0, #0x18
	str r0, [r7, #4]
	b _0828E22C
_0828E176:
	str r4, [r7, #4]
	ldrh r0, [r7, #0x22]
	subs r0, #0x96
_0828E17C:
	strh r0, [r7, #0x22]
	cmp r0, #0x96
	blo _0828E184
	b _0828E034
_0828E184:
	ldrb r2, [r7, #8]
	ldr r5, [r7, #0x2c]
_0828E188:
	ldrb r0, [r5]
	movs r1, #0x80
	tst r1, r0
	beq _0828E222
	movs r1, #0xf
	tst r1, r0
	beq _0828E222
	mov sb, r2
	adds r0, r7, #0
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _0828E218
_0828E1A6:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	bne _0828E1B6
	adds r0, r4, #0
	bl ClearChain
	b _0828E212
_0828E1B6:
	ldrb r0, [r4, #1]
	movs r6, #7
	ands r6, r0
	ldrb r3, [r5]
	movs r0, #3
	tst r0, r3
	beq _0828E1D4
	bl ChnVolSetAsm
	cmp r6, #0
	beq _0828E1D4
	ldrb r0, [r4, #0x1d]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4, #0x1d]
_0828E1D4:
	ldrb r3, [r5]
	movs r0, #0xc
	tst r0, r3
	beq _0828E212
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r2, r1, r0
	bpl _0828E1E8
	movs r2, #0
_0828E1E8:
	cmp r6, #0
	beq _0828E206
	mov r0, r8
	ldr r3, [r0, #0x30]
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	adds r0, r6, #0
	bl sub_0828E23C
	str r0, [r4, #0x20]
	ldrb r0, [r4, #0x1d]
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #0x1d]
	b _0828E212
_0828E206:
	adds r1, r2, #0
	ldrb r2, [r5, #9]
	ldr r0, [r4, #0x24]
	bl MidiKeyToFreq
	str r0, [r4, #0x20]
_0828E212:
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _0828E1A6
_0828E218:
	ldrb r0, [r5]
	movs r1, #0xf0
	ands r0, r1
	strb r0, [r5]
	mov r2, sb
_0828E222:
	subs r2, #1
	ble _0828E22C
	movs r0, #0x50
	adds r5, r5, r0
	bgt _0828E188
_0828E22C:
	ldr r0, _0828E248
	str r0, [r7, #0x34]
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r3}
	thumb_func_end MPlayMain

	thumb_func_start sub_0828E23C
sub_0828E23C: @ 0x0828E23C
	bx r3
	.align 2, 0
_0828E240: .4byte 0x085FD784
_0828E244: .4byte 0x03007FF0
_0828E248: .4byte 0x68736D53
	thumb_func_end sub_0828E23C

	thumb_func_start TrackStop
TrackStop: @ 0x0828E24C
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	ldrb r1, [r5]
	movs r0, #0x80
	tst r0, r1
	beq _0828E284
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _0828E282
	movs r6, #0
_0828E260:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0828E27A
	ldrb r0, [r4, #1]
	movs r3, #7
	ands r0, r3
	beq _0828E278
	ldr r3, _0828E28C
	ldr r3, [r3]
	ldr r3, [r3, #0x2c]
	bl sub_0828E23C
_0828E278:
	strb r6, [r4]
_0828E27A:
	str r6, [r4, #0x2c]
	ldr r4, [r4, #0x34]
	cmp r4, #0
	bne _0828E260
_0828E282:
	str r4, [r5, #0x20]
_0828E284:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0828E28C: .4byte 0x03007FF0
	thumb_func_end TrackStop

	thumb_func_start ChnVolSetAsm
ChnVolSetAsm: @ 0x0828E290
	ldrb r1, [r4, #0x12]
	movs r0, #0x14
	ldrsb r2, [r4, r0]
	movs r3, #0x80
	adds r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x10]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls _0828E2A8
	movs r0, #0xff
_0828E2A8:
	strb r0, [r4, #2]
	movs r3, #0x7f
	subs r3, r3, r2
	muls r3, r1, r3
	ldrb r0, [r5, #0x11]
	muls r0, r3, r0
	asrs r0, r0, #0xe
	cmp r0, #0xff
	bls _0828E2BC
	movs r0, #0xff
_0828E2BC:
	strb r0, [r4, #3]
	bx lr
	thumb_func_end ChnVolSetAsm

	thumb_func_start ply_note
ply_note: @ 0x0828E2C0
	push {r4, r5, r6, r7, lr}
	mov r4, r8
	mov r5, sb
	mov r6, sl
	mov r7, fp
	push {r4, r5, r6, r7}
	sub sp, #0x18
	str r1, [sp]
	adds r5, r2, #0
	ldr r1, _0828E4BC
	ldr r1, [r1]
	str r1, [sp, #4]
	ldr r1, _0828E4C0
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r5, #4]
	ldr r3, [r5, #0x40]
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _0828E306
	strb r0, [r5, #5]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _0828E304
	strb r0, [r5, #6]
	adds r3, #1
	ldrb r0, [r3]
	cmp r0, #0x80
	bhs _0828E304
	ldrb r1, [r5, #4]
	adds r1, r1, r0
	strb r1, [r5, #4]
	adds r3, #1
_0828E304:
	str r3, [r5, #0x40]
_0828E306:
	movs r0, #0
	str r0, [sp, #0x14]
	adds r4, r5, #0
	adds r4, #0x24
	ldrb r2, [r4]
	movs r0, #0xc0
	tst r0, r2
	beq _0828E358
	ldrb r3, [r5, #5]
	movs r0, #0x40
	tst r0, r2
	beq _0828E326
	ldr r1, [r5, #0x2c]
	adds r1, r1, r3
	ldrb r0, [r1]
	b _0828E328
_0828E326:
	adds r0, r3, #0
_0828E328:
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r5, #0x28]
	adds r1, r1, r0
	mov sb, r1
	mov r6, sb
	ldrb r1, [r6]
	movs r0, #0xc0
	tst r0, r1
	beq _0828E340
	b _0828E4AA
_0828E340:
	movs r0, #0x80
	tst r0, r2
	beq _0828E35C
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	beq _0828E354
	subs r1, #0xc0
	lsls r1, r1, #1
	str r1, [sp, #0x14]
_0828E354:
	ldrb r3, [r6, #1]
	b _0828E35C
_0828E358:
	mov sb, r4
	ldrb r3, [r5, #5]
_0828E35C:
	str r3, [sp, #8]
	ldr r6, [sp]
	ldrb r1, [r6, #9]
	ldrb r0, [r5, #0x1d]
	adds r0, r0, r1
	cmp r0, #0xff
	bls _0828E36C
	movs r0, #0xff
_0828E36C:
	str r0, [sp, #0x10]
	mov r6, sb
	ldrb r0, [r6]
	movs r6, #7
	ands r6, r0
	str r6, [sp, #0xc]
	beq _0828E3AC
	ldr r0, [sp, #4]
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _0828E384
	b _0828E4AA
_0828E384:
	subs r6, #1
	lsls r0, r6, #6
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _0828E400
	movs r0, #0x40
	tst r0, r1
	bne _0828E400
	ldrb r1, [r4, #0x13]
	ldr r0, [sp, #0x10]
	cmp r1, r0
	blo _0828E400
	beq _0828E3A4
	b _0828E4AA
_0828E3A4:
	ldr r0, [r4, #0x2c]
	cmp r0, r5
	bhs _0828E400
	b _0828E4AA
_0828E3AC:
	ldr r6, [sp, #0x10]
	adds r7, r5, #0
	movs r2, #0
	mov r8, r2
	ldr r4, [sp, #4]
	ldrb r3, [r4, #6]
	adds r4, #0x50
_0828E3BA:
	ldrb r1, [r4]
	movs r0, #0xc7
	tst r0, r1
	beq _0828E400
	movs r0, #0x40
	tst r0, r1
	beq _0828E3D4
	cmp r2, #0
	bne _0828E3D8
	adds r2, #1
	ldrb r6, [r4, #0x13]
	ldr r7, [r4, #0x2c]
	b _0828E3F2
_0828E3D4:
	cmp r2, #0
	bne _0828E3F4
_0828E3D8:
	ldrb r0, [r4, #0x13]
	cmp r0, r6
	bhs _0828E3E4
	adds r6, r0, #0
	ldr r7, [r4, #0x2c]
	b _0828E3F2
_0828E3E4:
	bhi _0828E3F4
	ldr r0, [r4, #0x2c]
	cmp r0, r7
	bls _0828E3F0
	adds r7, r0, #0
	b _0828E3F2
_0828E3F0:
	blo _0828E3F4
_0828E3F2:
	mov r8, r4
_0828E3F4:
	adds r4, #0x40
	subs r3, #1
	bgt _0828E3BA
	mov r4, r8
	cmp r4, #0
	beq _0828E4AA
_0828E400:
	adds r0, r4, #0
	bl ClearChain
	movs r1, #0
	str r1, [r4, #0x30]
	ldr r3, [r5, #0x20]
	str r3, [r4, #0x34]
	cmp r3, #0
	beq _0828E414
	str r4, [r3, #0x30]
_0828E414:
	str r4, [r5, #0x20]
	str r5, [r4, #0x2c]
	ldrb r0, [r5, #0x1b]
	strb r0, [r5, #0x1c]
	cmp r0, r1
	beq _0828E426
	adds r1, r5, #0
	bl clear_modM
_0828E426:
	ldr r0, [sp]
	adds r1, r5, #0
	bl TrkVolPitSet
	ldr r0, [r5, #4]
	str r0, [r4, #0x10]
	ldr r0, [sp, #0x10]
	strb r0, [r4, #0x13]
	ldr r0, [sp, #8]
	strb r0, [r4, #8]
	ldr r0, [sp, #0x14]
	strb r0, [r4, #0x14]
	mov r6, sb
	ldrb r0, [r6]
	strb r0, [r4, #1]
	ldr r7, [r6, #4]
	str r7, [r4, #0x24]
	ldr r0, [r6, #8]
	str r0, [r4, #4]
	ldrh r0, [r5, #0x1e]
	strh r0, [r4, #0xc]
	bl ChnVolSetAsm
	ldrb r1, [r4, #8]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r3, r1, r0
	bpl _0828E460
	movs r3, #0
_0828E460:
	ldr r6, [sp, #0xc]
	cmp r6, #0
	beq _0828E48E
	mov r6, sb
	ldrb r0, [r6, #2]
	strb r0, [r4, #0x1e]
	ldrb r1, [r6, #3]
	movs r0, #0x80
	tst r0, r1
	bne _0828E47A
	movs r0, #0x70
	tst r0, r1
	bne _0828E47C
_0828E47A:
	movs r1, #8
_0828E47C:
	strb r1, [r4, #0x1f]
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	ldr r0, [sp, #0xc]
	ldr r3, [sp, #4]
	ldr r3, [r3, #0x30]
	bl sub_0828E23C
	b _0828E49C
_0828E48E:
	ldr r0, [r5, #0x3c]
	str r0, [r4, #0x18]
	ldrb r2, [r5, #9]
	adds r1, r3, #0
	adds r0, r7, #0
	bl MidiKeyToFreq
_0828E49C:
	str r0, [r4, #0x20]
	movs r0, #0x80
	strb r0, [r4]
	ldrb r1, [r5]
	movs r0, #0xf0
	ands r0, r1
	strb r0, [r5]
_0828E4AA:
	add sp, #0x18
	pop {r0, r1, r2, r3, r4, r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	mov fp, r3
	pop {r0}
	bx r0
	.align 2, 0
_0828E4BC: .4byte 0x03007FF0
_0828E4C0: .4byte 0x085FD784
	thumb_func_end ply_note

	thumb_func_start ply_endtie
ply_endtie: @ 0x0828E4C4
	push {r4, r5}
	ldr r2, [r1, #0x40]
	ldrb r3, [r2]
	cmp r3, #0x80
	bhs _0828E4D6
	strb r3, [r1, #5]
	adds r2, #1
	str r2, [r1, #0x40]
	b _0828E4D8
_0828E4D6:
	ldrb r3, [r1, #5]
_0828E4D8:
	ldr r1, [r1, #0x20]
	cmp r1, #0
	beq _0828E500
	movs r4, #0x83
	movs r5, #0x40
_0828E4E2:
	ldrb r2, [r1]
	tst r2, r4
	beq _0828E4FA
	tst r2, r5
	bne _0828E4FA
	ldrb r0, [r1, #0x11]
	cmp r0, r3
	bne _0828E4FA
	movs r0, #0x40
	orrs r2, r0
	strb r2, [r1]
	b _0828E500
_0828E4FA:
	ldr r1, [r1, #0x34]
	cmp r1, #0
	bne _0828E4E2
_0828E500:
	pop {r4, r5}
	bx lr
	thumb_func_end ply_endtie

