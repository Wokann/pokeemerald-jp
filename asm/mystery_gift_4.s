.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start mevent_message_stamp_card_etc_send_status
mevent_message_stamp_card_etc_send_status: @ 0x08018B0C
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, _08018B28
	movs r0, #0
	str r0, [r3]
	adds r4, r1, #0
	cmp r2, #0xe
	bhi _08018BCE
	lsls r0, r2, #2
	ldr r1, _08018B2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08018B28: .4byte 0x082C2790
_08018B2C: .4byte 0x08018B30
_08018B30: @ jump table
	.4byte _08018B6C @ case 0
	.4byte _08018B74 @ case 1
	.4byte _08018B7C @ case 2
	.4byte _08018B84 @ case 3
	.4byte _08018B90 @ case 4
	.4byte _08018B98 @ case 5
	.4byte _08018BA0 @ case 6
	.4byte _08018BA8 @ case 7
	.4byte _08018BB0 @ case 8
	.4byte _08018BB8 @ case 9
	.4byte _08018BCC @ case 10
	.4byte _08018BC0 @ case 11
	.4byte _08018BC4 @ case 12
	.4byte _08018BC4 @ case 13
	.4byte _08018BCC @ case 14
_08018B6C:
	ldr r1, _08018B70
	b _08018BCE
	.align 2, 0
_08018B70: .4byte 0x082C2960
_08018B74:
	ldr r1, _08018B78
	b _08018BCE
	.align 2, 0
_08018B78: .4byte 0x082C2904
_08018B7C:
	ldr r1, _08018B80
	b _08018B86
	.align 2, 0
_08018B80: .4byte 0x082C29C0
_08018B84:
	ldr r1, _08018B8C
_08018B86:
	movs r0, #1
	str r0, [r3]
	b _08018BCE
	.align 2, 0
_08018B8C: .4byte 0x082C29D8
_08018B90:
	ldr r1, _08018B94
	b _08018BCE
	.align 2, 0
_08018B94: .4byte 0x082C29EC
_08018B98:
	ldr r1, _08018B9C
	b _08018BCE
	.align 2, 0
_08018B9C: .4byte 0x082C2A14
_08018BA0:
	ldr r1, _08018BA4
	b _08018BCE
	.align 2, 0
_08018BA4: .4byte 0x082C2A48
_08018BA8:
	ldr r1, _08018BAC
	b _08018BCE
	.align 2, 0
_08018BAC: .4byte 0x082C2A30
_08018BB0:
	ldr r1, _08018BB4
	b _08018BCE
	.align 2, 0
_08018BB4: .4byte 0x082C28E8
_08018BB8:
	ldr r1, _08018BBC
	b _08018BCE
	.align 2, 0
_08018BBC: .4byte 0x082C2A60
_08018BC0:
	adds r1, r4, #0
	b _08018BCE
_08018BC4:
	ldr r1, _08018BC8
	b _08018BCE
	.align 2, 0
_08018BC8: .4byte 0x082C2A00
_08018BCC:
	ldr r1, _08018BD8
_08018BCE:
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08018BD8: .4byte 0x082C2A78
	thumb_func_end mevent_message_stamp_card_etc_send_status

	thumb_func_start PrintMGSendStatus
PrintMGSendStatus: @ 0x08018BDC
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r0, sp
	bl mevent_message_stamp_card_etc_send_status
	adds r1, r0, #0
	ldr r0, [sp]
	cmp r0, #0
	bne _08018C02
	adds r0, r4, #0
	bl MG_PrintTextOnWindow1AndWaitButton
	b _08018C0A
_08018C02:
	adds r0, r4, #0
	adds r2, r5, #0
	bl PrintMGSuccessMessage
_08018C0A:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end PrintMGSendStatus
