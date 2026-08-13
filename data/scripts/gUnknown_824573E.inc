	goto 0x3411502C
	applymovement_at 0xB010, 0x2007FFB0, 0x1900
	compare_local_to_local 0x20, 0x12
	call_if 0x11, 0xA45001A
	copybyte 0xAB02412E, 0x452E0AFE
	nop 
	setworldmapflag 0x470F
	setvar 0x200, 0x30A
	goto_if 0x15, 0x1220FFAE
	goto_if 0x28, 0x2081600
	nop 
	checkitemspace 0x360C, 0xFE16
	compare_local_to_local 0x20, 0x12
	call_if 0x11, 0x812002D
	setflag 0x1B00
	copylocal 0x37, 0x0
	end 
	.string "る{LIGHT_BLUE}ど\l"
	.string "{DYNAMIC_COLOR1}っ{DYNAMIC_COLOR6}り{SE_BANG}{GREEN}{BLUE}れ{SE_SHIP}{DARK_GRAY}{MUS_RG_RIVAL_EXIT}の{GREEN}なぁ$"
	.string "グッズ{SE_WARP_IN}て{MUS_RG_CAUGHT}れ{SE_ICE_BREAK}ほ{LIGHT_GRAY}ほ{LIGHT_GRAY}は\n"
	.string "{DARK_GRAY}{MUS_RG_ENCOUNTER_DEOXYS}{SE_FALL}{WHITE}るっ{SE_SHIP}はな{DYNAMIC_COLOR3}よ\p"
	.string "どっち{SE_SAVE}{DYNAMIC_COLOR4}て{LIGHT_GREEN}{SE_PIN}グッズを\n"
	.string "て{MUS_RG_CAUGHT}れる{SE_WIN_OPEN}{LIGHT_GREEN}ょ{LIGHT_GRAY}{DYNAMIC_COLOR6}{LIGHT_GRAY}ね！\p"
	.string "{MUS_RG_OBTAIN_KEY_ITEM}で{SE_BOO}ポケモ{SE_M_BUBBLE3}{DYNAMIC_COLOR3}ょ{LIGHT_GRAY}ぶ{SE_SWITCH}{DYNAMIC_COLOR3}{MUS_RG_GAME_FREAK}？$"
	.string "じぶん{SE_A}ひみつ{LIGHT_GREEN}ち{SE_NOTE_B}ま{LIGHT_BLUE}られ{MUS_RG_GAME_FREAK}わ！$"
	.string "{DARK_GRAY}つで{SE_SWITCH}{DYNAMIC_COLOR3}ょ{LIGHT_GRAY}{SE_ITEMFINDER}まってるわ！$"
