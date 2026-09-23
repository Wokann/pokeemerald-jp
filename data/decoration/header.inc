@ JP Decoration physical data owner: 0x0857FE04..0x08581A0C.
@ Layout: 120 tile arrays, 120 JP descriptions, then 121 Decoration records (0x1C each).
@ Every inline name has exactly 11 preproc-encoded bytes, including EOS padding.

@ Decoration IDs used by the visible record fields.
.equ DECOR_NONE, 0
.equ DECOR_SMALL_DESK, 1
.equ DECOR_POKEMON_DESK, 2
.equ DECOR_HEAVY_DESK, 3
.equ DECOR_RAGGED_DESK, 4
.equ DECOR_COMFORT_DESK, 5
.equ DECOR_PRETTY_DESK, 6
.equ DECOR_BRICK_DESK, 7
.equ DECOR_CAMP_DESK, 8
.equ DECOR_HARD_DESK, 9
.equ DECOR_SMALL_CHAIR, 10
.equ DECOR_POKEMON_CHAIR, 11
.equ DECOR_HEAVY_CHAIR, 12
.equ DECOR_PRETTY_CHAIR, 13
.equ DECOR_COMFORT_CHAIR, 14
.equ DECOR_RAGGED_CHAIR, 15
.equ DECOR_BRICK_CHAIR, 16
.equ DECOR_CAMP_CHAIR, 17
.equ DECOR_HARD_CHAIR, 18
.equ DECOR_RED_PLANT, 19
.equ DECOR_TROPICAL_PLANT, 20
.equ DECOR_PRETTY_FLOWERS, 21
.equ DECOR_COLORFUL_PLANT, 22
.equ DECOR_BIG_PLANT, 23
.equ DECOR_GORGEOUS_PLANT, 24
.equ DECOR_RED_BRICK, 25
.equ DECOR_YELLOW_BRICK, 26
.equ DECOR_BLUE_BRICK, 27
.equ DECOR_RED_BALLOON, 28
.equ DECOR_BLUE_BALLOON, 29
.equ DECOR_YELLOW_BALLOON, 30
.equ DECOR_RED_TENT, 31
.equ DECOR_BLUE_TENT, 32
.equ DECOR_SOLID_BOARD, 33
.equ DECOR_SLIDE, 34
.equ DECOR_FENCE_LENGTH, 35
.equ DECOR_FENCE_WIDTH, 36
.equ DECOR_TIRE, 37
.equ DECOR_STAND, 38
.equ DECOR_MUD_BALL, 39
.equ DECOR_BREAKABLE_DOOR, 40
.equ DECOR_SAND_ORNAMENT, 41
.equ DECOR_SILVER_SHIELD, 42
.equ DECOR_GOLD_SHIELD, 43
.equ DECOR_GLASS_ORNAMENT, 44
.equ DECOR_TV, 45
.equ DECOR_ROUND_TV, 46
.equ DECOR_CUTE_TV, 47
.equ DECOR_GLITTER_MAT, 48
.equ DECOR_JUMP_MAT, 49
.equ DECOR_SPIN_MAT, 50
.equ DECOR_C_LOW_NOTE_MAT, 51
.equ DECOR_D_NOTE_MAT, 52
.equ DECOR_E_NOTE_MAT, 53
.equ DECOR_F_NOTE_MAT, 54
.equ DECOR_G_NOTE_MAT, 55
.equ DECOR_A_NOTE_MAT, 56
.equ DECOR_B_NOTE_MAT, 57
.equ DECOR_C_HIGH_NOTE_MAT, 58
.equ DECOR_SURF_MAT, 59
.equ DECOR_THUNDER_MAT, 60
.equ DECOR_FIRE_BLAST_MAT, 61
.equ DECOR_POWDER_SNOW_MAT, 62
.equ DECOR_ATTRACT_MAT, 63
.equ DECOR_FISSURE_MAT, 64
.equ DECOR_SPIKES_MAT, 65
.equ DECOR_BALL_POSTER, 66
.equ DECOR_GREEN_POSTER, 67
.equ DECOR_RED_POSTER, 68
.equ DECOR_BLUE_POSTER, 69
.equ DECOR_CUTE_POSTER, 70
.equ DECOR_PIKA_POSTER, 71
.equ DECOR_LONG_POSTER, 72
.equ DECOR_SEA_POSTER, 73
.equ DECOR_SKY_POSTER, 74
.equ DECOR_KISS_POSTER, 75
.equ DECOR_PICHU_DOLL, 76
.equ DECOR_PIKACHU_DOLL, 77
.equ DECOR_MARILL_DOLL, 78
.equ DECOR_TOGEPI_DOLL, 79
.equ DECOR_CYNDAQUIL_DOLL, 80
.equ DECOR_CHIKORITA_DOLL, 81
.equ DECOR_TOTODILE_DOLL, 82
.equ DECOR_JIGGLYPUFF_DOLL, 83
.equ DECOR_MEOWTH_DOLL, 84
.equ DECOR_CLEFAIRY_DOLL, 85
.equ DECOR_DITTO_DOLL, 86
.equ DECOR_SMOOCHUM_DOLL, 87
.equ DECOR_TREECKO_DOLL, 88
.equ DECOR_TORCHIC_DOLL, 89
.equ DECOR_MUDKIP_DOLL, 90
.equ DECOR_DUSKULL_DOLL, 91
.equ DECOR_WYNAUT_DOLL, 92
.equ DECOR_BALTOY_DOLL, 93
.equ DECOR_KECLEON_DOLL, 94
.equ DECOR_AZURILL_DOLL, 95
.equ DECOR_SKITTY_DOLL, 96
.equ DECOR_SWABLU_DOLL, 97
.equ DECOR_GULPIN_DOLL, 98
.equ DECOR_LOTAD_DOLL, 99
.equ DECOR_SEEDOT_DOLL, 100
.equ DECOR_PIKA_CUSHION, 101
.equ DECOR_ROUND_CUSHION, 102
.equ DECOR_KISS_CUSHION, 103
.equ DECOR_ZIGZAG_CUSHION, 104
.equ DECOR_SPIN_CUSHION, 105
.equ DECOR_DIAMOND_CUSHION, 106
.equ DECOR_BALL_CUSHION, 107
.equ DECOR_GRASS_CUSHION, 108
.equ DECOR_FIRE_CUSHION, 109
.equ DECOR_WATER_CUSHION, 110
.equ DECOR_SNORLAX_DOLL, 111
.equ DECOR_RHYDON_DOLL, 112
.equ DECOR_LAPRAS_DOLL, 113
.equ DECOR_VENUSAUR_DOLL, 114
.equ DECOR_CHARIZARD_DOLL, 115
.equ DECOR_BLASTOISE_DOLL, 116
.equ DECOR_WAILMER_DOLL, 117
.equ DECOR_REGIROCK_DOLL, 118
.equ DECOR_REGICE_DOLL, 119
.equ DECOR_REGISTEEL_DOLL, 120

@ Placement/collision permission values from include/decoration.h.
.equ DECORPERM_SOLID_FLOOR, 0
.equ DECORPERM_PASS_FLOOR, 1
.equ DECORPERM_BEHIND_FLOOR, 2
.equ DECORPERM_NA_WALL, 3
.equ DECORPERM_SPRITE, 4

@ Shape values from include/decoration.h.
.equ DECORSHAPE_1x1, 0
.equ DECORSHAPE_2x1, 1
.equ DECORSHAPE_3x1, 2
.equ DECORSHAPE_4x2, 3
.equ DECORSHAPE_2x2, 4
.equ DECORSHAPE_1x2, 5
.equ DECORSHAPE_1x3, 6
.equ DECORSHAPE_2x4, 7
.equ DECORSHAPE_3x3, 8
.equ DECORSHAPE_3x2, 9

@ Category values from include/decoration.h.
.equ DECORCAT_DESK, 0
.equ DECORCAT_CHAIR, 1
.equ DECORCAT_PLANT, 2
.equ DECORCAT_ORNAMENT, 3
.equ DECORCAT_MAT, 4
.equ DECORCAT_POSTER, 5
.equ DECORCAT_DOLL, 6
.equ DECORCAT_CUSHION, 7

@ struct Decoration (0x1C): id, name[11], permission, shape, category, pad, price, description, tiles.
	.align 2
	.globl gDecorations
gDecorations: @ 0x8580CD0

	@ [DECOR_NONE]
	.byte DECOR_NONE
	.string "ちいさいつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DESK
	.byte 0
	.4byte 0
	.4byte DecorDesc_SMALL_DESK
	.4byte DecorGfx_SMALL_DESK

	@ [DECOR_SMALL_DESK]
	.byte DECOR_SMALL_DESK
	.string "ちいさいつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DESK
	.byte 0
	.4byte 3000
	.4byte DecorDesc_SMALL_DESK
	.4byte DecorGfx_SMALL_DESK

	@ [DECOR_POKEMON_DESK]
	.byte DECOR_POKEMON_DESK
	.string "ポケモンつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DESK
	.byte 0
	.4byte 3000
	.4byte DecorDesc_POKEMON_DESK
	.4byte DecorGfx_POKEMON_DESK

	@ [DECOR_HEAVY_DESK]
	.byte DECOR_HEAVY_DESK
	.string "ずっしりつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_3x2
	.byte DECORCAT_DESK
	.byte 0
	.4byte 6000
	.4byte DecorDesc_HEAVY_DESK
	.4byte DecorGfx_HEAVY_DESK

	@ [DECOR_RAGGED_DESK]
	.byte DECOR_RAGGED_DESK
	.string "ゴツゴツつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_3x2
	.byte DECORCAT_DESK
	.byte 0
	.4byte 6000
	.4byte DecorDesc_RAGGED_DESK
	.4byte DecorGfx_RAGGED_DESK

	@ [DECOR_COMFORT_DESK]
	.byte DECOR_COMFORT_DESK
	.string "ふわふわつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_3x2
	.byte DECORCAT_DESK
	.byte 0
	.4byte 6000
	.4byte DecorDesc_COMFORT_DESK
	.4byte DecorGfx_COMFORT_DESK

	@ [DECOR_PRETTY_DESK]
	.byte DECOR_PRETTY_DESK
	.string "きれいなつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_DESK
	.byte 0
	.4byte 9000
	.4byte DecorDesc_PRETTY_DESK
	.4byte DecorGfx_PRETTY_DESK

	@ [DECOR_BRICK_DESK]
	.byte DECOR_BRICK_DESK
	.string "レンガのつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_DESK
	.byte 0
	.4byte 9000
	.4byte DecorDesc_BRICK_DESK
	.4byte DecorGfx_BRICK_DESK

	@ [DECOR_CAMP_DESK]
	.byte DECOR_CAMP_DESK
	.string "キャンプつくえ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_DESK
	.byte 0
	.4byte 9000
	.4byte DecorDesc_CAMP_DESK
	.4byte DecorGfx_CAMP_DESK

	@ [DECOR_HARD_DESK]
	.byte DECOR_HARD_DESK
	.string "かたいつくえ$$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_DESK
	.byte 0
	.4byte 9000
	.4byte DecorDesc_HARD_DESK
	.4byte DecorGfx_HARD_DESK

	@ [DECOR_SMALL_CHAIR]
	.byte DECOR_SMALL_CHAIR
	.string "ちいさいイス$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_SMALL_CHAIR
	.4byte DecorGfx_SMALL_CHAIR

	@ [DECOR_POKEMON_CHAIR]
	.byte DECOR_POKEMON_CHAIR
	.string "ポケモンイス$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_POKEMON_CHAIR
	.4byte DecorGfx_POKEMON_CHAIR

	@ [DECOR_HEAVY_CHAIR]
	.byte DECOR_HEAVY_CHAIR
	.string "ずっしりイス$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_HEAVY_CHAIR
	.4byte DecorGfx_HEAVY_CHAIR

	@ [DECOR_PRETTY_CHAIR]
	.byte DECOR_PRETTY_CHAIR
	.string "きれいなイス$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_PRETTY_CHAIR
	.4byte DecorGfx_PRETTY_CHAIR

	@ [DECOR_COMFORT_CHAIR]
	.byte DECOR_COMFORT_CHAIR
	.string "ふわふわのイス$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_COMFORT_CHAIR
	.4byte DecorGfx_COMFORT_CHAIR

	@ [DECOR_RAGGED_CHAIR]
	.byte DECOR_RAGGED_CHAIR
	.string "ゴツゴツのイス$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_RAGGED_CHAIR
	.4byte DecorGfx_RAGGED_CHAIR

	@ [DECOR_BRICK_CHAIR]
	.byte DECOR_BRICK_CHAIR
	.string "レンガのイス$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_BRICK_CHAIR
	.4byte DecorGfx_BRICK_CHAIR

	@ [DECOR_CAMP_CHAIR]
	.byte DECOR_CAMP_CHAIR
	.string "キャンプイス$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_CAMP_CHAIR
	.4byte DecorGfx_CAMP_CHAIR

	@ [DECOR_HARD_CHAIR]
	.byte DECOR_HARD_CHAIR
	.string "かたいイス$$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CHAIR
	.byte 0
	.4byte 2000
	.4byte DecorDesc_HARD_CHAIR
	.4byte DecorGfx_HARD_CHAIR

	@ [DECOR_RED_PLANT]
	.byte DECOR_RED_PLANT
	.string "まっかなうえき$$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_PLANT
	.byte 0
	.4byte 3000
	.4byte DecorDesc_RED_PLANT
	.4byte DecorGfx_RED_PLANT

	@ [DECOR_TROPICAL_PLANT]
	.byte DECOR_TROPICAL_PLANT
	.string "なんごくのうえき$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_PLANT
	.byte 0
	.4byte 3000
	.4byte DecorDesc_TROPICAL_PLANT
	.4byte DecorGfx_TROPICAL_PLANT

	@ [DECOR_PRETTY_FLOWERS]
	.byte DECOR_PRETTY_FLOWERS
	.string "かわいいはな$$$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_PLANT
	.byte 0
	.4byte 3000
	.4byte DecorDesc_PRETTY_FLOWERS
	.4byte DecorGfx_PRETTY_FLOWERS

	@ [DECOR_COLORFUL_PLANT]
	.byte DECOR_COLORFUL_PLANT
	.string "カラフルなうえき$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_2x2
	.byte DECORCAT_PLANT
	.byte 0
	.4byte 5000
	.4byte DecorDesc_COLORFUL_PLANT
	.4byte DecorGfx_COLORFUL_PLANT

	@ [DECOR_BIG_PLANT]
	.byte DECOR_BIG_PLANT
	.string "おっきなうえき$$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_2x2
	.byte DECORCAT_PLANT
	.byte 0
	.4byte 5000
	.4byte DecorDesc_BIG_PLANT
	.4byte DecorGfx_BIG_PLANT

	@ [DECOR_GORGEOUS_PLANT]
	.byte DECOR_GORGEOUS_PLANT
	.string "りっぱなうえき$$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_2x2
	.byte DECORCAT_PLANT
	.byte 0
	.4byte 5000
	.4byte DecorDesc_GORGEOUS_PLANT
	.4byte DecorGfx_GORGEOUS_PLANT

	@ [DECOR_RED_BRICK]
	.byte DECOR_RED_BRICK
	.string "あかいレンガ$$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 500
	.4byte DecorDesc_RED_BRICK
	.4byte DecorGfx_RED_BRICK

	@ [DECOR_YELLOW_BRICK]
	.byte DECOR_YELLOW_BRICK
	.string "きいろいレンガ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 500
	.4byte DecorDesc_YELLOW_BRICK
	.4byte DecorGfx_YELLOW_BRICK

	@ [DECOR_BLUE_BRICK]
	.byte DECOR_BLUE_BRICK
	.string "あおいレンガ$$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 500
	.4byte DecorDesc_BLUE_BRICK
	.4byte DecorGfx_BLUE_BRICK

	@ [DECOR_RED_BALLOON]
	.byte DECOR_RED_BALLOON
	.string "あかいふうせん$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 500
	.4byte DecorDesc_RED_BALLOON
	.4byte DecorGfx_RED_BALLOON

	@ [DECOR_BLUE_BALLOON]
	.byte DECOR_BLUE_BALLOON
	.string "あおいふうせん$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 500
	.4byte DecorDesc_BLUE_BALLOON
	.4byte DecorGfx_BLUE_BALLOON

	@ [DECOR_YELLOW_BALLOON]
	.byte DECOR_YELLOW_BALLOON
	.string "きいろいふうせん$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 500
	.4byte DecorDesc_YELLOW_BALLOON
	.4byte DecorGfx_YELLOW_BALLOON

	@ [DECOR_RED_TENT]
	.byte DECOR_RED_TENT
	.string "あかいテント$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 10000
	.4byte DecorDesc_RED_TENT
	.4byte DecorGfx_RED_TENT

	@ [DECOR_BLUE_TENT]
	.byte DECOR_BLUE_TENT
	.string "あおいテント$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 10000
	.4byte DecorDesc_BLUE_TENT
	.4byte DecorGfx_BLUE_TENT

	@ [DECOR_SOLID_BOARD]
	.byte DECOR_SOLID_BOARD
	.string "じょうぶないた$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 3000
	.4byte DecorDesc_SOLID_BOARD
	.4byte DecorGfx_SOLID_BOARD

	@ [DECOR_SLIDE]
	.byte DECOR_SLIDE
	.string "すべりだい$$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_2x4
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 8000
	.4byte DecorDesc_SLIDE
	.4byte DecorGfx_SLIDE

	@ [DECOR_FENCE_LENGTH]
	.byte DECOR_FENCE_LENGTH
	.string "タテのさく$$$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 500
	.4byte DecorDesc_FENCE_LENGTH
	.4byte DecorGfx_FENCE_LENGTH

	@ [DECOR_FENCE_WIDTH]
	.byte DECOR_FENCE_WIDTH
	.string "ヨコのさく$$$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 500
	.4byte DecorDesc_FENCE_WIDTH
	.4byte DecorGfx_FENCE_WIDTH

	@ [DECOR_TIRE]
	.byte DECOR_TIRE
	.string "タイヤ$$$$$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_2x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 800
	.4byte DecorDesc_TIRE
	.4byte DecorGfx_TIRE

	@ [DECOR_STAND]
	.byte DECOR_STAND
	.string "おおきなだい$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_4x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 7000
	.4byte DecorDesc_STAND
	.4byte DecorGfx_STAND

	@ [DECOR_MUD_BALL]
	.byte DECOR_MUD_BALL
	.string "どろだんご$$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 200
	.4byte DecorDesc_MUD_BALL
	.4byte DecorGfx_MUD_BALL

	@ [DECOR_BREAKABLE_DOOR]
	.byte DECOR_BREAKABLE_DOOR
	.string "やぶれるドア$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 3000
	.4byte DecorDesc_BREAKABLE_DOOR
	.4byte DecorGfx_BREAKABLE_DOOR

	@ [DECOR_SAND_ORNAMENT]
	.byte DECOR_SAND_ORNAMENT
	.string "すなのおきもの$$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 3000
	.4byte DecorDesc_SAND_ORNAMENT
	.4byte DecorGfx_SAND_ORNAMENT

	@ [DECOR_SILVER_SHIELD]
	.byte DECOR_SILVER_SHIELD
	.string "ぎんのたて$$$$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 0
	.4byte DecorDesc_SILVER_SHIELD
	.4byte DecorGfx_SILVER_SHIELD

	@ [DECOR_GOLD_SHIELD]
	.byte DECOR_GOLD_SHIELD
	.string "きんのたて$$$$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 0
	.4byte DecorDesc_GOLD_SHIELD
	.4byte DecorGfx_GOLD_SHIELD

	@ [DECOR_GLASS_ORNAMENT]
	.byte DECOR_GLASS_ORNAMENT
	.string "ガラスのオブジェ$$$"
	.byte DECORPERM_BEHIND_FLOOR
	.byte DECORSHAPE_1x2
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 0
	.4byte DecorDesc_GLASS_ORNAMENT
	.4byte DecorGfx_GLASS_ORNAMENT

	@ [DECOR_TV]
	.byte DECOR_TV
	.string "テレビ$$$$$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 3000
	.4byte DecorDesc_TV
	.4byte DecorGfx_TV

	@ [DECOR_ROUND_TV]
	.byte DECOR_ROUND_TV
	.string "まるいテレビ$$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_ROUND_TV
	.4byte DecorGfx_ROUND_TV

	@ [DECOR_CUTE_TV]
	.byte DECOR_CUTE_TV
	.string "かわいいテレビ$$$$"
	.byte DECORPERM_SOLID_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_ORNAMENT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_CUTE_TV
	.4byte DecorGfx_CUTE_TV

	@ [DECOR_GLITTER_MAT]
	.byte DECOR_GLITTER_MAT
	.string "きらきらマット$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 2000
	.4byte DecorDesc_GLITTER_MAT
	.4byte DecorGfx_GLITTER_MAT

	@ [DECOR_JUMP_MAT]
	.byte DECOR_JUMP_MAT
	.string "ジャンプマット$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 2000
	.4byte DecorDesc_JUMP_MAT
	.4byte DecorGfx_JUMP_MAT

	@ [DECOR_SPIN_MAT]
	.byte DECOR_SPIN_MAT
	.string "くるっとマット$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 2000
	.4byte DecorDesc_SPIN_MAT
	.4byte DecorGfx_SPIN_MAT

	@ [DECOR_C_LOW_NOTE_MAT]
	.byte DECOR_C_LOW_NOTE_MAT
	.string "おんぷマットCL$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 500
	.4byte DecorDesc_C_LOW_NOTE_MAT
	.4byte DecorGfx_C_LOW_NOTE_MAT

	@ [DECOR_D_NOTE_MAT]
	.byte DECOR_D_NOTE_MAT
	.string "おんぷマットD$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 500
	.4byte DecorDesc_D_NOTE_MAT
	.4byte DecorGfx_D_NOTE_MAT

	@ [DECOR_E_NOTE_MAT]
	.byte DECOR_E_NOTE_MAT
	.string "おんぷマットE$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 500
	.4byte DecorDesc_E_NOTE_MAT
	.4byte DecorGfx_E_NOTE_MAT

	@ [DECOR_F_NOTE_MAT]
	.byte DECOR_F_NOTE_MAT
	.string "おんぷマットF$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 500
	.4byte DecorDesc_F_NOTE_MAT
	.4byte DecorGfx_F_NOTE_MAT

	@ [DECOR_G_NOTE_MAT]
	.byte DECOR_G_NOTE_MAT
	.string "おんぷマットG$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 500
	.4byte DecorDesc_G_NOTE_MAT
	.4byte DecorGfx_G_NOTE_MAT

	@ [DECOR_A_NOTE_MAT]
	.byte DECOR_A_NOTE_MAT
	.string "おんぷマットA$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 500
	.4byte DecorDesc_A_NOTE_MAT
	.4byte DecorGfx_A_NOTE_MAT

	@ [DECOR_B_NOTE_MAT]
	.byte DECOR_B_NOTE_MAT
	.string "おんぷマットB$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 500
	.4byte DecorDesc_B_NOTE_MAT
	.4byte DecorGfx_B_NOTE_MAT

	@ [DECOR_C_HIGH_NOTE_MAT]
	.byte DECOR_C_HIGH_NOTE_MAT
	.string "おんぷマットCH$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_1x1
	.byte DECORCAT_MAT
	.byte 0
	.4byte 500
	.4byte DecorDesc_C_HIGH_NOTE_MAT
	.4byte DecorGfx_C_HIGH_NOTE_MAT

	@ [DECOR_SURF_MAT]
	.byte DECOR_SURF_MAT
	.string "なみのりマット$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_MAT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_SURF_MAT
	.4byte DecorGfx_SURF_MAT

	@ [DECOR_THUNDER_MAT]
	.byte DECOR_THUNDER_MAT
	.string "かみなりマット$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_MAT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_THUNDER_MAT
	.4byte DecorGfx_THUNDER_MAT

	@ [DECOR_FIRE_BLAST_MAT]
	.byte DECOR_FIRE_BLAST_MAT
	.string "だいもんじマット$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_MAT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_FIRE_BLAST_MAT
	.4byte DecorGfx_FIRE_BLAST_MAT

	@ [DECOR_POWDER_SNOW_MAT]
	.byte DECOR_POWDER_SNOW_MAT
	.string "こなゆきマット$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_MAT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_POWDER_SNOW_MAT
	.4byte DecorGfx_POWDER_SNOW_MAT

	@ [DECOR_ATTRACT_MAT]
	.byte DECOR_ATTRACT_MAT
	.string "メロメロマット$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_MAT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_ATTRACT_MAT
	.4byte DecorGfx_ATTRACT_MAT

	@ [DECOR_FISSURE_MAT]
	.byte DECOR_FISSURE_MAT
	.string "じわれマット$$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_MAT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_FISSURE_MAT
	.4byte DecorGfx_FISSURE_MAT

	@ [DECOR_SPIKES_MAT]
	.byte DECOR_SPIKES_MAT
	.string "まきびしマット$$$$"
	.byte DECORPERM_PASS_FLOOR
	.byte DECORSHAPE_3x3
	.byte DECORCAT_MAT
	.byte 0
	.4byte 4000
	.4byte DecorDesc_SPIKES_MAT
	.4byte DecorGfx_SPIKES_MAT

	@ [DECOR_BALL_POSTER]
	.byte DECOR_BALL_POSTER
	.string "ボールポスター$$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_1x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1000
	.4byte DecorDesc_BALL_POSTER
	.4byte DecorGfx_BALL_POSTER

	@ [DECOR_GREEN_POSTER]
	.byte DECOR_GREEN_POSTER
	.string "みどりのポスター$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_1x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1000
	.4byte DecorDesc_GREEN_POSTER
	.4byte DecorGfx_GREEN_POSTER

	@ [DECOR_RED_POSTER]
	.byte DECOR_RED_POSTER
	.string "あかいポスター$$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_1x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1000
	.4byte DecorDesc_RED_POSTER
	.4byte DecorGfx_RED_POSTER

	@ [DECOR_BLUE_POSTER]
	.byte DECOR_BLUE_POSTER
	.string "みずいろポスター$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_1x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1000
	.4byte DecorDesc_BLUE_POSTER
	.4byte DecorGfx_BLUE_POSTER

	@ [DECOR_CUTE_POSTER]
	.byte DECOR_CUTE_POSTER
	.string "かわいいポスター$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_1x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1000
	.4byte DecorDesc_CUTE_POSTER
	.4byte DecorGfx_CUTE_POSTER

	@ [DECOR_PIKA_POSTER]
	.byte DECOR_PIKA_POSTER
	.string "ピカピカポスター$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_2x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1500
	.4byte DecorDesc_PIKA_POSTER
	.4byte DecorGfx_PIKA_POSTER

	@ [DECOR_LONG_POSTER]
	.byte DECOR_LONG_POSTER
	.string "ながいポスター$$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_2x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1500
	.4byte DecorDesc_LONG_POSTER
	.4byte DecorGfx_LONG_POSTER

	@ [DECOR_SEA_POSTER]
	.byte DECOR_SEA_POSTER
	.string "うみのポスター$$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_2x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1500
	.4byte DecorDesc_SEA_POSTER
	.4byte DecorGfx_SEA_POSTER

	@ [DECOR_SKY_POSTER]
	.byte DECOR_SKY_POSTER
	.string "そらのポスター$$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_2x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1500
	.4byte DecorDesc_SKY_POSTER
	.4byte DecorGfx_SKY_POSTER

	@ [DECOR_KISS_POSTER]
	.byte DECOR_KISS_POSTER
	.string "キッスポスター$$$$"
	.byte DECORPERM_NA_WALL
	.byte DECORSHAPE_2x1
	.byte DECORCAT_POSTER
	.byte 0
	.4byte 1500
	.4byte DecorDesc_KISS_POSTER
	.4byte DecorGfx_KISS_POSTER

	@ [DECOR_PICHU_DOLL]
	.byte DECOR_PICHU_DOLL
	.string "ピチュードール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_PICHU_DOLL
	.4byte DecorGfx_PICHU_DOLL

	@ [DECOR_PIKACHU_DOLL]
	.byte DECOR_PIKACHU_DOLL
	.string "ピカチュウドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_PIKACHU_DOLL
	.4byte DecorGfx_PIKACHU_DOLL

	@ [DECOR_MARILL_DOLL]
	.byte DECOR_MARILL_DOLL
	.string "マリルドール$$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_MARILL_DOLL
	.4byte DecorGfx_MARILL_DOLL

	@ [DECOR_TOGEPI_DOLL]
	.byte DECOR_TOGEPI_DOLL
	.string "トゲピードール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_TOGEPI_DOLL
	.4byte DecorGfx_TOGEPI_DOLL

	@ [DECOR_CYNDAQUIL_DOLL]
	.byte DECOR_CYNDAQUIL_DOLL
	.string "ヒノアラシドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_CYNDAQUIL_DOLL
	.4byte DecorGfx_CYNDAQUIL_DOLL

	@ [DECOR_CHIKORITA_DOLL]
	.byte DECOR_CHIKORITA_DOLL
	.string "チコリータドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_CHIKORITA_DOLL
	.4byte DecorGfx_CHIKORITA_DOLL

	@ [DECOR_TOTODILE_DOLL]
	.byte DECOR_TOTODILE_DOLL
	.string "ワニノコドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_TOTODILE_DOLL
	.4byte DecorGfx_TOTODILE_DOLL

	@ [DECOR_JIGGLYPUFF_DOLL]
	.byte DECOR_JIGGLYPUFF_DOLL
	.string "プリンドール$$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_JIGGLYPUFF_DOLL
	.4byte DecorGfx_JIGGLYPUFF_DOLL

	@ [DECOR_MEOWTH_DOLL]
	.byte DECOR_MEOWTH_DOLL
	.string "ニャースドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_MEOWTH_DOLL
	.4byte DecorGfx_MEOWTH_DOLL

	@ [DECOR_CLEFAIRY_DOLL]
	.byte DECOR_CLEFAIRY_DOLL
	.string "ピッピドール$$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_CLEFAIRY_DOLL
	.4byte DecorGfx_CLEFAIRY_DOLL

	@ [DECOR_DITTO_DOLL]
	.byte DECOR_DITTO_DOLL
	.string "メタモンドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_DITTO_DOLL
	.4byte DecorGfx_DITTO_DOLL

	@ [DECOR_SMOOCHUM_DOLL]
	.byte DECOR_SMOOCHUM_DOLL
	.string "ムチュールドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_SMOOCHUM_DOLL
	.4byte DecorGfx_SMOOCHUM_DOLL

	@ [DECOR_TREECKO_DOLL]
	.byte DECOR_TREECKO_DOLL
	.string "キモリドール$$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_TREECKO_DOLL
	.4byte DecorGfx_TREECKO_DOLL

	@ [DECOR_TORCHIC_DOLL]
	.byte DECOR_TORCHIC_DOLL
	.string "アチャモドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_TORCHIC_DOLL
	.4byte DecorGfx_TORCHIC_DOLL

	@ [DECOR_MUDKIP_DOLL]
	.byte DECOR_MUDKIP_DOLL
	.string "ミズゴロウドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_MUDKIP_DOLL
	.4byte DecorGfx_MUDKIP_DOLL

	@ [DECOR_DUSKULL_DOLL]
	.byte DECOR_DUSKULL_DOLL
	.string "ヨマワルドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_DUSKULL_DOLL
	.4byte DecorGfx_DUSKULL_DOLL

	@ [DECOR_WYNAUT_DOLL]
	.byte DECOR_WYNAUT_DOLL
	.string "ソーナノドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_WYNAUT_DOLL
	.4byte DecorGfx_WYNAUT_DOLL

	@ [DECOR_BALTOY_DOLL]
	.byte DECOR_BALTOY_DOLL
	.string "ヤジロンドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_BALTOY_DOLL
	.4byte DecorGfx_BALTOY_DOLL

	@ [DECOR_KECLEON_DOLL]
	.byte DECOR_KECLEON_DOLL
	.string "カクレオンドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_KECLEON_DOLL
	.4byte DecorGfx_KECLEON_DOLL

	@ [DECOR_AZURILL_DOLL]
	.byte DECOR_AZURILL_DOLL
	.string "ルリリドール$$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_AZURILL_DOLL
	.4byte DecorGfx_AZURILL_DOLL

	@ [DECOR_SKITTY_DOLL]
	.byte DECOR_SKITTY_DOLL
	.string "エネコドール$$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_SKITTY_DOLL
	.4byte DecorGfx_SKITTY_DOLL

	@ [DECOR_SWABLU_DOLL]
	.byte DECOR_SWABLU_DOLL
	.string "チルットドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_SWABLU_DOLL
	.4byte DecorGfx_SWABLU_DOLL

	@ [DECOR_GULPIN_DOLL]
	.byte DECOR_GULPIN_DOLL
	.string "ゴクリンドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_GULPIN_DOLL
	.4byte DecorGfx_GULPIN_DOLL

	@ [DECOR_LOTAD_DOLL]
	.byte DECOR_LOTAD_DOLL
	.string "ハスボードール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_LOTAD_DOLL
	.4byte DecorGfx_LOTAD_DOLL

	@ [DECOR_SEEDOT_DOLL]
	.byte DECOR_SEEDOT_DOLL
	.string "タネボードール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 3000
	.4byte DecorDesc_SEEDOT_DOLL
	.4byte DecorGfx_SEEDOT_DOLL

	@ [DECOR_PIKA_CUSHION]
	.byte DECOR_PIKA_CUSHION
	.string "ピカクッション$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_PIKA_CUSHION
	.4byte DecorGfx_PIKA_CUSHION

	@ [DECOR_ROUND_CUSHION]
	.byte DECOR_ROUND_CUSHION
	.string "まるいクッション$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_ROUND_CUSHION
	.4byte DecorGfx_ROUND_CUSHION

	@ [DECOR_KISS_CUSHION]
	.byte DECOR_KISS_CUSHION
	.string "キッスクッション$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_KISS_CUSHION
	.4byte DecorGfx_KISS_CUSHION

	@ [DECOR_ZIGZAG_CUSHION]
	.byte DECOR_ZIGZAG_CUSHION
	.string "ジグザクッション$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_ZIGZAG_CUSHION
	.4byte DecorGfx_ZIGZAG_CUSHION

	@ [DECOR_SPIN_CUSHION]
	.byte DECOR_SPIN_CUSHION
	.string "グルルクッション$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_SPIN_CUSHION
	.4byte DecorGfx_SPIN_CUSHION

	@ [DECOR_DIAMOND_CUSHION]
	.byte DECOR_DIAMOND_CUSHION
	.string "ダイヤクッション$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_DIAMOND_CUSHION
	.4byte DecorGfx_DIAMOND_CUSHION

	@ [DECOR_BALL_CUSHION]
	.byte DECOR_BALL_CUSHION
	.string "ボールクッション$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_BALL_CUSHION
	.4byte DecorGfx_BALL_CUSHION

	@ [DECOR_GRASS_CUSHION]
	.byte DECOR_GRASS_CUSHION
	.string "くさクッション$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_GRASS_CUSHION
	.4byte DecorGfx_GRASS_CUSHION

	@ [DECOR_FIRE_CUSHION]
	.byte DECOR_FIRE_CUSHION
	.string "ほのおクッション$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_FIRE_CUSHION
	.4byte DecorGfx_FIRE_CUSHION

	@ [DECOR_WATER_CUSHION]
	.byte DECOR_WATER_CUSHION
	.string "みずクッション$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x1
	.byte DECORCAT_CUSHION
	.byte 0
	.4byte 2000
	.4byte DecorDesc_WATER_CUSHION
	.4byte DecorGfx_WATER_CUSHION

	@ [DECOR_SNORLAX_DOLL]
	.byte DECOR_SNORLAX_DOLL
	.string "カビゴンドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_SNORLAX_DOLL
	.4byte DecorGfx_SNORLAX_DOLL

	@ [DECOR_RHYDON_DOLL]
	.byte DECOR_RHYDON_DOLL
	.string "サイドンドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_RHYDON_DOLL
	.4byte DecorGfx_RHYDON_DOLL

	@ [DECOR_LAPRAS_DOLL]
	.byte DECOR_LAPRAS_DOLL
	.string "ラプラスドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_LAPRAS_DOLL
	.4byte DecorGfx_LAPRAS_DOLL

	@ [DECOR_VENUSAUR_DOLL]
	.byte DECOR_VENUSAUR_DOLL
	.string "フシギバナドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_VENUSAUR_DOLL
	.4byte DecorGfx_VENUSAUR_DOLL

	@ [DECOR_CHARIZARD_DOLL]
	.byte DECOR_CHARIZARD_DOLL
	.string "リザードンドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_CHARIZARD_DOLL
	.4byte DecorGfx_CHARIZARD_DOLL

	@ [DECOR_BLASTOISE_DOLL]
	.byte DECOR_BLASTOISE_DOLL
	.string "カメックスドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_BLASTOISE_DOLL
	.4byte DecorGfx_BLASTOISE_DOLL

	@ [DECOR_WAILMER_DOLL]
	.byte DECOR_WAILMER_DOLL
	.string "ホエルコドール$$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_WAILMER_DOLL
	.4byte DecorGfx_WAILMER_DOLL

	@ [DECOR_REGIROCK_DOLL]
	.byte DECOR_REGIROCK_DOLL
	.string "レジロックドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_REGIROCK_DOLL
	.4byte DecorGfx_REGIROCK_DOLL

	@ [DECOR_REGICE_DOLL]
	.byte DECOR_REGICE_DOLL
	.string "レジアイスドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_REGICE_DOLL
	.4byte DecorGfx_REGICE_DOLL

	@ [DECOR_REGISTEEL_DOLL]
	.byte DECOR_REGISTEEL_DOLL
	.string "レジスチルドール$$$"
	.byte DECORPERM_SPRITE
	.byte DECORSHAPE_1x2
	.byte DECORCAT_DOLL
	.byte 0
	.4byte 10000
	.4byte DecorDesc_REGISTEEL_DOLL
	.4byte DecorGfx_REGISTEEL_DOLL
