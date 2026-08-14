.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

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
