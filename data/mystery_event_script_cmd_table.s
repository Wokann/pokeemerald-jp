	.section script_data, "aw", %progbits

	.align 2
	.globl gMysteryEventScriptCmdTable
gMysteryEventScriptCmdTable:
	.4byte MEScrCmd_nop                 @ 0x00
	.4byte MEScrCmd_checkcompat         @ 0x01
	.4byte MEScrCmd_end                 @ 0x02
	.4byte MEScrCmd_setmsg              @ 0x03
	.4byte MEScrCmd_setstatus           @ 0x04
	.4byte MEScrCmd_runscript           @ 0x05
	.4byte MEScrCmd_initramscript       @ 0x06
	.4byte MEScrCmd_setenigmaberry      @ 0x07
	.4byte MEScrCmd_giveribbon          @ 0x08
	.4byte MEScrCmd_enableresetrtc      @ 0x09
	.4byte MEScrCmd_addrareword         @ 0x0A
	.4byte MEScrCmd_setrecordmixinggift @ 0x0B
	.4byte MEScrCmd_givepokemon         @ 0x0C
	.4byte MEScrCmd_addtrainer          @ 0x0D
	.4byte MEScrCmd_givenationaldex     @ 0x0E
	.4byte MEScrCmd_checksum            @ 0x0F
	.4byte MEScrCmd_crc                 @ 0x10
	.globl gMysteryEventScriptCmdTableEnd
gMysteryEventScriptCmdTableEnd:
