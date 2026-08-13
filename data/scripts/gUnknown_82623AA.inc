	setvar 0x40A4, 0x1
	special ExitSafariMode
	setwarp 0x1700, 0xFF, 0x2, 0x5
	end 
	.string "に3ぞ{SE_USE_ITEM}ゆ{SE_M_SWIFT}ぐ{SE_BALL}$"
	.incbin "baserom_jp.gba", 0x2623c7, 0x6
