	loadword 0x0, 0x8264313
	callstd 0x3
	end
	.incbin "baserom_jp.gba", 0x243690, 0x28
	.globl gJPText_002436B8
gJPText_002436B8: @ 0x082436B8
	.string "{MUS_RG_VS_TRAINER}は\n"
	.string "パソコンの　スイッチを　いれた！$"

