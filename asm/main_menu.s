
.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified








	thumb_func_start Task_NewGameBirchSpeech_FadeOutTarget1InTarget2
Task_NewGameBirchSpeech_FadeOutTarget1InTarget2: @ 0x0803179C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r4, _080317D0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r2, r0, r4
	ldrh r1, [r2, #0xa]
	movs r5, #0xa
	ldrsh r0, [r2, r5]
	cmp r0, #0
	bne _080317D4
	movs r1, #8
	ldrsh r0, [r2, r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r4
	movs r0, #1
	strh r0, [r1, #0x12]
	adds r0, r3, #0
	bl DestroyTask
	b _08031804
	.align 2, 0
_080317D0: .4byte 0x03005B60
_080317D4:
	ldrh r3, [r2, #0x10]
	movs r4, #0x10
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq _080317E4
	subs r0, r3, #1
	strh r0, [r2, #0x10]
	b _08031804
_080317E4:
	ldrh r0, [r2, #0xe]
	strh r0, [r2, #0x10]
	subs r1, #1
	strh r1, [r2, #0xa]
	ldrh r0, [r2, #0xc]
	adds r0, #1
	strh r0, [r2, #0xc]
	movs r5, #0xc
	ldrsh r0, [r2, r5]
	lsls r0, r0, #8
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
_08031804:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end Task_NewGameBirchSpeech_FadeOutTarget1InTarget2

	thumb_func_start NewGameBirchSpeech_StartFadeOutTarget1InTarget2
NewGameBirchSpeech_StartFadeOutTarget1InTarget2: @ 0x0803180C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	movs r1, #0x94
	lsls r1, r1, #2
	movs r0, #0x50
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0x10
	bl SetGpuReg
	movs r0, #0x54
	movs r1, #0
	bl SetGpuReg
	ldr r0, _08031874
	mov r8, r0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	add r0, r8
	movs r6, #0
	strh r6, [r0, #0x12]
	ldr r0, _08031878
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	add r1, r8
	strh r4, [r1, #8]
	movs r0, #0x10
	strh r0, [r1, #0xa]
	strh r6, [r1, #0xc]
	strh r5, [r1, #0xe]
	strh r5, [r1, #0x10]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08031874: .4byte 0x03005B60
_08031878: .4byte 0x0803179D
	thumb_func_end NewGameBirchSpeech_StartFadeOutTarget1InTarget2

	thumb_func_start Task_NewGameBirchSpeech_FadeInTarget1OutTarget2
Task_NewGameBirchSpeech_FadeInTarget1OutTarget2: @ 0x0803187C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r4, _080318B0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r2, r0, r4
	ldrh r1, [r2, #0xa]
	movs r5, #0xa
	ldrsh r0, [r2, r5]
	cmp r0, #0x10
	bne _080318B4
	movs r1, #8
	ldrsh r0, [r2, r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r4
	movs r0, #1
	strh r0, [r1, #0x12]
	adds r0, r3, #0
	bl DestroyTask
	b _080318E4
	.align 2, 0
_080318B0: .4byte 0x03005B60
_080318B4:
	ldrh r3, [r2, #0x10]
	movs r4, #0x10
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq _080318C4
	subs r0, r3, #1
	strh r0, [r2, #0x10]
	b _080318E4
_080318C4:
	ldrh r0, [r2, #0xe]
	strh r0, [r2, #0x10]
	adds r1, #1
	strh r1, [r2, #0xa]
	ldrh r0, [r2, #0xc]
	subs r0, #1
	strh r0, [r2, #0xc]
	movs r5, #0xc
	ldrsh r0, [r2, r5]
	lsls r0, r0, #8
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
_080318E4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end Task_NewGameBirchSpeech_FadeInTarget1OutTarget2

	thumb_func_start NewGameBirchSpeech_StartFadeInTarget1OutTarget2
NewGameBirchSpeech_StartFadeInTarget1OutTarget2: @ 0x080318EC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	movs r1, #0x94
	lsls r1, r1, #2
	movs r0, #0x50
	bl SetGpuReg
	movs r1, #0x80
	lsls r1, r1, #5
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #0x54
	movs r1, #0
	bl SetGpuReg
	ldr r0, _08031954
	mov r8, r0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	add r0, r8
	movs r6, #0
	strh r6, [r0, #0x12]
	ldr r0, _08031958
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	add r1, r8
	strh r4, [r1, #8]
	strh r6, [r1, #0xa]
	movs r0, #0x10
	strh r0, [r1, #0xc]
	strh r5, [r1, #0xe]
	strh r5, [r1, #0x10]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08031954: .4byte 0x03005B60
_08031958: .4byte 0x0803187D
	thumb_func_end NewGameBirchSpeech_StartFadeInTarget1OutTarget2

	thumb_func_start Task_NewGameBirchSpeech_FadePlatformIn
Task_NewGameBirchSpeech_FadePlatformIn: @ 0x0803195C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _0803197C
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r0, r1
	ldrh r3, [r1, #0xc]
	movs r4, #0xc
	ldrsh r0, [r1, r4]
	cmp r0, #0
	beq _08031980
	subs r0, r3, #1
	strh r0, [r1, #0xc]
	b _080319BC
	.align 2, 0
_0803197C: .4byte 0x03005B60
_08031980:
	ldrh r3, [r1, #0xa]
	movs r4, #0xa
	ldrsh r0, [r1, r4]
	cmp r0, #8
	bne _08031992
	adds r0, r2, #0
	bl DestroyTask
	b _080319BC
_08031992:
	ldrh r2, [r1, #0x10]
	movs r4, #0x10
	ldrsh r0, [r1, r4]
	cmp r0, #0
	beq _080319A2
	subs r0, r2, #1
	strh r0, [r1, #0x10]
	b _080319BC
_080319A2:
	ldrh r0, [r1, #0xe]
	strh r0, [r1, #0x10]
	adds r0, r3, #1
	strh r0, [r1, #0xa]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	ldr r1, _080319C4
	adds r0, r0, r1
	movs r1, #1
	movs r2, #0x10
	bl LoadPalette
_080319BC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080319C4: .4byte 0x082D28A6
	thumb_func_end Task_NewGameBirchSpeech_FadePlatformIn

	thumb_func_start NewGameBirchSpeech_StartFadePlatformIn
NewGameBirchSpeech_StartFadePlatformIn: @ 0x080319C8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _08031A00
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08031A04
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	movs r0, #0
	strh r4, [r1, #8]
	strh r0, [r1, #0xa]
	movs r0, #8
	strh r0, [r1, #0xc]
	strh r5, [r1, #0xe]
	strh r5, [r1, #0x10]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031A00: .4byte 0x0803195D
_08031A04: .4byte 0x03005B60
	thumb_func_end NewGameBirchSpeech_StartFadePlatformIn

	thumb_func_start Task_NewGameBirchSpeech_FadePlatformOut
Task_NewGameBirchSpeech_FadePlatformOut: @ 0x08031A08
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _08031A28
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r0, r1
	ldrh r3, [r1, #0xc]
	movs r4, #0xc
	ldrsh r0, [r1, r4]
	cmp r0, #0
	beq _08031A2C
	subs r0, r3, #1
	strh r0, [r1, #0xc]
	b _08031A68
	.align 2, 0
_08031A28: .4byte 0x03005B60
_08031A2C:
	ldrh r3, [r1, #0xa]
	movs r4, #0xa
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bne _08031A3E
	adds r0, r2, #0
	bl DestroyTask
	b _08031A68
_08031A3E:
	ldrh r2, [r1, #0x10]
	movs r4, #0x10
	ldrsh r0, [r1, r4]
	cmp r0, #0
	beq _08031A4E
	subs r0, r2, #1
	strh r0, [r1, #0x10]
	b _08031A68
_08031A4E:
	ldrh r0, [r1, #0xe]
	strh r0, [r1, #0x10]
	subs r0, r3, #1
	strh r0, [r1, #0xa]
	movs r2, #0xa
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	ldr r1, _08031A70
	adds r0, r0, r1
	movs r1, #1
	movs r2, #0x10
	bl LoadPalette
_08031A68:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031A70: .4byte 0x082D28A6
	thumb_func_end Task_NewGameBirchSpeech_FadePlatformOut

	thumb_func_start NewGameBirchSpeech_StartFadePlatformOut
NewGameBirchSpeech_StartFadePlatformOut: @ 0x08031A74
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _08031AAC
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08031AB0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	strh r4, [r1, #8]
	movs r0, #8
	strh r0, [r1, #0xa]
	strh r0, [r1, #0xc]
	strh r5, [r1, #0xe]
	strh r5, [r1, #0x10]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031AAC: .4byte 0x08031A09
_08031AB0: .4byte 0x03005B60
	thumb_func_end NewGameBirchSpeech_StartFadePlatformOut

	thumb_func_start NewGameBirchSpeech_ShowGenderMenu
NewGameBirchSpeech_ShowGenderMenu: @ 0x08031AB4
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r0, _08031B18
	movs r1, #0xdb
	bl DrawMainMenuWindowBorder
	movs r0, #1
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r0, #1
	movs r1, #0
	bl GetMenuCursorDimensionByFont
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r5, #0x10
	str r5, [sp]
	movs r4, #2
	str r4, [sp, #4]
	ldr r0, _08031B1C
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #1
	movs r3, #2
	bl PrintTextArray
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl sub_081984B0
	movs r0, #1
	bl PutWindowTilemap
	movs r0, #1
	movs r1, #2
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031B18: .4byte 0x082D2918
_08031B1C: .4byte 0x082D29A8
	thumb_func_end NewGameBirchSpeech_ShowGenderMenu

	thumb_func_start NewGameBirchSpeech_ProcessGenderMenuInput
NewGameBirchSpeech_ProcessGenderMenuInput: @ 0x08031B20
	push {lr}
	bl Menu_ProcessInputNoWrap
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end NewGameBirchSpeech_ProcessGenderMenuInput

	thumb_func_start NewGameBirchSpeech_SetDefaultPlayerName
NewGameBirchSpeech_SetDefaultPlayerName: @ 0x08031B30
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _08031B48
	ldr r0, [r1]
	ldrb r0, [r0, #8]
	adds r5, r1, #0
	cmp r0, #0
	bne _08031B50
	ldr r1, _08031B4C
	b _08031B52
	.align 2, 0
_08031B48: .4byte 0x03005AF0
_08031B4C: .4byte 0x082D29B8
_08031B50:
	ldr r1, _08031B7C
_08031B52:
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _08031B80
_08031B5C:
	ldr r1, [r4]
	adds r1, r1, r2
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #4
	bls _08031B5C
	ldr r1, [r5]
	movs r0, #0xff
	strb r0, [r1, #5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031B7C: .4byte 0x082D2A08
_08031B80: .4byte 0x03005AF0
	thumb_func_end NewGameBirchSpeech_SetDefaultPlayerName

	thumb_func_start CreateMainMenuErrorWindow
CreateMainMenuErrorWindow: @ 0x08031B84
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #7
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #7
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0
	bl AddTextPrinterParameterized
	movs r0, #7
	bl PutWindowTilemap
	movs r0, #7
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, _08031BD8
	ldr r1, _08031BDC
	bl DrawMainMenuWindowBorder
	ldr r1, _08031BE0
	movs r0, #0x40
	bl SetGpuReg
	ldr r1, _08031BE4
	movs r0, #0x44
	bl SetGpuReg
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031BD8: .4byte 0x082D2900
_08031BDC: .4byte 0x000001D5
_08031BE0: .4byte 0x000009E7
_08031BE4: .4byte 0x0000719F
	thumb_func_end CreateMainMenuErrorWindow

	thumb_func_start MainMenu_FormatSavegameText
MainMenu_FormatSavegameText: @ 0x08031BE8
	push {lr}
	bl MainMenu_FormatSavegamePlayer
	bl MainMenu_FormatSavegamePokedex
	bl MainMenu_FormatSavegameTime
	bl MainMenu_FormatSavegameBadges
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end MainMenu_FormatSavegameText

	thumb_func_start MainMenu_FormatSavegamePlayer
MainMenu_FormatSavegamePlayer: @ 0x08031C00
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _08031C38
	ldr r1, _08031C3C
	ldr r1, [r1]
	bl StringCopy
	ldr r4, _08031C40
	ldr r1, _08031C44
	adds r0, r4, #0
	bl StringExpandPlaceholders
	ldr r0, _08031C48
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #0
	movs r3, #0x11
	bl AddTextPrinterParameterized3
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031C38: .4byte 0x02021C40
_08031C3C: .4byte 0x03005AF0
_08031C40: .4byte 0x02021C7C
_08031C44: .4byte 0x085CCCBD
_08031C48: .4byte 0x082D2973
	thumb_func_end MainMenu_FormatSavegamePlayer

	thumb_func_start MainMenu_FormatSavegameTime
MainMenu_FormatSavegameTime: @ 0x08031C4C
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _08031C98
	ldr r4, _08031C9C
	ldr r1, [r4]
	ldrh r1, [r1, #0xe]
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r0, _08031CA0
	ldr r1, [r4]
	ldrb r1, [r1, #0x10]
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	ldr r4, _08031CA4
	ldr r1, _08031CA8
	adds r0, r4, #0
	bl StringExpandPlaceholders
	ldr r0, _08031CAC
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #0x67
	movs r3, #0x11
	bl AddTextPrinterParameterized3
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031C98: .4byte 0x02021C40
_08031C9C: .4byte 0x03005AF0
_08031CA0: .4byte 0x02021C54
_08031CA4: .4byte 0x02021C7C
_08031CA8: .4byte 0x085CCCC7
_08031CAC: .4byte 0x082D2973
	thumb_func_end MainMenu_FormatSavegameTime

	thumb_func_start MainMenu_FormatSavegamePokedex
MainMenu_FormatSavegamePokedex: @ 0x08031CB0
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _08031CD4
	bl FlagGet
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08031D0E
	bl IsNationalPokedexEnabled
	cmp r0, #0
	beq _08031CD8
	movs r0, #1
	bl GetNationalPokedexCount
	b _08031CDE
	.align 2, 0
_08031CD4: .4byte 0x00000861
_08031CD8:
	movs r0, #1
	bl GetHoennPokedexCount
_08031CDE:
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _08031D18
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r4, _08031D1C
	ldr r1, _08031D20
	adds r0, r4, #0
	bl StringExpandPlaceholders
	ldr r0, _08031D24
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #0
	movs r3, #0x21
	bl AddTextPrinterParameterized3
_08031D0E:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031D18: .4byte 0x02021C40
_08031D1C: .4byte 0x02021C7C
_08031D20: .4byte 0x085CCCD4
_08031D24: .4byte 0x082D2973
	thumb_func_end MainMenu_FormatSavegamePokedex

	thumb_func_start MainMenu_FormatSavegameBadges
MainMenu_FormatSavegameBadges: @ 0x08031D28
	push {r4, r5, lr}
	sub sp, #0xc
	movs r5, #0
	ldr r4, _08031D84
_08031D30:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08031D44
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08031D44:
	adds r4, #1
	ldr r0, _08031D88
	cmp r4, r0
	bls _08031D30
	ldr r0, _08031D8C
	adds r1, r5, #0
	movs r2, #2
	movs r3, #1
	bl ConvertIntToDecimalStringN
	ldr r4, _08031D90
	ldr r1, _08031D94
	adds r0, r4, #0
	bl StringExpandPlaceholders
	ldr r0, _08031D98
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #0x6f
	movs r3, #0x21
	bl AddTextPrinterParameterized3
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08031D84: .4byte 0x00000867
_08031D88: .4byte 0x0000086E
_08031D8C: .4byte 0x02021C40
_08031D90: .4byte 0x02021C7C
_08031D94: .4byte 0x085CCCE1
_08031D98: .4byte 0x082D2973
	thumb_func_end MainMenu_FormatSavegameBadges

	thumb_func_start LoadMainMenuWindowFrameTiles
LoadMainMenuWindowFrameTiles: @ 0x08031D9C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r6, _08031DE0
	ldr r0, [r6]
	ldrb r0, [r0, #0x14]
	lsrs r0, r0, #3
	bl GetWindowFrameTilesPal
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r3, r5, #0
	bl LoadBgTiles
	ldr r0, [r6]
	ldrb r0, [r0, #0x14]
	lsrs r0, r0, #3
	bl GetWindowFrameTilesPal
	ldr r0, [r0, #4]
	movs r1, #0x20
	movs r2, #0x20
	bl LoadPalette
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08031DE0: .4byte 0x03005AF0
	thumb_func_end LoadMainMenuWindowFrameTiles

	thumb_func_start DrawMainMenuWindowBorder
DrawMainMenuWindowBorder: @ 0x08031DE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	lsls r6, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #9
	adds r0, r0, r6
	lsrs r0, r0, #0x10
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r1, r1, r6
	lsrs r1, r1, #0x10
	mov sl, r1
	movs r7, #0xc0
	lsls r7, r7, #0xa
	adds r1, r6, r7
	lsrs r1, r1, #0x10
	str r1, [sp, #0x18]
	movs r0, #0xa0
	lsls r0, r0, #0xb
	adds r1, r6, r0
	lsrs r1, r1, #0x10
	str r1, [sp, #0xc]
	movs r7, #0xc0
	lsls r7, r7, #0xb
	adds r1, r6, r7
	lsrs r1, r1, #0x10
	str r1, [sp, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #0xb
	adds r1, r6, r0
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	lsrs r1, r6, #0x10
	movs r7, #0x80
	lsls r7, r7, #0xc
	adds r6, r6, r7
	lsrs r6, r6, #0x10
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r5, #1
	str r5, [sp]
	str r5, [sp, #4]
	movs r7, #2
	mov r8, r7
	str r7, [sp, #8]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r1, [r4, #3]
	str r1, [sp]
	str r5, [sp, #4]
	str r7, [sp, #8]
	mov r1, sb
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #3]
	ldrb r1, [r4, #1]
	adds r2, r2, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	str r7, [sp, #8]
	mov r1, sl
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	str r5, [sp]
	ldrb r1, [r4, #4]
	str r1, [sp, #4]
	str r7, [sp, #8]
	ldr r1, [sp, #0x18]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #3]
	ldrb r7, [r4, #1]
	adds r2, r2, r7
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	str r5, [sp]
	ldrb r1, [r4, #4]
	str r1, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	ldr r1, [sp, #0xc]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #4]
	ldrb r7, [r4, #2]
	adds r3, r3, r7
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	ldr r1, [sp, #0x10]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	ldrb r3, [r4, #4]
	ldrb r7, [r4, #2]
	adds r3, r3, r7
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r1, [r4, #3]
	str r1, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	ldr r1, [sp, #0x14]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #3]
	ldrb r7, [r4, #1]
	adds r2, r2, r7
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #4]
	ldrb r1, [r4, #2]
	adds r3, r3, r1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	mov r7, r8
	str r7, [sp, #8]
	adds r1, r6, #0
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	bl CopyBgTilemapBufferToVram
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end DrawMainMenuWindowBorder

	thumb_func_start ClearMainMenuWindowTilemap
ClearMainMenuWindowTilemap: @ 0x08031F48
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldrb r0, [r6]
	ldrb r1, [r6, #1]
	subs r2, r1, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r4, [r6, #2]
	subs r3, r4, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r5, [r6, #3]
	adds r1, r1, r5
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	ldrb r1, [r6, #4]
	adds r4, r4, r1
	adds r4, #1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #0
	bl FillBgTilemapBufferRect
	ldrb r0, [r6]
	bl CopyBgTilemapBufferToVram
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end ClearMainMenuWindowTilemap

	thumb_func_start NewGameBirchSpeech_ClearGenderWindowTilemap
NewGameBirchSpeech_ClearGenderWindowTilemap: @ 0x08031F90
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, [sp, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsls r5, r5, #0x18
	lsls r3, r3, #0x18
	lsls r1, r1, #0x18
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r4, r4, r2
	lsrs r4, r4, #0x18
	adds r5, r5, r2
	lsrs r5, r5, #0x18
	movs r2, #0x80
	lsls r2, r2, #0x12
	adds r3, r3, r2
	lsrs r3, r3, #0x18
	str r3, [sp]
	adds r1, r1, r2
	lsrs r1, r1, #0x18
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end NewGameBirchSpeech_ClearGenderWindowTilemap

	thumb_func_start sub_08031FD8
sub_08031FD8: @ 0x08031FD8
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _0803200C
	adds r0, r5, #0
	bl CallWindowFunction
	adds r0, r5, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	adds r0, r5, #0
	bl ClearWindowTilemap
	cmp r4, #1
	bne _08032006
	adds r0, r5, #0
	movs r1, #3
	bl CopyWindowToVram
_08032006:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803200C: .4byte 0x08031F91
	thumb_func_end sub_08031FD8

	thumb_func_start NewGameBirchSpeech_ClearWindow
NewGameBirchSpeech_ClearWindow: @ 0x08032010
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	movs r0, #1
	movs r1, #6
	bl GetFontAttribute
	mov sb, r0
	mov r0, sb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r0, #1
	movs r1, #0
	bl GetFontAttribute
	mov r8, r0
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r0, #1
	movs r1, #1
	bl GetFontAttribute
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	adds r0, r6, #0
	movs r1, #3
	bl GetWindowAttribute
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r6, #0
	movs r1, #4
	bl GetWindowAttribute
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, r8
	muls r1, r4, r1
	str r1, [sp]
	muls r0, r5, r0
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0
	bl FillWindowPixelRect
	adds r0, r6, #0
	movs r1, #2
	bl CopyWindowToVram
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end NewGameBirchSpeech_ClearWindow

	thumb_func_start NewGameBirchSpeech_ShowPokeBallPrinterCallback
NewGameBirchSpeech_ShowPokeBallPrinterCallback: @ 0x08032098
	push {lr}
	ldr r0, [r0]
	subs r0, #2
	ldrb r0, [r0]
	cmp r0, #8
	bne _080320B8
	ldr r1, _080320BC
	ldrb r0, [r1]
	cmp r0, #0
	bne _080320B8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080320C0
	movs r1, #0
	bl CreateTask
_080320B8:
	pop {r0}
	bx r0
	.align 2, 0
_080320BC: .4byte 0x020229B8
_080320C0: .4byte 0x080307B1
	thumb_func_end NewGameBirchSpeech_ShowPokeBallPrinterCallback

	thumb_func_start CreateYesNoMenuParameterized
CreateYesNoMenuParameterized: @ 0x080320C4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x20
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r2
	ldr r6, [sp, #0x34]
	ldr r1, [sp, #0x38]
	lsls r4, r4, #0x18
	lsls r5, r5, #0x18
	mov r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r4, r4, r0
	lsrs r4, r4, #0x18
	adds r5, r5, r0
	lsrs r5, r5, #0x18
	movs r0, #5
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl CreateWindowTemplate
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	add r0, sp, #0x18
	mov r1, r8
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl CreateYesNoMenuAtPos
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end CreateYesNoMenuParameterized

	thumb_func_start sub_0803213C
sub_0803213C: @ 0x0803213C
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _08032170
	adds r0, r5, #0
	bl CallWindowFunction
	adds r0, r5, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	adds r0, r5, #0
	bl PutWindowTilemap
	cmp r4, #1
	bne _0803216A
	adds r0, r5, #0
	movs r1, #3
	bl CopyWindowToVram
_0803216A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08032170: .4byte 0x08032175
	thumb_func_end sub_0803213C

	thumb_func_start sub_08032174
sub_08032174: @ 0x08032174
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	adds r5, r2, #0
	ldr r2, [sp, #0x4c]
	ldr r6, [sp, #0x50]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsls r5, r5, #0x18
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x10]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x14]
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsrs r0, r1, #0x18
	str r0, [sp, #0xc]
	movs r0, #0xfd
	lsls r0, r0, #0x18
	adds r1, r1, r0
	lsrs r1, r1, #0x18
	str r1, [sp, #0x18]
	lsrs r1, r5, #0x18
	mov sl, r1
	movs r0, #0xff
	lsls r0, r0, #0x18
	adds r5, r5, r0
	lsrs r5, r5, #0x18
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe5
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0xc]
	subs r0, #2
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x1c]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe6
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0xc]
	subs r0, #1
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x20]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe7
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, [sp, #0x10]
	str r1, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe8
	ldr r2, [sp, #0xc]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r7, r0, r1
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x24]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe9
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	adds r0, r7, #1
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x28]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe6
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	adds r0, r7, #2
	lsls r2, r0, #0x18
	lsrs r7, r2, #0x18
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xea
	adds r2, r7, #0
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xeb
	ldr r2, [sp, #0x18]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xf1
	ldr r2, [sp, #0x1c]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xef
	ldr r2, [sp, #0x20]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0x10]
	str r0, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xed
	ldr r2, [sp, #0xc]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _08032480
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x24]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xf1
	ldr r2, [sp, #0x28]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xee
	adds r2, r7, #0
	mov r3, sl
	bl FillBgTilemapBufferRect
	mov r5, sl
	adds r5, #1
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r4, [sp]
	movs r1, #2
	mov sb, r1
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xeb
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xec
	ldr r2, [sp, #0x1c]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0x10]
	adds r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xed
	ldr r2, [sp, #0x20]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xec
	ldr r2, [sp, #0x28]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xee
	adds r2, r7, #0
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032484
	ldr r0, [sp, #0x14]
	add sl, r0
	mov r5, sl
	subs r5, #1
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032488
	mov sb, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x1c]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _0803248C
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x20]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032490
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0xc]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032494
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x24]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	mov r1, sb
	ldr r2, [sp, #0x28]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032498
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	adds r2, r7, #0
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _0803249C
	mov r0, sl
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x18]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r5, _080324A0
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	adds r1, r5, #0
	ldr r2, [sp, #0x1c]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _080324A4
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x20]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _080324A8
	ldr r0, [sp, #0x10]
	str r0, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0xc]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _080324AC
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x24]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	adds r1, r5, #0
	ldr r2, [sp, #0x28]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _080324B0
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	adds r2, r7, #0
	mov r3, sl
	bl FillBgTilemapBufferRect
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032480: .4byte 0x000004EF
_08032484: .4byte 0x000008EB
_08032488: .4byte 0x000008F1
_0803248C: .4byte 0x000008EF
_08032490: .4byte 0x000008ED
_08032494: .4byte 0x00000CEF
_08032498: .4byte 0x000008EE
_0803249C: .4byte 0x000008E5
_080324A0: .4byte 0x000008E6
_080324A4: .4byte 0x000008E7
_080324A8: .4byte 0x000008E8
_080324AC: .4byte 0x000008E9
_080324B0: .4byte 0x000008EA
	thumb_func_end sub_08032174

	thumb_func_start Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox
Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox: @ 0x080324B4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080324E4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
	ldrh r0, [r4, #0x16]
	subs r1, r0, #1
	strh r1, [r4, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080324DC
	movs r0, #0
	movs r1, #1
	bl sub_0803213C
	ldr r0, _080324E8
	str r0, [r4]
_080324DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080324E4: .4byte 0x03005B60
_080324E8: .4byte 0x08030E45
	thumb_func_end Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox
