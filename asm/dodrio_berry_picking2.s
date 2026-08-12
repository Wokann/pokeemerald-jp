.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
























	thumb_func_start sub_08025BD4
sub_08025BD4: @ 0x08025BD4
	push {r4, r5, r6, lr}
	sub sp, #0x18
	ldr r0, _08025BE8
	ldr r5, [r0]
	ldrb r0, [r5, #0x18]
	cmp r0, #4
	beq _08025BEC
	cmp r0, #0xb
	beq _08025C44
	b _08025C88
	.align 2, 0
_08025BE8: .4byte 0x0202294C
_08025BEC:
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _08025C34
	adds r1, r1, r2
	adds r1, r5, r1
	ldr r3, _08025C38
	adds r2, r5, r3
	ldr r4, _08025C3C
	adds r3, r5, r4
	ldr r6, _08025C40
	adds r4, r5, r6
	str r4, [sp]
	adds r6, #0x3c
	adds r4, r5, r6
	str r4, [sp, #4]
	adds r6, #0x3c
	adds r4, r5, r6
	str r4, [sp, #8]
	adds r4, r5, #0
	adds r4, #0x40
	str r4, [sp, #0xc]
	movs r6, #0x90
	lsls r6, r6, #1
	adds r4, r5, r6
	str r4, [sp, #0x10]
	adds r6, #0xc
	adds r4, r5, r6
	str r4, [sp, #0x14]
	bl sub_08027E90
	b _08025C88
	.align 2, 0
_08025C34: .4byte 0x000031A0
_08025C38: .4byte 0x000031CC
_08025C3C: .4byte 0x00003208
_08025C40: .4byte 0x00003244
_08025C44:
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r2, _08025C90
	adds r1, r1, r2
	adds r1, r5, r1
	ldr r3, _08025C94
	adds r2, r5, r3
	ldr r4, _08025C98
	adds r3, r5, r4
	ldr r6, _08025C9C
	adds r4, r5, r6
	str r4, [sp]
	adds r6, #0x3c
	adds r4, r5, r6
	str r4, [sp, #4]
	adds r6, #0x3c
	adds r4, r5, r6
	str r4, [sp, #8]
	adds r4, r5, #0
	adds r4, #0x40
	str r4, [sp, #0xc]
	movs r6, #0x90
	lsls r6, r6, #1
	adds r4, r5, r6
	str r4, [sp, #0x10]
	adds r6, #0xc
	adds r4, r5, r6
	str r4, [sp, #0x14]
	bl sub_08027E90
_08025C88:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08025C90: .4byte 0x000031A0
_08025C94: .4byte 0x000031CC
_08025C98: .4byte 0x00003208
_08025C9C: .4byte 0x00003244
	thumb_func_end sub_08025BD4

	thumb_func_start sub_08025CA0
sub_08025CA0: @ 0x08025CA0
	push {r4, lr}
	ldr r4, _08025CB8
	ldr r1, [r4]
	ldrb r0, [r1, #0x18]
	cmp r0, #4
	beq _08025CD6
	cmp r0, #4
	bgt _08025CBC
	cmp r0, #3
	beq _08025CC2
	b _08025D08
	.align 2, 0
_08025CB8: .4byte 0x0202294C
_08025CBC:
	cmp r0, #0xb
	beq _08025CEC
	b _08025D08
_08025CC2:
	movs r0, #1
	bl sub_08027AFC
	ldr r0, [r4]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
	b _08025D08
_08025CD6:
	ldr r2, _08025CE8
	adds r1, r1, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025D08
	bl sub_08028018
	b _08025D08
	.align 2, 0
_08025CE8: .4byte 0x000032F8
_08025CEC:
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08025D08
	adds r2, #0xc
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08025D08
	movs r0, #1
	bl sub_0802807C
_08025D08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08025CA0

	thumb_func_start sub_08025D10
sub_08025D10: @ 0x08025D10
	push {r4, r5, r6, lr}
	ldr r6, _08025D48
	ldr r2, [r6]
	adds r0, r2, #0
	adds r0, #0x28
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r3, _08025D4C
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08025D50
	bl IsSEPlaying
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08025DB2
	ldr r0, [r6]
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	b _08025DB2
	.align 2, 0
_08025D48: .4byte 0x0202294C
_08025D4C: .4byte 0x000031CC
_08025D50:
	ldr r3, _08025D7C
	adds r0, r1, r3
	ldrb r4, [r0]
	cmp r4, #1
	bne _08025D80
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08025DB2
	movs r0, #0x1f
	bl m4aSongNumStop
	movs r0, #0x1f
	bl PlaySE
	ldr r0, [r6]
	movs r2, #0xa2
	lsls r2, r2, #1
	adds r0, r0, r2
	b _08025DB0
	.align 2, 0
_08025D7C: .4byte 0x000031D0
_08025D80:
	ldr r3, _08025DDC
	adds r0, r1, r3
	ldrb r4, [r0]
	cmp r4, #1
	bne _08025DB2
	movs r5, #0xa2
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08025DB2
	bl IsSEPlaying
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025DB2
	movs r0, #0x16
	bl PlaySE
	movs r0, #1
	bl sub_080281F8
	ldr r0, [r6]
	adds r0, r0, r5
_08025DB0:
	strb r4, [r0]
_08025DB2:
	ldr r0, _08025DE0
	ldr r2, [r0]
	movs r5, #0xaa
	lsls r5, r5, #1
	adds r1, r2, r5
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #0
	bne _08025DE4
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _08025DE4
	bl StopMapMusic
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #1
	b _08025E02
	.align 2, 0
_08025DDC: .4byte 0x000031D4
_08025DE0: .4byte 0x0202294C
_08025DE4:
	ldr r0, [r4]
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08025E04
	movs r0, #0xb
	bl PlayFanfareByFanfareNum
	ldr r0, [r4]
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r1, #2
_08025E02:
	strb r1, [r0]
_08025E04:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08025D10

	thumb_func_start sub_08025E0C
sub_08025E0C: @ 0x08025E0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r6, _08025E58
	ldr r2, [r6]
	adds r0, r2, #0
	adds r0, #0x44
	ldrb r0, [r0]
	mov r8, r0
	adds r0, r2, #0
	adds r0, #0x48
	ldrb r7, [r0]
	subs r0, #0x20
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r3, _08025E5C
	adds r0, r1, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _08025E64
	ldr r4, _08025E60
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _08025EC6
	adds r4, #4
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _08025EC6
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r2, r1
	strb r3, [r0]
	b _08025EC6
	.align 2, 0
_08025E58: .4byte 0x0202294C
_08025E5C: .4byte 0x000031CC
_08025E60: .4byte 0x000031D0
_08025E64:
	ldr r3, _08025E90
	adds r0, r1, r3
	ldrb r4, [r0]
	cmp r4, #1
	bne _08025E94
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08025EC6
	movs r0, #0x1f
	bl m4aSongNumStop
	movs r0, #0x1f
	bl PlaySE
	ldr r0, [r6]
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r0, r0, r3
	b _08025EC4
	.align 2, 0
_08025E90: .4byte 0x000031D0
_08025E94:
	ldr r4, _08025F18
	adds r0, r1, r4
	ldrb r4, [r0]
	cmp r4, #1
	bne _08025EC6
	movs r5, #0xa2
	lsls r5, r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08025EC6
	bl IsSEPlaying
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025EC6
	movs r0, #0x16
	bl PlaySE
	movs r0, #1
	bl sub_080281F8
	ldr r0, [r6]
	adds r0, r0, r5
_08025EC4:
	strb r4, [r0]
_08025EC6:
	mov r4, r8
	cmp r4, r7
	bhs _08025F3A
	ldr r5, _08025F1C
_08025ECE:
	ldr r2, [r5]
	adds r0, r2, #0
	adds r0, #0x28
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08025F20
	adds r0, r0, r1
	adds r0, r2, r0
	adds r1, r0, #0
	adds r1, #0x14
	adds r0, #0x1f
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #9
	bls _08025F24
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08025F30
	adds r0, r1, r4
	ldrb r0, [r0]
	adds r0, #0x4a
	bl PlaySE
	ldr r0, [r5]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r0, r4
	movs r1, #1
	b _08025F2E
	.align 2, 0
_08025F18: .4byte 0x000031D4
_08025F1C: .4byte 0x0202294C
_08025F20: .4byte 0x000031A0
_08025F24:
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r0, r0, r4
	movs r1, #0
_08025F2E:
	strb r1, [r0]
_08025F30:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r7
	blo _08025ECE
_08025F3A:
	ldr r0, _08025F64
	ldr r2, [r0]
	movs r5, #0xaa
	lsls r5, r5, #1
	adds r1, r2, r5
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #0
	bne _08025F68
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _08025F68
	bl StopMapMusic
	ldr r0, [r4]
	adds r0, r0, r5
	movs r1, #1
	b _08025F86
	.align 2, 0
_08025F64: .4byte 0x0202294C
_08025F68:
	ldr r0, [r4]
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08025F88
	movs r0, #0xb
	bl PlayFanfareByFanfareNum
	ldr r0, [r4]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r0, r3
	movs r1, #2
_08025F86:
	strb r1, [r0]
_08025F88:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08025E0C

	thumb_func_start sub_08025F94
sub_08025F94: @ 0x08025F94
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08025F94

	thumb_func_start sub_08025FAC
sub_08025FAC: @ 0x08025FAC
	push {lr}
	bl TransferPlttBuffer
	bl LoadOam
	bl ProcessSpriteCopyRequests
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08025FAC

	thumb_func_start sub_08025FC0
sub_08025FC0: @ 0x08025FC0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	bl IsMonShiny
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08025FC0

	thumb_func_start sub_08025FD4
sub_08025FD4: @ 0x08025FD4
	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl CreateTask
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08025FD4

	thumb_func_start sub_08025FE4
sub_08025FE4: @ 0x08025FE4
	push {lr}
	movs r1, #1
	bl CreateTask
	ldr r1, _08026004
	ldr r3, [r1]
	movs r2, #0
	strb r0, [r3, #4]
	ldr r0, [r1]
	strb r2, [r0, #0x10]
	ldr r0, [r1]
	strb r2, [r0, #0xc]
	ldr r0, [r1]
	strb r2, [r0, #0x14]
	pop {r0}
	bx r0
	.align 2, 0
_08026004: .4byte 0x0202294C
	thumb_func_end sub_08025FE4

	thumb_func_start sub_08026008
sub_08026008: @ 0x08026008
	push {r4, lr}
	ldr r2, _08026028
	ldr r1, [r2]
	ldrb r3, [r1, #0x18]
	movs r4, #0
	strb r3, [r1, #0x1c]
	ldr r1, [r2]
	strb r0, [r1, #0x18]
	ldr r0, [r2]
	strb r4, [r0, #0x10]
	ldr r0, [r2]
	strb r4, [r0, #0x14]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08026028: .4byte 0x0202294C
	thumb_func_end sub_08026008

	thumb_func_start sub_0802602C
sub_0802602C: @ 0x0802602C
	push {r4, lr}
	ldr r3, _08026060
	ldr r1, [r3]
	ldrb r0, [r1, #0x14]
	lsrs r2, r0, #2
	adds r0, #1
	strb r0, [r1, #0x14]
	cmp r2, #0
	beq _08026080
	ldr r3, [r3]
	ldrb r0, [r3, #0x14]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08026080
	ldr r1, _08026064
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	blo _08026068
	movs r0, #1
	b _08026082
	.align 2, 0
_08026060: .4byte 0x0202294C
_08026064: .4byte 0x082CB320
_08026068:
	lsls r4, r2, #3
	adds r1, r4, #0
	movs r0, #0x14
	bl SetGpuReg
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x18
	adds r1, r4, #0
	bl SetGpuReg
_08026080:
	movs r0, #0
_08026082:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802602C

	thumb_func_start sub_08026088
sub_08026088: @ 0x08026088
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r2, _080260E0
	ldr r0, [r2]
	adds r1, r0, #0
	adds r1, #0x44
	adds r0, #0x48
	ldrb r5, [r0]
	ldrb r1, [r1]
	cmp r1, r5
	bhs _080260D4
	mov r8, r2
	ldr r0, _080260E4
	mov ip, r0
	movs r7, #0
	movs r6, #1
_080260AA:
	mov r2, r8
	ldr r0, [r2]
	mov r2, ip
	adds r4, r0, r2
	ldr r2, _080260E8
	adds r0, r0, r2
	adds r2, r0, r1
	movs r3, #0
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _080260C4
	movs r3, #1
_080260C4:
	strb r3, [r2]
	adds r0, r4, r1
	strb r7, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r5
	blo _080260AA
_080260D4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080260E0: .4byte 0x0202294C
_080260E4: .4byte 0x000032E0
_080260E8: .4byte 0x000032EB
	thumb_func_end sub_08026088

	thumb_func_start sub_080260EC
sub_080260EC: @ 0x080260EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _080261C0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x44
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r1, #0
	adds r0, #0x48
	ldrb r0, [r0]
	str r0, [sp, #4]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	str r0, [sp, #8]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _08026120
	b _080263DC
_08026120:
	movs r6, #0
	ldr r0, [sp, #8]
	cmp r6, r0
	bhs _08026208
_08026128:
	ldr r3, _080261C0
	lsls r0, r6, #4
	subs r1, r0, r6
	lsls r1, r1, #2
	ldr r2, [r3]
	adds r1, r1, r2
	ldr r4, _080261C4
	adds r4, r4, r1
	mov r8, r4
	ldrb r1, [r4]
	mov sb, r0
	adds r0, r6, #1
	str r0, [sp, #0xc]
	cmp r1, #0
	beq _080261FC
	adds r0, r2, #0
	adds r0, #0xa8
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #1
	bne _080261FC
	ldr r1, [sp]
	mov sl, r1
	ldr r2, [sp, #4]
	cmp sl, r2
	bhs _080261FC
	adds r7, r3, #0
_0802615E:
	ldr r0, _080261C8
	add r0, sl
	ldrb r5, [r0]
	ldr r1, [r7]
	lsls r4, r5, #1
	adds r0, r1, #0
	adds r0, #0xf4
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, r6
	beq _080261FC
	adds r0, r1, #0
	adds r0, #0xf5
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, r6
	beq _080261FC
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r2, r5, #0
	bl sub_080263FC
	cmp r0, #1
	bne _080261D8
	movs r2, #0
	ldr r3, _080261C0
	mov r8, r4
_08026196:
	ldr r0, [r3]
	mov r4, r8
	adds r1, r2, r4
	adds r0, #0xf4
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080261CC
	strb r6, [r1]
	ldr r0, [r3]
	adds r0, #0xa8
	adds r0, r0, r6
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0xc4
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	b _080261FC
	.align 2, 0
_080261C0: .4byte 0x0202294C
_080261C4: .4byte 0x000031CC
_080261C8: .4byte 0x082C7D28
_080261CC:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #1
	bls _08026196
	b _080261FC
_080261D8:
	ldr r0, [r7]
	mov r2, sb
	subs r1, r2, r6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r4, _080262CC
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _080261FC
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r0, [sp, #4]
	cmp sl, r0
	blo _0802615E
_080261FC:
	ldr r1, [sp, #0xc]
	lsls r0, r1, #0x18
	lsrs r6, r0, #0x18
	ldr r2, [sp, #8]
	cmp r6, r2
	blo _08026128
_08026208:
	ldr r4, [sp]
	mov sl, r4
	ldr r0, [sp, #4]
	cmp sl, r0
	blo _08026214
	b _080263DC
_08026214:
	ldr r1, _080262D0
	mov sb, r1
_08026218:
	movs r6, #0xff
	ldr r0, _080262D4
	add r0, sl
	ldrb r5, [r0]
	mov r2, sb
	ldr r0, [r2]
	adds r0, #0xc4
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #1
	beq _08026230
	b _080263CA
_08026230:
	adds r0, r5, #0
	bl sub_08026B4C
	mov r1, sb
	ldr r4, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	adds r1, #0x90
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _08026256
	movs r3, #2
_08026256:
	ldr r2, _080262D8
	ldr r0, _080262DC
	adds r1, r4, r0
	adds r1, r1, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xd0
	adds r0, r0, r5
	ldrb r0, [r0]
	subs r2, r1, r0
	cmp r2, #5
	bgt _08026284
	adds r1, r4, #0
	adds r1, #0x9c
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, r0, r2
	strb r0, [r1]
_08026284:
	mov r2, sb
	ldr r1, [r2]
	adds r1, #0x9c
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r4, #0xff
	ands r0, r4
	cmp r0, #5
	bhi _0802629E
	b _080263CA
_0802629E:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x9c
	adds r0, r0, r5
	strb r2, [r0]
	ldr r3, [r1]
	lsls r1, r5, #1
	adds r0, r3, #0
	adds r0, #0xf4
	adds r2, r0, r1
	ldrb r0, [r2]
	mov r8, r1
	cmp r0, #0xff
	bne _080262E0
	adds r0, r3, #0
	adds r0, #0xf5
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080262C8
	b _080263CA
_080262C8:
	b _080262F0
	.align 2, 0
_080262CC: .4byte 0x000031D4
_080262D0: .4byte 0x0202294C
_080262D4: .4byte 0x082C7D28
_080262D8: .4byte 0x082CB314
_080262DC: .4byte 0x000031B4
_080262E0:
	adds r0, r3, #0
	adds r0, #0xf5
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080262F0
	ldrb r4, [r2]
	b _08026316
_080262F0:
	mov r2, sb
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0xf4
	add r0, r8
	ldrb r7, [r0]
	adds r1, #0xf5
	add r1, r8
	ldrb r6, [r1]
	bl Random
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	bne _08026312
	adds r4, r7, #0
	b _08026316
_08026312:
	adds r4, r6, #0
	adds r6, r7, #0
_08026316:
	mov r1, sb
	ldr r0, [r1]
	ldr r2, _080263EC
	adds r0, r0, r2
	adds r0, r0, r5
	movs r1, #7
	strb r1, [r0]
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0xc4
	adds r0, r0, r5
	movs r1, #2
	strb r1, [r0]
	mov r2, sb
	ldr r0, [r2]
	adds r0, #0xa8
	adds r0, r0, r4
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xb8
	adds r0, r0, r5
	strb r4, [r0]
	ldr r1, [r2]
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r2, _080263F0
	adds r1, r1, r2
	movs r0, #1
	strb r0, [r1]
	mov r2, sb
	ldr r1, [r2]
	lsls r0, r6, #4
	subs r0, r0, r6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, _080263F4
	adds r1, r1, r0
	movs r2, #1
	strb r2, [r1]
	mov r0, sb
	ldr r1, [r0]
	lsls r0, r4, #1
	adds r1, #0x86
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl sub_08026CDC
	movs r0, #1
	bl sub_08026FF4
	adds r0, r4, #0
	bl sub_08026ADC
	mov r1, sb
	ldr r0, [r1]
	adds r1, r0, #0
	adds r1, #0xe8
	adds r1, r1, r5
	ldr r2, _080263F8
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	mov r4, sb
	ldr r0, [r4]
	adds r0, r0, r2
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	ldr r1, [r4]
	adds r1, #0xf4
	add r1, r8
	ldrb r0, [r1]
	movs r2, #0xff
	orrs r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, #0xf5
	add r1, r8
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
_080263CA:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r4, [sp, #4]
	cmp sl, r4
	bhs _080263DC
	b _08026218
_080263DC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080263EC: .4byte 0x000032EB
_080263F0: .4byte 0x000031D0
_080263F4: .4byte 0x000031D4
_080263F8: .4byte 0x000032E0
	thumb_func_end sub_080260EC

	thumb_func_start sub_080263FC
sub_080263FC: @ 0x080263FC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r7, #0
	ldr r2, _08026430
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0x24
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _08026434
	adds r1, r1, r0
	mov ip, r2
	cmp r3, #2
	beq _08026438
	cmp r3, #2
	bgt _0802643E
	cmp r3, #1
	beq _0802643C
	b _0802643E
	.align 2, 0
_08026430: .4byte 0x0202294C
_08026434: .4byte 0x000032E0
_08026438:
	movs r7, #1
	b _0802643E
_0802643C:
	movs r7, #2
_0802643E:
	adds r0, r1, #0
	adds r0, #0xb
	adds r0, r0, r6
	ldrb r0, [r0]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0802649C
	ldr r0, _08026490
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r1, r7, r1
	lsls r2, r5, #4
	subs r2, r2, r5
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r1, [r1]
	cmp r6, r1
	bne _080264D2
	mov r0, ip
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0xc4
	adds r0, r0, r6
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08026498
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r1, r0
	ldr r1, _08026494
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	b _080264D2
	.align 2, 0
_08026490: .4byte 0x082C7E3B
_08026494: .4byte 0x000031D4
_08026498:
	movs r0, #1
	b _080264D4
_0802649C:
	ldr r0, _080264DC
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r1, r7, r1
	lsls r2, r5, #4
	subs r2, r2, r5
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r1, [r1]
	cmp r6, r1
	bne _080264D2
	mov r1, ip
	ldr r0, [r1]
	adds r0, #0xa8
	adds r0, r0, r4
	movs r1, #4
	strb r1, [r0]
	mov r0, ip
	ldr r1, [r0]
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, _080264E0
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
_080264D2:
	movs r0, #0
_080264D4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080264DC: .4byte 0x082C7E3B
_080264E0: .4byte 0x000031D4
	thumb_func_end sub_080263FC

	thumb_func_start sub_080264E4
sub_080264E4: @ 0x080264E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r2, _080265B8
	ldr r4, [r2]
	adds r0, r4, #0
	adds r0, #0x44
	ldrb r1, [r0]
	adds r0, #4
	ldrb r0, [r0]
	mov sb, r0
	movs r3, #0
	mov sl, r3
	movs r5, #0x90
	lsls r5, r5, #1
	adds r0, r4, r5
	str r3, [r0]
	adds r5, r1, #0
	mov r0, sb
	subs r0, #1
	cmp r5, r0
	blt _08026516
	b _08026734
_08026516:
	mov r8, r2
_08026518:
	mov r0, r8
	ldr r4, [r0]
	adds r0, r4, #0
	adds r0, #0xc4
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #1
	bls _0802652A
	b _08026634
_0802652A:
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #1
	str r2, [r0]
	ldr r1, _080265BC
	adds r0, r4, r1
	adds r6, r0, r5
	ldrb r0, [r6]
	cmp r0, #9
	bls _080265C4
	movs r7, #0
	movs r0, #0xa
	strb r0, [r6]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xc4
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	mov r1, r8
	ldr r0, [r1]
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r0, r0, r6
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0
	bne _08026574
	strb r2, [r1]
	ldr r2, _080265C0
	adds r0, r4, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, #0x4a
	bl PlaySE
_08026574:
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _0802658A
	mov r2, sl
	cmp r2, #1
	beq _0802658A
	b _08026724
_0802658A:
	movs r0, #1
	mov sl, r0
	adds r0, r1, r6
	adds r0, r0, r5
	strb r7, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r1, r0, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #9
	bhi _080265A6
	adds r0, #1
	strb r0, [r1]
_080265A6:
	movs r0, #3
	adds r1, r5, #0
	movs r2, #0
	bl sub_08026CDC
	movs r0, #0
	bl sub_08026FF4
	b _08026724
	.align 2, 0
_080265B8: .4byte 0x0202294C
_080265BC: .4byte 0x000032EB
_080265C0: .4byte 0x000032E0
_080265C4:
	adds r0, r5, #0
	bl sub_08026B4C
	mov r2, r8
	ldr r7, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	adds r1, #0x90
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _080265EA
	movs r3, #2
_080265EA:
	ldr r2, _0802662C
	ldr r0, _08026630
	adds r1, r4, r0
	adds r1, r1, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r2, [r0]
	adds r1, r7, #0
	adds r1, #0xd0
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r2
	blo _08026624
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xd0
	adds r0, r0, r5
	strb r3, [r0]
_08026624:
	bl sub_080260EC
	b _08026724
	.align 2, 0
_0802662C: .4byte 0x082CB314
_08026630: .4byte 0x000032E0
_08026634:
	cmp r0, #2
	bne _080266B4
	adds r1, r4, #0
	adds r1, #0xdc
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _08026724
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0xb8
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r1, _080266A8
	adds r2, r2, r1
	strb r3, [r2]
	mov r2, r8
	ldr r0, [r2]
	adds r0, #0xdc
	adds r0, r0, r5
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #0xd0
	adds r0, r0, r5
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #0xc4
	adds r0, r0, r5
	strb r3, [r0]
	ldr r1, _080266AC
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	adds r0, r5, #0
	bl sub_08026B4C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r5, #0
	bl sub_08026B70
	ldr r2, _080266B0
	adds r1, r4, r2
	adds r1, r1, r5
	strb r0, [r1]
	b _08026724
	.align 2, 0
_080266A8: .4byte 0x000031D0
_080266AC: .4byte 0x000032EB
_080266B0: .4byte 0x000032E0
_080266B4:
	cmp r0, #3
	bne _08026724
	adds r1, r4, #0
	adds r1, #0xdc
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _08026724
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bhi _08026724
	adds r0, r1, #0
	adds r0, #0xdc
	adds r0, r0, r5
	strb r2, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xd0
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, #0xc4
	adds r0, r0, r5
	strb r2, [r0]
	ldr r2, _08026744
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0xe8
	adds r1, r1, r5
	subs r2, #0xb
	adds r4, r4, r2
	adds r4, r4, r5
	ldrb r0, [r4]
	strb r0, [r1]
	adds r0, r5, #0
	bl sub_08026B4C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r5, #0
	bl sub_08026B70
	strb r0, [r4]
_08026724:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r0, sb
	subs r0, #1
	cmp r5, r0
	bge _08026734
	b _08026518
_08026734:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026744: .4byte 0x000032EB
	thumb_func_end sub_080264E4

	thumb_func_start sub_08026748
sub_08026748: @ 0x08026748
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080267B0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x44
	adds r0, #0x48
	ldrb r0, [r0]
	mov r8, r0
	ldrb r6, [r1]
	cmp r6, r8
	bhs _0802683A
	ldr r0, _080267B4
	mov sb, r0
_08026768:
	ldr r0, _080267B0
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x28
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _080267B8
	adds r0, r0, r2
	adds r7, r3, r0
	movs r0, #0xb
	adds r2, r1, #0
	muls r2, r0, r2
	adds r2, r6, r2
	adds r3, #0x24
	ldrb r1, [r3]
	subs r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r0, r0, r1
	adds r2, r2, r0
	add r2, sb
	ldrb r4, [r2]
	adds r0, r7, #0
	adds r0, #0x1f
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080267BC
	adds r0, r6, #0
	movs r1, #0
	bl sub_08028924
	b _080267C4
	.align 2, 0
_080267B0: .4byte 0x0202294C
_080267B4: .4byte 0x082C7D28
_080267B8: .4byte 0x000031A0
_080267BC:
	adds r0, r6, #0
	movs r1, #1
	bl sub_08028924
_080267C4:
	adds r0, r7, #0
	adds r0, #0x1f
	adds r5, r0, r4
	ldrb r0, [r5]
	cmp r0, #9
	bls _080267F0
	adds r0, r7, #0
	adds r0, #0x14
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r1, #3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl sub_080289D0
	ldrb r1, [r5]
	lsls r1, r1, #0x19
	movs r0, #0xff
	lsls r0, r0, #0x18
	adds r1, r1, r0
	b _08026812
_080267F0:
	adds r0, r7, #0
	adds r0, #0x14
	adds r3, r0, r4
	ldrb r0, [r3]
	cmp r0, #3
	bne _0802681C
	movs r0, #7
	strb r0, [r5]
	adds r0, r6, #0
	movs r1, #6
	bl sub_080289D0
	ldrb r1, [r5]
	lsls r1, r1, #0x19
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r1, r1, r2
_08026812:
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl sub_080289A8
	b _08026830
_0802681C:
	ldrb r1, [r3]
	adds r0, r6, #0
	bl sub_080289D0
	ldrb r1, [r5]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl sub_080289A8
_08026830:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r8
	blo _08026768
_0802683A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08026748

	thumb_func_start sub_08026848
sub_08026848: @ 0x08026848
	push {r4, r5, r6, lr}
	ldr r1, _08026880
	ldr r0, [r1]
	adds r0, #0x24
	ldrb r5, [r0]
	movs r4, #0
	cmp r4, r5
	bhs _0802687A
	adds r6, r1, #0
_0802685A:
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #2
	ldr r1, [r6]
	adds r0, r0, r1
	ldr r1, _08026884
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl sub_080283E0
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r5
	blo _0802685A
_0802687A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026880: .4byte 0x0202294C
_08026884: .4byte 0x000031CC
	thumb_func_end sub_08026848

	thumb_func_start sub_08026888
sub_08026888: @ 0x08026888
	push {r4, r5, lr}
	ldr r0, _080268B0
	ldr r0, [r0]
	adds r0, #0x24
	ldrb r5, [r0]
	movs r4, #0
	cmp r4, r5
	bhs _080268AA
_08026898:
	adds r0, r4, #0
	movs r1, #4
	bl sub_080283E0
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r5
	blo _08026898
_080268AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080268B0: .4byte 0x0202294C
	thumb_func_end sub_08026888

	thumb_func_start sub_080268B4
sub_080268B4: @ 0x080268B4
	push {lr}
	bl sub_08026748
	ldr r0, _080268CC
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _080268D0
	bl sub_08026888
	b _080268D4
	.align 2, 0
_080268CC: .4byte 0x0202294C
_080268D0:
	bl sub_08026848
_080268D4:
	ldr r0, _080268E4
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	bl sub_08028600
	pop {r0}
	bx r0
	.align 2, 0
_080268E4: .4byte 0x0202294C
	thumb_func_end sub_080268B4

	thumb_func_start sub_080268E8
sub_080268E8: @ 0x080268E8
	push {lr}
	bl sub_08026748
	ldr r0, _08026900
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _08026904
	bl sub_08026888
	b _08026908
	.align 2, 0
_08026900: .4byte 0x0202294C
_08026904:
	bl sub_08026848
_08026908:
	ldr r0, _08026918
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	bl sub_08028600
	pop {r0}
	bx r0
	.align 2, 0
_08026918: .4byte 0x0202294C
	thumb_func_end sub_080268E8

	thumb_func_start sub_0802691C
sub_0802691C: @ 0x0802691C
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #4
	bhi _08026974
	lsls r0, r0, #2
	ldr r1, _08026934
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026934: .4byte 0x08026938
_08026938: @ jump table
	.4byte _0802694C @ case 0
	.4byte _08026954 @ case 1
	.4byte _0802695C @ case 2
	.4byte _08026964 @ case 3
	.4byte _0802696C @ case 4
_0802694C:
	movs r0, #4
	strb r0, [r3]
	movs r0, #7
	b _08026972
_08026954:
	movs r0, #3
	strb r0, [r3]
	movs r0, #8
	b _08026972
_0802695C:
	movs r0, #2
	strb r0, [r3]
	movs r0, #9
	b _08026972
_08026964:
	movs r0, #1
	strb r0, [r3]
	movs r0, #0xa
	b _08026972
_0802696C:
	movs r0, #0
	strb r0, [r3]
	movs r0, #0xb
_08026972:
	strb r0, [r2]
_08026974:
	pop {r0}
	bx r0
	thumb_func_end sub_0802691C
