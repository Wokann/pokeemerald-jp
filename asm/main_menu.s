
.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified





	thumb_func_start Task_NewGameBirchSpeech_WhatsYourName
Task_NewGameBirchSpeech_WhatsYourName: @ 0x08030D14
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0
	bl NewGameBirchSpeech_ClearWindow
	ldr r0, _08030D44
	ldr r1, _08030D48
	bl StringExpandPlaceholders
	movs r0, #1
	bl AddTextPrinterForMessage
	ldr r1, _08030D4C
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _08030D50
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030D44: .4byte 0x02021C7C
_08030D48: .4byte 0x08277213
_08030D4C: .4byte 0x03005B60
_08030D50: .4byte 0x08030D55
	thumb_func_end Task_NewGameBirchSpeech_WhatsYourName

	thumb_func_start Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint
Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint: @ 0x08030D54
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl RunTextPrintersAndIsPrinter0Active
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08030D72
	ldr r0, _08030D78
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _08030D7C
	str r0, [r1]
_08030D72:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030D78: .4byte 0x03005B60
_08030D7C: .4byte 0x08030D81
	thumb_func_end Task_NewGameBirchSpeech_WaitForWhatsYourNameToPrint

	thumb_func_start Task_NewGameBirchSpeech_WaitPressBeforeNameChoice
Task_NewGameBirchSpeech_WaitPressBeforeNameChoice: @ 0x08030D80
	push {r4, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08030DC4
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08030D9C
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08030DBA
_08030D9C:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r1, _08030DC8
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _08030DCC
	str r1, [r0]
_08030DBA:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030DC4: .4byte 0x03002360
_08030DC8: .4byte 0x03005B60
_08030DCC: .4byte 0x08030DD1
	thumb_func_end Task_NewGameBirchSpeech_WaitPressBeforeNameChoice

	thumb_func_start Task_NewGameBirchSpeech_StartNamingScreen
Task_NewGameBirchSpeech_StartNamingScreen: @ 0x08030DD0
	push {r4, r5, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08030E34
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08030E2C
	bl FreeAllWindowBuffers
	ldr r1, _08030E38
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #0x1a]
	bl FreeAndDestroyMonPicSprite
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x14
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl NewGameBirchSpeech_SetDefaultPlayerName
	adds r0, r4, #0
	bl DestroyTask
	ldr r0, _08030E3C
	ldr r1, [r0]
	ldrb r2, [r1, #8]
	str r5, [sp]
	ldr r0, _08030E40
	str r0, [sp, #4]
	movs r0, #0
	movs r3, #0
	bl DoNamingScreen
_08030E2C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030E34: .4byte 0x02037C74
_08030E38: .4byte 0x03005B60
_08030E3C: .4byte 0x03005AF0
_08030E40: .4byte 0x080313B9
	thumb_func_end Task_NewGameBirchSpeech_StartNamingScreen

	thumb_func_start Task_NewGameBirchSpeech_SoItsPlayerName
Task_NewGameBirchSpeech_SoItsPlayerName: @ 0x08030E44
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0
	bl NewGameBirchSpeech_ClearWindow
	ldr r0, _08030E74
	ldr r1, _08030E78
	bl StringExpandPlaceholders
	movs r0, #1
	bl AddTextPrinterForMessage
	ldr r1, _08030E7C
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _08030E80
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030E74: .4byte 0x02021C7C
_08030E78: .4byte 0x08277224
_08030E7C: .4byte 0x03005B60
_08030E80: .4byte 0x08030E85
	thumb_func_end Task_NewGameBirchSpeech_SoItsPlayerName

	thumb_func_start Task_NewGameBirchSpeech_CreateNameYesNo
Task_NewGameBirchSpeech_CreateNameYesNo: @ 0x08030E84
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl RunTextPrintersAndIsPrinter0Active
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08030EB8
	movs r0, #2
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0xdb
	movs r3, #0xc7
	bl CreateYesNoMenuParameterized
	ldr r1, _08030EC0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, _08030EC4
	str r1, [r0]
_08030EB8:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030EC0: .4byte 0x03005B60
_08030EC4: .4byte 0x08030EC9
	thumb_func_end Task_NewGameBirchSpeech_CreateNameYesNo

	thumb_func_start Task_NewGameBirchSpeech_ProcessNameYesNoMenu
Task_NewGameBirchSpeech_ProcessNameYesNoMenu: @ 0x08030EC8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	beq _08030EEE
	cmp r1, #0
	bgt _08030EE8
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08030F3C
	b _08030F50
_08030EE8:
	cmp r1, #1
	beq _08030F3C
	b _08030F50
_08030EEE:
	movs r0, #5
	bl PlaySE
	ldr r2, _08030F30
	ldr r0, _08030F34
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	adds r4, r4, r0
	movs r0, #0xc
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r2, [r0, #1]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	movs r2, #4
	orrs r1, r2
	strb r1, [r0, #1]
	adds r0, r5, #0
	movs r1, #2
	bl NewGameBirchSpeech_StartFadeOutTarget1InTarget2
	adds r0, r5, #0
	movs r1, #1
	bl NewGameBirchSpeech_StartFadePlatformIn
	ldr r0, _08030F38
	str r0, [r4]
	b _08030F50
	.align 2, 0
_08030F30: .4byte 0x020205AC
_08030F34: .4byte 0x03005B60
_08030F38: .4byte 0x08030F61
_08030F3C:
	movs r0, #5
	bl PlaySE
	ldr r0, _08030F58
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _08030F5C
	str r0, [r1]
_08030F50:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030F58: .4byte 0x03005B60
_08030F5C: .4byte 0x08030B09
	thumb_func_end Task_NewGameBirchSpeech_ProcessNameYesNoMenu

	thumb_func_start Task_NewGameBirchSpeech_SlidePlatformAway2
Task_NewGameBirchSpeech_SlidePlatformAway2: @ 0x08030F60
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08030F88
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r2, [r1, #0x10]
	movs r3, #0x10
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _08030F8C
	adds r0, r2, #2
	strh r0, [r1, #0x10]
	ldrh r1, [r1, #0x10]
	movs r0, #0x14
	bl SetGpuReg
	b _08030F90
	.align 2, 0
_08030F88: .4byte 0x03005B60
_08030F8C:
	ldr r0, _08030F94
	str r0, [r1]
_08030F90:
	pop {r0}
	bx r0
	.align 2, 0
_08030F94: .4byte 0x08030F99
	thumb_func_end Task_NewGameBirchSpeech_SlidePlatformAway2

	thumb_func_start Task_NewGameBirchSpeech_ReshowBirchLotad
Task_NewGameBirchSpeech_ReshowBirchLotad: @ 0x08030F98
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _08031068
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r7, r0, r1
	movs r1, #0x12
	ldrsh r0, [r7, r1]
	cmp r0, #0
	beq _08031060
	ldr r5, _0803106C
	movs r2, #0x1c
	ldrsh r1, [r7, r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r3, #4
	mov ip, r3
	mov r2, ip
	orrs r1, r2
	strb r1, [r0]
	movs r3, #0x1e
	ldrsh r1, [r7, r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	ldrb r0, [r7, #0x18]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #0x88
	strh r0, [r1, #0x20]
	movs r0, #0x3c
	strh r0, [r1, #0x22]
	adds r3, r1, #0
	adds r3, #0x3e
	ldrb r2, [r3]
	movs r4, #5
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r2
	strb r0, [r3]
	ldrb r3, [r1, #1]
	movs r2, #0xd
	rsbs r2, r2, #0
	adds r0, r2, #0
	ands r0, r3
	mov r3, ip
	orrs r0, r3
	strb r0, [r1, #1]
	ldrb r1, [r7, #0x1a]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0x64
	strh r1, [r0, #0x20]
	movs r1, #0x4b
	strh r1, [r0, #0x22]
	adds r3, r0, #0
	adds r3, #0x3e
	ldrb r1, [r3]
	ands r4, r1
	strb r4, [r3]
	ldrb r1, [r0, #1]
	ands r2, r1
	mov r1, ip
	orrs r2, r1
	strb r2, [r0, #1]
	adds r0, r6, #0
	movs r1, #2
	bl NewGameBirchSpeech_StartFadeInTarget1OutTarget2
	adds r0, r6, #0
	movs r1, #1
	bl NewGameBirchSpeech_StartFadePlatformOut
	movs r0, #0
	bl NewGameBirchSpeech_ClearWindow
	ldr r0, _08031070
	ldr r1, _08031074
	bl StringExpandPlaceholders
	movs r0, #1
	bl AddTextPrinterForMessage
	ldr r0, _08031078
	str r0, [r7]
_08031060:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031068: .4byte 0x03005B60
_0803106C: .4byte 0x020205AC
_08031070: .4byte 0x02021C7C
_08031074: .4byte 0x0827722D
_08031078: .4byte 0x0803107D
	thumb_func_end Task_NewGameBirchSpeech_ReshowBirchLotad

	thumb_func_start Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter
Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter: @ 0x0803107C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08031118
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r1, #0x12
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _08031112
	ldr r7, _0803111C
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #1]
	movs r6, #0xd
	rsbs r6, r6, #0
	adds r0, r6, #0
	ands r0, r2
	strb r0, [r1, #1]
	movs r1, #0x1a
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #1]
	adds r0, r6, #0
	ands r0, r2
	strb r0, [r1, #1]
	bl RunTextPrintersAndIsPrinter0Active
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08031112
	movs r0, #0x18
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrb r2, [r0, #1]
	adds r1, r6, #0
	ands r1, r2
	movs r3, #4
	orrs r1, r3
	strb r1, [r0, #1]
	movs r1, #0x1a
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #1]
	adds r0, r6, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, #1]
	adds r0, r5, #0
	movs r1, #2
	bl NewGameBirchSpeech_StartFadeOutTarget1InTarget2
	adds r0, r5, #0
	movs r1, #1
	bl NewGameBirchSpeech_StartFadePlatformIn
	movs r0, #0x40
	strh r0, [r4, #0x16]
	ldr r0, _08031120
	str r0, [r4]
_08031112:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08031118: .4byte 0x03005B60
_0803111C: .4byte 0x020205AC
_08031120: .4byte 0x08031125
	thumb_func_end Task_NewGameBirchSpeech_WaitForSpriteFadeInAndTextPrinter

	thumb_func_start Task_NewGameBirchSpeech_AreYouReady
Task_NewGameBirchSpeech_AreYouReady: @ 0x08031124
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _0803117C
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r2, #0x12
	ldrsh r0, [r4, r2]
	adds r7, r1, #0
	cmp r0, #0
	beq _080311F0
	ldr r2, _08031180
	movs r3, #0x18
	ldrsh r1, [r4, r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r3, #4
	orrs r1, r3
	strb r1, [r0]
	movs r0, #0x1a
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	ldrh r1, [r4, #0x16]
	movs r3, #0x16
	ldrsh r0, [r4, r3]
	cmp r0, #0
	beq _08031184
	subs r0, r1, #1
	strh r0, [r4, #0x16]
	b _080311F0
	.align 2, 0
_0803117C: .4byte 0x03005B60
_08031180: .4byte 0x020205AC
_08031184:
	ldr r0, _08031194
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq _08031198
	ldrb r5, [r4, #0x1e]
	b _0803119A
	.align 2, 0
_08031194: .4byte 0x03005AF0
_08031198:
	ldrb r5, [r4, #0x1c]
_0803119A:
	lsls r1, r5, #4
	adds r1, r1, r5
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r0, #0x78
	strh r0, [r1, #0x20]
	movs r0, #0x3c
	strh r0, [r1, #0x22]
	adds r3, r1, #0
	adds r3, #0x3e
	ldrb r2, [r3]
	subs r0, #0x41
	ands r0, r2
	strb r0, [r3]
	ldrb r2, [r1, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #4
	orrs r0, r2
	strb r0, [r1, #1]
	lsls r4, r6, #2
	adds r4, r4, r6
	lsls r4, r4, #3
	adds r4, r4, r7
	strh r5, [r4, #0xc]
	adds r0, r6, #0
	movs r1, #2
	bl NewGameBirchSpeech_StartFadeInTarget1OutTarget2
	adds r0, r6, #0
	movs r1, #1
	bl NewGameBirchSpeech_StartFadePlatformOut
	ldr r0, _080311F8
	ldr r1, _080311FC
	bl StringExpandPlaceholders
	movs r0, #1
	bl AddTextPrinterForMessage
	ldr r0, _08031200
	str r0, [r4]
_080311F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080311F8: .4byte 0x02021C7C
_080311FC: .4byte 0x08277265
_08031200: .4byte 0x08031205
	thumb_func_end Task_NewGameBirchSpeech_AreYouReady

	thumb_func_start Task_NewGameBirchSpeech_ShrinkPlayer
Task_NewGameBirchSpeech_ShrinkPlayer: @ 0x08031204
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080312A8
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r6, r1, r2
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _0803129C
	ldr r7, _080312AC
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r1, #1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #1]
	bl RunTextPrintersAndIsPrinter0Active
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0
	bne _0803129C
	ldrb r0, [r6, #0xc]
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	adds r5, r4, r7
	ldrb r1, [r5, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	strb r0, [r5, #1]
	adds r0, r7, #0
	adds r0, #0x10
	adds r0, r4, r0
	ldr r1, _080312B0
	str r1, [r0]
	adds r0, r5, #0
	bl InitSpriteAffineAnim
	adds r0, r5, #0
	movs r1, #0
	bl StartSpriteAffineAnim
	adds r0, r7, #0
	adds r0, #0x1c
	adds r4, r4, r0
	ldr r0, _080312B4
	str r0, [r4]
	ldr r0, _080312B8
	mov r1, r8
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	movs r0, #4
	bl FadeOutBGMTemporarily
	ldr r0, _080312BC
	str r0, [r6]
_0803129C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080312A8: .4byte 0x03005B60
_080312AC: .4byte 0x020205AC
_080312B0: .4byte 0x082D29A4
_080312B4: .4byte 0x08031619
_080312B8: .4byte 0x0000FFFF
_080312BC: .4byte 0x080312C1
	thumb_func_end Task_NewGameBirchSpeech_ShrinkPlayer

	thumb_func_start Task_NewGameBirchSpeech_WaitForPlayerShrink
Task_NewGameBirchSpeech_WaitForPlayerShrink: @ 0x080312C0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080312F0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r3, r1, r2
	ldrb r1, [r3, #0xc]
	ldr r2, _080312F4
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	cmp r0, #0
	bge _080312EA
	ldr r0, _080312F8
	str r0, [r3]
_080312EA:
	pop {r0}
	bx r0
	.align 2, 0
_080312F0: .4byte 0x03005B60
_080312F4: .4byte 0x020205AC
_080312F8: .4byte 0x080312FD
	thumb_func_end Task_NewGameBirchSpeech_WaitForPlayerShrink

	thumb_func_start Task_NewGameBirchSpeech_FadePlayerToWhite
Task_NewGameBirchSpeech_FadePlayerToWhite: @ 0x080312FC
	push {r4, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _08031354
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0803134A
	ldr r0, _08031358
	lsls r4, r2, #2
	adds r4, r4, r2
	lsls r4, r4, #3
	adds r4, r4, r0
	ldrb r2, [r4, #0xc]
	ldr r1, _0803135C
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _08031360
	str r1, [r0]
	movs r1, #0x82
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r0, _08031364
	ldr r1, _08031368
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0803136C
	str r0, [r4]
_0803134A:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031354: .4byte 0x02037C74
_08031358: .4byte 0x03005B60
_0803135C: .4byte 0x020205AC
_08031360: .4byte 0x08031615
_08031364: .4byte 0xFFFF0000
_08031368: .4byte 0x0000FFFF
_0803136C: .4byte 0x08031371
	thumb_func_end Task_NewGameBirchSpeech_FadePlayerToWhite

	thumb_func_start Task_NewGameBirchSpeech_Cleanup
Task_NewGameBirchSpeech_Cleanup: @ 0x08031370
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080313AC
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080313A6
	bl FreeAllWindowBuffers
	ldr r1, _080313B0
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #0x1a]
	bl FreeAndDestroyMonPicSprite
	bl ResetAllPicSprites
	ldr r0, _080313B4
	bl SetMainCallback2
	adds r0, r4, #0
	bl DestroyTask
_080313A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080313AC: .4byte 0x02037C74
_080313B0: .4byte 0x03005B60
_080313B4: .4byte 0x08085861
	thumb_func_end Task_NewGameBirchSpeech_Cleanup

	thumb_func_start CB2_NewGameBirchSpeech_ReturnFromNamingScreen
CB2_NewGameBirchSpeech_ReturnFromNamingScreen: @ 0x080313B8
	push {r4, r5, lr}
	sub sp, #0xc
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	movs r1, #0x82
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r1, _080314E0
	movs r0, #0
	movs r2, #2
	bl InitBgsFromTemplates
	ldr r0, _080314E4
	bl InitBgFromTemplate
	movs r0, #0
	bl SetVBlankCallback
	movs r0, #0xc
	movs r1, #0
	bl SetGpuReg
	movs r0, #0xa
	movs r1, #0
	bl SetGpuReg
	movs r0, #8
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x18
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x1a
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x14
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x16
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x10
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x12
	movs r1, #0
	bl SetGpuReg
	add r0, sp, #4
	movs r4, #0
	strh r4, [r0]
	ldr r1, _080314E8
	str r0, [r1]
	movs r4, #0xc0
	lsls r4, r4, #0x13
	str r4, [r1, #4]
	ldr r0, _080314EC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0
	str r2, [sp, #8]
	add r0, sp, #8
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _080314F0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	add r0, sp, #4
	strh r2, [r0]
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _080314F4
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl ResetPaletteFade
	ldr r0, _080314F8
	adds r1, r4, #0
	bl LZ77UnCompVram
	ldr r0, _080314FC
	ldr r1, _08031500
	bl LZ77UnCompVram
	ldr r0, _08031504
	movs r1, #0
	movs r2, #0x40
	bl LoadPalette
	ldr r0, _08031508
	movs r1, #1
	movs r2, #0x10
	bl LoadPalette
	bl ResetTasks
	ldr r0, _0803150C
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08031510
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r0, #5
	strh r0, [r4, #0x16]
	ldr r0, _08031514
	strh r0, [r4, #0x10]
	bl ScanlineEffect_Stop
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetAllPicSprites
	adds r0, r5, #0
	bl AddBirchSpeechObjects
	ldr r0, _08031518
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	cmp r0, #0
	beq _0803151C
	movs r0, #1
	strh r0, [r4, #0x14]
	ldrb r3, [r4, #0x1e]
	b _08031520
	.align 2, 0
_080314E0: .4byte 0x082D2978
_080314E4: .4byte 0x082D2980
_080314E8: .4byte 0x040000D4
_080314EC: .4byte 0x8100C000
_080314F0: .4byte 0x85000100
_080314F4: .4byte 0x81000200
_080314F8: .4byte 0x082D25C8
_080314FC: .4byte 0x082D277C
_08031500: .4byte 0x06003800
_08031504: .4byte 0x082D2588
_08031508: .4byte 0x082D28A8
_0803150C: .4byte 0x080324B5
_08031510: .4byte 0x03005B60
_08031514: .4byte 0x0000FFC4
_08031518: .4byte 0x03005AF0
_0803151C:
	strh r0, [r4, #0x14]
	ldrb r3, [r4, #0x1c]
_08031520:
	ldr r0, _080315F4
	lsls r1, r3, #4
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r4, #0
	movs r0, #0xb4
	strh r0, [r1, #0x20]
	movs r0, #0x3c
	strh r0, [r1, #0x22]
	adds r1, #0x3e
	ldrb r2, [r1]
	subs r0, #0x41
	ands r0, r2
	strb r0, [r1]
	ldr r1, _080315F8
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	strh r3, [r0, #0xc]
	ldr r1, _080315FC
	movs r0, #0x14
	bl SetGpuReg
	movs r0, #1
	rsbs r0, r0, #0
	str r4, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	movs r0, #0x40
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x44
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x4a
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x54
	movs r1, #0
	bl SetGpuReg
	movs r0, #0
	bl ShowBg
	movs r0, #1
	bl ShowBg
	ldr r3, _08031600
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, _08031604
	ldrh r0, [r4]
	movs r1, #1
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	ldr r0, _08031608
	bl SetVBlankCallback
	ldr r0, _0803160C
	bl SetMainCallback2
	ldr r0, _08031610
	bl InitWindows
	movs r0, #0
	movs r1, #0xdb
	bl LoadMainMenuWindowFrameTiles
	movs r0, #0
	movs r1, #0xe4
	movs r2, #0xf0
	bl LoadMessageBoxGfx
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080315F4: .4byte 0x020205AC
_080315F8: .4byte 0x03005B60
_080315FC: .4byte 0x0000FFC4
_08031600: .4byte 0x04000208
_08031604: .4byte 0x04000200
_08031608: .4byte 0x0802F32D
_0803160C: .4byte 0x0802F315
_08031610: .4byte 0x082D2910
	thumb_func_end CB2_NewGameBirchSpeech_ReturnFromNamingScreen

	thumb_func_start SpriteCB_Null
SpriteCB_Null: @ 0x08031614
	bx lr
	.align 2, 0
	thumb_func_end SpriteCB_Null

	thumb_func_start SpriteCB_MovePlayerDownWhileShrinking
SpriteCB_MovePlayerDownWhileShrinking: @ 0x08031618
	movs r2, #0x22
	ldrsh r1, [r0, r2]
	lsls r1, r1, #0x10
	movs r3, #0x2e
	ldrsh r2, [r0, r3]
	adds r1, r1, r2
	movs r2, #0xc0
	lsls r2, r2, #8
	adds r1, r1, r2
	lsrs r2, r1, #0x10
	strh r2, [r0, #0x22]
	strh r1, [r0, #0x2e]
	bx lr
	.align 2, 0
	thumb_func_end SpriteCB_MovePlayerDownWhileShrinking

	thumb_func_start NewGameBirchSpeech_CreateLotadSprite
NewGameBirchSpeech_CreateLotadSprite: @ 0x08031634
	push {lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _08031664
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #0xe
	str r0, [sp, #8]
	ldr r0, _08031668
	str r0, [sp, #0xc]
	adds r0, r2, #0
	movs r1, #8
	movs r2, #0
	movs r3, #1
	bl CreatePicSprite2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x10
	pop {r1}
	bx r1
	.align 2, 0
_08031664: .4byte 0x00000127
_08031668: .4byte 0x0000FFFF
	thumb_func_end NewGameBirchSpeech_CreateLotadSprite

	thumb_func_start AddBirchSpeechObjects
AddBirchSpeechObjects: @ 0x0803166C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x88
	movs r1, #0x3c
	movs r2, #1
	bl AddNewGameBirchObject
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803178C
	mov sb, r1
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	movs r3, #0x1c
	add r3, sb
	mov r8, r3
	adds r1, r2, r3
	ldr r7, _08031790
	str r7, [r1]
	add r2, sb
	ldrb r3, [r2, #5]
	movs r6, #0xd
	rsbs r6, r6, #0
	adds r1, r6, #0
	ands r1, r3
	strb r1, [r2, #5]
	adds r2, #0x3e
	ldrb r1, [r2]
	movs r3, #4
	mov sl, r3
	mov r3, sl
	orrs r1, r3
	strb r1, [r2]
	ldr r1, _08031794
	lsls r5, r4, #2
	adds r5, r5, r4
	lsls r5, r5, #3
	adds r5, r5, r1
	strh r0, [r5, #0x18]
	movs r0, #0x64
	movs r1, #0x4b
	bl NewGameBirchSpeech_CreateLotadSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r4, r8
	adds r1, r2, r4
	str r7, [r1]
	add r2, sb
	ldrb r3, [r2, #5]
	adds r1, r6, #0
	ands r1, r3
	strb r1, [r2, #5]
	adds r2, #0x3e
	ldrb r1, [r2]
	mov r3, sl
	orrs r1, r3
	strb r1, [r2]
	strh r0, [r5, #0x1a]
	movs r0, #0x3c
	bl FacilityClassToPicIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _08031798
	str r4, [sp]
	movs r1, #0x78
	movs r2, #0x3c
	movs r3, #0
	bl CreateTrainerSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	mov r3, r8
	adds r1, r2, r3
	str r7, [r1]
	add r2, sb
	adds r3, r2, #0
	adds r3, #0x3e
	ldrb r1, [r3]
	mov r4, sl
	orrs r1, r4
	strb r1, [r3]
	ldrb r3, [r2, #5]
	adds r1, r6, #0
	ands r1, r3
	strb r1, [r2, #5]
	strh r0, [r5, #0x1c]
	movs r0, #0x3f
	bl FacilityClassToPicIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08031798
	movs r2, #0x80
	lsls r2, r2, #4
	adds r4, r1, r2
	str r4, [sp]
	movs r1, #0x78
	movs r2, #0x3c
	movs r3, #0
	bl CreateTrainerSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	add r8, r2
	mov r3, r8
	str r7, [r3]
	add r2, sb
	adds r3, r2, #0
	adds r3, #0x3e
	ldrb r1, [r3]
	mov r4, sl
	orrs r1, r4
	strb r1, [r3]
	ldrb r1, [r2, #5]
	ands r6, r1
	strb r6, [r2, #5]
	strh r0, [r5, #0x1e]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803178C: .4byte 0x020205AC
_08031790: .4byte 0x08031615
_08031794: .4byte 0x03005B60
_08031798: .4byte 0x0201C000
	thumb_func_end AddBirchSpeechObjects

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
