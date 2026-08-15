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
.global ply_fine
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
.global _0828DDEE
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
.global ply_goto
ply_goto:
	push {lr}
.global _0828DE16
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

