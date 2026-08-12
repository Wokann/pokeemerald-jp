
.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


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
