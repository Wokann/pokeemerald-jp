.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start SetContestantEffectStringID2
SetContestantEffectStringID2: @ 0x080DCB54
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DCB6C
	ldr r2, [r2]
	ldr r3, [r2, #4]
	lsls r2, r0, #3
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r3
	strb r1, [r2, #0x14]
	bx lr
	.align 2, 0
_080DCB6C: .4byte 0x02039BD4
	thumb_func_end SetContestantEffectStringID2

	thumb_func_start SetStartledString
SetStartledString: @ 0x080DCB70
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r2, r1, #0
	cmp r1, #0x3b
	bls _080DCB8A
	movs r1, #0x35
	bl SetContestantEffectStringID
	b _080DCBBA
_080DCB8A:
	cmp r1, #0x27
	bls _080DCB96
	movs r1, #0x34
	bl SetContestantEffectStringID
	b _080DCBBA
_080DCB96:
	cmp r1, #0x1d
	bls _080DCBA2
	movs r1, #0x33
	bl SetContestantEffectStringID
	b _080DCBBA
_080DCBA2:
	cmp r1, #0x13
	bls _080DCBAE
	movs r1, #0x32
	bl SetContestantEffectStringID
	b _080DCBBA
_080DCBAE:
	cmp r2, #9
	bls _080DCBBA
	adds r0, r3, #0
	movs r1, #0x31
	bl SetContestantEffectStringID
_080DCBBA:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SetStartledString

	thumb_func_start sub_080DCBC0
sub_080DCBC0: @ 0x080DCBC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	ldr r0, _080DCC20
	lsls r1, r4, #6
	ldr r2, _080DCC24
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _080DCC28
	ldr r5, _080DCC2C
	ldr r1, [r5]
	ldr r2, [r1, #4]
	lsls r1, r4, #3
	subs r1, r1, r4
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1, #6]
	lsls r1, r1, #3
	ldr r2, _080DCC30
	adds r1, r1, r2
	bl StringCopy
	ldr r3, _080DCC34
	ldr r1, [r5]
	ldr r0, [r1, #8]
	ldrb r2, [r0, #0x11]
	ldr r1, [r1, #4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #6]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrb r0, [r0, #1]
	lsls r1, r0, #0x1d
	cmp r1, #0
	bne _080DCC40
	ldr r0, _080DCC38
	ldr r1, _080DCC3C
	bl StringCopy
	b _080DCC90
	.align 2, 0
_080DCC20: .4byte 0x02021C40
_080DCC24: .4byte 0x02039AA2
_080DCC28: .4byte 0x02021C54
_080DCC2C: .4byte 0x02039BD4
_080DCC30: .4byte 0x082EACC4
_080DCC34: .4byte 0x08565FCC
_080DCC38: .4byte 0x02021C68
_080DCC3C: .4byte 0x0824C0D2
_080DCC40:
	lsrs r0, r1, #0x1d
	cmp r0, #1
	bne _080DCC58
	ldr r0, _080DCC50
	ldr r1, _080DCC54
	bl StringCopy
	b _080DCC90
	.align 2, 0
_080DCC50: .4byte 0x02021C68
_080DCC54: .4byte 0x0824C0D7
_080DCC58:
	lsrs r0, r1, #0x1d
	cmp r0, #2
	bne _080DCC70
	ldr r0, _080DCC68
	ldr r1, _080DCC6C
	bl StringCopy
	b _080DCC90
	.align 2, 0
_080DCC68: .4byte 0x02021C68
_080DCC6C: .4byte 0x0824C0DC
_080DCC70:
	lsrs r0, r1, #0x1d
	cmp r0, #3
	bne _080DCC88
	ldr r0, _080DCC80
	ldr r1, _080DCC84
	bl StringCopy
	b _080DCC90
	.align 2, 0
_080DCC80: .4byte 0x02021C68
_080DCC84: .4byte 0x0824C0E1
_080DCC88:
	ldr r0, _080DCCB4
	ldr r1, _080DCCB8
	bl StringCopy
_080DCC90:
	ldr r4, _080DCCBC
	ldr r1, _080DCCC0
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl StringExpandPlaceholders
	bl sub_080DB000
	adds r0, r4, #0
	movs r1, #1
	bl Contest_StartTextPrinter
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DCCB4: .4byte 0x02021C68
_080DCCB8: .4byte 0x0824C0E6
_080DCCBC: .4byte 0x02021C7C
_080DCCC0: .4byte 0x08560D74
	thumb_func_end sub_080DCBC0

	thumb_func_start MakeContestantNervous
MakeContestantNervous: @ 0x080DCCC4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _080DCCF0
	ldr r1, [r4]
	ldr r3, [r1, #4]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r3, r1, r3
	ldrb r0, [r3, #0xc]
	movs r2, #1
	orrs r0, r2
	strb r0, [r3, #0xc]
	ldr r0, [r4]
	ldr r0, [r0, #4]
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1, #6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DCCF0: .4byte 0x02039BD4
	thumb_func_end MakeContestantNervous

	thumb_func_start ApplyNextTurnOrder
ApplyNextTurnOrder: @ 0x080DCCF4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r0, #0
	mov ip, r0
	movs r4, #0
	ldr r1, _080DCD60
	mov sb, r1
	add r2, sp, #4
	mov r6, sb
	movs r5, #0
	adds r3, r2, #0
_080DCD10:
	mov r0, sp
	adds r1, r0, r4
	adds r0, r4, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r4
	strb r5, [r0]
	adds r4, #1
	cmp r4, #3
	ble _080DCD10
	movs r4, #0
	ldr r7, _080DCD64
	ldr r1, [r7]
	mov r8, r1
	adds r5, r2, #0
_080DCD2E:
	movs r2, #0
	mov r0, r8
	ldr r1, [r0, #4]
_080DCD34:
	ldrb r0, [r1, #0x19]
	cmp r0, r4
	beq _080DCD68
	adds r1, #0x1c
	adds r2, #1
	cmp r2, #3
	ble _080DCD34
_080DCD42:
	cmp r2, #4
	bne _080DCDE8
	movs r2, #0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080DCD76
	ldr r0, [r7]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x19]
	cmp r0, #0xff
	bne _080DCD76
	mov ip, r2
	movs r2, #1
	b _080DCD9E
	.align 2, 0
_080DCD60: .4byte 0x02039BC6
_080DCD64: .4byte 0x02039BD4
_080DCD68:
	mov r1, sp
	adds r0, r1, r2
	strb r4, [r0]
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080DCD42
_080DCD76:
	adds r2, #1
	cmp r2, #3
	bgt _080DCDDA
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DCD76
	ldr r0, [r7]
	ldr r1, [r0, #4]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #0x19]
	cmp r0, #0xff
	bne _080DCD76
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	adds r2, #1
_080DCD9E:
	cmp r2, #3
	bgt _080DCDDA
	ldr r6, _080DCE38
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r3, r0, #2
_080DCDAA:
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DCDD2
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r3, r0
	ldrb r0, [r0, #0x19]
	cmp r0, #0xff
	bne _080DCDD2
	mov r1, ip
	adds r0, r1, r6
	adds r1, r2, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080DCDD2
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
_080DCDD2:
	adds r3, #0x1c
	adds r2, #1
	cmp r2, #3
	ble _080DCDAA
_080DCDDA:
	mov r0, sp
	add r0, ip
	strb r4, [r0]
	mov r0, ip
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080DCDE8:
	adds r4, #1
	cmp r4, #3
	ble _080DCD2E
	movs r4, #0
	ldr r6, _080DCE3C
	movs r5, #0
_080DCDF4:
	ldr r0, [r6]
	ldr r1, [r0, #8]
	adds r1, r1, r4
	mov r0, sp
	adds r3, r0, r4
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r0, [r6]
	ldr r0, [r0, #4]
	adds r0, r5, r0
	movs r1, #0xff
	strb r1, [r0, #0x19]
	ldr r0, [r6]
	ldr r1, [r0, #4]
	adds r1, r5, r1
	ldrb r2, [r1, #0x10]
	movs r0, #0x3f
	ands r0, r2
	strb r0, [r1, #0x10]
	mov r0, sb
	adds r1, r4, r0
	ldrb r0, [r3]
	strb r0, [r1]
	adds r5, #0x1c
	adds r4, #1
	cmp r4, #3
	ble _080DCDF4
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DCE38: .4byte 0x02039BC6
_080DCE3C: .4byte 0x02039BD4
	thumb_func_end ApplyNextTurnOrder

	thumb_func_start sub_080DCE40
sub_080DCE40: @ 0x080DCE40
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x30]
	adds r1, r0, #1
	strh r1, [r2, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x54
	ble _080DCE76
	movs r0, #0
	strh r0, [r2, #0x30]
	adds r3, r2, #0
	adds r3, #0x3e
	ldrb r0, [r3]
	movs r1, #4
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _080DCE7C
	str r0, [r2, #0x1c]
	ldr r0, _080DCE80
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #6]
_080DCE76:
	pop {r0}
	bx r0
	.align 2, 0
_080DCE7C: .4byte 0x08007141
_080DCE80: .4byte 0x02039BD4
	thumb_func_end sub_080DCE40

	thumb_func_start sub_080DCE84
sub_080DCE84: @ 0x080DCE84
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, _080DCEA4
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r5, [r0, #0x12]
	cmp r1, #8
	bls _080DCE98
	b _080DD038
_080DCE98:
	lsls r0, r1, #2
	ldr r1, _080DCEA8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DCEA4: .4byte 0x02039BD4
_080DCEA8: .4byte 0x080DCEAC
_080DCEAC: @ jump table
	.4byte _080DCED0 @ case 0
	.4byte _080DCED0 @ case 1
	.4byte _080DCF00 @ case 2
	.4byte _080DCF34 @ case 3
	.4byte _080DCF68 @ case 4
	.4byte _080DCF9C @ case 5
	.4byte _080DCFD0 @ case 6
	.4byte _080DD038 @ case 7
	.4byte _080DD004 @ case 8
_080DCED0:
	ldr r0, _080DCEF4
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #0x2e]
	ldr r2, _080DCEF8
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCEFC
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x20
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCEF4: .4byte 0x020205AC
_080DCEF8: .4byte 0x000003FF
_080DCEFC: .4byte 0xFFFFFC00
_080DCF00:
	ldr r0, _080DCF28
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #4
	ldr r3, _080DCF2C
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCF30
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x1f
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCF28: .4byte 0x020205AC
_080DCF2C: .4byte 0x000003FF
_080DCF30: .4byte 0xFFFFFC00
_080DCF34:
	ldr r0, _080DCF5C
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #8
	ldr r3, _080DCF60
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCF64
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x1f
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCF5C: .4byte 0x020205AC
_080DCF60: .4byte 0x000003FF
_080DCF64: .4byte 0xFFFFFC00
_080DCF68:
	ldr r0, _080DCF90
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0xc
	ldr r3, _080DCF94
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCF98
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x2d
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCF90: .4byte 0x020205AC
_080DCF94: .4byte 0x000003FF
_080DCF98: .4byte 0xFFFFFC00
_080DCF9C:
	ldr r0, _080DCFC4
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0xc
	ldr r3, _080DCFC8
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DCFCC
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x2d
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCFC4: .4byte 0x020205AC
_080DCFC8: .4byte 0x000003FF
_080DCFCC: .4byte 0xFFFFFC00
_080DCFD0:
	ldr r0, _080DCFF8
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0x10
	ldr r3, _080DCFFC
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DD000
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x2d
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DCFF8: .4byte 0x020205AC
_080DCFFC: .4byte 0x000003FF
_080DD000: .4byte 0xFFFFFC00
_080DD004:
	ldr r0, _080DD02C
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0x18
	ldr r3, _080DD030
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DD034
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0xc3
	bl PlaySE
	b _080DD05C
	.align 2, 0
_080DD02C: .4byte 0x020205AC
_080DD030: .4byte 0x000003FF
_080DD034: .4byte 0xFFFFFC00
_080DD038:
	ldr r0, _080DD090
	lsls r4, r5, #4
	adds r1, r4, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r1, #0x2e]
	adds r2, #0x14
	ldr r3, _080DD094
	adds r0, r3, #0
	ands r2, r0
	ldrh r3, [r1, #4]
	ldr r0, _080DD098
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, #4]
	movs r0, #0x2d
	bl PlaySE
_080DD05C:
	adds r2, r4, #0
	ldr r4, _080DD090
	adds r2, r2, r5
	lsls r2, r2, #2
	adds r1, r2, r4
	movs r0, #0
	strh r0, [r1, #0x30]
	adds r1, #0x3e
	ldrb r3, [r1]
	subs r0, #5
	ands r0, r3
	strb r0, [r1]
	adds r4, #0x1c
	adds r2, r2, r4
	ldr r0, _080DD09C
	str r0, [r2]
	ldr r0, _080DD0A0
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #6]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD090: .4byte 0x020205AC
_080DD094: .4byte 0x000003FF
_080DD098: .4byte 0xFFFFFC00
_080DD09C: .4byte 0x080DCE41
_080DD0A0: .4byte 0x02039BD4
	thumb_func_end sub_080DCE84

	thumb_func_start UpdateApplauseMeter
UpdateApplauseMeter: @ 0x080DD0A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r5, #0
	ldr r6, _080DD140
	ldr r0, _080DD144
	mov sb, r0
	ldr r0, _080DD148
	mov r8, r0
	ldr r7, _080DD14C
_080DD0BA:
	ldr r0, [r6]
	ldr r1, [r0]
	movs r0, #0x13
	ldrsb r0, [r1, r0]
	ldr r4, _080DD150
	cmp r5, r0
	bge _080DD0CA
	adds r4, #0x40
_080DD0CA:
	adds r0, r1, #0
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sb
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	adds r0, r5, #0
	adds r0, #0x11
	adds r1, r1, r0
	lsls r1, r1, #5
	add r1, r8
	adds r0, r4, #0
	adds r2, r7, #0
	bl CpuSet
	adds r0, r4, #0
	adds r0, #0x20
	ldr r1, [r6]
	ldr r1, [r1]
	adds r1, #0x58
	ldrb r2, [r1]
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	add r1, sb
	ldrh r1, [r1, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	adds r2, r5, #0
	adds r2, #0x19
	adds r1, r1, r2
	lsls r1, r1, #5
	add r1, r8
	adds r2, r7, #0
	bl CpuSet
	ldr r0, [r6]
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	ble _080DD12C
	bl StartApplauseOverflowAnimation
_080DD12C:
	adds r5, #1
	cmp r5, #4
	ble _080DD0BA
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD140: .4byte 0x02039BD4
_080DD144: .4byte 0x020205AC
_080DD148: .4byte 0x06010000
_080DD14C: .4byte 0x04000008
_080DD150: .4byte 0x08D8EBD8
	thumb_func_end UpdateApplauseMeter

	thumb_func_start Contest_GetMoveExcitement
Contest_GetMoveExcitement: @ 0x080DD154
	lsls r0, r0, #0x10
	ldr r3, _080DD178
	ldr r1, _080DD17C
	lsrs r0, r0, #0xd
	adds r0, r0, r1
	ldrb r1, [r0, #1]
	lsls r1, r1, #0x1d
	lsrs r1, r1, #0x1d
	ldr r0, _080DD180
	ldrh r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r2
	adds r1, r1, r0
	adds r1, r1, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	bx lr
	.align 2, 0
_080DD178: .4byte 0x08562970
_080DD17C: .4byte 0x08565FCC
_080DD180: .4byte 0x02039BCC
	thumb_func_end Contest_GetMoveExcitement

	thumb_func_start StartApplauseOverflowAnimation
StartApplauseOverflowAnimation: @ 0x080DD184
	push {r4, r5, lr}
	ldr r0, _080DD1B8
	movs r1, #0xa
	bl CreateTask
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _080DD1BC
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	adds r4, r4, r0
	movs r0, #1
	strh r0, [r4, #0xa]
	ldr r0, _080DD1C0
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0xc]
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1B8: .4byte 0x080DD1C5
_080DD1BC: .4byte 0x03005B60
_080DD1C0: .4byte 0x0000ABE2
	thumb_func_end StartApplauseOverflowAnimation

	thumb_func_start Task_ApplauseOverflowAnimation
Task_ApplauseOverflowAnimation: @ 0x080DD1C4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _080DD1F4
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r2, r0, r1
	ldrh r0, [r2, #8]
	adds r0, #1
	strh r0, [r2, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _080DD262
	movs r0, #0
	strh r0, [r2, #8]
	movs r3, #0xe
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _080DD1F8
	ldrh r0, [r2, #0x10]
	adds r0, #1
	b _080DD1FC
	.align 2, 0
_080DD1F4: .4byte 0x03005B60
_080DD1F8:
	ldrh r0, [r2, #0x10]
	subs r0, #1
_080DD1FC:
	strh r0, [r2, #0x10]
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	movs r3, #0x84
	lsls r3, r3, #1
	adds r6, r3, #0
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r2, [r4, #0x10]
	ldr r3, _080DD268
	movs r1, #1
	bl BlendPalette
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _080DD22E
	cmp r0, #0x10
	bne _080DD262
_080DD22E:
	ldrh r0, [r4, #0xe]
	movs r1, #1
	eors r0, r1
	strh r0, [r4, #0xe]
	ldr r0, _080DD26C
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bgt _080DD262
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	lsls r0, r0, #4
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	movs r2, #0
	movs r3, #0x1f
	bl BlendPalette
	adds r0, r5, #0
	bl DestroyTask
_080DD262:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DD268: .4byte 0x00007FFF
_080DD26C: .4byte 0x02039BD4
	thumb_func_end Task_ApplauseOverflowAnimation

	thumb_func_start StartMoveApplauseMeterOnscreen
StartMoveApplauseMeterOnscreen: @ 0x080DD270
	push {r4, lr}
	ldr r0, _080DD2C0
	movs r1, #0xa
	bl CreateTask
	ldr r3, _080DD2C4
	ldr r4, _080DD2C8
	ldr r2, [r4]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, _080DD2CC
	strh r1, [r0, #0x24]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r0, [r2, #6]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DD2C0: .4byte 0x080DD2D1
_080DD2C4: .4byte 0x020205AC
_080DD2C8: .4byte 0x02039BD4
_080DD2CC: .4byte 0x0000FFBA
	thumb_func_end StartMoveApplauseMeterOnscreen

	thumb_func_start Task_MoveApplauseMeterOnscreen
Task_MoveApplauseMeterOnscreen: @ 0x080DD2D0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	ldr r4, _080DD340
	ldr r0, [r4]
	ldr r0, [r0]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DD344
	adds r2, r0, r1
	ldr r0, _080DD348
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r5, #0xd0
	lsls r5, r5, #3
	adds r0, r5, #0
	ldrh r5, [r1, #0x1c]
	adds r0, r0, r5
	strh r0, [r1, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r5, [r2, #0x24]
	adds r0, r0, r5
	strh r0, [r2, #0x24]
	ldrb r0, [r1, #0x1c]
	strh r0, [r1, #0x1c]
	movs r1, #0x24
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _080DD31C
	movs r0, #0
	strh r0, [r2, #0x24]
_080DD31C:
	movs r5, #0x24
	ldrsh r0, [r2, r5]
	cmp r0, #0
	bne _080DD338
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #6]
	adds r0, r3, #0
	bl DestroyTask
_080DD338:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD340: .4byte 0x02039BD4
_080DD344: .4byte 0x020205AC
_080DD348: .4byte 0x03005B60
	thumb_func_end Task_MoveApplauseMeterOnscreen

	thumb_func_start TryMoveApplauseMeterOffscreen
TryMoveApplauseMeterOffscreen: @ 0x080DD34C
	push {r4, r5, lr}
	ldr r5, _080DD378
	ldr r4, _080DD37C
	ldr r0, [r4]
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x3e
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _080DD380
	ldrb r1, [r2, #6]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	b _080DD3A4
	.align 2, 0
_080DD378: .4byte 0x020205AC
_080DD37C: .4byte 0x02039BD4
_080DD380:
	ldr r0, _080DD3AC
	movs r1, #0xa
	bl CreateTask
	ldr r2, [r4]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0
	strh r1, [r0, #0x24]
	ldr r2, [r2]
	ldrb r0, [r2, #6]
	movs r1, #0x40
	orrs r0, r1
_080DD3A4:
	strb r0, [r2, #6]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD3AC: .4byte 0x080DD3B1
	thumb_func_end TryMoveApplauseMeterOffscreen

	thumb_func_start Task_MoveApplauseMeterOffscreen
Task_MoveApplauseMeterOffscreen: @ 0x080DD3B0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	ldr r5, _080DD430
	ldr r0, [r5]
	ldr r0, [r0]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DD434
	adds r3, r0, r1
	ldr r0, _080DD438
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #3
	adds r2, r2, r0
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r1, #0
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r1, [r3, #0x24]
	subs r1, r1, r0
	strh r1, [r3, #0x24]
	ldrb r0, [r2, #0x1c]
	strh r0, [r2, #0x1c]
	movs r2, #0x24
	ldrsh r0, [r3, r2]
	movs r1, #0x46
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080DD400
	ldr r0, _080DD43C
	strh r0, [r3, #0x24]
_080DD400:
	movs r2, #0x24
	ldrsh r0, [r3, r2]
	cmp r0, r1
	bne _080DD428
	adds r2, r3, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #6]
	adds r0, r4, #0
	bl DestroyTask
_080DD428:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD430: .4byte 0x02039BD4
_080DD434: .4byte 0x020205AC
_080DD438: .4byte 0x03005B60
_080DD43C: .4byte 0x0000FFBA
	thumb_func_end Task_MoveApplauseMeterOffscreen

	thumb_func_start ShowAndUpdateApplauseMeter
ShowAndUpdateApplauseMeter: @ 0x080DD440
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _080DD478
	movs r1, #5
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DD47C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	strh r4, [r1, #8]
	ldr r0, _080DD480
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #6]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2, #6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DD478: .4byte 0x080DD485
_080DD47C: .4byte 0x03005B60
_080DD480: .4byte 0x02039BD4
	thumb_func_end ShowAndUpdateApplauseMeter

	thumb_func_start Task_ShowAndUpdateApplauseMeter
Task_ShowAndUpdateApplauseMeter: @ 0x080DD484
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _080DD4A8
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _080DD4B8
	cmp r0, #1
	bgt _080DD4AC
	cmp r0, #0
	beq _080DD4B2
	b _080DD500
	.align 2, 0
_080DD4A8: .4byte 0x03005B60
_080DD4AC:
	cmp r0, #2
	beq _080DD4D4
	b _080DD500
_080DD4B2:
	bl StartMoveApplauseMeterOnscreen
	b _080DD4C8
_080DD4B8:
	ldr r0, _080DD4D0
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, #6]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _080DD500
_080DD4C8:
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
	b _080DD500
	.align 2, 0
_080DD4D0: .4byte 0x02039BD4
_080DD4D4:
	ldrh r0, [r4, #0x1e]
	adds r1, r0, #1
	strh r1, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _080DD500
	movs r0, #0
	strh r0, [r4, #0x1e]
	bl UpdateApplauseMeter
	ldr r0, _080DD508
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #6]
	adds r0, r5, #0
	bl DestroyTask
_080DD500:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD508: .4byte 0x02039BD4
	thumb_func_end Task_ShowAndUpdateApplauseMeter

	thumb_func_start HideApplauseMeterNoAnim
HideApplauseMeterNoAnim: @ 0x080DD50C
	ldr r3, _080DD540
	ldr r0, _080DD544
	ldr r2, [r0]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #0
	strh r1, [r0, #0x24]
	ldr r0, [r2]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080DD540: .4byte 0x020205AC
_080DD544: .4byte 0x02039BD4
	thumb_func_end HideApplauseMeterNoAnim

	thumb_func_start ShowApplauseMeterNoAnim
ShowApplauseMeterNoAnim: @ 0x080DD548
	ldr r2, _080DD568
	ldr r0, _080DD56C
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, #0x58
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080DD568: .4byte 0x020205AC
_080DD56C: .4byte 0x02039BD4
	thumb_func_end ShowApplauseMeterNoAnim

	thumb_func_start sub_080DD570
sub_080DD570: @ 0x080DD570
	push {lr}
	ldr r0, _080DD58C
	movs r1, #0xf
	bl CreateTask
	ldr r0, _080DD590
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #6]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #6]
	pop {r0}
	bx r0
	.align 2, 0
_080DD58C: .4byte 0x080DD595
_080DD590: .4byte 0x02039BD4
	thumb_func_end sub_080DD570

	thumb_func_start sub_080DD594
sub_080DD594: @ 0x080DD594
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _080DD5D0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	ldrh r0, [r4, #0x1c]
	adds r1, r0, #1
	strh r1, [r4, #0x1c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #6
	ble _080DD61E
	movs r0, #0
	strh r0, [r4, #0x1c]
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _080DD5DC
	ldr r0, _080DD5D4
	ldr r1, _080DD5D8
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #1
	bl RequestDma3Copy
	b _080DD5F0
	.align 2, 0
_080DD5D0: .4byte 0x03005B60
_080DD5D4: .4byte 0x02019000
_080DD5D8: .4byte 0x06002000
_080DD5DC:
	ldr r0, _080DD624
	ldr r1, _080DD628
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #1
	bl RequestDma3Copy
	ldrh r0, [r4, #0x20]
	adds r0, #1
	strh r0, [r4, #0x20]
_080DD5F0:
	ldr r1, _080DD62C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #0x1e]
	movs r2, #1
	eors r1, r2
	strh r1, [r0, #0x1e]
	movs r1, #0x20
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _080DD61E
	ldr r0, _080DD630
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #6]
	adds r0, r5, #0
	bl DestroyTask
_080DD61E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD624: .4byte 0x02018000
_080DD628: .4byte 0x06002000
_080DD62C: .4byte 0x03005B60
_080DD630: .4byte 0x02039BD4
	thumb_func_end sub_080DD594

	thumb_func_start sub_080DD634
sub_080DD634: @ 0x080DD634
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080DD674
	movs r1, #0xa
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r4, r4, #0x18
	cmp r4, #0
	ble _080DD69C
	ldr r7, _080DD678
	lsls r0, r5, #0x18
	adds r4, r0, #0
	cmp r4, #0
	ble _080DD680
	movs r5, #0
	ldr r2, _080DD67C
	ldr r0, [r2]
	ldr r0, [r0]
	movs r1, #0x13
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	b _080DD6B2
	.align 2, 0
_080DD674: .4byte 0x080DD6E5
_080DD678: .4byte 0x0000237E
_080DD67C: .4byte 0x02039BD4
_080DD680:
	ldr r2, _080DD698
	ldr r0, [r2]
	ldr r0, [r0]
	movs r1, #0x13
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r3, #0
	b _080DD6B2
	.align 2, 0
_080DD698: .4byte 0x02039BD4
_080DD69C:
	movs r7, #0
	lsls r0, r5, #0x18
	adds r4, r0, #0
	cmp r4, #0
	ble _080DD6AC
	movs r5, #0
	movs r3, #0xc
	b _080DD6B0
_080DD6AC:
	movs r5, #0xc
	movs r3, #0
_080DD6B0:
	ldr r2, _080DD6DC
_080DD6B2:
	ldr r1, _080DD6E0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	strh r7, [r0, #8]
	strh r5, [r0, #0xa]
	asrs r1, r4, #0x18
	strh r1, [r0, #0xc]
	strh r3, [r0, #0xe]
	ldr r0, [r2]
	ldr r2, [r0]
	ldrb r1, [r2, #7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD6DC: .4byte 0x02039BD4
_080DD6E0: .4byte 0x03005B60
	thumb_func_end sub_080DD634

	thumb_func_start sub_080DD6E4
sub_080DD6E4: @ 0x080DD6E4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _080DD714
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r3, r0, r2
	ldrh r0, [r3, #0x1c]
	adds r1, r0, #1
	strh r1, [r3, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _080DD760
	movs r0, #0
	strh r0, [r3, #0x1c]
	movs r1, #0xc
	ldrsh r0, [r3, r1]
	cmp r0, #0
	ble _080DD718
	ldrh r0, [r3, #0xa]
	adds r0, #1
	b _080DD71C
	.align 2, 0
_080DD714: .4byte 0x03005B60
_080DD718:
	ldrh r0, [r3, #0xa]
	subs r0, #1
_080DD71C:
	strh r0, [r3, #0xa]
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	adds r4, r4, r2
	ldrb r2, [r4, #0xa]
	ldrh r3, [r4, #8]
	movs r0, #0x11
	movs r1, #1
	bl BlendPalette
	ldrb r2, [r4, #0xa]
	ldrh r3, [r4, #8]
	movs r0, #0x1a
	movs r1, #1
	bl BlendPalette
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	movs r2, #0xe
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _080DD760
	adds r0, r5, #0
	bl DestroyTask
	ldr r0, _080DD768
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, #7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #7]
_080DD760:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DD768: .4byte 0x02039BD4
	thumb_func_end sub_080DD6E4

	thumb_func_start sub_080DD76C
sub_080DD76C: @ 0x080DD76C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r5, #0
	ldr r0, _080DD808
	mov sb, r0
	mov r8, sb
	ldr r6, _080DD80C
	movs r4, #0
	movs r7, #0
_080DD78A:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r7, r0
	ldrb r1, [r0, #0x10]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _080DD820
	mov r2, sl
	cmp r2, #0
	beq _080DD820
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl GetTurnOrderNumberGfx
	mov r3, r8
	ldr r1, [r3]
	ldr r1, [r1, #0x14]
	adds r1, r4, r1
	ldrb r2, [r1, #1]
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r6
	ldrh r1, [r1, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	ldr r2, _080DD810
	adds r1, r1, r2
	ldr r2, _080DD814
	bl CpuSet
	mov r0, r8
	ldr r3, [r0]
	ldr r0, [r3, #0x14]
	adds r0, r4, r0
	ldrb r0, [r0, #1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r2, _080DD818
	ldr r0, _080DD81C
	adds r0, r5, r0
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	strh r0, [r1, #0x22]
	ldr r0, [r3, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0, #1]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r3, #5
	rsbs r3, r3, #0
	adds r2, r3, #0
	ands r1, r2
	b _080DD83A
	.align 2, 0
_080DD808: .4byte 0x02039BD4
_080DD80C: .4byte 0x020205AC
_080DD810: .4byte 0x06010040
_080DD814: .4byte 0x04000008
_080DD818: .4byte 0x085609D4
_080DD81C: .4byte 0x02039BC6
_080DD820:
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0, #1]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
_080DD83A:
	strb r1, [r0]
	adds r4, #4
	adds r7, #0x1c
	adds r5, #1
	cmp r5, #3
	ble _080DD78A
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_080DD76C

	thumb_func_start GetTurnOrderNumberGfx
GetTurnOrderNumberGfx: @ 0x080DD854
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080DD87C
	ldr r1, [r1]
	ldr r2, [r1, #4]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r2, r1, r2
	ldrb r1, [r2, #0x10]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0x40
	bne _080DD884
	ldrb r0, [r2, #0x19]
	lsls r0, r0, #5
	ldr r1, _080DD880
	adds r0, r0, r1
	b _080DD886
	.align 2, 0
_080DD87C: .4byte 0x02039BD4
_080DD880: .4byte 0x08D8E97C
_080DD884:
	ldr r0, _080DD88C
_080DD886:
	pop {r1}
	bx r1
	.align 2, 0
_080DD88C: .4byte 0x08D8E9FC
	thumb_func_end GetTurnOrderNumberGfx

	thumb_func_start sub_080DD890
sub_080DD890: @ 0x080DD890
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r7, #0
	movs r0, #2
	mov sl, r0
	movs r0, #1
	mov r8, r0
	movs r0, #0x11
	mov sb, r0
_080DD8AA:
	ldr r0, _080DD944
	ldr r0, [r0]
	ldr r0, [r0, #8]
	adds r0, #0xd
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DD92E
	lsls r0, r7, #0x18
	lsrs r0, r0, #0x18
	bl Contest_IsMonsTurnDisabled
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DD92E
	ldr r0, _080DD948
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r5, r0, #2
	adds r5, r5, r0
	adds r6, r5, #2
	movs r0, #3
	bl sub_080DAEAC
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r0, sl
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0x14
	adds r3, r6, #0
	bl ContestBG_FillBoxWithIncrementingTile
	adds r4, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r5, #3
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r0, sl
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0x14
	adds r3, r5, #0
	bl ContestBG_FillBoxWithIncrementingTile
	movs r0, #0x63
	bl PlaySE
_080DD92E:
	adds r7, #1
	cmp r7, #3
	ble _080DD8AA
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD944: .4byte 0x02039BD4
_080DD948: .4byte 0x02039BC6
	thumb_func_end sub_080DD890

	thumb_func_start sub_080DD94C
sub_080DD94C: @ 0x080DD94C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080DD97C
	ldr r1, [r1]
	ldr r2, [r1, #4]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r2, r1, r2
	ldrb r1, [r2, #0x15]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _080DD976
	ldrb r1, [r2, #0xc]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _080DD980
_080DD976:
	movs r0, #0
	b _080DD982
	.align 2, 0
_080DD97C: .4byte 0x02039BD4
_080DD980:
	movs r0, #1
_080DD982:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080DD94C

	thumb_func_start sub_080DD988
sub_080DD988: @ 0x080DD988
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	movs r0, #0xa
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	ldrb r1, [r2]
	movs r4, #4
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r2, #1]
	movs r0, #0x3f
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #1]
	ldrb r1, [r2, #1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #1]
	ldrb r1, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	mov r8, r0
	ands r0, r1
	strb r0, [r2]
	mov r0, sp
	ldrh r1, [r0]
	movs r0, #0xa
	bl SetGpuReg
	movs r0, #8
	bl GetGpuReg
	mov r6, sp
	adds r6, #2
	strh r0, [r6]
	movs r0, #0xc
	bl GetGpuReg
	add r5, sp, #4
	strh r0, [r5]
	ldrb r1, [r6]
	adds r0, r4, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r6]
	ldrb r0, [r5]
	ands r4, r0
	orrs r4, r1
	strb r4, [r5]
	ldrh r1, [r6]
	movs r0, #8
	bl SetGpuReg
	ldrh r1, [r5]
	movs r0, #0xc
	bl SetGpuReg
	ldr r1, _080DDA9C
	movs r0, #0xf0
	strh r0, [r1]
	ldr r4, _080DDAA0
	movs r0, #0xa0
	strh r0, [r4]
	movs r0, #0x14
	movs r1, #0xf0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, #0x16
	bl SetGpuReg
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r4, _080DDAA4
	ldr r1, [r4]
	ldr r1, [r1, #0x28]
	ldr r2, _080DDAA8
	bl CpuSet
	ldr r1, _080DDAAC
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	movs r0, #1
	bl Contest_SetBgCopyFlags
	movs r5, #0
	ldr r7, _080DDAB0
	movs r6, #4
_080DDA54:
	ldr r0, [r4]
	ldr r0, [r0, #0x14]
	lsls r3, r5, #2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	mov r0, r8
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, #5]
	ldr r0, [r4]
	ldr r0, [r0, #0x14]
	adds r3, r3, r0
	ldrb r0, [r3, #1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	mov r0, r8
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, #5]
	adds r5, #1
	cmp r5, #3
	ble _080DDA54
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DDA9C: .4byte 0x02022ACC
_080DDAA0: .4byte 0x02022ACE
_080DDAA4: .4byte 0x02039BD4
_080DDAA8: .4byte 0x05000400
_080DDAAC: .4byte 0x08C17988
_080DDAB0: .4byte 0x020205AC
	thumb_func_end sub_080DD988

	thumb_func_start sub_080DDAB4
sub_080DDAB4: @ 0x080DDAB4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r1, _080DDB70
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0
	movs r3, #1
	bl RequestDma3Fill
	movs r5, #0
	str r5, [sp]
	ldr r6, _080DDB74
	ldr r0, [r6]
	ldr r1, [r0, #0x28]
	ldr r2, _080DDB78
	mov r0, sp
	bl CpuSet
	movs r0, #1
	bl Contest_SetBgCopyFlags
	movs r0, #0xa
	bl GetGpuReg
	add r3, sp, #4
	strh r0, [r3]
	ldrb r1, [r3]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r3]
	mov r1, sp
	adds r1, #5
	ldrb r2, [r1]
	movs r0, #0x3f
	ands r0, r2
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r3]
	movs r4, #0xd
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r3]
	ldrh r1, [r3]
	movs r0, #0xa
	bl SetGpuReg
	ldr r0, _080DDB7C
	strh r5, [r0]
	ldr r0, _080DDB80
	strh r5, [r0]
	ldr r7, _080DDB84
_080DDB2E:
	ldr r0, [r6]
	ldr r0, [r0, #0x14]
	lsls r3, r5, #2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	adds r0, r4, #0
	ands r0, r2
	strb r0, [r1, #5]
	ldr r0, [r6]
	ldr r0, [r0, #0x14]
	adds r3, r3, r0
	ldrb r0, [r3, #1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #5]
	adds r0, r4, #0
	ands r0, r2
	strb r0, [r1, #5]
	adds r5, #1
	cmp r5, #3
	ble _080DDB2E
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DDB70: .4byte 0x06008000
_080DDB74: .4byte 0x02039BD4
_080DDB78: .4byte 0x05000400
_080DDB7C: .4byte 0x02022ACC
_080DDB80: .4byte 0x02022ACE
_080DDB84: .4byte 0x020205AC
	thumb_func_end sub_080DDAB4

	thumb_func_start sub_080DDB88
sub_080DDB88: @ 0x080DDB88
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _080DDBB8
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080DDBBC
	movs r0, #0xa0
	strh r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl PlaySE12WithPanning
	ldr r1, _080DDBC0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _080DDBC4
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DDBB8: .4byte 0x02022ACC
_080DDBBC: .4byte 0x02022ACE
_080DDBC0: .4byte 0x03005B60
_080DDBC4: .4byte 0x080DDBC9
	thumb_func_end sub_080DDB88

	thumb_func_start sub_080DDBC8
sub_080DDBC8: @ 0x080DDBC8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r1, _080DDC00
	ldrh r0, [r1]
	subs r0, #7
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080DDBE0
	movs r0, #0
	strh r0, [r1]
_080DDBE0:
	ldrh r2, [r1]
	cmp r2, #0
	bne _080DDBFA
	ldr r0, _080DDC04
	lsls r1, r3, #2
	adds r1, r1, r3
	lsls r1, r1, #3
	adds r1, r1, r0
	strh r2, [r1, #8]
	strh r2, [r1, #0xa]
	strh r2, [r1, #0xc]
	ldr r0, _080DDC08
	str r0, [r1]
_080DDBFA:
	pop {r0}
	bx r0
	.align 2, 0
_080DDC00: .4byte 0x02022ACE
_080DDC04: .4byte 0x03005B60
_080DDC08: .4byte 0x080DDC0D
	thumb_func_end sub_080DDBC8

	thumb_func_start sub_080DDC0C
sub_080DDC0C: @ 0x080DDC0C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _080DDC30
	lsls r3, r4, #2
	adds r0, r3, r4
	lsls r0, r0, #3
	adds r5, r0, r1
	movs r0, #8
	ldrsh r1, [r5, r0]
	cmp r1, #1
	beq _080DDC90
	cmp r1, #1
	bgt _080DDC34
	cmp r1, #0
	beq _080DDC3E
	b _080DDD18
	.align 2, 0
_080DDC30: .4byte 0x03005B60
_080DDC34:
	cmp r1, #2
	beq _080DDCEE
	cmp r1, #3
	beq _080DDD08
	b _080DDD18
_080DDC3E:
	movs r2, #0
	adds r6, r3, #0
	ldr r5, _080DDC84
	ldr r3, _080DDC88
_080DDC46:
	ldr r0, [r5]
	ldr r1, [r0]
	adds r1, #0x14
	adds r1, r1, r2
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	cmp r2, #3
	ble _080DDC46
	bl FillContestantWindowBgs
	bl sub_080DBFC8
	bl sub_080DAE00
	bl DrawContestantWindows
	movs r0, #1
	bl sub_080DD76C
	bl sub_080DBBB0
	ldr r0, _080DDC8C
	adds r1, r6, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r0, #1
	strh r0, [r1, #8]
	b _080DDD18
	.align 2, 0
_080DDC84: .4byte 0x02039BD4
_080DDC88: .4byte 0x02039BC6
_080DDC8C: .4byte 0x03005B60
_080DDC90:
	ldr r0, _080DDCD8
	ldrb r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _080DDCE8
	ldr r0, _080DDCDC
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #7]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #7]
	bl sub_080DA094
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080DDCB6
	bl sub_080DB204
_080DDCB6:
	ldr r4, _080DDCE0
	adds r0, r4, #0
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DDCE4
	adds r1, r4, #0
	bl SetTaskFuncWithFollowupFunc
	bl ContestPrintLinkStandby
	movs r0, #2
	strh r0, [r5, #8]
	b _080DDD18
	.align 2, 0
_080DDCD8: .4byte 0x02039BCA
_080DDCDC: .4byte 0x02039BD4
_080DDCE0: .4byte 0x080FD4DD
_080DDCE4: .4byte 0x080D9901
_080DDCE8:
	bl sub_080DB204
	b _080DDCFE
_080DDCEE:
	ldr r0, _080DDD04
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, #7]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080DDD18
_080DDCFE:
	movs r0, #3
	strh r0, [r5, #8]
	b _080DDD18
	.align 2, 0
_080DDD04: .4byte 0x02039BD4
_080DDD08:
	bl sub_080DAFE8
	bl SwapMoveDescAndContestTilemaps
	movs r0, #0
	strh r0, [r5, #8]
	ldr r0, _080DDD20
	str r0, [r5]
_080DDD18:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DDD20: .4byte 0x080DDD59
	thumb_func_end sub_080DDC0C

	thumb_func_start sub_080DDD24
sub_080DDD24: @ 0x080DDD24
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _080DDD4C
	ldrh r0, [r1]
	adds r0, #7
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa0
	ble _080DDD48
	ldr r0, _080DDD50
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _080DDD54
	str r0, [r1]
_080DDD48:
	pop {r0}
	bx r0
	.align 2, 0
_080DDD4C: .4byte 0x02022ACE
_080DDD50: .4byte 0x03005B60
_080DDD54: .4byte 0x080D9CE5
	thumb_func_end sub_080DDD24

	thumb_func_start sub_080DDD58
sub_080DDD58: @ 0x080DDD58
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DDD78
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r2, [r1, #0xc]
	movs r3, #0xc
	ldrsh r0, [r1, r3]
	cmp r0, #9
	bgt _080DDD7C
	adds r0, r2, #1
	strh r0, [r1, #0xc]
	b _080DDDB8
	.align 2, 0
_080DDD78: .4byte 0x03005B60
_080DDD7C:
	ldrh r3, [r1, #0xa]
	movs r4, #0xa
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne _080DDD9A
	ldrh r2, [r1, #8]
	movs r4, #8
	ldrsh r0, [r1, r4]
	cmp r0, #0x10
	bne _080DDD96
	adds r0, r3, #1
	strh r0, [r1, #0xa]
	b _080DDDB8
_080DDD96:
	adds r0, r2, #1
	b _080DDDB6
_080DDD9A:
	ldrh r0, [r1, #8]
	movs r3, #8
	ldrsh r2, [r1, r3]
	cmp r2, #0
	bne _080DDDB4
	strh r2, [r1, #0xa]
	strh r2, [r1, #0xc]
	ldr r0, _080DDDB0
	str r0, [r1]
	b _080DDDB8
	.align 2, 0
_080DDDB0: .4byte 0x080DDDC1
_080DDDB4:
	subs r0, #1
_080DDDB6:
	strh r0, [r1, #8]
_080DDDB8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080DDD58

	thumb_func_start sub_080DDDC0
sub_080DDDC0: @ 0x080DDDC0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DDDE0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
	ldrh r1, [r4, #0xc]
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r0, #9
	bgt _080DDDE4
	adds r0, r1, #1
	strh r0, [r4, #0xc]
	b _080DDDF4
	.align 2, 0
_080DDDE0: .4byte 0x03005B60
_080DDDE4:
	movs r0, #0
	strh r0, [r4, #0xc]
	movs r0, #0x61
	movs r1, #0
	bl PlaySE12WithPanning
	ldr r0, _080DDDFC
	str r0, [r4]
_080DDDF4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DDDFC: .4byte 0x080DDD25
	thumb_func_end sub_080DDDC0

	thumb_func_start sub_080DDE00
sub_080DDE00: @ 0x080DDE00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r7, #0
	ldr r6, _080DDEE8
	ldr r5, _080DDEEC
_080DDE12:
	bl AllocOamMatrix
	ldr r1, [r5]
	ldr r1, [r1, #0x14]
	lsls r4, r7, #2
	adds r1, r4, r1
	ldrb r1, [r1]
	lsls r3, r1, #4
	adds r3, r3, r1
	lsls r3, r3, #2
	adds r3, r3, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #1
	ldrb r1, [r3, #3]
	movs r2, #0x3f
	rsbs r2, r2, #0
	mov ip, r2
	mov r2, ip
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, #3]
	ldr r0, [r5]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r2, [r0, #1]
	movs r3, #4
	rsbs r3, r3, #0
	adds r1, r3, #0
	ands r2, r1
	movs r1, #1
	orrs r2, r1
	strb r2, [r0, #1]
	ldr r0, [r5]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	mov r1, r8
	bl StartSpriteAffineAnim
	mov r0, r8
	cmp r0, #2
	bne _080DDEB0
	ldr r0, [r5]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	bl AnimateSprite
	ldr r0, [r5]
	ldr r0, [r0, #0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r3, #5
	rsbs r3, r3, #0
	adds r2, r3, #0
	ands r1, r2
	strb r1, [r0]
_080DDEB0:
	adds r7, #1
	cmp r7, #3
	ble _080DDE12
	ldr r0, _080DDEF0
	movs r1, #5
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080DDEF4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	mov r0, r8
	strh r0, [r1, #8]
	ldr r0, _080DDEEC
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, #7]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #7]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DDEE8: .4byte 0x020205AC
_080DDEEC: .4byte 0x02039BD4
_080DDEF0: .4byte 0x080DDEF9
_080DDEF4: .4byte 0x03005B60
	thumb_func_end sub_080DDE00

	thumb_func_start sub_080DDEF8
sub_080DDEF8: @ 0x080DDEF8
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r2, _080DDF8C
	ldr r3, _080DDF90
	ldr r0, [r3]
	ldr r0, [r0, #0x14]
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bge _080DDF86
	ldr r0, _080DDF94
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrb r0, [r1, #8]
	cmp r0, #1
	bne _080DDF50
	movs r4, #0
	adds r5, r2, #0
	movs r2, #4
_080DDF30:
	ldr r0, [r3]
	ldr r1, [r0, #0x14]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r4, #1
	cmp r4, #3
	ble _080DDF30
_080DDF50:
	movs r4, #0
_080DDF52:
	ldr r5, _080DDF90
	ldr r0, [r5]
	ldr r1, [r0, #0x14]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DDF8C
	adds r0, r0, r1
	bl FreeSpriteOamMatrix
	adds r4, #1
	cmp r4, #3
	ble _080DDF52
	ldr r0, [r5]
	ldr r2, [r0]
	ldrb r1, [r2, #7]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2, #7]
	adds r0, r6, #0
	bl DestroyTask
_080DDF86:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DDF8C: .4byte 0x020205AC
_080DDF90: .4byte 0x02039BD4
_080DDF94: .4byte 0x03005B60
	thumb_func_end sub_080DDEF8

	thumb_func_start SanitizeMove
SanitizeMove: @ 0x080DDF98
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r0, #0xb1
	lsls r0, r0, #1
	cmp r1, r0
	bls _080DDFA8
	movs r1, #1
_080DDFA8:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end SanitizeMove

	thumb_func_start SanitizeSpecies
SanitizeSpecies: @ 0x080DDFB0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080DDFC4
	cmp r1, r0
	bls _080DDFBE
	movs r1, #0
_080DDFBE:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_080DDFC4: .4byte 0x0000019B
	thumb_func_end SanitizeSpecies

	thumb_func_start sub_080DDFC8
sub_080DDFC8: @ 0x080DDFC8
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r4, _080DE02C
	ldr r0, [r4]
	ldr r1, [r0, #4]
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #6]
	bl SanitizeMove
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r1, _080DE030
	lsls r0, r7, #6
	adds r0, r0, r1
	ldrh r0, [r0]
	bl SanitizeSpecies
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [r4]
	ldr r0, [r0, #0x18]
	movs r1, #0
	movs r2, #0x14
	bl memset
	bl ClearBattleAnimationVars
	ldr r1, _080DE034
	movs r2, #0
	adds r0, r1, #3
_080DE00C:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _080DE00C
	cmp r5, #0x90
	beq _080DE084
	cmp r5, #0x90
	bgt _080DE042
	cmp r5, #0x4c
	beq _080DE0DC
	cmp r5, #0x4c
	bgt _080DE038
	cmp r5, #0xd
	beq _080DE0DC
	b _080DE106
	.align 2, 0
_080DE02C: .4byte 0x02039BD4
_080DE030: .4byte 0x02039AA0
_080DE034: .4byte 0x02024188
_080DE038:
	cmp r5, #0x82
	beq _080DE0DC
	cmp r5, #0x8f
	beq _080DE0DC
	b _080DE106
_080DE042:
	cmp r5, #0xd8
	beq _080DE0C4
	cmp r5, #0xd8
	bgt _080DE050
	cmp r5, #0xae
	beq _080DE05E
	b _080DE106
_080DE050:
	cmp r5, #0xda
	beq _080DE0D0
	movs r0, #0x88
	lsls r0, r0, #1
	cmp r5, r0
	beq _080DE084
	b _080DE106
_080DE05E:
	ldr r0, _080DE07C
	lsls r1, r6, #3
	subs r1, r1, r6
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1, #6]
	cmp r0, #7
	beq _080DE074
	ldrb r0, [r1, #7]
	cmp r0, #7
	bne _080DE100
_080DE074:
	ldr r1, _080DE080
	movs r0, #0
	b _080DE104
	.align 2, 0
_080DE07C: .4byte 0x082F0D54
_080DE080: .4byte 0x020380D2
_080DE084:
	ldr r6, _080DE0BC
	ldr r0, [r6]
	ldr r1, [r0, #4]
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r4, [r0, #0x1b]
	ldr r5, _080DE0C0
	lsls r4, r4, #6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl SanitizeSpecies
	ldr r2, [r6]
	ldr r1, [r2, #0x18]
	strh r0, [r1, #2]
	ldr r2, [r2, #0x18]
	adds r5, #0x38
	adds r4, r4, r5
	ldr r0, [r4]
	str r0, [r2, #0x10]
	ldrb r0, [r2, #4]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2, #4]
	b _080DE106
	.align 2, 0
_080DE0BC: .4byte 0x02039BD4
_080DE0C0: .4byte 0x02039AA0
_080DE0C4:
	ldr r1, _080DE0CC
	movs r0, #0xff
	b _080DE104
	.align 2, 0
_080DE0CC: .4byte 0x020380BA
_080DE0D0:
	ldr r1, _080DE0D8
	movs r0, #0
	b _080DE104
	.align 2, 0
_080DE0D8: .4byte 0x020380BA
_080DE0DC:
	ldr r0, _080DE0F8
	ldr r0, [r0]
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x5a
	ldrb r1, [r2]
	cmp r1, #0
	bne _080DE100
	movs r0, #2
	strb r0, [r2]
	ldr r0, _080DE0FC
	strb r1, [r0]
	b _080DE106
	.align 2, 0
_080DE0F8: .4byte 0x02039BD4
_080DE0FC: .4byte 0x020380D2
_080DE100:
	ldr r1, _080DE110
	movs r0, #1
_080DE104:
	strb r0, [r1]
_080DE106:
	bl sub_080DE1C0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE110: .4byte 0x020380D2
	thumb_func_end sub_080DDFC8

	thumb_func_start sub_080DE114
sub_080DE114: @ 0x080DE114
	push {r4, lr}
	ldr r4, _080DE13C
	ldr r0, [r4]
	ldr r0, [r0, #0x18]
	movs r1, #0
	movs r2, #0x14
	bl memset
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5a
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DE136
	subs r0, #1
	strb r0, [r1]
_080DE136:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DE13C: .4byte 0x02039BD4
	thumb_func_end sub_080DE114

	thumb_func_start sub_080DE140
sub_080DE140: @ 0x080DE140
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r6, _080DE17C
	ldr r0, [r6]
	ldr r0, [r0, #0x18]
	strb r4, [r0, #5]
	ldr r5, _080DE180
	lsls r4, r4, #6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl SanitizeSpecies
	ldr r2, [r6]
	ldr r1, [r2, #0x18]
	strh r0, [r1]
	ldr r1, [r2, #0x18]
	adds r0, r5, #0
	adds r0, #0x38
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [r1, #8]
	adds r5, #0x3c
	adds r4, r4, r5
	ldr r0, [r4]
	str r0, [r1, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DE17C: .4byte 0x02039BD4
_080DE180: .4byte 0x02039AA0
	thumb_func_end sub_080DE140

	thumb_func_start sub_080DE184
sub_080DE184: @ 0x080DE184
	push {lr}
	ldr r0, _080DE1B0
	bl CreateInvisibleSpriteWithCallback
	ldr r1, _080DE1B4
	strb r0, [r1, #3]
	ldr r0, _080DE1B8
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DE1BC
	adds r0, r0, r1
	bl InitSpriteAffineAnim
	bl sub_080DE1C0
	pop {r0}
	bx r0
	.align 2, 0
_080DE1B0: .4byte 0x08007141
_080DE1B4: .4byte 0x02023E88
_080DE1B8: .4byte 0x02023EB0
_080DE1BC: .4byte 0x020205AC
	thumb_func_end sub_080DE184

	thumb_func_start sub_080DE1C0
sub_080DE1C0: @ 0x080DE1C0
	push {r4, lr}
	ldr r0, _080DE204
	ldrb r0, [r0, #3]
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080DE208
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	movs r0, #3
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x20]
	movs r0, #3
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x22]
	adds r4, #0x3e
	ldrb r0, [r4]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DE204: .4byte 0x02023E88
_080DE208: .4byte 0x020205AC
	thumb_func_end sub_080DE1C0

	thumb_func_start SelectContestMoveBankTarget
SelectContestMoveBankTarget: @ 0x080DE20C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080DE22C
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r0, [r1, #6]
	cmp r0, #0x20
	bhi _080DE2C4
	lsls r0, r0, #2
	ldr r1, _080DE230
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE22C: .4byte 0x082ED220
_080DE230: .4byte 0x080DE234
_080DE234: @ jump table
	.4byte _080DE2C4 @ case 0
	.4byte _080DE2C4 @ case 1
	.4byte _080DE2B8 @ case 2
	.4byte _080DE2C4 @ case 3
	.4byte _080DE2C4 @ case 4
	.4byte _080DE2C4 @ case 5
	.4byte _080DE2C4 @ case 6
	.4byte _080DE2C4 @ case 7
	.4byte _080DE2C4 @ case 8
	.4byte _080DE2C4 @ case 9
	.4byte _080DE2C4 @ case 10
	.4byte _080DE2C4 @ case 11
	.4byte _080DE2C4 @ case 12
	.4byte _080DE2C4 @ case 13
	.4byte _080DE2C4 @ case 14
	.4byte _080DE2C4 @ case 15
	.4byte _080DE2B8 @ case 16
	.4byte _080DE2C4 @ case 17
	.4byte _080DE2C4 @ case 18
	.4byte _080DE2C4 @ case 19
	.4byte _080DE2C4 @ case 20
	.4byte _080DE2C4 @ case 21
	.4byte _080DE2C4 @ case 22
	.4byte _080DE2C4 @ case 23
	.4byte _080DE2C4 @ case 24
	.4byte _080DE2C4 @ case 25
	.4byte _080DE2C4 @ case 26
	.4byte _080DE2C4 @ case 27
	.4byte _080DE2C4 @ case 28
	.4byte _080DE2C4 @ case 29
	.4byte _080DE2C4 @ case 30
	.4byte _080DE2C4 @ case 31
	.4byte _080DE2C4 @ case 32
_080DE2B8:
	ldr r1, _080DE2C0
	movs r0, #2
	b _080DE2C8
	.align 2, 0
_080DE2C0: .4byte 0x02023EB0
_080DE2C4:
	ldr r1, _080DE2D0
	movs r0, #3
_080DE2C8:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080DE2D0: .4byte 0x02023EB0
	thumb_func_end SelectContestMoveBankTarget

	thumb_func_start Contest_PrintTextToBg0WindowStd
Contest_PrintTextToBg0WindowStd: @ 0x080DE2D4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp]
	mov r0, sp
	movs r2, #0
	strb r4, [r0, #4]
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #5]
	mov r0, sp
	strb r2, [r0, #6]
	movs r1, #2
	strb r1, [r0, #7]
	strb r2, [r0, #8]
	strb r1, [r0, #9]
	strb r2, [r0, #0xa]
	strb r2, [r0, #0xb]
	mov r3, sp
	ldrb r2, [r3, #0xc]
	subs r1, #0x12
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xc]
	mov r2, sp
	movs r0, #0xf0
	strb r0, [r2, #0xc]
	ldrb r0, [r2, #0xd]
	ands r1, r0
	strb r1, [r2, #0xd]
	mov r1, sp
	movs r0, #0x80
	strb r0, [r1, #0xd]
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl AddTextPrinter
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl PutWindowTilemap
	movs r0, #0
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end Contest_PrintTextToBg0WindowStd

	thumb_func_start Contest_StartTextPrinter
Contest_StartTextPrinter: @ 0x080DE338
	push {r4, r5, lr}
	sub sp, #0x10
	str r0, [sp]
	mov r2, sp
	movs r3, #0
	movs r0, #8
	strb r0, [r2, #4]
	mov r0, sp
	movs r5, #1
	strb r5, [r0, #5]
	strb r3, [r0, #6]
	movs r2, #2
	strb r2, [r0, #7]
	strb r3, [r0, #8]
	strb r2, [r0, #9]
	strb r3, [r0, #0xa]
	strb r3, [r0, #0xb]
	mov r4, sp
	ldrb r3, [r4, #0xc]
	subs r2, #0x12
	adds r0, r2, #0
	ands r0, r3
	strb r0, [r4, #0xc]
	mov r3, sp
	movs r0, #0x10
	strb r0, [r3, #0xc]
	ldrb r0, [r3, #0xd]
	ands r2, r0
	strb r2, [r3, #0xd]
	mov r2, sp
	movs r0, #0x80
	strb r0, [r2, #0xd]
	cmp r1, #0
	bne _080DE388
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl AddTextPrinter
	b _080DE3AC
_080DE388:
	ldr r0, _080DE398
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _080DE39C
	movs r1, #4
	b _080DE3A4
	.align 2, 0
_080DE398: .4byte 0x02039BCA
_080DE39C:
	bl GetPlayerTextSpeedDelay
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_080DE3A4:
	mov r0, sp
	movs r2, #0
	bl AddTextPrinter
_080DE3AC:
	movs r0, #8
	bl PutWindowTilemap
	movs r0, #0
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end Contest_StartTextPrinter

	thumb_func_start ContestBG_FillBoxWithIncrementingTile
ContestBG_FillBoxWithIncrementingTile: @ 0x080DE3C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	ldr r0, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	mov r7, r8
	lsls r7, r7, #0x18
	lsrs r7, r7, #0x18
	mov r8, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r0, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	str r6, [sp, #0xc]
	mov r0, r8
	bl WriteSequenceToBgTilemapBuffer
	mov r0, r8
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ContestBG_FillBoxWithIncrementingTile

	thumb_func_start ContestBG_FillBoxWithTile
ContestBG_FillBoxWithTile: @ 0x080DE418
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r6, [sp, #0x28]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	bl ContestBG_FillBoxWithIncrementingTile
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end ContestBG_FillBoxWithTile

	thumb_func_start Contest_RunTextPrinters
Contest_RunTextPrinters: @ 0x080DE454
	push {lr}
	bl RunTextPrinters
	movs r0, #8
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	thumb_func_end Contest_RunTextPrinters

	thumb_func_start Contest_SetBgCopyFlags
Contest_SetBgCopyFlags: @ 0x080DE468
	ldr r2, _080DE478
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.align 2, 0
_080DE478: .4byte 0x02039BD8
	thumb_func_end Contest_SetBgCopyFlags

	thumb_func_start ResetContestLinkResults
ResetContestLinkResults: @ 0x080DE47C
	push {r4, r5, r6, lr}
	movs r0, #0
	ldr r6, _080DE4A8
	ldr r5, _080DE4AC
	movs r4, #0
_080DE486:
	adds r3, r0, #1
	lsls r1, r0, #3
	movs r2, #3
_080DE48C:
	ldr r0, [r6]
	adds r0, r0, r5
	adds r0, r0, r1
	strh r4, [r0]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _080DE48C
	adds r0, r3, #0
	cmp r0, #4
	ble _080DE486
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DE4A8: .4byte 0x03005AF0
_080DE4AC: .4byte 0x00000624
	thumb_func_end ResetContestLinkResults

	thumb_func_start sub_080DE4B0
sub_080DE4B0: @ 0x080DE4B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r5, #0
	ldr r1, _080DE500
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DE4EE
_080DE4E0:
	adds r5, #1
	cmp r5, #2
	bgt _080DE4EE
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DE4E0
_080DE4EE:
	ldr r0, [sp]
	cmp r0, #0xff
	bne _080DE508
	ldr r0, _080DE504
	ldrb r0, [r0]
	cmp r5, r0
	beq _080DE508
	movs r0, #0
	b _080DE698
	.align 2, 0
_080DE500: .4byte 0x02039BC0
_080DE504: .4byte 0x02039BC5
_080DE508:
	ldr r0, _080DE51C
	ldrh r0, [r0]
	cmp r0, #4
	bhi _080DE554
	lsls r0, r0, #2
	ldr r1, _080DE520
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE51C: .4byte 0x02039BCC
_080DE520: .4byte 0x080DE524
_080DE524: @ jump table
	.4byte _080DE554 @ case 0
	.4byte _080DE538 @ case 1
	.4byte _080DE53E @ case 2
	.4byte _080DE544 @ case 3
	.4byte _080DE54A @ case 4
_080DE538:
	mov r0, r8
	adds r0, #3
	b _080DE54E
_080DE53E:
	mov r0, r8
	adds r0, #6
	b _080DE54E
_080DE544:
	mov r0, r8
	adds r0, #9
	b _080DE54E
_080DE54A:
	mov r0, r8
	adds r0, #0xc
_080DE54E:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_080DE554:
	ldr r1, [sp]
	cmp r1, #0xfe
	bne _080DE55C
	b _080DE658
_080DE55C:
	adds r0, r1, #0
	movs r1, #1
	bl sub_080DE6B0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r2, _080DE5E0
	mov sl, r2
	ldr r0, [r2]
	mov r3, sb
	lsls r7, r3, #5
	ldr r6, _080DE5E4
	adds r2, r0, r6
	adds r2, r2, r7
	ldr r4, _080DE5E8
	lsls r5, r5, #6
	adds r1, r4, #0
	adds r1, #0x38
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r1, r0, r7
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r3, _080DE5EC
	adds r1, r1, r3
	strh r2, [r1]
	ldr r1, _080DE5F0
	adds r2, r0, r1
	adds r2, r2, r7
	adds r1, r4, #0
	adds r1, #0x3c
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r6, r7, r6
	adds r0, r0, r6
	adds r0, #0xb
	adds r1, r4, #2
	adds r1, r5, r1
	bl StringCopy
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r6
	adds r0, #0x16
	adds r4, #0xd
	adds r5, r5, r4
	adds r1, r5, #0
	bl StringCopy
	ldr r0, _080DE5F4
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DE5FC
	mov r3, sl
	ldr r0, [r3]
	adds r0, r0, r7
	ldr r1, _080DE5F8
	adds r0, r0, r1
	movs r1, #4
	b _080DE60A
	.align 2, 0
_080DE5E0: .4byte 0x03005AEC
_080DE5E4: .4byte 0x00002E90
_080DE5E8: .4byte 0x02039AA0
_080DE5EC: .4byte 0x00002E98
_080DE5F0: .4byte 0x00002E94
_080DE5F4: .4byte 0x02039BCA
_080DE5F8: .4byte 0x00002EAE
_080DE5FC:
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r7
	ldr r1, _080DE628
	ldrh r1, [r1]
	ldr r3, _080DE62C
	adds r0, r0, r3
_080DE60A:
	strb r1, [r0]
	ldr r0, [sp]
	cmp r0, #0xff
	beq _080DE63C
	ldr r0, _080DE630
	ldr r0, [r0]
	mov r2, sb
	lsls r1, r2, #5
	adds r0, r0, r1
	ldr r1, _080DE634
	ldrh r1, [r1]
	ldr r3, _080DE638
	adds r0, r0, r3
	strb r1, [r0]
	b _080DE696
	.align 2, 0
_080DE628: .4byte 0x02039BCE
_080DE62C: .4byte 0x00002EAE
_080DE630: .4byte 0x03005AEC
_080DE634: .4byte 0x02039BCC
_080DE638: .4byte 0x00002E9A
_080DE63C:
	ldr r0, _080DE650
	ldr r0, [r0]
	mov r2, sb
	lsls r1, r2, #5
	adds r0, r0, r1
	ldr r3, _080DE654
	adds r0, r0, r3
	mov r1, r8
	strb r1, [r0]
	b _080DE696
	.align 2, 0
_080DE650: .4byte 0x03005AEC
_080DE654: .4byte 0x00002E9A
_080DE658:
	ldr r6, _080DE6A8
	ldr r4, _080DE6AC
	lsls r5, r5, #6
	adds r0, r4, #0
	adds r0, #0x38
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0x3c
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6, #4]
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r6, #8]
	adds r0, r6, #0
	adds r0, #0xb
	adds r1, r4, #2
	adds r1, r5, r1
	bl StringCopy
	adds r0, r6, #0
	adds r0, #0x16
	adds r4, #0xd
	adds r5, r5, r4
	adds r1, r5, #0
	bl StringCopy
	mov r2, r8
	strb r2, [r6, #0xa]
_080DE696:
	movs r0, #1
_080DE698:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DE6A8: .4byte 0x02039BDC
_080DE6AC: .4byte 0x02039AA0
	thumb_func_end sub_080DE4B0

	thumb_func_start sub_080DE6B0
sub_080DE6B0: @ 0x080DE6B0
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r0, #3
	bgt _080DE700
	cmp r0, #0
	blt _080DE700
	cmp r1, #0
	beq _080DE6EE
	movs r2, #5
	ldr r0, _080DE6F4
	mov ip, r0
	ldr r4, _080DE6F8
	ldr r3, _080DE6FC
_080DE6D0:
	mov r1, ip
	ldr r0, [r1]
	lsls r1, r2, #5
	adds r1, r1, r0
	adds r0, r1, r4
	adds r1, r1, r3
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r0!, {r5, r6}
	subs r2, #1
	cmp r2, #0
	bgt _080DE6D0
_080DE6EE:
	movs r0, #0
	b _080DE742
	.align 2, 0
_080DE6F4: .4byte 0x03005AEC
_080DE6F8: .4byte 0x00002E90
_080DE6FC: .4byte 0x00002E70
_080DE700:
	ldr r0, _080DE714
	ldrh r0, [r0]
	cmp r0, #4
	bhi _080DE740
	lsls r0, r0, #2
	ldr r1, _080DE718
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE714: .4byte 0x02039BCC
_080DE718: .4byte 0x080DE71C
_080DE71C: @ jump table
	.4byte _080DE730 @ case 0
	.4byte _080DE734 @ case 1
	.4byte _080DE738 @ case 2
	.4byte _080DE73C @ case 3
	.4byte _080DE740 @ case 4
_080DE730:
	movs r0, #8
	b _080DE742
_080DE734:
	movs r0, #9
	b _080DE742
_080DE738:
	movs r0, #0xa
	b _080DE742
_080DE73C:
	movs r0, #0xb
	b _080DE742
_080DE740:
	movs r0, #0xc
_080DE742:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080DE6B0

	thumb_func_start ClearContestWinnerPicsInContestHall
ClearContestWinnerPicsInContestHall: @ 0x080DE748
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r0, _080DE77C
	mov ip, r0
	ldr r4, _080DE780
	ldr r3, _080DE784
_080DE754:
	mov r1, ip
	ldr r0, [r1]
	lsls r1, r2, #5
	adds r0, r0, r1
	adds r0, r0, r4
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r0!, {r5, r6}
	adds r3, #0x20
	adds r2, #1
	cmp r2, #7
	ble _080DE754
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE77C: .4byte 0x03005AEC
_080DE780: .4byte 0x00002E90
_080DE784: .4byte 0x08560F28
	thumb_func_end ClearContestWinnerPicsInContestHall

	thumb_func_start sub_080DE788
sub_080DE788: @ 0x080DE788
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _080DE8C0
	ldr r3, [r2]
	ldr r5, [r3, #0x10]
	ldrb r1, [r5, #1]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _080DE7DA
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _080DE7DA
	ldr r1, [r3, #4]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x15]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE7DA
	ldr r1, [r3, #0x1c]
	lsls r2, r4, #4
	adds r1, r2, r1
	ldrb r3, [r1, #0xc]
	movs r0, #1
	orrs r0, r3
	strb r0, [r1, #0xc]
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	adds r2, r2, r0
	ldrb r0, [r2, #0xe]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0xe]
_080DE7DA:
	ldr r3, [r6]
	ldr r1, [r3, #4]
	lsls r2, r4, #3
	subs r0, r2, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0xc]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _080DE802
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE802:
	ldr r3, [r6]
	ldr r2, [r3, #0x10]
	ldrb r1, [r2, #1]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE82E
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _080DE82E
	movs r0, #2
	ldrsb r0, [r2, r0]
	cmp r0, #0x3c
	bne _080DE82E
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #4
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE82E:
	ldr r3, [r6]
	ldr r1, [r3, #4]
	subs r0, r7, r4
	lsls r0, r0, #2
	adds r2, r0, r1
	ldrb r1, [r2, #0x15]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DE856
	ldrb r0, [r2, #0x16]
	cmp r0, #0
	beq _080DE856
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #8
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE856:
	movs r3, #0
	movs r5, #0
_080DE85A:
	cmp r3, r4
	beq _080DE888
	ldr r1, [r6]
	ldr r0, [r1, #4]
	adds r0, r5, r0
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _080DE888
	ldr r0, [r1, #0x1c]
	lsls r2, r4, #4
	adds r2, r2, r0
	ldrb r0, [r2, #0xc]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	lsls r2, r3, #4
	adds r2, r2, r0
	ldrb r0, [r2, #0xc]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0xc]
_080DE888:
	adds r5, #0x1c
	adds r3, #1
	cmp r3, #3
	ble _080DE85A
	ldr r2, [r6]
	ldr r1, [r2, #4]
	subs r0, r7, r4
	lsls r5, r0, #2
	adds r1, r5, r1
	ldrb r3, [r1, #0xc]
	movs r0, #6
	ands r0, r3
	cmp r0, #0
	bne _080DE8AE
	ldrb r1, [r1, #0xb]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080DE8C4
_080DE8AE:
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #0x20
	orrs r0, r2
	strb r0, [r1, #0xc]
	b _080DE8FE
	.align 2, 0
_080DE8C0: .4byte 0x02039BD4
_080DE8C4:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	bne _080DE8FE
	ldr r2, [r2, #0x1c]
	lsls r3, r4, #4
	adds r2, r3, r2
	ldrb r0, [r2, #0xc]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldr r0, [r6]
	ldr r1, [r0, #0x1c]
	adds r1, r3, r1
	ldrb r0, [r1, #0xe]
	movs r2, #1
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldr r1, [r6]
	ldr r0, [r1, #0x1c]
	adds r3, r3, r0
	ldr r0, [r1]
	ldrb r0, [r0, #1]
	lsls r0, r0, #1
	adds r3, r3, r0
	ldr r0, [r1, #4]
	adds r0, r5, r0
	ldrh r0, [r0, #6]
	strh r0, [r3]
_080DE8FE:
	ldr r2, [r6]
	ldr r1, [r2, #4]
	subs r0, r7, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x15]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _080DE922
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1, #0xd]
_080DE922:
	ldr r2, [r6]
	ldr r0, [r2]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080DE952
	ldr r3, [r2, #0x10]
	ldrb r1, [r3, #1]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE952
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _080DE952
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #0x20
	orrs r0, r2
	strb r0, [r1, #0xd]
_080DE952:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_080DE788

	thumb_func_start sub_080DE958
sub_080DE958: @ 0x080DE958
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	movs r1, #0
	movs r0, #0
	str r0, [sp, #0x20]
	movs r4, #0
	ldr r6, _080DE998
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x28]
	mov r3, sp
	adds r3, #0x14
	str r3, [sp, #0x2c]
	mov r7, sp
	adds r7, #2
	str r7, [sp, #0x24]
	ldr r5, _080DE99C
	movs r2, #0
	movs r3, #0x80
	lsls r3, r3, #0x11
_080DE988:
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DE9A0
	lsrs r0, r2, #0x18
	str r0, [sp, #0x20]
	b _080DE9A6
	.align 2, 0
_080DE998: .4byte 0x02039BD4
_080DE99C: .4byte 0x02039BC0
_080DE9A0:
	cmp r0, #3
	bne _080DE9A6
	lsrs r1, r2, #0x18
_080DE9A6:
	adds r2, r2, r3
	adds r4, #1
	cmp r4, #3
	ble _080DE988
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1, #0xd]
	movs r4, #0
	ldr r1, [sp, #0x20]
	lsls r1, r1, #4
	str r1, [sp, #0x30]
	mov sb, r4
	mov sl, r4
_080DE9CA:
	ldr r2, [sp, #0x20]
	cmp r4, r2
	beq _080DE9F6
	ldr r1, _080DEB94
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	add r1, sl
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r2, r2, r0
	cmp r2, #0x32
	bgt _080DE9F6
	ldr r7, _080DEB98
	ldr r0, [r7]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DE9F6:
	ldr r1, _080DEB98
	ldr r0, [r1]
	ldr r0, [r0, #0x1c]
	mov r3, sb
	adds r2, r3, r0
	ldrb r1, [r2, #0xe]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080DEA12
	ldrb r0, [r2, #0xd]
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEA12:
	movs r5, #0
	ldr r2, _080DEB9C
	add r2, sl
	movs r6, #0
	ldrsh r1, [r2, r6]
	ldr r7, _080DEB9C
	movs r3, #0
	ldrsh r0, [r7, r3]
	cmp r1, r0
	blt _080DEA3E
	adds r3, r2, #0
	adds r2, r7, #0
_080DEA2A:
	adds r2, #2
	adds r5, #1
	cmp r5, #3
	bgt _080DEA3E
	movs r6, #0
	ldrsh r1, [r3, r6]
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _080DEA2A
_080DEA3E:
	cmp r5, #4
	bne _080DEA5C
	ldr r1, _080DEBA0
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DEA5C
	ldr r2, _080DEB98
	ldr r0, [r2]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEA5C:
	movs r3, #0
	mov ip, r3
	mov r8, r3
	movs r5, #0
	ldr r0, _080DEB9C
	add r0, sl
	movs r7, #0
	ldrsh r6, [r0, r7]
	str r6, [sp, #0x34]
	ldr r2, _080DEB9C
	ldr r0, _080DEBA4
	mov r1, sl
	adds r6, r1, r0
	adds r3, r0, #0
_080DEA78:
	movs r7, #0
	ldrsh r0, [r2, r7]
	ldr r1, [sp, #0x34]
	cmp r1, r0
	ble _080DEA86
	movs r7, #1
	mov ip, r7
_080DEA86:
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble _080DEA96
	movs r0, #1
	mov r8, r0
_080DEA96:
	adds r2, #2
	adds r3, #2
	adds r5, #1
	cmp r5, #3
	ble _080DEA78
	mov r1, ip
	cmp r1, #0
	bne _080DEABC
	mov r2, r8
	cmp r2, #0
	bne _080DEABC
	ldr r3, _080DEB98
	ldr r0, [r3]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEABC:
	ldr r6, _080DEB98
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	mov r7, sb
	adds r2, r7, r0
	ldrb r1, [r2, #0xe]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DEAD8
	ldrb r0, [r2, #0xd]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEAD8:
	movs r0, #0x10
	add sb, r0
	movs r1, #2
	add sl, r1
	adds r4, #1
	cmp r4, #3
	bgt _080DEAE8
	b _080DE9CA
_080DEAE8:
	movs r4, #0
	movs r5, #0
	movs r3, #0
	ldr r2, [sp, #0x28]
	mov r1, sp
_080DEAF2:
	strh r3, [r1]
	adds r0, r2, r4
	strb r5, [r0]
	adds r1, #2
	adds r4, #1
	cmp r4, #4
	ble _080DEAF2
	mov r1, sp
	ldr r0, _080DEBA8
	strh r0, [r1, #0xa]
	movs r0, #0
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
	movs r4, #0
	ldr r0, _080DEB98
	ldr r0, [r0]
	mov r8, r0
	ldr r7, [sp, #0x30]
_080DEB16:
	mov r3, r8
	ldr r0, [r3, #0x1c]
	adds r0, r7, r0
	lsls r1, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, #1
	mov ip, r4
	cmp r0, #0
	beq _080DEB58
	ldr r0, _080DEB98
	ldr r6, [r0]
	ldr r3, [sp, #0x28]
	mov r4, sp
	movs r5, #4
_080DEB34:
	ldr r0, [r6, #0x1c]
	adds r0, r7, r0
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	beq _080DEB48
	cmp r2, #0
	bne _080DEB4E
	strh r0, [r4]
_080DEB48:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_080DEB4E:
	adds r3, #1
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080DEB34
_080DEB58:
	mov r4, ip
	cmp r4, #4
	ble _080DEB16
	mov r0, sp
	ldrh r0, [r0]
	ldr r6, [sp, #0x2c]
	strh r0, [r6]
	ldr r7, [sp, #0x28]
	ldrb r3, [r7]
	movs r6, #0
	movs r4, #1
	ldr r1, [sp, #0x24]
	ldrh r0, [r1]
	ldr r1, _080DEBA8
	cmp r0, r1
	beq _080DEBC8
	ldr r5, [sp, #0x2c]
	adds r7, r1, #0
	mov r2, sp
	adds r2, #2
_080DEB80:
	ldr r0, [sp, #0x28]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r3, r0
	bhs _080DEBAC
	ldrh r0, [r2]
	strh r0, [r5]
	ldrb r3, [r1]
	movs r6, #1
	b _080DEBBE
	.align 2, 0
_080DEB94: .4byte 0x02039BA8
_080DEB98: .4byte 0x02039BD4
_080DEB9C: .4byte 0x02039BA0
_080DEBA0: .4byte 0x02039BC0
_080DEBA4: .4byte 0x02039BB8
_080DEBA8: .4byte 0x0000FFFF
_080DEBAC:
	cmp r3, r0
	bne _080DEBBE
	lsls r0, r6, #1
	adds r0, r5, r0
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_080DEBBE:
	adds r2, #2
	adds r4, #1
	ldrh r0, [r2]
	cmp r0, r7
	bne _080DEB80
_080DEBC8:
	bl Random
	ldr r1, _080DEBFC
	ldr r1, [r1]
	ldr r4, [r1, #0x1c]
	ldr r1, [sp, #0x30]
	adds r4, r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl __modsi3
	lsls r0, r0, #1
	ldr r2, [sp, #0x2c]
	adds r0, r2, r0
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEBFC: .4byte 0x02039BD4
	thumb_func_end sub_080DE958

	thumb_func_start sub_080DEC00
sub_080DEC00: @ 0x080DEC00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r2, _080DED34
	ldr r0, _080DED38
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DEC1C
	b _080DEDCC
_080DEC1C:
	movs r1, #0
	movs r3, #0
	ldr r0, _080DED3C
	mov sb, r0
_080DEC24:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEC30
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
_080DEC30:
	adds r3, #1
	cmp r3, #3
	ble _080DEC24
	movs r2, #0
	mov sl, r2
	movs r4, #0
	str r4, [sp, #4]
	movs r3, #0
	lsls r2, r1, #1
	lsls r1, r1, #4
	mov r8, r1
	ldr r1, _080DED40
	adds r0, r2, r1
	movs r7, #0
	ldrsh r6, [r0, r7]
	adds r5, r1, #0
	ldr r0, _080DED44
	adds r2, r2, r0
	adds r4, r0, #0
_080DEC56:
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r6, r0
	bge _080DEC68
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
_080DEC68:
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r7, #0
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bge _080DEC7E
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
_080DEC7E:
	adds r5, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #3
	ble _080DEC56
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrb r1, [r0, #0xc]
	movs r4, #0
	movs r2, #1
	movs r3, #7
_080DEC98:
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080DECA6
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080DECA6:
	lsrs r1, r1, #1
	subs r3, #1
	cmp r3, #0
	bge _080DEC98
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080DED3C
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrb r1, [r0, #0xc]
	movs r4, #0
	movs r2, #0
	movs r3, #0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DECE2
	cmp r5, #0
	beq _080DECFC
_080DECDC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080DECE2:
	lsrs r1, r1, #1
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, #1
	cmp r3, #7
	bgt _080DECFC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DECE2
	cmp r5, r4
	bne _080DECDC
_080DECFC:
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r0, r2
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080DED3C
	ldr r1, [r0]
	ldr r0, [r1, #0x1c]
	ldrb r4, [r0, #0xd]
	movs r5, #1
	movs r3, #1
	mov r6, sp
_080DED1A:
	ldr r0, [r1, #0x1c]
	lsls r2, r3, #4
	adds r0, r2, r0
	ldrb r0, [r0, #0xd]
	cmp r4, r0
	bhs _080DED48
	strb r3, [r6]
	ldr r0, [r1, #0x1c]
	adds r0, r2, r0
	ldrb r4, [r0, #0xd]
	movs r5, #1
	b _080DED58
	.align 2, 0
_080DED34: .4byte 0x02039BC0
_080DED38: .4byte 0x02039BC5
_080DED3C: .4byte 0x02039BD4
_080DED40: .4byte 0x02039BA0
_080DED44: .4byte 0x02039BB8
_080DED48:
	cmp r4, r0
	bne _080DED58
	mov r2, sp
	adds r0, r2, r5
	strb r3, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080DED58:
	adds r3, #1
	cmp r3, #3
	ble _080DED1A
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl __modsi3
	add r0, sp
	ldrb r7, [r0]
	movs r2, #0x80
	movs r3, #0
	ldr r5, _080DEDDC
	ldr r0, [r5]
	ldr r0, [r0, #0x1c]
	lsls r1, r7, #4
	adds r0, r1, r0
	ldrb r0, [r0, #0xd]
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, sb
	lsls r6, r0, #0x18
	cmp r4, #0
	bne _080DEDA4
_080DED8E:
	lsrs r2, r2, #1
	adds r3, #1
	cmp r3, #7
	bgt _080DEDA4
	ldr r0, [r5]
	ldr r0, [r0, #0x1c]
	adds r0, r1, r0
	ldrb r4, [r0, #0xd]
	ands r4, r2
	cmp r4, #0
	beq _080DED8E
_080DEDA4:
	mov r0, sl
	bl ContestLiveUpdates_BeforeInterview_1
	ldr r0, [sp, #4]
	bl ContestLiveUpdates_BeforeInterview_2
	lsrs r0, r6, #0x18
	bl ContestLiveUpdates_BeforeInterview_3
	ldr r0, _080DEDDC
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrh r0, [r0, #0xa]
	bl ContestLiveUpdates_BeforeInterview_4
	adds r0, r4, #0
	adds r1, r7, #0
	bl ContestLiveUpdates_BeforeInterview_5
_080DEDCC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEDDC: .4byte 0x02039BD4
	thumb_func_end sub_080DEC00

	thumb_func_start ContestDebugToggleBitfields
ContestDebugToggleBitfields: @ 0x080DEDE0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _080DEE00
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r4, r0, #0
	cmp r1, #0
	bne _080DEE08
	cmp r3, #0
	bne _080DEE04
	movs r0, #2
	b _080DEE0A
	.align 2, 0
_080DEE00: .4byte 0x02000000
_080DEE04:
	movs r0, #3
	b _080DEE0A
_080DEE08:
	movs r0, #0
_080DEE0A:
	strb r0, [r2]
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEE22
	bl DrawContestantWindowText
	bl SwapMoveDescAndContestTilemaps
	b _080DEE26
_080DEE22:
	bl ContestDebugPrintBitStrings
_080DEE26:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ContestDebugToggleBitfields

	thumb_func_start ContestDebugPrintBitStrings
ContestDebugPrintBitStrings: @ 0x080DEE2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _080DEF28
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEE42
	b _080DEFD4
_080DEE42:
	ldr r0, _080DEF2C
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080DEE58
	b _080DEFD4
_080DEE58:
	movs r7, #0
	add r2, sp, #0x14
	mov sl, r2
_080DEE5E:
	adds r0, r7, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	adds r0, r7, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl FillWindowPixelBuffer
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEE5E
	ldr r0, _080DEF2C
	movs r4, #0xd0
	lsls r4, r4, #9
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	bne _080DEF3C
	movs r7, #0
	mov sb, sl
_080DEE8E:
	mov r0, sp
	ldr r1, _080DEF30
	bl StringCopy
	adds r6, r0, #0
	ldr r0, _080DEF34
	adds r0, r7, r0
	ldrb r0, [r0]
	mov r1, sp
	bl Contest_PrintTextToBg0WindowStd
	ldr r0, _080DEF38
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	lsls r0, r7, #4
	adds r0, r0, r1
	ldrb r5, [r0, #0xc]
	movs r4, #7
	adds r0, r7, #1
	mov r8, r0
_080DEEB6:
	movs r1, #1
	ands r1, r5
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	adds r6, r0, #0
	lsrs r5, r5, #1
	lsls r0, r4, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	bgt _080DEEB6
	movs r4, #0
	ldr r6, _080DEF34
	mov r3, sl
_080DEEE2:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	adds r2, r3, r0
	mov r4, sp
	adds r1, r4, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #4
	ble _080DEEE2
	mov r0, sb
	adds r1, r0, r5
	movs r0, #0xff
	strb r0, [r1]
	adds r4, r7, r6
	ldrb r0, [r4]
	mov r1, sb
	bl Contest_PrintTextToBg0WindowStd
	ldrb r0, [r4]
	adds r0, #4
	mov r2, sp
	adds r1, r2, r5
	bl Contest_PrintTextToBg0WindowStd
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEE8E
	b _080DEFD0
	.align 2, 0
_080DEF28: .4byte 0x02031F75
_080DEF2C: .4byte 0x02000000
_080DEF30: .4byte 0x085CC49D
_080DEF34: .4byte 0x02039BC6
_080DEF38: .4byte 0x02039BD4
_080DEF3C:
	movs r7, #0
	mov r0, sp
	adds r0, #2
	str r0, [sp, #0x28]
	mov sb, sl
_080DEF46:
	mov r0, sp
	ldr r1, _080DEFE4
	bl StringCopy
	ldr r0, _080DEFE8
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	lsls r0, r7, #4
	adds r0, r0, r1
	ldrb r5, [r0, #0xd]
	ldr r6, [sp, #0x28]
	movs r4, #7
	adds r1, r7, #1
	mov r8, r1
_080DEF62:
	movs r1, #1
	ands r1, r5
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	adds r6, r0, #0
	lsrs r5, r5, #1
	lsls r0, r4, #0x18
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _080DEF62
	movs r4, #0
	ldr r6, _080DEFEC
	mov r3, sl
_080DEF8E:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	adds r2, r3, r0
	mov r4, sp
	adds r1, r4, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #4
	ble _080DEF8E
	mov r0, sb
	adds r1, r0, r5
	movs r0, #0xff
	strb r0, [r1]
	adds r4, r7, r6
	ldrb r0, [r4]
	mov r1, sb
	bl Contest_PrintTextToBg0WindowStd
	ldrb r0, [r4]
	adds r0, #4
	mov r2, sp
	adds r1, r2, r5
	bl Contest_PrintTextToBg0WindowStd
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEF46
_080DEFD0:
	bl SwapMoveDescAndContestTilemaps
_080DEFD4:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEFE4: .4byte 0x085CC4A0
_080DEFE8: .4byte 0x02039BD4
_080DEFEC: .4byte 0x02039BC6
	thumb_func_end ContestDebugPrintBitStrings

