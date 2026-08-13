	nop 
	compare_addr_to_local 0x29030A28, 0x19
	.byte 0xCA
	nop 
	setdynamicwarp 0x400, 0x2, 0x1F6C, 0x857
	bufferitemname 0x8, 0x0
	.byte 0xF0
	.byte 0xFF
	setdivewarp 0x2, 0x0, 0x68, 0x2C28
	compare_addr_to_addr 0x4000100, 0x1F6C0206
	setobjectxy 0x8008, 0x8, 0xF000
	.byte 0xFF
	compare_addr_to_addr 0x68000200, 0x202C2800
	nop 
	setworldmapflag 0x200
	release 
	compare_addr_to_value 0x8800857, 0x0
	nop 
	.byte 0xF0
	.byte 0xFF
	nop 
	nop 
	end 
	.string "{TRANSPARENT}{SE_MUGSHOT}りわ{SE_FAILURE}{SE_USE_ITEM}{RED}{MUS_RG_POKE_TOWER}フまキ{BLUE}ィ{SE_DOOR}{TRANSPARENT}:$"
	.string "{SE_M_BATON_PASS}{SE_PC_LOGIN}{SE_MUGSHOT}りわ{SE_FAILURE}{SE_USE_ITEM}{DARK_GRAY}フまキ{BLUE}ィ{SE_DOOR}{TRANSPARENT}:$"
	.string "{SE_M_CUT}{SE_PC_LOGIN}{SE_MUGSHOT}りわ{SE_FAILURE}{SE_USE_ITEM}{RED}{MUS_RG_POKE_TOWER}フまキ{BLUE}ィ{SE_DOOR}{TRANSPARENT}:$"
	.string "{SE_M_LEER}{SE_PC_LOGIN}{SE_MUGSHOT}りわ{SE_FAILURE}{SE_USE_ITEM}{DARK_GRAY}フまキ{BLUE}ィ{SE_DOOR}{TRANSPARENT}:$"
	.string "{SE_M_RAZOR_WIND2}{SE_PC_LOGIN}{SE_MUGSHOT}りわ{SE_FAILURE}{SE_USE_ITEM}{RED}{MUS_RG_POKE_TOWER}フまキ{BLUE}ィ{SE_DOOR}{TRANSPARENT}:$"
	.incbin "baserom_jp.gba", 0x27cd09, 0x10
