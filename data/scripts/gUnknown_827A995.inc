	nop 
	compare_var_to_var 0xA27, 0x2802
	nop 
	returnram 
	.string "{SE_FAINT}{SE_PC_ON}の{SE_M_SWIFT}F{DARK_GRAY}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}t$"
	.string "t$"
	.incbin "baserom_jp.gba", 0x27a9b0, 0xb
	.string "t$"
	.string "{RED}{MUS_RG_POKE_CENTER}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_DOOR}t$"
	.string "{RED}{MUS_RG_POKE_CENTER}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_CONTEST_PLACE}t$"
	.string "{RED}{LIGHT_GRAY}の{SE_M_SWIFT}F{DARK_GRAY}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}t$"
	.incbin "baserom_jp.gba", 0x27a9e6, 0x2
	.incbin "baserom_jp.gba", 0x27a9e8, 0xb
	.incbin "baserom_jp.gba", 0x27a9f3, 0x2
	.incbin "baserom_jp.gba", 0x27a9f5, 0xd
	.incbin "baserom_jp.gba", 0x27aa02, 0xd
	.string "{RED}{LIGHT_GRAY}の{SE_M_SWIFT}F{DARK_GRAY}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}t$"
	.incbin "baserom_jp.gba", 0x27aa1e, 0xd
	.string "{SE_DOOR}{RED}{MUS_RG_POKE_CENTER}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_DOOR}{SE_DOOR}{RED}{MUS_RG_POKE_CENTER}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_CONTEST_PLACE}{SE_DOOR}{RED}{LIGHT_GRAY}の{SE_M_SWIFT}F{DARK_GRAY}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}t$"
	.incbin "baserom_jp.gba", 0x27aa56, 0xd
	.string "{SE_CONTEST_PLACE}{RED}{MUS_RG_POKE_CENTER}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_DOOR}{SE_CONTEST_PLACE}{RED}{MUS_RG_POKE_CENTER}クvカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_CONTEST_PLACE}{SE_CONTEST_PLACE}{RED}との{SE_M_BARRIER}F{LIGHT_GRAY}qナち{MUS_RG_FUCHSIA}{LIGHT_GREEN}めら{SE_USE_ITEM}{SE_USE_ITEM}$"
	.incbin "baserom_jp.gba", 0x27aa93, 0x17
