.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start CheckBoxMonSanityAt
CheckBoxMonSanityAt: @ 0x080D1B10
	push {r4, r5, r6, lr}
	adds r2, r1, #0
	cmp r0, #0xd
	bhi _080D1B68
	cmp r2, #0x1d
	bhi _080D1B68
	ldr r6, _080D1B64
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r5, r0, #4
	ldr r0, [r6]
	adds r0, r0, r5
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r4, r1, #4
	adds r0, r0, r4
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1B68
	ldr r0, [r6]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #6
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1B68
	ldr r0, [r6]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #4
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1B68
	movs r0, #1
	b _080D1B6A
	.align 2, 0
_080D1B64: .4byte 0x03005AF4
_080D1B68:
	movs r0, #0
_080D1B6A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end CheckBoxMonSanityAt

	thumb_func_start CountStorageNonEggMons
CountStorageNonEggMons: @ 0x080D1B70
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r0, #0
	ldr r1, _080D1BD8
	mov sb, r1
_080D1B80:
	lsls r1, r0, #2
	adds r2, r0, #1
	mov r8, r2
	adds r1, r1, r0
	movs r5, #0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r4, r0, #4
	movs r6, #0x1d
_080D1B94:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1BBA
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #6
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1BBA
	adds r7, #1
_080D1BBA:
	adds r5, #0x50
	subs r6, #1
	cmp r6, #0
	bge _080D1B94
	mov r0, r8
	cmp r0, #0xd
	ble _080D1B80
	adds r0, r7, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D1BD8: .4byte 0x03005AF4
	thumb_func_end CountStorageNonEggMons

	thumb_func_start CountAllStorageMons
CountAllStorageMons: @ 0x080D1BDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r0, #0
	ldr r1, _080D1C44
	mov sb, r1
_080D1BEC:
	lsls r1, r0, #2
	adds r2, r0, #1
	mov r8, r2
	adds r1, r1, r0
	movs r5, #0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r4, r0, #4
	movs r6, #0x1d
_080D1C00:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1C24
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #6
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1C26
_080D1C24:
	adds r7, #1
_080D1C26:
	adds r5, #0x50
	subs r6, #1
	cmp r6, #0
	bge _080D1C00
	mov r0, r8
	cmp r0, #0xd
	ble _080D1BEC
	adds r0, r7, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D1C44: .4byte 0x03005AF4
	thumb_func_end CountAllStorageMons

	thumb_func_start AnyStorageMonWithMove
AnyStorageMonWithMove: @ 0x080D1C48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r1, sp
	strh r0, [r1]
	ldr r0, _080D1C9C
	strh r0, [r1, #2]
	movs r0, #0
	mov r8, r0
	ldr r7, _080D1CA0
	movs r5, #4
_080D1C60:
	movs r6, #0
	movs r4, #0
_080D1C64:
	ldr r0, [r7]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1CA4
	ldr r0, [r7]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #6
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1CA4
	ldr r0, [r7]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #0x51
	mov r2, sp
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1CA4
	movs r0, #1
	b _080D1CBE
	.align 2, 0
_080D1C9C: .4byte 0x00000163
_080D1CA0: .4byte 0x03005AF4
_080D1CA4:
	adds r4, #0x50
	adds r6, #1
	cmp r6, #0x1d
	ble _080D1C64
	movs r0, #0x96
	lsls r0, r0, #4
	adds r5, r5, r0
	movs r0, #1
	add r8, r0
	mov r0, r8
	cmp r0, #0xd
	ble _080D1C60
	movs r0, #0
_080D1CBE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end AnyStorageMonWithMove

	thumb_func_start ResetWaldaWallpaper
ResetWaldaWallpaper: @ 0x080D1CCC
	ldr r2, _080D1D04
	ldr r0, [r2]
	ldr r1, _080D1D08
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _080D1D0C
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, _080D1D10
	adds r2, r1, r0
	ldr r0, _080D1D14
	strh r0, [r2]
	subs r3, #0x14
	adds r2, r1, r3
	ldr r0, _080D1D18
	strh r0, [r2]
	ldr r0, _080D1D1C
	adds r1, r1, r0
	movs r0, #0xff
	strb r0, [r1]
	bx lr
	.align 2, 0
_080D1D04: .4byte 0x03005AEC
_080D1D08: .4byte 0x00003D84
_080D1D0C: .4byte 0x00003D85
_080D1D10: .4byte 0x00003D70
_080D1D14: .4byte 0x00007B35
_080D1D18: .4byte 0x00006186
_080D1D1C: .4byte 0x00003D74
	thumb_func_end ResetWaldaWallpaper

	thumb_func_start SetWaldaWallpaperLockedOrUnlocked
SetWaldaWallpaperLockedOrUnlocked: @ 0x080D1D20
	ldr r1, _080D1D2C
	ldr r1, [r1]
	ldr r2, _080D1D30
	adds r1, r1, r2
	strb r0, [r1]
	bx lr
	.align 2, 0
_080D1D2C: .4byte 0x03005AEC
_080D1D30: .4byte 0x00003D86
	thumb_func_end SetWaldaWallpaperLockedOrUnlocked

	thumb_func_start IsWaldaWallpaperUnlocked
IsWaldaWallpaperUnlocked: @ 0x080D1D34
	ldr r0, _080D1D40
	ldr r0, [r0]
	ldr r1, _080D1D44
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080D1D40: .4byte 0x03005AEC
_080D1D44: .4byte 0x00003D86
	thumb_func_end IsWaldaWallpaperUnlocked

	thumb_func_start sub_080D1D48
sub_080D1D48: @ 0x080D1D48
	ldr r0, _080D1D54
	ldr r0, [r0]
	ldr r1, _080D1D58
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080D1D54: .4byte 0x03005AEC
_080D1D58: .4byte 0x00003D85
	thumb_func_end sub_080D1D48

	thumb_func_start SetWaldaWallpaperPatternId
SetWaldaWallpaperPatternId: @ 0x080D1D5C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xf
	bhi _080D1D70
	ldr r0, _080D1D74
	ldr r0, [r0]
	ldr r2, _080D1D78
	adds r0, r0, r2
	strb r1, [r0]
_080D1D70:
	pop {r0}
	bx r0
	.align 2, 0
_080D1D74: .4byte 0x03005AEC
_080D1D78: .4byte 0x00003D85
	thumb_func_end SetWaldaWallpaperPatternId

	thumb_func_start GetWaldaWallpaperIconId
GetWaldaWallpaperIconId: @ 0x080D1D7C
	ldr r0, _080D1D88
	ldr r0, [r0]
	ldr r1, _080D1D8C
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080D1D88: .4byte 0x03005AEC
_080D1D8C: .4byte 0x00003D84
	thumb_func_end GetWaldaWallpaperIconId

	thumb_func_start SetWaldaWallpaperIconId
SetWaldaWallpaperIconId: @ 0x080D1D90
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x1d
	bhi _080D1DA4
	ldr r0, _080D1DA8
	ldr r0, [r0]
	ldr r2, _080D1DAC
	adds r0, r0, r2
	strb r1, [r0]
_080D1DA4:
	pop {r0}
	bx r0
	.align 2, 0
_080D1DA8: .4byte 0x03005AEC
_080D1DAC: .4byte 0x00003D84
	thumb_func_end SetWaldaWallpaperIconId

	thumb_func_start sub_080D1DB0
sub_080D1DB0: @ 0x080D1DB0
	ldr r0, _080D1DBC
	ldr r0, [r0]
	ldr r1, _080D1DC0
	adds r0, r0, r1
	bx lr
	.align 2, 0
_080D1DBC: .4byte 0x03005AEC
_080D1DC0: .4byte 0x00003D70
	thumb_func_end sub_080D1DB0

	thumb_func_start SetWaldaWallpaperColors
SetWaldaWallpaperColors: @ 0x080D1DC4
	push {r4, lr}
	ldr r2, _080D1DDC
	ldr r2, [r2]
	ldr r4, _080D1DE0
	adds r3, r2, r4
	strh r0, [r3]
	ldr r0, _080D1DE4
	adds r2, r2, r0
	strh r1, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1DDC: .4byte 0x03005AEC
_080D1DE0: .4byte 0x00003D70
_080D1DE4: .4byte 0x00003D72
	thumb_func_end SetWaldaWallpaperColors

	thumb_func_start GetWaldaPhrasePtr
GetWaldaPhrasePtr: @ 0x080D1DE8
	ldr r0, _080D1DF4
	ldr r0, [r0]
	ldr r1, _080D1DF8
	adds r0, r0, r1
	bx lr
	.align 2, 0
_080D1DF4: .4byte 0x03005AEC
_080D1DF8: .4byte 0x00003D74
	thumb_func_end GetWaldaPhrasePtr

	thumb_func_start SetWaldaPhrase
SetWaldaPhrase: @ 0x080D1DFC
	push {lr}
	adds r1, r0, #0
	ldr r0, _080D1E10
	ldr r0, [r0]
	ldr r2, _080D1E14
	adds r0, r0, r2
	bl StringCopy
	pop {r0}
	bx r0
	.align 2, 0
_080D1E10: .4byte 0x03005AEC
_080D1E14: .4byte 0x00003D74
	thumb_func_end SetWaldaPhrase

	thumb_func_start IsWaldaPhraseEmpty
IsWaldaPhraseEmpty: @ 0x080D1E18
	push {lr}
	movs r1, #0
	ldr r0, _080D1E34
	ldr r0, [r0]
	ldr r2, _080D1E38
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080D1E2C
	movs r1, #1
_080D1E2C:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_080D1E34: .4byte 0x03005AEC
_080D1E38: .4byte 0x00003D74
	thumb_func_end IsWaldaPhraseEmpty

	thumb_func_start sub_080D1E3C
sub_080D1E3C: @ 0x080D1E3C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r6, _080D1E88
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #4
	bl Alloc
	str r0, [r6]
	ldr r5, _080D1E8C
	movs r1, #0
	cmp r0, #0
	beq _080D1E5A
	adds r1, r4, #0
_080D1E5A:
	strh r1, [r5]
	movs r2, #0
	cmp r2, r1
	bhs _080D1E82
	movs r3, #0
	adds r4, r5, #0
_080D1E66:
	ldr r0, [r6]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r1, r0
	str r3, [r1, #0x18]
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r4]
	cmp r2, r0
	blo _080D1E66
_080D1E82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D1E88: .4byte 0x02039A24
_080D1E8C: .4byte 0x02039A28
	thumb_func_end sub_080D1E3C

	thumb_func_start sub_080D1E90
sub_080D1E90: @ 0x080D1E90
	push {lr}
	ldr r0, _080D1EA0
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.align 2, 0
_080D1EA0: .4byte 0x02039A24
	thumb_func_end sub_080D1E90

	thumb_func_start sub_080D1EA4
sub_080D1EA4: @ 0x080D1EA4
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, _080D1EDC
	ldrh r0, [r0]
	cmp r4, r0
	bge _080D1ED4
	movs r5, #0
_080D1EB2:
	ldr r0, _080D1EE0
	ldr r0, [r0]
	adds r0, r5, r0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1EC8
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_080D21B8
_080D1EC8:
	adds r5, #0x30
	adds r4, #1
	ldr r0, _080D1EDC
	ldrh r0, [r0]
	cmp r4, r0
	blt _080D1EB2
_080D1ED4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D1EDC: .4byte 0x02039A28
_080D1EE0: .4byte 0x02039A24
	thumb_func_end sub_080D1EA4

	thumb_func_start sub_080D1EE4
sub_080D1EE4: @ 0x080D1EE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r2, #0
	ldr r2, [sp, #0x24]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	ldr r0, _080D1F7C
	ldrh r0, [r0]
	cmp r6, r0
	bhs _080D1FCC
	ldr r0, _080D1F80
	mov sb, r0
	ldr r0, [r0]
	lsls r1, r6, #1
	mov r8, r1
	adds r5, r1, r6
	lsls r5, r5, #4
	adds r0, r5, r0
	movs r1, #0
	str r1, [r0, #0x18]
	str r4, [r0, #0x1c]
	adds r0, #0x2b
	strb r7, [r0]
	mov r2, sb
	ldr r0, [r2]
	adds r0, r5, r0
	mov r3, sl
	strh r3, [r0, #0x24]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, #0x26]
	adds r0, r7, #0
	movs r1, #3
	bl GetBgAttribute
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r7, #0
	movs r1, #9
	bl GetBgAttribute
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sb
	ldr r1, [r2]
	adds r5, r5, r1
	ldr r2, _080D1F84
	lsls r4, r4, #2
	lsls r1, r0, #4
	adds r4, r4, r1
	adds r4, r4, r2
	ldrh r1, [r4]
	strh r1, [r5, #0x20]
	ldrh r1, [r4, #2]
	strh r1, [r5, #0x22]
	mov r2, r8
	cmp r0, #0
	beq _080D1F88
	adds r1, r5, #0
	adds r1, #0x2a
	movs r0, #1
	b _080D1F8E
	.align 2, 0
_080D1F7C: .4byte 0x02039A28
_080D1F80: .4byte 0x02039A24
_080D1F84: .4byte 0x08556784
_080D1F88:
	adds r1, r5, #0
	adds r1, #0x2a
	movs r0, #2
_080D1F8E:
	strb r0, [r1]
	ldr r4, _080D1FDC
	ldr r1, [r4]
	adds r2, r2, r6
	lsls r2, r2, #4
	adds r1, r2, r1
	adds r0, r1, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	mov r3, sl
	muls r3, r0, r3
	movs r0, #0
	strh r3, [r1, #0x28]
	mov r3, sl
	strh r3, [r1, #0x10]
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r1, #0x12]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	strh r0, [r1, #0x14]
	strh r0, [r1, #0x16]
	adds r0, r1, #0
	adds r0, #0xc
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldr r0, [r4]
	adds r2, r2, r0
	adds r2, #0x2c
	movs r0, #1
	strb r0, [r2]
_080D1FCC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1FDC: .4byte 0x02039A24
	thumb_func_end sub_080D1EE4

	thumb_func_start sub_080D1FE0
sub_080D1FE0: @ 0x080D1FE0
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _080D2008
	ldrh r0, [r0]
	cmp r2, r0
	bhs _080D2004
	ldr r0, _080D200C
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, r0, r1
	str r3, [r0, #0x18]
	adds r0, #0x2c
	movs r1, #1
	strb r1, [r0]
_080D2004:
	pop {r0}
	bx r0
	.align 2, 0
_080D2008: .4byte 0x02039A28
_080D200C: .4byte 0x02039A24
	thumb_func_end sub_080D1FE0

	thumb_func_start sub_080D2010
sub_080D2010: @ 0x080D2010
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, _080D2044
	ldrh r0, [r0]
	cmp r3, r0
	bhs _080D203C
	ldr r0, _080D2048
	ldr r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, r0, r1
	strh r4, [r0, #0x14]
	strh r2, [r0, #0x16]
	adds r0, #0x2c
	movs r1, #1
	strb r1, [r0]
_080D203C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2044: .4byte 0x02039A28
_080D2048: .4byte 0x02039A24
	thumb_func_end sub_080D2010

	thumb_func_start sub_080D204C
sub_080D204C: @ 0x080D204C
	push {r4, r5, r6, lr}
	ldr r4, [sp, #0x10]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _080D208C
	ldrh r0, [r0]
	cmp r5, r0
	bhs _080D2086
	ldr r0, _080D2090
	ldr r1, [r0]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #4
	adds r0, r0, r1
	strh r6, [r0, #0xc]
	strh r2, [r0, #0xe]
	strh r3, [r0, #0x10]
	strh r4, [r0, #0x12]
	adds r0, #0x2c
	movs r1, #1
	strb r1, [r0]
_080D2086:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D208C: .4byte 0x02039A28
_080D2090: .4byte 0x02039A24
	thumb_func_end sub_080D204C

	thumb_func_start sub_080D2094
sub_080D2094: @ 0x080D2094
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _080D20C0
	ldrh r0, [r0]
	cmp r5, r0
	blo _080D20AC
	b _080D21AE
_080D20AC:
	ldr r4, _080D20C4
	lsls r2, r5, #1
	cmp r1, #5
	bls _080D20B6
	b _080D21A0
_080D20B6:
	lsls r0, r1, #2
	ldr r1, _080D20C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D20C0: .4byte 0x02039A28
_080D20C4: .4byte 0x02039A24
_080D20C8: .4byte 0x080D20CC
_080D20CC: @ jump table
	.4byte _080D20E4 @ case 0
	.4byte _080D2104 @ case 1
	.4byte _080D2128 @ case 2
	.4byte _080D2148 @ case 3
	.4byte _080D216C @ case 4
	.4byte _080D2188 @ case 5
_080D20E4:
	ldr r4, _080D2100
	ldr r0, [r4]
	lsls r3, r5, #1
	adds r1, r3, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r2, r6, #0x18
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0x14]
	adds r0, r0, r2
	strh r0, [r1, #0x14]
	ldrh r0, [r1, #0x10]
	subs r0, r0, r2
	b _080D211E
	.align 2, 0
_080D2100: .4byte 0x02039A24
_080D2104:
	ldr r4, _080D2124
	ldr r0, [r4]
	lsls r3, r5, #1
	adds r1, r3, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r2, r6, #0x18
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0xc]
	adds r0, r0, r2
	strh r0, [r1, #0xc]
	ldrh r0, [r1, #0x10]
	adds r0, r0, r2
_080D211E:
	strh r0, [r1, #0x10]
	adds r2, r3, #0
	b _080D21A0
	.align 2, 0
_080D2124: .4byte 0x02039A24
_080D2128:
	ldr r4, _080D2144
	ldr r0, [r4]
	lsls r3, r5, #1
	adds r1, r3, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r2, r6, #0x18
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0x16]
	adds r0, r0, r2
	strh r0, [r1, #0x16]
	ldrh r0, [r1, #0x12]
	subs r0, r0, r2
	b _080D2162
	.align 2, 0
_080D2144: .4byte 0x02039A24
_080D2148:
	ldr r4, _080D2168
	ldr r0, [r4]
	lsls r3, r5, #1
	adds r1, r3, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r2, r6, #0x18
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0xe]
	subs r0, r0, r2
	strh r0, [r1, #0xe]
	ldrh r0, [r1, #0x12]
	adds r0, r0, r2
_080D2162:
	strh r0, [r1, #0x12]
	adds r2, r3, #0
	b _080D21A0
	.align 2, 0
_080D2168: .4byte 0x02039A24
_080D216C:
	ldr r3, _080D2184
	ldr r0, [r3]
	lsls r2, r5, #1
	adds r1, r2, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r1, #0x14]
	adds r0, r0, r4
	strh r0, [r1, #0x14]
	b _080D219E
	.align 2, 0
_080D2184: .4byte 0x02039A24
_080D2188:
	ldr r3, _080D21B4
	ldr r0, [r3]
	lsls r2, r5, #1
	adds r1, r2, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r1, #0x16]
	adds r0, r0, r4
	strh r0, [r1, #0x16]
_080D219E:
	adds r4, r3, #0
_080D21A0:
	ldr r0, [r4]
	adds r1, r2, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_080D21AE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D21B4: .4byte 0x02039A24
	thumb_func_end sub_080D2094

	thumb_func_start sub_080D21B8
sub_080D21B8: @ 0x080D21B8
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r6, r2, #0
	ldr r0, _080D21F8
	ldrh r0, [r0]
	cmp r2, r0
	bhs _080D21F2
	ldr r5, _080D21FC
	ldr r0, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r4, r1, #4
	adds r0, r4, r0
	ldr r0, [r0, #0x18]
	cmp r0, #0
	beq _080D21E0
	adds r0, r2, #0
	bl sub_080D2200
_080D21E0:
	adds r0, r6, #0
	bl sub_080D2298
	ldr r1, [r5]
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0xc
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
_080D21F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D21F8: .4byte 0x02039A28
_080D21FC: .4byte 0x02039A24
	thumb_func_end sub_080D21B8

	thumb_func_start sub_080D2200
sub_080D2200: @ 0x080D2200
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r4, _080D2294
	ldr r1, [r4]
	lsls r5, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #4
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x2a
	ldrb r3, [r1]
	ldrh r1, [r0, #0x20]
	adds r2, r3, #0
	muls r2, r1, r2
	mov sb, r2
	movs r6, #0xa
	ldrsh r1, [r0, r6]
	mov r2, sb
	muls r2, r1, r2
	ldr r1, [r0, #0x18]
	adds r1, r1, r2
	movs r6, #8
	ldrsh r2, [r0, r6]
	muls r2, r3, r2
	adds r7, r1, r2
	movs r6, #0
	ldrh r0, [r0, #6]
	cmp r6, r0
	bge _080D2284
	mov sl, r4
_080D224A:
	mov r0, sl
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, r4, #4
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	ldrb r2, [r1, #8]
	ldrb r3, [r1, #0xa]
	adds r3, r3, r6
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r1, [r1, #4]
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r7, #0
	bl CopyToBgTilemapBufferRect
	add r7, sb
	adds r6, #1
	mov r1, sl
	ldr r0, [r1]
	adds r4, r4, r0
	ldrh r4, [r4, #6]
	cmp r6, r4
	blt _080D224A
_080D2284:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2294: .4byte 0x02039A24
	thumb_func_end sub_080D2200

	thumb_func_start sub_080D2298
sub_080D2298: @ 0x080D2298
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r4, _080D232C
	ldr r1, [r4]
	lsls r5, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #4
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x2a
	ldrb r3, [r1]
	ldrh r1, [r0, #0x24]
	adds r2, r3, #0
	muls r2, r1, r2
	mov sb, r2
	movs r6, #0xe
	ldrsh r1, [r0, r6]
	mov r2, sb
	muls r2, r1, r2
	ldr r1, [r0, #0x1c]
	adds r1, r1, r2
	movs r6, #0xc
	ldrsh r2, [r0, r6]
	muls r2, r3, r2
	adds r7, r1, r2
	movs r6, #0
	ldrh r0, [r0, #0x12]
	cmp r6, r0
	bge _080D231C
	mov sl, r4
_080D22E2:
	mov r0, sl
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, r4, #4
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	ldrb r2, [r1, #0x14]
	ldrb r3, [r1, #0x16]
	adds r3, r3, r6
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r1, [r1, #0x10]
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r7, #0
	bl CopyToBgTilemapBufferRect
	add r7, sb
	adds r6, #1
	mov r1, sl
	ldr r0, [r1]
	adds r4, r4, r0
	ldrh r4, [r4, #0x12]
	cmp r6, r4
	blt _080D22E2
_080D231C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D232C: .4byte 0x02039A24
	thumb_func_end sub_080D2298

	thumb_func_start sub_080D2330
sub_080D2330: @ 0x080D2330
	ldr r3, _080D2340
	str r0, [r3]
	str r1, [r0]
	movs r1, #0
	strb r2, [r0, #5]
	strb r1, [r0, #4]
	bx lr
	.align 2, 0
_080D2340: .4byte 0x02039A2C
	thumb_func_end sub_080D2330

	thumb_func_start sub_080D2344
sub_080D2344: @ 0x080D2344
	push {r4, r5, lr}
	ldr r2, _080D2388
	ldr r1, [r2]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _080D2382
	movs r4, #0
	ldrb r1, [r1, #4]
	cmp r4, r1
	bhs _080D237A
	adds r5, r2, #0
_080D235A:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #2
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, [r0, #0x10]
	bl _call_via_r1
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	cmp r4, r0
	blo _080D235A
_080D237A:
	ldr r0, _080D2388
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1, #4]
_080D2382:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D2388: .4byte 0x02039A2C
	thumb_func_end sub_080D2344

	thumb_func_start sub_080D238C
sub_080D238C: @ 0x080D238C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	mov sl, r3
	ldr r0, [sp, #0x24]
	ldr r3, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r0, _080D240C
	ldr r2, [r0]
	ldrb r0, [r2, #4]
	adds r1, r0, #0
	ldrb r7, [r2, #5]
	cmp r1, r7
	bhs _080D2414
	adds r0, #1
	strb r0, [r2, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r2]
	adds r1, r1, r0
	lsls r0, r4, #1
	strh r0, [r1, #8]
	ldr r2, [sp]
	lsls r0, r2, #5
	add r0, ip
	lsls r0, r0, #1
	add r0, sb
	str r0, [r1, #4]
	adds r0, r3, #0
	muls r0, r6, r0
	add r0, r8
	lsls r0, r0, #1
	add r0, sl
	str r0, [r1]
	strh r5, [r1, #0xc]
	strh r6, [r1, #0xa]
	ldr r0, _080D2410
	str r0, [r1, #0x10]
	movs r0, #1
	b _080D2416
	.align 2, 0
_080D240C: .4byte 0x02039A2C
_080D2410: .4byte 0x080D2429
_080D2414:
	movs r0, #0
_080D2416:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080D238C

	thumb_func_start sub_080D2428
sub_080D2428: @ 0x080D2428
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _080D2452
_080D2430:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	ldrh r2, [r4, #8]
	lsrs r2, r2, #1
	bl CpuSet
	ldr r0, [r4, #4]
	adds r0, #0x40
	str r0, [r4, #4]
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #1
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_080D2452:
	ldrh r0, [r4, #0xc]
	cmp r5, r0
	blo _080D2430
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080D2428

	thumb_func_start sub_080D2460
sub_080D2460: @ 0x080D2460
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, [sp, #0x14]
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _080D24AC
	ldr r2, [r0]
	ldrb r0, [r2, #4]
	adds r1, r0, #0
	ldrb r7, [r2, #5]
	cmp r1, r7
	bhs _080D24B4
	adds r0, #1
	strb r0, [r2, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r2]
	adds r1, r1, r0
	lsls r0, r3, #1
	strh r0, [r1, #8]
	lsls r0, r4, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	add r0, ip
	str r0, [r1, #4]
	strh r5, [r1, #0xc]
	ldr r0, _080D24B0
	str r0, [r1, #0x10]
	movs r0, #1
	b _080D24B6
	.align 2, 0
_080D24AC: .4byte 0x02039A2C
_080D24B0: .4byte 0x080D24BD
_080D24B4:
	movs r0, #0
_080D24B6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080D2460

	thumb_func_start sub_080D24BC
sub_080D24BC: @ 0x080D24BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	ldrh r1, [r6, #0xc]
	cmp r0, r1
	bhs _080D254A
	movs r7, #0x80
	lsls r7, r7, #5
	mov r5, sp
	ldr r2, _080D2508
	mov r8, r2
	movs r1, #0x81
	lsls r1, r1, #0x18
	mov sl, r1
_080D24E2:
	ldr r2, [r6, #4]
	ldrh r3, [r6, #8]
	mov ip, r2
	adds r0, #1
	mov sb, r0
	cmp r3, r7
	bhi _080D250C
	movs r0, #0
	strh r0, [r5]
	mov r2, sp
	mov r0, r8
	str r2, [r0]
	mov r1, ip
	str r1, [r0, #4]
	lsrs r0, r3, #1
	mov r2, sl
	orrs r0, r2
	mov r1, r8
	b _080D2534
	.align 2, 0
_080D2508: .4byte 0x040000D4
_080D250C:
	movs r4, #0
	strh r4, [r5]
	ldr r1, _080D255C
	mov r0, sp
	str r0, [r1]
	str r2, [r1, #4]
	ldr r0, _080D2560
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r2, r2, r7
	subs r3, r3, r7
	cmp r3, r7
	bhi _080D250C
	strh r4, [r5]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, #4]
	lsrs r0, r3, #1
	mov r2, sl
	orrs r0, r2
_080D2534:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r0, ip
	adds r0, #0x40
	str r0, [r6, #4]
	mov r1, sb
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r6, #0xc]
	cmp r0, r2
	blo _080D24E2
_080D254A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D255C: .4byte 0x040000D4
_080D2560: .4byte 0x81000800
	thumb_func_end sub_080D24BC
