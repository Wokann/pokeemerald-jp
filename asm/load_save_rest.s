
.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified





	thumb_func_start LoadPlayerBag
LoadPlayerBag: @ 0x080768D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r2, #0
	ldr r0, _080769D4
	mov ip, r0
	ldr r1, _080769D8
	mov sl, r1
	ldr r5, _080769DC
	movs r3, #0xac
	lsls r3, r3, #3
	ldr r4, _080769E0
_080768F0:
	lsls r0, r2, #2
	ldr r1, [r5]
	adds r1, r1, r3
	adds r1, r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #0x1d
	ble _080768F0
	movs r2, #0
	ldr r0, _080769E0
	ldr r5, _080769DC
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r4, r0, #0
	adds r4, #0x78
_08076910:
	lsls r0, r2, #2
	ldr r1, [r5]
	adds r1, r1, r3
	adds r1, r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #0x1d
	ble _08076910
	movs r2, #0
	ldr r0, _080769E0
	ldr r5, _080769DC
	movs r3, #0xca
	lsls r3, r3, #3
	adds r4, r0, #0
	adds r4, #0xf0
_08076930:
	lsls r0, r2, #2
	ldr r1, [r5]
	adds r1, r1, r3
	adds r1, r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #0xf
	ble _08076930
	movs r2, #0
	ldr r0, _080769E0
	ldr r5, _080769DC
	movs r6, #0x98
	lsls r6, r6, #1
	adds r4, r0, r6
	movs r3, #0xd2
	lsls r3, r3, #3
_08076952:
	lsls r0, r2, #2
	ldr r1, [r5]
	adds r1, r1, r3
	adds r1, r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #0x3f
	ble _08076952
	movs r2, #0
	ldr r0, _080769E0
	ldr r5, _080769DC
	movs r7, #0x8c
	lsls r7, r7, #2
	adds r4, r0, r7
	movs r3, #0xf2
	lsls r3, r3, #3
_08076974:
	lsls r0, r2, #2
	ldr r1, [r5]
	adds r1, r1, r3
	adds r1, r1, r0
	ldr r0, [r1]
	stm r4!, {r0}
	adds r2, #1
	cmp r2, #0x2d
	ble _08076974
	ldr r0, _080769E0
	ldr r1, _080769DC
	mov r8, r1
	movs r5, #0xba
	lsls r5, r5, #2
	adds r4, r0, r5
	movs r3, #0
	ldr r6, _080769E4
	mov sb, r6
	movs r2, #0xf
_0807699A:
	mov r7, r8
	ldr r1, [r7]
	adds r1, r1, r3
	adds r0, r4, #0
	add r1, sb
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	adds r4, #0x24
	adds r3, #0x24
	subs r2, #1
	cmp r2, #0
	bge _0807699A
	mov r1, sl
	ldr r0, [r1]
	adds r0, #0xac
	ldr r0, [r0]
	mov r5, ip
	str r0, [r5]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080769D4: .4byte 0x02031E24
_080769D8: .4byte 0x03005AF0
_080769DC: .4byte 0x03005AEC
_080769E0: .4byte 0x020318FC
_080769E4: .4byte 0x00002BE0
	thumb_func_end LoadPlayerBag

	thumb_func_start SavePlayerBag
SavePlayerBag: @ 0x080769E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r2, #0
	ldr r0, _08076AF4
	mov r8, r0
	ldr r1, _08076AF8
	mov ip, r1
	ldr r5, _08076AFC
	movs r3, #0xac
	lsls r3, r3, #3
	ldr r4, _08076B00
_08076A04:
	ldr r0, [r5]
	lsls r1, r2, #2
	adds r0, r0, r3
	adds r0, r0, r1
	ldm r4!, {r1}
	str r1, [r0]
	adds r2, #1
	cmp r2, #0x1d
	ble _08076A04
	movs r2, #0
	ldr r5, _08076AFC
	movs r4, #0xbb
	lsls r4, r4, #3
	ldr r0, _08076B00
	adds r3, r0, #0
	adds r3, #0x78
_08076A24:
	ldr r0, [r5]
	lsls r1, r2, #2
	adds r0, r0, r4
	adds r0, r0, r1
	ldm r3!, {r1}
	str r1, [r0]
	adds r2, #1
	cmp r2, #0x1d
	ble _08076A24
	movs r2, #0
	ldr r5, _08076AFC
	movs r4, #0xca
	lsls r4, r4, #3
	ldr r0, _08076B00
	adds r3, r0, #0
	adds r3, #0xf0
_08076A44:
	ldr r0, [r5]
	lsls r1, r2, #2
	adds r0, r0, r4
	adds r0, r0, r1
	ldm r3!, {r1}
	str r1, [r0]
	adds r2, #1
	cmp r2, #0xf
	ble _08076A44
	movs r2, #0
	ldr r5, _08076AFC
	movs r4, #0xd2
	lsls r4, r4, #3
	ldr r0, _08076B00
	movs r6, #0x98
	lsls r6, r6, #1
	adds r3, r0, r6
_08076A66:
	ldr r0, [r5]
	lsls r1, r2, #2
	adds r0, r0, r4
	adds r0, r0, r1
	ldm r3!, {r1}
	str r1, [r0]
	adds r2, #1
	cmp r2, #0x3f
	ble _08076A66
	movs r2, #0
	ldr r5, _08076AFC
	movs r4, #0xf2
	lsls r4, r4, #3
	ldr r0, _08076B00
	movs r7, #0x8c
	lsls r7, r7, #2
	adds r3, r0, r7
_08076A88:
	ldr r0, [r5]
	lsls r1, r2, #2
	adds r0, r0, r4
	adds r0, r0, r1
	ldm r3!, {r1}
	str r1, [r0]
	adds r2, #1
	cmp r2, #0x2d
	ble _08076A88
	ldr r0, _08076AFC
	mov sb, r0
	ldr r1, _08076B04
	mov sl, r1
	ldr r4, _08076B00
	movs r3, #0
	movs r2, #0xf
_08076AA8:
	mov r5, sb
	ldr r1, [r5]
	adds r1, r1, r3
	add r1, sl
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r4, r6
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	adds r4, #0x24
	adds r3, #0x24
	subs r2, #1
	cmp r2, #0
	bge _08076AA8
	mov r7, r8
	ldr r0, [r7]
	adds r0, #0xac
	ldr r4, [r0]
	mov r2, ip
	ldr r1, [r2]
	str r1, [r0]
	adds r0, r4, #0
	bl ApplyNewEncryptionKeyToBagItems
	ldr r0, [r7]
	adds r0, #0xac
	str r4, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08076AF4: .4byte 0x03005AF0
_08076AF8: .4byte 0x02031E24
_08076AFC: .4byte 0x03005AEC
_08076B00: .4byte 0x020318FC
_08076B04: .4byte 0x00002BE0
	thumb_func_end SavePlayerBag

	thumb_func_start ApplyNewEncryptionKeyToHword
ApplyNewEncryptionKeyToHword: @ 0x08076B08
	ldr r2, _08076B1C
	ldr r2, [r2]
	adds r2, #0xac
	ldr r2, [r2]
	ldrh r3, [r0]
	eors r2, r3
	eors r2, r1
	strh r2, [r0]
	bx lr
	.align 2, 0
_08076B1C: .4byte 0x03005AF0
	thumb_func_end ApplyNewEncryptionKeyToHword

	thumb_func_start ApplyNewEncryptionKeyToWord
ApplyNewEncryptionKeyToWord: @ 0x08076B20
	ldr r2, _08076B34
	ldr r3, [r2]
	adds r3, #0xac
	ldr r2, [r0]
	ldr r3, [r3]
	eors r2, r3
	eors r2, r1
	str r2, [r0]
	bx lr
	.align 2, 0
_08076B34: .4byte 0x03005AF0
	thumb_func_end ApplyNewEncryptionKeyToWord

	thumb_func_start ApplyNewEncryptionKeyToAllEncryptedData
ApplyNewEncryptionKeyToAllEncryptedData: @ 0x08076B38
	push {r4, r5, lr}
	adds r4, r0, #0
	bl ApplyNewEncryptionKeyToGameStats
	adds r0, r4, #0
	bl ApplyNewEncryptionKeyToBagItems_
	adds r0, r4, #0
	bl ApplyNewEncryptionKeyToBerryPowder
	ldr r5, _08076B70
	ldr r0, [r5]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r4, #0
	bl ApplyNewEncryptionKeyToWord
	ldr r0, [r5]
	ldr r1, _08076B74
	adds r0, r0, r1
	adds r1, r4, #0
	bl ApplyNewEncryptionKeyToHword
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08076B70: .4byte 0x03005AEC
_08076B74: .4byte 0x00000494
	thumb_func_end ApplyNewEncryptionKeyToAllEncryptedData
