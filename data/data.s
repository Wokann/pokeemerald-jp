	.section .rodata.data_before_bg_data
	.globl gGameVersion
gGameVersion: @ 0x829BDA4
	.byte 0x03

	.globl gGameLanguage
gGameLanguage: @ 0x829BDA5
	.byte 0x01, 0x00, 0x00
	.asciz "2004 06 30 18:43"
	.byte 0x00, 0x00, 0x00

	.globl gIntrTableTemplate
gIntrTableTemplate: @ 0x829BDBC
	.4byte 0x08000845, 0x08000879, 0x0800B4E5, 0x08000815
	.4byte 0x08000739, 0x080008A9, 0x080008A9, 0x080008A9
	.4byte 0x080008A9, 0x080008A9, 0x080008A9, 0x080008A9
	.4byte 0x080008A9, 0x080008A9

	.globl sMallocAssertFile
sMallocAssertFile: @ 0x829BDF4
	.asciz "../gflib/malloc.c"
	.byte 0x00, 0x00
	.globl sMallocAssertAlloc
sMallocAssertAlloc: @ 0x829BE08
	.asciz "0"
	.byte 0x00, 0x00
	.globl sMallocAssertPNull
sMallocAssertPNull: @ 0x829BE0C
	.asciz "p != NULL"
	.byte 0x00, 0x00
	.globl sMallocAssertMagic
sMallocAssertMagic: @ 0x829BE18
	.asciz "pos->magic_number == MALLOC_SYSTEM_ID"
	.byte 0x00, 0x00
	.globl sMallocAssertFlag
sMallocAssertFlag: @ 0x829BE40
	.asciz "pos->flag == TRUE"
	.byte 0x00, 0x00
	.globl sMallocAssertNextMagic
sMallocAssertNextMagic: @ 0x829BE54
	.asciz "pos->next->magic_number == MALLOC_SYSTEM_ID"
	.globl sMallocAssertPrevMagic
sMallocAssertPrevMagic: @ 0x829BE80
	.asciz "pos->prev->magic_number == MALLOC_SYSTEM_ID"
