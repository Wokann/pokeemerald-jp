	faceplayer 
	waitmovement_at 0x377E, 0x2
	applymovement_at 0x24B, 0xFEAB0D44, 0x902
	compare_local_to_local 0x2E, 0x14
	nop 
	gotostd_if 0x3, 0x6
	gettime 
	nop 
	returnram 
	.string "{SE_SHIP}{BLUE}だ{MUS_RG_VICTORY_WILD}$"
