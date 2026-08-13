	lockall 
	compare_var_to_value 0x4037, 0x9
	goto_if 0x4, 0x824477B
	goto 0x8244789
	end 
	.incbin "baserom_jp.gba", 0x24475b, 0x554
	.string "{SE_BIKE_BELL}{SE_O}{LIGHT_GRAY}{SE_M_CONFUSE_RAY}と$"
	.string "{SE_PIN}{SE_CARD}{LIGHT_GRAY}{SE_M_CONFUSE_RAY}り$"
	.string "{SE_EXIT}{SE_FLEE}{LIGHT_GRAY}{SE_M_CONFUSE_RAY}り$"
	.string "{SE_CARD}{SE_SHIP}{LIGHT_GRAY}{SE_M_CONFUSE_RAY}れ$"
	.string "{SE_BALL_BOUNCE_3}{SE_LEDGE}{LIGHT_GRAY}{SE_M_CONFUSE_RAY}れ$"
	.string "{SE_NOTE_C}{SE_SUCCESS}{LIGHT_GRAY}{SE_M_CONFUSE_RAY}わ$"
	.string "{SE_FLEE}{SE_BALL_OPEN}{LIGHT_GRAY}{SE_M_CONFUSE_RAY}わ$"
	.incbin "baserom_jp.gba", 0x244cee, 0x5
