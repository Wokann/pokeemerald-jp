.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start MultiBootInit
MultiBootInit: @ 0x081BA36C
	adds r2, r0, #0
	movs r1, #0
	strb r1, [r2, #0x1e]
	strb r1, [r2, #0x18]
	strb r1, [r2, #0x1d]
	adds r3, r2, #0
	adds r3, #0x4a
	movs r0, #0xf
	strb r0, [r3]
	adds r0, r2, #0
	adds r0, #0x48
	strb r1, [r0]
	strh r1, [r2, #0x16]
	ldr r0, _081BA398
	strh r1, [r0]
	ldr r2, _081BA39C
	ldr r3, _081BA3A0
	adds r0, r3, #0
	strh r0, [r2]
	ldr r0, _081BA3A4
	strh r1, [r0]
	bx lr
	.align 2, 0
_081BA398: .4byte 0x04000134
_081BA39C: .4byte 0x04000128
_081BA3A0: .4byte 0x00002003
_081BA3A4: .4byte 0x0400012A
	thumb_func_end MultiBootInit
