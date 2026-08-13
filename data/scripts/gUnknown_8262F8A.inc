	gotostd_if 0xA, 0x1F
	giveitem 0x100, 0x2212
	setflag 0x1A14
	setdoorclosed 0xFEB0, 0x2007
	copyvar 0xB00, 0x1902
	return 
	.string "{SE_I}{MUS_RG_RIVAL_EXIT}{DYNAMIC_COLOR3}{SE_FAINT}ものだよ！$"
