	getpricereduction 0x7964
	dofieldeffect 0x7077
	checkplayergender 
	.byte 0x95
	copyvar 0x4400, 0x3B07
	copylocal 0x2D, 0xFE
	giveegg 0xAE9F
	moveobjectoffscreen 0x16
	goto_if 0x2, 0x35110013
	return 
	.string "だ{SE_WARP_OUT}{DYNAMIC_COLOR3}ま{DYNAMIC_COLOR4}\l"
	.string "よろ{MUS_RG_VICTORY_GYM_LEADER}で{DYNAMIC_COLOR4}{GREEN}？$"
