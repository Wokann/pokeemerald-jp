	.section .rodata

	.globl gUnknown_890EEF4
gUnknown_890EEF4: @ 0x890EEF4
	.asciz "ASSERTION FAILED  FILE=[%s] LINE=[%d]  EXP=[%s] \n"
	.byte 0x00, 0x00

	.globl gUnknown_890EF28
gUnknown_890EF28: @ 0x890EF28
	.asciz "WARING FILE=[%s] LINE=[%d]  EXP=[%s] \n"
	.byte 0x00
	.4byte gUnknown_890EEF4, gUnknown_890EF28
