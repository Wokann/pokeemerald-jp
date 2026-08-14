.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_08086CA4
sub_08086CA4: @ 0x08086CA4
	push {lr}
	ldrb r0, [r0, #2]
	cmp r0, #2
	beq _08086CB0
	cmp r0, #0
	bne _08086CB4
_08086CB0:
	movs r0, #1
	b _08086CB6
_08086CB4:
	movs r0, #0
_08086CB6:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08086CA4

	thumb_func_start sub_08086CBC
sub_08086CBC: @ 0x08086CBC
	push {lr}
	ldrb r0, [r0, #2]
	cmp r0, #2
	beq _08086CC8
	cmp r0, #0
	bne _08086CCC
_08086CC8:
	movs r0, #1
	b _08086CCE
_08086CCC:
	movs r0, #0
_08086CCE:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08086CBC

	thumb_func_start TryGetTileEventScript
TryGetTileEventScript: @ 0x08086CD4
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #2
	bne _08086CE6
	adds r0, r1, #4
	bl GetCoordEventScriptAtMapPosition
	b _08086CE8
_08086CE6:
	movs r0, #0
_08086CE8:
	pop {r1}
	bx r1
	thumb_func_end TryGetTileEventScript

	thumb_func_start PlayerIsAtSouthExit
PlayerIsAtSouthExit: @ 0x08086CEC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #2
	beq _08086CFA
	cmp r0, #0
	bne _08086D10
_08086CFA:
	ldrb r0, [r4, #0xc]
	bl MetatileBehavior_IsSouthArrowWarp
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08086D10
	ldrb r0, [r4, #3]
	cmp r0, #1
	bne _08086D10
	movs r0, #1
	b _08086D12
_08086D10:
	movs r0, #0
_08086D12:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end PlayerIsAtSouthExit

	thumb_func_start TryInteractWithPlayer
TryInteractWithPlayer: @ 0x08086D18
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08086D2C
	cmp r0, #2
	beq _08086D2C
	movs r0, #0
	b _08086DDA
_08086D2C:
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _08086D9C
	ldrb r0, [r4, #3]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldr r0, [r0]
	mov r1, sp
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08086DA0
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	asrs r1, r2, #0x10
	ldrb r0, [r4, #3]
	lsls r0, r0, #3
	adds r3, #4
	adds r0, r0, r3
	ldr r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _08086DA4
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r2, _08086DA8
	ldr r0, [sp, #4]
	ands r0, r2
	str r0, [sp, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	asrs r1, r1, #0x10
	bl GetLinkPlayerIdAt
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r2, r1, #0
	cmp r1, #4
	beq _08086DD0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08086D98
	ldr r0, _08086DAC
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, #0x80
	beq _08086DB4
_08086D98:
	ldr r0, _08086DB0
	b _08086DDA
	.align 2, 0
_08086D9C: .4byte 0x0830FCB0
_08086DA0: .4byte 0xFFFF0000
_08086DA4: .4byte 0x0000FFFF
_08086DA8: .4byte 0xFFFFFF00
_08086DAC: .4byte 0x03000E10
_08086DB0: .4byte 0x0824717B
_08086DB4:
	adds r0, r2, #0
	bl GetLinkTrainerCardColor
	cmp r0, #0
	bne _08086DC8
	ldr r0, _08086DC4
	b _08086DDA
	.align 2, 0
_08086DC4: .4byte 0x0824715D
_08086DC8:
	ldr r0, _08086DCC
	b _08086DDA
	.align 2, 0
_08086DCC: .4byte 0x0824716C
_08086DD0:
	ldrb r1, [r4, #0xc]
	ldrb r2, [r4, #3]
	mov r0, sp
	bl GetInteractedLinkPlayerScript
_08086DDA:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end TryInteractWithPlayer

	thumb_func_start GetDirectionForEventScript
GetDirectionForEventScript: @ 0x08086DE4
	push {lr}
	adds r1, r0, #0
	ldr r0, _08086E30
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E34
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E38
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E3C
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E40
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E44
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E48
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E4C
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E50
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E54
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E58
	cmp r1, r0
	bne _08086E5C
_08086E2A:
	movs r0, #0xa
	b _08086E6E
	.align 2, 0
_08086E30: .4byte 0x08247067
_08086E34: .4byte 0x08247082
_08086E38: .4byte 0x0824709D
_08086E3C: .4byte 0x082470B8
_08086E40: .4byte 0x082470FC
_08086E44: .4byte 0x08247111
_08086E48: .4byte 0x08247126
_08086E4C: .4byte 0x0824713B
_08086E50: .4byte 0x08247053
_08086E54: .4byte 0x0824705D
_08086E58: .4byte 0x082470D4
_08086E5C:
	ldr r0, _08086E68
	cmp r1, r0
	beq _08086E6C
	movs r0, #0
	b _08086E6E
	.align 2, 0
_08086E68: .4byte 0x082470DE
_08086E6C:
	movs r0, #9
_08086E6E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetDirectionForEventScript

	thumb_func_start sub_08086E74
sub_08086E74: @ 0x08086E74
	push {lr}
	bl LockPlayerFieldControls
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08086E74

	thumb_func_start InitLinkRoomStartMenuScript
InitLinkRoomStartMenuScript: @ 0x08086E80
	push {lr}
	movs r0, #6
	bl PlaySE
	bl ShowStartMenu
	bl LockPlayerFieldControls
	pop {r0}
	bx r0
	thumb_func_end InitLinkRoomStartMenuScript

	thumb_func_start InitMenuBasedScript
InitMenuBasedScript: @ 0x08086E94
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl PlaySE
	adds r0, r4, #0
	bl ScriptContext_SetupScript
	bl LockPlayerFieldControls
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end InitMenuBasedScript

	thumb_func_start CreateConfirmLeaveTradeRoomPrompt
CreateConfirmLeaveTradeRoomPrompt: @ 0x08086EB0
	push {lr}
	movs r0, #6
	bl PlaySE
	ldr r0, _08086EC8
	bl ScriptContext_SetupScript
	bl LockPlayerFieldControls
	pop {r0}
	bx r0
	.align 2, 0
_08086EC8: .4byte 0x082471CE
	thumb_func_end CreateConfirmLeaveTradeRoomPrompt

	thumb_func_start sub_08086ECC
sub_08086ECC: @ 0x08086ECC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl PlaySE
	adds r0, r4, #0
	bl ScriptContext_SetupScript
	bl LockPlayerFieldControls
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08086ECC

	thumb_func_start sub_08086EE8
sub_08086EE8: @ 0x08086EE8
	push {lr}
	ldr r0, _08086EF8
	bl ScriptContext_SetupScript
	bl LockPlayerFieldControls
	pop {r0}
	bx r0
	.align 2, 0
_08086EF8: .4byte 0x082471E8
	thumb_func_end sub_08086EE8

	thumb_func_start sub_08086EFC
sub_08086EFC: @ 0x08086EFC
	push {lr}
	bl IsUpdateLinkStateCBActive
	cmp r0, #0
	bne _08086F0A
	movs r0, #0
	b _08086F24
_08086F0A:
	bl GetLinkRecvQueueLength
	cmp r0, #2
	bls _08086F1C
	ldr r1, _08086F18
	movs r0, #1
	b _08086F20
	.align 2, 0
_08086F18: .4byte 0x03000E18
_08086F1C:
	ldr r1, _08086F28
	movs r0, #0
_08086F20:
	strb r0, [r1]
	ldrb r0, [r1]
_08086F24:
	pop {r1}
	bx r1
	.align 2, 0
_08086F28: .4byte 0x03000E18
	thumb_func_end sub_08086EFC

	thumb_func_start Overworld_RecvKeysFromLinkIsRunning
Overworld_RecvKeysFromLinkIsRunning: @ 0x08086F2C
	push {lr}
	bl GetLinkRecvQueueLength
	cmp r0, #1
	bls _08086F90
	bl IsUpdateLinkStateCBActive
	cmp r0, #1
	bne _08086F90
	bl IsSendingKeysToLink
	cmp r0, #1
	bne _08086F90
	ldr r0, _08086F7C
	ldr r1, [r0]
	ldr r0, _08086F80
	cmp r1, r0
	beq _08086F78
	ldr r0, _08086F84
	cmp r1, r0
	bne _08086F90
	ldr r0, _08086F88
	ldrb r2, [r0]
	movs r1, #0
	strb r1, [r0]
	cmp r2, #1
	beq _08086F78
	ldr r2, _08086F8C
	ldrb r1, [r2, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08086F90
	ldrb r1, [r2, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08086F90
_08086F78:
	movs r0, #1
	b _08086F92
	.align 2, 0
_08086F7C: .4byte 0x03000E14
_08086F80: .4byte 0x08086A81
_08086F84: .4byte 0x08086A5D
_08086F88: .4byte 0x03000E18
_08086F8C: .4byte 0x02037C74
_08086F90:
	movs r0, #0
_08086F92:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end Overworld_RecvKeysFromLinkIsRunning

	thumb_func_start Overworld_SendKeysToLinkIsRunning
Overworld_SendKeysToLinkIsRunning: @ 0x08086F98
	push {lr}
	bl GetLinkSendQueueLength
	cmp r0, #1
	bls _08086FBC
	bl IsUpdateLinkStateCBActive
	cmp r0, #1
	bne _08086FBC
	bl IsSendingKeysToLink
	cmp r0, #1
	bne _08086FBC
	ldr r0, _08086FC0
	ldr r1, [r0]
	ldr r0, _08086FC4
	cmp r1, r0
	beq _08086FC8
_08086FBC:
	movs r0, #0
	b _08086FCA
	.align 2, 0
_08086FC0: .4byte 0x03000E14
_08086FC4: .4byte 0x08086AA5
_08086FC8:
	movs r0, #1
_08086FCA:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end Overworld_SendKeysToLinkIsRunning

	thumb_func_start IsSendingKeysOverCable
IsSendingKeysOverCable: @ 0x08086FD0
	push {lr}
	ldr r0, _08086FE8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08086FEC
	bl IsSendingKeysToLink
	cmp r0, #0
	beq _08086FEC
	movs r0, #1
	b _08086FEE
	.align 2, 0
_08086FE8: .4byte 0x0300319C
_08086FEC:
	movs r0, #0
_08086FEE:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsSendingKeysOverCable

	thumb_func_start GetLinkSendQueueLength
GetLinkSendQueueLength: @ 0x08086FF4
	push {lr}
	ldr r0, _08087008
	ldrb r0, [r0]
	cmp r0, #0
	bne _08087014
	ldr r0, _0808700C
	ldr r1, _08087010
	adds r0, r0, r1
	ldrb r0, [r0]
	b _0808701C
	.align 2, 0
_08087008: .4byte 0x0300319C
_0808700C: .4byte 0x03003210
_08087010: .4byte 0x00000339
_08087014:
	ldr r0, _08087020
	ldr r1, _08087024
	adds r0, r0, r1
	ldrb r0, [r0]
_0808701C:
	pop {r1}
	bx r1
	.align 2, 0
_08087020: .4byte 0x030050A0
_08087024: .4byte 0x000008D2
	thumb_func_end GetLinkSendQueueLength

	thumb_func_start ZeroLinkPlayerObjectEvent
ZeroLinkPlayerObjectEvent: @ 0x08087028
	@ From src/overworld.c (ZeroLinkPlayerObjectEvent)
	movs r1, #0
	str r1, [r0]
	bx lr
	.align 2, 0
	thumb_func_end ZeroLinkPlayerObjectEvent

	thumb_func_start ClearLinkPlayerEventObjects
ClearLinkPlayerEventObjects: @ 0x08087030
	push {lr}
	ldr r0, _08087040
	movs r1, #0
	movs r2, #0x10
	bl memset
	pop {r0}
	bx r0
	.align 2, 0
_08087040: .4byte 0x02031FA8
	thumb_func_end ClearLinkPlayerEventObjects

	thumb_func_start ZeroEventObject
ZeroEventObject: @ 0x08087044
	push {lr}
	movs r1, #0
	movs r2, #0x24
	bl memset
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ZeroEventObject

	thumb_func_start SpawnLinkPlayerEventObject
SpawnLinkPlayerEventObject: @ 0x08087054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r1
	mov sl, r2
	mov r8, r3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	mov r2, r8
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	bl GetFirstInactiveEventObjectId
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r4, r7, #2
	ldr r0, _080870F8
	adds r4, r4, r0
	lsls r5, r6, #3
	adds r5, r5, r6
	lsls r5, r5, #2
	ldr r0, _080870FC
	adds r5, r5, r0
	adds r0, r4, #0
	bl ZeroLinkPlayerObjectEvent
	adds r0, r5, #0
	bl ZeroEventObject
	movs r2, #0
	movs r1, #1
	movs r0, #1
	strb r0, [r4]
	strb r7, [r4, #1]
	strb r6, [r4, #2]
	strb r2, [r4, #3]
	ldrb r0, [r5]
	orrs r0, r1
	mov r2, r8
	ands r2, r1
	lsls r2, r2, #1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	movs r0, #2
	strb r0, [r5, #0x19]
	movs r0, #0x40
	strb r0, [r5, #4]
	mov r0, sb
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov sb, r0
	mov r1, sl
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov sl, r1
	adds r0, r5, #0
	mov r1, sb
	mov r2, sl
	bl InitLinkPlayerEventObjectPos
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080870F8: .4byte 0x02031FA8
_080870FC: .4byte 0x02036FF0
	thumb_func_end SpawnLinkPlayerEventObject

	thumb_func_start InitLinkPlayerEventObjectPos
InitLinkPlayerEventObjectPos: @ 0x08087100
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	strh r0, [r4, #0x10]
	strh r1, [r4, #0x12]
	strh r0, [r4, #0x14]
	strh r1, [r4, #0x16]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, r4, #0
	adds r2, #0xc
	adds r3, r4, #0
	adds r3, #0xe
	bl SetSpritePosToMapCoords
	ldrh r0, [r4, #0xc]
	adds r0, #8
	strh r0, [r4, #0xc]
	adds r0, r4, #0
	bl EventObjectUpdateZCoord
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end InitLinkPlayerEventObjectPos

	thumb_func_start sub_08087140
sub_08087140: @ 0x08087140
	push {lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	ldr r1, _08087168
	lsrs r0, r0, #0x16
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _08087162
	ldrb r0, [r1, #2]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0808716C
	adds r1, r1, r0
	strb r2, [r1, #0x19]
_08087162:
	pop {r0}
	bx r0
	.align 2, 0
_08087168: .4byte 0x02031FA8
_0808716C: .4byte 0x02036FF0
	thumb_func_end sub_08087140

	thumb_func_start sub_08087170
sub_08087170: @ 0x08087170
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	ldr r1, _080871B0
	adds r5, r0, r1
	ldrb r1, [r5, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871B4
	adds r4, r0, r1
	ldrb r0, [r4, #4]
	cmp r0, #0x40
	beq _0808719C
	adds r1, r0, #0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871B8
	adds r0, r0, r1
	bl DestroySprite
_0808719C:
	movs r0, #0
	strb r0, [r5]
	ldrb r1, [r4]
	subs r0, #2
	ands r0, r1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080871B0: .4byte 0x02031FA8
_080871B4: .4byte 0x02036FF0
_080871B8: .4byte 0x020205AC
	thumb_func_end sub_08087170

	thumb_func_start GetSpriteForLinkedPlayer
GetSpriteForLinkedPlayer: @ 0x080871BC
	lsls r0, r0, #0x18
	ldr r1, _080871D4
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871D8
	adds r0, r0, r1
	ldrb r0, [r0, #4]
	bx lr
	.align 2, 0
_080871D4: .4byte 0x02031FA8
_080871D8: .4byte 0x02036FF0
	thumb_func_end GetSpriteForLinkedPlayer

	thumb_func_start GetLinkPlayerCoords
GetLinkPlayerCoords: @ 0x080871DC
	lsls r0, r0, #0x18
	ldr r3, _080871FC
	lsrs r0, r0, #0x16
	adds r0, r0, r3
	ldrb r3, [r0, #2]
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r3, _08087200
	adds r0, r0, r3
	ldrh r3, [r0, #0x10]
	strh r3, [r1]
	ldrh r0, [r0, #0x12]
	strh r0, [r2]
	bx lr
	.align 2, 0
_080871FC: .4byte 0x02031FA8
_08087200: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerCoords

	thumb_func_start GetLinkPlayerFacingDirection
GetLinkPlayerFacingDirection: @ 0x08087204
	lsls r0, r0, #0x18
	ldr r1, _0808721C
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087220
	adds r0, r0, r1
	ldrb r0, [r0, #0x19]
	bx lr
	.align 2, 0
_0808721C: .4byte 0x02031FA8
_08087220: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerFacingDirection

	thumb_func_start GetLinkPlayerElevation
GetLinkPlayerElevation: @ 0x08087224
	lsls r0, r0, #0x18
	ldr r1, _08087240
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087244
	adds r0, r0, r1
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	bx lr
	.align 2, 0
_08087240: .4byte 0x02031FA8
_08087244: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerElevation

	thumb_func_start sub_08087248
sub_08087248: @ 0x08087248
	lsls r0, r0, #0x18
	ldr r1, _08087268
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0808726C
	adds r0, r0, r1
	adds r0, #0x21
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x10
	subs r0, r0, r1
	bx lr
	.align 2, 0
_08087268: .4byte 0x02031FA8
_0808726C: .4byte 0x02036FF0
	thumb_func_end sub_08087248

	thumb_func_start GetLinkPlayerIdAt
GetLinkPlayerIdAt: @ 0x08087270
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r5, _080872B4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	lsls r1, r1, #0x10
	asrs r3, r1, #0x10
_0808727E:
	lsls r0, r2, #2
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0
	beq _080872BC
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _08087292
	cmp r0, #2
	bne _080872BC
_08087292:
	ldrb r1, [r1, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080872B8
	adds r1, r0, r1
	movs r6, #0x10
	ldrsh r0, [r1, r6]
	cmp r0, r4
	bne _080872BC
	movs r6, #0x12
	ldrsh r0, [r1, r6]
	cmp r0, r3
	bne _080872BC
	adds r0, r2, #0
	b _080872C8
	.align 2, 0
_080872B4: .4byte 0x02031FA8
_080872B8: .4byte 0x02036FF0
_080872BC:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _0808727E
	movs r0, #4
_080872C8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetLinkPlayerIdAt

	thumb_func_start SetPlayerFacingDirection
SetPlayerFacingDirection: @ 0x080872D0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	adds r2, r3, #0
	lsrs r0, r0, #0x16
	ldr r1, _08087300
	adds r5, r0, r1
	ldrb r1, [r5, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087304
	adds r6, r0, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _0808732C
	cmp r3, #0xa
	bls _08087308
	ldrb r0, [r6]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6]
	b _0808732C
	.align 2, 0
_08087300: .4byte 0x02031FA8
_08087304: .4byte 0x02036FF0
_08087308:
	ldr r4, _08087334
	ldr r1, _08087338
	ldrb r0, [r5, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
_0808732C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087334: .4byte 0x0830FD4C
_08087338: .4byte 0x0830FD14
	thumb_func_end SetPlayerFacingDirection

	thumb_func_start MovementEventModeCB_Normal
MovementEventModeCB_Normal: @ 0x0808733C
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, _08087358
	lsls r3, r2, #2
	adds r3, r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08087358: .4byte 0x0830FD20
	thumb_func_end MovementEventModeCB_Normal

	thumb_func_start MovementEventModeCB_Ignored
MovementEventModeCB_Ignored: @ 0x0808735C
	movs r0, #1
	bx lr
	thumb_func_end MovementEventModeCB_Ignored

	thumb_func_start MovementEventModeCB_Normal_2
MovementEventModeCB_Normal_2: @ 0x08087360
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, _0808737C
	lsls r3, r2, #2
	adds r3, r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808737C: .4byte 0x0830FD20
	thumb_func_end MovementEventModeCB_Normal_2

	thumb_func_start FacingHandler_DoNothing
FacingHandler_DoNothing: @ 0x08087380
	movs r0, #0
	bx lr
	thumb_func_end FacingHandler_DoNothing

	thumb_func_start FacingHandler_DpadMovement
FacingHandler_DpadMovement: @ 0x08087384
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #0x19]
	bl FlipVerticalAndClearForced
	strb r0, [r5, #0x19]
	ldrb r1, [r5, #0x19]
	mov r6, sp
	adds r6, #2
	adds r0, r5, #0
	mov r2, sp
	adds r3, r6, #0
	bl EventObjectMoveDestCoords
	ldrb r0, [r4, #2]
	ldrb r1, [r5, #0x19]
	mov r2, sp
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r4, #0
	ldrsh r3, [r6, r4]
	bl LinkPlayerDetectCollision
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080873E2
	adds r1, r5, #0
	adds r1, #0x21
	movs r0, #0x10
	strb r0, [r1]
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r2, [r6, r3]
	adds r0, r5, #0
	bl ShiftEventObjectCoords
	adds r0, r5, #0
	bl EventObjectUpdateZCoord
	movs r0, #1
	b _080873E4
_080873E2:
	movs r0, #0
_080873E4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end FacingHandler_DpadMovement

	thumb_func_start FacingHandler_ForcedFacingChange
FacingHandler_ForcedFacingChange: @ 0x080873EC
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #0x19]
	bl FlipVerticalAndClearForced
	strb r0, [r4, #0x19]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FacingHandler_ForcedFacingChange

	thumb_func_start MovementStatusHandler_EnterFreeMode
MovementStatusHandler_EnterFreeMode: @ 0x08087404
	@ From src/overworld.c
	movs r1, #0
	strb r1, [r0, #3]
	bx lr
	.align 2, 0
	thumb_func_end MovementStatusHandler_EnterFreeMode

	thumb_func_start MovementStatusHandler_TryAdvanceScript
MovementStatusHandler_TryAdvanceScript: @ 0x0808740C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x21
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	movs r0, #1
	strb r0, [r6, #3]
	ldrb r0, [r4, #0x19]
	adds r1, #0xc
	adds r2, r4, #0
	adds r2, #0xe
	bl MoveCoords
	ldrb r0, [r5]
	cmp r0, #0
	bne _0808743C
	adds r0, r4, #0
	bl ShiftStillEventObjectCoords
	movs r0, #2
	strb r0, [r6, #3]
_0808743C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end MovementStatusHandler_TryAdvanceScript

	thumb_func_start FlipVerticalAndClearForced
FlipVerticalAndClearForced: @ 0x08087444
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	subs r0, #1
	cmp r0, #9
	bhi _0808749C
	lsls r0, r0, #2
	ldr r1, _08087460
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087460: .4byte 0x08087464
_08087464: @ jump table
	.4byte _0808748C @ case 0
	.4byte _08087490 @ case 1
	.4byte _08087494 @ case 2
	.4byte _08087498 @ case 3
	.4byte _0808749C @ case 4
	.4byte _0808749C @ case 5
	.4byte _0808748C @ case 6
	.4byte _08087490 @ case 7
	.4byte _08087494 @ case 8
	.4byte _08087498 @ case 9
_0808748C:
	movs r0, #2
	b _0808749E
_08087490:
	movs r0, #1
	b _0808749E
_08087494:
	movs r0, #3
	b _0808749E
_08087498:
	movs r0, #4
	b _0808749E
_0808749C:
	adds r0, r2, #0
_0808749E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end FlipVerticalAndClearForced

	thumb_func_start LinkPlayerDetectCollision
LinkPlayerDetectCollision: @ 0x080874A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov ip, r2
	lsls r3, r3, #0x10
	movs r4, #0
	ldr r0, _08087508
	mov sb, r0
	lsrs r2, r3, #0x10
	mov sl, r2
	asrs r6, r3, #0x10
_080874C8:
	mov r7, ip
	lsls r3, r7, #0x10
	mov r0, sl
	lsls r5, r0, #0x10
	cmp r4, r8
	beq _0808750C
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	mov r2, sb
	adds r1, r0, r2
	movs r7, #0x10
	ldrsh r0, [r1, r7]
	asrs r2, r3, #0x10
	cmp r0, r2
	bne _080874F0
	movs r7, #0x12
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _08087502
_080874F0:
	movs r7, #0x14
	ldrsh r0, [r1, r7]
	cmp r0, r2
	bne _0808750C
	movs r0, #0x16
	ldrsh r1, [r1, r0]
	asrs r0, r5, #0x10
	cmp r1, r0
	bne _0808750C
_08087502:
	movs r0, #1
	b _08087522
	.align 2, 0
_08087508: .4byte 0x02036FF0
_0808750C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _080874C8
	asrs r0, r3, #0x10
	asrs r1, r5, #0x10
	bl MapGridGetCollisionAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08087522:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end LinkPlayerDetectCollision

	thumb_func_start CreateLinkPlayerSprite
CreateLinkPlayerSprite: @ 0x08087530
	push {r4, r5, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	lsls r2, r5, #2
	ldr r0, _08087564
	adds r2, r2, r0
	ldrb r1, [r2, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087568
	adds r4, r0, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080875DE
	subs r0, r3, #1
	cmp r0, #4
	bhi _080875BA
	lsls r0, r0, #2
	ldr r1, _0808756C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087564: .4byte 0x02031FA8
_08087568: .4byte 0x02036FF0
_0808756C: .4byte 0x08087570
_08087570: @ jump table
	.4byte _08087590 @ case 0
	.4byte _08087590 @ case 1
	.4byte _0808759C @ case 2
	.4byte _08087584 @ case 3
	.4byte _08087584 @ case 4
_08087584:
	ldrb r0, [r4]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	bl sub_0808B6D0
	b _080875A8
_08087590:
	ldrb r0, [r4]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	bl GetFRLGAvatarGraphicsIdByGender
	b _080875A8
_0808759C:
	ldrb r1, [r4]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1f
	movs r0, #0
	bl GetPlayerAvatarGraphicsIdByStateIdAndGender
_080875A8:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080875E8
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl AddPseudoEventObject
	strb r0, [r4, #4]
_080875BA:
	ldrb r1, [r4, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080875EC
	adds r0, r0, r1
	adds r3, r0, #0
	adds r3, #0x3e
	ldrb r1, [r3]
	movs r2, #2
	orrs r1, r2
	strb r1, [r3]
	strh r5, [r0, #0x2e]
	ldrb r1, [r4]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4]
_080875DE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080875E8: .4byte 0x080875F1
_080875EC: .4byte 0x020205AC
	thumb_func_end CreateLinkPlayerSprite

	thumb_func_start SpriteCB_LinkPlayer
SpriteCB_LinkPlayer: @ 0x080875F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x2e
	ldrsh r4, [r5, r0]
	lsls r4, r4, #2
	ldr r0, _08087654
	adds r4, r4, r0
	ldrb r1, [r4, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087658
	adds r6, r0, r1
	ldrh r0, [r6, #0xc]
	strh r0, [r5, #0x20]
	ldrh r0, [r6, #0xe]
	strh r0, [r5, #0x22]
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #4
	adds r1, r5, #0
	movs r2, #1
	bl SetObjectSubpriorityByElevation
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #4
	bl ElevationToPriority
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #5]
	ldrb r0, [r4, #3]
	cmp r0, #0
	bne _0808765C
	ldrb r0, [r6, #0x19]
	bl GetJumpInPlaceMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl StartSpriteAnim
	b _0808766E
	.align 2, 0
_08087654: .4byte 0x02031FA8
_08087658: .4byte 0x02036FF0
_0808765C:
	ldrb r0, [r6, #0x19]
	bl GetJumpInPlaceTurnAroundMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl StartSpriteAnimIfDifferent
_0808766E:
	adds r0, r5, #0
	movs r1, #0
	bl UpdateObjectEventSpriteInvisibility
	ldrb r0, [r6]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _080876A0
	ldrh r0, [r5, #0x3c]
	movs r1, #4
	ands r1, r0
	lsls r1, r1, #0x10
	adds r3, r5, #0
	adds r3, #0x3e
	lsrs r1, r1, #0x12
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r5, #0x3c]
	adds r0, #1
	strh r0, [r5, #0x3c]
_080876A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SpriteCB_LinkPlayer



