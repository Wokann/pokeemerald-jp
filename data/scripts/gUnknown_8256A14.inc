	loadword 0x0, 0x8256A1D
	callstd 0x3
	end
	.globl gJPText_00256A1D
gJPText_00256A1D: @ 0x08256A1D
	.string "ここには\n"
	.string "なにも　いないようだ⋯⋯$"

	.incbin "baserom_jp.gba", 0x256a2f, 0x2d8

Route123_EventScript_ItemCalcium:: @ 0x08256D07
	finditem ITEM_CALCIUM
	end

Route123_EventScript_ItemUltraBall:: @ 0x08256D14
	finditem ITEM_ULTRA_BALL
	end

Route123_EventScript_ItemElixir:: @ 0x08256D21
	finditem ITEM_ELIXIR
	end

Route123_EventScript_ItemPPUp:: @ 0x08256D2E
	finditem ITEM_PP_UP
	end

Route123_EventScript_ItemRevivalHerb:: @ 0x08256D3B
	finditem ITEM_REVIVAL_HERB
	end

Route124_EventScript_ItemRedShard:: @ 0x08256D48
	finditem ITEM_RED_SHARD
	end

Route124_EventScript_ItemBlueShard:: @ 0x08256D55
	finditem ITEM_BLUE_SHARD
	end

Route124_EventScript_ItemYellowShard:: @ 0x08256D62
	finditem ITEM_YELLOW_SHARD
	end

Route125_EventScript_ItemBigPearl:: @ 0x08256D6F
	finditem ITEM_BIG_PEARL
	end

Route126_EventScript_ItemGreenShard:: @ 0x08256D7C
	finditem ITEM_GREEN_SHARD
	end

	.incbin "baserom_jp.gba", 0x256d89, 0xd00
