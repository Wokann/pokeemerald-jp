	loadword 0x0, 0x8256A1D
	callstd 0x3
	end
	.globl gJPText_00256A1D
gJPText_00256A1D: @ 0x08256A1D
	.string "ここには\n"
	.string "なにも　いないようだ⋯⋯$"

	.incbin "baserom_jp.gba", 0x256a2f, 0x105a
