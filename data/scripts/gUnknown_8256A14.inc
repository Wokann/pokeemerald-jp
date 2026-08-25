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

Route127_EventScript_ItemZinc:: @ 0x08256D89
	finditem ITEM_ZINC
	end

Route127_EventScript_ItemCarbos:: @ 0x08256D96
	finditem ITEM_CARBOS
	end

Route127_EventScript_ItemRareCandy:: @ 0x08256DA3
	finditem ITEM_RARE_CANDY
	end

Route132_EventScript_ItemRareCandy:: @ 0x08256DB0
	finditem ITEM_RARE_CANDY
	end

Route132_EventScript_ItemProtein:: @ 0x08256DBD
	finditem ITEM_PROTEIN
	end

Route133_EventScript_ItemBigPearl:: @ 0x08256DCA
	finditem ITEM_BIG_PEARL
	end

Route133_EventScript_ItemStarPiece:: @ 0x08256DD7
	finditem ITEM_STAR_PIECE
	end

Route133_EventScript_ItemMaxRevive:: @ 0x08256DE4
	finditem ITEM_MAX_REVIVE
	end

Route134_EventScript_ItemCarbos:: @ 0x08256DF1
	finditem ITEM_CARBOS
	end

Route134_EventScript_ItemStarPiece:: @ 0x08256DFE
	finditem ITEM_STAR_PIECE
	end

PetalburgCity_EventScript_ItemMaxRevive:: @ 0x08256E0B
	finditem ITEM_MAX_REVIVE
	end

PetalburgCity_EventScript_ItemEther:: @ 0x08256E18
	finditem ITEM_ETHER
	end

	.incbin "baserom_jp.gba", 0x256e25, 0xc64
