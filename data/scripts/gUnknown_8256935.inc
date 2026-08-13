	lockall 
	checkpartymove 0x123
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, 0x8256974
	bufferpartymonnick 0x0, 0x800D
	setfieldeffectarg 0x0, 0x800D
	setfieldeffectarg 0x1, 0x1
	loadword 0x0, 0x82569F2
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8256983
	loadword 0x0, 0x82569B8
	callstd 0x4
	dofieldeffect 0x2C
	goto 0x8256983
	end 
	.string "ノ{SE_BALL_OPEN}Pノゆ{BLUE}{LIGHT_BLUE}{RED}{LIGHT_RED}ォノゆ{MUS_RG_FUCHSIA}ヒ{DARK_GRAY}ふ{MUS_RG_POKE_TOWER}{TRANSPARENT}{LIGHT_GRAY}みだ！\n"
	.string "ポケモン{SE_A}わざ{SE_NOTE_B}もぐれる{GREEN}も？$"
	.string "ふ{MUS_RG_POKE_TOWER}{TRANSPARENT}{LIGHT_GRAY}みだ！\n"
	.string "ダイビング{SE_WARP_IN}つ{MUS_RG_POKE_TOWER}ま{DYNAMIC_COLOR4}{GREEN}？$"
	.string "{B_COPY_VAR_1}{TRANSPARENT}{SE_I}ダイビング{SE_WARP_IN}つ{GREEN}った！$"
	.string "{LIGHT_GRAY}{RED}{GREEN}{SE_LAVARIDGE_FALL_WARP}ひ{GREEN}り{SE_SAVE}{DYNAMIC_COLOR2}{DYNAMIC_COLOR3}{DYNAMIC_COLOR1}ん{PH_LOT_BLEND}る！\n"
	.string "ポケモン{SE_A}わざ{SE_NOTE_B}ふじょ{LIGHT_GRAY}で{LIGHT_GREEN}る{GREEN}も？$"
	.string "{LIGHT_GRAY}{RED}{GREEN}{SE_LAVARIDGE_FALL_WARP}ひ{GREEN}り{SE_SAVE}{DYNAMIC_COLOR2}{DYNAMIC_COLOR3}{DYNAMIC_COLOR1}ん{PH_LOT_BLEND}る！\n"
	.string "ダイビング{SE_WARP_IN}つ{MUS_RG_POKE_TOWER}ま{DYNAMIC_COLOR4}{GREEN}？$"
